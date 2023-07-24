/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_ext.h

DESCRIPTION:               Extern header file of Common ACC Library (CAL)

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.0


**************************************************************************** */
#ifndef CAL_EXT_INCLUDED
#define CAL_EXT_INCLUDED

/**
   @defgroup cal CAL_DIST2CUR / LINESEG / LINETRACESEG
@brief    Function which calculates distance to curve, line segment and line trace segment
Module which provides functionalities used in entire ACC
   @ingroup fct_sen
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_glob_ext.h"
#include "fct_types.h"

#include "cal_ver.h"
#include "cal_std_ext.h"
#include "cal_fuzzy_ext.h"
#include "cal_param_ext.h"
#include "cal_prob_ext.h"
#include "cal_switch_ext.h"
#include "cal_dyn_ext.h"
#include "cal_kin_ext.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/

#define CAL_CURVATURE_USE_CIRCLE_EQUATION   (1.F/1000.F)  /* in 1/m */

/*! @brief CAL_MAX_NB_TRAJ_SAMPLES */
#define CAL_MAX_NB_TRAJ_SAMPLES     (20u)

/*! @brief CAL_INFINITE_DIST */
#define CAL_INFINITE_DIST                        (999.f)

/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/


/*! @brief Structure for the third order polynomial parameter mean values, variances and residual variance 
using y = f(x) = fC0 + fC1 * x + fC2 * x^2 + fC3 * x^3 */
typedef struct
{
  float32 fC0;
  float32 fC1;
  float32 fC2;
  float32 fC3;
  float32 fC0Var;
  float32 fC1Var;
  float32 fC2Var;
  float32 fC3Var;
  float32 fXmin;
  float32 fXmax;
  boolean bValid;
} CAL_t_TracePolyL3;

/*! @brief Structure storing position samples of trajectories */
typedef struct CPSamplesTag
{
  float32   fx[CAL_MAX_NB_TRAJ_SAMPLES];    /*!< x-Position */
  float32   fy[CAL_MAX_NB_TRAJ_SAMPLES];    /*!< y-position */
  float32   fVar[CAL_MAX_NB_TRAJ_SAMPLES];  /*!< variance information */
  uint8     nb_samples;                 /*!< Number of samples */
} CAL_t_PosSamples;


/*! @brief Structure storing gradient samples of trajectories */
typedef struct {
  float32   fx[CAL_MAX_NB_TRAJ_SAMPLES];                /*!< x-position */
  float32   fdydx[CAL_MAX_NB_TRAJ_SAMPLES];             /*!< Gradient at x-position */
  float32   fdydxMinStdDev[CAL_MAX_NB_TRAJ_SAMPLES];    /*!< Standard deviation */
  boolean   valid[CAL_MAX_NB_TRAJ_SAMPLES];             /*!< Boolean to describe if sample if valid */
} CAL_t_GradSamples;

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*! cal_dist2curve.c */

extern CAL_t_TrajRefPoint CAL_t_CalculateDistancePoint2Circle(float32 fX, float32 fY, float32 fC0);
extern CAL_t_TrajRefPoint CAL_t_CalculateDistancePoint2Clothoid(const float32 fX, const float32 fY, const float32 fC0, const float32 fC1);


/*! cal_linetraceseg.c */
#if (0) /* Disabling unused functions */
extern fDistance_t CAL_f_CalculatePoint2LineSegListDist(const GDBVector2_t pSamples[], uint8 NumSamples, fDistance_t fPointX, fDistance_t fPointY, boolean bExtendEndLineSegs);
extern fDistance_t CAL_f_CalculatePoint2LineSegCoordArr(const float32 * pSamplesX, const float32 * pSamplesY, uint8 NumSamples, fDistance_t fPointX, fDistance_t fPointY, boolean bExtendEndLineSegs);

/* cal_lineseg.c */
extern fDistance_t CAL_f_CalculatePoint2LineDist(const GDBVector2_t * pLineSeg1, const GDBVector2_t * pLineSeg2, const GDBVector2_t * pPoint);
extern fDistance_t CAL_f_CalculatePoint2LineSegDist(const GDBVector2_t * pLineSeg1, const GDBVector2_t * pLineSeg2, const GDBVector2_t * pPoint);
extern fDistance_t CAL_f_CalculateAbsPoint2LineSegDist(const GDBVector2_t * pLineSeg1, const GDBVector2_t * pLineSeg2, const GDBVector2_t * pPoint);
extern fDistance_t CAL_f_CalculatePoint2SamplesDist(const CAL_t_PosSamples * pSamples, fDistance_t fPointX, fDistance_t fPointY, boolean bExtendSampleEnds);
extern void CAL_v_CalcPointApproxPolyL3Ext(CAL_t_TracePolyL3* pPoly, const ObjectTrace_t* pObjTrace, const EM_t_GenObjKinematics* pActObjKin, const boolean bUseActObjKin);
extern void CAL_v_CalculateRadii(const float32 pSamplesX[], const float32 pSamplesY[], uint8 NumSamples, fDistance_t * pfRadius);
extern void CAL_v_CalcPointApproxPolyL2Ext(CAL_t_TracePolyL2 * pPoly, const float32 pafX[], const float32 pafY[], const float32 * pafYStdDev, uint8 uNumPts);
#endif /* (0) Unused functions */

extern void CAL_v_CalcPointApproxPolyL2(CAL_t_TracePolyL2 * pPoly, const float32 pafX[], const float32 pafY[], uint8 uNumPts);


#if (FCT_CFG_NEW_TRACES_INTERFACE)
extern uint8 CAL_u_CalcObjTraceApproxPolyL2(CAL_t_TracePolyL2 * pPoly, const ObjectTraces_t * const pTrace, uint8 * puiSkipPts, uint8 uiNumPts);
extern float32 CAL_f_CalcObjTraceSumSqDist(const CAL_t_TracePolyL2 * const pPoly, const ObjectTraces_t * const pTrace, float32 * const pfMinX, float32 * const pfMaxX, uint8 uNumPtsSkipped, uint8 uiNumPts);
#endif /* (FCT_CFG_NEW_TRACES_INTERFACE) */
extern float32 CAL_f_CalcDistToPolyL2Y(const CAL_t_TracePolyL2 * const pPoly, const float32 fX, const float32 fY);
extern float32 CAL_f_CalcSumSqDistance(const CAL_t_TracePolyL2 * const pPoly, const float32 * pfPointX, const float32 *pfPointY, uint8 uNumPoints);


#ifdef __cplusplus
};
#endif

/* End of conditional inclusion */
#endif  /*!< CAL_EXT_INCLUDED */

/** @} end defgroup */
