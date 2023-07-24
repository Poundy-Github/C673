/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_LCRTVG.h
//! @brief     (LCRTVG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_LCRTVG_SenReset
void LCRTVG_SenResetData(void);
void LCRTVG_SenReset(void)
{
	
	LCRTVG_SenResetData();
	
	DW_lcrtvg_Unit_Delay3_DSTATE = 0U;
	DW_lcrtvg_Unit_Delay1_DSTATE_p = 0U;
	DW_lcrtvg_Unit_Delay2_DSTATE = 0.F;
	DW_lcrtvg_Unit_Delay_DSTATE = 0.F;
	DW_lcrtvg_Unit_Delay_DSTATE_j = 0.F;
	DW_lcrtvg_Unit_Delay1_DSTATE = 0.F;
	
}
#define LCRTVG_SenReset LCRTVG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

