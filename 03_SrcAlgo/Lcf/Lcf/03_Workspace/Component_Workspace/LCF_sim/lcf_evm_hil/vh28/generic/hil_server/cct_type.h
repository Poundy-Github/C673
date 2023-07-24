
/*! \file **********************************************************************

  COMPANY:                Continental Temic, PL FAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    TMS320DM643x / Windows DLL

  COMPONENT:              GLOB

  MODULNAME:              cct_type.h

  DESCRIPTION:

  AUTHOR:                 Wilfried Rau

  CREATION DATE:          20.08.2009

  VERSION:                $Revision: 1.1 $

**************************************************************************** */

#ifndef __CCT_TYPE_H_
#define __CCT_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

/*! @description: ------ signed bit field of size 32 --------------------------
@bits: 32            @accuracy:                @unit:       
@min:  -2147483647  @max: 2147483648          @refreshtime:         */
typedef signed int sbit32_t;

/*! @description: ------ signed bit field of size 16 --------------------------
@bits: 16           @accuracy:                @unit:        
@min:  -32767       @max: 32768               @refreshtime:         */
typedef signed int sbit16_t;

/*! @description: ------ signed bit field of size 8 ---------------------------
@bits: 8            @accuracy:                @unit:       
@min:  -127         @max: 128                 @refreshtime:         */
typedef signed int sbit8_t;

/* Unsigned bit-fields are useful, since it is implementation defined,
whether a 'int' bitfield is unsigned or signed. For this reason dedicated
unsigned bits are useful. See also ISO C99 6.7.2 */

/*! @description: ------ unsigned bit field of size 32 ------------------------
@bits: 32           @accuracy:                @unit:       
@min:  0            @max: 4294967295          @refreshtime:         */
typedef unsigned int ubit32_t;

/*! @description: ------ unsigned bit field of size 16 ------------------------
@bits: 16           @accuracy:                @unit:       
@min:  0            @max: 65535               @refreshtime:         */
typedef unsigned int ubit16_t;

/*! @description: ------ unsigned bit field of size 8 -------------------------
@bits: 8            @accuracy:                @unit:      
@min:  0            @max: 255                 @refreshtime:         */
typedef unsigned int ubit8_t;

/*! @description: ------ unsigned 8 bit value ---------------------------------
@bits: 8            @accuracy:                @unit:      
@min:  0            @max: 255                 @refreshtime:         */
#define UI8_MIN   0U
#define UI8_MAX   255U
typedef unsigned char ui8_t;

/*! @description: ------  signed 8 bit value  ---------------------------------                          
@bits: 8            @accuracy:                @unit:            
@min:  -128         @max: 127                 @refreshtime:         */ 
#define I8_MIN    -128
#define I8_MAX    127
typedef signed char i8_t;

/*! @description: ------ unsigned 16 bit value --------------------------------
@bits: 16           @accuracy:                @unit:            
@min:  0            @max: 65535               @refreshtime:         */ 
#define UI16_MIN    0U
#define UI16_MAX    65535U
typedef unsigned short ui16_t;

/*! @description: ------ signed 16 bit value  ---------------------------------
@bits: 16           @accuracy:                @unit:           
@min:  -32768       @max: 32767               @refreshtime:         */
#define I16_MIN   -32768
#define I16_MAX   32767
typedef signed short int i16_t;

/*! @description: ------ unsigned 32 bit value --------------------------------                   
@bits: 32           @accuracy:                @unit:            
@min:  0            @max: 4294967295          @refreshtime:         */ 
#define UI32_MIN    0UL
#define UI32_MAX    4294967295UL

typedef unsigned int ui32_t;

/*! @description: ------ signed 32 bit value ----------------------------------
@bits: 32           @accuracy:                @unit:             
@min:  -2147483648  @max: 2147483647          @refreshtime:         */  
#define I32_MIN  -2147483648L
#define I32_MAX  2147483647L
#ifdef PC_SIM
typedef signed int i32_t;
#else
typedef signed int i32_t;
#endif

/*! @description: ------ unsigned 64 bit value --------------------------------                   
@bits: 64           @accuracy:                  @unit:            
@min:  0            @max: 18446744073709551615  @refreshtime:         */ 
#define UI64_MIN    0ULL
#define UI64_MAX    18446744073709551615ULL
#ifdef PC_SIM
typedef unsigned __int64 ui64_t;
#else
typedef unsigned long long ui64_t;
#endif

/*! @description: ------ signed 64 Bit Value ----------------------------------
@bits: 64                  @accuracy:                @unit:       
@min: -9223372036854775808 @max: 9223372036854775807    @refreshtime:         */
#define I64_MIN   -9223372036854775808LL
#define I64_MAX   9223372036854775807LL
#ifdef PC_SIM
typedef signed __int64 i64_t;
#else
typedef signed long long i64_t;
#endif

/*! @description: ------ 32 Bit floating point number [see float.h] -----------
@bits: 32           @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
#define F32_MIN            1.175494351E-38F  /* see: DSP C6000 "float.h" */
#define F32_MAX            3.402823466E+38F  /* see: DSP C6000 "float.h" */
typedef float f32_t;

/*! @description: ------ 64 Bit floating point number [see float.h] -----------
@bits: 64           @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
#define F64_MIN     2.2250738585072014E-308  /* see: DSP C6000 "float.h" */
#define F64_MAX     1.7976931348623157E+308  /* see: DSP C6000 "float.h" */
typedef double f64_t;

/*! @description: ------ boolean type where FALSE = 0  and TRUE = 1 -----------
@bits: 8            @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
#ifndef FALSE
#define FALSE   (0U)
#endif
#ifndef TRUE
#define TRUE    (1U)
#endif
typedef ui8_t     bool_t;

#ifdef __cplusplus
// genuine bool type for c++
typedef bool boolean_t;
#endif

/*! @description: ------ Basic data type unsigned char ------------------------
@resolution:        @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
//typedef unsigned char  uc_t;

/*! @description: ------ Basic data type signed char --------------------------
@resolution:        @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
//typedef signed char    sc_t;

/*! @description: ------ enum -------------------------------------------------
@resolution:        @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
typedef ui8_t     enum_t;

/*! @description: ------ Pixel data used in ROI-Framework ---------------------
@resolution:        @accuracy:                @unit:       
@min:               @max:                     @refreshtime:         */
typedef ui16_t  PixelData_t;

/*lint -emacro(717,FORCE_CODE) | do ... while(0); */
#define  FORCE_CODE() asm(" nop")

#ifdef __cplusplus
}
#endif

#endif
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
