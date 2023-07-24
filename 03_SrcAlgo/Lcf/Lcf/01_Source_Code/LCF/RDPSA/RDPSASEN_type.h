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
//! @file     RDPSASEN_type.h
//! @brief     (RDPSA) Sub-Component Sensor Type Header.

#ifndef RDPSASEN_TYPE_H_
#define RDPSASEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRSIA/DPRSIA_type.h"
#include "DPRSMI/DPRSMI_type.h"
#include "DPRSMW/DPRSMW_type.h"
#include "DPRTTG/DPRTTG_type.h"
#include "DPRTVG/DPRTVG_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! RDPSA sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	DPRSIA_SenDbgType DPRSIA_SenDbgData; //!< DPRSIA module sensor debug data structure for MTS measurement.
	DPRSMI_SenDbgType DPRSMI_SenDbgData; //!< DPRSMI module sensor debug data structure for MTS measurement.
	DPRSMW_SenDbgType DPRSMW_SenDbgData; //!< DPRSMW module sensor debug data structure for MTS measurement.
	DPRTTG_SenDbgType DPRTTG_SenDbgData; //!< DPRTTG module sensor debug data structure for MTS measurement.
} RDPSA_SenDbgType;

/*! RDPSA sub-component sensor output data structure. */
typedef struct
{
	DPRSMI_SenOutType DPRSMI_SenOutData; //!< DPRSMI module sensor output data structure.
	DPRSMW_SenOutType DPRSMW_SenOutData; //!< DPRSMW module sensor output data structure.
	DPRTTG_SenOutType DPRTTG_SenOutData; //!< DPRTTG module sensor output data structure.
	DPRTVG_SenOutType DPRTVG_SenOutData; //!< DPRTVG module sensor output data structure.
} RDPSA_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // RDPSASEN_TYPE_H_
