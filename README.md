<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# mtk-thermal-re

> Reverse-engineering and tuning toolkit for the MediaTek `thermal_core` thermal
> daemon and the vendor thermal HAL.
>
> Maintained by [sysretq0](https://github.com/sysretq0).

`thermal_core` is MediaTek's thermal daemon for Android. It reads INI-like policy
files (`thermal.conf`, `thermal_policy_XX.conf`, `thermal_mtbf.conf`, ...), but the
shipped files use a position-dependent obfuscation and the binary is stripped.
This project documents the subsystem and provides tooling to:

* decode, inspect, edit and re-encode those policy files;
* drive the runtime socket interface used to switch policies on a live device;
* inspect and re-patch the vendor thermal HAL.

The reverse-engineering that backs the tooling — function addresses, the
`tp_decrypt_v1` transform, the socket command set, the section/key registry and the
HAL threshold table — is recorded in `docs/` and `reverse/`.

## Features

- Decode and re-encode the `tp_decrypt_v1` obfuscation (both the `i % 10` and
  `i % 5` variants).
- Structured policy parser that preserves comments and ordering.
- Edit a single key while retaining the file's original on-disk encoding.
- Registry of every known section and key, each tied to the parser function that
  owns it.
- Documentation of the `/dev/socket/thermal_socket` command interface
  (`apply`, `mtbf_mode`, ...).
- Inspection and patching of the vendor thermal HAL threshold table
  (`hal-info`, `hal-patch`).
- Plaintext policy overlay for `/data/vendor/thermal/`, requiring no
  re-obfuscation.
- Standard-library-only test suite; no third-party runtime dependencies.

## Thermal profiles

A ready-to-use **sysretq0** profile is included. `sysretq0_hot` raises the
throttle targets by a uniform **+5.0 °C** while remaining within the vendor's own
safe envelope: it adopts the vendor's hottest shipped values
(`thermal_policy_08` / `thermal_mtbf`) and leaves the hard rails unchanged
(85.0 °C junction clamp, 80.0 °C HAL shutdown, charge-current and backlight
limits, and hardware protection).

| file | encoding | use |
|---|---|---|
| [`examples/sysretq0_hot.conf`](examples/sysretq0_hot.conf) | plaintext | read and edit; overlay into `/data/vendor/thermal/` |
| [`examples/sysretq0_hot.conf.enc`](examples/sysretq0_hot.conf.enc) | V10 | obfuscated twin |
| [`examples/vendor/thermal.conf`](examples/vendor/thermal.conf) | V10 | drop-in for `/vendor/etc/thermal/thermal.conf` |

```sh
# Verify, then install to /vendor (root; back up the original first):
mtk-thermal-re decrypt examples/vendor/thermal.conf
adb push examples/vendor/thermal.conf /data/local/tmp/thermal.conf
adb shell su -c 'mount -o rw,remount /vendor'
adb shell su -c 'cp /data/local/tmp/thermal.conf /vendor/etc/thermal/thermal.conf'
adb shell su -c 'thermal_intf apply thermal.conf'
```

See [`examples/vendor/README.md`](examples/vendor/README.md) for backups, rollback
and the safer `/data/vendor/thermal/` overlay path.

## The thermal HAL

`thermal_core` owns the real DVFS policy; the vendor HAL
(`android.hardware.thermal@2.0-impl.so`) is the component the Android framework
communicates with. The HAL derives the thermal *status* that the framework sees
from a compiled-in per-`TemperatureType` threshold table. Those thresholds can be
inspected and re-patched:

```sh
# Decode the table (CPU/GPU/NPU/BATTERY/SKIN/POWER_AMPLIFIER):
mtk-thermal-re hal-info android.hardware.thermal@2.0-impl.so

# Produce a hotter build: CPU/GPU/NPU severity onset +10 °C.
mtk-thermal-re hal-patch impl.so impl.sysretq0.so --profile sysretq0-hot
```

The patcher is guarded: it accepts only the reference build-id and size unless
`--force` is given, rejects non-monotonic or `NaN` thresholds, and refuses to make
a shared `.rodata` word hold two different values. The reference profile changes
only **3 bytes**. It affects the framework-visible status only; kernel and
`thermal_core` protection is untouched, and `SKIN` is governed by `thermal_core`'s
`[thermalhal-threshold]`. See **[docs/hal.md](docs/hal.md)** for the table layout,
the safety envelope and apply/rollback steps.

## Installation

Requires Python 3.9 or later. No runtime dependencies.

```sh
git clone <this repo> mtk-thermal-re
cd mtk-thermal-re
python -m pip install .
# or run straight from a checkout:
PYTHONPATH=src python -m mtk_thermal_re --help
```

## Quickstart

```sh
# Report the on-disk encoding of a policy.
mtk-thermal-re detect /vendor/etc/thermal/thermal.conf
# -> /vendor/etc/thermal/thermal.conf: v10

# Decode it to plaintext.
mtk-thermal-re decrypt /vendor/etc/thermal/thermal.conf thermal.plain.conf

# Pretty-print the decoded policy, annotated.
mtk-thermal-re show thermal.plain.conf -v

# Read and modify a single key, preserving the on-disk encoding.
mtk-thermal-re get thermal.plain.conf mtk-skin-control target_tpcb
mtk-thermal-re set /vendor/etc/thermal/thermal.conf mtk-skin-control target_tpcb 53000
```

Applying a tuned policy on-device (root shell):

```sh
# The loader treats a file whose first line is exactly "[policy_type]" as
# plaintext, so no re-encoding is required for an overlay.
cp thermal.plain.conf /data/vendor/thermal/my_tune.conf
thermal_intf apply my_tune.conf        # see docs/tuning-guide.md
```

## Python API

```python
from mtk_thermal_re import codec, Policy

raw = open("/vendor/etc/thermal/thermal.conf", "rb").read()
plaintext, variant = codec.decode_auto(raw)      # variant == Variant.V10
doc = Policy.parse(plaintext)
print(doc.get("mtk-skin-control", "target_tpcb"))  # "46000"
doc.set("mtk-skin-control", "target_tpcb", "53000")
reencoded = codec.encrypt(doc.dumps().encode(), variant)
```

## How tuning works (summary)

1. The loader (`exe_change_policy`, `0x8940`) looks for the policy in
   `/data/vendor/thermal/<name>` first, then `/vendor/etc/thermal/<name>`.
2. It reads the first line to determine the encoding. If that line is literally
   `[policy_type]`, the file is used as plaintext; otherwise it is decoded with
   `tp_decrypt_v1` (`0x103fc`).
3. A policy selected with `permanent= Yes` is written to
   `/data/vendor/thermal/.permanent_tp` and re-applied at boot.
4. On a running device, `thermal_intf <cmd> <args...>` sends a text command to
   `/dev/socket/thermal_socket`; `apply <file>` switches the active policy.

See **[docs/tuning-guide.md](docs/tuning-guide.md)** for procedures and
**[docs/obfuscation.md](docs/obfuscation.md)** for the transform.

## Repository layout

```
src/mtk_thermal_re/     the package (codec, policy parser, HAL tooling, CLI, registry)
tests/                  stdlib unittest suite and fixtures
docs/                   documentation and methodology
data/policies/          decoded (plaintext) copies of the shipped policies
data/samples/           the original obfuscated policies (test/sample inputs)
examples/               ready-to-use tuned policies and obfuscated forms
reverse/                reverse-engineering evidence: symbol tables, decompiled C, harnesses
```

## Documentation

| document | contents |
|----------|----------|
| [docs/index.md](docs/index.md) | overview and reading order |
| [docs/architecture.md](docs/architecture.md) | daemon, HAL service and socket plumbing |
| [docs/obfuscation.md](docs/obfuscation.md) | `tp_decrypt_v1` and its inverse |
| [docs/config-format.md](docs/config-format.md) | sections, keys and their semantics |
| [docs/tuning-guide.md](docs/tuning-guide.md) | how to change thermal behaviour safely |
| [docs/hal.md](docs/hal.md) | the thermal HAL threshold table and how to patch it |
| [docs/reverse-engineering.md](docs/reverse-engineering.md) | methodology and evidence trail |

## Scope and ethics

This project is intended for interoperability, research and device ownership: it
documents and re-tunes the thermal policy format of hardware you own. It ships no
vendor binaries and no encryption keys (the transform uses no key; it is a public
bijection). The decompilation under `reverse/decompiled/` is provided as evidence
for the analysis. Tune only devices you are authorised to modify; raising thermal
limits can damage hardware.

## License

Licensed under the **GNU General Public License, version 3 or later**
(`GPL-3.0-or-later`). See [`LICENSE`](LICENSE).

```
mtk-thermal-re - reverse-engineering and tuning toolkit for MediaTek thermal_core
Copyright (C) 2026 The mtk-thermal-re Authors

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.
```

The Corresponding Source for this work is this repository. Modified versions must
retain the same license and make their source available. See [`NOTICE`](NOTICE)
for the status of third-party and vendor material.
