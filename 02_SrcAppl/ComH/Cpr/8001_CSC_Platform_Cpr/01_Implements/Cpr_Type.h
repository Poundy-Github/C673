/**
 * \file Cpr_Type.h
 *
 * \brief This file contains related data types of Cpr.
 *
 * \version refer the Cpr_Core.h.
 *
 */

#ifndef _CPR_TYPE_H_
#define _CPR_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common_Type.h"
#include "Cpr_Cfg.h"


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_Cpr_InitStatus_t,Cpr Init Status
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef enum
{
	Cpr_InitStatus_None 	= 0x00,
	Cpr_InitStatus_Uninit 	= 0x01,
	Cpr_InitStatus_Init 	= 0x02,
	Cpr_InitStatus_Max 		= 0xFF
}e_Cpr_InitStatus_t;

/*
 * \brief 	e_Cpr_SignalDataConversionMode_t,Signal Data Conversion Mode,different conversion modes,using different conversion formulas.
 *			Cpr_SigDataConv_None : not convert,the phy data = raw data.
 *			Cpr_SigDataConv_Linear : linear convert,the phy data = raw data * Factor + offset.
 *			Cpr_SigDataConv_User : the convert mode definition by User,the implement in the call out function.
 * */
typedef enum
{
	Cpr_SigDataConv_None 	= 0x00,
	Cpr_SigDataConv_Linear 	= 0x01,
	Cpr_SigDataConv_User 	= 0xFE,
	Cpr_SigDataConv_Max 	= 0xFF
}e_Cpr_SignalDataConversionMode_t;

/*
 * \brief 	e_Cpr_SignalDataValueRangeCheckMode_t,
 * */
typedef enum
{
	Cpr_SigDataValRangeCheck_None 	= 0x00,
	Cpr_SigDataValRangeCheck_Lower 	= 0x01,
	Cpr_SigDataValRangeCheck_Upper 	= 0x02,
	Cpr_SigDataValRangeCheck_Range 	= 0x03,/*Include Lower and Upper check*/
	Cpr_SigDataValRangeCheck_User 	= 0xFE,
	Cpr_SigDataValRangeCheck_Max 	= 0xFF
}e_Cpr_SignalDataValueRangeCheckMode_t;

/*
 * \brief 	e_Cpr_SignalDataType_t,Signal Data Type
 * */
typedef enum
{
	Cpr_SigDataType_None 	= 0x00,
	Cpr_SigDataType_Boolean	= 0x01,
	Cpr_SigDataType_Uint8 	= 0x02,
	Cpr_SigDataType_Uint16 	= 0x03,
	Cpr_SigDataType_Uint32 	= 0x04,
	Cpr_SigDataType_Uint64 	= 0x05,
	Cpr_SigDataType_Sint8 	= 0x06,
	Cpr_SigDataType_Sint16 	= 0x07,
	Cpr_SigDataType_Sint32 	= 0x08,
	Cpr_SigDataType_Sint64 	= 0x09,
	Cpr_SigDataType_Float32 = 0x0A,
	Cpr_SigDataType_Float64 = 0x0B,
	Cpr_SigDataType_Max 	= 0xFF
}e_Cpr_SignalDataType_t;

/*
 * \brief 	e_Cpr_SignalStatus_t,Signal Status
 * */
typedef enum
{
	Cpr_SigStatus_None 				= 0x00,/*The Init status*/
	Cpr_SigStatus_Normal 			= 0x10,
	Cpr_SigStatus_Timeout 			= 0x20,
	Cpr_SigStatus_ValueOutOfRange	= 0x30,/*Only use for the Cpr_SigDataValRangeCheck_User mode*/
	Cpr_SigStatus_ValueToSmall	 	= 0x31,
	Cpr_SigStatus_ValueToBig	 	= 0x32,
	Cpr_SigStatus_ReadFailed		= 0x40,
	Cpr_SigStatus_Max 				= 0xFF
}e_Cpr_SignalStatus_t;

/*
 * \brief 	e_Cpr_SignalPhyStoredType_t,the phy signal stored type
 * */
typedef enum
{
	Cpr_SignalPhyStoredType_None		= 0x00,/*The Init status*/
	Cpr_SignalPhyStoredType_Var			= 0x01,/*The phy stored in variables*/
	Cpr_SignalPhyStoredType_Func		= 0x02,/*The phy stored via functions*/
	Cpr_SignalPhyStoredType_Max			= 0xFF
}e_Cpr_SignalPhyStoredType_t;
/*
 * \brief 	s_Cpr_ReceiveSignalConfig_t,Receive Signal Configuration Parameters struct
 * */
typedef struct
{
#if (CPR_USE_RTE_RECEIVE_SIGNAL == STD_OFF)
	/*
	 * \brief 	SignalId,the Signal Id which is from ComHandleId
	 * 			The data elements available if the CPR_USE_RTE_RECEIVE_SIGNAL setting to STD_OFF
	 * */
	uint16 SignalId;
#else
	/*
	 * \brief 	Op_ReadSignal,this is a function pointer which using for Read Signal via Rte interface
	 * */
	Std_ReturnType (*Op_ReadSignal)(void *data);
#endif
	/*
	 * \brief 	SignalMonitorCycle,Cpr monitor signal cycle which it is shall less than the Signal receive cycle.
	 * 			The unit is ms.
	 * */
	uint16 SignalMonitorCycle;
#if (CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE == STD_ON)
	/*
	 * \brief 	SignalTimeoutCycle,The Cpr using the parameter to signal timeout status.
	 * 			The timout cycle shall more than the SignalMonitorCycle,and it Integer multiples the SignalMonitorCycle.
	 * 			The unit is ms.
	 * */
	uint16 SignalTimeoutCycle;
	/*
	 * \brief 	Op_IsUpdatedOfSignal,this is a function pointer which using for get the signal updated flag
	 * 			The implemented shall be check,TODO
	 * */
	uint8 (*Op_IsUpdatedOfSignal)(void);

#endif
	/*
	 * \brief 	SignalDataConversionMode,The signal raw data and phy data conversion mode
	 * */
	e_Cpr_SignalDataConversionMode_t SignalDataConversionMode;
	/*
	 * \brief 	SignalRawDataType,The signal raw data type
	 * */
	e_Cpr_SignalDataType_t SignalRawDataType;
	/*
	 * \brief 	SignalPhyDataType,The signal phy data type
	 * */
	e_Cpr_SignalDataType_t SignalPhyDataType;
	/*
	 * \brief 	LinearMode_Factor,the linear convert formula of factor
	 * 			Note : The parameters only use the Cpr_SigDataConv_Linear
	 * */
	float LinearMode_Factor;
	/*
	 * \brief 	LinearMode_Factor,the linear convert formula of offset
	 * 			Note : The parameters only use the Cpr_SigDataConv_Linear
	 * */
	float LinearMode_Offset;
	/*
	 * \brief 	Op_UserConvertMode,this is a function pointer which using for conversion the signal raw data to phy data by user
	 * 			Note : when the SignalDataConversionMode is not setting to Cpr_SigDataConv_User,the parameters shall fill the NULL_PTR
	 * */
	Std_ReturnType (*Op_UserConvertMode)(void* raw_data,void* phy_data);
#if (CPR_RECEIVE_SIGNAL_VALUE_RANGE_CHECK_ENABLE == STD_ON)
	/*
	 * \brief 	SignalValueRangeCheckMode,
	 * */
	e_Cpr_SignalDataValueRangeCheckMode_t SignalValueRangeCheckMode;
	/*
	 * \brief 	SignalRawData_Lower,the variable using check the signal value range.
	 * */
	void* SignalRawData_Lower;
	/*
	 * \brief 	SignalRawData_Upper,the variable using check the signal value range.
	 * */
	void* SignalRawData_Upper;
	/*
	 * \brief 	Op_UserValueRangeCheck,this is a function pointer which using for check the signal raw data range by user
	 * 			Note : The parameters only use the CPR_RECEIVE_SIGNAL_VALUE_RANGE_CHECK_ENABLE setting to STD_ON.
	 * */
	Std_ReturnType (*Op_UserValueRangeCheck)(void* data);
#endif

	/*
	 * \brief 	SignalPhyDataStoredType,the phy variable stored type.
	 *
	 * */
	e_Cpr_SignalPhyStoredType_t SignalPhyDataStoredType;

	/*
	 * \brief 	SignalPhyData,the variable using stored the signal phy data.
	 *
	 * 			Note : 	When the PhyStoredType setting to Cpr_SignalPhyStoredType_Var,the data elements shall set to non null
	 * 					else the data elements shall fill to NULL_PTR
	 * */
	void* SignalPhyData;

	/*
	 * \brief 	Op_WriteSignalPhyData,this is a function pointer which using for write the signal phy data to Rte or other components via function.
	 *
	 * 			Note : 	When the PhyStoredType setting to Cpr_SignalPhyStoredType_Func,the data elements shall set to non null
	 * 					else the data elements shall fill to NULL_PTR
	 * */
	Std_ReturnType (*Op_WriteSignalPhyData)(void* data);

#if (CPR_RECEIVE_SIGNAL_STATUS_NOTIFICATION == STD_ON)

#if (CPR_RECEIVE_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/*
	 * \brief 	Notify_SignalStatusChanged,this is a function pointer which using for Notify the signal status to other components.
	 * 			Note :
	 * */
	void (*Notify_SignalStatusChanged)(e_Cpr_SignalStatus_t status,e_Cpr_SignalStatus_t status_last);
#else
	/*
	 * \brief 	Notify_SignalStatusUpdated,this is a function pointer which using for Notify the signal status to other components.
	 * 			Note :
	 *
	 * 			like the Rte_WriteFlag_xxx
	 * */
	void (*Notify_SignalStatusUpdated)(uint8 state, uint16 SignalId);
#endif

#endif
}s_Cpr_ReceiveSignalConfig_t;

/*
 * \brief 	s_Cpr_ReceiveSignalState_t,Receive Signal state Parameters struct which it indication the signal state of runtime
 * */
typedef struct
{
	/*
	 * \brief 	SignalMonitorCycleCounter,
	 * */
	uint16 SignalMonitorCycleCounter;
#if (CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE == STD_ON)
	/*
	 * \brief 	SignalTimeoutCycleCounter,
	 * */
	uint16 SignalTimeoutCycleCounter;
#endif
	/*
	 * \brief 	SignalMonitorCycleCounter,
	 * */
	e_Cpr_SignalStatus_t SignalStatus;
#if (CPR_RECEIVE_SIGNAL_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/*
	 * \brief 	LinearMode_Factor,the linear convert formula of offset
	 * 			Note : The parameters only use the Cpr_SigDataConv_Linear
	 * */
	e_Cpr_SignalStatus_t SignalStatus_Last;
#endif
}s_Cpr_ReceiveSignalState_t;

#endif /* _CPR_TYPE_H_ */
