/**
 * \file   Fcu_Common.c
 *
 * \brief  Get the signal from CAN and Soc ,then send it to all Fcu submodule.
 *
 * \version refer the Fcu_Common.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/* ==================[Includes]=============================================== */
#include "Fcu_Common.h"
#include "Cdm.h"
#include "Dbg_Cfg.h"
#include "Cps_Lcfg.h"

/*==================[internal data]=========================================*/
/*==================[.data]==============================*/
static boolean HMI_Factory_mode_flag = FALSE;

/*==================[.bss]==============================*/
static BaseCtrlData_t Fcu_BaseCtrlData;
static FCTCtrlData_t Fcu_FctCtrlData;

/*==================[external data]==========================================*/
uint8 FCU_SwitchData[7] = {0};
uint8 FCU_HMISwitch[7] = {0};
s_Esh_ErrorStatusInfo_t Fcu_ErrorStatusInfo;

/*==================[internal function declarations]=========================*/
static void Fcu_Process_CtrlData(void);
static void Fcu_Hmi_FactoryMode(s_Fcu_Rte_Output_SignalData_t *ptr_Fcu_Rte_Output_Signal);
static void Fcu_Hmi_InitFunction(s_Fcu_Rte_Output_SignalData_t *ptr_Fcu_Rte_Output_Signal);
static void Fcu_ReadProcess_Fim(void);
static uint8 Fcu_ReadNVMData_HMISwitch(uint8 *Data);
static uint8 Fcu_WriteNVMData_HMISwitch(uint8 *Data);

/*==================[external function definitions]=========================*/
/**
 * \functions Fcu_Common_InitFunction
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
FUNC(void, RTE_CODE) Fcu_Common_InitFunction (s_Fcu_Rte_Output_SignalData_t *ptr_Fcu_Rte_Output_Signal)
{
	/*TODO : Clean the local variable*/   	
	Fcu_Hmi_InitFunction(ptr_Fcu_Rte_Output_Signal);
}

/**
 * \functions Fcu_Common_MainFunction
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
FUNC(void, RTE_CODE) Fcu_Common_MainFunction (void)
{
	(void)Fcu_ReadNVMData_HMISwitch(FCU_SwitchData);
	Fcu_ReadProcess_Fim();
	Fcu_Process_CtrlData();
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Fcu_Process_CtrlData
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
static void Fcu_Process_CtrlData(void)
{
	sint64 time_stamp = 0;
	static uint32 Debug_OpMode_Ctrl = 0;
	/*TODO : get time stamp*/
	(void)Time_GetTimeStampMs(&time_stamp);

	Fcu_BaseCtrlData.uiVersionNumber = 2u/*BASE_CTRL_DATA_INTFVER*/;/*Shall set the value,if not ,the Lcf not running*/
	Fcu_BaseCtrlData.sSigHeader.eSigStatus = 1u;/*BASE_OM_RESET*/
	Fcu_BaseCtrlData.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	Fcu_BaseCtrlData.sSigHeader.uiCycleCounter++;
	Fcu_BaseCtrlData.sSigHeader.uiMeasurementCounter++;

	Fcu_FctCtrlData.uiVersionNumber = 0u;/*Shall confirmed by DF*/
	Fcu_FctCtrlData.sSigHeader.eSigStatus = 1u;/*FCT_MOD_INIT*/
	Fcu_FctCtrlData.sSigHeader.uiTimeStamp = (uint32)time_stamp;
	Fcu_FctCtrlData.sSigHeader.uiCycleCounter++;
	Fcu_FctCtrlData.sSigHeader.uiMeasurementCounter++;
    
    Fcu_FctCtrlData.fCycleTime++;

	Debug_OpMode_Ctrl++;
	/*TODO : Check ECU state from Esm*/
	if(Debug_OpMode_Ctrl >= 10)
	{
		Debug_OpMode_Ctrl = 1000;
		Fcu_BaseCtrlData.eOpMode = 0x04u;/*BASE_OM_RUN*/
		Fcu_FctCtrlData.OpMode = 0x02u;/*FCT_MOD_RUNNING*/
	}
	else
	{
		Fcu_BaseCtrlData.eOpMode = 0x01u;/*BASE_OM_RESET*/
		Fcu_FctCtrlData.OpMode = 0x01u;/*FCT_MOD_INIT*/
	}

    (void)Rte_Write_PP_Fcu_BaseCtrlData_BaseCtrlData(&Fcu_BaseCtrlData);
    //Ioc_Write_Ioc_BaseCtrlData(Fcu_BaseCtrlData);
    (void)Rte_Write_PP_Fcu_FctCtrlData_FctCtrlData(&Fcu_FctCtrlData);
   // Ioc_Write_Ioc_FctCtrlData(Fcu_FctCtrlData);
}


/**
 * \functions Fcu_Hmi_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments:
 *
 */
static void Fcu_Hmi_InitFunction(s_Fcu_Rte_Output_SignalData_t *ptr_Fcu_Rte_Output_Signal)
{
    //uint8 ret = E_NOT_OK;
	//uint8 SwitchData[7] = {0};

    (void)Fcu_ReadNVMData_HMISwitch(FCU_SwitchData);

	if((FCU_SwitchData[FUNC_Factory_Mode] != 0x5A) && (HMI_Factory_mode_flag == FALSE))//Factory mode
	{
		HMI_Factory_mode_flag = TRUE;
		Fcu_Hmi_FactoryMode(ptr_Fcu_Rte_Output_Signal);
		return;
	}

	HMI_Factory_mode_flag = FALSE;

	FCU_SwitchData[FUNC_AEB] = 0x1u;
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBEnable = 0x1;

	if(FCU_SwitchData[FUNC_FCW] == 0x3u)
	{
		FCU_SwitchData[FUNC_FCW] = 0x0u;
	}
	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWSettingStatus = FCU_SwitchData[FUNC_FCW];

	ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAEnableStatus = FCU_SwitchData[FUNC_FAB];

	ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus  = FCU_SwitchData[FUNC_LDW_or_LKA];

	/*FC_LASWarningModeSelectionSts
		0x1=sound；
		0x1=sound；
		0x2=vibration；
		0x3=sound and vibration；
	*/
	if(FCU_SwitchData[FUNC_LDW_Warning] == 2u)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts = 1u;
	}
	else if(FCU_SwitchData[FUNC_LDW_Warning] == 3u)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts = 2u;
	}
	else if(FCU_SwitchData[FUNC_LDW_Warning] == 4u)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts = 3u;
	}
	else
	{

	}

	/*FC_ELKEnableStatus
		0x0=off；
		0x1=on；
	*/
	if(FCU_SwitchData[FUNC_ELK] == 2u)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKEnableStatus = 1u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKEnableStatus  = 0u;
	}

	if(0x0u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus = 0x7u;
	}

	(void)Fcu_WriteNVMData_HMISwitch(FCU_SwitchData);
    //return;
}


/**
 * \functions Fcu_Hmi_FactoryMode
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments:
 *
 */
static void Fcu_Hmi_FactoryMode(s_Fcu_Rte_Output_SignalData_t *ptr_Fcu_Rte_Output_Signal)
{
	if(HMI_Factory_mode_flag == TRUE)//Factory mode
	{
		FCU_SwitchData[FUNC_AEB] = 0x1u;//ON
    	ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_AEBEnable = FCU_SwitchData[FUNC_AEB];

		FCU_SwitchData[FUNC_FCW] = 0x1u;//Normal
		ptr_Fcu_Rte_Output_Signal->Aeb_Data.u8_FC_FCWSettingStatus  = FCU_SwitchData[FUNC_FCW];

		FCU_SwitchData[FUNC_FAB] = 0x0u;//OFF
    	ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAEnableStatus = FCU_SwitchData[FUNC_FAB];

		FCU_SwitchData[FUNC_LDW_Warning] = 0x3u;//vibration
    	ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts = FCU_SwitchData[FUNC_LDW_Warning];

		FCU_SwitchData[FUNC_LDW_or_LKA] = 0x1u;//LDW
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus = FCU_SwitchData[FUNC_LDW_or_LKA];

		FCU_SwitchData[FUNC_ELK] = 0x1u;//OFF
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKEnableStatus = FCU_SwitchData[FUNC_ELK];

		FCU_SwitchData[FUNC_Factory_Mode] = 0x5A;
		(void)Fcu_WriteNVMData_HMISwitch(FCU_SwitchData);
	}

    //return;
}

/**
 * \functions Fcu_TxProcess_FuncSwitch_WriteNvm
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments:
 *
 */
FUNC(void, RTE_CODE)  Fcu_TxProcess_FuncSwitch_WriteNvm(uint8 Switch_ID, uint8 Func_Enable)
{
	switch(Switch_ID)
	{
		case FUNC_FCW:
		{
			//FCU_HMISwitch->FCW_Switch = Func_Enable;
			FCU_SwitchData[FUNC_FCW] = Func_Enable;
			break;
		}
		case FUNC_FAB:
		{
			//FCU_HMISwitch->FAB_Switch = Func_Enable;
			FCU_SwitchData[FUNC_FAB] = Func_Enable;
			break;
		}
		case FUNC_LDW_or_LKA:
		{
			//FCU_HMISwitch->LDW_Switch = Func_Enable;
			FCU_SwitchData[FUNC_LDW_or_LKA] = Func_Enable;
			break;
		}
		case FUNC_LDW_Warning:
		{
			//FCU_HMISwitch->LDW_Warning = Func_Enable;
			FCU_SwitchData[FUNC_LDW_Warning] = Func_Enable;
			break;
		}
		case FUNC_ELK:
		{
			//FCU_HMISwitch->ELK_Switch = Func_Enable;
			FCU_SwitchData[FUNC_ELK] = Func_Enable;
			break;
		}
		case FUNC_AEB:
		{
			FCU_SwitchData[FUNC_AEB] = Func_Enable;
			break;
		}
		default:
		{
			break;
		}
	}
	(void)Fcu_WriteNVMData_HMISwitch(FCU_SwitchData);

	//return;
}

/**
 * \functions Fcu_ReadProcess_Fim
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
static void Fcu_ReadProcess_Fim(void)
{
#if(STD_ON == DBG_FIM_MODULE_ENABLE)
	(void)Rte_Read_RP_Fcu_SRI_Esh_ErrorStatusInfo_DE_Esh_ErrorStatusInfo(&Fcu_ErrorStatusInfo);
#else 
	Fcu_ErrorStatusInfo.AEB = TRUE;
	Fcu_ErrorStatusInfo.ELK = TRUE;
	Fcu_ErrorStatusInfo.FCW = TRUE;
	Fcu_ErrorStatusInfo.HLA = TRUE;
	Fcu_ErrorStatusInfo.LDW = TRUE;
	Fcu_ErrorStatusInfo.LKA = TRUE;
	Fcu_ErrorStatusInfo.TSA = TRUE;
	Fcu_ErrorStatusInfo.FAB = TRUE;
#endif
	//return;
}


static uint8 Fcu_ReadNVMData_HMISwitch(uint8 *Data)
{
	uint8 ret = E_OK;
	
	ret =  Rte_Call_RP_Cdm_FcuBlockOp_Cdm_ReadBlock(NvMConf_NvMBlockDescriptor_NvM_Block_HMISwitchStatus, Data);
	
	return ret;
}

static uint8 Fcu_WriteNVMData_HMISwitch(uint8 *Data)
{
	uint8 ret = E_NOT_OK;

	ret = Rte_Call_RP_Cdm_FcuBlockOp_Cdm_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_Block_HMISwitchStatus, Data);
	
	return ret;
}


