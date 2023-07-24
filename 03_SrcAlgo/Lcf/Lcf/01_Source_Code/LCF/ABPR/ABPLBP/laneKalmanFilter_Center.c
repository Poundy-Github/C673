#ifndef LANE_KALMAN_FILTER_CENTER_SOURCE
#define LANE_KALMAN_FILTER_CENTER_SOURCE

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
 CHANGE:                    $Log: laneKalmanFilter_Center.c  $
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
static uint8_T valid_laneKFCntr = 0u;
/*status_laneKFCntr of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_laneKFCntr = 0u;
/*measurement weight*/
static real32_T measWeight_laneKFCntr = 0.0f;
/*internal quality*/
static real32_T internalQuality_laneKFCntr = 0.0f;
/*variable for the yaw rate standard deviation - TODO: really needed?*/
static real32_T vehYawRateStdDev_laneKFCntr = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_laneKFCntr = 0.0f;

/*****************************************************************************
 FUNCTION PROTOTYPES
 *****************************************************************************/
static void reset_laneKFCntr(CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr);
static void predict_laneKFCntr(real32_T dT_laneKFCntr, real32_T dX_laneKFCntr,
         real32_T vehYawRate, CML_t_Matrix* x_laneKFCntr,
         CML_t_Matrix* P_laneKFCntr, real32_T P_ABPLBP_LaneKFDynDistYFact_nu,
            real32_T P_ABPLBP_LaneKFDynYawFactor_nu,real32_T P_ABPLBP_LaneKFDynCrvFactor_nu, real32_T P_ABPLBP_LaneKFDynCrvRtFactor_nu);
static void init_laneKFCntr(const CML_t_Matrix* z_laneKFCntr, CML_t_Matrix* R_laneKFCntr, real32_T quality, CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr, uint8_T P_ABPLBP_LaneKFMnInitQual_perc, real32_T P_ABPLBP_LaneKFInitRFactor_nu);
static void update_laneKFCntr(const CML_t_Matrix* z_laneKFCntr,
         const CML_t_Matrix* R_laneKFCntr, real32_T weight,
         CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr, real32_T P_ABPLBP_LaneKFKGainFac_nu);
static void maintenance_laneKFCntr(CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr, real32_T P_ABPLBP_LaneKFIncQual_1ps,
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
void laneKalmanFilter_Center(const laneKFInTypeV3* inputs, laneKFOutType* outputs)
{
   /*state Matrix x_laneKFCntr*/
   CML_CreateMatrix(x_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   /*covariance matrix P_laneKFCntr*/
   CML_CreateMatrix(P_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   /*measurement matrix z_laneKFCntr*/
   CML_CreateMatrix(z_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   /*measurement variance matrix R_laneKFCntr*/
   CML_CreateMatrix(R_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)

   real32_T dX_laneKFCntr;
   real32_T PosY0Diff_laneKFCntr;
   /*calculate dX_laneKFCntr*/
   dX_laneKFCntr = inputs->sf_DeltaT_sec * inputs->sf_VehVelX_mps;
   vehYawRateStdDev_laneKFCntr = inputs->sf_VehYawRateStdDev_radps;
   /*geometric dependent model error*/
   if(inputs->sf_LaneKFErrCoeff1_met<1e-5 || inputs->sf_LaneKFErrCoeff2_mps<1e-5||inputs->sf_DeltaT_sec<1e-5){
    kappa2diff_sigma_laneKFCntr = 1;
      }
    else{
      kappa2diff_sigma_laneKFCntr = 1 / inputs->sf_LaneKFErrCoeff1_met
            / (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec)
            / (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec);
              }

   /*In case of an lane change allow the PosY0 position to jump in the corresponding cycle - only if kalman filter has been valid*/
   if (status_laneKFCntr > 0 && status_laneKFCntr < 4){
       /*check lane change detection*/
      if(inputs->sf_LaneChange_bool){
          /*a lateral position jump is forced in case of a lane change*/
          CML_GetMatrixElement(x_laneKFCntr, 0, 0) = inputs->sf_PosY0_met;
      }
   }

   /*predict_laneKFCntr -  will only be executed if valid_laneKFCntr state is set*/
   predict_laneKFCntr(inputs->sf_DeltaT_sec, dX_laneKFCntr,
            inputs->sf_VehYawRate_radps, x_laneKFCntr, P_laneKFCntr, inputs->sf_LaneKFDynDistYFact_nu,
            inputs->sf_LaneKFDynYawFactor_nu, inputs->sf_LaneKFDynCrvFact_nu, inputs->sf_LaneKFDynCrvRateFact_nu);

   /*initialize measurement vector z_laneKFCntr*/
   CML_GetMatrixElement(z_laneKFCntr, 0, 0)= inputs->sf_PosY0_met;
   CML_GetMatrixElement(z_laneKFCntr, 1, 0)= inputs->sf_HeadingAngle_rad;
   CML_GetMatrixElement(z_laneKFCntr, 2, 0)= inputs->sf_Crv_1pm;
   CML_GetMatrixElement(z_laneKFCntr, 3, 0)= inputs->sf_CrvChng_1pm2;

   /*initialize R_laneKFCntr matrix*/
   CML_GetMatrixElement(R_laneKFCntr, 0, 0)= inputs->sf_PosY0StdDev_met*inputs->sf_PosY0StdDev_met;
   CML_GetMatrixElement(R_laneKFCntr, 1, 1)= inputs->sf_HeadingAngleStdDev_rad*inputs->sf_HeadingAngleStdDev_rad;
   CML_GetMatrixElement(R_laneKFCntr, 2, 2)= inputs->sf_CrvStdDev_1pm*inputs->sf_CrvStdDev_1pm;
   CML_GetMatrixElement(R_laneKFCntr, 3, 3)= inputs->sf_CrvChngStdDev_1pm2*inputs->sf_CrvChngStdDev_1pm2;

   /*Init or Update*/
   if (!valid_laneKFCntr && !(inputs->sf_DegradedUpdate_bool))
   {
      /*initialization - for A_laneKFCntr better initialization the R_laneKFCntr matrix is multiplied with A_laneKFCntr constant (>1)*/
      init_laneKFCntr(z_laneKFCntr, R_laneKFCntr, inputs->sf_OverallMeasurementQuality_perc, x_laneKFCntr, P_laneKFCntr, inputs->sf_LaneKFMnInitQual_perc, inputs->sf_LaneKFInitRFactor_nu);
   }
   /*Update only if valid AND measurement quality > sf_LaneKFMnUpdateQual_perc*/
   else if (valid_laneKFCntr  && (inputs->sf_OverallMeasurementQuality_perc >= (inputs->sf_LaneKFMnUpdateQual_perc))){
       if (inputs->sf_DegradedUpdate_bool){
           /*degraded update_laneKFCntr - quality and weight are the 2 parameters*/
            update_laneKFCntr(z_laneKFCntr, R_laneKFCntr, inputs->sf_LaneKFDegradeWeight_nu, x_laneKFCntr, P_laneKFCntr, inputs->sf_LaneKFKGainFac_nu);
      }
      else
      {
         /*full update_laneKFCntr*/
         update_laneKFCntr(z_laneKFCntr, R_laneKFCntr, 1.0f, x_laneKFCntr, P_laneKFCntr, inputs->sf_LaneKFKGainFac_nu);
      }
   }
   /*maintenance_laneKFCntr*/
    if(!(status_laneKFCntr == 4)){
        maintenance_laneKFCntr(x_laneKFCntr, P_laneKFCntr,inputs->sf_LaneKFIncQual_1ps,
                                    inputs->sf_LaneKFDecQualDeg_1ps, inputs->sf_LaneKFDecQualPred_1ps,
                                        inputs->sf_DeltaT_sec);
    }
   /*Reset filter if basic lane data are not valid*/
   if (!inputs->sf_LaneDataValid_bool)
      reset_laneKFCntr(x_laneKFCntr, P_laneKFCntr);
   /*Set outputs*/
   outputs->sf_PosY0_met = CML_GetMatrixElement(x_laneKFCntr, 0, 0);
   outputs->sf_HeadingAngle_rad = CML_GetMatrixElement(x_laneKFCntr, 1, 0);
   outputs->sf_Crv_1pm = CML_GetMatrixElement(x_laneKFCntr, 2, 0);
   outputs->sf_CrvChng_1pm2 = CML_GetMatrixElement(x_laneKFCntr, 3, 0);
   outputs->sf_KFStatus_btf = status_laneKFCntr;
   outputs->sf_QualityMeasure_perc = internalQuality_laneKFCntr;
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
static void reset_laneKFCntr(CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr)
{
   /*reset_laneKFCntr parameters*/
   CML_v_InitMatrix(x_laneKFCntr, STATE_LENGTH_LANEKF, 1, 0.0f);
   CML_v_InitMatrix(P_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF, 0.0f);
   valid_laneKFCntr = FALSE;
   internalQuality_laneKFCntr = 0.0f;
   measWeight_laneKFCntr = 0.0f;
   status_laneKFCntr = 5u;
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
static void maintenance_laneKFCntr(CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr, real32_T P_ABPLBP_LaneKFIncQual_1ps,
                                    real32_T P_ABPLBP_LaneKFDecQualDeg_1ps, real32_T P_ABPLBP_LaneKFDecQualPred_1ps,
                                        real32_T deltaT_sec)
{
   if (valid_laneKFCntr)
   {
      /*Full Update, Degraded Update or No Update (predict only)? */
      if (measWeight_laneKFCntr > 0.9f)
      {
         /* Full Update */
         status_laneKFCntr = 1u;
         /* Increase internal quality by P_ABPLBP_LaneKFIncQual_1ps per second*/       
         internalQuality_laneKFCntr += P_ABPLBP_LaneKFIncQual_1ps*deltaT_sec;
      }
      else if (measWeight_laneKFCntr > 0.0f)
      {
         /* Degraded Update */
         status_laneKFCntr = 2u;
         /* Decrease internal quality by P_ABPLBP_LaneKFDecQualDeg_1ps per seconds */
         internalQuality_laneKFCntr -= P_ABPLBP_LaneKFDecQualDeg_1ps*deltaT_sec;
      }
      else
      {
         /* No Update - Predict Only */
         status_laneKFCntr = 3u;
         /* Decrease internal quality by P_ABPLBP_LaneKFDecQualPred_1ps per seconds */
         internalQuality_laneKFCntr -= P_ABPLBP_LaneKFDecQualPred_1ps*deltaT_sec;
      }

      /* Boundary check: 0 <= internalQuality <= 100 */
      if (internalQuality_laneKFCntr < 0.0f)
      {
         internalQuality_laneKFCntr = 0.0f;
         reset_laneKFCntr(x_laneKFCntr, P_laneKFCntr);
      }
      else if (internalQuality_laneKFCntr > 100.0f)
      {
         internalQuality_laneKFCntr = 100.0f;
      }

   }
   else
   {
      status_laneKFCntr = 0u;
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
static void update_laneKFCntr(const CML_t_Matrix* z_laneKFCntr,
         const CML_t_Matrix* R_laneKFCntr, real32_T weight,
         CML_t_Matrix* x_laneKFCntr, CML_t_Matrix* P_laneKFCntr, real32_T P_ABPLBP_LaneKFKGainFac_nu)
{
   /*temporary matrices*/
   CML_CreateMatrixLocal(I_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(H_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(H_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(K_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(PH_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_transPlusR_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HPH_transPlusR_inv_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(HX_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(ZSubHX_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(KZSubHX_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(KH_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(ISubKH_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(P_tmp_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   /*update_laneKFCntr state with measurement*/
   CML_v_CreateIdentityMatrix(I_laneKFCntr, STATE_LENGTH_LANEKF);
   CML_v_CreateIdentityMatrix(H_laneKFCntr, STATE_LENGTH_LANEKF);
   CML_v_TransposeMatrix(H_trans_laneKFCntr, H_laneKFCntr);
   /*PH'*/
   CML_v_MultiplyMatrices(PH_trans_laneKFCntr, P_laneKFCntr, H_trans_laneKFCntr);
   /*H_laneKFCntr[PH']*/
   CML_v_MultiplyMatrices(HPH_trans_laneKFCntr, H_laneKFCntr, PH_trans_laneKFCntr);
   /*[HPH']+R_laneKFCntr*/
   CML_v_AddMatrices(HPH_transPlusR_laneKFCntr, HPH_trans_laneKFCntr, R_laneKFCntr);
   /*inv([HPH'+R_laneKFCntr]*/
   //CML_v_InvertMatrix(HPH_transPlusR_inv_laneKFCntr, HPH_transPlusR_laneKFCntr);
   LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_laneKFCntr, HPH_transPlusR_laneKFCntr);
   /*if inversion fails num. of cols and rows are set to 0*/
   if (HPH_transPlusR_inv_laneKFCntr->Desc.col > 0)
   {
      /*K_laneKFCntr=[PH'][inv(HPH'+R_laneKFCntr)]*/
      CML_v_MultiplyMatrices(K_laneKFCntr, PH_trans_laneKFCntr,
               HPH_transPlusR_inv_laneKFCntr);
      /*K_laneKFCntr=K_laneKFCntr*weight*/
      CML_v_ScaleMatrix(K_laneKFCntr, weight);

      /* if degradedUpdate == true -> Set first row of K_laneKFCntr to FACTOR*K_laneKFCntr -> weight of Disty = FACTOR*weight */
      if (weight < 1.0f)
      {
         /*set process noise covariance matrix Q_laneKFCntr row 0*/
         CML_GetMatrixElement(K_laneKFCntr, 0, 0)= P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFCntr, 0, 0);
         CML_GetMatrixElement(K_laneKFCntr, 0, 1) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFCntr, 0, 1);
         CML_GetMatrixElement(K_laneKFCntr, 0, 2) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFCntr, 0, 2);
         CML_GetMatrixElement(K_laneKFCntr, 0, 3) = P_ABPLBP_LaneKFKGainFac_nu * CML_GetMatrixElement(K_laneKFCntr, 0, 3);
      }

      /*HX_laneKFCntr*/
      CML_v_MultiplyMatrices(HX_laneKFCntr, H_laneKFCntr, x_laneKFCntr);
      /*z_laneKFCntr-[HX_laneKFCntr]*/
      CML_v_SubtractMatrices(ZSubHX_laneKFCntr, z_laneKFCntr, HX_laneKFCntr);
      /*K_laneKFCntr[(z_laneKFCntr-HX_laneKFCntr)]*/
      CML_v_MultiplyMatrices(KZSubHX_laneKFCntr, K_laneKFCntr, ZSubHX_laneKFCntr);
      /*x_laneKFCntr=x_laneKFCntr+K_laneKFCntr(z_laneKFCntr-HX_laneKFCntr)*/
      CML_v_AddMatrices(x_laneKFCntr, x_laneKFCntr, KZSubHX_laneKFCntr);
      /*KH_laneKFCntr*/
      CML_v_MultiplyMatrices(KH_laneKFCntr, K_laneKFCntr, H_laneKFCntr);
      /*I_laneKFCntr-[KH_laneKFCntr]*/
      CML_v_SubtractMatrices(ISubKH_laneKFCntr, I_laneKFCntr, KH_laneKFCntr);
      /*P_laneKFCntr=[(I_laneKFCntr-K_laneKFCntr*H_laneKFCntr)]P_laneKFCntr*/
      CML_v_MultiplyMatrices(P_tmp_laneKFCntr, ISubKH_laneKFCntr, P_laneKFCntr);
      CML_v_CopyMatrix(P_laneKFCntr, P_tmp_laneKFCntr);

      measWeight_laneKFCntr = weight;

   }
   else
   {
      reset_laneKFCntr(x_laneKFCntr, P_laneKFCntr);
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
static void predict_laneKFCntr(real32_T dT_laneKFCntr, real32_T dX_laneKFCntr,
         real32_T vehYawRate, CML_t_Matrix* x_laneKFCntr,
         CML_t_Matrix* P_laneKFCntr, real32_T P_ABPLBP_LaneKFDynDistYFact_nu,
            real32_T P_ABPLBP_LaneKFDynYawFactor_nu, real32_T P_ABPLBP_LaneKFDynCrvFactor_nu, real32_T P_ABPLBP_LaneKFDynCrvRtFactor_nu)
{
   /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(Q_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(B_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(AX_laneKFCntr, STATE_LENGTH_LANEKF, 1)
   CML_CreateMatrixLocal(A_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(PA_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
   CML_CreateMatrixLocal(APA_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   real32_T dXPow2_laneKFCntr;
   real32_T dXPow3_laneKFCntr;
   real32_T dXPow4_laneKFCntr;
   real32_T dXPow5_laneKFCntr;
   real32_T dXPow6_laneKFCntr;
   real32_T dXPow7_laneKFCntr;
   real32_T dXPow8_laneKFCntr;
   real32_T Q00_laneKFCntr;
   real32_T Q01_laneKFCntr;
   real32_T Q02_laneKFCntr;
   real32_T Q03_laneKFCntr;
   real32_T Q11_laneKFCntr;
   real32_T Q12_laneKFCntr;
   real32_T Q13_laneKFCntr;
   real32_T Q22_laneKFCntr;
   real32_T Q23_laneKFCntr;
   real32_T Q33_laneKFCntr;
   real32_T sigmaSqr_laneKFCntr;

   if (valid_laneKFCntr)
   {
      /*initialize system matrix A_laneKFCntr*/
      CML_v_InitMatrix(A_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF,
               0.0f);
      /*calculate dX_laneKFCntr to the power of 2*/
      dXPow2_laneKFCntr = dX_laneKFCntr * dX_laneKFCntr;
      /*calculate dX_laneKFCntr to the power of 3*/
      dXPow3_laneKFCntr = dXPow2_laneKFCntr * dX_laneKFCntr;
      /*calculate dX_laneKFCntr to the power of 4*/
      dXPow4_laneKFCntr = dXPow3_laneKFCntr * dX_laneKFCntr;
      /*calculate dX_laneKFCntr to the power of 5*/
      dXPow5_laneKFCntr = dXPow4_laneKFCntr * dX_laneKFCntr;
      /*calculate dX_laneKFCntr to the power of 6*/
      dXPow6_laneKFCntr = dXPow5_laneKFCntr * dX_laneKFCntr;
      /*calculate dX_laneKFCntr to the power of 7*/
      dXPow7_laneKFCntr = dXPow6_laneKFCntr * dX_laneKFCntr;
      /*calculate dX_laneKFCntr to the power of 8*/
      dXPow8_laneKFCntr = dXPow7_laneKFCntr * dX_laneKFCntr;

      /*row 0: 1 dX_laneKFCntr 1/2*dX_laneKFCntr^2 1/6*dX_laneKFCntr^3*/
      CML_GetMatrixElement(A_laneKFCntr, 0, 0)= 1.0f;
      CML_GetMatrixElement(A_laneKFCntr, 0, 1)= -dX_laneKFCntr;
      CML_GetMatrixElement(A_laneKFCntr, 0, 2)= -0.5f * dXPow2_laneKFCntr;
      CML_GetMatrixElement(A_laneKFCntr, 0, 3)= -1.0f/6.0f * dXPow3_laneKFCntr;
      /*row 1: 0 1 -dX_laneKFCntr - dX_laneKFCntr^2*/
      CML_GetMatrixElement(A_laneKFCntr, 1, 1)= 1.0f;
      CML_GetMatrixElement(A_laneKFCntr, 1, 2)= -dX_laneKFCntr;
      CML_GetMatrixElement(A_laneKFCntr, 1, 3)= -dXPow2_laneKFCntr;
      /*row 2: 0 0 1 dX_laneKFCntr*/
      CML_GetMatrixElement(A_laneKFCntr, 2, 2)= 1.0f;
      CML_GetMatrixElement(A_laneKFCntr, 2, 3)= 0.0f;
      /*row 3: 0 0 0 1*/
      CML_GetMatrixElement(A_laneKFCntr, 3, 3)= 1.0f;

      /*calculate sigma squared*/
      sigmaSqr_laneKFCntr = kappa2diff_sigma_laneKFCntr * kappa2diff_sigma_laneKFCntr;

      /*calculate process noise covariance matrix Q_laneKFCntr elements*/
      Q00_laneKFCntr = dXPow8_laneKFCntr * sigmaSqr_laneKFCntr / 576.0f;
      Q01_laneKFCntr = dXPow7_laneKFCntr * sigmaSqr_laneKFCntr / 48.0f;
      Q02_laneKFCntr = -dXPow6_laneKFCntr * sigmaSqr_laneKFCntr / 48.0f;
      Q03_laneKFCntr = -dXPow5_laneKFCntr * sigmaSqr_laneKFCntr / 24.0f;

      Q11_laneKFCntr = dXPow6_laneKFCntr * sigmaSqr_laneKFCntr / 4.0f;
      Q12_laneKFCntr = -dXPow5_laneKFCntr * sigmaSqr_laneKFCntr / 4.0f;
      Q13_laneKFCntr = -dXPow4_laneKFCntr * sigmaSqr_laneKFCntr / 2.0f;

      Q22_laneKFCntr = dXPow4_laneKFCntr * sigmaSqr_laneKFCntr / 4.0f;
      Q23_laneKFCntr = dXPow3_laneKFCntr * sigmaSqr_laneKFCntr / 2.0f;

      Q33_laneKFCntr = dXPow2_laneKFCntr * sigmaSqr_laneKFCntr;

      /*set process noise covariance matrix Q_laneKFCntr row 0*/
      CML_GetMatrixElement(Q_laneKFCntr, 0, 0)= P_ABPLBP_LaneKFDynDistYFact_nu * Q00_laneKFCntr; // Factor needed to increase the dynamic of DistY
      CML_GetMatrixElement(Q_laneKFCntr, 0, 1)= Q01_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 0, 2)= Q02_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 0, 3)= Q03_laneKFCntr;
      /*set process noise covariance matrix Q_laneKFCntr row 1*/
      CML_GetMatrixElement(Q_laneKFCntr, 1, 0)= Q01_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 1, 1)= P_ABPLBP_LaneKFDynYawFactor_nu * Q11_laneKFCntr; // Factor needed to increase the dynamic of HeadingAngle
      CML_GetMatrixElement(Q_laneKFCntr, 1, 2)= Q12_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 1, 3)= Q13_laneKFCntr;
      /*set process noise covariance matrix Q_laneKFCntr row 2*/
      CML_GetMatrixElement(Q_laneKFCntr, 2, 0)= Q02_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 2, 1)= Q12_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 2, 2)= P_ABPLBP_LaneKFDynCrvFactor_nu * Q22_laneKFCntr; // Factor needed to increase the dynamic of Kappa
      CML_GetMatrixElement(Q_laneKFCntr, 2, 3)= Q23_laneKFCntr;
      /*set process noise covariance matrix Q_laneKFCntr row 3*/
      CML_GetMatrixElement(Q_laneKFCntr, 3, 0)= Q03_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 3, 1)= Q13_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 3, 2)= Q23_laneKFCntr;
      CML_GetMatrixElement(Q_laneKFCntr, 3, 3)= P_ABPLBP_LaneKFDynCrvRtFactor_nu * Q33_laneKFCntr;

      /*additional noise caused by vehicle movement*/
      CML_GetMatrixElement(Q_laneKFCntr, 0, 0)+= (dT_laneKFCntr * dX_laneKFCntr * vehYawRateStdDev_laneKFCntr) * (dT_laneKFCntr * dX_laneKFCntr * vehYawRateStdDev_laneKFCntr);
      CML_GetMatrixElement(Q_laneKFCntr, 1, 1)+= (dT_laneKFCntr * vehYawRateStdDev_laneKFCntr) * (dT_laneKFCntr * vehYawRateStdDev_laneKFCntr);

      /*initialize steering matrix*/

      CML_v_InitMatrix(B_laneKFCntr, STATE_LENGTH_LANEKF, 1, 0.0f);
      CML_GetMatrixElement(B_laneKFCntr, 0, 0)= -dT_laneKFCntr * dX_laneKFCntr;
      CML_GetMatrixElement(B_laneKFCntr, 1, 0)= dT_laneKFCntr;
      /*AX_laneKFCntr*/
      CML_v_MultiplyMatrices(AX_laneKFCntr, A_laneKFCntr, x_laneKFCntr);
      /*Bu*/
      CML_v_ScaleMatrix(B_laneKFCntr, vehYawRate);
      /*x_laneKFCntr = AX_laneKFCntr + Bu*/
      CML_v_AddMatrices(x_laneKFCntr, AX_laneKFCntr, B_laneKFCntr);
      /*A_laneKFCntr'*/
      CML_v_TransposeMatrix(A_trans_laneKFCntr, A_laneKFCntr);
      /*PA'*/
      CML_v_MultiplyMatrices(PA_trans_laneKFCntr, P_laneKFCntr, A_trans_laneKFCntr);
      /*APA'*/
      CML_v_MultiplyMatrices(APA_trans_laneKFCntr, A_laneKFCntr, PA_trans_laneKFCntr);
      /*P_laneKFCntr=APA'+Q_laneKFCntr*/
      CML_v_AddMatrices(P_laneKFCntr, APA_trans_laneKFCntr, Q_laneKFCntr);

      /*Measurement Weight*/
      measWeight_laneKFCntr = 0.0f;
      status_laneKFCntr = 3u;
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
static void init_laneKFCntr(const CML_t_Matrix* z_laneKFCntr, CML_t_Matrix* R_laneKFCntr, real32_T quality, CML_t_Matrix* x_laneKFCntr,CML_t_Matrix* P_laneKFCntr, uint8_T P_ABPLBP_LaneKFMnInitQual_perc, real32_T P_ABPLBP_LaneKFInitRFactor_nu){
    
    CML_CreateMatrixLocal(H_trans_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(H_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(tmp_laneKFCntr, STATE_LENGTH_LANEKF, STATE_LENGTH_LANEKF)
    CML_CreateMatrixLocal(R_scaled_laneKFCntr, STATE_LENGTH_LANEKF,
            STATE_LENGTH_LANEKF)

   if (quality > P_ABPLBP_LaneKFMnInitQual_perc)
   {
      /*scale R_laneKFCntr*/
      CML_v_InitMatrix(R_scaled_laneKFCntr, STATE_LENGTH_LANEKF,
      STATE_LENGTH_LANEKF, 0.0f);
      CML_GetMatrixElement(R_scaled_laneKFCntr, 0, 0)= CML_GetMatrixElement(R_laneKFCntr, 0, 0);
      CML_GetMatrixElement(R_scaled_laneKFCntr, 1, 1)= CML_GetMatrixElement(R_laneKFCntr, 1, 1);
      CML_GetMatrixElement(R_scaled_laneKFCntr, 2, 2)= CML_GetMatrixElement(R_laneKFCntr, 2, 2);
      CML_GetMatrixElement(R_scaled_laneKFCntr, 3, 3)= CML_GetMatrixElement(R_laneKFCntr, 3, 3);
      CML_v_ScaleMatrix(R_scaled_laneKFCntr, P_ABPLBP_LaneKFInitRFactor_nu);

      /*initialize matrix H_laneKFCntr*/
      CML_v_CreateIdentityMatrix(H_laneKFCntr, STATE_LENGTH_LANEKF);
      /*initialize matrix H_laneKFCntr'*/
      CML_v_TransposeMatrix(H_trans_laneKFCntr, H_laneKFCntr);
      /*tmp_laneKFCntr = H_laneKFCntr'R_laneKFCntr*/
      CML_v_MultiplyMatrices(tmp_laneKFCntr, H_trans_laneKFCntr, R_scaled_laneKFCntr);
      /*[H_laneKFCntr'R_laneKFCntr]H_laneKFCntr*/
      CML_v_MultiplyMatrices(P_laneKFCntr, tmp_laneKFCntr, H_laneKFCntr);
      /*fill x_laneKFCntr*/
      CML_v_MultiplyMatrices(x_laneKFCntr, H_trans_laneKFCntr, z_laneKFCntr);
      /*fill other states*/
      valid_laneKFCntr = true;
      internalQuality_laneKFCntr = 0.0f;
      measWeight_laneKFCntr = 0.0f;
      status_laneKFCntr = 4u;
   }
}
#endif
