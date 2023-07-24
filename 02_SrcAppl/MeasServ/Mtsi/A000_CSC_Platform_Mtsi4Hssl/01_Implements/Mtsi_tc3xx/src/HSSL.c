/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     ADC420HA22
  CPU:         AURIX TC38XP
  MODULNAME:   HSSL
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file      HSSL.c
 *  \brief     High Speed Serial Link driver source file.
 *  \date      15.07.2020
 *  \copyright Continental AG
 *
 *  The HSSL module provides point-to-point communication of both single data values and of large data blocks.
 *
 */

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
/** @defgroup Productive Productive code
 *  @{
 */
 /** @defgroup HSSL_Module HSSL_Module
 *  @{
 */
#include "HSSL.h"
#include "HSCT.h"
#include "HSSL_HSCT_Cfg.h"
#include "RegAccess.h"
#include "ScuWdt.h"
#include "glob_defs.h"
#include "Irq.h"
#include <Os.h>
	static uint32  HSSL0COK0_ISR_num=0;
	static uint32  HSSL0COK2_ISR_num=0;

/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */

/** @brief Clock Control Register address. */
#define HSSL_CLC_ADDR                (0xF0080000UL)

/** @brief Clock Control Register being enabled. */
#define HSSL_CLC_ENABLE              (0x00000000UL)

/** @brief Clock Control Register being disabled. */
#define HSSL_CLC_DISABLE             (0x00000001UL)

/** @brief Clock Control Register diss(bit which indicates the current status of the module) mask. */
#define HSSL_CLC_DISS_MASK           (0x00000001UL)

/** @brief Clock Control Register diss(bit which indicates the current status of the module) offset. */
#define HSSL_CLC_DISS_OFFSET         (2UL)

/** @brief Configuration Register address. */
#define HSSL_CFG_ADDR                (0xF0080010UL)

/** @brief Configuration Register value. */
#define HSSL_CFG_VALUE               (0x00073FFFUL)

/** @brief Configuration Register streaming mode transmitter offset. */
#define HSSL_CFG_SMT_OFFSET          (16UL)

/** @brief Configuration Register streaming mode receiver offset. */
#define HSSL_CFG_SMR_OFFSET          (17UL)

/** @brief Configuration Register streaming channel mode offset. */
#define HSSL_CFG_SCM_OFFSET          (18UL)

/** @brief Configuration Register global predivider offset. */
#define HSSL_PREDIV_MASK             (0x00003FFFUL)

/** @brief Access Rules Register address. */
#define HSSL_AR_ADDR                 (0xF00800E0UL)

/** @brief Access Window Start Register address. */
#define HSSL_AWSTART_ADDR            (0xF00800C0UL)

/** @brief Access Window End Register address. */
#define HSSL_AWEND_ADDR              (0xF00800C4UL)

/** @brief Access Window End Register channel offset. */
#define HSSL_AWSTARTEND_CH_OFFSET    (8UL)

/** @brief Access Window Start Register value. */
#define HSSL_AWSTART_VALUE           (0x00000000UL)

/** @brief Access Window End Register value. */
#define HSSL_AWEND_VALUE             (0xFFFFFF00UL)

/** @brief Access Rule for Window enable. */
#define HSSL_AR_ARW_EN_ALL           (0x000000FFUL)

/** @brief Number of HSSL channels. */
#define HSSL_NUMBER_OF_CHANNELS      (4UL)

/** @brief Miscellaneous Flags Clear Register address. */
#define HSSL_MFLAGSCL_ADDR           (0xF0080020UL)

/** @brief Initialize Mode Flag offset. */
#define HSSL_INI_OFFSET              (31UL)

/** @brief Miscellaneous Flags Clear Register clearall. */
#define HSSL_MFLAGS_CLEARALL         (0x03C0FFFFUL)

/** @brief Miscellaneous Flags Set Register address. */
#define HSSL_MFLAGSSET_ADDR          (0xF008001CUL)

/** @brief Miscellaneous Flags Set Register target stream enable flag offset. */
#define HSSL_MFLAGSSET_TSES_OFFSET   (28UL)

/** @brief Miscellaneous Flags Set Register initiator stream block request offset. */
#define HSSL_MFLAGSSET_ISBS_OFFSET   (20UL)

/** @brief Target ID Address Register address. */
#define HSSL_TIDADD_ADDR             (0xF0080094UL)

/** @brief Target ID Address Register ID address. */
#define HSSL_TIDADD_IDADDRESS        (0xF0000464UL)

/** @brief Initiator Control Data Register address. */
#define HSSL_ICON_ADDR               (0xF0080034UL)

/** @brief HSSL channel off. */
#define HSSL_CHANNEL_OFF             (0x10UL)

/** @brief Initiator Control Data Register timeout reload value offset. */
#define HSSL_ICON_TOREL_OFFSET       (24UL)

/** @brief Initiator Control Data Register timeout reload value max-value. */
#define HSSL_ICON_TOREL_MAX_VALUE    (0xFFUL)

/** @brief Initiator Control Data Register data length offset. */
#define HSSL_ICON_DATLEN_OFFSET      (16UL)

/** @brief Initiator Control Data Register read write trigger command type offset. */
#define HSSL_ICON_RWT_OFFSET         (18UL)

/** @brief Initiator Read Data Register address. */
#define HSSL_IRD_ADDR                (0xF008003CUL)

/** @brief Initiator Read Write Address Register address. */
#define HSSL_IRWA_ADDR               (0xF0080038UL)

/** @brief Initiator Write Data Register address. */
#define HSSL_IWD_ADDR                (0xF0080030UL)

/** @brief Initiator Stream Start Address Register address. */
#define HSSL_ISSA_ADDR               (0xF00800A0UL)

/** @brief Initiator Stream Frame Count Register address. */
#define HSSL_ISFC_ADDR               (0xF00800ACUL)

/** @brief Target Stream Start Address Register address. */
#define HSSL_TSSA_ADDR               (0xF00800B0UL)

/** @brief Target Stream Frame Count Register address. */
#define HSSL_TSFC_ADDR               (0xF00800BCUL)

/** @brief Kernel Reset Register 0 Register address. */
#define HSSL_KRST0_ADDR              (0xF00800F4UL)

/** @brief Kernel Reset Register 0 Register reset. */
#define HSSL_KRST0_RESET             (0x1UL)

/** @brief Kernel Reset Register 1 Register address. */
#define HSSL_KRST1_ADDR              (0xF00800F0UL)

/** @brief Kernel Reset Register 1 Register reset. */
#define HSSL_KRST1_RESET             (0x1UL)

/** @brief HSSL 32byte allign. */
#define HSSL_32BYTE_ALIGN            (0x20UL)

/** @brief HSSL 32byte mask. */
#define HSSL_32BYTE_MASK             (0x1FUL)

/** @brief HSSL 32byte allign lower. */
#define HSSL_32BYTE_ALIGN_LOWER      (0xFFFFFFE0UL)

/** @brief HSSL Stream length. */
#define HSSL_STREAM_LENGTH           (32u)
/* ================================================================================================================= */
/*                                                Private Types                                                      */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                               Private Variables                                                   */
/* ================================================================================================================= */
/** @brief HSSL_InternalData global variable. */
static HSSL_InternalData_struct HSSL_InternalData;
/* ================================================================================================================= */
/*                                               Public Variables                                                    */
/* ================================================================================================================= */
static uint32 HSSL0COK0_HSSL0COK2_ISR_BLOCK;
/* ================================================================================================================= */
/*                                         Private Functions Prototypes                                              */
/* ================================================================================================================= */
/// @brief      Init function for HSSL Module.
///
/// @pre        none
///
/// @post       none
///
/// @param[in] ChannelId HSSL channel id
/// @param[in] FrameRequest The type of frame request
/// @param[in] ui32Address The address of the frame
/// @param[in] ui32Data The data from the frame
/// @param[in] LengthType The type of data length
///
/// @return void
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   By writing configuration values into specific registers frames are triggered.
///
/// @startuml
/// title Activity Diagram for HSSL_SendFrameRequest
///  start
///   :Setup word size;
///   :Config max reload value;
///   :Config frame request type;
///   :Write in ICON register;
///   if (FrameRequest is different of HSSL_FRAME_READ) then (yes)
///      :Write in IWD Register;
///   else (no)
///   endif
///   :Trigger frame request by writting intro IRWA register;
///  stop
/// @enduml
///
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
static void HSSL_SendFrameRequest(const HSSL_ChannelIdType ChannelId,
                           const HSSL_FrameRequestType FrameRequest,
                           const uint32 ui32Address,
                           const uint32 ui32Data,
                           const HSSL_DataLenType LengthType);

/// @brief      Init function for HSSL Module.
/// @pre        none
///
/// @post       none
///
/// @param[in] u32TargetAddr Target stream address
/// @param[in] u32TsfcVal Target stream frame count value
///
/// @return     HSSL_ReturnType
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   Slave is configured by sending frame configurations to it.
///
/// @startuml
/// title Activity Diagram for HSSL_SetupTargetStream
///  start
///   if (Config target flag is 0) then (yes)
///      :Send a write frame to configure target Config register;
///      :Wait until the frame request is done;
///      if (Frame was not successfully sent) then (yes)
///         :Return value is HSSL_E_NOK;
///      else (no)
///         :Config target flag becomes 1;
///      endif
///   else (no)
///   endif
///   :Send a write frame to configure target Target Stream Start Address register;
///   :Wait until the frame request is done;
///   if (Frame was not successfully sent) then (yes)
///      :Return value is HSSL_E_NOK;
///   else (no)
///   endif
///   :Send a write frame to configure target Target Stream Frame Count register;
///   :Wait until the frame request is done;
///   if (Frame was not successfully sent) then (yes)
///      :Return value is HSSL_E_NOK;
///   else (no)
///   endif
///   :Send a write frame to configure target Miscellaneous Flags Sett register;
///   :Wait until the frame request is done;
///   if (Frame was not successfully sent) then (yes)
///      :Return value is HSSL_E_NOK;
///   else (no)
///   endif
///   :Return value is HSSL_E_OK;
///  stop
/// @enduml
///
/// @testmethod
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
static HSSL_ReturnType HSSL_SetupTargetStream(const uint32 u32TargetAddr, const uint32 u32TsfcVal);

/// @brief      Init function for HSSL Module.
///
/// @pre        none
///
/// @post       none
///
/// @param[in] pui32Data Frame data
/// @param[in] ui16FrameCount Frame count
///
/// @return     void
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   Master is configured by writting configuration values into specific registers.
///
/// @startuml
/// title Activity Diagram for HSSL_SetupMasterStream
///  start
///   :Setup streaming mode;
///   :Setup streaming channel;
///   :Write CFG register with the configured value;
///   :Set the ISBS bit to start the stream;
///  stop
/// @enduml
/// @testmethod
///
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
static void            HSSL_SetupMasterStream(uint32 const * const pui32Data, const uint16 ui16FrameCount);
/* ================================================================================================================= */
/*                                         Private Functions Definitions                                             */
/* ================================================================================================================= */
static void HSSL_SendFrameRequest(const HSSL_ChannelIdType ChannelId,
                           const HSSL_FrameRequestType FrameRequest,
                           const uint32 ui32Address,
                           const uint32 ui32Data,
                           const HSSL_DataLenType LengthType)
{
  uint32 u32RegValue = 0u;

  /* Setup word size */
  u32RegValue |= (uint32)LengthType << HSSL_ICON_DATLEN_OFFSET;

  /* Config max reload value */
  u32RegValue |= HSSL_ICON_TOREL_MAX_VALUE << HSSL_ICON_TOREL_OFFSET;

  /* Config frame request type */
  u32RegValue |= (uint32)FrameRequest << HSSL_ICON_RWT_OFFSET;

  /* Write ICON register */
  RegAccess_Write32(HSSL_ICON_ADDR + ((uint32)ChannelId * HSSL_CHANNEL_OFF), u32RegValue);

  /* COU_COV_DISABLE: <Reason: HSSL_READ_FRAME is not used for current implementation..> */
  if(HSSL_FRAME_READ != FrameRequest)
  /* COU_COV_ENABLE */
  {
    /* Config frame request type */
    RegAccess_Write32(HSSL_IWD_ADDR + ((uint32)ChannelId * HSSL_CHANNEL_OFF), ui32Data);
  }

  /* Trigger frame request by writing into IRWA register */
  RegAccess_Write32(HSSL_IRWA_ADDR + ((uint32)ChannelId * HSSL_CHANNEL_OFF), ui32Address);
}


static HSSL_ReturnType HSSL_SetupTargetStream(const uint32 u32TargetAddr, const uint32 u32TsfcVal)
{
  uint16 u16TimeoutCnt = HSSL_SEND_FRAME_TIMEOUT;
  HSSL_InternalData.ui8ReceivedCOK = 0u;

  if(0u == HSSL_InternalData.ui8ConfigTargetFlag)
  {
    /* Send write frame to configure target start address for memory block 0 on target device */
    HSSL_SendFrameRequest(HSSL_CHANNELID_0, HSSL_FRAME_WRITE, HSSL_CFG_ADDR, HSSL_CFG_VALUE, HSSL_DATALEN_32BIT);
    /*Wait until the frame request is done */
    while ((0u == HSSL_InternalData.ui8ReceivedCOK) && (u16TimeoutCnt > 0u))
    {
      --u16TimeoutCnt;
    }

    /* Check if the frame was not successfully sent */
    if (u16TimeoutCnt == 0u)
    {
      return HSSL_E_NOK;
    }
    else
    {
      HSSL_InternalData.ui8ConfigTargetFlag = 1u;
    }
  }
  else
  {
    /*do nothing*/
  }
  HSSL_InternalData.ui8ReceivedCOK = 0u;
  u16TimeoutCnt = HSSL_SEND_FRAME_TIMEOUT;

  /* Send write frame to configure target start address for memory block 0 on target device */
  HSSL_SendFrameRequest(HSSL_CHANNELID_0, HSSL_FRAME_WRITE, HSSL_TSSA_ADDR, u32TargetAddr, HSSL_DATALEN_32BIT);
  /*Wait until the frame request is done */
  while ((0u == HSSL_InternalData.ui8ReceivedCOK) && (u16TimeoutCnt > 0u))
  {
    --u16TimeoutCnt;
  }

  /* Check if the frame was not successfully sent */
  if (u16TimeoutCnt == 0u)
  {
    return HSSL_E_NOK;
  }

  HSSL_InternalData.ui8ReceivedCOK = 0u;
  u16TimeoutCnt = HSSL_SEND_FRAME_TIMEOUT;

  /* Send write frame to configure target frame count on target device */
  HSSL_SendFrameRequest(HSSL_CHANNELID_0, HSSL_FRAME_WRITE, HSSL_TSFC_ADDR, u32TsfcVal, HSSL_DATALEN_32BIT);
  /*Wait until the frame request is done */
  while ((0u == HSSL_InternalData.ui8ReceivedCOK) && (u16TimeoutCnt > 0u))
  {
    --u16TimeoutCnt;
  }

  /* Check if the frame was not successfully sent */
  if (u16TimeoutCnt == 0u)
  {
    return HSSL_E_NOK;
  }

  HSSL_InternalData.ui8ReceivedCOK = 0u;
  u16TimeoutCnt = HSSL_SEND_FRAME_TIMEOUT;

  /* end write frame to configure target Mflag on target device */
  HSSL_SendFrameRequest(HSSL_CHANNELID_0, HSSL_FRAME_WRITE, HSSL_MFLAGSSET_ADDR, 1UL << HSSL_MFLAGSSET_TSES_OFFSET, HSSL_DATALEN_32BIT);
  /*Wait until the frame request is done */
  while ((0u == HSSL_InternalData.ui8ReceivedCOK) && (u16TimeoutCnt > 0u))
  {
    --u16TimeoutCnt;
  }

  /* Check if the frame was not successfully sent */
  if (u16TimeoutCnt == 0u)
  {
    return HSSL_E_NOK;
  }

  return HSSL_E_OK;
}

static void HSSL_SetupMasterStream(uint32 const * const pui32Data, const uint16 ui16FrameCount)
{
  HSSL_StreamingModeType        StreamingModeTx      = HSSL_SINGLE;
  HSSL_StreamingChannelModeType StreamingChannelMode = HSSL_STREAMING;
  uint32                        ui32CfgRegister      = 0u;

  /*Write the address of pui32Data into the ISSA register*/
  RegAccess_Write32(HSSL_ISSA_ADDR, (uint32)pui32Data);

  /*Wite the number of frames that will be sent into the ISFC register*/
  RegAccess_Write32(HSSL_ISFC_ADDR, ui16FrameCount);
  /* PRQA S 3120 1 *//*For the following 1 line the suppresion is enabled*//*date: 29.03.2021*//*reviewer: Dragos Gheorghiu*//* Hard-coded numbers required for clear representation of bit masks. */
  RegAccess_Write32(HSSL_ICON_ADDR + (2u * HSSL_CHANNEL_OFF), (uint32)0xFF020000u);

  ui32CfgRegister  = RegAccess_Read32(HSSL_CFG_ADDR);
  ui32CfgRegister |= (((uint32)StreamingModeTx << HSSL_CFG_SMT_OFFSET) |
                       ((uint32)StreamingChannelMode << HSSL_CFG_SCM_OFFSET));

  RegAccess_Write32(HSSL_CFG_ADDR, ui32CfgRegister);

  RegAccess_SetBits32(HSSL_MFLAGSSET_ADDR, 1UL << HSSL_MFLAGSSET_ISBS_OFFSET);
}
/* ================================================================================================================= */
/*                                            Public Functions Definitions                                           */
/* ================================================================================================================= */
void HSSL_Init(HSSL_ConfigType const * const Config)
{
  uint8  ui8ChannelIndex = 0u;
  uint16 ui16Timeout = HSSL_SEND_FRAME_TIMEOUT;

  /* Initialize internal data */
  HSSL_InternalData.HsslState = HSSL_UNINITIALIZED;
  HSSL_InternalData.ui8ReceivedCOK = 0;
  HSSL_InternalData.ui8ConfigTargetFlag = 0u;

  SuspendAllInterrupts();
  /* Enable HSSL module */
  ScuWdt_EndinitClear();
  RegAccess_Write32(HSSL_CLC_ADDR, HSSL_CLC_ENABLE);
  ScuWdt_EndinitSet();
  ResumeAllInterrupts();

  /* Wait for the module to be enabled */
  while((0u != ((RegAccess_Read32(HSSL_CLC_ADDR) >> HSSL_CLC_DISS_OFFSET) & HSSL_CLC_DISS_MASK)) && (ui16Timeout > 0u))
  {
    --ui16Timeout;
  }

  /* Check if module was enabled in time */
  if (ui16Timeout > 0u)
  {
    /*Set Config command to Slave*/
    RegAccess_SetBits32(HSSL_CFG_ADDR, (Config->PreDiv & HSSL_PREDIV_MASK));

    /*Initialize channels*/
    for(ui8ChannelIndex = 0u; ui8ChannelIndex < HSSL_NUMBER_OF_CHANNELS; ui8ChannelIndex++)
    {
    RegAccess_Write32(HSSL_AWSTART_ADDR + ((uint32)ui8ChannelIndex * HSSL_AWSTARTEND_CH_OFFSET), HSSL_AWSTART_VALUE);
    RegAccess_Write32(HSSL_AWEND_ADDR   + ((uint32)ui8ChannelIndex * HSSL_AWSTARTEND_CH_OFFSET), HSSL_AWEND_VALUE);
    }
    RegAccess_SetBits32(HSSL_AR_ADDR, HSSL_AR_ARW_EN_ALL);

    RegAccess_SetBits32(HSSL_MFLAGSCL_ADDR, (1UL << HSSL_INI_OFFSET));

    RegAccess_Write32(HSSL_TIDADD_ADDR, HSSL_TIDADD_IDADDRESS);

    /*Change HsslState to HSSL_RUN*/
    HSSL_InternalData.HsslState = HSSL_RUN;
  }
  else
  {
    /* Do not switch the driver state to RUN */
  }
}

HSSL_ReturnType HSSL_SendStreamBlock(const uint32 ui32TargetAddr, void const * const pData, const uint32 ui32Length, boolean const ConfigureTarget)
{
  uint32          ui32LowestAllignedAddr;   /* HSSL start address */
  uint32          ui32BlockLength;          /* HSSL block length */

  uint32          ui32LastDataAddr;         /* Last address of data to be transmited */
  uint32          ui32UpperAddr;

  HSSL_ReturnType ReturnVal = HSSL_E_NOK;

  ui32LowestAllignedAddr = HSSL_Allign_32_Lower((uint32)((uint32 const *)pData));
  ui32BlockLength = HSSL_Allign_32_Upper(ui32Length);
  ui32UpperAddr = ui32LowestAllignedAddr + ui32BlockLength;

  ui32LastDataAddr = (uint32)((uint32 const *)pData) + ui32Length;

  /* Check if length of data to be copied needs one more frame */
  if (ui32LastDataAddr > ui32UpperAddr)
  {
    ui32BlockLength += HSSL_FRAME_SIZE;
  }

  if (HSSL_RUN == HSSL_InternalData.HsslState)
  {
    if(b_TRUE == ConfigureTarget)
    {
      ReturnVal = HSSL_SetupTargetStream(ui32TargetAddr,(ui32BlockLength/HSSL_STREAM_LENGTH));
    }
    else
    {
      ReturnVal = HSSL_E_OK;
    }

    if (HSSL_E_OK == ReturnVal)
    {
      if(b_TRUE == ConfigureTarget)
      {
        HSSL_SetupMasterStream((uint32*)ui32LowestAllignedAddr, 1u);
      }
      else
      {
        HSSL_SetupMasterStream((uint32*)ui32LowestAllignedAddr, (uint16)(ui32BlockLength/HSSL_STREAM_LENGTH));
      }
    }
    else
    {
      ReturnVal = HSSL_E_NOK;
    }
  }
  else
  {
     ReturnVal = HSSL_E_NOK;
  }

  return ReturnVal;
}

void HSSL_MainFunction( void )
{
  HSCT_StateType HSCT_eState = HSCT_GetState();

  /* COU_COV_DISABLE: <Reason: HSSL_State can be only HSSL_UNINITIALIZED or HSSL_RUN.> */
  switch(HSSL_InternalData.HsslState)
  /* COU_COV_ENABLE */
  {
    case HSSL_UNINITIALIZED:
      /* HSSL driver should be initialized after HSCT initialization */
      if(HSCT_eState != HSCT_UNINITIALIZED)
      {
        HSSL_Init(&HSSL_Cfg);
      }
      else
      {
      /* Wait until HSCT is initialized */
      }
      break;

    case HSSL_RUN:
      HSSL0COK0_HSSL0COK2_ISR_BLOCK++;
      break;
    /* COU_COV_DISABLE: <Reason: HSSL_State can be only HSSL_UNINITIALIZED or HSSL_RUN.> */
    default:
      /*do nothing*/
      break;
    /* COU_COV_ENABLE */
  }
}

void HSSL_Reset( void )
{
  uint16 u16TimeoutCnt = 0u;

  SuspendAllInterrupts();

  /* Request kernel reset */
  ScuWdt_EndinitClear();
  RegAccess_Write32(HSSL_KRST0_ADDR, HSSL_KRST0_RESET);
  RegAccess_Write32(HSSL_KRST1_ADDR, HSSL_KRST1_RESET);
  ScuWdt_EndinitSet();

  /* Enable HSSL module */
  ScuWdt_EndinitClear();
  RegAccess_Write32(HSSL_CLC_ADDR, HSSL_CLC_DISABLE);
  ScuWdt_EndinitSet();

  ResumeAllInterrupts();

  HSSL_Init(&HSSL_Cfg);

  HSSL_InternalData.ui8ReceivedCOK = 0u;
  u16TimeoutCnt = HSSL_SEND_FRAME_TIMEOUT;

  /* Send write frame to configure target start address for memory block 0 on target device */
  HSSL_SendFrameRequest(HSSL_CHANNELID_0, HSSL_FRAME_WRITE, HSSL_TSSA_ADDR, (uint32)0u, HSSL_DATALEN_32BIT);
  /*Wait until the frame request is done */
  while ((0u == HSSL_InternalData.ui8ReceivedCOK) && (u16TimeoutCnt > 0u))
  {
    --u16TimeoutCnt;
  }

  /* Check if the frame was not successfully sent */
  if (u16TimeoutCnt == 0u)
  {
    HSSL_InternalData.HsslState = HSSL_UNINITIALIZED;
  }

  HSSL_InternalData.ui8ReceivedCOK = 0u;
  u16TimeoutCnt = HSSL_SEND_FRAME_TIMEOUT;

  /* Send write frame to configure target frame count on target device */
  HSSL_SendFrameRequest(HSSL_CHANNELID_0, HSSL_FRAME_WRITE, HSSL_TSFC_ADDR, (uint32)0u, HSSL_DATALEN_32BIT);
  /*Wait until the frame request is done */
  while ((0u == HSSL_InternalData.ui8ReceivedCOK) && (u16TimeoutCnt > 0u))
  {
    --u16TimeoutCnt;
  }

  /* Check if the frame was not successfully sent */
  if (u16TimeoutCnt == 0u)
  {
    HSSL_InternalData.HsslState = HSSL_UNINITIALIZED;
  }
  HSSL0COK0_HSSL0COK2_ISR_BLOCK = 0;
}

HSSL_StateType HSSL_GetState( void )
{
  return HSSL_InternalData.HsslState;
}

uint32 HSSL_GetIsrBlockCount( void )
{
  return HSSL0COK0_HSSL0COK2_ISR_BLOCK;
}

void HSSL_SetTransmissionDoneCbk(const HSSL_TransmissionDoneCbk fpTransmissionDoneCbk)
{
  HSSL_InternalData.fpTransmissionDoneCbk = fpTransmissionDoneCbk;
}

uint32 HSSL_Allign_32_Upper(const uint32 ui32Address)
{
  uint32 ui32ReturnAddress = 0u;

  if( 0UL == (ui32Address % HSSL_32BYTE_ALIGN))
  {
    ui32ReturnAddress = ui32Address;
  }
  else
  {
    ui32ReturnAddress = ui32Address - (ui32Address & (HSSL_32BYTE_MASK)) + HSSL_32BYTE_ALIGN;
  }
  return ui32ReturnAddress;
}

uint32 HSSL_Allign_32_Lower(const uint32 ui32Address)
{
  return (ui32Address & HSSL_32BYTE_ALIGN_LOWER);
}

/// @brief      Function for ISR COK0.
/// @globals
///   @ref HSSL_InternalData \n
/// @InOutCorrelation
///   ReceivedCok member of HSSL_InternalData becomes 1
//ISR(HSSL_COK0_ISR)
extern void OS_ISR_HSSL0COK0_ISR(void)
{
	HSSL_InternalData.ui8ReceivedCOK = 1u;
  HSSL0COK0_HSSL0COK2_ISR_BLOCK = 0;
	HSSL0COK0_ISR_num++;
}

/// @brief      Function for ISR COK2.
/// @globals
///   @ref HSSL_InternalData \n
/// @InOutCorrelation
///   fpTransmissionDoneCbk() is called
//ISR(HSSL_COK2_ISR)
extern void OS_ISR_HSSL0COK2_ISR(void)
{
  if(NULL_PTR != HSSL_InternalData.fpTransmissionDoneCbk)
  {
    HSSL_InternalData.fpTransmissionDoneCbk();
  }
  HSSL0COK0_HSSL0COK2_ISR_BLOCK = 0;
  HSSL0COK2_ISR_num++;
}


/** @} doxygen end group definition  */
/** @} doxygen end group definition  */


/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
