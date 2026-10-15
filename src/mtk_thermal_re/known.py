# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 The mtk-thermal-re Authors

"""Human-readable registry of policy sections and their knobs.

The information here was recovered from the ``thermal_core`` binary; see
``reverse/symbols.csv`` for the parser function addresses and
``docs/config-format.md`` for the narrative form.
"""

from __future__ import annotations

from dataclasses import dataclass, field

__all__ = ["SectionInfo", "SECTIONS", "section_info"]


@dataclass(frozen=True)
class SectionInfo:
    name: str
    parser: str
    vma: str
    summary: str
    keys: dict[str, str] = field(default_factory=dict)


SECTIONS: dict[str, SectionInfo] = {
    "policy_type": SectionInfo(
        name="policy_type",
        parser="(loader exe_change_policy)",
        vma="0x8940",
        summary="Policy metadata; also the marker the loader uses to detect the "
                "on-disk encoding.  MUST be the first section.",
        keys={
            "permanent": "Yes/No - persist this policy across reboot "
                         "(writes /data/vendor/thermal/.permanent_tp)",
        },
    ),
    "LTF": SectionInfo(
        name="LTF",
        parser="(loader exe_change_policy)",
        vma="0x8940",
        summary="Links a Linux thermal zone into the legacy thermal framework.",
        keys={
            "thermal_zone": "kernel thermal_zone name, e.g. soc_max",
            "mode": "enabled/disabled",
        },
    ),
    "LTF-disable-throttling": SectionInfo(
        name="LTF-disable-throttling",
        parser="disable_throttling_parser",
        vma="0x104cc",
        summary="Controls HW reboot protection / SW shutdown.  'disabled' calls "
                "set_hw_reboot(0).",
        keys={"HW_protection": "enabled/disabled"},
    ),
    "mtk-skin-control": SectionInfo(
        name="mtk-skin-control",
        parser="skin_control_parser",
        vma="0x153f0",
        summary="Adaptive Thermal Control (ATC) brain.  target_tpcb is written to "
                "/sys/kernel/thermal/target_tpcb; set_ttj() writes "
                "/sys/kernel/thermal/ttj.",
        keys={
            "sensor": "temperature sensor name, e.g. ap_ntc",
            "max_target_tj": "max junction target (millidegC)",
            "min_target_tj": "min junction target (millidegC)",
            "trip_tpcb": "PCB trip temperature",
            "target_tpcb": "PCB control target temperature",
            "atc_mode": "enable/disable",
            "atc_max_target_tj": "upper junction clamp",
            "cluster0_min_throttle_freq": "CPU cluster 0 frequency floor when cooling",
            "cluster1_min_throttle_freq": "CPU cluster 1 frequency floor when cooling",
            "cluster2_min_throttle_freq": "CPU cluster 2 frequency floor when cooling",
            "gpu_min_throttle_freq": "GPU frequency floor when cooling",
        },
    ),
    "charger-cooler": SectionInfo(
        name="charger-cooler",
        parser="charger_cooler_parser",
        vma="0x18454",
        summary="Charge-current limiting by temperature.  Writes "
                "/sys/kernel/charger_cooler/charger_table.",
        keys={
            "mode": "enabled/disabled",
            "sensor": "temperature sensor name",
            "threshold": "[temp, ...] ascending (millidegC)",
            "hysteresis": "[degC, ...] per band",
            "current": "[mA, ...] per band",
        },
    ),
    "backlight-cooler": SectionInfo(
        name="backlight-cooler",
        parser="backlight_cooler_parser",
        vma="0x19f34",
        summary="Display brightness reduction by temperature (cdev: lcd-backlight).",
        keys={
            "mode": "enabled/disabled",
            "sensor": "temperature sensor name",
            "threshold": "[temp, ...]",
            "hysteresis": "[degC, ...]",
            "reduce-brightness": "[percent, ...] per band",
        },
    ),
    "thermalhal-threshold": SectionInfo(
        name="thermalhal-threshold",
        parser="thermal_hal_threshold_parser",
        vma="0x1924c",
        summary="Temperatures reported to the Android thermal HAL.",
        keys={
            "type": "threshold class, e.g. SKIN",
            "sensor": "temperature sensor name",
            "level": "[severe, critical, emergency, shutdown]",
            "threshold": "[millidegC, ...] matching level[]",
        },
    ),
    "cpu_table_mapping": SectionInfo(
        name="cpu_table_mapping",
        parser="cpu_table_mapping_parser",
        vma="0x15a70",
        summary="Per-cluster CPU frequency throttling table.",
        keys={
            "mode": "enabled/disabled",
            "sensor": "temperature sensor name",
            "cluster": "CPU cluster id",
            "threshold": "[temp, ...]",
            "hysteresis": "[degC, ...]",
            "freq": "[kHz, ...] frequency cap per band",
        },
    ),
    "cpu_isolate": SectionInfo(
        name="cpu_isolate",
        parser="cpu_isolate_parser",
        vma="0x16910",
        summary="CPU hotplug/isolation cooling.",
    ),
    "gpu_table_mapping": SectionInfo(
        name="gpu_table_mapping",
        parser="gpu_table_mapping_parser",
        vma="0x17708",
        summary="GPU OPP/frequency throttling table.",
    ),
    "wifi_cooler": SectionInfo(
        name="wifi_cooler",
        parser="wifi_cooler_parser",
        vma="0x1ad74",
        summary="WiFi throughput/duty throttling.",
    ),
    "wifi_throttling": SectionInfo(
        name="wifi_throttling",
        parser="wifi_throttling_parser",
        vma="0x10b44",
        summary="WiFi throughput throttling thresholds.",
    ),
    "wifi_off": SectionInfo(
        name="wifi_off",
        parser="wifi_off_parser",
        vma="0x1134c",
        summary="WiFi radio-off thresholds.",
    ),
    "md_off": SectionInfo(
        name="md_off",
        parser="md_off_parser",
        vma="0x119d0",
        summary="Modem radio-off thresholds.",
    ),
    "md_notification": SectionInfo(
        name="md_notification",
        parser="md_notification_parser",
        vma="0x13cc0",
        summary="Modem overheat notification.",
    ),
    "mutt-pa1-cooler": SectionInfo(
        name="mutt-pa1-cooler",
        parser="mutt_pa1_cooler_parser",
        vma="0x1c8cc",
        summary="Modem PA1 power back-off.",
        keys={"threshold": "[temp, ...]", "hysteresis": "[degC, ...]",
              "limit-state": "[state, ...]"},
    ),
    "mutt-pa2-cooler": SectionInfo(
        name="mutt-pa2-cooler",
        parser="mutt_pa2_cooler_parser",
        vma="0x1d70c",
        summary="Modem PA2 power back-off.",
    ),
    "tx-pwr-pa1": SectionInfo(
        name="tx-pwr-pa1",
        parser="tx_pwr_pa1_cooler_parser",
        vma="0x1e54c",
        summary="RF TX power back-off (PA1).",
    ),
    "tx-pwr-pa2": SectionInfo(
        name="tx-pwr-pa2",
        parser="tx_pwr_pa2_cooler_parser",
        vma="0x1f38c",
        summary="RF TX power back-off (PA2).",
    ),
    "scg-off-pa2": SectionInfo(
        name="scg-off-pa2",
        parser="scg_off_pa2_cooler_parser",
        vma="0x201cc",
        summary="Secondary-cell PA2 shutdown.",
    ),
    "flashlight-cooler": SectionInfo(
        name="flashlight-cooler",
        parser="flashlight_cooler_parser",
        vma="0x1ba8c",
        summary="Flashlight current limiting.",
    ),
    "aee_dump": SectionInfo(
        name="aee_dump", parser="aee_dump_parser", vma="0x12540",
        summary="AEE crash-dump trigger.",
    ),
    "log_dump": SectionInfo(
        name="log_dump", parser="log_dump_parser", vma="0x13100",
        summary="Diagnostic log trigger.",
    ),
    "tz_polling": SectionInfo(
        name="tz_polling", parser="tz_polling_parser", vma="0x14830",
        summary="Extra thermal-zone polling.",
    ),
    "hinge_sensor": SectionInfo(
        name="hinge_sensor", parser="(main)", vma="0xd00c",
        summary="Hinge angle sensor configuration.",
    ),
    "option_setting": SectionInfo(
        name="option_setting", parser="(main)", vma="0xd00c",
        summary="Only in thermal_options.conf: chooses default policy and the "
                "enabled sub-policy set per device type.",
        keys={
            "default": "default policy filename",
            "policy": "[policy_filename, ...] enabled sub-policies",
            "angle": "[min, max, ...] device-type ranges per enabled policy",
        },
    ),
}


def section_info(name: str) -> SectionInfo | None:
    """Return :class:`SectionInfo` for ``name`` (exact match)."""
    return SECTIONS.get(name)
