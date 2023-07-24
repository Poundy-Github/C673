/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_ext.h

DESCRIPTION:               Course prediction external header file

AUTHOR:                    Norman Apel

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.29 $

LEGACY VERSION:            Revision: 2.2.1.1

**************************************************************************** */
#ifndef CP_EXT_INCLUDED
#define CP_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/* Note: the below file is a dependency of this header, but currently through
include hierarchy considerations, this file is only included after that file
has already been pre-processed */
#include "slate_ext.h"
#include "cp_ver.h"
#include "cp_cfg.h"

#if (FCT_CFG_COURSE_PREDICTION)
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp
@{ */


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
#define CP_TRAJ_INVALID_VALUE       999.f

/*! @brief CP_INVALID_INLAP */
#define CP_INVALID_INLAP                        (-999.f)
/*! @brief CP_INVALID_INLAP_VAR */
#define CP_INVALID_INLAP_VAR                    (1.0E10f)
/*! @brief sTRAJ_C0 */
#define CP_sTRAJ_C0                                (0u)
/*! @brief sTRAJ_C1 */
#define CP_sTRAJ_C1                                (1u)
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
  /*! @brief sTRCE_TRAJ_C0 */
#define CP_sTRACE_TRAJ_C0                          (0u)
/*! @brief sTRACE_TRAJ_C1 */
#define CP_sTRACE_TRAJ_C1                          (1u)
/*! @brief CP_TRACE_TRAJ_NOISE */
#define CP_TRACE_TRAJ_NOISE                       (1.0E-6f)
#endif
/*****************************************************************************
  MACROS
*****************************************************************************/

/*! @brief  Utility define for the number of traces in the system */
#define CP_NUM_TRACES   (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES

  /*! @brief Minimum length of trace to used in CP */
#define CP_NUM_TRACE_MIN_NUMBER_OF_POINTS       (3u)


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*! @brief distance and deviation of object trace to vdy or road curve */
typedef struct 
{
  float32   fDistMean;  /*!< fDistMean */
  float32   fDistStdDev;  /*!< fDistStdDev */
}CP_t_Trace2CurveParallelism;

/*! @brief CP_t_TrajectoryInputParameter */
typedef struct
{
  uint8 b_dummy[3];   /*structure padding*/
  boolean bSuppressFusion;  /*!< Fusion will be suppressed */  
}CP_t_TrajectoryInputParameter;

/*! @brief CP_t_TrajectoryMeas */
typedef struct CP_TrajectoryMeas
{
  float32 fx;/*!<fx */
  float32 fy;/*!<fy */
  float32 fphi;/*!<fphi */
  float32 fc0;/*!<fc0 */
  float32 fc1;/*!<fc1 */
  CP_t_TrajectoryConfig  Config;/*!<Config */
  CP_t_TrajectoryState   State;/*!<State */
}CP_t_TrajectoryMeas;

typedef struct CP_UnfiltCourseMeas
{
  float32 fx;/*!<fx */
  float32 fy;/*!<fy */
  float32 fphi;/*!<fphi */
  float32 fc0;/*!<fc0 */
  float32 fc1;/*!<fc1 */
}CP_t_UnfiltCourseMeas;


/*! @brief  CPTraj2MOTraceParallelism */
typedef struct CP_Traj2MOTraceParallelism
{
  boolean   relevantTrace;/*!<relevantTrace */
  float32   fSADistMean; /*!<fSADistMean */
  float32   fSADistStdDev;/*!<fSADistStdDev */
}CP_t_Traj2MOTraceParallelism;

/*! Structure used to store trace additional data */
typedef struct CPTraceScoreAddData {
  ObjNumber_t       iObjNr;             /*!< Object number of the trace */
  uint8             uNumberOfPoints;    /*!< Number of trace points we have already seen */
  uint8             uApproxUseLen;      /*!< Number of indices to use for approximation */
  /*uint8             uTraceLaneIdx;*/  /*!< Trace lane index assigned */
  float32           fApproxCloseDist;   /*!< Close distance from where polynomial approx valid */
  float32           fApproxFarDist;     /*!< Far distance till where polynomial approx valid */
  float32           fCurSqDist;         /*!< summed squared distance of the sample points to the approximation polynomial (the residual) */
  CAL_t_TracePolyL2   ApproxPoly;         /*!< Trace approximation polynomial */
  boolean           isValid;            /*!< Flag to indicate whether the trace polynomial is valid */
  boolean           bUseTraceForFusion; /*!< Flag to indicate whether the trace is used within the trajectory fusion */
}CP_t_TraceAddData;

#if (FIP_CFG_USE_EGO_TRACE)
/*! Structure used to store ego trace additional data */
typedef struct CP_EgoTraceAddData {
  uint8             uNumberOfPoints;    /*!< Number of trace points we have already seen */
  float32           fApproxFarDist;     /*!< Far distance till where poly approx valid */
  float32           fCurSqDist;         /*!< summed squared distance of the sample points to the approximation polynomial (the residual) */
  CAL_t_TracePolyL2   ApproxPoly;         /*!< Trace approximation polynomial */
}CP_t_EgoTraceAddData;
#endif

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
/*! @brief Structure for navi CP meas freeze */
typedef struct CP_NaviDebugMeasInfo{
  boolean b_NaviFusionExternalSwitch;
  boolean b_ValidSpeedRangeFusion;
  boolean b_ValidPathLengthFusion;
  boolean b_IsLaneChangeFusion;
}CP_t_NaviDebugMeasInfo;
#endif

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*! @brief CP_t_TraceTrajectory */
typedef struct {
  float32 fCurve;/*!< fCurve */
  float32 fMaxDist;/*!< fMaxDist */
  float32 fMeanSquaredError;/*!< fMeanSquaredError */
  float32 fWeight;/*!< fWeight */
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
  GDBBaseKafi_t         KafiTraceEst;    /*!< The Kalman filter base data for trace(matrix representation information) */
  CP_t_TrajKafiData     KafiTraceData;   /*!< The Kalman filter data for trace (the matrices/vectors themselves) */
#endif
} CP_t_TraceTrajectory;
#endif

typedef struct CP_DeviceMeasInfo{
  CP_t_TrajectoryMeas    Trajectory;     /*!<Trajectory */
  CP_t_UnfiltCourseMeas  UnFiltCourse;   /*!<UnFiltCourse */
#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
  CP_t_NaviDebugMeasInfo t_NaviMeasInfo;
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CP_t_TraceTrajectory TraceTrajectory;
#endif
}CP_t_DeviceMeasInfo;

/*! Typedef of output of CP */
typedef struct CPOutput{
  CP_t_TrajectoryData  CP_TrajectoryData; /*Data related to CP trajectory*/
  CP_t_CourseData      CP_CourseData; /* Last cycle course data*/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CAL_t_TracePolyL2    CP_TracePoly[FIP_STATIC_TRACE_NO_OF_TRACES]; /*!< Trace approximation polynomial */
  CP_t_TraceTrajectory TraceTrajectory;
#endif
}CPOutput_t;

#ifdef FCT_SIMU
typedef struct CP_SimMeasInfo{
  CPOutput_t t_CP_FreezeOutput;
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CP_t_TraceAddData CP_TraceAdd[CP_NUM_TRACES];
#endif
#if (FIP_CFG_USE_EGO_TRACE)
  CP_t_EgoTraceAddData CP_EgoTraceAdd;
#endif
}CP_SimMeasInfo_t;
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
typedef struct CPInputLAConst{
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  LA_t_ScaleBracketState * pt_ScaleBracketState;  /*!< Reference to state of trace bracket adaption*/
#endif
  fDistance_t *pt_MovingObjPickUpRange;
  fDistance_t *pt_MovingObjBasePickUpRange;
}CPInputLAConst_t;
#endif

#if (FCT_CFG_ACC_SITUATION)
/*! Typedef of constant input to CP component from SIT */
typedef struct CPInputSITConst{
/*getter function for lane change Prob, state, phase*/
  const SIT_LC_t_LaneChangePhaseInfo * pt_GetLaneChangeInfo;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE) 
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  const float32 * (*pf_CrossingDistTrace)(const ObjNumber_t);
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
}CPInputSITConst_t;
#endif /* END IF FCT_CFG_ACC_SITUATION */

/*! Typedef of constant input to CP component from RTE Input Ports */
typedef struct CPInputRTEConst{
  const float32 * (*pf_ObjLongDisp)(ObjNumber_t); /* Longitudinal displacement of object */
  const float32 * (*pf_ObjLatDisp)(ObjNumber_t); /* Lateral displacement of object */
  uint8  (*pu_AccObjQuality)(ObjNumber_t); /* ACC Object Quality */
  const uint8 * (*pu_ObjExistProbability)(ObjNumber_t); /* Probability of existence of object */
  const float32 * pf_EgoLongVel; /* Longitudinal velocity of ego vehicle */
  const float32 * pf_EgoSideSlip; /* Side slip angle of ego vehicle */
  const float32 * pf_EgoSideSlipVar; /* Side slip angle variance of ego vehicle */
  const float32 * pf_EgoCurve; /* Curvature of ego vehicle path */
  const float32 * pf_EgoCurveGrad; /* Curvature Gradient of ego vehicle path */
  const float32 * pf_EgoCurveVar; /* Curvature variance of ego vehicle path */
  const float32 * pf_EgoDrvIntCurve; /* Curvature of ego vehicle path driving into a curve */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  const t_CamLaneInputData * pt_CamLaneData; /* Input Camera Lane Data */
#endif
  const float32 * pf_SensorYPos; /* Lateral position of sensor mounting */
  const float32 * pf_FCTBumperToCoG; /* Sensor Position Relative to CoG */
  boolean (*pb_ObjIsShadow)(ObjNumber_t); /* Boolean indicating if object is shadow */
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const float32 * pf_TunnelProbability; /* Probability of Tunnel */
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  const eTurnIndicator_t *pt_TurnIndicator;
#endif /*SIT_CFG_LC_USE_TURN_INDICATOR_INPUT*/
}CPInputRTEConst_t; 

#if (FCT_CFG_ACC_OOI)
typedef struct CPInputOOIConst{
  const OOI_RelObject_t *pt_OOIRelObj; /* Relevant Object Information */
}CPInputOOIConst_t;
#endif

/*! Typedef of inputs to SIT component from Frame */
typedef struct CPInputFrame{
#ifdef FCT_SIMU
  CP_SimMeasInfo_t * pt_CP_SimMeasInfo; /*!< Sim Freeze of SIT from Frame */
  const MEASInfo_t * pt_CP_SimMeasInfoFreeze;
#endif
  CP_t_DeviceMeasInfo * pt_CP_DeviceMeasInfo; /*!< Sim Freeze of CP from Frame */
  const MEASInfo_t * pt_CP_DeviceMeasInfoFreeze;
}CPInputFrame_t;

/*! Typedef of constant input to CP component */
typedef struct CPInputConst{
  CPInputFrame_t t_FrameFreezes;
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  const FIP_ND_Output_t *pt_FIPNaviData;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_RT_Output_t *pt_FIPRoadType;
  const FIP_RD_Output_t *pt_FIPRoad;
  const FIP_OA_Output_t *pt_FIPOA;       /*! < Input of FIP Object attributes */
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)  
  const FIP_TO_Output_t *pt_FIPTO;       /*! < Input of FIP Traffic Orientation */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */  
#endif /*END IF FCT_CFG_INPUT_PREPROCESSSING*/
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  const FIP_CL_Output_t *pt_FIPCamLane;
#endif/* END IF SLATE_CFG_CAM_LANE_INTERFACE*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  CPInputLAConst_t t_LAInput;
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
  const FIP_MOT_Output_t *pt_FIPMOT;
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const FIP_LM_Output_t *pt_FIPLaneMatrix;
#endif
#if (FCT_CFG_ACC_SITUATION)
  CPInputSITConst_t t_SIT;
#endif /* END IF FCT_CFG_ACC_SITUATION */
#if (FCT_CFG_ACC_OOI)
  CPInputOOIConst_t t_OOI;
#endif
  CPInputRTEConst_t t_RTE;
} CPInputConst_t;

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF SLATECompState_t CP_State;

#ifdef FASTSIM
extern CP_t_DeviceMeasInfo CP_DeviceMeasInfo;
#endif

extern MEMSEC_REF CPOutput_t t_CP_Output;

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*
  cp_trajectory.c
*/
extern CP_t_Traj2MOTraceParallelism CP_t_Traj2MOTraceParallelismCheck(TraceID_t iTr);
extern void CP_v_TrajectoryInit( const CP_t_CourseData * pCourseData , boolean bUseRoadEstim , boolean bUseObjTraces , boolean bUseCamLaneMarker, boolean bUseNaviPath, CP_t_TrajectoryData  *pTrajData, CP_t_TraceTrajectory  *pTraceTrajectory );

extern void CP_v_PrepareTrajectoryData( CP_t_TrajectoryData  *pTrajData );
extern CP_t_TrajectoryData * CP_t_GetTrajectoryData(void);
extern float32 CP_f_GetCourseVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected);
extern void CP_v_InitPosSamples(SLATE_t_PosSamples *pSamples);

/*
  cp_main.c
*/
extern void CP_v_PreProcess(CPInputConst_t * pt_CPInputGlob);
extern void CP_v_Process(CPInputConst_t * pt_CPInputGlob, CPOutput_t * pt_CPOutputGlob);
extern void CP_v_SetOperationMode(SLATECompState_t const t_CPOpModeValue);

/*--- cp_si.c ---*/
#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
/*! BMW-specific external declaration of custom function used */
extern boolean CP_b_ACC_CheckObjForOvertake(ObjNumber_t iObj);
#endif /*SLATE_CFG_ENABLE_OVERTAKE_ASSIST*/

/* --- cp_fusion_trace.c-- */
extern CP_t_Trace2CurveParallelism CP_t_FusionTraceCalcTraceCircleParallelism(uint8 iTr, const GDBTrafoMatrix2D_t * MOT2CIR);
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
extern void CP_v_DetermineObjectLaneChange(TraceID_t iTrace, const GDBTrafoMatrix2D_t * MOT2CIR);
extern void CP_v_TraceCutOutDetection(TraceID_t iTrace, ObjNumber_t iObj);
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

#ifdef __cplusplus
};
#endif

/*! @endcond Doxygen_Suppress */

#endif
#endif
/** @} end defgroup */
