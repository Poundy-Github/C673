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

#define MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for BswM_1_OsApplication_C2 */

#if (defined BSWM_1_OsApplication_C2_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to open section BSWM_1_OsApplication_C2_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef BSWM_1_OsApplication_C2_START_SEC_CODE
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #endif
#elif (defined BSWM_1_OsApplication_C2_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef BSWM_1_OsApplication_C2_STOP_SEC_CODE
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #else
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to close section BSWM_1_OsApplication_C2_STOP_SEC_CODE without prior opening BSWM_1_OsApplication_C2_START_SEC_CODE.
  #endif

#elif (defined BSWM_1_OsApplication_C2_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to open section BSWM_1_OsApplication_C2_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #endif
#elif (defined BSWM_1_OsApplication_C2_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #else
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to close section BSWM_1_OsApplication_C2_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening BSWM_1_OsApplication_C2_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined BSWM_1_OsApplication_C2_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to open section BSWM_1_OsApplication_C2_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #endif
#elif (defined BSWM_1_OsApplication_C2_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #else
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to close section BSWM_1_OsApplication_C2_STOP_CONFIG_DATA_UNSPECIFIED without prior opening BSWM_1_OsApplication_C2_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined BSWM_1_OsApplication_C2_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to open section BSWM_1_OsApplication_C2_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #endif
#elif (defined BSWM_1_OsApplication_C2_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #else
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to close section BSWM_1_OsApplication_C2_STOP_SEC_CONST_UNSPECIFIED without prior opening BSWM_1_OsApplication_C2_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined BSWM_1_OsApplication_C2_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to open section BSWM_1_OsApplication_C2_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #endif
#elif (defined BSWM_1_OsApplication_C2_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #else
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to close section BSWM_1_OsApplication_C2_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening BSWM_1_OsApplication_C2_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined BSWM_1_OsApplication_C2_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to open section BSWM_1_OsApplication_C2_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #endif
#elif (defined BSWM_1_OsApplication_C2_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef BSWM_1_OsApplication_C2_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #else
    #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
    #error Tried to close section BSWM_1_OsApplication_C2_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening BSWM_1_OsApplication_C2_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2
  #error MEMMAP_ERROR_BSWM_1_OSAPPLICATION_C2 the included memory section was not defined within the BSW-IMPLEMENTATION of BswM_1_OsApplication_C2.
#endif
