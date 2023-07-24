/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\QuasiStaticManager
* Class_____: C
* Name______: Qsm_Core.c
* vision____: 0.1
* Author____: YinXing
* History___: 2022/12/14 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
** Quasi Static manager is implemented by the user to manage the quasi-static 
** data. Quasi Static data blocks are read and written using FEE’s read and 
** write APIs.
*******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Rte_Qsm.h>
#include "Fee.h"
#include "Fls.h"
#include "Qsm_Core.h"
#include "Qsm_Lcfg.h"
#include "Qsm_Type.h"
#include "Qsm_Cfg.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
static uint8 Qsm_ErrorCnt;
static uint8 BufferUsed;
static uint32 Qsm_CycleCounter;
static uint8 CurBufferIdx = QSM_INVALID_BLOCK_ID;
static QSM_ReqType_e Qsm_PreReqOprSt;
static QSM_ReqInfo_s QSM_ReqOprStaticBlock;
static QSM_EraseStatus_e Qsm_EraseStatus;
static QSM_ReadStatus_e Qsm_ReadStatus;
static QSM_WriteStatus_e Qsm_WriteStatus;

static QSM_ReqInfo_s Qsm_ReqBuffer[QSM_BUFFER_MAX];

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static FUNC(void, QSM_CODE) Qsm_IdleOperation(void);
static FUNC(void, QSM_CODE) Qsm_EraseOpertion(void);
static FUNC(void, QSM_CODE) Qsm_WriteOpertion(void);
static FUNC(void, QSM_CODE) Qsm_ReadOpertion(void);
static FUNC(uint16, QSM_CODE) Qsm_GetFeeUsrBlockIndex(const uint16 BlockNumber);
static FUNC(void, QSM_CODE) Qsm_ErrorHandle(void);
static FUNC(void, QSM_CODE) Qsm_GetIntoErrorState(void);
static void Qsm_CycleUpdata(void);
static uint8 Qsm_GetBufferIndex(uint16 BlockNumber);
static uint8 Qsm_GetBlockToOperation(void);
static void Qsm_PoopBuffer(void);
static void Qsm_BufferInit(void);

/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Qsm_Core_InitFunction(void)    			  **
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

FUNC(void, RTE_CODE) Qsm_Core_InitFunction(void)
{
	Set_QsmEraseSt(QSM_ERASE_IDLE);
	Set_QsmReadSt(QSM_READ_IDLE);
	Set_QsmWriteSt(QSM_WRITE_IDLE);
	Set_Qsm_ErrorCnt(0u);
	Set_QsmPreReqOprSt(QSM_IDLE);
} 

/*******************************************************************************
** Syntax :  FUNC(void, RTE_CODE) Qsm_Core_MainFunction(void)    			  **
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

FUNC(void, RTE_CODE) Qsm_Core_MainFunction(void)
{
	Qsm_CycleUpdata();
	
	switch(Get_QsmOprSt())
	{
		case QSM_IDLE:
			Qsm_IdleOperation();

			break;

		case QSM_REQREAD:
			Qsm_ReadOpertion();

			break;

		case QSM_REQWRITE:
			Qsm_WriteOpertion();

			break;

		case QSM_ERASE:
			Qsm_EraseOpertion();

			break;
			
		case QSM_ERROR:
			Qsm_ErrorHandle();

			break;
			
		default:
			break;
	}
} 

/*******************************************************************************
** Syntax :  Qsm_ReadBlock()							    				  **
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

FUNC(Std_ReturnType, RTE_CODE) Qsm_ReadBlock(uint16 BlockId, void * QsmDstPtr, uint16 Offset, uint16 Length)
{
	Std_ReturnType Ret_Val = E_NOT_OK;
	uint8 BufferIndex = Qsm_GetBufferIndex(BlockId);

	if(NULL_PTR == QsmDstPtr)
	{
		Ret_Val = E_NOT_OK;
	}
	else if(0xffu == BufferIndex)
	{
		/*request blockid out of range*/
		Ret_Val = E_NOT_OK;
	}
	else if(QSM_REQRESULT_PENDING == Qsm_ReqBuffer[BufferIndex].ReqResult)
	{
		Ret_Val = E_NOT_OK;
	}
	else
	{
		Qsm_ReqBuffer[BufferIndex].QSM_ReqOpretion = QSM_REQREAD;
		Qsm_ReqBuffer[BufferIndex].BlockLength = Length;
		Qsm_ReqBuffer[BufferIndex].BlockOffset = Offset;
		Qsm_ReqBuffer[BufferIndex].DataBuffer = QsmDstPtr;
		Qsm_ReqBuffer[BufferIndex].ReqResult = QSM_REQRESULT_PENDING;
		Qsm_ReqBuffer[BufferIndex].CycCounter = Qsm_CycleCounter;

		Ret_Val = E_OK;
	}

	return Ret_Val;
} 

/*******************************************************************************
** Syntax :  Qsm_WriteBlock()							    				  **
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

FUNC(Std_ReturnType, RTE_CODE) Qsm_WriteBlock(uint16 BlockId, const void * QsmDstPtr)
{
	Std_ReturnType Ret_Val = E_NOT_OK;
	uint8 BufferIndex = Qsm_GetBufferIndex(BlockId);

	if(NULL_PTR == QsmDstPtr)
	{
		Ret_Val = E_NOT_OK;
	}
	else if(0xffu == BufferIndex)
	{
		/*request blockid out of range*/
		Ret_Val = E_NOT_OK;
	}
	else if(QSM_REQRESULT_PENDING == Qsm_ReqBuffer[BufferIndex].ReqResult)
	{
		Ret_Val = E_NOT_OK;
	}
	else
	{
		Qsm_ReqBuffer[BufferIndex].QSM_ReqOpretion = QSM_REQWRITE;
		Qsm_ReqBuffer[BufferIndex].BlockLength = 0x00u;
		Qsm_ReqBuffer[BufferIndex].BlockOffset = 0x00u;
		Qsm_ReqBuffer[BufferIndex].DataBuffer = QsmDstPtr;
		Qsm_ReqBuffer[BufferIndex].ReqResult = QSM_REQRESULT_PENDING;
		Qsm_ReqBuffer[BufferIndex].CycCounter = Qsm_CycleCounter;

		Ret_Val = E_OK;
	}

	return Ret_Val;
} 

/*******************************************************************************
** Syntax : FUNC(Std_ReturnType, QSM_CODE) Qsm_GetErrorStatues(uint16 BlockId)**
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

FUNC(Std_ReturnType, RTE_CODE) Qsm_GetErrorStatues(uint16 BlockId)
{
	uint8 i = 0u;
	Std_ReturnType ret = QSM_REQRESULT_PENDING;
	uint8 idx = 0x00u;

	if(QSM_MutiRead == BlockId)
	{
		for(i = 0u; i < QSM_CONFIGBLOCKNUM; i++)
		{
			idx = Qsm_GetBufferIndex(Qsm_ConfigAllTable[i].QuasiBlockId);
			ret = Qsm_ReqBuffer[idx].ReqResult;

			if((QSM_REQRESULT_PENDING == ret) || (QSM_REQRESULT_NOT_OK == ret))
			{
				break;
			}
			else
			{
				/*QAC*/
			}
		}
	}
	else
	{
		idx = Qsm_GetBufferIndex(BlockId);
		ret = Qsm_ReqBuffer[idx].ReqResult;
	}
	
	return ret;
} 

/******************************************************************************/
/*---------------------------Static Function----------------------------------*/
/******************************************************************************/

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_IdleOperation(void)	   		  **
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

static FUNC(void, QSM_CODE) Qsm_IdleOperation(void)
{
	/*Clear sub state machine*/
	Set_QsmEraseSt(QSM_ERASE_IDLE);
	Set_QsmReadSt(QSM_READ_IDLE);
	Set_QsmWriteSt(QSM_WRITE_IDLE);
	Set_Qsm_ErrorCnt(0u);
	Set_QsmPreReqOprSt(QSM_IDLE);

	CurBufferIdx = Qsm_GetBlockToOperation();

	/*Determine whether there is a pending request*/
	if(QSM_INVALID_BLOCK_ID != CurBufferIdx)
	{
		/*quasi block operation and GC is mutually exclusive. disable GC when quasi request start*/
		Fee_17_DisableGcStart();
		if(Qsm_ReqBuffer[CurBufferIdx].QSM_ReqOpretion == QSM_REQREAD)
		{
			Set_QsmOprSt(QSM_REQREAD);
			Set_QsmBlockId(Qsm_ReqBuffer[CurBufferIdx].BlockId);
			Set_QsmBlockOffset(Qsm_ReqBuffer[CurBufferIdx].BlockOffset);
			Set_QsmBlockLength(Qsm_ReqBuffer[CurBufferIdx].BlockLength);
			Set_QsmDataBuffer(Qsm_ReqBuffer[CurBufferIdx].DataBuffer);
			Qsm_ReqBuffer[CurBufferIdx].ReqResult = QSM_REQRESULT_PENDING;
		}
		else if(Qsm_ReqBuffer[CurBufferIdx].QSM_ReqOpretion == QSM_REQWRITE)
		{
			Set_QsmOprSt(QSM_ERASE);	/*Erase block before write*/
			Set_QsmBlockId(Qsm_ReqBuffer[CurBufferIdx].BlockId);
			Set_QsmBlockOffset(Qsm_ReqBuffer[CurBufferIdx].BlockOffset);
			Set_QsmBlockLength(Qsm_ReqBuffer[CurBufferIdx].BlockLength);
			Set_QsmDataBuffer(Qsm_ReqBuffer[CurBufferIdx].DataBuffer);
			Qsm_ReqBuffer[CurBufferIdx].ReqResult = QSM_REQRESULT_PENDING;
		}
	}
	else
	{
		/*on pending request*/
	}
}

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_EraseOpertion(void)    		  **
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

static FUNC(void, QSM_CODE) Qsm_EraseOpertion(void)
{
	uint16 Fee_BlockIndex = QSM_FEEINVALIDBLOCK;
	Std_ReturnType resultflag;
    Fee_QuasiStaticBlockInfoType BlockInfo;
	Std_ReturnType Erase_Rte = E_NOT_OK;
	
	switch(Get_QsmEraseSt())
	{
		case QSM_ERASE_IDLE:
			Set_QsmEraseSt(QSM_ERASE_START);
				
			break;

		case QSM_ERASE_START:
			Fee_BlockIndex = Qsm_GetFeeUsrBlockIndex(Get_QsmBlockId());
			if(QSM_FEEINVALIDBLOCK != Fee_BlockIndex)
			{
				Erase_Rte = Fee_17_EraseQuasiStaticData(Get_QsmBlockId(), Fee_Config.FeeBlockConfigPtr[Fee_BlockIndex].Instances);

				if(E_OK == Erase_Rte)
				{
					Set_QsmEraseSt(QSM_ERASE_PENDING);
				}
				else
				{
					Qsm_GetIntoErrorState();
				}
			}
			else
			{
				Qsm_GetIntoErrorState();
			}
			
			break;

		case QSM_ERASE_PENDING:
			if(MEMIF_BUSY == Fee_GetStatus() || MEMIF_BUSY_INTERNAL == Fee_GetStatus() || MEMIF_JOB_PENDING == Fee_17_GetQuasiStaticJobResult())
			{
				/*Erase is processing wait for finish*/
			}
			else if(MEMIF_IDLE == Fee_GetStatus() && MEMIF_JOB_OK == Fee_17_GetQuasiStaticJobResult())
			{
				Set_QsmEraseSt(QSM_ERASE_CHECK);
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		case QSM_ERASE_CHECK:
			resultflag = Fee_17_GetQuasiStaticBlockInfo(Get_QsmBlockId(), &BlockInfo);
			if((E_OK == resultflag ) && (FEE_QS_ERASE_COMPLETE == BlockInfo.State))
			{
				Set_QsmOprSt(QSM_REQWRITE);
				Set_QsmEraseSt(QSM_ERASE_IDLE);
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		default:
			break;
	}
}

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_WriteOpertion(void)    		  **
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
static FUNC(void, QSM_CODE) Qsm_WriteOpertion(void)
{
	Std_ReturnType Write_Rte;
	Std_ReturnType resultflag;
    Fee_QuasiStaticBlockInfoType BlockInfo;
	
	switch(Get_QsmWriteSt())
	{
		case QSM_WRITE_IDLE:
			Set_QsmWriteSt(QSM_WRITE_START);

			break;

		case QSM_WRITE_START:
			Write_Rte = Fee_Write(Get_QsmBlockId(), Get_QsmDataBuffer());

			if(E_OK == Write_Rte)
			{
				Set_QsmWriteSt(QSM_WRITE_PENDING);
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		case QSM_WRITE_PENDING:
			if(MEMIF_BUSY == Fee_GetStatus() || MEMIF_BUSY_INTERNAL == Fee_GetStatus() || MEMIF_JOB_PENDING == Fee_17_GetQuasiStaticJobResult())
			{
				/*Write is processing wait for finish*/
			}
			else if(MEMIF_IDLE == Fee_GetStatus() && MEMIF_JOB_OK == Fee_17_GetQuasiStaticJobResult())
			{
				Set_QsmWriteSt(QSM_WRITE_CHECK);
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		case QSM_WRITE_CHECK:
			resultflag = Fee_17_GetQuasiStaticBlockInfo(Get_QsmBlockId(), &BlockInfo);
			if((E_OK == resultflag) && (FEE_QS_WRITE_COMPLETE == BlockInfo.State))
			{
				Qsm_PoopBuffer();
				Set_QsmOprSt(QSM_IDLE);
				Set_QsmWriteSt(QSM_WRITE_IDLE);
				Qsm_ReqBuffer[CurBufferIdx].ReqResult = QSM_REQRESULT_OK;
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		default:
			break;
	}
}

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_ReadOpertion(void)  	  		  **
**                                                                            **
** Sync/Async:  Aynchronous                                                   **
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

static FUNC(void, QSM_CODE) Qsm_ReadOpertion(void)
{
	uint16 Fee_BlockIndex = QSM_FEEINVALIDBLOCK;
	
	Std_ReturnType Read_Rte;
	
	switch(Get_QsmReadSt())
	{
		case QSM_READ_IDLE:
			Set_QsmReadSt(QSM_READ_START);

			break;

		case QSM_READ_START:
			Fee_BlockIndex = Qsm_GetFeeUsrBlockIndex(Get_QsmBlockId());
			if(QSM_FEEINVALIDBLOCK != Fee_BlockIndex)
			{
				Read_Rte = Fee_Read(Get_QsmBlockId(), Get_QsmBlockOffset(), Get_QsmDataBuffer(), Get_QsmBlockLength());

				if(E_OK == Read_Rte)
				{
					Set_QsmReadSt(QSM_READ_PENDING);
				}
				else
				{
					Qsm_GetIntoErrorState();
				}
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		case QSM_READ_PENDING:
			if(MEMIF_BUSY == Fee_GetStatus() || MEMIF_BUSY_INTERNAL == Fee_GetStatus() || MEMIF_JOB_PENDING == Fee_17_GetQuasiStaticJobResult())
			{
				/*Read is processing wait for finish*/
			}
			else if(MEMIF_IDLE == Fee_GetStatus() && MEMIF_JOB_OK == Fee_17_GetQuasiStaticJobResult())
			{
				Set_QsmReadSt(QSM_READ_CHECK);
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		case QSM_READ_CHECK:
			if(MEMIF_JOB_OK == Fee_17_GetQuasiStaticJobResult())
			{
				Qsm_PoopBuffer();
				Set_QsmOprSt(QSM_IDLE);
				Set_QsmReadSt(QSM_READ_IDLE);
				Qsm_ReqBuffer[CurBufferIdx].ReqResult = QSM_REQRESULT_OK;
			}
			else
			{
				Qsm_GetIntoErrorState();
			}

			break;

		default:
			break;
	}
}

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_GetFeeUsrBlockIndex(void)        **
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

static FUNC(uint16, QSM_CODE) Qsm_GetFeeUsrBlockIndex(const uint16 BlockNumber)
{
  const Fee_BlockType  *BlockPtr;
  uint16                Index;
  uint16                BlockNumberRef;

  Index = QSM_FEEFIRSTBLOCK;

  BlockPtr = &(Fee_Config.FeeBlockConfigPtr[Index]);

  BlockNumberRef = BlockPtr->BlockNumber;

  while( (Index < Fee_Config.FeeBlkCnt) &&
         (BlockNumberRef != BlockNumber)
       )
  {
    Index++;

    if(Index < Fee_Config.FeeBlkCnt )
    {
      BlockNumberRef = BlockPtr[Index].BlockNumber;
    }

  }

  /* if block is not configured, return invalid block index */
  if( Index == Fee_Config.FeeBlkCnt )
  {
    Index = QSM_FEEINVALIDBLOCK;
  }
  else if(FEE_QUASI_STATIC_USER != Fee_Config.FeeBlockConfigPtr[Index].FeeUser)
  {
  	Index = QSM_FEEINVALIDBLOCK;
  }
  else
  {
  	/*request block is valid*/
  }

  return(Index);

}/* End of Qsm_GetFeeUsrBlockIndex */

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_ErrorHandle(void)    		  	  **
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

static FUNC(void, QSM_CODE) Qsm_ErrorHandle(void)
{
	if(Get_Qsm_ErrorCnt() <= QSM_ERROR_RETRY_CNT)
	{
		Set_Qsm_ErrorCnt(Get_Qsm_ErrorCnt()++);
		Set_QsmOprSt(Get_QsmPreReqOprSt());
		Set_QsmEraseSt(QSM_ERASE_IDLE);
		Set_QsmReadSt(QSM_READ_IDLE);
		Set_QsmWriteSt(QSM_WRITE_IDLE);
	}
	else
	{
		Set_QsmOprSt(QSM_IDLE);
		Qsm_PoopBuffer();
		Qsm_ReqBuffer[CurBufferIdx].ReqResult = QSM_REQRESULT_NOT_OK;
	}
}

/*******************************************************************************
** Syntax :  static FUNC(void, QSM_CODE) Qsm_GetIntoErrorState(void)    	  **
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

static FUNC(void, QSM_CODE) Qsm_GetIntoErrorState(void)
{
	Set_QsmPreReqOprSt(Get_QsmOprSt());
	Set_QsmOprSt(QSM_ERROR);
}
/*******************************************************************************
** Syntax :  void Qsm_BufferInit(void)    	  								  **
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

static void Qsm_BufferInit(void)
{
	const Fee_BlockType  *BlockPtr;
	uint16                Index;

	Index = QSM_FEEFIRSTBLOCK;

	BlockPtr = &(Fee_Config.FeeBlockConfigPtr[Index]);

	while(Index < Fee_Config.FeeBlkCnt)
	{
		Index++;
		if(FEE_QUASI_STATIC_USER == BlockPtr[Index].FeeUser)
		{
			if(BufferUsed < QSM_BUFFER_MAX)
			{
				Qsm_ReqBuffer[BufferUsed].BlockId = BlockPtr[Index].BlockNumber;
				Qsm_ReqBuffer[BufferUsed].QSM_ReqOpretion = QSM_IDLE;
				Qsm_ReqBuffer[BufferUsed].BlockLength = 0x00u;
				Qsm_ReqBuffer[BufferUsed].BlockOffset = 0x00u;
				Qsm_ReqBuffer[BufferUsed].DataBuffer = NULL_PTR;
				Qsm_ReqBuffer[BufferUsed].ReqResult = QSM_REQRESULT_OK;
				Qsm_ReqBuffer[BufferUsed].CycCounter = QSM_INVALID_CYCLE_MAX;
				BufferUsed++;
			}
			else
			{
				/*Buffer length is less than quasi block number. Please increase QSM_BUFFER_MAX*/
			}
		}
		else
		{
			/*FEE_NVM_USER*/
		}
	}
}
/*******************************************************************************
** Syntax :  static void Qsm_CycleUpdata(void)    	  						  **
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

static void Qsm_CycleUpdata(void)
{
	Qsm_CycleCounter++;
}
/*******************************************************************************
** Syntax :  static uint8 Qsm_GetBufferIndex(uint16 BlockNumber)    	  	  **
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

static uint8 Qsm_GetBufferIndex(uint16 BlockNumber)
{
	uint8 ret = 0xffu;
	uint8 index = 0x00u;
	
	while(index < BufferUsed)
	{
		if(Qsm_ReqBuffer[index].BlockId == BlockNumber)
		{
			ret = index;
		}
		else
		{
			/*Fee number error*/
		}
		index++;
	}

	return ret;
}
/*******************************************************************************
** Syntax :  static uint8 Qsm_GetBlockToOperation(void)    	  				  **
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

static uint8 Qsm_GetBlockToOperation(void)
{
	uint8 Idx;
	uint32 MinValCycle = QSM_INVALID_CYCLE_MAX;
	uint8 MinValId = QSM_INVALID_BLOCK_ID;

	for(Idx = 0u; Idx < BufferUsed; Idx++)
	{
		if((QSM_INVALID_CYCLE_MAX != Qsm_ReqBuffer[Idx].CycCounter) && (Qsm_ReqBuffer[Idx].CycCounter <= Qsm_CycleCounter))
		{
			if(QSM_INVALID_CYCLE_MAX == MinValCycle)
			{
				MinValCycle = Qsm_ReqBuffer[Idx].CycCounter;
				MinValId = Idx;
			}
			else if(Qsm_ReqBuffer[Idx].CycCounter < MinValCycle)
			{
				MinValCycle = Qsm_ReqBuffer[Idx].CycCounter;
				MinValId = Idx;
			}
			else
			{
				/*do nothing*/
			}
		}
		else
		{
			/*do nothing*/
		}
	}

	return MinValId;
}
/*******************************************************************************
** Syntax :  static void Qsm_PoopBuffer(void)    	  						  **
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

static void Qsm_PoopBuffer(void)
{
	/*quasi block operation and GC is mutually exclusive. enable GC when quasi finished*/
	Fee_17_EnableGcStart();
	Qsm_ReqBuffer[CurBufferIdx].CycCounter = QSM_INVALID_CYCLE_MAX;
	Qsm_ReqBuffer[CurBufferIdx].QSM_ReqOpretion = QSM_IDLE;
	Qsm_ReqBuffer[CurBufferIdx].BlockLength = 0x00u;
	Qsm_ReqBuffer[CurBufferIdx].BlockOffset = 0x00u;
	Qsm_ReqBuffer[CurBufferIdx].DataBuffer = NULL_PTR;
}
/*******************************************************************************
** Syntax :  void Qsm_CancelPendingJob(void)   	  							  **
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

void Qsm_CancelPendingJob(void)
{
	uint8 i = 0u;

	for(i = 0u; i < QSM_BUFFER_MAX; i++)
	{
		if(i != CurBufferIdx)
		{
			if(QSM_INVALID_CYCLE_MAX != Qsm_ReqBuffer[i].CycCounter)
			{
				Qsm_ReqBuffer[i].CycCounter = QSM_INVALID_CYCLE_MAX;
				Qsm_ReqBuffer[i].QSM_ReqOpretion = QSM_IDLE;
				Qsm_ReqBuffer[i].BlockLength = 0x00u;
				Qsm_ReqBuffer[i].BlockOffset = 0x00u;
				Qsm_ReqBuffer[i].DataBuffer = NULL_PTR;
				Qsm_ReqBuffer[i].ReqResult = QSM_REQRESULT_OK;
			}
			else
			{
				/*do nothings*/
			}
		}
		else
		{
			/*do not cancel current operation job*/
		}
	}
}
/*******************************************************************************
** Syntax :  void Qsm_ReadAll(void)    	  								      **
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

void Qsm_ReadAll(void)
{
	uint8 i = 0u;
	uint32 QsmReadCycleMax = QSM_GCTIMEOUTMAX;

	/*quasi block operation and GC is mutually exclusive.*/
	/*if there is a GC operation didn't process done during last IGN cycle then GC will start after Fee_init*/
	/*Fee_17_DisableGcStart can't disable a ongoing GC operation*/
	if(Fee_Config.FeeStatePtr->FeeMainJob == 5)
	{
		do
		{
			QsmReadCycleMax--;
			Fee_MainFunction();
		    Fls_MainFunction();
		}while((Fee_Config.FeeStatePtr->FeeMainJob == 5) && (QsmReadCycleMax != 0u));
		/*wait for GC processing done*/
	}
	
	Qsm_BufferInit();
	
	for(i = 0u; i < QSM_CONFIGBLOCKNUM; i++)
	{
		Qsm_ReadBlock(Qsm_ConfigAllTable[i].QuasiBlockId, Qsm_ConfigAllTable[i].DataPtr, Qsm_ConfigAllTable[i].offset, Qsm_ConfigAllTable[i].datalen);
	}
}

