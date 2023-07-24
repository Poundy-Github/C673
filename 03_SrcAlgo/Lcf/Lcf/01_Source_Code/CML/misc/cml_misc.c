/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_misc.c

  DESCRIPTION:               Provide miscellaneous basic mathematical operations

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.62.1.3 $

  ---*/ /*---
  CHANGES:                   $Log: cml_misc.c  $
  CHANGES:                   Revision 1.62.1.3 2020/01/08 11:32:37CET Thomas, Jyothy (uid22555) 
  CHANGES:                   corrected alignment
  CHANGES:                   Revision 1.62.1.2 2019/11/22 07:41:18CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Checkin the changes in misc functions for ECU-SIL bit exactness on A15
  CHANGES:                   Revision 1.62.1.1 2019/06/24 10:39:48CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   QAF level 3 warnings have been fixed.
  CHANGES:                   Revision 1.62 2018/07/27 12:10:07CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_b_isNAN() has been implemented.
  CHANGES:                   Revision 1.61 2018/06/19 10:42:50CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Removed CML_f_sqrtApprox
  CHANGES:                   Revision 1.60 2018/03/08 06:33:10CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Log and power functions are moved to cml_exp.c
  CHANGES:                   Revision 1.59 2018/02/26 08:51:53CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.58 2017/11/14 18:41:45CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.57 2017/11/09 11:36:20CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Replaced FALSE/TRUE by b_FALSE/b_TRUE
  CHANGES:                   Revision 1.56 2017/08/04 06:03:24CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Aligned and merged changes from AL_CML_01.09.11_INT-1.
  CHANGES:                   Revision 1.55 2016/12/06 11:09:17CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Code cleanup
  CHANGES:                   Revision 1.54 2016/11/18 06:49:28CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Intrinsic optimization
  CHANGES:                   Revision 1.53 2016/11/02 04:37:10CET Jagannath-EXT, Anu (uid42056) 
  CHANGES:                   Added code for bitmatching MSVC and C66x output
  CHANGES:                   Revision 1.52 2016/05/25 12:46:37CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Added inverse square roots with different accuracy, and a division-free square root.
  CHANGES:                   Revision 1.51 2016/05/20 10:54:29CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.50 2016/02/15 14:09:27CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Fix the last platform dependent warning.
  CHANGES:                   Revision 1.49 2016/02/10 09:03:03CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Fixed a sign bug.
  CHANGES:                   Profiled for C6X and confirmed pipelining. Speed up 4.5x for test set of small polygons.
  CHANGES:                   Revision 1.48 2016/02/05 14:11:50CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Removed unused variable.
  CHANGES:                   Revision 1.47 2016/02/05 11:05:15CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Reformulated the core comparison by extending the fraction by (x2-x1)(y2-y1), eliminating the floating point division.
  CHANGES:                   In addition, also removed the second loop variable.
  CHANGES:                   Revision 1.46 2016/02/05 10:50:28CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Replaced the implementation of 
  CHANGES:                   sint32 CML_s_CountNrOfBitsSet (uint32 u_PruefBits)
  CHANGES:                   with a faster one without a data-dependent loop.
  CHANGES:                   
  CHANGES:                   Profiled on C674X: 7 cycles vs. 78 for the old implementation, provided that the scoping allows inlining.
  CHANGES:                   
  CHANGES:                   New implementation can also be pipelines with other instructions when properly inlined.
  CHANGES:                   
  CHANGES:                   Expected runtime on a z7-class CPU: ca 10 cycles.
  CHANGES:                   
  CHANGES:                   Complete bitexactnesstest carried out, testing all possible 32-bit inputs.
  CHANGES:                   Revision 1.45 2015/10/12 05:40:08CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for doxygen warning
  CHANGES:                   - Added comments -  uidr5428 [Oct 12, 2015 5:40:09 AM CEST]
  CHANGES:                   Change Package : 383331:1 http://mks-psad:7002/im/viewissue?selection=383331
  CHANGES:                   Revision 1.44 2015/08/25 06:43:28CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 6:43:29 AM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.43 2015/06/30 13:33:26CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Merge from Branch 1.41.1.1
  CHANGES:                     ( Added new line at the end of file )
  CHANGES:                   --- Added comments ---  uidr5428 [Jun 30, 2015 1:33:27 PM CEST]
  CHANGES:                   Change Package : 316985:1 http://mks-psad:7002/im/viewissue?selection=316985
  CHANGES:                   Revision 1.42 2015/06/02 15:50:15CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - implemented higher accuracy log() functions
  CHANGES:                   --- Added comments ---  uidg6516 [Jun 2, 2015 3:50:15 PM CEST]
  CHANGES:                   Change Package : 324616:1 http://mks-psad:7002/im/viewissue?selection=324616
  CHANGES:                   Revision 1.41 2015/05/27 06:57:08CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed the unused if condition in the function CML_f_SqrtApprox
  CHANGES:                   --- Added comments ---  uidr5428 [May 27, 2015 6:57:09 AM CEST]
  CHANGES:                   Change Package : 317005:1 http://mks-psad:7002/im/viewissue?selection=317005
  CHANGES:                   Revision 1.40 2015/04/29 15:29:18CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 3:29:19 PM CEST]
  CHANGES:                   Change Package : 324617:2 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.39 2015/04/23 14:35:59CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Removed an if condition in function CML_v_CalculateCOFEgomotionMatrices
  CHANGES:                     The condition was found unnecessary. Retained the if part.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 23, 2015 2:36:00 PM CEST]
  CHANGES:                   Change Package : 317007:1 http://mks-psad:7002/im/viewissue?selection=317007
  CHANGES:                   Revision 1.38 2015/04/21 15:44:26CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Edited the function docu header of the function CML_f_ComputeClothoidLateralDistance
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 21, 2015 3:44:27 PM CEST]
  CHANGES:                   Change Package : 316975:1 http://mks-psad:7002/im/viewissue?selection=316975
  CHANGES:                   Revision 1.37 2015/04/21 13:25:58CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Edited function docu header of the function CML_f_ModTrig
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 21, 2015 1:26:01 PM CEST]
  CHANGES:                   Change Package : 316976:1 http://mks-psad:7002/im/viewissue?selection=316976
  CHANGES:                   Revision 1.36 2015/04/21 11:28:07CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Edited function docu header for function CML_s_GetLutIndexBackwards
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 21, 2015 11:28:07 AM CEST]
  CHANGES:                   Change Package : 312188:1 http://mks-psad:7002/im/viewissue?selection=312188
  CHANGES:                   Revision 1.35 2014/12/12 13:34:32CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added review ID to QA-C suppressions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 12, 2014 1:34:32 PM CET]
  CHANGES:                   Change Package : 266613:12 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.34 2014/12/10 10:38:19CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - extracted interpolation functions to seperate module to meet QA-C LOC metric requirements
  CHANGES:                   - fixed previously suppressed critical QA-C issue in CML_v_CalcCOFEgomotionMatrices()
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 10, 2014 10:38:19 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.33 2014/12/05 09:21:51CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed parameters of several functions from pointer to array where they are accessed like this
  CHANGES:                   - code maintenance to meet QA-C requirements
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 5, 2014 9:21:52 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.32 2014/10/22 11:34:29CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   declaration of static funcion in correct file
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 22, 2014 11:34:29 AM CEST]
  CHANGES:                   Change Package : 266613:7 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.31 2014/10/22 11:05:09CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   QA-C, function scope to static, rename function, move parameters to correct header
  CHANGES:                   Revision 1.30 2014/10/09 17:31:09CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   Check for divison by zero with macro
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 9, 2014 5:31:10 PM CEST]
  CHANGES:                   Change Package : 265242:3 http://mks-psad:7002/im/viewissue?selection=265242
  CHANGES:                   Revision 1.29 2014/10/01 14:46:22CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   add distance point 2 circle and distance point 2 clothoid computation from FCT to CML
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 1, 2014 2:46:22 PM CEST]
  CHANGES:                   Change Package : 265242:1 http://mks-psad:7002/im/viewissue?selection=265242
  CHANGES:                   Revision 1.28 2014/09/26 13:44:38CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - corrected handling of equal inputs in CML_f_Mod()
  CHANGES:                   --- Added comments ---  uidg6516 [Sep 26, 2014 1:44:39 PM CEST]
  CHANGES:                   Change Package : 266613:2 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.27 2014/08/20 11:31:31CEST Dintzer, Philippe (dintzerp) 
  CHANGES:                   - ecu-sil fixes for combined operators
  CHANGES:                   - use of CML_f_MultAdd( )
  CHANGES:                   --- Added comments ---  dintzerp [Aug 20, 2014 11:31:32 AM CEST]
  CHANGES:                   Change Package : 257759:1 http://mks-psad:7002/im/viewissue?selection=257759
  CHANGES:                   Revision 1.26 2014/08/13 14:43:05CEST Stolle, Ulf Eike (uidv1902) 
  CHANGES:                   Bugfix for Length of Array in CML_s_GetLutIndex
  CHANGES:                   QA C
  CHANGES:                   --- Added comments ---  uidv1902 [Aug 13, 2014 2:43:05 PM CEST]
  CHANGES:                   Change Package : 250334:2 http://mks-psad:7002/im/viewissue?selection=250334
  CHANGES:                   Revision 1.25 2014/07/09 11:20:11CEST Kronauge, Matthias (uidg8751) 
  CHANGES:                   Add function CML_f_XPowY calculating X to the power of Y
  CHANGES:                   --- Added comments ---  uidg8751 [Jul 9, 2014 11:20:12 AM CEST]
  CHANGES:                   Change Package : 243179:3 http://mks-psad:7002/im/viewissue?selection=243179
  CHANGES:                   Revision 1.24 2014/03/27 11:22:53CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:22:53 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.23 2014/03/25 11:33:45CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:33:45 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.22 2014/03/12 10:29:12CET Brendel, Matthias (uidv8244) 
  CHANGES:                   fastlog (natural logarithm)
  CHANGES:                   --- Added comments ---  uidv8244 [Mar 12, 2014 10:29:13 AM CET]
  CHANGES:                   Change Package : 223474:1 http://mks-psad:7002/im/viewissue?selection=223474
  CHANGES:                   Revision 1.21 2014/02/04 15:12:57CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:12:58 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.20 2014/01/31 12:25:04CET Stolle, Ulf Eike (uidv1902) 
  CHANGES:                   Add CML function for Power of Two
  CHANGES:                   --- Added comments ---  uidv1902 [Jan 31, 2014 12:25:04 PM CET]
  CHANGES:                   Change Package : 212119:2 http://mks-psad:7002/im/viewissue?selection=212119
  CHANGES:                   Revision 1.19 2014/01/27 13:57:44CET Dintzer, Philippe (dintzerp) 
  CHANGES:                   - direct use of cml function instead of macro
  CHANGES:                   --- Added comments ---  dintzerp [Jan 27, 2014 1:57:44 PM CET]
  CHANGES:                   Change Package : 189257:2 http://mks-psad:7002/im/viewissue?selection=189257
  CHANGES:                   Revision 1.18 2014/01/27 13:54:31CET Dintzer, Philippe (dintzerp) 
  CHANGES:                   - Runtime optimization of linear function
  CHANGES:                   Revision 1.17 2013/12/10 18:24:55CET Boll, Marie-Theres (uidu1091) 
  CHANGES:                   Carry over latest navi-developments into ARS400 path (shapepoint interpretation)
  CHANGES:                   --- Added comments ---  uidu1091 [Dec 10, 2013 6:24:56 PM CET]
  CHANGES:                   Change Package : 207953:1 http://mks-psad:7002/im/viewissue?selection=207953
  CHANGES:                   Revision 1.16 2013/10/30 14:52:41CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add function to check if a point lies inside a polygon
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 30, 2013 2:52:42 PM CET]
  CHANGES:                   Change Package : 159154:33 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.15 2013/05/13 17:38:21CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - clean up float and int macros
  CHANGES:                   --- Added comments ---  uidu0849 [May 13, 2013 5:38:21 PM CEST]
  CHANGES:                   Change Package : 159154:30 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.14 2013/05/06 16:46:33CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add treatment of special cases in CML_f_SqrtApprox
  CHANGES:                   --- Added comments ---  uidu0849 [May 6, 2013 4:46:33 PM CEST]
  CHANGES:                   Change Package : 159154:29 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.13 2013/05/06 14:46:54CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - reduce Lint/Misra warnings
  CHANGES:                   --- Added comments ---  uidu0849 [May 6, 2013 2:46:54 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.12 2013/05/03 09:57:20CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:20 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.11 2013/04/23 10:43:10CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - use assertions in the sqrt approximation
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 23, 2013 10:43:10 AM CEST]
  CHANGES:                   Change Package : 159154:26 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.10 2013/04/09 12:56:36CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Move the sqrt approximation from cml_trigo.c to cml_misc.c
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:56:36 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/02/28 13:23:11CET Diewald, Fabian (uidt8878) 
  CHANGES:                   added methods to get LUT index
  CHANGES:                   --- Added comments ---  uidt8878 [Feb 28, 2013 1:23:12 PM CET]
  CHANGES:                   Change Package : 176321:1 http://mks-psad:7002/im/viewissue?selection=176321
  CHANGES:                   Revision 1.8 2013/02/12 14:11:42CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - remove compiler warnings
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 12, 2013 2:11:42 PM CET]
  CHANGES:                   Change Package : 159154:14 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2012/11/26 17:23:11CET Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                   - sprint fixes.
  CHANGES:                   --- Added comments ---  uidu2446 [Nov 26, 2012 5:23:11 PM CET]
  CHANGES:                   Change Package : 102370:63 http://mks-psad:7002/im/viewissue?selection=102370
  CHANGES:                   Revision 1.6 2012/10/17 15:31:14CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - rework to get rid of Misra / Lint and compiler warnings
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 17, 2012 3:31:14 PM CEST]
  CHANGES:                   Change Package : 159154:8 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2012/10/12 13:58:19CEST Oprisan, Dan (oprisand) 
  CHANGES:                   - Add MOD, REM, CEI, FLOOR functions to CML
  CHANGES:                   - remove obsolete FMOD_ macro from cml_mapping.h
  CHANGES:                   --- Added comments ---  oprisand [Oct 12, 2012 1:58:20 PM CEST]
  CHANGES:                   Change Package : 139701:13 http://mks-psad:7002/im/viewissue?selection=139701
  CHANGES:                   Revision 1.4 2012/09/25 13:42:32CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - include function fastlog10 and CalculatePolygonValue
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 25, 2012 1:42:32 PM CEST]
  CHANGES:                   Change Package : 159154:6 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2012/09/20 13:29:45CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:45 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:19:55CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - remove German special characters in comments and review tags
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:19:55 PM CEST]
  CHANGES:                   Change Package : 159154:2 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:16CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uidk9586;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
 (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*! Parameters for CML_CalculateDistancePoint2Circle */
/* minimum curvature for which use circle equation instead of parabolic approximation */
#define CURVATURE_USE_CIRCLE_EQUATION   (1.F/1000.F)  /* in 1/m */
/* minimum curvature for which use circle equation instead of parabolic approximation */
#define RADIUS_INIT_VALUE               (999999.F)    /* in m */
#define BIT_MASK_1    0x55555555
#define BIT_MASK_2    0x33333333
#define NIBBLE_MASK   0x0F0F0F0FU
/*is used to achieve a modulo-256, carry-less Accumulation, in which the uppermost byte 
  of the result is our actual number of set bits.*/
#define ACCM_MASK     0x01010101U

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_f_mod                                            */ /*!

  @brief           Calculates modulus after division (similar to MATLAB)
                   
  @description     This function calculates modulus after division:
                   result = X - n*Y where n = floor(X/Y)
                   returns same values as CML_Rem if X and Y have same signs.
                   Divident & Divisor should be such that f_quotient should not 
                   exceed the range of sint32
                   
  @param[in]       f_value  : Divident under the range of float32. 

  @param[in]       f_modulo : Divisor under the range of float32.

  @return          f_value modulo f_modulo
                   
  @author          dan.oprisan@continental-corporation.com
*****************************************************************************/
float32 CML_f_mod(float32 f_value, float32 f_modulo)
{
    float32 f_quotient, f_ret;
    float32 f_temp1, f_temp2; 
    /* avoid Div0 if y~0 and return 0 (MATLAB returns x) */
    if(CML_f_IsZero(f_modulo))
    {
        f_ret = 0.0f;
    }
    else
    {
        f_quotient = f_value / f_modulo;
        /* If quotient is out of range or whole number return 0. */
        /* Added "=" in the condition to handle overflow for a special case when f_quotient = (float32)C_LONG_MAX */

        /* CML_Round(f_quotient) = return (f_quotient >= 0.f) ? (float32)(sint32)(x + 0.5f) : (float32)(sint32)(x - 0.5f);
        Code modified to maintain consistency between MSVC & C66x */
        if (f_quotient >= 0.f)
        {
            f_temp1 = (f_quotient + 0.5f);
        }
        else
        {
            f_temp1 = (f_quotient - 0.5f);
        }
        f_temp2 = (float32)(sint32)f_temp1; 
        if((CML_f_Abs(f_quotient) >= (float32)C_LONG_MAX) ||
            CML_f_IsZero(f_temp2 - f_quotient))
        {
            f_ret = 0.f;
        }

        else 
        {
            /* The below lines implement "f_ret = (f_value - (CML_f_Floor(f_quotient) * f_modulo));"
            Code modified to maintain consistency between MSVC & C66x */ 
            f_temp1 = CML_f_Floor(f_quotient);
            f_temp2 = f_temp1 * f_modulo;
            f_ret = f_value - f_temp2;
        }
    }

    return f_ret;
}

/*****************************************************************************
  Functionname:    CML_f_rem                                            */ /*!

  @brief           Calculates the remainder after division (similar to MATLAB)
                  
  @description     This function calculates remainder after division: 
                   result = X - n*Y where n = fix(X/Y)
                   returns same values as CML_Mod if X and Y have same signs.
                   Divident & Divisor should be such that f_quotient should not 
                   exceed the range of sint32
  @param[in]       f_dividend : Divident under the range of float32. 

  @param[in]       f_divisor  : Divisor under the range of float32.

  @return          remainder of f_dividend / f_divisor
                  
  @author          dan.oprisan@continental-corporation.com
*****************************************************************************/
float32 CML_f_rem(float32 f_dividend, float32 f_divisor)
{
    float32 f_quotient, f_ret;
    float32 f_temp1, f_temp2 ; 

    if ( (f_divisor < CML_f_ModuloEps) && (f_divisor > -CML_f_ModuloEps) )
    {
        /* avoid Div0 if y~0 and return 0 (MATLAB returns x) */
        f_ret = 0.0f;
    }
    else
    {
        f_quotient = f_dividend / f_divisor;

        if (CML_f_Abs(f_quotient) > (float32)C_LONG_MAX)
        {
            f_ret = 0.f;
        }
        else 
        {
            /* The below lines implement " f_ret = (f_dividend - ((float32)(sint32)(f_quotient) * f_divisor)); "
            The code is modified to maintain consistency between MSVC & C66x */ 
            f_temp1 = (float32)(sint32)(f_quotient);
            f_temp2 = f_temp1 * f_divisor;
            f_ret = f_dividend - f_temp2;
        }
    }

    return f_ret;
}

/*****************************************************************************
  Functionname     - CML_f_hypot
  @brief           - Computes the length of a vector without risking over-
                     or under-flow.

  @description     - This function Computes the length of a vector without risking over-
                     or under-flow.

  @param[in]       - f_x: A normalized real number.
                   - f_y: A normalized real number.

  @return          - The length of the vector (f_x, f_y)
  @author          - Lars Ulveland
*****************************************************************************/
float32 CML_f_hypot(float32 f_x, float32 f_y)
{
    float32 f_t;
    float32 f_temp;
    f_x = CML_f_Abs(f_x);
    f_y = CML_f_Abs(f_y);
    f_t = CML_Min(f_x, f_y);
    f_x = CML_Max(f_x, f_y);
    f_t = f_t / f_x;  /* Should be replaced with the corresponding fast division for each platform */
    f_t = f_t * f_t;
    f_t += 1.0F;
    f_t = CML_Sqrt67(f_t);
    f_temp = f_x * f_t;
    return f_temp;
}

/*****************************************************************************
Functionname:    CML_s_countNrOfBitsSet                               */ /*!

@brief           Count the number of bits set in a 32 bit unsigned int

@description     This function counts and returns the number of bits set
                 in a 32 bit unsigned integer
                 Executes in constant runtime, 7 cycles amortized time on C6X

@param[in]       u_PruefBits : 32-bit unsigned integer
                               Supported values [Full range of uint32]

@return          the number of bits set

@author          L. Ulveland

*****************************************************************************/
/* PRQA S 4542 14 */
/* PRQA S 4394 14 */
/* PRQA S 1841 12 */
/* Deactivate QAC warning 4542,4394 ,1841, Date: 2019-06-11; Reviewer: uidk9586;  
   Reason: There is no risk here as all are positive numbers in these operations. */
sint32 CML_s_countNrOfBitsSet(uint32 u_PruefBits)
{
    sint32 s_AnzahlEinsBit = 0;

    u_PruefBits = u_PruefBits - ((u_PruefBits >> 1) & BIT_MASK_1);
    u_PruefBits = (u_PruefBits & BIT_MASK_2) + ((u_PruefBits >> 2) & BIT_MASK_2);
    s_AnzahlEinsBit = (sint32)((((u_PruefBits + (u_PruefBits >> 4)) & NIBBLE_MASK) * ACCM_MASK) >> 24);

    return s_AnzahlEinsBit;
}

/*****************************************************************************

  Functionname:    CML_s_getLutIndex                                    */ /*!

  @brief           Returns the index for a lookup table value; the input
                   value is in the domain of f_LutMinInputValue and f_LutRes

  @description     The function finds and returns the index for a given look up 
                   table value. The result will be bounded between the maximum 
                   and minimum look-up table indices permitted.
                   Let  IDX = Look-up Table index 
                        INP = Input value for which index has to be found
                        MIP = Minimum Input Value in the look-up table
                        RES = Resolution of the look-up table
                   then,
                        IDX = MIP + ROUND((INP-MIP)/RES)

  @param[in]       f_InputValue :       Input value for the Lookup Table
                                        Supported range [Full range of float32]
  @param[in]       f_LutMinInputValue : Minimal input value of the Lookup table
                                        Supported range [Full range of float32]
  @param[in]       f_LutRes :           resolution of the Lookup table
                                        Supported range [Full range of float32]
  @param[in]       s_LutMinInd :        first index of the lookup table
                                        Supported range [Full range of sint32]
  @param[in]       s_LutMaxInd :        last index of the lookup table
                                        Supported range [Full range of sint32]
                                        Note: The result may vary from expected for 
                                        very high input values due to type conversion
                                        from float to signed int.

  @return          index of the lookup table

  @pre             -
  @post            -

  @author          Philippe Dintzer, Fabian Diewald

**************************************************************************** */
sint32 CML_s_getLutIndex(const float32 f_InputValue, const float32 f_LutMinInputValue, const float32 f_LutRes, const sint32 s_LutMinInd, const sint32 s_LutMaxInd)
{
    /* LUT index */
    sint32 s_Ind = s_LutMinInd;
    if (CML_f_IsNonZero(f_LutRes))
    {
        const float32 f_temp1 = f_InputValue - f_LutMinInputValue;
        const float32 f_temp2 = f_temp1 / f_LutRes ;
        const float32 f_Ind = f_temp2 + 0.5f ;

        /* Add Index Offset */
        s_Ind = ((sint32)f_Ind) + s_LutMinInd;
    }

    /* check if s_Ind is in the valid range */
    s_Ind = CML_MinMax(s_LutMinInd, s_LutMaxInd, s_Ind);

    return s_Ind;
}

/*****************************************************************************

  Functionname:    CML_s_getLutIndexBackwards                           */ /*!

  @brief           Returns the index for a lookup table value; the input
                   value is in the domain of a LUT.

  @description     The function finds and returns the look-up table index for a 
                   given value. The result will be bounded between the maximum 
                   and minimum look-up table indices permitted.
                   The index of the look-up table value, which is more closer to
                   the given value, will be returned.

  @param[in]       f_InputValue : Input value for the Lookup Table
                                  Supported range [Full range of float32]
  @param[in]       a_LUT :        Lookup table
                                  Supported range for values in a_LUT[] 
                                  [Full range of float32]
  @param[in]       s_LutMinInd :  first index of the lookup table.
                                  Supported range [Full positive range of sint32]
  @param[in]       s_LutMaxInd :  last index of the lookup table.
                                  Supported range [Full positive range of sint32]

  @return          index of the lookup table

  @pre             -
  @post            -

  @author          Fabian Diewald

**************************************************************************** */
sint32 CML_s_getLutIndexBackwards(const float32 f_InputValue, const float32 a_LUT[], const sint32 s_LutMinInd, const sint32 s_LutMaxInd)
{
  sint32 s_Result = s_LutMinInd,
        s_Ind;
  float32 f_tmp;

  if (f_InputValue <= a_LUT[s_LutMinInd])
  {
      s_Result = s_LutMinInd;
  }
  else if (f_InputValue >= a_LUT[s_LutMaxInd])
  {
      s_Result = s_LutMaxInd;
  }
  else
  {
      for (s_Ind = s_LutMinInd; s_Ind < s_LutMaxInd; s_Ind++)
      {
          if ((f_InputValue >= a_LUT[s_Ind]) && (f_InputValue <= a_LUT[s_Ind+1]))
          {
              f_tmp = CML_f_Abs(f_InputValue - a_LUT[s_Ind]);
              if (f_tmp < CML_f_Abs(f_InputValue - a_LUT[s_Ind+1]))
              {
                  s_Result = s_Ind;
              }
              else
              {
                  s_Result = s_Ind + 1;
              }
          }
      }
  }
  return s_Result;
}

/**************************************************************

  Functionname:    CML_b_isPointInsidePolygon            */ /*!

  @brief           Verifies whether a point is strictly inside a polygon.
                   Uses the Jordan curve theorem.

  @description     This function verifies whether a point is
                   strictly inside a polygon. Uses the Jordan curve
                   theorem.
                   Basic line equations are used to identify whether
                   a given point (a,b) lies inside the polygon or outside
                   the polygon.
                   Line Equation is used for each side of the polygon,
                   which is a line segment, if the line parallel to y-axis
                   with y=b, intersects this line segment. Then it is determined
                   whether the point lies to which side of the line segment. After
                   analysis of all sides, the final information is set.
                   If two points in a line are (x1,y1) and (x2,y2), then
                   line equation is:
                   (x-x1)      (y-y1)      (x-x1)(y2-y1)   (y-y1)(x2-x1)
                   --------- = --------- => ------------- = -------------
                   (x2-x1)     (y2-y1)           1               1

  @param[in]       a_Xarray :  Pointer to the X arrays of the polygon's vertices.
                               Optimal range for values [-F_MAX,.., F_MAX]
  @param[in]       a_Yarray :  Pointer to the Y arrays of the polygon's vertices.
                               Optimal range for values [-F_MAX,.., F_MAX]
  @param[in]       u_size :    The size of the arrays.
                               Supported range [Full range of uint32]
  @param[in]       f_Xpoint :  The X coordinate of the point.
                               Optimal range [-F_MAX,.., F_MAX]
  @param[in]       f_Ypoint :  The Y coordinate of the point.
                               Optimal range [-F_MAX,.., F_MAX]
                               where F_MAX is the square root of max value 
                               of float32.

  @return          True if the point is inside the polygon.

  @pre             -
  @post            -

  @note            First and last vertex of the polygon have to be identical!

  @author          nassim.ibrouchene@continental-corporation.com

*****************************************************************/
boolean CML_b_isPointInsidePolygon(const float32 a_Xarray[], const float32 a_Yarray[], uint32 u_size, float32 f_Xpoint, float32 f_Ypoint)
{
    boolean b_isInside = b_FALSE;
    boolean b_temp1;
    boolean b_temp2;
    uint32 i = 0u;

    /* Loop through all the edges */
    for (i = 1u; i < u_size; i++)
    {
        b_temp1 = (f_Ypoint > a_Yarray[i]) ? b_TRUE : b_FALSE;
        b_temp2 = (f_Ypoint > a_Yarray[i - 1U]) ? b_TRUE : b_FALSE;
        if (b_temp1 != b_temp2)
        {
            /* Find the intersection point */
            b_temp1 = (((f_Xpoint - a_Xarray[i]) * (a_Yarray[i - 1U] - a_Yarray[i])) < ((a_Xarray[i - 1U] - a_Xarray[i]) * (f_Ypoint - a_Yarray[i]))) ? b_TRUE : b_FALSE;
            b_temp2 = (a_Yarray[i - 1U] < a_Yarray[i])  ? b_TRUE : b_FALSE;		// Multiplying the expression with a negative number reverses the comparison.
            if (b_temp1 != b_temp2)
            {
                b_isInside = (b_isInside == b_TRUE) ? b_FALSE : b_TRUE;
            }
        }
    }
    return b_isInside;
}

/*****************************************************************************

  Functionname:    CML_u_arrayMaxValueFloat                                    

  @brief           Returns the index for an array; Array elements of float type.

  @description     The function finds and returns the index of maximum element in the array.
                   Linear search will be performing comparision of each element with the assumed maximum
                   and at end of complete traversal maximum element shall be identified.

  @param[in]       f_array :            Pointer to the input array,
                                        Supported range [Full range of float32]
  @param[in]       u_MaxSize :          size of the input array.
                                        Supported range [Full range of sint32]
  @Note            Findig the maximum element might consume lot of time of unsorted array, 
                   as linear search method implemented.

  @return          index of the input array

  @pre             -
  @post            -

  @author          Jeevan Kotre

**************************************************************************** */
uint32 CML_u_arrayMaxValueFloat(const float32 f_array[], const uint32 u_MaxSize)
{
    uint32  uimaxIndex = 0;
    uint32  uiIndex;
    float32 max_value = f_array[0];
    
    for(uiIndex = 1u; uiIndex < u_MaxSize; ++uiIndex)
    {
        if(f_array[uiIndex] > max_value)
        {
            uimaxIndex = uiIndex;
            max_value  = f_array[uiIndex];
        }
    }
    return uimaxIndex;
}

/*****************************************************************************

  Functionname:    CML_b_isNAN

  \brief           Check if input parameter is a NAN and returns true, false 
                   otherwise. 

  \description     Function checks if the entered number is beyond the float range,
                   returns TRUE if the number is not representable with IEEE 754 
                   representation for a floating point, false otherwise. 

  \param[in]       f_inp :  Input float value,
                   Supported range [Full range of float32]
                   
  \return          Boolean

  \pre             -
  \post            -

  \author          Jeevan Kotre
  
  \testmethod      Module testing - Courage
  
  \traceability  

**************************************************************************** */
/* PRQA S 4404 , 4440 20 */
/* Deactivate QAC warning 4404, 4440 , Date: 2019-06-17; Reviewer: uidk9586;
   Reason: The function is reviewed. There is no risk in violating this rule */
boolean CML_b_isNAN( float32 f_inp)
{
    uint32 temp;
    uint8 b_ret = b_FALSE;
    CML_t_FloatAsUnsigned u;

    u.f_d = f_inp;

    temp = (u.u_x & FLOAT_EXP_MASK);
    if(temp == FLOAT_EXP_MASK)
    {
        b_ret = b_TRUE;
    }

    return b_ret;
}
