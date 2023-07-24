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

#define MEMMAP_ERROR_VOLTMONI

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for VoltMonI */

#if (defined VoltMonI_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to open section VoltMonI_START_SEC_CODE within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef VoltMonI_START_SEC_CODE
    #undef MEMMAP_ERROR_VOLTMONI
  #endif
#elif (defined VoltMonI_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef VoltMonI_STOP_SEC_CODE
    #undef MEMMAP_ERROR_VOLTMONI
  #else
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to close section VoltMonI_STOP_SEC_CODE without prior opening VoltMonI_START_SEC_CODE.
  #endif

#elif (defined VoltMonI_START_SEC_CODE_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to open section VoltMonI_START_SEC_CODE_LOCAL within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL
    #undef VoltMonI_START_SEC_CODE_LOCAL
    #undef MEMMAP_ERROR_VOLTMONI
  #endif
#elif (defined VoltMonI_STOP_SEC_CODE_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_LOCAL
    #undef VoltMonI_STOP_SEC_CODE_LOCAL
    #undef MEMMAP_ERROR_VOLTMONI
  #else
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to close section VoltMonI_STOP_SEC_CODE_LOCAL without prior opening VoltMonI_START_SEC_CODE_LOCAL.
  #endif

#elif (defined VoltMonI_START_SEC_CONST)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to open section VoltMonI_START_SEC_CONST within an already open section.
  #else
    #pragma section farrom Grp_ROM_Core0_QM_Const_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST
    #undef VoltMonI_START_SEC_CONST
    #undef MEMMAP_ERROR_VOLTMONI
  #endif
#elif (defined VoltMonI_STOP_SEC_CONST)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST)
    #pragma section farrom restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST
    #undef VoltMonI_STOP_SEC_CONST
    #undef MEMMAP_ERROR_VOLTMONI
  #else
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to close section VoltMonI_STOP_SEC_CONST without prior opening VoltMonI_START_SEC_CONST.
  #endif

#elif (defined VoltMonI_START_SEC_VAR_CLEARED_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to open section VoltMonI_START_SEC_VAR_CLEARED_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_LOCAL
    #undef VoltMonI_START_SEC_VAR_CLEARED_LOCAL
    #undef MEMMAP_ERROR_VOLTMONI
  #endif
#elif (defined VoltMonI_STOP_SEC_VAR_CLEARED_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_LOCAL
    #undef VoltMonI_STOP_SEC_VAR_CLEARED_LOCAL
    #undef MEMMAP_ERROR_VOLTMONI
  #else
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to close section VoltMonI_STOP_SEC_VAR_CLEARED_LOCAL without prior opening VoltMonI_START_SEC_VAR_CLEARED_LOCAL.
  #endif

#elif (defined VoltMonI_START_SEC_VAR_INIT_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to open section VoltMonI_START_SEC_VAR_INIT_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL
    #undef VoltMonI_START_SEC_VAR_INIT_LOCAL
    #undef MEMMAP_ERROR_VOLTMONI
  #endif
#elif (defined VoltMonI_STOP_SEC_VAR_INIT_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_LOCAL
    #undef VoltMonI_STOP_SEC_VAR_INIT_LOCAL
    #undef MEMMAP_ERROR_VOLTMONI
  #else
    #undef MEMMAP_ERROR_VOLTMONI
    #error Tried to close section VoltMonI_STOP_SEC_VAR_INIT_LOCAL without prior opening VoltMonI_START_SEC_VAR_INIT_LOCAL.
  #endif

#endif

#ifdef MEMMAP_ERROR_VOLTMONI
  #undef MEMMAP_ERROR_VOLTMONI
  #error MEMMAP_ERROR_VOLTMONI the included memory section was not defined within the SWC-IMPLEMENTATION of VoltMonI.
#endif
