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

#define MEMMAP_ERROR_PBCFGM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for PbcfgM */

#if (defined PBCFGM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef PBCFGM_START_SEC_CODE
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef PBCFGM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_SEC_CODE without prior opening PBCFGM_START_SEC_CODE.
  #endif

#elif (defined PBCFGM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef PBCFGM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef PBCFGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening PBCFGM_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined PBCFGM_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef PBCFGM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef PBCFGM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_CONFIG_DATA_UNSPECIFIED without prior opening PBCFGM_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined PBCFGM_START_SEC_CONST_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_SEC_CONST_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef PBCFGM_START_SEC_CONST_32
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_SEC_CONST_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef PBCFGM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_SEC_CONST_32 without prior opening PBCFGM_START_SEC_CONST_32.
  #endif

#elif (defined PBCFGM_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef PBCFGM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef PBCFGM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_SEC_CONST_UNSPECIFIED without prior opening PBCFGM_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined PBCFGM_START_SEC_VAR_FAST_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_SEC_VAR_FAST_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_8
    #undef PBCFGM_START_SEC_VAR_FAST_INIT_8
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_SEC_VAR_FAST_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_8
    #undef PBCFGM_STOP_SEC_VAR_FAST_INIT_8
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_SEC_VAR_FAST_INIT_8 without prior opening PBCFGM_START_SEC_VAR_FAST_INIT_8.
  #endif

#elif (defined PBCFGM_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to open section PBCFGM_START_SEC_VAR_FAST_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_UNSPECIFIED
    #undef PBCFGM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #endif
#elif (defined PBCFGM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_UNSPECIFIED
    #undef PBCFGM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_PBCFGM
  #else
    #undef MEMMAP_ERROR_PBCFGM
    #error Tried to close section PBCFGM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED without prior opening PBCFGM_START_SEC_VAR_FAST_INIT_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_PBCFGM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_PBCFGM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_PBCFGM
  #error MEMMAP_ERROR_PBCFGM the included memory section was not defined within the BSW-IMPLEMENTATION of PbcfgM.
#endif
