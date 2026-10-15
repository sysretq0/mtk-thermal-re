# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Inspector / patcher for the MediaTek thermal HAL.

The vendor thermal HAL (``/vendor/lib64/hw/android.hardware.thermal@2.0-impl.so``)
is the AOSP ``ThermalHelper`` implementation with an MTK twist: instead of parsing
``thermal_info_config.json`` it fills its ``kMtkTempThreshold`` table from constants
that live in ``.rodata``.

Every ``TemperatureType`` owns an 0x58-byte entry of ``kMtkTempThreshold`` holding
six ``float`` hot-throttling thresholds (AOSP ``ThrottlingSeverity`` 1..6) at
entry offsets ``0x1c..0x30``.  For the CPU/GPU/NPU/BATTERY/SKIN/POWER_AMPLIFIER
entries the first two slots are ``NaN`` (disabled) and the remaining four are built
from pairs of ``float`` constants in ``.rodata``.  Those constants are what this
module decodes and rewrites.

Two consequences matter for tuning:

* Types that **share** a ``.rodata`` word move together.  This module refuses to
  apply a change that would require one word to hold two different values.
* The framework re-reads these thresholds through ``getTemperatureThresholds`` and
  derives its thermal status from the HAL's ``notifyThrottling`` severities, so
  raising them makes the *framework* less reactive.  Real DVFS protection lives in
  ``thermal_core``/the kernel and is not affected.

The ``SKIN`` entry is overwritten at runtime by ``thermal_core`` from
``[thermalhal-threshold]`` in ``/vendor/etc/thermal/thermal.conf``; patching its
``.rodata`` default has no lasting effect.  Tune SKIN through the vendor config.
"""

from __future__ import annotations

import struct
from collections.abc import Iterable, Mapping, Sequence
from dataclasses import dataclass

__all__ = [
    "HalError",
    "THRESHOLD_SLOTS",
    "KNOWN_DEFAULTS",
    "KNOWN_BUILD_ID",
    "KNOWN_SIZE",
    "SEVERITIES",
    "PROFILES",
    "elf_build_id",
    "is_thermal_hal",
    "read_thresholds",
    "apply_thresholds",
    "add_offset",
    "format_report",
]

# --------------------------------------------------------------------------- model

SEVERITIES = (3, 4, 5, 6)
"""Hot-throttling severities actually populated by the built-in table.

AOSP ``ThrottlingSeverity``: 3=SEVERE, 4=CRITICAL, 5=EMERGENCY, 6=SHUTDOWN.
Severities 1 (LIGHT) and 2 (MODERATE) are stored as ``NaN`` (disabled).
"""

#: File offset of each populated threshold, keyed by TemperatureType.
#: The order is severity 3, 4, 5, 6.  Offsets are into the ELF file image
#: (``.rodata`` is mapped 1:1 with its file offset in this binary).
THRESHOLD_SLOTS: Mapping[str, tuple[int, int, int, int]] = {
    "CPU": (0x8C8C, 0x8C70, 0x8C74, 0x8C78),
    "GPU": (0x8C8C, 0x8C70, 0x8C74, 0x8C78),
    "NPU": (0x8C8C, 0x8C70, 0x8C74, 0x8C78),
    "BATTERY": (0x8C6C, 0x8C50, 0x8C54, 0x8C58),
    "SKIN": (0x8C6C, 0x8C30, 0x8C34, 0x8C38),
    "POWER_AMPLIFIER": (0x8C4C, 0x8C20, 0x8C24, 0x8C28),
}

#: Values shipped in this HAL build, used to verify an image before patching.
KNOWN_DEFAULTS: Mapping[str, tuple[float, float, float, float]] = {
    "CPU": (85.0, 90.0, 100.0, 117.0),
    "GPU": (85.0, 90.0, 100.0, 117.0),
    "NPU": (85.0, 90.0, 100.0, 117.0),
    "BATTERY": (50.0, 55.0, 59.0, 60.0),
    "SKIN": (50.0, 70.0, 80.0, 90.0),
    "POWER_AMPLIFIER": (68.0, 90.0, 100.0, 110.0),
}

#: Fingerprint of the reference binary (``android.hardware.thermal@2.0-impl.so``).
KNOWN_BUILD_ID = "ce2460711bd53e46ecd0d3373aaf641c"
KNOWN_SIZE = 100304

#: Types that ``thermal_core`` overwrites at boot; a static edit is cosmetic.
RUNTIME_OVERRIDDEN = frozenset({"SKIN"})

#: Built-in tuning profiles.  Values are (severity3, severity4, severity5, severity6).
PROFILES: Mapping[str, Mapping[str, tuple[float, float, float, float]]] = {
    # "Hotter but within the SoC's own rails": raise the framework-visible
    # severity onset by 10 C for the compute types while leaving the SHUTDOWN
    # slot and every safety-critical type (BATTERY/POWER_AMPLIFIER) untouched.
    "sysretq0-hot": {
        "CPU": (95.0, 100.0, 110.0, 117.0),
        "GPU": (95.0, 100.0, 110.0, 117.0),
        "NPU": (95.0, 100.0, 110.0, 117.0),
    },
}


class HalError(ValueError):
    """Raised for an unusable image or an unsafe patch request."""


# --------------------------------------------------------------------------- elf helpers

_NOTE_GNU = b"\x04\x00\x00\x00\x10\x00\x00\x00\x03\x00\x00\x00GNU\x00"


def elf_build_id(data: bytes) -> str | None:
    """Return the lowercase-hex ``.note.gnu.build-id`` value, if present."""
    idx = data.find(_NOTE_GNU)
    if idx < 0:
        return None
    end = idx + len(_NOTE_GNU) + 16
    if end > len(data):
        return None
    return data[idx + len(_NOTE_GNU) : end].hex()


def is_thermal_hal(data: bytes) -> bool:
    """Check for a little-endian aarch64 shared object."""
    if len(data) < 64 or data[:4] != b"\x7fELF":
        return False
    if data[4] != 2 or data[5] != 1:  # 64-bit, little-endian
        return False
    e_type, e_machine = struct.unpack_from("<HH", data, 16)
    return e_type == 3 and e_machine == 0xB7  # ET_DYN, EM_AARCH64


# --------------------------------------------------------------------------- decode


def _f32(data: bytes, offset: int) -> float:
    return struct.unpack_from("<f", data, offset)[0]


def _is_nan(value: float) -> bool:
    return value != value


def _slot_map() -> dict[int, float]:
    """Build offset -> expected default value from :data:`KNOWN_DEFAULTS`."""
    expected: dict[int, float] = {}
    for name, slots in THRESHOLD_SLOTS.items():
        defaults = KNOWN_DEFAULTS[name]
        for sev, offset in zip(SEVERITIES, slots):
            value = defaults[sev - 3]
            if offset in expected and expected[offset] != value:
                # Shared word with a different default would be a registry bug.
                raise HalError("inconsistent registry for offset 0x%x (%s)" % (offset, name))
            expected[offset] = value
    return expected


def read_thresholds(data: bytes) -> dict[str, tuple[float, float, float, float]]:
    """Decode the four populated hot thresholds for every known type."""
    if not is_thermal_hal(data):
        raise HalError("not an aarch64 ELF shared object")
    for offset in _slot_map():
        if offset + 4 > len(data):
            raise HalError("image too small to hold the threshold table")
    return {
        name: tuple(_f32(data, off) for off in slots)  # type: ignore[misc]
        for name, slots in THRESHOLD_SLOTS.items()
    }


def verify_defaults(data: bytes) -> list[str]:
    """Return human-readable mismatches against :data:`KNOWN_DEFAULTS`.

    An empty list means the image matches the reference build exactly.
    """
    problems: list[str] = []
    build_id = elf_build_id(data)
    if build_id is not None and build_id != KNOWN_BUILD_ID:
        problems.append("build-id %s != reference %s" % (build_id, KNOWN_BUILD_ID))
    if len(data) != KNOWN_SIZE:
        problems.append("size %d != reference %d" % (len(data), KNOWN_SIZE))
    decoded = read_thresholds(data)
    for name, got in decoded.items():
        want = KNOWN_DEFAULTS[name]
        if got != want:
            problems.append("%s %s != stock %s" % (name, _fmt(got), _fmt(want)))
    return problems


# --------------------------------------------------------------------------- patch


def _check_series(name: str, values: Sequence[float]) -> tuple[float, ...]:
    if len(values) != len(SEVERITIES):
        raise HalError(
            "%s: expected %d thresholds (severity %s), got %d"
            % (name, len(SEVERITIES), "/".join(map(str, SEVERITIES)), len(values))
        )
    out: list[float] = []
    for value in values:
        try:
            fvalue = float(value)
        except (TypeError, ValueError) as exc:
            raise HalError("%s: %r is not a number" % (name, value)) from exc
        if _is_nan(fvalue) or fvalue != fvalue:
            raise HalError("%s: NaN thresholds are not allowed" % name)
        out.append(fvalue)
    for lower, upper in zip(out, out[1:]):
        if upper <= lower:
            raise HalError(
                "%s: thresholds must strictly increase, got %s" % (name, _fmt(tuple(out)))
            )
    return tuple(out)


def _plan(changes: Mapping[str, Sequence[float]]) -> dict[int, float]:
    """Resolve a type -> thresholds mapping into offset -> value edits."""
    plan: dict[int, float] = {}
    for name, values in changes.items():
        if name not in THRESHOLD_SLOTS:
            raise HalError(
                "unknown temperature type %r (known: %s)"
                % (name, ", ".join(sorted(THRESHOLD_SLOTS)))
            )
        series = _check_series(name, values)
        for offset, value in zip(THRESHOLD_SLOTS[name], series):
            if offset in plan and plan[offset] != value:
                raise HalError(
                    "conflict at 0x%x: shared .rodata word would need two values "
                    "(%g and %g); patch the sharing types together" % (offset, plan[offset], value)
                )
            plan[offset] = value
    return plan


def apply_thresholds(
    data: bytes,
    changes: Mapping[str, Sequence[float]],
    *,
    strict: bool = True,
) -> bytes:
    """Return a copy of ``data`` with the requested thresholds written in.

    ``strict`` refuses to touch anything but the reference build; pass
    ``strict=False`` (or ``--force``) to patch a different vendor image whose
    layout happens to match, after checking :func:`read_thresholds` yourself.
    """
    if not is_thermal_hal(data):
        raise HalError("not an aarch64 ELF shared object")
    if strict:
        problems = verify_defaults(data)
        if problems:
            raise HalError(
                "refusing to patch a non-reference image:\n  - " + "\n  - ".join(problems)
            )
    plan = _plan(changes)
    if not plan:
        raise HalError("nothing to do (no types requested)")
    out = bytearray(data)
    for offset, value in plan.items():
        struct.pack_into("<f", out, offset, value)
    return bytes(out)


def add_offset(
    data: bytes,
    delta: float,
    types: Iterable[str],
    *,
    strict: bool = True,
) -> bytes:
    """Raise the thresholds of ``types`` by ``delta`` degrees.

    The SHUTDOWN slot (severity 6) is clamped so a bulk uplift can never move it.
    """
    current = read_thresholds(data)
    changes: dict[str, tuple[float, float, float, float]] = {}
    for name in types:
        if name not in current:
            raise HalError("unknown temperature type %r" % name)
        s3, s4, s5, s6 = current[name]
        changes[name] = (s3 + delta, s4 + delta, s5 + delta, s6)
    return apply_thresholds(data, changes, strict=strict)


# --------------------------------------------------------------------------- report


def _fmt(values: Sequence[float]) -> str:
    return "[" + ", ".join("%g" % v for v in values) + "]"


@dataclass(frozen=True)
class Report:
    """Decoded view of a HAL image."""

    build_id: str | None
    size: int
    reference: bool
    thresholds: Mapping[str, tuple[float, float, float, float]]
    problems: tuple[str, ...]

    def as_text(self) -> str:
        lines = [
            "build-id : %s" % (self.build_id or "(none)"),
            "size     : %d bytes" % self.size,
            "reference: %s" % ("yes" if self.reference else "no"),
            "",
            "%-16s %s" % ("TYPE", "sev3 / sev4 / sev5 / sev6"),
        ]
        for name in THRESHOLD_SLOTS:
            note = "  (runtime-overridden by thermal_core)" if name in RUNTIME_OVERRIDDEN else ""
            lines.append("%-16s %s%s" % (name, _fmt(self.thresholds[name]), note))
        if self.problems:
            lines.append("")
            lines.append("problems:")
            lines.extend("  - %s" % p for p in self.problems)
        return "\n".join(lines)


def format_report(data: bytes) -> str:
    """Decode ``data`` into a :class:`Report` and render it as text."""
    problems = tuple(verify_defaults(data))
    return Report(
        build_id=elf_build_id(data),
        size=len(data),
        reference=not problems,
        thresholds=read_thresholds(data),
        problems=problems,
    ).as_text()
