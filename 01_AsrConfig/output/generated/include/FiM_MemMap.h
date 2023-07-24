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

#define MEMMAP_ERROR_FIM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for FiM */

#if (defined FIM_START_SEC_CALIB_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_CALIB_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CALIB_16
    #undef FIM_START_SEC_CALIB_16
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_CALIB_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CALIB_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CALIB_16
    #undef FIM_STOP_SEC_CALIB_16
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_CALIB_16 without prior opening FIM_START_SEC_CALIB_16.
  #endif

#elif (defined FIM_START_SEC_CALIB_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_CALIB_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CALIB_8
    #undef FIM_START_SEC_CALIB_8
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_CALIB_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CALIB_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CALIB_8
    #undef FIM_STOP_SEC_CALIB_8
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_CALIB_8 without prior opening FIM_START_SEC_CALIB_8.
  #endif

#elif (defined FIM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef FIM_START_SEC_CODE
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef FIM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_CODE without prior opening FIM_START_SEC_CODE.
  #endif

#elif (defined FIM_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef FIM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef FIM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_CONST_UNSPECIFIED without prior opening FIM_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined FIM_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef FIM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef FIM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_VAR_CLEARED_8 without prior opening FIM_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined FIM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef FIM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening FIM_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined FIM_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FIM_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef FIM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FIM_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef FIM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FIM_STOP_SEC_VAR_INIT_8 without prior opening FIM_START_SEC_VAR_INIT_8.
  #endif

#elif (defined FiM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FIM
    #error Tried to open section FiM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef FiM_START_SEC_CODE
    #undef MEMMAP_ERROR_FIM
  #endif
#elif (defined FiM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef FiM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_FIM
  #else
    #undef MEMMAP_ERROR_FIM
    #error Tried to close section FiM_STOP_SEC_CODE without prior opening FiM_START_SEC_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_FIM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FIM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FIM
  #error MEMMAP_ERROR_FIM the included memory section was not defined within the BSW-IMPLEMENTATION or SWC-IMPLEMENTATION of FiM.
#endif
