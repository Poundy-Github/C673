/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTEST
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TCTEST.h
//! @brief     (TCTEST) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TCTEST_VehReset
void TCTEST_VehResetData(void);
void TCTEST_VehReset(void)
{
	uint8 k1;
	
	TCTEST_VehResetData();
	
	DW_tctest_Unit_Delay_DSTATE_ei = 0U;
	DW_tctest_Unit_Delay4_DSTATE = 0.F;
	DW_tctest_Unit_Delay_DSTATE = 0.F;
	DW_tctest_Unit_Delay6_DSTATE = 0.F;
	DW_tctest_Unit_Delay_DSTATE_n = 0.F;
	DW_tctest_Unit_Delay1_DSTATE = 0.F;
	DW_tctest_Unit_Delay2_DSTATE = 0.F;
	DW_tctest_Unit_Delay3_DSTATE = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_k = 0.F;
	DW_tctest_Unit_Delay1_DSTATE_j = 0.F;
	DW_tctest_Unit_Delay6_DSTATE_h = 0.F;
	DW_tctest_Unit_Delay_DSTATE_e = 0.F;
	DW_tctest_Unit_Delay1_DSTATE_e = 0.F;
	DW_tctest_Unit_Delay2_DSTATE_i = 0.F;
	DW_tctest_Unit_Delay3_DSTATE_m = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_j = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_e = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_k3 = 0.F;
	DW_tctest_Unit_Delay1_DSTATE_l = 0.F;
	DW_tctest_Unit_Delay6_DSTATE_i = 0.F;
	DW_tctest_Unit_Delay2_DSTATE_e = 0.F;
	DW_tctest_Unit_Delay_DSTATE_e5 = 0.F;
	DW_tctest_Unit_Delay_DSTATE_a0 = 0.F;
	DW_tctest_Unit_Delay1_DSTATE_b = 0.F;
	DW_tctest_Unit_Delay2_DSTATE_b = 0.F;
	DW_tctest_Unit_Delay3_DSTATE_mt = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_d = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_b = 0.F;
	DW_tctest_Unit_Delay1_DSTATE_a = 0.F;
	DW_tctest_UnitDelay2_DSTATE = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_f = 0.F;
	DW_tctest_UnitDelay2_DSTATE_h = 0.F;
	DW_tctest_UnitDelay2_DSTATE_b = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_ex = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_m = 0.F;
	DW_tctest_Unit_Delay6_DSTATE_hj = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_n = 0.F;
	DW_tctest_UnitDelay2_DSTATE_d = 0.F;
	DW_tctest_Unit_Delay_DSTATE_p = 0.F;
	DW_tctest_UnitDelay2_DSTATE_m = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_o = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_og = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_g = 0.F;
	DW_tctest_Unit_Delay4_DSTATE_jr = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_tctest_Unit_Delay_DSTATE_a[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 3; k1++)
	{
		DW_tctest_Unit_Delay_DSTATE_nf[k1] = 0.F;
		DW_tctest_Unit_Delay_DSTATE_h[k1] = 0.F;
	}
	
	for(k1 = 0; k1 < 4; k1++)
	{
		DW_tctest_Unit_Delay_DSTATE_c[k1] = 0.F;
	}
	
}
#define TCTEST_VehReset TCTEST_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

