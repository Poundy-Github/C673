/*
 * imager_globdefs.h
 *
 *  Created on: 19.07.2011
 *      Author: uidt3974
 */

#ifndef IMAGER_GLOBDEFS_H_
#define IMAGER_GLOBDEFS_H_

#include "glob_defs.h"

// For memset()
#include <string.h>

// Version number of the imager control
#define IC_TOPLEVEL_VERSION  0x03060200

// ********************************************************************************
// **                                GLOBAL STUFF                                **
// ********************************************************************************

// Determine if left imager should be enabled or not
#if (CFG_MFC_STEREO == 1)
#define ICCFG_ENABLE_LEFT_IMAGER        1
#define ICCFG_HARDWARE_STEREO           1
#define ICCFG_NUM_IMAGERS               2

// This is the last entry in 'IC_E_Imager', which maps to a single imager. It's used
// to do boundary checks for arrays, which are indexed by this enum.
#define IC_ce_LAST_SINGLE_IMAGER        IC_e_IMAGER_LEFT
#else
#define ICCFG_ENABLE_LEFT_IMAGER        0
#define ICCFG_HARDWARE_STEREO           0
#define ICCFG_NUM_IMAGERS               1

// This is the last entry in 'IC_E_Imager', which maps to a single imager. It's used
// to do boundary checks for arrays, which are indexed by this enum.
#define IC_ce_LAST_SINGLE_IMAGER        IC_e_IMAGER_RIGHT
#endif

// Magic macros to allow expanded concatenation of preprocessor definitions
// PRQA S 0342,3429,3453 2
#define IC_PREPROC_CONCAT2(a,b)   a ## b
#define IC_PREPROC_CONCAT(a,b)    IC_PREPROC_CONCAT2(a,b)


// Are we compiling for Windows / MTS?
#ifdef WIN32
#define IC_COMPILE_FOR_MTS 1
#else
#define IC_COMPILE_FOR_MTS 0
#endif

// Inline directive
#if (IC_COMPILE_FOR_MTS == 1)
#define IC_INLINE
#else
#define IC_INLINE inline
#endif

// Workaround, as Rhapsody can not roundtrip 'inline void'
#define IC_INLINE_VOID IC_INLINE void
#define IC_INLINE_UI16 IC_INLINE uint16
#define IC_INLINE_UI32 IC_INLINE uint32

// This is a unique value that is used to enable HIL-mode. It's resistant to illegal memory-overwrites.
#define IC_cui32_KEY_HILMODE 0xAB62DBA3u

// Number of different frame types (2 = even+odd)
#define IC_cui16_NumFrameTypes ((uint16)2)

// The version of the embedded data format
#define IC_cui8_IC_EMBEDDED_DATA_VERSION ((uint8)0x10)

// Default/Master frametype
#define IC_ce_MASTER_FRAMETYPE    IC_e_FRAMETYPE_ODD

// Default/Master imager
#define IC_ce_MASTER_IMAGER       IC_e_IMAGER_RIGHT

// Number of bytes each pixel occupies in memory
#define IC_cui_BYTES_PER_PIXEL 2

// Macro for zeroing variables/structure instances
// PRQA S 3429,3435,3453,3456 1
#define IC_v_ZEROMEM(x) (void)memset(&(x), 0, (size_t)sizeof(x))

// Returns the number of elements contained in an array
// PRQA S 3429,3435,3453,3456 1
#define IC_ARRLEN(x)    ((uint32)sizeof(x) / (uint32)sizeof((x)[0]))

// Other constants
#define IC_FACTOR_US2NS 1000

// Unit conversion macros
#define IC_ui32_CONV_ns_us(time_ns)  (((time_ns) / 1000u))  // PRQA S 3429,3453
#define IC_ui32_CONV_us_ms(time_us)  (((time_us) / 1000u))  // PRQA S 3429,3453
#define IC_ui64_CONV_us_ms(time_us)  (((time_us) / 1000uL)) // PRQA S 3429,3453
#define IC_ui32_CONV_us_ns(time_us)  (((time_us) * 1000u))  // PRQA S 3429,3453

// Min/Max values for certain variables
#define TYPEMIN_UI32           0u
#define TYPEMAX_UI32  0xFFFFFFFFu
#define TYPEMIN_SI32 -0x80000000
#define TYPEMAX_SI32  0x7FFFFFFF
#define TYPEMIN_SI16     (-32768)
#define TYPEMAX_SI16       32767
#define TYPEMIN_UI16           0u
#define TYPEMAX_UI16       65535u
#define TYPEMIN_SI8         -128
#define TYPEMAX_SI8          127
#define TYPEMIN_UI8            0u
#define TYPEMAX_UI8          255u

// Common constants (prevents QAC warnings)
#define IC_cf32_ZERO  0.0f
#define IC_cf32_ONE   1.0f

// Common bitmasks
#define IC_BITMASK_U8  0xFFu
#define IC_BITMASK_U16 0xFFFFu
#define IC_BITMASK_U32 0xFFFFFFFFu

#define IC_BITSALLONE_U16 0xFFFFu
#define IC_BITSALLONE_U32 0xFFFFFFFFu

#define IC_BITSHIFT_0BYTE   0
#define IC_BITSHIFT_1BYTE   8
#define IC_BITSHIFT_2BYTE  16
#define IC_BITSHIFT_3BYTE  24
#define IC_BITSHIFT_4BYTE  32
#define IC_BITSHIFT_5BYTE  40
#define IC_BITSHIFT_6BYTE  48
#define IC_BITSHIFT_7BYTE  56

#define IC_NUMBITS_8      8
#define IC_NUMBITS_16    16
#define IC_NUMBITS_32    32
#define IC_NUMBITS_64    64

#endif /* IMAGER_GLOBDEFS_H_ */
