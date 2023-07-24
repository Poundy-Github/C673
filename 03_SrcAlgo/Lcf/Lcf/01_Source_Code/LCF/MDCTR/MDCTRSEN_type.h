/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULES       : MCTLFC
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MDCTRSEN_type.h
//! @brief     (MDCTR) Sub-Component Sensor Type Header.

#ifndef MDCTRSEN_TYPE_H_
#define MDCTRSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "MCTLFC/MCTLFC_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! MDCTR sub-component sensor output data structure. */
typedef struct
{
	MCTLFC_SenOutType MCTLFC_SenOutData; //!< MCTLFC module sensor output data structure.
} MDCTR_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // MDCTRSEN_TYPE_H_
