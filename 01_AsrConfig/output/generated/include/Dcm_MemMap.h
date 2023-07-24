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

#define MEMMAP_ERROR_DCM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Dcm */

#if (defined DCM_START_SEC_CALIB_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CALIB_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CALIB_8
    #undef DCM_START_SEC_CALIB_8
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CALIB_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CALIB_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CALIB_8
    #undef DCM_STOP_SEC_CALIB_8
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CALIB_8 without prior opening DCM_START_SEC_CALIB_8.
  #endif

#elif (defined DCM_START_SEC_CALLOUT_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CALLOUT_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CALLOUT_CODE
    #undef DCM_START_SEC_CALLOUT_CODE
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CALLOUT_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CALLOUT_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CALLOUT_CODE
    #undef DCM_STOP_SEC_CALLOUT_CODE
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CALLOUT_CODE without prior opening DCM_START_SEC_CALLOUT_CODE.
  #endif

#elif (defined DCM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef DCM_START_SEC_CODE
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef DCM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CODE without prior opening DCM_START_SEC_CODE.
  #endif

#elif (defined DCM_START_SEC_CONST_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CONST_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef DCM_START_SEC_CONST_16
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CONST_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef DCM_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CONST_16 without prior opening DCM_START_SEC_CONST_16.
  #endif

#elif (defined DCM_START_SEC_CONST_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CONST_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef DCM_START_SEC_CONST_32
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CONST_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef DCM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CONST_32 without prior opening DCM_START_SEC_CONST_32.
  #endif

#elif (defined DCM_START_SEC_CONST_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CONST_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef DCM_START_SEC_CONST_8
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CONST_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef DCM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CONST_8 without prior opening DCM_START_SEC_CONST_8.
  #endif

#elif (defined DCM_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef DCM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef DCM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_CONST_UNSPECIFIED without prior opening DCM_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined DCM_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef DCM_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef DCM_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_CLEARED_16 without prior opening DCM_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined DCM_START_SEC_VAR_CLEARED_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_CLEARED_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32
    #undef DCM_START_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_CLEARED_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32
    #undef DCM_STOP_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_CLEARED_32 without prior opening DCM_START_SEC_VAR_CLEARED_32.
  #endif

#elif (defined DCM_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef DCM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef DCM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_CLEARED_8 without prior opening DCM_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined DCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening DCM_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined DCM_START_SEC_VAR_INIT_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_INIT_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16
    #undef DCM_START_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_INIT_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_16
    #undef DCM_STOP_SEC_VAR_INIT_16
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_INIT_16 without prior opening DCM_START_SEC_VAR_INIT_16.
  #endif

#elif (defined DCM_START_SEC_VAR_INIT_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_INIT_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32
    #undef DCM_START_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_INIT_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32
    #undef DCM_STOP_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_INIT_32 without prior opening DCM_START_SEC_VAR_INIT_32.
  #endif

#elif (defined DCM_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef DCM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef DCM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_INIT_8 without prior opening DCM_START_SEC_VAR_INIT_8.
  #endif

#elif (defined DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef DCM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening DCM_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#elif (defined DCM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section DCM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef DCM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined DCM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef DCM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section DCM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED without prior opening DCM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED.
  #endif

#elif (defined Dcm_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DCM
    #error Tried to open section Dcm_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Dcm_START_SEC_CODE
    #undef MEMMAP_ERROR_DCM
  #endif
#elif (defined Dcm_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Dcm_STOP_SEC_CODE
    #undef MEMMAP_ERROR_DCM
  #else
    #undef MEMMAP_ERROR_DCM
    #error Tried to close section Dcm_STOP_SEC_CODE without prior opening Dcm_START_SEC_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_DCM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DCM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DCM
  #error MEMMAP_ERROR_DCM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of Dcm.
#endif
