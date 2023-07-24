/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULES       : TCTEST,TCTDTE,TCTCDC,TCTFFC,TCTLGC,TCTCLM
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TRJCTRVEH.c
//! @brief     (TRJCTR) Sub-Component Vehicle C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "TRJCTRVEH.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void TRJCTR_VehInitDbgPtr(TRJCTR_VehDbgType *TRJCTR_VehDbgPtr)
{
	TCTEST_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTEST_VehDbgData);
	TCTDTE_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTDTE_VehDbgData);
	TCTCDC_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTCDC_VehDbgData);
	TCTFFC_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTFFC_VehDbgData);
	TCTLGC_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTLGC_VehDbgData);
	TCTCLM_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTCLM_VehDbgData);
}

void TRJCTR_VehReset(void)
{
	TCTEST_VehReset();
	TCTDTE_VehReset();
	TCTCDC_VehReset();
	TCTFFC_VehReset();
	TCTLGC_VehReset();
	TCTCLM_VehReset();
}

void TRJCTR_VehProcess(void)
{
#define TRJCTR_VEHPROCESS_BEGIN
#include "lcf_veh_service.h"

#define TCTEST_VEHPROCESS_START
#include "lcf_veh_service.h"
	TCTEST_VehProcess();
#define TCTEST_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TCTDTE_VEHPROCESS_START
#include "lcf_veh_service.h"
	TCTDTE_VehProcess();
#define TCTDTE_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TCTCDC_VEHPROCESS_START
#include "lcf_veh_service.h"
	TCTCDC_VehProcess();
#define TCTCDC_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TCTFFC_VEHPROCESS_START
#include "lcf_veh_service.h"
	TCTFFC_VehProcess();
#define TCTFFC_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TCTLGC_VEHPROCESS_START
#include "lcf_veh_service.h"
	TCTLGC_VehProcess();
#define TCTLGC_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TCTCLM_VEHPROCESS_START
#include "lcf_veh_service.h"
	TCTCLM_VehProcess();
#define TCTCLM_VEHPROCESS_STOP
#include "lcf_veh_service.h"

#define TRJCTR_VEHPROCESS_END
#include "lcf_veh_service.h"
}

#ifdef __cplusplus
}
#endif
