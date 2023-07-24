/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULE        : MCTLFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_MCTLFC.h
//! @brief     (MCTLFC) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_MCTLFC_SenReset
void MCTLFC_SenResetData(void);
void MCTLFC_SenReset(void)
{
	uint8 k1;
	
	MCTLFC_SenResetData();
	
	BI_mctlfc_S_MCTLFC_ControllingFunction_nu_l = 0U;
	DW_mctlfc_is_active_c5_MCTLFC_cg = 0U;
	DW_mctlfc_is_c5_MCTLFC_cg = 0U;
	
	DW_mctlfc_Unit_Delay1_DSTATE[0] = 1U;
	DW_mctlfc_Unit_Delay1_DSTATE[1] = 1U;
	DW_mctlfc_Unit_Delay1_DSTATE[2] = 1U;
	DW_mctlfc_Unit_Delay1_DSTATE[3] = 1U;
	DW_mctlfc_Unit_Delay1_DSTATE[4] = 1U;
	DW_mctlfc_Unit_Delay1_DSTATE[5] = 1U;
	DW_mctlfc_Unit_Delay1_DSTATE[6] = 1U;
	
	for(k1 = 0; k1 < 7; k1++)
	{
		DW_mctlfc_Unit_Delay2_DSTATE[k1] = 0U;
		DW_mctlfc_Unit_Delay_DSTATE[k1] = 0.F;
	}
	
}
#define MCTLFC_SenReset MCTLFC_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

