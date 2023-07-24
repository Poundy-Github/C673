/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la.h

DESCRIPTION:               Internal header file for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.37 $

LEGACY VERSION:            Revision: 2.1.1.4

**************************************************************************** */
#ifndef LA_H_INCLUDED
#define LA_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#include "la_par.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup la
@{ */
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#define LA_INVALID_INLAP                        (-999.f)
/*! @brief CP_INVALID_INLAP_VAR */
#define LA_INVALID_INLAP_VAR                    (1.0E10f)

/*Default distance from ego front to object in blocked path*/
#define LA_SCENE_DEFAULT_DISTTOOBJ  (250.f) 
/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/* TODO - Remove direct access to output variable */
#define LA_SET_OBJ_TRAJ_REF_POINT(iObj,pRefPoint)        ((t_LA_Output.t_LAObjOutputList[iObj].ObjTrajRefPoint) = (pRefPoint))            /*TPObject[iObj].SI.ObjTrajRefPoint = pRefPoint*/
#define LA_SET_OBJ_TRAJ_REF_POINT_LAST(iObj,pRefPoint)   ((t_LA_Output.t_LAObjOutputList[iObj].ObjTrajRefPointLastCycle) = (pRefPoint))   /*TPObject[iObj].SI.ObjTrajRefPointLastCycle = pRefPoint*/
/*!@brief   Configuration switch to use EM kinematics instead of Kalman calculation for Dist2Traj */
#define LA_CFG_DIST2TRAJ_EM                         1

/*! @brief   these parameters determine the dynamic limits of the filter */ 
#define LA_MAX_VREL  (11.0F / C_KMH_MS)
/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*!< Information about parameters used to check if there are other objects in area relative to reference object */
typedef struct {
  /* Defines area and velocity delta in relation to reference object in which objects can be located */
  float32 f_DeltaDistXLower; /* Maximum distance delta in negative X direction e.g. (-20.f) */
  float32 f_DeltaDistXUpper; /* Maximum distance delta in positive X direction e.g. (40.f)  */
  float32 f_DeltaDistYLower; /* Maximum distance delta in negative Y direction e.g. (-6.f)  */
  float32 f_DeltaDistYUpper; /* Maximum distance delta in positive Y direction e.g. (6.f)   */
  float32 f_DeltaVelLower;   /* Velocity delta lower threshold e.g. (-999.f)                */
  float32 f_DeltaVelUpper;   /* Velocity delta upper threshold e.g. (-5.f/3.6F)             */
} LA_t_FindObjInAreaArgs;

typedef struct { // PRQA S 635
  /* date: 2015-07-06, reviewer: Rachit Sharma, reason: Project specific type definition */
  boolean bUseSeekLaneWidthOnly : 1;
  boolean bEnableAddExtensionObjectApproximation: 1;
  boolean bEnableAddRestrictionCurveOuterBorder : 1;
  boolean bEnableRestrictionTargetOutsideBrackets : 1;
  boolean bEnableRestrictionAnalogRoadBorder : 1;
  boolean bEnableRestrictionNeighbourhoodRelObj : 1;
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  boolean bEnableRestrictionObjTrace : 1; /*Enable the restriction of brackets for relevant object trace*/
#endif
#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
  boolean bEnableAddRestrictionStatObjNextLane  : 1; /*Enable the restriction of brackets for stationary objects in next lane*/
#endif
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
  boolean bEnableRestrictionEgoLaneChange : 1; /*Enable the restriction of brackets when Ego makes a lane change*/
#endif
#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
  boolean bEnableRestrictionCityNearRange : 1; /*Enable the restriction of brackets for near range in country road /city scenarios*/
#endif
  boolean bEnableExtensionRoadBorder : 1; /*Enable the extension of brackets for road border*/
  boolean bEnableExtensionCurveInnerBorder : 1; /*Enable the extension of brackets for Curve inner Border*/
  boolean bEnableExtensionRoadBorderCI : 1; /*Enable the extension of brackets for improved road border*/
  boolean bEnableExtensionFollowObjectIntoCurve : 1; /*Enable the extension of brackets for Following an Object in a Curve*/
  boolean bEnableExtensionGuardRailRoadBorder : 1; /*Enable the extension of brackets for Guard-Rail Road Border*/
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  boolean bEnableAddExtensionRelevantObject : 1; /*Enable the extension of brackets for relevant object*/
#endif
#if (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
  boolean bEnableRestrictionNaviObjCloseToExit : 1; /*Enable the restriction of brackets for country roads based on navi info*/
#endif
#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
  boolean bEnableExtensionNaviCountryroad : 1; /*Enable the extension of brackets for country roads based on navi info*/
#endif
#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
  boolean bEnableExtensionCamLaneObjAssoc : 1; /*Enable the extension of brackets for improved camera lane object association */
#endif
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  boolean bExtensionBlockedObstacleCorridor : 1; /*Enable the extension of brackets for blocked path between an object and an obstacle*/
#endif
#if (SIT_CFG_OBJECT_SCORING) //ToBeDiscussed
  boolean bEnableExtensionObjScoring : 1; /*Enable the extension of brackets for new object scoring module*/
#endif
#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
  boolean bEnableExtensionHighspeedApproach : 1; /*Enable the extension of brackets for relevant object which we approach very fast without reliable road estimation*/
#endif
#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
  boolean bEnableAddExtensionHighTunnelProb : 1; /*Enable the extension of brackets for improved robustness against drop-outs in tunnels*/
#endif
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ) 
  boolean bEnableExtensionNeighbourhoodRelObj : 1; /*Enable the extension of brackets for relevant object moves in the direction of a near neighboring object*/
#endif
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD)
  boolean bEnableExtensionLowSpeedFusedBrd : 1; /*Enable the extension of brackets for low ego velocities and missing adjacent lanes*/
#endif
#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
  boolean bEnableExtensionParallelLaneChange : 1; /*Enable the extension of trace brackets for relevant object when there is parallel lane change*/
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */
} LA_t_BracketFuncEnable;

/*! @brief CPObjDist2Traj_tMeas */
typedef LA_t_TrajDistKalmanMeas CPObjDist2Traj_tMeas;

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
#ifdef FCT_SIMU
/*! Structure to store information for debugging of O2O ego lane association */
typedef struct LAO2ODebugInfo {
  boolean b_hintRelObjDistToTraj;
  boolean b_hintRelObjOccluded;
  boolean b_hintRelObjTrace;
  boolean b_hintRelObjBorderDist;
  boolean b_hintRelObjCutOut;
  boolean b_hintO2ODoubleObject;
  boolean b_hintO2OMirror;
  boolean b_hintO2OLaneMatrix;
  boolean b_hintO2OVrel;
  boolean b_hintO2OTraceDistances;
  boolean b_hintO2OPosition;
  ObjNumber_t t_ObjNrEgoLaneByO2O;
}LA_t_O2ODebugInfo;
#endif
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
typedef struct {
   boolean b_TraceEgoLaneObj; /*!< TRUE indicates object is on ego lane based on a trace analysis */
   boolean b_O2OEgoLaneObj;   /*!< TRUE indicates object is on ego lane based on a object-to-object (O2O) relation analysis */
}O2O_t_EgoLaneAssocStatus;
#endif

#if ((LA_CFG_O2O_EGO_LANE_ASSOC) || (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) || (LA_CFG_DTR_OBJ_SELECTION))
typedef struct {
#if (LA_CFG_O2O_EGO_LANE_ASSOC)
  O2O_t_EgoLaneAssocStatus t_O2O_EgoLaneAssocStatus;
#ifdef FCT_SIMU
  LA_t_O2ODebugInfo t_O2ODebugInfo;
#endif
#endif
#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
  uint8 ui_ClusterVarianceLevel;
#ifdef FCT_SIMU
  float32 f_ObjDistToRoadborder;
#endif
#endif
  
#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
  uint8 ui_ClusterVarianceLevelforobstacles;
#endif /*(LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)*/

#if (LA_CFG_DTR_OBJ_SELECTION)
  uint8 uiPedestrianHighCounter; // Better strategy: generate custom LA object list (in this case uiPedestrianHighCounter can be deleted, bust custom-code need to be adapted (Grants information))
#endif
}LA_t_InternalObjectData;

typedef LA_t_InternalObjectData LA_InternalObjectData_t[EM_N_OBJECTS];
#endif

#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
#ifdef FCT_SIMU
typedef struct LACorrNeighbourDebug{
  ObjNumber_t t_ObjPair;
  float32 f_DiffDistX;
  float32 f_DiffVelocity;
  ObjNumber_t t_RefObj;
  float32 f_DistRef2Traj; 
} LA_t_CorrNeighbourDebug;
#endif  /* FCT_SIMU */
#endif  /* LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ */

/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#if ((LA_CFG_O2O_EGO_LANE_ASSOC) || (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) || (LA_CFG_DTR_OBJ_SELECTION))
extern MEMSEC_REF LA_InternalObjectData_t t_LA_InternalObjectData;
#endif

/*! External declaration of component internal pointer to LA Input structure for global access within LA */
extern MEMSEC_REF LAInputConst_t * pt_LAInput;

/*! External declaration of LA output structure whose content is filled in this this component */
extern MEMSEC_REF LAOutput_t * pt_LAOutput;
/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- la_main.c ---*/
extern void LA_v_MeasCallback(void);

/*--- la_acc_function_presel.c ----*/
extern void LA_v_ObjectPreselection(void);
extern void LA_v_InitAccFunPreselection(void);

/*--- la_corridor.c ---------------*/
extern void LA_v_CorridorInit (void);
extern void LA_v_Calculate_ACC_Corridor(LADistanceWidth_t pDistWidth[]);
extern void LA_v_CorridorObjInit(LA_t_ObjCorridor * const pObjCor);
extern LA_t_BracketOutput LA_t_GetBracketPosition(const ObjNumber_t iObj);

/*--- la_corridor_navi.c ---------------*/
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
extern void LA_v_NaviSetMeasData(LA_NaviDebugMeasInfo_t * p_NaviDebugMeasFreeze);
#endif

/*--- la_geometric_lane_assoc.c ---*/
extern void LA_v_ResetInlaneTimer(const ObjNumber_t iObj);
extern void LA_v_ResetInlaneDistance(const ObjNumber_t iObj);
extern void LA_v_GeometricLaneAssoc(const ObjNumber_t iObj);
extern void LA_v_GeometricLaneAssocInLaneCriteria(const ObjNumber_t iObj);
extern void LA_v_GeometricLaneAssocOutLaneCriteria(const ObjNumber_t iObj);
extern void LA_v_GeometricLaneAssocStateFlow(const ObjNumber_t iObj, const boolean b_InLInlapValue);
extern float32 LA_f_GetCorrectedInlap(const LA_t_TrajInlap * p_Inlap);

/*---la_laneassociation-----*/
extern void LA_v_LaneAssociation(void);
extern boolean LA_b_CheckObjInlapPickupValue(const LA_t_TrajInlap * p_Inlap, const float32 f_ObjInlapPickupThresh);
extern float32 LA_f_AdaptObjInlapPickupThresholdForCutIn( ObjNumber_t iObj, float32 f_ObjInlapPickupThresh );
extern boolean LA_b_CheckObjInlapDropValue(const LA_t_TrajInlap* p_Inlap, float32 f_ObjectInlapDropThresh);
extern boolean LA_b_CheckInlaneTimer(const ObjNumber_t iObj, const fTime_t fTimeThres);
extern boolean LA_b_CheckInlaneDistance(const ObjNumber_t iObj);
extern void LA_v_UpdateInlaneTimer(const ObjNumber_t iObj, const fTime_t fTimeThres);
extern fTime_t LA_f_GetInLaneTimeThreshold(const ObjNumber_t iObj);

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
extern fTime_t LA_f_AdaptInLaneTimeThresholdCam(const ObjNumber_t iObj, fTime_t f_InLTimeThreshold);
#endif

extern boolean LA_b_CheckObjLaneQuality(const ObjNumber_t s_Obj);
extern boolean LA_b_CheckObjAdjLaneValidity(const ObjNumber_t s_Obj,  const eAssociatedLane_t e_BaseAssocLane);
extern boolean LA_b_CheckObjOncRollBack(const ObjNumber_t s_Obj,  const eAssociatedLane_t e_BaseAssocLane);
#if (LA_CFG_AVOID_SPILT_OBJ)
extern void LA_v_FindObjInArea(ObjNumber_t p_ObjInArea[], const ObjNumber_t t_ObjA, LA_t_FindObjInAreaArgs const* const AreaArgs, boolean b_NoQualityCheck);
#else
extern void LA_v_FindObjInArea(ObjNumber_t p_ObjInArea[], const ObjNumber_t t_ObjA, LA_t_FindObjInAreaArgs const* const AreaArgs);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
extern boolean LA_b_CheckObjDistToCCCriteria(const ObjNumber_t t_Obj);
#endif
#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
extern boolean LA_b_CheckNarrowHighwayCriteria(const ObjNumber_t t_Obj);
#endif

/*--- la_corridor_scene.c ----*/
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
extern void LA_v_InitCorridorScene(void);
#endif
extern void LA_v_PerformO2OLaneAssociation(void);
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
extern void LA_t_FindNearNeighboringObjToEgoLane(const ObjNumber_t t_ObjNrRel);
#endif

/*--- la_traj2objrelation ---*/
extern void LA_v_InitObjDist2Traj(const CPObjDist2Traj_tMeas * pObjDist2TrajMeas , LAObjDist2Traj_t *pObjDist2TrajDist);
extern void LA_v_CalculateDistance2Traj(const float32 fX, const float32 fY, const boolean bUseEgoCourseOnly, const CP_t_GDBTrajectoryData * pTrajData, CAL_t_TrajRefPoint * pDist2Traj);
extern void LA_v_CalculateInlap(ObjNumber_t iObj, const LADistanceWidth_t *p_DistanceWidth,const float32 f_LeftBracketPos, const float32 f_RightBracketPos, LA_t_TrajInlap *p_Inlap);

/*--- la_kalman.c ---*/
extern void LA_v_KalmanInit(const LA_t_TrajDistKalmanMeas * pMeasurement , LA_t_TrajDistKalmanData *pTrajDist );
extern void LA_v_KalmanFiltering(ObjNumber_t iObj ,const LA_t_TrajDistKalmanMeas * pMeasurement, const GDBSymMatrix2_t * pQ ,float32 fCycleTime , LA_t_TrajDistKalmanData *pTrajDist);

/*--- la_pred_lane_assoc.c ---*/
extern void LA_v_PredLaneAssoc(const ObjNumber_t iObj);

/*--- la_customfunctions.c ---*/
extern void LA_v_InitCustom(void);
extern void LA_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete );
#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
extern boolean LA_b_CustProcessCriteriaMatrix(ObjNumber_t iObj, LA_t_CriteriaMatrix * pCriteriaMatrix);
#endif
extern boolean LA_b_CustMergePreselection(ObjNumber_t ObjNr, ACCObjectQuality_t uiAccQual, boolean bFunPresel);

extern boolean LA_b_CheckCustomInlaneCriteria(ObjNumber_t iObjNr);
extern boolean LA_b_CheckCustomOutlaneCriteria(ObjNumber_t iObjNr);

#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
extern  void LA_v_Camera_CutIn_CutOut_Potential(void);
#endif /* END IF (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL) */

#if (LA_CFG_CUSTOM_CORRIDOR_PREPROCESSING)
extern void LA_v_CustomCorridorPreProcessing(ObjNumber_t iObj, LA_t_BracketFuncEnable* pBracketFuncEnable);
#endif

#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
extern void LA_v_DetectTrajDynamism(void);
extern fTime_t LA_v_AdaptObjInLaneTimeThresholdTrajDynamism(const ObjNumber_t iObj, fTime_t fTimeThreshInLane);
extern float32 LA_v_AdaptObjInlapDropThresholdTrajDynamism(const ObjNumber_t iObj, float32 f_DropThresholdObj);
#endif /*(LA_CFG_TRAJ_DYNAMISM_DETECTION)*/

#if (LA_CFG_ADAPT_INLANE_FAR_TRUCK)
extern fTime_t LA_v_AdaptObjInLaneTimeThresholdFarTrucks(const ObjNumber_t iObj, fTime_t fTimeThreshInLane);
#endif /*(LA_CFG_ADAPT_INLANE_FAR_TRUCK)*/

#if (LA_CFG_TURN_INDICATOR_COUNTER)
extern void LA_v__FilterTurnIndicator(eTurnIndicator_t t_TurnIndicator);
#endif

#if (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
extern void LA_v_UpdateClusterVarianceLevelforObstacles(void);
#endif /*  (LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)*/

extern boolean LA_b_CheckEgoLaneAssocValidity(const ObjNumber_t iObjNr);

#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)
extern fTime_t LA_f_GetInLaneTimeCurveStatThreshold(const ObjNumber_t iObj, fTime_t fTimeThreshInLane);
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */

#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
extern uint8 LA_u_GetObjOutlaneCounterThreshold(const ObjNumber_t iObj, uint8 u_In2OutlaneCounterThreshold);
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */

#if (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
extern LA_t_ObjCamTrajLanAssocEnum LA_u_GetObjAssocLaneBasedOnCameraTrajectory(const ObjNumber_t iObj);
#endif /*(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */

/*--- la_camera_lane_assoc.c ---*/
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
extern boolean LA_b_CheckCameraObjAssoToEgoLane(const ObjNumber_t iObj);
extern boolean LA_b_CheckCameraObjAssoToOutLane(const ObjNumber_t iObj);
#endif

#ifdef __cplusplus
};
#endif
///@}
#endif /*!< FCT_CFG_ACC_LANE_ASSOCIATION */

/* End of conditional inclusion */
#endif  /*!< _LA_H_INCLUDED */
