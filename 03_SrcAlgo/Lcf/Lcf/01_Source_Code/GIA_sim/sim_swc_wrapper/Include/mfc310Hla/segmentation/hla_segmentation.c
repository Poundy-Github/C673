/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segmentation.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segmentation.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:39CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:25CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:57CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.52 2014/03/25 19:11:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:46 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.51 2014/03/25 18:46:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_segmentation.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_segmentation.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj.
  CHANGE:                 Revision 1.50 2014/03/24 11:26:29CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed some roundings
  CHANGE:                 --- Added comments ---  brunnm [Mar 24, 2014 11:26:29 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.49 2014/03/22 10:28:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added project specific defines
  CHANGE:                 Replaced defines for CORE by predefined ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:26 AM CET]
  CHANGE:                 Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.48 2014/03/21 15:30:22CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix:
  CHANGE:                  - fixed a bug caused by buffer overflow which caused segmentation to run amok
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 21, 2014 3:30:22 PM CET]
  CHANGE:                 Change Package : 226768:1 http://mks-psad:7002/im/viewissue?selection=226768
  CHANGE:                 Revision 1.47 2014/03/21 11:01:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some compiler warnings
  CHANGE:                 Small refactoring
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 11:01:13 AM CET]
  CHANGE:                 Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.46 2014/03/21 09:38:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:43 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.45 2014/03/19 16:30:16CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:16 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.44 2014/03/18 16:15:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Made some symbols not static
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 18, 2014 4:15:37 PM CET]
  CHANGE:                 Change Package : 207432:22 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.43 2014/03/14 07:43:22CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed corrupt stack (array HLASegLightFillRteOutput[] out of bounds) in HLASegLightFillRteOutput()
  CHANGE:                 --- Added comments ---  brunnm [Mar 14, 2014 7:43:23 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.42 2014/03/12 18:07:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:37 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.41 2014/03/11 15:43:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took cfg_project.h into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:44 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.40 2014/03/10 13:20:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:56 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.39 2014/03/05 14:08:38CET Brunn, Marcus (brunnm) 
  CHANGE:                 added RTE_HLA_Seg_LightList_t
  CHANGE:                 --- Added comments ---  brunnm [Mar 5, 2014 2:08:38 PM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.38 2014/03/04 16:52:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:06 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.37 2014/03/03 16:51:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.1 interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:38 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.36 2014/03/03 14:23:53CET Brunn, Marcus (brunnm) 
  CHANGE:                 fill RTE_HLA_Seg_Light_t (rte output of light/region list)
  CHANGE:                 --- Added comments ---  brunnm [Mar 3, 2014 2:23:54 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.35 2014/03/03 13:10:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced tabs by spaces
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 1:11:00 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2014/03/03 10:20:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed compilation for DSP
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 10:20:49 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.33 2014/02/28 15:04:56CET Brunn, Marcus (brunnm) 
  CHANGE:                 - improved light filtering
  CHANGE:                 - preparation of light list for new rte interface i390
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:04:56 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.31 2014/02/07 16:33:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed dframe calculation
  CHANGE:                 Updated time meas inside segmentation
  CHANGE:                 Updated HIL according to latest changes
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 4:33:03 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.30 2014/02/07 09:49:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:49:58 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.29 2014/02/06 16:02:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:47 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.28 2014/02/06 09:54:15CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed overflowing LED seglines on eve side in addition to Marcus' commit
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 9:54:15 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/02/05 15:26:53CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed LED segmentation
  CHANGE:                 --- Added comments ---  brunnm [Feb 5, 2014 3:26:53 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.26 2014/01/31 10:21:03CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed wrong region linking in "HLASegRegionBuildRelationship"
  CHANGE:                 -> this errors leads to double lights at same image position 
  CHANGE:                      which leads in the tracking to problems (track lost, jumping tracks, rockets, ... )
  CHANGE:                 --- Added comments ---  brunnm [Jan 31, 2014 10:21:03 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.25 2014/01/21 09:12:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:55 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.24 2014/01/10 18:33:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:19 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.23 2014/01/08 17:10:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 Revision 1.22 2014/01/05 22:56:15CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicite conversion from int to unsigned int and vise versa removed
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:56:15 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.21 2013/12/20 10:00:09CET Glebov, Roman (uidg4759) 
  CHANGE:                 removed not used #include <stdio.h>.
  CHANGE:                 it was used only for debugging purposes.
  CHANGE:                 
  CHANGE:                 right now existance of #include <stdio.h> causes 
  CHANGE:                 QAC-Analyser to stop with parse hard error, because
  CHANGE:                 it can not find __scanf__ and __printf__ functions
  CHANGE:                 --- Added comments ---  uidg4759 [Dec 20, 2013 10:00:09 AM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.20 2013/12/13 16:45:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:12 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2013/12/05 17:47:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Update to RTE I330
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:58 PM CET]
  CHANGE:                 Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2013/12/04 16:18:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Use L2 Cache for SegLightBuffer, SegLineRegionBuffer
  CHANGE:                 Fixed deadlock in segmentation
  CHANGE:                 
  CHANGE:                 Review by AlexM.
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 4, 2013 4:18:27 PM CET]
  CHANGE:                 Change Package : 207432:10 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.17 2013/11/29 16:48:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Moved find max position to vcop
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 29, 2013 4:48:18 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2013/11/21 17:53:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:56 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2013/10/16 14:59:23CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated eve code for support for lrf
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:24 PM CEST]
  CHANGE:                 Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.14.1.18 2013/11/21 13:37:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:38 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.14.1.17 2013/11/19 15:36:40CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed HLASegLightAddLight2List for release build of DSP
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 3:36:40 PM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.16 2013/11/19 14:04:37CET Brunn, Marcus (brunnm) 
  CHANGE:                 - bugfixed HLASegPreProcImage
  CHANGE:                 - removed unused vars from HlaSegAddLight
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 2:04:37 PM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.15 2013/11/19 13:44:05CET Brunn, Marcus (brunnm) 
  CHANGE:                 - clean up -> removed unused vars/ functions
  CHANGE:                 - added detailed time measurement for segmentation
  CHANGE:                 Revision 1.14.1.14 2013/11/19 07:54:02CET Brunn, Marcus (brunnm) 
  CHANGE:                 - removed day segmentation
  CHANGE:                 - updated HLASegLineBuffer_t
  CHANGE:                 - updated HLASegLineRegion_t (used region index instead of region pointer)
  CHANGE:                 - optimized region build
  CHANGE:                 - reduced max number of regions from 250 to 200
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 7:54:02 AM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.13 2013/11/14 09:48:32CET Brunn, Marcus (brunnm) 
  CHANGE:                 region build: clean up of region parameters
  CHANGE:                 --- Added comments ---  brunnm [Nov 14, 2013 9:48:32 AM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.12 2013/11/12 13:45:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added restrict keyword
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:39 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.11 2013/11/06 15:46:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Cosmetic changes
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 6, 2013 3:46:29 PM CET]
  CHANGE:                 Change Package : 201787:8 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.10 2013/11/05 12:05:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more RTA events
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 5, 2013 12:05:01 PM CET]
  CHANGE:                 Change Package : 201787:8 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.9 2013/10/31 17:44:20CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed compiler warning
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 31, 2013 5:44:20 PM CET]
  CHANGE:                 Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.8 2013/10/29 18:21:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Time meas fixes
  CHANGE:                 New roi calculation (alignment to eve)
  CHANGE:                 Call EVE in segmentation now
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:26 PM CET]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.7 2013/10/24 12:20:06CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added more time meas for segmentation internally
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 12:20:06 PM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.6 2013/10/24 10:44:19CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some not needed variables
  CHANGE:                 Made HLA working on evalboard
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:20 AM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.14.1.5 2013/10/23 16:42:43CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed lines copy (iLevelHight/ iLevelLow)
  CHANGE:                 --- Added comments ---  brunnm [Oct 23, 2013 4:42:43 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.4 2013/10/21 15:51:54CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced preprocessing function: HLASegPreProcImage()
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 3:51:54 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.3 2013/10/21 10:18:30CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t
  CHANGE:                 - removed bit field for line position
  CHANGE:                 - moved  level index from line to region
  CHANGE:                 Revision 1.14.1.2 2013/10/21 08:36:26CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - clean up
  CHANGE:                 - introduced adaptive thresholds for level 4 and 5
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 8:36:26 AM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.14.1.1 2013/10/18 13:27:56CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:57 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639              
**************************************************************************** */
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hla_segmentation.h"
#include "hla_segcalc.h"
#include "hla_segline.h"
#include "hla_seglightfillrte.h"
#include "hla_seglightfilter.h"
#include "hla_seglightutils.h"
#include "hla_segregion.h"
#include "hla_seglight.h"
#include "hla_segsubimage.h"

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* DEFINITIONS
******************************************************************************/
static void HLASegInitData( const boolean                             bFirst,
                                  HLASegLineRegionBuffer_t*           pRegionBuffer,
                                  HLASegLightBuffer_t*                pLightBuffer,
                                  HLASegData_t*                       pData,
                                  HLASegOut_t*                        pOut,
                                  RTE_HLA_Seg_LightList_t*            pLightList /* RTE Out */
                          );

static void HLASegInitLightDataRoiLevel(HLASegLightDataRoi_t* pDat);

/******************************************************************************
* GLOBAL VARIABLES
******************************************************************************/
/* segmentation: line buffer */
#ifdef HLA_SEGMENTATION_ON_EVE
/* As these variables are eve output buffers we have to invalidate corresponding cache lines
 * after Eve comes back,
 * Hence, we have to align start and end of each variable to HLA_DSP_CACHE_LINE_SIZE (128 Bytes)
 */
#pragma DATA_ALIGN (hlaSegLineBuffer,  HLA_DSP_CACHE_LINE_SIZE)
#endif
HLASegLineBuffer_t    hlaSegLineBuffer;
#ifdef HLA_SEGMENTATION_ON_EVE
/* We only need RTE_HLA_SEG_MAX_NUM_LEVELS elements. HLA_DSP_CACHE_LINE_SIZE / 2 is due to cache alignment reasons */
#pragma DATA_ALIGN (EVETimeMeas, HLA_DSP_CACHE_LINE_SIZE)
static HLAEveTimeMeas_t EVETimeMeas;
#endif
 
#ifdef _TMS320C6X
extern HLAImagerParameter_t          hlaImagerPar;
#endif

/* ****************************************************************************
  Functionname:     HLASegmentationExec
  Description:      

  @param[in]             

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegmentationExec( const HLAR_t_RequiredInputs*        ps_In,
                                t_PixelData*                  pImg,
                          const HLACameraData_t*              pCamData,
                          const HLA_t_SegmentationParameters* pPar,
                          const HLASegIn_t*                   pIn,
                                HLASegData_t*                 pData,
                                HLASegOut_t*                  pOut,
                                HLASegLightBuffer_t*          pLightBuffer,
                                HLASegLineRegionBuffer_t*     pRegionBuffer,
                                RTE_HLA_Seg_LightList_t*      ps_SegLightList, /* RTE Out */
                                HLADebugOutputs_t*            pDebug,
                          const AS_t_ServiceFuncts*           Services
                        )
{
  uint32 HWTime_us;
  sint32 i;
  const HLA_t_SegmentationParametersBrightness* pParBrightness; /* brightness dependent parameters */

  /* init segmentation data */
  HLASegInitData( FALSE, 
                  pRegionBuffer, 
                  pLightBuffer, 
                  pData, 
                  pOut,
                  ps_SegLightList /* RTE Out */
                 );
    
  /* select brightness dependent parameters set */
  if(pIn->eBrightnessState == RTE_HLAR_BRT_NIGHT)
  {
    /* Night */
    pParBrightness = &pPar->Night;  
  }
  else
  {
    /* Twilight */
    pParBrightness = &pPar->Twilight;
  }

  /* set light parameter: e.g. intensity threshold for all levels */
  HLASegUtilsBinarizeImage_SetThreshold(pParBrightness, pData);

  
  /* copy region level threshold */ 
  for(i=0;i <= (sint32) HLA_SEG_LEVEL_LIGHT;i++)
  {  
    pOut->RegionLevel.f32_Level[i] = pData->BinarizeImgData.Threshold.Lux.Level[i];
  }
  
  /* copy fingerprint */
  HLASegUtilsCopyFingerPrint( ps_In,
                              pImg,
                              &pOut->Fingerprint
                            );

  /* calc. average intensity of the subsampled image */
  HLASegSubImageCalcIntensities( /* input */
                                 &ps_In->s_Par.s_CameraParameter,
                                 pImg,
                                 pCamData,
                                 pIn,
                                 /* history */ 
                                 &pData->SubImage,
                                 /* output */
                                 pOut
                               );


  if(    (pIn->eBrightnessState > RTE_HLAR_BRT_TWLGT_1)
      || (pIn->TestMode == RTE_HLA_TESTMODE_SEG_ALWAYS_ON)
    )
  {

    /* image preprocessing on EVE/ PC */
    HLASegLinePreProcImage( &ps_In->s_Par.s_CameraParameter,
                            pCamData,
                            Services,
                            pImg,
                            pData,
                            pDebug,
                            &hlaSegLineBuffer
#ifdef HLA_SEGMENTATION_ON_EVE
                          , &EVETimeMeas 
#endif
                            );
  }
   

  /* build regions for all levels */
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();     
  /* build regions level from iLevelHigh to iLevelLow (from top down) */
  {
    for(i=hlaSegLineBuffer.iLevelHigh; i>=hlaSegLineBuffer.iLevelLow; i--)
    {
      const HLASegmentationParametersLineCluster_t *pParLineCluster;
      pParLineCluster = &pParBrightness->LineCluster;

      HLASegRegionBuildList( &hlaSegLineBuffer, 
                             pParLineCluster, 
                             pCamData, 
                             (uint8)i,
                             &hlaSegLineBuffer.Level[i], 
                             &(pRegionBuffer->Level[i].iRegion),
                             &(pRegionBuffer->Level[i].nRegions),
                             &(pRegionBuffer->iRegionFree),
                             pRegionBuffer                             
                           );
      pRegionBuffer->nRegions += pRegionBuffer->Level[i].nRegions;
      pRegionBuffer->Level[i].nRegionsSuperior = pRegionBuffer->Level[i].nRegions;
      pRegionBuffer->nRegionsSuperior += pRegionBuffer->Level[i].nRegionsSuperior;
    }
  }
  pDebug->timeMeas.dTimeSegmentationBuildRegions_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);


  /* build links between regions from highest to lowest level */
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32(); 
  for(i = hlaSegLineBuffer.iLevelHigh; i > hlaSegLineBuffer.iLevelLow; i--)
  {
    HLASegRegionBuildRelationship( &hlaSegLineBuffer, 
                                   pRegionBuffer->Level[i].iRegion,
                                   pRegionBuffer->Level[i-1].iRegion,
                                   pRegionBuffer                                   
                                 );
  }
  pDebug->timeMeas.dTimeSegmentationBuildRelationship_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);


  /* build all lights */
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();     
  /* build the normal light list */
  for(i=hlaSegLineBuffer.iLevelHigh; i>=hlaSegLineBuffer.iLevelLow; i--)
  {
    /* level i */
    HLASegLightBuildList( /* input */
                          pCamData->RoiYu,
                          pRegionBuffer,
                          pLightBuffer,
                          /* output */
                          pRegionBuffer->Level[i].iRegion,
                          &pData->LightData,
                          &pData->LightData.AboveRoi,
                          &pData->LightData.FunctRoi
                         );
  }
  pDebug->timeMeas.dTimeSegmentationBuildLights_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);   

  /* find maxima in greyvalues */
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();
  /* find one maxima for each light */
  HLASegUtilsFindMaxima( &ps_In->s_Par.s_CameraParameter, 
                         &hlaSegLineBuffer,
                         pImg, 
                         &pData->LightData.AboveRoi, 
                         pLightBuffer
                       );
  HLASegUtilsFindMaxima( &ps_In->s_Par.s_CameraParameter, 
                         &hlaSegLineBuffer,
                         pImg, 
                         &pData->LightData.FunctRoi, 
                         pLightBuffer
                       );

  pDebug->timeMeas.dTimeSegmentationFindMaximaGV_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* build pair lights */
  HWTime_us = Services->pfGetTimestampuS32();
  HLASegLightBuildPairLights( &pData->LightData.FunctRoi,
                              pRegionBuffer,
                              pLightBuffer,
                              pCamData,
                              &pParBrightness->Pair
                            );
  /* search for new red pair lights */
  HLASegLightSearchPairLights( &ps_In->s_Par.s_CameraParameter,
                               pCamData,
                               pImg,
                               pData,
                               &pData->LightData.FunctRoi,
                               &pParBrightness->Pair,
                               pRegionBuffer,
                               pLightBuffer
                             );
  pDebug->timeMeas.dTimeSegmentationBuildPairLights_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* detect potential LED rear lights in the function roi */
  HWTime_us = Services->pfGetTimestampuS32();
  HLASegLightUtilsPotentialLEDDetection( pCamData,
                                         pParBrightness,
                                         &pData->LightData.FunctRoi,
                                         pLightBuffer
                                       );
  /* saturation detection (T1 and T123) */
  HLASegLightUtilsDetectionSaturation( &pData->LightData.FunctRoi,
                                       pLightBuffer
                                     );
  pDebug->timeMeas.dTimeSegmentationPotentialLEDDetection_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* convert not linear 12Bit grey values to Lux intensity */
  HWTime_us = Services->pfGetTimestampuS32();
  HLASegCalcLuxIntensity(&pData->LightData.AboveRoi, pLightBuffer);
  HLASegCalcLuxIntensity(&pData->LightData.FunctRoi, pLightBuffer);
  pDebug->timeMeas.dTimeSegmentationCalcLuxInt_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* find maxima on lux values, HLASegFindMaxima() searches only for the max. grey value */
  HWTime_us = Services->pfGetTimestampuS32();
  HLASegUtilsFindMaxima_Lux(&pData->LightData.AboveRoi, pLightBuffer);
  HLASegUtilsFindMaxima_Lux(&pData->LightData.FunctRoi, pLightBuffer);
  pDebug->timeMeas.dTimeSegmentationFindMaximaLux_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* gradient based interpolation */
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();     
  HLASegCalcRGB_GradientBasedInterp(pData->LightData.AboveRoi.iLight, pLightBuffer);
  HLASegCalcRGB_GradientBasedInterp(pData->LightData.FunctRoi.iLight, pLightBuffer);
  pDebug->timeMeas.dTimeSegmentationCalcRGBGradientBasedInterp_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);
 
  /* Potential red light detection */
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();
  /* potential red light detection */
  HLASegLightUtilsPotentialRedDetection( pCamData,
                                         pParBrightness,
                                         &pData->LightData.FunctRoi,
                                         pLightBuffer                                         
                                       );

  pDebug->timeMeas.dTimeSegmentationRedLightDetection_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* set light position */
  HWTime_us = Services->pfGetTimestampuS32();
  HLASegLightUtilsSetLightPosition(pData->LightData.AboveRoi.iLight, pLightBuffer);
  HLASegLightUtilsSetLightPosition(pData->LightData.FunctRoi.iLight, pLightBuffer);
  pDebug->timeMeas.dTimeSegmentationSetLightPosition_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);
  
  /* remove dark lights in above roi */
  HWTime_us = Services->pfGetTimestampuS32();
  pData->LightData.AboveRoi.nLights[0] = pData->LightData.AboveRoi.nLights_Raw;
  pData->LightData.FunctRoi.nLights[0] = pData->LightData.FunctRoi.nLights_Raw;
  if(pData->LightData.AboveRoi.nLights[0] > pParBrightness->MaxNumLights[1].AboveRoi)
  {
    HLASegLightUtilsRemoveDarkLights( pCamData,
                                      pParBrightness,
                                      &pData->LightData.AboveRoi,
                                      pLightBuffer                                      
                                    );
  }
  if((pData->LightData.AboveRoi.nLights[0] + pData->LightData.FunctRoi.nLights[0]) > pParBrightness->MaxNumLights[1].Roi)
  {
    HLASegLightUtilsRemoveDarkLights( pCamData,
                                      pParBrightness,
                                      &pData->LightData.FunctRoi,
                                      pLightBuffer
                                    );
  }
  pDebug->timeMeas.dTimeSegmentationRemoveDarkLights_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

  /* for the further light filtering we have to       */
  /* split the function roi lights in sub categories  */
  /* 1. potential red lights                          */
  /* 2. potential led lights                          */
  /* 3. bright lights (all other lights)              */
  HLASegLightUtilsSplitLightList( pLightBuffer, 
                                  &pData->LightData.FunctRoi,
                                  &pData->LightData.FunctRoi_Red,
                                  &pData->LightData.FunctRoi_Led,
                                  &pData->LightData.FunctRoi_Bright
                                );
  /* sort lights in function roi from bottom up */
  HLASegLightUtilsSortFromBottomUp( &pData->LightData.FunctRoi_Red,
                                    pLightBuffer
                                  );
  HLASegLightUtilsSortFromBottomUp( &pData->LightData.FunctRoi_Led,
                                    pLightBuffer
                                  );
  HLASegLightUtilsSortFromBottomUp( &pData->LightData.FunctRoi_Bright,
                                    pLightBuffer
                                  );

  /* light reduction */
  HWTime_us = Services->pfGetTimestampuS32();
  /*********************************/
  /* 1st stage filter (RTE output) */
  /*********************************/
  pData->LightData.FunctRoi_Red.nLights[0] = pData->LightData.FunctRoi_Red.nLights_Raw;
  pData->LightData.FunctRoi_Led.nLights[0] = pData->LightData.FunctRoi_Led.nLights_Raw;
  pData->LightData.FunctRoi_Bright.nLights[0] = pData->LightData.FunctRoi_Bright.nLights_Raw;
  HLASegLightFilter( pCamData,
                     pParBrightness,
                     0, /* 1st filter stage (RTE output) */		     
                     pData,
                     pLightBuffer
                  );
  /*****************************************/
  /* 2nd stage filter (HLA tracking input) */
  /*****************************************/
  pData->LightData.AboveRoi.nLights[1] = pData->LightData.AboveRoi.nLights[0];
  pData->LightData.FunctRoi.nLights[1] = pData->LightData.FunctRoi.nLights[0];
  pData->LightData.FunctRoi_Red.nLights[1] = pData->LightData.FunctRoi_Red.nLights_Raw;
  pData->LightData.FunctRoi_Led.nLights[1] = pData->LightData.FunctRoi_Led.nLights_Raw;
  pData->LightData.FunctRoi_Bright.nLights[1] = pData->LightData.FunctRoi_Bright.nLights_Raw;
  HLASegLightFilter( pCamData,
                     pParBrightness,
                     1, /* 2nd filter stage (HLA tracking input) */
                     pData,
                     pLightBuffer
                   );
  pDebug->timeMeas.dTimeSegmentationLightsReduction_us = (uint16)((Services->pfGetTimestampuS32() - HWTime_us));

  /* build chain of all lights for segmentation output (above and function roi lights) */
  HWTime_us = Services->pfGetTimestampuS32();
  HLASegLightBuildChainOut( &pData->LightData,
                            pOut
                            );

  /* set the maximum light intensity -> used for intensity threshold */
  HLASegLightUtilsSetMaxInt(pData, pOut);
  pDebug->timeMeas.dTimeSegmentationBuildChainOut_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);
  
  HWTime_us = Services->pfGetTimestampuS32();
  /* increment segmentation call counter */
  pData->HLAS_Cnt++;

  /* copy frame counter and timestamp into output structure */
  /* hlaSegData             */
  pData->FrameCnt                           = ps_In->uiFrameCnt;
  pData->TimeStamp_Image_us                 = ps_In->uiTimeStamp_Image_us;
  /* hlaSegOut              */
  pOut->HLAS_Cnt                            = pData->HLAS_Cnt;
  pOut->FrameCnt                            = ps_In->uiFrameCnt;
  pOut->TimeStamp_Image_us                  = ps_In->uiTimeStamp_Image_us;
  /* hlaSegLineBuffer   */
  hlaSegLineBuffer.ui32_InterfaceVersionNumber = SEGLINE_BUF_INTERFACE_VERSION_NUMBER;
  hlaSegLineBuffer.HLAS_Cnt                 = pData->HLAS_Cnt;
  hlaSegLineBuffer.FrameCnt                 = ps_In->uiFrameCnt;
  hlaSegLineBuffer.TimeStamp_Image_us       = ps_In->uiTimeStamp_Image_us;
  /* hlaSegLineRegionBuffer */
  pRegionBuffer->ui32_InterfaceVersionNumber = SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER;
  pRegionBuffer->HLAS_Cnt                    = pData->HLAS_Cnt;
  pRegionBuffer->FrameCnt                    = ps_In->uiFrameCnt;
  pRegionBuffer->TimeStamp_Image_us          = ps_In->uiTimeStamp_Image_us;
  /* hlaSegLightBuffer      */
  pLightBuffer->HLAS_Cnt                     = pData->HLAS_Cnt;
  pLightBuffer->FrameCnt                     = ps_In->uiFrameCnt;
  pLightBuffer->TimeStamp_Image_us           = ps_In->uiTimeStamp_Image_us;

  /* set rte light list */
  HLASegLightFillRteOutput( pData,
                            pOut,
                            pLightBuffer,
                            pRegionBuffer,
                            pCamData,
                            ps_SegLightList /* RTE Out */
                          );
  pDebug->timeMeas.dTimeSegmentationFillRteOutput_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);
}

/* ****************************************************************************
  Functionname:     HLASegmentationInit
  Description:      Initializes the segmentation before HLA starts the first time after bootup.

  @param[in]        
  @param[in,out]    
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida, Marcus Brunn
**************************************************************************** */
void HLASegmentationInit( HLASegLineRegionBuffer_t* pRegionBuffer,
                          HLASegLightBuffer_t*      pLightBuffer,
                          HLASegData_t*             pData, 
                          HLASegOut_t*              pOut,
                          RTE_HLA_Seg_LightList_t*  ps_SegLightList /* RTE Out */
                        )
{
  /* init segmentation data */
  HLASegInitData( TRUE,
                  pRegionBuffer,
                  pLightBuffer,
                  pData,
                  pOut,
                  ps_SegLightList /* RTE Out */
                 );
}

/* ****************************************************************************
  Functionname:     HLASegmentationReInit
  Description:      Reinitializes the segmentation after each HLAR main function.

  @param[in]        
  @param[in,out]    
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida, Marcus Brunn
**************************************************************************** */
void HLASegmentationReInit( HLASegLineRegionBuffer_t* pRegionBuffer,
                            HLASegLightBuffer_t*      pLightBuffer,
                            HLASegData_t*             pData, 
                            HLASegOut_t*              pOut,
                            RTE_HLA_Seg_LightList_t*  ps_SegLightList /* RTE Out */
                          )
{
  /* init segmentation data */
  HLASegInitData( FALSE,
                  pRegionBuffer,
                  pLightBuffer,
                  pData,
                  pOut,
                  ps_SegLightList /* RTE Out */               
                );
}

/* ****************************************************************************
  Functionname:     HLASegmentationMeasfreeze
  Description:      

  @param[in]               

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegmentationMeasfreeze( const AS_t_MeasHdlr             pfMeasFreeze,
                                const HLASegLineRegionBuffer_t* pRegionBuffer,
                                const HLASegLightBuffer_t*      pLightBuffer
                               )
{
  AS_t_MeasInfo SegLineBufferMeasInfo       = {HLA_MEAS_VADDR_SEG_LINE_BUFFER, (40 * sizeof(HLASegLine_t)) + 16, 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo SegLineRegionBufferMeasInfo = {HLA_MEAS_VADDR_SEG_REGION_BUFFER, (20 * sizeof(HLASegLineRegion_t)) + 4, 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo SegLightBufferMeasInfo      = {HLA_MEAS_VADDR_SEG_LIGHT_BUFFER, (30 * sizeof(HLASegLight_t)) + 4, 0 /*COMP_ID_HLA*/, TASK_ID_HLA};

  (void)pfMeasFreeze(&SegLineBufferMeasInfo, (void*)&hlaSegLineBuffer, NULL);
  (void)pfMeasFreeze(&SegLineRegionBufferMeasInfo, (void*)pRegionBuffer, NULL);
  (void)pfMeasFreeze(&SegLightBufferMeasInfo, (void*)pLightBuffer, NULL);

}

/* **************************************************************************** 
  Functionname:     HLASegInitData
  Description:      Initializes the segmentation data

  @param[in]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegInitData( const boolean                             bFirst,
                                  HLASegLineRegionBuffer_t*           pRegionBuffer,
                                  HLASegLightBuffer_t*                pLightBuffer,
                                  HLASegData_t*                       pData,
                                  HLASegOut_t*                        pOut,
                                  RTE_HLA_Seg_LightList_t*            pLightList /* RTE Out */
                          )
{
   
  /* init some parts only the first time after bootup */
  if(bFirst == TRUE)
  {
    (void)memset((void*)pData, 0, sizeof(HLASegData_t));
    (void)memset((void*)pOut,  0, sizeof(HLASegOut_t));
  }
  
  (void)memset((void*)pLightBuffer,       0, sizeof(HLASegLightBuffer_t));
  (void)memset((void*)pRegionBuffer,      0, sizeof(HLASegLineRegionBuffer_t));
  (void)memset((void*)&hlaSegLineBuffer,  0, sizeof(HLASegLineBuffer_t));
  (void)memset((void*)pLightList,   0, sizeof(RTE_HLA_Seg_LightList_t));
  
    
  /* init internal segmentation data */
  /* init hlaSegLineRegionBuffer */
  {
    uint8 iLevel;

    for(iLevel = 0; iLevel < RTE_HLA_SEG_MAX_NUM_LEVELS; iLevel++)
    {
      hlaSegLineBuffer.Level[iLevel].iLine = HLA_SEG_MAX_NUM_SEG_LINES;
    }
  }
  
  /* init region data */
  {
    uint8 iReg;
    uint8 iLevel;
    
        
    for(iReg=0; iReg<(HLA_SEG_MAX_NUM_REGIONS-1); iReg++)
    {
      pRegionBuffer->Region[iReg].iNext = iReg + 1;
    }
    pRegionBuffer->Region[HLA_SEG_MAX_NUM_REGIONS-1].iNext = HLA_SEG_MAX_NUM_REGIONS;

    for(iLevel=0;iLevel<RTE_HLA_SEG_MAX_NUM_LEVELS; iLevel++)
    {
      pRegionBuffer->Level[iLevel].iRegion = HLA_SEG_MAX_NUM_REGIONS;
    }
  }


  /* init light data */
  {
    uint8 i;
    
    (void)memset((void*)&pData->LightData, 0, sizeof(HLASegLightData_t));
    pData->LightData.iLightFree = 0;
    
    HLASegInitLightDataRoiLevel(&pData->LightData.AboveRoi);
    HLASegInitLightDataRoiLevel(&pData->LightData.FunctRoi);
    HLASegInitLightDataRoiLevel(&pData->LightData.FunctRoi_Red);
    HLASegInitLightDataRoiLevel(&pData->LightData.FunctRoi_Led);
    HLASegInitLightDataRoiLevel(&pData->LightData.FunctRoi_Bright);
           
    for(i=0; i<(HLA_SEG_MAX_NUM_LIGHTS-1); i++)
    {
      pLightBuffer->Light[i].LightID = i;
      pLightBuffer->Light[i].iLightNext = i+1;
    }
    pLightBuffer->Light[HLA_SEG_MAX_NUM_LIGHTS-1].LightID = HLA_SEG_MAX_NUM_LIGHTS-1;
    pLightBuffer->Light[HLA_SEG_MAX_NUM_LIGHTS-1].iLightNext = HLA_SEG_MAX_NUM_LIGHTS;
  }

  /* init some internal variables for the subsampled image */
  pData->SubImage.currentRow = 0u;
  pData->SubImage.accIntCallCounter = 0u;
  pData->SubImage.accPixOffset = 0u;
  (void)memset((void*)(&pData->SubImage.accInt[0][0]), 0, sizeof(pData->SubImage.accInt[0][0]) * HLA_SEG_INTENSITY_SUB_IMG_HEIGHT*HLA_SEG_INTENSITY_SUB_IMG_WIDTH);
  (void)memset((void*)(&pData->SubImage.accCnt[0]),    0, sizeof(pData->SubImage.accCnt[0]) * HLA_SEG_INTENSITY_SUB_IMG_HEIGHT);
    

  /* init output structure */
  pOut->pLightMemoryStart = &(pLightBuffer->Light[0]);
  pOut->nLights           = 0;
  pOut->iLight            = HLA_SEG_MAX_NUM_LIGHTS;
  pOut->pLineBuffer       = &hlaSegLineBuffer;
  pOut->Region            = &(pRegionBuffer->Region[0]);
  pOut->Light             = &(pLightBuffer->Light[0]);
  
}

/* **************************************************************************** 
  Functionname:     HLASegInitLightDataRoiLevel
  Description:      

  @param[in]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegInitLightDataRoiLevel(HLASegLightDataRoi_t* pDat)
{
  memset(pDat, 0, sizeof(HLASegLightDataRoi_t));
  pDat->iLight = HLA_SEG_MAX_NUM_LIGHTS;
}/* PRQA S 861 1 */
