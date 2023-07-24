/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPREP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPREP_data.h
//! @brief     (ABPREP) Module Data Header.

#ifndef ABPREP_DATA_H_
#define ABPREP_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"
#include "ABPREP_type.h" //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	ABPREP module sensor get function. Function gets ABPREP sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ABPREP_SenDbgPtr</b> Global static pointer to ABPREP sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ABPREP_SenDbgType* ABPREP_SenGetDbgPtr(void);

/*!
 *	ABPREP module sensor get function. Function gets ABPREP sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ABPREP_SenOutPtr</b> Global static pointer to ABPREP sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ABPREP_SenOutType* ABPREP_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_ABPREP_LaneStabilization_btf
#define S_ABPREP_LaneStabilization_btf (ABPREP_SenGetDbgPtr()->S_ABPREP_LaneStabilization_btf) //!< ABPREP debug macro.
#define GET_S_ABPREP_LaneStabilization_btf() (S_ABPREP_LaneStabilization_btf) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LaneStabilization_btf

#ifndef S_ABPREP_LeReClthCrvChng_1pm2
#define S_ABPREP_LeReClthCrvChng_1pm2 (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReClthCrvChng_1pm2) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReClthCrvChng_1pm2() (S_ABPREP_LeReClthCrvChng_1pm2) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReClthCrvChng_1pm2

#ifndef S_ABPREP_LeReClthCrvSIF_1pm
#define S_ABPREP_LeReClthCrvSIF_1pm (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReClthCrvSIF_1pm) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReClthCrvSIF_1pm() (S_ABPREP_LeReClthCrvSIF_1pm) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReClthCrvSIF_1pm

#ifndef S_ABPREP_LeReClthCrv_1pm
#define S_ABPREP_LeReClthCrv_1pm (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReClthCrv_1pm) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReClthCrv_1pm() (S_ABPREP_LeReClthCrv_1pm) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReClthCrv_1pm

#ifndef S_ABPREP_LeReClthHeadingSIF_rad
#define S_ABPREP_LeReClthHeadingSIF_rad (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReClthHeadingSIF_rad) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReClthHeadingSIF_rad() (S_ABPREP_LeReClthHeadingSIF_rad) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReClthHeadingSIF_rad

#ifndef S_ABPREP_LeReClthPosY0SIF_met
#define S_ABPREP_LeReClthPosY0SIF_met (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReClthPosY0SIF_met) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReClthPosY0SIF_met() (S_ABPREP_LeReClthPosY0SIF_met) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReClthPosY0SIF_met

#ifndef S_ABPREP_LeReHeading_rad
#define S_ABPREP_LeReHeading_rad (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReHeading_rad) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReHeading_rad() (S_ABPREP_LeReHeading_rad) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReHeading_rad

#ifndef S_ABPREP_LeReInvalidQuSIF_btf
#define S_ABPREP_LeReInvalidQuSIF_btf (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReInvalidQuSIF_btf) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReInvalidQuSIF_btf() (S_ABPREP_LeReInvalidQuSIF_btf) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReInvalidQuSIF_btf

#ifndef S_ABPREP_LeReInvalidQu_btf
#define S_ABPREP_LeReInvalidQu_btf (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReInvalidQu_btf) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReInvalidQu_btf() (S_ABPREP_LeReInvalidQu_btf) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReInvalidQu_btf

#ifndef S_ABPREP_LeReKFQuality_perc
#define S_ABPREP_LeReKFQuality_perc (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReKFQuality_perc) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReKFQuality_perc() (S_ABPREP_LeReKFQuality_perc) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReKFQuality_perc

#ifndef S_ABPREP_LeReKFStatus_enum
#define S_ABPREP_LeReKFStatus_enum (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReKFStatus_enum) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReKFStatus_enum() (S_ABPREP_LeReKFStatus_enum) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReKFStatus_enum

#ifndef S_ABPREP_LeReLatVel_mps
#define S_ABPREP_LeReLatVel_mps (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReLatVel_mps) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReLatVel_mps() (S_ABPREP_LeReLatVel_mps) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReLatVel_mps

#ifndef S_ABPREP_LeReLength_met
#define S_ABPREP_LeReLength_met (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReLength_met) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReLength_met() (S_ABPREP_LeReLength_met) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReLength_met

#ifndef S_ABPREP_LeRePosY0_met
#define S_ABPREP_LeRePosY0_met (ABPREP_SenGetDbgPtr()->S_ABPREP_LeRePosY0_met) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeRePosY0_met() (S_ABPREP_LeRePosY0_met) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeRePosY0_met

#ifndef S_ABPREP_LeReQuality_perc
#define S_ABPREP_LeReQuality_perc (ABPREP_SenGetDbgPtr()->S_ABPREP_LeReQuality_perc) //!< ABPREP debug macro.
#define GET_S_ABPREP_LeReQuality_perc() (S_ABPREP_LeReQuality_perc) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LeReQuality_perc

#ifndef S_ABPREP_LnBndGradLimActive_btf
#define S_ABPREP_LnBndGradLimActive_btf (ABPREP_SenGetDbgPtr()->S_ABPREP_LnBndGradLimActive_btf) //!< ABPREP debug macro.
#define GET_S_ABPREP_LnBndGradLimActive_btf() (S_ABPREP_LnBndGradLimActive_btf) //!< ABPREP debug macro getter.
#endif // S_ABPREP_LnBndGradLimActive_btf

#ifndef S_ABPREP_RiReClthCrvChng_1pm2
#define S_ABPREP_RiReClthCrvChng_1pm2 (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReClthCrvChng_1pm2) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReClthCrvChng_1pm2() (S_ABPREP_RiReClthCrvChng_1pm2) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReClthCrvChng_1pm2

#ifndef S_ABPREP_RiReClthCrvSIF_1pm
#define S_ABPREP_RiReClthCrvSIF_1pm (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReClthCrvSIF_1pm) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReClthCrvSIF_1pm() (S_ABPREP_RiReClthCrvSIF_1pm) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReClthCrvSIF_1pm

#ifndef S_ABPREP_RiReClthCrv_1pm
#define S_ABPREP_RiReClthCrv_1pm (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReClthCrv_1pm) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReClthCrv_1pm() (S_ABPREP_RiReClthCrv_1pm) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReClthCrv_1pm

#ifndef S_ABPREP_RiReClthHeadingSIF_rad
#define S_ABPREP_RiReClthHeadingSIF_rad (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReClthHeadingSIF_rad) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReClthHeadingSIF_rad() (S_ABPREP_RiReClthHeadingSIF_rad) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReClthHeadingSIF_rad

#ifndef S_ABPREP_RiReClthPosY0SIF_met
#define S_ABPREP_RiReClthPosY0SIF_met (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReClthPosY0SIF_met) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReClthPosY0SIF_met() (S_ABPREP_RiReClthPosY0SIF_met) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReClthPosY0SIF_met

#ifndef S_ABPREP_RiReHeading_rad
#define S_ABPREP_RiReHeading_rad (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReHeading_rad) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReHeading_rad() (S_ABPREP_RiReHeading_rad) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReHeading_rad

#ifndef S_ABPREP_RiReInvalidQuSIF_btf
#define S_ABPREP_RiReInvalidQuSIF_btf (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReInvalidQuSIF_btf) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReInvalidQuSIF_btf() (S_ABPREP_RiReInvalidQuSIF_btf) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReInvalidQuSIF_btf

#ifndef S_ABPREP_RiReInvalidQu_btf
#define S_ABPREP_RiReInvalidQu_btf (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReInvalidQu_btf) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReInvalidQu_btf() (S_ABPREP_RiReInvalidQu_btf) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReInvalidQu_btf

#ifndef S_ABPREP_RiReKFQuality_perc
#define S_ABPREP_RiReKFQuality_perc (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReKFQuality_perc) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReKFQuality_perc() (S_ABPREP_RiReKFQuality_perc) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReKFQuality_perc

#ifndef S_ABPREP_RiReKFStatus_enum
#define S_ABPREP_RiReKFStatus_enum (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReKFStatus_enum) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReKFStatus_enum() (S_ABPREP_RiReKFStatus_enum) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReKFStatus_enum

#ifndef S_ABPREP_RiReLatVel_mps
#define S_ABPREP_RiReLatVel_mps (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReLatVel_mps) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReLatVel_mps() (S_ABPREP_RiReLatVel_mps) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReLatVel_mps

#ifndef S_ABPREP_RiReLength_met
#define S_ABPREP_RiReLength_met (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReLength_met) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReLength_met() (S_ABPREP_RiReLength_met) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReLength_met

#ifndef S_ABPREP_RiRePosY0_met
#define S_ABPREP_RiRePosY0_met (ABPREP_SenGetDbgPtr()->S_ABPREP_RiRePosY0_met) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiRePosY0_met() (S_ABPREP_RiRePosY0_met) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiRePosY0_met

#ifndef S_ABPREP_RiReQuality_perc
#define S_ABPREP_RiReQuality_perc (ABPREP_SenGetDbgPtr()->S_ABPREP_RiReQuality_perc) //!< ABPREP debug macro.
#define GET_S_ABPREP_RiReQuality_perc() (S_ABPREP_RiReQuality_perc) //!< ABPREP debug macro getter.
#endif // S_ABPREP_RiReQuality_perc

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_ABPREP_LeReClthPosX0_met
#define S_ABPREP_LeReClthPosX0_met (ABPREP_SenGetOutPtr()->S_ABPREP_LeReClthPosX0_met) //!< ABPREP output macro.
#define GET_S_ABPREP_LeReClthPosX0_met() (S_ABPREP_LeReClthPosX0_met) //!< ABPREP output macro getter.
#endif // S_ABPREP_LeReClthPosX0_met

#ifndef S_ABPREP_RiReClthPosX0_met
#define S_ABPREP_RiReClthPosX0_met (ABPREP_SenGetOutPtr()->S_ABPREP_RiReClthPosX0_met) //!< ABPREP output macro.
#define GET_S_ABPREP_RiReClthPosX0_met() (S_ABPREP_RiReClthPosX0_met) //!< ABPREP output macro getter.
#endif // S_ABPREP_RiReClthPosX0_met

#ifdef __cplusplus
}
#endif

#endif // ABPREP_DATA_H_
