/* Recovered from thermal_core (arm64, stripped, Ghidra decompilation)
 * Symbol: calcu_ap_param   VMA: 0x28e58   (see reverse/symbols.csv)
 */

void calcu_ap_param(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,int param_6,
                   undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  time_t __time1;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  double dVar11;
  int local_6c;
  long local_68;
  
  lVar5 = tpidr_el0;
  local_68 = *(long *)(lVar5 + 0x28);
  local_6c = 0;
  mtk_thermal_get_tpcb(&local_6c,param_7);
  iVar6 = local_6c;
  __time1 = time((time_t *)0x0);
  uVar10 = 1000;
  if ((__time1 != -1) && (DAT_0012f060 != 0)) {
    dVar11 = difftime(__time1,DAT_0012f060);
    uVar10 = (ulong)(dVar11 * 1000.0);
  }
  DAT_0012f060 = __time1;
  iVar7 = mtk_thermal_get_tpcb_target();
  if (iVar7 == -1) {
    DAT_0012f06c = 1000;
    DAT_0012f07c = 0x15180;
    iVar1 = 0;
    goto joined_r0x001291c0;
  }
  iVar1 = iVar7 + -25000;
  if (iVar7 == 25000) {
    iVar1 = 1;
  }
  if (uVar10 == 0) {
    DAT_0012f078 = 0;
    DAT_0012f07c = 0x15180;
    DAT_0012f074 = iVar6;
  }
  else {
    uVar8 = (uint)((long)iVar6 - (long)DAT_0012f070);
    uVar3 = DAT_0012f074 - DAT_0012f068;
    iVar9 = 0;
    if (DAT_0012f068 != 0) {
      iVar9 = DAT_0012f074 - iVar6;
    }
    DAT_0012f068 = DAT_0012f074;
    if (((int)uVar8 < 1 || (int)uVar3 < 1) && (-1 < (int)(uVar3 & uVar8))) {
      if (-1 < (int)uVar8) goto LAB_00128f84;
LAB_0012905c:
      uVar4 = 0;
      if (uVar10 != 0) {
        uVar4 = (ulong)(long)(int)-(uVar8 * param_5) / uVar10;
      }
      iVar9 = 0;
      if (uVar10 != 0) {
        iVar9 = (int)((ulong)(long)(int)(uVar8 * -1000) / uVar10);
      }
      DAT_0012f078 = -iVar9;
      iVar9 = -(int)((uVar4 * (long)(int)DAT_0012e7a0) / 100);
    }
    else {
      if (iVar9 != 0) {
        iVar2 = 0;
        if (iVar6 != 0) {
          iVar2 = (iVar9 * 100) / iVar6;
        }
        DAT_0012e7a0 = DAT_0012e7a0 - iVar2;
      }
      DAT_0012e7a0 = DAT_0012e7a0 & ((int)DAT_0012e7a0 >> 0x1f ^ 0xffffffffU);
      if (99 < (int)DAT_0012e7a0) {
        DAT_0012e7a0 = 100;
      }
      if ((int)uVar8 < 0) goto LAB_0012905c;
LAB_00128f84:
      uVar4 = 0;
      if (uVar10 != 0) {
        uVar4 = (ulong)(long)(int)(uVar8 * param_5) / uVar10;
      }
      DAT_0012f078 = 0;
      if (uVar10 != 0) {
        DAT_0012f078 = (int)((ulong)(((long)iVar6 - (long)DAT_0012f070) * 1000) / uVar10);
      }
      iVar9 = (int)((uVar4 * (long)(int)DAT_0012e7a0) / 100);
    }
    DAT_0012f074 = iVar6 + iVar9;
  }
  if (iVar7 < DAT_0012f074) {
    iVar9 = 0;
    if (iVar1 != 0) {
      iVar9 = ((DAT_0012f074 - iVar7) * 1000) / iVar1;
    }
    DAT_0012f06c = -iVar9;
  }
  else {
    DAT_0012f06c = 0;
    if (iVar1 != 0) {
      DAT_0012f06c = ((iVar7 - DAT_0012f074) * 1000) / iVar1;
    }
  }
  if (999 < DAT_0012f06c) {
    DAT_0012f06c = 1000;
  }
  if (param_6 != 0) {
    __android_log_print(4,&DAT_00103ade,
                        "prev/cur Tpcb=%d/%d, predict=%d(%d), headroom=%d, slope=%d, t=%lld, polling_interval=%d\n"
                        ,DAT_0012f070,iVar6,DAT_0012f074,DAT_0012e7a0,DAT_0012f06c,DAT_0012f078,
                        uVar10,param_5);
  }
  DAT_0012f070 = iVar6;
  iVar1 = DAT_0012f078;
  if (iVar7 - iVar6 == 0 || iVar7 < iVar6) {
    DAT_0012f07c = 0x15180;
  }
  else {
    DAT_0012f07c = 0x15180;
    if ((0 < DAT_0012f078) && (DAT_0012f07c = 0, DAT_0012f078 != 0)) {
      DAT_0012f07c = (iVar7 - iVar6) / DAT_0012f078;
    }
  }
joined_r0x001291c0:
  DAT_0012f078 = iVar1;
  if (param_3 != (int *)0x0) {
    *param_3 = DAT_0012f07c;
  }
  if (param_1 != (int *)0x0) {
    *param_1 = iVar1;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = DAT_0012f06c;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar6;
  }
  if (*(long *)(lVar5 + 0x28) == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
