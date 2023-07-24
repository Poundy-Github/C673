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

#define MEMMAP_ERROR_ESM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Esm */

#if (defined Esm_START_SEC_CALIB)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ESM
    #error Tried to open section Esm_START_SEC_CALIB within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CALIB
    #undef Esm_START_SEC_CALIB
    #undef MEMMAP_ERROR_ESM
  #endif
#elif (defined Esm_STOP_SEC_CALIB)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CALIB)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CALIB
    #undef Esm_STOP_SEC_CALIB
    #undef MEMMAP_ERROR_ESM
  #else
    #undef MEMMAP_ERROR_ESM
    #error Tried to close section Esm_STOP_SEC_CALIB without prior opening Esm_START_SEC_CALIB.
  #endif

#elif (defined Esm_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ESM
    #error Tried to open section Esm_START_SEC_CODE within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Esm_START_SEC_CODE
    #undef MEMMAP_ERROR_ESM
  #endif
#elif (defined Esm_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef Esm_STOP_SEC_CODE
    #undef MEMMAP_ERROR_ESM
  #else
    #undef MEMMAP_ERROR_ESM
    #error Tried to close section Esm_STOP_SEC_CODE without prior opening Esm_START_SEC_CODE.
  #endif

#elif (defined Esm_START_SEC_CODE_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ESM
    #error Tried to open section Esm_START_SEC_CODE_LOCAL within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL
    #undef Esm_START_SEC_CODE_LOCAL
    #undef MEMMAP_ERROR_ESM
  #endif
#elif (defined Esm_STOP_SEC_CODE_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL
    #undef Esm_STOP_SEC_CODE_LOCAL
    #undef MEMMAP_ERROR_ESM
  #else
    #undef MEMMAP_ERROR_ESM
    #error Tried to close section Esm_STOP_SEC_CODE_LOCAL without prior opening Esm_START_SEC_CODE_LOCAL.
  #endif

#elif (defined Esm_START_SEC_VAR_INIT_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_ESM
    #error Tried to open section Esm_START_SEC_VAR_INIT_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL
    #undef Esm_START_SEC_VAR_INIT_LOCAL
    #undef MEMMAP_ERROR_ESM
  #endif
#elif (defined Esm_STOP_SEC_VAR_INIT_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL
    #undef Esm_STOP_SEC_VAR_INIT_LOCAL
    #undef MEMMAP_ERROR_ESM
  #else
    #undef MEMMAP_ERROR_ESM
    #error Tried to close section Esm_STOP_SEC_VAR_INIT_LOCAL without prior opening Esm_START_SEC_VAR_INIT_LOCAL.
  #endif

#endif

#ifdef MEMMAP_ERROR_ESM
  #undef MEMMAP_ERROR_ESM
  #error MEMMAP_ERROR_ESM the included memory section was not defined within the SWC-IMPLEMENTATION of Esm.
#endif
