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

#define MEMMAP_ERROR_COM

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Com */

#if (defined COM_START_SEC_APPL_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_APPL_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_APPL_CODE
    #undef COM_START_SEC_APPL_CODE
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_APPL_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_APPL_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_APPL_CODE
    #undef COM_STOP_SEC_APPL_CODE
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_APPL_CODE without prior opening COM_START_SEC_APPL_CODE.
  #endif

#elif (defined COM_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef COM_START_SEC_CODE
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef COM_STOP_SEC_CODE
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_CODE without prior opening COM_START_SEC_CODE.
  #endif

#elif (defined COM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef COM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening COM_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined COM_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef COM_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef COM_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_CONFIG_DATA_UNSPECIFIED without prior opening COM_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined COM_START_SEC_CONST_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_CONST_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef COM_START_SEC_CONST_32
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_CONST_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef COM_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_CONST_32 without prior opening COM_START_SEC_CONST_32.
  #endif

#elif (defined COM_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef COM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef COM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_CONST_UNSPECIFIED without prior opening COM_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined COM_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef COM_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef COM_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_VAR_CLEARED_16 without prior opening COM_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined COM_START_SEC_VAR_CLEARED_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_VAR_CLEARED_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32
    #undef COM_START_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_VAR_CLEARED_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32
    #undef COM_STOP_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_VAR_CLEARED_32 without prior opening COM_START_SEC_VAR_CLEARED_32.
  #endif

#elif (defined COM_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef COM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef COM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_VAR_CLEARED_8 without prior opening COM_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined COM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef COM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening COM_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined COM_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_COM
    #error Tried to open section COM_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef COM_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_COM
  #endif
#elif (defined COM_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef COM_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_COM
  #else
    #undef MEMMAP_ERROR_COM
    #error Tried to close section COM_STOP_SEC_VAR_INIT_8 without prior opening COM_START_SEC_VAR_INIT_8.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_COM) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_COM) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_COM
  #error MEMMAP_ERROR_COM the included memory section was not defined within the BSW-IMPLEMENTATION of Com.
#endif
