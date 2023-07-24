/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_object_traces.h

DESCRIPTION:               Header File for ACC FIP object traces processing module

AUTHOR:                    Wolfgang Borgs 

CREATION DATE:             02.09.2015

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

#ifndef FIP_OBJECT_TRACES_H_INCLUDED
#define FIP_OBJECT_TRACES_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip_object_traces
@{ */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip.h"


#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
#if (FCT_CFG_TJA_OBJECT_TRACE)
#define FIP_OBJECT_TRACE_SEG_LEN_MIN   (1.0F)               /*!< Min length of 1st segment between object and trace [m] */
#endif /* FCT_CFG_TJA_OBJECT_TRACE */

#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES))
/* Object Macro Definition for Moving object traces*/
#define FIPMOT_INVALID_VALUE            (999.9f)
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#if ((FCT_CFG_USE_FCT_STATIC_TRACES) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES))
/*! Bitfield for quality criteria of moving object traces - common to both static and dynamic.
    In future if requirements mandates then they will have to be separated */
typedef struct 
{
  ubit32_t dummy_00                 :1; /*!< bit 00 */
  ubit32_t dummy_01                 :1; /*!< bit 01 */
  ubit32_t dummy_02                 :1; /*!< bit 02 */
  ubit32_t dummy_03                 :1; /*!< bit 03 */
  ubit32_t dummy_04                 :1; /*!< bit 04 */
  ubit32_t dummy_05                 :1; /*!< bit 05 */
  ubit32_t dummy_06                 :1; /*!< bit 06 */
  ubit32_t dummy_07                 :1; /*!< bit 07 */
  ubit32_t dummy_08                 :1; /*!< bit 08 */
  ubit32_t dummy_09                 :1; /*!< bit 09 */
  ubit32_t dummy_10                 :1; /*!< bit 10 */
  ubit32_t dummy_11                 :1; /*!< bit 11 */
  ubit32_t dummy_12                 :1; /*!< bit 12 */
  ubit32_t dummy_13                 :1; /*!< bit 13 */
  ubit32_t dummy_14                 :1; /*!< bit 14 */
  ubit32_t dummy_15                 :1; /*!< bit 15 */
  ubit32_t dummy_16                 :1; /*!< bit 16 */
  ubit32_t dummy_17                 :1; /*!< bit 17 */
  ubit32_t dummy_18                 :1; /*!< bit 18 */
  ubit32_t dummy_19                 :1; /*!< bit 19 */
  ubit32_t dummy_20                 :1; /*!< bit 20 */
  ubit32_t dummy_21                 :1; /*!< bit 21 */
  ubit32_t dummy_22                 :1; /*!< bit 22 */
  ubit32_t valid_NoShadowObj        :1; /*!< bit 23 */
  ubit32_t valid_YIntersecGrad      :1; /*!< bit 24 */
  ubit32_t valid_MaxAngleGrad       :1; /*!< bit 25 */
  ubit32_t valid_AngleGradVar       :1; /*!< bit 26 */
  ubit32_t valid_MeanVarMOT2Curve   :1; /*!< bit 27 */
  ubit32_t valid_YIntersecDelta     :1; /*!< bit 28 */
  ubit32_t ReachedEgoVeh            :1; /*!< bit 29 */
  ubit32_t PointNotOnStraightLine   :1; /*!< bit 30 */
  ubit32_t dummy_31                 :1; /*!< bit 31 */
} FIP_t_MOTQuality;
#endif /* ((FCT_CFG_USE_FCT_STATIC_TRACES) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES)) */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*! Structure for the traces from moving objects */
typedef struct 
{
  float32 fYVar[FIP_STATIC_TRACE_NO_OF_POINTS];   /*!< fYVar values of trace (m) */
  float32 fLength;                  /*!< length of trace (m) */
  float32 fTraceWithoutObjTime;     /*!< time since object has been deleted (s) */
  float32 YIntersecVar;             /*!< intersection variance of trace with y-axis */
  float32 YIntersecDelta;           /*!< distance, trace has moved on the y-axis (used for quality analysis) */
  sint8  iBadCycles;               /*!< Quality Number for hysteresis at trace deletion */
  FIP_t_MOTQuality Quality;         /*!< quality of the trace */
} FIP_t_MovingObjStaticTraceData;
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */ 
#endif
#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)

/*! Structure for the dynamic traces from moving objects */
typedef struct 
{
  float32 fYVar[FIP_DYN_TRACE_NO_OF_POINTS];   /*!< fYVar values of dynamic trace (m) */
  float32 fLength;                  /*!< length of dynamic trace (m) */
  float32 fTraceWithoutObjTime;     /*!< time since object has been deleted (s) */
  float32 YIntersecVar;             /*!< intersection variance of dynamic trace with y-axis */
  float32 YIntersecDelta;           /*!< distance, dynamic trace has moved on the y-axis (used for quality analysis) */
  sint8  iBadCycles;               /*!< Quality Number for hysteresis at dynamic trace deletion */
  FIP_t_MOTQuality Quality;         /*!< quality of the dynamic trace */
} FIP_t_MovingObjDynTraceData;

#endif /* END IF FCT_CFG_USE_FCT_DYNAMIC_TRACES */


/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  CONSTANTS
*****************************************************************************/
/*! sampling length in m */
#define FIP_MOST_SAMPLING_LENGTH           (5.0f)


/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! Definition of pointer to FIPMovingObjectTraces output structure for access within this sub module */
extern MEMSEC_REF FIP_MOT_Output_t * pt_FIP_MOT_Output;

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*! Initialize the trace parameters */
extern void FIP_v_Init_Static_Traces(void);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */


#if ((SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) && (FCT_CFG_OBJECT_TRACE_PREPROCESSSING))
extern void FIP_v_PreProcessEMTraces(void);
#endif /* END IF (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */

#if ((FCT_CFG_USE_FCT_STATIC_TRACES) && (FCT_CFG_OBJECT_TRACE_PREPROCESSSING))
/* main function for to compute the FCT moving object traces*/
extern void FIP_v_CalculateMovingObjectStaticTraces(void);
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
extern void FIP_v_CalculateMovingObjectDynamicTraces(void);
extern void FIP_v_Init_Dynamic_Traces(void);
#endif /* END IF (FCT_CFG_USE_FCT_DYNAMIC_TRACES) */

#if (FIP_CFG_USE_EGO_TRACE)
extern void FIP_v_CalculateEgoTrace(void);
extern void FIP_v_Init_Ego_Trace(void);
#endif

/* Functions common to both static and dynamic traces */
/*get Variance of Object depending on Distance*/
extern float32 FIP_f_GetObjObservationVariance ( ObjNumber_t iObj );
/* for updating ego motion attributes */
extern const GDBTrafoMatrix2D_t * FIPGetTrafoMatrix2DCOFFwdTgtSync(void);
/* for updating ego motion attributes */
extern const GDBTrafoMatrix2D_t * FIPGetTrafoMatrix2DCOFForJitTgtSync(void);


/*****************************************************************************
  CUSTOM FUNCTIONS
*****************************************************************************/
#if (FCT_CFG_TJA_OBJECT_TRACE)
extern void FIP_v_OutputTrajectoryCustomData(const FIP_ObjTraceTrajectory_t* const pObjTrajs, AlgoDataTimeStamp_t tTimeStamp);
#endif /* FCT_CFG_TJA_OBJECT_TRACE */


#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE)) */

///@}
#endif /*!< _FIP_OBJECT_TRACES_H_INCLUDED*/
