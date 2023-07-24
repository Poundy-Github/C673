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

#define MEMMAP_ERROR_WDGM_1_CORE_1

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for WdgM_1_CORE_1 */

#if (defined WDGM_1_CORE_1_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef WDGM_1_CORE_1_START_SEC_CODE
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef WDGM_1_CORE_1_STOP_SEC_CODE
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_CODE without prior opening WDGM_1_CORE_1_START_SEC_CODE.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_CODE_ASIL_D)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_CODE_ASIL_D within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_D
    #undef WDGM_1_CORE_1_START_SEC_CODE_ASIL_D
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_CODE_ASIL_D)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_D)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_D
    #undef WDGM_1_CORE_1_STOP_SEC_CODE_ASIL_D
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_CODE_ASIL_D without prior opening WDGM_1_CORE_1_START_SEC_CODE_ASIL_D.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_8
    #undef WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_8
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_8
    #undef WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_8
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_8 without prior opening WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_8.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_UNSPECIFIED
    #undef WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_UNSPECIFIED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_UNSPECIFIED
    #undef WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_UNSPECIFIED without prior opening WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_UNSPECIFIED.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_D_16
    #undef WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_16
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_D_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_D_16
    #undef WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_16
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_16 without prior opening WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_16.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_D_8
    #undef WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_8
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_D_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_D_8
    #undef WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_8
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_8 without prior opening WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_8.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_D_8
    #undef WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_8
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_D_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_D_8
    #undef WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_8
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_8 without prior opening WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_8.
  #endif

#elif (defined WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to open section WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
    #undef WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #endif
#elif (defined WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
    #undef WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #else
    #undef MEMMAP_ERROR_WDGM_1_CORE_1
    #error Tried to close section WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED without prior opening WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_WDGM_1_CORE_1) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_WDGM_1_CORE_1) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_WDGM_1_CORE_1
  #error MEMMAP_ERROR_WDGM_1_CORE_1 the included memory section was not defined within the BSW-IMPLEMENTATION of WdgM_1_CORE_1.
#endif
