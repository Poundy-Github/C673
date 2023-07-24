/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_laneassociation.c

DESCRIPTION:               This is the main file for implementation of object association to ego lane/adjacent lanes.

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             

VERSION:                   $Revision: 1.69 $

LEGACY VERSION:            Revision: 2.2
  
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_laneassociation Lane association
@ingroup la
@brief         This is the main file for implementation of object association to ego lane/adjacent lanes. \n\n

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
//PRQA S 0791 MACRO_IDENTIFIER_LENGTH
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Macro identifier does not differ from other macro identifier within the specified number of significant characters,Does not affect functionality*/

#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
#define LA_OBJ_DIST_TO_ROADBORDER_ROAD_TRACK_MIN      (5u)    /*<! Minimal tracking status for the Road Estimation to be considered */
#define LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN       (60.f)   /*<! Minimal confidence for the Road Estimation to be considered */
#define LA_OBJ_DIST_TO_ROADBORDER_STAT_MIN            (100u)  /*<! Minimum for road border stat left/right to compute object distance to road border */
#define LA_OBJ_DIST_TO_ROADBORDER_DIST_LOW            (70.F)  /*<! Distance up to which computation based on distance to trajectory is used */
#define LA_OBJ_DIST_TO_ROADBORDER_DIST_HIGH           (100.F) /*<! Distance up to which computation based on road estimation is used */
#define LA_OBJ_DIST_TO_ROADBORDER_DEFAULT             (999.F) /*<! Default distance of object to road border */
#endif
#if (LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS)
SET_MEMSEC_CONST(NearDistVelocityFactor)
static const GDBLFunction_t NearDistVelocityFactor = {
  LA_WIDE_NEAR_TRACK_FACTOR_MAX,
  LA_WIDE_NEAR_TRACK_FACTOR_MIN,
  ( ( LA_WIDE_NEAR_TRACK_FACTOR_MIN - LA_WIDE_NEAR_TRACK_FACTOR_MAX ) / ( LA_EGO_SPEED_MAX_FOR_WIDE_NEAR_TRACK - LA_EGO_SPEED_MIN_FOR_WIDE_NEAR_TRACK ) ),
  LA_WIDE_NEAR_TRACK_FACTOR_MAX - ( (( LA_WIDE_NEAR_TRACK_FACTOR_MIN - LA_WIDE_NEAR_TRACK_FACTOR_MAX ) / ( LA_EGO_SPEED_MAX_FOR_WIDE_NEAR_TRACK - LA_EGO_SPEED_MIN_FOR_WIDE_NEAR_TRACK ) ) * LA_EGO_SPEED_MIN_FOR_WIDE_NEAR_TRACK)
};
#endif
#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
SET_MEMSEC_CONST(LA_NarrowHighwayVrelBasedDistThres)
  static const GDBLFunction_t LA_NarrowHighwayVrelBasedDistThres = // PRQA S 3218
  /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
{
  LA_NARROW_HIGHWAY_VREL_MIN_DISTX,
  LA_NARROW_HIGHWAY_VREL_MAX_DISTX,
  ( ( LA_NARROW_HIGHWAY_VREL_MAX_DISTX - LA_NARROW_HIGHWAY_VREL_MIN_DISTX ) / ( LA_NARROW_HIGHWAY_VREL_MAX - LA_NARROW_HIGHWAY_VREL_MIN ) ),
  LA_NARROW_HIGHWAY_VREL_MIN_DISTX - ( (( LA_NARROW_HIGHWAY_VREL_MAX_DISTX - LA_NARROW_HIGHWAY_VREL_MIN_DISTX ) / ( LA_NARROW_HIGHWAY_VREL_MAX - LA_NARROW_HIGHWAY_VREL_MIN ) ) * LA_NARROW_HIGHWAY_VREL_MIN)
};
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
static const LA_t_FindObjInAreaArgs LA_OvertakingCheckArgs = // PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (LA_OVERTAKING_OBJ_DELTAX_LOWER),
  (LA_OVERTAKING_OBJ_DELTAX_UPPER),
  (LA_OVERTAKING_OBJ_DELTAY_LOWER),
  (LA_OVERTAKING_OBJ_DELTAY_UPPER),
  (LA_OVERTAKING_OBJ_DELTAV_LOWER),
  (LA_OVERTAKING_OBJ_DELTAV_UPPER)
};
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
static const LA_t_FindObjInAreaArgs LA_OvertakingCheckArgsLeftHandTraffic = // PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (LA_OVERTAKING_OBJ_DELTAX_LOWER),
  (LA_OVERTAKING_OBJ_DELTAX_UPPER),
  (-LA_OVERTAKING_OBJ_DELTAY_UPPER),
  (-LA_OVERTAKING_OBJ_DELTAY_LOWER),
  (LA_OVERTAKING_OBJ_DELTAV_LOWER),
  (LA_OVERTAKING_OBJ_DELTAV_UPPER)
};
#endif

#if ( (LA_CFG_NARROW_HIGHWAY_CRITERIA) || (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) )
static const LA_t_FindObjInAreaArgs LAMirrorObjArgs = // PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (LA_MIRROR_OBJ_DELTAX_LOWER),
  (LA_MIRROR_OBJ_DELTAX_UPPER),
  (LA_MIRROR_OBJ_DELTAY_LOWER),
  (LA_MIRROR_OBJ_DELTAY_UPPER),
  (LA_MIRROR_OBJ_DELTAV_LOWER),
  (LA_MIRROR_OBJ_DELTAV_UPPER)
};
#endif

/*Class confidence below which in-out tranisition time is maxed out to reduce dropins of ghost / irrelevant objects*/
#define LA_MIN_INOUT_CLASS_CONFIDENCE   (55u)

#define LA_IN2OUTLANE_MAX_TRANSITIONTIME                    (42u)     /*!< 42 cycles, that means about three seconds */
/*! Parameters to determine when a stationary object is not selected as OOI
    since it is an oncoming and stopped object */

#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
#define LA_MAX_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT          (10.f)    /*!< Maximum longitudinal distance, before which cut ins have to be treated more carefully */
#define LA_MIN_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT          (1.5f)    /*!< Maximum longitudinal distance, before which cut ins have to be treated more carefully. The value represents 0.33*Car_Length */
#define LA_MIN_TRUCK_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT    (4.f)     /*!< Maximum longitudinal distance, before which cut ins have to be treated more carefully */
#define LA_MAX_SHORTRANGE_CUT_IN_LAT_DISPLACEMENT           (2.0f)    /*!< Maximum lateral distance, before which cut ins have to be treated more carefully */
#define LA_MAX_CURVATURE_CUT_IN_LAT_DISPLACEMENT            (1.f/150.f)   /*!< Maximum curvature of the trajectory above which reduced Object distance to trajectory is used for overlap computation */
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*Maximum lane-change probability assumed in a non lane-change scenario*/
#define LA_MIN_PROB_LANE_CHANGE   (35u)
/*Minimum dynamic confidence required for stationary-object related changes*/
#define LA_MIN_DYN_CONFIDENCE     (90u)
#endif

#if (LA_CFG_CAM_PARKING_DETECTED) 
#define LA_MAX_LONG_OBJECT_GAP_SIZE         (15.f)    /*!< Maximum longitudinal distance between two stationary cars */
#define LA_MAX_LAT_OBJECT_GAP_SIZE          (1.8f)    /*!< Maximum lateral distance between two stationary cars */
#define LA_MIN_OBJ_DIST_PARKING_ROW         (10.f)     /*!< Minimum longitudinal distance to identify parking cars */
#define MAX_CITY_SPEED_THRESH               (65.f/C_KMH_MS)
#endif /* end of LA_CFG_CAM_PARKING_DETECTED */
/* PRQA L:MACRO_IDENTIFIER_LENGTH*/
/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION
*****************************************************************************/

static void LA_b_FusedLaneAssociation(const ObjNumber_t iObj);
/* PRQA S 2200 1 *//* Date: 2020-04-02, Reviewer:Gireesh , Reason:This warning is suppressed as Indentation does not have any critical impact the functionality. */
static eAssociatedLane_t  LA_t_GetAssociateLane(const ObjNumber_t ObjId);
static eAssociatedLane_t  LA_t_GetObjSelectionLane(const ObjNumber_t ObjId, const eAssociatedLane_t eBaseAssocLane);
#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
static void LA_v_CalculateOrientationEffect(const ObjNumber_t iObj, LADistanceWidth_t *pDistanceWidth);
#endif /* LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS */
#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
static float32      LA_f_ComputeObjDistToRoadBorder(const ObjNumber_t ObjNr);
static void         LA_v_UpdateClusterVarianceLevel(void);
static void         LA_v_RoadSideParkedObjDetection(void);
#endif /* END IF (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) */

#if (LA_CFG_ADD_CHECK_INLANE_TRANSITION)
static boolean      LA_b_CheckObjInlaneAllowed(const ObjNumber_t iObj);
#endif


/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/


// PRQA S 7013 STTLN_EXCEEDED
/* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Number of lines exceeded per file, not safety critical */
/*************************************************************************************************************************
  Functionname:    LA_v_LaneAssociation                                                                                */ /*!

  @brief           Calculates the associated lane for each objects.

  @description     Calculates and assigns the associated lane for each object based on the parameters like
                   lane width, borders, overlap with borders, etc.,
                   @startuml
                   partition LA_v_LaneAssociation {
                   Start
                   partition LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES {
                    - call LA_v_UpdateClusterVarianceLevelforObstacles function
                   }
                   
                   partition LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION {
                   :Update object specific cluster variance level
                      <b>LA_v_UpdateClusterVarianceLevel</b>;
                   }
                   
                   partition LA_CFG_ENABLE_PARKED_DETECTION {
                    - call LA_v_RoadSideParkedObjDetection function
                   }
                   
                   partition LA_CFG_RESTRICTION_EGO_LANE_CHANGE {
                    - call LA_v__FilterTurnIndicator function
                   }
                   
                   :Calculate the corridor width for the actual object, including criteria for corridor expansion and restriction
                      <b>LA_v_Calculate_ACC_Corridor</b>;
                      
                    partition LA_CFG_TRAJ_DYNAMISM_DETECTION {
                    - call LA_v_DetectTrajDynamism function
                   }
                   repeat
                      if (object is not deleted) then(TRUE)
                        partition LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS {
                          if(ego velocity is less than LA EGO SPEED MAX FOR WIDE NEAR TRACK and object longitudinal distance is less than LA MAX DIST FOR FOR WIDE NEAR TRACK and object is moving ) then (yes)
                   	     if(Object is not in ego lane) then (yes)
                   		   -In traffic jam situations, most objects, especially neigbour objects are classified as point objetcts.Therefore, in these situations  speed is less than 25 kph and objects nearer than 15 m lane width and object width are forced to grow to 3.75m vice versa 1.8m. This leads to a better pick up of objects cutting in from adjacent lanes in those situations. Do this only for moving or stopped objects not for stationaries
                   		 endif
                   	   endif	 
                        }
                   	 partition LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS {
                         if(Use orientation for overlap and occupancy computation ONLY if object is already OOI in previous cycle AND
                         1. Longitudinal distance of the object is in between 1.5m and 10m to EGO
                         <b>LA MAX SHORTRANGE CUT IN LONG DISPLACEMENT</b>
                         <b>LA MIN SHORTRANGE CUT IN LONG DISPLACEMENT</b>
                        2. Lateral distance of the object (with corridor center as reference) is < 2.0m to EGO
                        <b>LA MAX SHORTRANGE CUT IN LAT DISPLACEMENT</b>
                        3. Object is not Hidden OOI, i.e., only objects on adjacent lanes and 
                        4. Object is not stationary or stopped but it is moving and not oncoming!
                        <b>SLATE_OBJECT_PROPERTY_MOVING</b>)
                        :Calculates the projection of the object onto EGO lane taking into account the orientation of the object
                        <b>LA_v_CalculateOrientationEffect</b>;
                  	  endif
                  	  }
                       :Distance to Trajectory based geometric lane association
                       <b>LA_v_GeometricLaneAssoc</b>
                     
                       :Check customer specific inlane/outlane criteria
                       <b>LA_v_PredLaneAssoc</b>
                       
                       
                       
                       :Check if object is associated to ego lane based on the camera information
                       <b>LA_b_CheckCameraObjAssoToEgoLane</b>;
                       
                       :Fuse laneassociation
                       <b>LA_b_FusedLaneAssociation</b>;
                  
                       :Get associated lane of object
                       (without any quality considerations)
                       <b>LA_t_GetAssociateLane</b>;
                       
                       :Calculate associated lane used for OOI selection
                       (taking quality into account)
                       <b>LA_t_GetObjSelectionLane</b>;
                     else (FALSE)
                     :reset information;
                     :Default init deleted objects lane to unknown;
                     :Default init functional lane to unknown;
                     endif
                     :Assign a lane for the external interface without taking object quality into account;
                     :Write the lane used for object selection taking object quality into account to the external interface;
                  repeat while (do for all objects\n<b>EM_N_OBJECTS</b>)
                  Stop
                  }
                  @enduml


  @return          void

  @param[in]       -

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY            [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral displacement of an object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving [TRUE, FALSE]
  @glob_in         t_OOI_ObjectList[i].t_Bool.AlreadyOOI : Boolean if object i is already in OOI list [TRUE, FALSE]
  @glob_in         pt_LAInput->t_RTE.pf_ObjOrientation(i) : Orientation of the object i [-PI ... PI]
  @glob_in         pt_LAInput->t_RTE.pf_ObjOrientationStd(i) : Standard deviation of the orientation of the object i [0 ... PI]
  @glob_in         SLATE_b_GetObjIsDeleted(i) : Information if object i is deleted [TRUE, FALSE]
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX(i) : get object number of object of interest [0 ... EM_N_OBJECTS[
                   with i in [0 ... OOI_NUMBER_OF_OOI[ as defined in aiOOIList_array_t in Rte_Type.h and ooi_ext.h
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.In2OutlaneTransition : Outlane timer of object i  [0 ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane or not (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAActLaneState : State if object i in inlane or not (without timer and distance criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [full range of data type float]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjAssociatedLane : associated lane information of an object i [eAssociatedLane_t as in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjFuncLane : functional lane association of an object i [eAssociatedLane_t as in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].TrajDist.TrajDistMeas.Y.f0 : orthogonal distance to ACC trajectory [full range of float32]

  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjTrajDistWidth : projection of the object onto EGO lane taking into account the orientation of the object 
                   [CPDistanceWidth_t as defined in la_ext.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLCamValue : information if inlane camera satisfied [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.fCorridorRelevantTime : the relevant object has been seen inlane [full range of data type float]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : Lane assignment (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.Outlane timer of object i  [0 ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.Inlap_In2OutlaneCounter : Inlane to outlane transition counter for outlane decision of objects [full range of uint8]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjAssociatedLane : assigned lane of an object i without taking object quality into account [eAssociatedLane_t as in Rte_Type.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjFuncLane : functional lane association of an object i [eAssociatedLane_t as in Rte_Type.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc : Camera trajectory based lane association of an object i [0      3]
  
  @c_switch_part   LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS : Configuration switch to enable old wide near range track
  @c_switch_part   LA_CFG_TURN_INDICATOR_COUNTER  : Configuration Switch Enable Counter for Ego lane change indicator
  @c_switch_part   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Config switch to enable use of cluster variance in lane association
  @c_switch_part   SIT_CFG_OBJECT_SCORING : Configuration switch to enable object scoring module
  @c_switch_part   LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS : Configuration switch allowing the use of object orientation angle(OOA) in
                   inlap calculations for objects that are in NEAR region
  @c_switch_part   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE : Configuration switch to enable multi object analyze as one input for the cutin potential
  @c_switch_part   LA_CFG_DELAY_PRED_LANE_ASSOC : Configuration switch to delay the predicted lane association
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ : Configuration switch to check the object lane association with respect to Camera Trajectory
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @author          Norman Apel | norman.apel@continental-corporation.com | +49 (8382) 9699-365
*************************************************************************************************************************/
void LA_v_LaneAssociation(void)
{
  LADistanceWidth_t * pDistWidth;
  LADistanceWidth_t DistWidthArray[EM_N_OBJECTS];
  boolean b_ObjIsDeleted;

#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
  float32 f_ObjLongDisp = 0.f;
  float32 f_TrajDistMeas;
#endif /* LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS */

  ObjNumber_t iObj;
  eAssociatedLane_t eObjAssocLane;  /*!< Lane associated with object (on external interface) */
  eAssociatedLane_t e_ObjFuncLane;    /*!< Functional Lane associated with object for object selection (on external interface) */

#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
  float32 fDistToTrajExt = 0.f;
SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
float32 f_Orientation, f_StdOrientation;
float32 fABS_Orientation;	/* For calculating ABS value */
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  boolean bCamLaneAssoc = FALSE;
#endif /* END IF (FCT_CFG_CAMERA_OBJECT_DETECTION) */

#if (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
  LA_t_ObjCamTrajLanAssocEnum t_CamTrajLaneAssoc = LA_OBJ_CAM_LANE_UNDEFINED;
#endif/* (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */

#if (LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS)
  const fVelocity_t Veigen = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  float32 VelocityRampFactor;
  GDBLFunction_t NearDistWidth;
  GDBLFunction_t NearObjectWidth;
#endif

#if (LA_CFG_TURN_INDICATOR_COUNTER)
  eTurnIndicator_t t_TurnIndicator;
#endif /*end of LA_CFG_TURN_INDICATOR_COUNTER*/

#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
  LA_v_UpdateClusterVarianceLevelforObstacles();
#endif /* LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES */

#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
  LA_v_UpdateClusterVarianceLevel();
#endif /* END IF (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) */
#if (LA_CFG_ENABLE_PARKED_DETECTION)
  LA_v_RoadSideParkedObjDetection();
#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */

#if LA_CFG_TURN_INDICATOR_COUNTER
  t_TurnIndicator = (pSLATE_CustomInput->eTurnIndicator);
  /* turn indicator on/off based on hysteresis*/
  LA_v__FilterTurnIndicator(t_TurnIndicator);
#endif /* end of LA_CFG_TURN_INDICATOR_COUNTER*/

#if (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
   /* Update Camera Trajectory based lane association for all 40 objects */
   for (iObj = (ObjNumber_t)(EM_N_OBJECTS - 1); iObj >= 0; iObj--)
   {
      t_CamTrajLaneAssoc = LA_u_GetObjAssocLaneBasedOnCameraTrajectory(iObj);
      pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc = t_CamTrajLaneAssoc;
   }
#endif /*(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)*/

  /* Calculate the trace brackets */
  LA_v_Calculate_ACC_Corridor(DistWidthArray);
#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
  LA_v_DetectTrajDynamism();
#endif /* LA_CFG_TRAJ_DYNAMISM_DETECTION */

  for (iObj = (ObjNumber_t)(EM_N_OBJECTS - 1); iObj >= 0; iObj--)
  {
    b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(iObj);

    if (b_ObjIsDeleted == FALSE)
    {
      /* calc BORDERS*/
      /* Determines lane width and borders and calls CalculateOverlap using this borders */
      pDistWidth = &DistWidthArray[iObj];

#if (LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS)
      /* Made the below functionality configuration switchable, preferably disabled. Reason: the
      measurements of Task 8820 for which this code was added were restored and re-simulated, and
      showed no benefit from the below special code whatsoever. The code could in theory improve
      pick-ups in traffic jams on highways, however it leads to terrible drop-ins on roads with
      smaller lane-widths (city traffic in particular). */
      if( (Veigen < LA_EGO_SPEED_MAX_FOR_WIDE_NEAR_TRACK )
      &&(*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) < LA_MAX_DIST_FOR_FOR_WIDE__NEAR_TRACK)
      &&((*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_MOVING)
       ||(SLATE_b_GetObjIsMovingToStationary(iObj))))
      {
        if(pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState == OBJ_STATE_OUTLANE)
        {
          /*-----------------------------------------------------------------------------------*/
          /* In traffic jam situations, most objects, especially neigbour objects are classified as point objetcts.
            Therefore, in these situations  ( speed < 25 kph and objects nearer than 15 m lane width and object width are
            forced to grow to 3.75m vice versa 1.8m.
            This leads to a better pick up of objects cutting in from adjacent lanes in those situations.
            Do this only for moving or stopped objects not for stationaries !!!! */
          /*-----------------------------------------------------------------------------------*/
          NearDistWidth.dAmax = pDistWidth->fTrajectoryWidth;
          NearDistWidth.dAmin =LA_WIDE_NEAR_TRACK_WIDTH;
          NearDistWidth.dM = ( ( pDistWidth->fTrajectoryWidth - LA_WIDE_NEAR_TRACK_WIDTH ) / ( LA_MAX_DIST_FOR_FOR_WIDE__NEAR_TRACK - LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK ) );
          NearDistWidth.dB = LA_WIDE_NEAR_TRACK_WIDTH - ( (( pDistWidth->fTrajectoryWidth - LA_WIDE_NEAR_TRACK_WIDTH ) / ( LA_MAX_DIST_FOR_FOR_WIDE__NEAR_TRACK - LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK  ) ) * LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK);

          NearObjectWidth.dAmax = pDistWidth->fObjectWidth;
          NearObjectWidth.dAmin =LA_WIDE_NEAR_OBJECT_WIDTH;
          NearObjectWidth.dM = ( ( pDistWidth->fObjectWidth - LA_WIDE_NEAR_OBJECT_WIDTH ) / ( LA_MAX_DIST_FOR_FOR_WIDE__NEAR_TRACK - LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK ) );
          NearObjectWidth.dB = LA_WIDE_NEAR_OBJECT_WIDTH - ( (( pDistWidth->fObjectWidth - LA_WIDE_NEAR_OBJECT_WIDTH ) / ( LA_MAX_DIST_FOR_FOR_WIDE__NEAR_TRACK - LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK  ) ) * LA_MIN_DIST_FOR_FOR_WIDE__NEAR_TRACK);

          VelocityRampFactor = dGDBmathLineareFunktion(&NearDistVelocityFactor,Veigen);
        pDistWidth->fTrajectoryWidth = (VelocityRampFactor * (dGDBmathLineareFunktion(&NearDistWidth,*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj))-pDistWidth->fTrajectoryWidth))
                                        + pDistWidth->fTrajectoryWidth;
        pDistWidth->fObjectWidth = (VelocityRampFactor * (dGDBmathLineareFunktion(&NearObjectWidth,*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj))-pDistWidth->fObjectWidth))
                                        + pDistWidth->fObjectWidth;
          /*-----------------------------------------------------------------------------------*/
        }
      }
#endif  /* LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS */

#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
	  f_TrajDistMeas = fABS(pt_LAOutput->t_LAObjOutputList[iObj].TrajDist.TrajDistMeas.Y.f0);
      fDistToTrajExt = MAX(f_TrajDistMeas, pDistWidth->fDistance);
      f_ObjLongDisp = (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj));
      t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(iObj);
      f_Orientation = pt_LAInput->t_RTE.pf_ObjOrientation(iObj);
      f_StdOrientation = pt_LAInput->t_RTE.pf_ObjOrientationStd(iObj);
	  fABS_Orientation = fABS(f_Orientation);
      /* Use orientation for inlap computation ONLY if object is already OOI in previous cycle AND
           1. Longitudinal distance of the object is in between 1.5m and 10m to EGO
           2. Lateral distance of the object (with corridor center as reference) is < 2.0m to EGO
           3. Object is not Hidden OOI, i.e., only objects on adjacent lanes and ZO
           4. Object is not stationary or stopped but it is moving and not oncoming!
        */
      if ((t_OOI_ObjectList[iObj].t_Bool.AlreadyOOI  == (ubit16_t)1)
      &&(f_ObjLongDisp < LA_MAX_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT)
      &&(f_ObjLongDisp > LA_MIN_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT)
        &&(fDistToTrajExt < LA_MAX_SHORTRANGE_CUT_IN_LAT_DISPLACEMENT)
        &&(OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_HIDDEN_NEXT_OOI) != iObj)
      &&(t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
      &&(fABS_Orientation >= f_StdOrientation)
        )
      {
        /* Code for faster recognitions of Object that cut-in at short distances in front of EGO */
        LA_v_CalculateOrientationEffect(iObj, pDistWidth);
      } /* END IF for checking if orientation has to be considered for inlap computation */
#endif /* LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS */

      pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajDistWidth = *pDistWidth;

      /* Distance to Trajectory based geometric lane association */
      LA_v_GeometricLaneAssoc(iObj);

      /* Prediction based lane association */
      LA_v_PredLaneAssoc(iObj);

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
      bCamLaneAssoc = LA_b_CheckCameraObjAssoToEgoLane(iObj); /* Camera based lane association to ego lane*/
      pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLCamValue = bCamLaneAssoc;
#endif /* FCT_CFG_CAMERA_OBJECT_DETECTION */

      /* Fuse lane association considering geometric, camera, prediction and other considerations */
      LA_b_FusedLaneAssociation(iObj); 

      /* Get associated lane of object (without any quality considerations) */
      eObjAssocLane = LA_t_GetAssociateLane(iObj);

      /* Calculate associated lane used for OOI selection (taking quality into account) */
      e_ObjFuncLane = LA_t_GetObjSelectionLane(iObj, eObjAssocLane);

    } /* END if (!OBJ_IS_DELETED(iObj)) */
    else
    {
      /* Deleted object : reset information */
      pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime = 0.f;
      pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState = OBJ_STATE_OUTLANE;
      pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.In2OutlaneTransition = 0u;
      pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = 0u;

      /* Default init deleted objects lane to unknown */
      eObjAssocLane = ASSOC_LANE_UNKNOWN;

      /* Default init functional lane to unknown */
      e_ObjFuncLane = ASSOC_LANE_UNKNOWN;
    }

    /* Assign a lane for the external interface (without taking object quality into account) */
    pt_LAOutput->t_LAObjOutputList[iObj].ObjAssociatedLane = eObjAssocLane;

    /* Write the lane used for object selection (taking object quality into account) to the external interface*/
    pt_LAOutput->t_LAObjOutputList[iObj].ObjFuncLane = e_ObjFuncLane;

  } /* END LOOP for (iObj = (ObjNumber_t)(EM_N_OBJECTS - 1); iObj >= 0; iObj--) */
}

/*************************************************************************************************************************
  Functionname:    LA_t_GetAssociateLane                                                                               */ /*!

  @brief           Get associated lane of object

  @description     Get the lane associated to an object. The ego lane association is performed previously and is only checked here.
                   If an object is not inlane, a simple lane association is performed for the far right, right, left, and far left
                   lane.
                   @startuml
                    partition LA_t_GetAssociateLane {
                    start
                     if(check if object is associate in lane) then (yes)
                       -Set Object lane to ego lane
                     elseif( check if object is on right side of lane) then (yes)
                        -object is on Right side
                        if(object is not stationary or it is moving to stationary) then (yes)
                    	  if(distance to trajectory on right side is less that the product of scale lane width factor and standard road width) then (yes)
                    	    -Set object lane to far right lane
                    	  endif
                    	else
                    	  if(distance to trajectory on right side is less that the product of scale lane width factor and LA STATIONARY STRASSENBREITE) then (yes)
                    	    -Set object lane to far right lane
                    	  endif
                    	endif
                     else
                       -object is on left side
                       if(object is not stationary or it is moving to stationary) then (yes)
                    	  if(distance to trajectory on Left side is less that the product of scale lane width factor and standard road width) then (yes)
                    	    -Set object lane to far Left lane
                    	  endif
                    	else
                    	  if(distance to trajectory on Left side is less that the product of scale lane width factor and LA STATIONARY STRASSENBREITE) then (yes)
                    	    -Set object lane to far Left lane
                    	  endif
                    	endif
                     endif
                     
                    stop
                    }
                    @enduml

  @return          object_lane : Lane enumeration [eAssociatedLane_t as defined in Rte_Type.h]

  @param[in]       ObjId : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane or not (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    280:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-280-00061542 \n
                   171:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-171-00061542 \n
                   172:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-172-00061542 \n
                   173:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-173-00061542 \n
                   174:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-174-00061542 \n

  @created         22.02.2016
  @changed         22.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static eAssociatedLane_t LA_t_GetAssociateLane(const ObjNumber_t ObjId)
{
  eAssociatedLane_t object_lane;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(ObjId));
  float32 DistanceToTraj = pt_LAOutput->t_LAObjOutputList[ObjId].TrajDist.TrajDistMeas.Y.f0;
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(ObjId);

  /* check if object is associate in lane */
  if (pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.LAInlaneState == OBJ_STATE_INLANE)
  {
    object_lane = ASSOC_LANE_EGO;
  }
  /* check if object is on right side of lane */
  else if ( DistanceToTraj < 0.0f )
  {
    object_lane = ASSOC_LANE_RIGHT;
    if( (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
      ||(b_ObjIsMovingToStationary == TRUE))
    {
      if ( DistanceToTraj < - (LA_SCALE_LANE_WIDTH_LANE_ASSOC * STRASSENBREITE))
      {
        object_lane = ASSOC_LANE_FAR_RIGHT;
      }
    }
    else
    {
      if ( DistanceToTraj < - (LA_SCALE_LANE_WIDTH_LANE_ASSOC * LA_STATIONARY_STRASSENBREITE))
      {
        object_lane = ASSOC_LANE_FAR_RIGHT;
      }
    }
  }
  /* object is on left side */
  else
  {
    object_lane = ASSOC_LANE_LEFT;
    if( (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
      ||(b_ObjIsMovingToStationary == TRUE))
    {
      if ( DistanceToTraj > + (LA_SCALE_LANE_WIDTH_LANE_ASSOC * STRASSENBREITE))
      {
        object_lane = ASSOC_LANE_FAR_LEFT;
      }
    }
    else
    {
      if ( DistanceToTraj > + (LA_SCALE_LANE_WIDTH_LANE_ASSOC * LA_STATIONARY_STRASSENBREITE))
      {
        object_lane = ASSOC_LANE_FAR_LEFT;
      }
    }
  }
  return(object_lane);
}

/*************************************************************************************************************************
  Functionname:    LA_t_GetObjSelectionLane                                                                            */ /*!

  @brief           Get associated lane of object for object selection

  @description     Get the lane assigned to a given object identified by it's
                   object ID 'ObjId' for use in object selection. Note: this
                   lane may differ from the base lane associated, since
                   additional quality tests for different lanes may be
                   implemented here.
                   @startuml
                   partition LA_t_GetObjSelectionLane {
                   start
                      partition LA_b_CheckObjLaneQuality {
                        -check object lane quality 
                      }
                      
                      partition LA_b_CheckObjAdjLaneValidity {
                        -check object adjacent lane Validty
                      }
                      
                      partition LA_b_CheckObjOncRollBack {
                        -check object oncoming roll back
                      }
                      
                      partition LA_b_CheckEgoLaneAssocValidity {
                        -check Ego lane association Validty
                      }
                      
                      partition LA_b_CheckObjInlaneAllowed {
                        -check object in lane allowed
                      }
                      
                      If(object is not allowed to be inlane, but base assignment set it in-lane) then (yes)
                   	 -Set object right/left depending on it's distance to trajectory
                      endif
                      
                      if(the object does not pass preselection)then (yes)
                         -Set lane to unknown
                      endif
                   stop
                   }
                   @enduml
  @return          eRetLane : Associated lane of object ObjId for object selection [eAssociatedLane_t as defined in Rte_Type.h]

  @param[in]       ObjId : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       eBaseAssocLane : the base associated lane without quality considerations [eAssociatedLane_t as in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_ADD_CHECK_INLANE_TRANSITION : Configuration switch enabling additional object quality check for objects
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    93:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-934-00061542 \n
                   299:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-299-00061542 \n
                   280:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-280-00061542 \n
                   284:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-284-00061542 \n
                   170:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-170-00061542 \n

  @created         22.02.2016
  @changed         22.02.2016

  @author          Gergely Ungvary |  gergely.ungvary@continental-corporation.com | +36 88 548 671
*************************************************************************************************************************/
static eAssociatedLane_t LA_t_GetObjSelectionLane(const ObjNumber_t ObjId, const eAssociatedLane_t eBaseAssocLane)
{
  eAssociatedLane_t eRetLane = eBaseAssocLane;
  float32 DistanceToTraj;

  /* Check for sufficient ACC-quality and timegap-criterion. Objects, which do not pass
     this preselection, may not be assigned to a lane and will be assigned to ASSOC_LANE_UNKNOWN */
  const boolean b_ObjLaneQuality = LA_b_CheckObjLaneQuality(ObjId);

  /* Check, if the base associated lane (without quality considerations) is valid regarding the OOI-selection
     on adjacent lanes. Moving and stationary objects with invalid lane assignment or oncoming objects beyond
     the road border will be set to ASSOC_LANE_UNKNOWN and thus not be considered in OOI-selection. */
  const boolean b_ObjAdjLaneValidity = LA_b_CheckObjAdjLaneValidity(ObjId,  eBaseAssocLane);

  /* Oncoming objects may only be set on host-lane in case of the special 'relevant object rolling
     back' situation. If the extra function 'LA_b_CheckObjOncRollBack' returns FALSE, then the
     object may not be assigned to ego-lane and will be assigned to ASSOC_LANE_RIGHT or ASSOC_LANE_LEFT */
  const boolean b_ObjOncRollBack = LA_b_CheckObjOncRollBack(ObjId, eBaseAssocLane);

  /* Check, if other objects are overlapping with the relevant Object (OOI-0) and if TRUE
     set to ASSOC_LANE_UNKNOWN and thus not be considered in OOI-selection. */
  const boolean b_ObjCheckEgoLaneValidity = LA_b_CheckEgoLaneAssocValidity(ObjId);

#if (LA_CFG_ADD_CHECK_INLANE_TRANSITION)
  /* If the configuration dependent extra function 'LA_b_CheckObjInlaneAllowed' returns
  FALSE, then that means the object is not allowed to be set ego-lane. */
  const boolean bInlaneAllowed = LA_b_CheckObjInlaneAllowed(ObjId);
#endif

  /* If object is not allowed to be inlane, but base assignment set it in-lane
  then change the default association for selection */
  if (
#if (LA_CFG_ADD_CHECK_INLANE_TRANSITION)
        ((bInlaneAllowed == FALSE) && (eRetLane == ASSOC_LANE_EGO))
      ||
#endif
        ((b_ObjOncRollBack == FALSE) && (eRetLane == ASSOC_LANE_EGO))
     )
  {
    /* Set object right/left depending on it's distance to trajectory */
    DistanceToTraj = pt_LAOutput->t_LAObjOutputList[ObjId].TrajDist.TrajDistMeas.Y.f0;

    if (DistanceToTraj < 0.f)
    {
      eRetLane = ASSOC_LANE_RIGHT;
    }
    else
    {
      eRetLane = ASSOC_LANE_LEFT;
    }
  }
  /* Set lane to unknown, if the object does not pass preselection (including ACC-quality and timegap-criterion OR 
     if the adjacent lane is not valid regarding OOI-selection OR
     if another object (OOI-1) overlaps with relevant object (OOI-0)*/
  if ( (b_ObjLaneQuality == FALSE) || (b_ObjAdjLaneValidity == FALSE) || (b_ObjCheckEgoLaneValidity == FALSE) )
  {
    eRetLane = ASSOC_LANE_UNKNOWN;
  }

  return eRetLane;
}

#if (LA_CFG_ADD_CHECK_INLANE_TRANSITION)
/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjInlaneAllowed                                                                          */ /*!

  @brief           Check if object is allowed to be set in-lane

  @description     Check if object is allowed to be set in-lane. Additional
                   (special) quality checks can be done here. If the function
                   returns 'FALSE' then that effectively prevents the object
                   from becoming relevant.
                   Note: the function is not called each cycle only if the
                   object was otherwise detected to be in-lane
                   @startuml
                   partition LA_b_CheckObjInlaneAllowed {
                   start
                     if(object is stationary or stopped) then (yes)
                       if(Object Is Moving To Stationary) then (yes)
                   	   if(object was not moving and object was oncoming once) then (yes)
                   	      if(Object was in state oncoming during lifetime) then (yes)
                   		     - object is not associate to ego lane
                   		  endif 
                   		endif  
                   	else
                   	  if(object quality is less than or equal to FUNCTION PRESEL ACC MINIMUM OBJECT QUALITY and DYNAMIC SUB PROPERTY is not SLATE OBJECT SUBPROP CROSSING) then (yes)
                   	     - object is not associate to ego lane
                   	   endif
                   	endif
                     endif
                   stop
                   }
                   @enduml

  @return          TRUE if object may be associated to ego lane [TRUE, FALSE]

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information [0 ... 100]
  @glob_in         OBJ_DYNAMIC_SUB_PROPERTY(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         pt_LAInput->t_FIPOA.pt_ObjBool(i)->bit_ObjWasMoving : Info if object was moving once [TRUE, FALSE]
  @glob_in         pt_LAInput->t_FIPOA.pt_ObjBool(i)->bit_ObjWasOncoming : Info if object was oncoming once [TRUE, FALSE]
  @glob_in         pt_LAInput->t_FIPOA.pt_ObjBool(i)->bit_StatObjWasOncoming : Object was in state oncoming during lifetime [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLQualityValue : Quality indicating whether object is allowed inlane or not [TRUE, FALSE]

  @c_switch_part   FIP_CFG_CHECK_STAT_OBJ_WAS_ONCOMING : Configuration switch for treating stationary objects as oncoming
  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : DTR object selection
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_ADD_CHECK_INLANE_TRANSITION : Switch to enable additional object quality check for objects associated to ego lane

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2016
  @changed         12.02.2016

  @author          Gergely Ungvary | gergely.ungvary@continental-corporation.com | +36 88 548 671
*************************************************************************************************************************/
static boolean LA_b_CheckObjInlaneAllowed(const ObjNumber_t iObj)
{
  boolean bRet = TRUE;

  /* Extra check currently done for stationary objects:
    1. These have to have an ACC object quality more than
      FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL to be selectable
      for ego-lane.
    2. Stopped objects that have not been seen moving may only become
      ego lane if they are either below a given distance or were only
      seen oncoming for a short period of time */
  SLATE_t_Obj_DynamicProperty t_ObjDynProp = *SLATE_pt_GetObjDynProperty(iObj);
  if ( (t_ObjDynProp == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
    || (t_ObjDynProp == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
    )
  {
    boolean bObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);
    if (bObjIsMovingToStationary == TRUE)
    {
#if (FIP_CFG_CHECK_STAT_OBJ_WAS_ONCOMING)
      if ((pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_Bool.bit_ObjWasMoving == (ubit8_t)0u) && (pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_Bool.bit_ObjWasOncoming != (ubit8_t)0u))
      {
#if (FCT_CFG_INPUT_PREPROCESSSING)
        if(pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_Bool.bit_StatObjWasOncoming == (ubit8_t)1u)
        {
          bRet = FALSE;
        }
#endif
      }
#endif
    }
    else
    {
#if (!LA_CFG_DTR_OBJ_SELECTION)
      /* Stationary objects need to be of at least FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL
      quality to be selectable for ego-lane. Note that Objects of less than
      FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL quality are also handled in function
      LA_b_CheckObjLaneQuality */
      if((SLATE_u_GetAccQuality(iObj) <= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
        && (OBJ_DYNAMIC_SUB_PROPERTY(iObj) != SLATE_OBJECT_SUBPROP_CROSSING)
#endif
        )
      {
        bRet = FALSE;
      }
#endif
    }
  }

  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLQualityValue = bRet;

  return bRet;
}

#endif

#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
/*************************************************************************************************************************
  Functionname:    LA_v_UpdateClusterVarianceLevel                                                                  */ /*!

  @brief           Update object specific cluster variance level

  @description     Loop over all objects to update the cluster variance level. If the cluster variance of an object is high
                   and one of the situation specific criterias is fulfilled, increase the cluster variance difficulty level.
                   In these special situations with high cluster variance more stringent thresholds shall be used for
                   association of moving objects to ego lane.

                  @startuml 
                  partition LA_v_UpdateClusterVarianceLevel{
                 start
                 repeat
                     -Set default cluster variance level
                     -Get longitudinal displacement of object under consideration
                     -Check general conditions for higher cluster variance level
                     if(Object is not deleted and object is moving and acc quality is less than FUN PRESEL ACC HIGH CLUST VAR OBJ QUAL and ego velocity and object longitudinal displacement is in between minimum and maximum cluster variance Thresholds and ) then (yes)
                 	    -Set default values for criteria flags
                 		if(ego is close to road border) then (yes)
                 		    partition LA_f_ComputeObjDistToRoadBorder {
                 		    -Compute object position relative to the road border close to ego
                 			}
                 			-Compute delta between object and ego distance to road border
                 			if(object distance to road border is not default) then (yes)
                 			    -Set Object distance to road border criteria flag to true
                 			endif
                 		endif
                 		
                 		if(ego is not close to road border) then (yes)
                 		    -set tunnel criteria to true
                 		endif
                 		
                 		partition FCT_CFG_CURVATURE_CHANGE_COMPUTATION {
                 		    -Check curvature change criteria .curve entry/exit situations
                 		}
                 		if(situations tunnel or close to road border)then (yes)
                 		    partition LA_v_FindObjInArea{
                 			    -call LA_v_FindObjInArea function
                 			}
                 			-If a second object has been found, object under consideration is probably a mirror and should be suppressed
                 			-Check conditions for higher cluster variance level and  Set cluster variance level to difficult if conditions matches
                 		endif
                     endif
                     -Store cluster variance level    
                 repeat while(for all objects)
                 stop
                 @enduml


  @return          static void

  @param[in]       void :

  @glob_in         SLATE_b_GetObjIsDeleted(i) : Boolean if object i is deleted [TRUE, FALSE]
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information [0 ... 100]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s
  @glob_in         OBJ_LONG_DISPLACEMEN(i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of an object i [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border [0.f ... 30.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [-30.f ... 0.f]
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel [0.0f ... 1.0f]
  @glob_in         f_RoadVDYDeltaNear : Distance delta of road and vdy curves [full range of data type float32 >= 0.f]
  @glob_out        t_LA_InternalObjectData[i].ui_ClusterVarianceLevel : Difficulty level of object i with high cluster variance
                   [LA_CLUST_VAR_LEVEL_LOW ... LA_CLUST_VAR_LEVEL_DIFFICULT]

  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_full   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Config switch to enable use of cluster variance in lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             Cluster Variance considered in acc quality e.g. acc quality set to FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL
                   in case of high cluster variance
  @pre             f_RoadVDYDeltaNear updated

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         14.10.2015
  @changed         14.10.2015

  @todo            Check for separate cluster variance signal instead of ACC quality if available after RTE update
  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static void LA_v_UpdateClusterVarianceLevel(void)
{
  ObjNumber_t ObjNr;                                         /* Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1] */
  uint8 ui_ClusterVarianceLevel;                             /* Local cluster variance level */
  float32 f_ObjDistToRoadborder,                             /* Object position relative to road border close to ego. A positive value means object is inside road borders */
          f_RoadborderDistDelta;                             /* Delta between object and ego distance to road border */
  boolean b_ObjDist2RoadBorderCriteria,                      /* Object distance to road border criteria flag: ego is close to the road border while object is not */
          b_MirrorCriteria,                                  /* Mirror criteria flag: object is close to another object with same velocity */
          b_TunnelCriteria;                                  /* Tunnel criteria flag: ego is in a tunnel and not close to the road border */
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  boolean b_CurveEntryCriteria;                              /* Curve entry criteria flag: road estimation deviates significantly from vdy curve */
#endif
  float32 f_ObjLongDisp;                                     /* Longitudinal displacement of object under consideration */
  float32 f_ObjLongDispMax;
  SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty;
  float32 t_EgoVelObjSync;
  boolean b_ObjIsDeleted; 
  uint8 t_AccObjQuality;
  ObjNumber_t a_CloseObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX]; /* Array of objects close to ObjNr. Needed to check if it is a possible mirror */
  float32 CML_f_Abs_DistLeft, CML_f_Abs_DistRight;	/* For calculating ABS value */

  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1); ObjNr >= 0; ObjNr--)
  {
    /* Set default cluster variance level */
    ui_ClusterVarianceLevel = LA_CLUST_VAR_LEVEL_LOW;

    /* Get longitudinal displacement of object under consideration */
    f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr);

    /* Check general conditions for higher cluster variance level */
	t_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(ObjNr));
	t_EgoVelObjSync = (*pt_LAInput->t_RTE.pf_EgoVelObjSync);
	b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(ObjNr);
	t_AccObjQuality = SLATE_u_GetAccQuality(ObjNr);
	f_ObjLongDispMax = (LA_CLUST_VAR_TTC_MAX*(-*pt_LAInput->t_RTE.pf_ObjVrelX(ObjNr)));
    if ( (!b_ObjIsDeleted)
      && (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
      && (t_AccObjQuality <= FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL)
      && (t_EgoVelObjSync < LA_CLUST_VAR_VEGO_MAX)
      && (t_EgoVelObjSync > LA_CLUST_VAR_VEGO_MIN)
      && (f_ObjLongDisp > LA_CLUST_VAR_XDIST_MIN)
      && (f_ObjLongDisp < f_ObjLongDispMax)
       )
    {
      /* Set default values for criteria flags */
      b_ObjDist2RoadBorderCriteria  = FALSE;
      b_MirrorCriteria              = FALSE;
      b_TunnelCriteria              = FALSE;
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
      b_CurveEntryCriteria          = FALSE;
#endif
	  CML_f_Abs_DistLeft  = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft));
	  CML_f_Abs_DistRight = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight));
      /* 1. If ego is close to road border: check object distance to road border criteria  */
      if ( (CML_f_Abs_DistLeft  < LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
        || (CML_f_Abs_DistRight < LA_CLUST_VAR_ROAD_BORDER_DIST_MAX) )
      {
        /* Compute object position relative to the road border close to ego. */
        /* A positive value means object is inside road borders */
        f_ObjDistToRoadborder = LA_f_ComputeObjDistToRoadBorder(ObjNr);
        
		CML_f_Abs_DistLeft  = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft));/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Gireesh , Reason:This warning is suppressed as Indentation does not have any critical impact the functionality. */
	    CML_f_Abs_DistRight = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight));
        /* Compute delta between object and ego distance to road border */
        if ( CML_f_Abs_DistLeft <= CML_f_Abs_DistRight )
        {
          f_RoadborderDistDelta = f_ObjDistToRoadborder - CML_f_Abs_DistLeft;
        }
        else
        {
          f_RoadborderDistDelta = f_ObjDistToRoadborder - CML_f_Abs_DistRight;
        }

        /* In case the object distance to road border is not default, check if the distance delta is above threshold */
        if ( (f_ObjDistToRoadborder < LA_OBJ_DIST_TO_ROADBORDER_DEFAULT)
          && (f_RoadborderDistDelta > LA_CLUST_VAR_ROAD_BORDER_DIST_DELTA_THRES)
           )
        {
          /* If the distance delta is high, it is probably not a cut-in or appraoch szenario */
          b_ObjDist2RoadBorderCriteria = TRUE;
        }
      }

	  CML_f_Abs_DistLeft  = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft));
	  CML_f_Abs_DistRight = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight));
      /* 2. Check tunnel criteria if ego is not close to road border */
      if ( (CML_f_Abs_DistLeft  > LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
        && (CML_f_Abs_DistRight > LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
        && (*pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES )
         )
      {
        b_TunnelCriteria = TRUE;
      }

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
      /* 3. Check curvature change criteria (curve entry/exit situations).  */
      if ( (pt_LAInput->pt_FIPCC->b_FusedDistToHighCCValid == TRUE)
        && (pt_LAInput->pt_FIPCC->f_FusedDistToHighCC < f_ObjLongDisp)
        && (*pt_LAInput->t_RTE.pf_TunnelProbability < LA_TUNNEL_PROB_THRES) )
      {
        b_CurveEntryCriteria = TRUE;
      }
#endif /* FCT_CFG_CURVATURE_CHANGE_COMPUTATION */

	  CML_f_Abs_DistLeft  = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft));
	  CML_f_Abs_DistRight = CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight));
      /* 3. Check mirror criteria: if object is mirror, a second object with same velocity will be close to it */
      /* Criteria active only in tunnel or close to road border */
      if ( (*pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES)
        || (CML_f_Abs_DistLeft  < LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
        || (CML_f_Abs_DistRight < LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
         )
      {
#if (LA_CFG_AVOID_SPILT_OBJ)
        LA_v_FindObjInArea(a_CloseObjID, ObjNr, &LAMirrorObjArgs, FALSE);
#else
        LA_v_FindObjInArea(a_CloseObjID, ObjNr, &LAMirrorObjArgs);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
        /* If a second object has been found, object under consideration is probably a mirror and should be suppressed */
        if( a_CloseObjID[0] != (ObjNumber_t)-1)
        {
          b_MirrorCriteria = TRUE;
        }
      }

      /* Check conditions for higher cluster variance level */
      if ( (b_ObjDist2RoadBorderCriteria == TRUE) 
        || (b_MirrorCriteria == TRUE) 
        || (b_TunnelCriteria == TRUE) 
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
        || (b_CurveEntryCriteria == TRUE) 
#endif
         )
      {
        /* Set cluster variance level to difficult */
        ui_ClusterVarianceLevel = LA_CLUST_VAR_LEVEL_DIFFICULT;
      }
    }

    /* Store cluster variance level */
    t_LA_InternalObjectData[ObjNr].ui_ClusterVarianceLevel = ui_ClusterVarianceLevel;
  }
}
#endif /* END IF (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) */

#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
/*************************************************************************************************************************
  Functionname:    LA_f_ComputeObjDistToRoadBorder                                                                  */ /*!

  @brief           Compute object distance to the road border close to ego

  @description     Computes and returns the object distance to the road border closest to ego.
                   Dependant on longitudinal displacement of the object, distance to the road border is computed either
                   from the SI trajectory and road border information or the road estimation information.
                   @startuml 
                    partition LA_f_ComputeObjDistToRoadBorder {
                    start
                        if(object longitudinal distance is low) then (yes)
                    	    if(Abs RoadDistLeft is less than or equal to Abs RoadDistRight and Left road border status is greater than or equal to 100) then (yes)
                    		    -Get object distance to trajectory and compute distance to road border 
                    		elseif(Abs RoadDistLeft is greater than Abs RoadDistRight and Right road border status is greater than or equal to 100)then (yes)
                    		    -Get object distance to trajectory and compute distance to road border
                    		else
                    		    -Set road border information to default
                    		endif
                    	elseif(object longitudinal distance is high) then(yes)
                    	    if(ego is close to left road border) then (yes)
                    		    -Evaluate lateral object position relative to road center
                    			-Evaluate lateral object position relative to road border.A positive value means object is inside road borders. 
                    		elseif(ego is close to right road border) then (yes)
                    		    -Evaluate lateral object position relative to road center
                    			-Evaluate lateral object position relative to road border.A positive value means object is inside road borders
                    		else
                    		    -Set road border information to default
                    		endif
                    	else
                    	    -Set road border information to default
                    	endif
                    	-Store object distance to road border for debugging
                    stop
                    @enduml

  @return          f_ObjDistToRoadborder : Object position relative to road border. A positive value means object is
                   inside road borders [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       ObjNr : Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral displacement of an object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft : Left road border status [0u ... 100u]
  @glob_in         pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight : Right road border status [0u ... 100u]
  @glob_in         pt_FIPRoad->t_FIPRoadEstimation : Pointer to the estimated road properties
                                 pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft  [0u ... MAX_TRACKING_STATUS as defined in rd_ext.h]
                                 pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight [0u ... MAX_TRACKING_STATUS as defined in rd_ext.h]
                                 pt_FIPRoad->t_FIPRoadEstimation->fYawAngle         [-100.f .. +100.f] rad/s
                                 pt_FIPRoad->t_FIPRoadEstimation->fC0                          [-1 ... +1] m^(-1)
                                 pt_FIPRoad->t_FIPRoadEstimation->fC1                          [-1 ... +1] m^(-1)
                                 pt_FIPRoad->t_FIPRoadEstimation.fYLeft                [0 ... PI/2*RW_FCT_MAX] m
                                 pt_FIPRoad->t_FIPRoadEstimation.fYRight               [-PI/2*RW_FCT_MAX ... 0] m
  @glob_in         ROAD_GET_CONFIDENCE_LEFT : Confidence of road estimation on left side [0.f ... 100.f]
  @glob_in         ROAD_GET_MAX_X_LEFT_COMPENSTATED : Distance up to which road estimation on left side is available
                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         ROAD_GET_CONFIDENCE_RIGHT : Confidence of road estimation on right side [0.f ... 100.f]
  @glob_in         ROAD_GET_MAX_X_RIGHT_COMPENSTATED :  Distance up to which road estimation on right side is available
                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].f_ObjDistToRoadborder : Position of object i relative to road border which is close to ego.
                   A positive value means object is inside road borders [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @c_switch_full   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Config switch to enable use of cluster variance in lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             SI trajectory updated
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         14.10.2015
  @changed         14.10.2015

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static float32 LA_f_ComputeObjDistToRoadBorder(const ObjNumber_t ObjNr)
{
  float32 f_ObjDist2Traj;                         /* Object distance to trajectory */
  float32 f_ObjDistToRoadborder;                  /* Object position relative to road border close to ego */
  float32 f_DistX_Sqr;                            /* Object longitudinal distance square */
  float32 f_ObjRoadDistY;                          /* Object position relative to road center */
  
  float32 f_DistY;                                /* Lateral object distance */
  float32 f_DistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr); /* Longitudinal object distance */
  
  /* Local variables made since value accessed frequently */
  float32 f_RoadDistLeft = (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft);
  float32 f_RoadDistRight = (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight);

  /* For low longitudinal distance of object compute distance to road border from SI trajectory and road border information */
  if ( f_DistX < LA_OBJ_DIST_TO_ROADBORDER_DIST_LOW )
  {
    float32 f_Abs_RoadDistLeft = CML_f_Abs(f_RoadDistLeft);
    float32 f_Abs_RoadDistRight = CML_f_Abs(f_RoadDistRight);
    if ( (f_Abs_RoadDistLeft <= f_Abs_RoadDistRight)
          && ( (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= (LA_OBJ_DIST_TO_ROADBORDER_STAT_MIN)) )
    {
      /* Get object distance to trajectory and compute distance to road border */
      f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistMeas.Y.f0;
      f_ObjDistToRoadborder = f_RoadDistLeft - f_ObjDist2Traj;
    }
    else if ( (f_Abs_RoadDistLeft > f_Abs_RoadDistRight)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= (LA_OBJ_DIST_TO_ROADBORDER_STAT_MIN)) )
    {
      /* Get object distance to trajectory and compute distance to road border */
      f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistMeas.Y.f0;
      f_ObjDistToRoadborder = f_ObjDist2Traj - f_RoadDistRight;
    }
    else
    {
    /* If road border information not reliable, we cannot compute a distance to road border */
      f_ObjDistToRoadborder = LA_OBJ_DIST_TO_ROADBORDER_DEFAULT;
    }
  }
  /* For a higher longitudinal distance of object compute distance to road border from road estimation information */
  else if (f_DistX < LA_OBJ_DIST_TO_ROADBORDER_DIST_HIGH)
  {
    
    /* If ego is close to left road border check if road estimation and road border information are reliable enough */
    float32 f_AbsRoadDistLeft = CML_f_Abs(f_RoadDistLeft);
    float32 f_AbsRoadDistRight = CML_f_Abs(f_RoadDistRight);
    if ( (f_AbsRoadDistLeft <= f_AbsRoadDistRight)
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= (LA_OBJ_DIST_TO_ROADBORDER_STAT_MIN))
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN)
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_TRACK_MIN)
      && (f_DistX <= (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated)) )
    {
      /* Local variables */
      f_DistX_Sqr = SQR(f_DistX) * (0.5f);
      f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(ObjNr);

      /* Evaluate lateral object position relative to road center */
      f_ObjRoadDistY = f_DistY - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle))*f_DistX) - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*f_DistX_Sqr) - ((((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1))*f_DistX*f_DistX_Sqr)*(1.0F/3.0f));

      /* Evaluate lateral object position relative to road border.  A positive value means object is inside road borders. */
      f_ObjDistToRoadborder = (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft) - f_ObjRoadDistY;
    }
    /* If ego is close to right road border check if road estimation and road border information are reliable enough */
    else if ( (f_AbsRoadDistLeft > f_AbsRoadDistRight)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= (LA_OBJ_DIST_TO_ROADBORDER_STAT_MIN))
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_TRACK_MIN)
           && (f_DistX <= (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated)) )
    {
      /* Local variables */
      f_DistX_Sqr = SQR(f_DistX) * (0.5f);
      f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(ObjNr);

      /* Evaluate lateral object position relative to road center */
      f_ObjRoadDistY = f_DistY - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle))*f_DistX) - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*f_DistX_Sqr) - ((((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1))*f_DistX*f_DistX_Sqr)*(1.0F/3.0f));

      /* Evaluate lateral object position relative to road border. A positive value means object is inside road borders. */
      f_ObjDistToRoadborder = f_ObjRoadDistY - (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight);
    }
    else
    {
      /* If road estimation information not reliable, we cannot compute a distance to road border */
      f_ObjDistToRoadborder = LA_OBJ_DIST_TO_ROADBORDER_DEFAULT;
    }
  }
  else
  {
    /* For high longitudinal distances we do not compute a distance to road border as road border,
       road estimation and trajectory information are not reliable enough */
    f_ObjDistToRoadborder = LA_OBJ_DIST_TO_ROADBORDER_DEFAULT;
  }

#ifdef FCT_SIMU
  /* Store object distance to road border for debugging */
  t_LA_InternalObjectData[ObjNr].f_ObjDistToRoadborder = f_ObjDistToRoadborder;
#endif

  return f_ObjDistToRoadborder;
}
#endif /* END IF (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) */

#if (LA_CFG_ENABLE_PARKED_DETECTION)
/*************************************************************************************************************************
  Functionname:    LA_v_RoadSideParkedObjDetection                                                                  */ /*!

  @brief           Set flag to detect Stationary Parked Object using Right and Left Road Border information.

  @description     For camera confirmed stationary objects calculate Distance to RoadBorder using Left and Right roadborder information.
                   Depending on Distance to road border value associate the Objects to Left or Right roadborder, if the object
                   is within roadborder width then those objects are classified as parked object. If there are enough objects associated
                   to Right or Left Road border then flag is made True for road border associated Objects.
                    @startuml 
                    partition LA_v_RoadSideParkedObjDetection {
                    start
                        repeat
                    	    if(object is stationary or stopped  and object is camera confirmed and 
                    		   object longitudinal distance is less tha PARKED OBJ DETECTION RANGE and ego speed is less the max city speed) then (yes)
                    		    if(Confidence of Left Road Border is greater than Minimal confidence for the Road Estimation)
                    			    -Evaluate lateral object position relative to Left Road Border Curve
                    				-Evaluate lateral object position relative to Left road border
                    				-Calculate Distance to road border
                    				-Check if the Object is within the RoadBorder width
                    			endif
                    			if(Confidence of Right Road Border is greater than Minimal confidence for the Road Estimation)
                    			    -Evaluate lateral object position relative to Right Road Border Curve
                    				-Evaluate lateral object position relative to road border
                    				-Calculate Distance to road border
                    				-Check if the Object is within the Right RoadBorder width
                    			endif
                    		endif
                    	repeat while(For all objects in use)
                    	
                    	if(Left Parked Vehicle Object Count is greater than or equal to MIN NUM OF DETECTED PARKING CARS) then (yes)
                    	    if(Left Parked Vehicle Object Count is less than MAX NUM OF PARKING_CARS) then (yes)
                    		    -Calculate average dist to road boarder
                    		endif
                    	endif		
                    	if(Rigth Parked Vehicle Object Count is greater than or equal to MIN NUM OF DETECTED PARKING CARS) then (yes)
                    	    if(Rigth Parked Vehicle Object Count is less than MAX NUM OF PARKING_CARS) then (yes)
                    		    -Calculate average dist to road boarder
                    		endif	
                    	endif
                    	-Update flag for Object which are detected as Parked Vehicles
                    	-Get longitudinal displacement of object under consideration
                    	- Check stationary objects
                    stop
                    @enduml

  @return          void

  @param[in]       void


  @glob_in         *SLATE_pu_GetDistXSortedObj(i) : number of object i in dist-x sorted list [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                            with i in [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral displacement of an object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         *pt_LAInput->t_FIPOA.pt_CamConfirmationProb(ObjNr)   : Camera confirmation probability of Objects
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fConfidence   : Confidence of Left Road Border estimation 
                   pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fYawAngle     : Left Road Border YawAngle
                   pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fC0           : Left Road Border Curvature
                   pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fC1           : Left Road Border Curvature Gradient
                   pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fLateralOffset: Lateral offset to Left Road Border
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fConfidence  : Confidence of Right Road Border estimation 
                   pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fYawAngle    : Right Road Border YawAngle
                   pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fC0          : Right Road Border Curvature
                   pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fC1          : Right Road Border Curvature Gradient
                   pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fLateralOffset: Lateral offset to Right Road Border
  @glob_out         pt_LAOutput->b_RoadSideParkedObj[iObj] : Road side Parked Object detection flag

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author          Dyamana Gouda | Dyamana.gouda@continental-corporation.com | +91 80 6679 8429
*************************************************************************************************************************/
static void LA_v_RoadSideParkedObjDetection(void)
{
  ObjNumber_t t_ObjNr;                                                  /* Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1] */
  float32 f_ObjDistToRoadborder;                                        /* Object position relative to road borders */
  float32 f_DistX = 0.f;                                                /* Longitudinal displacement of object under consideration */
  float32 f_DistY = 0.f;                                                /* Lateral displacement of object under consideration */
  float32 f_DistX_Sqr = 0.f;                                            /* Object longitudinal distance squared */
  float32 f_ObjRoadDistY = 0.f;                                         /* Object lateral position relative to road borders */
  float32 f_RBShift = 0.f;                                              /* lateral object position shift relative to road border */

  float32 f_LeftConf = pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fConfidence;            /* Confidence of Left Road Border estimation */
  float32 f_RightConf = pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fConfidence;          /* Confidence of Right Road Border estimation */

  float32 f_LeftYawAngle = pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fYawAngle;          /* Left Road Border YawAngle */
  float32 f_Leftf0 = pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fC0;                      /* Left Road Border Curvature */
  float32 f_Leftf1 = pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fC1;                      /* Left Road Border Curvature Gradient */

  float32 f_RightYawAngle = pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fYawAngle;        /* Right Road Border YawAngle */
  float32 f_Rightf0 = pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fC0;                    /* Right Road Border Curvature */
  float32 f_Rightf1 = pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fC1;                    /* Right Road Border Curvature Gradient */

  float32 f_LeftOffset = pt_LAInput->pt_FIPRoad->t_FIPLeftRoadBorder.fLateralOffset;       /* Lateral offset to Left Road Border */
  float32 f_RightOffset = pt_LAInput->pt_FIPRoad->t_FIPRightRoadBorder.fLateralOffset;     /* Lateral offset to Right Road Border */

  ObjNumber_t a_tObjParkedLeft[EM_N_OBJECTS];                           /* Array of Left Parked Vehicle Object IDs */
  ObjNumber_t a_tObjParkedRight[EM_N_OBJECTS];                          /* Array of Right Parked Vehicle Object IDs */

  uint8 u_LeftParkVehCount = 0u;                                        /* Left Parked Vehicle Object Count */
  uint8 u_RightParkVehCount = 0u;                                       /* Right Parked Vehicle Object Count */
  ObjNumber_t t_SortedObjNum = 0;                                       /* Sorted Object number index */
  uint8 u_LoopCount = 0u;                                               /* Local Loop index variable */
  ObjNumber_t i_NumberofUsedObj = SLATE_t_GetNumOfObjectsUsed();
  
  SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty;                     /* Object Dynamic property */
  percentage_t t_camConfirmationProb;                                   /* Object camera confirmation probability */

  float32 a_fObjDistRoadBoarderLeft[MAX_NUM_OF_PARKING_CARS];           /* Left road side parked Object distance to Road Border */
  float32 a_fObjDistRoadBoarderRight[MAX_NUM_OF_PARKING_CARS];          /* Right road side parked Object distance to Road Border */
  float32 f_ObjDistRDAverageLeft = 0.0f;                                /* Left road side parked Object's Average distance to Road Border */
  float32 f_ObjDistRDAverageRight = 0.0f;                               /* Right road side parked Object's Average distance to Road Border */

  boolean b_LeftParkRowValid = FALSE;                                   /* Flag to indicate MIN_NUM_OF_DETECTED_PARKING_CARS Left parked Object detection */
  boolean b_RightParkRowValid = FALSE;                                  /* Flag to indicate MIN_NUM_OF_DETECTED_PARKING_CARS Right parked Object detection */

  /* Initialize array with default values */
  for(t_ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1);t_ObjNr >= 0;t_ObjNr--)
  {
    a_tObjParkedLeft[t_ObjNr] = OBJ_INDEX_NO_OBJECT;
    a_tObjParkedRight[t_ObjNr] = OBJ_INDEX_NO_OBJECT;
  }
  for(u_LoopCount = 0u; u_LoopCount < MAX_NUM_OF_PARKING_CARS;u_LoopCount++)
  {
    a_fObjDistRoadBoarderLeft[u_LoopCount] = 0.f;
    a_fObjDistRoadBoarderRight[u_LoopCount] = 0.f;
  }

    /************************/
    /* Parking Row Detector */
    /************************/
  for(t_SortedObjNum = 0;t_SortedObjNum < i_NumberofUsedObj;t_SortedObjNum++)
  {
    t_ObjNr = *(SLATE_pu_GetDistXSortedObj(t_SortedObjNum));
    f_DistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr);
    f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjNr);
    f_ObjDistToRoadborder = 0.0f ;
    t_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(t_ObjNr));
    t_camConfirmationProb = (pt_LAInput->pt_FIPOA->t_ObjList[t_ObjNr].t_CamObjectData.t_CamConfirmationProb);

    if(( (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      || (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
       )
       &&(t_camConfirmationProb > (percentage_t)LA_PAR_CAM_CONF_MIN)
       &&(f_DistX < PARKED_OBJ_DETECTION_RANGE )
       &&(EGO_SPEED_X_OBJ_SYNC < MAX_CITY_SPEED_THRESH_RB)
      )
    {
      if(f_LeftConf > LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN)
      {
        f_DistX_Sqr = (SQR(f_DistX))*(0.5f);
        /* Evaluate lateral object position relative to Left Road Border Curve*/
        f_ObjRoadDistY = (((f_LeftYawAngle)*f_DistX) + ((f_Leftf0)*f_DistX_Sqr) + (((f_Leftf1)*f_DistX*f_DistX_Sqr)*(1.0f/3.0f)));

        /* Evaluate lateral object position relative to Left road border. */
        f_RBShift = f_ObjRoadDistY + f_LeftOffset;
        /* Distance to road border calculation */
        f_ObjDistToRoadborder = f_DistY - f_RBShift;
        if((f_ObjDistToRoadborder > LA_PARKING_CORR_WIDTH_IN) && (f_ObjDistToRoadborder < LA_PARKING_CORR_WIDTH_OUT))
        {
          /*Check if the Object is within the RoadBorder width */
          a_tObjParkedLeft[u_LeftParkVehCount] = t_ObjNr;
          if(u_LeftParkVehCount < MAX_NUM_OF_PARKING_CARS)
          {
            a_fObjDistRoadBoarderLeft[u_LeftParkVehCount] = f_ObjDistToRoadborder;
          }
          u_LeftParkVehCount++;
        }
      }

      if(f_RightConf > LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN)
      {
        f_DistX_Sqr = (SQR(f_DistX))*(0.5f);
        /* Evaluate lateral object position relative to Right Road Border Curve */
        f_ObjRoadDistY = (((f_RightYawAngle)*f_DistX) + ((f_Rightf0)*f_DistX_Sqr) + (((f_Rightf1)*f_DistX*f_DistX_Sqr)*(1.0f/3.0f)));
        /* Evaluate lateral object position relative to road border. */
        f_RBShift = f_ObjRoadDistY + (f_RightOffset);
        /* Distance to road border calculation */  
        f_ObjDistToRoadborder = f_DistY - f_RBShift;
        if((f_ObjDistToRoadborder < LA_PARKING_CORR_WIDTH_OUT) && (f_ObjDistToRoadborder > LA_PARKING_CORR_WIDTH_IN))
        {
          /*Check if the Object is within the Right RoadBorder width */
          a_tObjParkedRight[u_RightParkVehCount] = t_ObjNr;
          if(u_RightParkVehCount < MAX_NUM_OF_PARKING_CARS)
          {
            a_fObjDistRoadBoarderRight[u_RightParkVehCount] = f_ObjDistToRoadborder;
          }
          u_RightParkVehCount++;
        }
      }
    }
  } /* End Loop for sorted objects */

  /* Check Average distance to road border of Park Detected Objects to validate Parking detection on Left and Right side. */

  /* Check for Left Parking Row */
  if(u_LeftParkVehCount >= MIN_NUM_OF_DETECTED_PARKING_CARS)
  {
    b_LeftParkRowValid = TRUE;
    if(u_LeftParkVehCount < MAX_NUM_OF_PARKING_CARS)
    {
      for(u_LoopCount = 0u;u_LoopCount < u_LeftParkVehCount;u_LoopCount++)
      {
        /* Sum Distance to road boarder */
        f_ObjDistRDAverageLeft += (float32)fABS(a_fObjDistRoadBoarderLeft[u_LoopCount]);
      }

      /* Calculate average dist to road boarder */
      f_ObjDistRDAverageLeft /= u_LeftParkVehCount;

      for(u_LoopCount = 0u;u_LoopCount < u_LeftParkVehCount;u_LoopCount++)
      {
        /* Check maximum object gap for qualification */
        if(CML_f_IsNonZero(f_ObjDistRDAverageLeft))
        {
          if((fABS(a_fObjDistRoadBoarderLeft[u_LoopCount])/f_ObjDistRDAverageLeft) > LA_MAX_FACTOR_RD_TO_AVRG)
          {
            /* Big delta found, invalidate parking row */
            b_LeftParkRowValid = FALSE;
          }
          else
          {
            /* no action */
          }
        }
      }
    }
  }

  /* Check for Right Parking Row */
  if(u_RightParkVehCount >= MIN_NUM_OF_DETECTED_PARKING_CARS)
  {
    b_RightParkRowValid = TRUE;
    if(u_RightParkVehCount < MAX_NUM_OF_PARKING_CARS)
    {
      for(u_LoopCount = 0u;u_LoopCount < u_RightParkVehCount;u_LoopCount++)
      {
        /* Sum Distance to road boarder */
        f_ObjDistRDAverageRight += (float32)fABS(a_fObjDistRoadBoarderRight[u_LoopCount]);
      }
      /* Calculate average dist to road boarder */
      f_ObjDistRDAverageRight /= u_RightParkVehCount;

      for(u_LoopCount = 0u;u_LoopCount < u_RightParkVehCount;u_LoopCount++)
      {
        /* Check maximum object gap for qualification */
        if(CML_f_IsNonZero(f_ObjDistRDAverageRight))
        {
          if((fABS(a_fObjDistRoadBoarderRight[u_LoopCount])/f_ObjDistRDAverageRight) > LA_MAX_FACTOR_RD_TO_AVRG)
          {
            /* Big delta found, invalidate parking row */
            b_RightParkRowValid = FALSE;
          }
          else
          {
            /* no action */
          }
        }
      }
    }
  }

  /* Update flag for Object which are detected as Parked Vehicles */
  for(t_ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1);t_ObjNr >= 0;t_ObjNr--)
  {
    /* Get longitudinal displacement of object under consideration */
    f_DistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr);
    t_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(t_ObjNr));
    t_camConfirmationProb = (pt_LAInput->pt_FIPOA->t_ObjList[t_ObjNr].t_CamObjectData.t_CamConfirmationProb);

    /* Check stationary objects */
    if(( (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      || (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif // /* FCT_CFG_SENSOR_TYPE_CAMERA */
       )
       &&(t_camConfirmationProb > (percentage_t)LA_PAR_CAM_CONF_MIN)
       &&(f_DistX > LA_MIN_OBJ_DIST_PARKING_ROW_RB)
      )
    {
      if(b_LeftParkRowValid == TRUE)
      {
        for(u_LoopCount = 0u;u_LoopCount <= u_LeftParkVehCount;u_LoopCount++)
        {
          if(a_tObjParkedLeft[u_LoopCount] == t_ObjNr)
          {
            /* Set Road side Parked Object detection flag*/
            pt_LAOutput->b_RoadSideParkedObj[t_ObjNr] = TRUE;
          }
        }
      }

      if(b_RightParkRowValid == TRUE)
      {
        for(u_LoopCount = 0u;u_LoopCount <= u_RightParkVehCount;u_LoopCount++)
        {
          if(a_tObjParkedRight[u_LoopCount] == t_ObjNr)
          {
            /* Set Road side Parked Object detection flag*/
            pt_LAOutput->b_RoadSideParkedObj[t_ObjNr] = TRUE;
          }
        }
      }
    }
  }
} /* PRQA S 7004 EOF */

#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */

/*************************************************************************************************************************
  Functionname:    LA_v_FindObjInArea                                                            */ /*!

  @brief           Find moving objects with position and velocity inside given boundaries relative to reference object

  @description     Function checks if another moving object with ACC quality can be found inside a rectangle around the 
                   reference object (ObjA). Also, velocity delta of reference object and other objects (ObjB) is 
                   considered.
                   @startuml 
                   partition LA_v_FindObjInArea {
                   start
                      repeat 
                          -Get index in normal FCT list
                   	   if(Check if candidate is not identical to to object handed to function,if it is moving and has acc quality) then (yes)
                   	       -Compute position and velocity delta of object B relative to object A
                   		    if(Check if position and velocity delta of object B relative to object A are whithin boundaries handed to the function) then (yes)
                                   -Store object ID in result array for further computation
                               endif			   
                   	   endif
                      repeat while(for all objects in use)
                   stop
                   @enduml

  @return          void

  @param[in]       t_ObjA : internal object number (Object ID) of a valid reference object [0 ... EM_N_OBJECTS[
                          with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       AreaArgs : reference to arguments defining the rectangle and velocity delta [LA_t_FindObjInAreaArgs]
                              boundaries in which for other objects is looked for
                    AreaArgs->f_DeltaDistXLower Maximum distance delta in negative X direction [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    AreaArgs->f_DeltaDistXUpper Maximum distance delta in positive X direction [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    AreaArgs->f_DeltaDistYLower Maximum distance delta in negative Y direction [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    AreaArgs->f_DeltaDistYUpper Maximum distance delta in positive Y direction [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    AreaArgs->f_DeltaVelLower Velocity delta lower threshold [-330.f ... 330.f] m/s
                    AreaArgs->f_DeltaVelUpper Velocity delta upper threshold [-330.f ... 330.f] m/s
  @param[in]       p_ObjInArea : pointer to array of length LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX with object IDs of objects 
                                 within boundaries [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      p_ObjInArea : pointer to array of length LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX with object IDs of objects 
                                 within boundaries [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @glob_in         OBJ_GET_ACC_FUN_PRESEL_QUALITY(i) : ACC object quality [0u ... 100u] 
                            with i in [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_t_GetNumOfObjectsUsed : number of objects [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_LONG_VREL(i) : Relative velocity of object i [-330.f ... 330.f] m/s
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pf_GetObjLatDisp(i) : Lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pf_GetObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_DYNAMIC_PROPERTY(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pu_GetDistXSortedObj(i) : number of object i in dist-x sorted list [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                            with i in [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : DTR spercific object selection
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
#if (LA_CFG_AVOID_SPILT_OBJ)
void LA_v_FindObjInArea(ObjNumber_t p_ObjInArea[], const ObjNumber_t t_ObjA, LA_t_FindObjInAreaArgs  const* const AreaArgs, boolean b_NoQualityCheck)
#else
void LA_v_FindObjInArea(ObjNumber_t p_ObjInArea[], const ObjNumber_t t_ObjA, LA_t_FindObjInAreaArgs  const* const AreaArgs)
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
{
  ObjNumber_t t_ObjBSorted;                     /* Index in range sorted FCT list                              */
  ObjNumber_t t_NumOfObjectsUsed;
  ObjNumber_t t_ObjB;                           /* Index of object B in normal FCT list                        */
  float32 f_DeltaDistX;                         /* Longitudinal displacement of object B relative to object A  */
  float32 f_DeltaDistY;                         /* Lateral displacement of object B relative to object A       */
  float32 f_DeltaVel;                           /* Velocity of object B relative to object A                   */
  uint8 u_ResultArrayIndex;                     /* index of current position of object in result array         */
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty; /* Dynamic property of of object B */
#if (LA_CFG_DTR_OBJ_SELECTION)
  boolean b_DTRPreSelect;                       /* DTR project specific object quality */
#else
  uint8 u_ObjBQuality;                          /* ACC object quality */
#endif
  
  /* Initialize result array with default values                                            */
  for (u_ResultArrayIndex = 0u; (u_ResultArrayIndex < LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX); u_ResultArrayIndex++)
  {
    p_ObjInArea[u_ResultArrayIndex] = (ObjNumber_t)-1;
  }

  /* Initialize result array index value with zero                                          */
  u_ResultArrayIndex = (uint8)0;

  /* Loop over range sorted FCT list so that the result of this function is independant of  */
  /* object position in normal FCT list.                                                    */
  /* In SLATE_pu_GetDistXSortedObj[i] "empty" objects have index -1.                         */
  /* They are at the end of the list. That is why we loop over OBJ_NUMBER_OF_OBJ_USED       */
  t_NumOfObjectsUsed = SLATE_t_GetNumOfObjectsUsed();
  for(t_ObjBSorted = 0; (t_ObjBSorted < t_NumOfObjectsUsed) && (u_ResultArrayIndex < LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX); t_ObjBSorted++)
  {
    /* Get index in normal FCT list */
    t_ObjB = *SLATE_pu_GetDistXSortedObj(t_ObjBSorted); 
    t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(t_ObjB));
#if (LA_CFG_DTR_OBJ_SELECTION)
    b_DTRPreSelect = LA_b_DTRPreselectCrit(t_ObjB); //ToBeDiscussed
#else
    u_ObjBQuality = SLATE_u_GetAccQuality(t_ObjB);
#endif

    /* Check if candidate is not identical to to object handed to function,if it is moving  */
    /* and has acc quality                                                                  */
    if ( (t_ObjB != t_ObjA)
      && (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
#if (LA_CFG_DTR_OBJ_SELECTION)
      && (b_DTRPreSelect == TRUE) 
#else
#if (LA_CFG_AVOID_SPILT_OBJ)
      && (((u_ObjBQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL) && (b_NoQualityCheck == FALSE)) || (b_NoQualityCheck == TRUE))
#else
      && (u_ObjBQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
#endif
       )
    {
      /* Compute position and velocity delta of object B relative to object A                 */
      f_DeltaDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjB) - *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjA);
      f_DeltaDistY  = *pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjB) - *pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjA);
      f_DeltaVel    = *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjB)   - *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjA);

      /* Check if position and velocity delta of object B relative to object A               */
      /* are whithin boundaries handed to the function                                       */
      if ( (f_DeltaDistX > (AreaArgs->f_DeltaDistXLower))
        && (f_DeltaDistX < (AreaArgs->f_DeltaDistXUpper))
        && (f_DeltaDistY > (AreaArgs->f_DeltaDistYLower))
        && (f_DeltaDistY < (AreaArgs->f_DeltaDistYUpper))
        && (f_DeltaVel   > (AreaArgs->f_DeltaVelLower))
        && (f_DeltaVel   < (AreaArgs->f_DeltaVelUpper))
         )
      {
        /* Store object ID in result array for further computation                           */
        p_ObjInArea[u_ResultArrayIndex] = t_ObjB;
        u_ResultArrayIndex++;
      }
    }
  }
}

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjDistToCCCriteria                                                            */ /*!

  @brief           If the curvature change information available check if object is below the distance 
                   where a high curvature change is defined.

  @description     If the curvature change information available check if object is below the distance 
                   where a high curvature change is defined.
                   @startuml 
                   partition LA_b_CheckObjDistToCCCriteria {
                   start
                      -If the curvature change information available check if object is below the distance where a high curvature change is defined.
                   stop
                   @enduml

  @return          bRet : boolean if object is below the distance to a high curvature change [TRUE, FALSE]

  @param[in]       t_Obj : internal object number (Object ID) of a valid reference object [0 ... EM_N_OBJECTS[
                          with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         pt_LAInput->pt_FIPCC->b_FusedDistToHighCCValid : valid flag for distance to high curvature flag [TRUE, FALSE]
  @glob_in         pt_LAInput->pt_FIPCC->f_FusedDistToHighCC : x-distance to high curvature [0.f ... 5*RW_FCT_MAX]
  @glob_in         *SLATE_pf_GetObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    240:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-240-00061542 \n
                   233:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-233-00061542 \n
                   213:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-213-00061542 \n

  @created         08.06.2017
  @changed         08.06.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
boolean LA_b_CheckObjDistToCCCriteria(const ObjNumber_t t_Obj)
{
  /* Internal variables */
  boolean b_return = TRUE; /* Default value TRUE i.e. object is closer than distance to high curvature change */ 

  /* Global inputs from outside LA */
  float32 f_ObjLongDisp                    = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_Obj);       /* Get longitudinal displacement of t_Obj */
  float32 f_EgoVelObjSync                  = *pt_LAInput->t_RTE.pf_EgoVelObjSync;            /* Get ego velocity */
  boolean b_DistToHighCurvatureChangeValid = pt_LAInput->pt_FIPCC->b_FusedDistToHighCCValid; /* Valid flag for distance to high curvature change */ 
  float32 f_DistToHighCurvatureChange      = pt_LAInput->pt_FIPCC->f_FusedDistToHighCC;      /* Distance to high curvature change (curve entry/exit) */

  if (b_DistToHighCurvatureChangeValid == TRUE)
  {
    if ( (f_ObjLongDisp > f_DistToHighCurvatureChange)
      && (f_ObjLongDisp > (LA_DIST_TO_HIGH_CC_CRIT_TG_MIN * f_EgoVelObjSync) )
      )
    {
      /* Object is above the distance where a high curvature change is defined */
      b_return = FALSE;
    }
  }

  return b_return;
}
#endif

#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
/*************************************************************************************************************************
  Functionname:    LA_v_CalculateOrientationEffect                                                                     */ /*!

  @brief           Calculates the projection of the object onto EGO lane taking into account the orientation of the object

  @description     Calculates the projection of an object taking into account the orientation of the object. Further constraints 
                   include type of the object, position of the object i.e., if it is traveling to the right or left of the trajectory 
                   and curvature of the trajectory (Strong curvatures can induce false projections of the object).
                   @startuml 
                   partition LA_v_CalculateOrientationEffect {
                   start
                      if(AbsObjectWidth is greater than C F32 DELTA) then (yes)
                           if(object is classified as truck) then (yes)
                   	        -Typically trucks are assigned a length of 18m, since we're only considering objects within 10m, we use a reduced value in our computations
                   	    endif
                   	    if(Object is on right lane) then (yes)
                   	       -Object on right lane will only be considered when they have both orientation and Vrel_Y positive
                   		   -In case EGO is traveling in a left curve then the traj2Obj limit is reduced 
                   		elseif(Object is on left lane) then (yes)
                   		   -Object on left lane will only be considered when they have both orientation and Vrel_Y negative
                   		   -In case EGO is traveling in a right curve then the traj2Obj limit is reduced
                   		elseif(Object is on Ego lane) then (yes)
                   		   -Object on Ego lane will only be considered when Ego steering towards the object
                         -In case Ego Indicator is switched on towards object’s direction
                   		else
                   		endif
                   		-The orientation must be always computed towards the EGO lane so that any object trying to cut out will have a smaller projection.However, for the sake of simplicity, this aspect is omitted and absolute value of orientation is used. This may result in keeping objects longer when they try to cut out, but Trade-OFF is achieved since only objects within 10m are affected
                      else
                          -set object projection to 0
                      endif
                   stop
                   @enduml


  @return          static void

  @param[in]       Obj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in,out]   pDistanceWidth : reference to structure containing information about object width, 
                   the relationship between its position and Trajectory [LADistanceWidth_t as defined in cp_ext.h]
                      fObjectWidth : Width of the Object based on it class [0.f ... RW_FCT_MAX] m

  @glob_in         pt_LAInput->t_RTE.pf_ObjOrientation(i) : Orientation of the object i [-PI ... PI]
  @glob_in         OBJ_LAT_VREL(i) : Lateral relative velocity of object i [-330.f ... 330.f] m/s
  @glob_in         *SLATE_pt_GetObjClassification(i) : object class [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX(i) : get object number of object of interest [0 ... EM_N_OBJECTS[
                       with i in [0 ... OOI_NUMBER_OF_OOI[ as defined in aiOOIList_array_t in Rte_Type.h and si_ext.h
  @glob_out        None 

  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST    : FCT switch for EM ARS object list
  @c_switch_part   LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0    : Switch disabling orientation if OOI intends to cut out
  @c_switch_part   LA_CFG_TURN_INDICATOR_COUNTER    : Switch to access the Indicator Timer
  @c_switch_full   LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS : Configuration switch allowing the use of object orientation angle(OOA) in overlap and occupancy calculations for objects that are in NEAR region
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.02.2016
  @changed         19.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void LA_v_CalculateOrientationEffect(const ObjNumber_t iObj, LADistanceWidth_t *pDistanceWidth)
{
  const float32 fAbsObjectWidth     = fABS(pDistanceWidth->fObjectWidth);
  float32 fObjectProjection, fAngleToFrontEdge, fObjectLength, fObjectOrientation;
  boolean bEGOTravellingInAStrongCurve = FALSE;
  float32 f_ObjVrelY = (*pt_LAInput->t_RTE.pf_ObjVrelY(iObj));   /*   Get relative lateral velocity of the object   */
  SLATE_t_Obj_CLassification t_ObjClassification = *pt_LAInput->t_RTE.pt_ObjClassification(iObj);     /*  Get the classification of the object   */
#if(LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0)
  FIP_t_FusedRoadType t_FusedRoadType = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
  float32 f_Curve = pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0;  /* Trajectory Curve*/
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync; /* Ego velocity */
#if(LA_CFG_TURN_INDICATOR_COUNTER)
  float32 f_IndTimeLeft = pt_LAOutput->f_TurnIndLeftTime; /*Left Indicator timer  */
  float32 f_IndTimeRight= pt_LAOutput->f_TurnIndRightTime;/*Right Indicator timer  */
#endif /*LA_CFG_TURN_INDICATOR_COUNTER */
#endif /*LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0 */
  if(fAbsObjectWidth > C_F32_DELTA)
  {
    fObjectLength = (pt_LAInput->pt_FIPOA->t_ObjList[iObj].fObjectLength);      /* Get the length of the object, based on its class */
    fObjectOrientation = (pt_LAInput->t_RTE.pf_ObjOrientation(iObj));   /* Get the orientation of the object */
    fAngleToFrontEdge = ATAN_(pDistanceWidth->fObjectWidth/fObjectLength);
    

    if (t_ObjClassification == SLATE_OBJCLASS_TRUCK)
    {
      /* Typically trucks are assigned a length of 18m, since we're only considering objects within 10m, we use a reduced value in our computations */
      fObjectLength = fObjectLength/2.f;

      /* if (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) < LA_MIN_TRUCK_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT)
      {
        If the Object is a Truck and its longitudinal distance is less than 4m - DO NOT USE Orientation for overlap computation
        fObjectOrientation = 0.f;
      } */
    }

    /* Check if Object is on right lane */
    if ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_RIGHT_OOI) == iObj) || ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_RIGHT_OOI) == iObj)))
    {
      /* Object on right lane will only be considered when they have both orientation and Vrel_Y positive, i.e., towards EGO lane */
      if ((fObjectOrientation < C_F32_DELTA) && (f_ObjVrelY < C_F32_DELTA))
      {
        /* Disregard orientation in overlap computation - NOTE:  IF condition NEGATIVE */
        fObjectOrientation = 0.f;
      } /* END IF orientation is positive */
      
      /* In case EGO is traveling in a left curve then the traj2Obj limit is reduced */
      if(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0 > LA_MAX_CURVATURE_CUT_IN_LAT_DISPLACEMENT)
      {
        bEGOTravellingInAStrongCurve = TRUE;
      } /* END IF EGO is traveling in a left curve */

    } /* Check if Object is on left lane */
    else if ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_LEFT_OOI) == iObj) || ((OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_LEFT_OOI) == iObj)))
    {
      /* Object on left lane will only be considered when they have both orientation and Vrel_Y negative, i.e., towards EGO lane */
      if ((fObjectOrientation > -C_F32_DELTA) && (f_ObjVrelY > -C_F32_DELTA))
      {
        /* Disregard orientation in overlap computation - NOTE:  IF condition NEGATIVE */
        fObjectOrientation = 0.f;
      } /* END IF orientation is negative */

      /* In case EGO is traveling in a right curve then the traj2Obj limit is reduced */
      if(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0 < -LA_MAX_CURVATURE_CUT_IN_LAT_DISPLACEMENT)
      {
        /*fObjectOrientation = 0.f;*/
        bEGOTravellingInAStrongCurve = TRUE;
      } /* END IF EGO is traveling in a right curve */
    } 
#if(LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0)
    /* Object is relevant (OOI-0) */
    else if( (OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI) == iObj) )
    {
      /* Ego velocity is less and road type is City */
      if (   (f_EgoVelObjSync < LA_OBJECT_ORIENTATION_NEAR_OBJECTS_FOR_OOI0_EGOVEL) 
          && (t_FusedRoadType == FIP_ROAD_TYPE_CITY) )
      {
        /* Object orientation is towards right and Ego is not turning to right or Ego left indicator is on */
        if(  ( (fObjectOrientation  < -C_F32_DELTA)
          && (   (f_Curve > -LA_OBJECT_ORIENTATION_NEAR_OBJECTS_FOR_OOI0_CURVE)
#if(LA_CFG_TURN_INDICATOR_COUNTER)
              || (f_IndTimeLeft > LA_EGO_LANE_CHANGE_IND_TIMER_ZERO)
#endif/*LA_CFG_TURN_INDICATOR_COUNTER */
             ) 
             )
             /* Object orientation is towards left and Ego is not turning to left or Ego right indicator is on */
          || ( (fObjectOrientation  > C_F32_DELTA)
          && (   (f_Curve < LA_OBJECT_ORIENTATION_NEAR_OBJECTS_FOR_OOI0_CURVE)
#if(LA_CFG_TURN_INDICATOR_COUNTER)
              || (f_IndTimeRight > LA_EGO_LANE_CHANGE_IND_TIMER_ZERO)
#endif/*LA_CFG_TURN_INDICATOR_COUNTER */
             )
             )
           )
         {
           fObjectOrientation = 0.f;
         }
      }
    }
#endif /*LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0 */
    else
    {
      /* DO NOTHING - Inserted to conform with MISRA/QAC */
    }/* END IF check for objects on adjacent lanes */
    
    /* The orientation must be always computed towards the EGO lane so that any object trying to cut out will have a smaller projection.
       However, for the sake of simplicity, this aspect is omitted and absolute value of orientation is used. 
       This may result in keeping objects longer when they try to cut out, but Trade-OFF is achieved since only objects within 10m are affected */
    if (bEGOTravellingInAStrongCurve == TRUE)
    {
      /* DO NOT use orientation or AngleToFrontEdge since EGO is in a strong curve and angle based overlap is not optimal under such circumstances */
      fObjectProjection = (pDistanceWidth->fObjectWidth)/2.f;
    } 
    else
    {
      fObjectProjection = SIN_HD_(fAngleToFrontEdge + fABS(fObjectOrientation))*fObjectLength;
    }
  }
  else
  {
    fObjectProjection = 0.f;
  }
  pDistanceWidth->fObjectWidth = fObjectProjection * 2.F;

}
#endif  /* LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS */

/*************************************************************************************************************************
  Functionname:    LA_b_FusedLaneAssociation                                                                        */ /*!

  @brief           Fuses the lane association information from different sources: geometrical (inlap based), predicted and camera 
                   lane association.

  @description     Fuses the lane association information of geometrical (inlap based), predicted and camera 
                   lane association into one single lane association. It differentiates between two states: dependent on the 
                   result of the fused lane association from the last cycle (LAInlaneState) either an outlane-to-inlane transition 
                   (e.g. cut-in) or an inlane-to-outlane (e.g. release) transition is considered. In case a change in the state is detected, 
                   the signals LAInlaneState/LAActLaneState are updated. LAInlaneState is the one considered by the functional
                   lane association, while LAActLaneState is only used for visualisation. Only for the case of a transition of 
                   from inlane to outlane the inlane-timer is reseted and the outlane-counter is updated.
                   @startuml
                   partition LA_b_FusedLaneAssociation
                   start
                   :Initialize the variables for Inlane and Outlane inlap value, inlane time value and 
                   adjacent thresholds with stored values from geometric lane association;
                   :Calculate inlane time threshold
                   **LA_f_GetInLaneTimeThreshold**;
                   partition FCT_CFG_CAMERA_OBJECT_DETECTION {
                   :Decrease pick-up threshold, since camera already set object in-lane;
                   :Increase drop threshold, since camera set object to out-lane;
                   :Adapt the inlap pickup threshold for cutIn
                   **LA_f_AdaptObjInlapPickupThresholdForCutIn**;
                   :Store new inlap pickup and drop thresholds with camera fusion;
                   :Check inlap pickup and drop value with camera fusion for object
                   **LA_b_CheckObjInlapPickupValue**
                   **LA_b_CheckObjInlapDropValue**
                   and store it;
                   :Adapt inlane timer with camera information
                   **LA_f_AdaptInLaneTimeThresholdCam**;
                   }
                   :Check inlane timer and inlane distance
                   **LA_b_CheckInlaneTimer**
                   **LA_b_CheckInlaneDistance**;
                   :Update inlane timer
                   **LA_v_UpdateInlaneTimer**;
                   :Set geometrical inlap based inlane criteria flag
                   **LA_v_GeometricLaneAssocStateFlow**;
                   stop
                   @enduml
  @return          static void

  @param[in]       Obj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLInlapValue : Inlane inlap flag [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLCamValue : Inlane camera satisfied [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLTimeValue : Inlane timer satisfied [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLDistValue : Inlane Distance satisfied [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLCustomValue : Inlane custom flag (predicted inlane) [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.OutLInlapValue : Outlane inlap flag [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].t_Bool.OutLCustomValue : Outlane custom flag (predicted outlane) [TRUE, FALSE]
  @glob_in         OBJ_ARS_SENSORSPECIFIC(i).ucMeasuredSources : information if object is measured in the current cycle [EM_t_ARS_MeasuredSources as per Rte_Type.h]
  @glob_in         OBJ_ATTRIBUTES(i).uiClassConfidence : Confidence of object class [ucConfidence_t as defined in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjTrajRelation.fInlap : Inlap value [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]m
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].f_ObjInlapDropThresh : Inlap drop threshold [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_M]m
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.Inlap_In2OutlaneCounter : Inlap in-to-outlane counter [0u ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.In2OutlaneTransition : In-to-outlane transtion counter [0u ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]
                      used in cut-in potential calculation [0, LA_IN2OUTLANE_MAX_TRANSITIONTIME]

  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAActLaneState : State if object i is geometrically inlane [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.Inlap_In2OutlaneCounter : Inlap in-to-outlane counter [0u ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.In2OutlaneTransition : In-to-outlane transtion counter [0u ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]

  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE : usage of object turn indicator signal in SLATE
  @c_switch_part   LA_CFG_DELAY_PRED_LANE_ASSOC : Configuration switch to delay the predicted lane association
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             All single lane association criteria updated for current cycle

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2018
  @changed         12.02.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static void LA_b_FusedLaneAssociation(const ObjNumber_t iObj)
{
  boolean bInLaneOcc       = FALSE;
  boolean bPredInLaneAssoc = FALSE;
  
  boolean b_InLInlapValue  = (boolean)pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLInlapValue;
  boolean b_OutLInlapValue = (boolean)pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.OutLInlapValue;

  boolean b_InlaneDistValue = FALSE;
  boolean b_InlaneTimeValue = FALSE;

#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
  uint8 u_In2OutlaneCounterThreshold = 0u; 
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */

  float32 f_ObjInlapDropThresh = pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapDropThresh;

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  float32 f_ObjInlapPickupThresh = pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapPickupThresh;
  const LA_t_TrajInlap *p_Inlap = &(pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajRelation);
#endif

  fTime_t fTimeThreshInLane = LA_f_GetInLaneTimeThreshold(iObj);

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  /* Adapt inlap thresholds with camera information */

  /* Pick-Up */
  if( (*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_STATIONARY)  
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
   || (*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
    )
  {
    /* Pick-Up Threshols for standing vehicles */
    if( LA_b_CheckCameraObjAssoToEgoLane(iObj) == TRUE )
    {
      /* Decrease pick-up threshold, since camera already set object IN-LANE */
      f_ObjInlapPickupThresh *= LA_PAR_CAM_ASSIGN_IN_LANE_PICKUP_THRES_STAT;
    }
    else if( LA_b_CheckCameraObjAssoToOutLane(iObj) == TRUE )
    {
      /* Increase pick-up threshold, since camera set object to OUT-LANE */
      f_ObjInlapPickupThresh *= LA_PAR_CAM_ASSIGN_OUT_LANE_PICKUP_THRES_STAT;
    }
    else
    {
        /*Do nothing for QAC */
    }
  }
  else
  {
    /* Pick-Up Threshols for moving vehicles */
    if ( ( LA_b_CheckCameraObjAssoToEgoLane(iObj) == TRUE )
       )
    {
      /* Decrease pick-up threshold, since camera already set object in-lane */
      f_ObjInlapPickupThresh *= LA_PAR_CAM_LANE_ASSIGN_PICKUP_THRES_FACTOR_INLAP;
    }
  }

  if ( (LA_b_CheckCameraObjAssoToOutLane(iObj) == TRUE)
     )
  {
    f_ObjInlapDropThresh = (f_ObjInlapDropThresh)/(LA_OUTLANE_INLAP_MUL_FACT);
  }

  f_ObjInlapPickupThresh = LA_f_AdaptObjInlapPickupThresholdForCutIn(iObj, f_ObjInlapPickupThresh);

  /* store inlane and outlane threshold values with camera fusion*/
  pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapPickupThresh = f_ObjInlapPickupThresh;
  pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapDropThresh = f_ObjInlapDropThresh;
#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[iObj].fObjInlapPickupThreshSIM = f_ObjInlapPickupThresh;
  pt_LAOutput->t_LAObjOutputList[iObj].fObjInlapDropThreshSIM = f_ObjInlapDropThresh;
#endif

  /* get inlane and outlane inlap information with new thresholds and use camera influenced values for further calculations */
  b_InLInlapValue = LA_b_CheckObjInlapPickupValue(p_Inlap, f_ObjInlapPickupThresh);
  b_OutLInlapValue = LA_b_CheckObjInlapDropValue(p_Inlap, f_ObjInlapDropThresh);

  /*store inlane and outlane inlap information with new thresholds */
  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLInlapValue = b_InLInlapValue;
  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.OutLInlapValue = b_OutLInlapValue;

  /* Adapt inlane timer with camera information */
  fTimeThreshInLane = LA_f_AdaptInLaneTimeThresholdCam(iObj, fTimeThreshInLane);
  pt_LAOutput->t_LAObjOutputList[iObj].fInLaneTimeThres = fTimeThreshInLane;
#endif

  /*In case the inlap criteria is TRUE, the in-lane time and the in-lane distance criteria are checked, otherwise they are set to FALSE. */
  if (b_InLInlapValue == TRUE)
  {
    b_InlaneTimeValue = LA_b_CheckInlaneTimer(iObj, fTimeThreshInLane);
    LA_v_UpdateInlaneTimer(iObj, fTimeThreshInLane);
    b_InlaneDistValue = LA_b_CheckInlaneDistance(iObj);
  }
  else
  {
    b_InlaneTimeValue = FALSE;
    b_InlaneDistValue = FALSE;
  }
  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLTimeValue = b_InlaneTimeValue;
  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLDistValue = b_InlaneDistValue;

  LA_v_GeometricLaneAssocStateFlow(iObj, b_InLInlapValue);

  if (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.In2OutlaneTransition > 0u)
  {
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.In2OutlaneTransition = pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.In2OutlaneTransition - 1u;
  }
  else
  {
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.In2OutlaneTransition = 0u;
  }

  switch(pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState)
  {
    case OBJ_STATE_OUTLANE:

    if ( ( (b_InLInlapValue == TRUE)
        && ( (b_InlaneTimeValue == TRUE)
          || (pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLDistValue == TRUE)
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
          || (pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLCamValue == TRUE)
#endif
           )
         )
      || (pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLCustomValue == TRUE)
       )
    {
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      if (OBJ_ARS_SENSORSPECIFIC(iObj).ucMeasuredSources != ARS_MEAS_SEN_NONE)
      /* Prevent assignment to ego lane of objects that are not measured in the current
         cycle. This prevents some nasty predicted drop-ins
         if (!(OBJ_IS_MEASURED(iObj, (ARS_MEAS_SEN_FARSCAN | ARS_MEAS_SEN_NEARSCAN | ARS_MEAS_SEN_GRID | ARS_MEAS_SEN_CAM)))) */
#endif
      {
        pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState  = OBJ_STATE_INLANE;
        pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAActLaneState = OBJ_STATE_INLANE;
      }
    }
    break;

    case OBJ_STATE_INLANE:

    if ( ( b_OutLInlapValue == TRUE)
      || (pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.OutLCustomValue == TRUE) )
    {
      /* At least one of the out-lane criteria satisfied : object may be making transition
      from in-lane to out-lane state. Next we need to check in-lane criteria, since if those
      aren't met, then the transition is OK */
      bInLaneOcc       = b_InLInlapValue;
      bPredInLaneAssoc = (boolean)pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLCustomValue;

      if ( (bInLaneOcc       == TRUE) 
        || (bPredInLaneAssoc == TRUE) )
      {
       /* Since in-lane criteria satisfied as well, these overrule the out-lane criteria */
       /*Do Nothing, Preserve last lane state of the object */
       pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = 0u;
      }
      else
      {
        pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter + 1u;
#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
        /*Outlane counter threshold based on situation */
        u_In2OutlaneCounterThreshold = LA_u_GetObjOutlaneCounterThreshold(iObj,u_In2OutlaneCounterThreshold);
        if ( (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter >= u_In2OutlaneCounterThreshold)
#else
        if ( (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter >= LA_OUTLANE_CYCLE_MIN)
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */     
          || (pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.OutLCustomValue == TRUE)
           )
        {
          /* In-lane criteria not satisfied : object really making transition from in-lane to out-lane */
          pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState  = OBJ_STATE_OUTLANE;
          pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAActLaneState = OBJ_STATE_OUTLANE;

          /* object actually changes from inlane to outlane -> set timer */
          pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = 0u;
          /* Update timer and distance information if out-lane inlap flag set */
          LA_v_ResetInlaneTimer(iObj);
          LA_v_ResetInlaneDistance(iObj);

          if ( ( (pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajRelation.fInlap) < ( ( f_ObjInlapDropThresh) * (LA_OUTLANE_INLAP_MUL_FACT) ) )
            || (SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence <= LA_MIN_INOUT_CLASS_CONFIDENCE)
             )
          {
            pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = LA_IN2OUTLANE_MAX_TRANSITIONTIME;
          }

          pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.In2OutlaneTransition = LA_IN2OUTLANE_MAX_TRANSITIONTIME;
        }
      }
    }
    else
    {
     /* Neither out-lane criteria satisfied : return FALSE (no state transition) */
     pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = 0u;
    }
    break;

    default:
    break;
  }
}

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
/*************************************************************************************************************************
  Functionname:    LA_b_CheckNarrowHighwayCriteria                                                            */ /*!

  @brief           Checks if object will likely generate a false positive event on a narrow highway e.g. the Brenner highway

  @description     In case the object fulfills the characteristics of a likely false positive event on a narrow highway, the return value is set
                   to FALSE. This information is used to tighten the ego-lane association criteria e.g. the in-lane time threshold is increased, the predicted
                   pick-up is turned off and the object specific pick-up range is set to a minimum. Currently, the logic is tuned for the Brenner highway i.e. a
                   highway with a guardrail which is very close to the road and when ego is driving close to the road border.
                   @startuml
partition LA_b_CheckNarrowHighwayCriteria
start
     if(TrafficOrientation is equal to SLATE TRAFFIC ORIENTATION RIGHT 
	    and RoadDistLeft is less than LA NARROW HIGHWAY CRIT DIST TO ROAD BORDER and NumOfLaneLeft is 0 and NumOfLaneRight is not 0) then (yes)
         -set DistToRoadBorderCrit to TRUE
     else if(TrafficOrientation is equal to SLATE TRAFFIC ORIENTATION LEFT and RoadDistRight is greater than -LA NARROW HIGHWAY CRIT DIST TO ROAD BORDER
              and NumOfLaneRight is 0 and NumOfLaneLeft is not 0) then (yes)
         -set DistToRoadBorderCrit to TRUE;
     else
     endif
   
    if(DistToRoadBorderCrit is TRUE and RoadTypeLevel is FIP ROAD TYPE HIGHWAY and EgoVelObjSync greater than LA NARROW HIGHWAY CRIT VEGO MIN
		and EgoVelObjSync less than LA NARROW HIGHWAY CRIT VEGO MAX) then (yes)
        -Get absolute velocity of object 
        -Compute time-gap (TG) based distance above which more stringent ego lane association criteria shall be applied. 
        -Dependent on the range factor the distance can be lowered even below the minimum time-gap based ACC range. 
        -Compute object relative velocity dependent distance above which more stringent ego lane association criteria shall be applied.
	endif
    
    if (ObjDynProperty is ARS_OBJECT_PROPERTY_MOVING and
        VelObj is greater than LA_NARROW_HIGHWAY_CRIT_VOBJ_MIN and 
        VelObj is less than LA_NARROW_HIGHWAY_CRIT_VOBJ_MAX and
        ObjLongDisp is greater than f_TGBasedDistThres and
        ObjLongDisp is greater than f_VrelBasedDistThres and
        VrelX is greater than LA_NARROW_HIGHWAY_VREL_MIN and
        ArelX is greater LA_NARROW_HIGHWAY_AREL_MIN ) then (yes)
    
      if (TrafficOrientation is SLATE_TRAFFIC_ORIENTATION_RIGHT)
        -Loop over all objects to check if object is overtaking 
        -Use area definition for right-hand traffic 
      else
        -Loop over all objects to check if object is overtaking 
        -Use area definition for left-hand traffic 
	  endif

      if (possible overtaken object has been found )
        -No possibly overtaken object has been found: object is likely on neighboring lane.
      
      else
        -Check if object found is likely a mirror 
      endif

        -If a second object has been found, object under consideration is probably a mirror and should be suppressed 
        -Check can be replaced with: a_CloseObjID[0]
    endif
 
stop
@enduml

  @return          b_return : boolean if for input object narrow highway criteria shall not be applied [TRUE, FALSE]

  @param[in]       t_Obj : internal object number (Object ID) of a valid reference object [0 ... EM_N_OBJECTS[
                          with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         *pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY            [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i                    [-330.f ... 330.f] m/s
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h 
  @glob_in         *pt_LAInput->t_RTE.pf_ObjArelX(i) : Relative longitudinal acceleration of object i  [-100.0f ... 100.0f] m/s^2
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h 
  @glob_in         *pt_LAInput->t_RTE.pt_ObjDynamicProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h 
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         *pt_LAInput->t_FIPTO.pt_FIPTrafficOrientation : FIP Fused Traffic Orientation Value [Full Range of datatype eTrafficOrientation_t as defined in Rte_Type.h]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border [0.f ... 30.f]
  @glob_in         *pt_LAInput->t_FIPLaneMatrix.ps_NumOfLaneLeft : Reference to FIP number of lanes on the left [-1 ... Maximum range of datatype]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [0.f ... 30.f]
  @glob_in         *pt_LAInput->t_FIPLaneMatrix.ps_NumOfLaneRight : Reference to FIP number of lanes on the right [-1 ... Maximum range of datatype]
  @glob_in         pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f]
  @glob_out        -

  @c_switch_full   LA_CFG_NARROW_HIGHWAY_CRITERIA : LA switch for narrow highway criteria check

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.10.2017
  @changed         17.10.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
boolean LA_b_CheckNarrowHighwayCriteria(const ObjNumber_t t_Obj)
{
  /* Internal variables */
  boolean     b_return = TRUE;                                   /* Default return value is TRUE i.e. narrow highway criteria shall not be applied */
  boolean     b_DistToRoadBorderCrit = FALSE;                    /* Distance to road border criteria */
  ObjNumber_t a_OvertakenObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX]; /* Array of objects possibly overtaken by t_Obj */
  ObjNumber_t a_CloseObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX];     /* Array of objects possibly causing a mirror */
  float32     f_TGBasedDistThres;                                /* Time-gap based distance above which more stringent ego lane association criteria shall be applied */
  float32     f_VrelBasedDistThres;                              /* Object relative velocity dependent distance above which more stringent ego lane association criteria shall be applied */
  float32     f_VelObj;                                          /* Absolute velocity of object t_Obj */

  /* Global inputs from outside LA */
  const float32                     f_EgoVelObjSync      = *pt_LAInput->t_RTE.pf_EgoVelObjSync;             /* Get ego velocity */
  const float32                     f_ObjLongDisp        = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_Obj);        /* Get longitudinal displacement of t_Obj */
  const float32                     f_VrelX              = *pt_LAInput->t_RTE.pf_ObjVrelX(t_Obj);           /* Get relative velocity of t_Obj */
  const float32                     f_ArelX              = *pt_LAInput->t_RTE.pf_ObjArelX(t_Obj);           /* Get relative longitudinal acceleration of t_Obj */
  const SLATE_t_Obj_DynamicProperty t_ObjDynProperty     = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(t_Obj); /* Get dynamic property of t_Obj */
  const FIP_t_FusedRoadType         t_RoadTypeLevel_1    = pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType;     /* Get road type */
  const SLATE_t_TrafficOrientation  t_TrafficOrientation = pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation;   /* Get traffic-orientation */
  const sint8                       i_NumOfLaneLeft      = pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft;   /* Get number of left lanes */
  const sint8                       i_NumOfLaneRight     = pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight;  /* Get number of right lanes */
  const float32                     f_RoadDistLeft       = pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft;                /* Get distance to left road border */
  const float32                     f_RoadDistRight      = pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight;               /* Get distance to right road border  */

  /* Check distance to road border criteria dependent on traffic orientation*/
  if ( (t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT)
    && (f_RoadDistLeft < LA_NARROW_HIGHWAY_CRIT_DIST_TO_ROAD_BORDER)
    && (i_NumOfLaneLeft == (sint8)0)
    && (i_NumOfLaneRight != (sint8)0)
    )
  {
    b_DistToRoadBorderCrit = TRUE;
  }
  else if ( (t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT)
         && (f_RoadDistRight > -LA_NARROW_HIGHWAY_CRIT_DIST_TO_ROAD_BORDER)
         && (i_NumOfLaneRight == (sint8)0)
         && (i_NumOfLaneLeft != (sint8)0)
          )
  {
    b_DistToRoadBorderCrit = TRUE;
  }
  else
  {
    /* Traffic direction unknown. Do not consider narrow highway criteria in this case. */
  }

  /* Check general constraints for the narrow highway criteria */
  if ( (b_DistToRoadBorderCrit == TRUE)
    && (t_RoadTypeLevel_1 == FIP_ROAD_TYPE_HIGHWAY)
    && (f_EgoVelObjSync > LA_NARROW_HIGHWAY_CRIT_VEGO_MIN)
    && (f_EgoVelObjSync < LA_NARROW_HIGHWAY_CRIT_VEGO_MAX)
     )
  {
    /* Get absolute velocity of object */
    f_VelObj = f_EgoVelObjSync + f_VrelX;

    /* Compute time-gap (TG) based distance above which more stringent ego lane association criteria shall be applied. */
    /* Dependent on the range factor the distance can be lowered even below the minimum time-gap based ACC range. */
    f_TGBasedDistThres = f_EgoVelObjSync * LA_ACC_RANGE_TIMEGAP_MIN_MOVING * (1.f - (LA_NARROW_HIGHWAY_CRIT_RANGE_FAC_WEIGHT * pt_LAOutput->fRangeFac) );

    /* Compute object relative velocity dependent distance above which more stringent ego lane association criteria shall be applied. */
    f_VrelBasedDistThres = dGDBmathLineareFunktion( &LA_NarrowHighwayVrelBasedDistThres, f_VrelX);

     /* Check object specific criteria */
    if ( (t_ObjDynProperty == ARS_OBJECT_PROPERTY_MOVING)
      && (f_VelObj > LA_NARROW_HIGHWAY_CRIT_VOBJ_MIN)
      && (f_VelObj < LA_NARROW_HIGHWAY_CRIT_VOBJ_MAX)
      && (f_ObjLongDisp > f_TGBasedDistThres)
      && (f_ObjLongDisp > f_VrelBasedDistThres)
      && (f_VrelX > LA_NARROW_HIGHWAY_VREL_MIN)
      && (f_ArelX > LA_NARROW_HIGHWAY_AREL_MIN)
       )
    {
      if (t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT)
      {
        /* Loop over all objects to check if object is overtaking */
        /* Use area definition for right-hand traffic */
#if (LA_CFG_AVOID_SPILT_OBJ)
        LA_v_FindObjInArea(a_OvertakenObjID, t_Obj, &LA_OvertakingCheckArgs, FALSE);
#else
        LA_v_FindObjInArea(a_OvertakenObjID, t_Obj, &LA_OvertakingCheckArgs);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
      }
      else
      {
        /* Loop over all objects to check if object is overtaking */
        /* Use area definition for left-hand traffic */
#if (LA_CFG_AVOID_SPILT_OBJ)
        LA_v_FindObjInArea(a_OvertakenObjID, t_Obj, &LA_OvertakingCheckArgsLeftHandTraffic, FALSE);
#else
        LA_v_FindObjInArea(a_OvertakenObjID, t_Obj, &LA_OvertakingCheckArgsLeftHandTraffic);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
      }

      /* Check if possible overtaken object has been found */
      if (a_OvertakenObjID[0] == (ObjNumber_t)-1)
      {
        /* No possibly overtaken object has been found: object is likely on neighboring lane. */
        b_return = FALSE;
      }
      else
      {
        /* Check if object found is likely a mirror */
#if (LA_CFG_AVOID_SPILT_OBJ)
        LA_v_FindObjInArea(a_CloseObjID, t_Obj, &LAMirrorObjArgs, FALSE);
#else
        LA_v_FindObjInArea(a_CloseObjID, t_Obj, &LAMirrorObjArgs);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
        /* If a second object has been found, object under consideration is probably a mirror and should be suppressed */
        /* Check can be replaced with: a_CloseObjID[0] != (ObjNumber_t)-1 */
        if ( a_CloseObjID[0] == a_OvertakenObjID[0])
        {
          /* Object is a possible mirror. */
          b_return = FALSE;
        }
      }
    }
  }

  return b_return;
}
#endif /* LA_CFG_NARROW_HIGHWAY_CRITERIA */


#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*************************************************************************************************************************
  Functionname:    LA_f_AdaptInLaneTimeThresholdCam                                                            */ /*!

  @brief           Adaption of inlane timer threshold with camera information.

  @description     Adaption of inlane timer threshold if camera indicates object is associated with ego lane
                   @startuml
partition LA_f_AdaptInLaneTimeThresholdCam {
start
    partition LA_CFG_CAM_PARKING_DETECTED {
    if(iObject is stationary and camera confirmed) then (yes)
	repeat 
	    if(object is camera confirmed stationary object) then (yes)
		    -Check if the object is within the search area
			-Set occlusion flag, if one object fulfills criteria
		else
		endif
	repeat while (for all EM objects)
     endif
	}
	
	if(object is not  stationary or Object Is Moving To Stationary) then (yes)
	else
	   if(camera confirmation probability is greater than LA PAR CAM CONF MIN) then (yes)
	      if(Camera object is associated to ego lane ) then (yes)
		     -set time threshlod to mimimum of time threshlod  and LA CAM INLANE STAT INLANETIME
		  elseif(Camera object is associated to out lane and ObjLongDisp is greater than LA CAM OUTLANE STAT DIST MIN and LALaneChangeProb is less than LA CAM OUTLANE MAX LC PROB) then (true)
		     -Camera assigned non-ego lane
		  elseif(Camera object is not associated to ego lane and there is no lane change and ego is not running into a stationary object and confidence of the obj being stationary is high) then (yes)
		     -reduce non-ego stat obj drop ins
		  else
		    if (object is in ego lane) then (yes)
			   -set time threshlod to mimimum of time threshlod  and LA CAM INLANE STAT INLANETIME
			else
			   if(Object is not point or not wide class ) then (yes)
			      -Update inlane time threshold if occluded stationary object is detected  or Roadside parked Object is detected
			   endif
			endif
		  endif
	   endif
	endif   
stop
}
@enduml

  @return          f_InLTimeThreshold : threshold for inlane timer [fTime_t as in Rte_type.h]

  @param[in]       t_Obj : internal object number (Object ID) of a valid reference object [0 ... EM_N_OBJECTS[
                          with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         pt_LAInput->t_RTE.pf_ObjLongDisp(t_Obj) : Longitudinal displacement of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
  @glob_in         pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr : object number of relevant object [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_RTE.pt_ObjClassification(iObj) : object class [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         pt_LAInput->t_FIPOA.pt_CamConfirmationProb(iObj) : Probability of camera confirmation of object i [0.f ... 100.f]
  @glob_in         pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb : 
  @glob_in         SLATE_p_GetEMGenObjAttributes(iObj)->uiDynConfidence : 

  @glob_out        -

  @c_switch_full   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.03.2018
  @changed         09.03.2018

  @author          Yvonne Strigel | Yvonne.Strigel@continental-corporation.com | +49-8382-9699-696
*************************************************************************************************************************/
extern fTime_t LA_f_AdaptInLaneTimeThresholdCam( const ObjNumber_t iObj, fTime_t f_InLTimeThreshold )
{
  const float32 f_ObjLongDisp = (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj));
  ObjNumber_t t_RelObjNr = pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr;
  SLATE_t_Obj_CLassification t_ObjClassification = (*pt_LAInput->t_RTE.pt_ObjClassification(iObj));
  percentage_t t_camConfirmationProb = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_CamConfirmationProb;
  /*get lane change information for lane object association*/
  uint8 u_LALaneChangeProb = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj));
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);

#if ( (LA_CFG_CAM_PARKING_DETECTED) || (LA_CFG_ENABLE_PARKED_DETECTION) )
  boolean b_UseOutlaneTimeThreshold = FALSE;
#endif /* end of ( (LA_CFG_CAM_PARKING_DETECTED) || (LA_CFG_ENABLE_PARKED_DETECTION) ) */

#if(LA_CFG_CAM_PARKING_DETECTED) 
  boolean b_Occlusion_Detected = 0;
  boolean b_ObjLongGapCondition = 0;
  boolean b_ObjLatGapCondition = 0;
  const float32 f_ObjLatDisp = (*pt_LAInput->t_RTE.pf_ObjLatDisp(iObj));
  ObjNumber_t loopObject;
  float32 f_OcclObjLongDisp, f_OcclObjLatDisp;
  SLATE_t_Obj_DynamicProperty t_OcclObjDynProb;
  percentage_t t_OcclObjCamConfProb;



/*************************************************************/
/* Analyze Gap Between Stationary Cars to Detect Parking Row */
/*************************************************************/

/* Check if iObj is stationary and camera confirmed */
if( ((t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
  || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
    )
   &&(t_camConfirmationProb > (percentage_t)LA_PAR_CAM_CONF_MIN)
   &&(EGO_SPEED_X_OBJ_SYNC <= MAX_CITY_SPEED_THRESH)
  )
{
  /* Loop over all objects to identify a camera confirmed stationary car which stand close behind the analyzed object */
  for (loopObject = (ObjNumber_t)(EM_N_OBJECTS - 1) ; loopObject >= 0; loopObject--)
  {
    t_OcclObjCamConfProb = pt_LAInput->pt_FIPOA->t_ObjList[loopObject].t_CamObjectData.t_CamConfirmationProb;
    t_OcclObjDynProb = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(loopObject));
    /* Check for camera confirmed stationary objects */
    if( ((t_OcclObjDynProb == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      || (t_OcclObjDynProb == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
        )
        &&(t_OcclObjCamConfProb > (percentage_t)LA_PAR_CAM_CONF_MIN)
      )
    {

      if((loopObject != iObj)
        )
      {
        f_OcclObjLongDisp = *SLATE_pf_GetObjLongDisp(loopObject);
        f_OcclObjLatDisp = *SLATE_pf_GetObjLatDisp(loopObject);
        b_ObjLongGapCondition = (boolean)((f_ObjLongDisp - f_OcclObjLongDisp) < LA_MAX_LONG_OBJECT_GAP_SIZE);
        b_ObjLatGapCondition = (boolean)(fABS(f_OcclObjLatDisp - f_ObjLatDisp) < LA_MAX_LAT_OBJECT_GAP_SIZE);
        /* Check if the object is within the search area */
        if((f_OcclObjLongDisp >= LA_MIN_OBJ_DIST_PARKING_ROW)
          && (f_ObjLongDisp > f_OcclObjLongDisp)
          && (b_ObjLongGapCondition)
          && (b_ObjLatGapCondition)
          )
        {
          /* Set occlusion flag, if one object fulfills criteria */
          b_Occlusion_Detected = TRUE;
        }
        else
        {
          /* No occlusion detected */
        }
      }
      else
      {
        /* same object - no operation */
      }
    }
    else
    {
      /* no cam confirmed stationary object available */
    }
  }
}
#endif /* end of LA_CFG_CAM_PARKING_DETECTED */


  if((t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
    || (b_ObjIsMovingToStationary == TRUE))
  {

  }
  else /* Stationary Objects or vehicles */
  {
      /* If camera indicates object is associated with ego lane, then limit
    in-lane timer parameterized maximums */
    if (t_camConfirmationProb > (percentage_t)LA_PAR_CAM_CONF_MIN)
    {
      if( LA_b_CheckCameraObjAssoToEgoLane(iObj) == TRUE )
      {
        f_InLTimeThreshold = MIN_FLOAT(f_InLTimeThreshold, LA_CAM_INLANE_STAT_INLANETIME);
      }
      else if ( ( LA_b_CheckCameraObjAssoToOutLane(iObj) == TRUE )
              && (f_ObjLongDisp > LA_CAM_OUTLANE_STAT_DIST_MIN)
              && (u_LALaneChangeProb < LA_CAM_OUTLANE_MAX_LC_PROB)
              )
      {
        /* Camera assigned non-ego lane*/
        f_InLTimeThreshold = MAX_FLOAT(f_InLTimeThreshold, LA_CAM_OUTLANE_STAT_INLANETIME);
      }
      /* To reduce the chances of stationary object drop-ins, which may occur when the distance of an adjacent
      stationary object is less than a moving object in ego lane, due to sudden changes in VDY trajectory and
      due to the fact that stat object time thresholds are very low */
      /* This block is satisfied when ego is following any object in the first place, 
      not changing lanes, and the stationary object is NOT assigned to ego lane */
      else if ( (LA_b_CheckCameraObjAssoToEgoLane(iObj) != TRUE) 
              && (u_LALaneChangeProb < LA_MIN_PROB_LANE_CHANGE) //we need to be absolutely sure we are not changing lanes
              && (t_RelObjNr != OBJ_INDEX_NO_OBJECT)        //Making sure ego is not running into a stationary object which may happen in free drive
              && (SLATE_p_GetEMGenObjAttributes(iObj)->uiDynConfidence > LA_MIN_DYN_CONFIDENCE) //Check if the confidence of the obj being stationary is high
              )
      {
        // To reduce non-ego stat obj drop ins
        f_InLTimeThreshold = MAX_FLOAT(f_InLTimeThreshold, LA_CAM_OUTLANE_STAT_INLANETIME);
      }
      else
      {
        /* Camera did not assign any lane, or non-ego lane */
#if (SIT_CFG_OBJECT_SCORING)
        /* Object is point or wide class : only decrease inlane time if scoring module
        did not decide for neighboring lanes */
        const eAssociatedLane_t eObjLane = *pt_LAInput->t_SIT.pt_ScoringAssocLane(iObj);
        if (eObjLane == ASSOC_LANE_EGO)
        {
          f_InLTimeThreshold = MIN_FLOAT(f_InLTimeThreshold, LA_CAM_SCORING_STAT_INLANETIME);
        }
        else
#endif
        {
          /* In this case only significantly decrease
          in-lane time when object class is different from point or wide */

          if((t_ObjClassification != SLATE_OBJCLASS_POINT) && (t_ObjClassification != SLATE_OBJCLASS_WIDE))
          {
            /* Update inlane time threshold if occluded stationary object is detected  or Roadside parked Object is detected*/
#if (LA_CFG_CAM_PARKING_DETECTED)
            if (b_Occlusion_Detected == TRUE)
            {
              b_UseOutlaneTimeThreshold = TRUE;
            }
#endif /* end of LA_CFG_CAM_PARKING_DETECTED */

#if (LA_CFG_ENABLE_PARKED_DETECTION)
            if (pt_LAOutput->b_RoadSideParkedObj[iObj] == TRUE)
            {
              b_UseOutlaneTimeThreshold = TRUE;
            }
#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */

#if ( (LA_CFG_CAM_PARKING_DETECTED) || (LA_CFG_ENABLE_PARKED_DETECTION) )
            if(b_UseOutlaneTimeThreshold == TRUE)
            {
              f_InLTimeThreshold = MIN_FLOAT(f_InLTimeThreshold, LA_CAM_OUTLANE_STAT_INLANETIME);
            }
            else
#endif /* end of ( (LA_CFG_CAM_PARKING_DETECTED) || (LA_CFG_ENABLE_PARKED_DETECTION) ) */
            {
              f_InLTimeThreshold = MAX_FLOAT(f_InLTimeThreshold, LA_CAM_DEFAULT_STAT_INLANETIME);
            }
          }
        }
      }
    }
  }

  return f_InLTimeThreshold;
}
#endif
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

// PRQA L:STTLN_EXCEEDED
