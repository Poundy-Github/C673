/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_customfunctions.c

DESCRIPTION:               Custom Functions for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.48 $

LEGACY VERSION:            Revision: 1.12

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "la.h"

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#include "la_corridor_crit.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       la_customfunctions Custom functions
@ingroup        la
@brief          This module contains customer specific functions for ACC Lane Association module.
@{
*/
/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/

#if (LA_CFG_DELAY_PRED_LANE_ASSOC)
#define LA_CUSTOM_PRED_OUTLANE_COUNT_THRES              (7u)  /* counter threshold to delay predicted change to outlane:
                                                                 - high values: + late detection of cut-outs
                                                                                + less drop-outs 
                                                                                + late release of objects 
                                                                 - low values : + early detection of cut-outs
                                                                                + more drop-outs
                                                                                + early release of objects */
#define LA_CUSTOM_PRED_INLANE_COUNT_THRES               (1u)  /* counter threshold to delay predicted change to inlane
                                                                 - high values: + late detection of cut-ins
                                                                                + less drop-ins 
                                                                                + late pick-up of objects 
                                                                 - low values : + early detection of cut-ins
                                                                                + more drop-ins
                                                                                + early pivk-up of objects */
#endif /* LA_CFG_DELAY_PRED_LANE_ASSOC */

#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
#define LA_DYNAMISM_COUNT_MAX                         (5u)
#define LA_DYNAMISM_COUNT                             (2u)
#define LA_DIST2TRAJDIFF_THRESH                       (0.15f)
#define LA_TRAJ_DYNAMISM_MAX_SPEED                    (60.f/C_KMH_MS)
#define LA_TRAJ_DYNAMISM_MAX_DISTX                    (50.f)
#define LA_RELEVANT_COUNTER_THRESH                    (10u)
#define LA_TRAJ_DYNAMISM_MAX_OBJ_RATIO                (0.3f) 
#define LA_TRAJ_DYNAMISM_MIN_DROP_THRESHOLD           (-1.0f)
#define LA_TRAJ_DYNAMISM_MIN_INLANE_TIME_THRESHOLD    (1.5f)
#define LA_TRAJ_DYNAMISM_MAX_CHECK_DISTX              (50.0f)
#define LA_TRAJ_DYNAMISM_MIN_CHECK_DISTX              (40.0f)
#define LA_TRAJ_DYNAMISM_EGO_VEL                      (30.0f/C_KMH_MS)
#define LA_TRAJ_DYNAMISM_MIN_DIFF_DIST2TRAJ           (0.02f)
#define LA_TRAJ_DYNAMISM_LAT_DIST_CHECK               (3.0f)
#endif /* (LA_CFG_TRAJ_DYNAMISM_DETECTION)*/

#if (LA_CFG_ADAPT_INLANE_FAR_TRUCK)
#define LA_FAR_TRUCK_DISPL_LONG                       (100.0f)
#define LA_FAR_TRUCK_VEL_REL                          (-10.0f)
#define LA_FAR_TRUCK_INLANE_TIME_FACT                 (0.5f)
#endif /*(LA_CFG_ADAPT_INLANE_FAR_TRUCK)*/

#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
#define LA_MAX_VEGO_FOR_OBSTACLE_SUPPR                            (60.F/C_KMH_MS)  
#define LA_MAX_ABS_VELX_OF_OBSTACLE                               (15.F/C_KMH_MS)
#define LA_MAX_DISTX_OF_OBSTACLE                                  (80.F)   
#define LA_OBJ_DISTX_TO_ROADBORDER_FOR_OBSTACLES_LOW              (50.F)
#define LA_OBJ_DISTX_TO_ROADBORDER_FOR_OBSTACLES_HIGH             (100.F)
#define LA_OBJ_DIST_TO_ROADBORDER_LEFT_MIN                        (100u)
#define LA_OBJ_DIST_TO_ROADBORDER_RIGHT_MIN                       (100u)
#define LA_OBJ_DIST_TO_ROADBORDER_DEFAULT                         (999.F)
#define LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN_FOR_OBSTACLES     (50u)
#define LA_OBJ_DIST_TO_ROADBORDER_ROAD_TRACK_MIN_FOR_OBSTACLES    (3u)
#define LA_CLUST_VAR_ROAD_BORDER_DIST_DELTA_THRES_FOR_OBSTACLES   (1.0F)
#endif /* (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES) */

#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)
#define LA_LONG_DISTANCE_CURVE_STAT                               (30.f)
#define LA_IN_LANE_TIME_THRESHOLD_CURVE_STAT                      (0.0035f)
#define LA_IN_LANE_TIME_THRESHOLD_CURVE_MAX                       (2.f)
#define LA_IN_LANE_TIME_THRESHOLD_CURVE_FACTOR                    (0.5f)
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */

#if (LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE)
#define LA_RELEVANT_COUNTER_CITY_NO_LANE_THRESHOLD                (3u)
#define LA_TRAJ_DYNAMISM_CITY_NO_LANE_MIN_DISTX                   (16.f)
#define LA_TRAJ_DYNAMISM_CITY_NO_LANE_MAX_DISTX                   (80.f)
#define LA_TRAJ_DYNAMISM_CITY_NO_LANE_DROP_THRESHOLD              (-2.f)
#endif /* (LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE) */
/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/
#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
SET_MEMSEC_VAR(f_DifferenceDist2TrajLast)
static float32 f_DifferenceDist2TrajLast = 0.0f;// PRQA S 3218
#endif /* (LA_CFG_TRAJ_DYNAMISM_DETECTION)*/
/* date: 2019-05-29, reviewer: Nandan Chaudhari (uia77568), reason: static local for saving data across function calls */

/*****************************************************************************
  STATIC FUNCTION PROTOTYPES
*****************************************************************************/
#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
static float32      LA_f_ComputeObjDistToRoadBorderforObstacles(const ObjNumber_t ObjNr);
#endif /* (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES) */
/*****************************************************************************
  Non - Static FUNCTIONS
*****************************************************************************/

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
/*************************************************************************************************************************
  Functionname:    LA_b_CustProcessCriteriaMatrix                                                                      */ /*!

  @brief           Custom processing of criteria matrix

  @description     Custom post-processing of trace bracket criteria matrix 
                    - Store active trace bracket information

  @return          bCritMatModified : Information if criteria matrix was modified [TRUE, FALSE]

  @param[in,out]   iObj : Object ID  [0 ... EM_N_OBJECTS[
  @param[in,out]   pCriteriaMatrix : Pointer to the criteria matrix

  @glob_out        -
  @glob_in         -

  @c_switch_part   -
  @c_switch_full   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING : Configuration switch for activating additional call to custom
                   LA_b_CustProcessCriteriaMatrix after all other trace bracket processing took place

  @pre             -
  @post            -

  @created         -
  @changed         21.04.2016

  @author          Thomas Kleintje/Gergely Ungvary
*************************************************************************************************************************/
boolean LA_b_CustProcessCriteriaMatrix(ObjNumber_t iObj, LA_t_CriteriaMatrix * pCriteriaMatrix)
{
  boolean bCritMatModified = FALSE;

  /* Store active trace bracket information */
  OUT_v_CustStoreBracketExtensions(iObj, pCriteriaMatrix);

  return bCritMatModified;
}
#endif /* #if OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING */

/*************************************************************************************************************************
  Functionname:    LA_b_CheckCustomInlaneCriteria                                                                      */ /*!

  @brief           Check customer specific inlane criteria

  @description     Check, if criteria for predicted inlane association are fulfilled. 
                    Predicted lane association not for stationary objects or occluded objects or objects occluded 
                    by trace analysis.
                    Consider occlusion only if the object can become the OOI-0 based in the longitudinal distance 
                    in order to reduce the influence on the OOI-1.
                    Delay predicted lane association based on a counter.

                    @startuml {LA_b_CheckCustomInlaneCriteria.png}
                        Start
                            Partition LA_b_CheckCustomInlaneCriteria {
                                -Check customer specific inlane criteria
                            }
                        end
                    @enduml

  @return          retval : Information if criteria for predicted inlane association are fulfilled [TRUE,FALSE] 

  @param[in]       iObjNr : object ID for which occupancies are checked [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[

  @glob_in         *SLATE_pt_GetObjDynProperty(iObjNr) : Dynamic property of an object iObjNr [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in         t_LA_InternalObjectData[iObjNr].ui_ClusterVarianceLevel : Difficulty level of object iObjNr with high cluster variance [LA_CLUST_VAR_LEVEL_LOW ... SIT_CLUST_VAR_LEVEL_DIFFICULT]
  @glob_in         SLATE_p_GetEMGenObjAttributes(iObjNr)->eObjectOcclusion : Occlusion of object iObjNr [EM_t_GenObjOclusionState as in Rte_Type.h]
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(iObjNr)->OccludedByTrace : Determine if object iObjNr is occluded based on a trace analysis [TRUE, FALSE]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SLATE_f_GetObjectLength(i) : Length of object i   [0 ... 100.0f] m
  @glob_in         OBJ_GET_RELEVANT_OBJ_NR : Object ID of relevant object (OOI-0) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.pred_counter : Cycle counter for delay of inlane and outlane state changes by prediction [full range of datatype]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.pred_counter : Cycle counter for delay of inlane and outlane state changes by prediction [full range of datatype]

  @c_switch_part   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Configuration switch to enable cluster variance usage for inlane decision
  @c_switch_part   SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION : Configuration switch to enable occlusion calculation usage for inlane decision
  @c_switch_part   LA_CFG_DELAY_PRED_LANE_ASSOC : Configuration switch to delay the predicted lane association
  @c_switch_part   LA_CFG_NARROW_HIGHWAY_CRITERIA : LA switch for narrow highway criteria check

  @pre             -
  @post            -

  @created         21.03.2016
  @changed         21.03.2016

  @author          Thomas Bock | thomas.2.bock@continental-corporation.com | +49 (8382) 9699-755
*************************************************************************************************************************/
boolean LA_b_CheckCustomInlaneCriteria(ObjNumber_t iObjNr)
{
  boolean retval = FALSE;

#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
  if ( ((t_OOI_ObjectList[iObjNr].t_Bool.AlreadyOOI) )
    && ((pt_LAOutput->t_LAObjOutputList[iObjNr].u_CameraCutInPotential) >= LA_CAM_OVERLAP_PROB_MAX)
     )
  {
    retval = TRUE;
  }
#else
  _PARAM_UNUSED(iObjNr);
#endif /* FCT_CFG_CAMERA_CUTIN_POTENTIAL */

  return(retval);
}


/*************************************************************************************************************************
  Functionname:    LA_b_CheckCustomOutlaneCriteria                                                                     */ /*!

  @brief           Check customer specific outlane criteria

  @description     Check, if criteria for predicted out-lane association are fulfilled. 
                   Delay predicted outlane detection based on a counter.

                    @startuml {LA_b_CheckCustomOutlaneCriteria.png}
                        Start
                            Partition LA_b_CheckCustomOutlaneCriteria {
                                -Check customer specific outlane criteria
                            }
                        End
                    @enduml

  @return          retval : Information if criteria for predicted outlane association are fulfilled. [TRUE, FALSE]

  @param[in]       iObjNr : object ID for which occupancies are checked [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *SLATE_pt_GetObjDynProperty(iObjNr) : Dynamic property of an object iObjNr [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.pred_counter : Cycle counter for delay of in-lane and out-lane state changes by prediction [full range of datatype]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.pred_counter : Cycle counter for delay of in-lane and out-lane state changes by prediction [full range of datatype]

  @c_switch_part   LA_CFG_DELAY_PRED_LANE_ASSOC : Configuration switch to delay the predicted lane association

  @pre             -
  @post            -

  @created         22.03.2016
  @changed         22.03.2016

  @author          Thomas Bock | thomas.2.bock@continental-corporation.com | +49 (8382) 9699-755
*************************************************************************************************************************/
boolean LA_b_CheckCustomOutlaneCriteria(ObjNumber_t iObjNr)
{
  boolean retval = FALSE;

#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  SLATE_t_Obj_DynamicProperty t_OBJ_DynamicProperty = *(pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObjNr));

  if ( ((t_OBJ_DynamicProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
     && (t_OBJ_DynamicProperty != SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
       )
    && ( (t_OOI_ObjectList[iObjNr].t_Bool.AlreadyOOI) )
    && ((pt_LAOutput->t_LAObjOutputList[iObjNr].u_CameraCutOutPotential) >= LA_CAM_OVERLAP_PROB_MAX)
    )
  {
    retval = TRUE;
  }
#else
  _PARAM_UNUSED(iObjNr);
#endif /* FCT_CFG_CAMERA_CUTOUT_POTENTIAL */

  return(retval);
}


#if (LA_CFG_CUSTOM_CORRIDOR_PREPROCESSING)
/*************************************************************************************************************************
  Functionname:    LA_v_CustomCorridorPreProcessing                                                                    */ /*!

  @brief           Custom corridor pre-processing 

  @description     Custom activation / deactivation of corridor bracket functions
                    - Check if course prediction overtake assist indicates that this object is being
                      overtaken. If yes, reset all trace bracket extensions for it 

                    @startuml
                        Start
                            Partition LA_v_CustomCorridorPreProcessing {
                                -Custom corridor pre-processing
                            }
                        End
                    @enduml

  @return          -

  @param[in]       iObj : Object ID   [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[
  @param[in,out]   pBracketFuncEnable : Pointer to enable/disable bracket functions
                      bUseSeekLaneWidthOnly                   [TRUE, FALSE]
                      bEnableAddRestrictionCurveOuterBorder   [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableExtensionRoadBorder              [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableAddExtensionRelevantObject       [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableExtensionObjScoring              [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableAddExtensionObjectApproximation  [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableExtensionNaviCountryroad         [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableExtensionCamLaneObjAssoc         [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bExtensionBlockedObstacleCorridor       [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h
                      bEnableAddExtensionHighTunnelProb       [SIT_CORR_BRACKET_FUNC_ENABLED, LA_CORR_BRACKET_FUNC_DISABLED] as in la_corridor_crit.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : Configuration switch to enable/disable relevant object extension as defined in la_cfg.h
  @c_switch_part   SIT_CFG_OBJECT_SCORING : Configuration switch to enable object scoring module
  @c_switch_part   LA_CFG_ADD_EXTENSION_OBJ_APPROX : Configuration switch to enable/disable extension object approximation.
  @c_switch_part   LA_CFG_NAVI_COUNTRYROAD_EXTENSION : Configuration switch enabling the trace bracket extension on country roads (based on navi information)
  @c_switch_part   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : Configuration switch, which enables corridor extension based on camera lane object association
  @c_switch_part   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : Configuration switch enabling the trace bracket extension for the blocked path between an object and an obstacle
  @c_switch_part   LA_CFG_ADD_EXT_TUNNEL_PROB : Config switch to enable a bracket extension used for improved robustness against drop-outs in tunnels
  @c_switch_full   LA_CFG_CUSTOM_CORRIDOR_PREPROCESSING : Configuration switch to activate additional call to custom
                    LA_v_CustomCorridorPreProcessing , which allows to enable or disable
                    selected corridor bracket functions before their actual calculation

  @pre             -
  @post            -

  @created         -
  @changed         21.04.2016

  @author          Christopher Knievel, Fabian Killus
*************************************************************************************************************************/
void LA_v_CustomCorridorPreProcessing(ObjNumber_t iObj, LA_t_BracketFuncEnable* pBracketFuncEnable)
{
#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
  /* Check if course prediction overtake assist indicates that this object is being
  overtaken. If yes, reset all trace bracket extensions for it */
  if (CP_b_ACC_CheckObjForOvertake(iObj))
  {
      /* Restrict base corridor width to the seeklane-width only. The seeklane-width
     is smaller compared to the tracklane-width and thus, objects can be released
     earlier in e.g. overtake-scenarios. */
    pBracketFuncEnable->bUseSeekLaneWidthOnly = TRUE;

    pBracketFuncEnable->bEnableAddRestrictionCurveOuterBorder  = LA_CORR_BRACKET_FUNC_DISABLED;
    pBracketFuncEnable->bEnableExtensionRoadBorder             = LA_CORR_BRACKET_FUNC_DISABLED;
  #if (LA_CFG_EXT_RELEVANT_OBJECT)
    pBracketFuncEnable->bEnableAddExtensionRelevantObject      = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif
  #if (SIT_CFG_OBJECT_SCORING)
      pBracketFuncEnable->bEnableExtensionObjScoring           = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif
  #if (LA_CFG_ADD_EXTENSION_OBJ_APPROX)
    pBracketFuncEnable->bEnableAddExtensionObjectApproximation = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif  
  #if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
    pBracketFuncEnable->bEnableExtensionNaviCountryroad        = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif
  #if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
    pBracketFuncEnable->bEnableExtensionCamLaneObjAssoc        = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif
  #if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
    pBracketFuncEnable->bExtensionBlockedObstacleCorridor      = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif
  #if (LA_CFG_ADD_EXT_TUNNEL_PROB)
    pBracketFuncEnable->bEnableAddExtensionHighTunnelProb      = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif
  #if (LA_CFG_EXT_HIGHSPEED_APPROACH)
    pBracketFuncEnable->bEnableExtensionHighspeedApproach      = LA_CORR_BRACKET_FUNC_DISABLED;
  #endif

  }
#else
  _PARAM_UNUSED(iObj);
  _PARAM_UNUSED(pBracketFuncEnable);
#endif /*SLATE_CFG_ENABLE_OVERTAKE_ASSIST*/
}
#endif


/*************************************************************************************************************************
  Functionname:    LA_b_CustMergePreselection                                                                          */ /*!

  @brief           Customizable pre-selection function

  @description     This function can customize how objects are selected for ACC functionality. The function is passed the ACC
                   object quality determined in EM as well as the base object selection boolean. Depending on this information
                   the function shall return TRUE if the object may be selected by ACC object selection. If this function
                   returns FALSE than the object is no longer considered by SI.

                    @startuml
                        Start
                            Partition LA_b_CustMergePreselection {
                                If(ACC Object quality is equal or greater than minimun ACC quality level)then (True)
                                    -Object consider by SI 
                                Else (False)
                                    -Objcet is no longer consider by SI
                                endif
                            }
                        End
                    @enduml

  @return          Select : TRUE if object shall be considered by ACC, FALSE otherwise [TRUE,FALSE]

  @param[in]       ObjNr : the object number to check (may be free/non-free) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       uiAccQual : The ACC object quality determined in EM [ucConfidence_t as in RTE_Type.h]
  @param[in]       bFunPresel : if this Boolean set to TRUE time-gap based selection would accept object [TRUE,FALSE]

  @glob_in         *SLATE_pt_GetObjDynProperty(iObjNr) : Dynamic property of an object iObjNr [EM_t_GenObjDynamicProperty as in Rte_Type.h] 
                        with iObjNr [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[
  @glob_in         SLATE_b_GetObjIsMovingToStationary(iObjNr) : Boolean, if an stationary object was seen moving [TRUE, FALSE] 
                        with iObjNr [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[
  @glob_out        -

  @c_switch_part   ALGO_CFG_CameraRadarFusion : Global switch for enabling EM/FCT code for fusion of camera and radar data. 

  @pre             -
  @post            -

  @created         -
  @changed         22.03.2016

  @author          Thomas Bock | thomas.2.bock@continental-corporation.com | +49 (8382) 9699-755
*************************************************************************************************************************/
boolean LA_b_CustMergePreselection(ObjNumber_t ObjNr, ACCObjectQuality_t uiAccQual, boolean bFunPresel)
{
  boolean Select;
  boolean bObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(ObjNr);

  SLATE_t_Obj_DynamicProperty t_OBJ_DynamicProperty = *(pt_LAInput->t_RTE.pt_ObjDynamicProperty(ObjNr));
#if (!SLATE_CFG_CAMERA_RADAR_FUSION)
  /*! @todo remove when Camera works for ARS4B0 */
  if( (t_OBJ_DynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) && (bObjIsMovingToStationary == FALSE))
  {
    uiAccQual = 0u;
  }
#else
  _PARAM_UNUSED(bObjIsMovingToStationary);
  _PARAM_UNUSED(t_OBJ_DynamicProperty);
#endif  /* END IF SLATE_CFG_CAMERA_RADAR_FUSION */
#ifdef _MSC_VER
  /* Keep MS-VC happy, even though currently this parameter is not used */
  ObjNr = ObjNr;// PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant, but may be used in future*/
#endif
  if ((uiAccQual >= FUN_PRESEL_ACC_MIN_OBJ_QUAL) && (bFunPresel))
  {
    Select = TRUE;
  }
  else
  {
    Select = FALSE;
  }
  return Select;
}

/*************************************************************************************************************************
  Functionname:    LA_v_InitCustom                                                                         */ /*!

  @brief           Initialize customer specific object data

  @description     Initialize customer specific object data

                    @startuml
                        Start
                            Partition LA_v_InitCustom {
                                -Do nothing 
                            }
                        End
                    @enduml

  @return          -

  @param[in]       -
  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         -
  @changed         -

  @author          -
*************************************************************************************************************************/
void LA_v_InitCustom(void)
{
  return;
}

/*************************************************************************************************************************
  Functionname:    LA_v_MergeCustomObjects                                                                         */ /*!

  @brief           Merge customer specific object data

  @description     Merge customer specific object data

                    @startuml
                        Start
                            Partition LA_v_MergeCustomObjects {
                                -merge customer specific object data
                            }
                        End
                    @enduml

  @return          -

  @param[in]       uiObjectToKeep   : Information describing the object to keep     [0u ... EM_N_OBJECTS-1]
  @param[in]       uiObjectToDelete : Information describing the object to delete   [0u ... EM_N_OBJECTS-1] 
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         -
  @changed         -

  @author          -
*************************************************************************************************************************/
void LA_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete )
{
  /* merge customer specific object data */
  uiObjectToKeep = uiObjectToKeep; // PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
  uiObjectToDelete = uiObjectToDelete;// PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
}


#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
/*************************************************************************************************************************
  Functionname:    LA_v_Camera_CutIn_CutOut_Potential                                                                        */ /*!

  @brief           Calculates LA custum camera based cut-in / cut-out potential

  @description     Calculates LA custum camera based cut-in /cut-out potential. Potential is calculated from camera overlap distance.
                   Potential is calculated only for for ooi's. The probabiliy is proportional to object overlap distance with ego lane
                   and overlap distnce .
                   The function is supressed during lane change.

  @return          -

  @param[in]       -

  @glob_in         pt_LAInput->t_SIT.pt_SITLaneChangeCamPreMoveState : enum
  @glob_in         pt_LAInput->t_FIPCamLane.pf_LaneWidth :  Width of the camera lane [m]
  @glob_in         pt_LAInput->t_CP.pf_CourseCurve :  Ego course curvature [1/m] 
  @glob_in         pt_LAOutput->t_LAObjOutputList[iCurObj].t_CutInCutOutstate : object state

  @glob_out        pt_LAOutput->t_LAObjOutputList[i].u_CameraCutInPotential  : camera based cut-In potential  [0U .. 100U]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].u_CameraCutOutPotential : camera based cut-Out potential [0U .. 100U]
  @glob_out        pt_LAOutput->t_LAObjOutputList[iCurObj].t_CutInCutOutstate : object state

  @c_switch_part   FCT_CFG_CAMERA_CUTIN_POTENTIAL  : Camera based cut in probability for ooi lane association
  @c_switch_part   FCT_CFG_CAMERA_CUTOUT_POTENTIAL : Camera based cut out probability for ooi lane association 
  @c_switch_full   FCT_CFG_CAMERA_CUTIN_POTENTIAL  : Camera based cut in probability for ooi lane association  or,
  @c_switch_full   FCT_CFG_CAMERA_CUTOUT_POTENTIAL : Camera based cut out probability for ooi lane association 

  @pre             None
  @post            No changes

  @created         03.04.2017
  @changed         27.04.2017

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 69 67869 6110
*************************************************************************************************************************/
void LA_v_Camera_CutIn_CutOut_Potential(void)
{
}

#endif /*(FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)*/

#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
/*************************************************************************************************************************
  Functionname:    LA_v_DetectTrajDynamism                                                                               */ /*!

  @brief           Update Trajecctory Dynamism detection flag

  @description     Trajectory Dynamism is detected by checking the difference between  Dist2Traj value of Current cycle value and Previous cycle value of OOI-0. 
                   If Differnce between Dist2Traj is above certain value then COunter will be incremented i.e. Trajectory Dynamism is detected. If the dynamism is sustained for 
                   more than N cycles then Dynamism detected flag will be made TRUE.

  @return          -

  @param[in]       -

  @glob_in         - 
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_TRAJ_DYNAMISM_DETECTION : Configuration switch to detect trajectory Dynamism in case based on OOI-0 Dist2Traj value

  @pre             -
  @post            -

  @created         13.02.2016
  
  @author          Dyamana Gouda | Dyamana.Gouda@continental-corporation.com
*************************************************************************************************************************/
void LA_v_DetectTrajDynamism(void)
{
  SIT_LC_t_LaneChangePhaseEnum tLCPhase = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase;

  CP_t_GDBTrajectoryData   CurTraj;
  CP_t_GDBTrajectoryData   LastCylTraj;
  CAL_t_TrajRefPoint      pTrajRefPoint;
  CAL_t_TrajRefPoint      pTrajRefPointLastCyl;
  float32 Xposition = LA_TRAJ_DYNAMISM_MIN_CHECK_DISTX;
  float32 f_SITCycleTime;
  float32 f_ABS_DifferenceDist2Traj;
  float32 f_ABS_DifferenceDist2TrajLast;

  if(*pt_LAInput->t_RTE.pf_EgoVelObjSync <= LA_TRAJ_DYNAMISM_EGO_VEL)
  {
    Xposition = LA_TRAJ_DYNAMISM_MAX_CHECK_DISTX;
  }
  else
  {
  
  }
  
  CurTraj = pt_LAInput->t_CP.pt_TrajectoryData->Current;
  LastCylTraj = pt_LAInput->t_CP.pt_TrajectoryData->LastCycle;
  

  LA_v_CalculateDistance2Traj(Xposition, 0.0f, (boolean) pt_LAInput->t_CP.pt_TrajectoryData->State.EgoCourseOnly, &CurTraj, &pTrajRefPoint);
  LA_v_CalculateDistance2Traj(Xposition, 0.0f, (boolean) pt_LAInput->t_CP.pt_TrajectoryData->State.EgoCourseOnly, &LastCylTraj, &pTrajRefPointLastCyl);

  /*Check for Ego lane change state*/
  if( tLCPhase == LC_NO_LANECHANGE )
  {
    if(CML_f_IsNonZero(pTrajRefPointLastCyl.fDistToTraj))/* PRQA S 3416 */
	/* date: 2020-09-25, reviewer: Dhamodharan Subramanian, reason: Not safety critical. */
    {
      /*Dist2Traj changed from +ve to -ve value or vice versa*/
      if( (pTrajRefPoint.fDistToTraj/pTrajRefPointLastCyl.fDistToTraj) < 0.f)
      {
        pt_LAOutput->f_DifferenceDist2Traj = fABS(pTrajRefPoint.fDistToTraj) + fABS(pTrajRefPointLastCyl.fDistToTraj);
      }
      else
      {
        pt_LAOutput->f_DifferenceDist2Traj = fABS(pTrajRefPoint.fDistToTraj) - fABS(pTrajRefPointLastCyl.fDistToTraj);
      }
    }
    else
    {
      pt_LAOutput->f_DifferenceDist2Traj = fABS(pTrajRefPoint.fDistToTraj);
    }

    /* Apply low pass filter */
    f_SITCycleTime = SLATE_f_GetSITCycleTime();
    f_DifferenceDist2TrajLast = GDB_FILTER(pt_LAOutput->f_DifferenceDist2Traj, f_DifferenceDist2TrajLast, (0.5f / f_SITCycleTime));

    /*Check difference between Dist2Traj of current cycle and Previous cycle to determine Dynamism*/
    f_ABS_DifferenceDist2Traj = fABS(pt_LAOutput->f_DifferenceDist2Traj);
    if(f_ABS_DifferenceDist2Traj > LA_DIST2TRAJDIFF_THRESH)     /* TODO : Need to consider near and far Objects accordingly update the width check */
    {
      if(pt_LAOutput->u_iDynamismCount < LA_DYNAMISM_COUNT_MAX)
      {
        pt_LAOutput->u_iDynamismCount ++;
      }
    }

    f_ABS_DifferenceDist2TrajLast = fABS(f_DifferenceDist2TrajLast);
    if((pt_LAOutput->b_TrajDynDetected == TRUE) && (f_ABS_DifferenceDist2TrajLast < LA_TRAJ_DYNAMISM_MIN_DIFF_DIST2TRAJ))
    {
      pt_LAOutput->u_iDynamismCount = (pt_LAOutput->u_iDynamismCount >= 1u) ? (pt_LAOutput->u_iDynamismCount-1) : 0u;
    }

    if(pt_LAOutput->u_iDynamismCount > LA_DYNAMISM_COUNT) 
    {
      /*Raise Flag if Dynamism is detected for LA_DYNAMISM_COUNT+1 consecutive cycles*/
      pt_LAOutput->b_TrajDynDetected = TRUE;
    }

    if(pt_LAOutput->u_iDynamismCount == 0u)
    {
      /*Reset Dynamism Flag*/
      pt_LAOutput->b_TrajDynDetected = FALSE;
    }
  }
  else
  { 
    /*Reset the counter during lane change for faster release*/
    pt_LAOutput->b_TrajDynDetected = FALSE;
    f_DifferenceDist2TrajLast = 0.0f;
    pt_LAOutput->u_iDynamismCount = 0u;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_AdaptObjInLaneTimeThresholdTrajDynamism                                                          */ /*!

  @brief           Update object inlane time threshold based on Trajectory Dynamism detection flag

  @description     If Dynamism detected flag is TRUE, then inlane time threshold is set to maximum value possible making the selection difficult and therefore prevents dropin. 

  @return          fTimeThreshInLane : The modified in-lane time threshold

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThreshInLane : Time threshold for object iObj                   [0 ... 100.0f] s

  @glob_in         *pt_LAInput->t_RTE.pt_ObjClassification(iObj) : Classification (into type) of object                             [type SLATE_t_Obj_CLassification defined in Rte_Type.h]   
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_TRAJ_DYNAMISM_DETECTION : Configuration switch to detect trajectory Dynamism in case based on OOI-0 Dist2Traj value

  @pre             -
  @post            -

  @created         13.02.2016


  @author          Nandan Chaudhari | Nandan.Chaudhari@continental-corporation.com
*************************************************************************************************************************/
fTime_t LA_v_AdaptObjInLaneTimeThresholdTrajDynamism(const ObjNumber_t iObj, fTime_t fTimeThreshInLane)
{
  float32 f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(iObj);
  float32 f_ABS_DistY = fABS(f_DistY);
  SLATE_t_Obj_CLassification t_ObjClassification = *pt_LAInput->t_RTE.pt_ObjClassification(iObj);

  if( (pt_LAOutput->b_TrajDynDetected == TRUE) && 
      (EGO_SPEED_X_OBJ_SYNC < LA_TRAJ_DYNAMISM_MAX_SPEED) && 
	  ( (f_ABS_DistY > LA_TRAJ_DYNAMISM_LAT_DIST_CHECK) || 
	    ((f_ABS_DistY < LA_TRAJ_DYNAMISM_LAT_DIST_CHECK) && (t_ObjClassification == SLATE_OBJCLASS_POINT))
	  )
    )  
  {
    fTimeThreshInLane = MAX_FLOAT(LA_TRAJ_DYNAMISM_MIN_INLANE_TIME_THRESHOLD, fTimeThreshInLane);
  }

  return (fTimeThreshInLane);
}

/*************************************************************************************************************************
  Functionname:    LA_v_AdaptObjInlapDropThresholdTrajDynamism                                                          */ /*!

  @brief           Update object inlap drop threshold based on Trajectory Dynamism detection flag

  @description     If Dynamism detected flag is TRUE, then inlap drop threshold is set to minimum value possible to prevent dropout. 

  @return          f_DropThresholdObj : The modified inlap drop threshold

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       f_DropThresholdObj : object inlap drop threshold  [0.0f   PI/2*RW_FCT_MAX]m

  @glob_in         -
  @glob_in         -

  @glob_out        -

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Configuration switch for FIP Lane Matrix
  @c_switch_part   LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE  : Configuration switch to Adapt Trajectory Dynamism detection to reduce Drop Threshold in Single City Lane Scenario
  @c_switch_full   LA_CFG_TRAJ_DYNAMISM_DETECTION           : Configuration switch to detect trajectory Dynamism in case based on OOI-0 Dist2Traj value

  @pre             -
  @post            -

  @created         13.02.2016


  @author          Nandan Chaudhari | Nandan.Chaudhari@continental-corporation.com
*************************************************************************************************************************/
float32 LA_v_AdaptObjInlapDropThresholdTrajDynamism(const ObjNumber_t iObj, float32 f_DropThresholdObj)
{
  /* Absolute Ratio of Object Lateral Velocity to Object Longitudinal Velocity */ 
  float32 f_ObjRatio;
  /* Absolute speed of OOI-0 in Longitudinal direction */
  float32 f_ObjAbsLongVel = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj) + *SLATE_pf_GetEgoLongVel();
  /* Absolute speed of OOI-0 in Lateral direction */
  float32 f_ObjAbsLatVel = *pt_LAInput->t_RTE.pf_ObjVrelY(iObj) + *SLATE_pf_GetEgoLongVel();
  /* Longitudinal displacement to the object (OOI-0) from Ego */
  float32 f_ooidistX =  *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
  boolean b_ObjisRel = SLATE_b_GetObjIsRelevant(iObj);
#if (LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE)
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const sint8 s_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 s_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#endif /* (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */
  SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj);
#endif /* (LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE) */

  if( (pt_LAOutput->b_TrajDynDetected == TRUE) && (b_ObjisRel == TRUE) && (EGO_SPEED_X_OBJ_SYNC < LA_TRAJ_DYNAMISM_MAX_SPEED))
  {
    /* Object Absolute Longitudinal velocity has to be greater than zero or else possibility for Division by zero */
    f_ObjAbsLongVel = MAX_FLOAT(CML_f_Delta, f_ObjAbsLongVel);
    f_ObjRatio = fABS(((f_ObjAbsLatVel)/(f_ObjAbsLongVel)));
    /*if OOI-0 is geometrically inlane for LA_RELEVANT_COUNTER_THRESH cycles, only then update Drop-Threshold*/ 
    /* Setting the drop threshold to -1 for the objects which are moving out to the left/right lane will lead to the late release of that object
    To prevent this, we check the f_ObjRatio value which says whether the cutout of an object is more probable or not.
    If an object is cutting out at less longitudinal distance and at slower speeds (city scenarios) then the object's lateral velocity is high compared to the object's longitudinal velocity
    so the object ratio is considered to identify the cutout scenarios */
    if( (pt_LAInput->t_OOI.pt_OOIRelObj->RelObjCounter >= LA_RELEVANT_COUNTER_THRESH) && 
        (f_ooidistX < LA_TRAJ_DYNAMISM_MAX_DISTX) && 
		(f_ObjRatio < LA_TRAJ_DYNAMISM_MAX_OBJ_RATIO)
      )
    { 
      f_DropThresholdObj = MIN(f_DropThresholdObj, LA_TRAJ_DYNAMISM_MIN_DROP_THRESHOLD);
    }
#if (LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE)
    /* Setting the drop threshold to -2 for the objects which have following conditions
    1. Relevant Object Counter > 3 (i.e. it is selected as OOI for more than 3 cycles)
    2. No Left or Right Lane available (i.e Single Lane. we are also consider Unknown Lane (-1) as No lane(0))
    3. Longitudinal Distance of object is in between 16m to 80m (Objects having distance below 10m is not considered since we observed bad releases or cutout)
    4. Objects having Moving or Stopped Dynamic Property */
    else if (   (pt_LAInput->t_OOI.pt_OOIRelObj->RelObjCounter > LA_RELEVANT_COUNTER_CITY_NO_LANE_THRESHOLD) 
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
             && (s_NumberOfLeftLanes <= 0) && (s_NumberOfRightLanes <= 0)
#endif /* (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */
             && (f_ooidistX > LA_TRAJ_DYNAMISM_CITY_NO_LANE_MIN_DISTX) && (f_ooidistX < LA_TRAJ_DYNAMISM_CITY_NO_LANE_MAX_DISTX) 
             && (t_ObjDynamicProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
            )
    {
      f_DropThresholdObj = MIN(f_DropThresholdObj, LA_TRAJ_DYNAMISM_CITY_NO_LANE_DROP_THRESHOLD);
    }
    else
    {
      /* Dummy else to satisfy QAC */
    }
#endif /* (LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE) */
  }

  return (f_DropThresholdObj);
}
#endif // end of LA_CFG_TRAJ_DYNAMISM_DETECTION

#if (LA_CFG_ADAPT_INLANE_FAR_TRUCK)
/*************************************************************************************************************************
  Functionname:    LA_v_AdaptObjInLaneTimeThresholdFarTrucks                                                          */ /*!

  @brief           Increase the Inlane Time Threshold for Trucks which are longitudinally at higher distance to avoid dropin

  @description     If there a truck at higher longitudinal distance, and and having negative relative velocity increase the inlane time threshold
                   Slowest lane trucks are often dropped in at higher distances especially in curve.

  @return          fTimeThreshInLane : The modified in-lane time threshold

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThreshInLane : Time threshold for object iObj                   [0 ... 100.0f] s

  @glob_in         *SLATE_pt_GetObjClassification(iObj)                     : Classification (into type) of object                             [type SLATE_t_Obj_CLassification defined in Rte_Type.h]
                    t_RTE.pf_ObjLongDisp(i) 								:Longitudinal displacement of an object i                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                    pt_LAInput->t_RTE.pt_ObjClassification(iObj)            : object class [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         
  @glob_in         

  @glob_out        void.

  @c_switch_part   -
  @c_switch_full   LA_CFG_ADAPT_INLANE_FAR_TRUCK

  @pre             -
  @post            -

  @created         08.01.2020


  @author          Anand Jose | Anand.jose@continental-corporation.com
*************************************************************************************************************************/
fTime_t LA_v_AdaptObjInLaneTimeThresholdFarTrucks(const ObjNumber_t iObj, fTime_t fTimeThreshInLane)
{
    const float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
    SLATE_t_Obj_CLassification t_ObjClassification = *pt_LAInput->t_RTE.pt_ObjClassification(iObj);
    float32 f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj);
    if( (f_ObjLongDisp > LA_FAR_TRUCK_DISPL_LONG)
        &&(t_ObjClassification == SLATE_OBJCLASS_TRUCK)
        &&(f_ObjVrelX < LA_FAR_TRUCK_VEL_REL) 
      )
    {
      fTimeThreshInLane = MAX_FLOAT((fTimeThreshInLane + LA_FAR_TRUCK_INLANE_TIME_FACT), fTimeThreshInLane);
    }
  return (fTimeThreshInLane);
}
#endif /*(LA_CFG_ADAPT_INLANE_FAR_TRUCK)*/

#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
/*************************************************************************************************************************
  Functionname:    LA_v_UpdateClusterVarianceLevel                                                                  */ /*!

  @brief           Update cluster variance level for obstacles

  @description     Loop over all objects to update the cluster variance level. If the situation specific criteria i.e Object 
                   distance to road border is fulfilled, increase the cluster variance difficulty level.

  @return          static void

  @param[in]       void :

  @glob_in         SLATE_b_GetObjIsDeleted(i) : Boolean if object i is deleted [TRUE, FALSE]
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information [0 ... 100]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s
  @glob_in         OBJ_LONG_DISPLACEMEN(i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of an object i [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border [0.f ... 30.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [-30.f ... 0.f]
  @glob_out        t_LA_InternalObjectData[i].ui_ClusterVarianceLevelforobstacles : Difficulty level of object i with high cluster variance
                   [LA_CLUST_VAR_LEVEL_LOW ... LA_CLUST_VAR_LEVEL_DIFFICULT]

  @c_switch_full   LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES : Config switch to Update Inlane Time value for obstacles based on Object's Distance to Road Border
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             Cluster Variance considered in acc quality e.g. acc quality set to FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL
                   in case of high cluster variance

  @created         04.06.2019
  @changed         04.06.2019

  @author          Pavan Kotra | pavan.kotra@continental-corporation.com | +91 (80) 6679-6000
*************************************************************************************************************************/
void LA_v_UpdateClusterVarianceLevelforObstacles(void)
{
  ObjNumber_t ObjNr;                                         /* Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1] */
  uint8 ui_ClusterVarianceLevel;                             /* Local cluster variance level */
  float32 f_ObjDistToRoadborder,                             /* Object position relative to road border close to ego. A positive value means object is inside road borders */
          f_RoadborderDistDelta;                             /* Delta between object and ego distance to road border */
  boolean b_ObjDist2RoadBorderCriteria;                     /* Object distance to road border criteria flag: ego is close to the road border while object is not */
  float32 f_ObjLongDisp;                                     /* Longitudinal displacement of object under consideration */
  float32 t_EgoVelObjSync,
          f_ObjAbsSpeedX;
  boolean b_ObjIsDeleted; 
  uint8 t_AccObjQuality;
  SLATE_t_Obj_CLassification t_ObjClassification;

  const sint8   i_NumOfLaneLeft  = pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft;  /* Get number of left lanes */
  const sint8   i_NumOfLaneRight = pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight;  /* Get number of right lanes */

  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1); ObjNr >= 0; ObjNr--)
  {
    /* Set default cluster variance level */
    ui_ClusterVarianceLevel = LA_CLUST_VAR_LEVEL_LOW;

    /* Get longitudinal displacement of object under consideration */
    f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr);

    /* Get Classification of the object */
    t_ObjClassification = *SLATE_pt_GetObjClassification(ObjNr);

    /* Get Absolute speed of the object in Longitudinal direction */
    f_ObjAbsSpeedX = *pt_LAInput->t_RTE.pf_ObjVrelX(ObjNr) + *SLATE_pf_GetEgoLongVel();

    /* Get Ego velocity */
    t_EgoVelObjSync = (*pt_LAInput->t_RTE.pf_EgoVelObjSync);

    /* Get the status of the object, whether it is deleted or not */
    b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(ObjNr);

    /* Get the ACC quality of the object */
    t_AccObjQuality = SLATE_u_GetAccQuality(ObjNr);

    if ( (b_ObjIsDeleted == FALSE)
      && ((t_AccObjQuality <= FUN_PRESEL_ACC_MIN_INLANE_OBJ_QUAL) && (t_AccObjQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL))
      && (t_EgoVelObjSync < LA_MAX_VEGO_FOR_OBSTACLE_SUPPR)
      && (f_ObjAbsSpeedX < LA_MAX_ABS_VELX_OF_OBSTACLE)
      && (f_ObjLongDisp < LA_MAX_DISTX_OF_OBSTACLE)
      && ((t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE) || (t_ObjClassification == SLATE_OBJCLASS_POINT) 
       || (t_ObjClassification == SLATE_OBJCLASS_PEDESTRIAN) || (t_ObjClassification == SLATE_OBJCLASS_BICYCLE))
       )
    {
       /* Set default value for b_ObjDist2RoadBorderCriteria criteria flag */
      b_ObjDist2RoadBorderCriteria  = FALSE;

      /*  If ego is close to road border: check object distance to road border criteria  */
      if ( (CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft))  < LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
        || (CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)) < LA_CLUST_VAR_ROAD_BORDER_DIST_MAX)
           || (i_NumOfLaneLeft == (sint8)0) || (i_NumOfLaneRight == (sint8)0)
         )
      {
        /* Compute object position relative to the road border close to ego. */
        /* A positive value means object is inside road borders */
        f_ObjDistToRoadborder = LA_f_ComputeObjDistToRoadBorderforObstacles(ObjNr);

        /* Compute delta between object and ego distance to road border */
        if  ( CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)) <= CML_f_Abs((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)) )
        {
          f_RoadborderDistDelta = CML_f_Abs(f_ObjDistToRoadborder - CML_f_Abs(pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft));
        }
        else
        {
          f_RoadborderDistDelta = CML_f_Abs(f_ObjDistToRoadborder - CML_f_Abs(pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight));
        }

        /* In case the object distance to road border is not default, check if the distance delta is above threshold */
        if ( (f_ObjDistToRoadborder < LA_OBJ_DIST_TO_ROADBORDER_DEFAULT)
          && (f_RoadborderDistDelta > LA_CLUST_VAR_ROAD_BORDER_DIST_DELTA_THRES_FOR_OBSTACLES)
           )
        {
          /* If the distance delta is high, it is probably not a cut-in or appraoch szenario */
          b_ObjDist2RoadBorderCriteria = TRUE;
        }
        else if ( (f_ObjDistToRoadborder >= LA_OBJ_DIST_TO_ROADBORDER_DEFAULT)
               && (f_ObjLongDisp > LA_OBJ_DISTX_TO_ROADBORDER_FOR_OBSTACLES_LOW) )
        {
          /* If object distance to road border not available at high longitudinal distances: */
          /* do increase cluster variance level anyway */
          b_ObjDist2RoadBorderCriteria = TRUE;
        }
        else
        {
          /* b_ObjDist2RoadBorderCriteria = FALSE */
        }
      }
     if (b_ObjDist2RoadBorderCriteria == TRUE) 
     {
        /* Set cluster variance level to difficult */
        ui_ClusterVarianceLevel = LA_CLUST_VAR_LEVEL_DIFFICULT;
     }
    }
    /* Store cluster variance level */
    t_LA_InternalObjectData[ObjNr].ui_ClusterVarianceLevelforobstacles = ui_ClusterVarianceLevel;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_f_ComputeObjDistToRoadBorder                                                                  */ /*!

  @brief           Compute object distance to the road border close to ego

  @description     Computes and returns the object distance to the road border closest to ego.
                   Dependant on longitudinal displacement of the object, distance to the road border is computed either
                   from the SI trajectory and road border information or the road estimation information.

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
  @c_switch_full   LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES : Config switch to Update Inlane Time value for obstacles based on Object's Distance to Road Border
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @created         04.06.2019
  @changed         04.06.2019

  @author          Pavan Kotra | pavan.kotra@continental-corporation.com | +91 (80) 6679-6000
*************************************************************************************************************************/
static float32 LA_f_ComputeObjDistToRoadBorderforObstacles(const ObjNumber_t ObjNr)
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
  if ( f_DistX < LA_OBJ_DISTX_TO_ROADBORDER_FOR_OBSTACLES_LOW )
  {
    if ( (CML_f_Abs(f_RoadDistLeft) <= CML_f_Abs(f_RoadDistRight))
          && ( (pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= (LA_OBJ_DIST_TO_ROADBORDER_LEFT_MIN))
      )
    {
      /* Get object distance to trajectory and compute distance to road border */
     f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistMeas.Y.f0;
     f_ObjDistToRoadborder = f_RoadDistLeft - (f_ObjDist2Traj);
    }
    else if ( (CML_f_Abs(f_RoadDistLeft) > CML_f_Abs(f_RoadDistRight))
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= (LA_OBJ_DIST_TO_ROADBORDER_RIGHT_MIN))
          )
    {
      /* Get object distance to trajectory and compute distance to road border */
      f_ObjDist2Traj = pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistMeas.Y.f0;
      f_ObjDistToRoadborder = f_ObjDist2Traj - (f_RoadDistRight);
    }
    else
    {
    /* If road border information not reliable, we cannot compute a distance to road border */
      f_ObjDistToRoadborder = LA_OBJ_DIST_TO_ROADBORDER_DEFAULT;
    }
  }
  /* For a higher longitudinal distance of object compute distance to road border from road estimation information */
  else if (f_DistX < LA_OBJ_DISTX_TO_ROADBORDER_FOR_OBSTACLES_HIGH)
  {
    
    /* If ego is close to left road border check if road estimation and road border information are reliable enough */
    if ( (CML_f_Abs(f_RoadDistLeft) <= CML_f_Abs(f_RoadDistRight))
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= (LA_OBJ_DIST_TO_ROADBORDER_LEFT_MIN))
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN_FOR_OBSTACLES)
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_TRACK_MIN_FOR_OBSTACLES)
      && (f_DistX <= (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated))
      )
    {
      /* Local variables */
      f_DistX_Sqr = SQR(f_DistX) * (0.5f);
      f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(ObjNr);

      /* Evaluate lateral object position relative to road center */
      f_ObjRoadDistY = f_DistY - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle))*f_DistX) - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*f_DistX_Sqr) - 
                                 ((((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1))*f_DistX*f_DistX_Sqr)*(1.0F/3.0f));

      /* Evaluate lateral object position relative to road border.  A positive value means object is inside road borders. */
      f_ObjDistToRoadborder = (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft) - f_ObjRoadDistY;
    }
    /* If ego is close to right road border check if road estimation and road border information are reliable enough */
    else if ( (CML_f_Abs(f_RoadDistLeft) > CML_f_Abs(f_RoadDistRight))
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= (LA_OBJ_DIST_TO_ROADBORDER_RIGHT_MIN))
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_CONF_MIN_FOR_OBSTACLES)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight) > LA_OBJ_DIST_TO_ROADBORDER_ROAD_TRACK_MIN_FOR_OBSTACLES)
           && (f_DistX <= (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated))
          )
    {
      /* Local variables */
      f_DistX_Sqr = SQR(f_DistX) * (0.5f);
      f_DistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(ObjNr);

      /* Evaluate lateral object position relative to road center */
      f_ObjRoadDistY = f_DistY - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle))*f_DistX) - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*f_DistX_Sqr) -
                                 ((((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1))*f_DistX*f_DistX_Sqr)*(1.0F/3.0f));

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
  return f_ObjDistToRoadborder;
}
#endif /* LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES */

/*************************************************************************************************************************
  Functionname:    LA_b_CheckEgoLaneAssocValidity                                                                   */ /*!

  @brief           The default value to have no impact to Functional Lane association is updated here

  @description     The default value to have no impact to Functional Lane association is updated here

  @return          boolean : used to updated Functional Lane Association                           [TRUE or FALSE]

  @param[in]       iObjNr : object number, which is checked for overlap with relevant object       [ 0 ... EM_N_OBJECTS-1]

  @glob_in         None
  @glob_out        pt_LAOutput->t_LAObjOutputList[iObjNr].b_SetEgoLaneValidity : boolean to denote
                                      if overlap of relevant object and current object is detected [TRUE or FALSE]

  @c_switch_part   None
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None
  @post            None

  @created         06.08.2019
  @changed         06.08.2019

  @author          Rahul Raj | Rahul.Raj@continental-corporation.com 
*************************************************************************************************************************/
boolean LA_b_CheckEgoLaneAssocValidity(const ObjNumber_t iObjNr)
{
  /* The default value to have no impact to Functional Lane association is updated here,
     the actual functionality is currently implemented only in ARS510TA19 */
  pt_LAOutput->t_LAObjOutputList[iObjNr].b_SetEgoLaneValidity = TRUE;

  return (pt_LAOutput->t_LAObjOutputList[iObjNr].b_SetEgoLaneValidity);
}

#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)
/*************************************************************************************************************************
  Functionname:    LA_f_GetInLaneTimeCurveStatThreshold                                                                  */ /*!

  @brief           Increase the In-Lane Timer for Stationary Object on Curve scenario to prevent False Positives

  @description     Increase the In-Lane Timer for Stationary on Curve scenario to prevent False Positives
                   Conditions which are considered to Increase the In-Lane Timer are
                     Relevant object is not present
                     Longitudinal distance of the object should be above 30m (to prevent close Valid Stationary Approaches)
                     Road Type is City
                     Steep Curve is present in either direction and corresponding left and right lane should be available
                     Object should not be In-Lane (confirmed with all criteria)

  @return          fTime_t : Increased Time threshold for Stationary object [0 ... 100.0f] s

  @param[in]       iObj : Object Number (Object ID)                         [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThreshInLane : Time threshold for object iObj       [0 ... 100.0f] s

  @glob_in         pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr : Relevant Object Number               [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType : Reference to FIP road type     [FIP_t_FusedRoadType as defined in fip_ext.h]
  @glob_in         pt_LAInput->t_RTE.pf_ObjLongDisp(iObjNr) : Longitudinal displacement of object  [-5*RW_FCT_MAX    5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve provided by VDY                        [-1 ... +1] m^-1
  @glob_in         pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft  : Number of lanes on the left    [full range of datatype as defined in Rte_Type.h]
  @glob_in         pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight : Number of lanes on the right   [full range of datatype as defined in Rte_Type.h]

  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].b_SetInLaneTimeCurve : Boolean to indicate increase in In-Lane timer for Stationry Objects on Curve [TRUE or FALSE]

  @c_switch_part   -
  @c_switch_full   LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT : Update Inlane Timer value for Stationary Objects on Curve
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None
  @post            None

  @created         06.09.2019
  @changed         06.09.2019

  @author          Rahul Raj | Rahul.Raj@continental-corporation.com
*************************************************************************************************************************/
fTime_t LA_f_GetInLaneTimeCurveStatThreshold(const ObjNumber_t iObj, fTime_t fTimeThreshInLane)
{
  ObjNumber_t t_RelObjNr = pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr;
  float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
  float32 f_EgoCurve = *pt_LAInput->t_RTE.pf_EgoCurve;
  FIP_t_FusedRoadType t_FIPFusedRoadType = pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType;
  sint32 s_NumberLanesLeft = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  sint32 s_NumberLanesRight = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);

  if (    (t_RelObjNr == OBJ_INDEX_NO_OBJECT)
       && (f_ObjLongDisp > LA_LONG_DISTANCE_CURVE_STAT)
       && (t_FIPFusedRoadType == FIP_ROAD_TYPE_CITY)
       && (((f_EgoCurve < C_F32_DELTA) && (f_EgoCurve < -LA_IN_LANE_TIME_THRESHOLD_CURVE_STAT) && (s_NumberLanesRight > 0)) ||
           ((f_EgoCurve > C_F32_DELTA) && (f_EgoCurve >  LA_IN_LANE_TIME_THRESHOLD_CURVE_STAT) && (s_NumberLanesLeft > 0)))
       && (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState != OBJ_STATE_INLANE))
  {
    fTimeThreshInLane = MAX_FLOAT((fTimeThreshInLane + LA_IN_LANE_TIME_THRESHOLD_CURVE_FACTOR), LA_IN_LANE_TIME_THRESHOLD_CURVE_MAX);
    pt_LAOutput->t_LAObjOutputList[iObj].b_SetInLaneTimeCurve = TRUE;
  }
  else
  {
    pt_LAOutput->t_LAObjOutputList[iObj].b_SetInLaneTimeCurve = FALSE;
  }

  return fTimeThreshInLane;
}
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */

#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
/*************************************************************************************************************************
  Functionname:    LA_u_GetObjOutlaneCounterThreshold                                                                  */ /*!

  @brief           Set outlane counter threshold based on Situation 

  @description     Set Different Out-lane counter threshold for different situations to prevent False Negatives

  @startuml
    start
        Partition LA_u_GetObjOutlaneCounterThreshold{
    if (Object is Relevant) then (Yes) 
            if (Object dynamic property is moving) then (Yes) 
                    : Moving Object Specific Counter Threshold;
                    If (relative velocity above a threshold) then (Yes)
                        : High Relative velocity Specific Counter Threshold;
                    Else (No)
                        If (Object Displacement less than a threshold) then (Yes)
                        If(Strong Curve and low Ego speed) then (Yes)
                            : Curve Specific Counter Threshold;
                        Else (No)
                           Endif
                        Else (No)
                        If (Curve Entry/Exit at higher distance) then (Yes)
                            : Distant Curve Specific Counter Threshold;
                        Else (No)
                        Endif
                        Endif
                        If (Narrow Highway Criteria) then (Yes)
                          : Narrow Highway Specific Counter Threshold;
                        Else (No)
                        Endif
                        If (Object Associated to Ego lane based on Camera Trajectory) then (Yes)
                          : Camera Ego lane Specific Counter Threshold;
                        Elseif (Object Associated to Left or right lane based on Camera Trajectory) then (Yes)
                          : Camera Outlane Specific Counter Threshold;
                        Endif
                        If (Object Trace cuts out) then (Yes)
                          : Cutout Specific Counter Threshold;
                        Else (No)
                        Endif
                    Endif
                    If (Ego does a lane change) then (Yes)
                        : Lane Change Specific Counter Threshold;
                    Else (No)
                    Endif
            Else (No)
                : Non Moving Object Specific Counter Threshold;
            Endif
            Else (No)
                : Other Inlane objects Specific Counter Threshold;
            endif
             }
    stop
  @enduml

  @return          uint8 : Situation Specific Outlane Counter threshold for object [0u ... LA_OUTLANE_CYCLE_MAX]

  @param[in]       iObj : Object Number (Object ID)      [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       u_In2OutlaneCounterThreshold : Outlane Counter threshold for object iObj       [0u ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]

  @glob_in		   pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision	: Object i was selected by blocked path  [TRUE, FALSE]
  @glob_in		   pt_LAOutput->b_EgoObjTracCutOut[iObj] 	: Object i cuts out based on Trace  [TRUE, FALSE]
  @glob_in		   pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb	:  Ego Lane change probability
  @glob_in		   pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase	: Lane Change Phase
  @glob_in		   *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj) : Dynamic property of object i [EM_t_ARS_DynamicProperty as defined in rte_type.h]
  @glob_in		   *(pt_LAInput->t_CP.pf_CourseCurve)	: Ego course curvature [1/m] 
  @glob_in		   *pt_LAInput->t_RTE.pf_ObjVrelX(iObj)	 : Relative velocity of object i [-330.f ... 330.f] m/s
  @glob_in		   *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in		   *pt_LAInput->t_RTE.pf_EgoVelObjSync : Velocity of the ego vehicle             [-330.f ... 330.f] m/s
  @glob_in		   pt_LAOutput->t_LAObjOutputList[iObj].ObjCor.dRelevantZeit : timer for relevancy [0 .. LA_RELEVANTZEIT_MAX] with LA_RELEVANTZEIT_MAX defined in la_par.h
  @glob_in		   pt_LAOutput->f_TurnIndLeftTime	: Left Indicator timer [-5.f ... 0.f] s
  @glob_in		   pt_LAOutput->f_TurnIndRightTime	: Right Indicator timer [-5.f ... 0.f] s
  @glob_in		   pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc [0.....3]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType : Reference to FIP road type     [FIP_t_FusedRoadType as defined in fip_ext.h]

  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_part   LA_CFG_NARROW_HIGHWAY_CRITERIA : LA switch for narrow highway criteria check
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : enable restriction based on relevant object trace
  @c_switch_part   LA_CFG_RESTRICTION_EGO_LANE_CHANGE : Switch to eneble restriction for ego lane change.
  @c_switch_part   LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC : Switch to eneble Camera trajectory based lane association. 
  @c_switch_full   LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD : Outlane counter based on Situation
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None
  @post            None

  @created         30.03.2020
  @changed         30.03.2020

  @author          Anand Jose | Anand.Jose@continental-corporation.com
*************************************************************************************************************************/
uint8 LA_u_GetObjOutlaneCounterThreshold(const ObjNumber_t iObj, uint8 u_In2OutlaneCounterThreshold)
{
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  boolean b_DistToHighCCCriteria; /* Flag for distance to high curvature change criteria */ 
#endif
#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
  boolean b_NarrowHighwayCriteria; /* Flag for narrow highway criteria */
#endif
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  const boolean b_ObjectTraceCutsOut = pt_LAOutput->b_EgoObjTracCutOut[iObj]; /*Flag for Cutting out Object based on Trace */
#endif
  const uint8 u_LALaneChangeProb = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb; /* Lane Change Probability */
  const SIT_LC_t_LaneChangePhaseEnum tLCPhase = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase;  /* Lane Change Phase */
  const SLATE_t_Obj_DynamicProperty f_DynamicProperty = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj); /* Object Dynamic Property */
  const fCurve_t f_Curve = *(pt_LAInput->t_CP.pf_CourseCurve);  /* get curvature */
  const fCurve_t f_AbsCurve = fABS(f_Curve); /* Absolute curvature */
  const float32 f_ObjAbsLongRVel = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj); /* Object's longitudinal relative velocity */
  const float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj); /* Object's longitudinal Displacement */
  const float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;   /* Get ego velocity */
  const float32 f_RelevTime = pt_LAOutput->t_LAObjOutputList[iObj].ObjCor.dRelevantZeit; /*Object relevent time */
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
  const float32 f_IndTimeLeft = pt_LAOutput->f_TurnIndLeftTime; /*Left Indicator timer for 5s */
  const float32 f_IndTimeRight= pt_LAOutput->f_TurnIndRightTime;/*Right Indicator timer for 5s */
#endif
#if (LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC)
  LA_t_ObjCamTrajLanAssocEnum t_ObjCamLaneAssoc = pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc;
  const FIP_t_FusedRoadType t_RoadType = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
#endif/* (LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC) */
  const boolean b_ObjisRel = SLATE_b_GetObjIsRelevant(iObj);

  if(b_ObjisRel == TRUE)
  {
      if ( f_DynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
      {
         /* For moving objects */
        u_In2OutlaneCounterThreshold = LA_OUTLANE_CYCLE_MOVING_OBJ;
    
        if((fABS(f_ObjAbsLongRVel)) > LA_OUTLANE_CYCLE_REL_VEL_MAX )
        {
            /* Small counter for Object with Higher relaive velocity */
            u_In2OutlaneCounterThreshold  = MIN( LA_OUTLANE_CYCLE_HIGH_REL_VEL, u_In2OutlaneCounterThreshold);
        }
        else
        {	
            /* Object with similar longitudinal relative velocity */	
            if(f_ObjLongDisp < LA_OUTLANE_OBJ_DISPL_CLOSE) 
            {
                /* Close Objects */
                if( (f_EgoVelObjSync < LA_OUTLANE_EGO_SPEED_LOW) && (f_AbsCurve > LA_OUTLANE_CYCLE_HIGH_CURVE))
                {
                    /* Big counter for Strong curve and low speed */
                    u_In2OutlaneCounterThreshold  = MAX( LA_OUTLANE_CYCLE_CLOSE_CURVE, u_In2OutlaneCounterThreshold);
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else 
            {
                /* Far Objets */
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
                /* Check distance to high curvature change (curve entry/exit) criteria */
                b_DistToHighCCCriteria = LA_b_CheckObjDistToCCCriteria(iObj);
                if (b_DistToHighCCCriteria == FALSE)
                {
                    /* Big counter in case object is above the distance where a high curvature change is defined */
                    u_In2OutlaneCounterThreshold  = MAX( LA_OUTLANE_CYCLE_DIST_HIGH_CURV, u_In2OutlaneCounterThreshold);
                }
                else
                {
                    /* Do Nothing */
                }
#endif
            }
#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
            /* Check Narrow Highway criteria */
            b_NarrowHighwayCriteria = LA_b_CheckNarrowHighwayCriteria(iObj);
            if (b_NarrowHighwayCriteria == FALSE)
            {
                /* Big Counter in case the narrow highway criteria is false */
                u_In2OutlaneCounterThreshold  = MAX(LA_OUTLANE_CYCLE_DIST_NARROW_HIGH, u_In2OutlaneCounterThreshold);
            }
            else
            {
                /* Do Nothing */
            }
#endif

#if (LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC)
        /* If the object is associated to ego lane by camera trajectory lane association, give higher counter */
        if ( (tLCPhase != LC_LANECHANGE) && (t_ObjCamLaneAssoc == LA_OBJ_CAM_LANE_EGO) )
        {
           u_In2OutlaneCounterThreshold  = MAX(LA_OUTLANE_COUNT_CAM_LANE_EGO, u_In2OutlaneCounterThreshold); /* PRQA S 2995 *//* Date: 2020-09-07, Reviewer:Anand Jose , Reason:This warning is suppressed as variable can be fed with higher or lower vavlue anywhere above this. */
        }
        /* If the object is associated to left or right lane by camera trajectory lane association, give lower counter */
        else if ( (    ((t_ObjCamLaneAssoc == LA_OBJ_CAM_LANE_LEFT) && (f_Curve < LA_OUTLANE_COUNT_CAM_LANE_EGO_CURVE) )
                    || ((t_ObjCamLaneAssoc == LA_OBJ_CAM_LANE_RIGHT)&& (f_Curve > -LA_OUTLANE_COUNT_CAM_LANE_EGO_CURVE))
                  )
                  && (f_ObjLongDisp < LA_OUTLANE_COUNT_CAM_LANE_OBJ_DIST) 
                  && (f_EgoVelObjSync < LA_OUTLANE_COUNT_CAM_LANE_EGO_VEL) 
                  && (t_RoadType == FIP_ROAD_TYPE_CITY)
                )
        {
          u_In2OutlaneCounterThreshold = MIN(LA_OUTLANE_CYCLE_MIN, u_In2OutlaneCounterThreshold); /* PRQA S 2995 *//* Date: 2020-11-13, Reviewer:Anand Jose , Reason:This warning is suppressed as variable can be fed with higher or lower vavlue anywhere above this. */
        }
        else
        {
            /* Do Nothing */
        }
#endif /*(LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC)*/

#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
            if(fABS(f_Curve) < LA_OUTLANE_CYCLE_SMALL_CURVE)//Almost straight trajectory
            {
                /* Small Counter when the Object Cuts out*/
                if(b_ObjectTraceCutsOut == TRUE)
                {
                    u_In2OutlaneCounterThreshold  = MIN(LA_OUTLANE_CYCLE_CUTOUT, u_In2OutlaneCounterThreshold);
                }
                else
                {
                    /* Do Nothing */
                }
            }
#endif
        }
        if(((tLCPhase == LC_PRELANECHANGE)||(tLCPhase == LC_LANECHANGE)) && (u_LALaneChangeProb > LA_OUTLANE_LANE_CHNG_PROB))
        {
          /* During the Ego lane change*/
          if(f_RelevTime > LA_OUTLANE_OBJ_RELEV_TIME)
          {
              /* Small Counter, Mostly Releasing Object */
              u_In2OutlaneCounterThreshold  = MIN( LA_OUTLANE_CYCLE_LANE_CHANGE, u_In2OutlaneCounterThreshold);
          }
          else
          {
              /* Big Counter, Mostly newly picked Object */
              u_In2OutlaneCounterThreshold  = MAX( LA_OUTLANE_CYCLE_PICKUP, u_In2OutlaneCounterThreshold);
          }
        }
        else
        {
          /* Do Nothing */
        }
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
        if( ((f_IndTimeLeft > LA_OUTLANE_ZERO_THRESHOLD) && (f_Curve > LA_OUTLANE_ZERO_THRESHOLD)) 
          ||((f_IndTimeRight > LA_OUTLANE_ZERO_THRESHOLD) && (f_Curve < LA_OUTLANE_ZERO_THRESHOLD)) 
          )
          {
            /* Ego is making a lane change by turning on the Indicator */
            if(f_RelevTime > LA_OUTLANE_OBJ_RELEV_TIME)
            {
                /* Small Counter , Mostly Releasing Object */
                u_In2OutlaneCounterThreshold  = MIN( LA_OUTLANE_CYCLE_TURN_IND, u_In2OutlaneCounterThreshold);
            }
            else 
            {
                /* Big Counter, Mostly newly picked Object */
                u_In2OutlaneCounterThreshold  = MAX( LA_OUTLANE_CYCLE_PICKUP, u_In2OutlaneCounterThreshold);
            }
          }
          else
          {
            /* Do Nothing */
          }
#endif
      }
      else
      {
        /* Small counter for Objects other than moving */
        u_In2OutlaneCounterThreshold = LA_OUTLANE_CYCLE_MIN;
      }
  }
  else
  {    
      /* Small counter for Other Inlane objects */
	  u_In2OutlaneCounterThreshold = LA_OUTLANE_CYCLE_MIN; 
  }	
  return u_In2OutlaneCounterThreshold;
}
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */

#if(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
/*************************************************************************************************************************
  Functionname:    LA_u_GetObjAssocLaneBasedOnCameraTrajectory                                                                  */ /*!

  @brief           Check Object's lane association with respect to Camera Trajectory 

  @description     Camera trajectory can be extended even beyond the visibility distance if the quality is good.
                   In this approach we are calculating virtual camera trajectory and 
                   checking whether the object associated to Ego, Left or Right lane. 

  @startuml
    start
      Partition LA_u_GetObjAssocLaneBasedOnCameraTrajectory {
        If (Road type is highway) then (yes)
          : Camera standard lane width is Highway Standard width;
        Else (false)
          : Camere standard lane width is City Standard width;
        Endif
        if (Maximum possible lane width is the standard lane width and existance quality is above a threshold
            Or At least one lane has good confidence and object is within the visibility distance) then (Yes) 
        if (Left visibility diatance is higher than right) then (yes)
            : Use the left marker to find the distance to trajectory;
        Else (false)
            : Use the Right marker to find the distance to trajectory;
        Endif                
        :Get the Distance to trajectory;	
        If (Object lateral distance is within the camera lane marker ) then (yes)
          : Object is associated to Ego Lane;
        Elseif (Object lateral distance is left to the left camera lane marker ) then (yes)
          : Object is associated to Left Lane;
        Elseif (Object lateral distance is right to the right camera lane marker ) then (yes)
          : Object is associated to Right Lane;
        Endif
        Else (false)
          : Associated Lane Unknown;
        Endif

        If (Associated lane is not unknown ) then (yes)
          : Calculate the lane association probability as a factor of object’s     longitudinal distance and lane marker visibility distance;
        Endif
        If (lane width or marker distance is greater than a limit) then (yes)
          : Assign Specific confidence value;
        Endif
        If (one lane curve is towards right and other lane curve is towards left) then (yes)
          : Assign Specific confidence value;
        Endif
        If (Lane change detected) then (yes)
          : Assign Specific confidence value;
        Endif
        If (high curve detected) then (yes)
          : Assign Specific confidence value;
        Endif
     }
    stop
  @enduml

  @return        t_ObjCamTrajLaneAssoc : Object's Camera trajectory based lane association                                                          [0 ... 3]

  @param[in]     iObj : Object Number (Object ID)                                                                                                   [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in       (*pt_LAInput->t_RTE.pf_ObjLatDisp(i) : Lateral displacement of an object i                                                         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in       pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType: Reference to FIP road type                                                         [FIP_t_FusedRoadType as defined in fip_ext.h]
  @glob_in       pt_LAInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[i].u_ExistanceProbability : Probability of existence for camera lane marker i     [0u...100u] 
  @glob_in       pt_LAInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[i].f_MarkerDist : Distance to camera lane marker i                                [Full range of float32  >= 0.F] 
  @glob_in       pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[i].CourseInfoSegNear.f_Length: length of near segment for camera lane marker i        [full range of datatype float32 with >= 0.f] m
  @glob_in       pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[i].CourseInfoSegNear.f_C0: camera lane i curvature as input of camera                 [full range of datatype float32] 1/m
  @glob_in       pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[i].CourseInfoSegNear.f_C1: camera lane i curvature change as input of camera          [full range of datatype float32] 1/m
  @glob_in       *pt_LAInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                                                    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in       pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb	:  Ego Lane change probability
  @glob_in       pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase	: Lane Change Phase
  @glob_in       *(pt_LAInput->t_CP.pf_CourseCurve)	: Ego course curvature [1/m] 

  @c_switch_full   LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ : FCT switch for ACC LA (Lane Association) sub-component

  @pre             None
  @post            None

  @created         17.09.2020
  @changed         17.09.2020

  @author          Anand Jose | Anand.Jose@continental-corporation.com
*************************************************************************************************************************/
LA_t_ObjCamTrajLanAssocEnum LA_u_GetObjAssocLaneBasedOnCameraTrajectory(const ObjNumber_t iObj)
{

  const float32 f_LatDisp = (*pt_LAInput->t_RTE.pf_ObjLatDisp(iObj));
  const FIP_t_FusedRoadType iRoadTypeLevel= (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
  const uint8 u_LCProb = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb; /*!< Lane change probability */
  const SIT_LC_t_LaneChangePhaseEnum tLCPhase = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase;  /* Lane Change Phase */
  const fCurve_t f_Curve = *(pt_LAInput->t_CP.pf_CourseCurve);  /* get ACC curvature */
  const uint8 u_ExistanceProbabilityR = pt_LAInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability; /* Right lane marker existance probability*/
  const uint8 u_ExistanceProbabilityL = pt_LAInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability; /* Left lane marker existance probability*/
  float32 f_RightMarkerDist = pt_LAInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist; /* Right lane marker distance */
  float32 f_LeftMarkerDist = pt_LAInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist; /* Left lane marker distance */
  const float32 f_VisibDistLeft = pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[FIP_CL_MK_LEFT].CourseInfoSegNear.f_Length; /* Left lane visibility distance */
  const float32 f_VisibDistRight = pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[FIP_CL_MK_RIGHT].CourseInfoSegNear.f_Length; /* Right lane visibility distance */
  const float32 f_CamCurveLeft = pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[FIP_CL_MK_LEFT].CourseInfoSegNear.f_C0; /* Left lane marker curve */
  const float32 f_CamCurveChangeLeft = pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[FIP_CL_MK_LEFT].CourseInfoSegNear.f_C1; /* Left lane marker curvature change*/
  const float32 f_CamCurveRight = pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[FIP_CL_MK_RIGHT].CourseInfoSegNear.f_C0; /* Right lane marker curve */
  const float32 f_CamCurveChangeRight = pt_LAInput->t_RTE.pt_CamLaneData->CourseInfo[FIP_CL_MK_RIGHT].CourseInfoSegNear.f_C1; /* Right lane marker curvature change*/
  float32 f_LeftMarkerDistAbs = fABS(f_LeftMarkerDist);
  float32 f_RightMarkerDistAbs = fABS(f_RightMarkerDist);
  const float32 f_ObjDistX = (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj)) + FCT_fBumperToCoG; /* Object's longitudinal distance */
  const float32 f_ObjDistY = 0.f;
  CP_t_GDBTrajectoryData t_CamCurve;
  CAL_t_TrajRefPoint RefPoint;
  float32 f_LeftCamMarkAtX , f_RightCamMarkAtX;
  float32 f_CamLanewidthStd, f_CamLanewidthMax;
  LA_t_ObjCamTrajLanAssocEnum t_ObjCamTrajLaneAssoc = LA_OBJ_CAM_LANE_UNDEFINED;
  float32 f_ObjCamTrajLaneAssocProb = LA_CAM_TRAJ_LA_PROB_ZERO;
  float32 f_MaxVisibDist;

  if ((iRoadTypeLevel == FIP_ROAD_TYPE_HIGHWAY) || (iRoadTypeLevel == FIP_ROAD_TYPE_COUNTRY))
  {
    f_CamLanewidthStd = LA_STANDARDLANEWIDTHSEEK; /* Assign the standard Highway lane width */
  }
  else
  {
    f_CamLanewidthStd = LA_CITYLANEWIDTHSEEK; /* Assign the standard City lane width */
  }

  f_CamLanewidthMax = f_CamLanewidthStd + LA_OBJ_LANE_ASSOC_CAM_TRAJ_LANEWIDTH_OFFSET;

  if ( 
    ( ((u_ExistanceProbabilityL  >= LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB) || (u_ExistanceProbabilityR  >= LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB)) /* At least one near lane has good confidence */
    && ((f_LeftMarkerDist - f_RightMarkerDist) <= f_CamLanewidthStd ) )/* Added lane width should not exceed the standard lane width */
    || ( ((u_ExistanceProbabilityL  >= LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB_MAX) || (u_ExistanceProbabilityR  >= LA_OBJ_LANE_ASSOC_CAM_TRAJ_EXIST_PROB_MAX)) 
          && (f_ObjDistX < MAX(f_VisibDistLeft,f_VisibDistRight) ) ) /* Lane width can be more than the standard with if marker confidence is high*/
    )
  {
    /* If left marker distance is not available, calculate virtually from the right marker distance */
    f_LeftMarkerDistAbs = (f_LeftMarkerDistAbs > 0.f) ? f_LeftMarkerDistAbs : (f_CamLanewidthStd - f_RightMarkerDistAbs); 
    f_LeftMarkerDist = f_LeftMarkerDistAbs;
    /* If right marker distance is not available, calculate virtually from the left marker distance */
    f_RightMarkerDistAbs = (f_RightMarkerDistAbs > 0.f) ? f_RightMarkerDistAbs : (f_CamLanewidthStd - f_LeftMarkerDistAbs); /* Distance to the Camera Right lane marker from Ego */
    f_RightMarkerDist = - f_RightMarkerDistAbs;

    /* Take the camera curve parameters from the longer visibility lane marker */
    if (f_VisibDistLeft > f_VisibDistRight) 
    {
      t_CamCurve.fTrajC0 = f_CamCurveLeft;
      t_CamCurve.fTrajC1 = f_CamCurveChangeLeft;
      f_MaxVisibDist = f_VisibDistLeft;
    }
    else
    {
      t_CamCurve.fTrajC0 = f_CamCurveRight;
      t_CamCurve.fTrajC1 = f_CamCurveChangeRight;
      f_MaxVisibDist = f_VisibDistRight;
    }

    /* Get the trajectory reference point information for given (f_ObjDistX,f_ObjDistY) point using the passed trajectory */
    LA_v_CalculateDistance2Traj(f_ObjDistX, f_ObjDistY, (boolean) pt_LAInput->t_CP.pt_TrajectoryData->State.EgoCourseOnly, &t_CamCurve, &RefPoint);

    f_LeftCamMarkAtX = f_LeftMarkerDist - RefPoint.fDistToTraj ; /* Get the left camera bracket position on camera trajectory at object x distance */
    f_RightCamMarkAtX = f_RightMarkerDist -  RefPoint.fDistToTraj ; /* Get the right camera bracket position on camera trajectory at object x distance */

    if ( (f_LatDisp <= f_LeftCamMarkAtX ) && ( f_LatDisp >= f_RightCamMarkAtX ) ) /* Check object's Y position is within the camera brackets calculated */
    {
      t_ObjCamTrajLaneAssoc  = LA_OBJ_CAM_LANE_EGO;
    }
    else if(f_LatDisp > f_LeftCamMarkAtX ) /* Check object's Y position is left to the left camera bracket calculated */
    {
      t_ObjCamTrajLaneAssoc  = LA_OBJ_CAM_LANE_LEFT;
    }
    else if(f_LatDisp < f_RightCamMarkAtX ) /* Check object's Y position is right to the right camera bracket calculated */
    {
      t_ObjCamTrajLaneAssoc  = LA_OBJ_CAM_LANE_RIGHT;
    }
    else
    {
      /* Do Nothing */
    }

    /* Calculate Confidence of the camera trajectory based lane association */
    if (t_ObjCamTrajLaneAssoc != LA_OBJ_CAM_LANE_UNDEFINED)
    {
        if (f_ObjDistX > C_F32_DELTA)
        {
          /* Calculate confidence based on the object distance and camera visibility distance */
          f_ObjCamTrajLaneAssocProb = (f_MaxVisibDist/f_ObjDistX);
          f_ObjCamTrajLaneAssocProb = MIN(f_ObjCamTrajLaneAssocProb, LA_CAM_TRAJ_LA_PROB_DIST_FACTOR_MAX);
          /* Adapt percentage based on both lane marker existance probability */
          f_ObjCamTrajLaneAssocProb *= ((float32)((u_ExistanceProbabilityL + u_ExistanceProbabilityR)/LA_CAM_TRAJ_LA_PROB_DIV));/* PRQA S 4394 *//* Date: 2020-11-13, Reviewer:Anand Jose , Reason:This warning is suppressed as there is no data loss. */
        }
        /* Less confidence if lane width or marker distance is greater than a limit */
        if ( ( (f_LeftMarkerDist - f_RightMarkerDist) > f_CamLanewidthMax ) || (f_RightMarkerDistAbs > (f_CamLanewidthMax * LA_CAM_TRAJ_LA_PROB_HALF)) || (f_LeftMarkerDistAbs > (f_CamLanewidthMax * LA_CAM_TRAJ_LA_PROB_HALF)) )
        {
          f_ObjCamTrajLaneAssocProb = LA_CAM_TRAJ_LA_PROB_LANE_WIDTH;
        }
        /* Less confidence if one lane curve is towards right and other lane curve is towards left */
        if ( ( (f_CamCurveLeft < -C_F32_DELTA) && (f_CamCurveRight > C_F32_DELTA)) || ( (f_CamCurveLeft > C_F32_DELTA) && (f_CamCurveRight < -C_F32_DELTA)) )
        {
          f_ObjCamTrajLaneAssocProb = LA_CAM_TRAJ_LA_PROB_OPPOSITE_CURVE;
        }
        /* Lesser confidence during lane change */
        if ((u_LCProb > LA_CAM_TRAJ_LA_PROB_LC_THD) || (tLCPhase != LC_NO_LANECHANGE))
        {
          f_ObjCamTrajLaneAssocProb = LA_CAM_TRAJ_LA_PROB_LANE_CHANGE; 
        }
        /* Lesser confidence in high curve */
        if ( fABS(f_Curve) > LA_CAM_TRAJ_LA_PROB_CURVE_THRES )
        {
           f_ObjCamTrajLaneAssocProb = LA_CAM_TRAJ_LA_PROB_HIGH_CURVE;
        }
    }
  }
  pt_LAOutput->t_LAObjOutputList[iObj].f_ObjCamTrajLaneAssocProb = f_ObjCamTrajLaneAssocProb;

  return t_ObjCamTrajLaneAssoc;
} 
#endif /*(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */
/** @} end defgroup */
#endif /*!< FCT_CFG_ACC_LANE_ASSOCIATION */

