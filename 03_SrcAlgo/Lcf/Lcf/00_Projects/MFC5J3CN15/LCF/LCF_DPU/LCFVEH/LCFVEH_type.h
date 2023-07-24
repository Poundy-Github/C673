/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3CN15
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Vehicle
  SUB-COMPONENTS : DRVMN,TRJPLN,TRJCTR,LATDMC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFVEH_type.h
//! @brief    Lateral Control Functions - Vehicle (LCFVEH) Task Type Header.

#ifndef LCFVEH_TYPE_H_
#define LCFVEH_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRVMN/DRVMNVEH_type.h"
#include "TRJPLN/TRJPLNVEH_type.h"
#include "TRJCTR/TRJCTRVEH_type.h"
#include "LATDMC/LATDMCVEH_type.h"
#include "LCFPRM/LCFPRM_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

#define _LCF_VEHDBGTYPE_T_ //!< Macro switch for LCFVEH task debug type @ref LCF_VehDbgType.
/*! LCFVEH task debug data structure for MTS measurement. */
typedef struct
{
	DRVMN_VehDbgType DRVMN_VehDbgData; //!< DRVMN sub-component debug data structure for MTS measurement.
	TRJPLN_VehDbgType TRJPLN_VehDbgData; //!< TRJPLN sub-component debug data structure for MTS measurement.
	TRJCTR_VehDbgType TRJCTR_VehDbgData; //!< TRJCTR sub-component debug data structure for MTS measurement.
} LCF_VehDbgType;

#define _LCF_VEHOUTTYPE_T_ //!< Macro switch for LCFVEH task output type @ref LCF_VehOutType.
/*! LCFVEH task output data structure. */
typedef struct
{
	DRVMN_VehOutType DRVMN_VehOutData; //!< DRVMN sub-component output data structure.
	TRJPLN_VehOutType TRJPLN_VehOutData; //!< TRJPLN sub-component output data structure.
	TRJCTR_VehOutType TRJCTR_VehOutData; //!< TRJCTR sub-component output data structure.
} LCF_VehOutType;

#ifdef __cplusplus
}
#endif

#endif // LCFVEH_TYPE_H_
