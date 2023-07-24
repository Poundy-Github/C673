/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSND_Veh.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.2.1.6 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include <string.h>  /*memset/memcpy*/
#include "LCFVEH/LCFVEH_data.h"

/*---------------------------------------------------------*
   G L O B A L   V A R I A B L E S
**---------------------------------------------------------*/

static uint8 T_LCFSND_ActToi_nu = (uint8)LCF_DEACTIVATE_TOI;

/*----------------------------------------------------------*
  FUNCTION PROTOTYPES
*----------------------------------------------------------*/
static void LCFSND_VehResetRTEOutputData(void);
static void LCFSND_VehFillRTEOutputData(void);
uint8 Get_T_LCFSND_ActToi_nu(void) { return T_LCFSND_ActToi_nu; }

/*---------------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**---------------------------------------------------------*/
  
  /* ***********************************************************************
  @fn               LCFSND_VehResetRTEOutputData */ /*!

  @brief           Reset global output data

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void LCFSND_VehResetRTEOutputData(void)
{
	(void)memset((void*)pLcfVehProPorts->pLcfVehOutputData, 0, sizeof(LCF_VehGenericOutputs_t));
	(void)memset((void*)pLcfVehProPorts->pLcfVehOutputToSenData, 0, sizeof(LCF_VehToSen_t));
	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
	(void)memset((void*)pLcfVehProPorts->pLcfLaDmcSocToIuc, 0, sizeof(LCF_LaDmcSocToIuc_t));
	#endif
	/* Port NVM_LcfLearningData_t*   pNvmLcfData; is already SET in function LCFRCV_VehReset. Do not overwrite these values!!!*/
}	
 
  /* ***********************************************************************
  @fn               LCFSND_VehFillRTEOutputData */ /*!

  @brief            copy global output data from computed output signals to provided ports

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void LCFSND_VehFillRTEOutputData(void)
{
	uint8 i;

/*CopyTrjCtrOutput*/
	/*Surpress QAC Messages (next lines): This usage of a function-like macro looks like it could be replaced by an equivalent function call.
	Intentional usage of  function like macro*/
	/*PRQA S 3469 ++*/
	pLcfVehProPorts->pLcfVehOutputToSenData->Curvatures.TgtCrv_DE_1pm            	= GET_S_TCTLGC_TgtCrv_DE_1pm();
	pLcfVehProPorts->pLcfVehOutputToSenData->Curvatures.TgtCrv_DEWithNoLatSlp_1pm	= GET_S_TCTLGC_TgtCrv_DENoLatSlp_1pm();
	pLcfVehProPorts->pLcfVehOutputToSenData->Curvatures.TgtCrv_Limited_1pm       	= GET_S_TCTCLM_Limiter_TgtCrv_1pm();
	pLcfVehProPorts->pLcfVehOutputToSenData->Curvatures.TgtCrv_NoDE_1pm          	= GET_S_TCTLGC_TgtCrv_NoDE_1pm();
  
	pLcfVehProPorts->pLcfVehOutputToSenData->Errors.CtrlErrDistY_m               	= GET_S_TCTCDC_CtrlErrDistY_met();
	pLcfVehProPorts->pLcfVehOutputToSenData->Errors.CtrlErrHeadingAngle_rad      	= GET_S_TCTCDC_CtrlErrHeadAgl_rad();

	pLcfVehProPorts->pLcfVehOutputToSenData->Flags.TgtCrv_LimiterWarning_nu      	= GET_S_TCTCLM_LimiterWarning_nu();
	pLcfVehProPorts->pLcfVehOutputToSenData->Flags.TgtVehCtrlQualifier_nu        	= 0u; /*GET_S_TCTCLM_Limiter_TgtVehCtrlQu_nu()*/
	pLcfVehProPorts->pLcfVehOutputToSenData->Flags.TrjCtrQualifierService_nu       = GET_S_TCTCLM_QuServTrajCtr_nu(); 
	pLcfVehProPorts->pLcfVehOutputToSenData->Flags.QuStatusTrajPlan_nu        	    = GET_S_TPLFBT_QuStatusTrajPlan_nu(); /*RO840664*/
	pLcfVehProPorts->pLcfVehOutputToSenData->Flags.LaDmcQualifierService_nu        = 0u; /*not available anymore*/
/*end CopyTrjCtrOutput*/

/*CopyTrjPlnOutput*/
	pLcfVehProPorts->pLcfVehOutputToSenData->DesiredTraj.TrajDistY_m                         			= GET_S_TPLFBT_TrajDistY_met();
	pLcfVehProPorts->pLcfVehOutputToSenData->DesiredTraj.TrajHeading_rad                     			= GET_S_TPLFBT_TrajHeading_rad();
	pLcfVehProPorts->pLcfVehOutputToSenData->DesiredTraj.TrajHeadingInclPreview_rad          			= GET_S_TPLFBT_TrajHeadInclPrev_rad();

	pLcfVehProPorts->pLcfVehOutputToSenData->ReplanValues.TrajGuiQualifier_nu                			= GET_S_TPLFBT_TrajGuiQualifier_nu();
	pLcfVehProPorts->pLcfVehOutputToSenData->ReplanValues.TrigCustFctReplanCurValues_nu      			= 0u;/* Signal must not be used. Should be deleted from RTE8*/

	pLcfVehProPorts->pLcfVehOutputToSenData->TrajError.CurDistY_m                            			= GET_S_TPLFBT_CurDistY_met();
	pLcfVehProPorts->pLcfVehOutputToSenData->TrajError.CurHeading_rad                        			= GET_S_TPLFBT_CurHeading_rad();
	pLcfVehProPorts->pLcfVehOutputToSenData->TrajError.LtcyComp_DevHeading_rad               			= GET_S_TPLLCO_DevHeading_rad();
	pLcfVehProPorts->pLcfVehOutputToSenData->TrajPlanCurvatures.TgtTrajCrv_1pm               			= GET_S_TPLFBT_TrajTgtCrv_1pm();
	
    for( i = 0u; i < 5u; i ++)
    {
        pLcfVehProPorts->pLcfVehOutputToSenData->EvntDtctnVehEvents_nu[i].EventId_nu = 0;
        pLcfVehProPorts->pLcfVehOutputToSenData->EvntDtctnVehEvents_nu[i].EventLifetime_nu = 0;
    }
	
	pLcfVehProPorts->pLcfVehOutputToSenData->DrvAttention_perc       = GET_S_DRMDAE_DrvAttention_perc();
	pLcfVehProPorts->pLcfVehOutputToSenData->DrvAttentionConf_perc   = GET_S_DRMDAE_DrvAttentionConf_perc();
	pLcfVehProPorts->pLcfVehOutputToSenData->DrvMonSysWarning_nu     = GET_S_DRMDAE_SysWarning_nu();
	pLcfVehProPorts->pLcfVehOutputToSenData->HandsOffConfirmed_nu    = GET_S_DRMHOD_HandsOffConfirmed_bool();
	pLcfVehProPorts->pLcfVehOutputToSenData->AbuseWarning_nu         = GET_S_DRMDAE_AbuseWarning_bool();
	pLcfVehProPorts->pLcfVehOutputToSenData->EstHandTor_nm           = GET_D_DRMHOD_EstHandTor_Nm();

	pLcfVehProPorts->pLcfVehOutputData->LaDMC_Status_nu = (unsigned_char_t)DMC_LAT_STATUS;
	if (LADMC_EPS_INTERFACE_ACTIVE_REQ == 0) /* LADMC_EPS_INTERFACE_ACTIVE_REQ range: 0..7 */
	{
		pLcfVehProPorts->pLcfVehOutputData->Lkas_ActToi_nu = (uint8)LCF_DEACTIVATE_TOI;
	}
	else
	{
		pLcfVehProPorts->pLcfVehOutputData->Lkas_ActToi_nu = (uint8)LCF_ACTIVATE_TOI;
	}
	T_LCFSND_ActToi_nu = pLcfVehProPorts->pLcfVehOutputData->Lkas_ActToi_nu;
	pLcfVehProPorts->pLcfVehOutputData->Lkas_StrToqReq_nm						= (float32)LADMC_EPS_TORQUE_REQUEST * LADMC_TRQ_RES;
	pLcfVehProPorts->pLcfVehOutputData->LaDMC_Eps_Damping_Level_Request_per	= DMC_LAT_EPS_DAMP_LVL_REQ;
	pLcfVehProPorts->pLcfVehOutputData->Lkas_ToiFlt_nu							= (uint8)LCF_NO_FAULT;
	pLcfVehProPorts->pLcfVehOutputData->Lkas_SteeringAngleRate_rps				= ((float32)LADMC_STEER_ANGLE_RATE_REQ * LADMC_STANGRATEREQ_RES) * CONV_DEG2RAD;
	pLcfVehProPorts->pLcfVehOutputData->LaKMC_CrvCmd_FF_1pm					= GET_S_TCTLGC_FFCrv_1pm();
	pLcfVehProPorts->pLcfVehOutputData->LaKMC_CrvCmd_Ctrl_1pm					= GET_S_TCTLGC_CtrlCrv_DE_1pm();
	pLcfVehProPorts->pLcfVehOutputData->LaKMC_CrvCmd_Sum_1pm					= GET_S_TCTCLM_Limiter_TgtCrv_1pm();
	pLcfVehProPorts->pLcfVehOutputData->LaKMC_QuTgtVehCtrl_nu					= 0u; /*GET_S_TCTCLM_Limiter_TgtVehCtrlQu_nu();8*/
 
#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Activation_Request_nu = LAT_Activation_Request_nu;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Activation_Request_Qf_nu = LAT_Activation_Request_Qf_nu;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Force_Shut_Off_Request = LAT_Force_Shut_Off_Request;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Steer_Angle_Command_deg = LAT_Steer_Angle_Command_deg;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Torque_Overlay_Request_nm = LAT_Torque_Overlay_Request_nm;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Stiffness_Request_per = LAT_Stiffness_Request_per;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Accuracy_Request_per = LAT_Accuracy_Request_per;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Steering_Wheel_Vibration_nu = LAT_Steering_Wheel_Vibration_nu;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Lane_Status_nu = LAT_Lane_Status_nu;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Derating_Level_Request_per = LAT_Derating_Level_Request_per;
	pLcfVehProPorts->pLcfLaDmcSocToIuc->SAC_Torque_Ramp_Factor_per = LAT_Torque_Ramp_Factor_per;	
#endif
    
/* Fill internal NVM info with corresponding outputs from LADMC */
#if defined(LCF_NVM_USED) && (LCF_NVM_USED == 1)
	for (i = 0u; i < MIN_NO_OF_ELEM(pNvmLcfInfo->AdpCorrFactorPos_nu, DMC_ADP_CORR_FACTOR_POS); i++)
	{
		pNvmLcfInfo->AdpCorrFactorPos_nu[i] =  DMC_ADP_CORR_FACTOR_POS[i];   
		pNvmLcfInfo->AdpCorrCounterPos_nu[i] = DMC_ADP_CORR_COUNTER_POS[i];
		pNvmLcfInfo->AdpCorrFactorNeg_nu[i] =  DMC_ADP_CORR_FACTOR_NEG[i];
		pNvmLcfInfo->AdpCorrCounterNeg_nu[i] = DMC_ADP_CORR_COUNTER_NEG[i];
	}
    pNvmLcfInfo->AngleOff_nu = DMC_ANGLE_OFF;
    pNvmLcfInfo->AngleOffCalibCnt_nu = DMC_ANGLE_OFF_CALIB_CNT;
#endif
/*end CopyLatDMCOutput*/
	
	pLcfVehProPorts->pLcfVehOutputToSenData->EvntDtctnVehEvents_nu[0].EventId_nu = GET_S_LCFERR_VehErrorToSen_btf();/*S_LCFERR_VehErrorToSen_btf*/
}

/* ***********************************************************************
  @fn               LCFSND_VehCommonReset */ /*!

  @brief            Reset LCFSND variables

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_VehCommonReset(void)
{
	T_LCFSND_ActToi_nu = 0u;
	
	/* L3D_ALGO_23195: Reset the output signals with default values */
	LCFSND_VehResetRTEOutputData();
    	
}

/* ***********************************************************************
  @fn               LCFSND_VehCommonProcess */ /*!

  @brief            copy global output data from computed output signals to provided ports

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_VehCommonProcess(void)
{
	
    /* Fill output signals with values from subcomponents */
	LCFSND_VehFillRTEOutputData();
}

