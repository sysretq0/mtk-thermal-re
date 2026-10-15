/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: cmd_handler   VMA: 0xfeb0   (see reverse/symbols.csv)
 */

undefined4 cmd_handler(char *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  char *pcVar5;
  char *local_b8;
  char local_b0 [64];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined7 uStack_48;
  undefined4 local_41;
  long local_38;
  
  lVar1 = tpidr_el0;
  local_38 = *(long *)(lVar1 + 0x28);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  local_41 = 0;
  uStack_50 = 0;
  uStack_68 = 0;
  local_70 = 0;
  local_b0[0x18] = '\0';
  local_b0[0x19] = '\0';
  local_b0[0x1a] = '\0';
  local_b0[0x1b] = '\0';
  local_b0[0x1c] = '\0';
  local_b0[0x1d] = '\0';
  local_b0[0x1e] = '\0';
  local_b0[0x1f] = '\0';
  local_b0[0x10] = '\0';
  local_b0[0x11] = '\0';
  local_b0[0x12] = '\0';
  local_b0[0x13] = '\0';
  local_b0[0x14] = '\0';
  local_b0[0x15] = '\0';
  local_b0[0x16] = '\0';
  local_b0[0x17] = '\0';
  local_b0[0x28] = '\0';
  local_b0[0x29] = '\0';
  local_b0[0x2a] = '\0';
  local_b0[0x2b] = '\0';
  local_b0[0x2c] = '\0';
  local_b0[0x2d] = '\0';
  local_b0[0x2e] = '\0';
  local_b0[0x2f] = '\0';
  local_b0[0x30] = '\0';
  local_b0[0x31] = '\0';
  local_b0[0x32] = '\0';
  local_b0[0x20] = '\0';
  local_b0[0x21] = '\0';
  local_b0[0x22] = '\0';
  local_b0[0x23] = '\0';
  local_b0[0x24] = '\0';
  local_b0[0x25] = '\0';
  local_b0[0x26] = '\0';
  local_b0[0x27] = '\0';
  local_b0[8] = '\0';
  local_b0[9] = '\0';
  local_b0[10] = '\0';
  local_b0[0xb] = '\0';
  local_b0[0xc] = '\0';
  local_b0[0xd] = '\0';
  local_b0[0xe] = '\0';
  local_b0[0xf] = '\0';
  local_b0[0] = '\0';
  local_b0[1] = '\0';
  local_b0[2] = '\0';
  local_b0[3] = '\0';
  local_b0[4] = '\0';
  local_b0[5] = '\0';
  local_b0[6] = '\0';
  local_b0[7] = '\0';
  iVar2 = sscanf(param_1,"%50s %50s",&local_70,local_b0);
  __android_log_print(4,"thermal_core","cmd=%s arg1=%s\n",&local_70,local_b0);
  if ((int)local_70 == 0x6c707061 && local_70._4_1_ == 'y') {
    if (iVar2 == 2) {
      uVar3 = change_policy(local_b0);
      goto LAB_00110158;
    }
LAB_00110104:
    uVar3 = 0xffffffff;
    goto LAB_00110178;
  }
  if ((int)local_70 == 0x6f5f646d && local_70._4_2_ == 0x6666) {
    local_b8 = (char *)0x0;
    if (iVar2 != 2) goto LAB_00110104;
    lVar4 = strtol(local_b0,&local_b8,10);
    if ((int)lVar4 == 0) {
      md_on();
      if (*(int *)PTR_DAT_0012d278 == 1) {
        pcVar5 = "turn on MD done\n";
        goto LAB_00110144;
      }
    }
    else {
      md_off();
      if (*(int *)PTR_DAT_0012d278 == 1) {
        pcVar5 = "turn off MD done\n";
LAB_00110144:
        __android_log_print(4,"thermal_core",pcVar5);
      }
    }
LAB_00110154:
    uVar3 = 0;
  }
  else {
    if (local_70 == 0x6f6c5f6775626564 && (char)uStack_68 == 'g') {
      local_b8 = (char *)0x0;
      if (iVar2 != 2) goto LAB_00110104;
      lVar4 = strtol(local_b0,&local_b8,10);
      if ((int)lVar4 != 0) {
        *(undefined4 *)PTR_DAT_0012d278 = 1;
        pcVar5 = "debug log on\n";
        goto LAB_00110144;
      }
      *(undefined4 *)PTR_DAT_0012d278 = 0;
      goto LAB_00110154;
    }
    if ((short)local_70 != 0x7266 || local_70._2_1_ != 's') {
      if (local_70 == 0x646f6d5f6662746d && (char)uStack_68 == 'e') {
        local_b8 = (char *)0x0;
        if (iVar2 != 2) goto LAB_00110104;
        lVar4 = strtol(local_b0,&local_b8,10);
        if ((int)lVar4 == 0) {
          DAT_0012e928 = 0;
          uVar3 = change_policy("thermal.conf");
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","mtbf_mode off\n");
          }
          goto LAB_00110158;
        }
        if (((DAT_0012e928 & 1) == 0) && (iVar2 = change_policy("thermal_mtbf.conf"), iVar2 != -1))
        {
          DAT_0012e928 = 1;
          if (*(int *)PTR_DAT_0012d278 == 1) {
            pcVar5 = "mtbf_mode on\n";
            goto LAB_00110144;
          }
        }
      }
      goto LAB_00110154;
    }
    uVar3 = frs_cmd_handle(param_1);
  }
LAB_00110158:
  __android_log_print(4,"thermal_core","cmd=%s arg1=%s done\n",&local_70,local_b0);
LAB_00110178:
  if (*(long *)(lVar1 + 0x28) == local_38) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
