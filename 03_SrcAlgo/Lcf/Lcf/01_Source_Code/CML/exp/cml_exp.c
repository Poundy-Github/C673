/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_exp.c

  DESCRIPTION:               Exponentail Functions Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             09.02.2018

  VERSION:                   $Revision: 1.11.1.3 $

    ---*/ /*---

  CHANGES:                   $Log: cml_exp.c  $
  CHANGES:                   Revision 1.11.1.3 2020/01/08 11:30:01CET Thomas, Jyothy (uid22555) 
  CHANGES:                   corrected alignment
  CHANGES:                   Revision 1.11.1.2 2019/11/22 07:40:39CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Checkin the changes in exponential functions for ECU-SIL bit exactness on A15
  CHANGES:                   Revision 1.11.1.1 2019/06/21 15:14:56CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.11 2018/09/27 10:05:17CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated design parameters of CML_f_exp100s
  CHANGES:                   Revision 1.10 2018/09/21 08:36:50CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Corrected minimum value of power works in cml_exp_100() to -86.95F
  CHANGES:                   Revision 1.9 2018/09/20 12:49:52CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated supported range of cml_exp100 function as per review comments
  CHANGES:                   Revision 1.8 2018/09/17 14:10:39CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Made CML_f_exp100 output zero if input is < -87.0F
  CHANGES:                   Revision 1.7 2018/07/30 07:43:24CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Floating point masks have been removed.
  CHANGES:                   Revision 1.6 2018/07/13 11:09:34CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_EXP_OPTIMIZED has been defined.
  CHANGES:                   Revision 1.5 2018/07/09 11:05:46CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Defined f_temp variable only when CML_GOLDDUST is not defined
  CHANGES:                   Revision 1.4 2018/07/05 10:35:44CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated function header for exp functions
  CHANGES:                   Revision 1.3 2018/07/04 10:25:22CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added fast division and optimizations under switches CML_OPT_c66x & CML_GOLDDUST
  CHANGES:                   Revision 1.2 2018/03/08 06:54:55CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Exponential, log and power functions are moved from cml_trigo.c & cml_misc.c files

**************************************************************************** */

/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-11; Reviewer: uid22555;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
  CONSTANTS
*****************************************************************************/


/*****************************************************************************
 TYPES
*****************************************************************************/
/* Deactivate QA-C warning 3629; Reviewer: S. Schwarzkopf; Date: 04.12.2014; 
   Reason: Union is intended to provide access to float value for manipulation. 
   Review-ID: */
/* PRQA S 3629 5 */
/// \brief     Access Union to manipulate float values
/// \details   The Union holds a float value and an unsigned integer. This can be used to manipulate the float values.
typedef union
{
    float32 f_val;  ///< float representation 
    uint32  u_val;  ///< unsigned integer / hexadecimal representation
} t_floatAccess;  


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
static float32 CML_f_exp100s(float32 f_power);

/*****************************************************************************
  Functionname:    CML_f_expPower                                         */ /*!

  @brief           calculates efficiently the pow function for positive 
                   integer powers

  @description     The function calculates the value of any number to the power
                   of any positive integer.
                   Limitation : Since the base value (input) and output datatypes  
                   are same, the function fails to store the results for higher 
                   values when the result exceeds the float range.

  @param[in]       f_base : the number which we want to raise to some power
                            Supported values [Full range of float32]

  @param[in]       u_power : the integer power to raise f_base to
                             Supported values [Full range of uint32]
                             Overflow will occur if one or both input values
                             are high.


  @return          f_base raised to the u_power'th power

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_expPower(float32 f_base, uint32 u_power)
{
    /*--- VARIABLES ---*/
    float32 f_retval;
    float32 f_factor;

    f_retval = 1.0F;
    f_factor = f_base;

    while (u_power != 0uL)
    {
        if ((u_power & 1uL) != 0uL)
        {
            f_retval *= f_factor;
        }
        if (u_power != 1uL)
        {
            f_factor *= f_factor;
        }
        u_power >>= 1;
    }

    return f_retval;
}

/*****************************************************************************
  Functionname:    CML_f_exp100s                                          */ /*!

  @brief           Calculates exp(x) (the natural exponential) for any positive 
                   floating point number.
  @pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Only +ve floating point number can be passed
                   as input. 
  @post            None        
  @globals         No global data used in this function.
  @description     This is a static function to calculate exp(x), which is used
                   by any other exponential functions in CML exp module.
                   
                   Relative error from standard C library for input[0, 80.0F]: 7.2e-006 \n
                   Relative accuracy: 5.1 decimal digits.
  @InOutCorrelation     
                   Method:
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
                   (((((((((y * E) + D) * y) + C) * y) + B) * y) + A) * y) + 1;
                   and the integer part is calculated using function CML_f_expPower.

  @param[in]       f_power :  The positive number for which we want e^x (exp(f_power))
                              Optimal value [0,..,MAX_VAL]
                              where MAX_VAL = 88.7F

  @return          exp(f_power)
  @callsequence    Not applicable as CML is a library.
  @testmethod      Tested on MSVC
  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9526-0003c62b
*****************************************************************************/
static float32 CML_f_exp100s(float32 f_power)
{
    /*--- VARIABLES ---*/
    float32 f_fracpart;
    float32 f_intpart;
    uint32 u_power;
    float32 f_temp1, f_temp2, f_temp3;

    f_power   *= 4.0F;
#ifdef CML_OPT_c66x
/* This type casting is to avoid _fixfu function call in c66x */
    u_power    = (uint32)(sint32)f_power;
#else
    u_power    = (uint32) f_power;
#endif
    f_power   -= (float32)u_power;
    f_power   *= 0.25F;

   /* The below lines implement 
    f_fracpart = (float32) (((((((((f_power * C_EXP_100_E) + C_EXP_100_D) 
    * f_power) + C_EXP_100_C) * f_power) + C_EXP_100_B) * f_power) + 
    C_EXP_100_A) * f_power) + 1.0F;	   
    These changes are done to get bitexactness between MSVC & c66x */
    f_temp1  = f_power * C_EXP_100_E;
    f_temp2 = f_temp1 + C_EXP_100_D;
    f_temp3 = f_temp2 * f_power;
    f_temp1 = f_temp3 + C_EXP_100_C;
    f_temp2 = f_temp1 * f_power;
    f_temp3 = f_temp2 + C_EXP_100_B;
    f_temp1 = f_temp3 * f_power;
    f_temp2 = f_temp1 + C_EXP_100_A;
    f_temp3 = f_temp2 * f_power;
    f_temp1 = f_temp3 + 1.0F;
    f_fracpart = (float32) f_temp1;

    f_intpart  = CML_f_expPower(C_EXP_100_ROOT_E, u_power);
    f_temp2 = f_intpart * f_fracpart;
    return f_temp2;
}

/*****************************************************************************
  Functionname:    CML_f_exp100                                           */ /*!

  @brief           calculates exp(x) (the natural exponential) for some 
                   number x

  @description     This function calculates the exponential for any number x.
                   It adjusts the input value and calls the function CML_f_exp100s
                   in turn.

  @param[in]       f_power :  The number for which we want e^x
                              Optimal value [-MAX_VAL,..,MAX_VAL]
                              where -MAX_VAL = -87.336F & MAX_VAL = 88.7F

  @return          exp(f_power)

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_exp100(float32 f_power)
{
    float32 f_result; /* result value */
#ifndef CML_GOLDDUST
    float32 f_temp;
#endif
    /*! it is necessary that function exp_100s will be called with positive argument */
    if (f_power < 0.0F)
    {
#ifdef CML_GOLDDUST
        f_result = 1.0F / CML_f_exp100s(-f_power);	
#else
        f_temp = CML_f_exp100s(-f_power);
        f_result = CML_f_fastInv69(f_temp);
#endif
    }
    else
    {
        f_result = CML_f_exp100s(f_power);
    }
    if (f_power < -86.95F)
    {
        f_result =  0.0F;
    }
    return f_result;
}



/************************************************************************
  Functionname:    CML_f_exp                                          */ /*!

  @brief           Fast approximation exponential function 

  @description     This function does a fast approximation of the 
                   exponential function with the help of some predetermined
                   constant coefficients.

  @param[in]       f_power : Any floating point value between -80.0F & 80.0F

  @return          Approximation of exp(f_power)

  @pre             x < 80, IEEE754 Floating Point format

  @post            Postcondition: none
**************************************************************************** */
/* PRQA S 1257 6 */
/* Deactivate QAC warning 1257, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in this conversion as there is no loss of data */
float32 CML_f_exp(float32 f_power)
{
    float32 f_exp;             /* Function result value */
    sint32 s_2base_exp = 0L;      /* Integer part for two base exponent */
    sint32 s_sign;           /* Sign bit: xsb=0 -> x>=0, xsb=1 -> x<0 */
    uint32 u_iVal;        /* Integer interpretation of float value */
    float32 f_tmp;
    uint32 ui_tmp;

    /* handling of out-of-range arguments */
    if (f_power < -80.0F)
    {
        f_exp = 0.0F;
    }

    else
    {
        /* Limit input. */
        f_power = CML_f_Min(f_power, 80.0f);

/* PRQA S 1257 , 0310 6 */
/* Deactivate QAC warning 1257, 0310, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating these rules as the further calculations need the data in Dword. */
        /* Reinterprete value as Dword */
        {
            const uint32* ui_pointer = (uint32 *)(&f_power);
            u_iVal = *ui_pointer;
        }

/* PRQA S 2985 4 */
/* Deactivate QAC warning 2985, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in doing this redundant operation and it is done for code clarity */
        ui_tmp = (u_iVal >> (uint32)31UL) & (uint32)1UL;
        s_sign = (sint32) ui_tmp;   /* extract sign bit of input value */
        u_iVal &= (uint32)0x7FFFFFFFUL;               /* remove sign bit x = |x| */

        /*  Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.3465735903F. Given x,
        find r and integer k such that x = k*ln2 + r,  |r| <= 0.5*ln2. */

        /* Test if argument is outside the desired reduction range */
        if( u_iVal > 0x3EB17218UL ) {   /* |x| > 0.5*ln2 */

            /* Natural logarithm of 2 as high and low value to increase accuracy for both sign. */
            const float32 a_ln2HiPrt_c[2] = { +6.9313812256e-01F, -6.9313812256e-01F };
            const float32 a_ln2LoPrt_c[2] = { +9.0580006145e-06F, -9.0580006145e-06F };

            float32 f_hi = 0.F;  /* High part of reduced value */
            float32 f_lo = 0.F;  /* Low part of reduced value */

            if ( u_iVal < 0x3F851592UL ) {    /* |x| < 1.5 * ln2 */
                /*  Simple reduction via addition or substraction */
                f_hi = f_power - a_ln2HiPrt_c[s_sign];
                f_lo = a_ln2LoPrt_c[s_sign];
/* PRQA S 1890 , 4460 5 */
/* Deactivate QAC warning 1890, 4460 Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating these rules as there is no loss of data */
                s_2base_exp = 1L - (s_sign + s_sign);
            }
            else {
                /* Complete reduction is necessary */
                const float32 f_invln2_c  = 1.4426950216F; /* 1/ln2 */
                const float32 a_halF_c[2] = {0.5F,-0.5F};

                /* Reduce to 0..ln2 and shift to -0.5*ln2 .. +0.5*ln2 */
                f_tmp = (f_invln2_c*f_power) + a_halF_c[s_sign];
                s_2base_exp  =  (sint32) f_tmp;
                f_hi = f_power - ( ((float32)s_2base_exp) * a_ln2HiPrt_c[0]);
                f_lo = ((float32)s_2base_exp) * a_ln2LoPrt_c[0];
            }
            f_power  = f_hi - f_lo;  /* Combine both parts */
        }
        else {
/* PRQA S 1257 4 */
/* Deactivate QAC warning 1257, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating these rules as there is no loss of data */
            /* Input argument is already within reduction range.  */
            s_2base_exp = 0L;
        }

        /* x is now in primary range */
        { /*  Approximation of exp(r) by a polynom on the interval [-0.34658,+0.34658] */
            const float32 f_a1_c = 0.0013793724F;
            const float32 f_a2_c = 0.0083682816F;
            const float32 f_a3_c = 0.0416686266F;
            const float32 f_a4_c = 0.1666652424F;
            const float32 f_a5_c = 0.4999999297F;

            /*
            The below code implement
            f_exp = (((((((((((f_power*f_a1_c) + f_a2_c)*f_power) + f_a3_c)*f_power) + f_a4_c)*f_power) + f_a5_c)*f_power) + 1.F)*f_power) + 1.F;
            */
            float32 f_tmp1, f_tmp2, f_tmp3, f_tmp4;

            /* Calculate polynom with horner schema */
            f_tmp1 = f_power * f_a1_c;
            f_tmp2 = f_tmp1  + f_a2_c;
            f_tmp3 = f_tmp2  * f_power;
            f_tmp4 = f_tmp3  + f_a3_c;

            f_tmp1 = f_tmp4 * f_power;
            f_tmp2 = f_tmp1 + f_a4_c;
            f_tmp3 = f_tmp2 * f_power;
            f_tmp4 = f_tmp3 + f_a5_c;

            f_tmp1 = f_tmp4 * f_power;
            f_tmp2 = f_tmp1 + 1.F;
            f_tmp3 = f_tmp2 * f_power;
            f_exp  = f_tmp3 + 1.F;  
        }
/* PRQA S 0310 6 */
/* Deactivate QAC warning 0310, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as further calculations need to be in unsigned int*/
        /*  Scale back to obtain exp(x) = 2^k * exp(r) */
        {
            const uint32* ui_pointer = (uint32 *)(&f_exp);
            u_iVal = *ui_pointer;
        }
/* PRQA S 0310 6 */
/* Deactivate QAC warning 0310, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as further calculations need to be in unsigned int */
        u_iVal += (  (*((uint32 *)&(s_2base_exp)))<<23UL);
        {
            const float32* f_pointer = (float32 *)(&u_iVal);
            f_exp = *f_pointer;
        }
    } /* if/else (x < -80.0F) */

    return f_exp;
}


/*****************************************************************************
  Functionname:    CML_f_fastlog                                          */ /*!
  
  @brief           Calculates a fast natural logarithm approximation

  @description     This function uses CML_f_fastlog10.
                   This function calculates the natural logarithm using             
                   ln(input) = log10(input) * ln(10)


  @param[in]       f_value: Value to be logarithmized
                            Supported range [Full range of float32]

  @return          Natural logarithm approximation of input value

  @author          Matthias Brendel

*****************************************************************************/
float32 CML_f_fastlog(float32 f_value)
{
    float32 f_temp, f_temp1;
    
    /*multiply with ln(10)*/
    f_temp = CML_f_fastlog10(f_value);
    f_temp1 = CML_LN_10 * f_temp;
    return f_temp1;
}



/*******************************************************************************
  Functionname:    CML_f_log2                                             */ /*!

  @brief           calculate the logarithm to the base of 2

  @description     This function calculates the logarithm to the base of 2 as 
                   follows:
                   - separate exponent and mantissa of float representation.
                   - calculate log2(mantissa) with polynomial
                   - result = log2(mantissa) + exponent

  @remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input < 0.0f.

  @return          log2(input) with accuracy of >5 decimals

  @param[in]       f_in: value for which log2() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  @created         02.06.2015
  @changed         02.06.2015

  @author          sebastian.schwarzkopf@continental-corporation.com
*******************************************************************************/
float32 CML_f_log2(const float32 f_in)
{
  float32       f_mantissa, /* mantissa float value of input */
                f_logMant,  /* log2(mant) */
                f_powVal,   /* power value for polynomial */
                f_result;   /* return value */
  sint32        s_exp,      /* exponent of input */
                s_cnt;      /* count value */
  t_floatAccess accTmp;     /* buffer for bit manipulation of input value */
  
  const float32 a_polyCoeff[NOF_LOG2_POLY_ELEMENTS] = {-3.235209154962737f,
                                                       7.085099692691060f,
                                                       -7.396145690524245f,
                                                       5.673515407791697f,
                                                       -2.914488887785300f,
                                                       0.950740445200145f,
                                                       -0.178109466192688f,
                                                       0.014598466017242f};  /* polynomial coefficients for log2(mant) */
  
  
  /* Check if input is a positive value. */
  if(f_in > 0.0f)
  {
    /* Write input to access union. */
    accTmp.f_val = f_in;
 /* PRQA S 4394 10 */
/* Deactivate QAC warning 4394, Date: 2019-06-17; Reviewer: uid22555;
   Reason: The function is reviewed. There is no risk in violating this rule */
    /* Get exponent value. */
    s_exp  = (sint32)((accTmp.u_val & FLOAT_EXP_MASK) >> FLOAT_EXP_SHIFT);
    s_exp -= FLOAT_EXP_OFFSET;
    
    /* Get mantissa in (float). */
    accTmp.u_val  = accTmp.u_val & FLOAT_MANT_MASK;
    accTmp.u_val += FLOAT_ZERO_HEX;
    f_mantissa    = accTmp.f_val;
    
    /* Calculate logarithmus of mantissa with series expansion:
       log2(x) = p0 + p1 * x^1 + p2 * x^2... */
    f_powVal  = 1.0f;
    f_logMant = a_polyCoeff[0];
    
    for(s_cnt = 1; s_cnt < NOF_LOG2_POLY_ELEMENTS; s_cnt++)
    {
      f_powVal  *= f_mantissa;
      f_logMant  = CML_f_MultAdd(f_powVal, a_polyCoeff[s_cnt], f_logMant);
    } /* for(s_cnt = 1L; s_cnt < NOF_LOG2_POLY_ELEMENTS; s_cnt++) */
    
    /* Result is log(mantissa) + exponent. */
    f_result = f_logMant + (float32)s_exp;
  } /* if(f_in > 0.0f) */
  

/* PRQA S 4404 , 1257 15 */
/* Deactivate QAC warning 4404, 1257, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating these rules, as there is no loss of data */
  else if(f_in < 0.0f)
  {
    /* Log() is not defined for real negative inputs. Return (-NAN). */
    accTmp.u_val = FLOAT_NEG_NAN;
    f_result     = accTmp.f_val;
  } /* if/else if(f_in) */
  
  else
  {
    /* Log(0) is (-inf). */
    accTmp.u_val = FLOAT_NEG_INF;
    f_result     = accTmp.f_val;
  } /* if/else if/else(f_in) */
  
  return f_result;
} /* CML_f_log2() */

/*******************************************************************************
  Functionname:    CML_f_log10                                            */ /*!

  @brief           calculate the logarithm to the base of 10

  @description     This function calculates the logarithm to the base of 10 
                   using
                   
                   log10(input) = log2(input) / log2(10)

  @remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  @return          log10(input) with accuracy of >5 decimals

  @param[in]       f_in: value for which log10() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  @created         02.06.2015
  @changed         02.06.2015

  @author          sebastian.schwarzkopf@continental-corporation.com
*******************************************************************************/
float32 CML_f_log10(const float32 f_in)
{
    return ONE_OVER_LOG2_OF_10 * CML_f_log2(f_in);
} /* CML_f_log10() */


/*******************************************************************************
  Functionname:    CML_f_ln                                            */ /*!

  @brief           calculate the natural logarithm

  @description     This function calculates the natural logarithm using
                   
                   ln(input) = log2(input) / log2(e)

  @remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  @return          ln(input) with accuracy of >5 decimals

  @param[in]       f_in: value for which log10() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  @created         02.06.2015
  @changed         02.06.2015

  @author          sebastian.schwarzkopf@continental-corporation.com
*******************************************************************************/
float32 CML_f_ln(const float32 f_in)
{
    float32 f_temp1, f_temp2; 

    f_temp1 = CML_f_log2(f_in);
    f_temp2 = ONE_OVER_LOG2_OF_E * f_temp1;

    return f_temp2;
} /* CML_f_ln() */



/*****************************************************************************
  Functionname:    CML_f_fastlog10                                      */ /*!

  @brief           Calculates a fast decadic logarithm approximation

  @description     This algorithm uses an IEEE754 floating point 
                   decomposition to get the 2's exponent as coarse log2 
                   value. To get a closer approximation the log2 of the 
                   mantissa is fetched from a lookup table and added to the 
                   exponent. At last the log2 is multiplied by a scaling 
                   factor to get the according log10 value.

  @param[in]       f_value : Value to be logarithmized to the base of 10
                             Supported range [Full range of float32]

  @return          Decadic logarithm approximation of input value

  @author          Andreas Geier

*****************************************************************************/
float32 CML_f_fastlog10(float32 f_value)
{
  /* float access as integer */
  /* Deactivate QA-C warning 3629; Reviewer: S. Schwarzkopf; Date: 04.12.2014; 
     Reason: Translation of MISRA suppresion below.
     Review-ID: 3942463 */
  /* PRQA S 3629 3 */
  /* <ln_offset:+1 MISRA Rule 18.4: reviewer name: Martin Sachs date: 12-09-2012 reason: used instead of pointer casting */
    typedef union {
        float32  f_entry;
        uint32 u_entry;
        sint32  s_entry;
    } t_FltAccess;

    /* bias of exponent in internal float memory */
    static const uint32 F32_EXPO_BIAS =      127u;
    /* number of mantissa bits in internal float memory */
    static const uint32 F32_MANT_BITS =      23u;

    static const uint32 F32_EXPO_MASK =        0x7F800000u;
    static const uint32 F32_MANT_MASK =        0x007FFFFFu;
    static const uint32 F32_NEG_INF   =        0xFF800000u;
    static const uint32  F32_NEG_NAN  =        0xFFC00000u; 
    static const float32 LOG10_LOG2_FACT =     0.30102999566398f;

  /* Log2 lookup table between 1 and 2 */
  static const float32 a_log2_lut [N_LUT] = 
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
  };

  float32 f_lut_val;
  float32 f_lut_idx;
  float32 f_temp;
  uint32 u_temp;
  t_FltAccess xFltAcc;
  xFltAcc.f_entry = f_value;

  if ( 0.0f < xFltAcc.f_entry )
  {
      u_temp =  xFltAcc.u_entry & F32_MANT_MASK ;
      f_lut_idx = (float32)u_temp;    
      f_lut_idx *= C_LUT_MAP; 
#ifdef CML_OPT_c66x
      /* This type casting is to avoid _fixfu function call in c66x */
      f_lut_val = a_log2_lut[(uint32)(sint32)f_lut_idx];
#else
      f_lut_val = a_log2_lut[(uint32) f_lut_idx];
#endif
      xFltAcc.u_entry = xFltAcc.u_entry & F32_EXPO_MASK;  
      xFltAcc.u_entry = xFltAcc.u_entry >> F32_MANT_BITS;     
      xFltAcc.s_entry = xFltAcc.s_entry - (sint32) F32_EXPO_BIAS;

      /* The below lines implement "xFltAcc.f_entry = (float32) ( LOG10_LOG2_FACT * ( (float32) xFltAcc.s_entry + f_lut_val ));"
      The code is modified to maintain consistency between MSVC & C66x */
      f_temp = (float32) xFltAcc.s_entry + f_lut_val;
      xFltAcc.f_entry  = (float32) (LOG10_LOG2_FACT * f_temp);
  } /* if ( 0.0f < f_value ) */
  else if ( 0.0f > xFltAcc.f_entry)
  {
      xFltAcc.u_entry = F32_NEG_NAN;
  }
  else 
  {
      xFltAcc.u_entry = F32_NEG_INF;
  }

  return xFltAcc.f_entry;
}

/**************************************************************

  Functionname:    CML_f_powerOfTwo                      */ /*!

  @brief           Calculates 2^x with x as floating point 

  @description     This function calculates the power of 2 (2^x), 
                   for any floating point value x.
                   Splits x into 2 values e.g. x = 12.34f
                   y = 2^12.34 = 2^(12 + 0.34)
                   y = 2^12 * 2^0.34 = A * B
                   Using Bit Shift to calculate A for |x| up to 31 
                   and LUT with length of 32 to look up B
                   For x values bigger than 31 this function uses
                   CML_f_expPower function

  @param[in]       f_value :  Input value for power
                              Optimal range [-F_MAX,.., F_MAX]
                              where F_MAX is the max value of sint32.

  @return          float value as result of 2^f_value

  @author          ulf.eike.stolle@continental-corporation.com

*****************************************************************/
extern float32 CML_f_powerOfTwo(float32 f_value)
{
    /* LUT for 2^(0, 1/32 ... 1-1/32) */
    static const sint32 s_MAXSHIFT = 31;
    uint16 u_idxlut;
    sint32 s_Pow;
    float32 f_overflow, f_out = 0.f;
    float32 f_temp1;
    #ifndef CML_GOLDDUST
    float32 f_temp;
    #endif
    uint32 u_BitPow = 1u; //
    static const float32 a_pow2LUT [N_LUT] = 
    {
        1.0000000000000f,
        1.0218971486541f,
        1.0442737824274f,
        1.0671404006768f,
        1.0905077326653f,
        1.1143867425959f,
        1.1387886347567f,
        1.1637248587776f,
        1.1892071150027f,
        1.2152473599805f,
        1.2418578120735f,
        1.2690509571917f,
        1.2968395546510f,
        1.3252366431597f,
        1.3542555469369f,
        1.3839098819638f,
        1.4142135623731f,
        1.4451808069770f,
        1.4768261459395f,
        1.5091644275934f,
        1.5422108254079f,
        1.5759808451079f,
        1.6104903319493f,
        1.6457554781540f,
        1.6817928305074f,
        1.7186192981225f,
        1.7562521603733f,
        1.7947090750031f,
        1.8340080864093f,
        1.8741676341103f,
        1.9152065613971f,
        1.9571441241754f
    };

    s_Pow = (sint32)f_value;

    if (s_Pow < 0 )
    {
        s_Pow--;
    }
    f_overflow = f_value - (float32)s_Pow; // between 0 and 1

/* PRQA S 4463 6 */
/* Deactivate QAC warning 4463, Date: 2019-06-17; Reviewer: uid22555;
   Reason: These are lookup table indices and uint16 is enough size to use here. */
    f_temp1 = 1.f/(float32)N_LUT;
    u_idxlut = (uint16)CML_s_getLutIndex(f_overflow,0.f,f_temp1,0,N_LUT - 1L );

    if ((s_Pow >= (-s_MAXSHIFT)) && (s_Pow <= s_MAXSHIFT) ) //use uint32 Bitshift
    {
        if (s_Pow >= 0)
        {

/* PRQA S 4534 , 4491 , 4499 11 */
/* Deactivate QAC warning 4534,4491,4499,  Date: 2019-06-17; Reviewer: uid22555;
   Reason: We want power as unsigned for further calculations. */
            u_BitPow = 1u << s_Pow;
            f_temp1 = (float32)u_BitPow;
            f_out = f_temp1 * a_pow2LUT[u_idxlut];
        }
        else
        {
            u_BitPow = 1u << (-s_Pow);
#ifdef CML_GOLDDUST //#if (defined(CPU_MPC5675K_EMU) || defined(CPU_MPC5775N_EMU))
            f_out = (a_pow2LUT[u_idxlut] / ((float32)u_BitPow )) ;
#else
            f_temp1 = (float32)u_BitPow;
            f_temp = CML_f_fastInv69 (f_temp1);
            f_out = a_pow2LUT[u_idxlut] * f_temp;

#endif
        }
    }
    else //Bitshift not possible
    {    
        if (s_Pow >= 0)
        {
            f_out = CML_f_expPower(2.f, (uint32)s_Pow) * a_pow2LUT[u_idxlut];
        }
        else
        {
#ifdef CML_GOLDDUST //#if (defined(CPU_MPC5675K_EMU) || defined(CPU_MPC5775N_EMU))
            f_out =  a_pow2LUT[u_idxlut] / CML_f_expPower(2.f, (uint32)(-s_Pow)) ;
#else
            f_temp = CML_f_fastInv69(CML_f_expPower(2.f, (uint32)(-s_Pow))) ;
            f_out =  a_pow2LUT[u_idxlut] * f_temp;
#endif
        }
    }
    return f_out;
}

/***********************************************************************
  Functionname:     CML_f_xPowY                                   */ /*!

  @brief            Calculate a floating point value to the power of 
                    another floating point value (Z = X^Y)
 
  @description      Calculate a floating point value to the power of 
                    another floating point value (Z = X^Y) using
                    natural logarithm and exponential function
                        exp(ln(Z))   = Z              | Z=X^Y
                    <=> exp(ln(X^Y)) = exp(Y*ln(X))
                    <=>            Z = exp(Y*ln(X))

  @param[in]        f_Base :      base value
                                  Optimal range is [C_F32_DELTA,..,MAX_VAL]
  @param[in]        f_Exponent :  exponent value
                                  Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                                  MAX_VAL is square root of maximum value of float32.

  
  @return           f_XPowY float32 result of base to the power of 
                    exponent

  @author           Matthias Kronauge
*********************************************************************** */

extern float32 CML_f_xPowY(const float32 f_Base, const float32 f_Exponent)
{
    float32 f_XPowY    = 0.0f;
    float32 f_LnOfBase = 0.0f;
    float32 f_temp1;
    
    // special case for fBase = 0
    if (CML_f_Abs(f_Base) <= C_F32_DELTA)
    {
        f_XPowY = 0.0f;
    }
    else
    {
        f_LnOfBase = CML_f_ln(f_Base);
        f_temp1 = f_Exponent * f_LnOfBase;
        f_XPowY = CML_f_exp(f_temp1);
    }

    return f_XPowY; 
}


