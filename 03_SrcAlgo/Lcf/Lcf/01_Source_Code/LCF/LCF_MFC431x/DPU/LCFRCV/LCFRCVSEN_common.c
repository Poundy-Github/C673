/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFRCVSEN_common.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.7 $


  ---*/ /*--- 
  CHANGES:                   $Log: LCFRCVSEN_common.c  $
  CHANGES:                   Revision 1.7 2020/02/12 13:11:11CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint 10.18
  CHANGES:                   Revision 1.6 2020/01/29 13:44:03CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate new updates
  CHANGES:                   Revision 1.5 2019/08/21 13:11:53CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.4 2019/07/31 14:13:32CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint 10.05
  CHANGES:                   Revision 1.3 2019/05/22 12:44:48CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint10
  CHANGES:                   Revision 1.1 2019/03/24 17:37:13CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:32CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/02/19 13:54:31CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/LCFRCV/project.pj

**************************************************************************** */

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"

/*---------------------------------------------------------*
   G L O B A L   V A R I A B L E S
**---------------------------------------------------------*/
volatile uint8 P_LCF_SENCopyVDY2LCFParam_bool = 1u; /*Parameter to switch between VDY and LCF values*/

static LCFRCV_SenCommonOutType LCFRCV_SenCommonOutData;

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

static void CopyLcfSenCParam(void);
static void CopyLcfSenVdyParam(void);

/*---------------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**---------------------------------------------------------*/

/* ***********************************************************************
  @fn               Get_LCFRCV_SenCommonOutPtr */ /*!

  @brief            Get pointer to LCFRCVSEN output data.

  @description      

  @param[in]        
  @param[out]       
  @return           Pointer to LCFRCVSEN output data.

  @pre              -
  @post             -
  **************************************************************************** */
const LCFRCV_SenCommonOutType* Get_LCFRCV_SenCommonOutPtr(void) { return (const LCFRCV_SenCommonOutType*) &LCFRCV_SenCommonOutData; }

/* ***********************************************************************
  @fn               LCFRCV_VehReset */ /*!

  @brief            Reset LCFRCVSEN output signals.

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFRCV_SenCommonReset(void)
{
	/* lane boundaries */
	LCFRCV_SenCommonOutData.apsLaneEvents[0]  = NULL;
	LCFRCV_SenCommonOutData.apsLaneEvents[1]  = NULL;
	
	/* velocity */
	LCFRCV_SenCommonOutData.T_LCFRCV_VehVelX_mps = 0.f;
}

/* ***********************************************************************
  @fn               LCFRCV_VehProcess */ /*!

  @brief            copy input data from required ports to generated input signals

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFRCV_SenCommonProcess(void)
{
	if (P_LCF_SENCopyVDY2LCFParam_bool == 1u)/* Copy parameters from VDY RO 1082116*/
	{
		/* Copy vehicle parameters from VDY */
		CopyLcfSenVdyParam();
	}
	else{}
    
#if defined(USE_IPC_PARAMS) && (USE_IPC_PARAMS != 0)	/*use parameters from eeprom*/
	/* copy coding parameters */
	CopyLcfSenCParam();
#endif
    
	/* lane boundaries */
	LCFRCV_SenCommonOutData.apsLaneEvents[0]  = &(pLcfSenReqPorts->pAbdOutputData->sLaneInformation.sEventLeft);
	LCFRCV_SenCommonOutData.apsLaneEvents[1]  = &(pLcfSenReqPorts->pAbdOutputData->sLaneInformation.sEventRight);
	
	/* velocity */
	LCFRCV_SenCommonOutData.T_LCFRCV_VehVelX_mps = pLcfSenReqPorts->pVehDyn->Longitudinal.Velocity;
	if (pLcfSenReqPorts->pVehDyn->MotionState.MotState == (uint8)VDY_LONG_MOT_STATE_MOVE_RWD)
	{
		LCFRCV_SenCommonOutData.T_LCFRCV_VehVelX_mps = -1.f * LCFRCV_SenCommonOutData.T_LCFRCV_VehVelX_mps;
	}
}

/* ***********************************************************************
  @fn               CopyLcfSenVdyParam */ /*!

  @brief            copy VDY parameters

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
static void CopyLcfSenVdyParam(void)
{
	uint8 uiVdyParAvailable;
	
	/* Copy VDY parameters only if they were not copied already */
	if (pFRAME_SenDbgData->uiVdyParCopied == 0u)
	{
		/* Check if at least one of the needed VDY parameters is not available */
		uiVdyParAvailable = 1u;
		#ifndef LCF_MFC431VA10 /* For VA10 this parameter is not availale */
		/* Copy parameter only if valid */
		if (pLcfSenReqPorts->pVehPar->VehParAdd.State[VEH_PAR_ADD_OVERHANG_FRONT] == VDY_IO_STATE_VALID)
		{
			/*ElNa, the parameter is constant now*/ /*P_VEH_OverhangFront_met = pLcfSenReqPorts->pVehPar->VehParAdd.OverhangFront;*/
		}
		else
		{
			uiVdyParAvailable = 0u;
		}
		#endif
		/* Copy parameter only if valid */
		if (pLcfSenReqPorts->pVehPar->VehParMain.State[VDY_PAR_POS_WBASE] == VDY_IO_STATE_VALID)
		{
			/*ElNa, the parameter is constant now*/ /*P_VEH_Wheelbase_met = pLcfSenReqPorts->pVehPar->VehParMain.WheelBase;*/
		}
		else
		{
			uiVdyParAvailable = 0u;
		}
		/* Copy parameter only if valid */
		if (pLcfSenReqPorts->pVehPar->VehParAdd.State[VEH_PAR_ADD_VEHICLE_WIDTH] == VDY_IO_STATE_VALID)
		{
			/*ElNa, the parameter is constant now*/ /*P_VEH_Width_met = pLcfSenReqPorts->pVehPar->VehParAdd.VehicleWidth;*/
		}
		else
		{
			uiVdyParAvailable = 0u;
		}
		pFRAME_SenDbgData->uiVdyParCopied = uiVdyParAvailable;
	}
}

/* ***********************************************************************
  @fn               CopyLcfSenCParam */ /*!

  @brief            copy input data from require ports to generated input signals

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
static void CopyLcfSenCParam(void)
{
	uint8 i; /*modified for R 2.0*/
	
#if (USE_IPC_PARAMS != 0)	/*TODO: remove this if after RTE CPAR data types are cleaned up*/
	/*Tunable parameters: copy only once at startup when tunable parameters are available*/
	if ((pFRAME_SenDbgData->uiTunParCopied == 0) && (pLcfSenReqPorts->pCParLdp != NULL) && (pLcfSenReqPorts->pCParLka != NULL))
	{
		if (pLcfSenReqPorts->pCParLdp.sSigHeader.eSigStatus == ((AlgoSignalState_t)AL_SIG_STATE_OK)) 
		{
		/* Copy parameters for LDP */
			for (i = 0; i < MIN_NO_OF_ELEM(P_MCTLFC_PriorityVector_nu, pLcfSenReqPorts->pCParLdp->P_MCTLFC_PriorityVector_nu); i++)
			{
				P_MCTLFC_PriorityVector_nu[i] = pLcfSenReqPorts->pCParLdp->P_MCTLFC_PriorityVector_nu[i];
			}
			P_DPLTVG_RampOutDuration_sec		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_RampOutDuration_sec;
			P_DPLSMI_ControllingMaxDuration_sec	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_ControllingMaxDuration_sec;
			P_DPLSMI_HazardCancelTol_met		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_HazardCancelTol_met;
			P_DPLSMI_NoHazardCancelTol_met		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_NoHazardCancelTol_met;
			P_DPLSMI_HazardFinishTol_met		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_HazardFinishTol_met;
			P_DPLSMI_NoHazardFinishTol_met		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_NoHazardFinishTol_met;
			P_DPLSMI_OnTargetFinishTime_sec		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_OnTargetFinishTime_sec;
			P_DPLSMI_TargetLateralHeading_rad	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_TargetLateralHeading_rad;
			P_DPLSMI_HeadAngThresMax_rad		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_HeadAngThresMax_rad;
			P_DPLSMI_HeadAngThresMin_rad		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_HeadAngThresMin_rad;
			P_DPLSMI_LaneWidthHyst_met			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_LaneWidthHyst_met;
			P_DPLSMI_LaneWidthMax_met			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_LaneWidthMax_met;
			P_DPLSMI_LaneWidthMin_met			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_LaneWidthMin_met;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMI_VXCrvThresMax_1pm, pLcfSenReqPorts->pCParLdp->Y_DPLSTM_VXCrvThresMax_1pm); i++)
			{
				Y_DPLSMI_VXCrvThresMax_1pm[i]		= pLcfSenReqPorts->pCParLdp->Y_DPLSTM_VXCrvThresMax_1pm[i];
			}
			P_DPLSMI_TriggerCondEnable_btm = pLcfSenReqPorts->pCParLdp->P_DPLSTM_TriggerCondEnable_btm;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMI_LWTrigDlcScalFact_nu, pLcfSenReqPorts->pCParLdp->Y_DPLSTM_LWTrigDlcScalFact_nu); i++)
			{
				Y_DPLSMI_LWTrigDlcScalFact_nu[i]	= pLcfSenReqPorts->pCParLdp->Y_DPLSTM_LWTrigDlcScalFact_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMI_LWTrigTlcScalFact_nu, pLcfSenReqPorts->pCParLdp->Y_DPLSTM_LWTrigTlcScalFact_nu); i++)
			{
				Y_DPLSMI_LWTrigTlcScalFact_nu[i]	= pLcfSenReqPorts->pCParLdp->Y_DPLSTM_LWTrigTlcScalFact_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMI_VXMD1TrigDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPLSTM_VXMD1TrigDlc_met); i++)
			{
				Y_DPLSMI_VXMD1TrigDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPLSTM_VXMD1TrigDlc_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMI_VXMD2TrigDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPLSTM_VXMD2TrigDlc_met); i++)
			{
				Y_DPLSMI_VXMD2TrigDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPLSTM_VXMD2TrigDlc_met[i];
			}
			P_DPLSMI_BlockingTimeDuration_sec	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_BlockingTimeDuration_sec;
			P_DPLSMI_TurnSignHoldingTime_sec	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_TurnSignHoldingTime_sec;
			P_DPLSMI_StrWhlAngleHyst_deg		= pLcfSenReqPorts->pCParLdp->P_DPLSTM_StrWhlAngleHyst_deg;
			P_DPLSMI_StrWhlAngleMax_deg			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_StrWhlAngleMax_deg;
			P_DPLSMI_StrWhlAngleMin_deg			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_StrWhlAngleMin_deg;
			P_DPLSMI_StrWhlAngSpeedHyst_degps	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_StrWhlAngSpeedHyst_degps;
			P_DPLSMI_StrWhlAngSpeedMax_degps	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_StrWhlAngSpeedMax_degps;
			P_DPLSMI_StrWhlAngSpeedMin_degps	= pLcfSenReqPorts->pCParLdp->P_DPLSTM_StrWhlAngSpeedMin_degps;
			P_DPLSMI_VelVehDispHyst_kph			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_VelVehDispHyst_kph;
			P_DPLSMI_VelVehDispMax_kph			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_VelVehDispMax_kph;
			P_DPLSMI_VelVehDispMin_kph			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_VelVehDispMin_kph;
			P_LDP_Existing_nu					= pLcfSenReqPorts->pCParLdp->P_LDP_Existing_nu;
			/*P_VEH_Width_met						= pLcfSenReqPorts->pCParLdp->P_VEH_Width_met; -ClPr: parameter copied from VDY now*/
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLTTG_LWTargetLatDist_met, pLcfSenReqPorts->pCParLdp->Y_DPLTTG_LWTargetLatDist_met); i++)
			{
				Y_DPLTTG_LWTargetLatDist_met[i] = pLcfSenReqPorts->pCParLdp->Y_DPLTTG_LWTargetLatDist_met[i];
			}
			P_DPLTVG_FTireAclMax_mps2					= pLcfSenReqPorts->pCParLdp->P_DPLTVG_FTireAclMax_mps2;
			P_DPLTVG_FTireAclMin_mps2					= pLcfSenReqPorts->pCParLdp->P_DPLTVG_FTireAclMin_mps2;
			P_DPLTVG_PlanningHorizon_sec				= pLcfSenReqPorts->pCParLdp->P_DPLTVG_PlanningHorizon_sec;
			P_DPLTVG_PredTimeCrv_sec					= pLcfSenReqPorts->pCParLdp->P_DPLTVG_PredTimeCrv_sec;
			P_DPLTVG_PredTimeHeadAng_sec				= pLcfSenReqPorts->pCParLdp->P_DPLTVG_PredTimeHeadAng_sec;
			P_DPLTVG_TgtStiffMaxVehVel_mps				= pLcfSenReqPorts->pCParLdp->P_DPLTVG_TgtStiffMaxVehVel_mps;
			P_DPLTVG_TgtStiffMaxVehVelFactor_nu			= pLcfSenReqPorts->pCParLdp->P_DPLTVG_TgtStiffMaxVehVelFactor_nu;
			P_DPLTVG_TgtStiffMinVehVel_mps				= pLcfSenReqPorts->pCParLdp->P_DPLTVG_TgtStiffMinVehVel_mps;
			P_DPLTVG_TgtStiffMinVehVelFactor_nu 		= pLcfSenReqPorts->pCParLdp->P_DPLTVG_TgtStiffMinVehVelFactor_nu;
			P_DPLTVG_TgtStiffUseVehVel_nu				= pLcfSenReqPorts->pCParLdp->P_DPLTVG_TgtStiffUseVehVel_nu;
			P_DPLTVG_TrajPlanServQu_nu					= pLcfSenReqPorts->pCParLdp->P_DPLTVG_TrajPlanServQu_nu;
			P_DPLTVG_UseAdvancedStiffnessAndAccuracy_nu = pLcfSenReqPorts->pCParLdp->P_DPLTVG_UseAdvancedStiffnessAndAccuracy_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(P_DPLTVG_VehGuiCtrlDeadTime_sec, pLcfSenReqPorts->pCParLdp->P_DPLTVG_VehGuiCtrlDeadTime_sec); i++)
			{
				P_DPLTVG_VehGuiCtrlDeadTime_sec[i] = pLcfSenReqPorts->pCParLdp->P_DPLTVG_VehGuiCtrlDeadTime_sec[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(P_DPLTVG_VehGuiCtrlFTireVel_mps, pLcfSenReqPorts->pCParLdp->P_DPLTVG_VehGuiCtrlFTireVel_mps); i++)
			{
				P_DPLTVG_VehGuiCtrlFTireVel_mps[i] = pLcfSenReqPorts->pCParLdp->P_DPLTVG_VehGuiCtrlFTireVel_mps[i];
			}
			P_DPLTVG_WeightEndtime_nu			= pLcfSenReqPorts->pCParLdp->P_DPLTVG_WeightEndtime_nu;
			P_DPLTVG_WeightTgtDistY_nu			= pLcfSenReqPorts->pCParLdp->P_DPLTVG_WeightTgtDistY_nu;
			P_DPLTVG_RampInDuration_sec			= pLcfSenReqPorts->pCParLdp->P_DPLSTM_RampInDuration_sec;
			P_DPLSMW_ControllingMaxDuration_sec = pLcfSenReqPorts->pCParLdp->P_DPWSTM_ControllingMaxDuration_sec;
			P_DPLSMW_HazardCancelTol_met		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_HazardCancelTol_met;
			P_DPLSMW_NoHazardCancelTol_met		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_NoHazardCancelTol_met;
			P_DPLSMW_HazardFinishTol_met		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_HazardFinishTol_met;
			P_DPLSMW_NoHazardFinishTol_met		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_NoHazardFinishTol_met;
			P_DPLSMW_OnTargetFinishTime_sec		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_OnTargetFinishTime_sec;
			P_DPLSMW_LaneWidthHyst_met			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_LaneWidthHyst_met;
			P_DPLSMW_LaneWidthMax_met			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_LaneWidthMax_met;
			P_DPLSMW_LaneWidthMin_met			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_LaneWidthMin_met;
			P_DPLSMW_TriggerCondEnable_btm		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_TriggerCondEnable_btm;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMW_LWTrigDlcScalFact_nu, pLcfSenReqPorts->pCParLdp->Y_DPWSTM_LWTrigDlcScalFact_nu); i++)
			{
				Y_DPLSMW_LWTrigDlcScalFact_nu[i]	= pLcfSenReqPorts->pCParLdp->Y_DPWSTM_LWTrigDlcScalFact_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMW_VXMD1TrigDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPWSTM_VXMD1TrigDlc_met); i++)
			{
				Y_DPLSMW_VXMD1TrigDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPWSTM_VXMD1TrigDlc_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPLSMW_VXMD2TrigDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPWSTM_VXMD2TrigDlc_met); i++)
			{
				Y_DPLSMW_VXMD2TrigDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPWSTM_VXMD2TrigDlc_met[i];
			}
			P_DPLSMW_BlockingTimeDuration_sec	= pLcfSenReqPorts->pCParLdp->P_DPWSTM_BlockingTimeDuration_sec;
			P_DPLSMW_TurnSignHoldingTime_sec	= pLcfSenReqPorts->pCParLdp->P_DPWSTM_TurnSignHoldingTime_sec;
			P_DPLSMW_StrWhlAngleHyst_deg		= pLcfSenReqPorts->pCParLdp->P_DPWSTM_StrWhlAngleHyst_deg;
			P_DPLSMW_StrWhlAngleMax_deg			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_StrWhlAngleMax_deg;
			P_DPLSMW_StrWhlAngleMin_deg			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_StrWhlAngleMin_deg;
			P_DPLSMW_StrWhlAngSpeedHyst_degps	= pLcfSenReqPorts->pCParLdp->P_DPWSTM_StrWhlAngSpeedHyst_degps;
			P_DPLSMW_StrWhlAngSpeedMax_degps	= pLcfSenReqPorts->pCParLdp->P_DPWSTM_StrWhlAngSpeedMax_degps;
			P_DPLSMW_StrWhlAngSpeedMin_degps	= pLcfSenReqPorts->pCParLdp->P_DPWSTM_StrWhlAngSpeedMin_degps;
			P_DPLSMW_VelVehDispHyst_kph			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_VelVehDispHyst_kph;
			P_DPLSMW_VelVehDispMax_kph			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_VelVehDispMax_kph;
			P_DPLSMW_VelVehDispMin_kph			= pLcfSenReqPorts->pCParLdp->P_DPWSTM_VelVehDispMin_kph;
			P_LDW_Existing_nu					= pLcfSenReqPorts->pCParLdp->P_LDW_Existing_nu;
			P_DPRTVG_RampOutDuration_sec		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_RampOutDuration_sec;
			P_DPRSTM_ControllingMaxDuration_sec	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_ControllingMaxDuration_sec;
			P_DPRSTM_HazardCancelTol_met		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_HazardCancelTol_met;
			P_DPRSTM_NoHazardCancelTol_met		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_NoHazardCancelTol_met;
			P_DPRSTM_HazardFinishTol_met		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_HazardFinishTol_met;
			P_DPRSTM_NoHazardFinishTol_met		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_NoHazardFinishTol_met;
			P_DPRSTM_OnTargetFinishTime_sec		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_OnTargetFinishTime_sec;
			P_DPRSTM_TargetLateralHeading_rad	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_TargetLateralHeading_rad;
			P_DPRSTM_LnHeadAngThresHyst_rad		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_LnHeadAngThresHyst_rad;
			P_DPRSTM_LnHeadAngThresMax_rad		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_LnHeadAngThresMax_rad;
			P_DPRSTM_LnHeadAngThresMin_rad		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_LnHeadAngThresMin_rad;
			P_DPRSTM_ReHeadAngThresHyst_rad		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_ReHeadAngThresHyst_rad;
			P_DPRSTM_ReHeadAngThresMax_rad		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_ReHeadAngThresMax_rad;
			P_DPRSTM_ReHeadAngThresMin_rad		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_ReHeadAngThresMin_rad;
			P_DPRSTM_RoadBitmask_btm			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_RoadBitmask_btm;
			P_DPRSTM_LnMarkRoadEdgeDist_met		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_LnMarkRoadEdgeDist_met;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPRSTM_LWTrigDlcScalFact_nu, pLcfSenReqPorts->pCParLdp->Y_DPRSTM_LWTrigDlcScalFact_nu); i++)
			{
				Y_DPRSTM_LWTrigDlcScalFact_nu[i]	= pLcfSenReqPorts->pCParLdp->Y_DPRSTM_LWTrigDlcScalFact_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPRSTM_VXMD1TrigDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXMD1TrigDlc_met); i++)
			{
				Y_DPRSTM_VXMD1TrigDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXMD1TrigDlc_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPRSTM_VXMD2TrigDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXMD2TrigDlc_met); i++)
			{
				Y_DPRSTM_VXMD2TrigDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXMD2TrigDlc_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPRSTM_VXTrigDrc_met, pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXTrigDrc_met); i++)
			{
				Y_DPRSTM_VXTrigDrc_met[i]			= pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXTrigDrc_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPRSTM_VXTrigDrcDlc_met, pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXTrigDrcDlc_met); i++)
			{
				Y_DPRSTM_VXTrigDrcDlc_met[i]		= pLcfSenReqPorts->pCParLdp->Y_DPRSTM_VXTrigDrcDlc_met[i];
			}
			P_DPRSTM_BlockingTimeDuration_sec	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_BlockingTimeDuration_sec;
			P_DPRSTM_TurnSignHoldingTime_sec	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_TurnSignHoldingTime_sec;
			P_DPRSTM_StrWhlAngleHyst_deg		= pLcfSenReqPorts->pCParLdp->P_DPRSTM_StrWhlAngleHyst_deg;
			P_DPRSTM_StrWhlAngleMax_deg			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_StrWhlAngleMax_deg;
			P_DPRSTM_StrWhlAngleMin_deg			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_StrWhlAngleMin_deg;
			P_DPRSTM_StrWhlAngSpeedHyst_degps	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_StrWhlAngSpeedHyst_degps;
			P_DPRSTM_StrWhlAngSpeedMax_degps	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_StrWhlAngSpeedMax_degps;
			P_DPRSTM_StrWhlAngSpeedMin_degps	= pLcfSenReqPorts->pCParLdp->P_DPRSTM_StrWhlAngSpeedMin_degps;
			P_DPRSTM_VelVehDispHyst_kph			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_VelVehDispHyst_kph;
			P_DPRSTM_VelVehDispMax_kph			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_VelVehDispMax_kph;
			P_DPRSTM_VelVehDispMin_kph			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_VelVehDispMin_kph;
			P_RDP_Existing_nu					= pLcfSenReqPorts->pCParLdp->P_RDP_Existing_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_DPRTTG_LWTargetLatDist_met, pLcfSenReqPorts->pCParLdp->Y_DPRTTG_LWTargetLatDist_met); i++)
			{
				Y_DPRTTG_LWTargetLatDist_met[i] = pLcfSenReqPorts->pCParLdp->Y_DPRTTG_LWTargetLatDist_met[i];
			}
			P_DPRTVG_CrvGrdMaxValueForLimiter_1pms		= pLcfSenReqPorts->pCParLdp->P_DPRTVG_CrvGrdMaxValueForLimiter_1pms;
			P_DPRTVG_CrvMaxValueForLimiter_1pm			= pLcfSenReqPorts->pCParLdp->P_DPRTVG_CrvMaxValueForLimiter_1pm;
			P_DPRTVG_DistYTolLeTgtArea_met				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_DistYTolLeTgtArea_met;
			P_DPRTVG_DistYTolRiTgtArea_met				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_DistYTolRiTgtArea_met;
			P_DPRTVG_FTireAccelMax_mps2					= pLcfSenReqPorts->pCParLdp->P_DPRTVG_FTireAclMax_mps2;
			P_DPRTVG_FTireAccelMin_mps2					= pLcfSenReqPorts->pCParLdp->P_DPRTVG_FTireAclMin_mps2;
			P_DPRTVG_PlanningHorizon_sec				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_PlanningHorizon_sec;
			P_DPRTVG_PredTimeCrv_sec					= pLcfSenReqPorts->pCParLdp->P_DPRTVG_PredTimeCrv_sec;
			P_DPRTVG_PredTimeHeadAng_sec				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_PredTimeHeadAng_sec;
			P_DPRTVG_TgtStiffMaxVehVel_mps				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_TgtStiffMaxVehVel_mps;
			P_DPRTVG_TgtStiffMaxVehVelFactor_nu			= pLcfSenReqPorts->pCParLdp->P_DPRTVG_TgtStiffMaxVehVelFactor_nu;
			P_DPRTVG_TgtStiffMinVehVel_mps				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_TgtStiffMinVehVel_mps;
			P_DPRTVG_TgtStiffMinVehVelFactor_nu			= pLcfSenReqPorts->pCParLdp->P_DPRTVG_TgtStiffMinVehVelFactor_nu;
			P_DPRTVG_TgtStiffUseVehVel_nu				= pLcfSenReqPorts->pCParLdp->P_DPRTVG_TgtStiffUseVehVel_nu;
			P_DPRTVG_TrajPlanServQu_nu					= pLcfSenReqPorts->pCParLdp->P_DPRTVG_TrajPlanServQu_nu;
			P_DPRTVG_UseAdvancedStiffnessAndAccuracy_nu	= pLcfSenReqPorts->pCParLdp->P_DPRTVG_UseAdvancedStiffnessAndAccuracy_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(P_DPRTVG_VehGuiCtrlDeadTime_sec, pLcfSenReqPorts->pCParLdp->P_DPRTVG_VehGuiCtrlDeadTime_sec); i++)
			{
				P_DPRTVG_VehGuiCtrlDeadTime_sec[i] = pLcfSenReqPorts->pCParLdp->P_DPRTVG_VehGuiCtrlDeadTime_sec[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(P_DPRTVG_VehGuiCtrlFTireVel_mps, pLcfSenReqPorts->pCParLdp->P_DPRTVG_VehGuiCtrlFTireVel_mps); i++)
			{
				P_DPRTVG_VehGuiCtrlFTireVel_mps[i] = pLcfSenReqPorts->pCParLdp->P_DPRTVG_VehGuiCtrlFTireVel_mps[i];
			}
			P_DPRTVG_WeightEndtime_nu			= pLcfSenReqPorts->pCParLdp->P_DPRTVG_WeightEndtime_nu;
			P_DPRTVG_WeightTgtDistY_nu			= pLcfSenReqPorts->pCParLdp->P_DPRTVG_WeightTgtDistY_nu;
			P_DPRTVG_RampInDuration_sec			= pLcfSenReqPorts->pCParLdp->P_DPRSTM_RampInDuration_sec;
			P_HMOHMC_VelVehXMax_kph				= pLcfSenReqPorts->pCParLdp->P_HMOHMC_VelVehXMax_kph;
			P_HMOHMC_VelVehXMin_kph				= pLcfSenReqPorts->pCParLdp->P_HMOHMC_VelVehXMin_kph;
			P_HMOHMC_WarningHoldTime_sec		= pLcfSenReqPorts->pCParLdp->P_HMOHMC_WarningHoldTime_sec;
			P_HSCHDA_CyclesToActFlags			= pLcfSenReqPorts->pCParLdp->P_HSCHDA_CyclesToActFlags;
			P_HSCHDA_SpeedLimitMaxHyst_kph		= pLcfSenReqPorts->pCParLdp->P_HSCHDA_SpeedLimitMaxHyst_kph;
			P_HSCHDA_SpeedLimitMaxIncrease_kph	= pLcfSenReqPorts->pCParLdp->P_HSCHDA_SpeedLimitMaxIncrease_kph;
			P_HSCHDA_SpeedLimitMax_kph			= pLcfSenReqPorts->pCParLdp->P_HSCHDA_SpeedLimitMax_kph;
			P_HSCHDA_SpeedLimitMinHyst_kph		= pLcfSenReqPorts->pCParLdp->P_HSCHDA_SpeedLimitMinHyst_kph;
			P_HSCHDA_SpeedLimitMin_kph			= pLcfSenReqPorts->pCParLdp->P_HSCHDA_SpeedLimitMin_kph;
			P_HSCHLC_MaxValidManTrqHyst_nm		= pLcfSenReqPorts->pCParLdp->P_HSCHLC_MaxValidManTrqHyst_nm;
			P_HSCHLC_MaxValidManTrq_nm			= pLcfSenReqPorts->pCParLdp->P_HSCHLC_MaxValidManTrq_nm;
		}  
		
		if (pLcfSenReqPorts->pCParLdp.sSigHeader.eSigStatus == ((AlgoSignalState_t)AL_SIG_STATE_OK)) 
		{		
			/* Copy parameters for LKA */
			P_LKASTM_BlockTimeLKA_sec		= pLcfSenReqPorts->pCParLka->P_LKASTM_BlockTimeLKA_sec;
			P_LKASTM_DistVeh2LnBndHyst_met	= pLcfSenReqPorts->pCParLka->P_LKASTM_DistVeh2LnBndHyst_met;
			P_LKASTM_DistVeh2LnBndMin_met	= pLcfSenReqPorts->pCParLka->P_LKASTM_DistVeh2LnBndMin_met;
			P_LKASTM_DrvVehStInvalidBT_btm	= pLcfSenReqPorts->pCParLka->P_LKASTM_DrvVehStInvalidBT_btm;
			P_LKASTM_LaneWidthHyst_met		= pLcfSenReqPorts->pCParLka->P_LKASTM_LaneWidthHyst_met;
			P_LKASTM_LaneWidthMax_met		= pLcfSenReqPorts->pCParLka->P_LKASTM_LaneWidthMax_met;
			P_LKASTM_LaneWidthMin_met		= pLcfSenReqPorts->pCParLka->P_LKASTM_LaneWidthMin_met;
			P_LKASTM_MaxHeadAngActnLKA_rad	= pLcfSenReqPorts->pCParLka->P_LKASTM_MaxHeadAngActnLKA_rad;
			/*P_LKASTM_TrigDegrAftTorTime_sec = pLcfSenReqPorts->pCParLka->P_LKASTM_TrigDegrAftTorTime_sec; -ClPr: signal not available anymore*/
			C_LKA_Available_bool			= pLcfSenReqPorts->pCParLka->C_LKA_Available_bool;
			/*C_LKA_DebHorAfterHandsOff_sec = pLcfSenReqPorts->pCParLka->C_LKA_DebHorAfterHandsOff_sec; -ClPr: signal not available anymore*/
			/*C_LKA_DebHorAfterHOActnLim_sec = pLcfSenReqPorts->pCParLka->C_LKA_DebHorAfterHOActnLim_sec; -ClPr: signal not available anymore*/
			/*C_LKA_DebHorAfterHOSwitchLim_sec = pLcfSenReqPorts->pCParLka->C_LKA_DebHorAfterHOSwitchLim_sec; -ClPr: signal not available anymore*/
			/*C_LKA_DebounceTorAfterHor_sec = pLcfSenReqPorts->pCParLka->C_LKA_DebounceTorAfterHor_sec; -ClPr: signal not available anymore*/
			C_LKA_VelXHyst_mps				= pLcfSenReqPorts->pCParLka->C_LKA_VelXHyst_mps;
			C_LKA_VelXMax_mps				= pLcfSenReqPorts->pCParLka->C_LKA_VelXMax_mps;
			for (i = 0; i < MIN_NO_OF_ELEM(X_LKATVG_RedFact_LnWidth_met, pLcfSenReqPorts->pCParLka->X_LKATVG_RedFact_LnWidth_met); i++)
			{
				X_LKATVG_RedFact_LnWidth_met[i]		= pLcfSenReqPorts->pCParLka->X_LKATVG_RedFact_LnWidth_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_LKATVG_RedFact_TgtTrjLen_met, pLcfSenReqPorts->pCParLka->X_LKATVG_RedFact_TgtTrjLen_met); i++)
			{
				X_LKATVG_RedFact_TgtTrjLen_met[i]	= pLcfSenReqPorts->pCParLka->X_LKATVG_RedFact_TgtTrjLen_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_LKATVG_VehVelX_RedFact_mps, pLcfSenReqPorts->pCParLka->X_LKATVG_VehVelX_RedFact_mps); i++)
			{
				X_LKATVG_VehVelX_RedFact_mps[i]		= pLcfSenReqPorts->pCParLka->X_LKATVG_VehVelX_RedFact_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_LKATVG_Gain_TgtTrjPosYHead_nu, pLcfSenReqPorts->pCParLka->Y_LKATVG_Gain_TgtTrjPosYHead_nu); i++)
			{
				Y_LKATVG_Gain_TgtTrjPosYHead_nu[i]	= pLcfSenReqPorts->pCParLka->Y_LKATVG_Gain_TgtTrjPosYHead_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_LKATVG_RedFact_LnWidth_nu, pLcfSenReqPorts->pCParLka->Y_LKATVG_RedFact_LnWidth_nu); i++)
			{
				Y_LKATVG_RedFact_LnWidth_nu[i]		= pLcfSenReqPorts->pCParLka->Y_LKATVG_RedFact_LnWidth_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_LKATVG_RedFact_TgtTrjLen_nu, pLcfSenReqPorts->pCParLka->Y_LKATVG_RedFact_TgtTrjLen_nu); i++)
			{
				Y_LKATVG_RedFact_TgtTrjLen_nu[i]	= pLcfSenReqPorts->pCParLka->Y_LKATVG_RedFact_TgtTrjLen_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_LKATVG_RedFact_Vel_nu, pLcfSenReqPorts->pCParLka->Y_LKATVG_RedFact_Vel_nu); i++)
			{
				Y_LKATVG_RedFact_Vel_nu[i]			= pLcfSenReqPorts->pCParLka->Y_LKATVG_RedFact_Vel_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_LKATVG_ScalRedFactTTL_Vel_nu, pLcfSenReqPorts->pCParLka->Y_LKATVG_ScalRedFactTTL_Vel_nu); i++)
			{
				Y_LKATVG_ScalRedFactTTL_Vel_nu[i]	= pLcfSenReqPorts->pCParLka->Y_LKATVG_ScalRedFactTTL_Vel_nu[i];
			}
			P_LKATVG_DistYToleranceLeftTgtArea_met	= pLcfSenReqPorts->pCParLka->P_LKATVG_DistYToleranceLeftTgtArea_met;
			P_LKATVG_DistYToleranceRightTgtArea_met	= pLcfSenReqPorts->pCParLka->P_LKATVG_DistYToleranceRightTgtArea_met;
			P_LKATVG_FTireAccelMax_mps2				= pLcfSenReqPorts->pCParLka->P_LKATVG_FTireAccelMax_mps2;
			P_LKATVG_FTireAccelMin_mps2				= pLcfSenReqPorts->pCParLka->P_LKATVG_FTireAccelMin_mps2;
			P_LKATVG_LatCtrlStatAccuCharc_nu		= pLcfSenReqPorts->pCParLka->P_LKATVG_LatCtrlStatAccuCharc_nu;
			P_LKATVG_LimiterMaxCrv_1pm				= pLcfSenReqPorts->pCParLka->P_LKATVG_LimiterMaxCrv_1pm;
			P_LKATVG_LimiterMaxCrvGrd_1pms			= pLcfSenReqPorts->pCParLka->P_LKATVG_LimiterMaxCrvGrd_1pms;
			P_LKATVG_MaxCrvScaling_nu				= pLcfSenReqPorts->pCParLka->P_LKATVG_MaxCrvScaling_nu;
			P_LKATVG_MaxSteeringAngle_deg			= pLcfSenReqPorts->pCParLka->P_LKATVG_MaxSteeringAngle_deg;
			P_LKATVG_MinFactorCrvGrd_nu				= pLcfSenReqPorts->pCParLka->P_LKATVG_MinFactorCrvGrd_nu;
			P_LKATVG_NormRefHeadAngEgo_deg			= pLcfSenReqPorts->pCParLka->P_LKATVG_NormRefHeadAngEgo_deg;
			P_LKATVG_NormRefPosYEgo_met				= pLcfSenReqPorts->pCParLka->P_LKATVG_NormRefPosYEgo_met;
			/*P_LKATVG_PlanningHorizonVal_sec = pLcfSenReqPorts->pCParLka->P_LKATVG_PlanningHorizonVal_sec; -ClPr: signal not available anymore*/
			P_LKATVG_PredictionTimeCrv_sec			= pLcfSenReqPorts->pCParLka->P_LKATVG_PredictionTimeCrv_sec;
			P_LKATVG_PredTimeHeadAng_sec			= pLcfSenReqPorts->pCParLka->P_LKATVG_PredTimeHeadAng_sec;
			P_LKATVG_TgtStiffTrajGuiCtrl_nu			= pLcfSenReqPorts->pCParLka->P_LKATVG_TgtStiffTrajGuiCtrl_nu;
			P_LKATVG_TrajPlanValServQu_nu			= pLcfSenReqPorts->pCParLka->P_LKATVG_TrajPlanValServQu_nu;
			P_LKATVG_WeightEndtime_nu				= pLcfSenReqPorts->pCParLka->P_LKATVG_WeightEndtime_nu;
			P_LKATVG_WeightTgtDistY_nu				= pLcfSenReqPorts->pCParLka->P_LKATVG_WeightTgtDistY_nu;
			/*P_VEH_Wheelbase_met						= pLcfSenReqPorts->pCParLka->P_VEH_Wheelbase_met; -ClPr: parameter copied from VDY now*/
			C_LCF_AclXHyst_mps2						= pLcfSenReqPorts->pCParLka->C_LCF_AclXHyst_mps2;
			C_LCF_AclXMax_mps2						= pLcfSenReqPorts->pCParLka->C_LCF_AclXMax_mps2;
			C_LCF_AclXMin_mps2						= pLcfSenReqPorts->pCParLka->C_LCF_AclXMin_mps2;
			C_LCF_AclYHyst_mps2						= pLcfSenReqPorts->pCParLka->C_LCF_AclYHyst_mps2;
			C_LCF_AclYMax_mps2						= pLcfSenReqPorts->pCParLka->C_LCF_AclYMax_mps2;
			P_VDPDRV_ManTrqOvrrdMaxTrq_Nm			= pLcfSenReqPorts->pCParLka->C_LCF_MaxManualTrqOverride_Nm;
			P_VDPDRV_ManTrqOvrrdTrnOnTm_sec			= pLcfSenReqPorts->pCParLka->P_VDPDRV_DebTimeManOverride_sec;
			P_VDPDRV_MaxVelLimStrngStp_mps			= pLcfSenReqPorts->pCParLka->P_VDPDRV_MaxVelLimStrngStp_mps;
			P_VDPDRV_ThStrngStpDtctd_rad			= pLcfSenReqPorts->pCParLka->P_VDPDRV_ThStrngStpDtctd_rad;
			P_VDPDRV_ThStrngStpNotDtctd_rad			= pLcfSenReqPorts->pCParLka->P_VDPDRV_ThStrngStpNotDtctd_rad;
			P_ABPLBP_AllOneSidLnCtrActv_bool		= pLcfSenReqPorts->pCParLka->P_ABPLBP_AllOneSidLnCtrActv_bool;
			P_ABPLBP_AllowUnltdBridging_bool		= pLcfSenReqPorts->pCParLka->P_ABPLBP_AllowUnltdBridging_bool;
			/*P_ABPLBP_BufferAvLnWidthSz_nu = pLcfSenReqPorts->pCParLka->P_ABPLBP_BufferAvLnWidthSz_nu; -ClPr: signal not available anymore*/
			P_ABPLBP_CrvLimStepDtct_1pm				= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvLimStepDtct_1pm;
			P_ABPLBP_DistTrigExRaDtct_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_DistTrigExRaDtct_met;
			P_ABPLBP_DistYLimitStepDtct_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_DistYLimitStepDtct_met;
			P_ABPLBP_DurValidCrvHeadStep_sec		= pLcfSenReqPorts->pCParLka->P_ABPLBP_DurValidCrvHeadStep_sec;
			P_ABPLBP_DurValidDistY_sec				= pLcfSenReqPorts->pCParLka->P_ABPLBP_DurValidDistY_sec;
			P_ABPLBP_DurValidNewCorr_sec			= pLcfSenReqPorts->pCParLka->P_ABPLBP_DurValidNewCorr_sec;
			P_ABPLBP_HeadLimDurOneSiDtct_rad		= pLcfSenReqPorts->pCParLka->P_ABPLBP_HeadLimDurOneSiDtct_rad;
			P_ABPLBP_HeadLimStepDtct_rad			= pLcfSenReqPorts->pCParLka->P_ABPLBP_HeadLimStepDtct_rad;
			P_ABPLBP_InvalDistExRaDtct_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_InvalDistExRaDtct_met;
			/*P_ABPLBP_InvalDistPedXDtct_met = pLcfSenReqPorts->pCParLka->P_ABPLBP_InvalDistPedXDtct_met; -ClPr: signal not available anymore*/
			/*P_ABPLBP_LnBoundMaxHeadDev_rad = pLcfSenReqPorts->pCParLka->P_ABPLBP_LnBoundMaxHeadDev_rad; -ClPr: signal not available anymore*/
			P_ABPLBP_LnDtctMaxCrvHyst_1pm			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LnDtctMaxCrvHyst_1pm;
			P_ABPLBP_LnDtctMaxCrv_1pm				= pLcfSenReqPorts->pCParLka->P_ABPLBP_LnDtctMaxCrv_1pm;
			P_ABPLBP_LnDtctMinExistProb_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LnDtctMinExistProb_nu;
			P_ABPLBP_LnExProbPT1Active_bool			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LnExProbPT1Active_bool;
			P_ABPLBP_LnExProbPT1TConst_sec			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LnExProbPT1TConst_sec;
			P_ABPLBP_MaxHeadingHyst_rad				= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxHeadingHyst_rad;
			P_ABPLBP_MaxHeading_rad					= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxHeading_rad;
			P_ABPLBP_MaxLaneWidthHyst_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxLaneWidthHyst_met;
			P_ABPLBP_MaxLaneWidth_met				= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxLaneWidth_met;
			/*P_ABPLBP_MaxPedXVelocity_mps	= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxPedXVelocity_mps; -ClPr: signal not available anymore*/
			P_ABPLBP_MinExRaEventQuality_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_MinExRaEventQuality_nu;
			P_ABPLBP_MinLaneWidthHyst_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_MinLaneWidthHyst_met;
			P_ABPLBP_MinLaneWidth_met				= pLcfSenReqPorts->pCParLka->P_ABPLBP_MinLaneWidth_met;
			/*P_ABPLBP_MinPedXQuality_nu	= pLcfSenReqPorts->pCParLka->P_ABPLBP_MinPedXQuality_nu; -ClPr: signal not available anymore*/
			P_ABPLBP_MnDistYDurOneSiDtct_met		= pLcfSenReqPorts->pCParLka->P_ABPLBP_MnDistYDurOneSiDtct_met;
			P_ABPLBP_MxBridgDistOneSided_met		= pLcfSenReqPorts->pCParLka->P_ABPLBP_MxBridgDistOneSided_met;
			P_ABPLBP_MxDistYDurOneSiDtct_met		= pLcfSenReqPorts->pCParLka->P_ABPLBP_MxDistYDurOneSiDtct_met;
			P_ABPLBP_TolRangeDistY_met				= pLcfSenReqPorts->pCParLka->P_ABPLBP_TolRangeDistY_met;
			P_ABPLBP_TolRangeNewCorr_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_TolRangeNewCorr_met;
			/*P_ABPLBP_UseAverageLnWidth_met	= pLcfSenReqPorts->pCParLka->P_ABPLBP_UseAverageLnWidth_met; -ClPr: signal not available anymore*/
			P_ABPLBP_ValidLnTypeBitmask_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_ValidLnTypeBitmask_nu;
			P_ABPLBP_ValidTBefOneSiAllow_sec		= pLcfSenReqPorts->pCParLka->P_ABPLBP_ValidTBefOneSiAllow_sec;
			for (i	= 0; i < MIN_NO_OF_ELEM(X_ABPLBP_ThLnClthMinValLen_mps, pLcfSenReqPorts->pCParLka->X_ABPLBP_ThLnClthMinValLen_mps); i++)
			{
				X_ABPLBP_ThLnClthMinValLen_mps[i]	= pLcfSenReqPorts->pCParLka->X_ABPLBP_ThLnClthMinValLen_mps[i];
			}
			for (i	= 0; i < MIN_NO_OF_ELEM(Y_ABPLBP_ThLnClthMinValLen_met, pLcfSenReqPorts->pCParLka->Y_ABPLBP_ThLnClthMinValLen_met); i++)
			{
				Y_ABPLBP_ThLnClthMinValLen_met[i]	= pLcfSenReqPorts->pCParLka->Y_ABPLBP_ThLnClthMinValLen_met[i];
			}
			P_ABPREP_CrvLimStepDtct_1pm			= pLcfSenReqPorts->pCParLka->P_ABPREP_CrvLimStepDtct_1pm;
			P_ABPREP_DistYLimitStepDtct_met		= pLcfSenReqPorts->pCParLka->P_ABPREP_DistYLimitStepDtct_met;
			P_ABPREP_DurValidCrvHeadStep_sec	= pLcfSenReqPorts->pCParLka->P_ABPREP_DurValidCrvHeadStep_sec;
			P_ABPREP_DurValidDistYStep_sec		= pLcfSenReqPorts->pCParLka->P_ABPREP_DurValidDistYStep_sec;
			P_ABPREP_HeadLimStepDtct_rad		= pLcfSenReqPorts->pCParLka->P_ABPREP_HeadLimStepDtct_rad;
			P_ABPREP_MaxHeading_rad				= pLcfSenReqPorts->pCParLka->P_ABPREP_MaxHeading_rad;
			P_ABPREP_ReBoundMaxHeadDev_rad		= pLcfSenReqPorts->pCParLka->P_ABPREP_ReBoundMaxHeadDev_rad;
			P_ABPREP_ReDtctMaxCrvHyst_1pm		= pLcfSenReqPorts->pCParLka->P_ABPREP_ReDtctMaxCrvHyst_1pm;
			P_ABPREP_ReDtctMaxCrv_1pm			= pLcfSenReqPorts->pCParLka->P_ABPREP_ReDtctMaxCrv_1pm;
			P_ABPREP_ReDtctMinExistProb_nu		= pLcfSenReqPorts->pCParLka->P_ABPREP_ReDtctMinExistProb_nu;
			P_ABPREP_ReExProbPT1Active_bool		= pLcfSenReqPorts->pCParLka->P_ABPREP_ReExProbPT1Active_bool;
			P_ABPREP_ReExProbPT1TConst_sec		= pLcfSenReqPorts->pCParLka->P_ABPREP_ReExProbPT1TConst_sec;
			for (i	= 0; i < MIN_NO_OF_ELEM(Y_ABPREP_ThReClthMinValLen_met, pLcfSenReqPorts->pCParLka->Y_ABPREP_ThReClthMinValLen_met); i++)
			{
				Y_ABPREP_ThReClthMinValLen_met[i]	= pLcfSenReqPorts->pCParLka->Y_ABPREP_ThReClthMinValLen_met[i];
			}
			P_ABPLBP_CrvKFErrCoeff1_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFErrCoeff1_nu;
			P_ABPLBP_CrvKFErrCoeff2_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFErrCoeff2_nu;
			P_ABPLBP_CrvKFInitRFactor_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFInitRFactor_nu;
			P_ABPLBP_CrvKFDegradeWeight_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFDegradeWeight_nu;
			P_ABPLBP_CrvKFLowQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFLowQual_nu;
			P_ABPLBP_CrvKFMidQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFMidQual_nu;
			P_ABPLBP_CrvKFIncQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFIncQual_nu;
			P_ABPLBP_CrvKFDecQualDegrade_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFDecQualDegrade_nu;
			P_ABPLBP_CrvKFDecQualPredict_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFDecQualPredict_nu;
			P_ABPLBP_CrvKFQ11Fac_nu				= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFQ11Fac_nu;
			P_ABPLBP_CrvKFDefCurve_1pm			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvKFDefCurve_1pm;
			P_ABPLBP_LaneKFErrCoeff1_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFErrCoeff1_nu;
			P_ABPLBP_LaneKFErrCoeff2_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFErrCoeff2_nu;
			P_ABPLBP_LaneKFInitRFactor_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFInitRFactor_nu;
			P_ABPLBP_LaneKFDegradeWeight_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFDegradeWeight_nu;
			P_ABPLBP_LaneKFLowQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFLowQual_nu;
			P_ABPLBP_LaneKFMidQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFMidQual_nu;
			P_ABPLBP_LaneKFIncQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFIncQual_nu;
			P_ABPLBP_LaneKFDecQualDegrade_nu	= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFDecQualDegrade_nu;
			P_ABPLBP_LaneKFDecQualPredict_nu	= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFDecQualPredict_nu;
			P_ABPLBP_LaneKFKGainFac_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFKGainFac_nu;
			P_ABPLBP_LaneKFDynYawFactor_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFDynYawFactor_nu;
			P_ABPLBP_laneKFLeErrCoeff1_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_laneKFLeErrCoeff1_nu;
			P_ABPLBP_laneKFLeErrCoeff2_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_laneKFLeErrCoeff2_nu;
			P_ABPLBP_laneKFLeInitRFactor_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_laneKFLeInitRFactor_nu;
			P_ABPLBP_laneKFLeDegradeWeight_nu	= pLcfSenReqPorts->pCParLka->P_ABPLBP_laneKFLeDegradeWeight_nu;
			P_ABPLBP_laneKFLeLowQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_laneKFLeLowQual_nu;
			P_ABPLBP_LaneKFLeMidQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFLeMidQual_nu;
			P_ABPLBP_LaneKFLeIncQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFLeIncQual_nu;
			P_ABPLBP_LaneKFLeDecQualDeg_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFLeDecQualDeg_nu;
			P_ABPLBP_LaneKFLeKGainFac_nu		= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFLeKGainFac_nu;
			P_ABPLBP_LaneKFLeDynYawFactor_nu	= pLcfSenReqPorts->pCParLka->P_ABPLBP_LaneKFLeDynYawFactor_nu;
			P_ABPLBP_SigmaMediumQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaMediumQual_nu;
			P_ABPLBP_SigmaLowQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaLowQual_nu;
			P_ABPLBP_SigmaHighQual_nu			= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaHighQual_nu;
			P_ABPLBP_SigmaHeadingTol_rad		= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaHeadingTol_rad;
			P_ABPLBP_SigmaDistYTol_met			= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaDistYTol_met;
			P_ABPLBP_SigmaCrvTol_1pm			= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaCrvTol_1pm;
			P_ABPLBP_SigmaCrvChngTol_1pm2		= pLcfSenReqPorts->pCParLka->P_ABPLBP_SigmaCrvChngTol_1pm2;
			P_ABPLBP_MinKalmanQuality_perc		= (uint8)pLcfSenReqPorts->pCParLka->P_ABPLBP_MinKalmanQuality_perc;
			P_ABPLBP_UseLaneKalmanFilt_bool		= pLcfSenReqPorts->pCParLka->P_ABPLBP_UseLaneKalmanFilt_bool;
			P_ABPLBP_ManualExRaCheckT_sec		= pLcfSenReqPorts->pCParLka->P_ABPLBP_ManualExRaCheckT_sec;
			P_ABPLBP_CrvFiltStart_1pm			= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvFiltStart_1pm;
			P_ABPLBP_CrvFiltEnd_1pm				= pLcfSenReqPorts->pCParLka->P_ABPLBP_CrvFiltEnd_1pm;
			P_ABPLBP_LowPassTime_sec			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LowPassTime_sec;
			P_ABPLBP_HighPassTime_sec			= pLcfSenReqPorts->pCParLka->P_ABPLBP_HighPassTime_sec;
			P_ABPLBP_LDJumpCheckT_sec			= pLcfSenReqPorts->pCParLka->P_ABPLBP_LDJumpCheckT_sec;
			P_ABPLBP_ManualExRaCheckT_sec		= pLcfSenReqPorts->pCParLka->P_ABPLBP_ManualExRaCheckT_sec;
			P_ABPLBP_MaxCrvChngGrad_1psm2		= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxCrvChngGrad_1psm2;
			P_ABPLBP_MaxCrvGrad_1pms			= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxCrvGrad_1pms;
			P_ABPLBP_MaxDistYGrad_mps			= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxDistYGrad_mps;
			P_ABPLBP_MaxHeadingGrad_radps		= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxHeadingGrad_radps;
			P_ABPLBP_MaxLaneWidthGrad_mps		= pLcfSenReqPorts->pCParLka->P_ABPLBP_MaxLaneWidthGrad_mps;
			P_ABPLBP_PT1LaneWidthTConst_sec		= pLcfSenReqPorts->pCParLka->P_ABPLBP_PT1LaneWidthTConst_sec;
			P_ABPLBP_PedExDtctTime_sec			= pLcfSenReqPorts->pCParLka->P_ABPLBP_PedExDtctTime_sec;
			P_ABPLBP_TimeLnWidthValFBrd_sec		= pLcfSenReqPorts->pCParLka->P_ABPLBP_TimeLnWidthValFBrd_sec;
			P_ABPLBP_IgnCrvChngStdDev_bool		= pLcfSenReqPorts->pCParLka->P_ABPLBP_IgnCrvChngStdDev_bool;
			P_ABPLBP_InvalLeftLane_bool			= pLcfSenReqPorts->pCParLka->P_ABPLBP_InvalLeftLane_bool;
			P_ABPLBP_InvalRightLane_bool		= pLcfSenReqPorts->pCParLka->P_ABPLBP_InvalRightLane_bool;
			P_ABPLBP_MinPedExEventQuality_nu	= pLcfSenReqPorts->pCParLka->P_ABPLBP_MinPedExEventQuality_nu;
			P_ABPLBP_UseGradLim_bool			= pLcfSenReqPorts->pCParLka->P_ABPLBP_UseGradLim_bool;
			P_ABPREP_DefaultRoadWidth_met		= pLcfSenReqPorts->pCParLka->P_ABPREP_DefaultRoadWidth_met;
			P_ABPREP_MaxCrvChngGrad_1psm2		= pLcfSenReqPorts->pCParLka->P_ABPREP_MaxCrvChngGrad_1psm2;
			P_ABPREP_MaxCrvGrad_1pms			= pLcfSenReqPorts->pCParLka->P_ABPREP_MaxCrvGrad_1pms;
			P_ABPREP_MaxDistYGrad_mps			= pLcfSenReqPorts->pCParLka->P_ABPREP_MaxDistYGrad_mps;
			P_ABPREP_MaxHeadingGrad_radps		= pLcfSenReqPorts->pCParLka->P_ABPREP_MaxHeadingGrad_radps;
			P_ABPREP_ValidReTypeBitmask_nu		= pLcfSenReqPorts->pCParLka->P_ABPREP_ValidReTypeBitmask_nu;
		}
	    /* Ensure tunable parameters are copied only once at startup, in order to have them tunable via XCP during runtime*/
        pFRAME_SenDbgData->uiTunParCopied	= 1u;
	}
#endif
}
 
