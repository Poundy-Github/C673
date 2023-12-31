/**
 * \file
 *
 * \brief AUTOSAR Fee
 *
 * This file contains the implementation of the AUTOSAR
 * module Fee.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* This file contains the prototypes of internal functions used by Fee APIs from AUTOSAR_SWS_FlashEEPROMEmulation.pdf
 * and internal definitions and declarations */

#ifndef FEE_INTERNAL_TYPES_H
#define FEE_INTERNAL_TYPES_H

/*==================[inclusions]============================================*/
#include <TSAutosar.h>        /* EB specific standard types */
#include <Fee_Cfg.h>          /* FEE configuration header */
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/** \brief This type represents the current job of the FEE module */
typedef uint8 Fee_Job_t;
#define  FEE_NO_JOB                 (Fee_Job_t)0      /**< No job is requested */
#define  FEE_READ_JOB               (Fee_Job_t)1      /**< Read job is requested */
#define  FEE_WRITE_JOB              (Fee_Job_t)2      /**< Write job is requested */
#define  FEE_INVALIDATE_JOB         (Fee_Job_t)3      /**< Invalidate job */
#define  FEE_ERASE_IMMEDIATE_JOB    (Fee_Job_t)4      /**< Erase immediate job is requested */

/** \brief This type represents the current internal mode of the FEE module */
typedef uint8 Fee_Mode_t;
#define  FEE_MODE_STARTUP1              (Fee_Mode_t)0                /**< First mode after initialization */
#define  FEE_MODE_STARTUP2              (Fee_Mode_t)1                /**< Repair mode after initialization */
#define  FEE_MODE_NORMAL                (Fee_Mode_t)2                /**< Normal runtime mode */
#define  FEE_MODE_SWITCH                (Fee_Mode_t)3                /**< Switch mode */

typedef uint8 Fee_SectionStatus_t;
#define  FEE_SECTION_UNKNOWN_STATUS              (Fee_SectionStatus_t)0    /**< Default status after initialization */
#define  FEE_SECTION_ERASED                      (Fee_SectionStatus_t)1    /**< Section is erased */
#define  FEE_SECTION_EMPTY                       (Fee_SectionStatus_t)2    /**< Section is empty */
#define  FEE_SECTION_NO_FOOTER                   (Fee_SectionStatus_t)3    /**< Section is empty without a footer */
#define  FEE_SECTION_ACTIVE                      (Fee_SectionStatus_t)4    /**< Section is active */
#define  FEE_SECTION_ACTIVE_INCONSISTENT         (Fee_SectionStatus_t)5    /**< Active section with either header or footer inconsistent */
#define  FEE_SECTION_ERASABLE                    (Fee_SectionStatus_t)6    /**< Section marked as erasable */
#define  FEE_SECTION_ERASABLE_INCONSISTENT       (Fee_SectionStatus_t)7    /**< Section marked as erasable with either header or footer inconsistent */
#define  FEE_SECTION_ERASABLE_HEADER             (Fee_SectionStatus_t)8    /**< Section header marked as erasable */
#define  FEE_SECTION_INCONSISTENT                (Fee_SectionStatus_t)9    /**< Section inconsistent */

/** \brief Structure for header information. */
typedef struct
{
  uint8 SCounter; /**< Erase counter */
  uint8 SectionStatus; /**< Section status */
}Fee_HeaderStatusType;

/** \brief typedefinition for the function pointer to be called */
typedef P2FUNC( void, FEE_CODE, Fee_FunctionPtrType )( void );

/** \brief Structure containing the global variables of the module which
 * can be initialized */
/* !LINKSTO Fee.GlobalVariables,1 */
typedef struct
{
  /* Internal buffer pointer*/
  P2VAR(uint8, FEE_VAR_CLEARED, FEE_APPL_DATA) FeeBuffPtr;
  /* Holds the address of the next function which will be executed in state FEE_TRIGGER_JOB_OR_INTERNAL */
  Fee_FunctionPtrType TriggerFunct;
  /* Array to store the blocks addresses */
  Fls_AddressType FeeCache[FEE_TOTAL_NUMBER_OF_BLOCKS];
  /* Array to store the addresses where the blocks are switched from */
  Fls_AddressType FeeSwRestartCache[FEE_TOTAL_NUMBER_OF_BLOCKS];
  /* Considered written size(with inconsistent data), used to avoid flash overwrite */
  Fls_AddressType FeeLostSectionSize;
  /* Address to the next block data to be find at init */
  Fls_AddressType FeeWorkingDataAddress;
  /* Address to the next block info to be find at init */
  Fls_AddressType FeeWorkingInfoAddress;
  /* Address where switch should read from */
  Fls_AddressType FeeSwitchSourceAddress;
  /* Address to which next data block to be written */
  Fls_AddressType FeeDataAddress;
  /* Address to which next block info to be written */
  Fls_AddressType FeeInfoAddress;
#if (FEE_CRITICAL_BLOCK_NUMBER != 0U)
  /* Address to which critical block info to be written */
  Fls_AddressType FeeInfoAddressCritical;
  /* Address to which critical block data to be written */
  Fls_AddressType FeeDataAddressCritical;
#endif
  /* Space needed for blocks to be switched in the last empty section */
  Fls_LengthType FeeSwitchRequiredSpace;
  /* To save user data buffer pointer during Write*/
  P2CONST(uint8, FEE_VAR_CLEARED, FEE_APPL_DATA) FeeBlockDataWriteBuffPtr;
  /* To save user data buffer pointer during Read*/
  P2VAR(uint8, FEE_VAR_CLEARED, FEE_APPL_DATA) FeeBlockDataReadBuffPtr;
  /* !LINKSTO Fee.SectionEraseCounter,1 */
  /* Store the number of erase cycles for the underlying flash device */
  uint32 SectionEraseCounter;
  /* Flash job result */
  MemIf_JobResultType FeeFlashJobResult;
  /* Fee Job result */
  MemIf_JobResultType FeeJobResult;
  /*Array of all sections headers and footers situation*/
  Fee_HeaderStatusType Fee_SectionManagement[FEE_NUMBER_OF_SECTIONS];
  /* The remaining size to be switched for a block */
  uint16 FeeSwitchBlockRemSize;
  /* The size of the current peace of the block that is being copied */
  uint16 FeeSwitchBlockSizeToCopy;
  /* Stores the internal flags used by Fee during runtime */
  uint16 FeeInternalFlags;
  /* Index in Fee Buffer used for init */
  uint16 Fee_BufferIndex;
  /* Index to the block configuration table for a block number */
  uint16 FeeIntBlockIndex;
  /* Index of the last copied block */
  uint16 FeeCopyBlockIndex;
  /* To save the BlockReadSize parameter of Fee_Read */
  uint16 FeeLength;
  /* To save the BlockReadOffset parameter of Fee_Read */
  uint16 FeeBlockReadOffset;
  /* Number of blocks found at initialization */
  uint16 FeeNbOfBlocksFound;
#if (FEE_NUMBER_NOT_CONFIGURED_BLOCKS != 0U)
  /* Number of not configured blocks found at initialization */
  uint16 FeeNbOfNotCfgBlocksFound;
#endif
#if (FEE_DYNAMIC_BLOCK_LENGTH == STD_ON)
  /* Array for storing older blocks lengths */
  uint16 FeeOldSizes[FEE_NO_OF_CONFIGURED_BLOCKS];
#endif
  /* Newest active section; new blocks will be written to this section */
  uint8 FeeActiveSectionIndex;
  /* Oldest active section; first switch will be done from this section */
  uint8 FeeOldestSectionIndex;
  /* Timer counter to count the internal operation delay time;
     after startup1 or after writing currently active section as full */
  uint8 FeeDelayTimer;
  /* Counter used to store the number of state retries */
  uint8 FeeRetryStateCounter;
  /*Current section index*/
  uint8 FeeWorkingSectionIndex;
  /* Number of BlockInfos found empty at FillCache step */
  uint8 Fee_NumberOfMarginBlockInfos;
#if (FEE_FREEZE_ACTIVITIES_API == STD_ON)
  /* Flag to check if FEE activities are freezed */
  boolean FreezeActivities;
#endif
  /* To save the current job */
  Fee_Job_t FeeJob;
  /* To save the current switch job */
  Fee_Job_t FeeSwitchJob;
  /* Stores the state to retry */
  Fee_State_t FeeRetryState;
  /* Stores the state the switch must resume from */
  Fee_State_t FeeSwitchState;
#if (FEE_CRITICAL_BLOCK_NUMBER != 0U)
  /* Stores the state interrupted by critical block */
  Fee_State_t FeeCriticalState;
#endif
  /* Stores the Fee mode */
  Fee_Mode_t FeeMode;
}Fee_Gv_t;



/** \brief Structure containing user-configuration of block specific parameters
 ** for FEE module. */
typedef struct
{
  uint16 FeeBlockSize; /**< Size of the block configured in bytes */
  uint16 FeeBlockAlignedSize; /**< Size of the block aligned to the virtual page size */
  uint16 FeeBlockNumber; /**< Block number of the block configured */
  boolean FeeImmediateData; /**< To mark whether the block contains immediate data */
}Fee_BlockConfiguration_t;

/** \brief Structure containing user-configuration of sections
 ** for FEE module. */
typedef struct
{
  uint32 FeeSectionStartAddress; /**< The address where the section starts */
  uint32 FeeSectionSize; /**< Size of the section in bytes */
}Fee_SectionConfiguration_t;

/** \brief typedefinition for checksum */
typedef uint8 Fee_ChecksumType;

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef FEE_INTERNAL_TYPES_H */
