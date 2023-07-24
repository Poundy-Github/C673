#ifndef CRV_KALMAN_FILTER_CENTER_SOURCE
#define CRV_KALMAN_FILTER_CENTER_SOURCE
/*! \file **********************************************************************

  COMPANY:                   Continental ADAS DF

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Functions)

  MODULNAME:                 crvKalmanFilter.c

  DESCRIPTION:               

  AUTHOR:                    $Author:  $

  CREATION DATE:             $Date:  $

  VERSION:                   $Revision: 1.0 $

  CHANGES:                
  ---*/ /*---
  CHANGE:                    $Log: $
 

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "crvKalmanFilter.h"


#include "cml_ext.h" /*include common math library for matrix operations*/
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
/*length of the KF state vector*/
#ifndef STATE_LENGTH_CRVKF
#define STATE_LENGTH_CRVKF (2u)
#endif

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/
/*state of the KF*/
static uint8_T valid_crvKF = 0u;
/*status_crvKF of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_crvKF = 0u;
/*measurement weight*/
static real32_T measWeight_crvKF = 0.0f;
/*internal quality*/
static real32_T internalQuality_crvKF = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_crvKF = 0.0f;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void reset_crvKF(CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF);
static void predict_crvKF(real32_T dX_crvKF, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF, real32_T P_ABPLBP_CrvKFDefCurve_1pm, 
                          real32_T P_ABPLBP_CrvKFQ11Fac_nu,real32_T P_ABPLBP_CrvKFQ11FacStraight_nu, real32_T curvature_1pm);
static void init_crvKF(const CML_t_Matrix* z_crvKF, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF, CML_t_Matrix* R_crvKF, real32_T quality, real32_T P_ABPLBP_CrvKFInitRFactor_nu, real32_T P_ABPLBP_CrvKFMnInitQual_perc);
static void update_crvKF(const CML_t_Matrix* z_crvKF, const CML_t_Matrix* R_crvKF, real32_T weight, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF);
static void maintenance_crvKF(real32_T deltaT_sec, real32_T P_ABPLBP_CrvKFIncQual_1ps, real32_T P_ABPLBP_CrvKFDecQualDeg_1ps, real32_T P_ABPLBP_CrvKFDecQualPred_1ps, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF);
/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************
Functionname:                                          */ /*!

@brief           

@description     

@param[in]       

@param[in]       

@return          

@author          
**************************************************************************** */
void crvKalmanFilter(const crvKFInTypeV2* inputs, crvKFOutType* outputs) {
  
   /*state Matrix x_crvKF*/
   CML_CreateMatrix(x_crvKF, STATE_LENGTH_CRVKF, 1)
   /*covariance matrix P_crvKF*/
   CML_CreateMatrix(P_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
   /*measurement matrix z_crvKF*/
   CML_CreateMatrix(z_crvKF, STATE_LENGTH_CRVKF, 1)
   /*measurement variance matrix R_crvKF*/
   CML_CreateMatrix(R_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)

   real32_T dX_crvKF;
   
	/*calculate dX*/
	dX_crvKF = inputs->sf_DeltaT_sec*inputs->sf_VehVelX_mps;

	/*geometric dependent model error*/  
  if(inputs->sf_CrvKFErrCoeff1_nu<1e-5 || inputs->sf_CrvKFErrCoeff2_nu<1e-5||inputs->sf_DeltaT_sec<1e-5){
    kappa2diff_sigma_crvKF=1;
      }
  else{
    kappa2diff_sigma_crvKF = 1 / inputs->sf_CrvKFErrCoeff1_nu / (inputs->sf_CrvKFErrCoeff2_nu*inputs->sf_DeltaT_sec) / (inputs->sf_CrvKFErrCoeff2_nu*inputs->sf_DeltaT_sec);
     }

	/*predict -  will only be executed if valid state is set*/
	predict_crvKF(dX_crvKF, x_crvKF, P_crvKF, inputs->sf_CrvKFDefCurve_1pm, 
                          inputs->sf_CrvKFQ11Fac_nu,inputs->sf_CrvKFQ11FacStraight_nu, inputs->sf_Crv_1pm);

	/*initialize measurement vector z*/
	CML_GetMatrixElement(z_crvKF, 0, 0) = inputs->sf_Crv_1pm;
	CML_GetMatrixElement(z_crvKF, 1, 0) = inputs->sf_CrvChng_1pm2;

	/*initialize R matrix*/
	CML_GetMatrixElement(R_crvKF, 0, 0) = inputs->sf_CrvStdDev_1pm*inputs->sf_CrvStdDev_1pm;
	CML_GetMatrixElement(R_crvKF, 1, 1) = inputs->sf_CrvChngStdDev_1pm2*inputs->sf_CrvChngStdDev_1pm2;

	/*Init or Update*/
	if (!valid_crvKF && !(inputs->sf_DegradedUpdate_bool)) {
		/*initialization - for a better initialization the R matrix is multiplied with a constant (>1)*/
		init_crvKF(z_crvKF, x_crvKF, P_crvKF, R_crvKF, inputs->sf_OverallMeasurementQuality_perc, inputs->sf_CrvKFInitRFactor_nu, inputs->sf_CrvKFMnInitQual_perc);
	}
	/*Update only if valid AND measurement quality > P_ABPLBP_CrvKFLowQual_nu*/
	else if (valid_crvKF && (inputs->sf_OverallMeasurementQuality_perc >= (inputs->sf_CrvKFMnUpdateQual_perc))){
		if (inputs->sf_DegradedUpdate_bool) {
			/*degraded update - quality and weight are the 2 parameters*/
			update_crvKF(z_crvKF, R_crvKF, inputs->sf_CrvKFDegradeWeight_nu, x_crvKF, P_crvKF);
      }
		else {
			/*full update*/
      update_crvKF(z_crvKF, R_crvKF, 1, x_crvKF, P_crvKF);		
		}
	}  
   /*maintenance_laneKFCntr*/
    if(!(status_crvKF == 4)){
        maintenance_crvKF(inputs->sf_DeltaT_sec, inputs->sf_CrvKFIncQual_1ps, inputs->sf_CrvKFDecQualDeg_1ps, inputs->sf_CrvKFDecQualPred_1ps, x_crvKF, P_crvKF);
    }
   /*Reset filter if basic lane data are not valid*/
   if (!inputs->sf_crvDataValid_bool)reset_crvKF(x_crvKF, P_crvKF);  

	
	/*Set outputs*/  
	outputs->sf_Crv_1pm = CML_GetMatrixElement(x_crvKF, 0, 0);
	outputs->sf_CrvChng_1pm2 = CML_GetMatrixElement(x_crvKF, 1, 0);  
	outputs->sf_KFStatus_btf = status_crvKF; 
	outputs->sf_QualityMeasure_perc = internalQuality_crvKF; 
}

/*****************************************************************************
Functionname:                                          */ /*!

@brief           

@description     

@param[in]       

@param[in]       

@return          

@author          
**************************************************************************** */
static void update_crvKF(const CML_t_Matrix* z_crvKF, const CML_t_Matrix* R_crvKF, real32_T weight, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF){
    
  /*create local matrices*/
  CML_CreateMatrixLocal(I_crvKF,STATE_LENGTH_CRVKF,STATE_LENGTH_CRVKF)
  CML_CreateMatrixLocal(H_crvKF,STATE_LENGTH_CRVKF,STATE_LENGTH_CRVKF)
  CML_CreateMatrixLocal(H_trans_crvKF,STATE_LENGTH_CRVKF,STATE_LENGTH_CRVKF)
  CML_CreateMatrixLocal(PH_trans_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
  CML_CreateMatrixLocal(HPH_trans_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
  CML_CreateMatrixLocal(HPH_transPlusR_crfKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
  CML_CreateMatrixLocal(HPH_transPlusR_inv_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)  
  CML_CreateMatrixLocal(K_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)  
   CML_CreateMatrixLocal(HX_crvKF, STATE_LENGTH_CRVKF, 1)
   CML_CreateMatrixLocal(ZSubHX_crvKF, STATE_LENGTH_CRVKF, 1)
   CML_CreateMatrixLocal(KZSubHX_crvKF, STATE_LENGTH_CRVKF, 1)
   CML_CreateMatrixLocal(KH_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
   CML_CreateMatrixLocal(ISubKH_crvKF, STATE_LENGTH_CRVKF,
            STATE_LENGTH_CRVKF)
   CML_CreateMatrixLocal(P_tmp_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)  
  
  /*update state with measurement*/
  CML_v_CreateIdentityMatrix(I_crvKF, STATE_LENGTH_CRVKF);
  CML_v_CreateIdentityMatrix(H_crvKF, STATE_LENGTH_CRVKF);
  CML_v_TransposeMatrix(H_trans_crvKF, H_crvKF);
  /*PH'*/
  CML_v_MultiplyMatrices(PH_trans_crvKF, P_crvKF, H_trans_crvKF);  
  /*H[PH']*/
  CML_v_MultiplyMatrices(HPH_trans_crvKF, H_crvKF, PH_trans_crvKF);
  /*[HPH']+R*/
  CML_v_AddMatrices(HPH_transPlusR_crfKF, HPH_trans_crvKF, R_crvKF);
  /*inv([HPH'+R]*/
  //CML_v_InvertMatrix(HPH_transPlusR_inv_crvKF, HPH_transPlusR_crfKF);
  LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_crvKF, HPH_transPlusR_crfKF);
  if(HPH_transPlusR_inv_crvKF->Desc.col > 0){/*if inversion fails num. of cols and rows are set to 0*/
	/*K=[PH'][inv(HPH'+R)]*/
	CML_v_MultiplyMatrices(K_crvKF, PH_trans_crvKF, HPH_transPlusR_inv_crvKF);
	/*K=K*weight*/
	CML_v_ScaleMatrix(K_crvKF, weight);
	/*Hx*/
	CML_v_MultiplyMatrices(HX_crvKF, H_crvKF, x_crvKF);
	/*z-[Hx]*/
	CML_v_SubtractMatrices(ZSubHX_crvKF, z_crvKF, HX_crvKF);
	/*K[(z-Hx)]*/
	CML_v_MultiplyMatrices(KZSubHX_crvKF, K_crvKF, ZSubHX_crvKF);
	/*x=x+K(z-Hx)*/
	CML_v_AddMatrices(x_crvKF, x_crvKF, KZSubHX_crvKF);
	/*KH*/
	CML_v_MultiplyMatrices(KH_crvKF, K_crvKF, H_crvKF);
	/*I-[KH]*/
	CML_v_SubtractMatrices(ISubKH_crvKF, I_crvKF, KH_crvKF);
	/*P=[(I-K*H)]P*/
	CML_v_MultiplyMatrices(P_tmp_crvKF, ISubKH_crvKF, P_crvKF);
	CML_GetMatrixElement(P_crvKF, 0, 0) = CML_GetMatrixElement(P_tmp_crvKF, 0, 0);
	CML_GetMatrixElement(P_crvKF, 0, 1) = CML_GetMatrixElement(P_tmp_crvKF, 0, 1);
	CML_GetMatrixElement(P_crvKF, 1, 0) = CML_GetMatrixElement(P_tmp_crvKF, 1, 0);
	CML_GetMatrixElement(P_crvKF, 1, 1) = CML_GetMatrixElement(P_tmp_crvKF, 1, 1);	
	
	measWeight_crvKF = weight;

  }
  else{
	reset_crvKF(x_crvKF, P_crvKF);
  }
}

static void init_crvKF(const CML_t_Matrix* z_crvKF, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF, CML_t_Matrix* R_crvKF, real32_T quality, real32_T P_ABPLBP_CrvKFInitRFactor_nu, real32_T P_ABPLBP_CrvKFMnInitQual_perc){
    /*temporary matrices*/
    CML_CreateMatrixLocal(tmp_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
    CML_CreateMatrixLocal(R_scaled_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
    CML_CreateMatrixLocal(H_trans_crvKF, STATE_LENGTH_CRVKF,
            STATE_LENGTH_CRVKF)
    CML_CreateMatrixLocal(H_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)

  if (quality>P_ABPLBP_CrvKFMnInitQual_perc){  
    /*scale R*/
    CML_v_InitMatrix(R_scaled_crvKF, STATE_LENGTH_CRVKF,
      STATE_LENGTH_CRVKF, 0.0f);
    CML_GetMatrixElement(R_scaled_crvKF, 0, 0) = CML_GetMatrixElement(R_crvKF, 0, 0);
    CML_GetMatrixElement(R_scaled_crvKF, 1, 1) = CML_GetMatrixElement(R_crvKF, 1, 1);    
    CML_v_ScaleMatrix(R_scaled_crvKF,P_ABPLBP_CrvKFInitRFactor_nu); 
  
    /*initialize matrix H*/    
    CML_v_CreateIdentityMatrix(H_crvKF, STATE_LENGTH_CRVKF);   
    /*initialize matrix H'*/      
    CML_v_TransposeMatrix(H_trans_crvKF, H_crvKF);   
    /*tmp = H'R*/
    CML_v_MultiplyMatrices(tmp_crvKF,H_trans_crvKF, R_scaled_crvKF);
    /*[H'R]H*/
    CML_v_MultiplyMatrices(P_crvKF, tmp_crvKF, H_crvKF);
    /*fill x*/
    CML_v_MultiplyMatrices(x_crvKF, H_trans_crvKF, z_crvKF);    
    /*fill other states*/
    valid_crvKF = true;
    internalQuality_crvKF = 0.0f;
    measWeight_crvKF = 0.0f;
    status_crvKF = 4u;
  }  
}

static void predict_crvKF(real32_T dX_crvKF, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF, real32_T P_ABPLBP_CrvKFDefCurve_1pm, 
                          real32_T P_ABPLBP_CrvKFQ11Fac_nu,real32_T P_ABPLBP_CrvKFQ11FacStraight_nu, real32_T curvature_1pm){
 /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
   CML_CreateMatrixLocal(Q_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF)
   CML_CreateMatrixLocal(B_crvKF, STATE_LENGTH_CRVKF, 1)
   
   CML_CreateMatrixLocal(AX_crvKF, STATE_LENGTH_CRVKF, 1)
   CML_CreateMatrixLocal(A_trans_crvKF, STATE_LENGTH_CRVKF,
            STATE_LENGTH_CRVKF)
   CML_CreateMatrixLocal(PA_trans_crvKF, STATE_LENGTH_CRVKF,
            STATE_LENGTH_CRVKF)
   CML_CreateMatrixLocal(APA_trans_crvKF, STATE_LENGTH_CRVKF,
            STATE_LENGTH_CRVKF)

   real32_T dXPow2_crvKF;
   real32_T dXPow3_crvKF;
   real32_T dXPow4_crvKF;
 
   real32_T Q00_crvKF;
   real32_T Q01_crvKF;
  
   real32_T Q11_crvKF;
   
   real32_T sigmaSqr_crvKF;
   
  if (valid_crvKF)
  {
    /*initialize system matrix A*/
    CML_v_InitMatrix(A_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF, 0.0f);	
    dXPow2_crvKF = dX_crvKF * dX_crvKF;
    dXPow3_crvKF = dXPow2_crvKF * dX_crvKF;
    dXPow4_crvKF = dXPow3_crvKF * dX_crvKF;
    /*row 0: 1 dX_crvKF*/ 	
    CML_GetMatrixElement(A_crvKF, 0, 0) = 1.0f;
    CML_GetMatrixElement(A_crvKF, 0, 1) = dX_crvKF;
    /*row 1: 0 1*/ 
    CML_GetMatrixElement(A_crvKF, 1, 1) = 1.0f;
    /*initialize Q*/
    sigmaSqr_crvKF = kappa2diff_sigma_crvKF * kappa2diff_sigma_crvKF;
    Q00_crvKF = dXPow4_crvKF * sigmaSqr_crvKF / 4.0f;
    Q01_crvKF = dXPow3_crvKF * sigmaSqr_crvKF / 2.0f;	    
    Q11_crvKF = dXPow2_crvKF * sigmaSqr_crvKF;
    CML_GetMatrixElement(Q_crvKF, 0, 0) = Q00_crvKF;
    CML_GetMatrixElement(Q_crvKF, 0, 1) = Q01_crvKF;
    CML_GetMatrixElement(Q_crvKF, 1, 0) = Q01_crvKF;

	/* Smoothness and thus phase delay of the filtered curvature in dependence of the absolute value of the measured curvature */
	if (CML_f_Abs(curvature_1pm) > P_ABPLBP_CrvKFDefCurve_1pm){ 
		/* Driving in a curve -> Increase the filtering of kappa */
		CML_GetMatrixElement(Q_crvKF, 1, 1) = P_ABPLBP_CrvKFQ11Fac_nu * Q11_crvKF; // 1.0005* or 1.0002* (smooth) or 2* (dynamic) Factor needed to increase the dynamic of kappa
	}
	else {
		/* Driving on a straight -> increase the dynamic of kappa*/
		CML_GetMatrixElement(Q_crvKF, 1, 1) = P_ABPLBP_CrvKFQ11FacStraight_nu * Q11_crvKF; // 1.0005* or 1.0002* (smooth) or 2* (dynamic) Factor needed to increase the dynamic of kappa
	}

    /*initialize steering matrix*/
    CML_v_InitMatrix(B_crvKF, STATE_LENGTH_CRVKF, 1, 0.0f);    
    /*Ax*/
    CML_v_MultiplyMatrices(AX_crvKF, A_crvKF, x_crvKF);
    /*x = Ax + Bu*/
    CML_v_AddMatrices(x_crvKF, AX_crvKF, B_crvKF);
    /*A'*/
    CML_v_TransposeMatrix(A_trans_crvKF, A_crvKF);
    /*PA'*/
    CML_v_MultiplyMatrices(PA_trans_crvKF, P_crvKF, A_trans_crvKF);
    /*APA'*/
    CML_v_MultiplyMatrices(APA_trans_crvKF, A_crvKF, PA_trans_crvKF);
    /*P=APA'+Q*/
    CML_v_AddMatrices(P_crvKF, APA_trans_crvKF, Q_crvKF);	

    /*Measurement Weight*/
    measWeight_crvKF = 0.0f;
    status_crvKF = 3u;
  }  
}

/*****************************************************************************
Functionname:                                          */ /*!

@brief           

@description     

@param[in]       

@param[in]       

@return          

@author          
**************************************************************************** */
static void reset_crvKF(CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF){
  
  /*reset_crvKF parameters*/
   CML_v_InitMatrix(x_crvKF, STATE_LENGTH_CRVKF, 1, 0.0f);
   CML_v_InitMatrix(P_crvKF, STATE_LENGTH_CRVKF, STATE_LENGTH_CRVKF, 0.0f);
   valid_crvKF = FALSE;
   internalQuality_crvKF = 0.0f;
   measWeight_crvKF = 0.0f;
   status_crvKF = 5u;
}

/*****************************************************************************
Functionname:                                          */ /*!

@brief           

@description     

@param[in]       

@param[in]       

@return          

@author          
**************************************************************************** */
static void maintenance_crvKF(real32_T deltaT_sec, real32_T P_ABPLBP_CrvKFIncQual_1ps, real32_T P_ABPLBP_CrvKFDecQualDeg_1ps, real32_T P_ABPLBP_CrvKFDecQualPred_1ps, CML_t_Matrix* x_crvKF, CML_t_Matrix* P_crvKF){
	if(valid_crvKF){
		/*Full Update, Degraded Update or No Update (predict only)? */
		if (measWeight_crvKF > 0.9f) {
			/* Full Update */
			status_crvKF = 1u;
			/* Increase internal quality by P_ABPLBP_CrvKFIncQual_1ps per second*/   
			internalQuality_crvKF += P_ABPLBP_CrvKFIncQual_1ps*deltaT_sec;

		}
		else if (measWeight_crvKF > 0.0f) {
			/* Degraded Update */
			status_crvKF = 2u;
			/* Decrease internal quality by P_ABPLBP_CrvKFDecQualDeg_1ps per seconds */
			internalQuality_crvKF -= P_ABPLBP_CrvKFDecQualDeg_1ps*deltaT_sec;
		}
		else {
			/* No Update - Predict Only */
			status_crvKF = 3u;
			/* Decrease internal quality by P_ABPLBP_CrvKFDecQualPred_1ps per seconds */
			internalQuality_crvKF -= P_ABPLBP_CrvKFDecQualPred_1ps*deltaT_sec;
		}
	  
		/* Boundary check: 0 <= internalQuality <= 100 */
		if (internalQuality_crvKF < 0.0f) {
			internalQuality_crvKF = 0.0f;
      reset_crvKF(x_crvKF, P_crvKF);
		}
		else if (internalQuality_crvKF > 100.0f) {
			internalQuality_crvKF= 100.0f;
		}

 }else{
   status_crvKF = 0u;
 }
}
#endif