/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3CN15
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : HMIOC
  MODULES       : HMODFL
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     HMIOCSEN_type.h
//! @brief     (HMIOC) Sub-Component Sensor Type Header.

#ifndef HMIOCSEN_TYPE_H_
#define HMIOCSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "HMODFL/HMODFL_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! HMIOC sub-component sensor output data structure. */
typedef struct
{
	HMODFL_SenOutType HMODFL_SenOutData; //!< HMODFL module sensor output data structure.
} HMIOC_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // HMIOCSEN_TYPE_H_
