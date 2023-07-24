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
//! @file     LCFPRM_data.h
//! @brief    Lateral Control Functions - Parameter (LCFPRM) Data Header.

#ifndef LCFPRM_DATA_H_
#define LCFPRM_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "lcf_dpu_cfg.h"
#include "LCFPRM_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   P A R A M E T E R   D E C L A R A T I O N S
**-----------------------------------------------------*/

#define LCFPRM_ONLINE_START //!< start section for online tunable parameters
#include "lcf_par_memmap.h"

extern LCF_ParamQualifier LCF_CommonParamType LCF_CommonParamData; /*!< @description
*	LCF common parameter data object. \n\n
*	\@asap_name: LCF_CommonParamData \n
*	\@function: LCF
*/

#define LCFPRM_ONLINE_STOP //!< stop section for online tunable parameters
#include "lcf_par_memmap.h"

/*-----------------------------------------------------*
   P A R A M E T E R   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef P_LCF_AlmostZero_nu
#define P_LCF_AlmostZero_nu (0.f) //!< LCF parameter macro.
#define GET_P_LCF_AlmostZero_nu() (P_LCF_AlmostZero_nu) //!< LCF parameter macro getter.
#endif // P_LCF_AlmostZero_nu

#ifndef P_TCTCDC_DelayCycleNum_nu
#define P_TCTCDC_DelayCycleNum_nu (0x00u) //!< LCF parameter macro.
#define GET_P_TCTCDC_DelayCycleNum_nu() (P_TCTCDC_DelayCycleNum_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_DelayCycleNum_nu

#ifndef P_VEH_Length_met
#define P_VEH_Length_met (4.255f) //!< LCF parameter macro.
#define GET_P_VEH_Length_met() (P_VEH_Length_met) //!< LCF parameter macro getter.
#endif // P_VEH_Length_met

#ifndef P_VEH_Wheelbase_met
#define P_VEH_Wheelbase_met (2.8f) //!< LCF parameter macro.
#define GET_P_VEH_Wheelbase_met() (P_VEH_Wheelbase_met) //!< LCF parameter macro getter.
#endif // P_VEH_Wheelbase_met

#ifndef P_VEH_WidthWithMirrors_met
#define P_VEH_WidthWithMirrors_met (0.f) //!< LCF parameter macro.
#define GET_P_VEH_WidthWithMirrors_met() (P_VEH_WidthWithMirrors_met) //!< LCF parameter macro getter.
#endif // P_VEH_WidthWithMirrors_met

#ifndef P_VEH_Width_met
#define P_VEH_Width_met (1.89f) //!< LCF parameter macro.
#define GET_P_VEH_Width_met() (P_VEH_Width_met) //!< LCF parameter macro getter.
#endif // P_VEH_Width_met

#ifndef P_ABPLBP_ABDSineWaveHoldOffT_sec
#define P_ABPLBP_ABDSineWaveHoldOffT_sec (LCF_CommonParamData.P_ABPLBP_ABDSineWaveHoldOffT_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_ABDSineWaveHoldOffT_sec() (P_ABPLBP_ABDSineWaveHoldOffT_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ABDSineWaveHoldOffT_sec

#ifndef P_ABPLBP_CSABDBitmask_btm
#define P_ABPLBP_CSABDBitmask_btm (LCF_CommonParamData.P_ABPLBP_CSABDBitmask_btm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CSABDBitmask_btm() (P_ABPLBP_CSABDBitmask_btm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CSABDBitmask_btm

#ifndef P_ABPLBP_CorridorHoldAfterLost_sec
#define P_ABPLBP_CorridorHoldAfterLost_sec (LCF_CommonParamData.P_ABPLBP_CorridorHoldAfterLost_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_CorridorHoldAfterLost_sec() (P_ABPLBP_CorridorHoldAfterLost_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CorridorHoldAfterLost_sec

#ifndef P_ABPLBP_CrvDiffForBridging_1pm
#define P_ABPLBP_CrvDiffForBridging_1pm (LCF_CommonParamData.P_ABPLBP_CrvDiffForBridging_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvDiffForBridging_1pm() (P_ABPLBP_CrvDiffForBridging_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvDiffForBridging_1pm

#ifndef P_ABPLBP_CrvDiffForPitchProb_1pm
#define P_ABPLBP_CrvDiffForPitchProb_1pm (LCF_CommonParamData.P_ABPLBP_CrvDiffForPitchProb_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvDiffForPitchProb_1pm() (P_ABPLBP_CrvDiffForPitchProb_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvDiffForPitchProb_1pm

#ifndef P_ABPLBP_CrvDiffRatioForPitch_nu
#define P_ABPLBP_CrvDiffRatioForPitch_nu (LCF_CommonParamData.P_ABPLBP_CrvDiffRatioForPitch_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvDiffRatioForPitch_nu() (P_ABPLBP_CrvDiffRatioForPitch_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvDiffRatioForPitch_nu

#ifndef P_ABPLBP_CrvEstimEndPoint_met
#define P_ABPLBP_CrvEstimEndPoint_met (LCF_CommonParamData.P_ABPLBP_CrvEstimEndPoint_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvEstimEndPoint_met() (P_ABPLBP_CrvEstimEndPoint_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvEstimEndPoint_met

#ifndef P_ABPLBP_CrvEstimPT1Curve_sec
#define P_ABPLBP_CrvEstimPT1Curve_sec (LCF_CommonParamData.P_ABPLBP_CrvEstimPT1Curve_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvEstimPT1Curve_sec() (P_ABPLBP_CrvEstimPT1Curve_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvEstimPT1Curve_sec

#ifndef P_ABPLBP_CrvEstimPT1Straight_sec
#define P_ABPLBP_CrvEstimPT1Straight_sec (LCF_CommonParamData.P_ABPLBP_CrvEstimPT1Straight_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvEstimPT1Straight_sec() (P_ABPLBP_CrvEstimPT1Straight_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvEstimPT1Straight_sec

#ifndef P_ABPLBP_CrvEstimStartPoint_met
#define P_ABPLBP_CrvEstimStartPoint_met (LCF_CommonParamData.P_ABPLBP_CrvEstimStartPoint_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvEstimStartPoint_met() (P_ABPLBP_CrvEstimStartPoint_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvEstimStartPoint_met

#ifndef P_ABPLBP_CrvFiltEnd_1pm
#define P_ABPLBP_CrvFiltEnd_1pm (LCF_CommonParamData.P_ABPLBP_CrvFiltEnd_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvFiltEnd_1pm() (P_ABPLBP_CrvFiltEnd_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvFiltEnd_1pm

#ifndef P_ABPLBP_CrvFiltMinCalcDist_met
#define P_ABPLBP_CrvFiltMinCalcDist_met (LCF_CommonParamData.P_ABPLBP_CrvFiltMinCalcDist_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvFiltMinCalcDist_met() (P_ABPLBP_CrvFiltMinCalcDist_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvFiltMinCalcDist_met

#ifndef P_ABPLBP_CrvFiltStart_1pm
#define P_ABPLBP_CrvFiltStart_1pm (LCF_CommonParamData.P_ABPLBP_CrvFiltStart_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvFiltStart_1pm() (P_ABPLBP_CrvFiltStart_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvFiltStart_1pm

#ifndef P_ABPLBP_CrvKFDecQualDeg_1ps
#define P_ABPLBP_CrvKFDecQualDeg_1ps (LCF_CommonParamData.P_ABPLBP_CrvKFDecQualDeg_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFDecQualDeg_1ps() (P_ABPLBP_CrvKFDecQualDeg_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFDecQualDeg_1ps

#ifndef P_ABPLBP_CrvKFDecQualPred_1ps
#define P_ABPLBP_CrvKFDecQualPred_1ps (LCF_CommonParamData.P_ABPLBP_CrvKFDecQualPred_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFDecQualPred_1ps() (P_ABPLBP_CrvKFDecQualPred_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFDecQualPred_1ps

#ifndef P_ABPLBP_CrvKFDefCurve_1pm
#define P_ABPLBP_CrvKFDefCurve_1pm (LCF_CommonParamData.P_ABPLBP_CrvKFDefCurve_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFDefCurve_1pm() (P_ABPLBP_CrvKFDefCurve_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFDefCurve_1pm

#ifndef P_ABPLBP_CrvKFDegradeWeight_nu
#define P_ABPLBP_CrvKFDegradeWeight_nu (LCF_CommonParamData.P_ABPLBP_CrvKFDegradeWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFDegradeWeight_nu() (P_ABPLBP_CrvKFDegradeWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFDegradeWeight_nu

#ifndef P_ABPLBP_CrvKFErrCoeff1_met
#define P_ABPLBP_CrvKFErrCoeff1_met (LCF_CommonParamData.P_ABPLBP_CrvKFErrCoeff1_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFErrCoeff1_met() (P_ABPLBP_CrvKFErrCoeff1_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFErrCoeff1_met

#ifndef P_ABPLBP_CrvKFErrCoeff2_mps
#define P_ABPLBP_CrvKFErrCoeff2_mps (LCF_CommonParamData.P_ABPLBP_CrvKFErrCoeff2_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFErrCoeff2_mps() (P_ABPLBP_CrvKFErrCoeff2_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFErrCoeff2_mps

#ifndef P_ABPLBP_CrvKFIncQual_1ps
#define P_ABPLBP_CrvKFIncQual_1ps (LCF_CommonParamData.P_ABPLBP_CrvKFIncQual_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFIncQual_1ps() (P_ABPLBP_CrvKFIncQual_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFIncQual_1ps

#ifndef P_ABPLBP_CrvKFInitRFactor_nu
#define P_ABPLBP_CrvKFInitRFactor_nu (LCF_CommonParamData.P_ABPLBP_CrvKFInitRFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFInitRFactor_nu() (P_ABPLBP_CrvKFInitRFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFInitRFactor_nu

#ifndef P_ABPLBP_CrvKFMnInitQual_perc
#define P_ABPLBP_CrvKFMnInitQual_perc (LCF_CommonParamData.P_ABPLBP_CrvKFMnInitQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFMnInitQual_perc() (P_ABPLBP_CrvKFMnInitQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFMnInitQual_perc

#ifndef P_ABPLBP_CrvKFMnUpdateQual_perc
#define P_ABPLBP_CrvKFMnUpdateQual_perc (LCF_CommonParamData.P_ABPLBP_CrvKFMnUpdateQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFMnUpdateQual_perc() (P_ABPLBP_CrvKFMnUpdateQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFMnUpdateQual_perc

#ifndef P_ABPLBP_CrvKFQ11FacStr_nu
#define P_ABPLBP_CrvKFQ11FacStr_nu (LCF_CommonParamData.P_ABPLBP_CrvKFQ11FacStr_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFQ11FacStr_nu() (P_ABPLBP_CrvKFQ11FacStr_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFQ11FacStr_nu

#ifndef P_ABPLBP_CrvKFQ11Fac_nu
#define P_ABPLBP_CrvKFQ11Fac_nu (LCF_CommonParamData.P_ABPLBP_CrvKFQ11Fac_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFQ11Fac_nu() (P_ABPLBP_CrvKFQ11Fac_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFQ11Fac_nu

#ifndef P_ABPLBP_CrvKFStdDevCrvRt_1pm2
#define P_ABPLBP_CrvKFStdDevCrvRt_1pm2 (LCF_CommonParamData.P_ABPLBP_CrvKFStdDevCrvRt_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFStdDevCrvRt_1pm2() (P_ABPLBP_CrvKFStdDevCrvRt_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFStdDevCrvRt_1pm2

#ifndef P_ABPLBP_CrvKFStdDevCrv_1pm
#define P_ABPLBP_CrvKFStdDevCrv_1pm (LCF_CommonParamData.P_ABPLBP_CrvKFStdDevCrv_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvKFStdDevCrv_1pm() (P_ABPLBP_CrvKFStdDevCrv_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvKFStdDevCrv_1pm

#ifndef P_ABPLBP_CrvLimStepDtct_1pm
#define P_ABPLBP_CrvLimStepDtct_1pm (LCF_CommonParamData.P_ABPLBP_CrvLimStepDtct_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvLimStepDtct_1pm() (P_ABPLBP_CrvLimStepDtct_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvLimStepDtct_1pm

#ifndef P_ABPLBP_CrvRateLimStepDtct_1pm2
#define P_ABPLBP_CrvRateLimStepDtct_1pm2 (LCF_CommonParamData.P_ABPLBP_CrvRateLimStepDtct_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_CrvRateLimStepDtct_1pm2() (P_ABPLBP_CrvRateLimStepDtct_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CrvRateLimStepDtct_1pm2

#ifndef P_ABPLBP_CurvatureGrad_1pms
#define P_ABPLBP_CurvatureGrad_1pms (LCF_CommonParamData.P_ABPLBP_CurvatureGrad_1pms) //!< LCF parameter macro.
#define GET_P_ABPLBP_CurvatureGrad_1pms() (P_ABPLBP_CurvatureGrad_1pms) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CurvatureGrad_1pms

#ifndef P_ABPLBP_CurvatureRateGrad_1pm2s
#define P_ABPLBP_CurvatureRateGrad_1pm2s (LCF_CommonParamData.P_ABPLBP_CurvatureRateGrad_1pm2s) //!< LCF parameter macro.
#define GET_P_ABPLBP_CurvatureRateGrad_1pm2s() (P_ABPLBP_CurvatureRateGrad_1pm2s) //!< LCF parameter macro getter.
#endif // P_ABPLBP_CurvatureRateGrad_1pm2s

#ifndef P_ABPLBP_DebounceTCrvRtStep_sec
#define P_ABPLBP_DebounceTCrvRtStep_sec (LCF_CommonParamData.P_ABPLBP_DebounceTCrvRtStep_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_DebounceTCrvRtStep_sec() (P_ABPLBP_DebounceTCrvRtStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DebounceTCrvRtStep_sec

#ifndef P_ABPLBP_DebounceTCrvStep_sec
#define P_ABPLBP_DebounceTCrvStep_sec (LCF_CommonParamData.P_ABPLBP_DebounceTCrvStep_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_DebounceTCrvStep_sec() (P_ABPLBP_DebounceTCrvStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DebounceTCrvStep_sec

#ifndef P_ABPLBP_DebounceTDistYStep_sec
#define P_ABPLBP_DebounceTDistYStep_sec (LCF_CommonParamData.P_ABPLBP_DebounceTDistYStep_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_DebounceTDistYStep_sec() (P_ABPLBP_DebounceTDistYStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DebounceTDistYStep_sec

#ifndef P_ABPLBP_DebounceTYawAngStep_sec
#define P_ABPLBP_DebounceTYawAngStep_sec (LCF_CommonParamData.P_ABPLBP_DebounceTYawAngStep_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_DebounceTYawAngStep_sec() (P_ABPLBP_DebounceTYawAngStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DebounceTYawAngStep_sec

#ifndef P_ABPLBP_DefaultLaneWidth_met
#define P_ABPLBP_DefaultLaneWidth_met (LCF_CommonParamData.P_ABPLBP_DefaultLaneWidth_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_DefaultLaneWidth_met() (P_ABPLBP_DefaultLaneWidth_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DefaultLaneWidth_met

#ifndef P_ABPLBP_DistYLimitStepDtctPitch_met
#define P_ABPLBP_DistYLimitStepDtctPitch_met (LCF_CommonParamData.P_ABPLBP_DistYLimitStepDtctPitch_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_DistYLimitStepDtctPitch_met() (P_ABPLBP_DistYLimitStepDtctPitch_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DistYLimitStepDtctPitch_met

#ifndef P_ABPLBP_DistYLimitStepDtct_met
#define P_ABPLBP_DistYLimitStepDtct_met (LCF_CommonParamData.P_ABPLBP_DistYLimitStepDtct_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_DistYLimitStepDtct_met() (P_ABPLBP_DistYLimitStepDtct_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DistYLimitStepDtct_met

#ifndef P_ABPLBP_DurValidDistY_sec
#define P_ABPLBP_DurValidDistY_sec (LCF_CommonParamData.P_ABPLBP_DurValidDistY_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_DurValidDistY_sec() (P_ABPLBP_DurValidDistY_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DurValidDistY_sec

#ifndef P_ABPLBP_DurValidNewCorr_sec
#define P_ABPLBP_DurValidNewCorr_sec (LCF_CommonParamData.P_ABPLBP_DurValidNewCorr_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_DurValidNewCorr_sec() (P_ABPLBP_DurValidNewCorr_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_DurValidNewCorr_sec

#ifndef P_ABPLBP_ExitCrvThresh_1pm
#define P_ABPLBP_ExitCrvThresh_1pm (LCF_CommonParamData.P_ABPLBP_ExitCrvThresh_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_ExitCrvThresh_1pm() (P_ABPLBP_ExitCrvThresh_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ExitCrvThresh_1pm

#ifndef P_ABPLBP_ExitHeadingThresh_rad
#define P_ABPLBP_ExitHeadingThresh_rad (LCF_CommonParamData.P_ABPLBP_ExitHeadingThresh_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_ExitHeadingThresh_rad() (P_ABPLBP_ExitHeadingThresh_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ExitHeadingThresh_rad

#ifndef P_ABPLBP_ExitNCycleTrig_bool
#define P_ABPLBP_ExitNCycleTrig_bool (LCF_CommonParamData.P_ABPLBP_ExitNCycleTrig_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_ExitNCycleTrig_bool() (P_ABPLBP_ExitNCycleTrig_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ExitNCycleTrig_bool

#ifndef P_ABPLBP_FadingFactorDiffCrv_nu
#define P_ABPLBP_FadingFactorDiffCrv_nu (LCF_CommonParamData.P_ABPLBP_FadingFactorDiffCrv_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_FadingFactorDiffCrv_nu() (P_ABPLBP_FadingFactorDiffCrv_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_FadingFactorDiffCrv_nu

#ifndef P_ABPLBP_FadingFactorDiffPit_nu
#define P_ABPLBP_FadingFactorDiffPit_nu (LCF_CommonParamData.P_ABPLBP_FadingFactorDiffPit_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_FadingFactorDiffPit_nu() (P_ABPLBP_FadingFactorDiffPit_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_FadingFactorDiffPit_nu

#ifndef P_ABPLBP_FadingFactorDiff_nu
#define P_ABPLBP_FadingFactorDiff_nu (LCF_CommonParamData.P_ABPLBP_FadingFactorDiff_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_FadingFactorDiff_nu() (P_ABPLBP_FadingFactorDiff_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_FadingFactorDiff_nu

#ifndef P_ABPLBP_FadingFactorOneSideCrv_nu
#define P_ABPLBP_FadingFactorOneSideCrv_nu (LCF_CommonParamData.P_ABPLBP_FadingFactorOneSideCrv_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_FadingFactorOneSideCrv_nu() (P_ABPLBP_FadingFactorOneSideCrv_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_FadingFactorOneSideCrv_nu

#ifndef P_ABPLBP_FadingFactorOneSide_nu
#define P_ABPLBP_FadingFactorOneSide_nu (LCF_CommonParamData.P_ABPLBP_FadingFactorOneSide_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_FadingFactorOneSide_nu() (P_ABPLBP_FadingFactorOneSide_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_FadingFactorOneSide_nu

#ifndef P_ABPLBP_HeadLimStepDtct_rad
#define P_ABPLBP_HeadLimStepDtct_rad (LCF_CommonParamData.P_ABPLBP_HeadLimStepDtct_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_HeadLimStepDtct_rad() (P_ABPLBP_HeadLimStepDtct_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_HeadLimStepDtct_rad

#ifndef P_ABPLBP_InvalLeftLane_bool
#define P_ABPLBP_InvalLeftLane_bool (LCF_CommonParamData.P_ABPLBP_InvalLeftLane_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_InvalLeftLane_bool() (P_ABPLBP_InvalLeftLane_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_InvalLeftLane_bool

#ifndef P_ABPLBP_InvalRightLane_bool
#define P_ABPLBP_InvalRightLane_bool (LCF_CommonParamData.P_ABPLBP_InvalRightLane_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_InvalRightLane_bool() (P_ABPLBP_InvalRightLane_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_InvalRightLane_bool

#ifndef P_ABPLBP_JumpDebounceTimeSIF_sec
#define P_ABPLBP_JumpDebounceTimeSIF_sec (LCF_CommonParamData.P_ABPLBP_JumpDebounceTimeSIF_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_JumpDebounceTimeSIF_sec() (P_ABPLBP_JumpDebounceTimeSIF_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_JumpDebounceTimeSIF_sec

#ifndef P_ABPLBP_LDSlopeHoldOffT_sec
#define P_ABPLBP_LDSlopeHoldOffT_sec (LCF_CommonParamData.P_ABPLBP_LDSlopeHoldOffT_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_LDSlopeHoldOffT_sec() (P_ABPLBP_LDSlopeHoldOffT_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LDSlopeHoldOffT_sec

#ifndef P_ABPLBP_LDVirtCycleTurnOn_nu
#define P_ABPLBP_LDVirtCycleTurnOn_nu (LCF_CommonParamData.P_ABPLBP_LDVirtCycleTurnOn_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LDVirtCycleTurnOn_nu() (P_ABPLBP_LDVirtCycleTurnOn_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LDVirtCycleTurnOn_nu

#ifndef P_ABPLBP_LDVirtDefaultQual_perc
#define P_ABPLBP_LDVirtDefaultQual_perc (LCF_CommonParamData.P_ABPLBP_LDVirtDefaultQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LDVirtDefaultQual_perc() (P_ABPLBP_LDVirtDefaultQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LDVirtDefaultQual_perc

#ifndef P_ABPLBP_LDVirtualDelayCycle_nu
#define P_ABPLBP_LDVirtualDelayCycle_nu (LCF_CommonParamData.P_ABPLBP_LDVirtualDelayCycle_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LDVirtualDelayCycle_nu() (P_ABPLBP_LDVirtualDelayCycle_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LDVirtualDelayCycle_nu

#ifndef P_ABPLBP_LDVirtualTForBrid_sec
#define P_ABPLBP_LDVirtualTForBrid_sec (LCF_CommonParamData.P_ABPLBP_LDVirtualTForBrid_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_LDVirtualTForBrid_sec() (P_ABPLBP_LDVirtualTForBrid_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LDVirtualTForBrid_sec

#ifndef P_ABPLBP_LaneKFDecQualDeg_1ps
#define P_ABPLBP_LaneKFDecQualDeg_1ps (LCF_CommonParamData.P_ABPLBP_LaneKFDecQualDeg_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDecQualDeg_1ps() (P_ABPLBP_LaneKFDecQualDeg_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDecQualDeg_1ps

#ifndef P_ABPLBP_LaneKFDecQualPred_1ps
#define P_ABPLBP_LaneKFDecQualPred_1ps (LCF_CommonParamData.P_ABPLBP_LaneKFDecQualPred_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDecQualPred_1ps() (P_ABPLBP_LaneKFDecQualPred_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDecQualPred_1ps

#ifndef P_ABPLBP_LaneKFDegrUpdateQu_perc
#define P_ABPLBP_LaneKFDegrUpdateQu_perc (LCF_CommonParamData.P_ABPLBP_LaneKFDegrUpdateQu_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDegrUpdateQu_perc() (P_ABPLBP_LaneKFDegrUpdateQu_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDegrUpdateQu_perc

#ifndef P_ABPLBP_LaneKFDegrUpdate_bool
#define P_ABPLBP_LaneKFDegrUpdate_bool (LCF_CommonParamData.P_ABPLBP_LaneKFDegrUpdate_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDegrUpdate_bool() (P_ABPLBP_LaneKFDegrUpdate_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDegrUpdate_bool

#ifndef P_ABPLBP_LaneKFDegradeWeight_nu
#define P_ABPLBP_LaneKFDegradeWeight_nu (LCF_CommonParamData.P_ABPLBP_LaneKFDegradeWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDegradeWeight_nu() (P_ABPLBP_LaneKFDegradeWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDegradeWeight_nu

#ifndef P_ABPLBP_LaneKFDynCrvFactor_nu
#define P_ABPLBP_LaneKFDynCrvFactor_nu (LCF_CommonParamData.P_ABPLBP_LaneKFDynCrvFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDynCrvFactor_nu() (P_ABPLBP_LaneKFDynCrvFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDynCrvFactor_nu

#ifndef P_ABPLBP_LaneKFDynCrvRtFactor_nu
#define P_ABPLBP_LaneKFDynCrvRtFactor_nu (LCF_CommonParamData.P_ABPLBP_LaneKFDynCrvRtFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDynCrvRtFactor_nu() (P_ABPLBP_LaneKFDynCrvRtFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDynCrvRtFactor_nu

#ifndef P_ABPLBP_LaneKFDynDistYFact_nu
#define P_ABPLBP_LaneKFDynDistYFact_nu (LCF_CommonParamData.P_ABPLBP_LaneKFDynDistYFact_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDynDistYFact_nu() (P_ABPLBP_LaneKFDynDistYFact_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDynDistYFact_nu

#ifndef P_ABPLBP_LaneKFDynYawFactor_nu
#define P_ABPLBP_LaneKFDynYawFactor_nu (LCF_CommonParamData.P_ABPLBP_LaneKFDynYawFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFDynYawFactor_nu() (P_ABPLBP_LaneKFDynYawFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFDynYawFactor_nu

#ifndef P_ABPLBP_LaneKFErrCoeff1_met
#define P_ABPLBP_LaneKFErrCoeff1_met (LCF_CommonParamData.P_ABPLBP_LaneKFErrCoeff1_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFErrCoeff1_met() (P_ABPLBP_LaneKFErrCoeff1_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFErrCoeff1_met

#ifndef P_ABPLBP_LaneKFErrCoeff2_mps
#define P_ABPLBP_LaneKFErrCoeff2_mps (LCF_CommonParamData.P_ABPLBP_LaneKFErrCoeff2_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFErrCoeff2_mps() (P_ABPLBP_LaneKFErrCoeff2_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFErrCoeff2_mps

#ifndef P_ABPLBP_LaneKFIncQual_1ps
#define P_ABPLBP_LaneKFIncQual_1ps (LCF_CommonParamData.P_ABPLBP_LaneKFIncQual_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFIncQual_1ps() (P_ABPLBP_LaneKFIncQual_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFIncQual_1ps

#ifndef P_ABPLBP_LaneKFInitRFactor_nu
#define P_ABPLBP_LaneKFInitRFactor_nu (LCF_CommonParamData.P_ABPLBP_LaneKFInitRFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFInitRFactor_nu() (P_ABPLBP_LaneKFInitRFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFInitRFactor_nu

#ifndef P_ABPLBP_LaneKFKGainFac_nu
#define P_ABPLBP_LaneKFKGainFac_nu (LCF_CommonParamData.P_ABPLBP_LaneKFKGainFac_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFKGainFac_nu() (P_ABPLBP_LaneKFKGainFac_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFKGainFac_nu

#ifndef P_ABPLBP_LaneKFMnInitQual_perc
#define P_ABPLBP_LaneKFMnInitQual_perc (LCF_CommonParamData.P_ABPLBP_LaneKFMnInitQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFMnInitQual_perc() (P_ABPLBP_LaneKFMnInitQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFMnInitQual_perc

#ifndef P_ABPLBP_LaneKFMnUpdateQual_perc
#define P_ABPLBP_LaneKFMnUpdateQual_perc (LCF_CommonParamData.P_ABPLBP_LaneKFMnUpdateQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFMnUpdateQual_perc() (P_ABPLBP_LaneKFMnUpdateQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFMnUpdateQual_perc

#ifndef P_ABPLBP_LaneKFQualForBrid_perc
#define P_ABPLBP_LaneKFQualForBrid_perc (LCF_CommonParamData.P_ABPLBP_LaneKFQualForBrid_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFQualForBrid_perc() (P_ABPLBP_LaneKFQualForBrid_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFQualForBrid_perc

#ifndef P_ABPLBP_LaneKFStdDevCrvRt_1pm2
#define P_ABPLBP_LaneKFStdDevCrvRt_1pm2 (LCF_CommonParamData.P_ABPLBP_LaneKFStdDevCrvRt_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFStdDevCrvRt_1pm2() (P_ABPLBP_LaneKFStdDevCrvRt_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFStdDevCrvRt_1pm2

#ifndef P_ABPLBP_LaneKFStdDevCrv_1pm
#define P_ABPLBP_LaneKFStdDevCrv_1pm (LCF_CommonParamData.P_ABPLBP_LaneKFStdDevCrv_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFStdDevCrv_1pm() (P_ABPLBP_LaneKFStdDevCrv_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFStdDevCrv_1pm

#ifndef P_ABPLBP_LaneKFStdDevLatDist_met
#define P_ABPLBP_LaneKFStdDevLatDist_met (LCF_CommonParamData.P_ABPLBP_LaneKFStdDevLatDist_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFStdDevLatDist_met() (P_ABPLBP_LaneKFStdDevLatDist_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFStdDevLatDist_met

#ifndef P_ABPLBP_LaneKFStdDevYawRt_radps
#define P_ABPLBP_LaneKFStdDevYawRt_radps (LCF_CommonParamData.P_ABPLBP_LaneKFStdDevYawRt_radps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFStdDevYawRt_radps() (P_ABPLBP_LaneKFStdDevYawRt_radps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFStdDevYawRt_radps

#ifndef P_ABPLBP_LaneKFStdDevYaw_rad
#define P_ABPLBP_LaneKFStdDevYaw_rad (LCF_CommonParamData.P_ABPLBP_LaneKFStdDevYaw_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFStdDevYaw_rad() (P_ABPLBP_LaneKFStdDevYaw_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFStdDevYaw_rad

#ifndef P_ABPLBP_LaneKFYawRtStdDev_bool
#define P_ABPLBP_LaneKFYawRtStdDev_bool (LCF_CommonParamData.P_ABPLBP_LaneKFYawRtStdDev_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneKFYawRtStdDev_bool() (P_ABPLBP_LaneKFYawRtStdDev_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneKFYawRtStdDev_bool

#ifndef P_ABPLBP_LaneQualCrvLim_1pm
#define P_ABPLBP_LaneQualCrvLim_1pm (LCF_CommonParamData.P_ABPLBP_LaneQualCrvLim_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneQualCrvLim_1pm() (P_ABPLBP_LaneQualCrvLim_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneQualCrvLim_1pm

#ifndef P_ABPLBP_LaneQualityLSP_perc
#define P_ABPLBP_LaneQualityLSP_perc (LCF_CommonParamData.P_ABPLBP_LaneQualityLSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneQualityLSP_perc() (P_ABPLBP_LaneQualityLSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneQualityLSP_perc

#ifndef P_ABPLBP_LaneQualityRSP_perc
#define P_ABPLBP_LaneQualityRSP_perc (LCF_CommonParamData.P_ABPLBP_LaneQualityRSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneQualityRSP_perc() (P_ABPLBP_LaneQualityRSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneQualityRSP_perc

#ifndef P_ABPLBP_LaneWidthDiffCrvFactor_nu
#define P_ABPLBP_LaneWidthDiffCrvFactor_nu (LCF_CommonParamData.P_ABPLBP_LaneWidthDiffCrvFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneWidthDiffCrvFactor_nu() (P_ABPLBP_LaneWidthDiffCrvFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneWidthDiffCrvFactor_nu

#ifndef P_ABPLBP_LaneWidthDiffThresh_met
#define P_ABPLBP_LaneWidthDiffThresh_met (LCF_CommonParamData.P_ABPLBP_LaneWidthDiffThresh_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneWidthDiffThresh_met() (P_ABPLBP_LaneWidthDiffThresh_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneWidthDiffThresh_met

#ifndef P_ABPLBP_LaneWidthGrad_mps
#define P_ABPLBP_LaneWidthGrad_mps (LCF_CommonParamData.P_ABPLBP_LaneWidthGrad_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LaneWidthGrad_mps() (P_ABPLBP_LaneWidthGrad_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LaneWidthGrad_mps

#ifndef P_ABPLBP_LatDistDevCrvFactor_nu
#define P_ABPLBP_LatDistDevCrvFactor_nu (LCF_CommonParamData.P_ABPLBP_LatDistDevCrvFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatDistDevCrvFactor_nu() (P_ABPLBP_LatDistDevCrvFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatDistDevCrvFactor_nu

#ifndef P_ABPLBP_LatDistDevCrvLSP_1pm
#define P_ABPLBP_LatDistDevCrvLSP_1pm (LCF_CommonParamData.P_ABPLBP_LatDistDevCrvLSP_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatDistDevCrvLSP_1pm() (P_ABPLBP_LatDistDevCrvLSP_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatDistDevCrvLSP_1pm

#ifndef P_ABPLBP_LatDistDevCrvRSP_1pm
#define P_ABPLBP_LatDistDevCrvRSP_1pm (LCF_CommonParamData.P_ABPLBP_LatDistDevCrvRSP_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatDistDevCrvRSP_1pm() (P_ABPLBP_LatDistDevCrvRSP_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatDistDevCrvRSP_1pm

#ifndef P_ABPLBP_LatDistDevThreshStr_met
#define P_ABPLBP_LatDistDevThreshStr_met (LCF_CommonParamData.P_ABPLBP_LatDistDevThreshStr_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatDistDevThreshStr_met() (P_ABPLBP_LatDistDevThreshStr_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatDistDevThreshStr_met

#ifndef P_ABPLBP_LatDistDevThresh_met
#define P_ABPLBP_LatDistDevThresh_met (LCF_CommonParamData.P_ABPLBP_LatDistDevThresh_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatDistDevThresh_met() (P_ABPLBP_LatDistDevThresh_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatDistDevThresh_met

#ifndef P_ABPLBP_LatDistGrad_mps
#define P_ABPLBP_LatDistGrad_mps (LCF_CommonParamData.P_ABPLBP_LatDistGrad_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatDistGrad_mps() (P_ABPLBP_LatDistGrad_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatDistGrad_mps

#ifndef P_ABPLBP_LatencyTimeSIF_sec
#define P_ABPLBP_LatencyTimeSIF_sec (LCF_CommonParamData.P_ABPLBP_LatencyTimeSIF_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_LatencyTimeSIF_sec() (P_ABPLBP_LatencyTimeSIF_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LatencyTimeSIF_sec

#ifndef P_ABPLBP_LnQualGrad_percps
#define P_ABPLBP_LnQualGrad_percps (LCF_CommonParamData.P_ABPLBP_LnQualGrad_percps) //!< LCF parameter macro.
#define GET_P_ABPLBP_LnQualGrad_percps() (P_ABPLBP_LnQualGrad_percps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_LnQualGrad_percps

#ifndef P_ABPLBP_MaxCrvRateRange_1pm2
#define P_ABPLBP_MaxCrvRateRange_1pm2 (LCF_CommonParamData.P_ABPLBP_MaxCrvRateRange_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxCrvRateRange_1pm2() (P_ABPLBP_MaxCrvRateRange_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxCrvRateRange_1pm2

#ifndef P_ABPLBP_MaxCurvatureRange_1pm
#define P_ABPLBP_MaxCurvatureRange_1pm (LCF_CommonParamData.P_ABPLBP_MaxCurvatureRange_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxCurvatureRange_1pm() (P_ABPLBP_MaxCurvatureRange_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxCurvatureRange_1pm

#ifndef P_ABPLBP_MaxDistYRange_met
#define P_ABPLBP_MaxDistYRange_met (LCF_CommonParamData.P_ABPLBP_MaxDistYRange_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxDistYRange_met() (P_ABPLBP_MaxDistYRange_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxDistYRange_met

#ifndef P_ABPLBP_MaxHeadingRange_rad
#define P_ABPLBP_MaxHeadingRange_rad (LCF_CommonParamData.P_ABPLBP_MaxHeadingRange_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxHeadingRange_rad() (P_ABPLBP_MaxHeadingRange_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxHeadingRange_rad

#ifndef P_ABPLBP_MaxLaneWidthHyst_met
#define P_ABPLBP_MaxLaneWidthHyst_met (LCF_CommonParamData.P_ABPLBP_MaxLaneWidthHyst_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxLaneWidthHyst_met() (P_ABPLBP_MaxLaneWidthHyst_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxLaneWidthHyst_met

#ifndef P_ABPLBP_MaxLaneWidth_met
#define P_ABPLBP_MaxLaneWidth_met (LCF_CommonParamData.P_ABPLBP_MaxLaneWidth_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxLaneWidth_met() (P_ABPLBP_MaxLaneWidth_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxLaneWidth_met

#ifndef P_ABPLBP_MaxRangeHyst_nu
#define P_ABPLBP_MaxRangeHyst_nu (LCF_CommonParamData.P_ABPLBP_MaxRangeHyst_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxRangeHyst_nu() (P_ABPLBP_MaxRangeHyst_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxRangeHyst_nu

#ifndef P_ABPLBP_MaxValidLengthRange_met
#define P_ABPLBP_MaxValidLengthRange_met (LCF_CommonParamData.P_ABPLBP_MaxValidLengthRange_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MaxValidLengthRange_met() (P_ABPLBP_MaxValidLengthRange_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MaxValidLengthRange_met

#ifndef P_ABPLBP_MinKalmanQuality_perc
#define P_ABPLBP_MinKalmanQuality_perc (LCF_CommonParamData.P_ABPLBP_MinKalmanQuality_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_MinKalmanQuality_perc() (P_ABPLBP_MinKalmanQuality_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MinKalmanQuality_perc

#ifndef P_ABPLBP_MinLaneWidthHyst_met
#define P_ABPLBP_MinLaneWidthHyst_met (LCF_CommonParamData.P_ABPLBP_MinLaneWidthHyst_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MinLaneWidthHyst_met() (P_ABPLBP_MinLaneWidthHyst_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MinLaneWidthHyst_met

#ifndef P_ABPLBP_MinLaneWidth_met
#define P_ABPLBP_MinLaneWidth_met (LCF_CommonParamData.P_ABPLBP_MinLaneWidth_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MinLaneWidth_met() (P_ABPLBP_MinLaneWidth_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MinLaneWidth_met

#ifndef P_ABPLBP_MinUncoupBridTime_sec
#define P_ABPLBP_MinUncoupBridTime_sec (LCF_CommonParamData.P_ABPLBP_MinUncoupBridTime_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_MinUncoupBridTime_sec() (P_ABPLBP_MinUncoupBridTime_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MinUncoupBridTime_sec

#ifndef P_ABPLBP_MinVelForKalmanFilt_mps
#define P_ABPLBP_MinVelForKalmanFilt_mps (LCF_CommonParamData.P_ABPLBP_MinVelForKalmanFilt_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_MinVelForKalmanFilt_mps() (P_ABPLBP_MinVelForKalmanFilt_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MinVelForKalmanFilt_mps

#ifndef P_ABPLBP_MinVelUpDownDtct_mps
#define P_ABPLBP_MinVelUpDownDtct_mps (LCF_CommonParamData.P_ABPLBP_MinVelUpDownDtct_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_MinVelUpDownDtct_mps() (P_ABPLBP_MinVelUpDownDtct_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MinVelUpDownDtct_mps

#ifndef P_ABPLBP_MotCompCrvGrad_1pms
#define P_ABPLBP_MotCompCrvGrad_1pms (LCF_CommonParamData.P_ABPLBP_MotCompCrvGrad_1pms) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompCrvGrad_1pms() (P_ABPLBP_MotCompCrvGrad_1pms) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompCrvGrad_1pms

#ifndef P_ABPLBP_MotCompCrvRtGrad_1pms2
#define P_ABPLBP_MotCompCrvRtGrad_1pms2 (LCF_CommonParamData.P_ABPLBP_MotCompCrvRtGrad_1pms2) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompCrvRtGrad_1pms2() (P_ABPLBP_MotCompCrvRtGrad_1pms2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompCrvRtGrad_1pms2

#ifndef P_ABPLBP_MotCompCrvThresh_1pm
#define P_ABPLBP_MotCompCrvThresh_1pm (LCF_CommonParamData.P_ABPLBP_MotCompCrvThresh_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompCrvThresh_1pm() (P_ABPLBP_MotCompCrvThresh_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompCrvThresh_1pm

#ifndef P_ABPLBP_MotCompDYGradLim_met
#define P_ABPLBP_MotCompDYGradLim_met (LCF_CommonParamData.P_ABPLBP_MotCompDYGradLim_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompDYGradLim_met() (P_ABPLBP_MotCompDYGradLim_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompDYGradLim_met

#ifndef P_ABPLBP_MotCompDYawGradLim_rad
#define P_ABPLBP_MotCompDYawGradLim_rad (LCF_CommonParamData.P_ABPLBP_MotCompDYawGradLim_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompDYawGradLim_rad() (P_ABPLBP_MotCompDYawGradLim_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompDYawGradLim_rad

#ifndef P_ABPLBP_MotCompDeltaQual_perc
#define P_ABPLBP_MotCompDeltaQual_perc (LCF_CommonParamData.P_ABPLBP_MotCompDeltaQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompDeltaQual_perc() (P_ABPLBP_MotCompDeltaQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompDeltaQual_perc

#ifndef P_ABPLBP_MotCompLatDistGrad_mps
#define P_ABPLBP_MotCompLatDistGrad_mps (LCF_CommonParamData.P_ABPLBP_MotCompLatDistGrad_mps) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompLatDistGrad_mps() (P_ABPLBP_MotCompLatDistGrad_mps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompLatDistGrad_mps

#ifndef P_ABPLBP_MotCompMinPrevQual_perc
#define P_ABPLBP_MotCompMinPrevQual_perc (LCF_CommonParamData.P_ABPLBP_MotCompMinPrevQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompMinPrevQual_perc() (P_ABPLBP_MotCompMinPrevQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompMinPrevQual_perc

#ifndef P_ABPLBP_MotCompMinValLenPF_met
#define P_ABPLBP_MotCompMinValLenPF_met (LCF_CommonParamData.P_ABPLBP_MotCompMinValLenPF_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompMinValLenPF_met() (P_ABPLBP_MotCompMinValLenPF_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompMinValLenPF_met

#ifndef P_ABPLBP_MotCompMinValLength_met
#define P_ABPLBP_MotCompMinValLength_met (LCF_CommonParamData.P_ABPLBP_MotCompMinValLength_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompMinValLength_met() (P_ABPLBP_MotCompMinValLength_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompMinValLength_met

#ifndef P_ABPLBP_MotCompPolyMinLen_met
#define P_ABPLBP_MotCompPolyMinLen_met (LCF_CommonParamData.P_ABPLBP_MotCompPolyMinLen_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompPolyMinLen_met() (P_ABPLBP_MotCompPolyMinLen_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompPolyMinLen_met

#ifndef P_ABPLBP_MotCompQualReset_perc
#define P_ABPLBP_MotCompQualReset_perc (LCF_CommonParamData.P_ABPLBP_MotCompQualReset_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompQualReset_perc() (P_ABPLBP_MotCompQualReset_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompQualReset_perc

#ifndef P_ABPLBP_MotCompYawGrad_radps
#define P_ABPLBP_MotCompYawGrad_radps (LCF_CommonParamData.P_ABPLBP_MotCompYawGrad_radps) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotCompYawGrad_radps() (P_ABPLBP_MotCompYawGrad_radps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotCompYawGrad_radps

#ifndef P_ABPLBP_MotionCompDfltQual_perc
#define P_ABPLBP_MotionCompDfltQual_perc (LCF_CommonParamData.P_ABPLBP_MotionCompDfltQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_MotionCompDfltQual_perc() (P_ABPLBP_MotionCompDfltQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MotionCompDfltQual_perc

#ifndef P_ABPLBP_MxBridgDistOneSided_met
#define P_ABPLBP_MxBridgDistOneSided_met (LCF_CommonParamData.P_ABPLBP_MxBridgDistOneSided_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_MxBridgDistOneSided_met() (P_ABPLBP_MxBridgDistOneSided_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MxBridgDistOneSided_met

#ifndef P_ABPLBP_MxBridgTimeOneSided_sec
#define P_ABPLBP_MxBridgTimeOneSided_sec (LCF_CommonParamData.P_ABPLBP_MxBridgTimeOneSided_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_MxBridgTimeOneSided_sec() (P_ABPLBP_MxBridgTimeOneSided_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_MxBridgTimeOneSided_sec

#ifndef P_ABPLBP_OverpassDfltQualT_sec
#define P_ABPLBP_OverpassDfltQualT_sec (LCF_CommonParamData.P_ABPLBP_OverpassDfltQualT_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_OverpassDfltQualT_sec() (P_ABPLBP_OverpassDfltQualT_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_OverpassDfltQualT_sec

#ifndef P_ABPLBP_OverpassDfltQual_perc
#define P_ABPLBP_OverpassDfltQual_perc (LCF_CommonParamData.P_ABPLBP_OverpassDfltQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_OverpassDfltQual_perc() (P_ABPLBP_OverpassDfltQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_OverpassDfltQual_perc

#ifndef P_ABPLBP_PT1LaneWidthTConst_sec
#define P_ABPLBP_PT1LaneWidthTConst_sec (LCF_CommonParamData.P_ABPLBP_PT1LaneWidthTConst_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_PT1LaneWidthTConst_sec() (P_ABPLBP_PT1LaneWidthTConst_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PT1LaneWidthTConst_sec

#ifndef P_ABPLBP_PT1LaneWidthTInit_sec
#define P_ABPLBP_PT1LaneWidthTInit_sec (LCF_CommonParamData.P_ABPLBP_PT1LaneWidthTInit_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_PT1LaneWidthTInit_sec() (P_ABPLBP_PT1LaneWidthTInit_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PT1LaneWidthTInit_sec

#ifndef P_ABPLBP_PT1LaneWidthTLD_1ps
#define P_ABPLBP_PT1LaneWidthTLD_1ps (LCF_CommonParamData.P_ABPLBP_PT1LaneWidthTLD_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_PT1LaneWidthTLD_1ps() (P_ABPLBP_PT1LaneWidthTLD_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PT1LaneWidthTLD_1ps

#ifndef P_ABPLBP_PT1LaneWidthTLU_1ps
#define P_ABPLBP_PT1LaneWidthTLU_1ps (LCF_CommonParamData.P_ABPLBP_PT1LaneWidthTLU_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_PT1LaneWidthTLU_1ps() (P_ABPLBP_PT1LaneWidthTLU_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PT1LaneWidthTLU_1ps

#ifndef P_ABPLBP_PT1TimeConstSIF_sec
#define P_ABPLBP_PT1TimeConstSIF_sec (LCF_CommonParamData.P_ABPLBP_PT1TimeConstSIF_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_PT1TimeConstSIF_sec() (P_ABPLBP_PT1TimeConstSIF_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PT1TimeConstSIF_sec

#ifndef P_ABPLBP_PitchProbDec_perc
#define P_ABPLBP_PitchProbDec_perc (LCF_CommonParamData.P_ABPLBP_PitchProbDec_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_PitchProbDec_perc() (P_ABPLBP_PitchProbDec_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PitchProbDec_perc

#ifndef P_ABPLBP_PitchProbGain_nu
#define P_ABPLBP_PitchProbGain_nu (LCF_CommonParamData.P_ABPLBP_PitchProbGain_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_PitchProbGain_nu() (P_ABPLBP_PitchProbGain_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PitchProbGain_nu

#ifndef P_ABPLBP_PitchProbLSP_perc
#define P_ABPLBP_PitchProbLSP_perc (LCF_CommonParamData.P_ABPLBP_PitchProbLSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_PitchProbLSP_perc() (P_ABPLBP_PitchProbLSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PitchProbLSP_perc

#ifndef P_ABPLBP_PitchProbRSP_perc
#define P_ABPLBP_PitchProbRSP_perc (LCF_CommonParamData.P_ABPLBP_PitchProbRSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_PitchProbRSP_perc() (P_ABPLBP_PitchProbRSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_PitchProbRSP_perc

#ifndef P_ABPLBP_QualCrvPenFactor_nu
#define P_ABPLBP_QualCrvPenFactor_nu (LCF_CommonParamData.P_ABPLBP_QualCrvPenFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCrvPenFactor_nu() (P_ABPLBP_QualCrvPenFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCrvPenFactor_nu

#ifndef P_ABPLBP_QualCrvPenWeight_nu
#define P_ABPLBP_QualCrvPenWeight_nu (LCF_CommonParamData.P_ABPLBP_QualCrvPenWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCrvPenWeight_nu() (P_ABPLBP_QualCrvPenWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCrvPenWeight_nu

#ifndef P_ABPLBP_QualCrvRtPenMax_1pm2
#define P_ABPLBP_QualCrvRtPenMax_1pm2 (LCF_CommonParamData.P_ABPLBP_QualCrvRtPenMax_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCrvRtPenMax_1pm2() (P_ABPLBP_QualCrvRtPenMax_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCrvRtPenMax_1pm2

#ifndef P_ABPLBP_QualCrvRtPenMin_1pm2
#define P_ABPLBP_QualCrvRtPenMin_1pm2 (LCF_CommonParamData.P_ABPLBP_QualCrvRtPenMin_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCrvRtPenMin_1pm2() (P_ABPLBP_QualCrvRtPenMin_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCrvRtPenMin_1pm2

#ifndef P_ABPLBP_QualCrvRtPenWeight_nu
#define P_ABPLBP_QualCrvRtPenWeight_nu (LCF_CommonParamData.P_ABPLBP_QualCrvRtPenWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCrvRtPenWeight_nu() (P_ABPLBP_QualCrvRtPenWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCrvRtPenWeight_nu

#ifndef P_ABPLBP_QualCurvaturePenMax_1pm
#define P_ABPLBP_QualCurvaturePenMax_1pm (LCF_CommonParamData.P_ABPLBP_QualCurvaturePenMax_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCurvaturePenMax_1pm() (P_ABPLBP_QualCurvaturePenMax_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCurvaturePenMax_1pm

#ifndef P_ABPLBP_QualCurvaturePenMin_1pm
#define P_ABPLBP_QualCurvaturePenMin_1pm (LCF_CommonParamData.P_ABPLBP_QualCurvaturePenMin_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualCurvaturePenMin_1pm() (P_ABPLBP_QualCurvaturePenMin_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualCurvaturePenMin_1pm

#ifndef P_ABPLBP_QualFadingFac_nu
#define P_ABPLBP_QualFadingFac_nu (LCF_CommonParamData.P_ABPLBP_QualFadingFac_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualFadingFac_nu() (P_ABPLBP_QualFadingFac_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualFadingFac_nu

#ifndef P_ABPLBP_QualGradLimLD_perc
#define P_ABPLBP_QualGradLimLD_perc (LCF_CommonParamData.P_ABPLBP_QualGradLimLD_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualGradLimLD_perc() (P_ABPLBP_QualGradLimLD_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualGradLimLD_perc

#ifndef P_ABPLBP_QualGradLimLU_perc
#define P_ABPLBP_QualGradLimLU_perc (LCF_CommonParamData.P_ABPLBP_QualGradLimLU_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualGradLimLU_perc() (P_ABPLBP_QualGradLimLU_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualGradLimLU_perc

#ifndef P_ABPLBP_QualHeadingPenMax_rad
#define P_ABPLBP_QualHeadingPenMax_rad (LCF_CommonParamData.P_ABPLBP_QualHeadingPenMax_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualHeadingPenMax_rad() (P_ABPLBP_QualHeadingPenMax_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualHeadingPenMax_rad

#ifndef P_ABPLBP_QualHeadingPenMin_rad
#define P_ABPLBP_QualHeadingPenMin_rad (LCF_CommonParamData.P_ABPLBP_QualHeadingPenMin_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualHeadingPenMin_rad() (P_ABPLBP_QualHeadingPenMin_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualHeadingPenMin_rad

#ifndef P_ABPLBP_QualLatDistPenMax_met
#define P_ABPLBP_QualLatDistPenMax_met (LCF_CommonParamData.P_ABPLBP_QualLatDistPenMax_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualLatDistPenMax_met() (P_ABPLBP_QualLatDistPenMax_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualLatDistPenMax_met

#ifndef P_ABPLBP_QualLatDistPenMin_met
#define P_ABPLBP_QualLatDistPenMin_met (LCF_CommonParamData.P_ABPLBP_QualLatDistPenMin_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualLatDistPenMin_met() (P_ABPLBP_QualLatDistPenMin_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualLatDistPenMin_met

#ifndef P_ABPLBP_QualLatDistPenWeight_nu
#define P_ABPLBP_QualLatDistPenWeight_nu (LCF_CommonParamData.P_ABPLBP_QualLatDistPenWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualLatDistPenWeight_nu() (P_ABPLBP_QualLatDistPenWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualLatDistPenWeight_nu

#ifndef P_ABPLBP_QualPenFactorPitch_nu
#define P_ABPLBP_QualPenFactorPitch_nu (LCF_CommonParamData.P_ABPLBP_QualPenFactorPitch_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualPenFactorPitch_nu() (P_ABPLBP_QualPenFactorPitch_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualPenFactorPitch_nu

#ifndef P_ABPLBP_QualPenFactor_nu
#define P_ABPLBP_QualPenFactor_nu (LCF_CommonParamData.P_ABPLBP_QualPenFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualPenFactor_nu() (P_ABPLBP_QualPenFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualPenFactor_nu

#ifndef P_ABPLBP_QualPenGradLimLD_nu
#define P_ABPLBP_QualPenGradLimLD_nu (LCF_CommonParamData.P_ABPLBP_QualPenGradLimLD_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualPenGradLimLD_nu() (P_ABPLBP_QualPenGradLimLD_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualPenGradLimLD_nu

#ifndef P_ABPLBP_QualPenGradLimLU_nu
#define P_ABPLBP_QualPenGradLimLU_nu (LCF_CommonParamData.P_ABPLBP_QualPenGradLimLU_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualPenGradLimLU_nu() (P_ABPLBP_QualPenGradLimLU_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualPenGradLimLU_nu

#ifndef P_ABPLBP_QualPenHoldFactor_nu
#define P_ABPLBP_QualPenHoldFactor_nu (LCF_CommonParamData.P_ABPLBP_QualPenHoldFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualPenHoldFactor_nu() (P_ABPLBP_QualPenHoldFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualPenHoldFactor_nu

#ifndef P_ABPLBP_QualValidLength_met
#define P_ABPLBP_QualValidLength_met (LCF_CommonParamData.P_ABPLBP_QualValidLength_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualValidLength_met() (P_ABPLBP_QualValidLength_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualValidLength_met

#ifndef P_ABPLBP_QualYawPenWeight_nu
#define P_ABPLBP_QualYawPenWeight_nu (LCF_CommonParamData.P_ABPLBP_QualYawPenWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_QualYawPenWeight_nu() (P_ABPLBP_QualYawPenWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_QualYawPenWeight_nu

#ifndef P_ABPLBP_SIFQualityLSP_perc
#define P_ABPLBP_SIFQualityLSP_perc (LCF_CommonParamData.P_ABPLBP_SIFQualityLSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_SIFQualityLSP_perc() (P_ABPLBP_SIFQualityLSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_SIFQualityLSP_perc

#ifndef P_ABPLBP_SIFQualityRSP_perc
#define P_ABPLBP_SIFQualityRSP_perc (LCF_CommonParamData.P_ABPLBP_SIFQualityRSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_SIFQualityRSP_perc() (P_ABPLBP_SIFQualityRSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_SIFQualityRSP_perc

#ifndef P_ABPLBP_StrDtctCrvDiffDef_perc
#define P_ABPLBP_StrDtctCrvDiffDef_perc (LCF_CommonParamData.P_ABPLBP_StrDtctCrvDiffDef_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctCrvDiffDef_perc() (P_ABPLBP_StrDtctCrvDiffDef_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctCrvDiffDef_perc

#ifndef P_ABPLBP_StrDtctCrvLSP_1pm
#define P_ABPLBP_StrDtctCrvLSP_1pm (LCF_CommonParamData.P_ABPLBP_StrDtctCrvLSP_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctCrvLSP_1pm() (P_ABPLBP_StrDtctCrvLSP_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctCrvLSP_1pm

#ifndef P_ABPLBP_StrDtctCrvMax_1pm
#define P_ABPLBP_StrDtctCrvMax_1pm (LCF_CommonParamData.P_ABPLBP_StrDtctCrvMax_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctCrvMax_1pm() (P_ABPLBP_StrDtctCrvMax_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctCrvMax_1pm

#ifndef P_ABPLBP_StrDtctCrvRSP_1pm
#define P_ABPLBP_StrDtctCrvRSP_1pm (LCF_CommonParamData.P_ABPLBP_StrDtctCrvRSP_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctCrvRSP_1pm() (P_ABPLBP_StrDtctCrvRSP_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctCrvRSP_1pm

#ifndef P_ABPLBP_StrDtctLengthRatio_nu
#define P_ABPLBP_StrDtctLengthRatio_nu (LCF_CommonParamData.P_ABPLBP_StrDtctLengthRatio_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctLengthRatio_nu() (P_ABPLBP_StrDtctLengthRatio_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctLengthRatio_nu

#ifndef P_ABPLBP_StrDtctMinQual_perc
#define P_ABPLBP_StrDtctMinQual_perc (LCF_CommonParamData.P_ABPLBP_StrDtctMinQual_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctMinQual_perc() (P_ABPLBP_StrDtctMinQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctMinQual_perc

#ifndef P_ABPLBP_StrDtctPreview_sec
#define P_ABPLBP_StrDtctPreview_sec (LCF_CommonParamData.P_ABPLBP_StrDtctPreview_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_StrDtctPreview_sec() (P_ABPLBP_StrDtctPreview_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StrDtctPreview_sec

#ifndef P_ABPLBP_StraightDiffThresh_met
#define P_ABPLBP_StraightDiffThresh_met (LCF_CommonParamData.P_ABPLBP_StraightDiffThresh_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_StraightDiffThresh_met() (P_ABPLBP_StraightDiffThresh_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StraightDiffThresh_met

#ifndef P_ABPLBP_StraightScaleFct_nu
#define P_ABPLBP_StraightScaleFct_nu (LCF_CommonParamData.P_ABPLBP_StraightScaleFct_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_StraightScaleFct_nu() (P_ABPLBP_StraightScaleFct_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_StraightScaleFct_nu

#ifndef P_ABPLBP_TolRangeDistY_met
#define P_ABPLBP_TolRangeDistY_met (LCF_CommonParamData.P_ABPLBP_TolRangeDistY_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_TolRangeDistY_met() (P_ABPLBP_TolRangeDistY_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_TolRangeDistY_met

#ifndef P_ABPLBP_TolRangeNewCorr_met
#define P_ABPLBP_TolRangeNewCorr_met (LCF_CommonParamData.P_ABPLBP_TolRangeNewCorr_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_TolRangeNewCorr_met() (P_ABPLBP_TolRangeNewCorr_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_TolRangeNewCorr_met

#ifndef P_ABPLBP_TriggerDistDevThres_met
#define P_ABPLBP_TriggerDistDevThres_met (LCF_CommonParamData.P_ABPLBP_TriggerDistDevThres_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_TriggerDistDevThres_met() (P_ABPLBP_TriggerDistDevThres_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_TriggerDistDevThres_met

#ifndef P_ABPLBP_UncoupDevReset_met
#define P_ABPLBP_UncoupDevReset_met (LCF_CommonParamData.P_ABPLBP_UncoupDevReset_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupDevReset_met() (P_ABPLBP_UncoupDevReset_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupDevReset_met

#ifndef P_ABPLBP_UncoupLnBridCrvLSP_1pm
#define P_ABPLBP_UncoupLnBridCrvLSP_1pm (LCF_CommonParamData.P_ABPLBP_UncoupLnBridCrvLSP_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnBridCrvLSP_1pm() (P_ABPLBP_UncoupLnBridCrvLSP_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnBridCrvLSP_1pm

#ifndef P_ABPLBP_UncoupLnBridCrvRSP_1pm
#define P_ABPLBP_UncoupLnBridCrvRSP_1pm (LCF_CommonParamData.P_ABPLBP_UncoupLnBridCrvRSP_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnBridCrvRSP_1pm() (P_ABPLBP_UncoupLnBridCrvRSP_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnBridCrvRSP_1pm

#ifndef P_ABPLBP_UncoupLnGradLimLD_1ps
#define P_ABPLBP_UncoupLnGradLimLD_1ps (LCF_CommonParamData.P_ABPLBP_UncoupLnGradLimLD_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnGradLimLD_1ps() (P_ABPLBP_UncoupLnGradLimLD_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnGradLimLD_1ps

#ifndef P_ABPLBP_UncoupLnGradLimLU_1ps
#define P_ABPLBP_UncoupLnGradLimLU_1ps (LCF_CommonParamData.P_ABPLBP_UncoupLnGradLimLU_1ps) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnGradLimLU_1ps() (P_ABPLBP_UncoupLnGradLimLU_1ps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnGradLimLU_1ps

#ifndef P_ABPLBP_UncoupLnQualLSP_perc
#define P_ABPLBP_UncoupLnQualLSP_perc (LCF_CommonParamData.P_ABPLBP_UncoupLnQualLSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnQualLSP_perc() (P_ABPLBP_UncoupLnQualLSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnQualLSP_perc

#ifndef P_ABPLBP_UncoupLnQualRSP_perc
#define P_ABPLBP_UncoupLnQualRSP_perc (LCF_CommonParamData.P_ABPLBP_UncoupLnQualRSP_perc) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnQualRSP_perc() (P_ABPLBP_UncoupLnQualRSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnQualRSP_perc

#ifndef P_ABPLBP_UncoupLnStepCRtMax_1pm2
#define P_ABPLBP_UncoupLnStepCRtMax_1pm2 (LCF_CommonParamData.P_ABPLBP_UncoupLnStepCRtMax_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepCRtMax_1pm2() (P_ABPLBP_UncoupLnStepCRtMax_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepCRtMax_1pm2

#ifndef P_ABPLBP_UncoupLnStepCRtMin_1pm2
#define P_ABPLBP_UncoupLnStepCRtMin_1pm2 (LCF_CommonParamData.P_ABPLBP_UncoupLnStepCRtMin_1pm2) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepCRtMin_1pm2() (P_ABPLBP_UncoupLnStepCRtMin_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepCRtMin_1pm2

#ifndef P_ABPLBP_UncoupLnStepCrvFactor_nu
#define P_ABPLBP_UncoupLnStepCrvFactor_nu (LCF_CommonParamData.P_ABPLBP_UncoupLnStepCrvFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepCrvFactor_nu() (P_ABPLBP_UncoupLnStepCrvFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepCrvFactor_nu

#ifndef P_ABPLBP_UncoupLnStepCrvMax_1pm
#define P_ABPLBP_UncoupLnStepCrvMax_1pm (LCF_CommonParamData.P_ABPLBP_UncoupLnStepCrvMax_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepCrvMax_1pm() (P_ABPLBP_UncoupLnStepCrvMax_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepCrvMax_1pm

#ifndef P_ABPLBP_UncoupLnStepCrvMin_1pm
#define P_ABPLBP_UncoupLnStepCrvMin_1pm (LCF_CommonParamData.P_ABPLBP_UncoupLnStepCrvMin_1pm) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepCrvMin_1pm() (P_ABPLBP_UncoupLnStepCrvMin_1pm) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepCrvMin_1pm

#ifndef P_ABPLBP_UncoupLnStepMaxVal_nu
#define P_ABPLBP_UncoupLnStepMaxVal_nu (LCF_CommonParamData.P_ABPLBP_UncoupLnStepMaxVal_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepMaxVal_nu() (P_ABPLBP_UncoupLnStepMaxVal_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepMaxVal_nu

#ifndef P_ABPLBP_UncoupLnStepPosYMax_met
#define P_ABPLBP_UncoupLnStepPosYMax_met (LCF_CommonParamData.P_ABPLBP_UncoupLnStepPosYMax_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepPosYMax_met() (P_ABPLBP_UncoupLnStepPosYMax_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepPosYMax_met

#ifndef P_ABPLBP_UncoupLnStepPosYMin_met
#define P_ABPLBP_UncoupLnStepPosYMin_met (LCF_CommonParamData.P_ABPLBP_UncoupLnStepPosYMin_met) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepPosYMin_met() (P_ABPLBP_UncoupLnStepPosYMin_met) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepPosYMin_met

#ifndef P_ABPLBP_UncoupLnStepYawMax_rad
#define P_ABPLBP_UncoupLnStepYawMax_rad (LCF_CommonParamData.P_ABPLBP_UncoupLnStepYawMax_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepYawMax_rad() (P_ABPLBP_UncoupLnStepYawMax_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepYawMax_rad

#ifndef P_ABPLBP_UncoupLnStepYawMin_rad
#define P_ABPLBP_UncoupLnStepYawMin_rad (LCF_CommonParamData.P_ABPLBP_UncoupLnStepYawMin_rad) //!< LCF parameter macro.
#define GET_P_ABPLBP_UncoupLnStepYawMin_rad() (P_ABPLBP_UncoupLnStepYawMin_rad) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UncoupLnStepYawMin_rad

#ifndef P_ABPLBP_UpDownDeactivatSIF_bool
#define P_ABPLBP_UpDownDeactivatSIF_bool (LCF_CommonParamData.P_ABPLBP_UpDownDeactivatSIF_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UpDownDeactivatSIF_bool() (P_ABPLBP_UpDownDeactivatSIF_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UpDownDeactivatSIF_bool

#ifndef P_ABPLBP_UpDownHillLSP_nu
#define P_ABPLBP_UpDownHillLSP_nu (LCF_CommonParamData.P_ABPLBP_UpDownHillLSP_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_UpDownHillLSP_nu() (P_ABPLBP_UpDownHillLSP_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UpDownHillLSP_nu

#ifndef P_ABPLBP_UpDownHillPT1TConst_sec
#define P_ABPLBP_UpDownHillPT1TConst_sec (LCF_CommonParamData.P_ABPLBP_UpDownHillPT1TConst_sec) //!< LCF parameter macro.
#define GET_P_ABPLBP_UpDownHillPT1TConst_sec() (P_ABPLBP_UpDownHillPT1TConst_sec) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UpDownHillPT1TConst_sec

#ifndef P_ABPLBP_UpDownHillRSP_nu
#define P_ABPLBP_UpDownHillRSP_nu (LCF_CommonParamData.P_ABPLBP_UpDownHillRSP_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_UpDownHillRSP_nu() (P_ABPLBP_UpDownHillRSP_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UpDownHillRSP_nu

#ifndef P_ABPLBP_UpDownHillShutOffLSP_nu
#define P_ABPLBP_UpDownHillShutOffLSP_nu (LCF_CommonParamData.P_ABPLBP_UpDownHillShutOffLSP_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_UpDownHillShutOffLSP_nu() (P_ABPLBP_UpDownHillShutOffLSP_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UpDownHillShutOffLSP_nu

#ifndef P_ABPLBP_UpDownHillShutOffRSP_nu
#define P_ABPLBP_UpDownHillShutOffRSP_nu (LCF_CommonParamData.P_ABPLBP_UpDownHillShutOffRSP_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_UpDownHillShutOffRSP_nu() (P_ABPLBP_UpDownHillShutOffRSP_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UpDownHillShutOffRSP_nu

#ifndef P_ABPLBP_UseABDOverpassFlag_bool
#define P_ABPLBP_UseABDOverpassFlag_bool (LCF_CommonParamData.P_ABPLBP_UseABDOverpassFlag_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseABDOverpassFlag_bool() (P_ABPLBP_UseABDOverpassFlag_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseABDOverpassFlag_bool

#ifndef P_ABPLBP_UseABDSineWave_bool
#define P_ABPLBP_UseABDSineWave_bool (LCF_CommonParamData.P_ABPLBP_UseABDSineWave_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseABDSineWave_bool() (P_ABPLBP_UseABDSineWave_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseABDSineWave_bool

#ifndef P_ABPLBP_UseABDSlope_bool
#define P_ABPLBP_UseABDSlope_bool (LCF_CommonParamData.P_ABPLBP_UseABDSlope_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseABDSlope_bool() (P_ABPLBP_UseABDSlope_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseABDSlope_bool

#ifndef P_ABPLBP_UseCBWeatherCond_bool
#define P_ABPLBP_UseCBWeatherCond_bool (LCF_CommonParamData.P_ABPLBP_UseCBWeatherCond_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseCBWeatherCond_bool() (P_ABPLBP_UseCBWeatherCond_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseCBWeatherCond_bool

#ifndef P_ABPLBP_UseCrvEstRecal_bool
#define P_ABPLBP_UseCrvEstRecal_bool (LCF_CommonParamData.P_ABPLBP_UseCrvEstRecal_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseCrvEstRecal_bool() (P_ABPLBP_UseCrvEstRecal_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseCrvEstRecal_bool

#ifndef P_ABPLBP_UseCrvEstSat_bool
#define P_ABPLBP_UseCrvEstSat_bool (LCF_CommonParamData.P_ABPLBP_UseCrvEstSat_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseCrvEstSat_bool() (P_ABPLBP_UseCrvEstSat_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseCrvEstSat_bool

#ifndef P_ABPLBP_UseCrvEstimation_bool
#define P_ABPLBP_UseCrvEstimation_bool (LCF_CommonParamData.P_ABPLBP_UseCrvEstimation_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseCrvEstimation_bool() (P_ABPLBP_UseCrvEstimation_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseCrvEstimation_bool

#ifndef P_ABPLBP_UseCrvKalman_bool
#define P_ABPLBP_UseCrvKalman_bool (LCF_CommonParamData.P_ABPLBP_UseCrvKalman_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseCrvKalman_bool() (P_ABPLBP_UseCrvKalman_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseCrvKalman_bool

#ifndef P_ABPLBP_UseGradientLimiter_bool
#define P_ABPLBP_UseGradientLimiter_bool (LCF_CommonParamData.P_ABPLBP_UseGradientLimiter_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseGradientLimiter_bool() (P_ABPLBP_UseGradientLimiter_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseGradientLimiter_bool

#ifndef P_ABPLBP_UseLDAlgoCompState_bool
#define P_ABPLBP_UseLDAlgoCompState_bool (LCF_CommonParamData.P_ABPLBP_UseLDAlgoCompState_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseLDAlgoCompState_bool() (P_ABPLBP_UseLDAlgoCompState_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseLDAlgoCompState_bool

#ifndef P_ABPLBP_UseLaneDynWeight_bool
#define P_ABPLBP_UseLaneDynWeight_bool (LCF_CommonParamData.P_ABPLBP_UseLaneDynWeight_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseLaneDynWeight_bool() (P_ABPLBP_UseLaneDynWeight_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseLaneDynWeight_bool

#ifndef P_ABPLBP_UseLaneWidthGrad_bool
#define P_ABPLBP_UseLaneWidthGrad_bool (LCF_CommonParamData.P_ABPLBP_UseLaneWidthGrad_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseLaneWidthGrad_bool() (P_ABPLBP_UseLaneWidthGrad_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseLaneWidthGrad_bool

#ifndef P_ABPLBP_UseLatencyCompSIF_bool
#define P_ABPLBP_UseLatencyCompSIF_bool (LCF_CommonParamData.P_ABPLBP_UseLatencyCompSIF_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseLatencyCompSIF_bool() (P_ABPLBP_UseLatencyCompSIF_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseLatencyCompSIF_bool

#ifndef P_ABPLBP_UseMaxValidLength_bool
#define P_ABPLBP_UseMaxValidLength_bool (LCF_CommonParamData.P_ABPLBP_UseMaxValidLength_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseMaxValidLength_bool() (P_ABPLBP_UseMaxValidLength_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseMaxValidLength_bool

#ifndef P_ABPLBP_UseMotionComp_bool
#define P_ABPLBP_UseMotionComp_bool (LCF_CommonParamData.P_ABPLBP_UseMotionComp_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseMotionComp_bool() (P_ABPLBP_UseMotionComp_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseMotionComp_bool

#ifndef P_ABPLBP_UsePT1FilterSIF_bool
#define P_ABPLBP_UsePT1FilterSIF_bool (LCF_CommonParamData.P_ABPLBP_UsePT1FilterSIF_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UsePT1FilterSIF_bool() (P_ABPLBP_UsePT1FilterSIF_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UsePT1FilterSIF_bool

#ifndef P_ABPLBP_UsePitchingDtct_bool
#define P_ABPLBP_UsePitchingDtct_bool (LCF_CommonParamData.P_ABPLBP_UsePitchingDtct_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UsePitchingDtct_bool() (P_ABPLBP_UsePitchingDtct_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UsePitchingDtct_bool

#ifndef P_ABPLBP_UseStraightEstim_bool
#define P_ABPLBP_UseStraightEstim_bool (LCF_CommonParamData.P_ABPLBP_UseStraightEstim_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseStraightEstim_bool() (P_ABPLBP_UseStraightEstim_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseStraightEstim_bool

#ifndef P_ABPLBP_UseSuppressBridged_bool
#define P_ABPLBP_UseSuppressBridged_bool (LCF_CommonParamData.P_ABPLBP_UseSuppressBridged_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseSuppressBridged_bool() (P_ABPLBP_UseSuppressBridged_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseSuppressBridged_bool

#ifndef P_ABPLBP_UseUncoupABDQual_bool
#define P_ABPLBP_UseUncoupABDQual_bool (LCF_CommonParamData.P_ABPLBP_UseUncoupABDQual_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseUncoupABDQual_bool() (P_ABPLBP_UseUncoupABDQual_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseUncoupABDQual_bool

#ifndef P_ABPLBP_UseUncoupLanesSIF_bool
#define P_ABPLBP_UseUncoupLanesSIF_bool (LCF_CommonParamData.P_ABPLBP_UseUncoupLanesSIF_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseUncoupLanesSIF_bool() (P_ABPLBP_UseUncoupLanesSIF_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseUncoupLanesSIF_bool

#ifndef P_ABPLBP_UseUncoupStepDtct_bool
#define P_ABPLBP_UseUncoupStepDtct_bool (LCF_CommonParamData.P_ABPLBP_UseUncoupStepDtct_bool) //!< LCF parameter macro.
#define GET_P_ABPLBP_UseUncoupStepDtct_bool() (P_ABPLBP_UseUncoupStepDtct_bool) //!< LCF parameter macro getter.
#endif // P_ABPLBP_UseUncoupStepDtct_bool

#ifndef P_ABPLBP_ValidCBWeatherCond_btf
#define P_ABPLBP_ValidCBWeatherCond_btf (LCF_CommonParamData.P_ABPLBP_ValidCBWeatherCond_btf) //!< LCF parameter macro.
#define GET_P_ABPLBP_ValidCBWeatherCond_btf() (P_ABPLBP_ValidCBWeatherCond_btf) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ValidCBWeatherCond_btf

#ifndef P_ABPLBP_ValidColorBitmask_nu
#define P_ABPLBP_ValidColorBitmask_nu (LCF_CommonParamData.P_ABPLBP_ValidColorBitmask_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_ValidColorBitmask_nu() (P_ABPLBP_ValidColorBitmask_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ValidColorBitmask_nu

#ifndef P_ABPLBP_ValidLnTypeBitmask_nu
#define P_ABPLBP_ValidLnTypeBitmask_nu (LCF_CommonParamData.P_ABPLBP_ValidLnTypeBitmask_nu) //!< LCF parameter macro.
#define GET_P_ABPLBP_ValidLnTypeBitmask_nu() (P_ABPLBP_ValidLnTypeBitmask_nu) //!< LCF parameter macro getter.
#endif // P_ABPLBP_ValidLnTypeBitmask_nu

#ifndef P_ABPLBP_YawAngleGrad_radps
#define P_ABPLBP_YawAngleGrad_radps (LCF_CommonParamData.P_ABPLBP_YawAngleGrad_radps) //!< LCF parameter macro.
#define GET_P_ABPLBP_YawAngleGrad_radps() (P_ABPLBP_YawAngleGrad_radps) //!< LCF parameter macro getter.
#endif // P_ABPLBP_YawAngleGrad_radps

#ifndef P_ABPREP_CrvLimStepDtct_1pm
#define P_ABPREP_CrvLimStepDtct_1pm (LCF_CommonParamData.P_ABPREP_CrvLimStepDtct_1pm) //!< LCF parameter macro.
#define GET_P_ABPREP_CrvLimStepDtct_1pm() (P_ABPREP_CrvLimStepDtct_1pm) //!< LCF parameter macro getter.
#endif // P_ABPREP_CrvLimStepDtct_1pm

#ifndef P_ABPREP_CrvRateLimStepDtct_1pm2
#define P_ABPREP_CrvRateLimStepDtct_1pm2 (LCF_CommonParamData.P_ABPREP_CrvRateLimStepDtct_1pm2) //!< LCF parameter macro.
#define GET_P_ABPREP_CrvRateLimStepDtct_1pm2() (P_ABPREP_CrvRateLimStepDtct_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPREP_CrvRateLimStepDtct_1pm2

#ifndef P_ABPREP_DefaultRoadWidth_met
#define P_ABPREP_DefaultRoadWidth_met (LCF_CommonParamData.P_ABPREP_DefaultRoadWidth_met) //!< LCF parameter macro.
#define GET_P_ABPREP_DefaultRoadWidth_met() (P_ABPREP_DefaultRoadWidth_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_DefaultRoadWidth_met

#ifndef P_ABPREP_DistYLimitStepDtct_met
#define P_ABPREP_DistYLimitStepDtct_met (LCF_CommonParamData.P_ABPREP_DistYLimitStepDtct_met) //!< LCF parameter macro.
#define GET_P_ABPREP_DistYLimitStepDtct_met() (P_ABPREP_DistYLimitStepDtct_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_DistYLimitStepDtct_met

#ifndef P_ABPREP_DurValidCrvRateStep_sec
#define P_ABPREP_DurValidCrvRateStep_sec (LCF_CommonParamData.P_ABPREP_DurValidCrvRateStep_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_DurValidCrvRateStep_sec() (P_ABPREP_DurValidCrvRateStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_DurValidCrvRateStep_sec

#ifndef P_ABPREP_DurValidCrvStep_sec
#define P_ABPREP_DurValidCrvStep_sec (LCF_CommonParamData.P_ABPREP_DurValidCrvStep_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_DurValidCrvStep_sec() (P_ABPREP_DurValidCrvStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_DurValidCrvStep_sec

#ifndef P_ABPREP_DurValidDistYStep_sec
#define P_ABPREP_DurValidDistYStep_sec (LCF_CommonParamData.P_ABPREP_DurValidDistYStep_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_DurValidDistYStep_sec() (P_ABPREP_DurValidDistYStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_DurValidDistYStep_sec

#ifndef P_ABPREP_DurValidHeadingStep_sec
#define P_ABPREP_DurValidHeadingStep_sec (LCF_CommonParamData.P_ABPREP_DurValidHeadingStep_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_DurValidHeadingStep_sec() (P_ABPREP_DurValidHeadingStep_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_DurValidHeadingStep_sec

#ifndef P_ABPREP_HeadLimStepDtct_rad
#define P_ABPREP_HeadLimStepDtct_rad (LCF_CommonParamData.P_ABPREP_HeadLimStepDtct_rad) //!< LCF parameter macro.
#define GET_P_ABPREP_HeadLimStepDtct_rad() (P_ABPREP_HeadLimStepDtct_rad) //!< LCF parameter macro getter.
#endif // P_ABPREP_HeadLimStepDtct_rad

#ifndef P_ABPREP_KalmanMinQuality_perc
#define P_ABPREP_KalmanMinQuality_perc (LCF_CommonParamData.P_ABPREP_KalmanMinQuality_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_KalmanMinQuality_perc() (P_ABPREP_KalmanMinQuality_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_KalmanMinQuality_perc

#ifndef P_ABPREP_Lane2ReDistThresh_met
#define P_ABPREP_Lane2ReDistThresh_met (LCF_CommonParamData.P_ABPREP_Lane2ReDistThresh_met) //!< LCF parameter macro.
#define GET_P_ABPREP_Lane2ReDistThresh_met() (P_ABPREP_Lane2ReDistThresh_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_Lane2ReDistThresh_met

#ifndef P_ABPREP_LaneKFDecQualDeg_1ps
#define P_ABPREP_LaneKFDecQualDeg_1ps (LCF_CommonParamData.P_ABPREP_LaneKFDecQualDeg_1ps) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDecQualDeg_1ps() (P_ABPREP_LaneKFDecQualDeg_1ps) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDecQualDeg_1ps

#ifndef P_ABPREP_LaneKFDecQualPred_1ps
#define P_ABPREP_LaneKFDecQualPred_1ps (LCF_CommonParamData.P_ABPREP_LaneKFDecQualPred_1ps) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDecQualPred_1ps() (P_ABPREP_LaneKFDecQualPred_1ps) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDecQualPred_1ps

#ifndef P_ABPREP_LaneKFDegrUpdateQu_perc
#define P_ABPREP_LaneKFDegrUpdateQu_perc (LCF_CommonParamData.P_ABPREP_LaneKFDegrUpdateQu_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDegrUpdateQu_perc() (P_ABPREP_LaneKFDegrUpdateQu_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDegrUpdateQu_perc

#ifndef P_ABPREP_LaneKFDegrUpdate_bool
#define P_ABPREP_LaneKFDegrUpdate_bool (LCF_CommonParamData.P_ABPREP_LaneKFDegrUpdate_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDegrUpdate_bool() (P_ABPREP_LaneKFDegrUpdate_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDegrUpdate_bool

#ifndef P_ABPREP_LaneKFDegradeWeight_nu
#define P_ABPREP_LaneKFDegradeWeight_nu (LCF_CommonParamData.P_ABPREP_LaneKFDegradeWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDegradeWeight_nu() (P_ABPREP_LaneKFDegradeWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDegradeWeight_nu

#ifndef P_ABPREP_LaneKFDynCrvFactor_nu
#define P_ABPREP_LaneKFDynCrvFactor_nu (LCF_CommonParamData.P_ABPREP_LaneKFDynCrvFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDynCrvFactor_nu() (P_ABPREP_LaneKFDynCrvFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDynCrvFactor_nu

#ifndef P_ABPREP_LaneKFDynCrvRtFactor_nu
#define P_ABPREP_LaneKFDynCrvRtFactor_nu (LCF_CommonParamData.P_ABPREP_LaneKFDynCrvRtFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDynCrvRtFactor_nu() (P_ABPREP_LaneKFDynCrvRtFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDynCrvRtFactor_nu

#ifndef P_ABPREP_LaneKFDynDistYFact_nu
#define P_ABPREP_LaneKFDynDistYFact_nu (LCF_CommonParamData.P_ABPREP_LaneKFDynDistYFact_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDynDistYFact_nu() (P_ABPREP_LaneKFDynDistYFact_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDynDistYFact_nu

#ifndef P_ABPREP_LaneKFDynYawFactor_nu
#define P_ABPREP_LaneKFDynYawFactor_nu (LCF_CommonParamData.P_ABPREP_LaneKFDynYawFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFDynYawFactor_nu() (P_ABPREP_LaneKFDynYawFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFDynYawFactor_nu

#ifndef P_ABPREP_LaneKFErrCoeff1_met
#define P_ABPREP_LaneKFErrCoeff1_met (LCF_CommonParamData.P_ABPREP_LaneKFErrCoeff1_met) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFErrCoeff1_met() (P_ABPREP_LaneKFErrCoeff1_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFErrCoeff1_met

#ifndef P_ABPREP_LaneKFErrCoeff2_mps
#define P_ABPREP_LaneKFErrCoeff2_mps (LCF_CommonParamData.P_ABPREP_LaneKFErrCoeff2_mps) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFErrCoeff2_mps() (P_ABPREP_LaneKFErrCoeff2_mps) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFErrCoeff2_mps

#ifndef P_ABPREP_LaneKFIncQual_1ps
#define P_ABPREP_LaneKFIncQual_1ps (LCF_CommonParamData.P_ABPREP_LaneKFIncQual_1ps) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFIncQual_1ps() (P_ABPREP_LaneKFIncQual_1ps) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFIncQual_1ps

#ifndef P_ABPREP_LaneKFInitRFactor_nu
#define P_ABPREP_LaneKFInitRFactor_nu (LCF_CommonParamData.P_ABPREP_LaneKFInitRFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFInitRFactor_nu() (P_ABPREP_LaneKFInitRFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFInitRFactor_nu

#ifndef P_ABPREP_LaneKFKGainFac_nu
#define P_ABPREP_LaneKFKGainFac_nu (LCF_CommonParamData.P_ABPREP_LaneKFKGainFac_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFKGainFac_nu() (P_ABPREP_LaneKFKGainFac_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFKGainFac_nu

#ifndef P_ABPREP_LaneKFMnInitQual_perc
#define P_ABPREP_LaneKFMnInitQual_perc (LCF_CommonParamData.P_ABPREP_LaneKFMnInitQual_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFMnInitQual_perc() (P_ABPREP_LaneKFMnInitQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFMnInitQual_perc

#ifndef P_ABPREP_LaneKFMnUpdateQual_perc
#define P_ABPREP_LaneKFMnUpdateQual_perc (LCF_CommonParamData.P_ABPREP_LaneKFMnUpdateQual_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFMnUpdateQual_perc() (P_ABPREP_LaneKFMnUpdateQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFMnUpdateQual_perc

#ifndef P_ABPREP_LaneKFStdDevCrvRt_1pm2
#define P_ABPREP_LaneKFStdDevCrvRt_1pm2 (LCF_CommonParamData.P_ABPREP_LaneKFStdDevCrvRt_1pm2) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFStdDevCrvRt_1pm2() (P_ABPREP_LaneKFStdDevCrvRt_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFStdDevCrvRt_1pm2

#ifndef P_ABPREP_LaneKFStdDevCrv_1pm
#define P_ABPREP_LaneKFStdDevCrv_1pm (LCF_CommonParamData.P_ABPREP_LaneKFStdDevCrv_1pm) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFStdDevCrv_1pm() (P_ABPREP_LaneKFStdDevCrv_1pm) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFStdDevCrv_1pm

#ifndef P_ABPREP_LaneKFStdDevLatDist_met
#define P_ABPREP_LaneKFStdDevLatDist_met (LCF_CommonParamData.P_ABPREP_LaneKFStdDevLatDist_met) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFStdDevLatDist_met() (P_ABPREP_LaneKFStdDevLatDist_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFStdDevLatDist_met

#ifndef P_ABPREP_LaneKFStdDevYawRt_radps
#define P_ABPREP_LaneKFStdDevYawRt_radps (LCF_CommonParamData.P_ABPREP_LaneKFStdDevYawRt_radps) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFStdDevYawRt_radps() (P_ABPREP_LaneKFStdDevYawRt_radps) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFStdDevYawRt_radps

#ifndef P_ABPREP_LaneKFStdDevYaw_rad
#define P_ABPREP_LaneKFStdDevYaw_rad (LCF_CommonParamData.P_ABPREP_LaneKFStdDevYaw_rad) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneKFStdDevYaw_rad() (P_ABPREP_LaneKFStdDevYaw_rad) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneKFStdDevYaw_rad

#ifndef P_ABPREP_LaneMaxCrv_1pm
#define P_ABPREP_LaneMaxCrv_1pm (LCF_CommonParamData.P_ABPREP_LaneMaxCrv_1pm) //!< LCF parameter macro.
#define GET_P_ABPREP_LaneMaxCrv_1pm() (P_ABPREP_LaneMaxCrv_1pm) //!< LCF parameter macro getter.
#endif // P_ABPREP_LaneMaxCrv_1pm

#ifndef P_ABPREP_LatVelPT1TimeConst_sec
#define P_ABPREP_LatVelPT1TimeConst_sec (LCF_CommonParamData.P_ABPREP_LatVelPT1TimeConst_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_LatVelPT1TimeConst_sec() (P_ABPREP_LatVelPT1TimeConst_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_LatVelPT1TimeConst_sec

#ifndef P_ABPREP_MaxCrvChngGrad_1psm2
#define P_ABPREP_MaxCrvChngGrad_1psm2 (LCF_CommonParamData.P_ABPREP_MaxCrvChngGrad_1psm2) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxCrvChngGrad_1psm2() (P_ABPREP_MaxCrvChngGrad_1psm2) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxCrvChngGrad_1psm2

#ifndef P_ABPREP_MaxCrvGrad_1pms
#define P_ABPREP_MaxCrvGrad_1pms (LCF_CommonParamData.P_ABPREP_MaxCrvGrad_1pms) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxCrvGrad_1pms() (P_ABPREP_MaxCrvGrad_1pms) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxCrvGrad_1pms

#ifndef P_ABPREP_MaxCrvRateRange_1pm2
#define P_ABPREP_MaxCrvRateRange_1pm2 (LCF_CommonParamData.P_ABPREP_MaxCrvRateRange_1pm2) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxCrvRateRange_1pm2() (P_ABPREP_MaxCrvRateRange_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxCrvRateRange_1pm2

#ifndef P_ABPREP_MaxCurvatureRange_1pm
#define P_ABPREP_MaxCurvatureRange_1pm (LCF_CommonParamData.P_ABPREP_MaxCurvatureRange_1pm) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxCurvatureRange_1pm() (P_ABPREP_MaxCurvatureRange_1pm) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxCurvatureRange_1pm

#ifndef P_ABPREP_MaxDistYGrad_mps
#define P_ABPREP_MaxDistYGrad_mps (LCF_CommonParamData.P_ABPREP_MaxDistYGrad_mps) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxDistYGrad_mps() (P_ABPREP_MaxDistYGrad_mps) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxDistYGrad_mps

#ifndef P_ABPREP_MaxDistYRange_met
#define P_ABPREP_MaxDistYRange_met (LCF_CommonParamData.P_ABPREP_MaxDistYRange_met) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxDistYRange_met() (P_ABPREP_MaxDistYRange_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxDistYRange_met

#ifndef P_ABPREP_MaxHeadingGrad_radps
#define P_ABPREP_MaxHeadingGrad_radps (LCF_CommonParamData.P_ABPREP_MaxHeadingGrad_radps) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxHeadingGrad_radps() (P_ABPREP_MaxHeadingGrad_radps) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxHeadingGrad_radps

#ifndef P_ABPREP_MaxHeadingRange_rad
#define P_ABPREP_MaxHeadingRange_rad (LCF_CommonParamData.P_ABPREP_MaxHeadingRange_rad) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxHeadingRange_rad() (P_ABPREP_MaxHeadingRange_rad) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxHeadingRange_rad

#ifndef P_ABPREP_MaxLaneBridgingTime_sec
#define P_ABPREP_MaxLaneBridgingTime_sec (LCF_CommonParamData.P_ABPREP_MaxLaneBridgingTime_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxLaneBridgingTime_sec() (P_ABPREP_MaxLaneBridgingTime_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxLaneBridgingTime_sec

#ifndef P_ABPREP_MaxLatDistStabilize_met
#define P_ABPREP_MaxLatDistStabilize_met (LCF_CommonParamData.P_ABPREP_MaxLatDistStabilize_met) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxLatDistStabilize_met() (P_ABPREP_MaxLatDistStabilize_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxLatDistStabilize_met

#ifndef P_ABPREP_MaxRangeHyst_nu
#define P_ABPREP_MaxRangeHyst_nu (LCF_CommonParamData.P_ABPREP_MaxRangeHyst_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxRangeHyst_nu() (P_ABPREP_MaxRangeHyst_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxRangeHyst_nu

#ifndef P_ABPREP_MaxValidLengthRange_met
#define P_ABPREP_MaxValidLengthRange_met (LCF_CommonParamData.P_ABPREP_MaxValidLengthRange_met) //!< LCF parameter macro.
#define GET_P_ABPREP_MaxValidLengthRange_met() (P_ABPREP_MaxValidLengthRange_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_MaxValidLengthRange_met

#ifndef P_ABPREP_MinLatDistStabilize_met
#define P_ABPREP_MinLatDistStabilize_met (LCF_CommonParamData.P_ABPREP_MinLatDistStabilize_met) //!< LCF parameter macro.
#define GET_P_ABPREP_MinLatDistStabilize_met() (P_ABPREP_MinLatDistStabilize_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_MinLatDistStabilize_met

#ifndef P_ABPREP_MinRoadEdgeABDQual_perc
#define P_ABPREP_MinRoadEdgeABDQual_perc (LCF_CommonParamData.P_ABPREP_MinRoadEdgeABDQual_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_MinRoadEdgeABDQual_perc() (P_ABPREP_MinRoadEdgeABDQual_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_MinRoadEdgeABDQual_perc

#ifndef P_ABPREP_MinRoadEdgeQualLSP_perc
#define P_ABPREP_MinRoadEdgeQualLSP_perc (LCF_CommonParamData.P_ABPREP_MinRoadEdgeQualLSP_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_MinRoadEdgeQualLSP_perc() (P_ABPREP_MinRoadEdgeQualLSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_MinRoadEdgeQualLSP_perc

#ifndef P_ABPREP_MinRoadEdgeQualRSP_perc
#define P_ABPREP_MinRoadEdgeQualRSP_perc (LCF_CommonParamData.P_ABPREP_MinRoadEdgeQualRSP_perc) //!< LCF parameter macro.
#define GET_P_ABPREP_MinRoadEdgeQualRSP_perc() (P_ABPREP_MinRoadEdgeQualRSP_perc) //!< LCF parameter macro getter.
#endif // P_ABPREP_MinRoadEdgeQualRSP_perc

#ifndef P_ABPREP_MinVelForKalmanFilt_mps
#define P_ABPREP_MinVelForKalmanFilt_mps (LCF_CommonParamData.P_ABPREP_MinVelForKalmanFilt_mps) //!< LCF parameter macro.
#define GET_P_ABPREP_MinVelForKalmanFilt_mps() (P_ABPREP_MinVelForKalmanFilt_mps) //!< LCF parameter macro getter.
#endif // P_ABPREP_MinVelForKalmanFilt_mps

#ifndef P_ABPREP_ReQualCrvMaxTh_1pm
#define P_ABPREP_ReQualCrvMaxTh_1pm (LCF_CommonParamData.P_ABPREP_ReQualCrvMaxTh_1pm) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualCrvMaxTh_1pm() (P_ABPREP_ReQualCrvMaxTh_1pm) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualCrvMaxTh_1pm

#ifndef P_ABPREP_ReQualCrvMinTh_1pm
#define P_ABPREP_ReQualCrvMinTh_1pm (LCF_CommonParamData.P_ABPREP_ReQualCrvMinTh_1pm) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualCrvMinTh_1pm() (P_ABPREP_ReQualCrvMinTh_1pm) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualCrvMinTh_1pm

#ifndef P_ABPREP_ReQualCrvRateMaxTh_1pm2
#define P_ABPREP_ReQualCrvRateMaxTh_1pm2 (LCF_CommonParamData.P_ABPREP_ReQualCrvRateMaxTh_1pm2) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualCrvRateMaxTh_1pm2() (P_ABPREP_ReQualCrvRateMaxTh_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualCrvRateMaxTh_1pm2

#ifndef P_ABPREP_ReQualCrvRateMinTh_1pm2
#define P_ABPREP_ReQualCrvRateMinTh_1pm2 (LCF_CommonParamData.P_ABPREP_ReQualCrvRateMinTh_1pm2) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualCrvRateMinTh_1pm2() (P_ABPREP_ReQualCrvRateMinTh_1pm2) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualCrvRateMinTh_1pm2

#ifndef P_ABPREP_ReQualCrvRateWeight_nu
#define P_ABPREP_ReQualCrvRateWeight_nu (LCF_CommonParamData.P_ABPREP_ReQualCrvRateWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualCrvRateWeight_nu() (P_ABPREP_ReQualCrvRateWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualCrvRateWeight_nu

#ifndef P_ABPREP_ReQualCrvWeight_nu
#define P_ABPREP_ReQualCrvWeight_nu (LCF_CommonParamData.P_ABPREP_ReQualCrvWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualCrvWeight_nu() (P_ABPREP_ReQualCrvWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualCrvWeight_nu

#ifndef P_ABPREP_ReQualDistanceMaxTh_met
#define P_ABPREP_ReQualDistanceMaxTh_met (LCF_CommonParamData.P_ABPREP_ReQualDistanceMaxTh_met) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualDistanceMaxTh_met() (P_ABPREP_ReQualDistanceMaxTh_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualDistanceMaxTh_met

#ifndef P_ABPREP_ReQualDistanceMinTh_met
#define P_ABPREP_ReQualDistanceMinTh_met (LCF_CommonParamData.P_ABPREP_ReQualDistanceMinTh_met) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualDistanceMinTh_met() (P_ABPREP_ReQualDistanceMinTh_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualDistanceMinTh_met

#ifndef P_ABPREP_ReQualDistanceWeight_nu
#define P_ABPREP_ReQualDistanceWeight_nu (LCF_CommonParamData.P_ABPREP_ReQualDistanceWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualDistanceWeight_nu() (P_ABPREP_ReQualDistanceWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualDistanceWeight_nu

#ifndef P_ABPREP_ReQualGradLimLD_nu
#define P_ABPREP_ReQualGradLimLD_nu (LCF_CommonParamData.P_ABPREP_ReQualGradLimLD_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualGradLimLD_nu() (P_ABPREP_ReQualGradLimLD_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualGradLimLD_nu

#ifndef P_ABPREP_ReQualGradLimLU_nu
#define P_ABPREP_ReQualGradLimLU_nu (LCF_CommonParamData.P_ABPREP_ReQualGradLimLU_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualGradLimLU_nu() (P_ABPREP_ReQualGradLimLU_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualGradLimLU_nu

#ifndef P_ABPREP_ReQualHeadingMaxTh_rad
#define P_ABPREP_ReQualHeadingMaxTh_rad (LCF_CommonParamData.P_ABPREP_ReQualHeadingMaxTh_rad) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualHeadingMaxTh_rad() (P_ABPREP_ReQualHeadingMaxTh_rad) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualHeadingMaxTh_rad

#ifndef P_ABPREP_ReQualHeadingMinTh_rad
#define P_ABPREP_ReQualHeadingMinTh_rad (LCF_CommonParamData.P_ABPREP_ReQualHeadingMinTh_rad) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualHeadingMinTh_rad() (P_ABPREP_ReQualHeadingMinTh_rad) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualHeadingMinTh_rad

#ifndef P_ABPREP_ReQualHeadingWeight_nu
#define P_ABPREP_ReQualHeadingWeight_nu (LCF_CommonParamData.P_ABPREP_ReQualHeadingWeight_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualHeadingWeight_nu() (P_ABPREP_ReQualHeadingWeight_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualHeadingWeight_nu

#ifndef P_ABPREP_ReQualPenFactor_nu
#define P_ABPREP_ReQualPenFactor_nu (LCF_CommonParamData.P_ABPREP_ReQualPenFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualPenFactor_nu() (P_ABPREP_ReQualPenFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualPenFactor_nu

#ifndef P_ABPREP_ReQualPenGradLimLD_nu
#define P_ABPREP_ReQualPenGradLimLD_nu (LCF_CommonParamData.P_ABPREP_ReQualPenGradLimLD_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualPenGradLimLD_nu() (P_ABPREP_ReQualPenGradLimLD_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualPenGradLimLD_nu

#ifndef P_ABPREP_ReQualPenGradLimLU_nu
#define P_ABPREP_ReQualPenGradLimLU_nu (LCF_CommonParamData.P_ABPREP_ReQualPenGradLimLU_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualPenGradLimLU_nu() (P_ABPREP_ReQualPenGradLimLU_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualPenGradLimLU_nu

#ifndef P_ABPREP_ReQualPenHoldFactor_nu
#define P_ABPREP_ReQualPenHoldFactor_nu (LCF_CommonParamData.P_ABPREP_ReQualPenHoldFactor_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualPenHoldFactor_nu() (P_ABPREP_ReQualPenHoldFactor_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualPenHoldFactor_nu

#ifndef P_ABPREP_ReQualValidLength_met
#define P_ABPREP_ReQualValidLength_met (LCF_CommonParamData.P_ABPREP_ReQualValidLength_met) //!< LCF parameter macro.
#define GET_P_ABPREP_ReQualValidLength_met() (P_ABPREP_ReQualValidLength_met) //!< LCF parameter macro getter.
#endif // P_ABPREP_ReQualValidLength_met

#ifndef P_ABPREP_SIFJumpDebounceT_sec
#define P_ABPREP_SIFJumpDebounceT_sec (LCF_CommonParamData.P_ABPREP_SIFJumpDebounceT_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_SIFJumpDebounceT_sec() (P_ABPREP_SIFJumpDebounceT_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_SIFJumpDebounceT_sec

#ifndef P_ABPREP_SIFLatencyTime_sec
#define P_ABPREP_SIFLatencyTime_sec (LCF_CommonParamData.P_ABPREP_SIFLatencyTime_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_SIFLatencyTime_sec() (P_ABPREP_SIFLatencyTime_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_SIFLatencyTime_sec

#ifndef P_ABPREP_SIFPT1TimeConst_sec
#define P_ABPREP_SIFPT1TimeConst_sec (LCF_CommonParamData.P_ABPREP_SIFPT1TimeConst_sec) //!< LCF parameter macro.
#define GET_P_ABPREP_SIFPT1TimeConst_sec() (P_ABPREP_SIFPT1TimeConst_sec) //!< LCF parameter macro getter.
#endif // P_ABPREP_SIFPT1TimeConst_sec

#ifndef P_ABPREP_SIFUseKalmanHead_bool
#define P_ABPREP_SIFUseKalmanHead_bool (LCF_CommonParamData.P_ABPREP_SIFUseKalmanHead_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_SIFUseKalmanHead_bool() (P_ABPREP_SIFUseKalmanHead_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_SIFUseKalmanHead_bool

#ifndef P_ABPREP_SIFUseLatVelPT1Flt_bool
#define P_ABPREP_SIFUseLatVelPT1Flt_bool (LCF_CommonParamData.P_ABPREP_SIFUseLatVelPT1Flt_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_SIFUseLatVelPT1Flt_bool() (P_ABPREP_SIFUseLatVelPT1Flt_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_SIFUseLatVelPT1Flt_bool

#ifndef P_ABPREP_SIFUseLatencyComp_bool
#define P_ABPREP_SIFUseLatencyComp_bool (LCF_CommonParamData.P_ABPREP_SIFUseLatencyComp_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_SIFUseLatencyComp_bool() (P_ABPREP_SIFUseLatencyComp_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_SIFUseLatencyComp_bool

#ifndef P_ABPREP_StabilizeWithLanes_bool
#define P_ABPREP_StabilizeWithLanes_bool (LCF_CommonParamData.P_ABPREP_StabilizeWithLanes_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_StabilizeWithLanes_bool() (P_ABPREP_StabilizeWithLanes_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_StabilizeWithLanes_bool

#ifndef P_ABPREP_UseCBWeatherCond_bool
#define P_ABPREP_UseCBWeatherCond_bool (LCF_CommonParamData.P_ABPREP_UseCBWeatherCond_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_UseCBWeatherCond_bool() (P_ABPREP_UseCBWeatherCond_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_UseCBWeatherCond_bool

#ifndef P_ABPREP_UseGradientLimiter_bool
#define P_ABPREP_UseGradientLimiter_bool (LCF_CommonParamData.P_ABPREP_UseGradientLimiter_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_UseGradientLimiter_bool() (P_ABPREP_UseGradientLimiter_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_UseGradientLimiter_bool

#ifndef P_ABPREP_UseLDAlgoCompState_bool
#define P_ABPREP_UseLDAlgoCompState_bool (LCF_CommonParamData.P_ABPREP_UseLDAlgoCompState_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_UseLDAlgoCompState_bool() (P_ABPREP_UseLDAlgoCompState_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_UseLDAlgoCompState_bool

#ifndef P_ABPREP_UseLatVelPT1Filter_bool
#define P_ABPREP_UseLatVelPT1Filter_bool (LCF_CommonParamData.P_ABPREP_UseLatVelPT1Filter_bool) //!< LCF parameter macro.
#define GET_P_ABPREP_UseLatVelPT1Filter_bool() (P_ABPREP_UseLatVelPT1Filter_bool) //!< LCF parameter macro getter.
#endif // P_ABPREP_UseLatVelPT1Filter_bool

#ifndef P_ABPREP_UseRoadEdgeKalman_nu
#define P_ABPREP_UseRoadEdgeKalman_nu (LCF_CommonParamData.P_ABPREP_UseRoadEdgeKalman_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_UseRoadEdgeKalman_nu() (P_ABPREP_UseRoadEdgeKalman_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_UseRoadEdgeKalman_nu

#ifndef P_ABPREP_UseRoadEdgeQuality_nu
#define P_ABPREP_UseRoadEdgeQuality_nu (LCF_CommonParamData.P_ABPREP_UseRoadEdgeQuality_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_UseRoadEdgeQuality_nu() (P_ABPREP_UseRoadEdgeQuality_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_UseRoadEdgeQuality_nu

#ifndef P_ABPREP_ValidCBWeatherCond_btf
#define P_ABPREP_ValidCBWeatherCond_btf (LCF_CommonParamData.P_ABPREP_ValidCBWeatherCond_btf) //!< LCF parameter macro.
#define GET_P_ABPREP_ValidCBWeatherCond_btf() (P_ABPREP_ValidCBWeatherCond_btf) //!< LCF parameter macro getter.
#endif // P_ABPREP_ValidCBWeatherCond_btf

#ifndef P_ABPREP_ValidReTypeBitmask_nu
#define P_ABPREP_ValidReTypeBitmask_nu (LCF_CommonParamData.P_ABPREP_ValidReTypeBitmask_nu) //!< LCF parameter macro.
#define GET_P_ABPREP_ValidReTypeBitmask_nu() (P_ABPREP_ValidReTypeBitmask_nu) //!< LCF parameter macro getter.
#endif // P_ABPREP_ValidReTypeBitmask_nu

#ifndef P_ALCA_DlcTriggerCustom_bool
#define P_ALCA_DlcTriggerCustom_bool (LCF_CommonParamData.P_ALCA_DlcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_ALCA_DlcTriggerCustom_bool() (P_ALCA_DlcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_ALCA_DlcTriggerCustom_bool

#ifndef P_ALCA_Existing_nu
#define P_ALCA_Existing_nu (LCF_CommonParamData.P_ALCA_Existing_nu) //!< LCF parameter macro.
#define GET_P_ALCA_Existing_nu() (P_ALCA_Existing_nu) //!< LCF parameter macro getter.
#endif // P_ALCA_Existing_nu

#ifndef P_DPLSIA_AclXHyst_mps2
#define P_DPLSIA_AclXHyst_mps2 (LCF_CommonParamData.P_DPLSIA_AclXHyst_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclXHyst_mps2() (P_DPLSIA_AclXHyst_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclXHyst_mps2

#ifndef P_DPLSIA_AclXLDWHyst_mps2
#define P_DPLSIA_AclXLDWHyst_mps2 (LCF_CommonParamData.P_DPLSIA_AclXLDWHyst_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclXLDWHyst_mps2() (P_DPLSIA_AclXLDWHyst_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclXLDWHyst_mps2

#ifndef P_DPLSIA_AclXLDWMax_mps2
#define P_DPLSIA_AclXLDWMax_mps2 (LCF_CommonParamData.P_DPLSIA_AclXLDWMax_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclXLDWMax_mps2() (P_DPLSIA_AclXLDWMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclXLDWMax_mps2

#ifndef P_DPLSIA_AclXLDWMin_mps2
#define P_DPLSIA_AclXLDWMin_mps2 (LCF_CommonParamData.P_DPLSIA_AclXLDWMin_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclXLDWMin_mps2() (P_DPLSIA_AclXLDWMin_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclXLDWMin_mps2

#ifndef P_DPLSIA_AclXMax_mps2
#define P_DPLSIA_AclXMax_mps2 (LCF_CommonParamData.P_DPLSIA_AclXMax_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclXMax_mps2() (P_DPLSIA_AclXMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclXMax_mps2

#ifndef P_DPLSIA_AclXMin_mps2
#define P_DPLSIA_AclXMin_mps2 (LCF_CommonParamData.P_DPLSIA_AclXMin_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclXMin_mps2() (P_DPLSIA_AclXMin_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclXMin_mps2

#ifndef P_DPLSIA_AclYHyst_mps2
#define P_DPLSIA_AclYHyst_mps2 (LCF_CommonParamData.P_DPLSIA_AclYHyst_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclYHyst_mps2() (P_DPLSIA_AclYHyst_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclYHyst_mps2

#ifndef P_DPLSIA_AclYLDWHyst_mps2
#define P_DPLSIA_AclYLDWHyst_mps2 (LCF_CommonParamData.P_DPLSIA_AclYLDWHyst_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclYLDWHyst_mps2() (P_DPLSIA_AclYLDWHyst_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclYLDWHyst_mps2

#ifndef P_DPLSIA_AclYLDWMax_mps2
#define P_DPLSIA_AclYLDWMax_mps2 (LCF_CommonParamData.P_DPLSIA_AclYLDWMax_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclYLDWMax_mps2() (P_DPLSIA_AclYLDWMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclYLDWMax_mps2

#ifndef P_DPLSIA_AclYMax_mps2
#define P_DPLSIA_AclYMax_mps2 (LCF_CommonParamData.P_DPLSIA_AclYMax_mps2) //!< LCF parameter macro.
#define GET_P_DPLSIA_AclYMax_mps2() (P_DPLSIA_AclYMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPLSIA_AclYMax_mps2

#ifndef P_DPLSIA_ConstrSiteLDP_bool
#define P_DPLSIA_ConstrSiteLDP_bool (LCF_CommonParamData.P_DPLSIA_ConstrSiteLDP_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_ConstrSiteLDP_bool() (P_DPLSIA_ConstrSiteLDP_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_ConstrSiteLDP_bool

#ifndef P_DPLSIA_ConstrSiteLDW_bool
#define P_DPLSIA_ConstrSiteLDW_bool (LCF_CommonParamData.P_DPLSIA_ConstrSiteLDW_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_ConstrSiteLDW_bool() (P_DPLSIA_ConstrSiteLDW_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_ConstrSiteLDW_bool

#ifndef P_DPLSIA_CurveDetectThreshold_1pm
#define P_DPLSIA_CurveDetectThreshold_1pm (LCF_CommonParamData.P_DPLSIA_CurveDetectThreshold_1pm) //!< LCF parameter macro.
#define GET_P_DPLSIA_CurveDetectThreshold_1pm() (P_DPLSIA_CurveDetectThreshold_1pm) //!< LCF parameter macro getter.
#endif // P_DPLSIA_CurveDetectThreshold_1pm

#ifndef P_DPLSIA_HeadAngThresLDPHyst_rad
#define P_DPLSIA_HeadAngThresLDPHyst_rad (LCF_CommonParamData.P_DPLSIA_HeadAngThresLDPHyst_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_HeadAngThresLDPHyst_rad() (P_DPLSIA_HeadAngThresLDPHyst_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_HeadAngThresLDPHyst_rad

#ifndef P_DPLSIA_HeadAngThresLDPMax_rad
#define P_DPLSIA_HeadAngThresLDPMax_rad (LCF_CommonParamData.P_DPLSIA_HeadAngThresLDPMax_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_HeadAngThresLDPMax_rad() (P_DPLSIA_HeadAngThresLDPMax_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_HeadAngThresLDPMax_rad

#ifndef P_DPLSIA_HeadAngThresLDPMin_rad
#define P_DPLSIA_HeadAngThresLDPMin_rad (LCF_CommonParamData.P_DPLSIA_HeadAngThresLDPMin_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_HeadAngThresLDPMin_rad() (P_DPLSIA_HeadAngThresLDPMin_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_HeadAngThresLDPMin_rad

#ifndef P_DPLSIA_HeadAngThresLDWHyst_rad
#define P_DPLSIA_HeadAngThresLDWHyst_rad (LCF_CommonParamData.P_DPLSIA_HeadAngThresLDWHyst_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_HeadAngThresLDWHyst_rad() (P_DPLSIA_HeadAngThresLDWHyst_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_HeadAngThresLDWHyst_rad

#ifndef P_DPLSIA_HeadAngThresLDWMax_rad
#define P_DPLSIA_HeadAngThresLDWMax_rad (LCF_CommonParamData.P_DPLSIA_HeadAngThresLDWMax_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_HeadAngThresLDWMax_rad() (P_DPLSIA_HeadAngThresLDWMax_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_HeadAngThresLDWMax_rad

#ifndef P_DPLSIA_HeadAngThresLDWMin_rad
#define P_DPLSIA_HeadAngThresLDWMin_rad (LCF_CommonParamData.P_DPLSIA_HeadAngThresLDWMin_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_HeadAngThresLDWMin_rad() (P_DPLSIA_HeadAngThresLDWMin_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_HeadAngThresLDWMin_rad

#ifndef P_DPLSIA_LaneBitmask_btm
#define P_DPLSIA_LaneBitmask_btm (LCF_CommonParamData.P_DPLSIA_LaneBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneBitmask_btm() (P_DPLSIA_LaneBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneBitmask_btm

#ifndef P_DPLSIA_LaneBridgedBitmask_btm
#define P_DPLSIA_LaneBridgedBitmask_btm (LCF_CommonParamData.P_DPLSIA_LaneBridgedBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneBridgedBitmask_btm() (P_DPLSIA_LaneBridgedBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneBridgedBitmask_btm

#ifndef P_DPLSIA_LaneCancelBitmask_btm
#define P_DPLSIA_LaneCancelBitmask_btm (LCF_CommonParamData.P_DPLSIA_LaneCancelBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneCancelBitmask_btm() (P_DPLSIA_LaneCancelBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneCancelBitmask_btm

#ifndef P_DPLSIA_LaneSafetyBitmask_btm
#define P_DPLSIA_LaneSafetyBitmask_btm (LCF_CommonParamData.P_DPLSIA_LaneSafetyBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneSafetyBitmask_btm() (P_DPLSIA_LaneSafetyBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneSafetyBitmask_btm

#ifndef P_DPLSIA_LaneWidthLDPHyst_met
#define P_DPLSIA_LaneWidthLDPHyst_met (LCF_CommonParamData.P_DPLSIA_LaneWidthLDPHyst_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthLDPHyst_met() (P_DPLSIA_LaneWidthLDPHyst_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthLDPHyst_met

#ifndef P_DPLSIA_LaneWidthLDPMax_met
#define P_DPLSIA_LaneWidthLDPMax_met (LCF_CommonParamData.P_DPLSIA_LaneWidthLDPMax_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthLDPMax_met() (P_DPLSIA_LaneWidthLDPMax_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthLDPMax_met

#ifndef P_DPLSIA_LaneWidthLDPMin_met
#define P_DPLSIA_LaneWidthLDPMin_met (LCF_CommonParamData.P_DPLSIA_LaneWidthLDPMin_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthLDPMin_met() (P_DPLSIA_LaneWidthLDPMin_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthLDPMin_met

#ifndef P_DPLSIA_LaneWidthLDWHyst_met
#define P_DPLSIA_LaneWidthLDWHyst_met (LCF_CommonParamData.P_DPLSIA_LaneWidthLDWHyst_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthLDWHyst_met() (P_DPLSIA_LaneWidthLDWHyst_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthLDWHyst_met

#ifndef P_DPLSIA_LaneWidthLDWMax_met
#define P_DPLSIA_LaneWidthLDWMax_met (LCF_CommonParamData.P_DPLSIA_LaneWidthLDWMax_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthLDWMax_met() (P_DPLSIA_LaneWidthLDWMax_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthLDWMax_met

#ifndef P_DPLSIA_LaneWidthLDWMin_met
#define P_DPLSIA_LaneWidthLDWMin_met (LCF_CommonParamData.P_DPLSIA_LaneWidthLDWMin_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthLDWMin_met() (P_DPLSIA_LaneWidthLDWMin_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthLDWMin_met

#ifndef P_DPLSIA_LaneWidthSIFOn_bool
#define P_DPLSIA_LaneWidthSIFOn_bool (LCF_CommonParamData.P_DPLSIA_LaneWidthSIFOn_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthSIFOn_bool() (P_DPLSIA_LaneWidthSIFOn_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthSIFOn_bool

#ifndef P_DPLSIA_LaneWidthWideLnDef_met
#define P_DPLSIA_LaneWidthWideLnDef_met (LCF_CommonParamData.P_DPLSIA_LaneWidthWideLnDef_met) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthWideLnDef_met() (P_DPLSIA_LaneWidthWideLnDef_met) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthWideLnDef_met

#ifndef P_DPLSIA_LaneWidthWideLn_bool
#define P_DPLSIA_LaneWidthWideLn_bool (LCF_CommonParamData.P_DPLSIA_LaneWidthWideLn_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_LaneWidthWideLn_bool() (P_DPLSIA_LaneWidthWideLn_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LaneWidthWideLn_bool

#ifndef P_DPLSIA_LnBndTurnOnTime_sec
#define P_DPLSIA_LnBndTurnOnTime_sec (LCF_CommonParamData.P_DPLSIA_LnBndTurnOnTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSIA_LnBndTurnOnTime_sec() (P_DPLSIA_LnBndTurnOnTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSIA_LnBndTurnOnTime_sec

#ifndef P_DPLSIA_SafetyIfaceLDPOn_bool
#define P_DPLSIA_SafetyIfaceLDPOn_bool (LCF_CommonParamData.P_DPLSIA_SafetyIfaceLDPOn_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_SafetyIfaceLDPOn_bool() (P_DPLSIA_SafetyIfaceLDPOn_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_SafetyIfaceLDPOn_bool

#ifndef P_DPLSIA_SafetyIfaceLDWOn_bool
#define P_DPLSIA_SafetyIfaceLDWOn_bool (LCF_CommonParamData.P_DPLSIA_SafetyIfaceLDWOn_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_SafetyIfaceLDWOn_bool() (P_DPLSIA_SafetyIfaceLDWOn_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_SafetyIfaceLDWOn_bool

#ifndef P_DPLSIA_StrWhlAngSpLDPHys_degps
#define P_DPLSIA_StrWhlAngSpLDPHys_degps (LCF_CommonParamData.P_DPLSIA_StrWhlAngSpLDPHys_degps) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngSpLDPHys_degps() (P_DPLSIA_StrWhlAngSpLDPHys_degps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngSpLDPHys_degps

#ifndef P_DPLSIA_StrWhlAngSpLDPMax_degps
#define P_DPLSIA_StrWhlAngSpLDPMax_degps (LCF_CommonParamData.P_DPLSIA_StrWhlAngSpLDPMax_degps) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngSpLDPMax_degps() (P_DPLSIA_StrWhlAngSpLDPMax_degps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngSpLDPMax_degps

#ifndef P_DPLSIA_StrWhlAngSpLDWHys_degps
#define P_DPLSIA_StrWhlAngSpLDWHys_degps (LCF_CommonParamData.P_DPLSIA_StrWhlAngSpLDWHys_degps) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngSpLDWHys_degps() (P_DPLSIA_StrWhlAngSpLDWHys_degps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngSpLDWHys_degps

#ifndef P_DPLSIA_StrWhlAngSpLDWMax_degps
#define P_DPLSIA_StrWhlAngSpLDWMax_degps (LCF_CommonParamData.P_DPLSIA_StrWhlAngSpLDWMax_degps) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngSpLDWMax_degps() (P_DPLSIA_StrWhlAngSpLDWMax_degps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngSpLDWMax_degps

#ifndef P_DPLSIA_StrWhlAngleLDPHyst_deg
#define P_DPLSIA_StrWhlAngleLDPHyst_deg (LCF_CommonParamData.P_DPLSIA_StrWhlAngleLDPHyst_deg) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngleLDPHyst_deg() (P_DPLSIA_StrWhlAngleLDPHyst_deg) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngleLDPHyst_deg

#ifndef P_DPLSIA_StrWhlAngleLDPMax_deg
#define P_DPLSIA_StrWhlAngleLDPMax_deg (LCF_CommonParamData.P_DPLSIA_StrWhlAngleLDPMax_deg) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngleLDPMax_deg() (P_DPLSIA_StrWhlAngleLDPMax_deg) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngleLDPMax_deg

#ifndef P_DPLSIA_StrWhlAngleLDWHyst_deg
#define P_DPLSIA_StrWhlAngleLDWHyst_deg (LCF_CommonParamData.P_DPLSIA_StrWhlAngleLDWHyst_deg) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngleLDWHyst_deg() (P_DPLSIA_StrWhlAngleLDWHyst_deg) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngleLDWHyst_deg

#ifndef P_DPLSIA_StrWhlAngleLDWMax_deg
#define P_DPLSIA_StrWhlAngleLDWMax_deg (LCF_CommonParamData.P_DPLSIA_StrWhlAngleLDWMax_deg) //!< LCF parameter macro.
#define GET_P_DPLSIA_StrWhlAngleLDWMax_deg() (P_DPLSIA_StrWhlAngleLDWMax_deg) //!< LCF parameter macro getter.
#endif // P_DPLSIA_StrWhlAngleLDWMax_deg

#ifndef P_DPLSIA_TlcHeadAngThres_rad
#define P_DPLSIA_TlcHeadAngThres_rad (LCF_CommonParamData.P_DPLSIA_TlcHeadAngThres_rad) //!< LCF parameter macro.
#define GET_P_DPLSIA_TlcHeadAngThres_rad() (P_DPLSIA_TlcHeadAngThres_rad) //!< LCF parameter macro getter.
#endif // P_DPLSIA_TlcHeadAngThres_rad

#ifndef P_DPLSIA_TurnSignHoldingTime_sec
#define P_DPLSIA_TurnSignHoldingTime_sec (LCF_CommonParamData.P_DPLSIA_TurnSignHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSIA_TurnSignHoldingTime_sec() (P_DPLSIA_TurnSignHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSIA_TurnSignHoldingTime_sec

#ifndef P_DPLSIA_TurnSignReset_bool
#define P_DPLSIA_TurnSignReset_bool (LCF_CommonParamData.P_DPLSIA_TurnSignReset_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_TurnSignReset_bool() (P_DPLSIA_TurnSignReset_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_TurnSignReset_bool

#ifndef P_DPLSIA_UncoupledLWEnable_bool
#define P_DPLSIA_UncoupledLWEnable_bool (LCF_CommonParamData.P_DPLSIA_UncoupledLWEnable_bool) //!< LCF parameter macro.
#define GET_P_DPLSIA_UncoupledLWEnable_bool() (P_DPLSIA_UncoupledLWEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPLSIA_UncoupledLWEnable_bool

#ifndef P_DPLSIA_VelDispLDPHyst_kph
#define P_DPLSIA_VelDispLDPHyst_kph (LCF_CommonParamData.P_DPLSIA_VelDispLDPHyst_kph) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelDispLDPHyst_kph() (P_DPLSIA_VelDispLDPHyst_kph) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelDispLDPHyst_kph

#ifndef P_DPLSIA_VelDispLDPMax_kph
#define P_DPLSIA_VelDispLDPMax_kph (LCF_CommonParamData.P_DPLSIA_VelDispLDPMax_kph) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelDispLDPMax_kph() (P_DPLSIA_VelDispLDPMax_kph) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelDispLDPMax_kph

#ifndef P_DPLSIA_VelDispLDPMin_kph
#define P_DPLSIA_VelDispLDPMin_kph (LCF_CommonParamData.P_DPLSIA_VelDispLDPMin_kph) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelDispLDPMin_kph() (P_DPLSIA_VelDispLDPMin_kph) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelDispLDPMin_kph

#ifndef P_DPLSIA_VelDispLDWHyst_kph
#define P_DPLSIA_VelDispLDWHyst_kph (LCF_CommonParamData.P_DPLSIA_VelDispLDWHyst_kph) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelDispLDWHyst_kph() (P_DPLSIA_VelDispLDWHyst_kph) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelDispLDWHyst_kph

#ifndef P_DPLSIA_VelDispLDWMax_kph
#define P_DPLSIA_VelDispLDWMax_kph (LCF_CommonParamData.P_DPLSIA_VelDispLDWMax_kph) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelDispLDWMax_kph() (P_DPLSIA_VelDispLDWMax_kph) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelDispLDWMax_kph

#ifndef P_DPLSIA_VelDispLDWMin_kph
#define P_DPLSIA_VelDispLDWMin_kph (LCF_CommonParamData.P_DPLSIA_VelDispLDWMin_kph) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelDispLDWMin_kph() (P_DPLSIA_VelDispLDWMin_kph) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelDispLDWMin_kph

#ifndef P_DPLSIA_VelLatThresLDPHyst_mps
#define P_DPLSIA_VelLatThresLDPHyst_mps (LCF_CommonParamData.P_DPLSIA_VelLatThresLDPHyst_mps) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelLatThresLDPHyst_mps() (P_DPLSIA_VelLatThresLDPHyst_mps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelLatThresLDPHyst_mps

#ifndef P_DPLSIA_VelLatThresLDPMax_mps
#define P_DPLSIA_VelLatThresLDPMax_mps (LCF_CommonParamData.P_DPLSIA_VelLatThresLDPMax_mps) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelLatThresLDPMax_mps() (P_DPLSIA_VelLatThresLDPMax_mps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelLatThresLDPMax_mps

#ifndef P_DPLSIA_VelLatThresLDPMin_mps
#define P_DPLSIA_VelLatThresLDPMin_mps (LCF_CommonParamData.P_DPLSIA_VelLatThresLDPMin_mps) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelLatThresLDPMin_mps() (P_DPLSIA_VelLatThresLDPMin_mps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelLatThresLDPMin_mps

#ifndef P_DPLSIA_VelLatThresLDWHyst_mps
#define P_DPLSIA_VelLatThresLDWHyst_mps (LCF_CommonParamData.P_DPLSIA_VelLatThresLDWHyst_mps) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelLatThresLDWHyst_mps() (P_DPLSIA_VelLatThresLDWHyst_mps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelLatThresLDWHyst_mps

#ifndef P_DPLSIA_VelLatThresLDWMax_mps
#define P_DPLSIA_VelLatThresLDWMax_mps (LCF_CommonParamData.P_DPLSIA_VelLatThresLDWMax_mps) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelLatThresLDWMax_mps() (P_DPLSIA_VelLatThresLDWMax_mps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelLatThresLDWMax_mps

#ifndef P_DPLSIA_VelLatThresLDWMin_mps
#define P_DPLSIA_VelLatThresLDWMin_mps (LCF_CommonParamData.P_DPLSIA_VelLatThresLDWMin_mps) //!< LCF parameter macro.
#define GET_P_DPLSIA_VelLatThresLDWMin_mps() (P_DPLSIA_VelLatThresLDWMin_mps) //!< LCF parameter macro getter.
#endif // P_DPLSIA_VelLatThresLDWMin_mps

#ifndef P_DPLSMI_AbortDrvSt_btm
#define P_DPLSMI_AbortDrvSt_btm (LCF_CommonParamData.P_DPLSMI_AbortDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortDrvSt_btm() (P_DPLSMI_AbortDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortDrvSt_btm

#ifndef P_DPLSMI_AbortFctCustom_btm
#define P_DPLSMI_AbortFctCustom_btm (LCF_CommonParamData.P_DPLSMI_AbortFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortFctCustom_btm() (P_DPLSMI_AbortFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortFctCustom_btm

#ifndef P_DPLSMI_AbortFctStCtr_btm
#define P_DPLSMI_AbortFctStCtr_btm (LCF_CommonParamData.P_DPLSMI_AbortFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortFctStCtr_btm() (P_DPLSMI_AbortFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortFctStCtr_btm

#ifndef P_DPLSMI_AbortFctStErr_btm
#define P_DPLSMI_AbortFctStErr_btm (LCF_CommonParamData.P_DPLSMI_AbortFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortFctStErr_btm() (P_DPLSMI_AbortFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortFctStErr_btm

#ifndef P_DPLSMI_AbortFctStNotAv_btm
#define P_DPLSMI_AbortFctStNotAv_btm (LCF_CommonParamData.P_DPLSMI_AbortFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortFctStNotAv_btm() (P_DPLSMI_AbortFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortFctStNotAv_btm

#ifndef P_DPLSMI_AbortSpecific_btm
#define P_DPLSMI_AbortSpecific_btm (LCF_CommonParamData.P_DPLSMI_AbortSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortSpecific_btm() (P_DPLSMI_AbortSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortSpecific_btm

#ifndef P_DPLSMI_AbortVehSt_btm
#define P_DPLSMI_AbortVehSt_btm (LCF_CommonParamData.P_DPLSMI_AbortVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_AbortVehSt_btm() (P_DPLSMI_AbortVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_AbortVehSt_btm

#ifndef P_DPLSMI_BlockingTimeDuration_sec
#define P_DPLSMI_BlockingTimeDuration_sec (LCF_CommonParamData.P_DPLSMI_BlockingTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_BlockingTimeDuration_sec() (P_DPLSMI_BlockingTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_BlockingTimeDuration_sec

#ifndef P_DPLSMI_CancelDrvSt_btm
#define P_DPLSMI_CancelDrvSt_btm (LCF_CommonParamData.P_DPLSMI_CancelDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelDrvSt_btm() (P_DPLSMI_CancelDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelDrvSt_btm

#ifndef P_DPLSMI_CancelFctCustom_btm
#define P_DPLSMI_CancelFctCustom_btm (LCF_CommonParamData.P_DPLSMI_CancelFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelFctCustom_btm() (P_DPLSMI_CancelFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelFctCustom_btm

#ifndef P_DPLSMI_CancelFctStCtr_btm
#define P_DPLSMI_CancelFctStCtr_btm (LCF_CommonParamData.P_DPLSMI_CancelFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelFctStCtr_btm() (P_DPLSMI_CancelFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelFctStCtr_btm

#ifndef P_DPLSMI_CancelFctStErr_btm
#define P_DPLSMI_CancelFctStErr_btm (LCF_CommonParamData.P_DPLSMI_CancelFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelFctStErr_btm() (P_DPLSMI_CancelFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelFctStErr_btm

#ifndef P_DPLSMI_CancelFctStNotAv_btm
#define P_DPLSMI_CancelFctStNotAv_btm (LCF_CommonParamData.P_DPLSMI_CancelFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelFctStNotAv_btm() (P_DPLSMI_CancelFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelFctStNotAv_btm

#ifndef P_DPLSMI_CancelSpecific_btm
#define P_DPLSMI_CancelSpecific_btm (LCF_CommonParamData.P_DPLSMI_CancelSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelSpecific_btm() (P_DPLSMI_CancelSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelSpecific_btm

#ifndef P_DPLSMI_CancelVehSt_btm
#define P_DPLSMI_CancelVehSt_btm (LCF_CommonParamData.P_DPLSMI_CancelVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_CancelVehSt_btm() (P_DPLSMI_CancelVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_CancelVehSt_btm

#ifndef P_DPLSMI_DebugDrvSt_btm
#define P_DPLSMI_DebugDrvSt_btm (LCF_CommonParamData.P_DPLSMI_DebugDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_DebugDrvSt_btm() (P_DPLSMI_DebugDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_DebugDrvSt_btm

#ifndef P_DPLSMI_DebugSpecific_btm
#define P_DPLSMI_DebugSpecific_btm (LCF_CommonParamData.P_DPLSMI_DebugSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_DebugSpecific_btm() (P_DPLSMI_DebugSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_DebugSpecific_btm

#ifndef P_DPLSMI_DegrTimeOut_sec
#define P_DPLSMI_DegrTimeOut_sec (LCF_CommonParamData.P_DPLSMI_DegrTimeOut_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_DegrTimeOut_sec() (P_DPLSMI_DegrTimeOut_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_DegrTimeOut_sec

#ifndef P_DPLSMI_DlcLimitMax_met
#define P_DPLSMI_DlcLimitMax_met (LCF_CommonParamData.P_DPLSMI_DlcLimitMax_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_DlcLimitMax_met() (P_DPLSMI_DlcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_DlcLimitMax_met

#ifndef P_DPLSMI_DlcLimitMin_met
#define P_DPLSMI_DlcLimitMin_met (LCF_CommonParamData.P_DPLSMI_DlcLimitMin_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_DlcLimitMin_met() (P_DPLSMI_DlcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_DlcLimitMin_met

#ifndef P_DPLSMI_ErrorStateLDPEnable_bool
#define P_DPLSMI_ErrorStateLDPEnable_bool (LCF_CommonParamData.P_DPLSMI_ErrorStateLDPEnable_bool) //!< LCF parameter macro.
#define GET_P_DPLSMI_ErrorStateLDPEnable_bool() (P_DPLSMI_ErrorStateLDPEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMI_ErrorStateLDPEnable_bool

#ifndef P_DPLSMI_ErrorStateLDP_bool
#define P_DPLSMI_ErrorStateLDP_bool (LCF_CommonParamData.P_DPLSMI_ErrorStateLDP_bool) //!< LCF parameter macro.
#define GET_P_DPLSMI_ErrorStateLDP_bool() (P_DPLSMI_ErrorStateLDP_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMI_ErrorStateLDP_bool

#ifndef P_DPLSMI_FctCustomBSMLe_btm
#define P_DPLSMI_FctCustomBSMLe_btm (LCF_CommonParamData.P_DPLSMI_FctCustomBSMLe_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FctCustomBSMLe_btm() (P_DPLSMI_FctCustomBSMLe_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FctCustomBSMLe_btm

#ifndef P_DPLSMI_FctCustomBSMRi_btm
#define P_DPLSMI_FctCustomBSMRi_btm (LCF_CommonParamData.P_DPLSMI_FctCustomBSMRi_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FctCustomBSMRi_btm() (P_DPLSMI_FctCustomBSMRi_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FctCustomBSMRi_btm

#ifndef P_DPLSMI_FctCustomCancelLe_btm
#define P_DPLSMI_FctCustomCancelLe_btm (LCF_CommonParamData.P_DPLSMI_FctCustomCancelLe_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FctCustomCancelLe_btm() (P_DPLSMI_FctCustomCancelLe_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FctCustomCancelLe_btm

#ifndef P_DPLSMI_FctCustomCancelRi_btm
#define P_DPLSMI_FctCustomCancelRi_btm (LCF_CommonParamData.P_DPLSMI_FctCustomCancelRi_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FctCustomCancelRi_btm() (P_DPLSMI_FctCustomCancelRi_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FctCustomCancelRi_btm

#ifndef P_DPLSMI_FctCustomTrgLe_btm
#define P_DPLSMI_FctCustomTrgLe_btm (LCF_CommonParamData.P_DPLSMI_FctCustomTrgLe_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FctCustomTrgLe_btm() (P_DPLSMI_FctCustomTrgLe_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FctCustomTrgLe_btm

#ifndef P_DPLSMI_FctCustomTrgRi_btm
#define P_DPLSMI_FctCustomTrgRi_btm (LCF_CommonParamData.P_DPLSMI_FctCustomTrgRi_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FctCustomTrgRi_btm() (P_DPLSMI_FctCustomTrgRi_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FctCustomTrgRi_btm

#ifndef P_DPLSMI_FinishCondEnable_btm
#define P_DPLSMI_FinishCondEnable_btm (LCF_CommonParamData.P_DPLSMI_FinishCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_FinishCondEnable_btm() (P_DPLSMI_FinishCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_FinishCondEnable_btm

#ifndef P_DPLSMI_HazardCancelTol_met
#define P_DPLSMI_HazardCancelTol_met (LCF_CommonParamData.P_DPLSMI_HazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_HazardCancelTol_met() (P_DPLSMI_HazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_HazardCancelTol_met

#ifndef P_DPLSMI_HazardFinishDlc_met
#define P_DPLSMI_HazardFinishDlc_met (LCF_CommonParamData.P_DPLSMI_HazardFinishDlc_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_HazardFinishDlc_met() (P_DPLSMI_HazardFinishDlc_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_HazardFinishDlc_met

#ifndef P_DPLSMI_HazardFinishHeadAng_rad
#define P_DPLSMI_HazardFinishHeadAng_rad (LCF_CommonParamData.P_DPLSMI_HazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPLSMI_HazardFinishHeadAng_rad() (P_DPLSMI_HazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPLSMI_HazardFinishHeadAng_rad

#ifndef P_DPLSMI_HazardFinishVelLat_mps
#define P_DPLSMI_HazardFinishVelLat_mps (LCF_CommonParamData.P_DPLSMI_HazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPLSMI_HazardFinishVelLat_mps() (P_DPLSMI_HazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPLSMI_HazardFinishVelLat_mps

#ifndef P_DPLSMI_LDPSwitchEnable_bool
#define P_DPLSMI_LDPSwitchEnable_bool (LCF_CommonParamData.P_DPLSMI_LDPSwitchEnable_bool) //!< LCF parameter macro.
#define GET_P_DPLSMI_LDPSwitchEnable_bool() (P_DPLSMI_LDPSwitchEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMI_LDPSwitchEnable_bool

#ifndef P_DPLSMI_LDPSwitch_bool
#define P_DPLSMI_LDPSwitch_bool (LCF_CommonParamData.P_DPLSMI_LDPSwitch_bool) //!< LCF parameter macro.
#define GET_P_DPLSMI_LDPSwitch_bool() (P_DPLSMI_LDPSwitch_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMI_LDPSwitch_bool

#ifndef P_DPLSMI_LatDMCClearEnable_bool
#define P_DPLSMI_LatDMCClearEnable_bool (LCF_CommonParamData.P_DPLSMI_LatDMCClearEnable_bool) //!< LCF parameter macro.
#define GET_P_DPLSMI_LatDMCClearEnable_bool() (P_DPLSMI_LatDMCClearEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMI_LatDMCClearEnable_bool

#ifndef P_DPLSMI_NoHazardCancelDlc_met
#define P_DPLSMI_NoHazardCancelDlc_met (LCF_CommonParamData.P_DPLSMI_NoHazardCancelDlc_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_NoHazardCancelDlc_met() (P_DPLSMI_NoHazardCancelDlc_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_NoHazardCancelDlc_met

#ifndef P_DPLSMI_NoHazardCancelTol_met
#define P_DPLSMI_NoHazardCancelTol_met (LCF_CommonParamData.P_DPLSMI_NoHazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_NoHazardCancelTol_met() (P_DPLSMI_NoHazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_NoHazardCancelTol_met

#ifndef P_DPLSMI_NoHazardFinishDlc_met
#define P_DPLSMI_NoHazardFinishDlc_met (LCF_CommonParamData.P_DPLSMI_NoHazardFinishDlc_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_NoHazardFinishDlc_met() (P_DPLSMI_NoHazardFinishDlc_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_NoHazardFinishDlc_met

#ifndef P_DPLSMI_NoHazardFinishHeadAng_rad
#define P_DPLSMI_NoHazardFinishHeadAng_rad (LCF_CommonParamData.P_DPLSMI_NoHazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPLSMI_NoHazardFinishHeadAng_rad() (P_DPLSMI_NoHazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPLSMI_NoHazardFinishHeadAng_rad

#ifndef P_DPLSMI_NoHazardFinishVelLat_mps
#define P_DPLSMI_NoHazardFinishVelLat_mps (LCF_CommonParamData.P_DPLSMI_NoHazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPLSMI_NoHazardFinishVelLat_mps() (P_DPLSMI_NoHazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPLSMI_NoHazardFinishVelLat_mps

#ifndef P_DPLSMI_OnTargetFinishTime_sec
#define P_DPLSMI_OnTargetFinishTime_sec (LCF_CommonParamData.P_DPLSMI_OnTargetFinishTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_OnTargetFinishTime_sec() (P_DPLSMI_OnTargetFinishTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_OnTargetFinishTime_sec

#ifndef P_DPLSMI_QuTrajCtrCancel_btm
#define P_DPLSMI_QuTrajCtrCancel_btm (LCF_CommonParamData.P_DPLSMI_QuTrajCtrCancel_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_QuTrajCtrCancel_btm() (P_DPLSMI_QuTrajCtrCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_QuTrajCtrCancel_btm

#ifndef P_DPLSMI_QuTrajCtrClearance_btm
#define P_DPLSMI_QuTrajCtrClearance_btm (LCF_CommonParamData.P_DPLSMI_QuTrajCtrClearance_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_QuTrajCtrClearance_btm() (P_DPLSMI_QuTrajCtrClearance_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_QuTrajCtrClearance_btm

#ifndef P_DPLSMI_QuTrajPlanCancel_btm
#define P_DPLSMI_QuTrajPlanCancel_btm (LCF_CommonParamData.P_DPLSMI_QuTrajPlanCancel_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_QuTrajPlanCancel_btm() (P_DPLSMI_QuTrajPlanCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_QuTrajPlanCancel_btm

#ifndef P_DPLSMI_QuTrajPlanClearance_btm
#define P_DPLSMI_QuTrajPlanClearance_btm (LCF_CommonParamData.P_DPLSMI_QuTrajPlanClearance_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_QuTrajPlanClearance_btm() (P_DPLSMI_QuTrajPlanClearance_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_QuTrajPlanClearance_btm

#ifndef P_DPLSMI_RequestTimeOut_sec
#define P_DPLSMI_RequestTimeOut_sec (LCF_CommonParamData.P_DPLSMI_RequestTimeOut_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_RequestTimeOut_sec() (P_DPLSMI_RequestTimeOut_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_RequestTimeOut_sec

#ifndef P_DPLSMI_SafeSituationDelay_sec
#define P_DPLSMI_SafeSituationDelay_sec (LCF_CommonParamData.P_DPLSMI_SafeSituationDelay_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_SafeSituationDelay_sec() (P_DPLSMI_SafeSituationDelay_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SafeSituationDelay_sec

#ifndef P_DPLSMI_SafeSituationOffset_met
#define P_DPLSMI_SafeSituationOffset_met (LCF_CommonParamData.P_DPLSMI_SafeSituationOffset_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_SafeSituationOffset_met() (P_DPLSMI_SafeSituationOffset_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SafeSituationOffset_met

#ifndef P_DPLSMI_SafeSituationState_btm
#define P_DPLSMI_SafeSituationState_btm (LCF_CommonParamData.P_DPLSMI_SafeSituationState_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SafeSituationState_btm() (P_DPLSMI_SafeSituationState_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SafeSituationState_btm

#ifndef P_DPLSMI_SideCondCancel_btm
#define P_DPLSMI_SideCondCancel_btm (LCF_CommonParamData.P_DPLSMI_SideCondCancel_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SideCondCancel_btm() (P_DPLSMI_SideCondCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SideCondCancel_btm

#ifndef P_DPLSMI_SideCondDebug_btm
#define P_DPLSMI_SideCondDebug_btm (LCF_CommonParamData.P_DPLSMI_SideCondDebug_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SideCondDebug_btm() (P_DPLSMI_SideCondDebug_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SideCondDebug_btm

#ifndef P_DPLSMI_SideCondEnable_btm
#define P_DPLSMI_SideCondEnable_btm (LCF_CommonParamData.P_DPLSMI_SideCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SideCondEnable_btm() (P_DPLSMI_SideCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SideCondEnable_btm

#ifndef P_DPLSMI_StrgRdyDrvSt_btm
#define P_DPLSMI_StrgRdyDrvSt_btm (LCF_CommonParamData.P_DPLSMI_StrgRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdyDrvSt_btm() (P_DPLSMI_StrgRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdyDrvSt_btm

#ifndef P_DPLSMI_StrgRdyFctCustom_btm
#define P_DPLSMI_StrgRdyFctCustom_btm (LCF_CommonParamData.P_DPLSMI_StrgRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdyFctCustom_btm() (P_DPLSMI_StrgRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdyFctCustom_btm

#ifndef P_DPLSMI_StrgRdyFctStCtr_btm
#define P_DPLSMI_StrgRdyFctStCtr_btm (LCF_CommonParamData.P_DPLSMI_StrgRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdyFctStCtr_btm() (P_DPLSMI_StrgRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdyFctStCtr_btm

#ifndef P_DPLSMI_StrgRdyFctStErr_btm
#define P_DPLSMI_StrgRdyFctStErr_btm (LCF_CommonParamData.P_DPLSMI_StrgRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdyFctStErr_btm() (P_DPLSMI_StrgRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdyFctStErr_btm

#ifndef P_DPLSMI_StrgRdyFctStNotAv_btm
#define P_DPLSMI_StrgRdyFctStNotAv_btm (LCF_CommonParamData.P_DPLSMI_StrgRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdyFctStNotAv_btm() (P_DPLSMI_StrgRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdyFctStNotAv_btm

#ifndef P_DPLSMI_StrgRdySpecific_btm
#define P_DPLSMI_StrgRdySpecific_btm (LCF_CommonParamData.P_DPLSMI_StrgRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdySpecific_btm() (P_DPLSMI_StrgRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdySpecific_btm

#ifndef P_DPLSMI_StrgRdyVehSt_btm
#define P_DPLSMI_StrgRdyVehSt_btm (LCF_CommonParamData.P_DPLSMI_StrgRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_StrgRdyVehSt_btm() (P_DPLSMI_StrgRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_StrgRdyVehSt_btm

#ifndef P_DPLSMI_SuppressDrvSt_btm
#define P_DPLSMI_SuppressDrvSt_btm (LCF_CommonParamData.P_DPLSMI_SuppressDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressDrvSt_btm() (P_DPLSMI_SuppressDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressDrvSt_btm

#ifndef P_DPLSMI_SuppressFctCustom_btm
#define P_DPLSMI_SuppressFctCustom_btm (LCF_CommonParamData.P_DPLSMI_SuppressFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressFctCustom_btm() (P_DPLSMI_SuppressFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressFctCustom_btm

#ifndef P_DPLSMI_SuppressFctStCtr_btm
#define P_DPLSMI_SuppressFctStCtr_btm (LCF_CommonParamData.P_DPLSMI_SuppressFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressFctStCtr_btm() (P_DPLSMI_SuppressFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressFctStCtr_btm

#ifndef P_DPLSMI_SuppressFctStErr_btm
#define P_DPLSMI_SuppressFctStErr_btm (LCF_CommonParamData.P_DPLSMI_SuppressFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressFctStErr_btm() (P_DPLSMI_SuppressFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressFctStErr_btm

#ifndef P_DPLSMI_SuppressFctStNotAv_btm
#define P_DPLSMI_SuppressFctStNotAv_btm (LCF_CommonParamData.P_DPLSMI_SuppressFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressFctStNotAv_btm() (P_DPLSMI_SuppressFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressFctStNotAv_btm

#ifndef P_DPLSMI_SuppressSpecific_btm
#define P_DPLSMI_SuppressSpecific_btm (LCF_CommonParamData.P_DPLSMI_SuppressSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressSpecific_btm() (P_DPLSMI_SuppressSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressSpecific_btm

#ifndef P_DPLSMI_SuppressVehSt_btm
#define P_DPLSMI_SuppressVehSt_btm (LCF_CommonParamData.P_DPLSMI_SuppressVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_SuppressVehSt_btm() (P_DPLSMI_SuppressVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_SuppressVehSt_btm

#ifndef P_DPLSMI_TlcDistanceMin_met
#define P_DPLSMI_TlcDistanceMin_met (LCF_CommonParamData.P_DPLSMI_TlcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_DPLSMI_TlcDistanceMin_met() (P_DPLSMI_TlcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_DPLSMI_TlcDistanceMin_met

#ifndef P_DPLSMI_TlcValidMinTime_sec
#define P_DPLSMI_TlcValidMinTime_sec (LCF_CommonParamData.P_DPLSMI_TlcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_TlcValidMinTime_sec() (P_DPLSMI_TlcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_TlcValidMinTime_sec

#ifndef P_DPLSMI_TriggerCondEnable_btm
#define P_DPLSMI_TriggerCondEnable_btm (LCF_CommonParamData.P_DPLSMI_TriggerCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_TriggerCondEnable_btm() (P_DPLSMI_TriggerCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_TriggerCondEnable_btm

#ifndef P_DPLSMI_TriggerHoldingTime_sec
#define P_DPLSMI_TriggerHoldingTime_sec (LCF_CommonParamData.P_DPLSMI_TriggerHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSMI_TriggerHoldingTime_sec() (P_DPLSMI_TriggerHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMI_TriggerHoldingTime_sec

#ifndef P_DPLSMI_WeakRdyDrvSt_btm
#define P_DPLSMI_WeakRdyDrvSt_btm (LCF_CommonParamData.P_DPLSMI_WeakRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdyDrvSt_btm() (P_DPLSMI_WeakRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdyDrvSt_btm

#ifndef P_DPLSMI_WeakRdyFctCustom_btm
#define P_DPLSMI_WeakRdyFctCustom_btm (LCF_CommonParamData.P_DPLSMI_WeakRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdyFctCustom_btm() (P_DPLSMI_WeakRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdyFctCustom_btm

#ifndef P_DPLSMI_WeakRdyFctStCtr_btm
#define P_DPLSMI_WeakRdyFctStCtr_btm (LCF_CommonParamData.P_DPLSMI_WeakRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdyFctStCtr_btm() (P_DPLSMI_WeakRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdyFctStCtr_btm

#ifndef P_DPLSMI_WeakRdyFctStErr_btm
#define P_DPLSMI_WeakRdyFctStErr_btm (LCF_CommonParamData.P_DPLSMI_WeakRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdyFctStErr_btm() (P_DPLSMI_WeakRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdyFctStErr_btm

#ifndef P_DPLSMI_WeakRdyFctStNotAv_btm
#define P_DPLSMI_WeakRdyFctStNotAv_btm (LCF_CommonParamData.P_DPLSMI_WeakRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdyFctStNotAv_btm() (P_DPLSMI_WeakRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdyFctStNotAv_btm

#ifndef P_DPLSMI_WeakRdySpecific_btm
#define P_DPLSMI_WeakRdySpecific_btm (LCF_CommonParamData.P_DPLSMI_WeakRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdySpecific_btm() (P_DPLSMI_WeakRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdySpecific_btm

#ifndef P_DPLSMI_WeakRdyVehSt_btm
#define P_DPLSMI_WeakRdyVehSt_btm (LCF_CommonParamData.P_DPLSMI_WeakRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMI_WeakRdyVehSt_btm() (P_DPLSMI_WeakRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMI_WeakRdyVehSt_btm

#ifndef P_DPLSMW_AbortDegrDuration_sec
#define P_DPLSMW_AbortDegrDuration_sec (LCF_CommonParamData.P_DPLSMW_AbortDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortDegrDuration_sec() (P_DPLSMW_AbortDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortDegrDuration_sec

#ifndef P_DPLSMW_AbortDrvSt_btm
#define P_DPLSMW_AbortDrvSt_btm (LCF_CommonParamData.P_DPLSMW_AbortDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortDrvSt_btm() (P_DPLSMW_AbortDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortDrvSt_btm

#ifndef P_DPLSMW_AbortFctCustom_btm
#define P_DPLSMW_AbortFctCustom_btm (LCF_CommonParamData.P_DPLSMW_AbortFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortFctCustom_btm() (P_DPLSMW_AbortFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortFctCustom_btm

#ifndef P_DPLSMW_AbortFctStCtr_btm
#define P_DPLSMW_AbortFctStCtr_btm (LCF_CommonParamData.P_DPLSMW_AbortFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortFctStCtr_btm() (P_DPLSMW_AbortFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortFctStCtr_btm

#ifndef P_DPLSMW_AbortFctStErr_btm
#define P_DPLSMW_AbortFctStErr_btm (LCF_CommonParamData.P_DPLSMW_AbortFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortFctStErr_btm() (P_DPLSMW_AbortFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortFctStErr_btm

#ifndef P_DPLSMW_AbortFctStNotAv_btm
#define P_DPLSMW_AbortFctStNotAv_btm (LCF_CommonParamData.P_DPLSMW_AbortFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortFctStNotAv_btm() (P_DPLSMW_AbortFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortFctStNotAv_btm

#ifndef P_DPLSMW_AbortSpecific_btm
#define P_DPLSMW_AbortSpecific_btm (LCF_CommonParamData.P_DPLSMW_AbortSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortSpecific_btm() (P_DPLSMW_AbortSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortSpecific_btm

#ifndef P_DPLSMW_AbortVehSt_btm
#define P_DPLSMW_AbortVehSt_btm (LCF_CommonParamData.P_DPLSMW_AbortVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_AbortVehSt_btm() (P_DPLSMW_AbortVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_AbortVehSt_btm

#ifndef P_DPLSMW_BlockingTimeDuration_sec
#define P_DPLSMW_BlockingTimeDuration_sec (LCF_CommonParamData.P_DPLSMW_BlockingTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_BlockingTimeDuration_sec() (P_DPLSMW_BlockingTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_BlockingTimeDuration_sec

#ifndef P_DPLSMW_CancelDegrDuration_sec
#define P_DPLSMW_CancelDegrDuration_sec (LCF_CommonParamData.P_DPLSMW_CancelDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelDegrDuration_sec() (P_DPLSMW_CancelDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelDegrDuration_sec

#ifndef P_DPLSMW_CancelDrvSt_btm
#define P_DPLSMW_CancelDrvSt_btm (LCF_CommonParamData.P_DPLSMW_CancelDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelDrvSt_btm() (P_DPLSMW_CancelDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelDrvSt_btm

#ifndef P_DPLSMW_CancelFctCustom_btm
#define P_DPLSMW_CancelFctCustom_btm (LCF_CommonParamData.P_DPLSMW_CancelFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelFctCustom_btm() (P_DPLSMW_CancelFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelFctCustom_btm

#ifndef P_DPLSMW_CancelFctStCtr_btm
#define P_DPLSMW_CancelFctStCtr_btm (LCF_CommonParamData.P_DPLSMW_CancelFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelFctStCtr_btm() (P_DPLSMW_CancelFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelFctStCtr_btm

#ifndef P_DPLSMW_CancelFctStErr_btm
#define P_DPLSMW_CancelFctStErr_btm (LCF_CommonParamData.P_DPLSMW_CancelFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelFctStErr_btm() (P_DPLSMW_CancelFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelFctStErr_btm

#ifndef P_DPLSMW_CancelFctStNotAv_btm
#define P_DPLSMW_CancelFctStNotAv_btm (LCF_CommonParamData.P_DPLSMW_CancelFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelFctStNotAv_btm() (P_DPLSMW_CancelFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelFctStNotAv_btm

#ifndef P_DPLSMW_CancelSpecific_btm
#define P_DPLSMW_CancelSpecific_btm (LCF_CommonParamData.P_DPLSMW_CancelSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelSpecific_btm() (P_DPLSMW_CancelSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelSpecific_btm

#ifndef P_DPLSMW_CancelVehSt_btm
#define P_DPLSMW_CancelVehSt_btm (LCF_CommonParamData.P_DPLSMW_CancelVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_CancelVehSt_btm() (P_DPLSMW_CancelVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_CancelVehSt_btm

#ifndef P_DPLSMW_DebugDrvSt_btm
#define P_DPLSMW_DebugDrvSt_btm (LCF_CommonParamData.P_DPLSMW_DebugDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_DebugDrvSt_btm() (P_DPLSMW_DebugDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_DebugDrvSt_btm

#ifndef P_DPLSMW_DebugSpecific_btm
#define P_DPLSMW_DebugSpecific_btm (LCF_CommonParamData.P_DPLSMW_DebugSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_DebugSpecific_btm() (P_DPLSMW_DebugSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_DebugSpecific_btm

#ifndef P_DPLSMW_DlcLimitMax_met
#define P_DPLSMW_DlcLimitMax_met (LCF_CommonParamData.P_DPLSMW_DlcLimitMax_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_DlcLimitMax_met() (P_DPLSMW_DlcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_DlcLimitMax_met

#ifndef P_DPLSMW_DlcLimitMin_met
#define P_DPLSMW_DlcLimitMin_met (LCF_CommonParamData.P_DPLSMW_DlcLimitMin_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_DlcLimitMin_met() (P_DPLSMW_DlcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_DlcLimitMin_met

#ifndef P_DPLSMW_ErrorStateLDWEnable_bool
#define P_DPLSMW_ErrorStateLDWEnable_bool (LCF_CommonParamData.P_DPLSMW_ErrorStateLDWEnable_bool) //!< LCF parameter macro.
#define GET_P_DPLSMW_ErrorStateLDWEnable_bool() (P_DPLSMW_ErrorStateLDWEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMW_ErrorStateLDWEnable_bool

#ifndef P_DPLSMW_ErrorStateLDW_bool
#define P_DPLSMW_ErrorStateLDW_bool (LCF_CommonParamData.P_DPLSMW_ErrorStateLDW_bool) //!< LCF parameter macro.
#define GET_P_DPLSMW_ErrorStateLDW_bool() (P_DPLSMW_ErrorStateLDW_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMW_ErrorStateLDW_bool

#ifndef P_DPLSMW_FctCustomBSMLe_btm
#define P_DPLSMW_FctCustomBSMLe_btm (LCF_CommonParamData.P_DPLSMW_FctCustomBSMLe_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FctCustomBSMLe_btm() (P_DPLSMW_FctCustomBSMLe_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FctCustomBSMLe_btm

#ifndef P_DPLSMW_FctCustomBSMRi_btm
#define P_DPLSMW_FctCustomBSMRi_btm (LCF_CommonParamData.P_DPLSMW_FctCustomBSMRi_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FctCustomBSMRi_btm() (P_DPLSMW_FctCustomBSMRi_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FctCustomBSMRi_btm

#ifndef P_DPLSMW_FctCustomCancelLe_btm
#define P_DPLSMW_FctCustomCancelLe_btm (LCF_CommonParamData.P_DPLSMW_FctCustomCancelLe_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FctCustomCancelLe_btm() (P_DPLSMW_FctCustomCancelLe_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FctCustomCancelLe_btm

#ifndef P_DPLSMW_FctCustomCancelRi_btm
#define P_DPLSMW_FctCustomCancelRi_btm (LCF_CommonParamData.P_DPLSMW_FctCustomCancelRi_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FctCustomCancelRi_btm() (P_DPLSMW_FctCustomCancelRi_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FctCustomCancelRi_btm

#ifndef P_DPLSMW_FctCustomTrgLe_btm
#define P_DPLSMW_FctCustomTrgLe_btm (LCF_CommonParamData.P_DPLSMW_FctCustomTrgLe_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FctCustomTrgLe_btm() (P_DPLSMW_FctCustomTrgLe_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FctCustomTrgLe_btm

#ifndef P_DPLSMW_FctCustomTrgRi_btm
#define P_DPLSMW_FctCustomTrgRi_btm (LCF_CommonParamData.P_DPLSMW_FctCustomTrgRi_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FctCustomTrgRi_btm() (P_DPLSMW_FctCustomTrgRi_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FctCustomTrgRi_btm

#ifndef P_DPLSMW_FinishCondEnable_btm
#define P_DPLSMW_FinishCondEnable_btm (LCF_CommonParamData.P_DPLSMW_FinishCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_FinishCondEnable_btm() (P_DPLSMW_FinishCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FinishCondEnable_btm

#ifndef P_DPLSMW_FinishDegrDuration_sec
#define P_DPLSMW_FinishDegrDuration_sec (LCF_CommonParamData.P_DPLSMW_FinishDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_FinishDegrDuration_sec() (P_DPLSMW_FinishDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FinishDegrDuration_sec

#ifndef P_DPLSMW_FinishMinDuration_sec
#define P_DPLSMW_FinishMinDuration_sec (LCF_CommonParamData.P_DPLSMW_FinishMinDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_FinishMinDuration_sec() (P_DPLSMW_FinishMinDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_FinishMinDuration_sec

#ifndef P_DPLSMW_HazardCancelTol_met
#define P_DPLSMW_HazardCancelTol_met (LCF_CommonParamData.P_DPLSMW_HazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_HazardCancelTol_met() (P_DPLSMW_HazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_HazardCancelTol_met

#ifndef P_DPLSMW_HazardFinishHeadAng_rad
#define P_DPLSMW_HazardFinishHeadAng_rad (LCF_CommonParamData.P_DPLSMW_HazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPLSMW_HazardFinishHeadAng_rad() (P_DPLSMW_HazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPLSMW_HazardFinishHeadAng_rad

#ifndef P_DPLSMW_HazardFinishVelLat_mps
#define P_DPLSMW_HazardFinishVelLat_mps (LCF_CommonParamData.P_DPLSMW_HazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPLSMW_HazardFinishVelLat_mps() (P_DPLSMW_HazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPLSMW_HazardFinishVelLat_mps

#ifndef P_DPLSMW_LDWSwitchEnable_bool
#define P_DPLSMW_LDWSwitchEnable_bool (LCF_CommonParamData.P_DPLSMW_LDWSwitchEnable_bool) //!< LCF parameter macro.
#define GET_P_DPLSMW_LDWSwitchEnable_bool() (P_DPLSMW_LDWSwitchEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMW_LDWSwitchEnable_bool

#ifndef P_DPLSMW_LDWSwitch_bool
#define P_DPLSMW_LDWSwitch_bool (LCF_CommonParamData.P_DPLSMW_LDWSwitch_bool) //!< LCF parameter macro.
#define GET_P_DPLSMW_LDWSwitch_bool() (P_DPLSMW_LDWSwitch_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMW_LDWSwitch_bool

#ifndef P_DPLSMW_NoHazardCancelTol_met
#define P_DPLSMW_NoHazardCancelTol_met (LCF_CommonParamData.P_DPLSMW_NoHazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_NoHazardCancelTol_met() (P_DPLSMW_NoHazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_NoHazardCancelTol_met

#ifndef P_DPLSMW_NoHazardFinishHeadAng_rad
#define P_DPLSMW_NoHazardFinishHeadAng_rad (LCF_CommonParamData.P_DPLSMW_NoHazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPLSMW_NoHazardFinishHeadAng_rad() (P_DPLSMW_NoHazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPLSMW_NoHazardFinishHeadAng_rad

#ifndef P_DPLSMW_NoHazardFinishVelLat_mps
#define P_DPLSMW_NoHazardFinishVelLat_mps (LCF_CommonParamData.P_DPLSMW_NoHazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPLSMW_NoHazardFinishVelLat_mps() (P_DPLSMW_NoHazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPLSMW_NoHazardFinishVelLat_mps

#ifndef P_DPLSMW_OnTargetFinishTime_sec
#define P_DPLSMW_OnTargetFinishTime_sec (LCF_CommonParamData.P_DPLSMW_OnTargetFinishTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_OnTargetFinishTime_sec() (P_DPLSMW_OnTargetFinishTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_OnTargetFinishTime_sec

#ifndef P_DPLSMW_SafeSituationDelay_sec
#define P_DPLSMW_SafeSituationDelay_sec (LCF_CommonParamData.P_DPLSMW_SafeSituationDelay_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_SafeSituationDelay_sec() (P_DPLSMW_SafeSituationDelay_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SafeSituationDelay_sec

#ifndef P_DPLSMW_SafeSituationOffset_met
#define P_DPLSMW_SafeSituationOffset_met (LCF_CommonParamData.P_DPLSMW_SafeSituationOffset_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_SafeSituationOffset_met() (P_DPLSMW_SafeSituationOffset_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SafeSituationOffset_met

#ifndef P_DPLSMW_SafeSituationState_btm
#define P_DPLSMW_SafeSituationState_btm (LCF_CommonParamData.P_DPLSMW_SafeSituationState_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SafeSituationState_btm() (P_DPLSMW_SafeSituationState_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SafeSituationState_btm

#ifndef P_DPLSMW_SideCondCancel_btm
#define P_DPLSMW_SideCondCancel_btm (LCF_CommonParamData.P_DPLSMW_SideCondCancel_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SideCondCancel_btm() (P_DPLSMW_SideCondCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SideCondCancel_btm

#ifndef P_DPLSMW_SideCondDebug_btm
#define P_DPLSMW_SideCondDebug_btm (LCF_CommonParamData.P_DPLSMW_SideCondDebug_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SideCondDebug_btm() (P_DPLSMW_SideCondDebug_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SideCondDebug_btm

#ifndef P_DPLSMW_SideCondEnable_btm
#define P_DPLSMW_SideCondEnable_btm (LCF_CommonParamData.P_DPLSMW_SideCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SideCondEnable_btm() (P_DPLSMW_SideCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SideCondEnable_btm

#ifndef P_DPLSMW_StrgRdyDegrDuration_sec
#define P_DPLSMW_StrgRdyDegrDuration_sec (LCF_CommonParamData.P_DPLSMW_StrgRdyDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyDegrDuration_sec() (P_DPLSMW_StrgRdyDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyDegrDuration_sec

#ifndef P_DPLSMW_StrgRdyDrvSt_btm
#define P_DPLSMW_StrgRdyDrvSt_btm (LCF_CommonParamData.P_DPLSMW_StrgRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyDrvSt_btm() (P_DPLSMW_StrgRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyDrvSt_btm

#ifndef P_DPLSMW_StrgRdyFctCustom_btm
#define P_DPLSMW_StrgRdyFctCustom_btm (LCF_CommonParamData.P_DPLSMW_StrgRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyFctCustom_btm() (P_DPLSMW_StrgRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyFctCustom_btm

#ifndef P_DPLSMW_StrgRdyFctStCtr_btm
#define P_DPLSMW_StrgRdyFctStCtr_btm (LCF_CommonParamData.P_DPLSMW_StrgRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyFctStCtr_btm() (P_DPLSMW_StrgRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyFctStCtr_btm

#ifndef P_DPLSMW_StrgRdyFctStErr_btm
#define P_DPLSMW_StrgRdyFctStErr_btm (LCF_CommonParamData.P_DPLSMW_StrgRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyFctStErr_btm() (P_DPLSMW_StrgRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyFctStErr_btm

#ifndef P_DPLSMW_StrgRdyFctStNotAv_btm
#define P_DPLSMW_StrgRdyFctStNotAv_btm (LCF_CommonParamData.P_DPLSMW_StrgRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyFctStNotAv_btm() (P_DPLSMW_StrgRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyFctStNotAv_btm

#ifndef P_DPLSMW_StrgRdySpecific_btm
#define P_DPLSMW_StrgRdySpecific_btm (LCF_CommonParamData.P_DPLSMW_StrgRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdySpecific_btm() (P_DPLSMW_StrgRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdySpecific_btm

#ifndef P_DPLSMW_StrgRdyVehSt_btm
#define P_DPLSMW_StrgRdyVehSt_btm (LCF_CommonParamData.P_DPLSMW_StrgRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_StrgRdyVehSt_btm() (P_DPLSMW_StrgRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_StrgRdyVehSt_btm

#ifndef P_DPLSMW_SuppressDrvSt_btm
#define P_DPLSMW_SuppressDrvSt_btm (LCF_CommonParamData.P_DPLSMW_SuppressDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressDrvSt_btm() (P_DPLSMW_SuppressDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressDrvSt_btm

#ifndef P_DPLSMW_SuppressFctCustom_btm
#define P_DPLSMW_SuppressFctCustom_btm (LCF_CommonParamData.P_DPLSMW_SuppressFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressFctCustom_btm() (P_DPLSMW_SuppressFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressFctCustom_btm

#ifndef P_DPLSMW_SuppressFctStCtr_btm
#define P_DPLSMW_SuppressFctStCtr_btm (LCF_CommonParamData.P_DPLSMW_SuppressFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressFctStCtr_btm() (P_DPLSMW_SuppressFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressFctStCtr_btm

#ifndef P_DPLSMW_SuppressFctStErr_btm
#define P_DPLSMW_SuppressFctStErr_btm (LCF_CommonParamData.P_DPLSMW_SuppressFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressFctStErr_btm() (P_DPLSMW_SuppressFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressFctStErr_btm

#ifndef P_DPLSMW_SuppressFctStNotAv_btm
#define P_DPLSMW_SuppressFctStNotAv_btm (LCF_CommonParamData.P_DPLSMW_SuppressFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressFctStNotAv_btm() (P_DPLSMW_SuppressFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressFctStNotAv_btm

#ifndef P_DPLSMW_SuppressSpecific_btm
#define P_DPLSMW_SuppressSpecific_btm (LCF_CommonParamData.P_DPLSMW_SuppressSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressSpecific_btm() (P_DPLSMW_SuppressSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressSpecific_btm

#ifndef P_DPLSMW_SuppressVehSt_btm
#define P_DPLSMW_SuppressVehSt_btm (LCF_CommonParamData.P_DPLSMW_SuppressVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_SuppressVehSt_btm() (P_DPLSMW_SuppressVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_SuppressVehSt_btm

#ifndef P_DPLSMW_TgtTrajPosY0_met
#define P_DPLSMW_TgtTrajPosY0_met (LCF_CommonParamData.P_DPLSMW_TgtTrajPosY0_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_TgtTrajPosY0_met() (P_DPLSMW_TgtTrajPosY0_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_TgtTrajPosY0_met

#ifndef P_DPLSMW_TlcDistanceMin_met
#define P_DPLSMW_TlcDistanceMin_met (LCF_CommonParamData.P_DPLSMW_TlcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_DPLSMW_TlcDistanceMin_met() (P_DPLSMW_TlcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_DPLSMW_TlcDistanceMin_met

#ifndef P_DPLSMW_TlcValidMinTime_sec
#define P_DPLSMW_TlcValidMinTime_sec (LCF_CommonParamData.P_DPLSMW_TlcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_TlcValidMinTime_sec() (P_DPLSMW_TlcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_TlcValidMinTime_sec

#ifndef P_DPLSMW_TriggerAlwaysOn_bool
#define P_DPLSMW_TriggerAlwaysOn_bool (LCF_CommonParamData.P_DPLSMW_TriggerAlwaysOn_bool) //!< LCF parameter macro.
#define GET_P_DPLSMW_TriggerAlwaysOn_bool() (P_DPLSMW_TriggerAlwaysOn_bool) //!< LCF parameter macro getter.
#endif // P_DPLSMW_TriggerAlwaysOn_bool

#ifndef P_DPLSMW_TriggerCondEnable_btm
#define P_DPLSMW_TriggerCondEnable_btm (LCF_CommonParamData.P_DPLSMW_TriggerCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_TriggerCondEnable_btm() (P_DPLSMW_TriggerCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_TriggerCondEnable_btm

#ifndef P_DPLSMW_TriggerHoldingTime_sec
#define P_DPLSMW_TriggerHoldingTime_sec (LCF_CommonParamData.P_DPLSMW_TriggerHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_DPLSMW_TriggerHoldingTime_sec() (P_DPLSMW_TriggerHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_DPLSMW_TriggerHoldingTime_sec

#ifndef P_DPLSMW_WeakRdyDrvSt_btm
#define P_DPLSMW_WeakRdyDrvSt_btm (LCF_CommonParamData.P_DPLSMW_WeakRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdyDrvSt_btm() (P_DPLSMW_WeakRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdyDrvSt_btm

#ifndef P_DPLSMW_WeakRdyFctCustom_btm
#define P_DPLSMW_WeakRdyFctCustom_btm (LCF_CommonParamData.P_DPLSMW_WeakRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdyFctCustom_btm() (P_DPLSMW_WeakRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdyFctCustom_btm

#ifndef P_DPLSMW_WeakRdyFctStCtr_btm
#define P_DPLSMW_WeakRdyFctStCtr_btm (LCF_CommonParamData.P_DPLSMW_WeakRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdyFctStCtr_btm() (P_DPLSMW_WeakRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdyFctStCtr_btm

#ifndef P_DPLSMW_WeakRdyFctStErr_btm
#define P_DPLSMW_WeakRdyFctStErr_btm (LCF_CommonParamData.P_DPLSMW_WeakRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdyFctStErr_btm() (P_DPLSMW_WeakRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdyFctStErr_btm

#ifndef P_DPLSMW_WeakRdyFctStNotAv_btm
#define P_DPLSMW_WeakRdyFctStNotAv_btm (LCF_CommonParamData.P_DPLSMW_WeakRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdyFctStNotAv_btm() (P_DPLSMW_WeakRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdyFctStNotAv_btm

#ifndef P_DPLSMW_WeakRdySpecific_btm
#define P_DPLSMW_WeakRdySpecific_btm (LCF_CommonParamData.P_DPLSMW_WeakRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdySpecific_btm() (P_DPLSMW_WeakRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdySpecific_btm

#ifndef P_DPLSMW_WeakRdyVehSt_btm
#define P_DPLSMW_WeakRdyVehSt_btm (LCF_CommonParamData.P_DPLSMW_WeakRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPLSMW_WeakRdyVehSt_btm() (P_DPLSMW_WeakRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPLSMW_WeakRdyVehSt_btm

#ifndef P_DPLTTG_TargetTrajPT1Active_nu
#define P_DPLTTG_TargetTrajPT1Active_nu (LCF_CommonParamData.P_DPLTTG_TargetTrajPT1Active_nu) //!< LCF parameter macro.
#define GET_P_DPLTTG_TargetTrajPT1Active_nu() (P_DPLTTG_TargetTrajPT1Active_nu) //!< LCF parameter macro getter.
#endif // P_DPLTTG_TargetTrajPT1Active_nu

#ifndef P_DPLTTG_TgtCntrLnEnable_nu
#define P_DPLTTG_TgtCntrLnEnable_nu (LCF_CommonParamData.P_DPLTTG_TgtCntrLnEnable_nu) //!< LCF parameter macro.
#define GET_P_DPLTTG_TgtCntrLnEnable_nu() (P_DPLTTG_TgtCntrLnEnable_nu) //!< LCF parameter macro getter.
#endif // P_DPLTTG_TgtCntrLnEnable_nu

#ifndef P_DPLTTG_TgtMaxDistance_met
#define P_DPLTTG_TgtMaxDistance_met (LCF_CommonParamData.P_DPLTTG_TgtMaxDistance_met) //!< LCF parameter macro.
#define GET_P_DPLTTG_TgtMaxDistance_met() (P_DPLTTG_TgtMaxDistance_met) //!< LCF parameter macro getter.
#endif // P_DPLTTG_TgtMaxDistance_met

#ifndef P_DPLTTG_TgtMaxLatDev_met
#define P_DPLTTG_TgtMaxLatDev_met (LCF_CommonParamData.P_DPLTTG_TgtMaxLatDev_met) //!< LCF parameter macro.
#define GET_P_DPLTTG_TgtMaxLatDev_met() (P_DPLTTG_TgtMaxLatDev_met) //!< LCF parameter macro getter.
#endif // P_DPLTTG_TgtMaxLatDev_met

#ifndef P_DPLTTG_TgtTrjPT1TimeConst_sec
#define P_DPLTTG_TgtTrjPT1TimeConst_sec (LCF_CommonParamData.P_DPLTTG_TgtTrjPT1TimeConst_sec) //!< LCF parameter macro.
#define GET_P_DPLTTG_TgtTrjPT1TimeConst_sec() (P_DPLTTG_TgtTrjPT1TimeConst_sec) //!< LCF parameter macro getter.
#endif // P_DPLTTG_TgtTrjPT1TimeConst_sec

#ifndef P_DPLTVG_DistYTolLeTgtArea_met
#define P_DPLTVG_DistYTolLeTgtArea_met (LCF_CommonParamData.P_DPLTVG_DistYTolLeTgtArea_met) //!< LCF parameter macro.
#define GET_P_DPLTVG_DistYTolLeTgtArea_met() (P_DPLTVG_DistYTolLeTgtArea_met) //!< LCF parameter macro getter.
#endif // P_DPLTVG_DistYTolLeTgtArea_met

#ifndef P_DPLTVG_DistYTolRiTgtArea_met
#define P_DPLTVG_DistYTolRiTgtArea_met (LCF_CommonParamData.P_DPLTVG_DistYTolRiTgtArea_met) //!< LCF parameter macro.
#define GET_P_DPLTVG_DistYTolRiTgtArea_met() (P_DPLTVG_DistYTolRiTgtArea_met) //!< LCF parameter macro getter.
#endif // P_DPLTVG_DistYTolRiTgtArea_met

#ifndef P_DPLTVG_FTireAclMax_mps2
#define P_DPLTVG_FTireAclMax_mps2 (LCF_CommonParamData.P_DPLTVG_FTireAclMax_mps2) //!< LCF parameter macro.
#define GET_P_DPLTVG_FTireAclMax_mps2() (P_DPLTVG_FTireAclMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPLTVG_FTireAclMax_mps2

#ifndef P_DPLTVG_FTireAclMin_mps2
#define P_DPLTVG_FTireAclMin_mps2 (LCF_CommonParamData.P_DPLTVG_FTireAclMin_mps2) //!< LCF parameter macro.
#define GET_P_DPLTVG_FTireAclMin_mps2() (P_DPLTVG_FTireAclMin_mps2) //!< LCF parameter macro getter.
#endif // P_DPLTVG_FTireAclMin_mps2

#ifndef P_DPLTVG_HighStatAccu_bool
#define P_DPLTVG_HighStatAccu_bool (LCF_CommonParamData.P_DPLTVG_HighStatAccu_bool) //!< LCF parameter macro.
#define GET_P_DPLTVG_HighStatAccu_bool() (P_DPLTVG_HighStatAccu_bool) //!< LCF parameter macro getter.
#endif // P_DPLTVG_HighStatAccu_bool

#ifndef P_DPLTVG_LimiterActivated_bool
#define P_DPLTVG_LimiterActivated_bool (LCF_CommonParamData.P_DPLTVG_LimiterActivated_bool) //!< LCF parameter macro.
#define GET_P_DPLTVG_LimiterActivated_bool() (P_DPLTVG_LimiterActivated_bool) //!< LCF parameter macro getter.
#endif // P_DPLTVG_LimiterActivated_bool

#ifndef P_DPLTVG_LimiterMaxCrvGrd_1pms
#define P_DPLTVG_LimiterMaxCrvGrd_1pms (LCF_CommonParamData.P_DPLTVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro.
#define GET_P_DPLTVG_LimiterMaxCrvGrd_1pms() (P_DPLTVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro getter.
#endif // P_DPLTVG_LimiterMaxCrvGrd_1pms

#ifndef P_DPLTVG_LimiterMaxCrv_1pm
#define P_DPLTVG_LimiterMaxCrv_1pm (LCF_CommonParamData.P_DPLTVG_LimiterMaxCrv_1pm) //!< LCF parameter macro.
#define GET_P_DPLTVG_LimiterMaxCrv_1pm() (P_DPLTVG_LimiterMaxCrv_1pm) //!< LCF parameter macro getter.
#endif // P_DPLTVG_LimiterMaxCrv_1pm

#ifndef P_DPLTVG_LimiterTimeDuration_sec
#define P_DPLTVG_LimiterTimeDuration_sec (LCF_CommonParamData.P_DPLTVG_LimiterTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_DPLTVG_LimiterTimeDuration_sec() (P_DPLTVG_LimiterTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPLTVG_LimiterTimeDuration_sec

#ifndef P_DPLTVG_MaxJerkAllowed_mps3
#define P_DPLTVG_MaxJerkAllowed_mps3 (LCF_CommonParamData.P_DPLTVG_MaxJerkAllowed_mps3) //!< LCF parameter macro.
#define GET_P_DPLTVG_MaxJerkAllowed_mps3() (P_DPLTVG_MaxJerkAllowed_mps3) //!< LCF parameter macro getter.
#endif // P_DPLTVG_MaxJerkAllowed_mps3

#ifndef P_DPLTVG_MaxTrqScalLimit_nu
#define P_DPLTVG_MaxTrqScalLimit_nu (LCF_CommonParamData.P_DPLTVG_MaxTrqScalLimit_nu) //!< LCF parameter macro.
#define GET_P_DPLTVG_MaxTrqScalLimit_nu() (P_DPLTVG_MaxTrqScalLimit_nu) //!< LCF parameter macro getter.
#endif // P_DPLTVG_MaxTrqScalLimit_nu

#ifndef P_DPLTVG_MaxTrqScalRampInGrd_1ps
#define P_DPLTVG_MaxTrqScalRampInGrd_1ps (LCF_CommonParamData.P_DPLTVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_MaxTrqScalRampInGrd_1ps() (P_DPLTVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_MaxTrqScalRampInGrd_1ps

#ifndef P_DPLTVG_MaxTrqScalRampOutGrd_1ps
#define P_DPLTVG_MaxTrqScalRampOutGrd_1ps (LCF_CommonParamData.P_DPLTVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_MaxTrqScalRampOutGrd_1ps() (P_DPLTVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_MaxTrqScalRampOutGrd_1ps

#ifndef P_DPLTVG_PredTimeCrv_sec
#define P_DPLTVG_PredTimeCrv_sec (LCF_CommonParamData.P_DPLTVG_PredTimeCrv_sec) //!< LCF parameter macro.
#define GET_P_DPLTVG_PredTimeCrv_sec() (P_DPLTVG_PredTimeCrv_sec) //!< LCF parameter macro getter.
#endif // P_DPLTVG_PredTimeCrv_sec

#ifndef P_DPLTVG_PredTimeHeadAng_sec
#define P_DPLTVG_PredTimeHeadAng_sec (LCF_CommonParamData.P_DPLTVG_PredTimeHeadAng_sec) //!< LCF parameter macro.
#define GET_P_DPLTVG_PredTimeHeadAng_sec() (P_DPLTVG_PredTimeHeadAng_sec) //!< LCF parameter macro getter.
#endif // P_DPLTVG_PredTimeHeadAng_sec

#ifndef P_DPLTVG_StrWhStifAbortROGrd_1ps
#define P_DPLTVG_StrWhStifAbortROGrd_1ps (LCF_CommonParamData.P_DPLTVG_StrWhStifAbortROGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_StrWhStifAbortROGrd_1ps() (P_DPLTVG_StrWhStifAbortROGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_StrWhStifAbortROGrd_1ps

#ifndef P_DPLTVG_StrWhStifLimit_nu
#define P_DPLTVG_StrWhStifLimit_nu (LCF_CommonParamData.P_DPLTVG_StrWhStifLimit_nu) //!< LCF parameter macro.
#define GET_P_DPLTVG_StrWhStifLimit_nu() (P_DPLTVG_StrWhStifLimit_nu) //!< LCF parameter macro getter.
#endif // P_DPLTVG_StrWhStifLimit_nu

#ifndef P_DPLTVG_StrWhStifROGrad_1ps
#define P_DPLTVG_StrWhStifROGrad_1ps (LCF_CommonParamData.P_DPLTVG_StrWhStifROGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_StrWhStifROGrad_1ps() (P_DPLTVG_StrWhStifROGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_StrWhStifROGrad_1ps

#ifndef P_DPLTVG_TrajPlanServQu_nu
#define P_DPLTVG_TrajPlanServQu_nu (LCF_CommonParamData.P_DPLTVG_TrajPlanServQu_nu) //!< LCF parameter macro.
#define GET_P_DPLTVG_TrajPlanServQu_nu() (P_DPLTVG_TrajPlanServQu_nu) //!< LCF parameter macro getter.
#endif // P_DPLTVG_TrajPlanServQu_nu

#ifndef P_DPLTVG_TriggerReplan_bool
#define P_DPLTVG_TriggerReplan_bool (LCF_CommonParamData.P_DPLTVG_TriggerReplan_bool) //!< LCF parameter macro.
#define GET_P_DPLTVG_TriggerReplan_bool() (P_DPLTVG_TriggerReplan_bool) //!< LCF parameter macro getter.
#endif // P_DPLTVG_TriggerReplan_bool

#ifndef P_DPLTVG_TrqAbortROGrd_1ps
#define P_DPLTVG_TrqAbortROGrd_1ps (LCF_CommonParamData.P_DPLTVG_TrqAbortROGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_TrqAbortROGrd_1ps() (P_DPLTVG_TrqAbortROGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_TrqAbortROGrd_1ps

#ifndef P_DPLTVG_TrqRampInGrad_1ps
#define P_DPLTVG_TrqRampInGrad_1ps (LCF_CommonParamData.P_DPLTVG_TrqRampInGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_TrqRampInGrad_1ps() (P_DPLTVG_TrqRampInGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_TrqRampInGrad_1ps

#ifndef P_DPLTVG_TrqRampOutGrad_1ps
#define P_DPLTVG_TrqRampOutGrad_1ps (LCF_CommonParamData.P_DPLTVG_TrqRampOutGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPLTVG_TrqRampOutGrad_1ps() (P_DPLTVG_TrqRampOutGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPLTVG_TrqRampOutGrad_1ps

#ifndef P_DPLTVG_UseLtcyComp_nu
#define P_DPLTVG_UseLtcyComp_nu (LCF_CommonParamData.P_DPLTVG_UseLtcyComp_nu) //!< LCF parameter macro.
#define GET_P_DPLTVG_UseLtcyComp_nu() (P_DPLTVG_UseLtcyComp_nu) //!< LCF parameter macro getter.
#endif // P_DPLTVG_UseLtcyComp_nu

#ifndef P_DPLTVG_WeightTgtDistY_nu
#define P_DPLTVG_WeightTgtDistY_nu (LCF_CommonParamData.P_DPLTVG_WeightTgtDistY_nu) //!< LCF parameter macro.
#define GET_P_DPLTVG_WeightTgtDistY_nu() (P_DPLTVG_WeightTgtDistY_nu) //!< LCF parameter macro getter.
#endif // P_DPLTVG_WeightTgtDistY_nu

#ifndef P_DPRSIA_AclXHyst_mps2
#define P_DPRSIA_AclXHyst_mps2 (LCF_CommonParamData.P_DPRSIA_AclXHyst_mps2) //!< LCF parameter macro.
#define GET_P_DPRSIA_AclXHyst_mps2() (P_DPRSIA_AclXHyst_mps2) //!< LCF parameter macro getter.
#endif // P_DPRSIA_AclXHyst_mps2

#ifndef P_DPRSIA_AclXMax_mps2
#define P_DPRSIA_AclXMax_mps2 (LCF_CommonParamData.P_DPRSIA_AclXMax_mps2) //!< LCF parameter macro.
#define GET_P_DPRSIA_AclXMax_mps2() (P_DPRSIA_AclXMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPRSIA_AclXMax_mps2

#ifndef P_DPRSIA_AclXMin_mps2
#define P_DPRSIA_AclXMin_mps2 (LCF_CommonParamData.P_DPRSIA_AclXMin_mps2) //!< LCF parameter macro.
#define GET_P_DPRSIA_AclXMin_mps2() (P_DPRSIA_AclXMin_mps2) //!< LCF parameter macro getter.
#endif // P_DPRSIA_AclXMin_mps2

#ifndef P_DPRSIA_AclYHyst_mps2
#define P_DPRSIA_AclYHyst_mps2 (LCF_CommonParamData.P_DPRSIA_AclYHyst_mps2) //!< LCF parameter macro.
#define GET_P_DPRSIA_AclYHyst_mps2() (P_DPRSIA_AclYHyst_mps2) //!< LCF parameter macro getter.
#endif // P_DPRSIA_AclYHyst_mps2

#ifndef P_DPRSIA_AclYMax_mps2
#define P_DPRSIA_AclYMax_mps2 (LCF_CommonParamData.P_DPRSIA_AclYMax_mps2) //!< LCF parameter macro.
#define GET_P_DPRSIA_AclYMax_mps2() (P_DPRSIA_AclYMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPRSIA_AclYMax_mps2

#ifndef P_DPRSIA_ConstrSiteLnTurnOff_sec
#define P_DPRSIA_ConstrSiteLnTurnOff_sec (LCF_CommonParamData.P_DPRSIA_ConstrSiteLnTurnOff_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_ConstrSiteLnTurnOff_sec() (P_DPRSIA_ConstrSiteLnTurnOff_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ConstrSiteLnTurnOff_sec

#ifndef P_DPRSIA_ConstrSiteLnTurnOn_sec
#define P_DPRSIA_ConstrSiteLnTurnOn_sec (LCF_CommonParamData.P_DPRSIA_ConstrSiteLnTurnOn_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_ConstrSiteLnTurnOn_sec() (P_DPRSIA_ConstrSiteLnTurnOn_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ConstrSiteLnTurnOn_sec

#ifndef P_DPRSIA_ConstrSiteLn_bool
#define P_DPRSIA_ConstrSiteLn_bool (LCF_CommonParamData.P_DPRSIA_ConstrSiteLn_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_ConstrSiteLn_bool() (P_DPRSIA_ConstrSiteLn_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ConstrSiteLn_bool

#ifndef P_DPRSIA_ConstrSiteReTurnOff_sec
#define P_DPRSIA_ConstrSiteReTurnOff_sec (LCF_CommonParamData.P_DPRSIA_ConstrSiteReTurnOff_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_ConstrSiteReTurnOff_sec() (P_DPRSIA_ConstrSiteReTurnOff_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ConstrSiteReTurnOff_sec

#ifndef P_DPRSIA_ConstrSiteReTurnOn_sec
#define P_DPRSIA_ConstrSiteReTurnOn_sec (LCF_CommonParamData.P_DPRSIA_ConstrSiteReTurnOn_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_ConstrSiteReTurnOn_sec() (P_DPRSIA_ConstrSiteReTurnOn_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ConstrSiteReTurnOn_sec

#ifndef P_DPRSIA_ConstrSiteRe_bool
#define P_DPRSIA_ConstrSiteRe_bool (LCF_CommonParamData.P_DPRSIA_ConstrSiteRe_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_ConstrSiteRe_bool() (P_DPRSIA_ConstrSiteRe_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ConstrSiteRe_bool

#ifndef P_DPRSIA_ExitRampProb_perc
#define P_DPRSIA_ExitRampProb_perc (LCF_CommonParamData.P_DPRSIA_ExitRampProb_perc) //!< LCF parameter macro.
#define GET_P_DPRSIA_ExitRampProb_perc() (P_DPRSIA_ExitRampProb_perc) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ExitRampProb_perc

#ifndef P_DPRSIA_ExitRampTurnOff_sec
#define P_DPRSIA_ExitRampTurnOff_sec (LCF_CommonParamData.P_DPRSIA_ExitRampTurnOff_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_ExitRampTurnOff_sec() (P_DPRSIA_ExitRampTurnOff_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ExitRampTurnOff_sec

#ifndef P_DPRSIA_ExitRampTurnOn_sec
#define P_DPRSIA_ExitRampTurnOn_sec (LCF_CommonParamData.P_DPRSIA_ExitRampTurnOn_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_ExitRampTurnOn_sec() (P_DPRSIA_ExitRampTurnOn_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ExitRampTurnOn_sec

#ifndef P_DPRSIA_LaneBitmask_btm
#define P_DPRSIA_LaneBitmask_btm (LCF_CommonParamData.P_DPRSIA_LaneBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneBitmask_btm() (P_DPRSIA_LaneBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneBitmask_btm

#ifndef P_DPRSIA_LaneBridgedBitmask_btm
#define P_DPRSIA_LaneBridgedBitmask_btm (LCF_CommonParamData.P_DPRSIA_LaneBridgedBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneBridgedBitmask_btm() (P_DPRSIA_LaneBridgedBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneBridgedBitmask_btm

#ifndef P_DPRSIA_LaneCancelBitmask_btm
#define P_DPRSIA_LaneCancelBitmask_btm (LCF_CommonParamData.P_DPRSIA_LaneCancelBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneCancelBitmask_btm() (P_DPRSIA_LaneCancelBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneCancelBitmask_btm

#ifndef P_DPRSIA_LaneSafetyBitmask_btm
#define P_DPRSIA_LaneSafetyBitmask_btm (LCF_CommonParamData.P_DPRSIA_LaneSafetyBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneSafetyBitmask_btm() (P_DPRSIA_LaneSafetyBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneSafetyBitmask_btm

#ifndef P_DPRSIA_LaneWidthHyst_met
#define P_DPRSIA_LaneWidthHyst_met (LCF_CommonParamData.P_DPRSIA_LaneWidthHyst_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthHyst_met() (P_DPRSIA_LaneWidthHyst_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthHyst_met

#ifndef P_DPRSIA_LaneWidthMax_met
#define P_DPRSIA_LaneWidthMax_met (LCF_CommonParamData.P_DPRSIA_LaneWidthMax_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthMax_met() (P_DPRSIA_LaneWidthMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthMax_met

#ifndef P_DPRSIA_LaneWidthMin_met
#define P_DPRSIA_LaneWidthMin_met (LCF_CommonParamData.P_DPRSIA_LaneWidthMin_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthMin_met() (P_DPRSIA_LaneWidthMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthMin_met

#ifndef P_DPRSIA_LaneWidthSIFOn_bool
#define P_DPRSIA_LaneWidthSIFOn_bool (LCF_CommonParamData.P_DPRSIA_LaneWidthSIFOn_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthSIFOn_bool() (P_DPRSIA_LaneWidthSIFOn_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthSIFOn_bool

#ifndef P_DPRSIA_LaneWidthSwitch_bool
#define P_DPRSIA_LaneWidthSwitch_bool (LCF_CommonParamData.P_DPRSIA_LaneWidthSwitch_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthSwitch_bool() (P_DPRSIA_LaneWidthSwitch_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthSwitch_bool

#ifndef P_DPRSIA_LaneWidthWideLnDef_met
#define P_DPRSIA_LaneWidthWideLnDef_met (LCF_CommonParamData.P_DPRSIA_LaneWidthWideLnDef_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthWideLnDef_met() (P_DPRSIA_LaneWidthWideLnDef_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthWideLnDef_met

#ifndef P_DPRSIA_LaneWidthWideLn_bool
#define P_DPRSIA_LaneWidthWideLn_bool (LCF_CommonParamData.P_DPRSIA_LaneWidthWideLn_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_LaneWidthWideLn_bool() (P_DPRSIA_LaneWidthWideLn_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LaneWidthWideLn_bool

#ifndef P_DPRSIA_LnBndTurnOnTime_sec
#define P_DPRSIA_LnBndTurnOnTime_sec (LCF_CommonParamData.P_DPRSIA_LnBndTurnOnTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnBndTurnOnTime_sec() (P_DPRSIA_LnBndTurnOnTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnBndTurnOnTime_sec

#ifndef P_DPRSIA_LnHeadAngThresHyst_rad
#define P_DPRSIA_LnHeadAngThresHyst_rad (LCF_CommonParamData.P_DPRSIA_LnHeadAngThresHyst_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnHeadAngThresHyst_rad() (P_DPRSIA_LnHeadAngThresHyst_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnHeadAngThresHyst_rad

#ifndef P_DPRSIA_LnHeadAngThresMax_rad
#define P_DPRSIA_LnHeadAngThresMax_rad (LCF_CommonParamData.P_DPRSIA_LnHeadAngThresMax_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnHeadAngThresMax_rad() (P_DPRSIA_LnHeadAngThresMax_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnHeadAngThresMax_rad

#ifndef P_DPRSIA_LnHeadAngThresMin_rad
#define P_DPRSIA_LnHeadAngThresMin_rad (LCF_CommonParamData.P_DPRSIA_LnHeadAngThresMin_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnHeadAngThresMin_rad() (P_DPRSIA_LnHeadAngThresMin_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnHeadAngThresMin_rad

#ifndef P_DPRSIA_LnRdWidthHyst_met
#define P_DPRSIA_LnRdWidthHyst_met (LCF_CommonParamData.P_DPRSIA_LnRdWidthHyst_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnRdWidthHyst_met() (P_DPRSIA_LnRdWidthHyst_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnRdWidthHyst_met

#ifndef P_DPRSIA_LnRdWidthMax_met
#define P_DPRSIA_LnRdWidthMax_met (LCF_CommonParamData.P_DPRSIA_LnRdWidthMax_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnRdWidthMax_met() (P_DPRSIA_LnRdWidthMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnRdWidthMax_met

#ifndef P_DPRSIA_LnRdWidthMin_met
#define P_DPRSIA_LnRdWidthMin_met (LCF_CommonParamData.P_DPRSIA_LnRdWidthMin_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_LnRdWidthMin_met() (P_DPRSIA_LnRdWidthMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_LnRdWidthMin_met

#ifndef P_DPRSIA_RdBndTurnOnTime_sec
#define P_DPRSIA_RdBndTurnOnTime_sec (LCF_CommonParamData.P_DPRSIA_RdBndTurnOnTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_RdBndTurnOnTime_sec() (P_DPRSIA_RdBndTurnOnTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RdBndTurnOnTime_sec

#ifndef P_DPRSIA_ReHeadAngThresHyst_rad
#define P_DPRSIA_ReHeadAngThresHyst_rad (LCF_CommonParamData.P_DPRSIA_ReHeadAngThresHyst_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_ReHeadAngThresHyst_rad() (P_DPRSIA_ReHeadAngThresHyst_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ReHeadAngThresHyst_rad

#ifndef P_DPRSIA_ReHeadAngThresMax_rad
#define P_DPRSIA_ReHeadAngThresMax_rad (LCF_CommonParamData.P_DPRSIA_ReHeadAngThresMax_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_ReHeadAngThresMax_rad() (P_DPRSIA_ReHeadAngThresMax_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ReHeadAngThresMax_rad

#ifndef P_DPRSIA_ReHeadAngThresMin_rad
#define P_DPRSIA_ReHeadAngThresMin_rad (LCF_CommonParamData.P_DPRSIA_ReHeadAngThresMin_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_ReHeadAngThresMin_rad() (P_DPRSIA_ReHeadAngThresMin_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_ReHeadAngThresMin_rad

#ifndef P_DPRSIA_RoadBitmask_btm
#define P_DPRSIA_RoadBitmask_btm (LCF_CommonParamData.P_DPRSIA_RoadBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadBitmask_btm() (P_DPRSIA_RoadBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadBitmask_btm

#ifndef P_DPRSIA_RoadBridgedBitmask_btm
#define P_DPRSIA_RoadBridgedBitmask_btm (LCF_CommonParamData.P_DPRSIA_RoadBridgedBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadBridgedBitmask_btm() (P_DPRSIA_RoadBridgedBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadBridgedBitmask_btm

#ifndef P_DPRSIA_RoadCancelBitmask_btm
#define P_DPRSIA_RoadCancelBitmask_btm (LCF_CommonParamData.P_DPRSIA_RoadCancelBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadCancelBitmask_btm() (P_DPRSIA_RoadCancelBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadCancelBitmask_btm

#ifndef P_DPRSIA_RoadSafetyBitmask_btm
#define P_DPRSIA_RoadSafetyBitmask_btm (LCF_CommonParamData.P_DPRSIA_RoadSafetyBitmask_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadSafetyBitmask_btm() (P_DPRSIA_RoadSafetyBitmask_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadSafetyBitmask_btm

#ifndef P_DPRSIA_RoadWidthHyst_met
#define P_DPRSIA_RoadWidthHyst_met (LCF_CommonParamData.P_DPRSIA_RoadWidthHyst_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadWidthHyst_met() (P_DPRSIA_RoadWidthHyst_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadWidthHyst_met

#ifndef P_DPRSIA_RoadWidthMax_met
#define P_DPRSIA_RoadWidthMax_met (LCF_CommonParamData.P_DPRSIA_RoadWidthMax_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadWidthMax_met() (P_DPRSIA_RoadWidthMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadWidthMax_met

#ifndef P_DPRSIA_RoadWidthMin_met
#define P_DPRSIA_RoadWidthMin_met (LCF_CommonParamData.P_DPRSIA_RoadWidthMin_met) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadWidthMin_met() (P_DPRSIA_RoadWidthMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadWidthMin_met

#ifndef P_DPRSIA_RoadWidthSwitch_bool
#define P_DPRSIA_RoadWidthSwitch_bool (LCF_CommonParamData.P_DPRSIA_RoadWidthSwitch_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_RoadWidthSwitch_bool() (P_DPRSIA_RoadWidthSwitch_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_RoadWidthSwitch_bool

#ifndef P_DPRSIA_SafetyIfaceLnOn_bool
#define P_DPRSIA_SafetyIfaceLnOn_bool (LCF_CommonParamData.P_DPRSIA_SafetyIfaceLnOn_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_SafetyIfaceLnOn_bool() (P_DPRSIA_SafetyIfaceLnOn_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_SafetyIfaceLnOn_bool

#ifndef P_DPRSIA_SafetyIfaceReOn_bool
#define P_DPRSIA_SafetyIfaceReOn_bool (LCF_CommonParamData.P_DPRSIA_SafetyIfaceReOn_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_SafetyIfaceReOn_bool() (P_DPRSIA_SafetyIfaceReOn_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_SafetyIfaceReOn_bool

#ifndef P_DPRSIA_StrWhlAngSpeedHyst_degps
#define P_DPRSIA_StrWhlAngSpeedHyst_degps (LCF_CommonParamData.P_DPRSIA_StrWhlAngSpeedHyst_degps) //!< LCF parameter macro.
#define GET_P_DPRSIA_StrWhlAngSpeedHyst_degps() (P_DPRSIA_StrWhlAngSpeedHyst_degps) //!< LCF parameter macro getter.
#endif // P_DPRSIA_StrWhlAngSpeedHyst_degps

#ifndef P_DPRSIA_StrWhlAngSpeedMax_degps
#define P_DPRSIA_StrWhlAngSpeedMax_degps (LCF_CommonParamData.P_DPRSIA_StrWhlAngSpeedMax_degps) //!< LCF parameter macro.
#define GET_P_DPRSIA_StrWhlAngSpeedMax_degps() (P_DPRSIA_StrWhlAngSpeedMax_degps) //!< LCF parameter macro getter.
#endif // P_DPRSIA_StrWhlAngSpeedMax_degps

#ifndef P_DPRSIA_StrWhlAngleHyst_deg
#define P_DPRSIA_StrWhlAngleHyst_deg (LCF_CommonParamData.P_DPRSIA_StrWhlAngleHyst_deg) //!< LCF parameter macro.
#define GET_P_DPRSIA_StrWhlAngleHyst_deg() (P_DPRSIA_StrWhlAngleHyst_deg) //!< LCF parameter macro getter.
#endif // P_DPRSIA_StrWhlAngleHyst_deg

#ifndef P_DPRSIA_StrWhlAngleMax_deg
#define P_DPRSIA_StrWhlAngleMax_deg (LCF_CommonParamData.P_DPRSIA_StrWhlAngleMax_deg) //!< LCF parameter macro.
#define GET_P_DPRSIA_StrWhlAngleMax_deg() (P_DPRSIA_StrWhlAngleMax_deg) //!< LCF parameter macro getter.
#endif // P_DPRSIA_StrWhlAngleMax_deg

#ifndef P_DPRSIA_TlcHeadAngThres_rad
#define P_DPRSIA_TlcHeadAngThres_rad (LCF_CommonParamData.P_DPRSIA_TlcHeadAngThres_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_TlcHeadAngThres_rad() (P_DPRSIA_TlcHeadAngThres_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_TlcHeadAngThres_rad

#ifndef P_DPRSIA_TrcHeadAngThres_rad
#define P_DPRSIA_TrcHeadAngThres_rad (LCF_CommonParamData.P_DPRSIA_TrcHeadAngThres_rad) //!< LCF parameter macro.
#define GET_P_DPRSIA_TrcHeadAngThres_rad() (P_DPRSIA_TrcHeadAngThres_rad) //!< LCF parameter macro getter.
#endif // P_DPRSIA_TrcHeadAngThres_rad

#ifndef P_DPRSIA_TriggerCondEnable_btm
#define P_DPRSIA_TriggerCondEnable_btm (LCF_CommonParamData.P_DPRSIA_TriggerCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPRSIA_TriggerCondEnable_btm() (P_DPRSIA_TriggerCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPRSIA_TriggerCondEnable_btm

#ifndef P_DPRSIA_TurnSignHoldingTime_sec
#define P_DPRSIA_TurnSignHoldingTime_sec (LCF_CommonParamData.P_DPRSIA_TurnSignHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSIA_TurnSignHoldingTime_sec() (P_DPRSIA_TurnSignHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSIA_TurnSignHoldingTime_sec

#ifndef P_DPRSIA_TurnSignReset_bool
#define P_DPRSIA_TurnSignReset_bool (LCF_CommonParamData.P_DPRSIA_TurnSignReset_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_TurnSignReset_bool() (P_DPRSIA_TurnSignReset_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_TurnSignReset_bool

#ifndef P_DPRSIA_UncoupledLWEnable_bool
#define P_DPRSIA_UncoupledLWEnable_bool (LCF_CommonParamData.P_DPRSIA_UncoupledLWEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSIA_UncoupledLWEnable_bool() (P_DPRSIA_UncoupledLWEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSIA_UncoupledLWEnable_bool

#ifndef P_DPRSIA_VelLatThresHyst_mps
#define P_DPRSIA_VelLatThresHyst_mps (LCF_CommonParamData.P_DPRSIA_VelLatThresHyst_mps) //!< LCF parameter macro.
#define GET_P_DPRSIA_VelLatThresHyst_mps() (P_DPRSIA_VelLatThresHyst_mps) //!< LCF parameter macro getter.
#endif // P_DPRSIA_VelLatThresHyst_mps

#ifndef P_DPRSIA_VelLatThresMax_mps
#define P_DPRSIA_VelLatThresMax_mps (LCF_CommonParamData.P_DPRSIA_VelLatThresMax_mps) //!< LCF parameter macro.
#define GET_P_DPRSIA_VelLatThresMax_mps() (P_DPRSIA_VelLatThresMax_mps) //!< LCF parameter macro getter.
#endif // P_DPRSIA_VelLatThresMax_mps

#ifndef P_DPRSIA_VelLatThresMin_mps
#define P_DPRSIA_VelLatThresMin_mps (LCF_CommonParamData.P_DPRSIA_VelLatThresMin_mps) //!< LCF parameter macro.
#define GET_P_DPRSIA_VelLatThresMin_mps() (P_DPRSIA_VelLatThresMin_mps) //!< LCF parameter macro getter.
#endif // P_DPRSIA_VelLatThresMin_mps

#ifndef P_DPRSIA_VelVehDispHyst_kph
#define P_DPRSIA_VelVehDispHyst_kph (LCF_CommonParamData.P_DPRSIA_VelVehDispHyst_kph) //!< LCF parameter macro.
#define GET_P_DPRSIA_VelVehDispHyst_kph() (P_DPRSIA_VelVehDispHyst_kph) //!< LCF parameter macro getter.
#endif // P_DPRSIA_VelVehDispHyst_kph

#ifndef P_DPRSIA_VelVehDispMax_kph
#define P_DPRSIA_VelVehDispMax_kph (LCF_CommonParamData.P_DPRSIA_VelVehDispMax_kph) //!< LCF parameter macro.
#define GET_P_DPRSIA_VelVehDispMax_kph() (P_DPRSIA_VelVehDispMax_kph) //!< LCF parameter macro getter.
#endif // P_DPRSIA_VelVehDispMax_kph

#ifndef P_DPRSIA_VelVehDispMin_kph
#define P_DPRSIA_VelVehDispMin_kph (LCF_CommonParamData.P_DPRSIA_VelVehDispMin_kph) //!< LCF parameter macro.
#define GET_P_DPRSIA_VelVehDispMin_kph() (P_DPRSIA_VelVehDispMin_kph) //!< LCF parameter macro getter.
#endif // P_DPRSIA_VelVehDispMin_kph

#ifndef P_DPRSMI_AbortDrvSt_btm
#define P_DPRSMI_AbortDrvSt_btm (LCF_CommonParamData.P_DPRSMI_AbortDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortDrvSt_btm() (P_DPRSMI_AbortDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortDrvSt_btm

#ifndef P_DPRSMI_AbortFctCustom_btm
#define P_DPRSMI_AbortFctCustom_btm (LCF_CommonParamData.P_DPRSMI_AbortFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortFctCustom_btm() (P_DPRSMI_AbortFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortFctCustom_btm

#ifndef P_DPRSMI_AbortFctStCtr_btm
#define P_DPRSMI_AbortFctStCtr_btm (LCF_CommonParamData.P_DPRSMI_AbortFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortFctStCtr_btm() (P_DPRSMI_AbortFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortFctStCtr_btm

#ifndef P_DPRSMI_AbortFctStErr_btm
#define P_DPRSMI_AbortFctStErr_btm (LCF_CommonParamData.P_DPRSMI_AbortFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortFctStErr_btm() (P_DPRSMI_AbortFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortFctStErr_btm

#ifndef P_DPRSMI_AbortFctStNotAv_btm
#define P_DPRSMI_AbortFctStNotAv_btm (LCF_CommonParamData.P_DPRSMI_AbortFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortFctStNotAv_btm() (P_DPRSMI_AbortFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortFctStNotAv_btm

#ifndef P_DPRSMI_AbortSpecific_btm
#define P_DPRSMI_AbortSpecific_btm (LCF_CommonParamData.P_DPRSMI_AbortSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortSpecific_btm() (P_DPRSMI_AbortSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortSpecific_btm

#ifndef P_DPRSMI_AbortVehSt_btm
#define P_DPRSMI_AbortVehSt_btm (LCF_CommonParamData.P_DPRSMI_AbortVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_AbortVehSt_btm() (P_DPRSMI_AbortVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_AbortVehSt_btm

#ifndef P_DPRSMI_BlockingTimeDuration_sec
#define P_DPRSMI_BlockingTimeDuration_sec (LCF_CommonParamData.P_DPRSMI_BlockingTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_BlockingTimeDuration_sec() (P_DPRSMI_BlockingTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_BlockingTimeDuration_sec

#ifndef P_DPRSMI_CancelDrvSt_btm
#define P_DPRSMI_CancelDrvSt_btm (LCF_CommonParamData.P_DPRSMI_CancelDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelDrvSt_btm() (P_DPRSMI_CancelDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelDrvSt_btm

#ifndef P_DPRSMI_CancelFctCustom_btm
#define P_DPRSMI_CancelFctCustom_btm (LCF_CommonParamData.P_DPRSMI_CancelFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelFctCustom_btm() (P_DPRSMI_CancelFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelFctCustom_btm

#ifndef P_DPRSMI_CancelFctStCtr_btm
#define P_DPRSMI_CancelFctStCtr_btm (LCF_CommonParamData.P_DPRSMI_CancelFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelFctStCtr_btm() (P_DPRSMI_CancelFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelFctStCtr_btm

#ifndef P_DPRSMI_CancelFctStErr_btm
#define P_DPRSMI_CancelFctStErr_btm (LCF_CommonParamData.P_DPRSMI_CancelFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelFctStErr_btm() (P_DPRSMI_CancelFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelFctStErr_btm

#ifndef P_DPRSMI_CancelFctStNotAv_btm
#define P_DPRSMI_CancelFctStNotAv_btm (LCF_CommonParamData.P_DPRSMI_CancelFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelFctStNotAv_btm() (P_DPRSMI_CancelFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelFctStNotAv_btm

#ifndef P_DPRSMI_CancelSpecific_btm
#define P_DPRSMI_CancelSpecific_btm (LCF_CommonParamData.P_DPRSMI_CancelSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelSpecific_btm() (P_DPRSMI_CancelSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelSpecific_btm

#ifndef P_DPRSMI_CancelVehSt_btm
#define P_DPRSMI_CancelVehSt_btm (LCF_CommonParamData.P_DPRSMI_CancelVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CancelVehSt_btm() (P_DPRSMI_CancelVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CancelVehSt_btm

#ifndef P_DPRSMI_CurveDetectThreshold_1pm
#define P_DPRSMI_CurveDetectThreshold_1pm (LCF_CommonParamData.P_DPRSMI_CurveDetectThreshold_1pm) //!< LCF parameter macro.
#define GET_P_DPRSMI_CurveDetectThreshold_1pm() (P_DPRSMI_CurveDetectThreshold_1pm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_CurveDetectThreshold_1pm

#ifndef P_DPRSMI_DebugDrvSt_btm
#define P_DPRSMI_DebugDrvSt_btm (LCF_CommonParamData.P_DPRSMI_DebugDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_DebugDrvSt_btm() (P_DPRSMI_DebugDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DebugDrvSt_btm

#ifndef P_DPRSMI_DebugSpecific_btm
#define P_DPRSMI_DebugSpecific_btm (LCF_CommonParamData.P_DPRSMI_DebugSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_DebugSpecific_btm() (P_DPRSMI_DebugSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DebugSpecific_btm

#ifndef P_DPRSMI_DegrTimeOut_sec
#define P_DPRSMI_DegrTimeOut_sec (LCF_CommonParamData.P_DPRSMI_DegrTimeOut_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_DegrTimeOut_sec() (P_DPRSMI_DegrTimeOut_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DegrTimeOut_sec

#ifndef P_DPRSMI_DlcLimitMax_met
#define P_DPRSMI_DlcLimitMax_met (LCF_CommonParamData.P_DPRSMI_DlcLimitMax_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_DlcLimitMax_met() (P_DPRSMI_DlcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DlcLimitMax_met

#ifndef P_DPRSMI_DlcLimitMin_met
#define P_DPRSMI_DlcLimitMin_met (LCF_CommonParamData.P_DPRSMI_DlcLimitMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_DlcLimitMin_met() (P_DPRSMI_DlcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DlcLimitMin_met

#ifndef P_DPRSMI_DrcLimitMax_met
#define P_DPRSMI_DrcLimitMax_met (LCF_CommonParamData.P_DPRSMI_DrcLimitMax_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_DrcLimitMax_met() (P_DPRSMI_DrcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DrcLimitMax_met

#ifndef P_DPRSMI_DrcLimitMin_met
#define P_DPRSMI_DrcLimitMin_met (LCF_CommonParamData.P_DPRSMI_DrcLimitMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_DrcLimitMin_met() (P_DPRSMI_DrcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_DrcLimitMin_met

#ifndef P_DPRSMI_ErrorStateRDPEnable_bool
#define P_DPRSMI_ErrorStateRDPEnable_bool (LCF_CommonParamData.P_DPRSMI_ErrorStateRDPEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_ErrorStateRDPEnable_bool() (P_DPRSMI_ErrorStateRDPEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_ErrorStateRDPEnable_bool

#ifndef P_DPRSMI_ErrorStateRDP_bool
#define P_DPRSMI_ErrorStateRDP_bool (LCF_CommonParamData.P_DPRSMI_ErrorStateRDP_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_ErrorStateRDP_bool() (P_DPRSMI_ErrorStateRDP_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_ErrorStateRDP_bool

#ifndef P_DPRSMI_FctCustomCancelLe_btm
#define P_DPRSMI_FctCustomCancelLe_btm (LCF_CommonParamData.P_DPRSMI_FctCustomCancelLe_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_FctCustomCancelLe_btm() (P_DPRSMI_FctCustomCancelLe_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_FctCustomCancelLe_btm

#ifndef P_DPRSMI_FctCustomCancelRi_btm
#define P_DPRSMI_FctCustomCancelRi_btm (LCF_CommonParamData.P_DPRSMI_FctCustomCancelRi_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_FctCustomCancelRi_btm() (P_DPRSMI_FctCustomCancelRi_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_FctCustomCancelRi_btm

#ifndef P_DPRSMI_FctCustomTrgLe_btm
#define P_DPRSMI_FctCustomTrgLe_btm (LCF_CommonParamData.P_DPRSMI_FctCustomTrgLe_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_FctCustomTrgLe_btm() (P_DPRSMI_FctCustomTrgLe_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_FctCustomTrgLe_btm

#ifndef P_DPRSMI_FctCustomTrgRi_btm
#define P_DPRSMI_FctCustomTrgRi_btm (LCF_CommonParamData.P_DPRSMI_FctCustomTrgRi_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_FctCustomTrgRi_btm() (P_DPRSMI_FctCustomTrgRi_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_FctCustomTrgRi_btm

#ifndef P_DPRSMI_FinishCondEnable_btm
#define P_DPRSMI_FinishCondEnable_btm (LCF_CommonParamData.P_DPRSMI_FinishCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_FinishCondEnable_btm() (P_DPRSMI_FinishCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_FinishCondEnable_btm

#ifndef P_DPRSMI_HazardCancelTol_met
#define P_DPRSMI_HazardCancelTol_met (LCF_CommonParamData.P_DPRSMI_HazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_HazardCancelTol_met() (P_DPRSMI_HazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_HazardCancelTol_met

#ifndef P_DPRSMI_HazardFinishDlc_met
#define P_DPRSMI_HazardFinishDlc_met (LCF_CommonParamData.P_DPRSMI_HazardFinishDlc_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_HazardFinishDlc_met() (P_DPRSMI_HazardFinishDlc_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_HazardFinishDlc_met

#ifndef P_DPRSMI_HazardFinishHeadAng_rad
#define P_DPRSMI_HazardFinishHeadAng_rad (LCF_CommonParamData.P_DPRSMI_HazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPRSMI_HazardFinishHeadAng_rad() (P_DPRSMI_HazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPRSMI_HazardFinishHeadAng_rad

#ifndef P_DPRSMI_HazardFinishVelLat_mps
#define P_DPRSMI_HazardFinishVelLat_mps (LCF_CommonParamData.P_DPRSMI_HazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPRSMI_HazardFinishVelLat_mps() (P_DPRSMI_HazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPRSMI_HazardFinishVelLat_mps

#ifndef P_DPRSMI_LatDMCClearEnable_bool
#define P_DPRSMI_LatDMCClearEnable_bool (LCF_CommonParamData.P_DPRSMI_LatDMCClearEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_LatDMCClearEnable_bool() (P_DPRSMI_LatDMCClearEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LatDMCClearEnable_bool

#ifndef P_DPRSMI_LnMrkRdEdgeDistMax_met
#define P_DPRSMI_LnMrkRdEdgeDistMax_met (LCF_CommonParamData.P_DPRSMI_LnMrkRdEdgeDistMax_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_LnMrkRdEdgeDistMax_met() (P_DPRSMI_LnMrkRdEdgeDistMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LnMrkRdEdgeDistMax_met

#ifndef P_DPRSMI_LnMrkRdEdgeDistMin_met
#define P_DPRSMI_LnMrkRdEdgeDistMin_met (LCF_CommonParamData.P_DPRSMI_LnMrkRdEdgeDistMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_LnMrkRdEdgeDistMin_met() (P_DPRSMI_LnMrkRdEdgeDistMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LnMrkRdEdgeDistMin_met

#ifndef P_DPRSMI_LnOverlapCrv_1pm
#define P_DPRSMI_LnOverlapCrv_1pm (LCF_CommonParamData.P_DPRSMI_LnOverlapCrv_1pm) //!< LCF parameter macro.
#define GET_P_DPRSMI_LnOverlapCrv_1pm() (P_DPRSMI_LnOverlapCrv_1pm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LnOverlapCrv_1pm

#ifndef P_DPRSMI_LnOverlapEnable_bool
#define P_DPRSMI_LnOverlapEnable_bool (LCF_CommonParamData.P_DPRSMI_LnOverlapEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_LnOverlapEnable_bool() (P_DPRSMI_LnOverlapEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LnOverlapEnable_bool

#ifndef P_DPRSMI_LnOverlapInnerDist_met
#define P_DPRSMI_LnOverlapInnerDist_met (LCF_CommonParamData.P_DPRSMI_LnOverlapInnerDist_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_LnOverlapInnerDist_met() (P_DPRSMI_LnOverlapInnerDist_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LnOverlapInnerDist_met

#ifndef P_DPRSMI_LnOverlapOuterDist_met
#define P_DPRSMI_LnOverlapOuterDist_met (LCF_CommonParamData.P_DPRSMI_LnOverlapOuterDist_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_LnOverlapOuterDist_met() (P_DPRSMI_LnOverlapOuterDist_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_LnOverlapOuterDist_met

#ifndef P_DPRSMI_NoHazardCancelDlc_met
#define P_DPRSMI_NoHazardCancelDlc_met (LCF_CommonParamData.P_DPRSMI_NoHazardCancelDlc_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_NoHazardCancelDlc_met() (P_DPRSMI_NoHazardCancelDlc_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_NoHazardCancelDlc_met

#ifndef P_DPRSMI_NoHazardCancelTol_met
#define P_DPRSMI_NoHazardCancelTol_met (LCF_CommonParamData.P_DPRSMI_NoHazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_NoHazardCancelTol_met() (P_DPRSMI_NoHazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_NoHazardCancelTol_met

#ifndef P_DPRSMI_NoHazardFinishDlc_met
#define P_DPRSMI_NoHazardFinishDlc_met (LCF_CommonParamData.P_DPRSMI_NoHazardFinishDlc_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_NoHazardFinishDlc_met() (P_DPRSMI_NoHazardFinishDlc_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_NoHazardFinishDlc_met

#ifndef P_DPRSMI_NoHazardFinishHeadAng_rad
#define P_DPRSMI_NoHazardFinishHeadAng_rad (LCF_CommonParamData.P_DPRSMI_NoHazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPRSMI_NoHazardFinishHeadAng_rad() (P_DPRSMI_NoHazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPRSMI_NoHazardFinishHeadAng_rad

#ifndef P_DPRSMI_NoHazardFinishVelLat_mps
#define P_DPRSMI_NoHazardFinishVelLat_mps (LCF_CommonParamData.P_DPRSMI_NoHazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPRSMI_NoHazardFinishVelLat_mps() (P_DPRSMI_NoHazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPRSMI_NoHazardFinishVelLat_mps

#ifndef P_DPRSMI_OnTargetFinishTime_sec
#define P_DPRSMI_OnTargetFinishTime_sec (LCF_CommonParamData.P_DPRSMI_OnTargetFinishTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_OnTargetFinishTime_sec() (P_DPRSMI_OnTargetFinishTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_OnTargetFinishTime_sec

#ifndef P_DPRSMI_QuTrajCtrCancel_btm
#define P_DPRSMI_QuTrajCtrCancel_btm (LCF_CommonParamData.P_DPRSMI_QuTrajCtrCancel_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_QuTrajCtrCancel_btm() (P_DPRSMI_QuTrajCtrCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_QuTrajCtrCancel_btm

#ifndef P_DPRSMI_QuTrajCtrClearance_btm
#define P_DPRSMI_QuTrajCtrClearance_btm (LCF_CommonParamData.P_DPRSMI_QuTrajCtrClearance_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_QuTrajCtrClearance_btm() (P_DPRSMI_QuTrajCtrClearance_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_QuTrajCtrClearance_btm

#ifndef P_DPRSMI_QuTrajPlanCancel_btm
#define P_DPRSMI_QuTrajPlanCancel_btm (LCF_CommonParamData.P_DPRSMI_QuTrajPlanCancel_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_QuTrajPlanCancel_btm() (P_DPRSMI_QuTrajPlanCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_QuTrajPlanCancel_btm

#ifndef P_DPRSMI_QuTrajPlanClearance_btm
#define P_DPRSMI_QuTrajPlanClearance_btm (LCF_CommonParamData.P_DPRSMI_QuTrajPlanClearance_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_QuTrajPlanClearance_btm() (P_DPRSMI_QuTrajPlanClearance_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_QuTrajPlanClearance_btm

#ifndef P_DPRSMI_RDPSwitchEnable_bool
#define P_DPRSMI_RDPSwitchEnable_bool (LCF_CommonParamData.P_DPRSMI_RDPSwitchEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_RDPSwitchEnable_bool() (P_DPRSMI_RDPSwitchEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_RDPSwitchEnable_bool

#ifndef P_DPRSMI_RDPSwitch_bool
#define P_DPRSMI_RDPSwitch_bool (LCF_CommonParamData.P_DPRSMI_RDPSwitch_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_RDPSwitch_bool() (P_DPRSMI_RDPSwitch_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_RDPSwitch_bool

#ifndef P_DPRSMI_RequestTimeOut_sec
#define P_DPRSMI_RequestTimeOut_sec (LCF_CommonParamData.P_DPRSMI_RequestTimeOut_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_RequestTimeOut_sec() (P_DPRSMI_RequestTimeOut_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_RequestTimeOut_sec

#ifndef P_DPRSMI_SafeSitDelayLn_sec
#define P_DPRSMI_SafeSitDelayLn_sec (LCF_CommonParamData.P_DPRSMI_SafeSitDelayLn_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_SafeSitDelayLn_sec() (P_DPRSMI_SafeSitDelayLn_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SafeSitDelayLn_sec

#ifndef P_DPRSMI_SafeSitDelayRe_sec
#define P_DPRSMI_SafeSitDelayRe_sec (LCF_CommonParamData.P_DPRSMI_SafeSitDelayRe_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_SafeSitDelayRe_sec() (P_DPRSMI_SafeSitDelayRe_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SafeSitDelayRe_sec

#ifndef P_DPRSMI_SafeSitOffsetLn_met
#define P_DPRSMI_SafeSitOffsetLn_met (LCF_CommonParamData.P_DPRSMI_SafeSitOffsetLn_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_SafeSitOffsetLn_met() (P_DPRSMI_SafeSitOffsetLn_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SafeSitOffsetLn_met

#ifndef P_DPRSMI_SafeSitOffsetRe_met
#define P_DPRSMI_SafeSitOffsetRe_met (LCF_CommonParamData.P_DPRSMI_SafeSitOffsetRe_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_SafeSitOffsetRe_met() (P_DPRSMI_SafeSitOffsetRe_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SafeSitOffsetRe_met

#ifndef P_DPRSMI_SafeSitStateLn_btm
#define P_DPRSMI_SafeSitStateLn_btm (LCF_CommonParamData.P_DPRSMI_SafeSitStateLn_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SafeSitStateLn_btm() (P_DPRSMI_SafeSitStateLn_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SafeSitStateLn_btm

#ifndef P_DPRSMI_SafeSitStateRe_btm
#define P_DPRSMI_SafeSitStateRe_btm (LCF_CommonParamData.P_DPRSMI_SafeSitStateRe_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SafeSitStateRe_btm() (P_DPRSMI_SafeSitStateRe_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SafeSitStateRe_btm

#ifndef P_DPRSMI_SideCondCancel_btm
#define P_DPRSMI_SideCondCancel_btm (LCF_CommonParamData.P_DPRSMI_SideCondCancel_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SideCondCancel_btm() (P_DPRSMI_SideCondCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SideCondCancel_btm

#ifndef P_DPRSMI_SideCondDebug_btm
#define P_DPRSMI_SideCondDebug_btm (LCF_CommonParamData.P_DPRSMI_SideCondDebug_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SideCondDebug_btm() (P_DPRSMI_SideCondDebug_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SideCondDebug_btm

#ifndef P_DPRSMI_SideCondEnable_btm
#define P_DPRSMI_SideCondEnable_btm (LCF_CommonParamData.P_DPRSMI_SideCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SideCondEnable_btm() (P_DPRSMI_SideCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SideCondEnable_btm

#ifndef P_DPRSMI_StrgRdyDrvSt_btm
#define P_DPRSMI_StrgRdyDrvSt_btm (LCF_CommonParamData.P_DPRSMI_StrgRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdyDrvSt_btm() (P_DPRSMI_StrgRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdyDrvSt_btm

#ifndef P_DPRSMI_StrgRdyFctCustom_btm
#define P_DPRSMI_StrgRdyFctCustom_btm (LCF_CommonParamData.P_DPRSMI_StrgRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdyFctCustom_btm() (P_DPRSMI_StrgRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdyFctCustom_btm

#ifndef P_DPRSMI_StrgRdyFctStCtr_btm
#define P_DPRSMI_StrgRdyFctStCtr_btm (LCF_CommonParamData.P_DPRSMI_StrgRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdyFctStCtr_btm() (P_DPRSMI_StrgRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdyFctStCtr_btm

#ifndef P_DPRSMI_StrgRdyFctStErr_btm
#define P_DPRSMI_StrgRdyFctStErr_btm (LCF_CommonParamData.P_DPRSMI_StrgRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdyFctStErr_btm() (P_DPRSMI_StrgRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdyFctStErr_btm

#ifndef P_DPRSMI_StrgRdyFctStNotAv_btm
#define P_DPRSMI_StrgRdyFctStNotAv_btm (LCF_CommonParamData.P_DPRSMI_StrgRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdyFctStNotAv_btm() (P_DPRSMI_StrgRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdyFctStNotAv_btm

#ifndef P_DPRSMI_StrgRdySpecific_btm
#define P_DPRSMI_StrgRdySpecific_btm (LCF_CommonParamData.P_DPRSMI_StrgRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdySpecific_btm() (P_DPRSMI_StrgRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdySpecific_btm

#ifndef P_DPRSMI_StrgRdyVehSt_btm
#define P_DPRSMI_StrgRdyVehSt_btm (LCF_CommonParamData.P_DPRSMI_StrgRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_StrgRdyVehSt_btm() (P_DPRSMI_StrgRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_StrgRdyVehSt_btm

#ifndef P_DPRSMI_SuppressDrvSt_btm
#define P_DPRSMI_SuppressDrvSt_btm (LCF_CommonParamData.P_DPRSMI_SuppressDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressDrvSt_btm() (P_DPRSMI_SuppressDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressDrvSt_btm

#ifndef P_DPRSMI_SuppressFctCustom_btm
#define P_DPRSMI_SuppressFctCustom_btm (LCF_CommonParamData.P_DPRSMI_SuppressFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressFctCustom_btm() (P_DPRSMI_SuppressFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressFctCustom_btm

#ifndef P_DPRSMI_SuppressFctStCtr_btm
#define P_DPRSMI_SuppressFctStCtr_btm (LCF_CommonParamData.P_DPRSMI_SuppressFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressFctStCtr_btm() (P_DPRSMI_SuppressFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressFctStCtr_btm

#ifndef P_DPRSMI_SuppressFctStErr_btm
#define P_DPRSMI_SuppressFctStErr_btm (LCF_CommonParamData.P_DPRSMI_SuppressFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressFctStErr_btm() (P_DPRSMI_SuppressFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressFctStErr_btm

#ifndef P_DPRSMI_SuppressFctStNotAv_btm
#define P_DPRSMI_SuppressFctStNotAv_btm (LCF_CommonParamData.P_DPRSMI_SuppressFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressFctStNotAv_btm() (P_DPRSMI_SuppressFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressFctStNotAv_btm

#ifndef P_DPRSMI_SuppressSpecific_btm
#define P_DPRSMI_SuppressSpecific_btm (LCF_CommonParamData.P_DPRSMI_SuppressSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressSpecific_btm() (P_DPRSMI_SuppressSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressSpecific_btm

#ifndef P_DPRSMI_SuppressVehSt_btm
#define P_DPRSMI_SuppressVehSt_btm (LCF_CommonParamData.P_DPRSMI_SuppressVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_SuppressVehSt_btm() (P_DPRSMI_SuppressVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_SuppressVehSt_btm

#ifndef P_DPRSMI_TlcDistanceMin_met
#define P_DPRSMI_TlcDistanceMin_met (LCF_CommonParamData.P_DPRSMI_TlcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_TlcDistanceMin_met() (P_DPRSMI_TlcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_TlcDistanceMin_met

#ifndef P_DPRSMI_TlcValidMinTime_sec
#define P_DPRSMI_TlcValidMinTime_sec (LCF_CommonParamData.P_DPRSMI_TlcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_TlcValidMinTime_sec() (P_DPRSMI_TlcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_TlcValidMinTime_sec

#ifndef P_DPRSMI_TrcDistanceMin_met
#define P_DPRSMI_TrcDistanceMin_met (LCF_CommonParamData.P_DPRSMI_TrcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMI_TrcDistanceMin_met() (P_DPRSMI_TrcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMI_TrcDistanceMin_met

#ifndef P_DPRSMI_TrcValidMinTime_sec
#define P_DPRSMI_TrcValidMinTime_sec (LCF_CommonParamData.P_DPRSMI_TrcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_TrcValidMinTime_sec() (P_DPRSMI_TrcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_TrcValidMinTime_sec

#ifndef P_DPRSMI_TrgIgnoreLnContg_bool
#define P_DPRSMI_TrgIgnoreLnContg_bool (LCF_CommonParamData.P_DPRSMI_TrgIgnoreLnContg_bool) //!< LCF parameter macro.
#define GET_P_DPRSMI_TrgIgnoreLnContg_bool() (P_DPRSMI_TrgIgnoreLnContg_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMI_TrgIgnoreLnContg_bool

#ifndef P_DPRSMI_TriggerHoldingTime_sec
#define P_DPRSMI_TriggerHoldingTime_sec (LCF_CommonParamData.P_DPRSMI_TriggerHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMI_TriggerHoldingTime_sec() (P_DPRSMI_TriggerHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMI_TriggerHoldingTime_sec

#ifndef P_DPRSMI_WeakRdyDrvSt_btm
#define P_DPRSMI_WeakRdyDrvSt_btm (LCF_CommonParamData.P_DPRSMI_WeakRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdyDrvSt_btm() (P_DPRSMI_WeakRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdyDrvSt_btm

#ifndef P_DPRSMI_WeakRdyFctCustom_btm
#define P_DPRSMI_WeakRdyFctCustom_btm (LCF_CommonParamData.P_DPRSMI_WeakRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdyFctCustom_btm() (P_DPRSMI_WeakRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdyFctCustom_btm

#ifndef P_DPRSMI_WeakRdyFctStCtr_btm
#define P_DPRSMI_WeakRdyFctStCtr_btm (LCF_CommonParamData.P_DPRSMI_WeakRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdyFctStCtr_btm() (P_DPRSMI_WeakRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdyFctStCtr_btm

#ifndef P_DPRSMI_WeakRdyFctStErr_btm
#define P_DPRSMI_WeakRdyFctStErr_btm (LCF_CommonParamData.P_DPRSMI_WeakRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdyFctStErr_btm() (P_DPRSMI_WeakRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdyFctStErr_btm

#ifndef P_DPRSMI_WeakRdyFctStNotAv_btm
#define P_DPRSMI_WeakRdyFctStNotAv_btm (LCF_CommonParamData.P_DPRSMI_WeakRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdyFctStNotAv_btm() (P_DPRSMI_WeakRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdyFctStNotAv_btm

#ifndef P_DPRSMI_WeakRdySpecific_btm
#define P_DPRSMI_WeakRdySpecific_btm (LCF_CommonParamData.P_DPRSMI_WeakRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdySpecific_btm() (P_DPRSMI_WeakRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdySpecific_btm

#ifndef P_DPRSMI_WeakRdyVehSt_btm
#define P_DPRSMI_WeakRdyVehSt_btm (LCF_CommonParamData.P_DPRSMI_WeakRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMI_WeakRdyVehSt_btm() (P_DPRSMI_WeakRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMI_WeakRdyVehSt_btm

#ifndef P_DPRSMW_AbortDegrDuration_sec
#define P_DPRSMW_AbortDegrDuration_sec (LCF_CommonParamData.P_DPRSMW_AbortDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortDegrDuration_sec() (P_DPRSMW_AbortDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortDegrDuration_sec

#ifndef P_DPRSMW_AbortDrvSt_btm
#define P_DPRSMW_AbortDrvSt_btm (LCF_CommonParamData.P_DPRSMW_AbortDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortDrvSt_btm() (P_DPRSMW_AbortDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortDrvSt_btm

#ifndef P_DPRSMW_AbortFctCustom_btm
#define P_DPRSMW_AbortFctCustom_btm (LCF_CommonParamData.P_DPRSMW_AbortFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortFctCustom_btm() (P_DPRSMW_AbortFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortFctCustom_btm

#ifndef P_DPRSMW_AbortFctStCtr_btm
#define P_DPRSMW_AbortFctStCtr_btm (LCF_CommonParamData.P_DPRSMW_AbortFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortFctStCtr_btm() (P_DPRSMW_AbortFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortFctStCtr_btm

#ifndef P_DPRSMW_AbortFctStErr_btm
#define P_DPRSMW_AbortFctStErr_btm (LCF_CommonParamData.P_DPRSMW_AbortFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortFctStErr_btm() (P_DPRSMW_AbortFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortFctStErr_btm

#ifndef P_DPRSMW_AbortFctStNotAv_btm
#define P_DPRSMW_AbortFctStNotAv_btm (LCF_CommonParamData.P_DPRSMW_AbortFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortFctStNotAv_btm() (P_DPRSMW_AbortFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortFctStNotAv_btm

#ifndef P_DPRSMW_AbortSpecific_btm
#define P_DPRSMW_AbortSpecific_btm (LCF_CommonParamData.P_DPRSMW_AbortSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortSpecific_btm() (P_DPRSMW_AbortSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortSpecific_btm

#ifndef P_DPRSMW_AbortVehSt_btm
#define P_DPRSMW_AbortVehSt_btm (LCF_CommonParamData.P_DPRSMW_AbortVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_AbortVehSt_btm() (P_DPRSMW_AbortVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_AbortVehSt_btm

#ifndef P_DPRSMW_BlockingTimeDuration_sec
#define P_DPRSMW_BlockingTimeDuration_sec (LCF_CommonParamData.P_DPRSMW_BlockingTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_BlockingTimeDuration_sec() (P_DPRSMW_BlockingTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_BlockingTimeDuration_sec

#ifndef P_DPRSMW_CancelDegrDuration_sec
#define P_DPRSMW_CancelDegrDuration_sec (LCF_CommonParamData.P_DPRSMW_CancelDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelDegrDuration_sec() (P_DPRSMW_CancelDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelDegrDuration_sec

#ifndef P_DPRSMW_CancelDrvSt_btm
#define P_DPRSMW_CancelDrvSt_btm (LCF_CommonParamData.P_DPRSMW_CancelDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelDrvSt_btm() (P_DPRSMW_CancelDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelDrvSt_btm

#ifndef P_DPRSMW_CancelFctCustom_btm
#define P_DPRSMW_CancelFctCustom_btm (LCF_CommonParamData.P_DPRSMW_CancelFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelFctCustom_btm() (P_DPRSMW_CancelFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelFctCustom_btm

#ifndef P_DPRSMW_CancelFctStCtr_btm
#define P_DPRSMW_CancelFctStCtr_btm (LCF_CommonParamData.P_DPRSMW_CancelFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelFctStCtr_btm() (P_DPRSMW_CancelFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelFctStCtr_btm

#ifndef P_DPRSMW_CancelFctStErr_btm
#define P_DPRSMW_CancelFctStErr_btm (LCF_CommonParamData.P_DPRSMW_CancelFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelFctStErr_btm() (P_DPRSMW_CancelFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelFctStErr_btm

#ifndef P_DPRSMW_CancelFctStNotAv_btm
#define P_DPRSMW_CancelFctStNotAv_btm (LCF_CommonParamData.P_DPRSMW_CancelFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelFctStNotAv_btm() (P_DPRSMW_CancelFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelFctStNotAv_btm

#ifndef P_DPRSMW_CancelSpecific_btm
#define P_DPRSMW_CancelSpecific_btm (LCF_CommonParamData.P_DPRSMW_CancelSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelSpecific_btm() (P_DPRSMW_CancelSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelSpecific_btm

#ifndef P_DPRSMW_CancelVehSt_btm
#define P_DPRSMW_CancelVehSt_btm (LCF_CommonParamData.P_DPRSMW_CancelVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_CancelVehSt_btm() (P_DPRSMW_CancelVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_CancelVehSt_btm

#ifndef P_DPRSMW_DebugDrvSt_btm
#define P_DPRSMW_DebugDrvSt_btm (LCF_CommonParamData.P_DPRSMW_DebugDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_DebugDrvSt_btm() (P_DPRSMW_DebugDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_DebugDrvSt_btm

#ifndef P_DPRSMW_DebugSpecific_btm
#define P_DPRSMW_DebugSpecific_btm (LCF_CommonParamData.P_DPRSMW_DebugSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_DebugSpecific_btm() (P_DPRSMW_DebugSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_DebugSpecific_btm

#ifndef P_DPRSMW_DlcLimitMax_met
#define P_DPRSMW_DlcLimitMax_met (LCF_CommonParamData.P_DPRSMW_DlcLimitMax_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_DlcLimitMax_met() (P_DPRSMW_DlcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_DlcLimitMax_met

#ifndef P_DPRSMW_DlcLimitMin_met
#define P_DPRSMW_DlcLimitMin_met (LCF_CommonParamData.P_DPRSMW_DlcLimitMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_DlcLimitMin_met() (P_DPRSMW_DlcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_DlcLimitMin_met

#ifndef P_DPRSMW_DrcLimitMax_met
#define P_DPRSMW_DrcLimitMax_met (LCF_CommonParamData.P_DPRSMW_DrcLimitMax_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_DrcLimitMax_met() (P_DPRSMW_DrcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_DrcLimitMax_met

#ifndef P_DPRSMW_DrcLimitMin_met
#define P_DPRSMW_DrcLimitMin_met (LCF_CommonParamData.P_DPRSMW_DrcLimitMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_DrcLimitMin_met() (P_DPRSMW_DrcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_DrcLimitMin_met

#ifndef P_DPRSMW_ErrorStateRDWEnable_bool
#define P_DPRSMW_ErrorStateRDWEnable_bool (LCF_CommonParamData.P_DPRSMW_ErrorStateRDWEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_ErrorStateRDWEnable_bool() (P_DPRSMW_ErrorStateRDWEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_ErrorStateRDWEnable_bool

#ifndef P_DPRSMW_ErrorStateRDW_bool
#define P_DPRSMW_ErrorStateRDW_bool (LCF_CommonParamData.P_DPRSMW_ErrorStateRDW_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_ErrorStateRDW_bool() (P_DPRSMW_ErrorStateRDW_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_ErrorStateRDW_bool

#ifndef P_DPRSMW_FctCustomCancelLe_btm
#define P_DPRSMW_FctCustomCancelLe_btm (LCF_CommonParamData.P_DPRSMW_FctCustomCancelLe_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_FctCustomCancelLe_btm() (P_DPRSMW_FctCustomCancelLe_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FctCustomCancelLe_btm

#ifndef P_DPRSMW_FctCustomCancelRi_btm
#define P_DPRSMW_FctCustomCancelRi_btm (LCF_CommonParamData.P_DPRSMW_FctCustomCancelRi_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_FctCustomCancelRi_btm() (P_DPRSMW_FctCustomCancelRi_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FctCustomCancelRi_btm

#ifndef P_DPRSMW_FctCustomTrgLe_btm
#define P_DPRSMW_FctCustomTrgLe_btm (LCF_CommonParamData.P_DPRSMW_FctCustomTrgLe_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_FctCustomTrgLe_btm() (P_DPRSMW_FctCustomTrgLe_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FctCustomTrgLe_btm

#ifndef P_DPRSMW_FctCustomTrgRi_btm
#define P_DPRSMW_FctCustomTrgRi_btm (LCF_CommonParamData.P_DPRSMW_FctCustomTrgRi_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_FctCustomTrgRi_btm() (P_DPRSMW_FctCustomTrgRi_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FctCustomTrgRi_btm

#ifndef P_DPRSMW_FinishCondEnable_btm
#define P_DPRSMW_FinishCondEnable_btm (LCF_CommonParamData.P_DPRSMW_FinishCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_FinishCondEnable_btm() (P_DPRSMW_FinishCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FinishCondEnable_btm

#ifndef P_DPRSMW_FinishDegrDuration_sec
#define P_DPRSMW_FinishDegrDuration_sec (LCF_CommonParamData.P_DPRSMW_FinishDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_FinishDegrDuration_sec() (P_DPRSMW_FinishDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FinishDegrDuration_sec

#ifndef P_DPRSMW_FinishMinDuration_sec
#define P_DPRSMW_FinishMinDuration_sec (LCF_CommonParamData.P_DPRSMW_FinishMinDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_FinishMinDuration_sec() (P_DPRSMW_FinishMinDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_FinishMinDuration_sec

#ifndef P_DPRSMW_HazardCancelTol_met
#define P_DPRSMW_HazardCancelTol_met (LCF_CommonParamData.P_DPRSMW_HazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_HazardCancelTol_met() (P_DPRSMW_HazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_HazardCancelTol_met

#ifndef P_DPRSMW_HazardFinishHeadAng_rad
#define P_DPRSMW_HazardFinishHeadAng_rad (LCF_CommonParamData.P_DPRSMW_HazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPRSMW_HazardFinishHeadAng_rad() (P_DPRSMW_HazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPRSMW_HazardFinishHeadAng_rad

#ifndef P_DPRSMW_HazardFinishVelLat_mps
#define P_DPRSMW_HazardFinishVelLat_mps (LCF_CommonParamData.P_DPRSMW_HazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPRSMW_HazardFinishVelLat_mps() (P_DPRSMW_HazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPRSMW_HazardFinishVelLat_mps

#ifndef P_DPRSMW_LnMrkRdEdgeDistMax_met
#define P_DPRSMW_LnMrkRdEdgeDistMax_met (LCF_CommonParamData.P_DPRSMW_LnMrkRdEdgeDistMax_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_LnMrkRdEdgeDistMax_met() (P_DPRSMW_LnMrkRdEdgeDistMax_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_LnMrkRdEdgeDistMax_met

#ifndef P_DPRSMW_LnMrkRdEdgeDistMin_met
#define P_DPRSMW_LnMrkRdEdgeDistMin_met (LCF_CommonParamData.P_DPRSMW_LnMrkRdEdgeDistMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_LnMrkRdEdgeDistMin_met() (P_DPRSMW_LnMrkRdEdgeDistMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_LnMrkRdEdgeDistMin_met

#ifndef P_DPRSMW_LnOverlapCrv_1pm
#define P_DPRSMW_LnOverlapCrv_1pm (LCF_CommonParamData.P_DPRSMW_LnOverlapCrv_1pm) //!< LCF parameter macro.
#define GET_P_DPRSMW_LnOverlapCrv_1pm() (P_DPRSMW_LnOverlapCrv_1pm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_LnOverlapCrv_1pm

#ifndef P_DPRSMW_LnOverlapEnable_bool
#define P_DPRSMW_LnOverlapEnable_bool (LCF_CommonParamData.P_DPRSMW_LnOverlapEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_LnOverlapEnable_bool() (P_DPRSMW_LnOverlapEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_LnOverlapEnable_bool

#ifndef P_DPRSMW_LnOverlapInnerDist_met
#define P_DPRSMW_LnOverlapInnerDist_met (LCF_CommonParamData.P_DPRSMW_LnOverlapInnerDist_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_LnOverlapInnerDist_met() (P_DPRSMW_LnOverlapInnerDist_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_LnOverlapInnerDist_met

#ifndef P_DPRSMW_LnOverlapOuterDist_met
#define P_DPRSMW_LnOverlapOuterDist_met (LCF_CommonParamData.P_DPRSMW_LnOverlapOuterDist_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_LnOverlapOuterDist_met() (P_DPRSMW_LnOverlapOuterDist_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_LnOverlapOuterDist_met

#ifndef P_DPRSMW_NoHazardCancelTol_met
#define P_DPRSMW_NoHazardCancelTol_met (LCF_CommonParamData.P_DPRSMW_NoHazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_NoHazardCancelTol_met() (P_DPRSMW_NoHazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_NoHazardCancelTol_met

#ifndef P_DPRSMW_NoHazardFinishHeadAng_rad
#define P_DPRSMW_NoHazardFinishHeadAng_rad (LCF_CommonParamData.P_DPRSMW_NoHazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_DPRSMW_NoHazardFinishHeadAng_rad() (P_DPRSMW_NoHazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_DPRSMW_NoHazardFinishHeadAng_rad

#ifndef P_DPRSMW_NoHazardFinishVelLat_mps
#define P_DPRSMW_NoHazardFinishVelLat_mps (LCF_CommonParamData.P_DPRSMW_NoHazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_DPRSMW_NoHazardFinishVelLat_mps() (P_DPRSMW_NoHazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_DPRSMW_NoHazardFinishVelLat_mps

#ifndef P_DPRSMW_OnTargetFinishTime_sec
#define P_DPRSMW_OnTargetFinishTime_sec (LCF_CommonParamData.P_DPRSMW_OnTargetFinishTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_OnTargetFinishTime_sec() (P_DPRSMW_OnTargetFinishTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_OnTargetFinishTime_sec

#ifndef P_DPRSMW_RDWSwitchEnable_bool
#define P_DPRSMW_RDWSwitchEnable_bool (LCF_CommonParamData.P_DPRSMW_RDWSwitchEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_RDWSwitchEnable_bool() (P_DPRSMW_RDWSwitchEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_RDWSwitchEnable_bool

#ifndef P_DPRSMW_RDWSwitch_bool
#define P_DPRSMW_RDWSwitch_bool (LCF_CommonParamData.P_DPRSMW_RDWSwitch_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_RDWSwitch_bool() (P_DPRSMW_RDWSwitch_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_RDWSwitch_bool

#ifndef P_DPRSMW_SafeSitDelayLn_sec
#define P_DPRSMW_SafeSitDelayLn_sec (LCF_CommonParamData.P_DPRSMW_SafeSitDelayLn_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_SafeSitDelayLn_sec() (P_DPRSMW_SafeSitDelayLn_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SafeSitDelayLn_sec

#ifndef P_DPRSMW_SafeSitDelayRe_sec
#define P_DPRSMW_SafeSitDelayRe_sec (LCF_CommonParamData.P_DPRSMW_SafeSitDelayRe_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_SafeSitDelayRe_sec() (P_DPRSMW_SafeSitDelayRe_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SafeSitDelayRe_sec

#ifndef P_DPRSMW_SafeSitOffsetLn_met
#define P_DPRSMW_SafeSitOffsetLn_met (LCF_CommonParamData.P_DPRSMW_SafeSitOffsetLn_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_SafeSitOffsetLn_met() (P_DPRSMW_SafeSitOffsetLn_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SafeSitOffsetLn_met

#ifndef P_DPRSMW_SafeSitOffsetRe_met
#define P_DPRSMW_SafeSitOffsetRe_met (LCF_CommonParamData.P_DPRSMW_SafeSitOffsetRe_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_SafeSitOffsetRe_met() (P_DPRSMW_SafeSitOffsetRe_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SafeSitOffsetRe_met

#ifndef P_DPRSMW_SafeSitStateLn_btm
#define P_DPRSMW_SafeSitStateLn_btm (LCF_CommonParamData.P_DPRSMW_SafeSitStateLn_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SafeSitStateLn_btm() (P_DPRSMW_SafeSitStateLn_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SafeSitStateLn_btm

#ifndef P_DPRSMW_SafeSitStateRe_btm
#define P_DPRSMW_SafeSitStateRe_btm (LCF_CommonParamData.P_DPRSMW_SafeSitStateRe_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SafeSitStateRe_btm() (P_DPRSMW_SafeSitStateRe_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SafeSitStateRe_btm

#ifndef P_DPRSMW_SideCondCancel_btm
#define P_DPRSMW_SideCondCancel_btm (LCF_CommonParamData.P_DPRSMW_SideCondCancel_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SideCondCancel_btm() (P_DPRSMW_SideCondCancel_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SideCondCancel_btm

#ifndef P_DPRSMW_SideCondDebug_btm
#define P_DPRSMW_SideCondDebug_btm (LCF_CommonParamData.P_DPRSMW_SideCondDebug_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SideCondDebug_btm() (P_DPRSMW_SideCondDebug_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SideCondDebug_btm

#ifndef P_DPRSMW_SideCondEnable_btm
#define P_DPRSMW_SideCondEnable_btm (LCF_CommonParamData.P_DPRSMW_SideCondEnable_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SideCondEnable_btm() (P_DPRSMW_SideCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SideCondEnable_btm

#ifndef P_DPRSMW_StrgRdyDegrDuration_sec
#define P_DPRSMW_StrgRdyDegrDuration_sec (LCF_CommonParamData.P_DPRSMW_StrgRdyDegrDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyDegrDuration_sec() (P_DPRSMW_StrgRdyDegrDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyDegrDuration_sec

#ifndef P_DPRSMW_StrgRdyDrvSt_btm
#define P_DPRSMW_StrgRdyDrvSt_btm (LCF_CommonParamData.P_DPRSMW_StrgRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyDrvSt_btm() (P_DPRSMW_StrgRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyDrvSt_btm

#ifndef P_DPRSMW_StrgRdyFctCustom_btm
#define P_DPRSMW_StrgRdyFctCustom_btm (LCF_CommonParamData.P_DPRSMW_StrgRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyFctCustom_btm() (P_DPRSMW_StrgRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyFctCustom_btm

#ifndef P_DPRSMW_StrgRdyFctStCtr_btm
#define P_DPRSMW_StrgRdyFctStCtr_btm (LCF_CommonParamData.P_DPRSMW_StrgRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyFctStCtr_btm() (P_DPRSMW_StrgRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyFctStCtr_btm

#ifndef P_DPRSMW_StrgRdyFctStErr_btm
#define P_DPRSMW_StrgRdyFctStErr_btm (LCF_CommonParamData.P_DPRSMW_StrgRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyFctStErr_btm() (P_DPRSMW_StrgRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyFctStErr_btm

#ifndef P_DPRSMW_StrgRdyFctStNotAv_btm
#define P_DPRSMW_StrgRdyFctStNotAv_btm (LCF_CommonParamData.P_DPRSMW_StrgRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyFctStNotAv_btm() (P_DPRSMW_StrgRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyFctStNotAv_btm

#ifndef P_DPRSMW_StrgRdySpecific_btm
#define P_DPRSMW_StrgRdySpecific_btm (LCF_CommonParamData.P_DPRSMW_StrgRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdySpecific_btm() (P_DPRSMW_StrgRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdySpecific_btm

#ifndef P_DPRSMW_StrgRdyVehSt_btm
#define P_DPRSMW_StrgRdyVehSt_btm (LCF_CommonParamData.P_DPRSMW_StrgRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_StrgRdyVehSt_btm() (P_DPRSMW_StrgRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_StrgRdyVehSt_btm

#ifndef P_DPRSMW_SuppressDrvSt_btm
#define P_DPRSMW_SuppressDrvSt_btm (LCF_CommonParamData.P_DPRSMW_SuppressDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressDrvSt_btm() (P_DPRSMW_SuppressDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressDrvSt_btm

#ifndef P_DPRSMW_SuppressFctCustom_btm
#define P_DPRSMW_SuppressFctCustom_btm (LCF_CommonParamData.P_DPRSMW_SuppressFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressFctCustom_btm() (P_DPRSMW_SuppressFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressFctCustom_btm

#ifndef P_DPRSMW_SuppressFctStCtr_btm
#define P_DPRSMW_SuppressFctStCtr_btm (LCF_CommonParamData.P_DPRSMW_SuppressFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressFctStCtr_btm() (P_DPRSMW_SuppressFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressFctStCtr_btm

#ifndef P_DPRSMW_SuppressFctStErr_btm
#define P_DPRSMW_SuppressFctStErr_btm (LCF_CommonParamData.P_DPRSMW_SuppressFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressFctStErr_btm() (P_DPRSMW_SuppressFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressFctStErr_btm

#ifndef P_DPRSMW_SuppressFctStNotAv_btm
#define P_DPRSMW_SuppressFctStNotAv_btm (LCF_CommonParamData.P_DPRSMW_SuppressFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressFctStNotAv_btm() (P_DPRSMW_SuppressFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressFctStNotAv_btm

#ifndef P_DPRSMW_SuppressSpecific_btm
#define P_DPRSMW_SuppressSpecific_btm (LCF_CommonParamData.P_DPRSMW_SuppressSpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressSpecific_btm() (P_DPRSMW_SuppressSpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressSpecific_btm

#ifndef P_DPRSMW_SuppressVehSt_btm
#define P_DPRSMW_SuppressVehSt_btm (LCF_CommonParamData.P_DPRSMW_SuppressVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_SuppressVehSt_btm() (P_DPRSMW_SuppressVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_SuppressVehSt_btm

#ifndef P_DPRSMW_TgtTrajPosY0_met
#define P_DPRSMW_TgtTrajPosY0_met (LCF_CommonParamData.P_DPRSMW_TgtTrajPosY0_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_TgtTrajPosY0_met() (P_DPRSMW_TgtTrajPosY0_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TgtTrajPosY0_met

#ifndef P_DPRSMW_TlcDistanceMin_met
#define P_DPRSMW_TlcDistanceMin_met (LCF_CommonParamData.P_DPRSMW_TlcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_TlcDistanceMin_met() (P_DPRSMW_TlcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TlcDistanceMin_met

#ifndef P_DPRSMW_TlcValidMinTime_sec
#define P_DPRSMW_TlcValidMinTime_sec (LCF_CommonParamData.P_DPRSMW_TlcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_TlcValidMinTime_sec() (P_DPRSMW_TlcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TlcValidMinTime_sec

#ifndef P_DPRSMW_TrcDistanceMin_met
#define P_DPRSMW_TrcDistanceMin_met (LCF_CommonParamData.P_DPRSMW_TrcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_DPRSMW_TrcDistanceMin_met() (P_DPRSMW_TrcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TrcDistanceMin_met

#ifndef P_DPRSMW_TrcValidMinTime_sec
#define P_DPRSMW_TrcValidMinTime_sec (LCF_CommonParamData.P_DPRSMW_TrcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_TrcValidMinTime_sec() (P_DPRSMW_TrcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TrcValidMinTime_sec

#ifndef P_DPRSMW_TrgIgnoreLnContg_bool
#define P_DPRSMW_TrgIgnoreLnContg_bool (LCF_CommonParamData.P_DPRSMW_TrgIgnoreLnContg_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_TrgIgnoreLnContg_bool() (P_DPRSMW_TrgIgnoreLnContg_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TrgIgnoreLnContg_bool

#ifndef P_DPRSMW_TriggerAlwaysOn_bool
#define P_DPRSMW_TriggerAlwaysOn_bool (LCF_CommonParamData.P_DPRSMW_TriggerAlwaysOn_bool) //!< LCF parameter macro.
#define GET_P_DPRSMW_TriggerAlwaysOn_bool() (P_DPRSMW_TriggerAlwaysOn_bool) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TriggerAlwaysOn_bool

#ifndef P_DPRSMW_TriggerHoldingTime_sec
#define P_DPRSMW_TriggerHoldingTime_sec (LCF_CommonParamData.P_DPRSMW_TriggerHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_DPRSMW_TriggerHoldingTime_sec() (P_DPRSMW_TriggerHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_DPRSMW_TriggerHoldingTime_sec

#ifndef P_DPRSMW_WeakRdyDrvSt_btm
#define P_DPRSMW_WeakRdyDrvSt_btm (LCF_CommonParamData.P_DPRSMW_WeakRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdyDrvSt_btm() (P_DPRSMW_WeakRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdyDrvSt_btm

#ifndef P_DPRSMW_WeakRdyFctCustom_btm
#define P_DPRSMW_WeakRdyFctCustom_btm (LCF_CommonParamData.P_DPRSMW_WeakRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdyFctCustom_btm() (P_DPRSMW_WeakRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdyFctCustom_btm

#ifndef P_DPRSMW_WeakRdyFctStCtr_btm
#define P_DPRSMW_WeakRdyFctStCtr_btm (LCF_CommonParamData.P_DPRSMW_WeakRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdyFctStCtr_btm() (P_DPRSMW_WeakRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdyFctStCtr_btm

#ifndef P_DPRSMW_WeakRdyFctStErr_btm
#define P_DPRSMW_WeakRdyFctStErr_btm (LCF_CommonParamData.P_DPRSMW_WeakRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdyFctStErr_btm() (P_DPRSMW_WeakRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdyFctStErr_btm

#ifndef P_DPRSMW_WeakRdyFctStNotAv_btm
#define P_DPRSMW_WeakRdyFctStNotAv_btm (LCF_CommonParamData.P_DPRSMW_WeakRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdyFctStNotAv_btm() (P_DPRSMW_WeakRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdyFctStNotAv_btm

#ifndef P_DPRSMW_WeakRdySpecific_btm
#define P_DPRSMW_WeakRdySpecific_btm (LCF_CommonParamData.P_DPRSMW_WeakRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdySpecific_btm() (P_DPRSMW_WeakRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdySpecific_btm

#ifndef P_DPRSMW_WeakRdyVehSt_btm
#define P_DPRSMW_WeakRdyVehSt_btm (LCF_CommonParamData.P_DPRSMW_WeakRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_DPRSMW_WeakRdyVehSt_btm() (P_DPRSMW_WeakRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_DPRSMW_WeakRdyVehSt_btm

#ifndef P_DPRTTG_TargetLatDistLn_met
#define P_DPRTTG_TargetLatDistLn_met (LCF_CommonParamData.P_DPRTTG_TargetLatDistLn_met) //!< LCF parameter macro.
#define GET_P_DPRTTG_TargetLatDistLn_met() (P_DPRTTG_TargetLatDistLn_met) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TargetLatDistLn_met

#ifndef P_DPRTTG_TargetLatDistRe_met
#define P_DPRTTG_TargetLatDistRe_met (LCF_CommonParamData.P_DPRTTG_TargetLatDistRe_met) //!< LCF parameter macro.
#define GET_P_DPRTTG_TargetLatDistRe_met() (P_DPRTTG_TargetLatDistRe_met) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TargetLatDistRe_met

#ifndef P_DPRTTG_TargetTrajPT1Active_nu
#define P_DPRTTG_TargetTrajPT1Active_nu (LCF_CommonParamData.P_DPRTTG_TargetTrajPT1Active_nu) //!< LCF parameter macro.
#define GET_P_DPRTTG_TargetTrajPT1Active_nu() (P_DPRTTG_TargetTrajPT1Active_nu) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TargetTrajPT1Active_nu

#ifndef P_DPRTTG_TgtCntrLnEnable_bool
#define P_DPRTTG_TgtCntrLnEnable_bool (LCF_CommonParamData.P_DPRTTG_TgtCntrLnEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtCntrLnEnable_bool() (P_DPRTTG_TgtCntrLnEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtCntrLnEnable_bool

#ifndef P_DPRTTG_TgtCntrRdEnable_bool
#define P_DPRTTG_TgtCntrRdEnable_bool (LCF_CommonParamData.P_DPRTTG_TgtCntrRdEnable_bool) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtCntrRdEnable_bool() (P_DPRTTG_TgtCntrRdEnable_bool) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtCntrRdEnable_bool

#ifndef P_DPRTTG_TgtMaxDistanceLn_met
#define P_DPRTTG_TgtMaxDistanceLn_met (LCF_CommonParamData.P_DPRTTG_TgtMaxDistanceLn_met) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtMaxDistanceLn_met() (P_DPRTTG_TgtMaxDistanceLn_met) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtMaxDistanceLn_met

#ifndef P_DPRTTG_TgtMaxDistanceRe_met
#define P_DPRTTG_TgtMaxDistanceRe_met (LCF_CommonParamData.P_DPRTTG_TgtMaxDistanceRe_met) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtMaxDistanceRe_met() (P_DPRTTG_TgtMaxDistanceRe_met) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtMaxDistanceRe_met

#ifndef P_DPRTTG_TgtMaxLatDevLn_met
#define P_DPRTTG_TgtMaxLatDevLn_met (LCF_CommonParamData.P_DPRTTG_TgtMaxLatDevLn_met) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtMaxLatDevLn_met() (P_DPRTTG_TgtMaxLatDevLn_met) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtMaxLatDevLn_met

#ifndef P_DPRTTG_TgtMaxLatDevRe_met
#define P_DPRTTG_TgtMaxLatDevRe_met (LCF_CommonParamData.P_DPRTTG_TgtMaxLatDevRe_met) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtMaxLatDevRe_met() (P_DPRTTG_TgtMaxLatDevRe_met) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtMaxLatDevRe_met

#ifndef P_DPRTTG_TgtTrjPT1TimeConst_sec
#define P_DPRTTG_TgtTrjPT1TimeConst_sec (LCF_CommonParamData.P_DPRTTG_TgtTrjPT1TimeConst_sec) //!< LCF parameter macro.
#define GET_P_DPRTTG_TgtTrjPT1TimeConst_sec() (P_DPRTTG_TgtTrjPT1TimeConst_sec) //!< LCF parameter macro getter.
#endif // P_DPRTTG_TgtTrjPT1TimeConst_sec

#ifndef P_DPRTVG_DistYTolLeTgtArea_met
#define P_DPRTVG_DistYTolLeTgtArea_met (LCF_CommonParamData.P_DPRTVG_DistYTolLeTgtArea_met) //!< LCF parameter macro.
#define GET_P_DPRTVG_DistYTolLeTgtArea_met() (P_DPRTVG_DistYTolLeTgtArea_met) //!< LCF parameter macro getter.
#endif // P_DPRTVG_DistYTolLeTgtArea_met

#ifndef P_DPRTVG_DistYTolRiTgtArea_met
#define P_DPRTVG_DistYTolRiTgtArea_met (LCF_CommonParamData.P_DPRTVG_DistYTolRiTgtArea_met) //!< LCF parameter macro.
#define GET_P_DPRTVG_DistYTolRiTgtArea_met() (P_DPRTVG_DistYTolRiTgtArea_met) //!< LCF parameter macro getter.
#endif // P_DPRTVG_DistYTolRiTgtArea_met

#ifndef P_DPRTVG_FTireAccelMax_mps2
#define P_DPRTVG_FTireAccelMax_mps2 (LCF_CommonParamData.P_DPRTVG_FTireAccelMax_mps2) //!< LCF parameter macro.
#define GET_P_DPRTVG_FTireAccelMax_mps2() (P_DPRTVG_FTireAccelMax_mps2) //!< LCF parameter macro getter.
#endif // P_DPRTVG_FTireAccelMax_mps2

#ifndef P_DPRTVG_FTireAccelMin_mps2
#define P_DPRTVG_FTireAccelMin_mps2 (LCF_CommonParamData.P_DPRTVG_FTireAccelMin_mps2) //!< LCF parameter macro.
#define GET_P_DPRTVG_FTireAccelMin_mps2() (P_DPRTVG_FTireAccelMin_mps2) //!< LCF parameter macro getter.
#endif // P_DPRTVG_FTireAccelMin_mps2

#ifndef P_DPRTVG_HighStatAccu_bool
#define P_DPRTVG_HighStatAccu_bool (LCF_CommonParamData.P_DPRTVG_HighStatAccu_bool) //!< LCF parameter macro.
#define GET_P_DPRTVG_HighStatAccu_bool() (P_DPRTVG_HighStatAccu_bool) //!< LCF parameter macro getter.
#endif // P_DPRTVG_HighStatAccu_bool

#ifndef P_DPRTVG_LimiterActivated_bool
#define P_DPRTVG_LimiterActivated_bool (LCF_CommonParamData.P_DPRTVG_LimiterActivated_bool) //!< LCF parameter macro.
#define GET_P_DPRTVG_LimiterActivated_bool() (P_DPRTVG_LimiterActivated_bool) //!< LCF parameter macro getter.
#endif // P_DPRTVG_LimiterActivated_bool

#ifndef P_DPRTVG_LimiterMaxCrvGrd_1pms
#define P_DPRTVG_LimiterMaxCrvGrd_1pms (LCF_CommonParamData.P_DPRTVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro.
#define GET_P_DPRTVG_LimiterMaxCrvGrd_1pms() (P_DPRTVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro getter.
#endif // P_DPRTVG_LimiterMaxCrvGrd_1pms

#ifndef P_DPRTVG_LimiterMaxCrv_1pm
#define P_DPRTVG_LimiterMaxCrv_1pm (LCF_CommonParamData.P_DPRTVG_LimiterMaxCrv_1pm) //!< LCF parameter macro.
#define GET_P_DPRTVG_LimiterMaxCrv_1pm() (P_DPRTVG_LimiterMaxCrv_1pm) //!< LCF parameter macro getter.
#endif // P_DPRTVG_LimiterMaxCrv_1pm

#ifndef P_DPRTVG_LimiterTimeDuration_sec
#define P_DPRTVG_LimiterTimeDuration_sec (LCF_CommonParamData.P_DPRTVG_LimiterTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_DPRTVG_LimiterTimeDuration_sec() (P_DPRTVG_LimiterTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_DPRTVG_LimiterTimeDuration_sec

#ifndef P_DPRTVG_MaxJerkAllowed_mps3
#define P_DPRTVG_MaxJerkAllowed_mps3 (LCF_CommonParamData.P_DPRTVG_MaxJerkAllowed_mps3) //!< LCF parameter macro.
#define GET_P_DPRTVG_MaxJerkAllowed_mps3() (P_DPRTVG_MaxJerkAllowed_mps3) //!< LCF parameter macro getter.
#endif // P_DPRTVG_MaxJerkAllowed_mps3

#ifndef P_DPRTVG_MaxTrqScalLimit_nu
#define P_DPRTVG_MaxTrqScalLimit_nu (LCF_CommonParamData.P_DPRTVG_MaxTrqScalLimit_nu) //!< LCF parameter macro.
#define GET_P_DPRTVG_MaxTrqScalLimit_nu() (P_DPRTVG_MaxTrqScalLimit_nu) //!< LCF parameter macro getter.
#endif // P_DPRTVG_MaxTrqScalLimit_nu

#ifndef P_DPRTVG_MaxTrqScalRampInGrd_1ps
#define P_DPRTVG_MaxTrqScalRampInGrd_1ps (LCF_CommonParamData.P_DPRTVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_MaxTrqScalRampInGrd_1ps() (P_DPRTVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_MaxTrqScalRampInGrd_1ps

#ifndef P_DPRTVG_MaxTrqScalRampOutGrd_1ps
#define P_DPRTVG_MaxTrqScalRampOutGrd_1ps (LCF_CommonParamData.P_DPRTVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_MaxTrqScalRampOutGrd_1ps() (P_DPRTVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_MaxTrqScalRampOutGrd_1ps

#ifndef P_DPRTVG_PredTimeCrv_sec
#define P_DPRTVG_PredTimeCrv_sec (LCF_CommonParamData.P_DPRTVG_PredTimeCrv_sec) //!< LCF parameter macro.
#define GET_P_DPRTVG_PredTimeCrv_sec() (P_DPRTVG_PredTimeCrv_sec) //!< LCF parameter macro getter.
#endif // P_DPRTVG_PredTimeCrv_sec

#ifndef P_DPRTVG_PredTimeHeadAng_sec
#define P_DPRTVG_PredTimeHeadAng_sec (LCF_CommonParamData.P_DPRTVG_PredTimeHeadAng_sec) //!< LCF parameter macro.
#define GET_P_DPRTVG_PredTimeHeadAng_sec() (P_DPRTVG_PredTimeHeadAng_sec) //!< LCF parameter macro getter.
#endif // P_DPRTVG_PredTimeHeadAng_sec

#ifndef P_DPRTVG_StrWhStifAbortROGrd_1ps
#define P_DPRTVG_StrWhStifAbortROGrd_1ps (LCF_CommonParamData.P_DPRTVG_StrWhStifAbortROGrd_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_StrWhStifAbortROGrd_1ps() (P_DPRTVG_StrWhStifAbortROGrd_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_StrWhStifAbortROGrd_1ps

#ifndef P_DPRTVG_StrWhStifLimit_nu
#define P_DPRTVG_StrWhStifLimit_nu (LCF_CommonParamData.P_DPRTVG_StrWhStifLimit_nu) //!< LCF parameter macro.
#define GET_P_DPRTVG_StrWhStifLimit_nu() (P_DPRTVG_StrWhStifLimit_nu) //!< LCF parameter macro getter.
#endif // P_DPRTVG_StrWhStifLimit_nu

#ifndef P_DPRTVG_StrWhStifROGrad_1ps
#define P_DPRTVG_StrWhStifROGrad_1ps (LCF_CommonParamData.P_DPRTVG_StrWhStifROGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_StrWhStifROGrad_1ps() (P_DPRTVG_StrWhStifROGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_StrWhStifROGrad_1ps

#ifndef P_DPRTVG_TrajPlanServQu_nu
#define P_DPRTVG_TrajPlanServQu_nu (LCF_CommonParamData.P_DPRTVG_TrajPlanServQu_nu) //!< LCF parameter macro.
#define GET_P_DPRTVG_TrajPlanServQu_nu() (P_DPRTVG_TrajPlanServQu_nu) //!< LCF parameter macro getter.
#endif // P_DPRTVG_TrajPlanServQu_nu

#ifndef P_DPRTVG_TriggerReplan_bool
#define P_DPRTVG_TriggerReplan_bool (LCF_CommonParamData.P_DPRTVG_TriggerReplan_bool) //!< LCF parameter macro.
#define GET_P_DPRTVG_TriggerReplan_bool() (P_DPRTVG_TriggerReplan_bool) //!< LCF parameter macro getter.
#endif // P_DPRTVG_TriggerReplan_bool

#ifndef P_DPRTVG_TrqAbortROGrad_1ps
#define P_DPRTVG_TrqAbortROGrad_1ps (LCF_CommonParamData.P_DPRTVG_TrqAbortROGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_TrqAbortROGrad_1ps() (P_DPRTVG_TrqAbortROGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_TrqAbortROGrad_1ps

#ifndef P_DPRTVG_TrqRampInGrad_1ps
#define P_DPRTVG_TrqRampInGrad_1ps (LCF_CommonParamData.P_DPRTVG_TrqRampInGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_TrqRampInGrad_1ps() (P_DPRTVG_TrqRampInGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_TrqRampInGrad_1ps

#ifndef P_DPRTVG_TrqRampOutGrad_1ps
#define P_DPRTVG_TrqRampOutGrad_1ps (LCF_CommonParamData.P_DPRTVG_TrqRampOutGrad_1ps) //!< LCF parameter macro.
#define GET_P_DPRTVG_TrqRampOutGrad_1ps() (P_DPRTVG_TrqRampOutGrad_1ps) //!< LCF parameter macro getter.
#endif // P_DPRTVG_TrqRampOutGrad_1ps

#ifndef P_DPRTVG_UseLtcyComp_nu
#define P_DPRTVG_UseLtcyComp_nu (LCF_CommonParamData.P_DPRTVG_UseLtcyComp_nu) //!< LCF parameter macro.
#define GET_P_DPRTVG_UseLtcyComp_nu() (P_DPRTVG_UseLtcyComp_nu) //!< LCF parameter macro getter.
#endif // P_DPRTVG_UseLtcyComp_nu

#ifndef P_DPRTVG_WeightTgtDistY_nu
#define P_DPRTVG_WeightTgtDistY_nu (LCF_CommonParamData.P_DPRTVG_WeightTgtDistY_nu) //!< LCF parameter macro.
#define GET_P_DPRTVG_WeightTgtDistY_nu() (P_DPRTVG_WeightTgtDistY_nu) //!< LCF parameter macro getter.
#endif // P_DPRTVG_WeightTgtDistY_nu

#ifndef P_DRMDAE_1stIncCycle_nu
#define P_DRMDAE_1stIncCycle_nu (LCF_CommonParamData.P_DRMDAE_1stIncCycle_nu) //!< LCF parameter macro.
#define GET_P_DRMDAE_1stIncCycle_nu() (P_DRMDAE_1stIncCycle_nu) //!< LCF parameter macro getter.
#endif // P_DRMDAE_1stIncCycle_nu

#ifndef P_DRMDAE_Abuse1stDuration_sec
#define P_DRMDAE_Abuse1stDuration_sec (LCF_CommonParamData.P_DRMDAE_Abuse1stDuration_sec) //!< LCF parameter macro.
#define GET_P_DRMDAE_Abuse1stDuration_sec() (P_DRMDAE_Abuse1stDuration_sec) //!< LCF parameter macro getter.
#endif // P_DRMDAE_Abuse1stDuration_sec

#ifndef P_DRMDAE_AbuseFunctions_btf
#define P_DRMDAE_AbuseFunctions_btf (LCF_CommonParamData.P_DRMDAE_AbuseFunctions_btf) //!< LCF parameter macro.
#define GET_P_DRMDAE_AbuseFunctions_btf() (P_DRMDAE_AbuseFunctions_btf) //!< LCF parameter macro getter.
#endif // P_DRMDAE_AbuseFunctions_btf

#ifndef P_DRMDAE_ConsecIntervTimer_sec
#define P_DRMDAE_ConsecIntervTimer_sec (LCF_CommonParamData.P_DRMDAE_ConsecIntervTimer_sec) //!< LCF parameter macro.
#define GET_P_DRMDAE_ConsecIntervTimer_sec() (P_DRMDAE_ConsecIntervTimer_sec) //!< LCF parameter macro getter.
#endif // P_DRMDAE_ConsecIntervTimer_sec

#ifndef P_DRMDAE_IncNextWarning_sec
#define P_DRMDAE_IncNextWarning_sec (LCF_CommonParamData.P_DRMDAE_IncNextWarning_sec) //!< LCF parameter macro.
#define GET_P_DRMDAE_IncNextWarning_sec() (P_DRMDAE_IncNextWarning_sec) //!< LCF parameter macro getter.
#endif // P_DRMDAE_IncNextWarning_sec

#ifndef P_DRMDAE_RlvntConfFct_btf
#define P_DRMDAE_RlvntConfFct_btf (LCF_CommonParamData.P_DRMDAE_RlvntConfFct_btf) //!< LCF parameter macro.
#define GET_P_DRMDAE_RlvntConfFct_btf() (P_DRMDAE_RlvntConfFct_btf) //!< LCF parameter macro getter.
#endif // P_DRMDAE_RlvntConfFct_btf

#ifndef P_DRMDAE_SpeedLimitHyst_mps
#define P_DRMDAE_SpeedLimitHyst_mps (LCF_CommonParamData.P_DRMDAE_SpeedLimitHyst_mps) //!< LCF parameter macro.
#define GET_P_DRMDAE_SpeedLimitHyst_mps() (P_DRMDAE_SpeedLimitHyst_mps) //!< LCF parameter macro getter.
#endif // P_DRMDAE_SpeedLimitHyst_mps

#ifndef P_DRMDAE_SpeedMin_mps
#define P_DRMDAE_SpeedMin_mps (LCF_CommonParamData.P_DRMDAE_SpeedMin_mps) //!< LCF parameter macro.
#define GET_P_DRMDAE_SpeedMin_mps() (P_DRMDAE_SpeedMin_mps) //!< LCF parameter macro getter.
#endif // P_DRMDAE_SpeedMin_mps

#ifndef P_DRMHOD_AngleSensAvailable_bool
#define P_DRMHOD_AngleSensAvailable_bool (LCF_CommonParamData.P_DRMHOD_AngleSensAvailable_bool) //!< LCF parameter macro.
#define GET_P_DRMHOD_AngleSensAvailable_bool() (P_DRMHOD_AngleSensAvailable_bool) //!< LCF parameter macro getter.
#endif // P_DRMHOD_AngleSensAvailable_bool

#ifndef P_DRMHOD_BasicDebounceOnly_bool
#define P_DRMHOD_BasicDebounceOnly_bool (LCF_CommonParamData.P_DRMHOD_BasicDebounceOnly_bool) //!< LCF parameter macro.
#define GET_P_DRMHOD_BasicDebounceOnly_bool() (P_DRMHOD_BasicDebounceOnly_bool) //!< LCF parameter macro getter.
#endif // P_DRMHOD_BasicDebounceOnly_bool

#ifndef P_DRMHOD_DebugMode_nu
#define P_DRMHOD_DebugMode_nu (LCF_CommonParamData.P_DRMHOD_DebugMode_nu) //!< LCF parameter macro.
#define GET_P_DRMHOD_DebugMode_nu() (P_DRMHOD_DebugMode_nu) //!< LCF parameter macro getter.
#endif // P_DRMHOD_DebugMode_nu

#ifndef P_DRMHOD_EstHandTqOffsetN_Nm
#define P_DRMHOD_EstHandTqOffsetN_Nm (LCF_CommonParamData.P_DRMHOD_EstHandTqOffsetN_Nm) //!< LCF parameter macro.
#define GET_P_DRMHOD_EstHandTqOffsetN_Nm() (P_DRMHOD_EstHandTqOffsetN_Nm) //!< LCF parameter macro getter.
#endif // P_DRMHOD_EstHandTqOffsetN_Nm

#ifndef P_DRMHOD_EstHandTqOffsetP_Nm
#define P_DRMHOD_EstHandTqOffsetP_Nm (LCF_CommonParamData.P_DRMHOD_EstHandTqOffsetP_Nm) //!< LCF parameter macro.
#define GET_P_DRMHOD_EstHandTqOffsetP_Nm() (P_DRMHOD_EstHandTqOffsetP_Nm) //!< LCF parameter macro getter.
#endif // P_DRMHOD_EstHandTqOffsetP_Nm

#ifndef P_DRMHOD_ExternalSensorUsed_bool
#define P_DRMHOD_ExternalSensorUsed_bool (LCF_CommonParamData.P_DRMHOD_ExternalSensorUsed_bool) //!< LCF parameter macro.
#define GET_P_DRMHOD_ExternalSensorUsed_bool() (P_DRMHOD_ExternalSensorUsed_bool) //!< LCF parameter macro getter.
#endif // P_DRMHOD_ExternalSensorUsed_bool

#ifndef P_DRMHOD_HandsOffLimit_gen
#define P_DRMHOD_HandsOffLimit_gen (LCF_CommonParamData.P_DRMHOD_HandsOffLimit_gen) //!< LCF parameter macro.
#define GET_P_DRMHOD_HandsOffLimit_gen() (P_DRMHOD_HandsOffLimit_gen) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HandsOffLimit_gen

#ifndef P_DRMHOD_HandsOffQlfMaxTime_sec
#define P_DRMHOD_HandsOffQlfMaxTime_sec (LCF_CommonParamData.P_DRMHOD_HandsOffQlfMaxTime_sec) //!< LCF parameter macro.
#define GET_P_DRMHOD_HandsOffQlfMaxTime_sec() (P_DRMHOD_HandsOffQlfMaxTime_sec) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HandsOffQlfMaxTime_sec

#ifndef P_DRMHOD_HandsOffQlfTime_sec
#define P_DRMHOD_HandsOffQlfTime_sec (LCF_CommonParamData.P_DRMHOD_HandsOffQlfTime_sec) //!< LCF parameter macro.
#define GET_P_DRMHOD_HandsOffQlfTime_sec() (P_DRMHOD_HandsOffQlfTime_sec) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HandsOffQlfTime_sec

#ifndef P_DRMHOD_HandsOnLimit_gen
#define P_DRMHOD_HandsOnLimit_gen (LCF_CommonParamData.P_DRMHOD_HandsOnLimit_gen) //!< LCF parameter macro.
#define GET_P_DRMHOD_HandsOnLimit_gen() (P_DRMHOD_HandsOnLimit_gen) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HandsOnLimit_gen

#ifndef P_DRMHOD_HandsOnQlfTime_sec
#define P_DRMHOD_HandsOnQlfTime_sec (LCF_CommonParamData.P_DRMHOD_HandsOnQlfTime_sec) //!< LCF parameter macro.
#define GET_P_DRMHOD_HandsOnQlfTime_sec() (P_DRMHOD_HandsOnQlfTime_sec) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HandsOnQlfTime_sec

#ifndef P_DRMHOD_HandsOnTorLimAbs_Nm
#define P_DRMHOD_HandsOnTorLimAbs_Nm (LCF_CommonParamData.P_DRMHOD_HandsOnTorLimAbs_Nm) //!< LCF parameter macro.
#define GET_P_DRMHOD_HandsOnTorLimAbs_Nm() (P_DRMHOD_HandsOnTorLimAbs_Nm) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HandsOnTorLimAbs_Nm

#ifndef P_DRMHOD_HdOffDltProlTime_sec
#define P_DRMHOD_HdOffDltProlTime_sec (LCF_CommonParamData.P_DRMHOD_HdOffDltProlTime_sec) //!< LCF parameter macro.
#define GET_P_DRMHOD_HdOffDltProlTime_sec() (P_DRMHOD_HdOffDltProlTime_sec) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HdOffDltProlTime_sec

#ifndef P_DRMHOD_HdOffSensedTqDelta_Nm
#define P_DRMHOD_HdOffSensedTqDelta_Nm (LCF_CommonParamData.P_DRMHOD_HdOffSensedTqDelta_Nm) //!< LCF parameter macro.
#define GET_P_DRMHOD_HdOffSensedTqDelta_Nm() (P_DRMHOD_HdOffSensedTqDelta_Nm) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HdOffSensedTqDelta_Nm

#ifndef P_DRMHOD_HdOffTqStepLim_Nm
#define P_DRMHOD_HdOffTqStepLim_Nm (LCF_CommonParamData.P_DRMHOD_HdOffTqStepLim_Nm) //!< LCF parameter macro.
#define GET_P_DRMHOD_HdOffTqStepLim_Nm() (P_DRMHOD_HdOffTqStepLim_Nm) //!< LCF parameter macro getter.
#endif // P_DRMHOD_HdOffTqStepLim_Nm

#ifndef P_HMODFL_UsePassiveAvlbFct_bool
#define P_HMODFL_UsePassiveAvlbFct_bool (LCF_CommonParamData.P_HMODFL_UsePassiveAvlbFct_bool) //!< LCF parameter macro.
#define GET_P_HMODFL_UsePassiveAvlbFct_bool() (P_HMODFL_UsePassiveAvlbFct_bool) //!< LCF parameter macro getter.
#endif // P_HMODFL_UsePassiveAvlbFct_bool

#ifndef P_HMODFL_WarningCycle_nu
#define P_HMODFL_WarningCycle_nu (LCF_CommonParamData.P_HMODFL_WarningCycle_nu) //!< LCF parameter macro.
#define GET_P_HMODFL_WarningCycle_nu() (P_HMODFL_WarningCycle_nu) //!< LCF parameter macro getter.
#endif // P_HMODFL_WarningCycle_nu

#ifndef P_JCNCTR_ELKAccPedalPosNoSupDur_sec
#define P_JCNCTR_ELKAccPedalPosNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKAccPedalPosNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKAccPedalPosNoSupDur_sec() (P_JCNCTR_ELKAccPedalPosNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKAccPedalPosNoSupDur_sec

#ifndef P_JCNCTR_ELKAccPedalPosNoSup_nu
#define P_JCNCTR_ELKAccPedalPosNoSup_nu (LCF_CommonParamData.P_JCNCTR_ELKAccPedalPosNoSup_nu) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKAccPedalPosNoSup_nu() (P_JCNCTR_ELKAccPedalPosNoSup_nu) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKAccPedalPosNoSup_nu

#ifndef P_JCNCTR_ELKAccPedalPosSupDur_sec
#define P_JCNCTR_ELKAccPedalPosSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKAccPedalPosSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKAccPedalPosSupDur_sec() (P_JCNCTR_ELKAccPedalPosSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKAccPedalPosSupDur_sec

#ifndef P_JCNCTR_ELKAccPedalPosSup_nu
#define P_JCNCTR_ELKAccPedalPosSup_nu (LCF_CommonParamData.P_JCNCTR_ELKAccPedalPosSup_nu) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKAccPedalPosSup_nu() (P_JCNCTR_ELKAccPedalPosSup_nu) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKAccPedalPosSup_nu

#ifndef P_JCNCTR_ELKActiveStCtrNoSupTime_sec
#define P_JCNCTR_ELKActiveStCtrNoSupTime_sec (LCF_CommonParamData.P_JCNCTR_ELKActiveStCtrNoSupTime_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKActiveStCtrNoSupTime_sec() (P_JCNCTR_ELKActiveStCtrNoSupTime_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKActiveStCtrNoSupTime_sec

#ifndef P_JCNCTR_ELKActiveStCtrSupTime_sec
#define P_JCNCTR_ELKActiveStCtrSupTime_sec (LCF_CommonParamData.P_JCNCTR_ELKActiveStCtrSupTime_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKActiveStCtrSupTime_sec() (P_JCNCTR_ELKActiveStCtrSupTime_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKActiveStCtrSupTime_sec

#ifndef P_JCNCTR_ELKBothLaneInvalidSupDur_sec
#define P_JCNCTR_ELKBothLaneInvalidSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKBothLaneInvalidSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKBothLaneInvalidSupDur_sec() (P_JCNCTR_ELKBothLaneInvalidSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKBothLaneInvalidSupDur_sec

#ifndef P_JCNCTR_ELKBothLaneValidNoSupDur_sec
#define P_JCNCTR_ELKBothLaneValidNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKBothLaneValidNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKBothLaneValidNoSupDur_sec() (P_JCNCTR_ELKBothLaneValidNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKBothLaneValidNoSupDur_sec

#ifndef P_JCNCTR_ELKCurvatureNoSupDur_sec
#define P_JCNCTR_ELKCurvatureNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKCurvatureNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKCurvatureNoSupDur_sec() (P_JCNCTR_ELKCurvatureNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKCurvatureNoSupDur_sec

#ifndef P_JCNCTR_ELKCurvatureNoSup_1pm
#define P_JCNCTR_ELKCurvatureNoSup_1pm (LCF_CommonParamData.P_JCNCTR_ELKCurvatureNoSup_1pm) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKCurvatureNoSup_1pm() (P_JCNCTR_ELKCurvatureNoSup_1pm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKCurvatureNoSup_1pm

#ifndef P_JCNCTR_ELKCurvatureSupDur_sec
#define P_JCNCTR_ELKCurvatureSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKCurvatureSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKCurvatureSupDur_sec() (P_JCNCTR_ELKCurvatureSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKCurvatureSupDur_sec

#ifndef P_JCNCTR_ELKCurvatureSup_1pm
#define P_JCNCTR_ELKCurvatureSup_1pm (LCF_CommonParamData.P_JCNCTR_ELKCurvatureSup_1pm) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKCurvatureSup_1pm() (P_JCNCTR_ELKCurvatureSup_1pm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKCurvatureSup_1pm

#ifndef P_JCNCTR_ELKCustom_btm
#define P_JCNCTR_ELKCustom_btm (LCF_CommonParamData.P_JCNCTR_ELKCustom_btm) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKCustom_btm() (P_JCNCTR_ELKCustom_btm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKCustom_btm

#ifndef P_JCNCTR_ELKMainCylPresNoSupDur_sec
#define P_JCNCTR_ELKMainCylPresNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKMainCylPresNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMainCylPresNoSupDur_sec() (P_JCNCTR_ELKMainCylPresNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMainCylPresNoSupDur_sec

#ifndef P_JCNCTR_ELKMainCylPresNoSup_pa
#define P_JCNCTR_ELKMainCylPresNoSup_pa (LCF_CommonParamData.P_JCNCTR_ELKMainCylPresNoSup_pa) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMainCylPresNoSup_pa() (P_JCNCTR_ELKMainCylPresNoSup_pa) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMainCylPresNoSup_pa

#ifndef P_JCNCTR_ELKMainCylPresSupDur_sec
#define P_JCNCTR_ELKMainCylPresSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKMainCylPresSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMainCylPresSupDur_sec() (P_JCNCTR_ELKMainCylPresSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMainCylPresSupDur_sec

#ifndef P_JCNCTR_ELKMainCylPresSup_pa
#define P_JCNCTR_ELKMainCylPresSup_pa (LCF_CommonParamData.P_JCNCTR_ELKMainCylPresSup_pa) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMainCylPresSup_pa() (P_JCNCTR_ELKMainCylPresSup_pa) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMainCylPresSup_pa

#ifndef P_JCNCTR_ELKManualTrqNoSupDur_sec
#define P_JCNCTR_ELKManualTrqNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKManualTrqNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKManualTrqNoSupDur_sec() (P_JCNCTR_ELKManualTrqNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKManualTrqNoSupDur_sec

#ifndef P_JCNCTR_ELKManualTrqNoSup_Nm
#define P_JCNCTR_ELKManualTrqNoSup_Nm (LCF_CommonParamData.P_JCNCTR_ELKManualTrqNoSup_Nm) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKManualTrqNoSup_Nm() (P_JCNCTR_ELKManualTrqNoSup_Nm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKManualTrqNoSup_Nm

#ifndef P_JCNCTR_ELKManualTrqSupDur_sec
#define P_JCNCTR_ELKManualTrqSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKManualTrqSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKManualTrqSupDur_sec() (P_JCNCTR_ELKManualTrqSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKManualTrqSupDur_sec

#ifndef P_JCNCTR_ELKManualTrqSup_Nm
#define P_JCNCTR_ELKManualTrqSup_Nm (LCF_CommonParamData.P_JCNCTR_ELKManualTrqSup_Nm) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKManualTrqSup_Nm() (P_JCNCTR_ELKManualTrqSup_Nm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKManualTrqSup_Nm

#ifndef P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec
#define P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec() (P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMaxLaneWidthNoSupDur_sec

#ifndef P_JCNCTR_ELKMaxLaneWidthNoSup_met
#define P_JCNCTR_ELKMaxLaneWidthNoSup_met (LCF_CommonParamData.P_JCNCTR_ELKMaxLaneWidthNoSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMaxLaneWidthNoSup_met() (P_JCNCTR_ELKMaxLaneWidthNoSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMaxLaneWidthNoSup_met

#ifndef P_JCNCTR_ELKMaxLaneWidthSupDur_sec
#define P_JCNCTR_ELKMaxLaneWidthSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKMaxLaneWidthSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMaxLaneWidthSupDur_sec() (P_JCNCTR_ELKMaxLaneWidthSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMaxLaneWidthSupDur_sec

#ifndef P_JCNCTR_ELKMaxLaneWidthSup_met
#define P_JCNCTR_ELKMaxLaneWidthSup_met (LCF_CommonParamData.P_JCNCTR_ELKMaxLaneWidthSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMaxLaneWidthSup_met() (P_JCNCTR_ELKMaxLaneWidthSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMaxLaneWidthSup_met

#ifndef P_JCNCTR_ELKMinLaneWidthNoSupDur_sec
#define P_JCNCTR_ELKMinLaneWidthNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKMinLaneWidthNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMinLaneWidthNoSupDur_sec() (P_JCNCTR_ELKMinLaneWidthNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMinLaneWidthNoSupDur_sec

#ifndef P_JCNCTR_ELKMinLaneWidthNoSup_met
#define P_JCNCTR_ELKMinLaneWidthNoSup_met (LCF_CommonParamData.P_JCNCTR_ELKMinLaneWidthNoSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMinLaneWidthNoSup_met() (P_JCNCTR_ELKMinLaneWidthNoSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMinLaneWidthNoSup_met

#ifndef P_JCNCTR_ELKMinLaneWidthSupDur_sec
#define P_JCNCTR_ELKMinLaneWidthSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKMinLaneWidthSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMinLaneWidthSupDur_sec() (P_JCNCTR_ELKMinLaneWidthSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMinLaneWidthSupDur_sec

#ifndef P_JCNCTR_ELKMinLaneWidthSup_met
#define P_JCNCTR_ELKMinLaneWidthSup_met (LCF_CommonParamData.P_JCNCTR_ELKMinLaneWidthSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKMinLaneWidthSup_met() (P_JCNCTR_ELKMinLaneWidthSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKMinLaneWidthSup_met

#ifndef P_JCNCTR_ELKYawRateNoSupDur_sec
#define P_JCNCTR_ELKYawRateNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKYawRateNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKYawRateNoSupDur_sec() (P_JCNCTR_ELKYawRateNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKYawRateNoSupDur_sec

#ifndef P_JCNCTR_ELKYawRateNoSup_rps
#define P_JCNCTR_ELKYawRateNoSup_rps (LCF_CommonParamData.P_JCNCTR_ELKYawRateNoSup_rps) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKYawRateNoSup_rps() (P_JCNCTR_ELKYawRateNoSup_rps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKYawRateNoSup_rps

#ifndef P_JCNCTR_ELKYawRateSupDur_sec
#define P_JCNCTR_ELKYawRateSupDur_sec (LCF_CommonParamData.P_JCNCTR_ELKYawRateSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKYawRateSupDur_sec() (P_JCNCTR_ELKYawRateSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKYawRateSupDur_sec

#ifndef P_JCNCTR_ELKYawRateSup_rps
#define P_JCNCTR_ELKYawRateSup_rps (LCF_CommonParamData.P_JCNCTR_ELKYawRateSup_rps) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKYawRateSup_rps() (P_JCNCTR_ELKYawRateSup_rps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKYawRateSup_rps

#ifndef P_JCNCTR_ELKLatVel_mps
#define P_JCNCTR_ELKLatVel_mps (LCF_CommonParamData.P_JCNCTR_ELKLatVel_mps) //!< LCF parameter macro.
#define GET_P_JCNCTR_ELKLatVel_mps() (P_JCNCTR_ELKLatVel_mps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_ELKLatVel_mps

// # date: <2023-06-28>, author: <Jie, Tang>, reason: <C673 & C385: lateral velocity check>
#ifndef P_JCNCTR_VelLatLeRDP_mps
#define P_JCNCTR_VelLatLeRDP_mps (LCF_CommonParamData.P_JCNCTR_VelLatLeRDP_mps) //!< LCF parameter macro.
#define GET_P_JCNCTR_VelLatLeRDP_mps() (P_JCNCTR_VelLatLeRDP_mps)               //!< LCF parameter macro getter.
#endif                                                                          // P_JCNCTR_VelLatLeRDP_mps
#ifndef P_JCNCTR_VelLatRiRDP_mps
#define P_JCNCTR_VelLatRiRDP_mps (LCF_CommonParamData.P_JCNCTR_VelLatRiRDP_mps) //!< LCF parameter macro.
#define GET_P_JCNCTR_VelLatRiRDP_mps() (P_JCNCTR_VelLatRiRDP_mps)               //!< LCF parameter macro getter.
#endif
#ifndef P_JCNCTR_VelLatLeALCA_mps
#define P_JCNCTR_VelLatLeALCA_mps (LCF_CommonParamData.P_JCNCTR_VelLatLeALCA_mps) //!< LCF parameter macro.
#define GET_P_JCNCTR_VelLatLeALCA_mps() (P_JCNCTR_VelLatLeALCA_mps)               //!< LCF parameter macro getter.
#endif
#ifndef P_JCNCTR_VelLatRiALCA_mps
#define P_JCNCTR_VelLatRiALCA_mps (LCF_CommonParamData.P_JCNCTR_VelLatRiALCA_mps) //!< LCF parameter macro.
#define GET_P_JCNCTR_VelLatRiALCA_mps() (P_JCNCTR_VelLatRiALCA_mps)               //!< LCF parameter macro getter.
#endif
// #ifndef P_JCNCTR_LDWAccPedalPosNoSupDur_sec
// #define P_JCNCTR_LDWAccPedalPosNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWAccPedalPosNoSupDur_sec) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LDWAccPedalPosNoSupDur_sec() (P_JCNCTR_LDWAccPedalPosNoSupDur_sec) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LDWAccPedalPosNoSupDur_sec

// #ifndef P_JCNCTR_LDWAccPedalPosNoSup_nu
// #define P_JCNCTR_LDWAccPedalPosNoSup_nu (LCF_CommonParamData.P_JCNCTR_LDWAccPedalPosNoSup_nu) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LDWAccPedalPosNoSup_nu() (P_JCNCTR_LDWAccPedalPosNoSup_nu) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LDWAccPedalPosNoSup_nu

// #ifndef P_JCNCTR_LDWAccPedalPosSupDur_sec
// #define P_JCNCTR_LDWAccPedalPosSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWAccPedalPosSupDur_sec) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LDWAccPedalPosSupDur_sec() (P_JCNCTR_LDWAccPedalPosSupDur_sec) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LDWAccPedalPosSupDur_sec

// #ifndef P_JCNCTR_LDWAccPedalPosSup_nu
// #define P_JCNCTR_LDWAccPedalPosSup_nu (LCF_CommonParamData.P_JCNCTR_LDWAccPedalPosSup_nu) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LDWAccPedalPosSup_nu() (P_JCNCTR_LDWAccPedalPosSup_nu) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LDWAccPedalPosSup_nu

#ifndef P_JCNCTR_LDWActiveStCtrNoSupTime_sec
#define P_JCNCTR_LDWActiveStCtrNoSupTime_sec (LCF_CommonParamData.P_JCNCTR_LDWActiveStCtrNoSupTime_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWActiveStCtrNoSupTime_sec() (P_JCNCTR_LDWActiveStCtrNoSupTime_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWActiveStCtrNoSupTime_sec

#ifndef P_JCNCTR_LDWActiveStCtrSupTime_sec
#define P_JCNCTR_LDWActiveStCtrSupTime_sec (LCF_CommonParamData.P_JCNCTR_LDWActiveStCtrSupTime_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWActiveStCtrSupTime_sec() (P_JCNCTR_LDWActiveStCtrSupTime_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWActiveStCtrSupTime_sec

#ifndef P_JCNCTR_LDWBothLaneInvalidSupDur_sec
#define P_JCNCTR_LDWBothLaneInvalidSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWBothLaneInvalidSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWBothLaneInvalidSupDur_sec() (P_JCNCTR_LDWBothLaneInvalidSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWBothLaneInvalidSupDur_sec

#ifndef P_JCNCTR_LDWBothLaneValidNoSupDur_sec
#define P_JCNCTR_LDWBothLaneValidNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWBothLaneValidNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWBothLaneValidNoSupDur_sec() (P_JCNCTR_LDWBothLaneValidNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWBothLaneValidNoSupDur_sec

#ifndef P_JCNCTR_LDWCurvatureNoSupDur_sec
#define P_JCNCTR_LDWCurvatureNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWCurvatureNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWCurvatureNoSupDur_sec() (P_JCNCTR_LDWCurvatureNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWCurvatureNoSupDur_sec

#ifndef P_JCNCTR_LDWCurvatureNoSup_1pm
#define P_JCNCTR_LDWCurvatureNoSup_1pm (LCF_CommonParamData.P_JCNCTR_LDWCurvatureNoSup_1pm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWCurvatureNoSup_1pm() (P_JCNCTR_LDWCurvatureNoSup_1pm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWCurvatureNoSup_1pm

#ifndef P_JCNCTR_LDWCurvatureSupDur_sec
#define P_JCNCTR_LDWCurvatureSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWCurvatureSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWCurvatureSupDur_sec() (P_JCNCTR_LDWCurvatureSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWCurvatureSupDur_sec

#ifndef P_JCNCTR_LDWCurvatureSup_1pm
#define P_JCNCTR_LDWCurvatureSup_1pm (LCF_CommonParamData.P_JCNCTR_LDWCurvatureSup_1pm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWCurvatureSup_1pm() (P_JCNCTR_LDWCurvatureSup_1pm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWCurvatureSup_1pm

#ifndef P_JCNCTR_LDWCustom_btm
#define P_JCNCTR_LDWCustom_btm (LCF_CommonParamData.P_JCNCTR_LDWCustom_btm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWCustom_btm() (P_JCNCTR_LDWCustom_btm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWCustom_btm

#ifndef P_JCNCTR_LDWMainCylPresNoSupDur_sec
#define P_JCNCTR_LDWMainCylPresNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWMainCylPresNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMainCylPresNoSupDur_sec() (P_JCNCTR_LDWMainCylPresNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMainCylPresNoSupDur_sec

#ifndef P_JCNCTR_LDWMainCylPresNoSup_pa
#define P_JCNCTR_LDWMainCylPresNoSup_pa (LCF_CommonParamData.P_JCNCTR_LDWMainCylPresNoSup_pa) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMainCylPresNoSup_pa() (P_JCNCTR_LDWMainCylPresNoSup_pa) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMainCylPresNoSup_pa

#ifndef P_JCNCTR_LDWMainCylPresSupDur_sec
#define P_JCNCTR_LDWMainCylPresSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWMainCylPresSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMainCylPresSupDur_sec() (P_JCNCTR_LDWMainCylPresSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMainCylPresSupDur_sec

#ifndef P_JCNCTR_LDWMainCylPresSup_pa
#define P_JCNCTR_LDWMainCylPresSup_pa (LCF_CommonParamData.P_JCNCTR_LDWMainCylPresSup_pa) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMainCylPresSup_pa() (P_JCNCTR_LDWMainCylPresSup_pa) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMainCylPresSup_pa

#ifndef P_JCNCTR_LDWManualTrqNoSupDur_sec
#define P_JCNCTR_LDWManualTrqNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWManualTrqNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWManualTrqNoSupDur_sec() (P_JCNCTR_LDWManualTrqNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWManualTrqNoSupDur_sec

#ifndef P_JCNCTR_LDWManualTrqNoSup_Nm
#define P_JCNCTR_LDWManualTrqNoSup_Nm (LCF_CommonParamData.P_JCNCTR_LDWManualTrqNoSup_Nm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWManualTrqNoSup_Nm() (P_JCNCTR_LDWManualTrqNoSup_Nm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWManualTrqNoSup_Nm

#ifndef P_JCNCTR_LDWManualTrqSupDur_sec
#define P_JCNCTR_LDWManualTrqSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWManualTrqSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWManualTrqSupDur_sec() (P_JCNCTR_LDWManualTrqSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWManualTrqSupDur_sec

#ifndef P_JCNCTR_LDWManualTrqSup_Nm
#define P_JCNCTR_LDWManualTrqSup_Nm (LCF_CommonParamData.P_JCNCTR_LDWManualTrqSup_Nm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWManualTrqSup_Nm() (P_JCNCTR_LDWManualTrqSup_Nm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWManualTrqSup_Nm

#ifndef P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec
#define P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec() (P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMaxLaneWidthNoSupDur_sec

#ifndef P_JCNCTR_LDWMaxLaneWidthNoSup_met
#define P_JCNCTR_LDWMaxLaneWidthNoSup_met (LCF_CommonParamData.P_JCNCTR_LDWMaxLaneWidthNoSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMaxLaneWidthNoSup_met() (P_JCNCTR_LDWMaxLaneWidthNoSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMaxLaneWidthNoSup_met

#ifndef P_JCNCTR_LDWMaxLaneWidthSupDur_sec
#define P_JCNCTR_LDWMaxLaneWidthSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWMaxLaneWidthSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMaxLaneWidthSupDur_sec() (P_JCNCTR_LDWMaxLaneWidthSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMaxLaneWidthSupDur_sec

#ifndef P_JCNCTR_LDWMaxLaneWidthSup_met
#define P_JCNCTR_LDWMaxLaneWidthSup_met (LCF_CommonParamData.P_JCNCTR_LDWMaxLaneWidthSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMaxLaneWidthSup_met() (P_JCNCTR_LDWMaxLaneWidthSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMaxLaneWidthSup_met

#ifndef P_JCNCTR_LDWMinLaneWidthNoSupDur_sec
#define P_JCNCTR_LDWMinLaneWidthNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWMinLaneWidthNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMinLaneWidthNoSupDur_sec() (P_JCNCTR_LDWMinLaneWidthNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMinLaneWidthNoSupDur_sec

#ifndef P_JCNCTR_LDWMinLaneWidthNoSup_met
#define P_JCNCTR_LDWMinLaneWidthNoSup_met (LCF_CommonParamData.P_JCNCTR_LDWMinLaneWidthNoSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMinLaneWidthNoSup_met() (P_JCNCTR_LDWMinLaneWidthNoSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMinLaneWidthNoSup_met

#ifndef P_JCNCTR_LDWMinLaneWidthSupDur_sec
#define P_JCNCTR_LDWMinLaneWidthSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWMinLaneWidthSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMinLaneWidthSupDur_sec() (P_JCNCTR_LDWMinLaneWidthSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMinLaneWidthSupDur_sec

#ifndef P_JCNCTR_LDWMinLaneWidthSup_met
#define P_JCNCTR_LDWMinLaneWidthSup_met (LCF_CommonParamData.P_JCNCTR_LDWMinLaneWidthSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWMinLaneWidthSup_met() (P_JCNCTR_LDWMinLaneWidthSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWMinLaneWidthSup_met

#ifndef P_JCNCTR_LDWYawRateNoSupDur_sec
#define P_JCNCTR_LDWYawRateNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWYawRateNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWYawRateNoSupDur_sec() (P_JCNCTR_LDWYawRateNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWYawRateNoSupDur_sec

#ifndef P_JCNCTR_LDWYawRateNoSup_rps
#define P_JCNCTR_LDWYawRateNoSup_rps (LCF_CommonParamData.P_JCNCTR_LDWYawRateNoSup_rps) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWYawRateNoSup_rps() (P_JCNCTR_LDWYawRateNoSup_rps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWYawRateNoSup_rps

#ifndef P_JCNCTR_LDWYawRateSupDur_sec
#define P_JCNCTR_LDWYawRateSupDur_sec (LCF_CommonParamData.P_JCNCTR_LDWYawRateSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWYawRateSupDur_sec() (P_JCNCTR_LDWYawRateSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWYawRateSupDur_sec

#ifndef P_JCNCTR_LDWYawRateSup_rps
#define P_JCNCTR_LDWYawRateSup_rps (LCF_CommonParamData.P_JCNCTR_LDWYawRateSup_rps) //!< LCF parameter macro.
#define GET_P_JCNCTR_LDWYawRateSup_rps() (P_JCNCTR_LDWYawRateSup_rps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LDWYawRateSup_rps

// #ifndef P_JCNCTR_LKAAccPedalPosNoSupDur_sec
// #define P_JCNCTR_LKAAccPedalPosNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAAccPedalPosNoSupDur_sec) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LKAAccPedalPosNoSupDur_sec() (P_JCNCTR_LKAAccPedalPosNoSupDur_sec) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LKAAccPedalPosNoSupDur_sec

// #ifndef P_JCNCTR_LKAAccPedalPosNoSup_nu
// #define P_JCNCTR_LKAAccPedalPosNoSup_nu (LCF_CommonParamData.P_JCNCTR_LKAAccPedalPosNoSup_nu) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LKAAccPedalPosNoSup_nu() (P_JCNCTR_LKAAccPedalPosNoSup_nu) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LKAAccPedalPosNoSup_nu

// #ifndef P_JCNCTR_LKAAccPedalPosSupDur_sec
// #define P_JCNCTR_LKAAccPedalPosSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAAccPedalPosSupDur_sec) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LKAAccPedalPosSupDur_sec() (P_JCNCTR_LKAAccPedalPosSupDur_sec) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LKAAccPedalPosSupDur_sec

// #ifndef P_JCNCTR_LKAAccPedalPosSup_nu
// #define P_JCNCTR_LKAAccPedalPosSup_nu (LCF_CommonParamData.P_JCNCTR_LKAAccPedalPosSup_nu) //!< LCF parameter macro.
// #define GET_P_JCNCTR_LKAAccPedalPosSup_nu() (P_JCNCTR_LKAAccPedalPosSup_nu) //!< LCF parameter macro getter.
// #endif // P_JCNCTR_LKAAccPedalPosSup_nu

#ifndef P_JCNCTR_LKAActiveStCtrNoSupTime_sec
#define P_JCNCTR_LKAActiveStCtrNoSupTime_sec (LCF_CommonParamData.P_JCNCTR_LKAActiveStCtrNoSupTime_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAActiveStCtrNoSupTime_sec() (P_JCNCTR_LKAActiveStCtrNoSupTime_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAActiveStCtrNoSupTime_sec

#ifndef P_JCNCTR_LKAActiveStCtrSupTime_sec
#define P_JCNCTR_LKAActiveStCtrSupTime_sec (LCF_CommonParamData.P_JCNCTR_LKAActiveStCtrSupTime_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAActiveStCtrSupTime_sec() (P_JCNCTR_LKAActiveStCtrSupTime_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAActiveStCtrSupTime_sec

#ifndef P_JCNCTR_LKABothLaneInvalidSupDur_sec
#define P_JCNCTR_LKABothLaneInvalidSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKABothLaneInvalidSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKABothLaneInvalidSupDur_sec() (P_JCNCTR_LKABothLaneInvalidSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKABothLaneInvalidSupDur_sec

#ifndef P_JCNCTR_LKABothLaneValidNoSupDur_sec
#define P_JCNCTR_LKABothLaneValidNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKABothLaneValidNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKABothLaneValidNoSupDur_sec() (P_JCNCTR_LKABothLaneValidNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKABothLaneValidNoSupDur_sec

#ifndef P_JCNCTR_LKACurvatureNoSupDur_sec
#define P_JCNCTR_LKACurvatureNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKACurvatureNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKACurvatureNoSupDur_sec() (P_JCNCTR_LKACurvatureNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKACurvatureNoSupDur_sec

#ifndef P_JCNCTR_LKACurvatureNoSup_1pm
#define P_JCNCTR_LKACurvatureNoSup_1pm (LCF_CommonParamData.P_JCNCTR_LKACurvatureNoSup_1pm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKACurvatureNoSup_1pm() (P_JCNCTR_LKACurvatureNoSup_1pm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKACurvatureNoSup_1pm

#ifndef P_JCNCTR_LKACurvatureSupDur_sec
#define P_JCNCTR_LKACurvatureSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKACurvatureSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKACurvatureSupDur_sec() (P_JCNCTR_LKACurvatureSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKACurvatureSupDur_sec

#ifndef P_JCNCTR_LKACurvatureSup_1pm
#define P_JCNCTR_LKACurvatureSup_1pm (LCF_CommonParamData.P_JCNCTR_LKACurvatureSup_1pm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKACurvatureSup_1pm() (P_JCNCTR_LKACurvatureSup_1pm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKACurvatureSup_1pm

#ifndef P_JCNCTR_LKACustom_btm
#define P_JCNCTR_LKACustom_btm (LCF_CommonParamData.P_JCNCTR_LKACustom_btm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKACustom_btm() (P_JCNCTR_LKACustom_btm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKACustom_btm

#ifndef P_JCNCTR_LKAMainCylPresNoSupDur_sec
#define P_JCNCTR_LKAMainCylPresNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAMainCylPresNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMainCylPresNoSupDur_sec() (P_JCNCTR_LKAMainCylPresNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMainCylPresNoSupDur_sec

#ifndef P_JCNCTR_LKAMainCylPresNoSup_pa
#define P_JCNCTR_LKAMainCylPresNoSup_pa (LCF_CommonParamData.P_JCNCTR_LKAMainCylPresNoSup_pa) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMainCylPresNoSup_pa() (P_JCNCTR_LKAMainCylPresNoSup_pa) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMainCylPresNoSup_pa

#ifndef P_JCNCTR_LKAMainCylPresSupDur_sec
#define P_JCNCTR_LKAMainCylPresSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAMainCylPresSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMainCylPresSupDur_sec() (P_JCNCTR_LKAMainCylPresSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMainCylPresSupDur_sec

#ifndef P_JCNCTR_LKAMainCylPresSup_pa
#define P_JCNCTR_LKAMainCylPresSup_pa (LCF_CommonParamData.P_JCNCTR_LKAMainCylPresSup_pa) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMainCylPresSup_pa() (P_JCNCTR_LKAMainCylPresSup_pa) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMainCylPresSup_pa
// # date: <2023-06-28>, author: <Jie, Tang>, reason: <C673 new requirement: brake pedal distance check>
#ifndef P_JCNCTR_BrakePedalPostionNoSup_mm
#define P_JCNCTR_BrakePedalPostionNoSup_mm (LCF_CommonParamData.P_JCNCTR_BrakePedalPostionNoSup_mm)     //!< LCF parameter macro.
#define GET_P_JCNCTR_BrakePedalPostionNoSup_mm() (P_JCNCTR_BrakePedalPostionNoSup_mm)                   //!< LCF parameter macro getter.
#endif                                                                                             // P_JCNCTR_BrakePedalPostionNoSupDur_sec
#ifndef P_JCNCTR_BrakePedalPostionNoSupDur_sec
#define P_JCNCTR_BrakePedalPostionNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_BrakePedalPostionNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_BrakePedalPostionNoSupDur_sec() (P_JCNCTR_BrakePedalPostionNoSupDur_sec)               //!< LCF parameter macro getter.
#endif
#ifndef P_JCNCTR_BrakePedalPostionSupDur_sec
#define P_JCNCTR_BrakePedalPostionSupDur_sec (LCF_CommonParamData.P_JCNCTR_BrakePedalPostionSupDur_sec)     //!< LCF parameter macro.
#define GET_P_JCNCTR_BrakePedalPostionSupDur_sec() (P_JCNCTR_BrakePedalPostionSupDur_sec)                   //!< LCF parameter macro getter.
#endif
#ifndef P_JCNCTR_BrakePedalPostionSup_mm
#define P_JCNCTR_BrakePedalPostionSup_mm (LCF_CommonParamData.P_JCNCTR_BrakePedalPostionSup_mm)     //!< LCF parameter macro.
#define GET_P_JCNCTR_BrakePedalPostionSup_mm() (P_JCNCTR_BrakePedalPostionSup_mm)                   //!< LCF parameter macro getter.
#endif

#ifndef P_JCNCTR_LKAManualTrqNoSupDur_sec
#define P_JCNCTR_LKAManualTrqNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAManualTrqNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAManualTrqNoSupDur_sec() (P_JCNCTR_LKAManualTrqNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAManualTrqNoSupDur_sec

#ifndef P_JCNCTR_LKAManualTrqNoSup_Nm
#define P_JCNCTR_LKAManualTrqNoSup_Nm (LCF_CommonParamData.P_JCNCTR_LKAManualTrqNoSup_Nm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAManualTrqNoSup_Nm() (P_JCNCTR_LKAManualTrqNoSup_Nm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAManualTrqNoSup_Nm

#ifndef P_JCNCTR_LKAManualTrqSupDur_sec
#define P_JCNCTR_LKAManualTrqSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAManualTrqSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAManualTrqSupDur_sec() (P_JCNCTR_LKAManualTrqSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAManualTrqSupDur_sec

#ifndef P_JCNCTR_LKAManualTrqSup_Nm
#define P_JCNCTR_LKAManualTrqSup_Nm (LCF_CommonParamData.P_JCNCTR_LKAManualTrqSup_Nm) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAManualTrqSup_Nm() (P_JCNCTR_LKAManualTrqSup_Nm) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAManualTrqSup_Nm

#ifndef P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec
#define P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec() (P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMaxLaneWidthNoSupDur_sec

#ifndef P_JCNCTR_LKAMaxLaneWidthNoSup_met
#define P_JCNCTR_LKAMaxLaneWidthNoSup_met (LCF_CommonParamData.P_JCNCTR_LKAMaxLaneWidthNoSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMaxLaneWidthNoSup_met() (P_JCNCTR_LKAMaxLaneWidthNoSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMaxLaneWidthNoSup_met

#ifndef P_JCNCTR_LKAMaxLaneWidthSupDur_sec
#define P_JCNCTR_LKAMaxLaneWidthSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAMaxLaneWidthSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMaxLaneWidthSupDur_sec() (P_JCNCTR_LKAMaxLaneWidthSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMaxLaneWidthSupDur_sec

#ifndef P_JCNCTR_LKAMaxLaneWidthSup_met
#define P_JCNCTR_LKAMaxLaneWidthSup_met (LCF_CommonParamData.P_JCNCTR_LKAMaxLaneWidthSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMaxLaneWidthSup_met() (P_JCNCTR_LKAMaxLaneWidthSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMaxLaneWidthSup_met

#ifndef P_JCNCTR_LKAMinLaneWidthNoSupDur_sec
#define P_JCNCTR_LKAMinLaneWidthNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAMinLaneWidthNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMinLaneWidthNoSupDur_sec() (P_JCNCTR_LKAMinLaneWidthNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMinLaneWidthNoSupDur_sec

#ifndef P_JCNCTR_LKAMinLaneWidthNoSup_met
#define P_JCNCTR_LKAMinLaneWidthNoSup_met (LCF_CommonParamData.P_JCNCTR_LKAMinLaneWidthNoSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMinLaneWidthNoSup_met() (P_JCNCTR_LKAMinLaneWidthNoSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMinLaneWidthNoSup_met

#ifndef P_JCNCTR_LKAMinLaneWidthSupDur_sec
#define P_JCNCTR_LKAMinLaneWidthSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAMinLaneWidthSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMinLaneWidthSupDur_sec() (P_JCNCTR_LKAMinLaneWidthSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMinLaneWidthSupDur_sec

#ifndef P_JCNCTR_LKAMinLaneWidthSup_met
#define P_JCNCTR_LKAMinLaneWidthSup_met (LCF_CommonParamData.P_JCNCTR_LKAMinLaneWidthSup_met) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAMinLaneWidthSup_met() (P_JCNCTR_LKAMinLaneWidthSup_met) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAMinLaneWidthSup_met

#ifndef P_JCNCTR_LKAYawRateNoSupDur_sec
#define P_JCNCTR_LKAYawRateNoSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAYawRateNoSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAYawRateNoSupDur_sec() (P_JCNCTR_LKAYawRateNoSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAYawRateNoSupDur_sec

#ifndef P_JCNCTR_LKAYawRateNoSup_rps
#define P_JCNCTR_LKAYawRateNoSup_rps (LCF_CommonParamData.P_JCNCTR_LKAYawRateNoSup_rps) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAYawRateNoSup_rps() (P_JCNCTR_LKAYawRateNoSup_rps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAYawRateNoSup_rps

#ifndef P_JCNCTR_LKAYawRateSupDur_sec
#define P_JCNCTR_LKAYawRateSupDur_sec (LCF_CommonParamData.P_JCNCTR_LKAYawRateSupDur_sec) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAYawRateSupDur_sec() (P_JCNCTR_LKAYawRateSupDur_sec) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAYawRateSupDur_sec

#ifndef P_JCNCTR_LKAYawRateSup_rps
#define P_JCNCTR_LKAYawRateSup_rps (LCF_CommonParamData.P_JCNCTR_LKAYawRateSup_rps) //!< LCF parameter macro.
#define GET_P_JCNCTR_LKAYawRateSup_rps() (P_JCNCTR_LKAYawRateSup_rps) //!< LCF parameter macro getter.
#endif // P_JCNCTR_LKAYawRateSup_rps

#ifndef P_LCRSIA_AclXHyst_mps2
#define P_LCRSIA_AclXHyst_mps2 (LCF_CommonParamData.P_LCRSIA_AclXHyst_mps2) //!< LCF parameter macro.
#define GET_P_LCRSIA_AclXHyst_mps2() (P_LCRSIA_AclXHyst_mps2) //!< LCF parameter macro getter.
#endif // P_LCRSIA_AclXHyst_mps2

#ifndef P_LCRSIA_AclXMax_mps2
#define P_LCRSIA_AclXMax_mps2 (LCF_CommonParamData.P_LCRSIA_AclXMax_mps2) //!< LCF parameter macro.
#define GET_P_LCRSIA_AclXMax_mps2() (P_LCRSIA_AclXMax_mps2) //!< LCF parameter macro getter.
#endif // P_LCRSIA_AclXMax_mps2

#ifndef P_LCRSIA_AclXMin_mps2
#define P_LCRSIA_AclXMin_mps2 (LCF_CommonParamData.P_LCRSIA_AclXMin_mps2) //!< LCF parameter macro.
#define GET_P_LCRSIA_AclXMin_mps2() (P_LCRSIA_AclXMin_mps2) //!< LCF parameter macro getter.
#endif // P_LCRSIA_AclXMin_mps2

#ifndef P_LCRSIA_AclYHyst_mps2
#define P_LCRSIA_AclYHyst_mps2 (LCF_CommonParamData.P_LCRSIA_AclYHyst_mps2) //!< LCF parameter macro.
#define GET_P_LCRSIA_AclYHyst_mps2() (P_LCRSIA_AclYHyst_mps2) //!< LCF parameter macro getter.
#endif // P_LCRSIA_AclYHyst_mps2

#ifndef P_LCRSIA_AclYMax_mps2
#define P_LCRSIA_AclYMax_mps2 (LCF_CommonParamData.P_LCRSIA_AclYMax_mps2) //!< LCF parameter macro.
#define GET_P_LCRSIA_AclYMax_mps2() (P_LCRSIA_AclYMax_mps2) //!< LCF parameter macro getter.
#endif // P_LCRSIA_AclYMax_mps2

#ifndef P_LCRSIA_ConstrSite_bool
#define P_LCRSIA_ConstrSite_bool (LCF_CommonParamData.P_LCRSIA_ConstrSite_bool) //!< LCF parameter macro.
#define GET_P_LCRSIA_ConstrSite_bool() (P_LCRSIA_ConstrSite_bool) //!< LCF parameter macro getter.
#endif // P_LCRSIA_ConstrSite_bool

#ifndef P_LCRSIA_CurveDetectThreshold_1pm
#define P_LCRSIA_CurveDetectThreshold_1pm (LCF_CommonParamData.P_LCRSIA_CurveDetectThreshold_1pm) //!< LCF parameter macro.
#define GET_P_LCRSIA_CurveDetectThreshold_1pm() (P_LCRSIA_CurveDetectThreshold_1pm) //!< LCF parameter macro getter.
#endif // P_LCRSIA_CurveDetectThreshold_1pm

#ifndef P_LCRSIA_HeadAngThresALCAHyst_rad
#define P_LCRSIA_HeadAngThresALCAHyst_rad (LCF_CommonParamData.P_LCRSIA_HeadAngThresALCAHyst_rad) //!< LCF parameter macro.
#define GET_P_LCRSIA_HeadAngThresALCAHyst_rad() (P_LCRSIA_HeadAngThresALCAHyst_rad) //!< LCF parameter macro getter.
#endif // P_LCRSIA_HeadAngThresALCAHyst_rad

#ifndef P_LCRSIA_HeadAngThresALCAMax_rad
#define P_LCRSIA_HeadAngThresALCAMax_rad (LCF_CommonParamData.P_LCRSIA_HeadAngThresALCAMax_rad) //!< LCF parameter macro.
#define GET_P_LCRSIA_HeadAngThresALCAMax_rad() (P_LCRSIA_HeadAngThresALCAMax_rad) //!< LCF parameter macro getter.
#endif // P_LCRSIA_HeadAngThresALCAMax_rad

#ifndef P_LCRSIA_HeadAngThresALCAMin_rad
#define P_LCRSIA_HeadAngThresALCAMin_rad (LCF_CommonParamData.P_LCRSIA_HeadAngThresALCAMin_rad) //!< LCF parameter macro.
#define GET_P_LCRSIA_HeadAngThresALCAMin_rad() (P_LCRSIA_HeadAngThresALCAMin_rad) //!< LCF parameter macro getter.
#endif // P_LCRSIA_HeadAngThresALCAMin_rad

#ifndef P_LCRSIA_LaneBitmask_btm
#define P_LCRSIA_LaneBitmask_btm (LCF_CommonParamData.P_LCRSIA_LaneBitmask_btm) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneBitmask_btm() (P_LCRSIA_LaneBitmask_btm) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneBitmask_btm

#ifndef P_LCRSIA_LaneCancelBitmask_btm
#define P_LCRSIA_LaneCancelBitmask_btm (LCF_CommonParamData.P_LCRSIA_LaneCancelBitmask_btm) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneCancelBitmask_btm() (P_LCRSIA_LaneCancelBitmask_btm) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneCancelBitmask_btm

#ifndef P_LCRSIA_LaneSafetyBitmask_btm
#define P_LCRSIA_LaneSafetyBitmask_btm (LCF_CommonParamData.P_LCRSIA_LaneSafetyBitmask_btm) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneSafetyBitmask_btm() (P_LCRSIA_LaneSafetyBitmask_btm) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneSafetyBitmask_btm

#ifndef P_LCRSIA_LaneWidthALCAHyst_met
#define P_LCRSIA_LaneWidthALCAHyst_met (LCF_CommonParamData.P_LCRSIA_LaneWidthALCAHyst_met) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneWidthALCAHyst_met() (P_LCRSIA_LaneWidthALCAHyst_met) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneWidthALCAHyst_met

#ifndef P_LCRSIA_LaneWidthALCAMax_met
#define P_LCRSIA_LaneWidthALCAMax_met (LCF_CommonParamData.P_LCRSIA_LaneWidthALCAMax_met) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneWidthALCAMax_met() (P_LCRSIA_LaneWidthALCAMax_met) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneWidthALCAMax_met

#ifndef P_LCRSIA_LaneWidthALCAMin_met
#define P_LCRSIA_LaneWidthALCAMin_met (LCF_CommonParamData.P_LCRSIA_LaneWidthALCAMin_met) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneWidthALCAMin_met() (P_LCRSIA_LaneWidthALCAMin_met) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneWidthALCAMin_met

#ifndef P_LCRSIA_LaneWidthSIFOn_bool
#define P_LCRSIA_LaneWidthSIFOn_bool (LCF_CommonParamData.P_LCRSIA_LaneWidthSIFOn_bool) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneWidthSIFOn_bool() (P_LCRSIA_LaneWidthSIFOn_bool) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneWidthSIFOn_bool

#ifndef P_LCRSIA_LaneWidthWideLnDef_met
#define P_LCRSIA_LaneWidthWideLnDef_met (LCF_CommonParamData.P_LCRSIA_LaneWidthWideLnDef_met) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneWidthWideLnDef_met() (P_LCRSIA_LaneWidthWideLnDef_met) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneWidthWideLnDef_met

#ifndef P_LCRSIA_LaneWidthWideLn_bool
#define P_LCRSIA_LaneWidthWideLn_bool (LCF_CommonParamData.P_LCRSIA_LaneWidthWideLn_bool) //!< LCF parameter macro.
#define GET_P_LCRSIA_LaneWidthWideLn_bool() (P_LCRSIA_LaneWidthWideLn_bool) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LaneWidthWideLn_bool

#ifndef P_LCRSIA_LnBndTurnOnTime_sec
#define P_LCRSIA_LnBndTurnOnTime_sec (LCF_CommonParamData.P_LCRSIA_LnBndTurnOnTime_sec) //!< LCF parameter macro.
#define GET_P_LCRSIA_LnBndTurnOnTime_sec() (P_LCRSIA_LnBndTurnOnTime_sec) //!< LCF parameter macro getter.
#endif // P_LCRSIA_LnBndTurnOnTime_sec

#ifndef P_LCRSIA_SafetyIfaceALCAOn_bool
#define P_LCRSIA_SafetyIfaceALCAOn_bool (LCF_CommonParamData.P_LCRSIA_SafetyIfaceALCAOn_bool) //!< LCF parameter macro.
#define GET_P_LCRSIA_SafetyIfaceALCAOn_bool() (P_LCRSIA_SafetyIfaceALCAOn_bool) //!< LCF parameter macro getter.
#endif // P_LCRSIA_SafetyIfaceALCAOn_bool

#ifndef P_LCRSIA_StrWhlAngSpeedALCAHyst_degps
#define P_LCRSIA_StrWhlAngSpeedALCAHyst_degps (LCF_CommonParamData.P_LCRSIA_StrWhlAngSpeedALCAHyst_degps) //!< LCF parameter macro.
#define GET_P_LCRSIA_StrWhlAngSpeedALCAHyst_degps() (P_LCRSIA_StrWhlAngSpeedALCAHyst_degps) //!< LCF parameter macro getter.
#endif // P_LCRSIA_StrWhlAngSpeedALCAHyst_degps

#ifndef P_LCRSIA_StrWhlAngSpeedALCAMax_degps
#define P_LCRSIA_StrWhlAngSpeedALCAMax_degps (LCF_CommonParamData.P_LCRSIA_StrWhlAngSpeedALCAMax_degps) //!< LCF parameter macro.
#define GET_P_LCRSIA_StrWhlAngSpeedALCAMax_degps() (P_LCRSIA_StrWhlAngSpeedALCAMax_degps) //!< LCF parameter macro getter.
#endif // P_LCRSIA_StrWhlAngSpeedALCAMax_degps

#ifndef P_LCRSIA_StrWhlAngleALCAHyst_deg
#define P_LCRSIA_StrWhlAngleALCAHyst_deg (LCF_CommonParamData.P_LCRSIA_StrWhlAngleALCAHyst_deg) //!< LCF parameter macro.
#define GET_P_LCRSIA_StrWhlAngleALCAHyst_deg() (P_LCRSIA_StrWhlAngleALCAHyst_deg) //!< LCF parameter macro getter.
#endif // P_LCRSIA_StrWhlAngleALCAHyst_deg

#ifndef P_LCRSIA_StrWhlAngleALCAMax_deg
#define P_LCRSIA_StrWhlAngleALCAMax_deg (LCF_CommonParamData.P_LCRSIA_StrWhlAngleALCAMax_deg) //!< LCF parameter macro.
#define GET_P_LCRSIA_StrWhlAngleALCAMax_deg() (P_LCRSIA_StrWhlAngleALCAMax_deg) //!< LCF parameter macro getter.
#endif // P_LCRSIA_StrWhlAngleALCAMax_deg

#ifndef P_LCRSIA_TlcHeadAngThres_rad
#define P_LCRSIA_TlcHeadAngThres_rad (LCF_CommonParamData.P_LCRSIA_TlcHeadAngThres_rad) //!< LCF parameter macro.
#define GET_P_LCRSIA_TlcHeadAngThres_rad() (P_LCRSIA_TlcHeadAngThres_rad) //!< LCF parameter macro getter.
#endif // P_LCRSIA_TlcHeadAngThres_rad

#ifndef P_LCRSIA_TurnSignHoldingTime_sec
#define P_LCRSIA_TurnSignHoldingTime_sec (LCF_CommonParamData.P_LCRSIA_TurnSignHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_LCRSIA_TurnSignHoldingTime_sec() (P_LCRSIA_TurnSignHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_LCRSIA_TurnSignHoldingTime_sec

#ifndef P_LCRSIA_TurnSignReset_bool
#define P_LCRSIA_TurnSignReset_bool (LCF_CommonParamData.P_LCRSIA_TurnSignReset_bool) //!< LCF parameter macro.
#define GET_P_LCRSIA_TurnSignReset_bool() (P_LCRSIA_TurnSignReset_bool) //!< LCF parameter macro getter.
#endif // P_LCRSIA_TurnSignReset_bool

#ifndef P_LCRSIA_UncoupledLWEnable_bool
#define P_LCRSIA_UncoupledLWEnable_bool (LCF_CommonParamData.P_LCRSIA_UncoupledLWEnable_bool) //!< LCF parameter macro.
#define GET_P_LCRSIA_UncoupledLWEnable_bool() (P_LCRSIA_UncoupledLWEnable_bool) //!< LCF parameter macro getter.
#endif // P_LCRSIA_UncoupledLWEnable_bool

#ifndef P_LCRSIA_VelDispALCAHyst_kph
#define P_LCRSIA_VelDispALCAHyst_kph (LCF_CommonParamData.P_LCRSIA_VelDispALCAHyst_kph) //!< LCF parameter macro.
#define GET_P_LCRSIA_VelDispALCAHyst_kph() (P_LCRSIA_VelDispALCAHyst_kph) //!< LCF parameter macro getter.
#endif // P_LCRSIA_VelDispALCAHyst_kph

#ifndef P_LCRSIA_VelDispALCAMax_kph
#define P_LCRSIA_VelDispALCAMax_kph (LCF_CommonParamData.P_LCRSIA_VelDispALCAMax_kph) //!< LCF parameter macro.
#define GET_P_LCRSIA_VelDispALCAMax_kph() (P_LCRSIA_VelDispALCAMax_kph) //!< LCF parameter macro getter.
#endif // P_LCRSIA_VelDispALCAMax_kph

#ifndef P_LCRSIA_VelDispALCAMin_kph
#define P_LCRSIA_VelDispALCAMin_kph (LCF_CommonParamData.P_LCRSIA_VelDispALCAMin_kph) //!< LCF parameter macro.
#define GET_P_LCRSIA_VelDispALCAMin_kph() (P_LCRSIA_VelDispALCAMin_kph) //!< LCF parameter macro getter.
#endif // P_LCRSIA_VelDispALCAMin_kph

#ifndef P_LCRSIA_VelLatThresALCAHyst_mps
#define P_LCRSIA_VelLatThresALCAHyst_mps (LCF_CommonParamData.P_LCRSIA_VelLatThresALCAHyst_mps) //!< LCF parameter macro.
#define GET_P_LCRSIA_VelLatThresALCAHyst_mps() (P_LCRSIA_VelLatThresALCAHyst_mps) //!< LCF parameter macro getter.
#endif // P_LCRSIA_VelLatThresALCAHyst_mps

#ifndef P_LCRSIA_VelLatThresALCAMax_mps
#define P_LCRSIA_VelLatThresALCAMax_mps (LCF_CommonParamData.P_LCRSIA_VelLatThresALCAMax_mps) //!< LCF parameter macro.
#define GET_P_LCRSIA_VelLatThresALCAMax_mps() (P_LCRSIA_VelLatThresALCAMax_mps) //!< LCF parameter macro getter.
#endif // P_LCRSIA_VelLatThresALCAMax_mps

#ifndef P_LCRSIA_VelLatThresALCAMin_mps
#define P_LCRSIA_VelLatThresALCAMin_mps (LCF_CommonParamData.P_LCRSIA_VelLatThresALCAMin_mps) //!< LCF parameter macro.
#define GET_P_LCRSIA_VelLatThresALCAMin_mps() (P_LCRSIA_VelLatThresALCAMin_mps) //!< LCF parameter macro getter.
#endif // P_LCRSIA_VelLatThresALCAMin_mps

#ifndef P_LCRSMI_ALCALightEnable_bool
#define P_LCRSMI_ALCALightEnable_bool (LCF_CommonParamData.P_LCRSMI_ALCALightEnable_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_ALCALightEnable_bool() (P_LCRSMI_ALCALightEnable_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_ALCALightEnable_bool

#ifndef P_LCRSMI_ALCASwitchEnable_bool
#define P_LCRSMI_ALCASwitchEnable_bool (LCF_CommonParamData.P_LCRSMI_ALCASwitchEnable_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_ALCASwitchEnable_bool() (P_LCRSMI_ALCASwitchEnable_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_ALCASwitchEnable_bool

#ifndef P_LCRSMI_ALCASwitch_bool
#define P_LCRSMI_ALCASwitch_bool (LCF_CommonParamData.P_LCRSMI_ALCASwitch_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_ALCASwitch_bool() (P_LCRSMI_ALCASwitch_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_ALCASwitch_bool

#ifndef P_LCRSMI_AbortDrvSt_btm
#define P_LCRSMI_AbortDrvSt_btm (LCF_CommonParamData.P_LCRSMI_AbortDrvSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortDrvSt_btm() (P_LCRSMI_AbortDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortDrvSt_btm

#ifndef P_LCRSMI_AbortFctCustom_btm
#define P_LCRSMI_AbortFctCustom_btm (LCF_CommonParamData.P_LCRSMI_AbortFctCustom_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortFctCustom_btm() (P_LCRSMI_AbortFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortFctCustom_btm

#ifndef P_LCRSMI_AbortFctStCtr_btm
#define P_LCRSMI_AbortFctStCtr_btm (LCF_CommonParamData.P_LCRSMI_AbortFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortFctStCtr_btm() (P_LCRSMI_AbortFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortFctStCtr_btm

#ifndef P_LCRSMI_AbortFctStErr_btm
#define P_LCRSMI_AbortFctStErr_btm (LCF_CommonParamData.P_LCRSMI_AbortFctStErr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortFctStErr_btm() (P_LCRSMI_AbortFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortFctStErr_btm

#ifndef P_LCRSMI_AbortFctStNotAv_btm
#define P_LCRSMI_AbortFctStNotAv_btm (LCF_CommonParamData.P_LCRSMI_AbortFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortFctStNotAv_btm() (P_LCRSMI_AbortFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortFctStNotAv_btm

#ifndef P_LCRSMI_AbortSpecific_btm
#define P_LCRSMI_AbortSpecific_btm (LCF_CommonParamData.P_LCRSMI_AbortSpecific_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortSpecific_btm() (P_LCRSMI_AbortSpecific_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortSpecific_btm

#ifndef P_LCRSMI_AbortVehSt_btm
#define P_LCRSMI_AbortVehSt_btm (LCF_CommonParamData.P_LCRSMI_AbortVehSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_AbortVehSt_btm() (P_LCRSMI_AbortVehSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_AbortVehSt_btm

#ifndef P_LCRSMI_BVDanRearObjBSRearLe_bool
#define P_LCRSMI_BVDanRearObjBSRearLe_bool (LCF_CommonParamData.P_LCRSMI_BVDanRearObjBSRearLe_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVDanRearObjBSRearLe_bool() (P_LCRSMI_BVDanRearObjBSRearLe_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVDanRearObjBSRearLe_bool

#ifndef P_LCRSMI_BVDanRearObjBSRearRi_bool
#define P_LCRSMI_BVDanRearObjBSRearRi_bool (LCF_CommonParamData.P_LCRSMI_BVDanRearObjBSRearRi_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVDanRearObjBSRearRi_bool() (P_LCRSMI_BVDanRearObjBSRearRi_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVDanRearObjBSRearRi_bool

#ifndef P_LCRSMI_BVDanRearObjFOVRearLe_bool
#define P_LCRSMI_BVDanRearObjFOVRearLe_bool (LCF_CommonParamData.P_LCRSMI_BVDanRearObjFOVRearLe_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVDanRearObjFOVRearLe_bool() (P_LCRSMI_BVDanRearObjFOVRearLe_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVDanRearObjFOVRearLe_bool

#ifndef P_LCRSMI_BVDanRearObjFOVRearRi_bool
#define P_LCRSMI_BVDanRearObjFOVRearRi_bool (LCF_CommonParamData.P_LCRSMI_BVDanRearObjFOVRearRi_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVDanRearObjFOVRearRi_bool() (P_LCRSMI_BVDanRearObjFOVRearRi_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVDanRearObjFOVRearRi_bool

#ifndef P_LCRSMI_BVQualifRearLe_bool
#define P_LCRSMI_BVQualifRearLe_bool (LCF_CommonParamData.P_LCRSMI_BVQualifRearLe_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVQualifRearLe_bool() (P_LCRSMI_BVQualifRearLe_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVQualifRearLe_bool

#ifndef P_LCRSMI_BVQualifRearRi_bool
#define P_LCRSMI_BVQualifRearRi_bool (LCF_CommonParamData.P_LCRSMI_BVQualifRearRi_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVQualifRearRi_bool() (P_LCRSMI_BVQualifRearRi_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVQualifRearRi_bool

#ifndef P_LCRSMI_BVSopMSFlagRearLe_bool
#define P_LCRSMI_BVSopMSFlagRearLe_bool (LCF_CommonParamData.P_LCRSMI_BVSopMSFlagRearLe_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVSopMSFlagRearLe_bool() (P_LCRSMI_BVSopMSFlagRearLe_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVSopMSFlagRearLe_bool

#ifndef P_LCRSMI_BVSopMSFlagRearRi_bool
#define P_LCRSMI_BVSopMSFlagRearRi_bool (LCF_CommonParamData.P_LCRSMI_BVSopMSFlagRearRi_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BVSopMSFlagRearRi_bool() (P_LCRSMI_BVSopMSFlagRearRi_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BVSopMSFlagRearRi_bool

#ifndef P_LCRSMI_BlockingTimeDuration_sec
#define P_LCRSMI_BlockingTimeDuration_sec (LCF_CommonParamData.P_LCRSMI_BlockingTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_BlockingTimeDuration_sec() (P_LCRSMI_BlockingTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BlockingTimeDuration_sec

#ifndef P_LCRSMI_BypassSRRSignal_bool
#define P_LCRSMI_BypassSRRSignal_bool (LCF_CommonParamData.P_LCRSMI_BypassSRRSignal_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_BypassSRRSignal_bool() (P_LCRSMI_BypassSRRSignal_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_BypassSRRSignal_bool

#ifndef P_LCRSMI_CancelDrvSt_btm
#define P_LCRSMI_CancelDrvSt_btm (LCF_CommonParamData.P_LCRSMI_CancelDrvSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelDrvSt_btm() (P_LCRSMI_CancelDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelDrvSt_btm

#ifndef P_LCRSMI_CancelFctCustomLe_btm
#define P_LCRSMI_CancelFctCustomLe_btm (LCF_CommonParamData.P_LCRSMI_CancelFctCustomLe_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelFctCustomLe_btm() (P_LCRSMI_CancelFctCustomLe_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelFctCustomLe_btm

#ifndef P_LCRSMI_CancelFctCustomRi_btm
#define P_LCRSMI_CancelFctCustomRi_btm (LCF_CommonParamData.P_LCRSMI_CancelFctCustomRi_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelFctCustomRi_btm() (P_LCRSMI_CancelFctCustomRi_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelFctCustomRi_btm

#ifndef P_LCRSMI_CancelFctCustom_btm
#define P_LCRSMI_CancelFctCustom_btm (LCF_CommonParamData.P_LCRSMI_CancelFctCustom_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelFctCustom_btm() (P_LCRSMI_CancelFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelFctCustom_btm

#ifndef P_LCRSMI_CancelFctStCtr_btm
#define P_LCRSMI_CancelFctStCtr_btm (LCF_CommonParamData.P_LCRSMI_CancelFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelFctStCtr_btm() (P_LCRSMI_CancelFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelFctStCtr_btm

#ifndef P_LCRSMI_CancelFctStErr_btm
#define P_LCRSMI_CancelFctStErr_btm (LCF_CommonParamData.P_LCRSMI_CancelFctStErr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelFctStErr_btm() (P_LCRSMI_CancelFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelFctStErr_btm

#ifndef P_LCRSMI_CancelFctStNotAv_btm
#define P_LCRSMI_CancelFctStNotAv_btm (LCF_CommonParamData.P_LCRSMI_CancelFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelFctStNotAv_btm() (P_LCRSMI_CancelFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelFctStNotAv_btm

#ifndef P_LCRSMI_CancelSpecific_btm
#define P_LCRSMI_CancelSpecific_btm (LCF_CommonParamData.P_LCRSMI_CancelSpecific_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelSpecific_btm() (P_LCRSMI_CancelSpecific_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelSpecific_btm

#ifndef P_LCRSMI_CancelVehSt_btm
#define P_LCRSMI_CancelVehSt_btm (LCF_CommonParamData.P_LCRSMI_CancelVehSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_CancelVehSt_btm() (P_LCRSMI_CancelVehSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_CancelVehSt_btm

#ifndef P_LCRSMI_ControllingMaxDuration_sec
#define P_LCRSMI_ControllingMaxDuration_sec (LCF_CommonParamData.P_LCRSMI_ControllingMaxDuration_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_ControllingMaxDuration_sec() (P_LCRSMI_ControllingMaxDuration_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_ControllingMaxDuration_sec

#ifndef P_LCRSMI_DebugDrvSt_btm
#define P_LCRSMI_DebugDrvSt_btm (LCF_CommonParamData.P_LCRSMI_DebugDrvSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_DebugDrvSt_btm() (P_LCRSMI_DebugDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_DebugDrvSt_btm

#ifndef P_LCRSMI_DebugSpecific_btm
#define P_LCRSMI_DebugSpecific_btm (LCF_CommonParamData.P_LCRSMI_DebugSpecific_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_DebugSpecific_btm() (P_LCRSMI_DebugSpecific_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_DebugSpecific_btm

#ifndef P_LCRSMI_DegrTimeOut_sec
#define P_LCRSMI_DegrTimeOut_sec (LCF_CommonParamData.P_LCRSMI_DegrTimeOut_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_DegrTimeOut_sec() (P_LCRSMI_DegrTimeOut_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_DegrTimeOut_sec

#ifndef P_LCRSMI_DlcLimitMax_met
#define P_LCRSMI_DlcLimitMax_met (LCF_CommonParamData.P_LCRSMI_DlcLimitMax_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_DlcLimitMax_met() (P_LCRSMI_DlcLimitMax_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_DlcLimitMax_met

#ifndef P_LCRSMI_DlcLimitMin_met
#define P_LCRSMI_DlcLimitMin_met (LCF_CommonParamData.P_LCRSMI_DlcLimitMin_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_DlcLimitMin_met() (P_LCRSMI_DlcLimitMin_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_DlcLimitMin_met

#ifndef P_LCRSMI_ErrorStateALCAEnable_bool
#define P_LCRSMI_ErrorStateALCAEnable_bool (LCF_CommonParamData.P_LCRSMI_ErrorStateALCAEnable_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_ErrorStateALCAEnable_bool() (P_LCRSMI_ErrorStateALCAEnable_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_ErrorStateALCAEnable_bool

#ifndef P_LCRSMI_ErrorStateALCA_bool
#define P_LCRSMI_ErrorStateALCA_bool (LCF_CommonParamData.P_LCRSMI_ErrorStateALCA_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_ErrorStateALCA_bool() (P_LCRSMI_ErrorStateALCA_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_ErrorStateALCA_bool

#ifndef P_LCRSMI_FctCustomTrgLe_btm
#define P_LCRSMI_FctCustomTrgLe_btm (LCF_CommonParamData.P_LCRSMI_FctCustomTrgLe_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_FctCustomTrgLe_btm() (P_LCRSMI_FctCustomTrgLe_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_FctCustomTrgLe_btm

#ifndef P_LCRSMI_FctCustomTrgRi_btm
#define P_LCRSMI_FctCustomTrgRi_btm (LCF_CommonParamData.P_LCRSMI_FctCustomTrgRi_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_FctCustomTrgRi_btm() (P_LCRSMI_FctCustomTrgRi_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_FctCustomTrgRi_btm

#ifndef P_LCRSMI_FinishCondEnable_btm
#define P_LCRSMI_FinishCondEnable_btm (LCF_CommonParamData.P_LCRSMI_FinishCondEnable_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_FinishCondEnable_btm() (P_LCRSMI_FinishCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_FinishCondEnable_btm

#ifndef P_LCRSMI_HazardCancelTol_met
#define P_LCRSMI_HazardCancelTol_met (LCF_CommonParamData.P_LCRSMI_HazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_HazardCancelTol_met() (P_LCRSMI_HazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_HazardCancelTol_met

#ifndef P_LCRSMI_HazardFinishDlc_met
#define P_LCRSMI_HazardFinishDlc_met (LCF_CommonParamData.P_LCRSMI_HazardFinishDlc_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_HazardFinishDlc_met() (P_LCRSMI_HazardFinishDlc_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_HazardFinishDlc_met

#ifndef P_LCRSMI_HazardFinishHeadAng_rad
#define P_LCRSMI_HazardFinishHeadAng_rad (LCF_CommonParamData.P_LCRSMI_HazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_LCRSMI_HazardFinishHeadAng_rad() (P_LCRSMI_HazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_LCRSMI_HazardFinishHeadAng_rad

#ifndef P_LCRSMI_HazardFinishTol_met
#define P_LCRSMI_HazardFinishTol_met (LCF_CommonParamData.P_LCRSMI_HazardFinishTol_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_HazardFinishTol_met() (P_LCRSMI_HazardFinishTol_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_HazardFinishTol_met

#ifndef P_LCRSMI_HazardFinishVelLat_mps
#define P_LCRSMI_HazardFinishVelLat_mps (LCF_CommonParamData.P_LCRSMI_HazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_LCRSMI_HazardFinishVelLat_mps() (P_LCRSMI_HazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_LCRSMI_HazardFinishVelLat_mps

#ifndef P_LCRSMI_LatDMCClearEnable_bool
#define P_LCRSMI_LatDMCClearEnable_bool (LCF_CommonParamData.P_LCRSMI_LatDMCClearEnable_bool) //!< LCF parameter macro.
#define GET_P_LCRSMI_LatDMCClearEnable_bool() (P_LCRSMI_LatDMCClearEnable_bool) //!< LCF parameter macro getter.
#endif // P_LCRSMI_LatDMCClearEnable_bool

#ifndef P_LCRSMI_NoHazardCancelDlc_met
#define P_LCRSMI_NoHazardCancelDlc_met (LCF_CommonParamData.P_LCRSMI_NoHazardCancelDlc_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_NoHazardCancelDlc_met() (P_LCRSMI_NoHazardCancelDlc_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_NoHazardCancelDlc_met

#ifndef P_LCRSMI_NoHazardCancelTol_met
#define P_LCRSMI_NoHazardCancelTol_met (LCF_CommonParamData.P_LCRSMI_NoHazardCancelTol_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_NoHazardCancelTol_met() (P_LCRSMI_NoHazardCancelTol_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_NoHazardCancelTol_met

#ifndef P_LCRSMI_NoHazardFinishDlc_met
#define P_LCRSMI_NoHazardFinishDlc_met (LCF_CommonParamData.P_LCRSMI_NoHazardFinishDlc_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_NoHazardFinishDlc_met() (P_LCRSMI_NoHazardFinishDlc_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_NoHazardFinishDlc_met

#ifndef P_LCRSMI_NoHazardFinishHeadAng_rad
#define P_LCRSMI_NoHazardFinishHeadAng_rad (LCF_CommonParamData.P_LCRSMI_NoHazardFinishHeadAng_rad) //!< LCF parameter macro.
#define GET_P_LCRSMI_NoHazardFinishHeadAng_rad() (P_LCRSMI_NoHazardFinishHeadAng_rad) //!< LCF parameter macro getter.
#endif // P_LCRSMI_NoHazardFinishHeadAng_rad

#ifndef P_LCRSMI_NoHazardFinishTol_met
#define P_LCRSMI_NoHazardFinishTol_met (LCF_CommonParamData.P_LCRSMI_NoHazardFinishTol_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_NoHazardFinishTol_met() (P_LCRSMI_NoHazardFinishTol_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_NoHazardFinishTol_met

#ifndef P_LCRSMI_NoHazardFinishVelLat_mps
#define P_LCRSMI_NoHazardFinishVelLat_mps (LCF_CommonParamData.P_LCRSMI_NoHazardFinishVelLat_mps) //!< LCF parameter macro.
#define GET_P_LCRSMI_NoHazardFinishVelLat_mps() (P_LCRSMI_NoHazardFinishVelLat_mps) //!< LCF parameter macro getter.
#endif // P_LCRSMI_NoHazardFinishVelLat_mps

#ifndef P_LCRSMI_OnTargetFinishTime_sec
#define P_LCRSMI_OnTargetFinishTime_sec (LCF_CommonParamData.P_LCRSMI_OnTargetFinishTime_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_OnTargetFinishTime_sec() (P_LCRSMI_OnTargetFinishTime_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_OnTargetFinishTime_sec

#ifndef P_LCRSMI_QuTrajCtrCancel_btm
#define P_LCRSMI_QuTrajCtrCancel_btm (LCF_CommonParamData.P_LCRSMI_QuTrajCtrCancel_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_QuTrajCtrCancel_btm() (P_LCRSMI_QuTrajCtrCancel_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_QuTrajCtrCancel_btm

#ifndef P_LCRSMI_QuTrajCtrClearance_btm
#define P_LCRSMI_QuTrajCtrClearance_btm (LCF_CommonParamData.P_LCRSMI_QuTrajCtrClearance_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_QuTrajCtrClearance_btm() (P_LCRSMI_QuTrajCtrClearance_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_QuTrajCtrClearance_btm

#ifndef P_LCRSMI_QuTrajPlanCancel_btm
#define P_LCRSMI_QuTrajPlanCancel_btm (LCF_CommonParamData.P_LCRSMI_QuTrajPlanCancel_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_QuTrajPlanCancel_btm() (P_LCRSMI_QuTrajPlanCancel_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_QuTrajPlanCancel_btm

#ifndef P_LCRSMI_QuTrajPlanClearance_btm
#define P_LCRSMI_QuTrajPlanClearance_btm (LCF_CommonParamData.P_LCRSMI_QuTrajPlanClearance_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_QuTrajPlanClearance_btm() (P_LCRSMI_QuTrajPlanClearance_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_QuTrajPlanClearance_btm

#ifndef P_LCRSMI_RequestTimeOut_sec
#define P_LCRSMI_RequestTimeOut_sec (LCF_CommonParamData.P_LCRSMI_RequestTimeOut_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_RequestTimeOut_sec() (P_LCRSMI_RequestTimeOut_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_RequestTimeOut_sec

#ifndef P_LCRSMI_SafeSituationDelay_sec
#define P_LCRSMI_SafeSituationDelay_sec (LCF_CommonParamData.P_LCRSMI_SafeSituationDelay_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_SafeSituationDelay_sec() (P_LCRSMI_SafeSituationDelay_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SafeSituationDelay_sec

#ifndef P_LCRSMI_SafeSituationOffset_met
#define P_LCRSMI_SafeSituationOffset_met (LCF_CommonParamData.P_LCRSMI_SafeSituationOffset_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_SafeSituationOffset_met() (P_LCRSMI_SafeSituationOffset_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SafeSituationOffset_met

#ifndef P_LCRSMI_SafeSituationState_btm
#define P_LCRSMI_SafeSituationState_btm (LCF_CommonParamData.P_LCRSMI_SafeSituationState_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SafeSituationState_btm() (P_LCRSMI_SafeSituationState_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SafeSituationState_btm

#ifndef P_LCRSMI_SideCondCancel_btm
#define P_LCRSMI_SideCondCancel_btm (LCF_CommonParamData.P_LCRSMI_SideCondCancel_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SideCondCancel_btm() (P_LCRSMI_SideCondCancel_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SideCondCancel_btm

#ifndef P_LCRSMI_SideCondDebug_btm
#define P_LCRSMI_SideCondDebug_btm (LCF_CommonParamData.P_LCRSMI_SideCondDebug_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SideCondDebug_btm() (P_LCRSMI_SideCondDebug_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SideCondDebug_btm

#ifndef P_LCRSMI_SideCondEnable_btm
#define P_LCRSMI_SideCondEnable_btm (LCF_CommonParamData.P_LCRSMI_SideCondEnable_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SideCondEnable_btm() (P_LCRSMI_SideCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SideCondEnable_btm

#ifndef P_LCRSMI_StrgRdyDrvSt_btm
#define P_LCRSMI_StrgRdyDrvSt_btm (LCF_CommonParamData.P_LCRSMI_StrgRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdyDrvSt_btm() (P_LCRSMI_StrgRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdyDrvSt_btm

#ifndef P_LCRSMI_StrgRdyFctCustom_btm
#define P_LCRSMI_StrgRdyFctCustom_btm (LCF_CommonParamData.P_LCRSMI_StrgRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdyFctCustom_btm() (P_LCRSMI_StrgRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdyFctCustom_btm

#ifndef P_LCRSMI_StrgRdyFctStCtr_btm
#define P_LCRSMI_StrgRdyFctStCtr_btm (LCF_CommonParamData.P_LCRSMI_StrgRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdyFctStCtr_btm() (P_LCRSMI_StrgRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdyFctStCtr_btm

#ifndef P_LCRSMI_StrgRdyFctStErr_btm
#define P_LCRSMI_StrgRdyFctStErr_btm (LCF_CommonParamData.P_LCRSMI_StrgRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdyFctStErr_btm() (P_LCRSMI_StrgRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdyFctStErr_btm

#ifndef P_LCRSMI_StrgRdyFctStNotAv_btm
#define P_LCRSMI_StrgRdyFctStNotAv_btm (LCF_CommonParamData.P_LCRSMI_StrgRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdyFctStNotAv_btm() (P_LCRSMI_StrgRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdyFctStNotAv_btm

#ifndef P_LCRSMI_StrgRdySpecific_btm
#define P_LCRSMI_StrgRdySpecific_btm (LCF_CommonParamData.P_LCRSMI_StrgRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdySpecific_btm() (P_LCRSMI_StrgRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdySpecific_btm

#ifndef P_LCRSMI_StrgRdyVehSt_btm
#define P_LCRSMI_StrgRdyVehSt_btm (LCF_CommonParamData.P_LCRSMI_StrgRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_StrgRdyVehSt_btm() (P_LCRSMI_StrgRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_StrgRdyVehSt_btm

#ifndef P_LCRSMI_SuppressDrvSt_btm
#define P_LCRSMI_SuppressDrvSt_btm (LCF_CommonParamData.P_LCRSMI_SuppressDrvSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressDrvSt_btm() (P_LCRSMI_SuppressDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressDrvSt_btm

#ifndef P_LCRSMI_SuppressFctCustom_btm
#define P_LCRSMI_SuppressFctCustom_btm (LCF_CommonParamData.P_LCRSMI_SuppressFctCustom_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressFctCustom_btm() (P_LCRSMI_SuppressFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressFctCustom_btm

#ifndef P_LCRSMI_SuppressFctStCtr_btm
#define P_LCRSMI_SuppressFctStCtr_btm (LCF_CommonParamData.P_LCRSMI_SuppressFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressFctStCtr_btm() (P_LCRSMI_SuppressFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressFctStCtr_btm

#ifndef P_LCRSMI_SuppressFctStErr_btm
#define P_LCRSMI_SuppressFctStErr_btm (LCF_CommonParamData.P_LCRSMI_SuppressFctStErr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressFctStErr_btm() (P_LCRSMI_SuppressFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressFctStErr_btm

#ifndef P_LCRSMI_SuppressFctStNotAv_btm
#define P_LCRSMI_SuppressFctStNotAv_btm (LCF_CommonParamData.P_LCRSMI_SuppressFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressFctStNotAv_btm() (P_LCRSMI_SuppressFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressFctStNotAv_btm

#ifndef P_LCRSMI_SuppressSpecific_btm
#define P_LCRSMI_SuppressSpecific_btm (LCF_CommonParamData.P_LCRSMI_SuppressSpecific_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressSpecific_btm() (P_LCRSMI_SuppressSpecific_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressSpecific_btm

#ifndef P_LCRSMI_SuppressVehSt_btm
#define P_LCRSMI_SuppressVehSt_btm (LCF_CommonParamData.P_LCRSMI_SuppressVehSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_SuppressVehSt_btm() (P_LCRSMI_SuppressVehSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_SuppressVehSt_btm

#ifndef P_LCRSMI_TlcDistanceMin_met
#define P_LCRSMI_TlcDistanceMin_met (LCF_CommonParamData.P_LCRSMI_TlcDistanceMin_met) //!< LCF parameter macro.
#define GET_P_LCRSMI_TlcDistanceMin_met() (P_LCRSMI_TlcDistanceMin_met) //!< LCF parameter macro getter.
#endif // P_LCRSMI_TlcDistanceMin_met

#ifndef P_LCRSMI_TlcValidMinTime_sec
#define P_LCRSMI_TlcValidMinTime_sec (LCF_CommonParamData.P_LCRSMI_TlcValidMinTime_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_TlcValidMinTime_sec() (P_LCRSMI_TlcValidMinTime_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_TlcValidMinTime_sec

#ifndef P_LCRSMI_TriggerCondEnable_btm
#define P_LCRSMI_TriggerCondEnable_btm (LCF_CommonParamData.P_LCRSMI_TriggerCondEnable_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_TriggerCondEnable_btm() (P_LCRSMI_TriggerCondEnable_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_TriggerCondEnable_btm

#ifndef P_LCRSMI_TriggerHoldingTime_sec
#define P_LCRSMI_TriggerHoldingTime_sec (LCF_CommonParamData.P_LCRSMI_TriggerHoldingTime_sec) //!< LCF parameter macro.
#define GET_P_LCRSMI_TriggerHoldingTime_sec() (P_LCRSMI_TriggerHoldingTime_sec) //!< LCF parameter macro getter.
#endif // P_LCRSMI_TriggerHoldingTime_sec

#ifndef P_LCRSMI_WeakRdyDrvSt_btm
#define P_LCRSMI_WeakRdyDrvSt_btm (LCF_CommonParamData.P_LCRSMI_WeakRdyDrvSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdyDrvSt_btm() (P_LCRSMI_WeakRdyDrvSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdyDrvSt_btm

#ifndef P_LCRSMI_WeakRdyFctCustom_btm
#define P_LCRSMI_WeakRdyFctCustom_btm (LCF_CommonParamData.P_LCRSMI_WeakRdyFctCustom_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdyFctCustom_btm() (P_LCRSMI_WeakRdyFctCustom_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdyFctCustom_btm

#ifndef P_LCRSMI_WeakRdyFctStCtr_btm
#define P_LCRSMI_WeakRdyFctStCtr_btm (LCF_CommonParamData.P_LCRSMI_WeakRdyFctStCtr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdyFctStCtr_btm() (P_LCRSMI_WeakRdyFctStCtr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdyFctStCtr_btm

#ifndef P_LCRSMI_WeakRdyFctStErr_btm
#define P_LCRSMI_WeakRdyFctStErr_btm (LCF_CommonParamData.P_LCRSMI_WeakRdyFctStErr_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdyFctStErr_btm() (P_LCRSMI_WeakRdyFctStErr_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdyFctStErr_btm

#ifndef P_LCRSMI_WeakRdyFctStNotAv_btm
#define P_LCRSMI_WeakRdyFctStNotAv_btm (LCF_CommonParamData.P_LCRSMI_WeakRdyFctStNotAv_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdyFctStNotAv_btm() (P_LCRSMI_WeakRdyFctStNotAv_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdyFctStNotAv_btm

#ifndef P_LCRSMI_WeakRdySpecific_btm
#define P_LCRSMI_WeakRdySpecific_btm (LCF_CommonParamData.P_LCRSMI_WeakRdySpecific_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdySpecific_btm() (P_LCRSMI_WeakRdySpecific_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdySpecific_btm

#ifndef P_LCRSMI_WeakRdyVehSt_btm
#define P_LCRSMI_WeakRdyVehSt_btm (LCF_CommonParamData.P_LCRSMI_WeakRdyVehSt_btm) //!< LCF parameter macro.
#define GET_P_LCRSMI_WeakRdyVehSt_btm() (P_LCRSMI_WeakRdyVehSt_btm) //!< LCF parameter macro getter.
#endif // P_LCRSMI_WeakRdyVehSt_btm

#ifndef P_LCRTTG_TargetTrajPT1Active_nu
#define P_LCRTTG_TargetTrajPT1Active_nu (LCF_CommonParamData.P_LCRTTG_TargetTrajPT1Active_nu) //!< LCF parameter macro.
#define GET_P_LCRTTG_TargetTrajPT1Active_nu() (P_LCRTTG_TargetTrajPT1Active_nu) //!< LCF parameter macro getter.
#endif // P_LCRTTG_TargetTrajPT1Active_nu

#ifndef P_LCRTTG_TgtCntrLnEnable_nu
#define P_LCRTTG_TgtCntrLnEnable_nu (LCF_CommonParamData.P_LCRTTG_TgtCntrLnEnable_nu) //!< LCF parameter macro.
#define GET_P_LCRTTG_TgtCntrLnEnable_nu() (P_LCRTTG_TgtCntrLnEnable_nu) //!< LCF parameter macro getter.
#endif // P_LCRTTG_TgtCntrLnEnable_nu

#ifndef P_LCRTTG_TgtMaxDistance_met
#define P_LCRTTG_TgtMaxDistance_met (LCF_CommonParamData.P_LCRTTG_TgtMaxDistance_met) //!< LCF parameter macro.
#define GET_P_LCRTTG_TgtMaxDistance_met() (P_LCRTTG_TgtMaxDistance_met) //!< LCF parameter macro getter.
#endif // P_LCRTTG_TgtMaxDistance_met

#ifndef P_LCRTTG_TgtMaxLatDev_met
#define P_LCRTTG_TgtMaxLatDev_met (LCF_CommonParamData.P_LCRTTG_TgtMaxLatDev_met) //!< LCF parameter macro.
#define GET_P_LCRTTG_TgtMaxLatDev_met() (P_LCRTTG_TgtMaxLatDev_met) //!< LCF parameter macro getter.
#endif // P_LCRTTG_TgtMaxLatDev_met

#ifndef P_LCRTTG_TgtTrjPT1TimeConst_sec
#define P_LCRTTG_TgtTrjPT1TimeConst_sec (LCF_CommonParamData.P_LCRTTG_TgtTrjPT1TimeConst_sec) //!< LCF parameter macro.
#define GET_P_LCRTTG_TgtTrjPT1TimeConst_sec() (P_LCRTTG_TgtTrjPT1TimeConst_sec) //!< LCF parameter macro getter.
#endif // P_LCRTTG_TgtTrjPT1TimeConst_sec

#ifndef P_LCRTVG_DistYTolLeTgtArea_met
#define P_LCRTVG_DistYTolLeTgtArea_met (LCF_CommonParamData.P_LCRTVG_DistYTolLeTgtArea_met) //!< LCF parameter macro.
#define GET_P_LCRTVG_DistYTolLeTgtArea_met() (P_LCRTVG_DistYTolLeTgtArea_met) //!< LCF parameter macro getter.
#endif // P_LCRTVG_DistYTolLeTgtArea_met

#ifndef P_LCRTVG_DistYTolRiTgtArea_met
#define P_LCRTVG_DistYTolRiTgtArea_met (LCF_CommonParamData.P_LCRTVG_DistYTolRiTgtArea_met) //!< LCF parameter macro.
#define GET_P_LCRTVG_DistYTolRiTgtArea_met() (P_LCRTVG_DistYTolRiTgtArea_met) //!< LCF parameter macro getter.
#endif // P_LCRTVG_DistYTolRiTgtArea_met

#ifndef P_LCRTVG_FTireAclMax_mps2
#define P_LCRTVG_FTireAclMax_mps2 (LCF_CommonParamData.P_LCRTVG_FTireAclMax_mps2) //!< LCF parameter macro.
#define GET_P_LCRTVG_FTireAclMax_mps2() (P_LCRTVG_FTireAclMax_mps2) //!< LCF parameter macro getter.
#endif // P_LCRTVG_FTireAclMax_mps2

#ifndef P_LCRTVG_FTireAclMin_mps2
#define P_LCRTVG_FTireAclMin_mps2 (LCF_CommonParamData.P_LCRTVG_FTireAclMin_mps2) //!< LCF parameter macro.
#define GET_P_LCRTVG_FTireAclMin_mps2() (P_LCRTVG_FTireAclMin_mps2) //!< LCF parameter macro getter.
#endif // P_LCRTVG_FTireAclMin_mps2

#ifndef P_LCRTVG_HighStatAccu_bool
#define P_LCRTVG_HighStatAccu_bool (LCF_CommonParamData.P_LCRTVG_HighStatAccu_bool) //!< LCF parameter macro.
#define GET_P_LCRTVG_HighStatAccu_bool() (P_LCRTVG_HighStatAccu_bool) //!< LCF parameter macro getter.
#endif // P_LCRTVG_HighStatAccu_bool

#ifndef P_LCRTVG_LimiterActivated_bool
#define P_LCRTVG_LimiterActivated_bool (LCF_CommonParamData.P_LCRTVG_LimiterActivated_bool) //!< LCF parameter macro.
#define GET_P_LCRTVG_LimiterActivated_bool() (P_LCRTVG_LimiterActivated_bool) //!< LCF parameter macro getter.
#endif // P_LCRTVG_LimiterActivated_bool

#ifndef P_LCRTVG_LimiterMaxCrvGrd_1pms
#define P_LCRTVG_LimiterMaxCrvGrd_1pms (LCF_CommonParamData.P_LCRTVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro.
#define GET_P_LCRTVG_LimiterMaxCrvGrd_1pms() (P_LCRTVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro getter.
#endif // P_LCRTVG_LimiterMaxCrvGrd_1pms

#ifndef P_LCRTVG_LimiterMaxCrv_1pm
#define P_LCRTVG_LimiterMaxCrv_1pm (LCF_CommonParamData.P_LCRTVG_LimiterMaxCrv_1pm) //!< LCF parameter macro.
#define GET_P_LCRTVG_LimiterMaxCrv_1pm() (P_LCRTVG_LimiterMaxCrv_1pm) //!< LCF parameter macro getter.
#endif // P_LCRTVG_LimiterMaxCrv_1pm

#ifndef P_LCRTVG_LimiterTimeDuration_sec
#define P_LCRTVG_LimiterTimeDuration_sec (LCF_CommonParamData.P_LCRTVG_LimiterTimeDuration_sec) //!< LCF parameter macro.
#define GET_P_LCRTVG_LimiterTimeDuration_sec() (P_LCRTVG_LimiterTimeDuration_sec) //!< LCF parameter macro getter.
#endif // P_LCRTVG_LimiterTimeDuration_sec

#ifndef P_LCRTVG_MaxJerkAllowed_mps3
#define P_LCRTVG_MaxJerkAllowed_mps3 (LCF_CommonParamData.P_LCRTVG_MaxJerkAllowed_mps3) //!< LCF parameter macro.
#define GET_P_LCRTVG_MaxJerkAllowed_mps3() (P_LCRTVG_MaxJerkAllowed_mps3) //!< LCF parameter macro getter.
#endif // P_LCRTVG_MaxJerkAllowed_mps3

#ifndef P_LCRTVG_MaxTrqScalLimit_nu
#define P_LCRTVG_MaxTrqScalLimit_nu (LCF_CommonParamData.P_LCRTVG_MaxTrqScalLimit_nu) //!< LCF parameter macro.
#define GET_P_LCRTVG_MaxTrqScalLimit_nu() (P_LCRTVG_MaxTrqScalLimit_nu) //!< LCF parameter macro getter.
#endif // P_LCRTVG_MaxTrqScalLimit_nu

#ifndef P_LCRTVG_MaxTrqScalRampInGrd_1ps
#define P_LCRTVG_MaxTrqScalRampInGrd_1ps (LCF_CommonParamData.P_LCRTVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_MaxTrqScalRampInGrd_1ps() (P_LCRTVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_MaxTrqScalRampInGrd_1ps

#ifndef P_LCRTVG_MaxTrqScalRampOutGrd_1ps
#define P_LCRTVG_MaxTrqScalRampOutGrd_1ps (LCF_CommonParamData.P_LCRTVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_MaxTrqScalRampOutGrd_1ps() (P_LCRTVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_MaxTrqScalRampOutGrd_1ps

#ifndef P_LCRTVG_PredTimeCrv_sec
#define P_LCRTVG_PredTimeCrv_sec (LCF_CommonParamData.P_LCRTVG_PredTimeCrv_sec) //!< LCF parameter macro.
#define GET_P_LCRTVG_PredTimeCrv_sec() (P_LCRTVG_PredTimeCrv_sec) //!< LCF parameter macro getter.
#endif // P_LCRTVG_PredTimeCrv_sec

#ifndef P_LCRTVG_PredTimeHeadAng_sec
#define P_LCRTVG_PredTimeHeadAng_sec (LCF_CommonParamData.P_LCRTVG_PredTimeHeadAng_sec) //!< LCF parameter macro.
#define GET_P_LCRTVG_PredTimeHeadAng_sec() (P_LCRTVG_PredTimeHeadAng_sec) //!< LCF parameter macro getter.
#endif // P_LCRTVG_PredTimeHeadAng_sec

#ifndef P_LCRTVG_StrWhStifAbortROGrd_1ps
#define P_LCRTVG_StrWhStifAbortROGrd_1ps (LCF_CommonParamData.P_LCRTVG_StrWhStifAbortROGrd_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_StrWhStifAbortROGrd_1ps() (P_LCRTVG_StrWhStifAbortROGrd_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_StrWhStifAbortROGrd_1ps

#ifndef P_LCRTVG_StrWhStifLimit_nu
#define P_LCRTVG_StrWhStifLimit_nu (LCF_CommonParamData.P_LCRTVG_StrWhStifLimit_nu) //!< LCF parameter macro.
#define GET_P_LCRTVG_StrWhStifLimit_nu() (P_LCRTVG_StrWhStifLimit_nu) //!< LCF parameter macro getter.
#endif // P_LCRTVG_StrWhStifLimit_nu

#ifndef P_LCRTVG_StrWhStifRampOutGrd_1ps
#define P_LCRTVG_StrWhStifRampOutGrd_1ps (LCF_CommonParamData.P_LCRTVG_StrWhStifRampOutGrd_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_StrWhStifRampOutGrd_1ps() (P_LCRTVG_StrWhStifRampOutGrd_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_StrWhStifRampOutGrd_1ps

#ifndef P_LCRTVG_TrajPlanServQu_nu
#define P_LCRTVG_TrajPlanServQu_nu (LCF_CommonParamData.P_LCRTVG_TrajPlanServQu_nu) //!< LCF parameter macro.
#define GET_P_LCRTVG_TrajPlanServQu_nu() (P_LCRTVG_TrajPlanServQu_nu) //!< LCF parameter macro getter.
#endif // P_LCRTVG_TrajPlanServQu_nu

#ifndef P_LCRTVG_TriggerReplan_bool
#define P_LCRTVG_TriggerReplan_bool (LCF_CommonParamData.P_LCRTVG_TriggerReplan_bool) //!< LCF parameter macro.
#define GET_P_LCRTVG_TriggerReplan_bool() (P_LCRTVG_TriggerReplan_bool) //!< LCF parameter macro getter.
#endif // P_LCRTVG_TriggerReplan_bool

#ifndef P_LCRTVG_TrqAbortROGrd_1ps
#define P_LCRTVG_TrqAbortROGrd_1ps (LCF_CommonParamData.P_LCRTVG_TrqAbortROGrd_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_TrqAbortROGrd_1ps() (P_LCRTVG_TrqAbortROGrd_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_TrqAbortROGrd_1ps

#ifndef P_LCRTVG_TrqRampInGrad_1ps
#define P_LCRTVG_TrqRampInGrad_1ps (LCF_CommonParamData.P_LCRTVG_TrqRampInGrad_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_TrqRampInGrad_1ps() (P_LCRTVG_TrqRampInGrad_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_TrqRampInGrad_1ps

#ifndef P_LCRTVG_TrqRampOutGrad_1ps
#define P_LCRTVG_TrqRampOutGrad_1ps (LCF_CommonParamData.P_LCRTVG_TrqRampOutGrad_1ps) //!< LCF parameter macro.
#define GET_P_LCRTVG_TrqRampOutGrad_1ps() (P_LCRTVG_TrqRampOutGrad_1ps) //!< LCF parameter macro getter.
#endif // P_LCRTVG_TrqRampOutGrad_1ps

#ifndef P_LCRTVG_UseLtcyComp_nu
#define P_LCRTVG_UseLtcyComp_nu (LCF_CommonParamData.P_LCRTVG_UseLtcyComp_nu) //!< LCF parameter macro.
#define GET_P_LCRTVG_UseLtcyComp_nu() (P_LCRTVG_UseLtcyComp_nu) //!< LCF parameter macro getter.
#endif // P_LCRTVG_UseLtcyComp_nu

#ifndef P_LCRTVG_WeightTgtDistY_nu
#define P_LCRTVG_WeightTgtDistY_nu (LCF_CommonParamData.P_LCRTVG_WeightTgtDistY_nu) //!< LCF parameter macro.
#define GET_P_LCRTVG_WeightTgtDistY_nu() (P_LCRTVG_WeightTgtDistY_nu) //!< LCF parameter macro getter.
#endif // P_LCRTVG_WeightTgtDistY_nu

#ifndef P_LDP_DlcLimitCustom_bool
#define P_LDP_DlcLimitCustom_bool (LCF_CommonParamData.P_LDP_DlcLimitCustom_bool) //!< LCF parameter macro.
#define GET_P_LDP_DlcLimitCustom_bool() (P_LDP_DlcLimitCustom_bool) //!< LCF parameter macro getter.
#endif // P_LDP_DlcLimitCustom_bool

#ifndef P_LDP_DlcTriggerCustom_bool
#define P_LDP_DlcTriggerCustom_bool (LCF_CommonParamData.P_LDP_DlcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_LDP_DlcTriggerCustom_bool() (P_LDP_DlcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_LDP_DlcTriggerCustom_bool

#ifndef P_LDP_Existing_nu
#define P_LDP_Existing_nu (LCF_CommonParamData.P_LDP_Existing_nu) //!< LCF parameter macro.
#define GET_P_LDP_Existing_nu() (P_LDP_Existing_nu) //!< LCF parameter macro getter.
#endif // P_LDP_Existing_nu

#ifndef P_LDW_DlcLimitCustom_bool
#define P_LDW_DlcLimitCustom_bool (LCF_CommonParamData.P_LDW_DlcLimitCustom_bool) //!< LCF parameter macro.
#define GET_P_LDW_DlcLimitCustom_bool() (P_LDW_DlcLimitCustom_bool) //!< LCF parameter macro getter.
#endif // P_LDW_DlcLimitCustom_bool

#ifndef P_LDW_DlcTriggerCustom_bool
#define P_LDW_DlcTriggerCustom_bool (LCF_CommonParamData.P_LDW_DlcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_LDW_DlcTriggerCustom_bool() (P_LDW_DlcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_LDW_DlcTriggerCustom_bool

#ifndef P_LDW_Existing_nu
#define P_LDW_Existing_nu (LCF_CommonParamData.P_LDW_Existing_nu) //!< LCF parameter macro.
#define GET_P_LDW_Existing_nu() (P_LDW_Existing_nu) //!< LCF parameter macro getter.
#endif // P_LDW_Existing_nu

#ifndef P_LKA_Available_bool
#define P_LKA_Available_bool (LCF_CommonParamData.P_LKA_Available_bool) //!< LCF parameter macro.
#define GET_P_LKA_Available_bool() (P_LKA_Available_bool) //!< LCF parameter macro getter.
#endif // P_LKA_Available_bool

#ifndef P_MCTLFC_ControllingFunction_nu
#define P_MCTLFC_ControllingFunction_nu (LCF_CommonParamData.P_MCTLFC_ControllingFunction_nu) //!< LCF parameter macro.
#define GET_P_MCTLFC_ControllingFunction_nu() (P_MCTLFC_ControllingFunction_nu) //!< LCF parameter macro getter.
#endif // P_MCTLFC_ControllingFunction_nu

#ifndef P_MCTLFC_ErrInjEnable_bool
#define P_MCTLFC_ErrInjEnable_bool (LCF_CommonParamData.P_MCTLFC_ErrInjEnable_bool) //!< LCF parameter macro.
#define GET_P_MCTLFC_ErrInjEnable_bool() (P_MCTLFC_ErrInjEnable_bool) //!< LCF parameter macro getter.
#endif // P_MCTLFC_ErrInjEnable_bool

#ifndef P_ODPFOH_AccObjChange_btm
#define P_ODPFOH_AccObjChange_btm (LCF_CommonParamData.P_ODPFOH_AccObjChange_btm) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjChange_btm() (P_ODPFOH_AccObjChange_btm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjChange_btm

#ifndef P_ODPFOH_AccObjCheckLane_bool
#define P_ODPFOH_AccObjCheckLane_bool (LCF_CommonParamData.P_ODPFOH_AccObjCheckLane_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjCheckLane_bool() (P_ODPFOH_AccObjCheckLane_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjCheckLane_bool

#ifndef P_ODPFOH_AccObjChngDuration_sec
#define P_ODPFOH_AccObjChngDuration_sec (LCF_CommonParamData.P_ODPFOH_AccObjChngDuration_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjChngDuration_sec() (P_ODPFOH_AccObjChngDuration_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjChngDuration_sec

#ifndef P_ODPFOH_AccObjDtct_btm
#define P_ODPFOH_AccObjDtct_btm (LCF_CommonParamData.P_ODPFOH_AccObjDtct_btm) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjDtct_btm() (P_ODPFOH_AccObjDtct_btm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjDtct_btm

#ifndef P_ODPFOH_AccObjFreeze_btm
#define P_ODPFOH_AccObjFreeze_btm (LCF_CommonParamData.P_ODPFOH_AccObjFreeze_btm) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjFreeze_btm() (P_ODPFOH_AccObjFreeze_btm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjFreeze_btm

#ifndef P_ODPFOH_AccObjKfUpdate_btm
#define P_ODPFOH_AccObjKfUpdate_btm (LCF_CommonParamData.P_ODPFOH_AccObjKfUpdate_btm) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjKfUpdate_btm() (P_ODPFOH_AccObjKfUpdate_btm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjKfUpdate_btm

#ifndef P_ODPFOH_AccObjValidLSM_btm
#define P_ODPFOH_AccObjValidLSM_btm (LCF_CommonParamData.P_ODPFOH_AccObjValidLSM_btm) //!< LCF parameter macro.
#define GET_P_ODPFOH_AccObjValidLSM_btm() (P_ODPFOH_AccObjValidLSM_btm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_AccObjValidLSM_btm

#ifndef P_ODPFOH_CrvStdDev_1pm
#define P_ODPFOH_CrvStdDev_1pm (LCF_CommonParamData.P_ODPFOH_CrvStdDev_1pm) //!< LCF parameter macro.
#define GET_P_ODPFOH_CrvStdDev_1pm() (P_ODPFOH_CrvStdDev_1pm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_CrvStdDev_1pm

#ifndef P_ODPFOH_EnableObjTraceKF_bool
#define P_ODPFOH_EnableObjTraceKF_bool (LCF_CommonParamData.P_ODPFOH_EnableObjTraceKF_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_EnableObjTraceKF_bool() (P_ODPFOH_EnableObjTraceKF_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_EnableObjTraceKF_bool

#ifndef P_ODPFOH_EnableTransAtStart_bool
#define P_ODPFOH_EnableTransAtStart_bool (LCF_CommonParamData.P_ODPFOH_EnableTransAtStart_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_EnableTransAtStart_bool() (P_ODPFOH_EnableTransAtStart_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_EnableTransAtStart_bool

#ifndef P_ODPFOH_FeatPtsMinPosXTime_sec
#define P_ODPFOH_FeatPtsMinPosXTime_sec (LCF_CommonParamData.P_ODPFOH_FeatPtsMinPosXTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_FeatPtsMinPosXTime_sec() (P_ODPFOH_FeatPtsMinPosXTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_FeatPtsMinPosXTime_sec

#ifndef P_ODPFOH_FeatPtsMinPosX_met
#define P_ODPFOH_FeatPtsMinPosX_met (LCF_CommonParamData.P_ODPFOH_FeatPtsMinPosX_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_FeatPtsMinPosX_met() (P_ODPFOH_FeatPtsMinPosX_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_FeatPtsMinPosX_met

#ifndef P_ODPFOH_HeadingAngStdDev_rad
#define P_ODPFOH_HeadingAngStdDev_rad (LCF_CommonParamData.P_ODPFOH_HeadingAngStdDev_rad) //!< LCF parameter macro.
#define GET_P_ODPFOH_HeadingAngStdDev_rad() (P_ODPFOH_HeadingAngStdDev_rad) //!< LCF parameter macro getter.
#endif // P_ODPFOH_HeadingAngStdDev_rad

#ifndef P_ODPFOH_LowSpeedHystVel_kph
#define P_ODPFOH_LowSpeedHystVel_kph (LCF_CommonParamData.P_ODPFOH_LowSpeedHystVel_kph) //!< LCF parameter macro.
#define GET_P_ODPFOH_LowSpeedHystVel_kph() (P_ODPFOH_LowSpeedHystVel_kph) //!< LCF parameter macro getter.
#endif // P_ODPFOH_LowSpeedHystVel_kph

#ifndef P_ODPFOH_LowSpeedMaxVel_kph
#define P_ODPFOH_LowSpeedMaxVel_kph (LCF_CommonParamData.P_ODPFOH_LowSpeedMaxVel_kph) //!< LCF parameter macro.
#define GET_P_ODPFOH_LowSpeedMaxVel_kph() (P_ODPFOH_LowSpeedMaxVel_kph) //!< LCF parameter macro getter.
#endif // P_ODPFOH_LowSpeedMaxVel_kph

#ifndef P_ODPFOH_MaxDeltaEgoCrvLSM_1pm
#define P_ODPFOH_MaxDeltaEgoCrvLSM_1pm (LCF_CommonParamData.P_ODPFOH_MaxDeltaEgoCrvLSM_1pm) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxDeltaEgoCrvLSM_1pm() (P_ODPFOH_MaxDeltaEgoCrvLSM_1pm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxDeltaEgoCrvLSM_1pm

#ifndef P_ODPFOH_MaxGradCrv_1pms
#define P_ODPFOH_MaxGradCrv_1pms (LCF_CommonParamData.P_ODPFOH_MaxGradCrv_1pms) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxGradCrv_1pms() (P_ODPFOH_MaxGradCrv_1pms) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxGradCrv_1pms

#ifndef P_ODPFOH_MaxGradHeadAng_rps
#define P_ODPFOH_MaxGradHeadAng_rps (LCF_CommonParamData.P_ODPFOH_MaxGradHeadAng_rps) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxGradHeadAng_rps() (P_ODPFOH_MaxGradHeadAng_rps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxGradHeadAng_rps

#ifndef P_ODPFOH_MaxGradPosY0_mps
#define P_ODPFOH_MaxGradPosY0_mps (LCF_CommonParamData.P_ODPFOH_MaxGradPosY0_mps) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxGradPosY0_mps() (P_ODPFOH_MaxGradPosY0_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxGradPosY0_mps

#ifndef P_ODPFOH_MaxHistStartX0_met
#define P_ODPFOH_MaxHistStartX0_met (LCF_CommonParamData.P_ODPFOH_MaxHistStartX0_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxHistStartX0_met() (P_ODPFOH_MaxHistStartX0_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxHistStartX0_met

#ifndef P_ODPFOH_MaxObjDistHystLSM_met
#define P_ODPFOH_MaxObjDistHystLSM_met (LCF_CommonParamData.P_ODPFOH_MaxObjDistHystLSM_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxObjDistHystLSM_met() (P_ODPFOH_MaxObjDistHystLSM_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxObjDistHystLSM_met

#ifndef P_ODPFOH_MaxObjHistSampleD_met
#define P_ODPFOH_MaxObjHistSampleD_met (LCF_CommonParamData.P_ODPFOH_MaxObjHistSampleD_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxObjHistSampleD_met() (P_ODPFOH_MaxObjHistSampleD_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxObjHistSampleD_met

#ifndef P_ODPFOH_MaxObjHistSampleT_sec
#define P_ODPFOH_MaxObjHistSampleT_sec (LCF_CommonParamData.P_ODPFOH_MaxObjHistSampleT_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxObjHistSampleT_sec() (P_ODPFOH_MaxObjHistSampleT_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxObjHistSampleT_sec

#ifndef P_ODPFOH_MaxRangeCrv_1pm
#define P_ODPFOH_MaxRangeCrv_1pm (LCF_CommonParamData.P_ODPFOH_MaxRangeCrv_1pm) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxRangeCrv_1pm() (P_ODPFOH_MaxRangeCrv_1pm) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxRangeCrv_1pm

#ifndef P_ODPFOH_MaxRangeHead_rad
#define P_ODPFOH_MaxRangeHead_rad (LCF_CommonParamData.P_ODPFOH_MaxRangeHead_rad) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxRangeHead_rad() (P_ODPFOH_MaxRangeHead_rad) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxRangeHead_rad

#ifndef P_ODPFOH_MaxRangePosY0_met
#define P_ODPFOH_MaxRangePosY0_met (LCF_CommonParamData.P_ODPFOH_MaxRangePosY0_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_MaxRangePosY0_met() (P_ODPFOH_MaxRangePosY0_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MaxRangePosY0_met

#ifndef P_ODPFOH_MinHistLengthTime_sec
#define P_ODPFOH_MinHistLengthTime_sec (LCF_CommonParamData.P_ODPFOH_MinHistLengthTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinHistLengthTime_sec() (P_ODPFOH_MinHistLengthTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinHistLengthTime_sec

#ifndef P_ODPFOH_MinHistLength_met
#define P_ODPFOH_MinHistLength_met (LCF_CommonParamData.P_ODPFOH_MinHistLength_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinHistLength_met() (P_ODPFOH_MinHistLength_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinHistLength_met

#ifndef P_ODPFOH_MinObjHistSampleD_met
#define P_ODPFOH_MinObjHistSampleD_met (LCF_CommonParamData.P_ODPFOH_MinObjHistSampleD_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinObjHistSampleD_met() (P_ODPFOH_MinObjHistSampleD_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinObjHistSampleD_met

#ifndef P_ODPFOH_MinObjValidityTime_sec
#define P_ODPFOH_MinObjValidityTime_sec (LCF_CommonParamData.P_ODPFOH_MinObjValidityTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinObjValidityTime_sec() (P_ODPFOH_MinObjValidityTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinObjValidityTime_sec

#ifndef P_ODPFOH_MinPosXVelXOn_bool
#define P_ODPFOH_MinPosXVelXOn_bool (LCF_CommonParamData.P_ODPFOH_MinPosXVelXOn_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinPosXVelXOn_bool() (P_ODPFOH_MinPosXVelXOn_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinPosXVelXOn_bool

#ifndef P_ODPFOH_MinTrajValidTime_sec
#define P_ODPFOH_MinTrajValidTime_sec (LCF_CommonParamData.P_ODPFOH_MinTrajValidTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinTrajValidTime_sec() (P_ODPFOH_MinTrajValidTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinTrajValidTime_sec

#ifndef P_ODPFOH_MinValidEntries_nu
#define P_ODPFOH_MinValidEntries_nu (LCF_CommonParamData.P_ODPFOH_MinValidEntries_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinValidEntries_nu() (P_ODPFOH_MinValidEntries_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinValidEntries_nu

#ifndef P_ODPFOH_MinVelForKF_mps
#define P_ODPFOH_MinVelForKF_mps (LCF_CommonParamData.P_ODPFOH_MinVelForKF_mps) //!< LCF parameter macro.
#define GET_P_ODPFOH_MinVelForKF_mps() (P_ODPFOH_MinVelForKF_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_MinVelForKF_mps

#ifndef P_ODPFOH_NumObjDistHistParts_nu
#define P_ODPFOH_NumObjDistHistParts_nu (LCF_CommonParamData.P_ODPFOH_NumObjDistHistParts_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_NumObjDistHistParts_nu() (P_ODPFOH_NumObjDistHistParts_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_NumObjDistHistParts_nu

#ifndef P_ODPFOH_ObjKFDecQualDegr_1ps
#define P_ODPFOH_ObjKFDecQualDegr_1ps (LCF_CommonParamData.P_ODPFOH_ObjKFDecQualDegr_1ps) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDecQualDegr_1ps() (P_ODPFOH_ObjKFDecQualDegr_1ps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDecQualDegr_1ps

#ifndef P_ODPFOH_ObjKFDecQualPred_1ps
#define P_ODPFOH_ObjKFDecQualPred_1ps (LCF_CommonParamData.P_ODPFOH_ObjKFDecQualPred_1ps) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDecQualPred_1ps() (P_ODPFOH_ObjKFDecQualPred_1ps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDecQualPred_1ps

#ifndef P_ODPFOH_ObjKFDegrUpdGrad_1ps
#define P_ODPFOH_ObjKFDegrUpdGrad_1ps (LCF_CommonParamData.P_ODPFOH_ObjKFDegrUpdGrad_1ps) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDegrUpdGrad_1ps() (P_ODPFOH_ObjKFDegrUpdGrad_1ps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDegrUpdGrad_1ps

#ifndef P_ODPFOH_ObjKFDegrUpdWeight_nu
#define P_ODPFOH_ObjKFDegrUpdWeight_nu (LCF_CommonParamData.P_ODPFOH_ObjKFDegrUpdWeight_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDegrUpdWeight_nu() (P_ODPFOH_ObjKFDegrUpdWeight_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDegrUpdWeight_nu

#ifndef P_ODPFOH_ObjKFDegrUpdateQu_perc
#define P_ODPFOH_ObjKFDegrUpdateQu_perc (LCF_CommonParamData.P_ODPFOH_ObjKFDegrUpdateQu_perc) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDegrUpdateQu_perc() (P_ODPFOH_ObjKFDegrUpdateQu_perc) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDegrUpdateQu_perc

#ifndef P_ODPFOH_ObjKFDegrUpdate_bool
#define P_ODPFOH_ObjKFDegrUpdate_bool (LCF_CommonParamData.P_ODPFOH_ObjKFDegrUpdate_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDegrUpdate_bool() (P_ODPFOH_ObjKFDegrUpdate_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDegrUpdate_bool

#ifndef P_ODPFOH_ObjKFDynCrvFact_nu
#define P_ODPFOH_ObjKFDynCrvFact_nu (LCF_CommonParamData.P_ODPFOH_ObjKFDynCrvFact_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDynCrvFact_nu() (P_ODPFOH_ObjKFDynCrvFact_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDynCrvFact_nu

#ifndef P_ODPFOH_ObjKFDynDistYFact_nu
#define P_ODPFOH_ObjKFDynDistYFact_nu (LCF_CommonParamData.P_ODPFOH_ObjKFDynDistYFact_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDynDistYFact_nu() (P_ODPFOH_ObjKFDynDistYFact_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDynDistYFact_nu

#ifndef P_ODPFOH_ObjKFDynYawFact_nu
#define P_ODPFOH_ObjKFDynYawFact_nu (LCF_CommonParamData.P_ODPFOH_ObjKFDynYawFact_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFDynYawFact_nu() (P_ODPFOH_ObjKFDynYawFact_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFDynYawFact_nu

#ifndef P_ODPFOH_ObjKFIncrQual_1ps
#define P_ODPFOH_ObjKFIncrQual_1ps (LCF_CommonParamData.P_ODPFOH_ObjKFIncrQual_1ps) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFIncrQual_1ps() (P_ODPFOH_ObjKFIncrQual_1ps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFIncrQual_1ps

#ifndef P_ODPFOH_ObjKFInitRFactor_nu
#define P_ODPFOH_ObjKFInitRFactor_nu (LCF_CommonParamData.P_ODPFOH_ObjKFInitRFactor_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFInitRFactor_nu() (P_ODPFOH_ObjKFInitRFactor_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFInitRFactor_nu

#ifndef P_ODPFOH_ObjKFKGainFact_nu
#define P_ODPFOH_ObjKFKGainFact_nu (LCF_CommonParamData.P_ODPFOH_ObjKFKGainFact_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFKGainFact_nu() (P_ODPFOH_ObjKFKGainFact_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFKGainFact_nu

#ifndef P_ODPFOH_ObjKFMinInitQual_perc
#define P_ODPFOH_ObjKFMinInitQual_perc (LCF_CommonParamData.P_ODPFOH_ObjKFMinInitQual_perc) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFMinInitQual_perc() (P_ODPFOH_ObjKFMinInitQual_perc) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFMinInitQual_perc

#ifndef P_ODPFOH_ObjKFMinUpdateQual_perc
#define P_ODPFOH_ObjKFMinUpdateQual_perc (LCF_CommonParamData.P_ODPFOH_ObjKFMinUpdateQual_perc) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKFMinUpdateQual_perc() (P_ODPFOH_ObjKFMinUpdateQual_perc) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKFMinUpdateQual_perc

#ifndef P_ODPFOH_ObjKinMaxLatAccel_mps2
#define P_ODPFOH_ObjKinMaxLatAccel_mps2 (LCF_CommonParamData.P_ODPFOH_ObjKinMaxLatAccel_mps2) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKinMaxLatAccel_mps2() (P_ODPFOH_ObjKinMaxLatAccel_mps2) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKinMaxLatAccel_mps2

#ifndef P_ODPFOH_ObjKinMaxLatJerk_mps3
#define P_ODPFOH_ObjKinMaxLatJerk_mps3 (LCF_CommonParamData.P_ODPFOH_ObjKinMaxLatJerk_mps3) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKinMaxLatJerk_mps3() (P_ODPFOH_ObjKinMaxLatJerk_mps3) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKinMaxLatJerk_mps3

#ifndef P_ODPFOH_ObjKinRefVel_mps
#define P_ODPFOH_ObjKinRefVel_mps (LCF_CommonParamData.P_ODPFOH_ObjKinRefVel_mps) //!< LCF parameter macro.
#define GET_P_ODPFOH_ObjKinRefVel_mps() (P_ODPFOH_ObjKinRefVel_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ObjKinRefVel_mps

#ifndef P_ODPFOH_PF_CrvChngDecay_nu
#define P_ODPFOH_PF_CrvChngDecay_nu (LCF_CommonParamData.P_ODPFOH_PF_CrvChngDecay_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_PF_CrvChngDecay_nu() (P_ODPFOH_PF_CrvChngDecay_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PF_CrvChngDecay_nu

#ifndef P_ODPFOH_PF_CrvDecay_nu
#define P_ODPFOH_PF_CrvDecay_nu (LCF_CommonParamData.P_ODPFOH_PF_CrvDecay_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_PF_CrvDecay_nu() (P_ODPFOH_PF_CrvDecay_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PF_CrvDecay_nu

#ifndef P_ODPFOH_PT1CrvEnable_bool
#define P_ODPFOH_PT1CrvEnable_bool (LCF_CommonParamData.P_ODPFOH_PT1CrvEnable_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_PT1CrvEnable_bool() (P_ODPFOH_PT1CrvEnable_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PT1CrvEnable_bool

#ifndef P_ODPFOH_PT1HeadEnable_bool
#define P_ODPFOH_PT1HeadEnable_bool (LCF_CommonParamData.P_ODPFOH_PT1HeadEnable_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_PT1HeadEnable_bool() (P_ODPFOH_PT1HeadEnable_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PT1HeadEnable_bool

#ifndef P_ODPFOH_PT1PosY0Enable_bool
#define P_ODPFOH_PT1PosY0Enable_bool (LCF_CommonParamData.P_ODPFOH_PT1PosY0Enable_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_PT1PosY0Enable_bool() (P_ODPFOH_PT1PosY0Enable_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PT1PosY0Enable_bool

#ifndef P_ODPFOH_PT1PosYEnable_bool
#define P_ODPFOH_PT1PosYEnable_bool (LCF_CommonParamData.P_ODPFOH_PT1PosYEnable_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_PT1PosYEnable_bool() (P_ODPFOH_PT1PosYEnable_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PT1PosYEnable_bool

#ifndef P_ODPFOH_PT1YawRateEnable_bool
#define P_ODPFOH_PT1YawRateEnable_bool (LCF_CommonParamData.P_ODPFOH_PT1YawRateEnable_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_PT1YawRateEnable_bool() (P_ODPFOH_PT1YawRateEnable_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PT1YawRateEnable_bool

#ifndef P_ODPFOH_PosY0StdDev_met
#define P_ODPFOH_PosY0StdDev_met (LCF_CommonParamData.P_ODPFOH_PosY0StdDev_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_PosY0StdDev_met() (P_ODPFOH_PosY0StdDev_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PosY0StdDev_met

#ifndef P_ODPFOH_PredTimeMaxPosX0_sec
#define P_ODPFOH_PredTimeMaxPosX0_sec (LCF_CommonParamData.P_ODPFOH_PredTimeMaxPosX0_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_PredTimeMaxPosX0_sec() (P_ODPFOH_PredTimeMaxPosX0_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_PredTimeMaxPosX0_sec

#ifndef P_ODPFOH_ScalingFactorCrv_nu
#define P_ODPFOH_ScalingFactorCrv_nu (LCF_CommonParamData.P_ODPFOH_ScalingFactorCrv_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ScalingFactorCrv_nu() (P_ODPFOH_ScalingFactorCrv_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ScalingFactorCrv_nu

#ifndef P_ODPFOH_ScalingFactorHead_nu
#define P_ODPFOH_ScalingFactorHead_nu (LCF_CommonParamData.P_ODPFOH_ScalingFactorHead_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ScalingFactorHead_nu() (P_ODPFOH_ScalingFactorHead_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ScalingFactorHead_nu

#ifndef P_ODPFOH_ScalingFactorPosY0_nu
#define P_ODPFOH_ScalingFactorPosY0_nu (LCF_CommonParamData.P_ODPFOH_ScalingFactorPosY0_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_ScalingFactorPosY0_nu() (P_ODPFOH_ScalingFactorPosY0_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_ScalingFactorPosY0_nu

#ifndef P_ODPFOH_SignLimMinObjPosY_met
#define P_ODPFOH_SignLimMinObjPosY_met (LCF_CommonParamData.P_ODPFOH_SignLimMinObjPosY_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_SignLimMinObjPosY_met() (P_ODPFOH_SignLimMinObjPosY_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_SignLimMinObjPosY_met

#ifndef P_ODPFOH_SignLimStrEstLSP_perc
#define P_ODPFOH_SignLimStrEstLSP_perc (LCF_CommonParamData.P_ODPFOH_SignLimStrEstLSP_perc) //!< LCF parameter macro.
#define GET_P_ODPFOH_SignLimStrEstLSP_perc() (P_ODPFOH_SignLimStrEstLSP_perc) //!< LCF parameter macro getter.
#endif // P_ODPFOH_SignLimStrEstLSP_perc

#ifndef P_ODPFOH_SignLimStrEstRSP_perc
#define P_ODPFOH_SignLimStrEstRSP_perc (LCF_CommonParamData.P_ODPFOH_SignLimStrEstRSP_perc) //!< LCF parameter macro.
#define GET_P_ODPFOH_SignLimStrEstRSP_perc() (P_ODPFOH_SignLimStrEstRSP_perc) //!< LCF parameter macro getter.
#endif // P_ODPFOH_SignLimStrEstRSP_perc

#ifndef P_ODPFOH_StrEstimMeanDevFac_nu
#define P_ODPFOH_StrEstimMeanDevFac_nu (LCF_CommonParamData.P_ODPFOH_StrEstimMeanDevFac_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_StrEstimMeanDevFac_nu() (P_ODPFOH_StrEstimMeanDevFac_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_StrEstimMeanDevFac_nu

#ifndef P_ODPFOH_StrEstimMeanDev_met
#define P_ODPFOH_StrEstimMeanDev_met (LCF_CommonParamData.P_ODPFOH_StrEstimMeanDev_met) //!< LCF parameter macro.
#define GET_P_ODPFOH_StrEstimMeanDev_met() (P_ODPFOH_StrEstimMeanDev_met) //!< LCF parameter macro getter.
#endif // P_ODPFOH_StrEstimMeanDev_met

#ifndef P_ODPFOH_StrEstimNegGrad_1ps
#define P_ODPFOH_StrEstimNegGrad_1ps (LCF_CommonParamData.P_ODPFOH_StrEstimNegGrad_1ps) //!< LCF parameter macro.
#define GET_P_ODPFOH_StrEstimNegGrad_1ps() (P_ODPFOH_StrEstimNegGrad_1ps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_StrEstimNegGrad_1ps

#ifndef P_ODPFOH_StrEstimPT1_sec
#define P_ODPFOH_StrEstimPT1_sec (LCF_CommonParamData.P_ODPFOH_StrEstimPT1_sec) //!< LCF parameter macro.
#define GET_P_ODPFOH_StrEstimPT1_sec() (P_ODPFOH_StrEstimPT1_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOH_StrEstimPT1_sec

#ifndef P_ODPFOH_StrEstimPosGrad_1ps
#define P_ODPFOH_StrEstimPosGrad_1ps (LCF_CommonParamData.P_ODPFOH_StrEstimPosGrad_1ps) //!< LCF parameter macro.
#define GET_P_ODPFOH_StrEstimPosGrad_1ps() (P_ODPFOH_StrEstimPosGrad_1ps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_StrEstimPosGrad_1ps

#ifndef P_ODPFOH_UseCrvOnlyLSM_bool
#define P_ODPFOH_UseCrvOnlyLSM_bool (LCF_CommonParamData.P_ODPFOH_UseCrvOnlyLSM_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseCrvOnlyLSM_bool() (P_ODPFOH_UseCrvOnlyLSM_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseCrvOnlyLSM_bool

#ifndef P_ODPFOH_UseEstimPosY_bool
#define P_ODPFOH_UseEstimPosY_bool (LCF_CommonParamData.P_ODPFOH_UseEstimPosY_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseEstimPosY_bool() (P_ODPFOH_UseEstimPosY_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseEstimPosY_bool

#ifndef P_ODPFOH_UseOutputGradLim_bool
#define P_ODPFOH_UseOutputGradLim_bool (LCF_CommonParamData.P_ODPFOH_UseOutputGradLim_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseOutputGradLim_bool() (P_ODPFOH_UseOutputGradLim_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseOutputGradLim_bool

#ifndef P_ODPFOH_UseOutputRangeLim_bool
#define P_ODPFOH_UseOutputRangeLim_bool (LCF_CommonParamData.P_ODPFOH_UseOutputRangeLim_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseOutputRangeLim_bool() (P_ODPFOH_UseOutputRangeLim_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseOutputRangeLim_bool

#ifndef P_ODPFOH_UsePosYReduction_bool
#define P_ODPFOH_UsePosYReduction_bool (LCF_CommonParamData.P_ODPFOH_UsePosYReduction_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UsePosYReduction_bool() (P_ODPFOH_UsePosYReduction_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UsePosYReduction_bool

#ifndef P_ODPFOH_UsePosYcorr_bool
#define P_ODPFOH_UsePosYcorr_bool (LCF_CommonParamData.P_ODPFOH_UsePosYcorr_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UsePosYcorr_bool() (P_ODPFOH_UsePosYcorr_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UsePosYcorr_bool

#ifndef P_ODPFOH_UseSignLimCrv_bool
#define P_ODPFOH_UseSignLimCrv_bool (LCF_CommonParamData.P_ODPFOH_UseSignLimCrv_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseSignLimCrv_bool() (P_ODPFOH_UseSignLimCrv_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseSignLimCrv_bool

#ifndef P_ODPFOH_UseSignLimHead_bool
#define P_ODPFOH_UseSignLimHead_bool (LCF_CommonParamData.P_ODPFOH_UseSignLimHead_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseSignLimHead_bool() (P_ODPFOH_UseSignLimHead_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseSignLimHead_bool

#ifndef P_ODPFOH_UseSignLimPosY0_bool
#define P_ODPFOH_UseSignLimPosY0_bool (LCF_CommonParamData.P_ODPFOH_UseSignLimPosY0_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseSignLimPosY0_bool() (P_ODPFOH_UseSignLimPosY0_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseSignLimPosY0_bool

#ifndef P_ODPFOH_UseStrEstimGradLim_bool
#define P_ODPFOH_UseStrEstimGradLim_bool (LCF_CommonParamData.P_ODPFOH_UseStrEstimGradLim_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseStrEstimGradLim_bool() (P_ODPFOH_UseStrEstimGradLim_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseStrEstimGradLim_bool

#ifndef P_ODPFOH_UseStrEstimLimit_bool
#define P_ODPFOH_UseStrEstimLimit_bool (LCF_CommonParamData.P_ODPFOH_UseStrEstimLimit_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseStrEstimLimit_bool() (P_ODPFOH_UseStrEstimLimit_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseStrEstimLimit_bool

#ifndef P_ODPFOH_UseStrEstimPT1_bool
#define P_ODPFOH_UseStrEstimPT1_bool (LCF_CommonParamData.P_ODPFOH_UseStrEstimPT1_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseStrEstimPT1_bool() (P_ODPFOH_UseStrEstimPT1_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseStrEstimPT1_bool

#ifndef P_ODPFOH_UseStraightEstim_bool
#define P_ODPFOH_UseStraightEstim_bool (LCF_CommonParamData.P_ODPFOH_UseStraightEstim_bool) //!< LCF parameter macro.
#define GET_P_ODPFOH_UseStraightEstim_bool() (P_ODPFOH_UseStraightEstim_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOH_UseStraightEstim_bool

#ifndef P_ODPFOH_VehYawRateStdDev_radps
#define P_ODPFOH_VehYawRateStdDev_radps (LCF_CommonParamData.P_ODPFOH_VehYawRateStdDev_radps) //!< LCF parameter macro.
#define GET_P_ODPFOH_VehYawRateStdDev_radps() (P_ODPFOH_VehYawRateStdDev_radps) //!< LCF parameter macro getter.
#endif // P_ODPFOH_VehYawRateStdDev_radps

#ifndef P_ODPFOH_YawRateDelayCycles_nu
#define P_ODPFOH_YawRateDelayCycles_nu (LCF_CommonParamData.P_ODPFOH_YawRateDelayCycles_nu) //!< LCF parameter macro.
#define GET_P_ODPFOH_YawRateDelayCycles_nu() (P_ODPFOH_YawRateDelayCycles_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOH_YawRateDelayCycles_nu

#ifndef P_ODPFOP_DistYMaxCrvOffset_met
#define P_ODPFOP_DistYMaxCrvOffset_met (LCF_CommonParamData.P_ODPFOP_DistYMaxCrvOffset_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_DistYMaxCrvOffset_met() (P_ODPFOP_DistYMaxCrvOffset_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_DistYMaxCrvOffset_met

#ifndef P_ODPFOP_DriveoffDelayTime_sec
#define P_ODPFOP_DriveoffDelayTime_sec (LCF_CommonParamData.P_ODPFOP_DriveoffDelayTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_DriveoffDelayTime_sec() (P_ODPFOP_DriveoffDelayTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_DriveoffDelayTime_sec

#ifndef P_ODPFOP_DriveoffTolTime_sec
#define P_ODPFOP_DriveoffTolTime_sec (LCF_CommonParamData.P_ODPFOP_DriveoffTolTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_DriveoffTolTime_sec() (P_ODPFOP_DriveoffTolTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_DriveoffTolTime_sec

#ifndef P_ODPFOP_DriveoffVelReset_mps
#define P_ODPFOP_DriveoffVelReset_mps (LCF_CommonParamData.P_ODPFOP_DriveoffVelReset_mps) //!< LCF parameter macro.
#define GET_P_ODPFOP_DriveoffVelReset_mps() (P_ODPFOP_DriveoffVelReset_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOP_DriveoffVelReset_mps

#ifndef P_ODPFOP_EnableLatMovFreeze_bool
#define P_ODPFOP_EnableLatMovFreeze_bool (LCF_CommonParamData.P_ODPFOP_EnableLatMovFreeze_bool) //!< LCF parameter macro.
#define GET_P_ODPFOP_EnableLatMovFreeze_bool() (P_ODPFOP_EnableLatMovFreeze_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOP_EnableLatMovFreeze_bool

#ifndef P_ODPFOP_FacMaxDistYActive_nu
#define P_ODPFOP_FacMaxDistYActive_nu (LCF_CommonParamData.P_ODPFOP_FacMaxDistYActive_nu) //!< LCF parameter macro.
#define GET_P_ODPFOP_FacMaxDistYActive_nu() (P_ODPFOP_FacMaxDistYActive_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOP_FacMaxDistYActive_nu

#ifndef P_ODPFOP_FusionMCamFront_nu
#define P_ODPFOP_FusionMCamFront_nu (LCF_CommonParamData.P_ODPFOP_FusionMCamFront_nu) //!< LCF parameter macro.
#define GET_P_ODPFOP_FusionMCamFront_nu() (P_ODPFOP_FusionMCamFront_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOP_FusionMCamFront_nu

#ifndef P_ODPFOP_FusionRadarFront_nu
#define P_ODPFOP_FusionRadarFront_nu (LCF_CommonParamData.P_ODPFOP_FusionRadarFront_nu) //!< LCF parameter macro.
#define GET_P_ODPFOP_FusionRadarFront_nu() (P_ODPFOP_FusionRadarFront_nu) //!< LCF parameter macro getter.
#endif // P_ODPFOP_FusionRadarFront_nu

#ifndef P_ODPFOP_LongDistMaxHyst_met
#define P_ODPFOP_LongDistMaxHyst_met (LCF_CommonParamData.P_ODPFOP_LongDistMaxHyst_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_LongDistMaxHyst_met() (P_ODPFOP_LongDistMaxHyst_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_LongDistMaxHyst_met

#ifndef P_ODPFOP_MaxDistYHyst_met
#define P_ODPFOP_MaxDistYHyst_met (LCF_CommonParamData.P_ODPFOP_MaxDistYHyst_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxDistYHyst_met() (P_ODPFOP_MaxDistYHyst_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxDistYHyst_met

#ifndef P_ODPFOP_MaxDistY_met
#define P_ODPFOP_MaxDistY_met (LCF_CommonParamData.P_ODPFOP_MaxDistY_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxDistY_met() (P_ODPFOP_MaxDistY_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxDistY_met

#ifndef P_ODPFOP_MaxLatAcl_mps2
#define P_ODPFOP_MaxLatAcl_mps2 (LCF_CommonParamData.P_ODPFOP_MaxLatAcl_mps2) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLatAcl_mps2() (P_ODPFOP_MaxLatAcl_mps2) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLatAcl_mps2

#ifndef P_ODPFOP_MaxLatVelHyst_mps
#define P_ODPFOP_MaxLatVelHyst_mps (LCF_CommonParamData.P_ODPFOP_MaxLatVelHyst_mps) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLatVelHyst_mps() (P_ODPFOP_MaxLatVelHyst_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLatVelHyst_mps

#ifndef P_ODPFOP_MaxLatVel_mps
#define P_ODPFOP_MaxLatVel_mps (LCF_CommonParamData.P_ODPFOP_MaxLatVel_mps) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLatVel_mps() (P_ODPFOP_MaxLatVel_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLatVel_mps

#ifndef P_ODPFOP_MaxLongAclHyst_mps2
#define P_ODPFOP_MaxLongAclHyst_mps2 (LCF_CommonParamData.P_ODPFOP_MaxLongAclHyst_mps2) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLongAclHyst_mps2() (P_ODPFOP_MaxLongAclHyst_mps2) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLongAclHyst_mps2

#ifndef P_ODPFOP_MaxLongAcl_mps2
#define P_ODPFOP_MaxLongAcl_mps2 (LCF_CommonParamData.P_ODPFOP_MaxLongAcl_mps2) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLongAcl_mps2() (P_ODPFOP_MaxLongAcl_mps2) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLongAcl_mps2

#ifndef P_ODPFOP_MaxLongVelHyst_mps
#define P_ODPFOP_MaxLongVelHyst_mps (LCF_CommonParamData.P_ODPFOP_MaxLongVelHyst_mps) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLongVelHyst_mps() (P_ODPFOP_MaxLongVelHyst_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLongVelHyst_mps

#ifndef P_ODPFOP_MaxLongVel_mps
#define P_ODPFOP_MaxLongVel_mps (LCF_CommonParamData.P_ODPFOP_MaxLongVel_mps) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxLongVel_mps() (P_ODPFOP_MaxLongVel_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxLongVel_mps

#ifndef P_ODPFOP_MaxPosXDev_met
#define P_ODPFOP_MaxPosXDev_met (LCF_CommonParamData.P_ODPFOP_MaxPosXDev_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxPosXDev_met() (P_ODPFOP_MaxPosXDev_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxPosXDev_met

#ifndef P_ODPFOP_MaxPosYDev_met
#define P_ODPFOP_MaxPosYDev_met (LCF_CommonParamData.P_ODPFOP_MaxPosYDev_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxPosYDev_met() (P_ODPFOP_MaxPosYDev_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxPosYDev_met

#ifndef P_ODPFOP_MaxSteerAngle_rad
#define P_ODPFOP_MaxSteerAngle_rad (LCF_CommonParamData.P_ODPFOP_MaxSteerAngle_rad) //!< LCF parameter macro.
#define GET_P_ODPFOP_MaxSteerAngle_rad() (P_ODPFOP_MaxSteerAngle_rad) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MaxSteerAngle_rad

#ifndef P_ODPFOP_MinDurCamFusBefBrid_sec
#define P_ODPFOP_MinDurCamFusBefBrid_sec (LCF_CommonParamData.P_ODPFOP_MinDurCamFusBefBrid_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_MinDurCamFusBefBrid_sec() (P_ODPFOP_MinDurCamFusBefBrid_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MinDurCamFusBefBrid_sec

#ifndef P_ODPFOP_MinMeasStateForPred_sec
#define P_ODPFOP_MinMeasStateForPred_sec (LCF_CommonParamData.P_ODPFOP_MinMeasStateForPred_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_MinMeasStateForPred_sec() (P_ODPFOP_MinMeasStateForPred_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MinMeasStateForPred_sec

#ifndef P_ODPFOP_MinObjQualitiy_perc
#define P_ODPFOP_MinObjQualitiy_perc (LCF_CommonParamData.P_ODPFOP_MinObjQualitiy_perc) //!< LCF parameter macro.
#define GET_P_ODPFOP_MinObjQualitiy_perc() (P_ODPFOP_MinObjQualitiy_perc) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MinObjQualitiy_perc

#ifndef P_ODPFOP_MinWidthTgtObjHyst_met
#define P_ODPFOP_MinWidthTgtObjHyst_met (LCF_CommonParamData.P_ODPFOP_MinWidthTgtObjHyst_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_MinWidthTgtObjHyst_met() (P_ODPFOP_MinWidthTgtObjHyst_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MinWidthTgtObjHyst_met

#ifndef P_ODPFOP_MinWidthTgtObj_met
#define P_ODPFOP_MinWidthTgtObj_met (LCF_CommonParamData.P_ODPFOP_MinWidthTgtObj_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_MinWidthTgtObj_met() (P_ODPFOP_MinWidthTgtObj_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_MinWidthTgtObj_met

#ifndef P_ODPFOP_ObjLossDebounceT_sec
#define P_ODPFOP_ObjLossDebounceT_sec (LCF_CommonParamData.P_ODPFOP_ObjLossDebounceT_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjLossDebounceT_sec() (P_ODPFOP_ObjLossDebounceT_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjLossDebounceT_sec

#ifndef P_ODPFOP_ObjPosYPT1Time4Yaw_sec
#define P_ODPFOP_ObjPosYPT1Time4Yaw_sec (LCF_CommonParamData.P_ODPFOP_ObjPosYPT1Time4Yaw_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjPosYPT1Time4Yaw_sec() (P_ODPFOP_ObjPosYPT1Time4Yaw_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjPosYPT1Time4Yaw_sec

#ifndef P_ODPFOP_ObjRelToRadar_bool
#define P_ODPFOP_ObjRelToRadar_bool (LCF_CommonParamData.P_ODPFOP_ObjRelToRadar_bool) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjRelToRadar_bool() (P_ODPFOP_ObjRelToRadar_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjRelToRadar_bool

#ifndef P_ODPFOP_ObjSyncDelay_sec
#define P_ODPFOP_ObjSyncDelay_sec (LCF_CommonParamData.P_ODPFOP_ObjSyncDelay_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjSyncDelay_sec() (P_ODPFOP_ObjSyncDelay_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjSyncDelay_sec

#ifndef P_ODPFOP_ObjTypeDebounceTime_sec
#define P_ODPFOP_ObjTypeDebounceTime_sec (LCF_CommonParamData.P_ODPFOP_ObjTypeDebounceTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjTypeDebounceTime_sec() (P_ODPFOP_ObjTypeDebounceTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjTypeDebounceTime_sec

#ifndef P_ODPFOP_ObjYawPT1Time_sec
#define P_ODPFOP_ObjYawPT1Time_sec (LCF_CommonParamData.P_ODPFOP_ObjYawPT1Time_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjYawPT1Time_sec() (P_ODPFOP_ObjYawPT1Time_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjYawPT1Time_sec

#ifndef P_ODPFOP_ObjYawSampleDist_met
#define P_ODPFOP_ObjYawSampleDist_met (LCF_CommonParamData.P_ODPFOP_ObjYawSampleDist_met) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjYawSampleDist_met() (P_ODPFOP_ObjYawSampleDist_met) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjYawSampleDist_met

#ifndef P_ODPFOP_ObjYawSampleTime_sec
#define P_ODPFOP_ObjYawSampleTime_sec (LCF_CommonParamData.P_ODPFOP_ObjYawSampleTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_ObjYawSampleTime_sec() (P_ODPFOP_ObjYawSampleTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_ObjYawSampleTime_sec

#ifndef P_ODPFOP_PosStepDebounceTime_sec
#define P_ODPFOP_PosStepDebounceTime_sec (LCF_CommonParamData.P_ODPFOP_PosStepDebounceTime_sec) //!< LCF parameter macro.
#define GET_P_ODPFOP_PosStepDebounceTime_sec() (P_ODPFOP_PosStepDebounceTime_sec) //!< LCF parameter macro getter.
#endif // P_ODPFOP_PosStepDebounceTime_sec

#ifndef P_ODPFOP_RearAxleCoordSys_bool
#define P_ODPFOP_RearAxleCoordSys_bool (LCF_CommonParamData.P_ODPFOP_RearAxleCoordSys_bool) //!< LCF parameter macro.
#define GET_P_ODPFOP_RearAxleCoordSys_bool() (P_ODPFOP_RearAxleCoordSys_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOP_RearAxleCoordSys_bool

#ifndef P_ODPFOP_StandstillVelX_mps
#define P_ODPFOP_StandstillVelX_mps (LCF_CommonParamData.P_ODPFOP_StandstillVelX_mps) //!< LCF parameter macro.
#define GET_P_ODPFOP_StandstillVelX_mps() (P_ODPFOP_StandstillVelX_mps) //!< LCF parameter macro getter.
#endif // P_ODPFOP_StandstillVelX_mps

#ifndef P_ODPFOP_UseEstimPosY4Yaw_bool
#define P_ODPFOP_UseEstimPosY4Yaw_bool (LCF_CommonParamData.P_ODPFOP_UseEstimPosY4Yaw_bool) //!< LCF parameter macro.
#define GET_P_ODPFOP_UseEstimPosY4Yaw_bool() (P_ODPFOP_UseEstimPosY4Yaw_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOP_UseEstimPosY4Yaw_bool

#ifndef P_ODPFOP_UseOwnObjYaw_bool
#define P_ODPFOP_UseOwnObjYaw_bool (LCF_CommonParamData.P_ODPFOP_UseOwnObjYaw_bool) //!< LCF parameter macro.
#define GET_P_ODPFOP_UseOwnObjYaw_bool() (P_ODPFOP_UseOwnObjYaw_bool) //!< LCF parameter macro getter.
#endif // P_ODPFOP_UseOwnObjYaw_bool

#ifndef P_RDP_DlcLimitCustom_bool
#define P_RDP_DlcLimitCustom_bool (LCF_CommonParamData.P_RDP_DlcLimitCustom_bool) //!< LCF parameter macro.
#define GET_P_RDP_DlcLimitCustom_bool() (P_RDP_DlcLimitCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDP_DlcLimitCustom_bool

#ifndef P_RDP_DlcTriggerCustom_bool
#define P_RDP_DlcTriggerCustom_bool (LCF_CommonParamData.P_RDP_DlcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_RDP_DlcTriggerCustom_bool() (P_RDP_DlcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDP_DlcTriggerCustom_bool

#ifndef P_RDP_DrcLimitCustom_bool
#define P_RDP_DrcLimitCustom_bool (LCF_CommonParamData.P_RDP_DrcLimitCustom_bool) //!< LCF parameter macro.
#define GET_P_RDP_DrcLimitCustom_bool() (P_RDP_DrcLimitCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDP_DrcLimitCustom_bool

#ifndef P_RDP_DrcTriggerCustom_bool
#define P_RDP_DrcTriggerCustom_bool (LCF_CommonParamData.P_RDP_DrcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_RDP_DrcTriggerCustom_bool() (P_RDP_DrcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDP_DrcTriggerCustom_bool

#ifndef P_RDP_Existing_nu
#define P_RDP_Existing_nu (LCF_CommonParamData.P_RDP_Existing_nu) //!< LCF parameter macro.
#define GET_P_RDP_Existing_nu() (P_RDP_Existing_nu) //!< LCF parameter macro getter.
#endif // P_RDP_Existing_nu

#ifndef P_RDW_DlcLimitCustom_bool
#define P_RDW_DlcLimitCustom_bool (LCF_CommonParamData.P_RDW_DlcLimitCustom_bool) //!< LCF parameter macro.
#define GET_P_RDW_DlcLimitCustom_bool() (P_RDW_DlcLimitCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDW_DlcLimitCustom_bool

#ifndef P_RDW_DlcTriggerCustom_bool
#define P_RDW_DlcTriggerCustom_bool (LCF_CommonParamData.P_RDW_DlcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_RDW_DlcTriggerCustom_bool() (P_RDW_DlcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDW_DlcTriggerCustom_bool

#ifndef P_RDW_DrcLimitCustom_bool
#define P_RDW_DrcLimitCustom_bool (LCF_CommonParamData.P_RDW_DrcLimitCustom_bool) //!< LCF parameter macro.
#define GET_P_RDW_DrcLimitCustom_bool() (P_RDW_DrcLimitCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDW_DrcLimitCustom_bool

#ifndef P_RDW_DrcTriggerCustom_bool
#define P_RDW_DrcTriggerCustom_bool (LCF_CommonParamData.P_RDW_DrcTriggerCustom_bool) //!< LCF parameter macro.
#define GET_P_RDW_DrcTriggerCustom_bool() (P_RDW_DrcTriggerCustom_bool) //!< LCF parameter macro getter.
#endif // P_RDW_DrcTriggerCustom_bool

#ifndef P_RDW_Existing_nu
#define P_RDW_Existing_nu (LCF_CommonParamData.P_RDW_Existing_nu) //!< LCF parameter macro.
#define GET_P_RDW_Existing_nu() (P_RDW_Existing_nu) //!< LCF parameter macro getter.
#endif // P_RDW_Existing_nu

#ifndef P_TCTCDC_KMCDeltaPsiAttenu_nu
#define P_TCTCDC_KMCDeltaPsiAttenu_nu (LCF_CommonParamData.P_TCTCDC_KMCDeltaPsiAttenu_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_KMCDeltaPsiAttenu_nu() (P_TCTCDC_KMCDeltaPsiAttenu_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_KMCDeltaPsiAttenu_nu

#ifndef P_TCTCDC_KMCDeltaPsiObsGain_nu
#define P_TCTCDC_KMCDeltaPsiObsGain_nu (LCF_CommonParamData.P_TCTCDC_KMCDeltaPsiObsGain_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_KMCDeltaPsiObsGain_nu() (P_TCTCDC_KMCDeltaPsiObsGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_KMCDeltaPsiObsGain_nu

#ifndef P_TCTCDC_OssDeltaTheta_nu
#define P_TCTCDC_OssDeltaTheta_nu (LCF_CommonParamData.P_TCTCDC_OssDeltaTheta_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_OssDeltaTheta_nu() (P_TCTCDC_OssDeltaTheta_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_OssDeltaTheta_nu

#ifndef P_TCTCDC_OssDeltaY_nu
#define P_TCTCDC_OssDeltaY_nu (LCF_CommonParamData.P_TCTCDC_OssDeltaY_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_OssDeltaY_nu() (P_TCTCDC_OssDeltaY_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_OssDeltaY_nu

#ifndef P_TCTCDC_PT1CurDistYTime_sec
#define P_TCTCDC_PT1CurDistYTime_sec (LCF_CommonParamData.P_TCTCDC_PT1CurDistYTime_sec) //!< LCF parameter macro.
#define GET_P_TCTCDC_PT1CurDistYTime_sec() (P_TCTCDC_PT1CurDistYTime_sec) //!< LCF parameter macro getter.
#endif // P_TCTCDC_PT1CurDistYTime_sec

#ifndef P_TCTCDC_PT1CurHeadingTime_sec
#define P_TCTCDC_PT1CurHeadingTime_sec (LCF_CommonParamData.P_TCTCDC_PT1CurHeadingTime_sec) //!< LCF parameter macro.
#define GET_P_TCTCDC_PT1CurHeadingTime_sec() (P_TCTCDC_PT1CurHeadingTime_sec) //!< LCF parameter macro getter.
#endif // P_TCTCDC_PT1CurHeadingTime_sec

#ifndef P_TCTCDC_UseAltOBFApproach_nu
#define P_TCTCDC_UseAltOBFApproach_nu (LCF_CommonParamData.P_TCTCDC_UseAltOBFApproach_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_UseAltOBFApproach_nu() (P_TCTCDC_UseAltOBFApproach_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_UseAltOBFApproach_nu

#ifndef P_TCTCDC_UseTrajCrv_nu
#define P_TCTCDC_UseTrajCrv_nu (LCF_CommonParamData.P_TCTCDC_UseTrajCrv_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_UseTrajCrv_nu() (P_TCTCDC_UseTrajCrv_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_UseTrajCrv_nu

#ifndef P_TCTCDC_WtchdgActive_nu
#define P_TCTCDC_WtchdgActive_nu (LCF_CommonParamData.P_TCTCDC_WtchdgActive_nu) //!< LCF parameter macro.
#define GET_P_TCTCDC_WtchdgActive_nu() (P_TCTCDC_WtchdgActive_nu) //!< LCF parameter macro getter.
#endif // P_TCTCDC_WtchdgActive_nu

#ifndef P_TCTCDC_WtchdgLimCoAnErr_rad
#define P_TCTCDC_WtchdgLimCoAnErr_rad (LCF_CommonParamData.P_TCTCDC_WtchdgLimCoAnErr_rad) //!< LCF parameter macro.
#define GET_P_TCTCDC_WtchdgLimCoAnErr_rad() (P_TCTCDC_WtchdgLimCoAnErr_rad) //!< LCF parameter macro getter.
#endif // P_TCTCDC_WtchdgLimCoAnErr_rad

#ifndef P_TCTCDC_WtchdgLimYErr_m
#define P_TCTCDC_WtchdgLimYErr_m (LCF_CommonParamData.P_TCTCDC_WtchdgLimYErr_m) //!< LCF parameter macro.
#define GET_P_TCTCDC_WtchdgLimYErr_m() (P_TCTCDC_WtchdgLimYErr_m) //!< LCF parameter macro getter.
#endif // P_TCTCDC_WtchdgLimYErr_m

#ifndef P_TCTCLM_ErrCntrCyclesToCheck_nu
#define P_TCTCLM_ErrCntrCyclesToCheck_nu (LCF_CommonParamData.P_TCTCLM_ErrCntrCyclesToCheck_nu) //!< LCF parameter macro.
#define GET_P_TCTCLM_ErrCntrCyclesToCheck_nu() (P_TCTCLM_ErrCntrCyclesToCheck_nu) //!< LCF parameter macro getter.
#endif // P_TCTCLM_ErrCntrCyclesToCheck_nu

#ifndef P_TCTCLM_ErrCntrDisengageThr_nu
#define P_TCTCLM_ErrCntrDisengageThr_nu (LCF_CommonParamData.P_TCTCLM_ErrCntrDisengageThr_nu) //!< LCF parameter macro.
#define GET_P_TCTCLM_ErrCntrDisengageThr_nu() (P_TCTCLM_ErrCntrDisengageThr_nu) //!< LCF parameter macro getter.
#endif // P_TCTCLM_ErrCntrDisengageThr_nu

#ifndef P_TCTCLM_FbcCrvInterface_nu
#define P_TCTCLM_FbcCrvInterface_nu (LCF_CommonParamData.P_TCTCLM_FbcCrvInterface_nu) //!< LCF parameter macro.
#define GET_P_TCTCLM_FbcCrvInterface_nu() (P_TCTCLM_FbcCrvInterface_nu) //!< LCF parameter macro getter.
#endif // P_TCTCLM_FbcCrvInterface_nu

#ifndef P_TCTCLM_FfcCrvInterface_nu
#define P_TCTCLM_FfcCrvInterface_nu (LCF_CommonParamData.P_TCTCLM_FfcCrvInterface_nu) //!< LCF parameter macro.
#define GET_P_TCTCLM_FfcCrvInterface_nu() (P_TCTCLM_FfcCrvInterface_nu) //!< LCF parameter macro getter.
#endif // P_TCTCLM_FfcCrvInterface_nu

#ifndef P_TCTCLM_QuServiceErrMemAct_nu
#define P_TCTCLM_QuServiceErrMemAct_nu (LCF_CommonParamData.P_TCTCLM_QuServiceErrMemAct_nu) //!< LCF parameter macro.
#define GET_P_TCTCLM_QuServiceErrMemAct_nu() (P_TCTCLM_QuServiceErrMemAct_nu) //!< LCF parameter macro getter.
#endif // P_TCTCLM_QuServiceErrMemAct_nu

#ifndef P_TCTCLM_QuServiceMaxTime_sec
#define P_TCTCLM_QuServiceMaxTime_sec (LCF_CommonParamData.P_TCTCLM_QuServiceMaxTime_sec) //!< LCF parameter macro.
#define GET_P_TCTCLM_QuServiceMaxTime_sec() (P_TCTCLM_QuServiceMaxTime_sec) //!< LCF parameter macro getter.
#endif // P_TCTCLM_QuServiceMaxTime_sec

#ifndef P_TCTCLM_QuServiceMinTime_sec
#define P_TCTCLM_QuServiceMinTime_sec (LCF_CommonParamData.P_TCTCLM_QuServiceMinTime_sec) //!< LCF parameter macro.
#define GET_P_TCTCLM_QuServiceMinTime_sec() (P_TCTCLM_QuServiceMinTime_sec) //!< LCF parameter macro getter.
#endif // P_TCTCLM_QuServiceMinTime_sec

#ifndef P_TCTCLM_QuServiceOverride_nu
#define P_TCTCLM_QuServiceOverride_nu (LCF_CommonParamData.P_TCTCLM_QuServiceOverride_nu) //!< LCF parameter macro.
#define GET_P_TCTCLM_QuServiceOverride_nu() (P_TCTCLM_QuServiceOverride_nu) //!< LCF parameter macro getter.
#endif // P_TCTCLM_QuServiceOverride_nu

#ifndef P_TCTCLM_WtchdgCDCQuSv_btm
#define P_TCTCLM_WtchdgCDCQuSv_btm (LCF_CommonParamData.P_TCTCLM_WtchdgCDCQuSv_btm) //!< LCF parameter macro.
#define GET_P_TCTCLM_WtchdgCDCQuSv_btm() (P_TCTCLM_WtchdgCDCQuSv_btm) //!< LCF parameter macro getter.
#endif // P_TCTCLM_WtchdgCDCQuSv_btm

#ifndef P_TCTCLM_WtchdgCLMQuSv_btm
#define P_TCTCLM_WtchdgCLMQuSv_btm (LCF_CommonParamData.P_TCTCLM_WtchdgCLMQuSv_btm) //!< LCF parameter macro.
#define GET_P_TCTCLM_WtchdgCLMQuSv_btm() (P_TCTCLM_WtchdgCLMQuSv_btm) //!< LCF parameter macro getter.
#endif // P_TCTCLM_WtchdgCLMQuSv_btm

#ifndef P_TCTDTE_BnkAglCompActive_nu
#define P_TCTDTE_BnkAglCompActive_nu (LCF_CommonParamData.P_TCTDTE_BnkAglCompActive_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_BnkAglCompActive_nu() (P_TCTDTE_BnkAglCompActive_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_BnkAglCompActive_nu

#ifndef P_TCTDTE_BnkAglCrvReqGrd_1pms
#define P_TCTDTE_BnkAglCrvReqGrd_1pms (LCF_CommonParamData.P_TCTDTE_BnkAglCrvReqGrd_1pms) //!< LCF parameter macro.
#define GET_P_TCTDTE_BnkAglCrvReqGrd_1pms() (P_TCTDTE_BnkAglCrvReqGrd_1pms) //!< LCF parameter macro getter.
#endif // P_TCTDTE_BnkAglCrvReqGrd_1pms

#ifndef P_TCTDTE_CroCGainS1_nu
#define P_TCTDTE_CroCGainS1_nu (LCF_CommonParamData.P_TCTDTE_CroCGainS1_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_CroCGainS1_nu() (P_TCTDTE_CroCGainS1_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_CroCGainS1_nu

#ifndef P_TCTDTE_CroCGainS2_nu
#define P_TCTDTE_CroCGainS2_nu (LCF_CommonParamData.P_TCTDTE_CroCGainS2_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_CroCGainS2_nu() (P_TCTDTE_CroCGainS2_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_CroCGainS2_nu

#ifndef P_TCTDTE_CroWindCompActive_nu
#define P_TCTDTE_CroWindCompActive_nu (LCF_CommonParamData.P_TCTDTE_CroWindCompActive_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_CroWindCompActive_nu() (P_TCTDTE_CroWindCompActive_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_CroWindCompActive_nu

#ifndef P_TCTDTE_CroWindDeltaSetGain_nu
#define P_TCTDTE_CroWindDeltaSetGain_nu (LCF_CommonParamData.P_TCTDTE_CroWindDeltaSetGain_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_CroWindDeltaSetGain_nu() (P_TCTDTE_CroWindDeltaSetGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_CroWindDeltaSetGain_nu

#ifndef P_TCTDTE_CrvReqBnkAglGain_nu
#define P_TCTDTE_CrvReqBnkAglGain_nu (LCF_CommonParamData.P_TCTDTE_CrvReqBnkAglGain_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_CrvReqBnkAglGain_nu() (P_TCTDTE_CrvReqBnkAglGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_CrvReqBnkAglGain_nu

#ifndef P_TCTDTE_DelayCyclesDeltaDi_nu
#define P_TCTDTE_DelayCyclesDeltaDi_nu (LCF_CommonParamData.P_TCTDTE_DelayCyclesDeltaDi_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_DelayCyclesDeltaDi_nu() (P_TCTDTE_DelayCyclesDeltaDi_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DelayCyclesDeltaDi_nu

#ifndef P_TCTDTE_DelayCyclesLaDMC_nu
#define P_TCTDTE_DelayCyclesLaDMC_nu (LCF_CommonParamData.P_TCTDTE_DelayCyclesLaDMC_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_DelayCyclesLaDMC_nu() (P_TCTDTE_DelayCyclesLaDMC_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DelayCyclesLaDMC_nu

#ifndef P_TCTDTE_DeltaSetBnkAglGain_nu
#define P_TCTDTE_DeltaSetBnkAglGain_nu (LCF_CommonParamData.P_TCTDTE_DeltaSetBnkAglGain_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_DeltaSetBnkAglGain_nu() (P_TCTDTE_DeltaSetBnkAglGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DeltaSetBnkAglGain_nu

#ifndef P_TCTDTE_DistrbCompActive_nu
#define P_TCTDTE_DistrbCompActive_nu (LCF_CommonParamData.P_TCTDTE_DistrbCompActive_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_DistrbCompActive_nu() (P_TCTDTE_DistrbCompActive_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DistrbCompActive_nu

#ifndef P_TCTDTE_DmcT1_sec
#define P_TCTDTE_DmcT1_sec (LCF_CommonParamData.P_TCTDTE_DmcT1_sec) //!< LCF parameter macro.
#define GET_P_TCTDTE_DmcT1_sec() (P_TCTDTE_DmcT1_sec) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DmcT1_sec

#ifndef P_TCTDTE_DmcT1comp_sec
#define P_TCTDTE_DmcT1comp_sec (LCF_CommonParamData.P_TCTDTE_DmcT1comp_sec) //!< LCF parameter macro.
#define GET_P_TCTDTE_DmcT1comp_sec() (P_TCTDTE_DmcT1comp_sec) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DmcT1comp_sec

#ifndef P_TCTDTE_DmcT2_sec
#define P_TCTDTE_DmcT2_sec (LCF_CommonParamData.P_TCTDTE_DmcT2_sec) //!< LCF parameter macro.
#define GET_P_TCTDTE_DmcT2_sec() (P_TCTDTE_DmcT2_sec) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DmcT2_sec

#ifndef P_TCTDTE_DmcT2comp_sec
#define P_TCTDTE_DmcT2comp_sec (LCF_CommonParamData.P_TCTDTE_DmcT2comp_sec) //!< LCF parameter macro.
#define GET_P_TCTDTE_DmcT2comp_sec() (P_TCTDTE_DmcT2comp_sec) //!< LCF parameter macro getter.
#endif // P_TCTDTE_DmcT2comp_sec

#ifndef P_TCTDTE_Dss_nu
#define P_TCTDTE_Dss_nu (LCF_CommonParamData.P_TCTDTE_Dss_nu) //!< LCF parameter macro.
#define GET_P_TCTDTE_Dss_nu() (P_TCTDTE_Dss_nu) //!< LCF parameter macro getter.
#endif // P_TCTDTE_Dss_nu

#ifndef P_TCTDTE_MinimumSpeed_mps
#define P_TCTDTE_MinimumSpeed_mps (LCF_CommonParamData.P_TCTDTE_MinimumSpeed_mps) //!< LCF parameter macro.
#define GET_P_TCTDTE_MinimumSpeed_mps() (P_TCTDTE_MinimumSpeed_mps) //!< LCF parameter macro getter.
#endif // P_TCTDTE_MinimumSpeed_mps

#ifndef P_TCTDTE_PT1CrvReqBAC_sec
#define P_TCTDTE_PT1CrvReqBAC_sec (LCF_CommonParamData.P_TCTDTE_PT1CrvReqBAC_sec) //!< LCF parameter macro.
#define GET_P_TCTDTE_PT1CrvReqBAC_sec() (P_TCTDTE_PT1CrvReqBAC_sec) //!< LCF parameter macro getter.
#endif // P_TCTDTE_PT1CrvReqBAC_sec

#ifndef P_TCTDTE_TConstSteerAngle_sec
#define P_TCTDTE_TConstSteerAngle_sec (LCF_CommonParamData.P_TCTDTE_TConstSteerAngle_sec) //!< LCF parameter macro.
#define GET_P_TCTDTE_TConstSteerAngle_sec() (P_TCTDTE_TConstSteerAngle_sec) //!< LCF parameter macro getter.
#endif // P_TCTDTE_TConstSteerAngle_sec

#ifndef P_TCTEST_DelayCyclesDeltaSs_nu
#define P_TCTEST_DelayCyclesDeltaSs_nu (LCF_CommonParamData.P_TCTEST_DelayCyclesDeltaSs_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_DelayCyclesDeltaSs_nu() (P_TCTEST_DelayCyclesDeltaSs_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_DelayCyclesDeltaSs_nu

#ifndef P_TCTEST_HdrDThetaDotEnd_rps
#define P_TCTEST_HdrDThetaDotEnd_rps (LCF_CommonParamData.P_TCTEST_HdrDThetaDotEnd_rps) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrDThetaDotEnd_rps() (P_TCTEST_HdrDThetaDotEnd_rps) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrDThetaDotEnd_rps

#ifndef P_TCTEST_HdrDThetaDotPT1Time_sec
#define P_TCTEST_HdrDThetaDotPT1Time_sec (LCF_CommonParamData.P_TCTEST_HdrDThetaDotPT1Time_sec) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrDThetaDotPT1Time_sec() (P_TCTEST_HdrDThetaDotPT1Time_sec) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrDThetaDotPT1Time_sec

#ifndef P_TCTEST_HdrDThetaDotStart_rps
#define P_TCTEST_HdrDThetaDotStart_rps (LCF_CommonParamData.P_TCTEST_HdrDThetaDotStart_rps) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrDThetaDotStart_rps() (P_TCTEST_HdrDThetaDotStart_rps) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrDThetaDotStart_rps

#ifndef P_TCTEST_HdrDYDotEnd_mps
#define P_TCTEST_HdrDYDotEnd_mps (LCF_CommonParamData.P_TCTEST_HdrDYDotEnd_mps) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrDYDotEnd_mps() (P_TCTEST_HdrDYDotEnd_mps) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrDYDotEnd_mps

#ifndef P_TCTEST_HdrDYDotPT1Time_sec
#define P_TCTEST_HdrDYDotPT1Time_sec (LCF_CommonParamData.P_TCTEST_HdrDYDotPT1Time_sec) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrDYDotPT1Time_sec() (P_TCTEST_HdrDYDotPT1Time_sec) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrDYDotPT1Time_sec

#ifndef P_TCTEST_HdrDYDotStart_mps
#define P_TCTEST_HdrDYDotStart_mps (LCF_CommonParamData.P_TCTEST_HdrDYDotStart_mps) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrDYDotStart_mps() (P_TCTEST_HdrDYDotStart_mps) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrDYDotStart_mps

#ifndef P_TCTEST_HdrMeanDThetaWghtOf_nu
#define P_TCTEST_HdrMeanDThetaWghtOf_nu (LCF_CommonParamData.P_TCTEST_HdrMeanDThetaWghtOf_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrMeanDThetaWghtOf_nu() (P_TCTEST_HdrMeanDThetaWghtOf_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrMeanDThetaWghtOf_nu

#ifndef P_TCTEST_HdrMeanDThetaWghtSf_nu
#define P_TCTEST_HdrMeanDThetaWghtSf_nu (LCF_CommonParamData.P_TCTEST_HdrMeanDThetaWghtSf_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrMeanDThetaWghtSf_nu() (P_TCTEST_HdrMeanDThetaWghtSf_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrMeanDThetaWghtSf_nu

#ifndef P_TCTEST_HdrMeanDThetaWght_nu
#define P_TCTEST_HdrMeanDThetaWght_nu (LCF_CommonParamData.P_TCTEST_HdrMeanDThetaWght_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrMeanDThetaWght_nu() (P_TCTEST_HdrMeanDThetaWght_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrMeanDThetaWght_nu

#ifndef P_TCTEST_HdrMeanDYWghtOf_nu
#define P_TCTEST_HdrMeanDYWghtOf_nu (LCF_CommonParamData.P_TCTEST_HdrMeanDYWghtOf_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrMeanDYWghtOf_nu() (P_TCTEST_HdrMeanDYWghtOf_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrMeanDYWghtOf_nu

#ifndef P_TCTEST_HdrMeanDYWghtSf_nu
#define P_TCTEST_HdrMeanDYWghtSf_nu (LCF_CommonParamData.P_TCTEST_HdrMeanDYWghtSf_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrMeanDYWghtSf_nu() (P_TCTEST_HdrMeanDYWghtSf_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrMeanDYWghtSf_nu

#ifndef P_TCTEST_HdrMeanDYWght_nu
#define P_TCTEST_HdrMeanDYWght_nu (LCF_CommonParamData.P_TCTEST_HdrMeanDYWght_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_HdrMeanDYWght_nu() (P_TCTEST_HdrMeanDYWght_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_HdrMeanDYWght_nu

#ifndef P_TCTEST_IssPlObsCurvature_nu
#define P_TCTEST_IssPlObsCurvature_nu (LCF_CommonParamData.P_TCTEST_IssPlObsCurvature_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_IssPlObsCurvature_nu() (P_TCTEST_IssPlObsCurvature_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_IssPlObsCurvature_nu

#ifndef P_TCTEST_MinimumSpeed_mps
#define P_TCTEST_MinimumSpeed_mps (LCF_CommonParamData.P_TCTEST_MinimumSpeed_mps) //!< LCF parameter macro.
#define GET_P_TCTEST_MinimumSpeed_mps() (P_TCTEST_MinimumSpeed_mps) //!< LCF parameter macro getter.
#endif // P_TCTEST_MinimumSpeed_mps

#ifndef P_TCTEST_PT1CrObsCrosswind_sec
#define P_TCTEST_PT1CrObsCrosswind_sec (LCF_CommonParamData.P_TCTEST_PT1CrObsCrosswind_sec) //!< LCF parameter macro.
#define GET_P_TCTEST_PT1CrObsCrosswind_sec() (P_TCTEST_PT1CrObsCrosswind_sec) //!< LCF parameter macro getter.
#endif // P_TCTEST_PT1CrObsCrosswind_sec

#ifndef P_TCTEST_PT1PlObsInCurvature_sec
#define P_TCTEST_PT1PlObsInCurvature_sec (LCF_CommonParamData.P_TCTEST_PT1PlObsInCurvature_sec) //!< LCF parameter macro.
#define GET_P_TCTEST_PT1PlObsInCurvature_sec() (P_TCTEST_PT1PlObsInCurvature_sec) //!< LCF parameter macro getter.
#endif // P_TCTEST_PT1PlObsInCurvature_sec

#ifndef P_TCTEST_SObsActive_nu
#define P_TCTEST_SObsActive_nu (LCF_CommonParamData.P_TCTEST_SObsActive_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_SObsActive_nu() (P_TCTEST_SObsActive_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_SObsActive_nu

#ifndef P_TCTEST_UseSteerAngleLatDMC_nu
#define P_TCTEST_UseSteerAngleLatDMC_nu (LCF_CommonParamData.P_TCTEST_UseSteerAngleLatDMC_nu) //!< LCF parameter macro.
#define GET_P_TCTEST_UseSteerAngleLatDMC_nu() (P_TCTEST_UseSteerAngleLatDMC_nu) //!< LCF parameter macro getter.
#endif // P_TCTEST_UseSteerAngleLatDMC_nu

#ifndef P_TCTFFC_DecelAclXGrdLD_mps3
#define P_TCTFFC_DecelAclXGrdLD_mps3 (LCF_CommonParamData.P_TCTFFC_DecelAclXGrdLD_mps3) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelAclXGrdLD_mps3() (P_TCTFFC_DecelAclXGrdLD_mps3) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelAclXGrdLD_mps3

#ifndef P_TCTFFC_DecelAclXGrdLU_mps3
#define P_TCTFFC_DecelAclXGrdLU_mps3 (LCF_CommonParamData.P_TCTFFC_DecelAclXGrdLU_mps3) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelAclXGrdLU_mps3() (P_TCTFFC_DecelAclXGrdLU_mps3) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelAclXGrdLU_mps3

#ifndef P_TCTFFC_DecelHystLSP_mps2
#define P_TCTFFC_DecelHystLSP_mps2 (LCF_CommonParamData.P_TCTFFC_DecelHystLSP_mps2) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelHystLSP_mps2() (P_TCTFFC_DecelHystLSP_mps2) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelHystLSP_mps2

#ifndef P_TCTFFC_DecelModeHyst_nu
#define P_TCTFFC_DecelModeHyst_nu (LCF_CommonParamData.P_TCTFFC_DecelModeHyst_nu) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelModeHyst_nu() (P_TCTFFC_DecelModeHyst_nu) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelModeHyst_nu

#ifndef P_TCTFFC_DecelReduction_perc
#define P_TCTFFC_DecelReduction_perc (LCF_CommonParamData.P_TCTFFC_DecelReduction_perc) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelReduction_perc() (P_TCTFFC_DecelReduction_perc) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelReduction_perc

#ifndef P_TCTFFC_DecelThrsAxEnd_mps2
#define P_TCTFFC_DecelThrsAxEnd_mps2 (LCF_CommonParamData.P_TCTFFC_DecelThrsAxEnd_mps2) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelThrsAxEnd_mps2() (P_TCTFFC_DecelThrsAxEnd_mps2) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelThrsAxEnd_mps2

#ifndef P_TCTFFC_DecelThrsAxStart_mps2
#define P_TCTFFC_DecelThrsAxStart_mps2 (LCF_CommonParamData.P_TCTFFC_DecelThrsAxStart_mps2) //!< LCF parameter macro.
#define GET_P_TCTFFC_DecelThrsAxStart_mps2() (P_TCTFFC_DecelThrsAxStart_mps2) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DecelThrsAxStart_mps2

#ifndef P_TCTFFC_DynGainFadingTime_sec
#define P_TCTFFC_DynGainFadingTime_sec (LCF_CommonParamData.P_TCTFFC_DynGainFadingTime_sec) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainFadingTime_sec() (P_TCTFFC_DynGainFadingTime_sec) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainFadingTime_sec

#ifndef P_TCTFFC_DynGainMaxAdaption_perc
#define P_TCTFFC_DynGainMaxAdaption_perc (LCF_CommonParamData.P_TCTFFC_DynGainMaxAdaption_perc) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainMaxAdaption_perc() (P_TCTFFC_DynGainMaxAdaption_perc) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainMaxAdaption_perc

#ifndef P_TCTFFC_DynGainMode_btm
#define P_TCTFFC_DynGainMode_btm (LCF_CommonParamData.P_TCTFFC_DynGainMode_btm) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainMode_btm() (P_TCTFFC_DynGainMode_btm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainMode_btm

#ifndef P_TCTFFC_DynGainPreThrDY_met
#define P_TCTFFC_DynGainPreThrDY_met (LCF_CommonParamData.P_TCTFFC_DynGainPreThrDY_met) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainPreThrDY_met() (P_TCTFFC_DynGainPreThrDY_met) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainPreThrDY_met

#ifndef P_TCTFFC_DynGainPreThrDriver_Nm
#define P_TCTFFC_DynGainPreThrDriver_Nm (LCF_CommonParamData.P_TCTFFC_DynGainPreThrDriver_Nm) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainPreThrDriver_Nm() (P_TCTFFC_DynGainPreThrDriver_Nm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainPreThrDriver_Nm

#ifndef P_TCTFFC_DynGainPrecCtrlFcn_btm
#define P_TCTFFC_DynGainPrecCtrlFcn_btm (LCF_CommonParamData.P_TCTFFC_DynGainPrecCtrlFcn_btm) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainPrecCtrlFcn_btm() (P_TCTFFC_DynGainPrecCtrlFcn_btm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainPrecCtrlFcn_btm

#ifndef P_TCTFFC_DynGainPrecCtrlMode_btm
#define P_TCTFFC_DynGainPrecCtrlMode_btm (LCF_CommonParamData.P_TCTFFC_DynGainPrecCtrlMode_btm) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainPrecCtrlMode_btm() (P_TCTFFC_DynGainPrecCtrlMode_btm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainPrecCtrlMode_btm

#ifndef P_TCTFFC_DynGainPrecSelect_btm
#define P_TCTFFC_DynGainPrecSelect_btm (LCF_CommonParamData.P_TCTFFC_DynGainPrecSelect_btm) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainPrecSelect_btm() (P_TCTFFC_DynGainPrecSelect_btm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainPrecSelect_btm

#ifndef P_TCTFFC_DynGainPrecThrKappa_1pm
#define P_TCTFFC_DynGainPrecThrKappa_1pm (LCF_CommonParamData.P_TCTFFC_DynGainPrecThrKappa_1pm) //!< LCF parameter macro.
#define GET_P_TCTFFC_DynGainPrecThrKappa_1pm() (P_TCTFFC_DynGainPrecThrKappa_1pm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_DynGainPrecThrKappa_1pm

#ifndef P_TCTFFC_OssDynGain_btm
#define P_TCTFFC_OssDynGain_btm (LCF_CommonParamData.P_TCTFFC_OssDynGain_btm) //!< LCF parameter macro.
#define GET_P_TCTFFC_OssDynGain_btm() (P_TCTFFC_OssDynGain_btm) //!< LCF parameter macro getter.
#endif // P_TCTFFC_OssDynGain_btm

#ifndef P_TCTFFC_OssFfcCrv_nu
#define P_TCTFFC_OssFfcCrv_nu (LCF_CommonParamData.P_TCTFFC_OssFfcCrv_nu) //!< LCF parameter macro.
#define GET_P_TCTFFC_OssFfcCrv_nu() (P_TCTFFC_OssFfcCrv_nu) //!< LCF parameter macro getter.
#endif // P_TCTFFC_OssFfcCrv_nu

#ifndef P_TCTFFC_PT1TgtCrvFiltTime_sec
#define P_TCTFFC_PT1TgtCrvFiltTime_sec (LCF_CommonParamData.P_TCTFFC_PT1TgtCrvFiltTime_sec) //!< LCF parameter macro.
#define GET_P_TCTFFC_PT1TgtCrvFiltTime_sec() (P_TCTFFC_PT1TgtCrvFiltTime_sec) //!< LCF parameter macro getter.
#endif // P_TCTFFC_PT1TgtCrvFiltTime_sec

#ifndef P_TCTFFC_UpDwnHllReduction_perc
#define P_TCTFFC_UpDwnHllReduction_perc (LCF_CommonParamData.P_TCTFFC_UpDwnHllReduction_perc) //!< LCF parameter macro.
#define GET_P_TCTFFC_UpDwnHllReduction_perc() (P_TCTFFC_UpDwnHllReduction_perc) //!< LCF parameter macro getter.
#endif // P_TCTFFC_UpDwnHllReduction_perc

#ifndef P_TCTFFC_UpDwnHllThres_perc
#define P_TCTFFC_UpDwnHllThres_perc (LCF_CommonParamData.P_TCTFFC_UpDwnHllThres_perc) //!< LCF parameter macro.
#define GET_P_TCTFFC_UpDwnHllThres_perc() (P_TCTFFC_UpDwnHllThres_perc) //!< LCF parameter macro getter.
#endif // P_TCTFFC_UpDwnHllThres_perc

#ifndef P_TCTFFC_UseAltOBFApproach_nu
#define P_TCTFFC_UseAltOBFApproach_nu (LCF_CommonParamData.P_TCTFFC_UseAltOBFApproach_nu) //!< LCF parameter macro.
#define GET_P_TCTFFC_UseAltOBFApproach_nu() (P_TCTFFC_UseAltOBFApproach_nu) //!< LCF parameter macro getter.
#endif // P_TCTFFC_UseAltOBFApproach_nu

#ifndef P_TCTLGC_ActivateDynBacGain_nu
#define P_TCTLGC_ActivateDynBacGain_nu (LCF_CommonParamData.P_TCTLGC_ActivateDynBacGain_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_ActivateDynBacGain_nu() (P_TCTLGC_ActivateDynBacGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_ActivateDynBacGain_nu

#ifndef P_TCTLGC_ActivateOverride_nu
#define P_TCTLGC_ActivateOverride_nu (LCF_CommonParamData.P_TCTLGC_ActivateOverride_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_ActivateOverride_nu() (P_TCTLGC_ActivateOverride_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_ActivateOverride_nu

#ifndef P_TCTLGC_CacILimit_rad
#define P_TCTLGC_CacILimit_rad (LCF_CommonParamData.P_TCTLGC_CacILimit_rad) //!< LCF parameter macro.
#define GET_P_TCTLGC_CacILimit_rad() (P_TCTLGC_CacILimit_rad) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CacILimit_rad

#ifndef P_TCTLGC_CacLaDmcCompEnable_nu
#define P_TCTLGC_CacLaDmcCompEnable_nu (LCF_CommonParamData.P_TCTLGC_CacLaDmcCompEnable_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CacLaDmcCompEnable_nu() (P_TCTLGC_CacLaDmcCompEnable_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CacLaDmcCompEnable_nu

#ifndef P_TCTLGC_CacMode_nu
#define P_TCTLGC_CacMode_nu (LCF_CommonParamData.P_TCTLGC_CacMode_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CacMode_nu() (P_TCTLGC_CacMode_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CacMode_nu

#ifndef P_TCTLGC_CacOfPGain_nu
#define P_TCTLGC_CacOfPGain_nu (LCF_CommonParamData.P_TCTLGC_CacOfPGain_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CacOfPGain_nu() (P_TCTLGC_CacOfPGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CacOfPGain_nu

#ifndef P_TCTLGC_CacPGain_nu
#define P_TCTLGC_CacPGain_nu (LCF_CommonParamData.P_TCTLGC_CacPGain_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CacPGain_nu() (P_TCTLGC_CacPGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CacPGain_nu

#ifndef P_TCTLGC_CacSfPGain_nu
#define P_TCTLGC_CacSfPGain_nu (LCF_CommonParamData.P_TCTLGC_CacSfPGain_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CacSfPGain_nu() (P_TCTLGC_CacSfPGain_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CacSfPGain_nu

#ifndef P_TCTLGC_CssCrv_nu
#define P_TCTLGC_CssCrv_nu (LCF_CommonParamData.P_TCTLGC_CssCrv_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CssCrv_nu() (P_TCTLGC_CssCrv_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CssCrv_nu

#ifndef P_TCTLGC_CssDeltaF_nu
#define P_TCTLGC_CssDeltaF_nu (LCF_CommonParamData.P_TCTLGC_CssDeltaF_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_CssDeltaF_nu() (P_TCTLGC_CssDeltaF_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_CssDeltaF_nu

#ifndef P_TCTLGC_DynIntResetSelect_nu
#define P_TCTLGC_DynIntResetSelect_nu (LCF_CommonParamData.P_TCTLGC_DynIntResetSelect_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_DynIntResetSelect_nu() (P_TCTLGC_DynIntResetSelect_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_DynIntResetSelect_nu

#ifndef P_TCTLGC_DynPT1ResetSelect_nu
#define P_TCTLGC_DynPT1ResetSelect_nu (LCF_CommonParamData.P_TCTLGC_DynPT1ResetSelect_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_DynPT1ResetSelect_nu() (P_TCTLGC_DynPT1ResetSelect_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_DynPT1ResetSelect_nu

#ifndef P_TCTLGC_IntResMaxCrv_1pm
#define P_TCTLGC_IntResMaxCrv_1pm (LCF_CommonParamData.P_TCTLGC_IntResMaxCrv_1pm) //!< LCF parameter macro.
#define GET_P_TCTLGC_IntResMaxCrv_1pm() (P_TCTLGC_IntResMaxCrv_1pm) //!< LCF parameter macro getter.
#endif // P_TCTLGC_IntResMaxCrv_1pm

#ifndef P_TCTLGC_IntResMaxLatErr_m
#define P_TCTLGC_IntResMaxLatErr_m (LCF_CommonParamData.P_TCTLGC_IntResMaxLatErr_m) //!< LCF parameter macro.
#define GET_P_TCTLGC_IntResMaxLatErr_m() (P_TCTLGC_IntResMaxLatErr_m) //!< LCF parameter macro getter.
#endif // P_TCTLGC_IntResMaxLatErr_m

#ifndef P_TCTLGC_IntResMaxManTrq_Nm
#define P_TCTLGC_IntResMaxManTrq_Nm (LCF_CommonParamData.P_TCTLGC_IntResMaxManTrq_Nm) //!< LCF parameter macro.
#define GET_P_TCTLGC_IntResMaxManTrq_Nm() (P_TCTLGC_IntResMaxManTrq_Nm) //!< LCF parameter macro getter.
#endif // P_TCTLGC_IntResMaxManTrq_Nm

#ifndef P_TCTLGC_LdcILimit_rad
#define P_TCTLGC_LdcILimit_rad (LCF_CommonParamData.P_TCTLGC_LdcILimit_rad) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcILimit_rad() (P_TCTLGC_LdcILimit_rad) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcILimit_rad

#ifndef P_TCTLGC_LdcLaDmcCompEnable_nu
#define P_TCTLGC_LdcLaDmcCompEnable_nu (LCF_CommonParamData.P_TCTLGC_LdcLaDmcCompEnable_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcLaDmcCompEnable_nu() (P_TCTLGC_LdcLaDmcCompEnable_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcLaDmcCompEnable_nu

#ifndef P_TCTLGC_LdcMode_nu
#define P_TCTLGC_LdcMode_nu (LCF_CommonParamData.P_TCTLGC_LdcMode_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcMode_nu() (P_TCTLGC_LdcMode_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcMode_nu

#ifndef P_TCTLGC_LdcOfP_radpm
#define P_TCTLGC_LdcOfP_radpm (LCF_CommonParamData.P_TCTLGC_LdcOfP_radpm) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcOfP_radpm() (P_TCTLGC_LdcOfP_radpm) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcOfP_radpm

#ifndef P_TCTLGC_LdcPT1MaxGrd_radpms
#define P_TCTLGC_LdcPT1MaxGrd_radpms (LCF_CommonParamData.P_TCTLGC_LdcPT1MaxGrd_radpms) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcPT1MaxGrd_radpms() (P_TCTLGC_LdcPT1MaxGrd_radpms) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcPT1MaxGrd_radpms

#ifndef P_TCTLGC_LdcP_radpm
#define P_TCTLGC_LdcP_radpm (LCF_CommonParamData.P_TCTLGC_LdcP_radpm) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcP_radpm() (P_TCTLGC_LdcP_radpm) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcP_radpm

#ifndef P_TCTLGC_LdcSfP_radpm
#define P_TCTLGC_LdcSfP_radpm (LCF_CommonParamData.P_TCTLGC_LdcSfP_radpm) //!< LCF parameter macro.
#define GET_P_TCTLGC_LdcSfP_radpm() (P_TCTLGC_LdcSfP_radpm) //!< LCF parameter macro getter.
#endif // P_TCTLGC_LdcSfP_radpm

#ifndef P_TCTLGC_MaxDeltaFGrd_dps
#define P_TCTLGC_MaxDeltaFGrd_dps (LCF_CommonParamData.P_TCTLGC_MaxDeltaFGrd_dps) //!< LCF parameter macro.
#define GET_P_TCTLGC_MaxDeltaFGrd_dps() (P_TCTLGC_MaxDeltaFGrd_dps) //!< LCF parameter macro getter.
#endif // P_TCTLGC_MaxDeltaFGrd_dps

#ifndef P_TCTLGC_MaxDeltaF_deg
#define P_TCTLGC_MaxDeltaF_deg (LCF_CommonParamData.P_TCTLGC_MaxDeltaF_deg) //!< LCF parameter macro.
#define GET_P_TCTLGC_MaxDeltaF_deg() (P_TCTLGC_MaxDeltaF_deg) //!< LCF parameter macro getter.
#endif // P_TCTLGC_MaxDeltaF_deg

#ifndef P_TCTLGC_PGainGrdLimit_1ps
#define P_TCTLGC_PGainGrdLimit_1ps (LCF_CommonParamData.P_TCTLGC_PGainGrdLimit_1ps) //!< LCF parameter macro.
#define GET_P_TCTLGC_PGainGrdLimit_1ps() (P_TCTLGC_PGainGrdLimit_1ps) //!< LCF parameter macro getter.
#endif // P_TCTLGC_PGainGrdLimit_1ps

#ifndef P_TCTLGC_PT1CoAnErrEnable_nu
#define P_TCTLGC_PT1CoAnErrEnable_nu (LCF_CommonParamData.P_TCTLGC_PT1CoAnErrEnable_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_PT1CoAnErrEnable_nu() (P_TCTLGC_PT1CoAnErrEnable_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_PT1CoAnErrEnable_nu

#ifndef P_TCTLGC_PT1DeltaFCmdEnable_nu
#define P_TCTLGC_PT1DeltaFCmdEnable_nu (LCF_CommonParamData.P_TCTLGC_PT1DeltaFCmdEnable_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_PT1DeltaFCmdEnable_nu() (P_TCTLGC_PT1DeltaFCmdEnable_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_PT1DeltaFCmdEnable_nu

#ifndef P_TCTLGC_PT1YErrEnable_nu
#define P_TCTLGC_PT1YErrEnable_nu (LCF_CommonParamData.P_TCTLGC_PT1YErrEnable_nu) //!< LCF parameter macro.
#define GET_P_TCTLGC_PT1YErrEnable_nu() (P_TCTLGC_PT1YErrEnable_nu) //!< LCF parameter macro getter.
#endif // P_TCTLGC_PT1YErrEnable_nu

#ifndef P_TCTLGC_StandstillThreshVel_mps
#define P_TCTLGC_StandstillThreshVel_mps (LCF_CommonParamData.P_TCTLGC_StandstillThreshVel_mps) //!< LCF parameter macro.
#define GET_P_TCTLGC_StandstillThreshVel_mps() (P_TCTLGC_StandstillThreshVel_mps) //!< LCF parameter macro getter.
#endif // P_TCTLGC_StandstillThreshVel_mps

#ifndef P_TJACMB_AccObjPosXStdDev_met
#define P_TJACMB_AccObjPosXStdDev_met (LCF_CommonParamData.P_TJACMB_AccObjPosXStdDev_met) //!< LCF parameter macro.
#define GET_P_TJACMB_AccObjPosXStdDev_met() (P_TJACMB_AccObjPosXStdDev_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_AccObjPosXStdDev_met

#ifndef P_TJACMB_AccObjPosYStdDev_met
#define P_TJACMB_AccObjPosYStdDev_met (LCF_CommonParamData.P_TJACMB_AccObjPosYStdDev_met) //!< LCF parameter macro.
#define GET_P_TJACMB_AccObjPosYStdDev_met() (P_TJACMB_AccObjPosYStdDev_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_AccObjPosYStdDev_met

#ifndef P_TJACMB_AccObjTransitionTime_sec
#define P_TJACMB_AccObjTransitionTime_sec (LCF_CommonParamData.P_TJACMB_AccObjTransitionTime_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_AccObjTransitionTime_sec() (P_TJACMB_AccObjTransitionTime_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_AccObjTransitionTime_sec

#ifndef P_TJACMB_CMB_Enabled_bool
#define P_TJACMB_CMB_Enabled_bool (LCF_CommonParamData.P_TJACMB_CMB_Enabled_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_CMB_Enabled_bool() (P_TJACMB_CMB_Enabled_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_CMB_Enabled_bool

#ifndef P_TJACMB_CombinedCrvEnable_bool
#define P_TJACMB_CombinedCrvEnable_bool (LCF_CommonParamData.P_TJACMB_CombinedCrvEnable_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_CombinedCrvEnable_bool() (P_TJACMB_CombinedCrvEnable_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_CombinedCrvEnable_bool

#ifndef P_TJACMB_CombinedCrvObjWeight_nu
#define P_TJACMB_CombinedCrvObjWeight_nu (LCF_CommonParamData.P_TJACMB_CombinedCrvObjWeight_nu) //!< LCF parameter macro.
#define GET_P_TJACMB_CombinedCrvObjWeight_nu() (P_TJACMB_CombinedCrvObjWeight_nu) //!< LCF parameter macro getter.
#endif // P_TJACMB_CombinedCrvObjWeight_nu

#ifndef P_TJACMB_ConstSiteCheckOn_bool
#define P_TJACMB_ConstSiteCheckOn_bool (LCF_CommonParamData.P_TJACMB_ConstSiteCheckOn_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_ConstSiteCheckOn_bool() (P_TJACMB_ConstSiteCheckOn_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_ConstSiteCheckOn_bool

#ifndef P_TJACMB_CurvatureMaxOF_1pm
#define P_TJACMB_CurvatureMaxOF_1pm (LCF_CommonParamData.P_TJACMB_CurvatureMaxOF_1pm) //!< LCF parameter macro.
#define GET_P_TJACMB_CurvatureMaxOF_1pm() (P_TJACMB_CurvatureMaxOF_1pm) //!< LCF parameter macro getter.
#endif // P_TJACMB_CurvatureMaxOF_1pm

#ifndef P_TJACMB_IndVelLimitsEnable_bool
#define P_TJACMB_IndVelLimitsEnable_bool (LCF_CommonParamData.P_TJACMB_IndVelLimitsEnable_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_IndVelLimitsEnable_bool() (P_TJACMB_IndVelLimitsEnable_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_IndVelLimitsEnable_bool

#ifndef P_TJACMB_InjectLaneError_bool
#define P_TJACMB_InjectLaneError_bool (LCF_CommonParamData.P_TJACMB_InjectLaneError_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_InjectLaneError_bool() (P_TJACMB_InjectLaneError_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_InjectLaneError_bool

#ifndef P_TJACMB_KalmanMinValidTime_sec
#define P_TJACMB_KalmanMinValidTime_sec (LCF_CommonParamData.P_TJACMB_KalmanMinValidTime_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_KalmanMinValidTime_sec() (P_TJACMB_KalmanMinValidTime_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_KalmanMinValidTime_sec

#ifndef P_TJACMB_LaneCheckEnabled_bool
#define P_TJACMB_LaneCheckEnabled_bool (LCF_CommonParamData.P_TJACMB_LaneCheckEnabled_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_LaneCheckEnabled_bool() (P_TJACMB_LaneCheckEnabled_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_LaneCheckEnabled_bool

#ifndef P_TJACMB_LaneInvalidTime_sec
#define P_TJACMB_LaneInvalidTime_sec (LCF_CommonParamData.P_TJACMB_LaneInvalidTime_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_LaneInvalidTime_sec() (P_TJACMB_LaneInvalidTime_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_LaneInvalidTime_sec

#ifndef P_TJACMB_LnCurveDtctEnable_bool
#define P_TJACMB_LnCurveDtctEnable_bool (LCF_CommonParamData.P_TJACMB_LnCurveDtctEnable_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_LnCurveDtctEnable_bool() (P_TJACMB_LnCurveDtctEnable_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnCurveDtctEnable_bool

#ifndef P_TJACMB_LnCurveMaxPercHyst_perc
#define P_TJACMB_LnCurveMaxPercHyst_perc (LCF_CommonParamData.P_TJACMB_LnCurveMaxPercHyst_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnCurveMaxPercHyst_perc() (P_TJACMB_LnCurveMaxPercHyst_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnCurveMaxPercHyst_perc

#ifndef P_TJACMB_LnCurveMaxPerc_perc
#define P_TJACMB_LnCurveMaxPerc_perc (LCF_CommonParamData.P_TJACMB_LnCurveMaxPerc_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnCurveMaxPerc_perc() (P_TJACMB_LnCurveMaxPerc_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnCurveMaxPerc_perc

#ifndef P_TJACMB_LnQualGradMaxExit_perc
#define P_TJACMB_LnQualGradMaxExit_perc (LCF_CommonParamData.P_TJACMB_LnQualGradMaxExit_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualGradMaxExit_perc() (P_TJACMB_LnQualGradMaxExit_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualGradMaxExit_perc

#ifndef P_TJACMB_LnQualMinContrast_perc
#define P_TJACMB_LnQualMinContrast_perc (LCF_CommonParamData.P_TJACMB_LnQualMinContrast_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinContrast_perc() (P_TJACMB_LnQualMinContrast_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinContrast_perc

#ifndef P_TJACMB_LnQualMinCurve_perc
#define P_TJACMB_LnQualMinCurve_perc (LCF_CommonParamData.P_TJACMB_LnQualMinCurve_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinCurve_perc() (P_TJACMB_LnQualMinCurve_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinCurve_perc

#ifndef P_TJACMB_LnQualMinExit_perc
#define P_TJACMB_LnQualMinExit_perc (LCF_CommonParamData.P_TJACMB_LnQualMinExit_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinExit_perc() (P_TJACMB_LnQualMinExit_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinExit_perc

#ifndef P_TJACMB_LnQualMinHystWR_perc
#define P_TJACMB_LnQualMinHystWR_perc (LCF_CommonParamData.P_TJACMB_LnQualMinHystWR_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinHystWR_perc() (P_TJACMB_LnQualMinHystWR_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinHystWR_perc

#ifndef P_TJACMB_LnQualMinOnTmCurve_sec
#define P_TJACMB_LnQualMinOnTmCurve_sec (LCF_CommonParamData.P_TJACMB_LnQualMinOnTmCurve_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinOnTmCurve_sec() (P_TJACMB_LnQualMinOnTmCurve_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinOnTmCurve_sec

#ifndef P_TJACMB_LnQualMinOnTmWR_sec
#define P_TJACMB_LnQualMinOnTmWR_sec (LCF_CommonParamData.P_TJACMB_LnQualMinOnTmWR_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinOnTmWR_sec() (P_TJACMB_LnQualMinOnTmWR_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinOnTmWR_sec

#ifndef P_TJACMB_LnQualMinWR_perc
#define P_TJACMB_LnQualMinWR_perc (LCF_CommonParamData.P_TJACMB_LnQualMinWR_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualMinWR_perc() (P_TJACMB_LnQualMinWR_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualMinWR_perc

#ifndef P_TJACMB_LnQualShutOffQulOn_bool
#define P_TJACMB_LnQualShutOffQulOn_bool (LCF_CommonParamData.P_TJACMB_LnQualShutOffQulOn_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_LnQualShutOffQulOn_bool() (P_TJACMB_LnQualShutOffQulOn_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_LnQualShutOffQulOn_bool

#ifndef P_TJACMB_MaxTimeObjCntrl_sec
#define P_TJACMB_MaxTimeObjCntrl_sec (LCF_CommonParamData.P_TJACMB_MaxTimeObjCntrl_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_MaxTimeObjCntrl_sec() (P_TJACMB_MaxTimeObjCntrl_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_MaxTimeObjCntrl_sec

#ifndef P_TJACMB_MaxTimeObjCtrlOn_bool
#define P_TJACMB_MaxTimeObjCtrlOn_bool (LCF_CommonParamData.P_TJACMB_MaxTimeObjCtrlOn_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_MaxTimeObjCtrlOn_bool() (P_TJACMB_MaxTimeObjCtrlOn_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_MaxTimeObjCtrlOn_bool

#ifndef P_TJACMB_MinDurObjLnValidWR_sec
#define P_TJACMB_MinDurObjLnValidWR_sec (LCF_CommonParamData.P_TJACMB_MinDurObjLnValidWR_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_MinDurObjLnValidWR_sec() (P_TJACMB_MinDurObjLnValidWR_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_MinDurObjLnValidWR_sec

#ifndef P_TJACMB_MinLnLengthHystLC_met
#define P_TJACMB_MinLnLengthHystLC_met (LCF_CommonParamData.P_TJACMB_MinLnLengthHystLC_met) //!< LCF parameter macro.
#define GET_P_TJACMB_MinLnLengthHystLC_met() (P_TJACMB_MinLnLengthHystLC_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_MinLnLengthHystLC_met

#ifndef P_TJACMB_MinLnLengthLC_met
#define P_TJACMB_MinLnLengthLC_met (LCF_CommonParamData.P_TJACMB_MinLnLengthLC_met) //!< LCF parameter macro.
#define GET_P_TJACMB_MinLnLengthLC_met() (P_TJACMB_MinLnLengthLC_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_MinLnLengthLC_met

#ifndef P_TJACMB_MinObjStraightProb_perc
#define P_TJACMB_MinObjStraightProb_perc (LCF_CommonParamData.P_TJACMB_MinObjStraightProb_perc) //!< LCF parameter macro.
#define GET_P_TJACMB_MinObjStraightProb_perc() (P_TJACMB_MinObjStraightProb_perc) //!< LCF parameter macro getter.
#endif // P_TJACMB_MinObjStraightProb_perc

#ifndef P_TJACMB_MinObjStraightProb_sec
#define P_TJACMB_MinObjStraightProb_sec (LCF_CommonParamData.P_TJACMB_MinObjStraightProb_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_MinObjStraightProb_sec() (P_TJACMB_MinObjStraightProb_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_MinObjStraightProb_sec

#ifndef P_TJACMB_OF_Debug_bool
#define P_TJACMB_OF_Debug_bool (LCF_CommonParamData.P_TJACMB_OF_Debug_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_OF_Debug_bool() (P_TJACMB_OF_Debug_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_OF_Debug_bool

#ifndef P_TJACMB_OF_Enabled_bool
#define P_TJACMB_OF_Enabled_bool (LCF_CommonParamData.P_TJACMB_OF_Enabled_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_OF_Enabled_bool() (P_TJACMB_OF_Enabled_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_OF_Enabled_bool

#ifndef P_TJACMB_ObjHystPosXOF_met
#define P_TJACMB_ObjHystPosXOF_met (LCF_CommonParamData.P_TJACMB_ObjHystPosXOF_met) //!< LCF parameter macro.
#define GET_P_TJACMB_ObjHystPosXOF_met() (P_TJACMB_ObjHystPosXOF_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_ObjHystPosXOF_met

#ifndef P_TJACMB_ObjMaxPosXOF_met
#define P_TJACMB_ObjMaxPosXOF_met (LCF_CommonParamData.P_TJACMB_ObjMaxPosXOF_met) //!< LCF parameter macro.
#define GET_P_TJACMB_ObjMaxPosXOF_met() (P_TJACMB_ObjMaxPosXOF_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_ObjMaxPosXOF_met

#ifndef P_TJACMB_ObjMinPosXOF_met
#define P_TJACMB_ObjMinPosXOF_met (LCF_CommonParamData.P_TJACMB_ObjMinPosXOF_met) //!< LCF parameter macro.
#define GET_P_TJACMB_ObjMinPosXOF_met() (P_TJACMB_ObjMinPosXOF_met) //!< LCF parameter macro getter.
#endif // P_TJACMB_ObjMinPosXOF_met

#ifndef P_TJACMB_PassivModeMinTime_sec
#define P_TJACMB_PassivModeMinTime_sec (LCF_CommonParamData.P_TJACMB_PassivModeMinTime_sec) //!< LCF parameter macro.
#define GET_P_TJACMB_PassivModeMinTime_sec() (P_TJACMB_PassivModeMinTime_sec) //!< LCF parameter macro getter.
#endif // P_TJACMB_PassivModeMinTime_sec

#ifndef P_TJACMB_SetLaneCondInvalid_bool
#define P_TJACMB_SetLaneCondInvalid_bool (LCF_CommonParamData.P_TJACMB_SetLaneCondInvalid_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_SetLaneCondInvalid_bool() (P_TJACMB_SetLaneCondInvalid_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_SetLaneCondInvalid_bool

#ifndef P_TJACMB_TransitionHandleOn_bool
#define P_TJACMB_TransitionHandleOn_bool (LCF_CommonParamData.P_TJACMB_TransitionHandleOn_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_TransitionHandleOn_bool() (P_TJACMB_TransitionHandleOn_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_TransitionHandleOn_bool

#ifndef P_TJACMB_UseInterCmbCrvCalc_bool
#define P_TJACMB_UseInterCmbCrvCalc_bool (LCF_CommonParamData.P_TJACMB_UseInterCmbCrvCalc_bool) //!< LCF parameter macro.
#define GET_P_TJACMB_UseInterCmbCrvCalc_bool() (P_TJACMB_UseInterCmbCrvCalc_bool) //!< LCF parameter macro getter.
#endif // P_TJACMB_UseInterCmbCrvCalc_bool

#ifndef P_TJACMB_VelXMaxOF_kph
#define P_TJACMB_VelXMaxOF_kph (LCF_CommonParamData.P_TJACMB_VelXMaxOF_kph) //!< LCF parameter macro.
#define GET_P_TJACMB_VelXMaxOF_kph() (P_TJACMB_VelXMaxOF_kph) //!< LCF parameter macro getter.
#endif // P_TJACMB_VelXMaxOF_kph

#ifndef P_TJACMB_VelXMax_kph
#define P_TJACMB_VelXMax_kph (LCF_CommonParamData.P_TJACMB_VelXMax_kph) //!< LCF parameter macro.
#define GET_P_TJACMB_VelXMax_kph() (P_TJACMB_VelXMax_kph) //!< LCF parameter macro getter.
#endif // P_TJACMB_VelXMax_kph

#ifndef P_TJACMB_VelXMin_kph
#define P_TJACMB_VelXMin_kph (LCF_CommonParamData.P_TJACMB_VelXMin_kph) //!< LCF parameter macro.
#define GET_P_TJACMB_VelXMin_kph() (P_TJACMB_VelXMin_kph) //!< LCF parameter macro getter.
#endif // P_TJACMB_VelXMin_kph

#ifndef P_TJAGEN_AccelXHyst_mps2
#define P_TJAGEN_AccelXHyst_mps2 (LCF_CommonParamData.P_TJAGEN_AccelXHyst_mps2) //!< LCF parameter macro.
#define GET_P_TJAGEN_AccelXHyst_mps2() (P_TJAGEN_AccelXHyst_mps2) //!< LCF parameter macro getter.
#endif // P_TJAGEN_AccelXHyst_mps2

#ifndef P_TJAGEN_AccelYHyst_mps2
#define P_TJAGEN_AccelYHyst_mps2 (LCF_CommonParamData.P_TJAGEN_AccelYHyst_mps2) //!< LCF parameter macro.
#define GET_P_TJAGEN_AccelYHyst_mps2() (P_TJAGEN_AccelYHyst_mps2) //!< LCF parameter macro getter.
#endif // P_TJAGEN_AccelYHyst_mps2

#ifndef P_TJAGEN_AclXMax_mps2
#define P_TJAGEN_AclXMax_mps2 (LCF_CommonParamData.P_TJAGEN_AclXMax_mps2) //!< LCF parameter macro.
#define GET_P_TJAGEN_AclXMax_mps2() (P_TJAGEN_AclXMax_mps2) //!< LCF parameter macro getter.
#endif // P_TJAGEN_AclXMax_mps2

#ifndef P_TJAGEN_AclXMin_mps2
#define P_TJAGEN_AclXMin_mps2 (LCF_CommonParamData.P_TJAGEN_AclXMin_mps2) //!< LCF parameter macro.
#define GET_P_TJAGEN_AclXMin_mps2() (P_TJAGEN_AclXMin_mps2) //!< LCF parameter macro getter.
#endif // P_TJAGEN_AclXMin_mps2

#ifndef P_TJAGEN_AclYMax_mps2
#define P_TJAGEN_AclYMax_mps2 (LCF_CommonParamData.P_TJAGEN_AclYMax_mps2) //!< LCF parameter macro.
#define GET_P_TJAGEN_AclYMax_mps2() (P_TJAGEN_AclYMax_mps2) //!< LCF parameter macro getter.
#endif // P_TJAGEN_AclYMax_mps2

#ifndef P_TJAGEN_ActiveStCtrlSR_btm
#define P_TJAGEN_ActiveStCtrlSR_btm (LCF_CommonParamData.P_TJAGEN_ActiveStCtrlSR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_ActiveStCtrlSR_btm() (P_TJAGEN_ActiveStCtrlSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_ActiveStCtrlSR_btm

#ifndef P_TJAGEN_BlockTimeTJA_sec
#define P_TJAGEN_BlockTimeTJA_sec (LCF_CommonParamData.P_TJAGEN_BlockTimeTJA_sec) //!< LCF parameter macro.
#define GET_P_TJAGEN_BlockTimeTJA_sec() (P_TJAGEN_BlockTimeTJA_sec) //!< LCF parameter macro getter.
#endif // P_TJAGEN_BlockTimeTJA_sec

#ifndef P_TJAGEN_CheckTJAErrorState_bool
#define P_TJAGEN_CheckTJAErrorState_bool (LCF_CommonParamData.P_TJAGEN_CheckTJAErrorState_bool) //!< LCF parameter macro.
#define GET_P_TJAGEN_CheckTJAErrorState_bool() (P_TJAGEN_CheckTJAErrorState_bool) //!< LCF parameter macro getter.
#endif // P_TJAGEN_CheckTJAErrorState_bool

#ifndef P_TJAGEN_DrvStInvalidC_btm
#define P_TJAGEN_DrvStInvalidC_btm (LCF_CommonParamData.P_TJAGEN_DrvStInvalidC_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_DrvStInvalidC_btm() (P_TJAGEN_DrvStInvalidC_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_DrvStInvalidC_btm

#ifndef P_TJAGEN_DrvStInvalidSR_btm
#define P_TJAGEN_DrvStInvalidSR_btm (LCF_CommonParamData.P_TJAGEN_DrvStInvalidSR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_DrvStInvalidSR_btm() (P_TJAGEN_DrvStInvalidSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_DrvStInvalidSR_btm

#ifndef P_TJAGEN_DrvStInvalidWR_btm
#define P_TJAGEN_DrvStInvalidWR_btm (LCF_CommonParamData.P_TJAGEN_DrvStInvalidWR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_DrvStInvalidWR_btm() (P_TJAGEN_DrvStInvalidWR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_DrvStInvalidWR_btm

#ifndef P_TJAGEN_PrjSpecQuA_btm
#define P_TJAGEN_PrjSpecQuA_btm (LCF_CommonParamData.P_TJAGEN_PrjSpecQuA_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_PrjSpecQuA_btm() (P_TJAGEN_PrjSpecQuA_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_PrjSpecQuA_btm

#ifndef P_TJAGEN_PrjSpecQuC_btm
#define P_TJAGEN_PrjSpecQuC_btm (LCF_CommonParamData.P_TJAGEN_PrjSpecQuC_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_PrjSpecQuC_btm() (P_TJAGEN_PrjSpecQuC_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_PrjSpecQuC_btm

#ifndef P_TJAGEN_PrjSpecQuSR_btm
#define P_TJAGEN_PrjSpecQuSR_btm (LCF_CommonParamData.P_TJAGEN_PrjSpecQuSR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_PrjSpecQuSR_btm() (P_TJAGEN_PrjSpecQuSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_PrjSpecQuSR_btm

#ifndef P_TJAGEN_PrjSpecQuWR_btm
#define P_TJAGEN_PrjSpecQuWR_btm (LCF_CommonParamData.P_TJAGEN_PrjSpecQuWR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_PrjSpecQuWR_btm() (P_TJAGEN_PrjSpecQuWR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_PrjSpecQuWR_btm

#ifndef P_TJAGEN_QuTrajCtrCancel_btm
#define P_TJAGEN_QuTrajCtrCancel_btm (LCF_CommonParamData.P_TJAGEN_QuTrajCtrCancel_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_QuTrajCtrCancel_btm() (P_TJAGEN_QuTrajCtrCancel_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_QuTrajCtrCancel_btm

#ifndef P_TJAGEN_QuTrajCtrClearance_btm
#define P_TJAGEN_QuTrajCtrClearance_btm (LCF_CommonParamData.P_TJAGEN_QuTrajCtrClearance_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_QuTrajCtrClearance_btm() (P_TJAGEN_QuTrajCtrClearance_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_QuTrajCtrClearance_btm

#ifndef P_TJAGEN_QuTrajPlanCancel_btm
#define P_TJAGEN_QuTrajPlanCancel_btm (LCF_CommonParamData.P_TJAGEN_QuTrajPlanCancel_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_QuTrajPlanCancel_btm() (P_TJAGEN_QuTrajPlanCancel_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_QuTrajPlanCancel_btm

#ifndef P_TJAGEN_QuTrajPlanClearance_btm
#define P_TJAGEN_QuTrajPlanClearance_btm (LCF_CommonParamData.P_TJAGEN_QuTrajPlanClearance_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_QuTrajPlanClearance_btm() (P_TJAGEN_QuTrajPlanClearance_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_QuTrajPlanClearance_btm

#ifndef P_TJAGEN_QuTrajPlanMinLnQual_perc
#define P_TJAGEN_QuTrajPlanMinLnQual_perc (LCF_CommonParamData.P_TJAGEN_QuTrajPlanMinLnQual_perc) //!< LCF parameter macro.
#define GET_P_TJAGEN_QuTrajPlanMinLnQual_perc() (P_TJAGEN_QuTrajPlanMinLnQual_perc) //!< LCF parameter macro getter.
#endif // P_TJAGEN_QuTrajPlanMinLnQual_perc

#ifndef P_TJAGEN_RampoutTimeMax_sec
#define P_TJAGEN_RampoutTimeMax_sec (LCF_CommonParamData.P_TJAGEN_RampoutTimeMax_sec) //!< LCF parameter macro.
#define GET_P_TJAGEN_RampoutTimeMax_sec() (P_TJAGEN_RampoutTimeMax_sec) //!< LCF parameter macro getter.
#endif // P_TJAGEN_RampoutTimeMax_sec

#ifndef P_TJAGEN_SetSysStOnLatDMC_bool
#define P_TJAGEN_SetSysStOnLatDMC_bool (LCF_CommonParamData.P_TJAGEN_SetSysStOnLatDMC_bool) //!< LCF parameter macro.
#define GET_P_TJAGEN_SetSysStOnLatDMC_bool() (P_TJAGEN_SetSysStOnLatDMC_bool) //!< LCF parameter macro getter.
#endif // P_TJAGEN_SetSysStOnLatDMC_bool

#ifndef P_TJAGEN_SteerWAngleMaxWR_deg
#define P_TJAGEN_SteerWAngleMaxWR_deg (LCF_CommonParamData.P_TJAGEN_SteerWAngleMaxWR_deg) //!< LCF parameter macro.
#define GET_P_TJAGEN_SteerWAngleMaxWR_deg() (P_TJAGEN_SteerWAngleMaxWR_deg) //!< LCF parameter macro getter.
#endif // P_TJAGEN_SteerWAngleMaxWR_deg

#ifndef P_TJAGEN_SysStErrorSR_btm
#define P_TJAGEN_SysStErrorSR_btm (LCF_CommonParamData.P_TJAGEN_SysStErrorSR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_SysStErrorSR_btm() (P_TJAGEN_SysStErrorSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_SysStErrorSR_btm

#ifndef P_TJAGEN_SysStNotAvailableWR_btm
#define P_TJAGEN_SysStNotAvailableWR_btm (LCF_CommonParamData.P_TJAGEN_SysStNotAvailableWR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_SysStNotAvailableWR_btm() (P_TJAGEN_SysStNotAvailableWR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_SysStNotAvailableWR_btm

#ifndef P_TJAGEN_VehStInvalidC_btm
#define P_TJAGEN_VehStInvalidC_btm (LCF_CommonParamData.P_TJAGEN_VehStInvalidC_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_VehStInvalidC_btm() (P_TJAGEN_VehStInvalidC_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_VehStInvalidC_btm

#ifndef P_TJAGEN_VehStInvalidSR_btm
#define P_TJAGEN_VehStInvalidSR_btm (LCF_CommonParamData.P_TJAGEN_VehStInvalidSR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_VehStInvalidSR_btm() (P_TJAGEN_VehStInvalidSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_VehStInvalidSR_btm

#ifndef P_TJAGEN_VehStInvalidWR_btm
#define P_TJAGEN_VehStInvalidWR_btm (LCF_CommonParamData.P_TJAGEN_VehStInvalidWR_btm) //!< LCF parameter macro.
#define GET_P_TJAGEN_VehStInvalidWR_btm() (P_TJAGEN_VehStInvalidWR_btm) //!< LCF parameter macro getter.
#endif // P_TJAGEN_VehStInvalidWR_btm

#ifndef P_TJALKA_BlockTimeTJA_sec
#define P_TJALKA_BlockTimeTJA_sec (LCF_CommonParamData.P_TJALKA_BlockTimeTJA_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_BlockTimeTJA_sec() (P_TJALKA_BlockTimeTJA_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_BlockTimeTJA_sec

#ifndef P_TJALKA_BothSideBrdgEnable_bool
#define P_TJALKA_BothSideBrdgEnable_bool (LCF_CommonParamData.P_TJALKA_BothSideBrdgEnable_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_BothSideBrdgEnable_bool() (P_TJALKA_BothSideBrdgEnable_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_BothSideBrdgEnable_bool

#ifndef P_TJALKA_ConstSiteCheckOn_bool
#define P_TJALKA_ConstSiteCheckOn_bool (LCF_CommonParamData.P_TJALKA_ConstSiteCheckOn_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_ConstSiteCheckOn_bool() (P_TJALKA_ConstSiteCheckOn_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_ConstSiteCheckOn_bool

#ifndef P_TJALKA_DistVeh2LnBndHyst_met
#define P_TJALKA_DistVeh2LnBndHyst_met (LCF_CommonParamData.P_TJALKA_DistVeh2LnBndHyst_met) //!< LCF parameter macro.
#define GET_P_TJALKA_DistVeh2LnBndHyst_met() (P_TJALKA_DistVeh2LnBndHyst_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_DistVeh2LnBndHyst_met

#ifndef P_TJALKA_DistVeh2LnBndMin_met
#define P_TJALKA_DistVeh2LnBndMin_met (LCF_CommonParamData.P_TJALKA_DistVeh2LnBndMin_met) //!< LCF parameter macro.
#define GET_P_TJALKA_DistVeh2LnBndMin_met() (P_TJALKA_DistVeh2LnBndMin_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_DistVeh2LnBndMin_met

#ifndef P_TJALKA_DrvStInvalidSR_btm
#define P_TJALKA_DrvStInvalidSR_btm (LCF_CommonParamData.P_TJALKA_DrvStInvalidSR_btm) //!< LCF parameter macro.
#define GET_P_TJALKA_DrvStInvalidSR_btm() (P_TJALKA_DrvStInvalidSR_btm) //!< LCF parameter macro getter.
#endif // P_TJALKA_DrvStInvalidSR_btm

#ifndef P_TJALKA_InjectLaneError_bool
#define P_TJALKA_InjectLaneError_bool (LCF_CommonParamData.P_TJALKA_InjectLaneError_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_InjectLaneError_bool() (P_TJALKA_InjectLaneError_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_InjectLaneError_bool

#ifndef P_TJALKA_LC_Enabled_bool
#define P_TJALKA_LC_Enabled_bool (LCF_CommonParamData.P_TJALKA_LC_Enabled_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_LC_Enabled_bool() (P_TJALKA_LC_Enabled_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_LC_Enabled_bool

#ifndef P_TJALKA_LaneInvalidTime_sec
#define P_TJALKA_LaneInvalidTime_sec (LCF_CommonParamData.P_TJALKA_LaneInvalidTime_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneInvalidTime_sec() (P_TJALKA_LaneInvalidTime_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneInvalidTime_sec

#ifndef P_TJALKA_LaneQualityHyst_perc
#define P_TJALKA_LaneQualityHyst_perc (LCF_CommonParamData.P_TJALKA_LaneQualityHyst_perc) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneQualityHyst_perc() (P_TJALKA_LaneQualityHyst_perc) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneQualityHyst_perc

#ifndef P_TJALKA_LaneQualityMin_perc
#define P_TJALKA_LaneQualityMin_perc (LCF_CommonParamData.P_TJALKA_LaneQualityMin_perc) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneQualityMin_perc() (P_TJALKA_LaneQualityMin_perc) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneQualityMin_perc

#ifndef P_TJALKA_LaneValid_btm
#define P_TJALKA_LaneValid_btm (LCF_CommonParamData.P_TJALKA_LaneValid_btm) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneValid_btm() (P_TJALKA_LaneValid_btm) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneValid_btm

#ifndef P_TJALKA_LaneVirtOrBridged_btm
#define P_TJALKA_LaneVirtOrBridged_btm (LCF_CommonParamData.P_TJALKA_LaneVirtOrBridged_btm) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneVirtOrBridged_btm() (P_TJALKA_LaneVirtOrBridged_btm) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneVirtOrBridged_btm

#ifndef P_TJALKA_LaneWidthHyst_met
#define P_TJALKA_LaneWidthHyst_met (LCF_CommonParamData.P_TJALKA_LaneWidthHyst_met) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneWidthHyst_met() (P_TJALKA_LaneWidthHyst_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneWidthHyst_met

#ifndef P_TJALKA_LaneWidthMax_met
#define P_TJALKA_LaneWidthMax_met (LCF_CommonParamData.P_TJALKA_LaneWidthMax_met) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneWidthMax_met() (P_TJALKA_LaneWidthMax_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneWidthMax_met

#ifndef P_TJALKA_LaneWidthMin_met
#define P_TJALKA_LaneWidthMin_met (LCF_CommonParamData.P_TJALKA_LaneWidthMin_met) //!< LCF parameter macro.
#define GET_P_TJALKA_LaneWidthMin_met() (P_TJALKA_LaneWidthMin_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_LaneWidthMin_met

#ifndef P_TJALKA_LnPredMinValidTime_sec
#define P_TJALKA_LnPredMinValidTime_sec (LCF_CommonParamData.P_TJALKA_LnPredMinValidTime_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_LnPredMinValidTime_sec() (P_TJALKA_LnPredMinValidTime_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_LnPredMinValidTime_sec

#ifndef P_TJALKA_LnPredictionCrvMax_1pm
#define P_TJALKA_LnPredictionCrvMax_1pm (LCF_CommonParamData.P_TJALKA_LnPredictionCrvMax_1pm) //!< LCF parameter macro.
#define GET_P_TJALKA_LnPredictionCrvMax_1pm() (P_TJALKA_LnPredictionCrvMax_1pm) //!< LCF parameter macro getter.
#endif // P_TJALKA_LnPredictionCrvMax_1pm

#ifndef P_TJALKA_LnPredictionTimeMax_sec
#define P_TJALKA_LnPredictionTimeMax_sec (LCF_CommonParamData.P_TJALKA_LnPredictionTimeMax_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_LnPredictionTimeMax_sec() (P_TJALKA_LnPredictionTimeMax_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_LnPredictionTimeMax_sec

#ifndef P_TJALKA_LnPredictionTimeMin_sec
#define P_TJALKA_LnPredictionTimeMin_sec (LCF_CommonParamData.P_TJALKA_LnPredictionTimeMin_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_LnPredictionTimeMin_sec() (P_TJALKA_LnPredictionTimeMin_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_LnPredictionTimeMin_sec

#ifndef P_TJALKA_LnQualTurnOffTime_sec
#define P_TJALKA_LnQualTurnOffTime_sec (LCF_CommonParamData.P_TJALKA_LnQualTurnOffTime_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_LnQualTurnOffTime_sec() (P_TJALKA_LnQualTurnOffTime_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_LnQualTurnOffTime_sec

#ifndef P_TJALKA_LnQualTurnOnTime_sec
#define P_TJALKA_LnQualTurnOnTime_sec (LCF_CommonParamData.P_TJALKA_LnQualTurnOnTime_sec) //!< LCF parameter macro.
#define GET_P_TJALKA_LnQualTurnOnTime_sec() (P_TJALKA_LnQualTurnOnTime_sec) //!< LCF parameter macro getter.
#endif // P_TJALKA_LnQualTurnOnTime_sec

#ifndef P_TJALKA_MaxHeadAngActnTJA_rad
#define P_TJALKA_MaxHeadAngActnTJA_rad (LCF_CommonParamData.P_TJALKA_MaxHeadAngActnTJA_rad) //!< LCF parameter macro.
#define GET_P_TJALKA_MaxHeadAngActnTJA_rad() (P_TJALKA_MaxHeadAngActnTJA_rad) //!< LCF parameter macro getter.
#endif // P_TJALKA_MaxHeadAngActnTJA_rad

#ifndef P_TJALKA_MaxLnWdthUseCoup_bool
#define P_TJALKA_MaxLnWdthUseCoup_bool (LCF_CommonParamData.P_TJALKA_MaxLnWdthUseCoup_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_MaxLnWdthUseCoup_bool() (P_TJALKA_MaxLnWdthUseCoup_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_MaxLnWdthUseCoup_bool

#ifndef P_TJALKA_MinLnWdthUseUncoup_bool
#define P_TJALKA_MinLnWdthUseUncoup_bool (LCF_CommonParamData.P_TJALKA_MinLnWdthUseUncoup_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_MinLnWdthUseUncoup_bool() (P_TJALKA_MinLnWdthUseUncoup_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_MinLnWdthUseUncoup_bool

#ifndef P_TJALKA_PrjSpecQuC_btm
#define P_TJALKA_PrjSpecQuC_btm (LCF_CommonParamData.P_TJALKA_PrjSpecQuC_btm) //!< LCF parameter macro.
#define GET_P_TJALKA_PrjSpecQuC_btm() (P_TJALKA_PrjSpecQuC_btm) //!< LCF parameter macro getter.
#endif // P_TJALKA_PrjSpecQuC_btm

#ifndef P_TJALKA_PrjSpecQuSR_btm
#define P_TJALKA_PrjSpecQuSR_btm (LCF_CommonParamData.P_TJALKA_PrjSpecQuSR_btm) //!< LCF parameter macro.
#define GET_P_TJALKA_PrjSpecQuSR_btm() (P_TJALKA_PrjSpecQuSR_btm) //!< LCF parameter macro getter.
#endif // P_TJALKA_PrjSpecQuSR_btm

#ifndef P_TJALKA_PrjSpecQuWR_btm
#define P_TJALKA_PrjSpecQuWR_btm (LCF_CommonParamData.P_TJALKA_PrjSpecQuWR_btm) //!< LCF parameter macro.
#define GET_P_TJALKA_PrjSpecQuWR_btm() (P_TJALKA_PrjSpecQuWR_btm) //!< LCF parameter macro getter.
#endif // P_TJALKA_PrjSpecQuWR_btm

#ifndef P_TJALKA_RadiusHyst_met
#define P_TJALKA_RadiusHyst_met (LCF_CommonParamData.P_TJALKA_RadiusHyst_met) //!< LCF parameter macro.
#define GET_P_TJALKA_RadiusHyst_met() (P_TJALKA_RadiusHyst_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_RadiusHyst_met

#ifndef P_TJALKA_RadiusMin_met
#define P_TJALKA_RadiusMin_met (LCF_CommonParamData.P_TJALKA_RadiusMin_met) //!< LCF parameter macro.
#define GET_P_TJALKA_RadiusMin_met() (P_TJALKA_RadiusMin_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_RadiusMin_met

#ifndef P_TJALKA_RampoutPredictOn_bool
#define P_TJALKA_RampoutPredictOn_bool (LCF_CommonParamData.P_TJALKA_RampoutPredictOn_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_RampoutPredictOn_bool() (P_TJALKA_RampoutPredictOn_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_RampoutPredictOn_bool

#ifndef P_TJALKA_TransLnChecksOff_bool
#define P_TJALKA_TransLnChecksOff_bool (LCF_CommonParamData.P_TJALKA_TransLnChecksOff_bool) //!< LCF parameter macro.
#define GET_P_TJALKA_TransLnChecksOff_bool() (P_TJALKA_TransLnChecksOff_bool) //!< LCF parameter macro getter.
#endif // P_TJALKA_TransLnChecksOff_bool

#ifndef P_TJALKA_ValidLengthMinHyst_met
#define P_TJALKA_ValidLengthMinHyst_met (LCF_CommonParamData.P_TJALKA_ValidLengthMinHyst_met) //!< LCF parameter macro.
#define GET_P_TJALKA_ValidLengthMinHyst_met() (P_TJALKA_ValidLengthMinHyst_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_ValidLengthMinHyst_met

#ifndef P_TJALKA_ValidLengthMin_met
#define P_TJALKA_ValidLengthMin_met (LCF_CommonParamData.P_TJALKA_ValidLengthMin_met) //!< LCF parameter macro.
#define GET_P_TJALKA_ValidLengthMin_met() (P_TJALKA_ValidLengthMin_met) //!< LCF parameter macro getter.
#endif // P_TJALKA_ValidLengthMin_met

#ifndef P_TJALKA_VelXHyst_kph
#define P_TJALKA_VelXHyst_kph (LCF_CommonParamData.P_TJALKA_VelXHyst_kph) //!< LCF parameter macro.
#define GET_P_TJALKA_VelXHyst_kph() (P_TJALKA_VelXHyst_kph) //!< LCF parameter macro getter.
#endif // P_TJALKA_VelXHyst_kph

#ifndef P_TJALKA_VelXMax_kph
#define P_TJALKA_VelXMax_kph (LCF_CommonParamData.P_TJALKA_VelXMax_kph) //!< LCF parameter macro.
#define GET_P_TJALKA_VelXMax_kph() (P_TJALKA_VelXMax_kph) //!< LCF parameter macro getter.
#endif // P_TJALKA_VelXMax_kph

#ifndef P_TJALKA_VelXMin_kph
#define P_TJALKA_VelXMin_kph (LCF_CommonParamData.P_TJALKA_VelXMin_kph) //!< LCF parameter macro.
#define GET_P_TJALKA_VelXMin_kph() (P_TJALKA_VelXMin_kph) //!< LCF parameter macro getter.
#endif // P_TJALKA_VelXMin_kph

#ifndef P_TJAOBF_AccObjChange_btm
#define P_TJAOBF_AccObjChange_btm (LCF_CommonParamData.P_TJAOBF_AccObjChange_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_AccObjChange_btm() (P_TJAOBF_AccObjChange_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_AccObjChange_btm

#ifndef P_TJAOBF_AccObjLanesInvalid_btm
#define P_TJAOBF_AccObjLanesInvalid_btm (LCF_CommonParamData.P_TJAOBF_AccObjLanesInvalid_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_AccObjLanesInvalid_btm() (P_TJAOBF_AccObjLanesInvalid_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_AccObjLanesInvalid_btm

#ifndef P_TJAOBF_AccObjectInvalid_btm
#define P_TJAOBF_AccObjectInvalid_btm (LCF_CommonParamData.P_TJAOBF_AccObjectInvalid_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_AccObjectInvalid_btm() (P_TJAOBF_AccObjectInvalid_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_AccObjectInvalid_btm

#ifndef P_TJAOBF_CheckAccObjValidty_bool
#define P_TJAOBF_CheckAccObjValidty_bool (LCF_CommonParamData.P_TJAOBF_CheckAccObjValidty_bool) //!< LCF parameter macro.
#define GET_P_TJAOBF_CheckAccObjValidty_bool() (P_TJAOBF_CheckAccObjValidty_bool) //!< LCF parameter macro getter.
#endif // P_TJAOBF_CheckAccObjValidty_bool

#ifndef P_TJAOBF_ConstSiteCheckOn_bool
#define P_TJAOBF_ConstSiteCheckOn_bool (LCF_CommonParamData.P_TJAOBF_ConstSiteCheckOn_bool) //!< LCF parameter macro.
#define GET_P_TJAOBF_ConstSiteCheckOn_bool() (P_TJAOBF_ConstSiteCheckOn_bool) //!< LCF parameter macro getter.
#endif // P_TJAOBF_ConstSiteCheckOn_bool

#ifndef P_TJAOBF_CutinObValidFreezTm_sec
#define P_TJAOBF_CutinObValidFreezTm_sec (LCF_CommonParamData.P_TJAOBF_CutinObValidFreezTm_sec) //!< LCF parameter macro.
#define GET_P_TJAOBF_CutinObValidFreezTm_sec() (P_TJAOBF_CutinObValidFreezTm_sec) //!< LCF parameter macro getter.
#endif // P_TJAOBF_CutinObValidFreezTm_sec

#ifndef P_TJAOBF_DefaultLaneWidth_met
#define P_TJAOBF_DefaultLaneWidth_met (LCF_CommonParamData.P_TJAOBF_DefaultLaneWidth_met) //!< LCF parameter macro.
#define GET_P_TJAOBF_DefaultLaneWidth_met() (P_TJAOBF_DefaultLaneWidth_met) //!< LCF parameter macro getter.
#endif // P_TJAOBF_DefaultLaneWidth_met

#ifndef P_TJAOBF_DrvStInvalidSR_btm
#define P_TJAOBF_DrvStInvalidSR_btm (LCF_CommonParamData.P_TJAOBF_DrvStInvalidSR_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_DrvStInvalidSR_btm() (P_TJAOBF_DrvStInvalidSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_DrvStInvalidSR_btm

#ifndef P_TJAOBF_LaneCheckEnabled_bool
#define P_TJAOBF_LaneCheckEnabled_bool (LCF_CommonParamData.P_TJAOBF_LaneCheckEnabled_bool) //!< LCF parameter macro.
#define GET_P_TJAOBF_LaneCheckEnabled_bool() (P_TJAOBF_LaneCheckEnabled_bool) //!< LCF parameter macro getter.
#endif // P_TJAOBF_LaneCheckEnabled_bool

#ifndef P_TJAOBF_MaxDiffLnLen2ObjPosX_met
#define P_TJAOBF_MaxDiffLnLen2ObjPosX_met (LCF_CommonParamData.P_TJAOBF_MaxDiffLnLen2ObjPosX_met) //!< LCF parameter macro.
#define GET_P_TJAOBF_MaxDiffLnLen2ObjPosX_met() (P_TJAOBF_MaxDiffLnLen2ObjPosX_met) //!< LCF parameter macro getter.
#endif // P_TJAOBF_MaxDiffLnLen2ObjPosX_met

#ifndef P_TJAOBF_MaxDurObjBrdg_sec
#define P_TJAOBF_MaxDurObjBrdg_sec (LCF_CommonParamData.P_TJAOBF_MaxDurObjBrdg_sec) //!< LCF parameter macro.
#define GET_P_TJAOBF_MaxDurObjBrdg_sec() (P_TJAOBF_MaxDurObjBrdg_sec) //!< LCF parameter macro getter.
#endif // P_TJAOBF_MaxDurObjBrdg_sec

#ifndef P_TJAOBF_MinDurAccObjValid_sec
#define P_TJAOBF_MinDurAccObjValid_sec (LCF_CommonParamData.P_TJAOBF_MinDurAccObjValid_sec) //!< LCF parameter macro.
#define GET_P_TJAOBF_MinDurAccObjValid_sec() (P_TJAOBF_MinDurAccObjValid_sec) //!< LCF parameter macro getter.
#endif // P_TJAOBF_MinDurAccObjValid_sec

#ifndef P_TJAOBF_MinDurLCforOB_sec
#define P_TJAOBF_MinDurLCforOB_sec (LCF_CommonParamData.P_TJAOBF_MinDurLCforOB_sec) //!< LCF parameter macro.
#define GET_P_TJAOBF_MinDurLCforOB_sec() (P_TJAOBF_MinDurLCforOB_sec) //!< LCF parameter macro getter.
#endif // P_TJAOBF_MinDurLCforOB_sec

#ifndef P_TJAOBF_MinDurObjLnValidWR_sec
#define P_TJAOBF_MinDurObjLnValidWR_sec (LCF_CommonParamData.P_TJAOBF_MinDurObjLnValidWR_sec) //!< LCF parameter macro.
#define GET_P_TJAOBF_MinDurObjLnValidWR_sec() (P_TJAOBF_MinDurObjLnValidWR_sec) //!< LCF parameter macro getter.
#endif // P_TJAOBF_MinDurObjLnValidWR_sec

#ifndef P_TJAOBF_OF_Enabled_bool
#define P_TJAOBF_OF_Enabled_bool (LCF_CommonParamData.P_TJAOBF_OF_Enabled_bool) //!< LCF parameter macro.
#define GET_P_TJAOBF_OF_Enabled_bool() (P_TJAOBF_OF_Enabled_bool) //!< LCF parameter macro getter.
#endif // P_TJAOBF_OF_Enabled_bool

#ifndef P_TJAOBF_ObjBrdgEnabled_bool
#define P_TJAOBF_ObjBrdgEnabled_bool (LCF_CommonParamData.P_TJAOBF_ObjBrdgEnabled_bool) //!< LCF parameter macro.
#define GET_P_TJAOBF_ObjBrdgEnabled_bool() (P_TJAOBF_ObjBrdgEnabled_bool) //!< LCF parameter macro getter.
#endif // P_TJAOBF_ObjBrdgEnabled_bool

#ifndef P_TJAOBF_ObjLnCheckMinVelX_kph
#define P_TJAOBF_ObjLnCheckMinVelX_kph (LCF_CommonParamData.P_TJAOBF_ObjLnCheckMinVelX_kph) //!< LCF parameter macro.
#define GET_P_TJAOBF_ObjLnCheckMinVelX_kph() (P_TJAOBF_ObjLnCheckMinVelX_kph) //!< LCF parameter macro getter.
#endif // P_TJAOBF_ObjLnCheckMinVelX_kph

#ifndef P_TJAOBF_PrjSpecQuC_btm
#define P_TJAOBF_PrjSpecQuC_btm (LCF_CommonParamData.P_TJAOBF_PrjSpecQuC_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_PrjSpecQuC_btm() (P_TJAOBF_PrjSpecQuC_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_PrjSpecQuC_btm

#ifndef P_TJAOBF_PrjSpecQuSR_btm
#define P_TJAOBF_PrjSpecQuSR_btm (LCF_CommonParamData.P_TJAOBF_PrjSpecQuSR_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_PrjSpecQuSR_btm() (P_TJAOBF_PrjSpecQuSR_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_PrjSpecQuSR_btm

#ifndef P_TJAOBF_PrjSpecQuWR_btm
#define P_TJAOBF_PrjSpecQuWR_btm (LCF_CommonParamData.P_TJAOBF_PrjSpecQuWR_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_PrjSpecQuWR_btm() (P_TJAOBF_PrjSpecQuWR_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_PrjSpecQuWR_btm

#ifndef P_TJAOBF_TgtClthCrvMaxHyst_1pm
#define P_TJAOBF_TgtClthCrvMaxHyst_1pm (LCF_CommonParamData.P_TJAOBF_TgtClthCrvMaxHyst_1pm) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthCrvMaxHyst_1pm() (P_TJAOBF_TgtClthCrvMaxHyst_1pm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthCrvMaxHyst_1pm

#ifndef P_TJAOBF_TgtClthHeadMaxHyst_rad
#define P_TJAOBF_TgtClthHeadMaxHyst_rad (LCF_CommonParamData.P_TJAOBF_TgtClthHeadMaxHyst_rad) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthHeadMaxHyst_rad() (P_TJAOBF_TgtClthHeadMaxHyst_rad) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthHeadMaxHyst_rad

#ifndef P_TJAOBF_TgtClthInvalid_btm
#define P_TJAOBF_TgtClthInvalid_btm (LCF_CommonParamData.P_TJAOBF_TgtClthInvalid_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthInvalid_btm() (P_TJAOBF_TgtClthInvalid_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthInvalid_btm

#ifndef P_TJAOBF_TgtClthLengthMin_met
#define P_TJAOBF_TgtClthLengthMin_met (LCF_CommonParamData.P_TJAOBF_TgtClthLengthMin_met) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthLengthMin_met() (P_TJAOBF_TgtClthLengthMin_met) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthLengthMin_met

#ifndef P_TJAOBF_TgtClthMinValidTime_sec
#define P_TJAOBF_TgtClthMinValidTime_sec (LCF_CommonParamData.P_TJAOBF_TgtClthMinValidTime_sec) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthMinValidTime_sec() (P_TJAOBF_TgtClthMinValidTime_sec) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthMinValidTime_sec

#ifndef P_TJAOBF_TgtClthPosYMaxHyst_met
#define P_TJAOBF_TgtClthPosYMaxHyst_met (LCF_CommonParamData.P_TJAOBF_TgtClthPosYMaxHyst_met) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthPosYMaxHyst_met() (P_TJAOBF_TgtClthPosYMaxHyst_met) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthPosYMaxHyst_met

#ifndef P_TJAOBF_TgtClthWRInvalid_btm
#define P_TJAOBF_TgtClthWRInvalid_btm (LCF_CommonParamData.P_TJAOBF_TgtClthWRInvalid_btm) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtClthWRInvalid_btm() (P_TJAOBF_TgtClthWRInvalid_btm) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtClthWRInvalid_btm

#ifndef P_TJAOBF_TgtVehDist2LnBndHst_met
#define P_TJAOBF_TgtVehDist2LnBndHst_met (LCF_CommonParamData.P_TJAOBF_TgtVehDist2LnBndHst_met) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtVehDist2LnBndHst_met() (P_TJAOBF_TgtVehDist2LnBndHst_met) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtVehDist2LnBndHst_met

#ifndef P_TJAOBF_TgtVehDist2LnBndMin_met
#define P_TJAOBF_TgtVehDist2LnBndMin_met (LCF_CommonParamData.P_TJAOBF_TgtVehDist2LnBndMin_met) //!< LCF parameter macro.
#define GET_P_TJAOBF_TgtVehDist2LnBndMin_met() (P_TJAOBF_TgtVehDist2LnBndMin_met) //!< LCF parameter macro getter.
#endif // P_TJAOBF_TgtVehDist2LnBndMin_met

#ifndef P_TJAOBF_VelXMax_kph
#define P_TJAOBF_VelXMax_kph (LCF_CommonParamData.P_TJAOBF_VelXMax_kph) //!< LCF parameter macro.
#define GET_P_TJAOBF_VelXMax_kph() (P_TJAOBF_VelXMax_kph) //!< LCF parameter macro getter.
#endif // P_TJAOBF_VelXMax_kph

#ifndef P_TJAOBF_VelXMinOF_kph
#define P_TJAOBF_VelXMinOF_kph (LCF_CommonParamData.P_TJAOBF_VelXMinOF_kph) //!< LCF parameter macro.
#define GET_P_TJAOBF_VelXMinOF_kph() (P_TJAOBF_VelXMinOF_kph) //!< LCF parameter macro getter.
#endif // P_TJAOBF_VelXMinOF_kph

#ifndef P_TJAOBF_VelXMin_kph
#define P_TJAOBF_VelXMin_kph (LCF_CommonParamData.P_TJAOBF_VelXMin_kph) //!< LCF parameter macro.
#define GET_P_TJAOBF_VelXMin_kph() (P_TJAOBF_VelXMin_kph) //!< LCF parameter macro getter.
#endif // P_TJAOBF_VelXMin_kph

#ifndef P_TJASLC_SALC_Enabled_bool
#define P_TJASLC_SALC_Enabled_bool (LCF_CommonParamData.P_TJASLC_SALC_Enabled_bool) //!< LCF parameter macro.
#define GET_P_TJASLC_SALC_Enabled_bool() (P_TJASLC_SALC_Enabled_bool) //!< LCF parameter macro getter.
#endif // P_TJASLC_SALC_Enabled_bool

#ifndef P_TJATTG_CrvChngDecay_nu
#define P_TJATTG_CrvChngDecay_nu (LCF_CommonParamData.P_TJATTG_CrvChngDecay_nu) //!< LCF parameter macro.
#define GET_P_TJATTG_CrvChngDecay_nu() (P_TJATTG_CrvChngDecay_nu) //!< LCF parameter macro getter.
#endif // P_TJATTG_CrvChngDecay_nu

#ifndef P_TJATTG_EnableVirtAdjLane_bool
#define P_TJATTG_EnableVirtAdjLane_bool (LCF_CommonParamData.P_TJATTG_EnableVirtAdjLane_bool) //!< LCF parameter macro.
#define GET_P_TJATTG_EnableVirtAdjLane_bool() (P_TJATTG_EnableVirtAdjLane_bool) //!< LCF parameter macro getter.
#endif // P_TJATTG_EnableVirtAdjLane_bool

#ifndef P_TJATTG_LnMeasCrvChngVar_1pm4
#define P_TJATTG_LnMeasCrvChngVar_1pm4 (LCF_CommonParamData.P_TJATTG_LnMeasCrvChngVar_1pm4) //!< LCF parameter macro.
#define GET_P_TJATTG_LnMeasCrvChngVar_1pm4() (P_TJATTG_LnMeasCrvChngVar_1pm4) //!< LCF parameter macro getter.
#endif // P_TJATTG_LnMeasCrvChngVar_1pm4

#ifndef P_TJATTG_LnMeasCrvVar_1pm2
#define P_TJATTG_LnMeasCrvVar_1pm2 (LCF_CommonParamData.P_TJATTG_LnMeasCrvVar_1pm2) //!< LCF parameter macro.
#define GET_P_TJATTG_LnMeasCrvVar_1pm2() (P_TJATTG_LnMeasCrvVar_1pm2) //!< LCF parameter macro getter.
#endif // P_TJATTG_LnMeasCrvVar_1pm2

#ifndef P_TJATTG_LnMeasHeadVar_rad2
#define P_TJATTG_LnMeasHeadVar_rad2 (LCF_CommonParamData.P_TJATTG_LnMeasHeadVar_rad2) //!< LCF parameter macro.
#define GET_P_TJATTG_LnMeasHeadVar_rad2() (P_TJATTG_LnMeasHeadVar_rad2) //!< LCF parameter macro getter.
#endif // P_TJATTG_LnMeasHeadVar_rad2

#ifndef P_TJATTG_LnMeasPosYVar_m2
#define P_TJATTG_LnMeasPosYVar_m2 (LCF_CommonParamData.P_TJATTG_LnMeasPosYVar_m2) //!< LCF parameter macro.
#define GET_P_TJATTG_LnMeasPosYVar_m2() (P_TJATTG_LnMeasPosYVar_m2) //!< LCF parameter macro getter.
#endif // P_TJATTG_LnMeasPosYVar_m2

#ifndef P_TJATTG_LnPredMinTrajLength_met
#define P_TJATTG_LnPredMinTrajLength_met (LCF_CommonParamData.P_TJATTG_LnPredMinTrajLength_met) //!< LCF parameter macro.
#define GET_P_TJATTG_LnPredMinTrajLength_met() (P_TJATTG_LnPredMinTrajLength_met) //!< LCF parameter macro getter.
#endif // P_TJATTG_LnPredMinTrajLength_met

#ifndef P_TJATTG_ModelCrvChngVar_1pm4
#define P_TJATTG_ModelCrvChngVar_1pm4 (LCF_CommonParamData.P_TJATTG_ModelCrvChngVar_1pm4) //!< LCF parameter macro.
#define GET_P_TJATTG_ModelCrvChngVar_1pm4() (P_TJATTG_ModelCrvChngVar_1pm4) //!< LCF parameter macro getter.
#endif // P_TJATTG_ModelCrvChngVar_1pm4

#ifndef P_TJATTG_ModelCrvVar_1pm2
#define P_TJATTG_ModelCrvVar_1pm2 (LCF_CommonParamData.P_TJATTG_ModelCrvVar_1pm2) //!< LCF parameter macro.
#define GET_P_TJATTG_ModelCrvVar_1pm2() (P_TJATTG_ModelCrvVar_1pm2) //!< LCF parameter macro getter.
#endif // P_TJATTG_ModelCrvVar_1pm2

#ifndef P_TJATTG_ModelPosYVar_m2
#define P_TJATTG_ModelPosYVar_m2 (LCF_CommonParamData.P_TJATTG_ModelPosYVar_m2) //!< LCF parameter macro.
#define GET_P_TJATTG_ModelPosYVar_m2() (P_TJATTG_ModelPosYVar_m2) //!< LCF parameter macro getter.
#endif // P_TJATTG_ModelPosYVar_m2

#ifndef P_TJATTG_ModelYawVar_rad2
#define P_TJATTG_ModelYawVar_rad2 (LCF_CommonParamData.P_TJATTG_ModelYawVar_rad2) //!< LCF parameter macro.
#define GET_P_TJATTG_ModelYawVar_rad2() (P_TJATTG_ModelYawVar_rad2) //!< LCF parameter macro getter.
#endif // P_TJATTG_ModelYawVar_rad2

#ifndef P_TJATTG_NewPredEnable_bool
#define P_TJATTG_NewPredEnable_bool (LCF_CommonParamData.P_TJATTG_NewPredEnable_bool) //!< LCF parameter macro.
#define GET_P_TJATTG_NewPredEnable_bool() (P_TJATTG_NewPredEnable_bool) //!< LCF parameter macro getter.
#endif // P_TJATTG_NewPredEnable_bool

#ifndef P_TJATTG_ObjFolVirtLnWdth_met
#define P_TJATTG_ObjFolVirtLnWdth_met (LCF_CommonParamData.P_TJATTG_ObjFolVirtLnWdth_met) //!< LCF parameter macro.
#define GET_P_TJATTG_ObjFolVirtLnWdth_met() (P_TJATTG_ObjFolVirtLnWdth_met) //!< LCF parameter macro getter.
#endif // P_TJATTG_ObjFolVirtLnWdth_met

#ifndef P_TJATTG_ObjMeasPosXVar_m2
#define P_TJATTG_ObjMeasPosXVar_m2 (LCF_CommonParamData.P_TJATTG_ObjMeasPosXVar_m2) //!< LCF parameter macro.
#define GET_P_TJATTG_ObjMeasPosXVar_m2() (P_TJATTG_ObjMeasPosXVar_m2) //!< LCF parameter macro getter.
#endif // P_TJATTG_ObjMeasPosXVar_m2

#ifndef P_TJATTG_ObjMeasPosYVar_m2
#define P_TJATTG_ObjMeasPosYVar_m2 (LCF_CommonParamData.P_TJATTG_ObjMeasPosYVar_m2) //!< LCF parameter macro.
#define GET_P_TJATTG_ObjMeasPosYVar_m2() (P_TJATTG_ObjMeasPosYVar_m2) //!< LCF parameter macro getter.
#endif // P_TJATTG_ObjMeasPosYVar_m2

#ifndef P_TJATTG_PredCrvChngPT1_sec
#define P_TJATTG_PredCrvChngPT1_sec (LCF_CommonParamData.P_TJATTG_PredCrvChngPT1_sec) //!< LCF parameter macro.
#define GET_P_TJATTG_PredCrvChngPT1_sec() (P_TJATTG_PredCrvChngPT1_sec) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredCrvChngPT1_sec

#ifndef P_TJATTG_PredCrvPT1_sec
#define P_TJATTG_PredCrvPT1_sec (LCF_CommonParamData.P_TJATTG_PredCrvPT1_sec) //!< LCF parameter macro.
#define GET_P_TJATTG_PredCrvPT1_sec() (P_TJATTG_PredCrvPT1_sec) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredCrvPT1_sec

#ifndef P_TJATTG_PredFreezeCrvChng_bool
#define P_TJATTG_PredFreezeCrvChng_bool (LCF_CommonParamData.P_TJATTG_PredFreezeCrvChng_bool) //!< LCF parameter macro.
#define GET_P_TJATTG_PredFreezeCrvChng_bool() (P_TJATTG_PredFreezeCrvChng_bool) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredFreezeCrvChng_bool

#ifndef P_TJATTG_PredFreezeCrv_bool
#define P_TJATTG_PredFreezeCrv_bool (LCF_CommonParamData.P_TJATTG_PredFreezeCrv_bool) //!< LCF parameter macro.
#define GET_P_TJATTG_PredFreezeCrv_bool() (P_TJATTG_PredFreezeCrv_bool) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredFreezeCrv_bool

#ifndef P_TJATTG_PredResetTrajLength_met
#define P_TJATTG_PredResetTrajLength_met (LCF_CommonParamData.P_TJATTG_PredResetTrajLength_met) //!< LCF parameter macro.
#define GET_P_TJATTG_PredResetTrajLength_met() (P_TJATTG_PredResetTrajLength_met) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredResetTrajLength_met

#ifndef P_TJATTG_PredVelXVar_m2
#define P_TJATTG_PredVelXVar_m2 (LCF_CommonParamData.P_TJATTG_PredVelXVar_m2) //!< LCF parameter macro.
#define GET_P_TJATTG_PredVelXVar_m2() (P_TJATTG_PredVelXVar_m2) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredVelXVar_m2

#ifndef P_TJATTG_PredYawRtVar_r2ps2
#define P_TJATTG_PredYawRtVar_r2ps2 (LCF_CommonParamData.P_TJATTG_PredYawRtVar_r2ps2) //!< LCF parameter macro.
#define GET_P_TJATTG_PredYawRtVar_r2ps2() (P_TJATTG_PredYawRtVar_r2ps2) //!< LCF parameter macro getter.
#endif // P_TJATTG_PredYawRtVar_r2ps2

#ifndef P_TJATTG_TransDurationCMB_sec
#define P_TJATTG_TransDurationCMB_sec (LCF_CommonParamData.P_TJATTG_TransDurationCMB_sec) //!< LCF parameter macro.
#define GET_P_TJATTG_TransDurationCMB_sec() (P_TJATTG_TransDurationCMB_sec) //!< LCF parameter macro getter.
#endif // P_TJATTG_TransDurationCMB_sec

#ifndef P_TJATTG_TransDurationLD_sec
#define P_TJATTG_TransDurationLD_sec (LCF_CommonParamData.P_TJATTG_TransDurationLD_sec) //!< LCF parameter macro.
#define GET_P_TJATTG_TransDurationLD_sec() (P_TJATTG_TransDurationLD_sec) //!< LCF parameter macro getter.
#endif // P_TJATTG_TransDurationLD_sec

#ifndef P_TJATTG_TransDurationOD_sec
#define P_TJATTG_TransDurationOD_sec (LCF_CommonParamData.P_TJATTG_TransDurationOD_sec) //!< LCF parameter macro.
#define GET_P_TJATTG_TransDurationOD_sec() (P_TJATTG_TransDurationOD_sec) //!< LCF parameter macro getter.
#endif // P_TJATTG_TransDurationOD_sec

#ifndef P_TJATTG_TransDurationPredct_sec
#define P_TJATTG_TransDurationPredct_sec (LCF_CommonParamData.P_TJATTG_TransDurationPredct_sec) //!< LCF parameter macro.
#define GET_P_TJATTG_TransDurationPredct_sec() (P_TJATTG_TransDurationPredct_sec) //!< LCF parameter macro getter.
#endif // P_TJATTG_TransDurationPredct_sec

#ifndef P_TJATTG_TransHandleEnable_bool
#define P_TJATTG_TransHandleEnable_bool (LCF_CommonParamData.P_TJATTG_TransHandleEnable_bool) //!< LCF parameter macro.
#define GET_P_TJATTG_TransHandleEnable_bool() (P_TJATTG_TransHandleEnable_bool) //!< LCF parameter macro getter.
#endif // P_TJATTG_TransHandleEnable_bool

#ifndef P_TJATTG_TriggerReplanCMBLC2OF_bool
#define P_TJATTG_TriggerReplanCMBLC2OF_bool (LCF_CommonParamData.P_TJATTG_TriggerReplanCMBLC2OF_bool) //!< LCF parameter macro.
#define GET_P_TJATTG_TriggerReplanCMBLC2OF_bool() (P_TJATTG_TriggerReplanCMBLC2OF_bool) //!< LCF parameter macro getter.
#endif // P_TJATTG_TriggerReplanCMBLC2OF_bool

#ifndef P_TJATTG_VirtAdjLaneWidth_met
#define P_TJATTG_VirtAdjLaneWidth_met (LCF_CommonParamData.P_TJATTG_VirtAdjLaneWidth_met) //!< LCF parameter macro.
#define GET_P_TJATTG_VirtAdjLaneWidth_met() (P_TJATTG_VirtAdjLaneWidth_met) //!< LCF parameter macro getter.
#endif // P_TJATTG_VirtAdjLaneWidth_met

#ifndef P_TJATVG_DistYToleranceLeftTgtArea_met
#define P_TJATVG_DistYToleranceLeftTgtArea_met (LCF_CommonParamData.P_TJATVG_DistYToleranceLeftTgtArea_met) //!< LCF parameter macro.
#define GET_P_TJATVG_DistYToleranceLeftTgtArea_met() (P_TJATVG_DistYToleranceLeftTgtArea_met) //!< LCF parameter macro getter.
#endif // P_TJATVG_DistYToleranceLeftTgtArea_met

#ifndef P_TJATVG_DistYToleranceRightTgtArea_met
#define P_TJATVG_DistYToleranceRightTgtArea_met (LCF_CommonParamData.P_TJATVG_DistYToleranceRightTgtArea_met) //!< LCF parameter macro.
#define GET_P_TJATVG_DistYToleranceRightTgtArea_met() (P_TJATVG_DistYToleranceRightTgtArea_met) //!< LCF parameter macro getter.
#endif // P_TJATVG_DistYToleranceRightTgtArea_met

#ifndef P_TJATVG_FTireAccelMax_mps2
#define P_TJATVG_FTireAccelMax_mps2 (LCF_CommonParamData.P_TJATVG_FTireAccelMax_mps2) //!< LCF parameter macro.
#define GET_P_TJATVG_FTireAccelMax_mps2() (P_TJATVG_FTireAccelMax_mps2) //!< LCF parameter macro getter.
#endif // P_TJATVG_FTireAccelMax_mps2

#ifndef P_TJATVG_FTireAccelMin_mps2
#define P_TJATVG_FTireAccelMin_mps2 (LCF_CommonParamData.P_TJATVG_FTireAccelMin_mps2) //!< LCF parameter macro.
#define GET_P_TJATVG_FTireAccelMin_mps2() (P_TJATVG_FTireAccelMin_mps2) //!< LCF parameter macro getter.
#endif // P_TJATVG_FTireAccelMin_mps2

#ifndef P_TJATVG_FactorCrvGrdBuildUp_nu
#define P_TJATVG_FactorCrvGrdBuildUp_nu (LCF_CommonParamData.P_TJATVG_FactorCrvGrdBuildUp_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_FactorCrvGrdBuildUp_nu() (P_TJATVG_FactorCrvGrdBuildUp_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_FactorCrvGrdBuildUp_nu

#ifndef P_TJATVG_FactorCrvGrdRed_nu
#define P_TJATVG_FactorCrvGrdRed_nu (LCF_CommonParamData.P_TJATVG_FactorCrvGrdRed_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_FactorCrvGrdRed_nu() (P_TJATVG_FactorCrvGrdRed_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_FactorCrvGrdRed_nu

#ifndef P_TJATVG_GrdLimitTgtCrvTGC_1pms
#define P_TJATVG_GrdLimitTgtCrvTGC_1pms (LCF_CommonParamData.P_TJATVG_GrdLimitTgtCrvTGC_1pms) //!< LCF parameter macro.
#define GET_P_TJATVG_GrdLimitTgtCrvTGC_1pms() (P_TJATVG_GrdLimitTgtCrvTGC_1pms) //!< LCF parameter macro getter.
#endif // P_TJATVG_GrdLimitTgtCrvTGC_1pms

#ifndef P_TJATVG_HighStatAccu_bool
#define P_TJATVG_HighStatAccu_bool (LCF_CommonParamData.P_TJATVG_HighStatAccu_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_HighStatAccu_bool() (P_TJATVG_HighStatAccu_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_HighStatAccu_bool

#ifndef P_TJATVG_LimiterMaxCrvGrd_1pms
#define P_TJATVG_LimiterMaxCrvGrd_1pms (LCF_CommonParamData.P_TJATVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro.
#define GET_P_TJATVG_LimiterMaxCrvGrd_1pms() (P_TJATVG_LimiterMaxCrvGrd_1pms) //!< LCF parameter macro getter.
#endif // P_TJATVG_LimiterMaxCrvGrd_1pms

#ifndef P_TJATVG_LimiterMaxCrv_1pm
#define P_TJATVG_LimiterMaxCrv_1pm (LCF_CommonParamData.P_TJATVG_LimiterMaxCrv_1pm) //!< LCF parameter macro.
#define GET_P_TJATVG_LimiterMaxCrv_1pm() (P_TJATVG_LimiterMaxCrv_1pm) //!< LCF parameter macro getter.
#endif // P_TJATVG_LimiterMaxCrv_1pm

#ifndef P_TJATVG_MD1DeratingLevel_perc
#define P_TJATVG_MD1DeratingLevel_perc (LCF_CommonParamData.P_TJATVG_MD1DeratingLevel_perc) //!< LCF parameter macro.
#define GET_P_TJATVG_MD1DeratingLevel_perc() (P_TJATVG_MD1DeratingLevel_perc) //!< LCF parameter macro getter.
#endif // P_TJATVG_MD1DeratingLevel_perc

#ifndef P_TJATVG_MD2DeratingLevel_perc
#define P_TJATVG_MD2DeratingLevel_perc (LCF_CommonParamData.P_TJATVG_MD2DeratingLevel_perc) //!< LCF parameter macro.
#define GET_P_TJATVG_MD2DeratingLevel_perc() (P_TJATVG_MD2DeratingLevel_perc) //!< LCF parameter macro getter.
#endif // P_TJATVG_MD2DeratingLevel_perc

#ifndef P_TJATVG_MD3DeratingLevel_perc
#define P_TJATVG_MD3DeratingLevel_perc (LCF_CommonParamData.P_TJATVG_MD3DeratingLevel_perc) //!< LCF parameter macro.
#define GET_P_TJATVG_MD3DeratingLevel_perc() (P_TJATVG_MD3DeratingLevel_perc) //!< LCF parameter macro getter.
#endif // P_TJATVG_MD3DeratingLevel_perc

#ifndef P_TJATVG_MaxJerkAllowed_mps3
#define P_TJATVG_MaxJerkAllowed_mps3 (LCF_CommonParamData.P_TJATVG_MaxJerkAllowed_mps3) //!< LCF parameter macro.
#define GET_P_TJATVG_MaxJerkAllowed_mps3() (P_TJATVG_MaxJerkAllowed_mps3) //!< LCF parameter macro getter.
#endif // P_TJATVG_MaxJerkAllowed_mps3

#ifndef P_TJATVG_MaxSteeringAngle_deg
#define P_TJATVG_MaxSteeringAngle_deg (LCF_CommonParamData.P_TJATVG_MaxSteeringAngle_deg) //!< LCF parameter macro.
#define GET_P_TJATVG_MaxSteeringAngle_deg() (P_TJATVG_MaxSteeringAngle_deg) //!< LCF parameter macro getter.
#endif // P_TJATVG_MaxSteeringAngle_deg

#ifndef P_TJATVG_MaxTrqScalLimit_nu
#define P_TJATVG_MaxTrqScalLimit_nu (LCF_CommonParamData.P_TJATVG_MaxTrqScalLimit_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_MaxTrqScalLimit_nu() (P_TJATVG_MaxTrqScalLimit_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_MaxTrqScalLimit_nu

#ifndef P_TJATVG_MaxTrqScalRampInGrd_1ps
#define P_TJATVG_MaxTrqScalRampInGrd_1ps (LCF_CommonParamData.P_TJATVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_MaxTrqScalRampInGrd_1ps() (P_TJATVG_MaxTrqScalRampInGrd_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_MaxTrqScalRampInGrd_1ps

#ifndef P_TJATVG_MaxTrqScalRampOutGrd_1ps
#define P_TJATVG_MaxTrqScalRampOutGrd_1ps (LCF_CommonParamData.P_TJATVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_MaxTrqScalRampOutGrd_1ps() (P_TJATVG_MaxTrqScalRampOutGrd_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_MaxTrqScalRampOutGrd_1ps

#ifndef P_TJATVG_MinFactorCrvGrd_nu
#define P_TJATVG_MinFactorCrvGrd_nu (LCF_CommonParamData.P_TJATVG_MinFactorCrvGrd_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_MinFactorCrvGrd_nu() (P_TJATVG_MinFactorCrvGrd_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_MinFactorCrvGrd_nu

#ifndef P_TJATVG_ModeTransTrigReplan_bool
#define P_TJATVG_ModeTransTrigReplan_bool (LCF_CommonParamData.P_TJATVG_ModeTransTrigReplan_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_ModeTransTrigReplan_bool() (P_TJATVG_ModeTransTrigReplan_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_ModeTransTrigReplan_bool

#ifndef P_TJATVG_PlanHorzLaneChange_sec
#define P_TJATVG_PlanHorzLaneChange_sec (LCF_CommonParamData.P_TJATVG_PlanHorzLaneChange_sec) //!< LCF parameter macro.
#define GET_P_TJATVG_PlanHorzLaneChange_sec() (P_TJATVG_PlanHorzLaneChange_sec) //!< LCF parameter macro getter.
#endif // P_TJATVG_PlanHorzLaneChange_sec

#ifndef P_TJATVG_PredTimeHeadAng_sec
#define P_TJATVG_PredTimeHeadAng_sec (LCF_CommonParamData.P_TJATVG_PredTimeHeadAng_sec) //!< LCF parameter macro.
#define GET_P_TJATVG_PredTimeHeadAng_sec() (P_TJATVG_PredTimeHeadAng_sec) //!< LCF parameter macro getter.
#endif // P_TJATVG_PredTimeHeadAng_sec

#ifndef P_TJATVG_PredictionTimeCrv_sec
#define P_TJATVG_PredictionTimeCrv_sec (LCF_CommonParamData.P_TJATVG_PredictionTimeCrv_sec) //!< LCF parameter macro.
#define GET_P_TJATVG_PredictionTimeCrv_sec() (P_TJATVG_PredictionTimeCrv_sec) //!< LCF parameter macro getter.
#endif // P_TJATVG_PredictionTimeCrv_sec

#ifndef P_TJATVG_SetMaxCrvAndGrdLims_nu
#define P_TJATVG_SetMaxCrvAndGrdLims_nu (LCF_CommonParamData.P_TJATVG_SetMaxCrvAndGrdLims_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_SetMaxCrvAndGrdLims_nu() (P_TJATVG_SetMaxCrvAndGrdLims_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_SetMaxCrvAndGrdLims_nu

#ifndef P_TJATVG_StrWhStifAbortGrd_1ps
#define P_TJATVG_StrWhStifAbortGrd_1ps (LCF_CommonParamData.P_TJATVG_StrWhStifAbortGrd_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_StrWhStifAbortGrd_1ps() (P_TJATVG_StrWhStifAbortGrd_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_StrWhStifAbortGrd_1ps

#ifndef P_TJATVG_StrWhStifLimitPredct_nu
#define P_TJATVG_StrWhStifLimitPredct_nu (LCF_CommonParamData.P_TJATVG_StrWhStifLimitPredct_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_StrWhStifLimitPredct_nu() (P_TJATVG_StrWhStifLimitPredct_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_StrWhStifLimitPredct_nu

#ifndef P_TJATVG_StrWhStifLimit_nu
#define P_TJATVG_StrWhStifLimit_nu (LCF_CommonParamData.P_TJATVG_StrWhStifLimit_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_StrWhStifLimit_nu() (P_TJATVG_StrWhStifLimit_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_StrWhStifLimit_nu

#ifndef P_TJATVG_StrWhStifRampInGrd_1ps
#define P_TJATVG_StrWhStifRampInGrd_1ps (LCF_CommonParamData.P_TJATVG_StrWhStifRampInGrd_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_StrWhStifRampInGrd_1ps() (P_TJATVG_StrWhStifRampInGrd_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_StrWhStifRampInGrd_1ps

#ifndef P_TJATVG_StrWhStifRampOutGrd_1ps
#define P_TJATVG_StrWhStifRampOutGrd_1ps (LCF_CommonParamData.P_TJATVG_StrWhStifRampOutGrd_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_StrWhStifRampOutGrd_1ps() (P_TJATVG_StrWhStifRampOutGrd_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_StrWhStifRampOutGrd_1ps

#ifndef P_TJATVG_TrajPlanValServQu_nu
#define P_TJATVG_TrajPlanValServQu_nu (LCF_CommonParamData.P_TJATVG_TrajPlanValServQu_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_TrajPlanValServQu_nu() (P_TJATVG_TrajPlanValServQu_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_TrajPlanValServQu_nu

#ifndef P_TJATVG_TrajPlanValSrvQuSALC_nu
#define P_TJATVG_TrajPlanValSrvQuSALC_nu (LCF_CommonParamData.P_TJATVG_TrajPlanValSrvQuSALC_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_TrajPlanValSrvQuSALC_nu() (P_TJATVG_TrajPlanValSrvQuSALC_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_TrajPlanValSrvQuSALC_nu

#ifndef P_TJATVG_TriggerReplan_bool
#define P_TJATVG_TriggerReplan_bool (LCF_CommonParamData.P_TJATVG_TriggerReplan_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_TriggerReplan_bool() (P_TJATVG_TriggerReplan_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_TriggerReplan_bool

#ifndef P_TJATVG_TrqAbortGrad_1ps
#define P_TJATVG_TrqAbortGrad_1ps (LCF_CommonParamData.P_TJATVG_TrqAbortGrad_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_TrqAbortGrad_1ps() (P_TJATVG_TrqAbortGrad_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_TrqAbortGrad_1ps

#ifndef P_TJATVG_TrqRampInGrad_1ps
#define P_TJATVG_TrqRampInGrad_1ps (LCF_CommonParamData.P_TJATVG_TrqRampInGrad_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_TrqRampInGrad_1ps() (P_TJATVG_TrqRampInGrad_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_TrqRampInGrad_1ps

#ifndef P_TJATVG_TrqRampOutGrad_1ps
#define P_TJATVG_TrqRampOutGrad_1ps (LCF_CommonParamData.P_TJATVG_TrqRampOutGrad_1ps) //!< LCF parameter macro.
#define GET_P_TJATVG_TrqRampOutGrad_1ps() (P_TJATVG_TrqRampOutGrad_1ps) //!< LCF parameter macro getter.
#endif // P_TJATVG_TrqRampOutGrad_1ps

#ifndef P_TJATVG_UseLtcyCompCMB_bool
#define P_TJATVG_UseLtcyCompCMB_bool (LCF_CommonParamData.P_TJATVG_UseLtcyCompCMB_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_UseLtcyCompCMB_bool() (P_TJATVG_UseLtcyCompCMB_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_UseLtcyCompCMB_bool

#ifndef P_TJATVG_UseLtcyCompLC_bool
#define P_TJATVG_UseLtcyCompLC_bool (LCF_CommonParamData.P_TJATVG_UseLtcyCompLC_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_UseLtcyCompLC_bool() (P_TJATVG_UseLtcyCompLC_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_UseLtcyCompLC_bool

#ifndef P_TJATVG_UseLtcyCompOF_bool
#define P_TJATVG_UseLtcyCompOF_bool (LCF_CommonParamData.P_TJATVG_UseLtcyCompOF_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_UseLtcyCompOF_bool() (P_TJATVG_UseLtcyCompOF_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_UseLtcyCompOF_bool

#ifndef P_TJATVG_UseLtcyCompSALC_bool
#define P_TJATVG_UseLtcyCompSALC_bool (LCF_CommonParamData.P_TJATVG_UseLtcyCompSALC_bool) //!< LCF parameter macro.
#define GET_P_TJATVG_UseLtcyCompSALC_bool() (P_TJATVG_UseLtcyCompSALC_bool) //!< LCF parameter macro getter.
#endif // P_TJATVG_UseLtcyCompSALC_bool

#ifndef P_TJATVG_WeightEndtime_nu
#define P_TJATVG_WeightEndtime_nu (LCF_CommonParamData.P_TJATVG_WeightEndtime_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_WeightEndtime_nu() (P_TJATVG_WeightEndtime_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_WeightEndtime_nu

#ifndef P_TJATVG_WeightTgtDistY_nu
#define P_TJATVG_WeightTgtDistY_nu (LCF_CommonParamData.P_TJATVG_WeightTgtDistY_nu) //!< LCF parameter macro.
#define GET_P_TJATVG_WeightTgtDistY_nu() (P_TJATVG_WeightTgtDistY_nu) //!< LCF parameter macro getter.
#endif // P_TJATVG_WeightTgtDistY_nu

#ifndef P_TJA_Available_bool
#define P_TJA_Available_bool (LCF_CommonParamData.P_TJA_Available_bool) //!< LCF parameter macro.
#define GET_P_TJA_Available_bool() (P_TJA_Available_bool) //!< LCF parameter macro getter.
#endif // P_TJA_Available_bool

#ifndef P_TJA_ManFunctionSwitch_bool
#define P_TJA_ManFunctionSwitch_bool (LCF_CommonParamData.P_TJA_ManFunctionSwitch_bool) //!< LCF parameter macro.
#define GET_P_TJA_ManFunctionSwitch_bool() (P_TJA_ManFunctionSwitch_bool) //!< LCF parameter macro getter.
#endif // P_TJA_ManFunctionSwitch_bool

#ifndef P_TPLCEN_ActivebyRampout_nu
#define P_TPLCEN_ActivebyRampout_nu (LCF_CommonParamData.P_TPLCEN_ActivebyRampout_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_ActivebyRampout_nu() (P_TPLCEN_ActivebyRampout_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ActivebyRampout_nu

#ifndef P_TPLCEN_AllowReplanOBF_nu
#define P_TPLCEN_AllowReplanOBF_nu (LCF_CommonParamData.P_TPLCEN_AllowReplanOBF_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_AllowReplanOBF_nu() (P_TPLCEN_AllowReplanOBF_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_AllowReplanOBF_nu

#ifndef P_TPLCEN_AllowSpePlanStrategy_nu
#define P_TPLCEN_AllowSpePlanStrategy_nu (LCF_CommonParamData.P_TPLCEN_AllowSpePlanStrategy_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_AllowSpePlanStrategy_nu() (P_TPLCEN_AllowSpePlanStrategy_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_AllowSpePlanStrategy_nu

#ifndef P_TPLCEN_CyCTimeTrajCalc_sec
#define P_TPLCEN_CyCTimeTrajCalc_sec (LCF_CommonParamData.P_TPLCEN_CyCTimeTrajCalc_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_CyCTimeTrajCalc_sec() (P_TPLCEN_CyCTimeTrajCalc_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_CyCTimeTrajCalc_sec

#ifndef P_TPLCEN_CycEnable_nu
#define P_TPLCEN_CycEnable_nu (LCF_CommonParamData.P_TPLCEN_CycEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_CycEnable_nu() (P_TPLCEN_CycEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_CycEnable_nu

#ifndef P_TPLCEN_DTGradLimitDuration_sec
#define P_TPLCEN_DTGradLimitDuration_sec (LCF_CommonParamData.P_TPLCEN_DTGradLimitDuration_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_DTGradLimitDuration_sec() (P_TPLCEN_DTGradLimitDuration_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_DTGradLimitDuration_sec

#ifndef P_TPLCEN_EnableFcnChngDetect_nu
#define P_TPLCEN_EnableFcnChngDetect_nu (LCF_CommonParamData.P_TPLCEN_EnableFcnChngDetect_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_EnableFcnChngDetect_nu() (P_TPLCEN_EnableFcnChngDetect_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_EnableFcnChngDetect_nu

#ifndef P_TPLCEN_EnableJumpDetectOBF_nu
#define P_TPLCEN_EnableJumpDetectOBF_nu (LCF_CommonParamData.P_TPLCEN_EnableJumpDetectOBF_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_EnableJumpDetectOBF_nu() (P_TPLCEN_EnableJumpDetectOBF_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_EnableJumpDetectOBF_nu

#ifndef P_TPLCEN_EnableJumpDetectOFRQ_nu
#define P_TPLCEN_EnableJumpDetectOFRQ_nu (LCF_CommonParamData.P_TPLCEN_EnableJumpDetectOFRQ_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_EnableJumpDetectOFRQ_nu() (P_TPLCEN_EnableJumpDetectOFRQ_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_EnableJumpDetectOFRQ_nu

#ifndef P_TPLCEN_ErrDistY_met
#define P_TPLCEN_ErrDistY_met (LCF_CommonParamData.P_TPLCEN_ErrDistY_met) //!< LCF parameter macro.
#define GET_P_TPLCEN_ErrDistY_met() (P_TPLCEN_ErrDistY_met) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ErrDistY_met

#ifndef P_TPLCEN_ErrHeadAglPrev_rad
#define P_TPLCEN_ErrHeadAglPrev_rad (LCF_CommonParamData.P_TPLCEN_ErrHeadAglPrev_rad) //!< LCF parameter macro.
#define GET_P_TPLCEN_ErrHeadAglPrev_rad() (P_TPLCEN_ErrHeadAglPrev_rad) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ErrHeadAglPrev_rad

#ifndef P_TPLCEN_LCOReplanEnable_nu
#define P_TPLCEN_LCOReplanEnable_nu (LCF_CommonParamData.P_TPLCEN_LCOReplanEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_LCOReplanEnable_nu() (P_TPLCEN_LCOReplanEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_LCOReplanEnable_nu

#ifndef P_TPLCEN_ManualTrqMaxTime_sec
#define P_TPLCEN_ManualTrqMaxTime_sec (LCF_CommonParamData.P_TPLCEN_ManualTrqMaxTime_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_ManualTrqMaxTime_sec() (P_TPLCEN_ManualTrqMaxTime_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ManualTrqMaxTime_sec

#ifndef P_TPLCEN_ManualTrqMax_Nm
#define P_TPLCEN_ManualTrqMax_Nm (LCF_CommonParamData.P_TPLCEN_ManualTrqMax_Nm) //!< LCF parameter macro.
#define GET_P_TPLCEN_ManualTrqMax_Nm() (P_TPLCEN_ManualTrqMax_Nm) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ManualTrqMax_Nm

#ifndef P_TPLCEN_ManualTrqMinTime_sec
#define P_TPLCEN_ManualTrqMinTime_sec (LCF_CommonParamData.P_TPLCEN_ManualTrqMinTime_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_ManualTrqMinTime_sec() (P_TPLCEN_ManualTrqMinTime_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ManualTrqMinTime_sec

#ifndef P_TPLCEN_ManualTrqMin_Nm
#define P_TPLCEN_ManualTrqMin_Nm (LCF_CommonParamData.P_TPLCEN_ManualTrqMin_Nm) //!< LCF parameter macro.
#define GET_P_TPLCEN_ManualTrqMin_Nm() (P_TPLCEN_ManualTrqMin_Nm) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ManualTrqMin_Nm

#ifndef P_TPLCEN_MaxPredictionTime_sec
#define P_TPLCEN_MaxPredictionTime_sec (LCF_CommonParamData.P_TPLCEN_MaxPredictionTime_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_MaxPredictionTime_sec() (P_TPLCEN_MaxPredictionTime_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_MaxPredictionTime_sec

#ifndef P_TPLCEN_PTCrvGradLimitDur_sec
#define P_TPLCEN_PTCrvGradLimitDur_sec (LCF_CommonParamData.P_TPLCEN_PTCrvGradLimitDur_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_PTCrvGradLimitDur_sec() (P_TPLCEN_PTCrvGradLimitDur_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_PTCrvGradLimitDur_sec

#ifndef P_TPLCEN_PTHeadGradLimitDur_sec
#define P_TPLCEN_PTHeadGradLimitDur_sec (LCF_CommonParamData.P_TPLCEN_PTHeadGradLimitDur_sec) //!< LCF parameter macro.
#define GET_P_TPLCEN_PTHeadGradLimitDur_sec() (P_TPLCEN_PTHeadGradLimitDur_sec) //!< LCF parameter macro getter.
#endif // P_TPLCEN_PTHeadGradLimitDur_sec

#ifndef P_TPLCEN_ReIniDeltaDistY_met
#define P_TPLCEN_ReIniDeltaDistY_met (LCF_CommonParamData.P_TPLCEN_ReIniDeltaDistY_met) //!< LCF parameter macro.
#define GET_P_TPLCEN_ReIniDeltaDistY_met() (P_TPLCEN_ReIniDeltaDistY_met) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ReIniDeltaDistY_met

#ifndef P_TPLCEN_ReIniDeltaHead_rad
#define P_TPLCEN_ReIniDeltaHead_rad (LCF_CommonParamData.P_TPLCEN_ReIniDeltaHead_rad) //!< LCF parameter macro.
#define GET_P_TPLCEN_ReIniDeltaHead_rad() (P_TPLCEN_ReIniDeltaHead_rad) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ReIniDeltaHead_rad

#ifndef P_TPLCEN_ReIniWrtDMCReq_nu
#define P_TPLCEN_ReIniWrtDMCReq_nu (LCF_CommonParamData.P_TPLCEN_ReIniWrtDMCReq_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_ReIniWrtDMCReq_nu() (P_TPLCEN_ReIniWrtDMCReq_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ReIniWrtDMCReq_nu

#ifndef P_TPLCEN_ReplanLargeErrorMode_nu
#define P_TPLCEN_ReplanLargeErrorMode_nu (LCF_CommonParamData.P_TPLCEN_ReplanLargeErrorMode_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_ReplanLargeErrorMode_nu() (P_TPLCEN_ReplanLargeErrorMode_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ReplanLargeErrorMode_nu

#ifndef P_TPLCEN_ReplanbyTJA2X_nu
#define P_TPLCEN_ReplanbyTJA2X_nu (LCF_CommonParamData.P_TPLCEN_ReplanbyTJA2X_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_ReplanbyTJA2X_nu() (P_TPLCEN_ReplanbyTJA2X_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_ReplanbyTJA2X_nu

#ifndef P_TPLCEN_TrajPlanEnable_nu
#define P_TPLCEN_TrajPlanEnable_nu (LCF_CommonParamData.P_TPLCEN_TrajPlanEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_TrajPlanEnable_nu() (P_TPLCEN_TrajPlanEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_TrajPlanEnable_nu

#ifndef P_TPLCEN_UseJumpDetectOBFTrig_nu
#define P_TPLCEN_UseJumpDetectOBFTrig_nu (LCF_CommonParamData.P_TPLCEN_UseJumpDetectOBFTrig_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_UseJumpDetectOBFTrig_nu() (P_TPLCEN_UseJumpDetectOBFTrig_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_UseJumpDetectOBFTrig_nu

#ifndef P_TPLCEN_UseJumpDetection_nu
#define P_TPLCEN_UseJumpDetection_nu (LCF_CommonParamData.P_TPLCEN_UseJumpDetection_nu) //!< LCF parameter macro.
#define GET_P_TPLCEN_UseJumpDetection_nu() (P_TPLCEN_UseJumpDetection_nu) //!< LCF parameter macro getter.
#endif // P_TPLCEN_UseJumpDetection_nu

#ifndef P_TPLCEN_VMinTimeBasedTraj_kph
#define P_TPLCEN_VMinTimeBasedTraj_kph (LCF_CommonParamData.P_TPLCEN_VMinTimeBasedTraj_kph) //!< LCF parameter macro.
#define GET_P_TPLCEN_VMinTimeBasedTraj_kph() (P_TPLCEN_VMinTimeBasedTraj_kph) //!< LCF parameter macro getter.
#endif // P_TPLCEN_VMinTimeBasedTraj_kph

#ifndef P_TPLFBT_CheckTrajPlanStatus_nu
#define P_TPLFBT_CheckTrajPlanStatus_nu (LCF_CommonParamData.P_TPLFBT_CheckTrajPlanStatus_nu) //!< LCF parameter macro.
#define GET_P_TPLFBT_CheckTrajPlanStatus_nu() (P_TPLFBT_CheckTrajPlanStatus_nu) //!< LCF parameter macro getter.
#endif // P_TPLFBT_CheckTrajPlanStatus_nu

#ifndef P_TPLFBT_CrvPredictionEnbl_nu
#define P_TPLFBT_CrvPredictionEnbl_nu (LCF_CommonParamData.P_TPLFBT_CrvPredictionEnbl_nu) //!< LCF parameter macro.
#define GET_P_TPLFBT_CrvPredictionEnbl_nu() (P_TPLFBT_CrvPredictionEnbl_nu) //!< LCF parameter macro getter.
#endif // P_TPLFBT_CrvPredictionEnbl_nu

#ifndef P_TPLFBT_DeltaTargetCrv_1pm
#define P_TPLFBT_DeltaTargetCrv_1pm (LCF_CommonParamData.P_TPLFBT_DeltaTargetCrv_1pm) //!< LCF parameter macro.
#define GET_P_TPLFBT_DeltaTargetCrv_1pm() (P_TPLFBT_DeltaTargetCrv_1pm) //!< LCF parameter macro getter.
#endif // P_TPLFBT_DeltaTargetCrv_1pm

#ifndef P_TPLFBT_DeltaTargetHeading_rad
#define P_TPLFBT_DeltaTargetHeading_rad (LCF_CommonParamData.P_TPLFBT_DeltaTargetHeading_rad) //!< LCF parameter macro.
#define GET_P_TPLFBT_DeltaTargetHeading_rad() (P_TPLFBT_DeltaTargetHeading_rad) //!< LCF parameter macro getter.
#endif // P_TPLFBT_DeltaTargetHeading_rad

#ifndef P_TPLFBT_DeltaTargetPosY0_met
#define P_TPLFBT_DeltaTargetPosY0_met (LCF_CommonParamData.P_TPLFBT_DeltaTargetPosY0_met) //!< LCF parameter macro.
#define GET_P_TPLFBT_DeltaTargetPosY0_met() (P_TPLFBT_DeltaTargetPosY0_met) //!< LCF parameter macro getter.
#endif // P_TPLFBT_DeltaTargetPosY0_met

#ifndef P_TPLFBT_DurationGradLimit_sec
#define P_TPLFBT_DurationGradLimit_sec (LCF_CommonParamData.P_TPLFBT_DurationGradLimit_sec) //!< LCF parameter macro.
#define GET_P_TPLFBT_DurationGradLimit_sec() (P_TPLFBT_DurationGradLimit_sec) //!< LCF parameter macro getter.
#endif // P_TPLFBT_DurationGradLimit_sec

#ifndef P_TPLFBT_GradLimitCrv_1pm2
#define P_TPLFBT_GradLimitCrv_1pm2 (LCF_CommonParamData.P_TPLFBT_GradLimitCrv_1pm2) //!< LCF parameter macro.
#define GET_P_TPLFBT_GradLimitCrv_1pm2() (P_TPLFBT_GradLimitCrv_1pm2) //!< LCF parameter macro getter.
#endif // P_TPLFBT_GradLimitCrv_1pm2

#ifndef P_TPLFBT_GradLimitHeadHigh_rps
#define P_TPLFBT_GradLimitHeadHigh_rps (LCF_CommonParamData.P_TPLFBT_GradLimitHeadHigh_rps) //!< LCF parameter macro.
#define GET_P_TPLFBT_GradLimitHeadHigh_rps() (P_TPLFBT_GradLimitHeadHigh_rps) //!< LCF parameter macro getter.
#endif // P_TPLFBT_GradLimitHeadHigh_rps

#ifndef P_TPLFBT_GradLimitHead_rps
#define P_TPLFBT_GradLimitHead_rps (LCF_CommonParamData.P_TPLFBT_GradLimitHead_rps) //!< LCF parameter macro.
#define GET_P_TPLFBT_GradLimitHead_rps() (P_TPLFBT_GradLimitHead_rps) //!< LCF parameter macro getter.
#endif // P_TPLFBT_GradLimitHead_rps

#ifndef P_TPLFBT_GradLimitPosYHigh_mps
#define P_TPLFBT_GradLimitPosYHigh_mps (LCF_CommonParamData.P_TPLFBT_GradLimitPosYHigh_mps) //!< LCF parameter macro.
#define GET_P_TPLFBT_GradLimitPosYHigh_mps() (P_TPLFBT_GradLimitPosYHigh_mps) //!< LCF parameter macro getter.
#endif // P_TPLFBT_GradLimitPosYHigh_mps

#ifndef P_TPLFBT_GradLimitPosY_mps
#define P_TPLFBT_GradLimitPosY_mps (LCF_CommonParamData.P_TPLFBT_GradLimitPosY_mps) //!< LCF parameter macro.
#define GET_P_TPLFBT_GradLimitPosY_mps() (P_TPLFBT_GradLimitPosY_mps) //!< LCF parameter macro getter.
#endif // P_TPLFBT_GradLimitPosY_mps

#ifndef P_TPLFBT_HeadCheckTolOBF_rad
#define P_TPLFBT_HeadCheckTolOBF_rad (LCF_CommonParamData.P_TPLFBT_HeadCheckTolOBF_rad) //!< LCF parameter macro.
#define GET_P_TPLFBT_HeadCheckTolOBF_rad() (P_TPLFBT_HeadCheckTolOBF_rad) //!< LCF parameter macro getter.
#endif // P_TPLFBT_HeadCheckTolOBF_rad

#ifndef P_TPLFBT_HeadCheckTolerance_rad
#define P_TPLFBT_HeadCheckTolerance_rad (LCF_CommonParamData.P_TPLFBT_HeadCheckTolerance_rad) //!< LCF parameter macro.
#define GET_P_TPLFBT_HeadCheckTolerance_rad() (P_TPLFBT_HeadCheckTolerance_rad) //!< LCF parameter macro getter.
#endif // P_TPLFBT_HeadCheckTolerance_rad

#ifndef P_TPLFBT_HoldAllBits_nu
#define P_TPLFBT_HoldAllBits_nu (LCF_CommonParamData.P_TPLFBT_HoldAllBits_nu) //!< LCF parameter macro.
#define GET_P_TPLFBT_HoldAllBits_nu() (P_TPLFBT_HoldAllBits_nu) //!< LCF parameter macro getter.
#endif // P_TPLFBT_HoldAllBits_nu

#ifndef P_TPLFBT_MaxQuStatusHold_sec
#define P_TPLFBT_MaxQuStatusHold_sec (LCF_CommonParamData.P_TPLFBT_MaxQuStatusHold_sec) //!< LCF parameter macro.
#define GET_P_TPLFBT_MaxQuStatusHold_sec() (P_TPLFBT_MaxQuStatusHold_sec) //!< LCF parameter macro getter.
#endif // P_TPLFBT_MaxQuStatusHold_sec

#ifndef P_TPLFBT_MinQuStatusHold_sec
#define P_TPLFBT_MinQuStatusHold_sec (LCF_CommonParamData.P_TPLFBT_MinQuStatusHold_sec) //!< LCF parameter macro.
#define GET_P_TPLFBT_MinQuStatusHold_sec() (P_TPLFBT_MinQuStatusHold_sec) //!< LCF parameter macro getter.
#endif // P_TPLFBT_MinQuStatusHold_sec

#ifndef P_TPLFBT_QuStatusHold_nu
#define P_TPLFBT_QuStatusHold_nu (LCF_CommonParamData.P_TPLFBT_QuStatusHold_nu) //!< LCF parameter macro.
#define GET_P_TPLFBT_QuStatusHold_nu() (P_TPLFBT_QuStatusHold_nu) //!< LCF parameter macro getter.
#endif // P_TPLFBT_QuStatusHold_nu

#ifndef P_TPLFBT_UseLongQuStatus_nu
#define P_TPLFBT_UseLongQuStatus_nu (LCF_CommonParamData.P_TPLFBT_UseLongQuStatus_nu) //!< LCF parameter macro.
#define GET_P_TPLFBT_UseLongQuStatus_nu() (P_TPLFBT_UseLongQuStatus_nu) //!< LCF parameter macro getter.
#endif // P_TPLFBT_UseLongQuStatus_nu

#ifndef P_TPLFBT_UseTgtCridrHeading_nu
#define P_TPLFBT_UseTgtCridrHeading_nu (LCF_CommonParamData.P_TPLFBT_UseTgtCridrHeading_nu) //!< LCF parameter macro.
#define GET_P_TPLFBT_UseTgtCridrHeading_nu() (P_TPLFBT_UseTgtCridrHeading_nu) //!< LCF parameter macro getter.
#endif // P_TPLFBT_UseTgtCridrHeading_nu

#ifndef P_TPLFRT_CalcLeftCridrEnable_nu
#define P_TPLFRT_CalcLeftCridrEnable_nu (LCF_CommonParamData.P_TPLFRT_CalcLeftCridrEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLFRT_CalcLeftCridrEnable_nu() (P_TPLFRT_CalcLeftCridrEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLFRT_CalcLeftCridrEnable_nu

#ifndef P_TPLFRT_CridrSwitchDetection_nu
#define P_TPLFRT_CridrSwitchDetection_nu (LCF_CommonParamData.P_TPLFRT_CridrSwitchDetection_nu) //!< LCF parameter macro.
#define GET_P_TPLFRT_CridrSwitchDetection_nu() (P_TPLFRT_CridrSwitchDetection_nu) //!< LCF parameter macro getter.
#endif // P_TPLFRT_CridrSwitchDetection_nu

#ifndef P_TPLFRT_PlnHrznMinBarrier_sec
#define P_TPLFRT_PlnHrznMinBarrier_sec (LCF_CommonParamData.P_TPLFRT_PlnHrznMinBarrier_sec) //!< LCF parameter macro.
#define GET_P_TPLFRT_PlnHrznMinBarrier_sec() (P_TPLFRT_PlnHrznMinBarrier_sec) //!< LCF parameter macro getter.
#endif // P_TPLFRT_PlnHrznMinBarrier_sec

#ifndef P_TPLFRT_TgtPointMin_sec
#define P_TPLFRT_TgtPointMin_sec (LCF_CommonParamData.P_TPLFRT_TgtPointMin_sec) //!< LCF parameter macro.
#define GET_P_TPLFRT_TgtPointMin_sec() (P_TPLFRT_TgtPointMin_sec) //!< LCF parameter macro getter.
#endif // P_TPLFRT_TgtPointMin_sec

#ifndef P_TPLFRT_UseDMCSumCrv_nu
#define P_TPLFRT_UseDMCSumCrv_nu (LCF_CommonParamData.P_TPLFRT_UseDMCSumCrv_nu) //!< LCF parameter macro.
#define GET_P_TPLFRT_UseDMCSumCrv_nu() (P_TPLFRT_UseDMCSumCrv_nu) //!< LCF parameter macro getter.
#endif // P_TPLFRT_UseDMCSumCrv_nu

#ifndef P_TPLFRT_UseTgtTrajX0_nu
#define P_TPLFRT_UseTgtTrajX0_nu (LCF_CommonParamData.P_TPLFRT_UseTgtTrajX0_nu) //!< LCF parameter macro.
#define GET_P_TPLFRT_UseTgtTrajX0_nu() (P_TPLFRT_UseTgtTrajX0_nu) //!< LCF parameter macro getter.
#endif // P_TPLFRT_UseTgtTrajX0_nu

#ifndef P_TPLLCO_CCCAllowOverwrite_nu
#define P_TPLLCO_CCCAllowOverwrite_nu (LCF_CommonParamData.P_TPLLCO_CCCAllowOverwrite_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCAllowOverwrite_nu() (P_TPLLCO_CCCAllowOverwrite_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCAllowOverwrite_nu

#ifndef P_TPLLCO_CCCEnableInCurve_nu
#define P_TPLLCO_CCCEnableInCurve_nu (LCF_CommonParamData.P_TPLLCO_CCCEnableInCurve_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCEnableInCurve_nu() (P_TPLLCO_CCCEnableInCurve_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCEnableInCurve_nu

#ifndef P_TPLLCO_CCCEnable_nu
#define P_TPLLCO_CCCEnable_nu (LCF_CommonParamData.P_TPLLCO_CCCEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCEnable_nu() (P_TPLLCO_CCCEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCEnable_nu

#ifndef P_TPLLCO_CCCMaxCurvature_1pm
#define P_TPLLCO_CCCMaxCurvature_1pm (LCF_CommonParamData.P_TPLLCO_CCCMaxCurvature_1pm) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCMaxCurvature_1pm() (P_TPLLCO_CCCMaxCurvature_1pm) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCMaxCurvature_1pm

#ifndef P_TPLLCO_CCCMinCrvQuality_Perc
#define P_TPLLCO_CCCMinCrvQuality_Perc (LCF_CommonParamData.P_TPLLCO_CCCMinCrvQuality_Perc) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCMinCrvQuality_Perc() (P_TPLLCO_CCCMinCrvQuality_Perc) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCMinCrvQuality_Perc

#ifndef P_TPLLCO_CCCMinLnQuality_Perc
#define P_TPLLCO_CCCMinLnQuality_Perc (LCF_CommonParamData.P_TPLLCO_CCCMinLnQuality_Perc) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCMinLnQuality_Perc() (P_TPLLCO_CCCMinLnQuality_Perc) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCMinLnQuality_Perc

#ifndef P_TPLLCO_CCCMinQuCycle_nu
#define P_TPLLCO_CCCMinQuCycle_nu (LCF_CommonParamData.P_TPLLCO_CCCMinQuCycle_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCMinQuCycle_nu() (P_TPLLCO_CCCMinQuCycle_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCMinQuCycle_nu

#ifndef P_TPLLCO_CCCMinTestDistX_met
#define P_TPLLCO_CCCMinTestDistX_met (LCF_CommonParamData.P_TPLLCO_CCCMinTestDistX_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCMinTestDistX_met() (P_TPLLCO_CCCMinTestDistX_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCMinTestDistX_met

#ifndef P_TPLLCO_CCCMinValidLength_met
#define P_TPLLCO_CCCMinValidLength_met (LCF_CommonParamData.P_TPLLCO_CCCMinValidLength_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCMinValidLength_met() (P_TPLLCO_CCCMinValidLength_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCMinValidLength_met

#ifndef P_TPLLCO_CCCResetMaxDistX_met
#define P_TPLLCO_CCCResetMaxDistX_met (LCF_CommonParamData.P_TPLLCO_CCCResetMaxDistX_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCResetMaxDistX_met() (P_TPLLCO_CCCResetMaxDistX_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCResetMaxDistX_met

#ifndef P_TPLLCO_CCCResetMaxPerc_nu
#define P_TPLLCO_CCCResetMaxPerc_nu (LCF_CommonParamData.P_TPLLCO_CCCResetMaxPerc_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCResetMaxPerc_nu() (P_TPLLCO_CCCResetMaxPerc_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCResetMaxPerc_nu

#ifndef P_TPLLCO_CCCTestDisXPerc_nu
#define P_TPLLCO_CCCTestDisXPerc_nu (LCF_CommonParamData.P_TPLLCO_CCCTestDisXPerc_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCTestDisXPerc_nu() (P_TPLLCO_CCCTestDisXPerc_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCTestDisXPerc_nu

#ifndef P_TPLLCO_CCCThresholdMaxDev_met
#define P_TPLLCO_CCCThresholdMaxDev_met (LCF_CommonParamData.P_TPLLCO_CCCThresholdMaxDev_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCThresholdMaxDev_met() (P_TPLLCO_CCCThresholdMaxDev_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCThresholdMaxDev_met

#ifndef P_TPLLCO_CCCValidMaxPerc_nu
#define P_TPLLCO_CCCValidMaxPerc_nu (LCF_CommonParamData.P_TPLLCO_CCCValidMaxPerc_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CCCValidMaxPerc_nu() (P_TPLLCO_CCCValidMaxPerc_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CCCValidMaxPerc_nu

#ifndef P_TPLLCO_CalculationbyRampout_nu
#define P_TPLLCO_CalculationbyRampout_nu (LCF_CommonParamData.P_TPLLCO_CalculationbyRampout_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CalculationbyRampout_nu() (P_TPLLCO_CalculationbyRampout_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CalculationbyRampout_nu

#ifndef P_TPLLCO_CalculationbyRequest_nu
#define P_TPLLCO_CalculationbyRequest_nu (LCF_CommonParamData.P_TPLLCO_CalculationbyRequest_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_CalculationbyRequest_nu() (P_TPLLCO_CalculationbyRequest_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CalculationbyRequest_nu

#ifndef P_TPLLCO_CoordTrafoMinLength_met
#define P_TPLLCO_CoordTrafoMinLength_met (LCF_CommonParamData.P_TPLLCO_CoordTrafoMinLength_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_CoordTrafoMinLength_met() (P_TPLLCO_CoordTrafoMinLength_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CoordTrafoMinLength_met

#ifndef P_TPLLCO_CrvCheckTolerance_met
#define P_TPLLCO_CrvCheckTolerance_met (LCF_CommonParamData.P_TPLLCO_CrvCheckTolerance_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_CrvCheckTolerance_met() (P_TPLLCO_CrvCheckTolerance_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_CrvCheckTolerance_met

#ifndef P_TPLLCO_DistYCheckTolerance_met
#define P_TPLLCO_DistYCheckTolerance_met (LCF_CommonParamData.P_TPLLCO_DistYCheckTolerance_met) //!< LCF parameter macro.
#define GET_P_TPLLCO_DistYCheckTolerance_met() (P_TPLLCO_DistYCheckTolerance_met) //!< LCF parameter macro getter.
#endif // P_TPLLCO_DistYCheckTolerance_met

#ifndef P_TPLLCO_NumIter_nu
#define P_TPLLCO_NumIter_nu (LCF_CommonParamData.P_TPLLCO_NumIter_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_NumIter_nu() (P_TPLLCO_NumIter_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_NumIter_nu

#ifndef P_TPLLCO_OdoMaxTime_us
#define P_TPLLCO_OdoMaxTime_us (LCF_CommonParamData.P_TPLLCO_OdoMaxTime_us) //!< LCF parameter macro.
#define GET_P_TPLLCO_OdoMaxTime_us() (P_TPLLCO_OdoMaxTime_us) //!< LCF parameter macro getter.
#endif // P_TPLLCO_OdoMaxTime_us

#ifndef P_TPLLCO_PreviewDistXEnable_nu
#define P_TPLLCO_PreviewDistXEnable_nu (LCF_CommonParamData.P_TPLLCO_PreviewDistXEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_PreviewDistXEnable_nu() (P_TPLLCO_PreviewDistXEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_PreviewDistXEnable_nu

#ifndef P_TPLLCO_ReplanDevEnable_nu
#define P_TPLLCO_ReplanDevEnable_nu (LCF_CommonParamData.P_TPLLCO_ReplanDevEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_ReplanDevEnable_nu() (P_TPLLCO_ReplanDevEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_ReplanDevEnable_nu

#ifndef P_TPLLCO_SupressDoubleTrigRpl_nu
#define P_TPLLCO_SupressDoubleTrigRpl_nu (LCF_CommonParamData.P_TPLLCO_SupressDoubleTrigRpl_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_SupressDoubleTrigRpl_nu() (P_TPLLCO_SupressDoubleTrigRpl_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_SupressDoubleTrigRpl_nu

#ifndef P_TPLLCO_TimeDiffSwitch_nu
#define P_TPLLCO_TimeDiffSwitch_nu (LCF_CommonParamData.P_TPLLCO_TimeDiffSwitch_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_TimeDiffSwitch_nu() (P_TPLLCO_TimeDiffSwitch_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_TimeDiffSwitch_nu

#ifndef P_TPLLCO_TimeDiff_sec
#define P_TPLLCO_TimeDiff_sec (LCF_CommonParamData.P_TPLLCO_TimeDiff_sec) //!< LCF parameter macro.
#define GET_P_TPLLCO_TimeDiff_sec() (P_TPLLCO_TimeDiff_sec) //!< LCF parameter macro getter.
#endif // P_TPLLCO_TimeDiff_sec

#ifndef P_TPLLCO_UseEgoPredict_nu
#define P_TPLLCO_UseEgoPredict_nu (LCF_CommonParamData.P_TPLLCO_UseEgoPredict_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_UseEgoPredict_nu() (P_TPLLCO_UseEgoPredict_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_UseEgoPredict_nu

#ifndef P_TPLLCO_UseOdoReplan_nu
#define P_TPLLCO_UseOdoReplan_nu (LCF_CommonParamData.P_TPLLCO_UseOdoReplan_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_UseOdoReplan_nu() (P_TPLLCO_UseOdoReplan_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_UseOdoReplan_nu

#ifndef P_TPLLCO_UseSensorTStamp_nu
#define P_TPLLCO_UseSensorTStamp_nu (LCF_CommonParamData.P_TPLLCO_UseSensorTStamp_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_UseSensorTStamp_nu() (P_TPLLCO_UseSensorTStamp_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_UseSensorTStamp_nu

#ifndef P_TPLLCO_VehCrvPT1Enable_nu
#define P_TPLLCO_VehCrvPT1Enable_nu (LCF_CommonParamData.P_TPLLCO_VehCrvPT1Enable_nu) //!< LCF parameter macro.
#define GET_P_TPLLCO_VehCrvPT1Enable_nu() (P_TPLLCO_VehCrvPT1Enable_nu) //!< LCF parameter macro getter.
#endif // P_TPLLCO_VehCrvPT1Enable_nu

#ifndef P_TPLLCO_VehCrvPT1TimeConst_sec
#define P_TPLLCO_VehCrvPT1TimeConst_sec (LCF_CommonParamData.P_TPLLCO_VehCrvPT1TimeConst_sec) //!< LCF parameter macro.
#define GET_P_TPLLCO_VehCrvPT1TimeConst_sec() (P_TPLLCO_VehCrvPT1TimeConst_sec) //!< LCF parameter macro getter.
#endif // P_TPLLCO_VehCrvPT1TimeConst_sec

#ifndef P_TPLTJC_AllowedTimetoCross_sec
#define P_TPLTJC_AllowedTimetoCross_sec (LCF_CommonParamData.P_TPLTJC_AllowedTimetoCross_sec) //!< LCF parameter macro.
#define GET_P_TPLTJC_AllowedTimetoCross_sec() (P_TPLTJC_AllowedTimetoCross_sec) //!< LCF parameter macro getter.
#endif // P_TPLTJC_AllowedTimetoCross_sec

#ifndef P_TPLTJC_FTireAclMinScaling_nu
#define P_TPLTJC_FTireAclMinScaling_nu (LCF_CommonParamData.P_TPLTJC_FTireAclMinScaling_nu) //!< LCF parameter macro.
#define GET_P_TPLTJC_FTireAclMinScaling_nu() (P_TPLTJC_FTireAclMinScaling_nu) //!< LCF parameter macro getter.
#endif // P_TPLTJC_FTireAclMinScaling_nu

#ifndef P_TPLTJC_MaxArcLength_met
#define P_TPLTJC_MaxArcLength_met (LCF_CommonParamData.P_TPLTJC_MaxArcLength_met) //!< LCF parameter macro.
#define GET_P_TPLTJC_MaxArcLength_met() (P_TPLTJC_MaxArcLength_met) //!< LCF parameter macro getter.
#endif // P_TPLTJC_MaxArcLength_met

#ifndef P_TPLTJC_NumCircles_nu
#define P_TPLTJC_NumCircles_nu (LCF_CommonParamData.P_TPLTJC_NumCircles_nu) //!< LCF parameter macro.
#define GET_P_TPLTJC_NumCircles_nu() (P_TPLTJC_NumCircles_nu) //!< LCF parameter macro getter.
#endif // P_TPLTJC_NumCircles_nu

#ifndef P_TPLTJC_ParamCostFctInternal_nu
#define P_TPLTJC_ParamCostFctInternal_nu (LCF_CommonParamData.P_TPLTJC_ParamCostFctInternal_nu) //!< LCF parameter macro.
#define GET_P_TPLTJC_ParamCostFctInternal_nu() (P_TPLTJC_ParamCostFctInternal_nu) //!< LCF parameter macro getter.
#endif // P_TPLTJC_ParamCostFctInternal_nu

#ifndef P_TPLTJC_TMax_sec
#define P_TPLTJC_TMax_sec (LCF_CommonParamData.P_TPLTJC_TMax_sec) //!< LCF parameter macro.
#define GET_P_TPLTJC_TMax_sec() (P_TPLTJC_TMax_sec) //!< LCF parameter macro getter.
#endif // P_TPLTJC_TMax_sec

#ifndef P_TPLTJC_TimeTrajEndEnable_nu
#define P_TPLTJC_TimeTrajEndEnable_nu (LCF_CommonParamData.P_TPLTJC_TimeTrajEndEnable_nu) //!< LCF parameter macro.
#define GET_P_TPLTJC_TimeTrajEndEnable_nu() (P_TPLTJC_TimeTrajEndEnable_nu) //!< LCF parameter macro getter.
#endif // P_TPLTJC_TimeTrajEndEnable_nu

#ifndef P_TPLTJC_WeightDistBased_nu
#define P_TPLTJC_WeightDistBased_nu (LCF_CommonParamData.P_TPLTJC_WeightDistBased_nu) //!< LCF parameter macro.
#define GET_P_TPLTJC_WeightDistBased_nu() (P_TPLTJC_WeightDistBased_nu) //!< LCF parameter macro getter.
#endif // P_TPLTJC_WeightDistBased_nu

#ifndef P_TPLTJC_WeightTgtDistY_nu
#define P_TPLTJC_WeightTgtDistY_nu (LCF_CommonParamData.P_TPLTJC_WeightTgtDistY_nu) //!< LCF parameter macro.
#define GET_P_TPLTJC_WeightTgtDistY_nu() (P_TPLTJC_WeightTgtDistY_nu) //!< LCF parameter macro getter.
#endif // P_TPLTJC_WeightTgtDistY_nu

#ifndef P_VDPDRV_DebTimeAccPedRate_sec
#define P_VDPDRV_DebTimeAccPedRate_sec (LCF_CommonParamData.P_VDPDRV_DebTimeAccPedRate_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_DebTimeAccPedRate_sec() (P_VDPDRV_DebTimeAccPedRate_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_DebTimeAccPedRate_sec

#ifndef P_VDPDRV_DebTimeActStCtrl_sec
#define P_VDPDRV_DebTimeActStCtrl_sec (LCF_CommonParamData.P_VDPDRV_DebTimeActStCtrl_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_DebTimeActStCtrl_sec() (P_VDPDRV_DebTimeActStCtrl_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_DebTimeActStCtrl_sec

#ifndef P_VDPDRV_DebTimeTurnSignal_sec
#define P_VDPDRV_DebTimeTurnSignal_sec (LCF_CommonParamData.P_VDPDRV_DebTimeTurnSignal_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_DebTimeTurnSignal_sec() (P_VDPDRV_DebTimeTurnSignal_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_DebTimeTurnSignal_sec

#ifndef P_VDPDRV_DebugWiperStateActive_bool
#define P_VDPDRV_DebugWiperStateActive_bool (LCF_CommonParamData.P_VDPDRV_DebugWiperStateActive_bool) //!< LCF parameter macro.
#define GET_P_VDPDRV_DebugWiperStateActive_bool() (P_VDPDRV_DebugWiperStateActive_bool) //!< LCF parameter macro getter.
#endif // P_VDPDRV_DebugWiperStateActive_bool

#ifndef P_VDPDRV_HoldTimeErrorSt_sec
#define P_VDPDRV_HoldTimeErrorSt_sec (LCF_CommonParamData.P_VDPDRV_HoldTimeErrorSt_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_HoldTimeErrorSt_sec() (P_VDPDRV_HoldTimeErrorSt_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_HoldTimeErrorSt_sec

#ifndef P_VDPDRV_ManTrqOvrrdMaxTrq_Nm
#define P_VDPDRV_ManTrqOvrrdMaxTrq_Nm (LCF_CommonParamData.P_VDPDRV_ManTrqOvrrdMaxTrq_Nm) //!< LCF parameter macro.
#define GET_P_VDPDRV_ManTrqOvrrdMaxTrq_Nm() (P_VDPDRV_ManTrqOvrrdMaxTrq_Nm) //!< LCF parameter macro getter.
#endif // P_VDPDRV_ManTrqOvrrdMaxTrq_Nm

#ifndef P_VDPDRV_ManTrqOvrrdTrnOnTm_sec
#define P_VDPDRV_ManTrqOvrrdTrnOnTm_sec (LCF_CommonParamData.P_VDPDRV_ManTrqOvrrdTrnOnTm_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_ManTrqOvrrdTrnOnTm_sec() (P_VDPDRV_ManTrqOvrrdTrnOnTm_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_ManTrqOvrrdTrnOnTm_sec

#ifndef P_VDPDRV_MaxAccelPedalRate_nu
#define P_VDPDRV_MaxAccelPedalRate_nu (LCF_CommonParamData.P_VDPDRV_MaxAccelPedalRate_nu) //!< LCF parameter macro.
#define GET_P_VDPDRV_MaxAccelPedalRate_nu() (P_VDPDRV_MaxAccelPedalRate_nu) //!< LCF parameter macro getter.
#endif // P_VDPDRV_MaxAccelPedalRate_nu

#ifndef P_VDPDRV_MaxVelLimStrngStp_mps
#define P_VDPDRV_MaxVelLimStrngStp_mps (LCF_CommonParamData.P_VDPDRV_MaxVelLimStrngStp_mps) //!< LCF parameter macro.
#define GET_P_VDPDRV_MaxVelLimStrngStp_mps() (P_VDPDRV_MaxVelLimStrngStp_mps) //!< LCF parameter macro getter.
#endif // P_VDPDRV_MaxVelLimStrngStp_mps

#ifndef P_VDPDRV_NoDaytBrightState_btm
#define P_VDPDRV_NoDaytBrightState_btm (LCF_CommonParamData.P_VDPDRV_NoDaytBrightState_btm) //!< LCF parameter macro.
#define GET_P_VDPDRV_NoDaytBrightState_btm() (P_VDPDRV_NoDaytBrightState_btm) //!< LCF parameter macro getter.
#endif // P_VDPDRV_NoDaytBrightState_btm

#ifndef P_VDPDRV_NoDaytCndTimeMin_sec
#define P_VDPDRV_NoDaytCndTimeMin_sec (LCF_CommonParamData.P_VDPDRV_NoDaytCndTimeMin_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_NoDaytCndTimeMin_sec() (P_VDPDRV_NoDaytCndTimeMin_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_NoDaytCndTimeMin_sec

#ifndef P_VDPDRV_NoDaytCndTrnOff_sec
#define P_VDPDRV_NoDaytCndTrnOff_sec (LCF_CommonParamData.P_VDPDRV_NoDaytCndTrnOff_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_NoDaytCndTrnOff_sec() (P_VDPDRV_NoDaytCndTrnOff_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_NoDaytCndTrnOff_sec

#ifndef P_VDPDRV_ThStrngStpDtctd_rad
#define P_VDPDRV_ThStrngStpDtctd_rad (LCF_CommonParamData.P_VDPDRV_ThStrngStpDtctd_rad) //!< LCF parameter macro.
#define GET_P_VDPDRV_ThStrngStpDtctd_rad() (P_VDPDRV_ThStrngStpDtctd_rad) //!< LCF parameter macro getter.
#endif // P_VDPDRV_ThStrngStpDtctd_rad

#ifndef P_VDPDRV_ThStrngStpNotDtctd_rad
#define P_VDPDRV_ThStrngStpNotDtctd_rad (LCF_CommonParamData.P_VDPDRV_ThStrngStpNotDtctd_rad) //!< LCF parameter macro.
#define GET_P_VDPDRV_ThStrngStpNotDtctd_rad() (P_VDPDRV_ThStrngStpNotDtctd_rad) //!< LCF parameter macro getter.
#endif // P_VDPDRV_ThStrngStpNotDtctd_rad

#ifndef P_VDPDRV_TurnOffTimeErrorSt_sec
#define P_VDPDRV_TurnOffTimeErrorSt_sec (LCF_CommonParamData.P_VDPDRV_TurnOffTimeErrorSt_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_TurnOffTimeErrorSt_sec() (P_VDPDRV_TurnOffTimeErrorSt_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_TurnOffTimeErrorSt_sec

#ifndef P_VDPDRV_TurnOnTimeErrorSt_sec
#define P_VDPDRV_TurnOnTimeErrorSt_sec (LCF_CommonParamData.P_VDPDRV_TurnOnTimeErrorSt_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_TurnOnTimeErrorSt_sec() (P_VDPDRV_TurnOnTimeErrorSt_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_TurnOnTimeErrorSt_sec

#ifndef P_VDPDRV_WiperActiveTimeMin_sec
#define P_VDPDRV_WiperActiveTimeMin_sec (LCF_CommonParamData.P_VDPDRV_WiperActiveTimeMin_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_WiperActiveTimeMin_sec() (P_VDPDRV_WiperActiveTimeMin_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_WiperActiveTimeMin_sec

#ifndef P_VDPDRV_WiperEventsGapTimeMax_sec
#define P_VDPDRV_WiperEventsGapTimeMax_sec (LCF_CommonParamData.P_VDPDRV_WiperEventsGapTimeMax_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_WiperEventsGapTimeMax_sec() (P_VDPDRV_WiperEventsGapTimeMax_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_WiperEventsGapTimeMax_sec

#ifndef P_VDPDRV_WiperMinContinTime_sec
#define P_VDPDRV_WiperMinContinTime_sec (LCF_CommonParamData.P_VDPDRV_WiperMinContinTime_sec) //!< LCF parameter macro.
#define GET_P_VDPDRV_WiperMinContinTime_sec() (P_VDPDRV_WiperMinContinTime_sec) //!< LCF parameter macro getter.
#endif // P_VDPDRV_WiperMinContinTime_sec

#ifndef P_VDPDRV_WiperStageActive_btm
#define P_VDPDRV_WiperStageActive_btm (LCF_CommonParamData.P_VDPDRV_WiperStageActive_btm) //!< LCF parameter macro.
#define GET_P_VDPDRV_WiperStageActive_btm() (P_VDPDRV_WiperStageActive_btm) //!< LCF parameter macro getter.
#endif // P_VDPDRV_WiperStageActive_btm

#ifndef P_VEH_CenterOfPressure_met
#define P_VEH_CenterOfPressure_met (LCF_CommonParamData.P_VEH_CenterOfPressure_met) //!< LCF parameter macro.
#define GET_P_VEH_CenterOfPressure_met() (P_VEH_CenterOfPressure_met) //!< LCF parameter macro getter.
#endif // P_VEH_CenterOfPressure_met

#ifndef P_VEH_CorStiffFrontAxle_Npr
#define P_VEH_CorStiffFrontAxle_Npr (LCF_CommonParamData.P_VEH_CorStiffFrontAxle_Npr) //!< LCF parameter macro.
#define GET_P_VEH_CorStiffFrontAxle_Npr() (P_VEH_CorStiffFrontAxle_Npr) //!< LCF parameter macro getter.
#endif // P_VEH_CorStiffFrontAxle_Npr

#ifndef P_VEH_CorStiffRearAxle_Npr
#define P_VEH_CorStiffRearAxle_Npr (LCF_CommonParamData.P_VEH_CorStiffRearAxle_Npr) //!< LCF parameter macro.
#define GET_P_VEH_CorStiffRearAxle_Npr() (P_VEH_CorStiffRearAxle_Npr) //!< LCF parameter macro getter.
#endif // P_VEH_CorStiffRearAxle_Npr

#ifndef P_VEH_DistCogToFrontAxle_m
#define P_VEH_DistCogToFrontAxle_m (LCF_CommonParamData.P_VEH_DistCogToFrontAxle_m) //!< LCF parameter macro.
#define GET_P_VEH_DistCogToFrontAxle_m() (P_VEH_DistCogToFrontAxle_m) //!< LCF parameter macro getter.
#endif // P_VEH_DistCogToFrontAxle_m

#ifndef P_VEH_DistCogToRearAxle_m
#define P_VEH_DistCogToRearAxle_m (LCF_CommonParamData.P_VEH_DistCogToRearAxle_m) //!< LCF parameter macro.
#define GET_P_VEH_DistCogToRearAxle_m() (P_VEH_DistCogToRearAxle_m) //!< LCF parameter macro getter.
#endif // P_VEH_DistCogToRearAxle_m

#ifndef P_VEH_Inertia_kgm2
#define P_VEH_Inertia_kgm2 (LCF_CommonParamData.P_VEH_Inertia_kgm2) //!< LCF parameter macro.
#define GET_P_VEH_Inertia_kgm2() (P_VEH_Inertia_kgm2) //!< LCF parameter macro getter.
#endif // P_VEH_Inertia_kgm2

#ifndef P_VEH_Mass_kg
#define P_VEH_Mass_kg (LCF_CommonParamData.P_VEH_Mass_kg) //!< LCF parameter macro.
#define GET_P_VEH_Mass_kg() (P_VEH_Mass_kg) //!< LCF parameter macro getter.
#endif // P_VEH_Mass_kg

#ifndef P_VEH_OverhangFront_met
#define P_VEH_OverhangFront_met (LCF_CommonParamData.P_VEH_OverhangFront_met) //!< LCF parameter macro.
#define GET_P_VEH_OverhangFront_met() (P_VEH_OverhangFront_met) //!< LCF parameter macro getter.
#endif // P_VEH_OverhangFront_met

#ifndef P_VEH_SelfSteeringGrd_nu
#define P_VEH_SelfSteeringGrd_nu (LCF_CommonParamData.P_VEH_SelfSteeringGrd_nu) //!< LCF parameter macro.
#define GET_P_VEH_SelfSteeringGrd_nu() (P_VEH_SelfSteeringGrd_nu) //!< LCF parameter macro getter.
#endif // P_VEH_SelfSteeringGrd_nu

#ifndef P_DPLSIA_LDPSpecificDebTime_sec
#define P_DPLSIA_LDPSpecificDebTime_sec(i) (LCF_CommonParamData.P_DPLSIA_LDPSpecificDebTime_sec[(i)]) //!< LCF parameter macro.
#define GET_P_DPLSIA_LDPSpecificDebTime_sec(i) (P_DPLSIA_LDPSpecificDebTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_DPLSIA_LDPSpecificDebTime_sec() ((const float32*) &P_DPLSIA_LDPSpecificDebTime_sec(0)) //!< LCF parameter macro pointer.
#endif // P_DPLSIA_LDPSpecificDebTime_sec

#ifndef P_DPRSIA_RDPSpecificDebTime_sec
#define P_DPRSIA_RDPSpecificDebTime_sec(i) (LCF_CommonParamData.P_DPRSIA_RDPSpecificDebTime_sec[(i)]) //!< LCF parameter macro.
#define GET_P_DPRSIA_RDPSpecificDebTime_sec(i) (P_DPRSIA_RDPSpecificDebTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_DPRSIA_RDPSpecificDebTime_sec() ((const float32*) &P_DPRSIA_RDPSpecificDebTime_sec(0)) //!< LCF parameter macro pointer.
#endif // P_DPRSIA_RDPSpecificDebTime_sec

#ifndef P_DRMDAE_DebHorAfterHandsOff_sec
#define P_DRMDAE_DebHorAfterHandsOff_sec(i) (LCF_CommonParamData.P_DRMDAE_DebHorAfterHandsOff_sec[(i)]) //!< LCF parameter macro.
#define GET_P_DRMDAE_DebHorAfterHandsOff_sec(i) (P_DRMDAE_DebHorAfterHandsOff_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_DRMDAE_DebHorAfterHandsOff_sec() ((const float32*) &P_DRMDAE_DebHorAfterHandsOff_sec(0)) //!< LCF parameter macro pointer.
#endif // P_DRMDAE_DebHorAfterHandsOff_sec

#ifndef P_DRMDAE_DebounceTorAfterHor_sec
#define P_DRMDAE_DebounceTorAfterHor_sec(i) (LCF_CommonParamData.P_DRMDAE_DebounceTorAfterHor_sec[(i)]) //!< LCF parameter macro.
#define GET_P_DRMDAE_DebounceTorAfterHor_sec(i) (P_DRMDAE_DebounceTorAfterHor_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_DRMDAE_DebounceTorAfterHor_sec() ((const float32*) &P_DRMDAE_DebounceTorAfterHor_sec(0)) //!< LCF parameter macro pointer.
#endif // P_DRMDAE_DebounceTorAfterHor_sec

#ifndef P_DRMDAE_TrigDegrAftTorTime_sec
#define P_DRMDAE_TrigDegrAftTorTime_sec(i) (LCF_CommonParamData.P_DRMDAE_TrigDegrAftTorTime_sec[(i)]) //!< LCF parameter macro.
#define GET_P_DRMDAE_TrigDegrAftTorTime_sec(i) (P_DRMDAE_TrigDegrAftTorTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_DRMDAE_TrigDegrAftTorTime_sec() ((const float32*) &P_DRMDAE_TrigDegrAftTorTime_sec(0)) //!< LCF parameter macro pointer.
#endif // P_DRMDAE_TrigDegrAftTorTime_sec

#ifndef P_LCRSIA_SpecificDebTime_sec
#define P_LCRSIA_SpecificDebTime_sec(i) (LCF_CommonParamData.P_LCRSIA_SpecificDebTime_sec[(i)]) //!< LCF parameter macro.
#define GET_P_LCRSIA_SpecificDebTime_sec(i) (P_LCRSIA_SpecificDebTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_LCRSIA_SpecificDebTime_sec() ((const float32*) &P_LCRSIA_SpecificDebTime_sec(0)) //!< LCF parameter macro pointer.
#endif // P_LCRSIA_SpecificDebTime_sec

#ifndef P_MCTLFC_FollowUpDurationVec_sec
#define P_MCTLFC_FollowUpDurationVec_sec(i) (LCF_CommonParamData.P_MCTLFC_FollowUpDurationVec_sec[(i)]) //!< LCF parameter macro.
#define GET_P_MCTLFC_FollowUpDurationVec_sec(i) (P_MCTLFC_FollowUpDurationVec_sec(i)) //!< LCF parameter macro getter.
#define GETA_P_MCTLFC_FollowUpDurationVec_sec() ((const float32*) &P_MCTLFC_FollowUpDurationVec_sec(0)) //!< LCF parameter macro pointer.
#endif // P_MCTLFC_FollowUpDurationVec_sec

#ifndef P_MCTLFC_PriorityVector_nu
#define P_MCTLFC_PriorityVector_nu(i) (LCF_CommonParamData.P_MCTLFC_PriorityVector_nu[(i)]) //!< LCF parameter macro.
#define GET_P_MCTLFC_PriorityVector_nu(i) (P_MCTLFC_PriorityVector_nu(i)) //!< LCF parameter macro getter.
#define GETA_P_MCTLFC_PriorityVector_nu() ((const uint8*) &P_MCTLFC_PriorityVector_nu(0)) //!< LCF parameter macro pointer.
#endif // P_MCTLFC_PriorityVector_nu

#ifndef P_MCTLFC_RampOutOverwrite_bool
#define P_MCTLFC_RampOutOverwrite_bool(i) (LCF_CommonParamData.P_MCTLFC_RampOutOverwrite_bool[(i)]) //!< LCF parameter macro.
#define GET_P_MCTLFC_RampOutOverwrite_bool(i) (P_MCTLFC_RampOutOverwrite_bool(i)) //!< LCF parameter macro getter.
#define GETA_P_MCTLFC_RampOutOverwrite_bool() ((const uint8*) &P_MCTLFC_RampOutOverwrite_bool(0)) //!< LCF parameter macro pointer.
#endif // P_MCTLFC_RampOutOverwrite_bool

#ifndef X_ABPLBP_ThLnClthMinValLen_mps
#define X_ABPLBP_ThLnClthMinValLen_mps(i) (LCF_CommonParamData.X_ABPLBP_ThLnClthMinValLen_mps[(i)]) //!< LCF parameter macro.
#define GET_X_ABPLBP_ThLnClthMinValLen_mps(i) (X_ABPLBP_ThLnClthMinValLen_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_ABPLBP_ThLnClthMinValLen_mps() ((const float32*) &X_ABPLBP_ThLnClthMinValLen_mps(0)) //!< LCF parameter macro pointer.
#endif // X_ABPLBP_ThLnClthMinValLen_mps

#ifndef X_DRMHOD_VelX_mps
#define X_DRMHOD_VelX_mps(i) (LCF_CommonParamData.X_DRMHOD_VelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_DRMHOD_VelX_mps(i) (X_DRMHOD_VelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_DRMHOD_VelX_mps() ((const float32*) &X_DRMHOD_VelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_DRMHOD_VelX_mps

#ifndef X_LCF_Curvature_1pm
#define X_LCF_Curvature_1pm(i) (LCF_CommonParamData.X_LCF_Curvature_1pm[(i)]) //!< LCF parameter macro.
#define GET_X_LCF_Curvature_1pm(i) (X_LCF_Curvature_1pm(i)) //!< LCF parameter macro getter.
#define GETA_X_LCF_Curvature_1pm() ((const float32*) &X_LCF_Curvature_1pm(0)) //!< LCF parameter macro pointer.
#endif // X_LCF_Curvature_1pm

#ifndef X_LCF_DistY_met
#define X_LCF_DistY_met(i) (LCF_CommonParamData.X_LCF_DistY_met[(i)]) //!< LCF parameter macro.
#define GET_X_LCF_DistY_met(i) (X_LCF_DistY_met(i)) //!< LCF parameter macro getter.
#define GETA_X_LCF_DistY_met() ((const float32*) &X_LCF_DistY_met(0)) //!< LCF parameter macro pointer.
#endif // X_LCF_DistY_met

#ifndef X_LCF_LaneWidth_met
#define X_LCF_LaneWidth_met(i) (LCF_CommonParamData.X_LCF_LaneWidth_met[(i)]) //!< LCF parameter macro.
#define GET_X_LCF_LaneWidth_met(i) (X_LCF_LaneWidth_met(i)) //!< LCF parameter macro getter.
#define GETA_X_LCF_LaneWidth_met() ((const float32*) &X_LCF_LaneWidth_met(0)) //!< LCF parameter macro pointer.
#endif // X_LCF_LaneWidth_met

#ifndef X_LCF_VelX_mps
#define X_LCF_VelX_mps(i) (LCF_CommonParamData.X_LCF_VelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_LCF_VelX_mps(i) (X_LCF_VelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_LCF_VelX_mps() ((const float32*) &X_LCF_VelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_LCF_VelX_mps

#ifndef X_LCF_VelY_mps
#define X_LCF_VelY_mps(i) (LCF_CommonParamData.X_LCF_VelY_mps[(i)]) //!< LCF parameter macro.
#define GET_X_LCF_VelY_mps(i) (X_LCF_VelY_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_LCF_VelY_mps() ((const float32*) &X_LCF_VelY_mps(0)) //!< LCF parameter macro pointer.
#endif // X_LCF_VelY_mps

#ifndef X_ODPFOH_StraightEstim_perc
#define X_ODPFOH_StraightEstim_perc(i) (LCF_CommonParamData.X_ODPFOH_StraightEstim_perc[(i)]) //!< LCF parameter macro.
#define GET_X_ODPFOH_StraightEstim_perc(i) (X_ODPFOH_StraightEstim_perc(i)) //!< LCF parameter macro getter.
#define GETA_X_ODPFOH_StraightEstim_perc() ((const float32*) &X_ODPFOH_StraightEstim_perc(0)) //!< LCF parameter macro pointer.
#endif // X_ODPFOH_StraightEstim_perc

#ifndef X_ODPFOH_VehVelXPT1_kph
#define X_ODPFOH_VehVelXPT1_kph(i) (LCF_CommonParamData.X_ODPFOH_VehVelXPT1_kph[(i)]) //!< LCF parameter macro.
#define GET_X_ODPFOH_VehVelXPT1_kph(i) (X_ODPFOH_VehVelXPT1_kph(i)) //!< LCF parameter macro getter.
#define GETA_X_ODPFOH_VehVelXPT1_kph() ((const float32*) &X_ODPFOH_VehVelXPT1_kph(0)) //!< LCF parameter macro pointer.
#endif // X_ODPFOH_VehVelXPT1_kph

#ifndef X_ODPFOH_VehVelX_mps
#define X_ODPFOH_VehVelX_mps(i) (LCF_CommonParamData.X_ODPFOH_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_ODPFOH_VehVelX_mps(i) (X_ODPFOH_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_ODPFOH_VehVelX_mps() ((const float32*) &X_ODPFOH_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_ODPFOH_VehVelX_mps

#ifndef X_ODPFOP_LongDistMaxVel_mps
#define X_ODPFOP_LongDistMaxVel_mps(i) (LCF_CommonParamData.X_ODPFOP_LongDistMaxVel_mps[(i)]) //!< LCF parameter macro.
#define GET_X_ODPFOP_LongDistMaxVel_mps(i) (X_ODPFOP_LongDistMaxVel_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_ODPFOP_LongDistMaxVel_mps() ((const float32*) &X_ODPFOP_LongDistMaxVel_mps(0)) //!< LCF parameter macro pointer.
#endif // X_ODPFOP_LongDistMaxVel_mps

#ifndef X_TCTCLM_ControllingFunction_nu
#define X_TCTCLM_ControllingFunction_nu(i) (LCF_CommonParamData.X_TCTCLM_ControllingFunction_nu[(i)]) //!< LCF parameter macro.
#define GET_X_TCTCLM_ControllingFunction_nu(i) (X_TCTCLM_ControllingFunction_nu(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTCLM_ControllingFunction_nu() ((const uint8*) &X_TCTCLM_ControllingFunction_nu(0)) //!< LCF parameter macro pointer.
#endif // X_TCTCLM_ControllingFunction_nu

#ifndef X_TCTCLM_VehVelX_mps
#define X_TCTCLM_VehVelX_mps(i) (LCF_CommonParamData.X_TCTCLM_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TCTCLM_VehVelX_mps(i) (X_TCTCLM_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTCLM_VehVelX_mps() ((const float32*) &X_TCTCLM_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TCTCLM_VehVelX_mps

#ifndef X_TCTDTE_InputVehVelSat_met
#define X_TCTDTE_InputVehVelSat_met(i) (LCF_CommonParamData.X_TCTDTE_InputVehVelSat_met[(i)]) //!< LCF parameter macro.
#define GET_X_TCTDTE_InputVehVelSat_met(i) (X_TCTDTE_InputVehVelSat_met(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTDTE_InputVehVelSat_met() ((const float32*) &X_TCTDTE_InputVehVelSat_met(0)) //!< LCF parameter macro pointer.
#endif // X_TCTDTE_InputVehVelSat_met

#ifndef X_TCTDTE_KappaAngle_kph
#define X_TCTDTE_KappaAngle_kph(i) (LCF_CommonParamData.X_TCTDTE_KappaAngle_kph[(i)]) //!< LCF parameter macro.
#define GET_X_TCTDTE_KappaAngle_kph(i) (X_TCTDTE_KappaAngle_kph(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTDTE_KappaAngle_kph() ((const float32*) &X_TCTDTE_KappaAngle_kph(0)) //!< LCF parameter macro pointer.
#endif // X_TCTDTE_KappaAngle_kph

#ifndef X_TCTDTE_VehVelX_mps
#define X_TCTDTE_VehVelX_mps(i) (LCF_CommonParamData.X_TCTDTE_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TCTDTE_VehVelX_mps(i) (X_TCTDTE_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTDTE_VehVelX_mps() ((const float32*) &X_TCTDTE_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TCTDTE_VehVelX_mps

#ifndef X_TCTEST_InputVehVelSat_met
#define X_TCTEST_InputVehVelSat_met(i) (LCF_CommonParamData.X_TCTEST_InputVehVelSat_met[(i)]) //!< LCF parameter macro.
#define GET_X_TCTEST_InputVehVelSat_met(i) (X_TCTEST_InputVehVelSat_met(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTEST_InputVehVelSat_met() ((const float32*) &X_TCTEST_InputVehVelSat_met(0)) //!< LCF parameter macro pointer.
#endif // X_TCTEST_InputVehVelSat_met

#ifndef X_TCTEST_StwGearRatio_rad
#define X_TCTEST_StwGearRatio_rad(i) (LCF_CommonParamData.X_TCTEST_StwGearRatio_rad[(i)]) //!< LCF parameter macro.
#define GET_X_TCTEST_StwGearRatio_rad(i) (X_TCTEST_StwGearRatio_rad(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTEST_StwGearRatio_rad() ((const float32*) &X_TCTEST_StwGearRatio_rad(0)) //!< LCF parameter macro pointer.
#endif // X_TCTEST_StwGearRatio_rad

#ifndef X_TCTEST_VehVelX_mps
#define X_TCTEST_VehVelX_mps(i) (LCF_CommonParamData.X_TCTEST_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TCTEST_VehVelX_mps(i) (X_TCTEST_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTEST_VehVelX_mps() ((const float32*) &X_TCTEST_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TCTEST_VehVelX_mps

#ifndef X_TCTLGC_CrvFFC_1pm
#define X_TCTLGC_CrvFFC_1pm(i) (LCF_CommonParamData.X_TCTLGC_CrvFFC_1pm[(i)]) //!< LCF parameter macro.
#define GET_X_TCTLGC_CrvFFC_1pm(i) (X_TCTLGC_CrvFFC_1pm(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTLGC_CrvFFC_1pm() ((const float32*) &X_TCTLGC_CrvFFC_1pm(0)) //!< LCF parameter macro pointer.
#endif // X_TCTLGC_CrvFFC_1pm

#ifndef X_TCTLGC_CtrlErrDistY_met
#define X_TCTLGC_CtrlErrDistY_met(i) (LCF_CommonParamData.X_TCTLGC_CtrlErrDistY_met[(i)]) //!< LCF parameter macro.
#define GET_X_TCTLGC_CtrlErrDistY_met(i) (X_TCTLGC_CtrlErrDistY_met(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTLGC_CtrlErrDistY_met() ((const float32*) &X_TCTLGC_CtrlErrDistY_met(0)) //!< LCF parameter macro pointer.
#endif // X_TCTLGC_CtrlErrDistY_met

#ifndef X_TCTLGC_Vel_mps
#define X_TCTLGC_Vel_mps(i) (LCF_CommonParamData.X_TCTLGC_Vel_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TCTLGC_Vel_mps(i) (X_TCTLGC_Vel_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TCTLGC_Vel_mps() ((const float32*) &X_TCTLGC_Vel_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TCTLGC_Vel_mps

#ifndef X_TJAGEN_VehVelX_kph
#define X_TJAGEN_VehVelX_kph(i) (LCF_CommonParamData.X_TJAGEN_VehVelX_kph[(i)]) //!< LCF parameter macro.
#define GET_X_TJAGEN_VehVelX_kph(i) (X_TJAGEN_VehVelX_kph(i)) //!< LCF parameter macro getter.
#define GETA_X_TJAGEN_VehVelX_kph() ((const float32*) &X_TJAGEN_VehVelX_kph(0)) //!< LCF parameter macro pointer.
#endif // X_TJAGEN_VehVelX_kph

#ifndef X_TJAOBF_VehVelX_kph
#define X_TJAOBF_VehVelX_kph(i) (LCF_CommonParamData.X_TJAOBF_VehVelX_kph[(i)]) //!< LCF parameter macro.
#define GET_X_TJAOBF_VehVelX_kph(i) (X_TJAOBF_VehVelX_kph(i)) //!< LCF parameter macro getter.
#define GETA_X_TJAOBF_VehVelX_kph() ((const float32*) &X_TJAOBF_VehVelX_kph(0)) //!< LCF parameter macro pointer.
#endif // X_TJAOBF_VehVelX_kph

#ifndef X_TJATVG_CrvPlanHorizon_1pm
#define X_TJATVG_CrvPlanHorizon_1pm(i) (LCF_CommonParamData.X_TJATVG_CrvPlanHorizon_1pm[(i)]) //!< LCF parameter macro.
#define GET_X_TJATVG_CrvPlanHorizon_1pm(i) (X_TJATVG_CrvPlanHorizon_1pm(i)) //!< LCF parameter macro getter.
#define GETA_X_TJATVG_CrvPlanHorizon_1pm() ((const float32*) &X_TJATVG_CrvPlanHorizon_1pm(0)) //!< LCF parameter macro pointer.
#endif // X_TJATVG_CrvPlanHorizon_1pm

#ifndef X_TJATVG_VehVelX_RedFact_mps
#define X_TJATVG_VehVelX_RedFact_mps(i) (LCF_CommonParamData.X_TJATVG_VehVelX_RedFact_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TJATVG_VehVelX_RedFact_mps(i) (X_TJATVG_VehVelX_RedFact_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TJATVG_VehVelX_RedFact_mps() ((const float32*) &X_TJATVG_VehVelX_RedFact_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TJATVG_VehVelX_RedFact_mps

#ifndef X_TJATVG_VehVelX_mps
#define X_TJATVG_VehVelX_mps(i) (LCF_CommonParamData.X_TJATVG_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TJATVG_VehVelX_mps(i) (X_TJATVG_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TJATVG_VehVelX_mps() ((const float32*) &X_TJATVG_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TJATVG_VehVelX_mps

#ifndef X_TPLCEN_PotVecDynVelX_mps
#define X_TPLCEN_PotVecDynVelX_mps(i) (LCF_CommonParamData.X_TPLCEN_PotVecDynVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TPLCEN_PotVecDynVelX_mps(i) (X_TPLCEN_PotVecDynVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLCEN_PotVecDynVelX_mps() ((const float32*) &X_TPLCEN_PotVecDynVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TPLCEN_PotVecDynVelX_mps

#ifndef X_TPLFBT_VehVelX_mps
#define X_TPLFBT_VehVelX_mps(i) (LCF_CommonParamData.X_TPLFBT_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TPLFBT_VehVelX_mps(i) (X_TPLFBT_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLFBT_VehVelX_mps() ((const float32*) &X_TPLFBT_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TPLFBT_VehVelX_mps

#ifndef X_TPLLCO_CorridorCurvature_1pm
#define X_TPLLCO_CorridorCurvature_1pm(i) (LCF_CommonParamData.X_TPLLCO_CorridorCurvature_1pm[(i)]) //!< LCF parameter macro.
#define GET_X_TPLLCO_CorridorCurvature_1pm(i) (X_TPLLCO_CorridorCurvature_1pm(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLLCO_CorridorCurvature_1pm() ((const float32*) &X_TPLLCO_CorridorCurvature_1pm(0)) //!< LCF parameter macro pointer.
#endif // X_TPLLCO_CorridorCurvature_1pm

#ifndef X_TPLLCO_TestPointPosX_met
#define X_TPLLCO_TestPointPosX_met(i) (LCF_CommonParamData.X_TPLLCO_TestPointPosX_met[(i)]) //!< LCF parameter macro.
#define GET_X_TPLLCO_TestPointPosX_met(i) (X_TPLLCO_TestPointPosX_met(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLLCO_TestPointPosX_met() ((const float32*) &X_TPLLCO_TestPointPosX_met(0)) //!< LCF parameter macro pointer.
#endif // X_TPLLCO_TestPointPosX_met

#ifndef X_TPLLCO_VehVelX_mps
#define X_TPLLCO_VehVelX_mps(i) (LCF_CommonParamData.X_TPLLCO_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TPLLCO_VehVelX_mps(i) (X_TPLLCO_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLLCO_VehVelX_mps() ((const float32*) &X_TPLLCO_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TPLLCO_VehVelX_mps

#ifndef X_TPLTJC_PlanningHorizon_sec
#define X_TPLTJC_PlanningHorizon_sec(i) (LCF_CommonParamData.X_TPLTJC_PlanningHorizon_sec[(i)]) //!< LCF parameter macro.
#define GET_X_TPLTJC_PlanningHorizon_sec(i) (X_TPLTJC_PlanningHorizon_sec(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLTJC_PlanningHorizon_sec() ((const float32*) &X_TPLTJC_PlanningHorizon_sec(0)) //!< LCF parameter macro pointer.
#endif // X_TPLTJC_PlanningHorizon_sec

#ifndef X_TPLTJC_VehVelX_mps
#define X_TPLTJC_VehVelX_mps(i) (LCF_CommonParamData.X_TPLTJC_VehVelX_mps[(i)]) //!< LCF parameter macro.
#define GET_X_TPLTJC_VehVelX_mps(i) (X_TPLTJC_VehVelX_mps(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLTJC_VehVelX_mps() ((const float32*) &X_TPLTJC_VehVelX_mps(0)) //!< LCF parameter macro pointer.
#endif // X_TPLTJC_VehVelX_mps

#ifndef X_TPLTJC_WghtTgtDistYCustFct_nu
#define X_TPLTJC_WghtTgtDistYCustFct_nu(i) (LCF_CommonParamData.X_TPLTJC_WghtTgtDistYCustFct_nu[(i)]) //!< LCF parameter macro.
#define GET_X_TPLTJC_WghtTgtDistYCustFct_nu(i) (X_TPLTJC_WghtTgtDistYCustFct_nu(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLTJC_WghtTgtDistYCustFct_nu() ((const float32*) &X_TPLTJC_WghtTgtDistYCustFct_nu(0)) //!< LCF parameter macro pointer.
#endif // X_TPLTJC_WghtTgtDistYCustFct_nu

#ifndef X_TPLTJC_WghtTgtTimeCustFct_nu
#define X_TPLTJC_WghtTgtTimeCustFct_nu(i) (LCF_CommonParamData.X_TPLTJC_WghtTgtTimeCustFct_nu[(i)]) //!< LCF parameter macro.
#define GET_X_TPLTJC_WghtTgtTimeCustFct_nu(i) (X_TPLTJC_WghtTgtTimeCustFct_nu(i)) //!< LCF parameter macro getter.
#define GETA_X_TPLTJC_WghtTgtTimeCustFct_nu() ((const float32*) &X_TPLTJC_WghtTgtTimeCustFct_nu(0)) //!< LCF parameter macro pointer.
#endif // X_TPLTJC_WghtTgtTimeCustFct_nu

#ifndef Y_ABPLBP_ThLnClthMinValLen_met
#define Y_ABPLBP_ThLnClthMinValLen_met(i) (LCF_CommonParamData.Y_ABPLBP_ThLnClthMinValLen_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ABPLBP_ThLnClthMinValLen_met(i) (Y_ABPLBP_ThLnClthMinValLen_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ABPLBP_ThLnClthMinValLen_met() ((const float32*) &Y_ABPLBP_ThLnClthMinValLen_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ABPLBP_ThLnClthMinValLen_met

#ifndef Y_ABPLBP_ThMinValLenHyst_met
#define Y_ABPLBP_ThMinValLenHyst_met(i) (LCF_CommonParamData.Y_ABPLBP_ThMinValLenHyst_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ABPLBP_ThMinValLenHyst_met(i) (Y_ABPLBP_ThMinValLenHyst_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ABPLBP_ThMinValLenHyst_met() ((const float32*) &Y_ABPLBP_ThMinValLenHyst_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ABPLBP_ThMinValLenHyst_met

#ifndef Y_ABPREP_ThReClthMinValLen_met
#define Y_ABPREP_ThReClthMinValLen_met(i) (LCF_CommonParamData.Y_ABPREP_ThReClthMinValLen_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ABPREP_ThReClthMinValLen_met(i) (Y_ABPREP_ThReClthMinValLen_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ABPREP_ThReClthMinValLen_met() ((const float32*) &Y_ABPREP_ThReClthMinValLen_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ABPREP_ThReClthMinValLen_met

#ifndef Y_ABPREP_ThReMinValLenHyst_met
#define Y_ABPREP_ThReMinValLenHyst_met(i) (LCF_CommonParamData.Y_ABPREP_ThReMinValLenHyst_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ABPREP_ThReMinValLenHyst_met(i) (Y_ABPREP_ThReMinValLenHyst_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ABPREP_ThReMinValLenHyst_met() ((const float32*) &Y_ABPREP_ThReMinValLenHyst_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ABPREP_ThReMinValLenHyst_met

#ifndef Y_DPLSIA_VXCrvThresLDPHyst_1pm
#define Y_DPLSIA_VXCrvThresLDPHyst_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXCrvThresLDPHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXCrvThresLDPHyst_1pm(i) (Y_DPLSIA_VXCrvThresLDPHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXCrvThresLDPHyst_1pm() ((const float32*) &Y_DPLSIA_VXCrvThresLDPHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXCrvThresLDPHyst_1pm

#ifndef Y_DPLSIA_VXCrvThresLDPMax_1pm
#define Y_DPLSIA_VXCrvThresLDPMax_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXCrvThresLDPMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXCrvThresLDPMax_1pm(i) (Y_DPLSIA_VXCrvThresLDPMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXCrvThresLDPMax_1pm() ((const float32*) &Y_DPLSIA_VXCrvThresLDPMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXCrvThresLDPMax_1pm

#ifndef Y_DPLSIA_VXCrvThresLDWHyst_1pm
#define Y_DPLSIA_VXCrvThresLDWHyst_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXCrvThresLDWHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXCrvThresLDWHyst_1pm(i) (Y_DPLSIA_VXCrvThresLDWHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXCrvThresLDWHyst_1pm() ((const float32*) &Y_DPLSIA_VXCrvThresLDWHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXCrvThresLDWHyst_1pm

#ifndef Y_DPLSIA_VXCrvThresLDWMax_1pm
#define Y_DPLSIA_VXCrvThresLDWMax_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXCrvThresLDWMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXCrvThresLDWMax_1pm(i) (Y_DPLSIA_VXCrvThresLDWMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXCrvThresLDWMax_1pm() ((const float32*) &Y_DPLSIA_VXCrvThresLDWMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXCrvThresLDWMax_1pm

#ifndef Y_DPLSIA_VXVehCrvThresHyst_1pm
#define Y_DPLSIA_VXVehCrvThresHyst_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXVehCrvThresHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXVehCrvThresHyst_1pm(i) (Y_DPLSIA_VXVehCrvThresHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXVehCrvThresHyst_1pm() ((const float32*) &Y_DPLSIA_VXVehCrvThresHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXVehCrvThresHyst_1pm

#ifndef Y_DPLSIA_VXVehCrvThresLDWHyst_1pm
#define Y_DPLSIA_VXVehCrvThresLDWHyst_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXVehCrvThresLDWHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXVehCrvThresLDWHyst_1pm(i) (Y_DPLSIA_VXVehCrvThresLDWHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXVehCrvThresLDWHyst_1pm() ((const float32*) &Y_DPLSIA_VXVehCrvThresLDWHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXVehCrvThresLDWHyst_1pm

#ifndef Y_DPLSIA_VXVehCrvThresLDWMax_1pm
#define Y_DPLSIA_VXVehCrvThresLDWMax_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXVehCrvThresLDWMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXVehCrvThresLDWMax_1pm(i) (Y_DPLSIA_VXVehCrvThresLDWMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXVehCrvThresLDWMax_1pm() ((const float32*) &Y_DPLSIA_VXVehCrvThresLDWMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXVehCrvThresLDWMax_1pm

#ifndef Y_DPLSIA_VXVehCrvThresMax_1pm
#define Y_DPLSIA_VXVehCrvThresMax_1pm(i) (LCF_CommonParamData.Y_DPLSIA_VXVehCrvThresMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSIA_VXVehCrvThresMax_1pm(i) (Y_DPLSIA_VXVehCrvThresMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSIA_VXVehCrvThresMax_1pm() ((const float32*) &Y_DPLSIA_VXVehCrvThresMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSIA_VXVehCrvThresMax_1pm

#ifndef Y_DPLSMI_CrvICDlcOffset_met
#define Y_DPLSMI_CrvICDlcOffset_met(i) (LCF_CommonParamData.Y_DPLSMI_CrvICDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_CrvICDlcOffset_met(i) (Y_DPLSMI_CrvICDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_CrvICDlcOffset_met() ((const float32*) &Y_DPLSMI_CrvICDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_CrvICDlcOffset_met

#ifndef Y_DPLSMI_CrvICTlcOffset_sec
#define Y_DPLSMI_CrvICTlcOffset_sec(i) (LCF_CommonParamData.Y_DPLSMI_CrvICTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_CrvICTlcOffset_sec(i) (Y_DPLSMI_CrvICTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_CrvICTlcOffset_sec() ((const float32*) &Y_DPLSMI_CrvICTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_CrvICTlcOffset_sec

#ifndef Y_DPLSMI_CrvOCDlcOffset_met
#define Y_DPLSMI_CrvOCDlcOffset_met(i) (LCF_CommonParamData.Y_DPLSMI_CrvOCDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_CrvOCDlcOffset_met(i) (Y_DPLSMI_CrvOCDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_CrvOCDlcOffset_met() ((const float32*) &Y_DPLSMI_CrvOCDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_CrvOCDlcOffset_met

#ifndef Y_DPLSMI_CrvOCTlcOffset_sec
#define Y_DPLSMI_CrvOCTlcOffset_sec(i) (LCF_CommonParamData.Y_DPLSMI_CrvOCTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_CrvOCTlcOffset_sec(i) (Y_DPLSMI_CrvOCTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_CrvOCTlcOffset_sec() ((const float32*) &Y_DPLSMI_CrvOCTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_CrvOCTlcOffset_sec

#ifndef Y_DPLSMI_LWContrMaxDurScal_nu
#define Y_DPLSMI_LWContrMaxDurScal_nu(i) (LCF_CommonParamData.Y_DPLSMI_LWContrMaxDurScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_LWContrMaxDurScal_nu(i) (Y_DPLSMI_LWContrMaxDurScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_LWContrMaxDurScal_nu() ((const float32*) &Y_DPLSMI_LWContrMaxDurScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_LWContrMaxDurScal_nu

#ifndef Y_DPLSMI_LWHazardFinishTol_met
#define Y_DPLSMI_LWHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPLSMI_LWHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_LWHazardFinishTol_met(i) (Y_DPLSMI_LWHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_LWHazardFinishTol_met() ((const float32*) &Y_DPLSMI_LWHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_LWHazardFinishTol_met

#ifndef Y_DPLSMI_LWNoHazardFinishTol_met
#define Y_DPLSMI_LWNoHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPLSMI_LWNoHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_LWNoHazardFinishTol_met(i) (Y_DPLSMI_LWNoHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_LWNoHazardFinishTol_met() ((const float32*) &Y_DPLSMI_LWNoHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_LWNoHazardFinishTol_met

#ifndef Y_DPLSMI_LWTrigDlcScalFact_nu
#define Y_DPLSMI_LWTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMI_LWTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_LWTrigDlcScalFact_nu(i) (Y_DPLSMI_LWTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_LWTrigDlcScalFact_nu() ((const float32*) &Y_DPLSMI_LWTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_LWTrigDlcScalFact_nu

#ifndef Y_DPLSMI_LWTrigTlcScalFact_nu
#define Y_DPLSMI_LWTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMI_LWTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_LWTrigTlcScalFact_nu(i) (Y_DPLSMI_LWTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_LWTrigTlcScalFact_nu() ((const float32*) &Y_DPLSMI_LWTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_LWTrigTlcScalFact_nu

#ifndef Y_DPLSMI_VXContrMaxDur_sec
#define Y_DPLSMI_VXContrMaxDur_sec(i) (LCF_CommonParamData.Y_DPLSMI_VXContrMaxDur_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXContrMaxDur_sec(i) (Y_DPLSMI_VXContrMaxDur_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXContrMaxDur_sec() ((const float32*) &Y_DPLSMI_VXContrMaxDur_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXContrMaxDur_sec

#ifndef Y_DPLSMI_VXMD1TrigDlc_met
#define Y_DPLSMI_VXMD1TrigDlc_met(i) (LCF_CommonParamData.Y_DPLSMI_VXMD1TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXMD1TrigDlc_met(i) (Y_DPLSMI_VXMD1TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXMD1TrigDlc_met() ((const float32*) &Y_DPLSMI_VXMD1TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXMD1TrigDlc_met

#ifndef Y_DPLSMI_VXMD1TrigTlc_sec
#define Y_DPLSMI_VXMD1TrigTlc_sec(i) (LCF_CommonParamData.Y_DPLSMI_VXMD1TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXMD1TrigTlc_sec(i) (Y_DPLSMI_VXMD1TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXMD1TrigTlc_sec() ((const float32*) &Y_DPLSMI_VXMD1TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXMD1TrigTlc_sec

#ifndef Y_DPLSMI_VXMD2TrigDlc_met
#define Y_DPLSMI_VXMD2TrigDlc_met(i) (LCF_CommonParamData.Y_DPLSMI_VXMD2TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXMD2TrigDlc_met(i) (Y_DPLSMI_VXMD2TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXMD2TrigDlc_met() ((const float32*) &Y_DPLSMI_VXMD2TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXMD2TrigDlc_met

#ifndef Y_DPLSMI_VXMD2TrigTlc_sec
#define Y_DPLSMI_VXMD2TrigTlc_sec(i) (LCF_CommonParamData.Y_DPLSMI_VXMD2TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXMD2TrigTlc_sec(i) (Y_DPLSMI_VXMD2TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXMD2TrigTlc_sec() ((const float32*) &Y_DPLSMI_VXMD2TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXMD2TrigTlc_sec

#ifndef Y_DPLSMI_VXMD3TrigDlc_met
#define Y_DPLSMI_VXMD3TrigDlc_met(i) (LCF_CommonParamData.Y_DPLSMI_VXMD3TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXMD3TrigDlc_met(i) (Y_DPLSMI_VXMD3TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXMD3TrigDlc_met() ((const float32*) &Y_DPLSMI_VXMD3TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXMD3TrigDlc_met

#ifndef Y_DPLSMI_VXMD3TrigTlc_sec
#define Y_DPLSMI_VXMD3TrigTlc_sec(i) (LCF_CommonParamData.Y_DPLSMI_VXMD3TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VXMD3TrigTlc_sec(i) (Y_DPLSMI_VXMD3TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VXMD3TrigTlc_sec() ((const float32*) &Y_DPLSMI_VXMD3TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VXMD3TrigTlc_sec

#ifndef Y_DPLSMI_VYTrigDlcScalFact_nu
#define Y_DPLSMI_VYTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMI_VYTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VYTrigDlcScalFact_nu(i) (Y_DPLSMI_VYTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VYTrigDlcScalFact_nu() ((const float32*) &Y_DPLSMI_VYTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VYTrigDlcScalFact_nu

#ifndef Y_DPLSMI_VYTrigTlcScalFact_nu
#define Y_DPLSMI_VYTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMI_VYTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMI_VYTrigTlcScalFact_nu(i) (Y_DPLSMI_VYTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMI_VYTrigTlcScalFact_nu() ((const float32*) &Y_DPLSMI_VYTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMI_VYTrigTlcScalFact_nu

#ifndef Y_DPLSMW_CrvICDlcOffset_met
#define Y_DPLSMW_CrvICDlcOffset_met(i) (LCF_CommonParamData.Y_DPLSMW_CrvICDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_CrvICDlcOffset_met(i) (Y_DPLSMW_CrvICDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_CrvICDlcOffset_met() ((const float32*) &Y_DPLSMW_CrvICDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_CrvICDlcOffset_met

#ifndef Y_DPLSMW_CrvICTlcOffset_sec
#define Y_DPLSMW_CrvICTlcOffset_sec(i) (LCF_CommonParamData.Y_DPLSMW_CrvICTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_CrvICTlcOffset_sec(i) (Y_DPLSMW_CrvICTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_CrvICTlcOffset_sec() ((const float32*) &Y_DPLSMW_CrvICTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_CrvICTlcOffset_sec

#ifndef Y_DPLSMW_CrvOCDlcOffset_met
#define Y_DPLSMW_CrvOCDlcOffset_met(i) (LCF_CommonParamData.Y_DPLSMW_CrvOCDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_CrvOCDlcOffset_met(i) (Y_DPLSMW_CrvOCDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_CrvOCDlcOffset_met() ((const float32*) &Y_DPLSMW_CrvOCDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_CrvOCDlcOffset_met

#ifndef Y_DPLSMW_CrvOCTlcOffset_sec
#define Y_DPLSMW_CrvOCTlcOffset_sec(i) (LCF_CommonParamData.Y_DPLSMW_CrvOCTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_CrvOCTlcOffset_sec(i) (Y_DPLSMW_CrvOCTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_CrvOCTlcOffset_sec() ((const float32*) &Y_DPLSMW_CrvOCTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_CrvOCTlcOffset_sec

#ifndef Y_DPLSMW_LWContrMaxDurScal_nu
#define Y_DPLSMW_LWContrMaxDurScal_nu(i) (LCF_CommonParamData.Y_DPLSMW_LWContrMaxDurScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_LWContrMaxDurScal_nu(i) (Y_DPLSMW_LWContrMaxDurScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_LWContrMaxDurScal_nu() ((const float32*) &Y_DPLSMW_LWContrMaxDurScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_LWContrMaxDurScal_nu

#ifndef Y_DPLSMW_LWHazardFinishTol_met
#define Y_DPLSMW_LWHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPLSMW_LWHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_LWHazardFinishTol_met(i) (Y_DPLSMW_LWHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_LWHazardFinishTol_met() ((const float32*) &Y_DPLSMW_LWHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_LWHazardFinishTol_met

#ifndef Y_DPLSMW_LWNoHazardFinishTol_met
#define Y_DPLSMW_LWNoHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPLSMW_LWNoHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_LWNoHazardFinishTol_met(i) (Y_DPLSMW_LWNoHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_LWNoHazardFinishTol_met() ((const float32*) &Y_DPLSMW_LWNoHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_LWNoHazardFinishTol_met

#ifndef Y_DPLSMW_LWTrigDlcScalFact_nu
#define Y_DPLSMW_LWTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMW_LWTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_LWTrigDlcScalFact_nu(i) (Y_DPLSMW_LWTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_LWTrigDlcScalFact_nu() ((const float32*) &Y_DPLSMW_LWTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_LWTrigDlcScalFact_nu

#ifndef Y_DPLSMW_LWTrigTlcScalFact_nu
#define Y_DPLSMW_LWTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMW_LWTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_LWTrigTlcScalFact_nu(i) (Y_DPLSMW_LWTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_LWTrigTlcScalFact_nu() ((const float32*) &Y_DPLSMW_LWTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_LWTrigTlcScalFact_nu

#ifndef Y_DPLSMW_VXContrMaxDur_sec
#define Y_DPLSMW_VXContrMaxDur_sec(i) (LCF_CommonParamData.Y_DPLSMW_VXContrMaxDur_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXContrMaxDur_sec(i) (Y_DPLSMW_VXContrMaxDur_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXContrMaxDur_sec() ((const float32*) &Y_DPLSMW_VXContrMaxDur_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXContrMaxDur_sec

#ifndef Y_DPLSMW_VXMD1TrigDlc_met
#define Y_DPLSMW_VXMD1TrigDlc_met(i) (LCF_CommonParamData.Y_DPLSMW_VXMD1TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXMD1TrigDlc_met(i) (Y_DPLSMW_VXMD1TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXMD1TrigDlc_met() ((const float32*) &Y_DPLSMW_VXMD1TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXMD1TrigDlc_met

#ifndef Y_DPLSMW_VXMD1TrigTlc_sec
#define Y_DPLSMW_VXMD1TrigTlc_sec(i) (LCF_CommonParamData.Y_DPLSMW_VXMD1TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXMD1TrigTlc_sec(i) (Y_DPLSMW_VXMD1TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXMD1TrigTlc_sec() ((const float32*) &Y_DPLSMW_VXMD1TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXMD1TrigTlc_sec

#ifndef Y_DPLSMW_VXMD2TrigDlc_met
#define Y_DPLSMW_VXMD2TrigDlc_met(i) (LCF_CommonParamData.Y_DPLSMW_VXMD2TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXMD2TrigDlc_met(i) (Y_DPLSMW_VXMD2TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXMD2TrigDlc_met() ((const float32*) &Y_DPLSMW_VXMD2TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXMD2TrigDlc_met

#ifndef Y_DPLSMW_VXMD2TrigTlc_sec
#define Y_DPLSMW_VXMD2TrigTlc_sec(i) (LCF_CommonParamData.Y_DPLSMW_VXMD2TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXMD2TrigTlc_sec(i) (Y_DPLSMW_VXMD2TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXMD2TrigTlc_sec() ((const float32*) &Y_DPLSMW_VXMD2TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXMD2TrigTlc_sec

#ifndef Y_DPLSMW_VXMD3TrigDlc_met
#define Y_DPLSMW_VXMD3TrigDlc_met(i) (LCF_CommonParamData.Y_DPLSMW_VXMD3TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXMD3TrigDlc_met(i) (Y_DPLSMW_VXMD3TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXMD3TrigDlc_met() ((const float32*) &Y_DPLSMW_VXMD3TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXMD3TrigDlc_met

#ifndef Y_DPLSMW_VXMD3TrigTlc_sec
#define Y_DPLSMW_VXMD3TrigTlc_sec(i) (LCF_CommonParamData.Y_DPLSMW_VXMD3TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VXMD3TrigTlc_sec(i) (Y_DPLSMW_VXMD3TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VXMD3TrigTlc_sec() ((const float32*) &Y_DPLSMW_VXMD3TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VXMD3TrigTlc_sec

#ifndef Y_DPLSMW_VYTrigDlcScalFact_nu
#define Y_DPLSMW_VYTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMW_VYTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VYTrigDlcScalFact_nu(i) (Y_DPLSMW_VYTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VYTrigDlcScalFact_nu() ((const float32*) &Y_DPLSMW_VYTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VYTrigDlcScalFact_nu

#ifndef Y_DPLSMW_VYTrigTlcScalFact_nu
#define Y_DPLSMW_VYTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPLSMW_VYTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLSMW_VYTrigTlcScalFact_nu(i) (Y_DPLSMW_VYTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLSMW_VYTrigTlcScalFact_nu() ((const float32*) &Y_DPLSMW_VYTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLSMW_VYTrigTlcScalFact_nu

#ifndef Y_DPLTTG_CrvICTgtOffset_met
#define Y_DPLTTG_CrvICTgtOffset_met(i) (LCF_CommonParamData.Y_DPLTTG_CrvICTgtOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTTG_CrvICTgtOffset_met(i) (Y_DPLTTG_CrvICTgtOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTTG_CrvICTgtOffset_met() ((const float32*) &Y_DPLTTG_CrvICTgtOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTTG_CrvICTgtOffset_met

#ifndef Y_DPLTTG_CrvOCTgtOffset_met
#define Y_DPLTTG_CrvOCTgtOffset_met(i) (LCF_CommonParamData.Y_DPLTTG_CrvOCTgtOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTTG_CrvOCTgtOffset_met(i) (Y_DPLTTG_CrvOCTgtOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTTG_CrvOCTgtOffset_met() ((const float32*) &Y_DPLTTG_CrvOCTgtOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTTG_CrvOCTgtOffset_met

#ifndef Y_DPLTTG_LWTargetLatDist_met
#define Y_DPLTTG_LWTargetLatDist_met(i) (LCF_CommonParamData.Y_DPLTTG_LWTargetLatDist_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTTG_LWTargetLatDist_met(i) (Y_DPLTTG_LWTargetLatDist_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTTG_LWTargetLatDist_met() ((const float32*) &Y_DPLTTG_LWTargetLatDist_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTTG_LWTargetLatDist_met

#ifndef Y_DPLTVG_CrvICPlanHorizonScal_nu
#define Y_DPLTVG_CrvICPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPLTVG_CrvICPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_CrvICPlanHorizonScal_nu(i) (Y_DPLTVG_CrvICPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_CrvICPlanHorizonScal_nu() ((const float32*) &Y_DPLTVG_CrvICPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_CrvICPlanHorizonScal_nu

#ifndef Y_DPLTVG_CrvOCPlanHorizonScal_nu
#define Y_DPLTVG_CrvOCPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPLTVG_CrvOCPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_CrvOCPlanHorizonScal_nu(i) (Y_DPLTVG_CrvOCPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_CrvOCPlanHorizonScal_nu() ((const float32*) &Y_DPLTVG_CrvOCPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_CrvOCPlanHorizonScal_nu

#ifndef Y_DPLTVG_D2TPlanHorizonScal_nu
#define Y_DPLTVG_D2TPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPLTVG_D2TPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_D2TPlanHorizonScal_nu(i) (Y_DPLTVG_D2TPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_D2TPlanHorizonScal_nu() ((const float32*) &Y_DPLTVG_D2TPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_D2TPlanHorizonScal_nu

#ifndef Y_DPLTVG_VXPlanHorizonScal_nu
#define Y_DPLTVG_VXPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPLTVG_VXPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VXPlanHorizonScal_nu(i) (Y_DPLTVG_VXPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VXPlanHorizonScal_nu() ((const float32*) &Y_DPLTVG_VXPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VXPlanHorizonScal_nu

#ifndef Y_DPLTVG_VXWeightEndtime_nu
#define Y_DPLTVG_VXWeightEndtime_nu(i) (LCF_CommonParamData.Y_DPLTVG_VXWeightEndtime_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VXWeightEndtime_nu(i) (Y_DPLTVG_VXWeightEndtime_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VXWeightEndtime_nu() ((const float32*) &Y_DPLTVG_VXWeightEndtime_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VXWeightEndtime_nu

#ifndef Y_DPLTVG_VYMD1DeratingLevel_nu
#define Y_DPLTVG_VYMD1DeratingLevel_nu(i) (LCF_CommonParamData.Y_DPLTVG_VYMD1DeratingLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VYMD1DeratingLevel_nu(i) (Y_DPLTVG_VYMD1DeratingLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VYMD1DeratingLevel_nu() ((const float32*) &Y_DPLTVG_VYMD1DeratingLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VYMD1DeratingLevel_nu

#ifndef Y_DPLTVG_VYMD2DeratingLevel_nu
#define Y_DPLTVG_VYMD2DeratingLevel_nu(i) (LCF_CommonParamData.Y_DPLTVG_VYMD2DeratingLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VYMD2DeratingLevel_nu(i) (Y_DPLTVG_VYMD2DeratingLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VYMD2DeratingLevel_nu() ((const float32*) &Y_DPLTVG_VYMD2DeratingLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VYMD2DeratingLevel_nu

#ifndef Y_DPLTVG_VYMD3DeratingLevel_nu
#define Y_DPLTVG_VYMD3DeratingLevel_nu(i) (LCF_CommonParamData.Y_DPLTVG_VYMD3DeratingLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VYMD3DeratingLevel_nu(i) (Y_DPLTVG_VYMD3DeratingLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VYMD3DeratingLevel_nu() ((const float32*) &Y_DPLTVG_VYMD3DeratingLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VYMD3DeratingLevel_nu

#ifndef Y_DPLTVG_VYPlanningHorizon_sec
#define Y_DPLTVG_VYPlanningHorizon_sec(i) (LCF_CommonParamData.Y_DPLTVG_VYPlanningHorizon_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VYPlanningHorizon_sec(i) (Y_DPLTVG_VYPlanningHorizon_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VYPlanningHorizon_sec() ((const float32*) &Y_DPLTVG_VYPlanningHorizon_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VYPlanningHorizon_sec

#ifndef Y_DPLTVG_VYStrWhStifRIGrad_1ps
#define Y_DPLTVG_VYStrWhStifRIGrad_1ps(i) (LCF_CommonParamData.Y_DPLTVG_VYStrWhStifRIGrad_1ps[(i)]) //!< LCF parameter macro.
#define GET_Y_DPLTVG_VYStrWhStifRIGrad_1ps(i) (Y_DPLTVG_VYStrWhStifRIGrad_1ps(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPLTVG_VYStrWhStifRIGrad_1ps() ((const float32*) &Y_DPLTVG_VYStrWhStifRIGrad_1ps(0)) //!< LCF parameter macro pointer.
#endif // Y_DPLTVG_VYStrWhStifRIGrad_1ps

#ifndef Y_DPRSIA_CrvVehCrvTurnOn_sec
#define Y_DPRSIA_CrvVehCrvTurnOn_sec(i) (LCF_CommonParamData.Y_DPRSIA_CrvVehCrvTurnOn_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_CrvVehCrvTurnOn_sec(i) (Y_DPRSIA_CrvVehCrvTurnOn_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_CrvVehCrvTurnOn_sec() ((const float32*) &Y_DPRSIA_CrvVehCrvTurnOn_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_CrvVehCrvTurnOn_sec

#ifndef Y_DPRSIA_VXLnCrvThresHyst_1pm
#define Y_DPRSIA_VXLnCrvThresHyst_1pm(i) (LCF_CommonParamData.Y_DPRSIA_VXLnCrvThresHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_VXLnCrvThresHyst_1pm(i) (Y_DPRSIA_VXLnCrvThresHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_VXLnCrvThresHyst_1pm() ((const float32*) &Y_DPRSIA_VXLnCrvThresHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_VXLnCrvThresHyst_1pm

#ifndef Y_DPRSIA_VXLnCrvThresMax_1pm
#define Y_DPRSIA_VXLnCrvThresMax_1pm(i) (LCF_CommonParamData.Y_DPRSIA_VXLnCrvThresMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_VXLnCrvThresMax_1pm(i) (Y_DPRSIA_VXLnCrvThresMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_VXLnCrvThresMax_1pm() ((const float32*) &Y_DPRSIA_VXLnCrvThresMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_VXLnCrvThresMax_1pm

#ifndef Y_DPRSIA_VXReCrvThresHyst_1pm
#define Y_DPRSIA_VXReCrvThresHyst_1pm(i) (LCF_CommonParamData.Y_DPRSIA_VXReCrvThresHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_VXReCrvThresHyst_1pm(i) (Y_DPRSIA_VXReCrvThresHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_VXReCrvThresHyst_1pm() ((const float32*) &Y_DPRSIA_VXReCrvThresHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_VXReCrvThresHyst_1pm

#ifndef Y_DPRSIA_VXReCrvThresMax_1pm
#define Y_DPRSIA_VXReCrvThresMax_1pm(i) (LCF_CommonParamData.Y_DPRSIA_VXReCrvThresMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_VXReCrvThresMax_1pm(i) (Y_DPRSIA_VXReCrvThresMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_VXReCrvThresMax_1pm() ((const float32*) &Y_DPRSIA_VXReCrvThresMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_VXReCrvThresMax_1pm

#ifndef Y_DPRSIA_VXVehCrvThresHyst_1pm
#define Y_DPRSIA_VXVehCrvThresHyst_1pm(i) (LCF_CommonParamData.Y_DPRSIA_VXVehCrvThresHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_VXVehCrvThresHyst_1pm(i) (Y_DPRSIA_VXVehCrvThresHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_VXVehCrvThresHyst_1pm() ((const float32*) &Y_DPRSIA_VXVehCrvThresHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_VXVehCrvThresHyst_1pm

#ifndef Y_DPRSIA_VXVehCrvThresMax_1pm
#define Y_DPRSIA_VXVehCrvThresMax_1pm(i) (LCF_CommonParamData.Y_DPRSIA_VXVehCrvThresMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSIA_VXVehCrvThresMax_1pm(i) (Y_DPRSIA_VXVehCrvThresMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSIA_VXVehCrvThresMax_1pm() ((const float32*) &Y_DPRSIA_VXVehCrvThresMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSIA_VXVehCrvThresMax_1pm

#ifndef Y_DPRSMI_CrvICDlcOffset_met
#define Y_DPRSMI_CrvICDlcOffset_met(i) (LCF_CommonParamData.Y_DPRSMI_CrvICDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvICDlcOffset_met(i) (Y_DPRSMI_CrvICDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvICDlcOffset_met() ((const float32*) &Y_DPRSMI_CrvICDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvICDlcOffset_met

#ifndef Y_DPRSMI_CrvICDrcOffset_met
#define Y_DPRSMI_CrvICDrcOffset_met(i) (LCF_CommonParamData.Y_DPRSMI_CrvICDrcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvICDrcOffset_met(i) (Y_DPRSMI_CrvICDrcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvICDrcOffset_met() ((const float32*) &Y_DPRSMI_CrvICDrcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvICDrcOffset_met

#ifndef Y_DPRSMI_CrvICTlcOffset_sec
#define Y_DPRSMI_CrvICTlcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMI_CrvICTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvICTlcOffset_sec(i) (Y_DPRSMI_CrvICTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvICTlcOffset_sec() ((const float32*) &Y_DPRSMI_CrvICTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvICTlcOffset_sec

#ifndef Y_DPRSMI_CrvICTrcOffset_sec
#define Y_DPRSMI_CrvICTrcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMI_CrvICTrcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvICTrcOffset_sec(i) (Y_DPRSMI_CrvICTrcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvICTrcOffset_sec() ((const float32*) &Y_DPRSMI_CrvICTrcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvICTrcOffset_sec

#ifndef Y_DPRSMI_CrvOCDlcOffset_met
#define Y_DPRSMI_CrvOCDlcOffset_met(i) (LCF_CommonParamData.Y_DPRSMI_CrvOCDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvOCDlcOffset_met(i) (Y_DPRSMI_CrvOCDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvOCDlcOffset_met() ((const float32*) &Y_DPRSMI_CrvOCDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvOCDlcOffset_met

#ifndef Y_DPRSMI_CrvOCDrcOffset_met
#define Y_DPRSMI_CrvOCDrcOffset_met(i) (LCF_CommonParamData.Y_DPRSMI_CrvOCDrcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvOCDrcOffset_met(i) (Y_DPRSMI_CrvOCDrcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvOCDrcOffset_met() ((const float32*) &Y_DPRSMI_CrvOCDrcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvOCDrcOffset_met

#ifndef Y_DPRSMI_CrvOCTlcOffset_sec
#define Y_DPRSMI_CrvOCTlcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMI_CrvOCTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvOCTlcOffset_sec(i) (Y_DPRSMI_CrvOCTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvOCTlcOffset_sec() ((const float32*) &Y_DPRSMI_CrvOCTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvOCTlcOffset_sec

#ifndef Y_DPRSMI_CrvOCTrcOffset_sec
#define Y_DPRSMI_CrvOCTrcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMI_CrvOCTrcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_CrvOCTrcOffset_sec(i) (Y_DPRSMI_CrvOCTrcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_CrvOCTrcOffset_sec() ((const float32*) &Y_DPRSMI_CrvOCTrcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_CrvOCTrcOffset_sec

#ifndef Y_DPRSMI_LWContrMaxDurLnScal_nu
#define Y_DPRSMI_LWContrMaxDurLnScal_nu(i) (LCF_CommonParamData.Y_DPRSMI_LWContrMaxDurLnScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWContrMaxDurLnScal_nu(i) (Y_DPRSMI_LWContrMaxDurLnScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWContrMaxDurLnScal_nu() ((const float32*) &Y_DPRSMI_LWContrMaxDurLnScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWContrMaxDurLnScal_nu

#ifndef Y_DPRSMI_LWContrMaxDurReScal_nu
#define Y_DPRSMI_LWContrMaxDurReScal_nu(i) (LCF_CommonParamData.Y_DPRSMI_LWContrMaxDurReScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWContrMaxDurReScal_nu(i) (Y_DPRSMI_LWContrMaxDurReScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWContrMaxDurReScal_nu() ((const float32*) &Y_DPRSMI_LWContrMaxDurReScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWContrMaxDurReScal_nu

#ifndef Y_DPRSMI_LWHazardFinishTol_met
#define Y_DPRSMI_LWHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPRSMI_LWHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWHazardFinishTol_met(i) (Y_DPRSMI_LWHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWHazardFinishTol_met() ((const float32*) &Y_DPRSMI_LWHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWHazardFinishTol_met

#ifndef Y_DPRSMI_LWNoHazardFinishTol_met
#define Y_DPRSMI_LWNoHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPRSMI_LWNoHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWNoHazardFinishTol_met(i) (Y_DPRSMI_LWNoHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWNoHazardFinishTol_met() ((const float32*) &Y_DPRSMI_LWNoHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWNoHazardFinishTol_met

#ifndef Y_DPRSMI_LWTrigDlcScalFact_nu
#define Y_DPRSMI_LWTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_LWTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWTrigDlcScalFact_nu(i) (Y_DPRSMI_LWTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWTrigDlcScalFact_nu() ((const float32*) &Y_DPRSMI_LWTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWTrigDlcScalFact_nu

#ifndef Y_DPRSMI_LWTrigDrcScalFact_nu
#define Y_DPRSMI_LWTrigDrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_LWTrigDrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWTrigDrcScalFact_nu(i) (Y_DPRSMI_LWTrigDrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWTrigDrcScalFact_nu() ((const float32*) &Y_DPRSMI_LWTrigDrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWTrigDrcScalFact_nu

#ifndef Y_DPRSMI_LWTrigTlcScalFact_nu
#define Y_DPRSMI_LWTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_LWTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWTrigTlcScalFact_nu(i) (Y_DPRSMI_LWTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWTrigTlcScalFact_nu() ((const float32*) &Y_DPRSMI_LWTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWTrigTlcScalFact_nu

#ifndef Y_DPRSMI_LWTrigTrcScalFact_nu
#define Y_DPRSMI_LWTrigTrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_LWTrigTrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_LWTrigTrcScalFact_nu(i) (Y_DPRSMI_LWTrigTrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_LWTrigTrcScalFact_nu() ((const float32*) &Y_DPRSMI_LWTrigTrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_LWTrigTrcScalFact_nu

#ifndef Y_DPRSMI_VXContrMaxDurLn_sec
#define Y_DPRSMI_VXContrMaxDurLn_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXContrMaxDurLn_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXContrMaxDurLn_sec(i) (Y_DPRSMI_VXContrMaxDurLn_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXContrMaxDurLn_sec() ((const float32*) &Y_DPRSMI_VXContrMaxDurLn_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXContrMaxDurLn_sec

#ifndef Y_DPRSMI_VXContrMaxDurRe_sec
#define Y_DPRSMI_VXContrMaxDurRe_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXContrMaxDurRe_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXContrMaxDurRe_sec(i) (Y_DPRSMI_VXContrMaxDurRe_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXContrMaxDurRe_sec() ((const float32*) &Y_DPRSMI_VXContrMaxDurRe_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXContrMaxDurRe_sec

#ifndef Y_DPRSMI_VXMD1TrigDlc_met
#define Y_DPRSMI_VXMD1TrigDlc_met(i) (LCF_CommonParamData.Y_DPRSMI_VXMD1TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD1TrigDlc_met(i) (Y_DPRSMI_VXMD1TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD1TrigDlc_met() ((const float32*) &Y_DPRSMI_VXMD1TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD1TrigDlc_met

#ifndef Y_DPRSMI_VXMD1TrigDrc_met
#define Y_DPRSMI_VXMD1TrigDrc_met(i) (LCF_CommonParamData.Y_DPRSMI_VXMD1TrigDrc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD1TrigDrc_met(i) (Y_DPRSMI_VXMD1TrigDrc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD1TrigDrc_met() ((const float32*) &Y_DPRSMI_VXMD1TrigDrc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD1TrigDrc_met

#ifndef Y_DPRSMI_VXMD1TrigTlc_sec
#define Y_DPRSMI_VXMD1TrigTlc_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXMD1TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD1TrigTlc_sec(i) (Y_DPRSMI_VXMD1TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD1TrigTlc_sec() ((const float32*) &Y_DPRSMI_VXMD1TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD1TrigTlc_sec

#ifndef Y_DPRSMI_VXMD1TrigTrc_sec
#define Y_DPRSMI_VXMD1TrigTrc_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXMD1TrigTrc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD1TrigTrc_sec(i) (Y_DPRSMI_VXMD1TrigTrc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD1TrigTrc_sec() ((const float32*) &Y_DPRSMI_VXMD1TrigTrc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD1TrigTrc_sec

#ifndef Y_DPRSMI_VXMD2TrigDlc_met
#define Y_DPRSMI_VXMD2TrigDlc_met(i) (LCF_CommonParamData.Y_DPRSMI_VXMD2TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD2TrigDlc_met(i) (Y_DPRSMI_VXMD2TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD2TrigDlc_met() ((const float32*) &Y_DPRSMI_VXMD2TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD2TrigDlc_met

#ifndef Y_DPRSMI_VXMD2TrigDrc_met
#define Y_DPRSMI_VXMD2TrigDrc_met(i) (LCF_CommonParamData.Y_DPRSMI_VXMD2TrigDrc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD2TrigDrc_met(i) (Y_DPRSMI_VXMD2TrigDrc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD2TrigDrc_met() ((const float32*) &Y_DPRSMI_VXMD2TrigDrc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD2TrigDrc_met

#ifndef Y_DPRSMI_VXMD2TrigTlc_sec
#define Y_DPRSMI_VXMD2TrigTlc_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXMD2TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD2TrigTlc_sec(i) (Y_DPRSMI_VXMD2TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD2TrigTlc_sec() ((const float32*) &Y_DPRSMI_VXMD2TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD2TrigTlc_sec

#ifndef Y_DPRSMI_VXMD2TrigTrc_sec
#define Y_DPRSMI_VXMD2TrigTrc_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXMD2TrigTrc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD2TrigTrc_sec(i) (Y_DPRSMI_VXMD2TrigTrc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD2TrigTrc_sec() ((const float32*) &Y_DPRSMI_VXMD2TrigTrc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD2TrigTrc_sec

#ifndef Y_DPRSMI_VXMD3TrigDlc_met
#define Y_DPRSMI_VXMD3TrigDlc_met(i) (LCF_CommonParamData.Y_DPRSMI_VXMD3TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD3TrigDlc_met(i) (Y_DPRSMI_VXMD3TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD3TrigDlc_met() ((const float32*) &Y_DPRSMI_VXMD3TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD3TrigDlc_met

#ifndef Y_DPRSMI_VXMD3TrigDrc_met
#define Y_DPRSMI_VXMD3TrigDrc_met(i) (LCF_CommonParamData.Y_DPRSMI_VXMD3TrigDrc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD3TrigDrc_met(i) (Y_DPRSMI_VXMD3TrigDrc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD3TrigDrc_met() ((const float32*) &Y_DPRSMI_VXMD3TrigDrc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD3TrigDrc_met

#ifndef Y_DPRSMI_VXMD3TrigTlc_sec
#define Y_DPRSMI_VXMD3TrigTlc_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXMD3TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD3TrigTlc_sec(i) (Y_DPRSMI_VXMD3TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD3TrigTlc_sec() ((const float32*) &Y_DPRSMI_VXMD3TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD3TrigTlc_sec

#ifndef Y_DPRSMI_VXMD3TrigTrc_sec
#define Y_DPRSMI_VXMD3TrigTrc_sec(i) (LCF_CommonParamData.Y_DPRSMI_VXMD3TrigTrc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VXMD3TrigTrc_sec(i) (Y_DPRSMI_VXMD3TrigTrc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VXMD3TrigTrc_sec() ((const float32*) &Y_DPRSMI_VXMD3TrigTrc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VXMD3TrigTrc_sec

#ifndef Y_DPRSMI_VYTrigDlcScalFact_nu
#define Y_DPRSMI_VYTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_VYTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VYTrigDlcScalFact_nu(i) (Y_DPRSMI_VYTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VYTrigDlcScalFact_nu() ((const float32*) &Y_DPRSMI_VYTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VYTrigDlcScalFact_nu

#ifndef Y_DPRSMI_VYTrigDrcScalFact_nu
#define Y_DPRSMI_VYTrigDrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_VYTrigDrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VYTrigDrcScalFact_nu(i) (Y_DPRSMI_VYTrigDrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VYTrigDrcScalFact_nu() ((const float32*) &Y_DPRSMI_VYTrigDrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VYTrigDrcScalFact_nu

#ifndef Y_DPRSMI_VYTrigTlcScalFact_nu
#define Y_DPRSMI_VYTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_VYTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VYTrigTlcScalFact_nu(i) (Y_DPRSMI_VYTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VYTrigTlcScalFact_nu() ((const float32*) &Y_DPRSMI_VYTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VYTrigTlcScalFact_nu

#ifndef Y_DPRSMI_VYTrigTrcScalFact_nu
#define Y_DPRSMI_VYTrigTrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMI_VYTrigTrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMI_VYTrigTrcScalFact_nu(i) (Y_DPRSMI_VYTrigTrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMI_VYTrigTrcScalFact_nu() ((const float32*) &Y_DPRSMI_VYTrigTrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMI_VYTrigTrcScalFact_nu

#ifndef Y_DPRSMW_CrvICDlcOffset_met
#define Y_DPRSMW_CrvICDlcOffset_met(i) (LCF_CommonParamData.Y_DPRSMW_CrvICDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvICDlcOffset_met(i) (Y_DPRSMW_CrvICDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvICDlcOffset_met() ((const float32*) &Y_DPRSMW_CrvICDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvICDlcOffset_met

#ifndef Y_DPRSMW_CrvICDrcOffset_met
#define Y_DPRSMW_CrvICDrcOffset_met(i) (LCF_CommonParamData.Y_DPRSMW_CrvICDrcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvICDrcOffset_met(i) (Y_DPRSMW_CrvICDrcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvICDrcOffset_met() ((const float32*) &Y_DPRSMW_CrvICDrcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvICDrcOffset_met

#ifndef Y_DPRSMW_CrvICTlcOffset_sec
#define Y_DPRSMW_CrvICTlcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMW_CrvICTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvICTlcOffset_sec(i) (Y_DPRSMW_CrvICTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvICTlcOffset_sec() ((const float32*) &Y_DPRSMW_CrvICTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvICTlcOffset_sec

#ifndef Y_DPRSMW_CrvICTrcOffset_sec
#define Y_DPRSMW_CrvICTrcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMW_CrvICTrcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvICTrcOffset_sec(i) (Y_DPRSMW_CrvICTrcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvICTrcOffset_sec() ((const float32*) &Y_DPRSMW_CrvICTrcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvICTrcOffset_sec

#ifndef Y_DPRSMW_CrvOCDlcOffset_met
#define Y_DPRSMW_CrvOCDlcOffset_met(i) (LCF_CommonParamData.Y_DPRSMW_CrvOCDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvOCDlcOffset_met(i) (Y_DPRSMW_CrvOCDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvOCDlcOffset_met() ((const float32*) &Y_DPRSMW_CrvOCDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvOCDlcOffset_met

#ifndef Y_DPRSMW_CrvOCDrcOffset_met
#define Y_DPRSMW_CrvOCDrcOffset_met(i) (LCF_CommonParamData.Y_DPRSMW_CrvOCDrcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvOCDrcOffset_met(i) (Y_DPRSMW_CrvOCDrcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvOCDrcOffset_met() ((const float32*) &Y_DPRSMW_CrvOCDrcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvOCDrcOffset_met

#ifndef Y_DPRSMW_CrvOCTlcOffset_sec
#define Y_DPRSMW_CrvOCTlcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMW_CrvOCTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvOCTlcOffset_sec(i) (Y_DPRSMW_CrvOCTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvOCTlcOffset_sec() ((const float32*) &Y_DPRSMW_CrvOCTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvOCTlcOffset_sec

#ifndef Y_DPRSMW_CrvOCTrcOffset_sec
#define Y_DPRSMW_CrvOCTrcOffset_sec(i) (LCF_CommonParamData.Y_DPRSMW_CrvOCTrcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_CrvOCTrcOffset_sec(i) (Y_DPRSMW_CrvOCTrcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_CrvOCTrcOffset_sec() ((const float32*) &Y_DPRSMW_CrvOCTrcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_CrvOCTrcOffset_sec

#ifndef Y_DPRSMW_LWContrMaxDurLnScal_nu
#define Y_DPRSMW_LWContrMaxDurLnScal_nu(i) (LCF_CommonParamData.Y_DPRSMW_LWContrMaxDurLnScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWContrMaxDurLnScal_nu(i) (Y_DPRSMW_LWContrMaxDurLnScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWContrMaxDurLnScal_nu() ((const float32*) &Y_DPRSMW_LWContrMaxDurLnScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWContrMaxDurLnScal_nu

#ifndef Y_DPRSMW_LWContrMaxDurReScal_nu
#define Y_DPRSMW_LWContrMaxDurReScal_nu(i) (LCF_CommonParamData.Y_DPRSMW_LWContrMaxDurReScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWContrMaxDurReScal_nu(i) (Y_DPRSMW_LWContrMaxDurReScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWContrMaxDurReScal_nu() ((const float32*) &Y_DPRSMW_LWContrMaxDurReScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWContrMaxDurReScal_nu

#ifndef Y_DPRSMW_LWHazardFinishTol_met
#define Y_DPRSMW_LWHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPRSMW_LWHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWHazardFinishTol_met(i) (Y_DPRSMW_LWHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWHazardFinishTol_met() ((const float32*) &Y_DPRSMW_LWHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWHazardFinishTol_met

#ifndef Y_DPRSMW_LWNoHazardFinishTol_met
#define Y_DPRSMW_LWNoHazardFinishTol_met(i) (LCF_CommonParamData.Y_DPRSMW_LWNoHazardFinishTol_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWNoHazardFinishTol_met(i) (Y_DPRSMW_LWNoHazardFinishTol_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWNoHazardFinishTol_met() ((const float32*) &Y_DPRSMW_LWNoHazardFinishTol_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWNoHazardFinishTol_met

#ifndef Y_DPRSMW_LWTrigDlcScalFact_nu
#define Y_DPRSMW_LWTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_LWTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWTrigDlcScalFact_nu(i) (Y_DPRSMW_LWTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWTrigDlcScalFact_nu() ((const float32*) &Y_DPRSMW_LWTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWTrigDlcScalFact_nu

#ifndef Y_DPRSMW_LWTrigDrcScalFact_nu
#define Y_DPRSMW_LWTrigDrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_LWTrigDrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWTrigDrcScalFact_nu(i) (Y_DPRSMW_LWTrigDrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWTrigDrcScalFact_nu() ((const float32*) &Y_DPRSMW_LWTrigDrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWTrigDrcScalFact_nu

#ifndef Y_DPRSMW_LWTrigTlcScalFact_nu
#define Y_DPRSMW_LWTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_LWTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWTrigTlcScalFact_nu(i) (Y_DPRSMW_LWTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWTrigTlcScalFact_nu() ((const float32*) &Y_DPRSMW_LWTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWTrigTlcScalFact_nu

#ifndef Y_DPRSMW_LWTrigTrcScalFact_nu
#define Y_DPRSMW_LWTrigTrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_LWTrigTrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_LWTrigTrcScalFact_nu(i) (Y_DPRSMW_LWTrigTrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_LWTrigTrcScalFact_nu() ((const float32*) &Y_DPRSMW_LWTrigTrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_LWTrigTrcScalFact_nu

#ifndef Y_DPRSMW_VXContrMaxDurLn_sec
#define Y_DPRSMW_VXContrMaxDurLn_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXContrMaxDurLn_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXContrMaxDurLn_sec(i) (Y_DPRSMW_VXContrMaxDurLn_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXContrMaxDurLn_sec() ((const float32*) &Y_DPRSMW_VXContrMaxDurLn_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXContrMaxDurLn_sec

#ifndef Y_DPRSMW_VXContrMaxDurRe_sec
#define Y_DPRSMW_VXContrMaxDurRe_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXContrMaxDurRe_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXContrMaxDurRe_sec(i) (Y_DPRSMW_VXContrMaxDurRe_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXContrMaxDurRe_sec() ((const float32*) &Y_DPRSMW_VXContrMaxDurRe_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXContrMaxDurRe_sec

#ifndef Y_DPRSMW_VXMD1TrigDlc_met
#define Y_DPRSMW_VXMD1TrigDlc_met(i) (LCF_CommonParamData.Y_DPRSMW_VXMD1TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD1TrigDlc_met(i) (Y_DPRSMW_VXMD1TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD1TrigDlc_met() ((const float32*) &Y_DPRSMW_VXMD1TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD1TrigDlc_met

#ifndef Y_DPRSMW_VXMD1TrigDrc_met
#define Y_DPRSMW_VXMD1TrigDrc_met(i) (LCF_CommonParamData.Y_DPRSMW_VXMD1TrigDrc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD1TrigDrc_met(i) (Y_DPRSMW_VXMD1TrigDrc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD1TrigDrc_met() ((const float32*) &Y_DPRSMW_VXMD1TrigDrc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD1TrigDrc_met

#ifndef Y_DPRSMW_VXMD1TrigTlc_sec
#define Y_DPRSMW_VXMD1TrigTlc_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXMD1TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD1TrigTlc_sec(i) (Y_DPRSMW_VXMD1TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD1TrigTlc_sec() ((const float32*) &Y_DPRSMW_VXMD1TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD1TrigTlc_sec

#ifndef Y_DPRSMW_VXMD1TrigTrc_sec
#define Y_DPRSMW_VXMD1TrigTrc_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXMD1TrigTrc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD1TrigTrc_sec(i) (Y_DPRSMW_VXMD1TrigTrc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD1TrigTrc_sec() ((const float32*) &Y_DPRSMW_VXMD1TrigTrc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD1TrigTrc_sec

#ifndef Y_DPRSMW_VXMD2TrigDlc_met
#define Y_DPRSMW_VXMD2TrigDlc_met(i) (LCF_CommonParamData.Y_DPRSMW_VXMD2TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD2TrigDlc_met(i) (Y_DPRSMW_VXMD2TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD2TrigDlc_met() ((const float32*) &Y_DPRSMW_VXMD2TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD2TrigDlc_met

#ifndef Y_DPRSMW_VXMD2TrigDrc_met
#define Y_DPRSMW_VXMD2TrigDrc_met(i) (LCF_CommonParamData.Y_DPRSMW_VXMD2TrigDrc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD2TrigDrc_met(i) (Y_DPRSMW_VXMD2TrigDrc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD2TrigDrc_met() ((const float32*) &Y_DPRSMW_VXMD2TrigDrc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD2TrigDrc_met

#ifndef Y_DPRSMW_VXMD2TrigTlc_sec
#define Y_DPRSMW_VXMD2TrigTlc_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXMD2TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD2TrigTlc_sec(i) (Y_DPRSMW_VXMD2TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD2TrigTlc_sec() ((const float32*) &Y_DPRSMW_VXMD2TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD2TrigTlc_sec

#ifndef Y_DPRSMW_VXMD2TrigTrc_sec
#define Y_DPRSMW_VXMD2TrigTrc_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXMD2TrigTrc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD2TrigTrc_sec(i) (Y_DPRSMW_VXMD2TrigTrc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD2TrigTrc_sec() ((const float32*) &Y_DPRSMW_VXMD2TrigTrc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD2TrigTrc_sec

#ifndef Y_DPRSMW_VXMD3TrigDlc_met
#define Y_DPRSMW_VXMD3TrigDlc_met(i) (LCF_CommonParamData.Y_DPRSMW_VXMD3TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD3TrigDlc_met(i) (Y_DPRSMW_VXMD3TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD3TrigDlc_met() ((const float32*) &Y_DPRSMW_VXMD3TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD3TrigDlc_met

#ifndef Y_DPRSMW_VXMD3TrigDrc_met
#define Y_DPRSMW_VXMD3TrigDrc_met(i) (LCF_CommonParamData.Y_DPRSMW_VXMD3TrigDrc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD3TrigDrc_met(i) (Y_DPRSMW_VXMD3TrigDrc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD3TrigDrc_met() ((const float32*) &Y_DPRSMW_VXMD3TrigDrc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD3TrigDrc_met

#ifndef Y_DPRSMW_VXMD3TrigTlc_sec
#define Y_DPRSMW_VXMD3TrigTlc_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXMD3TrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD3TrigTlc_sec(i) (Y_DPRSMW_VXMD3TrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD3TrigTlc_sec() ((const float32*) &Y_DPRSMW_VXMD3TrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD3TrigTlc_sec

#ifndef Y_DPRSMW_VXMD3TrigTrc_sec
#define Y_DPRSMW_VXMD3TrigTrc_sec(i) (LCF_CommonParamData.Y_DPRSMW_VXMD3TrigTrc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VXMD3TrigTrc_sec(i) (Y_DPRSMW_VXMD3TrigTrc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VXMD3TrigTrc_sec() ((const float32*) &Y_DPRSMW_VXMD3TrigTrc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VXMD3TrigTrc_sec

#ifndef Y_DPRSMW_VYTrigDlcScalFact_nu
#define Y_DPRSMW_VYTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_VYTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VYTrigDlcScalFact_nu(i) (Y_DPRSMW_VYTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VYTrigDlcScalFact_nu() ((const float32*) &Y_DPRSMW_VYTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VYTrigDlcScalFact_nu

#ifndef Y_DPRSMW_VYTrigDrcScalFact_nu
#define Y_DPRSMW_VYTrigDrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_VYTrigDrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VYTrigDrcScalFact_nu(i) (Y_DPRSMW_VYTrigDrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VYTrigDrcScalFact_nu() ((const float32*) &Y_DPRSMW_VYTrigDrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VYTrigDrcScalFact_nu

#ifndef Y_DPRSMW_VYTrigTlcScalFact_nu
#define Y_DPRSMW_VYTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_VYTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VYTrigTlcScalFact_nu(i) (Y_DPRSMW_VYTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VYTrigTlcScalFact_nu() ((const float32*) &Y_DPRSMW_VYTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VYTrigTlcScalFact_nu

#ifndef Y_DPRSMW_VYTrigTrcScalFact_nu
#define Y_DPRSMW_VYTrigTrcScalFact_nu(i) (LCF_CommonParamData.Y_DPRSMW_VYTrigTrcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRSMW_VYTrigTrcScalFact_nu(i) (Y_DPRSMW_VYTrigTrcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRSMW_VYTrigTrcScalFact_nu() ((const float32*) &Y_DPRSMW_VYTrigTrcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRSMW_VYTrigTrcScalFact_nu

#ifndef Y_DPRTVG_CrvPlanHorizonScal_nu
#define Y_DPRTVG_CrvPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPRTVG_CrvPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_CrvPlanHorizonScal_nu(i) (Y_DPRTVG_CrvPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_CrvPlanHorizonScal_nu() ((const float32*) &Y_DPRTVG_CrvPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_CrvPlanHorizonScal_nu

#ifndef Y_DPRTVG_D2TPlanHorizonScal_nu
#define Y_DPRTVG_D2TPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPRTVG_D2TPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_D2TPlanHorizonScal_nu(i) (Y_DPRTVG_D2TPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_D2TPlanHorizonScal_nu() ((const float32*) &Y_DPRTVG_D2TPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_D2TPlanHorizonScal_nu

#ifndef Y_DPRTVG_VXPlanHorizonScal_nu
#define Y_DPRTVG_VXPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_DPRTVG_VXPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VXPlanHorizonScal_nu(i) (Y_DPRTVG_VXPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VXPlanHorizonScal_nu() ((const float32*) &Y_DPRTVG_VXPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VXPlanHorizonScal_nu

#ifndef Y_DPRTVG_VXWeightEndtime_nu
#define Y_DPRTVG_VXWeightEndtime_nu(i) (LCF_CommonParamData.Y_DPRTVG_VXWeightEndtime_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VXWeightEndtime_nu(i) (Y_DPRTVG_VXWeightEndtime_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VXWeightEndtime_nu() ((const float32*) &Y_DPRTVG_VXWeightEndtime_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VXWeightEndtime_nu

#ifndef Y_DPRTVG_VYMD1DeratingLevel_nu
#define Y_DPRTVG_VYMD1DeratingLevel_nu(i) (LCF_CommonParamData.Y_DPRTVG_VYMD1DeratingLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VYMD1DeratingLevel_nu(i) (Y_DPRTVG_VYMD1DeratingLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VYMD1DeratingLevel_nu() ((const float32*) &Y_DPRTVG_VYMD1DeratingLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VYMD1DeratingLevel_nu

#ifndef Y_DPRTVG_VYMD2DeratingLevel_nu
#define Y_DPRTVG_VYMD2DeratingLevel_nu(i) (LCF_CommonParamData.Y_DPRTVG_VYMD2DeratingLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VYMD2DeratingLevel_nu(i) (Y_DPRTVG_VYMD2DeratingLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VYMD2DeratingLevel_nu() ((const float32*) &Y_DPRTVG_VYMD2DeratingLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VYMD2DeratingLevel_nu

#ifndef Y_DPRTVG_VYMD3DeratingLevel_nu
#define Y_DPRTVG_VYMD3DeratingLevel_nu(i) (LCF_CommonParamData.Y_DPRTVG_VYMD3DeratingLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VYMD3DeratingLevel_nu(i) (Y_DPRTVG_VYMD3DeratingLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VYMD3DeratingLevel_nu() ((const float32*) &Y_DPRTVG_VYMD3DeratingLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VYMD3DeratingLevel_nu

#ifndef Y_DPRTVG_VYPlanHorizonLn_sec
#define Y_DPRTVG_VYPlanHorizonLn_sec(i) (LCF_CommonParamData.Y_DPRTVG_VYPlanHorizonLn_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VYPlanHorizonLn_sec(i) (Y_DPRTVG_VYPlanHorizonLn_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VYPlanHorizonLn_sec() ((const float32*) &Y_DPRTVG_VYPlanHorizonLn_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VYPlanHorizonLn_sec

#ifndef Y_DPRTVG_VYPlanHorizonRe_sec
#define Y_DPRTVG_VYPlanHorizonRe_sec(i) (LCF_CommonParamData.Y_DPRTVG_VYPlanHorizonRe_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VYPlanHorizonRe_sec(i) (Y_DPRTVG_VYPlanHorizonRe_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VYPlanHorizonRe_sec() ((const float32*) &Y_DPRTVG_VYPlanHorizonRe_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VYPlanHorizonRe_sec

#ifndef Y_DPRTVG_VYStrWhStifRIGrad_1ps
#define Y_DPRTVG_VYStrWhStifRIGrad_1ps(i) (LCF_CommonParamData.Y_DPRTVG_VYStrWhStifRIGrad_1ps[(i)]) //!< LCF parameter macro.
#define GET_Y_DPRTVG_VYStrWhStifRIGrad_1ps(i) (Y_DPRTVG_VYStrWhStifRIGrad_1ps(i)) //!< LCF parameter macro getter.
#define GETA_Y_DPRTVG_VYStrWhStifRIGrad_1ps() ((const float32*) &Y_DPRTVG_VYStrWhStifRIGrad_1ps(0)) //!< LCF parameter macro pointer.
#endif // Y_DPRTVG_VYStrWhStifRIGrad_1ps

#ifndef Y_DRMHOD_HandsOffTqLim_Nm
#define Y_DRMHOD_HandsOffTqLim_Nm(i) (LCF_CommonParamData.Y_DRMHOD_HandsOffTqLim_Nm[(i)]) //!< LCF parameter macro.
#define GET_Y_DRMHOD_HandsOffTqLim_Nm(i) (Y_DRMHOD_HandsOffTqLim_Nm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DRMHOD_HandsOffTqLim_Nm() ((const float32*) &Y_DRMHOD_HandsOffTqLim_Nm(0)) //!< LCF parameter macro pointer.
#endif // Y_DRMHOD_HandsOffTqLim_Nm

#ifndef Y_DRMHOD_HandsOnTqLim_Nm
#define Y_DRMHOD_HandsOnTqLim_Nm(i) (LCF_CommonParamData.Y_DRMHOD_HandsOnTqLim_Nm[(i)]) //!< LCF parameter macro.
#define GET_Y_DRMHOD_HandsOnTqLim_Nm(i) (Y_DRMHOD_HandsOnTqLim_Nm(i)) //!< LCF parameter macro getter.
#define GETA_Y_DRMHOD_HandsOnTqLim_Nm() ((const float32*) &Y_DRMHOD_HandsOnTqLim_Nm(0)) //!< LCF parameter macro pointer.
#endif // Y_DRMHOD_HandsOnTqLim_Nm

#ifndef Y_DRMHOD_VXLowPassC_nu
#define Y_DRMHOD_VXLowPassC_nu(i) (LCF_CommonParamData.Y_DRMHOD_VXLowPassC_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_DRMHOD_VXLowPassC_nu(i) (Y_DRMHOD_VXLowPassC_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_DRMHOD_VXLowPassC_nu() ((const float32*) &Y_DRMHOD_VXLowPassC_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_DRMHOD_VXLowPassC_nu

#ifndef Y_LCRSIA_VXCrvThresALCAHyst_1pm
#define Y_LCRSIA_VXCrvThresALCAHyst_1pm(i) (LCF_CommonParamData.Y_LCRSIA_VXCrvThresALCAHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSIA_VXCrvThresALCAHyst_1pm(i) (Y_LCRSIA_VXCrvThresALCAHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSIA_VXCrvThresALCAHyst_1pm() ((const float32*) &Y_LCRSIA_VXCrvThresALCAHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSIA_VXCrvThresALCAHyst_1pm

#ifndef Y_LCRSIA_VXCrvThresALCAMax_1pm
#define Y_LCRSIA_VXCrvThresALCAMax_1pm(i) (LCF_CommonParamData.Y_LCRSIA_VXCrvThresALCAMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSIA_VXCrvThresALCAMax_1pm(i) (Y_LCRSIA_VXCrvThresALCAMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSIA_VXCrvThresALCAMax_1pm() ((const float32*) &Y_LCRSIA_VXCrvThresALCAMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSIA_VXCrvThresALCAMax_1pm

#ifndef Y_LCRSIA_VXVehCrvThresHyst_1pm
#define Y_LCRSIA_VXVehCrvThresHyst_1pm(i) (LCF_CommonParamData.Y_LCRSIA_VXVehCrvThresHyst_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSIA_VXVehCrvThresHyst_1pm(i) (Y_LCRSIA_VXVehCrvThresHyst_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSIA_VXVehCrvThresHyst_1pm() ((const float32*) &Y_LCRSIA_VXVehCrvThresHyst_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSIA_VXVehCrvThresHyst_1pm

#ifndef Y_LCRSIA_VXVehCrvThresMax_1pm
#define Y_LCRSIA_VXVehCrvThresMax_1pm(i) (LCF_CommonParamData.Y_LCRSIA_VXVehCrvThresMax_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSIA_VXVehCrvThresMax_1pm(i) (Y_LCRSIA_VXVehCrvThresMax_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSIA_VXVehCrvThresMax_1pm() ((const float32*) &Y_LCRSIA_VXVehCrvThresMax_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSIA_VXVehCrvThresMax_1pm

#ifndef Y_LCRSMI_CrvICDlcOffset_met
#define Y_LCRSMI_CrvICDlcOffset_met(i) (LCF_CommonParamData.Y_LCRSMI_CrvICDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_CrvICDlcOffset_met(i) (Y_LCRSMI_CrvICDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_CrvICDlcOffset_met() ((const float32*) &Y_LCRSMI_CrvICDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_CrvICDlcOffset_met

#ifndef Y_LCRSMI_CrvICTlcOffset_sec
#define Y_LCRSMI_CrvICTlcOffset_sec(i) (LCF_CommonParamData.Y_LCRSMI_CrvICTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_CrvICTlcOffset_sec(i) (Y_LCRSMI_CrvICTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_CrvICTlcOffset_sec() ((const float32*) &Y_LCRSMI_CrvICTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_CrvICTlcOffset_sec

#ifndef Y_LCRSMI_CrvOCDlcOffset_met
#define Y_LCRSMI_CrvOCDlcOffset_met(i) (LCF_CommonParamData.Y_LCRSMI_CrvOCDlcOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_CrvOCDlcOffset_met(i) (Y_LCRSMI_CrvOCDlcOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_CrvOCDlcOffset_met() ((const float32*) &Y_LCRSMI_CrvOCDlcOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_CrvOCDlcOffset_met

#ifndef Y_LCRSMI_CrvOCTlcOffset_sec
#define Y_LCRSMI_CrvOCTlcOffset_sec(i) (LCF_CommonParamData.Y_LCRSMI_CrvOCTlcOffset_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_CrvOCTlcOffset_sec(i) (Y_LCRSMI_CrvOCTlcOffset_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_CrvOCTlcOffset_sec() ((const float32*) &Y_LCRSMI_CrvOCTlcOffset_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_CrvOCTlcOffset_sec

#ifndef Y_LCRSMI_LWTrigDlcScalFact_nu
#define Y_LCRSMI_LWTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_LCRSMI_LWTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_LWTrigDlcScalFact_nu(i) (Y_LCRSMI_LWTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_LWTrigDlcScalFact_nu() ((const float32*) &Y_LCRSMI_LWTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_LWTrigDlcScalFact_nu

#ifndef Y_LCRSMI_LWTrigTlcScalFact_nu
#define Y_LCRSMI_LWTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_LCRSMI_LWTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_LWTrigTlcScalFact_nu(i) (Y_LCRSMI_LWTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_LWTrigTlcScalFact_nu() ((const float32*) &Y_LCRSMI_LWTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_LWTrigTlcScalFact_nu

#ifndef Y_LCRSMI_VXMD1TrigDlc_met
#define Y_LCRSMI_VXMD1TrigDlc_met(i) (LCF_CommonParamData.Y_LCRSMI_VXMD1TrigDlc_met[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_VXMD1TrigDlc_met(i) (Y_LCRSMI_VXMD1TrigDlc_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_VXMD1TrigDlc_met() ((const float32*) &Y_LCRSMI_VXMD1TrigDlc_met(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_VXMD1TrigDlc_met

#ifndef Y_LCRSMI_VXTrigTlc_sec
#define Y_LCRSMI_VXTrigTlc_sec(i) (LCF_CommonParamData.Y_LCRSMI_VXTrigTlc_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_VXTrigTlc_sec(i) (Y_LCRSMI_VXTrigTlc_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_VXTrigTlc_sec() ((const float32*) &Y_LCRSMI_VXTrigTlc_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_VXTrigTlc_sec

#ifndef Y_LCRSMI_VYTrigDlcScalFact_nu
#define Y_LCRSMI_VYTrigDlcScalFact_nu(i) (LCF_CommonParamData.Y_LCRSMI_VYTrigDlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_VYTrigDlcScalFact_nu(i) (Y_LCRSMI_VYTrigDlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_VYTrigDlcScalFact_nu() ((const float32*) &Y_LCRSMI_VYTrigDlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_VYTrigDlcScalFact_nu

#ifndef Y_LCRSMI_VYTrigTlcScalFact_nu
#define Y_LCRSMI_VYTrigTlcScalFact_nu(i) (LCF_CommonParamData.Y_LCRSMI_VYTrigTlcScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRSMI_VYTrigTlcScalFact_nu(i) (Y_LCRSMI_VYTrigTlcScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRSMI_VYTrigTlcScalFact_nu() ((const float32*) &Y_LCRSMI_VYTrigTlcScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRSMI_VYTrigTlcScalFact_nu

#ifndef Y_LCRTTG_CrvICTgtOffset_met
#define Y_LCRTTG_CrvICTgtOffset_met(i) (LCF_CommonParamData.Y_LCRTTG_CrvICTgtOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTTG_CrvICTgtOffset_met(i) (Y_LCRTTG_CrvICTgtOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTTG_CrvICTgtOffset_met() ((const float32*) &Y_LCRTTG_CrvICTgtOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTTG_CrvICTgtOffset_met

#ifndef Y_LCRTTG_CrvOCTgtOffset_met
#define Y_LCRTTG_CrvOCTgtOffset_met(i) (LCF_CommonParamData.Y_LCRTTG_CrvOCTgtOffset_met[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTTG_CrvOCTgtOffset_met(i) (Y_LCRTTG_CrvOCTgtOffset_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTTG_CrvOCTgtOffset_met() ((const float32*) &Y_LCRTTG_CrvOCTgtOffset_met(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTTG_CrvOCTgtOffset_met

#ifndef Y_LCRTTG_LWTargetLatDist_met
#define Y_LCRTTG_LWTargetLatDist_met(i) (LCF_CommonParamData.Y_LCRTTG_LWTargetLatDist_met[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTTG_LWTargetLatDist_met(i) (Y_LCRTTG_LWTargetLatDist_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTTG_LWTargetLatDist_met() ((const float32*) &Y_LCRTTG_LWTargetLatDist_met(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTTG_LWTargetLatDist_met

#ifndef Y_LCRTVG_CrvICPlanHorizonScal_nu
#define Y_LCRTVG_CrvICPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_LCRTVG_CrvICPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_CrvICPlanHorizonScal_nu(i) (Y_LCRTVG_CrvICPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_CrvICPlanHorizonScal_nu() ((const float32*) &Y_LCRTVG_CrvICPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_CrvICPlanHorizonScal_nu

#ifndef Y_LCRTVG_CrvOCPlanHorizonScal_nu
#define Y_LCRTVG_CrvOCPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_LCRTVG_CrvOCPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_CrvOCPlanHorizonScal_nu(i) (Y_LCRTVG_CrvOCPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_CrvOCPlanHorizonScal_nu() ((const float32*) &Y_LCRTVG_CrvOCPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_CrvOCPlanHorizonScal_nu

#ifndef Y_LCRTVG_D2TPlanHorizonScal_nu
#define Y_LCRTVG_D2TPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_LCRTVG_D2TPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_D2TPlanHorizonScal_nu(i) (Y_LCRTVG_D2TPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_D2TPlanHorizonScal_nu() ((const float32*) &Y_LCRTVG_D2TPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_D2TPlanHorizonScal_nu

#ifndef Y_LCRTVG_VXPlanHorizonScal_nu
#define Y_LCRTVG_VXPlanHorizonScal_nu(i) (LCF_CommonParamData.Y_LCRTVG_VXPlanHorizonScal_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VXPlanHorizonScal_nu(i) (Y_LCRTVG_VXPlanHorizonScal_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VXPlanHorizonScal_nu() ((const float32*) &Y_LCRTVG_VXPlanHorizonScal_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VXPlanHorizonScal_nu

#ifndef Y_LCRTVG_VXWeightEndtime_nu
#define Y_LCRTVG_VXWeightEndtime_nu(i) (LCF_CommonParamData.Y_LCRTVG_VXWeightEndtime_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VXWeightEndtime_nu(i) (Y_LCRTVG_VXWeightEndtime_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VXWeightEndtime_nu() ((const float32*) &Y_LCRTVG_VXWeightEndtime_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VXWeightEndtime_nu

#ifndef Y_LCRTVG_VYMD1DerLevel_nu
#define Y_LCRTVG_VYMD1DerLevel_nu(i) (LCF_CommonParamData.Y_LCRTVG_VYMD1DerLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VYMD1DerLevel_nu(i) (Y_LCRTVG_VYMD1DerLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VYMD1DerLevel_nu() ((const float32*) &Y_LCRTVG_VYMD1DerLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VYMD1DerLevel_nu

#ifndef Y_LCRTVG_VYMD2DerLevel_nu
#define Y_LCRTVG_VYMD2DerLevel_nu(i) (LCF_CommonParamData.Y_LCRTVG_VYMD2DerLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VYMD2DerLevel_nu(i) (Y_LCRTVG_VYMD2DerLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VYMD2DerLevel_nu() ((const float32*) &Y_LCRTVG_VYMD2DerLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VYMD2DerLevel_nu

#ifndef Y_LCRTVG_VYMD3DerLevel_nu
#define Y_LCRTVG_VYMD3DerLevel_nu(i) (LCF_CommonParamData.Y_LCRTVG_VYMD3DerLevel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VYMD3DerLevel_nu(i) (Y_LCRTVG_VYMD3DerLevel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VYMD3DerLevel_nu() ((const float32*) &Y_LCRTVG_VYMD3DerLevel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VYMD3DerLevel_nu

#ifndef Y_LCRTVG_VYPlanningHorizon_sec
#define Y_LCRTVG_VYPlanningHorizon_sec(i) (LCF_CommonParamData.Y_LCRTVG_VYPlanningHorizon_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VYPlanningHorizon_sec(i) (Y_LCRTVG_VYPlanningHorizon_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VYPlanningHorizon_sec() ((const float32*) &Y_LCRTVG_VYPlanningHorizon_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VYPlanningHorizon_sec

#ifndef Y_LCRTVG_VYStrWhStifRIGrad_1ps
#define Y_LCRTVG_VYStrWhStifRIGrad_1ps(i) (LCF_CommonParamData.Y_LCRTVG_VYStrWhStifRIGrad_1ps[(i)]) //!< LCF parameter macro.
#define GET_Y_LCRTVG_VYStrWhStifRIGrad_1ps(i) (Y_LCRTVG_VYStrWhStifRIGrad_1ps(i)) //!< LCF parameter macro getter.
#define GETA_Y_LCRTVG_VYStrWhStifRIGrad_1ps() ((const float32*) &Y_LCRTVG_VYStrWhStifRIGrad_1ps(0)) //!< LCF parameter macro pointer.
#endif // Y_LCRTVG_VYStrWhStifRIGrad_1ps

#ifndef Y_ODPFOH_LSMPT1TimePosY_sec
#define Y_ODPFOH_LSMPT1TimePosY_sec(i) (LCF_CommonParamData.Y_ODPFOH_LSMPT1TimePosY_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_LSMPT1TimePosY_sec(i) (Y_ODPFOH_LSMPT1TimePosY_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_LSMPT1TimePosY_sec() ((const float32*) &Y_ODPFOH_LSMPT1TimePosY_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_LSMPT1TimePosY_sec

#ifndef Y_ODPFOH_MaxObjDistLSM_met
#define Y_ODPFOH_MaxObjDistLSM_met(i) (LCF_CommonParamData.Y_ODPFOH_MaxObjDistLSM_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_MaxObjDistLSM_met(i) (Y_ODPFOH_MaxObjDistLSM_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_MaxObjDistLSM_met() ((const float32*) &Y_ODPFOH_MaxObjDistLSM_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_MaxObjDistLSM_met

#ifndef Y_ODPFOH_MaxSampleAge_sec
#define Y_ODPFOH_MaxSampleAge_sec(i) (LCF_CommonParamData.Y_ODPFOH_MaxSampleAge_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_MaxSampleAge_sec(i) (Y_ODPFOH_MaxSampleAge_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_MaxSampleAge_sec() ((const float32*) &Y_ODPFOH_MaxSampleAge_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_MaxSampleAge_sec

#ifndef Y_ODPFOH_MinTrajectoryLength_met
#define Y_ODPFOH_MinTrajectoryLength_met(i) (LCF_CommonParamData.Y_ODPFOH_MinTrajectoryLength_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_MinTrajectoryLength_met(i) (Y_ODPFOH_MinTrajectoryLength_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_MinTrajectoryLength_met() ((const float32*) &Y_ODPFOH_MinTrajectoryLength_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_MinTrajectoryLength_met

#ifndef Y_ODPFOH_PT1StrEstCrv_sec
#define Y_ODPFOH_PT1StrEstCrv_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1StrEstCrv_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1StrEstCrv_sec(i) (Y_ODPFOH_PT1StrEstCrv_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1StrEstCrv_sec() ((const float32*) &Y_ODPFOH_PT1StrEstCrv_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1StrEstCrv_sec

#ifndef Y_ODPFOH_PT1StrEstHead_sec
#define Y_ODPFOH_PT1StrEstHead_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1StrEstHead_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1StrEstHead_sec(i) (Y_ODPFOH_PT1StrEstHead_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1StrEstHead_sec() ((const float32*) &Y_ODPFOH_PT1StrEstHead_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1StrEstHead_sec

#ifndef Y_ODPFOH_PT1StrEstPosY0_sec
#define Y_ODPFOH_PT1StrEstPosY0_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1StrEstPosY0_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1StrEstPosY0_sec(i) (Y_ODPFOH_PT1StrEstPosY0_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1StrEstPosY0_sec() ((const float32*) &Y_ODPFOH_PT1StrEstPosY0_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1StrEstPosY0_sec

#ifndef Y_ODPFOH_PT1TimeConstCrv_sec
#define Y_ODPFOH_PT1TimeConstCrv_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1TimeConstCrv_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1TimeConstCrv_sec(i) (Y_ODPFOH_PT1TimeConstCrv_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1TimeConstCrv_sec() ((const float32*) &Y_ODPFOH_PT1TimeConstCrv_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1TimeConstCrv_sec

#ifndef Y_ODPFOH_PT1TimeConstHead_sec
#define Y_ODPFOH_PT1TimeConstHead_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1TimeConstHead_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1TimeConstHead_sec(i) (Y_ODPFOH_PT1TimeConstHead_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1TimeConstHead_sec() ((const float32*) &Y_ODPFOH_PT1TimeConstHead_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1TimeConstHead_sec

#ifndef Y_ODPFOH_PT1TimeConstPosY0_sec
#define Y_ODPFOH_PT1TimeConstPosY0_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1TimeConstPosY0_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1TimeConstPosY0_sec(i) (Y_ODPFOH_PT1TimeConstPosY0_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1TimeConstPosY0_sec() ((const float32*) &Y_ODPFOH_PT1TimeConstPosY0_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1TimeConstPosY0_sec

#ifndef Y_ODPFOH_PT1TimeConstPosY_sec
#define Y_ODPFOH_PT1TimeConstPosY_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1TimeConstPosY_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1TimeConstPosY_sec(i) (Y_ODPFOH_PT1TimeConstPosY_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1TimeConstPosY_sec() ((const float32*) &Y_ODPFOH_PT1TimeConstPosY_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1TimeConstPosY_sec

#ifndef Y_ODPFOH_PT1TimeConstYawRate_sec
#define Y_ODPFOH_PT1TimeConstYawRate_sec(i) (LCF_CommonParamData.Y_ODPFOH_PT1TimeConstYawRate_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_PT1TimeConstYawRate_sec(i) (Y_ODPFOH_PT1TimeConstYawRate_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_PT1TimeConstYawRate_sec() ((const float32*) &Y_ODPFOH_PT1TimeConstYawRate_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_PT1TimeConstYawRate_sec

#ifndef Y_ODPFOH_WeightCrvPolyfit_nu
#define Y_ODPFOH_WeightCrvPolyfit_nu(i) (LCF_CommonParamData.Y_ODPFOH_WeightCrvPolyfit_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_WeightCrvPolyfit_nu(i) (Y_ODPFOH_WeightCrvPolyfit_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_WeightCrvPolyfit_nu() ((const float32*) &Y_ODPFOH_WeightCrvPolyfit_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_WeightCrvPolyfit_nu

#ifndef Y_ODPFOH_WeightLastPolyfit_nu
#define Y_ODPFOH_WeightLastPolyfit_nu(i) (LCF_CommonParamData.Y_ODPFOH_WeightLastPolyfit_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOH_WeightLastPolyfit_nu(i) (Y_ODPFOH_WeightLastPolyfit_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOH_WeightLastPolyfit_nu() ((const float32*) &Y_ODPFOH_WeightLastPolyfit_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOH_WeightLastPolyfit_nu

#ifndef Y_ODPFOP_LongDistMax_met
#define Y_ODPFOP_LongDistMax_met(i) (LCF_CommonParamData.Y_ODPFOP_LongDistMax_met[(i)]) //!< LCF parameter macro.
#define GET_Y_ODPFOP_LongDistMax_met(i) (Y_ODPFOP_LongDistMax_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_ODPFOP_LongDistMax_met() ((const float32*) &Y_ODPFOP_LongDistMax_met(0)) //!< LCF parameter macro pointer.
#endif // Y_ODPFOP_LongDistMax_met

#ifndef Y_TCTCLM_GrdLimitDeltaFCmd_deg
#define Y_TCTCLM_GrdLimitDeltaFCmd_deg(i) (LCF_CommonParamData.Y_TCTCLM_GrdLimitDeltaFCmd_deg[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_GrdLimitDeltaFCmd_deg(i) (Y_TCTCLM_GrdLimitDeltaFCmd_deg(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_GrdLimitDeltaFCmd_deg() ((const float32*) &Y_TCTCLM_GrdLimitDeltaFCmd_deg(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_GrdLimitDeltaFCmd_deg

#ifndef Y_TCTCLM_GrdLimitFbcDc_1pms
#define Y_TCTCLM_GrdLimitFbcDc_1pms(i) (LCF_CommonParamData.Y_TCTCLM_GrdLimitFbcDc_1pms[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_GrdLimitFbcDc_1pms(i) (Y_TCTCLM_GrdLimitFbcDc_1pms(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_GrdLimitFbcDc_1pms() ((const float32*) &Y_TCTCLM_GrdLimitFbcDc_1pms(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_GrdLimitFbcDc_1pms

#ifndef Y_TCTCLM_GrdLimitFfc_1pms
#define Y_TCTCLM_GrdLimitFfc_1pms(i) (LCF_CommonParamData.Y_TCTCLM_GrdLimitFfc_1pms[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_GrdLimitFfc_1pms(i) (Y_TCTCLM_GrdLimitFfc_1pms(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_GrdLimitFfc_1pms() ((const float32*) &Y_TCTCLM_GrdLimitFfc_1pms(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_GrdLimitFfc_1pms

#ifndef Y_TCTCLM_GrdLimitGain_nu
#define Y_TCTCLM_GrdLimitGain_nu(i) (LCF_CommonParamData.Y_TCTCLM_GrdLimitGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_GrdLimitGain_nu(i) (Y_TCTCLM_GrdLimitGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_GrdLimitGain_nu() ((const float32*) &Y_TCTCLM_GrdLimitGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_GrdLimitGain_nu

#ifndef Y_TCTCLM_LimitDeltaFCmd_deg
#define Y_TCTCLM_LimitDeltaFCmd_deg(i) (LCF_CommonParamData.Y_TCTCLM_LimitDeltaFCmd_deg[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_LimitDeltaFCmd_deg(i) (Y_TCTCLM_LimitDeltaFCmd_deg(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_LimitDeltaFCmd_deg() ((const float32*) &Y_TCTCLM_LimitDeltaFCmd_deg(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_LimitDeltaFCmd_deg

#ifndef Y_TCTCLM_LimitFbcDc_1pm
#define Y_TCTCLM_LimitFbcDc_1pm(i) (LCF_CommonParamData.Y_TCTCLM_LimitFbcDc_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_LimitFbcDc_1pm(i) (Y_TCTCLM_LimitFbcDc_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_LimitFbcDc_1pm() ((const float32*) &Y_TCTCLM_LimitFbcDc_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_LimitFbcDc_1pm

#ifndef Y_TCTCLM_LimitFfc_1pm
#define Y_TCTCLM_LimitFfc_1pm(i) (LCF_CommonParamData.Y_TCTCLM_LimitFfc_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_LimitFfc_1pm(i) (Y_TCTCLM_LimitFfc_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_LimitFfc_1pm() ((const float32*) &Y_TCTCLM_LimitFfc_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_LimitFfc_1pm

#ifndef Y_TCTCLM_LimitGain_nu
#define Y_TCTCLM_LimitGain_nu(i) (LCF_CommonParamData.Y_TCTCLM_LimitGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTCLM_LimitGain_nu(i) (Y_TCTCLM_LimitGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTCLM_LimitGain_nu() ((const float32*) &Y_TCTCLM_LimitGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTCLM_LimitGain_nu

#ifndef Y_TCTDTE_CroWindDeltaSetSat_rad
#define Y_TCTDTE_CroWindDeltaSetSat_rad(i) (LCF_CommonParamData.Y_TCTDTE_CroWindDeltaSetSat_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_CroWindDeltaSetSat_rad(i) (Y_TCTDTE_CroWindDeltaSetSat_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_CroWindDeltaSetSat_rad() ((const float32*) &Y_TCTDTE_CroWindDeltaSetSat_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_CroWindDeltaSetSat_rad

#ifndef Y_TCTDTE_DeltaSetBnkAglSat_rad
#define Y_TCTDTE_DeltaSetBnkAglSat_rad(i) (LCF_CommonParamData.Y_TCTDTE_DeltaSetBnkAglSat_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_DeltaSetBnkAglSat_rad(i) (Y_TCTDTE_DeltaSetBnkAglSat_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_DeltaSetBnkAglSat_rad() ((const float32*) &Y_TCTDTE_DeltaSetBnkAglSat_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_DeltaSetBnkAglSat_rad

#ifndef Y_TCTDTE_DeltaSetDstrbGain_nu
#define Y_TCTDTE_DeltaSetDstrbGain_nu(i) (LCF_CommonParamData.Y_TCTDTE_DeltaSetDstrbGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_DeltaSetDstrbGain_nu(i) (Y_TCTDTE_DeltaSetDstrbGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_DeltaSetDstrbGain_nu() ((const float32*) &Y_TCTDTE_DeltaSetDstrbGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_DeltaSetDstrbGain_nu

#ifndef Y_TCTDTE_DeltaSetDstrbSat_rad
#define Y_TCTDTE_DeltaSetDstrbSat_rad(i) (LCF_CommonParamData.Y_TCTDTE_DeltaSetDstrbSat_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_DeltaSetDstrbSat_rad(i) (Y_TCTDTE_DeltaSetDstrbSat_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_DeltaSetDstrbSat_rad() ((const float32*) &Y_TCTDTE_DeltaSetDstrbSat_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_DeltaSetDstrbSat_rad

#ifndef Y_TCTDTE_GLaDmcDenS0_nu
#define Y_TCTDTE_GLaDmcDenS0_nu(i) (LCF_CommonParamData.Y_TCTDTE_GLaDmcDenS0_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GLaDmcDenS0_nu(i) (Y_TCTDTE_GLaDmcDenS0_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GLaDmcDenS0_nu() ((const float32*) &Y_TCTDTE_GLaDmcDenS0_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GLaDmcDenS0_nu

#ifndef Y_TCTDTE_GLaDmcDenS1_nu
#define Y_TCTDTE_GLaDmcDenS1_nu(i) (LCF_CommonParamData.Y_TCTDTE_GLaDmcDenS1_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GLaDmcDenS1_nu(i) (Y_TCTDTE_GLaDmcDenS1_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GLaDmcDenS1_nu() ((const float32*) &Y_TCTDTE_GLaDmcDenS1_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GLaDmcDenS1_nu

#ifndef Y_TCTDTE_GLaDmcDenS2_nu
#define Y_TCTDTE_GLaDmcDenS2_nu(i) (LCF_CommonParamData.Y_TCTDTE_GLaDmcDenS2_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GLaDmcDenS2_nu(i) (Y_TCTDTE_GLaDmcDenS2_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GLaDmcDenS2_nu() ((const float32*) &Y_TCTDTE_GLaDmcDenS2_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GLaDmcDenS2_nu

#ifndef Y_TCTDTE_GLaDmcDenS3_nu
#define Y_TCTDTE_GLaDmcDenS3_nu(i) (LCF_CommonParamData.Y_TCTDTE_GLaDmcDenS3_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GLaDmcDenS3_nu(i) (Y_TCTDTE_GLaDmcDenS3_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GLaDmcDenS3_nu() ((const float32*) &Y_TCTDTE_GLaDmcDenS3_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GLaDmcDenS3_nu

#ifndef Y_TCTDTE_GLaDmcNumS0_nu
#define Y_TCTDTE_GLaDmcNumS0_nu(i) (LCF_CommonParamData.Y_TCTDTE_GLaDmcNumS0_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GLaDmcNumS0_nu(i) (Y_TCTDTE_GLaDmcNumS0_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GLaDmcNumS0_nu() ((const float32*) &Y_TCTDTE_GLaDmcNumS0_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GLaDmcNumS0_nu

#ifndef Y_TCTDTE_GLaDmcNumS1_nu
#define Y_TCTDTE_GLaDmcNumS1_nu(i) (LCF_CommonParamData.Y_TCTDTE_GLaDmcNumS1_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GLaDmcNumS1_nu(i) (Y_TCTDTE_GLaDmcNumS1_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GLaDmcNumS1_nu() ((const float32*) &Y_TCTDTE_GLaDmcNumS1_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GLaDmcNumS1_nu

#ifndef Y_TCTDTE_GainKappaDstrbReq_nu
#define Y_TCTDTE_GainKappaDstrbReq_nu(i) (LCF_CommonParamData.Y_TCTDTE_GainKappaDstrbReq_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_GainKappaDstrbReq_nu(i) (Y_TCTDTE_GainKappaDstrbReq_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_GainKappaDstrbReq_nu() ((const float32*) &Y_TCTDTE_GainKappaDstrbReq_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_GainKappaDstrbReq_nu

#ifndef Y_TCTDTE_KappaAngle_degm
#define Y_TCTDTE_KappaAngle_degm(i) (LCF_CommonParamData.Y_TCTDTE_KappaAngle_degm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_KappaAngle_degm(i) (Y_TCTDTE_KappaAngle_degm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_KappaAngle_degm() ((const float32*) &Y_TCTDTE_KappaAngle_degm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_KappaAngle_degm

#ifndef Y_TCTDTE_VelXToMaxCrv_1pm
#define Y_TCTDTE_VelXToMaxCrv_1pm(i) (LCF_CommonParamData.Y_TCTDTE_VelXToMaxCrv_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTDTE_VelXToMaxCrv_1pm(i) (Y_TCTDTE_VelXToMaxCrv_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTDTE_VelXToMaxCrv_1pm() ((const float32*) &Y_TCTDTE_VelXToMaxCrv_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTDTE_VelXToMaxCrv_1pm

#ifndef Y_TCTEST_CrObsLueGain11_nu
#define Y_TCTEST_CrObsLueGain11_nu(i) (LCF_CommonParamData.Y_TCTEST_CrObsLueGain11_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_CrObsLueGain11_nu(i) (Y_TCTEST_CrObsLueGain11_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_CrObsLueGain11_nu() ((const float32*) &Y_TCTEST_CrObsLueGain11_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_CrObsLueGain11_nu

#ifndef Y_TCTEST_CrObsLueGain12_nu
#define Y_TCTEST_CrObsLueGain12_nu(i) (LCF_CommonParamData.Y_TCTEST_CrObsLueGain12_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_CrObsLueGain12_nu(i) (Y_TCTEST_CrObsLueGain12_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_CrObsLueGain12_nu() ((const float32*) &Y_TCTEST_CrObsLueGain12_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_CrObsLueGain12_nu

#ifndef Y_TCTEST_CrObsLueGain21_nu
#define Y_TCTEST_CrObsLueGain21_nu(i) (LCF_CommonParamData.Y_TCTEST_CrObsLueGain21_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_CrObsLueGain21_nu(i) (Y_TCTEST_CrObsLueGain21_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_CrObsLueGain21_nu() ((const float32*) &Y_TCTEST_CrObsLueGain21_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_CrObsLueGain21_nu

#ifndef Y_TCTEST_CrObsLueGain22_nu
#define Y_TCTEST_CrObsLueGain22_nu(i) (LCF_CommonParamData.Y_TCTEST_CrObsLueGain22_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_CrObsLueGain22_nu(i) (Y_TCTEST_CrObsLueGain22_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_CrObsLueGain22_nu() ((const float32*) &Y_TCTEST_CrObsLueGain22_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_CrObsLueGain22_nu

#ifndef Y_TCTEST_CrObsLueGain31_nu
#define Y_TCTEST_CrObsLueGain31_nu(i) (LCF_CommonParamData.Y_TCTEST_CrObsLueGain31_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_CrObsLueGain31_nu(i) (Y_TCTEST_CrObsLueGain31_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_CrObsLueGain31_nu() ((const float32*) &Y_TCTEST_CrObsLueGain31_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_CrObsLueGain31_nu

#ifndef Y_TCTEST_CrObsLueGain32_nu
#define Y_TCTEST_CrObsLueGain32_nu(i) (LCF_CommonParamData.Y_TCTEST_CrObsLueGain32_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_CrObsLueGain32_nu(i) (Y_TCTEST_CrObsLueGain32_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_CrObsLueGain32_nu() ((const float32*) &Y_TCTEST_CrObsLueGain32_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_CrObsLueGain32_nu

#ifndef Y_TCTEST_HdrMeanThreshOf_perc
#define Y_TCTEST_HdrMeanThreshOf_perc(i) (LCF_CommonParamData.Y_TCTEST_HdrMeanThreshOf_perc[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_HdrMeanThreshOf_perc(i) (Y_TCTEST_HdrMeanThreshOf_perc(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_HdrMeanThreshOf_perc() ((const float32*) &Y_TCTEST_HdrMeanThreshOf_perc(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_HdrMeanThreshOf_perc

#ifndef Y_TCTEST_HdrMeanThreshSf_perc
#define Y_TCTEST_HdrMeanThreshSf_perc(i) (LCF_CommonParamData.Y_TCTEST_HdrMeanThreshSf_perc[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_HdrMeanThreshSf_perc(i) (Y_TCTEST_HdrMeanThreshSf_perc(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_HdrMeanThreshSf_perc() ((const float32*) &Y_TCTEST_HdrMeanThreshSf_perc(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_HdrMeanThreshSf_perc

#ifndef Y_TCTEST_HdrMeanThresh_perc
#define Y_TCTEST_HdrMeanThresh_perc(i) (LCF_CommonParamData.Y_TCTEST_HdrMeanThresh_perc[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_HdrMeanThresh_perc(i) (Y_TCTEST_HdrMeanThresh_perc(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_HdrMeanThresh_perc() ((const float32*) &Y_TCTEST_HdrMeanThresh_perc(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_HdrMeanThresh_perc

#ifndef Y_TCTEST_HdrMulThreshOf_perc
#define Y_TCTEST_HdrMulThreshOf_perc(i) (LCF_CommonParamData.Y_TCTEST_HdrMulThreshOf_perc[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_HdrMulThreshOf_perc(i) (Y_TCTEST_HdrMulThreshOf_perc(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_HdrMulThreshOf_perc() ((const float32*) &Y_TCTEST_HdrMulThreshOf_perc(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_HdrMulThreshOf_perc

#ifndef Y_TCTEST_HdrMulThreshSf_perc
#define Y_TCTEST_HdrMulThreshSf_perc(i) (LCF_CommonParamData.Y_TCTEST_HdrMulThreshSf_perc[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_HdrMulThreshSf_perc(i) (Y_TCTEST_HdrMulThreshSf_perc(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_HdrMulThreshSf_perc() ((const float32*) &Y_TCTEST_HdrMulThreshSf_perc(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_HdrMulThreshSf_perc

#ifndef Y_TCTEST_HdrMulThresh_perc
#define Y_TCTEST_HdrMulThresh_perc(i) (LCF_CommonParamData.Y_TCTEST_HdrMulThresh_perc[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_HdrMulThresh_perc(i) (Y_TCTEST_HdrMulThresh_perc(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_HdrMulThresh_perc() ((const float32*) &Y_TCTEST_HdrMulThresh_perc(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_HdrMulThresh_perc

#ifndef Y_TCTEST_KObsLueGain11_nu
#define Y_TCTEST_KObsLueGain11_nu(i) (LCF_CommonParamData.Y_TCTEST_KObsLueGain11_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_KObsLueGain11_nu(i) (Y_TCTEST_KObsLueGain11_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_KObsLueGain11_nu() ((const float32*) &Y_TCTEST_KObsLueGain11_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_KObsLueGain11_nu

#ifndef Y_TCTEST_KObsLueGain21_nu
#define Y_TCTEST_KObsLueGain21_nu(i) (LCF_CommonParamData.Y_TCTEST_KObsLueGain21_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_KObsLueGain21_nu(i) (Y_TCTEST_KObsLueGain21_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_KObsLueGain21_nu() ((const float32*) &Y_TCTEST_KObsLueGain21_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_KObsLueGain21_nu

#ifndef Y_TCTEST_KObsLueGain31_nu
#define Y_TCTEST_KObsLueGain31_nu(i) (LCF_CommonParamData.Y_TCTEST_KObsLueGain31_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_KObsLueGain31_nu(i) (Y_TCTEST_KObsLueGain31_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_KObsLueGain31_nu() ((const float32*) &Y_TCTEST_KObsLueGain31_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_KObsLueGain31_nu

#ifndef Y_TCTEST_PlObsDeltaThetaSat_rad
#define Y_TCTEST_PlObsDeltaThetaSat_rad(i) (LCF_CommonParamData.Y_TCTEST_PlObsDeltaThetaSat_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsDeltaThetaSat_rad(i) (Y_TCTEST_PlObsDeltaThetaSat_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsDeltaThetaSat_rad() ((const float32*) &Y_TCTEST_PlObsDeltaThetaSat_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsDeltaThetaSat_rad

#ifndef Y_TCTEST_PlObsDeltaYSat_m
#define Y_TCTEST_PlObsDeltaYSat_m(i) (LCF_CommonParamData.Y_TCTEST_PlObsDeltaYSat_m[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsDeltaYSat_m(i) (Y_TCTEST_PlObsDeltaYSat_m(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsDeltaYSat_m() ((const float32*) &Y_TCTEST_PlObsDeltaYSat_m(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsDeltaYSat_m

#ifndef Y_TCTEST_PlObsLueGain11_nu
#define Y_TCTEST_PlObsLueGain11_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain11_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain11_nu(i) (Y_TCTEST_PlObsLueGain11_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain11_nu() ((const float32*) &Y_TCTEST_PlObsLueGain11_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain11_nu

#ifndef Y_TCTEST_PlObsLueGain12_nu
#define Y_TCTEST_PlObsLueGain12_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain12_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain12_nu(i) (Y_TCTEST_PlObsLueGain12_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain12_nu() ((const float32*) &Y_TCTEST_PlObsLueGain12_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain12_nu

#ifndef Y_TCTEST_PlObsLueGain13_nu
#define Y_TCTEST_PlObsLueGain13_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain13_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain13_nu(i) (Y_TCTEST_PlObsLueGain13_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain13_nu() ((const float32*) &Y_TCTEST_PlObsLueGain13_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain13_nu

#ifndef Y_TCTEST_PlObsLueGain21_nu
#define Y_TCTEST_PlObsLueGain21_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain21_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain21_nu(i) (Y_TCTEST_PlObsLueGain21_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain21_nu() ((const float32*) &Y_TCTEST_PlObsLueGain21_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain21_nu

#ifndef Y_TCTEST_PlObsLueGain22_nu
#define Y_TCTEST_PlObsLueGain22_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain22_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain22_nu(i) (Y_TCTEST_PlObsLueGain22_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain22_nu() ((const float32*) &Y_TCTEST_PlObsLueGain22_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain22_nu

#ifndef Y_TCTEST_PlObsLueGain23_nu
#define Y_TCTEST_PlObsLueGain23_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain23_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain23_nu(i) (Y_TCTEST_PlObsLueGain23_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain23_nu() ((const float32*) &Y_TCTEST_PlObsLueGain23_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain23_nu

#ifndef Y_TCTEST_PlObsLueGain31_nu
#define Y_TCTEST_PlObsLueGain31_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain31_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain31_nu(i) (Y_TCTEST_PlObsLueGain31_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain31_nu() ((const float32*) &Y_TCTEST_PlObsLueGain31_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain31_nu

#ifndef Y_TCTEST_PlObsLueGain32_nu
#define Y_TCTEST_PlObsLueGain32_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain32_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain32_nu(i) (Y_TCTEST_PlObsLueGain32_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain32_nu() ((const float32*) &Y_TCTEST_PlObsLueGain32_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain32_nu

#ifndef Y_TCTEST_PlObsLueGain33_nu
#define Y_TCTEST_PlObsLueGain33_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain33_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain33_nu(i) (Y_TCTEST_PlObsLueGain33_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain33_nu() ((const float32*) &Y_TCTEST_PlObsLueGain33_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain33_nu

#ifndef Y_TCTEST_PlObsLueGain41_nu
#define Y_TCTEST_PlObsLueGain41_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain41_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain41_nu(i) (Y_TCTEST_PlObsLueGain41_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain41_nu() ((const float32*) &Y_TCTEST_PlObsLueGain41_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain41_nu

#ifndef Y_TCTEST_PlObsLueGain42_nu
#define Y_TCTEST_PlObsLueGain42_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain42_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain42_nu(i) (Y_TCTEST_PlObsLueGain42_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain42_nu() ((const float32*) &Y_TCTEST_PlObsLueGain42_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain42_nu

#ifndef Y_TCTEST_PlObsLueGain43_nu
#define Y_TCTEST_PlObsLueGain43_nu(i) (LCF_CommonParamData.Y_TCTEST_PlObsLueGain43_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PlObsLueGain43_nu(i) (Y_TCTEST_PlObsLueGain43_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PlObsLueGain43_nu() ((const float32*) &Y_TCTEST_PlObsLueGain43_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PlObsLueGain43_nu

#ifndef Y_TCTEST_PreviewDistX_met
#define Y_TCTEST_PreviewDistX_met(i) (LCF_CommonParamData.Y_TCTEST_PreviewDistX_met[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_PreviewDistX_met(i) (Y_TCTEST_PreviewDistX_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_PreviewDistX_met() ((const float32*) &Y_TCTEST_PreviewDistX_met(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_PreviewDistX_met

#ifndef Y_TCTEST_SObsBetaSat_rad
#define Y_TCTEST_SObsBetaSat_rad(i) (LCF_CommonParamData.Y_TCTEST_SObsBetaSat_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_SObsBetaSat_rad(i) (Y_TCTEST_SObsBetaSat_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_SObsBetaSat_rad() ((const float32*) &Y_TCTEST_SObsBetaSat_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_SObsBetaSat_rad

#ifndef Y_TCTEST_SObsLueGain1_nu
#define Y_TCTEST_SObsLueGain1_nu(i) (LCF_CommonParamData.Y_TCTEST_SObsLueGain1_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_SObsLueGain1_nu(i) (Y_TCTEST_SObsLueGain1_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_SObsLueGain1_nu() ((const float32*) &Y_TCTEST_SObsLueGain1_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_SObsLueGain1_nu

#ifndef Y_TCTEST_SObsLueGain2_nu
#define Y_TCTEST_SObsLueGain2_nu(i) (LCF_CommonParamData.Y_TCTEST_SObsLueGain2_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_SObsLueGain2_nu(i) (Y_TCTEST_SObsLueGain2_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_SObsLueGain2_nu() ((const float32*) &Y_TCTEST_SObsLueGain2_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_SObsLueGain2_nu

#ifndef Y_TCTEST_StwGearRatio_nu
#define Y_TCTEST_StwGearRatio_nu(i) (LCF_CommonParamData.Y_TCTEST_StwGearRatio_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTEST_StwGearRatio_nu(i) (Y_TCTEST_StwGearRatio_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTEST_StwGearRatio_nu() ((const float32*) &Y_TCTEST_StwGearRatio_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTEST_StwGearRatio_nu

#ifndef Y_TCTLGC_CacDGain_sec
#define Y_TCTLGC_CacDGain_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacDGain_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacDGain_sec(i) (Y_TCTLGC_CacDGain_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacDGain_sec() ((const float32*) &Y_TCTLGC_CacDGain_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacDGain_sec

#ifndef Y_TCTLGC_CacDT1_sec
#define Y_TCTLGC_CacDT1_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacDT1_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacDT1_sec(i) (Y_TCTLGC_CacDT1_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacDT1_sec() ((const float32*) &Y_TCTLGC_CacDT1_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacDT1_sec

#ifndef Y_TCTLGC_CacIGain_1ps
#define Y_TCTLGC_CacIGain_1ps(i) (LCF_CommonParamData.Y_TCTLGC_CacIGain_1ps[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacIGain_1ps(i) (Y_TCTLGC_CacIGain_1ps(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacIGain_1ps() ((const float32*) &Y_TCTLGC_CacIGain_1ps(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacIGain_1ps

#ifndef Y_TCTLGC_CacOfDGain_sec
#define Y_TCTLGC_CacOfDGain_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacOfDGain_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacOfDGain_sec(i) (Y_TCTLGC_CacOfDGain_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacOfDGain_sec() ((const float32*) &Y_TCTLGC_CacOfDGain_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacOfDGain_sec

#ifndef Y_TCTLGC_CacOfDT1_sec
#define Y_TCTLGC_CacOfDT1_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacOfDT1_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacOfDT1_sec(i) (Y_TCTLGC_CacOfDT1_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacOfDT1_sec() ((const float32*) &Y_TCTLGC_CacOfDT1_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacOfDT1_sec

#ifndef Y_TCTLGC_CacOfIGain_1ps
#define Y_TCTLGC_CacOfIGain_1ps(i) (LCF_CommonParamData.Y_TCTLGC_CacOfIGain_1ps[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacOfIGain_1ps(i) (Y_TCTLGC_CacOfIGain_1ps(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacOfIGain_1ps() ((const float32*) &Y_TCTLGC_CacOfIGain_1ps(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacOfIGain_1ps

#ifndef Y_TCTLGC_CacOfPGain_nu
#define Y_TCTLGC_CacOfPGain_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacOfPGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacOfPGain_nu(i) (Y_TCTLGC_CacOfPGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacOfPGain_nu() ((const float32*) &Y_TCTLGC_CacOfPGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacOfPGain_nu

#ifndef Y_TCTLGC_CacOfPT1Gain_nu
#define Y_TCTLGC_CacOfPT1Gain_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacOfPT1Gain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacOfPT1Gain_nu(i) (Y_TCTLGC_CacOfPT1Gain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacOfPT1Gain_nu() ((const float32*) &Y_TCTLGC_CacOfPT1Gain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacOfPT1Gain_nu

#ifndef Y_TCTLGC_CacOfPT1Time_sec
#define Y_TCTLGC_CacOfPT1Time_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacOfPT1Time_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacOfPT1Time_sec(i) (Y_TCTLGC_CacOfPT1Time_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacOfPT1Time_sec() ((const float32*) &Y_TCTLGC_CacOfPT1Time_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacOfPT1Time_sec

#ifndef Y_TCTLGC_CacPGainCrv_nu
#define Y_TCTLGC_CacPGainCrv_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacPGainCrv_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacPGainCrv_nu(i) (Y_TCTLGC_CacPGainCrv_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacPGainCrv_nu() ((const float32*) &Y_TCTLGC_CacPGainCrv_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacPGainCrv_nu

#ifndef Y_TCTLGC_CacPGain_nu
#define Y_TCTLGC_CacPGain_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacPGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacPGain_nu(i) (Y_TCTLGC_CacPGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacPGain_nu() ((const float32*) &Y_TCTLGC_CacPGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacPGain_nu

#ifndef Y_TCTLGC_CacPT1Gain_nu
#define Y_TCTLGC_CacPT1Gain_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacPT1Gain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacPT1Gain_nu(i) (Y_TCTLGC_CacPT1Gain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacPT1Gain_nu() ((const float32*) &Y_TCTLGC_CacPT1Gain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacPT1Gain_nu

#ifndef Y_TCTLGC_CacPT1Time_sec
#define Y_TCTLGC_CacPT1Time_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacPT1Time_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacPT1Time_sec(i) (Y_TCTLGC_CacPT1Time_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacPT1Time_sec() ((const float32*) &Y_TCTLGC_CacPT1Time_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacPT1Time_sec

#ifndef Y_TCTLGC_CacSfDGain_sec
#define Y_TCTLGC_CacSfDGain_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacSfDGain_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacSfDGain_sec(i) (Y_TCTLGC_CacSfDGain_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacSfDGain_sec() ((const float32*) &Y_TCTLGC_CacSfDGain_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacSfDGain_sec

#ifndef Y_TCTLGC_CacSfDT1_sec
#define Y_TCTLGC_CacSfDT1_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacSfDT1_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacSfDT1_sec(i) (Y_TCTLGC_CacSfDT1_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacSfDT1_sec() ((const float32*) &Y_TCTLGC_CacSfDT1_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacSfDT1_sec

#ifndef Y_TCTLGC_CacSfIGain_1ps
#define Y_TCTLGC_CacSfIGain_1ps(i) (LCF_CommonParamData.Y_TCTLGC_CacSfIGain_1ps[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacSfIGain_1ps(i) (Y_TCTLGC_CacSfIGain_1ps(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacSfIGain_1ps() ((const float32*) &Y_TCTLGC_CacSfIGain_1ps(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacSfIGain_1ps

#ifndef Y_TCTLGC_CacSfPGain_nu
#define Y_TCTLGC_CacSfPGain_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacSfPGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacSfPGain_nu(i) (Y_TCTLGC_CacSfPGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacSfPGain_nu() ((const float32*) &Y_TCTLGC_CacSfPGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacSfPGain_nu

#ifndef Y_TCTLGC_CacSfPT1Gain_nu
#define Y_TCTLGC_CacSfPT1Gain_nu(i) (LCF_CommonParamData.Y_TCTLGC_CacSfPT1Gain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacSfPT1Gain_nu(i) (Y_TCTLGC_CacSfPT1Gain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacSfPT1Gain_nu() ((const float32*) &Y_TCTLGC_CacSfPT1Gain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacSfPT1Gain_nu

#ifndef Y_TCTLGC_CacSfPT1Time_sec
#define Y_TCTLGC_CacSfPT1Time_sec(i) (LCF_CommonParamData.Y_TCTLGC_CacSfPT1Time_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_CacSfPT1Time_sec(i) (Y_TCTLGC_CacSfPT1Time_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_CacSfPT1Time_sec() ((const float32*) &Y_TCTLGC_CacSfPT1Time_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_CacSfPT1Time_sec

#ifndef Y_TCTLGC_DynBacGain_nu
#define Y_TCTLGC_DynBacGain_nu(i) (LCF_CommonParamData.Y_TCTLGC_DynBacGain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_DynBacGain_nu(i) (Y_TCTLGC_DynBacGain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_DynBacGain_nu() ((const float32*) &Y_TCTLGC_DynBacGain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_DynBacGain_nu

#ifndef Y_TCTLGC_GLaDmcCompNumS0_nu
#define Y_TCTLGC_GLaDmcCompNumS0_nu(i) (LCF_CommonParamData.Y_TCTLGC_GLaDmcCompNumS0_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_GLaDmcCompNumS0_nu(i) (Y_TCTLGC_GLaDmcCompNumS0_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_GLaDmcCompNumS0_nu() ((const float32*) &Y_TCTLGC_GLaDmcCompNumS0_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_GLaDmcCompNumS0_nu

#ifndef Y_TCTLGC_GLaDmcCompNumS1_nu
#define Y_TCTLGC_GLaDmcCompNumS1_nu(i) (LCF_CommonParamData.Y_TCTLGC_GLaDmcCompNumS1_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_GLaDmcCompNumS1_nu(i) (Y_TCTLGC_GLaDmcCompNumS1_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_GLaDmcCompNumS1_nu() ((const float32*) &Y_TCTLGC_GLaDmcCompNumS1_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_GLaDmcCompNumS1_nu

#ifndef Y_TCTLGC_GLaDmcCompPole1_nu
#define Y_TCTLGC_GLaDmcCompPole1_nu(i) (LCF_CommonParamData.Y_TCTLGC_GLaDmcCompPole1_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_GLaDmcCompPole1_nu(i) (Y_TCTLGC_GLaDmcCompPole1_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_GLaDmcCompPole1_nu() ((const float32*) &Y_TCTLGC_GLaDmcCompPole1_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_GLaDmcCompPole1_nu

#ifndef Y_TCTLGC_GLaDmcCompPole2_nu
#define Y_TCTLGC_GLaDmcCompPole2_nu(i) (LCF_CommonParamData.Y_TCTLGC_GLaDmcCompPole2_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_GLaDmcCompPole2_nu(i) (Y_TCTLGC_GLaDmcCompPole2_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_GLaDmcCompPole2_nu() ((const float32*) &Y_TCTLGC_GLaDmcCompPole2_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_GLaDmcCompPole2_nu

#ifndef Y_TCTLGC_LdcDGain_radspm
#define Y_TCTLGC_LdcDGain_radspm(i) (LCF_CommonParamData.Y_TCTLGC_LdcDGain_radspm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcDGain_radspm(i) (Y_TCTLGC_LdcDGain_radspm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcDGain_radspm() ((const float32*) &Y_TCTLGC_LdcDGain_radspm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcDGain_radspm

#ifndef Y_TCTLGC_LdcDT1_sec
#define Y_TCTLGC_LdcDT1_sec(i) (LCF_CommonParamData.Y_TCTLGC_LdcDT1_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcDT1_sec(i) (Y_TCTLGC_LdcDT1_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcDT1_sec() ((const float32*) &Y_TCTLGC_LdcDT1_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcDT1_sec

#ifndef Y_TCTLGC_LdcIGain_radpsm
#define Y_TCTLGC_LdcIGain_radpsm(i) (LCF_CommonParamData.Y_TCTLGC_LdcIGain_radpsm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcIGain_radpsm(i) (Y_TCTLGC_LdcIGain_radpsm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcIGain_radpsm() ((const float32*) &Y_TCTLGC_LdcIGain_radpsm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcIGain_radpsm

#ifndef Y_TCTLGC_LdcOfDGain_radspm
#define Y_TCTLGC_LdcOfDGain_radspm(i) (LCF_CommonParamData.Y_TCTLGC_LdcOfDGain_radspm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcOfDGain_radspm(i) (Y_TCTLGC_LdcOfDGain_radspm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcOfDGain_radspm() ((const float32*) &Y_TCTLGC_LdcOfDGain_radspm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcOfDGain_radspm

#ifndef Y_TCTLGC_LdcOfDT1_sec
#define Y_TCTLGC_LdcOfDT1_sec(i) (LCF_CommonParamData.Y_TCTLGC_LdcOfDT1_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcOfDT1_sec(i) (Y_TCTLGC_LdcOfDT1_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcOfDT1_sec() ((const float32*) &Y_TCTLGC_LdcOfDT1_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcOfDT1_sec

#ifndef Y_TCTLGC_LdcOfIGain_radpsm
#define Y_TCTLGC_LdcOfIGain_radpsm(i) (LCF_CommonParamData.Y_TCTLGC_LdcOfIGain_radpsm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcOfIGain_radpsm(i) (Y_TCTLGC_LdcOfIGain_radpsm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcOfIGain_radpsm() ((const float32*) &Y_TCTLGC_LdcOfIGain_radpsm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcOfIGain_radpsm

#ifndef Y_TCTLGC_LdcOfPT1Gain_nu
#define Y_TCTLGC_LdcOfPT1Gain_nu(i) (LCF_CommonParamData.Y_TCTLGC_LdcOfPT1Gain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcOfPT1Gain_nu(i) (Y_TCTLGC_LdcOfPT1Gain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcOfPT1Gain_nu() ((const float32*) &Y_TCTLGC_LdcOfPT1Gain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcOfPT1Gain_nu

#ifndef Y_TCTLGC_LdcOfPT1Time_sec
#define Y_TCTLGC_LdcOfPT1Time_sec(i) (LCF_CommonParamData.Y_TCTLGC_LdcOfPT1Time_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcOfPT1Time_sec(i) (Y_TCTLGC_LdcOfPT1Time_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcOfPT1Time_sec() ((const float32*) &Y_TCTLGC_LdcOfPT1Time_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcOfPT1Time_sec

#ifndef Y_TCTLGC_LdcOfP_radpm
#define Y_TCTLGC_LdcOfP_radpm(i) (LCF_CommonParamData.Y_TCTLGC_LdcOfP_radpm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcOfP_radpm(i) (Y_TCTLGC_LdcOfP_radpm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcOfP_radpm() ((const float32*) &Y_TCTLGC_LdcOfP_radpm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcOfP_radpm

#ifndef Y_TCTLGC_LdcPGainCrv_radpm
#define Y_TCTLGC_LdcPGainCrv_radpm(i) (LCF_CommonParamData.Y_TCTLGC_LdcPGainCrv_radpm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcPGainCrv_radpm(i) (Y_TCTLGC_LdcPGainCrv_radpm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcPGainCrv_radpm() ((const float32*) &Y_TCTLGC_LdcPGainCrv_radpm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcPGainCrv_radpm

#ifndef Y_TCTLGC_LdcPT1Gain_nu
#define Y_TCTLGC_LdcPT1Gain_nu(i) (LCF_CommonParamData.Y_TCTLGC_LdcPT1Gain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcPT1Gain_nu(i) (Y_TCTLGC_LdcPT1Gain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcPT1Gain_nu() ((const float32*) &Y_TCTLGC_LdcPT1Gain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcPT1Gain_nu

#ifndef Y_TCTLGC_LdcPT1Time_sec
#define Y_TCTLGC_LdcPT1Time_sec(i) (LCF_CommonParamData.Y_TCTLGC_LdcPT1Time_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcPT1Time_sec(i) (Y_TCTLGC_LdcPT1Time_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcPT1Time_sec() ((const float32*) &Y_TCTLGC_LdcPT1Time_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcPT1Time_sec

#ifndef Y_TCTLGC_LdcP_radpm
#define Y_TCTLGC_LdcP_radpm(i) (LCF_CommonParamData.Y_TCTLGC_LdcP_radpm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcP_radpm(i) (Y_TCTLGC_LdcP_radpm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcP_radpm() ((const float32*) &Y_TCTLGC_LdcP_radpm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcP_radpm

#ifndef Y_TCTLGC_LdcSfDGain_radspm
#define Y_TCTLGC_LdcSfDGain_radspm(i) (LCF_CommonParamData.Y_TCTLGC_LdcSfDGain_radspm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcSfDGain_radspm(i) (Y_TCTLGC_LdcSfDGain_radspm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcSfDGain_radspm() ((const float32*) &Y_TCTLGC_LdcSfDGain_radspm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcSfDGain_radspm

#ifndef Y_TCTLGC_LdcSfDT1_sec
#define Y_TCTLGC_LdcSfDT1_sec(i) (LCF_CommonParamData.Y_TCTLGC_LdcSfDT1_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcSfDT1_sec(i) (Y_TCTLGC_LdcSfDT1_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcSfDT1_sec() ((const float32*) &Y_TCTLGC_LdcSfDT1_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcSfDT1_sec

#ifndef Y_TCTLGC_LdcSfIGain_radpsm
#define Y_TCTLGC_LdcSfIGain_radpsm(i) (LCF_CommonParamData.Y_TCTLGC_LdcSfIGain_radpsm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcSfIGain_radpsm(i) (Y_TCTLGC_LdcSfIGain_radpsm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcSfIGain_radpsm() ((const float32*) &Y_TCTLGC_LdcSfIGain_radpsm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcSfIGain_radpsm

#ifndef Y_TCTLGC_LdcSfPT1Gain_nu
#define Y_TCTLGC_LdcSfPT1Gain_nu(i) (LCF_CommonParamData.Y_TCTLGC_LdcSfPT1Gain_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcSfPT1Gain_nu(i) (Y_TCTLGC_LdcSfPT1Gain_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcSfPT1Gain_nu() ((const float32*) &Y_TCTLGC_LdcSfPT1Gain_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcSfPT1Gain_nu

#ifndef Y_TCTLGC_LdcSfPT1Time_sec
#define Y_TCTLGC_LdcSfPT1Time_sec(i) (LCF_CommonParamData.Y_TCTLGC_LdcSfPT1Time_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcSfPT1Time_sec(i) (Y_TCTLGC_LdcSfPT1Time_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcSfPT1Time_sec() ((const float32*) &Y_TCTLGC_LdcSfPT1Time_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcSfPT1Time_sec

#ifndef Y_TCTLGC_LdcSfP_radpm
#define Y_TCTLGC_LdcSfP_radpm(i) (LCF_CommonParamData.Y_TCTLGC_LdcSfP_radpm[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_LdcSfP_radpm(i) (Y_TCTLGC_LdcSfP_radpm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_LdcSfP_radpm() ((const float32*) &Y_TCTLGC_LdcSfP_radpm(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_LdcSfP_radpm

#ifndef Y_TCTLGC_PT1CoAnErrTime_sec
#define Y_TCTLGC_PT1CoAnErrTime_sec(i) (LCF_CommonParamData.Y_TCTLGC_PT1CoAnErrTime_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_PT1CoAnErrTime_sec(i) (Y_TCTLGC_PT1CoAnErrTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_PT1CoAnErrTime_sec() ((const float32*) &Y_TCTLGC_PT1CoAnErrTime_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_PT1CoAnErrTime_sec

#ifndef Y_TCTLGC_PT1DeltaFCmdTime_sec
#define Y_TCTLGC_PT1DeltaFCmdTime_sec(i) (LCF_CommonParamData.Y_TCTLGC_PT1DeltaFCmdTime_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_PT1DeltaFCmdTime_sec(i) (Y_TCTLGC_PT1DeltaFCmdTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_PT1DeltaFCmdTime_sec() ((const float32*) &Y_TCTLGC_PT1DeltaFCmdTime_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_PT1DeltaFCmdTime_sec

#ifndef Y_TCTLGC_PT1YErrTime_sec
#define Y_TCTLGC_PT1YErrTime_sec(i) (LCF_CommonParamData.Y_TCTLGC_PT1YErrTime_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TCTLGC_PT1YErrTime_sec(i) (Y_TCTLGC_PT1YErrTime_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TCTLGC_PT1YErrTime_sec() ((const float32*) &Y_TCTLGC_PT1YErrTime_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TCTLGC_PT1YErrTime_sec

#ifndef Y_TJAGEN_VehRadiusMinWR_met
#define Y_TJAGEN_VehRadiusMinWR_met(i) (LCF_CommonParamData.Y_TJAGEN_VehRadiusMinWR_met[(i)]) //!< LCF parameter macro.
#define GET_Y_TJAGEN_VehRadiusMinWR_met(i) (Y_TJAGEN_VehRadiusMinWR_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJAGEN_VehRadiusMinWR_met() ((const float32*) &Y_TJAGEN_VehRadiusMinWR_met(0)) //!< LCF parameter macro pointer.
#endif // Y_TJAGEN_VehRadiusMinWR_met

#ifndef Y_TJAOBF_TgtClthCrvMaxWR_1pm
#define Y_TJAOBF_TgtClthCrvMaxWR_1pm(i) (LCF_CommonParamData.Y_TJAOBF_TgtClthCrvMaxWR_1pm[(i)]) //!< LCF parameter macro.
#define GET_Y_TJAOBF_TgtClthCrvMaxWR_1pm(i) (Y_TJAOBF_TgtClthCrvMaxWR_1pm(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJAOBF_TgtClthCrvMaxWR_1pm() ((const float32*) &Y_TJAOBF_TgtClthCrvMaxWR_1pm(0)) //!< LCF parameter macro pointer.
#endif // Y_TJAOBF_TgtClthCrvMaxWR_1pm

#ifndef Y_TJAOBF_TgtClthHeadMaxWR_rad
#define Y_TJAOBF_TgtClthHeadMaxWR_rad(i) (LCF_CommonParamData.Y_TJAOBF_TgtClthHeadMaxWR_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TJAOBF_TgtClthHeadMaxWR_rad(i) (Y_TJAOBF_TgtClthHeadMaxWR_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJAOBF_TgtClthHeadMaxWR_rad() ((const float32*) &Y_TJAOBF_TgtClthHeadMaxWR_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TJAOBF_TgtClthHeadMaxWR_rad

#ifndef Y_TJAOBF_TgtClthPosYMaxWR_met
#define Y_TJAOBF_TgtClthPosYMaxWR_met(i) (LCF_CommonParamData.Y_TJAOBF_TgtClthPosYMaxWR_met[(i)]) //!< LCF parameter macro.
#define GET_Y_TJAOBF_TgtClthPosYMaxWR_met(i) (Y_TJAOBF_TgtClthPosYMaxWR_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJAOBF_TgtClthPosYMaxWR_met() ((const float32*) &Y_TJAOBF_TgtClthPosYMaxWR_met(0)) //!< LCF parameter macro pointer.
#endif // Y_TJAOBF_TgtClthPosYMaxWR_met

#ifndef Y_TJATVG_LWDeratLvlScalFact_nu
#define Y_TJATVG_LWDeratLvlScalFact_nu(i) (LCF_CommonParamData.Y_TJATVG_LWDeratLvlScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TJATVG_LWDeratLvlScalFact_nu(i) (Y_TJATVG_LWDeratLvlScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJATVG_LWDeratLvlScalFact_nu() ((const float32*) &Y_TJATVG_LWDeratLvlScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TJATVG_LWDeratLvlScalFact_nu

#ifndef Y_TJATVG_PlanHorizonObjFolVal_sec
#define Y_TJATVG_PlanHorizonObjFolVal_sec(i) (LCF_CommonParamData.Y_TJATVG_PlanHorizonObjFolVal_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TJATVG_PlanHorizonObjFolVal_sec(i) (Y_TJATVG_PlanHorizonObjFolVal_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJATVG_PlanHorizonObjFolVal_sec() ((const float32*) &Y_TJATVG_PlanHorizonObjFolVal_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TJATVG_PlanHorizonObjFolVal_sec

#ifndef Y_TJATVG_PlanHorizonScalFact_nu
#define Y_TJATVG_PlanHorizonScalFact_nu(i) (LCF_CommonParamData.Y_TJATVG_PlanHorizonScalFact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TJATVG_PlanHorizonScalFact_nu(i) (Y_TJATVG_PlanHorizonScalFact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJATVG_PlanHorizonScalFact_nu() ((const float32*) &Y_TJATVG_PlanHorizonScalFact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TJATVG_PlanHorizonScalFact_nu

#ifndef Y_TJATVG_PlanningHorizonVal_sec
#define Y_TJATVG_PlanningHorizonVal_sec(i) (LCF_CommonParamData.Y_TJATVG_PlanningHorizonVal_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TJATVG_PlanningHorizonVal_sec(i) (Y_TJATVG_PlanningHorizonVal_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJATVG_PlanningHorizonVal_sec() ((const float32*) &Y_TJATVG_PlanningHorizonVal_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TJATVG_PlanningHorizonVal_sec

#ifndef Y_TJATVG_RedFact_Vel_nu
#define Y_TJATVG_RedFact_Vel_nu(i) (LCF_CommonParamData.Y_TJATVG_RedFact_Vel_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TJATVG_RedFact_Vel_nu(i) (Y_TJATVG_RedFact_Vel_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TJATVG_RedFact_Vel_nu() ((const float32*) &Y_TJATVG_RedFact_Vel_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TJATVG_RedFact_Vel_nu

#ifndef Y_TPLCEN_DeadTimeVehCtrl_sec
#define Y_TPLCEN_DeadTimeVehCtrl_sec(i) (LCF_CommonParamData.Y_TPLCEN_DeadTimeVehCtrl_sec[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLCEN_DeadTimeVehCtrl_sec(i) (Y_TPLCEN_DeadTimeVehCtrl_sec(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLCEN_DeadTimeVehCtrl_sec() ((const float32*) &Y_TPLCEN_DeadTimeVehCtrl_sec(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLCEN_DeadTimeVehCtrl_sec

#ifndef Y_TPLFBT_GradLimitCrvFactor_nu
#define Y_TPLFBT_GradLimitCrvFactor_nu(i) (LCF_CommonParamData.Y_TPLFBT_GradLimitCrvFactor_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLFBT_GradLimitCrvFactor_nu(i) (Y_TPLFBT_GradLimitCrvFactor_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLFBT_GradLimitCrvFactor_nu() ((const float32*) &Y_TPLFBT_GradLimitCrvFactor_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLFBT_GradLimitCrvFactor_nu

#ifndef Y_TPLLCO_AllowedDevPosY_met
#define Y_TPLLCO_AllowedDevPosY_met(i) (LCF_CommonParamData.Y_TPLLCO_AllowedDevPosY_met[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLLCO_AllowedDevPosY_met(i) (Y_TPLLCO_AllowedDevPosY_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLLCO_AllowedDevPosY_met() ((const float32*) &Y_TPLLCO_AllowedDevPosY_met(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLLCO_AllowedDevPosY_met

#ifndef Y_TPLLCO_PreviewDistXOBF_met
#define Y_TPLLCO_PreviewDistXOBF_met(i) (LCF_CommonParamData.Y_TPLLCO_PreviewDistXOBF_met[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLLCO_PreviewDistXOBF_met(i) (Y_TPLLCO_PreviewDistXOBF_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLLCO_PreviewDistXOBF_met() ((const float32*) &Y_TPLLCO_PreviewDistXOBF_met(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLLCO_PreviewDistXOBF_met

#ifndef Y_TPLLCO_PreviewDistX_met
#define Y_TPLLCO_PreviewDistX_met(i) (LCF_CommonParamData.Y_TPLLCO_PreviewDistX_met[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLLCO_PreviewDistX_met(i) (Y_TPLLCO_PreviewDistX_met(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLLCO_PreviewDistX_met() ((const float32*) &Y_TPLLCO_PreviewDistX_met(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLLCO_PreviewDistX_met

#ifndef Y_TPLLCO_TgtCridrHeadTolCrv_rad
#define Y_TPLLCO_TgtCridrHeadTolCrv_rad(i) (LCF_CommonParamData.Y_TPLLCO_TgtCridrHeadTolCrv_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLLCO_TgtCridrHeadTolCrv_rad(i) (Y_TPLLCO_TgtCridrHeadTolCrv_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLLCO_TgtCridrHeadTolCrv_rad() ((const float32*) &Y_TPLLCO_TgtCridrHeadTolCrv_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLLCO_TgtCridrHeadTolCrv_rad

#ifndef Y_TPLLCO_TgtCridrHeadTolVelX_rad
#define Y_TPLLCO_TgtCridrHeadTolVelX_rad(i) (LCF_CommonParamData.Y_TPLLCO_TgtCridrHeadTolVelX_rad[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLLCO_TgtCridrHeadTolVelX_rad(i) (Y_TPLLCO_TgtCridrHeadTolVelX_rad(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLLCO_TgtCridrHeadTolVelX_rad() ((const float32*) &Y_TPLLCO_TgtCridrHeadTolVelX_rad(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLLCO_TgtCridrHeadTolVelX_rad

#ifndef Y_TPLLCO_VehCrvFactor_nu
#define Y_TPLLCO_VehCrvFactor_nu(i) (LCF_CommonParamData.Y_TPLLCO_VehCrvFactor_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLLCO_VehCrvFactor_nu(i) (Y_TPLLCO_VehCrvFactor_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLLCO_VehCrvFactor_nu() ((const float32*) &Y_TPLLCO_VehCrvFactor_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLLCO_VehCrvFactor_nu

#ifndef Y_TPLTJC_MaxAclY_mps2
#define Y_TPLTJC_MaxAclY_mps2(i) (LCF_CommonParamData.Y_TPLTJC_MaxAclY_mps2[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLTJC_MaxAclY_mps2(i) (Y_TPLTJC_MaxAclY_mps2(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLTJC_MaxAclY_mps2() ((const float32*) &Y_TPLTJC_MaxAclY_mps2(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLTJC_MaxAclY_mps2

#ifndef Y_TPLTJC_WeightEndTime_nu
#define Y_TPLTJC_WeightEndTime_nu(i) (LCF_CommonParamData.Y_TPLTJC_WeightEndTime_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLTJC_WeightEndTime_nu(i) (Y_TPLTJC_WeightEndTime_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLTJC_WeightEndTime_nu() ((const float32*) &Y_TPLTJC_WeightEndTime_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLTJC_WeightEndTime_nu

#ifndef Y_TPLTJC_WghtTgtDistYCharact_nu
#define Y_TPLTJC_WghtTgtDistYCharact_nu(i) (LCF_CommonParamData.Y_TPLTJC_WghtTgtDistYCharact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLTJC_WghtTgtDistYCharact_nu(i) (Y_TPLTJC_WghtTgtDistYCharact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLTJC_WghtTgtDistYCharact_nu() ((const float32*) &Y_TPLTJC_WghtTgtDistYCharact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLTJC_WghtTgtDistYCharact_nu

#ifndef Y_TPLTJC_WghtTgtTimeCharact_nu
#define Y_TPLTJC_WghtTgtTimeCharact_nu(i) (LCF_CommonParamData.Y_TPLTJC_WghtTgtTimeCharact_nu[(i)]) //!< LCF parameter macro.
#define GET_Y_TPLTJC_WghtTgtTimeCharact_nu(i) (Y_TPLTJC_WghtTgtTimeCharact_nu(i)) //!< LCF parameter macro getter.
#define GETA_Y_TPLTJC_WghtTgtTimeCharact_nu() ((const float32*) &Y_TPLTJC_WghtTgtTimeCharact_nu(0)) //!< LCF parameter macro pointer.
#endif // Y_TPLTJC_WghtTgtTimeCharact_nu

#ifdef __cplusplus
}
#endif

#endif // LCFPRM_DATA_H_
