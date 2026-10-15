<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Changelog

All notable changes to this project are documented here.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [1.0.0] - 2026-10-15

Initial release: the full reverse-engineering result plus a packaged toolkit.

### Added

- **Codec** (`mtk_thermal_re.codec`): `tp_decrypt_v1` decode/encode for both
  variants (`i % 10` and `i % 5`), plus first-line variant detection and the
  `DecodeError` type. The transform is a position-dependent bijection over
  `0x20..0x7a`; round-trip is byte-exact.
- **Policy parser** (`mtk_thermal_re.policy`): line-preserving INI-like parser
  (`Policy`, `Section`, `parse_list`) that keeps comments/ordering and supports
  in-place single-key edits.
- **Section registry** (`mtk_thermal_re.known`): every recovered section/key with
  a description and the parser symbol + VMA that owns it.
- **CLI** (`mtk_thermal_re.cli`): `detect`, `decrypt`, `encrypt`, `show`,
  `sections`, `get`, `set`, `validate`, `schema`, `version`. `set` preserves a
  file's original encoding.
- **Tests**: stdlib `unittest` suite covering the codec, parser and CLI, with
  real obfuscated/plaintext policy fixtures.
- **Data**: decoded plaintext copies of the nine shipped policies
  (`data/policies/`) and the originals (`data/samples/`); tuned example policies
  with obfuscated twins (`examples/`).
- **RE evidence** (`reverse/`): 170 recovered symbols (`symbols.csv`), Ghidra
  decompilation of 13 key functions (`decompiled/`), and the PyGhidra harness
  (`scripts/decompile.py`).
- **Docs**: architecture, obfuscation, config format, tuning guide and
  reverse-engineering methodology.

### Findings captured

- Config "encryption" is reversible obfuscation (no key). Formula and inverse
  documented.
- The loader treats a policy whose first line is exactly `[policy_type]` as
  plaintext — the primary, no-rebuild tuning path.
- File resolution order `/data/vendor/thermal/` → `/vendor/etc/thermal/`, with
  `.current_tp` / `.permanent_tp` persistence.
- Socket command set: `apply`, `mtbf_mode`, `md_off`, `debug_log`, `frs`.

[Unreleased]: https://example.invalid/mtk-thermal-re/compare/v1.0.0...HEAD
[1.0.0]: https://example.invalid/mtk-thermal-re/releases/tag/v1.0.0
