/*! \file **********************************************************************

  COMPANY:                   Continental Teves AG & Co. oHG

  CPU:                       CPU-Independent

  COMPONENT:                 TJA (Traffic Jam Assist)

  MODULNAME:                 fusionKalmanFilter.h

  DESCRIPTION:               implements kalman filter for trajectory estimation

  AUTHOR:                    $Author: Nastasa, Elena (uidt4846) $

  CREATION DATE:

  VERSION:                   $Revision: 1.1 $

  CHANGES:                
  ---*/ /*---
  CHANGE:                    $Log: fusionKalmanFilter.h  $
  CHANGE:                    Revision 1.1 2019/07/17 12:06:13CEST Nastasa, Elena (uidt4846) 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/TJASA/TJACMB/project.pj


**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef FUSION_KALMAN_FILTER_
#define FUSION_KALMAN_FILTER_

#define GCC_C //ElNa: Uncomment for check-in. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifdef MATH_LOCAL_SFUNCTION
#include "tmwtypes.h"
#else
#ifdef GCC_C
#include "rtwtypes.h" //GrWe: Comment for SIL mode
#include "tjacmb_data.h"
#endif
#endif
/*****************************************************************************
  MACROS
*****************************************************************************/
#define LCOF_USE_DEBUG_OUTPUTS 0 /*make sure to change this if model is generated without debug outputs*/

/*this define is used to switch between tunable 1 (during development and testing) and const 0 parameters (shall be set for release) of the Kalman Filter*/
#define P_TJATTG_PARAMS_TUNABLE 1

#if P_TJATTG_PARAMS_TUNABLE
#define LCOF_PARAM_MODIFIER volatile
#else
#define LCOF_PARAM_MODIFIER const
#endif

#if P_TJATTG_PARAMS_TUNABLE
extern LCOF_PARAM_MODIFIER boolean_T P_TJATTG_UseEmObjStdDev_bool ;
#endif
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/*! @brief input to the trajectory estimation Kalman filter (provided by TJACMB simulink model) -- GrWe: Comment struct definition for SIL mode */
typedef struct {
  boolean_T  bLnValid_nu;/*lane validity - if true lane is used to update kf*/
  boolean_T  bObjValid_nu;/*object validity - if true object is used to update kf*/
  boolean_T  bPrediction_bool;/*prediction flag - if set kf does not execute measurement updates*/
  boolean_T bResetPosYState_bool; /*reset flag - if set kalman state for lateral position will be reset with input*/
  real32_T fLnPosY0_met; /*measured lateral deviation of lane center*/
  real32_T fLnHeading_rad; /*measured heading deviation of lane center trajectory*/
  real32_T fLnCrv_1pm;/*measured curvature of lane center trajectory*/
  real32_T fLnChngOfCrv_1pm2; /*measured change of curvature of lane center trajectory*/
  real32_T fObjXPos_met; /*measured object longitudinal position*/
  real32_T fObjYPos_met; /*measured object lateral position*/
  real32_T fObjXPosStdDev_met; /*measured object longitudinal position*/
  real32_T fObjYPosStdDev_met; /*measured object lateral position*/
  real32_T fCycleTime_sec; /*passed time since last call to fusionKalmanFilter - typically the cycle time*/
  real32_T fYawRate_rps;/*yaw rate of the ego vehicle*/
  real32_T fVelX_mps;/*velocity of the ego vehicle*/
  real32_T PredYawRtVar_r2ps2;/*yaw rate variance for prediction*/
  real32_T PredVelXVar_m2;/*velocity variance for prediction*/
  real32_T ModelPosYVar_m2;/*model uncertainty with respect to lateral position*/
  real32_T ModelYawVar_rad2;/*model uncertainty with respect to heading angle*/
  real32_T ModelCrvVar_1pm2;/*model uncertainty with respect to curvature*/
  real32_T ModelCrvChngVar_1pm4;/*model uncertainty with respect to curvature change*/
  real32_T ObjMeasPosYVar_m2;/*measurement uncertainty of lateral object position*/
  real32_T ObjMeasPosXVar_m2;/*measurement uncertainty of longitudinal object position*/
  real32_T LnMeasPosYVar_m2;/*measurement uncertainty of lateral lane position*/
  real32_T LnMeasHeadVar_rad2;/*measurement uncertainty of lane heading angle*/
  real32_T LnMeasCrvVar_1pm2;/*measurement uncertainty of lane curvature*/
  real32_T LnMeasCrvChngVar_1pm4;/*measurement uncertainty of lane curvature change*/
  real32_T CrvChngDecay_nu;/*Curvature change decay factor for object following*/
} fusionKFInput;

/*! @brief estimated trajectory (provided to TJACMB simulink model)*/
typedef struct {
  real32_T fPosY0_met;/*estimated lateral position of the trajectory start*/
  real32_T fHeading_rad;/*estimated heading of the trajectory*/
  real32_T fCrv_1pm; /*estimated curvature of the trajectory*/
  real32_T fChngOfCrv_1pm2; /*estimated change of curvature of the trajectory*/
  boolean_T  bTrajValid_nu; /*validity of the estimated trajectory - FALSE if KF-update fails or if none of the input triggers is false*/ 
#if LCOF_USE_DEBUG_OUTPUTS
  real32_T fKFCovarianceMatrix[16]; /*covariance matrix of the Kalman filter - for debuging purposes only*/
#endif
  /*TODO covariance matrix as output*/
} fusionKFOutput;


/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/* ****************************************************************************
Functionname:    fusionTgtCorridor                                      */ /*!

@brief           kalman filter to estimate the target trajectory based on lane and object measurements

@description     follows standard KF predictor/corrector scheme - updates based on object position measurement and
                 lane center trajectory measurements (represented by clothoid approximation). Prediction uses velocity
                 and yaw rate only and is executed even during degradation to always provide the "best possible" trajectory

@param[in]       input : struct comprising all data needed to estimate the target traj
                                  provided by the LCOF simulink model 
@param[out]          the estimated trajectory represented by polynom parameters (y0, psi, c0, c1) approximating a clothoid
                 and a flag that indicates if the trajectory is valid or not (invalid if no input available or internal error)

@author          Gregor Werum
*****************************************************************************/
void fusionTgtCorridor(const fusionKFInput* input, fusionKFOutput* output);

#endif
