/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULE        : MCTLFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MCTLFC_type.h
//! @brief     (MCTLFC) Module Type Header.

#ifndef MCTLFC_TYPE_H_
#define MCTLFC_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! MCTLFC module sensor output data structure. */
typedef struct
{
	
	E_LCF_FunctionV3Type_t S_MCTLFC_ControllingFunction_nu; /*!< @description
	*	Carries which function is allowed to control. \n\n
	*	\@asap_name: S_MCTLFC_ControllingFunction_nu \n
	*	\@values: E_LCF_FunctionV3Type \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 7
	*/
	
} MCTLFC_SenOutType; /*!< @description MCTLFC module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // MCTLFC_TYPE_H_
