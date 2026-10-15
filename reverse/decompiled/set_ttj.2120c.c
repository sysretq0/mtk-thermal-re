/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: set_ttj   VMA: 0x2120c   (see reverse/symbols.csv)
 */

void set_ttj(uint param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  ulong uVar7;
  long lVar8;
  char local_120 [80];
  char local_d0 [32];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_68;
  
  lVar3 = tpidr_el0;
  local_68 = *(long *)(lVar3 + 0x28);
  local_d0[8] = '\0';
  local_d0[9] = '\0';
  local_d0[10] = '\0';
  local_d0[0xb] = '\0';
  local_d0[0xc] = '\0';
  local_d0[0xd] = '\0';
  local_d0[0xe] = '\0';
  local_d0[0xf] = '\0';
  local_d0[0] = '\0';
  local_d0[1] = '\0';
  local_d0[2] = '\0';
  local_d0[3] = '\0';
  local_d0[4] = '\0';
  local_d0[5] = '\0';
  local_d0[6] = '\0';
  local_d0[7] = '\0';
  local_d0[0x18] = '\0';
  local_d0[0x19] = '\0';
  local_d0[0x1a] = '\0';
  local_d0[0x1b] = '\0';
  local_d0[0x1c] = '\0';
  local_d0[0x1d] = '\0';
  local_d0[0x1e] = '\0';
  local_d0[0x1f] = '\0';
  local_d0[0x10] = '\0';
  local_d0[0x11] = '\0';
  local_d0[0x12] = '\0';
  local_d0[0x13] = '\0';
  local_d0[0x14] = '\0';
  local_d0[0x15] = '\0';
  local_d0[0x16] = '\0';
  local_d0[0x17] = '\0';
  local_120[0x40] = '\0';
  local_120[0x41] = '\0';
  local_120[0x42] = '\0';
  local_120[0x43] = '\0';
  local_120[0x44] = '\0';
  local_120[0x45] = '\0';
  local_120[0x28] = '\0';
  local_120[0x29] = '\0';
  local_120[0x2a] = '\0';
  local_120[0x2b] = '\0';
  local_120[0x2c] = '\0';
  local_120[0x2d] = '\0';
  local_120[0x2e] = '\0';
  local_120[0x2f] = '\0';
  local_120[0x20] = '\0';
  local_120[0x21] = '\0';
  local_120[0x22] = '\0';
  local_120[0x23] = '\0';
  local_120[0x24] = '\0';
  local_120[0x25] = '\0';
  local_120[0x26] = '\0';
  local_120[0x27] = '\0';
  local_120[0x38] = '\0';
  local_120[0x39] = '\0';
  local_120[0x3a] = '\0';
  local_120[0x3b] = '\0';
  local_120[0x3c] = '\0';
  local_120[0x3d] = '\0';
  local_120[0x3e] = '\0';
  local_120[0x3f] = '\0';
  local_120[0x30] = '\0';
  local_120[0x31] = '\0';
  local_120[0x32] = '\0';
  local_120[0x33] = '\0';
  local_120[0x34] = '\0';
  local_120[0x35] = '\0';
  local_120[0x36] = '\0';
  local_120[0x37] = '\0';
  local_120[8] = '\0';
  local_120[9] = '\0';
  local_120[10] = '\0';
  local_120[0xb] = '\0';
  local_120[0xc] = '\0';
  local_120[0xd] = '\0';
  local_120[0xe] = '\0';
  local_120[0xf] = '\0';
  local_120[0] = '\0';
  local_120[1] = '\0';
  local_120[2] = '\0';
  local_120[3] = '\0';
  local_120[4] = '\0';
  local_120[5] = '\0';
  local_120[6] = '\0';
  local_120[7] = '\0';
  local_120[0x18] = '\0';
  local_120[0x19] = '\0';
  local_120[0x1a] = '\0';
  local_120[0x1b] = '\0';
  local_120[0x1c] = '\0';
  local_120[0x1d] = '\0';
  local_120[0x1e] = '\0';
  local_120[0x1f] = '\0';
  local_120[0x10] = '\0';
  local_120[0x11] = '\0';
  local_120[0x12] = '\0';
  local_120[0x13] = '\0';
  local_120[0x14] = '\0';
  local_120[0x15] = '\0';
  local_120[0x16] = '\0';
  local_120[0x17] = '\0';
  if (DAT_0012ea50 == param_1) goto LAB_001215bc;
  uVar2 = DAT_0012e8bc;
  if ((int)param_1 <= (int)DAT_0012e8bc) {
    uVar2 = param_1;
  }
  uVar1 = param_1;
  if (DAT_0012e8b0 != 0) {
    uVar1 = uVar2;
  }
  DAT_0012ea50 = param_1;
  snprintf(local_d0,0x20,(char *)0x20,&DAT_00101ff6,(ulong)uVar1);
  if (DAT_0012f384 != '\0') {
    node_write(local_d0,&DAT_0012f384);
  }
  lVar4 = DAT_0012ea68;
  if (DAT_0012ea68 != 0) {
    uVar7 = (ulong)DAT_0012ea60;
    if (DAT_0012ea60 == 0) {
LAB_00121340:
      __android_log_print(6,"thermal_core","Failed to find thermal zone index of %s\n",&DAT_0010516f
                         );
    }
    else {
      iVar5 = strncmp((char *)(DAT_0012ea68 + 4),"gpu2",4);
      if (iVar5 == 0) {
        lVar8 = 0;
      }
      else {
        lVar8 = 0;
        if (uVar7 < 2) {
          uVar7 = 1;
        }
        pcVar6 = (char *)(lVar4 + 0x54);
        do {
          if (1 - uVar7 == lVar8) goto LAB_00121340;
          iVar5 = strncmp(pcVar6,"gpu2",4);
          lVar8 = lVar8 + -1;
          pcVar6 = pcVar6 + 0x50;
        } while (iVar5 != 0);
        if ((int)lVar8 == 1) goto LAB_0012139c;
        lVar8 = -lVar8;
      }
      snprintf(local_120,0x46,(char *)0x46,"/sys/class/thermal/thermal_zone%d/trip_point_0_temp",
               lVar8);
      iVar5 = access(local_120,0);
      if (iVar5 == 0) {
        node_write(local_d0,local_120);
      }
    }
  }
LAB_0012139c:
  uVar2 = param_1;
  if (DAT_0012e8b4 != 1) {
    uVar2 = uVar1;
  }
  DAT_0012e8c0 = param_1;
  DAT_0012e8c4 = uVar1;
  snprintf(local_d0,0x20,(char *)0x20,"TTJ %d %d %d",(ulong)param_1,(ulong)uVar2,(ulong)uVar1);
  snprintf(local_120,0x46,(char *)0x46,"/sys/kernel/thermal/ttj");
  node_write(local_d0,local_120);
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  if (uVar1 != 0xfffbd1b0) {
    uVar2 = (int)uVar1 / 1000;
    snprintf((char *)&local_b0,0x40,(char *)0x40,"TYPE=thermal_hal_update NAME=CPU THRESHOLD=%d",
             (ulong)uVar2);
    send_notification_to_thermal_hal(&local_b0);
    snprintf((char *)&local_b0,0x40,(char *)0x40,"TYPE=thermal_hal_update NAME=GPU THRESHOLD=%d",
             (ulong)uVar2);
    send_notification_to_thermal_hal(&local_b0);
    snprintf((char *)&local_b0,0x40,(char *)0x40,"TYPE=thermal_hal_update NAME=NPU THRESHOLD=%d",
             (ulong)uVar2);
    send_notification_to_thermal_hal(&local_b0);
    lVar4 = DAT_0012ea68;
    if (DAT_0012ea68 != 0) {
      uVar7 = (ulong)DAT_0012ea60;
      if (DAT_0012ea60 == 0) {
LAB_00121518:
        __android_log_print(6,"thermal_core","Failed to find thermal zone index of %s\n","soc_max");
      }
      else {
        iVar5 = strncmp((char *)(DAT_0012ea68 + 4),"soc_max",7);
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          lVar8 = 0;
          if (uVar7 < 2) {
            uVar7 = 1;
          }
          pcVar6 = (char *)(lVar4 + 0x54);
          do {
            if (1 - uVar7 == lVar8) goto LAB_00121518;
            iVar5 = strncmp(pcVar6,"soc_max",7);
            lVar8 = lVar8 + -1;
            pcVar6 = pcVar6 + 0x50;
          } while (iVar5 != 0);
          if ((int)lVar8 == 1) goto LAB_0012154c;
          iVar5 = -(int)lVar8;
        }
        *(uint *)(lVar4 + (long)iVar5 * 0x50 + 0x30) = uVar1;
      }
    }
  }
LAB_0012154c:
  uVar2 = uVar1;
  if (DAT_0012e8b4 == 1) {
    uVar2 = param_1;
  }
  if (*(int *)PTR_DAT_0012d278 == 1) {
    __android_log_print(4,"thermal_core","set_ttj %d %d %d\n",param_1,uVar2,uVar1);
  }
LAB_001215bc:
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
