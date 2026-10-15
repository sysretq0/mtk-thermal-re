<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Reverse-engineering evidence

This directory preserves the raw evidence behind the analysis in
[`../docs/reverse-engineering.md`](../docs/reverse-engineering.md). It is **not**
part of the installable package.

```
symbols.csv       170 functions recovered from the binaries' .gnu_debugdata
                  (columns: binary,address,address_hex,size,type,name)
decompiled/       Ghidra C for the key functions, one file per function,
                  named <symbol>.<file-vma>.c
scripts/          the PyGhidra harness used to produce decompiled/
```

## Addresses

All addresses in `symbols.csv`, `decompiled/*.c` filenames and the documentation
are **file VMAs inside the stripped binary** (`.text` starts at `0x8000`).

Ghidra loads these PIE binaries at an image base of `0x100000`, so inside Ghidra
the same function appears at `image_base + vma` (e.g. `0x103fc` → `0x1103fc`).
Convert with `ghidra_address - 0x100000`.

## Regenerating the decompilation

Requires `pyghidra` and the target binaries (not distributed here — see
`../NOTICE`).

```sh
/opt/pyghidra-venv/bin/python scripts/decompile.py \
    /path/to/thermal_core \
    0x103fc:tp_decrypt_v1 \
    0x8940:exe_change_policy \
    0xfeb0:cmd_handler \
    ...
```

Two gotchas baked into the harness:

* `pyghidra.start()` must run **before** any `ghidra.*` import.
* Pass file VMAs; the script adds the image base internally.

## Key functions

| symbol | VMA | why it matters |
|---|---|---|
| `tp_decrypt_v1` | `0x103fc` | the policy transform (see docs/obfuscation.md) |
| `exe_change_policy` | `0x8940` | policy resolution, mode detection, persistence |
| `cmd_handler` | `0xfeb0` | the socket command dispatcher |
| `change_policy` | `0x2186c` | live policy switch |
| `thermal_options_checker` | `0x87b0` | `thermal_options.conf` handling |
| `skin_control_parser` | `0x153f0` | `[mtk-skin-control]` |
| `set_ttj` | `0x2120c` | programs `/sys/kernel/thermal/ttj` |
| `charger_cooler_parser` | `0x18454` | `[charger-cooler]` |
| `backlight_cooler_parser` | `0x19f34` | `[backlight-cooler]` |
| `thermal_hal_threshold_parser` | `0x1924c` | `[thermalhal-threshold]` |
| `disable_throttling_parser` | `0x104cc` | `[LTF-disable-throttling]` |
| `calcu_ap_param` | `0x28e58` | ATC control math (partially reconstructed) |
| `main` | `0xd00c` | startup, boot-default policy, socket server |
