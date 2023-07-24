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

#define MEMMAP_ERROR_ECUC

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for EcuC */

#if (defined ECUC_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUC
    #error Tried to open section ECUC_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ECUC_START_SEC_CODE
    #undef MEMMAP_ERROR_ECUC
  #endif
#elif (defined ECUC_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ECUC_STOP_SEC_CODE
    #undef MEMMAP_ERROR_ECUC
  #else
    #undef MEMMAP_ERROR_ECUC
    #error Tried to close section ECUC_STOP_SEC_CODE without prior opening ECUC_START_SEC_CODE.
  #endif

#elif (defined ECUC_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUC
    #error Tried to open section ECUC_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef ECUC_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUC
  #endif
#elif (defined ECUC_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef ECUC_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUC
  #else
    #undef MEMMAP_ERROR_ECUC
    #error Tried to close section ECUC_STOP_SEC_CONST_UNSPECIFIED without prior opening ECUC_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined ECUC_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ECUC
    #error Tried to open section ECUC_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef ECUC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUC
  #endif
#elif (defined ECUC_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef ECUC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_ECUC
  #else
    #undef MEMMAP_ERROR_ECUC
    #error Tried to close section ECUC_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening ECUC_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_ECUC) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_ECUC) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_ECUC
  #error MEMMAP_ERROR_ECUC the included memory section was not defined within the BSW-IMPLEMENTATION of EcuC.
#endif
