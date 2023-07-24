/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLLCO
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLLCO_data.h
//! @brief     (TPLLCO) Module Data Header.

#ifndef TPLLCO_DATA_H_
#define TPLLCO_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH/LCFVEH_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TPLLCO module vehicle get function. Function gets TPLLCO vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLLCO_VehDbgPtr</b> Global static pointer to TPLLCO vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLLCO_VehDbgType* TPLLCO_VehGetDbgPtr(void);

/*!
 *	TPLLCO module vehicle get function. Function gets TPLLCO vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLLCO_VehOutPtr</b> Global static pointer to TPLLCO vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLLCO_VehOutType* TPLLCO_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLLCO_CCCDeviation_met
#define D_TPLLCO_CCCDeviation_met (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCDeviation_met) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCDeviation_met() (D_TPLLCO_CCCDeviation_met) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCDeviation_met

#ifndef D_TPLLCO_CCCInvalid_nu
#define D_TPLLCO_CCCInvalid_nu (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCInvalid_nu) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCInvalid_nu() (D_TPLLCO_CCCInvalid_nu) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCInvalid_nu

#ifndef D_TPLLCO_CCCLength_met
#define D_TPLLCO_CCCLength_met (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCLength_met) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCLength_met() (D_TPLLCO_CCCLength_met) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCLength_met

#ifndef D_TPLLCO_CCCPassedPerc_nu
#define D_TPLLCO_CCCPassedPerc_nu (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCPassedPerc_nu) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCPassedPerc_nu() (D_TPLLCO_CCCPassedPerc_nu) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCPassedPerc_nu

#ifndef D_TPLLCO_CCCReset_nu
#define D_TPLLCO_CCCReset_nu (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCReset_nu) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCReset_nu() (D_TPLLCO_CCCReset_nu) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCReset_nu

#ifndef D_TPLLCO_CCCTestPointDistX_met
#define D_TPLLCO_CCCTestPointDistX_met (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCTestPointDistX_met) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCTestPointDistX_met() (D_TPLLCO_CCCTestPointDistX_met) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCTestPointDistX_met

#ifndef D_TPLLCO_CCCWarning_nu
#define D_TPLLCO_CCCWarning_nu (TPLLCO_VehGetDbgPtr()->D_TPLLCO_CCCWarning_nu) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_CCCWarning_nu() (D_TPLLCO_CCCWarning_nu) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_CCCWarning_nu

#ifndef D_TPLLCO_DeltaProjPosX_met
#define D_TPLLCO_DeltaProjPosX_met (TPLLCO_VehGetDbgPtr()->D_TPLLCO_DeltaProjPosX_met) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_DeltaProjPosX_met() (D_TPLLCO_DeltaProjPosX_met) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_DeltaProjPosX_met

#ifndef D_TPLLCO_DeltaProjPosY_met
#define D_TPLLCO_DeltaProjPosY_met (TPLLCO_VehGetDbgPtr()->D_TPLLCO_DeltaProjPosY_met) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_DeltaProjPosY_met() (D_TPLLCO_DeltaProjPosY_met) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_DeltaProjPosY_met

#ifndef D_TPLLCO_EgoDistYPre_met
#define D_TPLLCO_EgoDistYPre_met (TPLLCO_VehGetDbgPtr()->D_TPLLCO_EgoDistYPre_met) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_EgoDistYPre_met() (D_TPLLCO_EgoDistYPre_met) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_EgoDistYPre_met

#ifndef D_TPLLCO_EgoHeadingPre_rad
#define D_TPLLCO_EgoHeadingPre_rad (TPLLCO_VehGetDbgPtr()->D_TPLLCO_EgoHeadingPre_rad) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_EgoHeadingPre_rad() (D_TPLLCO_EgoHeadingPre_rad) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_EgoHeadingPre_rad

#ifndef D_TPLLCO_PlausiCheckStatus_nu
#define D_TPLLCO_PlausiCheckStatus_nu (TPLLCO_VehGetDbgPtr()->D_TPLLCO_PlausiCheckStatus_nu) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_PlausiCheckStatus_nu() (D_TPLLCO_PlausiCheckStatus_nu) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_PlausiCheckStatus_nu

#ifndef D_TPLLCO_RightOri_rad
#define D_TPLLCO_RightOri_rad (TPLLCO_VehGetDbgPtr()->D_TPLLCO_RightOri_rad) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_RightOri_rad() (D_TPLLCO_RightOri_rad) //!< TPLLCO debug macro getter.
#endif // D_TPLLCO_RightOri_rad

#ifndef S_TPLLCO_DevDistY_met
#define S_TPLLCO_DevDistY_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_DevDistY_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_DevDistY_met() (S_TPLLCO_DevDistY_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_DevDistY_met

#ifndef S_TPLLCO_DevHeading_rad
#define S_TPLLCO_DevHeading_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_DevHeading_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_DevHeading_rad() (S_TPLLCO_DevHeading_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_DevHeading_rad

#ifndef S_TPLLCO_LeftCorridorCrv_1pm
#define S_TPLLCO_LeftCorridorCrv_1pm (TPLLCO_VehGetDbgPtr()->S_TPLLCO_LeftCorridorCrv_1pm) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_LeftCorridorCrv_1pm() (S_TPLLCO_LeftCorridorCrv_1pm) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_LeftCorridorCrv_1pm

#ifndef S_TPLLCO_LeftCorridorHeading_rad
#define S_TPLLCO_LeftCorridorHeading_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_LeftCorridorHeading_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_LeftCorridorHeading_rad() (S_TPLLCO_LeftCorridorHeading_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_LeftCorridorHeading_rad

#ifndef S_TPLLCO_LeftCorridorLength_met
#define S_TPLLCO_LeftCorridorLength_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_LeftCorridorLength_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_LeftCorridorLength_met() (S_TPLLCO_LeftCorridorLength_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_LeftCorridorLength_met

#ifndef S_TPLLCO_LeftCorridorPosX0_met
#define S_TPLLCO_LeftCorridorPosX0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_LeftCorridorPosX0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_LeftCorridorPosX0_met() (S_TPLLCO_LeftCorridorPosX0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_LeftCorridorPosX0_met

#ifndef S_TPLLCO_LeftCorridorPosY0_met
#define S_TPLLCO_LeftCorridorPosY0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_LeftCorridorPosY0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_LeftCorridorPosY0_met() (S_TPLLCO_LeftCorridorPosY0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_LeftCorridorPosY0_met

#ifndef S_TPLLCO_LeftCridrChngOfCrv_1pm2
#define S_TPLLCO_LeftCridrChngOfCrv_1pm2 (TPLLCO_VehGetDbgPtr()->S_TPLLCO_LeftCridrChngOfCrv_1pm2) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_LeftCridrChngOfCrv_1pm2() (S_TPLLCO_LeftCridrChngOfCrv_1pm2) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_LeftCridrChngOfCrv_1pm2

#ifndef S_TPLLCO_MeasDeltaT_sec
#define S_TPLLCO_MeasDeltaT_sec (TPLLCO_VehGetDbgPtr()->S_TPLLCO_MeasDeltaT_sec) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_MeasDeltaT_sec() (S_TPLLCO_MeasDeltaT_sec) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_MeasDeltaT_sec

#ifndef S_TPLLCO_PlausiCheckStatus_nu
#define S_TPLLCO_PlausiCheckStatus_nu (TPLLCO_VehGetDbgPtr()->S_TPLLCO_PlausiCheckStatus_nu) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_PlausiCheckStatus_nu() (S_TPLLCO_PlausiCheckStatus_nu) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_PlausiCheckStatus_nu

#ifndef S_TPLLCO_ReplanDevDistY_met
#define S_TPLLCO_ReplanDevDistY_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_ReplanDevDistY_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_ReplanDevDistY_met() (S_TPLLCO_ReplanDevDistY_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_ReplanDevDistY_met

#ifndef S_TPLLCO_ReplanDevHeading_rad
#define S_TPLLCO_ReplanDevHeading_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_ReplanDevHeading_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_ReplanDevHeading_rad() (S_TPLLCO_ReplanDevHeading_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_ReplanDevHeading_rad

#ifndef S_TPLLCO_RiCridrChngOfCrv_1pm2
#define S_TPLLCO_RiCridrChngOfCrv_1pm2 (TPLLCO_VehGetDbgPtr()->S_TPLLCO_RiCridrChngOfCrv_1pm2) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_RiCridrChngOfCrv_1pm2() (S_TPLLCO_RiCridrChngOfCrv_1pm2) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_RiCridrChngOfCrv_1pm2

#ifndef S_TPLLCO_RightCorridorCrv_1pm
#define S_TPLLCO_RightCorridorCrv_1pm (TPLLCO_VehGetDbgPtr()->S_TPLLCO_RightCorridorCrv_1pm) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_RightCorridorCrv_1pm() (S_TPLLCO_RightCorridorCrv_1pm) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_RightCorridorCrv_1pm

#ifndef S_TPLLCO_RightCorridorLength_met
#define S_TPLLCO_RightCorridorLength_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_RightCorridorLength_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_RightCorridorLength_met() (S_TPLLCO_RightCorridorLength_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_RightCorridorLength_met

#ifndef S_TPLLCO_RightCorridorPosX0_met
#define S_TPLLCO_RightCorridorPosX0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_RightCorridorPosX0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_RightCorridorPosX0_met() (S_TPLLCO_RightCorridorPosX0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_RightCorridorPosX0_met

#ifndef S_TPLLCO_RightCorridorPosY0_met
#define S_TPLLCO_RightCorridorPosY0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_RightCorridorPosY0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_RightCorridorPosY0_met() (S_TPLLCO_RightCorridorPosY0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_RightCorridorPosY0_met

#ifndef S_TPLLCO_RightCridrHeading_rad
#define S_TPLLCO_RightCridrHeading_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_RightCridrHeading_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_RightCridrHeading_rad() (S_TPLLCO_RightCridrHeading_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_RightCridrHeading_rad

#ifndef S_TPLLCO_TargetCorridorCrv_1pm
#define S_TPLLCO_TargetCorridorCrv_1pm (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetCorridorCrv_1pm) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetCorridorCrv_1pm() (S_TPLLCO_TargetCorridorCrv_1pm) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetCorridorCrv_1pm

#ifndef S_TPLLCO_TargetCorridorPosX0_met
#define S_TPLLCO_TargetCorridorPosX0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetCorridorPosX0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetCorridorPosX0_met() (S_TPLLCO_TargetCorridorPosX0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetCorridorPosX0_met

#ifndef S_TPLLCO_TargetCorridorPosY0_met
#define S_TPLLCO_TargetCorridorPosY0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetCorridorPosY0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetCorridorPosY0_met() (S_TPLLCO_TargetCorridorPosY0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetCorridorPosY0_met

#ifndef S_TPLLCO_TargetCridrHeading_rad
#define S_TPLLCO_TargetCridrHeading_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetCridrHeading_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetCridrHeading_rad() (S_TPLLCO_TargetCridrHeading_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetCridrHeading_rad

#ifndef S_TPLLCO_TargetCridrLength_met
#define S_TPLLCO_TargetCridrLength_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetCridrLength_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetCridrLength_met() (S_TPLLCO_TargetCridrLength_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetCridrLength_met

#ifndef S_TPLLCO_TargetPathCrv_rad
#define S_TPLLCO_TargetPathCrv_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetPathCrv_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetPathCrv_rad() (S_TPLLCO_TargetPathCrv_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetPathCrv_rad

#ifndef S_TPLLCO_TargetPathHeading_rad
#define S_TPLLCO_TargetPathHeading_rad (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetPathHeading_rad) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetPathHeading_rad() (S_TPLLCO_TargetPathHeading_rad) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetPathHeading_rad

#ifndef S_TPLLCO_TargetPathY0_met
#define S_TPLLCO_TargetPathY0_met (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TargetPathY0_met) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TargetPathY0_met() (S_TPLLCO_TargetPathY0_met) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TargetPathY0_met

#ifndef S_TPLLCO_TgtCridrChngOfCrv_1pm2
#define S_TPLLCO_TgtCridrChngOfCrv_1pm2 (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TgtCridrChngOfCrv_1pm2) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TgtCridrChngOfCrv_1pm2() (S_TPLLCO_TgtCridrChngOfCrv_1pm2) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TgtCridrChngOfCrv_1pm2

#ifndef S_TPLLCO_TriggerReplan_nu
#define S_TPLLCO_TriggerReplan_nu (TPLLCO_VehGetDbgPtr()->S_TPLLCO_TriggerReplan_nu) //!< TPLLCO debug macro.
#define GET_S_TPLLCO_TriggerReplan_nu() (S_TPLLCO_TriggerReplan_nu) //!< TPLLCO debug macro getter.
#endif // S_TPLLCO_TriggerReplan_nu

#ifndef D_TPLLCO_LeCridrTransDev_met
#define D_TPLLCO_LeCridrTransDev_met(i) (TPLLCO_VehGetDbgPtr()->D_TPLLCO_LeCridrTransDev_met[(i)]) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_LeCridrTransDev_met(i) (D_TPLLCO_LeCridrTransDev_met(i)) //!< TPLLCO debug macro getter.
#define GETA_D_TPLLCO_LeCridrTransDev_met() ((const float32*) &D_TPLLCO_LeCridrTransDev_met(0)) //!< TPLLCO debug macro pointer.
#endif // D_TPLLCO_LeCridrTransDev_met

#ifndef D_TPLLCO_RiCridrTransDev_met
#define D_TPLLCO_RiCridrTransDev_met(i) (TPLLCO_VehGetDbgPtr()->D_TPLLCO_RiCridrTransDev_met[(i)]) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_RiCridrTransDev_met(i) (D_TPLLCO_RiCridrTransDev_met(i)) //!< TPLLCO debug macro getter.
#define GETA_D_TPLLCO_RiCridrTransDev_met() ((const float32*) &D_TPLLCO_RiCridrTransDev_met(0)) //!< TPLLCO debug macro pointer.
#endif // D_TPLLCO_RiCridrTransDev_met

#ifndef D_TPLLCO_TgtCridrTransDev_met
#define D_TPLLCO_TgtCridrTransDev_met(i) (TPLLCO_VehGetDbgPtr()->D_TPLLCO_TgtCridrTransDev_met[(i)]) //!< TPLLCO debug macro.
#define GET_D_TPLLCO_TgtCridrTransDev_met(i) (D_TPLLCO_TgtCridrTransDev_met(i)) //!< TPLLCO debug macro getter.
#define GETA_D_TPLLCO_TgtCridrTransDev_met() ((const float32*) &D_TPLLCO_TgtCridrTransDev_met(0)) //!< TPLLCO debug macro pointer.
#endif // D_TPLLCO_TgtCridrTransDev_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLLCO_CCCEgoDistX_met
#define D_TPLLCO_CCCEgoDistX_met (TPLLCO_VehGetOutPtr()->D_TPLLCO_CCCEgoDistX_met) //!< TPLLCO output macro.
#define GET_D_TPLLCO_CCCEgoDistX_met() (D_TPLLCO_CCCEgoDistX_met) //!< TPLLCO output macro getter.
#endif // D_TPLLCO_CCCEgoDistX_met

#ifndef D_TPLLCO_CCCEgoDistY_met
#define D_TPLLCO_CCCEgoDistY_met (TPLLCO_VehGetOutPtr()->D_TPLLCO_CCCEgoDistY_met) //!< TPLLCO output macro.
#define GET_D_TPLLCO_CCCEgoDistY_met() (D_TPLLCO_CCCEgoDistY_met) //!< TPLLCO output macro getter.
#endif // D_TPLLCO_CCCEgoDistY_met

#ifndef D_TPLLCO_CCCEgoYawangle_rad
#define D_TPLLCO_CCCEgoYawangle_rad (TPLLCO_VehGetOutPtr()->D_TPLLCO_CCCEgoYawangle_rad) //!< TPLLCO output macro.
#define GET_D_TPLLCO_CCCEgoYawangle_rad() (D_TPLLCO_CCCEgoYawangle_rad) //!< TPLLCO output macro getter.
#endif // D_TPLLCO_CCCEgoYawangle_rad

#ifdef __cplusplus
}
#endif

#endif // TPLLCO_DATA_H_
