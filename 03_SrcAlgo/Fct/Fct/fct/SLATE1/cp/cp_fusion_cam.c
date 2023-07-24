/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_fusion_cam.c

DESCRIPTION:               Fusion of camera info into ACC trajectory

AUTHOR:                    Matthias Thomi, Gregor Powarzynski

CREATION DATE:             07.05.2012

VERSION:                   $Revision: 1.25 $

LEGACY VERSION:            Revision: 2.0.

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_COURSE_PREDICTION)
#if (CP_CFG_LANE_CHG_CAM_FUSION)
#include "cp_kalman.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_fusion_cam Camera fusion
@ingroup cp_trajectory
@brief         Responsible for computation of camera data based trajectory . \n\n

@description    Checks if camera fusion is useful. If useful, it calculates the lane marker distances.
                Also checke whether the camera information is needed for lane/trajectory fusion. VDY information 
				based checks is also done for camera trajectory.
@{
*/
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/* Internal constant for minimal C0 delta, where second order equation for
lane middle intersection is solved. (Note: has to be non-zero to prevent
division by zero */
#define CP_MIN_C0_DELTA_LANE_MID    1e-8f


#define CP_DRV_INT_CURVE_TIME 30.0f
#if CP_CFG_CAM_LENGTH_FUSION
#define CAM_LANE_FUSION_DIST_FACTOR 1.2f
#define CAM_LANE_FUSION_DIST_FACTOR_HIGH 1.5f
#define CAM_LANE_FUSION_MIN_RATIO 0.6f
#define CAM_LANE_FUSION_VEL_THRES 19.0f         // [m/s]
#endif /* end of CP_CFG_CAM_LENGTH_FUSION */

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

static boolean CP_b_FusionCamSituationVote(void);
static void CP_v_PosSampleLaneMarkers(SLATE_t_PosSamples * pSamples, float32 fXDistFirstSample);
static float32 CP_f_GetCamLaneMarker(const float32 fMinYDist, const float32 fMaxYDist, const float32 fDefaultRetY);
static boolean CP_b_FusionCamCalcCamVDYParallelism(SLATE_t_PosSamples * pCLM_PosSamples);
/* CPRESTRUCTED: Rename: CPTrajCamFusion -> CP_v_FusionCamMain */
/*************************************************************************************************************************
  Functionname:    CP_v_FusionCamMain                                                                                  */ /*!

  @brief           Main function, which decides wheather the camera fusion is required or not.

  @description     Decides whether the situation is useful for camera fusion or not. When situation is useful, the trajectory
                   is calculated and then evaluated. If both the situation check and the evaluation are positive the camera
                   trajectory is later fused.

		@startuml
		Start
		Partition CP_v_FusionCamMain{
		: Initialize Camera Samples;
		if (if fusion camera Situation vote is True) then (True)
		: Generate pos samples from camera input;
			If (check if fusion camera is parallel to VDY) then (True)
				: Set ego course only to off; 
				: Set camera lane fusion to on;
				Partition FCT_SIMU {
					: Set Camera lane trajectory samples;
					: Freeze FCT data from CP Fusion components;
				}
			Else (False)
				: Set Camera Lane fusion to off;
			Endif
		Else (False)
			: Set Camera lane fusion to off;
		Endif
		}
		end
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_CPInput->t_RTE.pf_EgoDrvIntCurve : Curvature of ego vehicle path driving into a curve           [-1 … +1] m^-1
  @glob_in         pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData : CP trajectory data
                      CP_TrajectoryData.fFilteredDIC : Filtered driver intended curvature                             [Full range of float32  >= 0.F]
                      CP_TrajectoryData.fEgo2CamDistX : Ego curve to camera lane blending X distance                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      CP_TrajectoryData.fBaseY : Cam lane fusion Y displacement base                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CP_TrajectoryData.fCamLaneFusionTimer : Down counting camera lane fusion timer                  [Full range of float32  >= 0.F]
  @glob_out        CP_TrajFusionDebugInfo
                      CLM_PosSamples : Camera lane trajectory samples
                      CLM_PosSamples.nb_samples : Number of samples                                                   [0 ... SLATE_MAX_NB_TRAJ_SAMPLES]
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData.fFilteredDIC : Filtered driver intended curvature                             [Full range of float32  >= 0.F]
                      CP_TrajectoryData.State.CamLaneFusion : Bit when camera lane fusion is active                   [TRUE,FALSE]
                      CP_TrajectoryData.State.EgoCourseOnly : Bit indicating that only ego course used for trajectory [TRUE,FALSE]

  @c_switch_part   FCT_SIMU                   : Configuration switch used for simulation
  @c_switch_full   CP_CFG_LANE_CHG_CAM_FUSION : Configuration switch to enable support for camera lane fusion features when changing lanes
  @c_switch_full   FCT_CFG_COURSE_PREDICTION  : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis)

  @traceability    281:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-281-00061542 \n
  
  @created         -
  @changed         3/3/2016

  @todo            Remove this entire line if not needed

  @author          Norman Apel | norman.apel@continental-corporation.com | +49-(8382)-9699-365
*************************************************************************************************************************/
void CP_v_FusionCamMain(SLATE_t_PosSamples * pCLM_PosSamples, float32 fXDistFirstSample)
{
  boolean bFusCAMSituationVote = FALSE;
  boolean bFusCamEval = FALSE;

#ifdef FCT_SIMU
  CP_TrajFusionDebugInfo.CLM_PosSamples.nb_samples = 0;
#endif

  /* Initialize camera samples */
  CP_v_InitPosSamples(pCLM_PosSamples);

  /* Check if situation is useful for camera lane fusion */
  bFusCAMSituationVote = CP_b_FusionCamSituationVote();
  if (bFusCAMSituationVote == TRUE)
  {
    CP_v_PosSampleLaneMarkers(pCLM_PosSamples, fXDistFirstSample);
    /* Evaluate if the calculated trajectory fulfills basic criteria */
    /* At the moment we only check if the camera trajectory is somehow parallel to VDY */
    bFusCamEval = CP_b_FusionCamCalcCamVDYParallelism(pCLM_PosSamples);
    if(bFusCamEval == TRUE)
    {
      /* Update state settings: ego only off/camera fusion on */
      pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion  = TRUE;
      pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly  = FALSE;

#ifdef FCT_SIMU
      CP_TrajFusionDebugInfo.CLM_PosSamples = *pCLM_PosSamples;

      CP_v_CallFCTFreezeforCPFusion(&CP_TrajFusionDebugInfo);
#endif
    }
    else
    {
      pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion  = FALSE;
    }
  }
  else
  {
    /* Not a cam lane fusion situation: set cam lane fusion state to off */
    pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion  = FALSE;
  }
}

/*************************************************************************************************************************
  Functionname:    CP_f_GetCamLaneMarker                                                                               */ /*!

  @brief           Returns lane marker in the given lateral distance.

  @description     Checks the Lane marker distance is within [fMinYDist .. fMaxYDist]. If it is not within the limits, returns the fDefaultRetY.

		@startuml
		Start
		Partition CP_f_GetCamLaneMarker {
		Repeat
			If (check if lane marker state has to be valid) then (True)
				:  Set Current Distance using lane marker’s distance;
				If (check the validity of the lane marker state is within [fMinYDist .. fMaxYDist]) then (True)
					: Set return value to current distance;
				Else(False)
					: Do Nothing;
				Endif
			Else (False)
				: Do Nothing;
			Endif
		Repeat While (For the four lane markers)
		}
		End
		@enduml

  @return          fRet : returns matching lane marker distance or default (float32)                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 

  @param[in]       fMinYDist                                                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
  @param[in]       fMaxYDist                                                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       fDefaultRetY                                                                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pt_CamLaneData->sSigHeader.eSigStatus : Signal header status                                                     [AlgoSignalState_t as in Rte_Type.h]
                      t_RTE.pt_CamLaneData->LaneMarkerInfo[i].u_ExistanceProbability : Probability of existence for camera lane marker i     [0u...100u] 
                                                                                       with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]
                      t_RTE.pt_CamLaneData->LaneMarkerInfo[i].f_MarkerDist : Distance to camera lane marker i                                [Full range of float32  >= 0.F] 
                                                                             with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   CP_CFG_LANE_CHG_CAM_FUSION : Configuration switch to enable support for camera lane fusion features when changing lanes
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis)

  @created         -
  @changed         3/3/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
static float32 CP_f_GetCamLaneMarker(const float32 fMinYDist, const float32 fMaxYDist, const float32 fDefaultRetY)
{
  t_CamLaneMarkerEnum i;
  float32 fRet = fDefaultRetY;
  /* Go through the up to four lane markers and find matching lane markers */
  for (i=FIP_CL_MK_ADJ_LEFT; (i<=FIP_CL_MK_ADJ_RIGHT); i++)
  {
    /* First condition: lane marker state has to be valid */
    if ((pt_CPInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[i].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pt_CPInput->t_RTE.pt_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
    {
      /* Second condition: the marker's distance has to be within [fMinYDist .. fMaxYDist] */
      const float32 fCurDist = pt_CPInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[i].f_MarkerDist;
      if ((fCurDist >= fMinYDist) && (fCurDist <= fMaxYDist))
      {
        /* Set return value to current distance */
        fRet = fCurDist;
      }
    }
  }
  return fRet;
}

/*************************************************************************************************************************
  Functionname:    CP_b_FusionCamSituationVote                                                                         */ /*!

  @brief           Check if fusion of camera lane information is needed

  @description     Returns TRUE if situation allows fusion of camera lane
                   information.

		@startuml
		Start
		Partition CP_b_FusionCamSituationVote {
		If (if FCT_CFG_ACC_LANE_ASSOCIATION is enabled) then (True)
			: Set Minimum Camera Distance to X using Moving object pick up range;
		Else (False)
			: Set Minimum Camera distance to X which is less than or equals to 200; 
		Endif
		: Update Minimum camera Distance to X which is multiplying with CP_PAR_MIN_CAM_LANE_FUS_DIST_RATIO;
		: Set maximum camera lane angle;
		If (if camera lane quality is already high) then (True)
			: Update Min Camera Distance and Max Camera Angle;
		Else (False)
			: Do Nothing;
		Endif
		: Get Absolute Value of Curvature and Heading angle of camera lane;
		If (check if Visibility distance of camera lane is more than minimum camera Distance and Absolute value of Curvature of camera lane is less than max camera curvature and Absolute value of Heading angle of camera lane is less than Max heading angle) then (True)
		Partition #LightBlue “** if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE)) **” {
			: Set camera quality bit as High;
			: set SI lane change probability;
			If (if SI Lane change Probability is more than minimum value and Not Steer Back Lane change) then (True)
				: Get center lane marker;
				: set lane change state;
				If (If SI Lane change state is Left) then (True)
					: Get far left lane marker;
					: Calculate target Y displacement;
					If (if Object is not found) then (True)
						: Set Camera Lane Fusion Timer as CP_PAR_CAM_LANE_CHANGE_ACTIVATION_TIME;
					Else (False)
						: Do Nothing;
					Endif
				Else if (if SI Lane Change state is right) then (True)
					: Get far right lane marker;
					: Calculate target Y displacement;
					If (if Object is not found) then (True)
						: Set Camera Lane Fusion Timer as CP_PAR_CAM_LANE_CHANGE_ACTIVATION_TIME;
					Else (False)
						: Do Nothing;
					Endif
				Else (False)
					: Do nothing;
				Endif
			Else (False)
				: Get far left lane marker;
				: Get far right lane marker;
				If ((far left lane - far right lane) < CP_PAR_NO_LC_MAX_LANEWIDTH) then(True)
					: Calculate Target Y displacement;
				Else (False)
					: Set Target Y displacement as 0;
					: Reset fusion timer of camera lane;
				Endif
			Endif
			: Store the target Y displacement;
			: Camera lane funsion takes place;
		}
		Else (False)
			: Camera lane fusion don’t take place or visibility distance might be too small;
			: Set camera quality bit to false;
		Endif
		If (check if Camera Lane Fusion Timer is greater than 0 or Lane change happens) then (True)
			: Update camera lane fusion timer;
		Else (False)
			: Do Nothing;
		Endif
		Partition SLATE_CFG_CAM_LANE_INTERFACE {
			If (if Camera Lane Fusion is active) then (True)
				:Update Ego velocity upper and lower thresholds;
			Else (False)
				: Do Nothing;
			Endif
			: Get Absolute Ego curve;
			If (Absolute Ego curve < CP_PAR_MAX_CAM_CURVATURE and \n if Ego Longitudinal Velocity is in between Lower Threshold and upper Threshold and \n if camera fusion is active and \n check if road is not city road) then (True)
				: Get the camera lane information (camera curve, camera angle);
				: Calculate Delta Change between camera C0 anf VDY C0;
			Else (False)
				: Set Ego curve to camera lane blending X distance as CP_SAMPLEDIST_MAX;
				: Do Not use Camera Lane;
			Endif
		} 
		}
		End
		@enduml

  @return          bRet : Boolean, TRUE if camera lane fusion shall take place    [TRUE,FALSE]

  @param[in]       -
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pf_EgoLongVel : Longitudinal velocity of ego vehicle                                                           [-330.f ... 330.f] m/s
                      t_RTE.pf_EgoCurve : Curvature of ego vehicle path                                                                    [-1 … +1] m^-1
                      t_LAInput.pt_MovingObjPickUpRange : Pick up range of moving object                                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_FIPCamLane.pf_VisibilityDist : Visibility distance of camera lane                                                  [Full range of float32  >= 0.F]
                      t_FIPCamLane.pf_Curve : Curvature of camera lane                                                                     [Full range of float32  >= 0.F]
                      t_FIPCamLane.pf_HeadingAngle : Heading angle of camera lane                                                          [Full range of float32  >= 0.F]
                      t_SIT.ps_GetLaneChangeProbability : Lane change probability                                                          [-100 ... 100]
                      t_OOI.pt_OOIRelObj->ObjectNr : Obj Number of OOI-0                                                            [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1] 
                   pt_CPOutput->CP_TrajectoryData.State.CamLaneQualityHigh : Bit indicating if camera lane foresight/quality criteria met  [TRUE,FALSE]
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData.State.CamLaneQualityHigh : Bit indicating if camera lane foresight/quality criteria met            [TRUE,FALSE]
                      CP_TrajectoryData.fCamLaneFusionTimer : Down counting camera lane fusion timer                                       [Full range of float32  >= 0.F]    
                      CP_TrajectoryData.fBaseY : Cam lane fusion Y displacement base                                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CP_TrajectoryData.fEgo2CamDistX : Ego curve to camera lane blending X distance                                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m         

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING :  FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component
  @c_switch_full   CP_CFG_LANE_CHG_CAM_FUSION : Configuration switch to enable support for camera lane fusion features when changing lanes.

  @pre             Valid input pointer passed
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis)
  
  @traceability   150:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-150-00061542 \n
                  264:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-264-00061542 \n
                  265:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-265-00061542 \n
                  266:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-266-00061542 \n
                  267:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-267-00061542 \n
                  268:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-268-00061542 \n

  @created         -
  @changed         3/4/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
static boolean CP_b_FusionCamSituationVote(void)
{
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
  float32 f_CamLaneVisibilityDist, f_CamLaneC0, f_CamLaneAngle;
  float32 f_ABS_CamLaneC0, f_ABS_CamLaneAngle;	/* For finding the ABS value */
  /*declaration of lane change prob and state local variables*/
  uint8 SILaneChangeProb;
  SIT_LC_t_LaneChangeState SILaneChangeState;
#endif

  float32 fMinCamDistX;
  float32 fMaxCamAngle;
  boolean bRet = FALSE;
  float32 fTargetYDispl     = 0.f;

  /* Definition of local variables for input pointers */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  float32 f_EgoVelUpperThres = CP_PAR_MAX_CAM_LANE_FUS_SPEED;
  float32 f_EgoVelLowerThres = CP_PAR_MIN_CAM_LANE_FUS_SPEED;
  float32 f_EgoLongVel       = *pt_CPInput->t_RTE.pf_EgoLongVel;
  float32 f_EgoCurve         = *pt_CPInput->t_RTE.pf_EgoCurve;
  float32 f_Abs_EgoCurve;
#endif

  /* Determine minumum necessary camera lane foresight for camera fusion */  
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if (CP_USE_CAM_LANE_FUSION_IN_CITY)
#if (CP_CFG_ADAPT_CAM_FUSION_IN_CITY)
  if(((pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType) == FIP_ROAD_TYPE_CITY) && (f_EgoLongVel <CP_EGO_SPEED_HIGHWAY))
  {
    if(f_EgoLongVel <CP_LOW_EGO_SPEED)
    {
      fMinCamDistX = CP_LOW_EGO_SPEED_VISIBILITY;
    }
    else
    {
      fMinCamDistX = CP_HIGH_EGO_SPEED_VISIBILITY;
    }
  }
  else
#endif /* (CP_CFG_ADAPT_CAM_FUSION_IN_CITY) */
#endif /* (CP_USE_CAM_LANE_FUSION_IN_CITY) */
  {
    fMinCamDistX = *(pt_CPInput->t_LAInput.pt_MovingObjPickUpRange);
    fMinCamDistX *= CP_PAR_MIN_CAM_LANE_FUS_DIST_RATIO;
  }
#else
  fMinCamDistX = MAX_FLOAT(FIP_PICK_UP_RANGE_DEFAULT_MIN, FIP_PICK_UP_RANGE_DEFAULT_TIMEGAP * SLATE_f_GetEgoVelObjSync());
  fMinCamDistX = MIN_FLOAT(fMinCamDistX, RW_FCT_MAX);
  fMinCamDistX *= CP_PAR_MIN_CAM_LANE_FUS_DIST_RATIO;
#endif
  /* Set maximum camera lane angle */
  fMaxCamAngle = CP_PAR_MAX_CAM_LANE_ANGLE;
  /* If camera lane quality already high, then do hysteriesis */
  if (pt_CPOutput->CP_TrajectoryData.State.CamLaneQualityHigh == TRUE)
  {
    fMinCamDistX *= CP_PAR_CAM_LANE_FUSION_HYST;
    fMaxCamAngle *= (1.f/CP_PAR_CAM_LANE_FUSION_HYST);
  }
  fMinCamDistX = MAX_FLOAT(fMinCamDistX, C_F32_DELTA); /*!< To ensure that minimal camera lane distance is above zeros */

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
  /* Verify that camera lane minimal visibility distance
  criteria satisfied and seen camera curvature not too large (in large curvature situations
  the error of the camera seems to increase) and the seen camera lane angle shall not exceed
  a given threshold (when high angles are reported, camera lane seems to be completely bananas) */
  f_CamLaneVisibilityDist = (pt_CPInput->pt_FIPCamLane->f_VisibilityDist);     /*!< Visibility distance of camera lane */
  f_CamLaneC0 = (pt_CPInput->pt_FIPCamLane->f_Curve);                      /*!< Curvature of camera lane */
  f_CamLaneAngle = (pt_CPInput->pt_FIPCamLane->f_HeadingAngle);            /*!< Heading angle of camera lane */
  f_ABS_CamLaneC0 = fABS(f_CamLaneC0);
  f_ABS_CamLaneAngle = fABS(f_CamLaneAngle);
  if ((f_CamLaneVisibilityDist > fMinCamDistX) &&
      ( f_ABS_CamLaneC0 < CP_PAR_MAX_CAM_CURVATURE) &&
      ( f_ABS_CamLaneAngle < fMaxCamAngle))
  {
    /* Set camera quality bit */
    pt_CPOutput->CP_TrajectoryData.State.CamLaneQualityHigh = TRUE;
/*set lane change probability in local function*/
    SILaneChangeProb = pt_CPInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb;

    /* Use camera lane markers in special lane change situations only, avoid doing so during steerback
       Lane change states should only have left and right states after the threshold check as it is not possible to
       lane change 
    */
    if ( (SILaneChangeProb > CP_PAR_DIM_LANE_CHANGE_PROB_MIN)
      && (pt_CPInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase != LC_STEERBACK )
       )
    {
      /* Get center lane marker : it's the one thats [-CP_PAR_LC_MIN_MARKER_DIST .. CP_PAR_LC_MIN_MARKER_DIST] far away */
      const float32 fCenterMarker = CP_f_GetCamLaneMarker(-CP_PAR_LC_MIN_MARKER_DIST, CP_PAR_LC_MIN_MARKER_DIST, 0.f);
	  /*set lane change state to local variable*/
      SILaneChangeState = (pt_CPInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhaseState);
      /* Determine target Y displacement of lane change maneuver */
      if (SILaneChangeState == LC_LEFT)
      {
        /* Lane change to the left, evaluate lane marker(s) to our left */
        /* Get far left lane marker : it's the one thats [CP_PAR_LC_MIN_MARKER_DIST  .. CP_PAR_LC_MAX_MARKER_DIST] far away */
        const float32 fFarLeftMarker = CP_f_GetCamLaneMarker(CP_PAR_LC_MIN_MARKER_DIST, CP_PAR_LC_MAX_MARKER_DIST, (fCenterMarker + (2.f * CP_PAR_DEFAULT_LC_MARKER_OFFSET)));
        /* Create combined target Y displacement */
        fTargetYDispl = 0.5f * (fCenterMarker + fFarLeftMarker);
        /* Second activation criteria: high driver activity on steering wheel (as when high steering wheel
        dynamics are involved, then the current vehicle yaw rate is a bad predictor of the future path) */
        if (pt_CPInput->t_OOI.pt_OOIRelObj->ObjectNr == OBJ_INDEX_NO_OBJECT)
        {
          pt_CPOutput->CP_TrajectoryData.fCamLaneFusionTimer = CP_PAR_CAM_LANE_CHANGE_ACTIVATION_TIME;
        }
      }
      else if (SILaneChangeState == LC_RIGHT)
      {
        /* Lane change to the right, evaluate lane marker(s) to our right */
        /* Get far right lane marker : it's the one thats [-CP_PAR_LC_MAX_MARKER_DIST .. - CP_PAR_LC_MIN_MARKER_DIST] far away */
        const float32 fFarRightMarker = CP_f_GetCamLaneMarker(-CP_PAR_LC_MAX_MARKER_DIST, -CP_PAR_LC_MIN_MARKER_DIST, (fCenterMarker + (-2.f * CP_PAR_DEFAULT_LC_MARKER_OFFSET)));
        /* Create combined target Y displacement */
        fTargetYDispl = 0.5f * (fCenterMarker + fFarRightMarker);
        /* Second activation criteria: high driver activity on steering wheel (as when high steering wheel
        dynamics are involved, then the current vehicle yaw rate is a bad predictor of the future path) */
        if (pt_CPInput->t_OOI.pt_OOIRelObj->ObjectNr == OBJ_INDEX_NO_OBJECT)
        {
          pt_CPOutput->CP_TrajectoryData.fCamLaneFusionTimer = CP_PAR_CAM_LANE_CHANGE_ACTIVATION_TIME;
        }
      }
      else /* (SILaneChangeState == LC_FOLLOW) , for QAC check*/
      {
        /* else condition should not be reachable as no  Lane change should exist while having a follow state */
      }
    }
    else
    {
      /* Get far left lane marker : it's the one thats [CP_PAR_NO_LC_MIN_MARKER_DIST .. CP_PAR_NO_LC_MAX_MARKER_DIST] far away */
      const float32 fFarLeftMarker  = CP_f_GetCamLaneMarker(CP_PAR_NO_LC_MIN_MARKER_DIST, CP_PAR_NO_LC_MAX_MARKER_DIST, (CP_PAR_DEFAULT_LC_MARKER_OFFSET));
      /* Get far right lane marker : it's the one thats [-CP_PAR_NO_LC_MAX_MARKER_DIST .. -CP_PAR_NO_LC_MIN_MARKER_DIST] far away */
      const float32 fFarRightMarker = CP_f_GetCamLaneMarker(-CP_PAR_NO_LC_MAX_MARKER_DIST, -CP_PAR_NO_LC_MIN_MARKER_DIST, (-CP_PAR_DEFAULT_LC_MARKER_OFFSET));
      /* Verify that the thus gotten lane not too wide */
      if ((fFarLeftMarker - fFarRightMarker) < CP_PAR_NO_LC_MAX_LANEWIDTH)
      {
        /* Target Y displacement is middle of the two above */
        fTargetYDispl = 0.5f * (fFarLeftMarker + fFarRightMarker);
      }
      else
      {
        /* Unplausible lane markers for lane change model */
        fTargetYDispl = 0.f;
        /* Reset fusion timer */
        pt_CPOutput->CP_TrajectoryData.fCamLaneFusionTimer = 0.f;
      }
    }
    /* Store the target Y displacement (goal lane middle) */
    pt_CPOutput->CP_TrajectoryData.fBaseY               = fTargetYDispl;
   
    bRet = TRUE;

  }
  else
#endif
  {
    /* Camera lane data not available or visibility distance too small */
    bRet = FALSE;

    /* Clear camera quality bit */
    pt_CPOutput->CP_TrajectoryData.State.CamLaneQualityHigh = FALSE;
  }

  /* Update camera lane fusion timer active */
  if ( (pt_CPOutput->CP_TrajectoryData.fCamLaneFusionTimer > 0.f)
     ||(pt_CPInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase == LC_LANECHANGE )
     )
  {
    pt_CPOutput->CP_TrajectoryData.fCamLaneFusionTimer -= SLATE_f_GetCPCycleTime();
  }

#if (SLATE_CFG_CAM_LANE_INTERFACE)
  /* velocity hysteresis 
     CamLaneFusion State from last cycle, used for hysteresis!*/
  if (pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == TRUE)
  {
    f_EgoVelUpperThres += CP_PAR_CAM_HYST_OFFSET_LANE_FUS_SPEED_MAX;
    f_EgoVelLowerThres -= CP_PAR_CAM_HYST_OFFSET_LANE_FUS_SPEED_MIN;
  }

  /* Assuming the ego course can be approximated as 0.5 * (1/R) * x², then the x coordinate
  where the camera target lane and the ego course Y meet is SQRT(2*fTargetYDispl*R) */
  f_Abs_EgoCurve = fABS(f_EgoCurve);
  if ( (f_Abs_EgoCurve < CP_PAR_MAX_CAM_CURVATURE)
    && (f_EgoLongVel > f_EgoVelLowerThres)
    && (f_EgoLongVel < f_EgoVelUpperThres)
    && (bRet == TRUE)
    && (    ((pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType) != FIP_ROAD_TYPE_CITY)
      #if (CP_USE_CAM_LANE_FUSION_IN_CITY)
         || (   ((pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType) == FIP_ROAD_TYPE_CITY)
#if (CP_CFG_ADAPT_CAM_FUSION_IN_CITY)
#if (FCT_CFG_ACC_SITUATION)
             && (pt_CPInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb < CP_CITY_LC_PROB)
#endif /* (FCT_CFG_ACC_SITUATION) */
#endif /* (CP_CFG_ADAPT_CAM_FUSION_IN_CITY) */
            )
      #endif
       )
     )
  {
    float32 fTmp;
    float32 f_CamCurve, f_CamAngle;
    float32 fEgo2CamX, x_fact, fC0Delta;

    /* Get the camera lane information */
    f_CamCurve = (pt_CPInput->pt_FIPCamLane->f_Curve);
    f_CamAngle = (pt_CPInput->pt_FIPCamLane->f_HeadingAngle);
    x_fact = SIN_(f_CamAngle);
    fC0Delta = (f_CamCurve - f_EgoCurve);

    /* Second order equation: fC0Delta/2 * x² + x_fact * x + y_offs = 0
    Verify that really a second order equation */
    if ((fC0Delta > CP_MIN_C0_DELTA_LANE_MID) || (fC0Delta < (-CP_MIN_C0_DELTA_LANE_MID)))
    {
      /* Based on equation the sub-part (b²-4ac): correct with a tolerance */
      if (fC0Delta > 0.f)
      {
        fTmp = (SQR(x_fact) - (2.0f * fC0Delta * (fTargetYDispl - CP_CAM_LANE_FUSION_EGO_LANE_TOLERANCE)));
      }
      else
      {
        fTmp = (SQR(x_fact) - (2.0f * fC0Delta * (fTargetYDispl + CP_CAM_LANE_FUSION_EGO_LANE_TOLERANCE)));
      }

      if (fTmp >= 0.f)
      {
        float32 fX1, fX2;
        /* Take square root of b²-4ac */
        fTmp = SQRT_(fTmp);
        /* Solution #1 : (-b - sqrt(b²-4ac))/(2a) */
        fX1 = (-x_fact - fTmp)/fC0Delta;
        /* Solution #2 : (-b + sqrt(b²-4ac))/(2a) */
        fX2 = (-x_fact + fTmp)/fC0Delta;
        /* Choose smallest positive solution */
        if (fX1 >= 0.f)
        {
          if (fX2 >= 0.f)
          {
            /* Both positive: take smaller of two */
            fEgo2CamX = MIN(fX1, fX2);
          }
          else
          {
            /* Use X1 as that is positive */
            fEgo2CamX = fX1;
          }
        }
        else
        {
          /* Note: fX2 may be negative as well, but that is caught afterwards */
          fEgo2CamX = fX2;
        }
      }
      else
      {
        /* 2nd degree equation not solveable. This can happen when the yaw rate
        already swings back for stabilization in the target lane. Verify that this
        is the case (i.e.: target Y displacement small), then fuse samples from X=0,
        otherwise having ego samples take over */
        const float32 f_abs_TargetYDispl = fABS(fTargetYDispl);
        if (f_abs_TargetYDispl < CP_PAR_LC_MIN_MARKER_DIST)
        {
          fEgo2CamX = f_EgoLongVel;
        }
        else
        {
          fEgo2CamX = CP_SAMPLEDIST_MAX;
          bRet = FALSE;
        }
      }
    }
    else
    {
      /* First order equation, since fC0Delta is practically zero */
      if ((x_fact > C_F32_DELTA) || (x_fact < (-C_F32_DELTA)))
      {
        fEgo2CamX = (-fTargetYDispl / x_fact);
      }
      else
      {
        fEgo2CamX = CP_SAMPLEDIST_MAX;
        bRet = FALSE;
      }
    }

    /* Verify that positive definite result found */
    if (fEgo2CamX < 0.f)
    {
      /* Bad result: the two parabolas meet in negative X only */
      fEgo2CamX = CP_SAMPLEDIST_MAX;
      bRet = FALSE;
    }

    /* Store ego 2 camera lane blending distance */
    pt_CPOutput->CP_TrajectoryData.fEgo2CamDistX  = fEgo2CamX;
  }
  else
#endif
  {
    /* Curvature too large or ego speed too large : do not use camera lane */
    pt_CPOutput->CP_TrajectoryData.fEgo2CamDistX  = CP_SAMPLEDIST_MAX;
    bRet = FALSE;
  }

  return bRet;
}

/*************************************************************************************************************************
  Functionname:    CP_v_PosSampleLaneMarkers                                                                           */ /*!

  @brief           Generate pos samples from camera lane course information

  @description     Generate pos samples from camera lane course information

		@startuml
		Start
		Partition CP_v_PosSampleLaneMarkers {
		: Set Ego curve;
		: Get the camera lane information;
		Note Left: Camera Lane Info :\nCamera Angle \nCamera Length \nCamera curve \nCamera Curvature Change
		: Set as Y offset the middle of the lane (if available);
		: Get Absolute Ego curve;
		If (if Absolute Ego Curve is less than max Curvature) then (True)
			: Get Distance for first sample in X direction;
			: Use as long as the markers are visible;
			Repeat
				: get trajectory measure of fx;
				If (if Camera Lane Fusion Timer is more than C_F32_DELTA) then (True)
					: Use camera lane using Offset;
				Else (False)
					: Use camera lane;
				Endif
			: Get trajectory mesure of fy;
			Repeat While (For All Trajectory Samples)
			: Set number of samples as SLATE_MAX_NB_TRAJ_SAMPLES;
			If (check if road is not Highway) then (True)
			Partition CP_CFG_CAM_LENGTH_FUSION {
				: Update Camera Fusion Distance thresold;
				If (Camera Length >= Camera Fusion Distance Threshold and Ego Longitudinal speed <= Camera Lane Fusion Velocity Threshold) then (True)
					: Calculate Camera Length using CAM_LANE_FUSION_DIST_FACTOR_HIGH;
				Else (False)
					: Calculate Camera Length using CAM_LANE_FUSION_DIST_FACTOR;
				Endif
				}
			: Limit Samples to a given X Distance;
			Else (False)
				: Do Nothing;
			Endif
		Else (False)
			: Reset Temporary Course Data (curve, curve gradient, curve variance, side slip angle and side slip angle varience);
			: Calculate the (x,y)-Coordinates of the given Course Data ether by circle approximation or polynomial clothoid-approximation;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       fEgo2CamX : the X coordinate up to which ego shall be sampled,
                    for X values larger than this, the camera lane will be sampled           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       fCamBaseY : Cam lane fusion Y displacement base                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       fCamLaneFusionTimer : Down counting camera lane fusion timer              [Full range of float32  >= 0.F]
  @param[in,out]   pSamples : Pointer to structure of type SLATE_t_PosSamples, as defined in cp_ext.h
                      fx[i] : x-position of tarjectory sample                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      fy[i] : y-position of tarjectory sample                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      nb_samples : Number of samples                                         [0u ... SLATE_MAX_NB_TRAJ_SAMPLES]

  @glob_in         pt_CPInput
                      t_RTE.pf_EgoCurve : Curvature of ego vehicle path                      [-1 … +1] m^-1
                      pt_FIPCamLane.f_HeadingAngle : Heading angle of camera lane            [Full range of float32  >= 0.F]
                      pt_FIPCamLane.f_VisibilityDist : Visibility distance of camera lane    [Full range of float32  >= 0.F]
                      pt_FIPCamLane.f_Curve : Curvature of camera lane                       [Full range of float32  >= 0.F] 
                      pt_FIPCamLane.f_CurvatureChange : Curvature change of the camera lane  [Full range of float32  >= 0.F]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   CP_CFG_LANE_CHG_CAM_FUSION : Configuration switch to enable support for camera lane fusion features when changing lanes
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             Valid input & output pointers passed
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis)

  @created         -
  @changed         3/4/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void CP_v_PosSampleLaneMarkers(SLATE_t_PosSamples * pSamples, float32 fXDistFirstSample)
{
  const float32 fCamBaseY = pt_CPOutput->CP_TrajectoryData.fBaseY;
  const float32 fCamLaneFusionTimer = pt_CPOutput->CP_TrajectoryData.fCamLaneFusionTimer;

  uint32 i;
  float32 y_offs;
  float32 f_CamCurve;
  float32 f_CamAngle;
  float32 f_CamLength;
  float32 f_CamCurvatureChange;

  float32 f_x_s;
  float32 f_x_inc;
  float32 f_y_s;
  float32 cam_fus_dist_thresh = 0.f;
  float32 f_AbsEgoCurve;
  
  /* Definition of local variables for input pointers */
  float32 f_EgoCurve = *pt_CPInput->t_RTE.pf_EgoCurve;

  /* Get the camera lane information */
  f_CamAngle = (pt_CPInput->pt_FIPCamLane->f_HeadingAngle);
  f_CamLength = (pt_CPInput->pt_FIPCamLane->f_VisibilityDist);
  f_CamCurve = (pt_CPInput->pt_FIPCamLane->f_Curve);
  f_CamCurvatureChange = (pt_CPInput->pt_FIPCamLane->f_CurvatureChange);

  /* Set as Y offset the middle of the lane (if available) */
  y_offs = fCamBaseY;

  /* Assuming the ego course can be approximated as 0.5 * (1/R) * x², then the x coordinate
  where the camera target lane and the ego course Y meet is SQRT(2*fTargetYDispl*R) */
  f_AbsEgoCurve = fABS(f_EgoCurve);
  if (f_AbsEgoCurve < CP_PAR_MAX_CAM_CURVATURE)
  {
    f_x_s = fXDistFirstSample;

    /* Use as long as the markers are visible */
    f_x_inc = ( CP_SAMPLEDIST_MAX / (float32)SLATE_MAX_NB_TRAJ_SAMPLES );

    for( i = 0u; i < SLATE_MAX_NB_TRAJ_SAMPLES; i++ )
    {
      /*generate SLATE_MAX_NB_TRAJ_SAMPLES for RW_FCT_MAX m along Course*/
      pSamples->fx[i] = f_x_s;
      if(fCamLaneFusionTimer>C_F32_DELTA)
      {
        /* Use camera lane */
        f_y_s = y_offs + (TAN_HD_(f_CamAngle))*f_x_s + (0.5f*f_x_s*f_x_s*f_CamCurve) + (C_SIXTH*f_x_s*f_x_s*f_x_s*f_CamCurvatureChange);
      }
      else
      {
         f_y_s = (TAN_HD_(f_CamAngle))*f_x_s + (0.5f*f_x_s*f_x_s*f_CamCurve) + (C_SIXTH*f_x_s*f_x_s*f_x_s*f_CamCurvatureChange);
      }
      pSamples->fy[i] = f_y_s;
      f_x_s += f_x_inc;
    }
    pSamples->nb_samples = SLATE_MAX_NB_TRAJ_SAMPLES;
    
    if((pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType) != FIP_ROAD_TYPE_HIGHWAY)
    {
#if CP_CFG_CAM_LENGTH_FUSION	
      /* Adapt CamLength to guarantee a certain influence of cam lanes */
      cam_fus_dist_thresh = *(pt_CPInput->t_LAInput.pt_MovingObjPickUpRange);
      cam_fus_dist_thresh *= CAM_LANE_FUSION_MIN_RATIO;

      if ((f_CamLength >= cam_fus_dist_thresh)
          &&
          (EGO_SPEED_X_OBJ_SYNC <= CAM_LANE_FUSION_VEL_THRES)
         )
      {
        f_CamLength*=CAM_LANE_FUSION_DIST_FACTOR_HIGH;
      }
      else
      {
        f_CamLength*=CAM_LANE_FUSION_DIST_FACTOR;
      }
#else /* end of CP_CFG_CAM_LENGTH_FUSION */
  _PARAM_UNUSED(cam_fus_dist_thresh);/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
#endif 

      CP_v_LimitSamplesXDist( f_CamLength, pSamples );
    }
  }
  else
  {
    CP_t_CourseData CourseData_Temp;

    CourseData_Temp.fCurve                = f_EgoCurve;
    CourseData_Temp.fCurveGradient        = 0.f;
    CourseData_Temp.fCurveVar             = 0.f;
    CourseData_Temp.SideSlipAngle         = 0.f;
    CourseData_Temp.SideSlipAngleVariance = 0.f;

    CP_v_SamplePosClothApprox(&CourseData_Temp, CPClothApproxType_CircleOnly, CP_SAMPLEDIST_MAX, pSamples, fXDistFirstSample);
  }
}
/*************************************************************************************************************************
  Functionname:    CP_b_FusionCamCalcCamVDYParallelism                                                               */ /*!

  @brief           Check if Camera Trajectory is parallel to VDY Circle with Radius 1/C0

  @description     Calc distance mean and stdDeviation of distances of trajectory to circle. 
                   For camera trajectory mean and squared score of distances from trajectory to circle is calculated.
                   Big squared score means trajectory is not parallel to vdy and should not be used.

		@startuml
		Start
		Partition CP_b_FusionCamCalcCamVDYParallelism {
		Repeat 
			If (check if sample number is less than Camera Visibility Distance) then (True)
				: increase the last sample inside the visibility Distance;
			Else (False)
				: Do Nothing;
			Endif
		Repeat While (For all samples of CLM_Pos)
		: Update Last sample of visibility distance and inverse the updated value;
		Repeat 
			: Calculates the distance to trajectory for the given fX, fY and fC0;
			: Calculate the mean distance and the stdDeviation;
		Repeat While (For all last camera vision samples)
		: Calculate Mean Distance and variance velocity;
		If (if Variance velocity is more than 0) then (True)
			: Calculate Standard Deviation of Distance using Variance velocity;
		Else (False)
			: Set Standard Deviation of Distance as 0;
		Endif
		If (if Mean Distance is within left and right thresolds and Std_Dev of Distance is less than camera Parallelism Threshold) then (True)
			: Do a camera trajectory fusion;
		Else (False)
			: Don’t do a camera trajectory fusion;
		Endif
		}
		End
		@enduml

  @return          bRet : boolean that indicates if we should do a camera trajectory fusion or not


  @param[in]       pCLM_PosSamples : Pointer that holds the x and y positions of the camera trajectory samples.
  @param[out]      -

  @glob_in         pt_CPOutput->CP_CourseData.fCurve : Curvature (= 1 / Radius)         [-1 … +1] m^-1
  @glob_out        -

  @c_switch_part   FCT_CFG_ROAD_INPUT
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING
  @c_switch_full   CP_CFG_LANE_CHG_CAM_FUSION
  @c_switch_full   FCT_CFG_COURSE_PREDICTION

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis)
  
  @traceability   269:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-269-00061542 \n
                  281:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-281-00061542 \n

  @created         2/16/2018
  @changed         2/16/2018

  @author          Steffen Luis | steffen.luis@continental-corporation.com | 
*************************************************************************************************************************/
static boolean CP_b_FusionCamCalcCamVDYParallelism(SLATE_t_PosSamples * pCLM_PosSamples)
{
  float32 fC0 = pt_CPOutput->CP_CourseData.fCurve;
  float32 f_CamVisDist = (pt_CPInput->pt_FIPCamLane->f_VisibilityDist);
  boolean bRet = FALSE;
  CAL_t_TrajRefPoint TrajRefPoint;
  uint8 iS;
  uint32 uiLastVisCamSample = 0U;
  float32 fDistMean    = 0.0f;
  float32 fDistStdDev  = 0.0f;
  float32 InvNoPts;
  float32 fVarianceVal;
  uint32 u_Round2Uint;

#if (FCT_CFG_ROAD_INPUT)
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const sint8   iNumberOfLeftLanes = FIP_pt_LM_GetLaneMatrixData()->s_NumOfLaneLeft;
  const sint8   iNumberOfRightLanes = FIP_pt_LM_GetLaneMatrixData()->s_NumOfLaneRight;
  const float32 fLeftThreshold = (MAX(0.0f,((float32)iNumberOfLeftLanes))+1.0f) * STRASSENBREITE;
  const float32 fRightThreshold = (MAX(0.0f,((float32)iNumberOfRightLanes))+1.0f) * STRASSENBREITE * -1.0F;
#else
  const float32 fLeftThreshold =  STRASSENBREITE;
  const float32 fRightThreshold = STRASSENBREITE * -1.0F;
#endif
#else
  const float32 fLeftThreshold =  STRASSENBREITE;
  const float32 fRightThreshold = STRASSENBREITE * -1.0F;
#endif
  /* We want to calculate parallelism only to a min threshold or the max visDist of the camera */
  /* First we need to find the last sample inside the visDist */
  for( iS = 0U; iS < pCLM_PosSamples->nb_samples; iS++ )
  {
    if( pCLM_PosSamples->fx[iS] < f_CamVisDist )
    {
      uiLastVisCamSample++;
    }
  }
  /* Second we ensure that at least a minimum distance is considered */
  u_Round2Uint = CML_u_Round2Uint((CP_SAMPLEDIST_MAX/(float32)(SLATE_MAX_NB_TRAJ_SAMPLES)));
#if (CP_USE_CAM_LANE_FUSION_IN_CITY)
#if (CP_CFG_ADAPT_CAM_FUSION_IN_CITY)
  /* As the visibility distance is reduced for City the parallelism check also should be done at less distance because 
  if it is done at 80 meters it might lead to non parallelism as the camera trajectory will be extrapolated to check parallelism */
  if ((pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType) == FIP_ROAD_TYPE_CITY)
  {
    uiLastVisCamSample = MAX(uiLastVisCamSample,(((uint32)CP_LOW_EGO_SPEED_VISIBILITY) / u_Round2Uint));
  }
  else
#endif /* (CP_CFG_ADAPT_CAM_FUSION_IN_CITY) */
#endif /* (CP_USE_CAM_LANE_FUSION_IN_CITY)  */
  {
    uiLastVisCamSample = MAX(uiLastVisCamSample,(CP_PARALLELISM_MIN_LENGTH_CAM / u_Round2Uint));
  }
  
  InvNoPts = (1.f / (float32)uiLastVisCamSample);
  /* Now we can calculate the mean distance and the stdDeviation */
  for (iS = 0U; iS < uiLastVisCamSample; iS ++ )
  {
    float32 fX = pCLM_PosSamples->fx[iS];
    float32 fY = pCLM_PosSamples->fy[iS];
    TrajRefPoint = CAL_t_CalculateDistancePoint2Circle(fX, fY, fC0);
    fDistMean   += TrajRefPoint.fDistToTraj;
    fDistStdDev += SQR(TrajRefPoint.fDistToTraj);
  }
  fDistMean  *= InvNoPts;

  fVarianceVal = (fDistStdDev * InvNoPts) - SQR(fDistMean);
  if( fVarianceVal > 0.f )
  {
    fDistStdDev =  SQRT_(fVarianceVal);
  }
  else
  {
    fDistStdDev = 0.f;
  }
  /* At the end we make the final check.
     The mean distance has to be inside Thresholds, that are calculated based on lane width
     and the standard deviation has to be lower than an empiric found threshold.
  */
  if (   (fDistMean < fLeftThreshold)
    && (fDistMean > fRightThreshold) /*within carriageway */
    && (fDistStdDev < CP_PARALLELISM_THRES_CAM) /*parallelism*/
    )
  {
    bRet = TRUE;
  }
  else
  {
    bRet = FALSE;
  }
  return bRet;
}
/** @} end defgroup */
#endif  /* CP_CFG_LANE_CHG_CAM_FUSION */
#endif  /* FCT_CFG_COURSE_PREDICTION */
