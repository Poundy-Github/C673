/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULES       : DPRSIA,DPRSMI,DPRSMW,DPRTTG,DPRTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     RDPSASEN.c
//! @brief     (RDPSA) Sub-Component Sensor C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "RDPSASEN.h"
#include "RDPSASEN_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void RDPSA_SenInitDbgPtr(RDPSA_SenDbgType *RDPSA_SenDbgPtr)
{
	DPRSIA_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRSIA_SenDbgData);
	DPRSMI_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRSMI_SenDbgData);
	DPRSMW_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRSMW_SenDbgData);
	DPRTTG_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRTTG_SenDbgData);
}

void RDPSA_SenInitOutPtr(RDPSA_SenOutType *RDPSA_SenOutPtr)
{
	DPRSMI_SenInitOutPtr(&RDPSA_SenOutPtr->DPRSMI_SenOutData);
	DPRSMW_SenInitOutPtr(&RDPSA_SenOutPtr->DPRSMW_SenOutData);
	DPRTTG_SenInitOutPtr(&RDPSA_SenOutPtr->DPRTTG_SenOutData);
	DPRTVG_SenInitOutPtr(&RDPSA_SenOutPtr->DPRTVG_SenOutData);
}

void RDPSA_SenReset(void)
{
	DPRSIA_SenReset();
	DPRSMI_SenReset();
	DPRSMW_SenReset();
	DPRTTG_SenReset();
	DPRTVG_SenReset();
}

void RDPSA_SenProcess(void)
{
#define RDPSA_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

#define DPRSIA_SENPROCESS_START
#include "lcf_sen_service.h"
	DPRSIA_SenProcess();
#define DPRSIA_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPRSMI_SENPROCESS_START
#include "lcf_sen_service.h"
	DPRSMI_SenProcess();
#define DPRSMI_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPRSMW_SENPROCESS_START
#include "lcf_sen_service.h"
	DPRSMW_SenProcess();
#define DPRSMW_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPRTTG_SENPROCESS_START
#include "lcf_sen_service.h"
	DPRTTG_SenProcess();
#define DPRTTG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define DPRTVG_SENPROCESS_START
#include "lcf_sen_service.h"
	DPRTVG_SenProcess();
#define DPRTVG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define RDPSA_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
