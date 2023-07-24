/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : CTRSC
  MODULES       : CSCLTA
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     CTRSCSEN_type.h
//! @brief     (CTRSC) Sub-Component Sensor Type Header.

#ifndef CTRSCSEN_TYPE_H_
#define CTRSCSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "CSCLTA/CSCLTA_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! CTRSC sub-component sensor output data structure. */
typedef struct
{
	CSCLTA_SenOutType CSCLTA_SenOutData; //!< CSCLTA module sensor output data structure.
} CTRSC_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // CTRSCSEN_TYPE_H_
