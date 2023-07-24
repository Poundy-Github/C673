/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : HMIOC
  MODULE        : HMODFL
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_HMODFL.h
//! @brief     (HMODFL) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_HMODFL_SenReset
void HMODFL_SenResetData(void);
void HMODFL_SenReset(void)
{
	
	HMODFL_SenResetData();
	
	DW_hmodfl_Unit_Delay_DSTATE = 0U;
	DW_hmodfl_Unit_Delay4_DSTATE = 0U;
	DW_hmodfl_Unit_Delay3_DSTATE = 0U;
	DW_hmodfl_Unit_Delay1_DSTATE = 0U;
	DW_hmodfl_Unit_Delay2_DSTATE = 0U;
	
}
#define HMODFL_SenReset HMODFL_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

