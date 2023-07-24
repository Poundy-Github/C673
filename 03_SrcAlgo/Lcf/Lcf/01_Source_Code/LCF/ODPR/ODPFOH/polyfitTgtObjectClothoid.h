/*! \file **********************************************************************

  COMPANY:                   Continental Teves AG & Co. oHG

  CPU:                       CPU-Independent

  COMPONENT:                 TJA (Traffic Jam Assist)

  MODULNAME:                 polyfitTgtObjectClothoid.c

  DESCRIPTION:               implements polyfit for target object trajectory estimation

  AUTHOR:                    $Author: Asong, Wedndah Asaha (uidj2187) $

  CREATION DATE:             $Date: 2019/03/25 07:31:55CET $

  VERSION:                   $Revision: 1.1 $

  CHANGES:                
  ---*/ /*---


**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef FILTER_OBJ_TRAJ_HEADER_
#define FILTER_OBJ_TRAJ_HEADER_


#define GCC_C //ElNa: Uncomment for check-in. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifdef MATH_LOCAL_SFUNCTION
#include "tmwtypes.h"
typedef boolean_T uint8;
typedef uint8_T uint8;
typedef uint16_T uint16;
typedef real32_T float32;
#ifndef GTYPES_H
typedef uint32_T uint32;
typedef int32_T sint32;
#endif
#else
#ifdef GCC_C
#include "rtwtypes.h"
#include "odpfoh_data.h"
#endif
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
//#ifdef MATH_LOCAL_SFUNCTION /* for SIL mode compatibility. Comment for check-in. */
/*! @brief input to the trajectory estimation Kalman filter (provided by the LCOF simulink model)*/
typedef struct {
  boolean_T  bEnable_bool;
  boolean_T  bAddNewSample_bool;
  boolean_T bReset_bool;
  real32_T fObjXPos_met; /*measured object longitudinal position*/
  real32_T fObjYPos_met; /*measured object lateral position*/
  real32_T fObjXPosStdDev_met; /*measured object longitudinal position*/
  real32_T fObjYPosStdDev_met; /*measured object lateral position*/
  real32_T fTimeSinceLastCall_sec; /*passed time since last call to filterTgtObjectClothoid - typically the cycle time*/
  real32_T fEgoCrv_1pm;/*curvature of the ego vehicle*/
  real32_T fEgoYawRate_rps;/*yaw rate of the ego vehicle*/
  real32_T fEgoVelX_mps;/*velocity of the ego vehicle*/
  real32_T pPredYawRtVar_r2ps2;/*yaw rate variance for prediction*/
  real32_T pPredVelXVar_m2;/*velocity variance for prediction*/
  real32_T pModelPosYVar_m2;/*model uncertainty with respect to lateral position*/
  real32_T pModelYawVar_rad2;/*model uncertainty with respect to heading angle*/
  real32_T pModelCrvVar_1pm2;/*model uncertainty with respect to curvature*/
  real32_T pModelCrvChngVar_1pm4;/*model uncertainty with respect to curvature change*/
  real32_T pObjMeasPosYVar_m2;/*measurement uncertainty of lateral object position*/
  real32_T pObjMeasPosXVar_m2;/*measurement uncertainty of longitudinal object position*/
  real32_T pCrvDecay_nu; /* Curvature change decay factor for polyfit */
  real32_T pCrvChngDecay_nu;/* Curvature change decay factor for polyfit */
  real32_T fMinHistStartPosX_met;
  real32_T fMaxSampleAge_sec;
  uint8_T uMinNumValidSamples_nu;
  real32_T fMinHistLength_met;
  real32_T fMaxGapEgoToHist_met;
  real32_T pWeightLastFit_nu;
} TgtObjectPF_Input;

/*! @brief estimated trajectory (provided to the LCOF simulink model)*/
typedef struct {
  uint8_T uNumValidSamples_nu;
  real32_T fPosX0_met;
  real32_T fPosY0_1st_met;
  real32_T fPosY0_3rd_met;
  real32_T fHeading_1st_rad;
  real32_T fHeading_3rd_rad;
  real32_T fCrv_1pm;
  real32_T fChngOfCrv_1pm2;
  real32_T fTrajLength_met;
  boolean_T bTrajUpdate_bool;
  boolean_T bTrajInvalid1st_bool;
  boolean_T bTrajInvalid3rd_bool;
  real32_T fMeanDevToTraj_1st_met;
  real32_T fMeanDevToTraj_3rd_met;
  real32_T fLastStoredPntX_met;
  real32_T fLastStoredPntY_met;
  real32_T fLastStoredAge_sec;
  real32_T fFirstStoredAge_sec;
  real32_T fMeanSampleAge_sec;
} TgtObjectPF_Output;
//#endif // Comment for check-in

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/* ****************************************************************************
Functionname:    polyfitTgtObjectClothoid

@brief           calculates a polynomial fit using least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle.
                 The equation matrix X is filled with the x/y sample points and
                 the polynomial coefficient vector is calculated

@param[in]       fObjXPos_met : target object x position

@param[in]       fObjYPos_met : target object y position

@param[out]      vecPolyCoeff : calculated polynomial coefficients

@author          Alexander Fen
**************************************************************************** */
void polyfitTgtObjectClothoid(const TgtObjectPF_Input* input, TgtObjectPF_Output* output);

#endif
