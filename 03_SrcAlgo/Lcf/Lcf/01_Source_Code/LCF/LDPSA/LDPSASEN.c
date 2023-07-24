/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULES       : DPLSIA,DPLSMI,DPLSMW,DPLTTG,DPLTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LDPSASEN.c
//! @brief     (LDPSA) Sub-Component Sensor C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "LDPSASEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void LDPSA_SenInitDbgPtr(LDPSA_SenDbgType *LDPSA_SenDbgPtr)
{
	DPLSIA_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLSIA_SenDbgData);
	DPLSMI_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLSMI_SenDbgData);
	DPLSMW_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLSMW_SenDbgData);
	DPLTTG_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLTTG_SenDbgData);
}

void LDPSA_SenInitOutPtr(LDPSA_SenOutType *LDPSA_SenOutPtr)
{
	DPLSMI_SenInitOutPtr(&LDPSA_SenOutPtr->DPLSMI_SenOutData);
	DPLSMW_SenInitOutPtr(&LDPSA_SenOutPtr->DPLSMW_SenOutData);
	DPLTTG_SenInitOutPtr(&LDPSA_SenOutPtr->DPLTTG_SenOutData);
	DPLTVG_SenInitOutPtr(&LDPSA_SenOutPtr->DPLTVG_SenOutData);
}

void LDPSA_SenReset(void)
{
	DPLSIA_SenReset();
	DPLSMI_SenReset();
	DPLSMW_SenReset();
	DPLTTG_SenReset();
	DPLTVG_SenReset();
}

void LDPSA_SenProcess(void)
{
#define LDPSA_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

#define DPLSIA_SENPROCESS_START
#include "lcf_sen_service.h"
	DPLSIA_SenProcess();
#define DPLSIA_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPLSMI_SENPROCESS_START
#include "lcf_sen_service.h"
	DPLSMI_SenProcess();
#define DPLSMI_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPLSMW_SENPROCESS_START
#include "lcf_sen_service.h"
	DPLSMW_SenProcess();
#define DPLSMW_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPLTTG_SENPROCESS_START
#include "lcf_sen_service.h"
	DPLTTG_SenProcess();
#define DPLTTG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPLTVG_SENPROCESS_START
#include "lcf_sen_service.h"
	DPLTVG_SenProcess();
#define DPLTVG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define LDPSA_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
