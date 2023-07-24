/**
 * \file Cps_Type.h
 *
 * \brief This file contains related data types of Cps.
 *
 * \version refer the Cps_Core.h.
 *
 */

#ifndef _CPS_TYPE_H_
#define _CPS_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common_Type.h"
#include "Cps_Cfg.h"

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_Cps_InitStatus_t,Cps Init Status
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef enum
{
	Cps_InitStatus_None 	= 0x00,
	Cps_InitStatus_Uninit 	= 0x01,
	Cps_InitStatus_Init 	= 0x02,
	Cps_InitStatus_Max 		= 0xFF
}e_Cps_InitStatus_t;

/*
 * \brief 	e_Cps_SignalDataConversionMode_t,Signal Data Conversion Mode,different conversion modes,using different conversion formulas.
 *			Cps_SigDataConv_None : not convert,the raw data = phy data.
 *			Cps_SigDataConv_DeLinear : linear convert,the raw data = (phy data - offset) / Factor.
 *			Cps_SigDataConv_User : the convert mode definition by User,the implement in the call out function.
 * */
typedef enum
{
	Cps_SigDataConv_None 		= 0x00,
	Cps_SigDataConv_DeLinear 	= 0x01,
	Cps_SigDataConv_User 		= 0xFE,
	Cps_SigDataConv_Max 		= 0xFF
}e_Cps_SignalDataConversionMode_t;

/*
 * \brief 	e_Cps_SignalDataType_t,Signal Data Type
 * */
typedef enum
{
	Cps_SigDataType_None 	= 0x00,
	Cps_SigDataType_Boolean	= 0x01,
	Cps_SigDataType_Uint8 	= 0x02,
	Cps_SigDataType_Uint16 	= 0x03,
	Cps_SigDataType_Uint32 	= 0x04,
	Cps_SigDataType_Uint64 	= 0x05,
	Cps_SigDataType_Sint8 	= 0x06,
	Cps_SigDataType_Sint16 	= 0x07,
	Cps_SigDataType_Sint32 	= 0x08,
	Cps_SigDataType_Sint64 	= 0x09,
	Cps_SigDataType_Float32 = 0x0A,
	Cps_SigDataType_Float64 = 0x0B,
	Cps_SigDataType_Max 	= 0xFF
}e_Cps_SignalDataType_t;

/*
 * \brief 	e_Cps_SignalDataValueRangeCheckMode_t,
 * */
typedef enum
{
	Cps_SigDataValRangeCheck_None 	= 0x00,
	Cps_SigDataValRangeCheck_Lower 	= 0x01,
	Cps_SigDataValRangeCheck_Upper 	= 0x02,
	Cps_SigDataValRangeCheck_Range 	= 0x03,/*Include Lower and Upper check*/
	Cps_SigDataValRangeCheck_User 	= 0xFE,
	Cps_SigDataValRangeCheck_Max 	= 0xFF
}e_Cps_SignalDataValueRangeCheckMode_t;

/*
 * \brief 	e_Cps_SignalPhyGetType_t,the phy signal get type
 * */
typedef enum
{
	Cps_SignalPhyGetType_None		= 0x00,/*The Init status*/
	Cps_SignalPhyGetType_Var		= 0x01,/*The phy get from variables*/
	Cps_SignalPhyGetType_Func		= 0x02,/*The phy get from functions*/
	Cps_SignalPhyGetType_Max		= 0xFF
}e_Cps_SignalPhyGetType_t;

/*
 * \brief 	e_Cps_SignalStatus_t,Signal Status
 * */
typedef enum
{
	Cps_SigStatus_None 				= 0x00,/*The Init status*/
	Cps_SigStatus_Normal 			= 0x10,
	Cps_SigStatus_ValueOutOfRange	= 0x20,/*Only use for the Cps_SigDataValRangeCheck_User mode*/
	Cps_SigStatus_ValueToSmall	 	= 0x21,
	Cps_SigStatus_ValueToBig	 	= 0x22,
	Cps_SigStatus_Max 				= 0xFF
}e_Cps_SignalStatus_t;

/*
 * \brief 	s_Cps_SendSignalConfig_t,Send Signal Configuration Parameters struct
 * */
typedef struct
{
#if (CPS_USE_RTE_SEND_SIGNAL == STD_OFF)
	/*
	 * \brief 	SignalId,the Signal Id which is from ComHandleId
	 * 			The data elements available if the CPS_USE_RTE_SEND_SIGNAL setting to STD_OFF
	 * */
	uint16 SignalId;
#else
	/*
	 * \brief 	Op_WriteSignal,this is a function pointer which using for write Signal via Rte interface
	 *
	 * 	TBD : Shall be confirmed this function parameters data type.
	 * 		  General,the parameters not use the pointer
	 *
	 * */
	Std_ReturnType (*Op_WriteSignal)(void *data);
#endif
	/*
	 * \brief 	SignalSendCycle,The send cycle is write data to com cycle.
	 * 			General,the SignalSendCycle shall be equal or less than the message cycle base on Dbc.
	 * 			The unit is ms.
	 * */
	uint16 SignalSendCycle;
	/*
	 * \brief 	SignalDataConversionMode,The signal raw data and phy data conversion mode
	 * */
	e_Cps_SignalDataConversionMode_t SignalDataConversionMode;
	/*
	 * \brief 	SignalRawDataType,The signal raw data type
	 * */
	e_Cps_SignalDataType_t SignalRawDataType;
	/*
	 * \brief 	SignalPhyDataType,The signal phy data type
	 * */
	e_Cps_SignalDataType_t SignalPhyDataType;
	/*
	 * \brief 	DeLinearMode_Factor,the linear convert formula of factor
	 * 			Note : The parameters only use the Cps_SigDataConv_DeLinear
	 * */
	float DeLinearMode_Factor;
	/*
	 * \brief 	DeLinearMode_Offset,the linear convert formula of offset
	 * 			Note : The parameters only use the Cps_SigDataConv_DeLinear
	 * */
	float DeLinearMode_Offset;
	/*
	 * \brief 	Op_UserConvertMode,this is a function pointer which using for conversion the signal phy data to raw data by user
	 * 			Note : when the SignalDataConversionMode is not setting to Cps_SigDataConv_User,the parameters shall fill the NULL_PTR
	 * */
	Std_ReturnType (*Op_UserConvertMode)(void* phy_data, void* raw_data);
#if (CPS_SEND_SIGNAL_VALUE_RANGE_CHECK_ENABLE == STD_ON)
	/*
	 * \brief 	SignalValueRangeCheckMode,
	 * */
	e_Cps_SignalDataValueRangeCheckMode_t SignalValueRangeCheckMode;
	/*
	 * \brief 	SignalPhyValue_Lower,the variable using check the signal value range.
	 * */
	void* SignalPhyValue_Lower;
	/*
	 * \brief 	SignalPhyValue_Upper,the variable using check the signal value range.
	 * */
	void* SignalPhyValue_Upper;
	/*
	 * \brief 	SignalErrSubsititutionValue,If the phy value out of range,use the SignalErrSubsititutionValue send to Com.
	 * */
	void* SignalErrSubsititutionValue;
	/*
	 * \brief 	Op_UserValueRangeCheck,this is a function pointer which using for check the signal phy data range by user
	 * 			Note : The parameters only use the CPS_SEND_SIGNAL_VALUE_RANGE_CHECK_ENABLE setting to STD_ON.
	 * */
	Std_ReturnType (*Op_UserValueRangeCheck)(void* data);
#endif

	/*
	 * \brief 	SignalPhyDataGetType,the phy variable get type.
	 *
	 * */
	e_Cps_SignalPhyGetType_t SignalPhyDataGetType;

	/*
	 * \brief 	SignalPhyData,the variable using stored the signal phy data.
	 *
	 * 			Note : 	When the SignalPhyDataGetType setting to Cps_SignalPhyGetType_Var,the data elements shall set to non null
	 * 					else the data elements shall fill to NULL_PTR
	 * */
	void* SignalPhyData;
	/*
	 * \brief 	Op_WriteSignalPhyData,this is a function pointer which using for write the signal phy data to Rte or other components via function.
	 *
	 * 			Note : 	When the SignalPhyDataGetType setting to Cps_SignalPhyGetType_Func,the data elements shall set to non null
	 * 					else the data elements shall fill to NULL_PTR
	 * */
	Std_ReturnType (*Op_ReadSignalPhyData)(void* data);

#if (CPS_SEND_SIGNAL_STATUS_NOTIFICATION == STD_ON)
#if (CPS_SEND_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/*
	 * \brief 	Notify_SignalStatusChanged,this is a function pointer which using for Notify the signal status to other components.
	 * 			Note :
	 * */
	void (*Notify_SignalStatusChanged)(e_Cps_SignalStatus_t status,e_Cps_SignalStatus_t status_last);
#else
	/*
	 * \brief 	Notify_SignalStatusUpdated,this is a function pointer which using for Notify the signal status to other components.
	 * 			Note :
	 *
	 * 			like the Rte_WriteFlag_xxx
	 * */
	void (*Notify_SignalStatusUpdated)(e_Cps_SignalStatus_t state);
#endif

#endif
}s_Cps_SendSignalConfig_t;

/*
 * \brief 	s_Cps_SendSignalState_t,Send Signal state Parameters struct which it indication the signal state of runtime
 * */
typedef struct
{
	/*
	 * \brief 	SignalSendCycleCounter,
	 * */
	uint16 SignalSendCycleCounter;
	/*
	 * \brief 	SignalStatus,
	 * */
	e_Cps_SignalStatus_t SignalStatus;
#if (CPS_SEND_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/*
	 * \brief 	SignalStatus_Last,
	 * */
	e_Cpr_SignalStatus_t SignalStatus_Last;
#endif
}s_Cps_SendSignalState_t;



#endif /* _CPS_TYPE_H_ */
