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

#define MEMMAP_ERROR_MCALLIB

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for McalLib */

#if (defined MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to open section MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCALLIB
  #endif
#elif (defined MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_MCALLIB
  #else
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to close section MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL without prior opening MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL.
  #endif

#elif (defined MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to open section MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32
    #undef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCALLIB
  #endif
#elif (defined MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32
    #undef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCALLIB
  #else
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to close section MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32 without prior opening MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32.
  #endif

#elif (defined MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to open section MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_8
    #undef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_MCALLIB
  #endif
#elif (defined MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_8
    #undef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8
    #undef MEMMAP_ERROR_MCALLIB
  #else
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to close section MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8 without prior opening MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8.
  #endif

#elif (defined MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to open section MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCALLIB
  #endif
#elif (defined MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_MCALLIB
  #else
    #undef MEMMAP_ERROR_MCALLIB
    #error Tried to close section MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 without prior opening MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_MCALLIB) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_MCALLIB) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_MCALLIB
  #error MEMMAP_ERROR_MCALLIB the included memory section was not defined within the BSW-IMPLEMENTATION of McalLib.
#endif
