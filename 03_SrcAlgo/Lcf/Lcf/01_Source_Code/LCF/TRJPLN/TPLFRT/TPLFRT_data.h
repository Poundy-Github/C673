/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFRT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLFRT_data.h
//! @brief     (TPLFRT) Module Data Header.

#ifndef TPLFRT_DATA_H_
#define TPLFRT_DATA_H_

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
 *	TPLFRT module vehicle get function. Function gets TPLFRT vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLFRT_VehDbgPtr</b> Global static pointer to TPLFRT vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLFRT_VehDbgType* TPLFRT_VehGetDbgPtr(void);

/*!
 *	TPLFRT module vehicle get function. Function gets TPLFRT vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLFRT_VehOutPtr</b> Global static pointer to TPLFRT vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLFRT_VehOutType* TPLFRT_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TPLFRT_CurDistY1stDeriv_mps
#define S_TPLFRT_CurDistY1stDeriv_mps (TPLFRT_VehGetDbgPtr()->S_TPLFRT_CurDistY1stDeriv_mps) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_CurDistY1stDeriv_mps() (S_TPLFRT_CurDistY1stDeriv_mps) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_CurDistY1stDeriv_mps

#ifndef S_TPLFRT_CurDistY1stToPrev_mps
#define S_TPLFRT_CurDistY1stToPrev_mps (TPLFRT_VehGetDbgPtr()->S_TPLFRT_CurDistY1stToPrev_mps) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_CurDistY1stToPrev_mps() (S_TPLFRT_CurDistY1stToPrev_mps) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_CurDistY1stToPrev_mps

#ifndef S_TPLFRT_CurDistY2ndDeriv_mps2
#define S_TPLFRT_CurDistY2ndDeriv_mps2 (TPLFRT_VehGetDbgPtr()->S_TPLFRT_CurDistY2ndDeriv_mps2) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_CurDistY2ndDeriv_mps2() (S_TPLFRT_CurDistY2ndDeriv_mps2) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_CurDistY2ndDeriv_mps2

#ifndef S_TPLFRT_CurDistYPreview_met
#define S_TPLFRT_CurDistYPreview_met (TPLFRT_VehGetDbgPtr()->S_TPLFRT_CurDistYPreview_met) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_CurDistYPreview_met() (S_TPLFRT_CurDistYPreview_met) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_CurDistYPreview_met

#ifndef S_TPLFRT_CurDistY_met
#define S_TPLFRT_CurDistY_met (TPLFRT_VehGetDbgPtr()->S_TPLFRT_CurDistY_met) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_CurDistY_met() (S_TPLFRT_CurDistY_met) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_CurDistY_met

#ifndef S_TPLFRT_DistY1stToDevHead_mps
#define S_TPLFRT_DistY1stToDevHead_mps (TPLFRT_VehGetDbgPtr()->S_TPLFRT_DistY1stToDevHead_mps) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_DistY1stToDevHead_mps() (S_TPLFRT_DistY1stToDevHead_mps) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_DistY1stToDevHead_mps

#ifndef S_TPLFRT_DistY2ndToDevHead_mps2
#define S_TPLFRT_DistY2ndToDevHead_mps2 (TPLFRT_VehGetDbgPtr()->S_TPLFRT_DistY2ndToDevHead_mps2) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_DistY2ndToDevHead_mps2() (S_TPLFRT_DistY2ndToDevHead_mps2) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_DistY2ndToDevHead_mps2

#ifndef S_TPLFRT_NumPointsCridrLeft_nu
#define S_TPLFRT_NumPointsCridrLeft_nu (TPLFRT_VehGetDbgPtr()->S_TPLFRT_NumPointsCridrLeft_nu) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_NumPointsCridrLeft_nu() (S_TPLFRT_NumPointsCridrLeft_nu) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_NumPointsCridrLeft_nu

#ifndef S_TPLFRT_NumTgtPoints_nu
#define S_TPLFRT_NumTgtPoints_nu (TPLFRT_VehGetDbgPtr()->S_TPLFRT_NumTgtPoints_nu) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_NumTgtPoints_nu() (S_TPLFRT_NumTgtPoints_nu) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_NumTgtPoints_nu

#ifndef S_TPLFRT_PlanHorizonVisRange_sec
#define S_TPLFRT_PlanHorizonVisRange_sec (TPLFRT_VehGetDbgPtr()->S_TPLFRT_PlanHorizonVisRange_sec) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_PlanHorizonVisRange_sec() (S_TPLFRT_PlanHorizonVisRange_sec) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_PlanHorizonVisRange_sec

#ifndef S_TPLFRT_PreviewTimeHeading_sec
#define S_TPLFRT_PreviewTimeHeading_sec (TPLFRT_VehGetDbgPtr()->S_TPLFRT_PreviewTimeHeading_sec) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_PreviewTimeHeading_sec() (S_TPLFRT_PreviewTimeHeading_sec) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_PreviewTimeHeading_sec

#ifndef S_TPLFRT_TrajAclRefCurve_mps2
#define S_TPLFRT_TrajAclRefCurve_mps2 (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TrajAclRefCurve_mps2) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TrajAclRefCurve_mps2() (S_TPLFRT_TrajAclRefCurve_mps2) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_TrajAclRefCurve_mps2

#ifndef S_TPLFRT_TrajDistY1stToPrev_mps
#define S_TPLFRT_TrajDistY1stToPrev_mps (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TrajDistY1stToPrev_mps) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TrajDistY1stToPrev_mps() (S_TPLFRT_TrajDistY1stToPrev_mps) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_TrajDistY1stToPrev_mps

#ifndef S_TPLFRT_TrajDistY2ndToPrev_mps2
#define S_TPLFRT_TrajDistY2ndToPrev_mps2 (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TrajDistY2ndToPrev_mps2) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TrajDistY2ndToPrev_mps2() (S_TPLFRT_TrajDistY2ndToPrev_mps2) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_TrajDistY2ndToPrev_mps2

#ifndef S_TPLFRT_TrajDistYPrev_met
#define S_TPLFRT_TrajDistYPrev_met (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TrajDistYPrev_met) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TrajDistYPrev_met() (S_TPLFRT_TrajDistYPrev_met) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_TrajDistYPrev_met

#ifndef S_TPLFRT_TrajPlanningHorizon_sec
#define S_TPLFRT_TrajPlanningHorizon_sec (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TrajPlanningHorizon_sec) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TrajPlanningHorizon_sec() (S_TPLFRT_TrajPlanningHorizon_sec) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_TrajPlanningHorizon_sec

#ifndef S_TPLFRT_TrajVelRefCurve_mps
#define S_TPLFRT_TrajVelRefCurve_mps (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TrajVelRefCurve_mps) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TrajVelRefCurve_mps() (S_TPLFRT_TrajVelRefCurve_mps) //!< TPLFRT debug macro getter.
#endif // S_TPLFRT_TrajVelRefCurve_mps

#ifndef S_TPLFRT_TgtDistY1stDeriv_mps
#define S_TPLFRT_TgtDistY1stDeriv_mps(i) (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TgtDistY1stDeriv_mps[(i)]) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TgtDistY1stDeriv_mps(i) (S_TPLFRT_TgtDistY1stDeriv_mps(i)) //!< TPLFRT debug macro getter.
#define GETA_S_TPLFRT_TgtDistY1stDeriv_mps() ((const float32*) &S_TPLFRT_TgtDistY1stDeriv_mps(0)) //!< TPLFRT debug macro pointer.
#endif // S_TPLFRT_TgtDistY1stDeriv_mps

#ifndef S_TPLFRT_TgtDistY2ndDeriv_mps2
#define S_TPLFRT_TgtDistY2ndDeriv_mps2(i) (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TgtDistY2ndDeriv_mps2[(i)]) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TgtDistY2ndDeriv_mps2(i) (S_TPLFRT_TgtDistY2ndDeriv_mps2(i)) //!< TPLFRT debug macro getter.
#define GETA_S_TPLFRT_TgtDistY2ndDeriv_mps2() ((const float32*) &S_TPLFRT_TgtDistY2ndDeriv_mps2(0)) //!< TPLFRT debug macro pointer.
#endif // S_TPLFRT_TgtDistY2ndDeriv_mps2

#ifndef S_TPLFRT_TgtDistY_met
#define S_TPLFRT_TgtDistY_met(i) (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TgtDistY_met[(i)]) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TgtDistY_met(i) (S_TPLFRT_TgtDistY_met(i)) //!< TPLFRT debug macro getter.
#define GETA_S_TPLFRT_TgtDistY_met() ((const float32*) &S_TPLFRT_TgtDistY_met(0)) //!< TPLFRT debug macro pointer.
#endif // S_TPLFRT_TgtDistY_met

#ifndef S_TPLFRT_TgtPoints_nu
#define S_TPLFRT_TgtPoints_nu(i) (TPLFRT_VehGetDbgPtr()->S_TPLFRT_TgtPoints_nu[(i)]) //!< TPLFRT debug macro.
#define GET_S_TPLFRT_TgtPoints_nu(i) (S_TPLFRT_TgtPoints_nu(i)) //!< TPLFRT debug macro getter.
#define GETA_S_TPLFRT_TgtPoints_nu() ((const float32*) &S_TPLFRT_TgtPoints_nu(0)) //!< TPLFRT debug macro pointer.
#endif // S_TPLFRT_TgtPoints_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TPLFRT_LeftDistY_met
#define S_TPLFRT_LeftDistY_met(i) (TPLFRT_VehGetOutPtr()->S_TPLFRT_LeftDistY_met[(i)]) //!< TPLFRT output macro.
#define GET_S_TPLFRT_LeftDistY_met(i) (S_TPLFRT_LeftDistY_met(i)) //!< TPLFRT output macro getter.
#define GETA_S_TPLFRT_LeftDistY_met() ((const float32*) &S_TPLFRT_LeftDistY_met(0)) //!< TPLFRT output macro pointer.
#endif // S_TPLFRT_LeftDistY_met

#ifdef __cplusplus
}
#endif

#endif // TPLFRT_DATA_H_
