// fill_temperatures @ 0x12a9c
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::fill_temperatures(bool,
   android::hardware::hidl_vec<android::hardware::thermal::V2_0::Temperature>*,
   android::hardware::thermal::V2_0::TemperatureType) */

undefined4 __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::fill_temperatures
          (ThermalHelper *this,byte param_1,
          hidl_vec<android::hardware::thermal::V2_0::Temperature> *param_2,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  ulong uVar4;
  ThermalHelper *this_00;
  ulong uVar5;
  undefined4 *puVar6;
  ostream *poVar7;
  long lVar8;
  long lVar9;
  undefined4 uVar10;
  int *piVar11;
  V2_0 local_e0 [16];
  void *local_d0;
  V2_0 local_c8 [16];
  void *local_b8;
  LogMessage aLStack_b0 [8];
  undefined4 *local_a8;
  undefined4 *local_a0;
  undefined4 *local_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long local_68;
  
  lVar2 = tpidr_el0;
  local_68 = *(long *)(lVar2 + 0x28);
  local_a8 = (undefined4 *)0x0;
  local_a0 = (undefined4 *)0x0;
  local_98 = (undefined4 *)0x0;
  uVar4 = is_tz_path_valided(this,param_4);
  if ((uVar4 & 1) == 0) {
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
  }
  uVar4 = 0;
  uVar10 = 0;
  piVar11 = (int *)(PTR_tz_data_00116aa0 + 0x28);
  do {
    uStack_88 = 0;
    local_90 = 0;
    local_78 = 0;
    uStack_80 = 0;
    this_00 = (ThermalHelper *)
              android::hardware::hidl_string::hidl_string((hidl_string *)&uStack_88);
    if (((param_4 != uVar4 & param_1) == 0) && (*piVar11 != -1)) {
      uVar5 = read_temperature(this_00,(int)uVar4,(Temperature *)&local_90);
      if ((uVar5 & 1) == 0) {
        __android_log_print(5,0,"%s: read temp fail type:%d","fill_temperatures",uVar4 & 0xffffffff)
        ;
        android::hardware::hidl_string::~hidl_string((hidl_string *)&uStack_88);
        uVar10 = 0;
        puVar6 = local_a8;
        goto joined_r0x00112ddc;
      }
      uVar5 = android::base::ShouldLog(2,0);
      if ((uVar5 & 1) != 0) {
        puVar6 = (undefined4 *)__errno();
        uVar10 = *puVar6;
        android::base::LogMessage::LogMessage
                  (aLStack_b0,"vendor/mediatek/proprietary/hardware/thermal/2.0/thermal_helper.cpp",
                   0x159,2,0,0xffffffff);
        poVar7 = (ostream *)android::base::LogMessage::stream();
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                           (poVar7,"fill_temperatures ",0x12);
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>(poVar7,"filterType",10);
        poVar7 = (ostream *)std::ostream::operator<<(poVar7,(bool)(param_1 & 1));
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>(poVar7," name: ",7);
        poVar7 = (ostream *)android::hardware::operator<<(poVar7,(hidl_string *)&uStack_88);
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>(poVar7," type: ",7);
        toString(local_c8,local_90 & 0xffffffff);
        poVar7 = std::operator<<(poVar7,(string *)local_c8);
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                           (poVar7," throttlingStatus: ",0x13);
        toString(local_e0,local_78._4_4_);
        poVar7 = std::operator<<(poVar7,(string *)local_e0);
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>(poVar7," value: ",8);
        poVar7 = (ostream *)std::ostream::operator<<(poVar7,(float)local_78);
        poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                           (poVar7," ret_temps size ",0x10);
        std::ostream::operator<<(poVar7,(long)local_a0 - (long)local_a8 >> 5);
        if (((byte)local_e0[0] & 1) != 0) {
          operator_delete(local_d0);
        }
        if (((byte)local_c8[0] & 1) != 0) {
          operator_delete(local_b8);
        }
        android::base::LogMessage::~LogMessage(aLStack_b0);
        *puVar6 = uVar10;
      }
      puVar6 = local_a0;
      if (local_a0 < local_98) {
        *local_a0 = (undefined4)local_90;
        android::hardware::hidl_string::hidl_string
                  ((hidl_string *)(local_a0 + 2),(hidl_string *)&uStack_88);
        *(undefined8 *)(puVar6 + 6) = local_78;
        local_a0 = local_a0 + 8;
        uVar10 = 1;
      }
      else {
        std::
        vector<android::hardware::thermal::V2_0::Temperature,std::allocator<android::hardware::thermal::V2_0::Temperature>>
        ::__emplace_back_slow_path<android::hardware::thermal::V2_0::Temperature>
                  ((vector<android::hardware::thermal::V2_0::Temperature,std::allocator<android::hardware::thermal::V2_0::Temperature>>
                    *)&local_a8,(Temperature *)&local_90);
        uVar10 = 1;
      }
    }
    android::hardware::hidl_string::~hidl_string((hidl_string *)&uStack_88);
    uVar4 = uVar4 + 1;
    piVar11 = piVar11 + 0x10;
  } while (uVar4 != 10);
  if ((param_2[0xc] != (hidl_vec<android::hardware::thermal::V2_0::Temperature>)0x0) &&
     (lVar8 = *(long *)param_2, lVar8 != 0)) {
    lVar9 = *(long *)(lVar8 + -8);
    if (lVar9 != 0) {
      lVar9 = lVar9 << 5;
      do {
        android::hardware::hidl_string::~hidl_string((hidl_string *)(lVar8 + -0x18 + lVar9));
        lVar9 = lVar9 + -0x20;
      } while (lVar9 != 0);
    }
    operator_delete__((long *)(lVar8 + -8));
  }
  hidl_vec<android::hardware::thermal::V2_0::Temperature>::
  copyFrom<std::vector<android::hardware::thermal::V2_0::Temperature,std::allocator<android::hardware::thermal::V2_0::Temperature>>>
            (param_2,(vector *)&local_a8,(long)local_a0 - (long)local_a8 >> 5);
  puVar6 = local_a8;
joined_r0x00112ddc:
  local_a8 = puVar6;
  puVar3 = local_a0;
  if (puVar6 != (undefined4 *)0x0) {
    for (; puVar3 != puVar6; puVar3 = puVar3 + -8) {
      android::hardware::hidl_string::~hidl_string((hidl_string *)(puVar3 + -6));
    }
    local_a0 = puVar6;
    operator_delete(local_a8);
  }
  if (*(long *)(lVar2 + 0x28) == local_68) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
