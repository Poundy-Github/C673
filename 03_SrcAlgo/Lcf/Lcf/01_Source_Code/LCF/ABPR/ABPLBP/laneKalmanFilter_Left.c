#ifndef LANE_KALMAN_FILTER_LEFT_SOURCE
#define LANE_KALMAN_FILTER_LEFT_SOURCE

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
 CHANGE:                    $Log: laneKalmanFilter_Left.c  $
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
static uint8_T valid_laneKFLe = 0u;
/*status_laneKFLe of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_laneKFLe = 0u;
/*measurement weight*/
static real32_T measWeight_laneKFLe = 0.0f;
/*internal quality*/
static real32_T internalQuality_laneKFLe = 0.0f;
/*variable for the yaw rate standard deviation - TODO: really needed?*/
static real32_T vehYawRateStdDev_laneKFLe = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_laneKFLe = 0.0f;

/*****************************************************************************
 FUNCTION PROTOTYPES
 *****************************************************************************/
static void reset_laneKFLe(CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe);
static void predict_laneKFLe(real32_T dT_laneKFLe, real32_T dX_laneKFLe,
         real32_T vehYawRate, CML_t_Matrix* x_laneKFLe,
         CML_t_Matrix* P_laneKFLe, real32_T P_ABPLBP_LaneKFDynDistYFact_nu,
            real32_T P_ABPLBP_LaneKFDynYawFactor_nu);
static void init_laneKFLe(const CML_t_Matrix* z_laneKFLe, CML_t_Matrix* R_laneKFLe, real32_T quality, CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe, uint8_T P_ABPLBP_LaneKFMnInitQual_perc, real32_T P_ABPLBP_LaneKFInitRFactor_nu);
static void update_laneKFLe(const CML_t_Matrix* z_laneKFLe,
         const CML_t_Matrix* R_laneKFLe, real32_T weight,
         CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe, real32_T P_ABPLBP_LaneKFKGainFac_nu);
static void maintenance_laneKFLe(CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe, real32_T P_ABPLBP_LaneKFIncQual_1ps,
                                    real32_T P_ABPLBP_LaneKFDecQualDeg_1ps, real32_T P_ABPLBP_LaneKFDecQualPred_1ps,
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
void laneKalmanFilter_Left(const laneKFInTypeV3* inputs, laneKFOutType* outputs)
{
   /*state Matrix x_laneKFLe*/
   CML_CreateMatrix(x_laneKFLe, STATE_LENGTH_LANEKF, 1)
   /*covariance matrix P_laneKFLe*/
   CML_CreateMatrix(P_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   /*measurement matrix z_laneKFLe*/
   CML_CreateMatrix(z_laneKFLe, STATE_LENGTH_LANEKF, 1)
   /*measurement variance matrix R_laneKFLe*/
   CML_CreateMatrix(R_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)

   real32_T dX_laneKFLe;
   real32_T PosY0Diff_laneKFLe;
   /*calculate dX_laneKFLe*/
   dX_laneKFLe = inputs->sf_DeltaT_sec * inputs->sf_VehVelX_mps;
   vehYawRateStdDev_laneKFLe = inputs->sf_VehYawRateStdDev_radps;
   /*geometric dependent model error*/
    if(inputs->sf_LaneKFErrCoeff1_met<1e-5 || inputs->sf_LaneKFErrCoeff2_mps<1e-5||inputs->sf_DeltaT_sec<1e-5){
       kappa2diff_sigma_laneKFLe = 1;
       }
     else{
      kappa2diff_sigma_laneKFLe = 1 / inputs->sf_LaneKFErrCoeff1_met
            / (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec)
            / (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec);
            }

   /*In case of an lane change allow the PosY0 position to jump in the corresponding cycle - only if kalman filter has been valid*/
   if (status_laneKFLe > 0 && status_laneKFLe < 4){
       /*check lane change detection*/
      if(inputs->sf_LaneChange_bool){
          /*a lateral position jump is forced in case of a lane change*/
          CML_GetMatrixElement(x_laneKFLe, 0, 0) = inputs->sf_PosY0_met;
      }
   }

   /*predict_laneKFLe -  will only be executed if valid_laneKFLe state is set*/
   predict_laneKFLe(inputs->sf_DeltaT_sec, dX_laneKFLe,
            inputs->sf_VehYawRate_radps, x_laneKFLe, P_laneKFLe, inputs->sf_LaneKFDynDistYFact_nu,
            inputs->sf_LaneKFDynYawFactor_nu);

   /*initialize measurement vector z_laneKFLe*/
   CML_GetMatrixElement(z_laneKFLe, 0, 0)= inputs->sf_PosY0_met;
   CML_GetMatrixElement(z_laneKFLe, 1, 0)= inputs->sf_HeadingAngle_rad;
   CML_GetMatrixElement(z_laneKFLe, 2, 0)= inputs->sf_Crv_1pm;
   CML_GetMatrixElement(z_laneKFLe, 3, 0)= inputs->sf_CrvChng_1pm2;

   /*initialize R_laneKFLe matrix*/
   CML_GetMatrixElement(R_laneKFLe, 0, 0)= inputs->sf_PosY0StdDev_met*inputs->sf_PosY0StdDev_met;
   CML_GetMatrixElement(R_laneKFLe, 1, 1)= inputs->sf_HeadingAngleStdDev_rad*inputs->sf_HeadingAngleStdDev_rad;
   CML_GetMatrixElement(R_laneKFLe, 2, 2)= inputs->sf_CrvStdDev_1pm*inputs->sf_CrvStdDev_1pm;
   CML_GetMatrixElement(R_laneKFLe, 3, 3)= inputs->sf_CrvChngStdDev_1pm2*inputs->sf_CrvChngStdDev_1pm2;

   /*Init or Update*/
   if (!valid_laneKFLe && !(inputs->sf_DegradedUpdate_bool))
   {
      /*initialization - for A_laneKFLe better initialization the R_laneKFLe matrix is multiplied with A_laneKFLe constant (>1)*/
      init_laneKFLe(z_laneKFLe, R_laneKFLe, inputs->sf_OverallMeasurementQuality_perc, x_laneKFLe, P_laneKFLe, inputs->sf_LaneKFMnInitQual_perc, inputs->sf_LaneKFInitRFactor_nu);
   }
   /*Update only if valid AND measurement quality > sf_LaneKFMnUpdateQual_perc*/
   else if (valid_laneKFLe  && (inputs->sf_OverallMeasurementQuality_perc >= (inputs->sf_LaneKFMnUpdateQual_perc))){
       if (inputs->sf_DegradedUpdate_bool){
           /*degraded update_laneKFLe - quality and weight are the 2 parameters*/
            update_laneKFLe(z_laneKFLe, R_laneKFLe, inputs->sf_LaneKFDegradeWeight_nu, x_laneKFLe, P_laneKFLe, inputs->sf_LaneKFKGainFac_nu);
      }
      else
      {
         /*full update_laneKFLe*/
         update_laneKFLe(z_laneKFLe, R_laneKFLe, 1.0f, x_laneKFLe, P_laneKFLe, inputs->sf_LaneKFKGainFac_nu);
      }
   }
   /*maintenance_laneKFLe*/
    if(!(status_laneKFLe == 4)){
        maintenance_laneKFLe(x_laneKFLe, P_laneKFLe,inputs->sf_LaneKFIncQual_1ps,
                                    inputs->sf_LaneKFDecQualDeg_1ps, inputs->sf_LaneKFDecQualPred_1ps,
                                        inputs->sf_DeltaT_sec);
    }
   /*Reset filter if basic lane data are not valid*/
   if (!inputs->sf_LaneDataValid_bool)
      reset_laneKFLe(x_laneKFLe, P_laneKFLe);
   /*Set outputs*/
   outputs->sf_PosY0_met = CML_GetMatrixElement(x_laneKFLe, 0, 0);
   outputs->sf_HeadingAngle_rad = CML_GetMatrixElement(x_laneKFLe, 1, 0);
   outputs->sf_Crv_1pm = CML_GetMatrixElement(x_laneKFLe, 2, 0);
   outputs->sf_CrvChng_1pm2 = CML_GetMatrixElement(x_laneKFLe, 3, 0);
   outputs->sf_KFStatus_btf = status_laneKFLe;
   outputs->sf_QualityMeasure_perc = internalQuality_laneKFLe;
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
static void reset_laneKFLe(CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe)
{
   /*reset_laneKFLe parameters*/
   CML_v_InitMatrix(x_laneKFLe, STATE_LENGTH_LANEKF, 1, 0.0f);
   CML_v_InitMatrix(P_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF, 0.0f);
   valid_laneKFLe = FALSE;
   internalQuality_laneKFLe = 0.0f;
   measWeight_laneKFLe = 0.0f;
   status_laneKFLe = 5u;
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
static void maintenance_laneKFLe(CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe, real32_T P_ABPLBP_LaneKFIncQual_1ps,
                                    real32_T P_ABPLBP_LaneKFDecQualDeg_1ps, real32_T P_ABPLBP_LaneKFDecQualPred_1ps,
                                        real32_T deltaT_sec)
{
   if (valid_laneKFLe)
   {
      /*Full Update, Degraded Update or No Update (predict only)? */
      if (measWeight_laneKFLe > 0.9f)
      {
         /* Full Update */
         status_laneKFLe = 1u;
         /* Increase internal quality by P_ABPLBP_LaneKFIncQual_1ps per second*/       
         internalQuality_laneKFLe += P_ABPLBP_LaneKFIncQual_1ps*deltaT_sec;
      }
      else if (measWeight_laneKFLe > 0.0f)
      {
         /* Degraded Update */
         status_laneKFLe = 2u;
         /* Decrease internal quality by P_ABPLBP_LaneKFDecQualDeg_1ps per seconds */
         internalQuality_laneKFLe -= P_ABPLBP_LaneKFDecQualDeg_1ps*deltaT_sec;
      }
      else
      {
         /* No Update - Predict Only */
         status_laneKFLe = 3u;
         /* Decrease internal quality by P_ABPLBP_LaneKFDecQualPred_1ps per seconds */
         internalQuality_laneKFLe -= P_ABPLBP_LaneKFDecQualPred_1ps*deltaT_sec;
      }

      /* Boundary check: 0 <= internalQuality <= 100 */
      if (internalQuality_laneKFLe < 0.0f)
      {
         internalQuality_laneKFLe = 0.0f;
         reset_laneKFLe(x_laneKFLe, P_laneKFLe);
      }
      else if (internalQuality_laneKFLe > 100.0f)
      {
         internalQuality_laneKFLe = 100.0f;
      }

   }
   else
   {
      status_laneKFLe = 0u;
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
static void update_laneKFLe(const CML_t_Matrix* z_laneKFLe,
         const CML_t_Matrix* R_laneKFLe, real32_T weight,
         CML_t_Matrix* x_laneKFLe, CML_t_Matrix* P_laneKFLe, real32_T P_ABPLBP_LaneKFKGainFac_nu)
{
   /*temporary matrices*/
   CML_CreateMatrixLocal(I_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(H_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(H_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(K_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(PH_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_transPlusR_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_transPlusR_inv_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HX_laneKFLe, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(ZSubHX_laneKFLe, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(KZSubHX_laneKFLe, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(KH_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(ISubKH_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(P_tmp_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   /*update_laneKFLe state with measurement*/
   CML_v_CreateIdentityMatrix(I_laneKFLe, STATE_LENGTH_LANEKF);
   CML_v_CreateIdentityMatrix(H_laneKFLe, STATE_LENGTH_LANEKF);
   CML_v_TransposeMatrix(H_trans_laneKFLe, H_laneKFLe);
   /*PH'*/
   CML_v_MultiplyMatrices(PH_trans_laneKFLe, P_laneKFLe, H_trans_laneKFLe);
   /*H_laneKFLe[PH']*/
   CML_v_MultiplyMatrices(HPH_trans_laneKFLe, H_laneKFLe, PH_trans_laneKFLe);
   /*[HPH']+R_laneKFLe*/
   CML_v_AddMatrices(HPH_transPlusR_laneKFLe, HPH_trans_laneKFLe, R_laneKFLe);
   /*inv([HPH'+R_laneKFLe]*/
   //CML_v_InvertMatrix(HPH_transPlusR_inv_laneKFLe, HPH_transPlusR_laneKFLe);
   LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_laneKFLe, HPH_transPlusR_laneKFLe);
   /*if inversion fails num. of cols and rows are set to 0*/
   if (HPH_transPlusR_inv_laneKFLe->Desc.col > 0)
   {
      /*K_laneKFLe=[PH'][inv(HPH'+R_laneKFLe)]*/
      CML_v_MultiplyMatrices(K_laneKFLe, PH_trans_laneKFLe,
               HPH_transPlusR_inv_laneKFLe);
      /*K_laneKFLe=K_laneKFLe*weight*/
      CML_v_ScaleMatrix(K_laneKFLe, weight);

      /* if degradedUpdate == true -> Set first row of K_laneKFLe to FACTOR*K_laneKFLe -> weight of Disty = FACTOR*weight */
      if (weight < 1.0f)
      {
         /*set process noise covariance matrix Q_laneKFLe row 0*/
         CML_GetMatrixElement(K_laneKFLe, 0, 0)= P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFLe, 0, 0);
         CML_GetMatrixElement(K_laneKFLe, 0, 1) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFLe, 0, 1);
         CML_GetMatrixElement(K_laneKFLe, 0, 2) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFLe, 0, 2);
         CML_GetMatrixElement(K_laneKFLe, 0, 3) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFLe, 0, 3);
      }

      /*HX_laneKFLe*/
      CML_v_MultiplyMatrices(HX_laneKFLe, H_laneKFLe, x_laneKFLe);
      /*z_laneKFLe-[HX_laneKFLe]*/
      CML_v_SubtractMatrices(ZSubHX_laneKFLe, z_laneKFLe, HX_laneKFLe);
      /*K_laneKFLe[(z_laneKFLe-HX_laneKFLe)]*/
      CML_v_MultiplyMatrices(KZSubHX_laneKFLe, K_laneKFLe, ZSubHX_laneKFLe);
      /*x_laneKFLe=x_laneKFLe+K_laneKFLe(z_laneKFLe-HX_laneKFLe)*/
      CML_v_AddMatrices(x_laneKFLe, x_laneKFLe, KZSubHX_laneKFLe);
      /*KH_laneKFLe*/
      CML_v_MultiplyMatrices(KH_laneKFLe, K_laneKFLe, H_laneKFLe);
      /*I_laneKFLe-[KH_laneKFLe]*/
      CML_v_SubtractMatrices(ISubKH_laneKFLe, I_laneKFLe, KH_laneKFLe);
      /*P_laneKFLe=[(I_laneKFLe-K_laneKFLe*H_laneKFLe)]P_laneKFLe*/
      CML_v_MultiplyMatrices(P_tmp_laneKFLe, ISubKH_laneKFLe, P_laneKFLe);
      CML_v_CopyMatrix(P_laneKFLe, P_tmp_laneKFLe);

      measWeight_laneKFLe = weight;

   }
   else
   {
      reset_laneKFLe(x_laneKFLe, P_laneKFLe);
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
static void predict_laneKFLe(real32_T dT_laneKFLe, real32_T dX_laneKFLe,
         real32_T vehYawRate, CML_t_Matrix* x_laneKFLe,
         CML_t_Matrix* P_laneKFLe, real32_T P_ABPLBP_LaneKFDynDistYFact_nu,
            real32_T P_ABPLBP_LaneKFDynYawFactor_nu)
{
   /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(Q_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(B_laneKFLe, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(AX_laneKFLe, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(A_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(PA_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(APA_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   real32_T dXPow2_laneKFLe;
   real32_T dXPow3_laneKFLe;
   real32_T dXPow4_laneKFLe;
   real32_T dXPow5_laneKFLe;
   real32_T dXPow6_laneKFLe;
   real32_T dXPow7_laneKFLe;
   real32_T dXPow8_laneKFLe;
   real32_T Q00_laneKFLe;
   real32_T Q01_laneKFLe;
   real32_T Q02_laneKFLe;
   real32_T Q03_laneKFLe;
   real32_T Q11_laneKFLe;
   real32_T Q12_laneKFLe;
   real32_T Q13_laneKFLe;
   real32_T Q22_laneKFLe;
   real32_T Q23_laneKFLe;
   real32_T Q33_laneKFLe;
   real32_T sigmaSqr_laneKFLe;

   if (valid_laneKFLe)
   {

      /*initialize system matrix A_laneKFLe*/
      CML_v_InitMatrix(A_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF,
               0.0f);
      /*calculate dX_laneKFLe to the power of 2*/
      dXPow2_laneKFLe = dX_laneKFLe * dX_laneKFLe;
      /*calculate dX_laneKFLe to the power of 3*/
      dXPow3_laneKFLe = dXPow2_laneKFLe * dX_laneKFLe;
      /*calculate dX_laneKFLe to the power of 4*/
      dXPow4_laneKFLe = dXPow3_laneKFLe * dX_laneKFLe;
      /*calculate dX_laneKFLe to the power of 5*/
      dXPow5_laneKFLe = dXPow4_laneKFLe * dX_laneKFLe;
      /*calculate dX_laneKFLe to the power of 6*/
      dXPow6_laneKFLe = dXPow5_laneKFLe * dX_laneKFLe;
      /*calculate dX_laneKFLe to the power of 7*/
      dXPow7_laneKFLe = dXPow6_laneKFLe * dX_laneKFLe;
      /*calculate dX_laneKFLe to the power of 8*/
      dXPow8_laneKFLe = dXPow7_laneKFLe * dX_laneKFLe;

      /*row 0: 1 dX_laneKFLe 1/2*dX_laneKFLe^2 1/6*dX_laneKFLe^3*/
      CML_GetMatrixElement(A_laneKFLe, 0, 0)= 1.0f;
      CML_GetMatrixElement(A_laneKFLe, 0, 1)= -dX_laneKFLe;
      CML_GetMatrixElement(A_laneKFLe, 0, 2)= -0.5f * dXPow2_laneKFLe;
      CML_GetMatrixElement(A_laneKFLe, 0, 3)= -1.0f/6.0f * dXPow3_laneKFLe;
      /*row 1: 0 1 -dX_laneKFLe - dX_laneKFLe^2*/
      CML_GetMatrixElement(A_laneKFLe, 1, 1)= 1.0f;
      CML_GetMatrixElement(A_laneKFLe, 1, 2)= -dX_laneKFLe;
      CML_GetMatrixElement(A_laneKFLe, 1, 3)= -dXPow2_laneKFLe;
      /*row 2: 0 0 1 dX_laneKFLe*/
      CML_GetMatrixElement(A_laneKFLe, 2, 2)= 1.0f;
      CML_GetMatrixElement(A_laneKFLe, 2, 3)= dX_laneKFLe;
      /*row 3: 0 0 0 1*/
      CML_GetMatrixElement(A_laneKFLe, 3, 3)= 1.0f;

      /*calculate sigma squared*/
      sigmaSqr_laneKFLe = kappa2diff_sigma_laneKFLe * kappa2diff_sigma_laneKFLe;

      /*calculate process noise covariance matrix Q_laneKFLe elements*/
      Q00_laneKFLe = dXPow8_laneKFLe * sigmaSqr_laneKFLe / 576.0f;
      Q01_laneKFLe = dXPow7_laneKFLe * sigmaSqr_laneKFLe / 48.0f;
      Q02_laneKFLe = -dXPow6_laneKFLe * sigmaSqr_laneKFLe / 48.0f;
      Q03_laneKFLe = -dXPow5_laneKFLe * sigmaSqr_laneKFLe / 24.0f;

      Q11_laneKFLe = dXPow6_laneKFLe * sigmaSqr_laneKFLe / 4.0f;
      Q12_laneKFLe = -dXPow5_laneKFLe * sigmaSqr_laneKFLe / 4.0f;
      Q13_laneKFLe = -dXPow4_laneKFLe * sigmaSqr_laneKFLe / 2.0f;

      Q22_laneKFLe = dXPow4_laneKFLe * sigmaSqr_laneKFLe / 4.0f;
      Q23_laneKFLe = dXPow3_laneKFLe * sigmaSqr_laneKFLe / 2.0f;

      Q33_laneKFLe = dXPow2_laneKFLe * sigmaSqr_laneKFLe;

      /*set process noise covariance matrix Q_laneKFLe row 0*/
      CML_GetMatrixElement(Q_laneKFLe, 0, 0)= P_ABPLBP_LaneKFDynDistYFact_nu * Q00_laneKFLe; // Factor needed to increase the dynamic of DistY
      CML_GetMatrixElement(Q_laneKFLe, 0, 1)= Q01_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 0, 2)= Q02_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 0, 3)= Q03_laneKFLe;
      /*set process noise covariance matrix Q_laneKFLe row 1*/
      CML_GetMatrixElement(Q_laneKFLe, 1, 0)= Q01_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 1, 1)= P_ABPLBP_LaneKFDynYawFactor_nu * Q11_laneKFLe; // Factor needed to increase the dynamic of HeadingAngle
      CML_GetMatrixElement(Q_laneKFLe, 1, 2)= Q12_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 1, 3)= Q13_laneKFLe;
      /*set process noise covariance matrix Q_laneKFLe row 2*/
      CML_GetMatrixElement(Q_laneKFLe, 2, 0)= Q02_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 2, 1)= Q12_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 2, 2)= 100.0f * Q22_laneKFLe; // Factor needed to increase the dynamic of Kappa
      CML_GetMatrixElement(Q_laneKFLe, 2, 3)= Q23_laneKFLe;
      /*set process noise covariance matrix Q_laneKFLe row 3*/
      CML_GetMatrixElement(Q_laneKFLe, 3, 0)= Q03_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 3, 1)= Q13_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 3, 2)= Q23_laneKFLe;
      CML_GetMatrixElement(Q_laneKFLe, 3, 3)= 2.0f * Q33_laneKFLe;

      /*additional noise caused by vehicle movement*/
      CML_GetMatrixElement(Q_laneKFLe, 0, 0)+= (dT_laneKFLe * dX_laneKFLe * vehYawRateStdDev_laneKFLe) * (dT_laneKFLe * dX_laneKFLe * vehYawRateStdDev_laneKFLe);
      CML_GetMatrixElement(Q_laneKFLe, 1, 1)+= (dT_laneKFLe * vehYawRateStdDev_laneKFLe) * (dT_laneKFLe * vehYawRateStdDev_laneKFLe);

      /*initialize steering matrix*/

      CML_v_InitMatrix(B_laneKFLe, STATE_LENGTH_LANEKF, 1, 0.0f);
      CML_GetMatrixElement(B_laneKFLe, 0, 0)= -dT_laneKFLe * dX_laneKFLe;
      CML_GetMatrixElement(B_laneKFLe, 1, 0)= dT_laneKFLe;
      /*AX_laneKFLe*/
      CML_v_MultiplyMatrices(AX_laneKFLe, A_laneKFLe, x_laneKFLe);
      /*Bu*/
      CML_v_ScaleMatrix(B_laneKFLe, vehYawRate);
      /*x_laneKFLe = AX_laneKFLe + Bu*/
      CML_v_AddMatrices(x_laneKFLe, AX_laneKFLe, B_laneKFLe);
      /*A_laneKFLe'*/
      CML_v_TransposeMatrix(A_trans_laneKFLe, A_laneKFLe);
      /*PA'*/
      CML_v_MultiplyMatrices(PA_trans_laneKFLe, P_laneKFLe, A_trans_laneKFLe);
      /*APA'*/
      CML_v_MultiplyMatrices(APA_trans_laneKFLe, A_laneKFLe, PA_trans_laneKFLe);
      /*P_laneKFLe=APA'+Q_laneKFLe*/
      CML_v_AddMatrices(P_laneKFLe, APA_trans_laneKFLe, Q_laneKFLe);

      /*Measurement Weight*/
      measWeight_laneKFLe = 0.0f;
      status_laneKFLe = 3u;
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
static void init_laneKFLe(const CML_t_Matrix* z_laneKFLe, CML_t_Matrix* R_laneKFLe, real32_T quality, CML_t_Matrix* x_laneKFLe,CML_t_Matrix* P_laneKFLe, uint8_T P_ABPLBP_LaneKFMnInitQual_perc, real32_T P_ABPLBP_LaneKFInitRFactor_nu){
    
    CML_CreateMatrixLocal(H_trans_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(H_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(tmp_laneKFLe, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(R_scaled_laneKFLe, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   if (quality > P_ABPLBP_LaneKFMnInitQual_perc)
   {
      /*scale R_laneKFLe*/
      CML_v_InitMatrix(R_scaled_laneKFLe, STATE_LENGTH_LANEKF,
      STATE_LENGTH_LANEKF, 0.0f);
      CML_GetMatrixElement(R_scaled_laneKFLe, 0, 0)= CML_GetMatrixElement(R_laneKFLe, 0, 0);
      CML_GetMatrixElement(R_scaled_laneKFLe, 1, 1)= CML_GetMatrixElement(R_laneKFLe, 1, 1);
      CML_GetMatrixElement(R_scaled_laneKFLe, 2, 2)= CML_GetMatrixElement(R_laneKFLe, 2, 2);
      CML_GetMatrixElement(R_scaled_laneKFLe, 3, 3)= CML_GetMatrixElement(R_laneKFLe, 3, 3);
      CML_v_ScaleMatrix(R_scaled_laneKFLe, P_ABPLBP_LaneKFInitRFactor_nu);

      /*initialize matrix H_laneKFLe*/
      CML_v_CreateIdentityMatrix(H_laneKFLe, STATE_LENGTH_LANEKF);
      /*initialize matrix H_laneKFLe'*/
      CML_v_TransposeMatrix(H_trans_laneKFLe, H_laneKFLe);
      /*tmp_laneKFLe = H_laneKFLe'R_laneKFLe*/
      CML_v_MultiplyMatrices(tmp_laneKFLe, H_trans_laneKFLe, R_scaled_laneKFLe);
      /*[H_laneKFLe'R_laneKFLe]H_laneKFLe*/
      CML_v_MultiplyMatrices(P_laneKFLe, tmp_laneKFLe, H_laneKFLe);
      /*fill x_laneKFLe*/
      CML_v_MultiplyMatrices(x_laneKFLe, H_trans_laneKFLe, z_laneKFLe);
      /*fill other states*/
      valid_laneKFLe = true;
      internalQuality_laneKFLe = 0.0f;
      measWeight_laneKFLe = 0.0f;
      status_laneKFLe = 4u;
   }
}
#endif
