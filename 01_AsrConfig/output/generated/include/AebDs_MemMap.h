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

#define MEMMAP_ERROR_AEBDS

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for AebDs */

#if (defined AebDs_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_AEBDS
    #error Tried to open section AebDs_START_SEC_CODE within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef AebDs_START_SEC_CODE
    #undef MEMMAP_ERROR_AEBDS
  #endif
#elif (defined AebDs_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef AebDs_STOP_SEC_CODE
    #undef MEMMAP_ERROR_AEBDS
  #else
    #undef MEMMAP_ERROR_AEBDS
    #error Tried to close section AebDs_STOP_SEC_CODE without prior opening AebDs_START_SEC_CODE.
  #endif

#elif (defined AebDs_START_SEC_VAR_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_AEBDS
    #error Tried to open section AebDs_START_SEC_VAR_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef AebDs_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_AEBDS
  #endif
#elif (defined AebDs_STOP_SEC_VAR_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef AebDs_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_AEBDS
  #else
    #undef MEMMAP_ERROR_AEBDS
    #error Tried to close section AebDs_STOP_SEC_VAR_UNSPECIFIED without prior opening AebDs_START_SEC_VAR_UNSPECIFIED.
  #endif

#endif

#ifdef MEMMAP_ERROR_AEBDS
  #undef MEMMAP_ERROR_AEBDS
  #error MEMMAP_ERROR_AEBDS the included memory section was not defined within the SWC-IMPLEMENTATION of AebDs.
#endif
