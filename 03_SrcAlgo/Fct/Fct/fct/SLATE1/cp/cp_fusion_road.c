/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_fusion_road.c

DESCRIPTION:               Fusion of road info into ACC trajectory

AUTHOR:                    Matthias Thomi, Gregor Powarzynski

CREATION DATE:             07.05.2012

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_COURSE_PREDICTION)
#if (FCT_CFG_ROAD_INPUT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_fusion_road Road fusion
@ingroup cp_trajectory
@brief         Responsible for computation of road data based trajectory. \n\n

@description    This module is responsible for generating samples of road trajectory up to a maximum distance,
                evaluation check whether the Road trajectory can be used for the fusion of the ACC trajectory,identification
				of plausible shape of the road trajectory,checks if road trajectory can be used for fusion with
				ACC trajectory and use the traces of objects to verify the road trajectory.
@{
*/
/*****************************************************************************
  MACROS 
*****************************************************************************/
#if (CP_CFG_ENABLE_EXTEND_ROAD_FUSION_DIST)
/* Maximum x distance of compensated road estimation for artificial road extension*/
#define CP_ROAD_FUSION_MAX_DIST_RE (150.0f)
/* Maximum difference in x distance between last road cluster and last compensated cluster */
#define CP_ROAD_FUSION_MAX_DIFF_DIST_RE (20.0f)
/* Maximum extension of artificial road fusion distance */
#define CP_ROAD_FUSION_MAX_EXT_RE (30.0f)
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

#define CP_MIN_TRACE_INFO_IDX_REOK 3
#define CP_MAX_TRACE_INFO_IDX_REOK 9

SET_MEMSEC_CONST(CP_REFusionDistEgoSpeed)
static const GDBLFunction_t CP_REFusionDistEgoSpeed = {// PRQA S 3218
/* date: 2015-04-28, reviewer:Gangadhar Badiger, reason: static local for saving data across function calls */

  CP_MINREFUSIONEGOSPEEDDIST,
  CP_MAXREFUSIONEGOSPEEDDIST,
  (( CP_MAXREFUSIONEGOSPEEDDIST - CP_MINREFUSIONEGOSPEEDDIST ) / ( CP_MAXREFUSIONEGOSPEED - CP_MINREFUSIONEGOSPEED )),
  CP_MINREFUSIONEGOSPEEDDIST 
  -( (( CP_MAXREFUSIONEGOSPEEDDIST - CP_MINREFUSIONEGOSPEEDDIST ) / ( CP_MAXREFUSIONEGOSPEED - CP_MINREFUSIONEGOSPEED )) 
  * CP_MINREFUSIONEGOSPEED)
};

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CP_b_FusionRoadPlausabilityVote(const SLATE_t_PosSamples * pEGO_Samples , const SLATE_t_PosSamples * pRE_Samples);
static boolean CP_b_FusionRoadSituationVote( float32 fFusionSpeedTreshold, CP_t_TrajectoryState *pTrajState );
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
static boolean CP_b_FusionRoadTraceVote( const uint8 pTrace_QualityValid[], const CP_t_Trace2CurveParallelism pTrace_REPara[], float32 *fFusionSpeedTreshold );
#endif /* ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT)) */



/*************************************************************************************************************************
  Functionname:    CP_v_CalculateRoadSamples                                                                           */ /*!

  @brief           Generate samples of road trajectory up to a maximum distance

  @description     Generate samples of road trajectory up to a maximum distance. Maximum distance is given by the longitudinal
                   distance of the last cluster which has been evaluated by the road (fRangeMaxLeft/fRangeMaxRight).
                   The maximum fusion distance can be artificially increased for premium sensors when the longitudinal distance of 
                   the last seen cluster and the last cluster which actually has been used for the prediction 
                   (fmaxXLeftCompensated/fmaxXRightCompensated), is below a certain threshold.                   

		@startuml
		Start
		Partition CP_v_CalculateRoadSamples{
		: Initialize road samples;
		: Get course data road estimation;
		: Calculate the (x,y)-Coordinates of the given CourseData by polynomial clothoid-approximation;
		: Moves Samples From CoG To Sensor;
		: Determine maximum fusion distance for road estimation;
		Partition #LightBlue "**~#if SIT_CFG_TRAFFIC_DENSITY **" {
		: Determine maximum road cluster distance for Raod estimation;
		If (Maximum fusion distance < CP_ROAD_FUSION_MAX_DIST_RE and (maximum fusion distance - maximum road cluster distance) < CP_ROAD_FUSION_MAX_DIFF_DIST_RE) then (True)
			: Update Maximum Longitudinal distance for Road estimation;
		Else (False)
			: Do Nothing;
		Endif
		}
		: Limit Samples to a given Longitudinal Distance;
		}
		End
		@enduml

  @return          void

  @param[in,out]   pRE_PosSamples : Pointer to structure containing equidistant samples of road trajectory

  @glob_in         pt_CPInput : Pointer to CP input structure
                      pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated : Compensated maximum distance of left road border    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated : Compensated maximum distance of right road border  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_FIPRoad->t_FIPRoadEstimation.fRangeMaxLeft : Maximum distance of left road trajectory                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_FIPRoad->t_FIPRoadEstimation.fRangeMaxRight : Maximum distance of right road trajectory                 [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        - 

  @c_switch_part   CP_CFG_ENABLE_EXTEND_ROAD_FUSION_DIST : Configuration switch to enable an artificial extension of the road fusion
  @c_switch_full   FCT_CFG_ROAD_INPUT                    : Road estimation input to FCT
  @c_switch_full   FCT_CFG_COURSE_PREDICTION             : FCT support for CP sub-component 

  @pre             Road estimation needs to be available
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         13.01.2016
  @changed         13.01.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void CP_v_CalculateRoadSamples(SLATE_t_PosSamples * pRE_PosSamples)
{
  CP_t_CourseData CourseDataRE;
  float32 fXDistMaxRE;
#if (CP_CFG_ENABLE_EXTEND_ROAD_FUSION_DIST)
  float32 fXDistClusterRE;
#endif


  /* Initialize road samples */
  CP_v_InitPosSamples(pRE_PosSamples);

  /* Get road estimation in correct format */
  CourseDataRE = CP_t_GetRoadEstimationAsCourseData();

  /* Sample the road trajectory */
  CP_v_SamplePosClothApprox(&CourseDataRE, CPClothApproxType_PolynomialOnly, CP_SAMPLEDIST_MAX, pRE_PosSamples, CP_XDIST_FIRST_SAMPLE_ZERO_OFFSET);

  CP_v_MoveSamplesFromCoGToSensor(pRE_PosSamples);

  /* Determine maximum fusion distance */
  fXDistMaxRE = MAX_FLOAT( (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated), (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated) );

#if (CP_CFG_ENABLE_EXTEND_ROAD_FUSION_DIST)
  /* Determine maximum road cluster distance */
  fXDistClusterRE = MAX_FLOAT((pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fRangeMaxLeft), (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fRangeMaxRight));
  
  /* In case maximum fusion distance and maximum road cluster distance are approximately the same, we 
     artificially extend the fusion distance. As an effect, the road has a higher weighting within the fusion
     process. */
  if(   (fXDistMaxRE < CP_ROAD_FUSION_MAX_DIST_RE)
     && ((fXDistMaxRE - fXDistClusterRE) < CP_ROAD_FUSION_MAX_DIFF_DIST_RE))
  {
    fXDistMaxRE = MIN_FLOAT(CP_ROAD_FUSION_MAX_DIST_RE,fXDistMaxRE+CP_ROAD_FUSION_MAX_EXT_RE);
  }
#endif

  CP_v_LimitSamplesXDist( fXDistMaxRE, pRE_PosSamples );
}


/*************************************************************************************************************************
  Functionname:    CP_v_FusionEvalRoad                                                                                 */ /*!

  @brief           Evaluation if the Road trajectory can be used for the fusion of the ACC trajectory

  @description     The Road trajectory can only be fused if it fulfills certain quality measures: The 
                   ego velocity has to be sufficiently high, the confidence as well as range of the 
                   Road trajectory must be above given thresholds, and the shape of the Road trajectory
                   shall not have an S-shape

		@startuml
		Start
		Partition CP_v_FusionEvalRoad {
		Partition #LightBlue "**~#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT) **" {
		: Update Fusion Road Estimation Trace Vote Criterion;
		}
		: Update Fusion Situation Criterion for RE;
		: Update Fusion Plausible Criterion for RE;
		If (Fusion Trace Vote Criterion, Fusion Situation Criterion and Fusion Plausible Criterion are set) then (True)
			: Set road estimation fusion range;
		Else (False)
			: Do Nothing;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       pEGO_PosSamples : Pointer to structure containing samples of VDY trajectory
  @param[in]       pRE_PosSamples : Pointer to structure containing samples of Road trajectory
                      nb_samples : Number of samples of road trajectory                                                         [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
  @param[in]       pTrace_Params : Pointer to Structure used to store data which reflects the relationship of traces with road

  @glob_in         pt_CPOutput->CP_TrajectoryData.State : CP Trajectory State 
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData.State.FusTraceCrit : Bit set when if CPMOTraceFusionCriterion returns TRUE                                     [TRUE,FALSE]
                      CP_TrajectoryData.State.FusionRoadstimation : Bit field which indicates whether the Road trajectory is used for the fusion of 
                                                                    the ACC trajectory                                                                 [TRUE,FALSE]
                      CP_TrajectoryData.State.EgoCourseOnly : Bit field which indicates whether the ACC trajectory is based only on the VDY trajectory [TRUE,FALSE]
                      CP_TrajectoryData.fRoadEstFusRange : Range in longitudinal direction up to which the Road trajectory is used for the fusion for 
                                                           the ACC trajectory                                                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_part   FCT_CFG_ROAD_INPUT                  : Road estimation input to FCT
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ROAD_INPUT                  : Road estimation input to FCT
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component 

  @pre             Road needs to be available
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability   147:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-147-00061542 \n
                  246:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-246-00061542 \n
                  247:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-247-00061542 \n
                  248:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-248-00061542 \n
                  249:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-249-00061542 \n
                  149:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-149-00061542 \n


  @created         04.02.2016
  @changed         04.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
void CP_v_FusionEvalRoad(SLATE_t_PosSamples * pEGO_PosSamples, SLATE_t_PosSamples * pRE_PosSamples, CP_t_InputSourceParams * pTrace_Params)
#else
void CP_v_FusionEvalRoad(SLATE_t_PosSamples * pEGO_PosSamples, SLATE_t_PosSamples * pRE_PosSamples)
#endif
{
  boolean bFusRETraceVoteCriterion = 0u;
  boolean bFusREPlausibleCriterion = 0u;
  boolean bFusRESituationCriterion = 0u;

  float32 fFusionSpeedTreshold = CP_MAXFUSIONSPEED;
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
  /* Determine the fusion speed threshold. The Road trajectory is only considered for the ACC trajectory 
     if the ego velocity is above a certain threshold. In case a sufficient number of traces are parallel to 
     the road, this threshold can be reduced.*/
  bFusRETraceVoteCriterion = CP_b_FusionRoadTraceVote(pTrace_Params->Trace_QualityValid, pTrace_Params->Trace_REPara, &fFusionSpeedTreshold);
#endif
  /* Save trace voting for RE in state bit */
  pt_CPOutput->CP_TrajectoryData.State.FusTraceCrit = bFusRETraceVoteCriterion;
  
  /* Velocity hysteresis and situation check. */
  bFusRESituationCriterion = CP_b_FusionRoadSituationVote(fFusionSpeedTreshold, &pt_CPOutput->CP_TrajectoryData.State);


  /* Do plausibility check only if Situation is OK. This is more Runtime efficient */
  bFusREPlausibleCriterion = CP_b_FusionRoadPlausabilityVote(pEGO_PosSamples , pRE_PosSamples);


  if(   (bFusRETraceVoteCriterion != FALSE)
     && (bFusRESituationCriterion != FALSE)
     && (bFusREPlausibleCriterion != FALSE))
  {
    pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation = TRUE;
    pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly       = FALSE;

    /* Set road estimation fusion distance */
    pt_CPOutput->CP_TrajectoryData.fRoadEstFusRange = (float32)pRE_PosSamples->nb_samples * CP_SAMPLE_RESOLUTION_X;
  }
}

/*************************************************************************************************************************
  Functionname:    CP_b_FusionRoadPlausabilityVote                                                                     */ /*!

  @brief           Identifies a plausible shape of the road trajectory.

  @description     Identifies a plausible shape of the road trajectory. An implausible shape is given by e.g. an s-shape
                   of the road trajectory. In this case, the longitudinal distance, for which the deviation between the vdy-trajectory
                   and the road trajectory exceeds a given threshold, is saved. Once the distance is reached by the ego-vehicle,
                   the road is not longer used for the fusion for the ACC trajectory.

		@startuml
		Start
		Partition CP_b_FusionRoadPlausabilityVote {
		: Get VDY fc0 and fphi;
		Repeat
			: Calculate Distance between Ego and road samples;
			: Calculate left threshold curvature and right threshold based on calculated difference between VDY and road samples;
			If (Samples of road-trajectory in lateral direction > Left threshold or Right threshold > Samples of road-trajectory in lateral direction) then (True)
				: Plausibility Vote set to false;
			Else (False)
			Endif
			If (Road sample > 0) then (True)
				: Do derivate of ego course and road estimation;
				If (Trajectory sample > 1) then (True)
					: Do again derivate of ego course and road estimation;
				Else (False)
				Endif
				: Calculate First derivation of RE and First derivation of Ego course;
				If (Trajectory sample > 1) then (True)
					: calculate Second derivation of Ego course and RE;
				Else (False)
				Endif
			Endif
			: Calculate Absolute distance to Ego for RE;
			If (deviation == 0 and Absolute distance to Ego < CP_PLAUSIBILITY_S_CURVE_CORRIDOR) then (True)
				: Set deviation as 0;
			Else (False)
				If (distance to Ego for RE < 0) then (True)
					: Set deviation as -1;
				Else (False)
					: Set deviation as 1;
				Endif
			Endif
			: Calculate absolute value of Second derivation of RE and Second derivation of Ego course;
			If (last deviation != 0 && deviation != last deviation && absolute(Second derivation of RE) > absolute(Second derivation of Ego course)) then (True)
				: S curve detected;
			Else (False)
			Endif
			: Update Last deviation value using current deviation value; 
		Repeat While (For all samples of road trajectory)
		If (Check if S curve is Detected) then (True)
			: Plausibility Vote set to false;
		Else (False)
			: Do Nothing;
		Endif
		}
		End
		@enduml

  @return          ret : Info if road trajectory shape is plausible [TRUE,FALSE]
  
  @param[in,out]   pEGO_Samples : Pointer to structure containing position samples of VDY trajectory
                     fx[i] : Samples of vdy-trajectory in longitudinal direction                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                             and i in [0 CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES as in cp_ext.h
                     fy[i] : Samples of vdy-trajectory in lateral direction                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                             and i in [0 CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES as in cp_ext.h
  @param[in,out]   pRE_Samples : Pointer to structure containing position samples of Road trajectory
                     fx[i] : Samples of road-trajectory in longitudinal direction                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                             and i in [0 CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES as in cp_ext.h
                     fy[i] : Samples of road-trajectory in lateral direction                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                             and i in [0 CAL_MAX_NB_TRAJ_SAMPLES] and CAL_MAX_NB_TRAJ_SAMPLES as in cp_ext.h
                     nb_samples : Number of samples of road trajectory                                        [0 ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         pt_CPOutput : Pointer to CP output structure
                      CP_CourseData.fCurve : Radius of the curve provided by the VDY trajectory                               [-1 ... +1] m^(-1)
                      CP_CourseData.SideSlipAngle : Sideslip angle of the curve provided by the VDY trajectory                [-PI ... PI] 
                      CP_TrajectoryData.fDistXUnplausibleSCurve : Longitudinal distance at which an unplausible 
                                                                  s-curve has been detected for the road-trajectory           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_LAInput.pt_ScaleBracketState : state of trace bracket adaption                                        [LA_t_ScaleBracketState as defined in la_ext.h]
                      t_RTE.pf_FCTBumperToCoG : Distance from Bumper to Center of Gravity                                     [-100.f ... 100.f] m
                      t_RTE.pf_EgoLongVel : Ego velocity provided by VDY                                                      [-330.f ... 330.f] m/s 
  @glob_out        pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve : Longitudinal distance at which an unplausible 
                                                                            s-curve has been detected for the road-trajectory [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m


  
  @c_switch-part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Configuration switch which moves trace brackets in case of ego lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Configuration switch which moves trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch which moves trace brackets w.r.t. BLINKER FEATURE
  @c_switch_part   CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE                             : Configuration switch to limit Unplausible S Curve value to enable Road Fusion for longer duration
  @c_switch_full   FCT_CFG_ROAD_INPUT                                                 : Road estimation input to FCT
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                                          : FCT support for CP sub-component FCT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    249:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-249-00061542 \n

  @created         08.02.2016
  @changed         08.02.2016

  @author           Norman Apel | norman.apel@contiautomotive.com | +49 (8382) 9699-365
**************************************************************************** */
static boolean CP_b_FusionRoadPlausabilityVote(const SLATE_t_PosSamples * pEGO_Samples , const SLATE_t_PosSamples * pRE_Samples)
{
  boolean ret = TRUE;
  uint32  i;
  float32 fDistEgoRe;
  float32 fc0 = pt_CPOutput->CP_CourseData.fCurve;
  float32 fphi= pt_CPOutput->CP_CourseData.SideSlipAngle;
  float32 fx,fxx,fxxx,fxL,fxR,fLeftThresh,fRightThresh;
  sint8   deviation = 0;/*1 left, 0 neutral, -1 right*/
  sint8   lastdeviation = 0;/*1 left, 0 neutral, -1 right*/
  float32 fDYDX_RE = 0.0f, fDYDX2_RE = 0.0f, fDYDX_last_RE = 0.0f, fDX_RE = 1.0f;
  float32 fDYDX_EGO = 0.0f, fDYDX2_EGO = 0.0f, fDYDX_last_EGO = 0.0f, fDX_EGO = 1.0f;
  float32 fabs_fDYDX2_RE;
  float32 fabs_fDYDX2_EGO;
  float32 f_DistXUnplausibleSCurve;
  float32 f_Abs_DistEgoRe;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  const float32 f_DistXUnplSCurveLastCycle = pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve;
  const LA_t_ScaleBracketState LC_State = *(pt_CPInput->t_LAInput.pt_ScaleBracketState);
#endif
#endif
  for(i=0u;i < pRE_Samples->nb_samples;i++)
  {
    fDistEgoRe = pRE_Samples->fy[i] - pEGO_Samples->fy[i];

    fx   = pRE_Samples->fx[i]+*pt_CPInput->t_RTE.pf_FCTBumperToCoG;/*COF2COG transformation*/
    fxx  = SQR(fx);
    fxxx = fxx *  fx * CP_f_GetPlausibleC1AtSpeed(*pt_CPInput->t_RTE.pf_EgoLongVel)*C_SIXTH;
    fxx  = fxx * fc0 * 0.5F;
    fxL  = fx*(fphi+CP_PLAUSIBILITY_HIGHWAY_SLIP_OFFSET);/*tan(phi) = phi*/
    fxR  = fx*(fphi-CP_PLAUSIBILITY_HIGHWAY_SLIP_OFFSET);/*tan(phi) = phi*/
    /*starting with actual curve, check if RE is outside possible curve*/
    fLeftThresh  = fxL + fxx + (fxxx + CP_PLAUSIBILITY_DEVIATION_CORRIDOR);
    fRightThresh = fxR + fxx - (fxxx + CP_PLAUSIBILITY_DEVIATION_CORRIDOR);
    if((pRE_Samples->fy[i] > fLeftThresh) || (fRightThresh > pRE_Samples->fy[i]))
    {
      ret = FALSE;
    }
    /*the deviation of re should be to one side. s-curves are not accepted*/
    if(i>0u)
    {
      /*numeric calculation of 2. derivate of ego course and road estimation*/
      fDX_RE  = 1.0f/(pRE_Samples->fx[i]-pRE_Samples->fx[i-1]);
      fDX_EGO = 1.0f/(pEGO_Samples->fx[i]-pEGO_Samples->fx[i-1]);
      if(i>1u)
      {
        fDYDX_last_RE  = fDYDX_RE;
        fDYDX_last_EGO = fDYDX_EGO;
      }
      fDYDX_RE  = (pRE_Samples->fy[i]-pRE_Samples->fy[i-1])   * fDX_RE;
      fDYDX_EGO = (pEGO_Samples->fy[i]-pEGO_Samples->fy[i-1]) * fDX_EGO;
      if(i>1u)
      {
        fDYDX2_RE  = (fDYDX_last_RE  - fDYDX_RE)  * fDX_RE;
        fDYDX2_EGO = (fDYDX_last_EGO - fDYDX_EGO) * fDX_EGO;
      }
    }
    f_Abs_DistEgoRe = fABS(fDistEgoRe);
    if ((deviation == 0) && (f_Abs_DistEgoRe < CP_PLAUSIBILITY_S_CURVE_CORRIDOR))
    {
      deviation = 0;
    }
    else
    {
      if(fDistEgoRe<0.0F)
      {
        deviation = -1;
      }
      else
      {
        deviation =  1;
      }
    }
    fabs_fDYDX2_RE  = fABS(fDYDX2_RE);
    fabs_fDYDX2_EGO = fABS(fDYDX2_EGO);

    if((lastdeviation != 0) && (deviation != lastdeviation) && (fabs_fDYDX2_RE > fabs_fDYDX2_EGO))
    {
      f_DistXUnplausibleSCurve = MAX_FLOAT(pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve,0.0f);
      pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve = ( pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve < pRE_Samples->fx[i] ) ? pRE_Samples->fx[i] : f_DistXUnplausibleSCurve;
#if (CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE)
      pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve = MIN_FLOAT(pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve, CP_MIN_DISTX_UNPLAUSIBLE_SCURVE);
#endif /* (CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE) */
    }
    lastdeviation = deviation;
  }
  
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  /*! In case of a lane change, reset the detected S-Curve */
  if( (f_DistXUnplSCurveLastCycle < (pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve - C_F32_DELTA)) &&
      ( (LC_State == SLATE_PRE_LANE_CHANGE_LEFT) || 
        (LC_State == SLATE_PRE_LANE_CHANGE_RIGHT)
      )
    )
  {
    pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve = f_DistXUnplSCurveLastCycle;
#if (CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE)
    pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve = MIN_FLOAT(f_DistXUnplSCurveLastCycle, CP_MIN_DISTX_UNPLAUSIBLE_SCURVE);
#endif /* (CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE) */
  }
#endif

  if(pt_CPOutput->CP_TrajectoryData.fDistXUnplausibleSCurve > C_F32_DELTA)
  {
    ret = FALSE;/*example C_2008.02.01_at_11.08.05 00:15:36*/
  }

  return ret;
}



/*************************************************************************************************************************
  Functionname:    CP_b_FusionRoadSituationVote                                                                        */ /*!

  @brief           Checks if road trajectory can be used for fusion with ACC trajectory

  @description     The road trajectory shall only be considered for the fusion with the ACC trajectory if it fulfills 
                   given quality thresholds, which comprise the ego-velocity, the range of left and/or right road-trajectory,
                   and the confidence.

		@startuml
		Start
		Partition CP_b_FusionRoadSituationVote {
		: Set Confidence of left and right side estimation of road;
		Partition FCT_CFG_INPUT_PREPROCESSSING {
			: Set Road Type;
		}
		If (Fusion Hysteresis Ego Speed is fulfilled) then (True)
			If(Ego Longitudinal Velocity < (Fusion Speed Threshold - CP_FUSIONSPEEDHYSTOFFSET)) then (True) 
				: Don’t set Fusion Hysteresis Ego Speed;
			Else (False)
				: Do Nothing;
			Endif
		Else (False)
			If (Ego Longitudinal Velocity > Fusion Speed Threshold) then (True)
				: Set Fusion Hysteresis Ego Speed;
			Else (False)
				: Do Nothing;
			Endif
		Endif
		If (Fusion Hysteresis Left Road Range Confidence is fulfilled) then (True)
			If (Estimated Confident maximum range of road on left side < math Linear function \nor Left Confidence < CP Minimum Fusion Road Confidence) then (True)
				: Don’t set Fusion Hysteresis Left Road Range Confidence;
			Else (False)
				: Do Nothing;
			Endif
		Else (False)
			If (Estimated Confident maximum range of road on left side > math linear function \nand Left Confidence > CP_MAXFUSIONEOROADCONFIDENCE) then (True)
				: Set Fusion Hysteresis Left Road Range Confidence;
			Else (False)
				: Do Nothing;
			Endif
		Endif
		If (Fusion Hysteresis Right Road Range Confidence is fulfilled) then (True)
			If (Estimated Confident maximum range of road on right side < math liner function \nor Right Confidence < CP Minimum Fusion Road Confidence) then (True)
				: Don’t set Fusion Hysteresis Right Road Range Confidence;
			Else (False)
				: Do Nothing;
			Endif
		Else (False)
			If (Estimated Confident maximum range of road on right side > math liner function \nand Right Confidence > CP Miximum Fusion Road Confidence) then (True)
				: Set Fusion Hysteresis Right Road Range Confidence;
			Else (False)
				: Do Nothing;
			Endif
		Endif
		If (Fusion Ego radius hysteresis is fulfilled) then (True)
			If (Absolute Ego Curve > Max Fusion Curve) then (True)
				: Don’t Set Fusion Ego radius hysteresis;
			Else (False)
				: Do Nothing;
			Endif
		Else (False)
			If (Absolute Ego Curve < Min Fusion Curve) then (True) 
				: Set radius hysteresis;
			Else (False)
				: Do Nothing;
			Endif
		Endif
		: Set default neutral values for additional range-conf criterion;
		Partition In_case_of_lane_change {
		If (Lateral Road Border At Fusion Range >= CP_CURVEDIRECTIONTHRESH and \nLateral Road Border At Fusion Range > Lateral Ego Curve At Fusion Range) then (True)
			: Don’t set Left Range Confidence Addition Criterion;
		Else (False)
			: Do Nothing;
		Endif
		If (Lateral Road Border At Fusion Range <= -CP_CURVEDIRECTIONTHRESH and \nLateral Road Border At Fusion < Lateral Ego Curve At Fusion Range) then (True)
			: Don’t set Left Range Confidence Addition Criterion;
		Else (False)
			: Do Nothing;
		Endif
		If (if ego speed fusion criteria is fulfilled and \n(left side of road estimation and Left Range Confidence Addition Criterion are fulfilled) or \n(right side of road estimation and Right Range Confidence Addition Criterion are fulfilled) and \nego radius fusion criteria is fulfilled and \nRoad is Highway) then (True)
			: CP Fusion Plausibility Check returns TRUE;
		Else (False)
			: CP Fusion Plausibility Check returns FALSE;
		Endif
		}
		}
		End
		@enduml

  @return          pTrajState->FusionPlaus : Flag to identify if road trajectory can be used for fusion                                  [TRUE,FALSE]

  @param[in]       fFusionSpeedTreshold : Velocity threshold at which road trajectory is used for fusion                                 [0 ... 330.f] m/s 
  @param[in,out]   pTrajState : Pointer to ACC trajectory State
                      FusionHystEgoSpeed : Bit indicating that ego speed fusion criteria is fulfilled                                    [TRUE,FALSE]
                      FusionHystRRoadRangeConf : Bit indicating that features from right side of road estimation fulfill fusion criteria [TRUE,FALSE]
                      FusionHystLRoadRangeConf : Bit indicating that features from left side of road estimation fulfill fusion criteria  [TRUE,FALSE]
                      FusionHystEgoRadius : Bit indicating that ego radius fusion criteria is fulfilled                                  [TRUE,FALSE]
                      FusTraceCrit : Bit set when if CPMOTraceFusionCriterion returns TRUE                                               [TRUE,FALSE]
                      FusionPlaus : Flag to identify if road trajectory can be used for fusion                                           [TRUE,FALSE]
  
  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pf_EgoLongVel : Ego velocity provided by VDY                                  [-330.f ... 330.f] m/s 
                      t_RTE.pf_EgoCurve : Ego curve provided by VDY                                       [-1 ... +1] m-1
                      t_LAInput.pt_ScaleBracketState : state of trace bracket adaption                    [LA_t_ScaleBracketState as defined in la_ext.h]
                      pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft : Confidence of road estimation on left side              [0.f ... 100.f]
                      pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight : Confidence of road estimation on right side            [0.f ... 100.f]
                      pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated : Compensated maximum distance of left road border   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated : Compensated maximum distance of right road border [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_FIPRoadType->t_FIPFusedRoadType.pt_FusedRoadType : Reference to FIP road type                         [Full range of eRoadType_t as in Rte_Type.h]
                      pt_FIPRoad->t_FIPRoadEstimation.fC1 : Clothoid parameter c0 of road trajectry                             [-1 ... +1] m^-2
                      pt_FIPRoad->t_FIPRoadEstimation.fC0 : Clothoid parameter c1 of road trajectory                            [-1 ... +1] m^-1
                      pt_FIPRoad->t_FIPRoadEstimation.fYawAngle : Yaw angle of road trajectory                                  [-100.f .. +100.f] rad/s
  @glob_in         CP_REFusionDistEgoSpeed 
  @glob_out        -

  @c_switch-part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Configuration switch which moves trace brackets in case of ego lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Configuration switch which moves trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch which moves trace brackets w.r.t. BLINKER FEATURE
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   CP_CFG_USE_LOWER_VEL_ROAD_FUSION                                   : Allows fusion of road trajectory at lower ego velocities
  @c_switch_full   FCT_CFG_ROAD_INPUT                                                 : Road estimation input to FCT
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                                          : FCT support for CP sub-component 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability   147:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-147-00061542 \n
                  246:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-246-00061542 \n
                  247:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-247-00061542 \n
                  248:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-248-00061542 \n
                  250:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-250-00061542 \n

  @created         08.02.2016
  @changed         08.02.2016

  @author          Norman Apel | norman.apel@contiautomotive.com | +49 (8382) 9699-365
**************************************************************************** */
static boolean CP_b_FusionRoadSituationVote( float32 fFusionSpeedTreshold, CP_t_TrajectoryState *pTrajState )
{
  FIP_t_FusedRoadType iRoadType;
  /* Definition of local variables for input pointers */
  float32 f_EgoLongVel = *pt_CPInput->t_RTE.pf_EgoLongVel;
  const float32 fEgoCurve = *pt_CPInput->t_RTE.pf_EgoCurve;
  const float32 f_Abs_EgoCurve = fABS( fEgoCurve );

  float32 fMaxRight, fMaxLeft;
  float32 fConfidenceLeft;
  float32 fConfidenceRight;
  float32 fx,fxx,fxxx;
  float32 fYRoadBorderAtFusRange;
  float32 fYEgoCurveAtFusRange;
  boolean bLRangeConfAddCrit,bRRangeConfAddCrit;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  const LA_t_ScaleBracketState LC_State = *(pt_CPInput->t_LAInput.pt_ScaleBracketState);
#endif
#endif
  fConfidenceLeft  = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft;
  fConfidenceRight = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight;

  fMaxRight = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated;
  fMaxLeft = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated;
 
#if (FCT_CFG_INPUT_PREPROCESSSING)
  iRoadType = (pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType);
#else
  iRoadType = FIP_ROAD_TYPE_UNKNOWN;
#endif

  /*speed hysteresis*/
  if(pTrajState->FusionHystEgoSpeed)
  {
    if(f_EgoLongVel < (fFusionSpeedTreshold - CP_FUSIONSPEEDHYSTOFFSET) )
    {
      pTrajState->FusionHystEgoSpeed = FALSE;
    }
  }
  else
  {
    if(f_EgoLongVel > fFusionSpeedTreshold)
    {
      pTrajState->FusionHystEgoSpeed = TRUE;
    }
  }

  /*Left Road Range Conf*/
  if(pTrajState->FusionHystLRoadRangeConf)
  {
    if((fMaxLeft < (dGDBmathLineareFunktion(&CP_REFusionDistEgoSpeed, f_EgoLongVel ) - CP_SAREFUSIONDISTHYST)) ||
      (fConfidenceLeft < CP_MINFUSIONEOROADCONFIDENCE) )
    {
      pTrajState->FusionHystLRoadRangeConf = FALSE;
    }
  }
  else
  {
    if((fMaxLeft > dGDBmathLineareFunktion(&CP_REFusionDistEgoSpeed, f_EgoLongVel )) && 
      (fConfidenceLeft > CP_MAXFUSIONEOROADCONFIDENCE) )
    {
      pTrajState->FusionHystLRoadRangeConf = TRUE;
    }
  }

  /*Right Road Range Conf*/
  if(pTrajState->FusionHystRRoadRangeConf)
  {
    if((fMaxRight < (dGDBmathLineareFunktion(&CP_REFusionDistEgoSpeed, f_EgoLongVel ) - CP_SAREFUSIONDISTHYST)) ||
      (fConfidenceRight < CP_MINFUSIONEOROADCONFIDENCE) )
    {
      pTrajState->FusionHystRRoadRangeConf = FALSE;
    }
  }
  else
  {
    if((fMaxRight > dGDBmathLineareFunktion(&CP_REFusionDistEgoSpeed, f_EgoLongVel )) && 
      (fConfidenceRight > CP_MAXFUSIONEOROADCONFIDENCE) )
    {
      pTrajState->FusionHystRRoadRangeConf = TRUE;
    }
  }

  /*radius hysteresis*/
  if(pTrajState->FusionHystEgoRadius)
  {
    if(f_Abs_EgoCurve > CP_MAXFUSIONCURVE)
    {
      pTrajState->FusionHystEgoRadius = FALSE;
    }
  }
  else
  {
    if(f_Abs_EgoCurve < CP_MINFUSIONCURVE)
    {
      pTrajState->FusionHystEgoRadius = TRUE;
    }
  }

  /*set default neutral values for additional range-conf criterion*/
  bLRangeConfAddCrit = TRUE;
  bRRangeConfAddCrit = TRUE;

  fx   = dGDBmathLineareFunktion(&CP_REFusionDistEgoSpeed, f_EgoLongVel );
  fxx  = fx*fx;
  fxxx = fxx*fx;
  fYRoadBorderAtFusRange = ((pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC1)*fxxx*C_SIXTH) + (0.5f*((pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*fxx) + ((pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle)*fx);
  fYEgoCurveAtFusRange   = fxx * fEgoCurve * (0.5f);  

  /*! Check if road is pulling into curve. 
      Consider this only if the ego vehicle is not performing a lane change. */
  if(  (fYRoadBorderAtFusRange >= CP_CURVEDIRECTIONTHRESH)/*Left Curve estimated by RE*/
     && (fYRoadBorderAtFusRange > fYEgoCurveAtFusRange) /* RE is pulling into Curve*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
     && (LC_State != SLATE_PRE_LANE_CHANGE_RIGHT)
     && (LC_State != SLATE_POST_LANE_CHANGE_RIGHT)
#endif
     )
    { /*
      pulling with curve inner border is suspicious because of exit-situations
      --> BITMASK_FUSION_HYST_RROADRANGECONF must be filfilled to allow fusion
      */
      bLRangeConfAddCrit = FALSE;      
    }
  if(  (fYRoadBorderAtFusRange <= -1.0f*CP_CURVEDIRECTIONTHRESH)/*Right Curve estimated*/
     &&(fYRoadBorderAtFusRange < fYEgoCurveAtFusRange) /* RE is pulling into Curve*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
     && (LC_State != SLATE_PRE_LANE_CHANGE_LEFT)
     && (LC_State != SLATE_POST_LANE_CHANGE_LEFT)
#endif
    )
    { /*
      pulling with curve inner border is suspicious because of exit-situations
      --> BITMASK_FUSION_HYST_RROADRANGECONF must be filfilled to allow fusion
      */
      bRRangeConfAddCrit = FALSE;      
    }

  /*combine all single conditions to one bit*/
#if (CP_CFG_USE_LOWER_VEL_ROAD_FUSION == 0)
  if(  (pTrajState->FusionHystEgoSpeed)
       && ( ((pTrajState->FusionHystLRoadRangeConf) && (bLRangeConfAddCrit)) || 
            ((pTrajState->FusionHystRRoadRangeConf) && (bRRangeConfAddCrit)) )
       && (pTrajState->FusionHystEgoRadius)
#if (CP_CFG_ENABLE_ROAD_TYPE_CHECK_IN_FUSION)
       && (iRoadType == FIP_ROAD_TYPE_HIGHWAY)
#endif /* (CP_CFG_ENABLE_ROAD_TYPE_CHECK_IN_FUSION) */
    )
#else
  if( (  ((pTrajState->FusTraceCrit == TRUE) && ( ((pTrajState->FusionHystLRoadRangeConf) && (bLRangeConfAddCrit)) || ((pTrajState->FusionHystRRoadRangeConf) && (bRRangeConfAddCrit)) ) )
      || ((pTrajState->FusTraceCrit != TRUE) && ( ((pTrajState->FusionHystLRoadRangeConf) && (bLRangeConfAddCrit)) && ((pTrajState->FusionHystRRoadRangeConf) && (bRRangeConfAddCrit)) ) ) )
       && (pTrajState->FusionHystEgoSpeed)
       && (pTrajState->FusionHystEgoRadius)
#if (CP_CFG_ENABLE_ROAD_TYPE_CHECK_IN_FUSION)	   
       && (iRoadType == FIP_ROAD_TYPE_HIGHWAY)
#endif /* (CP_CFG_ENABLE_ROAD_TYPE_CHECK_IN_FUSION) */	    
    )
#endif
  {
    pTrajState->FusionPlaus = TRUE;
  }
  else
  {
    pTrajState->FusionPlaus = FALSE;
  }
  return (boolean)(pTrajState->FusionPlaus);
}
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
/*************************************************************************************************************************
  Functionname:    CP_b_FusionRoadTraceVote                                                                            */ /*!

  @brief           Use the traces of objects to verify the road trajectory

  @description     In case traces are of high quality, the velocity threshold can be reduced for the road trajectory fusion if 
                   a sufficient number of traces are in parallel to the road trajectory. 

		@startuml
		Start
		Partition CP_b_FusionRoadTraceVote {
		Repeat
			: Initialized Trace RE Distribution;
		Repeat While (All CP Trace Bins)
		Partition FCT_CFG_OBJECT_TRACE_PREPROCESSSING {
			Repeat 
				: Set number of trace points in a traces;
				If (if Trace valid bit is valid and (Ego Parallel bit is valid or Road parallel bit is valid)) then (True)
					Repeat
						If (Distance Standard Deviation < CP_PARALLELISM_THRESH)then(True)
							: Increment Trace Vote;
						Else (False)
							: Increment Trace Vote;
						Endif
					Repeat While (All Trace bins)
				Else (False)
					: Do Nothing;
				Endif
			Repeat While (All FIP Static Traces)
		}
		Repeat
			If (Trace RE Distribution > 0) then (True)
				: Update Road Estimation Ok;
			Else (False)
				: Do Nothing;
			Endif
			If (Trace RE Distribution > 1) then (True)
				Note Left: at least 2 traces against RE
				: Don’t Update RE;
			Else (False)
				: Do Nothing;
			Endif
		Repeat While (All CP Trace Number Bins)
		If (Number Trace points < CP_TRACE_FUSION_MIN_TRACEPOINTS) then (True)
			: Set Fusion Speed Threshold as CP_MAXFUSIONSPEED;
		Else (False)
			If (Check if RE is wrong) then (True)
				: Set Fusion Speed Threshold as CP_MAXFUSIONSPEED;
			Else (False)
				If (check if ok distance is at least 40m) then (True)
					Repeat
						If (if there are less or equal traces voting for RE than against) then (True)
							: Set RE Distance Check as TRUE;
						Else (False)
							: Do Nothing;
						Endif
					Repeat While (for at least 40m starting at the maximum distance)
					If (check if RE Distinct is possible) then (True)
						If (RE > CP_MAX_TRACE_INFO_IDX_REOK) then (True)
							: Set Fusion Speed Threshold as CP_MAXFUSIONSPEEDWITHTRACEINFO;
						Else (False)
							: Set Fusion Speed Threshold as CP_MAXFUSIONSPEED;
						Endif
					Else (False)
						: Set Fusion Speed Threshold as CP_MAXFUSIONSPEED;
					Endif
				Else (False)
					: not enough trace information. Threshold stays at maximum speed;
				Endif
			Endif
		Endif
		}
		End
		@enduml

  @return          bResult : Return value indicates whether traces could verify the road trajectory or not                                  [TRUE,FALSE]

  @param[in]       pTrace_QualityValid[i] : Qualifiers for trace of object i                                                                [Full range of data type uint8] 
                                            with i in [0,FIP_STATIC_TRACE_NO_OF_TRACES]
  @param[in]       pTrace_REPara[i] : Point to struct containing the deviation between Road trajectory and trace of object i
                      fDistStdDev : Standard deviation between the road trajectory and the trace  of object i                               [Full range of float32  >= 0.F]
  @param[out]      fFusionSpeedTreshold : Velocity threshold above which the road trajectory is used for the fusion with the ACC trajectory [0.f ... 330.f] m/s 
                        
  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->iNumberOfPoints : Number of trace points for object i                            [0 ... FIP_TRACE_NO_OF_POINTS] 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointX[j] : Longitudinal distance at sample point j of trace object i      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                                                             with j in [0, CP_TRACE_NUM_BINS[ as defined in cp.h                  
                      t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                                                    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                                                with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->uiReferenceToFCTObject : Returns the FCT-id of trace-object i                    [0 ... EM_N_OBJECTS-1] 
                                                                                    with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES]
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ROAD_INPUT                  : Road estimation input to FCT
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability   147:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-147-00061542 \n
                  245:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-245-00061542 \n

  @created         10.02.2016
  @changed         10.02.2016

  @author           Norman Apel | norman.apel@contiautomotive.com | +49 (8382) 9699-365
**************************************************************************** */
static boolean CP_b_FusionRoadTraceVote( const uint8 pTrace_QualityValid[], const CP_t_Trace2CurveParallelism pTrace_REPara[], float32 *fFusionSpeedTreshold )
{
  boolean bResult = FALSE;

  uint8 iTrace;
  uint8 iInit;
  sint8 uNumOfPoints;

  sint8 iTraceREOKDistribution[CP_TRACE_NUM_BINS];
  sint8 iTraceRENOTDistribution[CP_TRACE_NUM_BINS];

  sint32 iREOKIdx;
  sint32 iRENOTIdx;
  sint32 iTraceDistIdx;
  sint32 iNumTracepoints        = 0L;

  /* CPRESTRUCTED: Nice initialization : */
  for(iInit=0u; iInit < CP_TRACE_NUM_BINS; iInit++)
  {
    iTraceREOKDistribution[iInit]  = 0;
    iTraceRENOTDistribution[iInit] = 0;
  }

  /* Plausibilation of RE with traces*/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  for (iTrace=0u;iTrace<FIP_STATIC_TRACE_NO_OF_TRACES;iTrace++)
  {
    uNumOfPoints = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].iNumberOfPoints;
    /* PRQA S 1861 4 */ /* Date:2/25/2020, Reviewer: Gireesh, Reason: :The operands of this relational operator are of different essential type categories; one is 'essentially signed' and the other is 'essentially unsigned'. Both essential types are of lower rank than type int but the comparison will be performed in type int because of integral promotion*/
    /* PRQA S 1863 4 */ /* Date:4/2/2020, Reviewer: Tejaswini M, Reason: type cast required to fix level 4 warning from this,Not safety critical*/
    if(  ((boolean)GET_BIT(pTrace_QualityValid[iTrace],CP_TRACE_QUAL_MASK_TRACE_VALID) == TRUE)
      && (  ((boolean)GET_BIT(pTrace_QualityValid[iTrace],CP_TRACE_QUAL_MASK_EGO_PARALLEL) == TRUE)
          ||((boolean)GET_BIT(pTrace_QualityValid[iTrace],CP_TRACE_QUAL_MASK_ROAD_PARALLEL) == TRUE) 
         )
      )
    {
      const sint8 s_TraceBinLastSample = (sint8) ROUND(pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[uNumOfPoints - 1] * (1.f / CP_SAMPLE_RESOLUTION_X));
      const sint8 s_TraceBinFirstSample = (sint8) ROUND(*pt_CPInput->t_RTE.pf_ObjLongDisp((ObjNumber_t)(pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject)) * (1.f / CP_SAMPLE_RESOLUTION_X));
      iNumTracepoints += uNumOfPoints;
      /*accumulate vote count and parallelism stddev at distbucket*/
      for(iTraceDistIdx = MAX(0,s_TraceBinLastSample); iTraceDistIdx < MIN((sint8)(CP_TRACE_NUM_BINS-1), s_TraceBinFirstSample); iTraceDistIdx++)
      {
        if(pTrace_REPara[iTrace].fDistStdDev < CP_PARALLELISM_THRESH)
        {
          iTraceREOKDistribution[iTraceDistIdx]++;
        }
        else
        {
          iTraceRENOTDistribution[iTraceDistIdx]++;
        }
      }
    }
  }
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
  /*Analyse voting over range*/
  /*look for maximum distance where at least one trace is voting for RE and distance where at least 2 traces vote against RE*/
  iREOKIdx  = -1L;
  iRENOTIdx = -1L;
  for(iTraceDistIdx = 0L; iTraceDistIdx < (sint32)CP_TRACE_NUM_BINS; iTraceDistIdx++)
  {
    if(iTraceREOKDistribution[iTraceDistIdx]>0)
    {
      iREOKIdx = iTraceDistIdx;
    }
    if(iTraceRENOTDistribution[iTraceDistIdx]>1)/*at least 2 traces against RE*/
    {
      iRENOTIdx = iTraceDistIdx;
    }
  }
  if( (iNumTracepoints < CP_TRACE_FUSION_MIN_TRACEPOINTS) )
  { /*not enough trace information. Threshold stays at maximum speed*/ 
    bResult = TRUE;
    *fFusionSpeedTreshold = CP_MAXFUSIONSPEED;
  }
  else
  { /* maybe enough trace information*/
    if(iREOKIdx < iRENOTIdx)
    { /*there is enough info that RE is wrong*/
      bResult = FALSE;
      *fFusionSpeedTreshold = CP_MAXFUSIONSPEED;
    }
    else
    {
      if(iREOKIdx >= CP_MIN_TRACE_INFO_IDX_REOK) 
      { /*check if if okdist is at least 40m*/
        boolean bREDistinctCheck = TRUE;
        for(iTraceDistIdx = iREOKIdx; iTraceDistIdx >= iREOKIdx-3; iTraceDistIdx--)/*check if for at least 40m starting at the maximum okdist */
        {
          if(iTraceREOKDistribution[iTraceDistIdx] <= iTraceRENOTDistribution[iTraceDistIdx])
          {/*if there are less or equal traces voting for RE than against*/
            bREDistinctCheck = FALSE;
          }
        }
        if( bREDistinctCheck )
        {/*Threshold reduction possible*/
          if( iREOKIdx > CP_MAX_TRACE_INFO_IDX_REOK)
          {
            bResult = TRUE;
            *fFusionSpeedTreshold = CP_MAXFUSIONSPEEDWITHTRACEINFO;
          }
          else
          {
            bResult = TRUE;
            *fFusionSpeedTreshold = CP_MAXFUSIONSPEED;
          }
        }
        else
        {
          bResult = TRUE;
          *fFusionSpeedTreshold = CP_MAXFUSIONSPEED;
        }
      }
      else/*(iREOKIdx >= 3)*/
      { /*not enough trace information. Threshold stays at maximum speed*/
        bResult = TRUE;
        *fFusionSpeedTreshold = CP_MAXFUSIONSPEED;
      }
    }
  }

  return bResult;
}
#endif /* END IF #if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT)) */
/** @} end defgroup */
#endif  /* FCT_CFG_ROAD_INPUT */
#endif
