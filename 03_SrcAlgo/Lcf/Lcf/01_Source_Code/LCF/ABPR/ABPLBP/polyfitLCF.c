/*! \file **********************************************************************

  COMPANY:                   Continental Teves AG & Co. oHG

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Functions)

  MODULNAME:                 polyfitLCF.c

  DESCRIPTION:               implements polyfit of 1st, 2nd and 3rd order

  AUTHOR:                    $Author: Handtke, David (uidq4009) $

  CREATION DATE:             $Date: 2019/11/01 18:02:10CET $

  VERSION:                   $Revision: 1.0 $

  CHANGES:                
  ---*/ /*---


**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "polyfitLCF.h"
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
#define POLY_ORDER_3RD_POLYLCF (4u)
#define POLY_ORDER_2ND_POLYLCF (3u)
#define POLY_ORDER_1ST_POLYLCF (2u)
/* number of used data samples for polyfit */
#define SAMPLE_POINTS_POLYLCF (20u)


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static boolean_T calculatePolyfit1st(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff1st);
static boolean_T calculatePolyfit2nd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff2nd);
static boolean_T calculatePolyfit3rd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff3rd);
static void createEquationMatrix1st(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX);
static void createEquationMatrix2nd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu);
static void createEquationMatrix3rd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu, real32_T pCrvChngDecay_nu);
static real32_T getDevToTraj(CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff, CML_t_Matrix* Weight);
static real32_T getArcTanSmallAng(real32_T x);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************
Functionname:    calculatePolyfit1st

@brief           calculates a polynomial fit 1st order using least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle
                 y = X * a --> a = (X^T * (W*X))^-1 * (X^T * (W*y))

@param[in]       Weight : weighting factor vector (diagonal matrix elements)

@param[in]       mtrxX : model equation matrix X

@param[in]       vecY : y sample points

@return          bMtrxInvFailed : FALSE if matrix inversion was successful

@author          Alexander Fen
**************************************************************************** */
static boolean_T calculatePolyfit1st(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff1st){
  CML_CreateMatrixLocal(mtrxX_T, POLY_ORDER_1ST_POLYLCF, SAMPLE_POINTS_POLYLCF) /*transposed X^T matrix using local memory allocation*/
  CML_CreateMatrixLocal(mtrxX_I, POLY_ORDER_1ST_POLYLCF, POLY_ORDER_1ST_POLYLCF) /*inverted X^-1 matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWX, SAMPLE_POINTS_POLYLCF, POLY_ORDER_1ST_POLYLCF) /*temp (W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWX, POLY_ORDER_1ST_POLYLCF, POLY_ORDER_1ST_POLYLCF) /*temp (X^T)*(W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWy, SAMPLE_POINTS_POLYLCF, 1) /*temp (W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWy, POLY_ORDER_1ST_POLYLCF, 1) /*temp (X^T)*(W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(vecLastPolyCoeff, POLY_ORDER_1ST_POLYLCF, 1) /*temp vector used for weighting using local memory allocation*/
  
  uint8_T row, col;
  boolean_T bMtrxInvFailed = FALSE;
      
  CML_v_TransposeMatrix(mtrxX_T, mtrxX);
  
  for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
      for(col = 0; col < POLY_ORDER_1ST_POLYLCF; col++){
          CML_GetMatrixElement(tmpMtrxWX,row,col) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(mtrxX,row,col);
      }
  }
  CML_v_MultiplyMatrices(tmpMtrxXTWX, mtrxX_T, tmpMtrxWX);
  LCF_CML_v_InvertMatrix(mtrxX_I, tmpMtrxXTWX); /* from cml_adapted.c --> tmpMtrxXTWX gets overwritten with identity matrix */
  if((mtrxX_I->Desc.row == 0u) || (mtrxX_I->Desc.col == 0u)){
      bMtrxInvFailed = TRUE;
  }else{
      for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
        CML_GetMatrixElement(tmpMtrxWy,row,0) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(vecY,row,0);
      }
      CML_v_MultiplyMatrices(tmpMtrxXTWy, mtrxX_T, tmpMtrxWy);
      
      CML_v_MultiplyMatrices(vecPolyCoeff1st, mtrxX_I, tmpMtrxXTWy);      
      
      bMtrxInvFailed = FALSE;
  }
  return bMtrxInvFailed;
}
/* ****************************************************************************
Functionname:    calculatePolyfit2nd

@brief           calculates a polynomial fit using least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle
                 y = X * a --> a = (X^T * (W*X))^-1 * (X^T * (W*y))

@param[in]       Weight : weighting factor vector (diagonal matrix elements)

@param[in]       mtrxX : model equation matrix X

@param[in]       vecY : y sample points

@return          bMtrxInvFailed : FALSE if matrix inversion was successful

@author          Alexander Fen
**************************************************************************** */
static boolean_T calculatePolyfit2nd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff2nd){
  CML_CreateMatrixLocal(mtrxX_T, POLY_ORDER_2ND_POLYLCF, SAMPLE_POINTS_POLYLCF) /*transposed X^T matrix using local memory allocation*/
  CML_CreateMatrixLocal(mtrxX_I, POLY_ORDER_2ND_POLYLCF, POLY_ORDER_2ND_POLYLCF) /*inverted X^-1 matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWX, SAMPLE_POINTS_POLYLCF, POLY_ORDER_2ND_POLYLCF) /*temp (W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWX, POLY_ORDER_2ND_POLYLCF, POLY_ORDER_2ND_POLYLCF) /*temp (X^T)*(W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWy, SAMPLE_POINTS_POLYLCF, 1) /*temp (W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWy, POLY_ORDER_2ND_POLYLCF, 1) /*temp (X^T)*(W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(vecLastPolyCoeff, POLY_ORDER_2ND_POLYLCF, 1) /*temp vector used for weighting using local memory allocation*/
  
  uint8_T row, col;
  boolean_T bMtrxInvFailed = FALSE;
    
  CML_v_TransposeMatrix(mtrxX_T, mtrxX);
  
  for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
      for(col = 0; col < POLY_ORDER_2ND_POLYLCF; col++){
          CML_GetMatrixElement(tmpMtrxWX,row,col) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(mtrxX,row,col);
      }
  }
  CML_v_MultiplyMatrices(tmpMtrxXTWX, mtrxX_T, tmpMtrxWX);
  LCF_CML_v_InvertMatrix(mtrxX_I, tmpMtrxXTWX); /* from cml_adapted.c --> tmpMtrxXTWX gets overwritten with identity matrix */
  if((mtrxX_I->Desc.row == 0u) || (mtrxX_I->Desc.col == 0u)){
      bMtrxInvFailed = TRUE;
  }else{
      for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
        CML_GetMatrixElement(tmpMtrxWy,row,0) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(vecY,row,0);
      }
      CML_v_MultiplyMatrices(tmpMtrxXTWy, mtrxX_T, tmpMtrxWy);
      
      CML_v_MultiplyMatrices(vecPolyCoeff2nd, mtrxX_I, tmpMtrxXTWy);      
     
      bMtrxInvFailed = FALSE;
  }
  return bMtrxInvFailed;
}
/* ****************************************************************************
Functionname:    calculatePolyfit3rd

@brief           calculates a polynomial fit using least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle
                 y = X * a --> a = (X^T * (W*X))^-1 * (X^T * (W*y))

@param[in]       Weight : weighting factor vector (diagonal matrix elements)

@param[in]       mtrxX : model equation matrix X

@param[in]       vecY : y sample points

@return          bMtrxInvFailed : FALSE if matrix inversion was successful

@author          Alexander Fen
**************************************************************************** */
static boolean_T calculatePolyfit3rd(CML_t_Matrix* Weight, CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff3rd){
  CML_CreateMatrixLocal(mtrxX_T, POLY_ORDER_3RD_POLYLCF, SAMPLE_POINTS_POLYLCF) /*transposed X^T matrix using local memory allocation*/
  CML_CreateMatrixLocal(mtrxX_I, POLY_ORDER_3RD_POLYLCF, POLY_ORDER_3RD_POLYLCF) /*inverted X^-1 matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWX, SAMPLE_POINTS_POLYLCF, POLY_ORDER_3RD_POLYLCF) /*temp (W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWX, POLY_ORDER_3RD_POLYLCF, POLY_ORDER_3RD_POLYLCF) /*temp (X^T)*(W*X) matrix using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxWy, SAMPLE_POINTS_POLYLCF, 1) /*temp (W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(tmpMtrxXTWy, POLY_ORDER_3RD_POLYLCF, 1) /*temp (X^T)*(W*y) vector using local memory allocation*/
  CML_CreateMatrixLocal(vecLastPolyCoeff, POLY_ORDER_3RD_POLYLCF, 1) /*temp vector used for weighting using local memory allocation*/
  
  uint8_T row, col;
  boolean_T bMtrxInvFailed = FALSE;
    
  CML_v_TransposeMatrix(mtrxX_T, mtrxX);
  
  for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
      for(col = 0; col < POLY_ORDER_3RD_POLYLCF; col++){
          CML_GetMatrixElement(tmpMtrxWX,row,col) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(mtrxX,row,col);
      }
  }
  CML_v_MultiplyMatrices(tmpMtrxXTWX, mtrxX_T, tmpMtrxWX);
  LCF_CML_v_InvertMatrix(mtrxX_I, tmpMtrxXTWX); /* from cml_adapted.c --> tmpMtrxXTWX gets overwritten with identity matrix */
  if((mtrxX_I->Desc.row == 0u) || (mtrxX_I->Desc.col == 0u)){
      bMtrxInvFailed = TRUE;
  }else{
      for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
        CML_GetMatrixElement(tmpMtrxWy,row,0) = CML_GetMatrixElement(Weight,row,0) * CML_GetMatrixElement(vecY,row,0);
      }
      CML_v_MultiplyMatrices(tmpMtrxXTWy, mtrxX_T, tmpMtrxWy);
      
      CML_v_MultiplyMatrices(vecPolyCoeff3rd, mtrxX_I, tmpMtrxXTWy);      
     
      bMtrxInvFailed = FALSE;
  }
  return bMtrxInvFailed;
}

/* ****************************************************************************
Functionname:    createEquationMatrix1st

@brief           create equation matrix X with model equations

@description     create equation matrix X with model equations for 1st order

@param[in/out]   mtrxX : model equation matrix X (out --> updated)

@param[in]       vecX : x sample points

@author          Alexander Fen
**************************************************************************** */
static void createEquationMatrix1st(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX){
  //uint8_T row, col;
  uint8_T row;
  /*fill equation matrix X */
  for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
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
  for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
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
static void createEquationMatrix3rd(CML_t_Matrix* mtrxX, CML_t_Matrix* vecX, real32_T pCrvDecay_nu, real32_T pCrvChngDecay_nu){
  //uint8_T row, col;
  uint8_T row;
  /*fill equation matrix X */
  for(row = 0; row < SAMPLE_POINTS_POLYLCF; row++){
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
      /* use pCrvChngDecay_nu for damping of curvature change*/
      if(pCrvChngDecay_nu > 0.0001f){
          CML_GetMatrixElement(mtrxX,row,3) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) / 6.0f / pCrvChngDecay_nu;
      }else{
          CML_GetMatrixElement(mtrxX,row,3) = CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) * CML_GetMatrixElement(vecX,row,0) / 6.0f;
      }
  }
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
static real32_T getDevToTraj(CML_t_Matrix* mtrxX, CML_t_Matrix* vecY, CML_t_Matrix* vecPolyCoeff, CML_t_Matrix* Weight){
  CML_CreateMatrixLocal(tmpVecXa, SAMPLE_POINTS_POLYLCF, 1) /*temp (X*a) Vec using local memory allocation*/
  real32_T fDevTraj_met = 0.0;
  uint8_T i;  
  
      CML_v_MultiplyMatrices(tmpVecXa, mtrxX, vecPolyCoeff);
      
      for(i = 0; i < SAMPLE_POINTS_POLYLCF; i++){
          if(CML_GetMatrixElement(Weight, i, 0) > 0.0001f){
              fDevTraj_met += CML_f_Abs(CML_GetMatrixElement(tmpVecXa, i, 0) - CML_GetMatrixElement(vecY, i, 0));
          }
      }         
  
  return fDevTraj_met;
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
  fArcTan = x / (1 + (0.28086 * x * x));
  return fArcTan;
}

/* ****************************************************************************
Functionname:    polyfitLCF

@brief           calculates a 1st, 2nd and 3rd order polynomial fit using least square method

@description     the measured x-/y-object positions are stored and ego motion compensated
                 using the driven delta ego distance and rotated delta ego yaw angle.
                 The equation matrix X is filled with the x/y sample points and
                 the polynomial coefficient vector is calculated

@param[in]       fObjXPos_met : target object x position

@param[in]       fObjYPos_met : target object y position

@param[out]      vecPolyCoeff : calculated polynomial coefficients

@author          David Handtke
**************************************************************************** */
void polyfitLCF(const polyfitLCFInput* input, polyfitLCFOutput* output){
  CML_CreateMatrixLocal(mtrxX1st, SAMPLE_POINTS_POLYLCF, POLY_ORDER_1ST_POLYLCF) /*create X matrix with sample point equations using static memory allocation*/
  CML_CreateMatrixLocal(mtrxX2nd, SAMPLE_POINTS_POLYLCF, POLY_ORDER_2ND_POLYLCF) /*create X matrix with sample point equations using static memory allocation*/
  CML_CreateMatrixLocal(mtrxX3rd, SAMPLE_POINTS_POLYLCF, POLY_ORDER_3RD_POLYLCF) /*create X matrix with sample point equations using static memory allocation*/
  CML_CreateMatrixLocal(vecY, SAMPLE_POINTS_POLYLCF, 1) /* vector for object y-position storage which gets filled from input struct and transformed each cycle */
  CML_CreateMatrixLocal(vecX, SAMPLE_POINTS_POLYLCF, 1) /* vector for object x-position storage which gets filled from input struct and transformed each cycle */
  CML_CreateMatrixLocal(vecPolyCoeff1st, POLY_ORDER_1ST_POLYLCF, 1) /* calculated polynomial coefficients which are written to the output struct */
  CML_CreateMatrixLocal(vecPolyCoeff2nd, POLY_ORDER_2ND_POLYLCF, 1) /* calculated polynomial coefficients which are written to the output struct */
  CML_CreateMatrixLocal(vecPolyCoeff3rd, POLY_ORDER_3RD_POLYLCF, 1) /* calculated polynomial coefficients which are written to the output struct */
  CML_CreateMatrixLocal(Weight, SAMPLE_POINTS_POLYLCF, 1) /* weighting factors --> diagonal elements of matrix stored as vector for element-wise calculations */
      
  /*initialize local variables*/
  	boolean_T bTrajInvalid1st_bool = FALSE;
		boolean_T bTrajInvalid2nd_bool = FALSE;
		boolean_T bTrajInvalid3rd_bool = FALSE;

		int i;
  /*Initialize matrices*/
  for(i = 0; i < SAMPLE_POINTS_POLYLCF; i++){
	  CML_GetMatrixElement(vecX,i,0) = input->fXArray_met[i];
	  CML_GetMatrixElement(vecY,i,0) = input->fYArray_met[i];
	  CML_GetMatrixElement(Weight,i,0) = input->fWeight_nu[i];
  }	

/* calculate 1st order fit */
        if(input->bEnable1st_bool){                               
            
            createEquationMatrix1st(mtrxX1st, vecX);
            bTrajInvalid1st_bool = calculatePolyfit1st(Weight, mtrxX1st, vecY, vecPolyCoeff1st);
			
			if(!bTrajInvalid1st_bool){
      
			output->fPosY0_1st_met = CML_GetMatrixElement(vecPolyCoeff1st,0,0);
      output->fHeading_1st_rad = getArcTanSmallAng(CML_GetMatrixElement(vecPolyCoeff1st,1,0));
      output->fDevToTraj_1st_met = getDevToTraj(mtrxX1st, vecY, vecPolyCoeff1st, Weight);  
			
			}
			else{
			output->fPosY0_1st_met = 0.0f;
            output->fHeading_1st_rad = 0.0f;
            output->fDevToTraj_1st_met = 0.0f;  
			}
            output->bTrajInvalid1st_bool = bTrajInvalid1st_bool;               
		}
		else{
			output->bTrajInvalid1st_bool = TRUE;
			output->fPosY0_1st_met = 0.0f;
            output->fHeading_1st_rad = 0.0f;
            output->fDevToTraj_1st_met = 0.0f; 	
		}

/* calculate 2nd order fit */
        if(input->bEnable2nd_bool){                               
            
            createEquationMatrix2nd(mtrxX2nd, vecX, input->fCrvDecay_nu);
            bTrajInvalid2nd_bool = calculatePolyfit2nd(Weight, mtrxX2nd, vecY, vecPolyCoeff2nd);
			
			if(!bTrajInvalid2nd_bool){
			output->fPosY0_2nd_met = CML_GetMatrixElement(vecPolyCoeff2nd,0,0);
      output->fHeading_2nd_rad = getArcTanSmallAng(CML_GetMatrixElement(vecPolyCoeff2nd,1,0));
			output->fCrv_2nd_1pm = CML_GetMatrixElement(vecPolyCoeff2nd,2,0);

      output->fDevToTraj_2nd_met = getDevToTraj(mtrxX2nd, vecY, vecPolyCoeff2nd, Weight);  
			
			}
			else{
			output->fPosY0_2nd_met = 0.0f;
      output->fHeading_2nd_rad = 0.0f;
			output->fCrv_2nd_1pm =0.0f;
      output->fDevToTraj_2nd_met = 0.0f;  
			}
      output->bTrajInvalid2nd_bool = bTrajInvalid2nd_bool;               
		}
		else{
			output->bTrajInvalid2nd_bool = TRUE;
			output->fPosY0_2nd_met = 0.0f;
      output->fHeading_2nd_rad = 0.0f;
			output->fCrv_2nd_1pm =0.0f;
     output->fDevToTraj_2nd_met = 0.0f; 	
		}					
		
/*	calculate 3rd order fit*/
            if(input->bEnable3rd_bool){                               
            
            createEquationMatrix3rd(mtrxX3rd, vecX, input->fCrvDecay_nu,input->fCrvChngDecay_nu);
            bTrajInvalid3rd_bool = calculatePolyfit3rd(Weight, mtrxX3rd, vecY, vecPolyCoeff3rd);
			
			if(!bTrajInvalid3rd_bool){
			output->fPosY0_3rd_met = CML_GetMatrixElement(vecPolyCoeff3rd,0,0);
      output->fHeading_3rd_rad = getArcTanSmallAng(CML_GetMatrixElement(vecPolyCoeff3rd,1,0));
			output->fCrv_3rd_1pm = CML_GetMatrixElement(vecPolyCoeff3rd,2,0);
			output->fChngOfCrv_3rd_1pm2 =CML_GetMatrixElement(vecPolyCoeff3rd,3,0);

      output->fDevToTraj_3rd_met = getDevToTraj(mtrxX3rd, vecY, vecPolyCoeff3rd, Weight);  
			
			}
			else{
			output->fPosY0_3rd_met = 0.0f;
      output->fHeading_3rd_rad = 0.0f;
			output->fCrv_3rd_1pm =0.0f;
			output->fChngOfCrv_3rd_1pm2 =0.0f;
      output->fDevToTraj_3rd_met = 0.0f;  
			}
      output->bTrajInvalid3rd_bool = bTrajInvalid3rd_bool;               
		}
		else{
			output->bTrajInvalid3rd_bool = TRUE;
			output->fPosY0_3rd_met = 0.0f;
      output->fHeading_3rd_rad = 0.0f;
			output->fCrv_3rd_1pm =0.0f;
			output->fChngOfCrv_3rd_1pm2 =0.0f;
      output->fDevToTraj_3rd_met = 0.0f; 	
		}
}