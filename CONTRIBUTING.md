<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Contributing to mtk-thermal-re

Thanks for your interest! This project is about *understanding* MediaTek's thermal
stack and making the knowledge reproducible. Contributions that add evidence,
fix inaccuracies, or improve the tooling are very welcome.

## Ground rules

* Be respectful and constructive (see the spirit of the
  [Contributor Covenant](https://www.contributor-covenant.org/)).
* **Do not** submit vendor binaries, firmware blobs, or anything you are not
  allowed to redistribute. See [`NOTICE`](NOTICE) for what is and isn't covered.
* Keep the package dependency-free. The installable code under
  `src/mtk_thermal_re/` must run on the standard library alone.
* By contributing you agree your work is licensed under `GPL-3.0-or-later`.

## Development setup

Python ≥ 3.9. No runtime dependencies.

```sh
git clone <this repo> mtk-thermal-re
cd mtk-thermal-re

# run the tests with nothing but the stdlib:
make test          # = PYTHONPATH=src python3 -m unittest discover -s tests -v

# optional: lint/format with ruff
python -m pip install -e '.[dev]'
make lint
```

## What to work on

Good first contributions:

* **Fill in the unknowns** listed at the end of
  [`docs/reverse-engineering.md`](docs/reverse-engineering.md) — the ATC control
  math (`calcu_ap_param`, `algorithm_thread`), the `[option_setting]`/`angle`
  device-type matching, and the modem/RF `limit-state[]` encodings.
* Add decodes for new device policies (put the obfuscated file in
  `data/samples/`, its plaintext twin in `data/policies/`, and a round-trip test).
* Extend `src/mtk_thermal_re/known.py` with newly identified keys — each entry
  must cite the parser symbol/VMA it came from.

## Guidelines

1. **Everything must be reproducible.** New claims about behaviour should be
   traceable to a symbol, a decompiled function, or a test. Cite the VMA.
2. **Tests are mandatory for code changes.** Add or update tests under `tests/`;
   the suite must stay green with `python -m unittest` and no extra packages.
3. **Style.** Match the surrounding code; 4-space indent; `from __future__ import
   annotations`; SPDX header at the top of new files:
   `# SPDX-License-Identifier: GPL-3.0-or-later`.
4. **Keep it honest.** If something is inferred rather than proven, say so in the
   docstring/comment. Mark speculative findings as such in the docs.
5. **Addresses** are file VMAs in the stripped binary (`.text` starts at `0x8000`).

## Commit & PR

* Use clear, imperative commit subjects (e.g. `known: add wifi_cooler keys`).
* Reference the issue you're fixing.
* Ensure `make test` and `make lint` pass; CI runs both.
* Describe *evidence* in the PR body: which binary, which symbol, how you
  verified it.

## Reporting bugs / asking questions

Open an issue with the device model, Android/MTK generation if known, the exact
command you ran, and the observed vs. expected output. Attaching a decoded
policy (redacted if necessary) helps a lot.
