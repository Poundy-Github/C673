/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_LCRSIA.h
//! @brief     (LCRSIA) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_LCRSIA_SenReset
void LCRSIA_SenResetData(void);
void LCRSIA_SenReset(void)
{
	uint8 k1;
	
	LCRSIA_SenResetData();
	
	DW_lcrsia_UnitDelay2_DSTATE_p = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_j = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_m = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_jw = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_b = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_k = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_p2 = 0U;
	DW_lcrsia_UnitDelay1_DSTATE_d = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_kq = 0U;
	DW_lcrsia_UnitDelay1_DSTATE_b = 0U;
	DW_lcrsia_Unit_Delay_DSTATE_l = 0U;
	DW_lcrsia_Unit_Delay_DSTATE_b = 0U;
	DW_lcrsia_UnitDelay1_DSTATE_j = 0U;
	DW_lcrsia_UnitDelay1_DSTATE_jo = 0U;
	DW_lcrsia_UnitDelay3_DSTATE = 0U;
	DW_lcrsia_UnitDelay1_DSTATE_o = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_h = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_o = 0U;
	DW_lcrsia_UnitDelay2_DSTATE_a = 0U;
	DW_lcrsia_UnitDelay2_DSTATE = 0.F;
	DW_lcrsia_UnitDelay2_DSTATE_d = 0.F;
	DW_lcrsia_UnitDelay1_DSTATE = 0.F;
	DW_lcrsia_UnitDelay1_DSTATE_n = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_lcrsia_UnitDelay2_DSTATE_c[k1] = 0U;
	}
	
	for(k1 = 0; k1 < 8; k1++)
	{
		DW_lcrsia_Unit_Delay_DSTATE[k1] = 0.F;
	}
	
}
#define LCRSIA_SenReset LCRSIA_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

