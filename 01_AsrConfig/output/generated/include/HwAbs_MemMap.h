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

#define MEMMAP_ERROR_HWABS

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for HwAbs */

#if (defined HwAbs_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_HWABS
    #error Tried to open section HwAbs_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef HwAbs_START_SEC_CODE
    #undef MEMMAP_ERROR_HWABS
  #endif
#elif (defined HwAbs_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef HwAbs_STOP_SEC_CODE
    #undef MEMMAP_ERROR_HWABS
  #else
    #undef MEMMAP_ERROR_HWABS
    #error Tried to close section HwAbs_STOP_SEC_CODE without prior opening HwAbs_START_SEC_CODE.
  #endif

#elif (defined HwAbs_START_SEC_VAR_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_HWABS
    #error Tried to open section HwAbs_START_SEC_VAR_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef HwAbs_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_HWABS
  #endif
#elif (defined HwAbs_STOP_SEC_VAR_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef HwAbs_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_HWABS
  #else
    #undef MEMMAP_ERROR_HWABS
    #error Tried to close section HwAbs_STOP_SEC_VAR_UNSPECIFIED without prior opening HwAbs_START_SEC_VAR_UNSPECIFIED.
  #endif

#endif

#ifdef MEMMAP_ERROR_HWABS
  #undef MEMMAP_ERROR_HWABS
  #error MEMMAP_ERROR_HWABS the included memory section was not defined within the SWC-IMPLEMENTATION of HwAbs.
#endif
