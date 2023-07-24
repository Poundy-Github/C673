/*! \file **********************************************************************

  COMPANY:                   Continental Teves AG & Co. oHG

  CPU:                       CPU-Independent

  COMPONENT:                 TJA (Traffic Jam Assist)

  MODULNAME:                 fusionKalmanFilter.c

  DESCRIPTION:               implements kalman filter for trajectory estimation

  AUTHOR:                    $Author: Nastasa, Elena (uidt4846) $

  CREATION DATE:             $Date: 2019/07/17 12:06:13CEST $

  VERSION:                   $Revision: 1.1 $

  CHANGES:                
  ---*/ /*---


**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fusionKalmanFilter.h"
#include "cml_ext.h" /* include common math library */
// #include "cml_adapted.h" /* include customized cml functions for matrix inversion with lower F32_ZERO constant */

#ifdef LCOF_USE_DEBUG_OUTPUTS
#include <string.h>/*for memcpy*/
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/
#ifndef FALSE
#define FALSE (0u)
#endif
#ifndef TRUE
#define TRUE (1u)
#endif

/*length of the KF state vector*/
#define STATE_LENGTH (4u)
/*length of th measurement vector for lane measurements*/
#define LANE_MEAS_VEC_SIZE (4u)
/*length of th measurement vector for object measurements*/
#define OBJ_MEAS_VEC_SIZE (1u)


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

#if !defined(MATH_LOCAL_SFUNCTION) && P_TJATTG_PARAMS_TUNABLE
#define LCOF_START_TUNABLES
#include "Adp_MemMap.h"
#endif
/*minimum scaling divisor for the variance used by the outlier rejection mechanism*/
LCOF_PARAM_MODIFIER real32_T MinScalWeightVar_nu  = (1.0e-4f);
#if !defined(MATH_LOCAL_SFUNCTION) && P_TJATTG_PARAMS_TUNABLE
#define LCOF_STOP_TUNABLES
#include "Adp_MemMap.h"
#endif

#if !defined(MATH_LOCAL_SFUNCTION) && P_TJATTG_PARAMS_TUNABLE
#define LCOF_START_TUNABLES
#include "Adp_MemMap.h"
#endif
/*parameter "a" of the outlier rejection mechanism, see publication 
Ting, J., Theodorou, E., Schaal, S. Learning an Outlier-Robust Kalman Filter, European Conference on Machine Learning (ECML 2007), http://www-clmc.usc.edu/publications/T/ting-ECML2007.pdf */
LCOF_PARAM_MODIFIER real32_T OutlierRejectParamA_nu = (1.0f);
#if !defined(MATH_LOCAL_SFUNCTION) && P_TJATTG_PARAMS_TUNABLE
#define LCOF_STOP_TUNABLES
#include "Adp_MemMap.h"
#endif

#if !defined(MATH_LOCAL_SFUNCTION) && P_TJATTG_PARAMS_TUNABLE
#define LCOF_START_TUNABLES
#include "Adp_MemMap.h"
#endif
/*switch between fixed obj pos std. deviation and the one coming from the EM*/
LCOF_PARAM_MODIFIER boolean_T P_TJATTG_UseEmObjStdDev_bool = FALSE;
#if !defined(MATH_LOCAL_SFUNCTION) && P_TJATTG_PARAMS_TUNABLE
#define LCOF_STOP_TUNABLES
#include "Adp_MemMap.h"
#endif



/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void predictState(real32_T fVelX_mps, real32_T fYawRate_rps, real32_T fDeltaT_s, real32_T CrvChngDecay_nu, real32_T PredVelXVar_m2, real32_T PredYawRtVar_r2ps2, real32_T ModelPosYVar_m2, real32_T ModelYawVar_rad2, real32_T ModelCrvVar_1pm2, real32_T ModelCrvChngVar_1pm4, CML_t_Matrix* currentState, CML_t_Matrix* currentCovariance);
static boolean_T updateStateByObjPos(real32_T fObjXPos_met, real32_T fObjYPos_met, real32_T fObjXPosStdDev_met, real32_T fObjYPosStdDev_met, real32_T ObjMeasPosXVar_m2, real32_T ObjMeasPosYVar_m2, CML_t_Matrix* currentState, CML_t_Matrix* currentCovariance);
static boolean_T updateStateByLaneClothoid(real32_T fLnPosY0_met, real32_T fLnHeading_rad, real32_T fLnCrv_1pm, real32_T fLnCrvChng_1pm2, real32_T LnMeasPosYVar_m2, real32_T LnMeasHeadVar_rad2, real32_T LnMeasCrvVar_1pm2, real32_T LnMeasCrvChngVar_1pm4, CML_t_Matrix* currentState, CML_t_Matrix* currentCovariance);
static real32_T evalState(const CML_t_Matrix* currentState, real32_T xPos);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************
Functionname:    evalState                                      */ /*!

@brief           evaluate the trajectory state at a given distance to obtain the lateral position at that point

@description     clothoid approximation y = y0 + x*tan(psi) + x*x*c0/2.0 + x*x*x*c1/6.0
                 state vector is [y0 psi c0 c1]; remark: tan(psi) is approximated by psi

@param[in]       currentState : current trajectory state estimate

@param[in]       xPos : xPosition at which the trajectory is evaluated

@return          y-position

@author          Hendrik Deusch
**************************************************************************** */
static real32_T evalState(const CML_t_Matrix* currentState, real32_T xPos){
  /*approximate tan(psi) by psi  */
  return CML_GetMatrixElement(currentState,0,0) + (xPos*CML_GetMatrixElement(currentState,1,0)) + (xPos*xPos *CML_GetMatrixElement(currentState,2,0)/2.0f) +  (xPos*xPos *xPos * CML_GetMatrixElement(currentState,3,0)/6.0f);
}



/* ****************************************************************************
Functionname:    predictState                                      */ /*!

@brief           executes standard KF state prediction based on the passed time, vehicle speed and yaw rate

@description     prediction is just approximated, only reflects dominant effects
                 standard KF equations x_k|k-1 = F*x_k-1 +  B*u; P_k|k-1 = F*P_k*F^T+Q

@param[in]       fVelX_mps : vehicle velocity

@param[in]       fYawRate_rps : yaw rate of the vehicle

@param[in]       fDeltaT_s : passed time since last prediction

@param[in,out]   currentState : current state estimate (out --> predicted)

@param[in,out]   currentCovariance : covariance matrix of current state estimate (out --> predicted)

@return          void

@author          Hendrik Deusch
**************************************************************************** */
static void predictState(real32_T fVelX_mps, real32_T fYawRate_rps, real32_T fDeltaT_s, real32_T CrvChngDecay_nu, real32_T PredVelXVar_m2, real32_T PredYawRtVar_r2ps2, real32_T ModelPosYVar_m2, real32_T ModelYawVar_rad2, real32_T ModelCrvVar_1pm2, real32_T ModelCrvChngVar_1pm4, CML_t_Matrix* currentState, CML_t_Matrix* currentCovariance){
  CML_CreateMatrixLocal(procNoiseCov, STATE_LENGTH, STATE_LENGTH)/*Process Noise Matrix Q*/
  CML_CreateMatrixLocal(stateTransition,STATE_LENGTH,STATE_LENGTH)/*State Transition Matrix F*/
  CML_CreateMatrixLocal(tmpCovMat, STATE_LENGTH, STATE_LENGTH)/*temporary matrix for intermediate results*/
  CML_CreateMatrixLocal(predictedState, STATE_LENGTH, 1)/*predicted state x_k|k-1*/
  CML_CreateMatrixLocal(dxDotDv, STATE_LENGTH, 1)/*dependence on speed d(F(v)*x)/dv*/
  uint8_T i,j;
  /*initialization of F*/
  CML_v_CreateIdentityMatrix(stateTransition,STATE_LENGTH);/*does not allocate, only writes the values*/
  CML_GetMatrixElement(stateTransition,0,1) = fVelX_mps*fDeltaT_s; /*influence of heading on lateral position*/
  CML_GetMatrixElement(stateTransition,1,2) = fVelX_mps*fDeltaT_s; /*influence of curvature on heading*/
  CML_GetMatrixElement(stateTransition,2,3) = fVelX_mps*fDeltaT_s; /*influence of change of curvature on curvature*/
  CML_GetMatrixElement(stateTransition,3,3) = CrvChngDecay_nu;
  /*initialize dependence on speed vector, i.e. d(F(v)*x)/dv*/
  CML_GetMatrixElement(dxDotDv,0,0) = fDeltaT_s*CML_GetMatrixElement(currentState,1,0);
  CML_GetMatrixElement(dxDotDv,1,0) = fDeltaT_s*CML_GetMatrixElement(currentState,2,0);
  CML_GetMatrixElement(dxDotDv,2,0) = fDeltaT_s*CML_GetMatrixElement(currentState,3,0);
  CML_GetMatrixElement(dxDotDv,3,0) = 0.0f;

  for(i = 0; i < STATE_LENGTH; i++){
    for(j = 0; j < STATE_LENGTH; j++){
      /*process noise covariance from speed uncertainty*/
      CML_GetMatrixElement(procNoiseCov,i,j) = PredVelXVar_m2*CML_GetMatrixElement(dxDotDv,i,0)*CML_GetMatrixElement(dxDotDv,j,0);
    }
  }
  /*account for additive model uncertainty*/
  CML_GetMatrixElement(procNoiseCov,0,0) += ModelPosYVar_m2;
   /*considers also process noise from yaw rate uncertainty*/
  CML_GetMatrixElement(procNoiseCov,1,1) += ModelYawVar_rad2 + (PredYawRtVar_r2ps2*fDeltaT_s*fDeltaT_s);
  CML_GetMatrixElement(procNoiseCov,2,2) += ModelCrvVar_1pm2;
  CML_GetMatrixElement(procNoiseCov,3,3) += ModelCrvChngVar_1pm4;

  /*predict state - x_k|k-1 = F*x_k-1 +  B*u*/
  CML_v_MultiplyMatrices(predictedState, stateTransition,currentState);/*F*x_k-1*/
  CML_GetMatrixElement(predictedState,1,0) -= fYawRate_rps*fDeltaT_s; /*use control input (B*u) with B = [0 -dt 0 0]'*/
  /*copy to current state*/
  CML_v_CopyMatrix(currentState, predictedState);

  /*predict covariance P_k|k-1 = F*P_k*F^T+Q*/
  CML_v_MultiplyMatrices(tmpCovMat, stateTransition, currentCovariance);/*tmpCov = F*P_k-1*/
  CML_v_MultiplyMatrixWithTranspose(currentCovariance,tmpCovMat,stateTransition);/*P_k|k-1 = tmpCov * F^T*/
  CML_v_AddMatrices(currentCovariance, currentCovariance, procNoiseCov); /*P_k|k-1 = (F*P)*(F^T)+Q*/
}


/* ****************************************************************************
Functionname:    updateStateByObjPos                                      */ /*!

@brief           updates the KF state using an object measurement

@description     only measured object position is used to update full state
                 using standard KF state update x_k = x_k|k-1+K*(z - H*x_k|k-1) with
                 Joseph-Formulation for covariance-update P_k = (1-k*H)*P_k|k-1*(1-k*H)^T + K*R*K^T

@param[in]       fObjXPos_met : target object x position

@param[in]       fObjYPos_met : target object y position

@param[in]       fObjXPosStdDev_met : target object x position standard deviation

@param[in]       fObjYPosStdDev_met : target object y position standard deviation

@param[in,out]   currentState : current state estimate (out --> updated)

@param[in,out]   currentCovariance : covariance matrix of current state estimate (out --> updated)

@return          true if operation was successful

@author          Hendrik Deusch
**************************************************************************** */
static boolean_T updateStateByObjPos(real32_T fObjXPos_met, real32_T fObjYPos_met, real32_T fObjXPosStdDev_met, real32_T fObjYPosStdDev_met, real32_T ObjMeasPosXVar_m2, real32_T ObjMeasPosYVar_m2, CML_t_Matrix* currentState, CML_t_Matrix* currentCovariance){
  CML_CreateMatrixLocal(measMatrix,OBJ_MEAS_VEC_SIZE,STATE_LENGTH) /* measurement matrix H --> since we only measure lat dist it is actually a "row"-vector*/
  CML_CreateMatrixLocal(kalmanGain,STATE_LENGTH, OBJ_MEAS_VEC_SIZE) /*Kalman Gain K*/
  CML_CreateMatrixLocal(tmpRowVec,OBJ_MEAS_VEC_SIZE, STATE_LENGTH) /*needed for intermediate results*/
  CML_CreateMatrixLocal(tmpMat,STATE_LENGTH, STATE_LENGTH) /*needed for intermediate results*/
  CML_CreateMatrixLocal(tmpCovMat,STATE_LENGTH, STATE_LENGTH) /*needed for intermediate covariance results*/
  CML_CreateMatrixLocal(innovationCovariance, OBJ_MEAS_VEC_SIZE,OBJ_MEAS_VEC_SIZE)/*innovation covariance S is actually a scalar*/
  CML_CreateMatrixLocal(innovationResidual, OBJ_MEAS_VEC_SIZE,OBJ_MEAS_VEC_SIZE)/*innovation residual is actually a scalar*/
  real32_T fVarScaling = 1.0f;
  // real32_T fCurPosYVariance = (P_TJATTG_UseEmObjStdDev_bool? (fObjYPosStdDev_met*fObjYPosStdDev_met):(ObjMeasPosYVar_m2));
  real32_T fCurPosYVariance = ObjMeasPosYVar_m2;  
  real32_T fEstObjLatPos_m = evalState(currentState, fObjXPos_met);
  real32_T fDyDx = CML_GetMatrixElement(currentState,1,0) + CML_GetMatrixElement(currentState,2,0)*fObjXPos_met + fObjXPos_met*fObjXPos_met*0.5f*CML_GetMatrixElement(currentState,3,0);/*meas uncertainty of x affecting y --> dy/dx*/
  real32_T fMeasNoise = 0.0f;/*R*/
  uint8_T i,j;
  /*fill measurement matrix*/
  CML_GetMatrixElement(measMatrix,0,0) = 1.0;
  CML_GetMatrixElement(measMatrix,0,1) = fObjXPos_met;
  CML_GetMatrixElement(measMatrix,0,2) = fObjXPos_met*fObjXPos_met*0.5f;
  CML_GetMatrixElement(measMatrix,0,3) = fObjXPos_met*fObjXPos_met*fObjXPos_met/6.0f;
  /*outlier rejection --> scale variance for implausible values, see Ting, Theodoru & Schaal (2007))*/
  /* AlFe: ZDV protection added using CML_f_AlmostZero */
  // if(CML_f_IsNonZero(fObjYPos_met - fEstObjLatPos_m) && CML_f_IsNonZero(1.0f+(fObjYPos_met - fEstObjLatPos_m))){
    // if(P_TJATTG_UseEmObjStdDev_bool && CML_f_IsNonZero(fObjYPosStdDev_met*fObjYPosStdDev_met)){
        // polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator
        // fVarScaling = (OutlierRejectParamA_nu + 0.5f) / (1.0f+(fObjYPos_met - fEstObjLatPos_m) / (fObjYPosStdDev_met*fObjYPosStdDev_met) * (fObjYPos_met - fEstObjLatPos_m));
    // }else if(CML_f_IsNonZero(ObjMeasPosYVar_m2)){
        // polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator
        // fVarScaling = (OutlierRejectParamA_nu + 0.5f) / (1.0f+(fObjYPos_met - fEstObjLatPos_m) / ObjMeasPosYVar_m2 * (fObjYPos_met - fEstObjLatPos_m));
    // }else{
        // fVarScaling = MinScalWeightVar_nu;
    // }
  // }else{
      // fVarScaling = MinScalWeightVar_nu;
  // }
  
  fVarScaling = CML_f_Max(fVarScaling, MinScalWeightVar_nu);
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  fCurPosYVariance /= fVarScaling;
  // if(P_TJATTG_UseEmObjStdDev_bool){
    // fMeasNoise = fCurPosYVariance + fDyDx * fObjXPosStdDev_met*fObjXPosStdDev_met * fDyDx;
  // }else{
    // fMeasNoise = fCurPosYVariance + fDyDx * ObjMeasPosXVar_m2 * fDyDx;
  // }
  
  fMeasNoise = fCurPosYVariance + fDyDx * ObjMeasPosXVar_m2 * fDyDx;
  
  
  /*standard KF Update*/
  /*calculate innovation covariance S = (H*P_k|k-1)H^T + R, in this case S is scalar*/
  CML_v_MultiplyMatrices(tmpRowVec, measMatrix, currentCovariance);/*H*P_k|k-1*/
  CML_v_MultiplyMatrixWithTranspose(innovationCovariance, tmpRowVec, measMatrix); /*(H*P_k|k-1)H^T */
  CML_GetMatrixElement(innovationCovariance,0,0) += fMeasNoise;/*S = (H*P_k|k-1)H^T + R*/

  if(CML_f_IsNonZero(CML_GetMatrixElement(innovationCovariance,0,0))){/*avoid division by value too close to zero*/
    /*calculate Kalman gain by K = (P_k|k-1*H^T)*S^-1*/
    CML_v_MultiplyMatrixWithTranspose(kalmanGain, currentCovariance, measMatrix);/*(P_k|k-1*H^T)*/

    for(i = 0; i < STATE_LENGTH; i++){
      CML_GetMatrixElement(kalmanGain, i,0) /= CML_GetMatrixElement(innovationCovariance,0,0);  /*K = (P_k|k-1*H^T)*S^-1*/
    }
    /*calculate the innovation residual z - H*x_k|k-1*/
    CML_v_MultiplyMatrices(innovationResidual, measMatrix, currentState);/*H*x_k|k-1*/
    CML_GetMatrixElement(innovationResidual,0,0) = fObjYPos_met - CML_GetMatrixElement(innovationResidual,0,0);/*z - H*x_k|k-1*/

    /*update state x_k = x_k|k-1+K*(z - H*x_k|k-1)*/
    for(i = 0; i < STATE_LENGTH; i++){
      CML_GetMatrixElement(currentState,i,0) += CML_GetMatrixElement(kalmanGain, i,0)*CML_GetMatrixElement(innovationResidual,0,0);
    }
    /*update covariance using Joseph equation to be more robust round-off errors (1-k*H)*P_k|k-1*(1-k*H)^T + K*R*K^T*/
    /*tmpMat = (1-k*H)*/
    CML_v_CreateIdentityMatrix(tmpMat,STATE_LENGTH);
    for(i = 0; i < STATE_LENGTH; i++){
      for(j = 0; j < STATE_LENGTH; j++){
        CML_GetMatrixElement(tmpMat,i,j) -= CML_GetMatrixElement(kalmanGain,i,0)*CML_GetMatrixElement(measMatrix,0,j);
      }
    }
    CML_v_MultiplyMatrices(tmpCovMat, tmpMat, currentCovariance);/*tmpCovMat = (1-k*H)*P_k|k-1*/
    CML_v_MultiplyMatrixWithTranspose(currentCovariance, tmpCovMat, tmpMat);/*currentCovariance = (1-k*H)*P_k|k-1*(1-k*H)^T*/
    /*finally add K*R*K^T*/
    for(i = 0; i < STATE_LENGTH; i++){
      for(j = 0; j < STATE_LENGTH; j++){
        CML_GetMatrixElement(currentCovariance,i,j) += CML_GetMatrixElement(kalmanGain,i,0)*fMeasNoise*CML_GetMatrixElement(kalmanGain,j,0);/*add K*R*K^T*/
      }
    }
    return TRUE;
  }else{
    return FALSE;
  }
}

/* ****************************************************************************
Functionname:    updateStateByLaneClothoid                                      */ /*!

@brief           updates the KF state using an object measurement

@description     measured lane clothoid approximation is used to update full state (i.e. H = 1)
                 using standard KF state update x_k = x_k|k-1+K*(z - H*x_k|k-1) with
                 Joseph-Formulation for covariance-update P_k = (1-k*H)*P_k|k-1*(1-k*H)^T + K*R*K^T

@param[in]       fLnPosY0_met : lane y-position

@param[in]       fLnHeading_rad : lane heading

@param[in]       fLnCrv_1pm : lane curvature

@param[in]       fLnCrvChng_1pm2 : lane change of curvature

@param[in,out]   currentState : current state estimate (out --> updated)

@param[in,out]   currentCovariance : covariance matrix of current state estimate (out --> updated)

@return          true if operation was successful (only false if inversion fails)

@author          Hendrik Deusch
**************************************************************************** */
static boolean_T updateStateByLaneClothoid(real32_T fLnPosY0_met, real32_T fLnHeading_rad, real32_T fLnCrv_1pm, real32_T fLnCrvChng_1pm2, real32_T LnMeasPosYVar_m2, real32_T LnMeasHeadVar_rad2, real32_T LnMeasCrvVar_1pm2, real32_T LnMeasCrvChngVar_1pm4, CML_t_Matrix* currentState, CML_t_Matrix* currentCovariance){
  unsigned int i = 0;
  unsigned int j = 0;
  real32_T fVarScalingDivisor = 1.0f;
  real32_T fVarScaling  =(OutlierRejectParamA_nu + 0.5f);
  CML_CreateMatrixLocal(measNoise, LANE_MEAS_VEC_SIZE, LANE_MEAS_VEC_SIZE)
  CML_CreateMatrixLocal(innovationCovariance, LANE_MEAS_VEC_SIZE, LANE_MEAS_VEC_SIZE)
  CML_CreateMatrixLocal(innovationCovarianceInverse, LANE_MEAS_VEC_SIZE, LANE_MEAS_VEC_SIZE)
  CML_CreateMatrixLocal(kalmanGain, STATE_LENGTH, LANE_MEAS_VEC_SIZE) 
  CML_CreateMatrixLocal(kalmanGainMeas, STATE_LENGTH, LANE_MEAS_VEC_SIZE)
  CML_CreateMatrixLocal(tmpCovKRK, STATE_LENGTH, LANE_MEAS_VEC_SIZE)
  CML_CreateMatrixLocal(tmpCovJE, STATE_LENGTH, LANE_MEAS_VEC_SIZE) 
  CML_CreateMatrixLocal(measVec, LANE_MEAS_VEC_SIZE, 1u)
  CML_CreateMatrixLocal(innovationResidual, LANE_MEAS_VEC_SIZE, 1u)
  CML_CreateMatrixLocal(stateUpdate, STATE_LENGTH, 1u)
 
  CML_GetMatrixElement(measVec,0,0) = fLnPosY0_met;
  CML_GetMatrixElement(measVec,1,0) = fLnHeading_rad;
  CML_GetMatrixElement(measVec,2,0) = fLnCrv_1pm;
  CML_GetMatrixElement(measVec,3,0) = fLnCrvChng_1pm2;
  /*calulate scaling weight for measurement --> outlier rejection by increasing variance see Ting, Theodoru & Schaal (2007))*/
  /*AlFe: ZDV protection added using CML_f_AlmostZero*/
  LnMeasPosYVar_m2 = CML_f_Max(LnMeasPosYVar_m2, CML_f_AlmostZero);
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  fVarScalingDivisor += (CML_GetMatrixElement(measVec,0,0)-CML_GetMatrixElement(currentState,0,0))/LnMeasPosYVar_m2 *(CML_GetMatrixElement(measVec,0,0)-CML_GetMatrixElement(currentState,0,0));
  LnMeasHeadVar_rad2 = CML_f_Max(LnMeasHeadVar_rad2, CML_f_AlmostZero);
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  fVarScalingDivisor += (CML_GetMatrixElement(measVec,1,0)-CML_GetMatrixElement(currentState,1,0))/LnMeasHeadVar_rad2 *(CML_GetMatrixElement(measVec,1,0)-CML_GetMatrixElement(currentState,1,0));
  LnMeasCrvVar_1pm2 = CML_f_Max(LnMeasCrvVar_1pm2, CML_f_AlmostZero);
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  fVarScalingDivisor += (CML_GetMatrixElement(measVec,2,0)-CML_GetMatrixElement(currentState,2,0))/LnMeasCrvVar_1pm2 *(CML_GetMatrixElement(measVec,2,0)-CML_GetMatrixElement(currentState,2,0));
  LnMeasCrvChngVar_1pm4 = CML_f_Max(LnMeasCrvChngVar_1pm4, CML_f_AlmostZero);
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  fVarScalingDivisor += (CML_GetMatrixElement(measVec,3,0)-CML_GetMatrixElement(currentState,3,0))/LnMeasCrvChngVar_1pm4 *(CML_GetMatrixElement(measVec,3,0)-CML_GetMatrixElement(currentState,3,0));
  
  fVarScalingDivisor = CML_f_Max(fVarScalingDivisor, CML_f_AlmostZero);
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  fVarScaling /= fVarScalingDivisor;
  fVarScaling = CML_f_Max(fVarScaling, MinScalWeightVar_nu);
  
  /*scale variances by outlier rejection weight --> store in measuremnet noise matrix R*/
  CML_v_InitMatrix(measNoise, LANE_MEAS_VEC_SIZE, LANE_MEAS_VEC_SIZE, 0.0f);/*Measurement noise is a diagonal matrix with the variances of the respective measured quantities on the diagonal*/
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  CML_GetMatrixElement(measNoise,0,0) = LnMeasPosYVar_m2/fVarScaling;
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  CML_GetMatrixElement(measNoise,1,1) = LnMeasHeadVar_rad2/fVarScaling;
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  CML_GetMatrixElement(measNoise,2,2) = LnMeasCrvVar_1pm2/fVarScaling;
  /* polyspace<RTE:ZDV:Not a defect:No action planned> max function CML_f_Max used for denominator */
  CML_GetMatrixElement(measNoise,3,3) = LnMeasCrvChngVar_1pm4/fVarScaling;

  /*standard KF Update*/

  /*calculate innovation covariance S = (H*P_k|k-1)H^T + R with H = 1 --> S = P_k|k-1 + R*/
  CML_v_AddMatrices(innovationCovariance, currentCovariance, measNoise);
  /*invert innov Cov*/
  CML_v_InvertMatrix(innovationCovarianceInverse,innovationCovariance);
  if(innovationCovarianceInverse->Desc.col > 0){/*if inversion fails num. of cols and rows are set to 0*/
    /*Kalman gain*/ /*K = (P_k|k-1*H^T)*S^-1 with H = 1 --> K = P_k|k-1*S^-1*/
    CML_v_MultiplyMatrices(kalmanGain, currentCovariance, innovationCovarianceInverse);
    /*calculate innovation residual y = z - H*x_k|k-1 with H being 1*/
    CML_v_SubtractMatrices(innovationResidual, measVec, currentState);
    /*update state x_k = x_k|k-1 + K*y*/
    CML_v_MultiplyMatrices(stateUpdate, kalmanGain,innovationResidual);/*K*y*/
    CML_v_AddMatrices(currentState, currentState, stateUpdate);

    /*update covariance using Joseph equation to be more robust round-off errors (1-K*H)*P_k|k-1*(1-K*H)^T + K*R*K^T simplifies to (1-K)*P_k|k-1*(1-K)^T + K*R*K^T*/

    /*kalmanGainMeas <-- (1-K*H)*/
    CML_v_CreateIdentityMatrix(kalmanGainMeas,LANE_MEAS_VEC_SIZE);
    CML_v_SubtractMatrices(kalmanGainMeas, kalmanGainMeas, kalmanGain);

    CML_v_MultiplyMatrices(tmpCovJE, kalmanGainMeas, currentCovariance);/*(1-K*H)*P_k|k-1*/
    CML_v_MultiplyMatrixWithTranspose(currentCovariance, tmpCovJE, kalmanGainMeas);/*P = tmpCovJE*((1-K*H)^T)
                                                                                   /*calc --> K*R*K^T*/
    CML_v_MultiplyMatrices(tmpCovJE, kalmanGain, measNoise);
    CML_v_MultiplyMatrixWithTranspose(tmpCovKRK, tmpCovJE, kalmanGain);
    /*add K*R*K^T*/
    CML_v_AddMatrices(currentCovariance,currentCovariance, tmpCovKRK);
    return TRUE;
  }else{
    /*inversion failed*/
    return FALSE;
  }
}

void fusionTgtCorridor(const fusionKFInput* input, fusionKFOutput* output){
  CML_CreateMatrix(currentState,STATE_LENGTH,1) /*create state & cov matrix with static memory allocation*/
  CML_CreateMatrix(currentCovariance,STATE_LENGTH,STATE_LENGTH)
  static boolean_T bLastTrajValid = FALSE;
  boolean_T bTrajValid = TRUE;
  
  if((input->bPrediction_bool) || (input->bLnValid_nu) || (input->bObjValid_nu)){ /*predict traj on degradation, bridging of lanes or on imminent update of any kind*/
    /*consider initialization*/
    if((bLastTrajValid == FALSE) && (input->bLnValid_nu) && !(input->bPrediction_bool)){
      /*initialize state by setting it to the current value of the measured lanes and skipping the first filter cycle in order to reduce settling time*/
      /*if only object is available we prefer to initialize state with all zeros*/
      CML_GetMatrixElement(currentState,0,0) = input->fLnPosY0_met;
      CML_GetMatrixElement(currentState,1,0) = input->fLnHeading_rad;
      CML_GetMatrixElement(currentState,2,0) = input->fLnCrv_1pm;
      CML_GetMatrixElement(currentState,3,0) = input->fLnChngOfCrv_1pm2;
      CML_v_InitMatrix(currentCovariance,STATE_LENGTH,STATE_LENGTH,0.0f);
      /*TODO: should the initial variances be larger?*/
      CML_GetMatrixElement(currentCovariance,0,0) = input->LnMeasPosYVar_m2;
      CML_GetMatrixElement(currentCovariance,1,1) = input->LnMeasHeadVar_rad2;
      CML_GetMatrixElement(currentCovariance,2,2) = input->LnMeasCrvVar_1pm2;
      CML_GetMatrixElement(currentCovariance,3,3) = input->LnMeasCrvChngVar_1pm4;
    }else{
      /*normal operation mode -> first predict*/
      predictState(input->fVelX_mps, input->fYawRate_rps, input->fCycleTime_sec, input->CrvChngDecay_nu, input->PredVelXVar_m2, input->PredYawRtVar_r2ps2, input->ModelPosYVar_m2, input->ModelYawVar_rad2, input->ModelCrvVar_1pm2, input->ModelCrvChngVar_1pm4, currentState, currentCovariance);
      if(input->bLnValid_nu){ /*skip update if lanes are valid but bridged*/
        /*lane measurement update*/
        bTrajValid = updateStateByLaneClothoid(input->fLnPosY0_met, input->fLnHeading_rad, input->fLnCrv_1pm, input->fLnChngOfCrv_1pm2, input->LnMeasPosYVar_m2, input->LnMeasHeadVar_rad2, input->LnMeasCrvVar_1pm2, input->LnMeasCrvChngVar_1pm4, currentState, currentCovariance);
        // if(input->bResetPosYState_bool){
        	// CML_GetMatrixElement(currentState,0,0) = input->fLnPosY0_met;
        // }
      }else{
        /*no update by lane data*/
      }
      if(!(input->bPrediction_bool) && bTrajValid && input->bObjValid_nu){ /*if we degrade or already invalidated the traj by a bad lane update we skip object update*/
        /*object update*/
        bTrajValid = updateStateByObjPos(input->fObjXPos_met, input->fObjYPos_met, input->fObjXPosStdDev_met, input->fObjYPosStdDev_met, input->ObjMeasPosXVar_m2, input->ObjMeasPosYVar_m2, currentState, currentCovariance);
      }else{
        /*no update by object position*/
      }
    }
    bLastTrajValid = bTrajValid;
    output->bTrajValid_nu = bTrajValid; /*if this is false also we had an update, it shall trigger degradation*/
    output->fPosY0_met = CML_GetMatrixElement(currentState,0,0);
    output->fHeading_rad = CML_GetMatrixElement(currentState,1,0);
    output->fCrv_1pm = CML_GetMatrixElement(currentState,2,0);
    output->fChngOfCrv_1pm2 = CML_GetMatrixElement(currentState,3,0);    

  }else{ /*reset filter*/
    bLastTrajValid = FALSE;
    output->bTrajValid_nu = FALSE;
    output->fPosY0_met = 0.0f;
    output->fHeading_rad = 0.0f;
    output->fCrv_1pm = 0.0f;
    output->fChngOfCrv_1pm2 = 0.0f;
    /*TODO: should the initial variances be larger?*/
    CML_v_InitMatrix(currentCovariance,STATE_LENGTH,STATE_LENGTH,0.0f);
    CML_v_InitMatrix(currentState,STATE_LENGTH,1u,0.0f);
  }
  
// #ifdef LCOF_USE_DEBUG_OUTPUTS
//   memcpy(output->fKFCovarianceMatrix,currentCovariance->pData,currentCovariance->Desc.maxsize*sizeof(real32_T));
// #endif
  
}

