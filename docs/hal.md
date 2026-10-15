<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# The MediaTek thermal HAL

`thermal_core` owns the *policy* (see [architecture.md](architecture.md)); the HAL
is the component the Android framework communicates with. This document describes
the HAL as it ships on the reference device, the thresholds it hard-codes, and how
this toolkit rewrites them.

## Components

| Path | Role |
| --- | --- |
| `/vendor/bin/hw/android.hardware.thermal@2.0-service.mtk` | HIDL service entry point (`service.mtk`) |
| `/vendor/lib64/hw/android.hardware.thermal@2.0-impl.so` (`impl20.so`) | AOSP `ThermalHelper` plus MTK overrides; the thresholds are compiled in here |
| `/vendor/lib64/hw/thermal_hal.so` | MTK helpers (`mtk_get_temperatures`, reading `/proc/mtktz/*`) |

All three are stripped but carry a `.gnu_debugdata` section, so full symbol
tables were recovered (method: [reverse-engineering.md](reverse-engineering.md)).

`impl20.so` is the AOSP 2.0 default implementation with a MediaTek
`thermal_helper.cpp`. The notable difference from stock AOSP is that it does
not parse `thermal_info_config.json`; its thresholds come from a compiled-in
table.

## Temperature types and the threshold table

Every `TemperatureType` gets one 0x58-byte entry in the global
`kMtkTempThreshold` array (indexed by type id):

```
0x00  type (uint32)
0x08  name (hidl_string)
0x1c  hot threshold, ThrottlingSeverity 1   \
0x20  hot threshold, ThrottlingSeverity 2    |  six float slots,
0x24  hot threshold, ThrottlingSeverity 3    |  compared high->low by
0x28  hot threshold, ThrottlingSeverity 4    |  getSeverityFromThresholds()
0x2c  hot threshold, ThrottlingSeverity 5    |
0x30  hot threshold, ThrottlingSeverity 6   /
0x50  scalar hot threshold
```

The array is filled once at load by `_GLOBAL__sub_I_thermal_helper.cpp` using
128-bit loads from `.rodata`. For the meaningful types the first two severity
slots are `NaN` (disabled) and the last four are populated, so the framework sees
a four-value list:

| TemperatureType | sev3 | sev4 | sev5 | sev6 | source |
| --- | --- | --- | --- | --- | --- |
| CPU | 85 | 90 | 100 | 117 | `.rodata` |
| GPU | 85 | 90 | 100 | 117 | `.rodata` |
| NPU | 85 | 90 | 100 | 117 | `.rodata` |
| BATTERY | 50 | 55 | 59 | 60 | `.rodata` |
| SKIN | 50 | 70 | 80 | 90 | `.rodata` (**overridden at runtime**) |
| POWER_AMPLIFIER | 68 | 90 | 100 | 110 | `.rodata` |

These match `dumpsys thermalservice` exactly, which is the primary evidence.

Note the type ids: CPU/GPU/NPU share one set of `.rodata` words, and BATTERY and
SKIN share the word that supplies severity 3. Patching a shared word moves every
type that reads it.

## What actually controls what

Two distinct mechanisms are called "throttling":

* **Real DVFS protection** — kernel / `thermal_core`. Controlled by the policy
  files (`/vendor/etc/thermal/*.conf`). This is the layer that keeps silicon
  safe, and the layer the [tuning guide](tuning-guide.md) tunes.
* **Framework-visible status** — what `ThermalManagerService` reports to apps
  and `PowerManager`. The HAL computes this: `read_temperature()` reads
  `/sys/class/thermal/thermal_zone*/temp`, and `getSeverityFromThresholds()`
  maps the value against `kMtkTempThreshold`. `notifyThrottling()` pushes the
  result to the framework.

Raising the HAL thresholds therefore makes **the framework** less reactive. It
does **not** raise the hardware trip points.

`SKIN` is special: `thermal_core` re-writes its thresholds over
`/dev/socket/thermal_hal_socket` at boot from `[thermalhal-threshold]` in
`thermal.conf`. Patching SKIN's `.rodata` default has no lasting effect, so SKIN
is tuned through the vendor config instead.

## Inspecting

```sh
# decode every type from a pulled .so
mtk-thermal-re hal-info /path/to/android.hardware.thermal@2.0-impl.so

# machine-readable
mtk-thermal-re hal-info impl20.so --json
```

## Patching

```sh
# the bundled "hotter but within the rails" profile (CPU/GPU/NPU +10 °C on sev3-5)
mtk-thermal-re hal-patch impl20.so impl20.sysretq0.so --profile sysretq0-hot

# explicit values (one line per type, severity 3..6)
mtk-thermal-re hal-patch impl20.so out.so --set CPU=95,100,110,117

# bulk uplift of the compute types
mtk-thermal-re hal-patch impl20.so out.so --add 8 --types CPU,GPU,NPU
```

The patcher:

* refuses any image that is not the reference build-id/size **unless**
  `--force` is given, so a differently-built vendor `.so` can never be silently
  mangled;
* rejects non-increasing or `NaN` thresholds;
* refuses to make one shared `.rodata` word hold two different values;
* touches only the 4-byte floats it must; the reference profile changes 3 bytes.

### Applying and rolling back

```sh
sudo nsenter -t 1 -m sh -c '
  cp /vendor/lib64/hw/android.hardware.thermal@2.0-impl.so \
     /data/local/tmp/impl20.so.stock
  cp /data/local/tmp/impl20.sysretq0.so \
     /vendor/lib64/hw/android.hardware.thermal@2.0-impl.so
  stop vendor.thermal-hal-2-0
  start vendor.thermal-hal-2-0
'
```

Rollback is the reverse copy, then `dumpsys thermalservice` should show the
stock thresholds again. Keep `impl20.so.stock` off-device as well. `/vendor` is
not verified on the reference device, so the copy is durable without a repack.

## Safety envelope

The profile here only lifts the framework-visible severity onset for the compute
types. It deliberately leaves the following untouched:

* the SHUTDOWN slot (severity 6);
* every safety-critical type (BATTERY, POWER_AMPLIFIER);
* SKIN, which `thermal_core` governs;
* the hardware trip points in the kernel / `thermal_core` policy.

`tests/test_hal.py` encodes these invariants.
