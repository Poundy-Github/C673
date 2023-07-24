/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJATVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TJATVG.h
//! @brief     (TJATVG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJATVG_SenReset
void TJATVG_SenResetData(void);
void TJATVG_SenReset(void)
{
	
	TJATVG_SenResetData();
	
	DW_tjatvg_Unit_Delay2_DSTATE = 0U;
	DW_tjatvg_Unit_Delay_DSTATE = 0U;
	DW_tjatvg_Unit_Delay_DSTATE_h = 0U;
	DW_tjatvg_Unit_Delay1_DSTATE = 0.F;
	
}
#define TJATVG_SenReset TJATVG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

