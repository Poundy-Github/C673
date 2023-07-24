/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_fusion_navi.c

DESCRIPTION:               Fusion of navi path into ACC trajectory

AUTHOR:                    Marie-Theres Boll

CREATION DATE:             09.04.2013

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_COURSE_PREDICTION)
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_fusion_navi Navi fusion
@ingroup cp_trajectory
@brief         Responsible for computation of Navi data based trajectory . \n\n
@{
*/
#include "cp_kalman.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
#define CP_NAVI_SITU_MAX_LC_PROB          (65u)        /*!< Maximal lane change probability until which a navi path fusion is conducted */
#define CP_NAVI_SITU_MAX_EGO_CURVE        (0.012f)    /*!< Maximal ego curve until which a navi path fusion is conducted */
#define CP_NAVI_SITU_MIN_PERC_PICKUP_DIST (1.0f)      /*!< Minimum percent of the pick-up distance which the length of the navi path has to exceed */

#define CP_NAVI_SAMPLE_STD_DEFAULT        (0.15f)     /*!< Default navi path sample standard deviation */
#define CP_NAVI_SAMPLE_STD_MIN            (0.07f)     /*!< Minimum navi path sample standard deviation */
#define CP_NAVI_SAMPLE_STD_LC_PROB_MIN    (55)        /*!< Minimum lane change probability which influences the sample standard deviation */
#define CP_NAVI_SAMPLE_STD_HIGHWAY        (0.15f)     /*!< Reduce the standard deviation in case of a highway */
#define CP_NAVI_SAMPLE_MIN_VELO_HIGHWAY   (80.f/C_KMH_MS) /*!< Minimum ego velocity on the highway for reduceing the standard deviation in case of a highway */
#define CP_NAVI_SAMPLE_XDIST_NAVI_TRAJ_DIFF  (75.f)   /*!< X-distance at which the difference between the navi path and the ACC trajectory is evaluated @unit:m */

#if (SLATE_CFG_CAM_LANE_INTERFACE)
#define CP_NAVI_MAX_SPEED_ROADWORKS       (26.f)      /*!< Maximum speed for assuming a roadworks on a highway */
#endif

/*! In case of a high y-offset of the ego motion compensated NAVI path at the ego position, increase the standard deviation */
#define CP_PAR_NAVI_MIN_YOFFSET_STD_DEV     (0.f)
#define CP_PAR_NAVI_MAX_YOFFSET_STD_DEV     (1.0f)
#define CP_PAR_NAVI_MIN_YOFFSET             (0.f)
#define CP_PAR_NAVI_MAX_YOFFSET             FIP_NAVI_MAX_YCOMP_AT_ORIG

/*! In case of a high difference between the ego curve and the NAVI path, increase the standard deviation */
#define CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI_STD_DEV     (1.f)
#define CP_PAR_NAVI_MAX_ERR_EGOCURVE_NAVI_STD_DEV     (1.5f)
#define CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI             (0.f)
#define CP_PAR_NAVI_MAX_ERR_EGOCURVE_NAVI             FIP_NAVI_MAX_APPROX_EGO_DIFF


/*! Navi branch probability low threshold - 10%  */
#define CP_NAVI_FUSION_BRANCH_PROB_LOW            10.f
/*! Navi branch probability high threshold - 90%  */
#define CP_NAVI_FUSION_BRANCH_PROB_HIGH           90.f
/*! Navi course variance factor for low branch probability*/
#define CP_NAVI_FUSION_BRANCH_PROB_FACTOR_LOW     1.0f
/*! Navi course variance factor for high branch probability*/
#define CP_NAVI_FUSION_BRANCH_PROB_FACTOR_HIGH    (20.0f)

#define CURVE_TO_NAVI_FILTER_TIME  10.0f 

/*! In case of a high y-offset of the ego motion compensated NAVI path at the ego position, increase the standard deviation */
SET_MEMSEC_CONST(CP_NaviPathYOffsetEgoCompAtOrig)
static const GDBLFunction_t CP_NaviPathYOffsetEgoCompAtOrig = {// PRQA S 3218
/*date: 2015-04-27, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls*/
    CP_PAR_NAVI_MIN_YOFFSET_STD_DEV,
    CP_PAR_NAVI_MAX_YOFFSET_STD_DEV,
    ((CP_PAR_NAVI_MAX_YOFFSET_STD_DEV - CP_PAR_NAVI_MIN_YOFFSET_STD_DEV) / (CP_PAR_NAVI_MAX_YOFFSET - CP_PAR_NAVI_MIN_YOFFSET)),
    (CP_PAR_NAVI_MIN_YOFFSET_STD_DEV - (((CP_PAR_NAVI_MAX_YOFFSET_STD_DEV - CP_PAR_NAVI_MIN_YOFFSET_STD_DEV) / (CP_PAR_NAVI_MAX_YOFFSET - CP_PAR_NAVI_MIN_YOFFSET))*CP_PAR_NAVI_MIN_YOFFSET))
};


/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*! Variables for navi CP meas freeze */
static boolean CP_b_NaviCPExternalSwitchMeas = FALSE;
static boolean CP_b_NaviCPsLaneChangeFusionMeas = FALSE;
static boolean CP_b_NaviCPValidPathLengthFusionMeas = FALSE;
static boolean CP_b_NaviCPValidSpeedRangeFusionMeas = FALSE;
/*! Filtered error value in case of a high difference between the ego curve and the NAVI path */
SET_MEMSEC_VAR(f_ErrEgoCurveToNaviPath_filtered)
static float32 f_ErrEgoCurveToNaviPath_filtered = CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI_STD_DEV;//PRQA S 3218
/*date: 2018-07-31, reviewer: Midhun Easo Daniel, reason: static local for saving data across function calls*/

/*! static varible of this structure is used in CP_b_NaviPathFusionSituation() to do different situation checks for navi path fusion */
typedef struct CPNaviPathSituationBits{
  boolean b_IsNaviFusionSituation;
  boolean b_NaviDataPlausible;
  boolean b_AllowedNaviStreetTyp;
  boolean b_ValidSpeedRange;
  boolean b_ValidPathLength;
  boolean bIsNaviPathApproxPlausible;
  boolean b_EgoLaneChange;
  boolean b_HighEgoCurve;
  boolean b_Roadworks;
  boolean b_NaviDataQuality;
}CPNaviPathSituationBits_t;

SET_MEMSEC_VAR(CPNaviPathSituationBits)
static CPNaviPathSituationBits_t CPNaviPathSituationBits;//PRQA S 3218
/*date: 2018-07-31, reviewer: Midhun Easo Daniel, reason: static local for saving data across function calls*/
/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CP_b_NaviPathFusionSituation(boolean b_LastNaviFusionState);
static boolean CP_b_GetRoadIsRoadworks(void);
static boolean CP_b_EgoSpeedInValidRange(boolean b_LastNaviFusionState);
#ifdef FCT_SIMU
static void CP_v_InitDebugNaviInfo(void);
#endif
static void CP_v_KalmanUpdatePosNavi( const SLATE_t_PosSamples * pFUSED_Samples , CP_t_NoiseModelLinear sNoiseModel);


/*************************************************************************************************************************
  Functionname:    CP_v_FusionNaviMain                                                                                 */ /*!

  @brief           Fusion of NAVI position samples into the ACC-trajectory

  @description     Fusion of NAVI position samples into the ACC-trajectory
                   - check if NAVI information should be fused
                   - determine position samples and gradient for kalman filter
                   - fuse NAVI information based on kalman filter

		@startuml
		Start
		Partition CP_v_FusionNaviMain {
		Partition FCT_SIMU {
		: Initialize debug information;
		}
		: Initialize measure freeze data;
		: Set Navi Path Fusion Situation;
		Partition #LightBlue "**~#if (FCT_CFG_BSW_ALGO_PARAMS) && (BSW_ALGOPARAMETERS_INTFVER >= 16u) **" {
			If (navi path fusion is enabled using external switch) then (True)
				: Enable Navi External Switch;
			Else (False)
				: Disable Navi External Switch;
			Endif
		}
		: Set CP Navi External Switch Measure;
		If (Navi Path Fusion Situation is enabled and Navi External Switch is enabled) then (True)
			: Initialize trajectory sample structures for nave path position samples and for fused position samples;
			: Determine/Copy the position samples based on the filtered NAVI path (used for updating the ACC-trajectory);
			Repeat
				If (cehck if Navi Path Pos Sample which x-position is more than 0) then (True)
					: Exit;
				Else (False)
					: Do Nothing;
				Endif
			Repeat While (All Navi Path pos samples)
			: Get the y-offset of the ego motion compensated NAVI path at the ego position;
			: Get standard deviation y-offset of Ego compensated NAVI path;
			: Get the error between the ego curve and the NAVI path;
			: Get Standard deviation error between ego curve and navi path;
			: filter the error value with low pass filter;
			: Get the probability ego which takes the branch (leave mpp);
			: Get the probability ego which takes the branch factor;
			Partition FCT_SIMU {
				: Get fusion factor branch probability;
				: Get fusion factor Y offset;
				: Get fusion factor Error between ego Curve and navi path; 
			}
			Repeat
				: Copy position update to t_FusedPosSamples-structure (only samples which x-position is higher zero);
				: Get Navi variance;
				: Increase the navi variance by the curvature change and difference to ego path factors;
				: Get Variance information;
				: Increse number of fused pos samples by 1;
				Partition FCT_SIMU {
					: Get Vertex x-position, Vertex y-position and Standard deviation of Navi path fusion debug info;
				}
			Repeat While (All Navi Path Pos Samples)
			: Update Noise offset and noise gradient of constant noise;
			: Navi path position update of the Kalman filter to fuse the navi path into the ACC-trajectory;
			: Set NAVI path fusion state as True and Set Ego course as False;
		Else (False)
			: Set navi path fusion situation as False;
			: set filtered error from  Ego Curve to navi path as CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI_STD_DEV;
		Endif
		Partition FCT_SIMU {
			: Freeze FCT data from CP Fusion components;
		}
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_CPOutput->CP_TrajectoryData.State.NaviPathFusion : Bit when navi path fusion is active                    [TRUE, FALSE]
  @glob_in         FCT_BSW_ALGO_PARAM_PTR->Fct.Acc.NaviFusionPreselBits : Coding parameters to enable NAVI fusion               [type NaviFusionPreselBits_t defined in Rte_Type.h]
  @glob_in         pt_CPInput : Pointer to CP input structure
                      pt_FIPNaviData.f_YOffsetEgoCompAtOrig : Y-Offset of ego motion compensated navi path at the ego position  [Full range of float32  >= 0.F]
                      pt_FIPNaviData.f_EgoNaviPathErrDistAvg : Difference between the approximated NAVI path and the ego curve  [Full range of float32  >= 0.F]
					  pt_FIPNaviData.f_CurvinessProbFar : Curviness probability value from offset between curvature at ego position and NAVI-curvature for time-gap of 4s  [Full range of float32  >= 0.F]
                      pt_RTE.f_EgoLongVel : Longitudinal velocity of ego vehicle                                                [-330.f ... 330.f] m/s 
  @glob_in         CP_TrajFusionDebugInfo : Trajectory fusion debug information
  @glob_out        CP_b_NaviCPExternalSwitchMeas : meas freeze data: NAVI path fusion enabled                                   [TRUE, FALSE]
  @glob_out        CP_b_NaviCPsLaneChangeFusionMeas : meas freeze data: Ego lane change bit                                     [TRUE, FALSE]
  @glob_out        CP_b_NaviCPValidPathLengthFusionMeas : meas freeze data: valid path length bit                               [TRUE, FALSE]
  @glob_out        CP_b_NaviCPValidSpeedRangeFusionMeas : meas freeze data : valid speed range bit                              [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fXPos : X Position                                     [Full range of float32  >= 0.F]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fYPos : Y Position                                     [Full range of float32  >= 0.F]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fStdDev : Standard Deviation                           [Full range of float32  >= 0.F]
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData.State.NaviPathFusion : Bit when navi path fusion is active                              [TRUE, FALSE]
                      CP_TrajectoryData.State.EgoCourseOnly : Bit indicating that only ego course used for trajectory           [TRUE, FALSE]


  @c_switch_part   FCT_SIMU                          : Configuration switch used for simulation
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS           : Configuration switch enabling the passing of algo parameters to the FCT component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING      : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION         : FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis)

  @traceability    283:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-283-00061542 \n
  
  @created         -
  @changed         30.03.2017

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void CP_v_FusionNaviMain(void)
{
  boolean bNaviPathFusionSituation;
  boolean bNaviExternalSwitch = FALSE;
  uint8 ui_Sample, ui_SampleStart;
  float32 f_NaviEstVar, f_YOffsetEgoCompAtOrig, f_StdDiffYOffsetEgoCompAtOrig, f_ErrEgoCurveToNaviPath, f_StdErrEgoCurveToNaviPath;
  float32 f_prob_ego_takes_branch_factor;
  uint8 u_prob_ego_takes_branch;
  SLATE_t_PosSamples t_NaviPathPosSamples, t_FusedPosSamples;
  
  
  CP_t_NoiseModelLinear ConstantNoise;

  /*! Initialization of debug info */
#ifdef FCT_SIMU
  CP_v_InitDebugNaviInfo();
#endif

  /*! Initialize meas freeze data */
  CP_b_NaviCPExternalSwitchMeas = FALSE;
  CP_b_NaviCPsLaneChangeFusionMeas = FALSE;
  CP_b_NaviCPValidPathLengthFusionMeas = FALSE;
  CP_b_NaviCPValidSpeedRangeFusionMeas = FALSE;

  /*! Check if navi path fusion should be done in this situation */
  bNaviPathFusionSituation = CP_b_NaviPathFusionSituation((boolean)pt_CPOutput->CP_TrajectoryData.State.NaviPathFusion);
  /*! Check if navi path fusion is enabled using external switch */
#if ((FCT_CFG_BSW_ALGO_PARAMS) && (BSW_ALGOPARAMETERS_INTFVER >= 16u))
  if((FCT_BSW_ALGO_PARAM_PTR->Fct.Acc.NaviFusionPreselBits & ACC_NAV_FUSION_SEL_TRAJ_FUSION) != 0)
  {
    bNaviExternalSwitch = TRUE;
  }
#else
  bNaviExternalSwitch = TRUE;
#endif
  
  /*! Set meas freeze data: External switch */
  CP_b_NaviCPExternalSwitchMeas = bNaviExternalSwitch;

  if((bNaviPathFusionSituation == TRUE) && (bNaviExternalSwitch == TRUE))
  {
    /*! Initialization of sample structures */
    CP_v_InitPosSamples(&t_NaviPathPosSamples);
    CP_v_InitPosSamples(&t_FusedPosSamples);

    /*! Get the position samples of the navi path */
    FIP_v_CalcNaviPathApproxPosSample(&t_NaviPathPosSamples);
    
    /*! Find the first sample which x-position is higher zero */
    for (ui_SampleStart = 0u; (ui_SampleStart < t_NaviPathPosSamples.nb_samples); ui_SampleStart++)
    {
      if(t_NaviPathPosSamples.fx[ui_SampleStart] > C_F32_DELTA)
      {
        /* Condition for breaking up of the loop:
         first sample point with a x-distance higher than zero */
        break;
      }
    }

    /*! Get the y-offset of the ego motion compensated NAVI path at the ego position */
    f_YOffsetEgoCompAtOrig = (pt_CPInput->pt_FIPNaviData->f_YOffsetEgoCompAtOrig);
    /*! In case of a high y-offset of the ego motion compensated NAVI path at the ego position, increase the standard deviation */
    f_StdDiffYOffsetEgoCompAtOrig = dGDBmathLineareFunktion(&CP_NaviPathYOffsetEgoCompAtOrig, fABS(f_YOffsetEgoCompAtOrig));

    /*! Get the error between the ego curve and the NAVI path */
    f_ErrEgoCurveToNaviPath = (pt_CPInput->pt_FIPNaviData->f_EgoNaviPathErrDistAvg);
    f_ErrEgoCurveToNaviPath = fABS(f_ErrEgoCurveToNaviPath);
    /*! In case of a high difference between the ego curve and the NAVI path, increase the standard deviation */
    f_StdErrEgoCurveToNaviPath = GDBmathLinFuncLimBounded(f_ErrEgoCurveToNaviPath, CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI, FIP_NAVI_MAX_APPROX_EGO_DIFF,
                                    CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI_STD_DEV, CP_PAR_NAVI_MAX_ERR_EGOCURVE_NAVI_STD_DEV);
    /* filter the error value with low pass filter */
    f_ErrEgoCurveToNaviPath_filtered = GDB_FILTER(f_StdErrEgoCurveToNaviPath, f_ErrEgoCurveToNaviPath_filtered, CURVE_TO_NAVI_FILTER_TIME);

    /*! Get the probability ego the branch (leave mpp) */
    u_prob_ego_takes_branch = (pt_CPInput->pt_FIPNaviData->u_NaviBranchProb);
    f_prob_ego_takes_branch_factor = GDBmathLinFuncLimBounded((float32)u_prob_ego_takes_branch, CP_NAVI_FUSION_BRANCH_PROB_LOW, CP_NAVI_FUSION_BRANCH_PROB_HIGH,
      CP_NAVI_FUSION_BRANCH_PROB_FACTOR_LOW,  CP_NAVI_FUSION_BRANCH_PROB_FACTOR_HIGH );


#ifdef FCT_SIMU
      CP_TrajFusionDebugInfo.NaviPathFusionDebug.f_fusion_factor_BranchProb        = f_prob_ego_takes_branch_factor;
      CP_TrajFusionDebugInfo.NaviPathFusionDebug.f_fusion_factor_YOffset           = f_StdDiffYOffsetEgoCompAtOrig;
      CP_TrajFusionDebugInfo.NaviPathFusionDebug.f_fusion_factor_ErrEgoCurveToNavi = f_ErrEgoCurveToNaviPath_filtered;
#endif
   /*! Copy position update to t_FusedPosSamples-structure (only samples which x-position is higher zero) */
    for (ui_Sample = ui_SampleStart; ui_Sample < t_NaviPathPosSamples.nb_samples; ui_Sample++)
    {
      t_FusedPosSamples.fx[ui_Sample - ui_SampleStart] = t_NaviPathPosSamples.fx[ui_Sample];
      t_FusedPosSamples.fy[ui_Sample - ui_SampleStart] = t_NaviPathPosSamples.fy[ui_Sample];

      /*! Determine the standard deviation of the sample */
      f_NaviEstVar = CP_f_GetNaviVariance(t_FusedPosSamples.fx[ui_Sample - ui_SampleStart], *pt_CPInput->t_RTE.pf_EgoLongVel) + f_StdDiffYOffsetEgoCompAtOrig ;
	    /* Increase the variance by the curvature change and difference to ego path factors */
      f_NaviEstVar = f_NaviEstVar  * f_ErrEgoCurveToNaviPath_filtered * f_prob_ego_takes_branch_factor;

      t_FusedPosSamples.fVar[ui_Sample - ui_SampleStart] = f_NaviEstVar;
      t_FusedPosSamples.nb_samples++;

#ifdef FCT_SIMU
      CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[ui_Sample - ui_SampleStart].fXPos = t_FusedPosSamples.fx[ui_Sample - ui_SampleStart];
      CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[ui_Sample - ui_SampleStart].fYPos = t_FusedPosSamples.fy[ui_Sample - ui_SampleStart];
      CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[ui_Sample - ui_SampleStart].fStdDev = f_NaviEstVar;
#endif
    }

    /* Update Kalman filter with fused samples */
    ConstantNoise.fNoiseOffset   = 0.05f;
    ConstantNoise.fNoiseGradient = 0.f;
    CP_v_KalmanUpdatePosNavi(&t_FusedPosSamples,ConstantNoise);

    /*! Set NAVI path fusion state */
    pt_CPOutput->CP_TrajectoryData.State.NaviPathFusion = TRUE;
    pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly  = FALSE;
  }
  else
  {
    /*! Set navi course fusion state to "off", if no navi path fusion situation */
    pt_CPOutput->CP_TrajectoryData.State.NaviPathFusion  = FALSE;
    /* set the filterd signal to init value */
    f_ErrEgoCurveToNaviPath_filtered = CP_PAR_NAVI_MIN_ERR_EGOCURVE_NAVI_STD_DEV;
  }

#ifdef FCT_SIMU
  CP_v_CallFCTFreezeforCPFusion(&CP_TrajFusionDebugInfo);
#endif
}


/*************************************************************************************************************************
  Functionname:    CP_v_KalmanUpdatePosNavi                                                                            */ /*!

  @brief           Navi path position update of the Kalman filter to fuse the navi path into the ACC-trajectory

  @description     Navi path position update of the Kalman filter to fuse the navi path into the ACC-trajectory.

		@startuml
		Start
		Partition CP_v_KalmanUpdatePosNavi {
		: Create intermediate Matrices for the Measurement Update;
		Repeat
			: Complete Pointer to the entries of Measurement Matrix;
			: Calculate Y position Noise and squring same;
			#Orange :<b>GDBKalmanMeasUpdate</b>: Update the Kalman Measuremet(Innovation);
		Repeat While (all relevant Samples)
		: Update kalman Dialogue;
		}
		End
		@enduml

  @return          -

  @param[in]       pFUSED_Samples : Navi path position samples with variance
                      nb_samples : Number of samples                                                             [0u ... CAL_MAX_NB_TRAJ_SAMPLES]
                      fx[i] : Samples of road-trajectory in longitudinal direction                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                              with i in [0u ... CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES in cp_ext.h
                      fVar[i] : variance information of trajectory samples                                       [Full range of float32  >= 0.F]                                                                                    [Full range of float32  >= 0.F]
                              with i in [0u ... CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES in cp_ext.h
                      fy[i] : Samples of road-trajectory in lateral direction                                    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                              with i in [0u ... CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES in cp_ext.h
  @param[in]       sNoiseModel : structure containing noise information
                      fNoiseOffset : Noise offset value                                                          [Full range of float32  >= 0.F]
                      fNoiseGradient : Gradient of noise distribution                                            [Full range of float32  >= 0.F]
  @param[out]      -

  @glob_in         pt_CPInput->t_RTE.pf_FCTBumperToCoG : distance from Bumper to Center of Gravity               [0.f ... 10.f]
  @glob_in         pt_CPOutput->CP_TrajectoryData.KafiEst : The Kalman filter base data
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         10.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void CP_v_KalmanUpdatePosNavi( const SLATE_t_PosSamples * pFUSED_Samples , CP_t_NoiseModelLinear sNoiseModel)
{
  uint16 i;
  float32 fxTgt,fxTgt2,fYNoise;

  GDBBaseMatrix_t KMat; /* Kalman gain */
  GDBBaseMatrix_t FVec;
  GDBBaseMatrix_t CMat;
  float32 KMatrix[CP_NB_TRAJ_STATE];
  float32 FVector[CP_NB_TRAJ_STATE];
  float32 CMatrix[CP_NB_TRAJ_STATE];

  /* Create intermediate Matrices for the Measurement Update */
  GDBKalmanCreateMat(&KMat, KMatrix, MATTYPE_VECTOR, CP_NB_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&FVec, FVector, MATTYPE_VECTOR, CP_NB_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&CMat, CMatrix, MATTYPE_VECTOR, (uint8)1, CP_NB_TRAJ_STATE );

  /* Sequential measurement updates for all relevant Targets */
  for ( i = 0u; i < pFUSED_Samples->nb_samples; i++ )
  {
    fxTgt = pFUSED_Samples->fx[i] + *pt_CPInput->t_RTE.pf_FCTBumperToCoG;
    fxTgt2 = fxTgt*fxTgt;
    /* Complete  Measurement Matrix C */
    CMat.pdData[VECT_MAT_INDEX(CP_sTRAJ_C0) ] = fxTgt2 * (1.0f / 2.0f); //PRQA S 0491
    /* Date: 2/25/2020, Reviewer: Gireesh, Reason: There is no side effects because of array subscripting to an object of poiter type */ 

    CMat.pdData[VECT_MAT_INDEX(CP_sTRAJ_C1) ] = fxTgt2 * fxTgt * C_SIXTH; //PRQA S 0491
    /* Date: 2/25/2020, Reviewer: Gireesh, Reason: There is no side effects because of array subscripting to an object of poiter type */

    fYNoise = sNoiseModel.fNoiseOffset + (sNoiseModel.fNoiseGradient * fxTgt) + pFUSED_Samples->fVar[i];
    fYNoise = SQR(fYNoise);

    /* Innovation */
    GDBKalmanMeasUpdate(&pt_CPOutput->CP_TrajectoryData.KafiEst, KMat, FVec, CMat, pFUSED_Samples->fy[i], fYNoise);
  }
  GDBKalmanUpdatePDiag(&pt_CPOutput->CP_TrajectoryData.KafiEst);
}


/*************************************************************************************************************************
  Functionname:    CP_b_NaviPathFusionSituation                                                                 */ /*!

  @brief           Check if navi path fusion should be done in this situation

  @description     Check if navi path fusion should be done in this situation
                   Following conditions are checked to fuse the NAVI path into the ACC-trajectory
                   Plausibility of NAVI-data, allowed street type (only highway), ego speed in valid range, 
                   valid NAVI path length relative to pick up range, no lane change situation, ego curve not too high 
                   (indicating a turning), no roadwork situation and plausibility of NAVI path approximation (temporarily 
                   deactivated), no probability of branch (leaving MPP), Navi ADAS Quality

		@startuml
		Start
		Partition CP_b_NaviPathFusionSituation {
		: Initialize navi path fusion situation to false;
		: Check the navi path data are plausible or not;
		: Allow Navi street type as highways;
		: Check EGO speed is in valid speed range or not;
		: Set the length of navi path as True;
		Note Left: Check if the length of the navi path \nexceeds 90% of the required pick-up distance -> if the \nlength of the navi path is too low, \ndon't fuse the navi path into the ACC-trajectory 
		If (FCT_CFG_ACC_LANE_ASSOCIATION is enabled) then (True)
			: Set ACC Pick up Distance using moving object base pick up range;
		Else(False)
			: Set ACC Pick up Distance which is always less than or equals 200;
		Endif
		If (approx length of the navi path < ACC Pick up Distance) then (True)
			: navi path lenth is not valid;
		Else (False)
			: Do Nothing;
		Endif
		: Set SI Lane Change Probability;
		If (check if Lane Change Probability is\n more than Maximum Lane Change prob and \nNot Steer Back Lane Change or\n input is Left Turn Indicator or \ninput is Right Turn Indicator) then (True)
			: Enable Ego Lane change;
		Else (False)
			: Do Nothing;
		Endif
		If (Absolute value of Lateral acceleration curve > CP_NAVI_SITU_MAX_EGO_CURVE) then (True)
			: High Ego curve indicates a turning;
		Else (False)
			: Do Nothing;
		Endif
		: Detected roadworks;
		: Set Navi data Quality as ADAS Quality;
		: Get plausible NAVI path approximation;
		If (conditions are fulfilled to fuse the \nNAVI path into the ACC-trajectory)then(True)
		Note Left: Check following parameters: \nNaviDataPlausible == TRUE && \nValidSpeedRange == TRUE && ValidPathLength == TRUE && \nEgoLaneChange == FALSE && HighEgoCurve == FALSE && \nRoadworks == FALSE && IsNaviPathApproxPlausible == TRUE && \nNaviDataQuality == TRUE
			: Set Navi Fusion Situation as TRUE;
		Else (False)
			: Do Nothing;
		Endif
		: Set CP Navi Lane Change Fusion Measure, \nCP Navi Valid Path Length Fusion Measure \nand CP Navi Valid Speed Range Fusion Measure;
		Partition FCT_SIMU {
			: Set debug information like Allowed Navi Street Type, \nValid Path Length, Ego Lane Change, High Ego Curve,\n Navi Data Reliable, Road works info, Valid Speed Range, \nNavi Path Approx Plausible info, Navi Data Quality \nand Navi Fusion Situation;
		}
		: Return Navi Fusion Situation;
		} 
		End
		@enduml

  @return          CPNaviPathSituationBits.b_IsNaviFusionSituation : information, if NAVI path fusion should be done in this situation  [TRUE, FALSE]

  @param[in]       b_LastNaviFusionState : Bit when navi path fusion is active                                                          [TRUE, FALSE]
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure
                      pt_FIPNaviData.b_NaviPathPlausible : Info if Navi path is plausible                                               [TRUE, FALSE]
                      pt_FIPNaviData.b_NaviPathIsHighway : Info if driving on a highway                                                 [TRUE, FALSE]
					  pt_FIPNaviData.b_NaviBranchProbability : Probability that ego will not follow the navi path 					    [TRUE, FALSE]
					  pt_FIPNaviData.b_NaviADASQuality : Info if navi has enough quality to be used 								    [TRUE, FALSE]
                      pt_FIPNaviData.f_NaviPathApproxLength : length of NAVI path, which is used for approximation of the NAVI path     [Full range of float32  >= 0.F]
                      t_LAInput.pt_MovingObjBasePickUpRange : Pick up range of base moving object                                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_SIT.ps_GetLaneChangeProbability : Lane change probability                                                       [-100 ... 100]
  @glob_out        CP_b_NaviCPsLaneChangeFusionMeas                                                  [TRUE, FALSE]
  @glob_out        CP_b_NaviCPValidPathLengthFusionMeas                                              [TRUE, FALSE]
  @glob_out        CP_b_NaviCPValidSpeedRangeFusionMeas                                              [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bAllowedNaviStreetTyp      [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bValidPathLength           [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsLaneChange              [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bHighEgoCurve              [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bNaviDataReliable          [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsRoadworks               [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bValidSpeedRange           [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsNaviPathApproxPlausible [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsSituation               [TRUE, FALSE]
  @glob_out		   CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bBranch            	     [TRUE, FALSE]
  @glob_out		   CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bNaviDataQuality           [TRUE, FALSE] 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    260:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-260-00061542 \n
                   261:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-261-00061542 \n
                   262:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-262-00061542 \n
                   263:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-263-00061542 \n
                   160:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-160-00061542 \n
      

  @created         -
  @changed         16.01.2017

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static boolean CP_b_NaviPathFusionSituation(boolean b_LastNaviFusionState)
{
  /* local variable to store lane change probability to check later for navi fusion*/
  uint8 u_SILaneChangeProb;
  float32 f_LengthApproxNaviPath;
  float32 f_AccPickUpDist;
  float32 f_Abs_EGODRVINTCURVEOBJSYNC;
  

  /*! Initialize navi path fusion situation to false -> final decision if fusion should be done */
  CPNaviPathSituationBits.b_IsNaviFusionSituation = FALSE;

  /*! Check if the navi path data are plausible. This includes check for multi lane. */
  CPNaviPathSituationBits.b_NaviDataPlausible = (pt_CPInput->pt_FIPNaviData->b_NaviPathPlausible);
 
  /*! Check for allowed street types: Currently only highways are allowed */
  CPNaviPathSituationBits.b_AllowedNaviStreetTyp = (pt_CPInput->pt_FIPNaviData->b_NaviPathIsHighway);

  /*! Check if EGO speed is in valid speed range: Above 100kmph is the requirement but hysteresis loop 
      is implemented with min. 90kmph */
  CPNaviPathSituationBits.b_ValidSpeedRange = CP_b_EgoSpeedInValidRange(b_LastNaviFusionState);

  /*! Check if the length of the navi path exceeds 90% of the required pick-up distance 
    -> if the length of the navi path is too low, don't fuse the navi path into the ACC-trajectory */
  CPNaviPathSituationBits.b_ValidPathLength = TRUE;
  f_LengthApproxNaviPath = (pt_CPInput->pt_FIPNaviData->f_NaviPathApproxLength);
 #if (FCT_CFG_ACC_LANE_ASSOCIATION)
  f_AccPickUpDist = *(pt_CPInput->t_LAInput.pt_MovingObjBasePickUpRange);
#else
  f_AccPickUpDist = MAX_FLOAT(FIP_PICK_UP_RANGE_DEFAULT_MIN, FIP_PICK_UP_RANGE_DEFAULT_TIMEGAP * SLATE_f_GetEgoVelObjSync());
  f_AccPickUpDist = MIN_FLOAT(f_AccPickUpDist, RW_FCT_MAX);
#endif
  if ( f_LengthApproxNaviPath < (CP_NAVI_SITU_MIN_PERC_PICKUP_DIST * f_AccPickUpDist) )
  {
    CPNaviPathSituationBits.b_ValidPathLength = FALSE;
  }

  /*! Check if lane change situation -> don't fuse the navi path into the ACC-trajectory in case of an ego lane change 
    (faster release of the object which is overtaken) */
  CPNaviPathSituationBits.b_EgoLaneChange = FALSE;
  u_SILaneChangeProb = pt_CPInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb;
  if ( (( u_SILaneChangeProb > CP_NAVI_SITU_MAX_LC_PROB)
    && (pt_CPInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase != LC_STEERBACK ))
#if FCT_CFG_CUSTOM_IO_INTERFACE
	|| ( (pSLATE_CustomInput->eTurnIndicator == eTurnIndicator_Left)||(pSLATE_CustomInput->eTurnIndicator == eTurnIndicator_Right) )
#endif /* end of FCT_CFG_CUSTOM_IO_INTERFACE */     
	 )
  {
    CPNaviPathSituationBits.b_EgoLaneChange = TRUE;
  }

  /*! Check if the ego curve is too high -> no fusion since a high ego curve indicates a turning */
  CPNaviPathSituationBits.b_HighEgoCurve = FALSE;
  f_Abs_EGODRVINTCURVEOBJSYNC = fABS(EGO_DRV_INT_CURVE_OBJ_SYNC);
  if(f_Abs_EGODRVINTCURVEOBJSYNC > CP_NAVI_SITU_MAX_EGO_CURVE)
  {
    CPNaviPathSituationBits.b_HighEgoCurve = TRUE;
  }


  /*! Check is a roadworks is detected -> no fusion */
  CPNaviPathSituationBits.b_Roadworks = CP_b_GetRoadIsRoadworks();


  CPNaviPathSituationBits.b_NaviDataQuality =  (pt_CPInput->pt_FIPNaviData->b_NaviPathIsADASQuality);
  /*! Check if the NAVI path approximation is plausible (eg. not instable for successive cycles) */
  /* Temporarily disabled: CPNaviPathSituationBits.bIsNaviPathApproxPlausible = FIP_b_GetNaviPathApproxIsPlausible(); */
  CPNaviPathSituationBits.bIsNaviPathApproxPlausible = TRUE;

  /*! Check if the conditions are fulfilled to fuse the NAVI path into the ACC-trajectory */
  if(   (CPNaviPathSituationBits.b_NaviDataPlausible == TRUE)
     && (CPNaviPathSituationBits.b_ValidSpeedRange == TRUE)   && (CPNaviPathSituationBits.b_ValidPathLength == TRUE)  
     && (CPNaviPathSituationBits.b_EgoLaneChange == FALSE)    && (CPNaviPathSituationBits.b_HighEgoCurve == FALSE) 
     && (CPNaviPathSituationBits.b_Roadworks == FALSE)        && (CPNaviPathSituationBits.bIsNaviPathApproxPlausible == TRUE) // PRQA S 3355
  /* date: 2017-05-15, reviewer: Ranjitha Hanumantharayappa , Reason : CPNaviPathSituationBits.bIsNaviPathApproxPlausible is always ture since False part is diabled*/

     && (CPNaviPathSituationBits.b_NaviDataQuality == TRUE)
    )
  {
    CPNaviPathSituationBits.b_IsNaviFusionSituation = TRUE;
  }

  /* Set meas freeze data: Ego lane change bit, valid path length bit, valid speed range bit */
  CP_b_NaviCPsLaneChangeFusionMeas = CPNaviPathSituationBits.b_EgoLaneChange;
  CP_b_NaviCPValidPathLengthFusionMeas = CPNaviPathSituationBits.b_ValidPathLength;
  CP_b_NaviCPValidSpeedRangeFusionMeas = CPNaviPathSituationBits.b_ValidSpeedRange;

#ifdef FCT_SIMU
  /*! Set debug infos */
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bAllowedNaviStreetTyp = CPNaviPathSituationBits.b_AllowedNaviStreetTyp;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bValidPathLength = CPNaviPathSituationBits.b_ValidPathLength;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsLaneChange = CPNaviPathSituationBits.b_EgoLaneChange;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bHighEgoCurve = CPNaviPathSituationBits.b_HighEgoCurve;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bNaviDataReliable = CPNaviPathSituationBits.b_NaviDataPlausible;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsRoadworks = CPNaviPathSituationBits.b_Roadworks;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bValidSpeedRange = CPNaviPathSituationBits.b_ValidSpeedRange;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsNaviPathApproxPlausible = CPNaviPathSituationBits.bIsNaviPathApproxPlausible;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bNaviDataQuality = CPNaviPathSituationBits.b_NaviDataQuality;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsSituation = CPNaviPathSituationBits.b_IsNaviFusionSituation;
#endif

  return CPNaviPathSituationBits.b_IsNaviFusionSituation;
}


/*************************************************************************************************************************
  Functionname:    CP_b_GetRoadIsRoadworks                                                                      */ /*!

  @brief           Check if a roadworks is detected

  @description     Check if a roadworks is detected based on the infos of the navi path and the internal roadworks 
                   detection (ROAD)

		@startuml
		Start
		Partition CP_b_GetRoadIsRoadworks {
		: Initialize the roadworks as false;
		Partition #LightBlue "**~#if SLATE_CFG_CAM_LANE_INTERFACE **" {
		: Get information if the navi path indicates a highway;
		: Get information if the camera lane indicates a roadworks;
		}
		Partition #LightBlue "**~#if SLATE_CFG_CAM_LANE_INTERFACE **" {
			If (if Highway is detected, and \nthe ego Longitudinal velocity < CP_NAVI_MAX_SPEED_ROADWORKS and \nthe camera indicate a roadworks) then (True)
				: road works is detected;
			Else (False)
				: Do Nothing;
			Endif
		}
		If (FIP Roadworks == FIP_ROADWORKS_DETECTED) then (True)
			: road works is detected;
		Else (False)
			: Do Nothing;
		Endif
		End
		@enduml

  @return          b_Roadworks : Information if roadworks is detected                       [TRUE, FALSE]

  @param[in]       -
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure
                      pt_FIPNaviData.b_NaviPathIsHighway : Info if driving on a highway     [TRUE, FALSE]
                      pt_FIPCamLane.b_Roadworks : Info if camera lane indicates a roadworks [TRUE, FALSE]
                      t_RTE.pf_EgoLongVel : velocity of the ego vehicle                     [-330.f ... 330.f]
                      t_FIPRoadType.pt_RoadWorks : Reference to FIP road works type         [Full range of FIP_t_RoadWorks as defined in fip_ext.h]
  @glob_out        -

  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         11.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static boolean CP_b_GetRoadIsRoadworks(void)
{
  boolean b_Roadworks;
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  boolean b_NaviPathHighway;
  boolean b_CamRoadworks;
#endif

  /*! Initialize the decision of the roadworks to false */
  b_Roadworks = FALSE;

#if (SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Get info if the navi path indicates a highway */
  b_NaviPathHighway = (pt_CPInput->pt_FIPNaviData->b_NaviPathIsHighway);
  /*! Get info if the camera lane indicates a roadworks */
  b_CamRoadworks = (pt_CPInput->pt_FIPCamLane->b_Roadworks);
#endif
  
  
  /*! Check if a roadworks is detected: 
      -> Highway is detected and the ego vehicle is slow and the camera lane markers indicate a roadworks
      -> The internal roadworks (ROAD) detection indicates a roadworks */
  
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  if ( (b_NaviPathHighway == TRUE) && 
        (*pt_CPInput->t_RTE.pf_EgoLongVel < CP_NAVI_MAX_SPEED_ROADWORKS) &&
        (b_CamRoadworks == TRUE)
      ) 
  {
    b_Roadworks = TRUE;
  }

#endif

  if ((pt_CPInput->pt_FIPRoadType->t_FIPRoadWorks) == FIP_ROADWORKS_DETECTED)
  {
    b_Roadworks = TRUE;
  }

  return b_Roadworks;
}


/*************************************************************************************************************************
  Functionname:    CP_b_EgoSpeedInValidRange                                                                    */ /*!

  @brief           Check if EGO speed is in valid range

  @description     Check if EGO speed is in valid range for navi path fusion

		@startuml
		Start
		Partition CP_b_EgoSpeedInValidRange {
		If (if Navi fusion was active) then (True)
			If (Ego Longitudinal Velocity >= CP_NAVI_HYST_MIN_VALID_SPEED) then (True)
				: Indicating Speed is in valid range;
			Else (False)
				: Do Nothing;
			Endif
		Else (False)
			If (Ego Longitudinal Velocity >= CP_NAVI_REQ_VALID_SPEED) then (True) 
				: Indicating Speed is in valid range;
			Else (False)
				: Do Nothing;
			Endif
		Endif 
		}
		End
		@enduml

  @return          b_SpeedInValidRange : Boolean indicating if EGO speed is in valid range                                [TRUE, FALSE]
        
  @param[in]       b_LastNaviFusionState : Boolean indicating if fusion was active in previous cycle (used in hysteresis) [TRUE, FALSE]
  @param[out]      -

  @glob_in         pt_CPInput->t_RTE.pf_EgoLongVel : ego speed                                                            [-330.f ... 330.f]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    261:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-261-00061542\n

  @created         -
  @changed         11.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static boolean CP_b_EgoSpeedInValidRange(boolean b_LastNaviFusionState)
{
  boolean b_SpeedInValidRange = FALSE;
  /* Hysteresis Rule: 
     a) Navi fusion is inactive and EGO Speed is above 100km/h then VALID
     b) Once VALID, remain in state as long as EGO speed is greater than 90km/h
  */
  if(b_LastNaviFusionState == TRUE)
  {
    /* Fusion was active before, therefore check for hysteresis min.*/
    if(*pt_CPInput->t_RTE.pf_EgoLongVel >= CP_NAVI_HYST_MIN_VALID_SPEED)
    {
      b_SpeedInValidRange = TRUE;
    }
  }else 
  {
    /* Fusion was NOT active, check if EGO speed is greater than required threshold */
    if(*pt_CPInput->t_RTE.pf_EgoLongVel >= CP_NAVI_REQ_VALID_SPEED)
    {
      b_SpeedInValidRange = TRUE;
    }
  }
  return b_SpeedInValidRange;
}


/*************************************************************************************************************************
  Functionname:    CP_v_NaviSetMeasData                                                                             */ /*!

  @brief           Set navi CP meas freeze data

  @description     Set navi CP meas freeze data

		@startuml
		Start
		Partition CP_v_NaviSetMeasData {
		: Set navi CP measure freeze data;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      p_NaviDebugMeasFreeze : Structure for navi CP meas freeze
                      b_NaviFusionExternalSwitch                                                   [TRUE, FALSE]
                      b_IsLaneChangeFusion                                                         [TRUE, FALSE]
                      b_ValidPathLengthFusion                                                      [TRUE, FALSE]
                      b_ValidSpeedRangeFusion                                                      [TRUE, FALSE]

  @glob_in         CP_b_NaviCPExternalSwitchMeas : meas freeze data: NAVI path fusion enabled      [TRUE, FALSE]
  @glob_in         CP_b_NaviCPsLaneChangeFusionMeas : meas freeze data: Ego lane change bit        [TRUE, FALSE]
  @glob_in         CP_b_NaviCPValidPathLengthFusionMeas : meas freeze data: valid path length bit  [TRUE, FALSE]
  @glob_in         CP_b_NaviCPValidSpeedRangeFusionMeas : meas freeze data : valid speed range bit [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             meas freeze data have to be determined (CP_b_NaviCPExternalSwitchMeas, CP_b_NaviCPsLaneChangeFusionMeas, 
                   CP_b_NaviCPValidPathLengthFusionMeas and CP_b_NaviCPValidSpeedRangeFusionMeas)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         11.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void CP_v_NaviSetMeasData(CP_t_NaviDebugMeasInfo * p_NaviDebugMeasFreeze)
{
  p_NaviDebugMeasFreeze->b_NaviFusionExternalSwitch = CP_b_NaviCPExternalSwitchMeas;
  p_NaviDebugMeasFreeze->b_IsLaneChangeFusion = CP_b_NaviCPsLaneChangeFusionMeas;
  p_NaviDebugMeasFreeze->b_ValidPathLengthFusion = CP_b_NaviCPValidPathLengthFusionMeas;
  p_NaviDebugMeasFreeze->b_ValidSpeedRangeFusion = CP_b_NaviCPValidSpeedRangeFusionMeas;
}


#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    CP_v_InitDebugNaviInfo                                                                       */ /*!

  @brief           Initialization of debug info

  @description     Initialization of debug info

		@startuml
		Start
		Partition CP_v_InitDebugNaviInfo {
		: Initialize debug information;
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        CP_TrajFusionDebugInfo : Trajectory fusion debug information
                      NaviPathFusionDebug
                        IsSituation
                          bAllowedNaviStreetTyp                  [FALSE]
                          bValidPathLength                       [FALSE]
                          bIsLaneChange                          [FALSE]
                          bHighEgoCurve                          [FALSE]
                          bNaviDataReliable                      [FALSE]
                          bIsRoadworks                           [FALSE]
                          bValidSpeedRange                       [FALSE]
                          bIsNaviPathApproxPlausible             [FALSE]
                          bIsSituation                           [FALSE]
                        Samples[i] with i in [0u ... FCT_NAV_NUM_SEG] and FCT_NAV_NUM_SEG in Rte_SWCEmAdapat_Type.h
                          fGradient                              [0.f]
                          fDistLCStdDev                          [0.f]
                          fXPos                                  [0.f]
                          fYPos                                  [0.f]
                          fStdDev                                [0.f]
                        PathFusionInfo
                          fDistGenStdDev                         [0.f]
                          fApproxC0StdDev                        [0.f]
                          fNaviPathToPolySumSqDistAvgStdDev      [0.f]
                          fNaviPathEgoDiffStdDev                 [0.f]
                          fSumLengthNaviPathStdDev               [0.f]
                          fIsHighway                             [0.f]
                          fDiffTrajNavi                          [0.f]
                          fDiffTrajNaviStd                       [0.f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component
  @c_switch_full   FCT_SIMU : Simulation config switch

  @pre             #ifdef FCT_SIMU
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         11.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void CP_v_InitDebugNaviInfo(void)
{
  uint8 i;

  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bAllowedNaviStreetTyp = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bValidPathLength = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsLaneChange = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bHighEgoCurve = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bNaviDataReliable = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsRoadworks = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bValidSpeedRange = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsNaviPathApproxPlausible = FALSE;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.IsSituation.bIsSituation = FALSE;

  for (i = 0u; i < CAL_MAX_NB_TRAJ_SAMPLES; i++)
  {
    CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fGradient = 0.f;
    CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fDistLCStdDev  = 0.f;
    CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fXPos = 0.f;
    CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fYPos = 0.f;
    CP_TrajFusionDebugInfo.NaviPathFusionDebug.Samples[i].fStdDev = 0.f;
  }

  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fDistGenStdDev = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fApproxC0StdDev = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fNaviPathToPolySumSqDistAvgStdDev = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fNaviPathEgoDiffStdDev = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fSumLengthNaviPathStdDev = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fIsHighway = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fDiffTrajNavi = 0.f;
  CP_TrajFusionDebugInfo.NaviPathFusionDebug.PathFusionInfo.fDiffTrajNaviStd = 0.f;
}
#endif /*!< FCT_SIMU */
/** @} end defgroup */
#endif  /* (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */
#endif /* FCT_CFG_COURSE_PREDICTION */
