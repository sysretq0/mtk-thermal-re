<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Thermal HAL evidence

Evidence for **[`../../docs/hal.md`](../../docs/hal.md)** — the vendor
`android.hardware.thermal@2.0-impl.so` (build-id
`ce2460711bd53e46ecd0d3373aaf641c`, 100304 bytes).

```
impl20.symbols.tsv   recovered symbols (.dynsym + .gnu_debugdata), addr/kind/name
*.c                  Ghidra C for the threshold and data-path functions:
  fill_thresholds.12e50.c            builds the reported TemperatureThreshold list
  getSeverityFromThresholds.11970.c  temp -> ThrottlingSeverity (reads the table)
  getTemperatureThresholds.b8a8.c    HIDL entry point
  read_temperature.11c54.c           reads /sys/class/thermal/*/temp
  fill_temperatures.12a9c.c          builds the reported Temperature list
  ThermalHelper_ctor.1123c.c         starts the watcher thread
  global_thermal_helper.ff60.c       the load-time writer of kMtkTempThreshold
  get_tz_map.13d98.c, init_tz_path.12a40.c   zone table setup
```

## Addresses

As elsewhere, values are **file VMAs**; the binary is a PIE shared object whose
`.text` starts at `0xb000`. Ghidra reports these at `image_base + vma`
(`0x100000`), so `vma = ghidra_address - 0x100000`.

## The trigger

`_GLOBAL__sub_I_thermal_helper.cpp` (`0xff60`) writes the global
`kMtkTempThreshold` array (`.bss` `0x1a000`, 880 bytes = 10 × 0x58) at load time
using 128-bit loads from `.rodata` at `0x8c10..0x8c8c`. `getSeverityFromThresholds`
(`0x11970`) then compares the live temperature against the six floats at entry
offsets `0x1c..0x30`. Rewriting those four non-`NaN` `.rodata` floats is exactly
what `mtk-thermal-re hal-patch` does.

## Regenerating

```sh
/opt/pyghidra-venv/bin/python ../scripts/decompile.py \
    /path/to/android.hardware.thermal@2.0-impl.so \
    0x12e50:fill_thresholds \
    0x11970:getSeverityFromThresholds \
    0xb8a8:getTemperatureThresholds \
    0x11c54:read_temperature \
    0x12a9c:fill_temperatures
```
