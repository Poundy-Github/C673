/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_objscore.h

DESCRIPTION:               SIT object scoring module header file

AUTHOR:                    Gergely Ungvary

CREATION DATE:             -

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef SIT_OBJSCORE_H_INCLUDED
#define SIT_OBJSCORE_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "sit.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
#if (SIT_CFG_OBJECT_SCORING)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_objscore
@{ */
/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*! Configuration switch for enabling/disabling per-object additional data
storage/processing. Uses somewhat more RAM and CPU. */
#define SIT_CFG_SCORING_PER_OBJECT_DATA  0

/*! Configuration switch for enabling/disabling camera lane scoring information */
#define SIT_CFG_SCORING_USE_CAM_LANE     0

/*! Configuration switch for enabling object scoring using road information */
#define SIT_CFG_ROAD_OBJECT_SCORING               0

  /*! Configuration switch for enabling object scoring using Ego dynamics information */
#define SIT_CFG_EGODYN_OBJECT_SCORING               0

  /*! Configuration switch for enabling trajectory based trace to ego distance estimation */
#define SIT_CFG_TRAJ_BASED_DIST_EST                 0

/*! Configuration switch enabling lane-change features */
#define SIT_CFG_LANE_CHANGE_FEATURES             1

/*! Maximum number of traces that can be assigned to a lane */
#define SIT_MAX_NUM_TRACES_PER_LANE    4u

/*! Maximum number of lanes that can be tracked based on traces */
#define SIT_MAX_NUM_TRACE_LANES        4u

/*! The number of samples over which ego curvature is averaged for sigma spread */
#define SIT_EGO_DYN_NUM_CURVATURE_SAMPLES  16u

/*! Utility define for the number of traces in the system */
#if (FCT_CFG_NEW_TRACES_INTERFACE)
#define SIT_SCORING_NUM_TRACES   (TraceID_t)TRACE_NO_OF_TRACES
#else
#define SIT_SCORING_NUM_TRACES   (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES
#endif
  

/*! Constant value stored in uTraceLaneIdx when a trace has no lane assigned */
#define SIT_LANE_INDEX_NONE            255u

typedef CAL_t_TracePolyL2 SITTracePolyL2_t;

/*! Structure used to store lane data. Lane information is derived from moving object
traces by collecting traces that seem to overlap */
typedef struct SITLaneInformation {
  TraceID_t       NumTraces;            /*!< Number of traces assigned to this lane */
  TraceID_t       TracesInLane[SIT_MAX_NUM_TRACES_PER_LANE];
  float32         fCloseDist;           /*!< Smallest X with information */
  float32         fFarDist;             /*!< Largest X with information */
  SITTracePolyL2_t ApproxLane;           /*!< The approximation of the lane */
  float32         fEstiEgoDist;         /*!< Estimated distance from ego */
  float32         fLaneSigma;           /*!< Lane base sigma spread to use */
} SITLaneInformation_t;

/*! The lanes to which traces are assigned */
typedef struct {
  TraceID_t           uTrNumLanes;                    /*!< Number of lanes */
  SITLaneInformation_t Lanes[SIT_MAX_NUM_TRACE_LANES];  /*!< The traces assigned */
} SITTraceLanes_t;

/*! Structure used to store trace additional data */
typedef struct SITTraceScoreAddData {
  ObjNumber_t       iObjNr;             /*!< Object number of the trace */
  uint8             uNumberOfPoints;    /*!< Number of trace points we have already seen */
  uint8             uApproxUseLen;      /*!< Number of indices to use for approximation */
  uint8             uTraceLaneIdx;      /*!< Trace lane index assigned */
  float32           fApproxCloseDist;   /*!< Close distance from where poly approx valid */
  float32           fApproxFarDist;     /*!< Far distance till where poly approx valid */
  SITTracePolyL2_t   ApproxPoly;         /*!< Trace approximation polynomial */
  float32           fSumSqDist;         /*!< Approximation polynomial's summed squared dist from points */
  float32           fTraceWeightFact;   /*!< Trace's final weight factor (updated each cycle) */
#ifdef FCT_SIMU
  float32           fTraceWeightedDyn;  /*!< The weighted trace dynamics */
  float32           fTraceOwnConfFact;  /*!< Trace's own confidence factor (updated on trace change) */
#endif
} SITTraceScoreAddData_t;

/*! Structure storing the third degree polynomial approximation of a trace,
using y = f(x) = fC0 + fC1 * x + fC2 * x^2 + fC3 * x^3 */
typedef struct SITTracePolyL3 {
  float32 fC0;
  float32 fC1;
  float32 fC2;
  float32 fC3;
} SITTracePolyL3_t;

/*! Additional data stored for traces (one entry per trace) */
extern MEMSEC_REF SITTraceScoreAddData_t SITTraceScoreAdd[SIT_SCORING_NUM_TRACES];

/*! The object scores for all objects */
extern MEMSEC_REF SITObjScoreData_t SITObjScores[EM_N_OBJECTS];


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


/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

extern SITTraceLanes_t * SIT_pt_GetTraceLanes(void);

extern void SIT_v_InitTraceAddData(SITTraceScoreAddData_t * const pTraceAdd);
extern void SIT_v_InitObjScoreData(SITObjScoreData_t * const pScore);
extern float32 SIT_f_SetInvEgoSpeed(void);
extern float32 SIT_f_SetLaneWidth(void);
extern void SIT_v_InitObjLaneScores(SITObjLaneScores_t * const pLaneScores);

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
///@}
#endif /*!< (SIT_CFG_OBJECT_SCORING) */

#endif /*!< (FCT_CFG_ACC_SITUATION)*/

#ifdef __cplusplus
};
#endif


#endif /*!< _SIT_OBJSCORE_H_INCLUDED*/
