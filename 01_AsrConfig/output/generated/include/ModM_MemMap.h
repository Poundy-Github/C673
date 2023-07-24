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

#define MEMMAP_ERROR_MODM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for ModM */

#if (defined ModM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MODM
    #error Tried to open section ModM_START_SEC_CODE within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ModM_START_SEC_CODE
    #undef MEMMAP_ERROR_MODM
  #endif
#elif (defined ModM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ModM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_MODM
  #else
    #undef MEMMAP_ERROR_MODM
    #error Tried to close section ModM_STOP_SEC_CODE without prior opening ModM_START_SEC_CODE.
  #endif

#elif (defined ModM_START_SEC_CODE_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MODM
    #error Tried to open section ModM_START_SEC_CODE_LOCAL within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL
    #undef ModM_START_SEC_CODE_LOCAL
    #undef MEMMAP_ERROR_MODM
  #endif
#elif (defined ModM_STOP_SEC_CODE_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL
    #undef ModM_STOP_SEC_CODE_LOCAL
    #undef MEMMAP_ERROR_MODM
  #else
    #undef MEMMAP_ERROR_MODM
    #error Tried to close section ModM_STOP_SEC_CODE_LOCAL without prior opening ModM_START_SEC_CODE_LOCAL.
  #endif

#elif (defined ModM_START_SEC_CONST)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MODM
    #error Tried to open section ModM_START_SEC_CONST within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST
    #undef ModM_START_SEC_CONST
    #undef MEMMAP_ERROR_MODM
  #endif
#elif (defined ModM_STOP_SEC_CONST)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST
    #undef ModM_STOP_SEC_CONST
    #undef MEMMAP_ERROR_MODM
  #else
    #undef MEMMAP_ERROR_MODM
    #error Tried to close section ModM_STOP_SEC_CONST without prior opening ModM_START_SEC_CONST.
  #endif

#elif (defined ModM_START_SEC_VAR_CLEARED_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MODM
    #error Tried to open section ModM_START_SEC_VAR_CLEARED_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_LOCAL
    #undef ModM_START_SEC_VAR_CLEARED_LOCAL
    #undef MEMMAP_ERROR_MODM
  #endif
#elif (defined ModM_STOP_SEC_VAR_CLEARED_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_LOCAL
    #undef ModM_STOP_SEC_VAR_CLEARED_LOCAL
    #undef MEMMAP_ERROR_MODM
  #else
    #undef MEMMAP_ERROR_MODM
    #error Tried to close section ModM_STOP_SEC_VAR_CLEARED_LOCAL without prior opening ModM_START_SEC_VAR_CLEARED_LOCAL.
  #endif

#elif (defined ModM_START_SEC_VAR_INIT_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MODM
    #error Tried to open section ModM_START_SEC_VAR_INIT_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL
    #undef ModM_START_SEC_VAR_INIT_LOCAL
    #undef MEMMAP_ERROR_MODM
  #endif
#elif (defined ModM_STOP_SEC_VAR_INIT_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL
    #undef ModM_STOP_SEC_VAR_INIT_LOCAL
    #undef MEMMAP_ERROR_MODM
  #else
    #undef MEMMAP_ERROR_MODM
    #error Tried to close section ModM_STOP_SEC_VAR_INIT_LOCAL without prior opening ModM_START_SEC_VAR_INIT_LOCAL.
  #endif

#endif

#ifdef MEMMAP_ERROR_MODM
  #undef MEMMAP_ERROR_MODM
  #error MEMMAP_ERROR_MODM the included memory section was not defined within the SWC-IMPLEMENTATION of ModM.
#endif
