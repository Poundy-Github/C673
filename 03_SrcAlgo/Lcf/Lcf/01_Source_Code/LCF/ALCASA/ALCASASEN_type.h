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
//! @file     ALCASASEN_type.h
//! @brief     (ALCASA) Sub-Component Sensor Type Header.

#ifndef ALCASASEN_TYPE_H_
#define ALCASASEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCRSIA/LCRSIA_type.h"
#include "LCRSMI/LCRSMI_type.h"
#include "LCRTTG/LCRTTG_type.h"
#include "LCRTVG/LCRTVG_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! ALCASA sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	LCRSIA_SenDbgType LCRSIA_SenDbgData; //!< LCRSIA module sensor debug data structure for MTS measurement.
	LCRSMI_SenDbgType LCRSMI_SenDbgData; //!< LCRSMI module sensor debug data structure for MTS measurement.
	LCRTTG_SenDbgType LCRTTG_SenDbgData; //!< LCRTTG module sensor debug data structure for MTS measurement.
	LCRTVG_SenDbgType LCRTVG_SenDbgData; //!< LCRTVG module sensor debug data structure for MTS measurement.
} ALCASA_SenDbgType;

/*! ALCASA sub-component sensor output data structure. */
typedef struct
{
	LCRSIA_SenOutType LCRSIA_SenOutData; //!< LCRSIA module sensor output data structure.
	LCRSMI_SenOutType LCRSMI_SenOutData; //!< LCRSMI module sensor output data structure.
	LCRTVG_SenOutType LCRTVG_SenOutData; //!< LCRTVG module sensor output data structure.
} ALCASA_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // ALCASASEN_TYPE_H_
