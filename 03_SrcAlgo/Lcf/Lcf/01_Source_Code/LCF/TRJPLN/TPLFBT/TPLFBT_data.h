/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFBT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLFBT_data.h
//! @brief     (TPLFBT) Module Data Header.

#ifndef TPLFBT_DATA_H_
#define TPLFBT_DATA_H_

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
 *	TPLFBT module vehicle get function. Function gets TPLFBT vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLFBT_VehDbgPtr</b> Global static pointer to TPLFBT vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLFBT_VehDbgType* TPLFBT_VehGetDbgPtr(void);

/*!
 *	TPLFBT module vehicle get function. Function gets TPLFBT vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLFBT_VehOutPtr</b> Global static pointer to TPLFBT vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLFBT_VehOutType* TPLFBT_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLFBT_DeltaTargetCrv_1pm
#define D_TPLFBT_DeltaTargetCrv_1pm (TPLFBT_VehGetDbgPtr()->D_TPLFBT_DeltaTargetCrv_1pm) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_DeltaTargetCrv_1pm() (D_TPLFBT_DeltaTargetCrv_1pm) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_DeltaTargetCrv_1pm

#ifndef D_TPLFBT_DeltaTargetHeading_rad
#define D_TPLFBT_DeltaTargetHeading_rad (TPLFBT_VehGetDbgPtr()->D_TPLFBT_DeltaTargetHeading_rad) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_DeltaTargetHeading_rad() (D_TPLFBT_DeltaTargetHeading_rad) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_DeltaTargetHeading_rad

#ifndef D_TPLFBT_DeltaTargetPosY0_met
#define D_TPLFBT_DeltaTargetPosY0_met (TPLFBT_VehGetDbgPtr()->D_TPLFBT_DeltaTargetPosY0_met) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_DeltaTargetPosY0_met() (D_TPLFBT_DeltaTargetPosY0_met) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_DeltaTargetPosY0_met

#ifndef D_TPLFBT_GradLimitActive_nu
#define D_TPLFBT_GradLimitActive_nu (TPLFBT_VehGetDbgPtr()->D_TPLFBT_GradLimitActive_nu) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_GradLimitActive_nu() (D_TPLFBT_GradLimitActive_nu) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_GradLimitActive_nu

#ifndef D_TPLFBT_PlausiCheckStatus_nu
#define D_TPLFBT_PlausiCheckStatus_nu (TPLFBT_VehGetDbgPtr()->D_TPLFBT_PlausiCheckStatus_nu) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_PlausiCheckStatus_nu() (D_TPLFBT_PlausiCheckStatus_nu) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_PlausiCheckStatus_nu

#ifndef D_TPLFBT_QuStatusTrajPlan_nu
#define D_TPLFBT_QuStatusTrajPlan_nu (TPLFBT_VehGetDbgPtr()->D_TPLFBT_QuStatusTrajPlan_nu) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_QuStatusTrajPlan_nu() (D_TPLFBT_QuStatusTrajPlan_nu) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_QuStatusTrajPlan_nu

#ifndef D_TPLFBT_TargetSwitch_nu
#define D_TPLFBT_TargetSwitch_nu (TPLFBT_VehGetDbgPtr()->D_TPLFBT_TargetSwitch_nu) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_TargetSwitch_nu() (D_TPLFBT_TargetSwitch_nu) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_TargetSwitch_nu

#ifndef D_TPLFBT_UseTargetCorridor_nu
#define D_TPLFBT_UseTargetCorridor_nu (TPLFBT_VehGetDbgPtr()->D_TPLFBT_UseTargetCorridor_nu) //!< TPLFBT debug macro.
#define GET_D_TPLFBT_UseTargetCorridor_nu() (D_TPLFBT_UseTargetCorridor_nu) //!< TPLFBT debug macro getter.
#endif // D_TPLFBT_UseTargetCorridor_nu

#ifndef S_TPLFBT_CtrlErrDistY_met
#define S_TPLFBT_CtrlErrDistY_met (TPLFBT_VehGetDbgPtr()->S_TPLFBT_CtrlErrDistY_met) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_CtrlErrDistY_met() (S_TPLFBT_CtrlErrDistY_met) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_CtrlErrDistY_met

#ifndef S_TPLFBT_CtrlErrHeadAglPrev_rad
#define S_TPLFBT_CtrlErrHeadAglPrev_rad (TPLFBT_VehGetDbgPtr()->S_TPLFBT_CtrlErrHeadAglPrev_rad) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_CtrlErrHeadAglPrev_rad() (S_TPLFBT_CtrlErrHeadAglPrev_rad) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_CtrlErrHeadAglPrev_rad

#ifndef S_TPLFBT_CtrlErrHeadingAngle_rad
#define S_TPLFBT_CtrlErrHeadingAngle_rad (TPLFBT_VehGetDbgPtr()->S_TPLFBT_CtrlErrHeadingAngle_rad) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_CtrlErrHeadingAngle_rad() (S_TPLFBT_CtrlErrHeadingAngle_rad) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_CtrlErrHeadingAngle_rad

#ifndef S_TPLFBT_CurDistY_met
#define S_TPLFBT_CurDistY_met (TPLFBT_VehGetDbgPtr()->S_TPLFBT_CurDistY_met) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_CurDistY_met() (S_TPLFBT_CurDistY_met) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_CurDistY_met

#ifndef S_TPLFBT_CurHeading_rad
#define S_TPLFBT_CurHeading_rad (TPLFBT_VehGetDbgPtr()->S_TPLFBT_CurHeading_rad) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_CurHeading_rad() (S_TPLFBT_CurHeading_rad) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_CurHeading_rad

#ifndef S_TPLFBT_QuStatusTrajPlan_nu
#define S_TPLFBT_QuStatusTrajPlan_nu (TPLFBT_VehGetDbgPtr()->S_TPLFBT_QuStatusTrajPlan_nu) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_QuStatusTrajPlan_nu() (S_TPLFBT_QuStatusTrajPlan_nu) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_QuStatusTrajPlan_nu

#ifndef S_TPLFBT_TrajDistYPrev_met
#define S_TPLFBT_TrajDistYPrev_met (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajDistYPrev_met) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajDistYPrev_met() (S_TPLFBT_TrajDistYPrev_met) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajDistYPrev_met

#ifndef S_TPLFBT_TrajDistY_met
#define S_TPLFBT_TrajDistY_met (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajDistY_met) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajDistY_met() (S_TPLFBT_TrajDistY_met) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajDistY_met

#ifndef S_TPLFBT_TrajGuiQualifier_nu
#define S_TPLFBT_TrajGuiQualifier_nu (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajGuiQualifier_nu) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajGuiQualifier_nu() (S_TPLFBT_TrajGuiQualifier_nu) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajGuiQualifier_nu

#ifndef S_TPLFBT_TrajHeadInclPrev_rad
#define S_TPLFBT_TrajHeadInclPrev_rad (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajHeadInclPrev_rad) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajHeadInclPrev_rad() (S_TPLFBT_TrajHeadInclPrev_rad) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajHeadInclPrev_rad

#ifndef S_TPLFBT_TrajHeadingPrev_rad
#define S_TPLFBT_TrajHeadingPrev_rad (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajHeadingPrev_rad) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajHeadingPrev_rad() (S_TPLFBT_TrajHeadingPrev_rad) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajHeadingPrev_rad

#ifndef S_TPLFBT_TrajHeading_rad
#define S_TPLFBT_TrajHeading_rad (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajHeading_rad) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajHeading_rad() (S_TPLFBT_TrajHeading_rad) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajHeading_rad

#ifndef S_TPLFBT_TrajTgtCrvPrev_1pm
#define S_TPLFBT_TrajTgtCrvPrev_1pm (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajTgtCrvPrev_1pm) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajTgtCrvPrev_1pm() (S_TPLFBT_TrajTgtCrvPrev_1pm) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajTgtCrvPrev_1pm

#ifndef S_TPLFBT_TrajTgtCrv_1pm
#define S_TPLFBT_TrajTgtCrv_1pm (TPLFBT_VehGetDbgPtr()->S_TPLFBT_TrajTgtCrv_1pm) //!< TPLFBT debug macro.
#define GET_S_TPLFBT_TrajTgtCrv_1pm() (S_TPLFBT_TrajTgtCrv_1pm) //!< TPLFBT debug macro getter.
#endif // S_TPLFBT_TrajTgtCrv_1pm

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLFBT_TgtCorridorCrvGrd_1pms
#define D_TPLFBT_TgtCorridorCrvGrd_1pms (TPLFBT_VehGetOutPtr()->D_TPLFBT_TgtCorridorCrvGrd_1pms) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TgtCorridorCrvGrd_1pms() (D_TPLFBT_TgtCorridorCrvGrd_1pms) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TgtCorridorCrvGrd_1pms

#ifndef D_TPLFBT_TgtCorridorCrv_1pm
#define D_TPLFBT_TgtCorridorCrv_1pm (TPLFBT_VehGetOutPtr()->D_TPLFBT_TgtCorridorCrv_1pm) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TgtCorridorCrv_1pm() (D_TPLFBT_TgtCorridorCrv_1pm) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TgtCorridorCrv_1pm

#ifndef D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms
#define D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms (TPLFBT_VehGetOutPtr()->D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms() (D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms

#ifndef D_TPLFBT_TgtTrjCrvPrvwDT_1pm
#define D_TPLFBT_TgtTrjCrvPrvwDT_1pm (TPLFBT_VehGetOutPtr()->D_TPLFBT_TgtTrjCrvPrvwDT_1pm) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TgtTrjCrvPrvwDT_1pm() (D_TPLFBT_TgtTrjCrvPrvwDT_1pm) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TgtTrjCrvPrvwDT_1pm

#ifndef D_TPLFBT_TrajHeadingPrvw_rad
#define D_TPLFBT_TrajHeadingPrvw_rad (TPLFBT_VehGetOutPtr()->D_TPLFBT_TrajHeadingPrvw_rad) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TrajHeadingPrvw_rad() (D_TPLFBT_TrajHeadingPrvw_rad) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TrajHeadingPrvw_rad

#ifndef D_TPLFBT_TrajPlanInvalid_nu
#define D_TPLFBT_TrajPlanInvalid_nu (TPLFBT_VehGetOutPtr()->D_TPLFBT_TrajPlanInvalid_nu) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TrajPlanInvalid_nu() (D_TPLFBT_TrajPlanInvalid_nu) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TrajPlanInvalid_nu

#ifndef D_TPLFBT_TrajTgtCrvGrdPrev_1pms
#define D_TPLFBT_TrajTgtCrvGrdPrev_1pms (TPLFBT_VehGetOutPtr()->D_TPLFBT_TrajTgtCrvGrdPrev_1pms) //!< TPLFBT output macro.
#define GET_D_TPLFBT_TrajTgtCrvGrdPrev_1pms() (D_TPLFBT_TrajTgtCrvGrdPrev_1pms) //!< TPLFBT output macro getter.
#endif // D_TPLFBT_TrajTgtCrvGrdPrev_1pms

#ifdef __cplusplus
}
#endif

#endif // TPLFBT_DATA_H_
