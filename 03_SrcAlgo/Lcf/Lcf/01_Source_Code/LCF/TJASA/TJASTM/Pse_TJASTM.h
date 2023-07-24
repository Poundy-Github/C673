/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJASTM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TJASTM.h
//! @brief     (TJASTM) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJASTM_SenReset
void TJASTM_SenResetData(void);
void TJASTM_SenReset(void)
{
	
	TJASTM_SenResetData();
	
	BI_tjastm_SysState_nu = 0U;
	BI_tjastm_LatCtrlMode_nu = 0U;
	DW_tjastm_is_active_c10_TJASTM_cg = 0U;
	DW_tjastm_is_c10_TJASTM_cg = 0U;
	DW_tjastm_is_PRESENT = 0U;
	DW_tjastm_is_active_c14_TJASTM_cg = 0U;
	DW_tjastm_is_c14_TJASTM_cg = 0U;
	DW_tjastm_is_Request = 0U;
	DW_tjastm_is_Controlling = 0U;
	
}
#define TJASTM_SenReset TJASTM_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

