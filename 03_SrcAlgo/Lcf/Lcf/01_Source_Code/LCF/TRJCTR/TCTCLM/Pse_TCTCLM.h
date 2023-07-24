/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCLM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TCTCLM.h
//! @brief     (TCTCLM) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TCTCLM_VehReset
void TCTCLM_VehResetData(void);
void TCTCLM_VehReset(void)
{
	
	TCTCLM_VehResetData();
	
	DW_tctclm_Unit_Delay_DSTATE_fo = 0U;
	DW_tctclm_Unit_Delay13_DSTATE = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_p = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_d = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_n = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_p5 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_nu = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_c = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_i = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_p3 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_ck = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_j = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_pn = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_g = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_cw = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_p5d = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_jg = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_b = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_b2 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_gr = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_a = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_h = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_jl = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_i4 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_ir = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_dg = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_jw = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_f = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_l = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_g3 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_k = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_kq = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_fl = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_m = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_e = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_i0 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_o = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_pa = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_js = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_nj = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_ip = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_i0y = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_lj = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_oj = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_jm = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_ld = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_m3 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_hw = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_kw = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_ei = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_dm = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_ks = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_jo = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_hi = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_bb = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_j5 = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_lu = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_fm = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_bs = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_lx = 0U;
	DW_tctclm_Unit_Delay13_DSTATE_dn = 0U;
	DW_tctclm_Unit_Delay2_DSTATE_p = 0U;
	DW_tctclm_Unit_Delay_DSTATE_p = 0U;
	DW_tctclm_Unit_Delay_DSTATE_ks = 0U;
	DW_tctclm_Unit_Delay1_DSTATE_g = 0U;
	DW_tctclm_UnitDelay5_DSTATE = 0.F;
	DW_tctclm_UnitDelay1_DSTATE = 0.F;
	DW_tctclm_Unit_Delay_DSTATE = 0.F;
	DW_tctclm_Unit_Delay_DSTATE_k = 0.F;
	DW_tctclm_Unit_Delay_DSTATE_l = 0.F;
	DW_tctclm_Unit_Delay1_DSTATE = 0.F;
	DW_tctclm_Unit_Delay3_DSTATE = 0.F;
	DW_tctclm_Unit_Delay_DSTATE_f = 0.F;
	DW_tctclm_Unit_Delay1_DSTATE_c = 0.F;
	DW_tctclm_Unit_Delay2_DSTATE = 0.F;
	
}
#define TCTCLM_VehReset TCTCLM_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

