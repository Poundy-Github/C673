#ifndef ROAD_EDGE_KALMAN_FILTER_LEFT_SOURCE
#define ROAD_EDGE_KALMAN_FILTER_LEFT_SOURCE

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
static uint8_T valid_roadEdgeKFLe = 0u;
/*status_roadEdgeKFLe of the KF: 0: invalid, 1: valid, full update, 2: valid, degraded update, 3: valid, prediction, 4: valid, init, 5: invalid, reset*/
static uint8_T status_roadEdgeKFLe = 0u;
/*measurement weight*/
static real32_T measWeight_roadEdgeKFLe = 0.0f;
/*internal quality*/
static real32_T internalQuality_roadEdgeKFLe = 0.0f;
/*variable for the yaw rate standard deviation - TODO: really needed?*/
static real32_T vehYawRateStdDev_roadEdgeKFLe = 0.0f;
/*variable for the geometric model error*/
static real32_T kappa2diff_sigma_roadEdgeKFLe = 0.0f;

/*****************************************************************************
 FUNCTION PROTOTYPES
 *****************************************************************************/
static void reset_roadEdgeKFLe(CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe);
static void predict_roadEdgeKFLe(real32_T dT_roadEdgeKFLe, real32_T dX_roadEdgeKFLe,
         real32_T vehYawRate, CML_t_Matrix* x_roadEdgeKFLe,
         CML_t_Matrix* P_roadEdgeKFLe, real32_T P_ABPREP_RoadKFDynDistYFact_nu,
            real32_T P_ABPREP_RoadKFDynYawFactor_nu,real32_T P_ABPREP_RoadKFDynCrvFactor_nu, real32_T P_ABPREP_RoadKFDynCrvRtFactor_nu);
static void init_roadEdgeKFLe(const CML_t_Matrix* z_roadEdgeKFLe, CML_t_Matrix* R_roadEdgeKFLe, real32_T quality, CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe, uint8_T P_ABPREP_RoadKFMnInitQual_perc, real32_T P_ABPREP_RoadKFInitRFactor_nu);
static void update_roadEdgeKFLe(const CML_t_Matrix* z_roadEdgeKFLe,
         const CML_t_Matrix* R_roadEdgeKFLe, real32_T weight,
         CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe, real32_T P_ABPREP_RoadKFKGainFac_nu);
static void maintenance_roadEdgeKFLe(CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe, real32_T P_ABPREP_RoadKFIncQual_1ps,
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
void roadEdgeKalmanFilter_Left(const roadEdgeKFInType* inputs, roadEdgeKFOutType* outputs)
{
   /*state Matrix x_roadEdgeKFLe*/
   CML_CreateMatrix(x_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   /*covariance matrix P_roadEdgeKFLe*/
   CML_CreateMatrix(P_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   /*measurement matrix z_roadEdgeKFLe*/
   CML_CreateMatrix(z_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   /*measurement variance matrix R_roadEdgeKFLe*/
   CML_CreateMatrix(R_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)

   real32_T dX_roadEdgeKFLe;
   real32_T PosY0Diff_roadEdgeKFLe;
   /*calculate dX_roadEdgeKFLe*/
   dX_roadEdgeKFLe = inputs->sf_DeltaT_sec * inputs->sf_VehVelX_mps;
   vehYawRateStdDev_roadEdgeKFLe = inputs->sf_VehYawRateStdDev_radps;
   /*geometric dependent model error*/ 
	if(inputs->sf_LaneKFErrCoeff1_met<1e-5 || inputs->sf_LaneKFErrCoeff2_mps<1e-5||inputs->sf_DeltaT_sec<1e-5){
		kappa2diff_sigma_roadEdgeKFLe = 1;
	}
	else{
		kappa2diff_sigma_roadEdgeKFLe = 1 / inputs->sf_LaneKFErrCoeff1_met
			/ (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec)
			/ (inputs->sf_LaneKFErrCoeff2_mps * inputs->sf_DeltaT_sec);
	}

   /*In case of an lane change allow the PosY0 position to jump in the corresponding cycle - only if kalman filter has been valid*/
   if (status_roadEdgeKFLe > 0 && status_roadEdgeKFLe < 4){
       /*check lane change detection*/
      if(inputs->sf_LaneChange_bool){
          /*a lateral position jump is forced in case of a lane change*/
          CML_GetMatrixElement(x_roadEdgeKFLe, 0, 0) = inputs->sf_PosY0_met;
      }
   }

   /*predict_roadEdgeKFLe -  will only be executed if valid_roadEdgeKFLe state is set*/
   predict_roadEdgeKFLe(inputs->sf_DeltaT_sec, dX_roadEdgeKFLe,
            inputs->sf_VehYawRate_radps, x_roadEdgeKFLe, P_roadEdgeKFLe, inputs->sf_LaneKFDynDistYFact_nu,
            inputs->sf_LaneKFDynYawFactor_nu, inputs->sf_LaneKFDynCrvFact_nu, inputs->sf_LaneKFDynCrvRateFact_nu);

   /*initialize measurement vector z_roadEdgeKFLe*/
   CML_GetMatrixElement(z_roadEdgeKFLe, 0, 0)= inputs->sf_PosY0_met;
   CML_GetMatrixElement(z_roadEdgeKFLe, 1, 0)= inputs->sf_HeadingAngle_rad;
   CML_GetMatrixElement(z_roadEdgeKFLe, 2, 0)= inputs->sf_Crv_1pm;
   CML_GetMatrixElement(z_roadEdgeKFLe, 3, 0)= inputs->sf_CrvChng_1pm2;

   /*initialize R_roadEdgeKFLe matrix*/
   CML_GetMatrixElement(R_roadEdgeKFLe, 0, 0)= inputs->sf_PosY0StdDev_met*inputs->sf_PosY0StdDev_met;
   CML_GetMatrixElement(R_roadEdgeKFLe, 1, 1)= inputs->sf_HeadingAngleStdDev_rad*inputs->sf_HeadingAngleStdDev_rad;
   CML_GetMatrixElement(R_roadEdgeKFLe, 2, 2)= inputs->sf_CrvStdDev_1pm*inputs->sf_CrvStdDev_1pm;
   CML_GetMatrixElement(R_roadEdgeKFLe, 3, 3)= inputs->sf_CrvChngStdDev_1pm2*inputs->sf_CrvChngStdDev_1pm2;

   /*Init or Update*/
   if (!valid_roadEdgeKFLe && !(inputs->sf_DegradedUpdate_bool))
   {
      /*initialization - for A_roadEdgeKFLe better initialization the R_roadEdgeKFLe matrix is multiplied with A_roadEdgeKFLe constant (>1)*/
      init_roadEdgeKFLe(z_roadEdgeKFLe, R_roadEdgeKFLe, inputs->sf_OverallMeasurementQuality_perc, x_roadEdgeKFLe, P_roadEdgeKFLe, inputs->sf_LaneKFMnInitQual_perc, inputs->sf_LaneKFInitRFactor_nu);
   }
   /*Update only if valid AND measurement quality > sf_LaneKFMnUpdateQual_perc*/
   else if (valid_roadEdgeKFLe  && (inputs->sf_OverallMeasurementQuality_perc >= (inputs->sf_LaneKFMnUpdateQual_perc))){
       if (inputs->sf_DegradedUpdate_bool){
           /*degraded update_roadEdgeKFLe - quality and weight are the 2 parameters*/
            update_roadEdgeKFLe(z_roadEdgeKFLe, R_roadEdgeKFLe, inputs->sf_LaneKFDegradeWeight_nu, x_roadEdgeKFLe, P_roadEdgeKFLe, inputs->sf_LaneKFKGainFac_nu);
      }
      else
      {
         /*full update_roadEdgeKFLe*/
         update_roadEdgeKFLe(z_roadEdgeKFLe, R_roadEdgeKFLe, 1.0f, x_roadEdgeKFLe, P_roadEdgeKFLe, inputs->sf_LaneKFKGainFac_nu);
      }
   }
   /*maintenance_roadEdgeKFLe*/
    if(!(status_roadEdgeKFLe == 4)){
        maintenance_roadEdgeKFLe(x_roadEdgeKFLe, P_roadEdgeKFLe,inputs->sf_LaneKFIncQual_1ps,
                                    inputs->sf_LaneKFDecQualDeg_1ps, inputs->sf_LaneKFDecQualPred_1ps,
                                        inputs->sf_DeltaT_sec);
    }
   /*Reset filter if basic lane data are not valid*/
   if (!inputs->sf_LaneDataValid_bool)
      reset_roadEdgeKFLe(x_roadEdgeKFLe, P_roadEdgeKFLe);
   /*Set outputs*/
   outputs->sf_PosY0_met = CML_GetMatrixElement(x_roadEdgeKFLe, 0, 0);
   outputs->sf_HeadingAngle_rad = CML_GetMatrixElement(x_roadEdgeKFLe, 1, 0);
   outputs->sf_Crv_1pm = CML_GetMatrixElement(x_roadEdgeKFLe, 2, 0);
   outputs->sf_CrvChng_1pm2 = CML_GetMatrixElement(x_roadEdgeKFLe, 3, 0);
   outputs->sf_KFStatus_btf = status_roadEdgeKFLe;
   outputs->sf_QualityMeasure_perc = internalQuality_roadEdgeKFLe;
   
   outputs->sf_PosY0Variance_met2 = CML_GetMatrixElement(P_roadEdgeKFLe, 0, 0);
   outputs->sf_HeadingAngleVariance_rad2 = CML_GetMatrixElement(P_roadEdgeKFLe, 1, 1);
   outputs->sf_CrvVariance_1pm2 = CML_GetMatrixElement(P_roadEdgeKFLe, 2, 2);
   outputs->sf_CrvRateVariance_1pm4 = CML_GetMatrixElement(P_roadEdgeKFLe, 3, 3);
  
   
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
static void reset_roadEdgeKFLe(CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe)
{
   /*reset_roadEdgeKFLe parameters*/
   CML_v_InitMatrix(x_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1, 0.0f);
   CML_v_InitMatrix(P_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF, 0.0f);
   valid_roadEdgeKFLe = FALSE;
   internalQuality_roadEdgeKFLe = 0.0f;
   measWeight_roadEdgeKFLe = 0.0f;
   status_roadEdgeKFLe = 5u;
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
static void maintenance_roadEdgeKFLe(CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe, real32_T P_ABPREP_RoadKFIncQual_1ps,
                                    real32_T P_ABPREP_RoadKFDecQualDeg_1ps, real32_T P_ABPREP_RoadKFDecQualPred_1ps,
                                        real32_T deltaT_sec)
{
   if (valid_roadEdgeKFLe)
   {
      /*Full Update, Degraded Update or No Update (predict only)? */
      if (measWeight_roadEdgeKFLe > 0.9f)
      {
         /* Full Update */
         status_roadEdgeKFLe = 1u;
         /* Increase internal quality by P_ABPREP_RoadKFIncQual_1ps per second*/       
         internalQuality_roadEdgeKFLe += P_ABPREP_RoadKFIncQual_1ps*deltaT_sec;
      }
      else if (measWeight_roadEdgeKFLe > 0.0f)
      {
         /* Degraded Update */
         status_roadEdgeKFLe = 2u;
         /* Decrease internal quality by P_ABPREP_RoadKFDecQualDeg_1ps per seconds */
         internalQuality_roadEdgeKFLe -= P_ABPREP_RoadKFDecQualDeg_1ps*deltaT_sec;
      }
      else
      {
         /* No Update - Predict Only */
         status_roadEdgeKFLe = 3u;
         /* Decrease internal quality by P_ABPREP_RoadKFDecQualPred_1ps per seconds */
         internalQuality_roadEdgeKFLe -= P_ABPREP_RoadKFDecQualPred_1ps*deltaT_sec;
      }

      /* Boundary check: 0 <= internalQuality <= 100 */
      if (internalQuality_roadEdgeKFLe < 0.0f)
      {
         internalQuality_roadEdgeKFLe = 0.0f;
         reset_roadEdgeKFLe(x_roadEdgeKFLe, P_roadEdgeKFLe);
      }
      else if (internalQuality_roadEdgeKFLe > 100.0f)
      {
         internalQuality_roadEdgeKFLe = 100.0f;
      }

   }
   else
   {
      status_roadEdgeKFLe = 0u;
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
static void update_roadEdgeKFLe(const CML_t_Matrix* z_roadEdgeKFLe,
         const CML_t_Matrix* R_roadEdgeKFLe, real32_T weight,
         CML_t_Matrix* x_roadEdgeKFLe, CML_t_Matrix* P_roadEdgeKFLe, real32_T P_ABPREP_RoadKFKGainFac_nu)
{
   /*temporary matrices*/
   CML_CreateMatrixLocal(I_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(H_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(H_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(K_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(PH_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HPH_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HPH_transPlusR_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HPH_transPlusR_inv_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(HX_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(ZSubHX_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(KZSubHX_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(KH_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(ISubKH_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(P_tmp_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)

   /*update_roadEdgeKFLe state with measurement*/
   CML_v_CreateIdentityMatrix(I_roadEdgeKFLe, STATE_LENGTH_RoadKF);
   CML_v_CreateIdentityMatrix(H_roadEdgeKFLe, STATE_LENGTH_RoadKF);
   CML_v_TransposeMatrix(H_trans_roadEdgeKFLe, H_roadEdgeKFLe);
   /*PH'*/
   CML_v_MultiplyMatrices(PH_trans_roadEdgeKFLe, P_roadEdgeKFLe, H_trans_roadEdgeKFLe);
   /*H_roadEdgeKFLe[PH']*/
   CML_v_MultiplyMatrices(HPH_trans_roadEdgeKFLe, H_roadEdgeKFLe, PH_trans_roadEdgeKFLe);
   /*[HPH']+R_roadEdgeKFLe*/
   CML_v_AddMatrices(HPH_transPlusR_roadEdgeKFLe, HPH_trans_roadEdgeKFLe, R_roadEdgeKFLe);
   /*inv([HPH'+R_roadEdgeKFLe]*/
   //CML_v_InvertMatrix(HPH_transPlusR_inv_roadEdgeKFLe, HPH_transPlusR_roadEdgeKFLe);
   LCF_CML_v_InvertMatrix(HPH_transPlusR_inv_roadEdgeKFLe, HPH_transPlusR_roadEdgeKFLe);
   /*if inversion fails num. of cols and rows are set to 0*/
   if (HPH_transPlusR_inv_roadEdgeKFLe->Desc.col > 0)
   {
      /*K_roadEdgeKFLe=[PH'][inv(HPH'+R_roadEdgeKFLe)]*/
      CML_v_MultiplyMatrices(K_roadEdgeKFLe, PH_trans_roadEdgeKFLe,
               HPH_transPlusR_inv_roadEdgeKFLe);
      /*K_roadEdgeKFLe=K_roadEdgeKFLe*weight*/
      CML_v_ScaleMatrix(K_roadEdgeKFLe, weight);

      /* if degradedUpdate == true -> Set first row of K_roadEdgeKFLe to FACTOR*K_roadEdgeKFLe -> weight of Disty = FACTOR*weight */
      if (weight < 1.0f)
      {
         /*set process noise covariance matrix Q_roadEdgeKFLe row 0*/
         CML_GetMatrixElement(K_roadEdgeKFLe, 0, 0)= P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFLe, 0, 0);
         CML_GetMatrixElement(K_roadEdgeKFLe, 0, 1) = P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFLe, 0, 1);
         CML_GetMatrixElement(K_roadEdgeKFLe, 0, 2) = P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFLe, 0, 2);
         CML_GetMatrixElement(K_roadEdgeKFLe, 0, 3) = P_ABPREP_RoadKFKGainFac_nu * CML_GetMatrixElement(K_roadEdgeKFLe, 0, 3);
      }

      /*HX_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(HX_roadEdgeKFLe, H_roadEdgeKFLe, x_roadEdgeKFLe);
      /*z_roadEdgeKFLe-[HX_roadEdgeKFLe]*/
      CML_v_SubtractMatrices(ZSubHX_roadEdgeKFLe, z_roadEdgeKFLe, HX_roadEdgeKFLe);
      /*K_roadEdgeKFLe[(z_roadEdgeKFLe-HX_roadEdgeKFLe)]*/
      CML_v_MultiplyMatrices(KZSubHX_roadEdgeKFLe, K_roadEdgeKFLe, ZSubHX_roadEdgeKFLe);
      /*x_roadEdgeKFLe=x_roadEdgeKFLe+K_roadEdgeKFLe(z_roadEdgeKFLe-HX_roadEdgeKFLe)*/
      CML_v_AddMatrices(x_roadEdgeKFLe, x_roadEdgeKFLe, KZSubHX_roadEdgeKFLe);
      /*KH_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(KH_roadEdgeKFLe, K_roadEdgeKFLe, H_roadEdgeKFLe);
      /*I_roadEdgeKFLe-[KH_roadEdgeKFLe]*/
      CML_v_SubtractMatrices(ISubKH_roadEdgeKFLe, I_roadEdgeKFLe, KH_roadEdgeKFLe);
      /*P_roadEdgeKFLe=[(I_roadEdgeKFLe-K_roadEdgeKFLe*H_roadEdgeKFLe)]P_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(P_tmp_roadEdgeKFLe, ISubKH_roadEdgeKFLe, P_roadEdgeKFLe);
      CML_v_CopyMatrix(P_roadEdgeKFLe, P_tmp_roadEdgeKFLe);

      measWeight_roadEdgeKFLe = weight;

   }
   else
   {
      reset_roadEdgeKFLe(x_roadEdgeKFLe, P_roadEdgeKFLe);
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
static void predict_roadEdgeKFLe(real32_T dT_roadEdgeKFLe, real32_T dX_roadEdgeKFLe,
         real32_T vehYawRate, CML_t_Matrix* x_roadEdgeKFLe,
         CML_t_Matrix* P_roadEdgeKFLe, real32_T P_ABPREP_RoadKFDynDistYFact_nu,
            real32_T P_ABPREP_RoadKFDynYawFactor_nu, real32_T P_ABPREP_RoadKFDynCrvFactor_nu, real32_T P_ABPREP_RoadKFDynCrvRtFactor_nu)
{
   /*initialize local matrices and variables*/
   CML_CreateMatrixLocal(A_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(Q_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(B_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(AX_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1)
   CML_CreateMatrixLocal(A_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(PA_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
   CML_CreateMatrixLocal(APA_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)

   real32_T dXPow2_roadEdgeKFLe;
   real32_T dXPow3_roadEdgeKFLe;
   real32_T dXPow4_roadEdgeKFLe;
   real32_T dXPow5_roadEdgeKFLe;
   real32_T dXPow6_roadEdgeKFLe;
   real32_T dXPow7_roadEdgeKFLe;
   real32_T dXPow8_roadEdgeKFLe;
   real32_T Q00_roadEdgeKFLe;
   real32_T Q01_roadEdgeKFLe;
   real32_T Q02_roadEdgeKFLe;
   real32_T Q03_roadEdgeKFLe;
   real32_T Q11_roadEdgeKFLe;
   real32_T Q12_roadEdgeKFLe;
   real32_T Q13_roadEdgeKFLe;
   real32_T Q22_roadEdgeKFLe;
   real32_T Q23_roadEdgeKFLe;
   real32_T Q33_roadEdgeKFLe;
   real32_T sigmaSqr_roadEdgeKFLe;

   if (valid_roadEdgeKFLe)
   {
      /*initialize system matrix A_roadEdgeKFLe*/
      CML_v_InitMatrix(A_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF,
               0.0f);
      /*calculate dX_roadEdgeKFLe to the power of 2*/
      dXPow2_roadEdgeKFLe = dX_roadEdgeKFLe * dX_roadEdgeKFLe;
      /*calculate dX_roadEdgeKFLe to the power of 3*/
      dXPow3_roadEdgeKFLe = dXPow2_roadEdgeKFLe * dX_roadEdgeKFLe;
      /*calculate dX_roadEdgeKFLe to the power of 4*/
      dXPow4_roadEdgeKFLe = dXPow3_roadEdgeKFLe * dX_roadEdgeKFLe;
      /*calculate dX_roadEdgeKFLe to the power of 5*/
      dXPow5_roadEdgeKFLe = dXPow4_roadEdgeKFLe * dX_roadEdgeKFLe;
      /*calculate dX_roadEdgeKFLe to the power of 6*/
      dXPow6_roadEdgeKFLe = dXPow5_roadEdgeKFLe * dX_roadEdgeKFLe;
      /*calculate dX_roadEdgeKFLe to the power of 7*/
      dXPow7_roadEdgeKFLe = dXPow6_roadEdgeKFLe * dX_roadEdgeKFLe;
      /*calculate dX_roadEdgeKFLe to the power of 8*/
      dXPow8_roadEdgeKFLe = dXPow7_roadEdgeKFLe * dX_roadEdgeKFLe;

      /*row 0: 1 dX_roadEdgeKFLe 1/2*dX_roadEdgeKFLe^2 1/6*dX_roadEdgeKFLe^3*/
      CML_GetMatrixElement(A_roadEdgeKFLe, 0, 0)= 1.0f;
      CML_GetMatrixElement(A_roadEdgeKFLe, 0, 1)= -dX_roadEdgeKFLe;
      CML_GetMatrixElement(A_roadEdgeKFLe, 0, 2)= -0.5f * dXPow2_roadEdgeKFLe;
      CML_GetMatrixElement(A_roadEdgeKFLe, 0, 3)= -1.0f/6.0f * dXPow3_roadEdgeKFLe;
      /*row 1: 0 1 -dX_roadEdgeKFLe - dX_roadEdgeKFLe^2*/
      CML_GetMatrixElement(A_roadEdgeKFLe, 1, 1)= 1.0f;
      CML_GetMatrixElement(A_roadEdgeKFLe, 1, 2)= -dX_roadEdgeKFLe;
      CML_GetMatrixElement(A_roadEdgeKFLe, 1, 3)= -dXPow2_roadEdgeKFLe;
      /*row 2: 0 0 1 dX_roadEdgeKFLe*/
      CML_GetMatrixElement(A_roadEdgeKFLe, 2, 2)= 1.0f;
      CML_GetMatrixElement(A_roadEdgeKFLe, 2, 3)= 0.0f;
      /*row 3: 0 0 0 1*/
      CML_GetMatrixElement(A_roadEdgeKFLe, 3, 3)= 1.0f;

      /*calculate sigma squared*/
      sigmaSqr_roadEdgeKFLe = kappa2diff_sigma_roadEdgeKFLe * kappa2diff_sigma_roadEdgeKFLe;

      /*calculate process noise covariance matrix Q_roadEdgeKFLe elements*/
      Q00_roadEdgeKFLe = dXPow8_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 576.0f;
      Q01_roadEdgeKFLe = dXPow7_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 48.0f;
      Q02_roadEdgeKFLe = -dXPow6_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 48.0f;
      Q03_roadEdgeKFLe = -dXPow5_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 24.0f;

      Q11_roadEdgeKFLe = dXPow6_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 4.0f;
      Q12_roadEdgeKFLe = -dXPow5_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 4.0f;
      Q13_roadEdgeKFLe = -dXPow4_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 2.0f;

      Q22_roadEdgeKFLe = dXPow4_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 4.0f;
      Q23_roadEdgeKFLe = dXPow3_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe / 2.0f;

      Q33_roadEdgeKFLe = dXPow2_roadEdgeKFLe * sigmaSqr_roadEdgeKFLe;

      /*set process noise covariance matrix Q_roadEdgeKFLe row 0*/
      CML_GetMatrixElement(Q_roadEdgeKFLe, 0, 0)= P_ABPREP_RoadKFDynDistYFact_nu * Q00_roadEdgeKFLe; // Factor needed to increase the dynamic of DistY
      CML_GetMatrixElement(Q_roadEdgeKFLe, 0, 1)= Q01_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 0, 2)= Q02_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 0, 3)= Q03_roadEdgeKFLe;
      /*set process noise covariance matrix Q_roadEdgeKFLe row 1*/
      CML_GetMatrixElement(Q_roadEdgeKFLe, 1, 0)= Q01_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 1, 1)= P_ABPREP_RoadKFDynYawFactor_nu * Q11_roadEdgeKFLe; // Factor needed to increase the dynamic of HeadingAngle
      CML_GetMatrixElement(Q_roadEdgeKFLe, 1, 2)= Q12_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 1, 3)= Q13_roadEdgeKFLe;
      /*set process noise covariance matrix Q_roadEdgeKFLe row 2*/
      CML_GetMatrixElement(Q_roadEdgeKFLe, 2, 0)= Q02_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 2, 1)= Q12_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 2, 2)= P_ABPREP_RoadKFDynCrvFactor_nu * Q22_roadEdgeKFLe; // Factor needed to increase the dynamic of Kappa
      CML_GetMatrixElement(Q_roadEdgeKFLe, 2, 3)= Q23_roadEdgeKFLe;
      /*set process noise covariance matrix Q_roadEdgeKFLe row 3*/
      CML_GetMatrixElement(Q_roadEdgeKFLe, 3, 0)= Q03_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 3, 1)= Q13_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 3, 2)= Q23_roadEdgeKFLe;
      CML_GetMatrixElement(Q_roadEdgeKFLe, 3, 3)= P_ABPREP_RoadKFDynCrvRtFactor_nu * Q33_roadEdgeKFLe;

      /*additional noise caused by vehicle movement*/
      CML_GetMatrixElement(Q_roadEdgeKFLe, 0, 0)+= (dT_roadEdgeKFLe * dX_roadEdgeKFLe * vehYawRateStdDev_roadEdgeKFLe) * (dT_roadEdgeKFLe * dX_roadEdgeKFLe * vehYawRateStdDev_roadEdgeKFLe);
      CML_GetMatrixElement(Q_roadEdgeKFLe, 1, 1)+= (dT_roadEdgeKFLe * vehYawRateStdDev_roadEdgeKFLe) * (dT_roadEdgeKFLe * vehYawRateStdDev_roadEdgeKFLe);

      /*initialize steering matrix*/

      CML_v_InitMatrix(B_roadEdgeKFLe, STATE_LENGTH_RoadKF, 1, 0.0f);
      CML_GetMatrixElement(B_roadEdgeKFLe, 0, 0)= -dT_roadEdgeKFLe * dX_roadEdgeKFLe;
      CML_GetMatrixElement(B_roadEdgeKFLe, 1, 0)= dT_roadEdgeKFLe;
      /*AX_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(AX_roadEdgeKFLe, A_roadEdgeKFLe, x_roadEdgeKFLe);
      /*Bu*/
      CML_v_ScaleMatrix(B_roadEdgeKFLe, vehYawRate);
      /*x_roadEdgeKFLe = AX_roadEdgeKFLe + Bu*/
      CML_v_AddMatrices(x_roadEdgeKFLe, AX_roadEdgeKFLe, B_roadEdgeKFLe);
      /*A_roadEdgeKFLe'*/
      CML_v_TransposeMatrix(A_trans_roadEdgeKFLe, A_roadEdgeKFLe);
      /*PA'*/
      CML_v_MultiplyMatrices(PA_trans_roadEdgeKFLe, P_roadEdgeKFLe, A_trans_roadEdgeKFLe);
      /*APA'*/
      CML_v_MultiplyMatrices(APA_trans_roadEdgeKFLe, A_roadEdgeKFLe, PA_trans_roadEdgeKFLe);
      /*P_roadEdgeKFLe=APA'+Q_roadEdgeKFLe*/
      CML_v_AddMatrices(P_roadEdgeKFLe, APA_trans_roadEdgeKFLe, Q_roadEdgeKFLe);

      /*Measurement Weight*/
      measWeight_roadEdgeKFLe = 0.0f;
      status_roadEdgeKFLe = 3u;
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
static void init_roadEdgeKFLe(const CML_t_Matrix* z_roadEdgeKFLe, CML_t_Matrix* R_roadEdgeKFLe, real32_T quality, CML_t_Matrix* x_roadEdgeKFLe,CML_t_Matrix* P_roadEdgeKFLe, uint8_T P_ABPREP_RoadKFMnInitQual_perc, real32_T P_ABPREP_RoadKFInitRFactor_nu){
    
    CML_CreateMatrixLocal(H_trans_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)
    CML_CreateMatrixLocal(H_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
    CML_CreateMatrixLocal(tmp_roadEdgeKFLe, STATE_LENGTH_RoadKF, STATE_LENGTH_RoadKF)
    CML_CreateMatrixLocal(R_scaled_roadEdgeKFLe, STATE_LENGTH_RoadKF,
            STATE_LENGTH_RoadKF)

   if (quality > P_ABPREP_RoadKFMnInitQual_perc)
   {
      /*scale R_roadEdgeKFLe*/
      CML_v_InitMatrix(R_scaled_roadEdgeKFLe, STATE_LENGTH_RoadKF,
      STATE_LENGTH_RoadKF, 0.0f);
      CML_GetMatrixElement(R_scaled_roadEdgeKFLe, 0, 0)= CML_GetMatrixElement(R_roadEdgeKFLe, 0, 0);
      CML_GetMatrixElement(R_scaled_roadEdgeKFLe, 1, 1)= CML_GetMatrixElement(R_roadEdgeKFLe, 1, 1);
      CML_GetMatrixElement(R_scaled_roadEdgeKFLe, 2, 2)= CML_GetMatrixElement(R_roadEdgeKFLe, 2, 2);
      CML_GetMatrixElement(R_scaled_roadEdgeKFLe, 3, 3)= CML_GetMatrixElement(R_roadEdgeKFLe, 3, 3);
      CML_v_ScaleMatrix(R_scaled_roadEdgeKFLe, P_ABPREP_RoadKFInitRFactor_nu);

      /*initialize matrix H_roadEdgeKFLe*/
      CML_v_CreateIdentityMatrix(H_roadEdgeKFLe, STATE_LENGTH_RoadKF);
      /*initialize matrix H_roadEdgeKFLe'*/
      CML_v_TransposeMatrix(H_trans_roadEdgeKFLe, H_roadEdgeKFLe);
      /*tmp_roadEdgeKFLe = H_roadEdgeKFLe'R_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(tmp_roadEdgeKFLe, H_trans_roadEdgeKFLe, R_scaled_roadEdgeKFLe);
      /*[H_roadEdgeKFLe'R_roadEdgeKFLe]H_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(P_roadEdgeKFLe, tmp_roadEdgeKFLe, H_roadEdgeKFLe);
      /*fill x_roadEdgeKFLe*/
      CML_v_MultiplyMatrices(x_roadEdgeKFLe, H_trans_roadEdgeKFLe, z_roadEdgeKFLe);
      /*fill other states*/
      valid_roadEdgeKFLe = true;
      internalQuality_roadEdgeKFLe = 0.0f;
      measWeight_roadEdgeKFLe = 0.0f;
      status_roadEdgeKFLe = 4u;
   }
}
#endif
