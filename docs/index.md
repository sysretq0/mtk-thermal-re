<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# mtk-thermal-re documentation

This directory documents MediaTek's `thermal_core` thermal subsystem, the vendor
thermal HAL, and how to inspect and tune both with this toolkit.

## Reading order

1. **[architecture.md](architecture.md)** — the components and how they communicate.
2. **[obfuscation.md](obfuscation.md)** — the `tp_decrypt_v1` transform and its inverse.
3. **[config-format.md](config-format.md)** — the policy file grammar, lookup order
   and the semantics of each section and key.
4. **[tuning-guide.md](tuning-guide.md)** — procedures for changing thermal behaviour.
5. **[hal.md](hal.md)** — the vendor thermal HAL: its compiled-in thresholds and how
   to re-patch them.
6. **[reverse-engineering.md](reverse-engineering.md)** — methodology, evidence and
   open questions.

## Summary

* The shipped `*.conf` policies are obfuscated with a position-dependent bijection
  (not encryption). `thermal_core` reverses it at load time via `tp_decrypt_v1`.
* A policy whose first line is exactly `[policy_type]` is treated as plaintext.
* Policies in `/data/vendor/thermal/` take precedence over `/vendor/etc/thermal/`.
* `thermal_intf apply <file>` hot-swaps the active policy over
  `/dev/socket/thermal_socket`.
* The bundled CLI decodes, edits and re-encodes policies:

  ```sh
  mtk-thermal-re show /vendor/etc/thermal/thermal.conf -v
  mtk-thermal-re set  /vendor/etc/thermal/thermal.conf mtk-skin-control target_tpcb 53000
  ```

## Provenance

Every technical statement in this documentation was derived from the ELF binaries
collected in the parent workspace (`thermal_core`, `thermal_intf`,
`android.hardware.thermal@2.0-service.mtk`, `android.hardware.thermal@2.0-impl.so`)
by recovering their embedded `.gnu_debugdata` symbol tables and decompiling the
relevant functions with Ghidra. Function addresses are virtual addresses in the
stripped binaries. The supporting evidence is preserved under `reverse/`.
