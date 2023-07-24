// COMPANY:   Continental Automotive
// COMPONENT: Types
// VERSION:   $Revision: 1.7 $
/// Global typedefs and defines for DPU
/// @file

#ifndef PLATFORM_TYPES_CFG_H
#define PLATFORM_TYPES_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif //-- __cplusplus


/// Description: Type of CPU being used (8, 16 or 32 bit) \n
/// Range:       CPU_TYPE_8  - 8-bit architecture \n
///              CPU_TYPE_16 - 16-bit architecture \n
///              CPU_TYPE_32 - 32-bit architecture
#define CPU_TYPE CPU_TYPE_32

/// Force usage of usigned int for datatype uint32
#define USE_INT_INSTEAD_LONG  1

typedef unsigned int ubit32;

/// Core ID's
enum DSPCoreID
{
  e_CoreInvalid = 0, ///< Value 0 for not valid value.
  e_CoreCA8_0 = 11, ///< Cortex A8 core
  e_CoreM3_0 = 12, ///< Cortex M3 VIDEO in TI docs VICP
  e_CoreM3_Algo = 13, ///< Cortex M3Algo in TI docs VPSS
  e_CoreDSP_0 = 14, ///< DSP674 core
  e_CoreEVE_0 = 16, ///< ARP32 Core of EVE system
  e_CoreCA8_1 = 21, ///< Cortex A8 core of stereo DSP
  e_CoreM3_1 = 22, ///< Cortex M3 VIDEO of stereo DSP
  e_CoreDSP_1 = 25, ///< DSP674 core of stereo DSP
  e_CoreEVE_1 = 27, ///< ARP32 Core of stereo DSP
  e_CoreNumber = 8, ///< Marker for number of enums in cores type
  /* DSPCoreID must be smaller than 256 */
  /* compiler workaround */
  e_DSPCoreID_EVT_LAST_ENTRY  = 65536
};

/*! Macros for linking code into a specific section */
#ifdef __GNUC__
// Use __attribute__ in c++ file for GCC
#define SECTION_CODE_DECL(x)
#define SECTION_CODE_IMPL(x) __attribute__ ((section (x)))
#elif defined(__TI_COMPILER_VERSION__)
// Use _Pragma for TI compiler
#define SECTION_CODE_DECL(x)
#ifdef  PRAGMA
#undef  PRAGMA
#endif
#define PRAGMA(x) _Pragma(#x)
#define SECTION_CODE_IMPL(x) PRAGMA(CODE_SECTION(x))
#endif

/*! Macros for linking data into a specific section */
#ifdef __GNUC__
// Use __attribute__ in c++ file for GCC
#define SECTION_DATA_DECL(x)
#define SECTION_DATA_IMPL(x) __attribute__ ((section (x)))
#elif defined(__TI_COMPILER_VERSION__)
// Use _Pragma for TI compiler
#define SECTION_DATA_DECL(x)
#ifdef  PRAGMA
#undef  PRAGMA
#endif
#define PRAGMA(x) _Pragma(#x)
#define SECTION_DATA_IMPL(x) PRAGMA(DATA_SECTION(x))
#endif


/*! Macros for aligning a section */
#ifdef __GNUC__
// Use __attribute__ in c++ file for GCC
#define SECTION_ALIGN_DECL(x)
#define SECTION_ALIGN_IMPL(x) __attribute__ ((aligned (x)))
#elif defined(__TI_COMPILER_VERSION__)
// Use _Pragma for TI compiler
#define SECTION_ALIGN_DECL(x)
#ifdef  PRAGMA
#undef  PRAGMA
#endif
#define PRAGMA(x) _Pragma(#x)
#define SECTION_ALIGN_IMPL(x) PRAGMA(DATA_ALIGN(x))
#endif

#ifdef __cplusplus
}
#endif //-- __cplusplus

#endif //-- PLATFORM_TYPES_CFG_H
