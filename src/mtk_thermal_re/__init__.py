# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""mtk-thermal-re: reverse-engineering and tuning toolkit for MediaTek
``thermal_core`` thermal policies.

Public API::

    from mtk_thermal_re import codec, policy, Variant

    plaintext, variant = codec.decode_auto(open("thermal.conf", "rb").read())
    doc = policy.Policy.parse(plaintext)
"""

from __future__ import annotations

from . import codec, known, policy
from .__about__ import __license__, __summary__, __title__, __version__
from .codec import Variant
from .policy import Policy, Section

__all__ = [
    "__title__",
    "__version__",
    "__summary__",
    "__license__",
    "codec",
    "policy",
    "known",
    "Variant",
    "Policy",
    "Section",
]
