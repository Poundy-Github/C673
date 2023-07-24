/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFRCVVEH_common.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.2.1.5 $


  ---*/ /*--- 
  CHANGES:                   $Log: LCFRCVVEH_common.c  $
  CHANGES:                   Revision 1.2.1.5 2020/07/31 12:26:56CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   new updates
  CHANGES:                   Revision 1.2.1.4 2020/07/15 14:58:39CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   new updates
  CHANGES:                   Revision 1.2.1.3 2020/01/29 13:44:03CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate new updates
  CHANGES:                   Revision 1.2.1.2 2019/08/21 13:11:52CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.2.1.1 2019/07/12 15:48:03CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Fix compiler warnings
  CHANGES:                   Revision 1.2 2019/05/22 12:44:49CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint10
  CHANGES:                   Revision 1.1 2019/03/24 17:37:15CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:33CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/02/19 13:54:32CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/LCFRCV/project.pj

**************************************************************************** */

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include <string.h> /*memcpy used*/
#include "LCFVEH/LCFVEH_data.h"

/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/
#define LCF_MIRROR_OFFSET_MET    (0.25f)

/*---------------------------------------------------------*
   G L O B A L   V A R I A B L E S
**---------------------------------------------------------*/
volatile uint8 P_LCF_VEHCopyVDY2LCFParam_bool = 1u; /*Parameter to switch between VDY and LCF values*/
static LCFRCV_VehCommonOutType LCFRCV_VehCommonOutData;

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

static void CopyLcfVehCParam(void);
static void CopyLcfVehVdyParam(void);

/*---------------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**---------------------------------------------------------*/

/* ***********************************************************************
  @fn               Get_LCFRCV_VehCommonOutPtr */ /*!

  @brief            Get pointer to LCFRCVVEH output data.

  @description      

  @param[in]        
  @param[out]       
  @return           Pointer to LCFRCVVEH output data.

  @pre              -
  @post             -
  **************************************************************************** */
const LCFRCV_VehCommonOutType* Get_LCFRCV_VehCommonOutPtr(void) { return (const LCFRCV_VehCommonOutType*) &LCFRCV_VehCommonOutData; }

/* ***********************************************************************
  @fn               LCFRCV_VehCommonReset */ /*!

  @brief            Reset LCFRCV variables

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFRCV_VehCommonReset(void)
{
    uint8 i;
    
	LCFRCV_VehCommonOutData.T_LCFRCV_VehVelX_mps = 0.f;
#if defined(LCF_NVM_USED) && (LCF_NVM_USED == 1)
	/* L3D_ALGO_26005: Copy NVM data from NVM buffer to internal one */
    if (pLcfVehReqPorts->pNvmLcfData->sSigHeader.eSigStatus == (uint8)AL_SIG_STATE_OK)
    {
        (void)memcpy((void*)(pNvmLcfInfo), (const void*)pLcfVehReqPorts->pNvmLcfData, CML_Min(sizeof(*pNvmLcfInfo),sizeof(*(pLcfVehReqPorts->pNvmLcfData))));
        pFRAME_VehDbgData->uiNvmDataValid = 1u;
    }
    else
    {
        /* In case of invalid inputs a fall back to the default values shall occur */
        for (i = 0; i < LCF_NUM_ELEM_ADP_CORR_ARR; i++)
        {
            pNvmLcfInfo->AdpCorrFactorPos_nu[i]   = (uint8)LADMC_ADP_CORR_FCT_POS_DEF;   
            pNvmLcfInfo->AdpCorrCounterPos_nu[i]  = (uint8)LADMC_ADP_CORR_CNT_POS_DEF;
            pNvmLcfInfo->AdpCorrFactorNeg_nu[i]   = (uint8)LADMC_ADP_CORR_FCT_NEG_DEF;
            pNvmLcfInfo->AdpCorrCounterNeg_nu[i]  = (uint8)LADMC_ADP_CORR_CNT_NEG_DEF;
        }
        pNvmLcfInfo->AngleOff_nu          = (sint16)LADMC_ANG_OFF_DEF;
        pNvmLcfInfo->AngleOffCalibCnt_nu  = (uint16)LADMC_ANG_OFF_CAL_CNT_DEF;
        pFRAME_VehDbgData->uiNvmDataValid = 0u;
    }	
#endif
}

/* ***********************************************************************
  @fn               LCFRCV_VehCommonProcess */ /*!

  @brief            copy input data from required ports to generated input signals

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFRCV_VehCommonProcess(void)
{
	if (P_LCF_VEHCopyVDY2LCFParam_bool == 1u)/* Copy parameters from VDY RO 1082116*/
	{
		/* Copy vehicle parameters from VDY */
		CopyLcfVehVdyParam();
	}
	else{}
	
#if defined(USE_IPC_PARAMS) && (USE_IPC_PARAMS != 0)	/*use parameters from eeprom*/
	/* copy coding parameters */
	CopyLcfVehCParam();
#endif
    
	/* velocity */
	LCFRCV_VehCommonOutData.T_LCFRCV_VehVelX_mps = (pLcfVehReqPorts->pVehDyn->Longitudinal.Velocity);

	if (pLcfVehReqPorts->pVehDyn->MotionState.MotState == (uint8)VDY_LONG_MOT_STATE_MOVE_RWD)
	{
		/* velocity is negative when moving backwards */
		LCFRCV_VehCommonOutData.T_LCFRCV_VehVelX_mps = -1.f * LCFRCV_VehCommonOutData.T_LCFRCV_VehVelX_mps;
	}
	else
	{
	}
}

/* ***********************************************************************
  @fn               CopyLcfVehVdyParam */ /*!

  @brief            copy VDY parameters

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */  
static void CopyLcfVehVdyParam(void)
{
    uint8 uiVdyParAvailable;

	/* Copy VDY parameters only if they were not copied already */
	if (pFRAME_VehDbgData->uiVdyParCopied == 0u)
	{
		/* Check if at least one of the needed VDY parameters is not available */
		uiVdyParAvailable = 1u;
		/* Copy parameter only if valid */
		if (pLcfVehReqPorts->pVehPar->VehParAdd.State[VEH_PAR_ADD_VEHICLE_LENGTH] == VDY_IO_STATE_VALID)
		{
			#if (USE_PARAMSfromVDY ==1u)
			P_VEH_Length_met = pLcfVehReqPorts->pVehPar->VehParAdd.VehicleLength;
			#else
			//P_VEH_Length_met = pLcfVehReqPorts->pVehPar->VehParAdd.VehicleLength;
		    #endif
		}
		else
		{
			uiVdyParAvailable = 0u;
		}
		/* Copy parameter only if valid */
		if (pLcfVehReqPorts->pVehPar->VehParAdd.State[VEH_PAR_ADD_VEHICLE_WIDTH] == VDY_IO_STATE_VALID)
		{
			#if (USE_PARAMSfromVDY ==1u)
			P_VEH_WidthWithMirrors_met = pLcfVehReqPorts->pVehPar->VehParAdd.VehicleWidth + LCF_MIRROR_OFFSET_MET; /* VDY parameter does not include mirrors ;used by TRJPLN*/
			#else
			//P_VEH_WidthWithMirrors_met = pLcfVehReqPorts->pVehPar->VehParAdd.VehicleWidth + LCF_MIRROR_OFFSET_MET; /* VDY parameter does not include mirrors ;used by TRJPLN*/
			#endif
		}
		else
		{
			uiVdyParAvailable = 0u;
		}
		pFRAME_VehDbgData->uiVdyParCopied = uiVdyParAvailable;
	}
}

/* ***********************************************************************
  @fn               CopyLcfVehCParam */ /*!

  @brief            copy input data from required ports to initialize coding parameters

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
static void CopyLcfVehCParam(void)
{
#if (USE_IPC_PARAMS != 0)	/*TODO: remove this if after RTE CPAR data types are cleaned up*/
	/*Tunable parameters: copy only once at startup when tunable parameters are available*/
	if ((pFRAME_VehDbgData->uiTunParCopied == 0u) && (pLcfVehReqPorts->pCParKmc != NULL) && (pLcfVehReqPorts->pCParDmc != NULL))
	{
		if( pLcfVehReqPorts->pCParKmc->sSigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK )
		{
			/* Copy parameters for KMC */ /*TODO: action of sizeof input is not equal to sizeof actual parameters*/
			P_TPLFBT_TgtCrvSwitch_nu = pLcfVehReqPorts->pCParKmc->P_TPLFBT_TgtCrvSwitch_nu;
			P_TPLCEN_DrvTqrReplanEnable_nu = pLcfVehReqPorts->pCParKmc->P_TPLCEN_DrvTqrReplanEnable_nu;
			P_TPLCEN_ErrDistY_met = pLcfVehReqPorts->pCParKmc->P_TPLCEN_ErrDistY_met;
			P_TPLCEN_ErrHeadAglPrev_rad = pLcfVehReqPorts->pCParKmc->P_TPLCEN_ErrHeadAglPrev_rad;
			P_TPLCEN_ManualTrqImpuls_Nm = pLcfVehReqPorts->pCParKmc->P_TPLCEN_ManualTrqImpuls_Nm;
			P_TPLCEN_ManualTrqTime_sec = pLcfVehReqPorts->pCParKmc->P_TPLCEN_ManualTrqTime_sec;
			P_TPLCEN_ParamInternal_nu = pLcfVehReqPorts->pCParKmc->P_TPLCEN_ParamInternal_nu;
			P_TPLCEN_PlanTgtValueSwitch_nu = pLcfVehReqPorts->pCParKmc->P_TPLCEN_PlanTgtValueSwitch_nu;
			P_TPLCEN_RelTrigCustFctRplCur_nu = pLcfVehReqPorts->pCParKmc->P_TPLCEN_RelTrigCustFctRplCur_nu;
			P_TPLCEN_TrajPlanEnable_nu = pLcfVehReqPorts->pCParKmc->P_TPLCEN_TrajPlanEnable_nu;
			P_TPLCEN_CyCTimeTrajCalc_sec = pLcfVehReqPorts->pCParKmc->P_TPLCEN_CyCTimeTrajCalc_sec;
			P_TPLCEN_CycEnable_nu = pLcfVehReqPorts->pCParKmc->P_TPLCEN_CycEnable_nu;
			P_TPLTJC_ColldetActive_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_ColldetActive_nu;
			P_TPLTJC_MaxArcLength_met = pLcfVehReqPorts->pCParKmc->P_TPLTJC_MaxArcLength_met;
			P_TPLTJC_NumCircles_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_NumCircles_nu;
			P_TPLTJC_ParamCostFctInternal_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_ParamCostFctInternal_nu;
			P_TPLTJC_TMax_sec = pLcfVehReqPorts->pCParKmc->P_TPLTJC_TMax_nu;
			P_TPLTJC_TimeTrajEndEnable_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_TimeTrajEndEnable_nu;
			P_TPLTJC_WeightDistBased_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_WeightDistBased_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TPLTJC_WghtTgtDistYCharact_nu, pLcfVehReqPorts->pCParKmc->Y_TPLTJC_WghtTgtDistYCharact_nu); i++)
			{
				Y_TPLTJC_WghtTgtDistYCharact_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TPLTJC_WghtTgtDistYCharact_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TPLTJC_WghtTgtDistYCustFct_nu, pLcfVehReqPorts->pCParKmc->X_TPLTJC_WghtTgtDistYCustFct_nu); i++)
			{
				X_TPLTJC_WghtTgtDistYCustFct_nu[i] = pLcfVehReqPorts->pCParKmc->X_TPLTJC_WghtTgtDistYCustFct_nu[i];
			}
			P_TPLTJC_WeightTgtDistY_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_WeightTgtDistY_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TPLTJC_WghtTgtTimeCharact_nu, pLcfVehReqPorts->pCParKmc->Y_TPLTJC_WghtTgtTimeCharact_nu); i++)
			{
				Y_TPLTJC_WghtTgtTimeCharact_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TPLTJC_WghtTgtTimeCharact_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TPLTJC_WghtTgtTimeCustFct_nu, pLcfVehReqPorts->pCParKmc->X_TPLTJC_WghtTgtTimeCustFct_nu); i++)
			{
				X_TPLTJC_WghtTgtTimeCustFct_nu[i] = pLcfVehReqPorts->pCParKmc->X_TPLTJC_WghtTgtTimeCustFct_nu[i];
			}
			P_TPLTJC_WeightTgtTime_nu = pLcfVehReqPorts->pCParKmc->P_TPLTJC_WeightTgtTime_nu;
			P_TPLCEN_VMinTimeBasedTraj_kph = pLcfVehReqPorts->pCParKmc->P_TPLCEN_VMinTimeBasedTraj_kph;
			P_TPLLCO_PreviewDistXEnable_nu = pLcfVehReqPorts->pCParKmc->P_TPLLCO_PreviewDistXEnable_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(X_TPLLCO_VehVelX_mps, pLcfVehReqPorts->pCParKmc->X_TPLLCO_VehVelX_mps); i++)
			{
				X_TPLLCO_VehVelX_mps[i] = pLcfVehReqPorts->pCParKmc->X_TPLLCO_VehVelX_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TPLLCO_PreviewDistX_met, pLcfVehReqPorts->pCParKmc->Y_TPLLCO_PreviewDistX_met); i++)
			{
				Y_TPLLCO_PreviewDistX_met[i] = pLcfVehReqPorts->pCParKmc->Y_TPLLCO_PreviewDistX_met[i];
			}
			P_TCTLGC_CrvDifftoZeroSW_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_CrvDifftoZeroSW_nu;
			P_TCTLGC_CrvErrCorrTime_sec = pLcfVehReqPorts->pCParKmc->P_TCTLGC_CrvErrCorrTime_sec;
			P_TCTLGC_CrvErrorD_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_CrvErrorD_nu;
			P_TCTLGC_CrvErrorI_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_CrvErrorI_nu;
			P_TCTLGC_CrvErrorILimit_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_CrvErrorILimit_nu;
			P_TCTLGC_CrvErrorP_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_CrvErrorP_nu;
			P_TCTLGC_DistYGain_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_DistYGain_nu;
			P_TCTLGC_DTTCFunction_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_DTTCFunction_nu;
			P_TCTLGC_FactorDistYFromErrY_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_FactorDistYFromErrY_nu;
			P_TCTLGC_FactorHeadFromDistY_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_FactorHeadFromDistY_nu;
			P_TCTLGC_FlxOverallGainEnable_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_FlxOverallGainEnable_nu;
			P_TCTLGC_HeadingGain_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_HeadingGain_nu;
			P_TCTLGC_LateralCrvBeta_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_LateralCrvBeta_nu;
			P_TCTLGC_LateralErrorAlpha_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_LateralErrorAlpha_nu;
			P_TCTLGC_LateralErrorILimit_met = pLcfVehReqPorts->pCParKmc->P_TCTLGC_LateralErrorILimit_met;
			P_TCTLGC_LateralOffset_met = pLcfVehReqPorts->pCParKmc->P_TCTLGC_LateralOffset_met;
			P_TCTLGC_LCFControllerEnable_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_LCFControllerEnable_nu;
			P_TCTLGC_MaximumCorrDist_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_MaximumCorrDist_nu;
			P_TCTLGC_MaximumCrv_1pm = pLcfVehReqPorts->pCParKmc->P_TCTLGC_MaximumCrv_1pm;
			P_TCTLGC_MinimumCorrDist_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_MinimumCorrDist_nu;
			P_TCTLGC_MinimumCrv_1pm = pLcfVehReqPorts->pCParKmc->P_TCTLGC_MinimumCrv_1pm;
			P_TCTLGC_OverallGain_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_OverallGain_nu;
			P_TCTLGC_PT1FilterCorrDist_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_PT1FilterCorrDist_nu;
			P_TCTLGC_SpeedThreshold_mps = pLcfVehReqPorts->pCParKmc->P_TCTLGC_SpeedThreshold_mps;
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_Curve_1pm, pLcfVehReqPorts->pCParKmc->X_TCTLGC_Curve_1pm); i++)
			{
				X_TCTLGC_Curve_1pm[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_Curve_1pm[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_DTTC_met, pLcfVehReqPorts->pCParKmc->X_TCTLGC_DTTC_met); i++)
			{
				X_TCTLGC_DTTC_met[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_DTTC_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_DTTCTBVelX_mps, pLcfVehReqPorts->pCParKmc->X_TCTLGC_DTTCTBVelX_mps); i++)
			{
				X_TCTLGC_DTTCTBVelX_mps[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_DTTCTBVelX_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_FactorCrvDistY_nu, pLcfVehReqPorts->pCParKmc->X_TCTLGC_FactorCrvDistY_nu); i++)
			{
				X_TCTLGC_FactorCrvDistY_nu[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_FactorCrvDistY_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_FactorCrvHead_nu, pLcfVehReqPorts->pCParKmc->X_TCTLGC_FactorCrvHead_nu); i++)
			{
				X_TCTLGC_FactorCrvHead_nu[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_FactorCrvHead_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_OverallGainVelX_mps, pLcfVehReqPorts->pCParKmc->X_TCTLGC_OverallGainVelX_mps); i++)
			{
				X_TCTLGC_OverallGainVelX_mps[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_OverallGainVelX_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTLGC_Vel_mps, pLcfVehReqPorts->pCParKmc->X_TCTLGC_Vel_mps); i++)
			{
				X_TCTLGC_Vel_mps[i] = pLcfVehReqPorts->pCParKmc->X_TCTLGC_Vel_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_DistYGain_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DistYGain_nu); i++)
			{
				Y_TCTLGC_DistYGain_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DistYGain_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_DTTCGain_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DTTCGain_nu); i++)
			{
				Y_TCTLGC_DTTCGain_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DTTCGain_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_DTTCTBTime_sec, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DTTCTBTime_sec); i++)
			{
				Y_TCTLGC_DTTCTBTime_sec[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DTTCTBTime_sec[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FactorCrvCurveDistY_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvCurveDistY_nu); i++)
			{
				Y_TCTLGC_FactorCrvCurveDistY_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvCurveDistY_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FactorCrvCurveHead_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvCurveHead_nu); i++)
			{
				Y_TCTLGC_FactorCrvCurveHead_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvCurveHead_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FactorCrvDistY_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvDistY_nu); i++)
			{
				Y_TCTLGC_FactorCrvDistY_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvDistY_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FactorCrvDistYLKA_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvDistYLKA_nu); i++)
			{
				Y_TCTLGC_FactorCrvDistYLKA_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvDistYLKA_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FactorCrvHead_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvHead_nu); i++)
			{
				Y_TCTLGC_FactorCrvHead_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvHead_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FactorCrvHeadLKA_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvHeadLKA_nu); i++)
			{
				Y_TCTLGC_FactorCrvHeadLKA_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FactorCrvHeadLKA_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_FlxOverallGain_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FlxOverallGain_nu); i++)
			{
				Y_TCTLGC_FlxOverallGain_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_FlxOverallGain_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_HeadingGain_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_HeadingGain_nu); i++)
			{
				Y_TCTLGC_HeadingGain_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_HeadingGain_nu[i];
			}
			P_TCTCDC_PT1CurDistYEnable_nu = pLcfVehReqPorts->pCParKmc->P_TCTCDC_PT1CurDistYEnable_nu;
			P_TCTCDC_PT1CurDistYTime_sec = pLcfVehReqPorts->pCParKmc->P_TCTCDC_PT1CurDistYTime_sec;
			P_TCTCDC_PT1CurHeadingEnable_nu = pLcfVehReqPorts->pCParKmc->P_TCTCDC_PT1CurHeadingEnable_nu;
			P_TCTCDC_PT1CurHeadingTime_sec = pLcfVehReqPorts->pCParKmc->P_TCTCDC_PT1CurHeadingTime_sec;
			P_TCTCDC_PT1DevHeadingEnable_nu = pLcfVehReqPorts->pCParKmc->P_TCTCDC_PT1DevHeadingEnable_nu;
			P_TCTCDC_PT1DevHeadingTime_sec = pLcfVehReqPorts->pCParKmc->P_TCTCDC_PT1DevHeadingTime_sec;
			P_TCTDTE_ClearToZeroCrvDistrb_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_ClearToZeroCrvDistrb_nu;
			P_TCTDTE_ClrZeroHeadAglDistrb_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_ClrZeroHeadAglDistrb_nu;
			P_TCTDTE_DebounceTimerHold_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DebounceTimerHold_sec;
			P_TCTDTE_DeZoneHeadAglDistrb_rad = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DeZoneHeadAglDistrb_rad;
			P_TCTDTE_DmpngCrvBuildup_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DmpngCrvBuildup_nu;
			P_TCTDTE_DmpngCrvReduction_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DmpngCrvReduction_nu;
			P_TCTDTE_DmpngCtrlledSys_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DmpngCtrlledSys_nu;
			P_TCTDTE_DmpngGrdLimitBuildup_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DmpngGrdLimitBuildup_nu;
			P_TCTDTE_DmpngGrdLimRed_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DmpngGrdLimRed_nu;
			P_TCTDTE_DmpngHeadingAngle_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_DmpngHeadingAngle_nu;
			P_TCTDTE_EstiBankAngleEnable_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_EstiBankAngleEnable_nu;
			P_TCTDTE_GrdGHold_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_GrdGHold_nu;
			P_TCTDTE_MinimumSpeed_mps = pLcfVehReqPorts->pCParKmc->P_TCTDTE_MinimumSpeed_mps;
			P_TCTDTE_StartValTimerHold_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_StartValTimerHold_sec;
			P_TCTDTE_SwitchCtrlErrHeading_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_SwitchCtrlErrHeading_nu;
			P_TCTDTE_TConstCrvBuildup_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstCrvBuildup_sec;
			P_TCTDTE_TConstCrvRed_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstCrvRed_sec;
			P_TCTDTE_TConstCrvSlBdup_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstCrvSlBdup_sec;
			P_TCTDTE_TConstCtrlledSys_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstCtrlledSys_sec;
			P_TCTDTE_TConstGrdLimBdup_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstGrdLimBdup_sec;
			P_TCTDTE_TConstGrdLimRed_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstGrdLimRed_sec;
			P_TCTDTE_TConstGrdLimSlBdup_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstGrdLimSlBdup_sec;
			P_TCTDTE_TConstHeadAgl_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TConstHeadAgl_sec;
			P_TCTDTE_ThActualManualTrq_Nm = pLcfVehReqPorts->pCParKmc->P_TCTDTE_ThActualManualTrq_Nm;
			P_TCTDTE_ThCtrlErrLatOffset_met = pLcfVehReqPorts->pCParKmc->P_TCTDTE_ThCtrlErrLatOffset_met;
			P_TCTDTE_ThStrAglFRAxlEffGrd_rps = pLcfVehReqPorts->pCParKmc->P_TCTDTE_ThStrAglFRAxlEffGrd_rps;
			P_TCTDTE_TStrAglFRAxlEff_sec = pLcfVehReqPorts->pCParKmc->P_TCTDTE_TStrAglFRAxlEff_sec;
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTDTE_DetaVehVelToScalCrv_mps, pLcfVehReqPorts->pCParKmc->X_TCTDTE_DetaVehVelToScalCrv_mps); i++)
			{
				X_TCTDTE_DetaVehVelToScalCrv_mps[i] = pLcfVehReqPorts->pCParKmc->X_TCTDTE_DetaVehVelToScalCrv_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTDTE_FactorLatSlpVehVelX_nu, pLcfVehReqPorts->pCParKmc->X_TCTDTE_FactorLatSlpVehVelX_nu); i++)
			{
				X_TCTDTE_FactorLatSlpVehVelX_nu[i] = pLcfVehReqPorts->pCParKmc->X_TCTDTE_FactorLatSlpVehVelX_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTDTE_InputVehVelSat_met, pLcfVehReqPorts->pCParKmc->X_TCTDTE_InputVehVelSat_met); i++)
			{
				X_TCTDTE_InputVehVelSat_met[i] = pLcfVehReqPorts->pCParKmc->X_TCTDTE_InputVehVelSat_met[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTDTE_InputVehVelScaling_mps, pLcfVehReqPorts->pCParKmc->X_TCTDTE_InputVehVelScaling_mps); i++)
			{
				X_TCTDTE_InputVehVelScaling_mps[i] = pLcfVehReqPorts->pCParKmc->X_TCTDTE_InputVehVelScaling_mps[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTDTE_LatSlpFromCrvXAxis_rad, pLcfVehReqPorts->pCParKmc->X_TCTDTE_LatSlpFromCrvXAxis_rad); i++)
			{
				X_TCTDTE_LatSlpFromCrvXAxis_rad[i] = pLcfVehReqPorts->pCParKmc->X_TCTDTE_LatSlpFromCrvXAxis_rad[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(X_TCTDTE_ManualTrqActValScal_Nm, pLcfVehReqPorts->pCParKmc->X_TCTDTE_ManualTrqActValScal_Nm); i++)
			{
				X_TCTDTE_ManualTrqActValScal_Nm[i] = pLcfVehReqPorts->pCParKmc->X_TCTDTE_ManualTrqActValScal_Nm[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_DetaVehVelToScalCrvStartVal_nu, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_DetaVehVelToScalCrvStartVal_nu); i++)
			{
				Y_TCTDTE_DetaVehVelToScalCrvStartVal_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_DetaVehVelToScalCrvStartVal_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_FactorLatSlpVehVelY_nu, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_FactorLatSlpVehVelY_nu); i++)
			{
				Y_TCTDTE_FactorLatSlpVehVelY_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_FactorLatSlpVehVelY_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_InputVehVelToScalCrv_nu, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_InputVehVelToScalCrv_nu); i++)
			{
				Y_TCTDTE_InputVehVelToScalCrv_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_InputVehVelToScalCrv_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_LatSlpFromCrvYAxis_rad, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_LatSlpFromCrvYAxis_rad); i++)
			{
				Y_TCTDTE_LatSlpFromCrvYAxis_rad[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_LatSlpFromCrvYAxis_rad[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_ManuTrqActValScalCrv_nu, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_ManuTrqActValScalCrv_nu); i++)
			{
				Y_TCTDTE_ManuTrqActValScalCrv_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_ManuTrqActValScalCrv_nu[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_VelXToMaxCrv_1pm, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_VelXToMaxCrv_1pm); i++)
			{
				Y_TCTDTE_VelXToMaxCrv_1pm[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_VelXToMaxCrv_1pm[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_VelXToMaxHeadAgl_rad, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_VelXToMaxHeadAgl_rad); i++)
			{
				Y_TCTDTE_VelXToMaxHeadAgl_rad[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_VelXToMaxHeadAgl_rad[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTDTE_VelXToMaxLatSlp_rad, pLcfVehReqPorts->pCParKmc->Y_TCTDTE_VelXToMaxLatSlp_rad); i++)
			{
				Y_TCTDTE_VelXToMaxLatSlp_rad[i] = pLcfVehReqPorts->pCParKmc->Y_TCTDTE_VelXToMaxLatSlp_rad[i];
			}
			P_TCTDTE_BankAngleCrvActive_nu = pLcfVehReqPorts->pCParKmc->P_TCTDTE_BankAngleCrvActive_nu;
			P_TCTLGC_DistYGainLDP_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_DistYGainLDP_nu;
			P_TCTLGC_HeadingGainLDP_nu = pLcfVehReqPorts->pCParKmc->P_TCTLGC_HeadingGainLDP_nu;
			for (i = 0; i < MIN_NO_OF_ELEM(Y_TCTLGC_DistYD_nu, pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DistYD_nu); i++)
			{
				Y_TCTLGC_DistYD_nu[i] = pLcfVehReqPorts->pCParKmc->Y_TCTLGC_DistYD_nu[i];
			}
			
			/* Copy parameters for DRVMN */
			P_DRMHOD_EstHandTqFilterC = pLcfVehReqPorts->pCParKmc->P_DRMHOD_EstHandTqFilterC[0];
			/*		for (i = 0; i < MIN_NO_OF_ELEM(P_DRMHOD_EstHandTqFilterC, pLcfVehReqPorts->pCParKmc->P_DRMHOD_EstHandTqFilterC); i++)
			{
				P_DRMHOD_EstHandTqFilterC[i] = pLcfVehReqPorts->pCParKmc->P_DRMHOD_EstHandTqFilterC[i];
			}
			*/	
			P_DRMHOD_HandsOffTqLim_Nm = pLcfVehReqPorts->pCParKmc->P_DRMHOD_HandsOffTqLim_Nm;
			P_DRMHOD_HandsOnTorLimAbs_Nm = pLcfVehReqPorts->pCParKmc->P_DRMHOD_HandsOnTorLimAbs_Nm;
			P_DRMHOD_HandsOnTqLim_Nm = pLcfVehReqPorts->pCParKmc->P_DRMHOD_HandsOnTqLim_Nm;
			P_DRMDAE_IncWarningTime_bool = pLcfVehReqPorts->pCParKmc->P_DRMDAE_IncWarningTime_bool;
		}
		if( pLcfVehReqPorts->pCParKmc->sSigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK )
		{
			/* Copy parameters for DMC */
			Dit_dirac_loop_count = pLcfVehReqPorts->pCParDmc->RTE_Dit_dirac_loop_count;
			Dit_signal_gen_frequency = pLcfVehReqPorts->pCParDmc->RTE_Dit_signal_gen_frequency;
			Dit_torque_pulse_amplitude = pLcfVehReqPorts->pCParDmc->RTE_Dit_torque_pulse_amplitude;
			Dmc_configuration_mode = pLcfVehReqPorts->pCParDmc->RTE_Dmc_configuration_mode;
			Dyc_boost_signal_reduction = pLcfVehReqPorts->pCParDmc->RTE_Dyc_boost_signal_reduction;
			Dyc_compensation_mode = pLcfVehReqPorts->pCParDmc->RTE_Dyc_compensation_mode;
			Dyc_kappa_a2_boost_factor = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a2_boost_factor;
			Dyc_kappa_a2_factor = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a2_factor;
			for (i = 0; i < MIN_NO_OF_ELEM(Dyc_kappa_a2_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a2_y_scheduling); i++)
			{
				Dyc_kappa_a2_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a2_y_scheduling[i];
			}
			Dyc_kappa_a3_factor = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a3_factor;
			for (i = 0; i < MIN_NO_OF_ELEM(Dyc_kappa_a3_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a3_y_scheduling); i++)
			{
				Dyc_kappa_a3_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_a3_y_scheduling[i];
			}
			Dyc_kappa_angle_corr_factor = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_corr_factor;
			Dyc_kappa_angle_gen_cor_fct_neg = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_gen_cor_fct_neg;
			Dyc_kappa_angle_gen_corr_factor = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_gen_corr_factor;
			Dyc_kappa_angle_lpf_corr_factor = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_lpf_corr_factor;
			for (i = 0; i < MIN_NO_OF_ELEM(Dyc_kappa_angle_t_y_sch_gen_neg, pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_t_y_sch_gen_neg); i++)
			{
				Dyc_kappa_angle_t_y_sch_gen_neg[i] = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_t_y_sch_gen_neg[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Dyc_kappa_angle_t_y_schedul_gen, pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_t_y_schedul_gen); i++)
			{
				Dyc_kappa_angle_t_y_schedul_gen[i] = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_angle_t_y_schedul_gen[i];
			}
			Dyc_kappa_dot_boost_thrs = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_dot_boost_thrs;
			Dyc_kappa_dot_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Dyc_kappa_dot_filter_coeff;
			Dyc_state_filter_time_constant = pLcfVehReqPorts->pCParDmc->RTE_Dyc_state_filter_time_constant;
			for (i = 0; i < MIN_NO_OF_ELEM(Dyc_time_constant_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Dyc_time_constant_y_scheduling); i++)
			{
				Dyc_time_constant_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Dyc_time_constant_y_scheduling[i];
			}
			Eps_d = pLcfVehReqPorts->pCParDmc->RTE_Eps_d;
			Eps_one_by_j_motor = pLcfVehReqPorts->pCParDmc->RTE_Eps_one_by_j_motor;
			Eps_torque_comp_factor = pLcfVehReqPorts->pCParDmc->RTE_Eps_torque_comp_factor;
			Hec_controller_mode = pLcfVehReqPorts->pCParDmc->RTE_Hec_controller_mode;
			Lat_2nd_rate_ctrl_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_2nd_rate_ctrl_filter_coeff;
			Lat_2nd_rate_ctrl_max_p_part = pLcfVehReqPorts->pCParDmc->RTE_Lat_2nd_rate_ctrl_max_p_part;
			Lat_2nd_rate_ctrl_max_pt1_part = pLcfVehReqPorts->pCParDmc->RTE_Lat_2nd_rate_ctrl_max_pt1_part;
			Lat_2nd_rate_limit_ctrl_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_2nd_rate_limit_ctrl_kp;
			Lat_2nd_rate_limit_ctrl_pt1_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_2nd_rate_limit_ctrl_pt1_kp;
			Lat_ay_control_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_control_kp;
			Lat_ay_control_pt1_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_control_pt1_kp;
			Lat_ay_controller_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_controller_coeff;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_ay_max_support_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_max_support_y_scheduling); i++)
			{
				Lat_ay_max_support_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_max_support_y_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_ay_max_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_max_y_scheduling); i++)
			{
				Lat_ay_max_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_max_y_scheduling[i];
			}
			Lat_ay_requested_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_ay_requested_filter_coeff;
			Lat_damp_level_grad_off = pLcfVehReqPorts->pCParDmc->RTE_Lat_damp_level_grad_off;
			Lat_damp_level_grad_on = pLcfVehReqPorts->pCParDmc->RTE_Lat_damp_level_grad_on;
			Lat_delta_f_dot_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_delta_f_dot_filter_coeff;
			Lat_delta_f_offset = pLcfVehReqPorts->pCParDmc->RTE_Lat_delta_f_offset;
			Lat_delta_off_flt_initial_loops = pLcfVehReqPorts->pCParDmc->RTE_Lat_delta_off_flt_initial_loops;
			Lat_delta_off_flt_initial_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_delta_off_flt_initial_omega;
			Lat_delta_offset_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_delta_offset_filter_coeff;
			Lat_delta_offset_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_delta_offset_filter_omega;
			Lat_derating_factor_filt_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_derating_factor_filt_coeff;
			Lat_direct_feedthr_hf_part_trq = pLcfVehReqPorts->pCParDmc->RTE_Lat_direct_feedthr_hf_part_trq;
			Lat_direct_feedthr_kappa_ctrl = pLcfVehReqPorts->pCParDmc->RTE_Lat_direct_feedthr_kappa_ctrl;
			Lat_direct_feedthrough_kappa = pLcfVehReqPorts->pCParDmc->RTE_Lat_direct_feedthrough_kappa;
			Lat_direct_feedthrough_trq = pLcfVehReqPorts->pCParDmc->RTE_Lat_direct_feedthrough_trq;
			Lat_direct_feedthrough_trq_ldp = pLcfVehReqPorts->pCParDmc->RTE_Lat_direct_feedthrough_trq_ldp;
			Lat_dmc_status_override_cycles = pLcfVehReqPorts->pCParDmc->RTE_Lat_dmc_status_override_cycles;
			Lat_eps_trq_can_scaling_factor = pLcfVehReqPorts->pCParDmc->RTE_Lat_eps_trq_can_scaling_factor;
			Lat_feedthr_increment_per_loop = pLcfVehReqPorts->pCParDmc->RTE_Lat_feedthr_increment_per_loop;
			Lat_ffwd_rate_control_min_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_ffwd_rate_control_min_error;
			Lat_ffwd_rate_control_pt1_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_ffwd_rate_control_pt1_kp;
			Lat_ffwd_rate_limit_control_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_ffwd_rate_limit_control_kp;
			Lat_ffwd_rate_pt1_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_ffwd_rate_pt1_filter_coeff;
			Lat_ffwd_rate_pt1_max_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_ffwd_rate_pt1_max_coeff;
			Lat_kappa_ctrl_discharge_grad = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_ctrl_discharge_grad;
			Lat_kappa_ctrl_discharge_mn_err = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_ctrl_discharge_mn_err;
			Lat_kappa_ctrl_discharge_slope = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_ctrl_discharge_slope;
			Lat_kappa_ctrl_lat_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_ctrl_lat_error_slope;
			Lat_kappa_ctrl_max_lateral_err = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_ctrl_max_lateral_err;
			Lat_kappa_discharge_gradient = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_discharge_gradient;
			Lat_kappa_discharge_min_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_discharge_min_error;
			Lat_kappa_discharge_slope = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_discharge_slope;
			Lat_kappa_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_filter_coeff;
			Lat_kappa_lateral_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_lateral_error_slope;
			Lat_kappa_linz_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_linz_error_slope;
			Lat_kappa_linz_filt_max_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_linz_filt_max_error;
			Lat_kappa_linz_filter_max_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_linz_filter_max_omega;
			Lat_kappa_linz_filter_min_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_linz_filter_min_omega;
			Lat_kappa_linz_max_omega_memshp = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_linz_max_omega_memshp;
			Lat_kappa_linz_weighting_factor = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_linz_weighting_factor;
			Lat_kappa_max_lateral_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_kappa_max_lateral_error;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_kppa_min_omega_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_kppa_min_omega_y_scheduling); i++)
			{
				Lat_kppa_min_omega_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_kppa_min_omega_y_scheduling[i];
			}
			Lat_ldp_startup_time = pLcfVehReqPorts->pCParDmc->RTE_Lat_ldp_startup_time;
			Lat_linz_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Lat_linz_error_slope;
			Lat_linz_filter_max_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_linz_filter_max_error;
			Lat_linz_filter_max_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_linz_filter_max_omega;
			Lat_linz_filter_min_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_linz_filter_min_omega;
			Lat_max_ay = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_ay;
			Lat_max_ay_extrapolation_gain = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_ay_extrapolation_gain;
			Lat_max_ay_hand_off = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_ay_hand_off;
			Lat_max_ay_hand_off_kneepoint = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_ay_hand_off_kneepoint;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_max_kappa_ctrl_grad_y_sched, pLcfVehReqPorts->pCParDmc->RTE_Lat_max_kappa_ctrl_grad_y_sched); i++)
			{
				Lat_max_kappa_ctrl_grad_y_sched[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_kappa_ctrl_grad_y_sched[i];
			}
			Lat_max_kappa_ctrl_gradient = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_kappa_ctrl_gradient;
			Lat_max_kappa_gradient = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_kappa_gradient;
			Lat_max_output_torque = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_output_torque;
			Lat_max_torque_corr_factor = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_torque_corr_factor;
			Lat_max_torque_select = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_torque_select;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_max_torque_x_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_max_torque_x_scheduling); i++)
			{
				Lat_max_torque_x_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_torque_x_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_max_torque_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_max_torque_y_scheduling); i++)
			{
				Lat_max_torque_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_max_torque_y_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_min_damping_level_x, pLcfVehReqPorts->pCParDmc->RTE_Lat_min_damping_level_x); i++)
			{
				Lat_min_damping_level_x[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_min_damping_level_x[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_min_damping_level_y, pLcfVehReqPorts->pCParDmc->RTE_Lat_min_damping_level_y); i++)
			{
				Lat_min_damping_level_y[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_min_damping_level_y[i];
			}
			Lat_min_offset_state = pLcfVehReqPorts->pCParDmc->RTE_Lat_min_offset_state;
			Lat_oc_fast_ki = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_fast_ki;
			Lat_oc_kappa_cmd_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_kappa_cmd_filter_coeff;
			Lat_oc_kappa_max_driver_torque = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_kappa_max_driver_torque;
			Lat_oc_kappa_max_heading_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_kappa_max_heading_error;
			Lat_oc_kappa_min_head_err_qual = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_kappa_min_head_err_qual;
			Lat_oc_kappa_min_latency = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_kappa_min_latency;
			Lat_oc_ki = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_ki;
			Lat_oc_max_delta_f_dot = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_delta_f_dot;
			Lat_oc_max_delta_offset = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_delta_offset;
			Lat_oc_max_delta_offset_kappa = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_delta_offset_kappa;
			Lat_oc_max_driver_torque = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_driver_torque;
			Lat_oc_max_kappa = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_kappa;
			Lat_oc_max_kappa_dys = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_kappa_dys;
			Lat_oc_max_lateral_accel = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_lateral_accel;
			Lat_oc_max_lateral_error = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_lateral_error;
			Lat_oc_max_velocity = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_max_velocity;
			Lat_oc_min_kappa_quality = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_min_kappa_quality;
			Lat_oc_min_velocity = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_min_velocity;
			Lat_oc_min_velocity_dys = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_min_velocity_dys;
			Lat_oc_minimum_latency = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_minimum_latency;
			Lat_oc_minimum_latency_shrt = pLcfVehReqPorts->pCParDmc->RTE_Lat_oc_minimum_latency_shrt;
			Lat_offset_inc_per_loop_slow = pLcfVehReqPorts->pCParDmc->RTE_Lat_offset_inc_per_loop_slow;
			Lat_offset_inc_per_loop_turn_on = pLcfVehReqPorts->pCParDmc->RTE_Lat_offset_inc_per_loop_turn_on;
			Lat_offset_increment_per_loop = pLcfVehReqPorts->pCParDmc->RTE_Lat_offset_increment_per_loop;
			Lat_offset_max = pLcfVehReqPorts->pCParDmc->RTE_Lat_offset_max;
			Lat_offset_max_clm_trq = pLcfVehReqPorts->pCParDmc->RTE_Lat_offset_max_clm_trq;
			Lat_offset_max_steer_angle = pLcfVehReqPorts->pCParDmc->RTE_Lat_offset_max_steer_angle;
			Lat_out_direct_feedthrough_trq = pLcfVehReqPorts->pCParDmc->RTE_Lat_out_direct_feedthrough_trq;
			Lat_out_torque_gradient = pLcfVehReqPorts->pCParDmc->RTE_Lat_out_torque_gradient;
			Lat_rate_control_d_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_control_d_filter_coeff;
			Lat_rate_control_max_p_part = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_control_max_p_part;
			Lat_rate_control_max_pt1_part = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_control_max_pt1_part;
			Lat_rate_ctrl_pt1_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_ctrl_pt1_filter_coeff;
			Lat_rate_limit_control_kd = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_limit_control_kd;
			Lat_rate_limit_control_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_limit_control_kp;
			Lat_rate_limit_control_pt1_kp = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_limit_control_pt1_kp;
			Lat_rate_pt1_filter_max_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_pt1_filter_max_coeff;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_rate_ys_kp_pt1_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_ys_kp_pt1_y_scheduling); i++)
			{
				Lat_rate_ys_kp_pt1_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_ys_kp_pt1_y_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_rate_ys_kp_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_ys_kp_y_scheduling); i++)
			{
				Lat_rate_ys_kp_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_rate_ys_kp_y_scheduling[i];
			}
			Lat_saturation_class_thr = pLcfVehReqPorts->pCParDmc->RTE_Lat_saturation_class_thr;
			Lat_select_input_source = pLcfVehReqPorts->pCParDmc->RTE_Lat_select_input_source;
			Lat_support_arw_factor_1 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_arw_factor_1;
			Lat_support_arw_factor_2 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_arw_factor_2;
			Lat_support_arw_factor_3 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_arw_factor_3;
			Lat_support_discharge_omega = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_discharge_omega;
			Lat_support_feedback_factor_1 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_feedback_factor_1;
			Lat_support_feedback_factor_2 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_feedback_factor_2;
			Lat_support_feedback_factor_hf = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_feedback_factor_hf;
			Lat_support_min_driver_torque = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_min_driver_torque;
			Lat_support_omega_1 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_omega_1;
			Lat_support_omega_2 = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_omega_2;
			Lat_support_omega_hf = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_omega_hf;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_support_tor_x_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_support_tor_x_scheduling); i++)
			{
				Lat_support_tor_x_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_tor_x_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_support_tor_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_support_tor_y_scheduling); i++)
			{
				Lat_support_tor_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_tor_y_scheduling[i];
			}
			Lat_support_torque_threshold = pLcfVehReqPorts->pCParDmc->RTE_Lat_support_torque_threshold;
			Lat_switch_falling_rate = pLcfVehReqPorts->pCParDmc->RTE_Lat_switch_falling_rate;
			Lat_switch_falling_rate_2 = pLcfVehReqPorts->pCParDmc->RTE_Lat_switch_falling_rate_2;
			Lat_switch_off_time = pLcfVehReqPorts->pCParDmc->RTE_Lat_switch_off_time;
			Lat_switch_rising_rate = pLcfVehReqPorts->pCParDmc->RTE_Lat_switch_rising_rate;
			Lat_switch_rising_rate_2 = pLcfVehReqPorts->pCParDmc->RTE_Lat_switch_rising_rate_2;
			Lat_switch_rising_rate_initial = pLcfVehReqPorts->pCParDmc->RTE_Lat_switch_rising_rate_initial;
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_torque_grad_x_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_torque_grad_x_scheduling); i++)
			{
				Lat_torque_grad_x_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_torque_grad_x_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Lat_torque_grad_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Lat_torque_grad_y_scheduling); i++)
			{
				Lat_torque_grad_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Lat_torque_grad_y_scheduling[i];
			}
			Lat_torque_gradient = pLcfVehReqPorts->pCParDmc->RTE_Lat_torque_gradient;
			Lat_torque_ramp_down_gradient = pLcfVehReqPorts->pCParDmc->RTE_Lat_torque_ramp_down_gradient;
			Lat_trq_grad_incr_factor_ldp = pLcfVehReqPorts->pCParDmc->RTE_Lat_trq_grad_incr_factor_ldp;
			Lat_trq_grad_pos_req_factor_ldp = pLcfVehReqPorts->pCParDmc->RTE_Lat_trq_grad_pos_req_factor_ldp;
			Lat_trq_saturation_end = pLcfVehReqPorts->pCParDmc->RTE_Lat_trq_saturation_end;
			Lat_trq_saturation_min = pLcfVehReqPorts->pCParDmc->RTE_Lat_trq_saturation_min;
			Lat_trq_saturation_start = pLcfVehReqPorts->pCParDmc->RTE_Lat_trq_saturation_start;
			Lat_trq_supporting_filt_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_trq_supporting_filt_coeff;
			Lat_yaw_rate_dot_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Lat_yaw_rate_dot_filter_coeff;
			Lco_error_filter_falling_coeff = (uint16)pLcfVehReqPorts->pCParDmc->RTE_Lco_error_filter_falling_coeff;
			Lco_error_filter_rising_coeff = (uint16)pLcfVehReqPorts->pCParDmc->RTE_Lco_error_filter_rising_coeff;
			Lco_filter_falling_coeff = (uint16)pLcfVehReqPorts->pCParDmc->RTE_Lco_filter_falling_coeff;
			Lco_filter_rising_coeff = (uint16)pLcfVehReqPorts->pCParDmc->RTE_Lco_filter_rising_coeff;
			Lco_min_control_error = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_control_error;
			Lco_min_control_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_control_error_slope;
			Lco_min_curvature_command = (uint16)pLcfVehReqPorts->pCParDmc->RTE_Lco_min_curvature_command;
			Lco_min_curvature_slope = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_curvature_slope;
			Lco_min_err_preload_enh_factor = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_err_preload_enh_factor;
			Lco_min_lateral_error = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_lateral_error;
			Lco_min_lateral_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_lateral_error_slope;
			Lco_min_load_comp_factor = pLcfVehReqPorts->pCParDmc->RTE_Lco_min_load_comp_factor;
			Lco_preload_enhancement_factor = pLcfVehReqPorts->pCParDmc->RTE_Lco_preload_enhancement_factor;
			Ldc_comp_kd_factor = pLcfVehReqPorts->pCParDmc->RTE_Ldc_comp_kd_factor;
			Ldc_comp_kp_factor = pLcfVehReqPorts->pCParDmc->RTE_Ldc_comp_kp_factor;
			Ldc_controller_mode = pLcfVehReqPorts->pCParDmc->RTE_Ldc_controller_mode;
			Ldc_ki = pLcfVehReqPorts->pCParDmc->RTE_Ldc_ki;
			Ldc_ki_fb = pLcfVehReqPorts->pCParDmc->RTE_Ldc_ki_fb;
			Ldc_kp_factor = pLcfVehReqPorts->pCParDmc->RTE_Ldc_kp_factor;
			Lka_max_align_torque = pLcfVehReqPorts->pCParDmc->RTE_Lka_max_align_torque;
			Obs_damping_kd_transf_factor = pLcfVehReqPorts->pCParDmc->RTE_Obs_damping_kd_transf_factor;
			Obs_delta_dot_filter_time_const = pLcfVehReqPorts->pCParDmc->RTE_Obs_delta_dot_filter_time_const;
			Obs_dos_d = pLcfVehReqPorts->pCParDmc->RTE_Obs_dos_d;
			Obs_dos_ff_gain = pLcfVehReqPorts->pCParDmc->RTE_Obs_dos_ff_gain;
			for (i = 0; i < MIN_NO_OF_ELEM(Obs_dos_ff_vel_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Obs_dos_ff_vel_y_scheduling); i++)
			{
				Obs_dos_ff_vel_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Obs_dos_ff_vel_y_scheduling[i];
			}
			Obs_dos_l = pLcfVehReqPorts->pCParDmc->RTE_Obs_dos_l;
			Obs_dos_one_by_j_motor = pLcfVehReqPorts->pCParDmc->RTE_Obs_dos_one_by_j_motor;
			Obs_eps_d = pLcfVehReqPorts->pCParDmc->RTE_Obs_eps_d;
			Obs_eps_one_by_j_motor = pLcfVehReqPorts->pCParDmc->RTE_Obs_eps_one_by_j_motor;
			Obs_ffwd_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Obs_ffwd_filter_omega;
			Obs_ffwd_filter_tau = pLcfVehReqPorts->pCParDmc->RTE_Obs_ffwd_filter_tau;
			Obs_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Obs_filter_omega;
			Obs_filter_tau = pLcfVehReqPorts->pCParDmc->RTE_Obs_filter_tau;
			Obs_force_torque_transf_factor = pLcfVehReqPorts->pCParDmc->RTE_Obs_force_torque_transf_factor;
			Obs_l = pLcfVehReqPorts->pCParDmc->RTE_Obs_l;
			for (i = 0; i < MIN_NO_OF_ELEM(Obs_l_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Obs_l_y_scheduling); i++)
			{
				Obs_l_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Obs_l_y_scheduling[i];
			}
			Obs_observer_mode = pLcfVehReqPorts->pCParDmc->RTE_Obs_observer_mode;
			for (i = 0; i < MIN_NO_OF_ELEM(Obs_one_j_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Obs_one_j_y_scheduling); i++)
			{
				Obs_one_j_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Obs_one_j_y_scheduling[i];
			}
			Odm_odometry_mode = pLcfVehReqPorts->pCParDmc->RTE_Odm_odometry_mode;
			Sac_accepted_control_error = pLcfVehReqPorts->pCParDmc->RTE_Sac_accepted_control_error;
			Sac_accuracy_feedback_transf = pLcfVehReqPorts->pCParDmc->RTE_Sac_accuracy_feedback_transf;
			Sac_angle_fading_mode = pLcfVehReqPorts->pCParDmc->RTE_Sac_angle_fading_mode;
			Sac_backlash_torque = pLcfVehReqPorts->pCParDmc->RTE_Sac_backlash_torque;
			Sac_cmd_boost_request_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_cmd_boost_request_factor;
			Sac_cmd_enhancement_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_cmd_enhancement_gain;
			Sac_cmd_feedforward_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_cmd_feedforward_gain;
			Sac_cmd_offset_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_cmd_offset_gain;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_comp_fact_gain_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_comp_fact_gain_y_scheduling); i++)
			{
				Sac_comp_fact_gain_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_comp_fact_gain_y_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_comp_factor_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_comp_factor_y_scheduling); i++)
			{
				Sac_comp_factor_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_comp_factor_y_scheduling[i];
			}
			Sac_compensation_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_compensation_factor;
			Sac_compensation_filter_select = pLcfVehReqPorts->pCParDmc->RTE_Sac_compensation_filter_select;
			Sac_controller_mode_1 = pLcfVehReqPorts->pCParDmc->RTE_Sac_controller_mode_1;
			Sac_controller_mode_2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_controller_mode_2;
			Sac_ctrl_error_red_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_ctrl_error_red_filter_coeff;
			Sac_ctrl_error_red_hf_scale = pLcfVehReqPorts->pCParDmc->RTE_Sac_ctrl_error_red_hf_scale;
			Sac_damp_act_fading_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_damp_act_fading_gain;
			Sac_damp_act_min_control_error = pLcfVehReqPorts->pCParDmc->RTE_Sac_damp_act_min_control_error;
			Sac_damp_ffwd_filter_coeff_1 = pLcfVehReqPorts->pCParDmc->RTE_Sac_damp_ffwd_filter_coeff_1;
			Sac_damp_ffwd_filter_coeff_2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_damp_ffwd_filter_coeff_2;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_damp_level_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_damp_level_y_scheduling); i++)
			{
				Sac_damp_level_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_damp_level_y_scheduling[i];
			}
			Sac_damping_kd_transf_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_damping_kd_transf_factor;
			Sac_damping_lpf_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_damping_lpf_coeff;
			Sac_damping_reduction_gate_time = pLcfVehReqPorts->pCParDmc->RTE_Sac_damping_reduction_gate_time;
			Sac_dc_gain_curvature_slope = pLcfVehReqPorts->pCParDmc->RTE_Sac_dc_gain_curvature_slope;
			Sac_dc_gain_factor_high_curv = pLcfVehReqPorts->pCParDmc->RTE_Sac_dc_gain_factor_high_curv;
			Sac_dc_gain_min_curvature = pLcfVehReqPorts->pCParDmc->RTE_Sac_dc_gain_min_curvature;
			Sac_delta_f_cmd_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_f_cmd_filter_omega;
			Sac_delta_f_cmd_gradient = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_f_cmd_gradient;
			Sac_delta_f_dot2_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_f_dot2_filter_coeff;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_delta_gradient_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_gradient_y_scheduling); i++)
			{
				Sac_delta_gradient_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_gradient_y_scheduling[i];
			}
			Sac_delta_psi_dot_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_psi_dot_factor;
			Sac_delta_psi_dot_maf_length = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_psi_dot_maf_length;
			Sac_delta_psi_pt1_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_psi_pt1_filter_coeff;
			Sac_differential_2_part = pLcfVehReqPorts->pCParDmc->RTE_Sac_differential_2_part;
			Sac_differential_part = pLcfVehReqPorts->pCParDmc->RTE_Sac_differential_part;
			Sac_eps_damping_level = pLcfVehReqPorts->pCParDmc->RTE_Sac_eps_damping_level;
			Sac_eps_damping_level_low = pLcfVehReqPorts->pCParDmc->RTE_Sac_eps_damping_level_low;
			Sac_error_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Sac_error_filter_omega;
			Sac_error_filter_omega_2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_error_filter_omega_2;
			Sac_fad_flt_fallng_lw_dyn_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_fad_flt_fallng_lw_dyn_coeff;
			Sac_fad_flt_rising_lw_dyn_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_fad_flt_rising_lw_dyn_coeff;
			Sac_feedforward_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_feedforward_filter_coeff;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_feedfwd_factor_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_feedfwd_factor_y_scheduling); i++)
			{
				Sac_feedfwd_factor_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_feedfwd_factor_y_scheduling[i];
			}
			Sac_feedthr_increment_per_loop = pLcfVehReqPorts->pCParDmc->RTE_Sac_feedthr_increment_per_loop;
			Sac_ffwd_diff_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Sac_ffwd_diff_filter_omega;
			Sac_ffwd_scale_pos_angle_cmd = pLcfVehReqPorts->pCParDmc->RTE_Sac_ffwd_scale_pos_angle_cmd;
			Sac_ffwd_scaling_end = pLcfVehReqPorts->pCParDmc->RTE_Sac_ffwd_scaling_end;
			Sac_ffwd_scaling_start = pLcfVehReqPorts->pCParDmc->RTE_Sac_ffwd_scaling_start;
			Sac_filter_omega = pLcfVehReqPorts->pCParDmc->RTE_Sac_filter_omega;
			Sac_filter_tau = pLcfVehReqPorts->pCParDmc->RTE_Sac_filter_tau;
			Sac_frc_comp_b1_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_frc_comp_b1_factor;
			Sac_frc_comp_omega = pLcfVehReqPorts->pCParDmc->RTE_Sac_frc_comp_omega;
			Sac_frc_static_friction_torque = pLcfVehReqPorts->pCParDmc->RTE_Sac_frc_static_friction_torque;
			Sac_frc_torque_corr_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_frc_torque_corr_factor;
			Sac_friction_comp_activ_source = pLcfVehReqPorts->pCParDmc->RTE_Sac_friction_comp_activ_source;
			Sac_friction_comp_error_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_friction_comp_error_gain;
			Sac_friction_comp_linear_slope = pLcfVehReqPorts->pCParDmc->RTE_Sac_friction_comp_linear_slope;
			Sac_friction_comp_torque = pLcfVehReqPorts->pCParDmc->RTE_Sac_friction_comp_torque;
			Sac_friction_comp_torque_cw = pLcfVehReqPorts->pCParDmc->RTE_Sac_friction_comp_torque_cw;
			Sac_friction_control_error_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_friction_control_error_gain;
			Sac_kd = pLcfVehReqPorts->pCParDmc->RTE_Sac_kd;
			Sac_kd_fading_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_fading_factor;
			Sac_kd_max_fading_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_max_fading_factor;
			Sac_kd_obs = pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_obs;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_kd_x_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_x_scheduling); i++)
			{
				Sac_kd_x_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_x_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_kd_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_y_scheduling); i++)
			{
				Sac_kd_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_kd_y_scheduling[i];
			}
			Sac_ki = pLcfVehReqPorts->pCParDmc->RTE_Sac_ki;
			Sac_ki_fb = pLcfVehReqPorts->pCParDmc->RTE_Sac_ki_fb;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_ki_fb_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_ki_fb_y_scheduling); i++)
			{
				Sac_ki_fb_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_ki_fb_y_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_ki_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_ki_y_scheduling); i++)
			{
				Sac_ki_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_ki_y_scheduling[i];
			}
			Sac_kmc_loop_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_kmc_loop_gain;
			Sac_kp = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp;
			Sac_kp_dc_gain_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_dc_gain_factor;
			Sac_kp_derating_slope = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_derating_slope;
			Sac_kp_fading_flt_falling_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_fading_flt_falling_coeff;
			Sac_kp_fading_flt_rising_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_fading_flt_rising_coeff;
			Sac_kp_ldp = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_ldp;
			Sac_kp_scale_pos_angle_command = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_scale_pos_angle_command;
			Sac_kp_scale_pos_control_error = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_scale_pos_control_error;
			Sac_kp_scaling_end = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_scaling_end;
			Sac_kp_scaling_start = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_scaling_start;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_kp_x_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_x_scheduling); i++)
			{
				Sac_kp_x_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_x_scheduling[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_kp_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_y_scheduling); i++)
			{
				Sac_kp_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_kp_y_scheduling[i];
			}
			Sac_kx = pLcfVehReqPorts->pCParDmc->RTE_Sac_kx;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_kx_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_kx_y_scheduling); i++)
			{
				Sac_kx_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_kx_y_scheduling[i];
			}
			Sac_limiter_control_ki = pLcfVehReqPorts->pCParDmc->RTE_Sac_limiter_control_ki;
			Sac_lin_fad_enable_multi_ramp = pLcfVehReqPorts->pCParDmc->RTE_Sac_lin_fad_enable_multi_ramp;
			Sac_lin_fading_activation_thrs = pLcfVehReqPorts->pCParDmc->RTE_Sac_lin_fading_activation_thrs;
			Sac_lin_fading_coefficient = pLcfVehReqPorts->pCParDmc->RTE_Sac_lin_fading_coefficient;
			Sac_lin_fading_gate_time = pLcfVehReqPorts->pCParDmc->RTE_Sac_lin_fading_gate_time;
			Sac_lin_fading_max_offset = pLcfVehReqPorts->pCParDmc->RTE_Sac_lin_fading_max_offset;
			Sac_lin_fading_min_offset = pLcfVehReqPorts->pCParDmc->RTE_Sac_lin_fading_min_offset;
			Sac_load_compensation_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_load_compensation_factor;
			Sac_max_angle_velocity = pLcfVehReqPorts->pCParDmc->RTE_Sac_max_angle_velocity;
			Sac_max_integ_torque_corr_fact = pLcfVehReqPorts->pCParDmc->RTE_Sac_max_integ_torque_corr_fact;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_max_integ_trq_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_max_integ_trq_y_scheduling); i++)
			{
				Sac_max_integ_trq_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_max_integ_trq_y_scheduling[i];
			}
			Sac_min_command_gradient = pLcfVehReqPorts->pCParDmc->RTE_Sac_min_command_gradient;
			Sac_min_control_error = pLcfVehReqPorts->pCParDmc->RTE_Sac_min_control_error;
			Sac_min_kp = pLcfVehReqPorts->pCParDmc->RTE_Sac_min_kp;
			Sac_min_proportional_part = pLcfVehReqPorts->pCParDmc->RTE_Sac_min_proportional_part;
			Sac_min_proportional_part_scale = pLcfVehReqPorts->pCParDmc->RTE_Sac_min_proportional_part_scale;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_mx_angle_speed_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_mx_angle_speed_y_scheduling); i++)
			{
				Sac_mx_angle_speed_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_mx_angle_speed_y_scheduling[i];
			}
			Sac_notch_cf = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_cf;
			Sac_notch_d = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_d;
			Sac_notch_high_pass_omega_1 = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_high_pass_omega_1;
			Sac_notch_high_pass_omega_2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_high_pass_omega_2;
			Sac_notch_l1 = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_l1;
			Sac_notch_l2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_l2;
			Sac_notch_l3 = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_l3;
			Sac_notch_one_by_j_motor = pLcfVehReqPorts->pCParDmc->RTE_Sac_notch_one_by_j_motor;
			Sac_obs_scaling_end = pLcfVehReqPorts->pCParDmc->RTE_Sac_obs_scaling_end;
			Sac_obs_scaling_start = pLcfVehReqPorts->pCParDmc->RTE_Sac_obs_scaling_start;
			Sac_omega_arw = pLcfVehReqPorts->pCParDmc->RTE_Sac_omega_arw;
			Sac_one_by_ts = pLcfVehReqPorts->pCParDmc->RTE_Sac_one_by_ts;
			Sac_osc_damp_ctrl_error_slope = pLcfVehReqPorts->pCParDmc->RTE_Sac_osc_damp_ctrl_error_slope;
			Sac_osc_damp_diff_part_slope = pLcfVehReqPorts->pCParDmc->RTE_Sac_osc_damp_diff_part_slope;
			Sac_osc_damp_flt_falling_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_osc_damp_flt_falling_coeff;
			Sac_osc_damp_flt_rising_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_osc_damp_flt_rising_coeff;
			Sac_osc_damp_min_control_error = pLcfVehReqPorts->pCParDmc->RTE_Sac_osc_damp_min_control_error;
			Sac_p_part_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_p_part_filter_coeff;
			Sac_parity_omega = pLcfVehReqPorts->pCParDmc->RTE_Sac_parity_omega;
			Sac_parity_time_constant = pLcfVehReqPorts->pCParDmc->RTE_Sac_parity_time_constant;
			Sac_parity_time_constant_ldp = pLcfVehReqPorts->pCParDmc->RTE_Sac_parity_time_constant_ldp;
			Sac_pid_kd = pLcfVehReqPorts->pCParDmc->RTE_Sac_pid_kd;
			Sac_pid_kp = pLcfVehReqPorts->pCParDmc->RTE_Sac_pid_kp;
			for (i = 0; i < MIN_NO_OF_ELEM(Sac_pid_kp_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Sac_pid_kp_y_scheduling); i++)
			{
				Sac_pid_kp_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Sac_pid_kp_y_scheduling[i];
			}
			Sac_prop_part_limit_scale = pLcfVehReqPorts->pCParDmc->RTE_Sac_prop_part_limit_scale;
			Sac_pt1_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff;
			Sac_pt1_filter_coeff_2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff_2;
			Sac_pt1_filter_coeff_3 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff_3;
			Sac_pt1_filter_coeff_4 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff_4;
			Sac_pt1_filter_coeff_5 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff_5;
			Sac_pt1_filter_coeff_6 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff_6;
			Sac_pt1_filter_coeff_7 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_filter_coeff_7;
			Sac_pt1_max_filter_coeff_2 = pLcfVehReqPorts->pCParDmc->RTE_Sac_pt1_max_filter_coeff_2;
			Sac_reduced_kmc_loop_gain = pLcfVehReqPorts->pCParDmc->RTE_Sac_reduced_kmc_loop_gain;
			Sac_stiffness_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Sac_stiffness_filter_coeff;
			Sac_torque_scaling_factor = pLcfVehReqPorts->pCParDmc->RTE_Sac_torque_scaling_factor;
			Sac_ts = pLcfVehReqPorts->pCParDmc->RTE_Sac_ts;
			Sat_dynamic_enhancement_factor = pLcfVehReqPorts->pCParDmc->RTE_Sat_dynamic_enhancement_factor;
			Sat_max_delta_f_cmd = pLcfVehReqPorts->pCParDmc->RTE_Sat_max_delta_f_cmd;
			Sat_thrs_control_kp = pLcfVehReqPorts->pCParDmc->RTE_Sat_thrs_control_kp;
			Tdf_comp_factor_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Tdf_comp_factor_filter_coeff;
			Tdf_control_err_derating_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_control_err_derating_slope;
			Tdf_derating_end = pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_end;
			Tdf_derating_mode = pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_mode;
			for (i = 0; i < MIN_NO_OF_ELEM(Tdf_derating_slope_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_slope_y_scheduling); i++)
			{
				Tdf_derating_slope_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_slope_y_scheduling[i];
			}
			Tdf_derating_start = pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_start;
			for (i = 0; i < MIN_NO_OF_ELEM(Tdf_derating_thrs_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_thrs_y_scheduling); i++)
			{
				Tdf_derating_thrs_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Tdf_derating_thrs_y_scheduling[i];
			}
			Tdf_lat_accel_sign_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_lat_accel_sign_slope;
			Tdf_load_comp_end = pLcfVehReqPorts->pCParDmc->RTE_Tdf_load_comp_end;
			Tdf_load_comp_start = pLcfVehReqPorts->pCParDmc->RTE_Tdf_load_comp_start;
			for (i = 0; i < MIN_NO_OF_ELEM(Tdf_load_comp_y_scheduling, pLcfVehReqPorts->pCParDmc->RTE_Tdf_load_comp_y_scheduling); i++)
			{
				Tdf_load_comp_y_scheduling[i] = pLcfVehReqPorts->pCParDmc->RTE_Tdf_load_comp_y_scheduling[i];
			}
			Tdf_min_compensation_factor = pLcfVehReqPorts->pCParDmc->RTE_Tdf_min_compensation_factor;
			Tdf_min_steer_torque_class = pLcfVehReqPorts->pCParDmc->RTE_Tdf_min_steer_torque_class;
			for (i = 0; i < MIN_NO_OF_ELEM(Tdf_min_steer_trq_cls_y_schedul, pLcfVehReqPorts->pCParDmc->RTE_Tdf_min_steer_trq_cls_y_schedul); i++)
			{
				Tdf_min_steer_trq_cls_y_schedul[i] = pLcfVehReqPorts->pCParDmc->RTE_Tdf_min_steer_trq_cls_y_schedul[i];
			}
			Tdf_steer_torque_comp_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_torque_comp_slope;
			Tdf_steer_torque_comp_thrs_ldp = pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_torque_comp_thrs_ldp;
			Tdf_steer_torque_sign_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_torque_sign_slope;
			for (i = 0; i < MIN_NO_OF_ELEM(Tdf_steer_trq_cmp_ldp_y_schedul, pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_trq_cmp_ldp_y_schedul); i++)
			{
				Tdf_steer_trq_cmp_ldp_y_schedul[i] = pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_trq_cmp_ldp_y_schedul[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Tdf_steer_trq_cmp_slp_y_schedul, pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_trq_cmp_slp_y_schedul); i++)
			{
				Tdf_steer_trq_cmp_slp_y_schedul[i] = pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_trq_cmp_slp_y_schedul[i];
			}
			Tdf_steer_trq_comp_reduced_thrs = pLcfVehReqPorts->pCParDmc->RTE_Tdf_steer_trq_comp_reduced_thrs;
			Tdf_toque_derating_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_toque_derating_slope;
			Tdf_torque_der_filt_coeff_hf = pLcfVehReqPorts->pCParDmc->RTE_Tdf_torque_der_filt_coeff_hf;
			Tdf_torque_derating_filt_coeff = pLcfVehReqPorts->pCParDmc->RTE_Tdf_torque_derating_filt_coeff;
			Tdf_torque_derating_threshold = pLcfVehReqPorts->pCParDmc->RTE_Tdf_torque_derating_threshold;
			Tdf_torque_request_sign_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_torque_request_sign_slope;
			Tdf_torque_supporting_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_torque_supporting_slope;
			Tdf_torque_supporting_threshold = pLcfVehReqPorts->pCParDmc->RTE_Tdf_torque_supporting_threshold;
			Tdf_trq_der_thrs_dp_hi_sens = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_der_thrs_dp_hi_sens;
			Tdf_trq_derating_max_init_trq = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_derating_max_init_trq;
			Tdf_trq_derating_min_init_trq = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_derating_min_init_trq;
			Tdf_trq_derating_slope_hf_path = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_derating_slope_hf_path;
			Tdf_trq_derating_slope_hi_sens = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_derating_slope_hi_sens;
			Tdf_trq_derating_threshold_dp = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_derating_threshold_dp;
			Tdf_trq_derating_thrs_hi_sens = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_derating_thrs_hi_sens;
			Tdf_trq_filter_coeff = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_filter_coeff;
			Tdf_trq_scaling_end = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_scaling_end;
			Tdf_trq_scaling_start = pLcfVehReqPorts->pCParDmc->RTE_Tdf_trq_scaling_start;
			Tdf_vel_derating_filt_coeff = pLcfVehReqPorts->pCParDmc->RTE_Tdf_vel_derating_filt_coeff;
			Tdf_velocity_derating_slope = pLcfVehReqPorts->pCParDmc->RTE_Tdf_velocity_derating_slope;
			Tdf_velocity_derating_threshold = pLcfVehReqPorts->pCParDmc->RTE_Tdf_velocity_derating_threshold;
			Tge_state_filter_time_constant = pLcfVehReqPorts->pCParDmc->RTE_Tge_state_filter_time_constant;
			Trj_generation_mode = pLcfVehReqPorts->pCParDmc->RTE_Trj_generation_mode;
			Trj_max_accel = pLcfVehReqPorts->pCParDmc->RTE_Trj_max_accel;
			Trj_max_heading_angle = pLcfVehReqPorts->pCParDmc->RTE_Trj_max_heading_angle;
			Trj_step_command = pLcfVehReqPorts->pCParDmc->RTE_Trj_step_command;
			Veh_column_stiffness = pLcfVehReqPorts->pCParDmc->RTE_Veh_column_stiffness;
			Veh_steer_angle_rate_source = (uint8)pLcfVehReqPorts->pCParDmc->RTE_Veh_steer_angle_rate_source;
			Veh_steer_angle_source = (uint8)pLcfVehReqPorts->pCParDmc->RTE_Veh_steer_angle_source;
			for (i = 0; i < MIN_NO_OF_ELEM(Veh_steer_gear_ratio_x_tab, pLcfVehReqPorts->pCParDmc->RTE_Veh_steer_gear_ratio_x_tab); i++)
			{
				Veh_steer_gear_ratio_x_tab[i] = pLcfVehReqPorts->pCParDmc->RTE_Veh_steer_gear_ratio_x_tab[i];
			}
			for (i = 0; i < MIN_NO_OF_ELEM(Veh_steer_gear_ratio_y_tab, pLcfVehReqPorts->pCParDmc->RTE_Veh_steer_gear_ratio_y_tab); i++)
			{
				Veh_steer_gear_ratio_y_tab[i] = pLcfVehReqPorts->pCParDmc->RTE_Veh_steer_gear_ratio_y_tab[i];
			}
			Lat_lka_startup_time = pLcfVehReqPorts->pCParDmc->RTE_Lat_lka_startup_time;
			Sac_delta_f_cmd_initial_grad = pLcfVehReqPorts->pCParDmc->RTE_Sac_delta_f_cmd_initial_grad;
		}
		/* Ensure tunable parameters are copied only once at startup, in order to have them tunable via XCP during runtime */
		pFRAME_VehDbgData->uiTunParCopied = 1u;
	}
#endif
}

