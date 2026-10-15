// getTemperatureThresholds @ 0xb8a8
/* android::hardware::thermal::V2_0::implementation::Thermal::getTemperatureThresholds(bool,
   android::hardware::thermal::V2_0::TemperatureType, std::function<void
   (android::hardware::thermal::V1_0::ThermalStatus const&,
   android::hardware::hidl_vec<android::hardware::thermal::V2_0::TemperatureThreshold> const&)>) */

void android::hardware::thermal::V2_0::implementation::Thermal::getTemperatureThresholds
               (undefined8 *param_1,long param_2,uint param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long local_80;
  char cStack_74;
  undefined8 uStack_78;
  ulong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  long local_58;
  
  lVar1 = tpidr_el0;
  local_58 = *(long *)(lVar1 + 0x28);
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  android::hardware::hidl_string::hidl_string((hidl_string *)&uStack_68);
  local_70 = local_70 & 0xffffffff00000000;
  local_80 = 0;
  uStack_78 = 0;
  uVar2 = ThermalHelper::fill_thresholds
                    ((ThermalHelper *)(param_2 + 0x10),param_3 & 1,&local_80,param_4);
  if ((uVar2 & 1) == 0) {
    local_70 = CONCAT44(local_70._4_4_,1);
    android::hardware::hidl_string::operator=
              ((hidl_string *)&uStack_68,"get temperature thresholds fail");
  }
  plVar3 = *(long **)(param_5 + 0x20);
  if (plVar3 == (long *)0x0) {
    std::__throw_bad_function_call();
  }
  else {
    (**(code **)(*plVar3 + 0x30))(plVar3,&local_70,&local_80);
    *(undefined1 *)(param_1 + 4) = 0;
    param_1[1] = 0;
    *param_1 = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    if ((cStack_74 != '\0') && (local_80 != 0)) {
      plVar3 = (long *)(local_80 + -8);
      lVar4 = *plVar3;
      if (lVar4 != 0) {
        lVar4 = lVar4 * 0x58;
        lVar5 = local_80 + -0x50;
        do {
          android::hardware::hidl_string::~hidl_string((hidl_string *)(lVar5 + lVar4));
          lVar4 = lVar4 + -0x58;
        } while (lVar4 != 0);
      }
      operator_delete__(plVar3);
    }
    android::hardware::hidl_string::~hidl_string((hidl_string *)&uStack_68);
    if (*(long *)(lVar1 + 0x28) == local_58) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
