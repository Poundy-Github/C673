/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v1ABPR
  MODULES       : ABPLBP,ABPREP
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     v1ABPRSEN_type.h
//! @brief     (v1ABPR) Sub-Component Sensor Type Header.

#ifndef V1ABPRSEN_TYPE_H_
#define V1ABPRSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPLBP/ABPLBP_type.h"
#include "ABPREP/ABPREP_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! v1ABPR sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	ABPLBP_SenDbgType ABPLBP_SenDbgData; //!< ABPLBP module sensor debug data structure for MTS measurement.
	ABPREP_SenDbgType ABPREP_SenDbgData; //!< ABPREP module sensor debug data structure for MTS measurement.
} v1ABPR_SenDbgType;

/*! v1ABPR sub-component sensor output data structure. */
typedef struct
{
	ABPLBP_SenOutType ABPLBP_SenOutData; //!< ABPLBP module sensor output data structure.
	ABPREP_SenOutType ABPREP_SenOutData; //!< ABPREP module sensor output data structure.
} v1ABPR_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // V1ABPRSEN_TYPE_H_
