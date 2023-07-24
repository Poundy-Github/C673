// COMPANY:   Continental Automotive
// COMPONENT: Types
// VERSION:   $Revision: 1.3 $
// 01_Source_Code\common\GLOB\Platform_Types.h
/// Global typedefs and defines, AUTOSAR-compliant platform defines (version, CPU type, byte order, etc.)
/// @file
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

// TODO   get nesting solved
// PRQA S 0810 10
// PRQA S 0388 9
// 2018-08-09; uidw1725
// Msg(3:0810) [L] '#include "D:/prj/ars441/m11_appl/norm/ars441_m11_appl_norm-kw25/04_Engineering/01_Source_Code/BASE_EB_ACG8/include/Std_Types.h"' causes nesting to exceed 8 levels - program does not conform strictly to ISO:C90.
// Msg(3:0388) [L] '#include "D:/Jenkins_Slave/workspace/ARS441_Nightly_Static_Test/M11_Appl/04_Engineering/01_Source_Code/common/GLOB/Platform_Types.h"' causes nesting to exceed 15 levels - program does not conform strictly to ISO:C99.
//                             e.g. Included from here.:
// reason: solve preliminary, SW architecture problem, all three includes below are concerned
#include <glob_cfg.h>
#include <glob_defs.h>
#include <Platform_Types_Cfg.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// Description: 8-bit CPU type (used for CPU_TYPE)
#define CPU_TYPE_8    8

/// Description: 16-bit CPU type (used for CPU_TYPE)
#define CPU_TYPE_16   16

/// Description: 32-bit CPU type (used for CPU_TYPE)
#define CPU_TYPE_32   32

/// Description: 64-bit CPU type (used for CPU_TYPE)
#define CPU_TYPE_64   64

#if ( (!defined(CPU_TYPE)) || ((CPU_TYPE != CPU_TYPE_8) && (CPU_TYPE != CPU_TYPE_16) && (CPU_TYPE != CPU_TYPE_32) && (CPU_TYPE != CPU_TYPE_64)))
#error "CPU_TYPE not defined!"
#endif //-- CPU_TYPE

#ifndef USE_INT_INSTEAD_LONG
#if ((CPU_TYPE == CPU_TYPE_64) || defined(_MSC_VER))
#define USE_INT_INSTEAD_LONG  1
#else
#define USE_INT_INSTEAD_LONG  0
#endif //-- #if ((CPU_TYPE == CPU_TYPE_64) || defined(_MSC_VER))
#endif //-- USE_INT_INSTEAD_LONG

/// Description: Predefined boolean \n
/// Range:       (0...1)
typedef unsigned char boolean;

/// Description: Predefined boolean for C++ implementations \n
/// Range:       (0...1)
#ifdef __cplusplus
typedef bool boolean_t;
#endif

/// Description: signed byte \n
/// Range:       (-128...127)
typedef signed char sint8;

/// Description: unsigned byte \n
/// Range:       (0...255)
typedef unsigned char uint8;

/// Description: Pointer to a signed 8-bit integer
typedef sint8* psint8;

/// Description: Pointer to an unsigned 8-bit integer
typedef uint8* puint8;
/// Description: A void pointer
typedef void* pvoid;


/// Description: signed short integer \n
/// Range:       (-32768...32767)
typedef signed short sint16;

/// Description: unsigned short integer \n
/// Range:       (0...65535)
typedef unsigned short uint16;

/// Description: signed long integer \n
/// Range:       (-2147483648...2147483647)
#if (defined (USE_INT_INSTEAD_LONG) && ((USE_INT_INSTEAD_LONG) == 1))
typedef signed int sint32;
#else
typedef signed long sint32;
#endif //-- USE_INT_INSTEAD_LONG

/// Description: unsigned long integer \n
/// Range:       (0...4294967295)
#if (defined (USE_INT_INSTEAD_LONG) && ((USE_INT_INSTEAD_LONG) == 1))
typedef unsigned int uint32;
#else
typedef unsigned long uint32;
#endif //-- USE_INT_INSTEAD_LONG

/// Description: 32-bit IEEE 754 floating point number \n
/// Range:       -
typedef float float32;

/// Description: 64-bit IEEE 754 floating point number
typedef double float64;

/// Description: Pointer to a signed 16-bit integer
typedef sint16* psint16;

/// Description: Pointer to an unsigned 16-bit integer
typedef uint16* puint16;

/// Description: Pointer to a signed 32-bit integer
typedef sint32* psint32;

/// Description: Pointer to an unsigned 32-bit integer
typedef uint32* puint32;
/// Description: signed long long \n
/// Range:       (-2^63...2^63-1)
typedef signed long long sint64;

/// Description: unsigned long long \n
/// Range:       (0...2^64-1)
typedef unsigned long long uint64;

/// Description: Type definition of platform-specific size type, required by EB Stack
typedef uint32 usize;


/// Description: Boolean constant false (FALSE = boolean 0) \n
/// Range:       constant (boolean)0
#ifndef b_FALSE
#define b_FALSE ((boolean)0)
#endif // b_FALSE

/// Description: Boolean constant true (TRUE = boolean 1) \n
/// Range:       constant (boolean)1
#ifndef b_TRUE
#define b_TRUE ((boolean)1)
#endif // b_TRUE

/// Description: Legacy - use b_FALSE wherever possible. \n
/// Range:       constant (boolean)0
#ifndef FALSE
#define FALSE 0u
#endif // FALSE

/// Description: Legacy - use b_TRUE wherever possible \n
/// Range:       constant (boolean)1
#ifndef TRUE
#define TRUE 1u
#endif // TRUE

#if ( !(defined(_MSC_VER)))

/// Description: Legacy - use b_FALSE wherever possible. \n
/// Range:       constant (boolean)0
#ifndef False
#define False (0u)
#endif    // #ifndef False

/// Description: Legacy - use b_TRUE wherever possible \n
/// Range:       constant (boolean)1
#ifndef True
#define True (1u)
#endif // True

#endif // #if ( !(defined(_MSC_VER)))
#ifdef __cplusplus
}
#endif //-- __cplusplus

#endif //-- PLATFORM_TYPES_H
