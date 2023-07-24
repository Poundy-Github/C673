/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULES       : LCRSIA,LCRSMI,LCRTTG,LCRTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ALCASASEN.c
//! @brief     (ALCASA) Sub-Component Sensor C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "ALCASASEN.h"
#include "ALCASASEN_type.h" //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void ALCASA_SenInitDbgPtr(ALCASA_SenDbgType *ALCASA_SenDbgPtr)
{
	LCRSIA_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRSIA_SenDbgData);
	LCRSMI_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRSMI_SenDbgData);
	LCRTTG_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRTTG_SenDbgData);
	LCRTVG_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRTVG_SenDbgData);
}

void ALCASA_SenInitOutPtr(ALCASA_SenOutType *ALCASA_SenOutPtr)
{
	LCRSIA_SenInitOutPtr(&ALCASA_SenOutPtr->LCRSIA_SenOutData);
	LCRSMI_SenInitOutPtr(&ALCASA_SenOutPtr->LCRSMI_SenOutData);
	LCRTVG_SenInitOutPtr(&ALCASA_SenOutPtr->LCRTVG_SenOutData);
}

void ALCASA_SenReset(void)
{
	LCRSIA_SenReset();
	LCRSMI_SenReset();
	LCRTTG_SenReset();
	LCRTVG_SenReset();
}

void ALCASA_SenProcess(void)
{
#define ALCASA_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

#define LCRSIA_SENPROCESS_START
#include "lcf_sen_service.h"
	LCRSIA_SenProcess();
#define LCRSIA_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define LCRSMI_SENPROCESS_START
#include "lcf_sen_service.h"
	LCRSMI_SenProcess();
#define LCRSMI_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define LCRTTG_SENPROCESS_START
#include "lcf_sen_service.h"
	LCRTTG_SenProcess();
#define LCRTTG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define LCRTVG_SENPROCESS_START
#include "lcf_sen_service.h"
	LCRTVG_SenProcess();
#define LCRTVG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define ALCASA_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
