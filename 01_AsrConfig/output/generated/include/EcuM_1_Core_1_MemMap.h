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

#define MEMMAP_ERROR_ECUM_1_CORE_1

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for EcuM_1_Core_1 */

#if (defined ECUM_1_Core_1_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ECUM_1_Core_1_START_SEC_CODE
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ECUM_1_Core_1_STOP_SEC_CODE
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_CODE without prior opening ECUM_1_Core_1_START_SEC_CODE.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_CONST_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_CONST_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef ECUM_1_Core_1_START_SEC_CONST_16
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_CONST_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef ECUM_1_Core_1_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_CONST_16 without prior opening ECUM_1_Core_1_START_SEC_CONST_16.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_CONST_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_CONST_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef ECUM_1_Core_1_START_SEC_CONST_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_CONST_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef ECUM_1_Core_1_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_CONST_8 without prior opening ECUM_1_Core_1_START_SEC_CONST_8.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef ECUM_1_Core_1_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef ECUM_1_Core_1_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_CONST_UNSPECIFIED without prior opening ECUM_1_Core_1_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef ECUM_1_Core_1_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef ECUM_1_Core_1_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED without prior opening ECUM_1_Core_1_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef ECUM_1_Core_1_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_16 without prior opening ECUM_1_Core_1_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef ECUM_1_Core_1_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_8 without prior opening ECUM_1_Core_1_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef ECUM_1_Core_1_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening ECUM_1_Core_1_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef ECUM_1_Core_1_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef ECUM_1_Core_1_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_VAR_INIT_8 without prior opening ECUM_1_Core_1_START_SEC_VAR_INIT_8.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef ECUM_1_Core_1_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef ECUM_1_Core_1_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening ECUM_1_Core_1_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#elif (defined ECUM_1_Core_1_START_SEC_VAR_POWER_ON_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to open section ECUM_1_Core_1_START_SEC_VAR_POWER_ON_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_INIT_8
    #undef ECUM_1_Core_1_START_SEC_VAR_POWER_ON_INIT_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #endif
#elif (defined ECUM_1_Core_1_STOP_SEC_VAR_POWER_ON_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_INIT_8
    #undef ECUM_1_Core_1_STOP_SEC_VAR_POWER_ON_INIT_8
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_ECUM_1_CORE_1
    #error Tried to close section ECUM_1_Core_1_STOP_SEC_VAR_POWER_ON_INIT_8 without prior opening ECUM_1_Core_1_START_SEC_VAR_POWER_ON_INIT_8.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_ECUM_1_CORE_1) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_ECUM_1_CORE_1) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_ECUM_1_CORE_1
  #error MEMMAP_ERROR_ECUM_1_CORE_1 the included memory section was not defined within the BSW-IMPLEMENTATION of EcuM_1_Core_1.
#endif
