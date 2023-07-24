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

#define MEMMAP_ERROR_BASE

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Base */

#if (defined BASE_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_BASE
    #error Tried to open section BASE_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef BASE_START_SEC_CODE
    #undef MEMMAP_ERROR_BASE
  #endif
#elif (defined BASE_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef BASE_STOP_SEC_CODE
    #undef MEMMAP_ERROR_BASE
  #else
    #undef MEMMAP_ERROR_BASE
    #error Tried to close section BASE_STOP_SEC_CODE without prior opening BASE_START_SEC_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_BASE) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_BASE) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_BASE
  #error MEMMAP_ERROR_BASE the included memory section was not defined within the BSW-IMPLEMENTATION of Base.
#endif
