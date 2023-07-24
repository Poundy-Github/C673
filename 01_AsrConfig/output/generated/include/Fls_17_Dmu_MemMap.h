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

#define MEMMAP_ERROR_FLS_17_DMU

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Fls_17_Dmu */

#if (defined FLS_17_DMU_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to open section FLS_17_DMU_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef FLS_17_DMU_START_SEC_CODE
    #undef MEMMAP_ERROR_FLS_17_DMU
  #endif
#elif (defined FLS_17_DMU_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef FLS_17_DMU_STOP_SEC_CODE
    #undef MEMMAP_ERROR_FLS_17_DMU
  #else
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to close section FLS_17_DMU_STOP_SEC_CODE without prior opening FLS_17_DMU_START_SEC_CODE.
  #endif

#elif (defined FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to open section FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_LOCAL
    #undef FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
    #undef MEMMAP_ERROR_FLS_17_DMU
  #endif
#elif (defined FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_LOCAL
    #undef FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
    #undef MEMMAP_ERROR_FLS_17_DMU
  #else
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to close section FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL without prior opening FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL.
  #endif

#elif (defined FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to open section FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_FLS_17_DMU
  #endif
#elif (defined FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_FLS_17_DMU
  #else
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to close section FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED without prior opening FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED.
  #endif

#elif (defined FLS_17_DMU_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to open section FLS_17_DMU_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef FLS_17_DMU_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_FLS_17_DMU
  #endif
#elif (defined FLS_17_DMU_STOP_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef FLS_17_DMU_STOP_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_FLS_17_DMU
  #else
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to close section FLS_17_DMU_STOP_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED without prior opening FLS_17_DMU_START_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED.
  #endif

#elif (defined FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to open section FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MEMMAP_ERROR_FLS_17_DMU
  #endif
#elif (defined FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MEMMAP_ERROR_FLS_17_DMU
  #else
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to close section FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 without prior opening FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32.
  #endif

#elif (defined FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to open section FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_FLS_17_DMU
  #endif
#elif (defined FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_FLS_17_DMU
  #else
    #undef MEMMAP_ERROR_FLS_17_DMU
    #error Tried to close section FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED without prior opening FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_FLS_17_DMU) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FLS_17_DMU) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FLS_17_DMU
  #error MEMMAP_ERROR_FLS_17_DMU the included memory section was not defined within the BSW-IMPLEMENTATION of Fls_17_Dmu.
#endif