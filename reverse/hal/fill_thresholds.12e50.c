// fill_thresholds @ 0x12e50
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::fill_thresholds(bool,
   android::hardware::hidl_vec<android::hardware::thermal::V2_0::TemperatureThreshold>*,
   android::hardware::thermal::V2_0::TemperatureType) */

undefined4 __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::fill_thresholds
          (undefined8 param_1_00,byte param_1,
          hidl_vec<android::hardware::thermal::V2_0::TemperatureThreshold> *param_2,ulong param_4)

{
  long lVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  FILE *__stream;
  ulong uVar5;
  undefined4 *puVar6;
  ostream *poVar7;
  long lVar8;
  undefined4 uVar9;
  uint *puVar10;
  long lVar11;
  V2_0 local_138 [16];
  void *local_128;
  LogMessage aLStack_120 [8];
  undefined4 *local_118;
  undefined4 *local_110;
  undefined4 *local_108;
  ulong local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  long local_78;
  
  lVar11 = 0;
  uVar9 = 0;
  lVar1 = tpidr_el0;
  local_78 = *(long *)(lVar1 + 0x28);
  local_118 = (undefined4 *)0x0;
  local_110 = (undefined4 *)0x0;
  local_108 = (undefined4 *)0x0;
  local_80 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  puVar10 = (uint *)(PTR_tz_data_00116aa0 + 0x28);
  do {
    fStack_b0 = 0.0;
    uStack_ac = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_b8 = 0;
    uStack_b4 = 0;
    uStack_c0 = 0;
    local_bc = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_d8 = 0;
    uStack_e0 = 0;
    uStack_f8 = 0;
    local_100 = 0;
    android::hardware::hidl_string::hidl_string((hidl_string *)&uStack_f8);
    if (((param_4 & 0xffffffff) * 0x58 - lVar11 != 0 & param_1) == 0) {
      iVar3 = snprintf((char *)&local_a0,0x28,(char *)0x28,"/sys/class/thermal/thermal_zone%d/type",
                       (ulong)*puVar10);
      if (iVar3 < 0) {
        __android_log_print(5,0,"%s: snprintf fail: %d","fill_thresholds",iVar3);
      }
      __stream = fopen((char *)&local_a0,"r");
      if (__stream == (FILE *)0x0) {
        uVar4 = android::hardware::hidl_string::c_str();
        __android_log_print(5,0,"%s: %s not support","fill_thresholds",uVar4);
      }
      else {
        puVar6 = (undefined4 *)(PTR_kMtkTempThreshold_00116aa8 + lVar11);
        local_100 = CONCAT44(local_100._4_4_,*puVar6);
        android::hardware::hidl_string::operator=
                  ((hidl_string *)&uStack_f8,(hidl_string *)(puVar6 + 2));
        uStack_c8 = *(undefined8 *)(puVar6 + 0xe);
        uStack_e0 = *(undefined8 *)(puVar6 + 8);
        uStack_e8 = *(undefined8 *)(puVar6 + 6);
        local_d0 = *(undefined8 *)(puVar6 + 0xc);
        uStack_d8 = *(undefined8 *)(puVar6 + 10);
        uStack_b4 = (undefined4)*(undefined8 *)(puVar6 + 0x13);
        fStack_b0 = (float)((ulong)*(undefined8 *)(puVar6 + 0x13) >> 0x20);
        uStack_b8 = (undefined4)((ulong)*(undefined8 *)(puVar6 + 0x11) >> 0x20);
        uStack_c0 = (undefined4)*(undefined8 *)(puVar6 + 0x10);
        local_bc = (undefined4)((ulong)*(undefined8 *)(puVar6 + 0x10) >> 0x20);
        uVar5 = android::base::ShouldLog(2,0);
        if ((uVar5 & 1) != 0) {
          puVar6 = (undefined4 *)__errno();
          uVar9 = *puVar6;
          android::base::LogMessage::LogMessage
                    (aLStack_120,
                     "vendor/mediatek/proprietary/hardware/thermal/2.0/thermal_helper.cpp",0x181,2,0
                     ,0xffffffff);
          poVar7 = (ostream *)android::base::LogMessage::stream();
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                             (poVar7,"fill_thresholds ",0x10);
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                             (poVar7,"filterType",10);
          poVar7 = (ostream *)std::ostream::operator<<(poVar7,(bool)(param_1 & 1));
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>(poVar7," name: ",7);
          poVar7 = (ostream *)android::hardware::operator<<(poVar7,(hidl_string *)&uStack_f8);
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>(poVar7," type: ",7);
          toString(local_138,local_100 & 0xffffffff);
          poVar7 = std::operator<<(poVar7,(string *)local_138);
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                             (poVar7," hotThrottlingThresholds: ",0x1a);
          poVar7 = (ostream *)std::ostream::operator<<(poVar7,uStack_e0._4_4_);
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                             (poVar7," vrThrottlingThreshold: ",0x18);
          poVar7 = (ostream *)std::ostream::operator<<(poVar7,fStack_b0);
          poVar7 = std::__put_character_sequence<char,std::char_traits<char>>
                             (poVar7," ret_thresholds size ",0x15);
          std::ostream::operator<<
                    (poVar7,((long)local_110 - (long)local_118 >> 3) * 0x2e8ba2e8ba2e8ba3);
          if (((byte)local_138[0] & 1) != 0) {
            operator_delete(local_128);
          }
          android::base::LogMessage::~LogMessage(aLStack_120);
          *puVar6 = uVar9;
        }
        puVar6 = local_110;
        if (local_110 < local_108) {
          *local_110 = (undefined4)local_100;
          android::hardware::hidl_string::hidl_string
                    ((hidl_string *)(local_110 + 2),(hidl_string *)&uStack_f8);
          *(ulong *)(puVar6 + 0x13) = CONCAT44(fStack_b0,uStack_b4);
          *(ulong *)(puVar6 + 0x11) = CONCAT44(uStack_b8,local_bc);
          *(ulong *)(puVar6 + 0x10) = CONCAT44(local_bc,uStack_c0);
          *(undefined8 *)(puVar6 + 0xe) = uStack_c8;
          *(undefined8 *)(puVar6 + 0xc) = local_d0;
          *(undefined8 *)(puVar6 + 10) = uStack_d8;
          *(undefined8 *)(puVar6 + 8) = uStack_e0;
          *(undefined8 *)(puVar6 + 6) = uStack_e8;
          local_110 = local_110 + 0x16;
        }
        else {
          std::
          vector<android::hardware::thermal::V2_0::TemperatureThreshold,std::allocator<android::hardware::thermal::V2_0::TemperatureThreshold>>
          ::__emplace_back_slow_path<android::hardware::thermal::V2_0::TemperatureThreshold>
                    ((vector<android::hardware::thermal::V2_0::TemperatureThreshold,std::allocator<android::hardware::thermal::V2_0::TemperatureThreshold>>
                      *)&local_118,(TemperatureThreshold *)&local_100);
        }
        iVar3 = fclose(__stream);
        if (iVar3 != 0) {
          __android_log_print(5,0,"%s: fclose fail: %d","fill_thresholds",iVar3);
        }
        uVar9 = 1;
      }
    }
    android::hardware::hidl_string::~hidl_string((hidl_string *)&uStack_f8);
    puVar10 = puVar10 + 0x10;
    lVar11 = lVar11 + 0x58;
  } while (lVar11 != 0x370);
  if ((param_2[0xc] != (hidl_vec<android::hardware::thermal::V2_0::TemperatureThreshold>)0x0) &&
     (lVar11 = *(long *)param_2, lVar11 != 0)) {
    lVar8 = *(long *)(lVar11 + -8);
    if (lVar8 != 0) {
      lVar8 = lVar8 * 0x58;
      do {
        android::hardware::hidl_string::~hidl_string((hidl_string *)(lVar11 + -0x50 + lVar8));
        lVar8 = lVar8 + -0x58;
      } while (lVar8 != 0);
    }
    operator_delete__((long *)(lVar11 + -8));
  }
  hidl_vec<android::hardware::thermal::V2_0::TemperatureThreshold>::
  copyFrom<std::vector<android::hardware::thermal::V2_0::TemperatureThreshold,std::allocator<android::hardware::thermal::V2_0::TemperatureThreshold>>>
            (param_2,(vector *)&local_118,
             ((long)local_110 - (long)local_118 >> 3) * 0x2e8ba2e8ba2e8ba3);
  puVar2 = local_118;
  puVar6 = local_110;
  if (local_118 != (undefined4 *)0x0) {
    for (; puVar6 != puVar2; puVar6 = puVar6 + -0x16) {
      android::hardware::hidl_string::~hidl_string((hidl_string *)(puVar6 + -0x14));
    }
    local_110 = puVar2;
    operator_delete(local_118);
  }
  if (*(long *)(lVar1 + 0x28) != local_78) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}
