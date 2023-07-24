/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULES       : DRMHOD,DRMDAE
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRVMNVEH.c
//! @brief     (DRVMN) Sub-Component Vehicle C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "DRVMNVEH.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void DRVMN_VehInitDbgPtr(DRVMN_VehDbgType *DRVMN_VehDbgPtr)
{
	DRMHOD_VehInitDbgPtr(&DRVMN_VehDbgPtr->DRMHOD_VehDbgData);
	DRMDAE_VehInitDbgPtr(&DRVMN_VehDbgPtr->DRMDAE_VehDbgData);
}

void DRVMN_VehInitOutPtr(DRVMN_VehOutType *DRVMN_VehOutPtr)
{
	DRMHOD_VehInitOutPtr(&DRVMN_VehOutPtr->DRMHOD_VehOutData);
	DRMDAE_VehInitOutPtr(&DRVMN_VehOutPtr->DRMDAE_VehOutData);
}

void DRVMN_VehReset(void)
{
	DRMHOD_VehReset();
	DRMDAE_VehReset();
}

void DRVMN_VehProcess(void)
{
#define DRVMN_VEHPROCESS_BEGIN
#include "lcf_veh_service.h"

#define DRMHOD_VEHPROCESS_START
#include "lcf_veh_service.h"
	DRMHOD_VehProcess();
#define DRMHOD_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define DRMDAE_VEHPROCESS_START
#include "lcf_veh_service.h"
	DRMDAE_VehProcess();
#define DRMDAE_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define DRVMN_VEHPROCESS_END
#include "lcf_veh_service.h"
}

#ifdef __cplusplus
}
#endif
