# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.  See the LICENSE file for the full text.

"""Position-dependent substitution codec used by MediaTek ``thermal_core`` policy files.

The shipped ``*.conf`` files are *not* encrypted with a key.  ``thermal_core``
applies a reversible, position-dependent substitution at load time via
``tp_decrypt_v1`` (``thermal_core`` @ ``0x103fc``).

For every byte ``c`` at zero-based column ``i`` (the column counter is reset at
each newline)::

    if 0x20 <= c <= 0x7a:
        out = ((c - (i % step) + 0x3b) mod 91) + 0x20
    else:
        out = c

``step`` is 10 for the shipped files (``Variant.V10``); the loader also contains
an alternative path using step 5 (``Variant.V5``).  Bytes outside ``0x20..0x7a``
(newline, carriage return, other control bytes) are copied verbatim.

The transform is a bijection on ``0x20..0x7a``, so :func:`encrypt` is the exact
inverse of :func:`decrypt`.
"""

from __future__ import annotations

from enum import IntEnum

__all__ = [
    "Variant",
    "DecodeError",
    "decrypt",
    "encrypt",
    "detect",
    "LO",
    "HI",
    "MOD",
]

LO = 0x20
HI = 0x7A
MOD = 91  # 0x5B
SHIFT = 0x3B

#: First line of every well-formed policy file.  The loader reads it to decide
#: whether/how to de-obfuscate the remainder of the file.
FIRST_LINE = b"[policy_type]"


class Variant(IntEnum):
    """Decode variant of a policy file."""

    PLAINTEXT = 0
    """First line is literally ``[policy_type]``; the body is not transformed."""

    V10 = 10
    """Body columns use ``i % 10`` (the shipped files)."""

    V5 = 5
    """Body columns use ``i % 5`` (alternate loader path)."""


class DecodeError(ValueError):
    """Raised when a policy file has no recognisable ``[policy_type]`` header."""


def _decrypt_byte(c: int, i: int, step: int) -> int:
    if LO <= c <= HI:
        return (((c - (i % step) + SHIFT) % MOD) + LO) & 0xFF
    return c


def _encrypt_byte(p: int, i: int, step: int) -> int:
    if not (LO <= p <= HI):
        return p
    for c in range(LO, HI + 1):
        if _decrypt_byte(c, i, step) == p:
            return c
    raise DecodeError("no preimage for byte %#x at column %d" % (p, i))


def _map(data: bytes, step: int, byte_fn) -> bytes:
    out = bytearray(data)
    pos = 0
    for line in data.split(b"\n"):
        for i, c in enumerate(line):
            out[pos + i] = byte_fn(c, i, step)
        pos += len(line) + 1
    return bytes(out)


def decrypt(data: bytes, variant: Variant = Variant.V10) -> bytes:
    """Return the plaintext of ``data`` for ``variant``.

    ``Variant.PLAINTEXT`` returns ``data`` unchanged.
    """
    if variant == Variant.PLAINTEXT:
        return bytes(data)
    step = int(variant)
    return _map(bytes(data), step, _decrypt_byte)


def encrypt(data: bytes, variant: Variant = Variant.V10) -> bytes:
    """Return the obfuscated form of plaintext ``data``."""
    if variant == Variant.PLAINTEXT:
        return bytes(data)
    step = int(variant)
    return _map(bytes(data), step, _encrypt_byte)


def _first_line(data: bytes) -> bytes:
    return data.split(b"\n", 1)[0].rstrip(b" \t\r")


def detect(data: bytes) -> Variant | None:
    """Detect the variant of ``data``.

    Returns :data:`Variant.PLAINTEXT` for a plaintext file, the transform variant
    for an obfuscated one, or ``None`` when no variant produces the expected
    ``[policy_type]`` header.
    """
    first = _first_line(data)
    if first == FIRST_LINE:
        return Variant.PLAINTEXT
    for variant in (Variant.V10, Variant.V5):
        if _map(first, int(variant), _decrypt_byte).rstrip() == FIRST_LINE:
            return variant
    return None


def decode_auto(data: bytes) -> tuple[bytes, Variant]:
    """Detect and decrypt in one step.

    :returns: ``(plaintext, variant)``.
    :raises DecodeError: if the header is not recognisable.
    """
    variant = detect(data)
    if variant is None:
        raise DecodeError("not a thermal policy: first line does not resolve to %r" % (FIRST_LINE,))
    return decrypt(data, variant), variant
