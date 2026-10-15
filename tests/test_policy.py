# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Tests for the policy parser/editor."""

from __future__ import annotations

import unittest
from pathlib import Path

from mtk_thermal_re.policy import Policy, parse_list

DATA = Path(__file__).parent / "data"

SAMPLE = """\
[policy_type]
# a comment
permanent= Yes

[mtk-skin-control]
sensor= ap_ntc
max_target_tj= 85000
threshold= [43000, 46000, 49000]
"""


class ParseListTests(unittest.TestCase):
    def test_bracket_list(self):
        self.assertEqual(parse_list("[1, 2, 3]"), ["1", "2", "3"])

    def test_strips_comment(self):
        self.assertEqual(parse_list("[1, 2, 3] # note"), ["1", "2", "3"])

    def test_empty(self):
        self.assertEqual(parse_list("[]"), [])


class PolicyTests(unittest.TestCase):
    def setUp(self):
        self.doc = Policy.parse(SAMPLE)

    def test_sections(self):
        self.assertEqual(self.doc.sections(), ["policy_type", "mtk-skin-control"])

    def test_get(self):
        self.assertEqual(self.doc.get("mtk-skin-control", "sensor"), "ap_ntc")
        self.assertIsNone(self.doc.get("mtk-skin-control", "missing"))

    def test_get_list_and_ints(self):
        sec = self.doc.require_section("mtk-skin-control")
        self.assertEqual(sec.get_list("threshold"), ["43000", "46000", "49000"])
        self.assertEqual(sec.get_ints("threshold"), [43000, 46000, 49000])

    def test_get_int(self):
        sec = self.doc.require_section("mtk-skin-control")
        self.assertEqual(sec.get_int("max_target_tj"), 85000)

    def test_no_edit_roundtrip(self):
        self.assertEqual(self.doc.dumps(), SAMPLE)

    def test_set_replaces_in_place(self):
        self.doc.set("mtk-skin-control", "sensor", "batt_ntc")
        self.assertEqual(self.doc.get("mtk-skin-control", "sensor"), "batt_ntc")
        # rest of the file is preserved
        self.assertIn("# a comment", self.doc.dumps())
        self.assertEqual(self.doc.dumps().count("sensor= batt_ntc"), 1)

    def test_set_adds_key(self):
        self.doc.set("mtk-skin-control", "trip_tpcb", "50000")
        sec = self.doc.require_section("mtk-skin-control")
        self.assertEqual(sec.get("trip_tpcb"), "50000")
        # key placed before the section's trailing boundary
        self.assertTrue(self.doc.dumps().rstrip().endswith("trip_tpcb= 50000"))

    def test_set_adds_section(self):
        self.doc.set("charger-cooler", "mode", "enabled")
        self.assertIn("charger-cooler", self.doc.sections())
        self.assertEqual(self.doc.get("charger-cooler", "mode"), "enabled")


class FixtureTests(unittest.TestCase):
    def test_parse_real_plaintext_policy(self):
        text = (DATA / "sample_plaintext.conf").read_text()
        doc = Policy.parse(text)
        self.assertEqual(doc.get("policy_type", "permanent"), "Yes")
        self.assertEqual(doc.get("mtk-skin-control", "target_tpcb"), "46000")
        self.assertEqual(
            doc.require_section("charger-cooler").get_ints("current"),
            [3000, 3000, 3000, 3000, 1000],
        )

    def test_as_dict(self):
        doc = Policy.parse((DATA / "sample_plaintext.conf").read_text())
        d = doc.as_dict()
        self.assertIn("thermalhal-threshold", d)
        self.assertEqual(d["thermalhal-threshold"]["type"], "SKIN")


if __name__ == "__main__":
    unittest.main()
