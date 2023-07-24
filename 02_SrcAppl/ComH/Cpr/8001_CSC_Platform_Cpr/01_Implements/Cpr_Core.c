/**
 * \file Cpr_Core.c
 *
 * \brief Implement Can communication process of recevied
 *
 * \version refer the Cpr_Core.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Cpr_Core.h"
#include "Com.h"
#include "CSC_Platform_Common.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
e_Cpr_InitStatus_t Cpr_Core_InitStatus = Cpr_InitStatus_Uninit;
boolean Cpr_Core_SignalRawData_Boolean;
boolean Cpr_Core_SignalPhyData_Boolean;
uint8 Cpr_Core_SignalRawData_Uint8;
uint8 Cpr_Core_SignalPhyData_Uint8;
sint8 Cpr_Core_SignalRawData_Sint8;
sint8 Cpr_Core_SignalPhyData_Sint8;
uint16 Cpr_Core_SignalRawData_Uint16;
uint16 Cpr_Core_SignalPhyData_Uint16;
sint16 Cpr_Core_SignalRawData_Sint16;
sint16 Cpr_Core_SignalPhyData_Sint16;
uint32 Cpr_Core_SignalRawData_Uint32;
uint32 Cpr_Core_SignalPhyData_Uint32;
sint32 Cpr_Core_SignalRawData_Sint32;
sint32 Cpr_Core_SignalPhyData_Sint32;
float32 Cpr_Core_SignalRawData_Float32;
float32 Cpr_Core_SignalPhyData_Float32;
uint64 Cpr_Core_SignalRawData_Uint64;
uint64 Cpr_Core_SignalPhyData_Uint64;
sint64 Cpr_Core_SignalRawData_Sint64;
sint64 Cpr_Core_SignalPhyData_Sint64;
float64 Cpr_Core_SignalRawData_Float64;
float64 Cpr_Core_SignalPhyData_Float64;

s_Cpr_ReceiveSignalState_t Cpr_ReceiveSignalState[CPR_REVEIVE_SIGNAL_NUMBER];
/*==================[internal function declarations]========================*/
static void Cpr_Core_ReceiveSignal_InitFunction(void);
static void Cpr_Core_ReceiveSignal_MainFunction(void);

/*==================[external function definitions]=========================*/
/**
 * \functions Cpr_Core_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void Cpr_Core_InitFunction(void)
{
	/*TODO : Initialized internal and external variables*/
	Cpr_Core_ReceiveSignal_InitFunction();

	/*TODO : Updated the InitStatus flag*/
	Cpr_Core_InitStatus = Cpr_InitStatus_Init;
}

/**
 * \functions Cpr_Core_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void Cpr_Core_MainFunction(void)
{
	/*TODO: Check the Cpr_Core is initialization*/
	if(Cpr_InitStatus_Init == Cpr_Core_InitStatus)
	{
		/*TODO : Handling Rx Signals*/
		Cpr_Core_ReceiveSignal_MainFunction();
	}
	else
	{
		/*TODO: doing nothing or report Det*/
		return;
	}
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Cpr_Core_ReceiveSignal_InitFunction
 *
 * \brief Init the Signal Receive related variable
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
static void Cpr_Core_ReceiveSignal_InitFunction(void)
{
	uint16 i = 0x00;

	for(i = 0x00;i < CPR_REVEIVE_SIGNAL_NUMBER; i++)
	{
		Cpr_ReceiveSignalState[i].SignalMonitorCycleCounter = 0x00;
#if (CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE == STD_ON)
		Cpr_ReceiveSignalState[i].SignalTimeoutCycleCounter = 0x00;
#endif
		Cpr_ReceiveSignalState[i].SignalStatus = Cpr_SigStatus_None;
#if (CPR_RECEIVE_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
		Cpr_ReceiveSignalState[i].SignalStatus_Last = Cpr_SigStatus_None;
#endif
	}

}

/**
 * \functions Cpr_Core_ReceiveSignal_IsUpdatedFlag
 *
 * \brief handling the Signal Receive Updated Flag
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return uint8,UpdatedFlag,
 * 				 0x00 : the Signal not Updated
 * 				 0x01 : the Signal has been Updated
 *
 * \comments When the parameters fill NULL_PTR of Op_IsUpdatedOfSignal for s_Cpr_ReceiveSignalConfig_t,the software think it has been updated.
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_IsUpdatedFlag(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 UpdatedFlag = 0x00;
#if (CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE == STD_ON)
	/*TODO : Check the function pointer is null*/
	if(NULL_PTR != cfg.Op_IsUpdatedOfSignal)
	{
		UpdatedFlag = cfg.Op_IsUpdatedOfSignal();
	}
	else
	{
		UpdatedFlag = 0x01;
	}
#else
	UpdatedFlag = 0x01;
#endif

	return UpdatedFlag;
}

/**
 * \functions Cpr_Core_ReceiveSignal_ReadSignalRawData
 *
 * \brief	According to the signal raw data type get signal raw data,and it stored in local variable.
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_ReadSignalRawData(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x01;

#if (CPR_USE_RTE_RECEIVE_SIGNAL == STD_OFF)
	/*TODO : Read signal Raw data according the SignalRawDataType via call Com_ReceiveSignal*/
	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Boolean);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Uint8);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Uint16);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Uint32);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Uint64);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Sint8);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Sint16);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Sint32);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Sint64);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Float32);
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			Com_ReceiveSignal(cfg.SignalId,&Cpr_Core_SignalRawData_Float64);
			ret = 0x00;
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}
#else
	/*TODO : Check the funtion pointer is null*/
	if(NULL_PTR == cfg.Op_ReadSignal)
	{
		ret = 0x01;
	}
	else
	{
		/*TODO : Read signal Raw data according the SignalRawDataType via call Com_ReceiveSignal*/
		switch(cfg.SignalRawDataType)
		{
			case Cpr_SigDataType_Boolean:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Boolean);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Uint8:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Uint8);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Uint16:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Uint16);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Uint32:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Uint32);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Uint64:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Uint64);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Sint8:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Sint8);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Sint16:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Sint16);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Sint32:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Sint32);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Sint64:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Sint64);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Float32:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Float32);
				ret = 0x00;
				break;
			}

			case Cpr_SigDataType_Float64:
			{
				cfg.Op_ReadSignal(&Cpr_Core_SignalRawData_Float64);
				ret = 0x00;
				break;
			}

			default:
			{
				ret = 0x01;
				break;
			}
		}
	}
#endif

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Boolean(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Boolean(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Boolean(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Boolean(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Boolean(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Boolean(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Boolean(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Boolean(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Boolean(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Boolean(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Boolean(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Boolean(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Boolean(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Boolean);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Boolean);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}
	return ret;
}


static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint8(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint8(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : Doing nothing*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint8(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint8(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint8(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint8(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint8(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint8(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint8(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint8(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint8(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint8(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Uint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint16(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint16(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : Doing nothing*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint16(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint16(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint16(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32,&Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint16(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64,&Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint16(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint16(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint16(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint16(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint16(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint16(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Uint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint32(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint32(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : Doing nothing*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint32(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint32(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint32(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32,&Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint32(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64,&Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint32(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint32(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint32(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint32(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint32(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint32(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Uint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint64(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint64(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint64(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint64(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint64(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32,&Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint64(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64,&Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint64(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint64(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint64(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint64(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint64(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint64(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Uint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Uint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint8(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint8(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint8(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint8(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint8(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint8(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint8(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8,&Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint8(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint8(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint8(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint8(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint8(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Sint8(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint8);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint8);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint16(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint16(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint16(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint16(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint16(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint16(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint16(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8,&Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint16(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16,&Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint16(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32,&Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint16(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint16(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint16(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Sint16(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint16);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint16);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint32(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint32(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint32(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint32(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint32(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint32(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint32(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8,&Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint32(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16,&Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint32(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32,&Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint32(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint32(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint32(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Sint32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint64(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint64(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint64(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint64(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint64(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint64(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint64(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint64(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint64(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint64(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint64(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32,&Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint64(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Sint64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Sint64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Float32(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Float32(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Float32(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Float32(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Float32(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Float32(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Float32(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Float32(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Float32(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Float32(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Float32(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32,&Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Float32(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Float32(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Float32);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Float32);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Float64(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Float64(Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Boolean, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Float64(Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint82Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint8,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint8, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Float64(Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint162Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint16,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint16, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Float64(Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint322Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint32,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint32, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Float64(Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Uint642Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Uint64,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Uint64, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Float64(Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint82Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint8,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint8, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Float64(Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint162Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint16,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint16, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Float64(Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint322Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint32,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint32, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Float64(Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Sint642Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Sint64,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Sint64, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Float64(Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float322Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float32,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float32, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(Cpr_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Float64(Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_Linear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_LinearConvert_Float642Float64(cfg.LinearMode_Factor, cfg.LinearMode_Offset, Cpr_Core_SignalRawData_Float64,&Cpr_Core_SignalPhyData_Float64);
			}
			else if(Cpr_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cpr_Core_SignalRawData_Float64, &Cpr_Core_SignalPhyData_Float64);
				}
				else
				{
					ret = 0x01;
				}
			}
			else
			{
				/*TODO : Other Data Converion Mode not support*/
				ret = 0x01;
			}
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_RawDataConvertToPhyData
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_RawDataConvertToPhyData(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Boolean(cfg);
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint8(cfg);
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint16(cfg);
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint32(cfg);
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Uint64(cfg);
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint8(cfg);
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint16(cfg);
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint32(cfg);
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Sint64(cfg);
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Float32(cfg);
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			ret = Cpr_Core_ReceiveSignal_RawDataConvertToPhyData_Float64(cfg);
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

#if (CPR_RECEIVE_SIGNAL_VALUE_RANGE_CHECK_ENABLE == STD_ON)
/**
 * \functions Cpr_Core_ReceiveSignal_RawDataRangeCheck_User
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_RawDataRangeCheck_User(s_Cpr_ReceiveSignalConfig_t cfg,s_Cpr_ReceiveSignalState_t* state)
{
	uint8 ret = 0x00;
	Std_ReturnType ret_val = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Boolean);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Uint8);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Uint16);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Uint32);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Uint64);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Sint8);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Sint16);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Sint32);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Sint64);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Float32);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cpr_Core_SignalRawData_Float64);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cpr_SigStatus_ValueOutOfRange;
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		default:
		{
			/*TODO : doing nothing*/
			ret = 0x01;
			break;
		}
	}
	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_RawDataRangeCheck_Lower
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_RawDataRangeCheck_Lower(s_Cpr_ReceiveSignalConfig_t cfg,s_Cpr_ReceiveSignalState_t* state)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			boolean signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(boolean));
			if(Cpr_Core_SignalRawData_Boolean < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			uint8 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint8));
			if(Cpr_Core_SignalRawData_Uint8 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			uint16 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint16));
			if(Cpr_Core_SignalRawData_Uint16 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			uint32 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint32));
			if(Cpr_Core_SignalRawData_Uint32 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			uint64 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint64));
			if(Cpr_Core_SignalRawData_Uint64 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			sint8 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint8));
			if(Cpr_Core_SignalRawData_Sint8 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			sint16 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint16));
			if(Cpr_Core_SignalRawData_Sint16 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			sint32 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint32));
			if(Cpr_Core_SignalRawData_Sint32 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			sint64 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint64));
			if(Cpr_Core_SignalRawData_Sint64 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			float32 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(float32));
			if(Cpr_Core_SignalRawData_Float32 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			float64 signal_raw_value_lower;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(float32));
			if(Cpr_Core_SignalRawData_Float64 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		default:
		{
			/*TODO : doing nothing*/
			ret = 0x01;
			break;
		}
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_RawDataRangeCheck_Upper
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_RawDataRangeCheck_Upper(s_Cpr_ReceiveSignalConfig_t cfg,s_Cpr_ReceiveSignalState_t* state)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			boolean signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(boolean));
			if(Cpr_Core_SignalRawData_Boolean > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			uint8 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint8));
			if(Cpr_Core_SignalRawData_Uint8 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			uint16 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint16));
			if(Cpr_Core_SignalRawData_Uint16 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			uint32 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint32));
			if(Cpr_Core_SignalRawData_Uint32 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			uint64 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint64));
			if(Cpr_Core_SignalRawData_Uint64 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			sint8 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint8));
			if(Cpr_Core_SignalRawData_Sint8 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			sint16 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint16));
			if(Cpr_Core_SignalRawData_Sint16 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			sint32 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint32));
			if(Cpr_Core_SignalRawData_Sint32 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			sint64 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint64));
			if(Cpr_Core_SignalRawData_Sint64 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			float32 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(float32));
			if(Cpr_Core_SignalRawData_Float32 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			float64 signal_raw_value_upper;
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(float64));
			if(Cpr_Core_SignalRawData_Float64 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		default:
		{
			/*TODO : doing nothing*/
			ret = 0x01;
			break;
		}
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_RawDataRangeCheck_Range
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_RawDataRangeCheck_Range(s_Cpr_ReceiveSignalConfig_t cfg,s_Cpr_ReceiveSignalState_t* state)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			boolean signal_raw_value_lower;
			boolean signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(boolean));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(boolean));
			if(Cpr_Core_SignalRawData_Boolean < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Boolean > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			uint8 signal_raw_value_lower;
			uint8 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint8));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint8));
			if(Cpr_Core_SignalRawData_Uint8 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Uint8 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			uint16 signal_raw_value_lower;
			uint16 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint16));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint16));
			if(Cpr_Core_SignalRawData_Uint16 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Uint16 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			uint32 signal_raw_value_lower;
			uint32 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint32));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint32));
			if(Cpr_Core_SignalRawData_Uint32 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Uint32 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			uint64 signal_raw_value_lower;
			uint64 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(uint64));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(uint64));
			if(Cpr_Core_SignalRawData_Uint64 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Uint64 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			sint8 signal_raw_value_lower;
			sint8 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint8));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint8));
			if(Cpr_Core_SignalRawData_Sint8 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Sint8 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			sint16 signal_raw_value_lower;
			sint16 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint16));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint16));
			if(Cpr_Core_SignalRawData_Sint16 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Sint16 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			sint32 signal_raw_value_lower;
			sint32 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint32));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint32));
			if(Cpr_Core_SignalRawData_Sint32 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Sint32 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			sint64 signal_raw_value_lower;
			sint64 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(sint64));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(sint64));
			if(Cpr_Core_SignalRawData_Sint64 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Sint64 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			float32 signal_raw_value_lower;
			float32 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(float32));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(float32));
			if(Cpr_Core_SignalRawData_Float32 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Float32 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			float64 signal_raw_value_lower;
			float64 signal_raw_value_upper;
			memcpy(&signal_raw_value_lower, cfg.SignalRawData_Lower, sizeof(float64));
			memcpy(&signal_raw_value_upper, cfg.SignalRawData_Upper, sizeof(float64));
			if(Cpr_Core_SignalRawData_Float64 < signal_raw_value_lower)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToSmall;
			}
			else if(Cpr_Core_SignalRawData_Float64 > signal_raw_value_upper)
			{
				state->SignalStatus = Cpr_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		default:
		{
			/*TODO : doing nothing*/
			ret = 0x01;
			break;
		}
	}

	return ret;
}
#endif

/**
 * \functions Cpr_Core_ReceiveSignal_RawDataRangeCheck
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_RawDataRangeCheck(s_Cpr_ReceiveSignalConfig_t cfg, s_Cpr_ReceiveSignalState_t* state)
{
	uint8 ret = 0x00;

#if (CPR_RECEIVE_SIGNAL_VALUE_RANGE_CHECK_ENABLE == STD_ON)
	/*TODO : Check the pointer*/
	if(NULL_PTR != state)
	{
		switch(cfg.SignalValueRangeCheckMode)
		{
			case Cpr_SigDataValRangeCheck_None:
			{
				state->SignalStatus = Cpr_SigStatus_Normal;
				ret = 0x00;
				break;
			}

			case Cpr_SigDataValRangeCheck_Lower:
			{
				ret = Cpr_Core_ReceiveSignal_RawDataRangeCheck_Lower(cfg,state);
				break;
			}

			case Cpr_SigDataValRangeCheck_Upper:
			{
				ret = Cpr_Core_ReceiveSignal_RawDataRangeCheck_Upper(cfg,state);
				break;
			}

			case Cpr_SigDataValRangeCheck_Range:
			{
				ret = Cpr_Core_ReceiveSignal_RawDataRangeCheck_Range(cfg,state);
				break;
			}

			case Cpr_SigDataValRangeCheck_User:
			{
				ret = Cpr_Core_ReceiveSignal_RawDataRangeCheck_User(cfg,state);
				break;
			}

			default:
			{
				/*TODO : doing nothing*/
				ret = 0x01;
				break;
			}
		}
	}
	else
	{
		ret = 0x01;
	}
#endif

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_RawDataConvertToPhyData
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_PhyDataUpdatedToVariable(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Boolean, sizeof(boolean));
//			cfg.SignalPhyData = Cpr_Core_SignalPhyData_Boolean;//in this way,the compiler will reoprt a error
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Uint8, sizeof(uint8));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Uint8;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Uint16, sizeof(uint16));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Uint16;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Uint32, sizeof(uint32));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Uint32;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Uint64, sizeof(uint64));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Uint64;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Sint8, sizeof(sint8));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Sint8;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Sint16, sizeof(sint16));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Sint16;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Sint32, sizeof(sint32));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Sint32;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Sint64, sizeof(sint64));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Sint64;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Float32, sizeof(float32));
//			(float32*)(*cfg.SignalPhyData) = Cpr_Core_SignalPhyData_Float32;
			ret = 0x00;
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			memcpy(cfg.SignalPhyData, &Cpr_Core_SignalPhyData_Float64, sizeof(float64));
//			*cfg.SignalPhyData = Cpr_Core_SignalPhyData_Float64;
			ret = 0x00;
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(s_Cpr_ReceiveSignalConfig_t cfg,void *data)
{
	uint8 ret = 0x00;

	/*TODO : Check the null*/
	if(NULL_PTR != cfg.Op_WriteSignalPhyData)
	{
		ret = cfg.Op_WriteSignalPhyData(data);
	}
	else
	{
		ret = 0x01;
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;
	switch(cfg.SignalPhyDataType)
	{
		case Cpr_SigDataType_Boolean:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Boolean);
			break;
		}

		case Cpr_SigDataType_Uint8:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Uint8);
			break;
		}

		case Cpr_SigDataType_Uint16:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Uint16);
			break;
		}

		case Cpr_SigDataType_Uint32:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Uint32);
			break;
		}

		case Cpr_SigDataType_Uint64:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Uint64);
			break;
		}

		case Cpr_SigDataType_Sint8:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Sint8);
			break;
		}

		case Cpr_SigDataType_Sint16:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Sint16);
			break;
		}

		case Cpr_SigDataType_Sint32:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Sint32);
			break;
		}

		case Cpr_SigDataType_Sint64:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Sint64);
			break;
		}

		case Cpr_SigDataType_Float32:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Float32);
			break;
		}

		case Cpr_SigDataType_Float64:
		{
			ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction_Wrap(cfg, &Cpr_Core_SignalPhyData_Float64);
			break;
		}

		default:
		{
			ret = 0x01;
			break;
		}
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction
 *
 * \brief
 *
 * \parameters-in cfg
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments
 *
 *
 */
static uint8 Cpr_Core_ReceiveSignal_PhyDataUpdated(s_Cpr_ReceiveSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	if(Cpr_SignalPhyStoredType_Var == cfg.SignalPhyDataStoredType)
	{
		ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToVariable(cfg);
	}
	else if(Cpr_SignalPhyStoredType_Func == cfg.SignalPhyDataStoredType)
	{
		ret = Cpr_Core_ReceiveSignal_PhyDataUpdatedToFunction(cfg);
	}
	else
	{
		ret = 0x01;
	}

	return ret;
}

/**
 * \functions Cpr_Core_ReceiveSignal_MainFunction
 *
 * \brief handling the Signal Receive
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
static void Cpr_Core_ReceiveSignal_MainFunction(void)
{
	uint8 ret = 0x01;
	uint16 i = 0x00;

	/*TODO : Iterate through all signals*/
	for(i = 0x00; i < CPR_REVEIVE_SIGNAL_NUMBER; i++)
	{
		Cpr_ReceiveSignalState[i].SignalMonitorCycleCounter++;
#if (CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE == STD_ON)
		Cpr_ReceiveSignalState[i].SignalTimeoutCycleCounter++;
		/*TODO : Check the SignalTimeoutCycleCounter is out of range*/
		if(Cpr_ReceiveSignalState[i].SignalTimeoutCycleCounter >= (Cpr_ReceiveSignalConfigTable[i].SignalTimeoutCycle / CPR_MAIN_FUNCTION_PERIOD_TIME))
		{
			Cpr_ReceiveSignalState[i].SignalTimeoutCycleCounter = Cpr_ReceiveSignalConfigTable[i].SignalTimeoutCycle / CPR_MAIN_FUNCTION_PERIOD_TIME;
			Cpr_ReceiveSignalState[i].SignalStatus = Cpr_SigStatus_Timeout;
		}
		else
		{
			/*TODO : nothing doing*/
		}
#endif
		/*TODO : Check the SignalMonitorCycleCounter is out of range*/
		if(Cpr_ReceiveSignalState[i].SignalMonitorCycleCounter >= (Cpr_ReceiveSignalConfigTable[i].SignalMonitorCycle / CPR_MAIN_FUNCTION_PERIOD_TIME))
		{
			/*TODO : When the counter reached,clean,start next monitor cycle*/
			Cpr_ReceiveSignalState[i].SignalMonitorCycleCounter = 0x00;

			/*TODO : Check the Signal Updated Flag*/
			if(0x01 == Cpr_Core_ReceiveSignal_IsUpdatedFlag(Cpr_ReceiveSignalConfigTable[i]))
			{
#if (CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE == STD_ON)
				/*TODO : When the counter reached,clean,start next check cycle*/
				Cpr_ReceiveSignalState[i].SignalTimeoutCycleCounter = 0x00;;
#endif
				/*TODO : Read Receive Signal from Com*/
				ret = Cpr_Core_ReceiveSignal_ReadSignalRawData(Cpr_ReceiveSignalConfigTable[i]);
				if(0x00 == ret)
				{
					/*TODO : Check the signal raw data range */
					Cpr_Core_ReceiveSignal_RawDataRangeCheck(Cpr_ReceiveSignalConfigTable[i],&Cpr_ReceiveSignalState[i]);

					/*TODO : Convert the Raw Data to Phy Data */
					Cpr_Core_ReceiveSignal_RawDataConvertToPhyData(Cpr_ReceiveSignalConfigTable[i]);

					/*TODO : Updated the signal phy data to Rte or Local variable*/
					Cpr_Core_ReceiveSignal_PhyDataUpdated(Cpr_ReceiveSignalConfigTable[i]);

					/*TBD : Check the signal phy data range*/
				}
				else
				{
					/*TODO : If the ReadSignalRawData failed,Updated the SignalStatus*/
					Cpr_ReceiveSignalState[i].SignalStatus = Cpr_SigStatus_ReadFailed;
				}
			}
			else
			{
				/*TODO : nothing doing*/
			}

		}
		else
		{
			/*TODO: The Signal cycle not reached,skip.*/
		}

		/*TODO : Notifiy the Signal status via Callout function*/
#if (CPR_RECEIVE_SIGNAL_STATUS_NOTIFICATION == STD_ON)
#if (STD_ON == CPR_RECEIVE_SIGNAL_STATUS_CHANGED_NOTIFICATION)
		/*TODO : Check the Signal Status is Changed*/
		if(Cpr_ReceiveSignalState[i].SignalStatus != Cpr_ReceiveSignalState[i].SignalStatus_Last)
		{
			/*TODO : Check the Notification function pointer is NULL*/
			if(NULL_PTR != Cpr_ReceiveSignalConfigTable[i].Notify_SignalStatusChanged)
			{
				Cpr_ReceiveSignalConfigTable[i].Notify_SignalStatusChanged(Cpr_ReceiveSignalState[i].SignalStatus, Cpr_ReceiveSignalState[i].SignalStatus_Last);
			}
			else
			{
				/*TODO : doing nothing*/
			}

			/*TODO : Updated the SignalStatus_Last*/
			Cpr_ReceiveSignalState[i].SignalStatus_Last = Cpr_ReceiveSignalState[i].SignalStatus;
		}
		else
		{
			/*TODO : doing nothing*/
		}
#else
		if(NULL_PTR != Cpr_ReceiveSignalConfigTable[i].Notify_SignalStatusUpdated)
		{
			Cpr_ReceiveSignalConfigTable[i].Notify_SignalStatusUpdated( (uint8)Cpr_ReceiveSignalState[i].SignalStatus, Cpr_ReceiveSignalConfigTable[i].SignalId );
		}
#endif
#endif
	}
}

