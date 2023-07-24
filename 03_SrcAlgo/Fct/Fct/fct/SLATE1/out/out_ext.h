/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_ext.h

DESCRIPTION:               Extern header file for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.34 $

LEGACY VERSION:            Revision: 2.4.1.1

**************************************************************************** */
#ifndef OUT_EXT_INCLUDED
#define OUT_EXT_INCLUDED



/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "out_cfg.h"
#include "slate_ext.h"
#include "out_ver.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup out
@{ */
#if (SLATE_CFG_USE_EXT_OBJ_ID)
#include "slate_calc_ext_obj_id.h"
#endif

#if (FCT_CFG_ACC_OUTPUT)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

#if (OUT_CFG_CUSTOM_OOI_MEAS_DATA)
/*! The structure describing the custom measurement output per OOI object */
typedef struct OUT_CustMeasOOI
{
  fVelocity_t fAbsSpeedX; /*!< Absolute object speed in X direction */
  fAccel_t    fAbsAccelX; /*!< Absolute object acceleration in X direction */
#if OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING
  t_DrivingTubeMapping DrivingTubeMapping;  /*!< Driving tube mapping of the object */
#endif
#if OUT_CFG_CUSTOM_XY_RELEVANCE
  uint8       RelevanceX; /*!< X relevance of the object @min:0.0 @max:100.0 */
  uint8       RelevanceY; /*!< Y relevance of the object @min:0.0 @max:100.0 */
#endif
#if (OUT_CFG_OOI_TTC_TG_DEBUG_CRITERIA)
  float32     fTTC;       /*!< TTC time for given OOI object for evaluation of performance @unit:s */
  float32     fTimeGap;   /*!< Timegap time for given OOI object for evaluation of performance @unit:s */
#endif
} OUT_t_CustMeasOOI;
#endif

/*! Type output over measurement interface for one relevant object */
typedef struct {
  ObjNumber_t           object_id;        /*!< The object-ID of the object, or OBJ_INDEX_NO_OBJECT if none */
  eAssociatedLane_t     lane;             /*!< The lane assigned to the object */
  SLATE_t_Obj_CLassification     object_class;     /*!< The object class */
  SLATE_t_Obj_DynamicProperty    object_type;      /*!< The object type */
#if (FCT_CFG_SENSOR_TYPE_RADAR)
  SLATE_t_Obj_DynamicSubProperty object_sub_prop;  /*!< The objects dynamic sub-property */
#endif  /* END IF (FCT_CFG_SENSOR_TYPE_RADAR) */

  uint8                 potential;        /*!< The cut-in potential for outlane objects, the cut-out potential for inlane ones */
  boolean               seen_moving;      /*!< Flag indicating if object is stopped (stationary now, but seen moving) */
#if (SLATE_CFG_USE_EXT_OBJ_ID)
  FCTSenExtObjId_t      ext_id;           /*!< The extenal object ID assigned */
#endif
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  ObjNumber_t           cam_obj_id;       /*!< Camera object ID */
  percentage_t          cam_conf;         /*!< Camera confirmation probability */
  eAssociatedLane_t     cam_assoc_lane;   /*!< Camera associated lane */
  percentage_t          cam_assoc_lane_qual;  /*!< Camera associated lane quality */
# if (FCT_CFG_ME_INPUT_FOR_DEBUG)
  fDistance_t           cam_long_dist;    /*!< Camera long distance @unit: m */
  fDistance_t           cam_lat_dist;     /*!< Camera lateral distance @unit: m */
# endif
#endif

  float32 pred_lat_displ;                   /*!< Predicted lateral displacement from ego course */
  float32 long_displacement;                /*!< Distance of object in X direction */
  float32 lat_displacement;                 /*!< Distance of object in Y direction @name: lat_displacement_to_curvature @todo: remove misleading name alias! */
  float32 rel_long_velocity;                /*!< Object's relative speed in X direction (longitudinal) */
  float32 rel_long_acceleration;            /*!< Object's relative acceleration in X direction */
  float32 rel_lat_velocity;                 /*!< Object's relative speed in Y direction (lateral) */
  float32 fTraceBracketLeft;                /*!< The left trace bracket offset to course estimation @unit: m @name: lat_displ_road_bord_l @todo: Modify birdeye for new name, then remove renaming! */
  float32 fTraceBracketRight;               /*!< The right trace bracket offset to course estimation @unit: m @name: lat_displ_road_bord_r @todo: Modify birdeye for new name, then remove renaming! */

#if (OUT_CFG_CUSTOM_OOI_MEAS_DATA)
  OUT_t_CustMeasOOI       custom;           /*!< Custom meas data for OOI objects */
#endif
} OUT_t_Meas;

typedef OUT_t_Meas OUT_MeasObjs_t[OOI_NUMBER_OF_OOI];

/*typedef for device freeze for output component*/
typedef struct OUT_DeviceMeasInfo{
#if (FCT_MEASUREMENT)
 OUT_MeasObjs_t t_OOIList;
#endif
 OUT_t_CustomOutputDebugInfo t_OUT_CustomOutputDebugData;
}OUT_DeviceMeasInfo_t;

/*! Typedef of constant input to OUT component from CP */
typedef struct OUTInputCPConst{
  const CP_t_TrajectoryState*  pt_TrajectoryState;		 /*!<Trajectory  State */
  const CP_t_GDBTrajectoryData* pt_TrajectoryCurrent;    /*!< Trajectory data from the current cycle */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  const CP_t_TraceTrajectory * pt_TraceTrajectory;
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  const CPTraceLaneChangeInfo_t * (*pt_ObjLaneChangeInfo)(const TraceID_t); /*!< Lane Change Info for Objects */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
}OUTInputCPConst_t;

/*! Typedef of output of OUT*/
typedef struct OUTOutput{
#if(OUT_CFG_CUSTOM_COLUMN_OBJECT)
  float32 f_LeftMeanVelocity;
  float32 f_LeftMaxVelocity;
  float32 f_RightMeanVelocity;
  float32 f_RightMaxVelocity;
  ObjNumber_t t_RightMaxValobjId;
  ObjNumber_t t_LeftMaxValobjId;
#else
  boolean b_Dummy;
#endif  /*END IF OUT_CFG_CUSTOM_COLUMN_OBJECT*/
#if (OUT_CFG_FUNC_LANEASSOC_LA)
  boolean b_flag_LaneAss_LC; /* Flag to indicate functional LA of 40 objects are saved when pre lane change*/
  eAssociatedLane_t t_FuncLA_LC[EM_N_OBJECTS]; /* Functional lane association of 40 EM objects when pre lane change */
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */
}OUTOutput_t;

#ifdef FCT_SIMU
typedef struct OUT_SimMeasInfo{
  OUTOutput_t t_OUT_FreezeOutput; 
}OUT_SimMeasInfo_t;
#endif

#if (FCT_CFG_ACC_SITUATION)
typedef struct OUTInputSITConst{
  const SITObjOutput_t * (*pt_SITObjectList)(ObjNumber_t);
  boolean b_Dummy;
#if ((FCT_CFG_CUSTOM_PASSING_STATE) || (FCT_CFG_LOHP_COMPONENT))
  const SIT_LC_t_LaneChangePhaseInfo * pt_LaneChangePhaseInfo; /*!< Information for each lane change phase */
#endif /* ENDIF FCT_CFG_CUSTOM_PASSING_STATE */
#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

  const boolean * pb_FrontObstSigVal;
#endif /* END IF(SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
}OUTInputSITConst_t;
#endif /*END IF FCT_CFG_ACC_SITUATION */

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
typedef struct OUTInputLAConst{
  float32 * pf_SeekLaneWidth;  /*Variable for seek lane width*/
  const float32 * (*pf_ObjToRefDistMeas)(ObjNumber_t);
  const float32 * (*pf_ObjToRefDistFiltVar)(ObjNumber_t);
  const float32 * (*pf_ObjDistOnTraj)(ObjNumber_t);
  const fDistance_t *pt_MovingObjPickUpRange;
  const float32 *pf_Rangefac;
  const LAObjOutput_t  * (*pt_LAObjectList)(ObjNumber_t);
}OUTInputLAConst_t;
#endif

#if (FCT_CFG_ACC_OOI)
typedef struct OUT_OOI_Input{
  eRelObjLossReason_t * (*pt_OOIObjLossReason)(ObjNumber_t); /*Object loss reason for OOI Objects*/
  const float32 * (*pf_PredictedLatDispl)(ObjNumber_t);
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  const ObjNumber_t * (*pu_OOIListObjId) (uint8);  /* Get Object Number from OOI */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
}OUT_OOI_Input_t;
#endif  /* (FCT_CFG_ACC_OOI) */

/*! Typedef of constant input to SIT component from Frame */
typedef struct OUTInputFrame{
#ifdef FCT_SIMU
  OUT_SimMeasInfo_t * pt_OUT_SimMeasInfo; /*!< Sim Freeze of OUT from Frame */
  const MEASInfo_t * pt_OUT_SimMeasInfoFreeze;
#endif
  OUT_DeviceMeasInfo_t * pt_OUT_DeviceMeasInfo; /*!< Device Freeze of OUT from Frame */
  const MEASInfo_t * pt_OUT_DeviceMeasInfoFreeze;
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  const MEASInfo_t * pt_OUT_PubObjListMeasInfoFreeze;   /* Reference to memory where FCT Public Object List will be freezed */
#endif
  boolean dummy;
}OUTInputFrame_t;

#if (FCT_CFG_INPUT_PREPROCESSSING)
typedef struct OutInputFIP{
#if (SLATE_CFG_PARALLEL_LANE_CHANGE) 
  const TraceID_t * (*pt_ObjTraceID)(const ObjNumber_t);  /*!< Trace ID of object */
#else  
  uint8 dummy;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */    
}OutInputFIPConst_t;
#endif

/*! Typedef of constant input to OUT component from RTE Input Ports */
typedef struct OUTInputRTEConst{
  const float32 * (*pf_ObjVrelX)(ObjNumber_t); /* Relative longitudinal velocity of object */
  const float32 * (*pf_ObjVrelY)(ObjNumber_t); /* Relative lateral velocity of object */
  const float32 * (*pf_ObjArelX)(ObjNumber_t); /* Relative longitudinal acceleration of object */
  const float32 * (*pf_ObjArelY)(ObjNumber_t); /* Relative lateral acceleration of object */
  const float32 * (*pf_ObjLongDisp)(ObjNumber_t); /* Longitudinal displacement of object */
  const float32 * (*pf_ObjLatDisp)(ObjNumber_t); /* Lateral displacement of object */
  const float32 * (*pf_ObjVabsY)(ObjNumber_t); /* Absolute lateral velocity of object */
  const float32 * (*pf_ObjAabsY)(ObjNumber_t); /* Absolute lateral acceleration of object */
  const SLATE_t_Obj_DynamicProperty * (*pt_ObjDynProperty)(ObjNumber_t); /* Dynamic property of object */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  const SLATE_t_Obj_DynamicSubProperty * (*pt_ObjDynSubProperty)(ObjNumber_t); /* Dynamic sub property of object */
#endif
  const SLATE_t_Obj_CLassification * (*pt_ObjClassification)(ObjNumber_t); /* Classification of object */

  const float32 * (*pf_ObjLifeTime)(ObjNumber_t); /* Life time of object */
  const AlgoCycleCounter_t * (*pt_ObjLifeCycles)(ObjNumber_t); /* Life cycles of object */
#if (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY)
  const percentage_t * (*pt_ObjObstacleProbability)(ObjNumber_t); /* Obstacle probability of object */
#endif /* (OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY) */
  const EM_t_GenObjMaintenanceState * (*pt_ObjMaintenanceState)(ObjNumber_t); /* Maintenance state of object */

#if (SLATE_CFG_USE_EXT_OBJ_ID)
  const uint8 * (*pu_ObjExtID)(ObjNumber_t); /* External Object ID */
#endif /* ENDIF SLATE_CFG_USE_EXT_OBJ_ID */

#if (OUT_CFG_FUNC_LANEASSOC_LA)
  const eTurnIndicator_t * pt_TurnIndicator; /* Ego Turn indicator information */
#endif /*OUT_CFG_FUNC_LANEASSOC_LA*/

  const float32 * pf_EgoVelObjSync; /* Ego Velocity sync */
}OUTInputRTEConst_t;

/*! Typedef of constant input to OUT component*/
typedef struct OUTInputConst{
  OUTInputFrame_t t_FrameFreeze;
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  OUTInputLAConst_t t_LAInput;
#endif
#if (FCT_CFG_ACC_SITUATION)
  OUTInputSITConst_t t_SIT;
#endif /*END IF FCT_CFG_ACC_SITUATION */
#if (FCT_CFG_ACC_OOI)
  OUT_OOI_Input_t t_OUT_OOI_Input;
#endif  /* (FCT_CFG_ACC_OOI) */
  boolean b_Dummy;
  OUTInputCPConst_t t_CP;
#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_RT_Output_t *pt_FIPRoadType;
  const FIP_OA_Output_t *pt_FIPOA;
#if(OUT_CFG_CUSTOM_HMI_OBJECTS)
  const FIP_RD_Output_t *pt_FIPRD;
#endif
  OutInputFIPConst_t t_FIPTraceId;  
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const FIP_LM_Output_t *pt_FIPLaneMatrix;  /*!< Input of FIP lane matrix */
#endif /* END IF FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */  
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  const FIP_ND_Output_t *pt_FIPND;
#endif
#if (OUT_CFG_OVERTAKE_PREVENTION_FEATURE)
  const FIP_TO_Output_t *pt_FIPTO; /*!< Input of FIP Traffic Orientation */
#endif
#endif
  OUTInputRTEConst_t t_RTE;
}OUTInputConst_t;

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

extern MEMSEC_REF SLATECompState_t OUT_t_State;

#ifdef FASTSIM
extern OUT_DeviceMeasInfo_t OUT_DeviceMeasInfo;
#endif

/*! External declaration of const extern pointer to OUT output structure for usage in other components*/
extern MEMSEC_REF OUTOutput_t t_OUTOutput;

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- out_main.c ---*/
extern void OUT_v_PreProcess(OUTInputConst_t * pt_OUT_InputGlobal, OUTOutput_t * pt_OUT_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);
extern void OUT_v_Process(OUTInputConst_t * pt_OUT_InputGlobal, OUTOutput_t * pt_OUT_OutputGlobal);
extern void OUT_v_DeleteObject(ObjNumber_t ObjId);
extern void OUT_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete);
extern void OUT_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr);
extern void OUT_v_SetOperationMode(SLATECompState_t const t_OUTOpModeValue);

/*--- out_ouput.c ---*/  
extern void OUT_v_SeReObPutRelTrckObjNumber( ObjNumber_t RelTrckObjNr ); 
/* Temporary change of prefix to ensure compatibility in EBA */
extern ObjNumber_t SISeReObGetRelTrckObjNumber(void); 

/*--- out_customfunctions.c ---*/
#if (LA_CFG_DTR_OBJ_SELECTION)
extern void OUT_v_SetDTRLaneDegradation(float32 f_DegrDistPerf_MaxDist); 
#endif
#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
extern void OUT_v_CustStoreBracketExtensions(ObjNumber_t iObj, const LA_t_CriteriaMatrix * pCriteriaMatrix);
#endif


#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_ACC_LANE_OUTPUT */

/* End of conditional inclusion */

#endif  /*!< _OUT_EXT_INCLUDED */


