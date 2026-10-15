# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.  See the LICENSE file for the full text.

"""Parsing and editing of ``thermal_core`` policy files.

A policy is an INI-like text file::

    [policy_type]
    # comments start with '#'
    permanent= Yes

    [mtk-skin-control]
    sensor= ap_ntc
    max_target_tj= 85000
    threshold= [43000, 46000, 49000]

The :class:`Policy` class is line based: it keeps the original text (including
comments, blank lines and ordering) so that editing a single value does not
reformat the rest of the file.
"""

from __future__ import annotations

import re
from collections.abc import Iterator
from dataclasses import dataclass, field

__all__ = ["Policy", "Section", "ParseError"]

_SECTION_RE = re.compile(r"^\s*\[(?P<name>[^\]\r\n]+)\]\s*$")
_OPTION_RE = re.compile(r"^\s*(?P<key>[^=\s#][^=]*?)\s*=\s*(?P<value>.*?)\s*$")


class ParseError(ValueError):
    """Raised when a policy file cannot be parsed."""


def _strip_comment(value: str) -> str:
    """Remove an unquoted trailing ``#`` comment from a value."""
    return value.split("#", 1)[0].strip()


def parse_list(value: str) -> list[str]:
    """Parse ``[a, b, c]`` (also tolerates bare ``a b c``) into a list of tokens."""
    value = _strip_comment(value)
    if value.startswith("["):
        value = value[1:]
    if value.endswith("]"):
        value = value[:-1]
    value = value.strip()
    return [tok.strip() for tok in value.split(",") if tok.strip()]


@dataclass
class Section:
    """A view over one ``[name]`` block of a :class:`Policy`."""

    policy: Policy
    name: str
    start: int  # index of the '[' header line
    end: int  # index one past the last body line

    # -- lookups ---------------------------------------------------------
    def _iter_options(self) -> Iterator[tuple[int, str, str]]:
        for idx in range(self.start + 1, self.end):
            raw = self.policy.lines[idx]
            stripped = raw.strip()
            if not stripped or stripped.startswith("#"):
                continue
            m = _OPTION_RE.match(raw)
            if m:
                yield idx, m.group("key").strip(), _strip_comment(m.group("value"))

    def items(self) -> list[tuple[str, str]]:
        """Return ``[(key, value), ...]`` for this section, in file order."""
        return [(k, v) for _, k, v in self._iter_options()]

    def has(self, key: str) -> bool:
        return any(k == key for _, k, _ in self._iter_options())

    def get(self, key: str, default: str | None = None) -> str | None:
        for _, k, v in self._iter_options():
            if k == key:
                return v
        return default

    def get_list(self, key: str, default: list[str] | None = None) -> list[str] | None:
        raw = self.get(key)
        if raw is None:
            return default
        return parse_list(raw)

    def get_int(self, key: str, default: int | None = None) -> int | None:
        raw = self.get(key)
        if raw is None:
            return default
        try:
            return int(raw, 0)
        except ValueError as exc:
            raise ParseError("section [%s]: %r is not an integer" % (self.name, raw)) from exc

    def get_ints(self, key: str) -> list[int]:
        return [int(tok, 0) for tok in (self.get_list(key) or [])]

    def as_dict(self) -> dict[str, str]:
        return dict(self.items())


@dataclass
class Policy:
    """A parsed thermal policy."""

    lines: list[str] = field(default_factory=list)
    trailing_newline: bool = True

    # -- construction ----------------------------------------------------
    @classmethod
    def parse(cls, text: str | bytes) -> Policy:
        if isinstance(text, bytes):
            text = text.decode("utf-8", "surrogateescape")
        trailing = text.endswith("\n")
        return cls(
            lines=text.split("\n")[:-1] if trailing else text.split("\n"), trailing_newline=trailing
        )

    def dumps(self) -> str:
        text = "\n".join(self.lines)
        return text + "\n" if self.trailing_newline else text

    # -- section access --------------------------------------------------
    def _bounds(self) -> list[tuple[str, int, int]]:
        headers = []
        for idx, raw in enumerate(self.lines):
            m = _SECTION_RE.match(raw)
            if m:
                headers.append((m.group("name"), idx))
        out = []
        for i, (name, idx) in enumerate(headers):
            end = headers[i + 1][1] if i + 1 < len(headers) else len(self.lines)
            out.append((name, idx, end))
        return out

    def sections(self) -> list[str]:
        return [name for name, _, _ in self._bounds()]

    def section(self, name: str) -> Section | None:
        for sec_name, start, end in self._bounds():
            if sec_name == name:
                return Section(self, sec_name, start, end)
        return None

    def require_section(self, name: str) -> Section:
        sec = self.section(name)
        if sec is None:
            raise KeyError("section [%s] not found" % name)
        return sec

    def get(self, section: str, key: str, default: str | None = None) -> str | None:
        sec = self.section(section)
        return sec.get(key, default) if sec else default

    def get_list(self, section: str, key: str) -> list[str] | None:
        sec = self.section(section)
        return sec.get_list(key) if sec else None

    # -- editing ---------------------------------------------------------
    def set(self, section: str, key: str, value: str) -> None:
        """Set ``key`` inside ``section``.

        Replaces the existing ``key=`` line (preserving its indentation style is
        not attempted) or appends a new line at the end of the section.  A new
        ``[section]`` block is appended if it does not exist.
        """
        sec = self.section(section)
        if sec is None:
            if self.lines and self.lines[-1].strip():
                self.lines.append("")
            self.lines.append("[%s]" % section)
            self.lines.append("%s= %s" % (key, value))
            self.trailing_newline = True
            return
        for idx, k, _ in sec._iter_options():
            if k == key:
                self.lines[idx] = "%s= %s" % (key, value)
                return
        # insert before the trailing blank lines/comments of the section
        insert_at = sec.end
        while insert_at - 1 > sec.start and (
            not self.lines[insert_at - 1].strip()
            or self.lines[insert_at - 1].strip().startswith("#")
        ):
            insert_at -= 1
        self.lines.insert(insert_at, "%s= %s" % (key, value))

    def as_dict(self) -> dict[str, dict[str, str]]:
        return {name: self.require_section(name).as_dict() for name, _, _ in self._bounds()}
