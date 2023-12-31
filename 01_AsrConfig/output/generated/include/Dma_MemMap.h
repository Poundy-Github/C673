/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_DMA

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Dma */

#if (defined DMA_START_SEC_CODE_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CODE_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef DMA_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CODE_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef DMA_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CODE_ASIL_B_GLOBAL without prior opening DMA_START_SEC_CODE_ASIL_B_GLOBAL.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE0_256
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE0_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE0_256
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256 without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE0_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE0_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE0_256
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE0_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE0_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE0_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE0_256
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE0_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE0_256 without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE0_256.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE1_256
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE1_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE1_256
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_256 without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_256.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE1_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE1_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE1_256
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE1_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE1_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE1_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE1_256
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE1_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE1_256 without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE1_256.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE2_256
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE2_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE2_256
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_256 without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_256.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE2_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE2_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE2_256
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE2_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE2_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE2_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE2_256
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE2_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE2_256 without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE2_256.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE3_256
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE3_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE3_256
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_256 without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_256.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE3_256)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE3_256 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE3_256
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE3_256
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE3_256)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE3_256)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE3_256
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE3_256
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE3_256 without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE3_256.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef DMA_START_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED without prior opening DMA_START_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED.
  #endif

#elif (defined DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined DMA_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DMA_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DMA_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening DMA_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined DMA_START_SEC_CONST_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_CONST_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32
    #undef DMA_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32
    #undef DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32 without prior opening DMA_START_SEC_CONST_ASIL_B_GLOBAL_32.
  #endif

#elif (defined DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE0_8
    #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE0_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE0_8
    #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8 without prior opening DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8.
  #endif

#elif (defined DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE1_8
    #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE1_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE1_8
    #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8 without prior opening DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8.
  #endif

#elif (defined DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE2_8
    #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE2_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE2_8
    #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8 without prior opening DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8.
  #endif

#elif (defined DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE3_8
    #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE3_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_CORE3_8
    #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8 without prior opening DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8.
  #endif

#elif (defined DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 without prior opening DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32.
  #endif

#elif (defined DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DMA
    #error Tried to open section DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_DMA
  #endif
#elif (defined DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_DMA
  #else
    #undef MEMMAP_ERROR_DMA
    #error Tried to close section DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 without prior opening DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_DMA) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DMA) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DMA
  #error MEMMAP_ERROR_DMA the included memory section was not defined within the BSW-IMPLEMENTATION of Dma.
#endif
