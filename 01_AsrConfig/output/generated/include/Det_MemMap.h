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

#define MEMMAP_ERROR_DET

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Det */

#if (defined DET_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DET
    #error Tried to open section DET_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef DET_START_SEC_CODE
    #undef MEMMAP_ERROR_DET
  #endif
#elif (defined DET_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef DET_STOP_SEC_CODE
    #undef MEMMAP_ERROR_DET
  #else
    #undef MEMMAP_ERROR_DET
    #error Tried to close section DET_STOP_SEC_CODE without prior opening DET_START_SEC_CODE.
  #endif

#elif (defined DET_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DET
    #error Tried to open section DET_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef DET_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_DET
  #endif
#elif (defined DET_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef DET_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_DET
  #else
    #undef MEMMAP_ERROR_DET
    #error Tried to close section DET_STOP_SEC_VAR_CLEARED_16 without prior opening DET_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined DET_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DET
    #error Tried to open section DET_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef DET_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_DET
  #endif
#elif (defined DET_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef DET_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_DET
  #else
    #undef MEMMAP_ERROR_DET
    #error Tried to close section DET_STOP_SEC_VAR_CLEARED_8 without prior opening DET_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined DET_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DET
    #error Tried to open section DET_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef DET_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_DET
  #endif
#elif (defined DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_DET
  #else
    #undef MEMMAP_ERROR_DET
    #error Tried to close section DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening DET_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined DET_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DET
    #error Tried to open section DET_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef DET_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_DET
  #endif
#elif (defined DET_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef DET_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_DET
  #else
    #undef MEMMAP_ERROR_DET
    #error Tried to close section DET_STOP_SEC_VAR_INIT_8 without prior opening DET_START_SEC_VAR_INIT_8.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_DET) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DET) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DET
  #error MEMMAP_ERROR_DET the included memory section was not defined within the BSW-IMPLEMENTATION of Det.
#endif
