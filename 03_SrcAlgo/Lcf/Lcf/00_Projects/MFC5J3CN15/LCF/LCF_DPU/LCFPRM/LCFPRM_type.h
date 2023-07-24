/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3CN15
  COMPONENT      : LCF
  BUILD          : DPU
  TASKS          : SEN,VEH
  AUTHOR         : Build_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFPRM_type.h
//! @brief    Lateral Control Functions - Parameter (LCFPRM) Type Header.

#ifndef LCFPRM_TYPE_H_
#define LCFPRM_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   E N U M E R A T I O N S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! LCF common parameter data structure. */
typedef struct
{
	
	f32_s_0_60_1em3_t	P_ABPLBP_ABDSineWaveHoldOffT_sec; /*!< @description
	*	ABD sine wave road indicator hold off time \n\n
	*	\@asap_name: P_ABPLBP_ABDSineWaveHoldOffT_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_CorridorHoldAfterLost_sec; /*!< @description
	*	the parameter restrains Lateral position and curvature changing when lane available detection from LD is turn off \n\n
	*	\@asap_name: P_ABPLBP_CorridorHoldAfterLost_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvDiffForBridging_1pm; /*!< @description
	*	Curvature difference from corresponding lane to previous center lane to inhibit bridging \n\n
	*	\@asap_name: P_ABPLBP_CrvDiffForBridging_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvDiffForPitchProb_1pm; /*!< @description
	*	TBD \n\n
	*	\@asap_name: P_ABPLBP_CrvDiffForPitchProb_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0p0001_1_1em6_t	P_ABPLBP_CrvDiffRatioForPitch_nu; /*!< @description
	*	curvature threshold for pitching detection \n\n
	*	\@asap_name: P_ABPLBP_CrvDiffRatioForPitch_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0.0001 \n
	*	\@max: 1
	*/
	
	f32_m_0_200_1em3_t	P_ABPLBP_CrvEstimEndPoint_met; /*!< @description
	*	Define end point for 2nd order polynomial curvature estimation. \n\n
	*	\@asap_name: P_ABPLBP_CrvEstimEndPoint_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 200
	*/
	
	f32_s_0p06_10_1em3_t	P_ABPLBP_CrvEstimPT1Curve_sec; /*!< @description
	*	PT1 time constant for curvature signal filtering while driving in a curve \n\n
	*	\@asap_name: P_ABPLBP_CrvEstimPT1Curve_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	P_ABPLBP_CrvEstimPT1Straight_sec; /*!< @description
	*	PT1 time constant for curvature signal filtering while driving straight \n\n
	*	\@asap_name: P_ABPLBP_CrvEstimPT1Straight_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_m_0_150_1em3_t	P_ABPLBP_CrvEstimStartPoint_met; /*!< @description
	*	Define start point for 2nd order polynomial curvature estimation. \n\n
	*	\@asap_name: P_ABPLBP_CrvEstimStartPoint_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvFiltEnd_1pm; /*!< @description
	*	Final curvature value for maximum PT1 curvature filter time constant \n\n
	*	\@asap_name: P_ABPLBP_CrvFiltEnd_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_150_1em3_t	P_ABPLBP_CrvFiltMinCalcDist_met; /*!< @description
	*	Minimum distance between TLB (TrackerLaneBoundary) valid length and the desired start point for the curvature estimation. \n\n
	*	\@asap_name: P_ABPLBP_CrvFiltMinCalcDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvFiltStart_1pm; /*!< @description
	*	Start curvature value for maximum PT1 curvature filter time constant \n\n
	*	\@asap_name: P_ABPLBP_CrvFiltStart_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPLBP_CrvKFDecQualDeg_1ps; /*!< @description
	*	Quality decrease for the curvature kalman filter after the degraded update step has been applied \n\n
	*	\@asap_name: P_ABPLBP_CrvKFDecQualDeg_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPLBP_CrvKFDecQualPred_1ps; /*!< @description
	*	Quality decrease for the lane kalman filter after only a prediction step has been applied \n\n
	*	\@asap_name: P_ABPLBP_CrvKFDecQualPred_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvKFDefCurve_1pm; /*!< @description
	*	Defines the threshold for a curve (different filtering is applied in kalman filter) \n\n
	*	\@asap_name: P_ABPLBP_CrvKFDefCurve_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0p0001_1_1em6_t	P_ABPLBP_CrvKFDegradeWeight_nu; /*!< @description
	*	Weight for degraded update_laneKF \n\n
	*	\@asap_name: P_ABPLBP_CrvKFDegradeWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0.0001 \n
	*	\@max: 1
	*/
	
	f32_m_0_3p4E38_1em3_t	P_ABPLBP_CrvKFErrCoeff1_met; /*!< @description
	*	Geometric model error (kappa2diff) calculation factor 1 - [minimum radius european highway] \n\n
	*	\@asap_name: P_ABPLBP_CrvKFErrCoeff1_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 3.4E+38
	*/
	
	f32_mps_1_100_1em3_t	P_ABPLBP_CrvKFErrCoeff2_mps; /*!< @description
	*	Geometric model error (kappa2diff) calculation factor 2 - [average ego vehicle velocity highway] \n\n
	*	\@asap_name: P_ABPLBP_CrvKFErrCoeff2_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPLBP_CrvKFIncQual_1ps; /*!< @description
	*	Quality increase for the lane kalman filter after the update step has been applied \n\n
	*	\@asap_name: P_ABPLBP_CrvKFIncQual_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_1_100_1em3_t	P_ABPLBP_CrvKFInitRFactor_nu; /*!< @description
	*	Initialization factor for R_laneKF matrix -> achieve better transient oscillation \n\n
	*	\@asap_name: P_ABPLBP_CrvKFInitRFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_CrvKFQ11FacStr_nu; /*!< @description
	*	Q11 matrix factor for straight road \n\n
	*	\@asap_name: P_ABPLBP_CrvKFQ11FacStr_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_CrvKFQ11Fac_nu; /*!< @description
	*	Q11 matrix factor for curved road \n\n
	*	\@asap_name: P_ABPLBP_CrvKFQ11Fac_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_CrvKFStdDevCrvRt_1pm2; /*!< @description
	*	Center lane curvature rate standard deviation \n\n
	*	\@asap_name: P_ABPLBP_CrvKFStdDevCrvRt_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvKFStdDevCrv_1pm; /*!< @description
	*	Center lane curvature standard deviation \n\n
	*	\@asap_name: P_ABPLBP_CrvKFStdDevCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_CrvLimStepDtct_1pm; /*!< @description
	*	Threshold for step detection in lane marker curvature \n\n
	*	\@asap_name: P_ABPLBP_CrvLimStepDtct_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_CrvRateLimStepDtct_1pm2; /*!< @description
	*	Threshold for step detection in lane marker curvature change \n\n
	*	\@asap_name: P_ABPLBP_CrvRateLimStepDtct_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_m0p1_0p1_1em8_t	P_ABPLBP_CurvatureGrad_1pms; /*!< @description
	*	Curvature gradient \n\n
	*	\@asap_name: P_ABPLBP_CurvatureGrad_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pms2_0_0p1_1em7_t	P_ABPLBP_CurvatureRateGrad_1pm2s; /*!< @description
	*	Curvature rate gradient \n\n
	*	\@asap_name: P_ABPLBP_CurvatureRateGrad_1pm2s \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_DebounceTCrvRtStep_sec; /*!< @description
	*	Debounce time for curvature rate step detection \n\n
	*	\@asap_name: P_ABPLBP_DebounceTCrvRtStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_DebounceTCrvStep_sec; /*!< @description
	*	Debounce time for curvature step detection \n\n
	*	\@asap_name: P_ABPLBP_DebounceTCrvStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_DebounceTDistYStep_sec; /*!< @description
	*	Debounce time for lateral distance step detection \n\n
	*	\@asap_name: P_ABPLBP_DebounceTDistYStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_DebounceTYawAngStep_sec; /*!< @description
	*	Debounce time for yaw angle step detection \n\n
	*	\@asap_name: P_ABPLBP_DebounceTYawAngStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_DefaultLaneWidth_met; /*!< @description
	*	Default Lane Width \n\n
	*	\@asap_name: P_ABPLBP_DefaultLaneWidth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_DistYLimitStepDtctPitch_met; /*!< @description
	*	Threshold for step detection in lane marker positions during pitching detection \n\n
	*	\@asap_name: P_ABPLBP_DistYLimitStepDtctPitch_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_DistYLimitStepDtct_met; /*!< @description
	*	Threshold for step detection in lane marker positions \n\n
	*	\@asap_name: P_ABPLBP_DistYLimitStepDtct_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_DurValidDistY_sec; /*!< @description
	*	Debounce time after lateral distance step detection \n\n
	*	\@asap_name: P_ABPLBP_DurValidDistY_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_DurValidNewCorr_sec; /*!< @description
	*	The time it takes to consider a new corridor valid \n\n
	*	\@asap_name: P_ABPLBP_DurValidNewCorr_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_ExitCrvThresh_1pm; /*!< @description
	*	Uncoupled lane exit detetction curvature deviation threshold to inhibit detection above this curvature \n\n
	*	\@asap_name: P_ABPLBP_ExitCrvThresh_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_rad_0_1_1em6_t	P_ABPLBP_ExitHeadingThresh_rad; /*!< @description
	*	Exit detection heading angle threshold \n\n
	*	\@asap_name: P_ABPLBP_ExitHeadingThresh_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_FadingFactorDiffCrv_nu; /*!< @description
	*	Fading factor between left and right lane in tight curve situation. Fading will be applied dependent on the internal lane quality \n\n
	*	\@asap_name: P_ABPLBP_FadingFactorDiffCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_FadingFactorDiffPit_nu; /*!< @description
	*	Fading factor between left and right lane during pitching detected. Fading will be applied dependent on the internal lane quality \n\n
	*	\@asap_name: P_ABPLBP_FadingFactorDiffPit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_FadingFactorDiff_nu; /*!< @description
	*	Fading factor between left and right lane. Fading will be applied dependent on the internal lane quality \n\n
	*	\@asap_name: P_ABPLBP_FadingFactorDiff_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_FadingFactorOneSideCrv_nu; /*!< @description
	*	Fading factor for dynamic coupled/uncoupled lane weighting in tight curve situation. \n\n
	*	\@asap_name: P_ABPLBP_FadingFactorOneSideCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_FadingFactorOneSide_nu; /*!< @description
	*	Fading factor for dynamic coupled/uncoupled lane weighting \n\n
	*	\@asap_name: P_ABPLBP_FadingFactorOneSide_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_HeadLimStepDtct_rad; /*!< @description
	*	Threshold for step detection in heading angle \n\n
	*	\@asap_name: P_ABPLBP_HeadLimStepDtct_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_5_1em3_t	P_ABPLBP_JumpDebounceTimeSIF_sec; /*!< @description
	*	Debounce time for jumps of curvature, heading angle or lateral distance (safety interface) \n\n
	*	\@asap_name: P_ABPLBP_JumpDebounceTimeSIF_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_LDSlopeHoldOffT_sec; /*!< @description
	*	Hold off delay time for LD slope detection information \n\n
	*	\@asap_name: P_ABPLBP_LDSlopeHoldOffT_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_5_1em3_t	P_ABPLBP_LDVirtualTForBrid_sec; /*!< @description
	*	Defines the maximum time a LD virtual line is used for bridging \n\n
	*	\@asap_name: P_ABPLBP_LDVirtualTForBrid_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPLBP_LaneKFDecQualDeg_1ps; /*!< @description
	*	Quality decrease for the lane kalman filter after the degraded update step has been applied \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDecQualDeg_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPLBP_LaneKFDecQualPred_1ps; /*!< @description
	*	Quality decrease for the lane kalman filter after only a prediction step has been applied \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDecQualPred_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0p0001_1_1em6_t	P_ABPLBP_LaneKFDegradeWeight_nu; /*!< @description
	*	Weight for degraded update_laneKF \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDegradeWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0.0001 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LaneKFDynCrvFactor_nu; /*!< @description
	*	Factor to control the curvature signal dynamics in lane center kalman filter \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDynCrvFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LaneKFDynCrvRtFactor_nu; /*!< @description
	*	Factor to control the curvature signal dynamics in lane center kalman filter \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDynCrvRtFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LaneKFDynDistYFact_nu; /*!< @description
	*	Factor needed to set the dynamic of the lateral distance within the prediction step; \n
	*	100000.0f High Dynamic, 10000.0f Middle Dynamic, <1000.0f Low Dynamic \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDynDistYFact_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LaneKFDynYawFactor_nu; /*!< @description
	*	Factor needed to set the dynamic of the yaw angle within the prediction step \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDynYawFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_m_0_3p4E38_1em3_t	P_ABPLBP_LaneKFErrCoeff1_met; /*!< @description
	*	Geometric model error (kappa2diff) calculation factor 1 - [minimum radius european highway] \n\n
	*	\@asap_name: P_ABPLBP_LaneKFErrCoeff1_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 3.4E+38
	*/
	
	f32_mps_1_100_1em3_t	P_ABPLBP_LaneKFErrCoeff2_mps; /*!< @description
	*	Geometric model error (kappa2diff) calculation factor 2 - [average ego vehicle velocity highway] \n\n
	*	\@asap_name: P_ABPLBP_LaneKFErrCoeff2_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPLBP_LaneKFIncQual_1ps; /*!< @description
	*	Quality increase for the lane kalman filter after the update step has been applied \n\n
	*	\@asap_name: P_ABPLBP_LaneKFIncQual_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_1_100_1em3_t	P_ABPLBP_LaneKFInitRFactor_nu; /*!< @description
	*	Initialization factor for R_laneKF matrix -> achieve better transient oscillation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFInitRFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ABPLBP_LaneKFKGainFac_nu; /*!< @description
	*	Factor needed to set the dynamic of the lateral position within degraded update \n\n
	*	\@asap_name: P_ABPLBP_LaneKFKGainFac_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_LaneKFStdDevCrvRt_1pm2; /*!< @description
	*	Center lane curvature rate standard deviation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFStdDevCrvRt_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p5_1em3_t	P_ABPLBP_LaneKFStdDevCrv_1pm; /*!< @description
	*	Center lane curvature standard deviation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFStdDevCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.5
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_LaneKFStdDevLatDist_met; /*!< @description
	*	Center lane lateral distance standard deviation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFStdDevLatDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_radps_0_1_1em3_t	P_ABPLBP_LaneKFStdDevYawRt_radps; /*!< @description
	*	Center lane yaw rate standard deviation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFStdDevYawRt_radps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_rad_0_1_1em6_t	P_ABPLBP_LaneKFStdDevYaw_rad; /*!< @description
	*	Center lane yaw angle standard deviation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFStdDevYaw_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_LaneQualCrvLim_1pm; /*!< @description
	*	tight curvature check for lane quality \n\n
	*	\@asap_name: P_ABPLBP_LaneQualCrvLim_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LaneWidthDiffCrvFactor_nu; /*!< @description
	*	curvature-dependent lane width difference threshold for Exit detection \n\n
	*	\@asap_name: P_ABPLBP_LaneWidthDiffCrvFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_LaneWidthDiffThresh_met; /*!< @description
	*	Lane width difference threshold for exit detection \n\n
	*	\@asap_name: P_ABPLBP_LaneWidthDiffThresh_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps_0_100_1em3_t	P_ABPLBP_LaneWidthGrad_mps; /*!< @description
	*	Gradient limit for lane width before PT1 filter \n\n
	*	\@asap_name: P_ABPLBP_LaneWidthGrad_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LatDistDevCrvFactor_nu; /*!< @description
	*	a factor for lateral deviation in tight curve situation \n\n
	*	\@asap_name: P_ABPLBP_LatDistDevCrvFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_LatDistDevCrvLSP_1pm; /*!< @description
	*	Lateral distance deviation observer curvature threshold (LSP - lower hysteresis) \n\n
	*	\@asap_name: P_ABPLBP_LatDistDevCrvLSP_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_LatDistDevCrvRSP_1pm; /*!< @description
	*	Lateral distance deviation observer curvature threshold (LSP - lower hysteresis) \n\n
	*	\@asap_name: P_ABPLBP_LatDistDevCrvRSP_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_LatDistDevThreshStr_met; /*!< @description
	*	Lateral deviation threshold for estimated and measured lateral position on straight \n\n
	*	\@asap_name: P_ABPLBP_LatDistDevThreshStr_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_LatDistDevThresh_met; /*!< @description
	*	Lateral deviation threshold for estimated and measured lateral position \n\n
	*	\@asap_name: P_ABPLBP_LatDistDevThresh_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_LatDistGrad_mps; /*!< @description
	*	Lateral distance gradient \n\n
	*	\@asap_name: P_ABPLBP_LatDistGrad_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_5_1em3_t	P_ABPLBP_LatencyTimeSIF_sec; /*!< @description
	*	Latency time for lateral distance latency compensation \n\n
	*	\@asap_name: P_ABPLBP_LatencyTimeSIF_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_Pers_0_10000_1em3_t	P_ABPLBP_LnQualGrad_percps; /*!< @description
	*	 \n\n
	*	\@asap_name: P_ABPLBP_LnQualGrad_percps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_MaxCrvRateRange_1pm2; /*!< @description
	*	Maximum range check value for curvature rate \n\n
	*	\@asap_name: P_ABPLBP_MaxCrvRateRange_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_MaxCurvatureRange_1pm; /*!< @description
	*	Maximum range check value for curvature \n\n
	*	\@asap_name: P_ABPLBP_MaxCurvatureRange_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_MaxDistYRange_met; /*!< @description
	*	Maximum range check value for lateral position \n\n
	*	\@asap_name: P_ABPLBP_MaxDistYRange_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_MaxHeadingRange_rad; /*!< @description
	*	Maximum range check value for yaw angle \n\n
	*	\@asap_name: P_ABPLBP_MaxHeadingRange_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_MaxLaneWidthHyst_met; /*!< @description
	*	Lane widht hysteresis for maximum lane width \n\n
	*	\@asap_name: P_ABPLBP_MaxLaneWidthHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_MaxLaneWidth_met; /*!< @description
	*	Maximum valid lane width for LCF \n\n
	*	\@asap_name: P_ABPLBP_MaxLaneWidth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ABPLBP_MaxRangeHyst_nu; /*!< @description
	*	Maximum range check hysteresis factor \n\n
	*	\@asap_name: P_ABPLBP_MaxRangeHyst_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_300_1em3_t	P_ABPLBP_MaxValidLengthRange_met; /*!< @description
	*	Maximum range check value valid length \n\n
	*	\@asap_name: P_ABPLBP_MaxValidLengthRange_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_MinLaneWidthHyst_met; /*!< @description
	*	Hysteresis for minimum lane width \n\n
	*	\@asap_name: P_ABPLBP_MinLaneWidthHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_MinLaneWidth_met; /*!< @description
	*	Minimum valid lane width for LCF \n\n
	*	\@asap_name: P_ABPLBP_MinLaneWidth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_MinUncoupBridTime_sec; /*!< @description
	*	Minimum uncoupled lane bridging time \n\n
	*	\@asap_name: P_ABPLBP_MinUncoupBridTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps_0_100_1em3_t	P_ABPLBP_MinVelForKalmanFilt_mps; /*!< @description
	*	Minimum kalman filter input velocity to avoid internal matrix inversion failures \n\n
	*	\@asap_name: P_ABPLBP_MinVelForKalmanFilt_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_0_100_1em3_t	P_ABPLBP_MinVelUpDownDtct_mps; /*!< @description
	*	Minimum velocity for UpDownhill detection \n\n
	*	\@asap_name: P_ABPLBP_MinVelUpDownDtct_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pms_m0p1_0p1_1em8_t	P_ABPLBP_MotCompCrvGrad_1pms; /*!< @description
	*	Curvature gradient limiter after motion compensation \n\n
	*	\@asap_name: P_ABPLBP_MotCompCrvGrad_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pms2_0_0p1_1em7_t	P_ABPLBP_MotCompCrvRtGrad_1pms2; /*!< @description
	*	Curvature gradient limiter after motion compensation \n\n
	*	\@asap_name: P_ABPLBP_MotCompCrvRtGrad_1pms2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_MotCompCrvThresh_1pm; /*!< @description
	*	Motion compensation curvature threshold \n\n
	*	\@asap_name: P_ABPLBP_MotCompCrvThresh_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_MotCompDYGradLim_met; /*!< @description
	*	Delta lateral distance gradient limit threshold \n\n
	*	\@asap_name: P_ABPLBP_MotCompDYGradLim_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_MotCompDYawGradLim_rad; /*!< @description
	*	Delta yaw gradient limit threshold \n\n
	*	\@asap_name: P_ABPLBP_MotCompDYawGradLim_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_0_100_1em3_t	P_ABPLBP_MotCompLatDistGrad_mps; /*!< @description
	*	Motion compensation lateral distance gradient \n\n
	*	\@asap_name: P_ABPLBP_MotCompLatDistGrad_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_150_1em3_t	P_ABPLBP_MotCompMinValLenPF_met; /*!< @description
	*	Motion compensation minimum valid length of polyfit (reset condition) \n\n
	*	\@asap_name: P_ABPLBP_MotCompMinValLenPF_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t	P_ABPLBP_MotCompMinValLength_met; /*!< @description
	*	Minimum valid length for motion compensation \n\n
	*	\@asap_name: P_ABPLBP_MotCompMinValLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t	P_ABPLBP_MotCompPolyMinLen_met; /*!< @description
	*	Motion compensation minimum polyfit input valid length for sFunction enable switch \n\n
	*	\@asap_name: P_ABPLBP_MotCompPolyMinLen_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_radps_0_1_1em3_t	P_ABPLBP_MotCompYawGrad_radps; /*!< @description
	*	Motion compensation yaw angle gradient \n\n
	*	\@asap_name: P_ABPLBP_MotCompYawGrad_radps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_m1000_1000_1em3_t	P_ABPLBP_MxBridgDistOneSided_met; /*!< @description
	*	Maximum allowed bridging distance \n\n
	*	\@asap_name: P_ABPLBP_MxBridgDistOneSided_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_s_0_100000_1em3_t	P_ABPLBP_MxBridgTimeOneSided_sec; /*!< @description
	*	Time span in which lane bridging is allowed. \n\n
	*	\@asap_name: P_ABPLBP_MxBridgTimeOneSided_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_60_1em3_t	P_ABPLBP_OverpassDfltQualT_sec; /*!< @description
	*	Overpass (dark-light transition) hold off delay time \n\n
	*	\@asap_name: P_ABPLBP_OverpassDfltQualT_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0p06_10_1em3_t	P_ABPLBP_PT1LaneWidthTConst_sec; /*!< @description
	*	PT1 filter time constant for lane width \n\n
	*	\@asap_name: P_ABPLBP_PT1LaneWidthTConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p001_100_1em3_t	P_ABPLBP_PT1LaneWidthTInit_sec; /*!< @description
	*	Init value for PT1 time constant of lane width lowpass filter \n\n
	*	\@asap_name: P_ABPLBP_PT1LaneWidthTInit_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.001 \n
	*	\@max: 100
	*/
	
	f32_Pers_m1000_0_1em4_t	P_ABPLBP_PT1LaneWidthTLD_1ps; /*!< @description
	*	PT1 lane width time constant init gradient limitation (lower gradient) \n\n
	*	\@asap_name: P_ABPLBP_PT1LaneWidthTLD_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: -1000 \n
	*	\@max: 0
	*/
	
	f32_Pers_0_10000_1em3_t	P_ABPLBP_PT1LaneWidthTLU_1ps; /*!< @description
	*	PT1 lane width time constant init gradient limitation (upper gradient) \n\n
	*	\@asap_name: P_ABPLBP_PT1LaneWidthTLU_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_s_0p06_10_1em3_t	P_ABPLBP_PT1TimeConstSIF_sec; /*!< @description
	*	Latency compensation lateral velocity PT1 filter time constant (safety interface) \n\n
	*	\@asap_name: P_ABPLBP_PT1TimeConstSIF_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	P_ABPLBP_PitchProbDec_perc; /*!< @description
	*	number of decreasing pitching probability by 1cycle \n\n
	*	\@asap_name: P_ABPLBP_PitchProbDec_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_PitchProbGain_nu; /*!< @description
	*	gain for increasing probability \n\n
	*	\@asap_name: P_ABPLBP_PitchProbGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_m_m1000_1000_1em3_t	P_ABPLBP_QualCrvPenFactor_nu; /*!< @description
	*	Factor to increase curvature penalty range in tight curves \n\n
	*	\@asap_name: P_ABPLBP_QualCrvPenFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_QualCrvPenWeight_nu; /*!< @description
	*	Quality penalty weight for curvature \n\n
	*	\@asap_name: P_ABPLBP_QualCrvPenWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_QualCrvRtPenMax_1pm2; /*!< @description
	*	Quality maximum penalty curvature rate \n\n
	*	\@asap_name: P_ABPLBP_QualCrvRtPenMax_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_QualCrvRtPenMin_1pm2; /*!< @description
	*	Quality minimum penalty curvature rate \n\n
	*	\@asap_name: P_ABPLBP_QualCrvRtPenMin_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_QualCrvRtPenWeight_nu; /*!< @description
	*	Quality penalty weight for curvature rate \n\n
	*	\@asap_name: P_ABPLBP_QualCrvRtPenWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_QualCurvaturePenMax_1pm; /*!< @description
	*	Quality penalty curvature max value \n\n
	*	\@asap_name: P_ABPLBP_QualCurvaturePenMax_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_QualCurvaturePenMin_1pm; /*!< @description
	*	Quality penalty curvature min value \n\n
	*	\@asap_name: P_ABPLBP_QualCurvaturePenMin_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ABPLBP_QualFadingFac_nu; /*!< @description
	*	Lane quality fading factor between lookahead distance and standard deviation term \n\n
	*	\@asap_name: P_ABPLBP_QualFadingFac_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	P_ABPLBP_QualGradLimLD_perc; /*!< @description
	*	Quality gradient limit (lower) \n\n
	*	\@asap_name: P_ABPLBP_QualGradLimLD_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_QualGradLimLU_perc; /*!< @description
	*	Quality gradient limit (upper) \n\n
	*	\@asap_name: P_ABPLBP_QualGradLimLU_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_QualHeadingPenMax_rad; /*!< @description
	*	Quality heading max penalty value \n\n
	*	\@asap_name: P_ABPLBP_QualHeadingPenMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_QualHeadingPenMin_rad; /*!< @description
	*	Quality heading min penalty value \n\n
	*	\@asap_name: P_ABPLBP_QualHeadingPenMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_QualLatDistPenMax_met; /*!< @description
	*	Quality lateral distance max penalty value \n\n
	*	\@asap_name: P_ABPLBP_QualLatDistPenMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_QualLatDistPenMin_met; /*!< @description
	*	Quality lateral distance min penalty value \n\n
	*	\@asap_name: P_ABPLBP_QualLatDistPenMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_QualLatDistPenWeight_nu; /*!< @description
	*	Quality penalty weight for lateral distance \n\n
	*	\@asap_name: P_ABPLBP_QualLatDistPenWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_QualPenFactorPitch_nu; /*!< @description
	*	Quality penalty factor during pitching detection \n\n
	*	\@asap_name: P_ABPLBP_QualPenFactorPitch_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_QualPenFactor_nu; /*!< @description
	*	Quality penalty factor \n\n
	*	\@asap_name: P_ABPLBP_QualPenFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	P_ABPLBP_QualPenGradLimLD_nu; /*!< @description
	*	Quality penalty gradient limiter (lower) \n\n
	*	\@asap_name: P_ABPLBP_QualPenGradLimLD_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_QualPenGradLimLU_nu; /*!< @description
	*	Quality penalty gradient limiter (upper) \n\n
	*	\@asap_name: P_ABPLBP_QualPenGradLimLU_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_QualPenHoldFactor_nu; /*!< @description
	*	Quality penalty hold factor \n\n
	*	\@asap_name: P_ABPLBP_QualPenHoldFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_m_0_150_1em3_t	P_ABPLBP_QualValidLength_met; /*!< @description
	*	Quality valid length \n\n
	*	\@asap_name: P_ABPLBP_QualValidLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_QualYawPenWeight_nu; /*!< @description
	*	Quality penalty weight for yaw angle \n\n
	*	\@asap_name: P_ABPLBP_QualYawPenWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_StrDtctCrvLSP_1pm; /*!< @description
	*	Straight detection curvature hysteresis (LSP) \n\n
	*	\@asap_name: P_ABPLBP_StrDtctCrvLSP_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_StrDtctCrvMax_1pm; /*!< @description
	*	Maximum allowed center lane curvature to trigger curvature difference check \n\n
	*	\@asap_name: P_ABPLBP_StrDtctCrvMax_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_StrDtctCrvRSP_1pm; /*!< @description
	*	Straight detection curvature hysteresis (RSP) \n\n
	*	\@asap_name: P_ABPLBP_StrDtctCrvRSP_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_StrDtctLengthRatio_nu; /*!< @description
	*	Straight detection length ratio \n\n
	*	\@asap_name: P_ABPLBP_StrDtctLengthRatio_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_5_1em3_t	P_ABPLBP_StrDtctPreview_sec; /*!< @description
	*	Straight detection preview \n\n
	*	\@asap_name: P_ABPLBP_StrDtctPreview_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_StraightDiffThresh_met; /*!< @description
	*	Threshold for difference for the straight path estimation \n\n
	*	\@asap_name: P_ABPLBP_StraightDiffThresh_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ABPLBP_StraightScaleFct_nu; /*!< @description
	*	Scaling factor for curvature in case of a successful straight detection \n\n
	*	\@asap_name: P_ABPLBP_StraightScaleFct_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_TolRangeDistY_met; /*!< @description
	*	Tolerance for lane width after step in lateral position \n\n
	*	\@asap_name: P_ABPLBP_TolRangeDistY_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_TolRangeNewCorr_met; /*!< @description
	*	The corridor is considered new if the width changes more than this value \n\n
	*	\@asap_name: P_ABPLBP_TolRangeNewCorr_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_ABPLBP_TriggerDistDevThres_met; /*!< @description
	*	Lateral distance deviation threshold for uncoupled lane briding \n\n
	*	\@asap_name: P_ABPLBP_TriggerDistDevThres_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_UncoupDevReset_met; /*!< @description
	*	Uncoupled lane to coupled lane deviation for reset uncoupled lane bridging \n\n
	*	\@asap_name: P_ABPLBP_UncoupDevReset_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_UncoupLnBridCrvLSP_1pm; /*!< @description
	*	Uncoupled lane bridging curvature reset LSP (lower hysteresis) value \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnBridCrvLSP_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_UncoupLnBridCrvRSP_1pm; /*!< @description
	*	Uncoupled lane bridging curvature reset RSP (upper hysteresis) value \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnBridCrvRSP_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_Pers_m1000_0_1em4_t	P_ABPLBP_UncoupLnGradLimLD_1ps; /*!< @description
	*	Uncoupled lane stept detection gradient limiter (lower value) \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnGradLimLD_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: -1000 \n
	*	\@max: 0
	*/
	
	f32_Pers_0_10000_1em3_t	P_ABPLBP_UncoupLnGradLimLU_1ps; /*!< @description
	*	Uncoupled lane stept detection gradient limiter (upper value) \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnGradLimLU_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_UncoupLnStepCRtMax_1pm2; /*!< @description
	*	Uncoupled lane step detection curvature rate max \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepCRtMax_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPLBP_UncoupLnStepCRtMin_1pm2; /*!< @description
	*	Uncoupled lane step detection curvature rate min \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepCRtMin_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_UncoupLnStepCrvFactor_nu; /*!< @description
	*	the factor for curvature-dependent step detection \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepCrvFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_UncoupLnStepCrvMax_1pm; /*!< @description
	*	Uncoupled lane step detection curvature max \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepCrvMax_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPLBP_UncoupLnStepCrvMin_1pm; /*!< @description
	*	Uncoupled lane step detection curvature min \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepCrvMin_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ABPLBP_UncoupLnStepMaxVal_nu; /*!< @description
	*	Maximum uncoupled lane step detection threshold \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepMaxVal_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_UncoupLnStepPosYMax_met; /*!< @description
	*	Uncoupled lane step detection lateral position max \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepPosYMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ABPLBP_UncoupLnStepPosYMin_met; /*!< @description
	*	Uncoupled lane step detection lateral position min \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepPosYMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_UncoupLnStepYawMax_rad; /*!< @description
	*	Uncoupled lane step detection heading max \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepYawMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPLBP_UncoupLnStepYawMin_rad; /*!< @description
	*	Uncoupled lane step detection heading min \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnStepYawMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0p001_100_1em3_t	P_ABPLBP_UpDownHillPT1TConst_sec; /*!< @description
	*	Up/Downhill detection PT1 time constant \n\n
	*	\@asap_name: P_ABPLBP_UpDownHillPT1TConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.001 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPLBP_YawAngleGrad_radps; /*!< @description
	*	Yaw angle gradient \n\n
	*	\@asap_name: P_ABPLBP_YawAngleGrad_radps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPREP_CrvLimStepDtct_1pm; /*!< @description
	*	Curvature limit for the step detection \n\n
	*	\@asap_name: P_ABPREP_CrvLimStepDtct_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPREP_CrvRateLimStepDtct_1pm2; /*!< @description
	*	Threshold for step detection in lane marker curvature change \n\n
	*	\@asap_name: P_ABPREP_CrvRateLimStepDtct_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_10_1em3_t	P_ABPREP_DefaultRoadWidth_met; /*!< @description
	*	Default road width for virtual road edge building \n\n
	*	\@asap_name: P_ABPREP_DefaultRoadWidth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	P_ABPREP_DistYLimitStepDtct_met; /*!< @description
	*	Lateral postion limit for the step detection \n\n
	*	\@asap_name: P_ABPREP_DistYLimitStepDtct_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_5_1em3_t	P_ABPREP_DurValidCrvRateStep_sec; /*!< @description
	*	Indicates how long a step in the curvature rate is debounced \n\n
	*	\@asap_name: P_ABPREP_DurValidCrvRateStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_60_1em3_t	P_ABPREP_DurValidCrvStep_sec; /*!< @description
	*	Indicates how long a step in the curvature is debounced \n\n
	*	\@asap_name: P_ABPREP_DurValidCrvStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPREP_DurValidDistYStep_sec; /*!< @description
	*	Indicates how long a step in the lateral postition is stored \n\n
	*	\@asap_name: P_ABPREP_DurValidDistYStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ABPREP_DurValidHeadingStep_sec; /*!< @description
	*	Indicates how long a step in the heading angle is debounced \n\n
	*	\@asap_name: P_ABPREP_DurValidHeadingStep_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_ABPREP_HeadLimStepDtct_rad; /*!< @description
	*	Heading limit for the step detection \n\n
	*	\@asap_name: P_ABPREP_HeadLimStepDtct_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_10_1em3_t	P_ABPREP_Lane2ReDistThresh_met; /*!< @description
	*	Distance threshold between road edge and lanes for road edge stabilization with lane data \n\n
	*	\@asap_name: P_ABPREP_Lane2ReDistThresh_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPREP_LaneKFDecQualDeg_1ps; /*!< @description
	*	Quality decrease for the lane kalman filter after the degraded update step has been applied \n\n
	*	\@asap_name: P_ABPREP_LaneKFDecQualDeg_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPREP_LaneKFDecQualPred_1ps; /*!< @description
	*	Quality decrease for the lane kalman filter after only a prediction step has been applied \n\n
	*	\@asap_name: P_ABPREP_LaneKFDecQualPred_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0p0001_1_1em6_t	P_ABPREP_LaneKFDegradeWeight_nu; /*!< @description
	*	Weight for degraded update_laneKF \n\n
	*	\@asap_name: P_ABPREP_LaneKFDegradeWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0.0001 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_LaneKFDynCrvFactor_nu; /*!< @description
	*	Factor to control the curvature signal dynamics in lane center kalman filter \n\n
	*	\@asap_name: P_ABPREP_LaneKFDynCrvFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_LaneKFDynCrvRtFactor_nu; /*!< @description
	*	Factor to control the curvature signal dynamics in lane center kalman filter \n\n
	*	\@asap_name: P_ABPREP_LaneKFDynCrvRtFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_LaneKFDynDistYFact_nu; /*!< @description
	*	Factor needed to set the dynamic of the lateral distance within the prediction step; \n
	*	100000.0f High Dynamic, 10000.0f Middle Dynamic, <1000.0f Low Dynamic \n\n
	*	\@asap_name: P_ABPREP_LaneKFDynDistYFact_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_LaneKFDynYawFactor_nu; /*!< @description
	*	Factor needed to set the dynamic of the yaw angle within the prediction step \n\n
	*	\@asap_name: P_ABPREP_LaneKFDynYawFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_m_0_3p4E38_1em3_t	P_ABPREP_LaneKFErrCoeff1_met; /*!< @description
	*	Geometric model error (kappa2diff) calculation factor 1 - [minimum radius european highway] \n\n
	*	\@asap_name: P_ABPREP_LaneKFErrCoeff1_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 3.4E+38
	*/
	
	f32_mps_1_100_1em3_t	P_ABPREP_LaneKFErrCoeff2_mps; /*!< @description
	*	Geometric model error (kappa2diff) calculation factor 2 - [average ego vehicle velocity highway] \n\n
	*	\@asap_name: P_ABPREP_LaneKFErrCoeff2_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_Pers_1_10000_1em3_t	P_ABPREP_LaneKFIncQual_1ps; /*!< @description
	*	Quality increase for the lane kalman filter after the update step has been applied \n\n
	*	\@asap_name: P_ABPREP_LaneKFIncQual_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 1 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_1_100_1em3_t	P_ABPREP_LaneKFInitRFactor_nu; /*!< @description
	*	Initialization factor for R_laneKF matrix -> achieve better transient oscillation \n\n
	*	\@asap_name: P_ABPREP_LaneKFInitRFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ABPREP_LaneKFKGainFac_nu; /*!< @description
	*	Factor needed to set the dynamic of the lateral position within degraded update \n\n
	*	\@asap_name: P_ABPREP_LaneKFKGainFac_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPREP_LaneKFStdDevCrvRt_1pm2; /*!< @description
	*	Center lane curvature rate standard deviation \n\n
	*	\@asap_name: P_ABPREP_LaneKFStdDevCrvRt_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p5_1em3_t	P_ABPREP_LaneKFStdDevCrv_1pm; /*!< @description
	*	Center lane curvature standard deviation \n\n
	*	\@asap_name: P_ABPREP_LaneKFStdDevCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.5
	*/
	
	f32_m_0_5_1em3_t	P_ABPREP_LaneKFStdDevLatDist_met; /*!< @description
	*	Center lane lateral distance standard deviation \n\n
	*	\@asap_name: P_ABPREP_LaneKFStdDevLatDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_radps_0_1_1em3_t	P_ABPREP_LaneKFStdDevYawRt_radps; /*!< @description
	*	Center lane yaw rate standard deviation \n\n
	*	\@asap_name: P_ABPREP_LaneKFStdDevYawRt_radps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_rad_0_1_1em6_t	P_ABPREP_LaneKFStdDevYaw_rad; /*!< @description
	*	Center lane yaw angle standard deviation \n\n
	*	\@asap_name: P_ABPREP_LaneKFStdDevYaw_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t	P_ABPREP_LaneMaxCrv_1pm; /*!< @description
	*	Maximum curvature for lane bridging \n\n
	*	\@asap_name: P_ABPREP_LaneMaxCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_s_0p06_10_1em3_t	P_ABPREP_LatVelPT1TimeConst_sec; /*!< @description
	*	Lateral velocity PT1 time constant \n\n
	*	\@asap_name: P_ABPREP_LatVelPT1TimeConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_1pms2_0_0p1_1em7_t	P_ABPREP_MaxCrvChngGrad_1psm2; /*!< @description
	*	Gradient for the road edge curvature change \n\n
	*	\@asap_name: P_ABPREP_MaxCrvChngGrad_1psm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_0_5_1em7_t	P_ABPREP_MaxCrvGrad_1pms; /*!< @description
	*	Gradient for the road edge curvature \n\n
	*	\@asap_name: P_ABPREP_MaxCrvGrad_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPREP_MaxCrvRateRange_1pm2; /*!< @description
	*	Maximum range check value for curvature rate \n\n
	*	\@asap_name: P_ABPREP_MaxCrvRateRange_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPREP_MaxCurvatureRange_1pm; /*!< @description
	*	Maximum range check value for curvature \n\n
	*	\@asap_name: P_ABPREP_MaxCurvatureRange_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_10_1em3_t	P_ABPREP_MaxDistYGrad_mps; /*!< @description
	*	Gradient for the road edge distance \n\n
	*	\@asap_name: P_ABPREP_MaxDistYGrad_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ABPREP_MaxDistYRange_met; /*!< @description
	*	Maximum range check value for lateral position \n\n
	*	\@asap_name: P_ABPREP_MaxDistYRange_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_radps_0_1p5_1em6_t	P_ABPREP_MaxHeadingGrad_radps; /*!< @description
	*	Gradient for the road edge yaw angle \n\n
	*	\@asap_name: P_ABPREP_MaxHeadingGrad_radps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1.5
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPREP_MaxHeadingRange_rad; /*!< @description
	*	Maximum range check value for yaw angle \n\n
	*	\@asap_name: P_ABPREP_MaxHeadingRange_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_ABPREP_MaxLaneBridgingTime_sec; /*!< @description
	*	Maximum road edge bridging time \n\n
	*	\@asap_name: P_ABPREP_MaxLaneBridgingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_ABPREP_MaxLatDistStabilize_met; /*!< @description
	*	Maximum lateral distance for opposite lane stabilization \n\n
	*	\@asap_name: P_ABPREP_MaxLatDistStabilize_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ABPREP_MaxRangeHyst_nu; /*!< @description
	*	Maximum range check hysteresis factor \n\n
	*	\@asap_name: P_ABPREP_MaxRangeHyst_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_300_1em3_t	P_ABPREP_MaxValidLengthRange_met; /*!< @description
	*	Maximum range check value valid length \n\n
	*	\@asap_name: P_ABPREP_MaxValidLengthRange_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_10_1em3_t	P_ABPREP_MinLatDistStabilize_met; /*!< @description
	*	Minimum lateral distance for opposite lane stabilization \n\n
	*	\@asap_name: P_ABPREP_MinLatDistStabilize_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps_0_100_1em3_t	P_ABPREP_MinVelForKalmanFilt_mps; /*!< @description
	*	Minimum kalman filter input velocity to avoid internal matrix inversion failures \n\n
	*	\@asap_name: P_ABPREP_MinVelForKalmanFilt_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPREP_ReQualCrvMaxTh_1pm; /*!< @description
	*	Quality calculation maximum curvature step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualCrvMaxTh_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ABPREP_ReQualCrvMinTh_1pm; /*!< @description
	*	Quality calculation minimum curvature step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualCrvMinTh_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPREP_ReQualCrvRateMaxTh_1pm2; /*!< @description
	*	Quality calculation maximum curvature rate step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualCrvRateMaxTh_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_0_0p1_1em8_t	P_ABPREP_ReQualCrvRateMinTh_1pm2; /*!< @description
	*	Quality calculation minimum curvature rate step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualCrvRateMinTh_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualCrvRateWeight_nu; /*!< @description
	*	Quality calculation curvature rate penalty weighting factor \n\n
	*	\@asap_name: P_ABPREP_ReQualCrvRateWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualCrvWeight_nu; /*!< @description
	*	Quality calculation curvature penalty weighting factor \n\n
	*	\@asap_name: P_ABPREP_ReQualCrvWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_m_0_5_1em3_t	P_ABPREP_ReQualDistanceMaxTh_met; /*!< @description
	*	Quality calculation maximum distance step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualDistanceMaxTh_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_ABPREP_ReQualDistanceMinTh_met; /*!< @description
	*	Quality calculation maximum distance step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualDistanceMinTh_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualDistanceWeight_nu; /*!< @description
	*	Quality calculation lateral distance penalty weighting factor \n\n
	*	\@asap_name: P_ABPREP_ReQualDistanceWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	P_ABPREP_ReQualGradLimLD_nu; /*!< @description
	*	Quality calculation gradient limiter lower threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualGradLimLD_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualGradLimLU_nu; /*!< @description
	*	Quality calculation gradient limiter upper threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualGradLimLU_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPREP_ReQualHeadingMaxTh_rad; /*!< @description
	*	Quality calculation maximum heading step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualHeadingMaxTh_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ABPREP_ReQualHeadingMinTh_rad; /*!< @description
	*	Quality calculation minimum heading step threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualHeadingMinTh_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualHeadingWeight_nu; /*!< @description
	*	Quality calculation heading penalty weighting factor \n\n
	*	\@asap_name: P_ABPREP_ReQualHeadingWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualPenFactor_nu; /*!< @description
	*	Quality calculation penalty factor \n\n
	*	\@asap_name: P_ABPREP_ReQualPenFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	P_ABPREP_ReQualPenGradLimLD_nu; /*!< @description
	*	Quality calculation penalty gradient limiter lower threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualPenGradLimLD_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualPenGradLimLU_nu; /*!< @description
	*	Quality calculation penalty gradient limiter lower threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualPenGradLimLU_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ABPREP_ReQualPenHoldFactor_nu; /*!< @description
	*	Quality calculation penalty hold factor \n\n
	*	\@asap_name: P_ABPREP_ReQualPenHoldFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_mps_0_100_1em3_t	P_ABPREP_ReQualValidLength_met; /*!< @description
	*	Quality calculation lookahead distance threshold \n\n
	*	\@asap_name: P_ABPREP_ReQualValidLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_5_1em3_t	P_ABPREP_SIFJumpDebounceT_sec; /*!< @description
	*	Safety interface jump debounce time for yaw angle, lateral distance and curvature signals. \n\n
	*	\@asap_name: P_ABPREP_SIFJumpDebounceT_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_5_1em3_t	P_ABPREP_SIFLatencyTime_sec; /*!< @description
	*	Time contant for latency time compensation of lateral displacement \n\n
	*	\@asap_name: P_ABPREP_SIFLatencyTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0p06_10_1em3_t	P_ABPREP_SIFPT1TimeConst_sec; /*!< @description
	*	Time constant for lateral velocity lowpass filter \n\n
	*	\@asap_name: P_ABPREP_SIFPT1TimeConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclXHyst_mps2; /*!< @description
	*	Hysteresis of the longitudinal acceleration for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_AclXHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclXLDWHyst_mps2; /*!< @description
	*	Hysteresis of the longitudinal acceleration for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_AclXLDWHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclXLDWMax_mps2; /*!< @description
	*	Maximum allowed value of the longitudinal acceleration for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_AclXLDWMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclXLDWMin_mps2; /*!< @description
	*	Minimum allowed value of the longitudinal acceleration for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_AclXLDWMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclXMax_mps2; /*!< @description
	*	Maximum allowed value of the longitudinal acceleration for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_AclXMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclXMin_mps2; /*!< @description
	*	Minimum allowed value of the longitudinal acceleration for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_AclXMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclYHyst_mps2; /*!< @description
	*	Hysteresis of the lateral acceleration for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_AclYHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclYLDWHyst_mps2; /*!< @description
	*	Hysteresis of the lateral acceleration for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_AclYLDWHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclYLDWMax_mps2; /*!< @description
	*	Maximum allowed value of the lateral acceleration for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_AclYLDWMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLSIA_AclYMax_mps2; /*!< @description
	*	Maximum allowed value of the lateral acceleration for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_AclYMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_DPLSIA_CurveDetectThreshold_1pm; /*!< @description
	*	If the curvature is above this threshold, a curve is considered, else, a straight line. \n\n
	*	\@asap_name: P_DPLSIA_CurveDetectThreshold_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_HeadAngThresLDPHyst_rad; /*!< @description
	*	Hysteresis of the heading angle to the lane marking validation for LDP \n\n
	*	\@asap_name: P_DPLSIA_HeadAngThresLDPHyst_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_HeadAngThresLDPMax_rad; /*!< @description
	*	Maximal value of the heading angle to the lane marking validation for LDP \n\n
	*	\@asap_name: P_DPLSIA_HeadAngThresLDPMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_HeadAngThresLDPMin_rad; /*!< @description
	*	Minimal value of the heading angle to the lane marking validation for LDP \n\n
	*	\@asap_name: P_DPLSIA_HeadAngThresLDPMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_HeadAngThresLDWHyst_rad; /*!< @description
	*	Hysteresis of the heading angle to the lane marking validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_HeadAngThresLDWHyst_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_HeadAngThresLDWMax_rad; /*!< @description
	*	Maximal value of the heading angle to the lane marking validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_HeadAngThresLDWMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_HeadAngThresLDWMin_rad; /*!< @description
	*	Minimal value of the heading angle to the lane marking validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_HeadAngThresLDWMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_DPLSIA_LDPSpecificDebTime_sec[8]; /*!< @description
	*	Vector containing the turn off debounce times of the LDP Specific Qualifier. \n\n
	*	\@asap_name: P_DPLSIA_LDPSpecificDebTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthLDPHyst_met; /*!< @description
	*	Hysteresis of the lane width validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthLDPHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthLDPMax_met; /*!< @description
	*	Maximum allowed value of the lane width validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthLDPMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthLDPMin_met; /*!< @description
	*	Minimum allowed value of the lane width validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthLDPMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthLDWHyst_met; /*!< @description
	*	Hysteresis of the lane width validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthLDWHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthLDWMax_met; /*!< @description
	*	Maximum allowed value of the lane width validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthLDWMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthLDWMin_met; /*!< @description
	*	Minimum allowed value of the lane width validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthLDWMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLSIA_LaneWidthWideLnDef_met; /*!< @description
	*	New calculated Lane Width Default value. Used if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthWideLnDef_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_DPLSIA_LnBndTurnOnTime_sec; /*!< @description
	*	Turn on delay time for the lane marking validity flags. \n\n
	*	\@asap_name: P_DPLSIA_LnBndTurnOnTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_degps_m360_360_1em3_t	P_DPLSIA_StrWhlAngSpLDPHys_degps; /*!< @description
	*	Hysteresis of the steering wheel angle rate validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngSpLDPHys_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_degps_m360_360_1em3_t	P_DPLSIA_StrWhlAngSpLDPMax_degps; /*!< @description
	*	Maximum allowed value of the steering wheel angle rate validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngSpLDPMax_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_degps_m360_360_1em3_t	P_DPLSIA_StrWhlAngSpLDWHys_degps; /*!< @description
	*	Hysteresis of the steering wheel angle rate validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngSpLDWHys_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_degps_m360_360_1em3_t	P_DPLSIA_StrWhlAngSpLDWMax_degps; /*!< @description
	*	Maximum allowed value of the steering wheel angle rate validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngSpLDWMax_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_deg_m720_720_1em3_t	P_DPLSIA_StrWhlAngleLDPHyst_deg; /*!< @description
	*	Hysteresis of the steering wheel angle validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngleLDPHyst_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t	P_DPLSIA_StrWhlAngleLDPMax_deg; /*!< @description
	*	Maximum allowed value of the steering wheel angle validation for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngleLDPMax_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t	P_DPLSIA_StrWhlAngleLDWHyst_deg; /*!< @description
	*	Hysteresis of the steering wheel angle validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngleLDWHyst_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t	P_DPLSIA_StrWhlAngleLDWMax_deg; /*!< @description
	*	Maximum allowed value of the steering wheel angle validation for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_StrWhlAngleLDWMax_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSIA_TlcHeadAngThres_rad; /*!< @description
	*	For the Tlc Criterium to be fulfilled, the heading angle between the lane marking and the vehicle has to be under a certain threshold. (The vehicle shall be oriented towards the lane marking). \n\n
	*	\@asap_name: P_DPLSIA_TlcHeadAngThres_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_DPLSIA_TurnSignHoldingTime_sec; /*!< @description
	*	Holding time of the turn indicator signals. \n\n
	*	\@asap_name: P_DPLSIA_TurnSignHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_kph_0_300_1em3_t	P_DPLSIA_VelDispLDPHyst_kph; /*!< @description
	*	Hysteresis of the displayed longitudinal velocity for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_VelDispLDPHyst_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPLSIA_VelDispLDPMax_kph; /*!< @description
	*	Maximum allowed value of the displayed longitudinal velocity for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_VelDispLDPMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPLSIA_VelDispLDPMin_kph; /*!< @description
	*	Minimum allowed value of the displayed longitudinal velocity for the LDP. \n\n
	*	\@asap_name: P_DPLSIA_VelDispLDPMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPLSIA_VelDispLDWHyst_kph; /*!< @description
	*	Hysteresis of the displayed longitudinal velocity for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_VelDispLDWHyst_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPLSIA_VelDispLDWMax_kph; /*!< @description
	*	Maximum allowed value of the displayed longitudinal velocity for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_VelDispLDWMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPLSIA_VelDispLDWMin_kph; /*!< @description
	*	Minimum allowed value of the displayed longitudinal velocity for the LDW. \n\n
	*	\@asap_name: P_DPLSIA_VelDispLDWMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSIA_VelLatThresLDPHyst_mps; /*!< @description
	*	Hysteresis of the displayed longitudinal velocity for the LDP \n\n
	*	\@asap_name: P_DPLSIA_VelLatThresLDPHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSIA_VelLatThresLDPMax_mps; /*!< @description
	*	Maximum allowed value of the displayed longitudinal velocity for the LDP \n\n
	*	\@asap_name: P_DPLSIA_VelLatThresLDPMax_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSIA_VelLatThresLDPMin_mps; /*!< @description
	*	Minimum allowed value of the displayed longitudinal velocity for the LDP \n\n
	*	\@asap_name: P_DPLSIA_VelLatThresLDPMin_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSIA_VelLatThresLDWHyst_mps; /*!< @description
	*	Hysteresis of the displayed longitudinal velocity for the LDW \n\n
	*	\@asap_name: P_DPLSIA_VelLatThresLDWHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSIA_VelLatThresLDWMax_mps; /*!< @description
	*	Maximum allowed value of the displayed longitudinal velocity for the LDW \n\n
	*	\@asap_name: P_DPLSIA_VelLatThresLDWMax_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSIA_VelLatThresLDWMin_mps; /*!< @description
	*	Minimum allowed value of the displayed longitudinal velocity for the LDW \n\n
	*	\@asap_name: P_DPLSIA_VelLatThresLDWMin_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_BlockingTimeDuration_sec; /*!< @description
	*	Duration of the blocking time between two LDP lateral interventions. \n\n
	*	\@asap_name: P_DPLSMI_BlockingTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_DegrTimeOut_sec; /*!< @description
	*	Time out parameter for the degradation watch dog timer. \n\n
	*	\@asap_name: P_DPLSMI_DegrTimeOut_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_DlcLimitMax_met; /*!< @description
	*	Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
	*	\@asap_name: P_DPLSMI_DlcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_DlcLimitMin_met; /*!< @description
	*	Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
	*	\@asap_name: P_DPLSMI_DlcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_HazardCancelTol_met; /*!< @description
	*	When DLC is bigger than this tolerance across the lane marking the intervention is cancelled. \n\n
	*	\@asap_name: P_DPLSMI_HazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_HazardFinishDlc_met; /*!< @description
	*	Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_HazardFinishDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSMI_HazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_HazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSMI_HazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_HazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_NoHazardCancelDlc_met; /*!< @description
	*	When DLC is apart from the lane marking a distance bigger than this tolerance in the opposite direction of the dangerous situation the intervention is cancelled. \n\n
	*	\@asap_name: P_DPLSMI_NoHazardCancelDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_NoHazardCancelTol_met; /*!< @description
	*	When DLC is apart from the target a distance bigger than this tolerance in the opposite direction of the dangerous situation the intervention is cancelled. \n\n
	*	\@asap_name: P_DPLSMI_NoHazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_NoHazardFinishDlc_met; /*!< @description
	*	Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_NoHazardFinishDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSMI_NoHazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading angle has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the oppposite directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_NoHazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSMI_NoHazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the oppposite directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_NoHazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_OnTargetFinishTime_sec; /*!< @description
	*	Time for which all the finish conditions have to be fulfilled in order to consider an intervention finished. \n\n
	*	\@asap_name: P_DPLSMI_OnTargetFinishTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_RequestTimeOut_sec; /*!< @description
	*	Maximal time that the LDP can be in state REQUEST. \n\n
	*	\@asap_name: P_DPLSMI_RequestTimeOut_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_SafeSituationDelay_sec; /*!< @description
	*	Turn on delay time for the safe situation condition. \n\n
	*	\@asap_name: P_DPLSMI_SafeSituationDelay_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_SafeSituationOffset_met; /*!< @description
	*	To avoid two lateral interventions with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
	*	\@asap_name: P_DPLSMI_SafeSituationOffset_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMI_TlcDistanceMin_met; /*!< @description
	*	Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
	*	\@asap_name: P_DPLSMI_TlcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_TlcValidMinTime_sec; /*!< @description
	*	Minimum time that the TLC criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_DPLSMI_TlcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMI_TriggerHoldingTime_sec; /*!< @description
	*	Holding time when the trigger threshold was exceeded. \n\n
	*	\@asap_name: P_DPLSMI_TriggerHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_AbortDegrDuration_sec; /*!< @description
	*	Degradation time due to an abort condition. \n\n
	*	\@asap_name: P_DPLSMW_AbortDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_BlockingTimeDuration_sec; /*!< @description
	*	Duration of the blocking time between two LDW warnings. \n\n
	*	\@asap_name: P_DPLSMW_BlockingTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_CancelDegrDuration_sec; /*!< @description
	*	Degradation time due to a cancel condition. \n\n
	*	\@asap_name: P_DPLSMW_CancelDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_DlcLimitMax_met; /*!< @description
	*	Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
	*	\@asap_name: P_DPLSMW_DlcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_DlcLimitMin_met; /*!< @description
	*	Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
	*	\@asap_name: P_DPLSMW_DlcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_FinishDegrDuration_sec; /*!< @description
	*	Degradation time due to a finish condition. \n\n
	*	\@asap_name: P_DPLSMW_FinishDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_FinishMinDuration_sec; /*!< @description
	*	Finish Condition. The function shall have been at least this time controlling to be able to finish. \n\n
	*	\@asap_name: P_DPLSMW_FinishMinDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_HazardCancelTol_met; /*!< @description
	*	When DLC is bigger than this tolerance across the lane marking the warning is cancelled. \n\n
	*	\@asap_name: P_DPLSMW_HazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSMW_HazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMW_HazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSMW_HazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMW_HazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_NoHazardCancelTol_met; /*!< @description
	*	When DLC is apart from the target a distance bigger than this tolerance in the opposite direction of the dangerous situation the warning is cancelled. \n\n
	*	\@asap_name: P_DPLSMW_NoHazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPLSMW_NoHazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the opposite directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMW_NoHazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPLSMW_NoHazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the opposite directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPLSMW_NoHazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_OnTargetFinishTime_sec; /*!< @description
	*	Time for which all the finish conditions have to be fulfilled in order to consider a warning finished. \n\n
	*	\@asap_name: P_DPLSMW_OnTargetFinishTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_SafeSituationDelay_sec; /*!< @description
	*	Turn on delay time for the safe situation condition. \n\n
	*	\@asap_name: P_DPLSMW_SafeSituationDelay_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_SafeSituationOffset_met; /*!< @description
	*	To avoid two warnings with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
	*	\@asap_name: P_DPLSMW_SafeSituationOffset_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_StrgRdyDegrDuration_sec; /*!< @description
	*	Degradation time due to an strong ready condition. \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_TgtTrajPosY0_met; /*!< @description
	*	Expected end position of the vehicle if the driver reacts to the LDW. \n\n
	*	\@asap_name: P_DPLSMW_TgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLSMW_TlcDistanceMin_met; /*!< @description
	*	Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
	*	\@asap_name: P_DPLSMW_TlcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_TlcValidMinTime_sec; /*!< @description
	*	Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_DPLSMW_TlcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLSMW_TriggerHoldingTime_sec; /*!< @description
	*	Holding time when the trigger threshold was exceeded. \n\n
	*	\@asap_name: P_DPLSMW_TriggerHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPLTTG_TgtMaxDistance_met; /*!< @description
	*	Maximal allowed distance between the hazardous lane marking and the planned target. \n\n
	*	\@asap_name: P_DPLTTG_TgtMaxDistance_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPLTTG_TgtMaxLatDev_met; /*!< @description
	*	Maximal allowed distance between the middle of the vehicle and the planned target. \n\n
	*	\@asap_name: P_DPLTTG_TgtMaxLatDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPLTTG_TgtTrjPT1TimeConst_sec; /*!< @description
	*	 \n\n
	*	\@asap_name: P_DPLTTG_TgtTrjPT1TimeConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_DPLTVG_DistYTolLeTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_DistYTolLeTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPLTVG_DistYTolRiTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_DistYTolRiTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLTVG_FTireAclMax_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_FTireAclMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPLTVG_FTireAclMin_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_FTireAclMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_1pms_0_5_1em7_t	P_DPLTVG_LimiterMaxCrvGrd_1pms; /*!< @description
	*	Maximal limiter curvature gradient allowed. \n\n
	*	\@asap_name: P_DPLTVG_LimiterMaxCrvGrd_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_1pm_0_50_1em8_t	P_DPLTVG_LimiterMaxCrv_1pm; /*!< @description
	*	Maximal limiter curvature allowed. \n\n
	*	\@asap_name: P_DPLTVG_LimiterMaxCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_s_0_60_1em3_t	P_DPLTVG_LimiterTimeDuration_sec; /*!< @description
	*	Duration of the target curvature imit in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
	*	\@asap_name: P_DPLTVG_LimiterTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps3_0_50_1em3_t	P_DPLTVG_MaxJerkAllowed_mps3; /*!< @description
	*	Maximum Jerk Allowed in the trajectory planning \n\n
	*	\@asap_name: P_DPLTVG_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_NoUnit_0_100_1em3_t	P_DPLTVG_MaxTrqScalLimit_nu; /*!< @description
	*	Maximum Torque Scaling Gradient maximum value \n\n
	*	\@asap_name: P_DPLTVG_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_MaxTrqScalRampInGrd_1ps; /*!< @description
	*	Maximum Torque Scaling ramp in gradient \n\n
	*	\@asap_name: P_DPLTVG_MaxTrqScalRampInGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_MaxTrqScalRampOutGrd_1ps; /*!< @description
	*	Maximum Torque Scaling ramp out gradient \n\n
	*	\@asap_name: P_DPLTVG_MaxTrqScalRampOutGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_s_0_60_1em3_t	P_DPLTVG_PredTimeCrv_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_PredTimeCrv_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPLTVG_PredTimeHeadAng_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_StrWhStifAbortROGrd_1ps; /*!< @description
	*	Steering Wheel Stiffness Abort Ramp Out Gradient \n\n
	*	\@asap_name: P_DPLTVG_StrWhStifAbortROGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_DPLTVG_StrWhStifLimit_nu; /*!< @description
	*	Steering Wheel Stiffness Limit \n\n
	*	\@asap_name: P_DPLTVG_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_StrWhStifROGrad_1ps; /*!< @description
	*	Steering Wheel Stiffness Standard Ramp Out Gradient \n\n
	*	\@asap_name: P_DPLTVG_StrWhStifROGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_TrqAbortROGrd_1ps; /*!< @description
	*	Torque Ramp Out Abort Gradient \n\n
	*	\@asap_name: P_DPLTVG_TrqAbortROGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_TrqRampInGrad_1ps; /*!< @description
	*	Torque Standard Ramp In Gradient \n\n
	*	\@asap_name: P_DPLTVG_TrqRampInGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPLTVG_TrqRampOutGrad_1ps; /*!< @description
	*	Torque Standard Ramp Out Gradient \n\n
	*	\@asap_name: P_DPLTVG_TrqRampOutGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_m100_100_1em3_t	P_DPLTVG_WeightTgtDistY_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRSIA_AclXHyst_mps2; /*!< @description
	*	Hysteresis of the longitudinal acceleration for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_AclXHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRSIA_AclXMax_mps2; /*!< @description
	*	Maximum allowed value of the longitudinal acceleration for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_AclXMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRSIA_AclXMin_mps2; /*!< @description
	*	Minimum allowed value of the longitudinal acceleration for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_AclXMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRSIA_AclYHyst_mps2; /*!< @description
	*	Hysteresis of the lateral acceleration for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_AclYHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRSIA_AclYMax_mps2; /*!< @description
	*	Maximum allowed value of the lateral acceleration for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_AclYMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_ConstrSiteLnTurnOff_sec; /*!< @description
	*	Construction Site turn off delay for the lane marking validity. \n\n
	*	\@asap_name: P_DPRSIA_ConstrSiteLnTurnOff_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_ConstrSiteLnTurnOn_sec; /*!< @description
	*	Construction Site turn on delay for the lane marking validity. \n\n
	*	\@asap_name: P_DPRSIA_ConstrSiteLnTurnOn_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_ConstrSiteReTurnOff_sec; /*!< @description
	*	Construction Site turn off delay for the road edge validity. \n\n
	*	\@asap_name: P_DPRSIA_ConstrSiteReTurnOff_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_ConstrSiteReTurnOn_sec; /*!< @description
	*	Construction Site turn on delay for the road edge validity. \n\n
	*	\@asap_name: P_DPRSIA_ConstrSiteReTurnOn_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_ExitRampTurnOff_sec; /*!< @description
	*	Turn off time for the exit ramp. \n\n
	*	\@asap_name: P_DPRSIA_ExitRampTurnOff_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_ExitRampTurnOn_sec; /*!< @description
	*	Turn on time for the exit ramp. \n\n
	*	\@asap_name: P_DPRSIA_ExitRampTurnOn_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LaneWidthHyst_met; /*!< @description
	*	Hysteresis of the lane width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LaneWidthMax_met; /*!< @description
	*	Maximum allowed value of the lane width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LaneWidthMin_met; /*!< @description
	*	Minimum allowed value of the lane width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LaneWidthWideLnDef_met; /*!< @description
	*	New calculated Lane Width Default value. Used if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthWideLnDef_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_LnBndTurnOnTime_sec; /*!< @description
	*	Turn on delay time for the lane marking validity flags. \n\n
	*	\@asap_name: P_DPRSIA_LnBndTurnOnTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_LnHeadAngThresHyst_rad; /*!< @description
	*	Hysteresis of the heading angle to the lane marking validation. \n\n
	*	\@asap_name: P_DPRSIA_LnHeadAngThresHyst_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_LnHeadAngThresMax_rad; /*!< @description
	*	Maximal value of the heading angle to the lane marking validation. \n\n
	*	\@asap_name: P_DPRSIA_LnHeadAngThresMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_LnHeadAngThresMin_rad; /*!< @description
	*	Minimal value of the heading angle to the lane marking validation. \n\n
	*	\@asap_name: P_DPRSIA_LnHeadAngThresMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LnRdWidthHyst_met; /*!< @description
	*	Hysteresis of the lane/road width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LnRdWidthHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LnRdWidthMax_met; /*!< @description
	*	Maximum allowed value of the lane/road width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LnRdWidthMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_LnRdWidthMin_met; /*!< @description
	*	Minimum allowed value of the lane/road width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LnRdWidthMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_RDPSpecificDebTime_sec[8]; /*!< @description
	*	Vector containing the turn off debounce times of the RDP Specific Qualifier. \n\n
	*	\@asap_name: P_DPRSIA_RDPSpecificDebTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_RdBndTurnOnTime_sec; /*!< @description
	*	Turn on delay time for the road edge validity flags. \n\n
	*	\@asap_name: P_DPRSIA_RdBndTurnOnTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_ReHeadAngThresHyst_rad; /*!< @description
	*	Hysteresis of the heading angle to the road edge validation. \n\n
	*	\@asap_name: P_DPRSIA_ReHeadAngThresHyst_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_ReHeadAngThresMax_rad; /*!< @description
	*	Maximal value of the heading angle to the road edge validation. \n\n
	*	\@asap_name: P_DPRSIA_ReHeadAngThresMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_ReHeadAngThresMin_rad; /*!< @description
	*	Minimal value of the heading angle to the road edge validation. \n\n
	*	\@asap_name: P_DPRSIA_ReHeadAngThresMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSIA_RoadWidthHyst_met; /*!< @description
	*	Hysteresis of the road width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_RoadWidthHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_RoadWidthMax_met; /*!< @description
	*	Maximum allowed value of the road width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_RoadWidthMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRSIA_RoadWidthMin_met; /*!< @description
	*	Minimum allowed value of the road width validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_RoadWidthMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_degps_m360_360_1em3_t	P_DPRSIA_StrWhlAngSpeedHyst_degps; /*!< @description
	*	Hysteresis of the steering wheel angle rate validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_StrWhlAngSpeedHyst_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_degps_m360_360_1em3_t	P_DPRSIA_StrWhlAngSpeedMax_degps; /*!< @description
	*	Maximum allowed value of the steering wheel angle rate validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_StrWhlAngSpeedMax_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_deg_m720_720_1em3_t	P_DPRSIA_StrWhlAngleHyst_deg; /*!< @description
	*	Hysteresis of the steering wheel angle validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_StrWhlAngleHyst_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t	P_DPRSIA_StrWhlAngleMax_deg; /*!< @description
	*	Maximum allowed value of the steering wheel angle validation for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_StrWhlAngleMax_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_TlcHeadAngThres_rad; /*!< @description
	*	For the Tlc Criterium to be fulfilled, the heading angle between the lane marking and the vehicle has to be under a certain threshold. \n\n
	*	\@asap_name: P_DPRSIA_TlcHeadAngThres_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSIA_TrcHeadAngThres_rad; /*!< @description
	*	For the Trc Criterium to be fulfilled, the heading angle between the road edge and the vehicle has to be under a certain threshold. \n\n
	*	\@asap_name: P_DPRSIA_TrcHeadAngThres_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_DPRSIA_TurnSignHoldingTime_sec; /*!< @description
	*	Holding time of the turn signals. \n\n
	*	\@asap_name: P_DPRSIA_TurnSignHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSIA_VelLatThresHyst_mps; /*!< @description
	*	Hysteresis of the lateral velocity for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_VelLatThresHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSIA_VelLatThresMax_mps; /*!< @description
	*	Maximum allowed value of the lateral  velocity for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_VelLatThresMax_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSIA_VelLatThresMin_mps; /*!< @description
	*	Minimum allowed value of the lateral velocity for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_VelLatThresMin_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_kph_0_300_1em3_t	P_DPRSIA_VelVehDispHyst_kph; /*!< @description
	*	Hysteresis of the displayed longitudinal velocity for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_VelVehDispHyst_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPRSIA_VelVehDispMax_kph; /*!< @description
	*	Maximum allowed value of the displayed longitudinal velocity for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_VelVehDispMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_DPRSIA_VelVehDispMin_kph; /*!< @description
	*	Minimum allowed value of the displayed longitudinal velocity for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_VelVehDispMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_BlockingTimeDuration_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_BlockingTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_DPRSMI_CurveDetectThreshold_1pm; /*!< @description
	*	If the curvature is above this threshold, a curve is considered, else, a straight line. \n\n
	*	\@asap_name: P_DPRSMI_CurveDetectThreshold_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_DegrTimeOut_sec; /*!< @description
	*	Time out parameter for the degradation watch dog timer. \n\n
	*	\@asap_name: P_DPRSMI_DegrTimeOut_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_DlcLimitMax_met; /*!< @description
	*	Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
	*	\@asap_name: P_DPRSMI_DlcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_DlcLimitMin_met; /*!< @description
	*	Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
	*	\@asap_name: P_DPRSMI_DlcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_DrcLimitMax_met; /*!< @description
	*	Maximum allowed value of the DRC to trigger. If DRC is bigger than this value, even if the DRC is smaller than the threshold, the function shall not trigger. \n\n
	*	\@asap_name: P_DPRSMI_DrcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_DrcLimitMin_met; /*!< @description
	*	Minimum allowed value of the DRC to trigger. If DRC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
	*	\@asap_name: P_DPRSMI_DrcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_HazardCancelTol_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_HazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_HazardFinishDlc_met; /*!< @description
	*	Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_HazardFinishDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSMI_HazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_HazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSMI_HazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_HazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_LnMrkRdEdgeDistMax_met; /*!< @description
	*	Maximal allowed distance between a lane marking and a road edge to trigger. \n\n
	*	\@asap_name: P_DPRSMI_LnMrkRdEdgeDistMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_LnMrkRdEdgeDistMin_met; /*!< @description
	*	Minimal allowed distance between a lane marking and a road edge to trigger. \n\n
	*	\@asap_name: P_DPRSMI_LnMrkRdEdgeDistMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_DPRSMI_LnOverlapCrv_1pm; /*!< @description
	*	Maximum curvature of a boundary when a road edge and a lane marking overlap. \n\n
	*	\@asap_name: P_DPRSMI_LnOverlapCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_LnOverlapInnerDist_met; /*!< @description
	*	Maximal allowed distance between the road edge and the lane marking when the road edge is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
	*	\@asap_name: P_DPRSMI_LnOverlapInnerDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_LnOverlapOuterDist_met; /*!< @description
	*	Maximal allowed distance between the road edge and the lane marking when the lane marking is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
	*	\@asap_name: P_DPRSMI_LnOverlapOuterDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_NoHazardCancelDlc_met; /*!< @description
	*	When DLC/DRC is apart from the lane marking a distance bigger than this tolerance in the opposite direction of the dangerous situation the intervention is cancelled. \n\n
	*	\@asap_name: P_DPRSMI_NoHazardCancelDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_NoHazardCancelTol_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_NoHazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_NoHazardFinishDlc_met; /*!< @description
	*	Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_NoHazardFinishDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSMI_NoHazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_NoHazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSMI_NoHazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_NoHazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_OnTargetFinishTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_OnTargetFinishTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_RequestTimeOut_sec; /*!< @description
	*	Maximal allowed time for the RDP to be in state REQUEST \n\n
	*	\@asap_name: P_DPRSMI_RequestTimeOut_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_SafeSitDelayLn_sec; /*!< @description
	*	Turn on delay time for the lane marking safe situation condition. \n\n
	*	\@asap_name: P_DPRSMI_SafeSitDelayLn_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_SafeSitDelayRe_sec; /*!< @description
	*	Turn on delay time for the road edge safe situation condition. \n\n
	*	\@asap_name: P_DPRSMI_SafeSitDelayRe_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_SafeSitOffsetLn_met; /*!< @description
	*	To avoid two lateral interventions with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
	*	\@asap_name: P_DPRSMI_SafeSitOffsetLn_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_SafeSitOffsetRe_met; /*!< @description
	*	To avoid two lateral interventions with the same dangerous situation, the DRC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
	*	\@asap_name: P_DPRSMI_SafeSitOffsetRe_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_TlcDistanceMin_met; /*!< @description
	*	Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
	*	\@asap_name: P_DPRSMI_TlcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_TlcValidMinTime_sec; /*!< @description
	*	Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_DPRSMI_TlcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMI_TrcDistanceMin_met; /*!< @description
	*	Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TRC Criterium is fulfilled. \n\n
	*	\@asap_name: P_DPRSMI_TrcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_TrcValidMinTime_sec; /*!< @description
	*	Minimum time that the trc criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_DPRSMI_TrcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMI_TriggerHoldingTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_TriggerHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_AbortDegrDuration_sec; /*!< @description
	*	Degradation time due to an abort condition. \n\n
	*	\@asap_name: P_DPRSMW_AbortDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_BlockingTimeDuration_sec; /*!< @description
	*	Duration of the blocking time between two RDW warnings. \n\n
	*	\@asap_name: P_DPRSMW_BlockingTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_CancelDegrDuration_sec; /*!< @description
	*	Degradation time due to a cancel condition. \n\n
	*	\@asap_name: P_DPRSMW_CancelDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_DlcLimitMax_met; /*!< @description
	*	Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
	*	\@asap_name: P_DPRSMW_DlcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_DlcLimitMin_met; /*!< @description
	*	Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
	*	\@asap_name: P_DPRSMW_DlcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_DrcLimitMax_met; /*!< @description
	*	Maximum allowed value of the DRC to trigger. If DRC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
	*	\@asap_name: P_DPRSMW_DrcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_DrcLimitMin_met; /*!< @description
	*	Minimum allowed value of the DRC to trigger. If DRC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
	*	\@asap_name: P_DPRSMW_DrcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_FinishDegrDuration_sec; /*!< @description
	*	Degradation time due to a finish condition. \n\n
	*	\@asap_name: P_DPRSMW_FinishDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_FinishMinDuration_sec; /*!< @description
	*	Finish Condition. The function shall have been at least this time controlling to be able to finish. \n\n
	*	\@asap_name: P_DPRSMW_FinishMinDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_HazardCancelTol_met; /*!< @description
	*	When DRC is bigger than this tolerance across the road marking the warning is cancelled. \n\n
	*	\@asap_name: P_DPRSMW_HazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSMW_HazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMW_HazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSMW_HazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMW_HazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_LnMrkRdEdgeDistMax_met; /*!< @description
	*	Maximal allowed distance between a lane marking and a road edge to trigger. \n\n
	*	\@asap_name: P_DPRSMW_LnMrkRdEdgeDistMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_LnMrkRdEdgeDistMin_met; /*!< @description
	*	Minimal allowed distance between a lane marking and a road edge to trigger. \n\n
	*	\@asap_name: P_DPRSMW_LnMrkRdEdgeDistMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_DPRSMW_LnOverlapCrv_1pm; /*!< @description
	*	Maximum curvature of a boundary when a road edge and a lane marking overlap. \n\n
	*	\@asap_name: P_DPRSMW_LnOverlapCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_LnOverlapInnerDist_met; /*!< @description
	*	Maximal allowed distance between the road edge and the lane marking when the road edge is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
	*	\@asap_name: P_DPRSMW_LnOverlapInnerDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_LnOverlapOuterDist_met; /*!< @description
	*	Maximal allowed distance between the road edge and the lane marking when the lane marking is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
	*	\@asap_name: P_DPRSMW_LnOverlapOuterDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_NoHazardCancelTol_met; /*!< @description
	*	When DRC is apart from the target a distance bigger than this tolerance in the opposite direction of the dangerous situation the warning is cancelled. \n\n
	*	\@asap_name: P_DPRSMW_NoHazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_DPRSMW_NoHazardFinishHeadAng_rad; /*!< @description
	*	Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMW_NoHazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_mps_m20_20_1em3_t	P_DPRSMW_NoHazardFinishVelLat_mps; /*!< @description
	*	Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
	*	\@asap_name: P_DPRSMW_NoHazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_OnTargetFinishTime_sec; /*!< @description
	*	Time for which all the finish conditions have to be fulfilled in order to consider a warning finished. \n\n
	*	\@asap_name: P_DPRSMW_OnTargetFinishTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_SafeSitDelayLn_sec; /*!< @description
	*	Turn on delay time for the lane marking safe situation condition. \n\n
	*	\@asap_name: P_DPRSMW_SafeSitDelayLn_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_SafeSitDelayRe_sec; /*!< @description
	*	Turn on delay time for the road edge safe situation condition. \n\n
	*	\@asap_name: P_DPRSMW_SafeSitDelayRe_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_SafeSitOffsetLn_met; /*!< @description
	*	To avoid two lateral interventions with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
	*	\@asap_name: P_DPRSMW_SafeSitOffsetLn_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_SafeSitOffsetRe_met; /*!< @description
	*	To avoid two lateral interventions with the same dangerous situation, the DRC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
	*	\@asap_name: P_DPRSMW_SafeSitOffsetRe_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_StrgRdyDegrDuration_sec; /*!< @description
	*	Degradation time due to an strong ready condition. \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyDegrDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_TgtTrajPosY0_met; /*!< @description
	*	Expected end position of the vehicle if the driver reacts to the RDW. \n\n
	*	\@asap_name: P_DPRSMW_TgtTrajPosY0_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_TlcDistanceMin_met; /*!< @description
	*	Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
	*	\@asap_name: P_DPRSMW_TlcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_TlcValidMinTime_sec; /*!< @description
	*	Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_DPRSMW_TlcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRSMW_TrcDistanceMin_met; /*!< @description
	*	Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TRC Criterium is fulfilled. \n\n
	*	\@asap_name: P_DPRSMW_TrcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_TrcValidMinTime_sec; /*!< @description
	*	Minimum time that the trc criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_DPRSMW_TrcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRSMW_TriggerHoldingTime_sec; /*!< @description
	*	Holding time when the trigger threshold was exceeded. \n\n
	*	\@asap_name: P_DPRSMW_TriggerHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_DPRTTG_TargetLatDistLn_met; /*!< @description
	*	Target when a lane marking is available next to the road edge. \n\n
	*	\@asap_name: P_DPRTTG_TargetLatDistLn_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRTTG_TargetLatDistRe_met; /*!< @description
	*	Target when no lane marking is available next to the road edge. \n\n
	*	\@asap_name: P_DPRTTG_TargetLatDistRe_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRTTG_TgtMaxDistanceLn_met; /*!< @description
	*	Maximal allowed distance between the hazardous lane marking and the planned target. \n\n
	*	\@asap_name: P_DPRTTG_TgtMaxDistanceLn_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRTTG_TgtMaxDistanceRe_met; /*!< @description
	*	Maximal allowed distance between the hazardous road edge and the planned target. \n\n
	*	\@asap_name: P_DPRTTG_TgtMaxDistanceRe_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRTTG_TgtMaxLatDevLn_met; /*!< @description
	*	Maximal allowed distance between the middle of the vehicle and the planned target for a road edge + lane marking situation. \n\n
	*	\@asap_name: P_DPRTTG_TgtMaxLatDevLn_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_DPRTTG_TgtMaxLatDevRe_met; /*!< @description
	*	Maximal allowed distance between the middle of the vehicle and the planned target for a road edge only situation. \n\n
	*	\@asap_name: P_DPRTTG_TgtMaxLatDevRe_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_DPRTTG_TgtTrjPT1TimeConst_sec; /*!< @description
	*	Time constant for the PT1 output filter \n\n
	*	\@asap_name: P_DPRTTG_TgtTrjPT1TimeConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_DPRTVG_DistYTolLeTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_DistYTolLeTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_DPRTVG_DistYTolRiTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_DistYTolRiTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRTVG_FTireAccelMax_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_FTireAccelMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_DPRTVG_FTireAccelMin_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_FTireAccelMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_1pms_0_5_1em7_t	P_DPRTVG_LimiterMaxCrvGrd_1pms; /*!< @description
	*	Maximal limiter curvature gradient allowed. \n\n
	*	\@asap_name: P_DPRTVG_LimiterMaxCrvGrd_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_1pm_0_50_1em8_t	P_DPRTVG_LimiterMaxCrv_1pm; /*!< @description
	*	Maximal limiter curvature allowed. \n\n
	*	\@asap_name: P_DPRTVG_LimiterMaxCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_s_0_60_1em3_t	P_DPRTVG_LimiterTimeDuration_sec; /*!< @description
	*	Duration of the target curvature imit in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
	*	\@asap_name: P_DPRTVG_LimiterTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps3_0_50_1em3_t	P_DPRTVG_MaxJerkAllowed_mps3; /*!< @description
	*	Maximum Jerk Allowed in the trajectory planning \n\n
	*	\@asap_name: P_DPRTVG_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_NoUnit_0_100_1em3_t	P_DPRTVG_MaxTrqScalLimit_nu; /*!< @description
	*	Maximum Torque Scaling Limiter (Torque saturation) \n\n
	*	\@asap_name: P_DPRTVG_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_MaxTrqScalRampInGrd_1ps; /*!< @description
	*	Maximum Torque Scaling Ramp In Gradient \n\n
	*	\@asap_name: P_DPRTVG_MaxTrqScalRampInGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_MaxTrqScalRampOutGrd_1ps; /*!< @description
	*	Maximum Torque Scaling Ramp Out Gradient \n\n
	*	\@asap_name: P_DPRTVG_MaxTrqScalRampOutGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_s_0_60_1em3_t	P_DPRTVG_PredTimeCrv_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_PredTimeCrv_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_DPRTVG_PredTimeHeadAng_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_StrWhStifAbortROGrd_1ps; /*!< @description
	*	Abort Steering Wheel Stiffness Ramp Out Gradient \n\n
	*	\@asap_name: P_DPRTVG_StrWhStifAbortROGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_DPRTVG_StrWhStifLimit_nu; /*!< @description
	*	Steering Wheel Stiffness Limiter \n\n
	*	\@asap_name: P_DPRTVG_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_StrWhStifROGrad_1ps; /*!< @description
	*	Standard Steering Wheel Stiffness Ramp Out Gradient \n\n
	*	\@asap_name: P_DPRTVG_StrWhStifROGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_TrqAbortROGrad_1ps; /*!< @description
	*	Abort Torque Ramp Ramp Out Gradient \n\n
	*	\@asap_name: P_DPRTVG_TrqAbortROGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_TrqRampInGrad_1ps; /*!< @description
	*	Torque Ramp Ramp In Gradient \n\n
	*	\@asap_name: P_DPRTVG_TrqRampInGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_DPRTVG_TrqRampOutGrad_1ps; /*!< @description
	*	Torque Ramp Ramp Out Gradient \n\n
	*	\@asap_name: P_DPRTVG_TrqRampOutGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_m100_100_1em3_t	P_DPRTVG_WeightTgtDistY_nu; /*!< @description
	*	Weight of the target position in the trajectory planning \n\n
	*	\@asap_name: P_DPRTVG_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_100000_1em3_t	P_DRMDAE_Abuse1stDuration_sec; /*!< @description
	*	Time to warn the driver at first Abuse attempt \n\n
	*	\@asap_name: P_DRMDAE_Abuse1stDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_100000_1em3_t	P_DRMDAE_ConsecIntervTimer_sec; /*!< @description
	*	Max time between 2 consecutive interventions to monitor Driver Function Abuse \n\n
	*	\@asap_name: P_DRMDAE_ConsecIntervTimer_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_100000_1em3_t	P_DRMDAE_DebHorAfterHandsOff_sec[10]; /*!< @description
	*	Debounce time between physical driver hands off and hands on request warning \n\n
	*	\@asap_name: P_DRMDAE_DebHorAfterHandsOff_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_100000_1em3_t	P_DRMDAE_DebounceTorAfterHor_sec[10]; /*!< @description
	*	Debounce time between hands on request and take over request \n\n
	*	\@asap_name: P_DRMDAE_DebounceTorAfterHor_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_100000_1em3_t	P_DRMDAE_IncNextWarning_sec; /*!< @description
	*	Time to increment the warning sound duration if driver does not cooperate \n\n
	*	\@asap_name: P_DRMDAE_IncNextWarning_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_mps_m20_150_1em3_t	P_DRMDAE_SpeedLimitHyst_mps; /*!< @description
	*	Hysteresis for speed limit \n\n
	*	\@asap_name: P_DRMDAE_SpeedLimitHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_mps_m20_150_1em3_t	P_DRMDAE_SpeedMin_mps; /*!< @description
	*	Speed limit, under which Hands Off Detection is deactivated => always hands on, if the speed is bellow 10kph \n\n
	*	\@asap_name: P_DRMDAE_SpeedMin_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_s_0_100000_1em3_t	P_DRMDAE_TrigDegrAftTorTime_sec[10]; /*!< @description
	*	Time to Keep the Take Over Request warning. \n\n
	*	\@asap_name: P_DRMDAE_TrigDegrAftTorTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_Nm_m100_100_1em3_t	P_DRMHOD_EstHandTqOffsetN_Nm; /*!< @description
	*	Negative Torque Offset \n\n
	*	\@asap_name: P_DRMHOD_EstHandTqOffsetN_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_Nm_m100_100_1em3_t	P_DRMHOD_EstHandTqOffsetP_Nm; /*!< @description
	*	Positive Torque Offset \n\n
	*	\@asap_name: P_DRMHOD_EstHandTqOffsetP_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_600_1em3_t	P_DRMHOD_HandsOffQlfMaxTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HandsOffQlfMaxTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 600
	*/
	
	f32_s_0_600_1em3_t	P_DRMHOD_HandsOffQlfTime_sec; /*!< @description
	*	Qualification Time \n\n
	*	\@asap_name: P_DRMHOD_HandsOffQlfTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 600
	*/
	
	f32_s_0_600_1em3_t	P_DRMHOD_HandsOnQlfTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HandsOnQlfTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 600
	*/
	
	f32_Nm_m100_100_1em3_t	P_DRMHOD_HandsOnTorLimAbs_Nm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HandsOnTorLimAbs_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_600_1em3_t	P_DRMHOD_HdOffDltProlTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HdOffDltProlTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 600
	*/
	
	f32_Nm_m100_100_1em3_t	P_DRMHOD_HdOffSensedTqDelta_Nm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HdOffSensedTqDelta_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_Nm_m100_100_1em3_t	P_DRMHOD_HdOffTqStepLim_Nm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HdOffTqStepLim_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRSIA_AclXHyst_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_AclXHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRSIA_AclXMax_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_AclXMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRSIA_AclXMin_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_AclXMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRSIA_AclYHyst_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_AclYHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRSIA_AclYMax_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_AclYMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_1pm_m0p1_0p1_1em3_t	P_LCRSIA_CurveDetectThreshold_1pm; /*!< @description
	*	Parameter used to determine the curve. \n\n
	*	\@asap_name: P_LCRSIA_CurveDetectThreshold_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_LCRSIA_HeadAngThresALCAHyst_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_HeadAngThresALCAHyst_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_LCRSIA_HeadAngThresALCAMax_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_HeadAngThresALCAMax_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_LCRSIA_HeadAngThresALCAMin_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_HeadAngThresALCAMin_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_10_1em3_t	P_LCRSIA_LaneWidthALCAHyst_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_LaneWidthALCAHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_LCRSIA_LaneWidthALCAMax_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_LaneWidthALCAMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_LCRSIA_LaneWidthALCAMin_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_LaneWidthALCAMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_LCRSIA_LaneWidthWideLnDef_met; /*!< @description
	*	New calculated Lane Width Default value. Used if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: P_LCRSIA_LaneWidthWideLnDef_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_LCRSIA_LnBndTurnOnTime_sec; /*!< @description
	*	Turn on delay time for the lane marking validity flags. \n\n
	*	\@asap_name: P_LCRSIA_LnBndTurnOnTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRSIA_SpecificDebTime_sec[8]; /*!< @description
	*	Vector containing the turn off debounce times of the ALCA Specific Qualifier. \n\n
	*	\@asap_name: P_LCRSIA_SpecificDebTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_degps_m360_360_1em3_t	P_LCRSIA_StrWhlAngSpeedALCAHyst_degps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_StrWhlAngSpeedALCAHyst_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_degps_m360_360_1em3_t	P_LCRSIA_StrWhlAngSpeedALCAMax_degps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_StrWhlAngSpeedALCAMax_degps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: -360 \n
	*	\@max: 360
	*/
	
	f32_deg_m720_720_1em3_t	P_LCRSIA_StrWhlAngleALCAHyst_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_StrWhlAngleALCAHyst_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_deg_m720_720_1em3_t	P_LCRSIA_StrWhlAngleALCAMax_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_StrWhlAngleALCAMax_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_LCRSIA_TlcHeadAngThres_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_TlcHeadAngThres_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_LCRSIA_TurnSignHoldingTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_TurnSignHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_kph_0_300_1em3_t	P_LCRSIA_VelDispALCAHyst_kph; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_VelDispALCAHyst_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_LCRSIA_VelDispALCAMax_kph; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_VelDispALCAMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_LCRSIA_VelDispALCAMin_kph; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_VelDispALCAMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_mps_m20_20_1em3_t	P_LCRSIA_VelLatThresALCAHyst_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_VelLatThresALCAHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_LCRSIA_VelLatThresALCAMax_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_VelLatThresALCAMax_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t	P_LCRSIA_VelLatThresALCAMin_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_VelLatThresALCAMin_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_BlockingTimeDuration_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BlockingTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_ControllingMaxDuration_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_ControllingMaxDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_DegrTimeOut_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_DegrTimeOut_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_DlcLimitMax_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_DlcLimitMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_DlcLimitMin_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_DlcLimitMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_HazardCancelTol_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_HazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_HazardFinishDlc_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_HazardFinishDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_LCRSMI_HazardFinishHeadAng_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_HazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_HazardFinishTol_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_HazardFinishTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_mps_m20_20_1em3_t	P_LCRSMI_HazardFinishVelLat_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_HazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_NoHazardCancelDlc_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_NoHazardCancelDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_NoHazardCancelTol_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_NoHazardCancelTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_NoHazardFinishDlc_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_NoHazardFinishDlc_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_LCRSMI_NoHazardFinishHeadAng_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_NoHazardFinishHeadAng_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_NoHazardFinishTol_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_NoHazardFinishTol_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_mps_m20_20_1em3_t	P_LCRSMI_NoHazardFinishVelLat_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_NoHazardFinishVelLat_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_OnTargetFinishTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_OnTargetFinishTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_RequestTimeOut_sec; /*!< @description
	*	Maximum time that ALCA can be in state REQUEST \n\n
	*	\@asap_name: P_LCRSMI_RequestTimeOut_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_SafeSituationDelay_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SafeSituationDelay_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_SafeSituationOffset_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SafeSituationOffset_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRSMI_TlcDistanceMin_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_TlcDistanceMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_TlcValidMinTime_sec; /*!< @description
	*	Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
	*	\@asap_name: P_LCRSMI_TlcValidMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRSMI_TriggerHoldingTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_TriggerHoldingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_LCRTTG_TgtMaxDistance_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTTG_TgtMaxDistance_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_LCRTTG_TgtMaxLatDev_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTTG_TgtMaxLatDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_LCRTTG_TgtTrjPT1TimeConst_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTTG_TgtTrjPT1TimeConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_LCRTVG_DistYTolLeTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_DistYTolLeTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_LCRTVG_DistYTolRiTgtArea_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_DistYTolRiTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRTVG_FTireAclMax_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_FTireAclMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_LCRTVG_FTireAclMin_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_FTireAclMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_1pms_m1000_1000_1em3_t	P_LCRTVG_LimiterMaxCrvGrd_1pms; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_LimiterMaxCrvGrd_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_1pm_m1_1_1em3_t	P_LCRTVG_LimiterMaxCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_LimiterMaxCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_s_0_60_1em3_t	P_LCRTVG_LimiterTimeDuration_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_LimiterTimeDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps3_0_50_1em3_t	P_LCRTVG_MaxJerkAllowed_mps3; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_NoUnit_0_100_1em3_t	P_LCRTVG_MaxTrqScalLimit_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_MaxTrqScalRampInGrd_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_MaxTrqScalRampInGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_MaxTrqScalRampOutGrd_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_MaxTrqScalRampOutGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_s_0_60_1em3_t	P_LCRTVG_PredTimeCrv_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_PredTimeCrv_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_LCRTVG_PredTimeHeadAng_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_StrWhStifAbortROGrd_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_StrWhStifAbortROGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_LCRTVG_StrWhStifLimit_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_StrWhStifRampOutGrd_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_StrWhStifRampOutGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_TrqAbortROGrd_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_TrqAbortROGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_TrqRampInGrad_1ps; /*!< @description
	*	Torque Standard Ramp In Gradient \n\n
	*	\@asap_name: P_LCRTVG_TrqRampInGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_LCRTVG_TrqRampOutGrad_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_TrqRampOutGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_m100_100_1em3_t	P_LCRTVG_WeightTgtDistY_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	P_MCTLFC_FollowUpDurationVec_sec[7]; /*!< @description
	*	Follow up Duration vector for every function in MDCTR. \n\n
	*	\@asap_name: P_MCTLFC_FollowUpDurationVec_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_100_1em4_t	P_ODPFOH_AccObjChngDuration_sec; /*!< @description
	*	Maximum transition time duration during ACC object change \n\n
	*	\@asap_name: P_ODPFOH_AccObjChngDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ODPFOH_CrvStdDev_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_CrvStdDev_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_s_0_5_1em3_t	P_ODPFOH_FeatPtsMinPosXTime_sec; /*!< @description
	*	Minimum time to longitudinal position x (behind front axle) for history point to be valid \n\n
	*	\@asap_name: P_ODPFOH_FeatPtsMinPosXTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_m15_15_1em3_t	P_ODPFOH_FeatPtsMinPosX_met; /*!< @description
	*	Minimum longitudinal position x (with respect to front axle) for history point to be valid \n\n
	*	\@asap_name: P_ODPFOH_FeatPtsMinPosX_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_rad_0_5_1em3_t	P_ODPFOH_HeadingAngStdDev_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_HeadingAngStdDev_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_kph_0_250_1em3_t	P_ODPFOH_LowSpeedHystVel_kph; /*!< @description
	*	Hysteresis for maximum Ego velocity for Low Speed Mode \n\n
	*	\@asap_name: P_ODPFOH_LowSpeedHystVel_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 250
	*/
	
	f32_kph_0_250_1em3_t	P_ODPFOH_LowSpeedMaxVel_kph; /*!< @description
	*	Below this maximum Ego velocity the Low Speed Mode is valid (incl. Hysteresis) \n\n
	*	\@asap_name: P_ODPFOH_LowSpeedMaxVel_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 250
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ODPFOH_MaxDeltaEgoCrvLSM_1pm; /*!< @description
	*	Maximum allowed curvature in LowSpeedMode between calculated and EgoCurvature \n\n
	*	\@asap_name: P_ODPFOH_MaxDeltaEgoCrvLSM_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_0_100_1em3_t	P_ODPFOH_MaxGradCrv_1pms; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MaxGradCrv_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radps_0_50_1em3_t	P_ODPFOH_MaxGradHeadAng_rps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MaxGradHeadAng_rps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOH_MaxGradPosY0_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MaxGradPosY0_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_300_1em3_t	P_ODPFOH_MaxHistStartX0_met; /*!< @description
	*	 \n\n
	*	\@asap_name: P_ODPFOH_MaxHistStartX0_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_40_1em3_t	P_ODPFOH_MaxObjDistHystLSM_met; /*!< @description
	*	Object hysteresis distance for Low Speed Mode \n\n
	*	\@asap_name: P_ODPFOH_MaxObjDistHystLSM_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_m_0_150_1em3_t	P_ODPFOH_MaxObjHistSampleD_met; /*!< @description
	*	Maximum distance between new and old object history sample point \n\n
	*	\@asap_name: P_ODPFOH_MaxObjHistSampleD_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_s_0_5_1em3_t	P_ODPFOH_MaxObjHistSampleT_sec; /*!< @description
	*	Maximum time for new object history sample \n\n
	*	\@asap_name: P_ODPFOH_MaxObjHistSampleT_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_1pm_0_0p1_1em6_t	P_ODPFOH_MaxRangeCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MaxRangeCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_ODPFOH_MaxRangeHead_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MaxRangeHead_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_40_1em3_t	P_ODPFOH_MaxRangePosY0_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MaxRangePosY0_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_s_0_5_1em3_t	P_ODPFOH_MinHistLengthTime_sec; /*!< @description
	*	Minimum history length in seconds to be treated as valid \n\n
	*	\@asap_name: P_ODPFOH_MinHistLengthTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_300_1em3_t	P_ODPFOH_MinHistLength_met; /*!< @description
	*	Minimum required history length for validity \n\n
	*	\@asap_name: P_ODPFOH_MinHistLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_40_1em3_t	P_ODPFOH_MinObjHistSampleD_met; /*!< @description
	*	Minimum distance between new and old object history sample point \n\n
	*	\@asap_name: P_ODPFOH_MinObjHistSampleD_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_s_0_100_1em4_t	P_ODPFOH_MinObjValidityTime_sec; /*!< @description
	*	Minimum object validity time for starting measurement update \n\n
	*	\@asap_name: P_ODPFOH_MinObjValidityTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_100_1em4_t	P_ODPFOH_MinTrajValidTime_sec; /*!< @description
	*	Minimum Trajectory validity time for switch to Object History Mode \n\n
	*	\@asap_name: P_ODPFOH_MinTrajValidTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOH_MinVelForKF_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_MinVelForKF_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_1000_1em3_t	P_ODPFOH_ObjKFDecQualDegr_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDecQualDegr_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_Pers_0_1000_1em3_t	P_ODPFOH_ObjKFDecQualPred_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDecQualPred_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_Pers_0_1000_1em3_t	P_ODPFOH_ObjKFDegrUpdGrad_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDegrUpdGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ODPFOH_ObjKFDegrUpdWeight_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDegrUpdWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ODPFOH_ObjKFDynCrvFact_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDynCrvFact_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ODPFOH_ObjKFDynDistYFact_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDynDistYFact_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ODPFOH_ObjKFDynYawFact_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDynYawFact_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_Pers_0_1000_1em3_t	P_ODPFOH_ObjKFIncrQual_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFIncrQual_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_ODPFOH_ObjKFInitRFactor_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFInitRFactor_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100000_1em3_t	P_ODPFOH_ObjKFKGainFact_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFKGainFact_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_mps2_0_50_1em3_t	P_ODPFOH_ObjKinMaxLatAccel_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKinMaxLatAccel_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_mps3_0_50_1em3_t	P_ODPFOH_ObjKinMaxLatJerk_mps3; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKinMaxLatJerk_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOH_ObjKinRefVel_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKinRefVel_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ODPFOH_PF_CrvChngDecay_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_PF_CrvChngDecay_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ODPFOH_PF_CrvDecay_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_PF_CrvDecay_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_40_1em3_t	P_ODPFOH_PosY0StdDev_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_PosY0StdDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_s_0_5_1em3_t	P_ODPFOH_PredTimeMaxPosX0_sec; /*!< @description
	*	Maximum prediction (extrapolation) time from history X0 to ego vehicle front axle \n\n
	*	\@asap_name: P_ODPFOH_PredTimeMaxPosX0_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ODPFOH_ScalingFactorCrv_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ScalingFactorCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ODPFOH_ScalingFactorHead_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ScalingFactorHead_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_ODPFOH_ScalingFactorPosY0_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ScalingFactorPosY0_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_40_1em3_t	P_ODPFOH_SignLimMinObjPosY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_SignLimMinObjPosY_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_NoUnit_0_20_1em3_t	P_ODPFOH_StrEstimMeanDevFac_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_StrEstimMeanDevFac_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 20
	*/
	
	f32_m_0_40_1em3_t	P_ODPFOH_StrEstimMeanDev_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_StrEstimMeanDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_Pers_m1000_0_1em4_t	P_ODPFOH_StrEstimNegGrad_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_StrEstimNegGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: -1000 \n
	*	\@max: 0
	*/
	
	f32_s_0p06_10_1em3_t	P_ODPFOH_StrEstimPT1_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_StrEstimPT1_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_Pers_0_1000_1em3_t	P_ODPFOH_StrEstimPosGrad_1ps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_StrEstimPosGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_radps_0_50_1em3_t	P_ODPFOH_VehYawRateStdDev_radps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_VehYawRateStdDev_radps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_DistYMaxCrvOffset_met; /*!< @description
	*	Maximum lateral curvature offset at target object position \n\n
	*	\@asap_name: P_ODPFOP_DistYMaxCrvOffset_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_DriveoffDelayTime_sec; /*!< @description
	*	Time until moving state of both Objects and Ego vehicle is delayed at transition from standstill to driveoff. \n\n
	*	\@asap_name: P_ODPFOP_DriveoffDelayTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_DriveoffTolTime_sec; /*!< @description
	*	Time after driveoff until new lateral object position should be inside tolerance compared to previously frozen lateral position. \n\n
	*	\@asap_name: P_ODPFOP_DriveoffTolTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps_m20_150_1em3_t	P_ODPFOP_DriveoffVelReset_mps; /*!< @description
	*	Velocity threshold to reset lateral movement freeze flag after standstill \n\n
	*	\@asap_name: P_ODPFOP_DriveoffVelReset_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_FacMaxDistYActive_nu; /*!< @description
	*	Factor for max dist Y activation \n\n
	*	\@asap_name: P_ODPFOP_FacMaxDistYActive_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_150_1em3_t	P_ODPFOP_LongDistMaxHyst_met; /*!< @description
	*	Hysteresis distance for Object x-position \n\n
	*	\@asap_name: P_ODPFOP_LongDistMaxHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_MaxDistYHyst_met; /*!< @description
	*	Maximum hysteresis for lateral object position validation \n\n
	*	\@asap_name: P_ODPFOP_MaxDistYHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_MaxDistY_met; /*!< @description
	*	Maximum valid lateral target object distance \n\n
	*	\@asap_name: P_ODPFOP_MaxDistY_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps2_m20_20_1em3_t	P_ODPFOP_MaxLatAcl_mps2; /*!< @description
	*	Maximum lateral acceleration \n\n
	*	\@asap_name: P_ODPFOP_MaxLatAcl_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOP_MaxLatVelHyst_mps; /*!< @description
	*	Maximum lateral object velocity hysteresis \n\n
	*	\@asap_name: P_ODPFOP_MaxLatVelHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOP_MaxLatVel_mps; /*!< @description
	*	Maximum lateral object velocity \n\n
	*	\@asap_name: P_ODPFOP_MaxLatVel_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps2_m20_20_1em3_t	P_ODPFOP_MaxLongAclHyst_mps2; /*!< @description
	*	Maximum object longitudinal acceleration hysteresis \n\n
	*	\@asap_name: P_ODPFOP_MaxLongAclHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_ODPFOP_MaxLongAcl_mps2; /*!< @description
	*	Maximum valid longitudinal object acceleration \n\n
	*	\@asap_name: P_ODPFOP_MaxLongAcl_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOP_MaxLongVelHyst_mps; /*!< @description
	*	Maximum longitudinal object velocity hysteresis \n\n
	*	\@asap_name: P_ODPFOP_MaxLongVelHyst_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_0_100_1em3_t	P_ODPFOP_MaxLongVel_mps; /*!< @description
	*	Maximum longitudinal object velocity \n\n
	*	\@asap_name: P_ODPFOP_MaxLongVel_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_MaxPosXDev_met; /*!< @description
	*	Threshold for object switch detection \n\n
	*	\@asap_name: P_ODPFOP_MaxPosXDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_MaxPosYDev_met; /*!< @description
	*	Threshold for PosY0 object switch detection \n\n
	*	\@asap_name: P_ODPFOP_MaxPosYDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_ODPFOP_MaxSteerAngle_rad; /*!< @description
	*	Maximum steering angle \n\n
	*	\@asap_name: P_ODPFOP_MaxSteerAngle_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_MinDurCamFusBefBrid_sec; /*!< @description
	*	Minimum duration for cam fusion before bridging \n\n
	*	\@asap_name: P_ODPFOP_MinDurCamFusBefBrid_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_MinMeasStateForPred_sec; /*!< @description
	*	Minimum time span for the object measurement to be 'MEASURED' state before 'PREDITED' state is allowed \n\n
	*	\@asap_name: P_ODPFOP_MinMeasStateForPred_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_MinWidthTgtObjHyst_met; /*!< @description
	*	Hysteresis for minimum target object width \n\n
	*	\@asap_name: P_ODPFOP_MinWidthTgtObjHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_ODPFOP_MinWidthTgtObj_met; /*!< @description
	*	Minimum target object width \n\n
	*	\@asap_name: P_ODPFOP_MinWidthTgtObj_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_ObjLossDebounceT_sec; /*!< @description
	*	Object loss debounce time \n\n
	*	\@asap_name: P_ODPFOP_ObjLossDebounceT_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0p06_10_1em3_t	P_ODPFOP_ObjPosYPT1Time4Yaw_sec; /*!< @description
	*	PT1 time constant for PosY which is only used for object yaw angle calculation - not for PosY output signal! \n\n
	*	\@asap_name: P_ODPFOP_ObjPosYPT1Time4Yaw_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_ObjSyncDelay_sec; /*!< @description
	*	Latency time between ACC target object data and ego VDY input data \n\n
	*	\@asap_name: P_ODPFOP_ObjSyncDelay_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_ObjTypeDebounceTime_sec; /*!< @description
	*	Debounce time time for target object validation \n\n
	*	\@asap_name: P_ODPFOP_ObjTypeDebounceTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0p06_10_1em3_t	P_ODPFOP_ObjYawPT1Time_sec; /*!< @description
	*	PT1 filter time constant for either own calculated or input yaw angle signal \n\n
	*	\@asap_name: P_ODPFOP_ObjYawPT1Time_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_m_0_150_1em3_t	P_ODPFOP_ObjYawSampleDist_met; /*!< @description
	*	Sample distance used for update frequency of calculated object yaw angle based on travelled object x distance \n\n
	*	\@asap_name: P_ODPFOP_ObjYawSampleDist_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_s_0p06_10_1em3_t	P_ODPFOP_ObjYawSampleTime_sec; /*!< @description
	*	Sample time used for update frequency of calculated object yaw angle based on travelled object x and y distance during this time \n\n
	*	\@asap_name: P_ODPFOP_ObjYawSampleTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_ODPFOP_PosStepDebounceTime_sec; /*!< @description
	*	Debounce time after step has been detected for both PosX and PosY input signal \n\n
	*	\@asap_name: P_ODPFOP_PosStepDebounceTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_mps_m20_150_1em3_t	P_ODPFOP_StandstillVelX_mps; /*!< @description
	*	Below this standstill velocity threshold both Ego and Object moving state is assumed as stationary/stopped. \n\n
	*	\@asap_name: P_ODPFOP_StandstillVelX_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTCDC_KMCDeltaPsiAttenu_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTCDC_KMCDeltaPsiAttenu_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTCDC_KMCDeltaPsiObsGain_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTCDC_KMCDeltaPsiObsGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTCDC_PT1CurDistYTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTCDC_PT1CurDistYTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTCDC_PT1CurHeadingTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTCDC_PT1CurHeadingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_rad_0_3p14_1em3_t	P_TCTCDC_WtchdgLimCoAnErr_rad; /*!< @description
	*	Absolute value of the threshold used to classify the Course Angle Error as too high \n\n
	*	\@asap_name: P_TCTCDC_WtchdgLimCoAnErr_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 3.14
	*/
	
	f32_m_0_5_1em3_t	P_TCTCDC_WtchdgLimYErr_m; /*!< @description
	*	Absolute value of the threshold used to classify the Y-Coordinate Error as too high \n\n
	*	\@asap_name: P_TCTCDC_WtchdgLimYErr_m \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_60_1em3_t	P_TCTCLM_QuServiceMaxTime_sec; /*!< @description
	*	Maximum hold time of degradation request \n\n
	*	\@asap_name: P_TCTCLM_QuServiceMaxTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TCTCLM_QuServiceMinTime_sec; /*!< @description
	*	Minimum hold time of degradation request \n\n
	*	\@asap_name: P_TCTCLM_QuServiceMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_1pms_m0p1_0p1_1em8_t	P_TCTDTE_BnkAglCrvReqGrd_1pms; /*!< @description
	*	Gradient Limit of the curvature request needed to compensate the bank angle. \n\n
	*	\@asap_name: P_TCTDTE_BnkAglCrvReqGrd_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TCTDTE_CroCGainS1_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_CroCGainS1_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TCTDTE_CroCGainS2_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_CroCGainS2_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TCTDTE_CroWindDeltaSetGain_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_CroWindDeltaSetGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_10_1em6_t	P_TCTDTE_CrvReqBnkAglGain_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_CrvReqBnkAglGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	P_TCTDTE_DeltaSetBnkAglGain_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_DeltaSetBnkAglGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTDTE_DmcT1_sec; /*!< @description
	*	First Time Constant of the DMC's transfer function (command steering angle -> driven curvature) \n\n
	*	\@asap_name: P_TCTDTE_DmcT1_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTDTE_DmcT1comp_sec; /*!< @description
	*	First Time Constant of the of second order low pass needed for the inversion of the DMC's trasfer function \n\n
	*	\@asap_name: P_TCTDTE_DmcT1comp_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTDTE_DmcT2_sec; /*!< @description
	*	Second Time Constant of the DMC's transfer function (command steering angle -> driven curvature) \n\n
	*	\@asap_name: P_TCTDTE_DmcT2_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTDTE_DmcT2comp_sec; /*!< @description
	*	Second Time Constant of the second order low pass needed for the inversion of the DMC's transfer function \n\n
	*	\@asap_name: P_TCTDTE_DmcT2comp_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_mps_0p001_20_1em5_t	P_TCTDTE_MinimumSpeed_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_MinimumSpeed_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0.001 \n
	*	\@max: 20
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTDTE_PT1CrvReqBAC_sec; /*!< @description
	*	Time constant for PT1 filter of curvature signal from bank angle compensation \n\n
	*	\@asap_name: P_TCTDTE_PT1CrvReqBAC_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_s_0p04_10_1em3_t	P_TCTDTE_TConstSteerAngle_sec; /*!< @description
	*	Time constant of the PT1 element used to filter the steering angle \n\n
	*	\@asap_name: P_TCTDTE_TConstSteerAngle_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.04 \n
	*	\@max: 10
	*/
	
	f32_radps_0_1p5_1em6_t	P_TCTEST_HdrDThetaDotEnd_rps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrDThetaDotEnd_rps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1.5
	*/
	
	f32_s_0p025_10_1em4_t	P_TCTEST_HdrDThetaDotPT1Time_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrDThetaDotPT1Time_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radps_0_1p5_1em6_t	P_TCTEST_HdrDThetaDotStart_rps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrDThetaDotStart_rps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1.5
	*/
	
	f32_mps_0_100_1em3_t	P_TCTEST_HdrDYDotEnd_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrDYDotEnd_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	P_TCTEST_HdrDYDotPT1Time_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrDYDotPT1Time_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_mps_0_100_1em3_t	P_TCTEST_HdrDYDotStart_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrDYDotStart_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTEST_HdrMeanDThetaWghtOf_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrMeanDThetaWghtOf_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTEST_HdrMeanDThetaWghtSf_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrMeanDThetaWghtSf_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTEST_HdrMeanDThetaWght_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrMeanDThetaWght_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTEST_HdrMeanDYWghtOf_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrMeanDYWghtOf_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTEST_HdrMeanDYWghtSf_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrMeanDYWghtSf_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTEST_HdrMeanDYWght_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_HdrMeanDYWght_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_0p001_20_1em5_t	P_TCTEST_MinimumSpeed_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_MinimumSpeed_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0.001 \n
	*	\@max: 20
	*/
	
	f32_s_0p025_10_1em4_t	P_TCTEST_PT1CrObsCrosswind_sec; /*!< @description
	*	Time constant of the PT1 used to filter the estimated crosswind \n\n
	*	\@asap_name: P_TCTEST_PT1CrObsCrosswind_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_s_0p025_10_1em4_t	P_TCTEST_PT1PlObsInCurvature_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_PT1PlObsInCurvature_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_mps3_m20_20_1em3_t	P_TCTFFC_DecelAclXGrdLD_mps3; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelAclXGrdLD_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps3_m20_20_1em3_t	P_TCTFFC_DecelAclXGrdLU_mps3; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelAclXGrdLU_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TCTFFC_DecelHystLSP_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelHystLSP_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TCTFFC_DecelThrsAxEnd_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelThrsAxEnd_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TCTFFC_DecelThrsAxStart_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelThrsAxStart_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0p025_10_1em4_t	P_TCTFFC_DynGainFadingTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainFadingTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_Perc_0_100_1em3_t	P_TCTFFC_DynGainMaxAdaption_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainMaxAdaption_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_10_1em3_t	P_TCTFFC_DynGainPreThrDY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainPreThrDY_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_Nm_0_10_1em3_t	P_TCTFFC_DynGainPreThrDriver_Nm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainPreThrDriver_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_TCTFFC_DynGainPrecThrKappa_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainPrecThrKappa_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_s_0p025_10_1em4_t	P_TCTFFC_PT1TgtCrvFiltTime_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_PT1TgtCrvFiltTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_rad_0_6p28_1em3_t	P_TCTLGC_CacILimit_rad; /*!< @description
	*	Absolute value of the Course Angle Controller's integral part saturation \n\n
	*	\@asap_name: P_TCTLGC_CacILimit_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 6.28
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTLGC_CacOfPGain_nu; /*!< @description
	*	Proportional master gain of the Course Angle Controller \n\n
	*	\@asap_name: P_TCTLGC_CacOfPGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTLGC_CacPGain_nu; /*!< @description
	*	Proportional master gain of the Course Angle Controller \n\n
	*	\@asap_name: P_TCTLGC_CacPGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTLGC_CacSfPGain_nu; /*!< @description
	*	Proportional master gain of the Course Angle Controller \n\n
	*	\@asap_name: P_TCTLGC_CacSfPGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm_0_0p1_1em6_t	P_TCTLGC_IntResMaxCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTLGC_IntResMaxCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_m10_10_1em3_t	P_TCTLGC_IntResMaxLatErr_m; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTLGC_IntResMaxLatErr_m \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_Nm_0_10_1em3_t	P_TCTLGC_IntResMaxManTrq_Nm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTLGC_IntResMaxManTrq_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_6p28_1em3_t	P_TCTLGC_LdcILimit_rad; /*!< @description
	*	Absolute value of the Y-Coordinate Controller's integral part saturation \n\n
	*	\@asap_name: P_TCTLGC_LdcILimit_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 6.28
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TCTLGC_LdcOfP_radpm; /*!< @description
	*	Proportional master gain of the Lateral Deviation Controller \n\n
	*	\@asap_name: P_TCTLGC_LdcOfP_radpm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radpsm_0_100_1em4_t	P_TCTLGC_LdcPT1MaxGrd_radpms; /*!< @description
	*	Absolute value of the maximum allowed gradient of the PT1 control signal part of the lateral deviation controller \n\n
	*	\@asap_name: P_TCTLGC_LdcPT1MaxGrd_radpms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/sm \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radpm_0_100_1em4_t	P_TCTLGC_LdcP_radpm; /*!< @description
	*	Proportional master gain of the Lateral Deviation Controller \n\n
	*	\@asap_name: P_TCTLGC_LdcP_radpm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radpm_0_100_1em4_t	P_TCTLGC_LdcSfP_radpm; /*!< @description
	*	Proportional master gain of the Lateral Deviation Controller \n\n
	*	\@asap_name: P_TCTLGC_LdcSfP_radpm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_degps_0_360_1em2_t	P_TCTLGC_MaxDeltaFGrd_dps; /*!< @description
	*	Maximum allowed gradient of the steer angle command signal which is send to the LaDMC \n\n
	*	\@asap_name: P_TCTLGC_MaxDeltaFGrd_dps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: �/s \n
	*	\@min: 0 \n
	*	\@max: 360
	*/
	
	f32_deg_m720_720_1em3_t	P_TCTLGC_MaxDeltaF_deg; /*!< @description
	*	Maximum allowed steer angle command signal which is send to the LaDMC \n\n
	*	\@asap_name: P_TCTLGC_MaxDeltaF_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_NoUnit_0_2_1em3_t	P_TCTLGC_PGainGrdLimit_1ps; /*!< @description
	*	Gradient Limit for P-Gain Transition \n\n
	*	\@asap_name: P_TCTLGC_PGainGrdLimit_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	f32_mps_0_100_1em3_t	P_TCTLGC_StandstillThreshVel_mps; /*!< @description
	*	Definition of standstill for TCTLGC \n\n
	*	\@asap_name: P_TCTLGC_StandstillThreshVel_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_40_1em3_t	P_TJACMB_AccObjPosXStdDev_met; /*!< @description
	*	Standard deviation of Acc object measurement PosX \n\n
	*	\@asap_name: P_TJACMB_AccObjPosXStdDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_m_m15_15_1em3_t	P_TJACMB_AccObjPosYStdDev_met; /*!< @description
	*	Standard deviation of Acc object measurement PosY \n\n
	*	\@asap_name: P_TJACMB_AccObjPosYStdDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_AccObjTransitionTime_sec; /*!< @description
	*	Transition time for lane to object transition \n\n
	*	\@asap_name: P_TJACMB_AccObjTransitionTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TJACMB_CombinedCrvObjWeight_nu; /*!< @description
	*	Object weight for combined curvature \n\n
	*	\@asap_name: P_TJACMB_CombinedCrvObjWeight_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t	P_TJACMB_CurvatureMaxOF_1pm; /*!< @description
	*	Maximum curvature allowed during object-based combined mode \n\n
	*	\@asap_name: P_TJACMB_CurvatureMaxOF_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_KalmanMinValidTime_sec; /*!< @description
	*	Minimum Kalman Filter running time to allow Lane2Obj transition \n\n
	*	\@asap_name: P_TJACMB_KalmanMinValidTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_LaneInvalidTime_sec; /*!< @description
	*	Invalidation time for lane error injection \n\n
	*	\@asap_name: P_TJACMB_LaneInvalidTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_LnQualMinOnTmCurve_sec; /*!< @description
	*	Minimum time of lane quality below P_TJACMB_LnQualMinCurve_perc to consider curvature scenario \n\n
	*	\@asap_name: P_TJACMB_LnQualMinOnTmCurve_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_LnQualMinOnTmWR_sec; /*!< @description
	*	Minimum time of lane quality above P_TJACMB_LnQualMinWR_perc for lane based combined mode activation \n\n
	*	\@asap_name: P_TJACMB_LnQualMinOnTmWR_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_MaxTimeObjCntrl_sec; /*!< @description
	*	Maximum allowed control time for object-based combined mode \n\n
	*	\@asap_name: P_TJACMB_MaxTimeObjCntrl_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_MinDurObjLnValidWR_sec; /*!< @description
	*	Minimum duration of valid object-in-lane check as WR condition for object-based combined mode \n\n
	*	\@asap_name: P_TJACMB_MinDurObjLnValidWR_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_40_1em3_t	P_TJACMB_MinLnLengthHystLC_met; /*!< @description
	*	Minimum lane length for lane based combined mode (hysteresis) \n\n
	*	\@asap_name: P_TJACMB_MinLnLengthHystLC_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_m_0_40_1em3_t	P_TJACMB_MinLnLengthLC_met; /*!< @description
	*	Minimum lane length for lane based combined mode \n\n
	*	\@asap_name: P_TJACMB_MinLnLengthLC_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_MinObjStraightProb_sec; /*!< @description
	*	Minimum time of minimum OF straight probability to set higher priority on pure object following mode \n\n
	*	\@asap_name: P_TJACMB_MinObjStraightProb_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_40_1em3_t	P_TJACMB_ObjHystPosXOF_met; /*!< @description
	*	Hysteresis for long. distance check of ACC target object to allow object based combined mode \n\n
	*	\@asap_name: P_TJACMB_ObjHystPosXOF_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_m_0_300_1em3_t	P_TJACMB_ObjMaxPosXOF_met; /*!< @description
	*	Maximum long. distance to ACC target object to allow object based combined mode \n\n
	*	\@asap_name: P_TJACMB_ObjMaxPosXOF_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t	P_TJACMB_ObjMinPosXOF_met; /*!< @description
	*	Minimum long. distance to ACC target object to allow object based combined mode \n\n
	*	\@asap_name: P_TJACMB_ObjMinPosXOF_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_60_1em3_t	P_TJACMB_PassivModeMinTime_sec; /*!< @description
	*	Combined mode blocking time after switch to combined mode passive state \n\n
	*	\@asap_name: P_TJACMB_PassivModeMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_kph_0_300_1em3_t	P_TJACMB_VelXMaxOF_kph; /*!< @description
	*	Maximum ego vehicle velocity to allow object based combined mode \n\n
	*	\@asap_name: P_TJACMB_VelXMaxOF_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_TJACMB_VelXMax_kph; /*!< @description
	*	Maximum allowed ego vehicle velocity for combined mode \n\n
	*	\@asap_name: P_TJACMB_VelXMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	P_TJACMB_VelXMin_kph; /*!< @description
	*	Minimum required ego vehicle velocity for combined mode \n\n
	*	\@asap_name: P_TJACMB_VelXMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJAGEN_AccelXHyst_mps2; /*!< @description
	*	Maximum long acceleration for TJA activation (hysteresis) \n\n
	*	\@asap_name: P_TJAGEN_AccelXHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJAGEN_AccelYHyst_mps2; /*!< @description
	*	Maximum lateral acceleration for TJA activation (hysteresis) \n\n
	*	\@asap_name: P_TJAGEN_AccelYHyst_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJAGEN_AclXMax_mps2; /*!< @description
	*	Maximum long acceleration for TJA activation \n\n
	*	\@asap_name: P_TJAGEN_AclXMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJAGEN_AclXMin_mps2; /*!< @description
	*	Minimum long deceleration for TJA activation \n\n
	*	\@asap_name: P_TJAGEN_AclXMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJAGEN_AclYMax_mps2; /*!< @description
	*	Maximum lateral acceleration for TJA activation \n\n
	*	\@asap_name: P_TJAGEN_AclYMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t	P_TJAGEN_BlockTimeTJA_sec; /*!< @description
	*	TJA blocking time \n\n
	*	\@asap_name: P_TJAGEN_BlockTimeTJA_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJAGEN_RampoutTimeMax_sec; /*!< @description
	*	Maximum rampout time \n\n
	*	\@asap_name: P_TJAGEN_RampoutTimeMax_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_deg_0_180_1em6_t	P_TJAGEN_SteerWAngleMaxWR_deg; /*!< @description
	*	Maximum steering wheel angle for function activation \n\n
	*	\@asap_name: P_TJAGEN_SteerWAngleMaxWR_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: 0 \n
	*	\@max: 180
	*/
	
	f32_s_0_60_1em3_t	P_TJALKA_BlockTimeTJA_sec; /*!< @description
	*	TJA Blocking time \n\n
	*	\@asap_name: P_TJALKA_BlockTimeTJA_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_5_1em3_t	P_TJALKA_DistVeh2LnBndHyst_met; /*!< @description
	*	Minimum distance to lane boundary hysteresis \n\n
	*	\@asap_name: P_TJALKA_DistVeh2LnBndHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_TJALKA_DistVeh2LnBndMin_met; /*!< @description
	*	Minimum distance to lane boundary \n\n
	*	\@asap_name: P_TJALKA_DistVeh2LnBndMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_5_1em3_t	P_TJALKA_LaneInvalidTime_sec; /*!< @description
	*	Lane invalidation time for lane error injection \n\n
	*	\@asap_name: P_TJALKA_LaneInvalidTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_TJALKA_LaneWidthHyst_met; /*!< @description
	*	Hysteresis for lane width check \n\n
	*	\@asap_name: P_TJALKA_LaneWidthHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_m15_15_1em3_t	P_TJALKA_LaneWidthMax_met; /*!< @description
	*	Maximum allowed lane width for lane centering \n\n
	*	\@asap_name: P_TJALKA_LaneWidthMax_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	P_TJALKA_LaneWidthMin_met; /*!< @description
	*	Minimum required lane width for lane centering \n\n
	*	\@asap_name: P_TJALKA_LaneWidthMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	P_TJALKA_LnPredMinValidTime_sec; /*!< @description
	*	Minimum required time of valid lanes and active controlling in LC or CMB mode for allowing both-sided lane prediction \n\n
	*	\@asap_name: P_TJALKA_LnPredMinValidTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_TJALKA_LnPredictionCrvMax_1pm; /*!< @description
	*	Maximum allowed lane curvature for lane prediction activation \n\n
	*	\@asap_name: P_TJALKA_LnPredictionCrvMax_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_s_0_60_1em3_t	P_TJALKA_LnPredictionTimeMax_sec; /*!< @description
	*	Maximum allowed lane prediction duration \n\n
	*	\@asap_name: P_TJALKA_LnPredictionTimeMax_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_5_1em3_t	P_TJALKA_LnPredictionTimeMin_sec; /*!< @description
	*	Minimum prediction time for rampout prediction (prediction of lanes while outputs torque output is set to zero) \n\n
	*	\@asap_name: P_TJALKA_LnPredictionTimeMin_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_60_1em3_t	P_TJALKA_LnQualTurnOffTime_sec; /*!< @description
	*	Turn off delay time for lane quality check \n\n
	*	\@asap_name: P_TJALKA_LnQualTurnOffTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJALKA_LnQualTurnOnTime_sec; /*!< @description
	*	Turn on delay time for lane quality check \n\n
	*	\@asap_name: P_TJALKA_LnQualTurnOnTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t	P_TJALKA_MaxHeadAngActnTJA_rad; /*!< @description
	*	Maximum allowed ego vehicle heading angle for activation of TJA \n\n
	*	\@asap_name: P_TJALKA_MaxHeadAngActnTJA_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_m_0_200_1em3_t	P_TJALKA_RadiusHyst_met; /*!< @description
	*	Curvature radius hysteresis \n\n
	*	\@asap_name: P_TJALKA_RadiusHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 200
	*/
	
	f32_m_0_1000_1em3_t	P_TJALKA_RadiusMin_met; /*!< @description
	*	Minimum curvature radius for lane centering controlling \n\n
	*	\@asap_name: P_TJALKA_RadiusMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_m_0_200_1em3_t	P_TJALKA_ValidLengthMinHyst_met; /*!< @description
	*	Minimum required valid length (hysteresis) \n\n
	*	\@asap_name: P_TJALKA_ValidLengthMinHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 200
	*/
	
	f32_m_0_200_1em3_t	P_TJALKA_ValidLengthMin_met; /*!< @description
	*	Minimum required valid length \n\n
	*	\@asap_name: P_TJALKA_ValidLengthMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 200
	*/
	
	f32_kph_m72_360_1em3_t	P_TJALKA_VelXHyst_kph; /*!< @description
	*	Longitudinal velocity hysteresis \n\n
	*	\@asap_name: P_TJALKA_VelXHyst_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: -72 \n
	*	\@max: 360
	*/
	
	f32_kph_m72_360_1em3_t	P_TJALKA_VelXMax_kph; /*!< @description
	*	Maximum longitudinal velocity allowed for lane centering mode \n\n
	*	\@asap_name: P_TJALKA_VelXMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: -72 \n
	*	\@max: 360
	*/
	
	f32_kph_m72_360_1em3_t	P_TJALKA_VelXMin_kph; /*!< @description
	*	Minimum longitudinal velocity required for lane centering mode \n\n
	*	\@asap_name: P_TJALKA_VelXMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: -72 \n
	*	\@max: 360
	*/
	
	f32_s_0_60_1em3_t	P_TJAOBF_CutinObValidFreezTm_sec; /*!< @description
	*	Freeze time of Acc object validity status after object cut-in \n\n
	*	\@asap_name: P_TJAOBF_CutinObValidFreezTm_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_5_1em3_t	P_TJAOBF_DefaultLaneWidth_met; /*!< @description
	*	Assumption of default lane width for object-in-lane check for maximum distance to lane boundary \n\n
	*	\@asap_name: P_TJAOBF_DefaultLaneWidth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_300_1em3_t	P_TJAOBF_MaxDiffLnLen2ObjPosX_met; /*!< @description
	*	Maximum longitudinal difference between detected lane length and acc object position x for object  in lane evaluation \n\n
	*	\@asap_name: P_TJAOBF_MaxDiffLnLen2ObjPosX_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_60_1em3_t	P_TJAOBF_MaxDurObjBrdg_sec; /*!< @description
	*	Maximum allowed duration of object bridging mode at high velocities \n\n
	*	\@asap_name: P_TJAOBF_MaxDurObjBrdg_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJAOBF_MinDurAccObjValid_sec; /*!< @description
	*	Minimum duration of ACC object validity for activation of object following and combined mode \n\n
	*	\@asap_name: P_TJAOBF_MinDurAccObjValid_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJAOBF_MinDurLCforOB_sec; /*!< @description
	*	Minimum duration of Lane Centering availability to allow object bridging at high velocities \n\n
	*	\@asap_name: P_TJAOBF_MinDurLCforOB_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJAOBF_MinDurObjLnValidWR_sec; /*!< @description
	*	Minimum duration of object in lane validity as WR condition \n\n
	*	\@asap_name: P_TJAOBF_MinDurObjLnValidWR_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_kph_0_300_1em3_t	P_TJAOBF_ObjLnCheckMinVelX_kph; /*!< @description
	*	Minimum longitudinal velocity to allow object-in-lane assessment \n\n
	*	\@asap_name: P_TJAOBF_ObjLnCheckMinVelX_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_1pm_0_0p1_1em6_t	P_TJAOBF_TgtClthCrvMaxHyst_1pm; /*!< @description
	*	Maximum allowed target object clothoid curvature for OF mode activation (hysteresis) \n\n
	*	\@asap_name: P_TJAOBF_TgtClthCrvMaxHyst_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t	P_TJAOBF_TgtClthHeadMaxHyst_rad; /*!< @description
	*	Maximum allowed target object clothoid heading angle for OF mode activation \n\n
	*	\@asap_name: P_TJAOBF_TgtClthHeadMaxHyst_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_m_0_300_1em3_t	P_TJAOBF_TgtClthLengthMin_met; /*!< @description
	*	Minimum required object trajectory length \n\n
	*	\@asap_name: P_TJAOBF_TgtClthLengthMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_60_1em3_t	P_TJAOBF_TgtClthMinValidTime_sec; /*!< @description
	*	Minimum validity time of target clothoid features for OF mode activation \n\n
	*	\@asap_name: P_TJAOBF_TgtClthMinValidTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	P_TJAOBF_TgtClthPosYMaxHyst_met; /*!< @description
	*	Maximum allowed target object clothoid pos Y0 for OF mode activation (hysteresis) \n\n
	*	\@asap_name: P_TJAOBF_TgtClthPosYMaxHyst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_0_5_1em3_t	P_TJAOBF_TgtVehDist2LnBndHst_met; /*!< @description
	*	Target vehicle minimum distance to lane boundary hysteresis \n
	*	 \n
	*	(Distance defined as vehicle center to lane boundary) \n\n
	*	\@asap_name: P_TJAOBF_TgtVehDist2LnBndHst_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_m_0_5_1em3_t	P_TJAOBF_TgtVehDist2LnBndMin_met; /*!< @description
	*	Target vehicle minimum distance to lane boundary hysteresis \n
	*	 \n
	*	(Distance defined as vehicle center to lane boundary) \n\n
	*	\@asap_name: P_TJAOBF_TgtVehDist2LnBndMin_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_kph_m72_360_1em3_t	P_TJAOBF_VelXMax_kph; /*!< @description
	*	Maximum longitudinal velocity allowed for object following mode \n\n
	*	\@asap_name: P_TJAOBF_VelXMax_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: -72 \n
	*	\@max: 360
	*/
	
	f32_kph_0_300_1em3_t	P_TJAOBF_VelXMinOF_kph; /*!< @description
	*	Minimum ego vehicle velocity to allow object based combined mode \n\n
	*	\@asap_name: P_TJAOBF_VelXMinOF_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_m72_360_1em3_t	P_TJAOBF_VelXMin_kph; /*!< @description
	*	Minimum longitudinal velocity required for object following mode \n\n
	*	\@asap_name: P_TJAOBF_VelXMin_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: -72 \n
	*	\@max: 360
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TJATTG_CrvChngDecay_nu; /*!< @description
	*	Curvature change decay factor for object following \n\n
	*	\@asap_name: P_TJATTG_CrvChngDecay_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm2_m0p1_0p1_1em8_t	P_TJATTG_LnMeasCrvChngVar_1pm4; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Measurement uncertainty of lane curvature \n\n
	*	\@asap_name: P_TJATTG_LnMeasCrvChngVar_1pm4 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_m0p1_0p1_1em8_t	P_TJATTG_LnMeasCrvVar_1pm2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Measurement uncertainty of lane curvature \n\n
	*	\@asap_name: P_TJATTG_LnMeasCrvVar_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_LnMeasHeadVar_rad2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Measurement uncertainty of lane heading \n\n
	*	\@asap_name: P_TJATTG_LnMeasHeadVar_rad2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_LnMeasPosYVar_m2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Measurement uncertainty of lateral lane position \n\n
	*	\@asap_name: P_TJATTG_LnMeasPosYVar_m2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_150_1em3_t	P_TJATTG_LnPredMinTrajLength_met; /*!< @description
	*	Minimum trajectory length for lane prediction \n\n
	*	\@asap_name: P_TJATTG_LnPredMinTrajLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_1pm2_m0p1_0p1_1em8_t	P_TJATTG_ModelCrvChngVar_1pm4; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Model uncertainty with respect to curvature change \n\n
	*	\@asap_name: P_TJATTG_ModelCrvChngVar_1pm4 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm2_m0p1_0p1_1em8_t	P_TJATTG_ModelCrvVar_1pm2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Model uncertainty with respect to curvature \n\n
	*	\@asap_name: P_TJATTG_ModelCrvVar_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_ModelPosYVar_m2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Model uncertainty with respect to lateral position \n\n
	*	\@asap_name: P_TJATTG_ModelPosYVar_m2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_ModelYawVar_rad2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Model uncertainty with respect to heading angle \n\n
	*	\@asap_name: P_TJATTG_ModelYawVar_rad2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_m15_15_1em3_t	P_TJATTG_ObjFolVirtLnWdth_met; /*!< @description
	*	TJATTG_APARAM \n\n
	*	\@asap_name: P_TJATTG_ObjFolVirtLnWdth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_ObjMeasPosXVar_m2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Measurement uncertainty of lateral object position \n\n
	*	\@asap_name: P_TJATTG_ObjMeasPosXVar_m2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_ObjMeasPosYVar_m2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Measurement uncertainty of longitudinal object position \n\n
	*	\@asap_name: P_TJATTG_ObjMeasPosYVar_m2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_s_0p06_10_1em3_t	P_TJATTG_PredCrvChngPT1_sec; /*!< @description
	*	Curvature change PT1 time constant during prediction (if signal is set to zero) \n\n
	*	\@asap_name: P_TJATTG_PredCrvChngPT1_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	P_TJATTG_PredCrvPT1_sec; /*!< @description
	*	Curvature PT1 time constant during prediction (if signal is set to zero) \n\n
	*	\@asap_name: P_TJATTG_PredCrvPT1_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_m_m300_300_1em3_t	P_TJATTG_PredResetTrajLength_met; /*!< @description
	*	Remaining saved trajectory length for prediction reset \n\n
	*	\@asap_name: P_TJATTG_PredResetTrajLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -300 \n
	*	\@max: 300
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_PredVelXVar_m2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Velocity variance for prediction \n\n
	*	\@asap_name: P_TJATTG_PredVelXVar_m2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_NoUnit_m0p1_0p1_1em8_t	P_TJATTG_PredYawRtVar_r2ps2; /*!< @description
	*	Kalman Filter Parameter: \n
	*	Yaw rate variance for prediction \n\n
	*	\@asap_name: P_TJATTG_PredYawRtVar_r2ps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_s_0_60_1em3_t	P_TJATTG_TransDurationCMB_sec; /*!< @description
	*	Transition duration for mode switch to combined data \n\n
	*	\@asap_name: P_TJATTG_TransDurationCMB_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJATTG_TransDurationLD_sec; /*!< @description
	*	Transition duration for mode switch to lane data \n\n
	*	\@asap_name: P_TJATTG_TransDurationLD_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJATTG_TransDurationOD_sec; /*!< @description
	*	Transition duration for mode switch to object data \n\n
	*	\@asap_name: P_TJATTG_TransDurationOD_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJATTG_TransDurationPredct_sec; /*!< @description
	*	Transition duration to switch from predicted lane data to new detected lane data \n\n
	*	\@asap_name: P_TJATTG_TransDurationPredct_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_0_10_1em3_t	P_TJATTG_VirtAdjLaneWidth_met; /*!< @description
	*	Virtual adjacent lane width \n\n
	*	\@asap_name: P_TJATTG_VirtAdjLaneWidth_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m1000_1000_1em3_t	P_TJATVG_DistYToleranceLeftTgtArea_met; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_DistYToleranceLeftTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_m_m1000_1000_1em3_t	P_TJATVG_DistYToleranceRightTgtArea_met; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_DistYToleranceRightTgtArea_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJATVG_FTireAccelMax_mps2; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_FTireAccelMax_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t	P_TJATVG_FTireAccelMin_mps2; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_FTireAccelMin_mps2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_NoUnit_0_10_1em6_t	P_TJATVG_FactorCrvGrdBuildUp_nu; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_FactorCrvGrdBuildUp_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	P_TJATVG_FactorCrvGrdRed_nu; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_FactorCrvGrdRed_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_1pms_0_10_1em6_t	P_TJATVG_GrdLimitTgtCrvTGC_1pms; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_GrdLimitTgtCrvTGC_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_1pms_0_10_1em6_t	P_TJATVG_LimiterMaxCrvGrd_1pms; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_LimiterMaxCrvGrd_1pms \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_1pm_0_40_1em3_t	P_TJATVG_LimiterMaxCrv_1pm; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_LimiterMaxCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_mps3_0_50_1em3_t	P_TJATVG_MaxJerkAllowed_mps3; /*!< @description
	*	Maximum allowed jerk \n\n
	*	\@asap_name: P_TJATVG_MaxJerkAllowed_mps3 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s^3 \n
	*	\@min: 0 \n
	*	\@max: 50
	*/
	
	f32_deg_0_180_1em6_t	P_TJATVG_MaxSteeringAngle_deg; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_MaxSteeringAngle_deg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: � \n
	*	\@min: 0 \n
	*	\@max: 180
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TJATVG_MaxTrqScalLimit_nu; /*!< @description
	*	TJATVG_APARAM \n\n
	*	\@asap_name: P_TJATVG_MaxTrqScalLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_MaxTrqScalRampInGrd_1ps; /*!< @description
	*	Maximum torque scaling gradient during ramp-in \n\n
	*	\@asap_name: P_TJATVG_MaxTrqScalRampInGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_MaxTrqScalRampOutGrd_1ps; /*!< @description
	*	Maximum torque scaling gradient during ramp-out \n\n
	*	\@asap_name: P_TJATVG_MaxTrqScalRampOutGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TJATVG_MinFactorCrvGrd_nu; /*!< @description
	*	TJATVG_APARAM \n\n
	*	\@asap_name: P_TJATVG_MinFactorCrvGrd_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_0_60_1em3_t	P_TJATVG_PlanHorzLaneChange_sec; /*!< @description
	*	Planning Horizon during lane change maneuver \n\n
	*	\@asap_name: P_TJATVG_PlanHorzLaneChange_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJATVG_PredTimeHeadAng_sec; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_PredTimeHeadAng_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TJATVG_PredictionTimeCrv_sec; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_PredictionTimeCrv_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_StrWhStifAbortGrd_1ps; /*!< @description
	*	TMC: \n
	*	Steering Wheel Stiffness Abort Ramp Out Gradient \n\n
	*	\@asap_name: P_TJATVG_StrWhStifAbortGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TJATVG_StrWhStifLimitPredct_nu; /*!< @description
	*	TJA specific steering wheel stiffness limiter during rampout prediction \n\n
	*	\@asap_name: P_TJATVG_StrWhStifLimitPredct_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	P_TJATVG_StrWhStifLimit_nu; /*!< @description
	*	TJA specific steering wheel stiffness limiter \n\n
	*	\@asap_name: P_TJATVG_StrWhStifLimit_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_StrWhStifRampInGrd_1ps; /*!< @description
	*	Steering wheel stiffness gradient during ramp-in \n\n
	*	\@asap_name: P_TJATVG_StrWhStifRampInGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_StrWhStifRampOutGrd_1ps; /*!< @description
	*	Steering wheel stiffness gradient during ramp-out \n\n
	*	\@asap_name: P_TJATVG_StrWhStifRampOutGrd_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_TrqAbortGrad_1ps; /*!< @description
	*	TMC: \n
	*	Torque Ramp Abort Ramp Out Gradient \n\n
	*	\@asap_name: P_TJATVG_TrqAbortGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_TrqRampInGrad_1ps; /*!< @description
	*	Torque ramp gradient during ramp-in \n\n
	*	\@asap_name: P_TJATVG_TrqRampInGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Pers_0_10000_1em3_t	P_TJATVG_TrqRampOutGrad_1ps; /*!< @description
	*	Torque ramp gradient during ramp-out \n\n
	*	\@asap_name: P_TJATVG_TrqRampOutGrad_1ps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TJATVG_WeightEndtime_nu; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_WeightEndtime_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TJATVG_WeightTgtDistY_nu; /*!< @description
	*	TJATVG_APARAM \n\n
	*	\@asap_name: P_TJATVG_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_0p1_20_1em3_t	P_TPLCEN_CyCTimeTrajCalc_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_CyCTimeTrajCalc_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.1 \n
	*	\@max: 20
	*/
	
	f32_s_0_1_1em3_t	P_TPLCEN_DTGradLimitDuration_sec; /*!< @description
	*	Duration of the gradient limitation for dead time change. \n\n
	*	\@asap_name: P_TPLCEN_DTGradLimitDuration_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_m100_100_1em3_t	P_TPLCEN_ErrDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_ErrDistY_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_rad_m6_6_1em3_t	P_TPLCEN_ErrHeadAglPrev_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_ErrHeadAglPrev_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_s_0_60_1em3_t	P_TPLCEN_ManualTrqMaxTime_sec; /*!< @description
	*	Time buffer to make sure if the manual torque is smaller than the threshold \n\n
	*	\@asap_name: P_TPLCEN_ManualTrqMaxTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Nm_0_10_1em3_t	P_TPLCEN_ManualTrqMax_Nm; /*!< @description
	*	Threshold to detect if the manaul torque is small enough \n\n
	*	\@asap_name: P_TPLCEN_ManualTrqMax_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_TPLCEN_ManualTrqMinTime_sec; /*!< @description
	*	Time buffer to make sure if the manual torque is larger than the threshold and have been hold \n\n
	*	\@asap_name: P_TPLCEN_ManualTrqMinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Nm_0_10_1em3_t	P_TPLCEN_ManualTrqMin_Nm; /*!< @description
	*	Threshold to detect if the manaul torque is big enough \n\n
	*	\@asap_name: P_TPLCEN_ManualTrqMin_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_1_1em3_t	P_TPLCEN_MaxPredictionTime_sec; /*!< @description
	*	Limitation of prediction time on curvature and heading \n\n
	*	\@asap_name: P_TPLCEN_MaxPredictionTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_0_1_1em3_t	P_TPLCEN_PTCrvGradLimitDur_sec; /*!< @description
	*	Duration of the gradient limitation for prediction time curvature change. \n\n
	*	\@asap_name: P_TPLCEN_PTCrvGradLimitDur_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_0_1_1em3_t	P_TPLCEN_PTHeadGradLimitDur_sec; /*!< @description
	*	Duration of the gradient limitation for prediction time heading change. \n\n
	*	\@asap_name: P_TPLCEN_PTHeadGradLimitDur_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_1_1em3_t	P_TPLCEN_ReIniDeltaDistY_met; /*!< @description
	*	Threshold for reinitialization w.r.t the lateral deviation. \n\n
	*	\@asap_name: P_TPLCEN_ReIniDeltaDistY_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_TPLCEN_ReIniDeltaHead_rad; /*!< @description
	*	Threshold for reinitialization w.r.t the heading. \n\n
	*	\@asap_name: P_TPLCEN_ReIniDeltaHead_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_kph_0_300_1em3_t	P_TPLCEN_VMinTimeBasedTraj_kph; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_VMinTimeBasedTraj_kph \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	P_TPLFBT_DeltaTargetCrv_1pm; /*!< @description
	*	Threshold of the difference between planned trajectoy curvature and target corridor curvature for target switching. \n\n
	*	\@asap_name: P_TPLFBT_DeltaTargetCrv_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_rad_m6_6_1em3_t	P_TPLFBT_DeltaTargetHeading_rad; /*!< @description
	*	Threshold of the difference between planned trajectoy heading and target corridor heading for target switching. \n\n
	*	\@asap_name: P_TPLFBT_DeltaTargetHeading_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_m_m15_15_1em3_t	P_TPLFBT_DeltaTargetPosY0_met; /*!< @description
	*	Threshold of the difference between planned trajectoy disty and target corridor disty for target switching. \n\n
	*	\@asap_name: P_TPLFBT_DeltaTargetPosY0_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_100_1em4_t	P_TPLFBT_DurationGradLimit_sec; /*!< @description
	*	duration for the gradient limitation by target switch \n\n
	*	\@asap_name: P_TPLFBT_DurationGradLimit_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm2_0_0p5_1em8_t	P_TPLFBT_GradLimitCrv_1pm2; /*!< @description
	*	gradient limit of the curvature with regards to the distance \n\n
	*	\@asap_name: P_TPLFBT_GradLimitCrv_1pm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m^2 \n
	*	\@min: 0 \n
	*	\@max: 0.5
	*/
	
	f32_radps_0_100000_1em3_t	P_TPLFBT_GradLimitHeadHigh_rps; /*!< @description
	*	heading gradient limitation after the duration defined by P_TPLFBT_DurationGradLimit_sec \n\n
	*	\@asap_name: P_TPLFBT_GradLimitHeadHigh_rps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_radps_0_1_1em3_t	P_TPLFBT_GradLimitHead_rps; /*!< @description
	*	heading gradient limitation by target switch \n\n
	*	\@asap_name: P_TPLFBT_GradLimitHead_rps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad/s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_mps_0_250_1em3_t	P_TPLFBT_GradLimitPosYHigh_mps; /*!< @description
	*	disty gradient limitation after the duration defined by P_TPLFBT_DurationGradLimit_sec \n\n
	*	\@asap_name: P_TPLFBT_GradLimitPosYHigh_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 250
	*/
	
	f32_mps_m20_20_1em3_t	P_TPLFBT_GradLimitPosY_mps; /*!< @description
	*	disty gradient limitation by target switch \n\n
	*	\@asap_name: P_TPLFBT_GradLimitPosY_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_TPLFBT_HeadCheckTolOBF_rad; /*!< @description
	*	Heading plausi check tolerance for object following \n\n
	*	\@asap_name: P_TPLFBT_HeadCheckTolOBF_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_TPLFBT_HeadCheckTolerance_rad; /*!< @description
	*	Heading plausi check tolerance for all the functions and modes except object following \n\n
	*	\@asap_name: P_TPLFBT_HeadCheckTolerance_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_TPLFBT_MaxQuStatusHold_sec; /*!< @description
	*	Max. duration for holding the QuStatus \n\n
	*	\@asap_name: P_TPLFBT_MaxQuStatusHold_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_TPLFBT_MinQuStatusHold_sec; /*!< @description
	*	Min. duration for holding the QuStatus \n\n
	*	\@asap_name: P_TPLFBT_MinQuStatusHold_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_5_1em3_t	P_TPLFRT_PlnHrznMinBarrier_sec; /*!< @description
	*	Planning Horizon Minimum Barrier \n\n
	*	\@asap_name: P_TPLFRT_PlnHrznMinBarrier_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_s_0_1_1em3_t	P_TPLFRT_TgtPointMin_sec; /*!< @description
	*	Min. target point for trajectory planning (in time te) \n\n
	*	\@asap_name: P_TPLFRT_TgtPointMin_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm_0_0p1_1em6_t	P_TPLLCO_CCCMaxCurvature_1pm; /*!< @description
	*	threshold for curve for CCC check \n\n
	*	\@asap_name: P_TPLLCO_CCCMaxCurvature_1pm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.1
	*/
	
	f32_m_0_100_1em5_t	P_TPLLCO_CCCMinTestDistX_met; /*!< @description
	*	Min. DistX of the test point \n\n
	*	\@asap_name: P_TPLLCO_CCCMinTestDistX_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_100_1em5_t	P_TPLLCO_CCCMinValidLength_met; /*!< @description
	*	Min. valid length for bridging by failed CCC, afterwards it will be reported to SA through bitfield. \n\n
	*	\@asap_name: P_TPLLCO_CCCMinValidLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_100_1em5_t	P_TPLLCO_CCCResetMaxDistX_met; /*!< @description
	*	Reset when DistX over the Max. \n\n
	*	\@asap_name: P_TPLLCO_CCCResetMaxDistX_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TPLLCO_CCCResetMaxPerc_nu; /*!< @description
	*	Reset when the DistX of the test point is over the max perc. of the frozen length \n\n
	*	\@asap_name: P_TPLLCO_CCCResetMaxPerc_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TPLLCO_CCCTestDisXPerc_nu; /*!< @description
	*	DistX of the test point = TestDistXPerc * ValidLength \n\n
	*	\@asap_name: P_TPLLCO_CCCTestDisXPerc_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_1_1em3_t	P_TPLLCO_CCCThresholdMaxDev_met; /*!< @description
	*	Threshold of the max. allowed deviation by CCC \n\n
	*	\@asap_name: P_TPLLCO_CCCThresholdMaxDev_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_10_1em6_t	P_TPLLCO_CCCValidMaxPerc_nu; /*!< @description
	*	Max. Perc. of the frozen length of the test point by valid check \n\n
	*	\@asap_name: P_TPLLCO_CCCValidMaxPerc_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m100_100_1em3_t	P_TPLLCO_CoordTrafoMinLength_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_CoordTrafoMinLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_0_1_1em3_t	P_TPLLCO_CrvCheckTolerance_met; /*!< @description
	*	Tolerance of the deviation caused by the curvature term by coordinate transformation. \n\n
	*	\@asap_name: P_TPLLCO_CrvCheckTolerance_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_1_1em3_t	P_TPLLCO_DistYCheckTolerance_met; /*!< @description
	*	Tolerance of the deviation caused by the disty term by coordinate transformation. \n\n
	*	\@asap_name: P_TPLLCO_DistYCheckTolerance_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_m60_60_1em3_t	P_TPLLCO_TimeDiff_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_TimeDiff_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: -60 \n
	*	\@max: 60
	*/
	
	f32_s_0p025_10_1em4_t	P_TPLLCO_VehCrvPT1TimeConst_sec; /*!< @description
	*	Time constant of the low pass filter on vehicle curvature \n\n
	*	\@asap_name: P_TPLLCO_VehCrvPT1TimeConst_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_s_0_5_1em3_t	P_TPLTJC_AllowedTimetoCross_sec; /*!< @description
	*	Allowed time to cross the lane boundary \n\n
	*	\@asap_name: P_TPLTJC_AllowedTimetoCross_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TPLTJC_FTireAclMinScaling_nu; /*!< @description
	*	Scaling factor to dis/enable FTireAclMin check \n\n
	*	\@asap_name: P_TPLTJC_FTireAclMinScaling_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_1_100_1em3_t	P_TPLTJC_MaxArcLength_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_MaxArcLength_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	f32_s_0p001_100_1em3_t	P_TPLTJC_TMax_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_TMax_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0.001 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	P_TPLTJC_WeightDistBased_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_WeightDistBased_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_65535_1em3_t	P_TPLTJC_WeightTgtDistY_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_DebTimeAccPedRate_sec; /*!< @description
	*	VDPDRV_APARAM \n\n
	*	\@asap_name: P_VDPDRV_DebTimeAccPedRate_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_DebTimeActStCtrl_sec; /*!< @description
	*	VDPDRV_APARAM \n\n
	*	\@asap_name: P_VDPDRV_DebTimeActStCtrl_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_DebTimeTurnSignal_sec; /*!< @description
	*	VDPDRV_APARAM \n\n
	*	\@asap_name: P_VDPDRV_DebTimeTurnSignal_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_HoldTimeErrorSt_sec; /*!< @description
	*	Hold time for error state bit field \n
	*	(previous: P_VDPDRV_MinDurtnSysStError_sec) \n\n
	*	\@asap_name: P_VDPDRV_HoldTimeErrorSt_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Nm_0_10_1em3_t	P_VDPDRV_ManTrqOvrrdMaxTrq_Nm; /*!< @description
	*	Manual steering torque threshold, which will lead in any case to rampout. \n\n
	*	\@asap_name: P_VDPDRV_ManTrqOvrrdMaxTrq_Nm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: Nm \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_ManTrqOvrrdTrnOnTm_sec; /*!< @description
	*	Turn-on delay time for manual steering torque override trigger \n\n
	*	\@asap_name: P_VDPDRV_ManTrqOvrrdTrnOnTm_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Perc_0_100_1em3_t	P_VDPDRV_MaxAccelPedalRate_nu; /*!< @description
	*	VDPDRV_APARAM \n\n
	*	\@asap_name: P_VDPDRV_MaxAccelPedalRate_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_m150_150_1em3_t	P_VDPDRV_MaxVelLimStrngStp_mps; /*!< @description
	*	InitValue: 5.6 \n\n
	*	\@asap_name: P_VDPDRV_MaxVelLimStrngStp_mps \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m/s \n
	*	\@min: -150 \n
	*	\@max: 150
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_NoDaytCndTimeMin_sec; /*!< @description
	*	Min time to activate NoDaytime condition \n\n
	*	\@asap_name: P_VDPDRV_NoDaytCndTimeMin_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_NoDaytCndTrnOff_sec; /*!< @description
	*	Turn off time of NoDaytime condition \n\n
	*	\@asap_name: P_VDPDRV_NoDaytCndTrnOff_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_VDPDRV_ThStrngStpDtctd_rad; /*!< @description
	*	InitValue: 0.5235 \n\n
	*	\@asap_name: P_VDPDRV_ThStrngStpDtctd_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_0_0p78539816_1em8_t	P_VDPDRV_ThStrngStpNotDtctd_rad; /*!< @description
	*	InitValue: 0.4365 \n\n
	*	\@asap_name: P_VDPDRV_ThStrngStpNotDtctd_rad \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_TurnOffTimeErrorSt_sec; /*!< @description
	*	Turn off delay time for error state bit field \n\n
	*	\@asap_name: P_VDPDRV_TurnOffTimeErrorSt_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_TurnOnTimeErrorSt_sec; /*!< @description
	*	Turn on delay time for error state bit field \n\n
	*	\@asap_name: P_VDPDRV_TurnOnTimeErrorSt_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_WiperActiveTimeMin_sec; /*!< @description
	*	Wiper minimum active time for considering it as one wiper event \n\n
	*	\@asap_name: P_VDPDRV_WiperActiveTimeMin_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_WiperEventsGapTimeMax_sec; /*!< @description
	*	Maximum time gap between wiper events for continuous wiping check \n\n
	*	\@asap_name: P_VDPDRV_WiperEventsGapTimeMax_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	P_VDPDRV_WiperMinContinTime_sec; /*!< @description
	*	Minimum time of continuous wiping for considering rainy conditions \n\n
	*	\@asap_name: P_VDPDRV_WiperMinContinTime_sec \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m10_10_1em3_t	P_VEH_CenterOfPressure_met; /*!< @description
	*	Distance between the center of gravity and the center of pressure \n\n
	*	\@asap_name: P_VEH_CenterOfPressure_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_Npr_0_500000_1em4_t	P_VEH_CorStiffFrontAxle_Npr; /*!< @description
	*	Cornering stiffness coefficient of the tires at the front axle \n\n
	*	\@asap_name: P_VEH_CorStiffFrontAxle_Npr \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: N/rad \n
	*	\@min: 0 \n
	*	\@max: 500000
	*/
	
	f32_Npr_0_500000_1em4_t	P_VEH_CorStiffRearAxle_Npr; /*!< @description
	*	Cornering stiffness coefficient of the tires at the rear axle \n\n
	*	\@asap_name: P_VEH_CorStiffRearAxle_Npr \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: N/rad \n
	*	\@min: 0 \n
	*	\@max: 500000
	*/
	
	f32_m_0_10_1em3_t	P_VEH_DistCogToFrontAxle_m; /*!< @description
	*	Distance between front axle and the vehicle's center of gravity \n\n
	*	\@asap_name: P_VEH_DistCogToFrontAxle_m \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	P_VEH_DistCogToRearAxle_m; /*!< @description
	*	Distance between rear axle and the vehicle's center of gravity \n\n
	*	\@asap_name: P_VEH_DistCogToRearAxle_m \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_kgm2_1_100000_1em2_t	P_VEH_Inertia_kgm2; /*!< @description
	*	Inertia of the Vehicle \n\n
	*	\@asap_name: P_VEH_Inertia_kgm2 \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: kgm^2 \n
	*	\@min: 1 \n
	*	\@max: 100000
	*/
	
	f32_m_0_10_1em3_t	P_VEH_OverhangFront_met; /*!< @description
	*	Front overhang for transformation from radar to front axle coordinate system \n\n
	*	\@asap_name: P_VEH_OverhangFront_met \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_1_1em6_t	P_VEH_SelfSteeringGrd_nu; /*!< @description
	*	Self Steering Gradient of the Vehicle \n\n
	*	\@asap_name: P_VEH_SelfSteeringGrd_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_mps_0_100_1em3_t	X_ABPLBP_ThLnClthMinValLen_mps[7]; /*!< @description
	*	X-axis of the LUT for the minimum valid length of an input lane clothoid (in mps) \n\n
	*	\@asap_name: X_ABPLBP_ThLnClthMinValLen_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_m100_100_1em3_t	X_DRMHOD_VelX_mps[17]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_DRMHOD_VelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	X_LCF_Curvature_1pm[7]; /*!< @description
	*	X-axis for all the curvature dependant parameters. \n\n
	*	\@asap_name: X_LCF_Curvature_1pm \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m10_10_1em3_t	X_LCF_DistY_met[7]; /*!< @description
	*	X-axis for the Lateral Distance Dependant Look-Up Tables along LCF. \n\n
	*	\@asap_name: X_LCF_DistY_met \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m1000_1000_1em3_t	X_LCF_LaneWidth_met[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_LCF_LaneWidth_met \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_mps_m100_100_1em3_t	X_LCF_VelX_mps[9]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_LCF_VelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps_m20_20_1em3_t	X_LCF_VelY_mps[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_LCF_VelY_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_NoUnit_0_1_1em6_t	X_ODPFOH_StraightEstim_perc[8]; /*!< @description
	*	x-axis for straight estimation [%] / 100.0 --> [0..1] \n\n
	*	\@asap_name: X_ODPFOH_StraightEstim_perc \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_kph_0_250_1em3_t	X_ODPFOH_VehVelXPT1_kph[15]; /*!< @description
	*	Velocity axis for PT1 time constant speed dependent tuning \n\n
	*	\@asap_name: X_ODPFOH_VehVelXPT1_kph \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 250
	*/
	
	f32_mps_m20_150_1em3_t	X_ODPFOH_VehVelX_mps[15]; /*!< @description
	*	x-axis for ego veh. vel. [mps] \n\n
	*	\@asap_name: X_ODPFOH_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_mps_0_100_1em3_t	X_ODPFOP_LongDistMaxVel_mps[15]; /*!< @description
	*	Velocity axis for object distance validation \n\n
	*	\@asap_name: X_ODPFOP_LongDistMaxVel_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_m20_100_1em3_t	X_TCTCLM_VehVelX_mps[16]; /*!< @description
	*	Velocity vector along the vehicle's longitudinal axis / (m/s) \n\n
	*	\@asap_name: X_TCTCLM_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_mps_m20_100_1em3_t	X_TCTDTE_InputVehVelSat_met[8]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TCTDTE_InputVehVelSat_met \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_kph_0_250_1em3_t	X_TCTDTE_KappaAngle_kph[13]; /*!< @description
	*	Grid points for the x-Axis of the LaDMC Look Up Table "Kappa To Angle" \n\n
	*	\@asap_name: X_TCTDTE_KappaAngle_kph \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 250
	*/
	
	f32_mps_m20_100_1em3_t	X_TCTDTE_VehVelX_mps[14]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TCTDTE_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_mps_m20_100_1em3_t	X_TCTEST_InputVehVelSat_met[8]; /*!< @description
	*	- \n\n
	*	\@asap_name: X_TCTEST_InputVehVelSat_met \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_rad_0_12_1em4_t	X_TCTEST_StwGearRatio_rad[7]; /*!< @description
	*	Grid Points for the LookUp table for the steering ratio comprising steering wheel angles between 0rad and 12rad. Assumption: Symmetric Steering. \n\n
	*	\@asap_name: X_TCTEST_StwGearRatio_rad \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 12
	*/
	
	f32_mps_m20_100_1em3_t	X_TCTEST_VehVelX_mps[14]; /*!< @description
	*	- \n\n
	*	\@asap_name: X_TCTEST_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_1pm_m0p1_0p1_1em3_t	X_TCTLGC_CrvFFC_1pm[10]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TCTLGC_CrvFFC_1pm \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_m_m100_100_1em3_t	X_TCTLGC_CtrlErrDistY_met[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TCTLGC_CtrlErrDistY_met \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps_m20_100_1em3_t	X_TCTLGC_Vel_mps[16]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TCTLGC_Vel_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_kph_0_300_1em3_t	X_TJAGEN_VehVelX_kph[7]; /*!< @description
	*	TJAGEN vehicle speed x-axis for Y_TJAGEN_VehRadiusMaxWR_met \n\n
	*	\@asap_name: X_TJAGEN_VehVelX_kph \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_kph_0_300_1em3_t	X_TJAOBF_VehVelX_kph[7]; /*!< @description
	*	TJAOBF VehVelX x-axis for lookup tables \n\n
	*	\@asap_name: X_TJAOBF_VehVelX_kph \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: km/h \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	X_TJATVG_CrvPlanHorizon_1pm[8]; /*!< @description
	*	X axis for the Planning Horizon \n\n
	*	\@asap_name: X_TJATVG_CrvPlanHorizon_1pm \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_mps_m20_150_1em3_t	X_TJATVG_VehVelX_RedFact_mps[7]; /*!< @description
	*	TJATVG_APARAM for Y_TJATVG_RedFact_Vel_nu \n\n
	*	\@asap_name: X_TJATVG_VehVelX_RedFact_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_mps_m20_150_1em3_t	X_TJATVG_VehVelX_mps[7]; /*!< @description
	*	TJATVG_APARAM \n\n
	*	\@asap_name: X_TJATVG_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 150
	*/
	
	f32_mps_m20_100_1em3_t	X_TPLCEN_PotVecDynVelX_mps[8]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TPLCEN_PotVecDynVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_mps_0_100_1em3_t	X_TPLFBT_VehVelX_mps[14]; /*!< @description
	*	x axle: longitudinal velocity \n\n
	*	\@asap_name: X_TPLFBT_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	X_TPLLCO_CorridorCurvature_1pm[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TPLLCO_CorridorCurvature_1pm \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m100_100_1em3_t	X_TPLLCO_TestPointPosX_met[5]; /*!< @description
	*	x axle with test point longitudinal position \n\n
	*	\@asap_name: X_TPLLCO_TestPointPosX_met \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps_m20_100_1em3_t	X_TPLLCO_VehVelX_mps[14]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TPLLCO_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 100
	*/
	
	f32_s_0_100_1em4_t	X_TPLTJC_PlanningHorizon_sec[6]; /*!< @description
	*	x axle with planning horizon \n\n
	*	\@asap_name: X_TPLTJC_PlanningHorizon_sec \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_mps_0_100_1em3_t	X_TPLTJC_VehVelX_mps[7]; /*!< @description
	*	x axle with vehicle longitudinal velocity \n\n
	*	\@asap_name: X_TPLTJC_VehVelX_mps \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: m/s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	X_TPLTJC_WghtTgtDistYCustFct_nu[3]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TPLTJC_WghtTgtDistYCustFct_nu \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	X_TPLTJC_WghtTgtTimeCustFct_nu[3]; /*!< @description
	*	 \n\n
	*	\@asap_name: X_TPLTJC_WghtTgtTimeCustFct_nu \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_150_1em3_t	Y_ABPLBP_ThLnClthMinValLen_met[6]; /*!< @description
	*	Y-axis of the LUT for the minimum valid length of an input lane clothoid (in met) \n\n
	*	\@asap_name: Y_ABPLBP_ThLnClthMinValLen_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ABPLBP_ThLnClthMinValLen_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_150_1em3_t	Y_ABPLBP_ThMinValLenHyst_met[6]; /*!< @description
	*	Y-axis of the LUT for the minimum valid length of an input lane clothoid (hysteresis) \n\n
	*	\@asap_name: Y_ABPLBP_ThMinValLenHyst_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ABPLBP_ThLnClthMinValLen_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_m_0_300_1em3_t	Y_ABPREP_ThReClthMinValLen_met[6]; /*!< @description
	*	Y-axis of the LUT for the minimum valid length of an input lane clothoid (in met) \n\n
	*	\@asap_name: Y_ABPREP_ThReClthMinValLen_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ABPLBP_ThLnClthMinValLen_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_m_0_300_1em3_t	Y_ABPREP_ThReMinValLenHyst_met[6]; /*!< @description
	*	Minimum road edge valid length hysteresis \n\n
	*	\@asap_name: Y_ABPREP_ThReMinValLenHyst_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ABPLBP_ThLnClthMinValLen_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXCrvThresLDPHyst_1pm[8]; /*!< @description
	*	Hysteresis of the lane marking curvature validation. Speed Dependant. \n\n
	*	\@asap_name: Y_DPLSIA_VXCrvThresLDPHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXCrvThresLDPMax_1pm[8]; /*!< @description
	*	Maximal value of the lane marking curvature validation for the LDP. \n\n
	*	\@asap_name: Y_DPLSIA_VXCrvThresLDPMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXCrvThresLDWHyst_1pm[8]; /*!< @description
	*	Hysteresis of the lane marking curvature validation for the LDW. \n\n
	*	\@asap_name: Y_DPLSIA_VXCrvThresLDWHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXCrvThresLDWMax_1pm[8]; /*!< @description
	*	Maximal value of the lane marking curvature validation for the LDW. \n\n
	*	\@asap_name: Y_DPLSIA_VXCrvThresLDWMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXVehCrvThresHyst_1pm[8]; /*!< @description
	*	Hysteresis of the vehicle curvature validation for the LDP. \n\n
	*	\@asap_name: Y_DPLSIA_VXVehCrvThresHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXVehCrvThresLDWHyst_1pm[8]; /*!< @description
	*	Maximum value of the vehicle curvature validation for the LDW. \n\n
	*	\@asap_name: Y_DPLSIA_VXVehCrvThresLDWHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXVehCrvThresLDWMax_1pm[8]; /*!< @description
	*	Hysteresis of the vehicle curvature validation for the LDW. \n\n
	*	\@asap_name: Y_DPLSIA_VXVehCrvThresLDWMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPLSIA_VXVehCrvThresMax_1pm[8]; /*!< @description
	*	Maximum value of the vehicle curvature validation for the LDP. \n\n
	*	\@asap_name: Y_DPLSIA_VXVehCrvThresMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_CrvICDlcOffset_met[6]; /*!< @description
	*	InnerCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMI_CrvICDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMI_CrvICTlcOffset_sec[6]; /*!< @description
	*	InnerCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMI_CrvICTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_CrvOCDlcOffset_met[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMI_CrvOCDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMI_CrvOCTlcOffset_sec[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMI_CrvOCTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPLSMI_LWContrMaxDurScal_nu[6]; /*!< @description
	*	Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the LDP. \n\n
	*	\@asap_name: Y_DPLSMI_LWContrMaxDurScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_LWHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPLSMI_LWHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_LWNoHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPLSMI_LWNoHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPLSMI_LWTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPLSMI_LWTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMI_LWTrigTlcScalFact_nu[6]; /*!< @description
	*	Tlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPLSMI_LWTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMI_VXContrMaxDur_sec[8]; /*!< @description
	*	Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the LDP. \n\n
	*	\@asap_name: Y_DPLSMI_VXContrMaxDur_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_VXMD1TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMI_VXMD1TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMI_VXMD1TrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMI_VXMD1TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_VXMD2TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMI_VXMD2TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMI_VXMD2TrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMI_VXMD2TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMI_VXMD3TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 3. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMI_VXMD3TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMI_VXMD3TrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. Mode 3. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMI_VXMD3TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMI_VYTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPLSMI_VYTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMI_VYTrigTlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPLSMI_VYTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_CrvICDlcOffset_met[6]; /*!< @description
	*	InnerCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMW_CrvICDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMW_CrvICTlcOffset_sec[6]; /*!< @description
	*	InnerCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMW_CrvICTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_CrvOCDlcOffset_met[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMW_CrvOCDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMW_CrvOCTlcOffset_sec[6]; /*!< @description
	*	OuterCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPLSMW_CrvOCTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPLSMW_LWContrMaxDurScal_nu[6]; /*!< @description
	*	Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the LDW. \n\n
	*	\@asap_name: Y_DPLSMW_LWContrMaxDurScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_LWHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPLSMW_LWHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_LWNoHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPLSMW_LWNoHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMW_LWTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPLSMW_LWTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMW_LWTrigTlcScalFact_nu[6]; /*!< @description
	*	Tlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPLSMW_LWTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMW_VXContrMaxDur_sec[8]; /*!< @description
	*	Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the LDW. \n\n
	*	\@asap_name: Y_DPLSMW_VXContrMaxDur_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_VXMD1TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMW_VXMD1TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMW_VXMD1TrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMW_VXMD1TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_VXMD2TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMW_VXMD2TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMW_VXMD2TrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMW_VXMD2TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLSMW_VXMD3TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 3. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMW_VXMD3TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPLSMW_VXMD3TrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. Mode 3. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPLSMW_VXMD3TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMW_VYTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPLSMW_VYTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPLSMW_VYTrigTlcScalFact_nu[6]; /*!< @description
	*	Tlc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPLSMW_VYTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLTTG_CrvICTgtOffset_met[6]; /*!< @description
	*	Target Offset in inner curves \n\n
	*	\@asap_name: Y_DPLTTG_CrvICTgtOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPLTTG_CrvOCTgtOffset_met[6]; /*!< @description
	*	Target Offset in outer curves \n\n
	*	\@asap_name: Y_DPLTTG_CrvOCTgtOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m1000_1000_1em3_t	Y_DPLTTG_LWTargetLatDist_met[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_DPLTTG_LWTargetLatDist_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_CrvICPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an inner curve. \n\n
	*	\@asap_name: Y_DPLTVG_CrvICPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_CrvOCPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an outer curve. \n\n
	*	\@asap_name: Y_DPLTVG_CrvOCPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_D2TPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Distance to target dependant. \n\n
	*	\@asap_name: Y_DPLTVG_D2TPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_DistY_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_VXPlanHorizonScal_nu[8]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. VX dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VXPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_DPLTVG_VXWeightEndtime_nu[8]; /*!< @description
	*	Weight of the end time for the calculation in the TRJPLN. Speed dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VXWeightEndtime_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_VYMD1DeratingLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the LDP function when Driving Mode is either equal to 1 or to a default value. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VYMD1DeratingLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_VYMD2DeratingLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the LDP function when Driving Mode is equal to 2. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VYMD2DeratingLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPLTVG_VYMD3DeratingLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the LDP function when Driving Mode is equal to 3. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VYMD3DeratingLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	Y_DPLTVG_VYPlanningHorizon_sec[6]; /*!< @description
	*	Planning Horizon for the calculation in the TRJPLN. VY dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VYPlanningHorizon_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	Y_DPLTVG_VYStrWhStifRIGrad_1ps[6]; /*!< @description
	*	Standard Steering Wheel Stiffness Ramp In Gradient. VY dependant. \n\n
	*	\@asap_name: Y_DPLTVG_VYStrWhStifRIGrad_1ps \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSIA_CrvVehCrvTurnOn_sec[6]; /*!< @description
	*	Turn on delay time for the vehicle curvature activation condition. \n\n
	*	\@asap_name: Y_DPRSIA_CrvVehCrvTurnOn_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPRSIA_VXLnCrvThresHyst_1pm[8]; /*!< @description
	*	Hysteresis of the lane marking curvature validation. \n\n
	*	\@asap_name: Y_DPRSIA_VXLnCrvThresHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPRSIA_VXLnCrvThresMax_1pm[8]; /*!< @description
	*	Maximal value of the lane marking curvature validation. \n\n
	*	\@asap_name: Y_DPRSIA_VXLnCrvThresMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPRSIA_VXReCrvThresHyst_1pm[8]; /*!< @description
	*	Hysteresis of the road edge curvature validation. \n\n
	*	\@asap_name: Y_DPRSIA_VXReCrvThresHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPRSIA_VXReCrvThresMax_1pm[8]; /*!< @description
	*	Maximal value of the road edge curvature validation. \n\n
	*	\@asap_name: Y_DPRSIA_VXReCrvThresMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPRSIA_VXVehCrvThresHyst_1pm[8]; /*!< @description
	*	Hysteresis of the vehicle curvature validation. \n\n
	*	\@asap_name: Y_DPRSIA_VXVehCrvThresHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_DPRSIA_VXVehCrvThresMax_1pm[8]; /*!< @description
	*	Maximal value of the vehicle curvature validation. \n\n
	*	\@asap_name: Y_DPRSIA_VXVehCrvThresMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_CrvICDlcOffset_met[6]; /*!< @description
	*	InnerCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvICDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_CrvICDrcOffset_met[6]; /*!< @description
	*	InnerCurve Drc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvICDrcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_CrvICTlcOffset_sec[6]; /*!< @description
	*	InnerCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvICTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_CrvICTrcOffset_sec[6]; /*!< @description
	*	InnerCurve Trc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvICTrcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_CrvOCDlcOffset_met[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvOCDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_CrvOCDrcOffset_met[6]; /*!< @description
	*	OuterCurve Drc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvOCDrcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_CrvOCTlcOffset_sec[6]; /*!< @description
	*	OuterCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvOCTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_CrvOCTrcOffset_sec[6]; /*!< @description
	*	OuterCurve Trc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMI_CrvOCTrcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMI_LWContrMaxDurLnScal_nu[6]; /*!< @description
	*	Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDP for the use cases in which a lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMI_LWContrMaxDurLnScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMI_LWContrMaxDurReScal_nu[6]; /*!< @description
	*	Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDP for the use cases in which no lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMI_LWContrMaxDurReScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_LWHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPRSMI_LWHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_LWNoHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPRSMI_LWNoHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_LWTrigDlcScalFact_nu[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_DPRSMI_LWTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_LWTrigDrcScalFact_nu[6]; /*!< @description
	*	Lane Width Drc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPRSMI_LWTrigDrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_LWTrigTlcScalFact_nu[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_DPRSMI_LWTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_LWTrigTrcScalFact_nu[6]; /*!< @description
	*	Lane Width Trc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPRSMI_LWTrigTrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXContrMaxDurLn_sec[8]; /*!< @description
	*	Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDP for the use cases in which a lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMI_VXContrMaxDurLn_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXContrMaxDurRe_sec[8]; /*!< @description
	*	Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDP for the use cases in which no lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMI_VXContrMaxDurRe_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_VXMD1TrigDlc_met[8]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_DPRSMI_VXMD1TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_VXMD1TrigDrc_met[8]; /*!< @description
	*	MD1 Drc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD1TrigDrc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXMD1TrigTlc_sec[8]; /*!< @description
	*	MD1 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD1TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXMD1TrigTrc_sec[8]; /*!< @description
	*	Trigger time to road edge crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPRSMI_VXMD1TrigTrc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_VXMD2TrigDlc_met[8]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_DPRSMI_VXMD2TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_VXMD2TrigDrc_met[8]; /*!< @description
	*	MD2 Drc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD2TrigDrc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXMD2TrigTlc_sec[8]; /*!< @description
	*	MD2 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD2TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXMD2TrigTrc_sec[8]; /*!< @description
	*	Trigger time to road edge crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPRSMI_VXMD2TrigTrc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_VXMD3TrigDlc_met[8]; /*!< @description
	*	MD3 Dlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD3TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMI_VXMD3TrigDrc_met[8]; /*!< @description
	*	MD3 Drc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD3TrigDrc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXMD3TrigTlc_sec[8]; /*!< @description
	*	MD3 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD3TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMI_VXMD3TrigTrc_sec[8]; /*!< @description
	*	MD3 Trc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VXMD3TrigTrc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_VYTrigDlcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Dlc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VYTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_VYTrigDrcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Drc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VYTrigDrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_VYTrigTlcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Tlc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VYTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_DPRSMI_VYTrigTrcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Trc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMI_VYTrigTrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_CrvICDlcOffset_met[6]; /*!< @description
	*	InnerCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvICDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_CrvICDrcOffset_met[6]; /*!< @description
	*	InnerCurve Drc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvICDrcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_CrvICTlcOffset_sec[6]; /*!< @description
	*	InnerCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvICTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_CrvICTrcOffset_sec[6]; /*!< @description
	*	InnerCurve Trc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvICTrcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_CrvOCDlcOffset_met[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvOCDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_CrvOCDrcOffset_met[6]; /*!< @description
	*	OuterCurve Drc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvOCDrcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_CrvOCTlcOffset_sec[6]; /*!< @description
	*	OuterCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvOCTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_CrvOCTrcOffset_sec[6]; /*!< @description
	*	OuterCurve Trc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_DPRSMW_CrvOCTrcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_LWContrMaxDurLnScal_nu[6]; /*!< @description
	*	Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDW for the use cases in which a lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMW_LWContrMaxDurLnScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_LWContrMaxDurReScal_nu[6]; /*!< @description
	*	Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDW for the use cases in which no lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMW_LWContrMaxDurReScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_LWHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPRSMW_LWHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_LWNoHazardFinishTol_met[6]; /*!< @description
	*	Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
	*	\@asap_name: Y_DPRSMW_LWNoHazardFinishTol_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_LWTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPRSMW_LWTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_LWTrigDrcScalFact_nu[6]; /*!< @description
	*	Lane Width Drc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPRSMW_LWTrigDrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_LWTrigTlcScalFact_nu[6]; /*!< @description
	*	Tlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPRSMW_LWTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_LWTrigTrcScalFact_nu[6]; /*!< @description
	*	Lane Width Trc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_DPRSMW_LWTrigTrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXContrMaxDurLn_sec[8]; /*!< @description
	*	Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDW for the use cases in which a lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMW_VXContrMaxDurLn_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXContrMaxDurRe_sec[8]; /*!< @description
	*	Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDW for the use cases in which no lane marking is present next to the road edge. \n\n
	*	\@asap_name: Y_DPRSMW_VXContrMaxDurRe_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_VXMD1TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPRSMW_VXMD1TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_VXMD1TrigDrc_met[8]; /*!< @description
	*	MD1 Drc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD1TrigDrc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXMD1TrigTlc_sec[8]; /*!< @description
	*	MD1 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD1TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXMD1TrigTrc_sec[8]; /*!< @description
	*	Trigger time to road edge crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPRSMW_VXMD1TrigTrc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_VXMD2TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPRSMW_VXMD2TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_VXMD2TrigDrc_met[8]; /*!< @description
	*	MD2 Drc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD2TrigDrc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXMD2TrigTlc_sec[8]; /*!< @description
	*	MD2 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD2TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXMD2TrigTrc_sec[8]; /*!< @description
	*	Trigger time to road edge crossing. Mode 2. SpeedX dependant. \n\n
	*	\@asap_name: Y_DPRSMW_VXMD2TrigTrc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_VXMD3TrigDlc_met[8]; /*!< @description
	*	MD3 Dlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD3TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_DPRSMW_VXMD3TrigDrc_met[8]; /*!< @description
	*	MD3 Drc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD3TrigDrc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXMD3TrigTlc_sec[8]; /*!< @description
	*	MD3 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD3TrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRSMW_VXMD3TrigTrc_sec[8]; /*!< @description
	*	MD3 Trc Trigger Threshold - Ego-velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VXMD3TrigTrc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_VYTrigDlcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Dlc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VYTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_VYTrigDrcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Drc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VYTrigDrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_VYTrigTlcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Tlc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VYTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_DPRSMW_VYTrigTrcScalFact_nu[6]; /*!< @description
	*	Lateral velocity Trc Scaling Factor - Lateral velocity Dependant \n\n
	*	\@asap_name: Y_DPRSMW_VYTrigTrcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPRTVG_CrvPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant. \n\n
	*	\@asap_name: Y_DPRTVG_CrvPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPRTVG_D2TPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Distance to Target dependant. \n\n
	*	\@asap_name: Y_DPRTVG_D2TPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_DistY_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPRTVG_VXPlanHorizonScal_nu[8]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. VX dependant. \n\n
	*	\@asap_name: Y_DPRTVG_VXPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_DPRTVG_VXWeightEndtime_nu[8]; /*!< @description
	*	Weight of the target final time in the trajectory planning. Speed dependent. \n\n
	*	\@asap_name: Y_DPRTVG_VXWeightEndtime_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPRTVG_VYMD1DeratingLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the RDP function when Driving Mode is either equal to 1 or to a default value. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_DPRTVG_VYMD1DeratingLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPRTVG_VYMD2DeratingLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the RDP function when Driving Mode is equal to 2. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_DPRTVG_VYMD2DeratingLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_DPRTVG_VYMD3DeratingLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the RDP function when Driving Mode is equal to 3. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_DPRTVG_VYMD3DeratingLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	Y_DPRTVG_VYPlanHorizonLn_sec[6]; /*!< @description
	*	Planning Horizon for the calculation in the TRJPLN. Lateral Velocity dependant. Trigger due to road edge + lane marking. \n\n
	*	\@asap_name: Y_DPRTVG_VYPlanHorizonLn_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t	Y_DPRTVG_VYPlanHorizonRe_sec[6]; /*!< @description
	*	Planning Horizon for the calculation in the TRJPLN. Lateral Velocity dependant. Trigger due to road edge only. \n\n
	*	\@asap_name: Y_DPRTVG_VYPlanHorizonRe_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	Y_DPRTVG_VYStrWhStifRIGrad_1ps[6]; /*!< @description
	*	Standard Steering Wheel Stiffness Ramp In Gradient. Lateral velocity dependant. \n\n
	*	\@asap_name: Y_DPRTVG_VYStrWhStifRIGrad_1ps \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_Nm_m100_100_1em3_t	Y_DRMHOD_HandsOffTqLim_Nm[16]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: Y_DRMHOD_HandsOffTqLim_Nm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_DRMHOD_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_Nm_m100_100_1em3_t	Y_DRMHOD_HandsOnTqLim_Nm[16]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: Y_DRMHOD_HandsOnTqLim_Nm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_DRMHOD_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: Nm \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_DRMHOD_VXLowPassC_nu[8]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: Y_DRMHOD_VXLowPassC_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_LCRSIA_VXCrvThresALCAHyst_1pm[8]; /*!< @description
	*	Hysteresis of the lane marking curvature validation. Speed Dependant. \n\n
	*	\@asap_name: Y_LCRSIA_VXCrvThresALCAHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_LCRSIA_VXCrvThresALCAMax_1pm[8]; /*!< @description
	*	Maximal value of the lane marking curvature validation for the ALCA. \n\n
	*	\@asap_name: Y_LCRSIA_VXCrvThresALCAMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_LCRSIA_VXVehCrvThresHyst_1pm[8]; /*!< @description
	*	Hysteresis of the vehicle curvature validation for the ALCA. \n\n
	*	\@asap_name: Y_LCRSIA_VXVehCrvThresHyst_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_LCRSIA_VXVehCrvThresMax_1pm[8]; /*!< @description
	*	Maximum value of the vehicle curvature validation for the ALCA. \n\n
	*	\@asap_name: Y_LCRSIA_VXVehCrvThresMax_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_m_m15_15_1em3_t	Y_LCRSMI_CrvICDlcOffset_met[6]; /*!< @description
	*	InnerCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_LCRSMI_CrvICDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_LCRSMI_CrvICTlcOffset_sec[6]; /*!< @description
	*	InnerCurve Tlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_LCRSMI_CrvICTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_m_m15_15_1em3_t	Y_LCRSMI_CrvOCDlcOffset_met[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_LCRSMI_CrvOCDlcOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_LCRSMI_CrvOCTlcOffset_sec[6]; /*!< @description
	*	OuterCurve Dlc Offset - Curvature Dependant \n\n
	*	\@asap_name: Y_LCRSMI_CrvOCTlcOffset_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_LCRSMI_LWTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_LCRSMI_LWTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t	Y_LCRSMI_LWTrigTlcScalFact_nu[6]; /*!< @description
	*	Tlc Scaling Factor - Lane Width Dependant \n\n
	*	\@asap_name: Y_LCRSMI_LWTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	Y_LCRSMI_VXMD1TrigDlc_met[8]; /*!< @description
	*	Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
	*	\@asap_name: Y_LCRSMI_VXMD1TrigDlc_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t	Y_LCRSMI_VXTrigTlc_sec[8]; /*!< @description
	*	Trigger time to lane crossing. SpeedX dependant. \n\n
	*	\@asap_name: Y_LCRSMI_VXTrigTlc_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_LCRSMI_VYTrigDlcScalFact_nu[6]; /*!< @description
	*	Dlc Scaling Factor - Lateral Velocity  Dependant \n\n
	*	\@asap_name: Y_LCRSMI_VYTrigDlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_LCRSMI_VYTrigTlcScalFact_nu[6]; /*!< @description
	*	Tlc Scaling Factor - Lateral Velocity  Dependant \n\n
	*	\@asap_name: Y_LCRSMI_VYTrigTlcScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t	Y_LCRTTG_CrvICTgtOffset_met[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_LCRTTG_CrvICTgtOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t	Y_LCRTTG_CrvOCTgtOffset_met[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_LCRTTG_CrvOCTgtOffset_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m1000_1000_1em3_t	Y_LCRTTG_LWTargetLatDist_met[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_LCRTTG_LWTargetLatDist_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: -1000 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_CrvICPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an inner curve. \n\n
	*	\@asap_name: Y_LCRTVG_CrvICPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_CrvOCPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an outer curve. \n\n
	*	\@asap_name: Y_LCRTVG_CrvOCPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_Curvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_D2TPlanHorizonScal_nu[6]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. Distance to target dependant. \n\n
	*	\@asap_name: Y_LCRTVG_D2TPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_DistY_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_VXPlanHorizonScal_nu[8]; /*!< @description
	*	Planning Horizon Scaling Factor for the calculation in the TRJPLN. VX dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VXPlanHorizonScal_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_LCRTVG_VXWeightEndtime_nu[8]; /*!< @description
	*	Weight of the end time for the calculation in the TRJPLN. Speed dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VXWeightEndtime_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_VYMD1DerLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the LDP function when Driving Mode is either equal to 1 or to a default value. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VYMD1DerLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_VYMD2DerLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the LDP function when Driving Mode is equal to 2. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VYMD2DerLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_LCRTVG_VYMD3DerLevel_nu[6]; /*!< @description
	*	DMC Derating Level of the LDP function when Driving Mode is equal to 3. Lateral Velocity dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VYMD3DerLevel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	Y_LCRTVG_VYPlanningHorizon_sec[6]; /*!< @description
	*	Planning Horizon for the calculation in the TRJPLN. VY dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VYPlanningHorizon_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_Pers_0_10000_1em3_t	Y_LCRTVG_VYStrWhStifRIGrad_1ps[6]; /*!< @description
	*	Standard Steering Wheel Stiffness Ramp In Gradient. VY dependant. \n\n
	*	\@asap_name: Y_LCRTVG_VYStrWhStifRIGrad_1ps \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_VelY_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_LSMPT1TimePosY_sec[14]; /*!< @description
	*	Lookup table of speed dependent PT1 time constant values for lateral position in Low Speed Mode (not as Kalman Input) \n\n
	*	\@asap_name: Y_ODPFOH_LSMPT1TimePosY_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelXPT1_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_m_0_300_1em3_t	Y_ODPFOH_MaxObjDistLSM_met[14]; /*!< @description
	*	Lookup table to define speed dependent maximum object distance for Low Speed Mode \n\n
	*	\@asap_name: Y_ODPFOH_MaxObjDistLSM_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_100_1em4_t	Y_ODPFOH_MaxSampleAge_sec[14]; /*!< @description
	*	Maximim age for a saved object data sample point to be treated as valid \n\n
	*	\@asap_name: Y_ODPFOH_MaxSampleAge_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_0_300_1em3_t	Y_ODPFOH_MinTrajectoryLength_met[14]; /*!< @description
	*	Lookup table to define speed dependent minimum trajectory length for Kalman Filter input \n\n
	*	\@asap_name: Y_ODPFOH_MinTrajectoryLength_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1StrEstCrv_sec[7]; /*!< @description
	*	Lookup table of straight estimation dependent PT1 time constant values for curvature \n\n
	*	\@asap_name: Y_ODPFOH_PT1StrEstCrv_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_StraightEstim_perc \n
	*	\@axis_x_unit: - \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1StrEstHead_sec[7]; /*!< @description
	*	Lookup table of straight estimation dependent PT1 time constant values for curvature \n\n
	*	\@asap_name: Y_ODPFOH_PT1StrEstHead_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_StraightEstim_perc \n
	*	\@axis_x_unit: - \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1StrEstPosY0_sec[7]; /*!< @description
	*	Lookup table of straight estimation dependent PT1 time constant values for curvature \n\n
	*	\@asap_name: Y_ODPFOH_PT1StrEstPosY0_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_StraightEstim_perc \n
	*	\@axis_x_unit: - \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1TimeConstCrv_sec[14]; /*!< @description
	*	Lookup table of speed dependent PT1 time constant values for curvature \n\n
	*	\@asap_name: Y_ODPFOH_PT1TimeConstCrv_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelXPT1_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1TimeConstHead_sec[14]; /*!< @description
	*	Lookup table of speed dependent PT1 time constant values for heading \n\n
	*	\@asap_name: Y_ODPFOH_PT1TimeConstHead_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelXPT1_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1TimeConstPosY0_sec[14]; /*!< @description
	*	Lookup table of speed dependent PT1 time constant values for lateral position \n\n
	*	\@asap_name: Y_ODPFOH_PT1TimeConstPosY0_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelXPT1_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1TimeConstPosY_sec[14]; /*!< @description
	*	Lookup table of speed dependent PT1 time constant values for lateral position \n\n
	*	\@asap_name: Y_ODPFOH_PT1TimeConstPosY_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelXPT1_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_s_0p06_10_1em3_t	Y_ODPFOH_PT1TimeConstYawRate_sec[14]; /*!< @description
	*	Lookup table of speed dependent PT1 time constant values for input yaw rate \n\n
	*	\@asap_name: Y_ODPFOH_PT1TimeConstYawRate_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.06 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_ODPFOH_WeightCrvPolyfit_nu[14]; /*!< @description
	*	Lookup table of speed dependent weighting factor for polyfit coefficients [0..1] \n\n
	*	\@asap_name: Y_ODPFOH_WeightCrvPolyfit_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_ODPFOH_WeightLastPolyfit_nu[7]; /*!< @description
	*	Lookup table of speed dependent weighting factor with last polyfit [0..1] \n\n
	*	\@asap_name: Y_ODPFOH_WeightLastPolyfit_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOH_StraightEstim_perc \n
	*	\@axis_x_unit: - \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_150_1em3_t	Y_ODPFOP_LongDistMax_met[14]; /*!< @description
	*	Maximum longitudinal distance for object validation \n\n
	*	\@asap_name: Y_ODPFOP_LongDistMax_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_ODPFOP_LongDistMaxVel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 150
	*/
	
	f32_degps_0_360_1em2_t	Y_TCTCLM_GrdLimitDeltaFCmd_deg[15]; /*!< @description
	*	Absolut value of the gradient limitation of the set value send to the LaDMC \n\n
	*	\@asap_name: Y_TCTCLM_GrdLimitDeltaFCmd_deg \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: �/s \n
	*	\@min: 0 \n
	*	\@max: 360
	*/
	
	f32_1pms_0_10_1em6_t	Y_TCTCLM_GrdLimitFbcDc_1pms[15]; /*!< @description
	*	Absolute value / (1/(m*s)) of the maximal allowed gradient of the control signal "Feedback Controller + Disturbance Compensator" send to the LaDMC \n\n
	*	\@asap_name: Y_TCTCLM_GrdLimitFbcDc_1pms \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_1pms_0_10_1em6_t	Y_TCTCLM_GrdLimitFfc_1pms[15]; /*!< @description
	*	Absolute value / (1/(m*s)) of the maximal allowed gradient of the control signal Feedforward Controller" send to the LaDMC \n\n
	*	\@asap_name: Y_TCTCLM_GrdLimitFfc_1pms \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/ms \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_TCTCLM_GrdLimitGain_nu[8]; /*!< @description
	*	Gain of the gradient limitation in dependence on the controlling function \n\n
	*	\@asap_name: Y_TCTCLM_GrdLimitGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_ControllingFunction_nu \n
	*	\@axis_x_unit: - \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_deg_m90_90_1em8_t	Y_TCTCLM_LimitDeltaFCmd_deg[15]; /*!< @description
	*	Absolute value of the saturation of the set value send to the LaDMC \n\n
	*	\@asap_name: Y_TCTCLM_LimitDeltaFCmd_deg \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: � \n
	*	\@min: -90 \n
	*	\@max: 90
	*/
	
	f32_1pm_0_0p5001_1em8_t	Y_TCTCLM_LimitFbcDc_1pm[15]; /*!< @description
	*	Absolute value / (1/m) of the maximal allowed control signal "Feedback Controller + Disturbance Compensator" send to the LaDMC \n\n
	*	\@asap_name: Y_TCTCLM_LimitFbcDc_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.5001
	*/
	
	f32_1pm_0_0p5001_1em8_t	Y_TCTCLM_LimitFfc_1pm[15]; /*!< @description
	*	Absolute value / (1/m) of the maximal allowed control signal "Feedforward Controller" send to the LaDMC \n\n
	*	\@asap_name: Y_TCTCLM_LimitFfc_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: 0 \n
	*	\@max: 0.5001
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_TCTCLM_LimitGain_nu[8]; /*!< @description
	*	Gain of the saturation in dependence on the controlling function \n\n
	*	\@asap_name: Y_TCTCLM_LimitGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTCLM_ControllingFunction_nu \n
	*	\@axis_x_unit: - \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_0p78539816_1em8_t	Y_TCTDTE_CroWindDeltaSetSat_rad[13]; /*!< @description
	*	Absolute value of the saturation of the control signal used to compensate the crosswind / rad in dependence on the velocity \n\n
	*	\@asap_name: Y_TCTDTE_CroWindDeltaSetSat_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_0_0p78539816_1em8_t	Y_TCTDTE_DeltaSetBnkAglSat_rad[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTDTE_DeltaSetBnkAglSat_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 0.78539816
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_TCTDTE_DeltaSetDstrbGain_nu[13]; /*!< @description
	*	Gain of the Disturbance Compensator set value \n\n
	*	\@asap_name: Y_TCTDTE_DeltaSetDstrbGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t	Y_TCTDTE_DeltaSetDstrbSat_rad[13]; /*!< @description
	*	Saturation of the delta command needed to compensate disturbances \n\n
	*	\@asap_name: Y_TCTDTE_DeltaSetDstrbSat_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_NoUnit_0_65535_1em3_t	Y_TCTDTE_GLaDmcDenS0_nu[13]; /*!< @description
	*	Coefficient of the Lateral DMC transfer function's denominator concerning s^0 \n\n
	*	\@asap_name: Y_TCTDTE_GLaDmcDenS0_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t	Y_TCTDTE_GLaDmcDenS1_nu[13]; /*!< @description
	*	Coefficient of the Lateral DMC transfer function's denominator concerning s^1 \n\n
	*	\@asap_name: Y_TCTDTE_GLaDmcDenS1_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t	Y_TCTDTE_GLaDmcDenS2_nu[13]; /*!< @description
	*	Coefficient of the Lateral DMC transfer function's denominator concerning s^2 \n\n
	*	\@asap_name: Y_TCTDTE_GLaDmcDenS2_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t	Y_TCTDTE_GLaDmcDenS3_nu[13]; /*!< @description
	*	Coefficient of the Lateral DMC transfer function's denominator concerning s^3 \n\n
	*	\@asap_name: Y_TCTDTE_GLaDmcDenS3_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t	Y_TCTDTE_GLaDmcNumS0_nu[13]; /*!< @description
	*	Coefficient of the Lateral DMC transfer function's numerator concerning s^0 \n\n
	*	\@asap_name: Y_TCTDTE_GLaDmcNumS0_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t	Y_TCTDTE_GLaDmcNumS1_nu[13]; /*!< @description
	*	Coefficient of the Lateral DMC transfer function's numerator concerning s^1 \n\n
	*	\@asap_name: Y_TCTDTE_GLaDmcNumS1_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_1_1em6_t	Y_TCTDTE_GainKappaDstrbReq_nu[13]; /*!< @description
	*	Gain of the calculated curvature needed to compensate the disturbances in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTDTE_GainKappaDstrbReq_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_degm_0_5000_1em2_t	Y_TCTDTE_KappaAngle_degm[12]; /*!< @description
	*	Grid points of the y-Axis of the LaDMC Look Up Table "Kappa To Angle". \n
	*	Input: Curvature /m \n
	*	Output: Steer Angle /degree \n\n
	*	\@asap_name: Y_TCTDTE_KappaAngle_degm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_KappaAngle_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: degm \n
	*	\@min: 0 \n
	*	\@max: 5000
	*/
	
	f32_1pm_m0p15_0p15_1em8_t	Y_TCTDTE_VelXToMaxCrv_1pm[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTDTE_VelXToMaxCrv_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTDTE_InputVehVelSat_met \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	Y_TCTEST_CrObsLueGain11_nu[13]; /*!< @description
	*	First element of first column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
	*	\@asap_name: Y_TCTEST_CrObsLueGain11_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	Y_TCTEST_CrObsLueGain12_nu[13]; /*!< @description
	*	First element of second column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
	*	\@asap_name: Y_TCTEST_CrObsLueGain12_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	Y_TCTEST_CrObsLueGain21_nu[13]; /*!< @description
	*	Second element of first column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
	*	\@asap_name: Y_TCTEST_CrObsLueGain21_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	Y_TCTEST_CrObsLueGain22_nu[13]; /*!< @description
	*	Second element of second column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
	*	\@asap_name: Y_TCTEST_CrObsLueGain22_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	Y_TCTEST_CrObsLueGain31_nu[13]; /*!< @description
	*	Third element of first column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
	*	\@asap_name: Y_TCTEST_CrObsLueGain31_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t	Y_TCTEST_CrObsLueGain32_nu[13]; /*!< @description
	*	Third element of second column of gain matrix of the Luenberger observer to estimate the crosswind \n\n
	*	\@asap_name: Y_TCTEST_CrObsLueGain32_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_Perc_0_100_1em3_t	Y_TCTEST_HdrMeanThreshOf_perc[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_HdrMeanThreshOf_perc \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Perc_0_100_1em3_t	Y_TCTEST_HdrMeanThreshSf_perc[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_HdrMeanThreshSf_perc \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Perc_0_100_1em3_t	Y_TCTEST_HdrMeanThresh_perc[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_HdrMeanThresh_perc \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Perc_0_100_1em3_t	Y_TCTEST_HdrMulThreshOf_perc[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_HdrMulThreshOf_perc \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Perc_0_100_1em3_t	Y_TCTEST_HdrMulThreshSf_perc[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_HdrMulThreshSf_perc \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Perc_0_100_1em3_t	Y_TCTEST_HdrMulThresh_perc[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_HdrMulThresh_perc \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_KObsLueGain11_nu[13]; /*!< @description
	*	First element of first column of gain matrix of the Luenberger observer to estimate the curvature \n\n
	*	\@asap_name: Y_TCTEST_KObsLueGain11_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_KObsLueGain21_nu[13]; /*!< @description
	*	Second element of first column of gain matrix of the Luenberger observer to estimate the curvature \n\n
	*	\@asap_name: Y_TCTEST_KObsLueGain21_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_KObsLueGain31_nu[13]; /*!< @description
	*	Third element of first column of gain matrix of the Luenberger observer to estimate the curvature \n\n
	*	\@asap_name: Y_TCTEST_KObsLueGain31_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_rad_0_3p14_1em3_t	Y_TCTEST_PlObsDeltaThetaSat_rad[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_PlObsDeltaThetaSat_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 3.14
	*/
	
	f32_m_0_10_1em3_t	Y_TCTEST_PlObsDeltaYSat_m[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_PlObsDeltaYSat_m \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain11_nu[13]; /*!< @description
	*	First element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain11_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain12_nu[13]; /*!< @description
	*	First element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain12_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain13_nu[13]; /*!< @description
	*	First element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain13_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain21_nu[13]; /*!< @description
	*	Second element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain21_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain22_nu[13]; /*!< @description
	*	Second element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain22_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain23_nu[13]; /*!< @description
	*	Second element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain23_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain31_nu[13]; /*!< @description
	*	Third element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain31_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain32_nu[13]; /*!< @description
	*	Third element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain32_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain33_nu[13]; /*!< @description
	*	Third element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain33_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain41_nu[13]; /*!< @description
	*	Fourth element of first column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain41_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain42_nu[13]; /*!< @description
	*	Fourth element of second column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain42_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_PlObsLueGain43_nu[13]; /*!< @description
	*	Fourth element of third column of gain matrix of the Luenberger observer to estimate the course angle \n\n
	*	\@asap_name: Y_TCTEST_PlObsLueGain43_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_0_10_1em3_t	Y_TCTEST_PreviewDistX_met[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_PreviewDistX_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_3p14_1em3_t	Y_TCTEST_SObsBetaSat_rad[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTEST_SObsBetaSat_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_InputVehVelSat_met \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 3.14
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_SObsLueGain1_nu[13]; /*!< @description
	*	First element of the Gain-Vector of the Luenberger Observer used to estimate the Side Slip Angle. \n\n
	*	\@asap_name: Y_TCTEST_SObsLueGain1_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_m100_100_1em3_t	Y_TCTEST_SObsLueGain2_nu[13]; /*!< @description
	*	Second element of the Gain-Vector of the Luenberger Observer used to estimate the Side Slip Angle. \n\n
	*	\@asap_name: Y_TCTEST_SObsLueGain2_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTEST_StwGearRatio_nu[6]; /*!< @description
	*	Steering Gear Ratio of the vehicle, corresponding grid points are located in X_TCTDTE_StwGearRatio_rad. \n\n
	*	\@asap_name: Y_TCTEST_StwGearRatio_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTEST_StwGearRatio_rad \n
	*	\@axis_x_unit: rad \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_100_1em4_t	Y_TCTLGC_CacDGain_sec[15]; /*!< @description
	*	Gain of the Course Angle Controller's differential part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacDGain_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_CacDT1_sec[15]; /*!< @description
	*	Time constant of the first order low pass needed to filter the Course Angle Controller's D-part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacDT1_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_Pers_0_1000_1em3_t	Y_TCTLGC_CacIGain_1ps[15]; /*!< @description
	*	Gain of the Course Angle Controller's integral part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacIGain_1ps \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_s_0_100_1em4_t	Y_TCTLGC_CacOfDGain_sec[15]; /*!< @description
	*	Gain of the Course Angle Controller's differential part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacOfDGain_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_CacOfDT1_sec[15]; /*!< @description
	*	Time constant of the first order low pass needed to filter the Course Angle Controller's D-part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacOfDT1_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_Pers_0_1000_1em3_t	Y_TCTLGC_CacOfIGain_1ps[15]; /*!< @description
	*	Gain of the Course Angle Controller's integral part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacOfIGain_1ps \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_CacOfPGain_nu[15]; /*!< @description
	*	Course Angle Controller P-Gain for object following mode \n\n
	*	\@asap_name: Y_TCTLGC_CacOfPGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_CacOfPT1Gain_nu[15]; /*!< @description
	*	Gain of the Course Angle Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_CacOfPT1Gain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_CacOfPT1Time_sec[15]; /*!< @description
	*	Time Constant of the Course Angle Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_CacOfPT1Time_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_2_1em3_t	Y_TCTLGC_CacPGainCrv_nu[9]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTLGC_CacPGainCrv_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_CrvFFC_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_CacPGain_nu[15]; /*!< @description
	*	Proportional gain of the Course Angle Controller in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacPGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_CacPT1Gain_nu[15]; /*!< @description
	*	Gain of the Course Angle Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_CacPT1Gain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_CacPT1Time_sec[15]; /*!< @description
	*	Time Constant of the Course Angle Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_CacPT1Time_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_s_0_100_1em4_t	Y_TCTLGC_CacSfDGain_sec[15]; /*!< @description
	*	Gain of the Course Angle Controller's differential part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacSfDGain_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_CacSfDT1_sec[15]; /*!< @description
	*	Time constant of the first order low pass needed to filter the Course Angle Controller's D-part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacSfDT1_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_Pers_0_1000_1em3_t	Y_TCTLGC_CacSfIGain_1ps[15]; /*!< @description
	*	Gain of the Course Angle Controller's integral part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacSfIGain_1ps \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: 0 \n
	*	\@max: 1000
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_CacSfPGain_nu[15]; /*!< @description
	*	Proportional gain of the Course Angle Controller in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_CacSfPGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_CacSfPT1Gain_nu[15]; /*!< @description
	*	Gain of the Course Angle Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_CacSfPT1Gain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_CacSfPT1Time_sec[15]; /*!< @description
	*	Time Constant of the Course Angle Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_CacSfPT1Time_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_NoUnit_0_5_1em3_t	Y_TCTLGC_DynBacGain_nu[6]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTLGC_DynBacGain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_CtrlErrDistY_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	f32_NoUnit_0_100000_1em3_t	Y_TCTLGC_GLaDmcCompNumS0_nu[15]; /*!< @description
	*	s^0 coefficient of the approximated LaDMC transfer function's numerator \n\n
	*	\@asap_name: Y_TCTLGC_GLaDmcCompNumS0_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100000_1em3_t	Y_TCTLGC_GLaDmcCompNumS1_nu[15]; /*!< @description
	*	s^1 coefficient of the approximated LaDMC transfer function's numerator \n\n
	*	\@asap_name: Y_TCTLGC_GLaDmcCompNumS1_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_Pers_m1000_0_1em4_t	Y_TCTLGC_GLaDmcCompPole1_nu[15]; /*!< @description
	*	Pole 1 of the approximated LaDMC transfer function \n\n
	*	\@asap_name: Y_TCTLGC_GLaDmcCompPole1_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: -1000 \n
	*	\@max: 0
	*/
	
	f32_Pers_m1000_0_1em4_t	Y_TCTLGC_GLaDmcCompPole2_nu[15]; /*!< @description
	*	Pole 2 of the approximated LaDMC transfer function \n\n
	*	\@asap_name: Y_TCTLGC_GLaDmcCompPole2_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: 1/s \n
	*	\@min: -1000 \n
	*	\@max: 0
	*/
	
	f32_radspm_0_100_1em4_t	Y_TCTLGC_LdcDGain_radspm[15]; /*!< @description
	*	Gain of the Y-Coorindate Controller's differential part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcDGain_radspm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rads/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_LdcDT1_sec[15]; /*!< @description
	*	Time constant of the first order low pass needed to filter the Y-Coorindate Controller's D-part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcDT1_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radpsm_0_100_1em4_t	Y_TCTLGC_LdcIGain_radpsm[15]; /*!< @description
	*	Gain of the Y-Coordinate Controller's integral part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcIGain_radpsm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad/sm \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radspm_0_100_1em4_t	Y_TCTLGC_LdcOfDGain_radspm[15]; /*!< @description
	*	Gain of the Y-Coorindate Controller's differential part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcOfDGain_radspm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rads/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_LdcOfDT1_sec[15]; /*!< @description
	*	Time constant of the first order low pass needed to filter the Y-Coorindate Controller's D-part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcOfDT1_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radpsm_0_100_1em4_t	Y_TCTLGC_LdcOfIGain_radpsm[15]; /*!< @description
	*	Gain of the Y-Coordinate Controller's integral part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcOfIGain_radpsm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad/sm \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_LdcOfPT1Gain_nu[15]; /*!< @description
	*	Gain of the Lateral Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_LdcOfPT1Gain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_LdcOfPT1Time_sec[15]; /*!< @description
	*	Time Constant of the Lateral Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_LdcOfPT1Time_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radpm_0_100_1em4_t	Y_TCTLGC_LdcOfP_radpm[15]; /*!< @description
	*	Lateral Deviation Controller P-Gain for object following mode \n\n
	*	\@asap_name: Y_TCTLGC_LdcOfP_radpm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radpm_0_2_1em3_t	Y_TCTLGC_LdcPGainCrv_radpm[9]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TCTLGC_LdcPGainCrv_radpm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_CrvFFC_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: rad/m \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_LdcPT1Gain_nu[15]; /*!< @description
	*	Gain of the Lateral Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_LdcPT1Gain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_LdcPT1Time_sec[15]; /*!< @description
	*	Time Constant of the Lateral Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_LdcPT1Time_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radpm_0_100_1em4_t	Y_TCTLGC_LdcP_radpm[15]; /*!< @description
	*	Proportional gain of the Y-Coordinate Controller in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcP_radpm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_radspm_0_100_1em4_t	Y_TCTLGC_LdcSfDGain_radspm[15]; /*!< @description
	*	Gain of the Y-Coorindate Controller's differential part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcSfDGain_radspm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rads/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_LdcSfDT1_sec[15]; /*!< @description
	*	Time constant of the first order low pass needed to filter the Y-Coorindate Controller's D-part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcSfDT1_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radpsm_0_100_1em4_t	Y_TCTLGC_LdcSfIGain_radpsm[15]; /*!< @description
	*	Gain of the Y-Coordinate Controller's integral part in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcSfIGain_radpsm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad/sm \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TCTLGC_LdcSfPT1Gain_nu[15]; /*!< @description
	*	Gain of the Lateral Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_LdcSfPT1Gain_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_LdcSfPT1Time_sec[15]; /*!< @description
	*	Time Constant of the Lateral Deviation Controller's PT1-Branch \n\n
	*	\@asap_name: Y_TCTLGC_LdcSfPT1Time_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_radpm_0_100_1em4_t	Y_TCTLGC_LdcSfP_radpm[15]; /*!< @description
	*	Proportional gain of the Y-Coordinate Controller in dependence on the vehicle's velocity \n\n
	*	\@asap_name: Y_TCTLGC_LdcSfP_radpm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad/m \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_PT1CoAnErrTime_sec[15]; /*!< @description
	*	Time constant of the low pass filter used to filter the control error regarding the Course Angle \n\n
	*	\@asap_name: Y_TCTLGC_PT1CoAnErrTime_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_PT1DeltaFCmdTime_sec[15]; /*!< @description
	*	Velocity dependend value of the low pass' time constant to filter DeltaFCmd \n\n
	*	\@asap_name: Y_TCTLGC_PT1DeltaFCmdTime_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_s_0p025_10_1em4_t	Y_TCTLGC_PT1YErrTime_sec[15]; /*!< @description
	*	Time constant of the low pass filter used to filter the control error regarding the Y-Coordinate \n\n
	*	\@asap_name: Y_TCTLGC_PT1YErrTime_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TCTLGC_Vel_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0.025 \n
	*	\@max: 10
	*/
	
	f32_m_0_5000_1em3_t	Y_TJAGEN_VehRadiusMinWR_met[6]; /*!< @description
	*	Minimum required vehicle radius at function start \n\n
	*	\@asap_name: Y_TJAGEN_VehRadiusMinWR_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJAGEN_VehVelX_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 5000
	*/
	
	f32_1pm_m0p02_0p02_1em9_t	Y_TJAOBF_TgtClthCrvMaxWR_1pm[6]; /*!< @description
	*	Maximum allowed target object clothoid curvature for OF mode activation (WR condition) \n\n
	*	\@asap_name: Y_TJAOBF_TgtClthCrvMaxWR_1pm \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJAOBF_VehVelX_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: 1/m \n
	*	\@min: -0.02 \n
	*	\@max: 0.02
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t	Y_TJAOBF_TgtClthHeadMaxWR_rad[6]; /*!< @description
	*	Maximum allowed target object clothoid heading angle for OF mode activation (WR condition) \n\n
	*	\@asap_name: Y_TJAOBF_TgtClthHeadMaxWR_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJAOBF_VehVelX_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	f32_m_m15_15_1em3_t	Y_TJAOBF_TgtClthPosYMaxWR_met[6]; /*!< @description
	*	Maximum allowed target object clothoid lateral position Y0 for OF mode activation (WR condition) \n\n
	*	\@asap_name: Y_TJAOBF_TgtClthPosYMaxWR_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJAOBF_VehVelX_kph \n
	*	\@axis_x_unit: km/h \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_TJATVG_LWDeratLvlScalFact_nu[6]; /*!< @description
	*	Lookup table for lane width derating level scaling factort \n\n
	*	\@asap_name: Y_TJATVG_LWDeratLvlScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_LCF_LaneWidth_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	Y_TJATVG_PlanHorizonObjFolVal_sec[6]; /*!< @description
	*	Lookup table for vehicle speed dependend planning horizon for OF \n\n
	*	\@asap_name: Y_TJATVG_PlanHorizonObjFolVal_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJATVG_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_TJATVG_PlanHorizonScalFact_nu[7]; /*!< @description
	*	Y axis of the Planning Horizon scaling factor \n\n
	*	\@asap_name: Y_TJATVG_PlanHorizonScalFact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJATVG_CrvPlanHorizon_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_60_1em3_t	Y_TJATVG_PlanningHorizonVal_sec[6]; /*!< @description
	*	Lookup table for vehicle speed dependend planning horizon \n\n
	*	\@asap_name: Y_TJATVG_PlanningHorizonVal_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJATVG_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_TJATVG_RedFact_Vel_nu[6]; /*!< @description
	*	TJATVG_APARAM \n\n
	*	\@asap_name: Y_TJATVG_RedFact_Vel_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TJATVG_VehVelX_RedFact_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_s_0_1_1em3_t	Y_TPLCEN_DeadTimeVehCtrl_sec[7]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TPLCEN_DeadTimeVehCtrl_sec \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLCEN_PotVecDynVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_10_1em6_t	Y_TPLFBT_GradLimitCrvFactor_nu[13]; /*!< @description
	*	Y axle: speed dependent factor on the gradient limitation of curvature \n\n
	*	\@asap_name: Y_TPLFBT_GradLimitCrvFactor_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLFBT_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_1_1em3_t	Y_TPLLCO_AllowedDevPosY_met[4]; /*!< @description
	*	y axle with allowed deviation in lateral direction for coordinate transformation \n\n
	*	\@asap_name: Y_TPLLCO_AllowedDevPosY_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLLCO_TestPointPosX_met \n
	*	\@axis_x_unit: m \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_m_0_40_1em3_t	Y_TPLLCO_PreviewDistXOBF_met[13]; /*!< @description
	*	preview distance in longitudinal direction for OBF mode \n\n
	*	\@asap_name: Y_TPLLCO_PreviewDistXOBF_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLLCO_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 40
	*/
	
	f32_m_0_10_1em3_t	Y_TPLLCO_PreviewDistX_met[13]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TPLLCO_PreviewDistX_met \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLLCO_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_rad_0_1_1em6_t	Y_TPLLCO_TgtCridrHeadTolCrv_rad[6]; /*!< @description
	*	Target corridor heading tolerance regarding to the curvature \n\n
	*	\@asap_name: Y_TPLLCO_TgtCridrHeadTolCrv_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLLCO_CorridorCurvature_1pm \n
	*	\@axis_x_unit: 1/m \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_rad_0_1_1em6_t	Y_TPLLCO_TgtCridrHeadTolVelX_rad[13]; /*!< @description
	*	Target corridor heading tolerance regarding to longitudinal velocity \n\n
	*	\@asap_name: Y_TPLLCO_TgtCridrHeadTolVelX_rad \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLLCO_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: rad \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_0_2_1em3_t	Y_TPLLCO_VehCrvFactor_nu[13]; /*!< @description
	*	factor on vehicle curvature \n\n
	*	\@asap_name: Y_TPLLCO_VehCrvFactor_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLLCO_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	f32_mps2_0_20_1em3_t	Y_TPLTJC_MaxAclY_mps2[6]; /*!< @description
	*	y axle with max. lateral accleration \n\n
	*	\@asap_name: Y_TPLTJC_MaxAclY_mps2 \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLTJC_VehVelX_mps \n
	*	\@axis_x_unit: m/s \n
	*	\@unit: m/s^2 \n
	*	\@min: 0 \n
	*	\@max: 20
	*/
	
	f32_NoUnit_0_20_1em3_t	Y_TPLTJC_WeightEndTime_nu[5]; /*!< @description
	*	y axle with weight end time \n\n
	*	\@asap_name: Y_TPLTJC_WeightEndTime_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLTJC_PlanningHorizon_sec \n
	*	\@axis_x_unit: s \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 20
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TPLTJC_WghtTgtDistYCharact_nu[2]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TPLTJC_WghtTgtDistYCharact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLTJC_WghtTgtDistYCustFct_nu \n
	*	\@axis_x_unit: - \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t	Y_TPLTJC_WghtTgtTimeCharact_nu[2]; /*!< @description
	*	 \n\n
	*	\@asap_name: Y_TPLTJC_WghtTgtTimeCharact_nu \n
	*	\@type: curve \n
	*	\@calibration: online \n
	*	\@axis_x_type: curve \n
	*	\@axis_x_ref: LCF_CommonParamData.X_TPLTJC_WghtTgtTimeCustFct_nu \n
	*	\@axis_x_unit: - \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u32_us_0_4294967295_0_1_t	P_TPLLCO_OdoMaxTime_us; /*!< @description
	*	max timestamp of vdy data \n\n
	*	\@asap_name: P_TPLLCO_OdoMaxTime_us \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: us \n
	*	\@min: 0 \n
	*	\@max: 4294967295
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ABPLBP_ValidColorBitmask_nu; /*!< @description
	*	Defines valid lane marker colors: \n
	*	 \n
	*	ABD_MC_UNCLASSIFIED = 0  \n
	*	ABD_MC_WHITE = 1 \n
	*	ABD_MC_YELLOW = 2 \n
	*	ABD_MC_RED = 3 \n
	*	ABD_MC_BLUE = 4 \n
	*	ABD_MC_GREEN = 5 \n\n
	*	\@asap_name: P_ABPLBP_ValidColorBitmask_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ABPLBP_ValidLnTypeBitmask_nu; /*!< @description
	*	Bitmask for valid lane marker type. \n\n
	*	\@asap_name: P_ABPLBP_ValidLnTypeBitmask_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ABPREP_ValidReTypeBitmask_nu; /*!< @description
	*	Valid Road edge bitmask. \n\n
	*	\@asap_name: P_ABPREP_ValidReTypeBitmask_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSIA_LaneBitmask_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLSIA_LaneBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSIA_LaneBridgedBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which bits of the LaneBitfield mean lane markling bridged. \n\n
	*	\@asap_name: P_DPLSIA_LaneBridgedBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSIA_LaneCancelBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the LaneBitfield are needed to cancel the function. \n\n
	*	\@asap_name: P_DPLSIA_LaneCancelBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_AbortFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_AbortVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_CancelFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_CancelVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_FctCustomBSMLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM left lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FctCustomBSMLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_FctCustomBSMRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM right lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FctCustomBSMRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_FctCustomCancelLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FctCustomCancelLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_FctCustomCancelRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FctCustomCancelRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_FctCustomTrgLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FctCustomTrgLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_FctCustomTrgRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FctCustomTrgRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_QuTrajPlanCancel_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to cancel an LDP intevention. \n\n
	*	\@asap_name: P_DPLSMI_QuTrajPlanCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_QuTrajPlanClearance_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to give the clearance to an an LDP intevention. \n\n
	*	\@asap_name: P_DPLSMI_QuTrajPlanClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_StrgRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_StrgRdyVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_SuppressFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_SuppressVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_WeakRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMI_WeakRdyVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_AbortFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_AbortVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_CancelFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_CancelVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_FctCustomBSMLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM left warning. \n\n
	*	\@asap_name: P_DPLSMW_FctCustomBSMLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_FctCustomBSMRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM right warning. \n\n
	*	\@asap_name: P_DPLSMW_FctCustomBSMRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_FctCustomCancelLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left warning. \n\n
	*	\@asap_name: P_DPLSMW_FctCustomCancelLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_FctCustomCancelRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right warning. \n\n
	*	\@asap_name: P_DPLSMW_FctCustomCancelRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_FctCustomTrgLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left warning. \n\n
	*	\@asap_name: P_DPLSMW_FctCustomTrgLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_FctCustomTrgRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right warning. \n\n
	*	\@asap_name: P_DPLSMW_FctCustomTrgRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_StrgRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_StrgRdyVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_SuppressFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_SuppressVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_WeakRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPLSMW_WeakRdyVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSIA_LaneBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the LaneBitfield are needed to triger the RDP function. Used with S_ABPLBP_LeLnInvalidQu_btf/S_ABPLBP_RiLnInvalidQu_btf. \n\n
	*	\@asap_name: P_DPRSIA_LaneBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSIA_LaneBridgedBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which bits of the LaneBitfield mean lane markling bridged. \n\n
	*	\@asap_name: P_DPRSIA_LaneBridgedBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSIA_LaneCancelBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the LaneBitfield are needed to cancel the function. \n\n
	*	\@asap_name: P_DPRSIA_LaneCancelBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSIA_RoadBitmask_btm; /*!< @description
	*	Bitmask that indicates which properties of the RoadBitfield are needed to trigger the function. \n\n
	*	\@asap_name: P_DPRSIA_RoadBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSIA_RoadBridgedBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which bits of the RoadBitfield mean road edge bridged. \n\n
	*	\@asap_name: P_DPRSIA_RoadBridgedBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSIA_RoadCancelBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the RoadBitfield can cancel the function. \n\n
	*	\@asap_name: P_DPRSIA_RoadCancelBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_AbortFctCustom_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_AbortVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_CancelFctCustom_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_CancelVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_FctCustomCancelLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left lateral intervention. \n\n
	*	\@asap_name: P_DPRSMI_FctCustomCancelLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_FctCustomCancelRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right lateral intervention. \n\n
	*	\@asap_name: P_DPRSMI_FctCustomCancelRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_FctCustomTrgLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left lateral intervention. \n\n
	*	\@asap_name: P_DPRSMI_FctCustomTrgLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_FctCustomTrgRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right lateral intervention. \n\n
	*	\@asap_name: P_DPRSMI_FctCustomTrgRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_QuTrajPlanCancel_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to cancel an RDP intevention. \n\n
	*	\@asap_name: P_DPRSMI_QuTrajPlanCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_QuTrajPlanClearance_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to give the clearance to an an RDP intevention. \n\n
	*	\@asap_name: P_DPRSMI_QuTrajPlanClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_StrgRdyFctCustom_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_StrgRdyVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_SuppressFctCustom_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_SuppressVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_WeakRdyFctCustom_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMI_WeakRdyVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_AbortFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_AbortVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_CancelFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_CancelVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_FctCustomCancelLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left warning. \n\n
	*	\@asap_name: P_DPRSMW_FctCustomCancelLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_FctCustomCancelRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right warning. \n\n
	*	\@asap_name: P_DPRSMW_FctCustomCancelRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_FctCustomTrgLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left warning. \n\n
	*	\@asap_name: P_DPRSMW_FctCustomTrgLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_FctCustomTrgRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right warning. \n\n
	*	\@asap_name: P_DPRSMW_FctCustomTrgRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_StrgRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_StrgRdyVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_SuppressFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_SuppressVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_WeakRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DPRSMW_WeakRdyVehSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_DRMDAE_AbuseFunctions_btf; /*!< @description
	*	Bitfield to define for which functions, DriverAbuseMonitoring is enabled. \n\n
	*	\@asap_name: P_DRMDAE_AbuseFunctions_btf \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSIA_LaneBitmask_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_LaneBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSIA_LaneCancelBitmask_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_LaneCancelBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_AbortFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the abort conditions. \n\n
	*	\@asap_name: P_LCRSMI_AbortFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_AbortVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_AbortVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_CancelFctCustomLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left lateral intervention. \n\n
	*	\@asap_name: P_LCRSMI_CancelFctCustomLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_CancelFctCustomRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right lateral intervention. \n\n
	*	\@asap_name: P_LCRSMI_CancelFctCustomRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_CancelFctCustom_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_CancelVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_FctCustomTrgLe_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left lateral intervention. \n\n
	*	\@asap_name: P_LCRSMI_FctCustomTrgLe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_FctCustomTrgRi_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right lateral intervention. \n\n
	*	\@asap_name: P_LCRSMI_FctCustomTrgRi_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_QuTrajPlanCancel_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TPLTJC_QuStatusTrajPlan_nu are used to cancel an ALCA intevention. \n\n
	*	\@asap_name: P_LCRSMI_QuTrajPlanCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_QuTrajPlanClearance_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TPLTJC_QuStatusTrajPlan_nu are used to give the clearance to an an ALCA intevention. \n\n
	*	\@asap_name: P_LCRSMI_QuTrajPlanClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_StrgRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_LCRSMI_StrgRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_StrgRdyVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_StrgRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_SuppressFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the stsuppress conditions. \n\n
	*	\@asap_name: P_LCRSMI_SuppressFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_SuppressVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SuppressVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_WeakRdyFctCustom_btm; /*!< @description
	*	Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the weak ready conditions. \n\n
	*	\@asap_name: P_LCRSMI_WeakRdyFctCustom_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_LCRSMI_WeakRdyVehSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_WeakRdyVehSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOH_AccObjChange_btm; /*!< @description
	*	Bitmask for S_ODPFOP_AccObjInvBitfield_btf to observe ACC object changes \n\n
	*	\@asap_name: P_ODPFOH_AccObjChange_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOH_AccObjDtct_btm; /*!< @description
	*	Bitmask for S_ODPFOP_AccObjInvBitfield_btf to check if a new ACC obj has been detected \n\n
	*	\@asap_name: P_ODPFOH_AccObjDtct_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOH_AccObjFreeze_btm; /*!< @description
	*	Bitmask for S_ODPFOP_AccObjInvBitfield_btf to check if ACC obj position is frozen \n\n
	*	\@asap_name: P_ODPFOH_AccObjFreeze_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOH_AccObjKfUpdate_btm; /*!< @description
	*	Bitmask for check of Acc object validity for KF measurement update \n\n
	*	\@asap_name: P_ODPFOH_AccObjKfUpdate_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOH_AccObjValidLSM_btm; /*!< @description
	*	Bitmask for check of Acc object validity for Low Speed Mode \n\n
	*	\@asap_name: P_ODPFOH_AccObjValidLSM_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOP_FusionMCamFront_nu; /*!< @description
	*	Note: Should be an constant -> Cam fusion state \n\n
	*	\@asap_name: P_ODPFOP_FusionMCamFront_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_ODPFOP_FusionRadarFront_nu; /*!< @description
	*	Note: Should be a constant -> radar fusion \n\n
	*	\@asap_name: P_ODPFOP_FusionRadarFront_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TCTFFC_DynGainPrecSelect_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainPrecSelect_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TCTFFC_OssDynGain_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_OssDynGain_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_PrjSpecQuA_btm; /*!< @description
	*	Bitmask to check project specific abort conditions for all TJA modes \n\n
	*	\@asap_name: P_TJAGEN_PrjSpecQuA_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_PrjSpecQuC_btm; /*!< @description
	*	Bitmask to check project specific cancel conditions for all TJA modes \n\n
	*	\@asap_name: P_TJAGEN_PrjSpecQuC_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_PrjSpecQuSR_btm; /*!< @description
	*	Bitmask to check project specific strong ready conditions for all TJA modes \n\n
	*	\@asap_name: P_TJAGEN_PrjSpecQuSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_PrjSpecQuWR_btm; /*!< @description
	*	Bitmask to check project specific weak ready conditions for all TJA modes \n\n
	*	\@asap_name: P_TJAGEN_PrjSpecQuWR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_QuTrajPlanCancel_btm; /*!< @description
	*	Bitmask check for S_TPLTJC_QuStatusTrajPlan_nu as cancel condition \n\n
	*	\@asap_name: P_TJAGEN_QuTrajPlanCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_QuTrajPlanClearance_btm; /*!< @description
	*	Bitmask check for S_TPLTJC_QuStatusTrajPlan_nu as clearance condition \n\n
	*	\@asap_name: P_TJAGEN_QuTrajPlanClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_VehStInvalidC_btm; /*!< @description
	*	Bitmask value for vehicle state checks of the cancel condition \n\n
	*	\@asap_name: P_TJAGEN_VehStInvalidC_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_VehStInvalidSR_btm; /*!< @description
	*	Bitmask for vehicle state checks of the strong ready condition \n\n
	*	\@asap_name: P_TJAGEN_VehStInvalidSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAGEN_VehStInvalidWR_btm; /*!< @description
	*	Bitmask for vehicle state checks of the weak ready condition \n\n
	*	\@asap_name: P_TJAGEN_VehStInvalidWR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJALKA_LaneValid_btm; /*!< @description
	*	Bitmask for lane validity check (left/right) \n\n
	*	\@asap_name: P_TJALKA_LaneValid_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJALKA_LaneVirtOrBridged_btm; /*!< @description
	*	Bitmask to check if lanes are bridged or virtual \n\n
	*	\@asap_name: P_TJALKA_LaneVirtOrBridged_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJALKA_PrjSpecQuC_btm; /*!< @description
	*	Bitmask to check project specific cancel conditions for lane centering \n\n
	*	\@asap_name: P_TJALKA_PrjSpecQuC_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJALKA_PrjSpecQuSR_btm; /*!< @description
	*	Bitmask to check project specific SR conditions for lane centering \n\n
	*	\@asap_name: P_TJALKA_PrjSpecQuSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJALKA_PrjSpecQuWR_btm; /*!< @description
	*	Bitmask to check project specific WR conditions for lane centering \n\n
	*	\@asap_name: P_TJALKA_PrjSpecQuWR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_AccObjChange_btm; /*!< @description
	*	Bitmask to check if the ID of the target object has changed. \n\n
	*	\@asap_name: P_TJAOBF_AccObjChange_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_AccObjLanesInvalid_btm; /*!< @description
	*	Bit mask to check ACC object validity for object in target lane evalution (ignoring lateral position validity) \n\n
	*	\@asap_name: P_TJAOBF_AccObjLanesInvalid_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_AccObjectInvalid_btm; /*!< @description
	*	Bit mask to check ACC object validity \n\n
	*	\@asap_name: P_TJAOBF_AccObjectInvalid_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_PrjSpecQuC_btm; /*!< @description
	*	Bitmask to check project specific cancel conditions for object following \n\n
	*	\@asap_name: P_TJAOBF_PrjSpecQuC_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_PrjSpecQuSR_btm; /*!< @description
	*	Bitmask to check project specific SR conditions for object following \n\n
	*	\@asap_name: P_TJAOBF_PrjSpecQuSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_PrjSpecQuWR_btm; /*!< @description
	*	Bitmask to check project specific WR conditions for object following \n\n
	*	\@asap_name: P_TJAOBF_PrjSpecQuWR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_TgtClthInvalid_btm; /*!< @description
	*	Bit mask to check validity of ACC object clothoid generation \n\n
	*	\@asap_name: P_TJAOBF_TgtClthInvalid_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TJAOBF_TgtClthWRInvalid_btm; /*!< @description
	*	Bitmask for target object clothoid weak ready check \n\n
	*	\@asap_name: P_TJAOBF_TgtClthWRInvalid_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t	P_TPLFBT_CheckTrajPlanStatus_nu; /*!< @description
	*	Bit mask decides which bits of the trajectory planner status shall be checked: \n
	*	0 bit: min acceleration check \n
	*	1 bit: max acceleration check \n
	*	2 bit: right corridor boundary collision check \n
	*	3 bit: left corridor boundary collision check \n
	*	4 bit: object collision check \n
	*	5 bit: matrix invertible  \n
	*	6 bit: trajectory length \n
	*	7 bit: max jerk check \n
	*	8 bit: physical max curvature \n
	*	9 bit: target lateral distance \n
	*	10 bit: vehicle lateral distance \n
	*	11 bit: right corridor transformation \n
	*	12 bit: left corridor transformation \n\n
	*	\@asap_name: P_TPLFBT_CheckTrajPlanStatus_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_kg_0_10000_0_1_t	P_VEH_Mass_kg; /*!< @description
	*	Mass of the vehicle \n\n
	*	\@asap_name: P_VEH_Mass_kg \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: kg \n
	*	\@min: 0 \n
	*	\@max: 10000
	*/
	
	u8_NoUnit_0_255_0_1_t	P_ABPLBP_CSABDBitmask_btm; /*!< @description
	*	Bitmask determines the ABD CS information usage: \n
	*	 \n
	*	Bit 0: CS_MULTIPLE_MARKER; \n
	*	Bit 1: CS_LEFT_BARRIER; \n
	*	Bit 2: CS_RIGHT_BARRIER; \n
	*	Bit 3: CS_CROSSING_MARKER; \n
	*	Bit 4: CS_INHIBIT_SINGLE_LINE; \n
	*	Bit 5: CS_MARKER_COLOR_CHANGE; \n
	*	Bit 6: CS_HOLD \n\n
	*	\@asap_name: P_ABPLBP_CSABDBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_CrvKFMnInitQual_perc; /*!< @description
	*	Minimum measurement quality for the kalman filter initialization \n\n
	*	\@asap_name: P_ABPLBP_CrvKFMnInitQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_CrvKFMnUpdateQual_perc; /*!< @description
	*	Minimum measurement quality to apply kalman filter update step. If the measurement quality is below only the prediction step is applied. \n\n
	*	\@asap_name: P_ABPLBP_CrvKFMnUpdateQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_ExitNCycleTrig_bool; /*!< @description
	*	Edge rising trigger enable regarding exit ramp detection by lane width difference \n\n
	*	\@asap_name: P_ABPLBP_ExitNCycleTrig_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_InvalLeftLane_bool; /*!< @description
	*	Switch for setting the left lane boundary invalid \n\n
	*	\@asap_name: P_ABPLBP_InvalLeftLane_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_InvalRightLane_bool; /*!< @description
	*	Switch for setting the right lane invalid \n\n
	*	\@asap_name: P_ABPLBP_InvalRightLane_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ABPLBP_LDVirtCycleTurnOn_nu; /*!< @description
	*	Cycle turn on time \n\n
	*	\@asap_name: P_ABPLBP_LDVirtCycleTurnOn_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LDVirtDefaultQual_perc; /*!< @description
	*	Default internal quality for LD virtual line \n\n
	*	\@asap_name: P_ABPLBP_LDVirtDefaultQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ABPLBP_LDVirtualDelayCycle_nu; /*!< @description
	*	Determines the cycles for the samle turn on delay for the LD virtual information. \n\n
	*	\@asap_name: P_ABPLBP_LDVirtualDelayCycle_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LaneKFDegrUpdateQu_perc; /*!< @description
	*	Quality threshold for degraded update in center lane kalman filter \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDegrUpdateQu_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_LaneKFDegrUpdate_bool; /*!< @description
	*	Use degraded update in center lane kalman filter \n\n
	*	\@asap_name: P_ABPLBP_LaneKFDegrUpdate_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LaneKFMnInitQual_perc; /*!< @description
	*	Minimum measurement quality for the kalman filter initialization \n\n
	*	\@asap_name: P_ABPLBP_LaneKFMnInitQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LaneKFMnUpdateQual_perc; /*!< @description
	*	Minimum measurement quality to apply kalman filter update step. If the measurement quality is below only the prediction step is applied. \n\n
	*	\@asap_name: P_ABPLBP_LaneKFMnUpdateQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LaneKFQualForBrid_perc; /*!< @description
	*	Minimum center lane kalman filter to enable lane bridging \n\n
	*	\@asap_name: P_ABPLBP_LaneKFQualForBrid_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_LaneKFYawRtStdDev_bool; /*!< @description
	*	TRUE:Use VDY yaw rate standard deviation.  \n
	*	FALSE:Use constant standard deviation \n\n
	*	\@asap_name: P_ABPLBP_LaneKFYawRtStdDev_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LaneQualityLSP_perc; /*!< @description
	*	Lane quality LSP (lower hysteresis \n\n
	*	\@asap_name: P_ABPLBP_LaneQualityLSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_LaneQualityRSP_perc; /*!< @description
	*	Lane quality LSP (upper hysteresis) \n\n
	*	\@asap_name: P_ABPLBP_LaneQualityRSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_MinKalmanQuality_perc; /*!< @description
	*	Minimum kalman filter quality \n\n
	*	\@asap_name: P_ABPLBP_MinKalmanQuality_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ABPLBP_MotCompDeltaQual_perc; /*!< @description
	*	Motion compensation delta quality threshold \n\n
	*	\@asap_name: P_ABPLBP_MotCompDeltaQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_MotCompMinPrevQual_perc; /*!< @description
	*	Motion compensation minimum previous lane quality threshold \n\n
	*	\@asap_name: P_ABPLBP_MotCompMinPrevQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_MotCompQualReset_perc; /*!< @description
	*	Motion compensation reset quality \n\n
	*	\@asap_name: P_ABPLBP_MotCompQualReset_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_MotionCompDfltQual_perc; /*!< @description
	*	Default internal quality for motion compensation \n\n
	*	\@asap_name: P_ABPLBP_MotionCompDfltQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_OverpassDfltQual_perc; /*!< @description
	*	Default quality in case of an detected dark-light transition (overpass issue) \n\n
	*	\@asap_name: P_ABPLBP_OverpassDfltQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_PitchProbLSP_perc; /*!< @description
	*	pitching probability hysteresis (LSP) \n\n
	*	\@asap_name: P_ABPLBP_PitchProbLSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_PitchProbRSP_perc; /*!< @description
	*	pitching probability hysteresis (RSP) \n\n
	*	\@asap_name: P_ABPLBP_PitchProbRSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_SIFQualityLSP_perc; /*!< @description
	*	Safety interface quality hysteresis threshold (lower value) \n\n
	*	\@asap_name: P_ABPLBP_SIFQualityLSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_SIFQualityRSP_perc; /*!< @description
	*	Safety interface quality hysteresis threshold (upper value) \n\n
	*	\@asap_name: P_ABPLBP_SIFQualityRSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_StrDtctCrvDiffDef_perc; /*!< @description
	*	Default straight detection value if lane bridging is active, the center lane curvature is below a threshold and the difference of both uncoupled lanes to the center lane curvature is above a threshold \n\n
	*	\@asap_name: P_ABPLBP_StrDtctCrvDiffDef_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_StrDtctMinQual_perc; /*!< @description
	*	Straight detection minimum required quality \n\n
	*	\@asap_name: P_ABPLBP_StrDtctMinQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_UncoupLnQualLSP_perc; /*!< @description
	*	Uncoupled lane quality hysteresis (LSP) \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnQualLSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_UncoupLnQualRSP_perc; /*!< @description
	*	Uncoupled lane quality hysteresis (RSP) \n\n
	*	\@asap_name: P_ABPLBP_UncoupLnQualRSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UpDownDeactivatSIF_bool; /*!< @description
	*	Deactivate SIF if up downhill scenario has been detected \n\n
	*	\@asap_name: P_ABPLBP_UpDownDeactivatSIF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ABPLBP_UpDownHillLSP_nu; /*!< @description
	*	Lower hysteresis threshold for up/downhill detetion evaluation \n\n
	*	\@asap_name: P_ABPLBP_UpDownHillLSP_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ABPLBP_UpDownHillRSP_nu; /*!< @description
	*	Upper hysteresis threshold for up/downhill detetion evaluation \n\n
	*	\@asap_name: P_ABPLBP_UpDownHillRSP_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_UpDownHillShutOffLSP_nu; /*!< @description
	*	Lower threshold for up/downhill detection (hysteresis LSP) \n\n
	*	\@asap_name: P_ABPLBP_UpDownHillShutOffLSP_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPLBP_UpDownHillShutOffRSP_nu; /*!< @description
	*	Upper threshold for up/downhill detection (hysteresis RSP) \n\n
	*	\@asap_name: P_ABPLBP_UpDownHillShutOffRSP_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseABDOverpassFlag_bool; /*!< @description
	*	Use ABD dark-light transition flag (overpass issue) \n\n
	*	\@asap_name: P_ABPLBP_UseABDOverpassFlag_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseABDSineWave_bool; /*!< @description
	*	Determines usage of ABD interface sine wave road detection flag \n\n
	*	\@asap_name: P_ABPLBP_UseABDSineWave_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseABDSlope_bool; /*!< @description
	*	Determines usage of ABD interface significant slope detection flag \n\n
	*	\@asap_name: P_ABPLBP_UseABDSlope_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseCBWeatherCond_bool; /*!< @description
	*	Use CB weather condition information \n\n
	*	\@asap_name: P_ABPLBP_UseCBWeatherCond_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseCrvEstRecal_bool; /*!< @description
	*	Use re-calcuration for curve estimation after Kalman filter \n\n
	*	\@asap_name: P_ABPLBP_UseCrvEstRecal_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseCrvEstSat_bool; /*!< @description
	*	 \n\n
	*	\@asap_name: P_ABPLBP_UseCrvEstSat_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseCrvEstimation_bool; /*!< @description
	*	Use second order polynomial fit curvature \n\n
	*	\@asap_name: P_ABPLBP_UseCrvEstimation_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseCrvKalman_bool; /*!< @description
	*	Activate curvature kalman filter \n\n
	*	\@asap_name: P_ABPLBP_UseCrvKalman_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseGradientLimiter_bool; /*!< @description
	*	Use gradient limitation \n\n
	*	\@asap_name: P_ABPLBP_UseGradientLimiter_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseLDAlgoCompState_bool; /*!< @description
	*	Decidesto use LD algo component state information \n\n
	*	\@asap_name: P_ABPLBP_UseLDAlgoCompState_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseLaneDynWeight_bool; /*!< @description
	*	Use dynamic lane weighting of coupled/uncoupled lane \n\n
	*	\@asap_name: P_ABPLBP_UseLaneDynWeight_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseLaneWidthGrad_bool; /*!< @description
	*	use gradient limit logic for lane width before PT1 filter or don't use \n\n
	*	\@asap_name: P_ABPLBP_UseLaneWidthGrad_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseLatencyCompSIF_bool; /*!< @description
	*	TRUE: Activates latency compensation implemented in the safety interface \n\n
	*	\@asap_name: P_ABPLBP_UseLatencyCompSIF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseMaxValidLength_bool; /*!< @description
	*	Use maximum lookahead distance of both lanes in case \n\n
	*	\@asap_name: P_ABPLBP_UseMaxValidLength_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseMotionComp_bool; /*!< @description
	*	Use lane motion compensation \n\n
	*	\@asap_name: P_ABPLBP_UseMotionComp_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UsePT1FilterSIF_bool; /*!< @description
	*	TRUE: Activate lateral velocity PT1 filter for the latency compensation \n\n
	*	\@asap_name: P_ABPLBP_UsePT1FilterSIF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UsePitchingDtct_bool; /*!< @description
	*	Activate pitching detection observer \n\n
	*	\@asap_name: P_ABPLBP_UsePitchingDtct_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseStraightEstim_bool; /*!< @description
	*	Use straight estimation based on feature point data \n\n
	*	\@asap_name: P_ABPLBP_UseStraightEstim_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseSuppressBridged_bool; /*!< @description
	*	suppress the judgement of invalid condition during another side is bridged \n\n
	*	\@asap_name: P_ABPLBP_UseSuppressBridged_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseUncoupABDQual_bool; /*!< @description
	*	Use uncoupled lane quality from ABD interface in SIF \n\n
	*	\@asap_name: P_ABPLBP_UseUncoupABDQual_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseUncoupLanesSIF_bool; /*!< @description
	*	Use uncoupled raw lane data for safety interface (SIF) instead of ABPLBP fused lane data \n\n
	*	\@asap_name: P_ABPLBP_UseUncoupLanesSIF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPLBP_UseUncoupStepDtct_bool; /*!< @description
	*	Determines uncoupled lane step detection usage \n\n
	*	\@asap_name: P_ABPLBP_UseUncoupStepDtct_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_ABPLBP_ValidCBWeatherCond_btf; /*!< @description
	*	Bitmask selects weather condition information for evaluation \n
	*	 \n
	*	GB_HEAVY_RAIN_SNOW����(Bit 1) \n
	*	GB_HEAVY_FOG����(Bit 2) \n
	*	GB_HEAVY_GLARING_SUN����(Bit 3) \n
	*	GB_GLARING����(Bit 4) \n
	*	GB_RAIN����(Bit 5) \n
	*	GB_FOG����(Bit 6) \n\n
	*	\@asap_name: P_ABPLBP_ValidCBWeatherCond_btf \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_KalmanMinQuality_perc; /*!< @description
	*	Minimum kalman filter quality \n\n
	*	\@asap_name: P_ABPREP_KalmanMinQuality_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_LaneKFDegrUpdateQu_perc; /*!< @description
	*	Quality threshold for degraded update in center lane kalman filter \n\n
	*	\@asap_name: P_ABPREP_LaneKFDegrUpdateQu_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_LaneKFDegrUpdate_bool; /*!< @description
	*	Use degraded update in center lane kalman filter \n\n
	*	\@asap_name: P_ABPREP_LaneKFDegrUpdate_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_LaneKFMnInitQual_perc; /*!< @description
	*	Minimum measurement quality for the kalman filter initialization \n\n
	*	\@asap_name: P_ABPREP_LaneKFMnInitQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_LaneKFMnUpdateQual_perc; /*!< @description
	*	Minimum measurement quality to apply kalman filter update step. If the measurement quality is below only the prediction step is applied. \n\n
	*	\@asap_name: P_ABPREP_LaneKFMnUpdateQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_MinRoadEdgeABDQual_perc; /*!< @description
	*	Minimum road edge quality (ABD input quality threhold \n\n
	*	\@asap_name: P_ABPREP_MinRoadEdgeABDQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_MinRoadEdgeQualLSP_perc; /*!< @description
	*	Lower (LSP) quality hysteresis threshold \n\n
	*	\@asap_name: P_ABPREP_MinRoadEdgeQualLSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ABPREP_MinRoadEdgeQualRSP_perc; /*!< @description
	*	Upper (RSP) quality hysteresis threshold \n\n
	*	\@asap_name: P_ABPREP_MinRoadEdgeQualRSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_SIFUseKalmanHead_bool; /*!< @description
	*	Use kalman filter safety heading \n\n
	*	\@asap_name: P_ABPREP_SIFUseKalmanHead_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_SIFUseLatVelPT1Flt_bool; /*!< @description
	*	Determines if PT1 filter for the lateral velocity is active \n\n
	*	\@asap_name: P_ABPREP_SIFUseLatVelPT1Flt_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_SIFUseLatencyComp_bool; /*!< @description
	*	Indicates if latency compensation should be used for the lateral displacement \n\n
	*	\@asap_name: P_ABPREP_SIFUseLatencyComp_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_StabilizeWithLanes_bool; /*!< @description
	*	Determines if road edges are stabilized with lane data \n\n
	*	\@asap_name: P_ABPREP_StabilizeWithLanes_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_UseCBWeatherCond_bool; /*!< @description
	*	Use CB (camera blockage) weather condition check \n\n
	*	\@asap_name: P_ABPREP_UseCBWeatherCond_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_UseGradientLimiter_bool; /*!< @description
	*	TRUE: Activate output data gradient limiter \n\n
	*	\@asap_name: P_ABPREP_UseGradientLimiter_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_UseLDAlgoCompState_bool; /*!< @description
	*	Use LD algo component state check \n\n
	*	\@asap_name: P_ABPREP_UseLDAlgoCompState_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_UseLatVelPT1Filter_bool; /*!< @description
	*	Use lateral velocity kalman filter \n\n
	*	\@asap_name: P_ABPREP_UseLatVelPT1Filter_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_UseRoadEdgeKalman_nu; /*!< @description
	*	Activates road edge kalman filter \n\n
	*	\@asap_name: P_ABPREP_UseRoadEdgeKalman_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ABPREP_UseRoadEdgeQuality_nu; /*!< @description
	*	Activates internal calculated quality \n\n
	*	\@asap_name: P_ABPREP_UseRoadEdgeQuality_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_ABPREP_ValidCBWeatherCond_btf; /*!< @description
	*	Bitmask selects weather condition information for evaluation \n
	*	 \n
	*	GB_HEAVY_RAIN_SNOW    (Bit 1) \n
	*	GB_HEAVY_FOG    (Bit 2) \n
	*	GB_HEAVY_GLARING_SUN    (Bit 3) \n
	*	GB_GLARING    (Bit 4) \n
	*	GB_RAIN    (Bit 5) \n
	*	GB_FOG    (Bit 6) \n\n
	*	\@asap_name: P_ABPREP_ValidCBWeatherCond_btf \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ALCA_DlcTriggerCustom_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ALCA_DlcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ALCA_Existing_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ALCA_Existing_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_ConstrSiteLDP_bool; /*!< @description
	*	Construction Site Enable Switch for LDP \n\n
	*	\@asap_name: P_DPLSIA_ConstrSiteLDP_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_ConstrSiteLDW_bool; /*!< @description
	*	Construction Site Enable Switch for LDW \n\n
	*	\@asap_name: P_DPLSIA_ConstrSiteLDW_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSIA_LaneSafetyBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the LaneSafety Bitfield are needed to trigger the function. \n\n
	*	\@asap_name: P_DPLSIA_LaneSafetyBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_LaneWidthSIFOn_bool; /*!< @description
	*	If the switch is on, the Coupled/Uncoupled Lane Width will be taking into account and checked to trigger or cancel an intervention. If not, it will be ignored. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthSIFOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_LaneWidthWideLn_bool; /*!< @description
	*	New Lane Width too big logic switch. If on, lanes too wide will be considerd valid and a default lane width will be used. \n\n
	*	\@asap_name: P_DPLSIA_LaneWidthWideLn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_SafetyIfaceLDPOn_bool; /*!< @description
	*	If this parameter is enabled, the data from the safety interface will be used to trigger the LDP. Else, the control interface data will be used. \n\n
	*	\@asap_name: P_DPLSIA_SafetyIfaceLDPOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_SafetyIfaceLDWOn_bool; /*!< @description
	*	If this parameter is enabled, the data from the safety interface will be used to trigger the LDW. Else, the control interface data will be used. \n\n
	*	\@asap_name: P_DPLSIA_SafetyIfaceLDWOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_TurnSignReset_bool; /*!< @description
	*	If this parameter is enabled, the turn signal holding time is reseted when the driver switches on the turn light in the other direction. \n\n
	*	\@asap_name: P_DPLSIA_TurnSignReset_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSIA_UncoupledLWEnable_bool; /*!< @description
	*	If the switch in on, the uncoupled model lane width will be used. Else, the coupled model lane width. \n\n
	*	\@asap_name: P_DPLSIA_UncoupledLWEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_AbortDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_AbortFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf  are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_AbortFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_AbortFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_AbortSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used to abort a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_AbortSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_CancelDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_CancelFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_CancelFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_CancelFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_CancelSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_CancelSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_DebugDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
	*	\@asap_name: P_DPLSMI_DebugDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_DebugSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used for the SysState debug signal. \n\n
	*	\@asap_name: P_DPLSMI_DebugSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMI_ErrorStateLDPEnable_bool; /*!< @description
	*	Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPLSMI_ErrorStateLDPEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMI_ErrorStateLDP_bool; /*!< @description
	*	Parameter that simulates the behaviour of the Error State Signal. \n\n
	*	\@asap_name: P_DPLSMI_ErrorStateLDP_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_FinishCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions are used in order to finish a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_FinishCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMI_LDPSwitchEnable_bool; /*!< @description
	*	Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPLSMI_LDPSwitchEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMI_LDPSwitch_bool; /*!< @description
	*	Parameter that simulates the behaviour of the HMI Switch. \n\n
	*	\@asap_name: P_DPLSMI_LDPSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMI_LatDMCClearEnable_bool; /*!< @description
	*	Enabler of the SysStateDMC as clearance condition \n\n
	*	\@asap_name: P_DPLSMI_LatDMCClearEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_QuTrajCtrCancel_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to cancel an LDP intevention. \n\n
	*	\@asap_name: P_DPLSMI_QuTrajCtrCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_QuTrajCtrClearance_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to give the clearance to an LDP intevention. \n\n
	*	\@asap_name: P_DPLSMI_QuTrajCtrClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SafeSituationState_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
	*	\@asap_name: P_DPLSMI_SafeSituationState_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SideCondCancel_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDPLe_btf/S_DPLSIA_SideCondLDPRi_btf are used in order to cancel a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SideCondCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SideCondDebug_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDPLe_btf/S_DPLSIA_SideCondLDPRi_btf are used for the SysState debug signal \n\n
	*	\@asap_name: P_DPLSMI_SideCondDebug_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SideCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDPLe_btf/S_DPLSIA_SideCondLDPRi_btf are used in order to trigger a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SideCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_StrgRdyDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_StrgRdyFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_StrgRdyFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_StrgRdyFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_StrgRdySpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMI_StrgRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SuppressDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SuppressFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SuppressFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SuppressFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_SuppressSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used to suppress a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_SuppressSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_TriggerCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions are used in order to trigger a lateral intervention. \n\n
	*	\@asap_name: P_DPLSMI_TriggerCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_WeakRdyDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_WeakRdyFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_WeakRdyFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the weakready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_WeakRdyFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMI_WeakRdySpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMI_WeakRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_AbortDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_AbortFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf  are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_AbortFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_AbortFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_AbortSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPLSMW_AbortSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_CancelDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_CancelFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_CancelFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_CancelFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_CancelSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_CancelSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_DebugDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
	*	\@asap_name: P_DPLSMW_DebugDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_DebugSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used for the SysState debug signal. \n\n
	*	\@asap_name: P_DPLSMW_DebugSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMW_ErrorStateLDWEnable_bool; /*!< @description
	*	Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPLSMW_ErrorStateLDWEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMW_ErrorStateLDW_bool; /*!< @description
	*	Parameter that simulates the behaviour of the Error State Signal. \n\n
	*	\@asap_name: P_DPLSMW_ErrorStateLDW_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_FinishCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions are used in order to finish a warning. \n\n
	*	\@asap_name: P_DPLSMW_FinishCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMW_LDWSwitchEnable_bool; /*!< @description
	*	Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPLSMW_LDWSwitchEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMW_LDWSwitch_bool; /*!< @description
	*	Parameter that simulates the behaviour of the HMI Switch. \n\n
	*	\@asap_name: P_DPLSMW_LDWSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SafeSituationState_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two warnings with the same dangerous situation. \n\n
	*	\@asap_name: P_DPLSMW_SafeSituationState_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SideCondCancel_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDWLe_btf/S_DPLSIA_SideCondLDWRi_btf are used in order to cancel a warning. \n\n
	*	\@asap_name: P_DPLSMW_SideCondCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SideCondDebug_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDWLe_btf/S_DPLSIA_SideCondLDWRi_btf are used for the SysState debug signal. \n\n
	*	\@asap_name: P_DPLSMW_SideCondDebug_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SideCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDWLe_btf/S_DPLSIA_SideCondLDWRi_btf are used in order to trigger a warning. \n\n
	*	\@asap_name: P_DPLSMW_SideCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_StrgRdyDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_StrgRdyFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_StrgRdyFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_StrgRdyFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMW_StrgRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_StrgRdySpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPLSMW_StrgRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SuppressDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SuppressFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SuppressFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SuppressFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_SuppressSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPLSMW_SuppressSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLSMW_TriggerAlwaysOn_bool; /*!< @description
	*	If this switch is on, the trigger conditions (DLC or TLC) have to be fulfilled the whole time the trigger is being held, in order to have a trigger. Else, only the trigger holding time is relevant. \n\n
	*	\@asap_name: P_DPLSMW_TriggerAlwaysOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_TriggerCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions are used in order to trigger a warning. \n\n
	*	\@asap_name: P_DPLSMW_TriggerCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_WeakRdyDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_WeakRdyFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_WeakRdyFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_WeakRdyFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLSMW_WeakRdySpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPLSMW_WeakRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLTTG_TargetTrajPT1Active_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTTG_TargetTrajPT1Active_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLTTG_TgtCntrLnEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTTG_TgtCntrLnEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLTVG_HighStatAccu_bool; /*!< @description
	*	Switch for a high stationary accuracy in the LaDMC \n\n
	*	\@asap_name: P_DPLTVG_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLTVG_LimiterActivated_bool; /*!< @description
	*	Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
	*	\@asap_name: P_DPLTVG_LimiterActivated_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPLTVG_TrajPlanServQu_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_TrajPlanServQu_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLTVG_TriggerReplan_bool; /*!< @description
	*	Trigger replan flag. Enables a replanning when there is corridor information update. \n\n
	*	\@asap_name: P_DPLTVG_TriggerReplan_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPLTVG_UseLtcyComp_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPLTVG_UseLtcyComp_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_ConstrSiteLn_bool; /*!< @description
	*	Construction Site Enable Switch for lane markings \n\n
	*	\@asap_name: P_DPRSIA_ConstrSiteLn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_ConstrSiteRe_bool; /*!< @description
	*	Construction Site Enable Switch for road edges \n\n
	*	\@asap_name: P_DPRSIA_ConstrSiteRe_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_DPRSIA_ExitRampProb_perc; /*!< @description
	*	Minimum threshold (in percentage) that determines if an exit ramp was detected. \n\n
	*	\@asap_name: P_DPRSIA_ExitRampProb_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSIA_LaneSafetyBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the LaneSafetyBitfield can cancel the function. \n\n
	*	\@asap_name: P_DPRSIA_LaneSafetyBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_LaneWidthSIFOn_bool; /*!< @description
	*	If the switch is on, the Coupled/Uncoupled Lane Width will be taking into account and checked to trigger or cancel an intervention. If not, it will be ignored. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthSIFOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_LaneWidthSwitch_bool; /*!< @description
	*	Lane width validation switch for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_LaneWidthWideLn_bool; /*!< @description
	*	New Lane Width too big logic switch. If on, lanes too wide will be considerd valid and a default lane width will be used. \n\n
	*	\@asap_name: P_DPRSIA_LaneWidthWideLn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSIA_RoadSafetyBitmask_btm; /*!< @description
	*	Bitmask that carries the information of which properties of the RoadSafetyBitfield can cancel the function. \n\n
	*	\@asap_name: P_DPRSIA_RoadSafetyBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_RoadWidthSwitch_bool; /*!< @description
	*	Road width validation switch for the RDP. \n\n
	*	\@asap_name: P_DPRSIA_RoadWidthSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_SafetyIfaceLnOn_bool; /*!< @description
	*	If this parameter is enabled, the data from the safety lane markings will be used to trigger the function. Else, the control interface data will be used. \n\n
	*	\@asap_name: P_DPRSIA_SafetyIfaceLnOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_SafetyIfaceReOn_bool; /*!< @description
	*	If this parameter is enabled, the data from the safety road edges will be used to trigger the function. Else, the control interface data will be used. \n\n
	*	\@asap_name: P_DPRSIA_SafetyIfaceReOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSIA_TriggerCondEnable_btm; /*!< @description
	*	Bitfield that decides with constellation of lane markings and road edges is valid. \n\n
	*	\@asap_name: P_DPRSIA_TriggerCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_TurnSignReset_bool; /*!< @description
	*	If this parameter is enabled, the turn signal holding time is reseted when the driver switches on the turn light in the other direction. \n\n
	*	\@asap_name: P_DPRSIA_TurnSignReset_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSIA_UncoupledLWEnable_bool; /*!< @description
	*	If the switch in on, the uncoupled model lane width will be used. Else, the coupled model lane width. \n\n
	*	\@asap_name: P_DPRSIA_UncoupledLWEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_AbortDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_AbortFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_AbortFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_AbortFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_AbortSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_AbortSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_CancelDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_CancelFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_CancelFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_CancelFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_CancelSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_CancelSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_DebugDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
	*	\@asap_name: P_DPRSMI_DebugDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_DebugSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDP_btf are used for the SysState debug signal. \n\n
	*	\@asap_name: P_DPRSMI_DebugSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_ErrorStateRDPEnable_bool; /*!< @description
	*	Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPRSMI_ErrorStateRDPEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_ErrorStateRDP_bool; /*!< @description
	*	Parameter that simulates the behaviour of the Error State Signal. \n\n
	*	\@asap_name: P_DPRSMI_ErrorStateRDP_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_FinishCondEnable_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_FinishCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_LatDMCClearEnable_bool; /*!< @description
	*	Switch for the LatDMC clearance condition. \n\n
	*	\@asap_name: P_DPRSMI_LatDMCClearEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_LnOverlapEnable_bool; /*!< @description
	*	Trigger enabler when a road edge and a lane marking overlap. \n\n
	*	\@asap_name: P_DPRSMI_LnOverlapEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_QuTrajCtrCancel_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to cancel an RDP intevention. \n\n
	*	\@asap_name: P_DPRSMI_QuTrajCtrCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_QuTrajCtrClearance_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to give the clearance to an RDP intevention. \n\n
	*	\@asap_name: P_DPRSMI_QuTrajCtrClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_RDPSwitchEnable_bool; /*!< @description
	*	Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPRSMI_RDPSwitchEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_RDPSwitch_bool; /*!< @description
	*	Parameter that simulates the behaviour of the HMI Switch. \n\n
	*	\@asap_name: P_DPRSMI_RDPSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SafeSitStateLn_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_SafeSitStateLn_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SafeSitStateRe_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
	*	\@asap_name: P_DPRSMI_SafeSitStateRe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SideCondCancel_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SideCondCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SideCondDebug_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used for the SysState debug signal. \n\n
	*	\@asap_name: P_DPRSMI_SideCondDebug_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SideCondEnable_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SideCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_StrgRdyDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_StrgRdyFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_StrgRdyFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_StrgRdyFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_StrgRdySpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_StrgRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SuppressDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SuppressFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SuppressFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SuppressFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_SuppressSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_SuppressSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMI_TrgIgnoreLnContg_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_TrgIgnoreLnContg_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_WeakRdyDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_WeakRdyFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_WeakRdyFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_WeakRdyFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMI_WeakRdySpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRSMI_WeakRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_AbortDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_AbortFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf  are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_AbortFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_AbortFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_AbortSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used to abort a warning. \n\n
	*	\@asap_name: P_DPRSMW_AbortSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_CancelDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_CancelFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_CancelFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_CancelFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_CancelSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_CancelSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_DebugDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
	*	\@asap_name: P_DPRSMW_DebugDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_DebugSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used for the SysState debug signal. \n\n
	*	\@asap_name: P_DPRSMW_DebugSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_ErrorStateRDWEnable_bool; /*!< @description
	*	Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPRSMW_ErrorStateRDWEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_ErrorStateRDW_bool; /*!< @description
	*	Parameter that simulates the behaviour of the Error State Signal. \n\n
	*	\@asap_name: P_DPRSMW_ErrorStateRDW_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_FinishCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions are used in order to finish a warning. \n\n
	*	\@asap_name: P_DPRSMW_FinishCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_LnOverlapEnable_bool; /*!< @description
	*	Trigger enabler when a road edge and a lane marking overlap. \n\n
	*	\@asap_name: P_DPRSMW_LnOverlapEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_RDWSwitchEnable_bool; /*!< @description
	*	Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
	*	\@asap_name: P_DPRSMW_RDWSwitchEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_RDWSwitch_bool; /*!< @description
	*	Parameter that simulates the behaviour of the HMI Switch. \n\n
	*	\@asap_name: P_DPRSMW_RDWSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SafeSitStateLn_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two warnings with the same dangerous situation. \n\n
	*	\@asap_name: P_DPRSMW_SafeSitStateLn_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SafeSitStateRe_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two warnings with the same dangerous situation. \n\n
	*	\@asap_name: P_DPRSMW_SafeSitStateRe_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SideCondCancel_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used in order to cancel a warning. \n\n
	*	\@asap_name: P_DPRSMW_SideCondCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SideCondDebug_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used for the SysState debug signal \n\n
	*	\@asap_name: P_DPRSMW_SideCondDebug_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SideCondEnable_btm; /*!< @description
	*	Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used in order to trigger a warning. \n\n
	*	\@asap_name: P_DPRSMW_SideCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_StrgRdyDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_StrgRdyFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_StrgRdyFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_StrgRdyFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPRSMW_StrgRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_StrgRdySpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
	*	\@asap_name: P_DPRSMW_StrgRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SuppressDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SuppressFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SuppressFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SuppressFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_SuppressSpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used to suppress a warning. \n\n
	*	\@asap_name: P_DPRSMW_SuppressSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_TrgIgnoreLnContg_bool; /*!< @description
	*	Switch to ignore a lane marking when it is there, to trigger like a road edge only. \n\n
	*	\@asap_name: P_DPRSMW_TrgIgnoreLnContg_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRSMW_TriggerAlwaysOn_bool; /*!< @description
	*	If this switch is on, the trigger conditions (DLC or TLC/DRC or TRC) have to be fulfilled the whole time the trigger is being held, in order to have a trigger. Else, only the trigger holding time is relevant. \n\n
	*	\@asap_name: P_DPRSMW_TriggerAlwaysOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_WeakRdyDrvSt_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_WeakRdyFctStCtr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_WeakRdyFctStErr_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_WeakRdyFctStNotAv_btm; /*!< @description
	*	Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRSMW_WeakRdySpecific_btm; /*!< @description
	*	Bitfield that controls which conditions of S_DPRSIA_SpecificRDP_btf are used for the weak ready conditions (relevant for trigger). \n\n
	*	\@asap_name: P_DPRSMW_WeakRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTTG_TargetTrajPT1Active_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTTG_TargetTrajPT1Active_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTTG_TgtCntrLnEnable_bool; /*!< @description
	*	Parameter that enables the target in the center of the lane. \n\n
	*	\@asap_name: P_DPRTTG_TgtCntrLnEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTTG_TgtCntrRdEnable_bool; /*!< @description
	*	If there is a road edge in the dangerous side and a lane marking in the opposite side, this parameter enables the target to be placed in the center of them both. \n\n
	*	\@asap_name: P_DPRTTG_TgtCntrRdEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTVG_HighStatAccu_bool; /*!< @description
	*	High Stationary Accuracy enabler \n\n
	*	\@asap_name: P_DPRTVG_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTVG_LimiterActivated_bool; /*!< @description
	*	Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
	*	\@asap_name: P_DPRTVG_LimiterActivated_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DPRTVG_TrajPlanServQu_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_TrajPlanServQu_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTVG_TriggerReplan_bool; /*!< @description
	*	Trigger replan flag. Enables a replanning when there is corridor information update. \n\n
	*	\@asap_name: P_DPRTVG_TriggerReplan_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DPRTVG_UseLtcyComp_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DPRTVG_UseLtcyComp_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DRMDAE_1stIncCycle_nu; /*!< @description
	*	First HandsOff cycle with Active funciton when the duration of the warning should be incremented \n\n
	*	\@asap_name: P_DRMDAE_1stIncCycle_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_DRMDAE_RlvntConfFct_btf; /*!< @description
	*	Mask to determine which functions are relvant for Driver Monitoring System warning. \n
	*	Should be the confort functions, which are being degraded in case of hands off. \n\n
	*	\@asap_name: P_DRMDAE_RlvntConfFct_btf \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DRMHOD_AngleSensAvailable_bool; /*!< @description
	*	1 - Use Angle variant \n
	*	0 - Use torque bsaed algorithm \n\n
	*	\@asap_name: P_DRMHOD_AngleSensAvailable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DRMHOD_BasicDebounceOnly_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_BasicDebounceOnly_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	E_DRMHOD_DebugModeType_t	P_DRMHOD_DebugMode_nu; /*!< @description
	*	Debug mode for DRMHOD \n\n
	*	\@asap_name: P_DRMHOD_DebugMode_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@values: E_DRMHOD_DebugModeType \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DRMHOD_ExternalSensorUsed_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_ExternalSensorUsed_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DRMHOD_HandsOffLimit_gen; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HandsOffLimit_gen \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_DRMHOD_HandsOnLimit_gen; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_DRMHOD_HandsOnLimit_gen \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_HMODFL_UsePassiveAvlbFct_bool; /*!< @description
	*	Enable to use also state passive in  \n
	*	S_HMODFL_AvailableFunction_btf \n\n
	*	\@asap_name: P_HMODFL_UsePassiveAvlbFct_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_100_0_1_t	P_HMODFL_WarningCycle_nu; /*!< @description
	*	LKA change status warning cycle. \n\n
	*	\@asap_name: P_HMODFL_WarningCycle_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_60_1em3_t	P_JCNCTR_ELKAccPedalPosNoSupDur_sec;
	f32_Perc_0_100_1em3_t	P_JCNCTR_ELKAccPedalPosNoSup_nu;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKAccPedalPosSupDur_sec;
	f32_Perc_0_100_1em3_t	P_JCNCTR_ELKAccPedalPosSup_nu;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKActiveStCtrNoSupTime_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKActiveStCtrSupTime_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKBothLaneInvalidSupDur_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKBothLaneValidNoSupDur_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKCurvatureNoSupDur_sec;
	f32_1pm_m0p1_0p1_1em3_t	P_JCNCTR_ELKCurvatureNoSup_1pm;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKCurvatureSupDur_sec;
	f32_1pm_m0p1_0p1_1em3_t	P_JCNCTR_ELKCurvatureSup_1pm;
    u16_NoUnit_0_65535_0_1_t	P_JCNCTR_ELKCustom_btm;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKMainCylPresNoSupDur_sec;
	u32_Pa_0_1500000_0_1_t	P_JCNCTR_ELKMainCylPresNoSup_pa;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKMainCylPresSupDur_sec;
    u32_Pa_0_1500000_0_1_t	P_JCNCTR_ELKMainCylPresSup_pa;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKManualTrqNoSupDur_sec;
	f32_Nm_m100_100_1em3_t	P_JCNCTR_ELKManualTrqNoSup_Nm;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKManualTrqSupDur_sec;
	f32_Nm_m100_100_1em3_t	P_JCNCTR_ELKManualTrqSup_Nm;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_ELKMaxLaneWidthNoSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKMaxLaneWidthSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_ELKMaxLaneWidthSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKMinLaneWidthNoSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_ELKMinLaneWidthNoSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKMinLaneWidthSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_ELKMinLaneWidthSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKYawRateNoSupDur_sec;
	f32_radps_m1_1_1em3_t	P_JCNCTR_ELKYawRateNoSup_rps;
	f32_s_0_60_1em3_t	P_JCNCTR_ELKYawRateSupDur_sec;
	f32_radps_m1_1_1em3_t	P_JCNCTR_ELKYawRateSup_rps;
	f32_mps_m20_20_1em3_t   P_JCNCTR_ELKLatVel_mps;
	// # date: <2023-06-28>, author: <Jie, Tang>, reason: <C673 & C385: lateral velocity check>
	f32_mps_m20_20_1em3_t P_JCNCTR_VelLatLeRDP_mps;
	f32_mps_m20_20_1em3_t P_JCNCTR_VelLatRiRDP_mps;
	f32_mps_m20_20_1em3_t P_JCNCTR_VelLatLeALCA_mps;
	f32_mps_m20_20_1em3_t P_JCNCTR_VelLatRiALCA_mps;
	
	// f32_s_0_60_1em3_t	P_JCNCTR_LDWAccPedalPosNoSupDur_sec;
	// f32_Perc_0_100_1em3_t	P_JCNCTR_LDWAccPedalPosNoSup_nu;
	// f32_s_0_60_1em3_t	P_JCNCTR_LDWAccPedalPosSupDur_sec;
	// f32_Perc_0_100_1em3_t	P_JCNCTR_LDWAccPedalPosSup_nu;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWActiveStCtrNoSupTime_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWActiveStCtrSupTime_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWBothLaneInvalidSupDur_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWBothLaneValidNoSupDur_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWCurvatureNoSupDur_sec;
	f32_1pm_m0p1_0p1_1em3_t	P_JCNCTR_LDWCurvatureNoSup_1pm;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWCurvatureSupDur_sec;
	f32_1pm_m0p1_0p1_1em3_t	P_JCNCTR_LDWCurvatureSup_1pm;
    u16_NoUnit_0_65535_0_1_t	P_JCNCTR_LDWCustom_btm;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWMainCylPresNoSupDur_sec;	
	u32_Pa_0_1500000_0_1_t	P_JCNCTR_LDWMainCylPresNoSup_pa;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWMainCylPresSupDur_sec;
    u32_Pa_0_1500000_0_1_t	P_JCNCTR_LDWMainCylPresSup_pa;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWManualTrqNoSupDur_sec;	
	f32_Nm_m100_100_1em3_t	P_JCNCTR_LDWManualTrqNoSup_Nm;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWManualTrqSupDur_sec;
	f32_Nm_m100_100_1em3_t	P_JCNCTR_LDWManualTrqSup_Nm;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LDWMaxLaneWidthNoSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWMaxLaneWidthSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LDWMaxLaneWidthSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWMinLaneWidthNoSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LDWMinLaneWidthNoSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWMinLaneWidthSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LDWMinLaneWidthSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWYawRateNoSupDur_sec;
	f32_radps_m1_1_1em3_t	P_JCNCTR_LDWYawRateNoSup_rps;
	f32_s_0_60_1em3_t	P_JCNCTR_LDWYawRateSupDur_sec;
	f32_radps_m1_1_1em3_t	P_JCNCTR_LDWYawRateSup_rps;
	// f32_s_0_60_1em3_t	P_JCNCTR_LKAAccPedalPosNoSupDur_sec;
	// f32_Perc_0_100_1em3_t	P_JCNCTR_LKAAccPedalPosNoSup_nu;
	// f32_s_0_60_1em3_t	P_JCNCTR_LKAAccPedalPosSupDur_sec;
	// f32_Perc_0_100_1em3_t	P_JCNCTR_LKAAccPedalPosSup_nu;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAActiveStCtrNoSupTime_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAActiveStCtrSupTime_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LKABothLaneInvalidSupDur_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LKABothLaneValidNoSupDur_sec;
	f32_s_0_60_1em3_t	P_JCNCTR_LKACurvatureNoSupDur_sec;
	f32_1pm_m0p1_0p1_1em3_t	P_JCNCTR_LKACurvatureNoSup_1pm;
	f32_s_0_60_1em3_t	P_JCNCTR_LKACurvatureSupDur_sec;
	f32_1pm_m0p1_0p1_1em3_t	P_JCNCTR_LKACurvatureSup_1pm;
    u16_NoUnit_0_65535_0_1_t	P_JCNCTR_LKACustom_btm;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAMainCylPresNoSupDur_sec;	
	u32_Pa_0_1500000_0_1_t	P_JCNCTR_LKAMainCylPresNoSup_pa;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAMainCylPresSupDur_sec;
    u32_Pa_0_1500000_0_1_t	P_JCNCTR_LKAMainCylPresSup_pa;
	// # date: <2023-06-28>, author: <Jie, Tang>, reason: <C673 new requirement: brake pedal distance check>
	f32_s_0_60_1em3_t P_JCNCTR_BrakePedalPostionNoSupDur_sec;
	f32_m_0_10_1em3_t P_JCNCTR_BrakePedalPostionNoSup_mm;
	f32_s_0_60_1em3_t P_JCNCTR_BrakePedalPostionSupDur_sec;
	f32_m_0_10_1em3_t P_JCNCTR_BrakePedalPostionSup_mm;

	f32_s_0_60_1em3_t	P_JCNCTR_LKAManualTrqNoSupDur_sec;
	f32_Nm_m100_100_1em3_t	P_JCNCTR_LKAManualTrqNoSup_Nm;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAManualTrqSupDur_sec;
	f32_Nm_m100_100_1em3_t	P_JCNCTR_LKAManualTrqSup_Nm;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LKAMaxLaneWidthNoSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAMaxLaneWidthSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LKAMaxLaneWidthSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAMinLaneWidthNoSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LKAMinLaneWidthNoSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAMinLaneWidthSupDur_sec;
	f32_m_0_10_1em3_t	P_JCNCTR_LKAMinLaneWidthSup_met;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAYawRateNoSupDur_sec;
	f32_radps_m1_1_1em3_t	P_JCNCTR_LKAYawRateNoSup_rps;
	f32_s_0_60_1em3_t	P_JCNCTR_LKAYawRateSupDur_sec;
	f32_radps_m1_1_1em3_t	P_JCNCTR_LKAYawRateSup_rps;
	
	u8_NoUnit_0_1_0_1_t	P_LCRSIA_ConstrSite_bool; /*!< @description
	*	Construction Site Enable Switch for ALCA \n\n
	*	\@asap_name: P_LCRSIA_ConstrSite_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSIA_LaneSafetyBitmask_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_LaneSafetyBitmask_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSIA_LaneWidthSIFOn_bool; /*!< @description
	*	If the switch is on, the Coupled/Uncoupled Lane Width will be taking into account and checked to trigger or cancel an intervention. If not, it will be ignored. \n\n
	*	\@asap_name: P_LCRSIA_LaneWidthSIFOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSIA_LaneWidthWideLn_bool; /*!< @description
	*	New Lane Width too big logic switch. If on, lanes too wide will be considerd valid and a default lane width will be used. \n\n
	*	\@asap_name: P_LCRSIA_LaneWidthWideLn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSIA_SafetyIfaceALCAOn_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_SafetyIfaceALCAOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSIA_TurnSignReset_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_TurnSignReset_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSIA_UncoupledLWEnable_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSIA_UncoupledLWEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_ALCALightEnable_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_ALCALightEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_ALCASwitchEnable_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_ALCASwitchEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_ALCASwitch_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_ALCASwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_AbortDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_AbortDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_AbortFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_AbortFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_AbortFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_AbortFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_AbortFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_AbortFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_AbortSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_AbortSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVDanRearObjBSRearLe_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVDanRearObjBSRearLe_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVDanRearObjBSRearRi_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVDanRearObjBSRearRi_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVDanRearObjFOVRearLe_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVDanRearObjFOVRearLe_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVDanRearObjFOVRearRi_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVDanRearObjFOVRearRi_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVQualifRearLe_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVQualifRearLe_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVQualifRearRi_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVQualifRearRi_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVSopMSFlagRearLe_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVSopMSFlagRearLe_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BVSopMSFlagRearRi_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BVSopMSFlagRearRi_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_BypassSRRSignal_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_BypassSRRSignal_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_CancelDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_CancelFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_CancelFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_CancelFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_CancelSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_CancelSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_DebugDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_DebugDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_DebugSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_DebugSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_ErrorStateALCAEnable_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_ErrorStateALCAEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_ErrorStateALCA_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_ErrorStateALCA_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_FinishCondEnable_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_FinishCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRSMI_LatDMCClearEnable_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_LatDMCClearEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_QuTrajCtrCancel_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to cancel an ALCA intevention. \n\n
	*	\@asap_name: P_LCRSMI_QuTrajCtrCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_QuTrajCtrClearance_btm; /*!< @description
	*	Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to give the clearance to an ALCA intevention. \n\n
	*	\@asap_name: P_LCRSMI_QuTrajCtrClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SafeSituationState_btm; /*!< @description
	*	This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
	*	\@asap_name: P_LCRSMI_SafeSituationState_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SideCondCancel_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SideCondCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SideCondDebug_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SideCondDebug_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SideCondEnable_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SideCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_StrgRdyDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_StrgRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_StrgRdyFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_StrgRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_StrgRdyFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_StrgRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_StrgRdyFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_StrgRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_StrgRdySpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_StrgRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SuppressDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SuppressDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SuppressFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SuppressFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SuppressFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SuppressFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SuppressFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SuppressFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_SuppressSpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_SuppressSpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_TriggerCondEnable_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_TriggerCondEnable_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_WeakRdyDrvSt_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_WeakRdyDrvSt_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_WeakRdyFctStCtr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_WeakRdyFctStCtr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_WeakRdyFctStErr_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_WeakRdyFctStErr_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_WeakRdyFctStNotAv_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_WeakRdyFctStNotAv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRSMI_WeakRdySpecific_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRSMI_WeakRdySpecific_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRTTG_TargetTrajPT1Active_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTTG_TargetTrajPT1Active_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRTTG_TgtCntrLnEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTTG_TgtCntrLnEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRTVG_HighStatAccu_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRTVG_LimiterActivated_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_LimiterActivated_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_LCRTVG_TrajPlanServQu_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_TrajPlanServQu_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRTVG_TriggerReplan_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_TriggerReplan_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LCRTVG_UseLtcyComp_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LCRTVG_UseLtcyComp_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LDP_DlcLimitCustom_bool; /*!< @description
	*	Customer Specific DLC Limit Switch for the LDP. \n\n
	*	\@asap_name: P_LDP_DlcLimitCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LDP_DlcTriggerCustom_bool; /*!< @description
	*	Customer Specific DLC Threshold Switch for the LDP. \n\n
	*	\@asap_name: P_LDP_DlcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LDP_Existing_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LDP_Existing_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LDW_DlcLimitCustom_bool; /*!< @description
	*	Customer Specific DLC Limit Switch for the LDW. \n\n
	*	\@asap_name: P_LDW_DlcLimitCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LDW_DlcTriggerCustom_bool; /*!< @description
	*	Customer Specific DLC Threshold Switch for the LDW. \n\n
	*	\@asap_name: P_LDW_DlcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LDW_Existing_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_LDW_Existing_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_LKA_Available_bool; /*!< @description
	*	Indicates TRUE if LKA is a coded function of the system \n\n
	*	\@asap_name: P_LKA_Available_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	E_LCF_FunctionV3Type_t	P_MCTLFC_ControllingFunction_nu; /*!< @description
	*	Error Injection value for S_MCTLFC_ControllingFunction_nu \n\n
	*	\@asap_name: P_MCTLFC_ControllingFunction_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@values: E_LCF_FunctionV3Type \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 7
	*/
	
	u8_NoUnit_0_1_0_1_t	P_MCTLFC_ErrInjEnable_bool; /*!< @description
	*	Error Injection Switch for MCTLFC \n\n
	*	\@asap_name: P_MCTLFC_ErrInjEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_MCTLFC_PriorityVector_nu[7]; /*!< @description
	*	The order in the priority of the functions will be [TJA LDP LDPOC RDP ALCA AOLC ESA]. No two numbers shall be equal, except for 0. \n\n
	*	\@asap_name: P_MCTLFC_PriorityVector_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_MCTLFC_RampOutOverwrite_bool[7]; /*!< @description
	*	If the corresponding bit is activated, a function in degradation can be overwritten by a function with a lower priority. \n\n
	*	\@asap_name: P_MCTLFC_RampOutOverwrite_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_AccObjCheckLane_bool; /*!< @description
	*	Switch to enable use of TJAOBF object-lane-check for target object validation \n\n
	*	\@asap_name: P_ODPFOH_AccObjCheckLane_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_EnableObjTraceKF_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_EnableObjTraceKF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_EnableTransAtStart_bool; /*!< @description
	*	TRUE if transition handling is enabled at Kalman initialization \n\n
	*	\@asap_name: P_ODPFOH_EnableTransAtStart_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_MinPosXVelXOn_bool; /*!< @description
	*	TRUE to switch on velocity dependent minimum long object position logic \n\n
	*	\@asap_name: P_ODPFOH_MinPosXVelXOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_20_0_1_t	P_ODPFOH_MinValidEntries_nu; /*!< @description
	*	Minimum required valid history points \n\n
	*	\@asap_name: P_ODPFOH_MinValidEntries_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 20
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ODPFOH_NumObjDistHistParts_nu; /*!< @description
	*	Number of sections relatively to object x-distance \n\n
	*	\@asap_name: P_ODPFOH_NumObjDistHistParts_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_ODPFOH_ObjKFDegrUpdateQu_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDegrUpdateQu_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_ObjKFDegrUpdate_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFDegrUpdate_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ODPFOH_ObjKFMinInitQual_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFMinInitQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ODPFOH_ObjKFMinUpdateQual_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_ObjKFMinUpdateQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_PT1CrvEnable_bool; /*!< @description
	*	TRUE if low pass filter for curvature is enabled \n\n
	*	\@asap_name: P_ODPFOH_PT1CrvEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_PT1HeadEnable_bool; /*!< @description
	*	TRUE if low pass filter for heading is enabled \n\n
	*	\@asap_name: P_ODPFOH_PT1HeadEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_PT1PosY0Enable_bool; /*!< @description
	*	TRUE means low pass filter for lateral target position is enabled \n
	*	FALSE means low pass filter for lateral target position is disabled \n\n
	*	\@asap_name: P_ODPFOH_PT1PosY0Enable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_PT1PosYEnable_bool; /*!< @description
	*	TRUE means low pass filter for lateral position is enabled \n
	*	FALSE means low pass filter for lateral position is disabled \n\n
	*	\@asap_name: P_ODPFOH_PT1PosYEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_PT1YawRateEnable_bool; /*!< @description
	*	TRUE means low pass filter for input yaw rate is enabled \n
	*	FALSE means low pass filter for input yaw rate is disabled \n\n
	*	\@asap_name: P_ODPFOH_PT1YawRateEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ODPFOH_SignLimStrEstLSP_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_SignLimStrEstLSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_100_0_1_t	P_ODPFOH_SignLimStrEstRSP_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_SignLimStrEstRSP_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseCrvOnlyLSM_bool; /*!< @description
	*	TRUE: only curvature is used for target trajectory (PosY0 and heading angle are set to 0) \n
	*	FALSE: PosY0 and heading angle are used, curvature is set to 0 \n\n
	*	\@asap_name: P_ODPFOH_UseCrvOnlyLSM_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseEstimPosY_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseEstimPosY_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseOutputGradLim_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseOutputGradLim_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseOutputRangeLim_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseOutputRangeLim_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UsePosYReduction_bool; /*!< @description
	*	TRUE: input object y-position is squared if it is below a certain threshold \n
	*	FALSE: original object y-position is used \n\n
	*	\@asap_name: P_ODPFOH_UsePosYReduction_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UsePosYcorr_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UsePosYcorr_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseSignLimCrv_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseSignLimCrv_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseSignLimHead_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseSignLimHead_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseSignLimPosY0_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseSignLimPosY0_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseStrEstimGradLim_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseStrEstimGradLim_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseStrEstimLimit_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseStrEstimLimit_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseStrEstimPT1_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_UseStrEstimPT1_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOH_UseStraightEstim_bool; /*!< @description
	*	TRUE: own straight estimation calculation [%] will be used for weighting between 1st and 2nd order polyfit [0..1] \n
	*	FALSE: original Polyfit output is used \n\n
	*	\@asap_name: P_ODPFOH_UseStraightEstim_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_20_0_1_t	P_ODPFOH_YawRateDelayCycles_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_ODPFOH_YawRateDelayCycles_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 20
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOP_EnableLatMovFreeze_bool; /*!< @description
	*	TRUE enables freeze of lateral object data (position, velocity, acceleration). FALSE disables it. \n\n
	*	\@asap_name: P_ODPFOP_EnableLatMovFreeze_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_ODPFOP_MinObjQualitiy_perc; /*!< @description
	*	Minimum object quality for the validation \n\n
	*	\@asap_name: P_ODPFOP_MinObjQualitiy_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOP_ObjRelToRadar_bool; /*!< @description
	*	Determines if the objects are expressed in the radar coordinate system \n\n
	*	\@asap_name: P_ODPFOP_ObjRelToRadar_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOP_RearAxleCoordSys_bool; /*!< @description
	*	Flag if the object data should be transformed to the rear axle coordinate system. \n\n
	*	\@asap_name: P_ODPFOP_RearAxleCoordSys_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOP_UseEstimPosY4Yaw_bool; /*!< @description
	*	If TRUE the internally estimated PosY is used with respect to RelVelY and a constant time. \n
	*	If FALSE the AccObjPosY is used. \n\n
	*	\@asap_name: P_ODPFOP_UseEstimPosY4Yaw_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_ODPFOP_UseOwnObjYaw_bool; /*!< @description
	*	If TRUE then own calculated object yaw angle is used, if FALSE then input signal is used \n\n
	*	\@asap_name: P_ODPFOP_UseOwnObjYaw_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDP_DlcLimitCustom_bool; /*!< @description
	*	Customer Specific DLC Limit Switch for the RDP. \n\n
	*	\@asap_name: P_RDP_DlcLimitCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDP_DlcTriggerCustom_bool; /*!< @description
	*	Customer Specific DLC Threshold Switch for the RDP. \n\n
	*	\@asap_name: P_RDP_DlcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDP_DrcLimitCustom_bool; /*!< @description
	*	Customer Specific DRC Limit Switch for the RDP. \n\n
	*	\@asap_name: P_RDP_DrcLimitCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDP_DrcTriggerCustom_bool; /*!< @description
	*	Customer Specific DRC Threshold Switch for the RDP. \n\n
	*	\@asap_name: P_RDP_DrcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDP_Existing_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_RDP_Existing_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDW_DlcLimitCustom_bool; /*!< @description
	*	Customer Specific DLC Limit Switch for the RDW. \n\n
	*	\@asap_name: P_RDW_DlcLimitCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDW_DlcTriggerCustom_bool; /*!< @description
	*	Customer Specific DLC Threshold Switch for the RDW. \n\n
	*	\@asap_name: P_RDW_DlcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDW_DrcLimitCustom_bool; /*!< @description
	*	Customer Specific DRC Limit Switch for the RDW. \n\n
	*	\@asap_name: P_RDW_DrcLimitCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDW_DrcTriggerCustom_bool; /*!< @description
	*	Customer Specific DRC Threshold Switch for the RDW. \n\n
	*	\@asap_name: P_RDW_DrcTriggerCustom_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_RDW_Existing_nu; /*!< @description
	*	Main parameter switch of the RDW. \n\n
	*	\@asap_name: P_RDW_Existing_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_1_4_0_1_t	P_TCTCDC_OssDeltaTheta_nu; /*!< @description
	*	Output Source Selection of DeltaTheta \n
	*	------------------------------------------ \n
	*	1: Raw unfiltered \n
	*	2: PT1 Filter \n
	*	3: Plant Observer \n
	*	4: Old Course Angle Observer \n\n
	*	\@asap_name: P_TCTCDC_OssDeltaTheta_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 4
	*/
	
	u8_NoUnit_1_3_0_1_t	P_TCTCDC_OssDeltaY_nu; /*!< @description
	*	Output Source Selection of DeltaY \n
	*	------------------------------------------ \n
	*	1: Raw unfiltered \n
	*	2: PT1 Filter \n
	*	3: Plant Observer \n\n
	*	\@asap_name: P_TCTCDC_OssDeltaY_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 3
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCDC_UseAltOBFApproach_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTCDC_UseAltOBFApproach_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCDC_UseTrajCrv_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTCDC_UseTrajCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCDC_WtchdgActive_nu; /*!< @description
	*	1: Watchdog is activated \n
	*	0: Watchdog is deactivated \n\n
	*	\@asap_name: P_TCTCDC_WtchdgActive_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_10_0_1_t	P_TCTCLM_ErrCntrCyclesToCheck_nu; /*!< @description
	*	Error Counter -> Number of Cycles to Check for the sliding sum \n\n
	*	\@asap_name: P_TCTCLM_ErrCntrCyclesToCheck_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	u8_NoUnit_0_20_0_1_t	P_TCTCLM_ErrCntrDisengageThr_nu; /*!< @description
	*	Thresold of the Error Counter leading to a function disengagement \n\n
	*	\@asap_name: P_TCTCLM_ErrCntrDisengageThr_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 20
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCLM_FbcCrvInterface_nu; /*!< @description
	*	Select interface for the feedback controller \n
	*	0: Steer Angle Interface \n
	*	1: Curvature Interface \n\n
	*	\@asap_name: P_TCTCLM_FbcCrvInterface_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCLM_FfcCrvInterface_nu; /*!< @description
	*	Select interface for the feedforward controller \n
	*	0: Steer Angle Interface \n
	*	1: Curvature Interface \n\n
	*	\@asap_name: P_TCTCLM_FfcCrvInterface_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCLM_QuServiceErrMemAct_nu; /*!< @description
	*	Activate/Deactivate hold functionality of degradation request \n
	*	0: Deactivate \n
	*	1: Activate \n\n
	*	\@asap_name: P_TCTCLM_QuServiceErrMemAct_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTCLM_QuServiceOverride_nu; /*!< @description
	*	Force degradation request via signal S_TCTCLM_QuServTrajCtr \n
	*	0: Use conventional degradation request conditions \n
	*	1: Force degradation request \n\n
	*	\@asap_name: P_TCTCLM_QuServiceOverride_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTCLM_WtchdgCDCQuSv_btm; /*!< @description
	*	Bitmask for selecting the bits to be checked in the signal S_TCTCDC_QualifierService_nu \n\n
	*	\@asap_name: P_TCTCLM_WtchdgCDCQuSv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTCLM_WtchdgCLMQuSv_btm; /*!< @description
	*	Bitmask for selecting the bits to be checked in the signal D_TCTCLM_QualifierService_nu \n\n
	*	\@asap_name: P_TCTCLM_WtchdgCLMQuSv_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTDTE_BnkAglCompActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_BnkAglCompActive_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTDTE_CroWindCompActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_CroWindCompActive_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_5_0_1_t	P_TCTDTE_DelayCyclesDeltaDi_nu; /*!< @description
	*	Number of cycles the RTE Steer Angle Signal is delayed in the Disturbance Observer \n\n
	*	\@asap_name: P_TCTDTE_DelayCyclesDeltaDi_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_5_0_1_t	P_TCTDTE_DelayCyclesLaDMC_nu; /*!< @description
	*	Number of cycle delays of the LaDMC \n\n
	*	\@asap_name: P_TCTDTE_DelayCyclesLaDMC_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTDTE_DistrbCompActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTDTE_DistrbCompActive_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_2_0_1_t	P_TCTDTE_Dss_nu; /*!< @description
	*	P_TCTDTE_Dss_nu \n
	*	(Disturbance Source Select) \n
	*	---------------------------------------------------- \n
	*	0 = Off \n
	*	1 = Feedthrough of General Disturbance Compensator \n
	*	2 = Arbitration of BaC and CroC (Default) \n\n
	*	\@asap_name: P_TCTDTE_Dss_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_5_0_1_t	P_TCTEST_DelayCyclesDeltaSs_nu; /*!< @description
	*	Number of cycles the RTE Steer Angle Signal is delayed in the Side Slip Angle Observer \n\n
	*	\@asap_name: P_TCTEST_DelayCyclesDeltaSs_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_1_4_0_1_t	P_TCTEST_IssPlObsCurvature_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_IssPlObsCurvature_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 4
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTEST_SObsActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTEST_SObsActive_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTEST_UseSteerAngleLatDMC_nu; /*!< @description
	*	0: Use Steer Angle signal provided by VDY \n
	*	1: Use Steer Angle signal provided by LatDMC \n\n
	*	\@asap_name: P_TCTEST_UseSteerAngleLatDMC_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTFFC_DecelModeHyst_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelModeHyst_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_TCTFFC_DecelReduction_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DecelReduction_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTFFC_DynGainMode_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainMode_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTFFC_DynGainPrecCtrlFcn_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainPrecCtrlFcn_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTFFC_DynGainPrecCtrlMode_btm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_DynGainPrecCtrlMode_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_2_0_1_t	P_TCTFFC_OssFfcCrv_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_OssFfcCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_Perc_0_100_0_1_t	P_TCTFFC_UpDwnHllReduction_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_UpDwnHllReduction_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TCTFFC_UpDwnHllThres_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_UpDwnHllThres_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTFFC_UseAltOBFApproach_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTFFC_UseAltOBFApproach_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_ActivateDynBacGain_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTLGC_ActivateDynBacGain_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_ActivateOverride_nu; /*!< @description
	*	1: Force ENABLE OUTPUT = 1 \n
	*	0: Normal ENABLE OUTPUT behavior \n\n
	*	\@asap_name: P_TCTLGC_ActivateOverride_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_CacLaDmcCompEnable_nu; /*!< @description
	*	1: Enable filter to compensate the LaDMC's transmission behavior \n
	*	0: Disable filter to compensate the LaDMC's transmission behavior \n\n
	*	\@asap_name: P_TCTLGC_CacLaDmcCompEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTLGC_CacMode_nu; /*!< @description
	*	Course Angle Controller Mode: \n
	*	xxxx xxx0	Controller deactivated \n
	*	xxxx xxx1	P-Controller \n
	*	xxxx xx11	PDT1-Controller, DT1-Controller parallel to the P-Controller \n
	*	xxxx x1x1	PI-Controller, I-Part parallel to the P-Controller \n
	*	xxxx 1xx1	PPT1-Controller, PT1-Part parallel to the P-Controller \n\n
	*	\@asap_name: P_TCTLGC_CacMode_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTLGC_CssCrv_nu; /*!< @description
	*	Mode of TCTLGC (Curvature interface): \n
	*	Source  |  Controller \n
	*	0000 0000: Off \n
	*	0000 xxx1: FBC active \n
	*	0000 xx1x: FFC active \n
	*	0000 x1xx: DC active \n
	*	0000 1xxx: BAC active \n
	*	0001 0000: Chirp active \n\n
	*	\@asap_name: P_TCTLGC_CssCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTLGC_CssDeltaF_nu; /*!< @description
	*	Mode of TCTLGC (Steer Angle interface): \n
	*	Source  |  Controller \n
	*	0000 0000: Off \n
	*	0000 xxx1: FBC active \n
	*	0000 xx1x: FFC active \n
	*	0000 x1xx: DC active \n
	*	0000 1xxx: BAC active \n
	*	0001 0000: Chirp active \n\n
	*	\@asap_name: P_TCTLGC_CssDeltaF_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTLGC_DynIntResetSelect_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TCTLGC_DynIntResetSelect_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTLGC_DynPT1ResetSelect_nu; /*!< @description
	*	0000 0000 : Dynamic PT1 reset deactivated \n
	*	0000 xxx1 : Reset based on lateral deviation active \n
	*	0000 xx1x : Reset based on driver torque active \n
	*	0000 x1xx : Reset based on standstill active \n\n
	*	\@asap_name: P_TCTLGC_DynPT1ResetSelect_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_LdcLaDmcCompEnable_nu; /*!< @description
	*	1: Enable filter to compensate the LaDMC's transmission behavior \n
	*	0: Disable filter to compensate the LaDMC's transmission behavior \n\n
	*	\@asap_name: P_TCTLGC_LdcLaDmcCompEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TCTLGC_LdcMode_nu; /*!< @description
	*	Y-Coordinate Controller Mode: \n
	*	xxxx xxx0	Controller is deactivated \n
	*	xxxx xxx1	P-Controller \n
	*	xxxx xx11	PDT1-Controller, DT1-Controller parallel to the P-Controller \n
	*	xxxx x1x1	PI-Controller, I-Part parallel to the P-Controller \n
	*	xxxx 1xx1	PPT1-Controller, PT1-Part parallel to the P-Controller \n\n
	*	\@asap_name: P_TCTLGC_LdcMode_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_PT1CoAnErrEnable_nu; /*!< @description
	*	1: Enable low pass first order for filtering the control error regarding the Course Angle \n
	*	0: Disable low pass first order for filtering the control error regarding the Course Angle \n\n
	*	\@asap_name: P_TCTLGC_PT1CoAnErrEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_PT1DeltaFCmdEnable_nu; /*!< @description
	*	1: Enable low pass first order for filtering the control signal DeltaFCmd \n
	*	0: Disable low pass first order for filtering the control signal DeltaFCmd \n\n
	*	\@asap_name: P_TCTLGC_PT1DeltaFCmdEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TCTLGC_PT1YErrEnable_nu; /*!< @description
	*	1: Enable low pass first order for filtering the control error regarding the Y-Coordinate \n
	*	0: Disable low pass first order for filtering the control error regarding the Y-Coordinate \n\n
	*	\@asap_name: P_TCTLGC_PT1YErrEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_CMB_Enabled_bool; /*!< @description
	*	Switch to enable combined mode \n\n
	*	\@asap_name: P_TJACMB_CMB_Enabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_CombinedCrvEnable_bool; /*!< @description
	*	Switch to enable use of combined curvature during lane based combined mode \n\n
	*	\@asap_name: P_TJACMB_CombinedCrvEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_ConstSiteCheckOn_bool; /*!< @description
	*	Switch to enable construction site check for combined mode \n\n
	*	\@asap_name: P_TJACMB_ConstSiteCheckOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_IndVelLimitsEnable_bool; /*!< @description
	*	TRUE if individual combined mode velocities shall be enabled (P_TJACMB_VelXMax_kph, P_TJACMB_VelXMin_kph) \n\n
	*	\@asap_name: P_TJACMB_IndVelLimitsEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_InjectLaneError_bool; /*!< @description
	*	TJACMB error injection for lane validity \n\n
	*	\@asap_name: P_TJACMB_InjectLaneError_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_LaneCheckEnabled_bool; /*!< @description
	*	Switch to enable object-in-lane check for object-based combined mode \n\n
	*	\@asap_name: P_TJACMB_LaneCheckEnabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_LnCurveDtctEnable_bool; /*!< @description
	*	Switch to enable use of lane curvature detection as activation condition for object-based combined mode \n\n
	*	\@asap_name: P_TJACMB_LnCurveDtctEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnCurveMaxPercHyst_perc; /*!< @description
	*	Hysteresis for maximum probability of ABPR straight estimation below which a curve scenario is considered \n\n
	*	\@asap_name: P_TJACMB_LnCurveMaxPercHyst_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnCurveMaxPerc_perc; /*!< @description
	*	Maximum probability of ABPR straight estimation below which a curve scenario is considered \n\n
	*	\@asap_name: P_TJACMB_LnCurveMaxPerc_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnQualGradMaxExit_perc; /*!< @description
	*	Maximum lane quality drop (in one cycle) to consider exit scenario \n\n
	*	\@asap_name: P_TJACMB_LnQualGradMaxExit_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnQualMinContrast_perc; /*!< @description
	*	Minimum lane quality below which low contrast scenario is considered \n\n
	*	\@asap_name: P_TJACMB_LnQualMinContrast_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnQualMinCurve_perc; /*!< @description
	*	Minimum lane quality below which curve scenario is considered (if both lanes below this threshold for more than P_TJACMB_LnQualMinOnTmCurve_sec seconds) \n\n
	*	\@asap_name: P_TJACMB_LnQualMinCurve_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnQualMinExit_perc; /*!< @description
	*	Minimum lane quality below which exit scenario is considered \n\n
	*	\@asap_name: P_TJACMB_LnQualMinExit_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnQualMinHystWR_perc; /*!< @description
	*	Minimum required lane quality hysteresis for lane based combined mode activation \n\n
	*	\@asap_name: P_TJACMB_LnQualMinHystWR_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_LnQualMinWR_perc; /*!< @description
	*	Minimum required lane quality for lane based combined mode activation \n\n
	*	\@asap_name: P_TJACMB_LnQualMinWR_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_LnQualShutOffQulOn_bool; /*!< @description
	*	Switch to enable use of lane quality checks for trigger of combined mode transition from lanes to object \n\n
	*	\@asap_name: P_TJACMB_LnQualShutOffQulOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_MaxTimeObjCtrlOn_bool; /*!< @description
	*	Switch to enable control time limitation of object-based combined mode \n\n
	*	\@asap_name: P_TJACMB_MaxTimeObjCtrlOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_TJACMB_MinObjStraightProb_perc; /*!< @description
	*	Minimum OF straight probability to set higher priority on pure object following mode \n\n
	*	\@asap_name: P_TJACMB_MinObjStraightProb_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_OF_Debug_bool; /*!< @description
	*	Switch to enable debug mode (force object-based combined mode) \n\n
	*	\@asap_name: P_TJACMB_OF_Debug_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_OF_Enabled_bool; /*!< @description
	*	Switch to enable object based combined mode \n\n
	*	\@asap_name: P_TJACMB_OF_Enabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_SetLaneCondInvalid_bool; /*!< @description
	*	Switch to set lane conditions invalid \n\n
	*	\@asap_name: P_TJACMB_SetLaneCondInvalid_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_TransitionHandleOn_bool; /*!< @description
	*	Switch to enable transition handling for transition lane to objects \n\n
	*	\@asap_name: P_TJACMB_TransitionHandleOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJACMB_UseInterCmbCrvCalc_bool; /*!< @description
	*	Switch to enable internal calculation of object (combined) curvature \n\n
	*	\@asap_name: P_TJACMB_UseInterCmbCrvCalc_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_ActiveStCtrlSR_btm; /*!< @description
	*	Bitmask for active state check of vehicle safety functions \n\n
	*	\@asap_name: P_TJAGEN_ActiveStCtrlSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAGEN_CheckTJAErrorState_bool; /*!< @description
	*	Enable TJA error state check of S_RTE_ErrorStateTJA_bool \n\n
	*	\@asap_name: P_TJAGEN_CheckTJAErrorState_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_DrvStInvalidC_btm; /*!< @description
	*	Bitmask value for driver state checks of the cancel condition \n\n
	*	\@asap_name: P_TJAGEN_DrvStInvalidC_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_DrvStInvalidSR_btm; /*!< @description
	*	Bitmask value for driver state checks of the strong ready condition \n\n
	*	\@asap_name: P_TJAGEN_DrvStInvalidSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_DrvStInvalidWR_btm; /*!< @description
	*	Bitmask value for driver state checks of the weak ready condition \n\n
	*	\@asap_name: P_TJAGEN_DrvStInvalidWR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_QuTrajCtrCancel_btm; /*!< @description
	*	Bitmask check for S_TCTCLM_QuServTrajCtr_nu as cancel condition \n\n
	*	\@asap_name: P_TJAGEN_QuTrajCtrCancel_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_QuTrajCtrClearance_btm; /*!< @description
	*	Bitmask check for S_TCTCLM_QuServTrajCtr_nu as clearance condition \n\n
	*	\@asap_name: P_TJAGEN_QuTrajCtrClearance_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_Perc_0_100_0_1_t	P_TJAGEN_QuTrajPlanMinLnQual_perc; /*!< @description
	*	Minimum required lane quality for function re-activation after specific blocking time for TrajPlanCancelQualifier \n\n
	*	\@asap_name: P_TJAGEN_QuTrajPlanMinLnQual_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAGEN_SetSysStOnLatDMC_bool; /*!< @description
	*	Manual switch to set LatDMC system state ON \n\n
	*	\@asap_name: P_TJAGEN_SetSysStOnLatDMC_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_SysStErrorSR_btm; /*!< @description
	*	Bitmask for system error check of vehicle safety functions (ABS, ESC, etc.) for SR condition \n\n
	*	\@asap_name: P_TJAGEN_SysStErrorSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAGEN_SysStNotAvailableWR_btm; /*!< @description
	*	Bitmask to check for weak ready conditions if vehicle safety functions are not available \n\n
	*	\@asap_name: P_TJAGEN_SysStNotAvailableWR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_BothSideBrdgEnable_bool; /*!< @description
	*	TRUE if both-sided bridging/prediction is enabled \n\n
	*	\@asap_name: P_TJALKA_BothSideBrdgEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_ConstSiteCheckOn_bool; /*!< @description
	*	Switch to enable construction site check \n\n
	*	\@asap_name: P_TJALKA_ConstSiteCheckOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJALKA_DrvStInvalidSR_btm; /*!< @description
	*	Bitmask to check if turn signal left/right is engaged \n\n
	*	\@asap_name: P_TJALKA_DrvStInvalidSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_InjectLaneError_bool; /*!< @description
	*	Setting to TRUE will inject single error, which invalidates lanes for P_TJALKA_LaneInvalidTime_sec seconds \n\n
	*	\@asap_name: P_TJALKA_InjectLaneError_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_LC_Enabled_bool; /*!< @description
	*	Indicates TRUE, if lane centering mode is enabled. \n\n
	*	\@asap_name: P_TJALKA_LC_Enabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_TJALKA_LaneQualityHyst_perc; /*!< @description
	*	Minimum lane quality hysteresis \n\n
	*	\@asap_name: P_TJALKA_LaneQualityHyst_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJALKA_LaneQualityMin_perc; /*!< @description
	*	Minimum lane quality \n\n
	*	\@asap_name: P_TJALKA_LaneQualityMin_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_MaxLnWdthUseCoup_bool; /*!< @description
	*	Switch to enable use of coupled lane width for maximum lane width check \n\n
	*	\@asap_name: P_TJALKA_MaxLnWdthUseCoup_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_MinLnWdthUseUncoup_bool; /*!< @description
	*	Switch to enable use of uncoupled lane width for minimum lane width check \n\n
	*	\@asap_name: P_TJALKA_MinLnWdthUseUncoup_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_RampoutPredictOn_bool; /*!< @description
	*	Switch to enable rampout prediction (lane prediction while LatDMC output is set to zero) \n\n
	*	\@asap_name: P_TJALKA_RampoutPredictOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJALKA_TransLnChecksOff_bool; /*!< @description
	*	TRUE if lane quality checks shall be disabled during SALC --> LC transition \n\n
	*	\@asap_name: P_TJALKA_TransLnChecksOff_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAOBF_CheckAccObjValidty_bool; /*!< @description
	*	Switch to enable check of Acc object validity within TJAOBF as SR condition for pure object following \n\n
	*	\@asap_name: P_TJAOBF_CheckAccObjValidty_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAOBF_ConstSiteCheckOn_bool; /*!< @description
	*	Switch to enable construction site check for OF SR condition \n\n
	*	\@asap_name: P_TJAOBF_ConstSiteCheckOn_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJAOBF_DrvStInvalidSR_btm; /*!< @description
	*	Bitmask for turn signal SR condition check \n\n
	*	\@asap_name: P_TJAOBF_DrvStInvalidSR_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAOBF_LaneCheckEnabled_bool; /*!< @description
	*	Switch to enable object in lane evaluation \n\n
	*	\@asap_name: P_TJAOBF_LaneCheckEnabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAOBF_OF_Enabled_bool; /*!< @description
	*	Switch to enable object following mode \n\n
	*	\@asap_name: P_TJAOBF_OF_Enabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJAOBF_ObjBrdgEnabled_bool; /*!< @description
	*	Switch to enable object briding at speeds greated than P_TJAOBF_VelXMax_kph \n\n
	*	\@asap_name: P_TJAOBF_ObjBrdgEnabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJASLC_SALC_Enabled_bool; /*!< @description
	*	Switch to enable semi-automatic lane change functionality \n\n
	*	\@asap_name: P_TJASLC_SALC_Enabled_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATTG_EnableVirtAdjLane_bool; /*!< @description
	*	Enable virtual adjacent lane width for SALC \n\n
	*	\@asap_name: P_TJATTG_EnableVirtAdjLane_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATTG_NewPredEnable_bool; /*!< @description
	*	Switch to enable new prediction implementation \n\n
	*	\@asap_name: P_TJATTG_NewPredEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATTG_PredFreezeCrvChng_bool; /*!< @description
	*	TRUE if curvature change signal shall be frozen during prediction \n\n
	*	\@asap_name: P_TJATTG_PredFreezeCrvChng_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATTG_PredFreezeCrv_bool; /*!< @description
	*	TRUE if curvature signal shall be frozen during prediction \n\n
	*	\@asap_name: P_TJATTG_PredFreezeCrv_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATTG_TransHandleEnable_bool; /*!< @description
	*	Switch to enable mode transition handling \n\n
	*	\@asap_name: P_TJATTG_TransHandleEnable_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATTG_TriggerReplanCMBLC2OF_bool; /*!< @description
	*	Switch to enable replan trigger during Kalman transition lane-based to object-based combined mode \n\n
	*	\@asap_name: P_TJATTG_TriggerReplanCMBLC2OF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_HighStatAccu_bool; /*!< @description
	*	Indicates TRUE, if high stationary accuracy is required. \n\n
	*	\@asap_name: P_TJATVG_HighStatAccu_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_TJATVG_MD1DeratingLevel_perc; /*!< @description
	*	MD1DeratingLevel \n\n
	*	\@asap_name: P_TJATVG_MD1DeratingLevel_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJATVG_MD2DeratingLevel_perc; /*!< @description
	*	MD2DeratingLevel \n\n
	*	\@asap_name: P_TJATVG_MD2DeratingLevel_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TJATVG_MD3DeratingLevel_perc; /*!< @description
	*	MD3DeratingLevel \n\n
	*	\@asap_name: P_TJATVG_MD3DeratingLevel_perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_ModeTransTrigReplan_bool; /*!< @description
	*	Switch to enable trigger replan during mode transitions \n\n
	*	\@asap_name: P_TJATVG_ModeTransTrigReplan_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_SetMaxCrvAndGrdLims_nu; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_SetMaxCrvAndGrdLims_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJATVG_TrajPlanValServQu_nu; /*!< @description
	*	TJATVG_PARAMETER \n\n
	*	\@asap_name: P_TJATVG_TrajPlanValServQu_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TJATVG_TrajPlanValSrvQuSALC_nu; /*!< @description
	*	Trajectory planning service qualifier for semi-automatic lane change \n
	*	(enables lane cross check) \n\n
	*	\@asap_name: P_TJATVG_TrajPlanValSrvQuSALC_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_TriggerReplan_bool; /*!< @description
	*	Switch to trigger replanning \n\n
	*	\@asap_name: P_TJATVG_TriggerReplan_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_UseLtcyCompCMB_bool; /*!< @description
	*	Switch to enable use of latency compensation during CMB mode \n\n
	*	\@asap_name: P_TJATVG_UseLtcyCompCMB_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_UseLtcyCompLC_bool; /*!< @description
	*	Switch to enable use of latency compensation during LC mode \n\n
	*	\@asap_name: P_TJATVG_UseLtcyCompLC_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_UseLtcyCompOF_bool; /*!< @description
	*	Switch to enable use of latency compensation during OF mode \n\n
	*	\@asap_name: P_TJATVG_UseLtcyCompOF_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJATVG_UseLtcyCompSALC_bool; /*!< @description
	*	Switch to enable use of latency compensation during SALC mode \n\n
	*	\@asap_name: P_TJATVG_UseLtcyCompSALC_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJA_Available_bool; /*!< @description
	*	Indicates TRUE if TJA is a coded function of the system \n\n
	*	\@asap_name: P_TJA_Available_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TJA_ManFunctionSwitch_bool; /*!< @description
	*	TJA manual function switch (if HMI not working): 1: TJA switch off, 0: TJA switched off \n\n
	*	\@asap_name: P_TJA_ManFunctionSwitch_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_ActivebyRampout_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_ActivebyRampout_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_AllowReplanOBF_nu; /*!< @description
	*	allow replanning by OBF mode switch \n\n
	*	\@asap_name: P_TPLCEN_AllowReplanOBF_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_AllowSpePlanStrategy_nu; /*!< @description
	*	Allow the special plan strategy for TJA function (by pass with the checks) \n\n
	*	\@asap_name: P_TPLCEN_AllowSpePlanStrategy_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_CycEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_CycEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_EnableFcnChngDetect_nu; /*!< @description
	*	Enable the function change detection by jump detection for triggering the reinitialization \n\n
	*	\@asap_name: P_TPLCEN_EnableFcnChngDetect_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_EnableJumpDetectOBF_nu; /*!< @description
	*	Enable jump detection for replan by OBF \n\n
	*	\@asap_name: P_TPLCEN_EnableJumpDetectOBF_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_EnableJumpDetectOFRQ_nu; /*!< @description
	*	Switch to enable the jump detection for reinitialization by OBF request \n\n
	*	\@asap_name: P_TPLCEN_EnableJumpDetectOFRQ_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_LCOReplanEnable_nu; /*!< @description
	*	Enable replan triggered by LCO \n\n
	*	\@asap_name: P_TPLCEN_LCOReplanEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_ReIniWrtDMCReq_nu; /*!< @description
	*	Reinitialization w.r.t DMC status (req finisched) \n\n
	*	\@asap_name: P_TPLCEN_ReIniWrtDMCReq_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_TPLCEN_ReplanLargeErrorMode_nu; /*!< @description
	*	Bitmask to choose the trigger condition for reinitialization the trajectory by large deviation. \n
	*	Bit0: Edge rising by large PosY and Heading Deviations and small driver torque \n
	*	Bit1: Edge rising by large PosY and Heading Deviations \n
	*	Bit2: Large PosY and Heading Deviations and large driver torque \n
	*	Bit3: Edge rising by Large PosY and Heading Deviations and large driver torque \n\n
	*	\@asap_name: P_TPLCEN_ReplanLargeErrorMode_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_ReplanbyTJA2X_nu; /*!< @description
	*	Enable reinitialization when the controlling function changes from TJA to other functions. \n\n
	*	\@asap_name: P_TPLCEN_ReplanbyTJA2X_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_TrajPlanEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLCEN_TrajPlanEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_UseJumpDetectOBFTrig_nu; /*!< @description
	*	Enable jump detection by function change to TJA OBF mode \n\n
	*	\@asap_name: P_TPLCEN_UseJumpDetectOBFTrig_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLCEN_UseJumpDetection_nu; /*!< @description
	*	Switch to activate the jump detection, by off function change detection will be active. \n\n
	*	\@asap_name: P_TPLCEN_UseJumpDetection_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFBT_CrvPredictionEnbl_nu; /*!< @description
	*	enable prediction on the target corridor curvature \n\n
	*	\@asap_name: P_TPLFBT_CrvPredictionEnbl_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFBT_HoldAllBits_nu; /*!< @description
	*	Switch to determine if all the Qualifier Bits shall be stored during the hold phase \n\n
	*	\@asap_name: P_TPLFBT_HoldAllBits_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFBT_QuStatusHold_nu; /*!< @description
	*	Parameter to disable the holding logic for QuStatus for test purpose. \n\n
	*	\@asap_name: P_TPLFBT_QuStatusHold_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFBT_UseLongQuStatus_nu; /*!< @description
	*	switch between the long and short qu status \n\n
	*	\@asap_name: P_TPLFBT_UseLongQuStatus_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFBT_UseTgtCridrHeading_nu; /*!< @description
	*	switch to decide if take the calculated target corridor heading angle or 0 as the target heading angle \n\n
	*	\@asap_name: P_TPLFBT_UseTgtCridrHeading_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFRT_CalcLeftCridrEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLFRT_CalcLeftCridrEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFRT_CridrSwitchDetection_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLFRT_CridrSwitchDetection_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFRT_UseDMCSumCrv_nu; /*!< @description
	*	switch between the planer curvature and the dmc sum curvature as start curvature \n\n
	*	\@asap_name: P_TPLFRT_UseDMCSumCrv_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLFRT_UseTgtTrajX0_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLFRT_UseTgtTrajX0_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_CCCAllowOverwrite_nu; /*!< @description
	*	Allow to overwrite the corridors when CCC check failed \n\n
	*	\@asap_name: P_TPLLCO_CCCAllowOverwrite_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_CCCEnableInCurve_nu; /*!< @description
	*	enable CCC check in the curve all the time \n\n
	*	\@asap_name: P_TPLLCO_CCCEnableInCurve_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_CCCEnable_nu; /*!< @description
	*	Enable CCC (course consistency check) \n\n
	*	\@asap_name: P_TPLLCO_CCCEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_Perc_0_100_0_1_t	P_TPLLCO_CCCMinCrvQuality_Perc; /*!< @description
	*	Min Crv Quality for reset \n\n
	*	\@asap_name: P_TPLLCO_CCCMinCrvQuality_Perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_Perc_0_100_0_1_t	P_TPLLCO_CCCMinLnQuality_Perc; /*!< @description
	*	Min. Lane Quality for reset \n\n
	*	\@asap_name: P_TPLLCO_CCCMinLnQuality_Perc \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_100_0_1_t	P_TPLLCO_CCCMinQuCycle_nu; /*!< @description
	*	min. cycle of high quality for reset \n\n
	*	\@asap_name: P_TPLLCO_CCCMinQuCycle_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_CalculationbyRampout_nu; /*!< @description
	*	Allow the calculation of the current ego position when the function ramps out \n\n
	*	\@asap_name: P_TPLLCO_CalculationbyRampout_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_CalculationbyRequest_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_CalculationbyRequest_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_1_100_0_1_t	P_TPLLCO_NumIter_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_NumIter_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 100
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_PreviewDistXEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_PreviewDistXEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_ReplanDevEnable_nu; /*!< @description
	*	enable the deviation calculation for replan \n\n
	*	\@asap_name: P_TPLLCO_ReplanDevEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_SupressDoubleTrigRpl_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_SupressDoubleTrigRpl_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_TimeDiffSwitch_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_TimeDiffSwitch_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_UseEgoPredict_nu; /*!< @description
	*	consider ego motion by calculating current disty under OBF mode \n\n
	*	\@asap_name: P_TPLLCO_UseEgoPredict_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_UseOdoReplan_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLLCO_UseOdoReplan_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_UseSensorTStamp_nu; /*!< @description
	*	switch between sensor time stamp and sentoveh time stamp for calculation trigger \n\n
	*	\@asap_name: P_TPLLCO_UseSensorTStamp_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLLCO_VehCrvPT1Enable_nu; /*!< @description
	*	enable low pass filter by using ego vehicle curvature \n\n
	*	\@asap_name: P_TPLLCO_VehCrvPT1Enable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_1_7_0_1_t	P_TPLTJC_NumCircles_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_NumCircles_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 1 \n
	*	\@max: 7
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLTJC_ParamCostFctInternal_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_ParamCostFctInternal_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_TPLTJC_TimeTrajEndEnable_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: P_TPLTJC_TimeTrajEndEnable_nu \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t	P_VDPDRV_DebugWiperStateActive_bool; /*!< @description
	*	Deactivate Wiper State Signal \n\n
	*	\@asap_name: P_VDPDRV_DebugWiperStateActive_bool \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t	P_VDPDRV_NoDaytBrightState_btm; /*!< @description
	*	Define NoDaytime condition with the following states: \n
	*	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN = 0 \n
	*	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY = 1 \n
	*	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1 = 2 \n
	*	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2 = 3 \n
	*	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3 = 4 \n
	*	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT = 5 \n\n
	*	\@asap_name: P_VDPDRV_NoDaytBrightState_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	P_VDPDRV_WiperStageActive_btm; /*!< @description
	*	Activate/Deactivate Conditons which are valid for Wiper Stage.  Bits follow enums of S_LCFRCV_WiperStage_nu \n
	*	(State 0 = Bit 0) \n
	*	255 is deactivation of Stage check \n\n
	*	\@asap_name: P_VDPDRV_WiperStageActive_btm \n
	*	\@type: value \n
	*	\@calibration: online \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t	X_TCTCLM_ControllingFunction_nu[9]; /*!< @description
	*	X-Axis: Controlling Function \n\n
	*	\@asap_name: X_TCTCLM_ControllingFunction_nu \n
	*	\@type: axis \n
	*	\@calibration: online \n
	*	\@first_value: ignore \n
	*	\@monotony: strict_increase \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} LCF_CommonParamType; //!< @description LCF common parameter data structure.

#ifdef __cplusplus
}
#endif

#endif // LCFPRM_TYPE_H_
