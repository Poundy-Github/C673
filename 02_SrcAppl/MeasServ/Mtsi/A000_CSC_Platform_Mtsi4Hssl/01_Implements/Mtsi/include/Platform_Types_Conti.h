// COMPANY:   Continental Automotive
// COMPONENT: Types
// VERSION:   $Revision: 1.4 $
// 01_Source_Code\common\GLOB\Platform_Types.h
/// Global typedefs and defines, AUTOSAR-compliant platform defines (version, CPU type, byte order, etc.)
/// @file

//#ifndef PLATFORM_TYPES_H
//#define PLATFORM_TYPES_H

// TODO   get nesting solved
// PRQA S 0810 10
// PRQA S 0388 9
// 2018-08-09; uidw1725
// Msg(3:0810) [L] '#include "D:/prj/ars441/m11_appl/norm/ars441_m11_appl_norm-kw25/04_Engineering/01_Source_Code/BASE_EB_ACG8/include/Std_Types.h"' causes nesting to exceed 8 levels - program does not conform strictly to ISO:C90.
// Msg(3:0388) [L] '#include "D:/Jenkins_Slave/workspace/ARS441_Nightly_Static_Test/M11_Appl/04_Engineering/01_Source_Code/common/GLOB/Platform_Types.h"' causes nesting to exceed 15 levels - program does not conform strictly to ISO:C99.
//                             e.g. Included from here.:
// reason: solve preliminary, SW architecture problem, all three includes below are concerned
//#include <glob_cfg.h>
#include <glob_defs.h>
//#include <Platform_Types_Cfg.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// Description: 8-bit CPU type (used for CPU_TYPE)
//#define CPU_TYPE_8    8

/// Description: 16-bit CPU type (used for CPU_TYPE)
//#define CPU_TYPE_16   16

/// Description: 32-bit CPU type (used for CPU_TYPE)
//#define CPU_TYPE_32   32

/// Description: 64-bit CPU type (used for CPU_TYPE)
//#define CPU_TYPE_64   64



#ifndef USE_INT_INSTEAD_LONG
#if ((CPU_TYPE == CPU_TYPE_64) || defined(_MSC_VER))
#define USE_INT_INSTEAD_LONG  1
#else
#define USE_INT_INSTEAD_LONG  0
#endif //-- #if ((CPU_TYPE == CPU_TYPE_64) || defined(_MSC_VER))
#endif //-- USE_INT_INSTEAD_LONG

/// Description: Predefined boolean \n
/// Range:       (0...1)
//typedef unsigned char boolean;

/// Description: Predefined boolean for C++ implementations \n
/// Range:       (0...1)
#ifdef __cplusplus
typedef bool boolean_t;
#endif

/// Description: signed byte \n
/// Range:       (-128...127)
//typedef signed char sint8;

/// Description: unsigned byte \n
/// Range:       (0...255)
//typedef unsigned char uint8;

/// Description: Pointer to a signed 8-bit integer
//typedef sint8* psint8;

/// Description: Pointer to an unsigned 8-bit integer
//typedef uint8* puint8;

/// Description: A void pointer
// typedef void* pvoid; //To avoid compiling warning since it's already defined in source/SWC_ALGO/RTA/glob_type.h 

/// Description: Type definition for pointer to void
// typedef void * VoidPtr; //To avoid compiling warning since it's already defined in generated/include/Platform_Types.h

/// Description: Type definition for pointer to const void
// typedef const void *  ConstVoidPtr; //To avoid compiling warning since it's already defined in generated/include/Platform_Types.h

/// Description: signed byte. Optimized Autosar integer data type, may be used if the correct usage is proven by a formal code review \n
/// or a static analysis by a validated static analysis tool. \n
/// Range:       (-128...127)
#if (!defined(DISABLE_LEAST_TYPE_GENERATION))
//typedef signed int sint8_least;
#endif

/// Description: unsigned byte. Optimized Autosar integer data type, may be used if the correct usage is proven by a formal code review \n
/// or a static analysis by a validated static analysis tool. \n
/// Range:       (0...255)
#if (!defined(DISABLE_LEAST_TYPE_GENERATION))
//typedef unsigned int uint8_least;
#endif

/// Description: signed short integer. Optimized Autosar integer data type, may be used if the correct usage is proven by a formal \n
/// code review or a static analysis by a validated static analysis tool. \n
/// Range:       (-32768...32767)
#if (!defined(DISABLE_LEAST_TYPE_GENERATION))
//typedef signed int sint16_least;
#endif

/// Description: unsigned short integer. Optimized Autosar integer data type, may be used if the correct usage is proven by a formal \n
/// code review or a static analysis by a validated static analysis tool. \n
/// Range:       (0...65535)
#if (!defined(DISABLE_LEAST_TYPE_GENERATION))
//typedef unsigned int uint16_least;
#endif

/// Description: signed long integer. Optimized Autosar integer data type, may be used if the correct usage is proven by a formal \n
/// code review or a static analysis by a validated static analysis tool. \n
/// Range:       (-2147483648...2147483647)
#if (!defined(DISABLE_LEAST_TYPE_GENERATION))
#if (defined (USE_INT_INSTEAD_LONG) && ((USE_INT_INSTEAD_LONG) == 1))
//typedef signed int sint32_least;
#else
//typedef signed long sint32_least;
#endif //-- USE_INT_INSTEAD_LONG
#endif //-- DISABLE_LEAST_TYPE_GENERATION

/// Description: unsigned long integer. Optimized Autosar integer data type, may be used if the correct usage is proven by a formal \n
/// code review or a static analysis by a validated static analysis tool. \n
/// Range:       (0...4294967295)
#if (!defined(DISABLE_LEAST_TYPE_GENERATION))
#if (defined (USE_INT_INSTEAD_LONG) && ((USE_INT_INSTEAD_LONG) == 1))
//typedef unsigned int uint32_least;
#else
//typedef unsigned long uint32_least;
#endif //-- USE_INT_INSTEAD_LONG
#endif //-- DISABLE_LEAST_TYPE_GENERATION

/// Description: signed short integer \n
/// Range:       (-32768...32767)
//typedef signed short sint16;

/// Description: unsigned short integer \n
/// Range:       (0...65535)
//typedef unsigned short uint16;

/// Description: signed long integer \n
/// Range:       (-2147483648...2147483647)
#if (defined (USE_INT_INSTEAD_LONG) && ((USE_INT_INSTEAD_LONG) == 1))
//typedef signed int sint32;
#else
//typedef signed long sint32;
#endif //-- USE_INT_INSTEAD_LONG

/// Description: unsigned long integer \n
/// Range:       (0...4294967295)
#if (defined (USE_INT_INSTEAD_LONG) && ((USE_INT_INSTEAD_LONG) == 1))
//typedef unsigned int uint32;
#else
//typedef unsigned long uint32;
#endif //-- USE_INT_INSTEAD_LONG

/// Description: 32-bit IEEE 754 floating point number \n
/// Range:       -
//typedef float float32;

/// Description: 64-bit IEEE 754 floating point number
//typedef double float64;

/// Description: Pointer to a signed 16-bit integer
//typedef sint16* psint16;

/// Description: Pointer to an unsigned 16-bit integer
//typedef uint16* puint16;

/// Description: Pointer to a signed 32-bit integer
//typedef sint32* psint32;

/// Description: Pointer to an unsigned 32-bit integer
//typedef uint32* puint32;

/// Description: Pointer to a floating point 32-bit number
//typedef float32* pfloat32;

/// Description: signed long long \n
/// Range:       (-2^63...2^63-1)
//typedef signed long long sint64;

/// Description: unsigned long long \n
/// Range:       (0...2^64-1)
//typedef unsigned long long uint64;

/// Description: Type definition of platform-specific size type, required by EB Stack
//typedef uint32 usize;

#if (!defined USIZE_C)
/// Macro to define a constant of type usize
#define USIZE_C(x) (x ## UL)
#endif

/// Description: Low byte first (used for CPU_BYTE_ORDER)
//#define LOW_BYTE_FIRST 1

/// Description: High byte first (used for CPU_BYTE_ORDER)
//#define HIGH_BYTE_FIRST 0

/// Description: Least significant bit first (used for CPU_BIT_ORDER)
//#define LSB_FIRST 1

/// Description: Most significant bit first (used for CPU_BIT_ORDER)
//#define MSB_FIRST 0

// todo Try to remove the following defines

/// Description:  The vendor-ID of the Std_Types. \n
///               Added unsigned suffix in accordance with AUTOSAR 4.2 specs \n
/// Range:        uint16 (0...0xFFFF)
//#define STD_TYPES_VENDOR_ID 0x002Bu

/// Description:  Major version number for the architecture. \n
///               Added unsigned suffix in accordance with AUTOSAR 4.2 specs \n
/// Range:        uint8 (0...0xFF)
//#define STD_TYPES_AR_RELEASE_MAJOR_VERSION 4u

/// Description:  Minor version number for the architecture. \n
///               Added unsigned suffix in accordance with AUTOSAR 4.2 specs \n
/// Range:        uint8 (0...0xFF)
//#define STD_TYPES_AR_RELEASE_MINOR_VERSION 0u

/// Description: Revision version number for the architecture. \n
///              Added unsigned suffix in accordance with AUTOSAR 4.2 specs \n
/// Range:       uint8 (0...0xFF)
//#define STD_TYPES_AR_RELEASE_REVISION_VERSION 3u

/// Description: Logical state on. Only for compatibility - if possible use STD_ON instead. \n
//  Range:       1 (on)
#define ON STD_ON

/// Description: Logical state off. Only for compatibility - if possible use STD_OFF instead. \n
/// Range:       0 (off)
#define OFF STD_OFF

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

#if ( !(defined(_MSC_VER)) || (defined(__IPL_CANTPP__)) )

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

#endif // #if ( !(defined(_MSC_VER)) || (defined(__IPL_CANTPP__)) )

// DO NOT attempt to use HW-acceleration if the switch has not been defined at all,
// or if the program is running on PC (Module testing mode, etc.)
// PLEASE NOTE THAT THIS PART IS ONLY RELEVANT FOR PPC & DIAB-BASED PLATFORMS (__DCC__)
//
#if (!defined(GLOB_HW_ACCELERATION))
#define GLOB_HW_ACCELERATION     0
#endif  // #if (!defined(GLOB_HW_ACCELERATION))
// Cantata: __IPL_CANTPP__
#if (!defined(__DCC__) || defined(__IPL_CANTPP__))
#undef GLOB_HW_ACCELERATION
#define GLOB_HW_ACCELERATION     0
#endif  // #if (!defined(__DCC__) || defined(__IPL_CANTPP__))

/// @brief              Limit the floating point number to a minimum and a maximum value
/// @param[in]          min : lower limit
/// @param[in]          max : upper limit
/// @param[in]          value : value to be limited in case out of range
/// @return             value in range
/// @startuml
/// start
/// note right: Start
/// :getting the minimum out of the maximum value and the value to compare.;
/// :getting the maximum out of the minimum vale and the returned maximum value;
/// :returning the calculated value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define MINMAX_FLOAT_HW(min,max,value) MIN_FLOAT_HW(MAX_FLOAT_HW(min,value),max)
// PRQA S 3429,3453 --


#if GLOB_HW_ACCELERATION

/// @brief              Absolute value for floating point
/// @param[in]          x : float value
/// @return             absolute value
/// @startuml
/// start
/// note right: Start
/// :setting the highest bit to 0 and returning it.;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define fABS_HW(x)               GlobAbsFloat(x)
// PRQA S 3429,3453 --

/// @brief              Absolute value for floating point
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : float value
/// @return             absolute value
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :setting the highest bit to 0 and returning it.;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobAbsFloat(float32 f_FpX);
asm static volatile float32 GlobAbsFloat(float32 f_FpX)
{
% reg f_FpX;
! "r3"

  e_rlwinm r3,f_FpX,0,1,31 // r3 = |f_FpX|
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Negative absolute value for floating point
/// @param[in]          f_FpX : float value
/// @return             negative absolute value
/// @startuml
/// start
/// note right: Start
/// :setting the highest bit to 1 and returning it, therefore returning the negative value of the given value.;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define NEG_ABS_HW(x)            GlobNegAbsFloat(x)
// PRQA S 3429,3453 --


/// @brief              Negative absolute value for floating point
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : float value
/// @return             negative absolute value
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :setting the highest bit to 1 and returning it, therefore returning the negative value of the given value.;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobNegAbsFloat(float32 f_FpX);
asm static volatile float32 GlobNegAbsFloat(float32 f_FpX)
{
% reg f_FpX;
! "r3"

  oris  r3,f_FpX,0x8000    // r3 = -|f_FpX|
}
// PRQA S 0654, 3406, 3219, 3480 --


/// @brief              Negative value for floating point
/// @param[in]          x : float value
/// @return             negative value
/// @startuml
/// start
/// note right: Start
/// :flipping the highest bit returning the new value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
// Negate floating point
#define NEG_FLOAT_HW(x)          GlobNegFloat(x)
// PRQA S 3429,3453, 6030 --

/// @brief              Negative value for floating point
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : float value
/// @return             negative absolute value
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :flipping the highest bit returning the new value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobNegFloat(float32 f_FpX);
asm static volatile float32 GlobNegFloat(float32 f_FpX)
{
% reg f_FpX;
! "r3"

  xori  r3,f_FpX,0x80000000  // r3 = -f_FpX
}
// PRQA S 0654, 3406, 3219, 3480 --


/// @brief              Minimum float value of two values
/// @param[in]          x : first float value
/// @param[in]          y : second float value
/// @return             Minimum of both values
/// @startuml
/// start
/// note right: Start
/// :returning the minimum of the two handed values;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
// Floating point minimum
#define MIN_FLOAT_HW(x,y)        GlobMinFloat(x,y)
// PRQA S 3429,3453 --

/// @brief              Minimum float value of two values
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : first float value
/// @param[in]          f_FpY : second float value
/// @return             Minimum of both values
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the minimum of the two handed values;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobMinFloat(float32 f_FpX, float32 f_FpY);
asm static volatile float32 GlobMinFloat(float32 f_FpX, float32 f_FpY)
{
% reg f_FpX, f_FpY;
! "r3"

  efsmin  r3, f_FpX, f_FpY
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Maximum float value of two values
/// @param[in]          x : first float value
/// @param[in]          y : second float value
/// @return             Maximum of both values
/// @startuml
/// start
/// note right: Start
/// :returning the maximum of the two handed values;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
// Floating point maximum
#define MAX_FLOAT_HW(x,y)        GlobMaxFloat(x,y)
// PRQA S 3429,3453 --

/// @brief              Maximum float value of two values
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : first float value
/// @param[in]          f_FpY : second float value
/// @return             Maximum of both values
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the maximum of the two handed values;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobMaxFloat(float32 f_FpX, float32 f_FpY);
asm static volatile float32 GlobMaxFloat(float32 f_FpX, float32 f_FpY)
{
% reg f_FpX, f_FpY;
! "r3"

  efsmax  r3, f_FpX, f_FpY
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Rounds floating point number and converts to a signed integer
/// @param[in]          x : float value
/// @return             converted value
/// @startuml
/// start
/// note right: Start
/// :returning the signed integer value of a handed value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define ROUND_TO_INT_HW(x)       GlobRoundToSint(x)
// PRQA S 3429,3453 --

/// @brief              Rounds floating point number and converts to a signed integer
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : float value
/// @return             converted value
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the signed integer value of a handed value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile sint32 GlobRoundToSint(float32 f_FpX);
asm static volatile sint32 GlobRoundToSint(float32 f_FpX)
{
% reg f_FpX;
! "r3"

  efsctsi r3, f_FpX       // r3 = (sint32)f_FpX
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Rounds floating point and converts to an unsigned integer
/// @param[in]          x : float value
/// @return             converted value
/// @startuml
/// start
/// note right: Start
/// :returning the unsigned integer value of a handed value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
// Rounds floating point and converts to Unsigned Integer
#define ROUND_TO_UINT_HW(x)      GlobRoundToUint(x)
// PRQA S 3429,3453 --

/// @brief              Rounds floating point and converts to an unsigned integer
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : float value
/// @return             converted value
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the unsigned integer value of a handed value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile uint32 GlobRoundToUint(float32 f_FpX);
asm static volatile uint32 GlobRoundToUint(float32 f_FpX)
{
% reg f_FpX;
! "r3"

  efsctui r3, f_FpX       // r3 = (uint32)f_FpX
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Floating point multiply and add: y = a * b + d
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating a * b + d
/// @startuml
/// start
/// note right: Start
/// :returning the sum of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define MUL_ADD_FLOAT_HW(a,b,d)  GlobMulAddFloat(a,b,d)
// PRQA S 3429,3453 --

/// @brief              Floating point multiply and add: r3 = (f_FpA * f_FpB) + f_FpD
/// @pre                none
/// @post               none
/// @param[in]          f_FpA : float value
/// @param[in]          f_FpB : float value
/// @param[in]          f_FpD : float value
/// @return             result of calculating (f_FpA * f_FpB) + f_FpD
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the sum of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobMulAddFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD);
asm static volatile float32 GlobMulAddFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD)
{
% reg f_FpA, f_FpB, f_FpD;
! "r3"

  mr       r3, f_FpD           // r3 = f_FpD
  efsmadd  r3, f_FpA, f_FpB    // r3 = (f_FpA * f_FpB) + f_FpD
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Floating point negative multiply and add: y = -((a * b) + d)
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating -((a * b) + d)
/// @startuml
/// start
/// note right: Start
/// :returning the negative of the sum of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define NEG_MUL_ADD_FLOAT_HW(a,b,d)  GlobNegMulAddFloat(a,b,d)
// PRQA S 3429,3453 --

/// @brief              Floating point negative multiply and add: r3 = -((f_FpA * f_FpB) + f_FpD)
/// @pre                none
/// @post               none
/// @param[in]          f_FpA : float value
/// @param[in]          f_FpB : float value
/// @param[in]          f_FpD : float value
/// @return             result of calculating -((f_FpA * f_FpB) + f_FpD)
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the negative of the sum of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobNegMulAddFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD);
asm static volatile float32 GlobNegMulAddFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD)
{
% reg f_FpA, f_FpB, f_FpD;
! "r3"

  mr       r3, f_FpD           // r3 = f_FpD
  efsnmadd r3, f_FpA, f_FpB    // r3 = -((f_FpA * f_FpB) + f_FpD)
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Floating point multiply and subtract: y = a * b - d
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating a * b - d
/// @startuml
/// start
/// note right: Start
/// :returning the difference of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define MUL_SUB_FLOAT_HW(a,b,d)  GlobMulSubFloat(a,b,d)
// PRQA S 3429,3453 --

/// @brief              Floating point multiply and subtract: r3 = (f_FpA * f_FpB) - f_FpD
/// @pre                none
/// @post               none
/// @param[in]          f_FpA : float value
/// @param[in]          f_FpB : float value
/// @param[in]          f_FpD : float value
/// @return             result of calculating (f_FpA * f_FpB) - f_FpD
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the difference of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobMulSubFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD);
asm static volatile float32 GlobMulSubFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD)
{
% reg f_FpA, f_FpB, f_FpD;
! "r3"

  mr       r3, f_FpD           // r3 = f_FpD
  efsmsub  r3, f_FpA, f_FpB    // r3 = (f_FpA * f_FpB) - f_FpD
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Floating point negative multiply and subtract: y = -((a * b) - d)
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating -((a * b) - d)
/// @startuml
/// start
/// note right: Start
/// :returning the negative of the difference of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define NEG_MUL_SUB_FLOAT_HW(a,b,d)  GlobNegMulSubFloat(a,b,d)
// PRQA S 3429,3453 --

/// @brief              Negative-Multiply-Subtract function, returns r3 = -((f_FpA * f_FpB) - f_FpD)
/// @param[in]          f_FpA : float value
/// @param[in]          f_FpB : float value
/// @param[in]          f_FpD : float value
/// @return             result of calculating -((f_FpA * f_FpB) - f_FpD)
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the negative of the difference of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobNegMulSubFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD);
asm static volatile float32 GlobNegMulSubFloat(float32 f_FpA, float32 f_FpB, float32 f_FpD)
{
% reg f_FpA, f_FpB, f_FpD;
! "r3"

  mr       r3, f_FpD           // r3 = f_FpD
  efsnmsub r3, f_FpA, f_FpB    // r3 = -((f_FpA * f_FpB) - f_FpD)
}
// PRQA S 0654, 3406, 3219, 3480 --

/// @brief              Floating point Square Root
/// @param[in]          x : float value
/// @return             result of calculating square root (sqrt)
/// @startuml
/// start
/// note right: Start
/// :returning the square root of the given value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 3429,3453 ++
// uidv7861 This file is the single source for all HW macros. It aims to centralize and reduce the usage of function-like macros.
#define SQRT_HW(x)               GlobSqrtFloat(x)
// PRQA S 3429,3453 --

/// @brief              Floating point Square Root
/// @pre                none
/// @post               none
/// @param[in]          f_FpX : float value
/// @return             result of calculating square root (sqrt)
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the square root of the given value;
/// stop
/// note right: Stop
/// @enduml
// PRQA S 0654, 3406, 3219, 3480, 6030 ++
// uidv7861 Syntax of the asm macros here is conform to the Wind River Diab Compiler
asm static volatile float32 GlobSqrtFloat(float32 f_FpX);
asm static volatile float32 GlobSqrtFloat(float32 f_FpX)
{
% reg f_FpX;
! "r3"

  efssqrt r3, f_FpX
}
// PRQA S 0654, 3406, 3219, 3480 --


#else // #if GLOB_HW_ACCELERATION


// general reference macros


// PRQA S 3435, 3453, 3456 ++
// 2017-07-31; uid40533
// summary: Msg(3:3456) Parameter 'x' will be evaluated more than once when this macro is used.
//          Msg(2:3453) A function could probably be used instead of this function-like macro.
//          Msg(2:3435) Parameter 'x' occurs more than once in the replacement list of this macro.
// reason: Caller is aware of side effect of C macro

/// @brief              Absolute value of a floating point number
/// @param[in]          x : float value
/// @return             result absolute value
/// @startuml
/// start
/// note right: Start
/// if (Is the given value real smaller than 0?) then
///     ->[true];
///     : return the negative of this value;
/// else
///     ->[false];
///     : return the value;
/// endif
/// stop
/// note right: Stop
/// @enduml
#define fABS_HW(x)               (((x) <  0.f) ? -(x) :  (x))

/// @brief              Negative absolute value of a floating point number
/// @param[in]          x : float value
/// @return             result negative absolute value
/// @startuml
/// start
/// note right: Start
/// if (Is the given value smaller than or equal to 0?) then
///     ->[true];
///     : return the value;
/// else
///     ->[false];
///     : return the negative value;
/// endif
/// stop
/// note right: Stop
/// @enduml
#define NEG_ABS_HW(x)            (((x) <= 0.f) ?  (x) : -(x))

/// @brief              Negative value of a floating point number
/// @param[in]          x : float value
/// @return             result negative value
/// @startuml
/// start
/// note right: Start
/// :flipping the highest bit returning the new value;
/// stop
/// note right: Stop
/// @enduml
#define NEG_FLOAT_HW(x)          (-(x))

/// @brief              Minimum float value of two values
/// @param[in]          x : float value
/// @param[in]          y : float value
/// @return             result Minimum of both values
/// @startuml
/// start
/// note right: Start
/// if (Is the given value X smaller than then given value Y ?) then
///     ->[true];
///     : return the value X;
/// else
///     ->[false];
///     : return the value Y;
/// endif
/// stop
/// note right: Stop
/// @enduml
#define MIN_FLOAT_HW(x,y)        (((x) < (y)) ? (x) : (y))

/// @brief              Maximum float value of two values
/// @param[in]          x : float value
/// @param[in]          y : float value
/// @return             result Maximum of both values
/// @startuml
/// start
/// note right: Start
/// if (Is the given value X bigger than then given value Y ?) then
///     ->[true];
///     : return the value X;
/// else
///     ->[false];
///     : return the value Y;
/// endif
/// stop
/// note right: Stop
/// @enduml
#define MAX_FLOAT_HW(x,y)        (((x) > (y)) ? (x) : (y))

/// @brief              Rounds and converts floating point number to a signed integer
/// @param[in]          x : float value
/// @return             converted value
/// @startuml
/// start
/// note right: Start
/// if (Is the given value X bigger or equal to 0  ?) then
///     ->[true];
///     : return the value X + 0.5 as signed integer;
/// else
///     ->[false];
///     : return the value X - 0.5 as signed integer;
/// endif
/// stop
/// note right: Stop
/// @enduml
#define ROUND_TO_INT_HW(x)       (((x) >= 0.f) ? (sint32)((x) + 0.5f) : (sint32)((x) - 0.5f))

/// @brief              Rounds and converts floating point number to an unsigned integer
/// @param[in]          x : float value
/// @return             converted value
/// @startuml
/// start
/// note right: Start
/// if (Is the given value X bigger or equal to 0  ?) then
///     ->[true];
///     : return the value X + 0.5 as unsigned integer;
/// else
///     ->[false];
///     : return the value X - 0.5 as unsigned integer;
/// endif
/// stop
/// note right: Stop
/// @enduml
#define ROUND_TO_UINT_HW(x)      (((x) >= 0.f) ? (uint32)((x) + 0.5f) : (uint32)((x) - 0.5f))

/// @brief              Floating point multiply and add: y = a * b + d
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating a * b + d
/// @startuml
/// start
/// note right: Start
/// :returning the sum of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
#define     MUL_ADD_FLOAT_HW(a,b,d)   (((a) * (b)) + (d))

/// @brief              Floating point negative multiply and add: y = -((a * b) + d)
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating -((a * b) + d)
/// @startuml
/// start
/// note right: Start
/// :returning the negative of the sum of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
#define NEG_MUL_ADD_FLOAT_HW(a,b,d) (-(((a) * (b)) + (d)))

/// @brief              Floating point multiply and subtract: y = a * b - d
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating a * b - d
/// @startuml
/// start
/// note right: Start
/// :returning the difference of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
#define     MUL_SUB_FLOAT_HW(a,b,d)   (((a) * (b)) - (d))

/// @brief              Floating point negative multiply and subtract: y = -((a * b) - d)
/// @param[in]          a : float value
/// @param[in]          b : float value
/// @param[in]          d : float value
/// @return             result of calculating -((a * b) - d)
/// @startuml
/// start
/// note right: Start
/// :returning the negative of the difference of the product between the values A and B with the value D;
/// stop
/// note right: Stop
/// @enduml
#define NEG_MUL_SUB_FLOAT_HW(a,b,d) (-(((a) * (b)) - (d)))

#if (!defined(_MSC_VER) && defined(__DCC__))

/// @brief              Floating point Square Root
/// @pre                none
/// @post               none
/// @param[in]          x : float value
/// @return             result of calculating square root (sqrt)
/// @globals            none
/// @InOutCorrelation   TBD
/// @testmethod         TBD
/// @traceability       TBD
/// @startuml
/// start
/// note right: Start
/// :returning the square root of the given value;
/// stop
/// note right: Stop
/// @enduml
float32 sqrt(float32 x);

/// @brief              Floating point Square Root
/// @param[in]          x : float value
/// @return             result of calculating square root (sqrt)
/// @startuml
/// start
/// note right: Start
/// :returning the square root of the given value;
/// stop
/// note right: Stop
/// @enduml
#define SQRT_HW(x)               (sqrt(x))

#endif // (!defined(_MSC_VER) && defined(__DCC__))

// PRQA S 3435, 3453, 3456 --

#endif // GLOB_HW_ACCELERATION

#ifdef __cplusplus
}
#endif //-- __cplusplus

//#endif //-- PLATFORM_TYPES_H
