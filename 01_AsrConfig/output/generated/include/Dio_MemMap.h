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

#define MEMMAP_ERROR_DIO

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Dio */

#if (defined DIO_START_SEC_CODE_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DIO
    #error Tried to open section DIO_START_SEC_CODE_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef DIO_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_DIO
  #endif
#elif (defined DIO_STOP_SEC_CODE_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef DIO_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_DIO
  #else
    #undef MEMMAP_ERROR_DIO
    #error Tried to close section DIO_STOP_SEC_CODE_ASIL_B_GLOBAL without prior opening DIO_START_SEC_CODE_ASIL_B_GLOBAL.
  #endif

#elif (defined DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DIO
    #error Tried to open section DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DIO
  #endif
#elif (defined DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DIO
  #else
    #undef MEMMAP_ERROR_DIO
    #error Tried to close section DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined DIO_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DIO
    #error Tried to open section DIO_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DIO_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DIO
  #endif
#elif (defined DIO_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef DIO_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_DIO
  #else
    #undef MEMMAP_ERROR_DIO
    #error Tried to close section DIO_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening DIO_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined DIO_START_SEC_CONST_ASIL_B_GLOBAL_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DIO
    #error Tried to open section DIO_START_SEC_CONST_ASIL_B_GLOBAL_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_16
    #undef DIO_START_SEC_CONST_ASIL_B_GLOBAL_16
    #undef MEMMAP_ERROR_DIO
  #endif
#elif (defined DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_16
    #undef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16
    #undef MEMMAP_ERROR_DIO
  #else
    #undef MEMMAP_ERROR_DIO
    #error Tried to close section DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16 without prior opening DIO_START_SEC_CONST_ASIL_B_GLOBAL_16.
  #endif

#elif (defined DIO_START_SEC_CONST_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_DIO
    #error Tried to open section DIO_START_SEC_CONST_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32
    #undef DIO_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_DIO
  #endif
#elif (defined DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_ASIL_B_GLOBAL_32
    #undef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_DIO
  #else
    #undef MEMMAP_ERROR_DIO
    #error Tried to close section DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32 without prior opening DIO_START_SEC_CONST_ASIL_B_GLOBAL_32.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_DIO) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_DIO) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_DIO
  #error MEMMAP_ERROR_DIO the included memory section was not defined within the BSW-IMPLEMENTATION of Dio.
#endif
