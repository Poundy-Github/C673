/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_navi_data_process.h

DESCRIPTION:               Header File for ACC FIP NAVI data processing module

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             21.08.2014

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef FIP_NAVI_DATA_PROCESS_H_INCLUDED
#define FIP_NAVI_DATA_PROCESS_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip_navi_data_plg
@{ */

#include "fip.h"

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

  
#if (FCT_CFG_INPUT_PREPROCESSSING)
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/



/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/
#define FIP_NAV_USE_SEG_ID                SWITCH_OFF  /*!< Switch to enable usage of segment ID */
#define FIP_NAV_MAX_VALID_LANE_NUM        (10u)       /*!< Maximal lane number which is considered a valid lane number */

#define FIP_NAVI_SEG_ANGLE_THRES_EXIT     (30.f)                  /*< Threshold for the angle to the next segment for considering it an exit */
#define FIP_NAVI_DIST_NEXT_EVENT_DEFAULT  (999u)                  /*! Default value for u_DistNextRoundabout, u_DistNextTollbooth, u_DistNextTunnelStart, u_DistNextTunnelEnd, 
                                                                      f_DistNextExitLaneStart, f_DistNextExitLaneEnd */

#define FIP_NAVI_MAX_NB_SAMPLES           CAL_MAX_NB_TRAJ_SAMPLES     /*!< Number of samples in NAVI path */
#define FIP_NAVI_MIN_SAMPLEDIST           (200.f)                 /*!< Minimal sample distance of NAVI path @unit:m */
#define FIP_NAVI_MAX_SAMPLEDIST           (300.f)                 /*!< Maximal sample distance of NAVI path @unit:m */

#define FIP_NB_NAVI_PATH_STATE            (2u)                    /*!< Number of states in NAVI path kalman filter */
#define FIP_C0_INIT_NAVI_PATH_TRAJ_NOISE  (1.0e-8f)              /*!< Initial noise for C0 in NAVI path kalman filter */
#define FIP_C1_INIT_NAVI_PATH_TRAJ_NOISE  (1.0e-9f)              /*!< Initial noise for C1 in NAVI path kalman filter */

#define FIP_MAX_NAVI_MOVE_2CYCLES         (1.f)                   /*!< Maximal y-movement of NAVI path samples between two cycles @unit:m */
#define FIP_MAX_DIFF_EGO_TO_NAVI          (2.5f)                  /*!< Maximal difference between NAVI path EGO path @unit:m */
#define FIP_MIN_SAMPLE_DIFF_FOR_ACCU      (0.3f)                  /*!< Minimum y-movement of NAVI path sample between two cycles for accumulating y-movement @unit:m */
#define FIP_MAX_XDIST_TO_COMPARE_MOVE     (1.f)                   /*!< Maximal x-distance between two sample points in successive cycles to compare 
                                                                      the y-movement of NAVI path samples between two cycles @unit:m */
#define FIP_PROB_CURVATURE_CHANGE_NEAR_MIN    (2.0f)              /*!< minimal curvature offset for timgap of 2s*/
#define FIP_PROB_CURVATURE_CHANGE_NEAR_MAX    (20.0f)             /*!< maximal curvature offset for timgap of 2s*/
#define FIP_PROB_CURVATURE_CHANGE_FAR_MIN     (2.0f)              /*!< minimal curvature offset for timgap of 4s*/
#define FIP_PROB_CURVATURE_CHANGE_FAR_MAX     (20.0f)             /*!< maximal curvature offset for timgap of 4s*/
#define FIP_CURVINESSPROB_FILTER              (50.0f)              /*!< filter factor for filtering of curviness probability */
#define FIP_TIME_CURVATURE_CHANGE_NEAR        (2.f)               /*!< near time gap for curviness probability */ 
#define FIP_DIST_CURVATURE_CHANGE_NEAR        (0.f)               /*!< near distance for curviness probability */
#define FIP_TIME_CURVATURE_CHANGE_FAR         (4.f)               /*!< far time gap for curviness probability */
#define FIP_DIST_CURVATURE_CHANGE_FAR         (100.f)             /*!< far distance for curviness probability */
#define FIP_NAVI_SEGMENT_MAX_RADIUS         (10230.f)               /*!< Maximal radius of a segment of the NAVI path @unit:m */


#define FIP_NAVI_VALID_SEG_IDX_DEFAULT        (-1)                /*!< Default value in case of no valid segment ID */
#define FIP_NAVI_VALID_PATH_MAX_ANGLE         (15.f)              /*!< Maximum angle between two segments to be a valid navi path @unit:deg */
#define FIP_NAVI_VALID_PATH_MAX_BRANCH_PROP   (30u)               /*!< Maximum probability for the ego vehicle to take the branch for considering the later segments */

#define FIP_NAVI_MAX_MEAN_DIFF_APPROX_FILT    (0.4f)              /*!< Maximal mean difference between approximated and filtered NAVI path */

#define FIP_NAVI_MIN_SPEED_HIGHWAY        (115.f/C_KMH_MS)        /*!< Minimum ego speed which indicates a highway @unit:m/s */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
#define FIP_NAVI_HIGHWAY_LANE_WIDTH           (3.4f)              /*!< Typical lane width on a highway @unit:m */
#define FIP_NAVI_MIN_VALID_SECOND_LANE_WIDTH  (1.5f)              /*!< Minimum lane width of a valid second lane @unit:m */
#define FIP_NAVI_MAX_VALID_SECOND_LANE_WIDTH  (5.f)               /*!< Maximum lane width of a valid second lane @unit:m */
#endif

#define FIP_NAVI_XDIST_APPROX_EGO_DIFF          (75.f)            /*!< X-distance at which the difference between the approximated and kalman filtered NAVI path is evaluated @unit:m */
#define FIP_NAVI_HIGH_APPROX_EGO_DIFF           (5.f)             /*!< Minimum difference to count it a "high" difference between the approximated and kalman filtered NAVI path @unit:m */
#define FIP_NAVI_HYST_HIGH_APPROX_EGO_DIFF      (4.f)             /*!< Minimum difference with hysteresis to count it a "high" difference between the approximated and 
                                                                        kalman filtered NAVI path @unit:m */
#define FIP_NAVI_MAX_TIME_HIGH_APPROX_EGO_DIFF  (1.32f)           /*!< Maximum time with a "high" difference between the approximated and kalman filtered NAVI path @unit:sec*/

#define FIP_NAVI_MAX_EGO_DIFF_AVG               (5.f)             /*!< Threshold for maximum difference between EGO path and history shape points (averaged) */

#define FIP_NAVI_FILTER_GRAD_LOW_STD      (0.00000001f)           /*!< Low standard deviation to control influence of sample on kalman filtered NAVI path */
#define FIP_NAVI_FILTER_GRAD_MEDIUM_STD   (0.0000001f)            /*!< Medium standard deviation to control influence of sample on kalman filtered NAVI path */
#define FIP_NAVI_FILTER_GRAD_HIGH_STD     (0.000001f)             /*!< High standard deviation to control influence of sample on kalman filtered NAVI path */



/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/

/*! Enum to describe the first two segments of the NAVI path */
enum NaviSegmentEnum{
  SEGMENT_0,
  SEGMENT_1
};

/*!< Vehicle params used in FIP NAVI for EGO motion computation */
typedef struct FIPNaviVehicleMotionParameters
{
  float32 f_Velocity;
  float32 f_Acceleration;
  float32 f_YawRate;
  float32 f_Slip;
  float32 f_CycleTime;
}FIPNaviVehicleMotionParameters_t;

/*!< Structure used to store cumulative EGO motion from a given reference origin */
typedef struct FIPNaviCummulativeEgoMotion 
{
  float32 f_rel_dx;     /*!< X-position of the EGO with reference to a given origin */
  float32 f_rel_dy;     /*!< Y-position of the EGO with reference to a given origin */
  float32 f_abs_dist;   /*!< Absolute distance traveled by the EGO with reference to a given origin */
  float32 f_abs_angle;  /*!< Angle representing orientation accumulated by EGO with reference to a given origin */
}FIPNaviCummulativeEgoMotion_t;

/*! Struct containing global NAVI path data (need to be available beyond one cycle) */
/* This was previously defined as a static variable directly, now reorganized as a typedef here but still used as a static variable */
typedef struct FIPGlobalNavi_Info{
#if FIP_EVAL_SHAPE_POINTS
  uint16  ui_CountHighDiffEgo2NaviPath;   /*!< Number of cycles with high difference between ego path and NAVI path */
  float32 f_LengthSeg0LastCycleNavi;      /*!< Length of the first segment sent by the NAVI for the last cycle */
  float32 f_LengthSeg0LastCycleAdapt;     /*!< Length of the first segment adapted by the ego motion for the last cycle */
  float32 f_YOffsetEgoCompAtOrigLastCycle;
  float32 f_AccumDiffYSampleNaviPath;     /*!< Maximal y-position difference in the NAVI path between the same sample points in two successive cycle 
                                            (accumulated for multiple successive cycles) @unit:m */
#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
  t_NaviInputData NaviDataSegmentChange;  /*!< Navi input data when changing into a new segment (to compare if now in another segment) */
#else
#ifdef FCT_SIMU
  t_NaviInputData NaviDataSegmentChange;  /*!< NAVI input data when changing into a new segment (to compare if now in another segment) */
#endif

  float32 af_LengtSeg0Seg1SegmentChange[SEGMENT_1 + 1u];    /*!< Length of the first two segments when entering a new segment */
  uint16 au_SegmentIDSegmentChange[(uint8)FCT_NAV_NUM_SEG]; /*!< Segment IDs of the navi path when entering a new segment */
#endif
#endif /* FIP_EVAL_SHAPE_POINTS */
  SLATE_t_PosSamples NaviPathValidPosSamples; /*!< Position samples of NAVI path, which indicate the future course */
#if FIP_EVAL_SHAPE_POINTS
  FIPNaviEgoSegmentInfo_t NaviEGOSegment;
  FIPNaviVehicleMotionParameters_t MotionParams_LastCycle;     /*!< Vehicle motion parameters for last cycle */
#endif
} FIPGlobalNaviInfo_t;

/*! Evaluated NAVI data which is used in cp_trajectory.c*/
/* This was previously defined as a static variable directly, now reorganized as a typedef here but still used as a static variable */
typedef struct FIPNaviData_Evaluated{
  boolean b_NaviPathApproxPlausible;        /*!< Info if NAVI path approximation is plausible */
  float32 f_SumLengthNaviPath;              /*!< Entire length of NAVI path @unit:m */
  float32 f_NaviPathToPolySumSqDistAvg;     /*!< Measure how "close" the NAVI path is to the approximated NAVI path (by a polynomial) @unit:m */
  float32 f_EgoNaviPathErrDistAvg;          /*!< Difference between the approximated NAVI path and the ego curve @unit:m^2 */
  float32 f_DiffAngleToFistShapePoint;          /*!< Angle to first shape point */
  CAL_t_TracePolyL2 PolyNaviPathL2;           /*!< Approximated NAVI path by a second order polynom (y = f(x) = fC0 + fC1 * x + fC2 * x^2) */
} FIPNaviDataEvaluated_t;

#if (FIP_EVAL_SHAPE_POINTS)
#if (FIP_NUM_HIST_SHAPE_POINTS > 0u)
typedef struct FIPNaviGlobalShapePoint_Data
{
  float32 af_AlphaHistShapePoint[FIP_NUM_HIST_SHAPE_POINTS];  /*!< Angle of the last segments which are passed; last entry corresponds to the first segment of the current NAVI path */
  float32 af_LengthHistShapePoint[FIP_NUM_HIST_SHAPE_POINTS]; /*!< Length of the last segments which are passed; last entry corresponds to the first segment of the current NAVI path */
  
}FIPNaviGlobalShapePointData_t;
#endif
#endif

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*! Declaration of local pointer to FIP_NAVI output structure for access within this sub-module */
extern MEMSEC_REF FIP_ND_Output_t * pt_FIP_ND_Output;

/*! Declaration of local pointer to FIP_NAVI input structure for access within this sub-module */
extern MEMSEC_REF FIP_ND_InputConst_t * pt_FIP_ND_Input;


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*Functions defined in fip_navi_data_process.c*/
extern void FIP_v_ND_InitPersistentData(void);

extern void FIPSet_MapIsADASQuality(const boolean mapADASIsQuality);

/*Functions defined in fip_navi_data_plg.c*/
extern boolean FIPCalcNaviDataValid(const t_NaviInputData *pNaviData);
extern boolean FIPCheckNaviPathNumberLanes(const t_NaviInputData *p_NaviData);
extern void FIP_v_InitNaviCustomData(void);

#if FIP_EVAL_SHAPE_POINTS
extern void FIP_v_NaviInitVehicleMotionParameters(FIPNaviVehicleMotionParameters_t *p_VehicleMotionParameters);
extern void FIP_v_NaviSetLastCycleMotionParams(FIPNaviVehicleMotionParameters_t *p_VehicleMotionParaLastCycle);
extern boolean FIP_b_DrivingDifferentFromNaviPath(const FIPNaviReferenceShapePoint_t *p_FIPShapePointsInNaviRef);
#endif


#if 0
extern boolean FIPNaviPathIsHighway(const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, const t_NaviInputData *pNaviData);
extern boolean FIPNaviPathIsCountryRoadOneLane(const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, const t_NaviInputData *pNaviData);
extern boolean FIPNaviPathIsInCityLimits(const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, const t_NaviInputData *pNaviData);
#endif

extern boolean FIPNaviPathIsHighway(const t_NaviInputData *pNaviData);
extern boolean FIPNaviPathIsCountryRoadOneLane(const t_NaviInputData *pNaviData);
extern boolean FIPNaviPathIsInCityLimits(const t_NaviInputData *pNaviData);
extern FIPNaviPathCurvatureType_t FIP_t_GetNaviPathCurvatureType(const t_NavSegment * p_NaviSegment );
float32 FIP_f_CalcSegAngleBasedOnCurve( float32 f_length, const t_NavSegment * p_NaviSegment, FIPNaviPathCurvatureType_t t_approxType);



#if (FIP_EVAL_SHAPE_POINTS)
extern float32 FIP_f_NaviGetArcLengthSeg(float32 const f_SegLengthLine, float32 const f_SegCurvature);
extern float32 FIP_f_CalcSampleYPosForSpline(const float32 f_SampleXPosRelToSegment, 
                                             const float32 f_ParaA, const float32 f_ParaB, const float32 f_ParaC, const float32 f_ParaD);
extern void FIPGetNaviRefShapePoints(uint8 ui_IdxSegNaviOrig, uint8 ui_IdxSegNaviEnd, FIPNaviReferenceShapePoint_t * pFIPShapePointsInNaviRef, float32 f_XPosOrigin, float32 f_YPosOrigin);
extern void FIPGetEgoRefShapePoints(const FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t* pFIPNaviCON2COG, FIPNaviShapePointEgo_t* pFIPShapePointsInEgoRef, 
                                    const boolean b_NewSegment, const boolean b_NewSegmentF);
extern void FIPGetCubicSplineBasedOnShapePoints(FIPNaviShapePointEgo_t* p_NaviShapePointInEgoRef);

#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
extern void FIP_v_CheckNewTreeOrSegment(t_NaviInputData* p_NaviDataSegmentChange, const t_NaviInputData * p_FCTSEN_pNaviData, boolean* pb_NewSegment, boolean* pb_NewTree);
#else
#ifdef FCT_SIMU
extern void FIP_v_CheckNewTreeOrSegment(const t_NaviInputData* p_NaviDataSegmentChange, const t_NaviInputData * p_FCTSEN_pNaviData, boolean* pb_NewSegment, boolean* pb_NewTree);
#endif
extern void FIP_v_CheckNewTreeOrSegmentWithSegID(uint16 au_SegIDSegmentChange[], const t_NaviInputData * p_FCTSEN_pNaviData, boolean* pb_NewSegment, boolean* pb_NewTree);
#endif

extern void FIPCheckNaviSegmentForced(FIPNaviEgoSegmentInfo_t* pNaviEGOSegment, boolean* pb_NewSegmentF, FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef, 
                                      const GDBTrafoMatrix2D_t* pFIPNaviCON2COG);
extern void FIPAddNaviShapePoint(const t_NaviInputData * pNaviInputData, FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef);
extern void FIP_b_ComputeEgoPathDifference(FIPNaviReferenceShapePoint_t *pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t *pFIPNavi_CON2COG);
extern void FIP_v_UpdateHistorySP(const float32 p_af_XHistSPBT[], const float32 p_af_YHistSPBT[], FIPNaviReferenceShapePoint_t *pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t* pFIPNaviCON2COG);
#endif /*! FIP_EVAL_SHAPE_POINTS */
extern void FIPSamplePosAbsNaviPathArcRel( float32 * pfX, float32 * pfY, const float32 fAngleArcSampleRel_j, 
  const t_NavSegment * p_NaviSegment, const float32 fCosAngleAccu, const float32 fSinAngleAccu, const float32 fXSegmentStart, 
  const float32 fYSegmentStart, FIPNaviPathCurvatureType_t t_NaviPathCurvatureType);
void FIP_f_UpdateAccumOrientPrevSegments(float32 * f_AccumOrientPrevSegments, const t_NavSegment * p_NaviSegment, const FIPNaviPathCurvatureType_t t_NaviPathCurvatureType);

extern void FIPNaviSetDistNextExit(const float32 f_LengthSeg0Adapted, const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, t_NaviInputData const * p_NaviData, 
                                   FIP_ND_Output_t *pFIP_ND_Output);
#if FIP_EVAL_SHAPE_POINTS
extern void FIP_v_NaviUpdateEgoMotion(const float32 f_CosAngle, const float32 f_SinAngle, const float32 f_abs_dx, const float32 f_abs_dy, FIPNaviCummulativeEgoMotion_t * pFIPNaviEgoCummul);
extern boolean FIP_b_SetTreeValidShapePointsInNaviRef(const FIPNaviReferenceShapePoint_t * p_ShapePointsInNaviRef);
#endif

#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
void FIP_v_SetDistToHighCurvatureChangeNavi(void);
#endif

float32 FIP_f_CalcDyOffsetCurvatureNavi(float32 f_TimeGap, float32 f_minDistance);
void FIP_SetProbCurveDiffNaviNear(void);
void FIP_SetProbCurveDiffNaviFar(void);
#if FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY
uint8 FIP_u_UpdateBranchProbability(void);
#endif
#if(FCT_CFG_CUSTOM_PASSING_STATE)
extern boolean FIP_b_OvertakeLaneIsExitLane(void); 
#endif /*!< FCT_CFG_CUSTOM_PASSING_STATE */

#endif /*!< FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE */
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#ifdef __cplusplus
};
#endif

///@}
#endif /*!< _FIP_NAVI_DATA_PROCESS_H_INCLUDED*/
