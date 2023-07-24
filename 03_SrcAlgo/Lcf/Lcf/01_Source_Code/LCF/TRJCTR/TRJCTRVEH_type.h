/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULES       : TCTEST,TCTDTE,TCTCDC,TCTFFC,TCTLGC,TCTCLM
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TRJCTRVEH_type.h
//! @brief     (TRJCTR) Sub-Component Vehicle Type Header.

#ifndef TRJCTRVEH_TYPE_H_
#define TRJCTRVEH_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTEST/TCTEST_type.h"
#include "TCTDTE/TCTDTE_type.h"
#include "TCTCDC/TCTCDC_type.h"
#include "TCTFFC/TCTFFC_type.h"
#include "TCTLGC/TCTLGC_type.h"
#include "TCTCLM/TCTCLM_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! TRJCTR sub-component vehicle debug data structure for MTS measurement. */
typedef struct
{
	TCTEST_VehDbgType TCTEST_VehDbgData; //!< TCTEST module vehicle debug data structure for MTS measurement.
	TCTDTE_VehDbgType TCTDTE_VehDbgData; //!< TCTDTE module vehicle debug data structure for MTS measurement.
	TCTCDC_VehDbgType TCTCDC_VehDbgData; //!< TCTCDC module vehicle debug data structure for MTS measurement.
	TCTFFC_VehDbgType TCTFFC_VehDbgData; //!< TCTFFC module vehicle debug data structure for MTS measurement.
	TCTLGC_VehDbgType TCTLGC_VehDbgData; //!< TCTLGC module vehicle debug data structure for MTS measurement.
	TCTCLM_VehDbgType TCTCLM_VehDbgData; //!< TCTCLM module vehicle debug data structure for MTS measurement.
} TRJCTR_VehDbgType;

/*! TRJCTR sub-component vehicle output data structure. */
typedef struct
{
	TCTLGC_VehOutType TCTLGC_VehOutData; //!< TCTLGC module vehicle output data structure.
} TRJCTR_VehOutType;

#ifdef __cplusplus
}
#endif

#endif // TRJCTRVEH_TYPE_H_
