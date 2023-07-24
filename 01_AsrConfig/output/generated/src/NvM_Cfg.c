/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \version 6.17.24
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */




/*  MISRA-C:2012 Deviation List
 *
 *  MISRAC2012-1) Deviated Rule: 11.1 (required)
 *           "Conversions shall not be performed between a pointer to a function
 *           and any type other than an integral type."
 *
 *           Reason:
 *           The cast is necessary in order to avoid compiler warnings when mixing
 *           ports for mirror operations of different AUTOSAR versions.
 *
 *  MISRAC2012-2) Deviated Rule: 20.10 (advisory)
 *           "The # and ## preprocessor operators should not be used."
 *
 *           Reason:
 *           Concatenation(##) operator is used by pre compile time parameter. It doesn't
 *           have any negative impact on code.
 *
 */

/*==================[inclusions]=============================================*/
#if (defined NVM_INTERNAL_USE)
#error NVM_INTERNAL_USE already defined
#endif
/* prevent redundant declarations of RTE types */
#define NVM_INTERNAL_USE

#include <TSAutosar.h>

/* !LINKSTO SWS_NvM_00554,2 */
#include <NvM.h>
#include <NvM_FunctionIntern.h> /* for initialization of NvM_CalcCrc */
#include <NvM_DataIntern.h>   /* extern definition of NvM_ConfigurationId */
#include <NvM_CalcCrc.h>      /* Extern definitions of unit 'CalcCrc'. */
#include <NvM_UsrHdr.h>

#if (NVM_INCLUDE_RTE == STD_ON)
# include <Rte_NvM.h>
# include <Rte_NvMData.h>
#endif

/*==================[macros]================================================*/

#if (defined NVM_JOIN)
#error NVM_JOIN is already defined
#endif
/** \brief Concatenate the arguments X and Y after they are expanded by the
 ** preprocessor.
 **
 ** These are just helper macros used in the definition of NVM_ASSERT_STC().
 **/
#define NVM_JOIN(X,Y)  NVM_JOIN1(X,Y)

#if (defined NVM_JOIN1)
#error NVM_JOIN1 is already defined
#endif
/* Deviation MISRAC2012-2 */
#define NVM_JOIN1(X,Y) X##Y

/** \brief Check static assertion at compile time
 **
 ** \param expr logical expression to be evaluated at compile time
 **
 ** If \a expr evaluates to FALSE the compiler will abort with an error
 ** because array with a negative number of elements are forbidden in C.  If
 ** \a expr is TRUE the macro expands to a legal typedef.
 **
 ** The usage of this macro does \e not lead to additional resource usage in
 ** the resulting binary code.
 **
 ** The macro should be used were preprocessor #if directives cannot evaluate
 ** expressions but where these expressions can still be evaluated before
 ** runtime. E.g. expressions containig sizeof() functions used on types may
 ** be checked: NVM_ASSERT_STC(sizeof(Mod_SomeType) < 16U)
 **
 ** \note Macro may only be used at places in the code where typedefs are
 ** allowed.
 **/

#if (defined NVM_ASSERT_STC)
#error NVM_ASSERT_STC is already defined
#endif
/* Deviation MISRAC2012-2 <+2> */
#define NVM_ASSERT_STC(expr)\
 typedef uint8 NVM_JOIN(AssertFailedInLine,__LINE__)[(expr)?1:-1]

                    /* BlockIdentifier: 5 - RamBlockDataAddress: &RAM_NVM_BLOCK_ECUHardwareVersion */
        /* Length = 8U (Block length) */
        NVM_ASSERT_STC(8U == sizeof(RAM_NVM_BLOCK_ECUHardwareVersion));
        /* BlockIdentifier: 5 - RomBlockDataAddress: &ROM_NVM_BLOCK_ECUHardwareVersion */
    /* Length = 8U */
    NVM_ASSERT_STC(8U == sizeof(ROM_NVM_BLOCK_ECUHardwareVersion));
  
                    /* BlockIdentifier: 6 - RamBlockDataAddress: &RAM_NVM_BLOCK_SerialNumberDataId */
        /* Length = 13U (Block length) */
        NVM_ASSERT_STC(13U == sizeof(RAM_NVM_BLOCK_SerialNumberDataId));
        /* BlockIdentifier: 6 - RomBlockDataAddress: &ROM_NVM_BLOCK_SerialNumberDataId */
    /* Length = 13U */
    NVM_ASSERT_STC(13U == sizeof(ROM_NVM_BLOCK_SerialNumberDataId));
  


/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

#if ( defined(NVM_MULTICORE_ENABLED) )
#define NVM_START_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#else
#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#endif
/* !LINKSTO NVM138,1, NVM143,1, NVM443,1, NVM321,1 ,NVM140,1 */
CONST(NvM_BlockDescriptorType,NVM_CONST) NvM_BlockDescriptorTable[NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS]=
{
  /** \brief  block 0:  NvM internal block, used to manage multi block requests. */
  {
    NULL_PTR,    /* initBlockCallback */
    NULL_PTR,    /* singleBlockCallback */
    NULL_PTR,    /* readRamFromNvCallback */
    NULL_PTR,    /* writeRamToNvCallback */
    NULL_PTR,    /* romBlockDataAddress */
    NULL_PTR,    /* ramBlockDataAddress */
    0U,  /* blockDesc */
    0U,  /* nvBlockLength */
    0U,  /* BlockBaseNumber */
    0U,  /* nvBlockIdentifier*/
    0xFFFFU,  /* ramBlockCrcIndex */
    0xFFFFU,  /* nvBlockCrcIndex */
    0U,   /* verifyDataSize */
    0U,  /* nvBlockNum */
    0U,  /* romBlockNum */
    0U,  /* blockJobPriority */
    0U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvMBlock_ConfigID */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &NvM_CompiledConfigurationId, /* romBlockDataAddress */
    &NvM_ConfigurationId, /* ramBlockDataAddress */
    0x0054208aU,  /* blockDesc */
    2U,  /* nvBlockLength */
    
    
    16U,  /* nvBlockBaseNumber */
    1U,   /* nvBlockIdentifier*/
    0U, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    2U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_DEM_DEFAULT */
  {
    NULL_PTR, /* initBlockCallback */
    &Dem_NvMEventStatusBlockCallback, /* singleBlockCallback */
    &Dem_NvMReadCopyEventStatusBlock, /* readRamFromNvCallback */
    &Dem_NvMWriteCopyEventStatusBlock, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    &Dem_NvData, /* ramBlockDataAddress */
    0x00462203U,  /* blockDesc */
    640U,  /* nvBlockLength */
    
    
    32U,  /* nvBlockBaseNumber */
    2U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_DEM_PRIMARY */
  {
    NULL_PTR, /* initBlockCallback */
    &Dem_NvMGateEntryPrimaryBlockCallback, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    &Dem_NvGateEntryPrimaryData, /* ramBlockDataAddress */
    0x00402103U,  /* blockDesc */
    64U,  /* nvBlockLength */
    
    
    48U,  /* nvBlockBaseNumber */
    3U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    16U, /* nvBlockNum */
    0U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_VINDataIdentifier */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_VINDataIdentifier, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_VINDataIdentifier, /* ramBlockDataAddress */
    0x00440200U,  /* blockDesc */
    17U,  /* nvBlockLength */
    
    
    64U,  /* nvBlockBaseNumber */
    4U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_ECUHardwareVersion */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_ECUHardwareVersion, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_ECUHardwareVersion, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    8U,  /* nvBlockLength */
    
    
    80U,  /* nvBlockBaseNumber */
    5U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_SerialNumberDataId */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_SerialNumberDataId, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_SerialNumberDataId, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    13U,  /* nvBlockLength */
    
    
    96U,  /* nvBlockBaseNumber */
    6U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_FAB_switch */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_FAB_switch, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_FAB_switch, /* ramBlockDataAddress */
    0x00440200U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    112U,  /* nvBlockBaseNumber */
    7U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_TSR_switch */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_TSR_switch, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_TSR_switch, /* ramBlockDataAddress */
    0x00440200U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    128U,  /* nvBlockBaseNumber */
    8U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_TLA_switch */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_TLA_switch, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_TLA_switch, /* ramBlockDataAddress */
    0x00440200U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    144U,  /* nvBlockBaseNumber */
    9U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_Security_AttemptCount */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_Security_AttemptCount, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_Security_AttemptCount, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    2U,  /* nvBlockLength */
    
    
    160U,  /* nvBlockBaseNumber */
    10U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_EOL_Info_Input */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_EOL_Info_Input, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_EOL_Info_Input, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    6U,  /* nvBlockLength */
    
    
    352U,  /* nvBlockBaseNumber */
    11U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_Block_Reserve */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00402002U,  /* blockDesc */
    4094U,  /* nvBlockLength */
    
    
    192U,  /* nvBlockBaseNumber */
    12U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    255U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_Block_PartNumer_Sector */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x02402002U,  /* blockDesc */
    4094U,  /* nvBlockLength */
    
    
    208U,  /* nvBlockBaseNumber */
    13U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    254U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_Block_Startup_Flag */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00402002U,  /* blockDesc */
    4094U,  /* nvBlockLength */
    
    
    240U,  /* nvBlockBaseNumber */
    14U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    253U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_Block_ABCheck */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00402002U,  /* blockDesc */
    4094U,  /* nvBlockLength */
    
    
    224U,  /* nvBlockBaseNumber */
    15U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    252U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_Fingerprint */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_Fingerprint, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_Fingerprint, /* ramBlockDataAddress */
    0x0044a203U,  /* blockDesc */
    7U,  /* nvBlockLength */
    
    
    256U,  /* nvBlockBaseNumber */
    16U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_Vehicletype */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_Vehicletype, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_Vehicletype, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    272U,  /* nvBlockBaseNumber */
    17U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_PCBASerialNumberDataIdentifier */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_PCBASerialNumberDataIdentifier, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    5U,  /* nvBlockLength */
    
    
    288U,  /* nvBlockBaseNumber */
    18U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    2U,  /* writeRetryLimit */
    2U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_LaneFunctionConfiguration */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_LaneFunctionConfiguration, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_LaneFunctionConfiguration, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    3U,  /* nvBlockLength */
    
    
    304U,  /* nvBlockBaseNumber */
    19U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_EOLCalibrationData */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_EOLCalibrationData, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_EOLCalibrationData, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    20U,  /* nvBlockLength */
    
    
    320U,  /* nvBlockBaseNumber */
    20U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_SDACalibrationData */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_SDACalibrationData, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_SDACalibrationData, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    336U,  /* nvBlockBaseNumber */
    21U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_EOLModeGate */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00442202U,  /* blockDesc */
    4094U,  /* nvBlockLength */
    
    
    176U,  /* nvBlockBaseNumber */
    22U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    251U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_Block_HMISwitchStatus */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_HMISwitchStatus, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_HMISwitchStatus, /* ramBlockDataAddress */
    0x01642202U,  /* blockDesc */
    7U,  /* nvBlockLength */
    
    
    368U,  /* nvBlockBaseNumber */
    23U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0U, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_FCWLastbutoneappearedFD14 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_FCWLastbutoneappearedFD14, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_FCWLastbutoneappearedFD14, /* ramBlockDataAddress */
    0x00440000U,  /* blockDesc */
    49U,  /* nvBlockLength */
    
    
    384U,  /* nvBlockBaseNumber */
    24U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_AWBLastbutoneappearFD15 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_AWBLastbutoneappearFD15, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_AWBLastbutoneappearFD15, /* ramBlockDataAddress */
    0x00440000U,  /* blockDesc */
    49U,  /* nvBlockLength */
    
    
    400U,  /* nvBlockBaseNumber */
    25U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_AEBLastbutoneappearFD16 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_AEBLastbutoneappearFD16, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_AEBLastbutoneappearFD16, /* ramBlockDataAddress */
    0x00440000U,  /* blockDesc */
    49U,  /* nvBlockLength */
    
    
    416U,  /* nvBlockBaseNumber */
    26U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_FCWLastappearFD17 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_FCWLastappearFD17, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_FCWLastappearFD17, /* ramBlockDataAddress */
    0x00440000U,  /* blockDesc */
    49U,  /* nvBlockLength */
    
    
    432U,  /* nvBlockBaseNumber */
    27U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_AWBLasteappearFD18 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_AWBLasteappearFD18, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_AWBLasteappearFD18, /* ramBlockDataAddress */
    0x00400000U,  /* blockDesc */
    49U,  /* nvBlockLength */
    
    
    448U,  /* nvBlockBaseNumber */
    28U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_AEBLastappearFD19 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* readRamFromNvCallback */
    NULL_PTR, /* writeRamToNvCallback */
    &ROM_NVM_BLOCK_AEBLastappearFD19, /* romBlockDataAddress */
    &RAM_NVM_BLOCK_AEBLastappearFD19, /* ramBlockDataAddress */
    0x00440000U,  /* blockDesc */
    49U,  /* nvBlockLength */
    
    
    464U,  /* nvBlockBaseNumber */
    29U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_BLOCK_VDYData */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    /* !LINKSTO NvM.Block.R-PortInterfacesAsrVersion.Interfaces,1 */
    /* Deviation MISRAC2012-1 */
    (NvM_NvToRamCopyCallbackType)&Rte_Call_PMirror_NvM_BLOCK_VDYData_ReadRamBlockFromNvm, /* readRamFromNvCallback */
    /* !LINKSTO NvM.Block.R-PortInterfacesAsrVersion.Interfaces,1 */
    /* Deviation MISRAC2012-1 */
    (NvM_RamToNvCopyCallbackType)&Rte_Call_PMirror_NvM_BLOCK_VDYData_WriteRamBlockToNvm, /* writeRamToNvCallback */
    &ROM_BLOCK_VDY_Data, /* romBlockDataAddress */
    &RAM_BLOCK_VDY_Data, /* ramBlockDataAddress */
    0x00460200U,  /* blockDesc */
    108U,  /* nvBlockLength */
    
    
    480U,  /* nvBlockBaseNumber */
    30U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    0U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvM_BLOCK_FS_Debug_Status */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    &Fs_NvmReadCopyBlock, /* readRamFromNvCallback */
    &Fs_NvmWriteCopyBlock, /* writeRamToNvCallback */
    NULL_PTR, /* romBlockDataAddress */
    &RAM_BLOCK_FS_DEBUG, /* ramBlockDataAddress */
    0x00420200U,  /* blockDesc */
    164U,  /* nvBlockLength */
    
    
    496U,  /* nvBlockBaseNumber */
    31U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    0xFFFFU, /* nvBlockCrcIndex */
    1U,  /* verifyDataSize */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U,  /* readRetryLimit */
  }
}; /* NvM_BlockDescriptorTable */

#if ( defined(NVM_MULTICORE_ENABLED) )
#define NVM_STOP_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#else
#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#endif /*MULTICORE ENABLED*/



#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>

#if (NVM_CANCEL_INTERNAL_JOB == STD_ON)
CONST(uint8,NVM_CONST) NvM_UsedDeviceIds[NVM_NUM_USED_DEVICES]=
{
0U,
};/*NvM_UsedDeviceIds*/
#endif /* NVM_CANCEL_INTERNAL_JOB == STD_ON */

#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>


#define NVM_START_SEC_VAR_INIT_32
#include <NvM_MemMap.h>
 
VAR(uint32,NVM_APPL_DATA) NvM_CalcCrc_CalcBuffer = (uint32)0U;

#define NVM_STOP_SEC_VAR_INIT_32
#include <NvM_MemMap.h>


#define NVM_START_SEC_CONFIG_DATA_APPL_CONST
#include <NvM_MemMap.h>
/* !LINKSTO NVM034,1 */
CONST(uint16,NVM_APPL_CONST) NvM_CompiledConfigurationId = 0x3U;



#define NVM_STOP_SEC_CONFIG_DATA_APPL_CONST
#include <NvM_MemMap.h>


/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
