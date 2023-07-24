/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v2ODPR
  MODULES       : ODPFOP,ODPFOH
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:22:08CEST $
  $Log: v2ODPRSEN_type.h  $
  Revision 1.1.1.2 2020/04/09 14:22:08CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.1.1.1 2019/11/29 09:01:55CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     v2ODPRSEN_type.h
//! @brief     (v2ODPR) Sub-Component Sensor Type Header.

#ifndef V2ODPRSEN_TYPE_H_
#define V2ODPRSEN_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ODPFOP/ODPFOP_type.h"
#include "ODPFOH/ODPFOH_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! v2ODPR sub-component sensor debug data structure for MTS measurement. */
typedef struct
{
	ODPFOP_SenDbgType ODPFOP_SenDbgData; //!< ODPFOP module sensor debug data structure for MTS measurement.
	ODPFOH_SenDbgType ODPFOH_SenDbgData; //!< ODPFOH module sensor debug data structure for MTS measurement.
} v2ODPR_SenDbgType;

/*! v2ODPR sub-component sensor output data structure. */
typedef struct
{
	ODPFOH_SenOutType ODPFOH_SenOutData; //!< ODPFOH module sensor output data structure.
} v2ODPR_SenOutType;

#ifdef __cplusplus
}
#endif

#endif /* V2ODPRSEN_TYPE_H_*/
