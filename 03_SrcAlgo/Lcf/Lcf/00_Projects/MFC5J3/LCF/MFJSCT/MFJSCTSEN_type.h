/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MFJSCT
  MODULES       : JCNCTR
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MFJSCTSEN_type.h
//! @brief     (MFJSCT) Sub-Component Sensor Type Header.

#ifndef MFJSCTSEN_TYPE_H_
#define MFJSCTSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "JCNCTR/JCNCTR_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! MFJSCT module sensor debug data structure for MTS measurement. */
typedef struct 
{
   JCNCTR_SenDbgType JCNCTR_SenDbgData;
} MFJSCT_SenDbgType;

/*! MFJSCT sub-component sensor output data structure. */
typedef struct
{
	JCNCTR_SenOutType JCNCTR_SenOutData; //!< JCNCTR module sensor output data structure.
} MFJSCT_SenOutType;

#ifdef __cplusplus
}
#endif

#endif // MFJSCTSEN_TYPE_H_
