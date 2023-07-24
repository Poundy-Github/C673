/**
 * \file Sed_Lcfg.c
 *
 * \brief
 *
 * \version refer the Sed_Core.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Sed_Lcfg.h"
#include "Sed_Stubs.h"
#include "Dem_IntEvtId.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/ 
extern const s_Sed_ErrorDetectionConfig_t Sed_ErrorDetectionConfigTable[SED_ERROR_DETECTION_NUMBER] =
{/*						EventId,								                     MonitorCycle,	 DebounceEnable,			Mode,				Op_CheckPreCond,				                Op_TestFailed,						                    Op_TestPassed*/
	/*0*/  {DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage, 						10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_CameraBlockage, 			 Sed_TestFailed_CameraBlockage, 					NULL_PTR }
	/*1*/ ,{DemConf_DemEventParameter_DEM_DTC_Ethernet_Unexpected_Link_Down, 			10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_EthUnexpectedLinkDown, 		 Sed_TestFailed_EthUnexpectedLinkDown, 			    NULL_PTR }
	/*2*/ ,{DemConf_DemEventParameter_DEM_DTC_J3_SoC_ETH_IP_Ubnormal, 					10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_EthDriverAbnormal, 			 Sed_TestFailed_EthDriverAbnormal, 					NULL_PTR }
	/*3*/ ,{DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE, 					10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_CameraCalibrationFailure, 	 Sed_TestFailed_CameraCalibrationFailure, 			NULL_PTR }
	/*4*/ ,{DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error, 					10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocSafetylibError, 			 Sed_TestFailed_SocSafetylibError, 				    NULL_PTR }
	/*5*/ ,{DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH, 							10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocTempExtTooHigh, 			 Sed_TestFailed_SocTempExtTooHigh, 					NULL_PTR }
	/*6*/ ,{DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW, 							10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocSystemKernelError, 		 Sed_TestFailed_SocSystemKernelError, 				NULL_PTR }
	/*7*/ ,{DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE, 			10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_CameraAutoCalibrationFailure,Sed_TestFailed_CameraAutoCalibrationFailure, 		NULL_PTR }
	/*8*/ ,{DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error, 				10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocSystemServiceError, 	     Sed_TestFailed_SocSystemServiceError, 				NULL_PTR }
	/*9*/ ,{DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error, 							10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocCameraError, 			 Sed_TestFailed_SocCameraError, 					NULL_PTR }
	/*10*/,{DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing, 			10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_CPUErrorPWMMissing, 		 Sed_TestFailed_CPUErrorPWMMissing, 				NULL_PTR }
	/*11*/,{DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error, 					10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocPerceptionError,          Sed_TestFailed_SocPerceptionError, 				NULL_PTR }
	/*12*/,{DemConf_DemEventParameter_DEM_DTC_ETH_CRC_ERROR, 							10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_EthCrcError, 				 Sed_TestFailed_EthCrcError, 						NULL_PTR }
	/*13*/,{DemConf_DemEventParameter_DEM_DTC_ETH_LINK_SIGNAL_WAKE, 					10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_EthLinkSignalWake, 			 Sed_TestFailed_EthLinkSignalWake, 					NULL_PTR }
	/*14*/,{DemConf_DemEventParameter_DEM_DTC_ETH_CABLE_FAULT, 							10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_EthCableFault, 				 Sed_TestFailed_EthCableFault, 						NULL_PTR }
	/*15*/,{DemConf_DemEventParameter_DEM_DTC_ETH_ICMP_ERROR, 							10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_EthIcmpError, 				 Sed_TestFailed_EthIcmpError, 						NULL_PTR }
	/*16*/,{DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error, 						10, 			STD_OFF, 		Sed_ErrDetMode_Mutex, 		Sed_EnableCondition_SocTimeSyncError, 			 Sed_TestFailed_SocTimeSyncError, 					NULL_PTR }
};


/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

