// getSeverityFromThresholds @ 0x11970
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::getSeverityFromThresholds(float,
   android::hardware::thermal::V2_0::TemperatureType) */

int __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::getSeverityFromThresholds
          (float param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if ((int)param_3 < 0) {
    return 0;
  }
  iVar2 = 6;
  if (param_1 < *(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x30)) {
    iVar2 = 0;
  }
  iVar1 = 0;
  if (!NAN(*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x30))) {
    iVar1 = iVar2;
  }
  iVar2 = 5;
  if (param_1 < *(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x2c) ||
      iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (!NAN(*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x2c))) {
    iVar1 = iVar2;
  }
  iVar2 = 4;
  if (param_1 < *(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x28) ||
      iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (!NAN(*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x28))) {
    iVar1 = iVar2;
  }
  iVar2 = 3;
  if (param_1 < *(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x24) ||
      iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (!NAN(*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x24))) {
    iVar1 = iVar2;
  }
  iVar2 = 2;
  if (param_1 < *(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x20) ||
      iVar1 != 0) {
    iVar2 = iVar1;
  }
  if (!NAN(*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x20))) {
    iVar1 = iVar2;
  }
  iVar2 = iVar1;
  if (*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x1c) <= param_1 &&
      iVar1 == 0) {
    iVar2 = 1;
  }
  if (!NAN(*(float *)(PTR_kMtkTempThreshold_00116aa8 + (ulong)param_3 * 0x58 + 0x1c))) {
    iVar1 = iVar2;
  }
  return iVar1;
}
