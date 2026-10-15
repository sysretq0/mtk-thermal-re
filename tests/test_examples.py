# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Integrity and safety-envelope tests for the shipped example profiles.

These lock the contract of the ``sysretq0`` HOT profile: it must be hotter than
stock, yet never exceed the vendor's own hottest shipped policy, and it must
leave every hard safety rail (junction clamp, HAL shutdown, charge-current
limits, backlight limits, HW protection) untouched.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from mtk_thermal_re import codec
from mtk_thermal_re.codec import Variant
from mtk_thermal_re.policy import Policy

ROOT = Path(__file__).resolve().parent.parent
EXAMPLES = ROOT / "examples"
POLICIES = ROOT / "data" / "policies"
STOCK = POLICIES / "thermal.conf"


class ExampleIntegrityTests(unittest.TestCase):
    def test_every_conf_has_matching_enc_twin(self):
        for conf in sorted(EXAMPLES.glob("*.conf")):
            with self.subTest(conf=conf.name):
                enc = conf.with_suffix(conf.suffix + ".enc")
                self.assertTrue(enc.exists(), "%s has no .enc twin" % conf.name)
                plain, variant = codec.decode_auto(enc.read_bytes())
                self.assertEqual(variant, Variant.V10)
                self.assertEqual(plain, conf.read_bytes())

    def test_vendor_dropin_matches_hot_profile(self):
        vendor = EXAMPLES / "vendor" / "thermal.conf"
        self.assertTrue(vendor.exists())
        self.assertEqual(vendor.name, "thermal.conf")  # must be droppable as-is
        plain, variant = codec.decode_auto(vendor.read_bytes())
        self.assertEqual(variant, Variant.V10)
        self.assertEqual(plain, (EXAMPLES / "sysretq0_hot.conf").read_bytes())

    def test_all_example_policies_parse(self):
        files = sorted(EXAMPLES.rglob("*.conf"))
        self.assertIn(EXAMPLES / "vendor" / "thermal.conf", files)
        for f in files:
            with self.subTest(file=str(f.relative_to(ROOT))):
                plain, _ = codec.decode_auto(f.read_bytes())
                doc = Policy.parse(plain)
                self.assertIn("policy_type", doc.sections())


class Sysretq0HotEnvelopeTests(unittest.TestCase):
    """The HOT profile is hotter than stock but inside the vendor's limit."""

    @classmethod
    def setUpClass(cls):
        cls.stock = Policy.parse(STOCK.read_text())
        cls.hot = Policy.parse((EXAMPLES / "sysretq0_hot.conf").read_text())

    @staticmethod
    def _skin(doc):
        return doc.require_section("mtk-skin-control")

    @staticmethod
    def _hal(doc):
        return doc.require_section("thermalhal-threshold")

    def test_targets_are_meaningfully_hotter(self):
        s, h = self._skin(self.stock), self._skin(self.hot)
        for key in ("target_tpcb", "trip_tpcb", "min_target_tj"):
            with self.subTest(key=key):
                self.assertGreaterEqual(
                    h.get_int(key) - s.get_int(key), 5000, "%s must rise by >= 5.0 C" % key
                )

    def test_junction_clamp_unchanged(self):
        self.assertEqual(self._skin(self.hot).get_int("max_target_tj"), 85000)
        self.assertEqual(
            self._skin(self.hot).get_int("max_target_tj"),
            self._skin(self.stock).get_int("max_target_tj"),
        )

    def test_hard_shutdown_unchanged(self):
        self.assertEqual(self._hal(self.hot).get_ints("threshold")[-1], 80000)
        self.assertEqual(
            self._hal(self.hot).get_ints("threshold")[-1],
            self._hal(self.stock).get_ints("threshold")[-1],
        )

    def test_battery_and_display_rails_unchanged(self):
        self.assertEqual(
            self.hot.require_section("charger-cooler").get_ints("current"),
            self.stock.require_section("charger-cooler").get_ints("current"),
        )
        self.assertEqual(
            self.hot.require_section("backlight-cooler").get_ints("reduce-brightness"),
            self.stock.require_section("backlight-cooler").get_ints("reduce-brightness"),
        )

    def test_hw_protection_not_disabled(self):
        sec = self.hot.section("LTF-disable-throttling")
        if sec is not None:
            self.assertNotEqual(sec.get("HW_protection"), "disabled")

    def test_never_exceeds_vendor_hot_ceiling(self):
        # The vendor's own hottest shipped policies define the safe ceiling.
        for name in ("thermal_policy_08.conf", "thermal_mtbf.conf"):
            ref = Policy.parse((POLICIES / name).read_text())
            rs, rh = self._skin(ref), self._skin(self.hot)
            for key in ("target_tpcb", "trip_tpcb", "min_target_tj"):
                with self.subTest(ref=name, key=key):
                    self.assertLessEqual(rh.get_int(key), rs.get_int(key))
            with self.subTest(ref=name, key="hal_severe"):
                self.assertLessEqual(
                    self._hal(self.hot).get_ints("threshold")[0],
                    self._hal(ref).get_ints("threshold")[0],
                )


if __name__ == "__main__":
    unittest.main()
