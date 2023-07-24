/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_trigo.h
   
  DESCRIPTION:               Trigonometric Functions Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.37.1.2 $

  ---*/ /*---
  CHANGES:                   $Log: cml_trigo.h  $
  CHANGES:                   Revision 1.37.1.2 2019/06/24 09:11:25CEST Reddy, Purushothama (uid33569) 
  CHANGES:                   updated with QAF warnings handled.
  CHANGES:                   Revision 1.37.1.1 2019/05/27 11:04:52CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.37 2018/07/30 10:29:03CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated function header
  CHANGES:                   Revision 1.36 2018/07/30 08:19:21CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Replaced CML_f_tan52 with CML_f_tan66
  CHANGES:                   Revision 1.35 2018/07/12 13:29:54CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_TRIG_OPTIMIZED has been defined in place older legacy code.
  CHANGES:                   Revision 1.34 2018/06/19 12:16:44CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Detailed design was updated for atan2()
  CHANGES:                   Revision 1.33 2018/06/07 13:39:08CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   QAC warnings have been fixed.
  CHANGES:                   Revision 1.32 2018/06/01 11:51:38CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   atan66 functionality has been optimized with atan67 implementation.
  CHANGES:                   Revision 1.31 2018/05/23 08:51:03CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   updated atan18 description
  CHANGES:                   Revision 1.30 2018/05/18 13:55:04CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated Doors requirement link
  CHANGES:                   Revision 1.29 2018/05/18 08:27:15CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Doors requirements link updated
  CHANGES:                   Revision 1.28 2018/05/17 14:27:17CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Function header updated for Doxygen InOutCorrelation
  CHANGES:                   Revision 1.27 2018/05/10 12:02:54CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   updated cml_f_sincos
  CHANGES:                   Revision 1.26 2018/04/24 05:45:40CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   formatting done
  CHANGES:                   Revision 1.25 2018/04/23 08:16:54CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated review comments.
  CHANGES:                   Revision 1.24 2018/04/23 07:25:55CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added new functions in CML trigo module
  CHANGES:                   CML_f_Sine69Core
  CHANGES:                   CML_f_Cos69Core
  CHANGES:                   CML_f_ThreeStepSubPiQuarter
  CHANGES:                   CML_f_TwoStepSubPiQuarter
  CHANGES:                   Revision 1.23 2018/03/08 06:31:29CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Exponential functions are moved to cml_exp.h
  CHANGES:                   Revision 1.22 2018/02/27 06:51:03CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed the spaces after \ ; The change was lost while updating to the legacy release.
  CHANGES:                   Revision 1.21 2018/02/26 08:57:04CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.17.1.3 2017/12/20 06:42:50CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Correction for the compilation warning
  CHANGES:                   Revision 1.17.1.2 2017/11/14 18:41:28CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.17.1.1 2016/12/08 06:44:57CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed extern declarations for functions in header
  CHANGES:                   Revision 1.17.1.1 2016/12/08 06:44:57CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed extern declarations for functions in header
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
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef CML_TRIGO_INCLUDED
#define CML_TRIGO_INCLUDED      ///< To avoid multiple inclusion of the file

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_trigo.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

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
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_tan66
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_atan2
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_atan67
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_asin66
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_acos66
#endif /* #ifdef PRQA_SIZE_T */

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

#ifndef CML_NO_RTE_DEPENDENCY
#ifndef b_FALSE
#define b_FALSE ((boolean)0)
#endif
#ifndef b_TRUE
#define b_TRUE ((boolean)1)
#endif
#endif


/*! if working with trigonometric series, user have to choose different types of algorithms */
/*! Trigonometric series calculated with optimized micro controller code (with 5.2 decimals of accuracy) */
#define CML_TRIG_OPTIMIZED                        1                ///< Switch to include the series approximation of the trigonometric functions

#define CML_TRIG_SMALL_SERIES                     0                ///< Switch for enabling trigonometric series calculations with 3.2 decimals of accuracy

#if (CML_TRIG_OPTIMIZED)
  /*! calculation of sin(x) and cos(x) from optmimized COSinus-algorithm */

  #if (CML_TRIG_SMALL_SERIES)               /*! calculated with 3.2(sin, cos, tan) decimals accuracy */
    #define COS_(x) CML_f_cos32(x)            ///< Calculates the cosine with 3.2 or 5.2 decimals accuracy based on CML_TRIG_SMALL_SERIES is defined(default) or not.
    #define SIN_(x) CML_f_sin32(x)            ///< Calculates the sine with 3.2 or 5.2 decimals accuracy based on CML_TRIG_SMALL_SERIES is defined(default) or not.
    #define TAN_(x) CML_f_tan32(x)            ///< Calculates the tangent with 3.2 or 5.6 decimals accuracy based on CML_TRIG_SMALL_SERIES is defined(default) or not.
  #else                                     /*! calculated with 6.9(sin, cos), 5.6(tan) decimals accuracy */
    #define COS_(x) CML_f_cos66(x)            ///< Calculates the cosine with 3.2 or 6.9 decimals accuracy based on CML_TRIG_SMALL_SERIES is defined(default) or not.
    #define SIN_(x) CML_f_sin66(x)            ///< Calculates the sine with 3.2 or 6.9 decimals accuracy based on CML_TRIG_SMALL_SERIES is defined(default) or not.
    #define TAN_(x) CML_f_tan66(x)            ///< Calculates the tangent with 3.2 or 5.6 decimals accuracy based on CML_TRIG_SMALL_SERIES is defined(default) or not.
  #endif /* CML_TRIG_SMALL_SERIES */

  #define COS_HD_(x) CML_f_cos66(x)           ///< Calculates the cosine with 6.9 decimals accuracy 
  #define SIN_HD_(x) CML_f_sin66(x)           ///< Calculates the sine with 6.9 decimals accuracy   
  #define TAN_HD_(x) CML_f_tan66(x)           ///< Calculates the tangent with 5.6 decimals accuracy
                                            
  #define ATAN2_(y, x) CML_f_atan2(y, x)    ///< Computes the four-quadrant atan(y/x) with about 6.6 decimal digits accuracy
  #define ATAN_(x) CML_f_atan67(x)            ///< Computes atan(x) with about 6.7 decimal digits accuracy
  #define ASIN_(x) CML_f_asin66(x)            ///< Computes asin(x) with about 6.6 decimal digits accuracy
  #define ACOS_(x) CML_f_acos66(x)            ///< Computes acos(x) with about 6.6 decimal digits accuracy

#else /* #if (CML_TRIG_OPTIMIZED) */

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

#endif /* CML_TRIG_OPTIMIZED */

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


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/************************************************************************
  Functionname:    CML_f_sincos                                           *//*!

  \brief           Calculates the sine & cosine of an input value,and performs 
                   range reduction with 6.9 decimals relative accuracy.

  \description     This function computes the approximation for both sine
                   and cosine for the given value and populates to the memory
                   provided by the pointers passed. This function is a wrapper 
                   which performs range reduction on CML_f_Sine69Core & 
                   CML_f_Cos69Core. Three-step Payne-Hanek algorithm is used 
                   here for range reduction. Here large input arguments are 
                   reduced in the range within + or - pi/4 using this algorithm 
                   before calling the core sin & cosine functions.And then the
                   answer and it's sign is appropriately chosen to get sin(x) 
                   & cos(x)
                    @startuml
                    start
                        if (angle < 0) then (yes)
                            :signx = -1;     
                        else (No)
                            :signx =  1; 
                        endif
                        :f_AbsAngle = CML_f_Abs(angle);  
                        :f_temp = f_AbsAngle * FourOverPi;
                        :uQuadranti = type cast f_temp to unsigned integer ; 
                        :uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
                        :Typecast uQuadranti to float and store in f_Arg;
                        :utemp = (uQuadranti & 4);
                        if (utemp == 0) then (yes)
                            :SignS = b_true;     
                        else (No)
                            :SignS = b_false; 
                        endif
                        :utemp = ((uQuadranti - 2) & 4);
                        if (utemp == 0) then (yes)
                            :SignC = b_false;     
                        else (No)
                            :SignC = b_true; 
                        endif
                        :utemp = ((uQuadranti - 2) & 2);
                        if (utemp == 0) then (yes)
                            :SignPoly = b_false;     
                        else (No)
                            :SignPoly = b_true; 
                        endif
                        :f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);
                        :f_st = CML_f_Sine69Core(f_t);
                        :f_ct = CML_f_Cos69Core(f_t); 

                        if (SignPoly == 1) then (yes)
                            :f_sin= f_st;     
                        else (No)
                            :f_sin= f_ct; 
                        endif

                        if (SignS == 1) then (yes)
                            :f_sin= f_sin;     
                        else (No)
                            :f_sin= -f_sin; 
                        endif

                        if (SignPoly == 1) then (yes)
                            :f_cos = f_ct ;     
                        else (No)
                            :f_cos = f_st; 
                        endif

                        if (SignC == 1) then (yes)
                            :*p_cos= f_cos;     
                        else (No)
                            :*p_cos= -_cos; 
                        endif

                        :Type cast Signx to float;
                        :*p_sin  = f_sin * Signx; 

                        stop
                    @enduml

  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine & cosine, in radians. 
                   Optimal range [ Within ±CML_f_two_Pi. Maximum relative
                   Error: 1.19e-7] 
                   [Note:Tested upto ±1000 * CML_f_Pi. with stepsize 0.1F 
                   Maximum relative Error: 1.192e-7].
  \param[out]      p_sin :  sine of f_val
                            Valid float pointer
  \param[out]      p_cos :  cosine of f_val
                            Valid float pointer

  \return          void

  \author          Lars Ulveland, ADC GmbH - Lindau, Jyothy Thomas

  \testmethod  
  \traceability  
**************************************************************************** */
extern void CML_f_sincos(float32 f_Angle, float32 *p_sin, float32 *p_cos);


/*****************************************************************************
  Functionname:    CML_f_tanh58                                               *//*!

  \brief           Calculates the hyperbolic tangent with 5.8 decimals 
                   relative accuracy. Maximum relative error is 1.35e-6

  \description     Approximates the hyperbolic tangent using a rational 
                   function for arguments < 8, and by sign(arg) * 1 for 
                   larger arguments. The method has no poles on the real
                   axis.

  \InOutCorrelation
                   \f[ f_N(x) = C_1.x(((x^2 + C_2)x^2 + C_3)x^2 + C_4) \\
                       f_D(x) = (((x^2 + C_5)x^2 + C_6)x^2 + C_7)x^2 + C_8) \\
                       tanh(x) = \frac{f_N(x)}{f_D(x)} \f]

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

  \param[in]       f_Arg : input argument for which we would like to know the 
                           hyperbolic tangent.
                           Supported range [Full range of float32]

  \return          the hyperbolic tangent of f_Arg

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-9278-0005b460 
*****************************************************************************/
extern float32 CML_f_tanh58(float32 f_Arg);

/*****************************************************************************
  Functionname:    CML_f_sin66Core                                       *//*!

  \brief           Calculates the sine with 6.6 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Valid on the interval [-pi/2..pi/2]. 
                   Larger input range requires a range-reducing wrapper.
  \InOutCorrelation
                   \f[ sin(x) = x- \frac{x^3}{3!} + \frac{x^5}{5!} - 
                   \frac{x^7}{7!} +  \frac{x^9}{9!} -  \frac{x^{11}}{11!} \f]

  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine, radians
                             Optimal range [-CML_f_Half_Pi,..,CML_f_Half_Pi]
  \return          the sine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6337-0005b460   
*****************************************************************************/
extern float32 CML_f_sin66Core(float32 f_Angle);


/*****************************************************************************
  Functionname:    CML_f_cos66Core                                       *//*!

  \brief           Calculates the cosine with 6.6 decimals relative accuracy.

  \description     Approximates the sine function using a polynomial
                   of the 8th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Valid on the interval [-pi/4..pi/4]. 
                   Larger input range requires a range-reducing wrapper.
  \InOutCorrelation
                   \f[ cos(x) = 1- \frac{x^2}{2!} + \frac{x^4}{4!} - 
                   \frac{x^6}{6!} +  \frac{x^8}{8!} \f]

  \param[in]       f_Angle : input angle for which we would like to know the 
                             cosine, radians
                             Optimal range [-CML_f_Half_Pi,..,CML_f_Half_Pi]
  \return          the cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6326-0005b460  
*****************************************************************************/
extern float32 CML_f_cos66Core(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_f_sin66                                                *//*!

  \brief           Calculates the sine of a value,and performs range reduction
                   with 6.9 decimals relative accuracy.

  \description     This function is a wrapper which performs range reduction 
                   on CML_f_Sine69Core. Three-step Payne-Hanek algorithm is 
                   used here for range reduction. Here large input arguments
                   are reduced in the range within ±pi/4 using this algorithm
                   before calling the core sin & cosine functions.And then the
                   answer and it's sign is appropriately chosen to get sin(x).
                    @startuml
                    start
                        if (angle < 0) then (yes)
                            :signx = -1;     
                        else (No)
                            :signx = 1; 
                        endif
                        :f_AbsAngle = CML_f_Abs(angle);  
                        :f_temp = f_AbsAngle * FourOverPi;
                        :Type cast f_temp to unsigned integer and store in uQuadranti; 
                        :uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
                        :f_Arg = typecast uQuadranti to float;
                        :utemp = (uQuadranti & 4);

                        if (utemp == 0) then (yes)
                            :SignS = b_true;     
                        else (No)
                            :SignS = b_false; 
                        endif

                        :utemp = ((uQuadranti - 2) & 2);
                        if (utemp == 0) then (yes)
                            :SignPoly = b_false;     
                        else (No)
                            :SignPoly = b_true; 
                        endif

                        :f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);
                        :f_st = CML_f_Sine69Core(f_t);
                        :f_ct = CML_f_Cos69Core(f_t); 

                        if (SignPoly == 1) then (yes)
                            :f_sin= f_st;     
                        else (No)
                            :f_sin= f_ct; 
                        endif

                        if (SignS == 1) then (yes)
                            :f_sin= f_sin;     
                        else (No)
                            :f_sin= -f_sin; 
                        endif

                        :Type cast Signx to float;
                        :Return f_sin * Signx; 
                    stop
                    @enduml

  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine, in radians. 
                   Optimal range [ Within ±CML_f_two_Pi. Maximum relative
                   Error: 1.19e-7] 
                   [Note:Tested upto ±1000 * CML_f_Pi. with stepsize 0.1F 
                   Maximum relative Error: 1.192e-7]

  \return          The sine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau, Jyothy Thomas

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6337-0005b460    
*****************************************************************************/
extern float32 CML_f_sin66(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_f_cos66                                                *//*!

  \brief           Calculates the cosine of a value, and performs range 
                   reduction with 6.9 decimals relative accuracy.

  \description     This function is a wrapper which performs range reduction 
                   on CML_f_Cos69Core. Three-step Payne-Hanek algorithm is 
                   used here for range reduction. Large input arguments
                   are reduced in the range within ±pi/4 using this algorithm
                   before calling the core sin & cosine functions.And then the
                   answer and it's sign is appropriately chosen to get cos(x)
                    @startuml
                    start
                        :f_AbsAngle = CML_f_Abs(angle);  
                        :f_temp = f_AbsAngle * FourOverPi;
                        :uQuadranti = Type cast f_temp to unsigned integer and store in uQuadranti; 
                        :uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
                        :Typecast uQuadranti to float and store in f_Arg;
    
                        :utemp = ((uQuadranti - 2) & 4);
                        if (utemp == 0) then (yes)
                            :SignC = b_false;     
                        else (No)
                            :SignC = b_true; 
                        endif
    
                        :utemp = ((uQuadranti - 2) & 2);
                        if (utemp == 0) then (yes)
                            :SignPoly = b_false;     
                        else (No)
                            :SignPoly = b_true; 
                        endif

                        :f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);
                        :f_st = CML_f_Sine69Core(f_t);
                        :f_ct = CML_f_Cos69Core(f_t); 

                        if (SignPoly == 1) then (yes)
                            :f_cos = f_ct ;     
                        else (No)
                            :f_cos = f_st; 
                        endif

                        if (SignC == 1) then (yes)
                            :Return f_cos;     
                        else (No)
                            :return -f_cos; 
                        endif

                        stop
                    @enduml

  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine, in radians. 
                   Optimal range [ Within ±CML_f_two_Pi. Maximum relative 
                   Error: 1.19e-7]
                   [Note:Tested upto ±1000 * CML_f_Pi. with stepsize 0.1F 
                   Maximum relative Error: 1.192e-7]

  \return          The Cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau, Jyothy Thomas

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6326-0005b460   
*****************************************************************************/
extern float32 CML_f_cos66(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_f_cos32                                           *//*!

  \brief           Calculates the cosine with 3.2 decimals accuracy

  \description     It reduces the input argument's range to [0, pi/2],
                   and then performs the approximation.
                   Algorithm is as given below
  \InOutCorrelation
                   \f[ cos(x) = c_1 + C_2 \times x^2 + C_3 \times x^4 \\ \f]
                   which is the same as:
                   \f[cos(x)= c_1 + x^2(c_2 + c_3 \times x^2) \\ \f]

  \param[in]       f_angle : input angle for which we would like to know the 
                             cosine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE = [max range of uint32] * CML_f_two_Pi
  \return          the cosine of f_angle

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6326-0005b460  
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
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6337-0005b460   
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
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6345-0005b460   
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
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6326-0005b460  
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
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6337-0005b460    
*****************************************************************************/
extern float32 CML_f_sin52(float32 f_angle);

/*****************************************************************************
  Functionname:    CML_f_tan66                                           *//*!

  \brief           Approximates the tangent of x with accuracy of about 6.6 
                   decimal digits

  \description     This function is tangent approximation which uses sin & cos 
                   approximation, performs range reduction on CML_f_Sine69Core & 
                   CML_f_Cos69Core. This function is a wrapper with Three-step 
                   Payne-Hanek algorithm used for range reduction. Here large input
                   arguments are reduced in the range within ±pi/4 using this 
                   algorithm before calling the core sin & cosine functions. And  
                   then the answer and it's sign is appropriately chosen to get 
                   sin(x) & cos(x). Tan is calculated as sin (x)/cos(x).
                   Note: Tangent approaching infinity is tested and details 
                   added below.

  \InOutCorrelation 
                    @startuml
                    start
                        if (angle < 0) then (yes)
                            :signx = -1;     
                        else (No)
                            :signx =  1; 
                        endif
                        :f_AbsAngle = CML_f_Abs(angle);  
                        :f_temp = f_AbsAngle * FourOverPi;
                        :uQuadranti = type cast f_temp to unsigned integer ; 
                        :uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
                        :Typecast uQuadranti to float and store in f_Arg;
                        :utemp = (uQuadranti & 4);
                        if (utemp == 0) then (yes)
                            :SignS = b_true;     
                        else (No)
                            :SignS = b_false; 
                        endif
                        :utemp = ((uQuadranti - 2) & 4);
                        if (utemp == 0) then (yes)
                            :SignC = b_false;     
                        else (No)
                            :SignC = b_true; 
                        endif
                        :utemp = ((uQuadranti - 2) & 2);
                        if (utemp == 0) then (yes)
                            :SignPoly = b_false;     
                        else (No)
                            :SignPoly = b_true; 
                        endif
                        :f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);
                        :f_st = CML_f_Sine69Core(f_t);
                        :f_ct = CML_f_Cos69Core(f_t); 

                        if (SignPoly == 1) then (yes)
                            :f_sin= f_st;     
                        else (No)
                            :f_sin= f_ct; 
                        endif

                        if (SignS == 1) then (yes)
                            :f_sin= f_sin;     
                        else (No)
                            :f_sin= -f_sin; 
                        endif

                        if (SignPoly == 1) then (yes)
                            :f_cos = f_ct ;     
                        else (No)
                            :f_cos = f_st; 
                        endif

                        if (SignC == 1) then (yes)
                            :cos_out= f_cos;     
                        else (No)
                            :cos_out= -_cos; 
                        endif

                        :Type cast Signx to float;
                        :sin_out  = f_sin * Signx; 

                         if (GOLDDUST switch defined) then (yes)
                            :tan_out = sin_out/cos_out;
                         else (No)
                            :tan_out = sin_out * CML_f_fastInv69(cos_out);
                         endif

                        stop
                    @enduml

  \param[in]       f_Angle : input angle for which we would like to know the 
                             tanget, in radians. 
                   Optimal range [Within ±CML_f_Pi. Maximum relative
                   Error: 2.3918895e-007 from standard C library] 
                   [Note:Tested upto ±1000 * CML_f_Pi. with stepsize 100.0F 
                   Maximum relative Error < 2.3918895e-007].

                   Note: 
                   1. There are no input checks made. 
                   But Tested for Pi/2 & 3 * Pi/2. 
                   Maximum relative error for CML_f_Pi/2: 8.7422784e-008
                   Exception from the above relative error: 
                   Maximum relative error for 3 * CML_f_Pi/2: 1.0493895e-006
                   2. Average cycles consumed on c66x : 142
                   

  \param[out]      f_tan :  Tagent of f_angle

  \author          Jyothy Thomas/Lars Ulveland

  \testmethod      Module testing using Courage
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-9433-0003c62b   

*****************************************************************************/
extern float32 CML_f_tan66(float32 f_angle);
/*****************************************************************************
  Functionname:    CML_f_atan67                                               *//*!

  \brief           computes atan(x) with at least 6.6 decimal digits accuracy
                   Maximum error is 2.05e-7. Average is 3e-8.

  \description     The series atan(x) = x(1 + (c0 + (c1 + (c2 + (c3*x^2))x^2)x^2)x^2)x^2)
                   is used. For abs(x) > (sqrt(2) - 1),
                   atan((x-1)/(x+1)) = atan(x) - pi/4 is used,
                   and for abs(x) > (sqrt(2) + 1), atan((x+1)/(x-1)) = Pi/2 - atan(x) is used.
                   Reference function coded in Matlab Atan5.
				   @startuml
                    start  
                        :f_AbsArg = abs(f_Arg);
						if(f_AbsArg > f_Sqrtof2Plus1) then
							:fnem = -1;
							:fden = f_AbsArg;
						else (no)
							:fnem = f_AbsArg - 1;
							:fden = f_AbsArg + 1;
						endif
						:f_TransformedArg = (fnem / fden);
						if( f_AbsArg > f_Sqrtof2Minus1) then
							:f_at = f_TransformedArg;
						else (no)
							:f_at = f_AbsArg;
						endif
						:series expansion : f_t = atan(x) = x(1 + (c0 + (c1 + (c2 + (c3*x^2))x^2)x^2)x^2)x^2);
						if(f_AbsArg > f_Sqrtof2Plus1) then (yes)
							:f_t = half_Pi - f_t;
							note: To improve accuracy of code for abs(f_Arg) greater than f_Sqrtof2Plus1.
						else if(f_AbsArg > f_Sqrtof2Minus1) (yes)
							:f_t += f_QuarterPiUpperMantissa;
							:f_t += f_QuarterPiLowerMantissa;
							note: To improve accuracy of code for abs(f_Arg) greater than f_Sqrtof2Minus1.
						else (no)
						endif
						:f_T * sign;
                    stop
                   @enduml
  \InOutCorrelation 
  
  \param[in]       f_Arg : Argument to inverse Tangents

  \return          arctangent of f_tan

  \author         Lars Ulveland/Jeevan Kotre

  \testmethod 
  
  \traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6403-0005b460
*****************************************************************************/
extern float32 CML_f_atan67(float32 f_Arg);

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
                        @startuml
                        start  
                            if(f_cos >= 1.0F) then (YES)
                               :f_angle = 0.0F;
                               :Return f_angle;
                            else if(f_cos <= -1.0F) then (YES)
                               :f_angle = Pi;
                               :Return f_angle;
                            else (NO)
                                :Call CML_Sqr to square f_cos and store in f_tmp1;
                                :Subtract the squared value from 1.0F and store in f_tmp1;
                                if(CML_OPT_c66x switch is defined) then (YES)
                                   :Call CML_f_invSqrt67(f_tmp1) and store in f_tmp2; 
                                   :Multiply f_cos * f_tmp2 and store in f_tmp3;
                                else (NO)
                                   :Divide f_cos with CML_f_Sqrt(f_tmp1) and store in f_tmp3;
                                endif
                            :Call CML_f_atan66(f_tmp3) and store in f_tmp4;
                            :Subtract f_tmp4 from C_HALFPI and return the output;	
                           endif
                        stop
                        @enduml
  \param[in]       f_cos : value for which we want the inverse cosinus
                           Ideal values are [-1,..,0,..,1]

  \return          arccosinus corresponding to the value f_cos, in radians

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6412-0005b460
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
                    @startuml
                    start  
                        if(f_sin >= 1.0F) then (YES)
                           :f_angle = Pi/2;
                        else if (f_sin <= -1.0F) then (YES)
                           :f_angle = -Pi/2;
                        else  (NO)
                           :Call CML_Sqr to square f_sin and store in f_tmp1;
                           :Subtract = f_tmp1 from 1.0F and store in f_tmp2;
                           if(CML_OPT_c66x switch is defined) then (YES)
                              :Call CML_f_invSqrt67(f_tmp2) and store result in f_tmp4; 
                              :Multiply f_sin * f_tmp1 and store in f_tmp4;
                           else (NO)
                              :Divide f_sin with CML_f_Sqrt(f_tmp2) and store result in f_tmp4;
                           endif
                           :Call CML_f_atan66(f_tmp4) and store in f_angle;
                           endif						
                        :Return the f_angle;		
                    stop
                    @enduml
  \param[in]       f_sin : value for which we want the inverse sinus
                           Ideal values are [-1,..,0,..,1]

  \return          Arcsine corresponding to the value f_sin, in radians

  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau

  \testmethod  
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6412-0005b460
*****************************************************************************/
extern float32 CML_f_asin66(float32 f_sin);

/*****************************************************************************
  Functionname:    CML_f_atan2                                              *//*!

  \brief           computes the four-quadrant atan2(y/x) with 
                   about 6.6 decimal digits accuracy
				   Maximum error is 2.3826523e-007.

  \description     This function computes the four-quandrant arctangent with 
                   about 6.6 decimal digits accuracy.
                   The input arguments are f_yaxis and f_xaxis. 
                   @startuml
                    start  
                        if(f_xaxis > CML_f_AlmostZero) then (yes)
							:calculate f_yaxis/f_xaxis and store result in f_Temp;
							if(CML_GOLDDUST) then (yes)
								:f_temp = f_yaxis / f_xaxis;
							else
								:f_temp = f_yaxis * CML_f_fastInv69(f_xaxis);
							endif
							:Call CML_f_atan67(f_Temp);
						else
							if(f_xaxis < CML_f_AlmostNegZero)
								:calculate f_yaxis/f_xaxis and store result in f_Temp;
								if (CML_GOLDDUST) then (yes)
									:f_temp = -f_yaxis / f_xaxis;
								else
									:f_temp = f_yaxis * CML_f_fastInv69(f_xaxis);
								endif
								:Call CML_f_atan67(f_Temp);
								if(f_yaxis < CML_f_AlmostNegZero) then (yes)
									:resultant angle will be shifted by -pi;
								else
									:resultant angle will be shifted by pi;
								endif
							else
								if(f_yaxis < CML_f_AlmostNegZero) then (yes)
									:resultant angle is -pi/2;
								else if(f_yaxis > CML_f_AlmostZero) then (yes)
									:resultant angle is pi/2;
								else
									:resultant angle is 0;
								endif
							endif
						endif
                    stop
                   @enduml

  \param[in]       f_xaxis : any float value.
                             Optimal values are [-MAX_ANGLE,..,MAX_ANGLE] 
  \param[in]       f_yaxis : any float value.
                             Optimal values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE is cube root of max value of float32

  \return          the four-quadrant arctangent of f_yaxis/f_xaxis in 
                   radians [-Pi, Pi]
                   if x=0 and y=0 the result is 0

  \author          dan.oprisan@contiautomotive.com

  \testmethod  	   Courage testing.
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6403-0005b460    
*****************************************************************************/
extern float32 CML_f_atan2(float32 f_yaxis, float32 f_xaxis);



/*****************************************************************************
  Functionname:    CML_f_Sine69Core                                     *//*!

  \brief           7th order non-taylor polynomial approximation of sine,
                   with 6.9 decimals relative accuracy.

  \description     Approximates the sine function using a non-taylor 
                   polynomial of the 7th order. Larger input range requires 
                   a range-reducing wrapper
                   sin (x) = (((S4 * x^2 + S3) * x^2 - S2) * x^3) + x                 

 \InOutCorrelation   Implemented algorithm for f_Res = sin(f_Angle):
                     \f[AngleSq = f_Angle * f_Angle \f]
                     \f[y = (((f_S4 * AngleSq + f_S3) * 
                     AngleSq - f_S2) * AngleSq * f_Angle) + f_Angle \f]
                     Where -
                     fS2 = 1.6666654611E-1F, fS3 = 8.3321608736E-3F, 
                     fS4 = -1.9515295891E-4F\n
                     These are constants for the non Taylor polynomial.\n

                     Expected Output : y = sin(f_Angle), Where -
                     Optimal range of x valid from -Pi/4 to +Pi/4.\n.
                     Maximum Relative Error of y in this range <= 1.19e-7\n

  \param[in]      f_Angle : input angle for which we would like to know the 
                  sine, radians

  \return         Sine of f_Angle

  \author         Lars Ulveland, ADC GmbH - Lindau , Jyothy Thomas

  \testmethod      
  \traceability  doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6337-0005b460    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE  float32 CML_f_Sine69Core(float32 f_Angle);
CML_INLINE  float32 CML_f_Sine69Core(float32 f_Angle)
{
    const float32 f_S2 = 1.6666654611E-1F;
    const float32 f_S3 = 8.3321608736E-3F;
    const float32 f_S4 = -1.9515295891E-4F;
    float32 f_AngleSq , f_Res;
    float32 f_temp1, f_temp2, f_temp3, f_temp4;
    f_AngleSq = f_Angle * f_Angle;

    /*f_Res = (((f_S4 * f_AngleSq + f_S3) * 
    f_AngleSq - f_S2) * f_AngleSq * f_Angle) + f_Angle;*/
    f_temp1 = f_S4 * f_AngleSq;
    f_temp2 = f_temp1 + f_S3;
    f_temp3 = f_temp2 * f_AngleSq;
    f_temp4 = f_temp3 - f_S2;
    f_temp1 = f_temp4 * f_AngleSq;
    f_temp2 = f_temp1 * f_Angle; 
    f_Res = f_temp2 + f_Angle;

    return f_Res;
}

/*****************************************************************************
  Functionname:    CML_f_Cos69Core                                               *//*!

  \brief           8th-order non taylor polynomial approximation of Cosine,
                   with 6.9 decimals relative accuracy.

  \description     Approximates the Cosine function using a non-taylor 
                   polynomial of the 8th order. Larger input range requires
                   a range-reducing wrapper.
                   cos(x)=((S4* x^2 + S3) * x^2 + S2) * x^4 - 0.5f * x^2 + 1.0

\InOutCorrelation
                    \f[AngleSq = Angle * Angle \f]
                    \f[f_Res= (( f_S4 * f_AngleSq + f_S3) * 
                     f_AngleSq + f_S2) * f_AngleSq * f_AngleSq - 
                     0.5f * f_AngleSq + 1.0f \f]
                     Where -
                     f_S4, f_S3 & f_S2 are constants for the non Taylor 
                     polinomial.
                     \f[Input   : Angle \f]
                     \f[Output  : Res \f]
  \param[in]       f_Angle : input angle for which we would like to know the 
                             sine, radians
                             Optimal range [-Valid within ±pi/4. 
                             Maximum relative Error: 8.4e-8]
  \return          Cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau , Jyothy Thomas

  \testmethod  
  \traceability    doors://RBGS854A:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6328-0005b460    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE  float32 CML_f_Cos69Core(float32 f_Angle);
CML_INLINE  float32 CML_f_Cos69Core(float32 f_Angle)
{
    const float32 f_S2 = 4.166664568298827E-02F;
    const float32 f_S3 = -1.388731625493765E-03F;
    const float32 f_S4 = 2.443315711809948E-05F;
    float32 f_AngleSq, f_Res;
    float32 f_temp1, f_temp2, f_temp3, f_temp4;

    f_AngleSq = f_Angle * f_Angle;
    
    /* f_Res= (( f_S4 * f_AngleSq + f_S3) * f_AngleSq + f_S2) * 
    f_AngleSq * f_AngleSq - 0.5f * f_AngleSq + 1.0f;*/
    f_temp1 = f_S4 * f_AngleSq;
    f_temp2 = f_temp1 + f_S3;
    f_temp3 = f_temp2 * f_AngleSq;
    f_temp4 = f_temp3 + f_S2;
    f_temp1 = f_temp4 * f_AngleSq;
    f_temp2 = f_temp1 * f_AngleSq;
    f_temp3 = 0.5f * f_AngleSq;
    f_temp4 = f_temp2 - f_temp3;
    f_Res = f_temp4 + 1.0f;

    return f_Res;
}

/*****************************************************************************
  Functionname:    CML_f_ThreeStepSubPiQuarter                           *//*!

  \brief           Three step subtraction of Quarter Pi used in Payne-Hanek 
                   algorithm

  \description     Three-stage subtraction to remove the tiny spikes on some 
                   multiples of pi/2. More of number-theoretic interest, 
                   than algorithmic. These spikes are extremely narrow. 
                   Also, very large arguments are of no interest here.

  \InOutCorrelation
                     \f[f_t = ((f_AbsAngle - (QuarterPi * f_Arg)) - 
                      f_Arg * QuarterPiRes) - f_Arg * QuarterPiRes2 \f]
                     \f[Input   : f_Arg, f_AbsAngle \f]
                     \f[Output  : f_t \f]
  \param[in]       f_Arg      : Input corresponding to the quadrant. 
                   f_AbsAngle : Absolute value of Input angle.

  \return          The range reduced angle which can be passed to sine/cos 
                   core functions

  \author          Lars Ulveland, ADC GmbH - Lindau , Jyothy Thomas

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE  float32 CML_f_ThreeStepSubPiQuarter(float32 f_Arg, 
                                               float32 f_AbsAngle);
CML_INLINE  float32 CML_f_ThreeStepSubPiQuarter(float32 f_Arg, 
                                               float32 f_AbsAngle)
{
    const float32 QuarterPi = 0.78515625F;
    const float32 QuarterPiRes = 2.4187564849853515625e-4F;
    const float32 QuarterPiRes2 = 3.77489497744594108e-8F;
    float32 f_temp1, f_temp2, f_temp3, f_temp4, f_t;

    /* f_t = ((f_AbsAngle - (QuarterPi * f_Arg)) - f_Arg * 
    QuarterPiRes) - f_Arg * QuarterPiRes2;*/  
    f_temp1 = QuarterPi * f_Arg ;
    f_temp2 = f_AbsAngle - f_temp1;
    f_temp3 = f_Arg * QuarterPiRes;
    f_temp4 = f_temp2 - f_temp3;
    f_temp1 = f_Arg * QuarterPiRes2;
    f_t = f_temp4 - f_temp1;
    return f_t;
}

/*****************************************************************************
  Functionname:    CML_f_TwoStepSubPiQuarter                           *//*!

  \brief           Two step subtraction of Quarter Pi used in Payne-Hanek 
                   algorithm

  \description     When two step subtraction is used along with sine/cosine 
                   wrapper, there are tiny error spikes on multiples of pi/2,
                   which are extremely narrow. There is a maximum relative 
                   error of 5.8681715e-005 is observed when two step 
                   subtraction is used in sine/cosine wrappers.
\InOutCorrelation
                  \f[f_t = ((f_AbsAngle - (QuarterPi * f_Arg)) - 
                     f_Arg * QuarterPiRes) \f]
                  \f[Input   : f_Arg, f_AbsAngle \f]
                  \f[Output  : f_t \f]

  \param[in]       f_Arg      :  Input corresponding to the quadrant. 
                   f_AbsAngle : Absolute value of Input angle. 

  \return          The range reduced angle which can be passed to sine/cosine 
                   core functions.

  \author          Lars Ulveland, ADC GmbH - Lindau , Jyothy Thomas

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE  float32 CML_f_TwoStepSubPiQuarter(float32 f_Arg, 
                                             float32 f_AbsAngle);
CML_INLINE  float32 CML_f_TwoStepSubPiQuarter(float32 f_Arg, 
                                             float32 f_AbsAngle)
{
    const float32 QuarterPi = 0.78515625F;
    const float32 QuarterPiRes = 2.419133974E-4F;
    float32 f_temp1, f_temp2, f_temp3, f_t;

    /*f_t = ((f_AbsAngle - (QuarterPi * f_Arg)) - f_Arg * QuarterPiRes);*/
    f_temp1 = QuarterPi * f_Arg;
    f_temp2 = f_AbsAngle - f_temp1;
    f_temp3 = f_Arg * QuarterPiRes;
    f_t = f_temp2 - f_temp3;
    return f_t;
}


/*****************************************************************************
  Functionname:    CML_f_atan18                                           *//*!

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
                    @startuml
                    start  
                        :f_MagicNumber1 = 0.2447F;
                        :f_MagicNumber2 = 0.0663F;
                        :Take absolute of f_x & f_y;
        
                        if(f_abs_x > f_abs_y)  then (yes)
                            :b_Reciprocal = b_TRUE;
                        else (No)
                            :b_Reciprocal = b_FALSE;
                        endif
        
                        if(b_Reciprocal is b_TRUE )  then (yes)
                            :Divide f_y by f_x and store in f_q;
                        else (No)
                            :Divide f_x by f_y and store in f_q;
                        endif
                        : Take absolute of the output and store in f_Absq; 
                        : Implement the formula f_Result = ((CML_f_Pi * 0.25F) * f_q) - f_q * (f_Absq - 1.0F) * (f_MagicNumber1 + (f_MagicNumber2 * f_Absq));
        
                        if(b_Reciprocal is b_TRUE )  then (yes)
                            :f_tmp1 =  Pi/2 - f_Result;
                            :f_tmp2 = -Pi/2 - f_Result;
                            if (f_q > 0.0F)
                                :Return f_tmp1;
                            else  (No)
                                :Return f_tmp2;
                            endif
                        endif
                    stop
                    @enduml
    
  \param[in]       f_x :  x value of Vector (x,y) for which we want to know 
                          the atan.
                          Supported range [Full range of float32]
  \param[in]       f_y :  y value of Vector (x,y) for which we want to know 
                          the atan.
                          Supported range [Full range of float32]
  \attention       Both inputs f_x and f_y should never be equal to zero at 
                   the same time. This will result in a division by zero.
  \return          the inverse tangent of (x,y).

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6403-0005b460    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE float32 CML_f_atan18(float32 f_x, float32 f_y);
CML_INLINE float32 CML_f_atan18(float32 f_x, float32 f_y)
{
    float32 f_q;
    float32 f_Absq;
    float32 f_Result;
    const float32 f_MagicNumber1 = 0.2447F;
    const float32 f_MagicNumber2 = 0.0663F;
    /* The below code implement 
    boolean b_Reciprocal = (CML_f_Abs(f_x) > CML_f_Abs(f_y)) ? b_TRUE : b_FALSE;
    */
    float32 f_tmp1, f_tmp2, f_tmp3, f_tmp4;
    float32 f_abs_x, f_abs_y;
    boolean b_Reciprocal;
    f_abs_x = CML_f_Abs(f_x);
    f_abs_y = CML_f_Abs(f_y);
    b_Reciprocal = (f_abs_x > f_abs_y) ? b_TRUE : b_FALSE;

    if(b_Reciprocal == b_TRUE)
    {
        f_q = f_y / f_x;
    }
    else
    {
        f_q = f_x / f_y;
    }
    f_Absq = CML_f_Abs(f_q);

    /* The below code implement 
    f_Result = ((CML_f_Pi * 0.25F) * f_q) - f_q * (f_Absq - 1.0F) * (f_MagicNumber1 + (f_MagicNumber2 * f_Absq));
    */
    f_tmp1   = CML_f_Pi * 0.25F;
    f_tmp2   = f_MagicNumber2 * f_Absq;
    f_tmp3   = f_tmp1 * f_q;
    f_tmp1   = f_Absq - 1.0F;
    f_tmp4   = f_MagicNumber1 + f_tmp2;
    f_tmp2   = f_q * f_tmp1;
    f_tmp2  *= f_tmp4;
    f_Result = f_tmp3 - f_tmp2;

    if(b_Reciprocal == b_TRUE)
    {
        /* The below code implement 
        f_Result = (f_q > 0.0F) ? (CML_f_Half_Pi - f_Result) : (-CML_f_Half_Pi - f_Result);
        */
        f_tmp1 =  CML_f_Half_Pi - f_Result;
        f_tmp2 = -CML_f_Half_Pi - f_Result;
        f_Result = (f_q > 0.0F) ? f_tmp1 : f_tmp2;		
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
                             Maximum relative Error: 4.72E-04]
  \return          the sine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6337-0005b460       
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE float32 CML_f_sin33Core(float32 f_Angle);
CML_INLINE float32 CML_f_sin33Core(float32 f_Angle)
{
    const float32 f_C0 = 0.63661977F;      // 2 / pi
    const float32 f_C1 = 1.28318531F;      // 2*pi - 5
    const float32 f_C2 = 0.14159265F;      // 3 - pi
    float32 f_tmp1, f_tmp2, f_tmp3, f_tmp4, f_tmp5;
    float32 f_z;
    float32 f_y = f_Angle * f_C0;
    float32 f_y2 = f_y * f_y;

    /* The below code implement 
    float32 f_z = 0.5F * f_y * (CML_f_Pi - (f_y2 * (f_C1 - f_y2 * f_C2)));
    */
    f_tmp1 = f_y2 * f_C2;
    f_tmp5 = f_C1 - f_tmp1;
    f_tmp2 = f_y2 * f_tmp5;
    f_tmp3 = CML_f_Pi - f_tmp2;
    f_tmp4 = 0.5F * f_y;
    f_z    = f_tmp4 * f_tmp3;
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
                             Maximum relative Error: 4.72E-04]
  \return          The cosine of f_Angle

  \author          Lars Ulveland, ADC GmbH - Lindau

  \testmethod  
  \traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-6326-0005b460    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE float32 CML_f_cos33Core(float32 f_Angle);
CML_INLINE float32 CML_f_cos33Core(float32 f_Angle)
{
    const float32 f_C0 = 0.63661977F;      // 2 / pi
    const float32 f_C1 = 1.28318531F;      // 2*pi - 5
    const float32 f_C2 = 0.14159265F;      // pi - 3

    /* The below code implement
    float32 f_y = (CML_f_Abs(f_Angle) - CML_f_Half_Pi) * f_C0;
    float32 f_y2 = f_y * f_y;
    float32 f_z = -0.5F * f_y * (CML_f_Pi - (f_y2 * (f_C1 - f_y2 * f_C2)));
    */
    float32 f_tmp1, f_tmp2, f_tmp3, f_abs_angle;
    float32 f_y, f_y2, f_z;

    f_abs_angle = CML_f_Abs(f_Angle);
    f_tmp1 = f_abs_angle - CML_f_Half_Pi;
    f_y = f_tmp1 * f_C0;
    f_y2 = f_y * f_y;

    f_tmp2 =  f_y2 * f_C2;
    f_tmp3 =  f_C1 - f_tmp2;
    f_tmp1 =  f_y2 * f_tmp3;
    f_tmp2 =  CML_f_Pi - f_tmp1;
    f_tmp3 = -0.5F * f_y;
    f_z    =  f_tmp3 * f_tmp2;
    return f_z;
}

#endif /* #ifndef CML_TRIGO_INCLUDED */

/** @} end defgroup */

