<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Reverse-engineering methodology and evidence

This project was produced by analysing three stripped arm64 ELF binaries and the
obfuscated policy files they consume. This document records *how* the conclusions
were reached so they can be independently reproduced.

## Targets

| file | type | role |
|------|------|------|
| `thermal_core` | arm64 ELF, stripped, PIE | thermal daemon: parser + algorithms + control |
| `thermal_intf` | arm64 ELF, stripped | CLI client for the daemon socket |
| `android.hardware.thermal@2.0-service.mtk` | arm64 ELF, stripped | thin HIDL 2.0 passthrough |
| `thermal/*.conf` | obfuscated text | shipped policies |

## Step 1 — recover symbols from `.gnu_debugdata`

All three binaries carry an embedded `.gnu_debugdata` section: a mini
symbol table stored as a **XZ-compressed ELF**. Unpacking it restores the full
function symbol list that was stripped from the main file.

```sh
objcopy --dump-section .gnu_debugdata=tc.debug data thermal_core
xz -d -c tc.debug.data > tc.debug.elf     # it is an XZ stream wrapping an ELF
nm -n tc.debug.elf > symbols.txt
```

The recovered symbol names are the backbone of the analysis. The full table
(170 symbols) is preserved verbatim in
[`reverse/symbols.csv`](../reverse/symbols.csv) with the columns
`binary,address,address_hex,size,type,name`.

> Note: `.gnu_debugdata` supplies **function names and addresses**, not types,
> locals or line numbers. Structure layouts below were inferred from decompiled
> code and call sites, not from DWARF.

## Step 2 — decompile with Ghidra

Functions were decompiled with Ghidra via PyGhidra. The harness used is kept in
[`reverse/scripts/decompile.py`](../reverse/scripts/decompile.py).

```sh
/opt/pyghidra-venv/bin/python reverse/scripts/decompile.py \
    /path/to/thermal_core 0x103fc:tp_decrypt_v1 0x8940:exe_change_policy ...
```

Two practical notes:

* `pyghidra.start()` must be called **before** importing any `ghidra.*` module.
* Ghidra images this binary at a base of `0x100000`, so a file VMA of `0x8000`
  appears as `0x108000` in the tool. The addresses quoted everywhere in this
  project are **file VMAs** (`.text` starts at `0x8000`), i.e. `ghidra_addr - imageBase`.

The decompiled C for the key functions is stored under
[`reverse/decompiled/`](../reverse/decompiled/), one file per function, named
`<symbol>.<vma>.c`. It is provided as evidence and is **not** part of the
installable package.

## Step 3 — identify the config transform

The loader symbol `exe_change_policy` (`0x8940`) calls `tp_decrypt_v1`
(`0x103fc`). Reading `tp_decrypt_v1` yields the byte loop:

```c
for each line:
    for (i = 0; i < len; ++i) {
        c = line[i];
        if (c >= 0x20 && c <= 0x7a)
            out = ((c - (i % step) + 0x3b) % 91) + 0x20;
        else
            out = c;               /* newline / control bytes pass through */
    }
```

with `step` being a parameter (10 on the shipped path, 5 on an alternate path).
Because the map is a bijection on `0x20..0x7a`, the transform is trivially
invertible — this is obfuscation, not cryptography. See
[`obfuscation.md`](obfuscation.md).

Validation was by round-trip: every shipped file decrypts to readable INI text and
`encrypt(decrypt(x)) == x` byte-for-byte for all nine files and both step
variants (enforced by `tests/test_codec.py`).

## Step 4 — establish the loader semantics

`exe_change_policy` (`0x8940`) was decompiled to recover:

* the file search order (`/data/vendor/thermal/` then `/vendor/etc/thermal/`);
* the `*_infob.<ext>` preference;
* the `.current_tp` / `.permanent_tp` persistence files and `flock` usage;
* the **first-line mode detection** table (plaintext / step 10 / step 5).

The `[policy_type]` `permanent= Yes` handling and the boot-default logic
(`main` `0xd00c`) come from the same function and the startup path.

## Step 5 — map the socket command interface

`thermal_intf:main` (`0x1054`) joins `argv[1..]` with `"%s "` (rodata `0x694`)
and sends ≤128 bytes to `/dev/socket/thermal_socket`. On the daemon side,
`main` receives the datagram and hands it to `cmd_handler` (`0xfeb0`), which
string-compares and dispatches:

| command | handler |
|---|---|
| `apply` | `change_policy` (`0x2186c`) |
| `mtbf_mode` | loads/locks `thermal_mtbf.conf` |
| `md_off` | modem thermal interaction on/off |
| `debug_log` | global verbose flag |
| `frs` | `frs_cmd_handle` |

## Step 6 — enumerate the policy sections

Section names and their owning parsers were recovered from the decompiled parsers
and their string comparisons. The registry is encoded in
[`src/mtk_thermal_re/known.py`](../src/mtk_thermal_re/known.py) and can be queried
with `mtk-thermal-re schema`. Parser addresses are listed in
[`reverse/symbols.csv`](../reverse/symbols.csv); the notable ones:

| section | parser | VMA |
|---|---|---|
| `[mtk-skin-control]` | `skin_control_parser` | `0x153f0` |
| `[mtk-skin-control]` targets | `set_ttj` | `0x2120c` |
| `[charger-cooler]` | `charger_cooler_parser` | `0x18454` |
| `[backlight-cooler]` | `backlight_cooler_parser` | `0x19f34` |
| `[thermalhal-threshold]` | `thermal_hal_threshold_parser` | `0x1924c` |
| `[LTF-disable-throttling]` | `disable_throttling_parser` | `0x104cc` |
| `[cpu_table_mapping]` | `cpu_table_mapping_parser` | `0x15a70` |
| ATC math | `calcu_ap_param` | `0x28e58` |

## Evidence index

| path | contents |
|---|---|
| `reverse/symbols.csv` | 170 recovered symbols (`binary,address,address_hex,size,type,name`) |
| `reverse/decompiled/*.c` | Ghidra C for 13 key functions |
| `reverse/scripts/decompile.py` | the PyGhidra harness used to produce them |
| `data/samples/` | the 9 original obfuscated policies (inputs) |
| `data/policies/` | their verified plaintext decodes (outputs) |
| `tests/` | round-trip and behavioural tests that lock the findings in |

## Open questions

These were not exhaustively reconstructed and are flagged honestly:

* the exact `[option_setting]`/`angle` device-type matching used by
  `thermal_options.conf`;
* the full ATC control math in `calcu_ap_param` (`0x28e58`) and
  `algorithm_thread` (`0xb580`) — first-order behaviour (program
  `target_tpcb`/`ttj`, set trip points, ramp cooler state per threshold table) is
  established, the steady-state controller is not;
* the precise semantics of some modem/RF `limit-state[]` encodings.
