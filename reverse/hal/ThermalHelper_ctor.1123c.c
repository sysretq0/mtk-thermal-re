// ThermalHelper_ctor @ 0x1123c
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::ThermalHelper(std::function<void
   (std::vector<android::hardware::thermal::V2_0::Temperature,
   std::allocator<android::hardware::thermal::V2_0::Temperature> > const&)> const&) */

void __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::ThermalHelper
          (ThermalHelper *this,function *param_1)

{
  long lVar1;
  byte bVar2;
  undefined4 uVar3;
  ThermalWatcher *this_00;
  long *plVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined4 *puVar7;
  ostream *poVar8;
  code *pcVar9;
  undefined *local_80;
  undefined *puStack_78;
  undefined8 local_70;
  ThermalHelper *local_68;
  long *local_60;
  long local_48;
  
  lVar1 = tpidr_el0;
  local_48 = *(long *)(lVar1 + 0x28);
  this_00 = operator_new(0xf0);
  local_70 = 0;
  local_80 = PTR_vtable_00116ad0 + 0x10;
  puStack_78 = PTR_thermalWatcherCallbackFunc_00116ad8;
  local_68 = this;
  local_60 = (long *)&local_80;
  ThermalWatcher::ThermalWatcher(this_00,(function *)&local_80);
  *(ThermalWatcher **)this = this_00;
  if (((ulong)&stack0xffffffffffffffc0 ^ (ulong)this_00) < 0x1000) {
    android::sp_report_stack_pointer();
  }
  android::RefBase::incStrong(this_00 + *(long *)(*(long *)this_00 + -0x18));
  if (&local_80 == (undefined **)local_60) {
    pcVar9 = *(code **)(*local_60 + 0x20);
  }
  else {
    if (local_60 == (long *)0x0) goto LAB_001112f0;
    pcVar9 = *(code **)(*local_60 + 0x28);
  }
  (*pcVar9)();
LAB_001112f0:
  plVar4 = *(long **)(param_1 + 0x20);
  if (plVar4 == (long *)0x0) {
    *(undefined8 *)(this + 0x30) = 0;
  }
  else if ((long *)param_1 == plVar4) {
    *(ThermalHelper **)(this + 0x30) = this + 0x10;
    (**(code **)(**(long **)(param_1 + 0x20) + 0x18))();
  }
  else {
    uVar5 = (**(code **)(*plVar4 + 0x10))();
    *(undefined8 *)(this + 0x30) = uVar5;
  }
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(ThermalHelper **)(this + 0x68) = this + 0x70;
  uVar3 = get_tz_map_version();
  *(undefined4 *)(this + 0x88) = uVar3;
  __android_log_print(5,0,"%s:tz_map_version %d","ThermalHelper",uVar3);
  ThermalWatcher::initThermalWatcher(*(ThermalWatcher **)this,*(int *)(this + 0x88));
  bVar2 = ThermalWatcher::startThermalWatcher(*(ThermalWatcher **)this);
  this[8] = (ThermalHelper)(bVar2 & 1);
  if (((bVar2 & 1) == 0) && (uVar6 = android::base::ShouldLog(6,0), (uVar6 & 1) != 0)) {
    puVar7 = (undefined4 *)__errno();
    uVar3 = *puVar7;
    android::base::LogMessage::LogMessage
              ((LogMessage *)&local_80,
               "vendor/mediatek/proprietary/hardware/thermal/2.0/thermal_helper.cpp",0x51,6,0,
               0xffffffff);
    poVar8 = (ostream *)android::base::LogMessage::stream();
    std::__put_character_sequence<char,std::char_traits<char>>
              (poVar8,"ThermalHAL could not start watching thread properly.",0x34);
    android::base::LogMessage::~LogMessage((LogMessage *)&local_80);
    *puVar7 = uVar3;
  }
  if (*(long *)(lVar1 + 0x28) == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
