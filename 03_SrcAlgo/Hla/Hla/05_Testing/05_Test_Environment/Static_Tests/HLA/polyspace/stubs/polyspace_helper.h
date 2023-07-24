/********************************** FILE ************************************/
/* \file    polyspace_helper.h
 *
 * \brief    In combination, these macros can help to ensure that a variable used in a testdriver-file of a Polyspace-project is set to certain ranges.
 *           1. The macros are float-compatible. Instead of (A==B) the macros use (!((A<B)||(A>B))).
 *           2. The [include,include]-range-macro checks that the ranges defined satisfies the condition MAX >= MIN. If this is not true, polyspace throws a hint due to "division by zero".
 *           3. The Assert-macro does not produce an orange-finding in Polyspace. This is achieved by the exit(0)-function. The red-dotted line below the exit(0) shows, that the function does not return (what is intended) 
 *           A macro is used instead of a function to ensure that polyspace cannot pack/merge the return-values/ranges of the inlined function.
 *           
 *           Example:
 *                Code:
 *                float var = full_range_float;
 *                POLYSPACE_ASSERT( (IS_RANGE_II(var, 3, 3.5)) || (IS_VALUE(var, 7)) || (IS_RANGE(var, 10, 20)))    
 *                Result:
 *                    Variable 'var' is [3.0 .. 3.5] or 7.0 or [10.0 .. 20.0] 
 *
 * \note     Copyright (C) Continental Automotive AG
 *
 * Last Revision: $Revision: 1.1 $
 * Last Author:   $Author: Fischer, Stephan02 (uidg9447) $
 * Check in Date: $Date: 2017/02/28 15:32:25CET $
 *****************************************************************************/
#ifndef TESTDRIVER_HELPER_H_
#define TESTDRIVER_HELPER_H_
#include <stdlib.h> // needed to include exit()
#include <string.h> // needed to include memset()-function stub
#include <math.h>   // needed to include math-function stubs

#include <glob_type.h> // usually found in "..\04_Engineering\01_Source_Code\common\" to include primitive types (e.g. uint8,...)


// SET VARIABLES TO FULL-RANGE
// ===================================
// Set variables to full-range in Polyspace by using the following volatile variables.
// A volatile variable is set to '0' only to initialise it correctly.
// Each time a volatile variable is read, the corresponding value could be different. That's why Polyspace has to expect full-range.
static volatile uint8   full_range_uint8   = 0;
static volatile sint8   full_range_sint8   = 0;
static volatile uint16  full_range_uint16  = 0;
static volatile sint16  full_range_sint16  = 0;
static volatile uint32  full_range_uint32  = 0;
static volatile sint32  full_range_sint32  = 0;
static volatile uint64  full_range_uint64  = 0;
static volatile float32 full_range_float32 = 0;


// SET STRUCT-VARIABLES TO FULL-RANGE
// ===================================
// Using memset() with value 0 will set all data in the struct to 0 (and not to full-range).
// Using memset() with value !=0 will set all data in the struct to full-range. 
// Incorrect usage of memset() can corrupt complete memory in Polyspace-verification-run, leading to hard comprehensible orange/red-findings.
// Example: memset(&PARAM, 1, sizeof(PARAM));


// LIMIT RANGE OF A VARIABLE
// ===================================
// Use POLYSPACE_ASSERT-macro to limit a variable with full-range to certain ranges. Therefore use IS_RANGE, IS_VALUE macros.
#ifdef __cplusplus
 #define POLYSPACE_ASSERT(condition) if (!( condition )) { exit(0); }
#else
 #define POLYSPACE_ASSERT(condition) unchecked_assert(condition); // 'unchecked_assert' is not provided by Polyspace 2015b for CPP-projects
#endif

// II = [min,max] = min-value is Included and max-value is Included
// IE = [min,max[ = min-value is Included and max-value is Excluded
// EI = ]min,max] = min-value is Excluded and max-value is Included
// EE = ]min,max[ = min-value is Excluded and max-value is Excluded
#define IS_RANGE(PARAM, MIN, MAX)    IS_RANGE_II(PARAM, MIN, MAX)
#define IS_RANGE_II(PARAM, MIN, MAX) ((MIN>MAX)?(1/(MAX>=MIN)):(   (!((  PARAM<MIN ) || (  PARAM>MAX)) ) ? 1:0 )) 
#define IS_RANGE_IE(PARAM, MIN, MAX)                           (   (  (!(PARAM<MIN)) && (  PARAM<MAX)  ) ? 1:0 )
#define IS_RANGE_EI(PARAM, MIN, MAX)                           (   (  (  PARAM>MIN ) && (!(PARAM>MAX)) ) ? 1:0 )
#define IS_RANGE_EE(PARAM, MIN, MAX)                           (   (  (  PARAM>MIN ) && (  PARAM<MAX ) ) ? 1:0 )
#define IS_VALUE(PARAM, VALUE) ((!((PARAM<VALUE)||(PARAM>VALUE)))? 1:0 )


#endif /* TESTDRIVER_HELPER_H_ */








