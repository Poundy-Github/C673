/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULES       : DPLSIA,DPLSMI,DPLSMW,DPLTTG,DPLTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LDPSASEN_type.h
//! @brief     (LDPSA) Sub-Component Sensor Type Header.

#ifndef LDPSASEN_TYPE_H_
#define LDPSASEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLSIA/DPLSIA_type.h"
#include "DPLSMI/DPLSMI_type.h"
#include "DPLSMW/DPLSMW_type.h"
#include "DPLTTG/DPLTTG_type.h"
#include "DPLTVG/DPLTVG_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! LDPSA sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	DPLSIA_SenDbgType DPLSIA_SenDbgData; //!< DPLSIA module sensor debug data structure for MTS measurement.
	DPLSMI_SenDbgType DPLSMI_SenDbgData; //!< DPLSMI module sensor debug data structure for MTS measurement.
	DPLSMW_SenDbgType DPLSMW_SenDbgData; //!< DPLSMW module sensor debug data structure for MTS measurement.
	DPLTTG_SenDbgType DPLTTG_SenDbgData; //!< DPLTTG module sensor debug data structure for MTS measurement.
} LDPSA_SenDbgType;

/*! LDPSA sub-component sensor output data structure. */
typedef struct
{
	DPLSMI_SenOutType DPLSMI_SenOutData; //!< DPLSMI module sensor output data structure.
	DPLSMW_SenOutType DPLSMW_SenOutData; //!< DPLSMW module sensor output data structure.
	DPLTTG_SenOutType DPLTTG_SenOutData; //!< DPLTTG module sensor output data structure.
	DPLTVG_SenOutType DPLTVG_SenOutData; //!< DPLTVG module sensor output data structure.
} LDPSA_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // LDPSASEN_TYPE_H_
