# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Command line interface for mtk-thermal-re."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from . import __about__, codec, hal, known
from .codec import DecodeError, Variant
from .policy import Policy

__all__ = ["main", "build_parser"]

_VARIANTS = {
    "plaintext": Variant.PLAINTEXT,
    "0": Variant.PLAINTEXT,
    "v10": Variant.V10,
    "10": Variant.V10,
    "v5": Variant.V5,
    "5": Variant.V5,
}


def _read_bytes(path: str) -> bytes:
    if path == "-":
        return sys.stdin.buffer.read()
    return Path(path).read_bytes()


def _write_bytes(path: str, data: bytes) -> None:
    if path == "-":
        sys.stdout.buffer.write(data)
        sys.stdout.buffer.flush()
    else:
        Path(path).write_bytes(data)


def _write_text(path: str, text: str) -> None:
    if path == "-":
        sys.stdout.write(text)
        sys.stdout.flush()
    else:
        Path(path).write_text(text)


def _load(path: str) -> tuple[Policy, Variant]:
    """Read a policy (plaintext or obfuscated) and return (Policy, variant)."""
    data = _read_bytes(path)
    plaintext, variant = codec.decode_auto(data)
    return Policy.parse(plaintext), variant


# --------------------------------------------------------------------------- commands


def cmd_detect(args) -> int:
    rc = 0
    for path in args.files:
        variant = codec.detect(_read_bytes(path))
        if variant is None:
            print("%s: unknown (no [policy_type] header)" % path)
            rc = 1
        else:
            label = "plaintext" if variant == Variant.PLAINTEXT else "v%d" % variant
            print("%s: %s" % (path, label))
    return rc


def cmd_decrypt(args) -> int:
    data = _read_bytes(args.input)
    variant = _VARIANTS[args.variant] if args.variant else codec.detect(data)
    if variant is None:
        print("error: not a thermal policy (bad header)", file=sys.stderr)
        return 1
    out = codec.decrypt(data, variant)
    if args.output:
        _write_bytes(args.output, out)
    else:
        _write_bytes("-", out)
    return 0


def cmd_encrypt(args) -> int:
    data = _read_bytes(args.input)
    variant = _VARIANTS[args.variant] if args.variant else Variant.V10
    if variant == Variant.PLAINTEXT:
        print("error: refusing to 'encrypt' with the plaintext variant", file=sys.stderr)
        return 2
    out = codec.encrypt(data, variant)
    if args.output:
        _write_bytes(args.output, out)
    else:
        _write_bytes("-", out)
    return 0


def cmd_show(args) -> int:
    doc, variant = _load(args.file)
    label = "plaintext" if variant == Variant.PLAINTEXT else "v%d" % variant
    print("# %s  (variant: %s)" % (args.file, label))
    for name in doc.sections():
        sec = doc.require_section(name)
        info = known.section_info(name)
        header = "[%s]" % name
        print("\n" + header)
        if info and info.summary and args.verbose:
            print("  # %s" % info.summary)
        for key, value in sec.items():
            note = ""
            if args.verbose and info and key in info.keys:
                note = "  # %s" % info.keys[key]
            print("  %s= %s%s" % (key, value, note))
    return 0


def cmd_sections(args) -> int:
    doc, _ = _load(args.file)
    for name in doc.sections():
        info = known.section_info(name)
        parser = "unknown" if info is None else "%s @ %s" % (info.parser, info.vma)
        print("%-22s %s" % (name, parser))
    return 0


def cmd_get(args) -> int:
    doc, _ = _load(args.file)
    sec = doc.section(args.section)
    if sec is None:
        print("error: section [%s] not found" % args.section, file=sys.stderr)
        return 1
    value = sec.get(args.key)
    if value is None:
        print("error: key %r not found in [%s]" % (args.key, args.section), file=sys.stderr)
        return 1
    print(value)
    return 0


def cmd_set(args) -> int:
    doc, variant = _load(args.file)
    doc.set(args.section, args.key, args.value)
    text = doc.dumps()
    if variant == Variant.PLAINTEXT:
        out = text.encode("utf-8", "surrogateescape")
    else:
        out = codec.encrypt(text.encode("utf-8", "surrogateescape"), variant)
    dest = args.output or args.file
    _write_bytes(dest, out)
    if dest != "-":
        print("updated %s ([%s] %s= %s)" % (dest, args.section, args.key, args.value))
    return 0


def cmd_validate(args) -> int:
    rc = 0
    for path in args.files:
        data = _read_bytes(path)
        variant = codec.detect(data)
        if variant is None:
            print("%s: FAIL (no [policy_type] header)" % path)
            rc = 1
            continue
        try:
            doc = Policy.parse(codec.decrypt(data, variant))
        except Exception as exc:  # noqa: BLE001 - report any parse failure
            print("%s: FAIL (%s)" % (path, exc))
            rc = 1
            continue
        if "policy_type" not in doc.sections():
            print("%s: FAIL (missing [policy_type])" % path)
            rc = 1
            continue
        label = "plaintext" if variant == Variant.PLAINTEXT else "v%d" % variant
        print("%s: OK (%s, %d sections)" % (path, label, len(doc.sections())))
    return rc


def cmd_schema(args) -> int:
    names = [args.section] if args.section else list(known.SECTIONS)
    for name in names:
        info = known.section_info(name)
        if info is None:
            print("%s: unknown section" % name, file=sys.stderr)
            return 1
        print("[%s]  (%s @ %s)" % (info.name, info.parser, info.vma))
        print("  %s" % info.summary)
        for key, desc in info.keys.items():
            print("    %-30s %s" % (key, desc))
        print()
    return 0


def cmd_version(args) -> int:
    print("%s %s (%s)" % (__about__.__title__, __about__.__version__, __about__.__license__))
    return 0


# --------------------------------------------------------------------------- HAL


def _parse_set(items) -> dict[str, tuple[float, ...]]:
    changes: dict[str, tuple[float, ...]] = {}
    for item in items or []:
        if "=" not in item:
            raise hal.HalError("--set expects TYPE=v1,v2,v3,v4, got %r" % item)
        name, _, raw = item.partition("=")
        try:
            values = tuple(float(x) for x in raw.replace(";", ",").split(","))
        except ValueError as exc:
            raise hal.HalError("--set %s: bad number list %r" % (name, raw)) from exc
        changes[name.strip().upper()] = values
    return changes


def cmd_hal_info(args) -> int:
    data = _read_bytes(args.file)
    try:
        report = hal.format_report(data)
    except hal.HalError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 1
    if args.json:
        import json

        payload = {
            "build_id": hal.elf_build_id(data),
            "size": len(data),
            "reference": not hal.verify_defaults(data),
            "thresholds": {k: list(v) for k, v in hal.read_thresholds(data).items()},
        }
        print(json.dumps(payload, indent=2))
    else:
        print("# %s" % args.file)
        print(report)
    return 0


def cmd_hal_patch(args) -> int:
    data = _read_bytes(args.input)
    try:
        changes = dict(_parse_set(args.set))
        if args.profile:
            if args.profile not in hal.PROFILES:
                print(
                    "error: unknown profile %r (have: %s)"
                    % (args.profile, ", ".join(sorted(hal.PROFILES))),
                    file=sys.stderr,
                )
                return 2
            changes = {**hal.PROFILES[args.profile], **changes}
        if args.add is not None:
            types = [
                t.strip().upper() for t in (args.types or "CPU,GPU,NPU").split(",") if t.strip()
            ]
            current = hal.read_thresholds(data)
            for name in types:
                if name not in current:
                    raise hal.HalError("unknown temperature type %r" % name)
                s3, s4, s5, s6 = current[name]
                changes[name] = (s3 + args.add, s4 + args.add, s5 + args.add, s6)
        if not changes:
            print("error: give --set, --add or --profile", file=sys.stderr)
            return 2
        out = hal.apply_thresholds(data, changes, strict=not args.force)
    except hal.HalError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 1
    _write_bytes(args.output, out)
    changed = sorted(changes)
    print("patched %s -> %s (%s)" % (args.input, args.output, ", ".join(changed)))
    if args.output != "-":
        print(hal.format_report(out))
    return 0


# --------------------------------------------------------------------------- parser


def build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="mtk-thermal-re",
        description="Decode, inspect and tune MediaTek thermal_core policy files.",
    )
    p.add_argument("--version", action="version", version="%(prog)s " + __about__.__version__)
    sub = p.add_subparsers(dest="command", required=True)

    sp = sub.add_parser("detect", help="report the on-disk variant of each file")
    sp.add_argument("files", nargs="+")
    sp.set_defaults(func=cmd_detect)

    sp = sub.add_parser("decrypt", help="decode an obfuscated policy to plaintext")
    sp.add_argument("input")
    sp.add_argument("output", nargs="?")
    sp.add_argument("--variant", choices=sorted(_VARIANTS), help="force a variant")
    sp.set_defaults(func=cmd_decrypt)

    sp = sub.add_parser("encrypt", help="re-obfuscate a plaintext policy")
    sp.add_argument("input")
    sp.add_argument("output", nargs="?")
    sp.add_argument("--variant", choices=sorted(_VARIANTS), default="v10")
    sp.set_defaults(func=cmd_encrypt)

    sp = sub.add_parser("show", help="decode and pretty-print a policy")
    sp.add_argument("file")
    sp.add_argument("-v", "--verbose", action="store_true", help="annotate keys with descriptions")
    sp.set_defaults(func=cmd_show)

    sp = sub.add_parser("sections", help="list sections and the parser that handles them")
    sp.add_argument("file")
    sp.set_defaults(func=cmd_sections)

    sp = sub.add_parser("get", help="read one key from a policy")
    sp.add_argument("file")
    sp.add_argument("section")
    sp.add_argument("key")
    sp.set_defaults(func=cmd_get)

    sp = sub.add_parser("set", help="write one key into a policy (in place by default)")
    sp.add_argument("file")
    sp.add_argument("section")
    sp.add_argument("key")
    sp.add_argument("value")
    sp.add_argument("-o", "--output", help="write elsewhere instead of in place")
    sp.set_defaults(func=cmd_set)

    sp = sub.add_parser("validate", help="check that files are well-formed policies")
    sp.add_argument("files", nargs="+")
    sp.set_defaults(func=cmd_validate)

    sp = sub.add_parser("schema", help="document known sections and keys")
    sp.add_argument("section", nargs="?")
    sp.set_defaults(func=cmd_schema)

    sp = sub.add_parser("version", help="print version and license")
    sp.set_defaults(func=cmd_version)

    sp = sub.add_parser("hal-info", help="decode the thresholds of a thermal HAL .so")
    sp.add_argument("file")
    sp.add_argument("--json", action="store_true", help="emit machine-readable JSON")
    sp.set_defaults(func=cmd_hal_info)

    sp = sub.add_parser("hal-patch", help="rewrite the thresholds of a thermal HAL .so")
    sp.add_argument("input")
    sp.add_argument("output")
    sp.add_argument(
        "--set",
        action="append",
        metavar="TYPE=v3,v4,v5,v6",
        help="set one type's thresholds (repeatable)",
    )
    sp.add_argument(
        "--add", type=float, metavar="DELTA", help="raise the selected types by DELTA degrees"
    )
    sp.add_argument("--types", help="comma list for --add (default CPU,GPU,NPU)")
    sp.add_argument("--profile", choices=sorted(hal.PROFILES), help="start from a built-in profile")
    sp.add_argument(
        "--force", action="store_true", help="patch even if the image is not the reference build"
    )
    sp.set_defaults(func=cmd_hal_patch)
    return p


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    try:
        return args.func(args)
    except (DecodeError, hal.HalError) as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 1
    except FileNotFoundError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 1
    except BrokenPipeError:  # e.g. `... | head`
        return 0


if __name__ == "__main__":  # pragma: no cover
    raise SystemExit(main())
