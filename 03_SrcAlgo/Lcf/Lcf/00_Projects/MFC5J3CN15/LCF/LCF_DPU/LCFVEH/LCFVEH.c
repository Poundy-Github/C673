/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3CN15
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Vehicle
  SUB-COMPONENTS : DRVMN,TRJPLN,TRJCTR,LATDMC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFVEH.c
//! @brief    Lateral Control Functions - Vehicle (LCFVEH) Task C-File.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH.h"

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

void LCF_VehInitDbgPtr(LCF_VehDbgType *LCF_VehDbgArg)
{
	DRVMN_VehInitDbgPtr(&LCF_VehDbgArg->DRVMN_VehDbgData);
	TRJPLN_VehInitDbgPtr(&LCF_VehDbgArg->TRJPLN_VehDbgData);
	TRJCTR_VehInitDbgPtr(&LCF_VehDbgArg->TRJCTR_VehDbgData);
}

void LCF_VehInitOutPtr(LCF_VehOutType *LCF_VehOutPtr)
{
	DRVMN_VehInitOutPtr(&LCF_VehOutPtr->DRVMN_VehOutData);
	TRJPLN_VehInitOutPtr(&LCF_VehOutPtr->TRJPLN_VehOutData);
	TRJCTR_VehInitOutPtr(&LCF_VehOutPtr->TRJCTR_VehOutData);
}

void LCF_VehReset(void)
{
	DRVMN_VehReset();
	TRJPLN_VehReset();
	TRJCTR_VehReset();
	LATDMC_VehReset();
}

void LCF_VehProcess(void)
{
#define LCF_VEHPROCESS_BEGIN
#include "lcf_veh_service.h"

	//+++ BEGIN cycle counter update
	static uint8 u8CycleCnt = 1u;
	u8CycleCnt++;
	if(u8CycleCnt > 1u) { u8CycleCnt = 0u; }
	//+++ END cycle counter update

	if(0u == (u8CycleCnt % 2u))
	{
#define DRVMN_VEHPROCESS_START
#include "lcf_veh_service.h"
		DRVMN_VehProcess();
#define DRVMN_VEHPROCESS_STOP
#include "lcf_veh_service.h"
	}

	if(0u == (u8CycleCnt % 2u))
	{
#define TRJPLN_VEHPROCESS_START
#include "lcf_veh_service.h"
		TRJPLN_VehProcess();
#define TRJPLN_VEHPROCESS_STOP
#include "lcf_veh_service.h"
	}

	if(0u == (u8CycleCnt % 2u))
	{
#define TRJCTR_VEHPROCESS_START
#include "lcf_veh_service.h"
		TRJCTR_VehProcess();
#define TRJCTR_VEHPROCESS_STOP
#include "lcf_veh_service.h"
	}

	if(0u == (u8CycleCnt % 1u))
	{
#define LATDMC_VEHPROCESS_START
#include "lcf_veh_service.h"
		LATDMC_VehProcess();
#define LATDMC_VEHPROCESS_STOP
#include "lcf_veh_service.h"
	}

#define LCF_VEHPROCESS_END
#include "lcf_veh_service.h"
}

#ifdef __cplusplus
}
#endif
