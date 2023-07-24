/*
 * Sdc_SendInterface.h
 *
 *  Created on: May 28, 2023
 *      Author: uif69946
 */

#ifndef _SDC_SENDINTERFACE_H_
#define _SDC_SENDINTERFACE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Sdc_Diag.h"

/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

// extern uint8 Sdc_SendInterface_TimeSyncMsg(const void *data, uint16 length);
// extern uint8 Sdc_SendInterface_TimeSyncUtc(const s_Sdc_Timesync_st *ts_info);

//24+7+3+9 = 43
//7

// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestEOLCalibration(void);				//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestSDACalibration(void);	            //called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EOLCalResult_Read(void);			//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_CameraCaliresultDetails_Read(uint8 *data, uint16 length);	//called by Dsm_ReadDataByIdentifier.c and Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_CameraValue_Read(void *data, uint16 length);		//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_CalibrationFlag_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c and Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestCalibrationValue(void);	//called by Esh Module --Esh_MainFunction

// //3
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocSysState_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c and Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_UdsRequest(DID_RID_TYPE ServerType,uint16 Did,const void *Inparameter,uint8 InparameterLength,const void *OutParam1,uint8 OutparameterLength); //called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocDiagInfo_Read(uint8 group_id, void* SocDiagInfo);	//called by Esh_SnapshotExtendData.c and Sed_Stubs.c
// //  -- Esh_u_DataElementClass_SOCErrMap  
// //  -- Sed_MainFunction
 
// //9
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestSocSupplierSoftwarenumber(void); 	//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocSupplierSoftwarenumber_Read(uint8 *data, uint16 length);//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestOMSN(void);						//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocOMSN_Read(uint8 *data, uint16 length);//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_RequestBootSensor(void);					//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocBootSensor_Read(uint8 *data, uint16 length);//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocCpuInfo_Read(void* SocSystemInfo, uint16 length);	//called by Dsm_ReadDataByIdentifier.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_SocShutdownReuqest(void);	//called by Esm.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_PWMState_Read(void);//called by Esm.c
 

// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_J3_PerceptionData_Read(void* perceptionData, uint16 length);	//called by Fcu_Hla.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_Len_to_Left_Lane_Read(sint16 *wigth);	//called by Fcu_Lcf.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_Len_to_Right_Lane_Read(sint16 *wigth);//called by Fcu_Lcf.c
 
// //24
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableLengthDiagnostic_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthSetPortConfiguration_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetPortConfiguration_StartRoutine(void);	//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthReadPhyRegister_StartRoutine(uint8 *data, uint16 length);		//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableDiagnostic_StartRoutine(uint8 u_InputData);	//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthEnableTestMode_StartRoutine(uint8 *data, uint16 length);		//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthEnableTestMode_StopRoutine(void);			//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthPhyLoopBackTest_StartRoutine(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACAddress_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACLayerStatistic_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthPhyLoopBackTest_StopRoutine(void);		//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthSetPortConfigurationInfo_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthReadPhyRegisterInfo_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACAddressInfo_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetPortConfigurationInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableDiagnosticInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthResetMACLayerStatisticInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthEnableTestModeInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthPhyLoopBackTestInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableLengthDiagnosticInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCrcError_Read(uint8 *data, uint16 length); 	//called by Sed_Stubs.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthSQI_Read(uint8 *data, uint16 length);			//called by Sed_Stubs.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthCableFault_Read(uint8 *data, uint16 length);	//called by Sed_Stubs.c
// extern FUNC(Std_ReturnType, RTE_CODE) Sdc_SendInterface_EthIcmpError_Read(uint8 *data, uint16 length);	//called by Sed_Stubs.c


extern FUNC(uint8, RTE_CODE) Sdc_SendInterface_GetPWMState(void);


void Sdc_SendInterface_InitFunction(void);

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
#endif /* _SDC_SENDINTERFACE_H_ */
