/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: thermal_options_checker   VMA: 0x87b0   (see reverse/symbols.csv)
 */

/* WARNING: Removing unreachable block (ram,0x00108820) */

undefined4 thermal_options_checker(char *param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  size_t sVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  int *piVar8;
  char *__s;
  undefined4 uVar9;
  undefined4 uVar10;
  char local_80 [72];
  long local_38;
  
  lVar1 = tpidr_el0;
  local_38 = *(long *)(lVar1 + 0x28);
  local_80[0x28] = '\0';
  local_80[0x29] = '\0';
  local_80[0x2a] = '\0';
  local_80[0x2b] = '\0';
  local_80[0x2c] = '\0';
  local_80[0x2d] = '\0';
  local_80[0x2e] = '\0';
  local_80[0x2f] = '\0';
  local_80[0x20] = '\0';
  local_80[0x21] = '\0';
  local_80[0x22] = '\0';
  local_80[0x23] = '\0';
  local_80[0x24] = '\0';
  local_80[0x25] = '\0';
  local_80[0x26] = '\0';
  local_80[0x27] = '\0';
  local_80[0x38] = '\0';
  local_80[0x39] = '\0';
  local_80[0x3a] = '\0';
  local_80[0x3b] = '\0';
  local_80[0x3c] = '\0';
  local_80[0x3d] = '\0';
  local_80[0x3e] = '\0';
  local_80[0x3f] = '\0';
  local_80[0x30] = '\0';
  local_80[0x31] = '\0';
  local_80[0x32] = '\0';
  local_80[0x33] = '\0';
  local_80[0x34] = '\0';
  local_80[0x35] = '\0';
  local_80[0x36] = '\0';
  local_80[0x37] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  local_80[0x18] = '\0';
  local_80[0x19] = '\0';
  local_80[0x1a] = '\0';
  local_80[0x1b] = '\0';
  local_80[0x1c] = '\0';
  local_80[0x1d] = '\0';
  local_80[0x1e] = '\0';
  local_80[0x1f] = '\0';
  local_80[0x10] = '\0';
  local_80[0x11] = '\0';
  local_80[0x12] = '\0';
  local_80[0x13] = '\0';
  local_80[0x14] = '\0';
  local_80[0x15] = '\0';
  local_80[0x16] = '\0';
  local_80[0x17] = '\0';
  pthread_mutex_lock((pthread_mutex_t *)&DAT_0012e818);
  bVar2 = DAT_0012ea74;
  __s = DAT_0012e840;
  if (param_1 == (char *)0x0) {
    uVar5 = __strlen_chk(&DAT_0012e848,0x40);
    __strncpy_chk2(local_80,&DAT_0012e848,uVar5,0x40,0x40);
    uVar10 = 0xffffffff;
    if (((bVar2 ^ 1) & 1) != 0) goto LAB_00108908;
  }
  else {
    sVar4 = strlen(param_1);
    __strncpy_chk(local_80,param_1,sVar4,0x40);
  }
  uVar10 = 0xffffffff;
  if (__s != (char *)0x0) {
    uVar9 = 0xffffffff;
    do {
      sVar4 = strlen(__s);
      iVar3 = strncmp(__s,local_80,sVar4);
      uVar10 = uVar9;
      if (iVar3 == 0) {
        if (*(uint *)(__s + 0x40) != 0) {
          uVar7 = 0;
          lVar6 = *(long *)(__s + 0x48);
          do {
            piVar8 = *(int **)(lVar6 + 0x40);
            if (((*piVar8 != 0) && (DAT_0012e708 <= piVar8[2])) && (piVar8[1] <= DAT_0012e708)) {
              iVar3 = exe_change_policy();
              if (iVar3 == 0) {
                uVar10 = 0;
                goto LAB_0010888c;
              }
              break;
            }
            uVar7 = uVar7 + 1;
            lVar6 = lVar6 + 0x48;
          } while (uVar7 < *(uint *)(__s + 0x40));
        }
        iVar3 = exe_change_policy(__s);
        uVar10 = 0;
        if (iVar3 != 0) {
          uVar10 = uVar9;
        }
      }
LAB_0010888c:
      __s = *(char **)(__s + 0x50);
      uVar9 = uVar10;
    } while (__s != (char *)0x0);
  }
LAB_00108908:
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e818);
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar3);
}
