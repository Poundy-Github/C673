/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v1ABPR
  MODULES       : ABPLBP,ABPREP
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     v1ABPRSEN.c
//! @brief     (v1ABPR) Sub-Component Sensor C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "v1ABPRSEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void v1ABPR_SenInitDbgPtr(v1ABPR_SenDbgType *v1ABPR_SenDbgPtr)
{
	ABPLBP_SenInitDbgPtr(&v1ABPR_SenDbgPtr->ABPLBP_SenDbgData);
	ABPREP_SenInitDbgPtr(&v1ABPR_SenDbgPtr->ABPREP_SenDbgData);
}

void v1ABPR_SenInitOutPtr(v1ABPR_SenOutType *v1ABPR_SenOutPtr)
{
	ABPLBP_SenInitOutPtr(&v1ABPR_SenOutPtr->ABPLBP_SenOutData);
	ABPREP_SenInitOutPtr(&v1ABPR_SenOutPtr->ABPREP_SenOutData);
}

void v1ABPR_SenReset(void)
{
	ABPLBP_SenReset();
	ABPREP_SenReset();
}

void v1ABPR_SenProcess(void)
{
#define V1ABPR_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

#define ABPLBP_SENPROCESS_START
#include "lcf_sen_service.h"
	ABPLBP_SenProcess();
#define ABPLBP_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define ABPREP_SENPROCESS_START
#include "lcf_sen_service.h"
	ABPREP_SenProcess();
#define ABPREP_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define V1ABPR_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
