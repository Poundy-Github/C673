/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Sensor
  SUB-COMPONENTS : v1ABPR,v2ODPR,VDPR,MFJSCT,LDPSA,RDPSA,ALCASA,v1TJASA,MDCTR,CTRSC,HMIOC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFSEN.c
//! @brief    Lateral Control Functions - Sensor (LCFSEN) Task C-File.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   V A R I A N T   I N D E X   M A P P I N G
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

void LCF_SenInitDbgPtr(LCF_SenDbgType *LCF_SenDbgArg)
{
	v1ABPR_SenInitDbgPtr(&LCF_SenDbgArg->v1ABPR_SenDbgData);
	v2ODPR_SenInitDbgPtr(&LCF_SenDbgArg->v2ODPR_SenDbgData);
	VDPR_SenInitDbgPtr(&LCF_SenDbgArg->VDPR_SenDbgData);
	LDPSA_SenInitDbgPtr(&LCF_SenDbgArg->LDPSA_SenDbgData);
	RDPSA_SenInitDbgPtr(&LCF_SenDbgArg->RDPSA_SenDbgData);
	ALCASA_SenInitDbgPtr(&LCF_SenDbgArg->ALCASA_SenDbgData);
	v1TJASA_SenInitDbgPtr(&LCF_SenDbgArg->v1TJASA_SenDbgData);
	MFJSCT_SenInitDbgPtr(&LCF_SenDbgArg->MFJSCT_SenDbgData);
}

void LCF_SenInitOutPtr(LCF_SenOutType *LCF_SenOutPtr)
{
	v1ABPR_SenInitOutPtr(&LCF_SenOutPtr->v1ABPR_SenOutData);
	v2ODPR_SenInitOutPtr(&LCF_SenOutPtr->v2ODPR_SenOutData);
	MFJSCT_SenInitOutPtr(&LCF_SenOutPtr->MFJSCT_SenOutData);
	LDPSA_SenInitOutPtr(&LCF_SenOutPtr->LDPSA_SenOutData);
	RDPSA_SenInitOutPtr(&LCF_SenOutPtr->RDPSA_SenOutData);
	ALCASA_SenInitOutPtr(&LCF_SenOutPtr->ALCASA_SenOutData);
	v1TJASA_SenInitOutPtr(&LCF_SenOutPtr->v1TJASA_SenOutData);
	MDCTR_SenInitOutPtr(&LCF_SenOutPtr->MDCTR_SenOutData);
	CTRSC_SenInitOutPtr(&LCF_SenOutPtr->CTRSC_SenOutData);
	HMIOC_SenInitOutPtr(&LCF_SenOutPtr->HMIOC_SenOutData);
}

void LCF_SenReset(void)
{
	v1ABPR_SenReset();
	v2ODPR_SenReset();
	VDPR_SenReset();
	MFJSCT_SenReset();
	LDPSA_SenReset();
	RDPSA_SenReset();
	ALCASA_SenReset();
	v1TJASA_SenReset();
	MDCTR_SenReset();
	CTRSC_SenReset();
	HMIOC_SenReset();
}

void LCF_SenProcess(void)
{
#define LCF_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

	//+++ BEGIN cycle counter update
	static uint8 u8CycleCnt = 0u;
	u8CycleCnt++;
	if(u8CycleCnt > 0u) { u8CycleCnt = 0u; }
	//+++ END cycle counter update

	if(0u == (u8CycleCnt % 1u))
	{
#define V1ABPR_SENPROCESS_START
#include "lcf_sen_service.h"
		v1ABPR_SenProcess();
#define V1ABPR_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define V2ODPR_SENPROCESS_START
#include "lcf_sen_service.h"
		v2ODPR_SenProcess();
#define V2ODPR_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define VDPR_SENPROCESS_START
#include "lcf_sen_service.h"
		VDPR_SenProcess();
#define VDPR_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define MFJSCT_SENPROCESS_START
#include "lcf_sen_service.h"
		MFJSCT_SenProcess();
#define MFJSCT_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define LDPSA_SENPROCESS_START
#include "lcf_sen_service.h"
		LDPSA_SenProcess();
#define LDPSA_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define RDPSA_SENPROCESS_START
#include "lcf_sen_service.h"
		RDPSA_SenProcess();
#define RDPSA_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define ALCASA_SENPROCESS_START
#include "lcf_sen_service.h"
		ALCASA_SenProcess();
#define ALCASA_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define V1TJASA_SENPROCESS_START
#include "lcf_sen_service.h"
		v1TJASA_SenProcess();
#define V1TJASA_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define MDCTR_SENPROCESS_START
#include "lcf_sen_service.h"
		MDCTR_SenProcess();
#define MDCTR_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define CTRSC_SENPROCESS_START
#include "lcf_sen_service.h"
		CTRSC_SenProcess();
#define CTRSC_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define HMIOC_SENPROCESS_START
#include "lcf_sen_service.h"
		HMIOC_SenProcess();
#define HMIOC_SENPROCESS_STOP
#include "lcf_sen_service.h"
	}

#define LCF_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
