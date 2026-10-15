// read_temperature @ 0x11c54
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::read_temperature(int,
   android::hardware::thermal::V1_0::Temperature*) */

bool __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::read_temperature
          (ThermalHelper *this,int param_1,Temperature *param_2)

{
  undefined *puVar1;
  ulong uVar2;
  float fVar3;
  double dVar4;
  
  uVar2 = (ulong)(uint)param_1;
  if ((uint)param_1 < 4) {
    fVar3 = (float)get_max_temp(this,param_1);
    android::hardware::hidl_string::operator=
              ((hidl_string *)(param_2 + 8),PTR_tz_data_00116aa0 + uVar2 * 0x40 + 0x14);
    puVar1 = PTR_kMtkTempThreshold_00116aa8;
    dVar4 = (double)fVar3 * DAT_00108c00;
    *(int *)param_2 = param_1;
    *(float *)(param_2 + 0x18) = (float)dVar4;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(puVar1 + uVar2 * 0x58 + 0x24);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(puVar1 + uVar2 * 0x58 + 0x30);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(puVar1 + uVar2 * 0x58 + 0x50);
  }
  return (uint)param_1 < 4;
}
