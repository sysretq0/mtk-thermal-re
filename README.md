<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# mtk-thermal-re

> Reverse-engineering and tuning toolkit for MediaTek `thermal_core` thermal policies.

`thermal_core` is MediaTek's Android thermal daemon. It reads INI-like "policy"
files (`thermal.conf`, `thermal_policy_XX.conf`, `thermal_mtbf.conf`, …), but the
shipped files are stored with a small position-dependent obfuscation and the
binary is stripped. This project documents how it all works and gives you a tool
to **decode, inspect, edit and re-encode** those policies — plus the runtime
socket interface used to switch policies on a live device.

The reverse-engineering that backs this tool (function addresses, the
`tp_decrypt_v1` algorithm, the socket command set, the section/key map) is
recorded in `docs/` and `reverse/`.

## Features

- 🔓 Decode/encode the `tp_decrypt_v1` obfuscation (both `i % 10` and `i % 5` variants)
- 🧾 Structured policy parser that preserves comments and ordering
- ✏️ Edit a single key in place while keeping the file's original encoding
- 🧭 Registry of every known section and key, tied to the parser function that owns it
- 🔌 Documents the `/dev/socket/thermal_socket` command interface (`apply`, `mtbf_mode`, …)
- 📦 Plaintext policy overlay for `/data/vendor/thermal/` — no re-obfuscation required
- 🧪 Stdlib-only test suite (no third-party runtime dependencies)

## Installation

Requires Python ≥ 3.9. No runtime dependencies.

```sh
git clone <this repo> mtk-thermal-re
cd mtk-thermal-re
python -m pip install .
# or run straight from a checkout:
PYTHONPATH=src python -m mtk_thermal_re --help
```

## Quickstart

```sh
# What encoding is this policy using?
mtk-thermal-re detect /vendor/etc/thermal/thermal.conf
# → /vendor/etc/thermal/thermal.conf: v10

# Read it as plaintext.
mtk-thermal-re decrypt /vendor/etc/thermal/thermal.conf thermal.plain.conf

# Pretty-print the decoded policy (annotated).
mtk-thermal-re show thermal.plain.conf -v

# Read / change a single knob, preserving the on-disk encoding.
mtk-thermal-re get thermal.plain.conf mtk-skin-control target_tpcb
mtk-thermal-re set /vendor/etc/thermal/thermal.conf mtk-skin-control target_tpcb 53000
```

Applying a tuned policy on-device (root shell):

```sh
# Plaintext overlay — the loader treats a file whose first line is
# exactly "[policy_type]" as plaintext, so no re-encoding is needed.
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

## How tuning works (short version)

1. The loader (`exe_change_policy`, `0x8940`) looks for the policy in
   `/data/vendor/thermal/<name>` first, then `/vendor/etc/thermal/<name>`.
2. It reads the **first line** to decide the encoding. If that line is literally
   `[policy_type]`, the file is used as **plaintext** — otherwise it is decoded
   with `tp_decrypt_v1` (`0x103fc`).
3. A policy selected with `permanent= Yes` is written to
   `/data/vendor/thermal/.permanent_tp` and re-applied at boot.
4. On a running device, `thermal_intf <cmd> <args…>` sends a text command to
   `/dev/socket/thermal_socket`; `apply <file>` hot-swaps the active policy.

See **[docs/tuning-guide.md](docs/tuning-guide.md)** for recipes and
**[docs/obfuscation.md](docs/obfuscation.md)** for the algorithm.

## Repository layout

```
src/mtk_thermal_re/     the package (codec, policy parser, CLI, section registry)
tests/                  stdlib unittest suite + fixtures
docs/                   documentation and methodology
data/policies/          decoded (plaintext) copies of the shipped policies
data/samples/           the original obfuscated policies (test/sample inputs)
examples/               ready-to-use tuned policies (+ obfuscated forms)
reverse/                RE evidence: symbol table, decompiled C, harness script
```

## Documentation

| doc | contents |
|-----|----------|
| [docs/index.md](docs/index.md) | overview and reading order |
| [docs/architecture.md](docs/architecture.md) | daemon, HAL service and socket plumbing |
| [docs/obfuscation.md](docs/obfuscation.md) | `tp_decrypt_v1` and its inverse |
| [docs/config-format.md](docs/config-format.md) | sections, keys and their semantics |
| [docs/tuning-guide.md](docs/tuning-guide.md) | how to change thermal behaviour, safely |
| [docs/reverse-engineering.md](docs/reverse-engineering.md) | methodology and evidence trail |

## Scope and ethics

This project is for **interoperability, research and device ownership**: reading,
documenting and re-tuning the thermal policy format of hardware you own. It ships
**no vendor binaries and no encryption keys** (there is none — the transform is a
public bijection). Recovered decompilation under `reverse/decompiled/` is provided
as evidence for the analysis. Only tune devices you are authorised to modify;
raising thermal limits can damage hardware.

## License

Licensed under the **GNU General Public License, version 3 or later**
(`GPL-3.0-or-later`). See [`LICENSE`](LICENSE).

```
mtk-thermal-re — reverse-engineering and tuning toolkit for MediaTek thermal_core
Copyright (C) 2026 The mtk-thermal-re Authors

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.
```

Corresponding Source is this repository. If you distribute modified versions you
must keep the same license and make the source available. See
[`NOTICE`](NOTICE) for the status of third-party/vendor material.
