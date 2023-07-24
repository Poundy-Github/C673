/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\Cdm
* Class_____: C
* Name______: Cdm_Cfg.c
* vision____: 0.1
* Author____: YinXing
* History___: 2023/03/01 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
*******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Cdm_Cfg.h"
#include <McalLib.h>
#include "IfxCpu_reg.h"
#include "Os_api.h"
#include <Rte_Cdm.h>
#include "Dbg_Cfg.h"
#include "Qsm_Lcfg.h"`
#include "SystemData_VehicleVariant.h"

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

uint8 VdyNvm_Clear;

s_Cdm_CustomerData_t s_Cdm_CustomerCode = {0x00000000, 0x00, 0x00, {0x05, 0x25}};

//uint8 EOL_MODE_SWITCH[2]= {0x05,0x25};

const uint8 ROM_NVM_BLOCK_HMISwitchStatus[DIAG_SIZE_OF_HMISWITCH] = {0};
uint8 RAM_NVM_BLOCK_HMISwitchStatus[DIAG_SIZE_OF_HMISWITCH] = {0};

//Init value For for EOL info input 0xF1F5 & 0x3BAF
const uint8 ROM_NVM_BLOCK_EOL_Info_Input[DIAG_SIZE_OF_EOL_INFO_INPUT] = {0};
uint8 RAM_NVM_BLOCK_EOL_Info_Input[DIAG_SIZE_OF_EOL_INFO_INPUT] = {0};

//Init value For Finger print 0xF184
const uint8 ROM_NVM_BLOCK_Fingerprint[DIAG_SIZE_OF_FINGER_PRINT] = {0};
uint8 RAM_NVM_BLOCK_Fingerprint[DIAG_SIZE_OF_FINGER_PRINT] = {0};

//Init value For PCB A Serial Number 0xFD24
const uint8 ROM_NVM_BLOCK_PCBASerialNumberDataIdentifier[DIAG_SIZE_OF_SERIAL_NUMBER] = {0};
uint8 RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier[DIAG_SIZE_OF_SERIAL_NUMBER] = {0};

const uint8 ROM_NVM_BLOCK_ECUHardwareVersion[DIAG_SIZE_OF_ECUHardwareVersion] = {'H','W',':','C','.','1','.','0'};
uint8 RAM_NVM_BLOCK_ECUHardwareVersion[DIAG_SIZE_OF_ECUHardwareVersion] = {0};

const uint8 ROM_NVM_BLOCK_EOLCalibrationData[DIAG_SIZE_OFEOLCALIBRATIONDATA] = {0};
uint8 RAM_NVM_BLOCK_EOLCalibrationData[DIAG_SIZE_OFEOLCALIBRATIONDATA] = {0};

const uint8 ROM_NVM_BLOCK_SDACalibrationData[DIAG_SIZE_OFSDACALIBRATIONDATA] = {0};
uint8 RAM_NVM_BLOCK_SDACalibrationData[DIAG_SIZE_OFSDACALIBRATIONDATA] = {0};

//Init value For Lane function configuration 0xF1FE
const uint8 ROM_NVM_BLOCK_LaneFunctionConfiguration[DIAG_SIZE_OF_LANE_CONFIGURATION] = {0x07,0xD3};
uint8 RAM_NVM_BLOCK_LaneFunctionConfiguration[DIAG_SIZE_OF_LANE_CONFIGURATION] = {0};

//Init value Before Write FAB_switch 0xF1F1
const uint8 ROM_NVM_BLOCK_FAB_switch[DIAG_SIZE_OF_FAB_SWITCH] = {0x00};
uint8 RAM_NVM_BLOCK_FAB_switch[DIAG_SIZE_OF_FAB_SWITCH] = {0};

//Init value Before Write TSR_switch 0xF1F2
const uint8 ROM_NVM_BLOCK_TSR_switch[DIAG_SIZE_OF_TSR_SWITCH] = {0x00};
uint8 RAM_NVM_BLOCK_TSR_switch[DIAG_SIZE_OF_TSR_SWITCH] = {0};

//Init value Before Write TLA_switch 0xF1F3
const uint8 ROM_NVM_BLOCK_TLA_switch[DIAG_SIZE_OF_TLA_SWITCH] = {0x01};
uint8 RAM_NVM_BLOCK_TLA_switch[DIAG_SIZE_OF_TLA_SWITCH] = {0};

//Init value For Vehicle type 0xF1F0
const uint8 ROM_NVM_BLOCK_Vehicletype[DIAG_SIZE_OF_VEHICLE_TYPE] = {SYS_C673_LBL}; //Change log: DiagMariix V1.3.1Update ,Default value = 0x03(C673_LBL).
uint8 RAM_NVM_BLOCK_Vehicletype[DIAG_SIZE_OF_VEHICLE_TYPE] = {0};

//Init value For Key Counter Array 0x0103
const uint8 ROM_NVM_BLOCK_Security_AttemptCount[DIAG_SIZE_OF_KEY_COUNTER] = {0};
uint8 RAM_NVM_BLOCK_Security_AttemptCount[DIAG_SIZE_OF_KEY_COUNTER] = {0};

//Init value Before Write ECUSerialNumberDataIdentifier 0xF18C
const uint8 ROM_NVM_BLOCK_SerialNumberDataId[DIAG_SIZE_OF_ECUSERIALNUMBERDATAID] = {0};
uint8 RAM_NVM_BLOCK_SerialNumberDataId[DIAG_SIZE_OF_ECUSERIALNUMBERDATAID] = {0};

//Init value Before Write VINDataIdentifier 0xF190
const uint8 ROM_NVM_BLOCK_VINDataIdentifier[DIAG_SIZE_OF_VINDATAIDENTIFIER] = {0};
uint8 RAM_NVM_BLOCK_VINDataIdentifier[DIAG_SIZE_OF_VINDATAIDENTIFIER] = {0};

/**
 * \brief Declaration value for RAM_NVM_BLOCK_FCWLastbutoneappearedFD14 NVM temporary storing  use,
 */
const uint8 ROM_NVM_BLOCK_FCWLastbutoneappearedFD14[BLOCK_SIZE_FCWLastbutoneappearedFD14] = {0};
uint8 RAM_NVM_BLOCK_FCWLastbutoneappearedFD14[BLOCK_SIZE_FCWLastbutoneappearedFD14] = {0};
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AWBLastbutoneappearFD15 NVM temporary storing  use,
 */
const uint8 ROM_NVM_BLOCK_AWBLastbutoneappearFD15[BLOCK_SIZE_AWBLastbutoneappearFD15] = {0};
uint8 RAM_NVM_BLOCK_AWBLastbutoneappearFD15[BLOCK_SIZE_AWBLastbutoneappearFD15] = {0};
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AEBLastbutoneappearFD16 NVM temporary storing  use,
 */
const uint8 ROM_NVM_BLOCK_AEBLastbutoneappearFD16[BLOCK_SIZE_AEBLastbutoneappearFD16] = {0};
uint8 RAM_NVM_BLOCK_AEBLastbutoneappearFD16[BLOCK_SIZE_AEBLastbutoneappearFD16] = {0};
/**
 * \brief Declaration value for RAM_NVM_BLOCK_FCWLastappearFD17 NVM temporary storing  use,
 */
const uint8 ROM_NVM_BLOCK_FCWLastappearFD17[BLOCK_SIZE_FCWLastappearFD17] = {0};
uint8 RAM_NVM_BLOCK_FCWLastappearFD17[BLOCK_SIZE_FCWLastappearFD17] = {0};
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AWBLasteappearFD18 NVM temporary storing  use,
 */
const uint8 ROM_NVM_BLOCK_AWBLasteappearFD18[BLOCK_SIZE_AWBLasteappearFD18] = {0};
uint8 RAM_NVM_BLOCK_AWBLasteappearFD18[BLOCK_SIZE_AWBLasteappearFD18] = {0};
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AEBLastappearFD19 NVM temporary storing  use,
 */
const uint8 ROM_NVM_BLOCK_AEBLastappearFD19[BLOCK_SIZE_AEBLastappearFD19] = {0};
uint8 RAM_NVM_BLOCK_AEBLastappearFD19[BLOCK_SIZE_AEBLastappearFD19] = {0};

VDYNvIoData_t RAM_BLOCK_VDY_Data;
const VDYNvIoData_t ROM_BLOCK_VDY_Data = {
	0x00u,
	{ 0x00u, 0x00u, 0x00u, 0x00u,
	  {
	  	0x00u, 0x00u, 0x00u,
	  }
	},
	{ 
	  0.0f, 0x00, 
	},
	{ 
	  0.0f, 0x00u, 0x00u, 0x00, 0x00u, 
	},
	{ 
	  0.0f, 0.0f, 0.0f, 0x00u, 
	},
	{
	  0.0f, 0x00u, 
	},
	{ 
	  { 
	  	1.0f, 0.0f, 0.0f, 
	  },
	  { 
	  	1.0f, 0.0f, 0.0f, 
	  },
	  { 
	  	1.0f, 0.0f, 0.0f, 
	  },
	},
	{ 
	  0.0f, 0.0f, 0x00u, 0x00u, 
	},
	{ 
	  0xFFFFFFFFu, 
	}
};
FSDebugStateus RAM_BLOCK_FS_DEBUG;

const Cdm_BlockDescriptorType Cdm_BlockDescriptorTable[NVM_TOTAL_NUMBER_OF_CDM_BLOCK] = 
{ 
    {4,     17,     RAM_NVM_BLOCK_VINDataIdentifier,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {5,     8,     RAM_NVM_BLOCK_ECUHardwareVersion,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {6,     13,     RAM_NVM_BLOCK_SerialNumberDataId,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {7,     1,     RAM_NVM_BLOCK_FAB_switch,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {8,     1,     RAM_NVM_BLOCK_TSR_switch,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {9,     1,     RAM_NVM_BLOCK_TLA_switch,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {10,     2,     RAM_NVM_BLOCK_Security_AttemptCount,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {11,     6,     RAM_NVM_BLOCK_EOL_Info_Input,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {12,     4094,     NULL_PTR,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_QUASIBLOCK,    },
    {13,     4094,     NULL_PTR,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_QUASIBLOCK,    },
    {14,     4094,     NULL_PTR,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_QUASIBLOCK,    },
    {15,     4094,     NULL_PTR,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_QUASIBLOCK,    },
    {16,     7,     RAM_NVM_BLOCK_Fingerprint,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {17,     1,     RAM_NVM_BLOCK_Vehicletype,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {18,     5,     RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {19,     3,     RAM_NVM_BLOCK_LaneFunctionConfiguration,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {20,     20,     RAM_NVM_BLOCK_EOLCalibrationData,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {21,     1,     RAM_NVM_BLOCK_SDACalibrationData,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {22,     4094,     NULL_PTR,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_QUASIBLOCK,    },
    {23,     7,     RAM_NVM_BLOCK_HMISwitchStatus,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {24,     49,     RAM_NVM_BLOCK_FCWLastbutoneappearedFD14,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_IMME,     CDM_NVMBLOCK,    },
    {25,     49,     RAM_NVM_BLOCK_AWBLastbutoneappearFD15,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_IMME,     CDM_NVMBLOCK,    },
    {26,     49,     RAM_NVM_BLOCK_AEBLastbutoneappearFD16,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_IMME,     CDM_NVMBLOCK,    },
    {27,     49,     RAM_NVM_BLOCK_FCWLastappearFD17,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_IMME,     CDM_NVMBLOCK,    },
    {28,     49,     RAM_NVM_BLOCK_AWBLasteappearFD18,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_IMME,     CDM_NVMBLOCK,    },
    {29,     49,     RAM_NVM_BLOCK_AEBLastappearFD19,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_IMME,     CDM_NVMBLOCK,    },
    {30,     108,     &RAM_BLOCK_VDY_Data,     CDM_NVMWRITE_SHOTDOWN,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
    {31,     164,     &RAM_BLOCK_FS_DEBUG,     CDM_NVMWRITE_IMME,     CDM_NVMREAD_ALL,     CDM_NVMBLOCK,    },
};


/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/

/*******************************************************************************
** Syntax :  FUNC(void, MVM_CODE) Cdm_v_BoardDisableECCCheck(void)    		  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :  															  **
**                                            								  **
*******************************************************************************/

FUNC(void, RTE_CODE) Cdm_v_BoardDisableECCCheck(void)
{
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU0_FLASHCON2, (uint32)0xAA020A06);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU0_FLASHCON1, (uint32)0x02010000);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU1_FLASHCON2, (uint32)0xAA020A06);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU1_FLASHCON1, (uint32)0x02010000);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU2_FLASHCON2, (uint32)0xAA020A06);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU2_FLASHCON1, (uint32)0x02010000);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU3_FLASHCON2, (uint32)0xAA020A06);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU3_FLASHCON1, (uint32)0x02010000);
}

/*******************************************************************************
** Syntax :  FUNC(void, MVM_CODE) Cdm_v_BoardEnableECCCheck(void)    		  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :  															  **
**                                            								  **
*******************************************************************************/

FUNC(void, RTE_CODE) Cdm_v_BoardEnableECCCheck(void)
{
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU0_FLASHCON2, (uint32)0xAA020A0A);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU0_FLASHCON1, (uint32)0x02020000);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU1_FLASHCON2, (uint32)0xAA020A0A);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU1_FLASHCON1, (uint32)0x02020000);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU2_FLASHCON2, (uint32)0xAA020A0A);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU2_FLASHCON1, (uint32)0x02020000);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU3_FLASHCON2, (uint32)0xAA020A0A);
	Mcal_WriteCpuEndInitProtReg((uint32*)&CPU3_FLASHCON1, (uint32)0x02020000);
}

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Cdm_v_InitEOLModeGate_QSData(void)   		  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :Raed the EOL mode from QS dataflash in startup.  			  **
**                                            								  **
*******************************************************************************/
FUNC(void, RTE_CODE) Cdm_v_InitEOLModeGate_QSData(void)
{
#if ((defined DBG_CDM_EOL_MODE_ENABLE) && (DBG_CDM_EOL_MODE_ENABLE == STD_ON))	
    SuspendAllInterrupts();
	
    (void)TS_MemCpy((void*)s_Cdm_CustomerCode.Eolmode, (void*)s_QSBlock_EcuSpecInfo.F1FF, sizeof(s_Cdm_CustomerCode.Eolmode));  
	
	ResumeAllInterrupts();
#else
    /*Indicate enter to EOL mode.*/
    s_Cdm_CustomerCode.Eolmode[0] = 0x05;
    s_Cdm_CustomerCode.Eolmode[1] = 0x25;
	
#endif
}

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Cdm_v_InitCustomerCode_QSData(void)   	  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :Raed the customer coding from QS dataflash in startup.  	  **
**                                            								  **
*******************************************************************************/
FUNC(void, RTE_CODE) Cdm_v_InitCustomerCode_QSData(void)
{  
    #if 0
    SuspendAllInterrupts();
	
    (void)TS_MemCpy((void*)&s_Cdm_CustomerCode.CustomerCode1, (void*)&s_QSBlock_EcuSpecInfo.VehCustomCode, sizeof(s_Cdm_CustomerCode.CustomerCode1));  
	
	ResumeAllInterrupts();
	#endif
}

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Cdm_v_InitSpecVariant_QSData(void)   	      **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :Raed the specific variant from QS dataflash in startup.  	  **
**                                            								  **
*******************************************************************************/
FUNC(void, RTE_CODE) Cdm_v_InitSpecVariant_QSData(void)
{   
    #if 0
    SuspendAllInterrupts();
	
    (void)TS_MemCpy((void*)&s_Cdm_CustomerCode.SpecVariant, (void*)&s_QSBlock_EcuSpecInfo.VehSpecVar, sizeof(s_Cdm_CustomerCode.SpecVariant));  
	
	ResumeAllInterrupts();
	#endif
}

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Cdm_v_InitSpecVariant_QSData(void)   	      **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :Raed the operation mode from QS dataflash in startup.  	  **
**                                            								  **
*******************************************************************************/
FUNC(void, RTE_CODE) Cdm_v_InitOperationMode_QSData(void)
{
    #if 0
    SuspendAllInterrupts();
	
    (void)TS_MemCpy((void*)&s_Cdm_CustomerCode.Operationmode, (void*)&s_QSBlock_EcuSpecInfo.OperationMode, sizeof(s_Cdm_CustomerCode.Operationmode));  
	
	ResumeAllInterrupts();
	#endif
}

/*********************************************************************************************
** Syntax :  FUNC(Std_ReturnType, RTE_CODE) Cdm_VdyWriteBlockMirror (NvM_DstPtrType DstPtr) **
**                                                                                          **
** Sync/Async:  Synchronous                                                                 **
**                                                                                          **
** Reentrancy:  Non reentrant                                                               **
**                                                                                          **
** Parameters (in) :  None          										                **
**                                                                                          **
** Parameters (out):  None                                                                  **
**                                                                                          **
** Return value    :  None                                                                  **
**                                                                                          **
** Description :  															                **
**                                            								                **
*********************************************************************************************/
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>

FUNC(Std_ReturnType, RTE_CODE) Cdm_VdyWriteBlockMirror (NvM_DstPtrType DstPtr)
{
  if(VdyNvm_Clear == 0x00u)
  {
  	(void)Rte_Read_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData(&RAM_BLOCK_VDY_Data);
  	
  	SuspendAllInterrupts();
  
  	TS_MemCpy(DstPtr, &RAM_BLOCK_VDY_Data, sizeof(RAM_BLOCK_VDY_Data));
  
  	ResumeAllInterrupts();
  }
  else
  {
  	SuspendAllInterrupts();
  	
  	TS_MemCpy(DstPtr, &ROM_BLOCK_VDY_Data, sizeof(ROM_BLOCK_VDY_Data));
  
  	ResumeAllInterrupts();
  }

  return RTE_E_OK;
} 

#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>
/*********************************************************************************************
** Syntax : FUNC(Std_ReturnType, RTE_CODE) Cdm_VdyReadRamBlockMirror (NvM_SrcPtrType SrcPtr)**
**                                                                                          **
** Sync/Async:  Synchronous                                                                 **
**                                                                                          **
** Reentrancy:  Non reentrant                                                               **
**                                                                                          **
** Parameters (in) :  None          										                **
**                                                                                          **
** Parameters (out):  None                                                                  **
**                                                                                          **
** Return value    :  None                                                                  **
**                                                                                          **
** Description :  															                **
**                                            								                **
*********************************************************************************************/
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>

FUNC(Std_ReturnType, RTE_CODE) Cdm_VdyReadRamBlockMirror (NvM_SrcPtrType SrcPtr)
{
  SuspendAllInterrupts();

  TS_MemCpy(&RAM_BLOCK_VDY_Data, SrcPtr, sizeof(RAM_BLOCK_VDY_Data));
  
  ResumeAllInterrupts();
  
  return RTE_E_OK;
} 

#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>
/*********************************************************************************************
** Syntax : FUNC(Std_ReturnType, NVM_CODE) Fs_NvmReadCopyBlock(void* NvMBuffer)				**
**                                                                                          **
** Sync/Async:  Synchronous                                                                 **
**                                                                                          **
** Reentrancy:  Non reentrant                                                               **
**                                                                                          **
** Parameters (in) :  None          										                **
**                                                                                          **
** Parameters (out):  None                                                                  **
**                                                                                          **
** Return value    :  None                                                                  **
**                                                                                          **
** Description :  															                **
**                                            								                **
*********************************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) Fs_NvmReadCopyBlock(void* NvMBuffer)
{
	Std_ReturnType Ret_Value = E_NOT_OK;
	#if FS_PDO_ENABLED == 0
	FSDebugStateus fs_debug_data = {0};
	#endif

	if(NULL_PTR == NvMBuffer)
	{
		Ret_Value = E_NOT_OK;
	}
	else
	{
		SuspendAllInterrupts();

		#if FS_PDO_ENABLED
		TS_MemCpy(&g_fs_debug_status, NvMBuffer, sizeof(FSDebugStateus));
		RAM_BLOCK_FS_DEBUG = g_fs_debug_status;
		#elif FS_PDO_ENABLED == 0
		TS_MemCpy(&fs_debug_data, NvMBuffer, sizeof(FSDebugStateus));
		#endif

		ResumeAllInterrupts();
		
		Ret_Value = E_OK;
	}

	return Ret_Value;
}
/*********************************************************************************************
** Syntax : FUNC(Std_ReturnType, NVM_CODE) Fs_NvmWriteCopyBlock(void* NvMBuffer)			**
**                                                                                          **
** Sync/Async:  Synchronous                                                                 **
**                                                                                          **
** Reentrancy:  Non reentrant                                                               **
**                                                                                          **
** Parameters (in) :  None          										                **
**                                                                                          **
** Parameters (out):  None                                                                  **
**                                                                                          **
** Return value    :  None                                                                  **
**                                                                                          **
** Description :  															                **
**                                            								                **
*********************************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) Fs_NvmWriteCopyBlock(void* NvMBuffer)
{
	Std_ReturnType Ret_Value = E_NOT_OK;
	#if FS_PDO_ENABLED == 0
	FSDebugStateus fs_debug_data = {0};
	#endif

	if(NULL_PTR == NvMBuffer)
	{
		Ret_Value = E_NOT_OK;
	}
	else
	{		
		SuspendAllInterrupts();

		#if FS_PDO_ENABLED
		TS_MemCpy(NvMBuffer, &g_fs_debug_status, sizeof(FSDebugStateus));
		#elif FS_PDO_ENABLED == 0
		TS_MemCpy(&fs_debug_data, NvMBuffer, sizeof(FSDebugStateus));
		#endif

		ResumeAllInterrupts();
		
		Ret_Value = E_OK;
	}

	return Ret_Value;
}
