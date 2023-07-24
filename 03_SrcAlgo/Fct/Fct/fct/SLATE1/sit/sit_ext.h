/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)
  
CPU:                       CPU-Independent
  
COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_ext.h

DESCRIPTION:               Extern header file for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.44 $

LEGACY VERSION:            Revision: 2.3.1.1

**************************************************************************** */
#ifndef SIT_EXT_INCLUDED
#define SIT_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit_ver.h"
#include "sit_custom_ext.h"
#include "sit_cfg.h"
#include "slate_ext.h"

#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit
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



#define SIT_PREDICTED_LATERAL_DISPLACEMENT (999.f) 

/*! Counter for the approximated yaw rate curve during lane change */
#define SIT_LC_LCS_YAW_COUNTER_MAX (20u)
/*! Max number of samples for the DMMR yaw calculation */
#define SIT_LC_CUMSUM_DIST_MAX_SAMPLES (10u)
/*! Max number of samples for the cumulative sum distance calculation */
#define SIT_LC_DMMR_YAW_MAX_SAMPLES (5u)
#if (SIT_O2O_ANALYSIS)
/*! O2O Number of near objects for an object under investigation */
#define SIT_O2O_NEAR_OBJECTS                (3u)
#endif

#if (SIT_CFG_OBJECT_SCORING)
#define SIT_OBJSCORE_LANE_LEFT              (0u)  /* Left lane array Index */
#define SIT_OBJSCORE_LANE_EGO               (1u)  /* Ego lane array index */
#define SIT_OBJSCORE_LANE_RIGHT             (2u)  /* Right lane array index */
#define SIT_OBJ_SCORE_LANE_NUM              (3u)  /* Unknown lane array index */
#endif

#if (SIT_CFG_TRAFFIC_DENSITY)
#define SIT_TD_ACT_LIST_SIZE     (7u)          /*!< size of the active object list */
#define SIT_TD_HIST_LIST_SIZE    (15u)         /*!< size of the historical object list*/
#define SIT_TD_ACT_LIST_EGO_SIZE (2u)          /*!< size of the active object list for ego lane */
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

typedef SIT_t_PathOccupation SIT_t_PathOccupationArray[SIT_PATH_OCC_ENTRIES];

/*! Path occupation result structure, used in sit_check_occupied_lane.c. Only here because
simulation frame needs access to type. In ECU code type is only used in single C file. */
typedef struct SITPathOccResultStruct{
  float32       LengthTrajEgoFrontToObj;
  float32       PathWidth;
  ObjNumber_t   ObjIDL;
  ObjNumber_t   ObjIDR;
} SIT_t_PathOccResult;

typedef SIT_t_PathOccResult SIT_t_PathOccResultArray[SIT_PATH_OCC_ENTRIES];

typedef struct {
  ObjNumber_t ObjID;
  float32     HalbeSpurbreite;
  float32     CalculatedObjLength;
  float32     DistTrajToObjEdge;    /*!< Measured distance to trajectory */
  float32     ObjDistOnTraj;        /*!< Distance from EGO center of gravity to trajectory object reference point */
} SIT_t_PathOccInsertObjData;

#if (SIT_CFG_OBJECT_SCORING)
/*! Data type for an assigned object score */
typedef uint16 SITObjScore_t;
#endif

#if (SIT_CFG_OBJECT_SCORING)
/*! Scores for one object for the different lanes by one observer */
typedef struct SITObjLaneScores {
  SITObjScore_t Lanes[SIT_OBJ_SCORE_LANE_NUM];  /*!< The scores for the relevant lanes */
} SITObjLaneScores_t;
#endif

#if (SIT_CFG_OBJECT_SCORING)
/*! The assigned scores for one object for all the observed lanes */
typedef struct SITObjScoreData {
  SITObjLaneScores_t SumScore;     /*!< The current cycle score sum */
  eAssociatedLane_t eLane;        /*!< Associated lane based on scoring */
} SITObjScoreData_t;
#endif

/*--- sit_lanechange.c ---*/



#if (SIT_CFG_TRAFFIC_DENSITY)
/*! Struct history objects not in FoV */
typedef struct HistObjectStruct
{
  float32                 fDistX;           /*!< Distance to object */
  float32                 fVabsX;           /*!< absolute velocity */
  uint8                   uiFrontObjCell;   /*!< array index of the object in front */
  uint8                   uiBackObjCell;    /*!< array index of the object behind */
  uint8                   uiObjectAge;      /*!< 10 seconds * uiObjectAge = existence time for historical object */
  ObjNumber_t             ObjID;            /*!< object ID (Debug and validity detection) */
  SLATE_t_Obj_CLassification uiClass;          /*!< object class (for difference between car and truck) */
} t_HistObject;

/*! Struct objects in FoV */
typedef struct ActObjectStruct
{
  ObjNumber_t             ObjID;            /*!< object ID */
  SLATE_t_Obj_CLassification uiClass;          /*!< object class */
  uint16                  uiLifeTime;       /*!< object lifetime */
  float32                 fDistX;           /*!< Distance to object */
  uint8                   uiObjLossCount;   /*!< counter for lane change hysterese */
  boolean                 bObjExist;        /*!< to be or not to be, if false - add object to historical list */
} t_ActObject;

/*! Struct Lane Density Data for adjacent lane */
typedef struct LaneDensityData
{
  float32       fTrafficDensity;      /*!< traffic density in lane */
  float32       fVrelXMed;            /*!< relative middle velocity in lane */
  float32       fMaxPoint;            /*!< max distance border for traffic density calculation */
  float32       fMinPoint;            /*!< min distance border for traffic density calculation */
  sint8         siConfidence;         /*!< Confidence of traffic density */
  uint8         uiConfidenceCounter;  /*!< Confidence Counter for confidence change delay */
  uint8         uiLastCellIDBack;     /*!< last array index of the historical object in negative area */
  uint8         uiLastCellIDFront;    /*!< last array index of the historical object in positive area */
  uint8         uiOldObjectCellID;    /*!< object to delete if no place in a list */
  uint8         uiLaneState;          /*!< Traffic density state per lane */
  uint16        uiNoObjectCounter;    /*!< no traffic object available counter */
  t_ActObject   a_ActObjList[SIT_TD_ACT_LIST_SIZE];   /*!< Struct objects in FoV */
  t_HistObject  a_HistObjList[SIT_TD_HIST_LIST_SIZE]; /*!< Struct history objects not in FoV */
} t_LaneDensityData;

/*! Struct Lane Density Data for ego lane */
typedef struct LaneDensityDataE
{
  float32       fTrafficDensity;      /*!< traffic density in lane */
  float32       fVrelXMed;            /*!< relative middle velocity in lane */
  float32       fMaxPoint;            /*!< max distance border for traffic density calculation */
  float32       fMinPoint;            /*!< min distance border for traffic density calculation */
  sint8         siConfidence;         /*!< Confidence of traffic density */
  uint8         uiConfidenceCounter;  /*!< Confidence Counter for confidence change delay */
  uint8         uiLaneState;          /*!< Traffic density state per lane */
  t_ActObject   a_ActObjList[SIT_TD_ACT_LIST_EGO_SIZE]; /*!< Struct objects in FoV */
} t_LaneDensityDataE;

#endif

#if (SIT_CFG_TRAFFIC_DENSITY || SIT_CFG_TRAFFIC_ESTIMATION)
/*! Struct combination for all lanes  */
typedef struct GlobalDensityData
{
#if (SIT_CFG_TRAFFIC_DENSITY)
  t_LaneDensityData    DensityDataRight; /*!< right lane */
  t_LaneDensityData    DensityDataLeft;  /*!< left lane */
  t_LaneDensityDataE   DensityDataEgo;   /*!< ego lane */
  uint8                uiTrafficState;   /*!< combined traffic state */
#endif
#if (SIT_CFG_TRAFFIC_ESTIMATION)
  float32                uiJamProbability; /*!< probability of jam */
#endif
#if(SIT_CFG_TRAFFIC_ESTIMATION && SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING)
  CML_t_WeightedSample   t_CollectiveObject; /*!< Mean and stdev of collective velocity */
#endif
} GlobalDensityData_t;

#endif

/*! Struct for CutIn-potential specific object data */
typedef struct SITCutInObjDataTag{
  uint8         u_PotentialDistanceCutInOut; /*! CutIn/Out potential based on Distance to Inlap/ Distance to InlapDrop*/
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
  uint8         PotentialMultiObjectAnalyse; /*! CutIn/Out potential based on multi object analyse*/
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)*/
  uint8         u_KinematicCutInOutPot;      /*! CutIn/Out potential based on Kinematics*/
  uint8         u_FusedCutinPotential;       /*! Fused CutIn/Out potential */
} SITCutInObjData_t;

/* 
This is a global structure for LC module(local to SIT) which is not a part of output */
typedef struct SIT_LC_Globals{
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  float32 f_TimeFiltTurnIndLeft;      /*Hysteresis countdown time for turn indicator validity left*/
  float32 f_TimeFiltTurnIndRight;     /*Hysteresis countdown time for turn indicator validity left*/
#endif
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  float32 f_LCProbTIEnvLeft;          /*Lane availability probability  left*/
  float32 f_LCProbTIEnvRight ;        /*Lane availability probability right*/
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  float32 f_LCProbMultiobjectLeft;    /*probability based on surrounding OOI status left*/
  float32 f_LCProbMultiobjectRight ;  /*probability based on surrounding OOI status left*/
#endif
  float32 f_LCStateHysteresisRight;   /*hysteresis countdown for lane change state after probability drop*/
  float32 f_LCStateHysteresisLeft;    /*hysteresis countdown for lane change state after probability drop*/
  float32 f_LCFilterHysteresisRight;  /*hysteresis used to filter peak probabilities out */
  float32 f_LCFilterHysteresisLeft;   /*hysteresis used to filter peak probabilities out*/
  float32 f_LCProbLeftAverage;        /*final kinematic probability output*/
  float32 f_LCProbRightAverage;       /*final kinematic probability output*/
  SIT_LC_t_LaneChangeState t_PreviousState; /*previous state left / right  or follow*/
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  float32 f_LCCamLMHysteresisLeft;    /*hysteresis countdown after camera left lane marker crossed probability*/
  float32 f_LCCamLMHysteresiRight;    /*hysteresis countdown after camera right lane marker crossed probability*/
  float32 f_LCSteerbackTimer;         /*Timer for steerback phase*/
  eTurnIndicator_t TurnIndLastStatus; /* Previous state of ego turn indicator */
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  sint8   s_NumberLanesLeft;          /*number of lanes left */
  sint8   s_NumberLanesRight;         /*number of lanes right*/
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  sint8   s_relevantLaneObject;       /*relevant object id*/
  sint8   s_leftLaneObject;           /*id*/
  sint8   s_rightLaneObject;          /*id*/
#endif
}SIT_LC_Globals;

/*struct used for calculating the cumulative sum to distance to border */
typedef struct SITLaneChangeCUMSUMDist
{
   /*array with with all samples of border distance with a new measurement added every cycle up to the max number, afterwards is rested*/
  float32 fDMMRSamples[SIT_LC_CUMSUM_DIST_MAX_SAMPLES];  
  /*distance to border from previous cycle*/
  float32 fLastValue;                                     
  /* array index*/
  uint8 uiRunIndex;                                       
} SITLaneChangeCUMSUMDist;

/* Rate of change of yawrate calculate over a number of samples*/
typedef struct SITLaneChangeDMMRYaw
{
  /* Array with yaw rate samples*/
  float32 fDMMRSamples[SIT_LC_DMMR_YAW_MAX_SAMPLES];
  /* previous cycle yawrate*/
  float32 fLastValue;
  /* Array index*/
  uint8 uiRunIndex;
} SITLaneChangeDMMRYaw;

/*Kinematic global variables */
typedef struct SIT_LC_KINEMATIC_GLOBAL{
  SITLaneChangeDMMRYaw t_LaneChangeDMMRYaw;
  SITLaneChangeCUMSUMDist t_LaneChangeCUMSUMDist;
  /*yaw rate moving average calculated every cycle*/
  float32 fMovingAverageYawRate; 
  /*final kinematic probability*/
  float32 fLCProbOverall; 
}SIT_LC_Kinematic;


#if defined FCT_SIMU && !defined(FASTSIM)
#if (SIT_CFG_TRAFFIC_DENSITY)
typedef struct SITHistData{
  ObjNumber_t ObjID;
  float32 fDistX;   /* Longitudinal Displacement of the Object */
  float32 fDistY;   /* Lateral Displacement of the Object */
}SIT_ObjHistData_t;
#endif /* SIT_CFG_TRAFFIC_DENSITY */
#endif /* #if defined FCT_SIMU && !defined(FASTISIM) */

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

typedef struct SIT_FrontObstacleDetection{
  boolean b_FrontObstDetcd;     /* Boolean which indicates that if there are any crossing pedestrians/bicycle between subject(Ego) vehicle and OOI-0 */
  ObjNumber_t ObjID;            /* Object ID */
}SIT_FrontObstacleDetection_t; 
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */

/*! Typedef of output of SIT*/
typedef struct SITOutput{
 SITObjOutput_t t_ObjList[EM_N_OBJECTS];
 SIT_t_PathOccupationArray t_SITPathOccStat2Stat; 
 SIT_t_PathOccupationArray t_SITPathOccMov2Mov; 
#if defined FCT_SIMU && !defined(FASTSIM)
 #if (SIT_CFG_TRAFFIC_DENSITY)
 SIT_ObjHistData_t a_SITHistData[SIT_TD_HIST_LIST_SIZE];
 #endif /* END IF #if (SIT_CFG_TRAFFIC_DENSITY) */
#endif
#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))
    SIT_FrontObstacleDetection_t t_SIT_FrontObstacleDetection; 
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
 SIT_LC_t_LaneChangePhaseInfo t_LaneChangePhase;
 SIT_LC_Globals t_LaneChangeStatic;
 SIT_LC_Kinematic t_LaneChangeKinStatic;
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
 SITLCStateCamLaneMarkerCrossed_t t_CamLaneMarkerCrossed;
 SITLaneChangeCamPreMove_t t_LaneChangeCamPreMoveState;
#endif /* END IF FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */
 float32 f_DistXFarObjId;    /* Longitudinal Displacement of the Far Object in the Block path pair */
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
 float32 f_DistXCloseObjId;  /* Longitudinal Displacement of the Close Object in the Block path pair */
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
 float32 f_FarObjDistTraj;   /* Distance to trajectory of the Far Object in the Block path pair */
 float32 f_CloseObjDistTraj; /* Distance to trajectory of the Close Object in the Block path pair */

 sint16 s_LCProb;         /* Lane Change probability of the Ego vehicle */
 sint16 s_LCProbLeft;     /* Lane Change probability of the Ego vehicle to the left direction */
 sint16 s_LCProbRight;    /* Lane Change probability of the Ego vehicle to the right direction */
 /* for internal use only in lanechange not an actual output*/
#if defined FCT_SIMU && !defined(FASTSIM)
 ObjNumber_t StatCloseObjId; /*Nearer object in stat2stat blocked path; Used in SIM*/
 ObjNumber_t StatFarObjId;   /*Farther object in stat2stat blocekd path; Used in SIM*/
 ObjNumber_t CloseObjId;     /*Nearer object in mov2mov blocked path; Used in SIM*/
 ObjNumber_t FarObjId;       /*Farther object in mov2mov blocked path; Used in SIM*/
#endif /* END IF #if defined FCT_SIMU && !defined(FASTSIM) */
 ObjNumber_t t_BlockedPathFarObjID;  /* Object ID of the farther object in the Block path pair */
 ObjNumber_t t_BlockedPathCloseObjID; /* Object ID of the Nearer object in the Block path pair */
}SITOutput_t;

#ifdef FCT_SIMU
typedef struct SIT_SimMeasInfo{
  SITOutput_t t_SIT_FreezeOutput;
}SIT_SimMeasInfo_t;
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
typedef struct SITInputLAConst{
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  const LA_t_ScaleBracketState * pt_ScaleBracketState;
#endif
  const float32 * (*pf_ObjToRefDistMeas)(ObjNumber_t);
  const float32 * (*pf_ObjDistOnTraj)(ObjNumber_t);
  const boolean * (*pb_BasePreselObjList)(ObjNumber_t);
  const eAssociatedLane_t * (*pt_ObjAssociatedLane)(ObjNumber_t); /*!< Associated Lane for object */
  const eAssociatedLane_t * (*pt_ObjFuncLane)(ObjNumber_t); /*!< Associated Functional Lane for object*/
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
  const uint8 * (*pf_CameraCutInPotential)(ObjNumber_t);   /* Camera Cutin potential of object */
#endif
#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  const uint8 * (*pf_CameraCutOutPotential)(ObjNumber_t);  /* Camera Cutout potential of object */
#endif
  const float32  * (*pf_ObjDependantMaxRange)(ObjNumber_t);       /* Object Dependent Pick up Range */
  const fTime_t  * (*pt_PredTimeThreshold)(ObjNumber_t);          /* Prediction time of Object for predicted lane association */
  const fTime_t  * (*pt_TotalTimeToInlap)(ObjNumber_t);           /* Total TimeToInlap of Object for predicted lane association */
  const fTime_t  * (*pt_TotalTimeToInlapDrop)(ObjNumber_t);       /* TotalTimeToInlapDrop of Object for predicted lane association */
  const float32  * (*pt_f_DistanceToInlap)(ObjNumber_t);          /* Distance to Inlap of Object for predicted lane association */
  const float32  * (*pt_f_DistanceToInlapDrop)(ObjNumber_t);      /* Distance to Inlapdrop of Object for predicted lane association */
  const float32  * (*pt_f_TotalDistanceToInlap)(ObjNumber_t);     /* TotalDistanceToInlap of Object for predicted lane association */
  const float32  * (*pt_f_TotalDistanceToInlapDrop)(ObjNumber_t); /* TotalDistanceToInlapDrop of Object for predicted lane association */
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
  const float32  * (*pf_ObjInLap)(ObjNumber_t);                   /* Object's geometric lane association based In-Lap */
  const float32  * (*pf_ObjToRefDistFiltVar)(ObjNumber_t);        /* Pointer to variance of object to reference distance measurement */
  const float32  * (*pf_ObjToRefDistGradFilt)(ObjNumber_t);       /* Pointer to gradient filter of object to reference distance measurement */
  const float32  * (*pf_ObjToRefDistGradFiltVar)(ObjNumber_t);    /* Pointer to variance of gradient filter of object to reference distance measurement */
  const float32  * pf_SeekLaneWidth;                              /* Variable for seek lane width*/
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */
}SITInputLAConst_t;

typedef struct SITInputLAModify{
  LA_t_ObjLaneState * (*pt_ObjLaneState)(ObjNumber_t);
}SITInputLAModify_t;

#endif

typedef struct SITInputModify{
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  SITInputLAModify_t t_LAInputModify;
#endif
}SITInputModify_t;

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) 
typedef struct SITInputFIPMOTConst_t{
  const TraceID_t * (*pu_FIPStaticTraceID)(const ObjNumber_t);
} SITInputFIPMOTConst_t;
#endif


/*! Typedef of constant input to SIT component from CP */
typedef struct SITInputCPConst{
  /*Only 1 member of CP_t_CourseData structure is being used in LA. So only this member is being shifted to this structure
  If in future more members will be used, Shift the whole structure into this*/
  const fCurve_t* pf_CourseCurve; /*!< fCurve */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  const CAL_t_TracePolyL2 * (*pt_TracePoly)(TraceID_t);
#endif
}SITInputCPConst_t;

typedef struct SITObjData_Meas{
SITCutInObjData_t t_SITObjCutInPotMeas;
uint8 uiCutInProbability;
uint8 uiCutOutProbability;
}SITObjData_Meas_t;

typedef struct SIT_DeviceMeas{
  SITObjData_Meas_t t_SITObjData_Meas[EM_N_OBJECTS];
#if (SIT_CFG_TRAFFIC_DENSITY || SIT_CFG_TRAFFIC_ESTIMATION)
  GlobalDensityData_t t_SIT_GlobalTrafficDensity_Meas;
#endif
}SIT_t_DeviceMeasInfo;

/*! Typedef of inputs to SIT component from Frame */
typedef struct SITInputFrame{
#ifdef FCT_SIMU
  SIT_SimMeasInfo_t * pt_SIT_SimMeasInfo; /*!< Sim Freeze of SIT from Frame */
  const MEASInfo_t * pt_SIT_SimMeasInfoFreeze;
#endif
  SIT_t_DeviceMeasInfo * pt_SIT_DeviceMeasInfo; /*!< Sim Freeze of CP from Frame */
  const MEASInfo_t * pt_SIT_DeviceMeasInfoFreeze;
}SITInputFrame_t;

/*! Typedef of constant input to SIT component from RTE Input Ports */
typedef struct SITInputRTEConst{
  const float32 * (*pf_ObjLongDisp)(ObjNumber_t); /* Longitudinal displacement of object */
  const float32 * (*pf_ObjLatDisp)(ObjNumber_t); /* Lateral displacement of object */
  const float32 * (*pf_ObjVrelX)(ObjNumber_t); /* Relative longitudinal velocity of object */
  const float32 * (*pf_ObjVrelY)(ObjNumber_t);    /* Object relative lateral velocity */
  const float32 * (*pf_ObjArelX)(ObjNumber_t); /* Relative longitudinal acceleration of object */
  uint8   (*pu_AccObjQuality)(ObjNumber_t); /* ACC Object Quality */
  const uint16 * (*pu_ObjLifeCycles)(ObjNumber_t); /* Number of life cycles of object */
  const float32 * (*pf_ObjVrelYStd)(ObjNumber_t); /* Standard deviation of relative lateral velocity of object */
  const float32 * pf_EgoLongVel; /* Longitudinal velocity of ego vehicle */
  const float32 * pf_EgoLongAccel; /* Longitudinal acceleration of ego vehicle */
  const float32 * pf_EgoCurve; /* Curvature of ego vehicle path */
  const float32 * pf_EgoCurveGrad; /* Curvature Gradient of ego vehicle path */
  const float32 * pf_EgoDrvIntCurve; /* Curvature of ego vehicle path driving into a curve */
  const float32 * pf_EgoDrvIntCurveVar; /* Curvature variance of ego vehicle path driving into a curve */
  const ObjNumber_t * (*pu_DistXSortedObj)(ObjNumber_t); /*!< List of objects sorted as per distance from EM */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  const t_CamLaneInputData * pt_CamLaneData; /* Input Camera Lane Data */
#endif
  boolean (*b_ObjIsNew)(ObjNumber_t); /*!< Boolean informing if object is new */
  boolean (*b_ObjIsDeleted)(ObjNumber_t); /*!< Boolean informing if object is deleted */
  const SLATE_t_Obj_DynamicProperty * (*pt_ObjDynProperty)(ObjNumber_t); /* Dynamic property of object */
  const SLATE_t_Obj_CLassification * (*pt_ObjClassification)(ObjNumber_t); /* Classification of object */
  boolean (*b_ObjIsMovingToStationary)(ObjNumber_t); /*!< Boolean informing if object was moving */
  float32 (*pf_ObjOrientation)(ObjNumber_t); /* Orientation of object */
  const float32 * pf_FCTBumperToCoG; /* Sensor Position Relative to CoG */
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const float32 * pf_TunnelProbability; /* Probability of Tunnel */
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  const eTurnIndicator_t * pt_TurnIndicator; /* Turn indicator information from input */
#endif /*SIT_CFG_LC_USE_TURN_INDICATOR_INPUT*/
}SITInputRTEConst_t; 

#if (FCT_CFG_ACC_OOI)
typedef struct SITInputOOIConst{
  const ObjNumber_t * (*pu_OOIListObjId)(uint8); /* Obj Number of OOI-0 */
  const OOI_RelObject_t *pt_OOIRelObj;
}SITInputOOIConst_t;
#endif

/*! Typedef of constant input to SIT component*/
typedef struct SITInputConst{
  SITInputFrame_t t_FrameFreezes;
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  const FIP_ND_Output_t *pt_FIPNaviData;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_RT_Output_t *pt_FIPRoadType;
  const FIP_OA_Output_t *pt_FIPOA;
  const FIP_RD_Output_t *pt_FIPRoad;
  const FIP_TO_Output_t *pt_FIPTO;
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  SITInputLAConst_t t_LAInput;
#endif
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  const FIP_CL_Output_t *pt_FIPCamLane;
#endif /*END IF SLATE_CFG_CAM_LANE_INTERFACE*/
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
  SITInputFIPMOTConst_t t_FIPMOTTraceId;
  const FIP_MOT_Output_t *pt_FIPMOT;
#endif
  const FIP_LM_Output_t *pt_FIPLM;
  SITInputCPConst_t t_CP;
  SITInputRTEConst_t t_RTE;
  SITInputOOIConst_t t_OOI;
} SITInputConst_t;
/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

extern MEMSEC_REF SLATECompState_t SIT_t_State;

#if (SIT_CFG_TRAFFIC_DENSITY || SIT_CFG_TRAFFIC_ESTIMATION)
extern MEMSEC_REF GlobalDensityData_t SITGlobalDensityData; /*!< Struct combination for all lanes  */ 
#endif /* Remark: Used in OUT*/

extern MEMSEC_REF SITCutInObjData_t SITCutInObjData[EM_N_OBJECTS];

/*! External declaration of SIT output structure */
extern MEMSEC_REF SITOutput_t t_SITOutput;

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*-- sit_main.c --*/
extern void SIT_v_ProcessPRE(SITInputConst_t * pt_SIT_InputGlobal, SITInputModify_t * pt_SIT_InputModifyGlobal, SITOutput_t * pt_SIT_OutputGlobal);
extern void SIT_v_ProcessPOST(SITInputConst_t * pt_SIT_InputGlobal, SITInputModify_t * pt_SIT_InputModifyGlobal, SITOutput_t * pt_SIT_OutputGlobal);
extern void SIT_v_DeleteObject(ObjNumber_t ObjId);
extern void SIT_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete);
extern void SIT_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr);
extern void SIT_v_PreProcessPRE(SITInputConst_t * pt_SIT_InputGlobal, SITInputModify_t * pt_SIT_InputModifyGlobal, SITOutput_t * pt_SIT_OutputGlobal,  FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);
extern void SIT_v_SetOperationMode(SLATECompState_t const t_SITOpModeValue);

#ifdef __cplusplus
};
#endif
/// @}
#endif /*!< FCT_CFG_ACC_SITUATION */

/* End of conditional inclusion */
#else
#endif  /*!< _SIT_EXT_INCLUDED */

