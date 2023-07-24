/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_ext.h

DESCRIPTION:               Extern header file for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.44 $

LEGACY VERSION:            Revision: 2.4.1.4

**************************************************************************** */
#ifndef LA_EXT_INCLUDED
#define LA_EXT_INCLUDED

#include "la_cfg.h"
#include "slate_ext.h"


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la_ver.h"


#if (FCT_CFG_ACC_LANE_ASSOCIATION)
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
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/
/*! Macro to check if Object Quality is sufficient for functional use, 
  Macro and direct variable access both used in the code -> RESTRUCTURE */
#define LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObject)     (t_LA_Output.LABasePreselObjList[iObject])

#define OBJ_GET_CP(iObj)          t_LA_Output.t_LAObjOutputList[iObj].TrajDist //Used in EBA

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! Data type used for storing range reduction histogram information. Note:
this type is used in simulation for initialization purposes! When changing,
also update the adapter for handling the new layout! */
typedef struct
{
  float32 RangeFactor;
} LA_t_CurveObserv_RangeRed;

/*Lane association information*/
typedef struct LA_laneAssociationInfo{
  eAssociatedLane_t eObjAssocLane; /*!< Lane associated with object (on external interface) */
  eAssociatedLane_t e_ObjFuncLane; /*!< Functional Lane associated with object for object selection (on external interface) */
}LA_t_laneAssociationInfo;

/*LA data to be frozen which is a part of FCT Public Object List*/
typedef struct LA_PublicObjectData{
  LA_t_laneAssociationInfo t_LA_laneAssocInfo; /*Lane association info to be frozen*/
  float32 ObjToRefDist;
}LA_PublicObjectData_t;

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
/*! Structure for navi SI meas freeze */
typedef struct LA_NaviDebugMeasInfo{
  boolean b_NaviCountryExternalSwitch;
}LA_NaviDebugMeasInfo_t;
#endif

typedef LA_PublicObjectData_t LA_a_PublicObjList[EM_N_OBJECTS];
/*LA device Meas Info*/
typedef struct LA_DeviceMeasInfo{
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
  LA_NaviDebugMeasInfo_t t_NaviMeasInfo; /* Navi meas data */
#endif
  float32 f_LaneWidth;  /* Seek lane width output */
  LA_t_CurveObserv_RangeRed t_LA_CurveObs; /* Curve observer information*/
  LA_a_PublicObjList t_LA_PubObj; /*LA Public Object list*/
#if (SLATE_CFG_USE_DRIVE_MODE)
  DriveMode_t_e t_edrivemode;    /* Drivemode info */
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */
}LA_DeviceMeasInfo_t;

/*! Predicted distance structure with variances */
typedef struct LAPredictedDistanceTag {
  float32 pdist;              /*!< The predicted distance */
  float32 pdist_var;          /*!< The predicted distance variance */
  float32 pdist_var_fullpred; /*!< A variance corrected predicted distance */
} LA_t_PredictedDistance; /* Remark: Used in SIT, better move cut-in/cut-out analysis in si_pred_lane_assoc.c to SIT */


typedef boolean LA_t_BasePreselObjList; /*!< Type storing pre-selection decision for one object */


typedef LAObjOutput_t LAObjOutputList_t[EM_N_OBJECTS];

/*! Typedef of output of LA */
typedef struct LAOutput{
  LAObjOutputList_t t_LAObjOutputList;
  LA_t_BasePreselObjList LABasePreselObjList[EM_N_OBJECTS];
  float32 f_LA_SeekLaneWidth;   /*Seek lane width output*/
  float32 f_LA_TrackLaneWidth;  /*Track lane width output*/
  fDistance_t f_LAMovingObjPickUpRange; /* The pick up range for moving objects (with range factor correction) */
  fDistance_t f_LAMovingObjBasePickUpRange; /* The base pick up range for moving objects (without range factor correction) */
  fDistance_t f_LAMovingObjRangeLimitMin; /* The ego velocity dependent range limitation minimum for moving objects */
  fDistance_t f_LAMovingObjRangeLimitMax; /* The ego velocity dependent range limitation maximum for moving objects */
  float32 fRangeFac; /*! Range reduction factor @min:0 @max:1 */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
    LA_t_ScaleBracketState f_LA_StateScaleBracket;     /*state of trace bracket adaption*/
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  ObjNumber_t t_NearNeighboringObj[EM_N_OBJECTS];  /*Near neighboring object which is not the same side of ACC trajectory*/
#endif/*(LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)*/
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  ObjNumber_t s_BlockedNearObj;    /*!< The longitudinal closer object that is part of the blocking object-obstacle pair */
  ObjNumber_t s_BlockedFartherObj; /*!< The longitudinal further away object that is part of the blocking object-obstacle pair */
  float32 f_BlockedPathWidth;
  SIT_t_PathOccupation a_PathOccObj2Obstacle[SIT_PATH_OCC_ENTRIES]; /*!< Occupancy list for the objects and obstacles */
#endif /* END IF (LA_CFG_BLOCKED_OBSTACLE_EXTENSION) */
#if (LA_CFG_ENABLE_PARKED_DETECTION)
  boolean b_RoadSideParkedObj[EM_N_OBJECTS];        /*!< Flag to indicate parked Object detections. */
#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */
#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
  float32 f_CurrCycleDist2Traj;  /* Distance to trajectory value of an Object in current cycle */
  float32 f_PrevCycleDist2Traj;  /* Distance to trajectory value of an Object in previous cycle */
  float32 f_DifferenceDist2Traj; /* Difference between the Distance to trajecory value of an object in the current and previous cycle */
  boolean b_TrajDynDetected;     /* Boolean which indicates that the Trajectory Dynamism is detected or not */
  uint8 u_iDynamismCount;        /* Counter which holds the value of how many times the Trajectory Dynamism is detected */
#endif /* end of LA_CFG_TRAJ_DYNAMISM_DETECTION */
#if (LA_CFG_TURN_INDICATOR_COUNTER)
  float32 f_TurnIndLeftTime;     /* Timer for left ego turn indicator */
  float32 f_TurnIndRightTime;    /* Timer for right ego turn indicator */
#if (LA_CFG_USE_TURNIND_LASTSTATUS)
  eTurnIndicator_t TurnIndLastState;
#endif /* LA_CFG_USE_TURNIND_LASTSTATUS */
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER)
  float32 f_EgoLCRestrictTimer;  /* Timer for restriction ego lane change */
  ObjNumber_t iLastRelObjNr;     /* Last OOI0 which is released during ego lane change */
#endif /* LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER */
#endif /* end of LA_CFG_TURN_INDICATOR_COUNTER */
#if (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
  boolean b_EgoObjTracCutOut[EM_N_OBJECTS];        /*!< Flag to indicate Object Trae Cuts out. */
#endif /* end of LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD */
  #if (LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE)
    #if ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS))
     FIP_t_LaneWidthClass s_LaneWidthClass;
    #endif /* END IF ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS)) */
  #endif /* END IF LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE */
} LAOutput_t;

#ifdef FCT_SIMU
typedef struct LA_SimMeasInfo{
  LAOutput_t t_LA_FreezeOutput;
}LA_SimMeasInfo_t;
#endif

/*! Typedef of constant input to LA component from SIT */
#if (FCT_CFG_ACC_SITUATION)
typedef struct LAInputSITConst{
  SIT_OutputBool_t const * (*pt_ObjBool)(const ObjNumber_t); /*!< Reference to bit field for each object */
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
  const uint8 * (*pu_BlockedPathSelectionTimer)(const ObjNumber_t); /* Object blocked path Timer */
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  const SITLaneChangeCamPreMove_t * pt_SITLaneChangeCamPreMoveState;
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/
  const SIT_LC_t_LaneChangePhaseInfo * pt_GetLaneChangeInfo;  /* Ego Lane change information */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  const float32 * (*pf_CrossingDistTrace)(const ObjNumber_t);
#endif
#if (SIT_CFG_OBJECT_SCORING)
  const eAssociatedLane_t * (*pt_ScoringAssocLane)(ObjNumber_t);
#endif /* END IF SIT_CFG_OBJECT_SCORING */
}LAInputSITConst_t;
#endif /* END IF FCT_CFG_ACC_SITUATION */ 

/*! Typedef of constant input to LA component from FIP Object Traces */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) 
typedef struct LAInputFIPMOTConst{
  const TraceID_t * (*pu_FIPStaticTraceID)(const ObjNumber_t);
} LAInputFIPMOTConst_t;
#endif


#if (FCT_CFG_ACC_OOI)
/*! Typedef of constant input to LA component from OOI */
typedef struct LAInputOOIConst{
  const OOI_RelObject_t *pt_OOIRelObj; /* Relevant Object (OOI-0) Information */
  const ObjNumber_t * (*pu_OOIListObjId)(uint8);
}LAInputOOIConst_t;
#endif  /* (FCT_CFG_ACC_OOI) */


typedef struct LAInputRTEConst{
  const float32 * (*pf_ObjLongDisp)(ObjNumber_t); /* Longitudinal displacement of object */
  const float32 * (*pf_ObjLatDisp)(ObjNumber_t);  /* Lateral displacement of object */
  const float32 * (*pf_ObjVrelX)(ObjNumber_t);    /* Object relative longitudinal velocity */
  const float32 * (*pf_ObjVrelY)(ObjNumber_t);    /* Object relative lateral velocity */
  const float32 * (*pf_ObjArelX)(ObjNumber_t);    /* Object relative longitudinal acceleration */
  float32 (*pf_ObjOrientation)(ObjNumber_t); /* Object orientation */
  float32 (*pf_ObjOrientationStd)(ObjNumber_t); /* Object Orientation Std */
  const SLATE_t_Obj_DynamicProperty * (*pt_ObjDynamicProperty)(ObjNumber_t);
  const SLATE_t_Obj_CLassification * (*pt_ObjClassification)(ObjNumber_t);
  const float32 * pf_EgoVelObjSync; /* Ego velocity sync */
  const float32 * pf_EgoAccObjSync; /* Ego acceleration sync */
  const float32 * pf_EgoCurve;      /* Curvature of the ego path */
  const float32 * pf_EgoCurveRaw;    /* Raw ego curvature */
  float32 f_EgoYawRateQuality; /* Quality of ego yaw rate signal */
  boolean (*pb_ObjIsShadow)(ObjNumber_t); /* Boolean indicating if object is shadow */
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const float32 * pf_TunnelProbability; /* Probability of Tunnel */
#endif

#if (FCT_CFG_EMERGENCY_BRAKE_ASSIST)
  const EM_t_GenEbaObjClass * (*pt_EbaObjClass)(ObjNumber_t);
#endif

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  const EM_t_ARS_SensorSpecific * (*p_ARSSensorSpecific)(ObjNumber_t);
#endif
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  const EM_t_Cust_ObjectData * (*p_EMCustObj)(ObjNumber_t);
#endif
#if (SLATE_CFG_USE_DRIVE_MODE)
  const DriveMode_t_e * pt_edrivemode;    /* Drivemode info */
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  const t_CamLaneInputData * pt_CamLaneData; /* Input Camera Lane Data */
#endif
#if ((SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) && (LA_CFG_EGO_TURNIND_BASED_PICKUP))
  const eTurnIndicator_t *pt_TurnIndicator;
#endif /* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT && LA_CFG_EGO_TURNIND_BASED_PICKUP*/
}LAInputRTEConst_t; 

typedef struct LAInputCPConst{
  const CP_t_TrajectoryData*  pt_TrajectoryData; /*Data related to CP trajectory*/
  /*Only 2 members of CP_t_CourseData structure is being used in LA. So only those members are being shifted to this structure
  If in future more members will be used, Shift the whole structure into this*/
  const fCurve_t* pf_CourseCurve; /*!< fCurve */
  const fGradient_t* pf_CourseCurveGradient;/*!< fCurveGradient */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  const CAL_t_TracePolyL2 * (*pt_TracePoly)(TraceID_t);
#endif
}LAInputCPConst_t;

/*! Typedef of inputs to LA component from Frame */
typedef struct LAInputFrame{
#ifdef FCT_SIMU
  LA_SimMeasInfo_t * pt_LA_SimMeasInfo; /*!< Sim Freeze of SIT from Frame */
  const MEASInfo_t * pt_LA_SimMeasInfoFreeze;
#endif
  LA_DeviceMeasInfo_t * pt_LA_DeviceInfo;
  const MEASInfo_t   * pt_LA_DeviceInfoFreeze;
}LAInputFrame_t;

typedef struct LAInputConst{
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  const FIP_CC_Output_t *pt_FIPCC;
#endif
  LAInputFrame_t t_FrameFreeze;
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const FIP_LM_Output_t *pt_FIPLaneMatrix;  /*!< Input of FIP lane matrix */
#endif /* END IF FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  const FIP_ND_Output_t *pt_FIPNaviData;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_OA_Output_t *pt_FIPOA; /*! < Input of FIP Object attributes */
  const FIP_RT_Output_t *pt_FIPRoadType; /*!< Input of FIP RoadType */
  const FIP_RD_Output_t *pt_FIPRoad; /*!< Input of FIP Road */
 
  const FIP_TO_Output_t *pt_FIPTO; /*!< Input of FIP Traffic Orientation */
#endif
  LAInputCPConst_t t_CP;
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  const FIP_CL_Output_t *pt_FIPCamLane;
#endif
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
  LAInputFIPMOTConst_t t_FIPMOTTraceId;
  const FIP_MOT_Output_t *pt_FIPMOT;
#endif
#if (FCT_CFG_ACC_OOI)  
  LAInputOOIConst_t t_OOI;
#endif  /* (FCT_CFG_ACC_OOI) */
#if (FCT_CFG_ACC_SITUATION)
  LAInputSITConst_t t_SIT;
#endif /* END IF FCT_CFG_ACC_SITUATION */
  LAInputRTEConst_t t_RTE;
}LAInputConst_t;


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

extern MEMSEC_REF SLATECompState_t LA_t_State;

/* Declaration of extern pointer to LA output structure for usage in other components */
extern MEMSEC_REF LAOutput_t t_LA_Output;


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- la_main.c ---*/
extern void LA_v_PreProcess(LAInputConst_t * pt_LA_InputGlobal, LAOutput_t * pt_LA_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);
extern void LA_v_Process(LAInputConst_t * pt_LA_InputGlobal, LAOutput_t * pt_LA_OutputGlobal);
extern void LA_v_DeleteObject(ObjNumber_t ObjId);
extern void LA_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete);
extern void LA_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr);
extern void LA_v_SetOperationMode(SLATECompState_t const t_LAOpModeValue);

/*--- la_corridor_cam.c ---*/

/*--- la_corridor_navi.c ---*/

/*--- la_predictions.c ---*/
extern fTime_t LA_t_LimitPredictionTimeDist(fVelocity_t vehicle_speed, float32 ObjDisp);
/* Remark: Output to SIT, better move cut-in/cut-out analysis in si_pred_lane_assoc.c to SIT */
extern void LA_v_CalcPredDisplToCutOut(fTime_t prediction_time, SLATE_t_Obj_CLassification object_class, 
  ObjNumber_t obj_id, LA_t_PredictedDistance* pred_dist); /* Remark: Output to SIT, better move cut-in/cut-out analysis in si_pred_lane_assoc.c to SIT */

/*--- la_traj2objrelation ---*/
#if (FCT_CFG_COURSE_PREDICTION)
extern void CPUpdateObjDist2Traj(const ObjNumber_t iObj , const float32 fMaxAccelDist2Traj, CP_t_TrajectoryData const *pTrajData , LAObjDist2Traj_t *pObjDist2TrajDist); /* USED in EBA???*/
#endif /* FCT_CFG_COURSE_PREDICTION */
//extern void CPDeleteObjDist2Traj(LAObjDist2Traj_t *pObjDist2TrajDist); /* USED in EBA???*/
/*--- la_laneassociation_stateflow.c ---*/

#ifdef __cplusplus
};
#endif
///@}
#endif /*!< FCT_CFG_ACC_LANE_ASSOCIATION */

/* End of conditional inclusion */

#endif  /*!< _LA_EXT_INCLUDED */


