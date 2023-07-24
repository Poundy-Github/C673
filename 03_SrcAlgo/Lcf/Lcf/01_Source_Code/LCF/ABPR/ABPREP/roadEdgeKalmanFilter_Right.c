#ifndef ROAD_EDGE_KALMAN_FILTER_RIGHT_SOURCE
#define ROAD_EDGE_KALMAN_FILTER_RIGHT_SOURCE

/*! \file **********************************************************************

 COMPANY:                   Continental ADAS DF

 CPU:                       CPU-Independent

 COMPONENT:                 LCF (Lateral Control Functions)

 MODULNAME:                 raodEdgeKalmanFilter_Left.c

 DESCRIPTION:

 AUTHOR:                    $Author: Handtke-EXT, David (uidq4009) $

 CREATION DATE:             $Date: 2017/05/11 09:43:55CEST $

 VERSION:                   $Revision: 1.1 $

 CHANGES:
 ---*//*---


 **************************************************************************** */

/*****************************************************************************
 INCLUDES
 ****************************************************************************/
#include "roadEdgeKalmanFilter.h"

#include "cml_ext.h" /*include common math library for matrix operations*/

#include "cml_adapted.h"
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
#ifndef STATE_LENGTH_RoadKF
#define STATE_LENGTH_RoadKF (4u)
#endif

/*****************************************************************************
 LOCAL VARIABLES
 *****************************************************************************/
/*state of the KF*/
static uint8_T valid_roadEdgeKFRi = 0u;
/*status_roadEdgeKFRi of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_roadEdgeKFRi = 0u;
/*measurement weight*/
static real32_T measWeight_roadEdgeKFRi = 0.0f;
/*internal quality*/
static real32_T internalQuality_roadEdgeKFRi = 0.0f;
/*variable for the yaw rate standard deviation - TODO: really needed?*/
static real32_T vehYawRateStdDev_roadEdgeKFRi = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_roadEdgeKFRi = 0.0f;

/*****************************************************************************
 FUNCTION PROTOTYPES
 *****************************************************************************/
static void reset_roadEdgeKFRi(CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi);
static void predict_roadEdgeKFRi(real32_T dT_roadEdgeKFRi, real32_T dX_roadEdgeKFRi,
         real32_T vehYawRate, CML_t_Matrix* x_roadEdgeKFRi,
         CML_t_Matrix* P_roadEdgeKFRi, real32_T P_ABPREP_RoadKFDynDistYFact_nu,
            real32_T P_ABPREP_RoadKFDynYawFactor_nu,real32_T P_ABPREP_RoadKFDynCrvFactor_nu, real32_T P_ABPREP_RoadKFDynCrvRtFactor_nu);
static void init_roadEdgeKFRi(const CML_t_Matrix* z_roadEdgeKFRi, CML_t_Matrix* R_roadEdgeKFRi, real32_T quality, CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi, uint8_T P_ABPREP_RoadKFMnInitQual_perc, real32_T P_ABPREP_RoadKFInitRFactor_nu);
static void update_roadEdgeKFRi(const CML_t_Matrix* z_roadEdgeKFRi,
         const CML_t_Matrix* R_roadEdgeKFRi, real32_T weight,
         CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi, real32_T P_ABPREP_RoadKFKGainFac_nu);
static void maintenance_roadEdgeKFRi(CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi, real32_T P_ABPREP_RoadKFIncQual_1ps,
                                    real32_T P_ABPREP_RoadKFDecQualDeg_1ps, real32_T P_ABPREP_RoadKFDecQualPred_1ps,
                                        real32_T deltaT_sec);

/*****************************************************************************
 FUNCTIONS
 *****************************************************************************/
/*****************************************************************************
 Functionname:                                          *//*!

 @brief

 @description

 @param[in]

 @param[in]

 @return

 @author
 **************************************************************************** */
void roadEdgeKalmanFilter_Right(const roadEdgeKFInType* inputs, roadEdgeKFOutType* outputs)
{
   /*state Matrix x_roadEdgeKFRi*/
   CML_CreateMatrix(x_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   /*covariance matrix P_roadEdgeKFRi*/
   CML_CreateMatrix(P_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   /*measurement matrix z_roadEdgeKFRi*/
   CML_CreateMatrix(z_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   /*measurement variance matrix R_roadEdgeKFRi*/
   CML_CreateMatrix(R_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)

   real32_T dX_roadEdgeKFRi;
   real32_T PosY0Diff_roadEdgeKFRi;
   /*calculate dX_roadEdgeKFRi*/
   dX_roadEdgeKFRi = inputs->sf_DeltaT_sec * inputs->sf_VehVelX_mps;
   vehYawRateStdDev_roadEdgeKFRi = inputs->sf_VehYawRateStdDev_radps;
  
  /*geometric dependent model error*/ 
	if(inputs->sf_LaneKFErrCoeff1_met<1e-5 || inputs->sf_LaneKFErrCoeff2_mps<1e-5||inputs->sf_DeltaT_sec<1e-5){
		kappa2diff_sigma_roadEdgeKFRi = 1;
	}
	else{
		kappa2diff_sigma_roadEdgeKFRi = 1 / inputs->sf_LaneKFErrCoeff1_met
			/ (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec)
			/ (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec);
	}

   /*In case of an lane change allow the PosY0 position to jump in the corresponding cycle - only if kalman filter has been valid*/
   if (status_roadEdgeKFRi > 0 && status_roadEdgeKFRi < 4){
       /*check lane change detection*/
      if(inputs->sf_LaneChange_bool){
          /*a lateral position jump is forced in case of a lane change*/
          CML_GetMatrixElement(x_roadEdgeKFRi, 0, 0) = inputs->sf_PosY0_met;
      }
   }

   /*predict_roadEdgeKFRi -  will only be executed if valid_roadEdgeKFRi state is set*/
   predict_roadEdgeKFRi(inputs->sf_DeltaT_sec, dX_roadEdgeKFRi,
            inputs->sf_VehYawRate_radps, x_roadEdgeKFRi, P_roadEdgeKFRi, inputs->sf_LaneKFDynDistYFact_nu,
            inputs->sf_LaneKFDynYawFactor_nu, inputs->sf_LaneKFDynCrvFact_nu, inputs->sf_LaneKFDynCrvRateFact_nu);

   /*initialize measurement vector z_roadEdgeKFRi*/
   CML_GetMatrixElement(z_roadEdgeKFRi, 0, 0)= inputs->sf_PosY0_met;
   CML_GetMatrixElement(z_roadEdgeKFRi, 1, 0)= inputs->sf_HeadingAngle_rad;
   CML_GetMatrixElement(z_roadEdgeKFRi, 2, 0)= inputs->sf_Crv_1pm;
   CML_GetMatrixElement(z_roadEdgeKFRi, 3, 0)= inputs->sf_CrvChng_1pm2;

   /*initialize R_roadEdgeKFRi matrix*/
   CML_GetMatrixElement(R_roadEdgeKFRi, 0, 0)= inputs->sf_PosY0StdDev_met*inputs->sf_PosY0StdDev_met;
   CML_GetMatrixElement(R_roadEdgeKFRi, 1, 1)= inputs->sf_HeadingAngleStdDev_rad*inputs->sf_HeadingAngleStdDev_rad;
   CML_GetMatrixElement(R_roadEdgeKFRi, 2, 2)= inputs->sf_CrvStdDev_1pm*inputs->sf_CrvStdDev_1pm;
   CML_GetMatrixElement(R_roadEdgeKFRi, 3, 3)= inputs->sf_CrvChngStdDev_1pm2*inputs->sf_CrvChngStdDev_1pm2;

   /*Init or Update*/
   if (!valid_roadEdgeKFRi && !(inputs->sf_DegradedUpdate_bool))
   {
      /*initialization - for A_roadEdgeKFRi better initialization the R_roadEdgeKFRi matrix is multiplied with A_roadEdgeKFRi constant (>1)*/
      init_roadEdgeKFRi(z_roadEdgeKFRi, R_roadEdgeKFRi, inputs->sf_OverallMeasurementQuality_perc, x_roadEdgeKFRi, P_roadEdgeKFRi, inputs->sf_LaneKFMnInitQual_perc, inputs->sf_LaneKFInitRFactor_nu);
   }
   /*Update only if valid AND measurement quality > sf_LaneKFMnUpdateQual_perc*/
   else if (valid_roadEdgeKFRi  && (inputs->sf_OverallMeasurementQuality_perc >= (inputs->sf_LaneKFMnUpdateQual_perc))){
       if (inputs->sf_DegradedUpdate_bool){
           /*degraded update_roadEdgeKFRi - quality and weight are the 2 parameters*/
            update_roadEdgeKFRi(z_roadEdgeKFRi, R_roadEdgeKFRi, inputs->sf_LaneKFDegradeWeight_nu, x_roadEdgeKFRi, P_roadEdgeKFRi, inputs->sf_LaneKFKGainFac_nu);
      }
      else
      {
         /*full update_roadEdgeKFRi*/
         update_roadEdgeKFRi(z_roadEdgeKFRi, R_roadEdgeKFRi, 1.0f, x_roadEdgeKFRi, P_roadEdgeKFRi, inputs->sf_LaneKFKGainFac_nu);
      }
   }
   /*maintenance_roadEdgeKFRi*/
    if(!(status_roadEdgeKFRi == 4)){
        maintenance_roadEdgeKFRi(x_roadEdgeKFRi, P_roadEdgeKFRi,inputs->sf_LaneKFIncQual_1ps,
                                    inputs->sf_LaneKFDecQualDeg_1ps, inputs->sf_LaneKFDecQualPred_1ps,
                                        inputs->sf_DeltaT_sec);
    }
   /*Reset filter if basic lane data are not valid*/
   if (!inputs->sf_LaneDataValid_bool)
      reset_roadEdgeKFRi(x_roadEdgeKFRi, P_roadEdgeKFRi);
   /*Set outputs*/
   outputs->sf_PosY0_met = CML_GetMatrixElement(x_roadEdgeKFRi, 0, 0);
   outputs->sf_HeadingAngle_rad = CML_GetMatrixElement(x_roadEdgeKFRi, 1, 0);
   outputs->sf_Crv_1pm = CML_GetMatrixElement(x_roadEdgeKFRi, 2, 0);
   outputs->sf_CrvChng_1pm2 = CML_GetMatrixElement(x_roadEdgeKFRi, 3, 0);
   outputs->sf_KFStatus_btf = status_roadEdgeKFRi;
   outputs->sf_QualityMeasure_perc = internalQuality_roadEdgeKFRi;
   
   outputs->sf_PosY0Variance_met2 = CML_GetMatrixElement(P_roadEdgeKFRi, 0, 0);
   outputs->sf_HeadingAngleVariance_rad2 = CML_GetMatrixElement(P_roadEdgeKFRi, 1, 1);
   outputs->sf_CrvVariance_1pm2 = CML_GetMatrixElement(P_roadEdgeKFRi, 2, 2);
   outputs->sf_CrvRateVariance_1pm4 = CML_GetMatrixElement(P_roadEdgeKFRi, 3, 3);
}

/*****************************************************************************
 Functionname:                                          *//*!

 @brief

 @description

 @param[in]

 @param[in]

 @return

 @author
 **************************************************************************** */
static void reset_roadEdgeKFRi(CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi)
{
   /*reset_roadEdgeKFRi parameters*/
   CML_v_InitMatrix(x_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1, 0.0f);
   CML_v_InitMatrix(P_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF, 0.0f);
   valid_roadEdgeKFRi = FALSE;
   internalQuality_roadEdgeKFRi = 0.0f;
   measWeight_roadEdgeKFRi = 0.0f;
   status_roadEdgeKFRi = 5u;
}
/*****************************************************************************
 Functionname:                                          *//*!

 @brief

 @description

 @param[in]

 @param[in]

 @return

 @author
 **************************************************************************** */
static void maintenance_roadEdgeKFRi(CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi, real32_T P_ABPREP_RoadKFIncQual_1ps,
                                    real32_T P_ABPREP_RoadKFDecQualDeg_1ps, real32_T P_ABPREP_RoadKFDecQualPred_1ps,
                                        real32_T deltaT_sec)
{
   if (valid_roadEdgeKFRi)
   {
      /*Full Update, Degraded Update or No Update (predict only)? */
      if (measWeight_roadEdgeKFRi > 0.9f)
      {
         /* Full Update */
         status_roadEdgeKFRi = 1u;
         /* Increase internal quality by P_ABPREP_RoadKFIncQual_1ps per second*/       
         internalQuality_roadEdgeKFRi += P_ABPREP_RoadKFIncQual_1ps*deltaT_sec;
      }
      else if (measWeight_roadEdgeKFRi > 0.0f)
      {
         /* Degraded Update */
         status_roadEdgeKFRi = 2u;
         /* Decrease internal quality by P_ABPREP_RoadKFDecQualDeg_1ps per seconds */
         internalQuality_roadEdgeKFRi -= P_ABPREP_RoadKFDecQualDeg_1ps*deltaT_sec;
      }
      else
      {
         /* No Update - Predict Only */
         status_roadEdgeKFRi = 3u;
         /* Decrease internal quality by P_ABPREP_RoadKFDecQualPred_1ps per seconds */
         internalQuality_roadEdgeKFRi -= P_ABPREP_RoadKFDecQualPred_1ps*deltaT_sec;
      }

      /* Boundary check: 0 <= internalQuality <= 100 */
      if (internalQuality_roadEdgeKFRi < 0.0f)
      {
         internalQuality_roadEdgeKFRi = 0.0f;
         reset_roadEdgeKFRi(x_roadEdgeKFRi, P_roadEdgeKFRi);
      }
      else if (internalQuality_roadEdgeKFRi > 100.0f)
      {
         internalQuality_roadEdgeKFRi = 100.0f;
      }

   }
   else
   {
      status_roadEdgeKFRi = 0u;
   }
}
/*****************************************************************************
 Functionname:                                          *//*!

 @brief

 @description

 @param[in]

 @param[in]

 @return

 @author
 **************************************************************************** */
static void update_roadEdgeKFRi(const CML_t_Matrix* z_roadEdgeKFRi,
         const CML_t_Matrix* R_roadEdgeKFRi, real32_T weight,
         CML_t_Matrix* x_roadEdgeKFRi, CML_t_Matrix* P_roadEdgeKFRi, real32_T P_ABPREP_RoadKFKGainFac_nu)
{
   /*temporary matrices*/
   CML_CreateMatrixLocal(I_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(H_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(H_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(K_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(PH_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HPH_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HPH_transPlusR_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HPH_transPlusR_inv_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HX_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(ZSubHX_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(KZSubHX_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(KH_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(ISubKH_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(P_tmp_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)

   /*update_roadEdgeKFRi state with measurement*/
   CML_v_CreateIdentityMatrix(I_roadEdgeKFRi, STATE_LENGTH_RoadKF);
   CML_v_CreateIdentityMatrix(H_roadEdgeKFRi, STATE_LENGTH_RoadKF);
   CML_v_TransposeMatrix(H_trans_roadEdgeKFRi, H_roadEdgeKFRi);
   /*PH'*/
   CML_v_MultiplyMatrices(PH_trans_roadEdgeKFRi, P_roadEdgeKFRi, H_trans_roadEdgeKFRi);
   /*H_roadEdgeKFRi[PH']*/
   CML_v_MultiplyMatrices(HPH_trans_roadEdgeKFRi, H_roadEdgeKFRi, PH_trans_roadEdgeKFRi);
   /*[HPH']+R_roadEdgeKFRi*/
   CML_v_AddMatrices(HPH_transPlusR_roadEdgeKFRi, HPH_trans_roadEdgeKFRi, R_roadEdgeKFRi);
   /*inv([HPH'+R_roadEdgeKFRi]*/
   //CML_v_InvertMatrix(HPH_transPlusR_inv_roadEdgeKFRi, HPH_transPlusR_roadEdgeKFRi);
   LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_roadEdgeKFRi, HPH_transPlusR_roadEdgeKFRi);
   /*if inversion fails num. of cols and rows are set to 0*/
   if (HPH_transPlusR_inv_roadEdgeKFRi->Desc.col > 0)
   {
      /*K_roadEdgeKFRi=[PH'][inv(HPH'+R_roadEdgeKFRi)]*/
      CML_v_MultiplyMatrices(K_roadEdgeKFRi, PH_trans_roadEdgeKFRi,
               HPH_transPlusR_inv_roadEdgeKFRi);
      /*K_roadEdgeKFRi=K_roadEdgeKFRi*weight*/
      CML_v_ScaleMatrix(K_roadEdgeKFRi, weight);

      /* if degradedUpdate == true -> Set first row of K_roadEdgeKFRi to FACTOR*K_roadEdgeKFRi -> weight of Disty = FACTOR*weight */
      if (weight < 1.0f)
      {
         /*set process noise covariance matrix Q_roadEdgeKFRi row 0*/
         CML_GetMatrixElement(K_roadEdgeKFRi, 0, 0)= P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFRi, 0, 0);
         CML_GetMatrixElement(K_roadEdgeKFRi, 0, 1) = P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFRi, 0, 1);
         CML_GetMatrixElement(K_roadEdgeKFRi, 0, 2) = P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFRi, 0, 2);
         CML_GetMatrixElement(K_roadEdgeKFRi, 0, 3) = P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFRi, 0, 3);
      }

      /*HX_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(HX_roadEdgeKFRi, H_roadEdgeKFRi, x_roadEdgeKFRi);
      /*z_roadEdgeKFRi-[HX_roadEdgeKFRi]*/
      CML_v_SubtractMatrices(ZSubHX_roadEdgeKFRi, z_roadEdgeKFRi, HX_roadEdgeKFRi);
      /*K_roadEdgeKFRi[(z_roadEdgeKFRi-HX_roadEdgeKFRi)]*/
      CML_v_MultiplyMatrices(KZSubHX_roadEdgeKFRi, K_roadEdgeKFRi, ZSubHX_roadEdgeKFRi);
      /*x_roadEdgeKFRi=x_roadEdgeKFRi+K_roadEdgeKFRi(z_roadEdgeKFRi-HX_roadEdgeKFRi)*/
      CML_v_AddMatrices(x_roadEdgeKFRi, x_roadEdgeKFRi, KZSubHX_roadEdgeKFRi);
      /*KH_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(KH_roadEdgeKFRi, K_roadEdgeKFRi, H_roadEdgeKFRi);
      /*I_roadEdgeKFRi-[KH_roadEdgeKFRi]*/
      CML_v_SubtractMatrices(ISubKH_roadEdgeKFRi, I_roadEdgeKFRi, KH_roadEdgeKFRi);
      /*P_roadEdgeKFRi=[(I_roadEdgeKFRi-K_roadEdgeKFRi*H_roadEdgeKFRi)]P_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(P_tmp_roadEdgeKFRi, ISubKH_roadEdgeKFRi, P_roadEdgeKFRi);
      CML_v_CopyMatrix(P_roadEdgeKFRi, P_tmp_roadEdgeKFRi);

      measWeight_roadEdgeKFRi = weight;

   }
   else
   {
      reset_roadEdgeKFRi(x_roadEdgeKFRi, P_roadEdgeKFRi);
   }
}
/*****************************************************************************
 Functionname:                                          *//*!

 @brief

 @description

 @param[in]

 @param[in]

 @return

 @author
 **************************************************************************** */
static void predict_roadEdgeKFRi(real32_T dT_roadEdgeKFRi, real32_T dX_roadEdgeKFRi,
         real32_T vehYawRate, CML_t_Matrix* x_roadEdgeKFRi,
         CML_t_Matrix* P_roadEdgeKFRi, real32_T P_ABPREP_RoadKFDynDistYFact_nu,
            real32_T P_ABPREP_RoadKFDynYawFactor_nu, real32_T P_ABPREP_RoadKFDynCrvFactor_nu, real32_T P_ABPREP_RoadKFDynCrvRtFactor_nu)
{
   /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(Q_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(B_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(AX_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(A_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(PA_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(APA_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)

   real32_T dXPow2_roadEdgeKFRi;
   real32_T dXPow3_roadEdgeKFRi;
   real32_T dXPow4_roadEdgeKFRi;
   real32_T dXPow5_roadEdgeKFRi;
   real32_T dXPow6_roadEdgeKFRi;
   real32_T dXPow7_roadEdgeKFRi;
   real32_T dXPow8_roadEdgeKFRi;
   real32_T Q00_roadEdgeKFRi;
   real32_T Q01_roadEdgeKFRi;
   real32_T Q02_roadEdgeKFRi;
   real32_T Q03_roadEdgeKFRi;
   real32_T Q11_roadEdgeKFRi;
   real32_T Q12_roadEdgeKFRi;
   real32_T Q13_roadEdgeKFRi;
   real32_T Q22_roadEdgeKFRi;
   real32_T Q23_roadEdgeKFRi;
   real32_T Q33_roadEdgeKFRi;
   real32_T sigmaSqr_roadEdgeKFRi;

   if (valid_roadEdgeKFRi)
   {
      /*initialize system matrix A_roadEdgeKFRi*/
      CML_v_InitMatrix(A_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF,
               0.0f);
      /*calculate dX_roadEdgeKFRi to the power of 2*/
      dXPow2_roadEdgeKFRi = dX_roadEdgeKFRi * dX_roadEdgeKFRi;
      /*calculate dX_roadEdgeKFRi to the power of 3*/
      dXPow3_roadEdgeKFRi = dXPow2_roadEdgeKFRi * dX_roadEdgeKFRi;
      /*calculate dX_roadEdgeKFRi to the power of 4*/
      dXPow4_roadEdgeKFRi = dXPow3_roadEdgeKFRi * dX_roadEdgeKFRi;
      /*calculate dX_roadEdgeKFRi to the power of 5*/
      dXPow5_roadEdgeKFRi = dXPow4_roadEdgeKFRi * dX_roadEdgeKFRi;
      /*calculate dX_roadEdgeKFRi to the power of 6*/
      dXPow6_roadEdgeKFRi = dXPow5_roadEdgeKFRi * dX_roadEdgeKFRi;
      /*calculate dX_roadEdgeKFRi to the power of 7*/
      dXPow7_roadEdgeKFRi = dXPow6_roadEdgeKFRi * dX_roadEdgeKFRi;
      /*calculate dX_roadEdgeKFRi to the power of 8*/
      dXPow8_roadEdgeKFRi = dXPow7_roadEdgeKFRi * dX_roadEdgeKFRi;

      /*row 0: 1 dX_roadEdgeKFRi 1/2*dX_roadEdgeKFRi^2 1/6*dX_roadEdgeKFRi^3*/
      CML_GetMatrixElement(A_roadEdgeKFRi, 0, 0)= 1.0f;
      CML_GetMatrixElement(A_roadEdgeKFRi, 0, 1)= dX_roadEdgeKFRi;
      CML_GetMatrixElement(A_roadEdgeKFRi, 0, 2)= 0.5f * dXPow2_roadEdgeKFRi;
      CML_GetMatrixElement(A_roadEdgeKFRi, 0, 3)= 1.0f/6.0f * dXPow3_roadEdgeKFRi;
      /*row 1: 0 1 -dX_roadEdgeKFRi - dX_roadEdgeKFRi^2*/
      CML_GetMatrixElement(A_roadEdgeKFRi, 1, 1)= 1.0f;
      CML_GetMatrixElement(A_roadEdgeKFRi, 1, 2)= -dX_roadEdgeKFRi;
      CML_GetMatrixElement(A_roadEdgeKFRi, 1, 3)= -dXPow2_roadEdgeKFRi;
      /*row 2: 0 0 1 dX_roadEdgeKFRi*/
      CML_GetMatrixElement(A_roadEdgeKFRi, 2, 2)= 1.0f;
      CML_GetMatrixElement(A_roadEdgeKFRi, 2, 3)= 0.0f;
      /*row 3: 0 0 0 1*/
      CML_GetMatrixElement(A_roadEdgeKFRi, 3, 3)= 1.0f;

      /*calculate sigma squared*/
      sigmaSqr_roadEdgeKFRi = kappa2diff_sigma_roadEdgeKFRi * kappa2diff_sigma_roadEdgeKFRi;

      /*calculate process noise covariance matrix Q_roadEdgeKFRi elements*/
      Q00_roadEdgeKFRi = dXPow8_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 576.0f;
      Q01_roadEdgeKFRi = -(dXPow7_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi) / 48.0f;
      Q02_roadEdgeKFRi = dXPow6_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 48.0f;
      Q03_roadEdgeKFRi = dXPow5_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 24.0f;

      Q11_roadEdgeKFRi = dXPow6_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 4.0f;
      Q12_roadEdgeKFRi = -dXPow5_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 4.0f;
      Q13_roadEdgeKFRi = -dXPow4_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 2.0f;

      Q22_roadEdgeKFRi = dXPow4_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 4.0f;
      Q23_roadEdgeKFRi = dXPow3_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi / 2.0f;

      Q33_roadEdgeKFRi = dXPow2_roadEdgeKFRi * sigmaSqr_roadEdgeKFRi;

      /*set process noise covariance matrix Q_roadEdgeKFRi row 0*/
      CML_GetMatrixElement(Q_roadEdgeKFRi, 0, 0)= P_ABPREP_RoadKFDynDistYFact_nu * Q00_roadEdgeKFRi; // Factor needed to increase the dynamic of DistY
      CML_GetMatrixElement(Q_roadEdgeKFRi, 0, 1)= Q01_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 0, 2)= Q02_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 0, 3)= Q03_roadEdgeKFRi;
      /*set process noise covariance matrix Q_roadEdgeKFRi row 1*/
      CML_GetMatrixElement(Q_roadEdgeKFRi, 1, 0)= Q01_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 1, 1)= P_ABPREP_RoadKFDynYawFactor_nu * Q11_roadEdgeKFRi; // Factor needed to increase the dynamic of HeadingAngle
      CML_GetMatrixElement(Q_roadEdgeKFRi, 1, 2)= Q12_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 1, 3)= Q13_roadEdgeKFRi;
      /*set process noise covariance matrix Q_roadEdgeKFRi row 2*/
      CML_GetMatrixElement(Q_roadEdgeKFRi, 2, 0)= Q02_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 2, 1)= Q12_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 2, 2)= P_ABPREP_RoadKFDynCrvFactor_nu * Q22_roadEdgeKFRi; // Factor needed to increase the dynamic of Kappa
      CML_GetMatrixElement(Q_roadEdgeKFRi, 2, 3)= Q23_roadEdgeKFRi;
      /*set process noise covariance matrix Q_roadEdgeKFRi row 3*/
      CML_GetMatrixElement(Q_roadEdgeKFRi, 3, 0)= Q03_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 3, 1)= Q13_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 3, 2)= Q23_roadEdgeKFRi;
      CML_GetMatrixElement(Q_roadEdgeKFRi, 3, 3)= P_ABPREP_RoadKFDynCrvRtFactor_nu * Q33_roadEdgeKFRi;

      /*additional noise caused by vehicle movement*/
      CML_GetMatrixElement(Q_roadEdgeKFRi, 0, 0)+= (dT_roadEdgeKFRi * dX_roadEdgeKFRi * vehYawRateStdDev_roadEdgeKFRi) * (dT_roadEdgeKFRi * dX_roadEdgeKFRi * vehYawRateStdDev_roadEdgeKFRi);
      CML_GetMatrixElement(Q_roadEdgeKFRi, 1, 1)+= (dT_roadEdgeKFRi * vehYawRateStdDev_roadEdgeKFRi) * (dT_roadEdgeKFRi * vehYawRateStdDev_roadEdgeKFRi);

      /*initialize steering matrix*/

      CML_v_InitMatrix(B_roadEdgeKFRi, STATE_LENGTH_RoadKF, 1, 0.0f);
      CML_GetMatrixElement(B_roadEdgeKFRi, 0, 0)= dT_roadEdgeKFRi * dX_roadEdgeKFRi;
      CML_GetMatrixElement(B_roadEdgeKFRi, 1, 0)= dT_roadEdgeKFRi;
      /*AX_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(AX_roadEdgeKFRi, A_roadEdgeKFRi, x_roadEdgeKFRi);
      /*Bu*/
      CML_v_ScaleMatrix(B_roadEdgeKFRi, vehYawRate);
      /*x_roadEdgeKFRi = AX_roadEdgeKFRi + Bu*/
      CML_v_AddMatrices(x_roadEdgeKFRi, AX_roadEdgeKFRi, B_roadEdgeKFRi);
      /*A_roadEdgeKFRi'*/
      CML_v_TransposeMatrix(A_trans_roadEdgeKFRi, A_roadEdgeKFRi);
      /*PA'*/
      CML_v_MultiplyMatrices(PA_trans_roadEdgeKFRi, P_roadEdgeKFRi, A_trans_roadEdgeKFRi);
      /*APA'*/
      CML_v_MultiplyMatrices(APA_trans_roadEdgeKFRi, A_roadEdgeKFRi, PA_trans_roadEdgeKFRi);
      /*P_roadEdgeKFRi=APA'+Q_roadEdgeKFRi*/
      CML_v_AddMatrices(P_roadEdgeKFRi, APA_trans_roadEdgeKFRi, Q_roadEdgeKFRi);

      /*Measurement Weight*/
      measWeight_roadEdgeKFRi = 0.0f;
      status_roadEdgeKFRi = 3u;
   }
}
/*****************************************************************************
 Functionname:                                          *//*!

 @brief

 @description

 @param[in]

 @param[in]

 @return

 @author
 **************************************************************************** */
static void init_roadEdgeKFRi(const CML_t_Matrix* z_roadEdgeKFRi, CML_t_Matrix* R_roadEdgeKFRi, real32_T quality, CML_t_Matrix* x_roadEdgeKFRi,CML_t_Matrix* P_roadEdgeKFRi, uint8_T P_ABPREP_RoadKFMnInitQual_perc, real32_T P_ABPREP_RoadKFInitRFactor_nu){
    
    CML_CreateMatrixLocal(H_trans_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
    CML_CreateMatrixLocal(H_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
    CML_CreateMatrixLocal(tmp_roadEdgeKFRi, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
    CML_CreateMatrixLocal(R_scaled_roadEdgeKFRi, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)

   if (quality > P_ABPREP_RoadKFMnInitQual_perc)
   {
      /*scale R_roadEdgeKFRi*/
      CML_v_InitMatrix(R_scaled_roadEdgeKFRi, STATE_LENGTH_RoadKF,
      STATE_LENGTH_RoadKF, 0.0f);
      CML_GetMatrixElement(R_scaled_roadEdgeKFRi, 0, 0)= CML_GetMatrixElement(R_roadEdgeKFRi, 0, 0);
      CML_GetMatrixElement(R_scaled_roadEdgeKFRi, 1, 1)= CML_GetMatrixElement(R_roadEdgeKFRi, 1, 1);
      CML_GetMatrixElement(R_scaled_roadEdgeKFRi, 2, 2)= CML_GetMatrixElement(R_roadEdgeKFRi, 2, 2);
      CML_GetMatrixElement(R_scaled_roadEdgeKFRi, 3, 3)= CML_GetMatrixElement(R_roadEdgeKFRi, 3, 3);
      CML_v_ScaleMatrix(R_scaled_roadEdgeKFRi, P_ABPREP_RoadKFInitRFactor_nu);

      /*initialize matrix H_roadEdgeKFRi*/
      CML_v_CreateIdentityMatrix(H_roadEdgeKFRi, STATE_LENGTH_RoadKF);
      /*initialize matrix H_roadEdgeKFRi'*/
      CML_v_TransposeMatrix(H_trans_roadEdgeKFRi, H_roadEdgeKFRi);
      /*tmp_roadEdgeKFRi = H_roadEdgeKFRi'R_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(tmp_roadEdgeKFRi, H_trans_roadEdgeKFRi, R_scaled_roadEdgeKFRi);
      /*[H_roadEdgeKFRi'R_roadEdgeKFRi]H_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(P_roadEdgeKFRi, tmp_roadEdgeKFRi, H_roadEdgeKFRi);
      /*fill x_roadEdgeKFRi*/
      CML_v_MultiplyMatrices(x_roadEdgeKFRi, H_trans_roadEdgeKFRi, z_roadEdgeKFRi);
      /*fill other states*/
      valid_roadEdgeKFRi = true;
      internalQuality_roadEdgeKFRi = 0.0f;
      measWeight_roadEdgeKFRi = 0.0f;
      status_roadEdgeKFRi = 4u;
   }
}
#endif
