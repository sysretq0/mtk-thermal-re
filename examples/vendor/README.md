<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# /vendor drop-in: sysretq0 hot profile

`thermal.conf` in this directory is the obfuscated (V10) build of
[`../sysretq0_hot.conf`](../sysretq0_hot.conf), byte-identical to
`../sysretq0_hot.conf.enc`. It is encoded exactly like the stock MediaTek policy
files (the `[qqomh$f!'pf_` header), so the daemon accepts it at
`/vendor/etc/thermal/`.

The profile runs hotter by moving the throttle targets to the vendor's own hottest
shipped values (+5.0 °C) while leaving every hard rail in place. The header comment
in [`../sysretq0_hot.conf`](../sysretq0_hot.conf) documents the exact envelope.

## Verify before copying

```sh
mtk-thermal-re detect  thermal.conf     # -> thermal.conf: v10
mtk-thermal-re decrypt thermal.conf     # -> plaintext, branded header
mtk-thermal-re validate thermal.conf    # -> OK
```

## Back up the original first

```sh
adb shell su -c 'cp /vendor/etc/thermal/thermal.conf /sdcard/thermal.conf.stock'
adb pull /sdcard/thermal.conf.stock      # keep an off-device copy
```

## Install to /vendor/etc/thermal/ (root; requires an rw remount)

```sh
adb push thermal.conf /data/local/tmp/thermal.conf
adb shell su -c 'mount -o rw,remount /vendor'
adb shell su -c 'cp /data/local/tmp/thermal.conf /vendor/etc/thermal/thermal.conf'
adb shell su -c 'chmod 644 /vendor/etc/thermal/thermal.conf'
adb shell su -c 'sync'
adb shell su -c 'thermal_intf apply thermal.conf'
```

## Alternative: user overlay (no /vendor write)

`/data/vendor/thermal/` is searched before `/vendor/etc/thermal/`, so an overlay
takes precedence without touching the vendor partition and survives reboot because
`permanent= Yes` is set in the profile:

```sh
adb push thermal.conf /data/local/tmp/thermal.conf
adb shell su -c 'cp /data/local/tmp/thermal.conf /data/vendor/thermal/thermal.conf'
adb shell su -c 'thermal_intf apply thermal.conf'
```

## Roll back

```sh
adb push thermal.conf.stock /data/local/tmp/thermal.conf
adb shell su -c 'cp /data/local/tmp/thermal.conf /vendor/etc/thermal/thermal.conf'
adb shell su -c 'rm -f /data/vendor/thermal/.permanent_tp'
adb shell su -c 'thermal_intf apply thermal.conf'
```

If the device does not boot cleanly after a `/vendor` change, boot to recovery and
restore `thermal.conf.stock` to `/vendor/etc/thermal/thermal.conf`.

## Confirm it took effect

```sh
adb shell 'cat /sys/kernel/thermal/target_tpcb'   # expect ~51000
adb shell 'logcat -d -s thermal_core'             # look for the applied policy
```
