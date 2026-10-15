/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: exe_change_policy   VMA: 0x8940   (see reverse/symbols.csv)
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 exe_change_policy(char *param_1)

{
  bool bVar1;
  bool bVar2;
  long *plVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  size_t sVar12;
  undefined8 uVar13;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar14;
  size_t sVar15;
  FILE *__stream_01;
  int *piVar16;
  char *pcVar17;
  ulong *puVar18;
  byte bVar19;
  bool bVar20;
  ulong uVar21;
  ulong uVar22;
  long lVar23;
  uint *puVar24;
  uint uVar25;
  undefined4 uVar26;
  long lVar27;
  ulong uVar28;
  uint *puVar29;
  uint *puVar30;
  long lVar31;
  byte *pbVar32;
  ulong uVar33;
  byte *pbVar34;
  ulong local_538;
  long local_510;
  ulong local_508;
  ulong local_500;
  undefined5 local_4e0;
  undefined3 uStack_4db;
  undefined5 uStack_4d8;
  undefined3 uStack_4d3;
  undefined8 local_4d0;
  undefined8 uStack_4c8;
  undefined8 uStack_4c0;
  undefined8 uStack_4b8;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 uStack_4a0;
  undefined8 uStack_498;
  undefined8 local_490;
  undefined8 uStack_488;
  undefined8 uStack_480;
  undefined8 uStack_478;
  undefined8 local_470;
  undefined8 uStack_468;
  undefined8 uStack_460;
  undefined8 uStack_458;
  undefined8 local_450;
  undefined8 uStack_448;
  undefined8 uStack_440;
  undefined8 uStack_438;
  undefined8 local_430;
  undefined8 uStack_428;
  undefined8 uStack_420;
  undefined8 uStack_418;
  undefined8 local_410;
  undefined8 uStack_408;
  undefined8 uStack_400;
  undefined8 uStack_3f8;
  undefined8 local_3f0;
  undefined8 uStack_3e8;
  undefined4 local_3e0;
  char cStack_3dc;
  undefined1 uStack_3db;
  undefined2 uStack_3da;
  char local_3d8;
  undefined2 uStack_3d7;
  undefined1 uStack_3d5;
  undefined1 uStack_3d4;
  undefined1 uStack_3d3;
  undefined1 uStack_3d2;
  undefined1 uStack_3d1;
  char cStack_3d0;
  undefined1 uStack_3cf;
  undefined1 uStack_3ce;
  undefined1 uStack_3cd;
  undefined1 uStack_3cc;
  undefined1 uStack_3cb;
  undefined1 uStack_3ca;
  undefined1 uStack_3c9;
  undefined8 uStack_3c8;
  undefined8 uStack_3c0;
  undefined8 uStack_3b8;
  undefined8 local_3b0;
  undefined8 uStack_3a8;
  undefined8 uStack_3a0;
  undefined8 uStack_398;
  undefined8 local_390;
  undefined8 uStack_388;
  undefined8 uStack_380;
  undefined8 uStack_378;
  undefined8 local_370;
  undefined8 uStack_368;
  undefined8 uStack_360;
  undefined8 uStack_358;
  undefined8 local_350;
  undefined8 uStack_348;
  undefined8 uStack_340;
  undefined8 uStack_338;
  undefined8 local_330;
  undefined8 uStack_328;
  undefined8 uStack_320;
  undefined8 uStack_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 uStack_300;
  undefined8 uStack_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 uStack_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined8 uStack_2c0;
  undefined8 uStack_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 uStack_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined8 local_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  ulong local_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  ulong local_1c0 [7];
  undefined6 uStack_188;
  undefined2 local_182;
  undefined6 uStack_180;
  undefined2 uStack_17a;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  ulong local_120;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  long local_78;
  
  lVar6 = tpidr_el0;
  local_78 = *(long *)(lVar6 + 0x28);
  uStack_218 = 0;
  local_220 = 0;
  uStack_208 = 0;
  uStack_210 = 0;
  uStack_238 = 0;
  local_240 = 0;
  uStack_228 = 0;
  uStack_230 = 0;
  uStack_258 = 0;
  local_260 = 0;
  uStack_248 = 0;
  uStack_250 = 0;
  uStack_278 = 0;
  local_280 = 0;
  uStack_268 = 0;
  uStack_270 = 0;
  local_288 = 0;
  local_290 = 0;
  uStack_2a8 = 0;
  local_2b0 = 0;
  uStack_298 = 0;
  uStack_2a0 = 0;
  uStack_2c8 = 0;
  local_2d0 = 0;
  uStack_2b8 = 0;
  uStack_2c0 = 0;
  uStack_2e8 = 0;
  local_2f0 = 0;
  uStack_2d8 = 0;
  uStack_2e0 = 0;
  uStack_308 = 0;
  local_310 = 0;
  uStack_2f8 = 0;
  uStack_300 = 0;
  uStack_328 = 0;
  local_330 = 0;
  uStack_318 = 0;
  uStack_320 = 0;
  uStack_348 = 0;
  local_350 = 0;
  uStack_338 = 0;
  uStack_340 = 0;
  uStack_368 = 0;
  local_370 = 0;
  uStack_358 = 0;
  uStack_360 = 0;
  uStack_388 = 0;
  local_390 = 0;
  uStack_378 = 0;
  uStack_380 = 0;
  uStack_3a8 = 0;
  local_3b0 = 0;
  uStack_398 = 0;
  uStack_3a0 = 0;
  uStack_3c8 = 0;
  cStack_3d0 = '\0';
  uStack_3cf = 0;
  uStack_3ce = 0;
  uStack_3cd = 0;
  uStack_3cc = 0;
  uStack_3cb = 0;
  uStack_3ca = 0;
  uStack_3c9 = 0;
  uStack_3b8 = 0;
  uStack_3c0 = 0;
  uStack_3e8 = 0;
  local_3f0 = 0;
  local_3d8 = '\0';
  uStack_3d7 = 0;
  uStack_3d5 = 0;
  uStack_3d4 = 0;
  uStack_3d3 = 0;
  uStack_3d2 = 0;
  uStack_3d1 = 0;
  local_3e0 = 0;
  cStack_3dc = '\0';
  uStack_3db = 0;
  uStack_3da = 0;
  uStack_408 = 0;
  local_410 = 0;
  uStack_3f8 = 0;
  uStack_400 = 0;
  uStack_428 = 0;
  local_430 = 0;
  uStack_418 = 0;
  uStack_420 = 0;
  uStack_448 = 0;
  local_450 = 0;
  uStack_438 = 0;
  uStack_440 = 0;
  uStack_468 = 0;
  local_470 = 0;
  uStack_458 = 0;
  uStack_460 = 0;
  uStack_488 = 0;
  local_490 = 0;
  uStack_478 = 0;
  uStack_480 = 0;
  uStack_4a8 = 0;
  local_4b0 = 0;
  uStack_498 = 0;
  uStack_4a0 = 0;
  uStack_4c8 = 0;
  local_4d0 = 0;
  uStack_4b8 = 0;
  uStack_4c0 = 0;
  uStack_4d8 = 0;
  uStack_4d3 = 0;
  local_4e0 = 0;
  uStack_4db = 0;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_0012e92c);
  if ((DAT_0012e928 == '\x01') && (iVar9 = strncmp(param_1,"thermal_mtbf.conf",0x11), iVar9 != 0)) {
    __android_log_print(4,"thermal_core","mtbf mode on, lock policy\n");
LAB_00108cdc:
    iVar9 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e92c);
    uVar26 = 0xffffffff;
    goto LAB_00108cec;
  }
  sVar12 = strlen(param_1);
  iVar9 = strncmp(param_1,&DAT_0012e960,sVar12);
  if (iVar9 == 0) {
    pcVar14 = "Same policy %s, skip...\n";
  }
  else {
    sVar12 = strlen(param_1);
    __strncpy_chk(&local_240,param_1,sVar12,0x40);
    if (DAT_0012e9a0 != 0) {
      sVar12 = strlen(param_1);
      iVar9 = (int)sVar12;
      uVar21 = 0;
      do {
        lVar31 = (long)iVar9 + uVar21;
        uVar28 = uVar21 - 1;
        if (lVar31 < 1) break;
        lVar23 = uVar21 + (long)iVar9;
        uVar21 = uVar28;
      } while (param_1[lVar23] != '.');
      if ((0 < lVar31) && (iVar9 + (int)uVar28 + 1 < iVar9)) {
        __strncpy_chk(&local_280,param_1,uVar28 + (long)iVar9 + 1,0x40);
        __strncpy_chk(&local_290,param_1 + uVar28 + (long)iVar9 + 1,~uVar28,0x10);
        snprintf((char *)&local_280,0x40,(char *)0x40,"%s%s%s",&local_280,"_infob",&local_290);
        snprintf((char *)&uStack_2e0,0x50,(char *)0x50,&DAT_00105536,"/vendor/etc/thermal/",
                 &local_280);
        iVar9 = access((char *)&uStack_2e0,0);
        if (iVar9 == 0) {
          uStack_218 = 0;
          local_220 = 0;
          uStack_208 = 0;
          uStack_210 = 0;
          uStack_238 = 0;
          local_240 = 0;
          uStack_228 = 0;
          uStack_230 = 0;
          uVar13 = __strlen_chk(&local_280,0x40);
          __strncpy_chk2(&local_240,&local_280,uVar13,0x40,0x40);
          __android_log_print(6,"thermal_core","apply info_b policy: %s\n",&local_240);
        }
      }
    }
    sVar12 = __strlen_chk(&local_240,0x40);
    iVar9 = strncmp((char *)&local_240,&DAT_0012e9a4,sVar12);
    if (iVar9 != 0) {
      snprintf((char *)&uStack_2e0,0x50,(char *)0x50,&DAT_00105536,"/data/vendor/thermal/",
               &local_240);
      iVar9 = access((char *)&uStack_2e0,0);
      if (iVar9 != 0) {
        snprintf((char *)&uStack_2e0,0x50,(char *)0x50,&DAT_00105536,"/vendor/etc/thermal/",
                 &local_240);
        iVar9 = access((char *)&uStack_2e0,0);
        if (iVar9 != 0) goto LAB_00108cdc;
      }
      __stream = fopen("/data/vendor/thermal/.current_tp","w");
      if (__stream == (FILE *)0x0) {
        __android_log_print(6,"thermal_core","Failed to open %s\n",
                            "/data/vendor/thermal/.current_tp");
        goto LAB_00108cdc;
      }
      iVar9 = fileno(__stream);
      iVar9 = flock(iVar9,2);
      piVar16 = (int *)PTR_DAT_0012d278;
      if (iVar9 == 0) {
        __stream_00 = fopen((char *)&uStack_2e0,"r");
        if (__stream_00 == (FILE *)0x0) {
          __android_log_print(6,"thermal_core","Failed to open %s\n",&uStack_2e0);
          uVar26 = 0xffffffff;
        }
        else {
          DAT_0012e9e4 = '\x01';
          pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
          if ((char *)&local_3e0 == pcVar14) {
            uVar10 = __strlen_chk(&local_3e0,0x100);
            if (0 < (int)uVar10) {
              uVar21 = (ulong)uVar10;
              do {
                uVar10 = uVar10 - 1;
                if (0x20 < *(byte *)((long)&local_3e0 + (ulong)uVar10) ||
                    (1L << ((ulong)*(byte *)((long)&local_3e0 + (ulong)uVar10) & 0x3f) &
                    0x100002400U) == 0) goto LAB_0010b2a8;
                uVar28 = uVar21 - 1;
                bVar2 = 0 < (long)uVar21;
                uVar21 = uVar28;
              } while (uVar28 != 0 && bVar2);
              uVar21 = 0;
LAB_0010b2a8:
              *(undefined1 *)((long)&local_3e0 + (long)(int)uVar21) = 0;
            }
            rewind(__stream_00);
            if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                0x5f7963696c6f705b &&
                CONCAT17(uStack_3d4,
                         CONCAT16(uStack_3d5,
                                  CONCAT24(uStack_3d7,
                                           CONCAT13(local_3d8,CONCAT21(uStack_3da,uStack_3db))))) ==
                0x5d657079745f7963) goto LAB_00108d68;
            snprintf((char *)&local_4e0,0x100,(char *)0x100,&DAT_00102ab3,&local_3e0);
            tp_decrypt_v1(&local_4e0);
            if (CONCAT35(uStack_4db,local_4e0) == 0x5f7963696c6f705b &&
                CONCAT53(uStack_4d8,uStack_4db) == 0x5d657079745f7963) {
              bVar7 = false;
              bVar2 = true;
              iVar9 = 1;
            }
            else {
              iVar9 = 2;
              bVar7 = true;
              bVar2 = false;
            }
          }
          else {
LAB_00108d68:
            bVar7 = false;
            bVar2 = false;
            iVar9 = 0;
          }
          __android_log_print(6,"thermal_core","encrypted_policy %d\n");
          pthread_mutex_lock((pthread_mutex_t *)&DAT_0012e8f8);
          lVar31 = DAT_0012ea68;
          for (puVar30 = DAT_0012e920; DAT_0012ea68 = lVar31, puVar30 != (uint *)0x0;
              puVar30 = *(uint **)(puVar30 + 10)) {
            if (puVar30[9] == 0) {
              (**(code **)(*(long *)(puVar30 + 2) + 0x20))
                        (*puVar30,lVar31 + (ulong)puVar30[1] * 0x50,0);
              uVar10 = 0;
LAB_00108de0:
              puVar30[4] = uVar10;
            }
            else if (puVar30[9] == 1) {
              *(undefined4 *)(lVar31 + (ulong)puVar30[1] * 0x50 + 0x18) = 0xfffbd1b0;
              uVar10 = (**(code **)(*(long *)(puVar30 + 2) + 0x20))
                                 (*puVar30,lVar31 + (ulong)puVar30[1] * 0x50,1);
              goto LAB_00108de0;
            }
            puVar30[7] = 1;
            lVar31 = DAT_0012ea68;
          }
          pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e8f8);
          pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
          while (pcVar14 != (char *)0x0) {
            uVar10 = __strlen_chk(&local_3e0,0x100);
            if (0 < (int)uVar10) {
              uVar21 = (ulong)uVar10;
              do {
                uVar10 = uVar10 - 1;
                if (0x20 < *(byte *)((long)&local_3e0 + (ulong)uVar10) ||
                    (1L << ((ulong)*(byte *)((long)&local_3e0 + (ulong)uVar10) & 0x3f) &
                    0x100002400U) == 0) goto LAB_00108ee0;
                uVar28 = uVar21 - 1;
                bVar20 = 0 < (long)uVar21;
                uVar21 = uVar28;
              } while (uVar28 != 0 && bVar20);
              uVar21 = 0;
LAB_00108ee0:
              *(undefined1 *)((long)&local_3e0 + (long)(int)uVar21) = 0;
            }
            if (bVar2) {
              sVar12 = strnlen((char *)&local_3e0,0x200);
              if (sVar12 != 0) {
                uVar21 = 0;
                uVar28 = 1;
                do {
                  bVar19 = *(byte *)((long)&local_3e0 + uVar21);
                  if (bVar19 - 0x20 < 0x5b) {
                    uVar10 = ((uint)bVar19 - ((int)uVar21 + (int)(uVar21 / 10) * -10)) + 0x3b;
                    bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
                  }
                  *(byte *)((long)&local_3e0 + uVar21) = bVar19;
                  sVar12 = strnlen((char *)&local_3e0,0x200);
                  bVar20 = uVar28 < sVar12;
                  uVar21 = uVar28;
                  uVar28 = (ulong)((int)uVar28 + 1);
                } while (bVar20);
              }
            }
            else if ((bVar7) && (sVar12 = strnlen((char *)&local_3e0,0x200), sVar12 != 0)) {
              uVar21 = 0;
              uVar28 = 1;
              do {
                bVar19 = *(byte *)((long)&local_3e0 + uVar21);
                if (bVar19 - 0x20 < 0x5b) {
                  uVar10 = ((uint)bVar19 - ((int)uVar21 + (int)(uVar21 / 5) * -5)) + 0x3b;
                  bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
                }
                *(byte *)((long)&local_3e0 + uVar21) = bVar19;
                sVar12 = strnlen((char *)&local_3e0,0x200);
                bVar20 = uVar28 < sVar12;
                uVar21 = uVar28;
                uVar28 = (ulong)((int)uVar28 + 1);
              } while (bVar20);
            }
            iVar11 = __strlen_chk(&local_3e0,0x100);
            if (((iVar11 != 0) && ((byte)local_3e0 == 0x5b)) &&
               (*(char *)((long)&local_3e0 + (long)(iVar11 + -1)) == ']')) {
              if (*(int *)PTR_DAT_0012d278 == 1) {
                __android_log_print(4,"thermal_core","cmd: %s\n",&local_3e0);
              }
              if (local_3e0 == 0x46544c5b && cStack_3dc == ']') {
                uStack_1d8 = 0;
                local_1e0 = 0;
                uStack_1c8 = 0;
                uStack_1d0 = 0;
                uStack_1f8 = 0;
                local_200 = 0;
                uStack_1e8 = 0;
                uStack_1f0 = 0;
                local_508 = ftell(__stream_00);
                pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
                if (pcVar14 != (char *)0x0) {
                  bVar8 = true;
                  local_538 = 0xffffffff;
                  local_510 = -1;
                  bVar20 = true;
LAB_00109700:
                  do {
                    uVar10 = __strlen_chk(&local_3e0,0x100);
                    if (0 < (int)uVar10) {
                      uVar21 = (ulong)uVar10;
                      do {
                        uVar10 = uVar10 - 1;
                        if (0x20 < *(byte *)((long)&local_3e0 + (ulong)uVar10) ||
                            (1L << ((ulong)*(byte *)((long)&local_3e0 + (ulong)uVar10) & 0x3f) &
                            0x100002400U) == 0) goto LAB_00109740;
                        uVar28 = uVar21 - 1;
                        bVar1 = 0 < (long)uVar21;
                        uVar21 = uVar28;
                      } while (uVar28 != 0 && bVar1);
                      uVar21 = 0;
LAB_00109740:
                      *(undefined1 *)((long)&local_3e0 + (long)(int)uVar21) = 0;
                    }
                    if (iVar9 == 2) {
                      sVar12 = strnlen((char *)&local_3e0,0x200);
                      if (sVar12 != 0) {
                        uVar21 = 0;
                        uVar28 = 1;
                        do {
                          bVar19 = *(byte *)((long)&local_3e0 + uVar21);
                          if (bVar19 - 0x20 < 0x5b) {
                            uVar10 = ((uint)bVar19 - ((int)uVar21 + (int)(uVar21 / 5) * -5)) + 0x3b;
                            bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
                          }
                          *(byte *)((long)&local_3e0 + uVar21) = bVar19;
                          sVar12 = strnlen((char *)&local_3e0,0x200);
                          bVar1 = uVar28 < sVar12;
                          uVar21 = uVar28;
                          uVar28 = (ulong)((int)uVar28 + 1);
                        } while (bVar1);
                      }
                    }
                    else if ((iVar9 == 1) &&
                            (sVar12 = strnlen((char *)&local_3e0,0x200), sVar12 != 0)) {
                      uVar21 = 0;
                      uVar28 = 1;
                      do {
                        bVar19 = *(byte *)((long)&local_3e0 + uVar21);
                        if (bVar19 - 0x20 < 0x5b) {
                          uVar10 = ((uint)bVar19 - ((int)uVar21 + (int)(uVar21 / 10) * -10)) + 0x3b;
                          bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
                        }
                        *(byte *)((long)&local_3e0 + uVar21) = bVar19;
                        sVar12 = strnlen((char *)&local_3e0,0x200);
                        bVar1 = uVar28 < sVar12;
                        uVar21 = uVar28;
                        uVar28 = (ulong)((int)uVar28 + 1);
                      } while (bVar1);
                    }
                    iVar11 = __strlen_chk(&local_3e0,0x100);
                    if ((iVar11 != 0) && ((local_3e0 & 0xff) != 0x23)) {
                      if (((local_3e0 & 0xff) == 0x5b) &&
                         (*(char *)((long)&local_3e0 + (long)(iVar11 + -1)) == ']')) break;
                      if (*(int *)PTR_DAT_0012d278 == 1) {
                        __android_log_print(4,"thermal_core","line: %s\n",&local_3e0);
                      }
                      if (!bVar20) {
                        if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                            == 0x5f676e696c6c6f70 &&
                            CONCAT17(uStack_3d1,
                                     CONCAT16(uStack_3d2,
                                              CONCAT15(uStack_3d3,
                                                       CONCAT14(uStack_3d4,
                                                                CONCAT13(uStack_3d5,
                                                                         CONCAT21(uStack_3d7,
                                                                                  local_3d8)))))) ==
                            0x6c61767265746e69) {
                          pbVar34 = (byte *)&local_3e0;
                          local_1c0[0] = local_1c0[0] & 0xffffffff00000000;
                          uVar10 = local_3e0 & 0xff;
                          pbVar32 = pbVar34;
                          if ((byte)local_3e0 != 0) {
                            do {
                              if (uVar10 == 0x3d) {
                                pbVar34 = pbVar32 + 1;
                                *pbVar32 = 0;
                                break;
                              }
                              pbVar34 = pbVar32 + 1;
                              uVar10 = (uint)*pbVar34;
                              pbVar32 = pbVar34;
                            } while (uVar10 != 0);
                          }
                          for (; *pbVar34 == 0x20 || *pbVar34 == 9; pbVar34 = pbVar34 + 1) {
                          }
                          sscanf((char *)pbVar34,"%d",local_1c0);
                          lVar31 = DAT_0012ea68;
                          if (DAT_0012ea68 != 0) {
                            if ((CONCAT26(uStack_3da,
                                          CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                                 0x5f676e696c6c6f70 &&
                                CONCAT17(uStack_3d1,
                                         CONCAT16(uStack_3d2,
                                                  CONCAT15(uStack_3d3,
                                                           CONCAT14(uStack_3d4,
                                                                    CONCAT13(uStack_3d5,
                                                                             CONCAT21(uStack_3d7,
                                                                                      local_3d8)))))
                                        ) == 0x6c61767265746e69) &&
                                CONCAT13(uStack_3cd,
                                         CONCAT12(uStack_3ce,CONCAT11(uStack_3cf,cStack_3d0))) ==
                                0x6e696d5f) {
                              *(undefined4 *)(DAT_0012ea68 + local_510 * 0x50 + 0x1c) =
                                   (undefined4)local_1c0[0];
                            }
                            else if ((CONCAT26(uStack_3da,
                                               CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                                      == 0x5f676e696c6c6f70 &&
                                     CONCAT17(uStack_3d1,
                                              CONCAT16(uStack_3d2,
                                                       CONCAT15(uStack_3d3,
                                                                CONCAT14(uStack_3d4,
                                                                         CONCAT13(uStack_3d5,
                                                                                  CONCAT21(
                                                  uStack_3d7,local_3d8)))))) == 0x6c61767265746e69)
                                     && CONCAT13(uStack_3cd,
                                                 CONCAT12(uStack_3ce,CONCAT11(uStack_3cf,cStack_3d0)
                                                         )) == 0x64696d5f) {
                              *(undefined4 *)(DAT_0012ea68 + local_510 * 0x50 + 0x20) =
                                   (undefined4)local_1c0[0];
                            }
                            else if ((CONCAT26(uStack_3da,
                                               CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                                      == 0x5f676e696c6c6f70 &&
                                     CONCAT17(uStack_3d1,
                                              CONCAT16(uStack_3d2,
                                                       CONCAT15(uStack_3d3,
                                                                CONCAT14(uStack_3d4,
                                                                         CONCAT13(uStack_3d5,
                                                                                  CONCAT21(
                                                  uStack_3d7,local_3d8)))))) == 0x6c61767265746e69)
                                     && CONCAT13(uStack_3cd,
                                                 CONCAT12(uStack_3ce,CONCAT11(uStack_3cf,cStack_3d0)
                                                         )) == 0x78616d5f) {
                              *(undefined4 *)(DAT_0012ea68 + local_510 * 0x50 + 0x24) =
                                   (undefined4)local_1c0[0];
                            }
                            if (*(int *)PTR_DAT_0012d278 == 1) {
                              lVar31 = lVar31 + local_510 * 0x50;
                              __android_log_print(4,"thermal_core",
                                                  "TZ%d min_p%d, mid_p%d, max_p%d\n",local_538,
                                                  *(undefined4 *)(lVar31 + 0x1c),
                                                  *(undefined4 *)(lVar31 + 0x20),
                                                  *(undefined4 *)(lVar31 + 0x24));
                            }
                          }
                          goto LAB_00109938;
                        }
                        if (!bVar8) {
                          if (*(int *)(DAT_0012ea68 + local_510 * 0x50 + 0x2c) != 1)
                          goto LAB_00109938;
                          if (local_3e0 == 0x6c6f6f63 && CONCAT11(uStack_3db,cStack_3dc) == 0x7265)
                          {
                            uStack_98 = 0;
                            local_a0 = 0;
                            uStack_88 = 0;
                            uStack_90 = 0;
                            uStack_b8 = 0;
                            local_c0 = 0;
                            uStack_a8 = 0;
                            local_b0 = 0;
                            uStack_d8 = 0;
                            local_e0 = 0;
                            uStack_c8 = 0;
                            local_d0 = 0;
                            uStack_f8 = 0;
                            local_100 = 0;
                            uStack_e8 = 0;
                            uStack_f0 = 0;
                            uStack_108 = 0;
                            local_110 = 0;
                            local_120 = 0;
                            uStack_128 = 0;
                            local_130 = 0;
                            uStack_138 = 0;
                            local_140 = 0;
                            uStack_148 = 0;
                            local_150 = 0;
                            uStack_158 = 0;
                            local_160 = 0;
                            uStack_178 = 0;
                            uStack_180 = 0;
                            uStack_17a = 0;
                            uStack_168 = 0;
                            uStack_170 = 0;
                            local_1c0[5] = 0;
                            local_1c0[4] = 0;
                            uStack_188 = 0;
                            local_182 = 0;
                            local_1c0[6] = 0;
                            pbVar34 = (byte *)&local_3e0;
                            local_1c0[1] = 0;
                            local_1c0[0] = 0;
                            local_1c0[3] = 0;
                            local_1c0[2] = 0;
                            uVar10 = local_3e0 & 0xff;
                            pbVar32 = pbVar34;
                            if ((byte)local_3e0 != 0) {
                              do {
                                if (uVar10 == 0x3d) {
                                  pbVar34 = pbVar32 + 1;
                                  *pbVar32 = 0;
                                  break;
                                }
                                pbVar34 = pbVar32 + 1;
                                uVar10 = (uint)*pbVar34;
                                pbVar32 = pbVar34;
                              } while (uVar10 != 0);
                            }
                            for (; (bVar19 = *pbVar34, bVar19 == 9 || (bVar19 == 0x20));
                                pbVar34 = pbVar34 + 1) {
                            }
                            if (bVar19 == 0x5b) {
                              bVar20 = true;
                              local_120 = local_120 & 0xffffffff00000000;
                              do {
                                while( true ) {
                                  local_500 = local_120;
                                  bVar19 = *pbVar34;
                                  uVar10 = (uint)local_120;
                                  if (bVar19 < 0x5b) break;
                                  if ((bVar19 != 0x5d) && (bVar19 != 0x5b)) goto LAB_00109f08;
LAB_00109edc:
                                  *pbVar34 = 0;
LAB_00109ee0:
                                  pbVar34 = pbVar34 + 1;
                                }
                                if (bVar19 == 0x2c) {
                                  bVar20 = true;
                                  goto LAB_00109edc;
                                }
                                if (bVar19 == 0) {
                                  if ((uint)local_120 != 0) goto LAB_0010a190;
                                  local_500 = 0;
                                  goto LAB_0010a350;
                                }
LAB_00109f08:
                                if ((!bVar20) || (bVar19 == 0x20)) goto LAB_00109ee0;
                                if (0x13 < (uint)local_120) goto LAB_0010a160;
                                local_1c0[local_120 & 0xffffffff] = (ulong)pbVar34;
                                bVar20 = false;
                                local_120 = CONCAT44(local_120._4_4_,(uint)local_120 + 1);
                                pbVar34 = pbVar34 + 1;
                              } while( true );
                            }
                            local_500 = 0;
                            goto LAB_0010a350;
                          }
                          if (CONCAT26(uStack_3da,
                                       CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                              0x6c61636974697263 &&
                              CONCAT17(uStack_3d4,
                                       CONCAT16(uStack_3d5,
                                                CONCAT24(uStack_3d7,
                                                         CONCAT13(local_3d8,
                                                                  CONCAT21(uStack_3da,uStack_3db))))
                                      ) == 0x706d65745f6c6163) {
                            uStack_180 = 0;
                            local_1c0[5] = 0;
                            local_1c0[4] = 0;
                            uStack_188 = 0;
                            local_182 = 0;
                            local_1c0[6] = 0;
                            pbVar34 = (byte *)&local_3e0;
                            local_1c0[1] = 0;
                            local_1c0[0] = 0;
                            local_1c0[3] = 0;
                            local_1c0[2] = 0;
                            uVar10 = local_3e0 & 0xff;
                            pbVar32 = pbVar34;
                            if ((byte)local_3e0 != 0) {
                              do {
                                if (uVar10 == 0x3d) {
                                  pbVar34 = pbVar32 + 1;
                                  *pbVar32 = 0;
                                  break;
                                }
                                pbVar34 = pbVar32 + 1;
                                uVar10 = (uint)*pbVar34;
                                pbVar32 = pbVar34;
                              } while (uVar10 != 0);
                            }
                            for (; *pbVar34 == 0x20 || *pbVar34 == 9; pbVar34 = pbVar34 + 1) {
                            }
                            if (((DAT_0012ea68 != 0) &&
                                (lVar31 = *(long *)(DAT_0012ea68 + local_510 * 0x50 + 0x38),
                                lVar31 != 0)) &&
                               (*(int *)(DAT_0012ea68 + local_510 * 0x50 + 0x34) != 0)) {
                              uVar21 = 0;
                              lVar23 = 4;
                              lVar27 = DAT_0012ea68;
                              while( true ) {
                                if (*(int *)(lVar31 + lVar23) == 3) {
                                  snprintf((char *)local_1c0,0x46,(char *)0x46,
                                           "/sys/class/thermal/thermal_zone%d/trip_point_%d_temp",
                                           local_538,uVar21 & 0xffffffff);
                                  node_write(pbVar34,local_1c0);
                                  DAT_0012e9e4 = '\0';
                                  lVar27 = DAT_0012ea68;
                                }
                                uVar21 = uVar21 + 1;
                                if (*(uint *)(lVar27 + local_510 * 0x50 + 0x34) <= uVar21) break;
                                lVar31 = *(long *)(lVar27 + local_510 * 0x50 + 0x38);
                                lVar23 = lVar23 + 8;
                              }
                            }
                          }
                          else if (CONCAT26(uStack_3da,
                                            CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                                   0x6f5f686374697773 &&
                                   CONCAT17(uStack_3d3,
                                            CONCAT16(uStack_3d4,
                                                     CONCAT15(uStack_3d5,
                                                              CONCAT23(uStack_3d7,
                                                                       CONCAT12(local_3d8,uStack_3da
                                                                               ))))) ==
                                   0x706d65745f6e6f5f) {
                            uStack_180 = 0;
                            local_1c0[5] = 0;
                            local_1c0[4] = 0;
                            uStack_188 = 0;
                            local_182 = 0;
                            local_1c0[6] = 0;
                            pbVar34 = (byte *)&local_3e0;
                            local_1c0[1] = 0;
                            local_1c0[0] = 0;
                            local_1c0[3] = 0;
                            local_1c0[2] = 0;
                            uVar10 = local_3e0 & 0xff;
                            pbVar32 = pbVar34;
                            if ((byte)local_3e0 != 0) {
                              do {
                                if (uVar10 == 0x3d) {
                                  pbVar34 = pbVar32 + 1;
                                  *pbVar32 = 0;
                                  break;
                                }
                                pbVar34 = pbVar32 + 1;
                                uVar10 = (uint)*pbVar34;
                                pbVar32 = pbVar34;
                              } while (uVar10 != 0);
                            }
                            for (; *pbVar34 == 0x20 || *pbVar34 == 9; pbVar34 = pbVar34 + 1) {
                            }
                            if (((DAT_0012ea68 != 0) &&
                                (lVar31 = *(long *)(DAT_0012ea68 + local_510 * 0x50 + 0x38),
                                lVar31 != 0)) &&
                               (uVar10 = *(uint *)(DAT_0012ea68 + local_510 * 0x50 + 0x34),
                               uVar21 = (ulong)uVar10, uVar10 != 0)) {
                              uVar28 = 0;
                              piVar16 = (int *)(lVar31 + 4);
                              do {
                                if (*piVar16 == 1) {
                                  uVar21 = uVar28 & 0xffffffff;
                                  uVar22 = uVar28;
                                  break;
                                }
                                uVar28 = uVar28 + 1;
                                piVar16 = piVar16 + 2;
                                uVar22 = uVar21;
                              } while (uVar21 != uVar28);
                              if (*(int *)(lVar31 + uVar22 * 8 + 4) == 1) {
                                snprintf((char *)local_1c0,0x46,(char *)0x46,
                                         "/sys/class/thermal/thermal_zone%d/trip_point_%d_temp",
                                         local_538,uVar21);
                                puVar18 = local_1c0;
                                goto LAB_0010a0e4;
                              }
                            }
                          }
                          else {
                            pbVar34 = (byte *)&local_3e0;
                            if (CONCAT26(uStack_3da,
                                         CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                                0x5f6c6f72746e6f63 &&
                                CONCAT13(uStack_3d5,CONCAT21(uStack_3d7,local_3d8)) == 0x706d6574) {
                              for (; pbVar32 = pbVar34, *pbVar34 != 0; pbVar34 = pbVar34 + 1) {
                                if (*pbVar34 == 0x3d) {
                                  pbVar32 = pbVar34 + 1;
                                  *pbVar34 = 0;
                                  break;
                                }
                              }
                              for (; *pbVar32 == 0x20 || *pbVar32 == 9; pbVar32 = pbVar32 + 1) {
                              }
                              if (((DAT_0012ea68 != 0) &&
                                  (lVar31 = *(long *)(DAT_0012ea68 + local_510 * 0x50 + 0x38),
                                  lVar31 != 0)) &&
                                 (uVar10 = *(uint *)(DAT_0012ea68 + local_510 * 0x50 + 0x34),
                                 uVar10 != 0)) {
                                uVar21 = 0;
                                piVar16 = (int *)(lVar31 + 4);
                                iVar11 = 0;
                                do {
                                  iVar4 = (int)uVar21;
                                  if (*piVar16 != 1) {
                                    iVar4 = iVar11;
                                  }
                                  uVar21 = uVar21 + 1;
                                  piVar16 = piVar16 + 2;
                                  iVar11 = iVar4;
                                } while (uVar10 != uVar21);
                                if (*(int *)(lVar31 + (long)iVar4 * 8 + 4) == 1) {
                                  snprintf(&DAT_0012f384,0x46,(char *)0x46,
                                           "/sys/class/thermal/thermal_zone%d/trip_point_%d_temp",
                                           local_538);
                                  node_write(pbVar32,&DAT_0012f384);
                                }
                              }
                            }
                            else {
                              uVar10 = local_3e0 & 0xff;
                              pbVar32 = pbVar34;
                              if ((byte)local_3e0 != 0) {
                                do {
                                  if (uVar10 == 0x3d) {
                                    pbVar34 = pbVar32 + 1;
                                    *pbVar32 = 0;
                                    break;
                                  }
                                  pbVar34 = pbVar32 + 1;
                                  uVar10 = (uint)*pbVar34;
                                  pbVar32 = pbVar34;
                                } while (uVar10 != 0);
                              }
                              for (; *pbVar34 == 0x20 || *pbVar34 == 9; pbVar34 = pbVar34 + 1) {
                              }
                              uVar10 = __strlen_chk(&local_3e0,0x100);
                              if (0 < (int)uVar10) {
                                uVar21 = (ulong)uVar10;
                                do {
                                  uVar10 = uVar10 - 1;
                                  if (0x20 < *(byte *)((long)&local_3e0 + (ulong)uVar10) ||
                                      (1L << ((ulong)*(byte *)((long)&local_3e0 + (ulong)uVar10) &
                                             0x3f) & 0x100002400U) == 0) goto LAB_0010a0bc;
                                  uVar28 = uVar21 - 1;
                                  bVar20 = 0 < (long)uVar21;
                                  uVar21 = uVar28;
                                } while (uVar28 != 0 && bVar20);
                                uVar21 = 0;
LAB_0010a0bc:
                                *(undefined1 *)((long)&local_3e0 + (long)(int)uVar21) = 0;
                              }
                              snprintf((char *)&local_200,0x40,(char *)0x40,
                                       "/sys/class/thermal/thermal_zone%d/%s",local_538,&local_3e0);
                              puVar18 = &local_200;
LAB_0010a0e4:
                              node_write(pbVar34,puVar18);
                            }
                          }
                          goto LAB_0010a88c;
                        }
                        break;
                      }
                      if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x5f6c616d72656874 &&
                          CONCAT13(uStack_3d5,CONCAT21(uStack_3d7,local_3d8)) == 0x656e6f7a) {
                        pbVar34 = (byte *)&local_3e0;
                        uVar10 = local_3e0 & 0xff;
                        pbVar32 = pbVar34;
                        if ((byte)local_3e0 != 0) {
                          do {
                            if (uVar10 == 0x3d) {
                              pbVar34 = pbVar32 + 1;
                              *pbVar32 = 0;
                              break;
                            }
                            pbVar34 = pbVar32 + 1;
                            uVar10 = (uint)*pbVar34;
                            pbVar32 = pbVar34;
                          } while (uVar10 != 0);
                        }
                        for (; *pbVar34 == 0x20 || *pbVar34 == 9; pbVar34 = pbVar34 + 1) {
                        }
                        if (*(int *)PTR_DAT_0012d278 == 1) {
                          __android_log_print(4,"thermal_core","par: %s\n",pbVar34);
                        }
                        if (DAT_0012ea68 == 0) break;
                        if (DAT_0012ea60 == 0) {
LAB_0010add4:
                          __android_log_print(6,"thermal_core",
                                              "Failed to find thermal zone index of %s\n",pbVar34);
                          break;
                        }
                        pcVar14 = (char *)(DAT_0012ea68 + 4);
                        sVar12 = strlen((char *)pbVar34);
                        iVar11 = strncmp(pcVar14,(char *)pbVar34,sVar12);
                        if (iVar11 == 0) {
                          local_538 = 0;
                        }
                        else {
                          local_538 = 0;
                          uVar21 = (ulong)DAT_0012ea60;
                          pcVar14 = (char *)(DAT_0012ea68 + 0x54);
                          do {
                            local_538 = local_538 + 1;
                            if (uVar21 <= local_538) goto LAB_0010add4;
                            sVar12 = strlen((char *)pbVar34);
                            iVar11 = strncmp(pcVar14,(char *)pbVar34,sVar12);
                            pcVar14 = pcVar14 + 0x50;
                          } while (iVar11 != 0);
                          if ((int)local_538 == -1) break;
                          local_538 = local_538 & 0xffffffff;
                        }
                      }
                      iVar11 = (int)local_538;
                      goto LAB_0010a8a0;
                    }
                    pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
                  } while (pcVar14 != (char *)0x0);
                }
LAB_0010adf4:
                if ((int)local_508 < 0) {
                  pcVar14 = "Negative file position %s\n";
                }
                else {
                  iVar11 = fseek(__stream_00,local_508 & 0xffffffff,0);
                  if (iVar11 != -1) goto LAB_00108e8c;
                  pcVar14 = "fseek failed: %s\n";
                }
                piVar16 = (int *)__errno();
                pcVar17 = strerror(*piVar16);
                __android_log_print(6,"thermal_core",pcVar14,pcVar17);
              }
              else {
                lVar31 = DAT_0012e840;
                lVar23 = DAT_0012e840;
                if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                    0x5f7963696c6f705b &&
                    CONCAT17(uStack_3d4,
                             CONCAT16(uStack_3d5,
                                      CONCAT24(uStack_3d7,
                                               CONCAT13(local_3d8,CONCAT21(uStack_3da,uStack_3db))))
                            ) == 0x5d657079745f7963) {
                  for (; lVar31 != 0; lVar31 = *(long *)(lVar31 + 0x50)) {
                    if (*(int *)(lVar23 + 0x40) == 0) {
                      do {
                    /* WARNING: Do nothing block with infinite loop */
                      } while( true );
                    }
                    if (*(int *)(lVar31 + 0x40) != 0) {
                      lVar27 = 0;
                      uVar21 = 0;
                      do {
                        lVar23 = *(long *)(lVar31 + 0x48);
                        sVar12 = __strlen_chk(&local_240,0x40);
                        iVar11 = strncmp((char *)(lVar23 + lVar27),(char *)&local_240,sVar12);
                        if (iVar11 == 0) {
                          if (-1 < (int)uVar21) goto LAB_00108e8c;
                          goto LAB_0010a970;
                        }
                        uVar21 = uVar21 + 1;
                        lVar27 = lVar27 + 0x48;
                        lVar23 = DAT_0012e840;
                      } while (uVar21 < *(uint *)(lVar31 + 0x40));
                    }
                  }
                  if (*(int *)PTR_DAT_0012d278 == 1) {
                    __android_log_print(4,"thermal_core","Failed to find sub policy index of %s\n",
                                        &local_240);
                  }
LAB_0010a970:
                  local_500 = ftell(__stream_00);
                  pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
                  while (pcVar14 != (char *)0x0) {
                    uVar10 = __strlen_chk(&local_3e0,0x100);
                    if (0 < (int)uVar10) {
                      uVar21 = (ulong)uVar10;
                      do {
                        uVar10 = uVar10 - 1;
                        if (0x20 < *(byte *)((long)&local_3e0 + (ulong)uVar10) ||
                            (1L << ((ulong)*(byte *)((long)&local_3e0 + (ulong)uVar10) & 0x3f) &
                            0x100002400U) == 0) goto LAB_0010aa40;
                        uVar28 = uVar21 - 1;
                        bVar20 = 0 < (long)uVar21;
                        uVar21 = uVar28;
                      } while (uVar28 != 0 && bVar20);
                      uVar21 = 0;
LAB_0010aa40:
                      *(undefined1 *)((long)&local_3e0 + (long)(int)uVar21) = 0;
                    }
                    if (iVar9 == 2) {
                      sVar12 = strnlen((char *)&local_3e0,0x200);
                      if (sVar12 != 0) {
                        uVar21 = 0;
                        uVar28 = 1;
                        do {
                          bVar19 = *(byte *)((long)&local_3e0 + uVar21);
                          if (bVar19 - 0x20 < 0x5b) {
                            uVar10 = ((uint)bVar19 - ((int)uVar21 + (int)(uVar21 / 5) * -5)) + 0x3b;
                            bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
                          }
                          *(byte *)((long)&local_3e0 + uVar21) = bVar19;
                          sVar12 = strnlen((char *)&local_3e0,0x200);
                          bVar20 = uVar28 < sVar12;
                          uVar21 = uVar28;
                          uVar28 = (ulong)((int)uVar28 + 1);
                        } while (bVar20);
                      }
                    }
                    else if ((iVar9 == 1) &&
                            (sVar12 = strnlen((char *)&local_3e0,0x200), sVar12 != 0)) {
                      uVar21 = 0;
                      uVar28 = 1;
                      do {
                        bVar19 = *(byte *)((long)&local_3e0 + uVar21);
                        if (bVar19 - 0x20 < 0x5b) {
                          uVar10 = ((uint)bVar19 - ((int)uVar21 + (int)(uVar21 / 10) * -10)) + 0x3b;
                          bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
                        }
                        *(byte *)((long)&local_3e0 + uVar21) = bVar19;
                        sVar12 = strnlen((char *)&local_3e0,0x200);
                        bVar20 = uVar28 < sVar12;
                        uVar21 = uVar28;
                        uVar28 = (ulong)((int)uVar28 + 1);
                      } while (bVar20);
                    }
                    iVar11 = __strlen_chk(&local_3e0,0x100);
                    if ((iVar11 != 0) && ((local_3e0 & 0xff) != 0x23)) {
                      if (((local_3e0 & 0xff) == 0x5b) &&
                         (*(char *)((long)&local_3e0 + (long)(iVar11 + -1)) == ']')) break;
                      if (*(int *)PTR_DAT_0012d278 == 1) {
                        __android_log_print(4,"thermal_core","line: %s\n",&local_3e0);
                      }
                      if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x6e656e616d726570 && local_3d8 == 't') {
                        pbVar34 = (byte *)&local_3e0;
                        uVar10 = local_3e0 & 0xff;
                        pbVar32 = pbVar34;
                        if ((byte)local_3e0 != 0) {
                          do {
                            if (uVar10 == 0x3d) {
                              pbVar34 = pbVar32 + 1;
                              *pbVar32 = 0;
                              break;
                            }
                            pbVar34 = pbVar32 + 1;
                            uVar10 = (uint)*pbVar34;
                            pbVar32 = pbVar34;
                          } while (uVar10 != 0);
                        }
                        for (; *pbVar34 == 0x20 || *pbVar34 == 9; pbVar34 = pbVar34 + 1) {
                        }
                        if (*(int *)PTR_DAT_0012d278 == 1) {
                          __android_log_print(4,"thermal_core","par: %s\n",pbVar34);
                        }
                        iVar11 = strncasecmp((char *)pbVar34,"Yes",3);
                        if (iVar11 == 0) {
                          if (*(int *)PTR_DAT_0012d278 == 1) {
                            __android_log_print(4,"thermal_core","Change ptp\n");
                          }
                          __stream_01 = fopen("/data/vendor/thermal/.permanent_tp","w");
                          if (__stream_01 == (FILE *)0x0) {
                            __android_log_print(6,"thermal_core","Failed to open %s\n",
                                                "/data/vendor/thermal/.permanent_tp");
                            goto LAB_0010a9ec;
                          }
                          fputs((char *)&local_240,__stream_01);
                          fclose(__stream_01);
                        }
                      }
                      local_500 = ftell(__stream_00);
                    }
LAB_0010a9ec:
                    pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
                  }
                  if ((int)local_500 < 0) {
                    piVar16 = (int *)__errno();
                    pcVar14 = strerror(*piVar16);
                    __android_log_print(6,"thermal_core","Negative file position %s\n",pcVar14);
                  }
                  else {
                    iVar11 = fseek(__stream_00,local_500 & 0xffffffff,0);
                    if (iVar11 == -1) {
                      piVar16 = (int *)__errno();
                      pcVar14 = strerror(*piVar16);
                      __android_log_print(6,"thermal_core","fseek failed: %s\n",pcVar14);
                    }
                  }
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x7369642d46544c5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x7268742d656c6261) &&
                         CONCAT17(uStack_3c9,
                                  CONCAT16(uStack_3ca,
                                           CONCAT15(uStack_3cb,
                                                    CONCAT14(uStack_3cc,
                                                             CONCAT13(uStack_3cd,
                                                                      CONCAT12(uStack_3ce,
                                                                               CONCAT11(uStack_3cf,
                                                                                        cStack_3d0))
                                                                     ))))) == 0x5d676e696c74746f) {
                  disable_throttling_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x6669772d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x74746f7268742d69) &&
                         CONCAT17(uStack_3cc,
                                  CONCAT16(uStack_3cd,
                                           CONCAT15(uStack_3ce,
                                                    CONCAT14(uStack_3cf,
                                                             CONCAT13(cStack_3d0,
                                                                      CONCAT12(uStack_3d1,
                                                                               CONCAT11(uStack_3d2,
                                                                                        uStack_3d3))
                                                                     ))))) == 0x5d676e696c74746f) {
                  wifi_throttling_parser(__stream_00,&local_3e0);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x6669772d6b746d5b &&
                         CONCAT17(uStack_3d3,
                                  CONCAT16(uStack_3d4,
                                           CONCAT15(uStack_3d5,
                                                    CONCAT23(uStack_3d7,
                                                             CONCAT12(local_3d8,uStack_3da))))) ==
                         0x5d66666f2d696669) {
                  wifi_off_parser(__stream_00,&local_3e0);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x2d646d2d6b746d5b &&
                         CONCAT13(uStack_3d5,CONCAT21(uStack_3d7,local_3d8)) == 0x5d66666f) {
                  md_off_parser(__stream_00,&local_3e0);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x6565612d6b746d5b &&
                         CONCAT17(uStack_3d3,
                                  CONCAT16(uStack_3d4,
                                           CONCAT15(uStack_3d5,
                                                    CONCAT23(uStack_3d7,
                                                             CONCAT12(local_3d8,uStack_3da))))) ==
                         0x5d706d75642d6565) {
                  aee_dump_parser(__stream_00,&local_3e0);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x676f6c2d6b746d5b &&
                         CONCAT17(uStack_3d3,
                                  CONCAT16(uStack_3d4,
                                           CONCAT15(uStack_3d5,
                                                    CONCAT23(uStack_3d7,
                                                             CONCAT12(local_3d8,uStack_3da))))) ==
                         0x5d706d75642d676f) {
                  log_dump_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x2d646d2d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6163696669746f6e) &&
                         CONCAT17(uStack_3cc,
                                  CONCAT16(uStack_3cd,
                                           CONCAT15(uStack_3ce,
                                                    CONCAT14(uStack_3cf,
                                                             CONCAT13(cStack_3d0,
                                                                      CONCAT12(uStack_3d1,
                                                                               CONCAT11(uStack_3d2,
                                                                                        uStack_3d3))
                                                                     ))))) == 0x5d6e6f6974616369) {
                  md_notification_parser(__stream_00,&local_3e0);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x2d7a742d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x5d676e696c6c6f70) {
                  tz_polling_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x696b732d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6f72746e6f632d6e) &&
                         CONCAT11(uStack_3cf,cStack_3d0) == 0x5d6c) {
                  skin_control_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x7570632d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6d2d656c6261742d) &&
                         CONCAT17(uStack_3ca,
                                  CONCAT16(uStack_3cb,
                                           CONCAT15(uStack_3cc,
                                                    CONCAT14(uStack_3cd,
                                                             CONCAT13(uStack_3ce,
                                                                      CONCAT12(uStack_3cf,
                                                                               CONCAT11(cStack_3d0,
                                                                                        uStack_3d1))
                                                                     ))))) == 0x5d676e697070616d) {
                  cpu_table_mapping_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x7570632d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6574616c6f73692d) &&
                         cStack_3d0 == ']') {
                  cpu_isolate_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x7570672d6b746d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6d2d656c6261742d) &&
                         CONCAT17(uStack_3ca,
                                  CONCAT16(uStack_3cb,
                                           CONCAT15(uStack_3cc,
                                                    CONCAT14(uStack_3cd,
                                                             CONCAT13(uStack_3ce,
                                                                      CONCAT12(uStack_3cf,
                                                                               CONCAT11(cStack_3d0,
                                                                                        uStack_3d1))
                                                                     ))))) == 0x5d676e697070616d) {
                  gpu_table_mapping_parser(__stream_00,&local_3e0);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x726567726168635b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x5d72656c6f6f632d) {
                  charger_cooler_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x6c616d726568745b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x657268742d6c6168) &&
                         CONCAT17(uStack_3cb,
                                  CONCAT16(uStack_3cc,
                                           CONCAT15(uStack_3cd,
                                                    CONCAT14(uStack_3ce,
                                                             CONCAT13(uStack_3cf,
                                                                      CONCAT12(cStack_3d0,
                                                                               CONCAT11(uStack_3d1,
                                                                                        uStack_3d2))
                                                                     ))))) == 0x5d646c6f68736572) {
                  thermal_hal_threshold_parser(__stream_00,&local_3e0);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x67696c6b6361625b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x656c6f6f632d7468) &&
                         CONCAT11(uStack_3cf,cStack_3d0) == 0x5d72) {
                  backlight_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
                         0x6f632d696669775b &&
                         CONCAT17(uStack_3d4,
                                  CONCAT16(uStack_3d5,
                                           CONCAT24(uStack_3d7,
                                                    CONCAT13(local_3d8,
                                                             CONCAT21(uStack_3da,uStack_3db))))) ==
                         0x5d72656c6f6f632d) {
                  wifi_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x696c6873616c665b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6c6f6f632d746867) &&
                         CONCAT17(uStack_3ce,
                                  CONCAT16(uStack_3cf,
                                           CONCAT15(cStack_3d0,
                                                    CONCAT14(uStack_3d1,
                                                             CONCAT13(uStack_3d2,
                                                                      CONCAT12(uStack_3d3,
                                                                               CONCAT11(uStack_3d4,
                                                                                        uStack_3d5))
                                                                     ))))) == 0x5d72656c6f6f632d) {
                  flashlight_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x61702d7474756d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x72656c6f6f632d31) &&
                         cStack_3d0 == ']') {
                  mutt_pa1_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x61702d7474756d5b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x72656c6f6f632d32) &&
                         cStack_3d0 == ']') {
                  mutt_pa2_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x2d7277702d78745b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6c6f6f632d316170) &&
                         CONCAT17(uStack_3ce,
                                  CONCAT16(uStack_3cf,
                                           CONCAT15(cStack_3d0,
                                                    CONCAT14(uStack_3d1,
                                                             CONCAT13(uStack_3d2,
                                                                      CONCAT12(uStack_3d3,
                                                                               CONCAT11(uStack_3d4,
                                                                                        uStack_3d5))
                                                                     ))))) == 0x5d72656c6f6f632d) {
                  tx_pwr_pa1_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x2d7277702d78745b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6c6f6f632d326170) &&
                         CONCAT17(uStack_3ce,
                                  CONCAT16(uStack_3cf,
                                           CONCAT15(cStack_3d0,
                                                    CONCAT14(uStack_3d1,
                                                             CONCAT13(uStack_3d2,
                                                                      CONCAT12(uStack_3d3,
                                                                               CONCAT11(uStack_3d4,
                                                                                        uStack_3d5))
                                                                     ))))) == 0x5d72656c6f6f632d) {
                  tx_pwr_pa2_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
                else if ((CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0)))
                          == 0x66666f2d6763735b &&
                         CONCAT17(uStack_3d1,
                                  CONCAT16(uStack_3d2,
                                           CONCAT15(uStack_3d3,
                                                    CONCAT14(uStack_3d4,
                                                             CONCAT13(uStack_3d5,
                                                                      CONCAT21(uStack_3d7,local_3d8)
                                                                     ))))) == 0x6f6f632d3261702d) &&
                         CONCAT13(uStack_3cd,CONCAT12(uStack_3ce,CONCAT11(uStack_3cf,cStack_3d0)))
                         == 0x5d72656c) {
                  scg_off_pa2_cooler_parser(__stream_00,&local_3e0,iVar9);
                }
              }
            }
LAB_00108e8c:
            pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
          }
          if ((DAT_0012e9e4 == '\x01') && (iVar9 = set_hw_reboot(1), iVar9 != 0)) {
            __android_log_print(6,"thermal_core","Failed to enable HW reboot\n");
          }
          fclose(__stream_00);
          fputs((char *)&local_240,__stream);
          uRam000000000012e9ac = 0;
          _DAT_0012e9a4 = 0;
          uRam000000000012e9bc = 0;
          _DAT_0012e9b4 = 0;
          uRam000000000012e9cc = 0;
          _DAT_0012e9c4 = 0;
          uRam000000000012e9dc = 0;
          _DAT_0012e9d4 = 0;
          uRam000000000012e968 = 0;
          _DAT_0012e960 = 0;
          uRam000000000012e978 = 0;
          _DAT_0012e970 = 0;
          uRam000000000012e988 = 0;
          _DAT_0012e980 = 0;
          uRam000000000012e998 = 0;
          _DAT_0012e990 = 0;
          uVar13 = __strlen_chk(&local_240,0x40);
          __strncpy_chk2(&DAT_0012e9a4,&local_240,uVar13,0x40,0x40);
          sVar12 = strlen(param_1);
          __strncpy_chk(&DAT_0012e960,param_1,sVar12,0x40);
          set_ttj(DAT_0012e888);
          uVar25 = DAT_0012e888;
          uVar10 = DAT_0012e8bc;
          if ((int)DAT_0012e888 <= (int)DAT_0012e8bc) {
            uVar10 = DAT_0012e888;
          }
          uStack_c8 = 0;
          local_d0 = 0;
          uStack_b8 = 0;
          local_c0 = 0;
          uStack_180 = 0;
          uVar5 = DAT_0012e888;
          if (DAT_0012e8b0 != 0) {
            uVar5 = uVar10;
          }
          local_1c0[5] = 0;
          local_1c0[4] = 0;
          uStack_188 = 0;
          local_182 = 0;
          local_1c0[6] = 0;
          uVar10 = DAT_0012e888;
          if (DAT_0012e8b4 != 1) {
            uVar10 = uVar5;
          }
          local_1c0[1] = 0;
          local_1c0[0] = 0;
          local_1c0[3] = 0;
          local_1c0[2] = 0;
          snprintf((char *)&local_d0,0x20,(char *)0x20,"MAX_TTJ %d %d %d",(ulong)DAT_0012e888,
                   (ulong)uVar10,(ulong)uVar5);
          snprintf((char *)local_1c0,0x46,(char *)0x46,"/sys/kernel/thermal/max_ttj");
          node_write(&local_d0,local_1c0);
          piVar16 = (int *)PTR_DAT_0012d278;
          uVar10 = uVar5;
          if (DAT_0012e8b4 == 1) {
            uVar10 = uVar25;
          }
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","set_max_ttj %d %d %d\n",uVar25,uVar10,uVar5);
          }
          uVar10 = DAT_0012e88c;
          uStack_180 = 0;
          uStack_c8 = 0;
          local_d0 = 0;
          uStack_b8 = 0;
          local_c0 = 0;
          local_1c0[5] = 0;
          local_1c0[4] = 0;
          uStack_188 = 0;
          local_182 = 0;
          local_1c0[6] = 0;
          local_1c0[1] = 0;
          local_1c0[0] = 0;
          local_1c0[3] = 0;
          local_1c0[2] = 0;
          snprintf((char *)&local_d0,0x20,(char *)0x20,"MIN_TTJ %d",(ulong)DAT_0012e88c);
          snprintf((char *)local_1c0,0x46,(char *)0x46,"/sys/kernel/thermal/min_ttj");
          node_write(&local_d0,local_1c0);
          if (*piVar16 == 1) {
            __android_log_print(4,"thermal_core","set_min_ttj %d\n",uVar10);
          }
          uStack_a8 = 0;
          local_b0 = 0;
          uStack_98 = 0;
          local_a0 = 0;
          uStack_c8 = 0;
          local_d0 = 0;
          uStack_b8 = 0;
          local_c0 = 0;
          uStack_180 = 0;
          local_1c0[5] = 0;
          local_1c0[4] = 0;
          uStack_188 = 0;
          local_182 = 0;
          local_1c0[6] = 0;
          local_1c0[1] = 0;
          local_1c0[0] = 0;
          local_1c0[3] = 0;
          local_1c0[2] = 0;
          snprintf((char *)&local_d0,0x40,(char *)0x40,"MIN_FREQ %d %d %d %d",(ulong)DAT_0012e8c8,
                   (ulong)_DAT_0012e8cc,(ulong)DAT_0012e8d0,(ulong)_DAT_0012e8d4);
          snprintf((char *)local_1c0,0x46,(char *)0x46,"/sys/kernel/thermal/min_throttle_freq");
          node_write(&local_d0,local_1c0);
          if (*piVar16 == 1) {
            __android_log_print(4,"thermal_core","min_throttle_freq %d %d %d %d\n",DAT_0012e8c8,
                                _DAT_0012e8cc,DAT_0012e8d0,_DAT_0012e8d4);
          }
          iVar9 = strncmp(param_1,"thermal_policy_08.conf",0x16);
          if (iVar9 == 0) {
            uVar26 = 0;
            DAT_0012f380 = 1;
          }
          else {
            uVar26 = 0;
            DAT_0012f380 = 0;
            DAT_0012f37c = 0;
          }
        }
        iVar9 = fileno(__stream);
        iVar9 = flock(iVar9,8);
        if (iVar9 != 0) {
          pcVar14 = "Failed to unlock %s\n";
          goto LAB_0010b364;
        }
      }
      else {
        uVar26 = 0xffffffff;
        pcVar14 = "Failed to lock %s\n";
LAB_0010b364:
        __android_log_print(6,"thermal_core",pcVar14,"/data/vendor/thermal/.current_tp");
      }
      fclose(__stream);
      puVar30 = DAT_0012e920;
      puVar29 = DAT_0012e920;
      if (*piVar16 == 1) {
        __android_log_print(4,"thermal_core","thermal instance\n");
        puVar29 = DAT_0012e920;
      }
      for (; DAT_0012e920 = puVar29, puVar30 != (uint *)0x0; puVar30 = *(uint **)(puVar30 + 10)) {
        if (*piVar16 == 1) {
          __android_log_print(4,"thermal_core",
                              "%d: TZ %s, CL %s, target %u, th %d, hy %d, mode %u\n",*puVar30,
                              DAT_0012ea68 + (ulong)puVar30[1] * 0x50 + 4,
                              *(undefined8 *)(puVar30 + 2),puVar30[4],puVar30[5],puVar30[6],
                              puVar30[7]);
        }
        puVar29 = DAT_0012e920;
      }
      if (puVar29 == (uint *)0x0) {
        puVar30 = malloc(0);
      }
      else {
        sVar12 = 0;
        lVar31 = 0;
        puVar30 = puVar29;
        do {
          puVar30 = *(uint **)(puVar30 + 10);
          lVar31 = lVar31 + 1;
          sVar12 = sVar12 + 4;
        } while (puVar30 != (uint *)0x0);
        puVar30 = malloc(sVar12);
        puVar24 = puVar30;
        do {
          if (puVar29[7] == 0) {
            uVar10 = puVar29[1];
          }
          else {
            uVar10 = 0xffffffff;
          }
          *puVar24 = uVar10;
          puVar29 = *(uint **)(puVar29 + 10);
          puVar24 = puVar24 + 1;
        } while (puVar29 != (uint *)0x0);
        uVar21 = 0;
        do {
          if (*piVar16 == 1) {
            __android_log_print(4,"thermal_core","tz_id_array[%d]:%d\n",uVar21 & 0xffffffff,
                                puVar30[uVar21]);
          }
          uVar21 = uVar21 + 1;
          lVar31 = lVar31 + -1;
          puVar29 = DAT_0012e920;
        } while (lVar31 != 0);
        for (; puVar29 != (uint *)0x0; puVar29 = *(uint **)(puVar29 + 10)) {
          uVar13 = 1;
          uVar10 = *puVar29;
          puVar29[8] = 1;
          if (uVar10 != 0) {
            uVar13 = 1;
            puVar24 = puVar30;
            uVar21 = (ulong)uVar10;
            do {
              if (*puVar24 == puVar29[1]) {
                uVar13 = 0;
                puVar29[8] = 0;
              }
              uVar21 = uVar21 - 1;
              puVar24 = puVar24 + 1;
            } while (uVar21 != 0);
          }
          if (*piVar16 == 1) {
            __android_log_print(4,"thermal_core","%d: polling_tz_flag=%d\n",(ulong)uVar10,uVar13);
          }
        }
      }
      if (puVar30 != (uint *)0x0) {
        free(puVar30);
      }
      iVar9 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e92c);
      goto LAB_00108cec;
    }
    pcVar14 = "Same tp_name %s, skip...\n";
    param_1 = (char *)&local_240;
  }
  __android_log_print(4,"thermal_core",pcVar14,param_1);
  iVar9 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_0012e92c);
  uVar26 = 0;
LAB_00108cec:
  if (*(long *)(lVar6 + 0x28) == local_78) {
    return uVar26;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar9);
LAB_0010a160:
  if (*(int *)PTR_DAT_0012d278 == 1) {
    __android_log_print(4,"thermal_core","List items are more than MAX_NUM_PTRS %d\n",0x14);
  }
LAB_0010a190:
  local_500 = local_500 & 0xffffffff;
  uVar21 = 0;
  if (uVar10 < 2) {
    uVar10 = 1;
  }
  do {
    pcVar14 = (char *)local_1c0[uVar21];
    sVar12 = strlen(pcVar14);
    uVar25 = (uint)sVar12;
    if (0 < (int)uVar25) {
      uVar28 = sVar12 & 0xffffffff;
      do {
        uVar25 = uVar25 - 1;
        if (0x20 < (byte)pcVar14[uVar25] ||
            (1L << ((ulong)(byte)pcVar14[uVar25] & 0x3f) & 0x100002400U) == 0) goto LAB_0010a204;
        uVar22 = uVar28 - 1;
        bVar20 = 0 < (long)uVar28;
        uVar28 = uVar22;
      } while (uVar22 != 0 && bVar20);
      uVar28 = 0;
LAB_0010a204:
      pcVar14[(int)uVar28] = '\0';
    }
    if ((DAT_0012ea68 == 0) ||
       (lVar31 = *(long *)(DAT_0012ea68 + local_538 * 0x50 + 0x48), lVar31 == 0)) {
      uVar26 = 0xffffffff;
    }
    else {
      if (*(int *)(DAT_0012ea68 + local_538 * 0x50 + 0x40) != 0) {
        sVar12 = strlen(pcVar14);
        lVar23 = 0;
        uVar28 = 0;
        lVar27 = DAT_0012ea68 + local_538 * 0x50;
        plVar3 = (long *)(lVar27 + 0x48);
        while( true ) {
          sVar15 = strlen((char *)(lVar31 + lVar23));
          if (((int)sVar15 == (int)sVar12) &&
             (iVar11 = strncmp((char *)(*plVar3 + lVar23),pcVar14,(long)(int)sVar15), iVar11 == 0))
          goto LAB_0010a300;
          uVar28 = uVar28 + 1;
          if (*(uint *)(lVar27 + 0x40) <= uVar28) break;
          lVar31 = *plVar3;
          lVar23 = lVar23 + 0x17;
        }
      }
      __android_log_print(6,"thermal_core","Failed to find cooler index of %s in thermal zone %d\n",
                          pcVar14,local_538);
      uVar28 = 0xffffffff;
LAB_0010a300:
      uVar26 = (undefined4)uVar28;
    }
    iVar11 = *(int *)PTR_DAT_0012d278;
    *(undefined4 *)((long)&local_d0 + uVar21 * 4) = uVar26;
    if (iVar11 == 1) {
      __android_log_print(4,"thermal_core","Cooler %s, cd_id %d\n",pcVar14,uVar26);
    }
    uVar21 = uVar21 + 1;
  } while (uVar21 != uVar10);
LAB_0010a350:
  do {
    uVar21 = ftell(__stream_00);
    do {
      pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
      if (pcVar14 == (char *)0x0) goto LAB_0010a7ec;
      uVar10 = __strlen_chk(&local_3e0,0x100);
      if (0 < (int)uVar10) {
        uVar28 = (ulong)uVar10;
        do {
          uVar10 = uVar10 - 1;
          if (0x20 < *(byte *)((long)&local_3e0 + (ulong)uVar10) ||
              (1L << ((ulong)*(byte *)((long)&local_3e0 + (ulong)uVar10) & 0x3f) & 0x100002400U) ==
              0) goto LAB_0010a3b0;
          uVar22 = uVar28 - 1;
          bVar20 = 0 < (long)uVar28;
          uVar28 = uVar22;
        } while (uVar22 != 0 && bVar20);
        uVar28 = 0;
LAB_0010a3b0:
        *(undefined1 *)((long)&local_3e0 + (long)(int)uVar28) = 0;
      }
      if (iVar9 == 2) {
        sVar12 = strnlen((char *)&local_3e0,0x200);
        if (sVar12 != 0) {
          uVar28 = 1;
          uVar22 = 0;
          do {
            uVar33 = uVar28;
            bVar19 = *(byte *)((long)&local_3e0 + uVar22);
            if (bVar19 - 0x20 < 0x5b) {
              uVar10 = ((uint)bVar19 - ((int)uVar22 + (int)(uVar22 / 5) * -5)) + 0x3b;
              bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
            }
            *(byte *)((long)&local_3e0 + uVar22) = bVar19;
            sVar12 = strnlen((char *)&local_3e0,0x200);
            uVar28 = (ulong)((int)uVar33 + 1);
            uVar22 = uVar33;
          } while (uVar33 < sVar12);
        }
      }
      else if ((iVar9 == 1) && (sVar12 = strnlen((char *)&local_3e0,0x200), sVar12 != 0)) {
        uVar28 = 1;
        uVar22 = 0;
        do {
          uVar33 = uVar28;
          bVar19 = *(byte *)((long)&local_3e0 + uVar22);
          if (bVar19 - 0x20 < 0x5b) {
            uVar10 = ((uint)bVar19 - ((int)uVar22 + (int)(uVar22 / 10) * -10)) + 0x3b;
            bVar19 = (char)uVar10 + (char)((uVar10 & 0xff) / 0x5b) * -0x5b + 0x20;
          }
          *(byte *)((long)&local_3e0 + uVar22) = bVar19;
          sVar12 = strnlen((char *)&local_3e0,0x200);
          uVar28 = (ulong)((int)uVar33 + 1);
          uVar22 = uVar33;
        } while (uVar33 < sVar12);
      }
      iVar11 = __strlen_chk(&local_3e0,0x100);
    } while ((iVar11 == 0) || ((local_3e0 & 0xff) == 0x23));
    if (((local_3e0 & 0xff) == 0x5b) && (*(char *)((long)&local_3e0 + (long)(iVar11 + -1)) == ']'))
    break;
    if (*(int *)PTR_DAT_0012d278 == 1) {
      __android_log_print(4,"thermal_core","line: %s\n",&local_3e0);
    }
    if (local_3e0 != 0x6c6f6f63 || CONCAT11(uStack_3db,cStack_3dc) != 0x7265) break;
    pbVar34 = (byte *)&local_3e0;
    uVar10 = local_3e0 & 0xff;
    pbVar32 = pbVar34;
    if ((byte)local_3e0 != 0) {
      do {
        if (uVar10 == 0x3d) {
          pbVar34 = pbVar32 + 1;
          *pbVar32 = 0;
          break;
        }
        pbVar34 = pbVar32 + 1;
        uVar10 = (uint)*pbVar34;
        pbVar32 = pbVar34;
      } while (uVar10 != 0);
    }
    for (; (bVar19 = *pbVar34, bVar19 == 9 || (bVar19 == 0x20)); pbVar34 = pbVar34 + 1) {
    }
    if (bVar19 == 0x5b) {
      bVar20 = true;
      local_120 = local_120 & 0xffffffff00000000;
LAB_0010a5d8:
      bVar19 = *pbVar34;
      if (0x5a < bVar19) {
        if ((bVar19 != 0x5d) && (bVar19 != 0x5b)) goto LAB_0010a5fc;
LAB_0010a5d0:
        *pbVar34 = 0;
LAB_0010a5d4:
        pbVar34 = pbVar34 + 1;
        goto LAB_0010a5d8;
      }
      if (bVar19 == 0x2c) {
        bVar20 = true;
        goto LAB_0010a5d0;
      }
      if (bVar19 == 0) {
        local_500 = local_120 & 0xffffffff;
        goto LAB_0010a63c;
      }
LAB_0010a5fc:
      if ((!bVar20) || (bVar19 == 0x20)) goto LAB_0010a5d4;
      local_500 = local_120 & 0xffffffff;
      if ((uint)local_120 < 0x14) {
        local_1c0[local_500] = (ulong)pbVar34;
        bVar20 = false;
        local_120 = CONCAT44(local_120._4_4_,(uint)local_120 + 1);
        pbVar34 = pbVar34 + 1;
        goto LAB_0010a5d8;
      }
      if (*(int *)PTR_DAT_0012d278 == 1) {
        __android_log_print(4,"thermal_core","List items are more than MAX_NUM_PTRS %d\n",0x14);
      }
LAB_0010a680:
      uVar21 = 0;
      uVar28 = local_500;
      if ((uint)local_500 < 2) {
        uVar28 = 1;
      }
      do {
        iVar11 = *(int *)((long)&local_d0 + uVar21 * 4);
        if (iVar11 != -1) {
          if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) ==
              0x775f72656c6f6f63 &&
              CONCAT17(uStack_3d4,
                       CONCAT16(uStack_3d5,
                                CONCAT24(uStack_3d7,
                                         CONCAT13(local_3d8,CONCAT21(uStack_3da,uStack_3db))))) ==
              0x7468676965775f72) {
            snprintf((char *)&local_110,0x40,(char *)0x40,
                     "/sys/class/thermal/thermal_zone%d/cdev%d_weight",local_538);
          }
          else {
            if (CONCAT26(uStack_3da,CONCAT15(uStack_3db,CONCAT14(cStack_3dc,local_3e0))) !=
                0x745f72656c6f6f63 ||
                CONCAT17(uStack_3d1,
                         CONCAT16(uStack_3d2,
                                  CONCAT15(uStack_3d3,
                                           CONCAT14(uStack_3d4,
                                                    CONCAT13(uStack_3d5,
                                                             CONCAT21(uStack_3d7,local_3d8)))))) !=
                0x706d65745f706972) break;
            snprintf((char *)&local_110,0x40,(char *)0x40,
                     "/sys/class/thermal/thermal_zone%d/trip_point_%s_temp",local_538,
                     *(long *)(DAT_0012ea68 + local_510 * 0x50 + 0x48) + (long)iVar11 * 0x17 + 0x14)
            ;
          }
          pcVar14 = (char *)local_1c0[uVar21];
          sVar12 = strlen(pcVar14);
          uVar10 = (uint)sVar12;
          if (0 < (int)uVar10) {
            uVar22 = sVar12 & 0xffffffff;
            do {
              uVar10 = uVar10 - 1;
              if (0x20 < (byte)pcVar14[uVar10] ||
                  (1L << ((ulong)(byte)pcVar14[uVar10] & 0x3f) & 0x100002400U) == 0)
              goto LAB_0010a6a0;
              uVar33 = uVar22 - 1;
              bVar20 = 0 < (long)uVar22;
              uVar22 = uVar33;
            } while (uVar33 != 0 && bVar20);
            uVar22 = 0;
LAB_0010a6a0:
            pcVar14[(int)uVar22] = '\0';
          }
          node_write(pcVar14,&local_110);
        }
        uVar21 = uVar21 + 1;
      } while (uVar21 != uVar28);
    }
    else {
LAB_0010a63c:
      if ((int)local_500 != 0) goto LAB_0010a680;
      local_500 = 0;
    }
  } while( true );
LAB_0010a7ec:
  if ((int)uVar21 < 0) {
    pcVar14 = "Negative file position %s\n";
  }
  else {
    iVar11 = fseek(__stream_00,uVar21 & 0xffffffff,0);
    if (iVar11 != -1) goto LAB_0010a88c;
    pcVar14 = "fseek failed: %s\n";
  }
  piVar16 = (int *)__errno();
  pcVar17 = strerror(*piVar16);
  __android_log_print(6,"thermal_core",pcVar14,pcVar17);
LAB_0010a88c:
  local_508 = ftell(__stream_00);
  iVar11 = (int)local_538;
LAB_0010a8a0:
  bVar8 = iVar11 == -1;
  local_510 = (long)iVar11;
LAB_00109938:
  pcVar14 = fgets((char *)&local_3e0,0x100,__stream_00);
  bVar20 = false;
  if (pcVar14 == (char *)0x0) goto LAB_0010adf4;
  goto LAB_00109700;
}
