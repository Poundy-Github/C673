/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_kalman.c

DESCRIPTION:               Course prediction kalman filter

AUTHOR:                    Norman Apel

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_COURSE_PREDICTION)
#include "cp_kalman.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp
@{ */
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

static void CP_v_KalmanSetTrajModelMat( const CP_t_TrajectoryData  *pTrajData );
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
static void CP_v_KalmanSetTraceTrajModelMat( const CP_t_TraceTrajectory * pTraceTrajectory);
#endif
/*************************************************************************************************************************
  Functionname:    CP_v_KalmanUpdatePos                                                                                */ /*!

  @brief           Update Distance/Velocity using Kalman measurement

  @description     Update Distance/Velocity using Kalman measurement

		@startuml
		Start
		Partition CP_v_KalmanUpdatePos {
		: Create intermediate Matrixes(KMatrix, FVector, CMatrix) for the Measurement Update;
		Repeat 
			: Calculate Relative Target Position;
			: Calculate Pointers to the entries of the matrix;
			: Calculate Lateral Noise;
			#Orange :<b>GDBKalmanMeasUpdate</b>: Update the Kalman Measuremet(Innovation);
		Repeat While (all relevant Targets) 
		#Orange :<b>GDBKalmanUpdatePDiag</b>:Update GDB Kalman Dialogue;
		}
		End
		@enduml

  @return          -

  @param[in]       pFUSED_Samples : Pointer to structure containing position of trajectory samples
                      nb_samples : number of trajectory samples                 [0u ... CAL_MAX_NB_TRAJ_SAMPLES]
                      fx[i] : x-position of trajectory sample                   [-5 * RW_FCT_MAX to +5 * RW_FCT_MAX] m
                      fy[i] : y-position of trajectory sample                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       sNoiseModel : structure containing noise information
                      fNoiseOffset : Noise offset value                         [Full range of float32  >= 0.F] 
                      fNoiseGradient : Gradient of noise distribution           [Full range of float32  >= 0.F] 
  @param[in]       pTrajData : pointer to structure containing trajectory data
                      KafiEst : The Kalman filter base data

  @glob_in         pt_CPInput->t_RTE.pf_FCTBumperToCoG : distance from Bumper to Center of Gravity  [0.f to +5*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_KalmanUpdatePos( const SLATE_t_PosSamples * pFUSED_Samples , CP_t_NoiseModelLinear sNoiseModel, const CP_t_TrajectoryData  *pTrajData )
{
  uint16 i;
  float32 fxTgt,fxTgt2,fYNoise;

  GDBBaseMatrix_t KMat; /* kalman gain */
  GDBBaseMatrix_t FVec;
  GDBBaseMatrix_t CMat;
  float32 KMatrix[CP_NB_TRAJ_STATE];
  float32 FVector[CP_NB_TRAJ_STATE];
  float32 CMatrix[CP_NB_TRAJ_STATE];

  /* Create intermediate Matrixes for the Measurement Update */
  GDBKalmanCreateMat(&KMat, KMatrix, MATTYPE_VECTOR, CP_NB_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&FVec, FVector, MATTYPE_VECTOR, CP_NB_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&CMat, CMatrix, MATTYPE_VECTOR, (uint8)1, CP_NB_TRAJ_STATE );

  /* sequential measurement updates for all relevant Targets */
  for ( i = 0u; i < pFUSED_Samples->nb_samples; i++ )
  {
    fxTgt = pFUSED_Samples->fx[i] + *pt_CPInput->t_RTE.pf_FCTBumperToCoG;
    fxTgt2 = fxTgt*fxTgt;
    /* Complete  Measurement Matrix C */
    CMat.pdData[VECT_MAT_INDEX(CP_sTRAJ_C0) ] = fxTgt2 * (1.0f / 2.0f); //PRQA S 0491
    /* Date: 2/25/2020, Reviewer: Gireesh, Reason: There is no side effects because of array subscripting to an object of poiter type */  

    CMat.pdData[VECT_MAT_INDEX(CP_sTRAJ_C1) ] = fxTgt2 * fxTgt * C_SIXTH; //PRQA S 0491
    /* Date: 2/25/2020, Reviewer: Gireesh, Reason: There is no side effects because of array subscripting to an object of poiter type */ 

    fYNoise = sNoiseModel.fNoiseOffset + (sNoiseModel.fNoiseGradient * fxTgt);
    fYNoise = SQR(fYNoise);

    /* Innovation */
    GDBKalmanMeasUpdate(&pTrajData->KafiEst, KMat, FVec, CMat, pFUSED_Samples->fy[i], fYNoise);
  }
  GDBKalmanUpdatePDiag(&pTrajData->KafiEst);
}

#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
/*************************************************************************************************************************
  Functionname:    KalmanUpdateTraceMeas                                                                                */ /*!

  @brief           Update curvature(c0)/curvature gradient(c1) using Kalman measurement for trace trajectory

  @description     Update curvature(c0)/curvature gradient(c1) using Kalman measurement for trace trajectory
  
		@startuml
		Start
		Partition CP_v_KalmanUpdateTraceMeas {
		: Create intermediate Matrixes (KMatrix, FVector, CMatrix) for the Measurement Update;
		: Set Pointer to the entries of the matrix as 1;
		: Set Lateral measurement noise as CP_TRACE_TRAJ_NOISE;
		#Orange :<b>GDBKalmanMeasUpdate</b>: Update the Kalman Measuremet(Innovation);
		#Orange :<b>GDBKalmanUpdatePDiag</b>:Update GDB Kalman Dialogue;
		}
		end
		@enduml

@return          -

  @param[in]       pTraceTrajectory : pointer to structure containing trajectory data
                      KafiTraceEst : The Kalman filter base data

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component
                   CP_CFG_TRACE_TRAJ_KALMAN_FILTER:Switch to enable Kalman filtering after PSO

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         04/05/2020

  @author          aathira.elizabeth.binu@continental-corporation.com
                   mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/
void CP_v_KalmanUpdateTraceMeas( const CP_t_TraceTrajectory * pTraceTrajectory)
{
  float32 fYNoise;
  
  GDBBaseMatrix_t KMat; /* kalman gain */
  GDBBaseMatrix_t FVec;
  GDBBaseMatrix_t CMat;
  float32 KMatrix[CP_NB_TRACE_TRAJ_STATE];
  float32 FVector[CP_NB_TRACE_TRAJ_STATE];
  float32 CMatrix[CP_NB_TRACE_TRAJ_STATE];

  /* Create intermediate Matrixes for the Measurement Update */
  GDBKalmanCreateMat(&KMat, KMatrix, MATTYPE_VECTOR, CP_NB_TRACE_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&FVec, FVector, MATTYPE_VECTOR, CP_NB_TRACE_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&CMat, CMatrix, MATTYPE_VECTOR, (uint8)1, CP_NB_TRACE_TRAJ_STATE );

  /* Complete  Measurement Matrix C */
  CMat.pdData[VECT_MAT_INDEX(CP_sTRACE_TRAJ_C0) ] = 1.0f; //PRQA S 0491
  /* Date: 05/30/2020, Reviewer:Karthik Chittepu, Reason: There is no side effects because of array subscripting to an object of pointer type */

  fYNoise = (CP_TRACE_TRAJ_NOISE);

  /* Innovation */
  GDBKalmanMeasUpdate(&pTraceTrajectory->KafiTraceEst, KMat, FVec, CMat, pTraceTrajectory->fCurve, fYNoise);

  GDBKalmanUpdatePDiag(&pTraceTrajectory->KafiTraceEst);
}
#endif
#if 0
//Currently unused function
/*************************************************************************************************************************
  Functionname:    CP_v_KalmanUpdateGrad                                                                               */ /*!

  @brief           Update gradient of Trajectory samples

  @description     Update gradient of Trajectory samples

  @return          -

  @param[in]       pFUSED_GradSamples : pointer to structure storing gradient samples of trajectories
                      valid[i] : Boolean to decide whether sample is valid or not                            [TRUE,FALSE]
                      fx[i] : x-position of trajectory sample                                                [-5 * RW_FCT_MAX to +5 * RW_FCT_MAX] m
                      fdydxMinStdDev[i] : Standard deviation of gradient at x-position of trajectory sample  [Full range of float32  >= 0.F] 
                      fdydx[i] : gradient at x-position of trajectory sample                                 [Full range of float32  >= 0.F] 
  @param[in]       pTrajData : pointer to structure containing trajectory data
                      KafiEst : The Kalman filter base data

  @glob_in         pt_CPInput->t_RTE.pf_FCTBumperToCoG : distance from Bumper to Center of Gravity           [0.f to +5 * RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_KalmanUpdateGrad( const CAL_t_GradSamples * pFUSED_GradSamples , const CP_t_TrajectoryData  *pTrajData )
{ 
  uint16 i;
  float32 fxTgt,fxTgt2,fYNoise;

  GDBBaseMatrix_t KMat; /* kalman gain */
  GDBBaseMatrix_t FVec;
  GDBBaseMatrix_t CMat;
  float32 KMatrix[CP_NB_TRAJ_STATE];
  float32 FVector[CP_NB_TRAJ_STATE];
  float32 CMatrix[CP_NB_TRAJ_STATE];


  /* Create intermediate Matrixes for the Measurement Update */
  GDBKalmanCreateMat(&KMat, KMatrix, MATTYPE_VECTOR, CP_NB_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&FVec, FVector, MATTYPE_VECTOR, CP_NB_TRAJ_STATE, (uint8)1 );
  GDBKalmanCreateMat(&CMat, CMatrix, MATTYPE_VECTOR, (uint8)1, CP_NB_TRAJ_STATE );

  /* sequential measurement updates for all relevant Targets */
  for ( i = 0u; i < CAL_MAX_NB_TRAJ_SAMPLES; i++ )
  {
    if( (pFUSED_GradSamples->valid[i]) != FALSE )
    {
      fxTgt = pFUSED_GradSamples->fx[i]+*pt_CPInput->t_RTE.pf_FCTBumperToCoG;
      fxTgt2 = fxTgt*fxTgt;

      /* Complete  Measurement Matrix C */
      CMat.pdData[VECT_MAT_INDEX(CP_sTRAJ_C0) ] = fxTgt; //PRQA S 0491
      /* Date: 2/25/2020, Reviewer: Gireesh, Reason: There is no side effects because of array subscripting to an object of poiter type */  

      CMat.pdData[VECT_MAT_INDEX(CP_sTRAJ_C1) ] = fxTgt2 * 0.5f; //PRQA S 0491
      /* Date: 2/25/2020, Reviewer: Gireesh, Reason: There is no side effects because of array subscripting to an object of poiter type */  

      fYNoise = MAX_FLOAT(CP_GRADUPDATE_STD_MIN,pFUSED_GradSamples->fdydxMinStdDev[i]);
      fYNoise = SQR(fYNoise);

      /* Innovation */
      GDBKalmanMeasUpdate(&pTrajData->KafiEst, KMat, FVec, CMat, pFUSED_GradSamples->fdydx[i], fYNoise);
    }   
  }  
}
#endif
/*************************************************************************************************************************
  Functionname:    CP_v_KalmanPredictTrajectory                                                                        */ /*!

  @brief           Predict Trajectory

  @description     Predict Trajectory

		@startuml
		Start
		Partition CP_v_KalmanPredictTrajectory {
		: Initialize the Kalman Filter;
		: Create intermediate Matrixes used for the time Update;
		: Predict the trajectory states from the Kalman Model;
		}
		End
		@enduml

  @return          -

  @param[in]       pTrajData : pointer to structure containing trajectory data
                      KafiEst : The Kalman filter base data

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_KalmanPredictTrajectory( const CP_t_TrajectoryData  * pTrajData )
{
  GDBBaseMatrix_t WMat;
  GDBBaseMatrix_t DAMat;
  GDBBaseMatrix_t DAWVec;
  float32 WMatrix[CP_NB_TRAJ_STATE*CP_NB_TRAJ_STATE2];
  float32 DAMatrix[CP_NB_TRAJ_STATE2];
  float32 DAWVector[CP_NB_TRAJ_STATE2];

  /* Update A & Q Matrixes */
  CP_v_KalmanSetTrajModelMat( pTrajData );

  /* Create intermediate Matrixes used for the time Update */
  GDBKalmanCreateMat(&WMat,     WMatrix,     MATTYPE_FULL,     CP_NB_TRAJ_STATE,  CP_NB_TRAJ_STATE2 );
  GDBKalmanCreateMat(&DAMat,    DAMatrix,    MATTYPE_DIAGONAL, CP_NB_TRAJ_STATE2, CP_NB_TRAJ_STATE2 );
  GDBKalmanCreateMat(&DAWVec,   DAWVector,   MATTYPE_VECTOR,   CP_NB_TRAJ_STATE2, (uint8)1  );

  /* Predict the actual state from the old estimated states */
  GDBKalmanTimeUpdate(&pTrajData->KafiEst, WMat, DAMat, DAWVec);
}

/*************************************************************************************************************************
  Functionname:    CP_v_KalmanSetTrajModelMat                                                                          */ /*!

  @brief           Initialize the Kalman Filter

  @description     Initialize the Kalman Filter

		@startuml
		Start
		Partition CP_v_KalmanSetTrajModelMat {
		: Get Cycle Time in seconds;
		: Set Kalman System Matrix;
		: Set Kalman Process noise covariance matrix;
		}
		End
		@enduml

  @return          -

  @param[in]       pTrajData : pointer to structure containing trajectory data
                      KafiEst.AMat : Full matrix, transition matrix             [float32 as defined in cml_kafi.h]
                      KafiEst.QMat : Diagonal matrix, process noise covariance  [float32 as defined in cml_kafi.h]

  @glob_in         pt_CPInput->t_RTE.pf_EgoLongVel : Ego speed  [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CP_v_KalmanSetTrajModelMat( const CP_t_TrajectoryData  *pTrajData )
{
  /* Get Cycle Time */
  const float32 fTc = SLATE_f_GetCPCycleTime();    /* in s   */
  
  float32 dx         = fTc * (*pt_CPInput->t_RTE.pf_EgoLongVel);
  float32 dx2half    = (dx * dx) / 2.0f;
  /*  float32 dx3sixth   = dx * dx2half / 3.0f;*/
  /*float32 dx4fourth  = dx2half * dx2half;*/
  /*float32 Tc2        = fTc * fTc;*/
  /*float32 Tc3        = fTc * Tc2;*/
  float32 temp; 

  /* Update System Matrix A */

  /* [ 1  0   0.5.*dx2   dx3./6    dx  -0.5.*dx.*Tc ] */
  /* [ 0  1   0.5.*dx2   dx3./6    dx  -0.5.*dx.*Tc ] */
  /* [ 0  0   1          dx        0    0           ] */
  /* [ 0  0   0          1         0    0           ] */
  /* [ 0  0   dx         0.5.*dx2  1   -Tc          ] */
  /* [ 0  0   0          0         0    1           ] */

  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0L, sY0L, 1.0f             );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0L, sTRAJ_C0,  dx2half          );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0L, sTRAJ_C1,  dx3sixth         );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0L, sPSI, dx               );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0L, sYRf, -0.5f * dx * fTc );*/

  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0R, sY0R, 1.0f             );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0R, sTRAJ_C0,  dx2half          );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0R, sTRAJ_C1,  dx3sixth         );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0R, sPSI, dx               );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sY0R, sYRf, -0.5f * dx * fTc );*/
 
  GDBKalmanSetMat(&pTrajData->KafiEst.AMat, CP_sTRAJ_C0,  CP_sTRAJ_C0,  1.0f             );
  GDBKalmanSetMat(&pTrajData->KafiEst.AMat, CP_sTRAJ_C0,  CP_sTRAJ_C1,  dx               );

  GDBKalmanSetMat(&pTrajData->KafiEst.AMat, CP_sTRAJ_C1,  CP_sTRAJ_C1,  1.0f             );

  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sPSI, sTRAJ_C0,  dx               );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sPSI, sTRAJ_C1,  dx2half          );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sPSI, sPSI, 1.0f             );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sPSI, sYRf, -fTc             );*/

  /*TPKalmanSetMat(&pTrajData->KafiEst.AMat, sYRf, sYRf, 1.0f             );*/


  /* Update System Noise Matrix Q */
  /*temp  = dx2half*NOISE_YRf_SQR*Tc3/6.0f;
  temp += ( NOISE_Y0_SQR + (dx3sixth * ( (2.0f*NOISE_Y0*NOISE_C1) + (dx3sixth*NOISE_C1_SQR) )) )*fTc;
  temp -= (NOISE_Y0+(dx3sixth*NOISE_C1))*NOISE_YRf*Tc2*dx*0.5f;*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.QMat, sY0L, sY0L, temp);*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.QMat, sY0R, sY0R, temp);*/
  temp = CP_TRAJ_NOISE_C1_SQR*fTc;
  GDBKalmanSetMat(&pTrajData->KafiEst.QMat, CP_sTRAJ_C0,  CP_sTRAJ_C0,  2.0f*dx2half*temp);
  GDBKalmanSetMat(&pTrajData->KafiEst.QMat, CP_sTRAJ_C1,  CP_sTRAJ_C1,  temp);
  /*TPKalmanSetMat(&pTrajData->KafiEst.QMat, sPSI, sPSI, (NOISE_YRf_SQR*Tc3/3.0f) + (dx4fourth*NOISE_C1_SQR*fTc) - (dx2half*NOISE_C1*NOISE_YRf*Tc2) );*/
  /*TPKalmanSetMat(&pTrajData->KafiEst.QMat, sYRf, sYRf, fTc*NOISE_YRf_SQR);*/
}

#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
/*************************************************************************************************************************
  Functionname:    CP_v_KalmanSetTraceTrajModelMat                                                                          */ /*!

  @brief           Initialize the Kalman Filter for combined trace calculation

  @description     Initialize the Kalman Filter for combined trace calculation

		@startuml
		Start
		Partition CP_v_KalmanSetTraceTrajModelMat {
		: Get Cycle Time in seconds;
		: Set Kalman System Matrix;
		: Set Kalman Process noise covariance matrix;
		}
		End
		@enduml

  @return          -

  @param[in]       pTraceTrajectory : pointer to structure containing trace trajectory data
                      KafiTraceEst.AMat : Full matrix, transition matrix             [float32 as defined in cml_kafi.h]
                      KafiTraceEst.QMat : Diagonal matrix, process noise covariance  [float32 as defined in cml_kafi.h]

  @glob_in         pt_CPInput->t_RTE.pf_EgoLongVel : Ego speed  [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component
                   CP_CFG_TRACE_TRAJ_KALMAN_FILTER: Switch to enable Kalman filtering after PSO

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         04/05/2020

  @author          aathira.elizabeth.binu@continental-corporation.com
                   mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/

static void CP_v_KalmanSetTraceTrajModelMat( const CP_t_TraceTrajectory * pTraceTrajectory )
{
  /* Get Cycle Time */
  const float32 fTc = SLATE_f_GetCPCycleTime();    /* in s   */
  
  float32 dx         = fTc * (*pt_CPInput->t_RTE.pf_EgoLongVel);
  float32 dx2half    = (dx * dx) / 2.0f;
  float32 temp; 

  /* Update System Matrix A */
  /* [1   dx] */
  /* [0   1 ] */

  /* Update System Matrix A */ 
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.AMat, CP_sTRACE_TRAJ_C0,  CP_sTRACE_TRAJ_C0,  1.0f             );
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.AMat, CP_sTRACE_TRAJ_C0,  CP_sTRACE_TRAJ_C1,  dx               );
  /*Index 1,0 not updated as its value is already initialized to 0*/
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.AMat, CP_sTRACE_TRAJ_C1,  CP_sTRACE_TRAJ_C1,  1.0f             );



  /* Update the process noise covariance matrix Q */
  /* [1   dx*dx*CP_TRAJ_NOISE_C1_SQR*dt] */
  /* [0         CP_TRAJ_NOISE_C1_SQR*dt] */

    temp = CP_TRAJ_NOISE_C1_SQR*fTc;
  /* Update process noise covariance matrix Q */ 
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.QMat, CP_sTRACE_TRAJ_C0,  CP_sTRACE_TRAJ_C0,  2.0f*dx2half*temp);
  GDBKalmanSetMat(&pTraceTrajectory->KafiTraceEst.QMat, CP_sTRACE_TRAJ_C1,  CP_sTRACE_TRAJ_C1,  temp);

}
/*************************************************************************************************************************
  Functionname:    CP_v_KalmanPredictTraceTrajectory                                                                        */ /*!

  @brief           Predict trace Trajectory state based on previously estimated state values

  @description     Predict trace Trajectory state based on previously estimated state values

		@startuml
		Start
		Partition CP_v_KalmanPredictTraceTrajectory  {
		: Initialize the Kalman Filter for combined trace calculation;
		: Create intermediate Matrixes used for the time Update;
		: Update Kalman Time;
		}
		End
		@enduml

  @return          -

  @param[in]       pTraceTrajectory : pointer to structure containing trace trajectory data
                      KafiTraceEst : The Kalman filter base data

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component
                   CP_CFG_TRACE_TRAJ_KALMAN_FILTER:Switch to enable Kalman filtering after PSO

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         - 4/05/2020
  @changed         

  @author          aathira.elizabeth.binu@continental-corporation.com
                   mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/
void CP_v_KalmanPredictTraceTrajectory( const CP_t_TraceTrajectory * pTraceTrajectory )
{
  GDBBaseMatrix_t WMat;
  GDBBaseMatrix_t DAMat;
  GDBBaseMatrix_t DAWVec;
  float32 WMatrix[CP_NB_TRACE_TRAJ_STATE*CP_NB_TRACE_TRAJ_STATE2];
  float32 DAMatrix[CP_NB_TRACE_TRAJ_STATE2];
  float32 DAWVector[CP_NB_TRACE_TRAJ_STATE2];

  /* Update A & Q Matrixes */
  CP_v_KalmanSetTraceTrajModelMat( pTraceTrajectory );

  /* Create intermediate Matrixes used for the time Update */
  GDBKalmanCreateMat(&WMat,     WMatrix,     MATTYPE_FULL,     CP_NB_TRACE_TRAJ_STATE,  CP_NB_TRACE_TRAJ_STATE2 );
  GDBKalmanCreateMat(&DAMat,    DAMatrix,    MATTYPE_DIAGONAL, CP_NB_TRACE_TRAJ_STATE2, CP_NB_TRACE_TRAJ_STATE2 );
  GDBKalmanCreateMat(&DAWVec,   DAWVector,   MATTYPE_VECTOR,   CP_NB_TRACE_TRAJ_STATE2, (uint8)1  );

  /* Predict the actual state from the old estimated states */
  GDBKalmanTimeUpdate(&pTraceTrajectory->KafiTraceEst, WMat, DAMat, DAWVec);
}
#endif
/*************************************************************************************************************************
  Functionname:    CP_f_KalmanGetTrajEstState                                                                          */ /*!

  @brief           Return Value of Estimated State X Vector

  @description     Return Value of Estimated State X Vector

		@startuml
		Start
		Partition CP_f_KalmanGetTrajEstState {
		: Return Value of Estimated State X Vector;
		}
		End
		@enduml

  @return          fValue : Returns an element of a matrix used by the Kalman filter (float32)

  @param[in]       pTrajData : pointer to structure containing trajectory data
                      KafiEst.XVec : Vector, estimated state vector             [float32 as defined in cml_kafi.h]
  @param[in]       uiVarState : row index to the matrix                         [uint8 datatype as defined in Platform_Types.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          Norman.Apel@contiautomotive.com
*************************************************************************************************************************/
float32 CP_f_KalmanGetTrajEstState(const CP_t_TrajectoryData * pTrajData , uint8 uiVarState)
{
  float32 fValue = GDBKalmanGetMat(&pTrajData->KafiEst.XVec, uiVarState, (uint8)0);

  return fValue;
}

/*************************************************************************************************************************
  Functionname:    CP_f_KalmanGetTrajErrorCov                                                                          */ /*!

  @brief           Return Value of error covariance P Matrix

  @description     Return Value of error covariance P Matrix

		@startuml
		Start
		Partition CP_f_KalmanGetTrajErrorCov {
		: Return Value of error covariance P Matrix;
		}
		End
		@enduml

  @return          fValue : Returns an element of a matrix used by the Kalman filter (float32)

  @param[in]       pTrajData : pointer to structure containing trajectory data
                      KafiEst.PDiagMat : diagonal matrix, covariance            [float32 as defined in cml_kafi.h]
  @param[in]       uiVarState : row index to the matrix                         [uint8 datatype as defined in Platform_Types.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/11/2015

  @author          Norman.Apel@contiautomotive.com
*************************************************************************************************************************/
float32 CP_f_KalmanGetTrajErrorCov(const CP_t_TrajectoryData * pTrajData , uint8 uiVarState)
{
  float32 fValue = GDBKalmanGetMat(&pTrajData->KafiEst.PDiagMat, uiVarState, uiVarState);

  return fValue;
}
#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
/*************************************************************************************************************************
  Functionname:    CP_f_KalmanGetTraceTrajEstState                                                                          */ /*!

  @brief           Return Value of Estimated State X Vector for trace trajectory

  @description     Return Value of Estimated State X Vector for trace trajectory

		@startuml
		Start
		Partition CP_f_KalmanGetTraceTrajEstState {
		: Return Value of Estimated State X Vector for trace trajectory;
		}
		End
		@enduml

  @return          fValue : Returns an element of a matrix used by the Kalman filter (float32)

  @param[in]       pTraceTrajectory : pointer to structure containing trace trajectory data
                   KafiTraceEst.XVec : Vector, estimated state vector             [float32 as defined in cml_kafi.h]
  @param[in]       uiVarState : row index to the matrix                           [uint8 datatype as defined in Platform_Types.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component
                   CP_CFG_TRACE_TRAJ_KALMAN_FILTER:Switch to enable Kalman filtering after PSO

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         05/05/2020

  @author          aathira.elizabeth.binu@continental-corporation.com
                   mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/
float32 CP_f_KalmanGetTraceTrajEstState(const CP_t_TraceTrajectory * pTraceTrajectory , uint8 uiVarState)
{
  float32 fValue = GDBKalmanGetMat(&pTraceTrajectory->KafiTraceEst.XVec, uiVarState, (uint8)0);

  return fValue;
}
#endif
/** @} end defgroup */
#endif  /* FCT_CFG_COURSE_PREDICTION */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
