/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAGEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TJAGEN.h
//! @brief     (TJAGEN) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJAGEN_SenReset
void TJAGEN_SenResetData(void);
void TJAGEN_SenReset(void)
{
	
	TJAGEN_SenResetData();
	
	DW_tjagen_Unit_Delay1_DSTATE = 0U;
	DW_tjagen_Unit_Delay2_DSTATE = 0U;
	DW_tjagen_UnitDelay1_DSTATE = 0U;
	DW_tjagen_UnitDelay3_DSTATE = 0U;
	DW_tjagen_UnitDelay2_DSTATE = 0U;
	DW_tjagen_Unit_Delay_DSTATE = 0.F;
	DW_tjagen_Unit_Delay_DSTATE_a = 0.F;
	
}
#define TJAGEN_SenReset TJAGEN_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

