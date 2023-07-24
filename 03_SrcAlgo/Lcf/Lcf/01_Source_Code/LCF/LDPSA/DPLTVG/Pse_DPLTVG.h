/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DPLTVG.h
//! @brief     (DPLTVG) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DPLTVG_SenReset
void DPLTVG_SenResetData(void);
void DPLTVG_SenReset(void)
{
	
	DPLTVG_SenResetData();
	
	DW_dpltvg_Unit_Delay3_DSTATE = 0U;
	DW_dpltvg_Unit_Delay1_DSTATE_i = 0U;
	DW_dpltvg_Unit_Delay2_DSTATE = 0.F;
	DW_dpltvg_Unit_Delay_DSTATE = 0.F;
	DW_dpltvg_Unit_Delay_DSTATE_o = 0.F;
	DW_dpltvg_Unit_Delay1_DSTATE = 0.F;
	
}
#define DPLTVG_SenReset DPLTVG_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

