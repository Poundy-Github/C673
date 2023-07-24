/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPLSIA.h
//! @brief     (DPLSIA) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPLSIA_SenReset
void DPLSIA_SenResetData(void);
void DPLSIA_SenReset(void)
{
	uint8 k1;
	
	DPLSIA_SenResetData();
	
	DW_dplsia_UnitDelay2_DSTATE_o = 0U;
	DW_dplsia_UnitDelay2_DSTATE_g = 0U;
	DW_dplsia_UnitDelay2_DSTATE_f = 0U;
	DW_dplsia_UnitDelay2_DSTATE_oc = 0U;
	DW_dplsia_UnitDelay2_DSTATE_b = 0U;
	DW_dplsia_UnitDelay2_DSTATE_k = 0U;
	DW_dplsia_Unit_Delay_DSTATE = 0U;
	DW_dplsia_Unit_Delay_DSTATE_p = 0U;
	DW_dplsia_UnitDelay2_DSTATE_mk = 0U;
	DW_dplsia_UnitDelay1_DSTATE_n = 0U;
	DW_dplsia_UnitDelay2_DSTATE_a = 0U;
	DW_dplsia_UnitDelay1_DSTATE_j = 0U;
	DW_dplsia_UnitDelay1_DSTATE_nx = 0U;
	DW_dplsia_UnitDelay1_DSTATE_d = 0U;
	DW_dplsia_UnitDelay3_DSTATE = 0U;
	DW_dplsia_UnitDelay1_DSTATE_p = 0U;
	DW_dplsia_UnitDelay2_DSTATE_d = 0U;
	DW_dplsia_UnitDelay2_DSTATE_h = 0U;
	DW_dplsia_UnitDelay2_DSTATE_ly = 0U;
	DW_dplsia_UnitDelay2_DSTATE_n = 0U;
	DW_dplsia_UnitDelay2_DSTATE_la = 0U;
	DW_dplsia_UnitDelay2_DSTATE_j = 0U;
	DW_dplsia_UnitDelay2_DSTATE_kx = 0U;
	DW_dplsia_UnitDelay2_DSTATE_id = 0U;
	DW_dplsia_UnitDelay2_DSTATE_e = 0U;
	DW_dplsia_UnitDelay2_DSTATE_le = 0U;
	DW_dplsia_UnitDelay1_DSTATE_l = 0U;
	DW_dplsia_UnitDelay2_DSTATE_ix = 0U;
	DW_dplsia_UnitDelay1_DSTATE_b = 0U;
	DW_dplsia_UnitDelay1_DSTATE_f = 0U;
	DW_dplsia_UnitDelay1_DSTATE_o = 0U;
	DW_dplsia_UnitDelay3_DSTATE_e = 0U;
	DW_dplsia_UnitDelay1_DSTATE_b5 = 0U;
	DW_dplsia_UnitDelay2_DSTATE_jc = 0U;
	DW_dplsia_UnitDelay2_DSTATE_c = 0U;
	DW_dplsia_UnitDelay2_DSTATE_c5 = 0U;
	DW_dplsia_UnitDelay2_DSTATE = 0.F;
	DW_dplsia_UnitDelay2_DSTATE_l = 0.F;
	DW_dplsia_UnitDelay1_DSTATE = 0.F;
	DW_dplsia_UnitDelay1_DSTATE_c = 0.F;
	DW_dplsia_UnitDelay2_DSTATE_i = 0.F;
	DW_dplsia_UnitDelay2_DSTATE_m = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_dplsia_UnitDelay2_DSTATE_p[k1] = 0U;
		DW_dplsia_UnitDelay1_DSTATE_jp[k1] = 0U;
	}
	
	for(k1 = 0; k1 < 8; k1++)
	{
		DW_dplsia_Unit_Delay1_DSTATE[k1] = 0.F;
	}
	
}
#define DPLSIA_SenReset DPLSIA_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

