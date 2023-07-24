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

#define MEMMAP_ERROR_MCU

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Mcu */

#if (defined MCU_START_SEC_CODE_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_START_SEC_CODE_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef MCU_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_STOP_SEC_CODE_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef MCU_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_STOP_SEC_CODE_ASIL_B_GLOBAL without prior opening MCU_START_SEC_CODE_ASIL_B_GLOBAL.
  #endif

#elif (defined MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined MCU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening MCU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 without prior opening MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL without prior opening MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_FAST_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL without prior opening MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16 without prior opening MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16.
  #endif

#elif (defined MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_16 without prior opening MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_16.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32 without prior opening MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32.
  #endif

#elif (defined MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_32 without prior opening MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_32.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8 without prior opening MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8.
  #endif

#elif (defined MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_CONFIG_DATA_ASIL_B_GLOBAL_8 without prior opening MCU_17_TIMERIP_START_CONFIG_DATA_ASIL_B_GLOBAL_8.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED without prior opening MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 without prior opening MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32.
  #endif

#elif (defined MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCU
    #error Tried to open section MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #endif
#elif (defined MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_MCU
  #else
    #undef MEMMAP_ERROR_MCU
    #error Tried to close section MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED without prior opening MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_MCU) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_MCU) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_MCU
  #error MEMMAP_ERROR_MCU the included memory section was not defined within the BSW-IMPLEMENTATION of Mcu.
#endif