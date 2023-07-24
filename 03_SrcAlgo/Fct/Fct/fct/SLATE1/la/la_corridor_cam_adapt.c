/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_cam_adapt.c

DESCRIPTION:               ACC object corridor brackets adaptation implementation. This 
                           is a subsidiary file along with la_corridor_cam.c for all 
                           things related to trace brackets using camera lane information. 

                           All functions related to checking if adaptation is necessary 
                           for a given object and implementing the adaptation for a given 
                           object is included here.

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             05.11.2014

VERSION:                   $Revision: 1.21 $

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
@defgroup la_corridor_cam_adapt LA camera adaptation
@ingroup la_corridor_cam
@brief         Checking if adaptation is necessary for a given object and implementing adaptation is done. \n\n

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

/* ExtensionCamLaneObjAssoc: */
 #if(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA) 
  #define LA_MAX_VREL_CAM_LANE_OBJ_USE_OVERLAP        (-3.5f)
  #define LA_MAX_EGO_VEL_CAM_LANE_NEAR_RANGE      	  (60.f/C_KMH_MS)
  #define LA_MAX_EGO_VEL_CAM_LANE_NON_REL_OBJ_ADD     (20.f/C_KMH_MS)

  /* ObjDist Thresholds [m] */
  #define LA_MAX_OBJ_DIST_CAM_LANE_NEAR_RANGE      	(20.f)
  /* Extensions [m] */
  #define LA_EXT_CAM_LANE_OBJ_ASSOC_NEAR_EXT          (0.4f)
 #endif /*(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)*/

/* Vrel Thresholds [m/s] */
#define LA_MAX_VREL_CAM_LANE_OBJ_ASSOC_EXT          (-5.f)


/* Vego Thresholds [m/s] */
#define LA_MAX_EGO_VEL_CAM_LANE_OBJ_ASSOC_EXT       (70.f/C_KMH_MS)



/* Extensions [m] */
#define LA_EXT_TRACK_CAM_LANE_OBJ_ASSOC_EXT         (1.f)
#define LA_EXT_SEEK_CAM_LANE_OBJ_ASSOC_EXT          (0.5f)



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
static void LA_v_AdaptTBBasedOnPerformedLC(LA_t_RelTraObjInput const * pObj, LA_t_AssTraEnvironment const * pEnvironment, 
                                           const LA_t_ScaleBracketOutput * pRatioEgoPosInLine, 
                                           float32 fYDist, float32 fDist2Ref,
                                           boolean * pReturnValue);
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */

#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
static void LA_v_RelTraExtensionCamLaneObjAssoc(LA_t_RelTraObjInput const * pObjInput, LA_t_BracketOutput const * pBracketBase, LA_t_BracketOutput * pBracketOut);
#endif

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*************************************************************************************************************************
  Functionname:    LA_b_FindObjRelevantForTraceBracketAdaptPosInLaneCam                                                */ /*!

  @brief           Decision if the trace bracket adaption should be performed for the specific object

  @description     Elementary assignment of the object to the ego-/left/right lane; depending on this decision a 
                   trace bracket adaption is performed (if object is on the ego lane, 
                   the trace brackets are moved if the object can be "caught" more easily; if the object is on the the left/right lane,
                   the trace brackets are moved if the object can be "caught" less easily)
                   Test if the object was classified as oncoming, i.e. no adaption should be performed

		@startuml
		Start
		Partition LA_b_FindObjRelevantForTraceBracketAdaptPosInLaneCam {
		: Initialize variable for assigning the object to the ego-lane;
		: Initialize the number of lanes;
		: Set Visibility distance of camera lane, Curvature of camera lane and Heading angle of camera lane;
		If (Scale Bracket Right and Left < LA_BRACKETPOS_VALID_VAL_COMPARE) then (yes)
			: Calculate lateral distance to the object, polar distance to the object and longitudinal distance to the object;
			: Calculate lateral offset due to camera lane curvature;
			If (Camera Lane Visibility Distance > the longitudinal distance to the object) then (yes)
				: Consider Only the curvature of the camera lane;
			Else (no)
				: Determine the offset of the lateral displacement of the object based on the ACC-trajectory;
			Endif
			: Calculate Lateral Curve Distance;
			: Determine Lateral Distance to the Object;
			: Compensate lateral distance to object based on the ego-position in lane;
			: Determine the distance of the object to the ACC-trajectory and compensate this distance based on the ego-position in lane;
			If (Check if State of trace bracket adaption is SLATE_NO_LANE_CHANGE and ego curve < LA_LEVEL_CURVE_DIFF_CAM_EGO) then (yes) 
				If (Curvy Camera Lane > LA_TB_LANE_ASSO_CAM_COURSE_LEVEL and Absolute Raw Ego Curve > LA_TB_LANE_ASSO_CAM_COURSE_EGO_COURSE_DIFF_LEVEL) then (yes)
					If (Object is to the left) then (yes)
						: Set Number of Left Lanes;
					Else (no)
						: Set Number of right Lanes;
					Endif
					: Set Left and Right Road Edge of Camera Lane;
					If (Check if Number of Lane is one and (there is no right and left road edge) and (No Lateral distance on Right Side) or (No Lateral Distance on Left side)) then (True)
						: There is only one Lane that is Ego Lane;
					Else (False)
						If (Check if Lateral Distance to right side) then (yes)							: There is one more Lane that is Right Lane;
						Else (no)
							If (Check if Lateral Distance to left side) then (yes)
								: There is one more Lane that is Left Lane;
							Else (no)
								: There is only one Lane that is Ego Lane;
							Endif
						Endif
					Endif
				Else (no)
					If (Check if Lateral Distance to right side) then (yes)
						: There is one more Lane that is Right Lane;
					Else (no)
						If (Check if Lateral Distance to left side) then (yes)
							: There is one more Lane that is Left Lane;
						Else (no)
							: There is only one Lane that is Ego Lane;
						Endif
					Endif
					If (check if object on ego-lane) then (yes)
						If (if object on the right side of ego vehicle) then (yes)
							: Object adaption is needed;
						Endif
						If (if object on the left side of ego vehicle) then (yes)
							: Object adaption is needed;
						Endif
					Endif
					If (check if object on the right lane of ego vehicle) then (yes)
						: Object adaption is needed;
					Endif
					If (check if object on the left lane of ego vehicle) then (yes)
						: Object adaption is needed;
					Endif
				Endif
			Endif
			: Adapt trace brackets due to performed lance change;
		Endif
		If (If the object was classified as oncoming) then (yes)
			: no adaption should be performed;
		Endif
		}
		End
		@enduml

  @return          boolean : the variable tells if trace bracket adaption is needed for the object

  @param[in]       pObj : data about object; pointer to LA_t_RelTraObjInput defined in la_corridor_crit.h
                      pObj->dAbst_mittel                       [full range float32]
                      pObj->dWinkel_mittel                     [full range float32]
                      pObj->dAblage_m                          [full range float32]
                      pObj->iObjNr                             [type ObjNumber_t defined in Rte_Type.h] [0u   39u]

  @param[in]       pEnvironment : data about number of lanes ; pointer to LA_t_AssTraEnvironment defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesLeft                  [Full range sint32]
                      pEnvironment->iNumberLanesRight                 [Full range sint32]

  @param[in]       pRatioEgoPosInLine : data about factor for trace bracket adaption info if adaption is relevant;  pointer to LA_t_ScaleBracketOutput defined in LA_t_ScaleBracketOutput
                      pRatioEgoPosInLine->fScaleBracketRight             [full range float32]
                      pRatioEgoPosInLine->fScaleBracketLeft              [full range float32]

  @glob_in         CP_TrajectoryData.Current.fTrajC1 : clothoid parameter        [-1f   1f]
  @glob_in         CP_TrajectoryData.Current.fTrajC0 : clothoid parameter        [-1f   1f]
  @glob_in         pSLATE_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist        [-100.f ...100.f]
  @glob_in         OBJ_GET_OBJ_TO_REF_DISTANCE(   )                             [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurveRaw                            [-1f   1f]
  @glob_in         pt_LAInput->t_FIPOA.pt_ObjBool(pObj->iObjNr)->bit_ObjWasOncoming                                [0u   1u]
  @glob_in         ptLAOutput->f_LA_SeekLaneWidth : global seek lane width variable     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c-switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             LA_v_CalculateBaseLaneWidths has to be calculated for ptLA_Output->f_LA_SeekLaneWidth value
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015


  @author          Marie-Theres Boll
*************************************************************************************************************************/
boolean LA_b_FindObjRelevantForTraceBracketAdaptPosInLaneCam(LA_t_RelTraObjInput const * pObj, LA_t_AssTraEnvironment const * pEnvironment, const LA_t_ScaleBracketOutput * pRatioEgoPosInLine)
{
  /*! Declaration of variables */
  boolean returnValue;
  boolean b_CamLaneLeftIsRoadEdge, b_CamLaneRightIsRoadEdge;
  sint32 iNumLanes;
  float32 fCamLaneSin, fObjPolarDist, fCamLaneCOS, fX, yCompensateCam, fYDistCurve, yCompensateSITraj, fYDist, fCompensateEgoPos, fYDistCompensate, fDist2Ref, fDist2RefCompensate;
  float32 f_CamLaneVisibilityDist, f_CamLaneC0, f_CamLaneAngle;
  LA_t_InLaneDecision dec_lane;
  float32 fLASeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;
  float32 fABS_CamLaneC0_EgoCurveRaw, fABS_CamLaneC0, fABS_RIGHT_MarkerDist, fABS_LEFT_MarkerDist;	/* For calculating ABS value */

  /*! Set default factor value */
  dec_lane = UNKNOWN_LANE;        /*!< Initialization of the variable for assigning the object to the ego-lane */
  iNumLanes = 0;                  /*!< Initialization of the number of lanes */
  returnValue = FALSE;            /*!< Initialization of the return value */

  /*! If the factors for the trace bracket adaption are determined, the object is assigned elementarily the the ego-/left/right lane.
  An adaption of the trace brackets is performed depending on this assignment. */
  f_CamLaneVisibilityDist = (pt_LAInput->pt_FIPCamLane->f_VisibilityDist);/*!< Visibility distance of camera lane */
  f_CamLaneC0 = (pt_LAInput->pt_FIPCamLane->f_Curve);                      /*!< Curvature of camera lane */
  f_CamLaneAngle = (pt_LAInput->pt_FIPCamLane->f_HeadingAngle);            /*!< Heading angle of camera lane */
  if ((pRatioEgoPosInLine->fScaleBracketRight < LA_BRACKETPOS_VALID_VAL_COMPARE) && 
    (pRatioEgoPosInLine->fScaleBracketLeft < LA_BRACKETPOS_VALID_VAL_COMPARE))
  {

    /*! Calculation of lateral distance to the object; thereby, the lateral offset due to the curvature of the lane is considered */
    fCamLaneSin = SIN_(- f_CamLaneAngle + DEG2RAD(pObj->dWinkel_mittel));
    fObjPolarDist = SQRT(SQR(pObj->dAblage_m) + SQR(pObj->dAbst_mittel));       /*!< polar distance to the object */
    fCamLaneCOS = COS_(- f_CamLaneAngle + DEG2RAD(pObj->dWinkel_mittel));
    fX = fCamLaneCOS * fObjPolarDist;                                           /*!< longitudinal distance to the object */
    yCompensateCam = 0.5f * f_CamLaneC0 * SQR(fX);   /*!< lateral offset due to camera lane curvature */

    /*! If the visibility of the camera lane is lower than the longitudinal distance to the object, 
    the mean of the offset of the lateral displacement based on the camera lane and the ACC-trajectory is used */
    if (f_CamLaneVisibilityDist > pObj->dAbst_mittel)
    {
      /*! Only the curvature of the camera lane is considered */
      yCompensateSITraj = yCompensateCam;
    }
    else
    {
      /*! Determining the offset of the lateral displacement of the object based on the ACC-trajectory */
      yCompensateSITraj = (C_SIXTH * (pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1) * SQR(pObj->dAbst_mittel) * pObj->dAbst_mittel) + 
        (0.5f * pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0 * SQR(pObj->dAbst_mittel));
    }
    /*! Calculation of the mean */
    fYDistCurve = 0.5f * (yCompensateCam + yCompensateSITraj);

    /*! Determing the lateral distance to the object; thereby the curvature of the lane is considered */
    fYDist = (fCamLaneSin * fObjPolarDist) - fYDistCurve;

    /*! Compensate lateral distance to object based on the ego-position in lane */
    fCompensateEgoPos = fLASeekLaneWidth * (pRatioEgoPosInLine->fScaleBracketRight - 1.f);
    fYDistCompensate = fYDist + fCompensateEgoPos;

    /*! Determine the distance of the object to the ACC-trajectory and compensate this distance based on the ego-position in lane */
    fDist2Ref = *LA_pf_ObjToRefDistMeas(pObj->iObjNr);
    fDist2RefCompensate = fDist2Ref + fCompensateEgoPos;
    
    /* If the trace brackets are supposed to be adapted due to driving in the ego lane (no lane change); 
    condition for adaption of the trace bracket: the difference between the ego curve and the curvature 
    of the camera lane is not allowed to be too high (otherwise the camera lane cannot be trusted) */
	fABS_CamLaneC0_EgoCurveRaw = fABS(f_CamLaneC0 - (*pt_LAInput->t_RTE.pf_EgoCurveRaw));
	fABS_CamLaneC0 = fABS(f_CamLaneC0);
	fABS_RIGHT_MarkerDist = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist);
	fABS_LEFT_MarkerDist  = fABS(pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist);
    if( (pRatioEgoPosInLine->StateScaleBracket == SLATE_NO_LANE_CHANGE) &&
        (fABS_CamLaneC0_EgoCurveRaw < LA_LEVEL_CURVE_DIFF_CAM_EGO) 
      )
    {
      /*! A elementary assignment of the object to the ego/left/right lane is performed */

      /*! Distinction if we are driving on a curvy road or not */
      /*! Driving on a curvy lane (or the difference between the lane curvature and the ego-course is high) */
      if((fABS_CamLaneC0 > LA_TB_LANE_ASSO_CAM_COURSE_LEVEL) || 
         (fABS_CamLaneC0_EgoCurveRaw > LA_TB_LANE_ASSO_CAM_COURSE_EGO_COURSE_DIFF_LEVEL) 
        )
      {
        /*! Determining the number of lanes in the direction if the considered object */
        /*! Object is to the left */
        if(fYDist > 0.f) 
        {
          iNumLanes = pEnvironment->iNumberLanesLeft;
        }
        else /*! Object is to the right */
        {
          iNumLanes = pEnvironment->iNumberLanesRight;
        }

        

        /*! Distinguish for lane association if there is no other lane in the direction of the object or not */
        /*! No other lane: If there is no other lane in the direction of the object 
           (i.e. there is a continuous lane in the direction of the object but no continuous lanes on both sides of the ego vehicle), 
        it is very likely that the object is on the ego lane (or the lateral distance to the object is very high and it might be a mirror object) */
        /*! Get info if camera lane markers is road border */
        b_CamLaneLeftIsRoadEdge = (pt_LAInput->pt_FIPCamLane->b_CamLaneIsRoadEdge[FIP_CL_MK_LEFT]);
        b_CamLaneRightIsRoadEdge = (pt_LAInput->pt_FIPCamLane->b_CamLaneIsRoadEdge[FIP_CL_MK_RIGHT]);
        if ((iNumLanes < 2) && /*!< iNumLanes = 1 is considered as "no lane" since there is often the emergency lane on the highway */
            ( (b_CamLaneRightIsRoadEdge == FALSE) || 
              (b_CamLaneLeftIsRoadEdge == FALSE)
            )
            &&
            ( ( (fYDist < 0.f) && (fYDist > -(2.f * fABS_RIGHT_MarkerDist)) && 
                (b_CamLaneRightIsRoadEdge == TRUE)
              )
              ||
              ( (fYDist > 0.f) && (fYDist <  (2.f * fABS_LEFT_MarkerDist)) && 
                (b_CamLaneLeftIsRoadEdge == TRUE) )
              )
           )
        {
          dec_lane = EGO_LANE;
        }
        else /*! Other parameters for lane association if there is at least one next lane in the direction of the object */
        {
          if ((fYDistCompensate < - (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_COMP_PARA_MULTI_LANE)) || 
              (fYDist < - (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_PARA_MULTI_LANE)) || 
              (fDist2RefCompensate < - fLASeekLaneWidth) 
             )
          {
            dec_lane = RIGHT_LANE;
          }
          else
          {
            if ((fYDistCompensate > (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_COMP_PARA_MULTI_LANE)) || 
                (fYDist > (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_PARA_MULTI_LANE)) || 
                (fDist2RefCompensate > fLASeekLaneWidth) 
               )
            {
              dec_lane = LEFT_LANE;
            }
            else
            {
              dec_lane = EGO_LANE;
            }
          }
        }
      }
      else /*! Driving on a straight lane: other parameters for lane association */
      {
        if ((fYDistCompensate < - (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_COMP_PARA_STRAIGHT_LANE)) || 
            (fYDist < - (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_PARA_STRAIGHT_LANE)) || 
            (fDist2RefCompensate < - fLASeekLaneWidth) 
           )
        {
          dec_lane = RIGHT_LANE;
        }
        else
        {
          if ((fYDistCompensate > (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_COMP_PARA_STRAIGHT_LANE)) || 
              (fYDist > (fLASeekLaneWidth * LA_TB_ASSO_LAT_DIST_PARA_STRAIGHT_LANE)) || 
              (fDist2RefCompensate > fLASeekLaneWidth) 
             )
          {
            dec_lane = LEFT_LANE;
          }
          else
          {
            dec_lane = EGO_LANE;
          }
        }
      }

      /*! object on ego-lane -> adapt trace brackets only if the object can be pick-uped easier */
      if(dec_lane == EGO_LANE)
      {
        /*! object on the right side of ego vehicle */
        if((fDist2Ref < 0.f) && (pRatioEgoPosInLine->fScaleBracketRight > 1.f))
        {
          returnValue = TRUE;
        }
        /*! object on the left side of ego vehicle */
        if((fDist2Ref > 0.f) && (pRatioEgoPosInLine->fScaleBracketRight < 1.f))
        {
          returnValue = TRUE;
        }
      }

      /*! object on the right lane of ego vehicle -> adapt trace brackets only if it becomes more difficult to pick-up the object */
      if((dec_lane == RIGHT_LANE) && (pRatioEgoPosInLine->fScaleBracketRight < 1.f))
      {
        returnValue = TRUE;
      }
      
      /*! object on the left lane of ego vehicle -> adapt trace brackets only if it becomes more difficult to pick-up the object */
      if((dec_lane == LEFT_LANE) && (pRatioEgoPosInLine->fScaleBracketRight > 1.f))
      {
        returnValue = TRUE;
      }
    }

    /*! If the trace brackets are supposed to be adapted due to a performed lane change: 
    Check if the object is on the second next lane (than no adaption of the trace brackets is performed);
    Check if the object performs a lane change at the same time as the ego-vehicle (than no adaption of the trace brackets is performed) 
    Check if the object is inlane but deselected due to the instable yaw rate in a lane change situation (than no adaption of the trace brackets is performed)*/
    LA_v_AdaptTBBasedOnPerformedLC(pObj, pEnvironment, pRatioEgoPosInLine, fYDist, fDist2Ref, &returnValue);
  }
  
  /*! If the object was classified as oncoming, no adaption should be performed */
  if (pt_LAInput->pt_FIPOA->t_ObjList[pObj->iObjNr].t_Bool.bit_ObjWasOncoming == (ubit8_t)1u)
  {
    returnValue = FALSE;
  }

  return returnValue;
}

/*************************************************************************************************************************
  Functionname:    LA_v_AdaptTBBasedOnPerformedLC                                                                   */ /*!

  @brief           Adapt trace brackets due to performed lance change

  @description     If the trace brackets are supposed to be adapted due to a performed lane change: 
                   Check if the object is on the second next lane (than no adaption of the trace brackets is performed);
                   Check if the object performs a lane change at the same time as the ego-vehicle 
                   (than no adaption of the trace brackets is performed);
                   Check if the object is inlane but deselected due to the instable yaw rate in a lane change situation 
                   (than no adaption of the trace brackets is performed);

		@startuml
		Start
		Partition LA_v_AdaptTBBasedOnPerformedLC {
		If (check if Lane change to the left based on internal LC prob or Lane change to the right based on internal LC prob or Lane change to the left based on blinker feature
		Or Lane change to the right based on blinker feature) then (yes)
			If (check if Lane change to the left) then (yes)
				: Update number of lanes, Object Lateral Velocity and Object Lateral Displacement;
			Else (no)
				: Update number of lanes, Lateral Distance, Object Lateral Velocity and Object Lateral Displacement;
			Endif
			If (Only one Lane or Lateral Distance <= SI Seek Lane Width * LA_FAC_LANEWIDTH_OBJECT_SELECTION) then (yes)
				If (Check if Object is performing a lane change as the ego-vehicle or the object is inlane but deselected due to the instable yaw rate in lane change situations and different parameters for the POST_LANE_CHANGE and PRE_LANE_CHANGE situation when de-selection of object due to the instable yaw rate) then (yes)
					: Do Nothing;
				Else (no)
					: Adapt trace brackets due to performed lance change;
				Endif
			Endif
		Endif
		}
		End
		@enduml

  @return          static void

  @param[in]       pObj : data about object; pointer to LA_t_RelTraObjInput defined in la_corridor_crit.h
                      pObjInput->iObjNr                        [type ObjNumber_t defined in Rte_type.h] [0u   39u]

  @param[in]       pEnvironment : data about number of lanes; pointer to LA_t_AssTraEnvironment defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesLeft           [full range sint32]
                      pEnvironment->iNumberLanesRight          [full range sint32]

  @param[in]       pRatioEgoPosInLine : data about factor for trace bracket adaption, info if adaption is relevant; 
                                        pointer to LA_t_ScaleBracketOutput defined in la_corridor_crit.h
                      pRatioEgoPosInLine->StateScaleBracket    [type SIScaleBracketState_t defined in la_corridor_crit.h]

  @param[in]       fYDist : lateral distance to the object                      [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @param[in]       fDist2Ref : distance of the object to the ACC-trajectory     [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @param[in,out]   pReturnValue : pointer to return value declared in LA_b_FindObjRelevantForTraceBracketAdaptPosInLaneCam()     [type boolean defined in Platform_Types.h] [TRUE,FALSE]

  @glob_in         OBJ_LAT_VREL(   )                      [-330f   330f]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (   )              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(   )                     [-330f   330f]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (   )             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
  @glob_in         pt_LAOutput->t_LAObjOutputList[   ].ObjCor.dRelevantZeit   [full range float32]
  @glob_in         ptLAOutput->f_LA_SeekLaneWidth : global seek lane width variable        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   -

  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c-switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             LA_v_CalculateBaseLaneWidths has to be calculated for ptLA_Output->f_LA_SeekLaneWidth value
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/30/2015

  @author          Harsha Umesh Babu
*************************************************************************************************************************/
static void LA_v_AdaptTBBasedOnPerformedLC(LA_t_RelTraObjInput const * pObj, LA_t_AssTraEnvironment const * pEnvironment, 
                                     const LA_t_ScaleBracketOutput * pRatioEgoPosInLine, 
                                     float32 fYDist, float32 fDist2Ref,
                                     boolean * pReturnValue)
{
  sint32 iNumLanes;
  float32 fSISeekLaneWidth = pt_LAOutput->f_LA_SeekLaneWidth;

  if( (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_LEFT) ||
    (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_RIGHT) ||
    (pRatioEgoPosInLine->StateScaleBracket == SLATE_PRE_LANE_CHANGE_LEFT) ||
    (pRatioEgoPosInLine->StateScaleBracket == SLATE_PRE_LANE_CHANGE_RIGHT)
    )
  {
    float32 fObjLatVel, fObjLatDisp;
    float32 fObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(pObj->iObjNr);
    float32 fObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(pObj->iObjNr);

    /*! Lane change to the left */
    if ( (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_LEFT) || (pRatioEgoPosInLine->StateScaleBracket == SLATE_PRE_LANE_CHANGE_LEFT) )
    {
      iNumLanes = pEnvironment->iNumberLanesLeft;
      fObjLatVel = *pt_LAInput->t_RTE.pf_ObjVrelY(pObj->iObjNr);
      fObjLatDisp = *pt_LAInput->t_RTE.pf_ObjLatDisp(pObj->iObjNr);
    }
    else /*! Lane change to the right */
    {
      iNumLanes = pEnvironment->iNumberLanesRight;
      fYDist = - fYDist;
      fDist2Ref = - fDist2Ref;
      fObjLatVel = - *pt_LAInput->t_RTE.pf_ObjVrelY(pObj->iObjNr);
      fObjLatDisp = - *pt_LAInput->t_RTE.pf_ObjLatDisp(pObj->iObjNr);
    }

    /*! Object is not on the second next lane */
    if( (iNumLanes < 2) || (fYDist <= (fSISeekLaneWidth * LA_FAC_LANEWIDTH_OBJECT_SELECTION)) )
    {
      /*! Object is performing a lane change as the ego-vehicle or 
      the object is inlane but deselected due to the instable yaw rate in lane change situations; 
      different parameters for the POST_LANE_CHANGE and PRE_LANE_CHANGE situation when 
      de-selection of object due to the instable yaw rate */
      if( ( (fObjLatVel > LA_TB_ASSO_LC_LAT_VREL_PARA) && 
            (fObjVrelX > LA_TB_ASSO_LC_LONG_VREL_PARA) && 
            ( (fObjLatDisp > LA_TB_ASSO_LC_LAT_DIST_MIN_PARA) ||
              (fYDist > LA_TB_ASSO_LC_COURSE_LAT_DIST_MIN_PARA)
            ) &&
            (fDist2Ref < LA_TB_ASSO_LC_LAT_DIST_MAX_ACC_LANE_PARA) &&
            (fDist2Ref > LA_TB_ASSO_LC_LAT_DIST_MIN_ACC_LANE_PARA) && 
            (fObjLongDisp < LA_TB_ASSO_LC_LONG_DIST_MAX_PARALL) &&
            ( (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_LEFT) || 
              (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_RIGHT)
            )
          ) /*!< Parallel lane change of ego-vehicle and object */
          ||
          ( ( (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_LEFT) || 
              (pRatioEgoPosInLine->StateScaleBracket == SLATE_POST_LANE_CHANGE_RIGHT)
            ) &&
            (pt_LAOutput->t_LAObjOutputList[pObj->iObjNr].ObjCor.dRelevantZeit > LA_TB_ASSO_POST_LC_TIME_RELEVANT_PARA_MIN) && 
            (pt_LAOutput->t_LAObjOutputList[pObj->iObjNr].ObjCor.dRelevantZeit < LA_TB_ASSO_LC_TIME_RELEVANT_PARA_MAX) && 
            (fYDist > LA_TB_ASSO_POST_LC_LAT_DIST_CAM_LANE_PARA) && 
            (fDist2Ref < LA_TB_ASSO_LC_LAT_DIST_MAX_ACC_LANE_PARA)
          ) /*!< Deselection of object due to the instable yaw rate in a lane change situation (POST_LANE_CHANGE) */
          ||
          ( ( (pRatioEgoPosInLine->StateScaleBracket == SLATE_PRE_LANE_CHANGE_LEFT) || 
              (pRatioEgoPosInLine->StateScaleBracket == SLATE_PRE_LANE_CHANGE_RIGHT)
            ) &&
            (pt_LAOutput->t_LAObjOutputList[pObj->iObjNr].ObjCor.dRelevantZeit < LA_TB_ASSO_LC_TIME_RELEVANT_PARA_MAX) && 
            ( ( (pt_LAOutput->t_LAObjOutputList[pObj->iObjNr].ObjCor.dRelevantZeit > LA_TB_ASSO_PRE_LC_MIN_TIME_RELEVANT_PARA) && 
                (fYDist > LA_TB_ASSO_PRE_LC_LAT_DIST_CAM_LANE_PARA)
              ) 
              ||
              ( (pt_LAOutput->t_LAObjOutputList[pObj->iObjNr].ObjCor.dRelevantZeit > LA_TB_ASSO_PRE_LC_MIN_MIN_TIME_RELEVANT_PARA) && 
                (fYDist > LA_TB_ASSO_PRE_LC_LAT_DIST_CAM_LANE_PARA) && 
                (fObjLatDisp > LA_TB_ASSO_PRE_LC_LAT_DIST_PARA)
              )
            ) && 
            (fDist2Ref < LA_TB_ASSO_LC_LAT_DIST_MAX_ACC_LANE_PARA)
          ) /*!< Deselection of object due to the instable yaw rate in a lane change situation (PRE_LANE_CHANGE) */
        )
      {
        /* do nothing */
      }
      else
      {
        *pReturnValue = TRUE;
      }
    }
  }
}


#endif  /*!< #if (LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || 
                  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM ||
                  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) */

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraSetTrackWidthScale                                                                       */ /*!

  @brief           Moving the Center of the trace brackets based on a given ratio for the left and right trace brackets

  @description     Moving the Center of the trace brackets based on a given ratio for the left and right trace brackets
                   This function should ideally be in si_corridor_cam.c but avoid the STLIN error, it is retained here.

		@startuml
		Start
		Partition LA_v_RelTraSetTrackWidthScale {
		If (if the TrackWidth (TrackWidthRight,TrackWidthLeft) and the ratio for moving the center (BracketPositionLeft, BracketPositionRight) were already determined) then (yes)
			: Moving the center of the trace bracket to y = 0;
			: Adjusting the trace brackets according to factor and moving to former lateral position;
			If (If the left trace bracket is longer) then (yes)
				: Calculate Track Width Right Scale and Track Width Left Scale;
			Else (no)
				: Calculate Track Width Left Scale and Track Width Right Scale;
			Endif
			: Setting the new trace brackets to Track width Right and Left;
		Endif
		}
		End
		@enduml

  @return          void

  @param[in]       fYPosCenterBracket : y-position of the center of the trace brackets  [full range float32]

  @param[in]       *pScaleBracket : Factor for scaling the trace brackets' width (for left and right side);
                                    pointer to LA_t_ScaleBracketOutput defined in la_corridor_crit.h
                      pScaleBracket->fScaleBracketLeft     [full range float32]
                      pScaleBracket->fScaleBracketRight    [full range float32]



  @param[in,out]   *pTrackWidthLeft : width of the trace brackets for the left side (are scaled here)    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
  @param[in,out]   *pTrackWidthRight : width of the trace brackets for the right side (are scaled here)  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c-switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
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

  @created         05.07.2011
  @changed         12/30/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
void LA_v_RelTraSetTrackWidthScale(const float32 fYPosCenterBracket, float32 *pTrackWidthLeft, float32 *pTrackWidthRight, 
                                            const LA_t_ScaleBracketOutput *pScaleBracket)
{
  float32 fTrackWidthRightCenter, fTrackWidthLeftCenter, f_ABS_TrackWidthRightCenter, f_ABS_TrackWidthLeftCenter ;
  float32 fTrackWidthRightScale, fTrackWidthLeftScale;
  float32 fBrackedWidth;
  float32 fABS_pTrackWidthRight, fABS_pTrackWidthLeft;	/* For calculating ABS value */

  fABS_pTrackWidthRight = fABS(*pTrackWidthRight);
  fABS_pTrackWidthLeft  = fABS(*pTrackWidthLeft);
  /*Adjusting the trace brackets only if the TrackWidth (pTrackWidthRight,pTrackWidthLeft) and 
    the ratio for moving the center (BracketPositionLeft, BracketPositionRight) were already determined */
  if ( (pScaleBracket->fScaleBracketLeft < LA_BRACKETPOS_VALID_VAL_COMPARE) && 
    (pScaleBracket->fScaleBracketRight < LA_BRACKETPOS_VALID_VAL_COMPARE) &&
    (fABS_pTrackWidthRight < LA_BRACKETPOS_VALID_VAL_COMPARE) &&
    (fABS_pTrackWidthLeft  < LA_BRACKETPOS_VALID_VAL_COMPARE) &&
    ((pScaleBracket->fScaleBracketLeft > C_F32_DELTA) || (pScaleBracket->fScaleBracketRight > C_F32_DELTA)))
  {

    /* Moving the center of the trace bracket to y = 0*/
    fTrackWidthRightCenter = (*pTrackWidthRight) - fYPosCenterBracket;
    fTrackWidthLeftCenter = (*pTrackWidthLeft) - fYPosCenterBracket;

    /* Adjusting the trace brackets according to factor and moving to former lateral position */
    fBrackedWidth = fABS(fTrackWidthRightCenter) + fABS(fTrackWidthLeftCenter);
    /* If the left trace bracket is longer */
    f_ABS_TrackWidthRightCenter = fABS(fTrackWidthRightCenter);
    f_ABS_TrackWidthLeftCenter = fABS(fTrackWidthLeftCenter);
    if(f_ABS_TrackWidthRightCenter <= f_ABS_TrackWidthLeftCenter)
    {
      fTrackWidthRightScale = (fTrackWidthRightCenter * pScaleBracket->fScaleBracketRight) + fYPosCenterBracket;
      fTrackWidthLeftScale = (fBrackedWidth - fABS(fTrackWidthRightCenter * pScaleBracket->fScaleBracketRight)) + fYPosCenterBracket;
    }
    else /* If the right trace bracket is longer */
    {
      fTrackWidthLeftScale = (fTrackWidthLeftCenter * pScaleBracket->fScaleBracketLeft) + fYPosCenterBracket;
      fTrackWidthRightScale = -(fBrackedWidth - fABS(fTrackWidthLeftCenter * pScaleBracket->fScaleBracketLeft)) + fYPosCenterBracket;
    } 

    /* Setting the new trace brackets to variable */
    *pTrackWidthRight = fTrackWidthRightScale;
    *pTrackWidthLeft  = fTrackWidthLeftScale;
  }
}


/*************************************************************************************************************************
  Functionname:    LA_t_AdaptRatioEgoPosInLaneCamToObj                                                                 */ /*!

  @brief           Adapt the factors for scaling the trace brackets for each single object

  @description     Reduce moving the trace brackets based on the longitudinal distance to the object 
                   (only if trace bracks are adapted in case of no lane change, i.e. StateScaleBracket = SLATE_NO_LANE_CHANGE); 
                   between a threshold value and the maximum pick up distance, the factors are ramped to 1
                   This function should ideally be in si_corridor_cam.c but avoid the STLIN error, it is retained here.

		@startuml
		Start
		Partition LA_t_AdaptRatioEgoPosInLaneCamToObj {
		If (in case of no lane change) then (yes)
			If ((Scale Bracket Left > Scale Bracket Right and no lanes in left side) or (Scale Bracket Right > Scale Bracket Left and no lanes in right side)) then (yes)
				: Do Nothing;
			Else (no) 
				If (if the longitudinal distance to the object is higher than LA_TB_ADAPT_FACTOR_LONG_DIST) then (yes)
					: Update maximum longitudinal distance;
					If (Object Longitudinal Displacement < maximum longitudinal distance) then (yes)
						If ((maximum longitudinal distance - LA_TB_ADAPT_FACTOR_LONG_DIST) > 0) then (yes)
							: Calculate ratio;
							: Calculate Scale Bracket Left and Scale Bracket Right;
						Endif
					Else (no)
						: Set Scale Bracket Left and Scale Bracket Right as 1;
					Endif
				Endif
			Endif
		Endif
		}
		End
		@enduml

  @return          LA_t_ScaleBracketOutput : Struct to describe the lane change for the trace bracket adaption based on the ego position in lane

  @param[in]       *pObjInput : object properties; Pointer to LA_t_RelTraObjInput defined in la_corridor_crit.h
                      pObjInput->iObjNr                  [type ObjNumber_t defined in Rte_type.h]  [0u   39u]

  @param[in]       ScaleBracketIn : factors for scaling the trace brackets and info about the reason for scaling the trace brackets (state);
                                    LA_t_ScaleBracketOutput defined in la_corridor_crit.h
                      ScaleBracketIn.fScaleBracketLeft   [full range float32]
                      ScaleBracketIn.fScaleBracketRight  [full range float32]
                      ScaleBracketIn.StateScaleBracket   [SIScaleBracketState_t defined in la_corridor_crit.h]

  @param[in]       pEnvironment : data about number of lane; LA_t_AssTraEnvironment defined in la_corridor_crit.h
                      pEnvironment->iNumberLanesLeft     [Full range sint32]
                      pEnvironment->iNumberLanesRight    [Full range sint32]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (   )           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                   pt_LAOutput->f_LAMovingObjBasePickUpRange
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Adapt trace brackets in case of lane change
  @c-switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Adapt trace brackets in case of no lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Adapt trace brackets when blinkers are on
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
  @changed         12/16/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
LA_t_ScaleBracketOutput LA_t_AdaptRatioEgoPosInLaneCamToObj(LA_t_RelTraObjInput const *pObjInput, LA_t_ScaleBracketOutput const ScaleBracketIn, LA_t_AssTraEnvironment const * pEnvironment)
{
  float32 fXMax, fRatio;
  LA_t_ScaleBracketOutput ScaleBracketOut;

  ScaleBracketOut.fScaleBracketLeft = ScaleBracketIn.fScaleBracketLeft;
  ScaleBracketOut.fScaleBracketRight = ScaleBracketIn.fScaleBracketRight;
  ScaleBracketOut.StateScaleBracket = ScaleBracketIn.StateScaleBracket;

  /*! Reduce the amount of moving the trace brackets only in case of no lane change */
  if( (ScaleBracketIn.fScaleBracketLeft < LA_BRACKETPOS_VALID_VAL_COMPARE) && 
      (ScaleBracketIn.fScaleBracketRight < LA_BRACKETPOS_VALID_VAL_COMPARE) &&
      (ScaleBracketIn.StateScaleBracket == SLATE_NO_LANE_CHANGE)
    )
  {
    /*! Don't reduce the amount of moving the trace brackets if there is no other lane in the direction of moving the trace brackets, 
    hence, the risk of a drop-in is very small and the drop-out/pick-up performance increases */
    if ( ((ScaleBracketIn.fScaleBracketLeft > ScaleBracketIn.fScaleBracketRight) && (pEnvironment->iNumberLanesLeft <= 0)) ||
         ((ScaleBracketIn.fScaleBracketRight > ScaleBracketIn.fScaleBracketLeft) && (pEnvironment->iNumberLanesRight <= 0))
       )
    {
      /*! nothing */
    }
    else
    {
      /*! Reduce the amount of moving the trace brackets only if the longitudinal distance to the object 
      is higher than LA_TB_ADAPT_FACTOR_LONG_DIST */
      const float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr);
      if (f_ObjLongDisp > LA_TB_ADAPT_FACTOR_LONG_DIST)
      {
        /* Above the maximum longitudinal distance, the trace brackets are not moved at all (factor is 1); 
        the maximum longitudinal distance equals the BMW bick-up distance (2.2s * V_EGO + 40m) */
        fXMax = pt_LAOutput->f_LAMovingObjBasePickUpRange;
        if (f_ObjLongDisp < fXMax)
        {
          if ((fXMax - LA_TB_ADAPT_FACTOR_LONG_DIST) > 0.f)
          {
            fRatio = (*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr) - LA_TB_ADAPT_FACTOR_LONG_DIST)/(fXMax - LA_TB_ADAPT_FACTOR_LONG_DIST);

            ScaleBracketOut.fScaleBracketLeft += fRatio * (1.f - ScaleBracketIn.fScaleBracketLeft);
            ScaleBracketOut.fScaleBracketRight += fRatio * (1.f - ScaleBracketIn.fScaleBracketRight);
          }
        }
        else
        {
          ScaleBracketOut.fScaleBracketLeft = 1.f;
          ScaleBracketOut.fScaleBracketRight = 1.f;
        }
      }
    }
  }

  return ScaleBracketOut;
}

#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */


#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)

/*************************************************************************************************************************
  Functionname:    LA_v_ExecuteCameraCorrFuntions                                                                   */ /*!

  @brief           Execute si corridor functions based on camera information

  @description     Execute si corridor functions based on camera information

		@startuml
		Start
		Partition LA_v_ExecuteCameraCorrFuntions {
		Partition LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION {
			If (Check if the extension of brackets is enabled for improved camera lane object association) then (yes)
				: Set Trace bracket extension based on camera lane object association;
			Endif
		}
		}
		End
		@enduml

  @return          void

  @param[in]       pObjectProperties : object properties; Pointer to LA_t_RelTraObjInput defined in la_corridor_crit.h

  @param[in,out]   pBracketFuncResults : trace bracket results, information about all corridor criteria; Pointer to LA_t_CriteriaMatrix defined in la_corridor_crit.h
                      pBracketFuncResults->BaseCorridor                          [LA_t_BracketOutput defined in la_corridor_crit.h]

  @param[in]       pBracketFuncEnableFlags : enable flags for trace bracket criteria; Pointer to LA_t_BracketFuncEnable defined in la_corridor_crit.h
                      pBracketFuncEnableFlags->bEnableExtensionCamLaneObjAssoc   [boolean defined in Platform_Types.h] [TRUE,FALSE]
                      pBracketFuncResults->ExtensionCamLaneObjAssoc              [LA_t_BracketOutput defined in la_corridor_crit.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : Configuration switch, which enables corridor extension based on camera lane object association

  @c_switch_full   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : Configuration switch, which enables corridor extension based on camera lane object association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION        : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING        : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE      : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/16/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
void LA_v_ExecuteCameraCorrFuntions(LA_t_RelTraObjInput const * pObjectProperties, LA_t_CriteriaMatrix * pBracketFuncResults, LA_t_BracketFuncEnable const * pBracketFuncEnableFlags)
{
  /*! Trace bracket extension based on camera lane object association */
#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
  if(pBracketFuncEnableFlags->bEnableExtensionCamLaneObjAssoc != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionCamLaneObjAssoc(pObjectProperties, &(pBracketFuncResults->BaseCorridor), &(pBracketFuncResults->ExtensionCamLaneObjAssoc));
  }
#endif
}
#endif

#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionCamLaneObjAssoc                                                                 */ /*!

  @brief           Trace bracket extension based on camera lane object association

  @description     Trace bracket extension based on camera lane object association

		@startuml
		Start
		Partition LA_v_RelTraExtensionCamLaneObjAssoc {
		Partition FCT_CFG_CAMERA_OBJECT_DETECTION {
		: Get the object lane association based on the camera;
		Partition SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA {
		: Set Object Overlap Detected to Right and left as False;
		: Set Camera Object data;
		: Get Information about the detected camera lane markers;
		}
		}
		If (Check if Object is not relevant) then (yes)
			: Calculate Maximum Ego Velocity Camera Lane;
		Endif
		If (Check if Objects are stationary or if the car is driving much slower) then (yes)
			If (If Object is relevant) then (yes)
				: Set Extension as LA_EXT_TRACK_CAM_LANE_OBJ_ASSOC_EXT;
			Else (no)
				: Set Extension as LA_EXT_SEEK_CAM_LANE_OBJ_ASSOC_EXT;
			Endif
			If (if object is associated to the ego lane based on the camera) then (yes)
				: Increase the base corridor width (Left and Right Bracket);
			Endif
		Endif
		Partition #LightBlue "** if SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA && FCT_CFG_CAMERA_OBJECT_DETECTION **" {
		If (Assigned Lane Quality > 0 and Association Lane Right Quality > 0) then (yes)
			: Update Lane Overlap to right;
			: Update Bracket Extension with LA_EXT_CAM_LANE_OBJ_ASSOC_NEAR_EXT;
		Else if (Assigned Lane Quality > 0 and Association Lane Left Quality > 0) then (yes)
			: Update Lane Overlap to left;
			: Update Bracket Extension with LA_EXT_CAM_LANE_OBJ_ASSOC_NEAR_EXT;
		Else (no)
			: Do Nothing;
		Endif
		: Update Ego Velocity Object Sync and Object Longitudinal Displacement;
		If (Object Longitudinal relevant Velocity > LA_MAX_VREL_CAM_LANE_OBJ_USE_OVERLAP and Ego Velocity Object Sync <= Max Ego Velocity Camera Lane Near and Object Longitudinal Displacement <= Max Distance Camera Lane Near) then (yes)
			If (if Overlap Detected to Right) then (yes)
				: Extend Bracket for Overlap to Right;
			Else if (if Overlap Detected to Left) then (yes)
				: Extend Bracket for Overlap to Left;
			Else (no)
				: Do Nothing;
			Endif
		Endif
		}
		}
		End
		@enduml

  @return          static void

  @param[in]       pObjInput : object properties; Pointer to LA_t_RelTraObjInput defined in la_corridor_crit.h
                      pObjInput->ucDynamicProperty         [SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
                      pObjInput->iObjNr                    [ObjNumber_t defined in Rte_type.h] [0u   39u]
                      pObjInput->iRelevant                 [ubit8_t defined in algo_type.h] [TRUE,FALSE]

  @param[in]       pBracketBase : base trace bracket information; Pointer to LA_t_BracketOutput defined in la_corridor_crit.h
                      pBracketBase->BracketPositionLeft    [full range float32]
                      pBracketBase->BracketPositionRight   [full range float32]

  @param[out]      pBracketOut : resulting trace brackets based on camera lane object association; Pointer to LA_t_BracketOutput defined in la_corridor_crit.h
                      pBracketOut->BracketPositionLeft     [full range float32]
                      pBracketOut->BracketPositionRight    [full range float32]

  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(   )         [-330f   330f]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync       [-330f   330f]

  @glob_out        -

  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION     : FCT camera object/lane detection inputs

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION        : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING        : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE      : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : Configuration switch, which enables corridor extension based on camera lane object association

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         04/25/2018

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void LA_v_RelTraExtensionCamLaneObjAssoc(LA_t_RelTraObjInput const * pObjInput, LA_t_BracketOutput const * pBracketBase, LA_t_BracketOutput * pBracketOut)
{
  float32 f_Extension;
  float32 fObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(pObjInput->iObjNr);
#if(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)
#if(FCT_CFG_CAMERA_OBJECT_DETECTION)
  float32 fEgoVelObjSync;
  float32 fObjLongDisp;
#endif
#endif
  /*! Get the object lane association based on the camera: only valid in case of the camera object interface */
#if(FCT_CFG_CAMERA_OBJECT_DETECTION)
  const boolean b_CamLaneObjAssocEgo = LA_b_CheckCameraObjAssoToEgoLane(pObjInput->iObjNr);

#if(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)
  float32 f_MaxEgoVelCamLaneNear, f_MaxDistCamLaneNear, f_EgoWidth, f_VehicleWidth,f_MaxEgoVelCamLane;
  boolean b_Overlap_Detected_Right = FALSE;
  boolean b_Overlap_Detected_Left  = FALSE;
  percentage_t t_AssignedLaneQual = pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].t_CamObjectData.t_AssignedLaneQual;
  percentage_t t_AssLaneLeftQual  = pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].t_CamObjectData.t_AssLaneLeftQual;
  percentage_t t_AssLaneRightQual = pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].t_CamObjectData.t_AssLaneRightQual;

  const float32 f_LeftMarkerDist  = FCTSEN_pCamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist;
  const float32 f_RightMarkerDist = FCTSEN_pCamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;
#endif 

#else
  const boolean b_CamLaneObjAssocEgo = FALSE;
#endif

#if(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)
     /* Set/Init Parameter */
   f_MaxEgoVelCamLane = LA_MAX_EGO_VEL_CAM_LANE_OBJ_ASSOC_EXT;
   f_Extension = 0.f;
#if(FCT_CFG_CAMERA_OBJECT_DETECTION)
   f_MaxEgoVelCamLaneNear = LA_MAX_EGO_VEL_CAM_LANE_NEAR_RANGE;
   f_MaxDistCamLaneNear = LA_MAX_OBJ_DIST_CAM_LANE_NEAR_RANGE;
   f_EgoWidth = EGO_VEHICLE_WIDTH; /* [m] */
   f_VehicleWidth = pt_LAInput->pt_FIPOA->t_ObjList[pObjInput->iObjNr].f_ObjectWidthCorridor;
#endif
  
  /* For non relevant objects Extend Max Ego velocity for Camera lane association speed  */
   if (pObjInput->iRelevant == FALSE)
   {
      f_MaxEgoVelCamLane +=  LA_MAX_EGO_VEL_CAM_LANE_NON_REL_OBJ_ADD;
   }
#endif

  /*! For stationary objects or if the car is driving much slower -> evtl. Ego vel auf stadtverkehr einschränken, magic numbers weg */
   if( ( (pObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      || (pObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
       ) || 
       ( (fObjVrelX < LA_MAX_VREL_CAM_LANE_OBJ_ASSOC_EXT) && 
#if(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)
       (*pt_LAInput->t_RTE.pf_EgoVelObjSync  < f_MaxEgoVelCamLane ) 
#else
       (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_MAX_EGO_VEL_CAM_LANE_OBJ_ASSOC_EXT) 
#endif
       )
     )
  {
    /*! Use different extensions for relevant and non_relevant objects */
    if (pObjInput->iRelevant == TRUE)
    {
      f_Extension = LA_EXT_TRACK_CAM_LANE_OBJ_ASSOC_EXT;
    }
    else
    {
      f_Extension = LA_EXT_SEEK_CAM_LANE_OBJ_ASSOC_EXT;
    }

    /*! Apply extension only if object is associated to the ego lane based on the camera; increase the base corridor width */
    if (b_CamLaneObjAssocEgo == TRUE)
    {
      pBracketOut->BracketPositionLeft = pBracketBase->BracketPositionLeft + f_Extension;
      pBracketOut->BracketPositionRight = pBracketBase->BracketPositionRight - f_Extension;
    }
  }

 #if(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)
 #if(FCT_CFG_CAMERA_OBJECT_DETECTION)
/********************************************************************************************************/
/* Calculate Overlap based on camera information ego dist to lane marker and overlap object on ego lane */
/********************************************************************************************************/

   if((t_AssignedLaneQual > (percentage_t)0) && (t_AssLaneRightQual > (percentage_t)0))
   {
     /* Overlap Right */
     b_Overlap_Detected_Right = (boolean)(((float32)t_AssignedLaneQual*f_VehicleWidth/100.f) > (fABS(f_RightMarkerDist)-0.5*f_EgoWidth));
     f_Extension = LA_EXT_CAM_LANE_OBJ_ASSOC_NEAR_EXT;
   }
   else if ((t_AssignedLaneQual > (percentage_t)0) && (t_AssLaneLeftQual > (percentage_t)0))
   {
     /* Overlap Left */
     b_Overlap_Detected_Left = (boolean)(((float32)t_AssignedLaneQual*f_VehicleWidth/100.f) > (fABS(f_LeftMarkerDist)-0.5*f_EgoWidth));
     f_Extension = LA_EXT_CAM_LANE_OBJ_ASSOC_NEAR_EXT;
   }
   else
   {
      /* dummy else to keep QAC happy */
   }

/*************************************/
/* Bracket Extension for Overlapping */
/*************************************/
   fEgoVelObjSync = (*(pt_LAInput->t_RTE.pf_EgoVelObjSync));
   fObjLongDisp = (*pt_LAInput->t_RTE.pf_ObjLongDisp(pObjInput->iObjNr));

  if ((fObjVrelX > LA_MAX_VREL_CAM_LANE_OBJ_USE_OVERLAP)
            &&
            (fEgoVelObjSync <= f_MaxEgoVelCamLaneNear)
            &&
            ( (fObjLongDisp <= f_MaxDistCamLaneNear))
          )
  {
      if (b_Overlap_Detected_Right)
      {
        /* Extend for Overlap Right */
        pBracketOut->BracketPositionRight = pBracketBase->BracketPositionRight - f_Extension;
      }
      else if (b_Overlap_Detected_Left)
      {
        /* Extend for Overlap Left */
        pBracketOut->BracketPositionLeft = pBracketBase->BracketPositionLeft + f_Extension;
      }
	  else
	  {
         /* dummy else to keep QAC happy */
      }
  }
#endif /*(FCT_CFG_CAMERA_OBJECT_DETECTION)*/
#endif /*(SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA)*/
}
#endif

/** @} end defgroup */
#endif /*!< (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) */
#endif /*!< #if(FCT_CFG_ACC_LANE_ASSOCIATION) */
