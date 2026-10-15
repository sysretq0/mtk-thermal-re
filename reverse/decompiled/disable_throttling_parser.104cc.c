/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: disable_throttling_parser   VMA: 0x104cc   (see reverse/symbols.csv)
 */

void disable_throttling_parser(FILE *param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  int *piVar9;
  ulong extraout_x1;
  ulong uVar10;
  ulong extraout_x1_00;
  ulong extraout_x1_01;
  byte bVar11;
  ulong uVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  uint *puVar18;
  ulong uVar19;
  int iVar20;
  ulong extraout_x17;
  ulong uVar21;
  ulong extraout_x17_00;
  ulong extraout_x17_01;
  char *pcVar22;
  ulong local_118;
  char local_100 [64];
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined6 uStack_88;
  undefined2 local_82;
  undefined6 uStack_80;
  long local_70;
  
  lVar4 = tpidr_el0;
  local_70 = *(long *)(lVar4 + 0x28);
  local_118 = ftell(param_1);
  while (pcVar7 = fgets(param_2,0x100,param_1), pcVar7 != (char *)0x0) {
    sVar8 = strlen(param_2);
    uVar14 = (uint)sVar8;
    if (0 < (int)uVar14) {
      uVar12 = sVar8 & 0xffffffff;
      do {
        uVar14 = uVar14 - 1;
        if (0x20 < (byte)param_2[uVar14] ||
            (1L << ((ulong)(byte)param_2[uVar14] & 0x3f) & 0x100002400U) == 0) goto LAB_0011058c;
        uVar10 = uVar12 - 1;
        bVar1 = 0 < (long)uVar12;
        uVar12 = uVar10;
      } while (uVar10 != 0 && bVar1);
      uVar12 = 0;
LAB_0011058c:
      param_2[(int)uVar12] = '\0';
    }
    if (param_3 == 2) {
      sVar8 = strnlen(param_2,0x200);
      if (sVar8 != 0) {
        uVar12 = 0;
        uVar10 = 1;
        do {
          bVar11 = param_2[uVar12];
          if (bVar11 - 0x20 < 0x5b) {
            uVar14 = ((uint)bVar11 - ((int)uVar12 + (int)(uVar12 / 5) * -5)) + 0x3b;
            bVar11 = (char)uVar14 + (char)((uVar14 & 0xff) / 0x5b) * -0x5b + 0x20;
          }
          param_2[uVar12] = bVar11;
          sVar8 = strnlen(param_2,0x200);
          bVar1 = uVar10 < sVar8;
          uVar12 = uVar10;
          uVar10 = (ulong)((int)uVar10 + 1);
        } while (bVar1);
      }
    }
    else if ((param_3 == 1) && (sVar8 = strnlen(param_2,0x200), sVar8 != 0)) {
      uVar12 = 0;
      uVar10 = 1;
      do {
        bVar11 = param_2[uVar12];
        if (bVar11 - 0x20 < 0x5b) {
          uVar14 = ((uint)bVar11 - ((int)uVar12 + (int)(uVar12 / 10) * -10)) + 0x3b;
          bVar11 = (char)uVar14 + (char)((uVar14 & 0xff) / 0x5b) * -0x5b + 0x20;
        }
        param_2[uVar12] = bVar11;
        sVar8 = strnlen(param_2,0x200);
        bVar1 = uVar10 < sVar8;
        uVar12 = uVar10;
        uVar10 = (ulong)((int)uVar10 + 1);
      } while (bVar1);
    }
    sVar8 = strlen(param_2);
    if (((int)sVar8 != 0) && (*param_2 != '#')) {
      if ((*param_2 == '[') && (param_2[(int)sVar8 + -1] == ']')) break;
      if (*(int *)PTR_DAT_0012d278 == 1) {
        __android_log_print(4,"thermal_core","line: %s\n",param_2);
      }
      iVar5 = strncmp(param_2,"HW_protection",0xd);
      if (iVar5 == 0) {
        cVar3 = *param_2;
        pcVar7 = param_2;
        while (pcVar22 = pcVar7, cVar3 != '\0') {
          if (cVar3 == '=') {
            pcVar22 = pcVar7 + 1;
            *pcVar7 = '\0';
            break;
          }
          pcVar7 = pcVar7 + 1;
          cVar3 = *pcVar7;
        }
        for (; *pcVar22 == ' ' || *pcVar22 == '\t'; pcVar22 = pcVar22 + 1) {
        }
        if (*(int *)PTR_DAT_0012d278 == 1) {
          __android_log_print(4,"thermal_core","par: %s\n",pcVar22);
        }
        iVar5 = strncasecmp(pcVar22,"disabled",8);
        if (iVar5 == 0) {
          local_100[0x28] = '\0';
          local_100[0x29] = '\0';
          local_100[0x2a] = '\0';
          local_100[0x2b] = '\0';
          local_100[0x2c] = '\0';
          local_100[0x2d] = '\0';
          local_100[0x2e] = '\0';
          local_100[0x2f] = '\0';
          local_100[0x20] = '\0';
          local_100[0x21] = '\0';
          local_100[0x22] = '\0';
          local_100[0x23] = '\0';
          local_100[0x24] = '\0';
          local_100[0x25] = '\0';
          local_100[0x26] = '\0';
          local_100[0x27] = '\0';
          local_100[0x38] = '\0';
          local_100[0x39] = '\0';
          local_100[0x3a] = '\0';
          local_100[0x3b] = '\0';
          local_100[0x3c] = '\0';
          local_100[0x3d] = '\0';
          local_100[0x3e] = '\0';
          local_100[0x3f] = '\0';
          local_100[0x30] = '\0';
          local_100[0x31] = '\0';
          local_100[0x32] = '\0';
          local_100[0x33] = '\0';
          local_100[0x34] = '\0';
          local_100[0x35] = '\0';
          local_100[0x36] = '\0';
          local_100[0x37] = '\0';
          local_100[8] = '\0';
          local_100[9] = '\0';
          local_100[10] = '\0';
          local_100[0xb] = '\0';
          local_100[0xc] = '\0';
          local_100[0xd] = '\0';
          local_100[0xe] = '\0';
          local_100[0xf] = '\0';
          local_100[0] = '\0';
          local_100[1] = '\0';
          local_100[2] = '\0';
          local_100[3] = '\0';
          local_100[4] = '\0';
          local_100[5] = '\0';
          local_100[6] = '\0';
          local_100[7] = '\0';
          local_100[0x18] = '\0';
          local_100[0x19] = '\0';
          local_100[0x1a] = '\0';
          local_100[0x1b] = '\0';
          local_100[0x1c] = '\0';
          local_100[0x1d] = '\0';
          local_100[0x1e] = '\0';
          local_100[0x1f] = '\0';
          local_100[0x10] = '\0';
          local_100[0x11] = '\0';
          local_100[0x12] = '\0';
          local_100[0x13] = '\0';
          local_100[0x14] = '\0';
          local_100[0x15] = '\0';
          local_100[0x16] = '\0';
          local_100[0x17] = '\0';
          __android_log_print(4,"thermal_core",&DAT_00105994,"disable_thermal");
          iVar5 = set_hw_reboot(0);
          if (iVar5 == 0) {
            uStack_98 = 0;
            local_a0 = 0;
            uStack_88 = 0;
            local_82 = 0;
            uStack_90 = 0;
            uVar14 = 0xffffffff;
            uStack_b8 = 0;
            local_c0 = 0;
            uStack_a8 = 0;
            uStack_b0 = 0;
            iVar5 = 0;
            do {
              iVar20 = iVar5;
              uVar14 = uVar14 + 1;
              snprintf((char *)&local_c0,0x40,(char *)0x40,"/sys/class/thermal/thermal_zone%d",
                       (ulong)uVar14);
              iVar6 = access((char *)&local_c0,0);
              iVar5 = iVar20 + 1;
            } while (iVar6 == 0);
            if (uVar14 != 0) {
              uVar14 = 0;
              do {
                snprintf(local_100,0x40,(char *)0x40,"/sys/class/thermal/thermal_zone%d/mode",
                         (ulong)uVar14);
                node_write("disabled",local_100);
                uVar14 = uVar14 + 1;
                iVar20 = iVar20 + -1;
              } while (iVar20 != 0);
            }
          }
          else {
            __android_log_print(6,"thermal_core","Failed to disable HW reboot\n");
          }
          DAT_0012e9e4 = 0;
        }
        else {
          uStack_80 = 0;
          uStack_98 = 0;
          local_a0 = 0;
          uStack_88 = 0;
          local_82 = 0;
          uStack_90 = 0;
          uStack_b8 = 0;
          local_c0 = 0;
          uStack_a8 = 0;
          uStack_b0 = 0;
          local_100[8] = '\0';
          local_100[9] = '\0';
          local_100[10] = '\0';
          local_100[0xb] = '\0';
          local_100[0xc] = '\0';
          local_100[0xd] = '\0';
          local_100[0xe] = '\0';
          local_100[0xf] = '\0';
          local_100[0] = '\0';
          local_100[1] = '\0';
          local_100[2] = '\0';
          local_100[3] = '\0';
          local_100[4] = '\0';
          local_100[5] = '\0';
          local_100[6] = '\0';
          local_100[7] = '\0';
          local_100[0x18] = '\0';
          local_100[0x19] = '\0';
          local_100[0x1a] = '\0';
          local_100[0x1b] = '\0';
          local_100[0x1c] = '\0';
          local_100[0x1d] = '\0';
          local_100[0x1e] = '\0';
          local_100[0x1f] = '\0';
          local_100[0x10] = '\0';
          local_100[0x11] = '\0';
          local_100[0x12] = '\0';
          local_100[0x13] = '\0';
          local_100[0x14] = '\0';
          local_100[0x15] = '\0';
          local_100[0x16] = '\0';
          local_100[0x17] = '\0';
          if (DAT_0012ea60 != 0) {
            uVar12 = 0;
            uVar10 = extraout_x1;
            lVar13 = DAT_0012ea68;
            uVar21 = extraout_x17;
            do {
              if ((lVar13 != 0) && (lVar15 = *(long *)(lVar13 + uVar12 * 0x50 + 0x38), lVar15 != 0))
              {
                uVar14 = *(uint *)(lVar13 + uVar12 * 0x50 + 0x34);
                uVar16 = (ulong)uVar14;
                if (uVar14 != 0) {
                  if (uVar14 < 3) {
                    uVar17 = 0;
                    iVar6 = -0x42e50;
LAB_00110998:
                    piVar9 = (int *)(lVar15 + uVar17 * 8 + 4);
                    lVar15 = uVar16 - uVar17;
                    do {
                      iVar5 = iVar6;
                      if ((*piVar9 == 3) && (iVar5 = piVar9[-1], piVar9[-1] <= iVar6)) {
                        iVar5 = iVar6;
                      }
                      iVar6 = iVar5;
                      piVar9 = piVar9 + 2;
                      lVar15 = lVar15 + -1;
                    } while (lVar15 != 0);
                  }
                  else {
                    uVar17 = uVar16 & 0xfffffffe;
                    puVar18 = (uint *)(lVar15 + 8);
                    uVar19 = uVar17;
                    iVar5 = -0x42e50;
                    iVar20 = -0x42e50;
                    do {
                      if (puVar18[-1] == 3) {
                        uVar21 = (ulong)puVar18[-2];
                      }
                      if (puVar18[1] == 3) {
                        uVar10 = (ulong)*puVar18;
                      }
                      iVar6 = (int)uVar21;
                      if ((int)uVar21 <= iVar5 || puVar18[-1] != 3) {
                        iVar6 = iVar5;
                      }
                      iVar2 = (int)uVar10;
                      if ((int)uVar10 <= iVar20 || puVar18[1] != 3) {
                        iVar2 = iVar20;
                      }
                      puVar18 = puVar18 + 4;
                      uVar19 = uVar19 - 2;
                      iVar5 = iVar6;
                      iVar20 = iVar2;
                    } while (uVar19 != 0);
                    if (iVar6 <= iVar2) {
                      iVar6 = iVar2;
                    }
                    if (uVar17 != uVar16) goto LAB_00110998;
                  }
                  if ((iVar6 != -0x42e50) &&
                     (snprintf(local_100,0x20,(char *)0x20,&DAT_00101ff6,(ulong)(iVar6 + 10000)),
                     uVar10 = extraout_x1_00, lVar13 = DAT_0012ea68, uVar21 = extraout_x17_00,
                     *(int *)(DAT_0012ea68 + uVar12 * 0x50 + 0x34) != 0)) {
                    uVar16 = 0;
                    lVar15 = 4;
                    do {
                      if (*(uint *)(*(long *)(lVar13 + uVar12 * 0x50 + 0x38) + lVar15) < 2) {
                        snprintf((char *)&local_c0,0x46,(char *)0x46,
                                 "/sys/class/thermal/thermal_zone%d/trip_point_%d_temp",
                                 uVar12 & 0xffffffff,uVar16 & 0xffffffff);
                        node_write(local_100,&local_c0);
                        uVar10 = extraout_x1_01;
                        lVar13 = DAT_0012ea68;
                        uVar21 = extraout_x17_01;
                      }
                      uVar16 = uVar16 + 1;
                      lVar15 = lVar15 + 8;
                    } while (uVar16 < *(uint *)(lVar13 + uVar12 * 0x50 + 0x34));
                  }
                }
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < DAT_0012ea60);
          }
        }
      }
      local_118 = ftell(param_1);
    }
  }
  if ((int)local_118 < 0) {
    pcVar7 = "Negative file position %s\n";
  }
  else {
    iVar5 = fseek(param_1,local_118 & 0xffffffff,0);
    if (iVar5 != -1) goto LAB_00110b0c;
    pcVar7 = "fseek failed: %s\n";
  }
  piVar9 = (int *)__errno();
  pcVar22 = strerror(*piVar9);
  __android_log_print(6,"thermal_core",pcVar7,pcVar22);
LAB_00110b0c:
  if (*(long *)(lVar4 + 0x28) == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
