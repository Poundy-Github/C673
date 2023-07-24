/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLCEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TPLCEN.h
//! @brief     (TPLCEN) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TPLCEN_VehReset
void TPLCEN_VehResetData(void);
void TPLCEN_VehReset(void)
{
	uint8 k1;
	
	TPLCEN_VehResetData();
	
	DW_tplcen_Unit_Delay1_DSTATE = 0U;
	DW_tplcen_Unit_Delay3_DSTATE = 0U;
	DW_tplcen_UnitDelay_DSTATE_l = 0U;
	DW_tplcen_Unit_Delay3_DSTATE_h = 0U;
	DW_tplcen_Unit_Delay3_DSTATE_l = 0U;
	DW_tplcen_Unit_Delay3_DSTATE_b = 0U;
	DW_tplcen_UnitDelay1_DSTATE_k = 0U;
	DW_tplcen_Unit_Delay1_DSTATE_p = 0U;
	DW_tplcen_Unit_Delay_DSTATE_h = 0U;
	DW_tplcen_Unit_Delay1_DSTATE_l = 0U;
	DW_tplcen_Unit_Delay3_DSTATE_j = 0U;
	DW_tplcen_Unit_Delay2_DSTATE = 0U;
	DW_tplcen_Unit_Delay8_DSTATE = 0U;
	DW_tplcen_Unit_Delay1_DSTATE_d = 0U;
	DW_tplcen_UnitDelay_DSTATE_h = 0U;
	DW_tplcen_Unit_Delay_DSTATE_kz = 0U;
	DW_tplcen_Unit_Delay1_DSTATE_b = 0U;
	DW_tplcen_Unit_Delay_DSTATE = 0.F;
	DW_tplcen_Unit_Delay_DSTATE_k = 0.F;
	DW_tplcen_Unit_Delay_DSTATE_l = 0.F;
	DW_tplcen_Unit_Delay4_DSTATE = 0.F;
	DW_tplcen_Unit_Delay5_DSTATE = 0.F;
	DW_tplcen_Unit_Delay6_DSTATE = 0.F;
	DW_tplcen_Unit_Delay7_DSTATE = 0.F;
	DW_tplcen_Unit_Delay_DSTATE_m = 0.F;
	DW_tplcen_Unit_Delay_DSTATE_a = 0.F;
	DW_tplcen_UnitDelay1_DSTATE = 0.F;
	DW_tplcen_UnitDelay_DSTATE = 0.F;
	
	for(k1 = 0; k1 < 4; k1++)
	{
		BI_tplcen_VectorConcatenate[k1] = 0U;
	}
	
}
#define TPLCEN_VehReset TPLCEN_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

