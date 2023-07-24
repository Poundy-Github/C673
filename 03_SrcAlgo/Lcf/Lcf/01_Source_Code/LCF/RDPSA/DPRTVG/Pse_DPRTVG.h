/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPRTVG.h
//! @brief     (DPRTVG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPRTVG_SenReset
void DPRTVG_SenResetData(void);
void DPRTVG_SenReset(void)
{
	
	DPRTVG_SenResetData();
	
	DW_dprtvg_Unit_Delay1_DSTATE_f = 0U;
	DW_dprtvg_Unit_Delay3_DSTATE = 0U;
	DW_dprtvg_Unit_Delay_DSTATE = 0.F;
	DW_dprtvg_Unit_Delay2_DSTATE = 0.F;
	DW_dprtvg_Unit_Delay_DSTATE_f = 0.F;
	DW_dprtvg_Unit_Delay1_DSTATE = 0.F;
	
}
#define DPRTVG_SenReset DPRTVG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

