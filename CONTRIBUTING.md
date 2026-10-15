<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Contributing to mtk-thermal-re

This project documents MediaTek's thermal stack and provides tooling to inspect
and tune it. Contributions that add evidence, correct inaccuracies, or improve the
tooling are welcome.

## Ground rules

* Be respectful and constructive; the project follows the spirit of the
  [Contributor Covenant](https://www.contributor-covenant.org/).
* Do not submit vendor binaries, firmware blobs, or anything you are not permitted
  to redistribute. [`NOTICE`](NOTICE) states what is and is not covered.
* Keep the package dependency-free. The installable code under
  `src/mtk_thermal_re/` must run on the standard library alone.
* By contributing, you agree that your work is licensed under
  `GPL-3.0-or-later`.

## Development setup

Python 3.9 or later. No runtime dependencies.

```sh
git clone <this repo> mtk-thermal-re
cd mtk-thermal-re

# Run the tests with the standard library only:
make test          # = PYTHONPATH=src python3 -m unittest discover -s tests -v

# Optional: lint and format with ruff:
python -m pip install -e '.[dev]'
make lint
```

## Where to contribute

Suitable starting points:

* Resolve the open questions listed at the end of
  [`docs/reverse-engineering.md`](docs/reverse-engineering.md): the ATC control
  math (`calcu_ap_param`, `algorithm_thread`), the `[option_setting]`/`angle`
  device-type matching, and the modem/RF `limit-state[]` encodings.
* Add decodes for new device policies. Place the obfuscated file in
  `data/samples/`, its plaintext twin in `data/policies/`, and a round-trip test.
* Extend `src/mtk_thermal_re/known.py` with newly identified keys. Each entry must
  cite the parser symbol and VMA it came from.

## Guidelines

1. **Reproducibility.** Every new claim about behaviour must be traceable to a
   symbol, a decompiled function, or a test. Cite the VMA.
2. **Tests.** Code changes require tests under `tests/`. The suite must pass with
   `python -m unittest` and no extra packages.
3. **Style.** Match the surrounding code: 4-space indentation,
   `from __future__ import annotations`, and an SPDX header on new files:
   `# SPDX-License-Identifier: GPL-3.0-or-later`.
4. **State uncertainty explicitly.** Mark inferred or speculative findings as such
   in the relevant docstring, comment or document.
5. **Addresses** are file VMAs in the stripped binary (`.text` starts at `0x8000`).

## Commits and pull requests

* Use clear, imperative commit subjects, for example
  `known: add wifi_cooler keys`.
* Reference the issue being addressed.
* Ensure `make test` and `make lint` pass; CI runs both.
* Describe the evidence in the pull request: which binary, which symbol, and how
  the result was verified.

## Reporting bugs and asking questions

Open an issue with the device model, the Android/MTK generation if known, the
exact command run, and the observed versus expected output. A decoded policy
(redacted if necessary) is usually helpful.
