/* ==================[Includes]=============================================== */
#include "Sdc_SendInterface.h"
#include "Sdc_Core_Type.h"
#include "Sdc_Misc.h"
#include "Sdc_SendHandler.h"
#include "SpiSync_Type.h"
#include <Rte_type.h>
#include "Sdc_Perception.h"

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo_Tsync;
s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo_Utc;
s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo_Dtc;

s_SipSync_TimeSyncMessage_t Sdc_TimeSyncMsg;
s_SipSync_TimeSyncMessage_t Sdc_TimeSyncUtc;
/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/
FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocCpuInfo_Read(void* socSystemInfo, uint16 length);


/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"


void Sdc_SendInterface_InitFunction(void)
{

}
void Sdc_SendInterface_DeInitFunction(void)
{
    //TODO
}

void Sdc_SendInterface_MainFunction(void)
{
    //TODO : receive the rte date from other module
    //time sync
    // Rte_Read_RP_SendInterface_Tsync(&Sdc_eventMsgInfo_Tsync);
    //utc
    // Rte_Read_RP_SendInterface_Tsync(&Sdc_eventMsgInfo_Utc);
    //dtc
    // Rte_Read_RP_SendInterface_Tsync(&Sdc_eventMsgInfo_Dtc);

}


// uint8 Sdc_SendInterface_TimeSyncMsg(const void *data, uint16 length)
// {
//     s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
//     Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
//     Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_SocTimeSync;
//     memcpy(&Sdc_eventMsgInfo.data[0], data, length);
//     Sdc_eventMsgInfo.len = length;
//     Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
//     return 0;
// }

// uint8 Sdc_SendInterface_TimeSyncUtc(const s_Sdc_Timesync_st *ts_info)
// {
//     s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
//     Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0604_UtcTime;
//     Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_UTCSync;
//     memcpy(&Sdc_eventMsgInfo.data[0], (uint8 *)ts_info, sizeof(s_Sdc_Timesync_st));
//     Sdc_eventMsgInfo.len = sizeof(s_Sdc_Timesync_st);
//     Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
//     return 0;
// }

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_TimeSyncMsg (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length)
{
    s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
    Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
    Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_SocTimeSync;
    memcpy(&Sdc_eventMsgInfo.data[0], data, length);
    memcpy(&Sdc_TimeSyncMsg, data, length);
    Sdc_eventMsgInfo.len = length;
    Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_TimeSyncMsg (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length) */


FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_TimeSyncUtc (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length)
{
    s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
    Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0604_UtcTime;
    Sdc_eventMsgInfo.subId = e_Sdc_SpiMsgSubType_UTCSync;
    memcpy(&Sdc_eventMsgInfo.data[0], data, length);
    memcpy(&Sdc_TimeSyncUtc, data, length);
    Sdc_eventMsgInfo.len = length;
    Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
    return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_TimeSyncUtc (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length) */

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_J3_PerceptionData_Read(void* perceptionData, uint16 length)	//called by Fcu_Hla.c
{
    Sdc_Perception_J3_PerceptionData_Read(perceptionData, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_Len_to_Left_Lane_Read(sint16 *wigth)	//called by Fcu_Lcf.c
{
    Sdc_Perception_Len_to_Left_Lane_Read(wigth);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_Len_to_Right_Lane_Read(sint16 *wigth)//called by Fcu_Lcf.c
{
    Sdc_Perception_Len_to_Right_Lane_Read(wigth);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_HostLane_Left_flag_Read(uint8 *flag)//called by Fcu_Lcf.c
{
    Sdc_Perception_HostLane_Left_flag_Read(flag);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_HostLane_Right_flag_Read(uint8 *flag)//called by Fcu_Lcf.c
{
    Sdc_Perception_HostLane_Right_flag_Read(flag);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestSocSupplierSoftwarenumber(void) 	//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_RequestSocSupplierSoftwarenumber();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestOMSN(void)						//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_RequestOMSN();
}
FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocSupplierSoftwarenumber_Read(uint8 *data, uint16 length)//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_SocSupplierSoftwarenumber_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocOMSN_Read(uint8 *data, uint16 length)//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_SocOMSN_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestBootSensor(void)					//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_RequestBootSensor();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocBootSensor_Read(uint8 *data, uint16 length)//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_SocBootSensor_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestEOLCalibration(void)				//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_RequestEOLCalibration();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableLengthDiagnostic_StartRoutine(uint8 u_InputData)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthCableLengthDiagnostic_StartRoutine(u_InputData);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestSDACalibration(void)				//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_RequestSDACalibration();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthSetPortConfiguration_StartRoutine(uint8 u_InputData)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthSetPortConfiguration_StartRoutine(u_InputData);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetPortConfiguration_StartRoutine(void)	//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthResetPortConfiguration_StartRoutine();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthReadPhyRegister_StartRoutine(uint8 *data, uint16 length)		//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthReadPhyRegister_StartRoutine(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableDiagnostic_StartRoutine(uint8 u_InputData)	//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthCableDiagnostic_StartRoutine(u_InputData);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthEnableTestMode_StartRoutine(uint8 *data, uint16 length)		//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthEnableTestMode_StartRoutine(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthEnableTestMode_StopRoutine(void)			//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthEnableTestMode_StopRoutine();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthPhyLoopBackTest_StartRoutine(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthPhyLoopBackTest_StartRoutine(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACAddress_StartRoutine(uint8 u_InputData)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthResetMACAddress_StartRoutine(u_InputData);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACLayerStatistic_StartRoutine(uint8 u_InputData)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthResetMACLayerStatistic_StartRoutine(u_InputData);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthPhyLoopBackTest_StopRoutine(void)		//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthPhyLoopBackTest_StopRoutine();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EOLCalResult_Read(void)  //called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EOLCalResult_Read();
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocCpuInfo_Read(void* socSystemInfo, uint16 length)	//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_SocCpuInfo_Read(socSystemInfo, length);
}

FUNC(uint8, RTE_CODE) Sdc_SendInterface_SocShutdownReuqest(void)	//called by Esm.c
{
    return Sdc_Diag_SocShutdownReuqest();
}

FUNC(uint8, RTE_CODE) Sdc_SendInterface_GetPWMState(void)//called by Esm.c
{
    return Sdc_Diag_GetPWMState();
}

FUNC(uint8, RTE_CODE) Sdc_SendInterface_RequestCalibrationValue(void)	//called by Esh Module 
{
    return Sdc_Diag_RequestCalibrationValue();
}

FUNC(uint8, RTE_CODE) Sdc_SendInterface_SocDiagInfo_Read(uint8 group_id, void *socDiagInfo)	//called by Esh_SnapshotExtendData.c
{
    return Sdc_Diag_SocDiagInfo_Read(group_id, socDiagInfo);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_CameraCaliresultDetails_Read(uint8 *data, uint16 length)	//called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_CameraCaliresultDetails_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_CameraValue_Read(void *data, uint16 length)		//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_CameraValue_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_CalibrationFlag_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c and Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_CalibrationFlag_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocSysState_Read(uint8 *data, uint16 length)	//called by Dsm_RoutineControl.c and Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_SocSysState_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthSetPortConfigurationInfo_Read(uint8 *data, uint16 length)	//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthSetPortConfigurationInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthReadPhyRegisterInfo_Read(uint8 *data, uint16 length)	//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthReadPhyRegisterInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACAddressInfo_Read(uint8 *data, uint16 length)	//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthResetMACAddressInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetPortConfigurationInfo_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthResetPortConfigurationInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableDiagnosticInfo_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthCableDiagnosticInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACLayerStatisticInfo_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthResetMACLayerStatisticInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthEnableTestModeInfo_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthEnableTestModeInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthPhyLoopBackTestInfo_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthPhyLoopBackTestInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableLengthDiagnosticInfo_Read(uint8 *data, uint16 length)//called by Dsm_RoutineControl.c
{
    return Sdc_Diag_EthCableLengthDiagnosticInfo_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCrcError_Read(uint8 *data, uint16 length) 	//called by Sed_Stubs.c
{
    return Sdc_Diag_EthCrcError_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthSQI_Read(uint8 *data, uint16 length)			//called by Sed_Stubs.c
{
    return Sdc_Diag_EthSQI_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableFault_Read(uint8 *data, uint16 length)	//called by Sed_Stubs.c
{
    return Sdc_Diag_EthCableFault_Read(data, length);
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthIcmpError_Read(uint8 *data, uint16 length)	//called by Sed_Stubs.c
{
    return Sdc_Diag_EthIcmpError_Read(data, length);
}

uint8 Sdc_SendInterface_UdsRequest(uint8 ServerType,uint16 Did,const void *Inparameter,uint8 InparameterLength,const void *OutParam1,uint8 OutparameterLength) //called by Dsm_ReadDataByIdentifier.c
{
    return Sdc_Diag_UdsRequest(ServerType, Did, Inparameter, InparameterLength, OutParam1, OutparameterLength);
}






#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

/*==================[internal function definitions]=========================*/


