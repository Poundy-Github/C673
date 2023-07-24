/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:21:14CEST $
  $Log: ODPFOP_data.h  $
  Revision 1.4.1.2 2020/04/09 14:21:14CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:02:20CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOP_data.h
//! @brief     (ODPFOP) Module Data Header.

#ifndef ODPFOP_DATA_H_
#define ODPFOP_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	ODPFOP module sensor get function. Function gets ODPFOP sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ODPFOP_SenDbgPtr</b> Global static pointer to ODPFOP sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ODPFOP_SenDbgType* ODPFOP_SenGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_ODPFOP_AccFRObjTStamp_sec
#define S_ODPFOP_AccFRObjTStamp_sec (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccFRObjTStamp_sec) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccFRObjTStamp_sec() (S_ODPFOP_AccFRObjTStamp_sec) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccFRObjTStamp_sec

#ifndef S_ODPFOP_AccObjInvBitfield_btf
#define S_ODPFOP_AccObjInvBitfield_btf (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjInvBitfield_btf) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjInvBitfield_btf() (S_ODPFOP_AccObjInvBitfield_btf) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjInvBitfield_btf

#ifndef S_ODPFOP_AccObjPosXStdDev_met
#define S_ODPFOP_AccObjPosXStdDev_met (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjPosXStdDev_met) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjPosXStdDev_met() (S_ODPFOP_AccObjPosXStdDev_met) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjPosXStdDev_met

#ifndef S_ODPFOP_AccObjPosX_met
#define S_ODPFOP_AccObjPosX_met (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjPosX_met) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjPosX_met() (S_ODPFOP_AccObjPosX_met) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjPosX_met

#ifndef S_ODPFOP_AccObjPosYStdDev_met
#define S_ODPFOP_AccObjPosYStdDev_met (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjPosYStdDev_met) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjPosYStdDev_met() (S_ODPFOP_AccObjPosYStdDev_met) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjPosYStdDev_met

#ifndef S_ODPFOP_AccObjPosY_met
#define S_ODPFOP_AccObjPosY_met (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjPosY_met) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjPosY_met() (S_ODPFOP_AccObjPosY_met) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjPosY_met

#ifndef S_ODPFOP_AccObjRelAclX_mps2
#define S_ODPFOP_AccObjRelAclX_mps2 (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjRelAclX_mps2) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjRelAclX_mps2() (S_ODPFOP_AccObjRelAclX_mps2) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjRelAclX_mps2

#ifndef S_ODPFOP_AccObjRelAclY_mps2
#define S_ODPFOP_AccObjRelAclY_mps2 (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjRelAclY_mps2) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjRelAclY_mps2() (S_ODPFOP_AccObjRelAclY_mps2) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjRelAclY_mps2

#ifndef S_ODPFOP_AccObjRelVelX_mps
#define S_ODPFOP_AccObjRelVelX_mps (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjRelVelX_mps) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjRelVelX_mps() (S_ODPFOP_AccObjRelVelX_mps) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjRelVelX_mps

#ifndef S_ODPFOP_AccObjRelVelY_mps
#define S_ODPFOP_AccObjRelVelY_mps (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjRelVelY_mps) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjRelVelY_mps() (S_ODPFOP_AccObjRelVelY_mps) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjRelVelY_mps

#ifndef S_ODPFOP_AccObjRelYawAng_rad
#define S_ODPFOP_AccObjRelYawAng_rad (ODPFOP_SenGetDbgPtr()->S_ODPFOP_AccObjRelYawAng_rad) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_AccObjRelYawAng_rad() (S_ODPFOP_AccObjRelYawAng_rad) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_AccObjRelYawAng_rad

#ifndef S_ODPFOP_EstimatedObjPosX_met
#define S_ODPFOP_EstimatedObjPosX_met (ODPFOP_SenGetDbgPtr()->S_ODPFOP_EstimatedObjPosX_met) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_EstimatedObjPosX_met() (S_ODPFOP_EstimatedObjPosX_met) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_EstimatedObjPosX_met

#ifndef S_ODPFOP_EstimatedObjPosY_met
#define S_ODPFOP_EstimatedObjPosY_met (ODPFOP_SenGetDbgPtr()->S_ODPFOP_EstimatedObjPosY_met) //!< ODPFOP debug macro.
#define GET_S_ODPFOP_EstimatedObjPosY_met() (S_ODPFOP_EstimatedObjPosY_met) //!< ODPFOP debug macro getter.
#endif // S_ODPFOP_EstimatedObjPosY_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* ODPFOP_DATA_H_*/
