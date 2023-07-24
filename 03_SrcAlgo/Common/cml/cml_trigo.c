/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_trigo.c

  DESCRIPTION:               Trigonometric Functions Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.43 $

  ---*/ /*---
  CHANGES:                   $Log: cml_trigo.c  $
  CHANGES:                   Revision 1.43 2017/11/27 06:19:24CET A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Replaced TRUE and FALSE with b_TRUE and b_FALSE to match the Mainstream update
  CHANGES:                   Revision 1.42 2017/11/16 14:05:41CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_trigo module with coding guidelines.
  CHANGES:                   Revision 1.37 2016/05/20 14:33:21CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.36 2016/04/26 14:29:40CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Changed to the use of the CML_INLINE macro and moved the small, fast trig functions to the header to increase the chance of them being properly inlined.
  CHANGES:                   Revision 1.35 2016/04/19 15:03:11CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Initial version of FastAtan18.
  CHANGES:                   Revision 1.34 2016/03/31 12:27:39CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Fixed a flipped sign and corrected the doxygen documentation.
  CHANGES:                   Revision 1.33 2016/03/23 06:15:48CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for compilation error
  CHANGES:                   Revision 1.32 2016/03/18 11:56:34CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Bugfix and doxygen update in Tanh_58
  CHANGES:                   Revision 1.31 2016/03/17 14:15:59CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Introduced a hyperbolic tangent accurate to 5.8 decimal places for any input.
  CHANGES:                   Revision 1.30 2016/03/17 09:08:18CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Removed unsused variables.
  CHANGES:                   Revision 1.29 2016/03/15 14:43:26CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Improves accuracy of sine and cosine by improved range reduction and improved polynomial evaluation.
  CHANGES:                   
  CHANGES:                   Introduces fast sine and cosine functions without range reduction using a non-taylor quintic approximation.
  CHANGES:                   Revision 1.28 2016/02/16 06:17:20CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for doxygen warning
  CHANGES:                   Revision 1.27 2016/02/05 06:40:34CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Doxygen warning fixes
  CHANGES:                   Revision 1.26 2015/12/08 08:38:09CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Improved accuracy of cosine approximation by adding a dedicated kernel near 0, to avoid loosing trailing bits when adding during the shift of the argument.
  CHANGES:                   Revision 1.25 2015/11/25 11:52:00CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Adding high-precision sine approximation and range-reducing wrappers to call it for sine and cosine.
  CHANGES:                   --- Added comments ---  uidt7777 [Nov 25, 2015 11:52:01 AM CET]
  CHANGES:                   Change Package : 398598:1 http://mks-psad:7002/im/viewissue?selection=398598
  CHANGES:                   Revision 1.24 2015/10/12 05:48:39CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for doxygen warning
  CHANGES:                   --- Added comments ---  uidr5428 [Oct 12, 2015 5:48:40 AM CEST]
  CHANGES:                   Change Package : 383331:1 http://mks-psad:7002/im/viewissue?selection=383331
  CHANGES:                   Revision 1.23 2015/08/25 12:17:51CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 12:17:51 PM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.22 2015/07/22 11:40:57CEST Friebertshaeuser, Markus (uidt0551) 
  CHANGES:                   - fix GCC compiler warnings
  CHANGES:                   --- Added comments ---  uidt0551 [Jul 22, 2015 11:40:58 AM CEST]
  CHANGES:                   Change Package : 359580:1 http://mks-psad:7002/im/viewissue?selection=359580
  CHANGES:                   Revision 1.21 2015/06/11 10:36:30CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Added an if condition in order to avoid the additional multiplication
  CHANGES:                     causing overflow in function GDBexp_power
  CHANGES:                   --- Added comments ---  uidr5428 [Jun 11, 2015 10:36:30 AM CEST]
  CHANGES:                   Change Package : 346742:1 http://mks-psad:7002/im/viewissue?selection=346742
  CHANGES:                   Revision 1.20 2015/04/29 17:46:11CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 5:46:12 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.19 2015/04/22 16:52:23CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Edited docu header of function GDBexp_power
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 22, 2015 4:52:24 PM CEST]
  CHANGES:                   Change Package : 316980:1 http://mks-psad:7002/im/viewissue?selection=316980
  CHANGES:                   Revision 1.18 2015/04/20 16:37:15CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Deleted case 0 in the switch case in function GDB_tan32.
  CHANGES:                   The same case is covered within the default case of the switch statement.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 20, 2015 4:37:16 PM CEST]
  CHANGES:                   Change Package : 317009:1 http://mks-psad:7002/im/viewissue?selection=317009
  CHANGES:                   Revision 1.17 2015/04/20 16:19:05CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Deleted case 0 in the switch case in function GDBtan_52.
  CHANGES:                   The same case is covered within the default case of the switch statement.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 20, 2015 4:19:06 PM CEST]
  CHANGES:                   Change Package : 317008:1 http://mks-psad:7002/im/viewissue?selection=317008
  CHANGES:                   Revision 1.16 2015/04/20 15:48:26CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Deleted case 0 in the switch case in function GDBcos_52. The same case is covered within the default case of the switch statement.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 20, 2015 3:48:27 PM CEST]
  CHANGES:                   Change Package : 317003:1 http://mks-psad:7002/im/viewissue?selection=317003
  CHANGES:                   Revision 1.15 2014/12/05 10:09:30CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - removed multiple return statements in several functions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 5, 2014 10:09:31 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.14 2014/11/10 08:58:20CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - made GDBatan2_66() more robust near pole of input
  CHANGES:                   --- Added comments ---  uidg6516 [Nov 10, 2014 8:58:21 AM CET]
  CHANGES:                   Change Package : 266613:9 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.13 2014/04/07 16:57:44CEST Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - optimised GDB_cos32() for runtime
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 4:57:45 PM CEST]
  CHANGES:                   Change Package : 227281:4 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.12 2014/03/27 11:19:42CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:19:42 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.11 2014/03/25 11:42:16CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:42:16 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.10 2013/05/03 09:58:17CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:58:18 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/04/12 10:41:59CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - Remove inclusion of math.h
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 12, 2013 10:41:59 AM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/04/09 12:59:31CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - - Move the sqrt approximation from cml_trigo to cml_misc
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:59:31 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2012/11/22 20:37:47CET Kaelberer, Stephan (uidu2442)
  CHANGES:                   corrected for win
  CHANGES:                   --- Added comments ---  uidu2442 [Nov 22, 2012 8:37:48 PM CET]
  CHANGES:                   Change Package : 168105:2 http://mks-psad:7002/im/viewissue?selection=168105
  CHANGES:                   Revision 1.6 2012/11/22 17:00:40CET Kaelberer, Stephan (uidu2442)
  CHANGES:                   Quick fix to use correct Sqrt function in ECU.
  CHANGES:                   --- Added comments ---  uidu2442 [Nov 22, 2012 5:00:41 PM CET]
  CHANGES:                   Change Package : 168105:1 http://mks-psad:7002/im/viewissue?selection=168105
  CHANGES:                   Revision 1.5 2012/10/19 11:14:22CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - Fix sin, cos, tan
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 19, 2012 11:14:25 AM CEST]
  CHANGES:                   Change Package : 163252:1 http://mks-psad:7002/im/viewissue?selection=163252
  CHANGES:                   Revision 1.4 2012/10/12 13:58:19CEST Oprisan, Dan (oprisand)
  CHANGES:                   - Add MOD, REM, CEI, FLOOR functions to CML
  CHANGES:                   - remove obsolete FMOD_ macro from cml_mapping.h
  CHANGES:                   --- Added comments ---  oprisand [Oct 12, 2012 1:58:19 PM CEST]
  CHANGES:                   Change Package : 139701:13 http://mks-psad:7002/im/viewissue?selection=139701
  CHANGES:                   Revision 1.3 2012/09/20 13:29:43CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:43 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:19:56CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - remove German special characters in comments and review tags
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:19:56 PM CEST]
  CHANGES:                   Change Package : 159154:2 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:18CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/
#define PI_OVER_SIX   (CML_f_Pi / 6.F)
#define SIX_OVER_PI   (6.F / CML_f_Pi)
#define SIN_30   0.5F
#define COS_30   0.8660254038F    /* sqrt(0.75) */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
static float32 CML_f_tan56s(float32 f_angle);

#if (GDB_TRIG_OPTIMIZED)
  #if (GDB_TRIG_SMALL_SERIES)
    static float32 CML_f_tan32s(float32 f_angle);
    #if (GDB_TRIG_WITH_EXP)
      static float32 CML_f_exp100s(float32 f_power);
    #endif
  #endif
#endif

/*****************************************************************************
  Functionname:    CML_f_tanh58                                           */ /*!

  @brief           Calculates the hyperbolic tangent with 5.8 decimals 
                   relative accuracy. Maximum relative error is 1.35e-6

  @description     Approximates the hyperbolic tangent using a rational 
                   function for arguments < 8, and by sign(arg) * 1 for 
                   larger arguments. The method has no poles on the real
                   axis.

  @param[in]       f_Arg : input argument for which we would like to know the 
                           hyperbolic tangent.
                           Supported range [Full range of float32]

  @return          the hyperbolic tangent of f_Arg
  @author          Lars Ulveland, ADC GmbH - Lindau
*****************************************************************************/
float32 CML_f_tanh58(float32 f_Arg)
{
  const float32 f_C1 = 94.9339451088F;
  const float32 f_C2 = 1.06315869e+03F;
  const float32 f_C3 = 1.88748783e+05F;
  const float32 f_C4 = 5.86237309e+06F;

  const float32 f_C5 = 4.03183926e+03F;
  const float32 f_C6 = 1.64253046e+06F;
  const float32 f_C7 = 1.28592857e+08F;
  const float32 f_C8 = 1.11307745e+09F;

  float32 f_Res;

  float32 f_AbsArg = (f_Arg < 0.0F) ? -f_Arg : f_Arg;

  if (f_AbsArg > 8.0F)  // Above 8, tanh is so close to ±1 that we cannot approximate more accurately.
  {
    f_Res = (f_Arg > 0.0F) ? 1.0F : -1.0F;
  }
  else
  {
    float32 f_ArgSquare;
    float32 f_Nom;
    float32 f_Den;
    f_Arg *= 2.0F;
    f_ArgSquare = f_Arg * f_Arg;

    f_Nom = f_C1 * f_Arg * ((( f_ArgSquare + f_C2 ) * f_ArgSquare + f_C3 ) * f_ArgSquare + f_C4 );
    f_Den = (( ( f_ArgSquare + f_C5) * f_ArgSquare + f_C6 ) * f_ArgSquare + f_C7 ) * f_ArgSquare + f_C8;
    f_Res = f_Nom / f_Den;
  }
  return f_Res;
}

#if (GDB_TRIG_OPTIMIZED)

/*****************************************************************************
  Functionname:    CML_f_sin66Core                                       */ /*!

  @brief           Calculates the sine with 6.6 decimals relative accuracy.

  @description     Approximates the sine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Valid on the interval [-pi/2..pi/2]. 
                   Larger input range requires a range-reducing wrapper.

  @param[in]       f_Angle : input angle for which we would like to know the 
                             sine, radians
                             Optimal range [-CML_f_Half_Pi,..,CML_f_Half_Pi]
  @return          the sine of f_Angle
  @author          Lars Ulveland, ADC GmbH - Lindau
*****************************************************************************/
float32 CML_f_sin66Core(float32 f_Angle)
{
  const float32 f_C2 = -1.66666667e-1F;   // -1/3!
  const float32 f_C3 =  8.33333333e-3F;   //  1/5!
  const float32 f_C4 = -1.98412698e-4F;   // -1/7!
  const float32 f_C5 =  2.75573192e-6F;   //  1/9!
  const float32 f_C6 = -2.50521084e-8F;   // -1/11!

  float32 f_AngleSquare = f_Angle * f_Angle;

  // Contrary to the cosine, this series actually benefits from Horners scheme, gaining 1-2 Ulps.
  return f_Angle * (1.0F + (f_AngleSquare * (f_C2 + f_AngleSquare *(f_C3 + f_AngleSquare * (f_C4 + f_AngleSquare * (f_C5 + (f_C6 * f_AngleSquare)))))));
}
/*****************************************************************************
  Functionname:    CML_f_cos66Core                                       */ /*!

  @brief           Calculates the cosine with 6.6 decimals relative accuracy.

  @description     Approximates the sine function using a polynomial
                   of the 8th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Valid on the interval [-pi/4..pi/4]. 
                   Larger input range requires a range-reducing wrapper.

  @param[in]       f_Angle : input angle for which we would like to know the 
                             cosine, radians
                             Optimal range [-CML_f_Half_Pi,..,CML_f_Half_Pi]
  @return          the cosine of f_Angle
  @author          Lars Ulveland, ADC GmbH - Lindau
*****************************************************************************/
float32 CML_f_cos66Core(float32 f_Angle)
{
  const float32 f_C2 = -0.5F;				    // -1/2!
  const float32 f_C3 =  4.16666667e-2F;	//  1/4!
  const float32 f_C4 = -1.38888889e-3F;	// -1/6!
  const float32 f_C5 =  2.4801587e-5F;	//  1/8!

  float32 f_AngleSquare = f_Angle * f_Angle;
  float32 f_Angle_4	    = f_AngleSquare * f_AngleSquare;
  float32 f_Angle_6     = f_AngleSquare * f_Angle_4;
  float32 f_Angle_8     = f_Angle_4 * f_Angle_4;
  
  // Actually faster than Horner, since the terms can be calculated independently as soon as the powers are available.
  // For this series, Horners scheme does not improve accuracy by a single ulp.
  return 1.0F + ((f_C2 * f_AngleSquare) + ((f_C3 * f_Angle_4) + ((f_C4 * f_Angle_6) + (f_C5 * f_Angle_8))));
}
/*****************************************************************************
  Functionname:    CML_f_sin66                                           */ /*!

  @brief           Calculates the sine with 6.6 decimals relative accuracy.

  @description     Approximates the sine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Performs bounds wrapping, but looses accuracy for very
                   large arguments due to the reduced resolution of the argument.

  @param[in]       f_Angle : input angle for which we would like to know the 
                             sine, radians
                             Supported values [Full range of float32]
  @return          the sine of f_Angle
  @author          Lars Ulveland, ADC GmbH - Lindau
*****************************************************************************/
float32 CML_f_sin66(float32 f_Angle)
{
  float32 f_AbsAngle = CML_f_Abs(f_Angle);
  float32 f_Res;

  if (f_AbsAngle <= C_HALFPI)    // The direct route.
  {
    f_Res = CML_f_sin66Core(f_Angle);
  }
  else // Here, we first transform the absolute angle to < 2*Pi, then if necessary to < Pi and < Pi/2
  {
    float32 f_SignAngle = (f_Angle < 0.0F) ? -1.0F : 1.0F;

    if (f_AbsAngle > C_TWOPI)
    {
      float32 f_Quotient = f_AbsAngle / C_TWOPI;
      f_AbsAngle = (f_AbsAngle - ((float32)(sint32)(f_Quotient)* C_TWOPI));
    }
    // Here, we know that the angle is 0..2Pi
    if (f_AbsAngle <= C_HALFPI)    // The direct route.
    {
      f_Res = f_SignAngle * CML_f_sin66Core(f_AbsAngle);
    }
    else if (f_AbsAngle <= C_THREEHALFPI) // Mirror in Pi/2
    {
#if (defined(_TMS320C6X) || defined(__TMS470__) || defined(_MSC_VER))
      f_Res = -f_SignAngle * CML_f_sin66Core((float32)((float64)(f_AbsAngle) - CML_d_Pi));
#else
      f_Res = -f_SignAngle * CML_f_sin66Core(f_AbsAngle - CML_f_Pi);
#endif
    }
    else
    {
      // move from (C_THREEHALFPI to C_TWOPI) to (-C_HALFPI to 0)
#if (defined(_TMS320C6X) || defined(__TMS470__) || defined(_MSC_VER))
      f_Res = f_SignAngle * CML_f_sin66Core((float32)((float64)(f_AbsAngle) - CML_d_Two_Pi));
#else
      f_Res = f_SignAngle * CML_f_sin66Core(f_AbsAngle - CML_f_two_Pi);
#endif
    }
  }

  return f_Res;
}

/*****************************************************************************
  Functionname:    CML_f_cos66                                           */ /*!

  @brief           Calculates the cosine with 6.6 decimals relative accuracy.

  @description     Approximates the cosine function using a polynomial
                   of the 11th degree. The polynomial are the odd terms of the
                   Taylor expansion of the exponential function.
                   Performs bounds wrapping, but looses accuracy for very
                   large arguments due to the reduced resolution of the argument.

  @param[in]       f_Angle : input angle for which we would like to know the 
                             cosine, radians
                             Supported values [Full range of float32]
  @return          the cosine of f_Angle
  @author          Lars Ulveland, ADC GmbH - Lindau
*****************************************************************************/
float32 CML_f_cos66(float32 f_Angle)
{
  float32 f_AbsAngle = CML_f_Abs(f_Angle);	// cos is symmetric, sign doesn't matter.
  float32 f_Res;

  if (f_AbsAngle > C_TWOPI)
  {
    float32 f_Quotient = f_AbsAngle / C_TWOPI;
    f_AbsAngle = (f_AbsAngle - ((float32)(sint32)(f_Quotient)* C_TWOPI));
  }
  if (f_AbsAngle <= C_QUARTERPI)				// Cos kernel only converges within pi / 4. For very small angles, the shift by pi/2 to use sin reduces accuracy.
  {
    f_Res = CML_f_cos66Core(f_AbsAngle);
  }
  else if (f_AbsAngle < CML_f_Pi)    
  {
#if (defined(_TMS320C6X) || defined(__TMS470__) || defined(_MSC_VER))
    f_Res = -CML_f_sin66Core((float32)((float64)(f_AbsAngle) - CML_d_Pi_Half));
#else
    f_Res = -CML_f_sin66Core(f_AbsAngle - CML_f_Half_Pi);
#endif
  }
  else		// Here, we have already reduced to under 2 pi, so only [pi..2*pi] remains.
  {
#if (defined(_TMS320C6X) || defined(__TMS470__) || defined(_MSC_VER))
    f_Res = CML_f_sin66Core((float32)((float64)(f_AbsAngle) - CML_d_ThreeHalf_Pi));
#else
    f_Res = CML_f_sin66Core(f_AbsAngle - (CML_f_two_Pi * 0.75F));
#endif
  }
  return f_Res;
}
/*****************************************************************************
  Functionname:    CML_f_cos32                                           */ /*!

  @brief           Calculates the cosine with 3.2 decimals accuracy

  @description     It reduces the input argument's range to [0, pi/2],
                   and then performs the approximation.
                   Algorithm:
                           cos(x)= c1 + c2*x**2 + c3*x**4
                   which is the same as:
                           cos(x)= c1 + x**2(c2 + c3*x**2)

  @param[in]       f_angle : input angle for which we would like to know the cosine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE = [max range of uint32] * CML_f_two_Pi
  @return          the cosine of f_angle
  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_cos32(float32 f_angle)
{
  /*--- VARIABLES ---*/
  uint32  u_n;
  float32 f_angle_square, f_tmp;
  float32 f_Ret;

  /* remove sign, as COS function is symmetric */
  f_angle = CML_f_Abs(f_angle);

  /* Calculate approximation depending on quadrant. First, check if f_angle is in 1st
     one. */
  if (f_angle < CML_f_Half_Pi)
  {
    f_angle_square = CML_Sqr(f_angle);
    f_tmp          = CML_f_MultAdd(C_COS_32_C3, f_angle_square, C_COS_32_C2);
    f_Ret          = CML_f_MultAdd(f_angle_square, f_tmp, C_COS_32_C1);
  }

  /* 2nd and 3rd quadrant. */
  else if (f_angle < (CML_f_Pi + CML_f_Half_Pi))
  {
    f_angle_square = CML_f_Pi - f_angle;
    f_angle_square = CML_f_Abs(f_angle_square);
    f_angle_square = CML_Sqr(f_angle_square);
    f_tmp          = CML_f_MultAdd((-1.0f)*C_COS_32_C3, f_angle_square, (-1.0f)*C_COS_32_C2);
    f_Ret          = CML_f_MultAdd(f_angle_square, f_tmp, (-1.0f)*C_COS_32_C1);
  }

  /* 4th quadrant. */
  else if (f_angle < CML_f_two_Pi)
  {
    f_angle_square = CML_f_two_Pi - f_angle;
    f_angle_square = CML_Sqr(f_angle_square);
    f_tmp          = CML_f_MultAdd(C_COS_32_C3, f_angle_square, C_COS_32_C2);
    f_Ret          = CML_f_MultAdd(f_angle_square, f_tmp, C_COS_32_C1);
  }

  /* f_angle is out of 1st period. --> Shift it to [-PI..+PI] and use symmetry of
     COS. */
  else
  {
    /* limit to two_pi : f_angle = mod(f_angle, two_pi) limitation: quotient shall no exceed
       C_LONG_MAX. => f_angle < (LONG_MAX * C_TWOPI) Regarding to float32 accuracy of
       about 7 decimals, the reasonable threshold for f_angle is reached much earlier. */
    f_tmp = f_angle * (1.0f / CML_f_two_Pi);
    u_n   = (uint32) (f_tmp);

    /* Shift f_angle to [-PI..PI]. Due to symmetry of COS, it's enough to evaluate
       [0..PI]. */
    f_angle   = (f_angle - ((float32)u_n * CML_f_two_Pi)) - CML_f_Pi;
    f_angle   = CML_f_Abs(f_angle);

    /* Calculate approximation depending on quadrant. First, check if f_angle is in
       2nd (or 3rd) one. */
    if (f_angle > CML_f_Half_Pi)
    {
      f_angle_square = CML_f_Pi - f_angle;
      f_angle_square = CML_Sqr(f_angle_square);
      f_tmp          = CML_f_MultAdd(C_COS_32_C3, f_angle_square, C_COS_32_C2);
      f_Ret          = CML_f_MultAdd(f_angle_square, f_tmp, C_COS_32_C1);
    }

    /* 1st (or 4th) quadrant). */
    else
    {
      f_angle_square = CML_Sqr(f_angle);
      f_tmp          = CML_f_MultAdd(C_COS_32_C3, f_angle_square, C_COS_32_C2);
      f_Ret          = -(CML_f_MultAdd(f_angle_square, f_tmp, C_COS_32_C1));
    }
  }

  return (f_Ret);
} /* CML_f_cos32() */


/*****************************************************************************
  Functionname:    CML_f_sin32                                           */ /*!

  @brief           Calculates the sine with 3.2 decimals accuracy 

  @description     This function calculates the sine with 3.2 decimals 
                   accuracy.
                   The sine is just cosine shifted a half-pi, 
                   so the argument is adjusted and the cosine 
                   approximation is called.

  @param[in]       f_angle : input angle for which we would like to know the 
                             sine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE =
                             ([max range of uint32] * CML_f_two_Pi)-C_HALFPI
  @return          the sine of f_angle

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_sin32(float32 f_angle)
{
 return CML_f_cos32(C_HALFPI - f_angle);
}


/*****************************************************************************
  Functionname:    CML_f_tan32s                                          */ /*!

  @brief           Computes tan(pi *x/4)

  @description     Accurate to about 3.2 decimal digits over the range [0, pi/4].
                   Note that the function computes tan(pi*x/4), 
                   NOT tan(x); it's up to the range reduction algorithm that 
                   calls this to scale things properly.
                   Algorithm:    tan(x)= x*c1/(c2 + x^2)

  @param[in]       f_angle : the angle (times pi/4) for which we want to know 
                             the tangent, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE is square root of max value of float32

  @return          tan(pi*f_angle/4)

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
static float32 CML_f_tan32s(float32 f_angle)
{
/*--- VARIABLES ---*/
  float32 f_angle_square;

  f_angle_square = CML_Sqr(f_angle);
  return ((f_angle * C_TAN_32_C1)/(C_TAN_32_C2 + f_angle_square));
}


/*****************************************************************************
  Functionname:    CML_f_tan32                                           */ /*!

  @brief           Computes the tangent of x with accuracy of about 3.2 decimal digits

  @description     This is the main tangent approximation "driver". 
                   It reduces the input argument's range to [0, pi/4], 
                   and then calls the approximator.  
                   WARNING: We do not test for the tangent approaching 
                   infinity,  which it will at x=pi/2 and x=3*pi/2. 
                   If this is a problem in your application, take 
                   appropriate action.

  @param[in]       f_angle : the angle for which we want to know the 
                             tangent, radians
                             Supported values are [Full range of float32]
                             except ((2*n) + 1)*C_HALFPI, n is any integer.

  @return          the tangent of f_angle

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_tan32(float32 f_angle)
{
/*--- VARIABLES ---*/
  float32 f_tan;                   /*!< return value */
  uint32 u_octant;             /*!< what octant are we in? */
  boolean b_sign = b_FALSE;       /*!< TRUE, if arg was < 0 */
  float32 f_tmp;

  if (f_angle < 0.0f)
  {
    f_angle = -f_angle;
    b_sign = b_TRUE;
  }

  /* linit to two pi */
  if (f_angle > C_TENPI)
  {
    f_angle = CML_f_ModTrig(f_angle, C_TWOPI);
  }
  else
  {
    while (f_angle >= C_TWOPI)
    {
      f_angle -= C_TWOPI;
    }
  }

  /*! Get octant # (0 to 7) */
  f_tmp = f_angle * C_FOUR_OVER_PI;
  u_octant = (uint32)f_tmp;

  switch (u_octant)
  {
  case 1:
    f_tan =  1.0f / CML_f_tan32s( ((C_HALFPI - f_angle) * C_FOUR_OVER_PI));
    break;
  case 2:
    f_tan = -1.0f / CML_f_tan32s( ((f_angle - C_HALFPI) * C_FOUR_OVER_PI));
    break;
  case 3:
    f_tan = - CML_f_tan32s( ((CML_f_Pi - f_angle) * C_FOUR_OVER_PI));
    break;
  case 4:
    f_tan = CML_f_tan32s( ((f_angle - CML_f_Pi) * C_FOUR_OVER_PI));
    break;
  case 5:
    f_tan =  1.0f / CML_f_tan32s( ((C_THREEHALFPI - f_angle) * C_FOUR_OVER_PI));
    break;
  case 6:
    f_tan = -1.0f / CML_f_tan32s( ((f_angle - C_THREEHALFPI) * C_FOUR_OVER_PI));
    break;
  case 7:
    f_tan = - CML_f_tan32s( ((C_TWOPI - f_angle) * C_FOUR_OVER_PI));
    break;
  default:
  /*Case 0*/
    f_tan = CML_f_tan32s( (f_angle * C_FOUR_OVER_PI));
    break;
  }

  if (b_sign == b_TRUE)
  {
    f_tan = -f_tan;
  }

  return (f_tan);
}


/*****************************************************************************
  Functionname:    CML_f_cos52                                            */ /*!

  @brief           Calculates the cosine with 5.2 decimals accuracy 

  @description     It reduces the input argument's range to [0, pi/2],  
                   and then performs the approximation.
                   Algorithm:
                   cos(x)= c1 + c2*x^2 + c3*x^4 + c4*x^6
                   which is the same as:
                   cos(x)= c1 + x^2(c2 + c3*x^2 + c4*x^4)
                   cos(x)= c1 + x^2(c2 + x^2(c3 + c4*x^2))

  @param[in]       f_angle : angle for which cosine has to be found
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE = [max range of uint32] * CML_f_two_Pi

  @return          cosine of f_angle (double)

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_cos52(float32 f_angle)
{
/*--- VARIABLES ---*/
  uint32  u_quad;
  float32 f_angle_square, f_tmp;
  float32 f_resultValue; /* result value */

  if (f_angle < 0.0F)
  {
    f_angle = -f_angle;
  }

  /* limit to two pi */
  if (f_angle > C_TENPI)
  {
    f_angle = CML_f_ModTrig(f_angle, C_TWOPI);
  }
  else
  {
    /* sensible argument, use faster while loop */
    while (f_angle >= C_TWOPI)
    {
      f_angle -= C_TWOPI;
    }
  }

  f_tmp = f_angle * C_TWO_OVER_PI;
  u_quad = (uint32)f_tmp;
  switch (u_quad)
  {
  case 1:
    f_angle_square = (CML_f_Pi - f_angle) * (CML_f_Pi - f_angle);
    f_resultValue = -(C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
    break;
  case 2:
    f_angle_square = (f_angle - CML_f_Pi) * (f_angle - CML_f_Pi);
    f_resultValue = -(C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
    break;
  case 3:
    f_angle_square = (C_TWOPI - f_angle) * (C_TWOPI - f_angle);
    f_resultValue = (C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
    break;
  default:
    /*Case 0*/
    f_angle_square = f_angle * f_angle;
    f_resultValue = (C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
    break;
  }

  return f_resultValue;
}


/*****************************************************************************
  Functionname:    CML_f_sin52                                            */ /*!

  @brief           Calculates the sine with 5.2 decimals accuracy 

  @description     The sine is just cosine shifted a half-pi, 
                   so we'll adjust the argument and call the cosine approximation.

  @param[in]       f_angle : input angle for which we would like to know the 
                             sine, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE =
                             ([max range of uint32] * CML_f_two_Pi)-C_HALFPI

  @return          the sine of f_angle 

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_sin52(float32 f_angle)
{
  return CML_f_cos52(C_HALFPI - f_angle);
}


/*****************************************************************************
  Functionname:    CML_f_tan56s                                           */ /*!

  @brief           computes tan(pi*x/4)

  @description     Accurate to about 5.6 decimal digits over 
                   the range [0, pi/4].
                   Note that the function computes tan(pi*x/4), 
                   NOT tan(x); it's up to the range
                   reduction algorithm that calls this to scale 
                   things properly.
                   Algorithm: tan(x)= x(c1 + c2*x^2)/(c3 + x^2)

  @param[in]       f_angle : the angle (times pi/4) for which we want to know 
                             the tangent, radians
                             Supported values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE is cube root of max value of float32

  @return          parameter for tan_56(f_angle)

  @pre             CML_tan_56(x)

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
static float32 CML_f_tan56s(float32 f_angle)
{
  return (f_angle *(C_TAN_56_C1 + (C_TAN_56_C2 * CML_Sqr(f_angle)))) / (C_TAN_56_C3 + CML_Sqr(f_angle));
}


/*****************************************************************************
  Functionname:    CML_f_tan52                                            */ /*!

  @brief           Computes the tangent of x with accuracy of about 5.6 
                   decimal digits

  @description     This is the main tangent approximation "driver".
                   It reduces the input argument's range to [0, pi/4],
                   and then calls the approximator.
                    WARNING: We do not test for the tangent approaching
                   infinity,  which it will at x=pi/2 and x=3*pi/2.
                   If this is a problem in your application, take
                   appropriate action.

  @param[in]       f_angle : the angle for which we want to know the 
                             tangent, radians
                             Supported values are [Full range of float32]
                             except ((2*n) + 1)*C_HALFPI, n is any integer.

  @return          the tangent of f_angle

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_tan52(float32 f_angle)
{
/*--- VARIABLES ---*/
  float32 f_tan, f_tmp;
  uint32 u_octant;
  boolean b_sign = b_FALSE;

  if (f_angle < 0.0F)
  {
    f_angle = -f_angle;
    b_sign = b_TRUE;
  }

  /* limit to two pi */
  if (f_angle > C_TENPI)
  {
    f_angle = CML_f_ModTrig(f_angle, C_TWOPI);
  }
  else
  {
    while (f_angle >= C_TWOPI)
    {
       f_angle -= C_TWOPI;
    }
  }

  f_tmp = f_angle * C_FOUR_OVER_PI;
  u_octant = (uint32)f_tmp;

  switch (u_octant)
  {
  case 1:
    f_tan =  1.0F/CML_f_tan56s((C_HALFPI - f_angle)      * C_FOUR_OVER_PI);
    break;
  case 2:
    f_tan = -1.0F/CML_f_tan56s((f_angle - C_HALFPI)      * C_FOUR_OVER_PI);
    break;
  case 3:
    f_tan = -     CML_f_tan56s((CML_f_Pi - f_angle)          * C_FOUR_OVER_PI);
    break;
  case 4:
    f_tan =       CML_f_tan56s((f_angle - CML_f_Pi)          * C_FOUR_OVER_PI);
    break;
  case 5:
    f_tan =  1.0F/CML_f_tan56s((C_THREEHALFPI - f_angle) * C_FOUR_OVER_PI);
    break;
  case 6:
    f_tan = -1.0F/CML_f_tan56s((f_angle - C_THREEHALFPI) * C_FOUR_OVER_PI);
    break;
  case 7:
    f_tan = -     CML_f_tan56s((C_TWOPI - f_angle)       * C_FOUR_OVER_PI);
    break;
  default:
    /*Case 0*/
    f_tan =       CML_f_tan56s(f_angle                   * C_FOUR_OVER_PI);
    break;
  }

  if (b_sign == b_TRUE)
  {
    f_tan = -f_tan;
  }

  return f_tan;
}


/*****************************************************************************
  Functionname:    CML_f_atan66                                           */ /*!

  @brief           computes atan(x) with about 6.6 decimal digits accuracy

  @description     The input argument's range is reduced to [0, pi/12] 
                   before the approximation takes place
                   Algorithm: atan(x)= x(c1 + c2*x^2)/(c3 + x^2)

  @param[in]       f_tan : the "secant length" for which we want to know the 
                           corresponding angle, radians
                           Optimal values are [-MAX_ANGLE,..,MAX_ANGLE], 
                           where MAX_ANGLE is square root of max value of float32

  @return          arctangent of f_tan

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_atan66(float32 f_tan)
{
/*--- VARIABLES ---*/
  float32 f_angle;                             /* return from atan__s function */
  float32 f_tan_square;                            /* The input argument squared */
  boolean b_complement = b_FALSE;           /* TRUE if arg was >1 */
  boolean b_region     = b_FALSE;           /* TRUE depending on region arg is in */
  boolean b_sign       = b_FALSE;           /* TRUE if arg was < 0 */

  /* reduce input argument */
  if (f_tan < 0.0F)
  {
    f_tan = -f_tan;
    b_sign = b_TRUE;       /* argtan(-x) = - arctan(x) */
  }
  if (f_tan > 1.0F)
  {
    f_tan = 1.0F/f_tan;
    b_complement = b_TRUE;   /* keep arg between 0 and 1 */
  }
  if (f_tan > C_TANTWELFTHPI)
  {
    f_tan      = ((f_tan - C_TANSIXTHPI)/(1.F + (C_TANSIXTHPI * f_tan)));  /* reduce arg to under tan(pi/12) */
    b_region = b_TRUE;
  }

  /* do the approximation on the reduced argument */
  f_tan_square = CML_Sqr(f_tan);
  f_angle  = (f_tan * (C_ATAN_66_C1 + (f_tan_square * C_ATAN_66_C2))) / (C_ATAN_66_C3 + f_tan_square);

  /* put result back together */
  if (b_region == b_TRUE)
  {
    f_angle += C_SIXTHPI;      /* correct for region we are in */
  }
  if (b_complement == b_TRUE)
  {
    f_angle = C_HALFPI -f_angle;     /* correct for 1/x if we did that */
  }
  if (b_sign == b_TRUE)
  {
    f_angle = -f_angle;             /* correct for negative arg */
  }

  return (f_angle);
}


/*****************************************************************************
  Functionname:    CML_f_acos66                                           */ /*!

  @brief           implements the acos() function with 6.6 decimals of accuracy

  @description     This function uses the relationships between trigonomtric 
                   and inverse trigonometric functions.
                   tan(arccos x) = sqrt(1 - x^2) / x
                   tan(arcsin x) = x / sqrt(1 - x^2)

  @param[in]       f_cos : value for which we want the inverse cosinus
                           Ideal values are [-1,..,0,..,1]

  @return          arccosinus corresponding to the value f_cos, in radians

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_acos66 (float32 f_cos)
{
  float32 f_angle; /* result value */

  /*! catch invalid input ranges and prevent division by zero below */
  if (f_cos >= 1.0F)
  {
    f_angle = 0.0F;
  }

  else if (f_cos <= -1.0F)
  {
    f_angle = CML_f_Pi;
  }

  else
  {
    f_angle = C_HALFPI - CML_f_atan66(f_cos / CML_f_Sqrt(1.0F - CML_Sqr(f_cos)));
  }

  return f_angle;
}


/*****************************************************************************
  Functionname:    CML_f_asin66                                           */ /*!

  @brief           implements the asin() function with 6.6 decimals of accuracy

  @description     This function uses the relationships between trigonomtric 
                   and inverse trigonometric functions.
                   tan(arccos x) = sqrt(1 - x^2) / x
                   tan(arcsin x) = x / sqrt(1 - x^2)

  @param[in]       f_sin : value for which we want the inverse sinus
                           Ideal values are [-1,..,0,..,1]

  @return          arcsinus corresponding to the value f_sin, in radians

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_asin66(float32 f_sin)
{
  float32 f_angle; /* result value */

  /*! catch invalid input ranges and prevent division by zero below */
  if (f_sin >= 1.0F)
  {
    f_angle = C_HALFPI;
  }

  else if (f_sin <= -1.0F)
  {
    f_angle = -C_HALFPI;
  }

  else
  {
    f_angle = CML_f_atan66( f_sin / CML_f_Sqrt(1.0F - CML_Sqr(f_sin)));
  }

  return f_angle;
}


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




#if (GDB_TRIG_WITH_EXP)
/*****************************************************************************
  Functionname:    CML_f_exp100s                                          */ /*!

  @brief           calculates exp(x) (the natural exponential) for some 
                   number x

  @description     Method:
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
                              where MAX_VAL is fifth root of max value of float32.

  @return          exp(f_power)

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
static float32 CML_f_exp100s(float32 f_power)
{
/*--- VARIABLES ---*/
  float32 f_fracpart;
  float32 f_intpart;
  uint32 u_power;

  f_power   *= 4.0F;
  u_power    = (uint32) f_power;
  f_power   -= (float32)u_power;
  f_power   *= 0.25F;
  f_fracpart = (float32) (((((((((f_power * C_EXP_100_E) + C_EXP_100_D) * f_power) + C_EXP_100_C) * f_power) + C_EXP_100_B) * f_power) + C_EXP_100_A) * f_power) + 1.0F;
  f_intpart  = CML_f_expPower(C_EXP_100_ROOT_E, u_power);

  return (f_intpart * f_fracpart);
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
                              where MAX_VAL is fifth root of max value of float32.

  @return          exp(f_power)

  @author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
*****************************************************************************/
float32 CML_f_exp100(float32 f_power)
{
  float32 f_result; /* result value */


  /*! it is necessary that function exp_100s will be called with positive argument */
  if (f_power < 0.0F)
  {
    f_result = 1.0F / CML_f_exp100s(-f_power);
  }
  else
  {
    f_result = CML_f_exp100s(f_power);
  }

  return f_result;
}
#endif /* CML_TRIG_WITH_EXP */

/*****************************************************************************
  Functionname:    CML_f_atan2                                          */ /*!

  @brief           computes the four-quadrant atan(y/x) with 
                   about 6.6 decimal digits accuracy

  @description     This function computes the four-quandrant arctangent with 
                   about 6.6 decimal digits accuracy.
                   The input arguments are x and y. The situation y=0 is 
                   handled correctly.

  @param[in]       f_xaxis : any number
                             Optimal values are [-MAX_ANGLE,..,MAX_ANGLE] 
  @param[in]       f_yaxis : any number
                             Optimal values are [-MAX_ANGLE,..,MAX_ANGLE], 
                             where MAX_ANGLE is cube root of max value of float32

  @return          the four-quadrant arctangent of f_yaxis/f_xaxis in 
                   radians [-Pi, Pi]
                   if x=0 and y=0 the result is 0

  @author          dan.oprisan@contiautomotive.com
*****************************************************************************/
float32 CML_f_atan2(float32 f_yaxis, float32 f_xaxis)
{
  float32 f_angle;

  /* handle x = 0 */
  if (f_xaxis > CML_f_AlmostZero)
  {
    /* compute arctangent */
    f_angle = CML_f_atan66(f_yaxis / f_xaxis);
  }

  else
  {
    if(f_xaxis < CML_f_AlmostNegZero)
    {
      /* compute arctangent */
      f_angle = CML_f_atan66(f_yaxis / -f_xaxis);

      if(f_yaxis < CML_f_AlmostNegZero)
      {
        f_angle = -CML_f_Pi - f_angle;
      }

      else
      {
        f_angle = CML_f_Pi - f_angle;
      }
    }

    else
    {
      if(f_yaxis < CML_f_AlmostNegZero)
      {
        f_angle = -CML_f_Pi/2.0F;
      }

      else if(f_yaxis > CML_f_AlmostZero)
      {
        f_angle = CML_f_Pi/2.0F;
      }

      else
      {
        f_angle = 0.0F;
      }
    }
  }

  return f_angle;
}
#endif /* CML_TRIG_OPTIMIZED */

/************************************************************************
  Functionname:    CML_f_exp                                          */ /*!

  @brief           Fast approximation exponential function 

  @description     This function does a fast approximation of the 
                   exponential function with the help of some predetermined
                   constant coefficients.

  @param[in]       f_power :  any number
                              Supported values [Full range of float32]

  @return          Approximation of exp(f_power)

  @pre             x < 80, IEEE754 Floating Point format

  @post            Postcondition: none
**************************************************************************** */
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

    /* Reinterprete value as Dword */
    {
      const uint32* ui_pointer = (uint32 *)(&f_power);
      u_iVal = *ui_pointer;
    }

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

      /* Calculate polynom with horner schema */
      f_exp = (((((((((((f_power*f_a1_c) + f_a2_c)*f_power) + f_a3_c)*f_power) + f_a4_c)*f_power) + f_a5_c)*f_power) + 1.F)*f_power) + 1.F;
    }

    /*  Scale back to obtain exp(x) = 2^k * exp(r) */
    {
      const uint32* ui_pointer = (uint32 *)(&f_exp);
      u_iVal = *ui_pointer;
    }
    u_iVal += (  (*((uint32 *)&(s_2base_exp)))<<23UL);
    {
      const float32* f_pointer = (float32 *)(&u_iVal);
      f_exp = *f_pointer;
    }
  } /* if/else (x < -80.0F) */

  return f_exp;
}

/************************************************************************
  Functionname:    CML_f_sincos                                       */ /*!

  @brief           Computes the approximation for sine and cosine for the 
                   given value.

  @description     This function computes the approximation for both sine
                   and cosine for the given value and populates to the memory
                   provided by the pointers passed. 

  @param[in]       f_val :  Angle for which sine and cosine needs to be computed
                            Optimal value [-MAX_VAL,..,MAX_VAL]
                            where MAX_VAL is fifth root of max value of float32.
  @param[out]      p_sin :  sine of f_val
                            Valid float pointer
  @param[out]      p_cos :  cosine of f_val
                            Valid float pointer

  @return          void

  @pre             x < 80, IEEE754 Floating Point format

  @post            Postcondition: none

  @author          thomas.diepolder@contiautomotive.com
                   norman.apel@contiautomotive.com
**************************************************************************** */
void CML_f_sincos(float32 f_val, float32 *p_sin, float32 *p_cos)
{
  float32 f_s1, f_c1, f_val_square;
  float32 f_tmp = (f_val * SIX_OVER_PI) + 0.5F;
  sint32 s_option = (sint32) f_tmp;

  f_val -= (float32) s_option * PI_OVER_SIX;
  s_option = s_option % 12L;

  if(s_option < 0L) {
    s_option += 12L;
  }

  f_val_square = f_val*f_val;

  f_s1 = (((((f_val_square * 0.05F) - 1.F ) * f_val_square) * 0.1666666667F) + 1.F) * f_val;
  f_c1 = (((((((f_val_square * 0.0333333333F) + 1.F) * f_val_square) * 0.0833333333F) - 1.F) * f_val_square) * 0.5F) + 1.F;

  switch(s_option){
    case 0L:
      *p_sin = f_s1;
      *p_cos = f_c1;
      break;

    case 1L:
      *p_sin =  (COS_30 * f_s1) + (SIN_30 * f_c1);
      *p_cos = (-SIN_30 * f_s1) + (COS_30 * f_c1);
      break;

    case 2L:
      *p_sin =  (SIN_30 * f_s1) + (COS_30 * f_c1);
      *p_cos = (-COS_30 * f_s1) + (SIN_30 * f_c1);
      break;

    case 3L:
      *p_sin =  f_c1;
      *p_cos = -f_s1;
      break;

    case 4L:
      *p_sin = (-SIN_30 * f_s1) + (COS_30 * f_c1);
      *p_cos = (-COS_30 * f_s1) - (SIN_30 * f_c1);
      break;

    case 5L:
      *p_sin = (-COS_30 * f_s1) + (SIN_30 * f_c1);
      *p_cos = (-SIN_30 * f_s1) - (COS_30 * f_c1);
      break;

    case 6L:
      *p_sin = -f_s1;
      *p_cos = -f_c1;
      break;

    case 7L:
      *p_sin = (-COS_30 * f_s1) - (SIN_30 * f_c1);
      *p_cos =  (SIN_30 * f_s1) - (COS_30 * f_c1);
      break;

    case 8L:
      *p_sin = (-SIN_30 * f_s1) - (COS_30 * f_c1);
      *p_cos =  (COS_30 * f_s1) - (SIN_30 * f_c1);
      break;

    case 9L:
      *p_sin = -f_c1;
      *p_cos =  f_s1;
      break;

    case 10L:
      *p_sin =  (SIN_30 * f_s1) - (COS_30 * f_c1);
      *p_cos =  (COS_30 * f_s1) + (SIN_30 * f_c1);
      break;

    case 11L:
      *p_sin =  (COS_30 * f_s1) - (SIN_30 * f_c1);
      *p_cos =  (SIN_30 * f_s1) + (COS_30 * f_c1);
      break;
    default:
      /* nothing - misra compatibility */
      break;

    }
}

