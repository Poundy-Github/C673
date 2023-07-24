/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULES       : TPLLCO,TPLCEN,TPLFRT,TPLTJC,TPLFBT
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TRJPLNVEH.c
//! @brief     (TRJPLN) Sub-Component Vehicle C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "TRJPLNVEH.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void TRJPLN_VehInitDbgPtr(TRJPLN_VehDbgType *TRJPLN_VehDbgPtr)
{
	TPLLCO_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLLCO_VehDbgData);
	TPLCEN_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLCEN_VehDbgData);
	TPLFRT_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLFRT_VehDbgData);
	TPLTJC_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLTJC_VehDbgData);
	TPLFBT_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLFBT_VehDbgData);
}

void TRJPLN_VehInitOutPtr(TRJPLN_VehOutType *TRJPLN_VehOutPtr)
{
	TPLLCO_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLLCO_VehOutData);
	TPLCEN_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLCEN_VehOutData);
	TPLFRT_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLFRT_VehOutData);
	TPLFBT_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLFBT_VehOutData);
}

void TRJPLN_VehReset(void)
{
	TPLLCO_VehReset();
	TPLCEN_VehReset();
	TPLFRT_VehReset();
	TPLTJC_VehReset();
	TPLFBT_VehReset();
}

void TRJPLN_VehProcess(void)
{
#define TRJPLN_VEHPROCESS_BEGIN
#include "lcf_veh_service.h"

#define TPLLCO_VEHPROCESS_START
#include "lcf_veh_service.h"
	TPLLCO_VehProcess();
#define TPLLCO_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TPLCEN_VEHPROCESS_START
#include "lcf_veh_service.h"
	TPLCEN_VehProcess();
#define TPLCEN_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TPLFRT_VEHPROCESS_START
#include "lcf_veh_service.h"
	TPLFRT_VehProcess();
#define TPLFRT_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TPLTJC_VEHPROCESS_START
#include "lcf_veh_service.h"
	TPLTJC_VehProcess();
#define TPLTJC_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TPLFBT_VEHPROCESS_START
#include "lcf_veh_service.h"
	TPLFBT_VehProcess();
#define TPLFBT_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TRJPLN_VEHPROCESS_END
#include "lcf_veh_service.h"
}

#ifdef __cplusplus
}
#endif
