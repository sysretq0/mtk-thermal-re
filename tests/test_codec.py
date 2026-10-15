# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Tests for the codec (tp_decrypt_v1 / inverse)."""

from __future__ import annotations

import unittest
from pathlib import Path

from mtk_thermal_re import codec
from mtk_thermal_re.codec import DecodeError, Variant

DATA = Path(__file__).parent / "data"


class DetectTests(unittest.TestCase):
    def test_detects_v10(self):
        raw = (DATA / "sample_obfuscated.conf").read_bytes()
        self.assertEqual(codec.detect(raw), Variant.V10)

    def test_detects_plaintext(self):
        raw = (DATA / "sample_plaintext.conf").read_bytes()
        self.assertEqual(codec.detect(raw), Variant.PLAINTEXT)

    def test_garbage_is_unknown(self):
        self.assertIsNone(codec.detect(b"hello world\nnot a policy\n"))
        self.assertIsNone(codec.detect(b""))


class DecodeTests(unittest.TestCase):
    def test_known_header(self):
        # The obfuscated header of every shipped file.
        self.assertEqual(codec.decrypt(b"[qqomh$f!'pf_", Variant.V10), b"[policy_type]")

    def test_shipped_file_matches_plaintext(self):
        raw = (DATA / "sample_obfuscated.conf").read_bytes()
        plain = (DATA / "sample_plaintext.conf").read_bytes()
        self.assertEqual(codec.decrypt(raw, Variant.V10), plain)

    def test_decode_auto(self):
        raw = (DATA / "sample_obfuscated.conf").read_bytes()
        plain, variant = codec.decode_auto(raw)
        self.assertEqual(variant, Variant.V10)
        self.assertTrue(plain.startswith(b"[policy_type]"))

    def test_control_bytes_untouched(self):
        # newlines and other non-printable bytes must survive verbatim
        data = b"a\n\x00\x01\t b\n"
        out = codec.decrypt(data, Variant.V10)
        self.assertEqual(out[1], 0x0A)
        self.assertEqual(out[2:4], b"\x00\x01")
        self.assertEqual(out[4], 0x09)

    def test_decode_auto_raises(self):
        with self.assertRaises(DecodeError):
            codec.decode_auto(b"not a policy at all\n")


class RoundTripTests(unittest.TestCase):
    def test_encrypt_is_inverse_on_samples(self):
        for name in ("sample_obfuscated.conf", "sample_plaintext.conf"):
            raw = (DATA / name).read_bytes()
            for variant in (Variant.V10, Variant.V5):
                self.assertEqual(
                    codec.encrypt(codec.decrypt(raw, variant), variant), raw,
                    "%s / %s" % (name, variant),
                )

    def test_every_printable_byte_at_every_column(self):
        for variant in (Variant.V10, Variant.V5):
            for col in range(30):
                line = bytes(range(0x20, 0x7B))  # one line, columns 0..90
                enc = codec.encrypt(line, variant)
                self.assertEqual(codec.decrypt(enc, variant), line)

    def test_variant_shapes_differ(self):
        line = b"[policy_type]"
        self.assertNotEqual(codec.encrypt(line, Variant.V10),
                            codec.encrypt(line, Variant.V5))


if __name__ == "__main__":
    unittest.main()
