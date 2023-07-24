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

#define MEMMAP_ERROR_WDGIF

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for WdgIf */

#if (defined WDGIF_START_SEC_CODE_ASIL_D)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGIF
    #error Tried to open section WDGIF_START_SEC_CODE_ASIL_D within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_D
    #undef WDGIF_START_SEC_CODE_ASIL_D
    #undef MEMMAP_ERROR_WDGIF
  #endif
#elif (defined WDGIF_STOP_SEC_CODE_ASIL_D)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_D)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_D
    #undef WDGIF_STOP_SEC_CODE_ASIL_D
    #undef MEMMAP_ERROR_WDGIF
  #else
    #undef MEMMAP_ERROR_WDGIF
    #error Tried to close section WDGIF_STOP_SEC_CODE_ASIL_D without prior opening WDGIF_START_SEC_CODE_ASIL_D.
  #endif

#elif (defined WDGIF_START_SEC_CONST_ASIL_D_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_WDGIF
    #error Tried to open section WDGIF_START_SEC_CONST_ASIL_D_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_UNSPECIFIED
    #undef WDGIF_START_SEC_CONST_ASIL_D_UNSPECIFIED
    #undef MEMMAP_ERROR_WDGIF
  #endif
#elif (defined WDGIF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_D_UNSPECIFIED
    #undef WDGIF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
    #undef MEMMAP_ERROR_WDGIF
  #else
    #undef MEMMAP_ERROR_WDGIF
    #error Tried to close section WDGIF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED without prior opening WDGIF_START_SEC_CONST_ASIL_D_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_WDGIF) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_WDGIF) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_WDGIF
  #error MEMMAP_ERROR_WDGIF the included memory section was not defined within the BSW-IMPLEMENTATION of WdgIf.
#endif
