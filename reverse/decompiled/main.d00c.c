/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: main   VMA: 0xd00c   (see reverse/symbols.csv)
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(void)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  void *pvVar13;
  void *pvVar14;
  long lVar15;
  FILE *pFVar16;
  byte *pbVar17;
  char *pcVar18;
  size_t sVar19;
  char *pcVar20;
  int *piVar21;
  ssize_t sVar22;
  byte bVar23;
  undefined4 uVar24;
  char *pcVar25;
  ulong uVar26;
  undefined4 *puVar27;
  ulong uVar28;
  long lVar29;
  byte *pbVar30;
  long *plVar31;
  ulong uVar32;
  undefined8 *puVar33;
  uint local_8ac;
  ulong local_8a8;
  uint local_878;
  void *local_870;
  pthread_t local_850;
  pthread_t local_848;
  pthread_t pStack_840;
  pthread_t local_838;
  pthread_t pStack_830;
  undefined8 local_828;
  undefined8 local_820;
  undefined8 uStack_818;
  undefined8 uStack_810;
  undefined8 uStack_808;
  undefined8 local_800;
  undefined8 uStack_7f8;
  undefined8 uStack_7f0;
  undefined8 uStack_7e8;
  undefined8 local_7e0;
  undefined8 uStack_7d8;
  undefined8 uStack_7d0;
  undefined8 uStack_7c8;
  undefined8 local_7c0;
  undefined8 uStack_7b8;
  undefined8 uStack_7b0;
  undefined8 uStack_7a8;
  undefined5 local_7a0;
  undefined3 uStack_79b;
  undefined5 uStack_798;
  undefined3 uStack_793;
  undefined8 local_790;
  undefined8 uStack_788;
  undefined8 local_780;
  undefined8 uStack_778;
  undefined8 local_770;
  undefined8 uStack_768;
  undefined8 uStack_760;
  undefined8 uStack_758;
  undefined8 local_750;
  undefined8 uStack_748;
  undefined8 uStack_740;
  undefined8 uStack_738;
  undefined8 local_730;
  undefined8 uStack_728;
  undefined8 uStack_720;
  undefined8 uStack_718;
  undefined8 local_710;
  undefined8 uStack_708;
  undefined8 uStack_700;
  undefined8 uStack_6f8;
  undefined8 local_6f0;
  undefined8 uStack_6e8;
  undefined8 uStack_6e0;
  undefined8 uStack_6d8;
  undefined8 local_6d0;
  undefined8 uStack_6c8;
  undefined8 uStack_6c0;
  undefined8 uStack_6b8;
  undefined8 local_6b0;
  undefined8 uStack_6a8;
  byte local_6a0 [8];
  int iStack_698;
  undefined4 uStack_694;
  undefined8 local_690;
  undefined8 uStack_688;
  undefined8 local_680;
  undefined8 uStack_678;
  undefined8 local_670;
  undefined8 uStack_668;
  undefined8 uStack_660;
  undefined8 uStack_658;
  undefined8 local_650;
  undefined8 uStack_648;
  undefined8 uStack_640;
  undefined8 uStack_638;
  undefined8 local_630;
  undefined8 uStack_628;
  undefined8 uStack_620;
  undefined8 uStack_618;
  undefined8 local_610;
  undefined8 uStack_608;
  undefined8 uStack_600;
  undefined8 uStack_5f8;
  undefined8 local_5f0;
  undefined8 uStack_5e8;
  undefined8 uStack_5e0;
  undefined8 uStack_5d8;
  undefined8 local_5d0;
  undefined8 uStack_5c8;
  undefined8 uStack_5c0;
  undefined8 uStack_5b8;
  undefined8 local_5b0;
  undefined8 uStack_5a8;
  undefined8 uStack_5a0;
  undefined8 uStack_598;
  undefined8 local_590;
  undefined8 uStack_588;
  undefined8 uStack_580;
  undefined8 uStack_578;
  undefined8 local_570;
  undefined8 uStack_568;
  undefined8 uStack_560;
  undefined8 uStack_558;
  undefined8 local_550;
  undefined8 uStack_548;
  undefined8 uStack_540;
  undefined8 uStack_538;
  undefined8 local_530;
  undefined8 uStack_528;
  undefined8 uStack_520;
  undefined8 uStack_518;
  undefined8 local_510 [20];
  ulong local_470;
  char *local_460 [20];
  ulong local_3c0;
  undefined8 local_3b0;
  undefined8 uStack_3a8;
  undefined8 local_3a0;
  undefined8 uStack_398;
  undefined8 local_390;
  undefined8 uStack_388;
  undefined8 local_380;
  undefined8 uStack_378;
  undefined8 local_370;
  undefined8 uStack_368;
  undefined8 local_360;
  undefined8 uStack_358;
  undefined8 local_350;
  undefined8 uStack_348;
  undefined8 local_340;
  undefined8 uStack_338;
  undefined8 local_330;
  undefined8 uStack_328;
  undefined8 local_320;
  undefined8 uStack_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  undefined8 uStack_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined8 local_2b0;
  long lStack_2a8;
  ulong local_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined8 uStack_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined8 local_240;
  undefined8 uStack_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  long local_88;
  
  lVar3 = tpidr_el0;
  local_88 = *(long *)(lVar3 + 0x28);
  uStack_7b8 = 0;
  local_7c0 = 0;
  uStack_7a8 = 0;
  uStack_7b0 = 0;
  uStack_7d8 = 0;
  local_7e0 = 0;
  uStack_7c8 = 0;
  uStack_7d0 = 0;
  uStack_7f8 = 0;
  local_800 = 0;
  uStack_7e8 = 0;
  uStack_7f0 = 0;
  uStack_818 = 0;
  local_820 = 0;
  uStack_808 = 0;
  uStack_810 = 0;
  local_838 = 0;
  pStack_830 = 0;
  local_848 = 0;
  pStack_840 = 0;
  local_850 = 0;
  uVar8 = get_kernel_version();
  if (uVar8 < 51000) {
    __android_log_print(4,"thermal_core","Wrong kernel version: %d, exit\n",uVar8);
LAB_0010d088:
    uVar24 = 0;
    goto LAB_0010fa54;
  }
  __android_log_print(4,"thermal_core","Hello thermal core deamon\n");
  uStack_778 = 0;
  local_780 = 0;
  uStack_768 = 0;
  local_770 = 0;
  uStack_798 = 0;
  uStack_793 = 0;
  local_7a0 = 0;
  uStack_79b = 0;
  uStack_788 = 0;
  local_790 = 0;
  uStack_278 = 0;
  local_280 = 0;
  uStack_288 = 0;
  local_290 = 0;
  uVar26 = 0xffffffffffffffff;
  uStack_298 = 0;
  local_2a0 = 0;
  lStack_2a8 = 0;
  local_2b0 = 0;
  do {
    uVar26 = uVar26 + 1;
    snprintf((char *)&local_2b0,0x40,(char *)0x40,"/sys/class/thermal/thermal_zone%d",
             uVar26 & 0xffffffff);
    iVar9 = access((char *)&local_2b0,0);
  } while (iVar9 == 0);
  DAT_0012ea60 = (uint)uVar26;
  pvVar13 = calloc(uVar26,0x50);
  uVar5 = DAT_00101f18;
  if (pvVar13 == (void *)0x0) {
    __android_log_print(6,"thermal_core","Failed to allocate memory for tzs\n");
joined_r0x0010d6d4:
    if (DAT_0012ea68 != (void *)0x0) {
LAB_0010db08:
      if (DAT_0012ea60 != 0) {
        lVar15 = 0;
        uVar26 = 1;
        while( true ) {
          pvVar13 = *(void **)((long)DAT_0012ea68 + lVar15 + 0x38);
          if (pvVar13 != (void *)0x0) {
            free(pvVar13);
          }
          pvVar13 = *(void **)((long)DAT_0012ea68 + lVar15 + 0x48);
          if (pvVar13 != (void *)0x0) {
            free(pvVar13);
          }
          if (DAT_0012ea60 <= uVar26) break;
          uVar26 = uVar26 + 1;
          lVar15 = lVar15 + 0x50;
        }
      }
      free(DAT_0012ea68);
    }
  }
  else {
    DAT_0012ea68 = pvVar13;
    if ((uint)uVar26 != 0) {
      bVar2 = false;
      uVar32 = 0;
      do {
        puVar27 = (undefined4 *)((long)pvVar13 + uVar32 * 0x50);
        *puVar27 = (int)uVar32;
        snprintf((char *)&local_7a0,0x40,(char *)0x40,"/sys/class/thermal/thermal_zone%d/type",
                 uVar32 & 0xffffffff);
        node_read(&local_7a0,puVar27 + 1,0x14);
        bVar4 = bVar2;
        do {
          bVar2 = bVar4;
          uStack_3a8 = 0;
          local_3b0 = 0;
          uStack_278 = 0;
          local_280 = 0;
          uStack_288 = 0;
          local_290 = 0;
          uStack_298 = 0;
          local_2a0 = 0;
          lStack_2a8 = 0;
          local_2b0 = 0;
          *(undefined4 *)((long)DAT_0012ea68 + uVar32 * 0x50 + 0x2c) = 0;
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","check tz_mode_ready\n");
          }
          snprintf((char *)&local_2b0,0x40,(char *)0x40,"/sys/class/thermal/thermal_zone%d/mode",
                   uVar32 & 0xffffffff);
          node_read(&local_2b0,&local_3b0,0x10);
          piVar21 = (int *)((long)DAT_0012ea68 + uVar32 * 0x50 + 0x2c);
          if ((int)local_3b0 == 0x62616e65 && local_3b0._4_2_ == 0x656c) {
            *piVar21 = 1;
            goto LAB_0010d2f4;
          }
          if (*piVar21 == 1) goto LAB_0010d2f4;
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","wait tz:%d tz_mode_ready ...\n",
                                uVar32 & 0xffffffff);
          }
          sleep(1);
          bVar4 = true;
        } while (!bVar2);
        __android_log_print(6,"thermal_core","wait TZ:%d tz_mode_ready timeout\n",
                            uVar32 & 0xffffffff);
LAB_0010d2f4:
        uStack_378 = 0;
        local_380 = 0;
        uStack_388 = 0;
        local_390 = 0;
        uStack_398 = 0;
        local_3a0 = 0;
        uStack_3a8 = 0;
        local_3b0 = 0;
        uStack_678 = 0;
        local_680 = 0;
        uStack_668 = 0;
        local_670 = 0;
        iStack_698 = 0;
        uStack_694 = 0;
        local_6a0[0] = 0;
        local_6a0[1] = 0;
        local_6a0[2] = '\0';
        local_6a0[3] = 0;
        local_6a0[4] = '\0';
        local_6a0[5] = 0;
        local_6a0[6] = 0;
        local_6a0[7] = 0;
        uStack_688 = 0;
        local_690 = 0;
        local_460[0] = (char *)0x0;
        uStack_278 = 0;
        local_280 = 0;
        uStack_288 = 0;
        local_290 = 0;
        uVar28 = 0xffffffffffffffff;
        uStack_298 = 0;
        local_2a0 = 0;
        lStack_2a8 = 0;
        local_2b0 = 0;
        lVar15 = 0;
        do {
          lVar29 = lVar15;
          uVar28 = uVar28 + 1;
          snprintf((char *)&local_2b0,0x40,(char *)0x40,
                   "/sys/class/thermal/thermal_zone%d/trip_point_%d_temp",uVar32 & 0xffffffff,
                   uVar28 & 0xffffffff);
          iVar9 = access((char *)&local_2b0,0);
          lVar15 = lVar29 + 1;
        } while (iVar9 == 0);
        *(int *)((long)pvVar13 + uVar32 * 0x50 + 0x34) = (int)uVar28;
        if ((int)uVar28 != 0) {
          pvVar14 = calloc(uVar28,8);
          if (pvVar14 == (void *)0x0) {
            __android_log_print(6,"thermal_core","Failed to allocate memory for trips\n");
            if (DAT_0012ea68 == (void *)0x0) goto LAB_0010fa50;
            goto LAB_0010db08;
          }
          uVar8 = 0;
          puVar27 = (undefined4 *)((long)pvVar14 + 4);
          *(void **)((long)pvVar13 + uVar32 * 0x50 + 0x38) = pvVar14;
          do {
            snprintf((char *)&local_3b0,0x40,(char *)0x40,
                     "/sys/class/thermal/thermal_zone%d/trip_point_%d_temp",uVar32 & 0xffffffff,
                     (ulong)uVar8);
            node_read(&local_3b0,local_6a0,0x40);
            lVar15 = strtol((char *)local_6a0,local_460,10);
            puVar27[-1] = (int)lVar15;
            snprintf((char *)&local_3b0,0x40,(char *)0x40,
                     "/sys/class/thermal/thermal_zone%d/trip_point_%d_type",uVar32 & 0xffffffff,
                     (ulong)uVar8);
            node_read(&local_3b0,local_6a0,0x40);
            if (CONCAT17(local_6a0[7],
                         CONCAT16(local_6a0[6],
                                  CONCAT15(local_6a0[5],
                                           CONCAT14(local_6a0[4],
                                                    CONCAT13(local_6a0[3],
                                                             CONCAT12(local_6a0[2],
                                                                      CONCAT11(local_6a0[1],
                                                                               local_6a0[0])))))))
                == 0x6c61636974697263) {
              *puVar27 = 3;
            }
            else {
              if (CONCAT13(local_6a0[3],CONCAT12(local_6a0[2],CONCAT11(local_6a0[1],local_6a0[0])))
                  == 0x73736170 &&
                  CONCAT13(local_6a0[6],CONCAT12(local_6a0[5],CONCAT11(local_6a0[4],local_6a0[3])))
                  == 0x65766973) {
                uVar24 = 1;
              }
              else if (CONCAT11(local_6a0[1],local_6a0[0]) == 0x6f68 && local_6a0[2] == 't') {
                uVar24 = 2;
              }
              else {
                if (CONCAT13(local_6a0[3],CONCAT12(local_6a0[2],CONCAT11(local_6a0[1],local_6a0[0]))
                            ) == 0x69746361 && CONCAT11(local_6a0[5],local_6a0[4]) == 0x6576) {
                  *puVar27 = 0;
                  goto LAB_0010d39c;
                }
                uVar24 = 4;
              }
              *puVar27 = uVar24;
            }
LAB_0010d39c:
            puVar27 = puVar27 + 2;
            lVar29 = lVar29 + -1;
            uVar8 = uVar8 + 1;
          } while (lVar29 != 0);
        }
        uStack_378 = 0;
        local_380 = 0;
        uStack_388 = 0;
        local_390 = 0;
        uStack_398 = 0;
        local_3a0 = 0;
        uStack_3a8 = 0;
        local_3b0 = 0;
        uStack_278 = 0;
        local_280 = 0;
        uStack_288 = 0;
        local_290 = 0;
        uVar28 = 0xffffffffffffffff;
        uStack_298 = 0;
        local_2a0 = 0;
        lStack_2a8 = 0;
        local_2b0 = 0;
        lVar15 = 0;
        do {
          lVar29 = lVar15;
          uVar28 = uVar28 + 1;
          snprintf((char *)&local_2b0,0x40,(char *)0x40,"/sys/class/thermal/thermal_zone%d/cdev%d",
                   uVar32 & 0xffffffff,uVar28 & 0xffffffff);
          iVar9 = access((char *)&local_2b0,0);
          lVar15 = lVar29 + 1;
        } while (iVar9 == 0);
        *(int *)((long)pvVar13 + uVar32 * 0x50 + 0x40) = (int)uVar28;
        if ((int)uVar28 != 0) {
          pvVar14 = calloc(uVar28,0x17);
          if (pvVar14 == (void *)0x0) {
            __android_log_print(6,"thermal_core","Failed to allocate memory for cds\n");
            goto joined_r0x0010d6d4;
          }
          uVar8 = 0;
          *(void **)((long)pvVar13 + uVar32 * 0x50 + 0x48) = pvVar14;
          do {
            snprintf((char *)&local_3b0,0x40,(char *)0x40,
                     "/sys/class/thermal/thermal_zone%d/cdev%d/type",uVar32 & 0xffffffff,
                     (ulong)uVar8);
            node_read(&local_3b0,pvVar14,0x14);
            snprintf((char *)&local_3b0,0x40,(char *)0x40,
                     "/sys/class/thermal/thermal_zone%d/cdev%d_trip_point",uVar32 & 0xffffffff,
                     (ulong)uVar8);
            node_read(&local_3b0,(long)pvVar14 + 0x14,3);
            lVar29 = lVar29 + -1;
            pvVar14 = (void *)((long)pvVar14 + 0x17);
            uVar8 = uVar8 + 1;
          } while (lVar29 != 0);
        }
        pvVar14 = DAT_0012ea68;
        uVar28 = uVar32 + 1;
        *(undefined8 *)((long)DAT_0012ea68 + uVar32 * 0x50 + 0x1c) = uVar5;
        *(undefined4 *)((long)pvVar14 + uVar32 * 0x50 + 0x24) = 10;
        uVar32 = uVar28;
      } while (uVar26 != uVar28);
    }
    uStack_378 = 0;
    local_380 = 0;
    uStack_388 = 0;
    local_390 = 0;
    uStack_398 = 0;
    local_3a0 = 0;
    uStack_3a8 = 0;
    local_3b0 = 0;
    uStack_278 = 0;
    local_280 = 0;
    uStack_288 = 0;
    local_290 = 0;
    uVar26 = 0xffffffffffffffff;
    uStack_298 = 0;
    local_2a0 = 0;
    lStack_2a8 = 0;
    local_2b0 = 0;
    do {
      uVar26 = uVar26 + 1;
      snprintf((char *)&local_2b0,0x40,(char *)0x40,"/sys/class/thermal/cooling_device%d",
               uVar26 & 0xffffffff);
      iVar9 = access((char *)&local_2b0,0);
    } while (iVar9 == 0);
    DAT_0012ea78 = (int)uVar26;
    pvVar13 = calloc(uVar26,0x18);
    if (pvVar13 == (void *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cls\n");
    }
    else {
      DAT_0012ea80 = pvVar13;
      if ((int)uVar26 != 0) {
        uVar8 = 0;
        do {
          snprintf((char *)&local_3b0,0x40,(char *)0x40,"/sys/class/thermal/cooling_device%d/type",
                   (ulong)uVar8);
          node_read(&local_3b0,pvVar13,0x14);
          uVar26 = uVar26 - 1;
          pvVar13 = (void *)((long)pvVar13 + 0x18);
          uVar8 = uVar8 + 1;
        } while (uVar26 != 0);
      }
    }
    if (DAT_0012ea60 != 0) {
      uVar26 = 0;
      do {
        if (*(int *)PTR_DAT_0012d278 == 1) {
          __android_log_print(4,"thermal_core","TZ%d: %s\n",uVar26 & 0xffffffff,
                              (long)DAT_0012ea68 + uVar26 * 0x50 + 4);
        }
        pvVar13 = DAT_0012ea68;
        if (*(int *)((long)DAT_0012ea68 + uVar26 * 0x50 + 0x34) != 0) {
          lVar15 = 0;
          uVar32 = 0;
          do {
            if (*(int *)PTR_DAT_0012d278 == 1) {
              puVar27 = (undefined4 *)(*(long *)((long)pvVar13 + uVar26 * 0x50 + 0x38) + lVar15);
              __android_log_print(4,"thermal_core","trip%d: temp= %d, type= %d\n",
                                  uVar32 & 0xffffffff,*puVar27,puVar27[1]);
              pvVar13 = DAT_0012ea68;
            }
            uVar32 = uVar32 + 1;
            lVar15 = lVar15 + 8;
          } while (uVar32 < *(uint *)((long)pvVar13 + uVar26 * 0x50 + 0x34));
        }
        if (*(int *)((long)pvVar13 + uVar26 * 0x50 + 0x40) != 0) {
          uVar32 = 0;
          lVar15 = 0x14;
          do {
            if (*(int *)PTR_DAT_0012d278 == 1) {
              __android_log_print(4,"thermal_core","cd%d: %s, trip_point= %s\n",uVar32 & 0xffffffff,
                                  *(long *)((long)pvVar13 + uVar26 * 0x50 + 0x48) + lVar15 + -0x14);
              pvVar13 = DAT_0012ea68;
            }
            uVar32 = uVar32 + 1;
            lVar15 = lVar15 + 0x17;
          } while (uVar32 < *(uint *)((long)pvVar13 + uVar26 * 0x50 + 0x40));
        }
        uVar26 = uVar26 + 1;
      } while (uVar26 < DAT_0012ea60);
    }
    _DAT_0012e888 = DAT_00101f28;
    _DAT_0012e894 = DAT_00101f20;
    DAT_0012e8b0 = 0;
    _DAT_0012e8a0 = 0x1f4000001f4;
    _DAT_0012e8c8 = 0xffffffffffffffff;
    _DAT_0012e8d0 = 0xffffffffffffffff;
    snprintf(&DAT_0012e8d8,0x1e,(char *)0x1e,&DAT_00102ab3,"ap_ntc");
    DAT_0012e89c = 0;
    if (DAT_0012e898 - DAT_0012e894 != 0) {
      DAT_0012e89c = 0xd2f000 / (DAT_0012e898 - DAT_0012e894);
    }
    DAT_0012e890 = DAT_0012e888 + -0x34bc;
    DAT_0012e8ac = 0;
    if ((DAT_0012e8a4 != 0) && (DAT_0012e8ac = 0, DAT_0012e8a4 != 0)) {
      DAT_0012e8ac = 0xd2f000 / DAT_0012e8a4;
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
    snprintf(&DAT_0012ea12,0x1e,(char *)0x1e,&DAT_00102ab3,"ap_ntc");
    snprintf(&DAT_0012e9f4,0x1e,(char *)0x1e,&DAT_00102ab3,"soc_max");
    snprintf(&DAT_0012ea30,0x1e,(char *)0x1e,&DAT_00102ab3,"battery");
    uStack_528 = 0;
    local_530 = 0;
    uStack_518 = 0;
    uStack_520 = 0;
    uStack_548 = 0;
    local_550 = 0;
    uStack_538 = 0;
    uStack_540 = 0;
    uStack_568 = 0;
    local_570 = 0;
    uStack_558 = 0;
    uStack_560 = 0;
    uStack_588 = 0;
    local_590 = 0;
    uStack_578 = 0;
    uStack_580 = 0;
    uStack_5a8 = 0;
    local_5b0 = 0;
    uStack_598 = 0;
    uStack_5a0 = 0;
    uStack_5c8 = 0;
    local_5d0 = 0;
    uStack_5b8 = 0;
    uStack_5c0 = 0;
    uStack_5e8 = 0;
    local_5f0 = 0;
    uStack_5d8 = 0;
    uStack_5e0 = 0;
    uStack_608 = 0;
    local_610 = 0;
    uStack_5f8 = 0;
    uStack_600 = 0;
    uStack_628 = 0;
    local_630 = 0;
    uStack_618 = 0;
    uStack_620 = 0;
    uStack_648 = 0;
    local_650 = 0;
    uStack_638 = 0;
    uStack_640 = 0;
    uStack_668 = 0;
    local_670 = 0;
    uStack_658 = 0;
    uStack_660 = 0;
    uStack_688 = 0;
    local_690 = 0;
    uStack_678 = 0;
    local_680 = 0;
    uStack_6a8 = 0;
    local_6b0 = 0;
    iStack_698 = 0;
    uStack_694 = 0;
    local_6a0[0] = 0;
    local_6a0[1] = 0;
    local_6a0[2] = '\0';
    local_6a0[3] = 0;
    local_6a0[4] = '\0';
    local_6a0[5] = 0;
    local_6a0[6] = 0;
    local_6a0[7] = 0;
    uStack_6c8 = 0;
    local_6d0 = 0;
    uStack_6b8 = 0;
    uStack_6c0 = 0;
    uStack_6e8 = 0;
    local_6f0 = 0;
    uStack_6d8 = 0;
    uStack_6e0 = 0;
    uStack_708 = 0;
    local_710 = 0;
    uStack_6f8 = 0;
    uStack_700 = 0;
    uStack_728 = 0;
    local_730 = 0;
    uStack_718 = 0;
    uStack_720 = 0;
    uStack_748 = 0;
    local_750 = 0;
    uStack_738 = 0;
    uStack_740 = 0;
    uStack_768 = 0;
    local_770 = 0;
    uStack_758 = 0;
    uStack_760 = 0;
    uStack_788 = 0;
    local_790 = 0;
    uStack_778 = 0;
    local_780 = 0;
    uStack_798 = 0;
    uStack_793 = 0;
    local_7a0 = 0;
    uStack_79b = 0;
    DAT_0012ea70 = 0xffffffff;
    snprintf((char *)&local_550,0x40,(char *)0x40,"thermal_options.conf");
    snprintf((char *)&uStack_5a0,0x50,(char *)0x50,&DAT_00105536,"/data/vendor/thermal/",&local_550)
    ;
    iVar9 = access((char *)&uStack_5a0,0);
    if (iVar9 == 0) {
LAB_0010da70:
      pFVar16 = fopen((char *)&uStack_5a0,"r");
      if (pFVar16 == (FILE *)0x0) {
        __android_log_print(6,"thermal_core","Failed to open %s\n",&uStack_5a0);
      }
      else {
        pbVar17 = (byte *)fgets((char *)local_6a0,0x100,pFVar16);
        if (local_6a0 == pbVar17) {
          uVar8 = __strlen_chk(local_6a0,0x100);
          if (0 < (int)uVar8) {
            uVar26 = (ulong)uVar8;
            do {
              uVar8 = uVar8 - 1;
              if (0x20 < local_6a0[uVar8] ||
                  (1L << ((ulong)local_6a0[uVar8] & 0x3f) & 0x100002400U) == 0) goto LAB_0010dbe0;
              uVar32 = uVar26 - 1;
              bVar2 = 0 < (long)uVar26;
              uVar26 = uVar32;
            } while (uVar32 != 0 && bVar2);
            uVar26 = 0;
LAB_0010dbe0:
            local_6a0[(int)uVar26] = 0;
          }
          rewind(pFVar16);
          if (CONCAT17(local_6a0[7],
                       CONCAT16(local_6a0[6],
                                CONCAT15(local_6a0[5],
                                         CONCAT14(local_6a0[4],
                                                  CONCAT13(local_6a0[3],
                                                           CONCAT12(local_6a0[2],
                                                                    CONCAT11(local_6a0[1],
                                                                             local_6a0[0]))))))) ==
              0x5f7963696c6f705b &&
              CONCAT17((undefined1)uStack_694,
                       CONCAT43(iStack_698,
                                CONCAT12(local_6a0[7],CONCAT11(local_6a0[6],local_6a0[5])))) ==
              0x5d657079745f7963) goto LAB_0010daa8;
          snprintf((char *)&local_7a0,0x100,(char *)0x100,&DAT_00102ab3,local_6a0);
          sVar19 = strnlen((char *)&local_7a0,0x200);
          if (sVar19 != 0) {
            uVar26 = 0;
            uVar32 = 1;
            do {
              bVar23 = *(byte *)((long)&local_7a0 + uVar26);
              if (bVar23 - 0x20 < 0x5b) {
                uVar8 = ((uint)bVar23 - ((int)uVar26 + (int)(uVar26 / 10) * -10)) + 0x3b;
                bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
              }
              *(byte *)((long)&local_7a0 + uVar26) = bVar23;
              sVar19 = strnlen((char *)&local_7a0,0x200);
              bVar2 = uVar32 < sVar19;
              uVar26 = uVar32;
              uVar32 = (ulong)((int)uVar32 + 1);
            } while (bVar2);
          }
          bVar4 = CONCAT35(uStack_79b,local_7a0) == 0x5f7963696c6f705b;
          bVar1 = CONCAT53(uStack_798,uStack_79b) == 0x5d657079745f7963;
          bVar2 = bVar4 && bVar1;
          if (bVar2) {
            iVar9 = 1;
          }
          else {
            iVar9 = 2;
          }
          bVar4 = !bVar4 || !bVar1;
        }
        else {
LAB_0010daa8:
          bVar2 = false;
          bVar4 = false;
          iVar9 = 0;
        }
        __android_log_print(6,"thermal_core","encrypted_policy %d\n",iVar9);
        pcVar18 = fgets((char *)local_6a0,0x100,pFVar16);
        if (pcVar18 != (char *)0x0) {
          do {
            uVar8 = __strlen_chk(local_6a0,0x100);
            if (0 < (int)uVar8) {
              uVar26 = (ulong)uVar8;
              do {
                uVar8 = uVar8 - 1;
                if (0x20 < local_6a0[uVar8] ||
                    (1L << ((ulong)local_6a0[uVar8] & 0x3f) & 0x100002400U) == 0) goto LAB_0010de24;
                uVar32 = uVar26 - 1;
                bVar1 = 0 < (long)uVar26;
                uVar26 = uVar32;
              } while (uVar32 != 0 && bVar1);
              uVar26 = 0;
LAB_0010de24:
              local_6a0[(int)uVar26] = 0;
            }
            if (bVar2) {
              sVar19 = strnlen((char *)local_6a0,0x200);
              if (sVar19 != 0) {
                uVar26 = 0;
                uVar32 = 1;
                do {
                  bVar23 = local_6a0[uVar26];
                  if (bVar23 - 0x20 < 0x5b) {
                    uVar8 = ((uint)bVar23 - ((int)uVar26 + (int)(uVar26 / 10) * -10)) + 0x3b;
                    bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
                  }
                  local_6a0[uVar26] = bVar23;
                  sVar19 = strnlen((char *)local_6a0,0x200);
                  bVar1 = uVar32 < sVar19;
                  uVar26 = uVar32;
                  uVar32 = (ulong)((int)uVar32 + 1);
                } while (bVar1);
              }
            }
            else if ((bVar4) && (sVar19 = strnlen((char *)local_6a0,0x200), sVar19 != 0)) {
              uVar26 = 0;
              uVar32 = 1;
              do {
                bVar23 = local_6a0[uVar26];
                if (bVar23 - 0x20 < 0x5b) {
                  uVar8 = ((uint)bVar23 - ((int)uVar26 + (int)(uVar26 / 5) * -5)) + 0x3b;
                  bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
                }
                local_6a0[uVar26] = bVar23;
                sVar19 = strnlen((char *)local_6a0,0x200);
                bVar1 = uVar32 < sVar19;
                uVar26 = uVar32;
                uVar32 = (ulong)((int)uVar32 + 1);
              } while (bVar1);
            }
            iVar10 = __strlen_chk(local_6a0,0x100);
            if (((iVar10 != 0) && (local_6a0[0] == 0x5b)) && (local_6a0[iVar10 + -1] == 0x5d)) {
              if (*(int *)PTR_DAT_0012d278 == 1) {
                __android_log_print(4,"thermal_core","cmd: %s\n",local_6a0);
              }
              if (CONCAT17(local_6a0[7],
                           CONCAT16(local_6a0[6],
                                    CONCAT15(local_6a0[5],
                                             CONCAT14(local_6a0[4],
                                                      CONCAT13(local_6a0[3],
                                                               CONCAT12(local_6a0[2],
                                                                        CONCAT11(local_6a0[1],
                                                                                 local_6a0[0])))))))
                  == 0x5f6e6f6974706f5b && CONCAT44(uStack_694,iStack_698) == 0x5d676e6974746573) {
                local_2b0 = local_2b0 & 0xffffffff00000000;
LAB_0010e6cc:
                uVar26 = ftell(pFVar16);
                pcVar18 = fgets((char *)local_6a0,0x100,pFVar16);
                if (pcVar18 != (char *)0x0) {
                  do {
                    uVar8 = __strlen_chk(local_6a0,0x100);
                    if (0 < (int)uVar8) {
                      uVar32 = (ulong)uVar8;
                      do {
                        uVar8 = uVar8 - 1;
                        if (0x20 < local_6a0[uVar8] ||
                            (1L << ((ulong)local_6a0[uVar8] & 0x3f) & 0x100002400U) == 0)
                        goto LAB_0010e748;
                        uVar28 = uVar32 - 1;
                        bVar1 = 0 < (long)uVar32;
                        uVar32 = uVar28;
                      } while (uVar28 != 0 && bVar1);
                      uVar32 = 0;
LAB_0010e748:
                      local_6a0[(int)uVar32] = 0;
                    }
                    if (iVar9 == 2) {
                      sVar19 = strnlen((char *)local_6a0,0x200);
                      if (sVar19 != 0) {
                        uVar32 = 0;
                        uVar28 = 1;
                        do {
                          bVar23 = local_6a0[uVar32];
                          if (bVar23 - 0x20 < 0x5b) {
                            uVar8 = ((uint)bVar23 - ((int)uVar32 + (int)(uVar32 / 5) * -5)) + 0x3b;
                            bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
                          }
                          local_6a0[uVar32] = bVar23;
                          sVar19 = strnlen((char *)local_6a0,0x200);
                          bVar1 = uVar28 < sVar19;
                          uVar32 = uVar28;
                          uVar28 = (ulong)((int)uVar28 + 1);
                        } while (bVar1);
                      }
                    }
                    else if ((iVar9 == 1) &&
                            (sVar19 = strnlen((char *)local_6a0,0x200), sVar19 != 0)) {
                      uVar32 = 0;
                      uVar28 = 1;
                      do {
                        bVar23 = local_6a0[uVar32];
                        if (bVar23 - 0x20 < 0x5b) {
                          uVar8 = ((uint)bVar23 - ((int)uVar32 + (int)(uVar32 / 10) * -10)) + 0x3b;
                          bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
                        }
                        local_6a0[uVar32] = bVar23;
                        sVar19 = strnlen((char *)local_6a0,0x200);
                        bVar1 = uVar28 < sVar19;
                        uVar32 = uVar28;
                        uVar28 = (ulong)((int)uVar28 + 1);
                      } while (bVar1);
                    }
                    iVar10 = __strlen_chk(local_6a0,0x100);
                    if ((iVar10 != 0) && (local_6a0[0] != 0x23)) goto code_r0x0010e890;
                    pcVar18 = fgets((char *)local_6a0,0x100,pFVar16);
                    if (pcVar18 == (char *)0x0) break;
                  } while( true );
                }
LAB_0010e974:
                if ((int)uVar26 < 0) {
                  pcVar18 = "Negative file position %s\n";
                }
                else {
                  iVar10 = fseek(pFVar16,uVar26 & 0xffffffff,0);
                  if (iVar10 != -1) goto LAB_0010ddd0;
                  pcVar18 = "fseek failed: %s\n";
                }
                piVar21 = (int *)__errno();
                pcVar20 = strerror(*piVar21);
              }
              else {
                if (CONCAT17(local_6a0[7],
                             CONCAT16(local_6a0[6],
                                      CONCAT15(local_6a0[5],
                                               CONCAT14(local_6a0[4],
                                                        CONCAT13(local_6a0[3],
                                                                 CONCAT12(local_6a0[2],
                                                                          CONCAT11(local_6a0[1],
                                                                                   local_6a0[0])))))
                                     )) != 0x6c6f705f6275735b || iStack_698 != 0x5d796369)
                goto LAB_0010ddd0;
                local_828 = 0;
                uStack_a8 = 0;
                local_b0 = 0;
                uStack_98 = 0;
                uStack_a0 = 0;
                uStack_b8 = 0;
                local_c0 = 0;
                uStack_c8 = 0;
                local_d0 = 0;
                uStack_d8 = 0;
                local_e0 = 0;
                uStack_e8 = 0;
                local_f0 = 0;
                uStack_f8 = 0;
                local_100 = 0;
                uStack_108 = 0;
                local_110 = 0;
                uStack_118 = 0;
                local_120 = 0;
                uStack_128 = 0;
                local_130 = 0;
                uStack_138 = 0;
                local_140 = 0;
                uStack_148 = 0;
                local_150 = 0;
                uStack_158 = 0;
                local_160 = 0;
                uStack_168 = 0;
                local_170 = 0;
                uStack_178 = 0;
                local_180 = 0;
                uStack_188 = 0;
                local_190 = 0;
                uStack_198 = 0;
                local_1a0 = 0;
                uStack_1a8 = 0;
                local_1b0 = 0;
                uStack_1b8 = 0;
                local_1c0 = 0;
                uStack_1c8 = 0;
                local_1d0 = 0;
                uStack_1d8 = 0;
                local_1e0 = 0;
                uStack_1e8 = 0;
                local_1f0 = 0;
                uStack_1f8 = 0;
                local_200 = 0;
                uStack_208 = 0;
                local_210 = 0;
                uStack_218 = 0;
                local_220 = 0;
                uStack_228 = 0;
                local_230 = 0;
                uStack_238 = 0;
                local_240 = 0;
                uStack_248 = 0;
                local_250 = 0;
                uStack_258 = 0;
                local_260 = 0;
                uStack_268 = 0;
                local_270 = 0;
                uStack_278 = 0;
                local_280 = 0;
                uStack_288 = 0;
                local_290 = 0;
                uStack_298 = 0;
                local_2a0 = 0;
                lStack_2a8 = 0;
                local_2b0 = 0;
                uStack_2b8 = 0;
                local_2c0 = 0;
                uStack_2c8 = 0;
                local_2d0 = 0;
                uStack_2d8 = 0;
                local_2e0 = 0;
                uStack_2e8 = 0;
                local_2f0 = 0;
                uStack_2f8 = 0;
                local_300 = 0;
                uStack_308 = 0;
                local_310 = 0;
                uStack_318 = 0;
                local_320 = 0;
                uStack_328 = 0;
                local_330 = 0;
                uStack_338 = 0;
                local_340 = 0;
                uStack_348 = 0;
                local_350 = 0;
                uStack_358 = 0;
                local_360 = 0;
                uStack_368 = 0;
                local_370 = 0;
                uStack_378 = 0;
                local_380 = 0;
                uStack_388 = 0;
                local_390 = 0;
                uStack_398 = 0;
                local_3a0 = 0;
                uStack_3a8 = 0;
                local_3b0 = 0;
                local_3c0 = 0;
                local_460[0x13] = (char *)0x0;
                local_460[0x12] = (char *)0x0;
                local_460[0x11] = (char *)0x0;
                local_460[0x10] = (char *)0x0;
                local_460[0xf] = (char *)0x0;
                local_460[0xe] = (char *)0x0;
                local_460[0xd] = (char *)0x0;
                local_460[0xc] = (char *)0x0;
                local_460[0xb] = (char *)0x0;
                local_460[10] = (char *)0x0;
                local_460[9] = (char *)0x0;
                local_460[8] = (char *)0x0;
                local_460[7] = (char *)0x0;
                local_460[6] = (char *)0x0;
                local_460[5] = (char *)0x0;
                local_460[4] = (char *)0x0;
                local_460[3] = (char *)0x0;
                local_460[2] = (char *)0x0;
                local_460[1] = (char *)0x0;
                local_460[0] = (char *)0x0;
                local_470 = 0;
                local_510[0x13] = 0;
                local_510[0x12] = 0;
                local_510[0x11] = 0;
                local_510[0x10] = 0;
                local_510[0xf] = 0;
                local_510[0xe] = 0;
                local_510[0xd] = 0;
                local_510[0xc] = 0;
                local_510[9] = 0;
                local_510[8] = 0;
                local_510[0xb] = 0;
                local_510[10] = 0;
                local_510[5] = 0;
                local_510[4] = 0;
                local_510[7] = 0;
                local_510[6] = 0;
                local_510[1] = 0;
                local_510[0] = 0;
                local_510[3] = 0;
                local_510[2] = 0;
                local_8a8 = ftell(pFVar16);
                pcVar20 = fgets((char *)local_6a0,0x100,pFVar16);
                uVar26 = 0;
                pcVar18 = DAT_0012e840;
                if (pcVar20 != (char *)0x0) {
                  local_8ac = 0;
                  local_878 = 0;
                  do {
                    uVar8 = __strlen_chk(local_6a0,0x100);
                    if (0 < (int)uVar8) {
                      uVar26 = (ulong)uVar8;
                      do {
                        uVar8 = uVar8 - 1;
                        if (0x20 < local_6a0[uVar8] ||
                            (1L << ((ulong)local_6a0[uVar8] & 0x3f) & 0x100002400U) == 0)
                        goto LAB_0010e194;
                        uVar32 = uVar26 - 1;
                        bVar1 = 0 < (long)uVar26;
                        uVar26 = uVar32;
                      } while (uVar32 != 0 && bVar1);
                      uVar26 = 0;
LAB_0010e194:
                      local_6a0[(int)uVar26] = 0;
                    }
                    if (iVar9 == 2) {
                      sVar19 = strnlen((char *)local_6a0,0x200);
                      if (sVar19 != 0) {
                        uVar26 = 0;
                        uVar32 = 1;
                        do {
                          bVar23 = local_6a0[uVar26];
                          if (bVar23 - 0x20 < 0x5b) {
                            uVar8 = ((uint)bVar23 - ((int)uVar26 + (int)(uVar26 / 5) * -5)) + 0x3b;
                            bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
                          }
                          local_6a0[uVar26] = bVar23;
                          sVar19 = strnlen((char *)local_6a0,0x200);
                          bVar1 = uVar32 < sVar19;
                          uVar26 = uVar32;
                          uVar32 = (ulong)((int)uVar32 + 1);
                        } while (bVar1);
                      }
                    }
                    else if ((iVar9 == 1) &&
                            (sVar19 = strnlen((char *)local_6a0,0x200), sVar19 != 0)) {
                      uVar26 = 0;
                      uVar32 = 1;
                      do {
                        bVar23 = local_6a0[uVar26];
                        if (bVar23 - 0x20 < 0x5b) {
                          uVar8 = ((uint)bVar23 - ((int)uVar26 + (int)(uVar26 / 10) * -10)) + 0x3b;
                          bVar23 = (char)uVar8 + (char)((uVar8 & 0xff) / 0x5b) * -0x5b + 0x20;
                        }
                        local_6a0[uVar26] = bVar23;
                        sVar19 = strnlen((char *)local_6a0,0x200);
                        bVar1 = uVar32 < sVar19;
                        uVar26 = uVar32;
                        uVar32 = (ulong)((int)uVar32 + 1);
                      } while (bVar1);
                    }
                    uVar26 = __strlen_chk(local_6a0,0x100);
                    if (((int)uVar26 != 0) && (local_6a0[0] != 0x23)) {
                      if ((local_6a0[0] == 0x5b) && (local_6a0[(int)uVar26 + -1] == 0x5d))
                      goto LAB_0010e9a0;
                      if (*(int *)PTR_DAT_0012d278 == 1) {
                        __android_log_print(4,"thermal_core","line: %s\n",local_6a0);
                      }
                      if (CONCAT13(local_6a0[3],
                                   CONCAT12(local_6a0[2],CONCAT11(local_6a0[1],local_6a0[0]))) ==
                          0x61666564 &&
                          CONCAT13(local_6a0[6],
                                   CONCAT12(local_6a0[5],CONCAT11(local_6a0[4],local_6a0[3]))) ==
                          0x746c7561) {
                        pbVar17 = local_6a0;
                        bVar23 = local_6a0[0];
                        while (pbVar30 = pbVar17, bVar23 != 0) {
                          if (bVar23 == 0x3d) {
                            pbVar30 = pbVar17 + 1;
                            *pbVar17 = 0;
                            break;
                          }
                          pbVar17 = pbVar17 + 1;
                          bVar23 = *pbVar17;
                        }
                        for (; *pbVar30 == 0x20 || *pbVar30 == 9; pbVar30 = pbVar30 + 1) {
                        }
                        snprintf((char *)&local_b0,0x20,(char *)0x20,&DAT_00102ab3);
                      }
                      else if (CONCAT13(local_6a0[3],
                                        CONCAT12(local_6a0[2],CONCAT11(local_6a0[1],local_6a0[0])))
                               == 0x696c6f70 && CONCAT11(local_6a0[5],local_6a0[4]) == 0x7963) {
                        pbVar17 = local_6a0;
                        bVar23 = local_6a0[0];
                        while (pbVar30 = pbVar17, bVar23 != 0) {
                          if (bVar23 == 0x3d) {
                            pbVar30 = pbVar17 + 1;
                            *pbVar17 = 0;
                            break;
                          }
                          pbVar17 = pbVar17 + 1;
                          bVar23 = *pbVar17;
                        }
                        pbVar17 = local_6a0 + (uVar26 - (long)pbVar30);
                        for (; iVar10 = (int)pbVar17, *pbVar30 == 0x20 || *pbVar30 == 9;
                            pbVar30 = pbVar30 + 1) {
                          pbVar17 = pbVar17 + -1;
                        }
                        if (0x200 < iVar10) {
                          __android_log_print(6,"thermal_core","option_enable list overflow\n");
                          iVar10 = 0x200;
                        }
                        __memcpy_chk(&local_2b0,pbVar30,(long)iVar10,0x200);
                        if ((byte)local_2b0 == 0x5b) {
                          local_8ac = 0;
                          pbVar17 = (byte *)&local_2b0;
                          bVar1 = true;
                          bVar23 = 0x5b;
                          local_3c0 = local_3c0 & 0xffffffff00000000;
LAB_0010e504:
                          do {
                            if (bVar23 < 0x5b) {
                              if (bVar23 != 0x2c) {
                                if (bVar23 != 0) goto LAB_0010e528;
                                break;
                              }
                              bVar1 = true;
LAB_0010e4fc:
                              *pbVar17 = 0;
                            }
                            else {
                              if ((bVar23 == 0x5d) || (bVar23 == 0x5b)) goto LAB_0010e4fc;
LAB_0010e528:
                              if ((bVar23 != 0x20) && (bVar1)) {
                                if (local_8ac < 0x14) {
                                  local_460[local_8ac] = (char *)pbVar17;
                                  local_8ac = (int)local_3c0 + 1;
                                  bVar1 = false;
                                  local_3c0 = CONCAT44(local_3c0._4_4_,local_8ac);
                                  pbVar17 = pbVar17 + 1;
                                  bVar23 = *pbVar17;
                                  goto LAB_0010e504;
                                }
                                goto LAB_0010e680;
                              }
                            }
                            pbVar17 = pbVar17 + 1;
                            bVar23 = *pbVar17;
                          } while( true );
                        }
                      }
                      else if (CONCAT13(local_6a0[3],
                                        CONCAT12(local_6a0[2],CONCAT11(local_6a0[1],local_6a0[0])))
                               == 0x6c676e61 && local_6a0[4] == 'e') {
                        pbVar17 = local_6a0;
                        bVar23 = local_6a0[0];
                        while (pbVar30 = pbVar17, bVar23 != 0) {
                          if (bVar23 == 0x3d) {
                            pbVar30 = pbVar17 + 1;
                            *pbVar17 = 0;
                            break;
                          }
                          pbVar17 = pbVar17 + 1;
                          bVar23 = *pbVar17;
                        }
                        pbVar17 = local_6a0 + (uVar26 - (long)pbVar30);
                        for (; iVar10 = (int)pbVar17, *pbVar30 == 0x20 || *pbVar30 == 9;
                            pbVar30 = pbVar30 + 1) {
                          pbVar17 = pbVar17 + -1;
                        }
                        if (0x100 < iVar10) {
                          __android_log_print(6,"thermal_core","option_enable list overflow\n");
                          iVar10 = 0x100;
                        }
                        __memcpy_chk(&local_3b0,pbVar30,(long)iVar10,0x100);
                        if ((byte)local_3b0 == 0x5b) {
                          local_878 = 0;
                          pbVar17 = (byte *)&local_3b0;
                          bVar1 = true;
                          uVar8 = 0x5b;
                          local_470 = local_470 & 0xffffffff00000000;
LAB_0010e60c:
                          uVar11 = uVar8 - 0x28;
                          if (uVar11 < 0x36) {
                            if ((1L << ((ulong)uVar11 & 0x3f) & 0x28000000000002U) == 0) {
                              if ((1L << ((ulong)uVar11 & 0x3f) & 0x11U) == 0) goto LAB_0010e634;
                              bVar1 = true;
                            }
                            *pbVar17 = 0;
LAB_0010e608:
                            pbVar17 = pbVar17 + 1;
                            uVar8 = (uint)*pbVar17;
                            goto LAB_0010e60c;
                          }
LAB_0010e634:
                          if (uVar8 == 0) goto LAB_0010e6b0;
                          if ((uVar8 == 0x20) || (!bVar1)) goto LAB_0010e608;
                          if (local_878 < 0x14) {
                            local_510[local_878] = pbVar17;
                            local_878 = (int)local_470 + 1;
                            bVar1 = false;
                            local_470 = CONCAT44(local_470._4_4_,local_878);
                            pbVar17 = pbVar17 + 1;
                            uVar8 = (uint)*pbVar17;
                            goto LAB_0010e60c;
                          }
LAB_0010e680:
                          if (*(int *)PTR_DAT_0012d278 == 1) {
                            __android_log_print(4,"thermal_core",
                                                "List items are more than MAX_NUM_PTRS %d\n",0x14);
                          }
                        }
                      }
LAB_0010e6b0:
                      local_8a8 = ftell(pFVar16);
                    }
                    pcVar18 = fgets((char *)local_6a0,0x100,pFVar16);
                  } while (pcVar18 != (char *)0x0);
                  uVar26 = 0;
LAB_0010e9a0:
                  pcVar18 = DAT_0012e840;
                  if (local_8ac != 0) {
                    if (DAT_0012e840 != (char *)0x0) {
LAB_0010e9b4:
                      sVar19 = __strlen_chk(&local_b0,0x20);
                      iVar10 = strncmp(pcVar18,(char *)&local_b0,sVar19);
                      if (iVar10 != 0) goto code_r0x0010e9d4;
                      iVar10 = *(int *)(pcVar18 + 0x40);
                      local_870 = calloc((ulong)(iVar10 + local_8ac),0x48);
                      if (local_870 != (void *)0x0) {
                        if (*(int *)(pcVar18 + 0x40) != 0) {
                          lVar15 = 0;
                          uVar26 = 0;
                          do {
                            snprintf((char *)((long)local_870 + lVar15),0x40,(char *)0x40,
                                     &DAT_00102ab3,*(long *)(pcVar18 + 0x48) + lVar15);
                            *(undefined8 *)((char *)((long)local_870 + lVar15) + 0x40) =
                                 *(undefined8 *)(*(long *)(pcVar18 + 0x48) + lVar15 + 0x40);
                            uVar26 = uVar26 + 1;
                            lVar15 = lVar15 + 0x48;
                          } while (uVar26 < *(uint *)(pcVar18 + 0x40));
                        }
                        free(*(void **)(pcVar18 + 0x48));
                        *(uint *)(pcVar18 + 0x40) = *(int *)(pcVar18 + 0x40) + local_8ac;
                        *(void **)(pcVar18 + 0x48) = local_870;
                        goto LAB_0010eab0;
                      }
                      __android_log_print(6,"thermal_core","Failed to reallocate memory for sp\n");
                      goto LAB_0010ddd0;
                    }
LAB_0010e9dc:
                    local_870 = calloc((ulong)local_8ac,0x48);
                    if (local_870 == (void *)0x0) {
                      __android_log_print(6,"thermal_core","Failed to allocate memory for sp\n");
                      goto LAB_0010ddd0;
                    }
                    iVar10 = 0;
LAB_0010eab0:
                    uVar32 = 0;
                    uVar8 = local_8ac;
                    if (local_8ac < 2) {
                      uVar8 = 1;
                    }
                    puVar33 = local_510 + 1;
                    do {
                      pcVar18 = (char *)((long)local_870 + (long)(iVar10 + (int)uVar32) * 0x48);
                      snprintf(pcVar18,0x40,(char *)0x40,&DAT_00102ab3,local_460[uVar32]);
                      puVar27 = calloc(1,0xc);
                      plVar31 = (long *)(pcVar18 + 0x40);
                      *plVar31 = (long)puVar27;
                      if (local_878 == local_8ac << 1) {
                        pcVar18 = (char *)puVar33[-1];
                        *puVar27 = 1;
                        sscanf(pcVar18,"%d",&local_828);
                        uVar11 = sscanf((char *)*puVar33,"%d",(ulong)&local_828 | 4);
                        uVar26 = (ulong)uVar11;
                        iVar12 = local_828._4_4_;
                        if ((int)local_828 <= local_828._4_4_) {
                          iVar12 = (int)local_828;
                        }
                        *(int *)(*plVar31 + 4) = iVar12;
                        iVar12 = (int)local_828;
                        if ((int)local_828 <= local_828._4_4_) {
                          iVar12 = local_828._4_4_;
                        }
                        *(int *)(*plVar31 + 8) = iVar12;
                      }
                      else {
                        uVar26 = __android_log_print(6,"thermal_core",
                                                     "%s angle setting type error\n",pcVar18);
                      }
                      uVar32 = uVar32 + 1;
                      puVar33 = puVar33 + 2;
                    } while (uVar8 != uVar32);
                    pcVar18 = DAT_0012e840;
                    if (iVar10 == 0) {
                      pcVar18 = malloc(0x58);
                      if (pcVar18 == (char *)0x0) {
                        uVar26 = __android_log_print(6,"thermal_core",
                                                                                                          
                                                  "Failed to allocate memory for sub policy node\n")
                        ;
                        pcVar18 = DAT_0012e840;
                      }
                      else {
                        uVar26 = snprintf(pcVar18,0x40,(char *)0x40,&DAT_00102ab3,&local_b0);
                        *(uint *)(pcVar18 + 0x40) = local_8ac;
                        pcVar20 = DAT_0012e840;
                        *(void **)(pcVar18 + 0x48) = local_870;
                        pcVar18[0x50] = '\0';
                        pcVar18[0x51] = '\0';
                        pcVar18[0x52] = '\0';
                        pcVar18[0x53] = '\0';
                        pcVar18[0x54] = '\0';
                        pcVar18[0x55] = '\0';
                        pcVar18[0x56] = '\0';
                        pcVar18[0x57] = '\0';
                        do {
                          pcVar25 = pcVar20;
                          if (pcVar25 == (char *)0x0) goto LAB_0010ebd0;
                          pcVar20 = *(char **)(pcVar25 + 0x50);
                        } while (*(char **)(pcVar25 + 0x50) != (char *)0x0);
                        *(char **)(pcVar25 + 0x50) = pcVar18;
                        pcVar18 = DAT_0012e840;
                      }
                    }
                  }
                }
LAB_0010ebd0:
                DAT_0012e840 = pcVar18;
                if ((int)local_8a8 < 0) {
                  piVar21 = (int *)__errno(uVar26);
                  pcVar20 = strerror(*piVar21);
                  pcVar18 = "Negative file position %s\n";
                }
                else {
                  iVar10 = fseek(pFVar16,local_8a8 & 0xffffffff,0);
                  if (iVar10 != -1) goto LAB_0010ddd0;
                  piVar21 = (int *)__errno();
                  pcVar20 = strerror(*piVar21);
                  pcVar18 = "fseek failed: %s\n";
                }
              }
              __android_log_print(6,"thermal_core",pcVar18,pcVar20);
            }
LAB_0010ddd0:
            pcVar18 = fgets((char *)local_6a0,0x100,pFVar16);
          } while (pcVar18 != (char *)0x0);
        }
        fclose(pFVar16);
      }
    }
    else {
      snprintf((char *)&uStack_5a0,0x50,(char *)0x50,&DAT_00105536,"/vendor/etc/thermal/",&local_550
              );
      iVar9 = access((char *)&uStack_5a0,0);
      if (iVar9 == 0) goto LAB_0010da70;
    }
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"md_off");
      puVar7 = PTR_free_md_off_cooler_instance_0012d288;
      puVar6 = PTR_md_off_cooler_0012d280;
      pcVar18[0x18] = '\0';
      pcVar18[0x19] = '\0';
      pcVar18[0x1a] = '\0';
      pcVar18[0x1b] = '\0';
      pcVar18[0x1c] = '\0';
      pcVar18[0x1d] = '\0';
      pcVar18[0x1e] = '\0';
      pcVar18[0x1f] = '\0';
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010ed8c;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010ed8c:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"aee_dump");
      puVar7 = PTR_free_aee_dump_cooler_instance_0012d298;
      puVar6 = PTR_aee_dump_cooler_0012d290;
      pcVar18[0x18] = '\0';
      pcVar18[0x19] = '\0';
      pcVar18[0x1a] = '\0';
      pcVar18[0x1b] = '\0';
      pcVar18[0x1c] = '\0';
      pcVar18[0x1d] = '\0';
      pcVar18[0x1e] = '\0';
      pcVar18[0x1f] = '\0';
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010ee0c;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010ee0c:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"md_notification");
      puVar7 = PTR_free_md_notification_instance_0012d2a8;
      puVar6 = PTR_md_notification_0012d2a0;
      pcVar18[0x18] = '\0';
      pcVar18[0x19] = '\0';
      pcVar18[0x1a] = '\0';
      pcVar18[0x1b] = '\0';
      pcVar18[0x1c] = '\0';
      pcVar18[0x1d] = '\0';
      pcVar18[0x1e] = '\0';
      pcVar18[0x1f] = '\0';
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010ee8c;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010ee8c:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"log_dump");
      puVar7 = PTR_free_log_on_cooler_instance_0012d2b8;
      puVar6 = PTR_log_on_cooler_0012d2b0;
      pcVar18[0x18] = '\0';
      pcVar18[0x19] = '\0';
      pcVar18[0x1a] = '\0';
      pcVar18[0x1b] = '\0';
      pcVar18[0x1c] = '\0';
      pcVar18[0x1d] = '\0';
      pcVar18[0x1e] = '\0';
      pcVar18[0x1f] = '\0';
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010ef0c;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010ef0c:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"tz_polling");
      puVar7 = PTR_free_tz_polling_cooler_instance_0012d2c8;
      puVar6 = PTR_tz_polling_cooler_0012d2c0;
      pcVar18[0x18] = '\0';
      pcVar18[0x19] = '\0';
      pcVar18[0x1a] = '\0';
      pcVar18[0x1b] = '\0';
      pcVar18[0x1c] = '\0';
      pcVar18[0x1d] = '\0';
      pcVar18[0x1e] = '\0';
      pcVar18[0x1f] = '\0';
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010ef8c;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010ef8c:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"cpu_table_mapping");
      puVar7 = PTR_free_cpu_table_cooler_instance_0012d2e0;
      puVar6 = PTR_cpu_table_cooler_0012d2d8;
      *(undefined **)(pcVar18 + 0x18) = PTR_cpu_table_cooler_constructor_0012d2d0;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f014;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f014:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"cpu_isolate");
      puVar7 = PTR_free_cpu_isolate_cooler_instance_0012d2f8;
      puVar6 = PTR_cpu_isolate_cooler_0012d2f0;
      *(undefined **)(pcVar18 + 0x18) = PTR_cpu_isolate_cooler_constructor_0012d2e8;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f09c;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f09c:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"gpu_table_mapping");
      puVar7 = PTR_free_gpu_table_cooler_instance_0012d310;
      puVar6 = PTR_gpu_table_cooler_0012d308;
      *(undefined **)(pcVar18 + 0x18) = PTR_gpu_table_cooler_constructor_0012d300;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f124;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f124:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"charger_cooler");
      puVar7 = PTR_free_charger_cooler_instance_0012d328;
      puVar6 = PTR_charger_cooler_0012d320;
      *(undefined **)(pcVar18 + 0x18) = PTR_charger_cooler_constructor_0012d318;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f1ac;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f1ac:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"tskin_control");
      pcVar20 = DAT_0012e9e8;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      pcVar18[0x28] = '\0';
      pcVar18[0x29] = '\0';
      pcVar18[0x2a] = '\0';
      pcVar18[0x2b] = '\0';
      pcVar18[0x2c] = '\0';
      pcVar18[0x2d] = '\0';
      pcVar18[0x2e] = '\0';
      pcVar18[0x2f] = '\0';
      pcVar18[0x20] = '\0';
      pcVar18[0x21] = '\0';
      pcVar18[0x22] = '\0';
      pcVar18[0x23] = '\0';
      pcVar18[0x24] = '\0';
      pcVar18[0x25] = '\0';
      pcVar18[0x26] = '\0';
      pcVar18[0x27] = '\0';
      pcVar18[0x18] = '\0';
      pcVar18[0x19] = '\0';
      pcVar18[0x1a] = '\0';
      pcVar18[0x1b] = '\0';
      pcVar18[0x1c] = '\0';
      pcVar18[0x1d] = '\0';
      pcVar18[0x1e] = '\0';
      pcVar18[0x1f] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f220;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f220:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"backlight_cooler");
      puVar7 = PTR_free_backlight_cooler_instance_0012d340;
      puVar6 = PTR_backlight_cooler_0012d338;
      *(undefined **)(pcVar18 + 0x18) = PTR_backlight_cooler_constructor_0012d330;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f2a8;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f2a8:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"wifi_cooler");
      puVar7 = PTR_free_wifi_cooler_instance_0012d358;
      puVar6 = PTR_wifi_cooler_0012d350;
      *(undefined **)(pcVar18 + 0x18) = PTR_wifi_cooler_constructor_0012d348;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f330;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f330:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"flashlight_cooler");
      puVar7 = PTR_free_flashlight_cooler_instance_0012d370;
      puVar6 = PTR_flashlight_cooler_0012d368;
      *(undefined **)(pcVar18 + 0x18) = PTR_flashlight_cooler_constructor_0012d360;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f3b8;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f3b8:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"mutt_pa1_cooler");
      puVar7 = PTR_free_mutt_pa1_cooler_instance_0012d388;
      puVar6 = PTR_mutt_pa1_cooler_0012d380;
      *(undefined **)(pcVar18 + 0x18) = PTR_mutt_pa1_cooler_constructor_0012d378;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f440;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f440:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"mutt_pa2_cooler");
      puVar7 = PTR_free_mutt_pa2_cooler_instance_0012d3a0;
      puVar6 = PTR_mutt_pa2_cooler_0012d398;
      *(undefined **)(pcVar18 + 0x18) = PTR_mutt_pa2_cooler_constructor_0012d390;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f4c8;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f4c8:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"tx_pwr_pa1_cooler");
      puVar7 = PTR_free_tx_pwr_pa1_cooler_instance_0012d3b8;
      puVar6 = PTR_tx_pwr_pa1_cooler_0012d3b0;
      *(undefined **)(pcVar18 + 0x18) = PTR_tx_pwr_pa1_cooler_constructor_0012d3a8;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f550;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f550:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"tx_pwr_pa2_cooler");
      puVar7 = PTR_free_tx_pwr_pa2_cooler_instance_0012d3d0;
      puVar6 = PTR_tx_pwr_pa2_cooler_0012d3c8;
      *(undefined **)(pcVar18 + 0x18) = PTR_tx_pwr_pa2_cooler_constructor_0012d3c0;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f5d8;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f5d8:
    DAT_0012e9e8 = pcVar18;
    pcVar18 = malloc(0x38);
    if (pcVar18 == (char *)0x0) {
      __android_log_print(6,"thermal_core","Failed to allocate memory for cooler node\n");
      pcVar18 = DAT_0012e9e8;
    }
    else {
      snprintf(pcVar18,0x14,(char *)0x14,&DAT_00102ab3,"scg_off_pa2_cooler");
      puVar7 = PTR_free_scg_off_pa2_cooler_instance_0012d3e8;
      puVar6 = PTR_scg_off_pa2_cooler_0012d3e0;
      *(undefined **)(pcVar18 + 0x18) = PTR_scg_off_pa2_cooler_constructor_0012d3d8;
      *(undefined **)(pcVar18 + 0x20) = puVar6;
      pcVar20 = DAT_0012e9e8;
      *(undefined **)(pcVar18 + 0x28) = puVar7;
      pcVar18[0x30] = '\0';
      pcVar18[0x31] = '\0';
      pcVar18[0x32] = '\0';
      pcVar18[0x33] = '\0';
      pcVar18[0x34] = '\0';
      pcVar18[0x35] = '\0';
      pcVar18[0x36] = '\0';
      pcVar18[0x37] = '\0';
      do {
        pcVar25 = pcVar20;
        if (pcVar25 == (char *)0x0) goto LAB_0010f660;
        pcVar20 = *(char **)(pcVar25 + 0x30);
      } while (*(char **)(pcVar25 + 0x30) != (char *)0x0);
      *(char **)(pcVar25 + 0x30) = pcVar18;
      pcVar18 = DAT_0012e9e8;
    }
LAB_0010f660:
    DAT_0012e9e8 = pcVar18;
    uStack_278 = 0;
    local_280 = 0;
    uStack_288 = 0;
    local_290 = 0;
    uStack_298 = 0;
    local_2a0 = 0;
    lStack_2a8 = 0;
    local_2b0 = 0;
    node_read("/sys/kernel/thermal/info_b",&local_2b0,0x40);
    sscanf((char *)&local_2b0,"%d",&DAT_0012e9a0);
    if (DAT_0012e9a0 != 1) {
      DAT_0012e9a0 = 0;
    }
    iVar9 = efuse_read(0x100);
    if (iVar9 != 0) {
      DAT_0012e8b4 = 1;
    }
    uStack_278 = 0;
    local_280 = 0;
    uStack_288 = 0;
    local_290 = 0;
    uStack_298 = 0;
    local_2a0 = 0;
    lStack_2a8 = 0;
    local_2b0 = 0;
    iVar9 = access("/data/vendor/thermal/.permanent_tp",0);
    if (iVar9 == 0) {
      pFVar16 = fopen("/data/vendor/thermal/.permanent_tp","r");
      if (pFVar16 == (FILE *)0x0) {
        __android_log_print(6,"thermal_core","Failed to open %s\n",
                            "/data/vendor/thermal/.permanent_tp");
      }
      else {
        pcVar18 = fgets((char *)&local_2b0,0x40,pFVar16);
        if (pcVar18 == (char *)0x0) {
          __android_log_print(6,"thermal_core","Failed to read %s\n",
                              "/data/vendor/thermal/.permanent_tp");
        }
        fclose(pFVar16);
        uVar8 = __strlen_chk(&local_2b0,0x40);
        if (0 < (int)uVar8) {
          uVar26 = (ulong)uVar8;
          do {
            uVar8 = uVar8 - 1;
            if (0x20 < *(byte *)((long)&local_2b0 + (ulong)uVar8) ||
                (1L << ((ulong)*(byte *)((long)&local_2b0 + (ulong)uVar8) & 0x3f) & 0x100002400U) ==
                0) goto LAB_0010f804;
            uVar32 = uVar26 - 1;
            bVar2 = 0 < (long)uVar26;
            uVar26 = uVar32;
          } while (uVar32 != 0 && bVar2);
          uVar26 = 0;
LAB_0010f804:
          *(undefined1 *)((long)&local_2b0 + (long)(int)uVar26) = 0;
        }
        __android_log_print(4,"thermal_core","Permanent_tp is %s\n",&local_2b0);
        iVar9 = (int)local_2b0;
        if ((iVar9 != 0x72656874 || local_2b0._3_4_ != 0x6c616d72) &&
           (iVar9 != 0x61736964 || local_2b0._3_4_ != 0x656c6261)) {
          __android_log_print(4,"thermal_core","Permanent_tp abnormal\n");
          goto LAB_0010f718;
        }
        change_policy(&local_2b0);
        if ((local_2b0 == 0x5f6c616d72656874 && lStack_2a8 == 0x6e6f632e6662746d) &&
            (local_2a0 & 0xff) == 0x66) {
          __android_log_print(4,"thermal_core","mtbf mode on\n");
          DAT_0012e928 = 1;
        }
      }
    }
    else {
      __android_log_print(4,"thermal_core","%s doesn\'t exist\n",
                          "/data/vendor/thermal/.permanent_tp");
LAB_0010f718:
      change_policy("thermal.conf");
    }
    iVar9 = pthread_create(&pStack_830,(pthread_attr_t *)0x0,algorithm_thread,(void *)0x0);
    if (iVar9 == 0) {
      iVar9 = pthread_create(&local_838,(pthread_attr_t *)0x0,(__start_routine *)PTR_frs_0012d3f0,
                             (void *)0x0);
      if (iVar9 == 0) {
        iVar9 = pthread_create(&pStack_830,(pthread_attr_t *)0x0,
                               (__start_routine *)PTR_md_thermal_thread_0012d3f8,(void *)0x0);
        if (iVar9 == 0) {
          iVar9 = pthread_create(&pStack_840,(pthread_attr_t *)0x0,thermal_worker,(void *)0x0);
          if (iVar9 == 0) {
            iVar9 = pthread_create(&local_850,(pthread_attr_t *)0x0,hinge_update_thread,(void *)0x0)
            ;
            if (iVar9 == 0) {
              iVar9 = pthread_create(&local_848,(pthread_attr_t *)0x0,hinge_check_thread,(void *)0x0
                                    );
              if (iVar9 == 0) {
                iVar9 = create_socket_server();
                if (iVar9 != -1) {
                  iVar10 = accept(iVar9,(sockaddr *)0x0,(socklen_t *)0x0);
                  while (iVar10 != -1) {
                    sVar22 = recvfrom(iVar10,&local_820,0x80,0,(sockaddr *)0x0,(socklen_t *)0x0);
                    iVar12 = (int)sVar22;
                    if (iVar12 == -1) {
                      piVar21 = (int *)__errno();
                      pcVar18 = strerror(*piVar21);
                      __android_log_print(6,"thermal_core","Socket recv failed: %s\n",pcVar18);
                    }
                    else {
                      uVar26 = (long)iVar12;
                      if (0x7f < iVar12) {
                        uVar26 = (ulong)(iVar12 - 1);
                      }
                      *(undefined1 *)((long)&local_820 + uVar26) = 0;
                      __android_log_print(4,"thermal_core","Get from client %s\n",&local_820);
                      thermal_add_job(&local_820);
                    }
                    close(iVar10);
                    iVar10 = accept(iVar9,(sockaddr *)0x0,(socklen_t *)0x0);
                  }
                  __android_log_print(6,"thermal_core","Failed to accept a connection");
                  close(iVar9);
                  iVar9 = unlink("thermal_socket");
                  free_bind_map(iVar9);
                  free_cooler_list();
                  free_thermal_instance_list();
                  free_sub_policy_list();
                  iVar9 = pthread_mutex_destroy((pthread_mutex_t *)&DAT_0012e8f8);
                  if (iVar9 != 0) {
                    pcVar18 = strerror(iVar9);
                    __android_log_print(6,"thermal_core","Failed to destory a mutex lock: %s\n",
                                        pcVar18);
                  }
                  iVar9 = pthread_mutex_destroy((pthread_mutex_t *)&DAT_0012e818);
                  if (iVar9 != 0) {
                    pcVar18 = strerror(iVar9);
                    __android_log_print(6,"thermal_core","Failed to destory a mutex lock: %s\n",
                                        pcVar18);
                  }
                  iVar9 = pthread_mutex_destroy((pthread_mutex_t *)&DAT_0012e92c);
                  uVar24 = 0;
                  if (iVar9 == 0) goto LAB_0010fa54;
                  pcVar18 = strerror(iVar9);
                  __android_log_print(6,"thermal_core","Failed to destory a mutex lock: %s\n",
                                      pcVar18);
                  goto LAB_0010d088;
                }
                __android_log_print(6,"thermal_core","Failed to create a server socket\n");
                goto LAB_0010fa50;
              }
              pcVar20 = strerror(iVar9);
              pcVar18 = "Failed to create a thread for hinge update thread: %s\n";
            }
            else {
              pcVar20 = strerror(iVar9);
              pcVar18 = "Failed to create a thread for hinge check thread: %s\n";
            }
          }
          else {
            pcVar20 = strerror(iVar9);
            pcVar18 = "Failed to create a thread for thermal worker: %s\n";
          }
        }
        else {
          pcVar20 = strerror(iVar9);
          pcVar18 = "Failed to create a thread for md thermal thread: %s\n";
        }
      }
      else {
        pcVar20 = strerror(iVar9);
        pcVar18 = "Failed to create a thread for fps cooler: %s\n";
      }
    }
    else {
      pcVar20 = strerror(iVar9);
      pcVar18 = "Failed to create a thread for thermal algorithms: %s\n";
    }
    __android_log_print(6,"thermal_core",pcVar18,pcVar20);
  }
LAB_0010fa50:
  uVar24 = 0xffffffff;
LAB_0010fa54:
  if (*(long *)(lVar3 + 0x28) != local_88) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar24);
  }
  return;
code_r0x0010e890:
  if ((local_6a0[0] == 0x5b) && (local_6a0[iVar10 + -1] == 0x5d)) goto LAB_0010e974;
  if (*(int *)PTR_DAT_0012d278 == 1) {
    __android_log_print(4,"thermal_core","line: %s\n",local_6a0);
  }
  DAT_0012ea74 = 0;
  if (CONCAT17(local_6a0[7],
               CONCAT16(local_6a0[6],
                        CONCAT15(local_6a0[5],
                                 CONCAT14(local_6a0[4],
                                          CONCAT13(local_6a0[3],
                                                   CONCAT12(local_6a0[2],
                                                            CONCAT11(local_6a0[1],local_6a0[0]))))))
              ) == 0x65735f65676e6968 && iStack_698 == 0x726f736e) {
    pbVar17 = local_6a0;
    bVar23 = local_6a0[0];
    while (pbVar30 = pbVar17, bVar23 != 0) {
      if (bVar23 == 0x3d) {
        pbVar30 = pbVar17 + 1;
        *pbVar17 = 0;
        break;
      }
      pbVar17 = pbVar17 + 1;
      bVar23 = *pbVar17;
    }
    for (; *pbVar30 == 0x20 || *pbVar30 == 9; pbVar30 = pbVar30 + 1) {
    }
    sscanf((char *)pbVar30,"%d",&local_2b0);
    DAT_0012ea70 = (int)local_2b0;
  }
  goto LAB_0010e6cc;
code_r0x0010e9d4:
  pcVar18 = *(char **)(pcVar18 + 0x50);
  if (pcVar18 == (char *)0x0) goto LAB_0010e9dc;
  goto LAB_0010e9b4;
}
