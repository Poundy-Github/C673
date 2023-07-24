/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : CTRSC
  MODULE        : CSCLTA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_CSCLTA.h
//! @brief     (CSCLTA) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_CSCLTA_SenReset
void CSCLTA_SenResetData(void);
void CSCLTA_SenReset(void)
{
	
	CSCLTA_SenResetData();
	
	
}
#define CSCLTA_SenReset CSCLTA_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

