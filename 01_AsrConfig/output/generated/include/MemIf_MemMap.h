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

#define MEMMAP_ERROR_MEMIF

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for MemIf */

#if (defined MEMIF_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MEMIF
    #error Tried to open section MEMIF_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef MEMIF_START_SEC_CODE
    #undef MEMMAP_ERROR_MEMIF
  #endif
#elif (defined MEMIF_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #undef MEMMAP_ERROR_MEMIF
  #else
    #undef MEMMAP_ERROR_MEMIF
    #error Tried to close section MEMIF_STOP_SEC_CODE without prior opening MEMIF_START_SEC_CODE.
  #endif

#elif (defined MEMIF_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MEMIF
    #error Tried to open section MEMIF_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef MEMIF_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_MEMIF
  #endif
#elif (defined MEMIF_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef MEMIF_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_MEMIF
  #else
    #undef MEMMAP_ERROR_MEMIF
    #error Tried to close section MEMIF_STOP_SEC_CONST_UNSPECIFIED without prior opening MEMIF_START_SEC_CONST_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_MEMIF) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_MEMIF) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_MEMIF
  #error MEMMAP_ERROR_MEMIF the included memory section was not defined within the BSW-IMPLEMENTATION of MemIf.
#endif
