/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: cpu_table_mapping_parser   VMA: 0x15a70   (see reverse/symbols.csv)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cpu_table_mapping_parser(FILE *param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  ulong uVar9;
  char *pcVar10;
  size_t sVar11;
  undefined4 *__ptr;
  void *pvVar12;
  int *piVar13;
  byte bVar14;
  ulong uVar15;
  byte *pbVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  char *pcVar20;
  long lVar21;
  ulong uVar22;
  ulong local_440;
  undefined4 local_434;
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
  undefined8 local_98;
  undefined8 local_90;
  undefined6 uStack_88;
  undefined2 local_82;
  undefined6 uStack_80;
  long local_78;
  
  lVar4 = tpidr_el0;
  local_78 = *(long *)(lVar4 + 0x28);
  uVar9 = ftell(param_1);
  uVar7 = _UNK_00101f48;
  uVar6 = _DAT_00101f40;
LAB_00115ad4:
  while (pcVar10 = fgets(param_2,0x100,param_1), pcVar10 != (char *)0x0) {
    sVar11 = strlen(param_2);
    uVar17 = (uint)sVar11;
    if (0 < (int)uVar17) {
      uVar15 = sVar11 & 0xffffffff;
      do {
        uVar17 = uVar17 - 1;
        if (0x20 < (byte)param_2[uVar17] ||
            (1L << ((ulong)(byte)param_2[uVar17] & 0x3f) & 0x100002400U) == 0) goto LAB_00115b28;
        uVar22 = uVar15 - 1;
        bVar1 = 0 < (long)uVar15;
        uVar15 = uVar22;
      } while (uVar22 != 0 && bVar1);
      uVar15 = 0;
LAB_00115b28:
      param_2[(int)uVar15] = '\0';
    }
    if (param_3 == 2) {
      sVar11 = strnlen(param_2,0x200);
      if (sVar11 != 0) {
        uVar15 = 0;
        uVar22 = 1;
        do {
          bVar14 = param_2[uVar15];
          if (bVar14 - 0x20 < 0x5b) {
            uVar17 = ((uint)bVar14 - ((int)uVar15 + (int)(uVar15 / 5) * -5)) + 0x3b;
            bVar14 = (char)uVar17 + (char)((uVar17 & 0xff) / 0x5b) * -0x5b + 0x20;
          }
          param_2[uVar15] = bVar14;
          sVar11 = strnlen(param_2,0x200);
          bVar1 = uVar22 < sVar11;
          uVar15 = uVar22;
          uVar22 = (ulong)((int)uVar22 + 1);
        } while (bVar1);
      }
    }
    else if ((param_3 == 1) && (sVar11 = strnlen(param_2,0x200), sVar11 != 0)) {
      uVar15 = 0;
      uVar22 = 1;
      do {
        bVar14 = param_2[uVar15];
        if (bVar14 - 0x20 < 0x5b) {
          uVar17 = ((uint)bVar14 - ((int)uVar15 + (int)(uVar15 / 10) * -10)) + 0x3b;
          bVar14 = (char)uVar17 + (char)((uVar17 & 0xff) / 0x5b) * -0x5b + 0x20;
        }
        param_2[uVar15] = bVar14;
        sVar11 = strnlen(param_2,0x200);
        bVar1 = uVar22 < sVar11;
        uVar15 = uVar22;
        uVar22 = (ulong)((int)uVar22 + 1);
      } while (bVar1);
    }
    sVar11 = strlen(param_2);
    if (((int)sVar11 != 0) && (*param_2 != '#')) {
      if ((*param_2 != '[') || (param_2[(int)sVar11 + -1] != ']')) {
        if (*(int *)PTR_DAT_0012d278 == 1) {
          __android_log_print(4,"thermal_core","line: %s\n",param_2);
        }
        iVar8 = strncmp(param_2,"mode",4);
        if (iVar8 == 0) {
          cVar3 = *param_2;
          pcVar10 = param_2;
          while (pcVar20 = pcVar10, cVar3 != '\0') {
            if (cVar3 == '=') {
              pcVar20 = pcVar10 + 1;
              *pcVar10 = '\0';
              break;
            }
            pcVar10 = pcVar10 + 1;
            cVar3 = *pcVar10;
          }
          for (; *pcVar20 == ' ' || *pcVar20 == '\t'; pcVar20 = pcVar20 + 1) {
          }
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","par: %s\n",pcVar20);
          }
          iVar8 = strncasecmp(pcVar20,"disabled",8);
          if (iVar8 != 0) {
            local_440 = 0;
            uVar19 = 0;
            uVar17 = 0;
            local_434 = 0;
            local_90 = 0;
            local_98 = 0;
            uStack_80 = 0;
            uStack_88 = 0;
            local_82 = 0;
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
LAB_00115e1c:
            do {
              uVar9 = ftell(param_1);
              do {
                pcVar10 = fgets(param_2,0x100,param_1);
                if (pcVar10 == (char *)0x0) goto LAB_001164dc;
                sVar11 = strlen(param_2);
                uVar18 = (uint)sVar11;
                if (0 < (int)uVar18) {
                  uVar15 = sVar11 & 0xffffffff;
                  do {
                    uVar18 = uVar18 - 1;
                    if (0x20 < (byte)param_2[uVar18] ||
                        (1L << ((ulong)(byte)param_2[uVar18] & 0x3f) & 0x100002400U) == 0)
                    goto LAB_00115e7c;
                    uVar22 = uVar15 - 1;
                    bVar1 = 0 < (long)uVar15;
                    uVar15 = uVar22;
                  } while (uVar22 != 0 && bVar1);
                  uVar15 = 0;
LAB_00115e7c:
                  param_2[(int)uVar15] = '\0';
                }
                if (param_3 == 2) {
                  sVar11 = strnlen(param_2,0x200);
                  if (sVar11 != 0) {
                    uVar15 = 0;
                    uVar22 = 1;
                    do {
                      bVar14 = param_2[uVar15];
                      if (bVar14 - 0x20 < 0x5b) {
                        uVar18 = ((uint)bVar14 - ((int)uVar15 + (int)(uVar15 / 5) * -5)) + 0x3b;
                        bVar14 = (char)uVar18 + (char)((uVar18 & 0xff) / 0x5b) * -0x5b + 0x20;
                      }
                      param_2[uVar15] = bVar14;
                      sVar11 = strnlen(param_2,0x200);
                      bVar1 = uVar22 < sVar11;
                      uVar15 = uVar22;
                      uVar22 = (ulong)((int)uVar22 + 1);
                    } while (bVar1);
                  }
                }
                else if ((param_3 == 1) && (sVar11 = strnlen(param_2,0x200), sVar11 != 0)) {
                  uVar15 = 0;
                  uVar22 = 1;
                  do {
                    bVar14 = param_2[uVar15];
                    if (bVar14 - 0x20 < 0x5b) {
                      uVar18 = ((uint)bVar14 - ((int)uVar15 + (int)(uVar15 / 10) * -10)) + 0x3b;
                      bVar14 = (char)uVar18 + (char)((uVar18 & 0xff) / 0x5b) * -0x5b + 0x20;
                    }
                    param_2[uVar15] = bVar14;
                    sVar11 = strnlen(param_2,0x200);
                    bVar1 = uVar22 < sVar11;
                    uVar15 = uVar22;
                    uVar22 = (ulong)((int)uVar22 + 1);
                  } while (bVar1);
                }
                sVar11 = strlen(param_2);
              } while (((int)sVar11 == 0) || (*param_2 == '#'));
              if ((*param_2 == '[') && (param_2[(int)sVar11 + -1] == ']')) goto LAB_001164dc;
              if (*(int *)PTR_DAT_0012d278 == 1) {
                __android_log_print(4,"thermal_core","line: %s\n",param_2);
              }
              iVar8 = strncmp(param_2,"sensor",6);
              if (iVar8 == 0) {
                cVar3 = *param_2;
                pcVar10 = param_2;
                while (pcVar20 = pcVar10, cVar3 != '\0') {
                  if (cVar3 == '=') {
                    pcVar20 = pcVar10 + 1;
                    *pcVar10 = '\0';
                    break;
                  }
                  pcVar10 = pcVar10 + 1;
                  cVar3 = *pcVar10;
                }
                for (; *pcVar20 == ' ' || *pcVar20 == '\t'; pcVar20 = pcVar20 + 1) {
                }
                snprintf((char *)&local_98,0x1e,(char *)0x1e,&DAT_00102ab3);
              }
              else {
                iVar8 = strncmp(param_2,"cluster",7);
                if (iVar8 == 0) {
                  cVar3 = *param_2;
                  pcVar10 = param_2;
                  while (pcVar20 = pcVar10, cVar3 != '\0') {
                    if (cVar3 == '=') {
                      pcVar20 = pcVar10 + 1;
                      *pcVar10 = '\0';
                      break;
                    }
                    pcVar10 = pcVar10 + 1;
                    cVar3 = *pcVar10;
                  }
                  for (; *pcVar20 == ' ' || *pcVar20 == '\t'; pcVar20 = pcVar20 + 1) {
                  }
                  sscanf(pcVar20,"%d",&local_434);
                }
                else {
                  iVar8 = strncmp(param_2,"threshold",9);
                  if (iVar8 == 0) {
                    cVar3 = *param_2;
                    pcVar10 = param_2;
                    while (pcVar20 = pcVar10, cVar3 != '\0') {
                      if (cVar3 == '=') {
                        pcVar20 = pcVar10 + 1;
                        *pcVar10 = '\0';
                        break;
                      }
                      pcVar10 = pcVar10 + 1;
                      cVar3 = *pcVar10;
                    }
                    pcVar10 = param_2 + (sVar11 - (long)pcVar20);
                    for (; iVar8 = (int)pcVar10, *pcVar20 == ' ' || *pcVar20 == '\t';
                        pcVar20 = pcVar20 + 1) {
                      pcVar10 = pcVar10 + -1;
                    }
                    if (0x80 < iVar8) {
                      __android_log_print(6,"thermal_core","Threshold list overflow\n");
                      iVar8 = 0x80;
                    }
                    __memcpy_chk(&local_120,pcVar20,(long)iVar8,0x80);
                    if ((byte)local_120 == 0x5b) {
                      uVar17 = 0;
                      pbVar16 = (byte *)&local_120;
                      bVar1 = true;
                      bVar14 = 0x5b;
                      local_230 = local_230 & 0xffffffff00000000;
                      do {
                        while (bVar14 < 0x5b) {
                          if (bVar14 != 0x2c) {
                            if (bVar14 != 0) goto LAB_0011626c;
                            goto LAB_00115e1c;
                          }
                          bVar1 = true;
LAB_00116240:
                          *pbVar16 = 0;
LAB_00116244:
                          pbVar16 = pbVar16 + 1;
                          bVar14 = *pbVar16;
                        }
                        if ((bVar14 == 0x5d) || (bVar14 == 0x5b)) goto LAB_00116240;
LAB_0011626c:
                        if ((bVar14 == 0x20) || (!bVar1)) goto LAB_00116244;
                        if (0x13 < uVar17) goto LAB_001164a8;
                        local_2d0[uVar17] = pbVar16;
                        uVar17 = (int)local_230 + 1;
                        bVar1 = false;
                        local_230 = CONCAT44(local_230._4_4_,uVar17);
                        pbVar16 = pbVar16 + 1;
                        bVar14 = *pbVar16;
                      } while( true );
                    }
                  }
                  else {
                    iVar8 = strncmp(param_2,"hysteresis",10);
                    if (iVar8 == 0) {
                      cVar3 = *param_2;
                      pcVar10 = param_2;
                      while (pcVar20 = pcVar10, cVar3 != '\0') {
                        if (cVar3 == '=') {
                          pcVar20 = pcVar10 + 1;
                          *pcVar10 = '\0';
                          break;
                        }
                        pcVar10 = pcVar10 + 1;
                        cVar3 = *pcVar10;
                      }
                      pcVar10 = param_2 + (sVar11 - (long)pcVar20);
                      for (; iVar8 = (int)pcVar10, *pcVar20 == ' ' || *pcVar20 == '\t';
                          pcVar20 = pcVar20 + 1) {
                        pcVar10 = pcVar10 + -1;
                      }
                      if (0x80 < iVar8) {
                        __android_log_print(6,"thermal_core","Hysteresis list overflow\n");
                        iVar8 = 0x80;
                      }
                      __memcpy_chk(&local_1a0,pcVar20,(long)iVar8,0x80);
                      if ((byte)local_1a0 == 0x5b) {
                        uVar19 = 0;
                        pbVar16 = (byte *)&local_1a0;
                        bVar1 = true;
                        bVar14 = 0x5b;
                        local_2e0 = local_2e0 & 0xffffffff00000000;
                        do {
                          while (bVar14 < 0x5b) {
                            if (bVar14 != 0x2c) {
                              if (bVar14 != 0) goto LAB_00116360;
                              goto LAB_00115e1c;
                            }
                            bVar1 = true;
LAB_00116334:
                            *pbVar16 = 0;
LAB_00116338:
                            pbVar16 = pbVar16 + 1;
                            bVar14 = *pbVar16;
                          }
                          if ((bVar14 == 0x5d) || (bVar14 == 0x5b)) goto LAB_00116334;
LAB_00116360:
                          if ((bVar14 == 0x20) || (!bVar1)) goto LAB_00116338;
                          if (0x13 < uVar19) goto LAB_001164a8;
                          local_380[uVar19] = pbVar16;
                          uVar19 = (int)local_2e0 + 1;
                          bVar1 = false;
                          local_2e0 = CONCAT44(local_2e0._4_4_,uVar19);
                          pbVar16 = pbVar16 + 1;
                          bVar14 = *pbVar16;
                        } while( true );
                      }
                    }
                    else {
                      iVar8 = strncmp(param_2,"freq",4);
                      if (iVar8 == 0) {
                        cVar3 = *param_2;
                        pcVar10 = param_2;
                        while (pcVar20 = pcVar10, cVar3 != '\0') {
                          if (cVar3 == '=') {
                            pcVar20 = pcVar10 + 1;
                            *pcVar10 = '\0';
                            break;
                          }
                          pcVar10 = pcVar10 + 1;
                          cVar3 = *pcVar10;
                        }
                        pcVar10 = param_2 + (sVar11 - (long)pcVar20);
                        for (; iVar8 = (int)pcVar10, *pcVar20 == ' ' || *pcVar20 == '\t';
                            pcVar20 = pcVar20 + 1) {
                          pcVar10 = pcVar10 + -1;
                        }
                        if (0x80 < iVar8) {
                          __android_log_print(6,"thermal_core","Hysteresis list overflow\n");
                          iVar8 = 0x80;
                        }
                        __memcpy_chk(&local_220,pcVar20,(long)iVar8,0x80);
                        if ((byte)local_220 == 0x5b) {
                          local_440 = 0;
                          pbVar16 = (byte *)&local_220;
                          bVar1 = true;
                          bVar14 = 0x5b;
                          local_390 = local_390 & 0xffffffff00000000;
                          do {
                            while (bVar14 < 0x5b) {
                              if (bVar14 != 0x2c) {
                                if (bVar14 != 0) goto LAB_0011645c;
                                goto LAB_00115e1c;
                              }
                              bVar1 = true;
LAB_00116430:
                              *pbVar16 = 0;
LAB_00116434:
                              pbVar16 = pbVar16 + 1;
                              bVar14 = *pbVar16;
                            }
                            if ((bVar14 == 0x5d) || (bVar14 == 0x5b)) goto LAB_00116430;
LAB_0011645c:
                            if ((bVar14 == 0x20) || (!bVar1)) goto LAB_00116434;
                            if (0x13 < (uint)local_440) goto LAB_001164a8;
                            local_430[local_440] = pbVar16;
                            local_440 = (ulong)((int)local_390 + 1U);
                            bVar1 = false;
                            local_390 = CONCAT44(local_390._4_4_,(int)local_390 + 1U);
                            pbVar16 = pbVar16 + 1;
                            bVar14 = *pbVar16;
                          } while( true );
                        }
                      }
                    }
                  }
                }
              }
            } while( true );
          }
          pthread_mutex_lock((pthread_mutex_t *)&DAT_0012e8f8);
          for (lVar21 = DAT_0012e920; lVar21 != 0; lVar21 = *(long *)(lVar21 + 0x28)) {
            iVar8 = strncmp(*(char **)(lVar21 + 8),"cpu_table_mapping",0x11);
            if (iVar8 == 0) {
              *(undefined4 *)(lVar21 + 0x1c) = 1;
            }
          }
          pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e8f8);
        }
        goto LAB_00115cdc;
      }
      break;
    }
  }
  if ((int)uVar9 < 0) {
    pcVar10 = "Negative file position %s\n";
  }
  else {
    iVar8 = fseek(param_1,uVar9 & 0xffffffff,0);
    if (iVar8 != -1) goto LAB_001168dc;
    pcVar10 = "fseek failed: %s\n";
  }
  piVar13 = (int *)__errno();
  pcVar20 = strerror(*piVar13);
  __android_log_print(6,"thermal_core",pcVar10,pcVar20);
LAB_001168dc:
  if (*(long *)(lVar4 + 0x28) != local_78) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001164dc:
  uVar18 = (uint)local_440;
  if (((uVar19 == uVar18) && (uVar17 != 0)) && (uVar17 == uVar19)) {
    __ptr = malloc(0x40);
    uVar15 = -(local_440 >> 0x1f) & 0xfffffffc00000000 | local_440 << 2;
    __ptr[1] = local_434;
    __ptr[10] = uVar18;
    pvVar12 = malloc(uVar15);
    *(void **)(__ptr + 2) = pvVar12;
    pvVar12 = malloc(uVar15);
    *(void **)(__ptr + 4) = pvVar12;
    pvVar12 = malloc(uVar15);
    lVar21 = DAT_0012ea68;
    *(void **)(__ptr + 6) = pvVar12;
    *(undefined8 *)(__ptr + 0xd) = uVar7;
    *(undefined8 *)(__ptr + 0xb) = uVar6;
    if (lVar21 == 0) {
      uVar15 = 0xffffffff;
    }
    else if (DAT_0012ea60 == 0) {
LAB_00116630:
      __android_log_print(6,"thermal_core","Failed to find thermal zone index of %s\n",&local_98);
      uVar15 = 0xffffffff;
    }
    else {
      sVar11 = __strlen_chk(&local_98,0x1e);
      iVar8 = strncmp((char *)(lVar21 + 4),(char *)&local_98,sVar11);
      if (iVar8 == 0) {
        uVar15 = 0;
      }
      else {
        uVar15 = 0;
        lVar21 = 0x54;
        do {
          uVar15 = uVar15 + 1;
          if (DAT_0012ea60 <= uVar15) goto LAB_00116630;
          pcVar10 = (char *)(DAT_0012ea68 + lVar21);
          sVar11 = __strlen_chk(&local_98,0x1e);
          iVar8 = strncmp(pcVar10,(char *)&local_98,sVar11);
          lVar21 = lVar21 + 0x50;
        } while (iVar8 != 0);
      }
    }
    lVar21 = 0;
    uVar22 = 0;
    if (uVar18 < 2) {
      uVar18 = 1;
    }
    *__ptr = (int)uVar15;
    do {
      sscanf((char *)local_2d0[uVar22],"%d",*(long *)(__ptr + 2) + lVar21);
      sscanf((char *)local_380[uVar22],"%d",*(long *)(__ptr + 4) + lVar21);
      sscanf((char *)local_430[uVar22],"%d",*(long *)(__ptr + 6) + lVar21);
      iVar8 = *(int *)(*(long *)(__ptr + 2) + uVar22 * 4);
      iVar2 = *(int *)(*(long *)(__ptr + 4) + uVar22 * 4);
      if (*(int *)PTR_DAT_0012d278 == 1) {
        __android_log_print(4,"thermal_core","cluster %d, Table i= %d, th %d, hy %d, freq %d\n",
                            local_434,uVar22 & 0xffffffff,iVar8,iVar2,
                            *(undefined4 *)(*(long *)(__ptr + 6) + uVar22 * 4));
      }
      iVar2 = iVar8 - iVar2;
      iVar5 = __ptr[0xb];
      if (iVar8 < (int)__ptr[0xb]) {
        __ptr[0xb] = iVar8;
        iVar5 = iVar8;
      }
      iVar8 = __ptr[0xc];
      if (iVar2 < (int)__ptr[0xc]) {
        __ptr[0xc] = iVar2;
        iVar8 = iVar2;
      }
      uVar22 = uVar22 + 1;
      lVar21 = lVar21 + 4;
    } while (uVar18 != uVar22);
    pcVar10 = DAT_0012e9e8;
    if (*(int *)PTR_DAT_0012d278 == 1) {
      __android_log_print(4,"thermal_core","min_th %d, min_exit %d\n",iVar5,iVar8);
      pcVar10 = DAT_0012e9e8;
    }
    for (; pcVar10 != (char *)0x0; pcVar10 = *(char **)(pcVar10 + 0x30)) {
      iVar8 = strncmp(pcVar10,"cpu_table_mapping",0x11);
      if (iVar8 == 0) {
        (**(code **)(pcVar10 + 0x18))(__ptr);
        add_thermal_instance(&local_98,"cpu_table_mapping",0,0,1);
        goto joined_r0x00116854;
      }
    }
    __android_log_print(6,"thermal_core","Error: Cooler cpu_table_mapping not found\n");
    free(*(void **)(__ptr + 2));
    free(*(void **)(__ptr + 4));
    free(*(void **)(__ptr + 6));
    free(__ptr);
  }
joined_r0x00116854:
  if ((int)uVar9 < 0) {
    pcVar10 = "Negative file position %s\n";
  }
  else {
    iVar8 = fseek(param_1,uVar9 & 0xffffffff,0);
    if (iVar8 != -1) goto LAB_00115cdc;
    pcVar10 = "fseek failed: %s\n";
  }
  piVar13 = (int *)__errno();
  pcVar20 = strerror(*piVar13);
  __android_log_print(6,"thermal_core",pcVar10,pcVar20);
LAB_00115cdc:
  uVar9 = ftell(param_1);
  goto LAB_00115ad4;
LAB_001164a8:
  if (*(int *)PTR_DAT_0012d278 == 1) {
    __android_log_print(4,"thermal_core","List items are more than MAX_NUM_PTRS %d\n",0x14);
  }
  goto LAB_00115e1c;
}
