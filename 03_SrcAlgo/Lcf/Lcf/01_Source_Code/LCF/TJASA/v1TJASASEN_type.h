/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v1TJASA
  MODULES       : TJALKA,TJAOBF,TJACMB,TJAGEN,TJASTM,TJATTG,TJATVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.3 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:25:12CEST $
  $Log: v1TJASASEN_type.h  $
  Revision 1.1.1.3 2020/04/09 14:25:12CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.1.1.2 2019/11/29 09:04:44CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     v1TJASASEN_type.h
//! @brief     (v1TJASA) Sub-Component Sensor Type Header.

#ifndef V1TJASASEN_TYPE_H_
#define V1TJASASEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJALKA/TJALKA_type.h"
#include "TJAOBF/TJAOBF_type.h"
#include "TJACMB/TJACMB_type.h"
#include "TJAGEN/TJAGEN_type.h"
#include "TJASTM/TJASTM_type.h"
#include "TJATTG/TJATTG_type.h"
#include "TJATVG/TJATVG_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! v1TJASA sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	TJALKA_SenDbgType TJALKA_SenDbgData; //!< TJALKA module sensor debug data structure for MTS measurement.
	TJAOBF_SenDbgType TJAOBF_SenDbgData; //!< TJAOBF module sensor debug data structure for MTS measurement.
	TJACMB_SenDbgType TJACMB_SenDbgData; //!< TJACMB module sensor debug data structure for MTS measurement.
	TJAGEN_SenDbgType TJAGEN_SenDbgData; //!< TJAGEN module sensor debug data structure for MTS measurement.
	TJASTM_SenDbgType TJASTM_SenDbgData; //!< TJASTM module sensor debug data structure for MTS measurement.
	TJATTG_SenDbgType TJATTG_SenDbgData; //!< TJATTG module sensor debug data structure for MTS measurement.
} v1TJASA_SenDbgType;

/*! v1TJASA sub-component sensor output data structure. */
typedef struct
{
	TJALKA_SenOutType TJALKA_SenOutData; //!< TJALKA module sensor output data structure.
	TJAOBF_SenOutType TJAOBF_SenOutData; //!< TJAOBF module sensor output data structure.
	TJACMB_SenOutType TJACMB_SenOutData; //!< TJACMB module sensor output data structure.
	TJAGEN_SenOutType TJAGEN_SenOutData; //!< TJAGEN module sensor output data structure.
	TJASTM_SenOutType TJASTM_SenOutData; //!< TJASTM module sensor output data structure.
	TJATTG_SenOutType TJATTG_SenOutData; //!< TJATTG module sensor output data structure.
	TJATVG_SenOutType TJATVG_SenOutData; //!< TJATVG module sensor output data structure.
} v1TJASA_SenOutType;

#ifdef __cplusplus
}
#endif

#endif /* V1TJASASEN_TYPE_H_*/
