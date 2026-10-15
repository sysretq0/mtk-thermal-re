<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# The policy obfuscation (`tp_decrypt_v1`)

The shipped `.conf` files are **not** encrypted with a key: there is no secret.
They are transformed with a reversible, **position-dependent substitution**.
`thermal_core` decodes them in memory at load time via `tp_decrypt_v1`
(`0x103fc`), called from `exe_change_policy` (`0x8940`).

## The transform

For every byte `c` of a file at zero-based column `i` — where the column counter is
**reset at each newline**:

```
if 0x20 <= c <= 0x7a:                      # printable ' ' .. 'z'
    out = ((c - (i % step) + 0x3b) mod 91) + 0x20
else:
    out = c                                # '\n', '\r' and control bytes unchanged
```

`step` is **10** for the shipped files (`Variant.V10`). `thermal_core` also contains
an alternative path using **5** (`Variant.V5`), selected by a second
`[policy_type]` header pattern.

The map is a bijection on `0x20..0x7a` (91 values → 91 values), so the inverse is:

```
c = (((p - 0x20) + (i % step) - 0x3b) mod 91) + 0x20
```

## Worked example

```
[qqomh$f!'pf_   ->   [policy_type]
```

Column by column (step 10):

| i | cipher | `(c - i%10 + 0x3b) mod 91 + 0x20` | plain |
|---|--------|-----------------------------------|-------|
| 0 | `[` | `(91 - 0 + 59) % 91 + 32 = 91` | `[` |
| 1 | `q` | `(113 - 1 + 59) % 91 + 32 = 112` | `p` |
| 2 | `q` | `(113 - 2 + 59) % 91 + 32 = 111` | `o` |
| … | | | |

giving `[policy_type]`.

## Encoding modes recognised by the loader

`exe_change_policy` reads the **first line** (trailing whitespace stripped) and
records a decode mode:

| first line | mode | body handling |
|---|---|---|
| literally `[policy_type]` | 0 | **plaintext — no transform** |
| decodes to `[policy_type]` with `i % 10` | 1 | decrypt every line with step 10 |
| decodes to `[policy_type]` with `i % 5` | 2 | decrypt every line with step 5 |

Mode is logged as `encrypted_policy <n>` (logcat tag `thermal_core`).

## Consequence for tuning

Because mode 0 is plaintext, **you can author a policy as ordinary text as long as
its first line is `[policy_type]`**. Re-run `mtk-thermal-re encrypt` only if you need
to overwrite the obfuscated vendor file byte-for-byte in place.

## Tool

```sh
mtk-thermal-re detect  file.conf
mtk-thermal-re decrypt file.conf out.conf
mtk-thermal-re encrypt out.conf file.conf --variant v10
```

Library:

```python
from mtk_thermal_re import codec, Variant
plain, variant = codec.decode_auto(open("thermal.conf", "rb").read())
encoded = codec.encrypt(plain, variant)
```
