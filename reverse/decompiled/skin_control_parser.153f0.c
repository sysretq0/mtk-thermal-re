/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: skin_control_parser   VMA: 0x153f0   (see reverse/symbols.csv)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void skin_control_parser(FILE *param_1,char *param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  int *piVar7;
  byte bVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  char *pcVar13;
  ulong local_c8;
  int local_b8;
  int local_b4;
  char local_b0 [72];
  long local_68;
  
  lVar3 = tpidr_el0;
  local_68 = *(long *)(lVar3 + 0x28);
  local_b8 = 0;
  DAT_0012e8b0 = 0;
  _DAT_0012e8c8 = 0xffffffffffffffff;
  _DAT_0012e8d0 = 0xffffffffffffffff;
  local_c8 = ftell(param_1);
  while (pcVar5 = fgets(param_2,0x100,param_1), pcVar5 != (char *)0x0) {
    sVar6 = strlen(param_2);
    uVar10 = (uint)sVar6;
    if (0 < (int)uVar10) {
      uVar9 = sVar6 & 0xffffffff;
      do {
        uVar10 = uVar10 - 1;
        if (0x20 < (byte)param_2[uVar10] ||
            (1L << ((ulong)(byte)param_2[uVar10] & 0x3f) & 0x100002400U) == 0) goto LAB_001154c8;
        uVar12 = uVar9 - 1;
        bVar1 = 0 < (long)uVar9;
        uVar9 = uVar12;
      } while (uVar12 != 0 && bVar1);
      uVar9 = 0;
LAB_001154c8:
      param_2[(int)uVar9] = '\0';
    }
    if (param_3 == 2) {
      sVar6 = strnlen(param_2,0x200);
      if (sVar6 != 0) {
        uVar9 = 1;
        uVar12 = 0;
        do {
          uVar11 = uVar9;
          bVar8 = param_2[uVar12];
          if (bVar8 - 0x20 < 0x5b) {
            uVar10 = ((uint)bVar8 - ((int)uVar12 + (int)(uVar12 / 5) * -5)) + 0x3b;
            bVar8 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
          }
          param_2[uVar12] = bVar8;
          sVar6 = strnlen(param_2,0x200);
          uVar9 = (ulong)((int)uVar11 + 1);
          uVar12 = uVar11;
        } while (uVar11 < sVar6);
      }
    }
    else if ((param_3 == 1) && (sVar6 = strnlen(param_2,0x200), sVar6 != 0)) {
      uVar9 = 1;
      uVar12 = 0;
      do {
        uVar11 = uVar9;
        bVar8 = param_2[uVar12];
        if (bVar8 - 0x20 < 0x5b) {
          uVar10 = ((uint)bVar8 - ((int)uVar12 + (int)(uVar12 / 10) * -10)) + 0x3b;
          bVar8 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
        }
        param_2[uVar12] = bVar8;
        sVar6 = strnlen(param_2,0x200);
        uVar9 = (ulong)((int)uVar11 + 1);
        uVar12 = uVar11;
      } while (uVar11 < sVar6);
    }
    sVar6 = strlen(param_2);
    if (((int)sVar6 != 0) && (cVar2 = *param_2, cVar2 != '#')) {
      if ((cVar2 == '[') && (param_2[(int)sVar6 + -1] == ']')) break;
      iVar4 = strncmp(param_2,"sensor",6);
      pcVar5 = param_2;
      if (iVar4 == 0) {
        while (pcVar13 = pcVar5 + 1, cVar2 != '\0') {
          if (cVar2 == '=') {
            *pcVar5 = '\0';
            pcVar5 = pcVar13;
            break;
          }
          pcVar5 = pcVar13;
          cVar2 = *pcVar13;
        }
        for (; *pcVar5 == ' ' || *pcVar5 == '\t'; pcVar5 = pcVar5 + 1) {
        }
        snprintf(&DAT_0012e8d8,0x1e,(char *)0x1e,&DAT_00102ab3);
        if (param_2 != (char *)0x0) goto LAB_0011563c;
LAB_001156e4:
        pcVar13 = (char *)0x0;
      }
      else {
        if (param_2 == (char *)0x0) goto LAB_001156e4;
LAB_0011563c:
        cVar2 = *param_2;
        pcVar5 = param_2;
        while (pcVar13 = pcVar5, cVar2 != '\0') {
          if (cVar2 == '=') {
            pcVar13 = pcVar5 + 1;
            *pcVar5 = '\0';
            break;
          }
          pcVar5 = pcVar5 + 1;
          cVar2 = *pcVar5;
        }
        for (; *pcVar13 == ' ' || *pcVar13 == '\t'; pcVar13 = pcVar13 + 1) {
        }
      }
      sscanf(pcVar13,"%d",&local_b8);
      iVar4 = strncmp(param_2,"max_target_tj",0xd);
      if (iVar4 == 0) {
        DAT_0012e888 = local_b8;
      }
      else {
        iVar4 = strncmp(param_2,"min_target_tj",0xd);
        if (iVar4 == 0) {
          DAT_0012e88c = local_b8;
        }
        else {
          iVar4 = strncmp(param_2,"trip_tpcb",9);
          if (iVar4 == 0) {
            DAT_0012e894 = local_b8;
          }
          else {
            iVar4 = strncmp(param_2,"target_tpcb",0xb);
            if (iVar4 == 0) {
              DAT_0012e898 = local_b8;
              node_write(pcVar13,"/sys/kernel/thermal/target_tpcb");
            }
            else {
              iVar4 = strncmp(param_2,"atc_mode",8);
              if (iVar4 == 0) {
                iVar4 = strncmp(pcVar13,"enable",6);
                if (iVar4 == 0) {
                  DAT_0012e8b0 = 1;
                }
                else {
                  DAT_0012e8b0 = 0;
                }
              }
              else {
                iVar4 = strncmp(param_2,"cluster0_min_throttle_freq",0x1a);
                if (iVar4 == 0) {
                  _DAT_0012e8c8 = CONCAT44(_DAT_0012e8cc,local_b8);
                }
                else {
                  iVar4 = strncmp(param_2,"cluster1_min_throttle_freq",0x1a);
                  if (iVar4 == 0) {
                    _DAT_0012e8c8 = CONCAT44(local_b8,DAT_0012e8c8);
                  }
                  else {
                    iVar4 = strncmp(param_2,"cluster2_min_throttle_freq",0x1a);
                    if (iVar4 == 0) {
                      _DAT_0012e8d0 = CONCAT44(_DAT_0012e8d4,local_b8);
                    }
                    else {
                      iVar4 = strncmp(param_2,"gpu_min_throttle_freq",0x15);
                      if (iVar4 == 0) {
                        _DAT_0012e8d0 = CONCAT44(local_b8,DAT_0012e8d0);
                      }
                      else {
                        iVar4 = strncmp(param_2,"atc_max_target_tj",0x11);
                        if (iVar4 == 0) {
                          DAT_0012e8b8 = local_b8;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      local_c8 = ftell(param_1);
    }
  }
  if (DAT_0012e8b0 != 0) {
    DAT_0012e8bc = DAT_0012e888;
    local_b0[0x28] = '\0';
    local_b0[0x29] = '\0';
    local_b0[0x2a] = '\0';
    local_b0[0x2b] = '\0';
    local_b0[0x2c] = '\0';
    local_b0[0x2d] = '\0';
    local_b0[0x2e] = '\0';
    local_b0[0x2f] = '\0';
    local_b0[0x20] = '\0';
    local_b0[0x21] = '\0';
    local_b0[0x22] = '\0';
    local_b0[0x23] = '\0';
    local_b0[0x24] = '\0';
    local_b0[0x25] = '\0';
    local_b0[0x26] = '\0';
    local_b0[0x27] = '\0';
    local_b0[0x38] = '\0';
    local_b0[0x39] = '\0';
    local_b0[0x3a] = '\0';
    local_b0[0x3b] = '\0';
    local_b0[0x3c] = '\0';
    local_b0[0x3d] = '\0';
    local_b0[0x3e] = '\0';
    local_b0[0x3f] = '\0';
    local_b0[0x30] = '\0';
    local_b0[0x31] = '\0';
    local_b0[0x32] = '\0';
    local_b0[0x33] = '\0';
    local_b0[0x34] = '\0';
    local_b0[0x35] = '\0';
    local_b0[0x36] = '\0';
    local_b0[0x37] = '\0';
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
    local_b4 = 0;
    node_read("/sys/kernel/thermal/atc",local_b0,0x40);
    sscanf(local_b0,"%d",&local_b4);
    DAT_0012e888 = DAT_0012e8b8;
    if (local_b4 <= DAT_0012e8b8 || DAT_0012e8b8 == 0) {
      DAT_0012e888 = local_b4;
    }
  }
  DAT_0012e89c = 0;
  if (DAT_0012e898 - DAT_0012e894 != 0) {
    DAT_0012e89c = 0xd2f000 / (DAT_0012e898 - DAT_0012e894);
  }
  DAT_0012e890 = DAT_0012e888 + -0x34bc;
  if (DAT_0012e8a4 == 0) {
    DAT_0012e8ac = 0;
  }
  else {
    DAT_0012e8ac = 0;
    if (DAT_0012e8a4 != 0) {
      DAT_0012e8ac = 0xd2f000 / DAT_0012e8a4;
    }
  }
  if (DAT_0012e8a0 == 0) {
    DAT_0012e8a8 = 0;
  }
  else {
    DAT_0012e8a8 = 0;
    if (DAT_0012e8a0 != 0) {
      DAT_0012e8a8 = ((DAT_0012e88c - DAT_0012e890) * 0x400) / DAT_0012e8a0;
    }
  }
  __android_log_print(4,"thermal_core","g_catm.sensor_name: %s\n",&DAT_0012e8d8);
  add_thermal_instance(&DAT_0012e8d8,"tskin_control",0,0,2);
  if ((int)local_c8 < 0) {
    pcVar5 = "Negative file position %s\n";
  }
  else {
    iVar4 = fseek(param_1,local_c8 & 0xffffffff,0);
    if (iVar4 != -1) goto LAB_00115a38;
    pcVar5 = "fseek failed: %s\n";
  }
  piVar7 = (int *)__errno();
  pcVar13 = strerror(*piVar7);
  __android_log_print(6,"thermal_core",pcVar5,pcVar13);
LAB_00115a38:
  if (*(long *)(lVar3 + 0x28) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
