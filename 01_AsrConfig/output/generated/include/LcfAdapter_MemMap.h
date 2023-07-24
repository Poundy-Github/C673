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

#define MEMMAP_ERROR_LCFADAPTER

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for LcfAdapter */

#if (defined LcfAdapter_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_LCFADAPTER
    #error Tried to open section LcfAdapter_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef LcfAdapter_START_SEC_CODE
    #undef MEMMAP_ERROR_LCFADAPTER
  #endif
#elif (defined LcfAdapter_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef LcfAdapter_STOP_SEC_CODE
    #undef MEMMAP_ERROR_LCFADAPTER
  #else
    #undef MEMMAP_ERROR_LCFADAPTER
    #error Tried to close section LcfAdapter_STOP_SEC_CODE without prior opening LcfAdapter_START_SEC_CODE.
  #endif

#elif (defined LcfAdapter_START_SEC_VAR_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_LCFADAPTER
    #error Tried to open section LcfAdapter_START_SEC_VAR_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef LcfAdapter_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_LCFADAPTER
  #endif
#elif (defined LcfAdapter_STOP_SEC_VAR_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef LcfAdapter_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_LCFADAPTER
  #else
    #undef MEMMAP_ERROR_LCFADAPTER
    #error Tried to close section LcfAdapter_STOP_SEC_VAR_UNSPECIFIED without prior opening LcfAdapter_START_SEC_VAR_UNSPECIFIED.
  #endif

#endif

#ifdef MEMMAP_ERROR_LCFADAPTER
  #undef MEMMAP_ERROR_LCFADAPTER
  #error MEMMAP_ERROR_LCFADAPTER the included memory section was not defined within the SWC-IMPLEMENTATION of LcfAdapter.
#endif
