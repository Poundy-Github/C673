/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : VDPR
  MODULES       : VDPDRV
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     VDPRSEN_type.h
//! @brief     (VDPR) Sub-Component Sensor Type Header.

#ifndef VDPRSEN_TYPE_H_
#define VDPRSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "VDPDRV/VDPDRV_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! VDPR sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	VDPDRV_SenDbgType VDPDRV_SenDbgData; //!< VDPDRV module sensor debug data structure for MTS measurement.
} VDPR_SenDbgType;

#ifdef __cplusplus
}
#endif

#endif // VDPRSEN_TYPE_H_
