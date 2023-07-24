/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_trigo.h

  DESCRIPTION:               Trigonometric Functions Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.17.1.4 $

  ---*/ /*---
  CHANGES:                   $Log: cml_trigo.h  $
  CHANGES:                   Revision 1.17.1.4 2017/11/16 14:15:10CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_trigo module functions with coding standard naming convention
  CHANGES:                   Revision 1.17.1.3 2017/10/13 11:16:30CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Corrected the function header format
  CHANGES:                   Revision 1.17.1.2 2017/09/27 05:58:28CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.17.1.1 2016/12/08 06:44:57CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed extern declarations for functions in header
  CHANGES:                   Revision 1.17 2016/05/25 13:16:50CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   QAC-fixes
  CHANGES:                   Revision 1.16 2016/05/24 10:51:22CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Added macro definitions required and corrected argument names for atan18
  CHANGES:                   Revision 1.15 2016/05/20 14:46:00CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Corrected argument names and updated function header with argument range
  CHANGES:                   Revision 1.14 2016/04/26 14:29:45CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Changed to the use of the CML_INLINE macro and moved the small, fast trig functions to the header to increase the chance of them being properly inlined.
  CHANGES:                   Revision 1.13 2016/04/20 11:23:11CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Header update for CML_atan18()
  CHANGES:                   Revision 1.12 2016/03/17 14:17:02CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Adding hyperbolic tangent.
  CHANGES:                   Revision 1.11 2016/03/15 14:45:25CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Introducing new, fast sine and cosine approximations using a non-Taylor quintic approximation.
  CHANGES:                   Revision 1.10 2015/12/08 08:39:19CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Added cosine approximation and cosine kernel for small angles to avoid shifting small arguments.
  CHANGES:                   Revision 1.9 2015/11/25 11:52:09CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Adding high-precision sine approximation and range-reducing wrappers to call it for sine and cosine.
  CHANGES:                   --- Added comments ---  uidt7777 [Nov 25, 2015 11:52:10 AM CET]
  CHANGES:                   Change Package : 398598:1 http://mks-psad:7002/im/viewissue?selection=398598
  CHANGES:                   Revision 1.8 2015/04/29 17:46:32CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 5:46:33 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.7 2014/09/26 13:37:17CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - switched off QA-C-warnings on side effects for functions that don't have some and sure will never have
  CHANGES:                   --- Added comments ---  uidg6516 [Sep 26, 2014 1:37:18 PM CEST]
  CHANGES:                   Change Package : 266613:3 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.6 2014/05/10 11:22:53CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C issues
  CHANGES:                   --- Added comments ---  uidg6516 [May 10, 2014 11:22:54 AM CEST]
  CHANGES:                   Change Package : 230040:1 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.5 2014/04/07 10:33:00CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:33:00 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2013/05/03 09:58:24CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:58:25 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/04/09 12:59:41CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Move the sqrt approximation from cml_trigo to cml_misc
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:59:42 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:42CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:42 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:18CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj
  
**************************************************************************** */

/**
@defgroup trigo TRIGO (Trigonometric Functions Library)
  @ingroup cml
@{ */

/*****************************************************************************
  QA-C
*****************************************************************************/

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_cos32
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_sin32
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_tan32
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_tan32s
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_cos52
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_sin52
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_tan52
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_atan2
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_atan66
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_asin66
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_acos66
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_expPower
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_exp100
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_exp
#endif /* #ifdef PRQA_SIZE_T */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_trigo.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_TRIGO_INCLUDED
#define _CML_TRIGO_INCLUDED      ///< To avoid multiple inclusion of the file


/*****************************************************************************
  INCLUDES
*****************************************************************************/



/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! if working with trigonometric series, user have to choose different types of algorithms */

#define GDB_TRIG_OPTIMIZED                        1                ///< Switch to include the series approximation of the trigonometric functions

#define GDB_TRIG_SMALL_SERIES                     1                ///< Switch for enabling trigonometric series calculations with 3.2 decimals of accuracy

#define GDB_TRIG_WITH_EXP                         1                ///< Switch to include the fast approximation of the exponential function.

#ifndef CML_NO_RTE_DEPENDENCY
#ifndef b_FALSE
#define b_FALSE ((boolean)0)
#endif
#ifndef b_TRUE
#define b_TRUE ((boolean)1)
#endif
#endif

/*****************************************************************************
  Functionname:    CML_f_atan18                                               *//*!

  \brief           Calculates the inverse tangent with 1.8 decimals 
                   accuracy. 

  \description     Approximates the inverse tangent using a common
                   method. The function calculates the inverse tangent with 
                   1.8 decimals accuracy. Maximum error is 0.0015 radians, 0.088°.
  \InOutCorrelation
                   Arc tangent is calculated as follows: 
                   Let the 'b' be the numerator and 'a' be the denominator in the 
                   ratio for atan such that,
                   \f[  tan(\theta) = \frac{b}{a}  \\
                   or \  \theta   = atan(\frac{b}{a}). \f]
                   Now the angle can be calculated as,
                   \f[ \theta = (\frac{\pi}{4} \times \frac{b}{a}) - \frac{b}{a} \times (\left|\frac{b}{a}
                   \right| - 1) \times (M_1 + (M_2 \times (\left|\frac{b}{a} \right|))
                   \f]
                    where M1 amd M2 are the magic constants.
                   The value can be then subtracted from (+/-)Half of pi, the sign same as the 
                   sign of fraction b/a.
  \param[in]       f_x :  x value of Vector (x,y) for which we want to know 
                          the atan.
                          Supported range [Full range of float32]
  \param[in]       f_y :  y value of Vector (x,y) for which we want to know 
                          the atan.
                          Supported range [Full range of float32]
  \attention       Both inputs f_x and f_y should never be equal to zero at 
                   the same time. This will result in a division by zero.
  \return          the inverse tangent of (x,y)

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_atan18(float32 f_x, float32 f_y);
CML_INLINE float32 CML_f_atan18(float32 f_x, float32 f_y)
{
  float32 f_q;
  float32 f_Absq;
  float32 f_Result;
  const float32 f_MagicNumber1 = 0.2447F;
  const float32 f_MagicNumber2 = 0.0663F;
  boolean b_Reciprocal = (CML_f_Abs(f_x) > CML_f_Abs(f_y)) ? b_TRUE : b_FALSE;
  if(b_Reciprocal == b_TRUE)
  {
    f_q = f_y / f_x;
  }
  else
  {
    f_q = f_x / f_y;
  }
  f_Absq = CML_f_Abs(f_q);
  f_Result = ((CML_f_Pi * 0.25F) * f_q) - f_q * (f_Absq - 1.0F) * (f_MagicNumber1 + (f_MagicNumber2 * f_Absq));
  if(b_Reciprocal == b_TRUE)
  {
    f_Result = (f_q > 0.0F) ? (CML_f_Half_Pi - f_Result) : (-CML_f_Half_Pi - f_Result);
  }
  return f_Result;
}

/*****************************************************************************
  Functionname:    CML_f_sin33Core                                           *//*!

  \brief           Calculates the sine with 3.3 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 5th degree. 
                   Valid on the interval [-pi/2..pi/2].
                   Larger input range requires a range-reducing wrapper.
  \InOutCorrelation
                     For the given angle, 
                   \f[ sin(\theta) = (A \times \theta) - (B \times \theta^3) + (C \times \theta^5) \\
                    where,  \\
                    A = 1, \ B = \frac{(2\pi - 5 )(\frac{2}{\pi})^3}{2}, \ C = \frac{(pi - 3 )(\frac{2}{\pi})^5}{2} 
                   \f]

  \param[in]       f_Angle : input angle for which we would like to know the
                             sine, radians
                             Valid on the interval [-pi/2..pi/2].
  \return          the sine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_sin33Core(float32 f_Angle);
CML_INLINE float32 CML_f_sin33Core(float32 f_Angle)
{
  const float32 f_C0 = 0.63661977F;      // 2 / pi
  const float32 f_C1 = 1.28318531F;      // 2*pi - 5
  const float32 f_C2 = 0.14159265F;      // 3 - pi

  float32 f_y = f_Angle * f_C0;
  float32 f_y2 = f_y * f_y;
  float32 f_z = 0.5F * f_y * (CML_f_Pi - (f_y2 * (f_C1 - f_y2 * f_C2)));

  return f_z;
}
      
/*****************************************************************************
  Functionname:    CML_f_cos33Core                                           *//*! 

  \brief           Calculates the cosine with 3.3 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 5th degree.
                   Valid on the interval [-pi..pi].
                   Larger input range requires a range-reducing wrapper.
  \InOutCorrelation
                     For the given angle, 
                   \f[ sin(\theta) = (A \times \alpha) - (B \times \alpha^3) + (C \times \alpha^5) \\
                    where,  \\
                    \alpha = \left|\theta\right|-\frac{\pi}{2}, \\
                    A = 1, \ B = \frac{(2\pi - 5 )(\frac{2}{\pi})^3}{2}, \ C = \frac{(pi - 3 )(\frac{2}{\pi})^5}{2} 
                   \f]

  \param[in]       f_Angle : input angle for which we would like to know the
                             cosine, radians
                             Valid on the interval [-pi..pi].
  \return          The cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_cos33Core(float32 f_Angle);
CML_INLINE float32 CML_f_cos33Core(float32 f_Angle)
{
  const float32 f_C0 = 0.63661977F;      // 2 / pi
  const float32 f_C1 = 1.28318531F;      // 2*pi - 5
  const float32 f_C2 = 0.14159265F;      // pi - 3

  float32 f_y = (CML_f_Abs(f_Angle) - CML_f_Half_Pi) * f_C0;
  float32 f_y2 = f_y * f_y;
  float32 f_z = -0.5F * f_y * (CML_f_Pi - (f_y2 * (f_C1 - f_y2 * f_C2)));

  return f_z;
}

#if (GDB_TRIG_OPTIMIZED)
  /*! calculation of sin(x) and cos(x) from optmimized COSinus-algorithm */

  #if (GDB_TRIG_SMALL_SERIES)               /*! calculated with 3.2(sin, cos, tan) decimals accuracy */
    #define COS_(x) CML_f_cos32(x)            ///< Calculates the cosine with 3.2 or 5.2 decimals accuracy based on GDB_TRIG_SMALL_SERIES is defined(default) or not.
    #define SIN_(x) CML_f_sin32(x)            ///< Calculates the sine with 3.2 or 5.2 decimals accuracy based on GDB_TRIG_SMALL_SERIES is defined(default) or not.
    #define TAN_(x) CML_f_tan32(x)            ///< Calculates the tangent with 3.2 or 5.6 decimals accuracy based on GDB_TRIG_SMALL_SERIES is defined(default) or not.
  #else                                     /*! calculated with 5.2(sin, cos), 5.6(tan) decimals accuracy */
    #define COS_(x) CML_f_cos52(x)            ///< Calculates the cosine with 3.2 or 5.2 decimals accuracy based on GDB_TRIG_SMALL_SERIES is defined(default) or not.
    #define SIN_(x) CML_f_sin52(x)            ///< Calculates the sine with 3.2 or 5.2 decimals accuracy based on GDB_TRIG_SMALL_SERIES is defined(default) or not.
    #define TAN_(x) CML_f_tan52(x)            ///< Calculates the tangent with 3.2 or 5.6 decimals accuracy based on GDB_TRIG_SMALL_SERIES is defined(default) or not.
  #endif /* GDB_TRIG_SMALL_SERIES */

  #define COS_HD_(x) CML_f_cos52(x)           ///< Calculates the cosine with 5.2 decimals accuracy 
  #define SIN_HD_(x) CML_f_sin52(x)           ///< Calculates the sine with 5.2 decimals accuracy   
  #define TAN_HD_(x) CML_f_tan52(x)           ///< Calculates the tangent with 5.6 decimals accuracy
                                            
  #define ATAN2_(y, x) CML_f_atan2(y, x)    ///< Computes the four-quadrant atan(y/x) with about 6.6 decimal digits accuracy
  #define ATAN_(x) CML_f_atan66(x)            ///< Computes atan(x) with about 6.6 decimal digits accuracy
  #define ASIN_(x) CML_f_asin66(x)            ///< Computes asin(x) with about 6.6 decimal digits accuracy
  #define ACOS_(x) CML_f_acos66(x)            ///< Computes acos(x) with about 6.6 decimal digits accuracy

  #if (GDB_TRIG_WITH_EXP)
    #define EXP_(x)    (CML_f_exp(x))          ///< Fast approximation exponential function 
  #else
    #define EXP_(x)    ((float32) exp((float32)x))
  #endif /* GDB_TRIG_WITH_EXP */
#else /* #if (GDB_TRIG_OPTIMIZED) */

  #include "math.h"

  #define ATAN2_(y, x) ((float32) atan2((float32)(y), (float32)(x)))
  #define ATAN_(x)   ((float32) atan((float32)(x)))
  #define TAN_(x)    ((float32) tan((float32)(x)))
  #define ASIN_(x)   ((float32) asin((float32)(x)))
  #define SIN_(x)    ((float32) sin((float32)(x)))
  #define COS_(x)    ((float32) cos((float32)(x)))
  #define ACOS_(x)   ((float32) acos((float32)(x)))

  #define COS_HD_(x) ((float32) cos((float64)(x)))
  #define SIN_HD_(x) ((float32) sin((float64)(x)))
  #define TAN_HD_(x) ((float32) tan((float64)(x)))

  #define EXP_(x)    (((float32)) exp(((float32))(x)))

#endif /* GDB_TRIG_OPTIMIZED */

#if (GDB_TRIG_OPTIMIZED)
  #define C_LONG_MAX      2147483647L          ///< Maximum value for signed long 
  #define C_TWOPI        (2.0F * CML_f_Pi)     ///< Value for 2 times the mathematical constant pi
  #define C_TWO_OVER_PI  (2.0F / CML_f_Pi)     ///< Value of 2 over the mathematical constant pi
  #define C_HALFPI       (0.5F * CML_f_Pi)     ///< Value of half the mathematical constant pi
  #define C_QUARTERPI    (0.25F * CML_f_Pi)    ///< Value of quarter the mathematical constant pi
  #define C_FOUR_OVER_PI (4.0F / CML_f_Pi)     ///< Value of 4 over the mathematical constant pi. Used in tan(x) routine
  #define C_THREEHALFPI  (1.5F * CML_f_Pi)     ///< Value of 1.5 times the mathematical constant pi. Used in tan(x) routine
  #define C_TENPI  (10.0F * CML_f_Pi)          ///< Value of 10 times the mathematical constant pi


  #define C_COS_32_C1  0.99940307f             ///< Constant value in the series calculation for cosine function with 3.2 decomals of accuracy
  #define C_COS_32_C2 (-0.49558072f)           ///< Coefficient for square of the angle in the series calculation for cosine function with 3.2 decomals of accuracy
  #define C_COS_32_C3  0.03679168f             ///< Coefficient for fourth power of the angle in the series calculation for cosine function with 3.2 decomals of accuracy

  #define C_TAN_32_C1 (-3.6112171f)            ///< Constant coefficient in the numerator for the calculation of tangent with 3.2 decimal places accuracy
  #define C_TAN_32_C2 (-4.6133253f)            ///< Constant term in the denominator for the calculation of tangent with 3.2 decimal places accuracy

  #define C_COS_52_C1  0.99999329F             ///< Constant value in the series calculation for cosine function with 5.2 decomals of accuracy
  #define C_COS_52_C2 (-0.49991243F)           ///< Coefficient for square of the angle in the series calculation for cosine function with 5.2 decomals of accuracy
  #define C_COS_52_C3  0.04148774F             ///< Coefficient for fourth power of the angle in the series calculation for cosine function with 5.2 decomals of accuracy
  #define C_COS_52_C4 (-0.00127120F)           ///< Coefficient for sixth power of the angle in the series calculation for cosine function with 5.2 decomals of accuracy

  /*! optimized TAN-algorithm */

  #define C_TAN_56_C1 (-3.16783027F)           ///< Coefficient for the angle in the numerator for the calculation of tangent with 5.6 decimal places accuracy
  #define C_TAN_56_C2  0.13451612F             ///< Coefficient for the third power of angle in the numerator for the calculation of tangent with 5.6 decimal places accuracy
  #define C_TAN_56_C3 (-4.03332198F)           ///< Constant term in the denominator for the calculation of tangent with 5.6 decimal places accuracy

  /*! optimized ArcTAN-algorithm */
  
  #define C_ATAN_66_C1 1.68676291F             ///< Coefficient for the tangent in the numerator for the calculation of arctangent with 6.6 decimal places accuracy
  #define C_ATAN_66_C2 0.43784973F             ///< Coefficient for the third power of tangent in the numerator for the calculation of arctangent with 6.6 decimal places accuracy
  #define C_ATAN_66_C3 1.68676331F             ///< Constant term in the denominator for the calculation of arctangent with 6.6 decimal places accuracy
  
  
  #define C_SIXTHPI      (CML_f_Pi/6.0F)       ///< Holds the value of one-sixth of the mathematical constant Pi in 32 bit floating point to be used in all calculations
  #define C_TANSIXTHPI   0.57735026F           ///< Holds the value of tangent one-sixth of the mathematical constant Pi in 32 bit floating point to be used in all calculations
  #define C_TANTWELFTHPI 0.26794919F           ///< Holds the value of tangent one-twelfth of the mathematical constant Pi in 32 bit floating point to be used in all calculations
  #define C_SIXTH (1.0F/6.0F)                  ///< Holds the value of one by six to be used in calculations.

  #if (GDB_TRIG_WITH_EXP)
    /*! optimized (exp(x)) exponential-series */
    
    #define C_EXP_100_ROOT_E  1.28402541F     ///< sqrt(sqrt(exp(1))) with single precision for calculating exp() with 10.0 decimals of accuracy
    #define C_EXP_100_A       1.00000003F     ///< Coefficient of the input in the series for calculating exp() with 10.0 decimals of accuracy
    #define C_EXP_100_B       0.49999798F     ///< Coefficient of sqaure of the input in the series for calculating exp() with 10.0 decimals of accuracy
    #define C_EXP_100_C       0.16670407F     ///< Coefficient of cube of the input in the series for calculating exp() with 10.0 decimals of accuracy
    #define C_EXP_100_D       0.04136541F     ///< Coefficient of fourth power of the input in the series for calculating exp() with 10.0 decimals of accuracy
    #define C_EXP_100_E       9.41927345E-3   ///< Coefficient of fifth power of the input in the series for calculating exp() with 10.0 decimals of accuracy
  #endif /* GDB_TRIG_WITH_EXP */
#endif /* GDB_TRIG_OPIMIZED */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/************************************************************************
  Functionname:    CML_f_sincos                                           *//*!

  \brief           Computes the approximation for sine and cosine for the 
                   given value.

  \description     This function computes the approximation for both sine
                   and cosine for the given value and populates to the memory
                   provided by the pointers passed. 
                   

  \param[in]       f_val :  Angle for which sine and cosine needs to be computed
                            Optimal value [-MAX_VAL,..,MAX_VAL]
                            where MAX_VAL is fifth root of max value of float32.
  \param[out]      p_sin :  sine of f_val
                            Valid float pointer
  \param[out]      p_cos :  cosine of f_val
                            Valid float pointer

  \return          void

  \pre             x < 80, IEEE754 Floating Point format

  \post            Postcondition: none

  \author          thomas.diepolder@contiautomotive.com
                   norman.apel@contiautomotive.com

  \testmethod  
  \traceability  
**************************************************************************** */
extern void CML_f_sincos(float32 f_val, float32 *p_sin, float32 *p_cos);

#if (GDB_TRIG_OPTIMIZED)

/*****************************************************************************
  Functionname:    CML_f_tanh58                                               *//*!

  \brief           Calculates the hyperbolic tangent with 5.8 decimals 
                   relative accuracy. Maximum relative error is 1.35e-6

  \description     Approximates the hyperbolic tangent using a rational 
                   function for arguments < 8, and by sign(arg) * 1 for 
                   larger arguments. The method has no poles on the real
                   axis.
                   @startuml
                   (*) --> [x] check input
                   note right: tanh is very close to +/- 1 after 8.
                   If (|x| > 8)
                    --> [Yes] tanh(x) = +-1
                   note left : Sign of the result same as sign of the input
                   --> (*)
                   else
                   --> [No] Compute the tanh
                   note right : Uses the numerator and denominator polynomials with predefined constant coefficients
                   Endif
                   --> (*)
                   @enduml

  \InOutCorrelation
                   \f[ f_N(x) = C_1.x(((x^2 + C_2)x^2 + C_3)x^2 + C_4) \\
                       f_D(x) = (((x^2 + C_5)x^2 + C_6)x^2 + C_7)x^2 + C_8) \\
                       tanh(x) = \frac{f_N(x)}{f_D(x)} \f]

  \param[in]       f_Arg : input argument for which we would like to know the 
                           hyperbolic tangent.
                           Supported range [Full range of float32]

  \return          the hyperbolic tangent of f_Arg

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_tanh58(float32 f_Arg);

/*****************************************************************************
  Functionname:    CML_f_sin66Core                                           *//*!

  \brief           Calculates the sine with 6.6 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Valid on the interval [-pi/2..pi/2]. 
                   Larger input range requires a range-reducing wrapper.
  \InOutCorrelation
                   \f[ sin(x) = x- \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} +  \frac{x^9}{9!} -  \frac{x^{11}}{11!} \f]

  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine, radians
                             Optimal range [-CML_f_Half_Pi,..,CML_f_Half_Pi]
  \return          the sine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_sin66Core(float32 f_Angle);


/*****************************************************************************
  Functionname:    CML_f_cos66Core                                           *//*!

  \brief           Calculates the cosine with 6.6 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 8th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Valid on the interval [-pi/4..pi/4]. 
                   Larger input range requires a range-reducing wrapper.
  \InOutCorrelation
                   \f[ cos(x) = 1- \frac{x^2}{2!} + \frac{x^4}{4!} - \frac{x^6}{6!} +  \frac{x^8}{8!} \f]

  \param[in]       f_Angle : input angle for which we would like to know the 
                             cosine, radians
                             Optimal range [-CML_f_Half_Pi,..,CML_f_Half_Pi]
  \return          the cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_cos66Core(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_f_sin66                                                *//*!

  \brief           Calculates the sine with 6.6 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Performs bounds wrapping, but looses accuracy for very
                   large arguments due to the reduced resolution of the argument.
                   @startuml
                   (*) --> [angle] check input angle
                   If angle <= (pi/2)
                   --> [Yes] sin(angle) = sine_core(angle)
                   note left : Calls the core sine function with the input
                   --> (*)
                   else
                   --> [No] calculate x' = Range reduction to (0,2pi)
                    note right : Bring the absolute of argument to the range 0-2pi if it is greater than 2pi
                   If x' <= (pi/2)
                   --> [Yes] sin(angle) = (Sign of angle) * sine_core(x')
                   note left : x' in the first quadrant
                   --> (*)
                   else
                   --> [No] check for other quadrants
                   If x' <= (3pi/2)
                   --> [Yes] sin(angle) = -(Sign of angle) * sine_core(x'- pi)
                   note left : x' is in second or third quadrant
                   --> (*)
                   else
                   --> [No] sin(angle) = (Sign of angle) * sine_core(x'- 2pi)
                   note right : x' is in the fourth quadrant
                   --> (*)
                   Endif
                   Endif
                   Endif
                   @enduml

  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine, radians
                             Supported values [Full range of float32]
  \return          the sine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_sin66(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_f_cos66                                                *//*!

  \brief           Calculates the cosine with 6.6 decimals relative accuracy.

  \description     Approximates the cosine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Performs bounds wrapping, but looses accuracy for very
                   large arguments due to the reduced resolution of the argument.
                   @startuml
                   (*) --> [angle] calculate x' = Range reduction to (0,2pi)
                    note right : Bring the absolute of argument to the range 0-2pi if it is greater than 2pi
                   If x' <= (pi/4)
                   --> [Yes] cos(angle) = cos_core(x')
                   note left : Cos kernel only converges within pi/4
                   --> (*)
                   else
                   --> [No] check for pi/4 to 2pi
                   If x' < (pi)
                   --> [Yes] cos(angle) = -cos_core(x'- pi/2)
                   --> (*)
                   else
                   --> [No] cos(angle) = cos_core(x'- 3pi/2)
                   note right : in the range pi to 2pi
                   --> (*)
                   Endif
                   Endif
                   @enduml

  \param[in]       f_Angle : input angle for which we would like to know the 
                             cosine, radians
                             Supported values [Full range of float32]
  \return          the cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_cos66(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_f_cos32                                               *//*!

  \brief           Calculates the cosine with 3.2 decimals accuracy

  \description     It reduces the input argument's range to [0, pi/2],
                   and then performs the approximation.
                   Algorithm is as given below
  \InOutCorrelation
                   \f[ cos(x) = c_1 + C_2 \times x^2 + C_3 \times x^4 \\ \f]
                   which is the same as:
                   \f[cos(x)= c_1 + x^2(c_2 + c_3 \times x^2) \\ \f]

  \param[in]       f_angle : input angle for which we would like to know the cosine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE = [max range of uint32] * CML_f_two_Pi
  \return          the cosine of f_angle

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_cos32(float32 f_angle);


/*****************************************************************************
  Functionname:    CML_f_sin32                                               *//*!

  \brief           Calculates the sine with 3.2 decimals accuracy 

  \description     This function calculates the sine with 3.2 decimals 
                   accuracy.
                   The sine is just cosine shifted a half-pi, 
                   so the argument is adjusted and the cosine 
                   approximation is called.
  \InOutCorrelation
                   \f[ sin(x) = cos(pi/2 - x) \\ and \f]
                   \f[ cos(x) = c_1 + c_2 \times x^2 + c_3 \times x^4 \\ \f]
                   which is the same as:
                   \f[cos(x)= c_1 + x^2(c_2 + c_3 \times x^2) \\ \f]
  \param[in]       f_angle : input angle for which we would like to know the 
                             sine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE =
                             ([max range of uint32] * CML_f_two_Pi)-C_HALFPI
  \return          the sine of f_angle

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_sin32(float32 f_angle);


/*****************************************************************************
  Functionname:    CML_f_tan32                                               *//*!

  \brief           Computes the tangent of x with accuracy of about 3.2 decimal digits

  \description     This is the main tangent approximation "driver". 
                   It reduces the input argument's range to [0, pi/4], 
                   and then calls the approximator. 
                   @startuml
                   (*) --> check the input for positive number
                   note left : set the sign flag if the number is negative
                   --> Limit input to 2pi
                   --> Find the octant (0-7) to which the angle belong to
                   If Octant 1
                   --> [Yes] inverse of core_tan((pi/2 - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 2
                   --> [Yes]  negative inverse of core_tan((angle - pi/2)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 3
                   --> [Yes]  negative of core_tan((pi - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 4
                   --> [Yes]  core_tan((angle - pi)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 5
                   --> [Yes]  inverse of core_tan((3pi/2 - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 6
                   --> [Yes]  negative inverse of core_tan((angle - 3pi/2)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 7
                   --> [Yes]  negative of core_tan((2pi - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] core_tan(angle *(4/pi))
                   note left: Default octant - 0
                   --> (*)
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif
                   @enduml
  \InOutCorrelation
                   \f[ tan(x)= \frac{x \times c_1}{(c_2 + x^2)} \f]
  \attention       We do not test for the tangent approaching 
                   infinity,  which it will at x=pi/2 and x=3*pi/2. 
                   If this is a problem in your application, take 
                   appropriate action.

  \param[in]       f_angle : the angle for which we want to know the 
                             tangent, radians
                             Supported values are [Full range of float32]
                             except ((2*n) + 1)*C_HALFPI, n is any integer.

  \return          the tangent of f_angle

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_tan32(float32 f_angle);


/*****************************************************************************
  Functionname:    CML_f_cos52                                                *//*!

  \brief           Calculates the cosine with 5.2 decimals accuracy 

  \description     It reduces the input argument's range to [0, pi/2],  
                   and then performs the approximation.
                   Algorithm as given below
  \InOutCorrelation
                   \f[ cos(x) = c_1 + c_2 \times x^2 + c_3 \times x^4 + c_4 \times x^6 \\ \f]
                   which is the same as:
                   \f[cos(x)= c_1 + x^2(c_2 + c_3 \times x^2 + c_4 \times x^4) \\ 
                      cos(x)= c_1 + x^2(c_2 + x^2(c_3 + c_4 \times x^2) \\ \f]

  \param[in]       f_angle : angle for which cosine has to be found
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE = [max range of uint32] * CML_f_two_Pi

  \return          cosine of f_angle (double)

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_cos52(float32 f_angle);

/*****************************************************************************
  Functionname:    CML_f_sin52                                                *//*!

  \brief           Calculates the sine with 5.2 decimals accuracy 

  \description     The sine is just cosine shifted a half-pi, 
                   so we'll adjust the argument and call the cosine approximation.
  \InOutCorrelation
                   \f[ sin(x) = cos(pi/2 - x) \\ \f] and
                   \f[ cos(x) = c_1 + c_2 \times x^2 + c_3 \times x^4 + c_4 \times x^6 \\ \f]
                   which is the same as:
                   \f[cos(x)= c_1 + x^2(c_2 + c_3 \times x^2 + c_4 \times x^4) \\ 
                      cos(x)= c_1 + x^2(c_2 + x^2(c_3 + c_4 \times x^2) \\ \f]

  \param[in]       f_angle : input angle for which we would like to know the 
                             sine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE =
                             ([max range of uint32] * CML_f_two_Pi)-C_HALFPI

  \return          the sine of f_angle 

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_sin52(float32 f_angle);

/*****************************************************************************
  Functionname:    CML_f_tan52                                                *//*!

  \brief           Computes the tangent of x with accuracy of about 5.6 
                   decimal digits

  \description     This is the main tangent approximation "driver".
                   It reduces the input argument's range to [0, pi/4],
                   and then calls the approximator.
                    WARNING: We do not test for the tangent approaching
                   infinity,  which it will at x=pi/2 and x=3*pi/2.
                   If this is a problem in your application, take
                   appropriate action.
                   //                   @startuml
                   (*) --> check the input for positive number
                   note left : set the sign flag if the number is negative
                   --> Limit input to 2pi
                   --> Find the octant (0-7) to which the angle belong to
                   If Octant 1
                   --> [Yes] inverse of core_tan((pi/2 - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 2
                   --> [Yes]  negative inverse of core_tan((angle - pi/2)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 3
                   --> [Yes]  negative of core_tan((pi - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 4
                   --> [Yes]  core_tan((angle - pi)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 5
                   --> [Yes]  inverse of core_tan((3pi/2 - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 6
                   --> [Yes]  negative inverse of core_tan((angle - 3pi/2)*(4/pi))
                   --> (*)
                   else
                   --> [No] If Octant 7
                   --> [Yes]  negative of core_tan((2pi - angle)*(4/pi))
                   --> (*)
                   else
                   --> [No] core_tan(angle *(4/pi))
                   note left: Default octant - 0
                   --> (*)
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif
                   Endif
                   @enduml
  \InOutCorrelation
                   \f[ tan(x)= \frac{x(c_1 + (c_2 \times x^2))}{(c_3 + x^2)} \f]

  \param[in]       f_angle : the angle for which we want to know the 
                             tangent, radians
                             Supported values are [Full range of float32]
                             except ((2*n) + 1)*C_HALFPI, n is any integer.

  \return          the tangent of f_angle

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_tan52(float32 f_angle);

/*****************************************************************************
  Functionname:    CML_f_atan66                                               *//*!

  \brief           computes atan(x) with about 6.6 decimal digits accuracy

  \description     The input argument's range is reduced to [0, pi/12] 
                   before the approximation takes place
                   @startuml
                   (*) --> check the sign of the input
                   note left: Set the sign flag if input is negative
                   --> take inverse of input if it exceeds 1. Keep input between 0 and 1
                   note right : Set the complement flag if the input exceeds 1
                   --> Define a region in terms of pi/12
                   note left : Reduce arg to under tan(pi/12)
                   --> Approximation on the reduced argument
                   --> Compensation for region, complement and sign
                   --> (*)
                   @enduml
  \InOutCorrelation 
                   \f[ atan(x)= \frac{x(c_1 + c_2 \times x^2)}{(c_3 + x^2)} \f]

  \param[in]       f_tan : the "secant length" for which we want to know the 
                           corresponding angle, radians
                           Optimal values are [-MAX_ANGLE,..,MAX_ANGLE], 
                           where MAX_ANGLE is square root of max value of float32

  \return          arctangent of f_tan

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_atan66(float32 f_tan);

/*****************************************************************************
  Functionname:    CML_f_acos66                                               *//*!

  \brief           implements the acos() function with 6.6 decimals of accuracy

  \description     This function uses the relationships between trigonomtric 
                   and inverse trigonometric functions.
                   Let y be the angle and x be the input cosine. y = acos(x)
                   Also this means that y = pi/2 - asin(x). 
  \InOutCorrelation
                    \f[ tan(asin(x)) = \frac{x}{\sqrt{(1 - x^2)}} \\ \f]
                   which makes
                    \f[ atan(tan(asin(x))) = atan(\frac{x}{\sqrt{(1 - x^2)}}) \\
                        asin(x) = atan(\frac{x}{\sqrt{(1 - x^2)}}) \\ 
                        acos(x) = \frac{\pi}{2} - asin(x) \f]

  \param[in]       f_cos : value for which we want the inverse cosinus
                           Ideal values are [-1,..,0,..,1]

  \return          arccosinus corresponding to the value f_cos, in radians

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_acos66 (float32 f_cos);

/*****************************************************************************
  Functionname:    CML_f_asin66                                               *//*!

  \brief           implements the asin() function with 6.6 decimals of accuracy

  \description     This function uses the relationships between trigonomtric 
                   and inverse trigonometric functions.
                   Let y be the angle and x be the input cosine. y = acos(x)
  \InOutCorrelation
                    \f[ tan(asin(x)) = \frac{x}{\sqrt{(1 - x^2)}} \\ \f]
                   which makes
                    \f[ atan(tan(asin(x))) = atan(\frac{x}{\sqrt{(1 - x^2)}}) \\
                        asin(x) = atan(\frac{x}{\sqrt{(1 - x^2)}}) \\ \f]

  \param[in]       f_sin : value for which we want the inverse sinus
                           Ideal values are [-1,..,0,..,1]

  \return          arcsinus corresponding to the value f_sin, in radians

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_asin66(float32 f_sin);

/*****************************************************************************
  Functionname:    CML_f_atan2                                              *//*!

  \brief           computes the four-quadrant atan2(y/x) with 
                   about 6.6 decimal digits accuracy

  \description     This function computes the four-quandrant arctangent with 
                   about 6.6 decimal digits accuracy.
                   The input arguments are x and y. The situation x=0 is 
                   handled correctly. atan2(y/x) needs to be calculated.
                   @startuml
                   (*) --> check if x > 0
                   If x>0
                   --> [Yes] angle = atan(y/x)
                   note left : Call the atan core function to compute for first or fourth quadrant
                   --> (*)
                   else
                   --> [No] check negative values
                   If x<0
                   --> [Yes] angle = atan(y/(-x))
                   note left: Once angle is computed, it needs to be adjusted based on y 
                   If y<0 
                   --> [Yes] angle = -pi - angle
                   note left: third quadrant
                   --> (*)
                   else
                   --> [No]  angle = pi - angle
                   note right: second quadrant
                   --> (*)
                   Endif
                   else
                   -->[No] x is considered zero
                   If y<0
                   -->[Yes] angle = -(pi/2)
                   --> (*)
                   else
                   --> [No] check for positive values of y 
                   If y>0
                   --> [Yes] angle = (pi/2)
                   --> (*)
                   else
                   --> [No] angle = 0
                   note right: Both x and y are zero
                   --> (*)
                   Endif
                   Endif
                   Endif
                   Endif
                   @enduml

  \param[in]       f_xaxis : any number
                             Optimal values are [-MAX_ANGLE,..,MAX_ANGLE] 
  \param[in]       f_yaxis : any number
                             Optimal values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE is cube root of max value of float32

  \return          the four-quadrant arctangent of f_yaxis/f_xaxis in 
                   radians [-Pi, Pi]
                   if x=0 and y=0 the result is 0

  \author          dan.oprisan@contiautomotive.com

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_atan2(float32 f_yaxis, float32 f_xaxis);


/*****************************************************************************
  Functionname:    CML_f_expPower                                             *//*!

  \brief           calculates efficiently the pow function for positive 
                   integer powers

  \description     The function calculates the value of any number to the power
                   of any positive integer.
                   Limitation : Since the base value (input) and output datatypes  
                   are same, the function fails to store the results for higher 
                   values when the result exceeds the float range.
                   Since the power is an integer value, repeated multplication is
                   implemented.

  \param[in]       f_base : the number which we want to raise to some power
                            Supported values [Full range of float32]

  \param[in]       u_power : the integer power to raise f_base to
                             Supported values [Full range of uint32]
                             Overflow will occur if one or both input values
                             are high.


  \return          f_base raised to the u_power'th power

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_expPower(float32 f_base, uint32 u_power);

#if (GDB_TRIG_WITH_EXP)

/*****************************************************************************
  Functionname:    CML_f_exp100                                               *//*!

  \brief           calculates exp(x) (the natural exponential) for some 
                   number x

  \description     This function calculates the exponential for any number x.
                   It adjusts the input value and calls the function GDBexp_100s
                   in turn. The function checks if the power is negative or not.
                   If negative, the function calls the core function and returns the 
                   reciprocal result. Otherwise it calls the core function and returns
                   the result as such. Core function is as follows.
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


  \param[in]       f_power :  The number for which we want e^x
                              Optimal value [-MAX_VAL,..,MAX_VAL]
                              where MAX_VAL is fifth root of max value of float32.

  \return          exp(f_power)

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_exp100(float32 f_power);

/************************************************************************
  Functionname:    CML_f_exp                                              *//*!

  \brief           Fast approximation exponential function 

  \description     This function does a fast approximation of the 
                   exponential function with the help of some predetermined
                   constant coefficients. If the input is less than -80, then
                   zero will be returned, whereas if it is greater than 80, the 
                   value is capped at 80. Let the input be x. 
                   Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.3465735903F. Given x,
                   find r and integer k such that x = k*ln2 + r,  |r| <= 0.5*ln2. 
                   Once these values are found, then the result is obtained by scaling 
                   the found values.

  \param[in]       f_power :  any number
                              Supported values [-80, 80]

  \pre             x < 80, IEEE754 Floating Point format

  \return          Approximation of exp(f_power)

  \testmethod  
  \traceability    
**************************************************************************** */
extern float32 CML_f_exp(float32 f_power);
#endif
#endif

#endif /* #ifndef _CML_TRIGO_INCLUDED */


/** @} end defgroup */
