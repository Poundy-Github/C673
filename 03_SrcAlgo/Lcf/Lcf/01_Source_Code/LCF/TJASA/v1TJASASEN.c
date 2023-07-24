/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v1TJASA
  MODULES       : TJALKA,TJAOBF,TJACMB,TJAGEN,TJASTM,TJATTG,TJATVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.2 $
  $Author: Nastasa, Elena (uidt4846) $
  $Date: 2019/11/29 09:04:45CET $
  $Log: v1TJASASEN.c  $
  Revision 1.1.1.2 2019/11/29 09:04:45CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     v1TJASASEN.c
//! @brief     (v1TJASA) Sub-Component Sensor C-File.

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "v1TJASASEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-------------------------------------------------*/

void v1TJASA_SenInitDbgPtr(v1TJASA_SenDbgType *v1TJASA_SenDbgPtr)
{
	TJALKA_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJALKA_SenDbgData);
	TJAOBF_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJAOBF_SenDbgData);
	TJACMB_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJACMB_SenDbgData);
	TJAGEN_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJAGEN_SenDbgData);
	TJASTM_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJASTM_SenDbgData);
	TJATTG_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJATTG_SenDbgData);
}

void v1TJASA_SenInitOutPtr(v1TJASA_SenOutType *v1TJASA_SenOutPtr)
{
	TJALKA_SenInitOutPtr(&v1TJASA_SenOutPtr->TJALKA_SenOutData);
	TJAOBF_SenInitOutPtr(&v1TJASA_SenOutPtr->TJAOBF_SenOutData);
	TJACMB_SenInitOutPtr(&v1TJASA_SenOutPtr->TJACMB_SenOutData);
	TJAGEN_SenInitOutPtr(&v1TJASA_SenOutPtr->TJAGEN_SenOutData);
	TJASTM_SenInitOutPtr(&v1TJASA_SenOutPtr->TJASTM_SenOutData);
	TJATTG_SenInitOutPtr(&v1TJASA_SenOutPtr->TJATTG_SenOutData);
	TJATVG_SenInitOutPtr(&v1TJASA_SenOutPtr->TJATVG_SenOutData);
}

void v1TJASA_SenReset(void)
{
	TJALKA_SenReset();
	TJAOBF_SenReset();
	TJACMB_SenReset();
	TJAGEN_SenReset();
	TJASTM_SenReset();
	TJATTG_SenReset();
	TJATVG_SenReset();
}

void v1TJASA_SenProcess(void)
{
#define V1TJASA_SENPROCESS_BEGIN
#include "lcf_sen_service.h"

#define TJALKA_SENPROCESS_START
#include "lcf_sen_service.h"
	TJALKA_SenProcess();
#define TJALKA_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define TJAOBF_SENPROCESS_START
#include "lcf_sen_service.h"
	TJAOBF_SenProcess();
#define TJAOBF_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define TJACMB_SENPROCESS_START
#include "lcf_sen_service.h"
	TJACMB_SenProcess();
#define TJACMB_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define TJAGEN_SENPROCESS_START
#include "lcf_sen_service.h"
	TJAGEN_SenProcess();
#define TJAGEN_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define TJASTM_SENPROCESS_START
#include "lcf_sen_service.h"
	TJASTM_SenProcess();
#define TJASTM_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define TJATTG_SENPROCESS_START
#include "lcf_sen_service.h"
	TJATTG_SenProcess();
#define TJATTG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define TJATVG_SENPROCESS_START
#include "lcf_sen_service.h"
	TJATVG_SenProcess();
#define TJATVG_SENPROCESS_STOP
#include "lcf_sen_service.h"

#define V1TJASA_SENPROCESS_END
#include "lcf_sen_service.h"
}

#ifdef __cplusplus
}
#endif
