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

#define MEMMAP_ERROR_CANNM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for CanNm */

#if (defined CANNM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CANNM_START_SEC_CODE
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CANNM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_CODE without prior opening CANNM_START_SEC_CODE.
  #endif

#elif (defined CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined CANNM_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef CANNM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef CANNM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_CONFIG_DATA_UNSPECIFIED without prior opening CANNM_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined CANNM_START_SEC_CONST_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_CONST_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef CANNM_START_SEC_CONST_32
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_CONST_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef CANNM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_CONST_32 without prior opening CANNM_START_SEC_CONST_32.
  #endif

#elif (defined CANNM_START_SEC_CONST_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_CONST_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef CANNM_START_SEC_CONST_8
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_CONST_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef CANNM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_CONST_8 without prior opening CANNM_START_SEC_CONST_8.
  #endif

#elif (defined CANNM_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef CANNM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef CANNM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_CONST_UNSPECIFIED without prior opening CANNM_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined CANNM_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef CANNM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef CANNM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_VAR_CLEARED_8 without prior opening CANNM_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined CANNM_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef CANNM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef CANNM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_VAR_INIT_8 without prior opening CANNM_START_SEC_VAR_INIT_8.
  #endif

#elif (defined CANNM_START_SEC_VAR_INIT_BOOLEAN)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_VAR_INIT_BOOLEAN within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_BOOLEAN
    #undef CANNM_START_SEC_VAR_INIT_BOOLEAN
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_VAR_INIT_BOOLEAN)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_BOOLEAN)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_BOOLEAN
    #undef CANNM_STOP_SEC_VAR_INIT_BOOLEAN
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_VAR_INIT_BOOLEAN without prior opening CANNM_START_SEC_VAR_INIT_BOOLEAN.
  #endif

#elif (defined CANNM_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANNM
    #error Tried to open section CANNM_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #endif
#elif (defined CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CANNM
  #else
    #undef MEMMAP_ERROR_CANNM
    #error Tried to close section CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening CANNM_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_CANNM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CANNM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CANNM
  #error MEMMAP_ERROR_CANNM the included memory section was not defined within the BSW-IMPLEMENTATION of CanNm.
#endif
