// init_tz_path @ 0x12a40
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::init_tz_path() */

void __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::init_tz_path(ThermalHelper *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x88);
  if (iVar1 == 3) {
    init_tz_path_v3(this);
  }
  else if (iVar1 == 2) {
    init_tz_path_v2(this);
  }
  else if (iVar1 == 1) {
    init_tz_path_v1(this);
  }
  get_tz_map(this);
  return;
}
