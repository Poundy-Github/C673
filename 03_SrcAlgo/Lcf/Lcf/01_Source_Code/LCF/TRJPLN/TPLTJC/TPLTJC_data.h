/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLTJC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLTJC_data.h
//! @brief     (TPLTJC) Module Data Header.

#ifndef TPLTJC_DATA_H_
#define TPLTJC_DATA_H_

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
 *	TPLTJC module vehicle get function. Function gets TPLTJC vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLTJC_VehDbgPtr</b> Global static pointer to TPLTJC vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLTJC_VehDbgType* TPLTJC_VehGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLTJC_MaxAclTraj_mps2
#define D_TPLTJC_MaxAclTraj_mps2 (TPLTJC_VehGetDbgPtr()->D_TPLTJC_MaxAclTraj_mps2) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_MaxAclTraj_mps2() (D_TPLTJC_MaxAclTraj_mps2) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_MaxAclTraj_mps2

#ifndef D_TPLTJC_MaxJerkOK_nu
#define D_TPLTJC_MaxJerkOK_nu (TPLTJC_VehGetDbgPtr()->D_TPLTJC_MaxJerkOK_nu) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_MaxJerkOK_nu() (D_TPLTJC_MaxJerkOK_nu) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_MaxJerkOK_nu

#ifndef D_TPLTJC_MaxJerkTraj_mps3
#define D_TPLTJC_MaxJerkTraj_mps3 (TPLTJC_VehGetDbgPtr()->D_TPLTJC_MaxJerkTraj_mps3) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_MaxJerkTraj_mps3() (D_TPLTJC_MaxJerkTraj_mps3) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_MaxJerkTraj_mps3

#ifndef D_TPLTJC_OptimalCost_nu
#define D_TPLTJC_OptimalCost_nu (TPLTJC_VehGetDbgPtr()->D_TPLTJC_OptimalCost_nu) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_OptimalCost_nu() (D_TPLTJC_OptimalCost_nu) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_OptimalCost_nu

#ifndef D_TPLTJC_PassedTrajLenPercent_nu
#define D_TPLTJC_PassedTrajLenPercent_nu (TPLTJC_VehGetDbgPtr()->D_TPLTJC_PassedTrajLenPercent_nu) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_PassedTrajLenPercent_nu() (D_TPLTJC_PassedTrajLenPercent_nu) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_PassedTrajLenPercent_nu

#ifndef D_TPLTJC_WeightEndTime_nu
#define D_TPLTJC_WeightEndTime_nu (TPLTJC_VehGetDbgPtr()->D_TPLTJC_WeightEndTime_nu) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_WeightEndTime_nu() (D_TPLTJC_WeightEndTime_nu) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_WeightEndTime_nu

#ifndef D_TPLTJC_WeightTgtDistY_nu
#define D_TPLTJC_WeightTgtDistY_nu (TPLTJC_VehGetDbgPtr()->D_TPLTJC_WeightTgtDistY_nu) //!< TPLTJC debug macro.
#define GET_D_TPLTJC_WeightTgtDistY_nu() (D_TPLTJC_WeightTgtDistY_nu) //!< TPLTJC debug macro getter.
#endif // D_TPLTJC_WeightTgtDistY_nu

#ifndef S_TPLTJC_EndPointTrajectory_nu
#define S_TPLTJC_EndPointTrajectory_nu (TPLTJC_VehGetDbgPtr()->S_TPLTJC_EndPointTrajectory_nu) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_EndPointTrajectory_nu() (S_TPLTJC_EndPointTrajectory_nu) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_EndPointTrajectory_nu

#ifndef S_TPLTJC_LengthOK_nu
#define S_TPLTJC_LengthOK_nu (TPLTJC_VehGetDbgPtr()->S_TPLTJC_LengthOK_nu) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_LengthOK_nu() (S_TPLTJC_LengthOK_nu) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_LengthOK_nu

#ifndef S_TPLTJC_MatrixInverseOK_nu
#define S_TPLTJC_MatrixInverseOK_nu (TPLTJC_VehGetDbgPtr()->S_TPLTJC_MatrixInverseOK_nu) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_MatrixInverseOK_nu() (S_TPLTJC_MatrixInverseOK_nu) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_MatrixInverseOK_nu

#ifndef S_TPLTJC_QuStatusTrajPlan_nu
#define S_TPLTJC_QuStatusTrajPlan_nu (TPLTJC_VehGetDbgPtr()->S_TPLTJC_QuStatusTrajPlan_nu) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_QuStatusTrajPlan_nu() (S_TPLTJC_QuStatusTrajPlan_nu) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_QuStatusTrajPlan_nu

#ifndef S_TPLTJC_TrajDistY1stDeriv_mps
#define S_TPLTJC_TrajDistY1stDeriv_mps (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajDistY1stDeriv_mps) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajDistY1stDeriv_mps() (S_TPLTJC_TrajDistY1stDeriv_mps) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_TrajDistY1stDeriv_mps

#ifndef S_TPLTJC_TrajDistY2ndDeriv_mps2
#define S_TPLTJC_TrajDistY2ndDeriv_mps2 (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajDistY2ndDeriv_mps2) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajDistY2ndDeriv_mps2() (S_TPLTJC_TrajDistY2ndDeriv_mps2) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_TrajDistY2ndDeriv_mps2

#ifndef S_TPLTJC_TrajDistY3rdDeriv_mps3
#define S_TPLTJC_TrajDistY3rdDeriv_mps3 (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajDistY3rdDeriv_mps3) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajDistY3rdDeriv_mps3() (S_TPLTJC_TrajDistY3rdDeriv_mps3) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_TrajDistY3rdDeriv_mps3

#ifndef S_TPLTJC_TrajDistYFmPrev_met
#define S_TPLTJC_TrajDistYFmPrev_met (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajDistYFmPrev_met) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajDistYFmPrev_met() (S_TPLTJC_TrajDistYFmPrev_met) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_TrajDistYFmPrev_met

#ifndef S_TPLTJC_TrajDistY_met
#define S_TPLTJC_TrajDistY_met (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajDistY_met) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajDistY_met() (S_TPLTJC_TrajDistY_met) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_TrajDistY_met

#ifndef S_TPLTJC_TrajEnd_nu
#define S_TPLTJC_TrajEnd_nu (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajEnd_nu) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajEnd_nu() (S_TPLTJC_TrajEnd_nu) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_TrajEnd_nu

#ifndef S_TPLTJC_YDt2TrjFmKpPrevDT_mps2
#define S_TPLTJC_YDt2TrjFmKpPrevDT_mps2 (TPLTJC_VehGetDbgPtr()->S_TPLTJC_YDt2TrjFmKpPrevDT_mps2) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_YDt2TrjFmKpPrevDT_mps2() (S_TPLTJC_YDt2TrjFmKpPrevDT_mps2) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_YDt2TrjFmKpPrevDT_mps2

#ifndef S_TPLTJC_YDt2TrjFmKpPrev_mps2
#define S_TPLTJC_YDt2TrjFmKpPrev_mps2 (TPLTJC_VehGetDbgPtr()->S_TPLTJC_YDt2TrjFmKpPrev_mps2) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_YDt2TrjFmKpPrev_mps2() (S_TPLTJC_YDt2TrjFmKpPrev_mps2) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_YDt2TrjFmKpPrev_mps2

#ifndef S_TPLTJC_YDt3TrjFmKpPrevDT_mps3
#define S_TPLTJC_YDt3TrjFmKpPrevDT_mps3 (TPLTJC_VehGetDbgPtr()->S_TPLTJC_YDt3TrjFmKpPrevDT_mps3) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_YDt3TrjFmKpPrevDT_mps3() (S_TPLTJC_YDt3TrjFmKpPrevDT_mps3) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_YDt3TrjFmKpPrevDT_mps3

#ifndef S_TPLTJC_YDtTrjFmHeadPrev_mps
#define S_TPLTJC_YDtTrjFmHeadPrev_mps (TPLTJC_VehGetDbgPtr()->S_TPLTJC_YDtTrjFmHeadPrev_mps) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_YDtTrjFmHeadPrev_mps() (S_TPLTJC_YDtTrjFmHeadPrev_mps) //!< TPLTJC debug macro getter.
#endif // S_TPLTJC_YDtTrjFmHeadPrev_mps

#ifndef S_TPLTJC_TrajParam_nu
#define S_TPLTJC_TrajParam_nu(i) (TPLTJC_VehGetDbgPtr()->S_TPLTJC_TrajParam_nu[(i)]) //!< TPLTJC debug macro.
#define GET_S_TPLTJC_TrajParam_nu(i) (S_TPLTJC_TrajParam_nu(i)) //!< TPLTJC debug macro getter.
#define GETA_S_TPLTJC_TrajParam_nu() ((const float32*) &S_TPLTJC_TrajParam_nu(0)) //!< TPLTJC debug macro pointer.
#endif // S_TPLTJC_TrajParam_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TPLTJC_DATA_H_
