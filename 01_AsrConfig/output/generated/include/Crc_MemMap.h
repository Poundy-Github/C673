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

#define MEMMAP_ERROR_CRC

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Crc */

#if (defined CRC_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CRC
    #error Tried to open section CRC_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CRC_START_SEC_CODE
    #undef MEMMAP_ERROR_CRC
  #endif
#elif (defined CRC_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CRC_STOP_SEC_CODE
    #undef MEMMAP_ERROR_CRC
  #else
    #undef MEMMAP_ERROR_CRC
    #error Tried to close section CRC_STOP_SEC_CODE without prior opening CRC_START_SEC_CODE.
  #endif

#elif (defined CRC_START_SEC_CONST_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CRC
    #error Tried to open section CRC_START_SEC_CONST_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef CRC_START_SEC_CONST_16
    #undef MEMMAP_ERROR_CRC
  #endif
#elif (defined CRC_STOP_SEC_CONST_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef CRC_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR_CRC
  #else
    #undef MEMMAP_ERROR_CRC
    #error Tried to close section CRC_STOP_SEC_CONST_16 without prior opening CRC_START_SEC_CONST_16.
  #endif

#elif (defined CRC_START_SEC_CONST_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CRC
    #error Tried to open section CRC_START_SEC_CONST_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef CRC_START_SEC_CONST_32
    #undef MEMMAP_ERROR_CRC
  #endif
#elif (defined CRC_STOP_SEC_CONST_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef CRC_STOP_SEC_CONST_32
    #undef MEMMAP_ERROR_CRC
  #else
    #undef MEMMAP_ERROR_CRC
    #error Tried to close section CRC_STOP_SEC_CONST_32 without prior opening CRC_START_SEC_CONST_32.
  #endif

#elif (defined CRC_START_SEC_CONST_64)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CRC
    #error Tried to open section CRC_START_SEC_CONST_64 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_64
    #undef CRC_START_SEC_CONST_64
    #undef MEMMAP_ERROR_CRC
  #endif
#elif (defined CRC_STOP_SEC_CONST_64)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_64)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_64
    #undef CRC_STOP_SEC_CONST_64
    #undef MEMMAP_ERROR_CRC
  #else
    #undef MEMMAP_ERROR_CRC
    #error Tried to close section CRC_STOP_SEC_CONST_64 without prior opening CRC_START_SEC_CONST_64.
  #endif

#elif (defined CRC_START_SEC_CONST_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CRC
    #error Tried to open section CRC_START_SEC_CONST_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef CRC_START_SEC_CONST_8
    #undef MEMMAP_ERROR_CRC
  #endif
#elif (defined CRC_STOP_SEC_CONST_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef CRC_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR_CRC
  #else
    #undef MEMMAP_ERROR_CRC
    #error Tried to close section CRC_STOP_SEC_CONST_8 without prior opening CRC_START_SEC_CONST_8.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_CRC) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CRC) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CRC
  #error MEMMAP_ERROR_CRC the included memory section was not defined within the BSW-IMPLEMENTATION of Crc.
#endif
