<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Architecture

```
 +---------------------+      text command        +----------------------------+
 |  thermal_intf       |  e.g. "apply foo.conf"   |  thermal_core (daemon)      |
 |  (CLI)              | -----------------------> |  /dev/socket/thermal_socket |
 +---------------------+    AF_LOCAL datagram     |   -> thermal_add_job()      |
                                                  |   -> cmd_handler() @0xfeb0  |
 +---------------------+                          |                             |
 | IThermal 2.0 HAL    | <--- notifications ----  |  reads /vendor/etc/thermal  |
 | @2.0-service.mtk    |      (*(thermal_hal_     |        /data/vendor/thermal |
 +---------------------+       socket))           +----------------------------+
```

## Components

| file | role | notes |
|------|------|-------|
| `thermal_core` | the daemon | config parser (`exe_change_policy` `0x8940`), control algorithms (`algorithm_thread` `0xb580`), socket server, `main` `0xd00c` |
| `thermal_intf` | CLI client | connects `/dev/socket/thermal_socket`, sends `argv[1..]` joined by `"%s "` (max 128 bytes) |
| `android.hardware.thermal@2.0-service.mtk` | HIDL 2.0 passthrough | only `main` + a string ctor; registers `IThermal/V2_0` |
| `android.hardware.thermal@2.0-impl.so` | HIDL 2.0 implementation | AOSP `ThermalHelper` with a compiled-in MTK threshold table — see [hal.md](hal.md) |
| `thermal_hal.so` | HAL helpers | `mtk_get_temperatures()` reads `/proc/mtktz/*` |

## Threads started by `thermal_core:main`

`algorithm_thread`, the FRS cooler thread, `md_thermal_thread`, `thermal_worker`,
`hinge_update_thread`, `hinge_check_thread`, then `create_socket_server()` followed
by an `accept()`/`recvfrom()` loop.

## Command path

1. `thermal_intf` connects to `/dev/socket/thermal_socket` (AF_LOCAL/SOCK_DGRAM)
   and sends `"<cmd> <arg> …\n"`.
2. `main` receives up to 128 bytes, NUL-terminates and calls `thermal_add_job()`.
3. A worker calls `cmd_handler` (`0xfeb0`), which parses the command and dispatches.

## Notification path

`send_notification_to_thermal_hal` (`0x23920`) emits `TYPE=thermal_hal_update …`
strings to the thermal HAL over `/dev/socket/thermal_hal_socket`. These are the
severity/threshold notifications in `[thermalhal-threshold]`.

## System interfaces touched

* `/sys/class/thermal/thermal_zoneN/…` — zones, trip points, modes, cdev weights
* `/sys/class/thermal/cooling_deviceN/…` — cooling device state
* `/sys/kernel/thermal/target_tpcb`, `/sys/kernel/thermal/ttj` — ATC targets
* `/sys/kernel/thermal/info_b`, `/sys/kernel/ccci/boot` — device info
* `/sys/kernel/charger_cooler/charger_table` — charge current table
* `/proc/gpufreqv2/…` — GPU OPP tables
* `/proc/device-tree/chosen/atag,devinfo` + `efuse_read` — device-type detection
