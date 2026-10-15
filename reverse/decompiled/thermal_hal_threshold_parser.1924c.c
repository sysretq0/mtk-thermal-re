/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: thermal_hal_threshold_parser   VMA: 0x1924c   (see reverse/symbols.csv)
 */

void thermal_hal_threshold_parser(FILE *param_1,char *param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  size_t sVar7;
  undefined8 uVar8;
  int *piVar9;
  char *pcVar10;
  byte bVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  byte *pbVar15;
  undefined8 *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 *puVar19;
  ulong uVar20;
  undefined8 *puVar21;
  long lVar22;
  uint local_46c;
  ulong local_448;
  int local_434;
  char local_430 [16];
  undefined8 local_420;
  undefined8 uStack_418;
  undefined8 local_410;
  undefined8 uStack_408;
  undefined8 uStack_400;
  undefined8 uStack_3f8;
  undefined8 local_3f0;
  undefined8 uStack_3e8;
  undefined8 local_3e0 [20];
  ulong local_340;
  undefined8 local_330 [20];
  ulong local_290;
  byte local_280 [256];
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
  undefined8 uStack_90;
  undefined8 uStack_88;
  long local_78;
  
  lVar3 = tpidr_el0;
  local_78 = *(long *)(lVar3 + 0x28);
  local_430[0] = '\0';
  local_430[1] = '\0';
  local_430[2] = '\0';
  local_430[3] = '\0';
  local_430[4] = '\0';
  local_430[5] = '\0';
  local_430[6] = '\0';
  local_430[7] = '\0';
  local_430[8] = '\0';
  local_430[9] = '\0';
  local_430[10] = '\0';
  local_430[0xb] = '\0';
  local_430[0xc] = '\0';
  local_430[0xd] = '\0';
  local_430[0xe] = '\0';
  local_430[0xf] = '\0';
  local_448 = ftell(param_1);
LAB_001192b8:
  while (pcVar6 = fgets(param_2,0x100,param_1), pcVar6 != (char *)0x0) {
    sVar7 = strlen(param_2);
    uVar17 = (uint)sVar7;
    if (0 < (int)uVar17) {
      uVar12 = sVar7 & 0xffffffff;
      do {
        uVar17 = uVar17 - 1;
        if (0x20 < (byte)param_2[uVar17] ||
            (1L << ((ulong)(byte)param_2[uVar17] & 0x3f) & 0x100002400U) == 0) goto LAB_00119308;
        uVar14 = uVar12 - 1;
        bVar1 = 0 < (long)uVar12;
        uVar12 = uVar14;
      } while (uVar14 != 0 && bVar1);
      uVar12 = 0;
LAB_00119308:
      param_2[(int)uVar12] = '\0';
    }
    if (param_3 == 2) {
      sVar7 = strnlen(param_2,0x200);
      if (sVar7 != 0) {
        uVar12 = 1;
        uVar14 = 0;
        do {
          uVar20 = uVar12;
          bVar11 = param_2[uVar14];
          if (bVar11 - 0x20 < 0x5b) {
            uVar17 = ((uint)bVar11 - ((int)uVar14 + (int)(uVar14 / 5) * -5)) + 0x3b;
            bVar11 = (char)uVar17 + (char)((uVar17 & 0xff) / 0x5b) * -0x5b + 0x20;
          }
          param_2[uVar14] = bVar11;
          sVar7 = strnlen(param_2,0x200);
          uVar12 = (ulong)((int)uVar20 + 1);
          uVar14 = uVar20;
        } while (uVar20 < sVar7);
      }
    }
    else if ((param_3 == 1) && (sVar7 = strnlen(param_2,0x200), sVar7 != 0)) {
      uVar12 = 1;
      uVar14 = 0;
      do {
        uVar20 = uVar12;
        bVar11 = param_2[uVar14];
        if (bVar11 - 0x20 < 0x5b) {
          uVar17 = ((uint)bVar11 - ((int)uVar14 + (int)(uVar14 / 10) * -10)) + 0x3b;
          bVar11 = (char)uVar17 + (char)((uVar17 & 0xff) / 0x5b) * -0x5b + 0x20;
        }
        param_2[uVar14] = bVar11;
        sVar7 = strnlen(param_2,0x200);
        uVar12 = (ulong)((int)uVar20 + 1);
        uVar14 = uVar20;
      } while (uVar20 < sVar7);
    }
    sVar7 = strlen(param_2);
    if (((int)sVar7 != 0) && (*param_2 != '#')) {
      if ((*param_2 != '[') || (param_2[(int)sVar7 + -1] != ']')) {
        if (*(int *)PTR_DAT_0012d278 == 1) {
          __android_log_print(4,"thermal_core","line: %s\n",param_2);
        }
        iVar4 = strncmp(param_2,"type",4);
        if (iVar4 == 0) {
          cVar2 = *param_2;
          pcVar6 = param_2;
          while (pcVar10 = pcVar6, cVar2 != '\0') {
            if (cVar2 == '=') {
              pcVar10 = pcVar6 + 1;
              *pcVar6 = '\0';
              break;
            }
            pcVar6 = pcVar6 + 1;
            cVar2 = *pcVar6;
          }
          for (; *pcVar10 == ' ' || *pcVar10 == '\t'; pcVar10 = pcVar10 + 1) {
          }
          if (*(int *)PTR_DAT_0012d278 == 1) {
            __android_log_print(4,"thermal_core","par: %s\n",pcVar10);
          }
          snprintf(local_430,0x10,(char *)0x10,&DAT_00102ab3,pcVar10);
          iVar4 = strncasecmp(pcVar10,"SKIN",4);
          lVar22 = DAT_0012ea68;
          if (iVar4 == 0) {
            local_434 = 0;
            uStack_98 = 0;
            local_a0 = 0;
            uStack_88 = 0;
            uStack_90 = 0;
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
            local_280[0xe8] = 0;
            local_280[0xe9] = 0;
            local_280[0xea] = 0;
            local_280[0xeb] = 0;
            local_280[0xec] = 0;
            local_280[0xed] = 0;
            local_280[0xee] = 0;
            local_280[0xef] = 0;
            local_280[0xe0] = 0;
            local_280[0xe1] = 0;
            local_280[0xe2] = 0;
            local_280[0xe3] = 0;
            local_280[0xe4] = 0;
            local_280[0xe5] = 0;
            local_280[0xe6] = 0;
            local_280[0xe7] = 0;
            local_280[0xf8] = 0;
            local_280[0xf9] = 0;
            local_280[0xfa] = 0;
            local_280[0xfb] = 0;
            local_280[0xfc] = 0;
            local_280[0xfd] = 0;
            local_280[0xfe] = 0;
            local_280[0xff] = 0;
            local_280[0xf0] = 0;
            local_280[0xf1] = 0;
            local_280[0xf2] = 0;
            local_280[0xf3] = 0;
            local_280[0xf4] = 0;
            local_280[0xf5] = 0;
            local_280[0xf6] = 0;
            local_280[0xf7] = 0;
            local_280[200] = 0;
            local_280[0xc9] = 0;
            local_280[0xca] = 0;
            local_280[0xcb] = 0;
            local_280[0xcc] = 0;
            local_280[0xcd] = 0;
            local_280[0xce] = 0;
            local_280[0xcf] = 0;
            local_280[0xc0] = 0;
            local_280[0xc1] = 0;
            local_280[0xc2] = 0;
            local_280[0xc3] = 0;
            local_280[0xc4] = 0;
            local_280[0xc5] = 0;
            local_280[0xc6] = 0;
            local_280[199] = 0;
            local_280[0xd8] = 0;
            local_280[0xd9] = 0;
            local_280[0xda] = 0;
            local_280[0xdb] = 0;
            local_280[0xdc] = 0;
            local_280[0xdd] = 0;
            local_280[0xde] = 0;
            local_280[0xdf] = 0;
            local_280[0xd0] = 0;
            local_280[0xd1] = 0;
            local_280[0xd2] = 0;
            local_280[0xd3] = 0;
            local_280[0xd4] = 0;
            local_280[0xd5] = 0;
            local_280[0xd6] = 0;
            local_280[0xd7] = 0;
            local_280[0xa8] = 0;
            local_280[0xa9] = 0;
            local_280[0xaa] = 0;
            local_280[0xab] = 0;
            local_280[0xac] = 0;
            local_280[0xad] = 0;
            local_280[0xae] = 0;
            local_280[0xaf] = 0;
            local_280[0xa0] = 0;
            local_280[0xa1] = 0;
            local_280[0xa2] = 0;
            local_280[0xa3] = 0;
            local_280[0xa4] = 0;
            local_280[0xa5] = 0;
            local_280[0xa6] = 0;
            local_280[0xa7] = 0;
            local_280[0xb8] = 0;
            local_280[0xb9] = 0;
            local_280[0xba] = 0;
            local_280[0xbb] = 0;
            local_280[0xbc] = 0;
            local_280[0xbd] = 0;
            local_280[0xbe] = 0;
            local_280[0xbf] = 0;
            local_280[0xb0] = 0;
            local_280[0xb1] = 0;
            local_280[0xb2] = 0;
            local_280[0xb3] = 0;
            local_280[0xb4] = 0;
            local_280[0xb5] = 0;
            local_280[0xb6] = 0;
            local_280[0xb7] = 0;
            local_280[0x88] = 0;
            local_280[0x89] = 0;
            local_280[0x8a] = 0;
            local_280[0x8b] = 0;
            local_280[0x8c] = 0;
            local_280[0x8d] = 0;
            local_280[0x8e] = 0;
            local_280[0x8f] = 0;
            local_280[0x80] = 0;
            local_280[0x81] = 0;
            local_280[0x82] = 0;
            local_280[0x83] = 0;
            local_280[0x84] = 0;
            local_280[0x85] = 0;
            local_280[0x86] = 0;
            local_280[0x87] = 0;
            local_280[0x98] = 0;
            local_280[0x99] = 0;
            local_280[0x9a] = 0;
            local_280[0x9b] = 0;
            local_280[0x9c] = 0;
            local_280[0x9d] = 0;
            local_280[0x9e] = 0;
            local_280[0x9f] = 0;
            local_280[0x90] = 0;
            local_280[0x91] = 0;
            local_280[0x92] = 0;
            local_280[0x93] = 0;
            local_280[0x94] = 0;
            local_280[0x95] = 0;
            local_280[0x96] = 0;
            local_280[0x97] = 0;
            local_280[0x68] = 0;
            local_280[0x69] = 0;
            local_280[0x6a] = 0;
            local_280[0x6b] = 0;
            local_280[0x6c] = 0;
            local_280[0x6d] = 0;
            local_280[0x6e] = 0;
            local_280[0x6f] = 0;
            local_280[0x60] = 0;
            local_280[0x61] = 0;
            local_280[0x62] = 0;
            local_280[99] = 0;
            local_280[100] = 0;
            local_280[0x65] = 0;
            local_280[0x66] = 0;
            local_280[0x67] = 0;
            local_280[0x78] = 0;
            local_280[0x79] = 0;
            local_280[0x7a] = 0;
            local_280[0x7b] = 0;
            local_280[0x7c] = 0;
            local_280[0x7d] = 0;
            local_280[0x7e] = 0;
            local_280[0x7f] = 0;
            local_280[0x70] = 0;
            local_280[0x71] = 0;
            local_280[0x72] = 0;
            local_280[0x73] = 0;
            local_280[0x74] = 0;
            local_280[0x75] = 0;
            local_280[0x76] = 0;
            local_280[0x77] = 0;
            local_280[0x48] = 0;
            local_280[0x49] = 0;
            local_280[0x4a] = 0;
            local_280[0x4b] = 0;
            local_280[0x4c] = 0;
            local_280[0x4d] = 0;
            local_280[0x4e] = 0;
            local_280[0x4f] = 0;
            local_280[0x40] = 0;
            local_280[0x41] = 0;
            local_280[0x42] = 0;
            local_280[0x43] = 0;
            local_280[0x44] = 0;
            local_280[0x45] = 0;
            local_280[0x46] = 0;
            local_280[0x47] = 0;
            local_280[0x58] = 0;
            local_280[0x59] = 0;
            local_280[0x5a] = 0;
            local_280[0x5b] = 0;
            local_280[0x5c] = 0;
            local_280[0x5d] = 0;
            local_280[0x5e] = 0;
            local_280[0x5f] = 0;
            local_280[0x50] = 0;
            local_280[0x51] = 0;
            local_280[0x52] = 0;
            local_280[0x53] = 0;
            local_280[0x54] = 0;
            local_280[0x55] = 0;
            local_280[0x56] = 0;
            local_280[0x57] = 0;
            local_280[0x28] = 0;
            local_280[0x29] = 0;
            local_280[0x2a] = 0;
            local_280[0x2b] = 0;
            local_280[0x2c] = 0;
            local_280[0x2d] = 0;
            local_280[0x2e] = 0;
            local_280[0x2f] = 0;
            local_280[0x20] = 0;
            local_280[0x21] = 0;
            local_280[0x22] = 0;
            local_280[0x23] = 0;
            local_280[0x24] = 0;
            local_280[0x25] = 0;
            local_280[0x26] = 0;
            local_280[0x27] = 0;
            local_280[0x38] = 0;
            local_280[0x39] = 0;
            local_280[0x3a] = 0;
            local_280[0x3b] = 0;
            local_280[0x3c] = 0;
            local_280[0x3d] = 0;
            local_280[0x3e] = 0;
            local_280[0x3f] = 0;
            local_280[0x30] = 0;
            local_280[0x31] = 0;
            local_280[0x32] = 0;
            local_280[0x33] = 0;
            local_280[0x34] = 0;
            local_280[0x35] = 0;
            local_280[0x36] = 0;
            local_280[0x37] = 0;
            local_280[8] = 0;
            local_280[9] = 0;
            local_280[10] = 0;
            local_280[0xb] = 0;
            local_280[0xc] = 0;
            local_280[0xd] = 0;
            local_280[0xe] = 0;
            local_280[0xf] = 0;
            local_280[0] = 0;
            local_280[1] = 0;
            local_280[2] = 0;
            local_280[3] = 0;
            local_280[4] = 0;
            local_280[5] = 0;
            local_280[6] = 0;
            local_280[7] = 0;
            local_280[0x18] = 0;
            local_280[0x19] = 0;
            local_280[0x1a] = 0;
            local_280[0x1b] = 0;
            local_280[0x1c] = 0;
            local_280[0x1d] = 0;
            local_280[0x1e] = 0;
            local_280[0x1f] = 0;
            local_280[0x10] = 0;
            local_280[0x11] = 0;
            local_280[0x12] = 0;
            local_280[0x13] = 0;
            local_280[0x14] = 0;
            local_280[0x15] = 0;
            local_280[0x16] = 0;
            local_280[0x17] = 0;
            local_290 = 0;
            local_330[0x11] = 0;
            local_330[0x10] = 0;
            local_330[0x13] = 0;
            local_330[0x12] = 0;
            local_330[0xd] = 0;
            local_330[0xc] = 0;
            local_330[0xf] = 0;
            local_330[0xe] = 0;
            local_330[9] = 0;
            local_330[8] = 0;
            local_330[0xb] = 0;
            local_330[10] = 0;
            local_330[5] = 0;
            local_330[4] = 0;
            local_330[7] = 0;
            local_330[6] = 0;
            local_330[1] = 0;
            local_330[0] = 0;
            local_330[3] = 0;
            local_330[2] = 0;
            local_340 = 0;
            local_3e0[0x11] = 0;
            local_3e0[0x10] = 0;
            local_3e0[0x13] = 0;
            local_3e0[0x12] = 0;
            local_3e0[0xd] = 0;
            local_3e0[0xc] = 0;
            local_3e0[0xf] = 0;
            local_3e0[0xe] = 0;
            local_3e0[9] = 0;
            local_3e0[8] = 0;
            local_3e0[0xb] = 0;
            local_3e0[10] = 0;
            local_3e0[7] = 0;
            local_3e0[6] = 0;
            local_3e0[3] = 0;
            local_3e0[2] = 0;
            local_3e0[5] = 0;
            local_3e0[4] = 0;
            uStack_3e8 = 0;
            local_3f0 = 0;
            local_3e0[1] = 0;
            local_3e0[0] = 0;
            uStack_408 = 0;
            local_410 = 0;
            uStack_3f8 = 0;
            uStack_400 = 0;
            uStack_418 = 0;
            local_420 = 0;
            if (DAT_0012ea68 != 0) {
              uVar12 = (ulong)DAT_0012ea60;
              if (DAT_0012ea60 != 0) {
                if (DAT_0012ea60 == 1) {
                  uVar20 = 0;
                }
                else {
                  uVar20 = uVar12 & 0xfffffffe;
                  puVar19 = (undefined4 *)(DAT_0012ea68 + 0x80);
                  uVar14 = uVar20;
                  do {
                    puVar19[-0x14] = 0xfffbd1b0;
                    *puVar19 = 0xfffbd1b0;
                    uVar14 = uVar14 - 2;
                    puVar19 = puVar19 + 0x28;
                  } while (uVar14 != 0);
                  if (uVar20 == uVar12) goto LAB_00119688;
                }
                lVar13 = uVar12 - uVar20;
                puVar19 = (undefined4 *)(lVar22 + uVar20 * 0x50 + 0x30);
                do {
                  *puVar19 = 0xfffbd1b0;
                  lVar13 = lVar13 + -1;
                  puVar19 = puVar19 + 0x14;
                } while (lVar13 != 0);
              }
LAB_00119688:
              local_46c = 0;
              uVar17 = 0;
              local_290 = 0;
LAB_00119694:
              do {
                uVar12 = ftell(param_1);
                do {
                  pcVar6 = fgets(param_2,0x100,param_1);
                  if (pcVar6 == (char *)0x0) goto LAB_00119bcc;
                  sVar7 = strlen(param_2);
                  uVar18 = (uint)sVar7;
                  if (0 < (int)uVar18) {
                    uVar14 = sVar7 & 0xffffffff;
                    do {
                      uVar18 = uVar18 - 1;
                      if (0x20 < (byte)param_2[uVar18] ||
                          (1L << ((ulong)(byte)param_2[uVar18] & 0x3f) & 0x100002400U) == 0)
                      goto LAB_001196f0;
                      uVar20 = uVar14 - 1;
                      bVar1 = 0 < (long)uVar14;
                      uVar14 = uVar20;
                    } while (uVar20 != 0 && bVar1);
                    uVar14 = 0;
LAB_001196f0:
                    param_2[(int)uVar14] = '\0';
                  }
                  if (param_3 == 2) {
                    sVar7 = strnlen(param_2,0x200);
                    if (sVar7 != 0) {
                      uVar14 = 0;
                      uVar20 = 1;
                      do {
                        bVar11 = param_2[uVar14];
                        if (bVar11 - 0x20 < 0x5b) {
                          uVar18 = ((uint)bVar11 - ((int)uVar14 + (int)(uVar14 / 5) * -5)) + 0x3b;
                          bVar11 = (char)uVar18 + (char)((uVar18 & 0xff) / 0x5b) * -0x5b + 0x20;
                        }
                        param_2[uVar14] = bVar11;
                        sVar7 = strnlen(param_2,0x200);
                        bVar1 = uVar20 < sVar7;
                        uVar14 = uVar20;
                        uVar20 = (ulong)((int)uVar20 + 1);
                      } while (bVar1);
                    }
                  }
                  else if ((param_3 == 1) && (sVar7 = strnlen(param_2,0x200), sVar7 != 0)) {
                    uVar14 = 0;
                    uVar20 = 1;
                    do {
                      bVar11 = param_2[uVar14];
                      if (bVar11 - 0x20 < 0x5b) {
                        uVar18 = ((uint)bVar11 - ((int)uVar14 + (int)(uVar14 / 10) * -10)) + 0x3b;
                        bVar11 = (char)uVar18 + (char)((uVar18 & 0xff) / 0x5b) * -0x5b + 0x20;
                      }
                      param_2[uVar14] = bVar11;
                      sVar7 = strnlen(param_2,0x200);
                      bVar1 = uVar20 < sVar7;
                      uVar14 = uVar20;
                      uVar20 = (ulong)((int)uVar20 + 1);
                    } while (bVar1);
                  }
                  sVar7 = strlen(param_2);
                } while (((int)sVar7 == 0) || (*param_2 == '#'));
                if ((*param_2 == '[') && (param_2[(int)sVar7 + -1] == ']')) goto LAB_00119bcc;
                if (*(int *)PTR_DAT_0012d278 == 1) {
                  __android_log_print(4,"thermal_core","line: %s\n",param_2);
                }
                iVar4 = strncmp(param_2,"level",5);
                if (iVar4 == 0) {
                  cVar2 = *param_2;
                  pcVar6 = param_2;
                  while (pcVar10 = pcVar6, cVar2 != '\0') {
                    if (cVar2 == '=') {
                      pcVar10 = pcVar6 + 1;
                      *pcVar6 = '\0';
                      break;
                    }
                    pcVar6 = pcVar6 + 1;
                    cVar2 = *pcVar6;
                  }
                  pcVar6 = param_2 + (sVar7 - (long)pcVar10);
                  for (; iVar4 = (int)pcVar6, *pcVar10 == ' ' || *pcVar10 == '\t';
                      pcVar10 = pcVar10 + 1) {
                    pcVar6 = pcVar6 + -1;
                  }
                  if (0x100 < iVar4) {
                    if (*(int *)PTR_DAT_0012d278 == 1) {
                      __android_log_print(4,"thermal_core","level list overflow\n");
                    }
                    iVar4 = 0x100;
                  }
                  __memcpy_chk(&local_180,pcVar10,(long)iVar4,0x100);
                  if ((byte)local_180 == 0x5b) {
                    uVar17 = 0;
                    pbVar15 = (byte *)&local_180;
                    bVar1 = true;
                    bVar11 = 0x5b;
                    local_290 = local_290 & 0xffffffff00000000;
LAB_001199e0:
                    if (bVar11 < 0x5b) {
                      if (bVar11 == 0x2c) {
                        bVar1 = true;
                        goto LAB_001199d8;
                      }
                      if (bVar11 == 0) goto LAB_00119694;
LAB_00119a04:
                      if ((bVar11 != 0x20) && (bVar1)) {
                        if (uVar17 < 0x14) {
                          local_330[uVar17] = pbVar15;
                          uVar17 = (int)local_290 + 1;
                          bVar1 = false;
                          local_290 = CONCAT44(local_290._4_4_,uVar17);
                          pbVar15 = pbVar15 + 1;
                          bVar11 = *pbVar15;
                          goto LAB_001199e0;
                        }
LAB_00119b98:
                        if (*(int *)PTR_DAT_0012d278 == 1) {
                          __android_log_print(4,"thermal_core",
                                              "List items are more than MAX_NUM_PTRS %d\n",0x14);
                        }
                        goto LAB_00119694;
                      }
                    }
                    else {
                      if ((bVar11 != 0x5d) && (bVar11 != 0x5b)) goto LAB_00119a04;
LAB_001199d8:
                      *pbVar15 = 0;
                    }
                    pbVar15 = pbVar15 + 1;
                    bVar11 = *pbVar15;
                    goto LAB_001199e0;
                  }
                  goto LAB_00119694;
                }
                iVar4 = strncmp(param_2,"threshold",9);
                if (iVar4 == 0) {
                  cVar2 = *param_2;
                  pcVar6 = param_2;
                  while (pcVar10 = pcVar6, cVar2 != '\0') {
                    if (cVar2 == '=') {
                      pcVar10 = pcVar6 + 1;
                      *pcVar6 = '\0';
                      break;
                    }
                    pcVar6 = pcVar6 + 1;
                    cVar2 = *pcVar6;
                  }
                  pcVar6 = param_2 + (sVar7 - (long)pcVar10);
                  for (; iVar4 = (int)pcVar6, *pcVar10 == ' ' || *pcVar10 == '\t';
                      pcVar10 = pcVar10 + 1) {
                    pcVar6 = pcVar6 + -1;
                  }
                  if (0x100 < iVar4) {
                    if (*(int *)PTR_DAT_0012d278 == 1) {
                      __android_log_print(4,"thermal_core","Threshold list overflow\n");
                    }
                    iVar4 = 0x100;
                  }
                  __memcpy_chk(local_280,pcVar10,(long)iVar4,0x100);
                  if (local_280[0] == 0x5b) {
                    local_46c = 0;
                    pbVar15 = local_280;
                    bVar1 = true;
                    bVar11 = 0x5b;
                    local_340 = local_340 & 0xffffffff00000000;
                    do {
                      while (0x5a < bVar11) {
                        if ((bVar11 != 0x5d) && (bVar11 != 0x5b)) goto LAB_00119b10;
LAB_00119ae4:
                        *pbVar15 = 0;
LAB_00119ae8:
                        pbVar15 = pbVar15 + 1;
                        bVar11 = *pbVar15;
                      }
                      if (bVar11 == 0x2c) {
                        bVar1 = true;
                        goto LAB_00119ae4;
                      }
                      if (bVar11 == 0) break;
LAB_00119b10:
                      if ((bVar11 == 0x20) || (!bVar1)) goto LAB_00119ae8;
                      if (0x13 < local_46c) goto LAB_00119b98;
                      local_3e0[local_46c] = pbVar15;
                      local_46c = (int)local_340 + 1;
                      bVar1 = false;
                      local_340 = CONCAT44(local_340._4_4_,local_46c);
                      pbVar15 = pbVar15 + 1;
                      bVar11 = *pbVar15;
                    } while( true );
                  }
                }
                else {
                  iVar4 = strncmp(param_2,"sensor",6);
                  if (iVar4 == 0) {
                    cVar2 = *param_2;
                    pcVar6 = param_2;
                    while (pcVar10 = pcVar6, cVar2 != '\0') {
                      if (cVar2 == '=') {
                        pcVar10 = pcVar6 + 1;
                        *pcVar6 = '\0';
                        break;
                      }
                      pcVar6 = pcVar6 + 1;
                      cVar2 = *pcVar6;
                    }
                    for (; *pcVar10 == ' ' || *pcVar10 == '\t'; pcVar10 = pcVar10 + 1) {
                    }
                    snprintf(&DAT_0012ea12,0x1e,(char *)0x1e,&DAT_00102ab3);
                  }
                }
              } while( true );
            }
            goto LAB_001194a8;
          }
          if (*(int *)PTR_DAT_0012d278 != 1) goto LAB_001194a8;
          uVar8 = 4;
          pcVar6 = "unsupport thermal hal threshold type %s\n";
          goto LAB_00119588;
        }
        goto LAB_001194a8;
      }
      break;
    }
  }
  if ((int)local_448 < 0) {
    pcVar6 = "Negative file position %s\n";
  }
  else {
    iVar4 = fseek(param_1,local_448 & 0xffffffff,0);
    if (iVar4 != -1) goto LAB_00119efc;
    pcVar6 = "fseek failed: %s\n";
  }
  piVar9 = (int *)__errno();
  pcVar10 = strerror(*piVar9);
  __android_log_print(6,"thermal_core",pcVar6,pcVar10);
LAB_00119efc:
  if (*(long *)(lVar3 + 0x28) == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00119bcc:
  __android_log_print(4,"thermal_core","overheat_warning sensor_name %s\n",&DAT_0012ea12);
  if (DAT_0012ea68 != 0) {
    if (DAT_0012ea60 != 0) {
      pcVar6 = (char *)(DAT_0012ea68 + 4);
      sVar7 = __strlen_chk(&DAT_0012ea12,0x3c);
      iVar4 = strncmp(pcVar6,&DAT_0012ea12,sVar7);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        lVar22 = 0x54;
        uVar14 = 1;
        do {
          uVar20 = uVar14;
          if (DAT_0012ea60 <= uVar20) goto LAB_00119ca4;
          pcVar6 = (char *)(DAT_0012ea68 + lVar22);
          sVar7 = __strlen_chk(&DAT_0012ea12,0x3c);
          iVar4 = strncmp(pcVar6,&DAT_0012ea12,sVar7);
          lVar22 = lVar22 + 0x50;
          uVar14 = uVar20 + 1;
        } while (iVar4 != 0);
        if ((int)(uVar20 + 1) == 0) goto LAB_00119cc8;
        iVar4 = (int)uVar20;
      }
      if ((uVar17 != 0) && (uVar17 == local_46c)) {
        uVar14 = (ulong)local_46c;
        puVar16 = local_330;
        puVar21 = local_3e0;
        do {
          sscanf((char *)*puVar21,"%d",&local_434);
          pcVar6 = (char *)*puVar16;
          iVar5 = strncmp(pcVar6,"severe",6);
          if (iVar5 == 0) {
            pcVar6 = "TYPE=thermal_hal_update NAME=%s THRESHOLD=%d";
            *(int *)(DAT_0012ea68 + (long)iVar4 * 0x50 + 0x30) = local_434;
LAB_00119d3c:
            snprintf((char *)&local_420,0x40,(char *)0x40,pcVar6,local_430,
                     (ulong)(uint)(local_434 / 1000));
            send_notification_to_thermal_hal(&local_420);
          }
          else {
            iVar5 = strncmp(pcVar6,"critical",8);
            if (iVar5 == 0) {
              pcVar6 = "TYPE=thermal_hal_update NAME=%s CRITICAL=%d";
              goto LAB_00119d3c;
            }
            iVar5 = strncmp(pcVar6,"emergency",9);
            if (iVar5 == 0) {
              pcVar6 = "TYPE=thermal_hal_update NAME=%s EMERGENCY=%d";
              goto LAB_00119d3c;
            }
            iVar5 = strncmp(pcVar6,"shutdown",8);
            if (iVar5 == 0) {
              pcVar6 = "TYPE=thermal_hal_update NAME=%s SHUTDOWN=%d";
              goto LAB_00119d3c;
            }
          }
          uVar14 = uVar14 - 1;
          puVar16 = puVar16 + 1;
          puVar21 = puVar21 + 1;
        } while (uVar14 != 0);
      }
      if ((int)uVar12 < 0) {
        piVar9 = (int *)__errno();
        pcVar10 = strerror(*piVar9);
        uVar8 = 6;
        pcVar6 = "Negative file position %s\n";
      }
      else {
        iVar4 = fseek(param_1,uVar12 & 0xffffffff,0);
        if (iVar4 != -1) goto LAB_001194a8;
        piVar9 = (int *)__errno();
        pcVar10 = strerror(*piVar9);
        uVar8 = 6;
        pcVar6 = "fseek failed: %s\n";
      }
LAB_00119588:
      __android_log_print(uVar8,"thermal_core",pcVar6,pcVar10);
      goto LAB_001194a8;
    }
LAB_00119ca4:
    __android_log_print(6,"thermal_core","Failed to find thermal zone index of %s\n",&DAT_0012ea12);
  }
LAB_00119cc8:
  __android_log_print(4,"thermal_core","skin sensor not found\n");
LAB_001194a8:
  local_448 = ftell(param_1);
  goto LAB_001192b8;
}
