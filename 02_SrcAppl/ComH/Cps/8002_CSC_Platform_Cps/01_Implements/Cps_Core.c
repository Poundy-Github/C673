/**
 * \file Cps_Core.c
 *
 * \brief This file contains related data types of Cps.
 *
 * \version refer the Cps_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "Cps_Core.h"
#include "Com.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
e_Cps_InitStatus_t Cps_Core_InitStatus;
boolean Cps_Core_SignalRawData_Boolean;
boolean Cps_Core_SignalPhyData_Boolean;
uint8 Cps_Core_SignalRawData_Uint8;
uint8 Cps_Core_SignalPhyData_Uint8;
sint8 Cps_Core_SignalRawData_Sint8;
sint8 Cps_Core_SignalPhyData_Sint8;
uint16 Cps_Core_SignalRawData_Uint16;
uint16 Cps_Core_SignalPhyData_Uint16;
sint16 Cps_Core_SignalRawData_Sint16;
sint16 Cps_Core_SignalPhyData_Sint16;
uint32 Cps_Core_SignalRawData_Uint32;
uint32 Cps_Core_SignalPhyData_Uint32;
sint32 Cps_Core_SignalRawData_Sint32;
sint32 Cps_Core_SignalPhyData_Sint32;
float32 Cps_Core_SignalRawData_Float32;
float32 Cps_Core_SignalPhyData_Float32;
uint64 Cps_Core_SignalRawData_Uint64;
uint64 Cps_Core_SignalPhyData_Uint64;
sint64 Cps_Core_SignalRawData_Sint64;
sint64 Cps_Core_SignalPhyData_Sint64;
float64 Cps_Core_SignalRawData_Float64;
float64 Cps_Core_SignalPhyData_Float64;
s_Cps_SendSignalState_t Cps_Core_SendSignalState[CPS_SEND_SIGNAL_NUMBER];

/*==================[internal function declarations]========================*/
static void Cps_Core_SendSignal_InitFunction(void);
static void Cps_Core_SendSignal_MainFunction(void);
static void Cps_Core_Signal_replace_with_substitute_val(s_Cps_SendSignalConfig_t cfg,s_Cps_SendSignalState_t* state);

/*==================[external function definitions]=========================*/
/**
 * \functions Cps_Core_InitFunction
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
void Cps_Core_InitFunction(void)
{
	/*TODO : Initialized internal and external variables*/
	Cps_Core_SendSignal_InitFunction();

	/*TODO : Updated the InitStatus flag*/
	Cps_Core_InitStatus = Cps_InitStatus_Init;
}

/**
 * \functions Cps_Core_MainFunction
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
void Cps_Core_MainFunction(void)
{
	/*TODO: Check the Cpr_Core is initialization*/
	if(Cps_InitStatus_Init == Cps_Core_InitStatus)
	{
		/*TODO : Handling Tx Signals*/
		Cps_Core_SendSignal_MainFunction();
	}
	else
	{
		/*TODO: doing nothing or report Det*/
		return;
	}
}
/*==================[external function definitions]=========================*/
/**
 * \functions Cps_Core_ReceiveSignal_InitFunction
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
static void Cps_Core_SendSignal_InitFunction(void)
{
	uint16 i = 0x00;

	for(i = 0x00;i < CPS_SEND_SIGNAL_NUMBER; i++)
	{
		Cps_Core_SendSignalState[i].SignalSendCycleCounter = 0x00;
		Cps_Core_SendSignalState[i].SignalStatus = Cps_SigStatus_None;
#if (CPS_SEND_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
		Cps_Core_SendSignalState[i].SignalStatus_Last = Cps_SigStatus_None;
#endif
	}
}


/**
 * \functions Cps_Core_SendSignal_PhyDataGetFromVariable
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
static uint8 Cps_Core_SendSignal_PhyDataGetFromVariable(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			memcpy(&Cps_Core_SignalPhyData_Boolean, cfg.SignalPhyData, sizeof(boolean));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			memcpy(&Cps_Core_SignalPhyData_Uint8,cfg.SignalPhyData,  sizeof(uint8));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			memcpy(&Cps_Core_SignalPhyData_Uint16, cfg.SignalPhyData, sizeof(uint16));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			memcpy(&Cps_Core_SignalPhyData_Uint32,cfg.SignalPhyData,  sizeof(uint32));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			memcpy(&Cps_Core_SignalPhyData_Uint64,cfg.SignalPhyData,  sizeof(uint64));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			memcpy(&Cps_Core_SignalPhyData_Sint8,cfg.SignalPhyData,  sizeof(sint8));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			memcpy(&Cps_Core_SignalPhyData_Sint16, cfg.SignalPhyData, sizeof(sint16));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			memcpy(&Cps_Core_SignalPhyData_Sint32, cfg.SignalPhyData, sizeof(sint32));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			memcpy(&Cps_Core_SignalPhyData_Sint64, cfg.SignalPhyData, sizeof(sint64));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float32:
		{
			memcpy(&Cps_Core_SignalPhyData_Float32, cfg.SignalPhyData, sizeof(float32));
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float64:
		{
			memcpy(&Cps_Core_SignalPhyData_Float64, cfg.SignalPhyData, sizeof(float64));
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
 * \functions Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap
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
static uint8 Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(s_Cps_SendSignalConfig_t cfg,void *data)
{
	uint8 ret = 0x00;

	/*TODO : Check the null*/
	if(NULL_PTR != cfg.Op_ReadSignalPhyData)
	{
		ret = cfg.Op_ReadSignalPhyData(data);
	}
	else
	{
		ret = 0x01;
	}

	return ret;
}

/**
 * \functions Cps_Core_SendSignal_PhyDataGetFromFunction
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
static uint8 Cps_Core_SendSignal_PhyDataGetFromFunction(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;
	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Boolean);
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Uint8);
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Uint16);
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Uint32);
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Uint64);
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Sint8);
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Sint16);
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Sint32);
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Sint64);
			break;
		}

		case Cps_SigDataType_Float32:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Float32);
			break;
		}

		case Cps_SigDataType_Float64:
		{
			ret = Cps_Core_SendSignal_PhyDataGetFromFunction_Wrap(cfg, &Cps_Core_SignalPhyData_Float64);
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
 * \functions Cps_Core_SendSignal_GetPhyData
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
static uint8 Cps_Core_SendSignal_GetPhyData(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	if(Cps_SignalPhyGetType_Var == cfg.SignalPhyDataGetType)
	{
		ret = Cps_Core_SendSignal_PhyDataGetFromVariable(cfg);
	}
	else if(Cps_SignalPhyGetType_Func == cfg.SignalPhyDataGetType)
	{
		ret = Cps_Core_SendSignal_PhyDataGetFromFunction(cfg);
	}
	else
	{
		ret = 0x01;
	}

	return ret;
}

#if (CPS_SEND_SIGNAL_VALUE_RANGE_CHECK_ENABLE == STD_ON)
/**
 * \functions Cps_Core_SendSignal_PhyDataRangeCheck_User
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
static uint8 Cps_Core_SendSignal_PhyDataRangeCheck_User(s_Cps_SendSignalConfig_t cfg,s_Cps_SendSignalState_t* state)
{
	uint8 ret = 0x00;
	Std_ReturnType ret_val = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Boolean);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Uint8:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Uint8);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Uint16:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Uint16);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Uint32:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Uint32);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Uint64:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Uint64);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Sint8:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Sint8);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Sint16:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Sint16);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Sint32:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Sint32);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Sint64:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Sint64);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Float32:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Float32);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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

		case Cps_SigDataType_Float64:
		{
			if(NULL_PTR != cfg.Op_UserValueRangeCheck)
			{
				ret_val = cfg.Op_UserValueRangeCheck(&Cps_Core_SignalPhyData_Float64);
				if(0x00 != ret_val)
				{
					state->SignalStatus = Cps_SigStatus_ValueOutOfRange;
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
 * \functions Cps_Core_SendSignal_PhyDataRangeCheck_Lower
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
static uint8 Cps_Core_SendSignal_PhyDataRangeCheck_Lower(s_Cps_SendSignalConfig_t cfg,s_Cps_SendSignalState_t* state)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			boolean signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(boolean));
			if(Cps_Core_SignalPhyData_Boolean < signal_phy_value_lower/*(boolean)(*cfg.SignalPhyValue_Lower)*/)//may be report a compiler error
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			uint8 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint8));
			if(Cps_Core_SignalPhyData_Uint8 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			uint16 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint16));
			if(Cps_Core_SignalPhyData_Uint16 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			uint32 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint32));
			if(Cps_Core_SignalPhyData_Uint32 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			uint64 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint64));
			if(Cps_Core_SignalPhyData_Uint64 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			sint8 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint8));
			if(Cps_Core_SignalPhyData_Sint8 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			sint16 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint16));
			if(Cps_Core_SignalPhyData_Sint16 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			sint32 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint32));
			if(Cps_Core_SignalPhyData_Sint32 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			sint64 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint64));
			if(Cps_Core_SignalPhyData_Sint64 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float32:
		{
			float32 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(float32));
			if(Cps_Core_SignalPhyData_Float32 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float64:
		{
			float64 signal_phy_value_lower;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(float64));
			if(Cps_Core_SignalPhyData_Float64 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
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
 * \functions Cps_Core_SendSignal_PhyDataRangeCheck_Upper
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
static uint8 Cps_Core_SendSignal_PhyDataRangeCheck_Upper(s_Cps_SendSignalConfig_t cfg,s_Cps_SendSignalState_t* state)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			boolean signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(boolean));
			if(Cps_Core_SignalPhyData_Boolean > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			uint8 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint8));
			if(Cps_Core_SignalPhyData_Uint8 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			uint16 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint16));
			if(Cps_Core_SignalPhyData_Uint16 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			uint32 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint32));
			if(Cps_Core_SignalPhyData_Uint32 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			uint64 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint64));
			if(Cps_Core_SignalPhyData_Uint64 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			sint8 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint8));
			if(Cps_Core_SignalPhyData_Sint8 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			sint16 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint16));
			if(Cps_Core_SignalPhyData_Sint16 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			sint32 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint32));
			if(Cps_Core_SignalPhyData_Sint32 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			sint64 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint64));
			if(Cps_Core_SignalPhyData_Sint64 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float32:
		{
			float32 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(float32));
			if(Cps_Core_SignalPhyData_Float32 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				/*TODO : doing nothing*/
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float64:
		{
			float64 signal_phy_value_upper;
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(float64));
			if(Cps_Core_SignalPhyData_Float64 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
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
 * \functions Cps_Core_Signal_replace_with_substitute_val
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
static void Cps_Core_Signal_replace_with_substitute_val(s_Cps_SendSignalConfig_t cfg,s_Cps_SendSignalState_t* state)
{
	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			boolean signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(boolean));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Boolean = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Uint8:
		{
			uint8 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(uint8));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Uint8 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Uint16:
		{
			uint16 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(uint16));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Uint16 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Uint32:
		{
			uint32 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(uint32));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Uint32 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Uint64:
		{
			uint64 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(uint64));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Uint64 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Sint8:
		{
			sint8 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(sint8));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Sint8 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Sint16:
		{
			sint16 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(sint16));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Sint16 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Sint32:
		{
			sint32 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(sint32));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Sint32 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Sint64:
		{
			sint64 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(sint64));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Sint64 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Float32:
		{
			float32 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(float32));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Float32 = signal_phy_value_sub;
			}
		}
		case Cps_SigDataType_Float64:
		{
			float64 signal_phy_value_sub;
			memcpy(&signal_phy_value_sub, cfg.SignalErrSubsititutionValue, sizeof(float64));
			if((state->SignalStatus == Cps_SigStatus_ValueToSmall)||(state->SignalStatus == Cps_SigStatus_ValueToBig))
			{
				Cps_Core_SignalPhyData_Float64 = signal_phy_value_sub;
			}
		}
		default:
		{
			/*TODO : doing nothing*/
			break;
		}

	}
}

/**
 * \functions Cps_Core_SendSignal_PhyDataRangeCheck_Range
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

static uint8 Cps_Core_SendSignal_PhyDataRangeCheck_Range(s_Cps_SendSignalConfig_t cfg,s_Cps_SendSignalState_t* state)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			boolean signal_phy_value_lower;
			boolean signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(boolean));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(boolean));
			if(Cps_Core_SignalPhyData_Boolean < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			}
			else if(Cps_Core_SignalPhyData_Boolean > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			uint8 signal_phy_value_lower;
			uint8 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint8));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint8));
			if(Cps_Core_SignalPhyData_Uint8 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;

			}
			else if(Cps_Core_SignalPhyData_Uint8 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
				
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			uint16 signal_phy_value_lower;
			uint16 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint16));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint16));
			if(Cps_Core_SignalPhyData_Uint16 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Uint16 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
				
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			uint32 signal_phy_value_lower;
			uint32 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint32));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint32));
			if(Cps_Core_SignalPhyData_Uint32 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Uint32 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			uint64 signal_phy_value_lower;
			uint64 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(uint64));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(uint64));
			if(Cps_Core_SignalPhyData_Uint64 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Uint64 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			sint8 signal_phy_value_lower;
			sint8 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint8));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint8));
			if(Cps_Core_SignalPhyData_Sint8 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			
			}
			else if(Cps_Core_SignalPhyData_Sint8 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			sint16 signal_phy_value_lower;
			sint16 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint16));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint16));
			if(Cps_Core_SignalPhyData_Sint16 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
			
			}
			else if(Cps_Core_SignalPhyData_Sint16 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
				
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			sint32 signal_phy_value_lower;
			sint32 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint32));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint32));
			if(Cps_Core_SignalPhyData_Sint32 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Sint32 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
				
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			sint64 signal_phy_value_lower;
			sint64 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(sint64));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(sint64));
			if(Cps_Core_SignalPhyData_Sint64 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Sint64 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
		
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float32:
		{
			float32 signal_phy_value_lower;
			float32 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(float32));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(float32));
			if(Cps_Core_SignalPhyData_Float32 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Float32 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
				
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
			}
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float64:
		{
			float64 signal_phy_value_lower;
			float64 signal_phy_value_upper;
			memcpy(&signal_phy_value_lower, cfg.SignalPhyValue_Lower, sizeof(float64));
			memcpy(&signal_phy_value_upper, cfg.SignalPhyValue_Upper, sizeof(float64));
			if(Cps_Core_SignalPhyData_Float64 < signal_phy_value_lower)
			{
				state->SignalStatus = Cps_SigStatus_ValueToSmall;
				
			}
			else if(Cps_Core_SignalPhyData_Float64 > signal_phy_value_upper)
			{
				state->SignalStatus = Cps_SigStatus_ValueToBig;
			
			}
			else
			{
				state->SignalStatus = Cps_SigStatus_Normal;
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

	Cps_Core_Signal_replace_with_substitute_val(cfg,state);

	return ret;
}
#endif


/**
 * \functions Cps_Core_SendSignal_PhyDataRangeCheck
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
static uint8 Cps_Core_SendSignal_PhyDataRangeCheck(s_Cps_SendSignalConfig_t cfg, s_Cps_SendSignalState_t* state)
{
	uint8 ret = 0x00;

#if (CPS_SEND_SIGNAL_VALUE_RANGE_CHECK_ENABLE == STD_ON)
	/*TODO : Check the pointer*/
	if(NULL_PTR != state)
	{
		switch(cfg.SignalValueRangeCheckMode)
		{
			case Cps_SigDataValRangeCheck_None:
			{
				state->SignalStatus = Cps_SigStatus_Normal;
				ret = 0x00;
				break;
			}

			case Cps_SigDataValRangeCheck_Lower:
			{
				ret = Cps_Core_SendSignal_PhyDataRangeCheck_Lower(cfg,state);
				break;
			}

			case Cps_SigDataValRangeCheck_Upper:
			{
				ret = Cps_Core_SendSignal_PhyDataRangeCheck_Upper(cfg,state);
				break;
			}

			case Cps_SigDataValRangeCheck_Range:
			{
				ret = Cps_Core_SendSignal_PhyDataRangeCheck_Range(cfg,state);
				break;
			}

			case Cps_SigDataValRangeCheck_User:
			{
				ret = Cps_Core_SendSignal_PhyDataRangeCheck_User(cfg,state);
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


static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Boolean(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Boolean(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Boolean(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Boolean(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Boolean(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Boolean(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Boolean(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Boolean(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Boolean);			
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Boolean(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Boolean);	
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Boolean(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Boolean);	
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Boolean(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Boolean);	
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Boolean);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Boolean(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Boolean(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Boolean);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Boolean);
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


static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Uint8(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint8(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint8(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint8(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint8(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint8(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint8(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint8(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint8(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint8(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint8(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint8);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint8(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Uint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64,&Cps_Core_SignalRawData_Uint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint8);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Uint16(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint16(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint16(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint16(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint16(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint16(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint16(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint16(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint16(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint16(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint16(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32,&Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint16);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint16(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Uint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint16);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Uint32(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint32(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint32(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint32(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint32(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint32(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint32(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint32(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint32(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint32(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint32(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint32);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint32(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Uint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint32);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Uint64(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Uint64(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Uint64(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Uint64(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Uint64(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Uint64(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64,&Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Uint64(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Uint64(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Uint64(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Uint64(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Uint64(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Uint64);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Uint64(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Uint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Uint64);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Sint8(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint8(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint8(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint8(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint8(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint8(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint8(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint8(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint8(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint8(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint8(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint8);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint8(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Sint8(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint8);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint8);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Sint16(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint16(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint16(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint16(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint16(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint16(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint16(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint16(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint16(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint16(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint16(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint16);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint16(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Sint16(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint16);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint16);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Sint32(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint32(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint32(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint32(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint32(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint32(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint32(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint32(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint32(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint32(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64,&Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint32(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint32);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint32(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Sint32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint32);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Sint64(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Sint64(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Sint64(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Sint64(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Sint64(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Sint64(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Sint64(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Sint64(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Sint64(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Sint64(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64,&Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Sint64(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Sint64);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Sint64(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Sint64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Sint64);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Float32(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Float32(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Float32(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Float32(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Float32(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Float32(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Float32(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Float32(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Float32(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32,&Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Float32(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Float32(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Float32);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Float32(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Float32(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Float32);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Float32);
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

static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData_Float64(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalPhyDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Boolean2Float64(Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				/*TODO : Not support*/
				ret = 0x01;
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Boolean, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Uint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint82Float64(Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint82Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint8,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint8, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Uint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint162Float64(Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint162Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint16,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint16, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Uint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint322Float64(Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint322Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint32,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint32, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Uint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Uint642Float64(Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Uint642Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Uint64,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Uint64, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Sint8:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint82Float64(Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint82Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint8,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint8, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Sint16:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint162Float64(Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint162Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint16,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint16, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Sint32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint322Float64(Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint322Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint32,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint32, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Sint64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Sint642Float64(Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Sint642Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Sint64,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Sint64, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Float32:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float322Float64(Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float322Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float32,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float32, &Cps_Core_SignalRawData_Float64);
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

		case Cps_SigDataType_Float64:
		{
			if(Cps_SigDataConv_None == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_TypeConvert_Float642Float64(Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_DeLinear == cfg.SignalDataConversionMode)
			{
				ret = DataConvert_DeLinearConvert_Float642Float64(cfg.DeLinearMode_Factor, cfg.DeLinearMode_Offset, Cps_Core_SignalPhyData_Float64,&Cps_Core_SignalRawData_Float64);
			}
			else if(Cps_SigDataConv_User == cfg.SignalDataConversionMode)
			{
				if(NULL_PTR != cfg.Op_UserConvertMode)
				{
					ret = cfg.Op_UserConvertMode(&Cps_Core_SignalPhyData_Float64, &Cps_Core_SignalRawData_Float64);
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
 * \functions Cps_Core_SendSignal_PhyDataConvertToRawData
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
static uint8 Cps_Core_SendSignal_PhyDataConvertToRawData(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x00;

	switch(cfg.SignalRawDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Boolean(cfg);
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Uint8(cfg);
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Uint16(cfg);
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Uint32(cfg);
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Uint64(cfg);
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Sint8(cfg);
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Sint16(cfg);
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Sint32(cfg);
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Sint64(cfg);
			break;
		}

		case Cps_SigDataType_Float32:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Float32(cfg);
			break;
		}

		case Cps_SigDataType_Float64:
		{
			ret = Cps_Core_SendSignal_PhyDataConvertToRawData_Float64(cfg);
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
 * \functions Cps_Core_SendSignal_WriteSignalRawData
 *
 * \brief	According to the signal raw data type write raw data to Com.
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
static uint8 Cps_Core_SendSignal_WriteSignalRawData(s_Cps_SendSignalConfig_t cfg)
{
	uint8 ret = 0x01;

#if (CPS_USE_RTE_SEND_SIGNAL == STD_OFF)
	/*TODO : Read signal Raw data according the SignalRawDataType via call Com_ReceiveSignal*/
	switch(cfg.SignalRawDataType)
	{
		case Cps_SigDataType_Boolean:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Boolean);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint8:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Uint8);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint16:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Uint16);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint32:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Uint32);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Uint64:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Uint64);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint8:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Sint8);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint16:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Sint16);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint32:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Sint32);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Sint64:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Sint64);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float32:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Float32);
			ret = 0x00;
			break;
		}

		case Cps_SigDataType_Float64:
		{
			Com_SendSignal(cfg.SignalId,&Cps_Core_SignalRawData_Float64);
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
	if(NULL_PTR == cfg.Op_WriteSignal)
	{
		ret = 0x01;
	}
	else
	{
		/*TODO : Read signal Raw data according the SignalRawDataType via call Com_SendSignal*/
		switch(cfg.SignalRawDataType)
		{
			case Cps_SigDataType_Boolean:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Boolean);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Uint8:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Uint8);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Uint16:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Uint16);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Uint32:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Uint32);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Uint64:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Uint64);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Sint8:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Sint8);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Sint16:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Sint16);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Sint32:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Sint32);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Sint64:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Sint64);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Float32:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Float32);
				ret = 0x00;
				break;
			}

			case Cps_SigDataType_Float64:
			{
				cfg.Op_WriteSignal(&Cps_Core_SignalRawData_Float64);
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

/**
 * \functions Cps_Core_SendSignal_MainFunction
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
static void Cps_Core_SendSignal_MainFunction(void)
{
	uint16 i = 0x00;

	/*TODO : Iterate through all signals*/
	for(i = 0x00; i < CPS_SEND_SIGNAL_NUMBER; i++)
	{
		Cps_Core_SendSignalState[i].SignalSendCycleCounter++;
		/*TODO : Check the SignalSendCycleCounter is out of range*/
		if(Cps_Core_SendSignalState[i].SignalSendCycleCounter >= (Cps_SendSignalConfigTable[i].SignalSendCycle / CPS_MAIN_FUNCTION_PERIOD_TIME))
		{
			/*TODO : When the counter reached,clean,start next send cycle*/
			Cps_Core_SendSignalState[i].SignalSendCycleCounter = 0x00;

			/*TODO : Read phy value from Swc*/
			Cps_Core_SendSignal_GetPhyData(Cps_SendSignalConfigTable[i]);

			/*TODO : Check the signal Phy value range*/
			Cps_Core_SendSignal_PhyDataRangeCheck(Cps_SendSignalConfigTable[i], &Cps_Core_SendSignalState[i]);

			/*TODO : Convert the phy value to raw value*/
			Cps_Core_SendSignal_PhyDataConvertToRawData(Cps_SendSignalConfigTable[i]);

			/*TODO : Send the signal value to Com*/
			Cps_Core_SendSignal_WriteSignalRawData(Cps_SendSignalConfigTable[i]);

		}
		else
		{
			/*TODO: The Signal send cycle not reached,skip.*/
		}

		/*TODO : Notifiy the Signal status via Callout function*/
#if (CPR_RECEIVE_SIGNAL_STATUS_NOTIFICATION == STD_ON)
#if (CPS_SEND_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
		/*TODO : Check the Signal Status is Changed*/
		if(Cps_Core_SendSignalState[i].SignalStatus != Cps_Core_SendSignalState[i].SignalStatus_Last)
		{
			/*TODO : Check the Notification function pointer is NULL*/
			if(NULL_PTR != Cps_SendSignalConfigTable[i].Notify_SignalStatusChanged)
			{
				Cps_SendSignalConfigTable[i].Notify_SignalStatusChanged(Cps_Core_SendSignalState[i].SignalStatus, Cps_Core_SendSignalState[i].SignalStatus_Last);
			}
			else
			{
				/*TODO : doing nothing*/
			}

			/*TODO : Updated the SignalStatus_Last*/
			Cps_Core_SendSignalState[i].SignalStatus_Last = Cps_Core_SendSignalState[i].SignalStatus;
		}
		else
		{
			/*TODO : doing nothing*/
		}
#else
		if(NULL_PTR != Cpr_ReceiveSignalConfigTable[i].Notify_SignalStatusUpdated)
		{
			Cps_SendSignalConfigTable[i].Notify_SignalStatusUpdated(Cps_Core_SendSignalState[i].SignalStatus);
		}
#endif
#endif

	}
}
