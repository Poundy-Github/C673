/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_objscore.c

DESCRIPTION:               SIT object scoring module (abstract object scores for
                           lane assignment)

AUTHOR:                    Gergely Ungvary

CREATION DATE:             2010.07.27

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */



/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)

/* Disable complete module if scoring is disabled */
#if (SIT_CFG_OBJECT_SCORING)
#include "sit_objscore.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_objscore Sit Object scoring
@ingroup sit
@brief    This module gives the score for each object for lane assignment. \n\n
@{
*/


/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*! Scaling factor from distribution value to object score value for ego
dynamics (since scores are integers, using integer arithmetic */
#define SIT_EGO_DISTRIB_TO_SCORE_SCALING_FACTOR    1024.0f

/*! Scaling factor for traces to object score value */
#define SIT_TRACE_DISTRIB_TO_SCORE_SCALING_FACTOR  512.0f

/*! Scaling factor from distribution value to object score value for
road estimation. (Since scores are integers, using integer arithmetic) */
#define SIT_ROAD_DISTRIB_TO_SCORE_SCALING_FACTOR   512.0f

/*! Low-pass filtering weight for previous iteration scores */
#define SIT_PAR_PREV_SCORE_WEIGHTING     3.0f

/*! Maximum score value */
#define SIT_OBJSCORE_MAX                 65535u

/*! The object time-gap from which ego dynamics sigma is started to be spread */
#define SIT_PAR_EGO_SPREAD_TIMEGAP       2.25f

/*! Minimum length of trace to assign a confidence to it */
#define SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS       3u

/*! Length of trace for maximal length based confidence in timegap seconds (i.e.: 1 means
length of ego speed times 1) */
#define SIT_TRACE_MAX_CONF_LENGTH_TIMEGAP        1.f

/*! Length based trace confidence multiplier when trace is SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS long */
#define SIT_MIN_TRACE_LENGTH_CONFIDENCE          0.5f

/*! Length based trace confidence multiplier when trace is SIT_NUM_TRACE_MAX_CONF_NUM_POINTS long */
#define SIT_MAX_TRACE_LENGTH_CONFIDENCE          1.f

/*! The average trace residual where maximal confidence based on residual is assigned. (the higher
this value, the lower the match requirement */
#define SIT_PAR_SCORING_MAX_TR_CONF_AVG_RESIDUAL 0.005f

/*! The basic multiplier to trace weigtht to use */
#define SIT_PAR_BASE_TRACE_WEIGHT_WITH_OBJ 0.01f

/*! The basic trace confidence to use for trace's where the trace head object doesn't exist */
#define SIT_PAR_BASE_TRACE_WEIGHT_NO_OBJ   0.0f

/*! Scaling factor of score carried over to ego lane, when road estimation indicates no lanes
on the given side. Maximum value may be 1/confidence_max, otherwise substract from given lane's
score may overflow! @max: (1.f/255.f) */
#define SIT_PAR_CARRY_OVER_FACTOR_NO_LANE (0.5f/255.f)

/*! Parameter specifying the maximal distance between two trace Y's to
consider them to be in the same lane */
#define SIT_PAR_MAX_TRACE_SAME_LANE_DELTA_Y      1.5f

/*! Parameter specifying the maximum gradient delta for two trace's
to be considered moving in parallel */
#define SIT_PAR_MAX_TRACE_GRAD_DELTA             4e-2f

/*! Default invalid value used by several functions */
#define SIT_DEFAULT_INVALID_VALUE              999.0f

/*  Maximum score limit,for assigning a lane based on scoring*/
#define SIT_SUM_MAX_SCORE_LIMIT           (100u)

/* Summed squared distance limit and predefined threshold value for SumSqDistPerLen.*/
#define SIT_SUMSQDIST_LIMIT               (1.2f)
#define SIT_SUMSQDISTPERLEN_THRESLD       (0.125f)

/*! The trace timegap to sigma spread factor to use. The timegap (X dist / ego speed) is multiplied
with this value and added to the trace sigma to account for uncertainty when extending a trace */
#define SIT_PAR_TIMEGAP_TO_LANE_SIGMA_FACT   0.375f

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/

#ifndef STATIC_INLINE
#ifdef _MSC_VER
#define STATIC_INLINE static
#else
#define STATIC_INLINE inline
#endif
#endif

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*! The definition of the number of entries in the Gauss distribution lookup tables */
#define SIT_COURSE_PRED_LOOKUP_TABLE_SIZE 32
/*! The X resolution step in the Gauss distribution lookup tables */
#define SIT_COURSE_PRED_LOOKUP_TABLE_STEP 0.25f

/*! The lookup table for the function Gauss distribution function f(x) = 1/sqrt(2*PI) * exp(-sqr(x)/2)
Using steps of 0.25 size with first 32 entries stored. Note: size greater by one to store terminating
zero entry (simplifies lookup) */
SET_MEMSEC_CONST(SITGaussLookupTable)
static const float32 SITGaussLookupTable[SIT_COURSE_PRED_LOOKUP_TABLE_SIZE+1] = {// PRQA S 3218
  /* date: 2015-06-10, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
  /* [0] = 1/sqrt(2*pi) * exp(-sqr(0 * 0.25)/2) */
  0.398942f,
  /* [1] = 1/sqrt(2*pi) * exp(-sqr(1 * 0.25)/2) */
  0.386668f,
  /* [2] = 1/sqrt(2*pi) * exp(-sqr(2 * 0.25)/2) */
  0.352065f,
  /* [3] = 1/sqrt(2*pi) * exp(-sqr(3 * 0.25)/2) */
  0.301137f,
  /* [4] = 1/sqrt(2*pi) * exp(-sqr(4 * 0.25)/2) */
  0.241971f,
  /* [5] = 1/sqrt(2*pi) * exp(-sqr(5 * 0.25)/2) */
  0.182649f,
  /* [6] = 1/sqrt(2*pi) * exp(-sqr(6 * 0.25)/2) */
  0.129518f,
  /* [7] = 1/sqrt(2*pi) * exp(-sqr(7 * 0.25)/2) */
  0.0862773f,
  /* [8] = 1/sqrt(2*pi) * exp(-sqr(8 * 0.25)/2) */
  0.053991f,
  /* [9] = 1/sqrt(2*pi) * exp(-sqr(9 * 0.25)/2) */
  0.0317397f,
  /* [10] = 1/sqrt(2*pi) * exp(-sqr(10 * 0.25)/2) */
  0.0175283f,
  /* [11] = 1/sqrt(2*pi) * exp(-sqr(11 * 0.25)/2) */
  0.00909356f,
  /* [12] = 1/sqrt(2*pi) * exp(-sqr(12 * 0.25)/2) */
  0.00443185f,
  /* [13] = 1/sqrt(2*pi) * exp(-sqr(13 * 0.25)/2) */
  0.00202905f,
  /* [14] = 1/sqrt(2*pi) * exp(-sqr(14 * 0.25)/2) */
  0.000872683f,
  /* [15] = 1/sqrt(2*pi) * exp(-sqr(15 * 0.25)/2) */
  0.000352596f,
  /* [16] = 1/sqrt(2*pi) * exp(-sqr(16 * 0.25)/2) */
  0.00013383f,
  /* [17] = 1/sqrt(2*pi) * exp(-sqr(17 * 0.25)/2) */
  4.77186e-05f,
  /* [18] = 1/sqrt(2*pi) * exp(-sqr(18 * 0.25)/2) */
  1.59837e-05f,
  /* [19] = 1/sqrt(2*pi) * exp(-sqr(19 * 0.25)/2) */
  5.02951e-06f,
  /* [20] = 1/sqrt(2*pi) * exp(-sqr(20 * 0.25)/2) */
  1.48672e-06f,
  /* [21] = 1/sqrt(2*pi) * exp(-sqr(21 * 0.25)/2) */
  4.12847e-07f,
  /* [22] = 1/sqrt(2*pi) * exp(-sqr(22 * 0.25)/2) */
  1.07698e-07f,
  /* [23] = 1/sqrt(2*pi) * exp(-sqr(23 * 0.25)/2) */
  2.63924e-08f,
  /* [24] = 1/sqrt(2*pi) * exp(-sqr(24 * 0.25)/2) */
  6.07588e-09f,
  /* [25] = 1/sqrt(2*pi) * exp(-sqr(25 * 0.25)/2) */
  1.314e-09f,
  /* [26] = 1/sqrt(2*pi) * exp(-sqr(26 * 0.25)/2) */
  2.66956e-10f,
  /* [27] = 1/sqrt(2*pi) * exp(-sqr(27 * 0.25)/2) */
  5.09494e-11f,
  /* [28] = 1/sqrt(2*pi) * exp(-sqr(28 * 0.25)/2) */
  9.13472e-12f,
  /* [29] = 1/sqrt(2*pi) * exp(-sqr(29 * 0.25)/2) */
  1.53854e-12f,
  /* [30] = 1/sqrt(2*pi) * exp(-sqr(30 * 0.25)/2) */
  2.43432e-13f,
  /* [31] = 1/sqrt(2*pi) * exp(-sqr(31 * 0.25)/2) */
  3.61829e-14f,
  /* [32] = 0.0 (to simplify lookup & prevent branching) */
  0.0f
};

/*! The lookup table for the integral of the function f(x) = 1/sqrt(2*PI) * exp(-sqr(x)/2)
from 0 to given x, using steps of 0.25 size with first 32 entries stored */
SET_MEMSEC_CONST(SITGaussIntegralLookupTbl)
static const float32 SITGaussIntegralLookupTbl[SIT_COURSE_PRED_LOOKUP_TABLE_SIZE+1] = {// PRQA S 3207
  /* date: 2015-06-10, reviewer: Lonard jaison manohar, reason: currently the variable is not used, but in future it may be used.*/
  /* [0] = zero, to simplify lookup in function (reduce branching) */
  0.0f,
  /* [1] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 0.25 */
  0.0982013f,
  /* [2] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 0.5 */
  0.190543f,
  /* [3] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 0.75 */
  0.272193f,
  /* [4] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 1 */
  0.340082f,
  /* [5] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 1.25 */
  0.393159f,
  /* [6] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 1.5 */
  0.43218f,
  /* [7] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 1.75 */
  0.459155f,
  /* [8] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 2 */
  0.476688f,
  /* [9] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 2.25 */
  0.487404f,
  /* [10] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 2.5 */
  0.493563f,
  /* [11] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 2.75 */
  0.496891f,
  /* [12] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 3 */
  0.498581f,
  /* [13] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 3.25 */
  0.499389f,
  /* [14] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 3.5 */
  0.499752f,
  /* [15] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 3.75 */
  0.499905f,
  /* [16] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 4 */
  0.499966f,
  /* [17] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 4.25 */
  0.499988f,
  /* [18] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 4.5 */
  0.499996f,
  /* [19] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 4.75 */
  0.499999f,
  /* [20] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 5 */
  0.5f,
  /* [21] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 5.25 */
  0.5f,
  /* [22] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 5.5 */
  0.5f,
  /* [23] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 5.75 */
  0.5f,
  /* [24] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 6 */
  0.5f,
  /* [25] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 6.25 */
  0.5f,
  /* [26] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 6.5 */
  0.5f,
  /* [27] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 6.75 */
  0.5f,
  /* [28] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 7 */
  0.5f,
  /* [29] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 7.25 */
  0.5f,
  /* [30] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 7.5 */
  0.5f,
  /* [31] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 7.75 */
  0.5f,
  /* [32] = integral(1/sqrt(2*PI) * exp(-sqr(x)/2)) from 0 to 8 */
  0.5f,
};


/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/



/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/
/*! Additional data stored for traces (one entry per trace) */
SET_MEMSEC_VAR(SITTraceScoreAdd)
SITTraceScoreAddData_t SITTraceScoreAdd[SIT_SCORING_NUM_TRACES];

/*! The trace indices sorted by approximation start point distance */
SET_MEMSEC_VAR(SITTraceIdxSortByDist)
static TraceID_t SITTraceIdxSortByDist[SIT_SCORING_NUM_TRACES];// PRQA S 3218
/* date: 2015-06-10, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */

SET_MEMSEC_VAR(SITTraceLanes)
static SITTraceLanes_t SITTraceLanes;
SET_MEMSEC_VAR(p_SITraceLanes)
static SITTraceLanes_t const * p_SITraceLanes = &SITTraceLanes;// PRQA S 3207
/* date: 2015-06-10, reviewer: Lonard jaison manohar, reason: currently the variable is not used, but in future it may be used.*/

/*! The object scores for all objects */
SET_MEMSEC_VAR(SITObjScores)
SITObjScoreData_t SITObjScores[EM_N_OBJECTS];

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/* Gauss distribution calculation helper functions */
static float32 SIT_f_CalcStdGaussDistribution(const float32 value);
static float32 SIT_f_CalcGaussDistribution(const float32 sigma, const float32 value);
/* Gauss distribution to object score helper functions */
static SITObjScore_t SIT_u_CalcScoreGaussDistribFun(const float32 sigma, const float32 value, const float32 scale_fac);

/* Internal helper functions */
static float32 SIT_f_CalcPolyL2YCoordinate(const SITTracePolyL2_t * const pPoly, const float32 fX);
#if (SIT_CFG_TRAJ_BASED_DIST_EST)
static float32 SIT_f_CalcPolyL2ToEgoDist(const SITTracePolyL2_t * const pPoly);
#endif
static void SIT_v_CalcTraceApproxConfs(SITTraceScoreAddData_t * const pCurAddData, float32 fSumSqDist, float32 fBaseTraceWeight, float32 fUsedTraceLen);
#if (FCT_CFG_NEW_TRACES_INTERFACE)
static void SIT_v_CalcObjectTraceAddData(SITTraceScoreAddData_t * const pCurAddData, const ObjectTraces_t * const pTrace);
#else
static void SIT_v_CalcMovObjTraceAddData(SITTraceScoreAddData_t * const pCurAddData, TraceID_t iTrace);
#endif

/* One-time (non-per-object) score processing and helper functions */
static void SIT_v_ScoringPreProcessTraces(void);

/* Actual score calculation functions */
static void SIT_v_CalcTraceScore(SITObjLaneScores_t * pScore, ObjNumber_t iObj);

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetTraceLanes                                                                                 */ /*!

  @brief           Get pointer to SITTraceLanes

  @description     Get pointer to SITTraceLanes
  
		@startuml
		Start
		Partition SIT_pt_GetTraceLanes {
		: Get pointer to SITTraceLanes;
		}
		End
		@enduml  

  @return          retStruct : Pointer to SITTraceLanes

  @param[in]       -

  @glob_in         SITTraceLanes : Pointer to structure of type SITTraceLanes_t, as defined in sit_objscore.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
 SITTraceLanes_t * SIT_pt_GetTraceLanes(void)
{
  SITTraceLanes_t * retStruct;
  retStruct = &SITTraceLanes;

  return retStruct;  
}


/*************************************************************************************************************************
  Functionname:    SIT_f_CalcStdGaussDistribution                                                                       */ /*!

  @brief           This function calculates the approximate Gauss distribution value

  @description     This function uses the lookup table SITGaussLookup to linearly
                   interpolate the normal (Gauss distributation value) based on
                   the formula 1/(sqrt(2*pi)) * exp(-x^2 / 2). Note that this 
                   corresponds to the normal distribution with sigma = 1. Based
                   on the value returned by this function arbitary sigma normal
                   distribuations can be calculated (see also
                   SIT_f_CalcGaussDistribution)
				   
		@startuml
		Start
		Partition SIT_f_CalcStdGaussDistribution {
			: Calculate absolute approximate Gauss distribution value;
			: Calculate Index of Gauss distribution value;
			If (Check that index is within non-zero range specified by lookup table) then (yes)
				: Calculate high and low approximate Gauss distribution value;
				: Calculate high weight distribution value;
				: Calculate the approximate Gauss distribution value;
			Else (no)
				: approximate Gauss distribution value as 0;
			Endif
		}
		End
		@enduml				   

  @return          retval : The approximate distribution function value.          [Full range of float32]

  @param[in]       value : the floating point value to calculate the distribution
                   function (see above) approximation for.                        [Full range of float32]

  @glob_in         SITGaussLookupTable : The lookup table for the function Gauss distribution function [const float32]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             None (asside from constant table SITGaussLookup being valid)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static float32 SIT_f_CalcStdGaussDistribution(const float32 value)
{
  float32 retval;
  const float32 value_abs = fABS(value);
  const float32 fvalue_idx = (value_abs * (1.f / SIT_COURSE_PRED_LOOKUP_TABLE_STEP));
  /* Check that index is within non-zero range specified by lookup table */
  if (fvalue_idx < (float32)SIT_COURSE_PRED_LOOKUP_TABLE_SIZE)
  {
    const sint32 vidx = (sint32)fvalue_idx;
    const float32 low_approx = SITGaussLookupTable[vidx];
    const float32 high_approx = SITGaussLookupTable[vidx+1];
    const float32 weight_high = ((value_abs - ((float32)vidx*SIT_COURSE_PRED_LOOKUP_TABLE_STEP))*(1.f/SIT_COURSE_PRED_LOOKUP_TABLE_STEP));

    /* Linearly interpolate between lower and upper bound */
    retval = (((1.f - weight_high) * low_approx) + (weight_high * high_approx));
  }
  else
  {
    retval = 0.f;
  }
  return retval;
}

/*************************************************************************************************************************
  Functionname:    SIT_f_CalcGaussDistribution                                                                          */ /*!

  @brief           This function calculates the approximate Gauss distribution value.

  @description     This function calculates the normal distribution value for
                   an arbitary sigma value and given input value. It does so
                   by using the standard distibuation calculation function
                   (which calculates for sigma = 1) with modified parameters.
                   Note: the approximation only works acceptably for sigma values greater 0.1

		@startuml
		Start
		Partition SIT_f_CalcGaussDistribution {
			If (sigma is more than 0) then (yes)
				: Calculate the inverse of sigma;
			Else (no)
				: Use approximate inverse;
			Endif
			: Compensate for sigma from standard distribution;
		}
		End
		@enduml

  @return          retval : approximate value of Gaussian distribution function         [Full range of float32] 

  @param[in]       sigma : sigma value to use (shall be > C_F32_DELTA, otherwise
                   function will always return 0)                                       [Full range of float32]
  @param[in]       value : point where distribution functions value shall be taken.     [Full range of float32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static float32 SIT_f_CalcGaussDistribution(const float32 sigma, const float32 value)
{
  float32 retval;
  float32 sigma_inv;

  /* Calculate the inverse of sigma (needed for multipliers) */
  if (sigma > C_F32_DELTA)
  {
    sigma_inv = 1.0f / sigma;
  }
  else
  {
    /* Use approximate inverse */
    sigma_inv = 1.0f / C_F32_DELTA;
  }

  /* Compensate for sigma from standard distribution */
  retval = sigma_inv * SIT_f_CalcStdGaussDistribution(value * sigma_inv);

  return retval;
}


/*************************************************************************************************************************
  Functionname:    SIT_u_CalcScoreGaussDistribFun                                                                       */ /*!

  @brief           This function calculates the normal distribution value as score.

  @description     This function uses SIT_f_CalcGaussDistribution, and scales and
                   clips the result into the range representable by the SITObjScore_t type.

		@startuml
		Start
		Partition SIT_u_CalcScoreGaussDistribFun {
			: Calculate the raw (floating-point) value;
			: Scale it up for integer storage;
			If (raw value is less than maximum object score) then (yes)
				: Limit to maximum object score;
			Else (no)
				: Set raw value as maximum;
			Endif
		}
		End
		@enduml

  @return          ret_value : The scaled/clipped score value.

  @param[in]       sigma : The sigma value to use                                 [Full range of float32]
  @param[in]       value : point where the distribution is to be sampled          [Full range of float32]
  @param[in]       scale_fac : The scaling factor to use when converting floating
                   point value to integer. (Select this cautiously to avoid
                   overflows of the integer type SITObjScore_t).                  [Full range of float32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION  : FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static SITObjScore_t SIT_u_CalcScoreGaussDistribFun(const float32 sigma, const float32 value, const float32 scale_fac)
{
  SITObjScore_t ret_value;
  float32 result_value;

  /* Calculate the raw (floating-point) value */
  result_value = SIT_f_CalcGaussDistribution(sigma, value);

  /* Scale it up for integer storage */
  result_value = result_value * scale_fac;

  /* Limit to maximum object score */
  if (result_value < (float32)SIT_OBJSCORE_MAX)
  {
    ret_value = (SITObjScore_t)ROUND_TO_UINT(result_value);
  }
  else
  {
    ret_value = (SITObjScore_t)SIT_OBJSCORE_MAX;
  }

  return ret_value;
}

/*************************************************************************************************************************
  Functionname:    SIT_f_CalcPolyL2YCoordinate                                                                          */ /*!

  @brief           Calculate Y coordinate of a trace poly approximation

  @description     Calculate the Y coordinate of a trace poly approximation for a given X.

		@startuml
		Start
		Partition SIT_f_CalcPolyL2YCoordinate {
		: Calculate Y coordinate of a trace poly approximation;
		}
		End
		@enduml

  @return          fX : The Y coordinate of the poly at the given X [Full range of float32] 

  @param[in]       pPoly : the polynomial approximation of the path. Pointer to structure of type SITTracePolyL2_t.
                      fC0    [-1 … +1] m^-1
                      fC1    [-1 … +1] m^-2
                      fC2    [Full range of float32] 
  @param[in]       fX        [Full range of float32] 

  @glob_in         - 
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION  : FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            Add better approximation

  @author          Gergely Ungvary
*************************************************************************************************************************/
static float32 SIT_f_CalcPolyL2YCoordinate(const SITTracePolyL2_t * const pPoly, const float32 fX)
{
  return pPoly->fC0 + ((pPoly->fC1 + (pPoly->fC2 * fX)) * fX);
}

#if (SIT_CFG_TRAJ_BASED_DIST_EST)
/*************************************************************************************************************************
  Functionname:    SIT_f_CalcPolyL2ToEgoDist                                                                            */ /*!

  @brief           Calculate estimated distance of polynome from ego

  @description     Calculate the estimated distance of the passed polynomial
                   approximation to the ego.

		@startuml
		Start
		Partition SIT_f_CalcPolyL2ToEgoDist {
		: Set Ego speed and Ego curve;
		: Integrate the distance of the polynomials for 1 second or at least 15 m;
		: Calculate the polynome difference between ego movement and lane (using parabolic approximation for ego movement);
		: Calculate Lane Ego Integral;
		}
		End
		@enduml

  @return          fLaneEgoIntegral      [Full range of float32]

  @param[in]       pPoly : Pointer to polynomial approximation of the trace. Pointer to structure of type SITTracePolyL2_t, defined in sit_objscore.h
                        fC0      [-1 … +1]
                        fC1      [-1 … +1]
                        fC2      [Full range of float32]

  @glob_in         pt_SITInput->t_RTE.pf_EgoCurve : Ego curve   [-1 … +1]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING         : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static float32 SIT_f_CalcPolyL2ToEgoDist(const SITTracePolyL2_t * const pPoly)
{
  float32 f_EgoSpeed, fLaneEgoIntegral,f_Curve, fLaneIntegralX;
  SITTracePolyL2_t DiffLaneEgo;

  f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  f_Curve = *pt_SITInput->t_RTE.pf_EgoCurve;

  /* Integrate the distance of the polynomials for 1 second or at least 15 m */
  fLaneIntegralX = MAX_FLOAT(f_EgoSpeed, 15.f);

  /* Calculate the polynome difference between ego movement and lane (using
  parabolic approximation for ego movement) */
  DiffLaneEgo.fC0 = pPoly->fC0;
  DiffLaneEgo.fC1 = pPoly->fC1;
  DiffLaneEgo.fC2 = pPoly->fC2 - (0.5f * (f_Curve));
  /* Lane assignment done by calculating average distance on the next
  1 seconds of time or at least 10 meters, which ever is less */
  fLaneEgoIntegral = ((((DiffLaneEgo.fC2 * fLaneIntegralX) + DiffLaneEgo.fC1) * fLaneIntegralX) + DiffLaneEgo.fC0) * fLaneIntegralX;
  /* Store calculated average lane distance */
  fLaneEgoIntegral /= fLaneIntegralX;
  return fLaneEgoIntegral;
}
#endif /* END IF SIT_CFG_TRAJ_BASED_DIST_EST */

/*************************************************************************************************************************
  Functionname:    SIT_v_CalcTraceApproxConfs                                                                           */ /*!

  @brief           Calculate trace poly approximation confidences.

  @description     Calculate the trace polynome approximation confidences.

		@startuml
		Start
		Partition SIT_v_CalcTraceApproxConfs {
		: Update Ego speed using Ego Longitudinal Velocity;
		: Depending on the deviation of C2/C1 to the ego movement polynomial, decrease trace own confidence, since the larger the curvature or the angle of the trace;
		: Take absolute value of deviation;
		: Set Trace Weighted Dynamic;
		If (Used Trace Lane is more than 0) then (yes)
			: Calculate the squared distance averaged over the length of the trace;
			If (summed squared distance increased significantly or exceeds a pre-defined threshold) then (yes)
				: Reset trace approximation to only use the last 'SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS' - will only take effect in the next iteration;
				: Set trace length factor as SIT_MIN_TRACE_LENGTH_CONFIDENCE;
			Else (no)
				If (Used Trace Lane is less than max confidence) the  (yes)
					: Calculate Length Multiplier;
					: Calculate Length Factor;
				Else (no)
					: Set Length Factor as maximum Trace length Confidence ;
				Endif
			Endif
			: Multiply the weighted deviation from the raw ego dynamics course with the average per length residual to get a confidence;
			If (trace confidence factor is more than maximum confidence average residual) then (yes)
				: Calculate trace confidence factor;
			Else (no)
				: Set trace confidence factor as 1;
			Endif
		Else (no)
			: Trace length invalid (negative or zero - or too short);
			: Reset trace own confidence factor;
		Endif
		: Store new summed squared distance;
		: Set Trace Own Confidence Factor;
		: Total trace weight is calculated as the base weight (derived from it's object probability) multiplied with the trace's own confidence (derived from the trace's own quality attributes) multiplied by the length (trace stability) confidence;
		}		
		End
		@enduml

  @return          -

  @param[in,out]   pCurAddData : pointer to the trace data structure of type SITTraceScoreAddData_t,defined in sit_objscore.h
                   Note: the approximation polygon shall be filled on input.
                   On output the 'iApproxUseLen' field may be reset to decrease the used trace length for approximation.
                   The 'fSumSqDist' is filled with the approximation summed square distance error. 
                        ApproxPoly.fC1                                  [-1 … +1]
                        ApproxPoly.fC2                                  [Full range of float32]
                        fTraceWeightedDyn                               [Full range of float32]
                        fSumSqDist                                      [Full range of float32]
                        uApproxUseLen                                   [Full range of uint8]
                        fTraceOwnConfFact                               [Full range of float32]
                        fTraceWeightFact                                [Full range of float32]
  @param[in]       fSumSqDist : the summed square distance error (approximation residual) from the polynome approximation in 'pCurAddData->ApproxPoly'.
                   On output stored into 'pCurAddData->fSumSqDist'      [Full range of float32]
  @param[in]       fBaseTraceWeight :  Is a base trace confidence       [0 .. 1]           
  @param[in]       fUsedTraceLen : length of the trace used in meters   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         pt_SITInput->t_RTE.pf_EgoCurve                       [-1 … +1] m^-1
  @glob_out        -

  @c_switch_part   FCT_SIMU               : Configuration switch for simulation.
  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable new object scoring module

  @pre             pCurAddData already filled with approximation polynomial.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SIT_v_CalcTraceApproxConfs(SITTraceScoreAddData_t * const pCurAddData, float32 fSumSqDist, float32 fBaseTraceWeight, float32 fUsedTraceLen)
{
  float32 fC1Diff;
  float32 fC2Diff;
  float32 fLenFactor;
  float32 fTemp;
  float32 f_Curve;
  float32 f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  f_Curve = *pt_SITInput->t_RTE.pf_EgoCurve;
  /* Depending on the deviation of C2/C1 to the ego movement polynomial, decrease trace
  own confidence, since the larger the curvature or the angle of the trace, the more
  unlikely that we want to follow */
  fC2Diff = pCurAddData->ApproxPoly.fC2 - (0.5f * (f_Curve));
  fC1Diff = pCurAddData->ApproxPoly.fC1;
  /* C2diff*EgoSpeed² + C1Diff*EgoSpeed */
  fTemp = ((fC2Diff * f_EgoSpeed) + fC1Diff) * f_EgoSpeed;
  /* Take absolute value of deviation */
  fTemp = fABS(fTemp);

#ifdef FCT_SIMU
  pCurAddData->fTraceWeightedDyn = fTemp;
#endif

  /* Verify that trace length passed can be used as divisor */
  if (fUsedTraceLen > C_F32_DELTA)
  {
    /* Calculate the squared distance averaged over the length of the trace */
    const float32 fSumSqDistPerLen = (fSumSqDist / fUsedTraceLen);

    /* Check if summed squared distance increased significantly or exceeds a pre-defined
    threshold, then force approximation to restart */
    if (((fSumSqDist > (pCurAddData->fSumSqDist * SIT_SUMSQDIST_LIMIT)) && (fSumSqDistPerLen > 0.05f)) || (fSumSqDistPerLen > SIT_SUMSQDISTPERLEN_THRESLD))
    {
      /* Reset trace approximation to only use the last 'SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS' - will only take
      effect in the next iteration */
      pCurAddData->uApproxUseLen = (SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS);
      /* Set trace length confidence factor */
      fLenFactor = SIT_MIN_TRACE_LENGTH_CONFIDENCE;
    }
    else
    {
      /* The longer the stable trace is, the more confidence we have in it */
      if (fUsedTraceLen < (SIT_TRACE_MAX_CONF_LENGTH_TIMEGAP * f_EgoSpeed))
      {
        const float32 fLenMultiplier = SIT_f_SetInvEgoSpeed() * ((SIT_MAX_TRACE_LENGTH_CONFIDENCE - SIT_MIN_TRACE_LENGTH_CONFIDENCE)/SIT_TRACE_MAX_CONF_LENGTH_TIMEGAP);
        fLenFactor = (fLenMultiplier*fUsedTraceLen) + SIT_MIN_TRACE_LENGTH_CONFIDENCE;
      }
      else
      {
        fLenFactor = SIT_MAX_TRACE_LENGTH_CONFIDENCE;
      }
    }

    /* Multiply the weighted deviation from the raw ego dynamics course with the
    average per length residual to get a confidence */
    fTemp *= MAX_FLOAT(fSumSqDistPerLen, SIT_PAR_SCORING_MAX_TR_CONF_AVG_RESIDUAL);
    if (fTemp > SIT_PAR_SCORING_MAX_TR_CONF_AVG_RESIDUAL)
    {
      fTemp = SIT_PAR_SCORING_MAX_TR_CONF_AVG_RESIDUAL / fTemp;
    }
    else
    {
      fTemp = 1.f;
    }
  }
  else
  {
    /* Trace length invalid (negative or zero - or too short) */
    fLenFactor = 0.f;
    /* Reset trace own confidence factor */
    fTemp = 0.f;
  }

  /* Store new summed squared distance */
  pCurAddData->fSumSqDist = fSumSqDist;

#ifdef FCT_SIMU
  pCurAddData->fTraceOwnConfFact = fTemp;
#endif

  /* Total trace weight is calculated as the base weight (derived from it's object
  probability) multiplied with the trace's own confidence (derived from the trace's
  own quality attributes) multiplied by the length (trace stability) confidence */
  pCurAddData->fTraceWeightFact = fBaseTraceWeight * fTemp * fLenFactor;
}

#if (FCT_CFG_NEW_TRACES_INTERFACE)
/*************************************************************************************************************************
  Functionname:    SIT_v_CalcObjectTraceAddData                                                                         */ /*!

  @brief           Calculate internal 'SITTraceScoreAddData_t' based on trace.

  @description     Update/calculate the internally used SITTraceScoreAddData_t
                   structure with the information from the trace 'pTrace'.
                   This includes calculation of a 2nd level polynomial
                   approximation of the relevant part of the trace.

		@startuml
		Start
		Partition SIT_v_CalcObjectTraceAddData {
		If (check if trace valid or deleted and not of unknown or ego type) then (yes)
			If (check if trace has a valid object assigned) then (yes)
				: Get the object number of the trace;
				If (object associated with trace changed) then (yes)
					: reset the trace and assign new object ID;
				Endif
				: Set base trace confidence value;
				: Calculate base trace confidence for traces with objects to that of no objects (lower bound), and 1.f (maximal conf);
			Else (no)
				: Trace no longer has a valid object, set it's object number to no object;
				: Set base trace confidence value;
			Endif
			If (number of points increased) then (yes)
				: increase used approximation length;
			Endif
			: Load number of points used in last iteration for approximation;
			If (verify that sufficient number of trace points for polynome extrapolation) then (yes)
				: Calculate the trace approximation polynomial;
				If (check if the points used for the poly approximation are sufficient) then (yes)
					: Calculate the summed squared distance of the sample points to the approximation polynomial (the residual);
					: Calculate trace confidences;
				Else (no)
					: Insufficient number of points used for polynomial, set to invalid;
				Endif
			Else(no)
				: Trace too short, set it to invalid;
			Endif
			: Update number of points;
		Else (no)
			: Trace seems to have a reference to object greater TRACE_VALID_NO_OBJ_ID, which means the trace is deleted - reset data on it;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in,out]   pCurAddData : pointer to the trace data structure of type SITTraceScoreAddData_t,defined in sit_objscore.h
                   On input the currently stored state of the trace. This will be filled/updated with the information
                   from the new trace (based on changes of object ID/length)
                      iObjNr                                    [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
                      uNumberOfPoints                           [Full range of unsigned char]
                      uApproxUseLen                             [Full range of uint8]
                      ApproxPoly : pointer to strcture of type SITTracePolyL2_t, defined in sit_objscore.c
                      fApproxCloseDist                          [full range of float32 datatype]
                      fApproxFarDist                            [full range of float32 datatype]
                      fTraceWeightFact                          [Full range of float32]
  @param[in]       pTrace : The trace to use to update the data
                      ObjectTraceBasic.uiReferenceToFCTObject   [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
                      ObjectTraceBasic.uiNumberOfPoints         [Full range of unsigned char]
                      ObjectTraceAttributes.eTraceType          [Enum of type eTraceType_t, defined in Rte_Type.h]

  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information [0 ... 100]
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_NEW_TRACES_INTERFACE : Enable Interface for Traces
  @c_switch_full   FCT_CFG_ACC_SITUATION        :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING       : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SIT_v_CalcObjectTraceAddData(SITTraceScoreAddData_t * const pCurAddData, const ObjectTraces_t * const pTrace)
{
  /* First check if trace valid or deleted and not of unknown or ego type */
  if (  (pTrace->ObjectTraceBasic.uiReferenceToFCTObject <= TRACE_VALID_NO_OBJ_ID)
    &&  (pTrace->ObjectTraceBasic.uiNumberOfPoints >= SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS)
    &&  (pTrace->ObjectTraceAttributes.eTraceType != TRACE_TYPE_EGO)
    &&  (pTrace->ObjectTraceAttributes.eTraceType != TRACE_TYPE_UNKNOWN))
  {
    uint8     uNumApproxPts;      /*!< Number of trace points used for poly approx */
    float32   fBaseTraceWeight;

    /* Check if trace has a valid object assigned */
    if (pTrace->ObjectTraceBasic.uiReferenceToFCTObject < EM_N_OBJECTS)
    {
      /* Get the object number of the trace */
      const ObjNumber_t iTraceObjIdx = pTrace->ObjectTraceBasic.uiReferenceToFCTObject;

      /* Sanity check: if object associated with trace changed, then reset
      the trace, and assign new object ID */
      if (pCurAddData->iObjNr != iTraceObjIdx)
      {
        SIT_v_InitTraceAddData(pCurAddData);
        pCurAddData->iObjNr = iTraceObjIdx;
      }

      /* Set base trace confidence value */
      fBaseTraceWeight  = SIT_PAR_BASE_TRACE_WEIGHT_WITH_OBJ * SLATE_u_GetAccQuality(iTraceObjIdx);

      /* Clamp base trace confidence for traces with objects to that of no objects (lower
      bound), and 1.f (maximal conf) */
      fBaseTraceWeight = MINMAX_FLOAT(SIT_PAR_BASE_TRACE_WEIGHT_NO_OBJ, 1.f, fBaseTraceWeight);
    }
    else
    {
      /* Trace no longer has a valid object, set it's object number to no object */
      pCurAddData->iObjNr = OBJ_INDEX_NO_OBJECT;

      /* Set base trace confidence value */
      fBaseTraceWeight  = SIT_PAR_BASE_TRACE_WEIGHT_NO_OBJ;
    }

    /* If number of points increased, then increase used approximation length */
    if (pTrace->ObjectTraceBasic.uiNumberOfPoints > pCurAddData->uNumberOfPoints)
    {
      pCurAddData->uApproxUseLen = (pCurAddData->uApproxUseLen + (pTrace->ObjectTraceBasic.uiNumberOfPoints - pCurAddData->uNumberOfPoints));
    }

    /* Load number of points used in last iteration for approximation */
    uNumApproxPts = pCurAddData->uApproxUseLen;

    /* Verify that sufficient number of trace points for polynome extrapolation */
    if (uNumApproxPts >= SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS)
    {
      float32 fCurSqDist;
      uint8 uNumPtsSkipped;
      uint8 uNumPtsUsed;

      /* Calculate the trace approximation polynomial */
      uNumPtsUsed = CAL_u_CalcPointApproxPolyL3Ext(&pCurAddData->ApproxPoly, pTrace, &uNumPtsSkipped, uNumApproxPts);

      /* Verify that the points used for the poly approximation are sufficient */
      if (uNumPtsUsed >= SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS)
      {
        /* Calculate the summed squared distance of the sample points to the
        approximation polynomial (the residual) */
        fCurSqDist = CAL_f_CalcObjTraceSumSqDist(&pCurAddData->ApproxPoly, pTrace, &pCurAddData->fApproxCloseDist, &pCurAddData->fApproxFarDist, uNumPtsSkipped, uNumApproxPts);

        /* Calculate trace confidences */
        SIT_v_CalcTraceApproxConfs(pCurAddData, fCurSqDist, fBaseTraceWeight, (pCurAddData->fApproxFarDist - pCurAddData->fApproxCloseDist));
      }
      else
      {
        /* Insufficient number of points used for polynomial, set to invalid */
        pCurAddData->fApproxCloseDist   = SIT_DEFAULT_INVALID_VALUE;
        pCurAddData->fApproxFarDist     = SIT_DEFAULT_INVALID_VALUE;
        pCurAddData->fTraceWeightFact   = 0.f;
      }
    }
    else
    {
      /* Trace too short, set it to invalid */
      pCurAddData->fApproxCloseDist   = SIT_DEFAULT_INVALID_VALUE;
      pCurAddData->fApproxFarDist     = SIT_DEFAULT_INVALID_VALUE;
      pCurAddData->fTraceWeightFact   = 0.f;
    }

    /* Update number of points */
    pCurAddData->uNumberOfPoints  = pTrace->ObjectTraceBasic.uiNumberOfPoints;
  }
  else
  {
    /* Trace seems to have a reference to object greater TRACE_VALID_NO_OBJ_ID,
    which means the trace is deleted - reset data on it */
    SIT_v_InitTraceAddData(pCurAddData);
  }
}


#else


/*************************************************************************************************************************
  Functionname:    SIT_v_CalcMovObjTraceAddData                                                                         */ /*!

  @brief           Calculate internal 'SITTraceScoreAddData_t' based on trace

  @description     Update/calculate the internally used SITTraceScoreAddData_t
                   structure with the information from the trace 'pTrace'.
                   This includes calculation of a 2nd level polynomial
                   approximation of the relevant part of the trace.

		@startuml
		Start
		Partition SIT_v_CalcMovObjTraceAddData {
		If (check if trace valid or deleted) then (yes)
			If (check if trace has a valid object assigned) then (yes)
				: Get the object number of the trace;
				If (object associated with trace changed) then (yes)
					: reset the trace, and assign new object ID;
				Endif
				: Set base trace confidence value;
				: Clamp base trace confidence for traces with objects to that of no objects (lower bound), and 1.f (maximal conf);
			Else (no)
				: Trace no longer has a valid object, set it's object number to no object;
				: Set base trace confidence value;
			Endif
			If (if number of points increased) then (yes)
				: increase used approximation length;
			Endif
			: Find the number of samples with positive X coordinate;
			Repeat 
				: Decrease number approximate Point by 1;
			Repeat While (For All number of samples) 
			: Take smaller of the two possible values between used approximation length and number of samples with positive X coordinate;
			: Store the number of points used for poly approximation;
			If (sufficient number of trace points for polynome extrapolation and we have a real trace weight) then (yes)
				: Calculate the trace approximation polynomial;
				: Calculate the summed squared distance of the sample points to the approximation polynomial (the residual);
				: Store the estimated distance of the starting point (currently only take X offset into account);
				: Calculate the trace confidences;
			Else (no)
				: Trace too short, set it to invalid;
				: Update number of points;
			Endif
		Else (no)
			: Trace seems to have a reference to object greater TRACE_VALID_NO_OBJ_ID,\n which means the trace is deleted - reset data on it;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       iTrace      : Trace Index type [Full Range of Type TraceID_t as defined in Rte_Type.h ]
  @param[in,out]   pCurAddData : pointer to the trace data structure of type SITTraceScoreAddData_t,defined in sit_objscore.h
                   On input the currently stored state of the trace. This will be filled/updated with the information from the new trace (based on changes of object ID/length)
                        iObjNr                               [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1s]
                        uApproxUseLen                        [Full range of uint8]
                        uNumberOfPoints                      [0 ... 24]
                        ApproxPoly : pointer to strcture of type SITTracePolyL2_t, defined in sit_objscore.c
                        fApproxCloseDist                     [full range of float32 datatype]
                        fApproxFarDist                       [full range of float32 datatype]
                        fTraceWeightFact                     [Full range of float32]
 
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->iNumberOfPoints : No of points for the given trace                     [0 ... 24]
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES] and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->uiReferenceToFCTObject : The reference FCT Object Id for given trace i [0 ... EM_N_OBJECTS-1s] 
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES] and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointX : The X coordinate of given trace i                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES] and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointY : The Y coordinate of given trace i                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information                  [0 ... 100]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_NEW_TRACES_INTERFACE : Enable Interface for Traces
  @c_switch_full   FCT_CFG_ACC_SITUATION        : FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING       : Configuration switch to enable new object scoring module

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SIT_v_CalcMovObjTraceAddData(SITTraceScoreAddData_t * const pCurAddData, TraceID_t iTrace)
{
  /* Defining local variables from reference pointer */
  sint8 i_NumberOfPoints = pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].iNumberOfPoints;
  uint8 uRefToFCTObject = pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;

  /* First check if trace valid or deleted */
  if (  (uRefToFCTObject <= TRACE_VALID_NO_OBJ_ID)
    &&  ((uint8)i_NumberOfPoints >= SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS) )
  {
    uint8     uNumApproxPts;      /*!< Number of trace points used for poly approx */
    float32   fBaseTraceWeight;

    /* Check if trace has a valid object assigned */
    if (uRefToFCTObject < (uint8)EM_N_OBJECTS)
    {
      /* Get the object number of the trace */
      const ObjNumber_t iTraceObjIdx = (ObjNumber_t)(uRefToFCTObject);

      /* Sanity check: if object associated with trace changed, then reset
      the trace, and assign new object ID */
      if (pCurAddData->iObjNr != iTraceObjIdx)
      {
        SIT_v_InitTraceAddData(pCurAddData);
        pCurAddData->iObjNr = iTraceObjIdx;
      }

      /* Set base trace confidence value */
      fBaseTraceWeight  = SIT_PAR_BASE_TRACE_WEIGHT_WITH_OBJ * (float32)SLATE_u_GetAccQuality(iTraceObjIdx);

      /* Clamp base trace confidence for traces with objects to that of no objects (lower
      bound), and 1.f (maximal conf) */
      fBaseTraceWeight = MINMAX_FLOAT(SIT_PAR_BASE_TRACE_WEIGHT_NO_OBJ, 1.f, fBaseTraceWeight);
    }
    else
    {
      /* Trace no longer has a valid object, set it's object number to no object */
      pCurAddData->iObjNr = OBJ_INDEX_NO_OBJECT;

      /* Set base trace confidence value */
      fBaseTraceWeight  = SIT_PAR_BASE_TRACE_WEIGHT_NO_OBJ;
    }

    /* If number of points increased, then increase used approximation length */
    if ((uint8)i_NumberOfPoints > pCurAddData->uNumberOfPoints)
    {
      const uint8 uLengthIncrease = ((uint8)(i_NumberOfPoints) - pCurAddData->uNumberOfPoints);
      pCurAddData->uApproxUseLen += uLengthIncrease;
    }

    /* Find the number of samples with positive X coordinate */
    uNumApproxPts = (uint8)i_NumberOfPoints;
    while ((uNumApproxPts > 0u) && (pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[uNumApproxPts-1u] <= 0.f))
    {
      uNumApproxPts--;
    }

    /* Take smaller of the two possible values between used approximation length
    and number of samples with positive X coordinate */
    uNumApproxPts = MIN(pCurAddData->uApproxUseLen, uNumApproxPts);

    /* Store the number of points used for poly approximation */
    pCurAddData->uApproxUseLen = uNumApproxPts;

    /* Verify that sufficient number of trace points for polynome extrapolation and we
    have a real trace weight */
    if ((uNumApproxPts >= SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS) && (fBaseTraceWeight > 0.f))
    {
      float32 fCurSqDist;

      /* Calculate the trace approximation polynomial */
      CAL_v_CalcPointApproxPolyL2(&pCurAddData->ApproxPoly, pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX, pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointY, uNumApproxPts);
      /* Alternatively one could use : CAL_v_CalcPointApproxPolyL2Ext(&pCurAddData->ApproxPoly, pTrace->fTracePointX, pTrace->fTracePointY, pTrace->fTracePointYStdDev, uNumApproxPts); */

      /* Calculate the summed squared distance of the sample points to the
      approximation polynomial (the residual) */
      fCurSqDist = CAL_f_CalcSumSqDistance(&pCurAddData->ApproxPoly, pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX, pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointY, uNumApproxPts);

      /* Store the estimated distance of the starting point (currently only take X offset
      into account) */
      pCurAddData->fApproxCloseDist = pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[uNumApproxPts-1u];
      pCurAddData->fApproxFarDist   = pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[0];

      /* Calculate the trace confidences */
      SIT_v_CalcTraceApproxConfs(pCurAddData, fCurSqDist, fBaseTraceWeight, (pCurAddData->fApproxFarDist - pCurAddData->fApproxCloseDist));
    }
    else
    {
      /* Trace too short, set it to invalid */
      pCurAddData->fApproxCloseDist = SIT_DEFAULT_INVALID_VALUE;
      pCurAddData->fApproxFarDist   = SIT_DEFAULT_INVALID_VALUE;
      pCurAddData->fTraceWeightFact = 0.f;
    }

    /* Update number of points */
    pCurAddData->uNumberOfPoints  = (uint8)i_NumberOfPoints;
  }
  else
  {
    /* Trace seems to have a reference to object greater TRACE_VALID_NO_OBJ_ID,
    which means the trace is deleted - reset data on it */
    SIT_v_InitTraceAddData(pCurAddData);
  }
}
#endif  /* FCT_CFG_NEW_TRACES_INTERFACE */

/*************************************************************************************************************************
  Functionname:    SIT_v_ScoringPreProcessTraces                                                                        */ /*!

  @brief           Does object trace pre-processing

  @description     This function does object trace pre-processing. Perform all
                   necessary one time per cycle calculations on traces here.
                   Currently this consists of first going through all traces
                   and calculating/updating internal trace approximation
                   structures. Afterwards these approximation structures are
                   sorted for increasing X distance and a simple parallelism/

		@startuml
		Start
		Partition SIT_v_ScoringPreProcessTraces {
		Repeat 
			: Get utility pointer to current trace's additional data;
			: Use helper function to fill 'pCurAddData' with all relevant aspects of trace;
			If (the trace polynomial approximation uses at least the minimum required number of points and it has positive weight, then it is considered 'valid') then (yes)
				: Store trace ID in traces sorted by distance array by first finding the point to insert it in (sorted by closer point X distance);
				: Next move any trace indices farther away up by one position;
				: Insert the current trace in it's position;
			Endif
			: Reset assigned lane index (will be assigned in loop below);
		Repeat While (Go through all traces)
		: Reset number of trace lanes;
		Repeat
			: Get utility pointer to current trace's additional data;
			: Calculate the inverse of the base trace weight;
			: The close point of the current trace is test point # 1;
			Repeat
				: The test point # 2 is the closer one of the two trace's far points;
				: Calculate the deltas;
				If (if the two traces seem to be on the same lane using the distance of their endpoints from each other and the gradients in those points) then (yes)
					: Calculate Absolute Y deltas are small enough to be in the same lane;
					If (check if gradients are OK) then (yes)
						: Set that the currently processed trace is on lane # x;
					Endif
				Endif
			Repeat While (For All New trace Lanes)
			If (if trace is found in the same lane) then (yes)
				: Interpolate lane between trace and lane;
				If (If Number of Traces is less than Maximum Traces) then (yes)
					: Add trace to the correct position;
				Endif
				If (if Closest Distance is more than Approx Closest Distance) then (yes)
					: Update closest X of lane;
				Endif
				If (if Farthest Distance is more than Approx Farthest Distance) then (yes)
					: Update farthest X of lane;
				Endif
				: Update lane sigma factor;
				: Update number of traces;
			Else (no)
				: Create a new lane;
				If (if Number of Lanes is less than maximum Lanes) then (yes)
					: Initialize the lane with the current trace;
					: Store the trace as part of lane;
					: Initialize lane far/near with the trace;
					: Set base lane sigma;
					: Initialize lane to have single trace;
				Endif
			Endif
		Repeat While (All Valid Number of Traces)
		Repeat
			: Calculate Y coordinate of a trace poly approximation;
		Repeat While (All Trace Number Lanes)
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         SITTraceScoreAdd[] : Array of type SITTraceScoreAddData_t, defined in sit_objscore.h
  @glob_in         SITTraceIdxSortByDist[] : Array of type TraceID_t, defined in sit_objscore.c
  @glob_in         SITTraceScoreAdd[].fApproxCloseDist : [full range of float32 datatype]
  @glob_in         SITTraceLanes.uTrNumLanes :           [Type TraceID_t as defined in Rte_Type.h]
  @glob_in         SITTraceLanes.Lanes[uLaneIdx]         
  @glob_out        - 

  @c_switch_part   FCT_CFG_NEW_TRACES_INTERFACE : Enable Interface for Traces
  @c_switch_full   FCT_CFG_ACC_SITUATION        :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING       : Configuration switch to enable new object scoring module

  @pre             Road estimation pre-processing already done
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SIT_v_ScoringPreProcessTraces(void)
{
  TraceID_t uTrIdx;             /*!< Current trace ID (index) */
  TraceID_t uNumValidTr = 0u;   /*!< Counter of valid traces */

  /* First pass: go through all traces, calculating the trace polynomials as needed */
  for (uTrIdx = 0u; uTrIdx < SIT_SCORING_NUM_TRACES; uTrIdx++)
  {
    /* Get utility pointer to current trace's additional data */
    SITTraceScoreAddData_t * const pCurAddData = &SITTraceScoreAdd[uTrIdx];

    /* Use helper function to fill 'pCurAddData' with all relevant aspects of trace */
#if (FCT_CFG_NEW_TRACES_INTERFACE)
    SIT_v_CalcObjectTraceAddData(pCurAddData, &(FCT_GET_TRACE(uTrIdx)));
#else
    SIT_v_CalcMovObjTraceAddData(pCurAddData, uTrIdx);
#endif

    /* If the trace polynomial approximation uses at least the minimum required
    number of points and it has positive weight, then it is considered 'valid' */
    if ((pCurAddData->uApproxUseLen >= SIT_NUM_TRACE_MIN_NUMBER_OF_POINTS) && (pCurAddData->fTraceWeightFact >= C_F32_DELTA))
    {
      TraceID_t uTrPos;             /*!< Helper variable for X sorted valid traces */
      TraceID_t uFarTrPos;          /*!< Helper variable for X sorted valid traces */

      /* Store trace ID in traces sorted by distance array by first finding the point
      to insert it in (sorted by closer point X distance) */
      uTrPos = 0u;
      while ((uTrPos < uNumValidTr) && (SITTraceScoreAdd[SITTraceIdxSortByDist[uTrPos]].fApproxCloseDist < pCurAddData->fApproxCloseDist))
      {
        uTrPos++;
      }
      /* Next move any trace indices farther away up by one position */
      uFarTrPos = uNumValidTr;
      while ((uFarTrPos > uTrPos) && (uFarTrPos > 0))
      {
        SITTraceIdxSortByDist[uFarTrPos] = SITTraceIdxSortByDist[uFarTrPos-1u];
        uFarTrPos--;
      }
      /* Insert the current trace in it's position */
      SITTraceIdxSortByDist[uTrPos] = uTrIdx;
      uNumValidTr++;
    }
    /* Reset assigned lane index (will be assigned in loop below) */
    pCurAddData->uTraceLaneIdx = SIT_LANE_INDEX_NONE;
  }

  /* Reset number of trace lanes */
  SITTraceLanes.uTrNumLanes = 0u;

  /* After the above loop the local variable 'uNumValidTr' tells us the valid number
  of traces, which are sorted by approximation tail's distance in SITTraceIdxSortByDist
  The below loop tries to make lanes out of these traces by finding traces that are
  sufficiently parallel to each other */
  for (uTrIdx=0u; uTrIdx<uNumValidTr; uTrIdx++)
  {
    /* Get utility pointer to current trace's additional data */
    SITTraceScoreAddData_t * const pCurAddData = &SITTraceScoreAdd[SITTraceIdxSortByDist[uTrIdx]];
    /* Calculate the inverse of the base trace weight */
    const float32 fCurTraceWeightFactInv = 1.f / pCurAddData->fTraceWeightFact;
    /* The close point of the current trace is test point # 1 */
    const float32 fTestX1 = pCurAddData->fApproxCloseDist;
    const float32 fCurTrTestY1 = SIT_f_CalcPolyL2YCoordinate(&pCurAddData->ApproxPoly, fTestX1);
    const float32 fCurTestGrad1 = (pCurAddData->ApproxPoly.fC2 * fTestX1 * 0.5f) + pCurAddData->ApproxPoly.fC1;
    SITLaneInformation_t * pSameLane;
    TraceID_t uLaneIdx;
    /* See if any of the lanes created so far overlap with this new trace */
    pSameLane = NULL;
    for (uLaneIdx = 0u; (uLaneIdx < SITTraceLanes.uTrNumLanes) && (pSameLane == NULL); uLaneIdx++)
    {
      SITLaneInformation_t * const pCurLane = &SITTraceLanes.Lanes[uLaneIdx];
      const float32 fCloseTrTestY1 = SIT_f_CalcPolyL2YCoordinate(&pCurLane->ApproxLane, fTestX1);
      const float32 fCloseTestGrad1 = (pCurLane->ApproxLane.fC2 * fTestX1 * 0.5f) + pCurLane->ApproxLane.fC1;
      /* The test point # 2 is the closer one of the two trace's far points */
      const float32 fTestX2 = MIN_FLOAT(pCurLane->fFarDist, pCurAddData->fApproxFarDist);
      const float32 fCurTrTestY2 = SIT_f_CalcPolyL2YCoordinate(&pCurAddData->ApproxPoly, fTestX2);
      const float32 fCurTestGrad2 = (pCurAddData->ApproxPoly.fC2 * fTestX2 * 0.5f) + pCurAddData->ApproxPoly.fC1;
      const float32 fCloseTrTestY2 = SIT_f_CalcPolyL2YCoordinate(&pCurLane->ApproxLane, fTestX2);
      const float32 fCloseTestGrad2 = (pCurLane->ApproxLane.fC2 * fTestX2 * 0.5f) + pCurLane->ApproxLane.fC1;
      /* Calculate the deltas */
      float32 fAbsDeltaY1, fAbsDeltaY2;
      fAbsDeltaY1 = fABS(fCurTrTestY1 - fCloseTrTestY1);
      fAbsDeltaY2 = fABS(fCurTrTestY2 - fCloseTrTestY2);
      /* Calculate if the two traces seem to be on the same lane using the distance
      of their endpoints from each other and the gradients in those points */
      if ((fAbsDeltaY1 < SIT_PAR_MAX_TRACE_SAME_LANE_DELTA_Y) && (fAbsDeltaY2 < SIT_PAR_MAX_TRACE_SAME_LANE_DELTA_Y))
      {
        /* Absolute Y deltas are small enough to be in the same lane, verify that gradients
        are OK */
        const float32 fAbsGradDelta1 = fABS(fCurTestGrad1 - fCloseTestGrad1);
        const float32 fAbsGradDelta2 = fABS(fCurTestGrad2 - fCloseTestGrad2);
        if ((fAbsGradDelta1 < SIT_PAR_MAX_TRACE_GRAD_DELTA) && (fAbsGradDelta2 < SIT_PAR_MAX_TRACE_GRAD_DELTA))
        {
          pSameLane = pCurLane;
          /* Set that the currently processed trace is on lane # x */
          pCurAddData->uTraceLaneIdx = uLaneIdx;
        }
      }
    }
    /* See if trace in the same lane found */
    if (pSameLane != NULL)
    {
      const float32 fPrevNumTraces = (float32)pSameLane->NumTraces;
      const float32 fInvNumTraces = (1.f / (fPrevNumTraces + 1.f));
      /* Interpolate lane between trace and lane */
      pSameLane->ApproxLane.fC0 = ((pSameLane->ApproxLane.fC0 * fPrevNumTraces) + pCurAddData->ApproxPoly.fC0) * fInvNumTraces;
      pSameLane->ApproxLane.fC1 = ((pSameLane->ApproxLane.fC1 * fPrevNumTraces) + pCurAddData->ApproxPoly.fC1) * fInvNumTraces;
      pSameLane->ApproxLane.fC2 = ((pSameLane->ApproxLane.fC2 * fPrevNumTraces) + pCurAddData->ApproxPoly.fC2) * fInvNumTraces;
      /* Add trace to the correct position */
      if (pSameLane->NumTraces < SIT_MAX_NUM_TRACES_PER_LANE)
      {
        pSameLane->TracesInLane[pSameLane->NumTraces] = SITTraceIdxSortByDist[uTrIdx];
      }
      /* Update closest X and farthest X of lane */
      if (pSameLane->fCloseDist > pCurAddData->fApproxCloseDist)
      {
        pSameLane->fCloseDist = pCurAddData->fApproxCloseDist;
      }
      if (pSameLane->fFarDist < pCurAddData->fApproxFarDist)
      {
        pSameLane->fFarDist   = pCurAddData->fApproxFarDist;
      }
      /* Update lane sigma factor */
      pSameLane->fLaneSigma *= fCurTraceWeightFactInv;
      /* Update number of traces */
      pSameLane->NumTraces++;
    }
    else
    {
      /* Create a new lane */
      pCurAddData->uTraceLaneIdx = SITTraceLanes.uTrNumLanes;
      if (SITTraceLanes.uTrNumLanes < SIT_MAX_NUM_TRACE_LANES)
      {
        pSameLane = &SITTraceLanes.Lanes[SITTraceLanes.uTrNumLanes];
        SITTraceLanes.uTrNumLanes++;
        /* Initialize the lane with the current trace */
        pSameLane->ApproxLane.fC0 = pCurAddData->ApproxPoly.fC0;
        pSameLane->ApproxLane.fC1 = pCurAddData->ApproxPoly.fC1;
        pSameLane->ApproxLane.fC2 = pCurAddData->ApproxPoly.fC2;
        /* Store the trace as part of lane */
        pSameLane->TracesInLane[0] = SITTraceIdxSortByDist[uTrIdx];
        /* Initialize lane far/near with the trace */
        pSameLane->fCloseDist = pCurAddData->fApproxCloseDist;
        pSameLane->fFarDist   = pCurAddData->fApproxFarDist;
        /* Set base lane sigma */
        pSameLane->fLaneSigma = fCurTraceWeightFactInv;
        /* Initialize lane to have single trace */
        pSameLane->NumTraces = 1u;
      }
    }
  }
  /* Now go through the lanes we have and assign them to lanes */
  for (uTrIdx=0u; uTrIdx < SITTraceLanes.uTrNumLanes; uTrIdx++)
  {
    const float32 f_EgoX = 0.f;
    SITLaneInformation_t * const pCurLane = &SITTraceLanes.Lanes[uTrIdx];
#if (SIT_CFG_TRAJ_BASED_DIST_EST)
    /* Calculate and store the estimated distance to ego */
    pCurLane->fEstiEgoDist = SIT_f_CalcPolyL2ToEgoDist(&pCurLane->ApproxLane);
#else
    pCurLane->fEstiEgoDist = SIT_f_CalcPolyL2YCoordinate(&pCurLane->ApproxLane, f_EgoX);
#endif
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalcTraceScore                                                                                 */ /*!

  @brief           Calculate trace information based score for object

  @description     Calculate the trace information based score for the object

		@startuml
		Start
		Partition SIT_v_CalcTraceScore {
		#Orange :<b> SIT_v_InitObjLaneScores</b>: Reset trace score;
		: Reset trace related scores;
		Repeat
			: Get utility pointer to the trace;
			: Calculate the object's distance from the lane;
			: Update object to ego estimated distance;
			: Load lane sigma into sigma;
			If (check if object X before lane starts) then (yes)
				: Calculate Delta using far Distance;
				: Increase sigma;
			Else if (check if object X after it ends) then (yes)
				: Calculate Delta using closest Distance;
				: Increase Sigma;
			Else (no)
				: Leave sigma unchanged - within the X range where trace present;
			Endif
			: Assign scores to the individual lanes;
		Repeat While (All Traces) 
		}
		End
		@enduml

  @return          -

  @param[in,out]   pScore : the struct filled with the lane scores, Pointer to structure SITObjLaneScores_t, defined in sit_objscore.h
                      Lanes[]                
  @param[in]       iObj : index of the object         [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *pt_SITInput->t_RTE.pf_ObjLongDisp               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *pt_SITInput->t_RTE.pf_ObjLatDisp                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         SITTraceLanes.uTrNumLanes          [Type TraceID_t as defined in Rte_Type.h]
  @glob_in         SITTraceLanes.Lanes[]             
  @glob_out        -

  @c_switch_full   FCT_CFG_ACC_SITUATION  :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING         : Configuration switch to enable new object scoring module

  @pre             SIT_v_ScoringPreProcessTraces functions called for current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            Implement functionality

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SIT_v_CalcTraceScore(SITObjLaneScores_t * pScore, ObjNumber_t iObj)
{
  TraceID_t uLaneIdx;
  const float32 fObjX = *pt_SITInput->t_RTE.pf_ObjLongDisp (iObj);
  const float32 fObjY = *pt_SITInput->t_RTE.pf_ObjLatDisp (iObj);
#if (FCT_CFG_ROAD_INPUT)
  const float32 fLaneWid = SIT_f_SetLaneWidth();
#else
  const float32 fLaneWid = STRASSENBREITE;
#endif

  /* Reset trace score */
  SIT_v_InitObjLaneScores(pScore);

  /* Reset trace related scores */
  pScore->Lanes[SIT_OBJSCORE_LANE_LEFT]   = 0u;
  pScore->Lanes[SIT_OBJSCORE_LANE_EGO]    = 0u;
  pScore->Lanes[SIT_OBJSCORE_LANE_RIGHT]  = 0u;

  /* Go through each trace & calculate distance to the trace */
  for (uLaneIdx = 0u; uLaneIdx < SITTraceLanes.uTrNumLanes; uLaneIdx++)
  {
    float32 fObj2LaneDist;
    float32 fObj2EgoEstiDist;
    float32 fSigma;
    /* Get utility pointer to the trace */
    const SITLaneInformation_t * const pLane = &SITTraceLanes.Lanes[uLaneIdx];

    /* Calculate the object's distance from the lane */
    fObj2LaneDist = CAL_f_CalcDistToPolyL2Y(&pLane->ApproxLane, fObjX, fObjY);

    /* Update object to ego estimated distance */
    fObj2EgoEstiDist = fObj2LaneDist + pLane->fEstiEgoDist;

    /* Load lane sigma into sigma */
    fSigma = pLane->fLaneSigma;

    /* Increase sigma if object X before lane starts or after it ends */
    if (fObjX > pLane->fFarDist)
    {
      const float32 fDeltaX = (fObjX - pLane->fFarDist);
      fSigma += fDeltaX * SIT_f_SetInvEgoSpeed() * SIT_PAR_TIMEGAP_TO_LANE_SIGMA_FACT;
    }
    else if (fObjX < pLane->fCloseDist)
    {
      const float32 fDeltaX = (pLane->fCloseDist - fObjX);
      fSigma += fDeltaX * SIT_f_SetInvEgoSpeed() * SIT_PAR_TIMEGAP_TO_LANE_SIGMA_FACT;
    }
    else
    {
      /* Leave sigma unchanged - within the X range where trace present */
    }

    /* Now assign scores to the individual lanes */
    pScore->Lanes[SIT_OBJSCORE_LANE_LEFT]   += SIT_u_CalcScoreGaussDistribFun(fSigma, (fObj2EgoEstiDist - fLaneWid), SIT_TRACE_DISTRIB_TO_SCORE_SCALING_FACTOR);
    pScore->Lanes[SIT_OBJSCORE_LANE_EGO]    += SIT_u_CalcScoreGaussDistribFun(fSigma, fObj2EgoEstiDist,              SIT_TRACE_DISTRIB_TO_SCORE_SCALING_FACTOR);
    pScore->Lanes[SIT_OBJSCORE_LANE_RIGHT]  += SIT_u_CalcScoreGaussDistribFun(fSigma, (fObj2EgoEstiDist + fLaneWid), SIT_TRACE_DISTRIB_TO_SCORE_SCALING_FACTOR);
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalculateObjectScores                                                                          */ /*!

  @brief           This function calculates the abstract object scores

  @description     This function is the main function of this module. It calls
                   the other routines to calculate the abstract object score
                   for lane assignment

		@startuml
		Start
		Partition SIT_v_CalculateObjectScores {
		#Orange : <b> SIT_v_ScoringPreProcessTraces </b> : Pre-processing traces;
		Repeat
			If (if object is not deleted) then (yes)
				If (if Object is new) then (yes)
					: Reset all scores of object;
				Endif
				: Calculate trace based score;
				: Initialize summary lane to invalid value;
				: Set alternative (2nd highest scoring) lane to unknown;
				: Set alternative (2nd highest scoring) lane score to zero;
				: Reset maximal score;
				Repeat
					: Calculate confidence weighted score for the given lane;
					: Age summarized score (low-pass filtering);
					: Convert score back to integer and store in struct;
					If (if Lanes are more than max Score) then (yes)
						If (Check if Alternate Lane is Unknown lane and Lanes < Summery max score) then (yes)
							:Update Alternate score and Alternate lane;
						Endif
						: Update summary score maximum lane assignment and Lane summary;
					Endif
				Repeat While (Go through each lane)
				If (If Sum Lane < SIT_OBJ_SCORE_LANE_NUM and Sum Max Score > SIT_SUM_MAX_SCORE_LIMIT) then (yes)
					If (check if summery Lane is Left) then (yes)
						: Set Lane as Left Associate Lane;
					Else if (check if summary Lane is Ego) then (yes)
						: Set Lane as Ego Associate Lane;
					Else if (Check if summery Lane is Right) then (yes)
						: Set Lane as Right Associate Lane;
					Else (no)
						:  Set Lane as unknown;
					Endif
					: Update Object score Lane;
				Else (no)
					: Set Lane as Unknown Lane;
					: Update Object Score Lane;
				Endif
			Else (no)
				: Object is deleted, then reset scores;
			Endif
		Repeat While (For Entire Object List)
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         SITObjScores[]                          [Array of type SITObjScoreData_t, defined in sit_objscore.c]
  @glob_in         pt_SITInput->t_FIPOA.pb_ObjIsDeleted    [0 or 1]
  @glob_in         pt_SITInput->t_FIPOA.pb_ObjIsNew        [0 or 1]
  @glob_out        -

  @c_switch_part   FCT_CFG_ROAD_INPUT              : Road estimation input to FCT
  @c_switch_part   FCT_SIMU                        : Configuration switch for simulation.
  @c_switch_full   FCT_CFG_ACC_SITUATION           : FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable new object scoring module

  @pre             SIInitObjectScores called (at least once)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/5/2016

  @todo            -

  @author          Gergely Ungvary
*************************************************************************************************************************/
void SIT_v_CalculateObjectScores(void)
{
  ObjNumber_t iObjNr;

  /* Pre-processing traces */
  SIT_v_ScoringPreProcessTraces();

  /* Now assign scores for each object */
  for (iObjNr=0; iObjNr < EM_N_OBJECTS; iObjNr++)
  {
    SITObjLaneScores_t TraceScore;
    SITObjScoreData_t * const pScore = &SITObjScores[iObjNr];

    /* Verify that object is not deleted */
    if (!pt_SITInput->t_RTE.b_ObjIsDeleted(iObjNr))
    {
      uint16 eCurLane;
      uint16 eSumLane;
      uint16 eAltLane;
      SITObjScore_t SumMaxScore;
      SITObjScore_t AltScore;

      /* Reset all scores of object, if new */
      if(pt_SITInput->t_RTE.b_ObjIsNew(iObjNr)) /* functional change with introducing the macro! state MERGE_NEW was not considered before! */
      {
        SIT_v_InitObjScoreData(pScore);
      }

      /* Calculate trace based score */
      SIT_v_CalcTraceScore(&TraceScore, iObjNr);

      /* Initialize summary lane to invalid value */
      eSumLane = SIT_OBJ_SCORE_LANE_NUM;

      /* Set alternative (2nd highest scoring) lane to unknown */
      eAltLane = SIT_OBJ_SCORE_LANE_NUM;

      /* Set alternative (2nd highest scoring) lane score to zero */
      AltScore = 0u;

      /* Reset maximal score */
      SumMaxScore = 0u;

      /* Go through each lane */
      for (eCurLane = 0u; eCurLane < SIT_OBJ_SCORE_LANE_NUM; eCurLane++)
      {
        /* Calculate confidence weighted score for the given lane */
        const SITObjScore_t uNewScore = (TraceScore.Lanes[eCurLane]);
        /* Age summarized score (low-pass filtering) */
        float32 fFilteredScore = GDB_FILTER((float32)uNewScore, (float32)pScore->SumScore.Lanes[eCurLane], SIT_PAR_PREV_SCORE_WEIGHTING);
        /* Convert score back to integer and store in struct */
        pScore->SumScore.Lanes[eCurLane] = (SITObjScore_t)fFilteredScore;
        /* Update summary score maximum lane assignment when needed */
        if (pScore->SumScore.Lanes[eCurLane] > SumMaxScore)
        {
          if ((eAltLane == SIT_OBJ_SCORE_LANE_NUM) || (pScore->SumScore.Lanes[eAltLane] < SumMaxScore))
          {
            AltScore = SumMaxScore;
            eAltLane = eSumLane;
          }
          SumMaxScore = pScore->SumScore.Lanes[eCurLane];
          eSumLane = eCurLane;
        }
      }

      /* Assign a lane based on scoring */
      if ((eSumLane < SIT_OBJ_SCORE_LANE_NUM) && 
          ( (SumMaxScore > SIT_SUM_MAX_SCORE_LIMIT) || 
            (SumMaxScore > ((SITObjScore_t)(AltScore + (AltScore >> 2)) + 20u)) ))
      {
        switch (eSumLane)
        {
        case SIT_OBJSCORE_LANE_LEFT:
          pScore->eLane = ASSOC_LANE_LEFT;
          break;
        case SIT_OBJSCORE_LANE_EGO:
          pScore->eLane = ASSOC_LANE_EGO;
          break;
        case SIT_OBJSCORE_LANE_RIGHT:
          pScore->eLane = ASSOC_LANE_RIGHT;
          break;
        case SIT_OBJ_SCORE_LANE_NUM:
        default:
          pScore->eLane = ASSOC_LANE_UNKNOWN;
          break;
        }
        pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_ObjScoreLane = pScore->eLane;
      }
      else
      {
        pScore->eLane = ASSOC_LANE_UNKNOWN;
        pt_SITOutput->t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_ObjScoreLane = pScore->eLane;
      }
    }
    else
    {
      /* Object is deleted, then reset scores */
      SIT_v_InitObjScoreData(pScore);
    }
  }

}
///@}
#endif    /* #if (SIT_CFG_OBJECT_SCORING) */
#endif /* (FCT_CFG_ACC_SITUATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

