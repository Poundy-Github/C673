/*! \file **********************************************************************

  COMPANY:                   Continental Teves AG & Co. oHG

  CPU:                       CPU-Independent

  COMPONENT:                 TJA (Traffic Jam Assist)

  MODULNAME:                 polyfitTgtObjectClothoid.c

  DESCRIPTION:               implements polyfit for target object trajectory estimation

  AUTHOR:                    $Author: Nastasa, Elena (uidt4846) $

  CREATION DATE:             $Date: 2019/07/17 12:10:33CEST $

  VERSION:                   $Revision: 1.4 $

  CHANGES:                
  ---*/ /*---


**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "polyfitTgtObjectClothoid.h"
#include "cml_ext.h" /* include common math library */
#include "cml_adapted.h" /* include customized cml functions for matrix inversion with lower F32_ZERO constant */

/*****************************************************************************
  MACROS
*****************************************************************************/
#ifndef FALSE
#define FALSE (0u)
#endif
#ifndef TRUE
#define TRUE (1u)
#endif

/* order+1 (number of coefficients) of fitted polynomial */
#ifndef POLY_ORDER_3RD
#define POLY_ORDER_3RD (4u)
#endif
#ifndef POLY_ORDER_2ND
#define POLY_ORDER_2ND (3u)
#endif
#ifndef POLY_ORDER_1ST
#define POLY_ORDER_1ST (2u)
#endif
/* number of used data samples for polyfit */
#ifndef SAMPLE_POINTS_ODPR
#define SAMPLE_POINTS_ODPR (32u)
#endif

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static boolean_T calculatePolyfit1st(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff1st, real32_T pWeightLastFit_nu, uint8_T bLastTrajInvalid1st_bool);
static boolean_T calculatePolyfit2nd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff2nd, real32_T pWeightLastFit_nu, uint8_T bLastTrajInvalid2nd_bool);
//static boolean_T calculatePolyfit3rd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff3rd, real32_T pWeightLastFit_nu, uint8_T bLastTrajInvalid3rd_bool);
static void createEquationMatrix1st(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX);
static void createEquationMatrix2nd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu);
//static void createEquationMatrix3rd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu, real32_T pCrvChngDecay_nu);
static void addNewSamplePoint(real32_T fObjXPos_met, real32_T fObjYPos_met, CML_t_Matrix* vecX, CML_t_Matrix* vecY, CML_t_Matrix* Weight, uint8_T *uNumValidEntries, CML_t_Matrix* vecAge);
static void validatePoints(real32_T fMinPosX_met, real32_T fMaxSampleAge_sec, CML_t_Matrix* vecX, CML_t_Matrix* Weight, uint8_T *uNumValidEntries, CML_t_Matrix* vecAge);
static void egoMotionCompensation(real32_T fDeltaX_met, real32_T fDeltaY_met, real32_T fDeltaYawAng_rad, real32_T fCycleTime_sec, CML_t_Matrix* vecX,  CML_t_Matrix* vecY, CML_t_Matrix* vecAge, CML_t_Matrix* Weight);
static void polyfitTransformation1st(real32_T fDeltaY_met, real32_T fDeltaYawAng_rad,  CML_t_Matrix* vecPolyCoeff1st);
static void polyfitTransformation2nd(real32_T fDeltaY_met, real32_T fDeltaYawAng_rad,  CML_t_Matrix* vecPolyCoeff2nd);
//static void polyfitTransformation3rd(real32_T fDeltaY_met, real32_T fDeltaYawAng_rad,  CML_t_Matrix* vecPolyCoeff3rd);
static real32_T getMeanSampleAge(CML_t_Matrix* vecAge, CML_t_Matrix* Weight, uint8_T uNumValidEntries);
static real32_T getMaxSampleAge(CML_t_Matrix* vecAge, CML_t_Matrix* Weight);
static real32_T getMeanDevToTraj(CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff, CML_t_Matrix* Weight, uint8_T uNumValidEntries);
static real32_T getMinSampleDist(CML_t_Matrix* vecX, CML_t_Matrix* Weight);
static real32_T getMaxSampleDist(CML_t_Matrix* vecX, CML_t_Matrix* Weight);
static real32_T getArcTanSmallAng(real32_T x);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************
Functionname:    calculatePolyfit1st

@brief           calculates a polynomial fit 1st order using weighted least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle
                 y = X * a --> a = (X^T * (W*X))^-1 * (X^T * (W*y))

@param[in]       Weight : weighting factor vector (diagonal matrix elements)

@param[in]       mtrxX : model equation matrix X

@param[in]       vecY : y sample points

@return          bMtrxInvFailed : FALSE if matrix inversion was successful

@author          Alexander Fen
**************************************************************************** */
static boolean_T calculatePolyfit1st(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff1st, real32_T pWeightLastFit_nu, uint8_T bLastTrajInvalid1st_bool){
  CML_CreateMatrixLocal(mtrxX_T, POLY_ORDER_1ST, SAMPLE_POINTS_ODPR) /*transposed X^T matrix using local memory allocation*/
  CML_CreateMatrixLocal(mtrxX_I, POLY_ORDER_1ST, POLY_ORDER_1ST) /*inverted X^-1 matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWX, SAMPLE_POINTS_ODPR, POLY_ORDER_1ST) /*temp (W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWX, POLY_ORDER_1ST, POLY_ORDER_1ST) /*temp (X^T)*(W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWy, SAMPLE_POINTS_ODPR, 1) /*temp (W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWy, POLY_ORDER_1ST, 1) /*temp (X^T)*(W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(vecLastPolyCoeff, POLY_ORDER_1ST, 1) /*temp vector used for weighting using local memory allocation*/
  
  uint8_T row, col;
  boolean_T bMtrxInvFailed = FALSE;

  if(bLastTrajInvalid1st_bool == FALSE){
          CML_v_copyMatrix(vecLastPolyCoeff, vecPolyCoeff1st);
  }
      
  CML_v_TransposeMatrix(mtrxX_T, mtrxX);
  
  for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
      for(col = 0; col < POLY_ORDER_1ST; col++){
          CML_GetMatrixElement(tmpMtrxWX,row,col) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(mtrxX,row,col);
      }
  }
  CML_v_MultiplyMatrices(tmpMtrxXTWX, mtrxX_T, tmpMtrxWX);
  LCF_CML_v_InvertMatrix(mtrxX_I, tmpMtrxXTWX); /* from cml_adapted.c --> tmpMtrxXTWX gets overwritten with identity matrix */
  if((mtrxX_I->Desc.row == 0u) || (mtrxX_I->Desc.col == 0u)){
      bMtrxInvFailed = TRUE;
  }else{
      for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
        CML_GetMatrixElement(tmpMtrxWy,row,0) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(vecY,row,0);
      }
      CML_v_MultiplyMatrices(tmpMtrxXTWy, mtrxX_T, tmpMtrxWy);
      
      CML_v_MultiplyMatrices(vecPolyCoeff1st, mtrxX_I, tmpMtrxXTWy);
      
      /* apply weighting between new and old fit */
      if(bLastTrajInvalid1st_bool == FALSE){
          for(row = 0; row < POLY_ORDER_1ST; row++){ /* row treated as col since it is a vec */ 
              CML_GetMatrixElement(vecPolyCoeff1st,row,0) = (pWeightLastFit_nu * CML_GetMatrixElement(vecLastPolyCoeff,row,0)) + ((1.0f - pWeightLastFit_nu) * CML_GetMatrixElement(vecPolyCoeff1st,row,0));
          }
      }
      bMtrxInvFailed = FALSE;
  }
  return bMtrxInvFailed;
}

/* ****************************************************************************
Functionname:    calculatePolyfit2nd

@brief           calculates a polynomial fit 2nd order using weighted least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle
                 y = X * a --> a = (X^T * (W*X))^-1 * (X^T * (W*y))

@param[in]       Weight : weighting factor vector (diagonal matrix elements)

@param[in]       mtrxX : model equation matrix X

@param[in]       vecY : y sample points

@return          bMtrxInvFailed : FALSE if matrix inversion was successful

@author          Alexander Fen
**************************************************************************** */
static boolean_T calculatePolyfit2nd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff2nd, real32_T pWeightLastFit_nu, uint8_T bLastTrajInvalid2nd_bool){
  CML_CreateMatrixLocal(mtrxX_T, POLY_ORDER_2ND, SAMPLE_POINTS_ODPR) /*transposed X^T matrix using local memory allocation*/
  CML_CreateMatrixLocal(mtrxX_I, POLY_ORDER_2ND, POLY_ORDER_2ND) /*inverted X^-1 matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWX, SAMPLE_POINTS_ODPR, POLY_ORDER_2ND) /*temp (W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWX, POLY_ORDER_2ND, POLY_ORDER_2ND) /*temp (X^T)*(W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWy, SAMPLE_POINTS_ODPR, 1) /*temp (W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWy, POLY_ORDER_2ND, 1) /*temp (X^T)*(W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(vecLastPolyCoeff, POLY_ORDER_2ND, 1) /*temp vector used for weighting using local memory allocation*/
  
  uint8_T row, col;
  boolean_T bMtrxInvFailed = FALSE;

  if(bLastTrajInvalid2nd_bool == FALSE){
      CML_v_copyMatrix(vecLastPolyCoeff, vecPolyCoeff2nd);
  }
  
  CML_v_TransposeMatrix(mtrxX_T, mtrxX);
  
  for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
      for(col = 0; col < POLY_ORDER_2ND; col++){
          CML_GetMatrixElement(tmpMtrxWX,row,col) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(mtrxX,row,col);
      }
  }
  CML_v_MultiplyMatrices(tmpMtrxXTWX, mtrxX_T, tmpMtrxWX);
  LCF_CML_v_InvertMatrix(mtrxX_I, tmpMtrxXTWX); /* from cml_adapted.c --> tmpMtrxXTWX gets overwritten with identity matrix */
  if((mtrxX_I->Desc.row == 0u) || (mtrxX_I->Desc.col == 0u)){
      bMtrxInvFailed = TRUE;
  }else{
      for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
        CML_GetMatrixElement(tmpMtrxWy,row,0) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(vecY,row,0);
      }
      CML_v_MultiplyMatrices(tmpMtrxXTWy, mtrxX_T, tmpMtrxWy);
      
      CML_v_MultiplyMatrices(vecPolyCoeff2nd, mtrxX_I, tmpMtrxXTWy);
      
      /* apply weighting between new and old fit */
      if(bLastTrajInvalid2nd_bool == FALSE){
          for(row = 0; row < POLY_ORDER_2ND; row++){ /* row treated as col since it is a vec */ 
              CML_GetMatrixElement(vecPolyCoeff2nd,row,0) = (pWeightLastFit_nu * CML_GetMatrixElement(vecLastPolyCoeff,row,0)) + ((1.0f - pWeightLastFit_nu) * CML_GetMatrixElement(vecPolyCoeff2nd,row,0));
          }
      }
      bMtrxInvFailed = FALSE;
  }
  return bMtrxInvFailed;
}

/* ****************************************************************************
Functionname:    calculatePolyfit3rd

@brief           calculates a polynomial fit 3rd order using weighted least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle
                 y = X * a --> a = (X^T * (W*X))^-1 * (X^T * (W*y))

@param[in]       Weight : weighting factor vector (diagonal matrix elements)

@param[in]       mtrxX : model equation matrix X

@param[in]       vecY : y sample points

@return          bMtrxInvFailed : FALSE if matrix inversion was successful

@author          Alexander Fen
**************************************************************************** */
// static boolean_T calculatePolyfit3rd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff3rd, real32_T pWeightLastFit_nu, uint8_T bLastTrajInvalid3rd_bool){
  // CML_CreateMatrixLocal(mtrxX_T, POLY_ORDER_3RD, SAMPLE_POINTS_ODPR) /*transposed X^T matrix using local memory allocation*/
  // CML_CreateMatrixLocal(mtrxX_I, POLY_ORDER_3RD, POLY_ORDER_3RD) /*inverted X^-1 matrix using local memory allocation*/
  // CML_CreateMatrixLocal(tmpMtrxWX, SAMPLE_POINTS_ODPR, POLY_ORDER_3RD) /*temp (W*X) matrix using local memory allocation*/
  // CML_CreateMatrixLocal(tmpMtrxXTWX, POLY_ORDER_3RD, POLY_ORDER_3RD) /*temp (X^T)*(W*X) matrix using local memory allocation*/
  // CML_CreateMatrixLocal(tmpMtrxWy, SAMPLE_POINTS_ODPR, 1) /*temp (W*y) vector using local memory allocation*/
  // CML_CreateMatrixLocal(tmpMtrxXTWy, POLY_ORDER_3RD, 1) /*temp (X^T)*(W*y) vector using local memory allocation*/
  // CML_CreateMatrixLocal(vecLastPolyCoeff, POLY_ORDER_3RD, 1) /*temp vector used for weighting using local memory allocation*/
  
  // uint8_T row, col;
  // boolean_T bMtrxInvFailed = FALSE;

  // if(bLastTrajInvalid3rd_bool == FALSE){
      // CML_v_copyMatrix(vecLastPolyCoeff, vecPolyCoeff3rd);
  // }
  
  // CML_v_TransposeMatrix(mtrxX_T, mtrxX);
  
  // for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
      // for(col = 0; col < POLY_ORDER_3RD; col++){
          // CML_GetMatrixElement(tmpMtrxWX,row,col) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(mtrxX,row,col);
      // }
  // }
  // CML_v_MultiplyMatrices(tmpMtrxXTWX, mtrxX_T, tmpMtrxWX);
  // LCF_CML_v_InvertMatrix(mtrxX_I, tmpMtrxXTWX); /* from cml_adapted.c --> tmpMtrxXTWX gets overwritten with identity matrix */
  // if((mtrxX_I->Desc.row == 0u) || (mtrxX_I->Desc.col == 0u)){
      // bMtrxInvFailed = TRUE;
  // }else{
      // for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
        // CML_GetMatrixElement(tmpMtrxWy,row,0) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(vecY,row,0);
      // }
      // CML_v_MultiplyMatrices(tmpMtrxXTWy, mtrxX_T, tmpMtrxWy);
      
      // CML_v_MultiplyMatrices(vecPolyCoeff3rd, mtrxX_I, tmpMtrxXTWy);
      
      // /* apply weighting between new and old fit */
      // if(bLastTrajInvalid3rd_bool == FALSE){
          // for(row = 0; row < POLY_ORDER_3RD; row++){ /* row treated as col since it is a vec */ 
              // CML_GetMatrixElement(vecPolyCoeff3rd,row,0) = (pWeightLastFit_nu * CML_GetMatrixElement(vecLastPolyCoeff,row,0)) + ((1.0f - pWeightLastFit_nu) * CML_GetMatrixElement(vecPolyCoeff3rd,row,0));
          // }
      // }
      // bMtrxInvFailed = FALSE;
  // }
  // return bMtrxInvFailed;
// }


/* ****************************************************************************
Functionname:    createEquationMatrix1st

@brief           create equation matrix X with model equations

@description     create equation matrix X with model equations for 3rd order

@param[in/out]   mtrxX : model equation matrix X (out --> updated)

@param[in]       vecX : x sample points

@author          Alexander Fen
**************************************************************************** */
static void createEquationMatrix1st(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX){
  //uint8_T row, col;
  uint8_T row;
  /*fill equation matrix X */
  for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
      /*for(col = 0; col < POLY_ORDER; col++){
      }*/
      /* alternatively without second for-loop for columns to avoid CML
      dependency (CML_f_expPower and factorial) */
      CML_GetMatrixElement(mtrxX,row,0) = 1.0f;
      CML_GetMatrixElement(mtrxX,row,1) = CML_GetMatrixElement(vecX,row,0);
  }
}

/* ****************************************************************************
Functionname:    createEquationMatrix2nd

@brief           create equation matrix X with model equations 

@description     create equation matrix X with model equations for 2nd order

@param[in/out]   mtrxX : model equation matrix X (out --> updated)

@param[in]       vecX : x sample points

@author          Alexander Fen
**************************************************************************** */
static void createEquationMatrix2nd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu){
  //uint8_T row, col;
  uint8_T row;
  /*fill equation matrix X */
  for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
      /*for(col = 0; col < POLY_ORDER; col++){
      }*/
      /* alternatively without second for-loop for columns to avoid CML
      dependency (CML_f_expPower and factorial) */
      CML_GetMatrixElement(mtrxX,row,0) = 1.0f;
      CML_GetMatrixElement(mtrxX,row,1) = CML_GetMatrixElement(vecX,row,0);
      /* use pCrvDecay_nu for damping of curvature */
      if(pCrvDecay_nu > 0.0001f){
          CML_GetMatrixElement(mtrxX,row,2) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * 0.5f / pCrvDecay_nu;
      }else{
          CML_GetMatrixElement(mtrxX,row,2) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * 0.5f;
      }
  }
}

/* ****************************************************************************
Functionname:    createEquationMatrix3rd

@brief           create equation matrix X with model equations for 3rd order

@description     create equation matrix X with model equations for 3rd order

@param[in/out]   mtrxX : model equation matrix X (out --> updated)

@param[in]       vecX : x sample points

@author          Alexander Fen
**************************************************************************** */
// static void createEquationMatrix3rd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu, real32_T pCrvChngDecay_nu){
  // //uint8_T row, col;
  // uint8_T row;
  // /*fill equation matrix X */
  // for(row = 0; row < SAMPLE_POINTS_ODPR; row++){
      // /*for(col = 0; col < POLY_ORDER; col++){
      // }*/
      // /* alternatively without second for-loop for columns to avoid CML
      // dependency (CML_f_expPower and factorial) */
      // CML_GetMatrixElement(mtrxX,row,0) = 1.0f;
      // CML_GetMatrixElement(mtrxX,row,1) = CML_GetMatrixElement(vecX,row,0);
      // /* use pCrvDecay_nu for damping of curvature */
      // if(pCrvDecay_nu > 0.0001f){
          // CML_GetMatrixElement(mtrxX,row,2) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * 0.5f / pCrvDecay_nu;
      // }else{
          // CML_GetMatrixElement(mtrxX,row,2) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * 0.5f;
      // }
      // /* use pCrvChngDecay_nu for damping of curvature change */
      // if(pCrvChngDecay_nu > 0.0001f){
          // CML_GetMatrixElement(mtrxX,row,3) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * 0.1667f / pCrvChngDecay_nu;
      // }else{
          // CML_GetMatrixElement(mtrxX,row,3) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * 0.1667f;
      // }
  // }
// }

/* ****************************************************************************
Functionname:    addNewSamplePoint

@brief           new sample points are added

@description     new sample points are added to the global ringbuffers[0],
                 previous values are shifted by 1 index

@param[in]       fObjXPos_met : ego yaw rate

@param[in]       fObjYPos_met : ego velocity

@param[in/out]   vecX : x sample points (out --> updated)

@param[in/out]   vecY : y sample points (out --> updated)

@param[in/out]   Weight : weighting factor vector (diagonal matrix elements) (out --> updated)

@param[in/out]   vecAge : vector for stored sample point age (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static void addNewSamplePoint(real32_T fObjXPos_met, real32_T fObjYPos_met, CML_t_Matrix* vecX, CML_t_Matrix* vecY, CML_t_Matrix* Weight, uint8_T *uNumValidEntries, CML_t_Matrix* vecAge){
  real32_T fDeltaYawAng_rad = 0.0;
  real32_T fDeltaX_met = 0.0;
  real32_T fDeltaY_met = 0.0;
  uint8_T i;
  
  /* ringbuffer: shift all values forwards by 1 index, start from behind */
  for(i = SAMPLE_POINTS_ODPR-1; i > 0; i--){
      CML_GetMatrixElement(vecX, i, 0) = CML_GetMatrixElement(vecX, i-1, 0);
      CML_GetMatrixElement(vecY, i, 0) = CML_GetMatrixElement(vecY, i-1, 0);
      CML_GetMatrixElement(Weight, i, 0) = CML_GetMatrixElement(Weight, i-1, 0);
      CML_GetMatrixElement(vecAge, i, 0) = CML_GetMatrixElement(vecAge, i-1, 0);
  }
  
  /* fill in new sample point at empty index 0 */
  CML_GetMatrixElement(vecX, 0, 0) = fObjXPos_met;
  CML_GetMatrixElement(vecY, 0, 0) = fObjYPos_met;
  CML_GetMatrixElement(Weight, 0, 0) = 1.0f;
  CML_GetMatrixElement(vecAge, 0, 0) = 0.0f;
  
  if(*uNumValidEntries < SAMPLE_POINTS_ODPR){
      *uNumValidEntries += 1;
  }
}

/* ****************************************************************************
Functionname:    validatePoints

@brief           new sample points are added

@description     new sample points are added to the global ringbuffers[0],
                 previous values are shifted by 1 index

@param[in]       fMinPosX_met : min object x-position

@param[in]       vecAge : vector for stored sample point age (out --> updated)

@param[in/out]   vecX : x sample points (out --> updated)

@param[in/out]   Weight : weighting factor vector (diagonal matrix elements) (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static void validatePoints(real32_T fMinHistStartPosX_met, real32_T fMaxSampleAge_sec, CML_t_Matrix* vecX, CML_t_Matrix* Weight, uint8_T *uNumValidEntries, CML_t_Matrix* vecAge){
  uint8_T i;
  
  /* check if stored points moved outside of valid area and set them to invalid */
  for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
      if((CML_GetMatrixElement(Weight, i, 0) > 0.0001f) &&
      ((CML_GetMatrixElement(vecX, i, 0) < fMinHistStartPosX_met) ||
      (CML_GetMatrixElement(vecAge, i, 0) > fMaxSampleAge_sec))){
          CML_GetMatrixElement(Weight, i, 0) = 0.0f;
          if(*uNumValidEntries > 0u){
            *uNumValidEntries -= 1;
          }
      }
  }
}

/* ****************************************************************************
Functionname:    egoMotionCompensation

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fEgoYawRate_rps : ego yaw rate

@param[in]       fEgoVelX_mps : ego velocity

@param[in]       fCycleTime_sec : cycle time

@param[in/out]   vecX : global x sample points (out --> updated)

@param[in/out]   vecY : global y sample points (out --> updated)

@param[in/out]   vecAge : vector for stored sample point age (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static void egoMotionCompensation(real32_T fDeltaX_met, real32_T fDeltaY_met, real32_T fDeltaYawAng_rad, real32_T fCycleTime_sec, CML_t_Matrix* vecX,  CML_t_Matrix* vecY, CML_t_Matrix* vecAge, CML_t_Matrix* Weight){
  //CML_CreateMatrixLocal(mRot, 2, 2) /*inverted X^-1 matrix using local memory allocation*/
  //CML_CreateMatrixLocal(mtrxXY, SAMPLE_POINTS_ODPR, 2) /*create X matrix with sample point equations using static memory allocation*/
  uint8_T i;
  /* compute the inverse 2D rotation followed by translation */
  for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
      if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
          CML_GetMatrixElement(vecX, i, 0) = ((CML_GetMatrixElement(vecX, i, 0) * CML_f_cos52(fDeltaYawAng_rad)) + (CML_GetMatrixElement(vecY, i, 0) * CML_f_sin52(fDeltaYawAng_rad))) - fDeltaX_met;
          CML_GetMatrixElement(vecY, i, 0) = ((CML_GetMatrixElement(vecY, i, 0) * CML_f_cos52(fDeltaYawAng_rad)) - (CML_GetMatrixElement(vecX, i, 0) * CML_f_sin52(fDeltaYawAng_rad))) - fDeltaY_met;
          CML_GetMatrixElement(vecAge, i, 0) += fCycleTime_sec;
      }
  }
  
  // alternatively to for-loop matrix multiplication could be used but therefore additional XY matrix needed
  /*CML_GetMatrixElement(mRot,0,0) = CML_f_cos52(fDeltaYawAng_rad);
  CML_GetMatrixElement(mRot,0,1) = CML_f_sin52(fDeltaYawAng_rad) * -1.0;
  CML_GetMatrixElement(mRot,1,0) = CML_f_sin52(fDeltaYawAng_rad);
  CML_GetMatrixElement(mRot,1,1) = CML_f_cos52(fDeltaYawAng_rad);*/
  
}

/* ****************************************************************************
Functionname:    polyfitTransformation1st

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fDeltaY_met : y-portion of ego motion

@param[in]       fDeltaYawAng_rad : yaw portion of ego motion

@param[in/out]   vecPolyCoeff1st : polyFit coefficients (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static void polyfitTransformation1st(real32_T fDeltaY_met, real32_T fDeltaYawAng_rad,  CML_t_Matrix* vecPolyCoeff1st){
    /* y' = y(t-1) - deltaY
       yaw' = yaw(t-1) - deltaYaw */
    CML_GetMatrixElement(vecPolyCoeff1st, 0, 0) -= fDeltaY_met;
    CML_GetMatrixElement(vecPolyCoeff1st, 1, 0) -= fDeltaYawAng_rad;
  
}

/* ****************************************************************************
Functionname:    polyfitTransformation2nd

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fDeltaY_met : y-portion of ego motion

@param[in]       fDeltaYawAng_rad : yaw portion of ego motion

@param[in/out]   vecPolyCoeff1st : polyFit coefficients (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static void polyfitTransformation2nd(real32_T fDeltaY_met, real32_T fDeltaYawAng_rad,  CML_t_Matrix* vecPolyCoeff2nd){
    /* y' = y(t-1) - deltaY
       yaw' = yaw(t-1) - deltaYaw
       c0' = c0 (assumption due to robustness)
       c1' = c1 (assumption due to robustness) */
    CML_GetMatrixElement(vecPolyCoeff2nd, 0, 0) -= fDeltaY_met;
    CML_GetMatrixElement(vecPolyCoeff2nd, 1, 0) -= fDeltaYawAng_rad;
  
}

/* ****************************************************************************
Functionname:    polyfitTransformation3rd

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fDeltaY_met : y-portion of ego motion

@param[in]       fDeltaYawAng_rad : yaw portion of ego motion

@param[in/out]   vecPolyCoeff1st : polyFit coefficients (out --> updated)

@author          Alexander Fen
**************************************************************************** */
// static void polyfitTransformation3rd(real32_T fDeltaY_met, real32_T fDeltaYawAng_rad,  CML_t_Matrix* vecPolyCoeff3rd){
    // /* y' = y(t-1) - deltaY
       // yaw' = yaw(t-1) - deltaYaw
       // c0' = c0 (assumption due to robustness)
       // c1' = c1 (assumption due to robustness) */
    // CML_GetMatrixElement(vecPolyCoeff3rd, 0, 0) -= fDeltaY_met;
    // CML_GetMatrixElement(vecPolyCoeff3rd, 1, 0) -= fDeltaYawAng_rad;
  
// }

/* ****************************************************************************
Functionname:    getMeanSampleAge

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fEgoYawRate_rps : ego yaw rate

@param[in]       fEgoVelX_mps : ego velocity

@param[in]       fCycleTime_sec : cycle time

@param[in/out]   vecX : global x sample points (out --> updated)

@param[in/out]   vecY : global y sample points (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static real32_T getMeanSampleAge(CML_t_Matrix* vecAge, CML_t_Matrix* Weight, uint8_T uNumValidEntries){
  real32_T fMeanSampleAge = 0.0;
  uint8_T i;
  
  if(uNumValidEntries > 0u){
      for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
          if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
              fMeanSampleAge += CML_GetMatrixElement(vecAge, i, 0);
          }
      }
          fMeanSampleAge /= uNumValidEntries;
  }
  return fMeanSampleAge;
}

/* ****************************************************************************
Functionname:    getMaxSampleAge

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fEgoYawRate_rps : ego yaw rate

@param[in]       fEgoVelX_mps : ego velocity

@param[in]       fCycleTime_sec : cycle time

@param[in/out]   vecX : global x sample points (out --> updated)

@param[in/out]   vecY : global y sample points (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static real32_T getMaxSampleAge(CML_t_Matrix* vecAge, CML_t_Matrix* Weight){
  real32_T fFirstSampleAge = 0.0f;
  uint8_T i;
  
  for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
      if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
          if(CML_GetMatrixElement(vecAge, i, 0) > fFirstSampleAge){
              fFirstSampleAge = CML_GetMatrixElement(vecAge, i, 0);
          }
      }
  }
  return fFirstSampleAge;
}

/* ****************************************************************************
Functionname:    getMeanDevToTraj

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fEgoYawRate_rps : ego yaw rate

@param[in]       fEgoVelX_mps : ego velocity

@param[in]       fCycleTime_sec : cycle time

@param[in/out]   vecX : global x sample points (out --> updated)

@param[in/out]   vecY : global y sample points (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static real32_T getMeanDevToTraj(CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff, CML_t_Matrix* Weight, uint8_T uNumValidEntries){
  CML_CreateMatrixLocal(tmpVecXa, SAMPLE_POINTS_ODPR, 1) /*temp (X*a) Vec using local memory allocation*/
  real32_T fMeanDevTraj_met = 0.0;
  uint8_T i;
  
  if(uNumValidEntries > 0u){
      CML_v_MultiplyMatrices(tmpVecXa, mtrxX, vecPolyCoeff);
      
      for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
          if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
              fMeanDevTraj_met += CML_f_Abs(CML_GetMatrixElement(tmpVecXa, i, 0) - CML_GetMatrixElement(vecY, i, 0));
          }
      }
          fMeanDevTraj_met /= uNumValidEntries;
  }
  return fMeanDevTraj_met;
}

/* ****************************************************************************
Functionname:    getMinSampleDist

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fEgoYawRate_rps : ego yaw rate

@param[in]       fEgoVelX_mps : ego velocity

@param[in]       fCycleTime_sec : cycle time

@param[in/out]   vecX : global x sample points (out --> updated)

@param[in/out]   vecY : global y sample points (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static real32_T getMinSampleDist(CML_t_Matrix* vecX, CML_t_Matrix* Weight){
  real32_T fMinSampleX = 150.0f;
  uint8_T i;
  
  for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
      if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
          if(CML_GetMatrixElement(vecX, i, 0) < fMinSampleX){
              fMinSampleX = CML_GetMatrixElement(vecX, i, 0);
          }
      }
  }
  return fMinSampleX;
}

/* ****************************************************************************
Functionname:    getMaxSampleDist

@brief           compensate ego motion between 2 cycles

@description     first fDeltaX_met and fDeltaY_met are subtracted,
                 then both points are rotated with fDeltaYawAng_rad

@param[in]       fEgoYawRate_rps : ego yaw rate

@param[in]       fEgoVelX_mps : ego velocity

@param[in]       fCycleTime_sec : cycle time

@param[in/out]   vecX : global x sample points (out --> updated)

@param[in/out]   vecY : global y sample points (out --> updated)

@author          Alexander Fen
**************************************************************************** */
static real32_T getMaxSampleDist(CML_t_Matrix* vecX, CML_t_Matrix* Weight){
  real32_T fMaxSampleX = 0.0f;
  uint8_T i;
  
  for(i = 0; i < SAMPLE_POINTS_ODPR; i++){
      if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
          if(CML_GetMatrixElement(vecX, i, 0) > fMaxSampleX){
              fMaxSampleX = CML_GetMatrixElement(vecX, i, 0);
          }
      }
  }
  return fMaxSampleX;
}

/* ****************************************************************************
Functionname:    getArcTanSmallAng
                 arctan approximation using equation 10 of
                 "Efficient Approximations for the Arctangent Function" with
                 smaller errors around 0 degree
                
@author          Alexander Fen
**************************************************************************** */
static real32_T getArcTanSmallAng(real32_T x){
  real32_T fArcTan = 0.0f;
  /* − 1 ≤ x ≤ 1 */
  if(x > 1.0f){
      x = 1.0f;
  }else if(x < -1.0f){
      x = -1.0f;
  }
  fArcTan = x / (1.0 + (0.28086 * x * x));
  return fArcTan;
}

/* ****************************************************************************
Functionname:    polyfitTgtObjectClothoid

@brief           calculates a polynomial fit using least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle.
                 The equation matrix X is filled with the x/y sample points and
                 the polynomial coefficient vector is calculated

@param[in]       fObjXPos_met : target object x position

@param[in]       fObjYPos_met : target object y position

@param[out]      vecPolyCoeff : calculated polynomial coefficients

@author          Alexander Fen
**************************************************************************** */
void polyfitTgtObjectClothoid(const TgtObjectPF_Input* input, TgtObjectPF_Output* output){
  CML_CreateMatrixLocal(mtrxX1st, SAMPLE_POINTS_ODPR, POLY_ORDER_1ST) /*create X matrix with sample point equations using static memory allocation*/
  CML_CreateMatrixLocal(mtrxX2nd, SAMPLE_POINTS_ODPR, POLY_ORDER_2ND) /*create X matrix with sample point equations using static memory allocation*/
  //CML_CreateMatrixLocal(mtrxX3rd, SAMPLE_POINTS_ODPR, POLY_ORDER_3RD) /*create X matrix with sample point equations using static memory allocation*/
  CML_CreateMatrix(vecY, SAMPLE_POINTS_ODPR, 1) /* vector for object y-position storage which gets filled from input struct and transformed each cycle */
  CML_CreateMatrix(vecX, SAMPLE_POINTS_ODPR, 1) /* vector for object x-position storage which gets filled from input struct and transformed each cycle */
  CML_CreateMatrix(vecPolyCoeff1st, POLY_ORDER_1ST, 1) /* calculated polynomial coefficients which are written to the output struct */
  CML_CreateMatrix(vecPolyCoeff2nd, POLY_ORDER_2ND, 1) /* calculated polynomial coefficients which are written to the output struct */
  //CML_CreateMatrix(vecPolyCoeff3rd, POLY_ORDER_3RD, 1) /* calculated polynomial coefficients which are written to the output struct */
  CML_CreateMatrix(Weight, SAMPLE_POINTS_ODPR, 1) /* weighting factors --> diagonal elements of matrix stored as vector for element-wise calculations */
  CML_CreateMatrix(vecAge, SAMPLE_POINTS_ODPR, 1) /* vector for stored sample point age which gets accumulated each cycle */
  
  static uint8_T uNumValidEntries = 0u;
  static uint8_T bLastTrajInvalid1st_bool = TRUE;
  static uint8_T bLastTrajInvalid2nd_bool = TRUE;
  //static uint8_T bLastTrajInvalid3rd_bool = TRUE;
  
  real32_T fDeltaYawAng_rad = 0.0;
  real32_T fDeltaX_met = 0.0;
  real32_T fDeltaY_met = 0.0;
  
  /* small angle approximations: sin(ang) = ang | tan(ang) = ang | cos(ang) = 1-(ang^2 / 2) */
  fDeltaYawAng_rad = input->fEgoYawRate_rps * input->fTimeSinceLastCall_sec;
  fDeltaX_met = input->fEgoVelX_mps * input->fTimeSinceLastCall_sec;
  fDeltaY_met = fDeltaX_met * fDeltaYawAng_rad;
  
  if(input->bReset_bool){ /* reset the global and output data */
    CML_v_InitMatrix(mtrxX1st, SAMPLE_POINTS_ODPR, POLY_ORDER_1ST, 0.0f);
    CML_v_InitMatrix(mtrxX2nd, SAMPLE_POINTS_ODPR, POLY_ORDER_2ND, 0.0f);
    //CML_v_InitMatrix(mtrxX3rd, SAMPLE_POINTS_ODPR, POLY_ORDER_3RD, 0.0f);
    CML_v_InitMatrix(vecY, SAMPLE_POINTS_ODPR, 1, 0.0f);
    CML_v_InitMatrix(vecX, SAMPLE_POINTS_ODPR, 1, 0.0f);
    CML_v_InitMatrix(vecPolyCoeff1st, POLY_ORDER_1ST, 1, 0.0f);
    CML_v_InitMatrix(vecPolyCoeff2nd, POLY_ORDER_2ND, 1, 0.0f);
    //CML_v_InitMatrix(vecPolyCoeff3rd, POLY_ORDER_3RD, 1, 0.0f);
    CML_v_InitMatrix(Weight, SAMPLE_POINTS_ODPR, 1, 0.0f);
    CML_v_InitMatrix(vecAge, SAMPLE_POINTS_ODPR, 1, 0.0f);
    uNumValidEntries = 0u;
    bLastTrajInvalid1st_bool = TRUE;
    bLastTrajInvalid2nd_bool = TRUE;
    //bLastTrajInvalid3rd_bool = TRUE;
    output->uNumValidSamples_nu = 0u;
    output->fPosX0_met = 0.0f;
    output->fPosY0_1st_met = 0.0f;
    output->fPosY0_3rd_met = 0.0f;
    output->fHeading_1st_rad = 0.0f;
    output->fHeading_3rd_rad = 0.0f;
    output->fCrv_1pm = 0.0f;
    output->fChngOfCrv_1pm2 = 0.0f;
    output->fTrajLength_met = 0.0f;
    output->bTrajUpdate_bool = FALSE;
    output->bTrajInvalid1st_bool = TRUE;
    output->bTrajInvalid3rd_bool = TRUE;
    output->fMeanSampleAge_sec = 0.0f;
    output->fFirstStoredAge_sec = 0.0f;
    output->fMeanDevToTraj_1st_met = 0.0f;
    output->fMeanDevToTraj_3rd_met = 0.0f;
    output->fLastStoredPntX_met = 0.0f;
    output->fLastStoredPntY_met = 0.0f;
    output->fLastStoredAge_sec = 0.0f;
    }else{
        if(uNumValidEntries > 0u){
            egoMotionCompensation(fDeltaX_met, fDeltaY_met, fDeltaYawAng_rad, input->fTimeSinceLastCall_sec, vecX, vecY, vecAge, Weight);
            validatePoints(input->fMinHistStartPosX_met, input->fMaxSampleAge_sec, vecX, Weight, &uNumValidEntries, vecAge);
        }
        if(input->bAddNewSample_bool){
            addNewSamplePoint(input->fObjXPos_met, input->fObjYPos_met, vecX, vecY, Weight, &uNumValidEntries, vecAge);
        }
        if(bLastTrajInvalid1st_bool == FALSE){
            polyfitTransformation1st(fDeltaY_met, fDeltaYawAng_rad, vecPolyCoeff1st);
        }
        if(bLastTrajInvalid2nd_bool == FALSE){
            polyfitTransformation2nd(fDeltaY_met, fDeltaYawAng_rad, vecPolyCoeff2nd);
        }
        // if(bLastTrajInvalid3rd_bool == FALSE){
            // polyfitTransformation3rd(fDeltaY_met, fDeltaYawAng_rad, vecPolyCoeff3rd);
        // }
        if(uNumValidEntries > 0u){
            output->fTrajLength_met = getMaxSampleDist(vecX, Weight);
            output->fPosX0_met = getMinSampleDist(vecX, Weight);
        }else{
            output->fTrajLength_met = 0.0f;
            output->fPosX0_met = 0.0f;
        }
        
        output->uNumValidSamples_nu = uNumValidEntries;
        output->fLastStoredPntX_met = CML_GetMatrixElement(vecX,0,0);
        output->fLastStoredPntY_met = CML_GetMatrixElement(vecY,0,0);
        output->fLastStoredAge_sec = CML_GetMatrixElement(vecAge,0,0);
        output->fMeanSampleAge_sec = getMeanSampleAge(vecAge, Weight, uNumValidEntries);
        output->fFirstStoredAge_sec = getMaxSampleAge(vecAge, Weight);
        
        if((uNumValidEntries >= input->uMinNumValidSamples_nu) &&
          ((output->fTrajLength_met - output->fPosX0_met) > input->fMinHistLength_met) &&
          (output->fPosX0_met < input->fMaxGapEgoToHist_met) &&
          (input->bEnable_bool)){
            
            output->bTrajUpdate_bool = TRUE;
            
            /* calculate 1st order fit first */
            createEquationMatrix1st(mtrxX1st, vecX);
            bLastTrajInvalid1st_bool = calculatePolyfit1st(Weight, mtrxX1st, vecY, vecPolyCoeff1st, input->pWeightLastFit_nu, bLastTrajInvalid1st_bool);
            output->bTrajInvalid1st_bool = bLastTrajInvalid1st_bool;
            if(bLastTrajInvalid1st_bool){
                output->fPosY0_1st_met = 0.0f;
                output->fHeading_1st_rad = 0.0f;
                output->fMeanDevToTraj_1st_met = 0.0f;
            }else{
                output->fPosY0_1st_met = CML_GetMatrixElement(vecPolyCoeff1st,0,0);
                output->fHeading_1st_rad = getArcTanSmallAng(CML_GetMatrixElement(vecPolyCoeff1st,1,0));
                output->fMeanDevToTraj_1st_met = getMeanDevToTraj(mtrxX1st, vecY, vecPolyCoeff1st, Weight, uNumValidEntries);
            }
            
            /* now calculate 2nd order fit*/
            createEquationMatrix2nd(mtrxX2nd, vecX, input->pCrvDecay_nu);
            bLastTrajInvalid2nd_bool = calculatePolyfit2nd(Weight, mtrxX2nd, vecY, vecPolyCoeff2nd, input->pWeightLastFit_nu, bLastTrajInvalid2nd_bool);
            output->bTrajInvalid3rd_bool = bLastTrajInvalid2nd_bool;
            if(bLastTrajInvalid2nd_bool){
                output->fPosY0_3rd_met = 0.0f;
                output->fHeading_3rd_rad = 0.0f;
                output->fCrv_1pm = 0.0f;
                output->fChngOfCrv_1pm2 = 0.0f;
                output->fMeanDevToTraj_3rd_met = 0.0f;
            }else{
                output->fPosY0_3rd_met = CML_GetMatrixElement(vecPolyCoeff2nd,0,0);
                output->fHeading_3rd_rad = getArcTanSmallAng(CML_GetMatrixElement(vecPolyCoeff2nd,1,0));
                output->fCrv_1pm = CML_GetMatrixElement(vecPolyCoeff2nd,2,0);
                output->fChngOfCrv_1pm2 = 0.0f;
                output->fMeanDevToTraj_3rd_met = getMeanDevToTraj(mtrxX2nd, vecY, vecPolyCoeff2nd, Weight, uNumValidEntries);
            }
            /* now calculate 3rd order fit*/
            // createEquationMatrix3rd(mtrxX3rd, vecX, input->pCrvDecay_nu, input->pCrvChngDecay_nu);
            // bLastTrajInvalid3rd_bool = calculatePolyfit3rd(Weight, mtrxX3rd, vecY, vecPolyCoeff3rd, input->pWeightLastFit_nu, bLastTrajInvalid3rd_bool);
            // output->bTrajInvalid3rd_bool = bLastTrajInvalid3rd_bool;
            // if(bLastTrajInvalid3rd_bool){
                // output->fPosY0_3rd_met = 0.0f;
                // output->fHeading_3rd_rad = 0.0f;
                // output->fCrv_1pm = 0.0f;
                // output->fChngOfCrv_1pm2 = 0.0f;
                // output->fMeanDevToTraj_3rd_met = 0.0f;
            // }else{
                // output->fPosY0_3rd_met = CML_GetMatrixElement(vecPolyCoeff3rd,0,0);
                // output->fHeading_3rd_rad = getArcTanSmallAng(CML_GetMatrixElement(vecPolyCoeff3rd,1,0));
                // output->fCrv_1pm = CML_GetMatrixElement(vecPolyCoeff3rd,2,0);
                // output->fChngOfCrv_1pm2 = CML_GetMatrixElement(vecPolyCoeff3rd,3,0);
                // output->fMeanDevToTraj_3rd_met = getMeanDevToTraj(mtrxX3rd, vecY, vecPolyCoeff3rd, Weight, uNumValidEntries);
            // }
        }else{
            output->fPosY0_1st_met = 0.0f;
            output->fPosY0_3rd_met = 0.0f;
            output->fHeading_1st_rad = 0.0f;
            output->fHeading_3rd_rad = 0.0f;
            output->fCrv_1pm = 0.0f;
            output->fChngOfCrv_1pm2 = 0.0f;
            output->bTrajUpdate_bool = FALSE;
            output->bTrajInvalid1st_bool = TRUE;
            output->bTrajInvalid3rd_bool = TRUE;
            output->fMeanDevToTraj_1st_met = 0.0f;
            output->fMeanDevToTraj_3rd_met = 0.0f;
        }
    }
}