/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_float16_util.h

DESCRIPTION:               methods for float 16 conversion 

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/11/13 15:05:33CET $

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            1.4

**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_FLOAT16_UTIL_H_INCLUDED
#define HEAD_FLOAT16_UTIL_H_INCLUDED

/*! @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*! @endcond */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          Defines a "float16" (half precision) type 
                    @unit f16_t
    */
typedef uint16 f16_t; 


/*****************************************************************************
  CONSTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: Veerashettappa.Nagaraja; Date: 06.07.2018;  
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406, 3242, 3240 ALGO_INLINES */

ALGO_INLINE f16_t HEADConvf32Tof16(float32 fOrig);
ALGO_INLINE float32 HEADConvf16Tof32(f16_t const h);

/*<------ FLOATING-POINT 16-BIT / 32-BIT FORMAT CONVERSION ------
  
  IEEE 754 half precision binary floating-point format
  ----------------------------------------------------
  15   10         0
  |    |         |
  SEEEEEFFFFFFFFFF
  -> S: Sign bit: 1 bit 
  -> E: Exponent width: 5 bits 
  -> F: Significant precision: 11 (10 explicitly stored) 

  Exponent encoding
  Exponent is encoded using an offset binary representation, with the zero offset being 15; 
  also known as exponent bias in the IEEE 754 standard.

  Exponent bias := 0Fh = 15 

  Emin = 01h - 0Fh = -14 
  Emax = 1Eh - 0Fh =  15 

  Thus, as defined by the offset binary representation, in order to get the true exponent the offset 
  of 15 has to be subtracted from the stored exponent. The stored exponents 0x00 and 0x1f are 
  interpreted specially.

  Exponent  | Significant | Significant        |  Equation 
            |    zero     |   non-zero         |
  --------------------------------------------------------------
  00h       | zero, -0    | subnormal numbers  | (-1)^signbit * 2^-14 * 0.significandbitsb
  01h...1Eh |        normalized value          | (-1)^signbit * 2^(exponent-15) * 1.significandbitsb
  1Fh       | ±infinity   | NaN(quiet, signal) | 


  The minimum strictly positive (subnormal) value is 2^-24 = 5.96 * 10^-8
  The minimum positive normal value is 2^-14 = 6.10 * 10^-5
  The maximum representable value is (2 - 2^-10) * 2^15 = 65504.


  IEEE 754 single precision binary floating-point format
  ------------------------------------------------------
  31      23                     0
  |       |                      |
  SEEEEEEEEFFFFFFFFFFFFFFFFFFFFFFF

  -> S: Sign bit: 1 bit 
  -> E: Exponent width: 8 bits 
  -> F: Significant precision: 24 (23 explicitly stored)

  Exponent encoding
  Exponent is encoded using an offset binary representation, with the zero offset being 127; 
  also known as exponent bias in the IEEE 754 standard.

  Emin = 01h - 7Fh = -126 
  Emax = FEh - 7Fh =  127 
  Exponent bias = 7Fh = 127 

  Thus, in order to get the true exponent as defined by the offset binary representation, 
  the offset of 127 has to be subtracted from the stored exponent.
  The stored exponents 00H and FFH are interpreted specially.

  Exponent  | Significant | Significand        |  Equation 
            |    zero     |   non-zero         |
  --------------------------------------------------------------
  00h       |  zero, -0   | subnormal numbers  | (-1)^signbits * 2^-126 * 0.significandbitsb 
  01h...FEh |        normalized value          | (-1)^signbits * 2^exponentbits^-127 * 1.significandbitsb
  FFh       | ±infinity   | NaN (quiet,signal) | 

  The minimum positive (subnormal) value is 2^-149 = 1.4 * 10^-45
  The minimum positive normal value is 2^-126 = 1.18 * 10^-38
  The maximum representable value is (2-2^-23) * 2^127 = 3.4 * 10^38

------ FLOATING-POINT 16-BIT / 32-BIT FORMAT CONVERSION ------>*/

/*! @brief       Fixed float max value
 
*/
#define HEADPARFCT_FLOAT_MAX              (0xFFE0)

/* Half precision floating point defines */


/*! @brief       Half precision sign shift value

*/
#define HEADPARFCT_SIGN_SHIFT             (0x0Fu)

/*! @brief       Half precision exponent maximum value

*/
#define HEADPARFCT_EXPONENT_MAXVAL        (0x1Fu)

/*! @brief       Half precision exponent mask value

*/
#define HEADPARFCT_EXPONENT_MASK          (0x7C00u)

/*! @brief       Half precision exponent shift value

*/
#define HEADPARFCT_EXPONENT_SHIFT         (0x0Au)

/*! @brief       Half precision exponent bias value

*/
#define HEADPARFCT_EXPONENT_BIAS          (0x0F)

/*! @brief       Half precision mantissa mask value

*/
#define HEADPARFCT_MANTISSA_MASK          (0x03FFu)


/* Single precision floating point defines */

/*! @brief       Single precision sign shift value

*/
#define HEADPARFCT_FLOAT_SIGN_SHIFT       (0x1Fu)

/*! @brief       Single precision exponent maximum value

*/
#define HEADPARFCT_FLOAT_EXPONENT_MAXVAL  (0xFFu)

/*! @brief       Single precision exponent shift value

*/
#define HEADPARFCT_FLOAT_EXPONENT_SHIFT   (0x17u)

/*! @brief       Single precision exponent bias value

*/
#define HEADPARFCT_FLOAT_EXPONENT_BIAS    (0x7F)


/*************************************************************************************************************************
  Functionname:         HEADConvf32Tof16                                                                            */ /*!

  @brief                returns a 16bit float (1-10-5) out of a 32bit float

  @description          returns a 16bit float (1-10-5) out of a 32bit float
                        Does only work for floating point format based on IEEE754

  @return               f16_t : 16-Bit Float value 

  @param[in]            fOrig : 32-Bit Float value which need to be converted to 16-Bit float
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE f16_t HEADConvf32Tof16(float32 fOrig)
{
  f16_t raw;
  /*PRQA S 0314 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: Intended behaviour*/
  const uint32 u = *((uint32 *)(void *)(&fOrig)); 
  const uint32 sign = ((u>>HEADPARFCT_FLOAT_SIGN_SHIFT)<<HEADPARFCT_SIGN_SHIFT);
  const uint32 biasExp = (u>>HEADPARFCT_FLOAT_EXPONENT_SHIFT) & HEADPARFCT_FLOAT_EXPONENT_MAXVAL;
  const sint32 exponent = (sint32)biasExp - HEADPARFCT_FLOAT_EXPONENT_BIAS;
  const uint32 mantissa = ((u>>(HEADPARFCT_FLOAT_EXPONENT_SHIFT - HEADPARFCT_EXPONENT_SHIFT))) & HEADPARFCT_MANTISSA_MASK;
  
  if (exponent == -HEADPARFCT_FLOAT_EXPONENT_BIAS) 
  {
    /* Single precision value is subnormal number => set half precision value to zero and use sign */
    raw = (f16_t)sign;
  } 
  else if ((exponent + HEADPARFCT_EXPONENT_BIAS) < 0) 
  {
    /* Singe precision exponent is too small to fit into half precision format (<E16min) => set half 
       precision value to zero and use sign */
    raw = (f16_t)sign;
  }
  else if (exponent >= (sint32)(HEADPARFCT_FLOAT_EXPONENT_MAXVAL - (uint32)HEADPARFCT_FLOAT_EXPONENT_BIAS)) 
  {
    /* Single precision value is infinity (E32_bias == 0xFF) => set half precision value to infinity and use 
       sign and mantissa */
    raw = (f16_t)((sign | HEADPARFCT_EXPONENT_MASK | mantissa));
  } 
  else if (exponent >= (sint32)(HEADPARFCT_EXPONENT_MAXVAL - (uint32)HEADPARFCT_EXPONENT_BIAS)) 
  {
    /* Single precision exponent is too large to fit into half precision format => set half precision value to infinity 
       and use sign */
    raw = (f16_t)((sign | HEADPARFCT_EXPONENT_MASK));
  } 
  else 
  {
    /* Normal floating point values which can be represented as half precision */
    sint32 exp16 = (exponent + HEADPARFCT_EXPONENT_BIAS);
    raw = (f16_t)(sign | ((uint32)exp16<<HEADPARFCT_EXPONENT_SHIFT) | mantissa);
  }
  return raw;
}

/*************************************************************************************************************************
  Functionname:         HEADConvf16Tof32                                                                            */ /*!

  @brief                returns a 32bit float  out of a 16bit float (1-10-5)

  @description          returns a 32bit float  out of a 16bit float (1-10-5)

  @return               float32 : 32-Bit Float value 

  @param[in]            h : 16-Bit Float value which need to be converted to 32-Bit float
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
ALGO_INLINE float32 HEADConvf16Tof32(f16_t const h)
{
  const uint32 exponent_raw = ((uint32)h>>HEADPARFCT_EXPONENT_SHIFT) & HEADPARFCT_EXPONENT_MAXVAL;
  const uint32 mantissa_raw = ((uint32)h & HEADPARFCT_MANTISSA_MASK);
  uint32 u;

  sint32 exponent = (sint32) exponent_raw + (HEADPARFCT_FLOAT_EXPONENT_BIAS - HEADPARFCT_EXPONENT_BIAS);
  const sint32 mantissa = (sint32) mantissa_raw;

  if ((exponent == (HEADPARFCT_FLOAT_EXPONENT_BIAS - HEADPARFCT_EXPONENT_BIAS)) && (mantissa == 0))
  {
    /* Half precision value is subnormal and mantissa keeps no value => set exponent to zero. 
       If mantissa is non zero:  2^-15 * 1.significandbitsb (= 2^-14 * 0.significandbitsb) */
    exponent = 0;
  }
  else if (exponent == (sint32)((uint32)(HEADPARFCT_FLOAT_EXPONENT_BIAS - HEADPARFCT_EXPONENT_BIAS) + HEADPARFCT_EXPONENT_MAXVAL)) 
  {
    /* Half precision vale is infinity => set single precision exponent to infinity */
    exponent = (sint32)HEADPARFCT_FLOAT_EXPONENT_MAXVAL;
  }
  else
  {
    /* exponent can directly used for single precision format */
  }
  
  /* Binary format conversion */
  u = (  ((((uint32)h)>>HEADPARFCT_SIGN_SHIFT))<<HEADPARFCT_FLOAT_SIGN_SHIFT)          /* sign bit */
        | (((uint32)exponent)<<HEADPARFCT_FLOAT_EXPONENT_SHIFT)                                 /* exponent */
        | (((uint32)mantissa)<<(HEADPARFCT_FLOAT_EXPONENT_SHIFT - HEADPARFCT_EXPONENT_SHIFT));  /* mantissa */

  /* cast return value to machine floating point format */
  /*PRQA S 0314 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: Intended behaviour*/
  return *((float32 *)(void *)(&u));
}

/*! @cond */
#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
/*! @endcond */
/* PRQA L:ALGO_INLINES */
#endif
/**@}*/

