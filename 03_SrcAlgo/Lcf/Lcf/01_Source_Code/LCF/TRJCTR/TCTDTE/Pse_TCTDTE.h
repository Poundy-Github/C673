/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTDTE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TCTDTE.h
//! @brief     (TCTDTE) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TCTDTE_VehReset
void TCTDTE_VehResetData(void);
void TCTDTE_VehReset(void)
{
	
	TCTDTE_VehResetData();
	
	DW_tctdte_Unit_Delay_DSTATE_mt = 0U;
	DW_tctdte_Unit_Delay_DSTATE = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_l = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_k = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_i = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_p = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_j = 0.F;
	DW_tctdte_Unit_Delay1_DSTATE = 0.F;
	DW_tctdte_Unit_Delay2_DSTATE = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_o = 0.F;
	DW_tctdte_Unit_Delay4_DSTATE = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_h = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_m = 0.F;
	DW_tctdte_Unit_Delay1_DSTATE_d = 0.F;
	DW_tctdte_Unit_Delay2_DSTATE_p = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_d = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_n = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_e = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_lo = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_j = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_jz = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_i0 = 0.F;
	DW_tctdte_Unit_Delay5_DSTATE = 0.F;
	DW_tctdte_Unit_Delay1_DSTATE_m = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_he = 0.F;
	DW_tctdte_Unit_Delay2_DSTATE_g = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_c = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_o2 = 0.F;
	DW_tctdte_Unit_Delay5_DSTATE_e = 0.F;
	DW_tctdte_Unit_Delay1_DSTATE_o = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_d = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_m0 = 0.F;
	DW_tctdte_Unit_Delay1_DSTATE_h = 0.F;
	DW_tctdte_Unit_Delay2_DSTATE_e = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_g = 0.F;
	DW_tctdte_Unit_Delay4_DSTATE_p = 0.F;
	DW_tctdte_Unit_Delay_DSTATE_i = 0.F;
	DW_tctdte_Unit_Delay1_DSTATE_b = 0.F;
	DW_tctdte_Unit_Delay2_DSTATE_o = 0.F;
	DW_tctdte_Unit_Delay3_DSTATE_ck = 0.F;
	DW_tctdte_Unit_Delay4_DSTATE_f = 0.F;
	DW_tctdte_UnitDelay2_DSTATE = 0.F;
	DW_tctdte_UnitDelay2_DSTATE_d = 0.F;
	DW_tctdte_UnitDelay2_DSTATE_n = 0.F;
	DW_tctdte_UnitDelay2_DSTATE_l = 0.F;
	DW_tctdte_UnitDelay2_DSTATE_c = 0.F;
	
}
#define TCTDTE_VehReset TCTDTE_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

