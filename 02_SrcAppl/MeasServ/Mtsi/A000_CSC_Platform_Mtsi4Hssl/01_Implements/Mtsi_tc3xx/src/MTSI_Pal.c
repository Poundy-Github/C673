/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     ADC420HA10
  CPU:         AURIX TC38XP
  MODULNAME:   MTSI_PAL
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file      MTSI_Pal.c
 *  \brief     MTSI Platform abstraction layer source file.
 *  \date      05.12.2020
 *  \copyright Continental AG
 *
 *  PAL layer of MTSI used to send MTS debug data using specific platform hardware.
 *
 */

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */
/* PRQA S 6040 EOF */  /* uib56245: Justification description */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include "MTSI_Pal.h"
#include "HSSL.h"
#include "HSSL_HSCT_Cfg.h"
#include <Rte_MtsiAdapter.h>
#include "MTSI_Cfg.h"



/** @defgroup Productive Productive code
 *  @{
 */

 /** @defgroup MTSI_PAL MTSI_PAL
 *  @{
 */

/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */
/// @brief    Define used to convert nanoseconds to microseconds
#define MTSI_PAL_NANOSEC_TO_MICROSEC                  (1000u)

/// @brief    Define used to convert seconds to microseconds
#define MTSI_PAL_SEC_TO_MICROSEC                      (1000000u)

/// @brief    uint32 bit position offset
#define MTSI_PAL_UINT32_OFFSET                        (32u)

/// @brief    HSSL block offset
#define MTSI_HSSL_BLOCK_OFFSET                        (0x20u)

/// @brief    Frame to byte conversion
#define MTSI_FRAME_TO_BYTE_CONVERSION                 (32u)
//uic15660
#define CFG_MTSI_HSSL_NO_OF_MEM_BLOCKS 				  (2u)
/* ================================================================================================================= */
/*                                                Private Types                                                      */
/* ================================================================================================================= */
/// @brief Status of the PAL specific MTSi module.
typedef enum
{
  MODULE_UNINITIALIZED     = 0, ///< Module is not initialized
  MODULE_PREINITIALIZED    = 1, ///< Preinitialization of module is done
  MODULE_INITIALIZED       = 2, ///< Complete initialization of module is done
  MODULE_DE_INIT_REQUESTED = 3, ///< Deinitialization of module has been requested
  MODULE_DEINITIALIZED     = 4  ///< Module has been deinitialized
} t_ModuleStatePAL;

/// @brief Status of the Driver frame state.
typedef enum
{
  MTA_DRIVER_FRAME_INACTIVE = 0, ///< MTSi Driver frame is inactive
  MTA_DRIVER_FRAME_ACTIVE   = 1  ///< MTSi Driver frame is active
} t_MtaDriverFrameState;

/// @brief Structure used to create SwFreezeHeader for HSSL MTS transmission.
typedef struct
{
  uint32         DataOffset;     ///< Payload offset when aligned to HSSL byte alignment
  uint32         DataLength;     ///< Length of payload in bytes
  MTSI_t_Header  SwFreezeHeader; ///< SW freeze packet header
} t_FreezeInfo;

/// @brief Structure used to create MTA signature for HSSL MTS transmission.
typedef struct
{
  uint64 Timestamp;       ///< MoE timestamp
  uint32 SwPacketsCount;  ///< Number of Sw packets sent in one MTA frame
  uint16 MtaFrameCounter; ///< MTA frame counter
  uint16 Valid;           ///< Valid bitfield used to signalize the end of a MTA frame
} t_MtaSignature;

/// @brief Structure describing one entry in PAL Async Queue
typedef struct
{
  t_FreezeInfo QueuedFreezeInfo; ///< Queued Freeze Info
  void const * QueuedpData;      ///< Queued Pointer to data
} t_PalAsyncQueue;


//ADCU TC387 sends to target address 0x4000 0000, FPGA receives to address 0x1000 0000
//ADCU TC387 sends to target address 0x5000 0000, FPGA receives to address 0x2000 0000
//address offset is 0x3000 0000
#define CFG_MTSI_HSSL_TARGET_BLOCK_ADDRESS_1   (0x40000000UL)
#define CFG_MTSI_HSSL_TARGET_BLOCK_ADDRESS_2   (0x50000000UL)

//#define CFG_MTSI_HSSL_TARGET_BLOCK_ADDRESS_1   (0x10000000UL)
//#define CFG_MTSI_HSSL_TARGET_BLOCK_ADDRESS_2   (0x20000000UL)

/* ================================================================================================================= */
/*                                               Private Variables                                                   */
/* ================================================================================================================= */
/// @brief Pointer towards the MTSi callback for finished transmission. \n
/// This function is called when the transmission is done.
static MTSI_t_TransmissionDoneCbk p_TransmissionDoneCallback = NULL;

/// @brief MTSI PAL Status of the module. \n
/// Indicates the initialization status of the platform abstraction for MTSI.
static t_ModuleStatePAL ModuleStatePAL = MODULE_UNINITIALIZED;

/// @brief Current status of the MTSI output mode.
/// Range: 0 - 4 (OFF = 0, MODE: 1 - 4)
static uint8 OutputMode = MTSI_OUTPUTMODE_OFF;

/// @brief Timestamp of MTA frame start in microseconds.
static uint32 MtaFrameStart = 0u;

/// @brief MTSI PAL internal MTA frame counter.
static uint16 MtaFrameCounter = 0u;

/// @brief Flag used for first MTA fragment.
static boolean FirstFragment = b_TRUE;

/// @brief Variable used for counting SW packets sent.
static uint32 SwPacketsCount = 0u;

/// @brief MTSI PAL HSSL Freeze Info data.
static __align(32) t_FreezeInfo FreezeInfo;

/// @brief MTSI PAL HSSL Mta signature data.
static __align(32) t_MtaSignature MtaSignature;

/// @brief MTSI PAL HSSL Target array addresses.
static const uint32 HsslTargetAddresses[CFG_MTSI_HSSL_NO_OF_MEM_BLOCKS] = {
  CFG_MTSI_HSSL_TARGET_BLOCK_ADDRESS_1,
  CFG_MTSI_HSSL_TARGET_BLOCK_ADDRESS_2
};

/// @brief MTSI PAL HSSL Current Block Index.
static uint8 HsslBlockIndex = 0u;

/// @brief MTSI PAL HSSL Block Offset.
static uint32 HsslBlockOffset = 0u;

/// @brief MTSI PAL HSSL Transmission State.
static t_HsslTransmissionState HsslTransmissionState = HSSL_TRANSMISSION_IDLE;

/// @brief MTSI PAL pointer to queued data.
static void const * pQueuedData = NULL_PTR;

/// @brief MTSI PAL MTA frame state.
static t_MtaDriverFrameState MtaDriverFrameState = MTA_DRIVER_FRAME_INACTIVE;

/// @brief MTSI PAL Async Queue.
static t_PalAsyncQueue PalAsyncQueue[CFG_MTSI_SIZE_OF_ASYNC_QUEUE_MAX];

/// @brief MTSI PAL Async Queue Tail.
static uint32 PalQueueTail = 0u;

/// @brief MTSI PAL Async Queue Head.
static uint32 PalQueueHead = 0u;

/// @brief Number of HSSL frames in the whole MTSI PAL Async Queue.
static uint32 QueueNrOfFrames = 0u;

/* ================================================================================================================= */
/*                                               Public Variables                                                    */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                         Private Functions Prototypes                                              */
/* ================================================================================================================= */
/// @brief      Get timestamp for MoE protocol
static uint64                GetMoeTimestamp(void);

/// @brief      Callback triggered by the HSSL lower layer when a HSSL transmission is completed.
static void                  HsslTransmissionDoneCkb(void);

/// @brief      Send async job freeze info via HSSl
static t_MTSi_Std_ReturnType HsslSendAsyncJobFreezeInfo(t_FreezeInfo const * const pFreezeInfo);

/// @brief      Send async job payload via HSSl
static void                  HsslSendAsyncJobPayload(void const * const p_Data, const uint32 DataLength);

/// @brief      Get the number of hssl frames required to sent a stream
static uint32                GetNumberOfHsslFrames(void const * const p_Data, uint32 const Length);

/// @brief      Start the state machine to send an async job via HSSL
static void                  HsslSendAsyncJob(void);
/* ================================================================================================================= */
/*                                         Private Functions Definitions                                             */
/* ================================================================================================================= */
static uint64 GetMoeTimestamp(void)
{
  uint64 Time_s;
  uint64 Time_Ms;
  uint64 eth_timeStamp = 0;

	SuspendAllInterrupts();
  (void)MTSI_GetTimeStampMs(&Time_Ms);
  (void)MTSI_GetTimeStampSec(&Time_s);
  eth_timeStamp = (((uint32)(Time_s) << 32) | (uint32)(Time_Ms * 1000));
	ResumeAllInterrupts();

  return eth_timeStamp;
}



static void HsslTransmissionDoneCkb(void)
{
  /* COU_COV_DISABLE: <Reason: HsslTransmissionState cannot be in other states apart from those in the switch.> */
  switch(HsslTransmissionState)
  /* COU_COV_ENABLE */
  {
    case HSSL_TRANSMISSION_FREEZE_INFO:
      /* Freeze Info transmission is done -> change to next state to transmit PAYLOAD */
      HsslTransmissionState = HSSL_TRANSMISSION_PAYLOAD;
      /* Trigger Transmission of Payload */
      HsslSendAsyncJobPayload(pQueuedData, FreezeInfo.DataLength);
      break;

    case HSSL_TRANSMISSION_PAYLOAD:
      /* Check if there are jobs in Pal Internal Queue to be sent over HSSL */
      if(PalQueueHead < PalQueueTail)
      {
        /* Trigger Transmission of next job */
        HsslSendAsyncJob();
      }
      else
      {
        /* All jobs from Pal Interna Queue have been sent over HSSL; reset related variables. */
        PalQueueHead = 0u;
        PalQueueTail = 0u;
        QueueNrOfFrames = 0u;

        /* Payload transmission is done -> change state to IDLE */
        HsslTransmissionState = HSSL_TRANSMISSION_IDLE;

        /* Call transmission done callback if available */
        (void)Rte_Call_rpMtsiTxCallback_CDD_MTSI_Callback();
        // CDD_MTSI_Tx_Callback();
      }
      break;

    case HSSL_TRANSMISSION_MTA_SIGNATURE:
      /* MTA signature transmission is done -> change state to IDLE */
      HsslTransmissionState = HSSL_TRANSMISSION_IDLE;
      break;

    default:
      /* COU_COV_DISABLE: <Reason: HsslTransmissionState cannot be in other states apart from those in the switch.> */
      break;
      /* COU_COV_ENABLE */
  }
}

static t_MTSi_Std_ReturnType HsslSendAsyncJobFreezeInfo(t_FreezeInfo  const * const pFreezeInfo)
{
  t_MTSi_Std_ReturnType TransmissionStatus     = MTSI_E_NOK;
  HSSL_ReturnType       HsslTransmissionStatus = HSSL_E_NOK;

  /* Freeze Info transmission is in progress, change HSSL state to FREEZE_INFO */
  HsslTransmissionState = HSSL_TRANSMISSION_FREEZE_INFO;
  /* Send the Freeze Info over HSSL transmission */
  /* PRQA S 314 6 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*/
  /* Casts to void-pointer are required because of generic interface of HSSL_SendStreamBlock. */
  HsslTransmissionStatus = HSSL_SendStreamBlock(HsslTargetAddresses[HsslBlockIndex] + HsslBlockOffset,
                                                (void const *)pFreezeInfo,
                                                sizeof(t_FreezeInfo),
                                                b_FALSE);

  /* Check if the transmission was accepted by the HSSL */
  if(HSSL_E_OK == HsslTransmissionStatus)
  {
    /* Transmission was done succesfully, return OK to MTSi Driver */
    TransmissionStatus = MTSI_E_OK;
  }
  else
  {
    HsslTransmissionState = HSSL_TRANSMISSION_IDLE;
  }

  return (TransmissionStatus);
}

static void HsslSendAsyncJobPayload(void const * const p_Data, const uint32 DataLength)
{
  HSSL_ReturnType HsslTransmissionStatus = HSSL_E_NOK;

  /* Increment block offset with the size of Freeze Info */
  HsslBlockOffset += sizeof(t_FreezeInfo);

  /* Send the Payload over HSSL transmission */
  HsslTransmissionStatus = HSSL_SendStreamBlock(HsslTargetAddresses[HsslBlockIndex] + HsslBlockOffset,
                                                p_Data,
                                                DataLength,
                                                b_FALSE);
  /* Check if the transmission was accepted by the HSSL */
  if(HSSL_E_OK == HsslTransmissionStatus)
  {
    /* Increment SW packets counter */
    SwPacketsCount++;
    /* Increment block offset with payload size, including offset for aligning the data to nearest 32 byte
         aligned address plus the overhead for the next 32 byte aligned address. */
    /* PRQA S 326 6 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*/
    /* Casts to pointer - integer are required because the pointer is 32 bites and we don't lose data. */
    HsslBlockOffset += (uint32)p_Data % CFG_MTSI_HSSL_BYTE_ALIGNMENT;
    HsslBlockOffset += (HSSL_Allign_32_Upper((uint32)p_Data + DataLength) - (uint32)p_Data);
  }
  else
  {
    HsslTransmissionState = HSSL_TRANSMISSION_IDLE;
  }
}

static uint32 GetNumberOfHsslFrames(void const * const p_Data, uint32 const Length)
{
  uint32 ui32LowestAllignedAddr = 0u;
  uint32 ui32UpperAddr = 0u;

  /* Calculate the lowest alligned addressed to 32 bytes for the start address of the payload */
  ui32LowestAllignedAddr = HSSL_Allign_32_Lower((uint32)((uint32 const *)p_Data));
  /* Calculate the upper address of the payload  alligned to 32 bytes */
  ui32UpperAddr = HSSL_Allign_32_Upper((uint32)((uint32 const *)p_Data) + Length);

  /* Return the number of HSSL frames needed to send the payload */
  return (ui32UpperAddr - ui32LowestAllignedAddr)/CFG_MTSI_HSSL_BYTE_ALIGNMENT;
}

static void HsslSendAsyncJob(void)
{
  /* Retrieve the current freeze to be sent via HSSL from Pal Internal Queue */
  FreezeInfo = PalAsyncQueue[PalQueueHead].QueuedFreezeInfo;
  pQueuedData = PalAsyncQueue[PalQueueHead].QueuedpData;

  /* Increment Queue Head */
  PalQueueHead++;
  /* Check if it is the first job in the queue. If yes, send only Freeze Info; Payload will be sent from HSSL Cbk */
  if(PalQueueHead == 1u)
  {
    /* Freeze Info transmission is in progress, change HSSL state to FREEZE_INFO */
    HsslTransmissionState = HSSL_TRANSMISSION_FREEZE_INFO;
    /* Send the first Freeze Info entry for current cycle with the number of frames combined for all jobs. */
    /* PRQA S 314 6 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*/
    /* Casts to void-pointer are required because of generic interface of HSSL_SendStreamBlock. */
    (void)HSSL_SendStreamBlock(HsslTargetAddresses[HsslBlockIndex] + HsslBlockOffset,
                                                (void const *)&FreezeInfo,
                                                (QueueNrOfFrames * MTSI_FRAME_TO_BYTE_CONVERSION),
                                                 b_TRUE);
  }
  else
  {
    (void)HsslSendAsyncJobFreezeInfo(&FreezeInfo);
  }
}
/* ================================================================================================================= */
/*                                            Public Functions Definitions                                           */
/* ================================================================================================================= */
/// @brief      HSSL callback switched from ISR context to OS Task context

FUNC(void, RTE_CODE) CDD_MTSI_Tx_Callback (void)
{
  if ( NULL != p_TransmissionDoneCallback )
  {
    p_TransmissionDoneCallback(MTSI_ID_LANE_0);
  }
  else
  {
    /* Nothing needs to be done */
  }
} /* FUNC(void, RTE_CODE) CDD_MTSI_Tx_Callback (void) */

/* Initialization of the platform abstraction module for MTSI */
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameters p_TriggerTransmissionCbk, InstanceNr and p_StartMTAFrameCbk are requiered because of generic interface of MTSI_PalInit */
void MTSI_PalInit(const uint8 Mode, const uint8 InstanceNr, const MTSI_t_TransmissionDoneCbk p_TransmissionDoneCbk, const MTSI_t_StartMTAFrameCbk p_StartMTAFrameCbk, const MTSI_t_TriggerTransmissionCbk p_TriggerTransmissionCbk)
{
  OutputMode = Mode;
  /* Only initialize DMA in case it has never be done before */
  if ((MODULE_UNINITIALIZED == ModuleStatePAL) || (MODULE_DEINITIALIZED == ModuleStatePAL))
  {
    p_TransmissionDoneCallback = p_TransmissionDoneCbk;

    /* Send pointer for Callback function to HSSL layer */
    HSSL_SetTransmissionDoneCbk(&HsslTransmissionDoneCkb);

    /* Init global variables */
    HsslTransmissionState = HSSL_TRANSMISSION_IDLE;
    FirstFragment = b_TRUE;

    /* Change module state */
    ModuleStatePAL = MODULE_INITIALIZED;
  }
}

/* Deinitialization of the platform abstraction module for MTSI */
void MTSI_PalDeInit(void)
{
  /* Change module state */
  ModuleStatePAL = MODULE_DEINITIALIZED;
}

/* Get local timestamp */
uint32 MTSI_PalGetTimestamp(void)
{
  uint64 Time_Ms;
  uint32 ui32_timeStamp = 0;

  SuspendAllInterrupts();
  (void)MTSI_GetTimeStampMs(&Time_Ms);
  ui32_timeStamp = (uint32)(Time_Ms * 1000);
  ResumeAllInterrupts();
  
  return ui32_timeStamp;
}

/* Get core ID via OS */
uint8 MTSI_PalGetCoreId(void)
{
  return ((uint8)MTSI_GetCoreID());
}


/* Request TriggerTransmission() on core 0 */
void MTSI_PalSetTriggerTransmissionEvent(void)
{
}

/* Start a new MTA frame */
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameter LaneId is requiered because of generic interface of MTSI_PalStartMTAFrame*/
Std_ReturnType MTSI_PalStartMTAFrame(const uint8 LaneId)
{
  Std_ReturnType  ReturnValue        = E_NOT_OK;

  /* Store timestamp of MTA frame start */
  MtaFrameStart = MTSI_PalGetTimestamp();


  /* Reset SwPacketsCount and HsslBlockOffset to zero */
  SwPacketsCount = 0u;
  HsslBlockOffset = MTSI_HSSL_BLOCK_OFFSET;

  /* Get Timestamp for MTA Signature */
  MtaSignature.Timestamp = GetMoeTimestamp();

  /* Increment MTA frame counter */
  MtaFrameCounter++;

  /* Change Frame State to ACTIVE */
  MtaDriverFrameState = MTA_DRIVER_FRAME_ACTIVE;

  ReturnValue = E_OK;

  return ReturnValue;
}

/* Finish the current MTA frame */
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameter LaneId is requiered because of generic interface of MTSI_PalFinishMTAFrame*/
Std_ReturnType MTSI_PalFinishMTAFrame(const uint8 LaneId)
{
  Std_ReturnType  ReturnValue            = E_NOT_OK;
  HSSL_ReturnType HsslTransmissionStatus = HSSL_E_NOK;

  /* Update the MTA signature */
  MtaSignature.SwPacketsCount = SwPacketsCount;
  MtaSignature.Valid = 0x0001u;
  MtaSignature.MtaFrameCounter = MtaFrameCounter;

  /* Check if this is the first MTA frame after reset and set the FirstFragment bit to 1 */
  if(b_TRUE == FirstFragment)
  {
    FirstFragment = b_FALSE;
    MtaSignature.Valid |= ((uint16)0x1u << CFG_MTSI_HSSL_FIRST_FRAGMENT_OFFSET);
  }

  if(HSSL_TRANSMISSION_IDLE == HsslTransmissionState)
  {
    /* MTA signature transmission is in progress, change HSSL state to MTA_SIGNATURE */
    HsslTransmissionState = HSSL_TRANSMISSION_MTA_SIGNATURE;
    /* Send the MTA signature over HSSL transmission */
    /* PRQA S 314 6 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*/
    /* Casts to void-pointer are required because of generic interface of HSSL_SendStreamBlock. */
    HsslTransmissionStatus = HSSL_SendStreamBlock(HsslTargetAddresses[HsslBlockIndex],
                                                  (void *)&MtaSignature,
                                                  sizeof(t_MtaSignature),
                                                  b_TRUE);

    /* Check if the transmission was accepted by the HSSL */
    if(HSSL_E_OK == HsslTransmissionStatus)
    {
      /* Increment Block Index */
      HsslBlockIndex = (HsslBlockIndex + 1u) % CFG_MTSI_HSSL_NO_OF_MEM_BLOCKS;
      /* Transmission succesfully done, return OK */
      ReturnValue = E_OK;

      MtaDriverFrameState = MTA_DRIVER_FRAME_INACTIVE;
    }
    else
    {
      HsslTransmissionState = HSSL_TRANSMISSION_IDLE;
    }
  }

  return ReturnValue;
}

/* Get the timestamp for the start of the last MTA frame */
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameter LaneId is requiered because of generic interface of MTSI_PalGetMtaFrameStart */
uint32 MTSI_PalGetMtaFrameStart(const uint8 LaneId)
{
  return MtaFrameStart;
}

/* Get the total number of MTA frames */
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameter LaneId is requiered because of generic interface of MTSI_PalGetMtaFrameCounter */
uint16 MTSI_PalGetMtaFrameCounter(const uint8 LaneId)
{
  return MtaFrameCounter;
}
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//*The parameters LaneId, Length and p_Data are requiered because of generic interface of MTSI_PalQueueSyncBuffer*/
t_MTSi_Std_ReturnType MTSI_PalQueueSyncBuffer(const uint8 LaneId, void const * const p_Data, const uint32 Length)
{
  /* Local variables */
  t_MTSi_Std_ReturnType TransmissionStatus = MTSI_E_NOK;

  /* Allow execution only on core 0, if the MTSi PAL is initialized and output enabled. */
  if ( MODULE_INITIALIZED == ModuleStatePAL )
  {
  }
  else
  {
    /* Nothing needs to be done */
  }

  return (TransmissionStatus);
}


/* Initiate the transmission of a single async job */
/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameter LaneId is requiered because of generic interface of MTSI_PalQueueAsyncJob */
t_MTSi_Std_ReturnType MTSI_PalQueueAsyncJob(const uint8 LaneId, MTSI_t_Header const * const p_Header, void const * const p_Data)
{
  /* Local variables */
  t_MTSi_Std_ReturnType TransmissionStatus = MTSI_E_NOK;
  uint32                DataLength = 0u;

  /* Allow execution only on core 0, if the MTSi PAL is initialized and output enabled. */
  if ( MODULE_INITIALIZED == ModuleStatePAL )
  {
    if((HSSL_TRANSMISSION_IDLE == HsslTransmissionState) &&
       (MTA_DRIVER_FRAME_ACTIVE == MtaDriverFrameState) &&
       (CFG_MTSI_SIZE_OF_ASYNC_QUEUE_MAX > PalQueueTail))
    {
      /* Check validity of input parameters */
      if ( (NULL != p_Header) && (NULL != p_Data) )
      {
        DataLength = MTSI_PalSwapUINT32(&p_Header->CtrlFieldAndPayloadLength) & (uint32)MTSI_PAYLOAD_LENGTH_BIT_MASK;

        /* Update Freeze Info packet */
        /* PRQA S 326 6 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*/
        /* Casts to pointer - integer are required because the pointer is 32 bites and we don't loose data. */
        PalAsyncQueue[PalQueueTail].QueuedFreezeInfo.DataOffset     = (uint32)p_Data % CFG_MTSI_HSSL_BYTE_ALIGNMENT;
        PalAsyncQueue[PalQueueTail].QueuedFreezeInfo.DataLength     = DataLength;
        PalAsyncQueue[PalQueueTail].QueuedFreezeInfo.SwFreezeHeader = *p_Header;

        /* Queue the pointer for current async job and send it later when PalTriggerTransmission is called */
        PalAsyncQueue[PalQueueTail].QueuedpData = p_Data;

        /* Increment one time the number of freezes for Freeze Info */
        QueueNrOfFrames++;
        /* Increment with the required number of frames for the received freeze payload */
        QueueNrOfFrames += GetNumberOfHsslFrames(p_Data, DataLength);
        /* Increment the Queue Tail with one more job */
        PalQueueTail++;

        /* Change status to OK */
        TransmissionStatus = MTSI_E_OK;
      }
      else
      {
         /* Nothing to do */
      }
    }
    else
    {
      /* Request TriggerTransmission */
      TransmissionStatus = MTSI_E_TRIG_REQUEST;
    }
  }
  else
  {
     /* Nothing to do */
  }

  return (TransmissionStatus);
}

void MTSI_PalUpdateStatistics(void)
{
}

/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameter LaneId is requiered because of generic interface of MTSI_PalTriggerTransmission */
t_MTSi_Std_ReturnType MTSI_PalTriggerTransmission(const uint8 LaneId)
{
  /* Local variables */
  t_MTSi_Std_ReturnType TransmissionStatus = MTSI_E_NOK;

  if (MTSI_OUTPUTMODE_1 == OutputMode)
  {
    /* Check if there is a job to be sent */
    if((0u != PalQueueTail) && (0u == PalQueueHead))
    {
      /* Set transmission state to PENDING */
      HsslTransmissionState = HSSL_TRANSMISSION_PENDING;
      /* Send the Async Job over HSSL */
      HsslSendAsyncJob();
      TransmissionStatus = MTSI_E_OK;
    }
  }
  else
  {
    /* Nothing to do, MTSi output is disabled. */
  }

  return (TransmissionStatus);
}


/* PRQA S 3206 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* The parameters byteCnt and blockPtr are requiered because of generic interface of MTSI_PalFlushCache*/
void MTSI_PalFlushCache(const void* const blockPtr, const uint32 byteCnt)
{
}

/* Disable interrupts via SYS component */
t_MTSi_Std_ReturnType MTSI_PalEnterExclusiveArea(void)
{
  SuspendAllInterrupts();
  return MTSI_E_OK;
}


/* Enable interrupts via SYS component */
void MTSI_PalExitExclusiveArea(void)
{
  ResumeAllInterrupts();
}

/* Convert the header endianness */
MTSI_t_Header MTSI_PalConvertHeaderEndianness(MTSI_t_Header const * const p_Header)
{
  MTSI_t_Header ConvertedHeader;

  /* Convert header */
  ConvertedHeader.VirtualAddress = MTSI_PalSwapUINT32(&p_Header->VirtualAddress);
  ConvertedHeader.CtrlFieldAndPayloadLength = MTSI_PalSwapUINT32(&p_Header->CtrlFieldAndPayloadLength);
  ConvertedHeader.TaskIdentifier = MTSI_PalSwapUINT16(&p_Header->TaskIdentifier);
  ConvertedHeader.TaskCounter = MTSI_PalSwapUINT16(&p_Header->TaskCounter);
#if( (defined CFG_MTSI_HEADER_USE_FUNCTION_ID) && (TRUE == CFG_MTSI_HEADER_USE_FUNCTION_ID) )
  ConvertedHeader.FunctionId = MTSI_PalSwapUINT16(&p_Header->FunctionId);
#endif
#if( (defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER) )
  ConvertedHeader.PacketCounter = MTSI_PalSwapUINT16(&p_Header->PacketCounter);
#endif
#if( (defined CFG_MTSI_HEADER_USE_HIGH_RES_TIMESTAMP) && (TRUE == CFG_MTSI_HEADER_USE_HIGH_RES_TIMESTAMP) )
  ConvertedHeader.Timestamp.Absolute = MTSI_PalSwapUINT32(&p_Header->Timestamp.Absolute);
#else
  ConvertedHeader.Timestamp.Absolute = MTSI_PalSwapUINT16(&p_Header->Timestamp.Absolute);
#endif
  ConvertedHeader.PaddingLength = MTSI_PalSwapUINT16(&p_Header->PaddingLength);

  return ConvertedHeader;
}


/* Swap the endianness of a uint16 */
uint16 MTSI_PalSwapUINT16(uint16 const * const p_Data)
{
  /* PRQA S 3120 1 *//* Hard-coded numbers required for clear representation of bit masks. - Reviewed by M. Limbrunner, G. Fischer on 2016-05-12 */
  return (((uint16) (*p_Data >> 8) & (uint16) 0x00FF) | ((uint16) (*p_Data << 8) & (uint16) 0xFF00));
}


/* Swap the endianness of a uint32 */
uint32 MTSI_PalSwapUINT32(uint32 const * const p_Data)
{
  /* PRQA S 3120 1 *//* Hard-coded numbers required for clear representation of bit masks. - Reviewed by M. Limbrunner, G. Fischer on 2016-05-12 */
  return (((*p_Data >> 24) & 0x000000FFu) | ((*p_Data >> 8) & 0x0000FF00u) | ((*p_Data << 8) & 0x00FF0000u) | ((*p_Data << 24) & 0xFF000000u));
}

t_HsslTransmissionState MTSI_PalGetHsslTransmissionState(void)
{
  /* Returns HsslTransmissionState */
  return HsslTransmissionState;
}

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
