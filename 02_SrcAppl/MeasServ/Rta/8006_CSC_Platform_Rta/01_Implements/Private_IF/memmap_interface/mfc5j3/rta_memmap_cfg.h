// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief RTA memory mapping configuration header file for ARS540 IUC

#ifndef RTA_MEMMAP_CFG_H
#define RTA_MEMMAP_CFG_H


/// Switch to activate/deactivate usage of EB MEMMAP
/// 1 - MEMMAP mechanism from EB is used
/// 0 - MEMMAP mechanism from EB is not used
#define RTA_MEMMAP_EB_IS_USED  (0)

#endif // #define RTA_MEMMAP_CFG_H

#if (!defined RTA_MEMMAP_EB_IS_USED) || (RTA_MEMMAP_EB_IS_USED == (0))

// ---------------------------------------------------------------------------------------------
// MEMMAP mechanism from EB is NOT used
// ---------------------------------------------------------------------------------------------

///  \brief  Memory section mapping
///
/// If the MEMMAP mechanism from EB is not used, the assignment to the memory area shall be
/// made here.
/// @{
//\cond MEMORY_MAPPING


#define MEMMAP_ERROR_CDDSWC_RTA

#if (defined CddSwc_RTA_START_SEC_INIT_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_INIT_CODE within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CddSwc_RTA_START_SEC_INIT_CODE
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_INIT_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CddSwc_RTA_STOP_SEC_INIT_CODE
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_INIT_CODE without prior opening CddSwc_RTA_START_SEC_INIT_CODE.
  #endif
#elif (defined CddSwc_RTA_AUX_START_SEC_INIT_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_AUX_START_SEC_INIT_CODE within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CddSwc_RTA_AUX_START_SEC_INIT_CODE
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_AUX_STOP_SEC_INIT_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CddSwc_RTA_AUX_STOP_SEC_INIT_CODE
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_AUX_STOP_SEC_INIT_CODE without prior opening CddSwc_RTA_START_SEC_INIT_CODE.
  #endif

#elif (defined CddSwc_RTA_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_CODE within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CddSwc_RTA_START_SEC_CODE
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CddSwc_RTA_STOP_SEC_CODE
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_CODE without prior opening CddSwc_RTA_START_SEC_CODE.
  #endif

#elif (defined CddSwc_RTA_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_INIT_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_INIT_32 within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32
    #undef CddSwc_RTA_START_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_INIT_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32
    #undef CddSwc_RTA_STOP_SEC_VAR_INIT_32
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_INIT_32 without prior opening CddSwc_RTA_START_SEC_VAR_INIT_32.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_INIT_32_UNCACHED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_INIT_32_UNCACHED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32_UNCACHED
    #undef CddSwc_RTA_START_SEC_VAR_INIT_32_UNCACHED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_INIT_32_UNCACHED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32_UNCACHED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_32_UNCACHED
    #undef CddSwc_RTA_STOP_SEC_VAR_INIT_32_UNCACHED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_INIT_32_UNCACHED without prior opening CddSwc_RTA_START_SEC_VAR_INIT_32_UNCACHED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_INIT_8 within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef CddSwc_RTA_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef CddSwc_RTA_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_INIT_8 without prior opening CddSwc_RTA_START_SEC_VAR_INIT_8.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_INIT_8_UNCACHED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_INIT_8_UNCACHED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8_UNCACHED
    #undef CddSwc_RTA_START_SEC_VAR_INIT_8_UNCACHED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_INIT_8_UNCACHED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8_UNCACHED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8_UNCACHED
    #undef CddSwc_RTA_STOP_SEC_VAR_INIT_8_UNCACHED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_INIT_8_UNCACHED without prior opening CddSwc_RTA_START_SEC_VAR_INIT_8_UNCACHED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_NO_INIT_UNSPECIFIED.
  #endif

//All defines for the rtaBuffers
#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_1_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_2_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_3_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_4_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_5_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_6_NO_INIT_UNSPECIFIED.
  #endif

#elif (defined CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to open section CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED within an already open section.
  #else
    // no definition -> default compiler settings are used
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #endif
#elif (defined CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED)
    // no definition -> default compiler settings are used
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED
    #undef CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CDDSWC_RTA
  #else
    #undef MEMMAP_ERROR_CDDSWC_RTA
    #error Tried to close section CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED without prior opening CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_7_NO_INIT_UNSPECIFIED.
  #endif

#endif

#ifdef MEMMAP_ERROR_CDDSWC_RTA
  #undef MEMMAP_ERROR_CDDSWC_RTA
  #error MEMMAP_ERROR_CDDSWC_RTA the included memory section was not defined within the SWC-IMPLEMENTATION of CddSwc_RTA.
#endif


//\endcond
/// @}

#else  // #if (!defined RTA_MEMMAP_EB_IS_USED) || (RTA_MEMMAP_EB_IS_USED == (0))

// ---------------------------------------------------------------------------------------------
// MEMMAP mechanism from EB is used
// ---------------------------------------------------------------------------------------------

#include <CddSwc_RTA_MemMap.h>

#endif // #if (!defined RTA_MEMMAP_EB_IS_USED) || (RTA_MEMMAP_EB_IS_USED == (0))
// PRQA S 0883 // 2022-05-19; uidv3699; summary: Include file code not protected against repeated inclusion; reason: must be included repeated times to map code/data to different memory regions
