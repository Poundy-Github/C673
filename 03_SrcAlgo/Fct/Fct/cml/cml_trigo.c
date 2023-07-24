/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_trigo.c

  DESCRIPTION:               Trigonometric Functions Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.58.1.3 $

  ---*/ /*---
  CHANGES:                   $Log: cml_trigo.c  $
  CHANGES:                   Revision 1.58.1.3 2020/01/08 11:33:59CET Thomas, Jyothy (uid22555) 
  CHANGES:                   corrected alignment
  CHANGES:                   Revision 1.58.1.2 2019/11/18 10:02:53CET Thomas, Jyothy (uid22555) 
  CHANGES:                   checking in changes to get ECU-SIL bit exactness of bCML_f_cos32 on A15.
  CHANGES:                   Revision 1.58.1.1 2019/06/24 10:39:39CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   QAF level 3 warnings have been fixed.
  CHANGES:                   Revision 1.58 2018/07/30 10:28:40CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated function header
  CHANGES:                   Revision 1.57 2018/07/30 08:19:12CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Replaced CML_f_tan52 with CML_f_tan66
  CHANGES:                   Revision 1.56 2018/07/12 13:29:53CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_TRIG_OPTIMIZED has been defined in place older legacy code.
  CHANGES:                   Revision 1.55 2018/06/19 12:17:47CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   atan2() was optimised with use of fast inverse functions.
  CHANGES:                   Revision 1.53 2018/06/07 13:39:08CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   QAC warnings have been fixed.
  CHANGES:                   Revision 1.52 2018/06/06 13:44:02CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_f_atan67 updated for range above f_Sqrtof2Plus1.
  CHANGES:                   Revision 1.51 2018/06/01 11:51:37CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   atan66 functionality has been optimized with atan67 implementation.
  CHANGES:                   Revision 1.50 2018/05/10 12:39:20CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   cml_f_sincos header updated
  CHANGES:                   Revision 1.49 2018/05/10 12:16:36CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Replaced cml_f_sincos with algorithm using Payne-Hanek range reduction.
  CHANGES:                   Revision 1.48 2018/04/24 05:45:55CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   formatting done
  CHANGES:                   Revision 1.47 2018/04/23 11:09:23CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated review comments
  CHANGES:                   Revision 1.46 2018/04/23 09:23:06CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Replaced CML_f_sin66 & CML_f_cos66 with new implementation, which uses Payne-Hanek algorithm. 
  CHANGES:                   The functions are having better accuracy and runtime performance.
  CHANGES:                   Revision 1.45 2018/04/20 04:52:15CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Review comments added
  CHANGES:                   Revision 1.44 2018/04/19 08:11:18CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   OPtimization added for asin66 & acos66
  CHANGES:                   Revision 1.43 2018/03/08 06:29:07CET Thomas, Jyothy (uid22555) 
  CHANGES:                   exponentail functions are moved to cml_exp.c
  CHANGES:                   Revision 1.42 2018/02/26 08:57:04CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.37.2.1 2017/11/09 11:36:20CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Replaced FALSE/TRUE by b_FALSE/b_TRUE
  CHANGES:                   Revision 1.37 2016/05/20 14:33:21CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.37 2016/05/20 14:33:21CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
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
/* PRQA S 0288 EOF */
/* Deactivate QAF warning 0288, Date: 2019-06-18; Reviewer: uidk9586;  
   Reason: There is no risk here as the warning is in comments and not in the source code. */
/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uidk9586;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
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
static float32 CML_f_tan32s(float32 f_angle);


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

    if (f_AbsArg > 8.0F)  // Above 8, tanh is so close to + or - 1 that we cannot approximate more accurately.
    {
        f_Res = (f_Arg > 0.0F) ? 1.0F : -1.0F;
    }
    else
    {
        float32 f_ArgSquare;
        float32 f_Nom;
        float32 f_Den;
        float32 f_tmp1;
        float32 f_tmp2, f_tmp3, f_tmp4;
        f_Arg *= 2.0F;
        f_ArgSquare = f_Arg * f_Arg;

        /*The below code implements 
        f_Nom = f_C1 * f_Arg * ((( f_ArgSquare + f_C2 ) * f_ArgSquare + f_C3 ) * f_ArgSquare + f_C4 );
        f_Den = (( ( f_ArgSquare + f_C5) * f_ArgSquare + f_C6 ) * f_ArgSquare + f_C7 ) * f_ArgSquare + f_C8; */
        f_tmp1 = f_ArgSquare + f_C2;
        f_tmp2 = f_tmp1 * f_ArgSquare;
        f_tmp3 = f_tmp2 + f_C3;
        f_tmp4 = f_tmp3 * f_ArgSquare;
        f_tmp1 = f_tmp4 + f_C4;
        f_tmp2 = f_C1 * f_Arg;
        f_Nom = f_tmp2 * f_tmp1;

        f_tmp3 = f_ArgSquare + f_C5;
        f_tmp4 = f_tmp3 * f_ArgSquare;
        f_tmp1 = f_tmp4 + f_C6;
        f_tmp2 = f_tmp1 *  f_ArgSquare;
        f_tmp3 = f_tmp2 + f_C7;
        f_tmp4 = f_tmp3 * f_ArgSquare;
        f_Den = f_tmp4 + f_C8;
        f_Res = f_Nom / f_Den;
    }
    return f_Res;
}


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
    float32 f_tmp1, f_tmp2, f_tmp3, f_tmp4;
    float32 f_AngleSquare = f_Angle * f_Angle;

    // Contrary to the cosine, this series actually benefits from Horners scheme, gaining 1-2 Ulps.
    /*The below code implements 
    return f_Angle * (1.0F + (f_AngleSquare * (f_C2 + f_AngleSquare *(f_C3 + f_AngleSquare * (f_C4 + f_AngleSquare * (f_C5 + (f_C6 * f_AngleSquare)))))));
    */
    f_tmp1 = f_C6 * f_AngleSquare;
    f_tmp2 = f_C5 + f_tmp1;
    f_tmp3 = f_AngleSquare * f_tmp2;
    f_tmp4 = f_C4 + f_tmp3;

    f_tmp1 = f_AngleSquare * f_tmp4;
    f_tmp2 = f_C3 + f_tmp1;
    f_tmp3 = f_AngleSquare * f_tmp2;
    f_tmp4 = f_C2 + f_tmp3;

    f_tmp1 = f_AngleSquare * f_tmp4;
    f_tmp2 = 1.0F + f_tmp1;
    f_tmp3 = f_Angle * f_tmp2;

    return f_tmp3;  
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
    float32 f_tmp1, f_tmp2, f_tmp3, f_tmp4, f_tmp5;
    float32 f_AngleSquare = f_Angle * f_Angle;
    float32 f_Angle_4	    = f_AngleSquare * f_AngleSquare;
    float32 f_Angle_6     = f_AngleSquare * f_Angle_4;
    float32 f_Angle_8     = f_Angle_4 * f_Angle_4;

    // Actually faster than Horner, since the terms can be calculated independently as soon as the powers are available.
    // For this series, Horners scheme does not improve accuracy by a single ulp.
    /* The below code implements
    return 1.0F + ((f_C2 * f_AngleSquare) + ((f_C3 * f_Angle_4) + ((f_C4 * f_Angle_6) + (f_C5 * f_Angle_8))));
    */
    f_tmp4 = f_C2 * f_AngleSquare;
    f_tmp3 = f_C3 * f_Angle_4;
    f_tmp2 = f_C4 * f_Angle_6;
    f_tmp1 = f_C5 * f_Angle_8;

    f_tmp5 = f_tmp2 + f_tmp1;
    f_tmp1 = f_tmp3 + f_tmp5;
    f_tmp2 = f_tmp4 + f_tmp1;
    f_tmp1 = 1.0F + f_tmp2;

    return f_tmp1; 
}

/*****************************************************************************
  Functionname:    CML_f_sin66                                           */ /*!

  @brief           Calculates the sine of a value,and performs range reduction
                   with 6.9 decimals relative accuracy.

  @description     This function is a wrapper which performs range reduction 
                   on CML_f_Sine69Core. Three-step Payne-Hanek algorithm is 
                   used here for range reduction. Here large input arguments
                   are reduced in the range within + or -pi/4 using this algorithm
                   before calling the core sin & cosine functions.And then the
                   answer and it's sign is appropriately chosen to get sin(x)

  @param[in]       f_Angle : input angle for which we would like to know the 
                             sine, in radians. 
                   Optimal range [ Within �CML_f_two_Pi. Maximum relative
                   Error: 1.19e-7] 
                   [Note:Tested upto �1000 * CML_f_Pi. with stepsize 0.1F 
                   Maximum relative Error: 1.192e-7]

  @return          The sine of f_Angle

  @author          Lars Ulveland, ADC GmbH - Lindau, Jyothy Thomas
*****************************************************************************/
/* PRQA S 1294 20 */
/* Deactivate QAC warning 1294, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: There is no risk here as there is no loss of data in this conversion. */
/* PRQA S 1298,  1802 20 */
/* Deactivate QAC warning 1298, 1802 Date: 2019-06-17; Reviewer: uidk9586;
   Reason: The function is reviewed. There is no risk in violating this rule  as this is an initialization*/
float32  CML_f_sin66(float32 f_Angle)
{
    const uint32 intmax_minusOne = 2147483646;
    const float32 FourOverPi = 1.2732395F;
    float32 f_AbsAngle, f_Arg, f_Res = 0;
    float32 f_t, f_st, f_ct, f_sin, f_temp;
    sint32 Signx = 0;
    uint32 utemp, uQuadranti;
    boolean b_true = 1, b_false = 0, SignS, SignPoly;

    Signx = (f_Angle < 0) ? -1 : 1; 
    f_AbsAngle = CML_f_Abs(f_Angle);  
    f_temp = f_AbsAngle * FourOverPi;

/* PRQA S 1840 10 */
/* Deactivate QAC warning 1840, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: unsigned is fine here as this is to determine the quadrant which is a positive number */
    /* This type casting is to avoid _fixfu function call in c66x */
    uQuadranti = (uint32)(sint32) f_temp; 
    uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
    f_Arg = (float32)uQuadranti;

/* PRQA S 4404 , 1841 , 1843 , 4542 6 */
/* Deactivate QAC warning 4404, 1841, 1843, 4542 Date: 2019-06-17; Reviewer: uidk9586;
   Reason: These operations are required here as per the algorithm  */
    /* SignS = bitand(Quadranti, 4) == 0; */
    utemp = (uQuadranti & 4);
    SignS = (utemp == 0) ? b_true : b_false;

/* PRQA S 1840 ,1841,1843, 4542 10 */
/* Deactivate QAC warning 1840,1841,1843, 4542, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: There is no risk in doing this conversion here as there is no loss of data. */
   /* SignPoly  = ~(bitand(Quadranti - 2, 2) == 0); */
    utemp = ((uQuadranti - 2) & 2);
    SignPoly = (utemp == 0) ? b_false : b_true ;

    /* 3 step Payne Hanek algorithm for range reduction */
    f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);

    /* Sine & Cos computation from core functions */
    f_st = CML_f_Sine69Core(f_t);
    f_ct = CML_f_Cos69Core(f_t);  

    /* Sine or cosine seletion and sign adjustment for quadrant */
    f_sin = SignPoly ? f_st : f_ct;   
    f_sin = SignS ? f_sin: -f_sin;

    /* sin(-x) - -sin(x) */
    f_Res = f_sin * (float32) Signx; 

    return f_Res;
}


/*****************************************************************************
  Functionname:    CML_f_cos66                                          */ /*!

  @brief           Calculates the cosine of a value, and performs range 
                   reduction with 6.9 decimals relative accuracy.

  @description     This function is a wrapper which performs range reduction 
                   on CML_f_Cos69Core. Three-step Payne-Hanek algorithm is 
                   used here for range reduction. Large input arguments
                   are reduced in the range within �pi/4 using this algorithm
                   before calling the core sin & cosine functions.And then the
                   answer and it's sign is appropriately chosen to get cos(x)    
                     
  @param[in]       f_Angle : input angle for which we would like to know the 
                             sine, in radians. 
                   Optimal range [ Within �CML_f_two_Pi. Maximum relative 
                   Error: 1.19e-7]
                   [Note:Tested upto �1000 * CML_f_Pi. with stepsize 0.1F 
                   Maximum relative Error: 1.192e-7]

  @return          The Cosine of f_Angle

  @author          Lars Ulveland, ADC GmbH - Lindau, Jyothy Thomas
*****************************************************************************/
/* PRQA S 1294 20 */
/* Deactivate QAC warning 1294, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: There is no risk in violating this rule as the conversion is safe.*/
/* PRQA S 4404, 1298 12 */
/* Deactivate QAC warning 4404, 1298  Date: 2019-06-17; Reviewer: uidk9586;
   Reason: There is no risk in doing this conversion as the value assigned is zero. */
float32  CML_f_cos66(float32 f_Angle)
{
    const uint32 intmax_minusOne = 2147483646;
    const float32 FourOverPi = 1.2732395F;

    float32 f_AbsAngle, f_Arg, f_Res = 0, f_temp;
    float32 f_t, f_st, f_ct, f_cos;
    uint32 uQuadranti, utemp;
    boolean b_true = 1, b_false = 0, SignC, SignPoly;

    f_AbsAngle = CML_f_Abs(f_Angle);  
    f_temp = f_AbsAngle * FourOverPi;

/* PRQA S 1840 ,1841, 1843 , 4542 25 */
/* Deactivate QAC warning 1840,1841,1843, 4542 Date: 2019-06-17; Reviewer: uidk9586;
   Reason: These operations are required here as per the algorithm */
    /* This type casting is to avoid _fixfu function call in c66x */
    uQuadranti = (uint32)(sint32) f_temp; 
    /* Quadranti = bitand(Quadranti + 1, intmax - 1); */
    uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
    f_Arg = (float32)uQuadranti;

   /* SignC = ~(bitand(Quadranti - 2, 4) == 0); */
    utemp = ((uQuadranti - 2) & 4);
    SignC = (utemp == 0) ? b_false: b_true;

   /* poly  = ~(bitand(Quadranti - 2, 2) == 0); */
    utemp = ((uQuadranti - 2) & 2);
    SignPoly = (utemp == 0) ? b_false: b_true;
 
    /* 3 step Payne Hanek algorithm for range reduction*/
    f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);

    /* Sine & Cos computation from core functions */
    f_st = CML_f_Sine69Core(f_t);
    f_ct = CML_f_Cos69Core(f_t);

    /* Sine or cosine seletion and sign adjustment for quadrant */
    f_cos = SignPoly ? f_ct : f_st; 
    f_Res = SignC ? f_cos: -f_cos;

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
    float32 f_temp1, f_temp2;

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
        f_temp1        = -1.0f * C_COS_32_C3;
        f_temp2        = -1.0f * C_COS_32_C2;
        f_tmp          = CML_f_MultAdd(f_temp1, f_angle_square, f_temp2);
        f_temp1        = -1.0f * C_COS_32_C1;
        f_Ret          = CML_f_MultAdd(f_angle_square, f_tmp, f_temp1);
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
        f_temp1 = 1.0f / CML_f_two_Pi;
        f_tmp = f_angle * f_temp1;
        u_n   = (uint32) (f_tmp);

        /* Shift f_angle to [-PI..PI]. Due to symmetry of COS, it's enough to evaluate
        [0..PI]. */
        f_temp1 = (float32)u_n * CML_f_two_Pi;
        f_temp2 =  f_angle - f_temp1;
        f_angle = f_temp2 - CML_f_Pi;
        f_angle = CML_f_Abs(f_angle);

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
    float32 f_tmp1, f_tmp2, f_tmp3;
    f_tmp1 = (f_angle * C_TAN_32_C1);
    f_angle_square = CML_Sqr(f_angle);
    f_tmp2 = C_TAN_32_C2 + f_angle_square;
    f_tmp3 = f_tmp1/f_tmp2;
    return f_tmp3;
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

/* PRQA S 3339 , 3350 4 */
/* Deactivate QAC warning 3339,3350  Date: 2019-06-17; Reviewer: uid33569;
   Reason: As per the algorithm usage of constant 2 Pi can not be avoided */
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
    float32 f_tmp1, f_tmp2, f_tmp3, f_tmp4;

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


/* PRQA S 3350, 3339 5 */
/* Deactivate QAC warning 3350,3339  Date: 2019-06-17; Reviewer: uid33569;
   Reason: As per the algorithm usage of constant 2 Pi can not be avoided */
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
        /* The below code implements
        f_angle_square = (CML_f_Pi - f_angle) * (CML_f_Pi - f_angle);
        f_resultValue = -(C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
        */
        f_tmp1 = CML_f_Pi - f_angle;
        f_angle_square = f_tmp1 * f_tmp1;
        f_tmp2 = C_COS_52_C4 * f_angle_square;
        f_tmp3 = C_COS_52_C3 + f_tmp2;
        f_tmp4 = f_angle_square * f_tmp3;

        f_tmp1 = C_COS_52_C2 + f_tmp4;
        f_tmp2 = f_angle_square * f_tmp1;
        f_tmp3 = f_tmp2 + C_COS_52_C1;
        f_resultValue = -f_tmp3;	
        break;
    case 2:
        /* The below code implements
        f_angle_square = (f_angle - CML_f_Pi) * (f_angle - CML_f_Pi);
        f_resultValue = -(C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
        */
        f_tmp1 = f_angle - CML_f_Pi;
        f_angle_square = f_tmp1 * f_tmp1;
        f_tmp2 = C_COS_52_C4 * f_angle_square;
        f_tmp3 = C_COS_52_C3 + f_tmp2;
        f_tmp4 = f_angle_square * f_tmp3;

        f_tmp1 = C_COS_52_C2 + f_tmp4;
        f_tmp2 = f_angle_square * f_tmp1;
        f_tmp3 = f_tmp2 + C_COS_52_C1;
        f_resultValue = -f_tmp3;
        break;
    case 3:
        /* The below code implements
        f_angle_square = (C_TWOPI - f_angle) * (C_TWOPI - f_angle);
        f_resultValue = (C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
        */ 
        f_tmp1 = C_TWOPI - f_angle;
        f_angle_square = f_tmp1 * f_tmp1;
        f_tmp2 = C_COS_52_C4 * f_angle_square;
        f_tmp3 = C_COS_52_C3 + f_tmp2;
        f_tmp4 = f_angle_square * f_tmp3;

        f_tmp1 = C_COS_52_C2 + f_tmp4;
        f_tmp2 = f_angle_square * f_tmp1;
        f_resultValue = f_tmp2 + C_COS_52_C1;	
        break;
    default:
        /*Case 0*/
        f_angle_square = f_angle * f_angle;
        /* The below code implements
        f_resultValue = (C_COS_52_C1 + (f_angle_square * (C_COS_52_C2 + (f_angle_square * (C_COS_52_C3 + (C_COS_52_C4 * f_angle_square))))));
        */ 
        f_tmp2 = C_COS_52_C4 * f_angle_square;
        f_tmp3 = C_COS_52_C3 + f_tmp2;
        f_tmp4 = f_angle_square * f_tmp3;

        f_tmp1 = C_COS_52_C2 + f_tmp4;
        f_tmp2 = f_angle_square * f_tmp1;
        f_resultValue = f_tmp2 + C_COS_52_C1;
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
  Functionname:    CML_f_tan66                                            */ /*!

  @brief           Approximates the tangent of x with accuracy of about 6.6 
                   decimal digits

  @description     This function is tangent approximation which uses sin & cos 
                   approximation, performs range reduction on CML_f_Sine69Core & 
                   CML_f_Cos69Core. This function is a wrapper with Three-step 
                   Payne-Hanek algorithm used for range reduction. Here large input
                   arguments are reduced in the range within �pi/4 using this 
                   algorithm before calling the core sin & cosine functions. And 
                   then the answer and it's sign is appropriately chosen to get 
                   sin(x) & cos(x). Tan is calculated as sin(x)/cos(x).
                   Note: Tangent approaching infinity is tested and details 
                   added below.

  @param[in]       f_Angle : input angle for which we would like to know the 
                             tanget, in radians. 
                   Optimal range [Within �CML_f_Pi. Maximum relative
                   Error: 2.3918895e-007 from standard C library] 
                   [Note:Tested upto �1000 * CML_f_Pi. with stepsize 100.0F 
                   Maximum relative Error < 2.3918895e-007].

                   Note: 
                   1. There are no input checks made. 
                   But Tested for Pi/2 & 3 * Pi/2. 
                   Maximum relative error for CML_f_Pi/2: 8.7422784e-008
                   Exception from the above relative error: 
                   Maximum relative error for 3 * CML_f_Pi/2: 1.0493895e-006
                   2. Average cycles consumed on c66x : 142

  @param[out]      f_tan :  Tagent of f_angle

  @author          Jyothy Thomas/Lars Ulveland
*****************************************************************************/
/* PRQA S 4404 , 1294 20 */
/* Deactivate QAC warning 4404, 1294, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in doing this conversion as the value assigned is zero. */
float32 CML_f_tan66(float32 f_angle)
{
    const uint32 intmax_minusOne = 2147483646;
    const float32 FourOverPi = 1.2732395F;
    float32 f_AbsAngle, f_Arg ;
    float32 f_t, f_st, f_ct, f_sin, f_cos, f_temp, f_cosout, f_sinout, f_tan;
    sint32 Signx = 0;
    uint32 utemp, uQuadranti;
    boolean b_true = 1, b_false = 0, SignS, SignC, SignPoly;

/* PRQA S 1802 5 */
/* Deactivate QAC warning 1802, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in this as this conversion */
    Signx = (f_angle < 0) ? -1 : 1; 
    f_AbsAngle = CML_f_Abs(f_angle);  
    f_temp = f_AbsAngle * FourOverPi;

/* PRQA S 1840, 1841, 1843, 4542, 1881 30 */
/* Deactivate QAC warning 1840,1841,1843, 4542, 1881, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule */
    /* This type casting is to avoid _fixfu function call in c66x */
    uQuadranti = (uint32)(sint32) f_temp; 
    uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
    f_Arg = (float32)uQuadranti;

    /* SignS = bitand(Quadranti, 4) == 0; */
    utemp = (uQuadranti & 4);
    SignS = (utemp == 0) ? b_true : b_false;

   /* SignC = ~(bitand(Quadranti - 2, 4) == 0); */
    utemp = ((uQuadranti - 2) & 4);
    SignC = (utemp == 0) ? b_false: b_true;

/* PRQA S 4404 10 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule */
   /* SignPoly  = ~(bitand(Quadranti - 2, 2) == 0); */
    utemp = ((uQuadranti - 2) & 2);
    SignPoly = (utemp == 0) ? b_false : b_true ;

    /* 3 step Payne Hanek algorithm for range reduction */
    f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);

    /* Sine & Cos computation from core functions */
    f_st = CML_f_Sine69Core(f_t);
    f_ct = CML_f_Cos69Core(f_t);  

    /* Sine or cosine seletion and sign adjustment for quadrant */
    f_sin = SignPoly ? f_st : f_ct;   
    f_sin = SignS ? f_sin: -f_sin;
    f_cos = SignPoly ? f_ct : f_st; 

    f_cosout = SignC ? f_cos: -f_cos;

    /* sin(-x) - -sin(x) */
    f_sinout  = f_sin * (float32) Signx; 

#ifdef CML_GOLDDUST
    f_tan = f_sinout / f_cosout;
#else
    f_temp = CML_f_fastInv69 (f_cosout);
    f_tan = f_sinout * f_temp;
#endif
    return f_tan;
}

/*****************************************************************************
  Functionname:    CML_f_atan67                                           */ /*!

  @brief           computes atan(x) with at least 6.6 decimal digits accuracy
                   Maximum error is 2.05e-7. Average is 3e-8.

  @description     The series atan(x) = x(1 + (c0 + (c1 + (c2 + (c3*x^2))x^2)x^2)x^2)x^2)
                   is used. For abs(x) > (sqrt(2) - 1),
                   atan((x-1)/(x+1)) = atan(x) - pi/4 is used,
                   and for abs(x) > (sqrt(2) + 1), atan((x+1)/(x-1)) = Pi/2 - atan(x) is used.

  @param[in]       f_Arg : Argument to inverser Tangens.
                   Optimal values are [-MAX_ANGLE,..,MAX_ANGLE], 
                   where MAX_ANGLE is square root of max value of float32

  @return          arctangent of f_Arg

  @author          Jeevan Kotre/Lars Ulveland
*****************************************************************************/
float32 CML_f_atan67(float32 f_Arg)
{
  /* Coefficients tested in Matlab function Atan5.m */
  const float32 f_Coeff_c0 = -3.33329491539E-1F;
  const float32 f_Coeff_c1 = 1.99777106478E-1F;
  const float32 f_Coeff_c2 = -1.38776856032E-1F;
  const float32 f_Coeff_c3 = 8.05374449538E-2F;

  /* Final shift by Pi/4 requires increased precision */
  const float32 f_QuarterPiUpperMantissa = 0.78515625F;
  const float32 f_QuarterPiLowerMantissa = 2.41913397E-4F;
  /* For comparison only */
  const float32 f_Sqrtof2Minus1 = 0.41421356F;
  const float32 f_Sqrtof2Plus1  = 2.41421356F;

  uint8 b_LargeArg, b_VeryLargeArg;

  float32 f_x2;
  float32 f_T;
  float32 f_TransformedArg;
  float32 f_Den, f_Nom;
  float32 f_AbsArg = CML_f_Abs(f_Arg);

/* PRQA S 1802 10 */
/* Deactivate QAC warning 1802, Date: 2019-06-17; Reviewer: uid33569;
   Reason: This is just to determine the sign and there is no risk here */
  float32 f_Sign = (f_Arg > 0) ? 1.0F : -1.0F;
  
  /* If argument is large, transform it, otherwise use it. */
  b_LargeArg     = (uint8) (f_AbsArg > f_Sqrtof2Minus1);
  b_VeryLargeArg = (uint8) (f_AbsArg > f_Sqrtof2Plus1);
  

/* PRQA S 4559 20 */
/* Deactivate QAC warning 4559, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule */
  /*  Select (x-1)/(x+1) or (x+1)/(x-1) */
  f_Den = (b_VeryLargeArg) ? (f_AbsArg) : (f_AbsArg + 1.0F);
  f_Nom = (b_VeryLargeArg) ? (  - 1.0F) : (f_AbsArg - 1.0F);
    
#ifdef CML_GOLDDUST //#if (defined(CPU_MPC5675K_EMU) || defined(CPU_MPC5775N_EMU))
  f_TransformedArg = f_Nom / f_Den;
#else
  f_TransformedArg = f_Nom * CML_f_fastInv69(f_Den);
#endif

  f_TransformedArg = (b_LargeArg) ? f_TransformedArg : f_AbsArg;
  f_x2 = f_TransformedArg * f_TransformedArg;

  f_T = f_Coeff_c3 * f_x2;
  f_T += f_Coeff_c2;
  f_T *= f_x2;
  f_T += f_Coeff_c1;
  f_T *= f_x2;
  f_T += f_Coeff_c0;
  f_T *= f_x2;
  f_T *= f_TransformedArg;
  f_T += f_TransformedArg;

/* PRQA S 1881 15 */
/* Deactivate QAC warning 1881, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule */
  /* Theoretically, this branch should be executable as a conditional, otherwise it can be rewritten. */
  if(b_VeryLargeArg == b_TRUE)
  {
    /* In this range, the values are of comparable magnitude, plain subtraction suffices.*/
    f_T = CML_f_Half_Pi + f_T;
  }
  else if(b_LargeArg == b_TRUE)
  {
  /*  Conditional shift by Pi/4 using the two-stage method to increase accuracy. 
      Reduces the maximum error by ca 20%. */
    f_T += f_QuarterPiUpperMantissa;
    f_T += f_QuarterPiLowerMantissa;
  }
  else
  {  
     /* Empty MISRA-clause, small arguments require not additional transform */
  }
  
  return f_Sign * f_T;  /* Replace the sign. */
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
    float32 f_tmp1, f_tmp3, f_cos_square, f_tmp4;
#ifdef CML_OPT_c66x
    float32 f_tmp2;
#endif
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
        f_cos_square = CML_Sqr(f_cos);
        f_tmp1 = 1.0F - f_cos_square;
#ifdef CML_OPT_c66x
        /* CML_f_invSqrt67 is an optimized function for inverse square root 
        which uses _rsqrsp intrinsic with additonal code to improve accuracy */
        f_tmp2 = CML_f_invSqrt67(f_tmp1); 
        f_tmp3 = f_cos * f_tmp2;
#else
        f_tmp3 = f_cos/CML_f_Sqrt(f_tmp1);	
#endif
        f_tmp4 = CML_f_atan66(f_tmp3);
        f_angle = C_HALFPI - f_tmp4;
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
    float32 f_tmp1, f_tmp2, f_tmp4;
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
        f_tmp1 = CML_Sqr(f_sin);
        f_tmp2 = 1.0F - f_tmp1;
#ifdef CML_OPT_c66x
        /* CML_f_invSqrt67 is an optimized function for inverse square root 
        which uses _rsqrsp intrinsic with additonal code to improve accuracy */
        f_tmp1 = CML_f_invSqrt67(f_tmp2);
        f_tmp4 = f_sin * f_tmp1;
#else
        f_tmp4 = f_sin / CML_f_Sqrt(f_tmp2);
#endif
        f_angle = CML_f_atan66(f_tmp4);
    }
    return f_angle;
}


/*****************************************************************************
  Functionname:    CML_f_atan2                                          */ /*!

  @brief           computes the four-quadrant atan(y/x) with 
                   about 6.6 decimal digits accuracy
                   Maximum error is 2.3826523e-007.

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
    /* Perform fast inverse calculation*/
    float32 f_temp = 0.0f;
#ifdef CML_GOLDDUST 
    f_temp = f_yaxis / f_xaxis;
#else
    f_temp = f_yaxis * CML_f_fastInv69(f_xaxis);
#endif
    /* compute arctangent */
    f_angle = CML_f_atan67(f_temp);
  }

  else
  {
    if(f_xaxis < CML_f_AlmostNegZero)
    {
      /* Perform fast inverse calculation*/
      float32 f_temp = 0.0f;
#ifdef CML_GOLDDUST 
      f_temp = -f_yaxis / f_xaxis;
#else
      f_temp = -f_yaxis * CML_f_fastInv69(f_xaxis);
#endif
      /* compute arctangent */
      f_angle = CML_f_atan67(f_temp);

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
        f_angle = -(CML_f_Half_Pi);
      }

      else if(f_yaxis > CML_f_AlmostZero)
      {
        f_angle = CML_f_Half_Pi;
      }

      else
      {
        f_angle = 0.0F;
      }
    }
  }

  return f_angle;
}


/*****************************************************************************
  Functionname:    CML_f_sincos                                         */ /*!

  @brief           Calculates the sine & cosine of an input value,and performs 
                   range reduction with 6.9 decimals relative accuracy.

  @description     This function computes the approximation for both sine
                   and cosine for the given value and populates to the memory
                   provided by the pointers passed. This function is a wrapper 
                   which performs range reduction on CML_f_Sine69Core & 
                   CML_f_Cos69Core. Three-step Payne-Hanek algorithm is used 
                   here for range reduction. Here large input arguments are 
                   reduced in the range within �pi/4 using this algorithm 
                   before calling the core sin & cosine functions.And then the
                   answer and it's sign is appropriately chosen to get sin(x) 
                   & cos(x)

  @param[in]       f_Angle : input angle for which we would like to know the 
                             sine & cosine, in radians. 
                   Optimal range [ Within �CML_f_two_Pi. Maximum relative
                   Error: 1.19e-7] 
                   [Note:Tested upto �1000 * CML_f_Pi. with stepsize 0.1F 
                   Maximum relative Error: 1.192e-7].

  @param[out]      p_sin :  sine of f_val
                            Valid float pointer
  @param[out]      p_cos :  cosine of f_val
                            Valid float pointer

  @return          void

  @author          Lars Ulveland, ADC GmbH - Lindau, Jyothy Thomas
**************************************************************************** */
void CML_f_sincos(float32 f_Angle, float32 *p_sin, float32 *p_cos)
{
    const uint32 intmax_minusOne = 2147483646;
    const float32 FourOverPi = 1.2732395F;
    float32 f_AbsAngle, f_Arg ;
    float32 f_t, f_st, f_ct, f_sin,f_cos, f_temp;
    sint32 Signx = 0;
    uint32 utemp, uQuadranti;

/* PRQA S 1294 , 1802 10 */
/* Deactivate QAC warning 1294, Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule */
    boolean b_true = 1, b_false = 0, SignS, SignC, SignPoly;

    Signx = (f_Angle < 0) ? -1 : 1; 
    f_AbsAngle = CML_f_Abs(f_Angle);  
    f_temp = f_AbsAngle * FourOverPi;

    /* This type casting is to avoid _fixfu function call in c66x */
/* PRQA S 1840 ,1841, 1843, 4542 40 */
/* Deactivate QAC warning 1840,1841, 1843,4542 Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule */
    uQuadranti = (uint32)(sint32) f_temp; 
    uQuadranti = (uQuadranti + 1 ) & intmax_minusOne; 
    f_Arg = (float32)uQuadranti;

    /* SignS = bitand(Quadranti, 4) == 0; */
    utemp = (uQuadranti & 4);
    SignS = (utemp == 0) ? b_true : b_false;

   /* SignC = ~(bitand(Quadranti - 2, 4) == 0); */
    utemp = ((uQuadranti - 2) & 4);
    SignC = (utemp == 0) ? b_false: b_true;

   /* SignPoly  = ~(bitand(Quadranti - 2, 2) == 0); */
    utemp = ((uQuadranti - 2) & 2);
    SignPoly = (utemp == 0) ? b_false : b_true ;

    /* 3 step Payne Hanek algorithm for range reduction */
    f_t = CML_f_ThreeStepSubPiQuarter(f_Arg, f_AbsAngle);

    /* Sine & Cos computation from core functions */
    f_st = CML_f_Sine69Core(f_t);
    f_ct = CML_f_Cos69Core(f_t);  

    /* Sine or cosine seletion and sign adjustment for quadrant */
    f_sin = SignPoly ? f_st : f_ct;   
    f_sin = SignS ? f_sin: -f_sin;
    f_cos = SignPoly ? f_ct : f_st; 
    *p_cos = SignC ? f_cos: -f_cos;

    /* sin(-x) - -sin(x) */
    *p_sin  = f_sin * (float32) Signx; 
}
