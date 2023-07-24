/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_cam.c

DESCRIPTION:               ACC object corridor brackets adaptation implementation. This 
                           is a main file for this submodule along with la_corridor_cam_adapt.c
                           for all things related to trace brackets using camera lane information

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             28.10.2014

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))


#include "la_corridor_crit.h"
#include "la_corridor_cam.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_corridor_cam LA Corridor Camera
@ingroup la_corridor
@brief          This is a main file for this submodule along with la_corridor_cam_adapt.c
                for things related to trace brackets using camera lane information. \n\n

@{

*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*---------------------------------------------------------------------------
| Constants, Variables: Adaption of trace brackets based on camera information about ego-position in lane |
---------------------------------------------------------------------------*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*! The lane change specific variable: need to be known beyond one cycle */
SET_MEMSEC_VAR(LALaneChangeBracket)
static struct {
  float32             fMarkerDistLeftHistory[LA_LANE_CHANGE_HISTORY_BUFFER];  /*!< Buffer: distance to the lane marker on the left side */
  float32             fMarkerDistRightHistory[LA_LANE_CHANGE_HISTORY_BUFFER]; /*!< Buffer: distance to the lane marker on the right side */
  LA_t_LaneChangeTraceBracketState LaneChgTBState;   /*!< LA_t_LaneChangeTraceBracketState: Info about the last lane change state */
  boolean             bMarkerCrossed;                 /*!< Information if lane marker was crossed */
  boolean             bLaneChangeIsActive;            /*!< Information if a lane change is detected (with hystersis) */
  boolean             bBlinkerFeatureTriggered;       /*!< Information if trace brackets are adapted based on blinker feature */
} LALaneChangeBracket;



#endif  /*!< ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || 
               LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || 
               LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) */

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*! Functions related to trace bracket adaption based on the ego position in lane */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

static void LA_v_ResetAdaptTBForLCBasedOnLCProb(SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo, LA_t_LaneChangeTraceBracketState const LaneChangeTBState);
static void LA_v_FillCamLaneMarkerDistHistoryBuffer(void);

#if (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM)
static void LA_v_AdaptTBForLCBasedOnLCProb(float32 * pf_DistMarkerLeft, float32 * pf_DistMarkerRight,
            LA_t_ScaleBracketState * p_StateScaleBracket, SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo,
            LA_t_LaneChangeTraceBracketState const LaneChangeTBState);
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM */
#if (LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM)
static void LA_v_AdaptTBIfNoLC(float32 * const pf_DistMarkerLeft, float32 * const pf_DistMarkerRight, LA_t_ScaleBracketState * const p_StateScaleBracket, boolean const b_LCProbValid, SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo);
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM */
#if (LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)
static void LA_v_AdaptTBForLCBasedOnBlinkerFeature(float32 * const pf_DistMarkerLeft, float32 * const pf_DistMarkerRight, 
            LA_t_ScaleBracketState * const p_StateScaleBracket, SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo, boolean const b_ValidLCProb);
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */
#if (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)
static void LA_v_FillCamLaneMarkerDistHistoryBuffer(void);
#endif /*! LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */

#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */




#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)

/*************************************************************************************************************************
  Functionname:    LA_v_InitCorridorCamParameter                                                                       */ /*!

  @brief           Initialize global variables of this module

  @description     Initialize/reset global variables of this module
                   Previously called SIInitCorridorNaviParameter()

		@startuml
		Start
		Partition LA_v_InitCorridorCamParameter {
			Repeat
				: Update Maker Distance for left and right history to LA_PAR_INVALIDE_LANE_MARKER_DIST;
			Repeat While (For entire Lane Change History Buffer)
			: Update lane change state for trace bracket adaption;
			: lane marker was not crossed, and lane change is not detected;
			: trace brackets are not adapted based on blinker feature;
		}
		End
		@enduml

  @return          void

  @param[in]       void  

  @glob_in         -
  @glob_out        LALaneChangeBracket.fMarkerDistLeftHistory[   ]  [-100f   100f]
  @glob_out        LALaneChangeBracket.fMarkerDistRightHistory[   ] [-100f   100f]
  @glob_out        LALaneChangeBracket.LaneChgTBState               [LA_t_LaneChangeTraceBracketState as defined in la_cooridor_crit.h]
  @glob_out        LALaneChangeBracket.bMarkerCrossed               [type boolean defined in Platform_Types.h]  [TRUE,FALSE]
  @glob_out        LALaneChangeBracket.bLaneChangeIsActive          [type boolean defined in Platform_Types.h]  [TRUE,FALSE]
  @glob_out        LALaneChangeBracket.bBlinkerFeatureTriggered     [type boolean defined in Platform_Types.h]  [TRUE,FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN 
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adaption of trace brackets  in case of a lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adaption of trace brackets if the lane change probability is low
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/7/2015
   
  @author          Christopher Knievel
*************************************************************************************************************************/
void LA_v_InitCorridorCamParameter(void)
{
  uint8 i;
  for (i = 0u; i < LA_LANE_CHANGE_HISTORY_BUFFER; i++)
  {
    LALaneChangeBracket.fMarkerDistLeftHistory[i]   = LA_PAR_INVALIDE_LANE_MARKER_DIST;
    LALaneChangeBracket.fMarkerDistRightHistory[i]  = LA_PAR_INVALIDE_LANE_MARKER_DIST;
  }
  LALaneChangeBracket.LaneChgTBState                = LA_NO_TB_LANE_CHANGE;
  LALaneChangeBracket.bMarkerCrossed                = FALSE;
  LALaneChangeBracket.bLaneChangeIsActive           = FALSE;
  LALaneChangeBracket.bBlinkerFeatureTriggered      = FALSE;
}


/*************************************************************************************************************************
  Functionname:    LA_v_RelTraInitCriteriaOutputScale                                                                  */ /*!

  @brief           Initialization of one criteria for scaling the trace brackets

  @description     Initialization of one criteria for scaling the trace brackets

		@startuml
		Start
		Partition LA_v_RelTraInitCriteriaOutputScale {
		: Initialize criteria for scaling the trace brackets;
		Note Left: Scale Bracket Left, Scale Bracket Right and State Scale Bracket
		}
		End
		@enduml

  @return          void

  @param[in,out]   pOutput : pointer to the factor for scaling the trace brackets; Pointer to the structure LA_t_ScaleBracketOutput defined in la_corridor_crit.h
                      pOutput->fScaleBracketLeft   [full range float32]
                      pOutput->fScaleBracketRight  [full range float32]
                      pOutput->StateScaleBracket   [LA_t_ScaleBracketState defined in la_corridor_crit.h]


  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adaption of trace brackets  in case of a lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adaption of trace brackets if the lane change probability is low
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/7/2015

 
  @author          Marie-Theres Boll
*************************************************************************************************************************/
void LA_v_RelTraInitCriteriaOutputScale(LA_t_ScaleBracketOutput *const pOutput)
{
  pOutput->fScaleBracketLeft  = INITVALUE_BRACKETPOSITION;
  pOutput->fScaleBracketRight = INITVALUE_BRACKETPOSITION;
  pOutput->StateScaleBracket = SLATE_LANE_CHANGE_UNKNOWN;
}



/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRatioEgoPositionInLaneCam                                                                */ /*!

  @brief           Determining the ratio of the ego position in the ego lane based on camera information

  @description     Determining the ratio of the ego position in the ego lane based on camera information for scaling the trace brackets:
                   The ratio is determined in case of a lane change (and directly afterwards) or if the car is driving in lane (probability of lane change is low)

		@startuml
		Start
		Partition LA_v_RelTraRatioEgoPositionInLaneCam {
		: Initialize distance to camera lane markers;
		: Initialize lane change information;
		Note Left: Lane change Phase, Lane change Phase Probability,\n Lane Change Phase State,Lane Change Confidence, \nLane Change Traffic Orientation
		: Initialize State of trace bracket adaption;
		: Set Visibility distance of camera lane;
		If (check if Visibility distance of camera lane <= 0.0001 \nand Check if lane change state is happened \nfor trace bracket adaption) then (yes) 
			: the trace bracket adaption is reset;
		Endif
		: Fill the history buffer of the ego-distance to the camera lane markers;
		: Set Validity of Lane Change probability as FALSE and Lane change History state;
		If (Camera Lane Visibility Distance > LA_MIN_CAM_COURSE_DIST) then (yes)
			: Update Lane Change Information;
			: Update Validity of Lane Change Probability as True;
			If (If lane change is already active) then (yes)
				If (Check if Lane Change to the left) then (yes)
					: Update Lane Change Probability with LA_LC_PROB_LEVEL_HYSTERESIS;
				Else if (Check if Lane Change to the right) then (yes)
					: Update Lane Change Probability with LA_LC_PROB_LEVEL_HYSTERESIS;
				Else (no)
					: Do Nothing;
				Endif
			Endif
		Endif
		If (Lane Change Probability is valid \nand (Ego Velocity Object Sync <= LA_LEVEL_LOW_SPEED and \nLane Change Probability > LA_LC_PROB_LEVEL_LOW_SPEED) \nor (Ego Velocity Object Sync > LA_LEVEL_LOW_SPEED \nand Lane Change Probability > LA_LC_PROB_LEVEL_HIGH_SPEED)) then (yes)
			If (Check if LC to the left) then (yes)
				: Update Lane Change History State as LA_TB_LANE_CHANGE_LEFT;
				: Update lane change state for trace bracket adaption as LA_TB_LANE_CHANGE_LEFT;
				: Set Lane Change is Active;
			Else if (Check if LC to the right) then (yes)
				: Update Lane Change History State as LA_TB_LANE_CHANGE_RIGHT;
				: Update lane change state for trace bracket adaption as LA_TB_LANE_CHANGE_RIGHT;
				: Set Lane Change is Active;
			Else (no)
				: Update Lane Change History State as LA_NO_TB_LANE_CHANGE;
				: Update lane change state for trace bracket adaption as LA_NO_TB_LANE_CHANGE;
				: Set Lane Change is not Active;
			Endif
		Else (no)
			: Update Lane Change History State as LA_NO_TB_LANE_CHANGE;
			: Set Lane Change is not Active;
		Endif
		: Check reset conditions for history info and if conditions fulfilled, reset history information;
		Partition LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM {
			: Trace bracket adaption during a lane change based on the ego position in lane;
		}
		Partition LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM {
			: Trace bracket adaption if ego vehicle is not performing a lane change (lane change probability is low);
		}
		Partition LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM {
			: Trace bracket adaption based on the blinker feature;
		}
		If (Distance Marker Left < LA_BRACKETPOS_VALID_VAL_COMPARE \nand Distance Marker Right < LA_BRACKETPOS_VALID_VAL_COMPARE \nand Tunnel Probability < Threshold value) then (yes)
			: Update Lane Width Half Camera;
			If (Lane Width Half Camera > 0.0001) then (yes)
				: Update Factor to scale the left trace bracket and right trace bracket;
				If (Ego Velocity Object Sync <= LA_LEVEL_LOW_SPEED) then (yes)
					If (Scale Bracket Left > 1) then (yes)
						: Update Factor to scale the left trace bracket and right trace bracket;
						Note Left: Left trace bracket \nbecomes larger than before
					Else (no)
						: Update Factor to scale the left trace bracket and right trace bracket;
						Note Left: Right trace bracket \nbecomes larger than before
					Endif
				Endif
			Else (no)
				: Set Factor to scale the left trace bracket and right trace bracket as INITVALUE_BRACKETPOSITION;
			Endif
		Else (no)
			: Set Factor to scale the left trace bracket and right trace bracket as INITVALUE_BRACKETPOSITION;
		Endif
		: Set Lane Association State Scale Bracket;
		}
		End
		@enduml

  @return          void

  @param[in,out]   pScaleBracketOut : factor for scaling the trace brackets; pointer to LA_t_ScaleBracketOutput defined in la_corridor_crit.h
                      pScaleBracketOut->fScaleBracketLeft   [full rnage float32]
                      pScaleBracketOut->fScaleBracketRight  [full range float32]
                      pScaleBracketOut->StateScaleBracket   [LA_t_ScaleBracketState defined in la_corridor_crit.h]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync           [-330f   330f]
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability             [0f   1f]
  @glob_out        LALaneChangeBracket.LaneChgTBState      [LA_t_LaneChangeTraceBracketState as defined in la_cooridor_crit.h]
  @glob_out        LALaneChangeBracket.bMarkerCrossed      [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_out        LALaneChangeBracket.bLaneChangeIsActive [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_out        LALaneChangeState                       [LA_t_ScaleBracketState defined in la_corridor_crit.h]

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adaption of trace brackets  in case of a lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adaption of trace brackets if the lane change probability is low
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adaption of trace brackets  in case of a lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adaption of trace brackets if the lane change probability is low
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
void LA_v_RelTraRatioEgoPositionInLaneCam(LA_t_ScaleBracketOutput *const pScaleBracketOut)
{
  /*! Declaration of local variables */
  boolean b_LCProbValid;
  float32 fDistMarkerLeft, fDistMarkerRight, fLaneWidthHalfCam;
  float32 f_CamLaneVisibilityDist;
  LA_t_LaneChangeTraceBracketState t_LaneChangeHistState;
  SIT_LC_t_LaneChangePhaseInfo t_LaneChangeInfo;
  /*! Initialize distance to camera lane markers */
  fDistMarkerLeft = INITVALUE_BRACKETPOSITION; 
  fDistMarkerRight = INITVALUE_BRACKETPOSITION;
  /*Initialize lane change information*/
  t_LaneChangeInfo.t_LCPhase = LC_NO_LANECHANGE;
  t_LaneChangeInfo.u_LCPhaseProb = 0u;
  t_LaneChangeInfo.t_LCPhaseState = LC_FOLLOW;
  t_LaneChangeInfo.u_LCConfidence = 0u;
  t_LaneChangeInfo.t_LCTrafficOrientation = LC_TRAFFIC_ORIENT_UNKNOWN;
   /*! Initialize of reason for trace bracket adaption */
  pScaleBracketOut->StateScaleBracket = SLATE_LANE_CHANGE_UNKNOWN;

  /*! If no camera lane information available during the course of maneuver, the trace bracket adaption is reset (former information might have been wrong) */
  f_CamLaneVisibilityDist = (pt_LAInput->pt_FIPCamLane->f_VisibilityDist); /*!< Visibility distance of camera lane */
  if ((f_CamLaneVisibilityDist <= C_F32_DELTA) && (LALaneChangeBracket.LaneChgTBState != LA_NO_TB_LANE_CHANGE))
  {
    LALaneChangeBracket.LaneChgTBState = LA_NO_TB_LANE_CHANGE;
    LALaneChangeBracket.bMarkerCrossed = FALSE;
    LALaneChangeBracket.bLaneChangeIsActive = FALSE;
  }

  /*! Switch: if the trace brackets should be adapted in case of a lane change, the history of the distance to the camera lane markers is evaluated
              (StateScaleBracket = POST_LANE_CHANGE / PRE_LANE_CHANGE ) */
  /*! Fill the history buffer of the ego-distance to the camera lane markers */
  LA_v_FillCamLaneMarkerDistHistoryBuffer();

  /*! Set lane change probability and validity flag of lane change probability */

  /*! Default values */
  b_LCProbValid = FALSE;
  t_LaneChangeHistState = LA_NO_TB_LANE_CHANGE;
  /*! Information about lane change probability */
  if (f_CamLaneVisibilityDist > LA_MIN_CAM_COURSE_DIST)
  {
    t_LaneChangeInfo = *(pt_LAInput->t_SIT.pt_GetLaneChangeInfo);
    b_LCProbValid = TRUE;
    /*! If lane change is already active, consider hysteresis */
    if (LALaneChangeBracket.bLaneChangeIsActive == TRUE )
    {
      /*! LC to the left */
      if (t_LaneChangeInfo.t_LCPhaseState == LC_LEFT)
      {
        t_LaneChangeInfo.u_LCPhaseProb += LA_LC_PROB_LEVEL_HYSTERESIS;
      }
      else if (t_LaneChangeInfo.t_LCPhaseState == LC_RIGHT) /*! LC to the right */
      {
        t_LaneChangeInfo.u_LCPhaseProb += LA_LC_PROB_LEVEL_HYSTERESIS;
      }
      else /*no hysteresis to be added in the a Follow state */
      {
        /*Do nothing, for QAC*/
      }
      
    }
  }

  /*! Evaluation of LC-probability: determine if lane change is detected (hysteresis) */
  if ( (b_LCProbValid == TRUE) 
    && ( ( (*pt_LAInput->t_RTE.pf_EgoVelObjSync <= LA_LEVEL_LOW_SPEED)
        && (t_LaneChangeInfo.u_LCPhaseProb > LA_LC_PROB_LEVEL_LOW_SPEED)
         )
      ||
         ( (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_LEVEL_LOW_SPEED)
        && (t_LaneChangeInfo.u_LCPhaseProb > LA_LC_PROB_LEVEL_HIGH_SPEED)
         )
       )
     )
  {
    /*! LC to the left */
    if (t_LaneChangeInfo.t_LCPhaseState == LC_LEFT)
    {
      t_LaneChangeHistState = LA_TB_LANE_CHANGE_LEFT;
      LALaneChangeBracket.LaneChgTBState = LA_TB_LANE_CHANGE_LEFT;
      LALaneChangeBracket.bLaneChangeIsActive = TRUE;
    }
    else if (t_LaneChangeInfo.t_LCPhaseState == LC_RIGHT)  /*! LC to the right */
    {
      t_LaneChangeHistState = LA_TB_LANE_CHANGE_RIGHT;
      LALaneChangeBracket.LaneChgTBState = LA_TB_LANE_CHANGE_RIGHT;
      LALaneChangeBracket.bLaneChangeIsActive = TRUE;
    }
    else
    {
     t_LaneChangeHistState = LA_NO_TB_LANE_CHANGE;
     LALaneChangeBracket.LaneChgTBState = LA_NO_TB_LANE_CHANGE;
     LALaneChangeBracket.bLaneChangeIsActive = FALSE;
    }
  }
  else /*! No LC in this cycle */
  {
    t_LaneChangeHistState = LA_NO_TB_LANE_CHANGE;
    LALaneChangeBracket.bLaneChangeIsActive = FALSE;
  }

  /*! Check reset conditions for history info and if conditions fulfilled, reset history info */
  LA_v_ResetAdaptTBForLCBasedOnLCProb(t_LaneChangeInfo, t_LaneChangeHistState);

  /*! Switch: if the trace brackets should be adapted in case of a lane change (StateScaleBracket = SLATE_POST_LANE_CHANGE_LEFT / SLATE_POST_LANE_CHANGE_RIGHT ) */
#if (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM)
  LA_v_AdaptTBForLCBasedOnLCProb(&fDistMarkerLeft, &fDistMarkerRight, &(pScaleBracketOut->StateScaleBracket), t_LaneChangeInfo, t_LaneChangeHistState);
#endif /*< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM */

#if (LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM)
  /*! Adaption of trace brackets if the lane change probability is low, i.e. driving "inlane" (StateScaleBracket = SLATE_NO_LANE_CHANGE), 
      only for high speed (lane markers in cities are often bad or there are no lane markers between two lanes),
      only if the distance to the lane markers is not too high (i.e. lane change might occur even though the probability is not high) */
  LA_v_AdaptTBIfNoLC(&fDistMarkerLeft, &fDistMarkerRight, &(pScaleBracketOut->StateScaleBracket), b_LCProbValid, t_LaneChangeInfo);
#endif /*< LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM */


#if (LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)
  /*! Adaption of trace brackets if the blinker feature is active (StateScaleBracket is SLATE_PRE_LANE_CHANGE_LEFT or SLATE_PRE_LANE_CHANGE_RIGHT);
      only for high speed (lane markers in cities are often bad or there are no lane markers between two lanes) */
  LA_v_AdaptTBForLCBasedOnBlinkerFeature(&fDistMarkerLeft, &fDistMarkerRight, &(pScaleBracketOut->StateScaleBracket), t_LaneChangeInfo, b_LCProbValid);
#endif /*< LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */

  /*! Determine the ratio (relative to middle position) of the ego-position in the lane for altering the trace brackets.
      In case of a tunnel, the distance to the camera lane cannot be trusted, hence, ignore the trace bracket adaption */
  if( (fDistMarkerLeft < LA_BRACKETPOS_VALID_VAL_COMPARE) 
      && (fDistMarkerRight < LA_BRACKETPOS_VALID_VAL_COMPARE) 
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
      && (*pt_LAInput->t_RTE.pf_TunnelProbability < LA_TUNNEL_PROB_THRES)
#endif
    )
  {
    fLaneWidthHalfCam = (fDistMarkerLeft + fDistMarkerRight) * 0.5f;

    if(fLaneWidthHalfCam > C_F32_DELTA)
    {
      pScaleBracketOut->fScaleBracketLeft = fDistMarkerLeft / fLaneWidthHalfCam;
      pScaleBracketOut->fScaleBracketRight = fDistMarkerRight / fLaneWidthHalfCam;

      /*! In case of a low speed scenario (city-traffic), the lane brackets are altered less 
        (cars in other lanes are closer to the ego-lane, lane association difficult) */
      if (*pt_LAInput->t_RTE.pf_EgoVelObjSync <= LA_LEVEL_LOW_SPEED)
      {
        /*! Left trace bracket becomes larger than before */
        if (pScaleBracketOut->fScaleBracketLeft > 1.f)
        {
          pScaleBracketOut->fScaleBracketLeft = 1.f + ((pScaleBracketOut->fScaleBracketLeft - 1.f)* 0.5f);
          pScaleBracketOut->fScaleBracketRight = 2.f - pScaleBracketOut->fScaleBracketLeft;
        }
        else /*! Right trace bracket becomes larger than before */
        {
          pScaleBracketOut->fScaleBracketRight = 1.f + ((pScaleBracketOut->fScaleBracketRight - 1.f)* 0.5f);
          pScaleBracketOut->fScaleBracketLeft = 2.f - pScaleBracketOut->fScaleBracketRight;
        }
      }
    }
    else /*! No adaption of trace brackets */
    {
      pScaleBracketOut->fScaleBracketLeft = INITVALUE_BRACKETPOSITION;
      pScaleBracketOut->fScaleBracketRight = INITVALUE_BRACKETPOSITION;
    }
  }
  else /*! No adaption of trace brackets */
  {
    pScaleBracketOut->fScaleBracketLeft = INITVALUE_BRACKETPOSITION;
    pScaleBracketOut->fScaleBracketRight = INITVALUE_BRACKETPOSITION;
  }

  /*! Set the global variable f_LA_StateScaleBracket to exchange it with other modules */
  pt_LAOutput->f_LA_StateScaleBracket = pScaleBracketOut->StateScaleBracket;
}
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */


#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*************************************************************************************************************************
  Functionname:    LA_v_FillCamLaneMarkerDistHistoryBuffer                                                          */ /*!

  @brief           Fill the history buffer of the ego-distance to the camera lane markers

  @description     Fill the history buffer (fMarkerDistLeftHistory) of the ego-distance to the camera lane markers

		@startuml
		Start
		Partition LA_v_FillCamLaneMarkerDistHistoryBuffer {
		If (If Existence Probability of left camera lane marker >= FIP_CAM_LANE_POE_LEVEL and Camera Lane Signal Status is ok) then (yes)
			: Calculate Delta Distance of left camera lane marker;
			If (if Absolute Delta Distance > 0.0001) then (yes)
				Repeat 
					: Move Marker Distance Left History in array;
				Repeat While (For LC History Buffer)
				: Set new value of Marker Distance Left History;
			Endif 
		Else (no)
			Repeat 
				: Move Marker Distance Left History in array;
			Repeat While (For LC History Buffer)
			: Set Marker Distance Left History as LA_PAR_INVALIDE_LANE_MARKER_DIST;
		Endif
		If (If Existence Probability of right camera lane marker>= FIP_CAM_LANE_POE_LEVEL and Camera Lane Signal Status is ok) then (yes)
			: Calculate Delta Distance of right camera lane marker;
			If (if Absolute Delta Distance > 0.0001) then (yes)
				Repeat 
					: Move Marker Distance Right History in array;
				Repeat While (For LC History Buffer)
				: Set new value of Marker Distance Right History;
			Endif 
		Else (no)
			Repeat 
				: Move Marker Distance Right History in array;
			Repeat While (For LC History Buffer)
			: Set Marker Distance Right History as LA_PAR_INVALIDE_LANE_MARKER_DIST;
		Endif
		}
		End
		@enduml

  @return          static void

  @param[in]       void

  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[   ].u_ExistanceProbability                  [0u ...100u]
  @glob_in         pSLATE_CamLaneData->sSigHeader.eSigStatus                                       [type AlgoSignalState_t defined in interfaceobjectlist.h]
  @glob_in         LALaneChangeBracket.fMarkerDistLeftHistory[   ]                                  [-100f   100f]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist                            [-100f   100f]
  @glob_in         LALaneChangeBracket.fMarkerDistRightHistory                                      [-100f   100f]

  @glob_out        LALaneChangeBracket.fMarkerDistLeftHistory[   ]                                  [-100f   100f]
  @glob_out        LALaneChangeBracket.fMarkerDistRightHistory[   ]                                 [-100f   100f]

  @c_switch_part   -

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adaption of trace brackets  in case of a lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adaption of trace brackets if the lane change probability is low
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_FillCamLaneMarkerDistHistoryBuffer(void)
{
  uint8 i;
  /*! Fill the history buffer of the ego-distance to the camera lane markers only if the distance changed (different cycle times); order: latest value first */
  /*! Left camera lane marker */
  /*! If the camera lane marker is valid */
  if ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    const float32 fDeltaDist = (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist - LALaneChangeBracket.fMarkerDistLeftHistory[0u]);
    const float32 f_ABS_DeltaDist = fABS(fDeltaDist);
    /*! Only if the distance changed */
    if (f_ABS_DeltaDist > C_F32_DELTA)
    {
      /*! Move entries in array */
      for( i = LA_LANE_CHANGE_HISTORY_BUFFER - 1u; i >= 1u ; i--)
      {
        LALaneChangeBracket.fMarkerDistLeftHistory[i] = LALaneChangeBracket.fMarkerDistLeftHistory[i - 1u];
      }
      /*! Set new value */
      LALaneChangeBracket.fMarkerDistLeftHistory[0u] = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist;
    }
  }
  else
  {
    /*! If the camera lane marker is not valid, set default invalid value */
    /*! Move entries in array */
    for( i = LA_LANE_CHANGE_HISTORY_BUFFER - 1u; i >= 1u ; i--)
    {
      LALaneChangeBracket.fMarkerDistLeftHistory[i] = LALaneChangeBracket.fMarkerDistLeftHistory[i - 1u];
    }
    /*! Set default invalid value */
    LALaneChangeBracket.fMarkerDistLeftHistory[0u] = LA_PAR_INVALIDE_LANE_MARKER_DIST;
  }

  /*! Right camera lane marker */
  /*! If the camera lane marker is valid */
  if ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    const float32 fDeltaDist = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - LALaneChangeBracket.fMarkerDistRightHistory[0u];
    const float32 f_absDeltaDist = fABS(fDeltaDist);
    /*! Only if the distance changed */
    if (f_absDeltaDist > C_F32_DELTA)
    {
      /*! Move entries in array */
      for( i = LA_LANE_CHANGE_HISTORY_BUFFER - 1u; i >= 1u ; i--)
      {
        LALaneChangeBracket.fMarkerDistRightHistory[i] = LALaneChangeBracket.fMarkerDistRightHistory[i - 1u];
      }
      /*! Set new value */
      LALaneChangeBracket.fMarkerDistRightHistory[0u] = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;
    }
  }
  else
  {
    /*! If the camera lane marker is not valid, set default invalid value */
    /*! Move entries in array */
    for( i = LA_LANE_CHANGE_HISTORY_BUFFER - 1u; i >= 1u ; i--)
    {
      LALaneChangeBracket.fMarkerDistRightHistory[i] = LALaneChangeBracket.fMarkerDistRightHistory[i - 1u];
    }
    /*! Set default invalid value */
    LALaneChangeBracket.fMarkerDistRightHistory[0u] = LA_PAR_INVALIDE_LANE_MARKER_DIST;
  }

}
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */


#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*************************************************************************************************************************
  Functionname:    LA_v_ResetAdaptTBForLCBasedOnLCProb                                                              */ /*!

  @brief           Check reset conditions for history info and if conditions fulfilled, reset history info

  @description     Check reset conditions for history info and if conditions fulfilled, reset history info

		@startuml
		Start
		Partition LA_v_ResetAdaptTBForLCBasedOnLCProb {
		: no reset of history information;
		If (Check if (lane change right for trace bracket adaption and Lane change probability > LA_TB_RIGHT_LC_PROB_LEVEL_RESET_HIST and Lane change state is Left LC) or (lane change left for trace bracket adaption and Lane change probability > LA_TB_LEFT_LC_PROB_LEVEL_RESET_HIST and Lane change state is Right LC)) then (yes)
			: Set Reset History Info as True;
		Else if (If No lane change and No lane change state for trace bracket adaption) then (yes)
			: Set Reset Different Marker LC Left and LC Right as False;
			Repeat
				: Determine the difference in the distance to the lane markers within the history buffer for both sides;
				If (If the lane change was to the left) then (yes)
					If (if Distance Marker Difference Left History > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL and Distance Marker Difference Left History < LA Seek Lane Width * 0.5) then (yes)
						: Set Reset Difference Marker LC Left as True;
					Endif
					If (if Distance Marker Difference Right History > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL and Distance Marker Difference Right History < LA Seek Lane Width * 0.5) then (yes)
						: Set Reset Difference Marker LC Right as True;
					Endif
				Endif
				If (If the lane change was to the right) then (yes)
					If (if Distance Marker Difference Left History > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL and Distance Marker Difference Left History < -LA Seek Lane Width * 0.5) then (yes)
						: Set Reset Difference Marker LC Left as True;
					Endif
					If (if Distance Marker Difference Right History > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL and Distance Marker Difference Right History < -LA Seek Lane Width * 0.5) then (yes)
						: Set Reset Difference Marker LC Right as True;
					Endif
				Endif
			Repeat While (Upto LA_LANE_CHANGE_HISTORY_BUFFER - 1)
			: Calculate Absolute Marker Distance Left and Absolute Marker Distance Right;
			If (if Reset Difference Marker LC Left is true and Reset Difference Marker LC Right is true) then (yes)
				: Set Reset History Info as True;
			Else if (if lane marker was crossed and (lane change state is left for trace bracket adaption and Absolute Marker Distance Left < Absolute Marker Distance Right) or (lane change state is right for trace bracket adaption and Absolute Marker Distance Right < Absolute Marker Distance Left)) then (yes)
				: Set Reset History Info as True;
			Else (no)
				: No reset;
			Endif
		Else (no)
			: No Reset;
		Endif
		If (Check if Reset History Info = True)
			: Set No lane change state for trace bracket adaption;
			: Set lane marker was not crossed;
		Endif
		}
		End
		@enduml

  @return          static void

  @param[in]       i_LALaneChangeProb : lane change (LC) probability   [-100s    100s]
  @param[in]       LaneChangeTBState : State of lane change for trace bracket adaption based on ego position in lane  [LA_t_LaneChangeTraceBracketState defined in la_corridor_crit.h]


  @glob_in         LALaneChangeBracket.fMarkerDistLeftHistory[   ]                                  [-100f   100f]
  @glob_in         LALaneChangeBracket.fMarkerDistRightHistory[   ]                                 [-100f   100f]
  @glob_in         LALaneChangeBracket.bMarkerCrossed                                               [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_in         LALaneChangeBracket.LaneChgTBState                                               [LA_t_LaneChangeTraceBracketState defined in la_corridor_crit.h]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist                            [-100f   100f]

  @glob_out        LALaneChangeBracket.bMarkerCrossed                                               [type boolean defined in Platform_Types.h] [TRUE,FALSE]
  @glob_out        LALaneChangeBracket.LaneChgTBState                                               [LA_t_LaneChangeTraceBracketState defined in la_corridor_crit.h]

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adaption of trace brackets  in case of a lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adaption of trace brackets if the lane change probability is low
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_ResetAdaptTBForLCBasedOnLCProb(SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo, LA_t_LaneChangeTraceBracketState const LaneChangeTBState)
{
  /*! Check reset conditions for history info and if conditions fulfilled, reset history info */
  /*! Local variables */
  uint8 i;
  boolean b_ResetDiffMarkerLCLeft, b_ResetDiffMarkerLCRight, b_RestHistoryInfo;
  float32 f_DistMarkerDiffLeftHistory, f_DistMarkerDiffRightHistory;
  float32 fLASeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;
  float32 f_ABS_MarkerDist_Left, f_ABS_MarkerDist_Right; /* For the calculation of ABS value */ 

  /*! Set default: no reset of history info */
  b_RestHistoryInfo = FALSE;

  /*! Reset history info if lance change probability rises in the opposite direction to the lane change history */
  if( ( (LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_RIGHT) 
        && (i_LALaneChangeInfo.u_LCPhaseProb > LA_TB_RIGHT_LC_PROB_LEVEL_RESET_HIST) 
    && (i_LALaneChangeInfo.t_LCPhaseState == LC_LEFT)
    ) 
      || 
      ( (LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_LEFT) 
        && ( (i_LALaneChangeInfo.u_LCPhaseProb > LA_TB_LEFT_LC_PROB_LEVEL_RESET_HIST) 
      && (i_LALaneChangeInfo.t_LCPhaseState == LC_RIGHT) ) 
    )
    )
  {
    b_RestHistoryInfo = TRUE;
  }
  /*! The trace brackets are adapted if the lane change probability is high. i.e. the object is driving towards the 
      new lane (LaneChangeTBState != LA_NO_TB_LANE_CHANGE) or directly after the lane change probility was high 
      (after crossing the lane markers the LC prob. usually drops but the LC is not finished yet 
      ((LaneChangeTBState == LA_NO_TB_LANE_CHANGE) && (LALaneChangeBracket.LaneChgTBState != LA_NO_TB_LANE_CHANGE))) */
  /*! Evaluate the distance to the lane markers directly after the LC probability was high (lane markers just crossed) 
      for resetting the adaption of trace brackets 
      -> if the vehicle starts moving to the opposite direction compared to the lane change, the adaption of the 
         trace brackets stops (LALaneChangeBracket.fMarkerDistLeft/RightHistory is reset)
      -> if the position in the middle of the lane is reached after a lane change, the adaption of the trace brackets
         is stopped (LALaneChangeBracket.fMarkerDistLeft/RightHistory is reset) */
  else if ( (LaneChangeTBState == LA_NO_TB_LANE_CHANGE) && (LALaneChangeBracket.LaneChgTBState != LA_NO_TB_LANE_CHANGE) )
  {
    /*! Determine if vehicle starts moving to the opposite direction compared to the lane change: Evaluate the difference in the distance to the lane markers within the history buffer */
    /*! Initialize decision according to difference in distance to lane markers */
    b_ResetDiffMarkerLCLeft = FALSE;
    b_ResetDiffMarkerLCRight = FALSE;
    for ( i = 0u ; i < (LA_LANE_CHANGE_HISTORY_BUFFER - 1u); i++)
    {
      /*! Determine the difference in the distance to the lane markers within the history buffer for both sides */
      f_DistMarkerDiffLeftHistory = LALaneChangeBracket.fMarkerDistLeftHistory[i] - LALaneChangeBracket.fMarkerDistLeftHistory[i + 1u];
      f_DistMarkerDiffRightHistory = LALaneChangeBracket.fMarkerDistRightHistory[i] - LALaneChangeBracket.fMarkerDistRightHistory[i + 1u];
      /*! If the lane change was to the left: the distance to the lane markers decreases when driving to the left (when the marker is crossed, the distance "jumps" to a higher value) */
      if ( LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_LEFT )
      {
        if ( (f_DistMarkerDiffLeftHistory > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL) && (f_DistMarkerDiffLeftHistory < (fLASeekLaneWidth * 0.5f)) )
        {
          b_ResetDiffMarkerLCLeft = TRUE;
        }
        if ( (f_DistMarkerDiffRightHistory > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL) && (f_DistMarkerDiffRightHistory < (fLASeekLaneWidth * 0.5f)) )
        {
          b_ResetDiffMarkerLCRight = TRUE;
        }
      }
      /*! If the lane change was to the right: the distance to the lane markers increases when driving to the right (when the marker is crossed, the distance "jumps" to a lower value) */
      if( LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_RIGHT )
      {
        if( (f_DistMarkerDiffLeftHistory < LA_LC_RIGHT_DIFF_DIST_MARKER_HIST_LEVEL) && (f_DistMarkerDiffLeftHistory > (- fLASeekLaneWidth * 0.5f)) )
        {
          b_ResetDiffMarkerLCLeft = TRUE;
        }
        if( (f_DistMarkerDiffRightHistory < LA_LC_RIGHT_DIFF_DIST_MARKER_HIST_LEVEL) && (f_DistMarkerDiffRightHistory > (- fLASeekLaneWidth * 0.5f)) )
        {
          b_ResetDiffMarkerLCRight = TRUE;
        }
      }
    }

    /*! Set reset condition:
      -> if the vehicle starts moving to the opposite direction compared to the lane change (indicated by distance to both lane markers)
      -> if the position in the middle of the lane is reached after a lane change */
	f_ABS_MarkerDist_Left  = fABS(pSLATE_CamLaneData->LaneMarkerInfo[CL_CAM_LANE_MK_LEFT].f_MarkerDist);
	f_ABS_MarkerDist_Right = fABS(pSLATE_CamLaneData->LaneMarkerInfo[CL_CAM_LANE_MK_RIGHT].f_MarkerDist);
    if( (b_ResetDiffMarkerLCLeft == TRUE) && (b_ResetDiffMarkerLCRight == TRUE) )
    {
      b_RestHistoryInfo = TRUE;
    }
    /*! If the position in the middle of the lane is reached after a lane change, the adaption of the trace brackets is stopped */
    else if ( (LALaneChangeBracket.bMarkerCrossed == TRUE) &&
              ( ( (LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_LEFT) && 
                  (f_ABS_MarkerDist_Left <  f_ABS_MarkerDist_Right)
                ) ||
                ( (LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_RIGHT) && 
                  (f_ABS_MarkerDist_Right < f_ABS_MarkerDist_Left)
                )
              ) 
            )
    {
      b_RestHistoryInfo = TRUE;
    }
    else
    {
      /*! No reset */
    }
  }
  else
  {
    /*! No reset */
  }

  /*! Reset history info */
  if( b_RestHistoryInfo == TRUE )
  {
    LALaneChangeBracket.LaneChgTBState = LA_NO_TB_LANE_CHANGE;
    LALaneChangeBracket.bMarkerCrossed = FALSE;
  }
}
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */


#if (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM)
/*************************************************************************************************************************
  Functionname:    LA_v_AdaptTBForLCBasedOnLCProb                                                                   */ /*!

  @brief           Trace bracket adaption during a lane change based on the ego position in lane

  @description     Trace bracket adaption during a lane change based on the ego position in lane: 
                   if situation fulfilled, set distance to lane markers (pf_DistMarkerLeft/pf_DistMarkerRight) and 
                   LaneChangeTBState = SLATE_POST_LANE_CHANGE_LEFT/SLATE_POST_LANE_CHANGE_RIGHT

		@startuml
		Start
		Partition LA_v_AdaptTBForLCBasedOnLCProb {
			: Initialize Absolute Distance Camera Lane Info;
			Note Left: Absolute Distance Camera Lane Marker Left, Absolute Distance Camera Lane Marker Right, Absolute Distance Camera Lane Marker Adjutance Left, Absolute Distance Camera Lane Marker Adjutance Right ;
			If (Check if distance of the ego-position to the lane marker in case of a lane change to the left) then (true)
				If (If Left Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Camera Lane Signal Status is ok) then (yes)
					If (check if lane marker was not crossed yet and (Right Lane Existence Probability < FIP_CAM_LANE_POE_LEVEL and Absolute Distance Camera Lane Marker Left < LA_CP_PAR_LC_MAX_MARKER_DIST) or (Right Lane Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Absolute Distance Camera Lane Marker Left < Absolute Distance Camera Lane Marker Right)) then (yes)
						: Set to zero since lane change detected, i.e. new lane although camera says something different;
						If (Left Lane Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Absolute Distance Camera Lane Marker Adjutance Left > Absolute Distance Camera Lane Marker Left) then (yes)
							: Calculate Distance Marker Left;
						Else (no)
							: Set Distance Marker to Left as LA Seek Lane Width;
						Endif
					Else (no)
						: Set Distance Marker to Left as Absolute Distance Camera Lane Marker Left;
						: Set Lane Marker was Crossed;
					Endif
				Endif
				If (check if Right Lane Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Camera Lane Signal Status is ok and Distance Marker Right > LA_BRACKETPOS_VALID_VAL_COMPARE)
					: Update Distance Marker Right;
					If (Distance Marker Left > LA_BRACKETPOS_VALID_VAL_COMPARE) then (yes)
						: Update Distance Marker Left with LA Seek Lane Width;
					Endif
					: Check Lane was crossed;
				Endif
			Endif
			If (check if lane marker was not crossed yet and (Right Lane Existence Probability < FIP_CAM_LANE_POE_LEVEL and Absolute Distance Camera Lane Marker Right < LA_CP_PAR_LC_MAX_MARKER_DIST) or (Left Lane Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Absolute Distance Camera Lane Marker Right < Absolute Distance Camera Lane Marker Left)) then (yes)
				: Set to zero since lane change detected, i.e. new lane although camera says something different;
				If (Right Lane Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Absolute Distance Camera Lane Marker Adjutance Right > Absolute Distance Camera Lane Marker Right) then (yes)
					: Calculate Distance Marker Right;
				Else (no)
					: Set Distance Marker to Right as LA Seek Lane Width;
				Endif
			Else (no)
				: Set Distance Marker to Right as Absolute Distance Camera Lane Marker Right;
				: Set Lane Marker was Crossed;
			Endif
			If (check if Left Lane Existence Probability >= FIP_CAM_LANE_POE_LEVEL and Camera Lane Signal Status is ok and Distance Marker Left > LA_BRACKETPOS_VALID_VAL_COMPARE)
				: Update Distance Marker Left;
				If (Distance Marker Right > LA_BRACKETPOS_VALID_VAL_COMPARE) then (yes)
					: Update Distance Marker Right with LA Seek Lane Width;
				Endif
				: Check Lane was crossed;
			Endif
			If (Distance Marker Left < LA_BRACKETPOS_VALID_VAL_COMPARE and Distance Marker Right < LA_BRACKETPOS_VALID_VAL_COMPARE) then (yes)
				If (Distance Marker Left >= Distance Marker Right) then (yes)
					: Set State Scale Bracket as SLATE_POST_LANE_CHANGE_LEFT;
				Else (no)
					: Set State Scale Bracket as SLATE_POST_LANE_CHANGE_RIGHT;
				Endif
				: Set Distance Marker Right and Distance Marker Left as INITVALUE_BRACKETPOSITION;
			Endif
		}
		End
		@enduml

  @return          static void

  @param[in,out]   pf_DistMarkerLeft : Distance to camera lane marker (left side)      [-PI/2*RW_FCT_MAX    PI/2*RW_FCT_MAX]
  @param[in,out]   pf_DistMarkerRight : Distance to camera lane marker (right side)    [-PI/2*RW_FCT_MAX    PI/2*RW_FCT_MAX]
  @param[in,out]   p_StateScaleBracket                                                 [type LA_t_ScaleBracketState defined in la_corridor_crit.h]

  @param[in]       i_LALaneChangeProb : lane chnage probability         [-100s   100s]
  @param[in]       LaneChangeTBState  : State of lane change for trace bracket adaption based on ego position in lane  [type LA_t_LaneChangeTraceBracketState defined in la_corridor_crit.h]
                                           

  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].f_MarkerDist               [-100f   100f]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].u_ExistanceProbability     [0u ...100u]
  @glob_in         pSLATE_CamLaneData->sSigHeader.eSigStatus                         [type AlgoSignalState_t defined in interfaceobjectlist.h]
  @glob_in         LALaneChangeBracket.bMarkerCrossed                                 [type boolean defined in Platform_Types.h] [TRUE,FALSE]

  @glob_out        LALaneChangeBracket.bMarkerCrossed                                 [type boolean defined in Platform_Types.h] [TRUE,FALSE]

  @c_switch_part   -

  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM             : Configuration switch which moves trace brackets in case of no lane change of ego vehicle
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                        : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                        : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                      : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/28/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_AdaptTBForLCBasedOnLCProb(float32 * pf_DistMarkerLeft, float32 * pf_DistMarkerRight, 
            LA_t_ScaleBracketState * p_StateScaleBracket, SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo,
            LA_t_LaneChangeTraceBracketState const LaneChangeTBState)
{
  float32 fAbsDistCamLaneMarkerLeft, fAbsDistCamLaneMarkerRight,fAbsDistCamLane_Adj_MarkerLeft, fAbsDistCamLane_Adj_MarkerRight;
  float32 fLASeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;

  fAbsDistCamLaneMarkerLeft = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist);
  fAbsDistCamLaneMarkerRight = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist);
  fAbsDistCamLane_Adj_MarkerLeft  = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].f_MarkerDist);
  fAbsDistCamLane_Adj_MarkerRight = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].f_MarkerDist);

  /* QAC Fix */
  _PARAM_UNUSED(i_LALaneChangeInfo);

  /*! Determining the distance of the ego-position to the lane marker in case of a lane change to the left*/
  if ( (LaneChangeTBState == LA_TB_LANE_CHANGE_LEFT) || (LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_LEFT) )
  {
    /*! Evaluate lane marker(s) to our left */
    if ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
    {
      /*! Distinguish if the lane marker was already crossed */
      /*! Not crossed yet */
      if ( (LALaneChangeBracket.bMarkerCrossed == FALSE) &&
           (((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability < FIP_CAM_LANE_POE_LEVEL) &&
             (fAbsDistCamLaneMarkerLeft < LA_CP_PAR_LC_MAX_MARKER_DIST)) ||
            ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
             (fAbsDistCamLaneMarkerLeft < fAbsDistCamLaneMarkerRight))) )
      {
        *pf_DistMarkerRight = 0.f; /*!< Set to zero since lane change detected, i.e. new lane although camera says something different */
        /*! Second condition: plausibility */
        if ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
             (fAbsDistCamLane_Adj_MarkerLeft > fAbsDistCamLaneMarkerLeft) )
        {
          *pf_DistMarkerLeft = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].f_MarkerDist); 
        }
        else
        {
          *pf_DistMarkerLeft = fLASeekLaneWidth;
        }
      }
      else /*! Marker was crossed */
      {
        *pf_DistMarkerLeft = fAbsDistCamLaneMarkerLeft; 
        LALaneChangeBracket.bMarkerCrossed = TRUE;
      }
    }
    /*! Evaluate lane marker(s) to our right (only if lane marker was crossed) */
    if ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) && 
         (*pf_DistMarkerRight > LA_BRACKETPOS_VALID_VAL_COMPARE) )
    {
      *pf_DistMarkerRight = fAbsDistCamLaneMarkerRight; 
      if (*pf_DistMarkerLeft  > LA_BRACKETPOS_VALID_VAL_COMPARE)
      {
        *pf_DistMarkerLeft = fLASeekLaneWidth;
      }
      LALaneChangeBracket.bMarkerCrossed = TRUE;
    }
  }
  
  /*! Determining the distance of the ego-position to the lane marker in case of a lane change to the right*/
  if ( (LaneChangeTBState == LA_TB_LANE_CHANGE_RIGHT) || (LALaneChangeBracket.LaneChgTBState == LA_TB_LANE_CHANGE_RIGHT) )
  {
    /*! Evaluate lane marker(s) to our right */
    if ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)) 
    {
      /*! Distinguish if the lane markers were already crossed */
      /*! Not crossed yet */
      if ((LALaneChangeBracket.bMarkerCrossed == FALSE) &&
          (((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability < FIP_CAM_LANE_POE_LEVEL) && 
            (fAbsDistCamLaneMarkerRight < LA_CP_PAR_LC_MAX_MARKER_DIST)) ||
           ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
            (fAbsDistCamLaneMarkerRight < fAbsDistCamLaneMarkerLeft))) 
         )
      {
        *pf_DistMarkerLeft = 0.f;  /*!< Set to zero since lane change detected, i.e. new lane although camera says something different */
        /*! Second condition: plausibility */
        if ((pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&  
            (fAbsDistCamLane_Adj_MarkerRight > fAbsDistCamLaneMarkerRight) )
        {
          *pf_DistMarkerRight = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].f_MarkerDist); 
        }
        else
        {
          *pf_DistMarkerRight = fLASeekLaneWidth;
        }
      }
      else /*! Marker was crossed */
      {
        *pf_DistMarkerRight = fAbsDistCamLaneMarkerRight; 
        LALaneChangeBracket.bMarkerCrossed = TRUE;
      }
    }
    /*! Evaluate lane marker(s) to our left (only if lane marker was crossed) */
    if ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
         (*pf_DistMarkerLeft > LA_BRACKETPOS_VALID_VAL_COMPARE) )
    {
      *pf_DistMarkerLeft = fAbsDistCamLaneMarkerLeft; 
      if (*pf_DistMarkerRight > LA_BRACKETPOS_VALID_VAL_COMPARE)
      {
        *pf_DistMarkerRight = fLASeekLaneWidth;
      }
      LALaneChangeBracket.bMarkerCrossed = TRUE;
    }
  }

  /* ! Set reason for trace bracket adaption */
  if( (*pf_DistMarkerLeft < LA_BRACKETPOS_VALID_VAL_COMPARE) && (*pf_DistMarkerRight < LA_BRACKETPOS_VALID_VAL_COMPARE) )
  {
    if( *pf_DistMarkerLeft >= *pf_DistMarkerRight )
    {
      *p_StateScaleBracket = SLATE_POST_LANE_CHANGE_LEFT;
    }
    else
    {
      *p_StateScaleBracket = SLATE_POST_LANE_CHANGE_RIGHT;
    }

    /* Temporary fix to prevent camera based bracket shift. Lane change phase detection needs to be 
     shifted to sit_lanechange in the future (april 2015) */
    *pf_DistMarkerRight = INITVALUE_BRACKETPOSITION;
    *pf_DistMarkerLeft = INITVALUE_BRACKETPOSITION;
  }

  _PARAM_UNUSED(i_LALaneChangeInfo);
}
#endif /*< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM */


#if (LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM)

/*************************************************************************************************************************
  Functionname:    LA_v_AdaptTBIfNoLC                                                                               */ /*!

  @brief           Trace bracket adaption if ego vehicle is not performing a lane change (lane change probability is low)

  @description     Trace bracket adaption if ego vehicle is not performing a lane change (lane change probability is low):
                   if situation fulfilled, set distance to lane markers (pf_DistMarkerLeft/pf_DistMarkerRight) and 
                   LaneChangeTBState = SLATE_NO_LANE_CHANGE

		@startuml
		Start
		Partition LA_v_AdaptTBIfNoLC {
			: Initialize Absolute Distance Camera Lane Marker Left, Absolute Distance Camera Lane Marker Right and Minimum Distance Marker In lane;
			If (if lane change probability is low and lane markers in cities are often bad or there are no lane markers between two lanes and if the distance to the lane markers is valid and if the distance to the lane markers is not too high) then (yes)
				If (Check if Turn Indicator is off) then (yes)
					: Set Distance Marker Left and Distance Marker Right;
					: Set State Scale Bracket as SLATE_NO_LANE_CHANGE;
				Else (no)
					: Do Nothing;
				Endif
				: Set Distance Marker Left and Distance Marker Right;
				: Set State Scale Bracket as SLATE_NO_LANE_CHANGE;
			Endif
		}
		End
		@enduml

  @return          static void

  @param[in,out]   pf_DistMarkerLeft : Distance to camera lane marker (left side)     [-PI/2*RW_FCT_MAX    PI/2*RW_FCT_MAX]
  @param[in,out]   pf_DistMarkerRight : Distance to camera lane marker (right side)   [-PI/2*RW_FCT_MAX    PI/2*RW_FCT_MAX]
  @param[in,out]   p_StateScaleBracket                                                [type LA_t_ScaleBracketState defined in la_corridor_crit.h]

  @param[in]       b_LCProbValid : boolean to describe if lane change probability is valid [boolean defined in Platform_Types.h] [TRUE,FALSE]
  @param[in]       i_LALaneChangeProb : lane chnage probability                            [-100s   100s]

  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].f_MarkerDist               [-100f   100f]
  @glob_in         LALaneChangeBracket.LaneChgTBState                                 [type LA_t_LaneChangeTraceBracketState defined in la_corridor_crit.h]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].u_ExistanceProbability     [0u ...100u]
  @glob_in         pSLATE_CamLaneData->sSigHeader.eSigStatus                         [type AlgoSignalState_t defined in interfaceobjectlist.h]

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM  : Adaption of trace brackets if the blinker feature is active
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_USE_BMW_BLINKER_FEATURE                  : Use BMW blinker feature
  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST                                    : Configuration switch enabling overtake support feature

  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM             : Configuration switch which moves trace brackets in case of no lane change of ego vehicle
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                        : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                        : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                      : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/28/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_AdaptTBIfNoLC(float32 * const pf_DistMarkerLeft, float32 * const pf_DistMarkerRight, LA_t_ScaleBracketState * const p_StateScaleBracket, boolean const b_LCProbValid, SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo)
{
  float32 fAbsDistCamLaneMarkerLeft, fAbsDistCamLaneMarkerRight,f_MinDistMarkerInlane;

  fAbsDistCamLaneMarkerLeft = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist);
  fAbsDistCamLaneMarkerRight = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist);
  f_MinDistMarkerInlane = MIN_FLOAT(LA_MIN_DIST_MARKER_INLANE, LA_MIN_FACTOR_DIST_MARKER_INLANE * (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight));

  /*! Adaption of trace brackets if the lane change probability is low, i.e. driving "inlane", 
      only if lane change probability is low (and is valid; StateScaleBracket = LA_NO_TB_LANE_CHANGE),
      only for high speed (lane markers in cities are often bad or there are no lane markers between two lanes),
      only if the distance to the lane markers is valid,
      only if the distance to the lane markers is not too high (i.e. lane change might occur even though the probability is not high) */
  if( (b_LCProbValid == TRUE) 
      && (LALaneChangeBracket.LaneChgTBState == LA_NO_TB_LANE_CHANGE) 
    && (i_LALaneChangeInfo.u_LCPhaseProb < (sint16) LA_LC_PROB_LEVEL_LOW)
    && (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_LEVEL_LOW_SPEED)
    && (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL)
    && (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL)
    && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) 
    &&( (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) > LA_TB_RATIO_MIN_CAM_LANE_WIDTH ) 
    && ( (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) < LA_TB_RATIO_MAX_CAM_LANE_WIDTH )
    &&(fAbsDistCamLaneMarkerLeft  > f_MinDistMarkerInlane) 
    &&(fAbsDistCamLaneMarkerRight > f_MinDistMarkerInlane)
    )
  {
    /*! If bmw blinker feature is on or if the blinker is switched on, no adaption */
#if (LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)
#if ((LA_CFG_ADAPT_TRACEBRACKETS_USE_BMW_BLINKER_FEATURE) && (SLATE_CFG_ENABLE_OVERTAKE_ASSIST))
    if(!CP_b_ACC_GetCustomOvertakeAssistanceState())
#else
     if(pSLATE_CustomInput->eTurnIndicator == eTurnIndicator_Off)
#endif
     {
       *pf_DistMarkerLeft = fAbsDistCamLaneMarkerLeft;
       *pf_DistMarkerRight = fAbsDistCamLaneMarkerRight;

       /* ! Set reason for trace bracket adaption */
       *p_StateScaleBracket = SLATE_NO_LANE_CHANGE;
     }
     else
     {
      /*! nothing */
     }
#else
      *pf_DistMarkerLeft = fAbsDistCamLaneMarkerLeft;
      *pf_DistMarkerRight = fAbsDistCamLaneMarkerRight;

      /* ! Set reason for trace bracket adaption */
      *p_StateScaleBracket = SLATE_NO_LANE_CHANGE;
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */
  }
}
#endif /*< LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM */


#if (LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)
/*************************************************************************************************************************
  Functionname:    LA_v_AdaptTBForLCBasedOnBlinkerFeature                                                           */ /*!

  @brief           Trace bracket adaption based on the blinker feature

  @description     Trace bracket adaption based on the blinker feature:
                   if situation fulfilled, set distance to lane markers (pf_DistMarkerLeft/pf_DistMarkerRight) and 
                   LaneChangeTBState = SLATE_PRE_LANE_CHANGE_LEFT/SLATE_PRE_LANE_CHANGE_RIGHT
                   Trace bracket adaption based on the blinker feature keeps active also after blinker feature is active until bBlinkerFeatureTriggered is reset

		@startuml
		Start
		Partition LA_v_AdaptTBForLCBasedOnBlinkerFeature {
		: not reset of trace bracket adaption based on the blinker feature;
		If (if lane change probability is valid and State Scale Bracket is unknown and Ego Velocity Object Sync > LA_LEVEL_LOW_SPEED) then (yes)
			If (check if Left Turn Indicator is active or Right Indicator is active)
				: Trace brackets are adapted based on blinker feature;
			Else (no)
				If (if trace brackets are adapted based on blinker feature) then (yes)
					Repeat
						If (Check if Left Lane Change State) then (yes)
							: Calculate Distance Marker Difference Blinker Feature History;
							If (Distance Marker Difference Blinker Feature History > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL and Distance Marker Difference Blinker Feature History < LA Seek Lane Width * 0.5) then (yes)
								: Reset Blinker Feature Trigger as True;
							Endif
						Else if (Check if Right Lane Change State) then (yes)
							: Calculate Distance Marker Difference Blinker Feature History;
							If (Distance Marker Difference Blinker Feature History > LA_LC_RIGHT_DIFF_DIST_MARKER_HIST_LEVEL and Distance Marker Difference Blinker Feature History < LA Seek Lane Width * 0.5) then (yes)
								: Reset Blinker Feature Trigger as True;
							Endif
						Else (no)
							: Do Nothing;
						Endif
					Repeat While (For Entire LA Lane Change History Buffer)
				Endif
			Endif
			If (if trace brackets are adapted based on blinker feature) then (yes)
				If ((Ego Velocity Object Sync <= LA_LEVEL_LOW_SPEED and LC Phase Probability > LA_LC_PROB_LEVEL_LOW_SPEED) or (Ego Velocity Object Sync <= LA_LEVEL_LOW_SPEED and LC Phase Probability > LA_LC_PROB_LEVEL_HIGH_SPEED) and LC Phase != LC_STEERBACK) then (yes)
					: Reset Blinker Feature Trigger as True;
				Else if (LC Phase Probability < LA_TB_ABORT_BLINKER_FEATURE_LC_PROB_LEVEL) then (yes)
					: Reset Blinker Feature Trigger as True;
				Else (no)
					: No Reset;
				Endif
				If (Reset blinker feature trigger is active) then (yes)
					: Set Blinker Feature Trigger as False;
				Endif
			Endif
			If (if blinker feature is active and the camera lane marker state is valid) then (yes)
				If (If lane change to the left) then (yes)
					: Set distance to lane marker in order to adapt the trace brackets and Move trace brackets in the direction of the lane change;
					: Set reason for trace bracket adaption;
				Else if (If lane change to the right) then (yes)	
					: Set distance to lane marker in order to adapt the trace brackets and Move trace brackets in the direction of the lane change;
					: Set reason for trace bracket adaption;
				Else (no)
					: Do Nothing;
				Endif
			Endif
		Else (no)
			If (if invalid lane change probability and if low velocity of Ego and if trace bracket adaption based on SLATE_POST_LANE_CHANGE_LEFT or SLATE_POST_LANE_CHANGE_RIGHT) then (yes)
				: Reset blinker feature trigger as False;
			Endif
		Endif
		}
		End
		@enduml

  @return          static void

  @param[in,out]   pf_DistMarkerLeft : Distance to camera lane marker (left side)           [-PI/2*RW_FCT_MAX    PI/2*RW_FCT_MAX]
  @param[in,out]   pf_DistMarkerRight : Distance to camera lane marker (right side)         [-PI/2*RW_FCT_MAX    PI/2*RW_FCT_MAX]
  @param[in,out]   p_StateScaleBracket                                                      [type LA_t_ScaleBracketState defined in la_corridor_crit.h]

  @param[in]       i_LALaneChangeProb : lane chnage probability                             [-100s   100s]
  @param[in]       b_ValidLCProb : boolean to describe if lane change probability is valid  [boolean defined in Platform_Types.h] [TRUE,FALSE]

  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[  ].f_MarkerDist               [-100f   100f]
  @glob_in         pSLATE_CustomInput->eTurnIndicator                                [eTurnIndicator_t defined in interfacediverinput.h]
  @glob_in         LALaneChangeBracket.fMarkerDistLeftHistory[   ]                    [full range float32]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[   ].u_ExistanceProbability    [0u ...100u]
  @glob_in         pSLATE_CamLaneData->sSigHeader.eSigStatus                         [type AlgoSignalState_t defined in interfaceobjectlist.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync                                               [-330f  330f]


  @glob_out        LALaneChangeBracket.bBlinkerFeatureTriggered                       [type boolean defined in Platform_Types.h] [TRUE   FALSE]

  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_USE_BMW_BLINKER_FEATURE                 : Use BMW blinker feature
  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST                                   : Configuration switch enabling overtake support feature

  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adaption of trace brackets if the blinker feature is active
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/29/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_AdaptTBForLCBasedOnBlinkerFeature(float32 * const pf_DistMarkerLeft, float32 * const pf_DistMarkerRight, 
            LA_t_ScaleBracketState * const p_StateScaleBracket, SIT_LC_t_LaneChangePhaseInfo const i_LALaneChangeInfo, boolean const b_ValidLCProb)
{
  boolean b_ResetBlinkerFeatureTriggered;
  uint8 i;
  float32 f_DistMarkerDiffBlinkerFeatureHistory;
  float32 fAbsDistCamLaneMarkerLeft, fAbsDistCamLaneMarkerRight;
  float32 fLASeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;

  fAbsDistCamLaneMarkerLeft = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist);
  fAbsDistCamLaneMarkerRight = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist);

  /*! Default: not reset of trace bracket adaption based on the blinker feature */
  b_ResetBlinkerFeatureTriggered = FALSE;
  
  /*! Adaption of trace brackets if the blinker feature is active (StateScaleBracket is SLATE_PRE_LANE_CHANGE_LEFT or SLATE_PRE_LANE_CHANGE_RIGHT);
      only if lane change probability is valid, 
      only if no other trace bracket adpation already active, 
      only for high speed (lane markers in cities are often bad or there are no lane markers between two lanes) */
  if( (b_ValidLCProb == TRUE) &&
      (*p_StateScaleBracket == SLATE_LANE_CHANGE_UNKNOWN) &&
      (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_LEVEL_LOW_SPEED)
    )
  {
    /*! Adapt trace bracket based on blinker feature, 
        if bmw blinker feature is active or if the turn indicator is active */
#if ((LA_CFG_ADAPT_TRACEBRACKETS_USE_BMW_BLINKER_FEATURE) && (SLATE_CFG_ENABLE_OVERTAKE_ASSIST))
    if( CP_b_ACC_GetCustomOvertakeAssistanceState() )
#else
    if( (pSLATE_CustomInput->eTurnIndicator == eTurnIndicator_Left)||
        (pSLATE_CustomInput->eTurnIndicator == eTurnIndicator_Right)
      )
#endif
    {
      LALaneChangeBracket.bBlinkerFeatureTriggered = TRUE;
    }
    else
    {
      /*! Abort trace bracket adaption based on blinker feature (after the blinker feature is not active anymore) 
          if the ego vehicle starts driving in the opposite direction to the lane change */
      if (LALaneChangeBracket.bBlinkerFeatureTriggered)
      {
        for ( i = 0u ; (i < (LA_LANE_CHANGE_HISTORY_BUFFER - 1u)) && (b_ResetBlinkerFeatureTriggered == FALSE); i++)
        {
          if ( i_LALaneChangeInfo.t_LCPhaseState == LC_LEFT )
          {
            f_DistMarkerDiffBlinkerFeatureHistory = LALaneChangeBracket.fMarkerDistLeftHistory[i] - LALaneChangeBracket.fMarkerDistLeftHistory[i + 1u];
            if( (f_DistMarkerDiffBlinkerFeatureHistory > LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL) && 
                (f_DistMarkerDiffBlinkerFeatureHistory < (fLASeekLaneWidth * 0.5f)) 
              )
            {
              b_ResetBlinkerFeatureTriggered = TRUE;
            }
          }
          else if (i_LALaneChangeInfo.t_LCPhaseState == LC_RIGHT)// PRQA S 2004 
		  /* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: conditions are checking in if and elseif, else is not required*/
          {
            f_DistMarkerDiffBlinkerFeatureHistory = LALaneChangeBracket.fMarkerDistRightHistory[i] - LALaneChangeBracket.fMarkerDistRightHistory[i + 1u];
            if( (f_DistMarkerDiffBlinkerFeatureHistory < LA_LC_RIGHT_DIFF_DIST_MARKER_HIST_LEVEL) && 
                (f_DistMarkerDiffBlinkerFeatureHistory > (- fLASeekLaneWidth * 0.5f)) 
              )
            {
              b_ResetBlinkerFeatureTriggered = TRUE;
            }
          }
        }
      }
    }

    /*! Reset conditions independed current blinker feature status (blinker feature may/may not be active in this cycle) */
    if(LALaneChangeBracket.bBlinkerFeatureTriggered)
    {
      /* Abort trace bracket adaption based on blinker feature if the lane change probability is so high 
        that the trace bracket adaption should be active due to POST_LANE_CHANGE */
      if( ( ( (*pt_LAInput->t_RTE.pf_EgoVelObjSync <= LA_LEVEL_LOW_SPEED) 
          && (i_LALaneChangeInfo.u_LCPhaseProb > (uint8) LA_LC_PROB_LEVEL_LOW_SPEED)
            ) 
        ||( (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_LEVEL_LOW_SPEED) 
        && (i_LALaneChangeInfo.u_LCPhaseProb > (uint8) LA_LC_PROB_LEVEL_HIGH_SPEED)
            )
          )
          && (i_LALaneChangeInfo.t_LCPhase != LC_STEERBACK )
        )
      {
        b_ResetBlinkerFeatureTriggered = TRUE;
      }
      /* Abort trace bracket adaption based on blinker feature if lane change probability is too low */
      else if(i_LALaneChangeInfo.u_LCPhaseProb < LA_TB_ABORT_BLINKER_FEATURE_LC_PROB_LEVEL) 
      {
        b_ResetBlinkerFeatureTriggered = TRUE;
      }
      else
      {
        /*! No reset */
      }

      /*! Reset blinker feature trigger */
      if (b_ResetBlinkerFeatureTriggered)
      {
        LALaneChangeBracket.bBlinkerFeatureTriggered = FALSE;
      }
    }

    /* Adapt trace brackets if blinker feature is active and the camera lane marker state is valid */
    if( (LALaneChangeBracket.bBlinkerFeatureTriggered) &&
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
        (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
        (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
        ( (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) > LA_TB_RATIO_MIN_CAM_LANE_WIDTH ) &&
        ( (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) < LA_TB_RATIO_MAX_CAM_LANE_WIDTH )
      )
    {
      if (i_LALaneChangeInfo.t_LCPhaseState == LC_LEFT ) /*!< In case of a lane change to the left */
      {
        /* Set distance to lane marker in order to adapt the trace brackets; 
           move trace brackets in the direction of the lane change */
        *pf_DistMarkerLeft = (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) * LA_TB_INCREASE_FACTOR_BLINKER_FEATURE;
        *pf_DistMarkerRight = (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) * LA_TB_DECREASE_FACTOR_BLINKER_FEATURE;

        /*! Set reason for trace bracket adaption */
        *p_StateScaleBracket = SLATE_PRE_LANE_CHANGE_LEFT;
      }
      else if(i_LALaneChangeInfo.t_LCPhaseState == LC_RIGHT) /*!< In case of a lane change to the right */// PRQA S 2004 
	  /* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: conditions are checking in if and elseif, else is not required*/
      {
        /* Set distance to lane marker in order to adapt the trace brackets; 
           move trace brackets in the direction of the lane change */
        *pf_DistMarkerRight = (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) * LA_TB_INCREASE_FACTOR_BLINKER_FEATURE;
        *pf_DistMarkerLeft = (fAbsDistCamLaneMarkerLeft + fAbsDistCamLaneMarkerRight) * LA_TB_DECREASE_FACTOR_BLINKER_FEATURE;
        /*! Set reason for trace bracket adaption */
        *p_StateScaleBracket = SLATE_PRE_LANE_CHANGE_RIGHT;
      }
    }
  }
  else
  {
    /*! Reset blinker feature trigger:
          if invalid lane change probability,
          if low velocity,
          if trace bracket adaption based on SLATE_POST_LANE_CHANGE_LEFT/SLATE_POST_LANE_CHANGE_RIGHT */
    if( (b_ValidLCProb == FALSE) || 
        (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_LEVEL_LOW_SPEED) || 
        (*p_StateScaleBracket == SLATE_POST_LANE_CHANGE_LEFT) || 
        (*p_StateScaleBracket == SLATE_POST_LANE_CHANGE_RIGHT) 
      )
    {
      LALaneChangeBracket.bBlinkerFeatureTriggered = FALSE;
    }
  }
}
#endif /*< LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */
/** @} end defgroup */
#endif /*!< (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) */
#endif /*!< #if(FCT_CFG_ACC_LANE_ASSOCIATION) */
