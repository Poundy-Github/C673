/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSNDSEN_Ext.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.3.1.6 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include <string.h>  /*memset/memcpy*/
#include "LCFSEN/LCFSEN_data.h"

/*---------------------------------------------------------*
   G L O B A L   V A R I A B L E S
**---------------------------------------------------------*/
 
/*----------------------------------------------------------*
  FUNCTION PROTOTYPES
**----------------------------------------------------------*/
static void LCFSND_SenResetRTEOutputData(void);
static void LCFSND_SenFillRTEOutputData(void);

/*---------------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**---------------------------------------------------------*/
 
   /* ***********************************************************************
  @fn               LCFSND_SenResetRTEOutputData */ /*!

  @brief            Reset global output data from computed output signals to provided ports

  @description      

  @param[in]        
  @param[out]       
  
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void LCFSND_SenResetRTEOutputData(void)
{
	(void)memset((void*)pLcfSenProPorts->pLcfSenOutputData, 0, sizeof(LCF_SenGenericOutputs_t));
	(void)memset((void*)pLcfSenProPorts->pLcfSenOutputToVehData, 0, sizeof(LCF_SenToVeh_t));
	
}
  /* ***********************************************************************
  @fn               LCFSND_SenFillRTEOutputData */ /*!

  @brief            copy global output data from computed output signals to provided ports

  @description      

  @param[in]        
  @param[out]       
  
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void LCFSND_SenFillRTEOutputData(void)
{
	uint8 i;
	uint8 ui8BitPos;
	uint8 ui8Row;
	
	pLcfSenProPorts->pLcfSenOutputToVehData->AngReqMaxLimitScale_per = 0u; /*Signal must be filled with the correct values in the Custom wrapers(by LTAMGR)*/
	pLcfSenProPorts->pLcfSenOutputToVehData->AngReqRateMaxLimitScale_per = 0u;  /*Signal must be filled with the correct values in the Custom wrapers(by LTAMGR)*/
	/*Surpress QAC Messages (next lines): This usage of a function-like macro looks like it could be replaced by an equivalent function call.
	Intentional usage of  function like macro*/
	/*PRQA S 3469 ++*/
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.LeftCorridor.CorridorChngOfCrv_1pm2		= GET_S_CSCLTA_LeCridrBndCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.LeftCorridor.CorridorCrv_1pm				= GET_S_CSCLTA_LeCridrBndCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.LeftCorridor.CorridorHeading_rad			= GET_S_CSCLTA_LeCridrBndHeadAng_rad();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.LeftCorridor.CorridorLength_m			= GET_S_CSCLTA_LeCridrBndLength_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.LeftCorridor.CorridorPosX0_m				= GET_S_CSCLTA_LeCridrBndPosX0_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.LeftCorridor.CorridorPosY0_m				= GET_S_CSCLTA_LeCridrBndPosY0_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.RightCorridor.CorridorChngOfCrv_1pm2		= GET_S_CSCLTA_RiCridrBndCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.RightCorridor.CorridorCrv_1pm			= GET_S_CSCLTA_RiCridrBndCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.RightCorridor.CorridorHeading_rad		= GET_S_CSCLTA_RiCridrBndHeadAng_rad();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.RightCorridor.CorridorLength_m			= GET_S_CSCLTA_RiCridrBndLength_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.RightCorridor.CorridorPosX0_m			= GET_S_CSCLTA_RiCridrBndPosX0_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.RightCorridor.CorridorPosY0_m			= GET_S_CSCLTA_RiCridrBndPosY0_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.TargetCorridor.CorridorChngOfCrv_1pm2	= GET_S_CSCLTA_TgtTrajCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.TargetCorridor.CorridorCrv_1pm			= GET_S_CSCLTA_TgtTrajCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.TargetCorridor.CorridorHeading_rad		= GET_S_CSCLTA_TgtTrajHeadAng_rad();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.TargetCorridor.CorridorLength_m			= GET_S_CSCLTA_TgtTrajLength_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.TargetCorridor.CorridorPosX0_m			= GET_S_CSCLTA_TgtTrajPosX0_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.AllCorridors.TargetCorridor.CorridorPosY0_m			= GET_S_CSCLTA_TgtTrajPosY0_met();

	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.LtcyComp.LtcyCompActivated_nu	= GET_S_CSCLTA_LatencyCompActivated_nu();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.LtcyComp.TimeStamp_s			= GET_S_CSCLTA_SensorTStamp_sec();

	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.Obstacle.Obstacle_AclX_mps2	= GET_S_CSCLTA_ObstacleAclX_mps2(); 
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.Obstacle.Obstacle_DistX_m		= GET_S_CSCLTA_ObstacleDistX_met();  
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.Obstacle.Obstacle_DistY_m		= GET_S_CSCLTA_ObstacleDistY_met();   
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.Obstacle.Obstacle_VelX_mps	= GET_S_CSCLTA_ObstacleVelX_mps();  
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.Obstacle.Obstacle_Width_m		= GET_S_CSCLTA_ObstacleWidth_met();   

	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.DevDistY_m				= 0.0f; /*S_CTRSC_DevDistY_met signal removed, not used anymore*/
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.DevHeading_rad			= 0.0f; /*S_CTRSC_DevHeading_rad signal removed, not used anymore*/
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.PlanningHorizon_s		= GET_S_CSCLTA_PlanningHorizon_sec();      
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.PredictionTimeCrv_s		= GET_S_CSCLTA_PredictionTimeCrv_sec();    
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.PredictionTimeHeading_s	= GET_S_CSCLTA_PredTimeHeadAng_sec();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.TrajGuiQualifier_nu		= GET_S_CSCLTA_TrajGuiQualifier_nu();    
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCalc.TriggerReplan_nu			= GET_S_CSCLTA_TriggerReplan_nu();       

	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CrvLimitation.GrdLimitTgtCrvTrajGuiCtrl_1pms	= GET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CrvLimitation.MaxCrvGrdBuildup_1pms			= GET_S_CSCLTA_MaxCrvGrdBuildup_1pms();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CrvLimitation.MaxCrvGrdReduction_1pms			= GET_S_CSCLTA_MaxCrvGrdRed_1pms();       
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CrvLimitation.MaxCrvTrajGuiCtrl_1pm			= GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm();         

	/* GeGr Mainstream : add new rte signals */
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.StrWhStifLimit_nu		= GET_S_CSCLTA_StrWhStifLimit_nu();/*ToDo: Ask if Array or scalar*/
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.StrWhStifGrad_1ps		= GET_S_CSCLTA_StrWhStifGrad_1ps();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.TrqRampGrad_1ps		= GET_S_CSCLTA_TrqRampGrad_1ps();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.MaxTrqScalLimit_nu		= GET_S_CSCLTA_MaxTrqScalLimit_nu();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.MaxTrqScalGrad_1ps		= GET_S_CSCLTA_MaxTrqScalGrad_1ps();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.HighStatAccu_nu		= GET_S_CSCLTA_HighStatAccu_bool();
   /*TODO: map to correct signals ??*/
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.RampingDownReq_nu		= 0u;
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.AngleFadingReq_nu		= 0u;
	pLcfSenProPorts->pLcfSenOutputToVehData->SpecialDrivingCorridor_nu	= 0u;

	pLcfSenProPorts->pLcfSenOutputToVehData->MaxJerkAllowed_mps3	= GET_S_CSCLTA_MaxJerkAllowed_mps3();
	
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.DistYToleranceLeftTgtArea_m	= GET_S_CSCLTA_DistYTolLeTgtArea_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.DistYToleranceRightTgtArea_m	= GET_S_CSCLTA_DistYTolRiTgtArea_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.FTireAclMax_mps2				= GET_S_CSCLTA_FTireAclMax_mps2();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.FTireAclMin_mps2				= GET_S_CSCLTA_FTireAclMin_mps2();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.TrajServiceQualifier_nu		= GET_S_CSCLTA_TrajPlanServQu_nu();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.WeightEndTime_nu				= GET_S_CSCLTA_WeightEndTime_nu();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajOptimization.WeightTgtDistY_nu			= GET_S_CSCLTA_WeightTgtDistY_nu();

	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlLimiter.LimiterActivated_nu	= GET_S_CSCLTA_LimiterActivated_nu();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlLimiter.LimiterTimeDuration_s	= GET_S_CSCLTA_LimiterTimeDuration_sec();
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlLimiter.LimiterType_nu		= GET_S_TJATVG_LimiterType_nu();
  
	pLcfSenProPorts->pLcfSenOutputToVehData->ABP_CamRawData.ABP_CamCorridorCurvature_1pm	= GET_S_ABPLBP_CntrLnClthCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputToVehData->ABP_CamRawData.ABP_CamLateralError_m			= GET_S_ABPLBP_CntrLnClthPosY0_met();
	pLcfSenProPorts->pLcfSenOutputToVehData->ABP_CamRawData.ABP_CamHeadingError_rad		= GET_S_ABPLBP_CntrLnClthHeading_rad();

	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.CrvAmp.CrvAmplificationActivated_nu	= GET_S_TJATVG_CrvAmplActivated_nu();
			
	pLcfSenProPorts->pLcfSenOutputToVehData->StraightPathDtct_nu  = GET_S_ABPLBP_StraightPathDtct_nu(); /*Add RTE signal for ABPR to Latdmc*/

	/*HMIOC*/
	pLcfSenProPorts->pLcfSenOutputData->Lkas_SysWarning_nu		= GET_S_HMIOC_SysWarning_nu();
	pLcfSenProPorts->pLcfSenOutputData->Lkas_LdwsLHWarning_nu	= GET_S_HMIOC_LdwsLHWarning_bool();
	pLcfSenProPorts->pLcfSenOutputData->Lkas_LdwsRHWarning_nu	= GET_S_HMIOC_LdwsRHWarning_bool();
	
	/*Surpress QAC Messages (next line): An expression of 'essentially Boolean' type (_Bool) is being cast to unsigned type 'unsigned char'.
	Intentional explicit cast as assignment of a essentially boolean to unsigned char variable*/
	/*PRQA S 4304 1*/
	pLcfSenProPorts->pLcfSenOutputToVehData->ActFctEnabled_nu	= GET_S_HMIOC_AvailableFunction_btf();
	pLcfSenProPorts->pLcfSenOutputToVehData->ActFctLevel_nu     = GET_S_HMIOC_ActFctLevel_nu(); 
	/*end HMIOC*/

	/* GeGr ToDo: Ask Gregor if TJASA cannot output the signal TJA_Status_nu */
	/*->TJA_Status_nu*/
	switch (GET_S_TJASTM_SysStateTJA_nu())
	{
		case (uint8)E_LCF_SYSSTATE_NOTPRESENT_nu: 
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 0U;
			break;
		}
		case (uint8)E_LCF_SYSSTATE_DISABLED_nu:
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 1U;
			break;
		}
		case (uint8)E_LCF_SYSSTATE_PASSIVE_nu:
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 2U;
			break;
		}
		case  (uint8)E_LCF_SYSSTATE_REQUEST_nu:
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 3U;
			break;
		}
		case (uint8)E_LCF_SYSSTATE_CONTROLLING_nu:
		{
			if(GET_S_TJASTM_LatCtrlMode_nu() == (uint8)E_TJASTM_LATCTRLMD_LC)
			{
				pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 4U;
			}
			else
			{
				if(GET_S_TJASTM_LatCtrlMode_nu() == (uint8)E_TJASTM_LATCTRLMD_OF)
				{
					pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 5U;
				}
				else
				{
					if(GET_S_TJASTM_LatCtrlMode_nu() == (uint8)E_TJASTM_LATCTRLMD_CMB)
					{
						pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 8U;
					}
					else
					{
						pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 10U;
					}
				}
			}
			break;
		}
		case (uint8)E_LCF_SYSSTATE_RAMPOUT_nu:
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 9U;
			break;
		}
		case (uint8)E_LCF_SYSSTATE_ERROR_nu:
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 10U;
			break;
		}
		default:
		{
			pLcfSenProPorts->pLcfSenOutputData->TJA_Status_nu = 10U;
			break;
		}
	}
	/*<-TJA_Status_nu*/

	/* GeGr ToDo: LaKMC_lane_status_nu must be provided by LDPSA */
	/* M.Kuboyama(170621) Check dangerous status for LatDMC, */
	if (GET_S_MCTLFC_ControllingFunction_nu() == (uint8)E_LCF_LDP_nu)
	{
		i = GET_S_DPLSMI_DangerousSide_nu();
	}
	else if (GET_S_MCTLFC_ControllingFunction_nu() == (uint8)E_LCF_RDP_nu)
	{
		i = GET_S_DPRSMI_DangerousSide_nu();
	}
	else if (GET_S_MCTLFC_ControllingFunction_nu() == (uint8)E_LCF_LDPOC_nu)
	{
		i = GET_S_DPOSTM_OcObjActSide_nu();
	}
	else if (GET_S_MCTLFC_ControllingFunction_nu() == (uint8)E_LCF_ALCA_nu)
	{
		i = GET_S_LCRSMI_DangerousSide_nu();
	}
	else
	{
		i = (uint8)E_LCF_DANGEROUSSIDE_NONE;
	}
     
	switch (i) 
	{
		case (uint8)E_LCF_DANGEROUSSIDE_NONE:
		{
			pLcfSenProPorts->pLcfSenOutputData->LaKMC_lane_status_nu = (uint8)LCF_NO_LANE_DEPARTURE;
			break;
		}
		case (uint8)E_LCF_DANGEROUSSIDE_LEFT:
		{
			pLcfSenProPorts->pLcfSenOutputData->LaKMC_lane_status_nu = (uint8)LCF_DEPARTING_LEFT_LANE;
			break;
		}
		case (uint8)E_LCF_DANGEROUSSIDE_RIGHT:
		{
			pLcfSenProPorts->pLcfSenOutputData->LaKMC_lane_status_nu = (uint8)LCF_DEPARTING_RIGHT_LANE;
			break;
		}
		default:
		{
			pLcfSenProPorts->pLcfSenOutputData->LaKMC_lane_status_nu = (uint8)LCF_DEPARTING_LANE_INVALID;
			break;
		}
	}
	/*end CopyLKASAOutput*/

	/*start CopyMdCtrOutput*/
	pLcfSenProPorts->pLcfSenOutputToVehData->ControllingFunction_nu	= GET_S_MCTLFC_ControllingFunction_nu();
	/*end CopyMdCtrOutput*/
	
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.CoordSysStateLCF_nu	= GET_S_CSCLTA_SysStateLCF_enum();  
    
if (GET_S_TJAGEN_LKAOnlySwitch_bool() == TRUE) /*RO 807821*/
{
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateLKA_nu = GET_S_TJASTM_SysStateTJA_nu(); 
}else
{
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateLKA_nu = (uint8)E_LCF_SYSSTATE_NOTPRESENT_nu;
}
 if (GET_S_TJAGEN_LKAOnlySwitch_bool() == TRUE) /*RO 807821*/
{
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LatCtrlModeLKA_nu		= GET_S_TJASTM_LatCtrlMode_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LatCtrlModeTJA_nu		= (uint8)E_TJASTM_LATCTRLMD_PASSIVE;  
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateTJA_nu		    = (uint8)E_LCF_SYSSTATE_NOTPRESENT_nu; 
}else
{
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LatCtrlModeTJA_nu		= GET_S_TJASTM_LatCtrlMode_nu();  
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateTJA_nu		    = GET_S_TJASTM_SysStateTJA_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LatCtrlModeLKA_nu		= (uint8)E_TJASTM_LATCTRLMD_PASSIVE;
}
	pLcfSenProPorts->pLcfSenOutputToVehData->Reserved1_nu		= GET_S_TJASTM_LatCtrlMode_nu(); /* map reserved bit to send GET_S_TJASTM_LatCtrlMode_nu to VEH*/

    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateLDW_nu		= GET_S_DPLSMW_SysStateLDW_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateLDP_nu     = GET_S_DPLSMI_SysStateLDP_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateRDP_nu     = GET_S_DPRSMI_SysStateRDP_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateLDPOC_nu	= GET_S_DPOSTM_SysStateLDPOC_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.SysStateALCA_nu	= GET_S_LCRSMI_SysStateALCA_nu();
	
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidLKA_nu	= GET_S_TJALKA_LnBndValid_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidTJA_nu	= GET_S_TJALKA_LnBndValid_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidLDW_nu	= GET_S_DPLSIA_LnBndValidLDW_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidLDP_nu	= GET_S_DPLSIA_LnBndValidLDP_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidRDP_nu	= GET_S_DPRSIA_LnBndValidRDP_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidLDPOC_nu	= GET_S_DPOSIA_LnBndValidLDPOC_nu();
    pLcfSenProPorts->pLcfSenOutputToVehData->LCF_SysCoordinator.LnBndValidALCA_nu	= GET_S_LCRSIA_LnBndValidALCA_nu();
	/*MiCr remove signal- TJAOBS not used any more in the projects*/
	/*pLcfSenProPorts->pLcfSenOutputToVehData->Reserved2_nu = GET_S_TJAOBS_OffScenarioInvalid_btf(); Send signal to LATDMC*/
  
	/*RO 891132 Function shall define the driver override capability*/
	pLcfSenProPorts->pLcfSenOutputToVehData->LCF_FCT.TrajCtrlDirect.CtrlTransitions.DeratingLevel_nu = GET_S_CSCLTA_DeratingLevel_nu();
	
	pLcfSenProPorts->pLcfSenOutputToVehData->OcObjActSide_nu = GET_S_DPOSTM_OcObjActSide_nu();
	
	pLcfSenProPorts->pLcfSenOutputToVehData->EvntDtctnSenEvents_nu[0].EventId_nu = GET_S_ABPLBP_RiLnQuality_perc();
	pLcfSenProPorts->pLcfSenOutputToVehData->EvntDtctnSenEvents_nu[1].EventId_nu = GET_S_ABPLBP_LeLnQuality_perc();
	pLcfSenProPorts->pLcfSenOutputToVehData->EvntDtctnSenEvents_nu[0].EventLifetime_nu = GET_S_ABPLBP_RiCrvQuality_perc();
	pLcfSenProPorts->pLcfSenOutputToVehData->EvntDtctnSenEvents_nu[1].EventLifetime_nu = GET_S_ABPLBP_LeCrvQuality_perc();
	
	pLcfSenProPorts->pLcfSenOutputData->Visualization.LaneValidQualVis_nu = GET_S_ABPLBP_LaneValidQualVis_nu();
	pLcfSenProPorts->pLcfSenOutputData->LaneValidQualDMC_nu = GET_S_ABPLBP_LaneValidQualDMC_nu();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.ABDTimeStamp_sec = GET_S_ABPLBP_ABDTimeStamp_sec();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftCorridor.CorridorChngOfCrv_1pm2		= GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftCorridor.CorridorCrv_1pm			= GET_S_ABPLBP_LeLnClthCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftCorridor.CorridorHeading_rad		= GET_S_ABPLBP_LeLnClthHeading_rad();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftCorridor.CorridorLength_m			= GET_S_ABPLBP_LeLnClthLength_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftCorridor.CorridorPosX0_m			= GET_S_ABPLBP_LeLnClthPosX0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftCorridor.CorridorPosY0_m			= GET_S_ABPLBP_LeLnClthPosY0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightCorridor.CorridorChngOfCrv_1pm2	= GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightCorridor.CorridorCrv_1pm			= GET_S_ABPLBP_RiLnClthCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightCorridor.CorridorHeading_rad		= GET_S_ABPLBP_RiLnClthHeading_rad();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightCorridor.CorridorLength_m			= GET_S_ABPLBP_RiLnClthLength_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightCorridor.CorridorPosX0_m			= GET_S_ABPLBP_RiLnClthPosX0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightCorridor.CorridorPosY0_m			= GET_S_ABPLBP_RiLnClthPosY0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.TargetCorridor.CorridorChngOfCrv_1pm2	= GET_S_ABPLBP_CntrLnClthCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.TargetCorridor.CorridorCrv_1pm			= GET_S_ABPLBP_CntrLnClthCrv_1pm();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.TargetCorridor.CorridorHeading_rad		= GET_S_ABPLBP_CntrLnClthHeading_rad();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.TargetCorridor.CorridorLength_m			= GET_S_ABPLBP_CntrLnClthLength_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.TargetCorridor.CorridorPosX0_m			= GET_S_ABPLBP_CntrLnClthPosX0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.TargetCorridor.CorridorPosY0_m			= GET_S_ABPLBP_CntrLnClthPosY0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftRoadEdge.CorridorChngOfCrv_1pm2		= GET_S_ABPREP_LeReClthCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftRoadEdge.CorridorCrv_1pm			= GET_S_ABPREP_LeReClthCrvSIF_1pm();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftRoadEdge.CorridorHeading_rad		= GET_S_ABPREP_LeReClthHeadingSIF_rad();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftRoadEdge.CorridorLength_m			= GET_S_ABPREP_LeReLength_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftRoadEdge.CorridorPosX0_m			= GET_S_ABPREP_LeReClthPosX0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.LeftRoadEdge.CorridorPosY0_m			= GET_S_ABPREP_LeReClthPosY0SIF_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightRoadEdge.CorridorChngOfCrv_1pm2	= GET_S_ABPREP_RiReClthCrvChng_1pm2();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightRoadEdge.CorridorCrv_1pm			= GET_S_ABPREP_RiReClthCrvSIF_1pm();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightRoadEdge.CorridorHeading_rad		= GET_S_ABPREP_RiReClthHeadingSIF_rad();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightRoadEdge.CorridorLength_m			= GET_S_ABPREP_RiReLength_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightRoadEdge.CorridorPosX0_m			= GET_S_ABPREP_RiReClthPosX0_met();
	pLcfSenProPorts->pLcfSenOutputData->Visualization.AllCorridors.RightRoadEdge.CorridorPosY0_m			= GET_S_ABPREP_RiReClthPosY0SIF_met();

	pLcfSenProPorts->pLcfSenOutputData->LCF_Stiffness_nu	= 0.0f; /*S_CSCLTA_TgtStiffTrajGuiCtrl_nu not available anymore*/
	pLcfSenProPorts->pLcfSenOutputData->LCF_Accuracy_nu	= 0.0f; /*S_CSCLTA_LatCtrlStatAccuCharc_nu not available anymore*/

	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.SteeringWheelVibrationReq_nu	= 0U; /*added for R 2.0 /MUC: Not existing in LCF yet, use default here */
	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.DrvAttWarnQualifier_nu			= GET_S_DRMDAE_SysWarning_nu(); /*GeGr: SysWarning implemented in DRVMN*/
	
	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.DFFunctActiveState_btf		= GET_S_HMIOC_DFFunctActiveState_btf();
	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.LnBndLeValid4Fct_btf		= GET_S_HMIOC_LnBndLeValid4Fct_btf();
	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.LnBndRiValid4Fct_btf		= GET_S_HMIOC_LnBndRiValid4Fct_btf();
	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.DispLaneLeftDetected_nu		= GET_S_HMIOC_DispLaneLeftDetected_nu();
	pLcfSenProPorts->pLcfSenOutputData->HMI_Out.DispLaneRightDetected_nu	= GET_S_HMIOC_DispLaneRightDetected_nu();

 if (GET_S_TJAGEN_LKAOnlySwitch_bool() == TRUE) /*RO 807821*/
{
    /*LKA*/
    pLcfSenProPorts->pLcfSenOutputData->LKASystemState_nu = GET_S_TJASTM_SysStateTJA_nu();
}	
else
{
	pLcfSenProPorts->pLcfSenOutputData->LKASystemState_nu = (uint8)E_LCF_SYSSTATE_NOTPRESENT_nu; 
}
	/*LDW*/
	pLcfSenProPorts->pLcfSenOutputData->LDWSystemState_nu = GET_S_DPLSMW_SysStateLDW_nu();
	pLcfSenProPorts->pLcfSenOutputData->LDWSystemStateLeft_nu = GET_S_DPLSMW_SysStateLDWLe_nu();
    pLcfSenProPorts->pLcfSenOutputData->LDWSystemStateRight_nu = GET_S_DPLSMW_SysStateLDWRi_nu();
    /*LDP*/
	pLcfSenProPorts->pLcfSenOutputData->LDPSystemState_nu = GET_S_DPLSMI_SysStateLDP_nu();
	pLcfSenProPorts->pLcfSenOutputData->LDPSystemStateLeft_nu =  GET_S_DPLSMI_SysStateLDPLe_nu();
    pLcfSenProPorts->pLcfSenOutputData->LDPSystemStateRight_nu = GET_S_DPLSMI_SysStateLDPRi_nu();
    /*RDP*/
	pLcfSenProPorts->pLcfSenOutputData->RDPSystemState_nu = GET_S_DPRSMI_SysStateRDP_nu();
	pLcfSenProPorts->pLcfSenOutputData->RDPSystemStateLeft_nu = GET_S_DPRSMI_SysStateRDPLe_nu();
    pLcfSenProPorts->pLcfSenOutputData->RDPSystemStateRight_nu = GET_S_DPRSMI_SysStateRDPRi_nu();
    /*RDW*/
	pLcfSenProPorts->pLcfSenOutputData->RDWSystemState_nu = GET_S_DPRSMW_SysStateRDW_nu();
	pLcfSenProPorts->pLcfSenOutputData->RDWSystemStateLeft_nu = GET_S_DPRSMW_SysStateRDWLe_nu();
    pLcfSenProPorts->pLcfSenOutputData->RDWSystemStateRight_nu = GET_S_DPRSMW_SysStateRDWRi_nu();
    /*LDPOC*/
	pLcfSenProPorts->pLcfSenOutputData->LDPOCSystemState_nu = GET_S_DPOSTM_SysStateLDPOC_nu();
	pLcfSenProPorts->pLcfSenOutputData->LDPOCSystemStateLeft_nu = GET_S_DPOSTM_SysStateLDPOCLe_nu();
    pLcfSenProPorts->pLcfSenOutputData->LDPOCSystemStateRight_nu = GET_S_DPOSTM_SysStateLDPOCRi_nu();
	/*ALCASA*/
	pLcfSenProPorts->pLcfSenOutputData->ALCASystemState_nu = GET_S_LCRSMI_SysStateALCA_nu();
	pLcfSenProPorts->pLcfSenOutputData->ALCASystemStateLeft_nu = GET_S_LCRSMI_SysStateALCALe_nu();
	pLcfSenProPorts->pLcfSenOutputData->ALCASystemStateRight_nu = GET_S_LCRSMI_SysStateALCARi_nu();
	/*AoLC TODO: fill when function is integrated*/
	pLcfSenProPorts->pLcfSenOutputData->AoLCSystemState_nu = (uint8)LCF_SYSSTATE_NOTPRESENT;
	pLcfSenProPorts->pLcfSenOutputData->AoLCSystemStateLeft_nu = (uint8)LCF_LAT_CONTROL_INVALID;
	pLcfSenProPorts->pLcfSenOutputData->AoLCSystemStateRight_nu = (uint8)LCF_LAT_CONTROL_INVALID;
   
	pLcfSenProPorts->pLcfSenOutputData->TJASystemState_nu = GET_S_TJASTM_SysStateTJA_nu();
	pLcfSenProPorts->pLcfSenOutputData->TJALatCtrlMode_nu = GET_S_TJASTM_LatCtrlMode_nu();
  
    /* HMI signals*/
	pLcfSenProPorts->pLcfSenOutputData->HapticWrnDeviceLeftReq_nu = GET_S_HMIOC_HaptWrnReqLeft_bool();
	pLcfSenProPorts->pLcfSenOutputData->HapticWrnDeviceRightReq_nu = GET_S_HMIOC_HaptWrnReqRight_bool();
	pLcfSenProPorts->pLcfSenOutputData->HapticWrnDeviceCommonReq_nu = GET_S_HMIOC_HaptWrnReqCommon_bool();
	pLcfSenProPorts->pLcfSenOutputData->VisualWrnDeviceLeftReq_nu = GET_S_HMIOC_VisWrnReqLeft_bool();
	pLcfSenProPorts->pLcfSenOutputData->VisualWrnDeviceRightReq_nu = GET_S_HMIOC_VisWrnReqRight_bool();
	pLcfSenProPorts->pLcfSenOutputData->VisualWrnDeviceCommonReq_nu = GET_S_HMIOC_VisWrnReqCommon_bool();
	pLcfSenProPorts->pLcfSenOutputData->AcousticWrnReqLeft_nu =  GET_S_HMIOC_AcWrnReqLeft_bool();
	pLcfSenProPorts->pLcfSenOutputData->AcousticWrnReqRight_nu = GET_S_HMIOC_AcWrnReqRight_bool();
	pLcfSenProPorts->pLcfSenOutputData->HandsOffSysWarning_nu = GET_S_HMIOC_HandsOffSysWarning_nu(); 

    pLcfSenProPorts->pLcfSenOutputData->AvailableFunction_nu = GET_S_HMIOC_AvailableFunction_btf();

    /*TDOD: pLcfSenProPorts->pLcfSenOutputData->AvailableFunction__bool = S_LCFSND_AvailableFunction_bool;  Add AvailableFunction__bool RTE*/

    /* Error Handler -->*/
	if (ERRIOSEN_size_ErrConfigNormData <= NUM_DEBUG_ERR_POS_NORM)
	{
        for (ui8Row = 0U; ui8Row < (NUM_DEBUG_ERR_POS_NORM/32U); ui8Row++)
        {
            pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedNorm_btf[ui8Row] = 0U;/*Refresh error info*/
        }
        for (i = 0U; i < ERRIOSEN_size_ErrConfigNormData; i++)
        {
            ui8BitPos = (uint8)(i%32u);
            ui8Row  = (uint8)(i/32u);
		    /*Surpress QAC Messages (next line): An expression of 'essentially unsigned' type (unsigned char) is being used as the  operand of this logical operator (!).
		    Use of an unsigned int as the operand of a logical operator is intentional due to faster code execution*/
		    /*PRQA S 4558,4304 1*/
            pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedNorm_btf[ui8Row] |= ((uint32)(!!(ERRIOSEN_ErrConfigNormData[i].ui8ErrorConfirmed_bool))) << ui8BitPos;
        }
	}
	else
	{
	}

	if (ERRIOSEN_size_ErrConfigVehDynData <= NUM_DEBUG_ERR_POS_VDY)
	{
        pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedVDY_btf = 0U;/*Refresh error info*/
        for (i = 0U; i < ERRIOSEN_size_ErrConfigVehDynData; i++)
        {
		    /*Surpress QAC Messages (next line): An expression of 'essentially unsigned' type (unsigned char) is being used as the  operand of this logical operator (!).
		    Use of an unsigned char as the operand of a logical operator is intentional due to faster code execution*/
		    /*PRQA S 4558,4304 1*/
            pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedVDY_btf |= (uint8)(((uint32)(!!(ERRIOSEN_ErrConfigVehDynData[i].ui8ErrorConfirmed_bool))) << (uint32)i);
        }
    }
    else
    {
    }

    if (ERRIOSEN_size_ErrConfigVehSigAddData <= NUM_DEBUG_ERR_POS_VSA)
    {
        pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedVSA_btf = 0U;/*Refresh error info*/
        for (i = 0U; i < ERRIOSEN_size_ErrConfigVehSigAddData; i++)
        {
		    /*Surpress QAC Messages (next line): An expression of 'essentially unsigned' type (unsigned char) is being used as the  operand of this logical operator (!).
		    Use of an unsigned char as the operand of a logical operator is intentional due to faster code execution*/
		    /*PRQA S 4558,4304 1*/
            pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedVSA_btf |= (uint8)(((uint32)(!!(ERRIOSEN_ErrConfigVehSigAddData[i].ui8ErrorConfirmed_bool))) << (uint32)i);
        }
    }
    else
    {
    }

    if (ERRIOSEN_size_ErrConfigVehSigMainData <= NUM_DEBUG_ERR_POS_VSM)
    {
        pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedVSM_btf = 0U;/*Refresh error info*/
        for (i = 0U; i < ERRIOSEN_size_ErrConfigVehSigMainData; i++)
        {
		    /*Surpress QAC Messages (next line): An expression of 'essentially unsigned' type (unsigned char) is being used as the  operand of this logical operator (!).
		    Use of an unsigned char as the operand of a logical operator is intentional due to faster code execution*/
		    /*PRQA S 4558,4304 1*/
            pLCFERR_SenDbgData->D_LCFERR_ErrorConfirmedVSM_btf |= (uint8)(((uint32)(!!(ERRIOSEN_ErrConfigVehSigMainData[i].ui8ErrorConfirmed_bool))) << (uint32)i);
        }
    }
    else
    {
    }
                                        
	/*S_LCFERR_SenErrorToVeh_btf*/
	pLcfSenProPorts->pLcfSenOutputToVehData->EvntDtctnSenEvents_nu[2].EventId_nu = GET_S_LCFERR_SenErrorToVeh_btf(); /*ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LATDMC]*/
    
    /* <--Error Handler */
}

 /* ***********************************************************************
  @fn               LCFSND_SenCommonReset */ /*!

  @brief            Reset LCFSND variables

  @description      

  @param[in]        
  @param[out]       
  
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_SenCommonReset(void)
{
    /* L3D_ALGO_23195: Fill output signals with default values (set by subcomponents during reset) */
	LCFSND_SenResetRTEOutputData();
}

/* ***********************************************************************
  @fn               LCFSND_SenCommonProcess */ /*!

  @brief            copy global output data from computed output signals to provided ports

  @description      

  @param[in]        
  @param[out]       
  
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_SenCommonProcess(void)
{
    /* Fill output signals with values from subcomponents */
	LCFSND_SenFillRTEOutputData();
}

