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

#define MEMMAP_ERROR_COMM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for ComM */

#if (defined COMM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef COMM_START_SEC_CODE
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef COMM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_CODE without prior opening COMM_START_SEC_CODE.
  #endif

#elif (defined COMM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening COMM_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined COMM_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef COMM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef COMM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_CONFIG_DATA_UNSPECIFIED without prior opening COMM_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined COMM_START_SEC_CONST_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_CONST_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef COMM_START_SEC_CONST_16
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_CONST_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef COMM_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_CONST_16 without prior opening COMM_START_SEC_CONST_16.
  #endif

#elif (defined COMM_START_SEC_CONST_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_CONST_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef COMM_START_SEC_CONST_32
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_CONST_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef COMM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_CONST_32 without prior opening COMM_START_SEC_CONST_32.
  #endif

#elif (defined COMM_START_SEC_CONST_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_CONST_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef COMM_START_SEC_CONST_8
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_CONST_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef COMM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_CONST_8 without prior opening COMM_START_SEC_CONST_8.
  #endif

#elif (defined COMM_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef COMM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef COMM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_CONST_UNSPECIFIED without prior opening COMM_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined COMM_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef COMM_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef COMM_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_CLEARED_16 without prior opening COMM_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined COMM_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef COMM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef COMM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_CLEARED_8 without prior opening COMM_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined COMM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening COMM_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined COMM_START_SEC_VAR_INIT_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_INIT_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16
    #undef COMM_START_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_INIT_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16
    #undef COMM_STOP_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_INIT_16 without prior opening COMM_START_SEC_VAR_INIT_16.
  #endif

#elif (defined COMM_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef COMM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef COMM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_INIT_8 without prior opening COMM_START_SEC_VAR_INIT_8.
  #endif

#elif (defined COMM_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef COMM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening COMM_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#elif (defined COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED without prior opening COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED.
  #endif

#elif (defined ComM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COMM
    #error Tried to open section ComM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ComM_START_SEC_CODE
    #undef MEMMAP_ERROR_COMM
  #endif
#elif (defined ComM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ComM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_COMM
  #else
    #undef MEMMAP_ERROR_COMM
    #error Tried to close section ComM_STOP_SEC_CODE without prior opening ComM_START_SEC_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_COMM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_COMM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_COMM
  #error MEMMAP_ERROR_COMM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of ComM.
#endif
