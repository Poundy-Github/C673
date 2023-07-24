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

#define MEMMAP_ERROR_DEVELOPMENTERRORTRACER

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for DevelopmentErrorTracer */

#if (defined DevelopmentErrorTracer_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DEVELOPMENTERRORTRACER
    #error Tried to open section DevelopmentErrorTracer_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef DevelopmentErrorTracer_START_SEC_CODE
    #undef MEMMAP_ERROR_DEVELOPMENTERRORTRACER
  #endif
#elif (defined DevelopmentErrorTracer_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef DevelopmentErrorTracer_STOP_SEC_CODE
    #undef MEMMAP_ERROR_DEVELOPMENTERRORTRACER
  #else
    #undef MEMMAP_ERROR_DEVELOPMENTERRORTRACER
    #error Tried to close section DevelopmentErrorTracer_STOP_SEC_CODE without prior opening DevelopmentErrorTracer_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_DEVELOPMENTERRORTRACER
  #undef MEMMAP_ERROR_DEVELOPMENTERRORTRACER
  #error MEMMAP_ERROR_DEVELOPMENTERRORTRACER the included memory section was not defined within the SWC-IMPLEMENTATION of DevelopmentErrorTracer.
#endif
