/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: backlight_cooler_parser   VMA: 0x19f34   (see reverse/symbols.csv)
 */

void backlight_cooler_parser(FILE *param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  char *pcVar8;
  size_t sVar9;
  long *__ptr;
  void *pvVar10;
  int *piVar11;
  byte bVar12;
  ulong uVar13;
  byte *pbVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  ulong uVar18;
  char *pcVar19;
  long lVar20;
  long lVar21;
  ulong local_448;
  undefined8 local_430 [20];
  ulong local_390;
  undefined8 local_380 [20];
  ulong local_2e0;
  undefined8 local_2d0 [20];
  ulong local_230;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined6 uStack_90;
  undefined2 local_8a;
  undefined6 uStack_88;
  long local_80;
  
  lVar4 = tpidr_el0;
  local_80 = *(long *)(lVar4 + 0x28);
  uVar7 = ftell(param_1);
LAB_00119f94:
  do {
    pcVar8 = fgets(param_2,0x100,param_1);
    if (pcVar8 == (char *)0x0) {
LAB_0011aca0:
      if ((int)uVar7 < 0) {
        piVar11 = (int *)__errno();
        pcVar8 = strerror(*piVar11);
        __android_log_print(6,"thermal_core","Negative file position %s\n",pcVar8);
      }
      else {
        iVar6 = fseek(param_1,uVar7 & 0xffffffff,0);
        if (iVar6 == -1) {
          piVar11 = (int *)__errno();
          pcVar8 = strerror(*piVar11);
          __android_log_print(6,"thermal_core","fseek failed: %s\n",pcVar8);
        }
        if (*(int *)PTR_DAT_0012d278 == 1) {
          __android_log_print(4,"thermal_core","backlight cooler parse done\n");
        }
      }
      if (*(long *)(lVar4 + 0x28) != local_80) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    sVar9 = strlen(param_2);
    uVar15 = (uint)sVar9;
    if (0 < (int)uVar15) {
      uVar13 = sVar9 & 0xffffffff;
      do {
        uVar15 = uVar15 - 1;
        if (0x20 < (byte)param_2[uVar15] ||
            (1L << ((ulong)(byte)param_2[uVar15] & 0x3f) & 0x100002400U) == 0) goto LAB_00119fe8;
        uVar18 = uVar13 - 1;
        bVar1 = 0 < (long)uVar13;
        uVar13 = uVar18;
      } while (uVar18 != 0 && bVar1);
      uVar13 = 0;
LAB_00119fe8:
      param_2[(int)uVar13] = '\0';
    }
    if (param_3 == 2) {
      sVar9 = strnlen(param_2,0x200);
      if (sVar9 != 0) {
        uVar13 = 0;
        uVar18 = 1;
        do {
          bVar12 = param_2[uVar13];
          if (bVar12 - 0x20 < 0x5b) {
            uVar15 = ((uint)bVar12 - ((int)uVar13 + (int)(uVar13 / 5) * -5)) + 0x3b;
            bVar12 = (char)uVar15 + (char)((uVar15 & 0xff) / 0x5b) * -0x5b + 0x20;
          }
          param_2[uVar13] = bVar12;
          sVar9 = strnlen(param_2,0x200);
          bVar1 = uVar18 < sVar9;
          uVar13 = uVar18;
          uVar18 = (ulong)((int)uVar18 + 1);
        } while (bVar1);
      }
    }
    else if ((param_3 == 1) && (sVar9 = strnlen(param_2,0x200), sVar9 != 0)) {
      uVar13 = 0;
      uVar18 = 1;
      do {
        bVar12 = param_2[uVar13];
        if (bVar12 - 0x20 < 0x5b) {
          uVar15 = ((uint)bVar12 - ((int)uVar13 + (int)(uVar13 / 10) * -10)) + 0x3b;
          bVar12 = (char)uVar15 + (char)((uVar15 & 0xff) / 0x5b) * -0x5b + 0x20;
        }
        param_2[uVar13] = bVar12;
        sVar9 = strnlen(param_2,0x200);
        bVar1 = uVar18 < sVar9;
        uVar13 = uVar18;
        uVar18 = (ulong)((int)uVar18 + 1);
      } while (bVar1);
    }
    sVar9 = strlen(param_2);
  } while (((int)sVar9 == 0) || (*param_2 == '#'));
  if ((*param_2 != '[') || (param_2[(int)sVar9 + -1] != ']')) {
    if (*(int *)PTR_DAT_0012d278 == 1) {
      __android_log_print(4,"thermal_core","line: %s\n",param_2);
    }
    iVar6 = strncmp(param_2,"mode",4);
    if (iVar6 == 0) {
      cVar3 = *param_2;
      pcVar8 = param_2;
      while (pcVar19 = pcVar8, cVar3 != '\0') {
        if (cVar3 == '=') {
          pcVar19 = pcVar8 + 1;
          *pcVar8 = '\0';
          break;
        }
        pcVar8 = pcVar8 + 1;
        cVar3 = *pcVar8;
      }
      for (; *pcVar19 == ' ' || *pcVar19 == '\t'; pcVar19 = pcVar19 + 1) {
      }
      if (*(int *)PTR_DAT_0012d278 == 1) {
        __android_log_print(4,"thermal_core","par: %s\n",pcVar19);
      }
      iVar6 = strncasecmp(pcVar19,"disabled",8);
      if (iVar6 != 0) {
        local_448 = 0;
        uVar17 = 0;
        uVar15 = 0;
        local_a0 = 0;
        uStack_98 = 0;
        uStack_88 = 0;
        uStack_90 = 0;
        local_8a = 0;
        uStack_b8 = 0;
        local_c0 = 0;
        uStack_a8 = 0;
        uStack_b0 = 0;
        uStack_d8 = 0;
        local_e0 = 0;
        uStack_c8 = 0;
        uStack_d0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        uStack_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        uStack_110 = 0;
        uStack_138 = 0;
        local_140 = 0;
        uStack_128 = 0;
        uStack_130 = 0;
        uStack_158 = 0;
        local_160 = 0;
        uStack_148 = 0;
        uStack_150 = 0;
        uStack_178 = 0;
        local_180 = 0;
        uStack_168 = 0;
        uStack_170 = 0;
        uStack_198 = 0;
        local_1a0 = 0;
        uStack_188 = 0;
        uStack_190 = 0;
        uStack_1b8 = 0;
        local_1c0 = 0;
        uStack_1a8 = 0;
        uStack_1b0 = 0;
        uStack_1d8 = 0;
        local_1e0 = 0;
        uStack_1c8 = 0;
        uStack_1d0 = 0;
        uStack_1f8 = 0;
        local_200 = 0;
        uStack_1e8 = 0;
        uStack_1f0 = 0;
        uStack_218 = 0;
        local_220 = 0;
        uStack_208 = 0;
        uStack_210 = 0;
        local_2d0[0x11] = 0;
        local_2d0[0x10] = 0;
        local_2d0[0x13] = 0;
        local_2d0[0x12] = 0;
        local_2d0[0xd] = 0;
        local_2d0[0xc] = 0;
        local_2d0[0xf] = 0;
        local_2d0[0xe] = 0;
        local_2d0[9] = 0;
        local_2d0[8] = 0;
        local_2d0[0xb] = 0;
        local_2d0[10] = 0;
        local_2d0[5] = 0;
        local_2d0[4] = 0;
        local_2d0[7] = 0;
        local_2d0[6] = 0;
        local_2d0[1] = 0;
        local_2d0[0] = 0;
        local_2d0[3] = 0;
        local_2d0[2] = 0;
        local_2e0 = 0;
        local_380[0x11] = 0;
        local_380[0x10] = 0;
        local_380[0x13] = 0;
        local_380[0x12] = 0;
        local_380[0xd] = 0;
        local_380[0xc] = 0;
        local_380[0xf] = 0;
        local_380[0xe] = 0;
        local_380[9] = 0;
        local_380[8] = 0;
        local_380[0xb] = 0;
        local_380[10] = 0;
        local_380[5] = 0;
        local_380[4] = 0;
        local_380[7] = 0;
        local_380[6] = 0;
        local_380[1] = 0;
        local_380[0] = 0;
        local_380[3] = 0;
        local_380[2] = 0;
        local_390 = 0;
        local_430[0x11] = 0;
        local_430[0x10] = 0;
        local_430[0x13] = 0;
        local_430[0x12] = 0;
        local_430[0xd] = 0;
        local_430[0xc] = 0;
        local_430[0xf] = 0;
        local_430[0xe] = 0;
        local_430[9] = 0;
        local_430[8] = 0;
        local_430[0xb] = 0;
        local_430[10] = 0;
        local_430[5] = 0;
        local_430[4] = 0;
        local_430[7] = 0;
        local_430[6] = 0;
        local_430[1] = 0;
        local_430[0] = 0;
        local_430[3] = 0;
        local_430[2] = 0;
        local_230 = 0;
LAB_0011a2d0:
        do {
          uVar7 = ftell(param_1);
          do {
            pcVar8 = fgets(param_2,0x100,param_1);
            if (pcVar8 == (char *)0x0) goto LAB_0011a914;
            sVar9 = strlen(param_2);
            uVar16 = (uint)sVar9;
            if (0 < (int)uVar16) {
              uVar13 = sVar9 & 0xffffffff;
              do {
                uVar16 = uVar16 - 1;
                if (0x20 < (byte)param_2[uVar16] ||
                    (1L << ((ulong)(byte)param_2[uVar16] & 0x3f) & 0x100002400U) == 0)
                goto LAB_0011a330;
                uVar18 = uVar13 - 1;
                bVar1 = 0 < (long)uVar13;
                uVar13 = uVar18;
              } while (uVar18 != 0 && bVar1);
              uVar13 = 0;
LAB_0011a330:
              param_2[(int)uVar13] = '\0';
            }
            if (param_3 == 2) {
              sVar9 = strnlen(param_2,0x200);
              if (sVar9 != 0) {
                uVar13 = 0;
                uVar18 = 1;
                do {
                  bVar12 = param_2[uVar13];
                  if (bVar12 - 0x20 < 0x5b) {
                    uVar16 = ((uint)bVar12 - ((int)uVar13 + (int)(uVar13 / 5) * -5)) + 0x3b;
                    bVar12 = (char)uVar16 + (char)((uVar16 & 0xff) / 0x5b) * -0x5b + 0x20;
                  }
                  param_2[uVar13] = bVar12;
                  sVar9 = strnlen(param_2,0x200);
                  bVar1 = uVar18 < sVar9;
                  uVar13 = uVar18;
                  uVar18 = (ulong)((int)uVar18 + 1);
                } while (bVar1);
              }
            }
            else if ((param_3 == 1) && (sVar9 = strnlen(param_2,0x200), sVar9 != 0)) {
              uVar13 = 0;
              uVar18 = 1;
              do {
                bVar12 = param_2[uVar13];
                if (bVar12 - 0x20 < 0x5b) {
                  uVar16 = ((uint)bVar12 - ((int)uVar13 + (int)(uVar13 / 10) * -10)) + 0x3b;
                  bVar12 = (char)uVar16 + (char)((uVar16 & 0xff) / 0x5b) * -0x5b + 0x20;
                }
                param_2[uVar13] = bVar12;
                sVar9 = strnlen(param_2,0x200);
                bVar1 = uVar18 < sVar9;
                uVar13 = uVar18;
                uVar18 = (ulong)((int)uVar18 + 1);
              } while (bVar1);
            }
            sVar9 = strlen(param_2);
          } while (((int)sVar9 == 0) || (*param_2 == '#'));
          if ((*param_2 == '[') && (param_2[(int)sVar9 + -1] == ']')) goto LAB_0011a914;
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","line: %s\n",param_2);
          }
          iVar6 = strncmp(param_2,"sensor",6);
          if (iVar6 == 0) {
            cVar3 = *param_2;
            pcVar8 = param_2;
            while (pcVar19 = pcVar8, cVar3 != '\0') {
              if (cVar3 == '=') {
                pcVar19 = pcVar8 + 1;
                *pcVar8 = '\0';
                break;
              }
              pcVar8 = pcVar8 + 1;
              cVar3 = *pcVar8;
            }
            for (; *pcVar19 == ' ' || *pcVar19 == '\t'; pcVar19 = pcVar19 + 1) {
            }
            snprintf((char *)&local_a0,0x1e,(char *)0x1e,&DAT_00102ab3);
          }
          else {
            iVar6 = strncmp(param_2,"threshold",9);
            if (iVar6 == 0) {
              cVar3 = *param_2;
              pcVar8 = param_2;
              while (pcVar19 = pcVar8, cVar3 != '\0') {
                if (cVar3 == '=') {
                  pcVar19 = pcVar8 + 1;
                  *pcVar8 = '\0';
                  break;
                }
                pcVar8 = pcVar8 + 1;
                cVar3 = *pcVar8;
              }
              pcVar8 = param_2 + (sVar9 - (long)pcVar19);
              for (; iVar6 = (int)pcVar8, *pcVar19 == ' ' || *pcVar19 == '\t'; pcVar19 = pcVar19 + 1
                  ) {
                pcVar8 = pcVar8 + -1;
              }
              if (0x80 < iVar6) {
                __android_log_print(6,"thermal_core","Threshold list overflow\n");
                iVar6 = 0x80;
              }
              __memcpy_chk(&local_120,pcVar19,(long)iVar6,0x80);
              if ((byte)local_120 == 0x5b) {
                uVar15 = 0;
                pbVar14 = (byte *)&local_120;
                bVar1 = true;
                bVar12 = 0x5b;
                local_230 = local_230 & 0xffffffff00000000;
                do {
                  while (bVar12 < 0x5b) {
                    if (bVar12 != 0x2c) {
                      if (bVar12 != 0) goto LAB_0011a6b4;
                      goto LAB_0011a2d0;
                    }
                    bVar1 = true;
LAB_0011a688:
                    *pbVar14 = 0;
LAB_0011a68c:
                    pbVar14 = pbVar14 + 1;
                    bVar12 = *pbVar14;
                  }
                  if ((bVar12 == 0x5d) || (bVar12 == 0x5b)) goto LAB_0011a688;
LAB_0011a6b4:
                  if ((bVar12 == 0x20) || (!bVar1)) goto LAB_0011a68c;
                  if (0x13 < uVar15) goto LAB_0011a8e0;
                  local_2d0[uVar15] = pbVar14;
                  uVar15 = (int)local_230 + 1;
                  bVar1 = false;
                  local_230 = CONCAT44(local_230._4_4_,uVar15);
                  pbVar14 = pbVar14 + 1;
                  bVar12 = *pbVar14;
                } while( true );
              }
            }
            else {
              iVar6 = strncmp(param_2,"hysteresis",10);
              if (iVar6 == 0) {
                cVar3 = *param_2;
                pcVar8 = param_2;
                while (pcVar19 = pcVar8, cVar3 != '\0') {
                  if (cVar3 == '=') {
                    pcVar19 = pcVar8 + 1;
                    *pcVar8 = '\0';
                    break;
                  }
                  pcVar8 = pcVar8 + 1;
                  cVar3 = *pcVar8;
                }
                pcVar8 = param_2 + (sVar9 - (long)pcVar19);
                for (; iVar6 = (int)pcVar8, *pcVar19 == ' ' || *pcVar19 == '\t';
                    pcVar19 = pcVar19 + 1) {
                  pcVar8 = pcVar8 + -1;
                }
                if (0x80 < iVar6) {
                  __android_log_print(6,"thermal_core","Hysteresis list overflow\n");
                  iVar6 = 0x80;
                }
                __memcpy_chk(&local_1a0,pcVar19,(long)iVar6,0x80);
                if ((byte)local_1a0 == 0x5b) {
                  uVar17 = 0;
                  pbVar14 = (byte *)&local_1a0;
                  bVar1 = true;
                  bVar12 = 0x5b;
                  local_2e0 = local_2e0 & 0xffffffff00000000;
                  do {
                    while (bVar12 < 0x5b) {
                      if (bVar12 != 0x2c) {
                        if (bVar12 != 0) goto LAB_0011a7a8;
                        goto LAB_0011a2d0;
                      }
                      bVar1 = true;
LAB_0011a77c:
                      *pbVar14 = 0;
LAB_0011a780:
                      pbVar14 = pbVar14 + 1;
                      bVar12 = *pbVar14;
                    }
                    if ((bVar12 == 0x5d) || (bVar12 == 0x5b)) goto LAB_0011a77c;
LAB_0011a7a8:
                    if ((bVar12 == 0x20) || (!bVar1)) goto LAB_0011a780;
                    if (0x13 < uVar17) goto LAB_0011a8e0;
                    local_380[uVar17] = pbVar14;
                    uVar17 = (int)local_2e0 + 1;
                    bVar1 = false;
                    local_2e0 = CONCAT44(local_2e0._4_4_,uVar17);
                    pbVar14 = pbVar14 + 1;
                    bVar12 = *pbVar14;
                  } while( true );
                }
              }
              else {
                iVar6 = strncmp(param_2,"reduce-brightness",0x11);
                if (iVar6 == 0) {
                  cVar3 = *param_2;
                  pcVar8 = param_2;
                  while (pcVar19 = pcVar8, cVar3 != '\0') {
                    if (cVar3 == '=') {
                      pcVar19 = pcVar8 + 1;
                      *pcVar8 = '\0';
                      break;
                    }
                    pcVar8 = pcVar8 + 1;
                    cVar3 = *pcVar8;
                  }
                  pcVar8 = param_2 + (sVar9 - (long)pcVar19);
                  for (; iVar6 = (int)pcVar8, *pcVar19 == ' ' || *pcVar19 == '\t';
                      pcVar19 = pcVar19 + 1) {
                    pcVar8 = pcVar8 + -1;
                  }
                  if (0x80 < iVar6) {
                    __android_log_print(6,"thermal_core","Current list overflow\n");
                    iVar6 = 0x80;
                  }
                  __memcpy_chk(&local_220,pcVar19,(long)iVar6,0x80);
                  if ((byte)local_220 == 0x5b) {
                    local_448 = 0;
                    pbVar14 = (byte *)&local_220;
                    bVar1 = true;
                    bVar12 = 0x5b;
                    local_390 = local_390 & 0xffffffff00000000;
                    do {
                      while (bVar12 < 0x5b) {
                        if (bVar12 != 0x2c) {
                          if (bVar12 != 0) goto LAB_0011a89c;
                          goto LAB_0011a2d0;
                        }
                        bVar1 = true;
LAB_0011a870:
                        *pbVar14 = 0;
LAB_0011a874:
                        pbVar14 = pbVar14 + 1;
                        bVar12 = *pbVar14;
                      }
                      if ((bVar12 == 0x5d) || (bVar12 == 0x5b)) goto LAB_0011a870;
LAB_0011a89c:
                      if ((bVar12 == 0x20) || (!bVar1)) goto LAB_0011a874;
                      if (0x13 < (uint)local_448) goto LAB_0011a8e0;
                      local_430[local_448] = pbVar14;
                      local_448 = (ulong)((int)local_390 + 1U);
                      bVar1 = false;
                      local_390 = CONCAT44(local_390._4_4_,(int)local_390 + 1U);
                      pbVar14 = pbVar14 + 1;
                      bVar12 = *pbVar14;
                    } while( true );
                  }
                }
              }
            }
          }
        } while( true );
      }
      pthread_mutex_lock((pthread_mutex_t *)&DAT_0012e8f8);
      for (lVar20 = DAT_0012e920; lVar20 != 0; lVar20 = *(long *)(lVar20 + 0x28)) {
        iVar6 = strncmp(*(char **)(lVar20 + 8),"backlight_cooler",0x10);
        if (iVar6 == 0) {
          *(undefined4 *)(lVar20 + 0x1c) = 1;
        }
      }
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e8f8);
    }
    goto LAB_0011a19c;
  }
  goto LAB_0011aca0;
LAB_0011a914:
  uVar16 = (uint)local_448;
  if (((uVar17 == uVar16) && (uVar15 != 0)) && (uVar15 == uVar17)) {
    __ptr = malloc(0x40);
    uVar13 = -(local_448 >> 0x1f) & 0xfffffffc00000000 | local_448 << 2;
    *(uint *)(__ptr + 4) = uVar16;
    pvVar10 = malloc(uVar13);
    *__ptr = (long)pvVar10;
    pvVar10 = malloc(uVar13);
    __ptr[1] = (long)pvVar10;
    pvVar10 = malloc(uVar13);
    pcVar8 = DAT_0012ea80;
    __ptr[2] = (long)pvVar10;
    if (pcVar8 == (char *)0x0) {
      lVar20 = 0xffffffff;
    }
    else {
      uVar13 = (ulong)DAT_0012ea78;
      if (DAT_0012ea78 == 0) {
LAB_0011aa38:
        __android_log_print(6,"thermal_core","Failed to find cooling device index of %s\n",
                            "lcd-backlight");
        lVar20 = 0xffffffff;
      }
      else {
        iVar6 = strncmp(pcVar8,"lcd-backlight",0xd);
        if (iVar6 == 0) {
          lVar20 = 0;
        }
        else {
          lVar20 = 0;
          if (uVar13 < 2) {
            uVar13 = 1;
          }
          do {
            pcVar8 = pcVar8 + 0x18;
            if (uVar13 - 1 == lVar20) goto LAB_0011aa38;
            lVar20 = lVar20 + 1;
            iVar6 = strncmp(pcVar8,"lcd-backlight",0xd);
          } while (iVar6 != 0);
        }
      }
    }
    lVar21 = 0;
    uVar13 = 0;
    *(int *)((long)__ptr + 0x24) = (int)lVar20;
    if (uVar16 < 2) {
      uVar16 = 1;
    }
    *(undefined4 *)(__ptr + 6) = 0;
    __ptr[5] = 0x7fffffff7fffffff;
    do {
      sscanf((char *)local_2d0[uVar13],"%d",*__ptr + lVar21);
      sscanf((char *)local_380[uVar13],"%d",__ptr[1] + lVar21);
      sscanf((char *)local_430[uVar13],"%d",__ptr[2] + lVar21);
      iVar6 = *(int *)(*__ptr + uVar13 * 4);
      iVar2 = *(int *)(__ptr[1] + uVar13 * 4);
      if (*(int *)PTR_DAT_0012d278 == 1) {
        __android_log_print(4,"thermal_core",
                            "backlight, Table i= %d, th %d, hy %d, reduce_b %d, cl_idx %d\n",
                            uVar13 & 0xffffffff,iVar6,iVar2,*(undefined4 *)(__ptr[2] + uVar13 * 4),
                            *(undefined4 *)((long)__ptr + 0x24));
      }
      iVar2 = iVar6 - iVar2;
      iVar5 = (int)__ptr[5];
      if (iVar6 < (int)__ptr[5]) {
        *(int *)(__ptr + 5) = iVar6;
        iVar5 = iVar6;
      }
      iVar6 = *(int *)((long)__ptr + 0x2c);
      if (iVar2 < *(int *)((long)__ptr + 0x2c)) {
        *(int *)((long)__ptr + 0x2c) = iVar2;
        iVar6 = iVar2;
      }
      uVar13 = uVar13 + 1;
      lVar21 = lVar21 + 4;
    } while (uVar16 != uVar13);
    pcVar8 = DAT_0012e9e8;
    if (*(int *)PTR_DAT_0012d278 == 1) {
      __android_log_print(4,"thermal_core","min_th %d, min_exit %d\n",iVar5,iVar6);
      pcVar8 = DAT_0012e9e8;
    }
    for (; pcVar8 != (char *)0x0; pcVar8 = *(char **)(pcVar8 + 0x30)) {
      iVar6 = strncmp(pcVar8,"backlight_cooler",0x10);
      if (iVar6 == 0) {
        (**(code **)(pcVar8 + 0x18))(__ptr);
        add_thermal_instance(&local_a0,"backlight_cooler",0,0,1);
        goto joined_r0x0011ac68;
      }
    }
    __android_log_print(6,"thermal_core","Error: Cooler backlight_cooler not found\n");
    free((void *)*__ptr);
    free((void *)__ptr[1]);
    free((void *)__ptr[2]);
    free(__ptr);
  }
joined_r0x0011ac68:
  if ((int)uVar7 < 0) {
    pcVar8 = "Negative file position %s\n";
  }
  else {
    iVar6 = fseek(param_1,uVar7 & 0xffffffff,0);
    if (iVar6 != -1) goto LAB_0011a19c;
    pcVar8 = "fseek failed: %s\n";
  }
  piVar11 = (int *)__errno();
  pcVar19 = strerror(*piVar11);
  __android_log_print(6,"thermal_core",pcVar8,pcVar19);
LAB_0011a19c:
  uVar7 = ftell(param_1);
  goto LAB_00119f94;
LAB_0011a8e0:
  if (*(int *)PTR_DAT_0012d278 == 1) {
    __android_log_print(4,"thermal_core","List items are more than MAX_NUM_PTRS %d\n",0x14);
  }
  goto LAB_0011a2d0;
}
