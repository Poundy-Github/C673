/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULES       : DRMHOD,DRMDAE
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRVMNVEH_type.h
//! @brief     (DRVMN) Sub-Component Vehicle Type Header.

#ifndef DRVMNVEH_TYPE_H_
#define DRVMNVEH_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRMHOD/DRMHOD_type.h"
#include "DRMDAE/DRMDAE_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! DRVMN sub-component vehicle debug data structure for MTS measurement. */
typedef struct
{
	DRMHOD_VehDbgType DRMHOD_VehDbgData; //!< DRMHOD module vehicle debug data structure for MTS measurement.
	DRMDAE_VehDbgType DRMDAE_VehDbgData; //!< DRMDAE module vehicle debug data structure for MTS measurement.
} DRVMN_VehDbgType;

/*! DRVMN sub-component vehicle output data structure. */
typedef struct
{
	DRMHOD_VehOutType DRMHOD_VehOutData; //!< DRMHOD module vehicle output data structure.
	DRMDAE_VehOutType DRMDAE_VehOutData; //!< DRMDAE module vehicle output data structure.
} DRVMN_VehOutType;

#ifdef __cplusplus
}
#endif

#endif // DRVMNVEH_TYPE_H_
