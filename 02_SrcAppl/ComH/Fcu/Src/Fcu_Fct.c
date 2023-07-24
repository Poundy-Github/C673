/**
 * \file   Fcu_Fct.c
 *
 * \brief  Get the signal from CAN and Soc ,then send it to Fct Algo.
 *
 * \version refer the Fcu_Fct.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/* ==================[Includes]=============================================== */
#include "Fcu_Common.h"
#include "Fcu_Fct.h"
#include "Dbg_Cfg.h"
#include "Cdm_Cfg.h"
#include "Cps_Lcfg.h"

/*==================[internal data]=========================================*/
/*==================[.rodata]============================*/

/*==================[.data]==============================*/

/*==================[.bss]===============================*/
Fcu_Static HEADInputCustom_t Fcu_HeadInputCustomData;
Fcu_Static DIMInputCustom_t Fcu_DimInputCustomData;
Fcu_Static HEADInputGeneric_t Fcu_HeadInputGenericData;
Fcu_Static DIMInputGeneric_t Fcu_DimInputGenericData;
Fcu_Static HEADOutputCustom_t Fcu_HeadOutputCustomData;
Fcu_Static EM_t_GenObjectList Fcu_GenObjcetList;

/*==================[external data]==========================================*/


/*==================[internal function declarations]=========================*/
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctHeadInputCustomData(HEADInputCustom_t* const ptr_Fcu_HeadInputCustomData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctDimInputGenericData(DIMInputGeneric_t* const ptr_Fcu_DimInputGenericData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctDimInputCustomData(DIMInputCustom_t* const ptr_Fcu_DimInputCustomData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctHeadInputGenericData(HEADInputGeneric_t* const ptrFcu_HeadInputGenericData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_TxProcess_HeadOutputCustomData(HEADOutputCustom_t* const ptr_Fcu_HeadOutputCustomData, const s_Fcu_AdasDomain_SignalData_t* const ptr_AdasDomain_Data, s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal);

/*==================[external function definitions]=========================*/
/**
 * \functions Fcu_Fct_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_Fct_InitFunction (void)
{
	/*TODO : Clean the local variable*/
	(void)TS_MemBZero(&Fcu_HeadInputCustomData, sizeof(HEADInputCustom_t));
	(void)TS_MemBZero(&Fcu_DimInputCustomData, sizeof(DIMInputCustom_t));
	(void)TS_MemBZero(&Fcu_HeadInputGenericData, sizeof(HEADInputGeneric_t)); 
	(void)TS_MemBZero(&Fcu_DimInputGenericData, sizeof(DIMInputGeneric_t)); 
	(void)TS_MemBZero(&Fcu_HeadOutputCustomData, sizeof(HEADOutputCustom_t)); 	
}


/**
 * \functions Fcu_Fct_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_Fct_MainFunction(const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal)
{
    /*Fcu_FCT_Input*/
	Fcu_RxProcess_FctDimInputGenericData(&Fcu_DimInputGenericData, ptr_Fcu_Rte_input_Signal);
	Fcu_RxProcess_FctDimInputCustomData(&Fcu_DimInputCustomData, ptr_Fcu_Rte_input_Signal);
	Fcu_RxProcess_FctHeadInputCustomData(&Fcu_HeadInputCustomData, ptr_Fcu_Rte_input_Signal);
	Fcu_RxProcess_FctHeadInputGenericData(&Fcu_HeadInputGenericData, ptr_Fcu_Rte_input_Signal);
    /*Fcu_FCT_Output*/
	Fcu_TxProcess_HeadOutputCustomData(&Fcu_HeadOutputCustomData, &ptr_Fcu_Rte_input_Signal->AdasDomain_Data,ptr_Fcu_Rte_Output_Signal);

}

/*==================[internal function definitions]=========================*/
/**
 * \functions Fcu_RxProcess_FctHeadInputCustomData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctHeadInputCustomData(HEADInputCustom_t* const ptr_Fcu_HeadInputCustomData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal)
{
	sint64 s64_time_stamp = 0;
	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&s64_time_stamp);

	ptr_Fcu_HeadInputCustomData->uiVersionNumber = 23;/*Shall be check the version by DF.*/
	ptr_Fcu_HeadInputCustomData->sSigHeader.eSigStatus = 0x01u;
	ptr_Fcu_HeadInputCustomData->sSigHeader.uiTimeStamp = (uint32)s64_time_stamp;
	ptr_Fcu_HeadInputCustomData->sSigHeader.uiCycleCounter++;
	ptr_Fcu_HeadInputCustomData->sSigHeader.uiMeasurementCounter++;
	ptr_Fcu_HeadInputCustomData->Mcylinder_Pressure = (float32)ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_BrakePressureSimulator;  
	ptr_Fcu_HeadInputCustomData->eQualifierWarnChain =(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAWBavailable == 1u)?0u:1u;
	ptr_Fcu_HeadInputCustomData->eQualifierHBA = (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspABAavailable == 1u)?0u:1u;
	ptr_Fcu_HeadInputCustomData->eQualifierPrefill = (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EsprefillAvailable == 1u)?0u:1u;
	ptr_Fcu_HeadInputCustomData->eQualifierBrakeChain = (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAEBAvailable == 1u)?0u:1u;
	ptr_Fcu_HeadInputCustomData->eBCM_Status = (ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_SrsDrvrBucSwtSts == 0u)?0u:1u;
	ptr_Fcu_HeadInputCustomData->SCS_AEB_decel_resp = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspActvSts;

    if(0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuVehGearPosnVld)
    {
        switch(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn)
        {
            case 0x1:
            {
                ptr_Fcu_HeadInputCustomData->SCS_HBA_resp = 0x01u;/*GEAR_POSITION_PARK*/
                break;
            }
            case 0x2:
            {
                ptr_Fcu_HeadInputCustomData->SCS_HBA_resp = 0x03u;/*GEAR_POSITION_REVERSE*/
                break;
            }
            case 0x3:
            {
                ptr_Fcu_HeadInputCustomData->SCS_HBA_resp = 0x02u;/*GEAR_POSITION_NEUTRAL*/
                break;
            }
            case 0x4:
            {
                ptr_Fcu_HeadInputCustomData->SCS_HBA_resp = 0x04u;/*GEAR_POSITION_DRIVE*/
                break;
            }
            default:
            {
                ptr_Fcu_HeadInputCustomData->SCS_HBA_resp = 0x00u;/*GEAR_POSITION_NONE*/
                break;
            }
        }
    }
    else
    {
        ptr_Fcu_HeadInputCustomData->SCS_HBA_resp = 0x00u;/*GEAR_POSITION_NONE*/
    }
	
    /* EOL Mode Gate */
	if(EOL_MODE_OFF) //Not transmit into EOL mode
    {
        if(0x01u == GET_FCU_HMI_COMMAND(FUNC_AEB)) //Get AEB active signal from HMI.
        {
            if(TRUE == GET_FCU_FIMSTATE_AEB()) //FiM Function disable
            {
                ptr_Fcu_HeadInputCustomData->EBA_Active_Condition_Custom_input = 0u; //active
			}
			else
			{
                ptr_Fcu_HeadInputCustomData->EBA_Active_Condition_Custom_input = 1u; //not active 
			}
		}
		else //When the event trigger ,shall be enable FIM to deactive algo.
		{
            ptr_Fcu_HeadInputCustomData->EBA_Active_Condition_Custom_input = 1u; //not active
		}
	}
	else
	{
        ptr_Fcu_HeadInputCustomData->EBA_Active_Condition_Custom_input = 1u; //not active
	}	
	
	(void)Rte_Write_PP_Fcu_HeadInputCustomData_HeadInputCustomData(ptr_Fcu_HeadInputCustomData);
}


/**
 * \functions Fcu_RxProcess_FctDimInputGenericData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctDimInputGenericData(DIMInputGeneric_t* const ptr_Fcu_DimInputGenericData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal)
{
	sint64 s64_time_stamp = 0;

	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&s64_time_stamp);

	ptr_Fcu_DimInputGenericData->sSigHeader.eSigStatus = 0x01u;/*Valid*/
	ptr_Fcu_DimInputGenericData->uiVersionNumber = 0x06;
	ptr_Fcu_DimInputGenericData->sSigHeader.uiTimeStamp = (uint32)s64_time_stamp;
	ptr_Fcu_DimInputGenericData->sSigHeader.uiCycleCounter++;
	ptr_Fcu_DimInputGenericData->sSigHeader.uiMeasurementCounter++;

	if(0x01 != ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsSasSteerAgVld)
	{
		/*TBD : Shall be check the +-*/
		ptr_Fcu_DimInputGenericData->fSteeringWheelAngle = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSasSteerAg; //* (3.141592653589793f/180.0);//unit convert : degree-->rad/s;
		ptr_Fcu_DimInputGenericData->fSteeringWheelAngleGrad = (float32)ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSteerAgRate;
	}
	else
	{
		ptr_Fcu_DimInputGenericData->fSteeringWheelAngle = 0;
		ptr_Fcu_DimInputGenericData->fSteeringWheelAngleGrad = 0;
	}

    /*20220723:AEB Code Review Add*/
    if(0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsSasSteerAgVld)
    {
        ptr_Fcu_DimInputGenericData->eSteeringWheelAngleStat = 0x0u;
    }
    else
    {
        ptr_Fcu_DimInputGenericData->eSteeringWheelAngleStat= 0x2u;
    }

	if(0x01 != ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuAccrPedlPosnVld)
	{
		/*20220723,AEB Code Review Add*/
		ptr_Fcu_DimInputGenericData->fAccelPedalPos = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_VcuAccrPedlPosn;
	}
	else
	{
		ptr_Fcu_DimInputGenericData->fAccelPedalPos = 0;
	}

    /*20220723,AEB Code Review Add*/
	ptr_Fcu_DimInputGenericData->eAccelPadelStat = (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuAccrPedlPosnVld == 0u)?0u:2u;

	switch(ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst)
	{
		case 0x0:
		{
			ptr_Fcu_DimInputGenericData->eTurnIndicator = 0x00u;
			break;
		}
		case 0x1:
		{
			ptr_Fcu_DimInputGenericData->eTurnIndicator = 0x01u;
			break;
		}
		case 0x2:
		{
			ptr_Fcu_DimInputGenericData->eTurnIndicator = 0x02u;
			break;
		}
		case 0x3:
		{
			ptr_Fcu_DimInputGenericData->eTurnIndicator = 0x04u;
			break;
		}
		default:
		{
			/*TODO : Doing nothing*/
			ptr_Fcu_DimInputGenericData->eTurnIndicator = 0x00u;
			break;
		}
	}

	if(0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IbBrkPedlStsGbVld)
	{
		if(0x65 == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IbBrkPedlStsGb)
		{
			ptr_Fcu_DimInputGenericData->eDriverBraking = 0x01u;
		}
		else
		{
			ptr_Fcu_DimInputGenericData->eDriverBraking = 0x00u;
		}
	}
	else
	{
		ptr_Fcu_DimInputGenericData->eDriverBraking = 0x02u;
	}

    if((0x00u == GET_FCU_HMI_COMMAND(FUNC_FCW)) || (0x01u == GET_FCU_HMI_COMMAND(FUNC_FCW)) || (0x02u == GET_FCU_HMI_COMMAND(FUNC_FCW)))
    {
        /*0x00: Early 0x01: Normal 0x02: Late*/
        if(TRUE == GET_FCU_FIMSTATE_FCW()) //FIM Function disable
        {            
		    /*  20221214,AEB Code Review Add:(if acc active and HU_FCWSetting != OFF fct = 0x02)*/
		    if(0x03 == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_ACC_ACCMode)  /*0x03: Active Control mode*/
		    {
			    ptr_Fcu_DimInputGenericData->eDriverSetting = 0x02u; //Late
		    }
			else
			{
                ptr_Fcu_DimInputGenericData->eDriverSetting = GET_FCU_HMI_COMMAND(FUNC_FCW);
			}			
		}
		else //When the event trigger ,shall be enable FIM to deactive algo.
		{
            ptr_Fcu_DimInputGenericData->eDriverSetting = 0x03u;
		}
	}
	else //Other value include (0x03: off 0x07: invalid)
	{	    
        ptr_Fcu_DimInputGenericData->eDriverSetting = 0x03u;
	}
	
	(void)Rte_Write_PP_Fcu_DimInputGenericData_DimInputGenericData(ptr_Fcu_DimInputGenericData);

}

/**
 * \functions Fcu_RxProcess_FctDimInputCustomData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctDimInputCustomData(DIMInputCustom_t* const ptr_Fcu_DimInputCustomData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal)
{
	sint64 s64_time_stamp = 0;

	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&s64_time_stamp);

	ptr_Fcu_DimInputCustomData->sSigHeader.eSigStatus = 1u;
	ptr_Fcu_DimInputCustomData->uiVersionNumber = 12;
	ptr_Fcu_DimInputCustomData->sSigHeader.uiTimeStamp = (uint32)s64_time_stamp;
	ptr_Fcu_DimInputCustomData->sSigHeader.uiCycleCounter++;
	ptr_Fcu_DimInputCustomData->sSigHeader.uiMeasurementCounter++;

	(void)Rte_Write_PP_Fcu_DimInputCustomData_DimInputCustomData(ptr_Fcu_DimInputCustomData);
}

/**
 * \functions Fcu_RxProcess_FctHeadInputGenericData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_FctHeadInputGenericData(HEADInputGeneric_t* const ptrFcu_HeadInputGenericData, const s_Fcu_Rte_Input_SignalData_t* const ptr_Fcu_Rte_input_Signal)
{
	sint64 time_stamp = 0;

	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&time_stamp);

    /*Merge 20220723  1->0 */
	ptrFcu_HeadInputGenericData->uiVersionNumber = 0;
	ptrFcu_HeadInputGenericData->sSigHeader.eSigStatus = 0x01;
	ptrFcu_HeadInputGenericData->sSigHeader.uiTimeStamp = (uint32)time_stamp;
	ptrFcu_HeadInputGenericData->sSigHeader.uiCycleCounter++;
	ptrFcu_HeadInputGenericData->sSigHeader.uiMeasurementCounter++;

	/*TBD : Not mapping,NOT FIND*/
	ptrFcu_HeadInputGenericData->eFunctionSwitch = 3221225471;/*Why*/

	ptrFcu_HeadInputGenericData->eMainSwitch = 0u;   //Default value

	(void)Rte_Write_PP_Fcu_HeadInputGenericData_HeadInputGenericData(ptrFcu_HeadInputGenericData);
}

/**
 * \functions Fcu_TxProcess_HeadOutputCustomData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
Fcu_Static FUNC(void, RTE_CODE) Fcu_TxProcess_HeadOutputCustomData(HEADOutputCustom_t* const ptr_Fcu_HeadOutputCustomData, const s_Fcu_AdasDomain_SignalData_t* const ptr_AdasDomain_Data, s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal)
{
	uint8 l_index_u8;
	uint8_t u8_HU_AutoBrakeEnable = 0;
    uint8_t u8_HU_FCW_Setting = 0;
	uint8_t u8_FC_FCWSettingStatus = 1;
	uint8_t u8_FC_FCWStatus = 0;
    uint8_t u8_FC_AEBStatus = 0;
    static uint8 u8_Fcu_CustomData_eFctChan = 0;
	static uint8 u8_Fcu_Signal_AEBActive_back = 0;
	static uint8 u8_Fcu_PreBrakeDecelEnabled_Flag = 0;
   
	u8_HU_AutoBrakeEnable = GET_FCU_HMI_COMMAND(FUNC_AEB);
	u8_HU_FCW_Setting = GET_FCU_HMI_COMMAND(FUNC_FCW);
	/*TODO : Read the data from FctAdapter*/
	(void)Rte_Read_RP_FctAdapter_HeadOutputCustomData_HeadOutputCustomData(ptr_Fcu_HeadOutputCustomData);
	/*TODO : ASIMA*/
#if (FCU_DEBUG_AEB_FOT_ENABLE != STD_ON)
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive = (ptr_Fcu_HeadOutputCustomData->sPreBrake.bPreBrakeDecelEnabled == 0x01u)?0x01u:0x00u;

	//When AEB is activated, the first frame of AEBCtrlType is recorded,This value is not updated further
	if((0x01u == Fcu_HeadOutputCustomData.sPreBrake.bPreBrakeDecelEnabled) && (0x00u == u8_Fcu_PreBrakeDecelEnabled_Flag))
	{
		u8_Fcu_CustomData_eFctChan = Fcu_HeadOutputCustomData.sPreBrake.eFctChan;
		u8_Fcu_PreBrakeDecelEnabled_Flag = 0x01u;
	}
	else if(0x00 == Fcu_HeadOutputCustomData.sPreBrake.bPreBrakeDecelEnabled)
	{
		u8_Fcu_CustomData_eFctChan = 0x00u;
		u8_Fcu_PreBrakeDecelEnabled_Flag = 0x00u;
	}

	if(((0x00u == u8_Fcu_Signal_AEBActive_back) && (0x01u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive))  // AEB is active.
		||((0x01u == u8_Fcu_Signal_AEBActive_back) && (0x00u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive)))  // AEB is no active.
	{
		switch(u8_Fcu_CustomData_eFctChan)
		{
			case 0x01:  //0x01 = 1
			{
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBCtrlType = 0x01u;
				break;
			}
			case 0x02:  //0x02 = 2
			{
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBCtrlType = 0x02u;
				break;
			}
			case 0x10:  //0x10 = 16
			{
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBCtrlType = 0x03u;
				break;
			}
			default:
			{
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBCtrlType = 0x00u;
				break;
			}
		}
	}

	u8_Fcu_Signal_AEBActive_back = ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive;
#endif

#if (DBG_AEB_DEBUG_ENABLE==STD_ON)
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetDeceleration = ptr_Fcu_HeadOutputCustomData->sPreBrake.fPreBrakeDecel;	//GW FC108
#else 
	if(ptr_Fcu_HeadOutputCustomData->sPreBrake.fPreBrakeDecel >= -2)
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetDeceleration = ptr_Fcu_HeadOutputCustomData->sPreBrake.fPreBrakeDecel;	//GW FC108
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetDeceleration = -2;
	}
#endif

	/*TODO : Check the AEB releated DTC status,use for Fim implemented*/
	// Cps_SignalPhyData_FC_AEBStatus = 0x03;
#if (FCU_DEBUG_AEB_FOT_ENABLE != STD_ON)
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBVehilceHoldReq = (ptr_Fcu_HeadOutputCustomData->sPreBrake.bPreBrakeStdstillRequest == 0x01u)?0x01u:0x00u;
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_PrefillActive = (ptr_Fcu_HeadOutputCustomData->sPrefill.bPrefillActive == 0x01)?0x01u:0x00u;
	
	switch(ptr_Fcu_HeadOutputCustomData->sWarnings.sAcuteDynamicHaptWarning.eWarnSens)
	{
		case 0x00:
		{
			ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AWBlevell = 0x00u;
			break;
		}
		case 0x01:
		{
			ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AWBlevell = 0x01u;
			break;
		}
		case 0x02:
		{
			ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AWBlevell = 0x02u;
			break;
		}
		case 0x03:
		{
			ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AWBlevell = 0x03u;
			break;
		}
		default:
		{
			ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AWBlevell = 0x05u;
			break;
		}
	}
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AWBActive = (ptr_Fcu_HeadOutputCustomData->sWarnings.sAcuteDynamicHaptWarning.eWarnSens != 0x00u)?0x01u:0x00u;
#endif

	if((0x00u != ptr_Fcu_HeadOutputCustomData->sWarnings.sAcuteDynamicWarning.eSignal) || \
		(0x01u == ptr_Fcu_HeadOutputCustomData->sWarnings.sPreStaticWarning.eSignal))
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive = 1u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive = 0u;
	}

    /*20220723 AEB Code Review Merge 
        eEBAOn_Inactive(0x0)
        eEBAOn_Moving(0x1)
        eEBAOn_Standing(0x2)
        eEBAOn_Halted(0x3)
        eEBAOn_CrossFrLeft(0x4)
        eEBAOn_CrossFrRight(0x5)
    */
    if(ptr_Fcu_HeadOutputCustomData->sWarnings.sPreStaticWarning.eSignal != 0u)
    {
        ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWLatentWarning = 1u;
    }
    else
    {
        ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWLatentWarning = 0u;
    }

	if(ptr_Fcu_HeadOutputCustomData->sWarnings.sPreStaticWarning.eSignal != 0u)
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_Voiceinfo_Aeb = 0x01;
	}
	else if(ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_Voiceinfo_Aeb == 0x01)
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_Voiceinfo_Aeb = 0x00;
	}

	if(ptr_Fcu_HeadOutputCustomData->sWarnings.sAcuteDynamicWarning.eSignal != 0)
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_Voiceinfo_Aeb = 0x02;
	}
	else if(ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_Voiceinfo_Aeb == 0x02)
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_Voiceinfo_Aeb = 0x00;
	}

#if (FCU_DEBUG_AEB_FOT_ENABLE != STD_ON)
    /*20220723 AEB Code Review Merge */
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_ABAlevel = ptr_Fcu_HeadOutputCustomData->sHBA.uiHBALevel;

	if(0x00u != ptr_Fcu_HeadOutputCustomData->sHBA.uiHBALevel)
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_ABAActive = 0x01u;
	}
	else 
    {
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_ABAActive = 0x0u;
	}
#endif

	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWPreWarning = (ptr_Fcu_HeadOutputCustomData->sWarnings.sAcuteDynamicWarning.eSignal == 0x00u)?0x00u:0x01u;

	/*TODO : FC_AEBTarge releated signal handling*/
	(void)Rte_Read_RP_Sdc_Cem_GenObjectList_GenObjectList(&Fcu_GenObjcetList);

	//get active object index
	l_index_u8 = ptr_Fcu_HeadOutputCustomData->EDROutput.ObjID;

	if((1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive) || (1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive))
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_OBJ_AEB_ID           = Fcu_GenObjcetList.aObject[l_index_u8].General.uiID;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetProb        = Fcu_GenObjcetList.aObject[l_index_u8].Qualifiers.uiProbabilityOfExistence;
		/*TODO : shall confirmed the mapping with Can*/
		// ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetStatus      = Fcu_GenObjcetList.aObject[l_index_u8].Attributes.eDynamicProperty;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetAx          = Fcu_GenObjcetList.aObject[l_index_u8].Kinematic.fArelX;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetAy          = Fcu_GenObjcetList.aObject[l_index_u8].Kinematic.fArelY;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetLatRelSpeed = Fcu_GenObjcetList.aObject[l_index_u8].Kinematic.fVrelY;//unit convert:m/s-->km/h
	}
	else
	{
		/*TODO : Send the default value*/
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_OBJ_AEB_ID     		  = 0xff;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetProb  		  = 0x0;
		// Cps_SignalPhyData_FC_AEBTargetStatus = 0x00;//This signal not find in Dbc
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetAx          = -16;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetAy          = -12;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetLatRelSpeed = -64;
	}

	/*Cps_SignalPhyData_FC_AEBTargetDetection*/
	if((1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive) || (1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive))
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetDetection = 0x01u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetDetection = 0x00u;
	}

	/*Cps_SignalPhyData_FC_AEBTargetType*/
	if((1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive) || (1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive))
	{
		EM_t_GenObjClassification l_objclassfication_u8;
		l_objclassfication_u8 = Fcu_GenObjcetList.aObject[l_index_u8].Attributes.eClassification;

		switch(l_objclassfication_u8)
		{
			case 1:
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 1u;
				break;
			case 2:
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 7u;
				break;
			case 3:
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 3u;
				break;
			case 4:
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 2u;
				break;
			case 5:
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 4u;
				break;
			default:
				ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 0xf;
				break;
		}
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetType = 0u;
	}

	if((1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive)||(1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive))
	{
		/*Cps_SignalPhyData_FC_AEBTargetLatRange*/
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetLatRange = Fcu_HeadOutputCustomData.EDROutput.fY_Dist;
		/*Cps_SignalPhyData_FC_AEBTargetRelSpeed*/
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetRelSpeed = Fcu_HeadOutputCustomData.EDROutput.fX_Vrel;
		/*Cps_SignalPhyData_FC_AEBTargetLngRange*/
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetLngRange = Fcu_HeadOutputCustomData.EDROutput.fX_Dist;
	}
	else
	{
		//Default Value
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetLatRange = 0xff;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetRelSpeed = 0xff;
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.f32_FC_AEBTargetLngRange = 0xff;
	}
	/*Cps_SignalPhyData_FC_AEBTargetmode
	canbus:
		0x0=none；
		0x1=video only mode；
		0x2=rader only mode；
		0x3=fusion mode

	fct:
	*/
	if((1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWActive) || (1u == ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBActive))
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetmode = 0x3u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBTargetmode = 0x0u;
	}

    /* EOL Mode Gate */
	if(EOL_MODE_OFF) //Not transmit into EOL mode
    {
        if(0x01u == u8_HU_AutoBrakeEnable) //Get AEB active signal from HMI.
        {
            if(TRUE == GET_FCU_FIMSTATE_AEB()) //FiM Function disable
            {
                u8_FC_AEBStatus = 0x01u; //On
			}
			else
			{   
	            u8_FC_AEBStatus = 0x03u; //Failure		
			}
		}
		else //When the event trigger ,shall be enable FIM to deactive algo.
		{
            u8_FC_AEBStatus = 0x00u; //Off
		}
	}
	else
	{
        u8_FC_AEBStatus = 0x00u; //Off
	}
	
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBEnable = u8_HU_AutoBrakeEnable; //Send the current HMI command to CAN bus.

	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBStatus = u8_FC_AEBStatus;

#if (FCU_DEBUG_AEB_FOT_ENABLE != STD_ON)

    /*0x00: Early 0x01: Normal 0x02: Late 0x03: off*/
    if((0x00u == u8_HU_FCW_Setting) || (0x01u == u8_HU_FCW_Setting) || (0x02u == u8_HU_FCW_Setting) || (0x03u == u8_HU_FCW_Setting))
    {
        if((0x03u == ptr_AdasDomain_Data->u8_Rte_ACC_ACCMode) && (0x03u != u8_HU_FCW_Setting)) /*0x03: Active Control mode*/
		{
			u8_FC_FCWSettingStatus = 0x02u;
		}
		else
		{
            u8_FC_FCWSettingStatus = u8_HU_FCW_Setting;
		}						

        if(0x03u == u8_HU_FCW_Setting)
		{
		    u8_FC_FCWStatus = 0x00u; //off			
		}
		else
		{
		    if(TRUE == GET_FCU_FIMSTATE_FCW()) //FIM Function disable
            {  
                u8_FC_FCWStatus = 0x01u; //on
			}
		    else //When the event trigger ,shall be enable FIM to deactive algo.
		    {   
                u8_FC_FCWStatus = 0x03u; //failure	
		    }	
		}
	}
	else //Other value is invalid
	{   
	    u8_FC_FCWSettingStatus = 0x01u; //initial value: Normal
	    u8_FC_FCWStatus = 0x00u; //off
	}
	
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWSettingStatus = u8_FC_FCWSettingStatus;
	
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWStatus = u8_FC_FCWStatus;
	
#endif	
}
