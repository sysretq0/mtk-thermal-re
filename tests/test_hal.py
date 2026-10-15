# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Tests for the thermal HAL inspector/patcher."""

from __future__ import annotations

import contextlib
import io
import struct
import tempfile
import unittest
from pathlib import Path

from mtk_thermal_re import hal


def _note(build_id_hex: str) -> bytes:
    return b"\x04\x00\x00\x00\x10\x00\x00\x00\x03\x00\x00\x00GNU\x00" + bytes.fromhex(build_id_hex)


def make_image(
    *,
    size: int = hal.KNOWN_SIZE,
    build_id: str = hal.KNOWN_BUILD_ID,
    defaults=hal.KNOWN_DEFAULTS,
) -> bytes:
    """Build a synthetic aarch64 ELF carrying the threshold table."""
    buf = bytearray(size)
    buf[0:4] = b"\x7fELF"
    buf[4] = 2  # 64-bit
    buf[5] = 1  # little-endian
    struct.pack_into("<HH", buf, 16, 3, 0xB7)  # ET_DYN, EM_AARCH64
    note = _note(build_id)
    buf[0x288 : 0x288 + len(note)] = note
    for name, slots in hal.THRESHOLD_SLOTS.items():
        for value, offset in zip(defaults[name], slots):
            struct.pack_into("<f", buf, offset, value)
    return bytes(buf)


class TestElf(unittest.TestCase):
    def test_is_thermal_hal(self):
        self.assertTrue(hal.is_thermal_hal(make_image()))

    def test_rejects_non_elf(self):
        self.assertFalse(hal.is_thermal_hal(b"not an elf"))

    def test_rejects_32bit(self):
        img = bytearray(make_image())
        img[4] = 1
        self.assertFalse(hal.is_thermal_hal(bytes(img)))

    def test_build_id(self):
        self.assertEqual(hal.elf_build_id(make_image()), hal.KNOWN_BUILD_ID)

    def test_build_id_absent(self):
        img = bytearray(make_image())
        img[0x288 : 0x288 + 0x1C] = b"\x00" * 0x1C
        self.assertIsNone(hal.elf_build_id(bytes(img)))


class TestDecode(unittest.TestCase):
    def test_reads_stock_table(self):
        got = hal.read_thresholds(make_image())
        for name, want in hal.KNOWN_DEFAULTS.items():
            self.assertEqual(tuple(got[name]), want, name)

    def test_verify_defaults_clean(self):
        self.assertEqual(hal.verify_defaults(make_image()), [])

    def test_verify_defaults_flags_other_build(self):
        img = make_image(build_id="00" * 16)
        problems = hal.verify_defaults(img)
        self.assertTrue(any("build-id" in p for p in problems))

    def test_report_marks_skin_as_runtime_overridden(self):
        text = hal.format_report(make_image())
        self.assertIn("SKIN", text)
        self.assertIn("runtime-overridden", text)


class TestPatch(unittest.TestCase):
    def test_apply_profile(self):
        img = make_image()
        out = hal.apply_thresholds(img, hal.PROFILES["sysretq0-hot"])
        got = hal.read_thresholds(out)
        self.assertEqual(tuple(got["CPU"]), (95.0, 100.0, 110.0, 117.0))
        self.assertEqual(tuple(got["GPU"]), (95.0, 100.0, 110.0, 117.0))
        self.assertEqual(tuple(got["NPU"]), (95.0, 100.0, 110.0, 117.0))
        # untouched types keep their stock values
        self.assertEqual(tuple(got["BATTERY"]), hal.KNOWN_DEFAULTS["BATTERY"])

    def test_apply_is_byte_exact_and_local(self):
        img = make_image()
        out = hal.apply_thresholds(img, {"CPU": (90.0, 95.0, 105.0, 120.0)})
        self.assertEqual(len(out), len(img))
        diff = {i for i, (a, b) in enumerate(zip(img, out)) if a != b}
        allowed = {o + i for o in hal.THRESHOLD_SLOTS["CPU"] for i in range(4)}
        # Nothing outside the CPU slots may move (GPU/NPU share those words).
        self.assertTrue(diff <= allowed, sorted(hex(d) for d in diff - allowed))
        self.assertTrue(diff, "expected the image to change")
        self.assertEqual(tuple(hal.read_thresholds(out)["NPU"]), (90.0, 95.0, 105.0, 120.0))

    def test_shared_word_conflict_rejected(self):
        # BATTERY and SKIN both take severity 3 from .rodata 0x8c6c.
        with self.assertRaises(hal.HalError) as ctx:
            hal.apply_thresholds(
                make_image(),
                {"BATTERY": (51.0, 55.0, 59.0, 60.0), "SKIN": (60.0, 70.0, 80.0, 90.0)},
            )
        self.assertIn("conflict", str(ctx.exception))

    def test_shared_word_consistent_ok(self):
        out = hal.apply_thresholds(
            make_image(),
            {"BATTERY": (55.0, 60.0, 64.0, 66.0), "SKIN": (55.0, 70.0, 80.0, 90.0)},
        )
        self.assertEqual(tuple(hal.read_thresholds(out)["SKIN"])[0], 55.0)

    def test_rejects_non_increasing(self):
        with self.assertRaises(hal.HalError):
            hal.apply_thresholds(make_image(), {"CPU": (95.0, 90.0, 100.0, 117.0)})

    def test_rejects_nan(self):
        with self.assertRaises(hal.HalError):
            hal.apply_thresholds(make_image(), {"CPU": (float("nan"), 95.0, 100.0, 117.0)})

    def test_rejects_unknown_type(self):
        with self.assertRaises(hal.HalError):
            hal.apply_thresholds(make_image(), {"FUSION": (1.0, 2.0, 3.0, 4.0)})

    def test_rejects_wrong_arity(self):
        with self.assertRaises(hal.HalError):
            hal.apply_thresholds(make_image(), {"CPU": (1.0, 2.0)})

    def test_strict_refuses_other_build(self):
        img = make_image(build_id="11" * 16)
        with self.assertRaises(hal.HalError):
            hal.apply_thresholds(img, {"CPU": (95.0, 100.0, 110.0, 117.0)})

    def test_force_allows_other_build(self):
        img = make_image(build_id="11" * 16)
        out = hal.apply_thresholds(img, {"CPU": (95.0, 100.0, 110.0, 117.0)}, strict=False)
        self.assertEqual(tuple(hal.read_thresholds(out)["CPU"]), (95.0, 100.0, 110.0, 117.0))

    def test_rejects_empty(self):
        with self.assertRaises(hal.HalError):
            hal.apply_thresholds(make_image(), {})


class TestOffset(unittest.TestCase):
    def test_add_offset_keeps_shutdown(self):
        out = hal.add_offset(make_image(), 10.0, ["CPU"])
        self.assertEqual(tuple(hal.read_thresholds(out)["CPU"]), (95.0, 100.0, 110.0, 117.0))

    def test_add_offset_unknown_type(self):
        with self.assertRaises(hal.HalError):
            hal.add_offset(make_image(), 10.0, ["BOGUS"])


class TestRegistry(unittest.TestCase):
    def test_shared_offsets_are_consistent(self):
        # _slot_map raises if two types claim the same word with different defaults.
        mapping = hal._slot_map()
        self.assertEqual(mapping[0x8C6C], 50.0)

    def test_severities_cover_four_slots(self):
        for slots in hal.THRESHOLD_SLOTS.values():
            self.assertEqual(len(slots), 4)

    def test_profiles_are_valid(self):
        for changes in hal.PROFILES.values():
            hal._plan(changes)  # raises on any inconsistency


class TestHalCli(unittest.TestCase):
    def _invoke(self, *args):
        from mtk_thermal_re import cli

        buf = io.StringIO()
        with contextlib.redirect_stdout(buf), contextlib.redirect_stderr(buf):
            rc = cli.main(list(args))
        return rc, buf.getvalue()

    def test_info(self):
        with tempfile.TemporaryDirectory() as tmp:
            src = Path(tmp) / "impl.so"
            src.write_bytes(make_image())
            rc, out = self._invoke("hal-info", str(src))
            self.assertEqual(rc, 0)
            self.assertIn("CPU", out)
            self.assertIn("reference: yes", out)

    def test_patch_profile(self):
        with tempfile.TemporaryDirectory() as tmp:
            src = Path(tmp) / "impl.so"
            dst = Path(tmp) / "out.so"
            src.write_bytes(make_image())
            rc, out = self._invoke("hal-patch", str(src), str(dst), "--profile", "sysretq0-hot")
            self.assertEqual(rc, 0, out)
            got = hal.read_thresholds(dst.read_bytes())
            self.assertEqual(tuple(got["CPU"]), (95.0, 100.0, 110.0, 117.0))
            self.assertEqual(tuple(got["BATTERY"]), hal.KNOWN_DEFAULTS["BATTERY"])

    def test_patch_set(self):
        with tempfile.TemporaryDirectory() as tmp:
            src = Path(tmp) / "impl.so"
            dst = Path(tmp) / "out.so"
            src.write_bytes(make_image())
            rc, out = self._invoke("hal-patch", str(src), str(dst), "--set", "BATTERY=54,58,62,64")
            self.assertEqual(rc, 0, out)
            self.assertEqual(
                tuple(hal.read_thresholds(dst.read_bytes())["BATTERY"]), (54.0, 58.0, 62.0, 64.0)
            )

    def test_patch_requires_change(self):
        with tempfile.TemporaryDirectory() as tmp:
            src = Path(tmp) / "impl.so"
            src.write_bytes(make_image())
            rc, _ = self._invoke("hal-patch", str(src), str(Path(tmp) / "o.so"))
            self.assertEqual(rc, 2)

    def test_info_rejects_non_hal(self):
        with tempfile.TemporaryDirectory() as tmp:
            src = Path(tmp) / "x.bin"
            src.write_bytes(b"nope")
            rc, _ = self._invoke("hal-info", str(src))
            self.assertEqual(rc, 1)


if __name__ == "__main__":  # pragma: no cover
    unittest.main()
