/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_misc.h

  DESCRIPTION:               Provide miscellaneous mathematical tools (low pass filter, clothoid calculation, etc...)

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.74.1.2 $

  ---*/ /*---
  CHANGES:                   $Log: cml_misc.h  $
  CHANGES:                   Revision 1.74.1.2 2019/06/24 10:39:47CEST Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   QAF level 3 warnings have been fixed.
  CHANGES:                   Revision 1.74.1.1 2019/05/27 11:02:50CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.74 2018/09/25 08:50:12CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added CML_f_fastDiv69
  CHANGES:                   Revision 1.73 2018/09/19 05:55:09CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Code under CML_NO_RTE_DEPENDENCY has been added
  CHANGES:                   Revision 1.72 2018/09/17 14:33:25CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Made squareroot output zero when input argument is zero.
  CHANGES:                   Revision 1.71 2018/09/10 09:34:53CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Code under CML_NO_RTE_DEPENDENCY has been removed.
  CHANGES:                   Revision 1.70 2018/09/04 13:06:37CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Modified change log to avoid warning in ARS540-RDT
  CHANGES:                   Revision 1.69 2018/08/30 07:56:32CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Removed fastdiv
  CHANGES:                   Revision 1.68 2018/08/30 07:15:10CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added test method.
  CHANGES:                   Revision 1.67 2018/08/28 12:19:02CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Corrected input range of cml_f_hypot function
  CHANGES:                   Revision 1.66 2018/08/28 11:57:25CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Removed max & min from design
  CHANGES:                   Revision 1.65 2018/08/22 13:32:11CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated deisgn for inverse and square root functions
  CHANGES:                   Revision 1.64 2018/08/20 10:28:21CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Check-in misc module design
  CHANGES:                   Revision 1.63 2018/07/30 10:56:20CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   CML_NO_RTE_DEPENDENCY changes have been reverted back.
  CHANGES:                   Revision 1.61 2018/07/18 08:14:08CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Code under CML_NO_RTE_DEPENDENCY has been removed.
  CHANGES:                   Revision 1.60 2018/06/19 10:39:17CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Formatting done. Removed CML_f_sqrtApprox
  CHANGES:                   Revision 1.59 2018/06/19 07:15:57CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   updated as per review comments
  CHANGES:                   Revision 1.58 2018/06/18 10:51:05CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Updated CML_f_sqrt67 to CML_f_sqrt69. Updated CML_f_invSqrt67 to CML_f_invSqrt69.
  CHANGES:                   Revision 1.57 2018/03/08 06:33:57CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Log and power functions are moved to cml_exp.h
  CHANGES:                   Revision 1.56 2018/02/27 06:51:05CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed the spaces after \ ; The change was lost while updating to the legacy release.
  CHANGES:                   Revision 1.55 2018/02/26 08:51:53CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.54 2017/12/20 06:43:06CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Correction for the compilation warning
  CHANGES:                   Revision 1.53 2017/11/14 18:41:45CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.52 2017/08/04 06:04:16CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Aligned and merged changes from AL_CML_01.09.11_INT-1
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
INCLUDE PROTECTION
*****************************************************************************/

#ifndef CML_MISC_INCLUDED
#define CML_MISC_INCLUDED   ///< To avoid multiple inclusion of the file

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
#pragma message(__FILE__": Inclusion of cml_misc.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

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
#endif /* #ifdef PRQA_SIZE_T */

/* PRQA S 0388 6 */
/* Deactivate QAF warning 0388, Date: 2019-06-18; Reviewer: uid22555;  
   Reason: The warning says nesting level exceeds 15, but this can not be avoided here. 
   There is no risk in suppressing this warning as per our analysis. */
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
#define CML_f_IsNonZeroPositive(value) ((value) > CML_f_AlmostZero)							 ///< Check if a number is non zero for positive values.

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
/* PRQA S  3240, 3219, 3480 8 */
/* Deactivate QAF warning 3240, 3219, 3480, Date: 04.12.2014; Reviewer: S. Schwarzkopf;   
   Reason: Styleguide wants it like this and CML_INLINE is 
   defined compiler dependent for inlining without external linkage.
   Review-ID: 3942463  */
/*! Determine the sign of a float number.
0: Value almost 0 ||  1: Positive Value || -1: Negative Value */
CML_INLINE sint32 CML_f_sign(float32 f_Input)
{
    sint32 s_Ret;

/* PRQA S 4460 6 */
/* Deactivate QAF warning 4460, Date: 2019-06-18; Reviewer: uidk9586;   
   Reason: There is no risk here as there is no loss of data */   
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.Divident & Divisor should be such that f_quotient
                   should not exceed the range of sint32.
  \post            None        
  \globals         No global data used in this function.             
  \description     This function calculates modulus after division:
                   result = Value - Quotient * Modulo where Quotient = floor(Value/Modulo)
                   returns same values as CML_Rem if Value and Modulo have same signs. 
  \InOutCorrelation
                   @startuml
                   start
                    if (Modulo almost ZERO) then (YES)  
                         :Return ZERO;
                    else (NO)
                         :Quotient = Value / Modulo;
                         if (Quotient  >= ZERO) ) then (YES)
                             :Add 0.5 to Quotient and store in TEMP; 
                         else (NO)
                             :Subtract 0.5 from Quotient and store in TEMP; 
                         endif
                         :Type cast output to integer and then float;
                          If ((abs(Quotient)>= integer MAX) OR (TEMP - Quotient) is almost ZERO))  then (YES);
                              :Return ZERO;
                          else
                              :Compute Value - Floor(Quotient * Modulo) and Return;
                         endif
                   endif
                   stop
                   @enduml
                   1.The function returns zero if the given modulus is approximately
                   equivalent to zero, in order to avoid a division by zero operation
                   in the function.\n
                   2.For Value / Modulo > C_LONG_MAX, Result = 0 
  \param[in]       f_value  : Divident, Any floating point value in the range of float32. 
  \param[in]       f_modulo : Divisor, Any floating point value in the range of float32. 
  \return          Remainder of f_value / f_modulo, in the range of float32.
  \callsequence    Not applicable as CML is a library                
  \author          dan.oprisan@continental-corporation.com
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
extern float32 CML_f_mod(float32 f_value, float32 f_modulo);

/*****************************************************************************
  Functionname:    CML_f_rem                                                *//*!

  \brief           Calculates the remainder after division (similar to MATLAB)
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.Divident & Divisor should be such that Quotient 
                   should not exceed the range of sint32. Divident & Divisor
                   should be having same sign. 
  \post            None        
  \globals         No global data used in this function.	
  \callsequence    Not applicable as CML is a library
                  
  \description     This function calculates remainder after division: 
                   result = X - n*Y where n = fix(X/Y)
                   returns same values as CML_Mod if X and Y have same signs.

  \InOutCorrelation
                    @startuml
                    start
                     if ((DIVISOR < CML_f_ModuloEps) AND (DIVISOR > -CML_f_ModuloEps)) then (YES)  
                       :Return ZERO;
                     else (NO)
                       :Quotient = dividend / divisor;
                       if (abs(Quotient)>= integer MAX) then (YES)
                             :Return ZERO ;
                       else (NO)
                            :Type cast Quotient to integer and then float , Save in TMP;
                            :Compute dividend - (TMP * divisor) and Return;
                       endif
                    endif
                    stop
                   @enduml
                   1.The function returns zero if the divisor is approximately 
                   equivalent to zero in order to avoid a division by zero operation
                   in the function.\n
                   2.For dividend / divisor > C_LONG_MAX, Result = 0 

  \param[in]       f_dividend : Divident under the range of float32. 

  \param[in]       f_divisor  : Divisor under the range of float32.

  \return          remainder of f_dividend / f_divisor
                  
  \author          dan.oprisan@continental-corporation.com

  \testmethod      Module Testing 
  \traceability    
*****************************************************************************/
extern float32 CML_f_rem(float32 f_dividend, float32 f_divisor);

/*****************************************************************************
  Functionname     - CML_f_hypot                                            *//*!

  \brief           Computes the length of a vector without risking over-
                   or under-flow.
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. f_x & f_y are 0, result in -1.#IND000.
  \post            None        
  \globals         No global data used in this function.	        
  \description     This function Computes the length of a vector without risking over-
                   or under-flow. The function operates in the absolute value of inputs,
                   take the fraction of the inputs with minimum value over the maximum.
                   The square is taken then followed by addition to unity and a 
                   multiplication with the maximum which results in the length
                   of the vector or in other terms value of the hypotenuse of a right 
                   angled triangle where the other two sides are represented by the 
                   absolute values of the inputs.\n
                   Maximum relative error: 7.1053726e-008F\n
                   Behavior outside range: When both inputs are above MAX of float32/2,
                   there will be overflow and output will be 1.#INF000.\n
  \InOutCorrelation
                   Let x be the max of the absolute value of the two inputs to the funciton 
                   and y be the min of the two. Then,
                   \f[ l = \sqrt{(\frac{y}{x})^2 + 1} \times x \f] 
                   @startuml
                    start
                       :Take absolute of f_x & f_y;
                       :x = maximum of the above output values;
                       :y = minimum of the above output values;
                       :Use above formula to get length of the vector;
                    stop
                   @enduml
  \attention       The function does not take care of an invalid vector where
                   both inputs are equal to zero.
  \param[in]       f_x: A normalized real number within the range of float32/2
  \param[in]       f_y: A normalized real number within the range of float32/2
  \return          The length of the vector (f_x, f_y), in the range of float32       
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module testing
  \traceability    
*****************************************************************************/
extern float32 CML_f_hypot(float32 f_x, float32 f_y);

/*****************************************************************************
Functionname:      CML_s_countNrOfBitsSet                                *//*!

  \brief           Count the number of bits set in a 32 bit unsigned int
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.	
  \description     This function counts and returns the number of bits set
                   in a 32 bit unsigned integer.
                   The function uses various bit masks to verify the set bits.\n
                   Executes in constant runtime, 7 cycles amortized time on C6X.               
  \InOutCorrelation
                   \f[x_1 = val - ((val >> 1) \ \& \ B_1 \\
                   x_2 = (x_1 \ \& \ B_2) + ((x_1 >> 2) \  \& \ B_2) \\
                   n   = ((((x_2 + (x_2 >> 4)) \ \& \ B_3) \times B_4) >> 24) \f]
  
                  \f[ B_1 = (01010101010101010101010101010101)_{binary} \f]
                  \f[ B_2 = (00110011001100110011001100110011)_{binary} \f]
                  \f[ B_3 = (00001111000011110000111100001111)_{binary} \f]
                  \f[ B_4 = (00000001000000010000000100000001)_{binary} \f]
  \param[in]       u_PruefBits : 32-bit unsigned integer
                                 Supported values [Full range of uint32]  
  \return          The number of bits set
                   Range of output : Minimum value: 0, Maximum value: 32  
  \author          L. Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module testing
  \traceability    
*****************************************************************************/
extern sint32 CML_s_countNrOfBitsSet (uint32 u_PruefBits);


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

  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.	
  \description     This function calculates the remainder of x when divided by y.\n 
                   Works only for x & y having same sign.\n
                   If any one input <= 0, The function might give wrong output.\n
                   The division is avoided in the function by passing the reciprocal along with the divisor
                   when the divisor is a known constant or a multiple of Pi. 
  \InOutCorrelation
                   Let f the input, d be the divisor and r be the reciprocal of divisor, then
                   \f[ q = integer part of (f \times r) \\
                       mod = f - (q \times d) \f]
                   @startuml
                    start
                        :Quotient = Value * Reciprocal of the Divisor;  
                        :Take Integer part of the Quotient; 
                        :Type cast the Integer Quotient to float;
                        :Return ( Value - Float Quotient *  Divisor);
                    stop
                   @enduml
  \param[in]       f_Value:   Denominator
  \param[in]       f_Reciprocal_Divisor: 1/Divisor.
  \param[in]       f_Divisor: Divisor         
  \return          f_Value % f_Divisor
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing 
  \traceability    
*****************************************************************************/
/* PRQA S 3240 , 3480, 3219 6 */
/* Deactivate QAF warning 3240 , 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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

  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input x should be <= input y
  \post            None        
  \globals         No global data used in this function.	
  \description     This function gives an approximation of the length of a 
                   vector defined by the input values. The function computes
                   the result using predefined constants alpha and beta and 
                   saves the use of any complex operation for the computation.\n
                   Maximum relative error : 0.0396.\n
  \InOutCorrelation
                   Let x and y be the absolute values of the input entries.
                   Also assume that x <= y
                   \f[ l = (y \times \alpha) + (x \times \beta) \f]
                   alpha = 0.96043387 and beta = 0.39782473
                   @startuml
                    start
                        :Get absoulute value of f_x; 
                        :Get absoulute value of f_y; 
                        :Get Max value of abs_x & abs_y;
                        :Get Min value of abs_x & abs_y;
                        :Return [(alpha * Max + beta * Min)];
                    stop
                   @enduml
                   Passing input values outside the mentioned range will result
                   in wrong output.\n
  \param[in]       f_x: A real number.                   
  \param[in]       f_y: A real number.
                   Input range of f_x & f_y: Minimum value - MIN of Float32 
                   Maximum value - MAX of Float32\n
  \return          The length of the vector (f_x, f_y).
                   Ouput range: In the range of 32 bit floating point numbers.\n
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240 , 3480, 3219 6 */
/* Deactivate QAF warning 3240 , 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. Input x should be <= input y
  \post            None        
  \globals         No global data used in this function.	
  \description     This function gives an approximation of the length of a 
                   vector defined by the input values. The function computes
                   the result using predefined constants alpha and beta and 
                   saves the use of any complex operation for the computation.\n
                   The function process integer values.\n 
                   Max relative error :0.04.\n                  
  \InOutCorrelation
                   Let x and y be the absolute values of the input entries.
                   Also assume that x <= y.
                   \f[ l = (y \times \alpha) + (x \times \beta) \f]
                   alpha = 123/128 and beta = 51/128.	   
                   @startuml
                    start
                        :Get absoulute value of s_x;  
                        :Get absoulute value of s_y; 
                        :Get Max value of abs_x & abs_y;
                        :Get Min value of abs_x & abs_y;
                        :Return [(alpha * Max + beta * Min)];
                    stop
                   @enduml
                   Passing input values outside the mentioned range will result
                   in wrong output.\n
  \param[in]       s_x: An integer value. Input range is in between -2^24 & 2^24
  \param[in]       s_y: An integer value. Input range is in between -2^24 & 2^24                
  \return          The length of the vector (s_x, s_y).
                   Ouput range: In the range of 32 bit signed integers 
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3219, 3480 14 */
/* Deactivate QAF warning 3240, 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  Functionname     - CML_f_invSqrt14                                      *//*!

  \brief           Approximates the inverse square root of x
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.	
  \description     This function provides the approximation of inverse of
                   square root of a number. \n 
                   Maximum relative error : 0.035.\n 
                   The function make use of a pre-defined constant to 
                   manipulate the floating point value to get the 
                   square root approximation.
                   References: The method is described in Lomont(2003)\n
                   Switches: This function uses the switch CML_OPT_c66x 
                   to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                   computation available on c66x.\n
                   Purpose: Used as a core function for inverse square 
                   root, which can be used along with Newton-Rhapson method
                   to get a more precised square root/inverse square root.\n
                   This function is optimized for c66x\n
  \InOutCorrelation
                   Let s be the integer typecasted value of input and
                   M be the predefined constant which equals 0x5f375a86.
                   \f[ r = M - (\frac{s}{2}) \f]
                   'r' can now be typecasted back to floating point to 
                   get the inverse square root of the input.
                   @startuml
                    start
                     if (CML_OPT_c66x) then (YES)  
                         :Use _rsqrsp to get inverse 
                         square root;
                     else (NO)
                         :Use the formula explained above 
                         to get inverse square root;
                     endif
                    stop
                   @enduml
                   Behavior outside range: When CML_OPT_c66x is enabled, 
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A rough approximation of x^(-1/2).
                   Output will be in the range of Float32 for any valid input.
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module testing
  \traceability    
*****************************************************************************/
/* PRQA S  3240 , 3242, 3480, 3219 10 */
/* Deactivate QAF warning 3240 , 3242, 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.	
  \description     This function provides the approximation of inverse of
                   square root of a number. \n 
                   Maximum relative error: 4.8e-6F\n 
                   The function make use of a pre-defined constant to 
                   manipulate the floating point value to get the 
                   square root approximation.\n
                   References: The method is described in Lomont(2003)\n
                   Switches:  This function uses the switch CML_OPT_c66x 
                   to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                   computation available on c66x.\n
                   This function is optimized for c66x\n
  \InOutCorrelation
                   Let y[n] be the inverse square root obtained using 
                   CML_InvSqrt14.\n Also, M be the predefined constant which
                   equals 1.5. \n Newton-Rhapson method explained in the below
                   formula is used to get improved accuracy over the result. 
                   \f[ y[n+1] =  y[n] \times (M - (x/2 \times y[n]^2)) \f]
                   2 iterations are implemented here to get inverse square root 
                   with 5.3 decimals relative accuracy.\n
                   @startuml
                    start
                     if (CML_OPT_c66x) then (YES)  
                         :Use _rsqrsp to get inverse square root;
                         :Use the formula explained above to get improved result
                          for next iteration, n = 1;
                     else (NO)
                         :Call CML_f_invSqrt14 to get first approiximation at n = 0;
                         :Use the formula explained above to get improved result
                          for two iterations, n = 1 & n= 2;
                     endif
                    stop
                   @enduml
                   Behavior outside range: When CML_OPT_c66x is enabled, 
                   passing zero as will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A highly accurate approximation of x^(-1/2)
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240, 3242, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  Functionname     CML_f_invSqrt69                                        *//*!

  \brief           Approximates the inverse square root of x with 6.9 decimals 
                   relative accuracy.
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     The function make use of a predefined 
                   constant to manipulate the floating point value to get the 
                   square root approximation.\n This in turn calls CML_InvSqrt14
                   for the initial approximation and does 3 iterations of the
                   correction computation using Newton-Rhapson method to 
                   improve the accuracy of the result.\n   
                   Accuracy: 6.9 decimals relative accuracy.\n
                   Max Relative error: Maximum relative error with standard 
                   C library for the range specified is 1.11567e-007F.\n
                   References :The method is a modified version of the one 
                   described in Lomont(2003).\n
                   Switches: This function uses the switch CML_OPT_c66x to 
                   make use of the intrinsic _rsqrsp for 1/x computation 
                   available on c66x.\n
                   Purpose: To provide a fast & precise inverse square root.
  \InOutCorrelation
                   @startuml
                   start
                   if (CML_OPT_c66x) then (yes)
                     :Use intrinsic _rsqrsp(Input) to get approximate
                     value of inverse square root x[0]	 
                     :Iteration 1: x[1] = x[0]*(1.5-Input/2*x[0]*x[0]);
                     :Iteration 2: x[2] = x[1]*(1.5-Input/2*x[1]*x[1]);
                     :Ouput = x[1] + x[2];
                   else (No)
                     :Call the function CML_f_invSqrt14(f_x) to get 
                     approximate value of inverse square root;
                     :Iteration 1: x[1] = x[0]*(1.5-Input/2*x[0]*x[0]);
                     :Iteration 2: x[2] = x[1]*(1.5-Input/2*x[1]*x[1]);
                     :Iteration 3: x[3] = x[2]*(1.5-Input/2*x[2]*x[2]);
                     :Ouput = x[2] + x[3];
                   endif
                   :return (Ouput);
                   stop
                   @enduml
                   Impact on timing behavior : This function is optimized for
                   c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled,
                   passing input argument zero, will give output zero.\n	
  \param[in]       f_x: A positive real number.
                   Valid range of f_x : MIN_INPUT <= f_x <= MAX_INPUT 
                   MAX_INPUT = maximum value of float32
                   MIN_INPUT = smallest positive value of float32

  \return          A precise calculation of x^(-1/2)             
  \callsequence    Not applicable as CML is a library 
  \author          Lars Ulveland, Jyothy Thomas
  \test method     Module testing
  \traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-9601-0003c62b  
 *****************************************************************************/
/* PRQA S  3240 , 3242, 3480, 3219 10 */
/* DeactivateDeactivate QAF warning 3240,3242,3219,3480, Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
/* PRQA S 3341 15 */
/* Deactivate QAC warning 3341; Date: 17.09.2018; 
   Reason: Floating point comparison with zero is needed for forcing squareroot
   to be zero when zero is the input argument */
CML_INLINE float32 CML_f_invSqrt69(float32 f_x);
CML_INLINE float32 CML_f_invSqrt69(float32 f_x)
{ 
#ifdef CML_OPT_c66x
    float32 f_Temp;
    float32 f_NewEst, f_NewerEst;
    float32 f_InitialSquared;
  
    float32 f_x2 = f_x * 0.5F;
    float32 f_Initial = _rsqrsp(f_x);
    /* Below line is added to make output zero when input argument is zero*/
    f_Initial = (f_x == 0.0F) ? 0.0F : f_Initial;

    f_InitialSquared = f_Initial * f_Initial;
    f_Temp  = f_x2 * f_InitialSquared;
    f_Temp    = 1.5F - f_Temp;
    f_NewEst  = f_Initial * f_Temp;

    f_Temp    = f_x2 * f_NewEst ;
    f_Temp    = f_Temp * f_NewEst;
    f_Temp    = 0.5F - f_Temp;
    f_Temp   = f_NewEst * f_Temp;
    f_NewerEst= f_NewEst + f_Temp;
    
    return f_NewerEst;
#else
    const float32 f_MagicNumber = 1.5F;
    float32 f_iter1, f_iter2, f_iter3;
    float32 f_temp1, f_temp2, f_temp;
    float32 f_x2, f_y;

    f_x2 = f_x * 0.5F;
    f_y = CML_f_invSqrt14(f_x);

    f_temp = f_x2 * f_y; 
    f_temp1 = f_y * f_temp;
    f_temp2 = f_MagicNumber - f_temp1;
    f_iter1 = f_y * f_temp2;

    f_temp = f_x2 * f_iter1;
    f_temp1 = f_iter1 * f_temp;
    f_temp2 = f_MagicNumber - f_temp1;
    f_iter2 = f_iter1 * f_temp2;

    f_temp = f_x2 * f_iter2;
    f_temp1 = f_iter2 * f_temp;
    f_temp2 = 0.5F - f_temp1;
    f_iter3 = f_iter2 * f_temp2;

    f_y = f_iter2 + f_iter3;
    return f_y;
#endif

}

/*****************************************************************************
  Functionname     - CML_f_invSqrt27                                          *//*!

  \brief           Approximates the inverse square root of x with 
                   maximum error 0.2% 
  \pre             No input checks are made. The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.	
  \description     This function provides the approximation of inverse of
                   square root of a number.\n 
                   Maximum relative error: 0.02\n 
                   The function make use of a predefined constant to 
                   manipulate the floating point value to get the 
                   square root approximation. This in turn calls 
                   CML_InvSqrt14 for the initial approximation and does
                   the correction computation using Newton-Rhapson method 
                   to improve the accuracy.
                   References: The method is described in Lomont(2003)\n
                   Switches:  This function uses the switch CML_OPT_c66x 
                   to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                   computation available on c66x.\n
  \InOutCorrelation
                   Let x be the input and y be the inverse square root obtained 
                   from the function CML_InvSqrt14. Also, 
                   M be the predefined constant which equals 1.5. 
                   \f[ y =  y \times (M - (\frac{x \times y^2}{2})) \f]
                   @startuml
                    start
                     if (CML_OPT_c66x) then (YES)  
                         :Use _rsqrsp to get inverse 
                         square root;
                     else (NO)
                         :Use the formula explained above 
                         to get inverse square root;
                     endif
                    stop
                   @enduml
                   This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled, 
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A rough approximation of x^(-1/2)
                   Output will be in the range of Float32 for any valid input.
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
/* PRQA S  3240 , 3242, 3480, 3219 10 */
/* DeactivateDeactivate QAF warning 3240,3242,3219,3480,3480,  Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
                   References: The method is described in Lomont(2003)\n
                   Switches: This function uses the switch CML_OPT_c66x 
                   to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                   computation available on c66x.\n
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f].
                   Timing behavior: This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled, 
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          An approximation of of x^(1/2)
                   Output will be in the range of Float32 for any valid input.
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability      
*****************************************************************************/
/* PRQA S  3240 , 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240, 3242, 3219, 3480,  Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     The function make use of the CML_f_sqrt27 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
                   Relative accuracy: 2.7
                   Maximum relative error: 				   
                   References: The method is described in Lomont(2003)\n
                   Switches: This function uses the switch CML_OPT_c66x 
                   to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                   computation available on c66x.\n
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f].
                   Timing behavior: This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled, 
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A rough approximation of x^(1/2)
                   Output will be in the range of Float32 for any valid input.
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability   
*****************************************************************************/
/* PRQA S  3240 , 3242, 3480, 3219 10 */
/* DeactivateDeactivate QAF warning 3240,3242,3219,3480,3480,  Date: 2019-06-14; Reviewer: uidk9586;   
     Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
     dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     The function make use of the CML_InvSqrt53 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number.
                   Relative accuracy: 5.3
                   Maximum relative error:
                   References: The method is described in Lomont(2003)\n
                   Switches: This function uses the switch CML_OPT_c66x 
                   to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                   computation available on c66x.\n
  \InOutCorrelation
                   \f[ r = x \times \frac{1}{\sqrt{x}} \f].
                   Timing behavior: This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled, 
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A highly accurate approximation of x^(1/2)
                   Output Range: Range of Float32 for any valid input.
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability   
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* DeactivateDeactivate QAF warning 3240,3242,3219,3480, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
CML_INLINE float32 CML_f_sqrt53(float32 f_x);
CML_INLINE float32 CML_f_sqrt53(float32 f_x)
{
    float32 f_temp;
    f_temp = f_x * CML_f_invSqrt53(f_x);
    return f_temp;
}

/*****************************************************************************
  Functionname     CML_f_sqrt69                                             *//*!

  \brief           Approximates the square root of x with 6.9 decimals relative 
                   accuracy.
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     The function make use of the CML_InvSqrt69 function to
                   compute the inverse square root of the floating point number
                   and then multiply it with the number to get the required
                   square root of the number
                   Relative accuracy: 6.9
                   Maximum relative error: 1.156046e-007F.  
                   References: The method is described in Lomont(2003)\n
                   Switches: This function uses the switch CML_OPT_c66x 
                                              to make use of the intrinsic _rsqrsp for 1/(x^1/2) 
                                              computation available on c66x.\n
  \InOutCorrelation
                   \f[r = x \times \frac{1}{\sqrt{x}}\f].
                   Timing behavior : This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled,
                   passing input argument zero, will give output zero.\n

  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A precise calculation of x^(1/2)
                   Output will be in the range of Float32 for any valid input.
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability     
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* DeactivateDeactivate QAF warning 3240,3242,3219,3480, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
CML_INLINE float32 CML_f_sqrt69(float32 f_x);
CML_INLINE float32 CML_f_sqrt69(float32 f_x)
{
    float32 f_temp;
    f_temp = f_x * CML_f_invSqrt69(f_x);
    return f_temp;
}

/*****************************************************************************
  Functionname     - CML_f_fastestInv                                         *//*!

  \brief           Approximates inverse of x roughly
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     Wraps the fastest inverse(division) approximation for each platform.
                   The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then square it to get the required inverse of the number.
                   Maximum relative error: Generic version: Max Error 0.069, average 0.043.
                   Ti version: Max 0.0046, average 0.0015.
                   References: The method is described in Lomont(2003)
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{x}})^2 \f]
                   @startuml
                    start
                     if (CML_OPT_c66x) then (YES)  
                         :Use _rcpsp intrinsic to get inverse square root;
                     else (NO)
                         :Use the formula explained above to get the inverse;
                         :The sign of the output is then applied as same to the sign of the input;
                     endif
                    stop
                   @enduml 
                   Impact on timing behavior : This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled,
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A normalized real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          1 / x    
  \author          Lars Ulveland
  \callsequence    Not applicable as CML is a library
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3480, 3219 6 */
/* Deactivate QAF warning 3240, 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     Maximum relative Error : 0.0048
                   Average Error : 0.0023
                   The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then square it to get the inverse of the number. 
                   Now to improve the accuracy, a correction computation is done
                   using Newton-Rhapson method. 
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{|x|}})^2 \f]
                   \f[ r = r \times (2 - (|x| \times r)) \f].
                   The sign of the output is then applied as same to the sign of the 
                   input
                   @startuml
                    start
                     if (CML_OPT_c66x) then (YES)  
                         :Use _rcpsp intrinsic to get inverse root;
                     else (NO)
                         :Call CML_f_invSqrt14(|input|) to get rough approximation of inverse square root.
                         :Use the formula explained above to get the inverse;
                     endif 
                    stop
                   @enduml
                   Impact on timing behavior : This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled,
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A rough approximation of 1 / x
  \callsequence    Not applicable as CML is a library
  \author          Lars Ulveland
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240 , 3480, 3219 6 */
/* Deactivate QAF warning 3240 , 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
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
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.         
  \description     The function make use of the CML_InvSqrt27 function to
                   compute the inverse square root of the floating point number
                   and then square it  to get the inverse of the number. 
                   To improve the accuracy, a correction compuatation is done using Newton-Rhapson method.
                   Maximum relative error: 1.24e-5F, average 4.4e-6F. 
                   Maximum error for Ti version is 2.09e-5F, average 3.4e-6F.\n
                   References: The method is described in Lomont(2003) \n 
                   Switches: CML_OPT_c66x switch is used for making use of the intrinsic
                   _rcpsp when c66x is enabled.
  \InOutCorrelation
                   \f[ r = (\frac{1}{\sqrt{|x|}})^2 \f]
                   \f[ r = r \times (2 - (|x| \times r)) \f].
                   The sign of the output is then applied as same to the sign of the 
                   input
                   @startuml
                    start
                     if (CML_OPT_c66x) then (YES)  
                         :Use _rcpsp intrinsic to get inverse square root;
                     else (NO)
                         :Call CML_f_invSqrt27(|input|) to get rough approximation of inverse square root.
                         :Use the formula explained above to get the inverse;
                     endif
                    stop
                   @enduml
                   Impact on timing behavior : This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled,
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A positive real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A precise approximation of 1 / x
                   Output Range: Output will be in the range of Float32 for any valid input.
  \callsequence    Not applicable as CML is a library   
  \author          Lars Ulveland
  \testmethod      Module Testing
  \traceability      
*****************************************************************************/
/* PRQA S 3240 , 3480, 3219 6 */
/* Deactivate QAF warning 3240 , 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
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
  Functionname     - CML_f_fastInv69                                      *//*!

  \brief           Computes inverse of x
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.

  \description     The function make use of the CML_InvSqrt14 function to
                   compute the inverse square root of the floating point number
                   and then square it to get the inverse of the number. 
                   Now to improve the accuracy, a correction compuatation using 
                   Newton-Rhapson method is done.\n
                   Maximum relative error: 1.19e-7F, average 1.5e-8F.\n
                   References: The method is described in Lomont(2003) \n 
                   Switches: CML_OPT_c66x switch is used for making use of the intrinsic
                   _rcpsp when c66x is enabled.
  \InOutCorrelation
                  @startuml
                   start
                   if (CML_OPT_c66x) then (yes)
                     :Use intrinsic _rcpsp(Input) to get approximate value of inverse, x[0]	 
                     :Iteration 1: x[1] = x[0] * (2 - x * x[0]);
                     :Iteration 2: x[2] = x * x[0] * x[0];
                     :Ouput =  2 * x[1] - x[2];
                   else (No)
                     :ABS_X = Get absolute of input.
                     :Call the function CML_f_invSqrt14(ABS_X) to get 
                      approximate value of inverse square root x[0];

                     :Iteration 1: x[1] = x[0] *( 2 - (ABS_X  * x[0] * x[0]));
                     :Iteration 2: x[2] = x[1] *( 2 - (ABS_X  * x[1])) ;
                     :Iteration 3: x[3] = (2 * x[2]) - (ABS_X  * x[2] * x[2]);
                     if (input<0) then (YES)  
                         :Change sign of output;
                     else (NO)
                         :Use same sign for output;
                     endif
                   endif
                   :return (Ouput);
                   stop
                   @enduml
                   Impact on timing behavior : This function is optimized for c66x\n
                   Behavior outside range: When CML_OPT_c66x is enabled,
                   passing zero as input will result in 'NAN.\n
  \param[in]       f_x: A normalized real number.
                   input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value:smallest positive value of float32 
                   maximum value:maximum value of float32
  \return          A very precise approximation of 1 / x
                   Output Range: Output will be in the range of Float32 for any valid input.
  \callsequence    Not applicable as CML is a library   
  \author          Lars Ulveland
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240 , 3480, 3219 6 */
/* Deactivate QAF warning 3240 , 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
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
  Functionname     - CML_f_fastDiv69                                      *//*!

  \brief           Computes Division y/x with 6.9 decimals accuracy.
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid. f_y/f_x should not go beyond the range of 
                   float32.
  \post            None        
  \globals         No global data used in this function.

  \description     The function make use of the CML_InvSqrt14 function to compute 
                   division of a floating point number by another. 
                   CML_InvSqrt14 is used computes the inverse square root of the 
                   denominator and then it is squared to get the inverse of the 
                   number.To improve the accuracy, a correction computation using
                   Newton-Rhapson method is done and then multiplied with the 
                   numerator to get the final result.\n
                   Maximum relative error when CML_OPT_c66x is OFF: 1.164e-007F
                   Maximum relative error when CML_OPT_c66x is ON: 1.164e-007F
                   References: The method is described in Lomont(2003) \n 
                   Switches used: CML_OPT_c66x switch is used for making use of
                   the intrinsic _rcpsp when c66x is enabled.
  \InOutCorrelation
                  @startuml
                   start
                   if (CML_OPT_c66x) then (yes)
                     :Use intrinsic _rcpsp(f_x) to get approximate value of inverse, x[0]	 
                     :Iteration 1: x[1] = x[0] * (2 - x * x[0]);
                     :Iteration 2: x[2] = x * x[0] * x[0];
                     :Ouput =  f_y * (2 * x[1] - x[2]);
                   else (No)
                     :ABS_X = Get absolute of input.
                     :Call the function CML_f_invSqrt14(ABS_X) to get 
                      approximate value of inverse square root x[0];

                     :Iteration 1: x[1] = x[0] *( 2 - (ABS_X  * x[0] * x[0]));
                     :Iteration 2: x[2] = x[1] *( 2 - (ABS_X  * x[1])) ;
                     :Iteration 3: x[3] = f_y * [(2 * x[2]) - (ABS_X  * x[2] * x[2])];
                     if (input<0) then (YES)  
                         :Change sign of output;
                     else (NO)
                         :Use same sign for output;
                     endif
                   endif
                   :return (Ouput);
                   stop
                   @enduml
                   Impact on timing behavior : This function is optimized on c66x\n
                   Average cycle consumption on c66x when CML_OPT_c66x is OFF: 61 \n
                   Average cycle consumption on c66x when CML_OPT_c66x is ON : 38 \n 
  \param[in]       f_y & f_x: Normalized real numbers.
                   Input range : Minimum value <= f_x <= maximum value \n		 
                   Minimum value: -3.4e37F
                   Maximum value: 3.4e37F
  \return          A very precise approximation of f_y / f_x
                   Output Range: Output will be in the range of Float32 for any valid input.
  \callsequence    Not applicable as CML is a library   
  \author          Jyothy Thomas
  \testmethod      Module Testing
  \traceability    
*****************************************************************************/
/* PRQA S 3240 , 3480, 3219 6 */
/* Deactivate QAF warning 3240 , 3480, 3219, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
CML_INLINE float32 CML_f_fastDiv69(float32 f_y, float32 f_x)
{
#ifdef CML_OPT_c66x
    float32 f_NewEst, f_Result;
    float32 f_Initial = _rcpsp(f_x);

    float32 f_Tmp     = f_Initial * f_x;
    f_Tmp             = 2.0F - f_Tmp;
    f_NewEst          = f_Tmp * f_Initial;

    /* A reformulation of NR increases accuracy at the cost of a single multiplication */
    f_Tmp             = f_x * f_NewEst;
    f_Tmp             = f_Tmp * f_NewEst; 
    f_NewEst          = 2.0F * f_NewEst;
    f_Tmp             = f_NewEst - f_Tmp;

    f_Result = f_y * f_Tmp;
    return f_Result;
#else
    /* PRQA S 3341 9 */
    /* Deactivate QAC warning 3341; Date: 25.09.2018; 
    Reason: Floating point comparison with zero is needed for forcing f_AbsX 
    to be zero when negative zero is the input argument */
    float32 f_Tmp, f_Result;
    float32 f_Initial; 
    boolean b_NegaX;
    float32 f_AbsX ;
    f_Tmp = f_x < 0.0F ? -f_x : f_x;
    f_AbsX = (f_x == 0.0F) ? 0.0F : f_Tmp;
    b_NegaX = (f_x < 0.0F) ? b_TRUE : b_FALSE;
    
    f_Initial = CML_f_invSqrt14(f_AbsX);  /* Initial estimate of 1/sqrt(x) */
    f_Initial *= f_Initial;       /* Squaring it generated inital estimate of 1/x */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = 2.0F - f_Tmp;
    f_Initial = f_Initial * f_Tmp; /* Initial is now the initial for the next iteration */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = 2.0F - f_Tmp;
    f_Initial = f_Initial * f_Tmp; /* Initial is now the initial for the next iteration */

    f_Tmp = f_AbsX * f_Initial;
    f_Tmp = f_Tmp * f_Initial;     /* Last iteration is different to reduce the rounding error */
    f_Initial = f_Initial * 2.0F;
    f_Tmp = f_Initial - f_Tmp;

    f_Result = f_y * f_Tmp;
    return (b_NegaX == b_TRUE) ? -f_Result : f_Result;
#endif
}
/*****************************************************************************
  Functionname     - CML_f_sqrtVeryFast                                      *//*!

  \brief           Approximates the square root of x
  \pre             No input checks are made.The caller must guarantee that the 
                   input is valid.
  \post            None        
  \globals         No global data used in this function.
  \description     The function make use of a predefined constant 0x4C000 to 
                   evaluate the square root using some basic operations.
                   Maximum relative error: 0.035, average is 0.019
  \InOutCorrelation
                   Let Hx be the hexadecimal value of the input and S be the
                   predefined constant,
                   \f[ R = \frac{H_x - (1<<23)}{2} + (1<<29) - S  \f]
  \param[in]       f_x: A positive real number.
  \return          A rough approximation of x^(1/2)
                   Output Range: Output will be in the range of Float32 for any valid input.
  \callsequence    Not applicable as CML is a library   
  \author          Lars Ulveland
  \testmethod      Module Testing
  \traceability  
*****************************************************************************/
/* PRQA S 3240, 3242, 3219, 3480 6 */
/* Deactivate QAF warning 3240,3242,3219,3480, Date: 2019-06-14; Reviewer: uidk9586;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler 
   dependent, to have no external linkage. */
CML_INLINE float32 CML_f_sqrtVeryFast(float32 f_x);
CML_INLINE float32 CML_f_sqrtVeryFast(float32 f_x)
{
    const uint32 u_SqrtConst = 0x4C000;
    CML_t_FloatAsUnsigned u;
    uint32 u_HexRepresentation;
    u.f_d = f_x;
    u_HexRepresentation = u.u_x;
    /* PRQA S 0499  8 */
    /* Deactivate QAF warning 0499, Date: 2019-06-14; Reviewer: uidk9586; 
    Reason: There is no risk in violating this rule as the result is always a positive value */
    u_HexRepresentation -= 1U << 23U;
    u_HexRepresentation /= 2U;
    u_HexRepresentation += 1U << 29U;
    u.u_x = u_HexRepresentation - u_SqrtConst;
    return u.f_d;
}

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

  \testmethod      Module Testing  
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

  \testmethod      Module Testing  
  \traceability    
*****************************************************************/
extern boolean CML_b_isPointInsidePolygon(const float32 a_Xarray[], const float32 a_Yarray[], uint32 u_size, float32 f_Xpoint, float32 f_Ypoint);

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
  \testmethod      Module Testing  
  \traceability    
******************************************************************************/
extern uint32 CML_u_arrayMaxValueFloat(const float32 f_array[],const uint32 u_MaxSize);

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
boolean CML_b_isNAN( float32 f_inp);


#endif /* #ifndef CML_MISC_INCLUDED */


/** @} end defgroup */
