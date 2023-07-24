/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\Cdm
* Class_____: C
* Name______: Cdm.c
* vision____: 0.1
* Author____: YinXing
* History___: 2023/03/01 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
*******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Rte_Cdm.h>
#include <Cdm.h>
#include <Nvm_Cfg.h>
#include <NvM.h>
//#include "Cdd_EvAdc.h"
#include "Qsm_Lcfg.h"
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static FUNC(Std_ReturnType, RTE_CODE) Cdm_ReadBloclNvm(uint16 BlockId, void * DstPtr);
static FUNC(Std_ReturnType, RTE_CODE) Cdm_ReadBlockQsm(uint16 BlockId, void * DstPtr);
static FUNC(Std_ReturnType, RTE_CODE) Cdm_WriteBlockNvm(uint16 BlockId, const void * DstPtr);
static FUNC(Std_ReturnType, RTE_CODE) Cdm_WriteBlockQsm(uint16 BlockId, const void * DstPtr);
/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Cdm_InitFunction (void)    		          **
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
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>

FUNC(void, RTE_CODE) Cdm_InitFunction (void)
{
	Rte_Write_PP_Cdm_VdyInputNvMData_VdyNvMInOutData(&RAM_BLOCK_VDY_Data);
	Cdm_v_InitEOLModeGate_QSData();
	Cdm_v_InitCustomerCode_QSData();
	Cdm_v_InitSpecVariant_QSData();
	Cdm_v_InitOperationMode_QSData();
} 

#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Cdm_MainFunction (void)    		          **
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
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>

FUNC(void, RTE_CODE) Cdm_MainFunction (void)
{
	uint8 BlockIdx;
	float32_t f_BattVolt = 0.0f;
		
	(void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f_BattVolt);

	if((f_BattVolt < NVM_VOLT_MIN) || (f_BattVolt > NVM_VOLT_MAX))
	{
		/*Voltage supply is unstable cancel pending quasi block request*/
		Qsm_CancelPendingJob();
		/*Voltage supply is unstable cancel pending write request*/
		NvM_CancelWriteAll();
		/*Disable garbage collection*/
		Fee_17_DisableGcStart();
		/*Disable all pending nvm job*/
		for(BlockIdx = 2u; BlockIdx < NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS; BlockIdx++)
		{
			NvM_CancelJobs(BlockIdx);
		}
	}
	else
	{
		Fee_17_EnableGcStart();
	}
} 
#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>
/*******************************************************************************
** Syntax :  Cdm_WriteBlock    		          							      **
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
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) Cdm_WriteBlock (uint16 BlockId, ConstVoidPtr NvM_DstPtr)
{

	Std_ReturnType Ret_Value = NVM_REQ_NOT_OK;
	
	if(Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmBlockType == CDM_NVMBLOCK)
	{
		Ret_Value = Cdm_WriteBlockNvm(BlockId, NvM_DstPtr);
	}
	else
	{
		Ret_Value = Cdm_WriteBlockQsm(BlockId, NvM_DstPtr);
	}
	return Ret_Value;
}
#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>
/*******************************************************************************
** Syntax :  Cdm_ReadBlock    		          								  **
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
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) Cdm_ReadBlock (uint16 BlockId, VoidPtr DstPtr)
{     
    Std_ReturnType retValue = (uint8)NVM_REQ_OK;        

	if(Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmBlockType == CDM_NVMBLOCK)
	{
	    retValue = Cdm_ReadBloclNvm(BlockId, DstPtr);
	}
	else
	{
		retValue = Cdm_ReadBlockQsm(BlockId, DstPtr);
	}
    
    return retValue;
}
#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>
/*******************************************************************************
** Syntax :  Cdm_WriteBlockQsm    		          							  **
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
#define Cdm_START_SEC_CODE
#include <Cdm_MemMap.h>
FUNC(void, RTE_CODE) Cdm_GetErrorStatus (uint16 BlockId, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_APPL_DATA) ResultPtr)
{
	uint8 i = 0u;
	
	if(Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmBlockType == CDM_NVMBLOCK)
	{
		(void)NvM_GetErrorStatus(BlockId, ResultPtr);
	}
	else
	{
		for(i = 0u; i < QSM_CONFIGBLOCKNUM; i++)
		{
			if(Qsm_ConfigAllTable[i].NvmBlockId == BlockId)
			{
				break;
			}
		}
		
		*ResultPtr = Qsm_GetErrorStatues(Qsm_ConfigAllTable[i].QuasiBlockId);
	}
}
#define Cdm_STOP_SEC_CODE
#include <Cdm_MemMap.h>
/*******************************************************************************
** Syntax :  Cdm_ReadBloclNvm    		          							  **
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
static FUNC(Std_ReturnType, RTE_CODE) Cdm_ReadBloclNvm(uint16 BlockId, void * DstPtr)
{
	uint16 Get_Block_Size;
    NvM_RequestResultType ReadAllStatus = NVM_REQ_PENDING;
	Std_ReturnType retValue = (uint8)NVM_REQ_OK; 
	
	    /* check if there is a multiblock job in progress*/
    (void)NvM_GetErrorStatus(NVM_BLOCK_MULTI, &ReadAllStatus);  
      
    if ((NVM_REQ_PENDING != ReadAllStatus) && (NULL_PTR != DstPtr))
    {
		/*if there is no multiblock job and the destination pointer is valid*/    
		if((NULL_PTR == Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmramBlockDataAddress)
			|| (CDM_NVMREAD_IMME == Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmRead))  
		{
			/*if there is no ram block or config for read immediately*/
			retValue = NvM_ReadBlock(BlockId, DstPtr);
		}       
		else
		{ 
			Get_Block_Size = Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmBlockLength;
			/*Copy NVM value to destination buffer*/         

			TS_MemCpy(DstPtr, Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmramBlockDataAddress, Get_Block_Size); 

			retValue = (uint8)NVM_REQ_OK;  
		}
    }
    else
    {
		retValue = (uint8)NVM_REQ_NOT_OK;
    } 

	return retValue;
}
/*******************************************************************************
** Syntax :  Cdm_ReadBlockQsm    		          							  **
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
static FUNC(Std_ReturnType, RTE_CODE) Cdm_ReadBlockQsm(uint16 BlockId, void * DstPtr)
{
	uint8 i = 0u;
	uint16 data_len = 0x00u;
	uint16 data_index = 0u;
	Std_ReturnType retValue = (uint8)NVM_REQ_OK; 

	for(i = 0u; i < QSM_CONFIGBLOCKNUM; i++)
	{
		if(Qsm_ConfigAllTable[i].NvmBlockId == BlockId)
		{
			break;
		}
	}

	if(NULL_PTR == DstPtr)
	{
		/*empty pointer.*/
		retValue = (uint8)NVM_REQ_NOT_OK;
	}
	else if(QSM_CONFIGBLOCKNUM == i)
	{
		/*This quasi block not config for Qsm_Readall*/
		retValue = Qsm_ReadBlock(Qsm_ConfigAllTable[i].QuasiBlockId, DstPtr, Qsm_ConfigAllTable[i].offset, Qsm_ConfigAllTable[i].datalen);
	}
	else if(NULL_PTR == Qsm_ConfigAllTable[i].DataPtr)
	{
		/*configuration invalid.*/
		retValue = (uint8)NVM_REQ_NOT_OK;
	}
	else
	{
		TS_MemCpy(DstPtr, Qsm_ConfigAllTable[i].DataPtr, Qsm_ConfigAllTable[i].datalen);

		retValue = (uint8)NVM_REQ_OK;
	}

	return retValue;
}
/*******************************************************************************
** Syntax :  Cdm_WriteBlockNvm       		            					  **
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
static FUNC(Std_ReturnType, RTE_CODE) Cdm_WriteBlockNvm(uint16 BlockId, const void * DstPtr)
{
	uint8 MemCmpRes = E_OK;
	uint8 Ret_NvmResult = NVM_REQ_NOT_OK;
	uint16 Get_Block_Size;
	Std_ReturnType Ret_Value = NVM_REQ_NOT_OK;
	Std_ReturnType Get_ReqErr = E_NOT_OK;	
	
	Get_Block_Size = Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmBlockLength;
	
	if(NULL_PTR == DstPtr)
	{
		/*write data pointer is invaild*/
		Ret_Value = NVM_REQ_NOT_OK;
	}
	else if(NULL_PTR == Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmramBlockDataAddress)
	{
		/*the block doesn't have a ram address*/
		Ret_Value = NvM_WriteBlock(BlockId, DstPtr);
	}
	else
	{
		MemCmpRes = TS_MemCmp(DstPtr, Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmramBlockDataAddress, (uint32)Get_Block_Size);

		if(E_OK == MemCmpRes)
		{
			/*write data is the same with old one*/
			Ret_Value = NVM_REQ_OK;
		}
		else
		{
			/*request write data is different*/
			TS_MemCpy(Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmramBlockDataAddress,DstPtr,(uint32)Get_Block_Size);

			#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
	        (void)NvM_SetRamBlockStatus(BlockId, TRUE);
			#endif

			if(Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmWrite == CDM_NVMWRITE_IMME)
			{
				Get_ReqErr = NvM_GetErrorStatus(BlockId, &Ret_NvmResult);

				if((E_OK == Get_ReqErr) && (NVM_REQ_PENDING != Ret_NvmResult))
				{
					Ret_Value = NvM_WriteBlock(BlockId, Cdm_BlockDescriptorTable[CDM_IDX(BlockId)].CdmramBlockDataAddress);
				}
				else
				{
					Ret_Value = NVM_REQ_NOT_OK;
				}
			}
			else
			{
				/*write data at shot down which means wait for NVM_Writeall()*/
				/*NvM_SetRamBlockStatus(BlockId, TRUE) mark this block has changes*/
				Ret_Value = NVM_REQ_OK;
			}
		}
	}

	return Ret_Value;
}
/*******************************************************************************
** Syntax :  Cdm_WriteBlockQsm    		          							  **
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
static FUNC(Std_ReturnType, RTE_CODE) Cdm_WriteBlockQsm(uint16 BlockId, const void * DstPtr)
{
	uint8 i = 0u;
	Std_ReturnType Ret_Value = NVM_REQ_NOT_OK;

	for(i = 0u; i < QSM_CONFIGBLOCKNUM; i++)
	{
		if(Qsm_ConfigAllTable[i].NvmBlockId == BlockId)
		{
			break;
		}
	}
	
	if(NULL_PTR == DstPtr)
	{
		/*empty pointer*/
		Ret_Value = NVM_REQ_NOT_OK;
	}
	else
	{
		TS_MemCpy(Qsm_ConfigAllTable[i].DataPtr, DstPtr, Qsm_ConfigAllTable[i].datalen);
		Ret_Value = Qsm_WriteBlock(Qsm_ConfigAllTable[i].QuasiBlockId, DstPtr);
	}

	return Ret_Value;
}
