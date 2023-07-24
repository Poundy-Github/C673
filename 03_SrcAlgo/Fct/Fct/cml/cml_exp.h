/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_exp.h

  DESCRIPTION:               Exponentail Functions Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             09.02.2018

  VERSION:                   $Revision: 1.10.3.2 $

  ---*/ /*---
  CHANGES:                   $Log: cml_exp.h  $
  CHANGES:                   Revision 1.10.3.2 2019/06/21 15:14:57CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.10.3.1 2019/05/27 10:58:24CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.10 2018/10/01 12:25:30CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated design parameters for log functions
  CHANGES:                   Revision 1.9 2018/09/27 11:44:32CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated review comments for exp module design parameters
  CHANGES:                   Revision 1.8 2018/09/27 10:13:14CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated design parameters for exponentail functions
  CHANGES:                   Revision 1.7 2018/09/10 09:34:55CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Code under CML_NO_RTE_DEPENDENCY has been removed.
  CHANGES:                   Revision 1.6 2018/07/13 11:09:34CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_EXP_OPTIMIZED has been defined.
  CHANGES:                   Revision 1.5 2018/07/05 10:36:42CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated function header for exp functions
  CHANGES:                   Revision 1.4 2018/07/04 10:18:30CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added F to C_EXP_100_E to make this float, as the computations using this constant were done in double precision which was not intentional
  CHANGES:                   Revision 1.3 2018/04/30 05:18:00CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added new line in the end of file
  CHANGES:                   Revision 1.2 2018/03/08 06:54:03CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Exponential, log and power functions are moved from cml_trigo.h & cml_misc.h files

**************************************************************************** */

/**
@defgroup exp EXP (Exponentail Functions Library)
  @ingroup cml
@{ */

#ifndef CML_EXP_INCLUDED
#define CML_EXP_INCLUDED      ///< To avoid multiple inclusion of the file

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_exp.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/*****************************************************************************
  QA-C
*****************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_expPower
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_exp100
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_exp
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_fastlog10
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_fastlog
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_powerOfTwo
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_xPowY
#endif /* #ifdef PRQA_SIZE_T */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

#define CML_EXP_OPTIMIZED                         1         ///< Switch to include the fast approximation of the exponential function.

#define CML_LN_10 2.3025850929940456840179914546844f        ///< Natural logarithm of 10

/*****************************************************************************
  MACROS
*****************************************************************************/

/*! optimized (exp(x)) exponential-series */
#define C_EXP_100_ROOT_E  1.28402541F     ///< sqrt(sqrt(exp(1))) with single precision for calculating exp() with 10.0 decimals of accuracy
#define C_EXP_100_A       1.00000003F     ///< Coefficient of the input in the series for calculating exp() with 10.0 decimals of accuracy
#define C_EXP_100_B       0.49999798F     ///< Coefficient of sqaure of the input in the series for calculating exp() with 10.0 decimals of accuracy
#define C_EXP_100_C       0.16670407F     ///< Coefficient of cube of the input in the series for calculating exp() with 10.0 decimals of accuracy
#define C_EXP_100_D       0.04136541F     ///< Coefficient of fourth power of the input in the series for calculating exp() with 10.0 decimals of accuracy
#define C_EXP_100_E       9.41927345E-3F   ///< Coefficient of fifth power of the input in the series for calculating exp() with 10.0 decimals of accuracy

#if (CML_EXP_OPTIMIZED)
    #define EXP_(x)    (CML_f_exp(x))          ///< Fast approximation exponential function 
#else  
  #include "math.h"
  #define EXP_(x)    ((float32) exp((float32)(x)))
#endif /* CML_EXP_OPTIMIZED */


/*****************************************************************************
  Functionname:    CML_f_expPower                                             *//*!

  \brief           calculates efficiently the pow function for positive 
                   integer powers
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Power should be a positive integer value.
                   (base value) ^ power should not exceed the range of float32. 
  \post            None        
  \globals         No global data used in this function.
  \description     The function calculates the value of any number to the power
                   of any positive integer.
                   Limitation : Since the base value (input) and output datatypes  
                   are same, the function fails to store the results for higher 
                   values when the result exceeds the float range.
                   Since the power is an integer value, repeated multplication is
                   implemented.\n
                   Relative error from C standard library: 4.9e-007F \n
                   Relative accuracy : 6.3
  \InOutCorrelation
                    @startuml
                    start
                      :Assign return value to 1;
                      :Assign factor to base value; 
                      while(power != 0uL)
                          if ((power & 1uL) != 0uL) then (YES)  
                            :Multiply return value with factor;
                          endif 
                          if (power !1uL) then (YES)  
                            :Multiply factor with factor;
                          endif 
                          :power >>= 1;
                      endwhile 
                    stop          
                   @enduml
  \param[in]       f_base : The number which we want to raise to some power
                            Supported values [Full range of float32]

  \param[in]       u_power : The integer power to raise f_base to
                             Supported values [Full range of uint32]
                             Overflow will occur if one or both input values
                             are high.

  \return          f_base raised to the u_power'th power

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9527-0003c62b    
*****************************************************************************/
extern float32 CML_f_expPower(float32 f_base, uint32 u_power);

/*****************************************************************************
  Functionname:     -CML_f_exp100                                               *//*!

  \brief           Calculates exp(x) (the natural exponential) for some 
                   number x.
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     This function calculates the exponential for any number x.
                   It adjusts the input value and calls the function GDBexp_100s
                   in turn. The function checks if the power is negative or not.
                   If negative, the function calls the core function and returns the 
                   reciprocal result. Otherwise it calls the core function and returns
                   the result as such.
  \InOutCorrelation
                   Core function is as follows.
                   e(x) is re-written as e(n/4 + y) 
                   where x = n/4 + y, n is an integer
                   and 0 < y < 1/4. 
                   We can transform this into 
                   e(n/4) * e(y) = e(1/4)^n * e(y).
                   We call these two part the integer and the fraction 
                   part, respectively.
                   The parameters of the fraction part of the 
                   approximation function are minimax-optimized for 
                   the range 0..1/4
                   Fractional part is computed using predefined constants as
                   \f[ e^y=(((((((((y \times E) + D) \times y) + C) \times y) + B) \times y) + A) \times y) + 1 \f]
                   and the integer part is calculated using function GDBexp_power.
                   @startuml
                    start
                        if (power is negative) then (YES)
                          if (CML_GOLDDUST) then (YES)
                            :p = change sign of power;
                            :inv = call CML_f_exp100s(p);
                            :result = calculate 1/inv;
                          else (NO)
                           :p = change sign of power;
                           :inv = CML_f_exp100s(p);
                           :result = call CML_f_fastInv69(inv) to get inverse;
                          endif 
                        else
                        :result = call CML_f_exp100s(power);
                        endif  
                        if (power is < -86.95F) then (YES)
                          :result = 0;
                        endif
                        :return result;
                    stop
                   @enduml
                   Behavior outside range: Outside range, this function behaves same
                   as standard C library.\n
                   Switches used: If CML_GOLDDUST is enabled, direct 1/x is used 
                   instead of using CML's inverse function.\n
                   Relative error from standard C library: 7.24e-006F \n
                   Relative accuracy : 5.1 decimal digits.
  \param[in]       f_power :  The number for which we want e^x
                              Optimal value [-MAX_VAL,..,MAX_VAL]
                              where -MAX_VAL = -86.95F & MAX_VAL = 88.7F
  \return          exp(f_power)
  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing 
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9512-0003c62b 
*****************************************************************************/
extern float32 CML_f_exp100(float32 f_power);

/************************************************************************
  Functionname:    CML_f_exp                                              *//*!

  \brief           Fast approximation exponential function with 6.9 decimals
                   accuracy.
  \pre             x < 80, IEEE754 Floating Point format.The caller must guarantee
                   that the input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     This function does a fast approximation of the 
                   exponential function with the help of some predetermined
                   constant coefficients.Let the input be x. 
                   Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.3465735903F. Given x,
                   find r and integer k such that x = k*ln2 + r,  |r| <= 0.5*ln2. 
                   Once these values are found, then the result is obtained by scaling 
                   the found values.
  \InOutCorrelation
                   @startuml
                    start  
                        if(power < -80.0F) then (YES)
                           :Exp = 0.0F;
                        else (NO)
                           :Call CML_f_MinGet to get minimum of 80 & input power;  
                           :Reinterprete the power to unsigned int;
                           :extract sign bit of input value & remove the sign bit;
                           if(Argument is outside the desired reduction range) then (YES)
                             :Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.3465735903F. 
                              Given x, find r and integer k such that x = k*ln2 + r,
                              |r| <= 0.5*ln2;
                           else (NO)
                            :Input argument is already within reduction range;
                           endif
                           :Do approximation of exp(r) by a polynom on the interval [-0.34658,+0.34658];
                           :Implement the formula f_exp = (((((((((((f_power*f_a1_c) + f_a2_c)*f_power)
                           + f_a3_c)*f_power) + f_a4_c)*f_power) + f_a5_c)*f_power) + 1.F)*f_power) + 1.F
                           Where f_a1_c = 0.0013793724F
                                 f_a2_c = 0.0083682816F
                                 f_a3_c = 0.0416686266F
                                 f_a4_c = 0.1666652424F
                                 f_a5_c = 0.4999999297F;
                           :Scale back to obtain Exp(x) = 2^k * exp(r);
                        endif
                        :Return Exp;
                    stop
                   @enduml
                   Behavior outside range: If the input is less than -80, then
                   zero will be returned, where as if it is greater than 80, the 
                   value is capped at 80.\n
                   Relative error from standard C library for input[-80, 80]: 1.182e-007F \n
                   Relative accuracy: 6.9 decimal digits.
  \param[in]       f_power: Any floating point number Supported values [-80.0, 80.0] 
  \return          Approximation of exp(f_power)
  \callsequence    Not applicable as CML is a library
  \test method     Module Testing  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9513-0003c62b
**************************************************************************** */
extern float32 CML_f_exp(float32 f_power);



/***********************************************************************
  Functionname:     CML_f_xPowY                                       *//*!

  \brief            Calculate a floating point value to the power of 
                    another floating point value (Z = X^Y)
 
  \description      Calculate a floating point value to the power of 
                    another floating point value (Z = X^Y) using
                    natural logarithm and exponential function. The 
                    function will return zero in case a zero input is 
                    received for the base.
  \InOutCorrelation
                    \f[ z = x^y \f]
                    \f[ z = e^{ln(z)} \f] So,
                    \f[ z = e^{ln(x^y)} \f]
                    \f[ z = e^{y \times ln(x)} \f]

  \param[in]        f_Base :      base value
                                  Optimal range is [C_F32_DELTA,..,MAX_VAL]
  \param[in]        f_Exponent :  exponent value
                                  Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                                  MAX_VAL is square root of maximum value of float32.

  
  \return           f_XPowY float32 result of base to the power of 
                    exponent

  \author           Matthias Kronauge

  \testmethod  
  \traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9525-0003c62b   
*************************************************************************/
extern float32 CML_f_xPowY(const float32 f_Base, const float32 f_Exponent);

/**************************************************************

  Functionname:    CML_f_powerOfTwo                          *//*!

  \brief           Calculates 2^x with x as floating point 

  \description     This function calculates the power of 2 (2^x), 
                   for any floating point value x.
                   Splits x into 2 values e.g. x = 12.34f
                   y = 2^12.34 = 2^(12 + 0.34)
                   y = 2^12 * 2^0.34 = A * B
                   Using Bit Shift to calculate A for |x| up to 31 
                   and LUT with length of 32 to look up B
                   For x values bigger than 31 this function uses
                   GDBexp_power function. For others, the integer
                   part of the power is calculated with the shift 
                   operation and the decimal part is read from the 
                   nearest value in the predefined Look up table.
                   The function make use of CML_s_GetLutIndex to get
                   Look up table index.

  \param[in]       f_value :  Input value for power
                              Optimal range [-F_MAX,.., F_MAX]
                              where F_MAX is the max value of sint32.

  \return          float value as result of 2^f_value

  \author          ulf.eike.stolle@continental-corporation.com

  \testmethod     
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9519-0003c62b  
*****************************************************************/
extern float32 CML_f_powerOfTwo(float32 f_value);

/*******************************************************************************
  Functionname:    CML_f_log2                                              *//*!

  \brief           calculate the logarithm to the base of 2
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input should not go beyond the range of 
                   float32 & should not be below 0.
  \post            None        
  \globals         No global data used in this function.
  \description     This function calculates the logarithm to the base of 2 as 
                   follows:
                   - separate exponent and mantissa of float representation.
                   - calculate log2(mantissa) with polynomial
                   - result = log2(mantissa) + exponent.
                   The function holds a precomputed polynomial coefficient set
                   for the computation of the mantissa part of the floating point 
                   number. The function first checks for positive input and then
                   does the extraction of the exponent and mantissa 
                   out of the input value. The processing happens only for the 
                   positive numbers, hence the sign bit value is not verified at 
                   the processing stage. The polynomial equation is used to 
                   process log of the mantissa part. The final result is then 
                   attained by adding the exponent to the log of the mantissa part.
                   Relative error : 5.06e-4F;
  \InOutCorrelation
                   Logarithm of mantissa is calculated as,
                   \f[ log_2(x) = \sum_{i=0}^7 (p_ix^i) \f]

                   Coeffients used :  PolyCoeff[NOF_LOG2_POLY_ELEMENTS]
                                       {-3.235209154962737f,
                                        7.085099692691060f,
                                        -7.396145690524245f,
                                        5.673515407791697f,
                                        -2.914488887785300f,
                                        0.950740445200145f,
                                        -0.178109466192688f,
                                        0.014598466017242f};
                   @startuml
                    start
                        if (input is positive) then (YES)  
                           :Store float input in union;
                           :Get exponent value by ANDing with FLOAT_EXP_MASK,
                            right shift by FLOAT_EXP_SHIFT and type casting to signed int;
                           :exp = exponent - FLOAT_EXP_OFFSET;
                           :Do the following steps to get mantissa in float.
                            Read integer input from union, AND with FLOAT_MANT_MASK.
                            Add the output with FLOAT_ZERO_HEX, store it in union as int.
                            read the float input from union;
                           :Calculate log of mantissa with series expansion upto 
                            NOF_LOG2_POLY_ELEMENTS. 
                            log2(x) = p0 + p1 * x^1 + p2 * x^2... 
                            Use CML_f_MultAdd for multiply and add;
                           :Result = mantissa + exp;
                        else if (input is negative) then (YES) 
                           :Result = FLOAT_NEG_NAN as log of negative numbers are not defined;
                        else (NO) 
                           :Result = FLOAT_NEG_INF as input is zero;
                        endif
                        :Return Result;
                     stop   
                   @enduml
  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input < 0.0f.
  \return          log2(input) with accuracy of >5 decimals
  \param[in]       f_in: value for which log2() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  \created         02.06.2015
  \changed         02.06.2015
  \author          sebastian.schwarzkopf@continental-corporation.com
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9530-0003c62b   
*******************************************************************************/
extern float32 CML_f_log2(const float32 f_in);

/*******************************************************************************
  Functionname:    CML_f_log10                                             *//*!

  \brief           calculate the logarithm to the base of 10
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input should not go beyond the range of 
                   float32 & should not be below 0.
  \post            None        
  \globals         No global data used in this function.
  \description     This function calculates the logarithm to the base of 10.
                   The function uses the CML_f_log2 , computes the logarithm 
                   value of the input to the base 2 and then multiply the result 
                   by the correction factor based on the log thoerem. The 
                   correction factor will be equal to the logarithm value of 
                   2 to the base 10 or the inverse of the logarithm value of 
                   10 to the base 2.
                   Maximum relative error from C standard Library :0.000506F;
  \InOutCorrelation
                   \f[ log_{10}(input) = log_2(input) \times log_{10}(2)  \f]

                   @startuml
                   start
                         :Result = ONE_OVER_LOG2_OF_10 * CML_f_log2(input);
                         :Return Result;
                   stop
                   @enduml

  \attention       Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  \return          log10(input) with accuracy of >5 decimals

  \param[in]       f_in: value for which log10() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.
  \created         02.06.2015
  \changed         02.06.2015
  \author          sebastian.schwarzkopf@continental-corporation.com
  \callsequence    Not applicable as CML is a library 
  \testmethod      Module Testing
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9531-0003c62b
*******************************************************************************/
extern float32 CML_f_log10(const float32 f_in);

/*******************************************************************************
  Functionname:    CML_f_ln                                                *//*!

  \brief           calculate the natural logarithm
  \pre             No input checks are made. The caller must guarantee that the 
                   input is valid. Input should not go beyond the range of 
                   float32 & should not be below 0.
  \post            None        
  \globals         No global data used in this function.
  \description     This function calculates the natural logarithm.
                   The function uses the CML_f_log2 , computes the logarithm 
                   value of the input to the base 2 and then multiply the result 
                   by the correction factor based on the log thoerem. The 
                   correction factor will be equal to the logarithm value of 
                   2 to the base e or the inverse of the logarithm value of 
                   e to the base 2.
                   Maximum Relative error :5.06e-4F
  \InOutCorrelation
                   \f[ log_e(input) = log_2(input) \times log_e(2)  \f]

                   @startuml
                   start
                         :Result =  ONE_OVER_LOG2_OF_E * CML_f_log2(input);
                         :Return Result;
                   stop
                   @enduml

  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  \return          ln(input) with accuracy of >5 decimals

  \param[in]       f_in: value for which log10() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  \created         02.06.2015
  \changed         02.06.2015
  \author          sebastian.schwarzkopf@continental-corporation.com
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9532-0003c62b
*******************************************************************************/
extern float32 CML_f_ln(const float32 f_in);

/*****************************************************************************
  Functionname:    CML_f_fastlog10                                       *//*!

  \brief           Calculates a fast decadic logarithm approximation
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input should not go beyond the range of 
                   float32 & should not be below 0.
  \post            None        
  \globals         No global data used in this function.
  \description     This algorithm uses an IEEE754 floating point 
                   decomposition to get the 2's exponent as coarse log2 
                   value. To get a closer approximation the log2 of the 
                   mantissa is fetched from a lookup table and added to the 
                   exponent. At last the log2 is multiplied by a scaling 
                   factor to get the according log10 value.
                   Maximum relative error: 4.9F
  \InOutCorrelation
                   \f[ log_{10}(input) = log_2(input) \times log_{10}(2)  \f]
                     
                    Log2 lookup table between 1 and 2: 
                    a_log2_lut [N_LUT] = 
                      {
                        0.00000000000000f,
                        0.04439411935845f,
                        0.08746284125034f,
                        0.12928301694497f,
                        0.16992500144231f,
                        0.20945336562895f,
                        0.24792751344359f,
                        0.28540221886225f,
                        0.32192809488736f,
                        0.35755200461808f,
                        0.39231742277876f,
                        0.42626475470210f,
                        0.45943161863730f,
                        0.49185309632967f,
                        0.52356195605701f,
                        0.55458885167764f,
                        0.58496250072116f,
                        0.61470984411521f,
                        0.64385618977472f,
                        0.67242534197150f,
                        0.70043971814109f,
                        0.72792045456320f,
                        0.75488750216347f,
                        0.78135971352466f,
                        0.80735492205760f,
                        0.83289001416474f,
                        0.85798099512757f,
                        0.88264304936184f,
                        0.90689059560852f,
                        0.93073733756289f,
                        0.95419631038688f,
                        0.97727992349992f
                      }

                     Unsigned integer Constants to be used:  
                     F32_EXPO_BIAS =      127u
                     F32_MANT_BITS =      23u 
                     F32_EXPO_MASK =        0x7F800000u 
                     F32_MANT_MASK =        0x007FFFFFu 
                     F32_NEG_INF   =        0xFF800000u 
                     F32_NEG_NAN  =        0xFFC00000u 
                     Floating point constants :
                     LOG10_LOG2_FACT =     0.30102999566398f 

                    @startuml
                      start
                          if (input is positive) then (YES)  
                            :Store float input in union;
                            :Get value by ANDing with F32_MANT_MASK;
                            :To get Look up table index, type cast value to float;
                            :Look up table index = Look up table index * C_LUT_MAP;
                            if (CML_OPT_c66x is enabled) then (YES)
                               :f_lut_val = Type cast look up table index to sint & then uint;
                            else
                               :f_lut_val = Type cast look up table index to uint;
                            endif
                            :Read input as unsigned int from union, AND with F32_EXPO_MASK and store back;  
                            :Read input as unsigned int from union right shift with F32_MANT_BITS and store back; 
                            :Read input as unsigned int from union, subtract from F32_EXPO_BIAS casted to sint;							
                            :Store back input as signed;	
                            :Result = (float) ( LOG10_LOG2_FACT * ( (float) input from union as signed int + f_lut_val ));
                          else if (input is negative) then (YES) 
                            :Result = FLOAT_NEG_NAN as log of negative numbers are not defined;
                          else
                            :Result = FLOAT_NEG_INF as input is zero;
                          endif
                          :Return Result;
                     stop
                    @enduml
  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  \param[in]       f_value : Value to be logarithmized to the base of 10
                             Supported range [positive values upto range of float32]

  \return          Decadic logarithm approximation of input value
  \author          Andreas Geier
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9533-0003c62b
*****************************************************************************/
extern float32 CML_f_fastlog10(float32 f_value);

/*****************************************************************************
  Functionname:    CML_f_fastlog                                         *//*!
  
  \brief           Calculates a fast natural logarithm approximation

  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input should not go beyond the range of 
                   float32 & should not be below 0.
  \post            None        
  \globals         No global data used in this function.
  \description     This function uses CML_f_fastlog10.
                   fast log10 algorithm uses an IEEE754 floating point 
                   decomposition to get the 2's exponent as coarse log2 
                   value. To get a closer approximation the log2 of the 
                   mantissa is fetched from a lookup table and added to the 
                   exponent. At last the log2 is multiplied by a scaling 
                   factor to get the according log10 value.
                   This function then, calculates the natural logarithm using 
                   conversion factor of natural logarithm of 10.
                   Maximum relative error : 5.01F
  \InOutCorrelation
                   \f[ log_e(input) = log_10(input) \times log_e(10)  \f]

                   @startuml
                   start
                         :result =  CML_LN_10 * CML_f_fastlog10(input);
                         :Return Result;
                   stop
                   @enduml

  \attention       This function does not check for the validity of input. 
                   Input should be greater than zero.
  \param[in]       f_value: Value to be logarithmized
                            Supported range [positive values upto range of float32]

  \return          Natural logarithm approximation of input value
  \callsequence    Not applicable as CML is a library
  \author          Matthias Brendel
  \testmethod      Module Testing 
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9534-0003c62b
*****************************************************************************/
extern float32 CML_f_fastlog(float32 f_value);

/*****************************************************************************
  Functionname     - CML_f_expVeryFast                                       *//*!

  \brief           Approximates exp(x) (the natural exponential) for some number x
  \pre             The caller must guarantee that the input is valid and in the 
                   range [-87.3F.. 88.7F], IEEE754 Floating Point format.
  \post            None        
  \globals         No global data used in this function.
  \description     Schraudolph (1999) adapted to 32-Bit float. \n
                   Accuracy < 4% throughout the range. The calculation is done
                   using predefined constants 12102203 and 1064866805 and bit 
                   manipulation operations. 
  \InOutCorrelation
                   Let a be the input and the constants bt M1 and M2.
                   \f[ R = (M_1 \times a) + M_2 \f]
                   The result is typecasted to signed integer and the 
                   representation is read as float. This value will be the 
                   exponential approximation. \n
                   M1 = 12102203.0F; \n
                   M2 = 1064866805.0F; \n
                   Relative error from standard C library [-87.3F, 88.7F]: 0.040F 
  \param[in]       f_a: the number for which we want e^x. 
  \return          A fast & rough approximation of exp(x)
  \callsequence    Not applicable as CML is a library
  \author          Lars Ulveland
  \testmethod      Module Testing  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9528-0003c62b
*****************************************************************************/
/* PRQA S 3240 ,3242, 3480, 3219 10 */
/* Deactivate QAF warning 3240, 3242 ,3480, 3219, Date: 2019-06-14; Reviewer: uid22555;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent. */
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: CML_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_expVeryFast(float32 f_a);
CML_INLINE float32 CML_f_expVeryFast(float32 f_a)
{
    const float32 f_MagicNumberOne = 12102203.0F;
    const float32 f_MagicNumberTwo = 1064866805.0F;
    CML_t_FloatAsSigned u;

    /* The below code implements - u.s_x = (sint32) ((f_MagicNumberOne * f_a) + f_MagicNumberTwo); */
    /* Code splitting is done to maintain consistency between CCS & MSVC.*/

    float32 fTemp1;
    float32 fTemp2;

    fTemp1 = f_MagicNumberOne * f_a;
    fTemp2 = fTemp1 + f_MagicNumberTwo;
    u.s_x = (sint32) fTemp2;
    return u.f_d;
}

/*****************************************************************************
  Functionname     - CML_f_lnVeryFast                                        *//*!

  \brief           Approximates ln(x) (the natural exponential) for some number x
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input should not go beyond the range of 
                   float32 & should not be below 0.             
  \post            None        
  \globals         No global data used in this function.
  \description     Schraudolph (1999) adapted to 32-Bit float.
                   Accuracy ~ 30% in the range 0.95..1.1
                            < 4% outside this range
                    The calculation is done using predefined constants 
                   1/12102203, 1064866805 and 1065353216 and bit 
                   manipulation operations. The function chooses the constant
                   based on the range in which the input falls in.
                   Maximum relative error: 0.384F
  \InOutCorrelation
                   Let x be the input read as a signed integer and the constants be M1 and M2.
                   \f[ r = ((float)(x - M_2)) \times M_1; \f]
                   The constant M2 is taken as 1065353216 if the input is in range 0.95-1.08.
                   Otherwise M2 is 1064866805.
  \param[in]       f_a: the number for which we want ln x
  \return          ln(x)
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module testing
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9539-0003c62b   
*****************************************************************************/
/* PRQA S  3240 , 3242, 3480, 3219 10 */
/* Deactivate QAF warning 3240, 3242, 3480, 3219, Date: 2019-06-14; Reviewer: uid22555;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent. */
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: CML_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_lnVeryFast(float32 f_a);
CML_INLINE float32 CML_f_lnVeryFast(float32 f_a)
{
    const float32 f_MagicNumberOne = 8.262958405176314e-8F;  /* 1 / 12102203 */
    const sint32  i_MagicNumberTwo = 1065353216;              /* Less accurate outside 0.95-1.08, but avoids the failure in this range. */
    const sint32  i_MagicNumberTre = 1064866805;              /* Most accurate outside the surrounding of 1. */
    const float32 f_LowerBound = 0.94F;
    const float32 f_UpperBound = 1.08F;
    float32 i_temp1;
    float32 f_temp2;
    sint32 i_MagicNumber;
    CML_t_FloatAsSigned u;
    u.f_d = f_a;
    i_MagicNumber = ((f_a > f_LowerBound) && (f_a < f_UpperBound)) ? i_MagicNumberTwo : i_MagicNumberTre;

    /* The following lines implement "(float32)(u.s_x - i_MagicNumber) * f_MagicNumberOne;"
    Modification is done to make the code consistent beween MSVC & CCS*/
/* PRQA S 4393 3 */
/* Deactivate QAF warning 4393, Date: 2019-06-18; Reviewer: uidk9586;   
     Reason: There is no risk here as there no change in data or loss of data. */   
    i_temp1 = (float32)(u.s_x - i_MagicNumber);
    f_temp2 = i_temp1 * f_MagicNumberOne;
    return f_temp2;
}

/*****************************************************************************
  Functionname:    CML_f_powToDB                                            *//*!

  \brief           convert power value to [dB]
  
  \description     This function converts the input magnitude value to [dB] by using 
                   CML_f_log10(). The function uses the conversion factor to derive 
                   the result.
  \InOutCorrelation
                   \f[ r = D \times log_10(input) \f]
                   where  D is the conversion factor equal to 10.
  
  \param[in]       f_ratio: is the input power ratio value
  
  \return          [dB] value of input
  
  \author          sebastian.schwarzkopf@continental-corporation.com

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9543-0003c62b   
*****************************************************************************/
/* PRQA S 3240 , 3242, 3480, 3219 10 */
/* Deactivate QAF warning 3240, 3242, 3219, 3480, Date: 2019-06-14; Reviewer: uid22555;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent. */
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: S. Schwarzkopf; Date: 14.10.2014; 
   Reason: CML_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_powToDB(float32 f_ratio);
CML_INLINE float32 CML_f_powToDB(float32 f_ratio)
{
    return CML_DBPOW_FACTOR * CML_f_log10(f_ratio);
} /* CML_f_powToDB() */


/*****************************************************************************
  Functionname:    CML_f_magToDB                                            *//*!

  \brief           convert magnitude value to [dB]

  \description     This function converts the input magnitude ratio to [dB] by using 
                   CML_f_log10(). The function uses the conversion factor to derive 
                   the result.
  \InOutCorrelation
                   \f[ r = D \times log_10(input) \f]
                   where  D is the conversion factor equal to 20.

  \param[in]       f_ratio: is the input magnitude ratio value

  \return          [dB] value of input

  \author          sebastian.schwarzkopf@continental-corporation.com

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9542-0003c62b
*****************************************************************************/
/* PRQA S 3240, 3242, 3480, 3219 10 */
/* Deactivate QAF warning 3240, 3242 ,3480, 3219, Date: 2019-06-14; Reviewer: uid22555;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: S. Schwarzkopf; Date: 14.10.2014; 
   Reason: CML_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_magToDB(float32 f_ratio);
CML_INLINE float32 CML_f_magToDB(float32 f_ratio)
{
    return CML_DBMAG_FACTOR * CML_f_log10(f_ratio);
} /* CML_f_MagToDB() */

#endif /* #ifndef CML_EXP_INCLUDED */

/** @} end defgroup */

