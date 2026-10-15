<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# mtk-thermal-re documentation

This directory documents the MediaTek `thermal_core` thermal subsystem and how to
inspect and tune it with this toolkit.

## Reading order

1. **[architecture.md](architecture.md)** — what the pieces are and how they talk.
2. **[obfuscation.md](obfuscation.md)** — the `tp_decrypt_v1` transform and its inverse.
3. **[config-format.md](config-format.md)** — the policy file grammar, lookup order
   and the meaning of every section/key.
4. **[tuning-guide.md](tuning-guide.md)** — practical recipes for changing thermal behaviour.
5. **[reverse-engineering.md](reverse-engineering.md)** — methodology, evidence and unknowns.

## TL;DR

* Shipped `*.conf` policies are obfuscated with a **position-dependent bijection**
  (not encryption); `thermal_core` reverses it at load time via `tp_decrypt_v1`.
* A policy whose **first line is exactly `[policy_type]`** is treated as **plaintext**.
* User policies in `/data/vendor/thermal/` override `/vendor/etc/thermal/`.
* `thermal_intf apply <file>` hot-swaps the active policy over
  `/dev/socket/thermal_socket`.
* Use the bundled CLI to decode, edit and re-encode policies:

  ```sh
  mtk-thermal-re show /vendor/etc/thermal/thermal.conf -v
  mtk-thermal-re set /vendor/etc/thermal/thermal.conf mtk-skin-control target_tpcb 53000
  ```

## Provenance

All technical statements here were derived from the three ELF binaries collected in
the parent workspace (`thermal_core`, `thermal_intf`,
`android.hardware.thermal@2.0-service.mtk`) using their embedded `.gnu_debugdata`
symbol tables and Ghidra decompilation. Function addresses are virtual addresses in
the stripped binaries. The evidence is preserved under `reverse/`.
