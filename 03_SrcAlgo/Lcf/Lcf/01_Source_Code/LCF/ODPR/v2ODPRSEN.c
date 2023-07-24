/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v2ODPR
  MODULES       : ODPFOP,ODPFOH
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.1 $
  $Author: Nastasa, Elena (uidt4846) $
  $Date: 2019/11/29 09:02:00CET $
  $Log: v2ODPRSEN.c  $
  Revision 1.1.1.1 2019/11/29 09:02:00CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     v2ODPRSEN.c
//! @brief     (v2ODPR) Sub-Component Sensor C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "v2ODPRSEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void v2ODPR_SenInitDbgPtr(v2ODPR_SenDbgType *v2ODPR_SenDbgPtr)
{
	ODPFOP_SenInitDbgPtr(&v2ODPR_SenDbgPtr->ODPFOP_SenDbgData);
	ODPFOH_SenInitDbgPtr(&v2ODPR_SenDbgPtr->ODPFOH_SenDbgData);
}

void v2ODPR_SenReset(void)
{
	ODPFOP_SenReset();
	ODPFOH_SenReset();
}

void v2ODPR_SenProcess(void)
{
#define V2ODPR_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

#define ODPFOP_SENPROCESS_START
#include "lcf_sen_service.h"
	ODPFOP_SenProcess();
#define ODPFOP_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define ODPFOH_SENPROCESS_START
#include "lcf_sen_service.h"
	ODPFOH_SenProcess();
#define ODPFOH_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define V2ODPR_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
