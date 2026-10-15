<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Policy file format

A policy file is ASCII, INI-like:

```
[policy_type]                 ; MUST be the first section
# comments start with '#'
permanent= Yes

[mtk-skin-control]
sensor= ap_ntc
max_target_tj= 85000
min_target_tj= 55000
trip_tpcb= 43000
target_tpcb= 46000

[charger-cooler]
mode= enabled
threshold= [43000, 46000, 49000, 52000, 56000]
hysteresis= [2000, 2000, 2000, 2000, 2000]
current= [3000, 3000, 3000, 3000, 1000]
```

* `[section]` headers, `key= value` (spaces optional), `#` comments and blank lines.
* List values are bracketed and comma separated: `[a, b, c]`. Up to 20 items.
* Temperatures are **millidegrees Celsius** (`85000` = 85.0 °C).

## Lookup order and persistence

`exe_change_policy(name)` (`0x8940`):

1. If MTBF mode is locked and `name != thermal_mtbf.conf`, refuse.
2. Optional `*_infob.<ext>` variant is preferred when present in
   `/vendor/etc/thermal/`.
3. Search **`/data/vendor/thermal/<name>`** first, then
   **`/vendor/etc/thermal/<name>`**.
4. Write the active name to `/data/vendor/thermal/.current_tp` (flock-protected).
5. If `[policy_type]` contains `permanent= Yes`, also write it to
   `/data/vendor/thermal/.permanent_tp`.

At boot `main` reads `.permanent_tp`; if it names a valid, non-`thermal`/non-`disable`
policy it is applied, otherwise the default **`thermal.conf`** is used.

## `thermal_options.conf`

Optional file that chooses the default policy and the enabled sub-policy set per
device type, using `[option_setting]`:

```
[option_setting]
default= thermal_policy_00.conf
policy= [thermal_policy_00.conf, thermal_policy_02.conf]
angle=  [0, 5, 6, 9]
```

`angle` provides a `[min, max]` device-type range for each entry in `policy`.

## Sections and keys

The registry lives in code (`src/mtk_thermal_re/known.py`) and is queryable:

```sh
mtk-thermal-re schema                 # all sections
mtk-thermal-re schema mtk-skin-control
```

### Highlights

**`[mtk-skin-control]`** — the Adaptive Thermal Control (ATC) controller.
`target_tpcb` is written to `/sys/kernel/thermal/target_tpcb`; `set_ttj`
(`0x2120c`) programs the junction-temperature target into `/sys/kernel/thermal/ttj`
and reprograms trip points.

| key | meaning |
|-----|---------|
| `sensor` | temperature sensor (e.g. `ap_ntc`) |
| `max_target_tj`, `min_target_tj` | junction-temperature window |
| `trip_tpcb` | PCB trip temperature |
| `target_tpcb` | PCB control target (lower => throttle earlier/colder) |
| `atc_mode`, `atc_max_target_tj` | enable/clamp |
| `clusterN_min_throttle_freq`, `gpu_min_throttle_freq` | frequency floors while cooling |

**`[charger-cooler]`** — `threshold[]`/`hysteresis[]`/`current[]` define the charge
current limit per temperature band (written to
`/sys/kernel/charger_cooler/charger_table`).

**`[backlight-cooler]`** — `threshold[]`/`hysteresis[]`/`reduce-brightness[]` define
the display brightness reduction (`lcd-backlight`).

**`[thermalhal-threshold]`** — `level= [severe, critical, emergency, shutdown]` and
matching `threshold[]` reported to the Android thermal HAL.

**`[cpu_table_mapping]` / `[gpu_table_mapping]` / `[cpu_isolate]`** — CPU/GPU
frequency caps and CPU isolation.

**PA / RF coolers** (`[mutt-pa1-cooler]`, `[tx-pwr-pa2]`, `[scg-off-pa2]`, …) —
modem/RF power back-off with `threshold[]`/`hysteresis[]`/`limit-state[]`.

**The shipped "off" policies** (`disable_thermal.conf`, `disable_thermal_temp.conf`,
`disable_throttling.conf`) disable protection by setting
`max_target_tj = min_target_tj = 300000` and either
`HW_protection= disabled` (calls `set_hw_reboot(0)`) or extreme HAL thresholds.

See [tuning-guide.md](tuning-guide.md) for the safe way to use them.
