/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysiscolor.c

  DESCRIPTION:            Analysis based on color evaluation..

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-09-30

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_analysiscolor.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:41CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:54CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:14CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.70 2014/03/28 10:36:16CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed some QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:16 AM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.69 2014/03/26 11:27:35CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some mandatory QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:36 AM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.68 2014/03/25 19:11:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Separation of hla_segmentation.c
  CHANGES:                Removed QAC warnings
  CHANGES:                Replaces fABS by CML_f_abs
  CHANGES:                Introduced CML_s_Round2Int
  CHANGES:                --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:53 PM CET]
  CHANGES:                Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.67 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_analysiscolor.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysiscolor.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGES:                Revision 1.66 2014/03/19 16:31:31CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:32 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.65 2014/03/04 16:51:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:48 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.64 2014/02/11 12:34:44CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed analysis level 1 color internal time meas
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 12:34:44 PM CET]
  CHANGES:                Change Package : 207432:18 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.63 2014/02/07 09:49:55CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed critical QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2014 9:49:56 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.62 2014/02/06 16:01:36CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:37 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.61 2014/01/28 10:48:08CET Schillinger, Patrick (uidv8776) 
  CHANGES:                -renaming of some unclear variables
  CHANGES:                -changes to meet coding guideline
  CHANGES:                --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:08 AM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.60 2014/01/17 13:46:29CET Schillinger, Patrick (uidv8776) 
  CHANGES:                rename pT and pTLB to pTrack
  CHANGES:                --- Added comments ---  uidv8776 [Jan 17, 2014 1:46:29 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.59 2014/01/16 14:29:16CET Schillinger, Patrick (uidv8776) 
  CHANGES:                remove defines:
  CHANGES:                HLA_COLOR_USE_OPTIMIZED_CODE 
  CHANGES:                HLA_HEADLIGHTTYPE_HALOGE
  CHANGES:                HLA_HEADLIGHTTYPE_XENON_LED
  CHANGES:                --- Added comments ---  uidv8776 [Jan 16, 2014 2:29:16 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.58 2014/01/10 18:33:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:59 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.57 2013/12/13 16:45:04CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:04 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.56 2013/11/21 17:53:40CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:40 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.55.1.3 2013/10/31 17:44:19CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed compiler warning
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:44:20 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.55.1.2 2013/10/25 15:16:15CEST Brunn, Marcus (brunnm) 
  CHANGES:                used UI8_T_MAX instead of magic 255
  CHANGES:                --- Added comments ---  brunnm [Oct 25, 2013 3:16:15 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.55.1.1 2013/10/18 13:27:31CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:31 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.55 2013/03/08 10:30:51CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:52 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.54 2012/10/18 17:55:33CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGES:                --- Added comments ---  uidt9253 [Oct 18, 2012 5:55:35 PM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.53 2012/10/10 13:02:53CEST Brunn, Marcus (brunnm) 
  CHANGES:                RAM optimization (Part2)
  CHANGES:                --- Added comments ---  brunnm [Oct 10, 2012 1:02:53 PM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.52 2012/10/08 10:10:01CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - update of the halogen otherColor classifier (some traffic ahead was detected as otherColor instead of red)
  CHANGES:                --- Added comments ---  uidt9253 [Oct 8, 2012 10:10:01 AM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.51 2012/10/05 12:41:34CEST Brunn, Marcus (brunnm) 
  CHANGES:                RAM optimization (part1)
  CHANGES:                --- Added comments ---  brunnm [Oct 5, 2012 12:41:34 PM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.50 2012/09/18 20:08:50CEST Brunn, Marcus (brunnm) 
  CHANGES:                used "__GOLDDUST__" define instead of PC_SIM
  CHANGES:                --- Added comments ---  brunnm [Sep 18, 2012 8:08:53 PM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.49 2012/06/04 12:53:24CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - correct pragma statements to make it compile on golddust again
  CHANGES:                --- Added comments ---  uidt9253 [Jun 4, 2012 12:53:25 PM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.48 2012/06/01 14:09:40CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - if halogen head lamps are available a special trained halogen color classifier is used (no changes for Xenon or Led head lamps)
  CHANGES:                --- Added comments ---  uidt9253 [Jun 1, 2012 2:09:40 PM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.47 2012/05/04 06:47:24CEST Brunn, Marcus (brunnm) 
  CHANGES:                - removed dead code
  CHANGES:                - removed dead ini-file entries
  CHANGES:                --- Added comments ---  brunnm [May 4, 2012 6:47:26 AM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.46 2012/04/20 16:52:42CEST Mueller, Reik (muellerr5) 
  CHANGES:                - updated isOtherColor classifier
  CHANGES:                    - removed false positive streetlamps from training set
  CHANGES:                    - added new traffic oncoming samples to training set
  CHANGES:                --- Added comments ---  muellerr5 [Apr 20, 2012 4:52:43 PM CEST]
  CHANGES:                Change Package : 54245:1 http://mks-psad:7002/im/viewissue?selection=54245
  CHANGES:                Revision 1.45 2012/04/16 17:05:34CEST Mueller, Reik (muellerr5) 
  CHANGES:                - always call HLAAnalysisColorWhiteOrRed(), independent of result from "OtherColor" classifier
  CHANGES:                --- Added comments ---  muellerr5 [Apr 16, 2012 5:05:34 PM CEST]
  CHANGES:                Change Package : 54245:1 http://mks-psad:7002/im/viewissue?selection=54245
  CHANGES:                Revision 1.44 2012/03/29 15:14:03CEST Mueller, Reik (muellerr5) 
  CHANGES:                - added comments from code review findings
  CHANGES:                --- Added comments ---  muellerr5 [Mar 29, 2012 3:14:03 PM CEST]
  CHANGES:                Change Package : 94915:1 http://mks-psad:7002/im/viewissue?selection=94915
  CHANGES:                Revision 1.43 2012/03/08 18:25:14CET Mueller, Reik (muellerr5) 
  CHANGES:                - optimized HLAAnalysisColorOther() with new table structure (no re-train)
  CHANGES:                - added special version HLAAnalysisColorOther_MPCIntrinsic() using SPE intrinsics from Golddust ECU
  CHANGES:                - added Bit-Exactness-Test to compare results of intrinsic and non-intrinsic versions
  CHANGES:                --- Added comments ---  muellerr5 [Mar 8, 2012 6:25:15 PM CET]
  CHANGES:                Change Package : 54245:1 http://mks-psad:7002/im/viewissue?selection=54245
  CHANGES:                Revision 1.42 2012/02/21 15:11:01CET Mueller, Reik (muellerr5) 
  CHANGES:                - removed check for saturated pixels in HLAAnalysisColorWhiteOrRed()
  CHANGES:                --- Added comments ---  muellerr5 [Feb 21, 2012 3:11:02 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.41 2012/02/20 16:46:41CET Mueller, Reik (muellerr5) 
  CHANGES:                - updated color classifiers:
  CHANGES:                    - runtime optimization (simple adaBoost, simple "radius" feature)
  CHANGES:                    - restructured classifier parameter tables
  CHANGES:                    - retrain due to new "radius" feature
  CHANGES:                --- Added comments ---  muellerr5 [Feb 20, 2012 4:46:41 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.40 2012/02/01 15:08:19CET Mueller, Reik (muellerr5) 
  CHANGES:                - removed max confidence check in HLAIdentificationColorWhiteOrRed()
  CHANGES:                --- Added comments ---  muellerr5 [Feb 1, 2012 3:08:21 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.39 2012/02/01 09:55:58CET Brunn, Marcus (brunnm) 
  CHANGES:                - RAM opt. -> lux values now in 16 Bit integer
  CHANGES:                --- Added comments ---  brunnm [Feb 1, 2012 9:55:59 AM CET]
  CHANGES:                Change Package : 94876:1 http://mks-psad:7002/im/viewissue?selection=94876
  CHANGES:                Revision 1.38 2012/01/25 21:59:30CET Brunn, Marcus (brunnm) 
  CHANGES:                added time measurement for color analysis
  CHANGES:                --- Added comments ---  brunnm [Jan 25, 2012 9:59:31 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.37 2012/01/19 17:46:17CET Mueller, Reik (muellerr5) 
  CHANGES:                - updated color classifiers 
  CHANGES:                    - use only training samples from MFC300 cameras
  CHANGES:                --- Added comments ---  muellerr5 [Jan 19, 2012 5:46:18 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.36 2011/11/22 15:17:15CET Godreau, Bertrand (uid28828) 
  CHANGES:                -> reintroduce hamming distance penalty
  CHANGES:                -> prevent use of hamming distance when maxima is saturated
  CHANGES:                -> move saturation test from hla_analysiscolor to hla_tracking_3d
  CHANGES:                -> remove posFromRegion
  CHANGES:                --- Added comments ---  uid28828 [Nov 22, 2011 3:17:15 PM CET]
  CHANGES:                Change Package : 54276:1 http://mks-psad:7002/im/viewissue?selection=54276
  CHANGES:                Revision 1.35 2011/11/16 17:22:17CET Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - removed unused classifier parameters
  CHANGES:                --- Added comments ---  muellerr5 [Nov 16, 2011 5:22:17 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.34 2011/11/11 17:17:10CET Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated color classifiers isOtherColor & isWhiteOrRed
  CHANGES:                    - added samples for oncoming vehicles in rain/fog scenarios
  CHANGES:                    - added samples for orange street lights
  CHANGES:                --- Added comments ---  muellerr5 [Nov 11, 2011 5:17:11 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.33 2011/10/12 16:08:37CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated color classifier for isOtherColor:
  CHANGES:                    - added samples for partly occluded oncoming vehicles
  CHANGES:                    - added samples for oncoming vehicles in rain
  CHANGES:                --- Added comments ---  muellerr5 [Oct 12, 2011 4:08:40 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.32 2011/10/07 18:00:10CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - bugfix: anaResStat and idResStat mixed up
  CHANGES:                --- Added comments ---  uidt9253 [Oct 7, 2011 6:00:10 PM CEST]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.31 2011/09/27 13:39:40CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                separation of HLAR/ HLAF
  CHANGES:                --- Added comments ---  brunnm [Sep 27, 2011 1:39:40 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.30 2011/09/07 18:06:44CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - removed a lot of unused stuff from blackboard
  CHANGES:                --- Added comments ---  uidt9253 [Sep 7, 2011 6:06:44 PM CEST]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.29 2011/09/02 15:53:16CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated color analysis
  CHANGES:                --- Added comments ---  muellerr5 [Sep 2, 2011 3:53:16 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.28 2011/07/19 18:48:58CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - calculate input vector for AdaBoost color classifiers just once per track
  CHANGES:                --- Added comments ---  muellerr5 [Jul 19, 2011 6:48:58 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.27 2011/07/18 16:59:50CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - got rid of another MISRA / PC Lint warning
  CHANGES:                --- Added comments ---  muellerr5 [Jul 18, 2011 4:59:51 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.26 2011/07/18 16:24:51CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - removed even more MISRA / PC Lint warnings
  CHANGES:                --- Added comments ---  muellerr5 [Jul 18, 2011 4:24:51 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.25 2011/07/18 14:07:41CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated HLAAnalysisColorNonWhite() : don't run calssifier if max confidence is already reached
  CHANGES:                - removed MISRA / PC Lint warnings
  CHANGES:                --- Added comments ---  muellerr5 [Jul 18, 2011 2:07:41 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.24 2011/07/18 13:15:57CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated AdaBoost classifier for HLAAnalysisColorNonWhite()
  CHANGES:                --- Added comments ---  muellerr5 [Jul 18, 2011 1:15:57 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.23 2011/07/16 18:33:34CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated HLAAnalysisColorNonWhite() : use AdaBoost classifier on 13 pixels
  CHANGES:                --- Added comments ---  muellerr5 [Jul 16, 2011 6:33:35 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.22 2011/07/11 17:07:58CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated HLARedLightAnalysis: set maximum lux input value to 15 bit
  CHANGES:                - removed MISRA / PC Lint warnings
  CHANGES:                --- Added comments ---  muellerr5 [Jul 11, 2011 5:07:59 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.21 2011/07/11 14:54:41CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - bugfix division by zero: for lux level 65535 the +1 increment sets the uint16 to 0
  CHANGES:                --- Added comments ---  uidt9253 [Jul 11, 2011 2:54:41 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.20 2011/06/30 08:24:57CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                HLAAnalysisColorNonWhite():
  CHANGES:                removed magic saturation value (3999)
  CHANGES:                -> used get function fom hla imager module (HLAImager_GetSaturation_... )
  CHANGES:                --- Added comments ---  brunnm [Jun 30, 2011 8:24:57 AM CEST]
  CHANGES:                Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.19 2011/06/29 14:09:55CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - HLAAnalysisColorNonWhite(): calculation of saturation based on all 5 red neighbour pixels instead of just the center one. Fixes problems with bright and pointy lights
  CHANGES:                --- Added comments ---  uidt9253 [Jun 29, 2011 2:09:55 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.18 2011/06/28 15:21:11CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - keep pulsed light confidence counter on same level when the led light switches between led and red
  CHANGES:                --- Added comments ---  uidt9253 [Jun 28, 2011 3:21:12 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.17 2011/06/20 14:49:36CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                added RedLightParameters
  CHANGES:                --- Added comments ---  brunnm [Jun 20, 2011 2:49:36 PM CEST]
  CHANGES:                Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.16 2011/05/24 23:26:52CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Deleted MISRA errors
  CHANGES:                --- Added comments ---  almeidac [May 24, 2011 11:26:53 PM CEST]
  CHANGES:                Change Package : 54255:1 http://mks-psad:7002/im/viewissue?selection=54255
  CHANGES:                Revision 1.15 2011/05/24 22:27:31CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Remove uneccessary returns
  CHANGES:                --- Added comments ---  almeidac [May 24, 2011 10:27:31 PM CEST]
  CHANGES:                Change Package : 54255:1 http://mks-psad:7002/im/viewissue?selection=54255
  CHANGES:                Revision 1.14 2011/05/23 19:48:35CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Adapted new identification model on all classifiers
  CHANGES:                --- Added comments ---  almeidac [May 23, 2011 7:48:35 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.13 2011/05/23 14:01:59CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                - renamed seg_TracklistNode into HLATrack_t
  CHANGES:                - renamed seg_ListNode into HLASegLight_t
  CHANGES:                --- Added comments ---  brunnm [May 23, 2011 2:01:59 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.12 2011/05/21 19:12:53CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Added new result status concept
  CHANGES:                --- Added comments ---  almeidac [May 21, 2011 7:12:53 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.11 2011/04/14 19:01:12CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGES:                3D tracking clean-up.
  CHANGES:                Remove use of global variables.
  CHANGES:                Set-up of an input/output/data archi
  CHANGES:                --- Added comments ---  uid28828 [Apr 14, 2011 7:01:13 PM CEST]
  CHANGES:                Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGES:                Revision 1.10 2011/02/25 12:39:22CET Reik Mueller (muellerr5) 
  CHANGES:                - moved HLAIdentificationColorNonWhite() from hla_analysis.c
  CHANGES:                --- Added comments ---  muellerr5 [Feb 25, 2011 12:39:23 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.9 2011/02/22 11:01:08CET Marcus Brunn (brunnm) 
  CHANGES:                improvement for HLAAnalysisColorRedLight() (hla target rec files)
  CHANGES:                --- Added comments ---  brunnm [Feb 22, 2011 11:01:09 AM CET]
  CHANGES:                Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGES:                Revision 1.8 2011/02/22 09:37:24CET Marcus Brunn (brunnm) 
  CHANGES:                HLA_RED_ANALYSIS_MIN_LUX = 25 (former 30 lux)
  CHANGES:                --- Added comments ---  brunnm [Feb 22, 2011 9:37:24 AM CET]
  CHANGES:                Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGES:                Revision 1.7 2011/02/18 13:54:10CET Reik Mueller (muellerr5) 
  CHANGES:                - updated HLAAnalysisColorNonWhite()
  CHANGES:                --- Added comments ---  muellerr5 [Feb 18, 2011 1:54:10 PM CET]
  CHANGES:                Change Package : 53528:1 http://mks-psad:7002/im/viewissue?selection=53528
  CHANGES:                Revision 1.6 2011/02/14 16:36:08CET Reik Mueller (muellerr5) 
  CHANGES:                - added HLAAnalysisColorNonWhite()
  CHANGES:                --- Added comments ---  muellerr5 [Feb 14, 2011 4:36:09 PM CET]
  CHANGES:                Change Package : 53528:1 http://mks-psad:7002/im/viewissue?selection=53528
  CHANGES:                Revision 1.5 2010/12/02 13:33:34CET Marcus Brunn (brunnm) 
  CHANGES:                imager:
  CHANGES:                - added function to read T1 saturation region
  CHANGES:                segmentation:
  CHANGES:                - clustering: increased number of regions from 64 to 128
  CHANGES:                - binarize row: implemented special feature for T1 saturation (dInt always 0)
  CHANGES:                --- Added comments ---  brunnm [Dec 2, 2010 1:33:35 PM CET]
  CHANGES:                Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGES:                Revision 1.4 2010/11/02 15:59:16CET Marcus Brunn (brunnm) 
  CHANGES:                removed 12Bit ngbs from maxima list to save RAM
  CHANGES:                Revision 1.3 2010/10/20 17:22:24CEST Reik Mueller (x-muellerr5) 
  CHANGES:                - updated red light classificator
  CHANGES:                --- Added comments ---  x-muellerr5 [Oct 20, 2010 5:22:25 PM CEST]
  CHANGES:                Change Package : 38439:1 http://mks-psad:7002/im/viewissue?selection=38439
  CHANGES:                Revision 1.2 2010/10/16 09:05:16CEST Marcus Brunn (brunnm) 
  CHANGES:                enabpulsed HLAAnalysisColorRedLight()
  CHANGES:                --- Added comments ---  brunnm [Oct 16, 2010 9:05:16 AM CEST]
  CHANGES:                Change Package : 38437:4 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGES:                Revision 1.1 2010/10/14 14:38:05CEST Marcus Brunn (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                Revision 1.4 2010/10/13 17:52:11CEST Reik Mueller (x-muellerr5) 
  CHANGES:                - added new redlight-counter/-status/-turnoff reason for new redlight classification
  CHANGES:                - updated new redlight classification (retrained CSF data with lux input)
  CHANGES:                --- Added comments ---  x-muellerr5 [Oct 13, 2010 5:52:11 PM CEST]
  CHANGES:                Change Package : 38439:1 http://mks-psad:7002/im/viewissue?selection=38439
  CHANGES:                Revision 1.3 2010/10/12 14:26:05CEST Reik Mueller (x-muellerr5) 
  CHANGES:                - added red light classificator (trained with CSF data)
  CHANGES:                --- Added comments ---  x-muellerr5 [Oct 12, 2010 2:26:05 PM CEST]
  CHANGES:                Change Package : 38439:1 http://mks-psad:7002/im/viewissue?selection=38439
  CHANGES:                Revision 1.2 2010/10/04 11:53:55CEST Marcus Brunn (brunnm) 
  CHANGES:                updated color analysis to new frame work concept
  CHANGES:                --- Added comments ---  brunnm [Oct 4, 2010 11:53:55 AM CEST]
  CHANGES:                Change Package : 38437:1 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGES:                Revision 1.1 2010/10/01 22:15:19CEST Carlos Almeida (almeidac) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hla_analysiscolor.h"
#include "hla_imager.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_NUM_COLOR_FEATURES 41

#define HLA_OTHERCOLOR_TABLE_SIZE_XENONLED 504
#define HLA_OTHERCOLOR_ALPHASUM_XENONLED   (-12892)
#define HLA_OTHERCOLOR_TABLE_SIZE_HALOGEN 476
#define HLA_OTHERCOLOR_ALPHASUM_HALOGEN   (-31979)

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  uint8 idx;
  uint16 b;
  sint32 alpha;
} simple_adaboost_rule_t;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
static ARRAY(uint16, HLA_NUM_COLOR_FEATURES, adaInputVector);

/* ~CodeReview ~ID:28c7400392bc39278e0e6be01886d4cf ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:magic number */
static const ARRAY(simple_adaboost_rule_t, 26, WhiteRed_Ada2) = {
  {31, 21, 46782},
  {23, 33, -26831},
  {36, 26, 28552},
  {18, 130, 20449},
  { 3, 121, 18119},
  {15, 27, -16338},
  {38, 58, 13457},
  {15, 52, -11572},
  {33, 55, 10452},
  { 6, 29176, -11039},
  {22, 87, -10682},
  {26, 107, 12034},
  {31, 21, -8976},
  { 1, 221, 10006},
  {18, 80, 9939},
  {20, 114, -9295},
  { 6, 126, -9669},
  {28, 163, -10349},
  {36, 17, 8614},
  {26, 235, 10542},
  {13, 29, 7580},
  { 8, 3594, -6696},
  {33, 78, 8795},
  { 8, 49, 9834},
  {18, 73, 7391},
  {34, 60, 7339}
};

  
static const ARRAY(uint16, HLA_NUM_COLOR_FEATURES+1, adaInputVectorIndexTab_XenonLED) = {
  0,
  12,
  24,
  36,
  60,
  76,
  88,
  100,
  112,
  124,
  136,
  144,
  164,
  172,
  180,
  192,
  208,
  212,
  220,
  232,
  240,
  252,
  260,
  272,
  284,
  292,
  304,
  316,
  332,
  340,
  348,
  360,
  380,
  392,
  404,
  416,
  428,
  440,
  448,
  460,
  476,
  504
};

static const ARRAY(uint16, HLA_OTHERCOLOR_TABLE_SIZE_XENONLED, u16OtherColor_Ada2_b_XenonLED) = {
  0,
  87,
  92,
  182,
  317,
  2850,
  3821,
  10124,
  17920,
  18535,
  32767,
  32767,
  0,
  211,
  217,
  231,
  236,
  252,
  257,
  260,
  18851,
  24036,
  32767,
  32767,
  0,
  19,
  22,
  27,
  34,
  154,
  327,
  381,
  32767,
  32767,
  32767,
  32767,
  0,
  32,
  106,
  163,
  210,
  211,
  235,
  236,
  255,
  260,
  261,
  272,
  651,
  1061,
  1097,
  2036,
  2237,
  4053,
  13257,
  23045,
  32767,
  32767,
  32767,
  32767,
  0,
  13,
  22,
  27,
  31,
  34,
  86,
  87,
  92,
  123,
  420,
  695,
  1023,
  32767,
  32767,
  32767,
  0,
  112,
  120,
  510,
  915,
  1031,
  1177,
  2523,
  32562,
  32767,
  32767,
  32767,
  0,
  125,
  143,
  144,
  212,
  249,
  704,
  2846,
  5381,
  8102,
  32767,
  32767,
  0,
  47,
  59,
  61,
  117,
  177,
  353,
  3821,
  7568,
  7682,
  32767,
  32767,
  0,
  22,
  53,
  83,
  85,
  93,
  94,
  467,
  596,
  1663,
  32767,
  32767,
  0,
  45,
  67,
  226,
  236,
  255,
  260,
  630,
  1871,
  5010,
  32767,
  32767,
  0,
  89,
  142,
  144,
  301,
  9508,
  32613,
  32767,
  0,
  44,
  45,
  178,
  199,
  217,
  246,
  267,
  303,
  496,
  592,
  2041,
  10482,
  12210,
  12282,
  15216,
  17615,
  32767,
  32767,
  32767,
  0,
  81,
  102,
  1351,
  32767,
  32767,
  32767,
  32767,
  0,
  10,
  11,
  22,
  27,
  32767,
  32767,
  32767,
  0,
  28,
  118,
  263,
  308,
  373,
  386,
  410,
  512,
  32767,
  32767,
  32767,
  0,
  8,
  9,
  10,
  11,
  12,
  17,
  19,
  20,
  50,
  56,
  63,
  71,
  32767,
  32767,
  32767,
  0,
  30,
  47,
  32767,
  0,
  89,
  95,
  101,
  139,
  150,
  293,
  32767,
  0,
  35,
  46,
  56,
  72,
  156,
  178,
  255,
  365,
  32767,
  32767,
  32767,
  0,
  19,
  37,
  38,
  51,
  76,
  32767,
  32767,
  0,
  42,
  65,
  82,
  111,
  181,
  270,
  512,
  545,
  32767,
  32767,
  32767,
  0,
  19,
  37,
  50,
  32767,
  32767,
  32767,
  32767,
  0,
  105,
  128,
  143,
  245,
  284,
  314,
  405,
  32767,
  32767,
  32767,
  32767,
  0,
  5,
  6,
  7,
  9,
  11,
  12,
  14,
  20,
  35,
  43,
  32767,
  0,
  5,
  9,
  43,
  72,
  77,
  32767,
  32767,
  0,
  25,
  57,
  68,
  69,
  100,
  100,
  101,
  153,
  32767,
  32767,
  32767,
  0,
  116,
  187,
  199,
  234,
  238,
  266,
  295,
  384,
  420,
  32767,
  32767,
  0,
  10,
  11,
  13,
  17,
  21,
  39,
  40,
  63,
  82,
  104,
  120,
  148,
  150,
  32767,
  32767,
  0,
  82,
  354,
  395,
  32767,
  32767,
  32767,
  32767,
  0,
  23,
  28,
  58,
  78,
  90,
  113,
  32767,
  0,
  11,
  15,
  22,
  60,
  110,
  673,
  717,
  721,
  32767,
  32767,
  32767,
  0,
  17,
  19,
  20,
  27,
  28,
  28,
  55,
  63,
  67,
  106,
  114,
  122,
  133,
  148,
  171,
  32767,
  32767,
  32767,
  32767,
  0,
  20,
  21,
  22,
  24,
  46,
  51,
  70,
  146,
  32767,
  32767,
  32767,
  0,
  13,
  18,
  19,
  26,
  33,
  34,
  41,
  32767,
  32767,
  32767,
  32767,
  0,
  23,
  26,
  32,
  35,
  59,
  82,
  122,
  32767,
  32767,
  32767,
  32767,
  0,
  20,
  21,
  26,
  28,
  330,
  407,
  470,
  611,
  614,
  701,
  32767,
  0,
  17,
  19,
  57,
  65,
  71,
  73,
  89,
  100,
  109,
  32767,
  32767,
  0,
  23,
  25,
  28,
  29,
  36,
  42,
  32767,
  0,
  21,
  22,
  27,
  34,
  36,
  40,
  45,
  46,
  55,
  63,
  32767,
  0,
  203,
  238,
  256,
  821,
  964,
  1244,
  1253,
  1285,
  2012,
  5501,
  10829,
  32767,
  32767,
  32767,
  32767,
  0,
  142,
  143,
  149,
  151,
  152,
  158,
  160,
  161,
  164,
  169,
  174,
  178,
  187,
  191,
  195,
  204,
  223,
  234,
  254,
  266,
  297,
  320,
  324,
  354,
  431,
  32767,
  32767
};


static const ARRAY(sint32, HLA_OTHERCOLOR_TABLE_SIZE_XENONLED, s32OtherColor_Ada2_alpha_XenonLED) = {
  0,
  -2566,
  -184,
  -1744,
  -2643,
  -1496,
  1247,
  4827,
  7546,
  11117,
  11117,
  11117,
  0,
  -3641,
  -5996,
  -7740,
  -14285,
  -7327,
  -5639,
  -4422,
  -1852,
  -532,
  -532,
  -532,
  0,
  -2070,
  -5066,
  -6538,
  -9177,
  -7543,
  -6632,
  -5773,
  -5773,
  -5773,
  -5773,
  -5773,
  0,
  -926,
  -1764,
  -2724,
  -5578,
  -6546,
  -7640,
  -8368,
  -7631,
  -5318,
  -3416,
  -268,
  1734,
  3187,
  3994,
  7344,
  8309,
  9223,
  11576,
  13088,
  13088,
  13088,
  13088,
  13088,
  0,
  1353,
  3514,
  4601,
  5340,
  6794,
  4872,
  4058,
  7042,
  8912,
  7368,
  6475,
  4918,
  4918,
  4918,
  4918,
  0,
  835,
  3696,
  2684,
  1425,
  319,
  -569,
  340,
  4576,
  4576,
  4576,
  4576,
  0,
  -2009,
  -3398,
  -4317,
  -7163,
  -8098,
  -9180,
  -10971,
  -11717,
  -12758,
  -12758,
  -12758,
  0,
  1036,
  2181,
  6440,
  10274,
  14169,
  13140,
  11891,
  10704,
  9743,
  9743,
  9743,
  0,
  887,
  -139,
  -3863,
  -5263,
  -1604,
  481,
  -394,
  -2202,
  -2976,
  -2976,
  -2976,
  0,
  -1194,
  -2042,
  -6329,
  -12261,
  -6630,
  -4600,
  -5404,
  -4419,
  479,
  479,
  479,
  0,
  -3770,
  -2749,
  -1248,
  882,
  4,
  1956,
  1956,
  0,
  -918,
  -2892,
  -5106,
  -7172,
  -10840,
  -8771,
  -6300,
  -4932,
  -3934,
  -1876,
  7541,
  8392,
  9502,
  11140,
  13760,
  14528,
  14528,
  14528,
  14528,
  0,
  -4844,
  -3567,
  -4608,
  -4608,
  -4608,
  -4608,
  -4608,
  0,
  1008,
  5121,
  6796,
  7912,
  7912,
  7912,
  7912,
  0,
  -3444,
  -2456,
  -4659,
  -8170,
  -9417,
  -10871,
  -11841,
  -12761,
  -12761,
  -12761,
  -12761,
  0,
  761,
  1826,
  3748,
  5263,
  7931,
  9664,
  10488,
  11555,
  12538,
  18743,
  20746,
  21851,
  21851,
  21851,
  21851,
  0,
  -1627,
  -3630,
  -3630,
  0,
  1016,
  3187,
  4207,
  1881,
  -969,
  -2897,
  -2897,
  0,
  -3062,
  -8292,
  -11902,
  -16548,
  -17785,
  -18756,
  -17848,
  -19993,
  -19993,
  -19993,
  -19993,
  0,
  3008,
  1433,
  528,
  -1671,
  -475,
  -475,
  -475,
  0,
  -1008,
  -2074,
  -1019,
  677,
  1600,
  -1132,
  -3439,
  -4372,
  -4372,
  -4372,
  -4372,
  0,
  2394,
  1438,
  54,
  54,
  54,
  54,
  54,
  0,
  2354,
  3813,
  6635,
  5358,
  2148,
  472,
  -590,
  -590,
  -590,
  -590,
  -590,
  0,
  1727,
  2982,
  7233,
  11553,
  12484,
  13231,
  14522,
  16594,
  13141,
  12043,
  12043,
  0,
  4118,
  5531,
  3337,
  -1079,
  -2090,
  -2090,
  -2090,
  0,
  -899,
  897,
  3238,
  4105,
  2066,
  13871,
  7736,
  6785,
  6785,
  6785,
  6785,
  0,
  1304,
  116,
  -1512,
  -4826,
  -5764,
  -6581,
  -8464,
  -10013,
  -11008,
  -11008,
  -11008,
  0,
  967,
  3338,
  4903,
  8144,
  8909,
  7168,
  6076,
  6990,
  8632,
  9844,
  10827,
  16966,
  18217,
  18217,
  18217,
  0,
  982,
  -784,
  -3204,
  -3204,
  -3204,
  -3204,
  -3204,
  0,
  2923,
  15968,
  16887,
  12740,
  11723,
  10503,
  10503,
  0,
  -990,
  -2743,
  -5884,
  -6906,
  -5407,
  -6364,
  -7707,
  -9936,
  -9936,
  -9936,
  -9936,
  0,
  -9008,
  -10633,
  -11670,
  -10704,
  -27245,
  -15774,
  -18607,
  -20746,
  -21598,
  -18159,
  -16928,
  -12489,
  -11578,
  -8296,
  -3728,
  -3728,
  -3728,
  -3728,
  -3728,
  0,
  -1332,
  -3979,
  -5767,
  -8234,
  -6941,
  -4481,
  -5262,
  3634,
  3634,
  3634,
  3634,
  0,
  952,
  3364,
  5868,
  11493,
  13152,
  14241,
  16958,
  16958,
  16958,
  16958,
  16958,
  0,
  979,
  6898,
  15192,
  17570,
  18463,
  17367,
  16440,
  16440,
  16440,
  16440,
  16440,
  0,
  -1106,
  -3343,
  -4757,
  -6625,
  -7974,
  -10606,
  -12828,
  -16523,
  -20577,
  -21469,
  -21469,
  0,
  -4468,
  -6368,
  -12725,
  -14682,
  -17591,
  -19534,
  -17740,
  -14654,
  -11955,
  -11955,
  -11955,
  0,
  -2936,
  -7913,
  -9674,
  -11796,
  -12716,
  -13532,
  -13532,
  0,
  2194,
  3441,
  11212,
  12582,
  15630,
  17341,
  18033,
  19039,
  20021,
  24218,
  24218,
  0,
  803,
  1723,
  2745,
  4829,
  5972,
  7191,
  8065,
  8955,
  9639,
  10462,
  9502,
  9502,
  9502,
  9502,
  9502,
  0,
  -4462,
  -5526,
  -7468,
  -8641,
  -9614,
  -10641,
  -12888,
  -16323,
  -17114,
  -18386,
  -19728,
  -20928,
  -21908,
  -24145,
  -24942,
  -29020,
  -33046,
  -39151,
  -46302,
  -49359,
  -56550,
  -60237,
  -61697,
  -66021,
  -73127,
  -73127,
  -73127
};


static const ARRAY(uint16, HLA_NUM_COLOR_FEATURES+1, adaInputVectorIndexTab_Halogen) = {
  0,
  20,
  28,
  36,
  48,
  60,
  76,
  92,
  112,
  120,
  128,
  132,
  148,
  156,
  164,
  172,
  184,
  192,
  200,
  212,
  224,
  236,
  248,
  260,
  272,
  280,
  296,
  308,
  320,
  328,
  340,
  344,
  360,
  368,
  376,
  384,
  396,
  412,
  424,
  432,
  452,
  476
};

static const ARRAY(uint16, HLA_OTHERCOLOR_TABLE_SIZE_HALOGEN, u16OtherColor_Ada2_b_Halogen) = {
  0,
  3,
  4,
  5,
  7,
  10,
  83,
  296,
  1813,
  2547,
  2850,
  3202,
  3821,
  6639,
  9525,
  11438,
  11604,
  18535,
  32767,
  32767,
  0,
  28,
  52,
  168,
  210,
  236,
  259,
  32767,
  0,
  100,
  182,
  10699,
  32767,
  32767,
  32767,
  32767,
  0,
  35,
  210,
  226,
  252,
  258,
  1089,
  2163,
  3084,
  3115,
  32767,
  32767,
  0,
  2,
  32,
  45,
  81,
  85,
  90,
  119,
  192,
  218,
  1924,
  32767,
  0,
  23,
  33,
  117,
  143,
  156,
  211,
  217,
  510,
  650,
  1178,
  3180,
  8313,
  32767,
  32767,
  32767,
  0,
  62,
  73,
  86,
  95,
  117,
  125,
  130,
  167,
  212,
  718,
  1173,
  1393,
  28959,
  29716,
  32767,
  0,
  21,
  33,
  39,
  114,
  117,
  180,
  353,
  358,
  469,
  610,
  647,
  1194,
  1296,
  3519,
  6064,
  7568,
  14060,
  14709,
  32767,
  0,
  31,
  90,
  93,
  99,
  454,
  733,
  32767,
  0,
  78,
  236,
  258,
  351,
  2310,
  32767,
  32767,
  0,
  289,
  301,
  32767,
  0,
  5,
  7,
  9,
  14,
  20,
  25,
  42,
  51,
  178,
  226,
  258,
  2015,
  2186,
  32767,
  32767,
  0,
  26,
  55,
  64,
  81,
  172,
  2248,
  32767,
  0,
  4,
  10,
  17,
  45,
  48,
  74,
  32767,
  0,
  64,
  99,
  183,
  213,
  309,
  32767,
  32767,
  0,
  16,
  17,
  19,
  22,
  29,
  64,
  98,
  32767,
  32767,
  32767,
  32767,
  0,
  14,
  37,
  47,
  32767,
  32767,
  32767,
  32767,
  0,
  86,
  88,
  96,
  108,
  32767,
  32767,
  32767,
  0,
  18,
  46,
  54,
  72,
  122,
  173,
  177,
  301,
  443,
  32767,
  32767,
  0,
  15,
  16,
  19,
  28,
  32,
  51,
  69,
  78,
  32767,
  32767,
  32767,
  0,
  64,
  161,
  229,
  345,
  512,
  545,
  639,
  672,
  680,
  32767,
  32767,
  0,
  8,
  11,
  20,
  27,
  37,
  53,
  90,
  32767,
  32767,
  32767,
  32767,
  0,
  45,
  55,
  63,
  79,
  224,
  246,
  314,
  359,
  32767,
  32767,
  32767,
  0,
  5,
  6,
  7,
  9,
  13,
  18,
  28,
  32767,
  32767,
  32767,
  32767,
  0,
  5,
  36,
  97,
  104,
  32767,
  32767,
  32767,
  0,
  68,
  77,
  84,
  86,
  96,
  133,
  134,
  135,
  139,
  157,
  255,
  740,
  830,
  32767,
  32767,
  0,
  44,
  45,
  54,
  193,
  199,
  234,
  295,
  391,
  32767,
  32767,
  32767,
  0,
  11,
  17,
  21,
  45,
  63,
  84,
  93,
  148,
  32767,
  32767,
  32767,
  0,
  65,
  188,
  263,
  354,
  32767,
  32767,
  32767,
  0,
  23,
  30,
  30,
  48,
  63,
  80,
  125,
  32767,
  32767,
  32767,
  32767,
  0,
  47,
  136,
  32767,
  0,
  6,
  8,
  17,
  22,
  22,
  31,
  32,
  48,
  62,
  97,
  157,
  32767,
  32767,
  32767,
  32767,
  0,
  21,
  24,
  72,
  146,
  165,
  32767,
  32767,
  0,
  28,
  28,
  41,
  32767,
  32767,
  32767,
  32767,
  0,
  26,
  33,
  45,
  47,
  32767,
  32767,
  32767,
  0,
  49,
  59,
  60,
  62,
  73,
  80,
  227,
  569,
  688,
  32767,
  32767,
  0,
  17,
  18,
  21,
  25,
  28,
  30,
  36,
  43,
  46,
  60,
  67,
  87,
  32767,
  32767,
  32767,
  0,
  29,
  42,
  43,
  47,
  48,
  49,
  52,
  61,
  63,
  32767,
  32767,
  0,
  14,
  27,
  34,
  34,
  63,
  78,
  32767,
  0,
  56,
  74,
  78,
  238,
  244,
  361,
  447,
  632,
  704,
  741,
  835,
  1106,
  1280,
  1379,
  1993,
  1998,
  2590,
  32767,
  32767,
  0,
  140,
  142,
  149,
  154,
  158,
  161,
  166,
  170,
  183,
  188,
  205,
  219,
  226,
  249,
  263,
  272,
  298,
  309,
  317,
  337,
  338,
  354,
  32767
};

static const ARRAY(sint32, HLA_OTHERCOLOR_TABLE_SIZE_HALOGEN, s32OtherColor_Ada2_alpha_Halogen) = {
  0,
  -5918,
  -8602,
  -15125,
  -19545,
  -22984,
  -23988,
  -24928,
  -24037,
  -23201,
  -21003,
  -19211,
  -17699,
  -16870,
  -11876,
  -10927,
  -10044,
  -9284,
  -9284,
  -9284,
  0,
  -4246,
  -4909,
  -5549,
  -8128,
  -13381,
  -8726,
  -8726,
  0,
  726,
  1455,
  686,
  686,
  686,
  686,
  686,
  0,
  -1637,
  -2430,
  -4022,
  -1877,
  3698,
  11023,
  12892,
  13676,
  14835,
  14835,
  14835,
  0,
  1529,
  2963,
  3940,
  -2248,
  411,
  4572,
  6325,
  7306,
  8075,
  8791,
  8791,
  0,
  3120,
  4020,
  4851,
  6117,
  7277,
  8246,
  8903,
  8087,
  6925,
  4858,
  3929,
  3249,
  3249,
  3249,
  3249,
  0,
  2340,
  3155,
  1415,
  -145,
  -921,
  -1904,
  -4474,
  -7258,
  -9806,
  -11445,
  -12277,
  -13675,
  -9003,
  -10450,
  -10450,
  0,
  2693,
  4541,
  6485,
  7300,
  8469,
  9441,
  8612,
  7827,
  6612,
  5838,
  4315,
  3188,
  2297,
  722,
  -372,
  -2269,
  -2966,
  -3758,
  -3758,
  0,
  835,
  1713,
  5926,
  6723,
  4973,
  4116,
  4116,
  0,
  803,
  -7861,
  -2869,
  1245,
  5708,
  5708,
  5708,
  0,
  745,
  1825,
  1825,
  0,
  -2250,
  -4082,
  -10118,
  -11005,
  -11790,
  -12819,
  -14793,
  -15476,
  -16403,
  -19619,
  -14771,
  -13241,
  -12491,
  -12491,
  -12491,
  0,
  652,
  -97,
  -2243,
  -3420,
  -4227,
  -3480,
  -3480,
  0,
  724,
  1588,
  4151,
  2683,
  362,
  -1050,
  -1050,
  0,
  -1806,
  -2451,
  -5183,
  -6517,
  -9215,
  -9215,
  -9215,
  0,
  729,
  1929,
  4285,
  5351,
  6087,
  7625,
  8348,
  8348,
  8348,
  8348,
  8348,
  0,
  1313,
  329,
  -1535,
  -1535,
  -1535,
  -1535,
  -1535,
  0,
  1890,
  2994,
  3672,
  4362,
  4362,
  4362,
  4362,
  0,
  3011,
  1154,
  -3309,
  -4272,
  -5030,
  -6107,
  -7037,
  -4505,
  -3488,
  -3488,
  -3488,
  0,
  1825,
  3106,
  6114,
  7158,
  7852,
  6408,
  7269,
  9422,
  9422,
  9422,
  9422,
  0,
  -729,
  -1544,
  -5597,
  -8308,
  -9645,
  -11815,
  -12615,
  -13510,
  -14330,
  -14330,
  -14330,
  0,
  885,
  4424,
  5668,
  4897,
  3859,
  1202,
  265,
  265,
  265,
  265,
  265,
  0,
  -813,
  -1750,
  -2897,
  -3600,
  -6534,
  -7992,
  -8881,
  -9832,
  -9832,
  -9832,
  -9832,
  0,
  2116,
  3554,
  7048,
  8802,
  7918,
  5959,
  6628,
  6628,
  6628,
  6628,
  6628,
  0,
  2826,
  -3819,
  -5081,
  -6049,
  -6049,
  -6049,
  -6049,
  0,
  2566,
  3854,
  4527,
  6370,
  8252,
  7058,
  15730,
  12018,
  11255,
  10208,
  8029,
  8914,
  10496,
  10496,
  10496,
  0,
  -744,
  -1779,
  -2639,
  -3923,
  -4781,
  -6713,
  -7510,
  -8526,
  -8526,
  -8526,
  -8526,
  0,
  2217,
  7087,
  8942,
  8182,
  10348,
  11519,
  12458,
  16531,
  16531,
  16531,
  16531,
  0,
  743,
  -2540,
  -4090,
  -6084,
  -6084,
  -6084,
  -6084,
  0,
  1974,
  -3995,
  10361,
  11179,
  11951,
  11146,
  10231,
  10231,
  10231,
  10231,
  10231,
  0,
  -965,
  4493,
  4493,
  0,
  -5889,
  -8393,
  -11092,
  -27810,
  -21063,
  -20169,
  -23513,
  -22847,
  -21248,
  -19780,
  -18195,
  -18195,
  -18195,
  -18195,
  -18195,
  0,
  -890,
  -1922,
  -3665,
  -986,
  -331,
  -331,
  -331,
  0,
  -920,
  5578,
  6531,
  6531,
  6531,
  6531,
  6531,
  0,
  4652,
  8260,
  7167,
  6474,
  6474,
  6474,
  6474,
  0,
  -683,
  -3959,
  -5606,
  -6306,
  -7224,
  -7919,
  -8822,
  -10851,
  -12553,
  -12553,
  -12553,
  0,
  -828,
  -4629,
  -5625,
  -6574,
  -7258,
  -9948,
  -11474,
  -12926,
  -14836,
  -13678,
  -10284,
  -8924,
  -8924,
  -8924,
  -8924,
  0,
  -744,
  -2668,
  -4677,
  -6185,
  -7483,
  -8226,
  -10376,
  -11049,
  -11857,
  -11857,
  -11857,
  0,
  -801,
  2010,
  -535,
  7968,
  10235,
  11848,
  11848,
  0,
  6989,
  11335,
  16671,
  17446,
  18275,
  19777,
  21986,
  24727,
  25426,
  26318,
  27617,
  29838,
  30635,
  31415,
  32387,
  33407,
  34205,
  34205,
  34205,
  0,
  -2738,
  -5009,
  -6016,
  -7646,
  -8485,
  -10204,
  -10822,
  -11611,
  -12366,
  -13208,
  -14450,
  -17128,
  -19012,
  -23965,
  -25924,
  -29667,
  -31858,
  -34045,
  -35667,
  -39056,
  -40000,
  -40865,
  -40865
};


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Detection of red lights */
static boolean HLAAnalysisColorRedLight( const HLA_t_AnalysisRedLightParameters*  pRedLightParamIn,
                                               HLATrack_t*                        pTrack );

/* ~CodeReviewBegin ~ID:5a47673c6e871c3f5c4cd4b01eec86e4 ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:dead code */
#if 0
/*! Detects red vehicle rear lights. */
static boolean HLARedLightAnalysis( const HLA_t_RedLightParameters  *pRedLightParamIn,
                                    HLATrack_t               *pTrack );

/*! Do color analysis based on color saturation. If color saturation is too high, the light is flagged as "non-white". */
static void HLAAnalysisColorNonWhite( HLATrack_t* pTrack );
#endif
/* ~CodeReviewEnd   ~ID:5a47673c6e871c3f5c4cd4b01eec86e4 */

/*! Calculate vector with input features for AdaBoost color classifiers */
static void HLAAnalysisColorSetInputVector(const HLATrack_t *pTrack);

/*! Detection of "other" lights (not red and not white) */
static sint32 HLAAnalysisColorOther( HLATrack_t*            pTrack,
                                     RTE_HLA_HeadlightType  eHeadLightType );



/*! Classification between red and white lights */
static void HLAAnalysisColorWhiteOrRed(HLATrack_t* pTrack);

/* **************************************************************************** 
  Functionname:     HLAAnalysisColorRedLight                             */ /*!  
  Description:      Detection of red lights

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static boolean HLAAnalysisColorRedLight( const HLA_t_AnalysisRedLightParameters*  pRedLightParamIn,
                                               HLATrack_t*                        pTrack )
{
  boolean bIsRed = b_FALSE;

  uint8 minRed_pos       = (uint8)CML_u_Round2Uint(pRedLightParamIn->minRed_pos * UI8_T_MAX);
  uint8 maxGreen_pos     = (uint8)CML_u_Round2Uint(pRedLightParamIn->maxGreen_pos * UI8_T_MAX);
  uint8 maxBlue_pos      = (uint8)CML_u_Round2Uint(pRedLightParamIn->maxBlue_pos * UI8_T_MAX);

  uint8 minRed_neg       = (uint8)CML_u_Round2Uint(pRedLightParamIn->minRed_neg * UI8_T_MAX);
  uint8 maxGreen_neg     = (uint8)CML_u_Round2Uint(pRedLightParamIn->maxGreen_neg * UI8_T_MAX);
  uint8 maxBlue_neg      = (uint8)CML_u_Round2Uint(pRedLightParamIn->maxBlue_neg * UI8_T_MAX);

  float32 minInt = pRedLightParamIn->minInt;

  uint8 minRed_City       = (uint8)CML_u_Round2Uint(pRedLightParamIn->minRed_City * UI8_T_MAX);
  uint8 maxGreen_City     = (uint8)CML_u_Round2Uint(pRedLightParamIn->maxGreen_City * UI8_T_MAX);
  uint8 maxBlue_City      = (uint8)CML_u_Round2Uint(pRedLightParamIn->maxBlue_City * UI8_T_MAX);
  float32 minInt_City     = pRedLightParamIn->minInt_City;

  if(   (pTrack->light_ref != NULL)
     && (pTrack->MaxInt > minInt)
     )
  {
    /* red light ? */
    if(    (pTrack->light_ref->current_R > minRed_pos)
        && (pTrack->light_ref->current_G < maxGreen_pos)
        && (pTrack->light_ref->current_B < maxBlue_pos)
      )
    {
      if(pTrack->RedLightCnt < UI8_T_MAX)
      {
        pTrack->RedLightCnt++;
      }
      bIsRed = b_TRUE;
    }
    else if(   (pTrack->light_ref->current_R < minRed_neg)
             || (pTrack->light_ref->current_G > maxGreen_neg)
             || (pTrack->light_ref->current_B > maxBlue_neg)
           )
    { 
      if(pTrack->RedLightCnt > 0)
      {
        pTrack->RedLightCnt--;
      }
    }
    else
    {
      /* Do nothing when no red light is there */
    }
  }
  else
  {
    /* no light detected or below intensity threshold */
    if(pTrack->RedLightCnt > 0)
    {
      pTrack->RedLightCnt--;
    } 
  }

  /* red light count for city detection */
  if(   (pTrack->light_ref != NULL)
     && (pTrack->MaxInt > minInt_City)
    )
  {
    /* red light ? */
    if(    (pTrack->light_ref->current_R > minRed_City)
        && (pTrack->light_ref->current_G < maxGreen_City)
        && (pTrack->light_ref->current_B < maxBlue_City)
      )
    {
      if(pTrack->RedLightCnt4City < UI8_T_MAX)
      {
        pTrack->RedLightCnt4City++;
      }
    }
    else
    { 
      if(pTrack->RedLightCnt4City > 0u)
      {
        pTrack->RedLightCnt4City--;
      }
    }
  }
  else
  {
    /* no light detected or below intensity threshold */
    if(pTrack->RedLightCnt4City > 0u)
    {
      pTrack->RedLightCnt4City--;
    } 
  }

  return bIsRed;
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisColorOther */ /*!
  Description:      Analyze color to classify between "red or white" (negative)
                    and "other" (positive).

  @param[in,out]    HLATrack_t              *pTrack     current track for analysis

  @return           sint32  s32result       classifier result (for validation)
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static sint32 HLAAnalysisColorOther( HLATrack_t*           pTrack,
                                     RTE_HLA_HeadlightType eHeadLightType )
{
  /*--- VARIABLES ---*/
  const uint16* adaInputVectorIndexTab;
  const uint16* u16OtherColor_Ada2_b;
  const sint32* s32OtherColor_Ada2_alpha;
  sint32 alphaSum;

  uint8   k;
  uint16  l;
  sint32  s32alphaVote = 0;
  sint32  s32result = 0;

  if (eHeadLightType == RTE_HLA_LTYPE_HALOGENE)
  {
    adaInputVectorIndexTab = &adaInputVectorIndexTab_Halogen[0];
    u16OtherColor_Ada2_b = &u16OtherColor_Ada2_b_Halogen[0];
    s32OtherColor_Ada2_alpha = &s32OtherColor_Ada2_alpha_Halogen[0];
    alphaSum = HLA_OTHERCOLOR_ALPHASUM_HALOGEN;
  }
  else
  {
    adaInputVectorIndexTab = &adaInputVectorIndexTab_XenonLED[0];
    u16OtherColor_Ada2_b = &u16OtherColor_Ada2_b_XenonLED[0];
    s32OtherColor_Ada2_alpha = &s32OtherColor_Ada2_alpha_XenonLED[0];
    alphaSum = HLA_OTHERCOLOR_ALPHASUM_XENONLED;
  }

  /* check for valid measurement */
  if (   (pTrack->lost_time == 0) 
      && (pTrack->light_ref != NULL) 
     )
  {           
    /* check if there are any saturated pixels */
    if (pTrack->light_ref->Status.isAnyNGBSaturated == 1)
    {
      /* do nothing */
      /* set result "idle" */
      pTrack->anaResStat.isOtherColor.result = HLA_RESULT_IDLE;
    }
    else
    {
      //  Loop to summarize the s32alphaVote for the 41 COLOR_FEATURES
      for (k = 0; k < HLA_NUM_COLOR_FEATURES; k++)
      {
        l = adaInputVectorIndexTab[k];
        do
        {
          l++;
        }
        while (u16OtherColor_Ada2_b[l] < adaInputVector[k]);
        s32alphaVote += s32OtherColor_Ada2_alpha[l-1];
      }
      s32result = (s32alphaVote * 2) - alphaSum;

      if (s32result < 0)
      {
        /* set result "positive" */
        pTrack->anaResStat.isOtherColor.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        /* set result "negative" */
        pTrack->anaResStat.isOtherColor.result = HLA_RESULT_NEGATIVE;
      }
    }
  }
  else
  {
    /* set result "idle" */
    pTrack->anaResStat.isOtherColor.result = HLA_RESULT_IDLE;
  }

  return (s32result);
  
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisColor */ /*!
  Description:      Do color based analysis.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn            required input for function
  @param[in]        const HLA_t_RedLightParameters  *pRedLightIn    required input for function
  @param[in,out]    HLATrack_t                      *pTrack             current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
boolean HLAAnalysisColor( const HLA_t_AnalysisParameters*   pAnalysisParamIn,
                          const RTE_HLA_HeadlightType       eHeadLightType,
                                HLATrack_t*                 pTrack
                         )
{
  boolean bIsRed = b_FALSE;

  HLAAnalysisColorSetInputVector(pTrack);

  bIsRed |= HLAAnalysisColorRedLight(&pAnalysisParamIn->RedLight, pTrack);

  /*isRed |= HLARedLightAnalysis(pRedLightIn, pTrack);*/
  /*HLAAnalysisColorNonWhite(pTrack);*/

  HLAAnalysisColorOther(pTrack, eHeadLightType);


  HLAAnalysisColorWhiteOrRed(pTrack);
  if (pTrack->anaResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE)
  {
    bIsRed = b_TRUE;
  }

  return bIsRed;
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisColorSetInputVector */ /*!
  Description:      Calculate vector with input features for AdaBoost color 
                    classifiers. Writes on global adaInputVector[] array.

  @param[in]        const HLATrack_t       *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAAnalysisColorSetInputVector(const HLATrack_t* pTrack)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/
  uint16 ngb[13];
  uint16 ngb_in[13];

  uint32 i;
  uint32 temp;

  
  if (   (pTrack != NULL) 
      && (pTrack->light_ref != NULL) 
     )
  {
    ngb_in[0] = pTrack->light_ref->Maxima.ngb[NGB_0].lux;
    ngb_in[1] = pTrack->light_ref->Maxima.ngb[NGB_1].lux;
    ngb_in[2] = pTrack->light_ref->Maxima.ngb[NGB_2].lux;
    ngb_in[3] = pTrack->light_ref->Maxima.ngb[NGB_3].lux;
    ngb_in[4] = pTrack->light_ref->Maxima.ngb[NGB_4].lux;
    ngb_in[5] = pTrack->light_ref->Maxima.ngb[NGB_5].lux;
    ngb_in[6] = pTrack->light_ref->Maxima.ngb[NGB_6].lux;
    ngb_in[7] = pTrack->light_ref->Maxima.ngb[NGB_7].lux;
    ngb_in[8] = pTrack->light_ref->Maxima.ngb[NGB_8].lux;
    ngb_in[9] = pTrack->light_ref->Maxima.ngb[NGB_9].lux;
    ngb_in[10]= pTrack->light_ref->Maxima.ngb[NGB_10].lux;
    ngb_in[11]= pTrack->light_ref->Maxima.ngb[NGB_11].lux;
    ngb_in[12]= pTrack->light_ref->Maxima.ngb[NGB_12].lux;

    /* get lux values for neighbouring pixels */
    for (i = 0; i < 13; i++)
    {
      const uint16 lux = ngb_in[i];
      
      ngb[i] = CML_Min(SI16_T_MAX - 1, lux);

      /* WORKAROUND: add 1 to avoid divisions by zero */
      ngb[i] = ngb[i] + 1;

      /* ***** set input vector (0 - 12) ***** */
      adaInputVector[i] = (uint16)(ngb[i]);
    }

    /* ***** set input vector  (13 - 40) ***** */
    /* ~CodeReviewBegin ~ID:5950df7d1a6177902c962379d099e366 ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:magic numbers */
    adaInputVector[13] = (uint16)( ((uint32)(ngb[ 1]) << 6) / (uint32)(ngb[ 2]) );
    adaInputVector[14] = (uint16)( ((uint32)(ngb[ 2]) << 6) / (uint32)(ngb[ 3]) );
    adaInputVector[15] = (uint16)( ((uint32)(ngb[ 4]) << 6) / (uint32)(ngb[ 5]) );
    adaInputVector[16] = (uint16)( ((uint32)(ngb[ 5]) << 6) / (uint32)(ngb[ 6]) );
    adaInputVector[17] = (uint16)( ((uint32)(ngb[ 6]) << 6) / (uint32)(ngb[ 7]) );
    adaInputVector[18] = (uint16)( ((uint32)(ngb[ 7]) << 6) / (uint32)(ngb[ 8]) );
    adaInputVector[19] = (uint16)( ((uint32)(ngb[ 9]) << 6) / (uint32)(ngb[10]) );
    adaInputVector[20] = (uint16)( ((uint32)(ngb[10]) << 6) / (uint32)(ngb[11]) );

    adaInputVector[21] = (uint16)( ((uint32)(ngb[ 1]) << 6) / (uint32)(ngb[ 5]) );
    adaInputVector[22] = (uint16)( ((uint32)(ngb[ 5]) << 6) / (uint32)(ngb[ 9]) );
    adaInputVector[23] = (uint16)( ((uint32)(ngb[ 0]) << 6) / (uint32)(ngb[ 2]) );
    adaInputVector[24] = (uint16)( ((uint32)(ngb[ 2]) << 6) / (uint32)(ngb[ 6]) );
    adaInputVector[25] = (uint16)( ((uint32)(ngb[ 6]) << 6) / (uint32)(ngb[10]) );
    adaInputVector[26] = (uint16)( ((uint32)(ngb[10]) << 6) / (uint32)(ngb[12]) );
    adaInputVector[27] = (uint16)( ((uint32)(ngb[ 3]) << 6) / (uint32)(ngb[ 7]) );
    adaInputVector[28] = (uint16)( ((uint32)(ngb[ 7]) << 6) / (uint32)(ngb[11]) );

    adaInputVector[29] = (uint16)( ((uint32)(ngb[ 1] + ngb[ 3]) << 5) / (uint32)(ngb[ 2]) );
    adaInputVector[30] = (uint16)( ((uint32)(ngb[ 4] + ngb[ 6]) << 5) / (uint32)(ngb[ 5]) );
    adaInputVector[31] = (uint16)( ((uint32)(ngb[ 5] + ngb[ 7]) << 5) / (uint32)(ngb[ 6]) );
    adaInputVector[32] = (uint16)( ((uint32)(ngb[ 6] + ngb[ 8]) << 5) / (uint32)(ngb[ 7]) );
    adaInputVector[33] = (uint16)( ((uint32)(ngb[ 9] + ngb[11]) << 5) / (uint32)(ngb[10]) );

    adaInputVector[34] = (uint16)( ((uint32)(ngb[ 1] + ngb[ 9]) << 5) / (uint32)(ngb[ 5]) );
    adaInputVector[35] = (uint16)( ((uint32)(ngb[ 0] + ngb[ 6]) << 5) / (uint32)(ngb[ 2]) );
    adaInputVector[36] = (uint16)( ((uint32)(ngb[ 2] + ngb[10]) << 5) / (uint32)(ngb[ 6]) );
    adaInputVector[37] = (uint16)( ((uint32)(ngb[ 6] + ngb[12]) << 5) / (uint32)(ngb[10]) );
    adaInputVector[38] = (uint16)( ((uint32)(ngb[ 3] + ngb[11]) << 5) / (uint32)(ngb[ 7]) );
    /* ~CodeReviewEnd   ~ID:5950df7d1a6177902c962379d099e366 */

    /* max intensity value */
    adaInputVector[39] = 0;
    for (i = 0; i < 13; i++)
    {
      adaInputVector[39] = CML_Max(adaInputVector[39], ngb[i]);
    }

    /* alternative "radius" calculation */
    temp = ((ngb[ 0] + ngb[ 4] + ngb[ 8] + ngb[12]) >> 2);
    temp = CML_Min(ngb[ 6], temp);
    temp = ((uint32)(ngb[ 6]) << 7) / (1 + (ngb[ 6] - temp));
    temp = CML_Min(temp, 32767);
    adaInputVector[40] = (uint16)temp;
    /* ***** end set input vector ***** */
  }

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationColorOther */ /*!
  Description:      Do identification for "other color" lights.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void HLAIdentificationColorOther( const HLA_t_IdentificationParameters* pIdentParamIn,
                                        HLATrack_t*                     pTrack )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  const sint8 maxNegativeConfidence = -31;
  /*const sint8 maxUnknownConfidence  =   0;*/
  const sint8 maxPositiveConfidence =  31;

  /*--- VARIABLES ---*/
  uint8 analysisResult;
  
  if (pTrack != NULL)
  {
    analysisResult = pTrack->anaResStat.isOtherColor.result;

    /* if the ident state has already reached its maximum positive or negative confidence, do no further updates */
    /*
    if (   (pTrack->idResStat.isOtherColor.confidence != maxNegativeConfidence) 
        && (pTrack->idResStat.isOtherColor.confidence != maxPositiveConfidence) 
        )
    */
    {
      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* update confidence in "negative" direction */
        /* ~CodeReview ~ID:47ef17833ea176b2cacd336484c820a4 ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:magic number "5" -> use otherColorPositiveBound */
        if (pTrack->idResStat.isOtherColor.confidence >= 5) /* beyond opposite decision boundary ? */
        {
          /* faster update */
          pTrack->idResStat.isOtherColor.confidence = CML_Max(maxNegativeConfidence, pTrack->idResStat.isOtherColor.confidence - pIdentParamIn->otherColorConfStepSizeFast);
        }
        else
        {
          /* normal update */
          pTrack->idResStat.isOtherColor.confidence = CML_Max(maxNegativeConfidence, pTrack->idResStat.isOtherColor.confidence - pIdentParamIn->otherColorConfStepSizeNormal);
        }
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* update confidence in "positive" direction */
        /* ~CodeReview ~ID:93ec962cfa59bad44d482fcf26c2e25a ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:magic number "-5" -> use otherColorNegativeBound */
        if (pTrack->idResStat.isOtherColor.confidence <= -5) /* beyond opposite decision boundary ? */
        {
          /* faster update */
          pTrack->idResStat.isOtherColor.confidence = CML_Min(maxPositiveConfidence, pTrack->idResStat.isOtherColor.confidence + pIdentParamIn->otherColorConfStepSizeFast);
        }
        else
        {
          /* normal update */
          pTrack->idResStat.isOtherColor.confidence = CML_Min(maxPositiveConfidence, pTrack->idResStat.isOtherColor.confidence + pIdentParamIn->otherColorConfStepSizeNormal);
        }
      }
      else /* if ((analysisResult == HLA_RESULT_IDLE) || (analysisResult == HLA_RESULT_ERROR)) */
      {
        /* "unknown" -> update confidence in "neutral" direction */
        if (pTrack->idResStat.isOtherColor.confidence > 0)
        {
          pTrack->idResStat.isOtherColor.confidence = CML_Max(0, pTrack->idResStat.isOtherColor.confidence - pIdentParamIn->otherColorConfStepSizeNeutral);
        }
        else if (pTrack->idResStat.isOtherColor.confidence < 0)
        {
          pTrack->idResStat.isOtherColor.confidence = CML_Min(0, pTrack->idResStat.isOtherColor.confidence + pIdentParamIn->otherColorConfStepSizeNeutral);
        }
        else
        {
          /* confidence is already "neutral" -> do nothing */
        }
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isOtherColor.confidence <= pIdentParamIn->otherColorNegativeBound)
      {
        pTrack->idResStat.isOtherColor.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isOtherColor.confidence >= pIdentParamIn->otherColorPositiveBound)
      {
        pTrack->idResStat.isOtherColor.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isOtherColor.result = HLA_RESULT_IDLE;
      }
    }
  }
  
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisColorWhiteOrRed */ /*!
  Description:      Analyze color to classify between white (positive) and 
                    red (negative).

  @param[in,out]    HLATrack_t                      *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAAnalysisColorWhiteOrRed(HLATrack_t *pTrack)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  /* const sint8 maxNegativeConfidence = -31; */
  /* const sint8 maxPositiveConfidence =  31; */

  /*--- VARIABLES ---*/
  uint32 n;
  sint32 result;

  /* check for valid measurement */
  if (   (pTrack->lost_time == 0) 
      && (pTrack->light_ref != NULL) 
     )
  {           
    /* check current ngb pixel values ...                    */
    result = 0;
    /* ~CodeReview ~ID:6a32301e0a7e312e5c57229ea0919c93 ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:magic number */
    for (n = 0; n < 26; n++)
    {
      /* ~CodeReview ~ID:57eaf66640582f09715703d10ee3658f ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:add comments on how "optimized" code works */
      result += WhiteRed_Ada2[n].alpha * (-1 + (((WhiteRed_Ada2[n].b - adaInputVector[WhiteRed_Ada2[n].idx]) & 0x8000) >> 14) );
    }

    if (result > 0)
    {
      /* set result "positive" */
      pTrack->anaResStat.isWhiteOrRed.result = HLA_RESULT_POSITIVE;
    }
    else
    {
      /* set result "negative" */
      pTrack->anaResStat.isWhiteOrRed.result = HLA_RESULT_NEGATIVE;
    }
  }
  else
  {
    /* set result "idle" */
    pTrack->anaResStat.isWhiteOrRed.result = HLA_RESULT_IDLE;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationColorWhiteOrRed */ /*!
  Description:      Do identification for "white or red" lights.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void HLAIdentificationColorWhiteOrRed( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                             HLATrack_t*                      pTrack )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  const sint8 maxNegativeConfidence = -31;
  /*const sint8 maxUnknownConfidence  =   0;*/
  const sint8 maxPositiveConfidence =  31;

  /*--- VARIABLES ---*/
  uint8 analysisResult;
  
  if (pTrack != NULL)
  {
    analysisResult = pTrack->anaResStat.isWhiteOrRed.result;

    if (analysisResult == HLA_RESULT_NEGATIVE)
    {
      /* update confidence in "negative" direction */
      pTrack->idResStat.isWhiteOrRed.confidence = CML_Max(maxNegativeConfidence, pTrack->idResStat.isWhiteOrRed.confidence - pIdentParamIn->whiteOrRedConfStepSize);
    }
    else if (analysisResult == HLA_RESULT_POSITIVE)
    {
      /* update confidence in "positive" direction */
      pTrack->idResStat.isWhiteOrRed.confidence = CML_Min(maxPositiveConfidence, pTrack->idResStat.isWhiteOrRed.confidence + pIdentParamIn->whiteOrRedConfStepSize);
    }
    else /*if (analysisResult == HLA_RESULT_IDLE)*/
    {
      /* "unknown" -> no change */
    }

    /* set identification result by confidence level */
    if (pTrack->idResStat.isWhiteOrRed.confidence <= pIdentParamIn->whiteOrRedNegativeBound)
    {
      pTrack->idResStat.isWhiteOrRed.result = HLA_RESULT_NEGATIVE;
    }
    else if (pTrack->idResStat.isWhiteOrRed.confidence >= pIdentParamIn->whiteOrRedPositiveBound)
    {
      pTrack->idResStat.isWhiteOrRed.result = HLA_RESULT_POSITIVE;
    }
    else
    {
      pTrack->idResStat.isWhiteOrRed.result = HLA_RESULT_IDLE;
    }
  }
  
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
  /* <ln_offset:+2 PCLINT Error 766: reviewer name: Reik Müller date: 08.03.2012 reason: LINT fails to recognize intrinsic code */
}
