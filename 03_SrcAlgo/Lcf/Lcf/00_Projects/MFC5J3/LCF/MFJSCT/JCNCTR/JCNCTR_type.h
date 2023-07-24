/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MFJSCT
  MODULE        : JCNCTR
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     JCNCTR_type.h
//! @brief     (JCNCTR) Module Type Header.

#ifndef JCNCTR_TYPE_H_
#define JCNCTR_TYPE_H_

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

/*! JCNCTR module sensor debug data structure for MTS measurement. */
typedef struct
{
   u16_NoUnit_0_65535_0_1_t S_JCNCTR_LDWPrjSpecQu_btf;
	u16_NoUnit_0_65535_0_1_t S_JCNCTR_LKAPrjSpecQu_btf;
	u16_NoUnit_0_65535_0_1_t S_JCNCTR_ELKPrjSpecQu_btf;

} JCNCTR_SenDbgType;

/*! JCNCTR module sensor output data structure. */
typedef struct
{
	
	u16_NoUnit_0_65535_0_1_t S_JCNCTR_PrjSpecQu_btf; /*!< @description
	*	 \n\n
	*	\@asap_name: S_JCNCTR_PrjSpecQu_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
} JCNCTR_SenOutType; /*!< @description JCNCTR module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // JCNCTR_TYPE_H_
