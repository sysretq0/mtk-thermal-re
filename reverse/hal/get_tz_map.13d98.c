// get_tz_map @ 0x13d98
/* android::hardware::thermal::V2_0::implementation::ThermalHelper::get_tz_map() */

void __thiscall
android::hardware::thermal::V2_0::implementation::ThermalHelper::get_tz_map(ThermalHelper *this)

{
  char *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined4 *puVar9;
  ulong uVar10;
  undefined *puVar11;
  long lVar12;
  undefined *puVar13;
  
  puVar3 = PTR_tz_data_v3_00116b00;
  puVar2 = PTR_tz_data_v2_00116af0;
  puVar13 = PTR_tz_data_v1_00116ae8;
  puVar11 = PTR_tz_data_00116aa0;
  iVar7 = *(int *)(this + 0x88);
  if (iVar7 == 1) {
    lVar12 = 0;
    do {
      pcVar1 = puVar11 + lVar12;
      iVar7 = snprintf(pcVar1,0x14,(char *)0x14,&DAT_00107c3c,puVar13 + lVar12);
      if (iVar7 < 0) {
        __android_log_print(5,0,"%s: snprintf fail: %d","get_tz_map",iVar7);
      }
      uVar4 = *(undefined4 *)(puVar13 + lVar12 + 0x28);
      lVar12 = lVar12 + 0x40;
      pcVar1[0x3c] = '\x01';
      pcVar1[0x3d] = '\0';
      pcVar1[0x3e] = '\0';
      pcVar1[0x3f] = '\0';
      *(undefined4 *)(pcVar1 + 0x28) = uVar4;
    } while (lVar12 != 0x280);
  }
  else if (iVar7 == 2) {
    lVar12 = 0;
    iVar7 = 0;
    puVar13 = PTR_tz_data_00116aa0 + 0x28;
    do {
      pcVar1 = puVar11 + lVar12 * 0x40;
      puVar3 = puVar2 + (long)iVar7 * 0x40;
      iVar6 = snprintf(pcVar1,0x14,(char *)0x14,&DAT_00107c3c,puVar3);
      if (iVar6 < 0) {
        __android_log_print(5,0,"%s: snprintf fail: %d","get_tz_map",iVar6);
      }
      iVar6 = *(int *)(puVar3 + 0x3c);
      *(int *)(pcVar1 + 0x3c) = iVar6;
      if (0 < iVar6) {
        lVar8 = 0;
        puVar9 = (undefined4 *)(puVar2 + (long)iVar7 * 0x40 + 0x28);
        do {
          *(undefined4 *)(puVar13 + lVar8 * 4) = *puVar9;
          iVar6 = *(int *)(pcVar1 + 0x3c);
          lVar8 = lVar8 + 1;
          puVar9 = puVar9 + 0x10;
        } while (lVar8 < iVar6);
      }
      iVar5 = iVar6 + -1;
      if (iVar5 == 0 || iVar6 < 1) {
        iVar5 = 0;
      }
      iVar7 = iVar7 + iVar5 + 1;
      lVar12 = lVar12 + 1;
      puVar13 = puVar13 + 0x40;
    } while (lVar12 != 10);
  }
  else if (iVar7 == 3) {
    lVar12 = 0;
    iVar7 = 0;
    puVar13 = PTR_tz_data_00116aa0 + 0x28;
    do {
      pcVar1 = puVar11 + lVar12 * 0x40;
      puVar2 = puVar3 + (long)iVar7 * 0x40;
      iVar6 = snprintf(pcVar1,0x14,(char *)0x14,&DAT_00107c3c,puVar2);
      if (iVar6 < 0) {
        __android_log_print(5,0,"%s: snprintf fail: %d","get_tz_map",iVar6);
      }
      iVar6 = *(int *)(puVar2 + 0x3c);
      *(int *)(pcVar1 + 0x3c) = iVar6;
      if (0 < iVar6) {
        lVar8 = 0;
        puVar9 = (undefined4 *)(puVar3 + (long)iVar7 * 0x40 + 0x28);
        do {
          *(undefined4 *)(puVar13 + lVar8 * 4) = *puVar9;
          iVar6 = *(int *)(pcVar1 + 0x3c);
          lVar8 = lVar8 + 1;
          puVar9 = puVar9 + 0x10;
        } while (lVar8 < iVar6);
      }
      iVar5 = iVar6 + -1;
      if (iVar5 == 0 || iVar6 < 1) {
        iVar5 = 0;
      }
      iVar7 = iVar7 + iVar5 + 1;
      lVar12 = lVar12 + 1;
      puVar13 = puVar13 + 0x40;
    } while (lVar12 != 10);
  }
  uVar10 = 0;
  puVar11 = PTR_tz_data_00116aa0;
  do {
    __android_log_print(5,0,"%s: tz%d, name=%s, label=%s, muti_tz_num=%d","get_tz_map",
                        uVar10 & 0xffffffff,puVar11,puVar11 + 0x14,*(undefined4 *)(puVar11 + 0x3c));
    __android_log_print(5,0,"tz_idx0:%d, tz_idx1:%d,tz_idx2:%d,tz_idx3:%d,tz_idx4:%d,",
                        *(undefined4 *)(puVar11 + 0x28),*(undefined4 *)(puVar11 + 0x2c),
                        *(undefined4 *)(puVar11 + 0x30),*(undefined4 *)(puVar11 + 0x34),
                        *(undefined4 *)(puVar11 + 0x38));
    uVar10 = uVar10 + 1;
    puVar11 = puVar11 + 0x40;
  } while (uVar10 != 10);
  return;
}
