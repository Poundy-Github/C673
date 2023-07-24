/*! \file **********************************************************************

 COMPANY:                   Continental ADAS DF

 CPU:                       CPU-Independent

 COMPONENT:                 LCF (Lateral Control Functions)

 MODULNAME:                 objTraceKalmanFilter.c

 DESCRIPTION:

 AUTHOR:                    $Author: Nastasa, Elena (uidt4846) $

 CREATION DATE:             $Date: 2019/07/03 13:52:52CEST $

 VERSION:                   $Revision: 1.2 $

 CHANGES:
 ---*//*---
 CHANGE:                    $Log: objTraceKalmanFilter.c  $
 CHANGE:                    Revision 1.2 2019/07/03 13:52:52CEST Nastasa, Elena (uidt4846) 
 CHANGE:                    Update for sprint 05.10.03
 CHANGE:                    Revision 1.1 2019/03/31 23:02:26CEST Asong, Wedndah Asaha (uidj2187) 
 CHANGE:                    Initial revision
 CHANGE:                    Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/ODPR/ODPFOH/project.pj
 

 **************************************************************************** */

/*****************************************************************************
 INCLUDES
 ****************************************************************************/
#include "objTraceKalmanFilter.h"

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

/*length of the KF state vector*/
#ifndef POLY_ORDER_2ND
#define POLY_ORDER_2ND (3u)
#endif

/*****************************************************************************
 LOCAL VARIABLES
 *****************************************************************************/
/*state of the KF*/
static uint8_T valid_objKF = 0u;
/*status_objKF of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_objKF = 0u;
/*measurement weight*/
static real32_T measWeight_objKF = 0.0f;
/*internal quality*/
static real32_T internalQuality_objKF = 0.0f;
/*variable for the yaw rate standard deviation - TODO: really needed?*/
static real32_T vehYawRateStdDev_objKF = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_objKF = 0.0f;

/*****************************************************************************
 FUNCTION PROTOTYPES
 *****************************************************************************/
static void reset_objKF(CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF);
static void predict_objKF(real32_T dT_objKF, real32_T dX_objKF, real32_T vehYawRate, CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, real32_T P_ODPFOH_ObjKFDynDistYFact_nu, real32_T P_ODPFOH_ObjKFDynYawFactor_nu,real32_T P_ODPFOH_ObjKFDynCrvFactor_nu);
static void init_objKF(const CML_t_Matrix* z_objKF, CML_t_Matrix* R_objKF, real32_T quality, CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, uint8_T P_ODPFOH_ObjKFMnInitQual_perc, real32_T P_ODPFOH_ObjKFInitRFactor_nu);
static void update_objKF(const CML_t_Matrix* z_objKF, const CML_t_Matrix* R_objKF, real32_T weight, CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, real32_T P_ODPFOH_ObjKFKGainFac_nu);
static void maintenance_objKF(CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, real32_T P_ODPFOH_ObjKFIncQual_1ps, real32_T P_ODPFOH_ObjKFDecQualDeg_1ps, real32_T P_ODPFOH_ObjKFDecQualPred_1ps, real32_T deltaT_sec);

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
void objTraceKalmanFilter(const TgtObjectTraceKF_Input* input, TgtObjectTraceKF_Output* output)
{
   /*state Matrix x_objKF*/
   CML_CreateMatrix(x_objKF, POLY_ORDER_2ND, 1)
   /*covariance matrix P_objKF*/
   CML_CreateMatrix(P_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   /*measurement matrix z_objKF*/
   CML_CreateMatrix(z_objKF, POLY_ORDER_2ND, 1)
   /*measurement variance matrix R_objKF*/
   CML_CreateMatrix(R_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)

   real32_T dX_objKF;
   //real32_T PosY0Diff_objKF;
   /*calculate dX_objKF*/
   dX_objKF = input->fDeltaT_sec * input->fVehVelX_mps;
   vehYawRateStdDev_objKF = input->fVehYawRateStdDev_radps;
   /*kinematic dependant model error*/
   // fObjKinMaxLatAccel_mps2 --> max. lateral acceleration [m/s^2]
   // fObjKinMaxLatJerk_mps3 --> max. lateral jerk [m/s^3]
   // fObjKinRefVel_mps --> reference velocity [m/s]
   if ((input->fObjKinRefVel_mps > 0.1f) && (input->fObjKinMaxLatAccel_mps2 > 0.01f) && (input->fObjKinMaxLatJerk_mps3 > 0.01f)){
       kappa2diff_sigma_objKF = input->fObjKinMaxLatAccel_mps2 / (input->fObjKinMaxLatAccel_mps2 / input->fObjKinMaxLatJerk_mps3) / (input->fObjKinRefVel_mps * input->fObjKinRefVel_mps * input->fObjKinRefVel_mps);
   } else {
       kappa2diff_sigma_objKF = 0.00001f;
   }
   
   /*Reset filter if basic obj data are not valid*/
   if ((input->bObjDataValid_bool) && (input->bEnableKF_bool)){
       /*In case of an obj change allow the PosY0 position to jump in the corresponding cycle - only if kalman filter has been valid*/
       if (status_objKF > 0 && status_objKF < 4){
           /*check obj change detection*/
          if(input->bObjChange_bool){
              /*a lateral position jump is forced in case of an obj change*/
              CML_GetMatrixElement(x_objKF, 0, 0) = input->fPosY0_met;
          }
       }

       /*predict_objKF -  will only be executed if valid_objKF state is set*/
       predict_objKF(input->fDeltaT_sec, dX_objKF,
                input->fVehYawRate_radps, x_objKF, P_objKF, input->fObjKFDynDistYFact_nu,
                input->fObjKFDynYawFactor_nu, input->fObjKFDynCrvFact_nu);

       /*initialize measurement vector z_objKF*/
       CML_GetMatrixElement(z_objKF, 0, 0) = input->fPosY0_met;
       CML_GetMatrixElement(z_objKF, 1, 0) = input->fHeadingAngle_rad;
       CML_GetMatrixElement(z_objKF, 2, 0) = input->fCrv_1pm;

       /*initialize R_objKF matrix*/
       CML_GetMatrixElement(R_objKF, 0, 0) = input->fPosY0StdDev_met * input->fPosY0StdDev_met;
       CML_GetMatrixElement(R_objKF, 1, 1) = input->fHeadingAngleStdDev_rad * input->fHeadingAngleStdDev_rad;
       CML_GetMatrixElement(R_objKF, 2, 2) = input->fCrvStdDev_1pm * input->fCrvStdDev_1pm;

       /*Init or Update*/
       if (!valid_objKF && !(input->bDegradedUpdate_bool))
       {
          /*initialization - for A_objKF better initialization the R_objKF matrix is multiplied with A_objKF constant (>1)*/
          init_objKF(z_objKF, R_objKF, input->uOverallMeasurementQuality_perc, x_objKF, P_objKF, input->uObjKFMnInitQual_perc, input->fObjKFInitRFactor_nu);
       }
       /*Update only if valid AND measurement quality > uObjKFMnUpdateQual_perc*/
       else if (valid_objKF  && (input->uOverallMeasurementQuality_perc >= (input->uObjKFMnUpdateQual_perc))){
           if (input->bDegradedUpdate_bool){
               /*degraded update_objKF - quality and weight are the 2 parameters*/
                update_objKF(z_objKF, R_objKF, input->fObjKFDegradeWeight_nu, x_objKF, P_objKF, input->fObjKFKGainFac_nu);
          }
          else
          {
             /*full update_objKF*/
             update_objKF(z_objKF, R_objKF, 1.0f, x_objKF, P_objKF, input->fObjKFKGainFac_nu);
          }
       }
       /*maintenance_objKF*/
        if(!(status_objKF == 4)){
            maintenance_objKF(x_objKF, P_objKF,input->fObjKFIncQual_1ps, input->fObjKFDecQualDeg_1ps, input->fObjKFDecQualPred_1ps, input->fDeltaT_sec);
        }
   } else {
       reset_objKF(x_objKF, P_objKF);
   }
   
   /*Set output*/
   if (!input->bEnableKF_bool){
       output->fPosY0_met = input->fPosY0_met;
       output->fHeadingAngle_rad = input->fHeadingAngle_rad;
       output->fCrv_1pm = input->fCrv_1pm;
       output->uKFStatus_btf = status_objKF;
       output->uQualityMeasure_perc = input->uOverallMeasurementQuality_perc;
   } else {
       output->fPosY0_met = CML_GetMatrixElement(x_objKF, 0, 0);
       output->fHeadingAngle_rad = CML_GetMatrixElement(x_objKF, 1, 0);
       output->fCrv_1pm = CML_GetMatrixElement(x_objKF, 2, 0);
       output->uKFStatus_btf = status_objKF;
       output->uQualityMeasure_perc = internalQuality_objKF;
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
static void reset_objKF(CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF)
{
   /*reset_objKF parameters*/
   CML_v_InitMatrix(x_objKF, POLY_ORDER_2ND, 1, 0.0f);
   CML_v_InitMatrix(P_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND, 0.0f);
   valid_objKF = FALSE;
   internalQuality_objKF = 0.0f;
   measWeight_objKF = 0.0f;
   status_objKF = 5u;
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
static void maintenance_objKF(CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, real32_T P_ODPFOH_ObjKFIncQual_1ps, real32_T P_ODPFOH_ObjKFDecQualDeg_1ps, real32_T P_ODPFOH_ObjKFDecQualPred_1ps, real32_T deltaT_sec)
{
   if (valid_objKF)
   {
      /*Full Update, Degraded Update or No Update (predict only)? */
      if (measWeight_objKF > 0.9f)
      {
         /* Full Update */
         status_objKF = 1u;
         /* Increase internal quality by P_ODPFOH_ObjKFIncQual_1ps per second*/       
         internalQuality_objKF += P_ODPFOH_ObjKFIncQual_1ps*deltaT_sec;
      }
      else if (measWeight_objKF > 0.0f)
      {
         /* Degraded Update */
         status_objKF = 2u;
         /* Decrease internal quality by P_ODPFOH_ObjKFDecQualDeg_1ps per seconds */
         internalQuality_objKF -= P_ODPFOH_ObjKFDecQualDeg_1ps*deltaT_sec;
      }
      else
      {
         /* No Update - Predict Only */
         status_objKF = 3u;
         /* Decrease internal quality by P_ODPFOH_ObjKFDecQualPred_1ps per seconds */
         internalQuality_objKF -= P_ODPFOH_ObjKFDecQualPred_1ps*deltaT_sec;
      }

      /* Boundary check: 0 <= internalQuality <= 100 */
      if (internalQuality_objKF < 0.0f)
      {
         internalQuality_objKF = 0.0f;
         reset_objKF(x_objKF, P_objKF);
      }
      else if (internalQuality_objKF > 100.0f)
      {
         internalQuality_objKF = 100.0f;
      }

   }
   else
   {
      status_objKF = 0u;
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
static void update_objKF(const CML_t_Matrix* z_objKF, const CML_t_Matrix* R_objKF, real32_T weight, CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, real32_T P_ODPFOH_ObjKFKGainFac_nu)
{
   /*temporary matrices*/
   CML_CreateMatrixLocal(I_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(H_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(H_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(K_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(PH_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(HPH_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(HPH_transPlusR_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(HPH_transPlusR_inv_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(HX_objKF, POLY_ORDER_2ND, 1)
   CML_CreateMatrixLocal(ZSubHX_objKF, POLY_ORDER_2ND, 1)
   CML_CreateMatrixLocal(KZSubHX_objKF, POLY_ORDER_2ND, 1)
   CML_CreateMatrixLocal(KH_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(ISubKH_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(P_tmp_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)

   /*update_objKF state with measurement*/
   CML_v_CreateIdentityMatrix(I_objKF, POLY_ORDER_2ND);
   CML_v_CreateIdentityMatrix(H_objKF, POLY_ORDER_2ND);
   CML_v_TransposeMatrix(H_trans_objKF, H_objKF);
   /*PH'*/
   CML_v_MultiplyMatrices(PH_trans_objKF, P_objKF, H_trans_objKF);
   /*H_objKF[PH']*/
   CML_v_MultiplyMatrices(HPH_trans_objKF, H_objKF, PH_trans_objKF);
   /*[HPH']+R_objKF*/
   CML_v_AddMatrices(HPH_transPlusR_objKF, HPH_trans_objKF, R_objKF);
   /*inv([HPH'+R_objKF]*/   
   LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_objKF, HPH_transPlusR_objKF);
   /*if inversion fails num. of cols and rows are set to 0*/
   if (HPH_transPlusR_inv_objKF->Desc.col > 0)
   {
      /*K_objKF=[PH'][inv(HPH'+R_objKF)]*/
      CML_v_MultiplyMatrices(K_objKF, PH_trans_objKF, HPH_transPlusR_inv_objKF);
      /*K_objKF=K_objKF*weight*/
      CML_v_ScaleMatrix(K_objKF, weight);

      /* if degradedUpdate == true -> Set first row of K_objKF to FACTOR*K_objKF -> weight of Disty = FACTOR*weight */
      if (weight < 0.99f)
      {
         /*set process noise covariance matrix Q_objKF row 0*/
         CML_GetMatrixElement(K_objKF, 0, 0) = P_ODPFOH_ObjKFKGainFac_nu * CML_GetMatrixElement(K_objKF, 0, 0);
         CML_GetMatrixElement(K_objKF, 0, 1) = P_ODPFOH_ObjKFKGainFac_nu * CML_GetMatrixElement(K_objKF, 0, 1);
         CML_GetMatrixElement(K_objKF, 0, 2) = P_ODPFOH_ObjKFKGainFac_nu * CML_GetMatrixElement(K_objKF, 0, 2);
      }

      /*HX_objKF*/
      CML_v_MultiplyMatrices(HX_objKF, H_objKF, x_objKF);
      /*z_objKF-[HX_objKF]*/
      CML_v_SubtractMatrices(ZSubHX_objKF, z_objKF, HX_objKF);
      /*K_objKF[(z_objKF-HX_objKF)]*/
      CML_v_MultiplyMatrices(KZSubHX_objKF, K_objKF, ZSubHX_objKF);
      /*x_objKF=x_objKF+K_objKF(z_objKF-HX_objKF)*/
      CML_v_AddMatrices(x_objKF, x_objKF, KZSubHX_objKF);
      /*KH_objKF*/
      CML_v_MultiplyMatrices(KH_objKF, K_objKF, H_objKF);
      /*I_objKF-[KH_objKF]*/
      CML_v_SubtractMatrices(ISubKH_objKF, I_objKF, KH_objKF);
      /*P_objKF=[(I_objKF-K_objKF*H_objKF)]P_objKF*/
      CML_v_MultiplyMatrices(P_tmp_objKF, ISubKH_objKF, P_objKF);
      CML_v_CopyMatrix(P_objKF, P_tmp_objKF);

      measWeight_objKF = weight;

   }
   else
   {
      reset_objKF(x_objKF, P_objKF);
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
static void predict_objKF(real32_T dT_objKF, real32_T dX_objKF, real32_T vehYawRate, CML_t_Matrix* x_objKF, CML_t_Matrix* P_objKF, real32_T P_ODPFOH_ObjKFDynDistYFact_nu, real32_T P_ODPFOH_ObjKFDynYawFactor_nu, real32_T P_ODPFOH_ObjKFDynCrvFactor_nu)
{
   /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(Q_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(B_objKF, POLY_ORDER_2ND, 1)
   CML_CreateMatrixLocal(AX_objKF, POLY_ORDER_2ND, 1)
   CML_CreateMatrixLocal(A_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(PA_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
   CML_CreateMatrixLocal(APA_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)

   real32_T dXPow2_objKF;
   real32_T dXPow3_objKF;
   real32_T dXPow4_objKF;
   real32_T dXPow5_objKF;
   real32_T dXPow6_objKF;
   real32_T dXPow7_objKF;
   real32_T dXPow8_objKF;
   real32_T Q00_objKF;
   real32_T Q01_objKF;
   real32_T Q02_objKF;
   real32_T Q10_objKF;
   real32_T Q11_objKF;
   real32_T Q12_objKF;
   real32_T Q20_objKF;
   real32_T Q21_objKF;
   real32_T Q22_objKF;
   real32_T sigmaSqr_objKF;

   if (valid_objKF)
   {
      /*initialize system matrix A_objKF*/
      CML_v_InitMatrix(A_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND, 0.0f);
      /*calculate dX_objKF to the power of 2*/
      dXPow2_objKF = dX_objKF * dX_objKF;
      /*calculate dX_objKF to the power of 3*/
      dXPow3_objKF = dXPow2_objKF * dX_objKF;
      /*calculate dX_objKF to the power of 4*/
      dXPow4_objKF = dXPow3_objKF * dX_objKF;
      /*calculate dX_objKF to the power of 5*/
      dXPow5_objKF = dXPow4_objKF * dX_objKF;
      /*calculate dX_objKF to the power of 6*/
      dXPow6_objKF = dXPow5_objKF * dX_objKF;

      /*row 0: 1 dX_objKF 1/2*dX_objKF^2*/
      CML_GetMatrixElement(A_objKF, 0, 0) = 1.0f;
      CML_GetMatrixElement(A_objKF, 0, 1) = dX_objKF;
      CML_GetMatrixElement(A_objKF, 0, 2) = 0.5f * dXPow2_objKF;
      /*row 1: 0 1 -dX_objKF - dX_objKF^2*/
      CML_GetMatrixElement(A_objKF, 1, 1) = 1.0f;
      CML_GetMatrixElement(A_objKF, 1, 2) = dX_objKF;
      /*row 2: 0 0 1 dX_objKF*/
      CML_GetMatrixElement(A_objKF, 2, 2) = 1.0f;

      /*calculate sigma squared*/
      sigmaSqr_objKF = kappa2diff_sigma_objKF * kappa2diff_sigma_objKF;

      /*calculate process noise covariance matrix Q_objKF elements*/
      Q00_objKF = dXPow6_objKF * sigmaSqr_objKF / 36.0f;
      Q01_objKF = dXPow5_objKF * sigmaSqr_objKF / 12.0f;
      Q02_objKF = dXPow4_objKF * sigmaSqr_objKF / 6.0f;

      Q10_objKF = Q01_objKF;
      Q11_objKF = dXPow4_objKF * sigmaSqr_objKF / 4.0f;
      Q12_objKF = dXPow3_objKF * sigmaSqr_objKF / 2.0f;

      Q20_objKF = Q02_objKF;
      Q21_objKF = Q12_objKF;
      Q22_objKF = dXPow2_objKF * sigmaSqr_objKF;

      /*set process noise covariance matrix Q_objKF row 0*/
      CML_GetMatrixElement(Q_objKF, 0, 0) = P_ODPFOH_ObjKFDynDistYFact_nu * Q00_objKF; // Factor needed to increase the dynamic of DistY
      CML_GetMatrixElement(Q_objKF, 0, 1) = Q01_objKF;
      CML_GetMatrixElement(Q_objKF, 0, 2) = Q02_objKF;
      /*set process noise covariance matrix Q_objKF row 1*/
      CML_GetMatrixElement(Q_objKF, 1, 0) = Q01_objKF;
      CML_GetMatrixElement(Q_objKF, 1, 1) = P_ODPFOH_ObjKFDynYawFactor_nu * Q11_objKF; // Factor needed to increase the dynamic of HeadingAngle
      CML_GetMatrixElement(Q_objKF, 1, 2) = Q12_objKF;
      /*set process noise covariance matrix Q_objKF row 2*/
      CML_GetMatrixElement(Q_objKF, 2, 0) = Q02_objKF;
      CML_GetMatrixElement(Q_objKF, 2, 1) = Q12_objKF;
      CML_GetMatrixElement(Q_objKF, 2, 2) = P_ODPFOH_ObjKFDynCrvFactor_nu * Q22_objKF; // Factor needed to increase the dynamic of Kappa

      /*additional noise caused by vehicle movement*/
      CML_GetMatrixElement(Q_objKF, 0, 0) += (dT_objKF * dX_objKF * vehYawRateStdDev_objKF) * (dT_objKF * dX_objKF * vehYawRateStdDev_objKF);
      CML_GetMatrixElement(Q_objKF, 1, 1) += (dT_objKF * vehYawRateStdDev_objKF) * (dT_objKF * vehYawRateStdDev_objKF);

      /*initialize steering matrix*/
      CML_v_InitMatrix(B_objKF, POLY_ORDER_2ND, 1, 0.0f);
      CML_GetMatrixElement(B_objKF, 0, 0) = -dT_objKF * dX_objKF;
      CML_GetMatrixElement(B_objKF, 1, 0) = -dT_objKF;
      /*AX_objKF*/
      CML_v_MultiplyMatrices(AX_objKF, A_objKF, x_objKF);
      /*Bu*/
      CML_v_ScaleMatrix(B_objKF, vehYawRate);
      /*x_objKF = AX_objKF + Bu*/
      CML_v_AddMatrices(x_objKF, AX_objKF, B_objKF);
      /*A_objKF'*/
      CML_v_TransposeMatrix(A_trans_objKF, A_objKF);
      /*PA'*/
      CML_v_MultiplyMatrices(PA_trans_objKF, P_objKF, A_trans_objKF);
      /*APA'*/
      CML_v_MultiplyMatrices(APA_trans_objKF, A_objKF, PA_trans_objKF);
      /*P_objKF=APA'+Q_objKF*/
      CML_v_AddMatrices(P_objKF, APA_trans_objKF, Q_objKF);

      /*Measurement Weight*/
      measWeight_objKF = 0.0f;
      status_objKF = 3u;
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
static void init_objKF(const CML_t_Matrix* z_objKF, CML_t_Matrix* R_objKF, real32_T quality, CML_t_Matrix* x_objKF,CML_t_Matrix* P_objKF, uint8_T P_ODPFOH_ObjKFMnInitQual_perc, real32_T P_ODPFOH_ObjKFInitRFactor_nu){
    
    CML_CreateMatrixLocal(H_trans_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
    CML_CreateMatrixLocal(H_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
    CML_CreateMatrixLocal(tmp_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)
    CML_CreateMatrixLocal(R_scaled_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND)

   if (quality > P_ODPFOH_ObjKFMnInitQual_perc)
   {
      /*scale R_objKF*/
      CML_v_InitMatrix(R_scaled_objKF, POLY_ORDER_2ND, POLY_ORDER_2ND, 0.0f);
      CML_GetMatrixElement(R_scaled_objKF, 0, 0) = CML_GetMatrixElement(R_objKF, 0, 0);
      CML_GetMatrixElement(R_scaled_objKF, 1, 1) = CML_GetMatrixElement(R_objKF, 1, 1);
      CML_GetMatrixElement(R_scaled_objKF, 2, 2) = CML_GetMatrixElement(R_objKF, 2, 2);
      CML_v_ScaleMatrix(R_scaled_objKF, P_ODPFOH_ObjKFInitRFactor_nu);

      /*initialize matrix H_objKF*/
      CML_v_CreateIdentityMatrix(H_objKF, POLY_ORDER_2ND);
      /*initialize matrix H_objKF'*/
      CML_v_TransposeMatrix(H_trans_objKF, H_objKF);
      /*tmp_objKF = H_objKF'R_objKF*/
      CML_v_MultiplyMatrices(tmp_objKF, H_trans_objKF, R_scaled_objKF);
      /*[H_objKF'R_objKF]H_objKF*/
      CML_v_MultiplyMatrices(P_objKF, tmp_objKF, H_objKF);
      /*fill x_objKF*/
      CML_v_MultiplyMatrices(x_objKF, H_trans_objKF, z_objKF);
      /*fill other states*/
      valid_objKF = true;
      internalQuality_objKF = 0.0f;
      measWeight_objKF = 0.0f;
      status_objKF = 4u;
   }
}