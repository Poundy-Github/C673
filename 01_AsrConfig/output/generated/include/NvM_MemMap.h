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

#define MEMMAP_ERROR_NVM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for NvM */

#if (defined NVM_START_SEC_ADMINBLOCK_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_ADMINBLOCK_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_ADMINBLOCK_UNSPECIFIED
    #undef NVM_START_SEC_ADMINBLOCK_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_ADMINBLOCK_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_ADMINBLOCK_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_ADMINBLOCK_UNSPECIFIED
    #undef NVM_STOP_SEC_ADMINBLOCK_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_ADMINBLOCK_UNSPECIFIED without prior opening NVM_START_SEC_ADMINBLOCK_UNSPECIFIED.
  #endif

#elif (defined NVM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef NVM_START_SEC_CODE
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef NVM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_CODE without prior opening NVM_START_SEC_CODE.
  #endif

#elif (defined NVM_START_SEC_CONFIG_DATA_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_CONFIG_DATA_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_16
    #undef NVM_START_SEC_CONFIG_DATA_16
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_CONFIG_DATA_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_16
    #undef NVM_STOP_SEC_CONFIG_DATA_16
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_CONFIG_DATA_16 without prior opening NVM_START_SEC_CONFIG_DATA_16.
  #endif

#elif (defined NVM_START_CONFIG_DATA_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_CONFIG_DATA_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_16
    #undef NVM_START_CONFIG_DATA_16
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_CONFIG_DATA_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_16
    #undef NVM_STOP_CONFIG_DATA_16
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_CONFIG_DATA_16 without prior opening NVM_START_CONFIG_DATA_16.
  #endif

#elif (defined NVM_START_SEC_CONFIG_DATA_APPL_CONST)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_CONFIG_DATA_APPL_CONST within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_APPL_CONST
    #undef NVM_START_SEC_CONFIG_DATA_APPL_CONST
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_CONFIG_DATA_APPL_CONST)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_APPL_CONST)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_APPL_CONST
    #undef NVM_STOP_SEC_CONFIG_DATA_APPL_CONST
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_CONFIG_DATA_APPL_CONST without prior opening NVM_START_SEC_CONFIG_DATA_APPL_CONST.
  #endif

#elif (defined NVM_START_CONFIG_DATA_APPL_CONST)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_CONFIG_DATA_APPL_CONST within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_APPL_CONST
    #undef NVM_START_CONFIG_DATA_APPL_CONST
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_CONFIG_DATA_APPL_CONST)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_APPL_CONST)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_APPL_CONST
    #undef NVM_STOP_CONFIG_DATA_APPL_CONST
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_CONFIG_DATA_APPL_CONST without prior opening NVM_START_CONFIG_DATA_APPL_CONST.
  #endif

#elif (defined NVM_START_SEC_CONFIG_DATA_APPL_DATA)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_CONFIG_DATA_APPL_DATA within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_APPL_DATA
    #undef NVM_START_SEC_CONFIG_DATA_APPL_DATA
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_CONFIG_DATA_APPL_DATA)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_APPL_DATA)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_APPL_DATA
    #undef NVM_STOP_SEC_CONFIG_DATA_APPL_DATA
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_CONFIG_DATA_APPL_DATA without prior opening NVM_START_SEC_CONFIG_DATA_APPL_DATA.
  #endif

#elif (defined NVM_START_CONFIG_DATA_APPL_DATA)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_CONFIG_DATA_APPL_DATA within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_APPL_DATA
    #undef NVM_START_CONFIG_DATA_APPL_DATA
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_CONFIG_DATA_APPL_DATA)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_APPL_DATA)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_APPL_DATA
    #undef NVM_STOP_CONFIG_DATA_APPL_DATA
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_CONFIG_DATA_APPL_DATA without prior opening NVM_START_CONFIG_DATA_APPL_DATA.
  #endif

#elif (defined NVM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening NVM_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined NVM_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef NVM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef NVM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_CONFIG_DATA_UNSPECIFIED without prior opening NVM_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined NVM_START_SEC_MC_SHARED_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_MC_SHARED_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_CODE
    #undef NVM_START_SEC_MC_SHARED_CODE
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_MC_SHARED_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_CODE
    #undef NVM_STOP_SEC_MC_SHARED_CODE
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_MC_SHARED_CODE without prior opening NVM_START_SEC_MC_SHARED_CODE.
  #endif

#elif (defined NVM_START_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
    #undef NVM_START_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
    #undef NVM_STOP_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED without prior opening NVM_START_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined NVM_START_SEC_MC_SHARED_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_MC_SHARED_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_CLEARED_16
    #undef NVM_START_SEC_MC_SHARED_VAR_CLEARED_16
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_MC_SHARED_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_CLEARED_16
    #undef NVM_STOP_SEC_MC_SHARED_VAR_CLEARED_16
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_MC_SHARED_VAR_CLEARED_16 without prior opening NVM_START_SEC_MC_SHARED_VAR_CLEARED_16.
  #endif

#elif (defined NVM_START_SEC_MC_SHARED_VAR_INIT_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_MC_SHARED_VAR_INIT_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_INIT_16
    #undef NVM_START_SEC_MC_SHARED_VAR_INIT_16
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_MC_SHARED_VAR_INIT_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_INIT_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_INIT_16
    #undef NVM_STOP_SEC_MC_SHARED_VAR_INIT_16
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_MC_SHARED_VAR_INIT_16 without prior opening NVM_START_SEC_MC_SHARED_VAR_INIT_16.
  #endif

#elif (defined NVM_START_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_START_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED without prior opening NVM_START_SEC_MC_SHARED_VAR_POWER_ON_INIT_UNSPECIFIED.
  #endif

#elif (defined NVM_START_SEC_VAR_APPL_DATA)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_APPL_DATA within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_APPL_DATA
    #undef NVM_START_SEC_VAR_APPL_DATA
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_APPL_DATA)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_APPL_DATA)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_APPL_DATA
    #undef NVM_STOP_SEC_VAR_APPL_DATA
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_APPL_DATA without prior opening NVM_START_SEC_VAR_APPL_DATA.
  #endif

#elif (defined NVM_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef NVM_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef NVM_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_CLEARED_16 without prior opening NVM_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined NVM_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef NVM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef NVM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_CLEARED_8 without prior opening NVM_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined NVM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening NVM_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined NVM_START_SEC_VAR_INIT_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_INIT_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16
    #undef NVM_START_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_INIT_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16
    #undef NVM_STOP_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_INIT_16 without prior opening NVM_START_SEC_VAR_INIT_16.
  #endif

#elif (defined NVM_START_SEC_VAR_INIT_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_INIT_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32
    #undef NVM_START_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_INIT_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32
    #undef NVM_STOP_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_INIT_32 without prior opening NVM_START_SEC_VAR_INIT_32.
  #endif

#elif (defined NVM_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef NVM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef NVM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_INIT_8 without prior opening NVM_START_SEC_VAR_INIT_8.
  #endif

#elif (defined NVM_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening NVM_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#elif (defined NVM_START_SEC_VAR_POWER_ON_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NVM_START_SEC_VAR_POWER_ON_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_INIT_8
    #undef NVM_START_SEC_VAR_POWER_ON_INIT_8
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NVM_STOP_SEC_VAR_POWER_ON_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_INIT_8
    #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_8
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NVM_STOP_SEC_VAR_POWER_ON_INIT_8 without prior opening NVM_START_SEC_VAR_POWER_ON_INIT_8.
  #endif

#elif (defined NvM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_NVM
    #error Tried to open section NvM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef NvM_START_SEC_CODE
    #undef MEMMAP_ERROR_NVM
  #endif
#elif (defined NvM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef NvM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_NVM
  #else
    #undef MEMMAP_ERROR_NVM
    #error Tried to close section NvM_STOP_SEC_CODE without prior opening NvM_START_SEC_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_NVM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_NVM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_NVM
  #error MEMMAP_ERROR_NVM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of NvM.
#endif
