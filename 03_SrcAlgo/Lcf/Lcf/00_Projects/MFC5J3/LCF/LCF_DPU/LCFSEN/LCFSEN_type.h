/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Sensor
  SUB-COMPONENTS : v1ABPR,v2ODPR,VDPR,MFJSCT,LDPSA,RDPSA,ALCASA,v1TJASA,MDCTR,CTRSC,HMIOC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFSEN_type.h
//! @brief    Lateral Control Functions - Sensor (LCFSEN) Task Type Header.

#ifndef LCFSEN_TYPE_H_
#define LCFSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPR/v1ABPRSEN_type.h"
#include "ODPR/v2ODPRSEN_type.h"
#include "VDPR/VDPRSEN_type.h"
#include "MFJSCT/MFJSCTSEN_type.h"
#include "LDPSA/LDPSASEN_type.h"
#include "RDPSA/RDPSASEN_type.h"
#include "ALCASA/ALCASASEN_type.h"
#include "TJASA/v1TJASASEN_type.h"
#include "MDCTR/MDCTRSEN_type.h"
#include "CTRSC/CTRSCSEN_type.h"
#include "HMIOC/HMIOCSEN_type.h"
#include "LCFPRM/LCFPRM_type.h"

//MFC5J3
//#ifdef __cplusplus
//extern "C"
//{
//#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

#define _LCF_SENDBGTYPE_T_ //!< Macro switch for LCFSEN task debug type @ref LCF_SenDbgType.
/*! LCFSEN task debug data structure for MTS measurement. */
typedef struct
{
	v1ABPR_SenDbgType v1ABPR_SenDbgData; //!< v1ABPR sub-component debug data structure for MTS measurement.
	v2ODPR_SenDbgType v2ODPR_SenDbgData; //!< v2ODPR sub-component debug data structure for MTS measurement.
	VDPR_SenDbgType VDPR_SenDbgData; //!< VDPR sub-component debug data structure for MTS measurement.
	LDPSA_SenDbgType LDPSA_SenDbgData; //!< LDPSA sub-component debug data structure for MTS measurement.
	RDPSA_SenDbgType RDPSA_SenDbgData; //!< RDPSA sub-component debug data structure for MTS measurement.
	ALCASA_SenDbgType ALCASA_SenDbgData; //!< ALCASA sub-component debug data structure for MTS measurement.
	v1TJASA_SenDbgType v1TJASA_SenDbgData; //!< v1TJASA sub-component debug data structure for MTS measurement.
   MFJSCT_SenDbgType MFJSCT_SenDbgData; //!< MFJSCT sub-component debug data structure for MTS measurement.
} LCF_SenDbgType;

#define _LCF_SENOUTTYPE_T_ //!< Macro switch for LCFSEN task output type @ref LCF_SenOutType.
/*! LCFSEN task output data structure. */
typedef struct
{
	v1ABPR_SenOutType v1ABPR_SenOutData; //!< v1ABPR sub-component output data structure.
	v2ODPR_SenOutType v2ODPR_SenOutData; //!< v2ODPR sub-component output data structure.
	MFJSCT_SenOutType MFJSCT_SenOutData; //!< MFJSCT sub-component output data structure.	
	LDPSA_SenOutType LDPSA_SenOutData; //!< LDPSA sub-component output data structure.
	RDPSA_SenOutType RDPSA_SenOutData; //!< RDPSA sub-component output data structure.
	ALCASA_SenOutType ALCASA_SenOutData; //!< ALCASA sub-component output data structure.
	v1TJASA_SenOutType v1TJASA_SenOutData; //!< v1TJASA sub-component output data structure.
	MDCTR_SenOutType MDCTR_SenOutData; //!< MDCTR sub-component output data structure.
	CTRSC_SenOutType CTRSC_SenOutData; //!< CTRSC sub-component output data structure.
	HMIOC_SenOutType HMIOC_SenOutData; //!< HMIOC sub-component output data structure.
} LCF_SenOutType;

//#ifdef __cplusplus
//}
//#endif

#endif // LCFSEN_TYPE_H_
