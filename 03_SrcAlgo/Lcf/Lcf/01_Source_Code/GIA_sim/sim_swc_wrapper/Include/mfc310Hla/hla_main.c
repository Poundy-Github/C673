/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    Renesas M32R

  COMPONENT:              HLA

  MODULNAME:              hla_main.c

  DESCRIPTION:            head light assist interface functions  

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          07.11.2006

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_main.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:33CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:44CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:08CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.53 2014/03/28 10:36:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Introduced CML_u_Round2Uint
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:23 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.52 2014/03/26 11:27:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:43 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.51 2014/03/25 19:02:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced fABS by CML_f_abs
  CHANGE:                 Introduced CML_f_Round
  CHANGE:                 Removed QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:02:58 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.50 2014/03/19 16:31:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:47 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.49 2014/03/19 15:23:28CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Added CountryCode to city input
  CHANGE:                 --- Added comments ---  uidv8778 [Mar 19, 2014 3:23:29 PM CET]
  CHANGE:                 Change Package : 226009:1 http://mks-psad:7002/im/viewissue?selection=226009
  CHANGE:                 Revision 1.48 2014/03/18 16:15:36CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Made some symbols not static
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 18, 2014 4:15:37 PM CET]
  CHANGE:                 Change Package : 207432:22 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.47 2014/03/18 11:52:41CET Brunn, Marcus (brunnm) 
  CHANGE:                 moved "Set frame counter of previous frame" to HLARCalcDFrame() function
  CHANGE:                 --- Added comments ---  brunnm [Mar 18, 2014 11:52:42 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.46 2014/03/12 18:07:20CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:20 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.45 2014/03/10 13:21:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:03 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.44 2014/03/05 14:07:59CET Brunn, Marcus (brunnm) 
  CHANGE:                 added RTE_HLA_Seg_LightList_t
  CHANGE:                 --- Added comments ---  brunnm [Mar 5, 2014 2:07:59 PM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.43 2014/03/05 11:05:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:22 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.42 2014/03/04 16:52:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:05 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.41 2014/03/03 16:51:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.1 interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:40 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.40 2014/02/28 15:10:04CET Brunn, Marcus (brunnm) 
  CHANGE:                 enabled usage of L2 memory
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:10:04 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.39 2014/02/28 15:04:55CET Brunn, Marcus (brunnm) 
  CHANGE:                 - improved light filtering
  CHANGE:                 - preparation of light list for new rte interface i390
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:04:55 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.38 2014/02/27 14:07:28CET Fischer, Alexander (uidv8778) 
  CHANGE:                 fixed setting systeminfo state to running, after error occured
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 27, 2014 2:07:28 PM CET]
  CHANGE:                 Change Package : 207443:3 http://mks-psad:7002/im/viewissue?selection=207443
  CHANGE:                 Revision 1.37 2014/02/24 12:23:15CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed dFrame calculation 
  CHANGE:                 - consider wrap around of frame count after 8 or 16 bit
  CHANGE:                 --- Added comments ---  brunnm [Feb 24, 2014 12:23:16 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.36 2014/02/24 11:44:43CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - tunnel detection types changed
  CHANGE:                  - removed some unnecessary flags from the simulation INI file (all related to very old visu)
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 24, 2014 11:44:43 AM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.35 2014/02/18 13:21:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:53 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2014/02/11 12:43:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC critical warning
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2014 12:43:44 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.33 2014/02/11 09:20:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed time meas
  CHANGE:                 Fixed dframe calculation on HIL
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:13 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.32 2014/02/11 08:14:05CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed check of pitch against +/-5° because online cali is now (MFC4xx) in absolute angles, and the default angle could be above 5° (e.g. truck)
  CHANGE:                 todo -> we have to check the delta to the default angle
  CHANGE:                 --- Added comments ---  brunnm [Feb 11, 2014 8:14:06 AM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.31 2014/02/07 16:32:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed dframe calculation
  CHANGE:                 Updated time meas inside segmentation
  CHANGE:                 Updated HIL according to latest changes
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 4:32:57 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.30 2014/02/07 13:40:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Get version info in wrapper now from lib
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 1:40:12 PM CET]
  CHANGE:                 Change Package : 207432:30 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.29 2014/02/07 09:49:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:49:58 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.28 2014/02/06 16:01:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:35 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.27 2014/02/05 08:57:39CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Increment HLAR Counter in reset
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 5, 2014 8:57:40 AM CET]
  CHANGE:                 Change Package : 207443:1 http://mks-psad:7002/im/viewissue?selection=207443
  CHANGE:                 Revision 1.26 2014/01/24 09:35:01CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:35:01 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.25 2014/01/23 10:36:02CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixes for float with float equality test
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 23, 2014 10:36:03 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.24 2014/01/22 14:01:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 22, 2014 2:01:57 PM CET]
  CHANGE:                 Change Package : 193435:6 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.23 2014/01/21 09:12:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:54 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/01/16 11:35:42CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - added some improvements for trucklights-on-highway pair tracking
  CHANGE:                  - changed pairing parameter for trucklights-on-highway pair tracking
  CHANGE:                  - removed switch between night and day visualization
  CHANGE:                 
  CHANGE:                 Minor fixes:
  CHANGE:                  - fixed some tabs
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 16, 2014 11:35:42 AM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.21 2014/01/13 17:01:38CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 clean up "copy tracks from HLAR to HLAF"- routine
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 13, 2014 5:01:38 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.20 2014/01/10 18:34:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:05 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.19 2014/01/08 17:10:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 Revision 1.18 2014/01/05 22:55:34CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicite conversion from int to unsigned int and vise versa removed
  CHANGE:                          default variable initializations
  CHANGE:                          qac messages with comments
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:55:34 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.17 2013/12/18 15:18:04CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:04 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.16 2013/12/13 16:45:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:02 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2013/12/05 15:46:12CET Brunn, Marcus (brunnm) 
  CHANGE:                 merged from I320
  CHANGE:                 --- Added comments ---  brunnm [Dec 5, 2013 3:46:13 PM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.14 2013/12/04 16:18:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Use L2 Cache for SegLightBuffer, SegLineRegionBuffer
  CHANGE:                 Fixed deadlock in segmentation
  CHANGE:                 
  CHANGE:                 Review by AlexM.
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 4, 2013 4:18:30 PM CET]
  CHANGE:                 Change Package : 207432:10 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.13 2013/11/21 17:53:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:39 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.12 2013/10/31 14:55:48CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Fix: Added Oncoming Hist in Debug Highway measfreeze
  CHANGE:                 --- Added comments ---  uidv8778 [Oct 31, 2013 2:55:48 PM CET]
  CHANGE:                 Change Package : 198634:1 http://mks-psad:7002/im/viewissue?selection=198634
  CHANGE:                 Revision 1.11.1.9 2013/11/12 13:44:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:45 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.11.1.8 2013/11/05 12:04:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more RTA events
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 5, 2013 12:04:47 PM CET]
  CHANGE:                 Change Package : 201787:8 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.11.1.7 2013/10/31 18:25:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from Trunk
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 31, 2013 6:25:21 PM CET]
  CHANGE:                 Change Package : 201787:3 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.11.1.6 2013/10/29 18:21:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Time meas fixes
  CHANGE:                 New roi calculation (alignment to eve)
  CHANGE:                 Call EVE in segmentation now
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:26 PM CET]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.11.1.5 2013/10/24 16:07:48CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fix for previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 4:07:48 PM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.11.1.4 2013/10/24 10:44:19CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some not needed variables
  CHANGE:                 Made HLA working on evalboard
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:19 AM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.11.1.3 2013/10/23 09:43:49CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed wrong image pointer for icon copy: 
  CHANGE:                 call HLAIconInit() before imager pointer is used by icon copy
  CHANGE:                 --- Added comments ---  brunnm [Oct 23, 2013 9:43:49 AM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.11.1.2 2013/10/21 10:18:29CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t
  CHANGE:                 - removed bit field for line position
  CHANGE:                 - moved  level index from line to region
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 10:18:29 AM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.11.1.1 2013/10/18 13:27:56CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 Replaced specific HLA opmodes by TestMode CPar
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:32 AM CEST]
  CHANGE:                 Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.10 2013/09/18 17:41:45CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Undo changes from development path
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 18, 2013 5:41:45 PM CEST]
  CHANGE:                 Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.7 2013/08/30 13:30:30CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: corrected a bug in the internal cali mapping
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 30, 2013 1:30:31 PM CEST]
  CHANGE:                 Change Package : 189284:1 http://mks-psad:7002/im/viewissue?selection=189284
  CHANGE:                 Revision 1.6 2013/08/29 12:39:44CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:44 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.5 2013/08/27 17:13:28CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed icon extraction
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 27, 2013 5:13:28 PM CEST]
  CHANGE:                 Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
  CHANGE:                 Revision 1.4 2013/08/19 16:53:02CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: Rough implementation of tunnel detection at night based on street lamps.
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 19, 2013 4:53:02 PM CEST]
  CHANGE:                 Change Package : 188780:1 http://mks-psad:7002/im/viewissue?selection=188780
  CHANGE:                 Revision 1.3 2013/08/09 17:53:32CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Eve bug fixes:
  CHANGE:                 - # of seglines of function roi
  CHANGE:                 - eve return code
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 9, 2013 5:53:32 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.2 2013/08/05 20:41:16CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed EVE/DSP caching issues
  CHANGE:                 Added time meas struct for EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:16 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1 2013/08/05 17:01:56CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.88.1.261 2013/07/26 17:43:18CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: fixed a small bug to enable building
  CHANGE:                 --- Added comments ---  uidv8777 [Jul 26, 2013 5:43:19 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.88.1.260 2013/07/26 17:04:20CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added first part of EVE implementation
  CHANGE:                 --- Added comments ---  uidv7867 [Jul 26, 2013 5:04:20 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.88.1.259 2013/07/18 18:12:22CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Updates due to RTE change:
  CHANGE:                 Includes: 
  CHANGE:                  - new HeadlightState
  CHANGE:                  - EcoLight Feature
  CHANGE:                  - Light Dimming Areas Feature
  CHANGE:                  - Light adaptive image display settings for MTS visu
  CHANGE:                  - SRLCam rec file support in visu
  CHANGE:                 --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:22 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>

#include "hla_main.h"
#include "hlar_ext.h"
#include "hla_base.h"
#include "hla_debug.h"
#include "hla_errorCheck.h"

#include "hla_analysis.h"
#include "hla_analysisicon.h"
#include "hla_segmentation.h"
#include "hla_highway.h"
#include "hla_imager.h"
#include "hla_icon.h"
#include "hla_brightness.h"
#include "hla_city.h"
#include "hla_tunnel.h"
#include "hla_trafficstyle.h"
#include "hla_camera.h"
#include "hla_analysisstreetlamps.h"
#include "hla_brightobjects.h"
#include "hla_ver.h"

#ifdef PC_SIM
#include "auto_eval.h"
#endif

/* ~CodeReview ~ID:bfcdeaef2387aa487884503b1d5e22d2 ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:(general)  signed and unsigned assignents mixed (e.g. uint8 i = 0; instead of uint8 i = 0u) */

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  boolean skipReInit;

  uint32  ui32_R1;    /* requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;    /* requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;  /* [us] current integration time T1     */
  float32 f32_T2_us;  /* [us] current integration time T2     */
  float32 f32_T3_us;  /* [us] current integration time T3     */
  float32 f32_Gain;   /* [1]  total gain, depending on temperature */
} HLAImagerPrevChar;

typedef struct
{
  HLASegLightBuffer_t      L2_hlaSegLightBuffer;
  HLASegLineRegionBuffer_t L2_hlaSegLineRegionBuffer;
} HLAL2Cache;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
/* frame counter of previous frame */

static AlgoCycleCounter_t hlaFrameCntPrevFrame;

/* hla camera data: roi, function roi position */
HLACameraData_t     hlaCamData;

/* debug variables */
HLADebugOutputs_t hlaDebugOutputs;

/* odometer */
HLA_GLOBAL_STATIC HLAOdometer_t       hlaOdometer;

/* segmentation: region buffer */
HLASegLineRegionBuffer_t hlaSegLineRegionBuffer;

/* segmentation: light buffer = merged maximas */
HLASegLightBuffer_t   hlaSegLightBuffer;

/* segmentation data */
HLASegData_t  hlaSegData;

/* segmentation input data */
HLA_GLOBAL_STATIC HLASegIn_t    hlaSegIn;

/* segmentation output data */
HLASegOut_t                     hlaSegOut;

/* highway detection input */
static HLAHighwayInput_t        hlaHighwayInput;

/* highway detection output */
HLA_t_Highway                   hlaHighwayOutput;

/* highway detection internal data */
HLA_GLOBAL_STATIC HLAHighwayInternalData_t  hlaHighwayInternalData;

/* recognition call counter */
static AlgoCycleCounter_t HLAR_Cnt;

/***************************/
/* hla_analysisstreetlamps */
/***************************/
/* street lamps analysis */
HLA_GLOBAL_STATIC HLASLInput_t hlaSLInput;

/* allocate memory for SL_ListNode */
static ARRAY(HLA_SL_ListNode_t, MAX_NUM_SL, hlaFreeStreetLampsBuffer);

/********************/
/* hla_tracking */
/********************/
/* tracking input */
static HLATracking3DInput_t   hlaTrackIn; 

/* tracking output */
HLATracking3DOutput_t         hlaTrackOut;

/* tracking internal data */
HLA_GLOBAL_STATIC HLATracking3DData_t    hlaTrackData; 

/********************/
/* hla_city */
/********************/
/* City Input */
static HLACityInput_t               hlaCityInput;

/* City Data */
HLA_GLOBAL_STATIC HLACityData_t     hlaCityData;

/* City output */
HLA_GLOBAL_STATIC RTE_HLAR_CityState  ehlaCityOutput;

/* Chain of Light*/
HLA_GLOBAL_STATIC HLAChainOfLightData_t hlaChainOfLightData;

/********************/
/* hla_trafficstyle */
/********************/
/* Traffic Style Input */
static HLATrafficStyleInput_t           hlaTrafficStyleInput;

/* Traffic Style Data */
HLA_GLOBAL_STATIC HLATrafficStyleHist_t hlaTrafficStyleHist;

/* Traffic Style Output */
HLA_GLOBAL_STATIC RTE_HLA_TrafficStyle                ehlaTrafficStyle;
HLA_GLOBAL_STATIC RTE_HLAR_TrafficStyleState          ehlaTrafficStyleState;
HLA_GLOBAL_STATIC RTE_HLAR_TrafficStyleLearningState  ehlaTrafficStyleLearningState;

/******************/
/*   hla_tunnel   */
/******************/
/* Tunnel recognition input */
static HLATunnelInput_t             hlaTunnelInput;

HLA_GLOBAL_STATIC HLATunnelOutput_t hlaTunnelOutput;

/* Tunnel recognition output */
HLA_GLOBAL_STATIC RTE_HLAR_Tunnel   ehlaTunnelOutput;

/* Tunnel recognition internal data */
HLA_GLOBAL_STATIC HLATunnelData_t   hlaTunnelData;

/******************/
/* hla icons      */
/******************/
static hlaIcon_t         hlaIcon;

/******************/
/* analysis icons */
/******************/
HLA_GLOBAL_STATIC ARRAY  (HLAIconData_t, HLA_ICON_ANALYSIS_MAX_BOXES, hlaAnalysisIconData);
static            ARRAY2D(t_PixelData  , HLA_ICON_ANALYSIS_MAX_BOXES, HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y, hlaAnalysisIcon); /* icon memory */

/******************/
/* analysis data  */
/******************/
HLA_GLOBAL_STATIC HLAAnalysisData_t hlaAnalysisData;



/****************************/
/* Environmental brightness */
/****************************/
HLA_GLOBAL_STATIC HLABrightnessData_t   hlaBrightnessData;
/* output data */
static RTE_HLAR_BrightnessState         ehlaBrightnessOut;

HLA_GLOBAL_STATIC HLACamRot             hlaCamRot; /* the pinhole camera model */

/* information about precalculated image parameters from previous frame */
static HLAImagerPrevChar                hlaImagerPrevChar;

/* hot pixels */
HLA_GLOBAL_STATIC HLAHotPixelsData_t    hlaHotPixelsData;

static HLAWeatherData_t                 hlaWeatherData;

/*****************************************************************************
  external VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

static void HLAMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);

static void HLASetDebugOutputs(void);

static void HLASetDebugHighwayData( HLADebugHighwayData_t*          pDebugHighwayData,
                                    const HLAHighwayInternalData_t* pHighwayInternData
                                  );

static void HLAInitMainGlobals(void);

static void HLAOutputFillEnvironmentData( /* input data */
                                          const RTE_HLAR_BrightnessState   eBrightness,
                                          const RTE_HLAR_CityState         eCity,
                                          const RTE_HLA_TrafficStyle       eTrafficStyle,
                                          const RTE_HLAR_TrafficStyleState eTrafficStyleState,
                                          const RTE_HLAR_Tunnel            eTunnel,
                                          const HLA_t_Highway*             pHighway,
                                          const RTE_HLAR_WeatherState      eWeather,
                                          const boolean                    bRedReflectorArea,
                                          /* output data */
                                          HLA_t_EnvironmentData*           pOut
                                        );

static void HLAOutputFillData( /* input data */ 
                               const HLACameraData_t*                   pCamData,
                               const HLACamRot*                         pCamRot,
                               HLATrack_t*                              pTrack,
                               const uint8                              NumTracks,
                               const HLAR_t_RequiredInputs*             pIn, 
                               const RTE_HLA_TrafficStyle               eTrafficStyle,
                               const RTE_HLAR_TrafficStyleState         eTrafficStyleState,
                               const RTE_HLAR_TrafficStyleLearningState eTrafficStyleLearningState,
                               const HLATracking3DDataCali_t*           pDataCali,
                               /* output data */   
                               HLAR_t_ProvidedOutputs*                  pOut
                             );

static void HLAFillDebugOutput( /* input data */
                                const HLAR_t_RequiredInputs* pIn, 
                                /* output data */ 
                                      HLADebugOutputs_t*     pOut
                              );

static void HLASetInternalCali( HLATracking3DDataCali_t*  pDataCali,
                                const HLA_t_CaliOnline*   ps_CaliOnline,
                                const HLA_t_SensorAngles* ps_SensorAngles,
                                HLA_t_SystemInfo*         ps_SystemInfo,
                                const boolean             initSwitch
                              );

static void HLASetInternalHotPixels( HLAHotPixelsData_t*          pDataHotPixels, 
                                     const HLA_t_DefectPixelList* ps_DefectPixelList
                                   );

static void HLASegFillInputData( HLASegIn_t*                      pSegIn,
                                 const HLACameraData_t*           pCamData,
                                 const HLACamRot*                 pCamRot,
                                 const HLABrightnessParameters_t* pParBrightness,
                                 const RTE_HLAR_BrightnessState   eBrightnessState,
                                 const HLA_t_eMovementState       eMoveState,
                                 const uint8                      numTracks,
                                 const RTE_HLA_TestMode           TestMode
                               );

static void HLASetOdometer( HLAOdometer_t*       pOdo, 
                            float32              ddist, 
                            HLA_t_eMovementState eMoveState
                          );

static void HLAObjectSetTrackData( /* input */
                                   const HLATrack_t* pTrack,
                                   const HLACamRot*  pCamRot,
                                   /* output */ 
                                   HLA_t_Object*     pObject
                                 );

static void HLAObjectSetTrack( /* input */
                               HLATrack_t*        pTrack,
                               const uint8        NumTracks,
                               const HLACamRot*   pCamRot,
                               /* output */ 
                               HLA_t_Object*      pObject,
                               uint32*            pNumObjects,
                               uint32*            pNumVehicles
                              );


static void HLAInitDiagnosisDebugMsg( /* input */
                                      const HLASegOut_t*       pSegOut,
                                      /* output */
                                      HLA_t_DiagnosisDebugMsg* pDbgMsgOut
                                    );

static void HLAFillDiagnosisDebugMsg( const HLAR_t_RequiredInputs*   pReqIn,
                                      const HLATurnOffReason_t*      pTurnOffReason,
                                      const hlaIcon_t*               pIcon,
                                      const HLAAnalysisData_t*       pAnalysisData,
                                      const sint16                   dFrameCnt,
                                            HLA_t_DiagnosisDebugMsg* pDbgMsgOut
                                    );

static void HLAObjectFillList( /* input */
                               const AlgoCycleCounter_t       FrameCnt,
                               const AlgoCycleCounter_t       HLAR_Counter,
                               const AlgoDataTimeStamp_t      TimeStamp_HLA_us,
                               const HLACameraData_t*         pCamData,
                               const HLACamRot*               pCamRot,
                                     HLATrack_t*              pTrack,
                               const uint8                    NumTracks,
                               /* output */ 
                                     HLA_t_ObjectList*        pObject
                             );

static void HLASetImagerPar(const HLAR_t_RequiredInputs* ps_In);


/* **************************************************************************** 
  Functionname:     HLAInitMainGlobals()                                 */ /*!  
  Description:      Initializes all global variables of the HLA Main. 
                    This enables the simulation framework to re-init the HLA 
                    algo without reloading the DLL.
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */ 
static void HLAInitMainGlobals(void)
{

  (void)memset((void*)&hlaDebugOutputs, 0, sizeof(HLADebugOutputs_t));

  (void)memset((void*)&hlaOdometer, 0, sizeof(HLAOdometer_t));

  (void)memset((void*)&hlaHotPixelsData, 0, sizeof(HLAHotPixelsData_t));

  (void)memset(&hlaWeatherData, 0, sizeof(HLAWeatherData_t));
  
}

/* ****************************************************************************
  Functionname:     HLAObjectListSetTrackData                            */ /*!
  Description:      Builds a list of selected tracks (objects) 

  @param[in,out]    
  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           Marcus Brunn
**************************************************************************** */
static void HLAObjectSetTrackData( /* input */
                                   const HLATrack_t  *pTrack,
                                   const HLACamRot   *pCamRot,
                                   /* output */ 
                                   HLA_t_Object      *pObject
                                 )
{
  /* object id = array index in the track list */
  pObject->ui8_Id = pTrack->TrackID;

  /* object id of the pair light = array index in the track list: 255 = no pair */
  if(   (pTrack->TrackingStatus.isTrackedInPair)
     && (pTrack->dist_est_pair_link)
    )
  {
    pObject->ui8_IdPairLight = pTrack->dist_est_pair_link->TrackID;
  }
  else
  {
    pObject->ui8_IdPairLight = UI8_T_MAX;
  }

  /* number of lost updates (reset if track is updated)       */
  pObject->ui8_lost_time = pTrack->lost_time;

  /* ID of corresponding light = array index in RTE light list: 255 = no light reference */
  if(pTrack->light_ref != NULL)
  {
    pObject->ui8_LightID = pTrack->light_ref->LightID_RTE;
  }
  else
  {
    pObject->ui8_LightID = UI8_T_MAX;
  }

  /* age of the object */
  pObject->ui16_trace_time = pTrack->trace_time;

  /* blinding time of the preceding/ oncoming vehicle = cycles until object is detected as vehicle */
  pObject->ui16_blind_time = pTrack->trace_time_firstVehicleDetection;

  /* object x,y-position in the image (absolute image coordinates) */
  pObject->si16_xcenter = pTrack->xcenter; 
  pObject->si16_ycenter = pTrack->ycenter;


  /* track motion inside the image (without any ego motion compensation) */
  pObject->si16_delta_x    = pTrack->delta_x;
  pObject->si16_delta_y    = pTrack->delta_y;
  /* low pass filtered track motion inside the image (without any ego motion compensation) */
  pObject->si16_delta_x_lp = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, (sint16)CML_s_Round2Int(pTrack->delta_x_lp));
  pObject->si16_delta_y_lp = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, (sint16)CML_s_Round2Int(pTrack->delta_y_lp));
   

  /* object Status */
  pObject->s_Status.isPotentialVehicleOncoming1st = pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st;
  pObject->s_Status.isPotentialVehicleAhead1st    = pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st;
  pObject->s_Status.isPotentialVehicleOncoming2nd = pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming2nd;
  pObject->s_Status.isPotentialVehicleAhead2nd    = pTrack->statusAnalysisVehicle.isPotentialVehicleAhead2nd;
  pObject->s_Status.isVehicleOncoming             = pTrack->statusAnalysisVehicle.isVehicleOncoming;
  pObject->s_Status.isVehicleAhead                = pTrack->statusAnalysisVehicle.isVehicleAhead;
  pObject->s_Status.isTooBright                   = pTrack->statusAnalysisVehicle.isTooBright;
  pObject->s_Status.isRed                         = pTrack->statusAnalysisVehicle.isRed;
  pObject->s_Status.isPulsedLight                 = pTrack->statusAnalysisVehicle.isPulsedLight;
  pObject->s_Status.isRed2                        = pTrack->statusAnalysisVehicle.isRed2;
  pObject->s_Status.isMovingWhite                 = pTrack->statusAnalysisVehicle.isMovingWhite;
  pObject->s_Status.isMovingNonWhite              = pTrack->statusAnalysisVehicle.isMovingNonWhite;
  pObject->s_Status.isOncomingPair                = pTrack->statusAnalysisVehicle.isOncomingPair;
  pObject->s_Status.isPotentialVehicleHighProbable= pTrack->statusAnalysisVehicle.isPotentialVehicleHighProbable;
  pObject->s_Status.isStreetLamp                  = ((uint8) pTrack->idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE);
  pObject->s_Status.isAboveROI                    = pTrack->statusAnalysisMisc.isAboveROI;
  pObject->s_Status.isInfinite                    = pTrack->statusAnalysisMisc.isInfinite;
  pObject->s_Status.is3DCorrect                   = pTrack->statusAnalysisMisc.is3DCorrect;
  pObject->s_Status.isChainOfLight                = pTrack->statusAnalysisMisc.isChainOfLight;
  pObject->s_Status.isBrightObject                = pTrack->statusAnalysisMisc.isBrightObject;
  pObject->s_Status.isPotentialTruckLight         = pTrack->statusAnalysisMisc.isPotentialTruckLight;

  pObject->s_Status.isTrackedInPair               = pTrack->TrackingStatus.isTrackedInPair;
  pObject->s_Status.willBeRemoved                 = pTrack->TrackingStatus.willBeRemoved;
  pObject->s_Status.isOneToOneAssociation         = pTrack->TrackingStatus.isOneToOneAssociation;
  pObject->s_Status.trackerClassStatic            = (pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_STATIC);
  pObject->s_Status.trackerClassDynamic           = (pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_DYNAMIC);

  /* [lux] object intensity */
  pObject->ui16_Intensity_lux = pTrack->MaxInt;

  /* [ms] time to border */
  pObject->ui16_ttb_ms   = CML_Min(UI16_T_MAX, (uint16)(pTrack->ttb*1000.0f));
  pObject->ui16_ttb18_ms = CML_Min(UI16_T_MAX, (uint16)(pTrack->ttb18*1000.0f));

  /* object/ light distance in the world (AUTOSAR, xw=0: front axis) */

  /* safe lighting distance */
  pObject->s_LightDist.ui16_distMax_cm = pTrack->lightDist.distMax_cm;
  pObject->s_LightDist.ui16_distMin_cm = pTrack->lightDist.distMin_cm;

  /* vehicle ? */
  if(    (pTrack->statusAnalysisVehicle.isVehicleOncoming == 1)
      || (pTrack->statusAnalysisVehicle.isVehicleAhead == 1)
      || (pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1)
      || (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
    )
  {
    /* dynamic object */
    pObject->s_ObjectPos_xw.ui16_distMax_cm = pTrack->objectDist.distMax_cm;
    pObject->s_ObjectPos_xw.ui16_distMin_cm = pTrack->objectDist.distMin_cm;    
  }    
  else
  {
    /* standing object */
    pObject->s_ObjectPos_xw.ui16_distMax_cm = pTrack->xwmax100;
    pObject->s_ObjectPos_xw.ui16_distMin_cm = pTrack->xwmin100;
  }
  
  /* horizontal object angle in the world (AUTOSAR, xw=0: front axis) */
  {
    float32 xb, yb, xw, yw, zw;
    
    xb = pTrack->xcenter;
    yb = pTrack->ycenter;
    xw = 0.005f * ((float32)pObject->s_ObjectPos_xw.ui16_distMin_cm + (float32)pObject->s_ObjectPos_xw.ui16_distMax_cm); /* [m] 0.005 = 0.5/100cm */

    yw = HLACamRotGetywX (pCamRot, xw, xb, yb);
    pObject->si16_ObjectPos_yw_cm = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, (sint16)(yw * 100.0f));
    zw = HLACamRotGetzwX (pCamRot, xw, xb, yb);
    pObject->si16_ObjectPos_zw_cm = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, (sint16)(zw * 100.0f));

    if(xw > 0.01f)
    {
      pObject->f32_ObjectHorAng_rad = atanf(yw/ xw);
    }
    else
    {
      pObject->f32_ObjectHorAng_rad = 0.0f;
    }
  }
  
  /* first detection of track in the image (absolute coordinates) */
  pObject->si16_xcenter_FD = pTrack->xcenter_FD; 
  pObject->si16_ycenter_FD = pTrack->ycenter_FD;

  /* icon state */
  pObject->s_IconState.status.ledDetectionCalled = pTrack->iconState.status.ledDetectionCalled;
  pObject->s_IconState.status.streetLampDetectionCalled = pTrack->iconState.status.streetLampDetectionCalled;
  pObject->s_IconState.status.redLightDetectionCalled = pTrack->iconState.status.redLightDetectionCalled;
  pObject->s_IconState.status.skippedBadPosition = pTrack->iconState.status.skippedBadPosition;
  pObject->s_IconState.classCnt = pTrack->iconState.classCnt;
  pObject->s_IconState.classResultSum = pTrack->iconState.classResultSum;

  /* calculate existence probability */
  if(    (pTrack->statusAnalysisVehicle.isVehicleOncoming == 1)
      || (pTrack->statusAnalysisVehicle.isVehicleAhead == 1)
    )
  {
    /* vehicle detected */
    pObject->ui8_ExistenceProb = (uint8)CML_MinMax(0,100, (25*((pTrack->trace_time - pTrack->trace_time_firstVehicleDetection)+1)));
    /* vehicle gets lost */
    pObject->ui8_ExistenceProb = (uint8)CML_MinMax(0,100, (pObject->ui8_ExistenceProb - (10 * pTrack->lost_time))); 
    /* todo: add vehicle classification */
  }
  else
  {
    /* not detected as vehicle */
    pObject->ui8_ExistenceProb = 0;
  }
}


/* ****************************************************************************
  Functionname:     HLAObjectSetTrack                                    */ /*!
  Description:      Copies selected tracks into object list.

  @param[in,out]    
  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           Marcus Brunn
**************************************************************************** */
static void HLAObjectSetTrack( /* input */
                               HLATrack_t*      pTrack,
                               const uint8      NumTracks,
                               const HLACamRot* pCamRot,
                               /* output */ 
                               HLA_t_Object*    pObject,
                               uint32*          pNumObjects,
                               uint32*			pNumVehicles
                             )
{
  HLATrack_t    *pT;
  uint32 NumObjects  = 0;
  uint32 NumVehicles = 0;

 
  /* clear old list of objects */
  (void)memset((void*)pObject, 0, (sizeof(HLA_t_Object) * RTE_HLAR_OBJECT_LIST_LENGTH));
  
  if(NumTracks > 0)
  {
    /* 1. copy all vehicle tracks     */
    /* 2. copy all non vehicle tracks */
        
    /* 1. copy all vehicle tracks                     */
    pT    = pTrack;
    while(    (pT != NULL)
           && (NumObjects < RTE_HLAR_OBJECT_LIST_LENGTH)
         )
    {
      if(    (pT->statusAnalysisVehicle.isVehicleOncoming == 1)
          || (pT->statusAnalysisVehicle.isVehicleAhead == 1)
        )
      {
        /* add track to object list */
        HLAObjectSetTrackData( /* input */
                               pT,
                               pCamRot,
                               /* output */ 
                               pObject
                             );
        /* increment object counter/ pointer to next object */
        NumObjects++;
        NumVehicles++;
        pObject++;
      }
      pT = pT->next;
    }

    /* 2. copy all non vehicle tracks */
    pT    = pTrack;
    while(    (pT != NULL)
           && (NumObjects < RTE_HLAR_OBJECT_LIST_LENGTH)
         )
    {
      if(    (pT->statusAnalysisVehicle.isVehicleOncoming == 0)
          && (pT->statusAnalysisVehicle.isVehicleAhead == 0)
        )
      {
        /* add track to object list */
        HLAObjectSetTrackData( /* input */
                               pT,
                               pCamRot,
                               /* output */ 
                               pObject
                             );
        /* increment object counter/ pointer to next object */
        NumObjects++;
        pObject++;
      }
      pT = pT->next;
    }
  }

  /* copy number of object/ vehicles */  
  *pNumObjects  = NumObjects;
  *pNumVehicles = NumVehicles;
}

/* ****************************************************************************
  Functionname:     HLAInitDiagnosisDebugMsg                             */ /*!
  Description:      Init diagnosis debug message (64Bit struct).

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAInitDiagnosisDebugMsg( /* input */
                                      const HLASegOut_t *pSegOut,
                                      /* output */
                                      HLA_t_DiagnosisDebugMsg *pDbgMsgOut
                                    )
{
  HLA_t_DiagnosisDebugMsg  DbgMsg;

  DbgMsg.ui64_DiagnosisDebugMsg = 0;

  DbgMsg.HLAVersion.NextState  = (uint8)HLA_DDM_STATE__HLA_VERSION;
  DbgMsg.HLAVersion.eState      = (uint8)HLA_DDM_STATE__HLA_VERSION;
  
  DbgMsg.HLAVersion.HLAVersion = (HLA_SW_VERSION_NUMBER>>8);
  DbgMsg.HLAVersion.FrameCnt   = ((pSegOut->FrameCnt >> 1) & 0xF);

  *pDbgMsgOut = DbgMsg;
}

/* ****************************************************************************
  Functionname:     HLAFillDiagnosisDebugMsg                             */ /*!
  Description:      Fill diagnosis debug message (64Bit struct).

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFillDiagnosisDebugMsg( const HLAR_t_RequiredInputs*   pReqIn,
                                      const HLATurnOffReason_t*      pTurnOffReason,
                                      const hlaIcon_t*               pIcon,
                                      const HLAAnalysisData_t*       pAnalysisData,
                                      const sint16                   dFrameCnt,
                                            HLA_t_DiagnosisDebugMsg* pDbgMsgOut
                                    )
{
  uint32 TurnOffReason_First = pTurnOffReason->TurnOffReason_First;
  HLA_t_DiagnosisDebugMsg  DbgMsg;


  DbgMsg = *pDbgMsgOut;
  
  if(    (DbgMsg.HLAVersion.NextState == (uint8)HLA_DDM_STATE__HLA_VERSION)
      || (DbgMsg.HLAVersion.NextState == (uint8)HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON)
      || (DbgMsg.HLAVersion.NextState == (uint8)HLA_DDM_STATE__HB_ON)
    )
  {
    /* red reflector area */
    if(pAnalysisData->bRedReflectorArea == b_TRUE)
    {
      DbgMsg.HBon.RedReflectorArea = 1;
    }
    else
    {
      DbgMsg.HBon.RedReflectorArea = 0;
    }

    /* frame drop ? */
    if(dFrameCnt != HLA_NUM_EXPECTED_DFRAMES)
    {
      DbgMsg.HBon.FrameDrop = 1;
    }
    else
    {
      DbgMsg.HBon.FrameDrop = 0;
    }
       
    DbgMsg.HBon.Dummy1 = 0;
  }
  
  /* fill debug message */
  switch(DbgMsg.HLAVersion.NextState)
  {
    case HLA_DDM_STATE__HLA_VERSION:
      DbgMsg.HLAVersion.eState      = (uint8)HLA_DDM_STATE__HLA_VERSION;
      DbgMsg.HLAVersion.HLAVersion  = (HLA_SW_VERSION_NUMBER>>8);
      DbgMsg.HLAVersion.Dummy2      = 0;
      DbgMsg.HLAVersion.FrameCnt    = ((pReqIn->uiFrameCnt >> 1) & 0xF);
      break;
    case HLA_DDM_STATE__HB_ON:
      /* init HB on data */
      DbgMsg.Long.High = (DbgMsg.Long.High & 0xFFF00000u);
      DbgMsg.Long.Low  = 0u;
 
      DbgMsg.HBon.eState = (uint8)HLA_DDM_STATE__HB_ON;
      /* 1. Icon */
      if(   (pIcon->phlaIconList != NULL)
         && (pIcon->phlaIconList->pData != NULL)
         && (pIcon->phlaIconList->pData->pRef != NULL)
        )
      {
        HLATrack_t* pTLB = (HLATrack_t*)pIcon->phlaIconList->pData->pRef;
        
        DbgMsg.HBon.Icon1_Oncom_TooBright             = pTLB->statusAnalysisVehicle.isTooBright;
        DbgMsg.HBon.Icon1_Oncom_ContraMotionWhite     = pTLB->statusAnalysisVehicle.isMovingWhite;
        DbgMsg.HBon.Icon1_Oncom_OncomingPair          = pTLB->statusAnalysisVehicle.isOncomingPair;
        DbgMsg.HBon.Icon1_Oncom_CenterBright          = pTLB->statusAnalysisVehicle.isCenterBright;
        DbgMsg.HBon.Icon1_Oncom_ExtremeBright         = pTLB->statusAnalysisVehicle.isExtremeBright;
        DbgMsg.HBon.Icon1_Oncom_LateralBright         = pTLB->statusAnalysisVehicle.isLateralBright;
        DbgMsg.HBon.Icon1_Oncom_Other                 = 0u;

        DbgMsg.HBon.Icon1_Ahead_RedLight              = pTLB->statusAnalysisVehicle.isRed;
        DbgMsg.HBon.Icon1_Ahead_RedLight2             = pTLB->statusAnalysisVehicle.isRed2;
        DbgMsg.HBon.Icon1_Ahead_PulsedLight           = pTLB->statusAnalysisVehicle.isPulsedLight;
        DbgMsg.HBon.Icon1_Ahead_ContraMotionNonWhite  = pTLB->statusAnalysisVehicle.isMovingNonWhite;
        DbgMsg.HBon.Icon1_Ahead_Other                 = 0;

        DbgMsg.HBon.Icon1_result                      = pTLB->iconState.resultInfo.result;
        DbgMsg.HBon.Icon1_result_Unused               = 0u;
 
        DbgMsg.HBon.Icon1_Status_ledDetectionCalled         = pTLB->iconState.status.ledDetectionCalled;     
        DbgMsg.HBon.Icon1_Status_streetLampDetectionCalled  = pTLB->iconState.status.streetLampDetectionCalled;
        DbgMsg.HBon.Icon1_Status_redLightDetectionCalled    = pTLB->iconState.status.redLightDetectionCalled;
               
        if(pTLB->iconState.classResultSum < 0)
        {
          /* no vehicle */
          uint16 classResultSum = (uint16)(-pTLB->iconState.classResultSum);
          
          /* uint16 is always >= 0 */
          classResultSum = CML_Min(127u, classResultSum);
                    
          DbgMsg.HBon.Icon1_classResult_Vehicle = 0u;
          DbgMsg.HBon.Icon1_classResult_Sum     = classResultSum;
        }
        else
        {
          /* vehicle */
          uint16 classResultSum = (uint16)(pTLB->iconState.classResultSum);

          /* uint16 is always >= 0 */
          classResultSum = CML_Min(127u, classResultSum);

          DbgMsg.HBon.Icon1_classResult_Vehicle = 1u;
          DbgMsg.HBon.Icon1_classResult_Sum     = classResultSum;
        }
      }
      
      /* 2. Icon */
      if(   (pIcon->phlaIconList != NULL)
         && (pIcon->phlaIconList->pNext != NULL)
         && (pIcon->phlaIconList->pNext->pData != NULL)
         && (pIcon->phlaIconList->pNext->pData->pRef != NULL)
        )
      {
        HLATrack_t* pTLB = (HLATrack_t*)pIcon->phlaIconList->pNext->pData->pRef;

        DbgMsg.HBon.Icon2_Oncom_TooBright             = pTLB->statusAnalysisVehicle.isTooBright;
        DbgMsg.HBon.Icon2_Oncom_ContraMotionWhite     = pTLB->statusAnalysisVehicle.isMovingWhite;
        DbgMsg.HBon.Icon2_Oncom_OncomingPair          = pTLB->statusAnalysisVehicle.isOncomingPair;
        DbgMsg.HBon.Icon2_Oncom_CenterBright          = pTLB->statusAnalysisVehicle.isCenterBright;
        DbgMsg.HBon.Icon2_Oncom_ExtremeBright         = pTLB->statusAnalysisVehicle.isExtremeBright;
        DbgMsg.HBon.Icon2_Oncom_LateralBright         = pTLB->statusAnalysisVehicle.isLateralBright;
        DbgMsg.HBon.Icon2_Oncom_Other                 = 0u;

        DbgMsg.HBon.Icon2_Ahead_RedLight              = pTLB->statusAnalysisVehicle.isRed;
        DbgMsg.HBon.Icon2_Ahead_RedLight2             = pTLB->statusAnalysisVehicle.isRed2;
        DbgMsg.HBon.Icon2_Ahead_PulsedLight           = pTLB->statusAnalysisVehicle.isPulsedLight;
        DbgMsg.HBon.Icon2_Ahead_ContraMotionNonWhite  = pTLB->statusAnalysisVehicle.isMovingNonWhite;
        DbgMsg.HBon.Icon2_Ahead_Other                 = 0u;

        DbgMsg.HBon.Icon2_result                      = pTLB->iconState.resultInfo.result;
        DbgMsg.HBon.Icon2_result_Unused               = 0u;

        DbgMsg.HBon.Icon2_Status_ledDetectionCalled         = pTLB->iconState.status.ledDetectionCalled;     
        DbgMsg.HBon.Icon2_Status_streetLampDetectionCalled  = pTLB->iconState.status.streetLampDetectionCalled;
        DbgMsg.HBon.Icon2_Status_redLightDetectionCalled    = pTLB->iconState.status.redLightDetectionCalled;
        
        if(pTLB->iconState.classResultSum < 0)
        {
          /* no vehicle */
          uint16 classResultSum = (uint16)(-pTLB->iconState.classResultSum);

          /* uint16 is always >= 0 */
          classResultSum = CML_Min(127u, classResultSum);

          DbgMsg.HBon.Icon2_classResult_Vehicle = 0u;
          DbgMsg.HBon.Icon2_classResult_Sum     = classResultSum;
        }
        else
        {
          /* vehicle */
          uint16 classResultSum = (uint16)(pTLB->iconState.classResultSum);

          /* uint16 is always >= 0 */
          classResultSum = CML_Min(127u, classResultSum);

          DbgMsg.HBon.Icon2_classResult_Vehicle = 1u;
          DbgMsg.HBon.Icon2_classResult_Sum     = classResultSum;
        }
      }
      break;
    case HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON:
      DbgMsg.HLARInitialTurnOffReason.eState     = (uint8)HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON;
      DbgMsg.HLARInitialTurnOffReason.FrameCnt  = ((pReqIn->uiFrameCnt >> 1) & 0xF);
      DbgMsg.HLARInitialTurnOffReason.Dummy2    = 0;

      /* oncoming vehicle */
      DbgMsg.HLARInitialTurnOffReason.Oncom_TooBright                 = (((TurnOffReason_First & HLA_TOR__ONCOM__TOO_BRIGHT) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Oncom_ContraMotionWhite         = (((TurnOffReason_First & HLA_TOR__ONCOM__CONTRA_MOTION_WHITE) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Oncom_OncomingPair              = (((TurnOffReason_First & HLA_TOR__ONCOM__ONCOMING_PAIR) > 0)? 1: 0);            
      DbgMsg.HLARInitialTurnOffReason.Oncom_CenterBright              = (((TurnOffReason_First & HLA_TOR__ONCOM__CENTER_BRIGHT) > 0)? 1: 0);            
      DbgMsg.HLARInitialTurnOffReason.Oncom_ExtremeBright             = (((TurnOffReason_First & HLA_TOR__ONCOM__EXTREME_BRIGHT) > 0)? 1: 0);           
      DbgMsg.HLARInitialTurnOffReason.Oncom_LateralBright             = (((TurnOffReason_First & HLA_TOR__ONCOM__LATERAL_BRIGHT) > 0)? 1: 0);          

      DbgMsg.HLARInitialTurnOffReason.Oncom_Unused                    = 0;
                  
      DbgMsg.HLARInitialTurnOffReason.Oncom_SuddenlyAppearingVehicle  = (((TurnOffReason_First & HLA_TOR__ONCOM__SUDDENLYAPPEARINGVEHICLE) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Oncom_ClassResultReached        = (((TurnOffReason_First & HLA_TOR__ONCOM__CLASSRESULTREACHED) > 0)? 1: 0);   
    
      /* preceding traffic */
      DbgMsg.HLARInitialTurnOffReason.Ahead_RedLight                = (((TurnOffReason_First & HLA_TOR__AHEAD__RED_LIGHT) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_RedLight2               = (((TurnOffReason_First & HLA_TOR__AHEAD__RED_LIGHT2) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_PulsedLight             = (((TurnOffReason_First & HLA_TOR__AHEAD__PULSED_LIGHT) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_ContraMotionNonWhite    = (((TurnOffReason_First & HLA_TOR__AHEAD__CONTRA_MOTION_NONWHITE) > 0)? 1: 0);

      DbgMsg.HLARInitialTurnOffReason.Ahead_Unused                  = 0;                  

      DbgMsg.HLARInitialTurnOffReason.Ahead_Overtaker               = (((TurnOffReason_First & HLA_TOR__AHEAD__OVERTAKER) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_DriveDistReached        = (((TurnOffReason_First & HLA_TOR__AHEAD__DRIVEDISTREACHED) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_DriveDistDynamicReached = (((TurnOffReason_First & HLA_TOR__AHEAD__DRIVEDISTDYNAMICREACHED) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_DriveDistPairReached    = (((TurnOffReason_First & HLA_TOR__AHEAD__DRIVEDISTPAIRREACHED) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_SuddenlyAppearingVehicle= (((TurnOffReason_First & HLA_TOR__AHEAD__SUDDENLYAPPEARINGVEHICLE) > 0)? 1: 0);
      DbgMsg.HLARInitialTurnOffReason.Ahead_ClassResultReached      = (((TurnOffReason_First & HLA_TOR__AHEAD__CLASSRESULTREACHED) > 0)? 1: 0);
      break;
    case HLA_DDM_STATE__HLAF_TURN_OFF_REASON:
    case HLA_DDM_STATE__HLAF_KEEP_OFF_REASON:
    default:
      /* do nothing */
      /* HLAF will fill the debug message */
      break;  
  }

  *pDbgMsgOut = DbgMsg;
}

/* ****************************************************************************
  Functionname:     HLAObjectFillList                                    */ /*!
  Description:      Fill object list.

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAObjectFillList( /* input */
                               const AlgoCycleCounter_t       FrameCnt,
                               const AlgoCycleCounter_t       HLAR_Counter,
                               const AlgoDataTimeStamp_t      TimeStamp_HLA_us,
                               const HLACameraData_t*         pCamData,
                               const HLACamRot*               pCamRot,
                                     HLATrack_t*              pTrack,
                               const uint8                    NumTracks,
                               /* output */ 
                                     HLA_t_ObjectList*        pObject
                             )
{
  /* object list version number */
  pObject->ui32_Version             = HLA_OBJECT_LIST_VERSION_NUMBER;
  /* HLA Software version number */
  pObject->ui32_HLA_SWVersionNumber = HLA_SW_VERSION_NUMBER;
  /* Frame counter */
  pObject->uiFrameCnt            = FrameCnt; 
  /* HLAR cycle counter */
  pObject->uiHLAR_Cnt            = HLAR_Counter;
  /* [us] HLA Timestamp, hla input data */
  pObject->uiTimeStamp_HLA_us    = TimeStamp_HLA_us; 
  
  /* position of the ROI = HLA Roi + Above Roi (absolute imager coordinates) */
  pObject->s_ObjectRoi.ui16_RoiX1 = pCamData->RoiX1;
  pObject->s_ObjectRoi.ui16_RoiX2 = pCamData->RoiX2;
  pObject->s_ObjectRoi.ui16_RoiY1 = pCamData->RoiY1;
  pObject->s_ObjectRoi.ui16_RoiY2 = pCamData->RoiY2;
  pObject->s_ObjectRoi.ui16_RoiYu = pCamData->RoiYu;

  /* focus of expansion */
  pObject->s_ObjectFOE.ui16_X = pCamData->FOE_x;
  /* ~CodeReview ~ID:291358c0aab1f618abb2e1b105ee1111 ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:double semcolumn */
  pObject->s_ObjectFOE.ui16_Y = pCamData->FOE_y;;

  /* copy selected tracks into object list */
  HLAObjectSetTrack( /* input */
                     pTrack,
                     NumTracks,
                     pCamRot,
                     /* output */ 
                     &pObject->as_Object[0],
                     &pObject->ui32_NumObjects,
                     &pObject->ui32_NumVehicles
                   );
}


/* ****************************************************************************
  Functionname:     HLAOutputFillEnvironmentData                         */ /*!
  Description:      Fill environment output data of HLAR.

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAOutputFillEnvironmentData( /* input data */
                                          const RTE_HLAR_BrightnessState   eBrightness,
                                          const RTE_HLAR_CityState         eCity,
                                          const RTE_HLA_TrafficStyle       eTrafficStyle,
                                          const RTE_HLAR_TrafficStyleState eTrafficStyleState,
                                          const RTE_HLAR_Tunnel            eTunnel,
                                          const HLA_t_Highway              *pHighway,
                                          const RTE_HLAR_WeatherState      eWeather,
                                          const boolean                    bRedReflectorArea,
                                          /* output data */
                                          HLA_t_EnvironmentData            *pOut
                                      )
{
  pOut->e_Brightness        = eBrightness;
  pOut->e_City              = eCity;
  pOut->e_TrafficStyle      = eTrafficStyle;
  pOut->e_TrafficStyleState = eTrafficStyleState;
  pOut->e_Tunnel            = eTunnel;
  pOut->s_Highway           = *pHighway;
  pOut->e_Weather           = eWeather;
  if(bRedReflectorArea == b_TRUE)
  {
    pOut->e_RedReflectorArea = RTE_HLAR_RED_REFLECTOR_AREA_DTCD;
  }
  else
  {
    pOut->e_RedReflectorArea = RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD;
  }
}


/* ****************************************************************************
  Functionname:     HLAOutputFillData */ /*!
  Description:      Fill output data of HLAR.

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAOutputFillData( /* input data */
                               const HLACameraData_t*                   pCamData,
                               const HLACamRot*                         pCamRot,
                               HLATrack_t*                              pTrack,
                               const uint8                              NumTracks,
                               const HLAR_t_RequiredInputs*             pIn, 
                               const RTE_HLA_TrafficStyle               eTrafficStyle,
                               const RTE_HLAR_TrafficStyleState         eTrafficStyleState,
                               const RTE_HLAR_TrafficStyleLearningState eTrafficStyleLearningState,
                               const HLATracking3DDataCali_t*           pDataCali,
                               /* output data */ 
                               HLAR_t_ProvidedOutputs*                  pOut
                             )
{
  float32 olcal_pitch,olcal_yaw,olcal_roll;
  /* ~CodeReview ~ID:d11f318f0945691ec4523606c0dfdace ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:120938, commented out code. Can be removed?\$r\$n */
  /*float32 eolcal_pitch,eolcal_yaw,eolcal_roll;*/

  /* copy interface version number, HLA/ HLAR SW version number and frame counter */
  /* into output data */
  pOut->ui32_InterfaceVersionNumber = HLAR_OUT_INTERFACE_VERSION_NUMBER;
  pOut->ui32_HLA_SWVersionNumber    = HLA_SW_VERSION_NUMBER;
  pOut->ui32_HLAR_SWVersionNumber   = HLAR_SW_VERSION_NUMBER;
  pOut->uiFrameCnt               = hlaSegOut.FrameCnt;
  
  /* set HLA and image timestamps */
  pOut->uiTimeStamp_HLA_us       = pIn->uiTimeStamp_HLA_us;
  pOut->uiTimeStamp_Image_us     = pIn->uiTimeStamp_Image_us;
    

  /* copy fingerprint */
  pOut->s_Fingerprint               = hlaSegOut.Fingerprint;

  /* copy counter to output struct */
  pOut->uiHLAR_Cnt = HLAR_Cnt;
  pOut->uiHLAS_Cnt = hlaSegOut.HLAS_Cnt;

  /* get on-line calibration in IO style*/
  {
    /* calc. angles for cali data  */
    /* rotation of coordinate system */
    olcal_pitch = - pDataCali->cal_pitch - CML_Deg2Rad(90.0f);
    olcal_roll  = + pDataCali->cal_roll;
    olcal_yaw   = + pDataCali->cal_yaw + CML_Deg2Rad(90.0f);

    /* set CaliOnline: angle variations from the end-of line calibration */
    pOut->s_CaliOnline.f32_Pitch = olcal_pitch; /*- pIn->s_Par.s_SensorAngles.f32_Pitch;*/
    pOut->s_CaliOnline.f32_Roll  = olcal_roll;  /*- pIn->s_Par.s_SensorAngles.f32_Roll;*/
    pOut->s_CaliOnline.f32_Yaw   = olcal_yaw;   /*- pIn->s_Par.s_SensorAngles.f32_Yaw;*/

    /* set CaliOnline: update odometer */
    pOut->s_CaliOnline.f32_OdoCali_m = pDataCali->odometerOnLineCaliM;
  }

  /* set TrafficStyle: update TrafficStyleLearningState */
  pOut->s_TrafficStyle.e_TrafficStyleLearningState = eTrafficStyleLearningState;

  /* set TrafficStyle: update TrafficStyleLastLearned */
  if( (eTrafficStyleState == RTE_HLAR_TRAFFIC_STATE_LEARN) || (eTrafficStyleState == RTE_HLAR_TRAFFIC_STATE_LAST_LEARNED) )
  {
    pOut->s_TrafficStyle.e_TrafficStyleLastLearned = eTrafficStyle;
  }
  else
  {
    pOut->s_TrafficStyle.e_TrafficStyleLastLearned = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
  }

  /* set HOT PIXELS output pointer */
  pOut->ps_DefectPixelList = &(hlaHotPixelsData.hlaDefectPixelList);

  /* fill object list */
  HLAObjectFillList( /* input */
                     pOut->uiFrameCnt,
                     pOut->uiHLAR_Cnt,
                     pOut->uiTimeStamp_HLA_us,
                     pCamData,
                     pCamRot,
                     pTrack,
                     NumTracks, 
                     /* output */ 
                     &pOut->s_ObjectList
                   );

}

/* ****************************************************************************
  Functionname:     HLAFillDebugData */ /*!
  Description:      Fill debug output data of HLAR.

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFillDebugOutput( /* input data */
                                const HLAR_t_RequiredInputs* pIn, 
                                /* output data */ 
                                      HLADebugOutputs_t*     pOut
                              )
{
  /* copy interface version number, HLA/ HLAR SW version number and frame counter */
  /* into output data */
  pOut->InterfaceVersionNumber = HLAD_OUT_INTERFACE_VERSION_NUMBER;
  pOut->HLA_SWVersionNumber    = HLA_SW_VERSION_NUMBER;
  pOut->HLAR_SWVersionNumber   = HLAR_SW_VERSION_NUMBER;
  pOut->FrameCnt               = hlaSegOut.FrameCnt;
  
  /* set HLA and image timestamps */
  pOut->TimeStamp_HLA_us       = pIn->uiTimeStamp_HLA_us;
  pOut->TimeStamp_Image_us     = pIn->uiTimeStamp_Image_us;
    
  /* copy counter to output struct */
  pOut->HLAR_Cnt = HLAR_Cnt;
  pOut->HLAS_Cnt = hlaSegOut.HLAS_Cnt;
 
}


/* **************************************************************************** 
  Functionname:     HLASetInternalCali */ /*!
  Description:      Set internal cali data from signal inputs

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLASetInternalCali( HLATracking3DDataCali_t  *pDataCali,
                                const HLA_t_CaliOnline   *ps_CaliOnline,
                                const HLA_t_SensorAngles *ps_SensorAngles,
                                HLA_t_SystemInfo         *ps_SystemInfo,
                                const boolean            initSwitch
                              )
{
  float32 Pitch = 0.f;
  float32 Yaw   = 0.f;
  float32 Roll  = 0.f;
    
  /* get calibration data (our online calibration and lane calibration (stored in signals->sensorAngles) */
  /* from input data and compare both fill the hlaCaliData struct                                        */
  /* ps_CaliOnline is coming from our NVM values through SW */
  /* ps_SensorAngles is coming from Lane Online Calibration through SW */

  /* J.Häfer: No Possible Side Effect */
  /* PRQA S 3415 5 */
  if (   (   (    (CML_f_IsZero(ps_CaliOnline->f32_Pitch))
               && (CML_f_IsZero(ps_CaliOnline->f32_Yaw))
               && (CML_f_IsZero(ps_CaliOnline->f32_Roll))
             )
          && (CML_f_IsZero(ps_CaliOnline->f32_OdoCali_m))
         )
      || (initSwitch)
     )
  {
    /* Case ps_CaliOnline and Odometer contains zeros no calibration has been done => use ps_SensorAngles */
    Pitch = ps_SensorAngles->f32_Pitch;
    Yaw   = ps_SensorAngles->f32_Yaw;
    Roll  = ps_SensorAngles->f32_Roll;
  }
  else
  {
#if 1
    Pitch = ps_CaliOnline->f32_Pitch;
    Yaw   = ps_CaliOnline->f32_Yaw;
    Roll  = ps_CaliOnline->f32_Roll;
#else
    Pitch = ps_SensorAngles->f32_Pitch;
    Yaw   = ps_SensorAngles->f32_Yaw;
    Roll  = ps_SensorAngles->f32_Roll;
#endif
    /* Case ps_SensorAngles are more than 1.0° different than ps_Calibration values => print an error */
    /* J.Häfer: No Possible Side Effect */
    /* PRQA S 3415 3 */
    if (   (CML_f_Abs(ps_CaliOnline->f32_Pitch - ps_SensorAngles->f32_Pitch) > CML_Deg2Rad(1.0f))
        || (CML_f_Abs(ps_CaliOnline->f32_Yaw   - ps_SensorAngles->f32_Yaw)   > CML_Deg2Rad(1.0f))
        || (CML_f_Abs(ps_CaliOnline->f32_Roll  - ps_SensorAngles->f32_Roll)  > CML_Deg2Rad(1.0f))
       )
    {
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_DIFF_TO_LANE_CALI;
    }
    
    /* Case ps_CaliOnline out of range => use ps_SensorAngles */
    if (/* online cali is now (MFC4xx) in absolute angles, and the default angle could be above 5° (e.g. truck)
           todo -> we have to check the delta to the default angle   
           (fABS(ps_CaliOnline->f32_Pitch) > DEG2RAD(5.0f)) 
        ||*/
           /* J.Häfer: No Possible Side Effect */
           /* PRQA S 3415 2 */
           (CML_f_Abs(ps_CaliOnline->f32_Yaw)   > CML_Deg2Rad(5.0f))
        || (CML_f_Abs(ps_CaliOnline->f32_Roll)  > CML_Deg2Rad(5.0f))
       )
    {
      Pitch = ps_SensorAngles->f32_Pitch;
      Yaw   = ps_SensorAngles->f32_Yaw;
      Roll  = ps_SensorAngles->f32_Roll;

      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
      ps_SystemInfo->errors.error[HLA_ERRORID_CALIBRATION].optData = HLA_ERRORID_OPTDATA_CALIBRATION_ONLINE_CALI_OUT_OF_RANGE;
    }
  }
  
  /* calc. angles for hlaCamParam  */
  /* rotation of coordinate system */
  pDataCali->cal_pitch = - Pitch - CML_Deg2Rad(90.0f);
  pDataCali->cal_roll  =   Roll;
  pDataCali->cal_yaw   =   Yaw   - CML_Deg2Rad(90.0f);

  /* update online cali odometer */
  pDataCali->odometerOnLineCaliM = ps_CaliOnline->f32_OdoCali_m;
}


/* **************************************************************************** 
  Functionname:     HLASetInternalHotPixels */ /*!
  Description:      Set internal hot pixel data from signal inputs

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLASetInternalHotPixels(
                           HLAHotPixelsData_t           *pDataHotPixels, 
                           const HLA_t_DefectPixelList  *ps_DefectPixelList
                           )
{
  /*----------------------------------------------------------------*/
  /* copy HOT PIXELS entry list */
  pDataHotPixels->hlaDefectPixelList = (*ps_DefectPixelList);
}


/* ****************************************************************************
  Functionname:     HLASegFillInputData */ /*!
  Description:      Fill segmentation input data for next segmentation

  @param[in]        HLASegIn_t *pSegIn          input data for segmentation
                    HLACameraData_t *pCamData   camera data

  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegFillInputData( HLASegIn_t                      *pSegIn,
                                 const HLACameraData_t           *pCamData,
                                 const HLACamRot                 *pCamRot,
                                 const HLABrightnessParameters_t *pParBrightness,
                                 const RTE_HLAR_BrightnessState   eBrightnessState,
                                 const HLA_t_eMovementState       eMoveState,
                                 const uint8                      numTracks,
                                 const RTE_HLA_TestMode           TestMode
                               )
{
  /* set sub image parameters */
  pSegIn->SubImage_EndRow[0] = pCamData->RoiYu;
  pSegIn->SubImage_EndRow[1] = pCamData->RoiYu + (uint16)(pParBrightness->SubImage.EndRow1_factor * (pCamData->FOE_y - pCamData->RoiYu));
  pSegIn->SubImage_EndRow[2] = (uint16)CML_u_Round2Uint(HLACamRotGetyb(pCamRot, pParBrightness->SubImage.xw_EndRow2_m, 0.0f, 0.0f));
  pSegIn->SubImage_EndRow[3] = (uint16)CML_u_Round2Uint(HLACamRotGetyb(pCamRot, pParBrightness->SubImage.xw_EndRow3_m, 0.0f, 0.0f));
  pSegIn->SubImage_EndRow[4] = (uint16)CML_u_Round2Uint(HLACamRotGetyb(pCamRot, pParBrightness->SubImage.xw_EndRow4_m, 0.0f, 0.0f));

  /* set current brightness state */
  pSegIn->eBrightnessState = eBrightnessState;
  
  /* set move state */
  pSegIn->eMoveState = eMoveState;

  /* copy number tracks */
  pSegIn->numTracks_LastFrame = numTracks;
  
  /* copy TestMode */
  pSegIn->TestMode = TestMode;
}


/* ****************************************************************************
  Functionname:     HLAFillOdometer */ /*!
  Description:      

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASetOdometer(HLAOdometer_t *pOdo, float32 ddist, HLA_t_eMovementState eMoveState)
{
  if(    (eMoveState == HLA_MOVE_STATE_FWD)
      || (eMoveState == HLA_MOVE_STATE_REV)
    )
  {
    pOdo->OdometerAll_m += ddist;

    /* check for transition from standstill to moving */
    if(pOdo->bStandstill == TRUE)
    {
      /* standstill -> moving */
      /* reset standstill odometer */
      pOdo->OdometerStandstill_m = 0;
      pOdo->bStandstill = FALSE;
    }
    else
    {
      pOdo->OdometerStandstill_m += ddist;  
    }
    
  }
  else if(eMoveState == HLA_MOVE_STATE_STAND_STILL)
  {
    pOdo->bStandstill = TRUE;
  }
  else
  {
    /* Do nothing! */
  }
}
/* ****************************************************************************
  Functionname:     HLAR_v_Init */ /*!
  Description:      Initializes the HLAR-component (after bootup).

  @param[in]        HLAR_t_RequiredInputs  *pIn    required input for HLAR
  @param[in,out]    HLARHistory_t         *pHist  history data for HLAR
  @param[out]       HLARProvidedOutputs_t *pOut   provided output from HLAR

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAR_v_Init( const HLAR_t_RequiredInputs  *ps_In,
                  HLAR_t_ProvidedOutputs       *ps_Out,
                  RTE_HLA_Seg_LightList_t      *ps_SegLightList,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  t_PixelData                  *pImg,
                  const AS_t_ServiceFuncts     *Services
                )
{
  uint32        HWTime_us;

  if (b_TRUE == HLAErrorCheck_NullPointer(ps_In, ps_Out, pImg, Services, ps_SystemInfo))
  {
    /* fatal Error */
    ps_SystemInfo->state = HLA_SYSTEMSTATE_NOT_INITIALIZED;
  }
  else
  {
    /* get current HW time */
    HWTime_us = Services->pfGetTimestampuS32();
 
    /* --------------------------------------------------------------*/
    /*    GLOBAL VAR INIT     */

    /* reset HLAR call counter */
    HLAR_Cnt = 0;
    /* reset frame counter of previous frame to current frame */
    hlaFrameCntPrevFrame = ps_In->uiFrameCnt;
    /* init the error handler */
    HLAErrorCheck_Init();
  

    /* set the system state and call error checks which are relevant for this init cycle */
    
    /* ~CodeReview ~ID:77fe65bd7b7205e802e2d9577e72530b ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:(4 times) 121103, error information from function not tested. (HLA error RTE_HLA_LTM_FAULT, HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED, etc not handled ) */
    (void)HLAErrorCheck_Vehicle(ps_SystemInfo, &ps_In->s_Sig.s_HeadlightState);
    (void)HLAErrorCheck_ImageData(ps_SystemInfo, &ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic, &ps_In->s_Par.s_CameraParameter);
    (void)HLAErrorCheck_Input(ps_In, &ps_In->s_Sig.s_MotionState, &ps_In->s_Sig.s_Avl, ehlaBrightnessOut, HLA_NUM_EXPECTED_DFRAMES, ps_SystemInfo);
    (void)HLAErrorCheck_Fatal(ps_SystemInfo, &hlaHotPixelsData.hlaDefectPixelList);
    

    if(    (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status == HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED)
        && (   (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_LENSCENTER)
            || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_FOCAL_LENGTH)
            || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_KNEELUX)
            || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_SATLUX)
           )
      )
    {
      /* fatal error */
      ps_SystemInfo->state = HLA_SYSTEMSTATE_NOT_INITIALIZED;
    }
    else
    {
      ps_SystemInfo->state = HLA_SYSTEMSTATE_RUNNING;

      /* --------------------------------------------------------------*/
      /*    STATIC INIT     */
      /* hla main */
      HLAInitMainGlobals();

      /* hla camera */
      HLAInitCamera(&hlaCamData, &hlaCamRot);
      /* init environmental brightness data */
      HLABrightnessInit(&hlaBrightnessData, &ehlaBrightnessOut);  
      /* hla hot pixels process */
      HLAHotPixelsInit(&hlaHotPixelsData);
      /* init hla icon only @bootup */
      HLAIconInit(&hlaIcon, pImg);
      /* init analysis */
      HLAAnalysisInit(ps_In, &hlaAnalysisIconData[0], &hlaAnalysisIcon[0][0], &hlaAnalysisData);
      /* Initialization for Highway Detection */
      HLAHighwayInit(&hlaHighwayInternalData,&hlaHighwayOutput);
      /* Initialization for street lamp analysis */
      HLAAnalysisStreetLampsInit( &hlaSLInput,
                                  &hlaFreeStreetLampsBuffer[0],
                                  &hlaTracking3DParameters
                                );
      /* pre-init city detection data */
      HLACityInit(&hlaCityData, &ehlaCityOutput);

      /* pre-init traffic style data */
      HLATrafficStyleInit(ps_In, &ehlaTrafficStyle, &ehlaTrafficStyleState, &ehlaTrafficStyleLearningState, &hlaTrafficStyleHist);

      /* pre-init tunnel detection data */
      HLATunnelDetectionInit(&hlaTunnelData, &hlaTunnelOutput, &ehlaTunnelOutput);

      /* --------------------------------------------------------------*/
      /*    DYNAMIC INIT  (USING FUNCTION INPUTS)  */

      /* init imager response curve data */
      HLAImager_InitPar(&ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic);

      /* invalidate pre-calculated imager parameters */
      (void)memset(&hlaImagerPrevChar, 0, sizeof(HLAImagerPrevChar));

      /* Initialization for Tracking 3D */
      HLATracking3DInit(  &hlaTrackOut, 
                          &hlaTrackData, 
                          &ps_In->s_Par.s_CameraParameter.s_FocalLength, 
                          &ps_In->s_Par.s_CameraParameter.s_LensCenter, 
                          &ps_In->s_Par.s_SensorSocket, 
                          &hlaTracking3DParameters,
                          &ps_In->s_Par.s_HlarPar
                       );

      /* set internal cali data */
      HLASetInternalCali( &hlaTrackOut.dataCali, 
                          &ps_In->s_Sig.s_CaliOnline, 
                          &ps_In->s_Par.s_SensorAngles, 
                          ps_SystemInfo, 
                          b_TRUE
                        );

      /* set internal hotpixels */
      HLASetInternalHotPixels( &hlaHotPixelsData, 
                               &ps_In->s_Sig.s_DefectPixelList
                             ); 

      /* update camera */
      HLAUpdateCamera( ps_In, 
                       &hlaTrackOut.dataCali, 
                       TRUE, 
                       0, 
                       &hlaCamData, 
                       &hlaCamRot
                     );

      /* initialize ROI */
      HLARUpdateRoi( ps_In, 
                     &hlaCamData, 
                     &hlaCamRot, 
                     ps_SystemInfo
                   );

      /* initialize the segmentation. */
      HLASegmentationInit( &hlaSegLineRegionBuffer,
                           &hlaSegLightBuffer,
                           &hlaSegData,
                           &hlaSegOut,
                           ps_SegLightList /* RTE Out */
                          );

      /* fill segmentation input data */
      HLASegFillInputData( &hlaSegIn,
                           &hlaCamData,
                           &hlaCamRot,
                           &hlaBrightnessParameters,
                           ehlaBrightnessOut,
                           ps_In->s_Sig.s_MotionState.e_MoveState,
                           hlaTrackOut.numTracks,
                           ps_In->s_Par.s_HlaPar.AlgoCfg.TestMode
                         );

      /* --------------------------------------------------------------*/
      /*    FUNCTION OUTPUT UPDATE */
        
 
      /* fill output/ history data */
      HLAOutputFillData( /* input data */
                         &hlaCamData,
                         &hlaCamRot,
                         hlaTrackOut.pTrack,
                         hlaTrackOut.numTracks,
                         ps_In,
                         ehlaTrafficStyle,
                         ehlaTrafficStyleState,
                         ehlaTrafficStyleLearningState,
                         &hlaTrackOut.dataCali,
                         /* output data */
                         ps_Out
                       );

      HLAOutputFillEnvironmentData( /* input data */
                                    ehlaBrightnessOut,
                                    ehlaCityOutput,
                                    ehlaTrafficStyle,
                                    ehlaTrafficStyleState,
                                    ehlaTunnelOutput,
                                    &hlaHighwayOutput,
                                    hlaWeatherData.eWeatherState,
                                    hlaAnalysisData.bRedReflectorArea,
                                    /* output data */
                                    &ps_Out->s_Environment
                                  );
      /* init diagnosis debug message */
      HLAInitDiagnosisDebugMsg( /* input */
                                &hlaSegOut,
                                /* output */
                                &ps_Out->s_DiagnosisDebugMsg
                              );
  

      /* fill debug output data */
      HLAFillDebugOutput( /* input data */
                          ps_In, 
                          /* debug output data */ 
                          &hlaDebugOutputs
                        );
  

      /* save init runtime */
      hlaDebugOutputs.timeMeas.dTimeInit_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);

      /* send internal hla data via measfreeze to MTS */
      HLAMeasfreeze(Services->pfMeasFreeze);


  #ifdef PC_SIM
      HLATrackingEvaluationInit();
  #endif  
    }
  }
}


void HLASetImagerPar(const HLAR_t_RequiredInputs  *ps_In)
{
  /* J.Häfer: No Possible Side Effect */
  /* PRQA S 3415 6 */
  if ((hlaImagerPrevChar.ui32_R1   == ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1) &&
      (hlaImagerPrevChar.ui32_R2   == ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2) &&
      (CML_f_IsZero(hlaImagerPrevChar.f32_T1_us - ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us)) &&
      (CML_f_IsZero(hlaImagerPrevChar.f32_T2_us - ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us)) &&
      (CML_f_IsZero(hlaImagerPrevChar.f32_T3_us - ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us)) &&
      (CML_f_IsZero(hlaImagerPrevChar.f32_Gain  - ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain)))
  {
    hlaImagerPrevChar.skipReInit = b_TRUE;
  }
  else
  {
    hlaImagerPrevChar.skipReInit = b_FALSE;

    hlaImagerPrevChar.ui32_R1   = ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1;
    hlaImagerPrevChar.ui32_R2   = ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2;
    hlaImagerPrevChar.f32_T1_us = ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us;
    hlaImagerPrevChar.f32_T2_us = ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us;
    hlaImagerPrevChar.f32_T3_us = ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us;
    hlaImagerPrevChar.f32_Gain  = ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain;

    /* update imager response curve data */
    HLAImager_InitPar(&ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic);
  }
}

sint16 HLARCalcDFrame(AlgoCycleCounter_t uiFrameCnt)
{
  sint16 dFrameOut;
  sint16 dFrame = (sint16)((uiFrameCnt & MAX_FRAMENUMBER) - (hlaFrameCntPrevFrame & MAX_FRAMENUMBER));

  if(   (dFrame <  MAX_DFRAME)
     && (dFrame > -MAX_DFRAME)
    )
  {
    dFrameOut = dFrame;
  }
  else if(dFrame < -(MAX_FRAMENUMBER-MAX_DFRAME))
  {
    /* wrap around */
    dFrameOut = dFrame + (MAX_FRAMENUMBER + 1);
  }
  else if(dFrame > (MAX_FRAMENUMBER-MAX_DFRAME))
  {
    /* wrap around */
    dFrameOut = dFrame - (MAX_FRAMENUMBER + 1);
  }
  else
  {
    /* frame jump > MAX_DFRAME */
    dFrameOut = MAX_DFRAME;
  }

  /* Set frame counter of previous frame */
  hlaFrameCntPrevFrame = uiFrameCnt;

  return(dFrameOut);
}

/* **************************************************************************** 
  Functionname:     HLAR_v_Exec */ /*!
  Description:      Executes tracking and environment modelling.

  @param[in]        HLAR_t_RequiredInputs  *pIn    required input for HLAR
  @param[in,out]    HLARHistory_t         *pHist  history data for HLAR
  @param[out]       HLARProvidedOutputs_t *pOut   provided output from HLAR

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAR_v_Exec( const HLAR_t_RequiredInputs  *ps_In,
                  HLAR_t_ProvidedOutputs       *ps_Out,
                  RTE_HLA_Seg_LightList_t      *ps_SegLightList,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  t_PixelData                  *pImg,
                  const AS_t_ServiceFuncts     *Services
                )
{
  uint32                    HWTime_us;
  uint32                    TimeStart_us;
  sint16                    dFrameCnt;
  HLASegLineRegionBuffer_t* pRegionBuffer;
  HLASegLightBuffer_t*      pLightBuffer;
  void*                     pL2Cache        = NULL;
  sint32                    sizeL2Cache     = 0;
  AS_t_MemState             memStateL2Cache = AS_MEM_STATE_LASTENTRY;
  sint32                    retValMemLockL2 = -1;

  /* Check for null pointer of input data once in the beginning of the algo */ 
  if (b_TRUE == HLAErrorCheck_NullPointer(ps_In, ps_Out, pImg, Services, ps_SystemInfo))
  {
    /* fatal Error */
    ps_SystemInfo->state = HLA_SYSTEMSTATE_TEMP_NOT_AVAILABLE;
  }
  else
  {

    /* get current HW time */
    HWTime_us = Services->pfGetTimestampuS32();

    /*---------------------------------------------------*/
    /* PRE-PROCESSING    */
    TimeStart_us = HWTime_us;

    /* Calc dframe */
    dFrameCnt = HLARCalcDFrame(ps_In->uiFrameCnt);
    
    /* call error checks */
    (void)HLAErrorCheck_Vehicle(ps_SystemInfo, &ps_In->s_Sig.s_HeadlightState);
    (void)HLAErrorCheck_ImageData(ps_SystemInfo, &ps_In->s_Sig.s_ImagerState.s_ImagerCharacteristic, &ps_In->s_Par.s_CameraParameter);
    (void)HLAErrorCheck_Calibration(ps_SystemInfo, &ps_In->s_Par.s_CameraParameter, &hlaCamData, &hlaCamRot);
    (void)HLAErrorCheck_Input(ps_In, &ps_In->s_Sig.s_MotionState, &ps_In->s_Sig.s_Avl, ehlaBrightnessOut, dFrameCnt, ps_SystemInfo);
    (void)HLAErrorCheck_Fatal(ps_SystemInfo, &hlaHotPixelsData.hlaDefectPixelList);

    if(     (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].status == HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED)
         && (   (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_LENSCENTER)
             || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_FOCAL_LENGTH)
             || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_CYCLETIME)
             || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_KNEELUX)
             || (ps_SystemInfo->errors.error[HLA_ERRORID_IMAGE_DATA].optData == HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_SATLUX)
            )
      )
    {
      /* fatal Error */
      ps_SystemInfo->state = HLA_SYSTEMSTATE_TEMP_NOT_AVAILABLE;
    }
    else
    {

      ps_SystemInfo->state = HLA_SYSTEMSTATE_RUNNING;

      /* Memset Eve time measurement */
      (void)memset((void*)&(hlaDebugOutputs.timeMeasEve), 0, sizeof(hlaDebugOutputs.timeMeasEve));

      HLASetImagerPar(ps_In);

      /* init all icon data */
      HLAIconInit(&hlaIcon, pImg);

      /* update hla imager precalculation */
      if (hlaImagerPrevChar.skipReInit == b_FALSE)
      {
        HLAImager_InitPar_Exec();
      }

      /* set internal cali data */
      HLASetInternalCali(&hlaTrackOut.dataCali, &ps_In->s_Sig.s_CaliOnline, &ps_In->s_Par.s_SensorAngles, ps_SystemInfo, b_FALSE);

      /* set internal hotpixels */
      HLASetInternalHotPixels(&hlaHotPixelsData, &ps_In->s_Sig.s_DefectPixelList); 

      /* reset new cam data flag */
      hlaCamData.newCamData = 0;

      /* update camera */
      HLAUpdateCamera(ps_In, &hlaTrackOut.dataCali, FALSE, dFrameCnt, &hlaCamData, &hlaCamRot);

      /* Try to lock L2 memory */
      retValMemLockL2 = Services->pfMemLockL2(&pL2Cache, &sizeL2Cache, &memStateL2Cache, AS_MEM_L2NOWAIT);
      /* Check whether we got it and if it is big enough */
      if (   (retValMemLockL2 == 0)
          && ( (uint32) sizeL2Cache >= sizeof(HLAL2Cache))
          && (   (memStateL2Cache == AS_MEM_L2FREE_L3FREE)
              || (memStateL2Cache == AS_MEM_L2FREE)
              )
          && (pL2Cache)
         )
      {
        /* Set region buffer pointer to L2Cache address */
        pLightBuffer  = &(((HLAL2Cache*)pL2Cache)->L2_hlaSegLightBuffer);
        pRegionBuffer = &(((HLAL2Cache*)pL2Cache)->L2_hlaSegLineRegionBuffer);
        Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_SEGMENTATION , 1);
      }
      else
      {
        /* Set region buffer pointer to global variable in DDR3 */
        pLightBuffer  = &hlaSegLightBuffer;
        pRegionBuffer = &hlaSegLineRegionBuffer;
        Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_SEGMENTATION , 0);
      }
      hlaDebugOutputs.timeMeas.dTimePreProcess_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* SEGMENTATION */

      TimeStart_us = Services->pfGetTimestampuS32();

      HLASegmentationExec( ps_In,
                           pImg,
                           &hlaCamData,
                           &hlaSegmentationParameters,
                           &hlaSegIn,
                           &hlaSegData,
                           &hlaSegOut,
                           pLightBuffer,
                           pRegionBuffer,
                           ps_SegLightList, /* RTE Out */
                           &hlaDebugOutputs,
                           Services
                          );
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_SEGMENTATION , 0);

      /* send segmentation measfreezes */
      HLASegmentationMeasfreeze( Services->pfMeasFreeze,
                                 pRegionBuffer,
                                 pLightBuffer
                                );

      hlaDebugOutputs.timeMeas.dTimeSegmentation_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us) - hlaDebugOutputs.timeMeasEve.dTimeEveSeg_us;
      /* Store peak time of segmentation */
      if (hlaDebugOutputs.timeMeas.dTimeSegmentation_us > hlaDebugOutputs.timeMeas.dTimeSegmentationPeak_us)
      {
        hlaDebugOutputs.timeMeas.dTimeSegmentationPeak_us = hlaDebugOutputs.timeMeas.dTimeSegmentation_us;
        hlaDebugOutputs.timeMeas.frameCntSegmentationPeak = ps_In->uiFrameCnt;
      }

      /*---------------------------------------------------*/
      /* BRIGHTNESS */

      TimeStart_us = Services->pfGetTimestampuS32();
      /* check environmental brightness */
      HLABrightnessExec( /* input */
                         &hlaSegOut.SubImage, 
                         &hlaCamData,
                         ps_In->s_Sig.s_MotionState.e_MoveState,
                         &hlaBrightnessParameters,
                         /* history */
                         &hlaBrightnessData,
                         /* output */
                         &ehlaBrightnessOut
                       );
      hlaDebugOutputs.timeMeas.dTimeBrightness_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* TRACKING */

      TimeStart_us = Services->pfGetTimestampuS32();

      /* set input */
      hlaTrackIn.pCamData               = &hlaCamData;
      hlaTrackIn.pMotionData            = &ps_In->s_Sig.s_MotionState;
      hlaTrackIn.pSegOut                = &hlaSegOut;
      hlaTrackIn.pDataHotPixels         = &(hlaHotPixelsData);
      hlaTrackIn.eBrightnessState       = ehlaBrightnessOut;

      /* run algo */
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_TRACKING , 0);
      HLATracking3D( &hlaTrackOut, 
                     &hlaDebugOutputs, 
                     &hlaTrackData, 
                     &hlaTrackIn, 
                     &hlaTracking3DParameters, 
                     &ps_In->s_Par.s_HlarPar, 
                     ehlaTrafficStyle,
                     Services->pfGetTimestampuS32
                    );
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_TRACKING , 0);

      hlaDebugOutputs.timeMeas.dTimeTrack_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);
      hlaDebugOutputs.timeMeas.dTimeTrackOther_us = hlaDebugOutputs.timeMeas.dTimeTrack_us - (  hlaDebugOutputs.timeMeas.dTimeTrackPredict_us
                                                                                              + hlaDebugOutputs.timeMeas.dTimeTrackAssoc_us
                                                                                              + hlaDebugOutputs.timeMeas.dTimeTrackUpdate_us
                                                                                              + hlaDebugOutputs.timeMeas.dTimeTrackAdd_us
                                                                                              + hlaDebugOutputs.timeMeas.dTimeTrackAddPair_us);
      /* Store peak time of tracking */
      if (hlaDebugOutputs.timeMeas.dTimeTrack_us > hlaDebugOutputs.timeMeas.dTimeTrackPeak_us)
      {
        hlaDebugOutputs.timeMeas.dTimeTrackPeak_us = hlaDebugOutputs.timeMeas.dTimeTrack_us;
        hlaDebugOutputs.timeMeas.frameCntTrackPeak = ps_In->uiFrameCnt;
      }

      /*---------------------------------------------------*/
      /* HOT PIXELS PROCESS */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      HLAHotPixels(&ps_In->s_Sig.s_MotionState, ehlaBrightnessOut, hlaTrackOut.pTrack, &hlaHotPixelsData, &hlaTracking3DParameters.paramHotPixel);

      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeHotPixels_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* ANALYSIS */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_ANALYSIS , 0);
      HLAAnalysis( ps_In,
                   &hlaTrackOut,
                   &hlaDebugOutputs.turnOffReason,
                   &hlaCamRot, 
                   &hlaCamData,
                   ehlaTrafficStyle,
                   /* icons */
                   &hlaAnalysisIconData[0],
                   &hlaSLInput,
                   &hlaAnalysisParameters,
                   &hlaAnalysisData,
                   &hlaTracking3DParameters.paramMeasurement,
                   &hlaHighwayOutput,
                   &hlaChainOfLightData,
                   &hlaWeatherData,
                   &hlaDebugOutputs,
                   Services
                 );
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_ANALYSIS , 0);

      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeAnalysis_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us) - hlaDebugOutputs.timeMeasEve.dTimeEveLrf_us;
      /* Store peak time of analysis */
      if (hlaDebugOutputs.timeMeas.dTimeAnalysis_us > hlaDebugOutputs.timeMeas.dTimeAnalysisPeak_us)
      {
        hlaDebugOutputs.timeMeas.dTimeAnalysisPeak_us = hlaDebugOutputs.timeMeas.dTimeAnalysis_us;
        hlaDebugOutputs.timeMeas.frameCntAnalysisPeak = ps_In->uiFrameCnt;
      }

      /*---------------------------------------------------*/
      /* BRIGHT OBJECT DETECTION */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      HLABrightObjects( hlaTrackOut.pTrack,
                        &hlaSegOut
                      );
      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeBrightObjects_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* HIGHWAY DETECTION */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      /* Set Input */
      hlaHighwayInput.pTLB = hlaTrackOut.pTrack;
      hlaHighwayInput.pCamData = &hlaCamData;
      hlaHighwayInput.pcamRot = &hlaCamRot;
      hlaHighwayInput.pMotionData = &ps_In->s_Sig.s_MotionState;
      hlaHighwayInput.pTrafficStyle = &ehlaTrafficStyle;
      hlaHighwayInput.pCameraParameter = &ps_In->s_Par.s_CameraParameter;
      hlaHighwayInput.pTracking3DParams = &hlaTracking3DParameters;
      hlaHighwayInput.eBrightnessState = ehlaBrightnessOut;


      if(ehlaTrafficStyle != RTE_HLA_TRAFFIC_STYLE_UNKNOWN)
      {
        Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_HIGHWAY , 0);
        HLAHighway(&hlaHighwayInternalData,&hlaHighwayOutput,&hlaHighwayInput,&hlaHighwayParams,&(ps_In->s_Par.s_HlarPar.Highway));
        Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_HIGHWAY , 0);
      }

      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeHighway_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* CITY DETECTION */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      /* Set Input */
      hlaCityInput.pCamData         = &hlaCamData;
      hlaCityInput.pCamRot          = &hlaCamRot;
      hlaCityInput.pMotionData      = &(ps_In->s_Sig.s_MotionState);
      hlaCityInput.ps_HLAR_In       = ps_In;
      hlaCityInput.pTLB             = hlaTrackOut.pTrack;
      hlaCityInput.pTrafficStyle    = &ehlaTrafficStyle;
      hlaCityInput.pSegOut          = &hlaSegOut;
      hlaCityInput.pHLASubImage     = &(hlaSegOut.SubImage);
      hlaCityInput.eBrightnessState = ehlaBrightnessOut;
      hlaCityInput.eCountyCode      = (ps_In->s_Par.s_HlaPar.Country.CountryCode);

      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_CITY , 0);
      HLACity( /* input */
               &hlaCityInput,
               &hlaCityDetectionParameters,
               &(ps_In->s_Par.s_HlarPar.City),
               /* history */ 
               &hlaCityData,
               /* output */ 
               &ehlaCityOutput
             );
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_CITY , 0);

      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeCity_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* TRAFFIC STYLE ANALYSIS */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      /* Set Input */
      hlaTrafficStyleInput.pcamRot = &hlaCamRot;
      hlaTrafficStyleInput.ps_HLAR_In = ps_In;
      hlaTrafficStyleInput.pTLB = hlaTrackOut.pTrack;
      hlaTrafficStyleInput.eCity = ehlaCityOutput;
      hlaTrafficStyleInput.pOdometer = &hlaOdometer;

      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_TRAFFIC_STYLE , 0);
      HLATrafficStyle( /* input */
                       &hlaTrafficStyleInput,
                       /* output */
                       &ehlaTrafficStyle,
                       &ehlaTrafficStyleState,
                       &ehlaTrafficStyleLearningState,
                       /* history */ 
                       &hlaTrafficStyleHist,
                       /* parameters */
                       &hlaTrafficStyleParameters,
                       &(ps_In->s_Par.s_HlarPar.TrafficStyle)
                     );
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_TRAFFIC_STYLE , 0);


      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeTrafficStyle_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);


      /*---------------------------------------------------*/
      /* TUNNEL DETECTION */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      /* Set Input */
      hlaTunnelInput.pHLASubImage     = &(hlaSegOut.SubImage);
      /* hlaTunnelInput.pHLAMotionState  = &(ps_In->s_Sig.s_MotionState); */
      hlaTunnelInput.pTrackStart      = hlaTrackOut.pTrack;
      hlaTunnelInput.eBrightnessState = ehlaBrightnessOut;
      hlaTunnelInput.eCityState       = ehlaCityOutput;
      hlaTunnelInput.dDistFwd_m       = hlaCamData.ddistFwd_m;

      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_HLA, HLA_RTA_RUNTIME_TUNNEL , 0);
      HLATunnelDetectionMain(&hlaTunnelInput,
                             &(ps_In->s_Par.s_HlarPar.Tunnel),
                             &hlaTunnelOutput,
                             &ehlaTunnelOutput);
      Services->pfRTAAlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_HLA, HLA_RTA_RUNTIME_TUNNEL , 0);


      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimeTunnel_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /*---------------------------------------------------*/
      /* POST-PROCESS */
      /* !!!!   time measurement */
      TimeStart_us = Services->pfGetTimestampuS32();

      HLASetDebugOutputs();

      HLASetOdometer( &hlaOdometer,
                      hlaCamData.ddist_m,
                      ps_In->s_Sig.s_MotionState.e_MoveState
                    );

      /***********************************************/
      /* post processing => parameters for next cyle */

      /* update camdata */
      HLAUpdateCamera(ps_In, &hlaTrackOut.dataCali, FALSE, dFrameCnt, &hlaCamData, &hlaCamRot);

      /* update roi */
      HLARUpdateRoi(ps_In, &hlaCamData, &hlaCamRot, ps_SystemInfo);
  
      (void)HLAErrorCheck_Segmentation(&hlaSegData, ps_SystemInfo);
      (void)HLAErrorCheck_Analysis(&hlaAnalysisData, ps_SystemInfo);

      /* increment HLAR call counter */
      HLAR_Cnt++;

      /* fill output/ history data */
      HLAOutputFillData( /* input data */
                         &hlaCamData,
                         &hlaCamRot,
                         hlaTrackOut.pTrack,
                         hlaTrackOut.numTracks,
                         ps_In,
                         ehlaTrafficStyle,
                         ehlaTrafficStyleState,
                         ehlaTrafficStyleLearningState,
                         &hlaTrackOut.dataCali,
                         /* output data */
                         ps_Out
                       );

      HLAOutputFillEnvironmentData( /* input data */
                                    ehlaBrightnessOut,
                                    ehlaCityOutput,
                                    ehlaTrafficStyle,
                                    ehlaTrafficStyleState,
                                    ehlaTunnelOutput,
                                    &hlaHighwayOutput,
                                    hlaWeatherData.eWeatherState,
                                    hlaAnalysisData.bRedReflectorArea,
                                    /* output data */
                                    &ps_Out->s_Environment
                                  );
      /* fill diagnosis message */
      HLAFillDiagnosisDebugMsg( ps_In,
                                &hlaDebugOutputs.turnOffReason,
                                &hlaIcon,
                                &hlaAnalysisData,
                                dFrameCnt,
                                &ps_Out->s_DiagnosisDebugMsg
                              );

      /* fill debug output data */
      HLAFillDebugOutput( /* input data */
                          ps_In, 
                          /* debug output data */ 
                          &hlaDebugOutputs
                         );
    
      /* fill segmentation input data for the next frame */
      HLASegFillInputData( &hlaSegIn,
                           &hlaCamData,
                           &hlaCamRot,
                           &hlaBrightnessParameters,
                           ehlaBrightnessOut,
                           ps_In->s_Sig.s_MotionState.e_MoveState,
                           hlaTrackOut.numTracks,
                           ps_In->s_Par.s_HlaPar.AlgoCfg.TestMode
                         );

      /* Unlock L2 Cache if applicable, i.e. at least retValMemLockL2 was not 0 */
      if (pL2Cache != NULL)
      {
        retValMemLockL2 = Services->pfMemUnlockL2(&memStateL2Cache);
        /* Check for errors */
        if (   (retValMemLockL2 != 0)
            || (memStateL2Cache != AS_MEM_L2USED)
           )
        {
          /* TODO: What to do here? Report an error in systemInfo? */
        }
      }
      
      /* !!!!   time measurement */
      hlaDebugOutputs.timeMeas.dTimePostProcess_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

      /* save main runtime, take care of eve runtime */
      hlaDebugOutputs.timeMeas.dTimeMain_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us) - hlaDebugOutputs.timeMeasEve.dTimeEve_us;
      /* Store peak time of hla main */
      if (hlaDebugOutputs.timeMeas.dTimeMain_us > hlaDebugOutputs.timeMeas.dTimeMainPeak_us)
      {
        hlaDebugOutputs.timeMeas.dTimeMainPeak_us = hlaDebugOutputs.timeMeas.dTimeMain_us;
        hlaDebugOutputs.timeMeas.frameCntMainPeak = ps_In->uiFrameCnt;
      }
      /* Store peak time of EVE */
      if (hlaDebugOutputs.timeMeasEve.dTimeEve_us > hlaDebugOutputs.timeMeas.dTimeEvePeak_us)
      {
        hlaDebugOutputs.timeMeas.dTimeEvePeak_us = hlaDebugOutputs.timeMeasEve.dTimeEve_us;
        hlaDebugOutputs.timeMeas.frameCntEvePeak = ps_In->uiFrameCnt;
      }

      /*---------------------------------------------------*/
      /* SEND MEAS FREEZES */
      /* send internal hla data via measfreeze to MTS */
      HLAMeasfreeze(Services->pfMeasFreeze);
  #ifdef ICON_MEASFREEZE
      HLAIconMeasfreeze(Services->pfMeasFreeze);
  #endif
  
  #ifdef PC_SIM
       HLATrackingEvaluationUpdate(&ps_In->s_Sig.s_MotionState);
       HLAEvaluateSL(&hlaSLInput);
       HLATrackingEvaluationPairing();
  #endif
    }
  }
}

/* ****************************************************************************
  Functionname:     HLAMeasfreeze                          */ /*!
  Description:      send internal hla data via measfreeze to MTS. 



  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           
**************************************************************************** */
static void HLAMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
 
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo CamDataMeasInfo          = {HLA_MEAS_VADDR_CAM_DATA, sizeof(hlaCamData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo OdometerMeasInfo         = {HLA_MEAS_VADDR_ODOMETER, sizeof(hlaOdometer), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo DebugOutMeasInfo         = {HLA_MEAS_VADDR_HLA_DEBUG_OUT, sizeof(hlaDebugOutputs), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo SegInMeasInfo            = {HLA_MEAS_VADDR_SEG_IN, sizeof(hlaSegIn), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo SegOutaMeasInfo          = {HLA_MEAS_VADDR_SEG_OUT, sizeof(hlaSegOut), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo SegDataMeasInfo          = {HLA_MEAS_VADDR_SEG_DATA, sizeof(hlaSegData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo TrackOutMeasInfo         = {HLA_MEAS_VADDR_TRACK_OUT, sizeof(hlaTrackOut), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo TrackPreComputedMeasInfo = {HLA_MEAS_VADDR_TRACK_PRE_COMPUTED, sizeof(HLATracking3DDataPreComputed_t), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HighwayMeasInfo          = {HLA_MEAS_VADDR_HIGHWAY_OUT, sizeof(hlaHighwayOutput), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo CityMeasInfo             = {HLA_MEAS_VADDR_CITY_DATA, sizeof(hlaCityData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo TunnelMeasInfo           = {HLA_MEAS_VADDR_TUNNEL_OUT, sizeof(hlaTunnelOutput), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};

  HLAImager_Measfreeze(pfMeasFreeze);
  (void)pfMeasFreeze(&CamDataMeasInfo, (void*)&hlaCamData, NULL);
  (void)pfMeasFreeze(&OdometerMeasInfo, (void*)&hlaOdometer, NULL);
  (void)pfMeasFreeze(&DebugOutMeasInfo, (void*)&hlaDebugOutputs, NULL);
  (void)pfMeasFreeze(&SegInMeasInfo, (void*)&hlaSegIn, NULL);
  (void)pfMeasFreeze(&SegOutaMeasInfo, (void*)&hlaSegOut, NULL);
  (void)pfMeasFreeze(&SegDataMeasInfo, (void*)&hlaSegData, NULL);
  (void)pfMeasFreeze(&TrackOutMeasInfo, (void*)&hlaTrackOut, NULL);
  (void)pfMeasFreeze(&TrackPreComputedMeasInfo, (void*)&hlaTrackData.dataPreComputed, NULL);
  (void)pfMeasFreeze(&HighwayMeasInfo, (void*)&hlaHighwayOutput, NULL);
  (void)pfMeasFreeze(&CityMeasInfo, (void*)&hlaCityData, NULL);
  (void)pfMeasFreeze(&TunnelMeasInfo, (void*)&hlaTunnelOutput, NULL);
#endif


}


/* ****************************************************************************
  Functionname:     HLASetDebugHighwayData                                    */ /*!
  Description:      - 

  @param[in,out]    -
  @param[in]        -

  @pre              -
  @post             -
  @todo             - 
  @author           Boris Lugez
**************************************************************************** */
static void HLASetDebugHighwayData(HLADebugHighwayData_t *pDebugHighwayData,const HLAHighwayInternalData_t *pHighwayInternData)
{
  uint8 i = 0;

  for(i=0; i<HLA_HIGHWAY_DEATH_AREA_NUM_MEAN; i=i+1)
  {
    pDebugHighwayData->OncomingHist[i] = pHighwayInternData->OncomingHist[i];
  }

  pDebugHighwayData->DeathAreaInd = pHighwayInternData->DeathAreaInd;
  pDebugHighwayData->DistToLastOncoming = pHighwayInternData->DistToLastOncoming;
  pDebugHighwayData->CountOncoming = pHighwayInternData->CountOncoming;
  pDebugHighwayData->LastCount = pHighwayInternData->LastCount;
  pDebugHighwayData->NewDeathCount = pHighwayInternData->NewDeathCount;
  pDebugHighwayData->NewPreDeathCount = pHighwayInternData->NewPreDeathCount;
  pDebugHighwayData->bLastCountFirstUpdate = pHighwayInternData->bLastCountFirstUpdate;
  pDebugHighwayData->bLastCountSecondUpdate = pHighwayInternData->bLastCountSecondUpdate;
  pDebugHighwayData->DistHwayDction = pHighwayInternData->DistHwayDction;
  pDebugHighwayData->DistHwayUndef = pHighwayInternData->DistHwayUndef;
  pDebugHighwayData->ThreshPrematureX = pHighwayInternData->ThreshPrematureX;
  pDebugHighwayData->ThreshPrematureY = pHighwayInternData->ThreshPrematureY;
  pDebugHighwayData->OcclusionCount = pHighwayInternData->OcclusionCount;
  pDebugHighwayData->ConfLatPos = pHighwayInternData->ConfLatPos;
  pDebugHighwayData->ConfEgoMotion = pHighwayInternData->ConfEgoMotion;
  pDebugHighwayData->ConfOcclDction = pHighwayInternData->ConfOcclDction;
  pDebugHighwayData->eLateralPosition = pHighwayInternData->eLateralPosition;
  pDebugHighwayData->eEgoMotion = pHighwayInternData->eEgoMotion;
  pDebugHighwayData->eOcclusionDetection = pHighwayInternData->eOcclusionDetection;
  pDebugHighwayData->Curvature = pHighwayInternData->Curvature;
  pDebugHighwayData->DistPossibleExit = pHighwayInternData->DistPossibleExit;
  pDebugHighwayData->YawIntegrate = pHighwayInternData->YawIntegrate;
  pDebugHighwayData->YawIntegrateMin = pHighwayInternData->YawIntegrateMin;
  pDebugHighwayData->YawIntegrateMax = pHighwayInternData->YawIntegrateMax;
  pDebugHighwayData->bHwayExit = pHighwayInternData->bHwayExit;
}
static void HLASetDebugOutputs(void)
{
  
  HLASetDebugHighwayData(&hlaDebugOutputs.HighwayData,&hlaHighwayInternalData);

}


/* ****************************************************************************
  Functionname:     HLA_v_GetAlgoVersion */ /*!
  Description:      Get the HLA Algo version number.

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLA_v_GetAlgoVersion( uint32* pHlaSWVersionNumber,
                           uint32* pHlaApplicationVersionNumber,
                           uint8   versionInfo[MFC_VERSION_INFO_LENGTH]
                          )
{
  uint8 VersionInfo[MFC_VERSION_INFO_LENGTH] = HLA_SW_VERSION_INFO;

  *pHlaSWVersionNumber = HLA_SW_VERSION_NUMBER;
  *pHlaApplicationVersionNumber = HLA_APPL_VERSION_NUMBER;
  (void)memcpy((void*)versionInfo, (void*)VersionInfo, MFC_VERSION_INFO_LENGTH * sizeof(uint8));
}/* PRQA S 861 1 */
