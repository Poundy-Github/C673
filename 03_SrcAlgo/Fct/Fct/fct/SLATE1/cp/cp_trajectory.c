/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_trajectory.c

DESCRIPTION:               Course prediction trajectory module

AUTHOR:                    Norman Apel

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.39 $

LEGACY VERSION:            Revision: 2.1.1.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_COURSE_PREDICTION)
#include "cp_kalman.h"
#ifdef FCT_SIMU
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#endif  /* FCT_SIMU */ 
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_trajectory Trajectory
@ingroup cp
@brief          Responsible for course computation and trajectory planning. \n\n

@description    It uses information from road, traces, NAVI,camera and VDY Kinematics to generate the ACC Trajectory.
@{
*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/
//PRQA S 0791 MACRO_IDENTIFIER_LENGTH
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Macro identifier does not differ from other macro identifier within the specified number of significant characters,Does not affect functionality*/

#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)
#endif

//#if defined(FCT_SIMU)
//#ifndef SI_MEAS_ID_SI_TRAJECTORY
//#define SI_MEAS_ID_SI_TRAJECTORY    0x20260900
//#endif
//#ifndef SI_MEAS_ID_SI_COURSE_DATA
//#define SI_MEAS_ID_SI_COURSE_DATA   0x20260B00
//#endif
//#endif
/*! @brief Minimum ego velocitie for variance calculation */
#define CP_TRAJ_VAR_EGO_VEL_MIN (1.0f)
/*! @brief Maximum time for velocities close to zero */
#define CP_TRAJ_VAR_TIMEGAP_MAX (200.0f)
/*! @brief Maximum time for velocities close to zero */
#define CP_TRAJ_VAR_OFFSET (0.00003f)
/*! @brief Time-gap limit for the approximation of the road, trace or VDY variance by the first segment */
#define CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_LOW  (1.0f)
/*! @brief Time-gap limit for the approximation of the road, trace or VDY variance by the second segment */
#define CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_MID  (4.0f)
/*! @brief Coefficient for the approximation of the VDY course variance by a power function for first two segments */
#define CP_VDY_COURSE_VAR_COEFF_LOW     (0.02f)
/*! @brief Maximum ego velocity for country road specific approximation of the trace trajectory course variance */
#define CP_TRACE_TRAJ_VEGO_MAX_COUNTRY              (120.f/C_KMH_MS)
/*! @brief Maximum curvature for country road specific approximation of the trace trajectory course variance */
#define CP_TRACE_TRAJ_CURVE_MAX_HIGHWAY             (1.f/600.f)
/*! @brief Coefficient for the approximation of the trace trajectory course variance on highways */
#define CP_TRACE_TRAJ_COURSE_VAR_COEFF_HIGHWAY      (0.1f)
/*! @brief Power for the approximation of the trace trajectory course variance on highways */
#define CP_TRACE_TRAJ_COURSE_VAR_POW_HIGHWAY        (3.3f)
/*! @brief Coefficient for the approximation of the trace trajectory course variance for first two segments on country roads */
#define CP_TRACE_TRAJ_COURSE_VAR_COEFF_COUNTRY_LOW  (0.045f)
/*! @brief Coefficient for the approximation of the trace trajectory course variance for third segment on country roads */
#define CP_TRACE_TRAJ_COURSE_VAR_COEFF_COUNTRY_HIGH (0.0056f)
/*! @brief Coefficient for the approximation of the road course variance by a power function for first two segments */
#define CP_ROAD_COURSE_VAR_COEFF_LOW                (0.1f)
/*! @brief Coefficient for the approximation of the road course variance by a power function for third segment */
#define CP_ROAD_COURSE_VAR_COEFF_HIGH               (0.025f)
/*! @brief Coefficient for the approximation of the navi course variance by a power function for time gap under 1 sec. */
#define CP_NAVI_COURSE_VAR_COEFF_LOW             0.09f
/*! @brief Coefficient for the approximation of the navi course variance by a power function for time gap from 1 sec. to 4 sec */
#define CP_NAVI_COURSE_VAR_COEFF_MED             0.09f
/*! @brief Coefficient for the approximation of the navi course variance by a power function for time gap over 4 sec. */
#define CP_NAVI_COURSE_VAR_COEFF_HIGH            0.03f

/*! @brief Coefficient for the approximation of the camera course variance by a power function for time gap under 1 sec. */
#define CP_CAM_COURSE_VAR_COEFF_LOW             (0.05f)
/*! @brief Coefficient for the approximation of the camera course variance by a power function for time gap over 4 sec. */
#define CP_CAM_COURSE_VAR_COEFF_HIGH            (0.0016f)

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

#ifdef FCT_SIMU

  /*! Trajectory fusion debug information */
  CP_t_TrajFusionDebugInfo CP_TrajFusionDebugInfo;

  static const MEASInfo_t CP_TrajFusionDebugMeasInfo =
  {
    CP_MOV_OBJ_TRACE_TRAJ_FUSION_VADDR, /* .VirtualAddress */
    sizeof(CP_TrajFusionDebugInfo),      /* .Length */
    FCT_MEAS_FUNC_ID,                   /* .FuncID */
    FCT_MEAS_FUNC_CHAN_ID               /* .FuncChannelID */
  };

#endif

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  /*! Trace Trajectory information */
CP_t_TraceTrajectory     CP_TraceTrajectory;

#endif

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/
/*! @brief CP_RE_FUS_SMOOTHING_MAX */
#define CP_RE_FUS_SMOOTHING_MAX           (0.45f)
/*! @brief CP_RE_FUS_SMOOTHING_INC */
#define CP_RE_FUS_SMOOTHING_INC           (0.03f)
/*! @brief RE_FUS_SMOOTHING_REDUCTION_FAC */
#define CP_RE_FUS_SMOOTHING_REDUCTION_FAC (2.f)
  /*! @brief CP_TRACEWEIGHT_CURVE_THRESH */
#define CP_TRACEWEIGHT_CURVE_THRESH       (0.0001F)
  /*! @brief CP_NUM_TRAJ_SAMPLES_AT_START */
#define CP_NUM_TRAJ_SAMPLES_AT_START      (6u)

#define CP_MAX_ANGLE_NEARRANGE_FOV    (25.f)
#define CP_MAX_DIST_NEAR_RANGE        (70.f)
#define CP_MIN_NUM_SAMPLES_VDY        (5u)
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

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*! Structure describing a moving object's parallelism to our course */
typedef struct
{
  boolean   relevantTrace;
  float32   fEGODistMean;
  float32   fEGODistStdDev;
  float32   fREDistMean;
  float32   fREDistStdDev;
} CP_t_RoadAndEgo2MOTraceParallelism;// PRQA S 3205
   /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Its reviewed and the usage of this struct is inside the commented code, that may be used later */
#endif

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/
#if (FCT_CFG_ROAD_INPUT)
  /* fFacFusionVDYROAD is used to get a smooth transition from VDY-only course to the fused VDY-ROAD trajectory.
  Previously, the trajectory switched instantaneously between the trajectories */
  SET_MEMSEC_VAR(fFacFusionVDYROAD)
  static float32 fFacFusionVDYROAD = CP_RE_FUS_SMOOTHING_MAX;//PRQA S 3218
  /*date: 2018-07-31, reviewer: Midhun Easo Daniel, reason: static local for saving data across function calls*/
#endif
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief CP_INIT_TRAJ_NOISE_C0 */
#define CP_INIT_TRAJ_NOISE_C0         1.0e-10f
/*! @brief CP_INIT_TRAJ_NOISE_C1 */
#define CP_INIT_TRAJ_NOISE_C1         1.0e-11f

/*! first ramp for vehicle velocity / RE distance criterion */

SET_MEMSEC_CONST(CP_REPlausibilityHighway)
static const GDBLFunction_t CP_REPlausibilityHighway = {// PRQA S 3218, 2200
 /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
  CP_PLAUSIBILITY_HIGHWAY_LOWSPEED_A,   /* Ausgangswert A1 */
  CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED_A,   /* Ausgangswert A2 */
  /* Steigung der Anpassungsgerade:        (A2-A1)/(E2-E1) */
  (CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED_A-CP_PLAUSIBILITY_HIGHWAY_LOWSPEED_A) / ( CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED - CP_PLAUSIBILITY_HIGHWAY_LOWSPEED ),
  /* Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 */
  CP_PLAUSIBILITY_HIGHWAY_LOWSPEED_A - (((CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED_A-CP_PLAUSIBILITY_HIGHWAY_LOWSPEED_A) 
                                    / ( CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED - CP_PLAUSIBILITY_HIGHWAY_LOWSPEED )) * CP_PLAUSIBILITY_HIGHWAY_LOWSPEED)
};

/* CP_CourseGradUpdateSTD used ONLY in CP_f_GetCourseGradUpdateSTDC1AtSpeed
SET_MEMSEC_CONST(CP_CourseGradUpdateSTD)
static const GDBLFunction_t CP_CourseGradUpdateSTD = {// PRQA S 3218
   date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls 

  CP_COURSE_GRADUPDATE_STD_LOWSPEED_A,    Ausgangswert A1 
  CP_COURSE_GRADUPDATE_STD_HIGHSPEED_A,    Ausgangswert A2 
   Steigung der Anpassungsgerade:        (A2-A1)/(E2-E1) 
  (CP_COURSE_GRADUPDATE_STD_HIGHSPEED_A-CP_COURSE_GRADUPDATE_STD_LOWSPEED_A) / ( CP_COURSE_GRADUPDATE_STD_HIGHSPEED - CP_COURSE_GRADUPDATE_STD_LOWSPEED ),
   Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 
  CP_COURSE_GRADUPDATE_STD_LOWSPEED_A - (((CP_COURSE_GRADUPDATE_STD_HIGHSPEED_A-CP_COURSE_GRADUPDATE_STD_LOWSPEED_A) 
                                     / ( CP_COURSE_GRADUPDATE_STD_HIGHSPEED - CP_COURSE_GRADUPDATE_STD_LOWSPEED )) * CP_COURSE_GRADUPDATE_STD_LOWSPEED)
};
*/
/* PRQA L:MACRO_IDENTIFIER_LENGTH */
/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

/* function prototype declarations */
static void CP_v_TrajectoryReset( const CP_t_CourseData * pCourseData , CP_t_TrajectoryData * pTrajData, CP_t_TraceTrajectory  *pTraceTrajectory );
static void CP_v_TrajKalmanSetInitValues(const CP_t_CourseData * pCourseData, const CP_t_TrajectoryData * pTrajData);
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
static void CP_v_TraceTrajKalmanSetInitValues(const CP_t_TrajectoryData * pTrajData, const CP_t_TraceTrajectory * pTraceTrajectory );
#endif
static Vector2_f32_t CP_t_ClothApproxByPolynom(const float32 fC0, const float32 fC1, const float32 fYawAngle, const float32 fDistOnCloth);
static Vector2_f32_t CP_t_ClothApproxByCircle(const float32 fC0, const float32 fDistOnCloth);
#if (FCT_CFG_ROAD_INPUT || FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
static void CP_v_FusePosSamples(SLATE_t_PosSamples * const Samples, const SLATE_t_PosSamples * const MeasSamples);
#endif /* FCT_CFG_ROAD_INPUT || FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
static void CP_v_CalculateVDYSamples(SLATE_t_PosSamples * pEGO_PosSamples);
static float32 CP_f_GetTraceTrajVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected);
#if (CP_CFG_LANE_CHG_CAM_FUSION)
static float32 CP_f_GetCamTrajVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected);
#endif /* END IF (CP_CFG_LANE_CHG_CAM_FUSION) */
static void CP_v_TrajSampleFusionMain(CP_t_TrajectoryPosSamples * pTrajectoryPosSamples);
/* Currently unused
static float32 CP_f_GetCourseGradUpdateSTDC1AtSpeed(const fVelocity_t EgoSpeedCorrected);
static void CP_v_SampleGradFromCourse(const CP_t_CourseData * pCourseData , CAL_t_GradSamples *pSamples);
static void CP_v_InitGradSamples(CAL_t_GradSamples *pSamples);
*/
// PRQA S 7013 STTLN_EXCEEDED
/* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Number of lines exceeded per file, not safety critical */

/*************************************************************************************************************************
  Functionname:    CP_v_InitPosSamples                                                                                 */ /*!

  @brief           Initialize the Trajectory Sample Structure

  @description     Initialize the position samples of trajectory structure.It contains the following information
                   x- position of the tajectory sample.
                   y - position of the trajectory sample.
                   var- variance information of trajectory samples.
                   number of samples.
  
                   @startuml
                   Partition CP_v_InitPosSamples{
                   Start
                       : Initialize x and y position, variance information of trajectory sample;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      pSamples : position samples of trajectory structure SLATE_t_PosSamples defined in cp_ext.h
                      fx : x-position of tarjectory sample                                           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fy : y-position of tarjectory sample                                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fVar : variance information of trajectory samples                              [Full range of float32  >= 0.F]
                      nb_samples : Number of samples                                                 [0u ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/16/2016

  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_InitPosSamples( SLATE_t_PosSamples *pSamples )
{
  uint32 i;

  for(i=0u;i<CAL_MAX_NB_TRAJ_SAMPLES;i++) 
  {
    pSamples->fx[i] = 0.0F;
    pSamples->fy[i] = 0.0F;
    pSamples->fVar[i] = 0.0F;
  }
  pSamples->nb_samples = 0u;
}

/*************************************************************************************************************************
  Functionname:    CP_v_InitGradSamples                                                                                */ /*!

  @brief           Initialize the Gradient Sample Struct

  @description     Initialize the Gradient Sample Struct.It contains the following information
                   x position of the sample
                   gradient at x position
                   standard deviation of the samples
                   boolean to check if sample is valid.

                   @startuml
                   Partition CP_v_InitGradSamples{
                   Start
                   : Initialize x position, gradient at x-position, Standard deviation of gradient of\n x-position of trajectory sample;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      pSamples : position of the gradient sample struct CAL_t_GradSamples defined in cp_ext.h.
                      fx : x-position of tarjectory sample                                                [-5 * RW_FCT_MAX to +5 * RW_FCT_MAX] m
                      fdydx : gradient at x-position of trajectory sample                                 [Full range of float32  >= 0.F] 
                      fdydxMinStdDev : Standard deviation of gradient at x-position of trajectory sample  [Full range of float32  >= 0.F]
                      valid : Boolean to decide whether sample is valid or not                            [TRUE,FALSE]

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         2/16/2016

  @todo            Currently unused, check and delete the function

  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
/*
static void CP_v_InitGradSamples( CAL_t_GradSamples *pSamples )
{
  uint32 i;

  for(i=0u;i<CAL_MAX_NB_TRAJ_SAMPLES;i++) 
  {
    pSamples->fx[i]    = 0.0F;
    pSamples->fdydx[i] = 0.0F;
    pSamples->fdydxMinStdDev[i] = 0.0F;
    pSamples->valid[i] = FALSE;
  }  
}
*/
/*************************************************************************************************************************
  Functionname:    CP_v_TrajectoryInit                                                                                 */ /*!

  @brief           Initialize the Trajectory Kalman Filter

  @description     This function sets the fusion configuration for the trajectory fusion.
                   The fusion of ego course is mandatory and fusion of trace and road data is based on situation.

                   @startuml
                   Partition CP_v_TrajectoryInit{
                   Start
                   : ROAD_ESTIMATION can be turned of;
                   : OBJECT_TRACES can be turned of;
                   : Set the number of states;
                   : Kalman Matrices;
                   : Internal Matrixes;
                   : Reset with Course C0 and TrajC1 with 0;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pCourseData : pointer to course data structure CP_t_CourseData defined in cp_ext.h
  @param[in]       bUseRoadEstim :     boolean to fuse if road estimation to trajectory                      [TRUE,FALSE]
  @param[in]       bUseObjTraces :     boolean to fuse if object traces to trajectory                        [TRUE,FALSE]
  @param[in]       bUseCamLaneMarker : boolean to fuse if camera lane to trajectory                          [TRUE,FALSE]
  @param[in]       bUseNaviPath :      boolean to fuse if navidata to trajectory                             [TRUE,FALSE]
  @param[in,out]   pTrajData : pointer to Trajectory data structure CP_t_TrajectoryData defined in cp_ext.h
                      Config.UseRoadEstim : Bit indicating if road estimation shall be used for fusion       [TRUE,FALSE]
                      Config.UseObjTraces : Bit indicating if object traces shall be used for fusion         [TRUE,FALSE]
                      Config.UseCamLane : Bit indicating if camera lane shall be used for trajectory fusion  [TRUE,FALSE]
                      Config.UseNaviPath : Bit indicating if Navi path shall be used for trajectory fusion   [TRUE,FALSE]
                      State.EgoCourseOnly : Bit indicating that only ego course used for trajectory          [TRUE,FALSE]
                      KafiEst.uiNbOfStates : Number of States                                                [0u    255u]
  @param[in]          KafiEst.AMat : Full matrix, transition matrix                                          [float32 as defined in cml_kafi.h]
                      KafiEst.QMat : Diagonal matrix, process noise covariance                               [float32 as defined in cml_kafi.h]
                      KafiEst.XVec : Vector, estimated state vector                                          [float32 as defined in cml_kafi.h]
                      KafiEst.UDMat : UDUT factorized matrix, covariance                                     [float32 as defined in cml_kafi.h]
                      KafiEst.XsVec : Vector, predicted state vector                                         [float32 as defined in cml_kafi.h]
                      KafiEst.PDiagMat : Diagonal matrix, covariance                                         [float32 as defined in cml_kafi.h]
                      KafiData.AMatrix : Full matrix, transition matrix                                      [float32 as defined in cp_ext.h]
                      KafiData.QMatrix : Diagonal matrix, process noise covariance                           [float32 as defined in cp_ext.h]
                      KafiData.XVector : Vector, estimated state vector                                      [float32 as defined in cp_ext.h]
                      KafiData.UDMatrix : UDUT factorized matrix, covariance                                 [float32 as defined in cp_ext.h]
                      KafiData.XsVector : Vector, predicted state vector                                     [float32 as defined in cp_ext.h]
                      KafiData.PDiagMatrix : Diagonal matrix                                                 [float32 as defined in cp_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CP_CFG_LANE_CHG_CAM_FUSION        : Configuration switch to enable support for camera lane fusion features when changing lanes
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING      : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   CP_CFG_TRACE_TRAJ_KALMAN_FILTER       : Switch to enable Kalman filtering after PSO
  @c_switch_full   FCT_CFG_COURSE_PREDICTION         : Switch to configure FCT support for CP sub-component
                   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         2/16/2016

  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_TrajectoryInit( const CP_t_CourseData * pCourseData , boolean bUseRoadEstim , 
                      boolean bUseObjTraces , boolean bUseCamLaneMarker, boolean bUseNaviPath, 
                      CP_t_TrajectoryData  *pTrajData, CP_t_TraceTrajectory  *pTraceTrajectory)
{
  /* Set fusion configuration of Trajectory*/

  /*ROAD_ESTIMATION can be turned of*/
  if(bUseRoadEstim != FALSE)
  {
    pTrajData->Config.UseRoadEstim  = TRUE;
  }
  else
  {
    pTrajData->Config.UseRoadEstim  = FALSE;
  }

  /*OBJECT_TRACES can be turned of*/
  if(bUseObjTraces != FALSE)
  {
    pTrajData->Config.UseObjTraces  = TRUE;
  }
  else
  {
    pTrajData->Config.UseObjTraces  = FALSE;
  }

#if (CP_CFG_LANE_CHG_CAM_FUSION)
  pTrajData->Config.UseCamLane = bUseCamLaneMarker;
#endif

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  pTrajData->Config.UseNaviPath = bUseNaviPath;
#endif

  /* reset State */
  /*EGO_COURSE is mandatory
    if only ego course is used fusion is bypassed 
    and distance is calculated in a different manner */
  if( (bUseRoadEstim == FALSE) && (bUseObjTraces == FALSE) && (bUseNaviPath == FALSE))
  {
    pTrajData->State.EgoCourseOnly = TRUE;
  }
  else
  {
    pTrajData->State.EgoCourseOnly = FALSE;
  }

  /* Set the number of states */
  pTrajData->KafiEst.uiNbOfStates = CP_NB_TRAJ_STATE;
  
  /* Kalman Matrices */
  GDBKalmanCreateMat(&pTrajData->KafiEst.AMat,     pTrajData->KafiData.AMatrix,     MATTYPE_FULL,             CP_NB_TRAJ_STATE,    CP_NB_TRAJ_STATE   );
  GDBKalmanCreateMat(&pTrajData->KafiEst.QMat,     pTrajData->KafiData.QMatrix,     MATTYPE_DIAGONAL,         CP_NB_TRAJ_STATE,    CP_NB_TRAJ_STATE   );
  GDBKalmanCreateMat(&pTrajData->KafiEst.XVec,     pTrajData->KafiData.XVector,     MATTYPE_VECTOR,           CP_NB_TRAJ_STATE,    (uint8)1   );

  /* Internal Matrixes */
  GDBKalmanCreateMat(&pTrajData->KafiEst.UDMat,    pTrajData->KafiData.UDMatrix,    MATTYPE_UPPERTRIANGULAR,  CP_NB_TRAJ_STATE,    CP_NB_TRAJ_STATE   );
  GDBKalmanCreateMat(&pTrajData->KafiEst.XsVec,    pTrajData->KafiData.XsVector,    MATTYPE_VECTOR,           CP_NB_TRAJ_STATE,    (uint8)1   );
  GDBKalmanCreateMat(&pTrajData->KafiEst.PDiagMat, pTrajData->KafiData.PDiagMatrix, MATTYPE_DIAGONAL,         CP_NB_TRAJ_STATE,    CP_NB_TRAJ_STATE   );

#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
  /* Trace Trajectory Kalaman filter */
  /* Set the number of states */
  pTraceTrajectory->KafiTraceEst.uiNbOfStates = CP_NB_TRACE_TRAJ_STATE;
    /* Kalman Matrices */
  GDBKalmanCreateMat(&pTraceTrajectory->KafiTraceEst.AMat,     pTraceTrajectory->KafiTraceData.AMatrix,     MATTYPE_FULL,             CP_NB_TRACE_TRAJ_STATE,    CP_NB_TRACE_TRAJ_STATE   );
  GDBKalmanCreateMat(&pTraceTrajectory->KafiTraceEst.QMat,     pTraceTrajectory->KafiTraceData.QMatrix,     MATTYPE_DIAGONAL,         CP_NB_TRACE_TRAJ_STATE,    CP_NB_TRACE_TRAJ_STATE   );
  GDBKalmanCreateMat(&pTraceTrajectory->KafiTraceEst.XVec,     pTraceTrajectory->KafiTraceData.XVector,     MATTYPE_VECTOR,           CP_NB_TRACE_TRAJ_STATE,    (uint8)1   );

  /* Internal Matrixes */
  GDBKalmanCreateMat(&pTraceTrajectory->KafiTraceEst.UDMat,    pTraceTrajectory->KafiTraceData.UDMatrix,    MATTYPE_UPPERTRIANGULAR,  CP_NB_TRACE_TRAJ_STATE,    CP_NB_TRACE_TRAJ_STATE   );
  GDBKalmanCreateMat(&pTraceTrajectory->KafiTraceEst.XsVec,    pTraceTrajectory->KafiTraceData.XsVector,    MATTYPE_VECTOR,           CP_NB_TRACE_TRAJ_STATE,    (uint8)1   );
  GDBKalmanCreateMat(&pTraceTrajectory->KafiTraceEst.PDiagMat, pTraceTrajectory->KafiTraceData.PDiagMatrix, MATTYPE_DIAGONAL,         CP_NB_TRACE_TRAJ_STATE,    CP_NB_TRACE_TRAJ_STATE   );
#endif
  /* Reset with Course C0 and TrajC1 with 0*/
  CP_v_TrajectoryReset( pCourseData , pTrajData, pTraceTrajectory );

#if (!CP_CFG_LANE_CHG_CAM_FUSION)
  _PARAM_UNUSED(bUseCamLaneMarker);
#endif

#if !((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
  _PARAM_UNUSED(bUseNaviPath);
#endif

}

/*************************************************************************************************************************
  Functionname:    CP_v_TrajectoryReset                                                                                */ /*!

  @brief           Initialize the Trajectory Kalman Filter

  @description     This function initializes the trajectory data of the current cycle,last cycle and it resets the state bits.

                   @startuml
                   Partition CP_v_TrajectoryReset{
                   Start
                   : Initialize TrajAngle with Course Slip Angle;
                   : Initialize Old State with actual VDY State;
                   : Reset state bits;
                   : Initialize TrajC0 with Course C0 and TrajC1 with 0;
                   End
                   }
                   @enduml

  @return          static void

  @param[in]       pCourseData : pointer to course data structure CP_t_CourseData defined in cp_ext.h
                      fCurve : Radius of the curve provided by the VDY trajectory                         [-1.f ... +1.f]m^-1
                      SideSlipAngle : Sideslip angle of the curve provided by the VDY trajectory          [-PI ... +PI] rad
  @param[out]      pTrajData : pointer to Trajectory data structure CP_t_TrajectoryData defined in cp_ext.h
                      Current.fTrajAngle : Trajectory angle of current cycle                                                                   [-PI ... +PI] rad
                      Current.fTrajC0 : Trajectory clothoid parameter of current cycle                                                         [-1.f ... +1.f]m^-1
                      Current.fTrajC1 : Trajectory clothoid parameter of current cycle                                                         [-1.f ... +1.f]m^-2
                      LastCycle.fTrajC0 : Trajectory clothoid parameter of last cycle                                                          [-1.f ... +1.f]m^-1
                      LastCycle.fTrajC1 : Trajectory clothoid parameter of last cycle                                                          [-1.f ... +1.f]m^-2
                      LastCycle.fTrajAngle : Trajectory angle of last cycle                                                                    [-PI ... +PI] rad
                      State.EgoCourseOnly : Bit indicating that only ego course used for trajectory                                            [TRUE,FALSE]
                      State.FusionTraces : Bit indicating that Traces are used for trajectory fusion                                           [TRUE,FALSE]
                      State.FusionRoadstimation : Bit indicating that RE is used for trajectory fusion                                         [TRUE,FALSE]
                      State.FusionHystLRoadRangeConf : Bit indicating that features from left side of road estimation fulfill fusion criteria  [TRUE,FALSE]
                      State.FusionHystRRoadRangeConf : Bit indicating that features from right side of road estimation fulfill fusion criteria [TRUE,FALSE]
                      State.FusionTraceHystEgoSpeed : Bit indicating that ego speed is sufficient for Traces fusion                            [TRUE,FALSE]
                      State.FusionHystEgoSpeed : Bit indicating that ego speed fusion criteria is fulfilled                                    [TRUE,FALSE]
                      State.FusionHystEgoRadius : Bit indicating that ego radius fusion criteria is fulfilled                                  [TRUE,FALSE]
                      State.FusTraceCrit : Bit set when if CPMOTraceFusionCriterion returns TRUE                                               [TRUE,FALSE]
                      State.FusionPlaus : Bit to non-zero if CPFusionPlausibilityCheck returns TRUE                                            [TRUE,FALSE]
                      State.CamLaneQualityHigh : Bit indicating if camera lane foresight/quality criteria met                                  [TRUE,FALSE]
                      State.CamLaneFusion : Bit when camera lane fusion is active                                                              [TRUE,FALSE]
                      State.NaviPathFusion : Bit when navi path fusion is active                                                               [TRUE,FALSE]
                      fDistXUnplausibleSCurve : Longitudinal distance at which an unplausible 
                                                s-curve has been detected for the road-trajectory                                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      fRoadEstFusRange : Range in longitudinal direction up to which the Road trajectory 
                                         is used for the fusion for the ACC trajectory                                                         [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      fMovObjFusRange : Moving object Fusion Range                                                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      fMSETrace : Mean Squared Error of Trace                                                                                  [0...CP_MAX_TRACE_MSE]        
                      bTraceFusionActiveLastCycle : Whether trace fusion is active or not                                                      [TRUE,FALSE]
                      fCamLaneFusionTimer : Down counting camera lane fusion timer                                                             [Full range of float32  >= 0.F]
                      fEgo2CamDistX : Ego curve to camera lane blending X distance                                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fBaseY : Cam lane fusion Y displacement base                                                                             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fFilteredDIC : Cam lane fusion Y displacement base                                                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   CP_CFG_LANE_CHG_CAM_FUSION : Switch to fuse camera data to predict the trajectory.
  @c_switch_part   CP_CFG_TRACE_TRAJ_KALMAN_FILTER: Switch to enable Kalman filtering after PSO
  @c_switch_full   FCT_CFG_COURSE_PREDICTION  : Switch to configure FCT support for CP sub-component
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/16/2016


  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CP_v_TrajectoryReset( const CP_t_CourseData * pCourseData , CP_t_TrajectoryData * pTrajData, CP_t_TraceTrajectory  *pTraceTrajectory )
{
  /* Init TrajAngle with Course Slip Angle */
  pTrajData->Current.fTrajAngle       = pCourseData->SideSlipAngle;
  /* Init Old State with actual VDY State */
  pTrajData->Current.fTrajC0          = pCourseData->fCurve;
  pTrajData->Current.fTrajC1          = 0.0F;
  pTrajData->LastCycle.fTrajC0        = pCourseData->fCurve;
  pTrajData->LastCycle.fTrajC1        = 0.0F;
  pTrajData->LastCycle.fTrajAngle     = pCourseData->SideSlipAngle;
  /* Reset state bits */
  pTrajData->State.EgoCourseOnly            = TRUE;
  pTrajData->State.FusionTraces             = FALSE;
  pTrajData->State.FusionRoadstimation      = FALSE;
  pTrajData->State.FusionHystLRoadRangeConf = FALSE;
  pTrajData->State.FusionHystRRoadRangeConf = FALSE;
  pTrajData->State.FusionTraceHystEgoSpeed  = FALSE;
  pTrajData->State.FusionHystEgoSpeed       = FALSE;
  pTrajData->State.FusionHystEgoRadius      = FALSE;
  pTrajData->State.FusTraceCrit             = FALSE;
  pTrajData->State.FusionPlaus              = FALSE;
  pTrajData->State.CamLaneQualityHigh       = FALSE;
  pTrajData->State.CamLaneFusion            = FALSE;
  pTrajData->State.NaviPathFusion           = FALSE;

  /* Init UnplausibleSCurve Dist with 0 */
  pTrajData->fDistXUnplausibleSCurve  = 0.0F;
  pTrajData->fRoadEstFusRange         = 0.0F;
  pTrajData->fMovObjFusRange          = 0.0F;
  pTrajData->fMSETrace                = 0.0F;
  pTrajData->bTraceFusionActiveLastCycle = FALSE;

#if (CP_CFG_LANE_CHG_CAM_FUSION)
  pTrajData->fCamLaneFusionTimer      = 0.0F;
  pTrajData->fEgo2CamDistX            = 0.0F;
  pTrajData->fBaseY                   = 0.0F;
  pTrajData->fFilteredDIC             = 0.0F;
#endif

  /* Init TrajC0 with Course C0 and TrajC1 with 0*/
  CP_v_TrajKalmanSetInitValues( pCourseData , pTrajData);

#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
  CP_v_TraceTrajKalmanSetInitValues(pTrajData, pTraceTrajectory);
#else
  _PARAM_UNUSED(pTraceTrajectory);
#endif
}
/*************************************************************************************************************************
  Functionname:    CP_v_TrajKalmanSetInitValues                                                                        */ /*!

  @brief           Initialize the Values (X0/P0) of the Kalman Filter

  @description     Initialize the Values (X0/P0) of the Kalman Filter

                   @startuml
                   Partition CP_v_TrajKalmanSetInitValues{
                   Start
                   : Set Initial P Matrix (P = U*D*U' ==> UD = P0);
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pCourseData : Pointer to course data structure 
                      fCurve : Radius of the curve provided by the VDY trajectory                         [-1.f ... +1.f]m^-1
  @param[in]       pTrajData : Pointer to trajectory data structure CP_t_CourseData defined in cp_ext.h
                      KafiEst : The Kalman filter base data                                               [float32 as defined in cml_kafi.h]
                      KafiEst.XVec : Vector, estimated state vector                                       [float32 as defined in cml_kafi.h]
                      KafiEst.UDMat : UDUT factorized matrix, covariance                                  [float32 as defined in cml_kafi.h]
                      KafiEst.XsVec : Vector, predicted state vector                                      [float32 as defined in cml_kafi.h]
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/16/2016



  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CP_v_TrajKalmanSetInitValues( const CP_t_CourseData * pCourseData, const CP_t_TrajectoryData * pTrajData )
{

  GDBKalmanSetMat(&pTrajData->KafiEst.XVec,  CP_sTRAJ_C0,  (uint8)0, pCourseData->fCurve);
  GDBKalmanSetMat(&pTrajData->KafiEst.XsVec, CP_sTRAJ_C0,  (uint8)0, pCourseData->fCurve);
  GDBKalmanSetMat(&pTrajData->KafiEst.XVec,  CP_sTRAJ_C1,  (uint8)0, 0.0f         );
  GDBKalmanSetMat(&pTrajData->KafiEst.XsVec, CP_sTRAJ_C1,  (uint8)0, 0.0f         );

  /* Set Initial P Matrix (P = U*D*U' ==> UD = P0) */

  GDBKalmanSetMat(&pTrajData->KafiEst.UDMat, CP_sTRAJ_C0,   CP_sTRAJ_C0,  CP_INIT_TRAJ_NOISE_C0 );
  GDBKalmanSetMat(&pTrajData->KafiEst.UDMat, CP_sTRAJ_C1,   CP_sTRAJ_C1,  CP_INIT_TRAJ_NOISE_C1 );


  GDBKalmanUpdatePDiag(&pTrajData->KafiEst);
}

# if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
/*************************************************************************************************************************
  Functionname:    CP_v_TraceTrajKalmanSetInitValues                                                                        */ /*!

  @brief           Initialize the Values (X0/P0) of the Kalman Filter for trace trajectory

  @description     Initialize the Values (X0/P0) of the Kalman Filter for trace trajectory

  @return          -

  @param[in]          pCourseData : Pointer to course data structure 
                      fCurve : Radius of the curve provided by the VDY trajectory                              [-1.f ... +1.f]m^-1
  @param[in]          pTraceTrajectory : Pointer to trace trajectory data structure
                      KafiTraceEst : The Kalman filter base data                                               [float32 as defined in cml_kafi.h]
                      KafiTraceEst.XVec : Vector, estimated state vector                                       [float32 as defined in cml_kafi.h]
                      KafiTraceEst.UDMat : UDUT factorized matrix, covariance                                  [float32 as defined in cml_kafi.h]
                      KafiTraceEst.XsVec : Vector, predicted state vector                                      [float32 as defined in cml_kafi.h]
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component
                   CP_CFG_TRACE_TRAJ_KALMAN_FILTER: Switch to enable Kalman filtering after PSO

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         4/05/2020
  @changed         

  @author          aathira.elizabeth.binu@continental-corporation.com
                   mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/
static void CP_v_TraceTrajKalmanSetInitValues(const CP_t_TrajectoryData * pTrajData, const CP_t_TraceTrajectory * pTraceTrajectory )
{
  /* Initializing X and Xs vector*/
  /*X=Xs= [ c0 ]
          [  0 ]*/
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.XVec,  CP_sTRACE_TRAJ_C0,  (uint8)0, CP_f_KalmanGetTrajEstState(pTrajData,CP_sTRAJ_C0));
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.XsVec, CP_sTRACE_TRAJ_C0,  (uint8)0, CP_f_KalmanGetTrajEstState(pTrajData,CP_sTRAJ_C0));
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.XVec,  CP_sTRACE_TRAJ_C1,  (uint8)0, CP_f_KalmanGetTrajEstState(pTrajData,CP_sTRAJ_C1));
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.XsVec, CP_sTRACE_TRAJ_C1,  (uint8)0, CP_f_KalmanGetTrajEstState(pTrajData,CP_sTRAJ_C1));

  /* Set Initial P Matrix (P = U*D*U' ==> UD = P0) */
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.UDMat, CP_sTRACE_TRAJ_C0,   CP_sTRACE_TRAJ_C0,  CP_f_KalmanGetTrajErrorCov(pTrajData,CP_sTRAJ_C0) );
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.UDMat, CP_sTRACE_TRAJ_C1,   CP_sTRACE_TRAJ_C1,  CP_f_KalmanGetTrajErrorCov(pTrajData,CP_sTRAJ_C1) );

  GDBKalmanUpdatePDiag(&pTraceTrajectory->KafiTraceEst);
}
#endif


/*************************************************************************************************************************
  Functionname:    CP_v_PrepareTrajectoryData                                                                          */ /*!

  @brief           Prepare Trajectory Data

  @description     This function prepares the trajectory data before calculating combined ACC trajectory. 
                   It remembers the last cycle data when calculating combined trajectory in next cycle.
                   

  @return          -

  @param[in,out]   pTrajData : Pointer to trajectory data structure CP_t_TrajectoryData defined in cp_ext.h
                      fDistXUnplausibleSCurve : Longitudinal distance at which an unplausible 
                                                s-curve has been detected for the road-trajectory           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      Current.fTrajAngle : Trajectory angle of current cycle                                [-PI ... +PI] rad   
  @param[out]      pTrajData : Pointer to trajectory data structure CP_t_TrajectoryData defined in cp_ext.h       
                      LastCycle.fTrajC0 : Trajectory clothoid parameter of last cycle                       [-1.f ... +1.f]m^-1
                      LastCycle.fTrajC1 : Trajectory clothoid parameter of last cycle                       [-1.f ... +1.f]m^-2
                      LastCycle.fTrajAngle : Trajectory angle of last cycle                                 [-PI ... +PI] rad
                      State.EgoCourseOnly : Bit indicating that only ego course used for trajectory         [TRUE,FALSE]
                      State.FusionTraces : Bit indicating that Traces are used for trajectory fusion        [TRUE,FALSE]
                      State.FusionRoadstimation : Bit indicating that RE is used for trajectory fusion      [TRUE,FALSE]
                      fMovObjFusRange : Moving object Fusion Range                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      fMSETrace : Mean Squared Error of Trace                                               [0...CP_MAX_TRACE_MSE]        
                      fRoadEstFusRange : Range in longitudinal direction up to which the Road trajectory 
                                         is used for the fusion for the ACC trajectory                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 

  @glob_in         pt_CPInput->t_LAInput.pt_ScaleBracketState : state of trace bracket adaption             [LA_t_ScaleBracketState as defined in la_ext.h]
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Configuration switch which moves trace brackets in case of ego lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Configuration switch which moves trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch which moves trace brackets w.r.t. BLINKER FEATURE
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                                          : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         2/16/2016

 

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
void CP_v_PrepareTrajectoryData( CP_t_TrajectoryData * pTrajData )
{
  const GDBTrafoMatrix2D_t  * pM = SLATE_p_GetTrafoMatrix2DCOFForward();  /* Note was: FCTGetTrafoMatrix2DCOFForwardTgtSync(); */
  float32 fDistXUnplausible;

  /* remember last state*/
  pTrajData->LastCycle.fTrajAngle = pTrajData->Current.fTrajAngle;
  pTrajData->LastCycle.fTrajC0    = CP_f_KalmanGetTrajEstState(pTrajData , CP_sTRAJ_C0);
  pTrajData->LastCycle.fTrajC1    = CP_f_KalmanGetTrajEstState(pTrajData , CP_sTRAJ_C1);
  /*@todo invent a TrajAngle estimation*/
  pTrajData->Current.fTrajAngle   = 0.0f;

  /*compensate UnplausibleSCurve distance*/
  fDistXUnplausible = GDBmathTrafoXPos2D(pM , pTrajData->fDistXUnplausibleSCurve , 0.0f);
  pTrajData->fDistXUnplausibleSCurve = MAX_FLOAT(fDistXUnplausible,0.0f);

  /*reset to Trajectory default state*/
  pTrajData->State.EgoCourseOnly  = TRUE;
  pTrajData->State.FusionRoadstimation  = FALSE;
  pTrajData->State.FusionTraces = FALSE;

  pTrajData->fMovObjFusRange  = 0.0f;
  pTrajData->fMSETrace        = 0.0f;
  pTrajData->fRoadEstFusRange = 0.0f;
}

/************************************************************************
  Functionname:    CP_v_CalculateTrajectory                           */ /*!

  @brief           Calculate ACC-Trajectory

  @description     Predict the combined ACC trajectory based on the vehicle dynamics data, navi data, road data, camera data and Moving object trace data
                   fuse any of these data to the vehicle dynamics data based on the situation. The fused data of any combination with vdy data pass to the kalman filter.
                   Kalman filter will predict the Combined ACC trajectory.

                   input         FILTER         Output

                   VDY         >|K F|
                   CAM DATA    >|A I|
                   NAVI DATA   >|L L|        >|KALMAN PREDICTED ACC TRAJECTORY|
                   TRACE DATA  >|M T|
                   ROAD DATA   >|A E|
                                |N R|

                                  X

                                  ^
                                  |
                                  |              AUTOSAR coordinate system
                                  |
                        Y  <-------
  
                   @startuml
                   Partition CP_v_CalculateTrajectory{
                   Start 
                   : prepares the trajectory data;
                   : predict fused trajectory based on model;
                   : Prepare VDY Trajectory for Fusion;
                   Note right 
                   Prepare Trace Trajectory for Fusion;
                   End note 
                   : Evaluate trace information;
                   : Calculate a combined trace trajectory based on all traces;
                   : Calculate trace samples based on trace trajectory;
                   : Evaluate trace samples;
                   Note right
                   Prepare Road Trajectory for Fusion
                   End note 
                   : Generate road samples;
                   : Evaluate road samples;
                   : Sample-Based ACC Trajectory Fusion;
                   : Navi Path Gradient Update;
                   : bypassing fusion filter if fusion disabled;
                   : set C0 and C1 in interface struct;
                   End 
                   } 
                   @enduml

  @return          -

  @param[in]       pTrajInputPara :Trajectory input parameter
                      bSuppressFusion : Boolean indicating if fusion will be suppressed                                        [TRUE,FALSE]

  @glob_in         CP_TrajFusionDebugInfo : structure containing trajectory fusion debug information
  @glob_in         pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData : Structure of data related to CP trajectory
                      CP_TrajectoryData.Config.UseRoadEstim : Bit indicating if road estimation shall be used for fusion       [TRUE,FALSE]
                      CP_TrajectoryData.Config.UseObjTraces : Bit indicating if object traces shall be used for fusion         [TRUE,FALSE]
                      CP_TrajectoryData.Config.UseCamLane : Bit indicating if camera lane shall be used for trajectory fusion  [TRUE,FALSE]
                      CP_TrajectoryData.Config.UseNaviPath : Bit indicating if Navi path shall be used for trajectory fusion   [TRUE,FALSE]
                      CP_TrajectoryData.KafiEst : The Kalman filter base data                                                  [float32 as defined in cml_kafi.h]      
                      CP_CourseData.fCurve : Radius of the curve provided by the VDY trajectory                                [-1.f ... +1.f]m^-1         
                      CP_CourseData.fCurveVar : Curvature variance of ego vehicle path                                         [-1.f ... +1.f]m^-1 
                      CP_TrajectoryData.KafiEst.XVec : Vector, estimated state vector                                          [float32 as defined in cml_kafi.h]
                      CP_TrajectoryData.KafiEst.UDMat : UDUT factorized matrix, covariance                                     [float32 as defined in cml_kafi.h]
                      CP_TrajectoryData.KafiEst.XsVec : Vector, predicted state vector                                         [float32 as defined in cml_kafi.h]
  @glob_out        pt_CPOutput
                      CP_TrajectoryData.State.NaviPathFusion : Bit when navi path fusion is active                             [TRUE,FALSE]
                      CP_TrajectoryData.State.CamLaneFusion : Bit when camera lane fusion is active                            [TRUE,FALSE]
                      CP_TrajectoryData.State.EgoCourseOnly : Bit indicating that only ego course used for trajectory          [TRUE,FALSE]
                      CP_TrajectoryData.State.FusionRoadstimation : Bit indicating that RE is used for trajectory fusion       [TRUE,FALSE]
                      CP_TrajectoryData.State.FusionTraces : Bit indicating that Traces are used for trajectory fusion         [TRUE,FALSE]
                      CP_TrajectoryData.Current.fTrajC0 : Trajectory clothoid parameter of current cycle                       [-1.f ... +1.f]m^-1
                      CP_TrajectoryData.Current.fTrajC1 : Trajectory clothoid parameter of current cycle                       [-1.f ... +1.f]m^-1

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT Support for Moving Object Traces
  @c_switch_part   FCT_SIMU                            : Configuration switch used for simulation  
  @c_switch_part   CP_CFG_LANE_CHG_CAM_FUSION          : Configuration switch to enable support for camera lane fusion features when changing lanes
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE     : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING        : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   FCT_CFG_ROAD_INPUT                  : FCT support for Road input
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    161:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-161-00061542 \n
  
  @created         
  @changed         2/23/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_CalculateTrajectory(const CP_t_TrajectoryInputParameter * pTrajInputPara)
{
  CP_v_PrepareTrajectoryData(&(pt_CPOutput->CP_TrajectoryData));

// Check if right way!
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#ifdef FCT_SIMU
  memset(&CP_TrajFusionDebugInfo, 0, sizeof(CP_TrajFusionDebugInfo));
#endif
#endif
  if  (
       (pt_CPOutput->CP_TrajectoryData.Config.UseRoadEstim != FALSE)
    || (pt_CPOutput->CP_TrajectoryData.Config.UseObjTraces != FALSE)
#if (CP_CFG_LANE_CHG_CAM_FUSION)
    || (pt_CPOutput->CP_TrajectoryData.Config.UseCamLane != FALSE)
#endif
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
    || (pt_CPOutput->CP_TrajectoryData.Config.UseNaviPath != FALSE)
#endif
    )
  {
    CP_t_TrajectoryPosSamples   TrajectoryPosSamples;

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
    CP_t_InputSourceParams       Trace_Params;
#endif

#if (CP_CFG_LANE_CHG_CAM_FUSION)
    float32 fXDistFirstSample;
#endif

    /*predict fused trajectory based on model*/
    CP_v_KalmanPredictTrajectory(&(pt_CPOutput->CP_TrajectoryData));

    /***************** Prepare VDY Trajectory for Fusion ********************************/
    CP_v_CalculateVDYSamples(&(TrajectoryPosSamples.EGO_PosSamples));


#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
    /***************** Prepare Trace Trajectory for Fusion *******************************/
    if( pt_CPOutput->CP_TrajectoryData.Config.UseObjTraces )
    {
      /* Evaluate trace information */
      CP_v_FusionTracesEvalTraces(&Trace_Params);

      /* Calculate a combined trace trajectory based on all traces */
      CP_v_CalculateCombinedTraceTrajectory(&(pt_CPOutput->TraceTrajectory));
      /* Evaluate combined trace trajectory */
      CP_v_FusionEvalTraceSamples(&(pt_CPOutput->TraceTrajectory));
      if (pt_CPOutput->CP_TrajectoryData.State.FusionTraces == TRUE)
      {
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
        /*predict trace trajectory based on model*/
        CP_v_KalmanPredictTraceTrajectory(&(pt_CPOutput->TraceTrajectory));
        /* update predicted state with measurment */
        CP_v_KalmanUpdateTraceMeas(&(pt_CPOutput->TraceTrajectory));
        /*set C0 in interface struct*/
        pt_CPOutput->TraceTrajectory.fCurve  = CP_f_KalmanGetTraceTrajEstState(&(pt_CPOutput->TraceTrajectory), CP_sTRAJ_C0);
#endif
        /* Calculate trace samples based on trace trajectory */
        CP_v_CalculateTraceSamples(&(pt_CPOutput->TraceTrajectory), &(TrajectoryPosSamples.TRACE_PosSamples));

      }
      else
      {
        /* We are not going to use traces. Therefore, reset the trace trajectory again */
        CP_v_InitPosSamples(&(TrajectoryPosSamples.TRACE_PosSamples));
      }
      /* freeze the trace trajectory data for visualization in BirdEyeView V4 MO  */
      CP_TraceTrajectory = pt_CPOutput->TraceTrajectory;
    }
#endif

#if (FCT_CFG_ROAD_INPUT)
    /***************** Prepare Road Trajectory for Fusion ********************************/
    if( pt_CPOutput->CP_TrajectoryData.Config.UseRoadEstim )
    {
      /* Generate road samples */
      CP_v_CalculateRoadSamples(&(TrajectoryPosSamples.RE_PosSamples));

      /* Evaluate road samples */
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
      CP_v_FusionEvalRoad(&(TrajectoryPosSamples.EGO_PosSamples), &(TrajectoryPosSamples.RE_PosSamples), &Trace_Params);
#else
      CP_v_FusionEvalRoad(&(TrajectoryPosSamples.EGO_PosSamples), &(TrajectoryPosSamples.RE_PosSamples));
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT)) */
    }
#endif /* FCT_CFG_ROAD_INPUT */

#if (CP_CFG_LANE_CHG_CAM_FUSION)
    /***************** Prepare Cam Trajectory for Fusion ********************************/
    if (pt_CPOutput->CP_TrajectoryData.Config.UseCamLane)
    {
      fXDistFirstSample = TrajectoryPosSamples.EGO_PosSamples.fx[0];
      CP_v_FusionCamMain(&(TrajectoryPosSamples.CLM_PosSamples),fXDistFirstSample);
    }
    else
    {
      pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion  = FALSE;
    }
#endif

    /***************** Sample-Based ACC Trajectory Fusion ********************************/
    CP_v_TrajSampleFusionMain(&TrajectoryPosSamples); 


#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
    /************************ Navi Path Gradient Update ***************************************/
    if( pt_CPOutput->CP_TrajectoryData.Config.UseNaviPath )
    {
      CP_v_FusionNaviMain();
    }
    else
    {
      pt_CPOutput->CP_TrajectoryData.State.NaviPathFusion = FALSE;
    }
#endif

    if(pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly == FALSE)
    {
      GDBKalmanUpdatePDiag(&pt_CPOutput->CP_TrajectoryData.KafiEst);
    }
  }

  /*! Suppress Fusion if Blinker-Feature is active or in the first phase of the lane change; 
      in the second phase of the lane change fuse the trajectory (in case of valid fusion data) */
  if(pTrajInputPara->bSuppressFusion != FALSE) 
  {
    pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly = TRUE;
    /*! Reset all other fusion bits */
    pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion = FALSE;
    pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation = FALSE;
    pt_CPOutput->CP_TrajectoryData.State.NaviPathFusion = FALSE;
    pt_CPOutput->CP_TrajectoryData.State.FusionTraces = FALSE;
  }

  /* bypassing fusion filter if fusion disabled */
  if(pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly != FALSE)
  {
    GDBKalmanSetMat(&pt_CPOutput->CP_TrajectoryData.KafiEst.XVec,  CP_sTRAJ_C0,  (uint8)0, pt_CPOutput->CP_CourseData.fCurve);
    GDBKalmanSetMat(&pt_CPOutput->CP_TrajectoryData.KafiEst.XsVec, CP_sTRAJ_C0,  (uint8)0, pt_CPOutput->CP_CourseData.fCurve);
    GDBKalmanSetMat(&pt_CPOutput->CP_TrajectoryData.KafiEst.XVec,  CP_sTRAJ_C1,  (uint8)0, 0.0f);
    GDBKalmanSetMat(&pt_CPOutput->CP_TrajectoryData.KafiEst.UDMat, CP_sTRAJ_C0,  CP_sTRAJ_C0, pt_CPOutput->CP_CourseData.fCurveVar);
    GDBKalmanSetMat(&pt_CPOutput->CP_TrajectoryData.KafiEst.XsVec, CP_sTRAJ_C1,  (uint8)0, 0.0f);
    GDBKalmanSetMat(&pt_CPOutput->CP_TrajectoryData.KafiEst.UDMat, CP_sTRAJ_C1,  CP_sTRAJ_C1, 0.0f);
    GDBKalmanUpdatePDiag(&pt_CPOutput->CP_TrajectoryData.KafiEst);
  }

  /*set C0 and C1 in interface struct*/
  pt_CPOutput->CP_TrajectoryData.Current.fTrajC0  = CP_f_KalmanGetTrajEstState(&(pt_CPOutput->CP_TrajectoryData), CP_sTRAJ_C0);
  pt_CPOutput->CP_TrajectoryData.Current.fTrajC1  = CP_f_KalmanGetTrajEstState(&(pt_CPOutput->CP_TrajectoryData), CP_sTRAJ_C1);

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
    if (pt_CPOutput->CP_TrajectoryData.State.FusionTraces   == FALSE)
    {
      CP_v_TraceTrajKalmanSetInitValues(&(pt_CPOutput->CP_TrajectoryData),&(pt_CPOutput->TraceTrajectory));
    }
#endif
#endif

}

/*************************************************************************************************************************
  Functionname:    CP_v_TrajSampleFusionMain                                                                           */ /*!

  @brief           Fuse the vdy, trace,road samples for the prediction of ACC Trajectory

  @description     Predict the combined ACC trajectory based on the vehicle dynamics data, navi data, road data, camera data and Moving object trace data
                   fuse any of these data to the vehicle dynamics data based on the situation. The fused data of any combination with vdy data pass to the kalman filter.
                   Kalman filter will predict the Combined ACC trajectory.

                   input         FILTER         Output

                   VDY         >|K F|
                   CAM DATA    >|A I|
                   NAVI DATA   >|L L|        >|KALMAN PREDICTED ACC TRAJECTORY|
                   TRACE DATA  >|M T|
                   ROAD DATA   >|A E|
                                |N R|
                @startuml 
                start
                partition Cp_trajectory{
                :Declare local varibles for getting values for long range, short range, trace, road , camera trajectory data;
                :Fill long range and short range with VDY trajectory data;
                :Set number of samples for long range and short range trajectory;
                :Generate sample for trace trajectory;
                :Calculate trace weight and variance for trace each sample;
                :Set number of trace samples to maximum available trace sample;
                :Generate sample for road trajectory;
                :Calculate course variance,road variance;
                If (Tunnel probability is greater than 0.5 ) then (yes)
                  : Set road vdy fusion factor;
                Endif
                If (Road fusion state is true or road vdy fusion factor is less than CP_RE_FUS_SMOOTHING_MAX) then (yes)
                     If (Road fusion state is true) then (yes)
                         If (diffrence between road vdy fusion factor and CP_RE_FUS_SMOOTHING_INC is greater than CML_f_Delta) then (yes)
                           :Decrement road vdy fusion factor by CP_RE_FUS_SMOOTHING_INC;
                         Else
                           :Set road vdy fusion factor to zero;
                     Endif
                    Else 
                         If (sum of road vdy fusion factor and CP_RE_FUS_SMOOTHING_INC is less than CP_RE_FUS_SMOOTHING_MAX) then (yes)
                           : Increment road vdy fusion factor by CP_RE_FUS_SMOOTHING_INC;
                         Else
                           : Set road vdy fusion factor to CP_RE_FUS_SMOOTHING_MAX; 
                     Endif
                    Endif
                Endif
                : Generate sample for camera trajectory;
                :Set number of camera samples to maximum available camera sample;
                If (Available number of Road samples greater than trace samples, and trace fusion state, road fusion state is true) then (yes)
                      : Set the maximum number of samples for long range trajectory based on road data;
                      : Fuse road samples to Long Range trajectory samples;
                Elseif (Road and trace Fusion State is true) then (yes)
                      : set the maximum number of samples for long range trajectory based on trace data;
                      : Fuse trace samples to Long Range trajectory samples;
                Elseif (camera and trace Fusion State is true and number of camera samples less than eight and trace greater than twelve) then (yes)
                      : set the maximum number of samples for long range trajectory based on trace data;
                      : Fuse trace samples to Long Range trajectory samples;
                Else
                      : Do nothing;
                Endif
                If (Road fusion state is true Or road vdy fusion factor less than CP_RE_FUS_SMOOTHING_MAX) then (yes)
                      : Fuse road samples to Long range trajectory;
                      : Set road fusion range;
                Endif
                If (road fusion state is true and lane change state is valid) then (yes)
                     : set trace fusion state as Flase;
                     : set maximum distance of trace equal to that of road;
                Endif
                If ((trace fusion state is true) then (yes)
                       : fuse trace sample data to Short Range trajectory samples;
                Endif
                : Set maximum and minimum distaces for fusion;
                If (camera fusion state is true) then (yes)
                    : Fuse camera samples into short range trajectoy.;
                    : set camera fusion state as true and ego course as false.;
                    : set minimum and maximum fusion distance based on camera.;
                Endif
                If (trace fusion state is false) then (yes)
                    If (road and camera fusion state is true) then (yes)
                        : set minimum fusion distance as the minimum of road and camera samples;
                    Elseif (road fusion state is flase and and camera fusion state is true) then (yes)
                        : set minimum fusion distance as the minimum of camera and CAL_MAX_NB_TRAJ_SAMPLES;
                    Elseif (road fusion stae is true and and camera fusion state is false) then (yes)
                        : set minimum fusion distance as the minimum of road and CAL_MAX_NB_TRAJ_SAMPLES;
                    Else 
                        : Do nothing;
                    Endif
                  :set minimum fusion distance;
                  :set maximum fusion distance equal to minimum fusion distance;
                Endif
                If (camera fusion state is false) then (yes)
                    If (road and trace fusion state is true) then (yes)
                        : set minimum fusion distance as the minimum of road and trace samples;
                    Elseif (road fusion state is flase and and trace fusion state is true) then (yes)
                        : set minimum fusion distance as the minimum of trace and CAL_MAX_NB_TRAJ_SAMPLES;
                    Elseif (road fusion state is true and and trace fusion state is false)
                        : set minimum fusion distance as the minimum of road and CAL_MAX_NB_TRAJ_SAMPLES;
                    Else 
                        : Do nothing;
                    Endif
                Endif
                If (minimum and maximum fusion disance is zero)  then (yes)
                     : set maximum fusion distance equal to CAL_MAX_NB_TRAJ_SAMPLES;
                Endif
                If (road fusion state is true and lane change is valid) then (yes)
                       If (ego position samples greater than short range trajectory samples) then (yes)
                       : Replace first six fused position samples with ego position samples;
                      Endif
                Endif
                : fuse short range trajectory sampeles into fused samples for samples less than minimum fusion distance;
                While(number samples less tham maximum fusion and greater than minimum fusion distance)
                   : fuse long range trajectory into fused trajectory samples;
                Endwhile
                : pass current trajectory and fused samples to kalman filter;
                Stop
                @enduml
  @return          -

  @param[in]       pTrajectoryPosSamples :  Structure containing  position samples from different input sources
                      RE_PosSamples : Structure containing road estimation trajectory samples
                      RE_PosSamples.fx[iSample] : x-position of tarjectory sample                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      RE_PosSamples.fy[iSample] : y-position of tarjectory sample                                [-PI/2*RW_FCT_MAX ...  PI/2*RW_FCT_MAX] m
                      RE_PosSamples.nb_samples : Number of samples                                               [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                      TRACE_PosSamples : Structure containing trace estimation trajectory samples
                      TRACE_PosSamples.fx[iSample] : x-position of tarjectory sample                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      TRACE_PosSamples.fy[iSample] : y-position of tarjectory sample                             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      EGO_PosSamples : Structure containing ego motion trajectory samples
                      EGO_PosSamples.fx[iSample] : x-position of tarjectory sample                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      EGO_PosSamples.fy[iSample] : y-position of tarjectory sample                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      EGO_PosSamples.nb_samples : Number of samples                                              [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
  @param[in,out]      TRACE_PosSamples.nb_samples : Number of samples                                            [0 ... CAL_MAX_NB_TRAJ_SAMPLES]                   
                      
  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_LAInput.pt_ScaleBracketState : State of trace bracket adaption [LA_t_ScaleBracketState defined in la_ext.h]
                      t_RTE.pf_EgoLongVel : Longitudinal velocity of ego vehicle                                                     [-330.f ... 330.f]m/s
                      t_RTE.pf_EgoCurve : Curvature of ego vehicle path                                                              [-1 ... +1] m^-1                
  @gob_in          pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData : Structure of data related to CP trajectory
                      CP_TrajectoryData.fMSETrace : Mean Squared Error of Trace                                                      [0...CP_MAX_TRACE_MSE]    
                      CP_TrajectoryData.State.FusionRoadstimation : Bit indicating that RE is used for trajectory fusion             [TRUE,FALSE]
                      CP_TrajectoryData.State.FusionTraces : Bit indicating that Traces are used for trajectory fusion               [TRUE,FALSE]
                      CP_TrajectoryData.State.EgoCourseOnly : Bit indicating that only ego course used for trajectory                [TRUE,FALSE]
                      CP_TrajectoryData.fRoadEstFusRange : Range in longitudinal direction up to which the Road trajectory 
                                                           is used for the fusion for the ACC trajectory                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
  @glob_in         TUNNEL_PROBABILITY : Tunnel Probability     [0 ... 1]
  @glob_out        CP_TrajFusionDebugInfo : Structure containing trajectory fusion debug information
                      EGO_PosSamples : Structure containing ego motion trajectory samples
                      RE_PosSamples : Structure containing road estimation trajectory samples
                      TRACE_PosSamples : Structure containing trace estimation trajectory samples
                      FUSED_PosSamples : Structure containing fused trajectory samples
                      FUSED_PosSamples.nb_samples : Number of samples                                                                [0 ... CAL_MAX_NB_TRAJ_SAMPLES]

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Configuration switch which moves trace brackets in case of ego lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Configuration switch which moves trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch which moves trace brackets w.r.t. BLINKER FEATURE
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING                                : FCT Support for Moving Object Traces
  @c_switch_part   FCT_CFG_ROAD_INPUT                                                 : FCT support for Road input
  @c_switch_part   FCT_SIMU                                                           : Configuration switch used for simulation    
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                                          : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability   146: doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-146-00061542 \n
                  147:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-147-00061542 \n


  @created         
  @changed         2/23/2016

  @author          Christopher Knievel
*************************************************************************************************************************/
static void CP_v_TrajSampleFusionMain(CP_t_TrajectoryPosSamples   * pTrajectoryPosSamples)
{
  uint8 iSample, minFusionDist, maxFusionDist;
  uint8 iSampleStart = 0u;
  float32 fDeltaTrajDuringLC = 0.f;
  float32 fDeltaCombinedTrajectories = 0.f;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT)
  const LA_t_ScaleBracketState LC_State = *(pt_CPInput->t_LAInput.pt_ScaleBracketState);
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT) */
#endif /* ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM ) */
#endif/* (FCT_CFG_ACC_LANE_ASSOCIATION) */

  SLATE_t_PosSamples FusedPosSamples;
  /* long range fusion */
  SLATE_t_PosSamples LRFusedPosSamples;
  /* short range fusion */
  SLATE_t_PosSamples SRFusedPosSamples;

  CP_t_NoiseModelLinear ConstantNoise;

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  SLATE_t_PosSamples TracePosSamples;
  float32 fWeightingTraces = 0.0f;
  float32 f_Abs_EgoCurve;
#endif

#if (FCT_CFG_ROAD_INPUT)
  SLATE_t_PosSamples RoadPosSamples;
  float32 fCourseVar,fRoadEstVar;
#endif

#if CP_CFG_LANE_CHG_CAM_FUSION
  SLATE_t_PosSamples CamPosSamples;
#endif

  /* Definition of local variables for input pointers */
  float32 f_EgoLongVel = *pt_CPInput->t_RTE.pf_EgoLongVel;

  /*************** Generate Samples for VDY Trajectory ******************/
  for (iSample=0u; iSample<CAL_MAX_NB_TRAJ_SAMPLES; iSample++)
  {
    LRFusedPosSamples.fx[iSample]   = pTrajectoryPosSamples->EGO_PosSamples.fx[iSample];
    LRFusedPosSamples.fy[iSample]   = pTrajectoryPosSamples->EGO_PosSamples.fy[iSample];
    LRFusedPosSamples.fVar[iSample] = CP_f_GetCourseVariance(pTrajectoryPosSamples->EGO_PosSamples.fx[iSample], f_EgoLongVel);
    
    /* Copy fused position samples to auxiliary vector */
    SRFusedPosSamples.fx[iSample]   = LRFusedPosSamples.fx[iSample];
    SRFusedPosSamples.fy[iSample]   = LRFusedPosSamples.fy[iSample];
    SRFusedPosSamples.fVar[iSample] = LRFusedPosSamples.fVar[iSample];
  }
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING)||(FCT_CFG_ROAD_INPUT))
  LRFusedPosSamples.nb_samples = CAL_MAX_NB_TRAJ_SAMPLES;
  SRFusedPosSamples.nb_samples = CAL_MAX_NB_TRAJ_SAMPLES;
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING)||(FCT_CFG_ROAD_INPUT)) */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  /*************** Generate Samples for Trace Trajectory ****************/
  for (iSample=0u; iSample<MIN(CAL_MAX_NB_TRAJ_SAMPLES,pTrajectoryPosSamples->TRACE_PosSamples.nb_samples); iSample++)
  {
    TracePosSamples.fx[iSample]   = pTrajectoryPosSamples->TRACE_PosSamples.fx[iSample];
    TracePosSamples.fy[iSample]   = pTrajectoryPosSamples->TRACE_PosSamples.fy[iSample];
    f_Abs_EgoCurve   = fABS(*pt_CPInput->t_RTE.pf_EgoCurve);
    if(f_Abs_EgoCurve>CP_TRACEWEIGHT_CURVE_THRESH)
    {
      fWeightingTraces = MINMAX_FLOAT(0.5f,1.0f,0.5f + pt_CPOutput->CP_TrajectoryData.fMSETrace);
    }
    else
    {
      fWeightingTraces = MINMAX_FLOAT(1.3f,1.5f,1.3f + pt_CPOutput->CP_TrajectoryData.fMSETrace);
    }

    TracePosSamples.fVar[iSample] = fWeightingTraces * CP_f_GetTraceTrajVariance(pTrajectoryPosSamples->TRACE_PosSamples.fx[iSample], f_EgoLongVel);
  }
  TracePosSamples.nb_samples = pTrajectoryPosSamples->TRACE_PosSamples.nb_samples;
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

#if (FCT_CFG_ROAD_INPUT)
  /* Set hysteresis for Road fusion */
  /* Stop VDY-Road-Fusion without smooth state transition if tunnel probability is high*/
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  if(*pt_CPInput->t_RTE.pf_TunnelProbability >= 0.5f)
  {
    fFacFusionVDYROAD = CP_RE_FUS_SMOOTHING_MAX;
  }
#endif

  if( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE) ||
      (fFacFusionVDYROAD < (CP_RE_FUS_SMOOTHING_MAX - CML_f_Delta)))
  { 
    /* fFacFusionVDYROAD is used to get a smooth transition from VDY-only course to the fused 
        VDY-ROAD trajectory, e.g. decrement fFacFusionVDYROAD to increase the weight of the RE-Fusion, 
        if the current situation is actually not a fusion-situation and vice versa*/
    if(pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE)
    {
      if((pt_CPOutput->CP_TrajectoryData.State.FusionTraces != FALSE) && ((fFacFusionVDYROAD - (CP_RE_FUS_SMOOTHING_REDUCTION_FAC * CP_RE_FUS_SMOOTHING_INC)) > CML_f_Delta) )
      {
        fFacFusionVDYROAD -= (CP_RE_FUS_SMOOTHING_INC * CP_RE_FUS_SMOOTHING_REDUCTION_FAC);
      }
      else if((fFacFusionVDYROAD - CP_RE_FUS_SMOOTHING_INC) > CML_f_Delta) 
      {
        fFacFusionVDYROAD -= CP_RE_FUS_SMOOTHING_INC;
      }
      else
      {
        fFacFusionVDYROAD = 0.0f;
      }
    }
    else
    {
      if((pt_CPOutput->CP_TrajectoryData.State.FusionTraces != FALSE) && (fFacFusionVDYROAD + (CP_RE_FUS_SMOOTHING_REDUCTION_FAC * CP_RE_FUS_SMOOTHING_INC) < CP_RE_FUS_SMOOTHING_MAX))
      {
        fFacFusionVDYROAD += (CP_RE_FUS_SMOOTHING_INC * CP_RE_FUS_SMOOTHING_REDUCTION_FAC);
      }
      else if((fFacFusionVDYROAD + CP_RE_FUS_SMOOTHING_INC) < CP_RE_FUS_SMOOTHING_MAX)
      {
        fFacFusionVDYROAD += CP_RE_FUS_SMOOTHING_INC;
      }
      else
      {
        fFacFusionVDYROAD = CP_RE_FUS_SMOOTHING_MAX;
      }
    }
  }

  /*************** Generate Samples for Road Trajectory ****************/
  for (iSample=0u; iSample<MIN(CAL_MAX_NB_TRAJ_SAMPLES,pTrajectoryPosSamples->RE_PosSamples.nb_samples); iSample++)
  {
    RoadPosSamples.fx[iSample] = pTrajectoryPosSamples->RE_PosSamples.fx[iSample];
    RoadPosSamples.fy[iSample] = pTrajectoryPosSamples->RE_PosSamples.fy[iSample];

    fCourseVar  = CP_f_GetCourseVariance(pTrajectoryPosSamples->EGO_PosSamples.fx[iSample], f_EgoLongVel);
    /* Use fFacFusionVDYROAD to get a smooth transition from VDY-only course to the fused VDY-ROAD trajectory */
    fRoadEstVar = (fFacFusionVDYROAD * fCourseVar) + CP_f_GetRoadVariance(pTrajectoryPosSamples->RE_PosSamples.fx[iSample], f_EgoLongVel); 

    RoadPosSamples.fVar[iSample] = fRoadEstVar;  
  }
  RoadPosSamples.nb_samples = pTrajectoryPosSamples->RE_PosSamples.nb_samples;

#endif /* END IF (FCT_CFG_ROAD_INPUT) */

#if (CP_CFG_LANE_CHG_CAM_FUSION)
  /*************** Generate Samples for Camera Trajectory ****************/
  for (iSample=0u; iSample<MIN(CAL_MAX_NB_TRAJ_SAMPLES,pTrajectoryPosSamples->CLM_PosSamples.nb_samples); iSample++)
  {
    CamPosSamples.fx[iSample]   = pTrajectoryPosSamples->CLM_PosSamples.fx[iSample];
    CamPosSamples.fy[iSample]   = pTrajectoryPosSamples->CLM_PosSamples.fy[iSample];
    CamPosSamples.fVar[iSample] = CP_f_GetCamTrajVariance(pTrajectoryPosSamples->CLM_PosSamples.fx[iSample], f_EgoLongVel);
  }
  CamPosSamples.nb_samples = pTrajectoryPosSamples->CLM_PosSamples.nb_samples;
#endif

  /******* Fusion of the trajectory with the longest valid distance ************************/
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
  if(  (pTrajectoryPosSamples->RE_PosSamples.nb_samples > pTrajectoryPosSamples->TRACE_PosSamples.nb_samples)
     && (pt_CPOutput->CP_TrajectoryData.State.FusionTraces != FALSE)
     && (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE))
  {
    /* Road trajectory is longer compared to the trace trajectory. Hence, start fusion with
       road up to the maximum road distance */
      
    /* Limit maximum fusion distance for road */
    LRFusedPosSamples.nb_samples = MAX(CAL_MAX_NB_TRAJ_SAMPLES,pTrajectoryPosSamples->RE_PosSamples.nb_samples);


    /********************** Fusion of Road Trajectory ********************/
    if( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE) ||
        (fFacFusionVDYROAD < (CP_RE_FUS_SMOOTHING_MAX - CML_f_Delta)))
    {
      CP_v_FusePosSamples(&LRFusedPosSamples, &RoadPosSamples);
    }
  }
  else if (( pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE) && (pt_CPOutput->CP_TrajectoryData.State.FusionTraces != FALSE))
  {
    /* Trace trajectory is longer compared to the road trajectory */
    /* Limit maximum fusion distance for trace */
    LRFusedPosSamples.nb_samples = MAX(CAL_MAX_NB_TRAJ_SAMPLES,pTrajectoryPosSamples->TRACE_PosSamples.nb_samples);

    CP_v_FusePosSamples(&LRFusedPosSamples,&TracePosSamples);
  }
#if (CP_CFG_LANE_CHG_CAM_FUSION)
  else if ( (pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion != FALSE )
          &&(pTrajectoryPosSamples->CLM_PosSamples.nb_samples <= CP_PAR_MAX_CAM_SAMPLES_LR_FUS) 
          &&(pt_CPOutput->CP_TrajectoryData.State.FusionTraces != FALSE )
          &&(pTrajectoryPosSamples->TRACE_PosSamples.nb_samples >= CP_PAR_MIN_TRACE_SAMPLES_LR_FUS))
  {
    LRFusedPosSamples.nb_samples = MAX(CAL_MAX_NB_TRAJ_SAMPLES,pTrajectoryPosSamples->TRACE_PosSamples.nb_samples);

    CP_v_FusePosSamples(&LRFusedPosSamples, &TracePosSamples);
  }
#endif
  else
  {
    /* One of the trajectories is longer, but only because one is missing. Therefore,
       we leave the VDY trajectory as the only component in the LR-Trajectory */
  }
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT)) */
  

  /**************** Fusion of Trace, Road, and VDY Samples ***************/
  /******************** for The Short Range Trajectory ******************/


  /********************** Fusion of Road Trajectory ********************/
#if (FCT_CFG_ROAD_INPUT)
  if( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE) ||
      (fFacFusionVDYROAD < (CP_RE_FUS_SMOOTHING_MAX - CML_f_Delta)))
  {
    CP_v_FusePosSamples(&SRFusedPosSamples, &RoadPosSamples);

    /* Road Estimation is considered due to the hysteresis function. Remember this state. */
    pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation = TRUE;
    pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly       = FALSE;

    /* Set road estimation fusion distance */
    pt_CPOutput->CP_TrajectoryData.fRoadEstFusRange = (float32)pTrajectoryPosSamples->RE_PosSamples.nb_samples * CP_SAMPLE_RESOLUTION_X;
  }
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

  /********************** Fusion of Trace Trajectory ********************/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
#if ((FCT_CFG_ROAD_INPUT) && (FCT_CFG_OBJECT_TRACE_PREPROCESSSING))
  if(pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE) 
  {
    if((LC_State != SLATE_NO_LANE_CHANGE) && (LC_State != SLATE_LANE_CHANGE_UNKNOWN))
    {
      /* Deactivate trace fusion in case of a lane change only if road trajectory is
         available */
      pt_CPOutput->CP_TrajectoryData.State.FusionTraces = FALSE;
      /* Bypass maximum distance calculation by setting maximum distance of traces equal to the one of road */
      pTrajectoryPosSamples->TRACE_PosSamples.nb_samples = pTrajectoryPosSamples->RE_PosSamples.nb_samples;
    }
  }
#endif /* END IF ((FCT_CFG_ROAD_INPUT) && (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)) */

#endif /* END IF ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM ) */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  if (pt_CPOutput->CP_TrajectoryData.State.FusionTraces != FALSE)
  {
    CP_v_FusePosSamples(&SRFusedPosSamples, &TracePosSamples);    
  }
#if (FCT_CFG_ROAD_INPUT) /* Both Trace and Road available */
    /* Determine the minimum/maximum distance of either road or trace */
  maxFusionDist = MAX(pTrajectoryPosSamples->RE_PosSamples.nb_samples,pTrajectoryPosSamples->TRACE_PosSamples.nb_samples);
  minFusionDist = MIN(pTrajectoryPosSamples->RE_PosSamples.nb_samples,pTrajectoryPosSamples->TRACE_PosSamples.nb_samples);

     /* Make sure we are not exceeding maximum number of samples */
  maxFusionDist = MIN(maxFusionDist,CAL_MAX_NB_TRAJ_SAMPLES);
#else /* Trace available but Road not available */
  maxFusionDist = MIN(pTrajectoryPosSamples->TRACE_PosSamples.nb_samples, CAL_MAX_NB_TRAJ_SAMPLES);
  minFusionDist = 0u;
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

#else /* Trace not available */
  /* Determine the minimum/maximum distance of either road or trace */
    minFusionDist = 0u;
#if (FCT_CFG_ROAD_INPUT) /* Trace not available but road available */
  maxFusionDist = MIN(pTrajectoryPosSamples->RE_PosSamples.nb_samples, CAL_MAX_NB_TRAJ_SAMPLES);
#else /* Both Trace and Road not available */
  maxFusionDist = 0u;
#endif /* END IF (FCT_CFG_ROAD_INPUT) */
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

  /********************** Fusion of Camera Trajectory ********************/
#if (CP_CFG_LANE_CHG_CAM_FUSION)
  if( (pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion != FALSE) )
  {
    CP_v_FusePosSamples(&SRFusedPosSamples, &CamPosSamples);

    /* Camera trajectory is used, remember this state. */
    pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion       = TRUE;
    pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly       = FALSE;
  maxFusionDist = MAX(maxFusionDist, pTrajectoryPosSamples->CLM_PosSamples.nb_samples);
  maxFusionDist = MIN(maxFusionDist, CAL_MAX_NB_TRAJ_SAMPLES);
  minFusionDist = MIN(minFusionDist, pTrajectoryPosSamples->CLM_PosSamples.nb_samples);
  }
#endif /* END IF (CP_CFG_LANE_CHG_CAM_FUSION) */

  /************* Combine SR-Trajectory with LR-Trajectory ***************/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING && FCT_CFG_ROAD_INPUT)
  if(pt_CPOutput->CP_TrajectoryData.State.FusionTraces == FALSE) 
  {
    /* Trace is missing, set minFusionDist equal to maximum distance of road/camera. 
       maxFusionDist is also set to minFusionDist. As a result, VDY samples are not
       attached at the end of the fused trajectory samples. VDY is not that trustworthy, 
       especially at larger distances. */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
    if( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == TRUE)
      &&(pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == TRUE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->RE_PosSamples.nb_samples, pTrajectoryPosSamples->CLM_PosSamples.nb_samples);
    }
    else if ( (pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == TRUE)
            &&(pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == FALSE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->CLM_PosSamples.nb_samples , CAL_MAX_NB_TRAJ_SAMPLES);
    }
    else
#endif
    if ( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == TRUE)
            &&(pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == FALSE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->RE_PosSamples.nb_samples , CAL_MAX_NB_TRAJ_SAMPLES);
    }
    else
    {
      /* Do Nothing --> This is just to supress QAC warnings */
    }
    minFusionDist = MIN(minFusionDist, CAL_MAX_NB_TRAJ_SAMPLES);
    maxFusionDist = minFusionDist;
  }
  
  if( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == FALSE) &&
    (fFacFusionVDYROAD > (CP_RE_FUS_SMOOTHING_MAX - CML_f_Delta)))
  {
    /* Road is missing, set minFusionDist equal to maximum distance of trace/camera */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
    if( (pt_CPOutput->CP_TrajectoryData.State.FusionTraces == TRUE)
      &&(pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == TRUE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->TRACE_PosSamples.nb_samples, pTrajectoryPosSamples->CLM_PosSamples.nb_samples);
    }
    else if ( (pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == TRUE)
            &&(pt_CPOutput->CP_TrajectoryData.State.FusionTraces == FALSE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->CLM_PosSamples.nb_samples , CAL_MAX_NB_TRAJ_SAMPLES);
    }
    else
#endif
    if ( (pt_CPOutput->CP_TrajectoryData.State.FusionTraces == TRUE)
            &&(pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == FALSE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->TRACE_PosSamples.nb_samples , CAL_MAX_NB_TRAJ_SAMPLES);
    }
    else
    {
      /* Do Nothing --> This is just to supress QAC warnings */
    }
    minFusionDist = MIN(minFusionDist, CAL_MAX_NB_TRAJ_SAMPLES);
    maxFusionDist = CAL_MAX_NB_TRAJ_SAMPLES;
  }

#if (CP_CFG_LANE_CHG_CAM_FUSION)
  if (pt_CPOutput->CP_TrajectoryData.State.CamLaneFusion == FALSE)
  {
    /* Camera is missing, set minFusionDist equal to maximum distance of trace/road */
    if( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == TRUE)
      &&(pt_CPOutput->CP_TrajectoryData.State.FusionTraces == TRUE)
      )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->RE_PosSamples.nb_samples, pTrajectoryPosSamples->TRACE_PosSamples.nb_samples);
      minFusionDist = MIN(minFusionDist, CAL_MAX_NB_TRAJ_SAMPLES);
      maxFusionDist = MAX(pTrajectoryPosSamples->RE_PosSamples.nb_samples, pTrajectoryPosSamples->TRACE_PosSamples.nb_samples);
    }
    else if ( (pt_CPOutput->CP_TrajectoryData.State.FusionTraces == TRUE)
      &&(pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == FALSE))
    {
      minFusionDist = MIN(pTrajectoryPosSamples->TRACE_PosSamples.nb_samples , CAL_MAX_NB_TRAJ_SAMPLES);
      maxFusionDist = CAL_MAX_NB_TRAJ_SAMPLES;
    }
    else if ( (pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation == TRUE)
      &&(pt_CPOutput->CP_TrajectoryData.State.FusionTraces == FALSE) )
    {
      minFusionDist = MIN(pTrajectoryPosSamples->RE_PosSamples.nb_samples , CAL_MAX_NB_TRAJ_SAMPLES);
      maxFusionDist = minFusionDist;
    }
    else
    {
      /* Do Nothing --> This is just to supress QAC warnings */
    }
  }
#endif
  /* Check minimum and maximum distance. If both are zero, than Road and Trace are invalid and not
     use for fusion. Therefore, reset to boundaries manually to consider VDY for the whole length */
  if((minFusionDist == 0u) && (maxFusionDist == 0u))
  {
    maxFusionDist = CAL_MAX_NB_TRAJ_SAMPLES;
  }  

  /* In case of a lane change replace the first samples of the road trajectory
     and use the vdy samples instead. */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

  if(pt_CPOutput->CP_TrajectoryData.State.FusionRoadstimation != FALSE) 
  {
    if((LC_State != SLATE_NO_LANE_CHANGE) && (LC_State != SLATE_LANE_CHANGE_UNKNOWN))
    {
      iSampleStart = CP_NUM_TRAJ_SAMPLES_AT_START;

      /* Limit the lane change impact */
      if(iSampleStart > minFusionDist)
      {
        iSampleStart = minFusionDist;
      }
      
      fDeltaTrajDuringLC = pTrajectoryPosSamples->EGO_PosSamples.fy[iSampleStart-1] - SRFusedPosSamples.fy[iSampleStart-1];//PRQA S 3689
      /* date: 2015-05-18, reviewer: Gangadhar Badiger, reason: Access bounds of an array manually verified, no side effect*/


      if(    (((LC_State == SLATE_PRE_LANE_CHANGE_LEFT) || (LC_State == SLATE_POST_LANE_CHANGE_LEFT))&& (pTrajectoryPosSamples->EGO_PosSamples.fy[iSampleStart-1] > SRFusedPosSamples.fy[iSampleStart-1]))//PRQA S 3689
      /* date: 2015-05-18, reviewer: Gangadhar Badiger, reason: Access bounds of an array manually verified, no side effect*/
          || (((LC_State == SLATE_PRE_LANE_CHANGE_RIGHT) || (LC_State == SLATE_POST_LANE_CHANGE_RIGHT))&& (pTrajectoryPosSamples->EGO_PosSamples.fy[iSampleStart-1] < SRFusedPosSamples.fy[iSampleStart-1])))//PRQA S 3689
      /* date: 2015-05-18, reviewer: Gangadhar Badiger, reason: Access bounds of an array manually verified, no side effect*/
      {
        for (iSample=0u; iSample<iSampleStart;iSample++)
        {       

          FusedPosSamples.fx[iSample]   = pTrajectoryPosSamples->EGO_PosSamples.fx[iSample];
          FusedPosSamples.fy[iSample]   = pTrajectoryPosSamples->EGO_PosSamples.fy[iSample];
          FusedPosSamples.fVar[iSample] = CP_f_GetCourseVariance(pTrajectoryPosSamples->EGO_PosSamples.fx[iSample], f_EgoLongVel);      
        }
      }
      else
      {
        /* VDY trajectory points in the opposite direction of the lane change (steerback). In this case, skip this fusion step */
        fDeltaTrajDuringLC = 0.f;
        iSampleStart = 0u;
      }
    }
  }
#endif /* END IF ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM ) */


  /* Determine the lateral deviation between the last sample of the short range trajectory
     and the position of the long range trajectory at this position */
  if(((minFusionDist-1) > 0) && ((minFusionDist-1) < CAL_MAX_NB_TRAJ_SAMPLES))
  {
    fDeltaCombinedTrajectories = (SRFusedPosSamples.fy[minFusionDist - 1] + fDeltaTrajDuringLC) - LRFusedPosSamples.fy[minFusionDist - 1];
  }
  else
  {
    fDeltaCombinedTrajectories = 0.0f;
  }
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING && FCT_CFG_ROAD_INPUT) */

  for (iSample = iSampleStart; iSample < minFusionDist; iSample++)
  {
    FusedPosSamples.fx[iSample]   = SRFusedPosSamples.fx[iSample];
    FusedPosSamples.fy[iSample]   = SRFusedPosSamples.fy[iSample] + fDeltaTrajDuringLC;
    FusedPosSamples.fVar[iSample] = SRFusedPosSamples.fVar[iSample];
  }

  for (iSample = minFusionDist; iSample < maxFusionDist; iSample++)
  {
    FusedPosSamples.fx[iSample]   = LRFusedPosSamples.fx[iSample];// PRQA S 3689
   /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Its reviewed and it made sure that maxFusionDist will never go out of boundary(which is CAL_MAX_NB_TRAJ_SAMPLES) */
    FusedPosSamples.fy[iSample]   = LRFusedPosSamples.fy[iSample] + fDeltaCombinedTrajectories;// PRQA S 3689
   /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Its reviewed and it made sure that maxFusionDist will never go out of boundary(which is CAL_MAX_NB_TRAJ_SAMPLES) */
    FusedPosSamples.fVar[iSample] = LRFusedPosSamples.fVar[iSample];// PRQA S 3689
   /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Its reviewed and it made sure that maxFusionDist will never go out of boundary(which is CAL_MAX_NB_TRAJ_SAMPLES) */
  }

  /* Limit maximum fusion distance as a function of VDY. In case the VDY trajectory indicates a narrow curve, do not
     use the complete amount of samples. Instead, the maximum fusion distance is set to the field-of-view calculated by
     the number of samples of the VDY samples */ 
  FusedPosSamples.nb_samples = (pTrajectoryPosSamples->EGO_PosSamples.nb_samples < maxFusionDist) ? pTrajectoryPosSamples->EGO_PosSamples.nb_samples : maxFusionDist;
  
  /* Update Kalman filter with fused samples */
  ConstantNoise.fNoiseOffset   = CP_KALMAN_POSAMPLES_NOISE_OFFSET;
  ConstantNoise.fNoiseGradient = 0.f;

  CP_v_KalmanUpdatePos(&FusedPosSamples,ConstantNoise,&(pt_CPOutput->CP_TrajectoryData));

#ifdef FCT_SIMU
  /*visualize generated samples in birdeye*/
  CP_TrajFusionDebugInfo.EGO_PosSamples   = pTrajectoryPosSamples->EGO_PosSamples;
  #if (FCT_CFG_ROAD_INPUT)
  CP_TrajFusionDebugInfo.RE_PosSamples    = pTrajectoryPosSamples->RE_PosSamples;
  #endif /* END IF (FCT_CFG_ROAD_INPUT) */
  #if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CP_TrajFusionDebugInfo.TRACE_PosSamples = pTrajectoryPosSamples->TRACE_PosSamples;
  #endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
  CP_TrajFusionDebugInfo.FUSED_PosSamples =  FusedPosSamples;

  if(pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly)
  {
    CP_TrajFusionDebugInfo.FUSED_PosSamples.nb_samples = FusedPosSamples.nb_samples;
  }
  CP_v_CallFCTFreezeforCPFusion(&CP_TrajFusionDebugInfo);
#endif
}// PRQA S 7004
 /* date: 2015-04-28, reviewer: Lonard jaison Manohar, reason: Not safety critical */

/*************************************************************************************************************************
  Functionname:    CP_v_CalculateVDYSamples                                                                            */ /*!

  @brief           Calculate VDY samples based on vdy trajectory

  @description     Calculate VDY samples based on vdy trajectory

                   @startuml
                   Partition CP_v_CalculateVDYSamples{
                   Start
                   : Set local curve gradient to 0.0 for sampling;
                   : Minimum number of samples for VDY is always used;
                   End
                   }
                   @enduml

  @return          -

  @param[in,out]   pEGO_PosSamples : VDY Samples based on VDY trajectory
                      fy[i] : Samples of vdy-trajectory in lateral direction                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      nb_samples : Number of available VDY samples                                           [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
  
  @glob_in         pt_CPOutput->CP_CourseData : Structure containing Last cycle course data (VDY trajectory)
  @glob_in         pt_CPInput->t_RTE.pf_SensorYPos : Sensor mounting lateral position.                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    146: doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-146-00061542 \n
  
  @created         -
  @changed         2/24/2016

  @author          Christopher Knievel
*************************************************************************************************************************/
static void CP_v_CalculateVDYSamples(SLATE_t_PosSamples * pEGO_PosSamples)
{
  CP_t_CourseData CourseDataLocal = pt_CPOutput->CP_CourseData;// PRQA S 1031
  /* date: 2015-04-28, reviewer: Lonard jaison M, reason: Allowed in later versions of ISO C99 */
  uint8 i;
  const float32 f_yDistAtX = (CP_MAX_DIST_NEAR_RANGE * (TAN_(DEG2RAD(CP_MAX_ANGLE_NEARRANGE_FOV))) + *pt_CPInput->t_RTE.pf_SensorYPos);
  float32 f_Abs_PosSamples_fy;

  /* Set local curve gradient to 0.0 for sampling */
  CourseDataLocal.fCurveGradient = 0.0f;
  CourseDataLocal.SideSlipAngle  = 0.0f;

  CP_v_SamplePosClothApprox(&CourseDataLocal, CPClothApproxType_Automatic, CP_SAMPLEDIST_MAX, pEGO_PosSamples, CP_XDIST_FIRST_SAMPLE_ZERO_OFFSET);
  CP_v_MoveSamplesFromCoGToSensor( pEGO_PosSamples );

  /* Determine maximum number of samples based on curvature. Although VDY provides always 20 samples,
     not all of them are always suitable for the Kalman fitting. TYpically, in narrow curves the first
     samples points will be fitted worse compared to the last samples points, which are beyond the field of view. */
  /* Ensure that a minimum number of samples for VDY is always used */
  pEGO_PosSamples->nb_samples = CP_MIN_NUM_SAMPLES_VDY;
  for (i=CP_MIN_NUM_SAMPLES_VDY; i<CAL_MAX_NB_TRAJ_SAMPLES; i++)
  {    
    f_Abs_PosSamples_fy = fABS(pEGO_PosSamples->fy[i]);
    if(f_Abs_PosSamples_fy < f_yDistAtX)
    {
      pEGO_PosSamples->nb_samples = i + 1;      
    }
    else
    {
      /* Lateral position of VDY samples exceeds field-of-view */
      break;
    }
  }
}

/* @todo: Is this function still needed? Currently no references to it found */
#if 0 && (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    CP_v_FusionMOTraceParallelismCheck                                                                  */ /*!

  @brief           check if Trace is parallel to Curve with C0, C1

  @description     Calc mean and variance -> big variance means not parallel

                   @startuml
                   Partition CP_v_FusionMOTraceParallelismCheck{
                   Start
                   : Get number of lanes;
                   : Initialize Relevant Trace, Ego mean distance, Ego standard deviation,\n Relevant mean distance, Relevant standard deviation;
                   : Get Left and Right Threshold;
                   : Rotate trace point to RE coordinate system;
                   : check if trace is within lanes in ego-vehicles direction;
                   End
                   }
                   @enduml

  @return          -

  @param[in,out]   pResult : Structure describing a moving object's parallelism to our course
                      relevantTrace : Relevant Trace                                           [TRUE,FALSE]
                      fEGODistMean : Ego mean distance                                         [Full range of float32  >= 0.F]
                      fEGODistStdDev : Ego standard deviation                                  [Full range of float32  >= 0.F]
                      fREDistMean : Relevant mean distance                                     [Full range of float32  >= 0.F]
                      fREDistStdDev : Relevant standard deviation                              [Full range of float32  >= 0.F]
  @param[in]       iTr : Trace Id Number     [TraceID_t type as defined in Rte_Type.h]         [0 ... 10]
  @param[in]       pCourseData : Pointer to driven ego course
                      fCurve : Radius of the curve provided by the VDY trajectory              [-1.f ... +1.f]m^-1           

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->uiReferenceToFCTObject : The reference FCT Object Id with given trace id    [0 ... EM_N_OBJECTS-1] 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                      t_FIPRoad.fYawAngle : Yaw angle of road trajectory                                                                 [-100.f .. +100.f] rad/s
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointX[iS] : The X coordinate of given trace ID                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointY[iS] : The Y coordinate of given trace ID                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pt_FIPRoad->t_FIPRoadEstimation.fC1 : Clothoid parameter c1 of road trajectry                                      [-1 ... +1] m^-2
                      pt_FIPRoad->t_FIPRoadEstimation.fC0 : Clothoid parameter c0 of road trajectory                                     [-1 ... +1] m^-1
                      pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatus : Road tracking status                                            [0 ... 7]
  @glob_out        -

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT support for lane matrix FCT Input Preprocessing (FIP)            
  @c_swtich_full   FCT_CFG_ROAD_INPUT                       : FCT support for Road input
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CP_v_FusionMOTraceParallelismCheck(CP_t_RoadAndEgo2MOTraceParallelism * pResult, TraceID_t iTr , const CP_t_CourseData * pCourseData )
{
  /* Defining local variable to reference pointer in function */
  uint8 u_RefToFCTObject= FIP_pt_GetMOTData()->t_MovObjStaticTrace[iTr].uiReferenceToFCTObject;
  sint8 i_NumberOfPoints = FIP_pt_GetMOTData()->t_MovObjStaticTrace[iTr].iNumberOfPoints;

  uint8 iS;
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  float32 fLeftThreshold , fRightThreshold;
#endif
  float32 fEGOmin = 0.0F;
  float32 fEGOmax = 0.0F;
  float32 fREmin = 0.0F;
  float32 fREmax = 0.0F;
  float32 fX,fY;
  CAL_t_TrajRefPoint TrajRefPoint;

  GDBTrafoMatrix2D_t COF2CEGO, COF2CRE;
  /*! Get number of lanes */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const sint8 s_NumberOfLeftLanes = FIP_pt_LM_GetLaneMatrixData()->s_NumOfLaneLeft;
  const sint8 s_NumberOfRightLanes = FIP_pt_LM_GetLaneMatrixData()->s_NumOfLaneRight);
#endif

  /*init*/
  pResult->relevantTrace  = FALSE;
  pResult->fEGODistMean   = 0.0f;
  pResult->fEGODistStdDev = 0.0f;
  pResult->fREDistMean    = 0.0f;
  pResult->fREDistStdDev  = 0.0f;

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  fLeftThreshold  = (MAX(0.0f,((float32)s_NumberOfLeftLanes))+1.0f) * STRASSENBREITE;
  fRightThreshold = (MAX(0.0f,((float32)s_NumberOfRightLanes))+1.0f) * STRASSENBREITE * -1.0F;
#endif

  COF2CRE  = GDBGetTrafoMatrixByAngle(-1.0f * (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle));
  COF2CEGO = GDBGetTrafoMatrixByDisplacement(*SLATE_pf_GetBumperToCoG(), 0.0f); /*Restructuring: To be changed to local variable */
if ( 
    (u_RefToFCTObject <= TRACE_VALID_NO_OBJ_ID) &&
    (i_NumberOfPoints > 0) 
   )
  {
       /* Since we're going to need several divisions with number of points, calculate
    inverse here */
    const float32 InvNoPts = (1.f / i_NumberOfPoints);
    for (iS = 0u; iS < i_NumberOfPoints ; iS ++ )
    {
      fX = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointX[iS];
      fY = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointY[iS];
      GDBmathTrafoPos2D( &COF2CEGO ,&fX, &fY );
      TrajRefPoint = CAL_t_CalculateDistancePoint2Circle  ( fX, fY, pCourseData->fCurve);
      pResult->fEGODistMean   += TrajRefPoint.fDistToTraj;
      pResult->fEGODistStdDev += SQR(TrajRefPoint.fDistToTraj);
      if(fEGOmin>TrajRefPoint.fDistToTraj)
      {
        fEGOmin=TrajRefPoint.fDistToTraj;
      }
      if(fEGOmax<TrajRefPoint.fDistToTraj)
      {
        fEGOmax=TrajRefPoint.fDistToTraj;
      }
      /*rotate tracepoint to RE coordiante system*/
      fX = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointX[iS];
      fY = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointY[iS];

      GDBmathTrafoPos2D( &COF2CRE ,&fX, &fY );
      TrajRefPoint = CAL_t_CalculateDistancePoint2Clothoid(fX, fY, (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC0), (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC1));
      pResult->fREDistMean += TrajRefPoint.fDistToTraj;
      pResult->fREDistStdDev  += SQR(TrajRefPoint.fDistToTraj);
      if(fREmin>TrajRefPoint.fDistToTraj)
      {
        fREmin=TrajRefPoint.fDistToTraj;
      }
      if(fREmax<TrajRefPoint.fDistToTraj)
      {
        fREmax=TrajRefPoint.fDistToTraj;
      }
    }
    pResult->fEGODistMean *= InvNoPts;
    pResult->fREDistMean  *= InvNoPts;

    pResult->fEGODistStdDev =  SQRT_((pResult->fEGODistStdDev * InvNoPts) - SQR(pResult->fEGODistMean));
    pResult->fREDistStdDev  =  SQRT_((pResult->fREDistStdDev  * InvNoPts) - SQR(pResult->fREDistMean));
    /*check if trace is within lanes in ego-vehicles direction*/
    pResult->relevantTrace  = (boolean)(((u_RefToFCTObject < TRACE_VALID_NO_OBJ_ID) && /*Object alive*/ 
                                        (i_NumberOfPoints > CP_PARALLELISM_MIN_LENGTH_TRACE) 
                                          ) /*minimal Length of Trace*/
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
                                          &&
                                          ( ( (pResult->fEGODistMean < fLeftThreshold) && /*within carriageway */
                                              (pResult->fEGODistMean > fRightThreshold) && /*within carriageway */
                                              (pResult->fEGODistStdDev < CP_PARALLELISM_THRESH)
                                            )  /*parallelism*/
                                            ||
                                            ( (pResult->fREDistMean < fLeftThreshold) && /*within carriageway */
                                              (pResult->fREDistMean > fRightThreshold) && /*within carriageway */
                                              ((pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatus) >= CP_PARALLELISM_MIN_RE_TRACKING_STAT) && /*RE available*/
                                              (pResult->fREDistStdDev < CP_PARALLELISM_THRESH)
                                            )
                                          )
#endif
                                        ); /*parallelism*/
  }
}
#endif /* FCT_CFG_ROAD_INPUT */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_t_Traj2MOTraceParallelismCheck                                                                   */ /*!

  @brief           check if Trace is parallel to SA Traj with C0, C1

  @description     Calc mean and variance -> big variance means not parallel

                   @startuml
                   Partition CP_t_Traj2MOTraceParallelismCheck{
                   Start
                   : Get number of lanes;
                   : Initialize relevant Trace, SA mean, SA standard deviation;
                   : Use road's estimation of number of lanes;
                   : Prevent using invalid or negative result under sqrt;
                   : check if trace is within lanes in ego-vehicles direction;
                   End
                   }
                   @enduml

  @return          ret : Structure of type CP_t_Traj2MOTraceParallelism containing
                      relevantTrace            [TRUE,FALSE]
                      fSADistMean              [Full range of float32 >=0]
                      fSADistStdDev            [Full range of float32 >=0]

  @param[in]       iTr : trace index (has to be a valid trace index, that is (iTr < FIP_STATIC_TRACE_NO_OF_TRACES)    [0 ... FIP_STATIC_TRACE_NO_OF_TRACES]

  @glob_in         FIP_pt_GetMovObjStaticTrace(iTr) : funtion returning datatype of type FIP_MovObjStaticTrace_t containing              
                      uiReferenceToFCTObject : The reference FCT Object Id with given trace id    [0 ... EM_N_OBJECTS-1] 
                      iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                      fTracePointX[iS] : The X coordinate of given trace ID                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      fTracePointY[iS] : The Y coordinate of given trace ID                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         CP_pt_GetTrajectoryData() : funtion returning datatype of type CP_t_TrajectoryData containing
                      Current.fTrajC0 : Trajectory clothoid parameter of current cycle                                                         [-1.f ... +1.f]m^-1
                      Current.fTrajC1 : Trajectory clothoid parameter of current cycle                                                         [-1.f ... +1.f]m^-2
  @glob_out        -


  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT support for lane matrix FCT Input Preprocessing (FIP)              
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING             : FCT support for moving object traces
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/25/2016

  @todo            Remove the direct access of FIP and FCT_Sen access functions after trace parallelism is given out as CP output

  @author          Jochen Spruck,  jochen.spruck@contiautomotive.com
*************************************************************************************************************************/
CP_t_Traj2MOTraceParallelism CP_t_Traj2MOTraceParallelismCheck(TraceID_t iTr)
{
  /* Defining local variable to reference pointer in function */
  FIP_MovObjStaticTrace_t t_LocalTraceCopy = FIP_pt_GetMOTData()->t_MovObjStaticTrace[iTr]; //PRQA S 1031
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Allowed in later versions of ISO C99 */
  CP_t_TrajectoryData t_LocalTrajCopy = *(CP_pt_GetTrajectoryData()); //PRQA S 1031
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Allowed in later versions of ISO C99 */
  
  CP_t_Traj2MOTraceParallelism ret;
  sint32 iS;
  float32 fLeftThreshold , fRightThreshold;
  float32 fSAmin = 0.0F;
  float32 fSAmax = 0.0F;
  float32 fX,fY;
  float32 fStdDevTemp = 0.0F;
  float32 fBumperToCoG;
  CAL_t_TrajRefPoint TrajRefPoint;
  GDBTrafoMatrix2D_t COF2CEGO;
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /*! Get number of lanes */
  const sint8 s_NumberOfLeftLanes = FIP_pt_LM_GetLaneMatrixData()->s_NumOfLaneLeft;
  const sint8 s_NumberOfRightLanes = FIP_pt_LM_GetLaneMatrixData()->s_NumOfLaneRight;
#endif

  /*init*/
  ret.relevantTrace   = FALSE;
  ret.fSADistMean     = 0.0f;
  ret.fSADistStdDev   = 0.0f;

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Use road's estimation of number of lanes */
  fLeftThreshold  = (MAX(0.0f,((float32)s_NumberOfLeftLanes))+1.0f) * STRASSENBREITE;
  fRightThreshold = (MAX(0.0f,((float32)s_NumberOfRightLanes))+1.0f) * STRASSENBREITE * -1.0F;
#else
  /* Road not available, always assume 1 lane left/right */
  fLeftThreshold  = (STRASSENBREITE);
  fRightThreshold = (STRASSENBREITE * -1.0F);
#endif
  fBumperToCoG = *SLATE_pf_GetBumperToCoG();
  COF2CEGO = GDBGetTrafoMatrixByDisplacement( fBumperToCoG , 0.0f); /*Restructuring: To be changed to local variable*/

  if (
    (t_LocalTraceCopy.uiReferenceToFCTObject <= FIP_u_TRACE_VALID_NO_OBJ_ID) &&
    (t_LocalTraceCopy.iNumberOfPoints > 0) 
     )
  {
    for (iS = 0; iS < t_LocalTraceCopy.iNumberOfPoints ; iS ++ )
    {
      fX = t_LocalTraceCopy.fTracePointX[iS];
      fY = t_LocalTraceCopy.fTracePointY[iS];
      GDBmathTrafoPos2D( &COF2CEGO ,&fX, &fY );
      TrajRefPoint = CAL_t_CalculateDistancePoint2Clothoid(fX, fY, t_LocalTrajCopy.Current.fTrajC0, t_LocalTrajCopy.Current.fTrajC1);

      ret.fSADistMean += TrajRefPoint.fDistToTraj;
      ret.fSADistStdDev  += SQR(TrajRefPoint.fDistToTraj);
      if(fSAmin>TrajRefPoint.fDistToTraj)
      {
        fSAmin=TrajRefPoint.fDistToTraj;
      }
      if(fSAmax<TrajRefPoint.fDistToTraj)
      {
        fSAmax=TrajRefPoint.fDistToTraj;
      }
    }
    ret.fSADistMean  /= (float32)t_LocalTraceCopy.iNumberOfPoints;
    /* Prevent using invalid or negative result under sqrt */
    fStdDevTemp = (ret.fSADistStdDev/(float32)t_LocalTraceCopy.iNumberOfPoints)  - SQR(ret.fSADistMean);
    if(fStdDevTemp > CAL_INFINITE_DIST)
    {
      fStdDevTemp = CAL_INFINITE_DIST;
    }
    else
    {
      /* do nothing */
    }
    if(fStdDevTemp >= C_F32_DELTA)
    {
      ret.fSADistStdDev  =  SQRT_(fStdDevTemp);
    }
    else
    {
      ret.fSADistStdDev = C_F32_DELTA;
    }
    /*check if trace is within lanes in ego-vehicles direction*/
    ret.relevantTrace    = (boolean)( ( 
                                  (t_LocalTraceCopy.uiReferenceToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID) && /*Object alive*/ 
                                  (t_LocalTraceCopy.iNumberOfPoints > CP_EXTOBJAPPROX_PARALLELISM_MIN_LENGTH_TRACE)  /*minimal Length of Trace*/
                                     )
                                     &&
                                     ( (ret.fSADistMean < fLeftThreshold) &&     /*within carriageway */
                                       (ret.fSADistMean > fRightThreshold) &&    /*within carriageway */
                                       (ret.fSADistStdDev < CP_PARALLELISM_THRESH)  /*parallelism*/
                                     )
                                   ); /*parallelism*/
                                    

  }
  return ret;
}
#endif /*(FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

#if (FCT_CFG_ROAD_INPUT || FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_v_FusePosSamples                                                                                 */ /*!

  @brief           Fusion of two Gaussian random samples

  @description     Fusion of two Gaussian random samples based on the standard equation
                   for the mean value: 
                  
                                mu_fus    = (sum_i (mu_i/sigma^2_i)) / (sum(1/sigma^2_i))

                                sigma_fus = 1 / (sum_i (1/sigma^2_i))

                   @startuml
                   Partition CP_v_FusePosSamples{
                   Start
                   : Determine maximum fusion distance;
                   : Calculate weighting factor as a function of variance;
                   : Calculate mean of combined random sample;
                   : Calculate variance of combined random sample;
                   End
                   }
                   @enduml

  @return          -

  @param[in,out]   Samples : Samples of Gaussian source A ~ N(mu_A,sigma_A)
                      fx[i] : x-position of tarjectory sample                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      fy[i] : y-position of tarjectory sample                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      fVar[i] : variance information of trajectory samples                   [Full range of float32  >= 0.F] 
                      nb_samples : Number of samples                                         [0u ... CAL_MAX_NB_TRAJ_SAMPLES]
  @param[in]       MeasSamples : Samples of Gaussian source B ~ N(mu_B,sigma_B)
                      fx[i] : x-position of tarjectory sample                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      fy[i] : y-position of tarjectory sample                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      fVar[i] : variance information of trajectory samples                   [Full range of float32  >= 0.F]
                      nb_samples : Number of samples                                         [0u ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ROAD_INPUT                  : FCT Interface for road input
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT Interface for Moving object traces
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/25/2016

  @author          Christopher Knievel
*************************************************************************************************************************/
static void CP_v_FusePosSamples(SLATE_t_PosSamples * const Samples, const SLATE_t_PosSamples * const MeasSamples)
{
  uint32 i;
  uint32 fMaxFusionDist;

  /* Determine maximum fusion distance */
  fMaxFusionDist = MIN(Samples->nb_samples,MeasSamples->nb_samples);

  for (i=0u; i<fMaxFusionDist; i++)
  {
    /* Calculate weighting factor as a function of variance */
    const float32 fWeight = Samples->fVar[i] / (Samples->fVar[i] + MeasSamples->fVar[i]);

    /* Calculate mean of combined random sample */
    Samples->fx[i] = Samples->fx[i] + ((fWeight) * (MeasSamples->fx[i] - Samples->fx[i]));
    Samples->fy[i] = Samples->fy[i] + ((fWeight) * (MeasSamples->fy[i] - Samples->fy[i]));

    /* Calculate variance of combined random sample */
    Samples->fVar[i] = (Samples->fVar[i] * MeasSamples->fVar[i]) / (Samples->fVar[i] + MeasSamples->fVar[i]);
  }
}
#endif /* (FCT_CFG_ROAD_INPUT || FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

/*************************************************************************************************************************
  Functionname:    CP_v_SampleGradFromCourse                                                                           */ /*!

  @brief           Sample Gradient from the course data

  @description     Sample Gradient from the course data

                   @startuml
                   Partition CP_v_SampleGradFromCourse{
                   Start
                   : Get x-position, gradient at x-position, Minimum and Maximum standard deviation\n of gradient at x-position of trajectory sample;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pCourseData : Course data structure
                      fCurve : Radius of the curve provided by the VDY trajectory                                    [-1.f ... +1.f]m^-1 
  @param[in,out]   pSamples : Output sample points
                      fx[i] : x-position of tarjectory sample                                                        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] 
                      fdydx[i] : gradient at x-position of trajectory sample                                         [Full range of float32  >= 0.F]
                      fdydxMinStdDev[i] : Minimum standard deviation of gradient at x-position of trajectory sample  [Full range of float32  >= 0.F] 
                      fdydxMaxStdDev[i] : Maximum standard deviation of gradient at x-position of trajectory sample  [Full range of float32  >= 0.F] 
                      valid[i] : Boolean to decide whether sample is valid or not                                    [TRUE,FALSE]

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pf_EgoLongVel : Longitudinal velocity of ego vehicle                                     [-330.f ... 330.f]m/s
                      t_RTE.pf_FCTBumperToCoG : Distance from Bumper to Center of Gravity                            [-100.f ... 100.f] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/25/2016

  @todo            Currently unused, check and delete the fucntion

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
/*
static void CP_v_SampleGradFromCourse(const CP_t_CourseData * pCourseData , CAL_t_GradSamples *pSamples)
{
  uint32 i;
  float32 x_s = 0.0F;
  const float32 x_max = MINMAX(CP_SAMPLEDIST_MIN,CP_SAMPLEDIST_MAX,CP_SAMPLETIMEDIST * (*pt_CPInput->t_RTE.pf_EgoLongVel));
  const float32 x_inc = x_max/(float32)CAL_MAX_NB_TRAJ_SAMPLES;
  const float32 fPlausibleC1 = CP_f_GetCourseGradUpdateSTDC1AtSpeed(*pt_CPInput->t_RTE.pf_EgoLongVel);

  for( i = 0u; i < CAL_MAX_NB_TRAJ_SAMPLES; i++ )
  {    
    generate CAL_MAX_NB_TRAJ_SAMPLES 200m along Course
    x_s += x_inc;
    pSamples->fx[i] = x_s - *pt_CPInput->t_RTE.pf_FCTBumperToCoG;
    pSamples->fdydx[i] = pCourseData->fCurve*x_s;
    pSamples->fdydxMinStdDev[i] = (0.5f*SQR(x_s)*fPlausibleC1) + CP_GRADUPDATE_STD_MIN;
    pSamples->fdydxMaxStdDev[i] = pSamples->fdydxMinStdDev[i];
    pSamples->valid[i] = 2u;
  }  
}
*/

/*************************************************************************************************************************
  Functionname:    CP_t_ClothApproxByPolynom                                                                           */ /*!

  @brief           Approximates Clothoid by third order polynom

  @description     Approximates Clothoid by third order polynom

                   @startuml
                   Partition CP_t_ClothApproxByPolynom{
                   Start
                   : Get X and Y distance ;
                   : Return Clothoid by third order polynom;
                   End
                   }
                   @enduml

  @return          sRes : Return of type Vector2_f32_t
                      fXDist : X distance                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fYDist : Y distance                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       fC0 : Curvature of Clothoid                       [-1 ... +1] m^-2
  @param[in]       fC1 : Gradient of Clothoid                        [-1 ... +1] m^-2
  @param[in]       fYawAngle : Ego vehicle yaw angle                 [-PI ... +PI]rad
  @param[in]       fDistOnCloth : Evaluation Distance on Clothoid    [Full range of float32  >= 0.F]
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/25/2016
  @changed         2/25/2016

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
static Vector2_f32_t CP_t_ClothApproxByPolynom(const float32 fC0, const float32 fC1, const float32 fYawAngle, const float32 fDistOnCloth)
{
  float32       fX, fXX, fXXX, fY;
  Vector2_f32_t sRes;

  fX   = fDistOnCloth; /* Approximation of X Value */
  fXX  = fX * fX;
  fXXX = fX * fXX;

  fY   = ((1.f/6.f) * fC1 * fXXX) + ((1.f/2.f) * fC0 *fXX) + (fYawAngle * fX);

  sRes.fXDist = fX;
  sRes.fYDist = fY;

  return sRes;
}

/*************************************************************************************************************************
  Functionname:    CP_t_ClothApproxByCircle                                                                            */ /*!

  @brief           Approximates Clothoid by Circle

  @description     Approximates Clothoid by Circle

                   @startuml
                   Partition CP_t_ClothApproxByCircle{
                   Start
                   : Get X and Y distance ;
                   : Return Clothoid by Circle;
                   End
                   }
                   @enduml

  @return          sRes : Return of type Vector2_f32_t
                      fXDist : X distance                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fYDist : Y distance                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       fC0 : Curvature of Clothoid                       [-1.f ... +1.f]m^-1 
  @param[in]       fDistOnCloth : Evaluation Distance on Clothoid    [Full range of float32  >= 0.F]
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/25/2016

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
static Vector2_f32_t CP_t_ClothApproxByCircle(const float32 fC0, const float32 fDistOnCloth)
{
  float32       fX, fY, fRadius;
  Vector2_f32_t sRes;

  fRadius = 1.0f / fC0;

  fX   =  fRadius * CML_cos66(fDistOnCloth);
  fY   = (fRadius * CML_sin66(fDistOnCloth) ) + fRadius;
  
  sRes.fXDist = fX;
  sRes.fYDist = fY;

  return sRes;
}

/*************************************************************************************************************************
  Functionname:    CP_v_SamplePosClothApprox                                                                           */ /*!

  @brief           Calculate the (x,y)-Coordinates of the given CourseData ether by circle or polynomial clothoid-approximation.

  @description     Calculate the (x,y)-Coordinates of the given CourseData ether by circle or polynomial clothoid-approximation.

                   @startuml
                   Partition CP_v_SamplePosClothApprox{
                   Start
                   If (Type of clothoid approximation is Automatic) then (TRUE)
                   If (Radius of the curve is greater than\n Curvature Circle Equation) then (TRUE)
                   : Update Selected Type of clothoid approximation with Circle Only;
                   Else (FALSE)
                   : Update Selected Type of clothoid approximation with Polynomial Only;
                   Endif
                   Else (FALSE)
                   : Update Selected Type of clothoid approximation with\n Type of clothoid approximation;
                   Endif
                   Note right
                   Start sampling
                   End note
                   If (Type of clothoid approximation is Polynomial Only) then (TRUE)
                   : do sampling with polynomial approximation;
                   Elseif (Type of clothoid approximation is Circle Only) then (TRUE)
                   : do sampling with circle approximation;
                   Else (FALSE)
                   : selectedApproxType has unsupported Content;
                   Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       pCPCourseData : pointer to course data structure
                      fCurve fCurve : Radius of the curve provided by the VDY trajectory     [-1.f ... +1.f]m^-1
                      fCurveGradient : Curvature Gradient of ego vehicle path                [-1.f ... +1.f]m^-2
                      SideSlipAngle : Side slip angle of ego vehicle                         [-PI ... +PI] rad
  @param[in]       CPClothApproxType : Type of clothoid approximation                        [CP_t_ClothApproxType as defined in xp.h]
  @param[in]       fSampleDistMax : Maximum distance of a sample                             [0 ... CP_SAMPLEDIST_MAX]
  @param[in,out]   pCPPosSamples : Structure storing position samples of trajectories
                      fx[i] : x-position of tarjectory sample                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      fy[i] : y-position of tarjectory sample                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      nb_samples : Number of samples                                         [0u ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/25/2016

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
void CP_v_SamplePosClothApprox(const CP_t_CourseData *pCPCourseData, const CP_t_ClothApproxType CPClothApproxType, const float32 fSampleDistMax, SLATE_t_PosSamples *pCPPosSamples, float32 fXDistFirstSample)
{
  uint32 i;
  float32 x_inc   = 0.0f;
  float32 x_s     = fXDistFirstSample;
  float32 t_inc   = 0.0f;
  float32 t_s     = 0.0f;
  float32 fRadius = 0.0f;
  float32 fMaxArclength;
  float32 f_Abs_Curve = fABS(pCPCourseData->fCurve);

  CP_t_ClothApproxType selectedApproxType;

  
  /* Figure out which Approximation (polynomial or circle) to use */
  if ( CPClothApproxType == CPClothApproxType_Automatic )
  {
    if ( f_Abs_Curve > CAL_CURVATURE_USE_CIRCLE_EQUATION )
    {
      selectedApproxType = CPClothApproxType_CircleOnly;
    }
    else
    {
      selectedApproxType = CPClothApproxType_PolynomialOnly;
    }
  }
  else
  {
    selectedApproxType = CPClothApproxType;
  }
  

  /* Start sampling */
  switch(selectedApproxType)
  {
  case CPClothApproxType_PolynomialOnly:
    /* do sampling with polynomial approximation */
    x_inc = ( fSampleDistMax / (float32)CAL_MAX_NB_TRAJ_SAMPLES );
    
    for( i=0u; i < CAL_MAX_NB_TRAJ_SAMPLES; i++ )
    {
      Vector2_f32_t vCoordsTemp;

      x_s += x_inc;
      vCoordsTemp = CP_t_ClothApproxByPolynom(pCPCourseData->fCurve, pCPCourseData->fCurveGradient, pCPCourseData->SideSlipAngle, x_s);

      pCPPosSamples->fx[i] = vCoordsTemp.fXDist;
      pCPPosSamples->fy[i] = vCoordsTemp.fYDist;
    }
    break;
  case CPClothApproxType_CircleOnly:
    /* do sampling with circle approximation */
    t_s = -C_PI/2.F;
    fRadius = 1.F/pCPCourseData->fCurve;
    fMaxArclength = (2.F*fABS(fRadius))*(C_PI/5.F);
    fMaxArclength = MIN_FLOAT(fSampleDistMax, fMaxArclength);
    t_inc = (fMaxArclength * (1.0f /(float32)CAL_MAX_NB_TRAJ_SAMPLES))*pCPCourseData->fCurve;

    for( i=0u; i < CAL_MAX_NB_TRAJ_SAMPLES; i++ )
    {
      Vector2_f32_t vCoordsTemp;

      t_s += t_inc;
      vCoordsTemp = CP_t_ClothApproxByCircle(pCPCourseData->fCurve, t_s);

      pCPPosSamples->fx[i] = vCoordsTemp.fXDist;
      pCPPosSamples->fy[i] = vCoordsTemp.fYDist;
    }
    break;
  default:
    /* selectedApproxType has unsupported Content */
    break;

  }

  pCPPosSamples->nb_samples = CAL_MAX_NB_TRAJ_SAMPLES;
}

/*************************************************************************************************************************
  Functionname:    CP_v_LimitSamplesXDist                                                                              */ /*!

  @brief           Limit Samples to a given X Distance

  @description     Limit Samples to a given X Distance

                   @startuml
                   Partition CP_v_LimitSamplesXDist{
                   Start
                   If (x-position of trajectory sample less than\n Maximum Distance) then (TRUE)
                   : Get Number of samples;
                   Else (FALSE)
                   Endif 
                   End 
                   }
                   @enduml


  @return          -

  @param[in]       fXDistMax : Maximum X Distance                                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in,out]   pCPPosSamples : Samples to be moved
                      fx[i] : x-position of tarjectory sample                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      nb_samples : Number of samples                                         [0u ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/25/2016

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
void CP_v_LimitSamplesXDist( const float32 fXDistMax, SLATE_t_PosSamples *pCPPosSamples )
{
  uint32 i;
  uint8  uiNbSamplesNew = 0U;  

  for( i=0u; i < pCPPosSamples->nb_samples; i++ )
  {
    if( pCPPosSamples->fx[i] < fXDistMax )
    {
      uiNbSamplesNew++;
    }
  }

  pCPPosSamples->nb_samples = uiNbSamplesNew;
}

/*************************************************************************************************************************
  Functionname:    CP_v_MoveSamplesFromCoGToSensor                                                                     */ /*!

  @brief           Moves Samples From CoG To Sensor

  @description     Moves Samples From CoG To Sensor

                   @startuml
                   Partition CP_v_MoveSamplesFromCoGToSensor{
                   Start
                   : Get x-position of tarjectory sample;
                   End
                   }
                   @enduml

  @return          -

  @param[in,out]   pCPPosSamples : Samples to be moved
                      fx[i] : x-position of tarjectory sample                                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      nb_samples : Number of samples                                                [0u ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         pt_CPInput->t_RTE.pf_FCTBumperToCoG : Distance from Bumper to Center of Gravity  [-100.f ... 100.f] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
void CP_v_MoveSamplesFromCoGToSensor( SLATE_t_PosSamples *pCPPosSamples )
{
  uint32 i;

  for( i=0u; i < pCPPosSamples->nb_samples; i++ )
  {
    pCPPosSamples->fx[i] = pCPPosSamples->fx[i] - *pt_CPInput->t_RTE.pf_FCTBumperToCoG;
  }
}

#if (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    CP_t_GetRoadEstimationAsCourseData                                                                  */ /*!

  @brief           Moves Samples From CoG To Sensor

  @description     Moves Samples From CoG To Sensor

                   @startuml
                   Partition CP_t_GetRoadEstimationAsCourseData{
                   Start
                   :  Get Curve of the trajectory, Curvature Gradient, Curvature variance\n of ego vehicle path, Side slip angle and Side slip angle variance of ego vehicle;
                   : Returns Course data;
                   End
                   }
                   @enduml

  @return          CourseDataResult : Returns Course data structure
                      fCurve : Curve of the trajectory                                  [-1.f ... +1.f]m^-1
                      fCurveGradient : Curvature Gradient of ego vehicle path           [-1.f ... +1.f]m^-2
                      fCurveVar : Curvature variance of ego vehicle path                [-1.f ... +1.f]m^-1
                      SideSlipAngle : Side slip angle of ego vehicle                    [-PI ... +PI] rad
                      SideSlipAngleVariance : Side slip angle variance of ego vehicle   [-PI ... +PI] rad

  @param[in]       -
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure
                      pt_FIPRoad->t_FIPRoadEstimation.fC0 : Curvature of Clothoid       [-1 ... +1] m^-2
                      pt_FIPRoad->t_FIPRoadEstimation.fC1 : Gradient of Clothoid        [-1 ... +1] m^-2
                      pt_FIPRoad->t_FIPRoadEstimation.fYawAngle : Ego vehicle yaw angle [-PI ... +PI]rad                 
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ROAD_INPUT : FCT support for Road input
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author           Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
CP_t_CourseData CP_t_GetRoadEstimationAsCourseData(void)
{
  CP_t_CourseData CourseDataResult;

  CourseDataResult.fCurve                = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC0;
  CourseDataResult.fCurveGradient        = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC1;
  CourseDataResult.fCurveVar             = 0.f;
  CourseDataResult.SideSlipAngle         = pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle;
  CourseDataResult.SideSlipAngleVariance = 0.f;

  return CourseDataResult;
}
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

#if(FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_t_GetTraceEstimationAsCourseData                                                                 */ /*!

  @brief           Get trace estimation in correct format as coursedata

  @description     Get trace estimation in correct format as coursedata

                   @startuml
                   Partition CP_t_GetTraceEstimationAsCourseData{
                   Start
                   :  Initialize Curve of the trajectory, Curvature Gradient, Curvature variance\n of ego vehicle path, Side slip angle and Side slip angle variance of ego vehicle;
                   : Returns Course data;
                   End
                   }
                   @enduml

  @return          CourseDataResult : Returns Course data structure
                      fCurve : Curve of the trajectory                                  [-1.f ... +1.f]m^-1
                      fCurveGradient : Curvature Gradient of ego vehicle path           [-1.f ... +1.f]m^-2
                      fCurveVar : Curvature variance of ego vehicle path                [-1.f ... +1.f]m^-1
                      SideSlipAngle : Side slip angle of ego vehicle                    [-PI ... +PI] rad
                      SideSlipAngleVariance : Side slip angle variance of ego vehicle   [-PI ... +PI] rad

  @param[in]       pTraceTrajectory : Trace trajectory structure
                      fCurve : Curve of the trajectory                                  [-1.f ... +1.f]m^-1
                    
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Moving Object Traces
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure FCT support for CP sub-component
                   
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Christopher Knievel
*************************************************************************************************************************/
CP_t_CourseData CP_t_GetTraceEstimationAsCourseData(const CP_t_TraceTrajectory * pTraceTrajectory)
{
  CP_t_CourseData CourseDataResult;

  CourseDataResult.fCurve                = pTraceTrajectory->fCurve;
  CourseDataResult.fCurveGradient        = 0.f;
  CourseDataResult.fCurveVar             = 0.f;
  CourseDataResult.SideSlipAngle         = 0.f;
  CourseDataResult.SideSlipAngleVariance = 0.f;

  return CourseDataResult;
}
#endif

/*************************************************************************************************************************
  Functionname:    CP_f_GetCourseVariance                                                                              */ /*!

  @brief           Return the time-gap dependent variance of the VDY course

  @description     Functional approximation of the lateral estimation error of the VDY course w.r.t. the ground 
                   truth. Estimation errors are obtained by a simulation with ARS400 data and the corresponding 
                   variance is calculated afterwards. Since the variance depends on the time-gap, an approximated 
                   function is used to express the relation of variance and time-gap.

                   @startuml
                   Partition CP_f_GetCourseVariance{
                   Start
                   If (Ego Velocity greater than Minimum ego velocity\n for variance calculation) then (TRUE)
                   : Compute time-gap;
                   Else (FALSE)
                   : Get maximum time-gap;
                   Endif
                   : Calculate the square of the time;
                   If (Time gap less than Time-gap limit by first segment) then (TRUE)
                   : For low time-gap values approximation by power function with exponent 3;
                   Else (FALSE)
                   : For high time-gap values approximation by power function with exponent 4.5;
                   Endif
                   : Return Time-gap dependent variance of the VDY course;
                   End
                   }
                   @enduml

  @return          f_Var : Time-gap dependent variance of the VDY course [Full range of float32  >= 0.F]

  @param[in]       f_DistX : longitudinal distance of the sample [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_EgoSpeedCorrected : ego velocity            [-330.f ... 330.f] m/s

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   -

  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         17.02.2016


  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
float32 CP_f_GetCourseVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected)
{
  float32 f_TimeGap,f_SQR_TimeGap;
  float32 f_Var;

  if(f_EgoSpeedCorrected > CP_TRAJ_VAR_EGO_VEL_MIN) /* Prevent division by zero */
  {
    /* Compute time-gap */
    f_TimeGap = fABS(f_DistX) / f_EgoSpeedCorrected;
  }  
  else
  {
    /* Get maximum time-gap 
       If speed is almost zero, then a large time will result in a large variance */
    f_TimeGap = CP_TRAJ_VAR_TIMEGAP_MAX;
  }

  /* Calculate the square of the time */
  f_SQR_TimeGap = SQR(f_TimeGap);

  /* Two-segmented variance approximation.
     For the time-gap 0s to 1s and above 1s different approximations are used. */
  if(f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_LOW)
  {
    /* For low time-gap values approximation by power function with exponent 3 */
    f_Var = (CP_VDY_COURSE_VAR_COEFF_LOW * f_SQR_TimeGap * f_TimeGap) + CP_TRAJ_VAR_OFFSET;
  }
  else
  {
    /* For high time-gap values approximation by power function with exponent 4.5 */
    f_Var = (CP_VDY_COURSE_VAR_COEFF_LOW * f_SQR_TimeGap * f_SQR_TimeGap* SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
  }

  return f_Var;
}

/*************************************************************************************************************************
  Functionname:    CP_f_GetTraceTrajVariance                                                                           */ /*!

  @brief           CP_f_GetRoadVariance
  @brief           Return the time-gap dependant variance of the trace trajectory course

  @description     Functional approximation of the lateral estimation error of the trace trajectory course w.r.t. the 
                   ground truth. Estimation errors are obtained by a simulation with ARS400 data and the corresponding 
                   variance is calculated afterwards. Since the variance depends on the time-gap, an approximated 
                   function is used to express the relation of variance and time-gap.
                   Different approximation functions are used for highway and country road scenarios. 

                   @startuml
                   Partition CP_f_GetTraceTrajVariance{
                   Start
                   If (Ego Velocity greater than Minimum ego velocity\n for variance calculation) then (TRUE)
                   : Compute time-gap;
                   Else (FALSE)
                   : Get maximum time-gap;
                   Endif
                   : Calculate the square of the time;
                   : Use different approximation functions of the variance for highways and country road;
                   If (Ego velocity less than Maximum ego velocity AND\n Road Type not HIGHWAY) then (TRUE)
                   If (Time gap less than Time-gap limit by first segment) then (TRUE)
                   : For low time-gap values approximation by power function with exponent 3;
                   Elseif (Time gap less than Time-gap limit by second segment) then (TRUE)
                   :For mid time-gap values approximation by power function with exponent 3.5;
                   Else (FALSE)
                   : For high time-gap values approximation by power function with exponent 5;
                   Endif
                   Else (FALSE)
                   : Approximation by power function with exponent 3.5;
                   Endif
                   End
                   }
                   @enduml


  @return          f_Var : Time-gap dependent variance of the trace trajectory course [Full range of float32  >= 0.F]

  @param[in]       f_DistX : longitudinal distance of the sample [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_EgoSpeedCorrected : ego velocity            [-330.f ... 330.f] m/s

  @glob_in         pt_CPInput : Pointer to CP input structure
                      pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type [Full range of FIP_t_FusedRoadType as defned in fip_ext.h]
                      t_RTE.pf_EgoCurve : ego curvature                           [-1.f ... +1.f] m^-1
  @glob_out        - 

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_COURSE_PREDICTION    : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         17.02.2016


  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static float32 CP_f_GetTraceTrajVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected)
{
  float32 f_TimeGap,f_SQR_TimeGap;
  float32 f_Var;
  float32 f_ABS_pf_EgoCurve; /* For calculating ABS value */

#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_t_FusedRoadType t_RoadTypeLevel_1 = pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType;
#else
  const FIP_t_FusedRoadType t_RoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
#endif

  if(f_EgoSpeedCorrected > CP_TRAJ_VAR_EGO_VEL_MIN) /* Prevent division by zero */
  {
    /* Compute time-gap */
    f_TimeGap = fABS(f_DistX) / f_EgoSpeedCorrected;
  }  
  else
  {
    /* Get maximum time-gap.
       If speed is almost zero, then a large time will result in a large variance */
    f_TimeGap = CP_TRAJ_VAR_TIMEGAP_MAX;
  }

  /* Calculate the square of the time */
  f_SQR_TimeGap = SQR(f_TimeGap);

    /* Use different approximation functions of the variance for highways and country road */
  f_ABS_pf_EgoCurve = fABS(*pt_CPInput->t_RTE.pf_EgoCurve);	
  if ( ( (f_EgoSpeedCorrected < CP_TRACE_TRAJ_VEGO_MAX_COUNTRY)
      && (t_RoadTypeLevel_1 != FIP_ROAD_TYPE_HIGHWAY)
       )
    || (f_ABS_pf_EgoCurve > CP_TRACE_TRAJ_CURVE_MAX_HIGHWAY)
     )
  {
    /* Three-segmented variance approximation for country road and the rest.
     For the time-gap 0s-1s, 1s-4s and above 4s different approximations are used. */
    if(f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_LOW)
    {
      /* For low time-gap values approximation by power function with exponent 3 */
      f_Var = (CP_TRACE_TRAJ_COURSE_VAR_COEFF_COUNTRY_LOW * f_SQR_TimeGap * f_TimeGap) + CP_TRAJ_VAR_OFFSET;
    }
    else if (f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_MID)
    {
      /* For mid time-gap values approximation by power function with exponent 3.5 */
      f_Var = (CP_TRACE_TRAJ_COURSE_VAR_COEFF_COUNTRY_LOW * f_SQR_TimeGap * f_TimeGap * SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
    }
    else
    {
      /* For high time-gap values approximation by power function with exponent 5 */
      f_Var = (CP_TRACE_TRAJ_COURSE_VAR_COEFF_COUNTRY_HIGH * f_SQR_TimeGap * f_SQR_TimeGap * f_TimeGap) + CP_TRAJ_VAR_OFFSET;
    }
  }
  else
  {
    /* One-segmented variance approximation for highways.
     For the whole time-gap one single function approximation is used. */
    /* Approximation by power function with exponent 3.3 */
     f_Var = (CP_TRACE_TRAJ_COURSE_VAR_COEFF_HIGHWAY * CML_f_xPowY(f_TimeGap,CP_TRACE_TRAJ_COURSE_VAR_POW_HIGHWAY)) + CP_TRAJ_VAR_OFFSET;
  }
  return f_Var;
}

#if (CP_CFG_LANE_CHG_CAM_FUSION)
/*************************************************************************************************************************
  Functionname:    CP_f_GetCamVariance                                                                           */ /*!

  @brief           Return the time-gap dependant variance of the camera trajectory course

  @description     Functional approximation of the lateral estimation error of the camera trajectory course w.r.t. the 
                   ground truth. Estimation errors are obtained by a simulation with ARS430 data and the corresponding 
                   variance is calculated afterwards. Since the variance depends on the time-gap, an approximated 
                   function is used to express the relation of variance and time-gap.

                   @startuml
                   Partition CP_f_GetCamTrajVariance{
                   Start
                   If (Ego Velocity greater than Minimum ego velocity\n for variance calculation) then (TRUE)
                   : Compute time-gap;
                   Else (FALSE)
                   : Get maximum time-gap;
                   Endif
                   : Calculate the square of the time;
                   If (Time gap less than Time-gap limit by first segment) then (TRUE)
                   : For low time-gap values approximation by power function with exponent 3,5;
                   Elseif (Time gap less than Time-gap limit by second segment) then (TRUE)
                   : For mid time-gap values approximation by power function with exponent 3.5,
                   Else (FALSE)
                   : For high time-gap values approximation by power function with exponent 6;
                   Endif
                   : Return Time-gap dependent variance of the VDY course;
                   End
                   }
                   @enduml

  @return          f_Var : Time-gap dependent variance of the camera trajectory course [Full range of float32  >= 0.F]

  @param[in]       f_DistX : longitudinal distance of the sample [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_EgoSpeedCorrected : ego velocity            [-330.f ... 330.f] m/s

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pf_EgoCurve : ego curvature                           [-1.f ... +1.f] m^-1
  @glob_out        - 

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_COURSE_PREDICTION    : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         21.02.2018


  @author          Steffen Luis | steffen.luis@continental-corporation.com
*************************************************************************************************************************/
static float32 CP_f_GetCamTrajVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected)
{
  float32 f_TimeGap,f_SQR_TimeGap;
  float32 f_Var;

  if(f_EgoSpeedCorrected > CP_TRAJ_VAR_EGO_VEL_MIN) /* Prevent division by zero */
  {
    /* Compute time-gap */
    f_TimeGap = fABS(f_DistX) / f_EgoSpeedCorrected;
  }  
  else
  {
    /* Get maximum time-gap.
       If speed is almost zero, then a large time will result in a large variance */
    f_TimeGap = CP_TRAJ_VAR_TIMEGAP_MAX;
  }

  /* Calculate the square of the time */
  f_SQR_TimeGap = SQR(f_TimeGap);

  /* Three-segmented variance approximation for country road and the rest.
  For the time-gap 0s-1s, 1s-4s and above 4s different approximations are used. */
  if(f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_LOW)
  {
    /* For low time-gap values approximation by power function with exponent 3,5*/
    f_Var = (CP_CAM_COURSE_VAR_COEFF_LOW * f_TimeGap * f_SQR_TimeGap * SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
  }
  else if (f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_MID)
  {
    /* For mid time-gap values approximation by power function with exponent 3,5 */
    f_Var = (CP_CAM_COURSE_VAR_COEFF_LOW * f_TimeGap * f_SQR_TimeGap * SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
  }
  else
  {
    /* For high time-gap values approximation by power function with exponent 6 */
    f_Var = (CP_CAM_COURSE_VAR_COEFF_HIGH * f_SQR_TimeGap * f_SQR_TimeGap * f_SQR_TimeGap) + CP_TRAJ_VAR_OFFSET;
  }

  return f_Var;
}
#endif /* END IF (CP_CFG_LANE_CHG_CAM_FUSION) */
/*************************************************************************************************************************
  Functionname:    CP_f_GetRoadVariance                                                                                */ /*!

  @brief           Return the time-gap dependent variance of the road course

  @description     Functional approximation of the lateral estimation error of the road course w.r.t. the ground 
                   truth. Estimation errors are obtained by a simulation with ARS400 data and the corresponding 
                   variance is calculated afterwards. \n\n 
                   Since the variance depends on the time-gap, an approximated function is used to express the 
                   relation of variance and time-gap. The minimum variance is provided by the OFFSET value CP_TRAJ_VAR_OFFSET.
                   In case the vehicle is stationary or moving in reverse the time-gap will take maximum value CP_TRAJ_VAR_TIMEGAP_MAX.
                   The time-gap is divided into three ranges [0 - 1)s, [1 - 4)s and [4-10]s which are characterized by
                   different coefficients and corresponding power functions of time-gap. \n\n 
                   time-gap [0-1) s = (CP_ROAD_COURSE_VAR_COEFF_LOW  * (time-gap)^2  ) + CP_TRAJ_VAR_OFFSET \n
                   time-gap [1-4) s = (CP_ROAD_COURSE_VAR_COEFF_LOW  * (time-gap)^2.5) + CP_TRAJ_VAR_OFFSET \n
                   time-gap [4-10]s = (CP_ROAD_COURSE_VAR_COEFF_HIGH * (time-gap)^3.5) + CP_TRAJ_VAR_OFFSET \n


                   @startuml
                   Partition CP_f_GetRoadVariance{
                   Start
                   If (Ego Velocity greater than Minimum ego velocity\n for variance calculation) then (TRUE)
                   : Compute time-gap;
                   Else (FALSE)
                   : Get maximum time-gap;
                   Endif
                   : Calculate the square of the time;
                   If (Time gap less than Time-gap limit by first segment) then (TRUE)
                   : For low time-gap values approximation by power function with exponent 2;
                   Elseif (Time gap less than Time-gap limit by second segment) then (TRUE)
                   : For mid time-gap values approximation by power function with exponent 2.5;
                   Else (FALSE)
                   : For high time-gap values approximation by power function with exponent 3.5;
                   Endif
                   : Return Time-gap dependent variance of the VDY course;
                   End
                   }
                   @enduml

  @return          f_Var : Time-gap dependent variance of the road course [full range of data type float32]

  @param[in]       f_DistX : longitudinal distance of the sample [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_EgoSpeedCorrected : ego velocity [-330.f ... 330.f] m/s

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   -

  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         17.02.2016

  @todo            The time gap f_TimeGap must not exceed CP_TRAJ_VAR_TIMEGAP_MAX value - Courage Test Case 9- FAILED

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
float32 CP_f_GetRoadVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected)
{
  float32 f_TimeGap,f_SQR_TimeGap;
  float32 f_Var;

  if(f_EgoSpeedCorrected > CP_TRAJ_VAR_EGO_VEL_MIN) /* Prevent division by zero */
  {
    /* Compute time-gap */
    f_TimeGap = fABS(f_DistX) / f_EgoSpeedCorrected;
  }  
  else
  {
    /* Get maximum time-gap.
       If speed is almost zero, then a large time will result in a large variance */
    f_TimeGap = CP_TRAJ_VAR_TIMEGAP_MAX; 
  }

  /* Calculate the square of the time */
  f_SQR_TimeGap = SQR(f_TimeGap);

  /* Three-segmented variance approximation.
     For the time-gap 0s-1s, 1s-4s and above 4s different approximations are used. */
  if(f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_LOW)
  {
    /* For low time-gap values approximation by power function with exponent 2 */
    f_Var = (CP_ROAD_COURSE_VAR_COEFF_LOW * f_SQR_TimeGap) + CP_TRAJ_VAR_OFFSET;
  }
  else if (f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_MID)
  {
    /* For mid time-gap values approximation by power function with exponent 2.5 */
    f_Var = (CP_ROAD_COURSE_VAR_COEFF_LOW * f_SQR_TimeGap * SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
  }
  else
  {
    /* For high time-gap values approximation by power function with exponent 3.5 */
    f_Var = (CP_ROAD_COURSE_VAR_COEFF_HIGH * f_SQR_TimeGap * f_TimeGap * SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
  }

  return f_Var;
}

#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_f_GetNaviVariance                                                                                */ /*!

  @brief           Return the time-gap dependant variance of the navi course

  @description     Functional approximation of the lateral estimation error of the navi course w.r.t. the ground 
                   truth. Estimation errors are obtained by a simulation with ARS400 data and the corresponding 
                   variance is calculated afterwards. Since the variance depends on the time-gap, an approximated 
                   function is used to express the relation of variance and time-gap.

                   @startuml
                   Partition CP_f_GetNaviVariance{
                   Start
                   If (Ego Velocity greater than Minimum ego velocity\n for variance calculation) then (TRUE)
                   : Compute time-gap;
                   Else (FALSE)
                   : Get maximum time-gap;
                   Endif
                   : Calculate the square of the time;
                   If (Time gap less than Time-gap limit by first segment) then (TRUE)
                   : For low time-gap values approximation by power function with exponent 2;
                   Elseif (Time gap less than Time-gap limit by second segment) then (TRUE)
                   : For mid time-gap values approximation by power function with exponent 2,5;
                   Else (FALSE)
                   : For high time-gap values approximation by power function with exponent 3,5;
                   Endif
                   : Return Time-gap dependent variance of the VDY course;
                   End
                   }
                   @enduml

  @return          f_Var : Time-gap dependant variance of the NAVI course [full range of data type float32]

  @param[in]       f_DistX : longitudinal distance of the sample [0 ... FIP_NAVI_MAX_SAMPLEDIST] m
  @param[in]       f_EgoSpeedCorrected : ego velocity            [-330.f ... 330.f] m/s

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING      : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         16.01.2017
  @changed         -


  @author          Piotr Pelechaty | Piotr.Pelechaty@conti-engineering.com | +49 69 67869 6110
*************************************************************************************************************************/
float32 CP_f_GetNaviVariance(const float32 f_DistX , const float32 f_EgoSpeedCorrected)
{
  float32 f_TimeGap,f_SQR_TimeGap;
  float32 f_Var;

  if(f_EgoSpeedCorrected > CP_TRAJ_VAR_EGO_VEL_MIN) /* Prevent division by zero */
  {
    /* Compute time-gap */
    f_TimeGap = fABS(f_DistX) / f_EgoSpeedCorrected;
  }  
  else
  {
    /* Get maximum time-gap.
       If speed is almost zero, then a large time will result in a large variance */
    f_TimeGap = CP_TRAJ_VAR_TIMEGAP_MAX; 
  }

  /* Calculate the square of the time */
  f_SQR_TimeGap = SQR(f_TimeGap);

  /* Three-segmented variance approximation.
     For the time-gap 0s-1s, 1s-4s and above 4s different approximations are used. */
  if(f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_LOW)
  {
    /* For low time-gap values approximation by power function with exponent 2 */
    f_Var = (CP_NAVI_COURSE_VAR_COEFF_LOW * f_SQR_TimeGap) + CP_TRAJ_VAR_OFFSET;
  }
  else if (f_TimeGap < CP_TRAJ_VAR_APPROX_SEGMENT_TIMEGAP_MID)
  {
    /* For mid time-gap values approximation by power function with exponent 2,5 */
    f_Var = (CP_NAVI_COURSE_VAR_COEFF_MED * f_SQR_TimeGap *  SQRT(f_TimeGap)) + CP_TRAJ_VAR_OFFSET;
  }
  else
  {
    /* For high time-gap values approximation by power function with exponent 3,5 */
    f_Var = (CP_NAVI_COURSE_VAR_COEFF_HIGH * f_SQR_TimeGap * f_TimeGap * SQRT(f_TimeGap) ) + CP_TRAJ_VAR_OFFSET;
  }

  return f_Var;
}
#endif
/*************************************************************************************************************************
  Functionname:    CP_f_GetPlausibleC1AtSpeed                                                                          */ /*!

  @brief           Calculates the Plausible value of C1 at speed.

  @description     Calculates the plausible value of C1 at speed, by linearly interpolating the speed with the Pre-defined highway plausibility parameters.

                   @startuml
                   Partition CP_f_GetPlausibleC1AtSpeed{
                   Start
                   : Get Plausible value of C1 at speed;
                   End
                   }
                   @enduml

  @return          float32 
                   Plausible value of C1 at speed.

  @param[in]       EgoSpeedCorrected : ego velocity in m/s   [-330.f ... 330.f] m/s 

  @glob_in         CP_REPlausibilityHighway  
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
float32 CP_f_GetPlausibleC1AtSpeed(const fVelocity_t EgoSpeedCorrected)
{
  float32 fA;

  fA = dGDBmathLineareFunktion (&CP_REPlausibilityHighway, EgoSpeedCorrected);

  return(1.0f/SQR(fA));
}

/*************************************************************************************************************************
  Functionname:    CP_f_GetCourseGradUpdateSTDC1AtSpeed                                                                */ /*!

  @brief           Calculates the gradient updates of course 

  @description     Calculates the gradient updates of course standard deviation at speed, by linearly interpolating pre-defined standard deviation 
                   values with the Ego speed.

                   @startuml
                   Partition CP_f_GetCourseGradUpdateSTDC1AtSpeed{
                   Start
                   : Get gradient updates of course;
                   End
                   }
                   @enduml

  @return          float32
                   Returns the Gradient updates of course standard deviation at speed.

  @param[in]       EgoSpeedCorrected : ego velocity in m/s   [-330.f ... 330.f] m/s 

  @glob_in         CP_CourseGradUpdateSTD
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @todo            Currently unused, check and delete the function

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
/*
static float32 CP_f_GetCourseGradUpdateSTDC1AtSpeed(const fVelocity_t EgoSpeedCorrected)
{
  float32 fA;

  fA = dGDBmathLineareFunktion (&CP_CourseGradUpdateSTD, EgoSpeedCorrected);

  return(1.0f/SQR(fA));
}
*/

/*************************************************************************************************************************
  Functionname:    CP_v_CopyTraj2Meas                                                                                  */ /*!

  @brief           Copy internal data to freeze struct

  @description     Copy internal data to freeze struct

                   @startuml
                   Partition CP_v_CopyTraj2Meas{
                   Start 
                   : Initialize x-position and y-position of trajectory sample,\n Trajectory Config, Trajectory State;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       pTrajectoryData : Trajectory data structure
                      Current.fTrajC0 : Trajectory clothoid parameter of current cycle  [-1.f ... +1.f]m^-1
                      Current.fTrajC1 : Trajectory clothoid parameter of current cycle  [-1.f ... +1.f]m^-2
                      Current.fTrajAngle : Trajectory angle of current cycle            [-PI ... +PI] rad
                      Config : Trajectory Config                      
                      State : Trajectory State                      
  @param[out]      pMeasTrajectory : Measured Trajectory data structure
                      fc0                                                               [-1 ... +1] m^-1
                      fc1                                                               [-1 ... +1] m^-2
                      fphi                                                              [-PI ... +PI] rad
                      fx : x-position of tarjectory sample                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fy : y-position of tarjectory sample                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      Config : Trajectory Config                    
                      State : Trajectory State                     

  @glob_in         pt_CPInput->t_RTE.pf_FCTBumperToCoG : Distance from Bumper to Center of Gravity  [-100.f ... 100.f] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_CopyTraj2Meas(const CP_t_TrajectoryData * pTrajectoryData , CP_t_TrajectoryMeas *pMeasTrajectory)
{
  pMeasTrajectory->fc0    = pTrajectoryData->Current.fTrajC0;
  pMeasTrajectory->fc1    = pTrajectoryData->Current.fTrajC1;
  pMeasTrajectory->fphi   = pTrajectoryData->Current.fTrajAngle;
  /*center of gravity in car front coordinate system*/
  pMeasTrajectory->fx     = -1.0f * (*pt_CPInput->t_RTE.pf_FCTBumperToCoG);
  pMeasTrajectory->fy     = 0.0f;
  pMeasTrajectory->Config = pTrajectoryData->Config;
  pMeasTrajectory->State  = pTrajectoryData->State;
}
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_v_CopyTraceTraj2Meas                                                                          */ /*!

  @brief           copy internal data to freeze struct

  @description     copy internal data to freeze struct

                    @startuml
                    Partition CP_v_CopyTraceTraj2Meas{
                    Start 
                    : Initialize Radius of the curve, maximum distance of the object,\n mean squared error of trace, Deviation of trace trajectory;
                    End                    
                    @enduml

  @return          -

  @param[in]       pTraceTrajectory : Trace Trajectory data structure
                      fCurve : Radius of the curve provided by the VDY trajectory   [-1.f ... +1.f]m^-1      
                      fMaxDist : maximum distance of the object                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fMeanSquaredError : mean squared error of trace               [0 ... CP_MAX_TRACE_MSE] as defined in cp_fusion_trace.c
                      fWeight : Deviation of trace trajectory from samples          [0 ... 100.f]
  @param[out]      pMeasTraceTrajectory : Measured Trace Trajectory data structure
                      fCurve : Radius of the curve provided by the VDY trajectory   [-1.f ... +1.f]m^-1      
                      fMaxDist : maximum distance of the object                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fMeanSquaredError : mean squared error of trace               [0 ... CP_MAX_TRACE_MSE] as defined in cp_fusion_trace.c
                      fWeight : Deviation of trace trajectory from samples          [0 ... 100.f]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Moving Object Traces
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure FCT support for CP sub-component
                   
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12/2/2016
  @changed         12/2/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
void CP_v_CopyTraceTraj2Meas(const CP_t_TraceTrajectory *pTraceTrajectory , CP_t_TraceTrajectory *pMeasTraceTrajectory)
{
  pMeasTraceTrajectory->fCurve            = pTraceTrajectory->fCurve;
  pMeasTraceTrajectory->fMaxDist          = pTraceTrajectory->fMaxDist;
  pMeasTraceTrajectory->fMeanSquaredError = pTraceTrajectory->fMeanSquaredError;
  pMeasTraceTrajectory->fWeight           = pTraceTrajectory->fWeight;
}
#endif
/*************************************************************************************************************************
  Functionname:    CP_v_CopyCourse2Meas                                                                                */ /*!

  @brief           copy internal data to freeze struct

  @description     copy internal data to freeze struct

                   @startuml
                   Partition CP_v_CopyCourse2Meas{
                   Start 
                   : Initialize x-position, y-position of trajectory sample;
                   End 
                   }
                   @enduml
  @return          -

  @param[in]       pCourseData : Course data structure
                      fCurve : Radius of the curve provided by the VDY trajectory                   [-1.f ... +1.f]m^-1  
                      SideSlipAngle : Sideslip angle of the curve provided by the VDY trajectory    [-PI ... +PI] rad   
  @param[out]      pMeasTrajectory : Measured Unfiltered Course data structure
                      fc0                                                                           [-1 ... +1] m^-1
                      fc1                                                                           [-1 ... +1] m^-2
                      fphi                                                                          [-PI ... +PI] rad
                      fx : x-position of tarjectory sample                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fy : y-position of tarjectory sample                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         pt_CPInput->t_RTE.pf_FCTBumperToCoG : Distance from Bumper to Center of Gravity  [-100.f ... 100.f] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_CopyCourse2Meas(const CP_t_CourseData * pCourseData , CP_t_UnfiltCourseMeas *pMeasUnFiltCourse)
{
  pMeasUnFiltCourse->fc0     = pCourseData->fCurve;
  pMeasUnFiltCourse->fc1     = 0.0f;
  pMeasUnFiltCourse->fphi    = pCourseData->SideSlipAngle;
  /*center of gravity in car front coordinate system*/
  pMeasUnFiltCourse->fx      = -1.0f * (*pt_CPInput->t_RTE.pf_FCTBumperToCoG);
  pMeasUnFiltCourse->fy      = 0.0f;
}

/*************************************************************************************************************************
  Functionname:    CP_v_GetCourseDataEgo                                                                               */ /*!

  @brief           Copy relevant ego input signals into course structure

  @description     Copy relevant input data from pInputSignals into the structure
                   pointed to by pCourseData, i.e. structure of ego course information. Depending on the parameter bUseSlipAngle,
                   either initialize side slip to zero (FALSE) or copy the relevant
                   values (TRUE)
                   
                   @startuml
                   Partition CP_v_GetCourseDataEgo{
                   Start 
                   : Initialize Curve of the trajectory, Curvature Gradient and Curvature variance of ego vehicle path;
                   If (side slip information shall be used?) then (TRUE)
                   : Get Side slip angle and Side slip angle variance of ego vehicle;
                   Else (FALSE)
                   : Initialize Side slip angle and Side slip angle variance of ego vehicle;
                   Endif 
                   End 
                   }
                   @enduml

  @return          -

  @param[out]      pCourseData : Course data structure
                      fCurve : Curve of the trajectory                                                             [-1.f ... +1.f]m^-1
                      fCurveGradient : Curvature Gradient of ego vehicle path                                      [-1.f ... +1.f]m^-2
                      fCurveVar : Curvature variance of ego vehicle path                                           [-1.f ... +1.f]m^-1
                      SideSlipAngle : Side slip angle of ego vehicle                                               [-PI ... +PI] rad
                      SideSlipAngleVariance : Side slip angle variance of ego vehicle                              [-PI ... +PI] rad
  @param[in]       bUseSlipAngle: boolean indicating if side slip information shall be used (TRUE) or not (FALSE)  [TRUE,FALSE] 
  @param[in]       pInputSignals: the input vehicle dynamics signals, commented out

  @glob_in         pt_CPInput
                      t_RTE.pf_EgoCurve : Curvature of ego vehicle path                                            [-1.f ... +1.f]m^-1         
                      t_RTE.pf_EgoCurveGrad : Curvature Gradient of ego vehicle path                               [-1.f ... +1.f]m^-2 
                      t_RTE.pf_EgoCurveVar : Curvature variance of ego vehicle path                                [-1.f ... +1.f]m^-1
                      t_RTE.pf_EgoSideSlip : Side slip angle of ego vehicle                                        [-PI +PI] rad             
                      t_RTE.pf_EgoSideSlipVar : Side slip angle variance of ego vehicle                            [-PI +PI] rad 
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Norman Apel
*************************************************************************************************************************/
void CP_v_GetCourseDataEgo( CP_t_CourseData *pCourseData , const boolean bUseSlipAngle/*, const VehDyn_t * pInputSignals*/ )
{
#if (defined(_MSC_VER))
#pragma COMPILEMSG("CPGetCourseData explicit ego dynamic parameter passing currently commented out! Check if functionality called for, or not needed!")//PRQA S 3116
/* date: 2015-04-28, reviewer: Lonard Jaison Manohar, reason: Non QAC related but required.*/
#endif
  pCourseData->fCurve                = *pt_CPInput->t_RTE.pf_EgoCurve;      /* pInputSignals->Lateral.Curve.Curve */
  pCourseData->fCurveGradient        = *pt_CPInput->t_RTE.pf_EgoCurveGrad; /* pInputSignals->Lateral.Curve.Gradient */
  pCourseData->fCurveVar             = *pt_CPInput->t_RTE.pf_EgoCurveVar;  /* pInputSignals->Lateral.Curve.varC0 */

  if ( bUseSlipAngle != FALSE)
  {
    pCourseData->SideSlipAngle         = *pt_CPInput->t_RTE.pf_EgoSideSlip;      /* pInputSignals->Lateral.SlipAngle.SideSlipAngle */
    pCourseData->SideSlipAngleVariance = *pt_CPInput->t_RTE.pf_EgoSideSlipVar;  /* pInputSignals->Lateral.SlipAngle.Variance */
  }
  else
  {
    pCourseData->SideSlipAngle         = 0.0f;
    pCourseData->SideSlipAngleVariance = 0.0f;
  }
}

/*************************************************************************************************************************
  Functionname:    CP_f_GetCurvature                                                                                   */ /*!

  @brief           Returns Curvature from a given Trajectory at a given Distance

  @description     Returns Curvature from a given Trajectory at a given Distance

                   @startuml
                   Partition CP_f_GetCurvature{
                   Start 
                   : Get curvature at x position by calculating Curve, Curvature Gradient and\n curvature at X position;
                   End 
                   }
                   @enduml

  @return          fCurvatureAtXPosition : Returns curvature at x position (float32) [-1   +1] m^-1

  @param[in]       pTrajectory : Structure containing Trajectory data
                      fCurve : Curve of the trajectory                               [-1.f ... +1.f]m^-1
                      fCurveGradient : Curvature Gradient of ego vehicle path        [-1.f ... +1.f]m^-2
  @param[in]       fXPosition : curvature at X position                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Matthias Thomi, Gregor Powarzynski
*************************************************************************************************************************/
float32 CP_f_GetCurvature( CP_t_CourseData const * const pTrajectory, const float32 fXPosition )
{
  float32 fCurvatureAtXPosition;

  fCurvatureAtXPosition = pTrajectory->fCurve + ( pTrajectory->fCurveGradient * fXPosition );
  
  return fCurvatureAtXPosition;
}

/*************************************************************************************************************************
  Functionname:    CP_t_GetTrajectoryData                                                                              */ /*!

  @brief           Get pointer to SI trajectory information

  @description     Get pointer to SI trajectory information

                   @startuml
                   Partition CP_t_GetTrajectoryData{
                   Start 
                   : Return Trajectory Data;
                   End 
                   }
                   @enduml

  @return          CP_TrajectoryData : Reference to SI trajectory used [pointer to CP_t_TrajectoryData]

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         02.03.2016
  
  @todo            To be removed after removed from CPCD

  @author          Norman Apel | norman.apel@continental-corporation.com
*************************************************************************************************************************/
CP_t_TrajectoryData * CP_t_GetTrajectoryData(void)
{
  return &(t_CP_Output.CP_TrajectoryData);
}

#ifdef FCT_SIMU

/*************************************************************************************************************************
  Functionname:    CP_v_CallFCTFreezeforCPFusion                                                                       */ /*!

  @brief           Freeze FCT data from CP Fusion components

  @description     CPTrajFusionDebugMeasInfo is defined in one central location 
                   and all fusion components are freezed here.

                   @startuml
                   Partition CP_v_CallFCTFreezeforCPFusion{
				   start 
                   : Freeze FCT data;
				   end 
                   }
                   @enduml

  @return          -

  @param[in]       p_CP_TrajFusionDebugInfo : CP Trajectory fusion info     [CP_t_TrajFusionDebugInfo defined in cp.h]

  @glob_in         CP_TrajFusionDebugMeasInfo : Trajectory fusion debug measurement information
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU                  : Configuration switch used for simulation   
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author       Harsha Umesh Babu
**************************************************************************** */
void CP_v_CallFCTFreezeforCPFusion(CP_t_TrajFusionDebugInfo * CP_p_TrajFusionDebugInfo)
{
  (void)FCT_FREEZE_DATA(&CP_TrajFusionDebugMeasInfo, CP_p_TrajFusionDebugInfo, NULL);
}
#endif  /*End FCT_SIMU */
/** @} end defgroup */
#endif  /* END FCT_CFG_COURSE_PREDICTION */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED
