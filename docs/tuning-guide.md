<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Tuning guide

> **Warning.** Thermal limits exist to protect the SoC, battery and enclosure.
> Loosening them can cause throttling instability, battery swelling, accelerated
> ageing or permanent hardware damage. Change one value at a time, monitor
> `/sys/class/thermal/thermal_zone*/temp` and `logcat -s thermal_core`, and always
> keep a known-good policy to fall back to. Tune only devices you own or are
> authorised to modify.

## Where policies live

| priority | location | notes |
|---|---|---|
| 1 (wins) | `/data/vendor/thermal/<name>` | user overlay; survives `apply` |
| 2 | `/vendor/etc/thermal/<name>` | vendor default (obfuscated) |
| boot default | `thermal.conf` | unless `.permanent_tp` names another |

`exe_change_policy` writes the active policy name to
`/data/vendor/thermal/.current_tp`, and — if `[policy_type]` says
`permanent= Yes` — also to `.permanent_tp`, which `main` re-applies at boot.

## Option A — plaintext overlay (recommended)

The loader treats a file whose **first line is exactly `[policy_type]`** as
plaintext. So the simplest, safest workflow needs no re-obfuscation:

```sh
# 1. Decode the current vendor policy to a working copy.
mtk-thermal-re decrypt /vendor/etc/thermal/thermal.conf my_tune.conf

# 2. Edit one or more values (CLI edits in place, preserving text).
mtk-thermal-re set my_tune.conf mtk-skin-control target_tpcb 53000
$EDITOR my_tune.conf            # the first line MUST stay [policy_type]

# 3. Install as an overlay and hot-swap it in.
cp my_tune.conf /data/vendor/thermal/my_tune.conf
thermal_intf apply my_tune.conf

# 4. (optional) make it the boot default.
mtk-thermal-re set /data/vendor/thermal/my_tune.conf policy_type permanent Yes
thermal_intf apply my_tune.conf
```

To revert:

```sh
thermal_intf apply thermal.conf
rm -f /data/vendor/thermal/.permanent_tp
```

## Option B — replace the vendor policy (re-obfuscated)

Use this when something insists on the vendor path. Keep the overlay location
anyway — it is still safer than writing `/vendor`:

```sh
mtk-thermal-re decrypt /vendor/etc/thermal/thermal.conf tuned.conf
$EDITOR tuned.conf
mtk-thermal-re encrypt tuned.conf /data/vendor/thermal/thermal.conf
thermal_intf apply thermal.conf
```

## Recipes

### Cool the device down (less performance, lower temperatures)

In `[mtk-skin-control]`, lowering the PCB targets makes ATC start throttling
earlier:

```
target_tpcb= 44000      # was 46000  (lower => throttle earlier/colder)
trip_tpcb=   41000      # was 43000
```

Also lower what the Android HAL escalates on, and the charge current bands:

```
[thermalhal-threshold]
threshold= [38000, 41000, 44000, 47000]

[charger-cooler]
current= [2000, 2000, 2000, 1000, 500]
```

### More sustained performance (runs hotter)

```
[mtk-skin-control]
target_tpcb= 48000      # throttle later
trip_tpcb=   45000
```

Raise the HAL escalation thresholds to match. Do **not** touch
`max_target_tj`/`min_target_tj` unless you understand ATC — they are the ATC
junction window, not a plain cap.

### Set the CPU/GPU frequency floor while cooling

`clusterN_min_throttle_freq` / `gpu_min_throttle_freq` are the floors ATC will
not go below. Raising them keeps the device responsive but hotter:

```
cluster0_min_throttle_freq= 1200000
cluster1_min_throttle_freq= 1200000
gpu_min_throttle_freq= 300000
```

### Reference examples

All under `examples/`, each with a `.conf.enc` obfuscated twin:

| profile | change | notes |
|---|---|---|
| `sysretq0_hot.conf` | **+5.0 °C** on `target_tpcb`/`trip_tpcb`/`min_target_tj`, `severe` +5 °C | runs hotter but remains pinned to the vendor's own hottest shipped values; hard rails untouched |
| `thermal_performant.conf` | `target_tpcb`/`trip_tpcb` +7 °C, HAL raised | more headroom, runs hottest of the three |
| `thermal_cool.conf` | targets lowered, HAL lowered | trade performance for lower temperatures |

`sysretq0_hot` is also provided obfuscated and named for direct placement at
`/vendor/etc/thermal/thermal.conf` as `examples/vendor/thermal.conf`. See
[`../examples/vendor/README.md`](../examples/vendor/README.md).

The `sysretq0_hot` profile is deliberately bounded by the vendor's **own** hottest
policy: `thermal_policy_08.conf` / `thermal_mtbf.conf` ship
`target_tpcb=51000`, `trip_tpcb=48000`, `min_target_tj=60000`, `severe=52000`.
The profile uses exactly those values (never more), and leaves `max_target_tj=85000`,
the 80.0 °C HAL shutdown, the charger-current bands and the backlight limits
unchanged. `tests/test_examples.py` enforces all of this.

## Live toggles (no file editing)

```sh
thermal_intf apply thermal_policy_08.conf   # hot-swap a different stock policy
thermal_intf debug_log 1                    # verbose logging (logcat tag: thermal_core)
thermal_intf mtbf_mode 1                    # lock the MTBF policy
thermal_intf md_off 1                       # disable modem thermal interaction
```

`apply` re-parses the file and switches live; `change_policy` rejects
`thermal_options.conf` and registered sub-policy names.

## The shipped "off" policies

`disable_thermal.conf`, `disable_thermal_temp.conf` and `disable_throttling.conf`
set `max_target_tj = min_target_tj = 300000`, pin all HAL thresholds at `300000`
(or `80000`) and, for `disable_throttling.conf`, `HW_protection= disabled`
(a `set_hw_reboot(0)` call). They remove the software safety net — use them only
for a diagnosis you revert immediately.

## Verifying a change

```sh
mtk-thermal-re validate my_tune.conf          # parses & has [policy_type]
mtk-thermal-re show my_tune.conf -v           # annotated, decoded view
mtk-thermal-re get my_tune.conf mtk-skin-control target_tpcb
adb shell 'cat /sys/kernel/thermal/target_tpcb'
adb shell 'logcat -d -s thermal_core'
```
