/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULES       : TPLLCO,TPLCEN,TPLFRT,TPLTJC,TPLFBT
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TRJPLNVEH_type.h
//! @brief     (TRJPLN) Sub-Component Vehicle Type Header.

#ifndef TRJPLNVEH_TYPE_H_
#define TRJPLNVEH_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLLCO/TPLLCO_type.h"
#include "TPLCEN/TPLCEN_type.h"
#include "TPLFRT/TPLFRT_type.h"
#include "TPLTJC/TPLTJC_type.h"
#include "TPLFBT/TPLFBT_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! TRJPLN sub-component vehicle debug data structure for MTS measurement. */
typedef struct
{
	TPLLCO_VehDbgType TPLLCO_VehDbgData; //!< TPLLCO module vehicle debug data structure for MTS measurement.
	TPLCEN_VehDbgType TPLCEN_VehDbgData; //!< TPLCEN module vehicle debug data structure for MTS measurement.
	TPLFRT_VehDbgType TPLFRT_VehDbgData; //!< TPLFRT module vehicle debug data structure for MTS measurement.
	TPLTJC_VehDbgType TPLTJC_VehDbgData; //!< TPLTJC module vehicle debug data structure for MTS measurement.
	TPLFBT_VehDbgType TPLFBT_VehDbgData; //!< TPLFBT module vehicle debug data structure for MTS measurement.
} TRJPLN_VehDbgType;

/*! TRJPLN sub-component vehicle output data structure. */
typedef struct
{
	TPLLCO_VehOutType TPLLCO_VehOutData; //!< TPLLCO module vehicle output data structure.
	TPLCEN_VehOutType TPLCEN_VehOutData; //!< TPLCEN module vehicle output data structure.
	TPLFRT_VehOutType TPLFRT_VehOutData; //!< TPLFRT module vehicle output data structure.
	TPLFBT_VehOutType TPLFBT_VehOutData; //!< TPLFBT module vehicle output data structure.
} TRJPLN_VehOutType;

#ifdef __cplusplus
}
#endif

#endif // TRJPLNVEH_TYPE_H_
