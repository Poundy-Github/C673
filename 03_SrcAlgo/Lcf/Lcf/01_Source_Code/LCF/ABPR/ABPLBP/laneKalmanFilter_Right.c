#ifndef LANE_KALMAN_FILTER_RIGHT_SOURCE
#define LANE_KALMAN_FILTER_RIGHT_SOURCE

/*! \file **********************************************************************

 COMPANY:                   Continental ADAS DF

 CPU:                       CPU-Independent

 COMPONENT:                 LCF (Lateral Control Functions)

 MODULNAME:                 laneKalmanFilter.c

 DESCRIPTION:

 AUTHOR:                    $Author: Handtke-EXT, David (uidq4009) $

 CREATION DATE:             $Date: 2017/05/11 09:43:55CEST $

 VERSION:                   $Revision: 1.1 $

 CHANGES:
 ---*//*---
 CHANGE:                    $Log: laneKalmanFilter_Right.c  $
 CHANGE:                    Revision 1.1 2017/05/11 09:43:55CEST Handtke-EXT, David (uidq4009)
 CHANGE:                    Initial revision
 CHANGE:                    Member added to project /C_ST/CMP/C_A_ABPR/30_Software_Engineering/30_SW_Environment/50_Deliverables/ABPR/ABPLBP/project.pj
 CHANGE:                    Revision 1.1 2017/05/11 09:21:20CEST Handtke-EXT, David (uidq4009)
 CHANGE:                    Initial revision
 CHANGE:                    Member added to project /C_ST/CMP/C_A_ABPR/30_Software_Engineering/30_SW_Environment/20_SourceCode/project.pj
 

 **************************************************************************** */

/*****************************************************************************
 INCLUDES
 ****************************************************************************/
#include "laneKalmanFilter.h"


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
#ifndef STATE_LENGTH_LANEKF
#define STATE_LENGTH_LANEKF (4u)
#endif

/*****************************************************************************
 LOCAL VARIABLES
 *****************************************************************************/
/*state of the KF*/
static uint8_T valid_laneKFRi = 0u;
/*status_laneKFRi of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_laneKFRi = 0u;
/*measurement weight*/
static real32_T measWeight_laneKFRi = 0.0f;
/*internal quality*/
static real32_T internalQuality_laneKFRi = 0.0f;
/*variable for the yaw rate standard deviation - TODO: really needed?*/
static real32_T vehYawRateStdDev_laneKFRi = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_laneKFRi = 0.0f;

/*****************************************************************************
 FUNCTION PROTOTYPES
 *****************************************************************************/
static void reset_laneKFRi(CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi);
static void predict_laneKFRi(real32_T dT_laneKFRi, real32_T dx_laneKFRi, real32_T vehYawRate, CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, real32_T P_ABPLBP_LaneKFDynDistYFact_nu, real32_T P_ABPLBP_LaneKFDynYawFactor_nu);
static void init_laneKFRi(const CML_t_Matrix* z_laneKFRi, CML_t_Matrix* R_laneKFRi, real32_T quality, CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, uint8_T P_ABPLBP_LaneKFMnInitQual_perc, real32_T P_ABPLBP_LaneKFInitRFactor_nu);
static void update_laneKFRi(const CML_t_Matrix* z_laneKFRi, const CML_t_Matrix* R_laneKFRi, real32_T weight, CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, real32_T P_ABPLBP_LaneKFKGainFac_nu);
static void maintenance_laneKFRi(CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, real32_T P_ABPLBP_LaneKFIncQual_1ps, real32_T P_ABPLBP_LaneKFDecQualDeg_1ps, real32_T P_ABPLBP_LaneKFDecQualPred_1ps, real32_T deltaT_sec);

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
void laneKalmanFilter_Right(const laneKFInTypeV3* inputs, laneKFOutType* outputs)
{
   /*state Matrix x_laneKFRi*/
   CML_CreateMatrix(x_laneKFRi, STATE_LENGTH_LANEKF, 1)
   /*covariance matrix P_laneKFRi*/
   CML_CreateMatrix(P_laneKFRi, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   /*measurement matrix z_laneKFRi*/
   CML_CreateMatrix(z_laneKFRi, STATE_LENGTH_LANEKF, 1)
   /*measurement variance matrix R_laneKFRi*/
   CML_CreateMatrix(R_laneKFRi, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)

   real32_T dx_laneKFRi;
   real32_T posY0Diff_laneKFRi;
   /*calculate dx_laneKFRi*/
   dx_laneKFRi = inputs->sf_DeltaT_sec * inputs->sf_VehVelX_mps;
   vehYawRateStdDev_laneKFRi = inputs->sf_VehYawRateStdDev_radps;
   /*geometric dependent model error*/
    if(inputs->sf_LaneKFErrCoeff1_met<1e-5 || inputs->sf_LaneKFErrCoeff2_mps<1e-5||inputs->sf_DeltaT_sec<1e-5){
      kappa2diff_sigma_laneKFRi = 1;
      }
    else{
      kappa2diff_sigma_laneKFRi = 1 / inputs->sf_LaneKFErrCoeff1_met
            / (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec)
            / (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec);
            }

    /*In case of an lane change allow the PosY0 position to jump in the corresponding cycle - only if kalman filter has been valid*/
   if (status_laneKFRi > 0 && status_laneKFRi < 4){
       /*check lane change detection*/
      if(inputs->sf_LaneChange_bool){
          /*a lateral position jump is forced in case of a lane change*/
          CML_GetMatrixElement(x_laneKFRi, 0, 0) = inputs->sf_PosY0_met;
      }
   }

   /*predict_laneKF -  will only be executed if valid_laneKFRi state is set*/
   predict_laneKFRi(inputs->sf_DeltaT_sec, dx_laneKFRi,
            inputs->sf_VehYawRate_radps, x_laneKFRi, P_laneKFRi, inputs->sf_LaneKFDynDistYFact_nu,
            inputs->sf_LaneKFDynYawFactor_nu);

   /*initialize measurement vector z_laneKFRi*/
   CML_GetMatrixElement(z_laneKFRi, 0, 0)= inputs->sf_PosY0_met;
   CML_GetMatrixElement(z_laneKFRi, 1, 0)= inputs->sf_HeadingAngle_rad;
   CML_GetMatrixElement(z_laneKFRi, 2, 0)= inputs->sf_Crv_1pm;
   CML_GetMatrixElement(z_laneKFRi, 3, 0)= inputs->sf_CrvChng_1pm2;

   /*initialize R_laneKFRi matrix*/
   CML_GetMatrixElement(R_laneKFRi, 0, 0)= inputs->sf_PosY0StdDev_met*inputs->sf_PosY0StdDev_met;
   CML_GetMatrixElement(R_laneKFRi, 1, 1)= inputs->sf_HeadingAngleStdDev_rad*inputs->sf_HeadingAngleStdDev_rad;
   CML_GetMatrixElement(R_laneKFRi, 2, 2)= inputs->sf_CrvStdDev_1pm*inputs->sf_CrvStdDev_1pm;
   CML_GetMatrixElement(R_laneKFRi, 3, 3)= inputs->sf_CrvChngStdDev_1pm2*inputs->sf_CrvChngStdDev_1pm2;

   /*Init or Update*/
   if (!valid_laneKFRi && !(inputs->sf_DegradedUpdate_bool))
   {
     /*initialization - for A_laneKF better initialization the R_laneKF matrix is multiplied with A_laneKF constant (>1)*/
      init_laneKFRi(z_laneKFRi, R_laneKFRi, inputs->sf_OverallMeasurementQuality_perc, x_laneKFRi, P_laneKFRi, inputs->sf_LaneKFMnInitQual_perc, inputs->sf_LaneKFInitRFactor_nu);
   }
   /*Update only if valid AND measurement quality > sf_LaneKFMnUpdateQual_perc*/
   else if (valid_laneKFRi  && (inputs->sf_OverallMeasurementQuality_perc >= (inputs->sf_LaneKFMnUpdateQual_perc))){
       if (inputs->sf_DegradedUpdate_bool){
           /*degraded update_laneKFRi - quality and weight are the 2 parameters*/
            update_laneKFRi(z_laneKFRi, R_laneKFRi, inputs->sf_LaneKFDegradeWeight_nu, x_laneKFRi, P_laneKFRi, inputs->sf_LaneKFKGainFac_nu);
      }
      else
      {
         /*full update_laneKFRi*/
         update_laneKFRi(z_laneKFRi, R_laneKFRi, 1.0f, x_laneKFRi, P_laneKFRi, inputs->sf_LaneKFKGainFac_nu);
      }
   }
   /*maintenance_laneKFRi*/
    if(!(status_laneKFRi == 4)){
        maintenance_laneKFRi(x_laneKFRi, P_laneKFRi,inputs->sf_LaneKFIncQual_1ps,
                                    inputs->sf_LaneKFDecQualDeg_1ps, inputs->sf_LaneKFDecQualPred_1ps,
                                        inputs->sf_DeltaT_sec);
    }
   /*Reset filter if basic lane data are not valid*/
   if (!inputs->sf_LaneDataValid_bool)
      reset_laneKFRi(x_laneKFRi, P_laneKFRi);
   /*Set outputs*/
   outputs->sf_PosY0_met = CML_GetMatrixElement(x_laneKFRi, 0, 0);
   outputs->sf_HeadingAngle_rad = CML_GetMatrixElement(x_laneKFRi, 1, 0);
   outputs->sf_Crv_1pm = CML_GetMatrixElement(x_laneKFRi, 2, 0);
   outputs->sf_CrvChng_1pm2 = CML_GetMatrixElement(x_laneKFRi, 3, 0);
   outputs->sf_KFStatus_btf = status_laneKFRi;
   outputs->sf_QualityMeasure_perc = internalQuality_laneKFRi;
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
static void reset_laneKFRi(CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi)
{
   /*reset_laneKFRi parameters*/
   CML_v_InitMatrix(x_laneKFRi, STATE_LENGTH_LANEKF, 1, 0.0f);
   CML_v_InitMatrix(P_laneKFRi, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF, 0.0f);
   valid_laneKFRi = FALSE;
   internalQuality_laneKFRi = 0.0f;
   measWeight_laneKFRi = 0.0f;
   status_laneKFRi = 5u;
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
static void maintenance_laneKFRi(CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, real32_T P_ABPLBP_LaneKFIncQual_1ps, real32_T P_ABPLBP_LaneKFDecQualDeg_1ps, real32_T P_ABPLBP_LaneKFDecQualPred_1ps, real32_T deltaT_sec)
{
   if (valid_laneKFRi)
   {
      /*Full Update, Degraded Update or No Update (predict only)? */
      if (measWeight_laneKFRi > 0.9f)
      {
         /* Full Update */
         status_laneKFRi = 1u;
         /* Increase internal quality by 10% -> 10 cycles are needed to increase the quality from 0% to 100% */
          /* Increase internal quality by P_ABPLBP_LaneKFIncQual_1ps per second*/       
         internalQuality_laneKFRi += P_ABPLBP_LaneKFIncQual_1ps*deltaT_sec;
      }
      else if (measWeight_laneKFRi > 0.0f)
      {
         /* Degraded Update */
         status_laneKFRi = 2u;
         /* Decrease internal quality by P_ABPLBP_LaneKFDecQualDeg_1ps per seconds */
         internalQuality_laneKFRi -= P_ABPLBP_LaneKFDecQualDeg_1ps*deltaT_sec;
      }
      else
      {
         /* No Update - Predict Only */
         status_laneKFRi = 3u;
         /* Decrease internal quality by P_ABPLBP_LaneKFDecQualPred_1ps per seconds */
         internalQuality_laneKFRi -= P_ABPLBP_LaneKFDecQualPred_1ps*deltaT_sec;
      }

      /* Boundary check: 0 <= internalQuality <= 100 */
      if (internalQuality_laneKFRi < 0.0f)
      {
         internalQuality_laneKFRi = 0.0f;
         reset_laneKFRi(x_laneKFRi, P_laneKFRi);
      }
      else if (internalQuality_laneKFRi > 100.0f)
      {
         internalQuality_laneKFRi = 100.0f;
      }

   }
   else
   {
      status_laneKFRi = 0u;
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
static void update_laneKFRi(const CML_t_Matrix* z_laneKFRi, const CML_t_Matrix* R_laneKFRi, real32_T weight, CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, real32_T P_ABPLBP_LaneKFKGainFac_nu){
   
    /*temporary matrices*/
   CML_CreateMatrixLocal(I_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(H_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(H_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(K_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(PH_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_transPlusR_laneKFRi, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_transPlusR_inv_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(Hx_laneKFRi, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(ZSubHx_laneKFRi, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(KZSubHx_laneKFRi, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(KH_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(ISubKH_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(P_tmP_laneKFRi, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)

   /*update_laneKF state with measurement*/
   CML_v_CreateIdentityMatrix(I_laneKF, STATE_LENGTH_LANEKF);
   CML_v_CreateIdentityMatrix(H_laneKF, STATE_LENGTH_LANEKF);
   CML_v_TransposeMatrix(H_trans_laneKF, H_laneKF);
   /*PH'*/
   CML_v_MultiplyMatrices(PH_trans_laneKF, P_laneKFRi, H_trans_laneKF);
   /*H_laneKF[PH']*/
   CML_v_MultiplyMatrices(HPH_trans_laneKF, H_laneKF, PH_trans_laneKF);
   /*[HPH']+R_laneKFRi*/
   CML_v_AddMatrices(HPH_transPlusR_laneKFRi, HPH_trans_laneKF, R_laneKFRi);
   
   /*inv([HPH'+R_laneKFRi]*/
   //CML_v_InvertMatrix(HPH_transPlusR_inv_laneKF, HPH_transPlusR_laneKFRi);
   LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_laneKF, HPH_transPlusR_laneKFRi);
   /*if inversion fails num. of cols and rows are set to 0*/
   if (HPH_transPlusR_inv_laneKF->Desc.col > 0)
   {
      /*K_laneKF=[PH'][inv(HPH'+R_laneKFRi)]*/
      CML_v_MultiplyMatrices(K_laneKF, PH_trans_laneKF,
               HPH_transPlusR_inv_laneKF);
      /*K_laneKF=K_laneKF*weight*/
      CML_v_ScaleMatrix(K_laneKF, weight);

      /* if degradedUpdate == true -> Set first row of K_laneKF to FACTOR*K_laneKF -> weight of Disty = FACTOR*weight */
      if (weight < 1.0f)
      {
         /*set process noise covariance matrix Q_laneKF row 0*/
         CML_GetMatrixElement(K_laneKF, 0, 0)= P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKF, 0, 0);
         CML_GetMatrixElement(K_laneKF, 0, 1) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKF, 0, 1);
         CML_GetMatrixElement(K_laneKF, 0, 2) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKF, 0, 2);
         CML_GetMatrixElement(K_laneKF, 0, 3) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKF, 0, 3);
      }

      /*Hx_laneKFRi*/
      CML_v_MultiplyMatrices(Hx_laneKFRi, H_laneKF, x_laneKFRi);
      /*z_laneKFRi-[Hx_laneKFRi]*/
      CML_v_SubtractMatrices(ZSubHx_laneKFRi, z_laneKFRi, Hx_laneKFRi);
      /*K_laneKF[(z_laneKFRi-Hx_laneKFRi)]*/
      CML_v_MultiplyMatrices(KZSubHx_laneKFRi, K_laneKF, ZSubHx_laneKFRi);
      /*x_laneKFRi=x_laneKFRi+K_laneKF(z_laneKFRi-Hx_laneKFRi)*/
      CML_v_AddMatrices(x_laneKFRi, x_laneKFRi, KZSubHx_laneKFRi);
      /*KH_laneKF*/
      CML_v_MultiplyMatrices(KH_laneKF, K_laneKF, H_laneKF);
      /*I_laneKF-[KH_laneKF]*/
      CML_v_SubtractMatrices(ISubKH_laneKF, I_laneKF, KH_laneKF);
      /*P_laneKFRi=[(I_laneKF-K_laneKF*H_laneKF)]P_laneKFRi*/
      CML_v_MultiplyMatrices(P_tmP_laneKFRi, ISubKH_laneKF, P_laneKFRi);
      CML_v_CopyMatrix(P_laneKFRi, P_tmP_laneKFRi);

      measWeight_laneKFRi = weight;

   }
   else
   {
      reset_laneKFRi(x_laneKFRi, P_laneKFRi);
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
static void predict_laneKFRi(real32_T dT_laneKFRi, real32_T dx_laneKFRi, real32_T vehYawRate, CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, real32_T P_ABPLBP_LaneKFDynDistYFact_nu, real32_T P_ABPLBP_LaneKFDynYawFactor_nu){
    
   /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(Q_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(B_laneKF, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(Ax_laneKFRi, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(A_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(PA_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(APA_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   real32_T dXPow2_laneKF;
   real32_T dXPow3_laneKF;
   real32_T dXPow4_laneKF;
   real32_T dXPow5_laneKF;
   real32_T dXPow6_laneKF;
   real32_T dXPow7_laneKF;
   real32_T dXPow8_laneKF;
   real32_T Q00_laneKF;
   real32_T Q01_laneKF;
   real32_T Q02_laneKF;
   real32_T Q03_laneKF;
   real32_T Q11_laneKF;
   real32_T Q12_laneKF;
   real32_T Q13_laneKF;
   real32_T Q22_laneKF;
   real32_T Q23_laneKF;
   real32_T Q33_laneKF;
   real32_T sigmaSqR_laneKFRi;

   if (valid_laneKFRi)
   {

      /*initialize system matrix A_laneKF*/
      CML_v_InitMatrix(A_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF,
               0.0f);
      /*calculate dx_laneKFRi to the power of 2*/
      dXPow2_laneKF = dx_laneKFRi * dx_laneKFRi;
      /*calculate dx_laneKFRi to the power of 3*/
      dXPow3_laneKF = dXPow2_laneKF * dx_laneKFRi;
      /*calculate dx_laneKFRi to the power of 4*/
      dXPow4_laneKF = dXPow3_laneKF * dx_laneKFRi;
      /*calculate dx_laneKFRi to the power of 5*/
      dXPow5_laneKF = dXPow4_laneKF * dx_laneKFRi;
      /*calculate dx_laneKFRi to the power of 6*/
      dXPow6_laneKF = dXPow5_laneKF * dx_laneKFRi;
      /*calculate dx_laneKFRi to the power of 7*/
      dXPow7_laneKF = dXPow6_laneKF * dx_laneKFRi;
      /*calculate dx_laneKFRi to the power of 8*/
      dXPow8_laneKF = dXPow7_laneKF * dx_laneKFRi;

      /*row 0: 1 dx_laneKFRi 1/2*dx_laneKFRi^2 1/6*dx_laneKFRi^3*/
      CML_GetMatrixElement(A_laneKF, 0, 0)= 1.0f;
      CML_GetMatrixElement(A_laneKF, 0, 1)= dx_laneKFRi;
      CML_GetMatrixElement(A_laneKF, 0, 2)= 0.5f * dXPow2_laneKF;
      CML_GetMatrixElement(A_laneKF, 0, 3)= 1.0f/6.0f * dXPow3_laneKF;
      /*row 1: 0 1 -dx_laneKFRi - dx_laneKFRi^2*/
      CML_GetMatrixElement(A_laneKF, 1, 1)= 1.0f;
      CML_GetMatrixElement(A_laneKF, 1, 2)= -dx_laneKFRi;
      CML_GetMatrixElement(A_laneKF, 1, 3)= -dXPow2_laneKF;
      /*row 2: 0 0 1 dx_laneKFRi*/
      CML_GetMatrixElement(A_laneKF, 2, 2)= 1.0f;
      CML_GetMatrixElement(A_laneKF, 2, 3)= dx_laneKFRi;
      /*row 3: 0 0 0 1*/
      CML_GetMatrixElement(A_laneKF, 3, 3)= 1.0f;

      /*calculate sigma squared*/
      sigmaSqR_laneKFRi = kappa2diff_sigma_laneKFRi * kappa2diff_sigma_laneKFRi;

      /*calculate process noise covariance matrix Q_laneKF elements*/
      Q00_laneKF = dXPow8_laneKF * sigmaSqR_laneKFRi / 576.0f;
      Q01_laneKF = -(dXPow7_laneKF * sigmaSqR_laneKFRi) / 48.0f;
      Q02_laneKF = dXPow6_laneKF * sigmaSqR_laneKFRi / 48.0f;
      Q03_laneKF = dXPow5_laneKF * sigmaSqR_laneKFRi / 24.0f;

      Q11_laneKF = dXPow6_laneKF * sigmaSqR_laneKFRi / 4.0f;
      Q12_laneKF = -dXPow5_laneKF * sigmaSqR_laneKFRi / 4.0f;
      Q13_laneKF = -dXPow4_laneKF * sigmaSqR_laneKFRi / 2.0f;

      Q22_laneKF = dXPow4_laneKF * sigmaSqR_laneKFRi / 4.0f;
      Q23_laneKF = dXPow3_laneKF * sigmaSqR_laneKFRi / 2.0f;

      Q33_laneKF = dXPow2_laneKF * sigmaSqR_laneKFRi;

      /*set process noise covariance matrix Q_laneKF row 0*/
      CML_GetMatrixElement(Q_laneKF, 0, 0)= P_ABPLBP_LaneKFDynDistYFact_nu * Q00_laneKF; // Factor needed to increase the dynamic of DistY
      CML_GetMatrixElement(Q_laneKF, 0, 1)= Q01_laneKF;
      CML_GetMatrixElement(Q_laneKF, 0, 2)= Q02_laneKF;
      CML_GetMatrixElement(Q_laneKF, 0, 3)= Q03_laneKF;
      /*set process noise covariance matrix Q_laneKF row 1*/
      CML_GetMatrixElement(Q_laneKF, 1, 0)= Q01_laneKF;
      CML_GetMatrixElement(Q_laneKF, 1, 1)= P_ABPLBP_LaneKFDynYawFactor_nu * Q11_laneKF; // Factor needed to increase the dynamic of HeadingAngle
      CML_GetMatrixElement(Q_laneKF, 1, 2)= Q12_laneKF;
      CML_GetMatrixElement(Q_laneKF, 1, 3)= Q13_laneKF;
      /*set process noise covariance matrix Q_laneKF row 2*/
      CML_GetMatrixElement(Q_laneKF, 2, 0)= Q02_laneKF;
      CML_GetMatrixElement(Q_laneKF, 2, 1)= Q12_laneKF;
      CML_GetMatrixElement(Q_laneKF, 2, 2)= 100.0f * Q22_laneKF; // Factor needed to increase the dynamic of Kappa
      CML_GetMatrixElement(Q_laneKF, 2, 3)= Q23_laneKF;
      /*set process noise covariance matrix Q_laneKF row 3*/
      CML_GetMatrixElement(Q_laneKF, 3, 0)= Q03_laneKF;
      CML_GetMatrixElement(Q_laneKF, 3, 1)= Q13_laneKF;
      CML_GetMatrixElement(Q_laneKF, 3, 2)= Q23_laneKF;
      CML_GetMatrixElement(Q_laneKF, 3, 3)= 2.0f * Q33_laneKF;

      /*additional noise caused by vehicle movement*/
      CML_GetMatrixElement(Q_laneKF, 0, 0)+= (dT_laneKFRi * dx_laneKFRi * vehYawRateStdDev_laneKFRi) * (dT_laneKFRi * dx_laneKFRi * vehYawRateStdDev_laneKFRi);
      CML_GetMatrixElement(Q_laneKF, 1, 1)+= (dT_laneKFRi * vehYawRateStdDev_laneKFRi) * (dT_laneKFRi * vehYawRateStdDev_laneKFRi);

      /*initialize steering matrix*/

      CML_v_InitMatrix(B_laneKF, STATE_LENGTH_LANEKF, 1, 0.0f);
      CML_GetMatrixElement(B_laneKF, 0, 0)= dT_laneKFRi * dx_laneKFRi;
      CML_GetMatrixElement(B_laneKF, 1, 0)= dT_laneKFRi;
      /*Ax_laneKFRi*/
      CML_v_MultiplyMatrices(Ax_laneKFRi, A_laneKF, x_laneKFRi);
      /*Bu*/
      CML_v_ScaleMatrix(B_laneKF, vehYawRate);
      /*x_laneKFRi = Ax_laneKFRi + Bu*/
      CML_v_AddMatrices(x_laneKFRi, Ax_laneKFRi, B_laneKF);
      /*A_laneKF'*/
      CML_v_TransposeMatrix(A_trans_laneKF, A_laneKF);
      /*PA'*/
      CML_v_MultiplyMatrices(PA_trans_laneKF, P_laneKFRi, A_trans_laneKF);
      /*APA'*/
      CML_v_MultiplyMatrices(APA_trans_laneKF, A_laneKF, PA_trans_laneKF);
      /*P_laneKFRi=APA'+Q_laneKF*/
      CML_v_AddMatrices(P_laneKFRi, APA_trans_laneKF, Q_laneKF);

      /*Measurement Weight*/
      measWeight_laneKFRi = 0.0f;
      status_laneKFRi = 3u;
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
static void init_laneKFRi(const CML_t_Matrix* z_laneKFRi, CML_t_Matrix* R_laneKFRi, real32_T quality, CML_t_Matrix* x_laneKFRi, CML_t_Matrix* P_laneKFRi, uint8_T P_ABPLBP_LaneKFMnInitQual_perc, real32_T P_ABPLBP_LaneKFInitRFactor_nu){
    CML_CreateMatrixLocal(H_trans_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(H_laneKF, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(tmP_laneKFRi, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(R_scaled_laneKF, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   if (quality > P_ABPLBP_LaneKFMnInitQual_perc){

       /*scale R_laneKFRi*/
      CML_v_InitMatrix(R_scaled_laneKF, STATE_LENGTH_LANEKF,
      STATE_LENGTH_LANEKF, 0.0f);
      CML_GetMatrixElement(R_scaled_laneKF, 0, 0)= CML_GetMatrixElement(R_laneKFRi, 0, 0);
      CML_GetMatrixElement(R_scaled_laneKF, 1, 1)= CML_GetMatrixElement(R_laneKFRi, 1, 1);
      CML_GetMatrixElement(R_scaled_laneKF, 2, 2)= CML_GetMatrixElement(R_laneKFRi, 2, 2);
      CML_GetMatrixElement(R_scaled_laneKF, 3, 3)= CML_GetMatrixElement(R_laneKFRi, 3, 3);
      CML_v_ScaleMatrix(R_scaled_laneKF, P_ABPLBP_LaneKFInitRFactor_nu);

      /*initialize matrix H_laneKF*/
      CML_v_CreateIdentityMatrix(H_laneKF, STATE_LENGTH_LANEKF);
      /*initialize matrix H_laneKF'*/
      CML_v_TransposeMatrix(H_trans_laneKF, H_laneKF);
      /*tmP_laneKFRi = H_laneKF'R_laneKFRi*/
      CML_v_MultiplyMatrices(tmP_laneKFRi, H_trans_laneKF, R_scaled_laneKF);
      /*[H_laneKF'R_laneKFRi]H_laneKF*/
      CML_v_MultiplyMatrices(P_laneKFRi, tmP_laneKFRi, H_laneKF);
      /*fill x_laneKFRi*/
      CML_v_MultiplyMatrices(x_laneKFRi, H_trans_laneKF, z_laneKFRi);
      /*fill other states*/
      valid_laneKFRi = true;
      internalQuality_laneKFRi = 0.0f;
      measWeight_laneKFRi = 0.0f;
      status_laneKFRi = 4u;
   }
}
#endif
