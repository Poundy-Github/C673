/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_misc.h

  DESCRIPTION:               Provide miscellaneous mathematical tools (low pass filter, clothoid calculation, etc...)

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.70 $

  ---*/ /*---
  CHANGES:                   $Log: cml_misc.h  $
  CHANGES:                   Revision 1.70 2017/11/16 15:29:12CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_misc module.
  CHANGES:                   Revision 1.69 2017/11/16 13:47:32CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_misc module with coding guidelines.
  CHANGES:                   Revision 1.68 2017/10/26 06:44:58CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated the argument from pointer to array
  CHANGES:                   Revision 1.67 2017/10/25 19:22:49CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from the branch for the new function to find the maximum value in an array.
  CHANGES:                   Revision 1.66 2017/10/13 09:52:27CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the function header comment format
  CHANGES:                   Revision 1.65 2017/09/27 05:59:09CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.64 2017/06/28 11:12:40CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Fixed compilation issue in A15
  CHANGES:                   Revision 1.63 2017/06/22 07:47:28CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Typo fixing in inverse square root 67
  CHANGES:                   Revision 1.62 2017/06/20 09:54:21CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Changed the names of inverse calculation functions
  CHANGES:                   Revision 1.61 2017/06/20 07:58:17CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Few corrections in division routine
  CHANGES:                   Revision 1.60 2017/06/16 09:35:27CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Few bug fixes & changes for bit exactness between c66x & msvc for the new functions
  CHANGES:                   Revision 1.59 2017/06/06 07:41:52CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Fixed QAC warnings
  CHANGES:                   Revision 1.58 2017/05/30 12:14:07CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Corrected indentations.
  CHANGES:                   Moved pragmas related to interpolation to cml_interpol.h
  CHANGES:                   Revision 1.57 2017/05/30 08:32:14CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added function headers for square root functions
  CHANGES:                   Revision 1.56 2017/05/25 15:15:22CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Moved radar specific functions & changes from branch 1.48.2.3 to cml_radar.h to cml_radar.h
  CHANGES:                   Removed CML_Pow_VeryFast due to accuracy issues
  CHANGES:                   Revision 1.55 2017/05/25 06:50:45CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch 1.48.2.3
  CHANGES:                   Revision 1.54 2017/05/19 09:16:58CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Corrected typo in the inverse square root intrinsic
  CHANGES:                   Revision 1.53 2017/05/05 07:54:15CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Fixed a couple of typos.
  CHANGES:                   Revision 1.52 2017/05/04 13:23:01CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Extension of the set of reciprocals, square roots and reciprocal square roots.
  CHANGES:                   Revision 1.51.1.4 2017/05/02 10:29:52CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added  CML_f_ModReciprocal
  CHANGES:                   Revision 1.51.1.3 2017/03/28 08:24:20CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Modified the function CML_AlphaMaxBetaMin - To store intermediate floating point calculations in single precision format.
  CHANGES:                   Revision 1.51.1.2 2017/03/16 06:35:48CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Added code for biteaxactness between MSVC & c66x.
  CHANGES:                   Removed C_LONG_MAX as this is not used in this function.
  CHANGES:                   Revision 1.51.1.1 2017/03/15 12:00:31CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Modified the code for bitmatching MSVC and C66x output
  CHANGES:                   Revision 1.51 2016/11/18 11:17:59CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Merged changes from 1.48.1.1 - Moved CML_f_Neg to cml_ecu_emul.h
  CHANGES:                   Revision 1.50 2016/10/18 09:02:42CEST Reissner, Jens02 (uidq1491) 
  CHANGES:                   - reset to version 1.48
  CHANGES:                   Revision 1.49 2016/10/18 08:57:04CEST Reissner, Jens02 (uidq1491) 
  CHANGES:                   - adapted function header of  "CML_v_CalcCOFEgomotionMatrices" for EM_V6 usage
  CHANGES:                   Revision 1.48 2016/06/07 11:08:33CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Added a switch of magic numbers to the pow-function to use the less accurate, but non-degenerate ln-estimate near x = 1.
  CHANGES:                   Revision 1.47 2016/05/25 12:46:39CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Added inverse square roots with different accuracy, and a division-free square root.
  CHANGES:                   Revision 1.46 2016/05/09 16:23:38CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Fixed formality in declaration to work on all known platforms.
  CHANGES:                   Revision 1.45 2016/04/27 15:26:15CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Added a fast approximation of x^y.
  CHANGES:                   Revision 1.44 2016/04/26 14:48:38CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Type of the magic number in the fast ln corrected.
  CHANGES:                   Revision 1.43 2016/04/21 13:46:37CEST Ulveland, Lars (uidt7777) 
  CHANGES:                   Added Schraudolph's exponention for IEEE 32-bit float with improved constant.
  CHANGES:                   Added Schraudolph's natural logrithm for IEEE 32-bit float with a switch between constants for the region around 1.
  CHANGES:                   Revision 1.42 2015/08/26 12:22:11CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated comments section for inline function CML_f_Sign
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 26, 2015 12:22:12 PM CEST]
  CHANGES:                   Change Package : 360603:3 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.41 2015/08/25 06:56:25CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 6:56:26 AM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.40 2015/06/02 15:51:20CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - implemented higher accuracy log() functions
  CHANGES:                   --- Added comments ---  uidg6516 [Jun 2, 2015 3:51:20 PM CEST]
  CHANGES:                   Change Package : 324616:1 http://mks-psad:7002/im/viewissue?selection=324616
  CHANGES:                   Revision 1.39 2015/04/29 15:29:44CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 3:29:45 PM CEST]
  CHANGES:                   Change Package : 324617:2 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.38 2015/04/29 15:02:57CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables : Matrix functions
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 3:02:57 PM CEST]
  CHANGES:                   Change Package : 324617:2 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.37 2015/04/29 14:08:34CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables: CML_f_BoundedLinInterpol2
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 2:08:35 PM CEST]
  CHANGES:                   Change Package : 324617:1 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.36 2014/12/12 13:34:03CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added review ID to QA-C suppressions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 12, 2014 1:34:04 PM CET]
  CHANGES:                   Change Package : 266613:12 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.35 2014/12/11 08:47:00CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - extracted interpolation functions to new module cml_interpol to meet QA-C requirements regarding LOC metrics
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 11, 2014 8:47:01 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.34 2014/12/05 09:22:45CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed parameters of several functions from pointer to array where they are accessed like this
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 5, 2014 9:22:46 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.33 2014/10/22 11:30:38CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   declaration of static funcion in correct file
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 22, 2014 11:30:38 AM CEST]
  CHANGES:                   Change Package : 266613:7 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.32 2014/10/22 11:04:49CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   QA-C, function scope to static, rename function, move parameters to correct header
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 22, 2014 11:04:50 AM CEST]
  CHANGES:                   Change Package : 266613:6 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.31 2014/10/22 08:52:22CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added functions CML_f_PowToDB() and CML_f_MagToDB() for convertion to [dB]
  CHANGES:                   --- Added comments ---  uidg6516 [Oct 22, 2014 8:52:22 AM CEST]
  CHANGES:                   Change Package : 220462:2 http://mks-psad:7002/im/viewissue?selection=220462
  CHANGES:                   Revision 1.30 2014/10/01 14:46:47CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   add distance point 2 circle and distance point 2 clothoid computation from FCT to CML
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 1, 2014 2:46:48 PM CEST]
  CHANGES:                   Change Package : 265242:1 http://mks-psad:7002/im/viewissue?selection=265242
  CHANGES:                   Revision 1.29 2014/09/26 13:40:39CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - switched off QA-C-warnings on side effects for functions that don't have some and sure will never have
  CHANGES:                   --- Added comments ---  uidg6516 [Sep 26, 2014 1:40:40 PM CEST]
  CHANGES:                   Change Package : 266613:3 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.28 2014/09/15 13:36:55CEST Sternig-EXT, Sabine (uidw5860) 
  CHANGES:                   - removed CML_MAX3 as it is no longer needed
  CHANGES:                   --- Added comments ---  uidw5860 [Sep 15, 2014 1:36:56 PM CEST]
  CHANGES:                   Change Package : 240850:5 http://mks-psad:7002/im/viewissue?selection=240850
  CHANGES:                   Revision 1.27 2014/09/03 14:38:25CEST Sternig-EXT, Sabine (uidw5860) 
  CHANGES:                   - added max3 macro
  CHANGES:                   Revision 1.26 2014/07/30 08:01:25CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added suppression of QA-C-Warning 3415 (possible side effect on operand of logical operation) for functions that sure don't have any side effects
  CHANGES:                   --- Added comments ---  uidg6516 [Jul 30, 2014 8:01:26 AM CEST]
  CHANGES:                   Change Package : 243179:6 http://mks-psad:7002/im/viewissue?selection=243179
  CHANGES:                   Revision 1.25 2014/07/22 13:06:35CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - merged runtime optimisations for CML_Round(), CML_f_Floor() and CML_f_Ceil() to trunk
  CHANGES:                   --- Added comments ---  uidg6516 [Jul 22, 2014 1:06:36 PM CEST]
  CHANGES:                   Change Package : 245057:1 http://mks-psad:7002/im/viewissue?selection=245057
  CHANGES:                   Revision 1.24 2014/07/09 11:20:23CEST Kronauge, Matthias (uidg8751) 
  CHANGES:                   Add function CML_f_XPowY calculating X to the power of Y
  CHANGES:                   --- Added comments ---  uidg8751 [Jul 9, 2014 11:20:23 AM CEST]
  CHANGES:                   Change Package : 243179:3 http://mks-psad:7002/im/viewissue?selection=243179
  CHANGES:                   Revision 1.23.1.1 2014/06/03 10:58:22CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - use HW accelerated functions for CML_Round(), CML_f_Floor() and CML_f_Ceil()
  CHANGES:                   --- Added comments ---  uidg6516 [Jun 3, 2014 10:58:22 AM CEST]
  CHANGES:                   Change Package : 230040:5 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.23 2014/05/10 11:22:05CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C issues
  CHANGES:                   --- Added comments ---  uidg6516 [May 10, 2014 11:22:05 AM CEST]
  CHANGES:                   Change Package : 230040:1 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.22 2014/04/11 10:36:23CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added CML_f_Sign()
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 11, 2014 10:36:23 AM CEST]
  CHANGES:                   Change Package : 230040:1 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.21 2014/04/07 10:31:50CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:31:50 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.20 2014/03/12 10:39:30CET Brendel, Matthias (uidv8244) 
  CHANGES:                   natural log function
  CHANGES:                   --- Added comments ---  uidv8244 [Mar 12, 2014 10:39:30 AM CET]
  CHANGES:                   Change Package : 223474:1 http://mks-psad:7002/im/viewissue?selection=223474
  CHANGES:                   Revision 1.19 2014/02/12 14:34:00CET Kubera, David (kuberad) 
  CHANGES:                   add "IsInRange" functions (int/float, with/without limits) to CML
  CHANGES:                   --- Added comments ---  kuberad [Feb 12, 2014 2:34:00 PM CET]
  CHANGES:                   Change Package : 217433:2 http://mks-psad:7002/im/viewissue?selection=217433
  CHANGES:                   Revision 1.18 2014/02/04 15:12:58CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:12:59 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.17 2014/01/31 12:25:20CET Stolle, Ulf Eike (uidv1902) 
  CHANGES:                   Add CML function for Power of Two
  CHANGES:                   --- Added comments ---  uidv1902 [Jan 31, 2014 12:25:20 PM CET]
  CHANGES:                   Change Package : 145527:9 http://mks-psad:7002/im/viewissue?selection=145527
  CHANGES:                   Revision 1.16 2014/01/27 13:54:31CET Dintzer, Philippe (dintzerp) 
  CHANGES:                   - Runtime optimization of linear function
  CHANGES:                   --- Added comments ---  dintzerp [Jan 27, 2014 1:54:32 PM CET]
  CHANGES:                   Change Package : 189257:2 http://mks-psad:7002/im/viewissue?selection=189257
  CHANGES:                   Revision 1.15 2013/12/10 18:24:38CET Boll, Marie-Theres (uidu1091) 
  CHANGES:                   Carry over latest navi-developments into ARS400 path (shapepoint interpretation)
  CHANGES:                   --- Added comments ---  uidu1091 [Dec 10, 2013 6:24:39 PM CET]
  CHANGES:                   Change Package : 207953:1 http://mks-psad:7002/im/viewissue?selection=207953
  CHANGES:                   Revision 1.14 2013/10/30 14:52:43CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add function to check if a point lies inside a polygon
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 30, 2013 2:52:43 PM CET]
  CHANGES:                   Change Package : 159154:33 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.13 2013/07/10 15:41:31CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - fix CML_Round macro
  CHANGES:                   --- Added comments ---  uidu0849 [Jul 10, 2013 3:41:32 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.12 2013/05/13 17:38:24CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - clean up float and int macros
  CHANGES:                   --- Added comments ---  uidu0849 [May 13, 2013 5:38:25 PM CEST]
  CHANGES:                   Change Package : 159154:30 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.11 2013/05/06 14:46:54CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - reduce Lint/Misra warnings
  CHANGES:                   --- Added comments ---  uidu0849 [May 6, 2013 2:46:54 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.10 2013/05/03 09:57:29CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:29 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/04/15 08:39:04CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Tighten bound of CML_f_IsZero
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 15, 2013 8:39:04 AM CEST]
  CHANGES:                   Change Package : 159154:25 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/04/11 14:43:49CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Move CML_f_Neg from cml_ecu_emul.h to cml_misc.h (not ECU dependent)
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 11, 2013 2:43:50 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2013/04/09 12:58:28CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Move the sqrt approximation from cml_trigo to cml_misc
  CHANGES:                   - Move min, max, fminmax from cml_ecu_emul.h to cml_misc.h because they are not ECU dependent
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:58:28 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.6 2013/02/28 13:23:42CET Diewald, Fabian (uidt8878) 
  CHANGES:                   added methods to get LUT index
  CHANGES:                   --- Added comments ---  uidt8878 [Feb 28, 2013 1:23:42 PM CET]
  CHANGES:                   Change Package : 176321:1 http://mks-psad:7002/im/viewissue?selection=176321
  CHANGES:                   Revision 1.5 2012/10/17 15:31:15CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - rework to get rid of Misra / Lint and compiler warnings
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 17, 2012 3:31:15 PM CEST]
  CHANGES:                   Change Package : 159154:8 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2012/10/12 13:58:17CEST Oprisan, Dan (oprisand) 
  CHANGES:                   - Add MOD, REM, CEI, FLOOR functions to CML
  CHANGES:                   - remove obsolete FMOD_ macro from cml_mapping.h
  CHANGES:                   --- Added comments ---  oprisand [Oct 12, 2012 1:58:18 PM CEST]
  CHANGES:                   Change Package : 139701:13 http://mks-psad:7002/im/viewissue?selection=139701
  CHANGES:                   Revision 1.3 2012/09/25 13:42:28CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - include function fastlog10 and CalculatePolygonValue
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 25, 2012 1:42:28 PM CEST]
  CHANGES:                   Change Package : 159154:6 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:45CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:45 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:16CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup misc MISC (miscellaneous mathematical tools)
  @ingroup cml
@{ */

/*****************************************************************************
  QA-C
*****************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
/* Switch off QA-C warnings on side effects for functions, which don't have 
any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS CML_f_Sign
#endif /* #ifdef PRQA_SIZE_T */

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
/* Switch off QA-C warnings on side effects for functions, which don't have 
any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS CML_f_mod
#pragma PRQA_NO_SIDE_EFFECTS CML_f_rem
#pragma PRQA_NO_SIDE_EFFECTS CML_s_countNrOfBitsSet
#pragma PRQA_NO_SIDE_EFFECTS CML_f_fastlog10
#pragma PRQA_NO_SIDE_EFFECTS CML_f_fastlog
#pragma PRQA_NO_SIDE_EFFECTS CML_f_sqrtApprox
#pragma PRQA_NO_SIDE_EFFECTS CML_f_powerOfTwo
#pragma PRQA_NO_SIDE_EFFECTS CML_f_xPowY
#endif /* #ifdef PRQA_SIZE_T */

/*****************************************************************************
INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
#pragma message(__FILE__": Inclusion of cml_misc.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_MISC_INCLUDED
#define _CML_MISC_INCLUDED   ///< To avoid multiple inclusion of the file

#include "cml_ext.h"

/*****************************************************************************
  CONSTANTS
*****************************************************************************/
#define CML_f_ModuloEps 0.0000001f                          ///< Threshold value for the modulo function. The modulo function returns zero if the denominator is smaller than this value
#define N_LUT 32                                            ///< Length of lookup table for CML_f_fastlog10 
#define ONE_DIV_2POT23 1.192092895507813e-007f              ///< Value of inverse of (2^23)
#define C_LUT_MAP ((float32)N_LUT * ONE_DIV_2POT23)         ///< Look up Table Mapping value. Used in function CML_f_fastlog10

/*! constants for the sqrt approximation */

#define CML_SqrtApprox_NumExpo        (23u)                 ///< Position of exponent bits. Used in the approximate square root calculation.
#define CML_SqrtApprox_MantissaMask   (0x007fffffu)         ///< Mask to get the Mantissa part from a float value.
#define CML_SqrtApprox_ExponentOffset (0x7f)                ///< Maximum value of the exponent part in a float value.
#define CML_SqrtApprox_AlmostZero (1e-20f)                  ///< Threshold value for approximate square root calculation. CML_f_SqrtApprox returns zero for arguments smaller than this value

#define CML_LN_10 2.3025850929940456840179914546844f        ///< Natural logarithm of 10

#define CML_DBPOW_FACTOR 10.0f                              ///< Factor for conversion of power ratio to decibel value 
#define CML_DBMAG_FACTOR 20.0f                              ///< factor for conversion of magnitude ratio to decibel value 

/*****************************************************************************
TYPEDEFS
*****************************************************************************/

///< \brief       The Linear function arguments Structure
///< \description The Linear function arguments structure contains the minimum, 
///<              maximum output values along with the slope and intercept of the line.
typedef struct {
    float32 dAmin;         ///< Minimum output value
    float32 dAmax;         ///< Maximum output value
    float32 dM;            ///< Slope of the line  (Amax-Amin)/(Emax-Emin)
    float32 dB;            ///< Intercept value of the line   (Amax-Amin)/(Emax-Emin) * Emin
}CML_t_LinFunctionArgs; 


/*****************************************************************************
  MACROS
*****************************************************************************/

#define CML_LinFuncInit(MIN_Y,MAX_Y,MIN_X,MAX_X) {(MIN_Y),(MAX_Y),(((MAX_Y)-(MIN_Y))/((MAX_X)-(MIN_X))),(MIN_Y)-((((MAX_Y)-(MIN_Y))/((MAX_X)-(MIN_X)))*(MIN_X))}  ///< Utility macro to create a linear function initializer from the min/max input output points
#define CML_u_Abs(x)        (((x)<(0L))?(-(x)):(x))                                          ///< Absolute value for type long
#define CML_Min(x,y)        (((x)<(y))?(x):(y))                                              ///< The minimum of two values
#define CML_Max(x,y)        (((x)>(y))?(x):(y))                                              ///< The maximum of two values
#define CML_MinMax(min,max,value) (CML_Min(CML_Max(min,value),max))                          ///< To bound an integer 'value' between two values 'min' and 'max'
#define CML_IsInRange(min,max,value)           (((min) <= (value)) && ((value) <= (max)))    ///< To test whether 'value' is between two values 'min' and 'max' including limits
#define CML_IsInRange_ExclLim(min,max,value)   (((min) <  (value)) && ((value) <  (max)))    ///< To test whether integer 'value' is between two values 'min' and 'max' excluding limits
#define CML_f_IsInRange(min,max,value)         (((min) <= (value)) && ((value) <= (max)))    ///< To test whether float 'value' is between two values 'min' and 'max' including limits
#define CML_f_IsInRange_ExclLim(min,max,value) ((((min) + CML_f_AlmostZero) <  (value)) && ((value) < ((max) - CML_f_AlmostZero)))  ///< /*! To test whether float 'value' is between two values 'min' and 'max' excluding limits
#define CML_Sqr(x)          ((x)*(x))                                                        ///< Calculating the square (x*x) of a number
#define CML_Sign(x)         (((x)==(0))?(0):(((x)>(0))?(1):(-1)))                            ///< To determine the sign of a number. \description 0: Value equal 0 ||  1: Positiv Value || -1: Negativ Value

/*****************************************************************************
  Functionname:    CML_f_sign                                           */ /*!

  @brief           Determine the sign of the input value
  
  @description     This function determines and returns the sign of the input 
                   value.
                    0 : For zero
                    1 : positive input
                   -1 : negative input
  
  @param[in]       f_Input :   input for which sign needs to be determined.
  
  @return          Representation value for sign of the input
  
  @author          sebastian.schwarzkopf@continental-corporation.com
*****************************************************************************/
/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; 
   Date: 04.12.2014; Reason: Styleguide wants it like this and CML_INLINE is 
   defined compiler dependent for inlining without external linkage.
   Review-ID: 3942463 */
/* PRQA S 3406 3 */
/*! Determine the sign of a float number.
0: Value almost 0 ||  1: Positive Value || -1: Negative Value */
CML_INLINE sint32 CML_f_sign(float32 f_Input)
{
    sint32 s_Ret;

    s_Ret = (CML_f_Abs(f_Input) < CML_f_AlmostZero) ? 0L : ((f_Input < 0.0f) ? (-1L) : 1L);

    return s_Ret;
} /* CML_f_sign() */

#define CML_f_MinMax(min,max,value)  (CML_f_Min(CML_f_Max(min,value),max))                      ///< Bound a given float 'value' between 'min' and 'max'
#define CML_Deg2Rad(deg_) ((deg_)*(CML_f_Pi/180.f))                                             ///< Conversion of angle from degree(deg_) to radian unit
#define CML_Rad2Deg(rad_)  ((rad_)*(180.f/CML_f_Pi))                                            ///< Conversion of angle from radian(rad_) to degree unit
#define CML_GetBit(source, bitmask)   ( ((source) & (bitmask)) == (bitmask) )                   ///< Get the corresponding Bit on the basis of the BITMASK
#define CML_SetBit(source, bitmask)   ((source) |=  (bitmask))                                  ///< Set the corresponding Bit on the basis of the BITMASK
#define CML_ClearBit(source, bitmask) ((source) &= ~( bitmask) )                                ///< Reset the corresponding Bit on the basis of the BITMASK
#define CML_ConditionalSetClearBit(flag, bitmask, destination) ( ((destination) & ~(bitmask)) | (-(flag) & (bitmask)) ) ///< Conditional set / clear bit: if flag is true set the bitmask in destination, otherwise clear it
#define CML_f_IsZero(value) (CML_f_Abs(value) < CML_f_AlmostZero)                               ///< Comparision of floating point value to equal zero
#define CML_f_IsNonZero(value) (CML_f_Abs(value) >= CML_f_AlmostZero)                           ///< Test whether the floating point value is approx. not zero (TRUE) or zero (FALSE)
#define CML_f_LowPassFilter(neu,alt,zeit_k) (((neu)+((alt)*(zeit_k)))/((zeit_k)+1.F))           ///< Macro for a low pass filter */
#define CML_f_Curvature2Radius(x)   ( ( CML_f_Abs((x)) < 0.00002F ) ? (0.0F) : ( (1.0F)/(x) ) ) ///< For Conversion of Curvature to radius. \description  If Radius is greater than 50000 m, then Radius = 0m (Means straight ahead) 

#ifndef CML_NO_RTE_DEPENDENCY
#ifndef b_FALSE
#define b_FALSE ((boolean)0)
#endif
#ifndef b_TRUE
#define b_TRUE ((boolean)1)
#endif
#endif

/*****************************************************************************
FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_f_mod                                                *//*!

  \brief           Calculates modulus after division (similar to MATLAB)
                   
  \description     This function calculates modulus after division:
                   result = X - n*Y where n = floor(X/Y)
                   returns same values as CML_Rem if X and Y have same signs.
                   Divident & Divisor should be such that f_quotient should not 
                   exceed the range of sint32. 
                   The function returns the result as zero is the given modulus is 
                   approximately equivalent to zero inorder to avoid a division 
                   by zero operation in the function.
  \InOutCorrelation
                   Let 'x' be the input value and 'y' be the modulus, then,,
                   \f[ r = x - (n \times y)   \f] where n is,
                   \f[ n = floor(\frac{x}{y}) \f]
  \param[in]       f_value  : Divident under the range of float32. 

  \param[in]       f_modulo : Divisor under the range of float32.

  \return          f_value modulo f_modulo
                   
  \author          dan.oprisan@continental-corporation.com

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_mod(float32 f_value, float32 f_modulo);

/*****************************************************************************
  Functionname:    CML_f_rem                                                *//*!

  \brief           Calculates the remainder after division (similar to MATLAB)
                  
  \description     This function calculates remainder after division: 
                   result = X - n*Y where n = fix(X/Y)
                   returns same values as CML_Mod if X and Y have same signs.
                   Divident & Divisor should be such that f_quotient should not 
                   exceed the range of sint32. 
  \InOutCorrelation
                   Let 'x' be the input value and 'y' be the modulus, then,,
                   \f[ r = x - (n \times y)  \f] where n is,
                   \f[ n = fix(\frac{x}{y})  \f]
                   Here 'fix' does flooring operation for positive numbers and ceiling 
                   operation for negative numbers.
  \param[in]       f_dividend : Divident under the range of float32. 

  \param[in]       f_divisor  : Divisor under the range of float32.

  \return          remainder of f_dividend / f_divisor
                  
  \author          dan.oprisan@continental-corporation.com

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_rem(float32 f_dividend, float32 f_divisor);

/*****************************************************************************
  Functionname     - CML_f_hypot                                            *//*!

  \brief           Computes the length of a vector without risking over-
                   or under-flow.
                   
  \description     This function Computes the length of a vector without risking over-
                   or under-flow. The function operates in the absolute value of inputs,
                   take the fraction of the inputs with minimum value over the maximum.
                   The square is taken then followed by addition to unity and a 
                   multiplication with the maximum which results in the length
                   of the vector or in other terms value of the hypotenuse of a right 
                   angled triangle where the other two sides are represented by the 
                   absolute values of the inputs.
  \InOutCorrelation
                   Let x be the max of the absolute value of the two inputs to the funciton 
                   and y be the min of the two. Then,
                   \f[ l = \sqrt{(\frac{y}{x})^2 + 1} \times x \f]
                   
  \attention       The function does not take care of an invalid vector where
                   both inputs are equal to zero.
  \param[in]       f_x: A normalized real number.
  \param[in]       f_y: A normalized real number.
                   
  \return          The length of the vector (f_x, f_y)
                   
  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_hypot(float32 f_x, float32 f_y);

/*****************************************************************************
Functionname:    CML_s_countNrOfBitsSet                                     *//*!

  \brief           Count the number of bits set in a 32 bit unsigned int
  
  \description     This function counts and returns the number of bits set
                   in a 32 bit unsigned integer
                   Executes in constant runtime, 7 cycles amortized time on C6X.
                   The function uses various bit masks to verify the set bits.
  \InOutCorrelation
                \f[x_1 = val - ((val >> 1) \ \& \ B_1 \\
                   x_2 = (x_1 \ \& \ B_2) + ((x_1 >> 2) \  \& \ B_2) \\
                   n   = ((((x_2 + (x_2 >> 4)) \ \& \ B_3) \times B_4) >> 24) \f]
  
                  \f[ B_1 = (01010101010101010101010101010101)_{binary} \\ 
                      B_2 = (00110011001100110011001100110011)_{binary} \\
                      B_3 = (00001111000011110000111100001111)_{binary} \\
                      B_4 = (00000001000000010000000100000001)_{binary} \n
                  \f]
  \param[in]       u_PruefBits : 32-bit unsigned integer
                                 Supported values [Full range of uint32]
  
  \return          the number of bits set
  
  \author          L. Ulveland
  
  \testmethod  
  \traceability    
*****************************************************************************/
extern sint32 CML_s_countNrOfBitsSet (uint32 u_PruefBits);

/*******************************************************************************
  Functionname:    CML_f_log2                                              *//*!

  \brief           calculate the logarithm to the base of 2

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
  \InOutCorrelation
                   Logarithm of mantissa is calculated as,
                   \f[ log_2(x) = \sum_{i=0}^7 (p_ix^i) \f]

  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input < 0.0f.

  \return          log2(input) with accuracy of >5 decimals

  \param[in]       f_in: value for which log2() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  \created         02.06.2015
  \changed         02.06.2015

  \author          sebastian.schwarzkopf@continental-corporation.com

  \testmethod  
  \traceability    
*******************************************************************************/
extern float32 CML_f_log2(const float32 f_in);

/*******************************************************************************
  Functionname:    CML_f_log10                                             *//*!

  \brief           calculate the logarithm to the base of 10

  \description     This function calculates the logarithm to the base of 10.
                   The function uses the CML_f_log2 , computes the logarithm 
                   value of the input to the base 2 and then multiply the result 
                   by the correction factor based on the log thoerem. The 
                   correction factor will be equal to the logarithm value of 
                   2 to the base 10 or the inverse of the logarithm value of 
                   10 to the base 2.
  \InOutCorrelation
                   \f[ log_{10}(input) = log_2(input) \times log_{10}(2)  \f]

  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  \return          log10(input) with accuracy of >5 decimals

  \param[in]       f_in: value for which log10() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  \created         02.06.2015
  \changed         02.06.2015

  \author          sebastian.schwarzkopf@continental-corporation.com

  \testmethod  
  \traceability    
*******************************************************************************/
extern float32 CML_f_log10(const float32 f_in);

/*******************************************************************************
  Functionname:    CML_f_ln                                                *//*!

  \brief           calculate the natural logarithm

  \description     This function calculates the natural logarithm.
                   The function uses the CML_f_log2 , computes the logarithm 
                   value of the input to the base 2 and then multiply the result 
                   by the correction factor based on the log thoerem. The 
                   correction factor will be equal to the logarithm value of 
                   2 to the base e or the inverse of the logarithm value of 
                   e to the base 2.
  \InOutCorrelation
                   \f[ log_e(input) = log_2(input) \times log_e(2)  \f]

  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  \return          ln(input) with accuracy of >5 decimals

  \param[in]       f_in: value for which log10() will be calculated
                         Optimal range is [0,..,MAX_VAL], where MAX_VAL is square 
                         root of maximum value of float32.

  \created         02.06.2015
  \changed         02.06.2015

  \author          sebastian.schwarzkopf@continental-corporation.com

  \testmethod  
  \traceability    
*******************************************************************************/
extern float32 CML_f_ln(const float32 f_in);

/*****************************************************************************
  Functionname:    CML_f_fastlog10                                       *//*!

  \brief           Calculates a fast decadic logarithm approximation

  \description     This algorithm uses an IEEE754 floating point 
                   decomposition to get the 2's exponent as coarse log2 
                   value. To get a closer approximation the log2 of the 
                   mantissa is fetched from a lookup table and added to the 
                   exponent. At last the log2 is multiplied by a scaling 
                   factor to get the according log10 value.
  \InOutCorrelation
                   \f[ log_{10}(input) = log_2(input) \times log_{10}(2)  \f]

  \remark          Function will return float representation of (-inf) on input 
                   0.0f, (-NAN) on input values < 0.0f.

  \param[in]       f_value : Value to be logarithmized to the base of 10
                             Supported range [Full range of float32]

  \return          Decadic logarithm approximation of input value

  \author          Andreas Geier

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_fastlog10(float32 f_value);

/*****************************************************************************
  Functionname:    CML_f_fastlog                                         *//*!
  
  \brief           Calculates a fast natural logarithm approximation

  \description     This function uses CML_f_fastlog10.
                   fast log10 algorithm uses an IEEE754 floating point 
                   decomposition to get the 2's exponent as coarse log2 
                   value. To get a closer approximation the log2 of the 
                   mantissa is fetched from a lookup table and added to the 
                   exponent. At last the log2 is multiplied by a scaling 
                   factor to get the according log10 value.
                   This function then, calculates the natural logarithm using 
                   conversion factor of natural logarithm of 10.
  \InOutCorrelation
                   \f[ log_e(input) = log_10(input) \times log_e(10)  \f]

  \attention       This function does not check for the validity of input. 
                   Input should be greater than zero.
  \param[in]       f_value: Value to be logarithmized
                            Supported range [Full range of float32]

  \return          Natural logarithm approximation of input value

  \author          Matthias Brendel

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_fastlog(float32 f_value);

/* PRQA S 3629 18 */
/* Deactivate QAC warning 3629, Reviewer: L. Ulveland; Date: 25.05.2016; 
Reason: Union for documented operations on elements of floating point numbers. */

/// \brief     Union to manipulate float values as signed integers
/// \details   The Union holds a float value and a signed integer. This can be used to manipulate the float values.
typedef union 
{ 
    float32 f_d;   ///< Float representation
    sint32 s_x;  ///< Signed integer representation
} CML_t_FloatAsSigned;

/// \brief     Union to manipulate float values as unsigned integers
/// \details   The Union holds a float value and an unsigned integer. This can be used to manipulate the float values.
typedef union 
{
    float32 f_d;   ///< Float representation 
    uint32 u_x;  ///< Unsigned integer representation
} CML_t_FloatAsUnsigned;

/*****************************************************************************
  Functionname     - CML_f_modReciprocal                                    *//*!

  \brief           Computes the modulo of a known constant using its reciprocal to avoid explicit division.

  \description     This function calculates the remainder of x when divided by y. \n Works only for y > 0 .\n
                   The division is avoided in the function by passing the reciprocal along with the divisor
                   when the divisor is a known constant or a multiple of Pi. 
  \InOutCorrelation
                   Let f the input, d be the divisor and r be the reciprocal of divisor, then
                   \f[ q = integer part of (f \times r) \\
                       mod = f - (q \times d) \f]
  \param[in]       f_Value:   Denominator
  \param[in]       f_Reciprocal_Divisor: 1/Divisor.
  \param[in]       f_Divisor: Divisor
                   
  \return          f_Value%f_Divisor

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_modReciprocal(const float32 f_Value, const float32 f_Reciprocal_Divisor, const float32 f_Divisor)
{
    float32 f_Temp;
    float32 f_Quotient;
    float32 f_IntegralQuotient;
    sint32  i_IntegerQuotient;

    f_Quotient = f_Value  * f_Reciprocal_Divisor;
    i_IntegerQuotient     = (sint32)f_Quotient;
    f_IntegralQuotient    = (float32)i_IntegerQuotient;
    f_IntegralQuotient   *= f_Divisor;
    f_Temp                =  f_Value - f_IntegralQuotient;
    return f_Temp;
}

/*****************************************************************************
  Functionname     - CML_f_alphaMaxBetaMin                                    *//*!

  \brief           Approximates the length of the vector (f_x, f_y)

  \description     This function gives an approximation of the length of a 
                   vector defined by the input values. The function computes
                   the result using predefined constants alpha and beta and 
                   saves the use of any complex operation for the computation
                   Maximum error is 3.96%. 
  \InOutCorrelation
                   Let x and y be the absolute values of the input entries.
                   Also assume that x <= y
                   \f[ l = (y \times \alpha) + (x \times \beta) \f]

                   alpha = 0.96043387 and beta = 0.39782473

  \param[in]       f_x: A real number.
  \param[in]       f_y: A real number.

  \return          The length of the vector (f_x, f_y)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_alphaMaxBetaMin(float32 f_x, float32 f_y)
{
    const float32 f_Alpha = 0.96043387F;
    const float32 f_Beta  = 0.39782473F;
    float32 f_Max;
    float32 f_Min;
    f_x = CML_f_Abs(f_x);
    f_y = CML_f_Abs(f_y);
    f_Max = CML_Max(f_x, f_y) * f_Alpha;
    f_Min = CML_Min(f_x, f_y) * f_Beta;
    return f_Max + f_Min;
}

/*****************************************************************************
  Functionname     - CML_s_alphaMaxBetaMinInt                               *//*!

  \brief           Approximates the length of the vector (f_x, f_y)

  \description     This function gives an approximation of the length of a 
                   vector defined by the input values. The function computes
                   the result using predefined constants alpha and beta and 
                   saves the use of any complex operation for the computation.
                   The function process integer values. Max relative error is 4%. 
  \InOutCorrelation
                   Let x and y be the absolute values of the input entries.
                   Also assume that x <= y
                   \f[ l = (y \times \alpha) + (x \times \beta) \f]

                   alpha = 123/128 and beta = 51/128


  \param[in]       s_x: An integer between -2^24 and 2^24.
  \param[in]       s_y: An integer between -2^24 and 2^24.

  \return          The length of the vector (s_x, s_y)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE sint32 CML_s_alphaMaxBetaMinInt(const sint32 s_x, const sint32 s_y)
{
    const sint32 s_Alpha = 123;
    const sint32 s_Beta  = 51;
    sint32 AbsX = (s_x < 0) ? -s_x : s_x;
    sint32 AbsY = (s_y < 0) ? -s_y : s_y;
    sint32 Max  = (AbsX > AbsY) ? AbsX : AbsY;
    sint32 Min  = (AbsY > AbsX) ? AbsX : AbsY;
    return (s_Alpha * Max + s_Beta * Min) / 128;
}

/*****************************************************************************
  Functionname     - CML_f_invSqrt14                                          *//*!

  \brief           Approximates the inverse square root of x

  \description     This function provides the approximation of inverse of
                   square root of a number. \n Maximum error is 3.5%. 
                   No input checks are made.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of a predefined constant to 
                   manipulate the floating point value to get the 
                   square root approximation.
  \InOutCorrelation
                   Let s be the integer typecasted value of input and
                   M be the predefined constant which equals 0x5f375a86.
                  \f[ r = M - (\frac{s}{2}) \f]
                   'r' can now be typecasted back to floating point to 
                    get the square root of the input.

  \param[in]       f_x: A positive real number.

  \return          A rough approximation of x^(-1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_invSqrt14(float32 f_x);
CML_INLINE float32 CML_f_invSqrt14(float32 f_x)
{
#ifdef CML_OPT_c66x
    return _rsqrsp(f_x);   /* More accurate than advertised, but as fast as can be.*/
#else
    const sint32 i_MagicNumber = 0x5f375a86;
    sint32 s_i;
    CML_t_FloatAsSigned u;
    u.f_d = f_x;

    // date: 2015-01-14, reviewer: Ulveland (uidt7777), reason: We really do operate mathematically on the individual bits.
    // PRQA S 3017 1
    s_i = u.s_x;
    s_i = i_MagicNumber - (s_i / 2);
    u.s_x = s_i;
    return u.f_d;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_invSqrt53                                          *//*!

  \brief           Approximates the inverse square root of x

  \description     Maximum error is 4.8e-6. No input checks are made.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of a predefined constant to 
                   manipulate the floating point value to get the 
                   square root approximation. This in turn calls 
                   CML_InvSqrt14 for the initial approximation and does
                   the correction computation to improve the accuracy.
  \InOutCorrelation
                   Let x be the input and y be the inverse square root obtained 
                   from the function CML_InvSqrt14. Also, 
                   M be the predefined constant which equals 1.5. 
                   \f[ y =  y \times (M - (\frac{x \times y^2}{2})) \f]

  \param[in]       f_x: A positive real number.

  \return          A highly accurate approximation of x^(-1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_invSqrt53(float32 f_x);
CML_INLINE float32 CML_f_invSqrt53(float32 f_x)
{
#ifdef CML_OPT_c66x	
    /* x[n+1] = x[n]*(1.5-v/2*x[n]*x[n]) */
    float32 ftemp1;
    float32 f_x2 = f_x * 0.5F; /* v/2 */
    float32 f_Initial = _rsqrsp(f_x);
    float32 f_InitialSquared = f_Initial * f_Initial;
    float32 f_Temp = f_x2 * f_InitialSquared;
    f_Temp = 1.5F - f_Temp;
    ftemp1 = f_Initial * f_Temp;
    return ftemp1;
#else                                       
    const float32 f_MagicNumber = 1.5F;
    float32 f_x2;
    float32 f_y;
    float32 f_temp1;
    float32 f_temp2;
    float32 f_temp3;

    f_x2 = f_x * 0.5F;
    f_y = CML_f_invSqrt14(f_x);

    /* Below lines implement
    "f_y = f_y * (f_MagicNumber - (f_x2 * f_y * f_y));"
    The code is modified to maintain consistency between MSVC & CCS
    */
    f_temp1 = f_x2 * f_y;
    f_temp2 = f_temp1 * f_y;
    f_temp3 = f_MagicNumber - f_temp2;
    f_y = f_y * f_temp3;

    f_temp1 = f_x2 * f_y;
    f_temp2 = f_temp1 * f_y;
    f_temp3 = f_MagicNumber - f_temp2;
    f_y = f_y * f_temp3;

    return f_y;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_invSqrt67                                         *//*!

  \brief           Approximates the inverse square root of x

  \description     Maximum error is 2.07e-7. No input checks are made.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of a predefined constant to 
                   manipulate the floating point value to get the 
                   square root approximation. This in turn calls 
                   CML_InvSqrt14 for the initial approximation and does
                   the correction computation to improve the accuracy.
  \InOutCorrelation
                   Let x be the input and y be the inverse square root obtained 
                   from the function CML_InvSqrt14. Also, 
                   M be the predefined constant which equals 1.5. 
                   \f[ y =  y \times (M - (\frac{x \times y^2}{2})) \f]
                   The above step is executed twice with the second time
                   using the y result from the first execution.

  \param[in]       f_x: A positive real number.

  \return          A precise calculation of x^(-1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_invSqrt67(float32 f_x);
CML_INLINE float32 CML_f_invSqrt67(float32 f_x)
{
#ifdef CML_OPT_c66x
    float32 f_Temp1;
    float32 f_NewEst;
    float32 f_x2 = f_x * 0.5F;
    float32 f_Initial = _rsqrsp(f_x);
    float32 f_InitialSquared = f_Initial * f_Initial;
    float32 f_Temp = f_x2 * f_InitialSquared;
    f_Temp    = 1.5F - f_Temp;
    f_NewEst  = f_Initial * f_Temp;

    f_Temp    = f_x2 * f_NewEst;
    f_Temp    = f_Temp * f_NewEst;
    f_Temp    = 1.5F - f_Temp;
    f_Temp1   = f_NewEst * f_Temp;
    return f_Temp1;

#else                                       
    const float32 f_MagicNumber = 1.5F;
    float32 f_x2;
    float32 f_y;
    float32 f_temp1;
    float32 f_temp2;
    float32 f_temp3;

    f_x2 = f_x * 0.5F;
    f_y = CML_f_invSqrt14(f_x);

    /* Below lines implement
    "f_y = f_y * (f_MagicNumber - (f_x2 * f_y * f_y));"
    The code is modified to maintain consistency between MSVC & CCS
    */
    f_temp1 = f_x2 * f_y;
    f_temp2 = f_temp1 * f_y;
    f_temp3 = f_MagicNumber - f_temp2;
    f_y = f_y * f_temp3;

    f_temp1 = f_x2 * f_y;
    f_temp2 = f_temp1 * f_y;
    f_temp3 = f_MagicNumber - f_temp2;
    f_y = f_y * f_temp3;

    return f_y;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_invSqrt27                                          *//*!

  \brief           Approximates the inverse square root of x

  \description     Maximum error is 0.2%. No input checks are made.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of a predefined constant to 
                   manipulate the floating point value to get the 
                   square root approximation. This in turn calls 
                   CML_InvSqrt14 for the initial approximation and does
                   the correction computation to improve the accuracy.
  \InOutCorrelation
                   Let x be the input and y be the inverse square root obtained 
                   from the function CML_InvSqrt14. Also, 
                   M be the predefined constant which equals 1.5. 
                   \f[ y =  y \times (M - (\frac{x \times y^2}{2})) \f]

  \param[in]       f_x: A positive real number.

  \return          A rough approximation of x^(-1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_invSqrt27(float32 f_x);
CML_INLINE float32 CML_f_invSqrt27(float32 f_x)
{
#ifdef CML_OPT_c66x
    return _rsqrsp(f_x);                       /* Intrinsic is accurate enough at this level.*/
#else                                       
    const float32 f_MagicNumber = 1.5F;
    float32 f_x2;
    float32 f_y;
    float32 f_temp1;
    float32 f_temp2;
    float32 f_temp3;

    f_x2 = f_x * 0.5F;
    f_y = CML_f_invSqrt14(f_x);
    /* Below lines implement
    "f_y = f_y * (f_MagicNumber - (f_x2 * f_y * f_y));"
    The code is modified to maintain consistency between MSVC & CCS
    */
    f_temp1 = f_x2 * f_y;
    f_temp2 = f_temp1 * f_y;
    f_temp3 = f_MagicNumber - f_temp2;
    f_y = f_y * f_temp3;

    return f_y;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_sqrt14                                            *//*!

  \brief           Approximates the square root of x

  \description     No input checks are made.
                   The caller must guarantee that the input is valid.
                   The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f]

  \param[in]       f_x: A positive real number.

  \return          An approximation of of x^(1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_sqrt14(float32 f_x);
CML_INLINE float32 CML_f_sqrt14(float32 f_x)
{
    float32 f_temp;
    f_temp = f_x * CML_f_invSqrt14(f_x);
    return f_temp;
}

/*****************************************************************************
  Functionname     - CML_f_sqrt27                                             *//*!

  \brief           Approximates the square root of x

  \description     No input checks are made.
                   The caller must guarantee that the input is valid.
                   The function make use of the CML_InvSqrt27 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f]

  \param[in]       f_x: A positive real number.

  \return          A rough approximation of x^(1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_sqrt27(float32 f_x);
CML_INLINE float32 CML_f_sqrt27(float32 f_x)
{
    float32 f_temp;
    f_temp = f_x * CML_f_invSqrt27(f_x);
    return f_temp;
}

/*****************************************************************************
  Functionname     - CML_f_sqrt53                                             *//*!

  \brief           Approximates the square root of x

  \description     No input checks are made.
                   The caller must guarantee that the input is valid.
                   The function make use of the CML_InvSqrt53 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f]

  \param[in]       f_x: A positive real number.

  \return          A highly accurate approximation of x^(1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_sqrt53(float32 f_x);
CML_INLINE float32 CML_f_sqrt53(float32 f_x)
{
    float32 f_temp;
    f_temp = f_x * CML_f_invSqrt53(f_x);
    return f_temp;
}

/*****************************************************************************
  Functionname     - CML_f_sqrt67                                             *//*!

  \brief           Approximates the square root of x

  \description     No input checks are made.
                   The caller must guarantee that the input is valid.
                   The function make use of the CML_InvSqrt67 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f]

  \param[in]       f_x: A positive real number.

  \return          A precise calculation of x^(1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_sqrt67(float32 f_x);
CML_INLINE float32 CML_f_sqrt67(float32 f_x)
{
    float32 f_temp;
    f_temp = f_x * CML_f_invSqrt67(f_x);
    return f_temp;
}

/*****************************************************************************
  Functionname     - CML_f_fastestInv                                         *//*!

  \brief           Approximates inverse of x roughly

  \description     Wraps the fastest inverse(division) approximation for each platform.
                   Generic version: Max Error 6.9%, average 4.3%.
                   Ti version: Max 0.46%, average 0.15%.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then square it  to get the required inverse of the number.
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{x}})^2 \f]

  \param[in]       f_x: A normalized real number.

  \return          1 / x

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_fastestInv(float32 f_x)
{
#ifdef CML_OPT_c66x
    return _rcpsp(f_x);                           /* Intrinsic is accurate enough at this level */
#else                                       
    float32 f_AbsX = f_x < 0.0F ? -f_x : f_x;
    boolean b_NegaX = (f_x < 0.0F) ? b_TRUE : b_FALSE;
    float32 f_Initial = CML_f_invSqrt14(f_AbsX);    /*  Initial estimate of 1/sqrt(x) */
    f_Initial *= f_Initial;                       /*  Squaring it generated inital estimate of 1/x */

    return (b_NegaX == b_TRUE) ? -f_Initial : f_Initial;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_fastInv23                                          *//*!

  \brief           Computes inverse of x

  \description     Maximum error is 0.48%, average 0.23%. No input checks are made.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then square it  to get the inverse of the number. 
                   Now to improve the accuracy, a correction compuatation is done.
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{|x|}})^2 \f]
                   \f[ r = r \times (2 - (|x| \times r)) \f].
                   The sign of the output is then applied as same to the sign of the 
                   input

  \param[in]       f_x: A normalized real number.

  \return          1 / x

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_fastInv23(float32 f_x)
{
#ifdef CML_OPT_c66x
    return _rcpsp(f_x);                           /* Intrinsic is accurate enough at this level */
#else                                       
    float32 f_Tmp;
    float32 f_AbsX = f_x < 0.0F ? -f_x : f_x;
    boolean b_NegaX = (f_x < 0.0F) ? b_TRUE : b_FALSE;
    float32 f_Initial = CML_f_invSqrt14(f_AbsX);   /*  Initial estimate of 1/sqrt(x) */
    f_Initial *= f_Initial;                      /*  Squaring it generated inital estimate of 1/x  */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = 2.0F - f_Tmp;
    f_Tmp = f_Initial * f_Tmp;                   /*  Single iterations brings us close enough */

    return (b_NegaX == b_TRUE) ? -f_Tmp : f_Tmp;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_fastInv47                                         *//*!

  \brief           Computes inverse of x
                  
  \description     Maximum error is 1.24e-5, average 4.4e-6. No input checks are made.
                   Maximum error for Ti version is 2.09e-5, average 3.4e-6
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of the CML_InvSqrt27 function to
                   compute the inverse square root of the floating point number
                   and then square it  to get the inverse of the number. 
                   Now to improve the accuracy, a correction compuatation is done.
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{|x|}})^2 \f]
                   \f[ r = r \times (2 - (|x| \times r)) \f].
                   The sign of the output is then applied as same to the sign of the 
                   input
                  
  \param[in]       f_x: A normalized real number.
                  
  \return          1 / x
                  
  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_fastInv47(float32 f_x)
{
#ifdef CML_OPT_c66x
    float32 f_Initial = _rcpsp(f_x);
    float32 f_Tmp     = f_Initial * f_x;
    f_Tmp             = 2.0F - f_Tmp;
    f_Tmp             = f_Tmp * f_Initial;
    return f_Tmp;
#else
    float32 f_Tmp;
    float32 f_AbsX = f_x < 0.0F ? -f_x : f_x;           
    boolean b_NegaX = (f_x < 0.0F) ? b_TRUE : b_FALSE;
    float32 f_Initial = CML_f_invSqrt27(f_AbsX);          /* Initial estimate of 1/sqrt(x) */
    f_Initial *= f_Initial;                             /* Squaring it generated inital estimate of 1/x */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = 2.0F - f_Tmp;
    f_Tmp = f_Initial * f_Tmp;                          /* Single iterations brings us close enough */
    return (b_NegaX == b_TRUE) ? -f_Tmp : f_Tmp;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_fastInv69                                          *//*!

  \brief           Computes inverse of x

  \description     Maximum error is 1.19e-7, average 1.5e-8 No input checks are made.
                   The caller must guarantee that the input is valid.
                   The method is described in Lomont(2003)
                   The function make use of the CML_InvSqrt27 function to
                   compute the inverse square root of the floating point number
                   and then square it  to get the inverse of the number. 
                   Now to improve the accuracy, a correction compuatation is done.
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{|x|}})^2 \f]
                   \f[ r = r \times (2 - (|x| \times r)) \f].
                   The above step is executed twice with the second time. Third step is then, 
                   \f[ r = 2r - (|x| \times r^2) \f].
                   The sign of the output is then applied as same to the sign of the 
                   input
                   using the y result from the first execution.

  \param[in]       f_x: A normalized real number.

  \return          1 / x

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
CML_INLINE float32 CML_f_fastInv69(float32 f_x)
{
#ifdef CML_OPT_c66x
    float32 f_NewEst;
    float32 f_Initial = _rcpsp(f_x);

    float32 f_Tmp     = f_Initial * f_x;
    f_Tmp             = 2.0F - f_Tmp;
    f_NewEst          = f_Tmp * f_Initial;

    /* A reformulation of NR increases accuracy at the cost of a single multiplication */
    f_Tmp             = f_x * f_NewEst;
    f_Tmp             = f_Tmp * f_NewEst; 
    f_NewEst          = 2.0F * f_NewEst;
    f_Tmp             = f_NewEst - f_Tmp;
    return f_Tmp;
#else
    float32 f_Tmp;
    float32 f_AbsX = f_x < 0.0F ? -f_x : f_x;
    boolean b_NegaX = (f_x < 0.0F) ? b_TRUE : b_FALSE;
    float32 f_Initial = CML_f_invSqrt14(f_AbsX);   /* Initial estimate of 1/sqrt(x) */
    f_Initial *= f_Initial;                      /* Squaring it generated inital estimate of 1/x */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = 2.0F - f_Tmp;
    f_Initial = f_Initial * f_Tmp;               /* Initial is now the initial for the next iteration */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = 2.0F - f_Tmp;
    f_Initial = f_Initial * f_Tmp;               /* Initial is now the initial for the next iteration */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = f_Tmp * f_Initial;                   /* Last iteration is different to reduce the rounding error */
    f_Initial = f_Initial * 2.0F;
    f_Tmp = f_Initial - f_Tmp;

    return (b_NegaX == b_TRUE) ? -f_Tmp : f_Tmp;
#endif
}

/*****************************************************************************
  Functionname     - CML_f_sqrtVeryFast                                      *//*!

  \brief           Approximates the square root of x

  \description     Maximum error is 3.5%, average is 1.9% No input checks are made.
                   The caller must guarantee that the input is valid.
                   The function make use of a predefined constant 0x4C000 to 
                   evaluate the square root using some basic operations.
  \InOutCorrelation
                   Let Hx be the hexadecimal value of the input and S be the
                   predefined constant,
                   \f[ R = \frac{H_x - (1<<23)}{2} + (1<<29) - S  \f]

  \param[in]       f_x: A positive real number.

  \return          A rough approximation of x^(1/2)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_sqrtVeryFast(float32 f_x);
CML_INLINE float32 CML_f_sqrtVeryFast(float32 f_x)
{
    const uint32 u_SqrtConst = 0x4C000;
    CML_t_FloatAsUnsigned u;
    uint32 u_HexRepresentation;
    u.f_d = f_x;
    u_HexRepresentation = u.u_x;
    u_HexRepresentation -= 1U << 23U;
    u_HexRepresentation /= 2U;
    u_HexRepresentation += 1U << 29U;
    u.u_x = u_HexRepresentation - u_SqrtConst;
    return u.f_d;
}
/*****************************************************************************
  Functionname     - CML_f_expVeryFast                                       *//*!

  \brief           Approximates exp(x) (the natural exponential) for some number x

  \description     Schraudolph (1999) adapted to 32-Bit float.
                   Accuracy < 4% throughout the range. The calculation is done
                   using predefined constants 12102203 and 1064866805 and bit 
                   manipulation operations. 
  \InOutCorrelation
                   Let a be the input and the constants bt M1 and M2.
                   \f[ R = (M_1 \times a) + M_2 \f]
                   The result is typecasted to signed integer and the 
                   representation is read as float. This value will be the 
                   exponential approximation.

  \param[in]       f_a: the number for which we want e^x. 

  \attention       The input should not cross 88.7F to avoid overflow. 

  \return          exp(x)

  \author          Lars Ulveland

  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
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

  \description     Schraudolph (1999) adapted to 32-Bit float.
                   Accuracy ~ 30% in the range 0.95..1.1
                            < 4% outside this range
                    The calculation is done using predefined constants 
                   1/12102203, 1064866805 and 1065353216 and bit 
                   manipulation operations. The function chooses the constant
                   based on the range in which the input falls in.
  \InOutCorrelation
                   Let x be the input read as a signed integer and the constants be M1 and M2.
                   \f[ r = ((float)(x - M_2)) \times M_1; \f]
                   The constant M2 is taken as 1065353216 if the input is in range 0.95-1.08.
                   Otherwise M2 is 1064866805.

  \param[in]       f_a: the number for which we want ln x

  \return          ln(x)

  \author          Lars Ulveland
  
  \testmethod  
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: L. Ulveland; Date: 21.04.2016; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
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
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: S. Schwarzkopf; Date: 14.10.2014; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
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
  \traceability    
*****************************************************************************/
/* PRQA S 3406 4 */
/* Deactivate QAC warning 3406, Reviewer: S. Schwarzkopf; Date: 14.10.2014; 
   Reason: ALGO_INLINE is defined to have no external linkage on target platform. */
CML_INLINE float32 CML_f_magToDB(float32 f_ratio);
CML_INLINE float32 CML_f_magToDB(float32 f_ratio)
{
    return CML_DBMAG_FACTOR * CML_f_log10(f_ratio);
} /* CML_f_MagToDB() */

/*****************************************************************************
  Functionname:    CML_f_sqrtApprox                                         *//*!

  \brief           approximates the square root of a float

  \description     approximates the square root of a float
                   the relative error is bound by 4.22e-7 \n
                   special cases: 

                                  |input | output    | 
                                  |  < 0 | 0         | 
                                  |  DEN | 0         | 
                                  |  NAN | max_float | 
                                  |  INF | max_float | 

                  The function extracts the exponent and mantissa parts 
                  from the given floating point number and process them.

  \param[in]       f_radicand : the radicand
                                Supported range [Full positive range of float32]
  
  \return          square root of f_value
  
  \author          Steen Kristensen, DC Research and Technology, Berlin
                   Jesko Klandt, DC Research and Technology, Berlin
                   Sven Behrendorf, ADC-Lindau
                   D. Meschenmoser
 
  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_sqrtApprox(float32 f_radicand);

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
  \traceability    
*****************************************************************/
extern float32 CML_f_powerOfTwo(float32 f_value);

/*****************************************************************************

  Functionname:    CML_s_getLutIndex                                       *//*!

  \brief           Returns the index for a lookup table value; the input
                   value is in the domain of f_LutMinInputValue and f_LutRes

  \description     The function finds and returns the index for a given look up 
                   table value. The result will be bounded between the maximum 
                   and minimum look-up table indices permitted.
                   The function checks for a non zero resolution of look up table.
                   It returns the minimum index if the resolution is zero.
  \InOutCorrelation
                   Let  IDX = Look-up Table index 
                        INP = Input value for which index has to be found
                        MIP = Minimum Input Value in the look-up table
                        RES = Resolution of the look-up table
                   then,
                   \f[     IDX = MIP + ROUND(\frac{(INP-MIP)}{RES})  \f]

  \param[in]       f_InputValue :       Input value for the Lookup Table
                                        Supported range [Full range of float32]
  \param[in]       f_LutMinInputValue : Minimal input value of the Lookup table
                                        Supported range [Full range of float32]
  \param[in]       f_LutRes :           resolution of the Lookup table
                                        Supported range [Full range of float32]
  \param[in]       s_LutMinInd :        first index of the lookup table
                                        Supported range [Full range of sint32]
  \param[in]       s_LutMaxInd :        last index of the lookup table
                                        Supported range [Full range of sint32]
                                        Note: The result may vary from expected for 
                                        very high input values due to type conversion
                                        from float to signed int.

  \return          index of the lookup table

  \author          Philippe Dintzer, Fabian Diewald

  \testmethod  
  \traceability    
**************************************************************************** */
extern sint32 CML_s_getLutIndex(const float32 f_InputValue, const float32 f_LutMinInputValue, const float32 f_LutRes, const sint32 s_LutMinInd, const sint32 s_LutMaxInd);

/*****************************************************************************

  Functionname:    CML_s_getLutIndexBackwards                              *//*!

  \brief           Returns the index for a lookup table value; the input
                   value is in the domain of a LUT.

  \description     The function finds and returns the look-up table index for a 
                   given value. The result will be bounded between the maximum 
                   and minimum look-up table indices permitted.
                   The index of the look-up table value, which is more closer to
                   the given value, will be returned. The minimum and maximum indices
                   are also received as inputs. The input value is checked 
                   against both the values at minimum index and maximum index
                   in the look-up table and limits the output to these
                   indices if the input is less than the value at min index or
                   or greater than the value at the max index.
                   @startuml
                   (*)--> [val, min, max, LUT] Check the input value
                   If val < LUT[min]
                   -->[Yes] r = min
                   note left : Clip the result at minimum index
                   -->(*)
                   Else
                   -->[No] If val > LUT[max]
                   -->[Yes] r = max
                   note right: Clip the result at maximum index
                   -->(*)
                   Else
                   -->[No] index = min
                   --> Check for the range in which the value falls in
                   If val is in between LUT[index] and LUT[index+1]
                   --> [Yes] If val is closer to LUT[index]
                   --> [Yes] r = index
                   -->(*)
                   Else
                   --> [No] r = index + 1
                   -->(*)
                   EndIf
                   Else
                   --> [No] index = index + 1
                   If index < max
                   --> [Yes] Check for the range in which the value falls in
                   Else
                   --> [No] r = default
                   -->(*)
                   EndIf
                   EndIf
                   @enduml

  \param[in]       f_InputValue : Input value for the Lookup Table
                                  Supported range [Full range of float32]
  \param[in]       a_LUT :        Lookup table
                                  Supported range for values in a_LUT[] 
                                  [Full range of float32]
  \param[in]       s_LutMinInd :  first index of the lookup table.
                                  Supported range [Full positive range of sint32]
  \param[in]       s_LutMaxInd :  last index of the lookup table.
                                  Supported range [Full positive range of sint32]

  \return          index of the lookup table

  \author          Fabian Diewald

  \testmethod  
  \traceability    
**************************************************************************** */
extern sint32 CML_s_getLutIndexBackwards(const float32 f_InputValue, const float32 a_LUT[], const sint32 s_LutMinInd, const sint32 s_LutMaxInd);

/**************************************************************

  Functionname:    CML_b_isPointInsidePolygon               *//*!

  \brief           Verifies whether a point is strictly inside a polygon.
                   Uses the Jordan curve theorem.

  \description     This function verifies whether a point is
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
                   \f[  \frac{(x-x_1)}{(x_2-x_1)} = \frac{(y-y_1)}{(y_2-y_1)} \f]
                   or, \f[  (x-x_1) \times (y_2-y_1) = (y-y_1) \times (x_2-x_1)\f]

  \param[in]       a_Xarray :  Pointer to the X arrays of the polygon's vertices.
                               Optimal range for values [-F_MAX,.., F_MAX]
  \param[in]       a_Yarray :  Pointer to the Y arrays of the polygon's vertices.
                               Optimal range for values [-F_MAX,.., F_MAX]
  \param[in]       u_size :    The size of the arrays.
                               Supported range [Full range of uint32]
  \param[in]       f_Xpoint :  The X coordinate of the point.
                               Optimal range [-F_MAX,.., F_MAX]
  \param[in]       f_Ypoint :  The Y coordinate of the point.
                               Optimal range [-F_MAX,.., F_MAX]
                               where F_MAX is the square root of max value 
                               of float32.

  \return          True if the point is inside the polygon.

  \note            First and last vertex of the polygon have to be identical!

  \author          nassim.ibrouchene@continental-corporation.com

  \testmethod  
  \traceability    
*****************************************************************/
extern boolean CML_b_isPointInsidePolygon(const float32 a_Xarray[], const float32 a_Yarray[], uint32 u_size, float32 f_Xpoint, float32 f_Ypoint);

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
  \traceability    
*************************************************************************/
extern float32 CML_f_xPowY(const float32 f_Base, const float32 f_Exponent);

/*****************************************************************************
  Functionname:    CML_u_arrayMaxValueFloat                              *//*!

  \brief           Returns the index for an array; Array elements of float type.
  
  \description     The function finds and returns the index of maximum element in the array.
                  Linear search will be performing comparision of each element with the assumed maximum
                  and at end of complete traversal maximum element shall be identified.
  
  \param[in]       f_array :            The input array,
                                       Supported range [Full range of float32]
  \param[in]       u_MaxSize :          size of the input array.
                                       Supported range [Full range of sint32]
  \Note            Findig the maximum element might consume lot of time for unsorted array, 
                  as linear search method implemented.
  
  \return          index of the input array
  
  \pre             -
  \post            -
  
  \author          Jeevan Kotre
  \testmethod  
  \traceability    
******************************************************************************/
extern uint32 CML_u_arrayMaxValueFloat(const float32 f_array[],const uint32 u_MaxSize);


#endif /* #ifndef _CML_MISC_INCLUDED */


/** @} end defgroup */
