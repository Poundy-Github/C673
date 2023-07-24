// COMPANY:   Continental Automotive
// COMPONENT: TYPES
// VERSION:   $Revision: 1.40 $
/// @file     01_Source_Code\common\GLOB\glob_defs.h
/// @brief    Global constants
// Note that typedefs for uint8, uint16 etc are not available in this file
// definitions using such typedefs have to be done in another file

#ifndef GLOB_DEFS_H
#define GLOB_DEFS_H

#ifdef __cplusplus
// PRQA S ALL ++
// 2021-05-21; uie23485
// Summary:
// Message(4:1020) Avoid Macros
// Message(4:5174) Macro definition of standard library NULL
// Message(4:5181) Macro definition of standard library NULL
// Message(4:5050) Literal has lower case letter in suffix
// Reason:         QACPP tool doesn't recognize the extern C command
extern "C"
{
#endif //-- __cplusplus

/// Description: Null pointer for initialization / comparison \n
/// Range:       constant void* 0
#ifndef NULL
#ifdef  __cplusplus
#define NULL           (0)
#else //-- __cplusplus
// PRQA S 4600 2
// uidv7861 This definition is guarded with ifndef to prevent duplicates.
#define NULL           ((void *)0)
#endif //-- __cplusplus
#endif //-- NULL


/// Description: Gravity constant \n
/// Range:       constant 9.80665 \n
/// Unit:        none
#define C_GRAVITY ((float32) 9.80665f)

/// Description: Constant conversion rate for km/h <-> m/s \n
/// Range:       constant 3.6 \n
/// Unit:        none
#ifndef C_KMH_MS
#define C_KMH_MS ((float32) 3.6f)
#endif

/// Description: Constant conversion rate for m/s -> km/h \n
/// Range:       constant 0.277778 \n
/// Unit:        none
#ifndef C_MS_KMH
#define C_MS_KMH ((float32) 0.277778f)
#endif

/// Description: Constant speed of light in a vacuum (c) \n
/// Range:       constant 299792458.0 \n
/// Unit:        m/s
#define C_V_LIGHT ((float32) 299792458.0f)

/// Description: Constant conversion millisecond <-> second \n
/// Range:       constant 1000.0F \n
/// Unit:        none
#ifdef C_MILLISEC_SEC
#undef C_MILLISEC_SEC
#endif
#define C_MILLISEC_SEC (1000.0F)

/// Description: Constant (high) denoting a set bit \n
/// Range:       constant 1 \n
/// Unit:        none
#define C_BIT_SET ((uint8)1u)

/// Description: Constant (low) denoting an unset bit \n
/// Range:       constant 0 \n
/// Unit:        none
#define C_BIT_RESET ((uint8)0u)

/// Description: Constant (high) denoting a set port pin \n
/// Range:       constant 1 \n
/// Unit:        none
#define C_PIN_SET ((uint8)1u)

/// Description: Constant (low) denoting an unset port pin \n
/// Range:       constant 0 \n
/// Unit:        none
#define C_PIN_RESET ((uint8)0u)

/// Description: Constant (high) denoting a set flag \n
/// Range:       constant 1 \n
/// Unit:        none
#define FLAG_SET ((uint8)1u)

/// Description: Constant (low) denoting an unset flag \n
/// Range:       constant 0 \n
/// Unit:        none
#define FLAG_RESET ((uint8)0u)

/// Description: Constant (low) denoting something inactive \n
///              Intentionally not using 0u because it would not work in constructs like \n
///               @code{.c}
///                 #if (FEATURE == SWITCH_OFF)
///               @endcode
/// Range:       constant 0
#ifdef SWITCH_OFF
#undef SWITCH_OFF
#endif
#define SWITCH_OFF 0

/// Description: Constant (high) denoting something active \n
///              Intentionally not using 1u because it would not work in constructs like \n
///               @code{.c}
///                 #if (FEATURE == SWITCH_ON)
///               @endcode
/// Range:       constant 1
#ifdef SWITCH_ON
#undef SWITCH_ON
#endif
#define SWITCH_ON 1

/// Description: Constant (low) denoting something inactive \n
///              Intentionally not using 0u because it would not work in constructs like \n
///               @code{.c}
///                 #if (FEATURE == ALGO_SwitchOff)
///               @endcode
/// Range:       constant 0
#ifdef ALGO_SwitchOff
#undef ALGO_SwitchOff
#endif
#define ALGO_SwitchOff 0

/// Description: Constant (high) denoting something active \n
///              Intentionally not using 1u because it would not work in constructs like \n
///               @code{.c}
///                 #if (FEATURE == ALGO_SwitchOn)
///               @endcode
/// Range:       constant 1
#ifdef ALGO_SwitchOn
#undef ALGO_SwitchOn
#endif
#define ALGO_SwitchOn 1

//-- The following 3 macros (CFG_OFF, CFG_ON and CFG_ENABLED) are from coding_guideline.docx: R 246 (C, C++, recommended)
// PRQA S 3410 ++
// 2017-07-10; uid40533
// summary: Msg(3:3410) Macro parameter not enclosed in ().
// reason: Missing bracket comes with another macro
// PRQA S 3411 ++
// 2017-07-10; uid40533
// summary: Msg(3:3411) Macro defined with unbalanced brackets, parentheses or braces.
// reason: This macros style is recommended explicitly in coding guideline.
// PRQA S 1020 ++
// 2017-07-06; uid42962
// summary: Msg(3:1020) Avoid macros.
//          Use constants, enumerators, typedefs or inline functions instead. MISRA-C++ Rules 16-0-4, 16-2-1
// reason: Macros used in #if statements -> they cannot be changed to constants

/// Description: Define for disabling feature flag. The "(" will match the ")" of the CFG_ENABLED macro.
#define CFG_OFF (0

/// Description: Define for enabling feature flag. The "(" will match the ")" of the CFG_ENABLED macro.
#define CFG_ON (1

/// Sets a value in a secure way (matching CFG_ON/CFG_OFF but with arbitrary
/// values). The "(" will match the ")" of the CFG_EVAL macro.
#define CFG_SET(value) (value

/// Description: Definition for checking feature configuration. The usage of this definition ensures that \n
///              the configuration flag to be checked is also defined as either CFG_ON or CFG_OFF. \n
/// @param[in] feature : Flag to be checked (Range: CFG_OFF or CFG_ON)
///
/// @code{.c}
///       #define FEATURE_FLAG CFG_ON
/// @endcode
///
/// @code{.c}
///       #if CFG_ENABLED( FEATURE_FLAG )
///           // flag enabled. do something
///       #else
///           // flag disabled. do something else.
///       #endif
/// @endcode
#define   CFG_ENABLED(feature) (feature))

/// Evaluates a value that is expected to be set via CFG_SET(). If the value has
/// never been set, this will result in a compilation error.
/// @param[in] feature : Flag to be evaluated (must be set via CFG_SET())
/// @par Setup
/// @code{.c}
///       #define CONFIGURATION_A 1
///       #define CONFIGURATION_B 2
///       #define CONFIGURATION_FLAG CFG_SET(CONFIGURATION_B)
/// @endcode
///
/// @par Usage
/// @code{.c}
///       #if(CFG_EVAL(CONFIGURATION_FLAG) == CONFIGURATION_B)
///           // CONFIGURATION_B is active
///       #else
///           // CONFIGURATION_B is inactive
///           // You could check for CONFIGURATION_A or something else.
///       #endif
/// @endcode
#define   CFG_EVAL(feature) (feature))

// PRQA S 1020 --
// PRQA S 3410 --
// PRQA S 3411 --


/// Description: Define for compiler messages
/// @param[in] x: The message to be displayed (Range: constant string)
#define BUILD_WARNING(x)   message(__FILE__"("STRING_QUOTE(__LINE__)"): !! ERROR !!: " x)

/// Description: Define for compiler messages
/// @param[in] x: The message to be displayed (Range: constant string)
#define COMPILEMSG(x)   message(__FILE__"("STRING_QUOTE(__LINE__)"): TODO: " x)

/// Description:  Utility macro to get the high byte from a 16 bit value
/// @param[in] x : The 16-bit source value (Range: Signed or unsigned 16-bit integer)
/// @return The 8-bit high byte (Range: 0x00...0xFF)
#define GET_UI16_HIGHBYTE(x)   (uint8)(((x) >> 8) & 0xFFu)

/// Description: Utility macro to get the low byte from a 16 bit value
/// Return value:     - Description: The 8-bit low byte (Range: 0x00...0xFF)
/// @param[in] x : The 16-bit source value (Range: Signed or unsigned 16-bit integer)
#define GET_UI16_LOWBYTE(x)   (uint8)((x) & 0xFFu)

/// Description: Utility macro to get the highest byte from a 32-bit value
/// @param[in] x: The 32-bit source value (Range: Signed or unsigned 32-bit integer)
/// @return The 8-bit high byte (Range: 0x00...0xFF)
#define GET_UI32_HIGHBYTE(x)   (uint8)(((x) >> 24) & 0xFFu)

/// Description: Utility macro to get the second highest byte from a 32-bit value
/// @param[in] x: The 32-bit source value (Range: Signed or unsigned 32-bit integer)
/// @return The second highest byte (Range: 0x00...0xFF)
#define GET_UI32_HMIDBYTE(x)   (uint8)(((x) >> 16) & 0xFFu)

/// Description: Utility macro to get the second lowest byte from a 32-bit value
/// @param[in] x : The 32-bit source value (Range: Signed or unsigned 32-bit integer)
/// @return The second lowest byte (Range: 0x00...0xFF)
#define GET_UI32_LMIDBYTE(x)   (uint8)(((x) >> 8) & 0xFFu)

/// Description: Utility macro to get the lowest byte from a 32-bit value
/// @param[in] x : The 32-bit source value (Range: Signed or unsigned 32-bit integer)
/// @return The lowest byte (Range: 0x00...0xFF)
#define GET_UI32_LOWBYTE(x)   (uint8)((x) & 0xFFu)

/// Description: Unsupported function. Generates error at compile time
/// @param[in] ELCNT : Dummy variable (function is unsupported)
/// @param[in] ELSIZE : Dummy variable (function is unsupported)
/// @return void
#define ROUND_TABLE_TO_MULTIPLE_OF_128(ELCNT, ELSIZE)   (error - unknown platform!)

/// Description: Unsupported function. Generates error at compile time
/// @param[in] ELCNT : Dummy variable (function is unsupported)
/// @param[in] ELSIZE: Dummy variable (function is unsupported)
/// @return void
#define ROUND_TABLE_TO_MULTIPLE_OF_CACHELINE(ELCNT, ELSIZE)   (error - unknown platform!)

/// Description: Rounds a number to a multiple of 128
/// @param[in] ELCNT: The number to round (Range: Any float or integer value)
/// @return Description: The closest multiple (Range: Depends on the format of the input value)
#define ROUND_TO_MULTIPLE_OF_128(ELCNT)   ROUND_TO_MULTIPLE_OF_N(ELCNT, 128)

/// Description: Rounds a number to a multiple of 16
/// @param[in] ELCNT : The number to round (Range: Any float or integer value)
/// @return: The closest multiple (Range: Depends on the format of the input value)
#define ROUND_TO_MULTIPLE_OF_16(ELCNT)   ROUND_TO_MULTIPLE_OF_N(ELCNT, 16)

/// Description: Rounds a number to a multiple of 32
/// @param[in] ELCNT : The number to round (Range: Any float or integer value)
/// @return The closest multiple (Range: Depends on the format of the input value)
#define ROUND_TO_MULTIPLE_OF_32(ELCNT)   ROUND_TO_MULTIPLE_OF_N(ELCNT, 32)

/// Description:      Rounds a number to a multiple of 64
/// @param[in] ELCNT : The number to round (Range: Any float or integer value)
/// @return The closest multiple (Range: Depends on the format of the input value)
#define ROUND_TO_MULTIPLE_OF_64(ELCNT)   ROUND_TO_MULTIPLE_OF_N(ELCNT, 64)

/// Description: Rounds a number to a multiple of 8
/// @param[in] ELCNT : The number to round (Range: Any float or integer value)
/// @return: The closest multiple (Range: Depends on the format of the input value)
#define ROUND_TO_MULTIPLE_OF_8(ELCNT)   ROUND_TO_MULTIPLE_OF_N(ELCNT, 8)

/// Description: Unsupported function. Generates error at compile time
/// @param{in] ELCNT : Dummy variable (function is unsupported)
/// @return void
#define ROUND_TO_MULTIPLE_OF_CACHELINE(ELCNT)   (error - unknown platform!)

/// Description: Unsupported function. Generates error at compile time
/// @param[in] ELCNT : Dummy variable (function is unsupported)
/// @return void
#define ROUND_TO_MULTIPLE_OF_CALIGN(ELCNT)   (error - unknown platform!)

/// Description: Rounds a number to a desired multiple
/// @param[in] ELCNT : The number to round (Range: Any float or integer value)
/// @param[in] _N : The multiple desired (Range: Any float or integer value)
/// @return The closest multiple (Range: Depends on the format of the input value)
// PRQA S 3456  2
// uidv7791: Multiple usage of parameter is accepted
#define ROUND_TO_MULTIPLE_OF_N(ELCNT, _N)   ( ( ( (ELCNT) + (_N) - 1 ) / (_N)) * (_N) )

/// Description: Internally used macro, never use outside of this file
/// @param[in] x : The string to quote
/// @return The string prefixed with a '#'
#ifndef STRING_INTERNAL_QUOTE
#define STRING_INTERNAL_QUOTE(x)   #x
#endif

/// Description: Wrapper for STIRNG_INTERNAL_QUOTE
/// @param[in] x : The string to quote
/// @return The string prefixed with a '#'
#ifndef STRING_QUOTE
#define STRING_QUOTE(x)   STRING_INTERNAL_QUOTE(x)
#endif

/// Description: Wrapper for STIRNG_INTERNAL_QUOTE
/// @param[in] x: The string to quote
/// @return The string prefixed with a '#'
#ifndef ALGO_StringQuote
#define ALGO_StringQuote(x)   STRING_INTERNAL_QUOTE(x)
#endif

/// Description: Calculates number of elements in array
/// @param{in] a : array
/// @retrun number of elements in array
// PRQA S 3456 2
// uidv7791: Multiple usage of parameter is accepted
#define ARRAY_LEN(a)   (sizeof( a ) / sizeof(*(a)))

/// Description: Absolute value for an integer
/// @param[in]   x : integer value
/// @return      absolute value
// PRQA S 3456 4
// 2018-06-22; uidw1725
// summary: Msg(3:3456) Parameter 'x' will be evaluated more than once when this macro is used.
// reason: get Absolute value for an integer
#define ABS(x)         (((x)<(0))?(-(x)):(x))

/// Description:
///   The define ENABLE_COURAGE_TEST is set in Courage module test environment only in order overcome the
///   limitation, that Courage can not see and evaluate static objects
///   The define GLOB_STATIC shall than be used in the components instead of the key word 'static', e.g. Dgm.c
#ifdef ENABLE_COURAGE_TEST
  #define GLOB_STATIC
#else
  // PRQA S 3414 4
  // 2019-11-28; uidw1725
  // summary: Msg(3:3414) Macro defines a storage-class or function specifier keyword.
  // reason: no static used while unit tests are executed, see description above
  #define GLOB_STATIC static
#endif

#ifdef __cplusplus
}
// PRQA S ALL --
#endif //-- __cplusplus

#endif //-- GLOB_DEFS_H
