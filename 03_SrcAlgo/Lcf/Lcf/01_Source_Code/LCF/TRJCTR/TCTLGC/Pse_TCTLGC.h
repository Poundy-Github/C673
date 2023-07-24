/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTLGC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TCTLGC.h
//! @brief     (TCTLGC) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TCTLGC_VehReset
void TCTLGC_VehResetData(void);
void TCTLGC_VehReset(void)
{
	
	TCTLGC_VehResetData();
	
	DW_tctlgc_Unit_Delay_DSTATE_cc = 0U;
	DW_tctlgc_Unit_Delay_DSTATE_j = 0U;
	DW_tctlgc_Unit_Delay1_DSTATE_lc = 0U;
	DW_tctlgc_Unit_Delay_DSTATE_lt2 = 0U;
	DW_tctlgc_Unit_Delay1_DSTATE_lu = 0U;
	DW_tctlgc_Unit_Delay_DSTATE_af = 0U;
	DW_tctlgc_Unit_Delay1_DSTATE_ph = 0U;
	DW_tctlgc_Unit_Delay_DSTATE = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_a = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_p = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_n = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_l = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_e = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_f = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_k = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_i = 0.F;
	DW_tctlgc_Unit_Delay2_DSTATE = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_b = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_o = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_eo = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_n = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_g = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_bb = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_g = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_f = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_m = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_p = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_fe = 0.F;
	DW_tctlgc_Unit_Delay2_DSTATE_e = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_bf = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_n = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_m = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_i1 = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_l = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_lt = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_im = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_l3 = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_e = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_ep = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_feo = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_ex = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_o = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_h = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_c = 0.F;
	DW_tctlgc_Unit_Delay2_DSTATE_j = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_k = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_gf = 0.F;
	DW_tctlgc_Unit_Delay3_DSTATE_ms = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_d = 0.F;
	DW_tctlgc_Unit_Delay1_DSTATE_f = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_p = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_h = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_gr = 0.F;
	DW_tctlgc_Unit_Delay_DSTATE_ir = 0.F;
	DW_tctlgc_UnitDelay2_DSTATE = 0.F;
	DW_tctlgc_UnitDelay2_DSTATE_d = 0.F;
	DW_tctlgc_UnitDelay_DSTATE = 0.F;
	DW_tctlgc_UnitDelay2_DSTATE_f = 0.F;
	DW_tctlgc_UnitDelay2_DSTATE_g = 0.F;
	DW_tctlgc_UnitDelay_DSTATE_c = 0.F;
	DW_tctlgc_UnitDelay2_DSTATE_dd = 0.F;
	DW_tctlgc_UnitDelay2_DSTATE_o = 0.F;
	DW_tctlgc_UnitDelay_DSTATE_a = 0.F;
	
}
#define TCTLGC_VehReset TCTLGC_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

