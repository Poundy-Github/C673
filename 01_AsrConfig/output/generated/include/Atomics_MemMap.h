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

#define MEMMAP_ERROR_ATOMICS

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Atomics */

#if (defined ATOMICS_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ATOMICS
    #error Tried to open section ATOMICS_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ATOMICS_START_SEC_CODE
    #undef MEMMAP_ERROR_ATOMICS
  #endif
#elif (defined ATOMICS_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef ATOMICS_STOP_SEC_CODE
    #undef MEMMAP_ERROR_ATOMICS
  #else
    #undef MEMMAP_ERROR_ATOMICS
    #error Tried to close section ATOMICS_STOP_SEC_CODE without prior opening ATOMICS_START_SEC_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_ATOMICS) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_ATOMICS) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_ATOMICS
  #error MEMMAP_ERROR_ATOMICS the included memory section was not defined within the BSW-IMPLEMENTATION of Atomics.
#endif
