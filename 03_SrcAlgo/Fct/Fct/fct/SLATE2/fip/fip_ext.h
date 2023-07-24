/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_ext.h

DESCRIPTION:               Extern Header File for ACC FCT Input Preprocessing (FIP) module

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             12.11.2012

VERSION:                   $Revision: 1.30 $

LEGACY VERSION:            Revision: 2.3.1.1

**************************************************************************** */
#ifndef FIP_EXT_INCLUDED
#define FIP_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip_ver.h"
#include "fip_cfg.h"
#include "slate_ext.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip
@{ */

#ifdef __cplusplus
extern "C" {
#endif
#if (FCT_CFG_INPUT_PREPROCESSSING)
/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/
/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/
/*! Maximum X distance for an oncoming object to become relevant */
#define FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX     (25.0f)
/* Constant definitions corresponds to typedef t_CamLaneMarkerEnum
   Filename:	Rte_SWCFctSenAdapt_Type.h
   RTE Version: 4.0.3.1.6.0   */
/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/


#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES))
/*!  */
#define FIP_u_TRACE_INVALID_ID            (255u)
/*! for check, whether trace is occupied but without obj */
#define FIP_u_TRACE_VALID_NO_OBJ_ID       (249u )   //FIP_MOT_VALID_NO_OBJ_ID
/*! for check, whether trace is occupied     with    obj */
#define FIP_u_TRACE_VALID_OBJ_ID          (250u )   //EOMOT_VALID_OBJ_ID
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/


/************************************************************************/
/* FIP Output Structures                                                */
/************************************************************************/
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/*! Typedef of FIP  specific Camera Object Data attributes */
typedef struct 
{
  FIP_t_CamTurnLightsState eTurnLightsState;  
  FIP_t_CamBrakeLight eBrakeLight;
  FIP_t_CamAssociatedLane eAssociatedLane;
  FIP_t_CamObjManeuver eObjManeuver;
  percentage_t t_BrakeLightConf;
  percentage_t t_TurnLightsStateConf;
  percentage_t t_AssociatedLaneConf;
  percentage_t t_CamConfirmationProb;
  percentage_t t_AssignedLaneQual;
  percentage_t t_AssLaneLeftQual;
  percentage_t t_AssLaneRightQual;
 } FIP_t_CamObjectData;
#endif

/*! Typedef of object specific output of FIP Object attributes */
typedef struct FIP_OAObj_Output{
  float32 fWidth;   /*Width of object using camera shape points*/
  float32 fLength;  /*Length of object using camera shape points*/
  float32 fObjectLength; /*Length of object using object class for use in SIT and LA*/
  float32 f_ObjectWidthCorridor; /*Object width for corridor calculations*/
  fVelocity_t fAbsVelocity;         /*!< Absolute longitudinal speed, with negative speeds indicating oncoming objects @min:-100 @max:100 @unit:m/s */
  fAccel_t fAbsAcceleration;     /*!< Absolute longitudinal acceleration, with positive accelerating away from us @min:-20 @max:20 @unit: m/s² */
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  float32     f_CamOverlapDst;                        /* Camera overlap distance  @unit: m  */
  float32     f_CamObjWidth;                          /* Camera object width @unit: m*/
  float32     f_Cam_overlap_diff_left_and_right;      /* difference between left to right overlap value, used for compensation [m]*/
#endif
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  FIP_t_CamObjectData t_CamObjectData;
  uint8 u_ExternalID_Cam; 	  
#endif
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  uint8       u_Cam_overlap_compensation_cnt;         /* offset validity counter  [0 .. FIP_CAM_VALID_OFFSET_CNT_INIT]*/
#endif
  FIP_OA_Bool_t t_Bool; /*!< bits indicating information about FIP object attributes */
  StatObjWasOncoming_t StatObjWasOncoming;
}FIP_OAObj_Output_t;

/*! Typedef of output of FIPObjectAttributes */
typedef struct FIP_OA_Output{
  FIP_OAObj_Output_t t_ObjList[EM_N_OBJECTS]; /*!< Object specific output of FIP Object attributes */
}FIP_OA_Output_t;

/*! Typedef of output of FIPTRAFFIC */
typedef struct FIP_TO_Output{
  SLATE_t_TrafficOrientation t_FIPTrafficOrientation;
}FIP_TO_Output_t;

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
/*! Typedef of output of FIP curvature change */
typedef struct FIP_CC_Output{
  float32 f_FusedDistToHighCC;       /*! Fused distance to high curvature change [0.f ... FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX] */
  boolean b_FusedDistToHighCCValid;  /*! Valid flag for fused distance to high curvature change */
}FIP_CC_Output_t;
#endif

/*! Typedef of output for FIP module */
typedef struct FIP_ALL_Output{
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  FIP_LM_Output_t t_FIP_LM_Output;
#endif
  FIP_OA_Output_t t_FIP_OA_Output;
  FIP_RD_Output_t t_FIP_RD_Output;
  FIP_RT_Output_t t_FIP_RT_Output;
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
  FIP_MOT_Output_t t_FIP_MOT_Output;
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE)) */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  FIP_CL_Output_t t_FIP_CL_Output;
#endif /* END IF SLATE_CFG_CAM_LANE_INTERFACE */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  FIP_ND_Output_t t_FIP_ND_Output;
#endif /* END IF (SLATE_CFG_SIMPLE_NAVI_INTERFACE) */
  FIP_TO_Output_t t_FIP_TO_Output;
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  FIP_CC_Output_t t_FIP_CC_Output;
#endif
}FIP_ALL_Output_t;

#ifdef FCT_SIMU
typedef struct FIP_SimMeasInfo{
  FIP_ALL_Output_t t_FIP_FreezeAllOutput;
}FIP_SimMeasInfo_t;
#endif

/************************************************************************/
/* FIP Device Freeze Structures                                         */
/************************************************************************/
/* FIPLaneMatrix Device Freeze Structure */
typedef struct FIPLM_DeviceMeasInfo{
  float32 f_FIPLaneWidth; /*!< Lane Width */
  sint8 s_NumOfLaneLeft;  /*!< Number of lanes on the left */
  sint8 s_NumOfLaneRight; /*!< Number of lanes on the right */
}FIPLM_DeviceMeasInfo_t;

/* FIP Traffic Orientation Device freeze structure */
typedef struct FIPTO_DeviceMeasInfo{
  SLATE_t_TrafficOrientation t_FIPTrafficOrientation; /*!< Traffic Orientation Information */
}FIPTO_DeviceMeasInfo_t;

/*! NAVI FIP Device Freeze Structure */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
typedef struct  FIP_NaviDebugMeasInfo{
  boolean b_ValidNaviData;
  boolean b_NaviPathPlausible;
  boolean b_ValidNaviNumberLanes;
}FIP_NaviDebugMeasInfo_t;
#endif

/*! FIP All Device Freeze Structure */
typedef struct FIP_DeviceMeasInfo{
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  FIPLM_DeviceMeasInfo_t t_FIPLaneMatrix;
#endif
  FIPTO_DeviceMeasInfo_t t_FIPTrafficOrientInfo;
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
  FIP_NaviDebugMeasInfo_t t_NaviMeasInfo;
#endif
}FIP_DeviceMeasInfo_t;


/************************************************************************/
/* FIP Input Structures                                                 */
/************************************************************************/
#if (FCT_CFG_ACC_SITUATION)
/*! Typedef of constant input to FIP Lane Matrix from SIT component */
typedef struct FIP_LM_InputSITConst{
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  const SITLCStateCamLaneMarkerCrossed_t * pt_SITCamLaneMarkerCrossed;
  const SITLaneChangeCamPreMove_t * pt_SITLaneChangeCamPreMoveState;
#else /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/
  boolean b_Dummy;
#endif
}FIP_LM_InputSITConst_t;
#endif /* END IF FCT_CFG_ACC_SITUATION */

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
typedef struct FIP_ND_InputLAConst{
  const fDistance_t *pt_MovingObjPickUpRange;
}FIP_ND_InputLAConst_t;
#endif

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
/*! Typedef of constant input to FIPLaneMatrix */
typedef struct FIP_LM_InputConst{
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  boolean b_NaviPathPlausible;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */
#if (FCT_CFG_ROAD_INPUT)
  const float32 * pf_NoLaneProbLeft;
  const float32 * pf_NoLaneProbRight;
#endif /* END IF FCT_CFG_ROAD_INPUT */
#if (FCT_CFG_ACC_SITUATION)
  FIP_LM_InputSITConst_t t_SIT;
#endif /* END IF FCT_CFG_ACC_SITUATION */
}FIP_LM_InputConst_t;
#endif /* END IF FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*! Typedef of constant input to FIP_NAVI data */
typedef struct FIP_ND_InputConst{
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  FIP_ND_InputLAConst_t t_LAInput;
#else
  boolean b_Dummy;  
#endif
}FIP_ND_InputConst_t;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE */

/*! Typedef of constant input to FIPObjectAttributes */
typedef struct FIP_OA_InputConst{
  /* Input to FIP OA from RTE Ports */
  boolean (*b_ObjIsMovingToStationary)(ObjNumber_t); /* Type of longitudinal Obj */
}FIP_OA_InputConst_t;

/*! Typedef of constant input to FIPRoad */
typedef struct FIP_RD_InputConst{
#if (FCT_CFG_ROAD_INPUT) && (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
#if (FCT_CFG_COURSE_PREDICTION)
  const CP_t_TrajectoryState * pt_TrajectoryState;
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  const fDistance_t * pt_MovingObjBasePickUpRange;
#endif
#else
  boolean b_Dummy;  
#endif
}FIP_RD_InputConst_t;

/*! Typedef of constant input to FIPLaneMatrix */
typedef struct FIP_RT_InputConst{
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  boolean b_NaviPathIsValid;
#else
  boolean b_Dummy;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
}FIP_RT_InputConst_t;

typedef struct FIP_TO_InputConst{
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  boolean b_NaviPathIsValid;
#else
  boolean b_Dummy;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
}FIP_TO_InputConst_t;

/*! Typedef of constant input to FIP component from RTE Input Ports */
typedef struct FIPInputRTEConst{
  const float32 * (*pf_ObjLongDisp)(ObjNumber_t);  /* Longitudinal displacement of object */
  const float32 * (*pf_ObjLatDisp)(ObjNumber_t);   /* Lateral displacement of object */
  const float32 * (*pf_ObjVRelX)(ObjNumber_t);     /* Object relative longitudinal velocity */
  const float32 * (*pf_ObjArelX)(ObjNumber_t);     /* Object relative longitudinal acceleration */
  const SLATE_t_Obj_DynamicProperty * (*pt_ObjDynamicProperty)(ObjNumber_t); /* Object dynamic property */
  const float32 * pf_EgoVelObjSync;                /* Ego velocity sync */
  const float32 * pf_EgoAccObjSync;                /* Ego acceleration sync */
  const float32 * pf_EgoCurve;                     /* Curvature of the ego vehicle path */
}FIPInputRTEConst_t; 


/*! Typedef of inputs to SIT component from Frame */
typedef struct FIPInputFrame{
#ifdef FCT_SIMU
  FIP_SimMeasInfo_t * pt_FIP_SimMeasInfo; /*!< Sim Freeze of FIP from Frame */
  const MEASInfo_t * pt_FIP_SimMeasInfoFreeze;
#endif
  FIP_DeviceMeasInfo_t * pt_FIP_DeviceMeasInfo; /*!< Device Freeze of FIP from Frame */
  const MEASInfo_t * pt_FIP_DeviceMeasInfoFreeze;
}FIPInputFrame_t;

/*! Typedef of constant input to FIP Module */
typedef struct FIP_ALL_InputConst{
  FIPInputFrame_t t_FrameFreeze;
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  FIP_LM_InputConst_t t_FIP_LM_InputConst;
#endif /* END IF FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  FIP_ND_InputConst_t t_FIP_ND_InputConst;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE */
  FIP_OA_InputConst_t t_FIP_OA_InputConst;
  FIP_RD_InputConst_t t_FIP_RD_InputConst;
  FIP_RT_InputConst_t t_FIP_RT_InputConst;
  FIP_TO_InputConst_t t_FIP_TO_InputConst;
  FIPInputRTEConst_t t_RTE;
}FIP_ALL_InputConst_t;

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/

#define FIP_CAM_LANE_POE_LEVEL                  (70u)             /*! Threshold for the existence probability of the camera lane; only above this value, the camera lane is cosidered as valid */
#define FIP_NAVI_MAX_APPROX_EGO_DIFF            (3.f)             /*!< Maximum difference between the approximated NAVI path and EGO curve @unit:m */
#define FIP_NAVI_MAX_YCOMP_AT_ORIG              (5.f)             /*!< Threshold for maximum difference between EGO path estimated NAVI path at X = 0 */

/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_INPUT_PREPROCESSSING)
extern MEMSEC_REF SLATECompState_t FIPState;
#endif

/*! External declaration of FIP ALL output structure which is filled in this component */
extern MEMSEC_REF FIP_ALL_Output_t t_FIP_ALL_Output;

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- fip_main.c ---*/
extern void FIP_v_PreProcess(FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal, FCTSen_MergeDeleteObject_t t_FIPSen_MDObjList[]);
extern void FIP_v_Process(FIP_ALL_InputConst_t * pt_FIP_ALL_InputGlobal, FIP_ALL_Output_t * pt_FIP_ALL_OutputGlobal);
extern void FIP_v_DeleteObject(ObjNumber_t ObjId);
extern void FIP_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete);
extern void FIP_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr);
extern void FIP_v_SetOperationMode(SLATECompState_t const t_FIPOpModeValue);

/*--- fip_navi_data_plg.c and fip_navi_data_process.c (used in CP and SI) ---*/
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
extern float32 FIP_f_GetEgoNaviPathErrDistAvg(void);
extern float32 FIP_f_GetNaviPathToPolySumSqDistAvg(void);
extern CAL_t_TracePolyL2 FIP_t_GetApproxNaviPath(void);
extern void FIP_v_CalcNaviPathApproxPosSample(SLATE_t_PosSamples * pOutput);
extern void FIPGetNaviNumLaneAtDist(uint8 * pu_NumLane, const float32 fDist);
#endif

#endif /*FCT_CFG_INPUT_PREPROCESSSING  */
#ifdef __cplusplus
};
#endif
/* End of conditional inclusion */
///@}
#endif  /*!< _FIP_EXT_INCLUDED */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
