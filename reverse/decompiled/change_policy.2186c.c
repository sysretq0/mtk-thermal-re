/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: change_policy   VMA: 0x2186c   (see reverse/symbols.csv)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 change_policy(char *param_1)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  char *__s1;
  char *pcVar5;
  ulong uVar6;
  
  iVar2 = strncmp(param_1,"thermal_options.conf",0x14);
  pcVar1 = DAT_0012e840;
  pcVar5 = DAT_0012e840;
  if (iVar2 == 0) {
    pcVar5 = "%s is not a thermal policy.\n";
LAB_0012193c:
    __android_log_print(4,"thermal_core",pcVar5,param_1);
    uVar4 = 0xffffffff;
  }
  else {
    for (; pcVar5 != (char *)0x0; pcVar5 = *(char **)(pcVar5 + 0x50)) {
      if (*(int *)(pcVar1 + 0x40) == 0) {
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if (*(int *)(pcVar5 + 0x40) != 0) {
        __s1 = *(char **)(pcVar5 + 0x48);
        sVar3 = strlen(param_1);
        uVar6 = 0;
        do {
          iVar2 = strncmp(__s1,param_1,sVar3);
          if (iVar2 == 0) {
            if ((int)uVar6 < 0) goto LAB_00121980;
            pcVar5 = "%s is a sub policy, and it is illegal to change a sub policy directly.\n";
            goto LAB_0012193c;
          }
          uVar6 = uVar6 + 1;
          __s1 = __s1 + 0x48;
        } while (uVar6 < *(uint *)(pcVar5 + 0x40));
      }
    }
    if (*(int *)PTR_DAT_0012d278 == 1) {
      __android_log_print(4,"thermal_core","Failed to find sub policy index of %s\n",param_1);
    }
LAB_00121980:
    pcVar5 = DAT_0012e840;
    if (DAT_0012e840 != (char *)0x0) {
      sVar3 = strlen(param_1);
      do {
        iVar2 = strncmp(pcVar5,param_1,sVar3);
        if (iVar2 == 0) {
          iVar2 = thermal_options_checker(param_1);
          if (iVar2 != 0) {
            return 0xffffffff;
          }
          DAT_0012ea74 = 1;
          snprintf(&DAT_0012e848,0x40,(char *)0x40,&DAT_00102ab3,param_1);
          return 0;
        }
        pcVar5 = *(char **)(pcVar5 + 0x50);
      } while (pcVar5 != (char *)0x0);
    }
    if (*(int *)PTR_DAT_0012d278 == 1) {
      __android_log_print(4,"thermal_core","Failed to find default policy index of %s\n",param_1);
    }
    uVar4 = exe_change_policy(param_1);
    if ((int)uVar4 == 0) {
      DAT_0012ea74 = 0;
      uRam000000000012e850 = 0;
      _DAT_0012e848 = 0;
      uRam000000000012e860 = 0;
      _DAT_0012e858 = 0;
      uRam000000000012e870 = 0;
      _DAT_0012e868 = 0;
      uRam000000000012e880 = 0;
      _DAT_0012e878 = 0;
    }
  }
  return uVar4;
}
