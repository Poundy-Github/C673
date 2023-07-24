/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp.h

DESCRIPTION:               Course Prediction Internal Header

AUTHOR:                    Gergely Ungvary

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */

#ifndef CP_H_INCLUDED
#define CP_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"
#include "cp_access_func.h"
#include "cp_par.h"

#if (FCT_CFG_COURSE_PREDICTION)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp
@{ */

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
/* Virtual adress for navi debug freeze in the device (to be moved to rte) */
#ifndef FCT_MEAS_ID_NAVI_CP_DEBUG
#define FCT_MEAS_ID_NAVI_CP_DEBUG 0x20270350
#endif
#endif  /* ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)) */

#ifdef FCT_SIMU
#ifndef CP_MOV_OBJ_TRACE_TRAJ_FUSION_VADDR
#define CP_MOV_OBJ_TRACE_TRAJ_FUSION_VADDR  0x2020D000u
#endif
#endif  /* FCT_SIMU */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#ifndef CP_MEAS_ID_TRACE_TRAJECTORY
#define CP_MEAS_ID_TRACE_TRAJECTORY  539369472u
#endif
#endif  /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

/*! @brief CP_TRACE_NUM_BINS */
#define CP_TRACE_NUM_BINS          CAL_MAX_NB_TRAJ_SAMPLES
/*! @brief CP_SAMPLE_RESOLUTION_X */
#define CP_SAMPLE_RESOLUTION_X     (CP_SAMPLEDIST_MAX / (float32)CP_TRACE_NUM_BINS)

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*! @brief       Total number of trace samples
    @general     Total number of trace samples given by [number of traces * number of sample point per trace]
    @conseq      @incp  Either the number of traces has increased or the number of sample points per trace has witnessed an increase
                 @decp  Either the number of traces has decreased or the number of sample points per trace has witnessed an decrease
    @attention   Any changes will have to checked for all functions using traces
    @typical     200   @unit No-unit     @min 0   @max 200   */
#define CP_NUM_TRACE_SAMPLES       (CAL_MAX_NB_TRAJ_SAMPLES * FIP_STATIC_TRACE_NO_OF_TRACES)
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
/*! @brief CP_KALMAN_POSAMPLES_NOISE_OFFSET */
#define CP_KALMAN_POSAMPLES_NOISE_OFFSET 0.75f

/*! Calculation of Position Samples based on ClothApprox must be called with an x-offset, in most cases this is 0 */
#define CP_XDIST_FIRST_SAMPLE_ZERO_OFFSET 0.0f
/*****************************************************************************
  TYPEDEFS (KOMPONENTENINTERN)
*****************************************************************************/

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief CP_t_SampleSlopQuality enum

    @general None

    @conseq None

    @attention None

    */
typedef enum
{
  CP_SSQ_INIT,
  CP_SSQ_LOW_QUALITY,
  CP_SSQ_HIGH_QUALITY
} CP_t_SampleSlopQuality;

/* ****************************************************************
    TYPEDEF STRUCT CP_t_Trace2CurveParallelism
    **************************************************************** */
/*! @brief CP_t_Trace2CurveParallelism structure

    @general CPRESTRUCTED: Renamed typedef struct MOTrace2CurveParallelism_t -> CP_t_Trace2CurveParallelism

    @conseq None

    @attention None

    */

/*! @brief CP_t_ClothApproxType */
typedef enum 
{
  CPClothApproxType_Automatic       = 0,
  CPClothApproxType_PolynomialOnly  = 1,
  CPClothApproxType_CircleOnly      = 2
} CP_t_ClothApproxType;

/*! @brief CP_t_NoiseModelLinear */
typedef struct
{
  float32 fNoiseOffset; /*!< fNoiseOffset */
  float32 fNoiseGradient;/*!< fNoiseGradient */
} CP_t_NoiseModelLinear;
#if defined (FIP_CFG_USE_EGO_TRACE)
#if (SWITCH_ON == FIP_CFG_USE_EGO_TRACE)
/*! Structure used to store ego trace additional data */
typedef struct CPEgoTraceAddData {
  uint8             uNumberOfPoints;    /*!< Number of trace points we have already seen */
  float32           fApproxFarDist;     /*!< Far distance till where poly approx valid */
  float32           fCurSqDist;         /*!< summed squared distance of the sample points to the approximation polynomial (the residual) */
  CAL_t_TracePolyL2   ApproxPoly;         /*!< Trace approximation polynomial */
} CPEgoTraceAddData_t;
#endif /* END IF (SWITCH_ON == FIP_CFG_USE_EGO_TRACE) */
#endif /* END IF defined (FIP_CFG_USE_EGO_TRACE) */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*! Structure used to store data which reflects the relationship of traces with road, VDY course and overall trace quality thereby */
typedef struct {
  CP_t_Trace2CurveParallelism  Trace_EGOPara[FIP_STATIC_TRACE_NO_OF_TRACES];
  uint8                       Trace_QualityValid[FIP_STATIC_TRACE_NO_OF_TRACES];
#if (FCT_CFG_ROAD_INPUT)
  CP_t_Trace2CurveParallelism  Trace_REPara[FIP_STATIC_TRACE_NO_OF_TRACES];
#endif /* END IF (FCT_CFG_ROAD_INPUT) */
}CP_t_InputSourceParams;
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

/*! Structure used to store position samples from different input sources */
typedef struct {
  SLATE_t_PosSamples EGO_PosSamples;    /*!< Ego motion trajectory samples, formerly global TPSIMU_EGO_PosSamples -> CPTrajFusionDebugInfo.EGO_PosSamples */
#if (FCT_CFG_ROAD_INPUT)
  SLATE_t_PosSamples RE_PosSamples;     /*!< Road estimation trajectory samples, formerly global TPSIMU_RE_PosSamples -> CPTrajFusionDebugInfo.RE_PosSamples */
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  SLATE_t_PosSamples TRACE_PosSamples;  /*!> Trace estimation trajectory samples */
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
  SLATE_t_PosSamples CLM_PosSamples;
#endif
} CP_t_TrajectoryPosSamples;

/*****************************************************************************
  KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/

 /*! CP_TRACE_QUAL_MASK_TRACE_VALID */
#define CP_TRACE_QUAL_MASK_TRACE_VALID    0x01
/*! CP_TRACE_QUAL_MASK_EGO_PARALLEL */
#define CP_TRACE_QUAL_MASK_EGO_PARALLEL   0x02
/*! CP_TRACE_QUAL_MASK_ROAD_PARALLEL */
#define CP_TRACE_QUAL_MASK_ROAD_PARALLEL  0x04

/*****************************************************************************
  VARIABLEN (KOMPONENTENINTERN)
*****************************************************************************/
 #ifdef FCT_SIMU

  /*! Typedef for debugging information for single trace */
  typedef struct CP_MOTraceFusionDebugInfo
  {
    uint8 QualityValid;     /*!< Quality valid flag, formerly array TPSIMU_Trace_QualityValid */
    boolean EgoValid;        /*!< Ego motion valid flag, formerly array TPSIMU_Trace_EgoValid */
    boolean RoadValid;       /*!< Road estimation valid flag, formerly array TPSIMU_Trace_RoadValid */
    struct CPTrFusSampleInfo
    {
      float32 fGradient;      /*!< Trace gradient, formerly array TPSIMU_fTraceGrad */
      float32 fdYdXMinStdDev; /*!< Minimal standard deviation of sample, formerly array TPSIMU_fdydxMinStdDev */
      /*float32 fdYdXMaxStdDev;*/ /*!< Maximal standard deviation of sample, formerly array TPSIMU_fdydxMaxStdDev @todo: Currenly unused, clarify if removal OK */
      CP_t_SampleSlopQuality  eQuality; /*!< Sample quality enum, formerly array TPSIMU_fTraceGradValid */
    } Samples[CAL_MAX_NB_TRAJ_SAMPLES]; /*!< Array of trace samples */
    struct CPTrParaInfo {
      float32 fDistMean;
      float32 fDistStdDev;
    } EgoPara, RoadPara;  /*!< Paralellism of trace with ego motion/road estimation */
    float32 fEgoErrAvg;     /*!< Average error between trace poly and driver intended curvature in 1 second timegap range */
  } CP_t_MOTraceFusionDebugInfo;
  
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  /*! Navi path fusion debug info */
  typedef struct CP_MONaviPathFusionDebugInfo
  {
    struct CPNaviPathFusIsSampleInfo
    {
      float32 fStdDev;
      float32 fXPos;
      float32 fYPos;
      float32 fGradient;
      float32 fDistLCStdDev;
    } Samples[CAL_MAX_NB_TRAJ_SAMPLES]; /*!< Array of navi path samples */
    struct CPNaviPathFusionInfo
    {
      float32 fDistGenStdDev;
      float32 fApproxC0StdDev;
      float32 fNaviPathToPolySumSqDistAvgStdDev;
      float32 fNaviPathEgoDiffStdDev;
      float32 fSumLengthNaviPathStdDev;
      float32 fIsHighway;
      float32 fDiffTrajNavi;
      float32 fDiffTrajNaviStd;
    }PathFusionInfo;
    struct CPNaviPathFusIsSituationInfo {
      boolean bAllowedNaviStreetTyp;
      boolean bValidPathLength;
      boolean bIsLaneChange;
      boolean bHighEgoCurve;
      boolean bNaviDataReliable;
      boolean bIsRoadworks;
      boolean bValidSpeedRange;
      boolean bIsNaviPathApproxPlausible;
      boolean bNaviDataQuality;
      boolean bIsSituation;      
    } IsSituation;
      float32 f_fusion_factor_YOffset;
      float32 f_fusion_factor_ErrEgoCurveToNavi;
      float32 f_fusion_factor_BranchProb;
  } CP_t_MONaviPathFusionDebugInfo;
#endif /*!< (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */

  typedef struct CPTrajFusionDebugInfo
  {
    SLATE_t_PosSamples FUSED_PosSamples;  /*!< Fused trajectory samples, formerly global TPSIMU_FUSED_PosSamples -> CPTrajFusionDebugInfo.FUSED_PosSamples */
    SLATE_t_PosSamples EGO_PosSamples;    /*!< Ego motion trajectory samples, formerly global TPSIMU_EGO_PosSamples -> CPTrajFusionDebugInfo.EGO_PosSamples */
    SLATE_t_PosSamples RE_PosSamples;     /*!< Road estimation trajectory samples, formerly global TPSIMU_RE_PosSamples -> CPTrajFusionDebugInfo.RE_PosSamples */
    SLATE_t_PosSamples TRACE_PosSamples;  /*!> Trace estimation trajectory samples */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
    SLATE_t_PosSamples CLM_PosSamples;    /*!< Camera lane trajectory samples, formerly global TPSIMU_CLM_Samples -> CPTrajFusionDebugInfo.CLM_PosSamples */
#endif /* CP_CFG_LANE_CHG_CAM_FUSION */

    sint32 iNumValidTraceGrad;         /*!< Number of valid traces for trace fusion, formerly global TPSIMU_numValidTraceGrad -> CP_TrajFusionDebugInfo.iNumValidTraceGrad */
    float32 fMSETrace;                  /*!< Mean squared error of trace samples with respect to trace trajectory */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
    CP_t_MOTraceFusionDebugInfo TraceFusionDebug[FIP_STATIC_TRACE_NO_OF_TRACES];  /*!< Trace fusion debug info, formerly global TPSIMU_TraceFusionDebug -> CP_TrajFusionDebugInfo.TraceFusionDebug */
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
    CP_t_MONaviPathFusionDebugInfo NaviPathFusionDebug;    /*!< Navi path fusion debug info */
#endif
  } CP_t_TrajFusionDebugInfo;

  /*! Trajectory fusion debug information */
  extern CP_t_TrajFusionDebugInfo CP_TrajFusionDebugInfo;

 #endif /*!< FCT_SIMU */

 /*! Additional data stored for traces (one entry per trace) */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
 extern MEMSEC_REF CP_t_TraceAddData CP_TraceAdd[CP_NUM_TRACES];
#endif /* FCT_CFG_OBJECT_TRACE_PREPROCESSSING */

 /*! External declaration of pointer to CP output structure for usage in this module */
 extern MEMSEC_REF CPOutput_t * pt_CPOutput;

 /*! External declaration of pointer to CP input structure for usage in this module */
 extern MEMSEC_REF CPInputConst_t * pt_CPInput;


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*--- cp_main.c ---*/
extern void CP_v_MeasCallback(void);
extern void CP_v_InitEveryCycle(void); /*!< Restructuring- Remove from cp.h if not called in cp_si.c (Split from EBA) */
extern void CP_v_InitPersistentData(void);
extern void CP_v_SetInput(void); /*!< Restructuring- Remove from cp.h if not called in cp_si.c (Split from EBA) */

/* cp_trajectory.c */
extern void CP_v_CopyCourse2Meas(const CP_t_CourseData * pCourseData , CP_t_UnfiltCourseMeas *pMeasUnFiltCourse);
extern void CP_v_CopyTraj2Meas(const CP_t_TrajectoryData * pTrajectoryData , CP_t_TrajectoryMeas *pMeasTrajectory);
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
extern void CP_v_CopyTraceTraj2Meas(const CP_t_TraceTrajectory *pTraceTrajectory , CP_t_TraceTrajectory *pMeasTraceTrajectory);
#endif
extern void CP_v_GetCourseDataEgo( CP_t_CourseData *pCourseData , const boolean bUseSlipAngle/*, const VehDyn_t * pInputSignals */);
extern void CP_v_CalculateTrajectory(const CP_t_TrajectoryInputParameter * pTrajInputPara);
extern float32 CP_f_GetRoadVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected);
#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
extern float32 CP_f_GetNaviVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected);
#endif
extern float32 CP_f_GetPlausibleC1AtSpeed(const fVelocity_t EgoSpeedCorrected);
/* CPRESTRUCTED: Added function declarations for custom functions that are used by CD and SI */
extern float32 CP_f_GetCurvature( CP_t_CourseData const * const pTrajectory, const float32 fXPosition );

extern void CP_v_SamplePosClothApprox(const CP_t_CourseData *pCPCourseData, const CP_t_ClothApproxType CPClothApproxType, const float32 fSampleDistMax, SLATE_t_PosSamples *pCPPosSamples, float32 fXDistFirstSample);

extern void CP_v_MoveSamplesFromCoGToSensor( SLATE_t_PosSamples *pCPPosSamples );
extern void CP_v_LimitSamplesXDist( const float32 fXDistMax, SLATE_t_PosSamples *pCPPosSamples );
#if (FCT_CFG_ROAD_INPUT)
extern CP_t_CourseData CP_t_GetRoadEstimationAsCourseData(void);
#endif /* END IF (FCT_CFG_ROAD_INPUT) */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
extern CP_t_CourseData CP_t_GetTraceEstimationAsCourseData(const CP_t_TraceTrajectory * pTraceTrajectory);
extern void CP_v_FusionEvalTraceSamples(const CP_t_TraceTrajectory * pTraceTrajectory);
#endif

#ifdef FCT_SIMU
void CP_v_CallFCTFreezeforCPFusion(CP_t_TrajFusionDebugInfo * p_CP_TrajFusionDebugInfo);
#endif


/* cp_fusion_trace.c */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
extern void CP_v_FusionTracesEvalTraces(CP_t_InputSourceParams           * pTrace_Params);

extern void CP_v_CalculateCombinedTraceTrajectory(CP_t_TraceTrajectory * pTraceTrajectory);
extern void CP_v_CalculateTraceSamples(const CP_t_TraceTrajectory * pTraceTrajectory, SLATE_t_PosSamples * pTRACE_PosSamples);
extern CP_t_TraceTrajectory     CP_TraceTrajectory;
#endif

#if (FCT_CFG_ROAD_INPUT)
/* cp_fusion_road.c */
extern void CP_v_CalculateRoadSamples(SLATE_t_PosSamples * pRE_PosSamples);
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
extern void CP_v_FusionEvalRoad(SLATE_t_PosSamples * pEGO_PosSamples, SLATE_t_PosSamples * pRE_PosSamples, CP_t_InputSourceParams * pTrace_Params);
#else
extern void CP_v_FusionEvalRoad(SLATE_t_PosSamples * pEGO_PosSamples, SLATE_t_PosSamples * pRE_PosSamples);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

/* cp_fusion_navi.c */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
extern void CP_v_FusionNaviMain(void);
extern void CP_v_NaviSetMeasData(CP_t_NaviDebugMeasInfo * p_NaviDebugMeasFreeze);
#endif

/* cp_fusion_cam.c */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
  extern void CP_v_FusionCamMain(SLATE_t_PosSamples * pCLM_PosSamples, float32 fXDistFirstSample);
#endif
#ifdef __cplusplus
};
#endif

#endif
/// @}
#endif

