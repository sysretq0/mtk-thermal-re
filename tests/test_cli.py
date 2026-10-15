# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""End-to-end tests for the CLI (run as a subprocess)."""

from __future__ import annotations

import os
import shutil
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src"
CLI = [sys.executable, "-m", "mtk_thermal_re"]
DATA = Path(__file__).parent / "data"

ENV = dict(os.environ, PYTHONPATH=str(SRC) + os.pathsep + os.environ.get("PYTHONPATH", ""))


def run(*args):
    return subprocess.run(CLI + list(args), cwd=REPO, env=ENV,
                          capture_output=True, text=True)


class CliTests(unittest.TestCase):
    def test_version(self):
        r = run("version")
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertIn("mtk-thermal-re", r.stdout)
        self.assertIn("GPL-3.0-or-later", r.stdout)

    def test_detect(self):
        r = run("detect", str(DATA / "sample_obfuscated.conf"),
                str(DATA / "sample_plaintext.conf"))
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertIn("sample_obfuscated.conf: v10", r.stdout)
        self.assertIn("sample_plaintext.conf: plaintext", r.stdout)

    def test_decrypt_outputs_plaintext(self):
        r = run("decrypt", str(DATA / "sample_obfuscated.conf"))
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertEqual(r.stdout,
                         (DATA / "sample_plaintext.conf").read_text())

    def test_encrypt_roundtrip(self):
        with tempfile.TemporaryDirectory() as tmp:
            enc = Path(tmp) / "enc.conf"
            dec = Path(tmp) / "dec.conf"
            r = run("encrypt", str(DATA / "sample_plaintext.conf"), str(enc))
            self.assertEqual(r.returncode, 0, r.stderr)
            r = run("decrypt", str(enc), str(dec))
            self.assertEqual(r.returncode, 0, r.stderr)
            self.assertEqual(dec.read_text(),
                             (DATA / "sample_plaintext.conf").read_text())

    def test_show(self):
        r = run("show", str(DATA / "sample_obfuscated.conf"))
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertIn("[mtk-skin-control]", r.stdout)
        self.assertIn("target_tpcb= 46000", r.stdout)

    def test_get(self):
        r = run("get", str(DATA / "sample_obfuscated.conf"),
                "mtk-skin-control", "sensor")
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertEqual(r.stdout.strip(), "ap_ntc")

    def test_get_missing_key(self):
        r = run("get", str(DATA / "sample_plaintext.conf"), "mtk-skin-control", "nope")
        self.assertEqual(r.returncode, 1)

    def test_set_in_place_preserves_encoding(self):
        with tempfile.TemporaryDirectory() as tmp:
            work = Path(tmp) / "thermal.conf"
            shutil.copy(DATA / "sample_obfuscated.conf", work)
            r = run("set", str(work), "mtk-skin-control", "target_tpcb", "53000")
            self.assertEqual(r.returncode, 0, r.stderr)
            # still obfuscated, and decodes with the new value
            r = run("get", str(work), "mtk-skin-control", "target_tpcb")
            self.assertEqual(r.stdout.strip(), "53000")
            r = run("detect", str(work))
            self.assertIn("v10", r.stdout)

    def test_validate(self):
        r = run("validate", str(DATA / "sample_obfuscated.conf"))
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertIn("OK", r.stdout)

    def test_validate_rejects_garbage(self):
        with tempfile.TemporaryDirectory() as tmp:
            bad = Path(tmp) / "bad.conf"
            bad.write_text("nothing to see here\n")
            r = run("validate", str(bad))
            self.assertEqual(r.returncode, 1)

    def test_schema(self):
        r = run("schema", "mtk-skin-control")
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertIn("target_tpcb", r.stdout)


if __name__ == "__main__":
    unittest.main()
