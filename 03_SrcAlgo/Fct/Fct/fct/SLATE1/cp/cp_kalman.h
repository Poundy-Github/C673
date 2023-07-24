/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_kalman.h

DESCRIPTION:               distance filter to trajectory with kalman filter

AUTHOR:                    Norman Apel

CREATION DATE:             05.08.2008

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef CP_KALMAN_INCLUDED
#define CP_KALMAN_INCLUDED
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp
@{ */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"
#ifdef __cplusplus
extern "C" {
#endif

extern void CP_v_KalmanUpdatePos( const SLATE_t_PosSamples * pFUSED_Samples , CP_t_NoiseModelLinear sNoiseModel, const CP_t_TrajectoryData  *pTrajData );
// Currently unused
//extern void CP_v_KalmanUpdateGrad( const CAL_t_GradSamples * pFUSED_GradSamples , const CP_t_TrajectoryData  *pTrajData );
extern void CP_v_KalmanPredictTrajectory( const CP_t_TrajectoryData  * pTrajData );

extern float32 CP_f_KalmanGetTrajEstState(const CP_t_TrajectoryData * pTrajData , uint8 uiVarState);
extern float32 CP_f_KalmanGetTrajErrorCov(const CP_t_TrajectoryData * pTrajData , uint8 uiVarState);

#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
extern void CP_v_KalmanPredictTraceTrajectory(const CP_t_TraceTrajectory * pTraceTrajectory);
extern void CP_v_KalmanUpdateTraceMeas( const CP_t_TraceTrajectory * pTraceTrajectory);
extern float32 CP_f_KalmanGetTraceTrajEstState(const CP_t_TraceTrajectory * pTraceTrajectory , uint8 uiVarState);
#endif
#ifdef __cplusplus
};
#endif
/*! @endcond Doxygen_Suppress */
#endif
/** @} end defgroup */
