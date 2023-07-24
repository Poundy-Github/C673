/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_base.h

  DESCRIPTION:            Base type definitions for HLAR and HLAF

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          26-10-2010

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_base.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:31CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:40CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:05CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.258 2014/03/19 16:31:39CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:39 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.257 2014/03/04 16:51:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:53 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.256 2014/03/04 15:53:10CET Glebov, Roman (uidg4759) 
  CHANGES:                changed type of angleUL for chainOfLight from float32 to sint32
  CHANGES:                --- Added comments ---  uidg4759 [Mar 4, 2014 3:53:10 PM CET]
  CHANGES:                Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGES:                Revision 1.255 2014/03/04 14:03:06CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for latest R2.1 RTE
  CHANGES:                Undid I390 RTE specific things
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 2:03:06 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.254 2014/03/04 13:52:19CET Glebov, Roman (uidg4759) 
  CHANGES:                changed dist2 field to angleUL
  CHANGES:                --- Added comments ---  uidg4759 [Mar 4, 2014 1:52:20 PM CET]
  CHANGES:                Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGES:                Revision 1.253 2014/03/04 12:58:50CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for I390 RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:50 PM CET]
  CHANGES:                Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.252 2014/03/03 16:51:33CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:33 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.251 2014/03/03 16:28:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Smaller type for icon position
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:28:57 PM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.250 2014/03/03 14:23:52CET Brunn, Marcus (brunnm) 
  CHANGES:                fill RTE_HLA_Seg_Light_t (rte output of light/region list)
  CHANGES:                --- Added comments ---  brunnm [Mar 3, 2014 2:23:53 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.249 2014/03/03 13:11:00CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced tabs by spaces
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 1:11:01 PM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.248 2014/03/03 10:20:46CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed compilation for DSP
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 10:20:47 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.247 2014/02/28 15:42:36CET Schillinger, Patrick (uidv8776) 
  CHANGES:                remove unused fields in HLAIconData_t
  CHANGES:                --- Added comments ---  uidv8776 [Feb 28, 2014 3:42:36 PM CET]
  CHANGES:                Change Package : 217405:1 http://mks-psad:7002/im/viewissue?selection=217405
  CHANGES:                Revision 1.246 2014/02/28 15:04:50CET Brunn, Marcus (brunnm) 
  CHANGES:                - improved light filtering
  CHANGES:                - preparation of light list for new rte interface i390
  CHANGES:                --- Added comments ---  brunnm [Feb 28, 2014 3:04:50 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.245 2014/02/24 11:44:37CET Manz, Alexander (uidv8777) 
  CHANGES:                Update:
  CHANGES:                 - tunnel detection types changed
  CHANGES:                 - removed some unnecessary flags from the simulation INI file (all related to very old visu)
  CHANGES:                --- Added comments ---  uidv8777 [Feb 24, 2014 11:44:37 AM CET]
  CHANGES:                Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGES:                Revision 1.244 2014/02/21 16:53:54CET Manz, Alexander (uidv8777) 
  CHANGES:                Update: changed "Vehicle" to "Pair" for better understandability in macro name
  CHANGES:                --- Added comments ---  uidv8777 [Feb 21, 2014 4:53:55 PM CET]
  CHANGES:                Change Package : 207634:3 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGES:                Revision 1.243 2014/02/11 09:20:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed time meas
  CHANGES:                Fixed dframe calculation on HIL
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:08 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.242 2014/02/06 16:02:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:49 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.241 2014/02/05 15:10:37CET Brunn, Marcus (brunnm) 
  CHANGES:                removed LED segmentation
  CHANGES:                --- Added comments ---  brunnm [Feb 5, 2014 3:10:38 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.240 2014/01/28 16:20:38CET Glebov, Roman (uidg4759) 
  CHANGES:                added field for the length of chain of light to HLATrack_T
  CHANGES:                --- Added comments ---  uidg4759 [Jan 28, 2014 4:20:38 PM CET]
  CHANGES:                Change Package : 199150:2 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.239 2014/01/21 09:12:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added a few more checks for devision of zero
  CHANGES:                Removed some PC_SIM code that is no longer needed
  CHANGES:                --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:53 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.238 2014/01/13 16:59:52CET Schillinger, Patrick (uidv8776) 
  CHANGES:                reduce eHLAIconState_t
  CHANGES:                --- Added comments ---  uidv8776 [Jan 13, 2014 4:59:52 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.237 2014/01/10 18:34:01CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:01 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.236 2014/01/08 17:10:32CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactored HLA_Exec() function
  CHANGES:                Replaced uint64 time stamps by uint32 ones
  CHANGES:                Smaller bug fixes
  CHANGES:                --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:32 PM CET]
  CHANGES:                Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.235 2014/01/07 09:32:25CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved PC specific pragmas behind PC_SIM flag
  CHANGES:                --- Added comments ---  uidv7867 [Jan 7, 2014 9:32:26 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.234 2013/12/27 22:11:01CET Glebov, Roman (uidg4759) 
  CHANGES:                disabled unknown pragma warning of VC++ for special QAC pragmas
  CHANGES:                --- Added comments ---  uidg4759 [Dec 27, 2013 10:11:01 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.233 2013/12/26 18:30:47CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC: decalred sqrtf for qac not having any side effects
  CHANGES:                --- Added comments ---  uidg4759 [Dec 26, 2013 6:30:47 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.232 2013/12/26 15:25:26CET Glebov, Roman (uidg4759) 
  CHANGES:                Solved several QAC critical messages:
  CHANGES:                
  CHANGES:                - implicit conversion from signed char to float
  CHANGES:                - possible side effects ciritical warnings if conditional expressions
  CHANGES:                - comparison with 0 of float variables in conditional expressions
  CHANGES:                --- Added comments ---  uidg4759 [Dec 26, 2013 3:25:26 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.231 2013/12/18 15:18:01CET Schillinger, Patrick (uidv8776) 
  CHANGES:                introduction of new HighwayOncomingTruckLight detection
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:02 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.230 2013/12/17 17:32:41CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGES:                --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:41 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.229 2013/12/05 17:47:51CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:51 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.228 2013/11/21 17:53:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:58 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.227.1.7 2013/11/19 13:42:30CET Brunn, Marcus (brunnm) 
  CHANGES:                clean up -> removed unused vars
  CHANGES:                --- Added comments ---  brunnm [Nov 19, 2013 1:42:31 PM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.227.1.6 2013/11/19 07:50:41CET Brunn, Marcus (brunnm) 
  CHANGES:                - removed day segmentation
  CHANGES:                - updated HLASegLineBuffer_t
  CHANGES:                - updated HLASegLineRegion_t
  CHANGES:                --- Added comments ---  brunnm [Nov 19, 2013 7:50:42 AM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.227.1.5 2013/11/14 09:45:54CET Brunn, Marcus (brunnm) 
  CHANGES:                removed unused HLASegMaximaBuffer_t
  CHANGES:                --- Added comments ---  brunnm [Nov 14, 2013 9:45:54 AM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.227.1.4 2013/10/29 18:21:22CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Time meas fixes
  CHANGES:                New roi calculation (alignment to eve)
  CHANGES:                Call EVE in segmentation now
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:22 PM CET]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.227.1.3 2013/10/24 10:44:15CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some not needed variables
  CHANGES:                Made HLA working on evalboard
  CHANGES:                --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:15 AM CEST]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.227.1.2 2013/10/21 10:18:27CEST Brunn, Marcus (brunnm) 
  CHANGES:                - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t
  CHANGES:                - removed bit field for line position
  CHANGES:                - moved  level index from line to region
  CHANGES:                --- Added comments ---  brunnm [Oct 21, 2013 10:18:28 AM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.227.1.1 2013/10/18 13:27:33CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:33 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.227 2013/09/25 11:42:48CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed sampling aborted check
  CHANGES:                --- Added comments ---  uidv7867 [Sep 25, 2013 11:42:49 AM CEST]
  CHANGES:                Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.226 2013/08/19 16:53:01CEST Manz, Alexander (uidv8777) 
  CHANGES:                Update: Rough implementation of tunnel detection at night based on street lamps.
  CHANGES:                --- Added comments ---  uidv8777 [Aug 19, 2013 4:53:01 PM CEST]
  CHANGES:                Change Package : 188780:1 http://mks-psad:7002/im/viewissue?selection=188780
  CHANGES:                Revision 1.225 2013/08/15 14:35:42CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed segline buffer measfreeze
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:35:43 PM CEST]
  CHANGES:                Change Package : 192116:2 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.224 2013/08/02 15:25:51CEST Manz, Alexander (uidv8777) 
  CHANGES:                Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGES:                --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:51 PM CEST]
  CHANGES:                Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGES:                Revision 1.223 2013/07/23 09:51:50CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Added more CoL debug information
  CHANGES:                --- Added comments ---  uidv8778 [Jul 23, 2013 9:51:51 AM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.222 2013/07/12 11:20:17CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Further restructuring of chain of light
  CHANGES:                --- Added comments ---  uidv8778 [Jul 12, 2013 11:20:17 AM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.221 2013/06/21 16:18:49CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Moved chain of light visu from hla_analysischain to sim_hla_visualisation_draw
  CHANGES:                --- Added comments ---  uidv8778 [Jun 21, 2013 4:18:49 PM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.220 2013/04/19 14:41:24CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Implemented BMW Highway Codierparamter
  CHANGES:                --- Added comments ---  uidv8778 [Apr 19, 2013 2:41:24 PM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.219 2013/04/02 16:49:15CEST Schillinger, Patrick (uidv8776) 
  CHANGES:                replaced "Bit_07" by "iconMissed"
  CHANGES:                --- Added comments ---  uidv8776 [Apr 2, 2013 4:49:15 PM CEST]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.218 2013/03/15 12:56:37CET Manz, Alexander (uidv8777) 
  CHANGES:                Tunnel detection update includes ability to work with parameter and create measFreezes
  CHANGES:                --- Added comments ---  uidv8777 [Mar 15, 2013 12:56:38 PM CET]
  CHANGES:                Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGES:                Revision 1.217 2013/03/12 14:11:32CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2013 2:11:33 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.216 2013/03/11 16:13:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                - HLA_t_eSignalState
  CHANGES:                - HLA_t_eLightStyle
  CHANGES:                - HLA_t_eTunnel
  CHANGES:                - HLA_t_eCityState
  CHANGES:                - HLA_t_eWeatherState
  CHANGES:                - HLA_t_eMotorwayState
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:49 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.215 2013/03/08 17:42:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed HeadlightState and taken RTE type into use
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 5:42:57 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.214 2013/03/08 15:37:40CET Fischer, Alexander (uidv8778) 
  CHANGES:                First version of ambient city detection
  CHANGES:                --- Added comments ---  uidv8778 [Mar 8, 2013 3:37:41 PM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.213 2013/03/08 10:31:12CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:12 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.212 2013/03/08 10:12:28CET Schillinger, Patrick (uidv8776) 
  CHANGES:                Moved Highway Oncoming Car Analysis to First Level Analysis
  CHANGES:                --- Added comments ---  uidv8776 [Mar 8, 2013 10:12:28 AM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.211 2013/03/06 11:19:27CET Zechner, Stefan (uidt9253) 
  CHANGES:                - remove dependencies to algo_common
  CHANGES:                - replace HLA type Pix16_t by RTE type t_PixelData
  CHANGES:                --- Added comments ---  uidt9253 [Mar 6, 2013 11:19:27 AM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.210 2013/02/26 09:19:27CET Fischer, Alexander (uidv8778) 
  CHANGES:                Highway detection over high speed implemented
  CHANGES:                --- Added comments ---  uidv8778 [Feb 26, 2013 9:19:27 AM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.209 2013/02/04 10:33:57CET Schillinger, Patrick (uidv8776) 
  CHANGES:                added possibility for for direct image access for icon creation.
  CHANGES:                --- Added comments ---  uidv8776 [Feb 4, 2013 10:33:59 AM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.208 2013/01/30 10:51:26CET Brunn, Marcus (brunnm) 
  CHANGES:                renamed Highway variables:
  CHANGES:                - RdwayType -> LatPos
  CHANGES:                - HwayDction -> EgoMotion
  CHANGES:                --- Added comments ---  brunnm [Jan 30, 2013 10:51:27 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.207 2013/01/28 15:06:14CET Brunn, Marcus (brunnm) 
  CHANGES:                Switched to rte like types for
  CHANGES:                - HLA_t_eRedReflectorArea
  CHANGES:                - HLA_t_eHighwayLatPosState
  CHANGES:                - HLA_t_eHighwayEgoMotionState
  CHANGES:                - HLA_t_eHighwayOcclusionState
  CHANGES:                --- Added comments ---  brunnm [Jan 28, 2013 3:06:14 PM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.206 2013/01/24 14:19:27CET Zechner, Stefan (uidt9253) 
  CHANGES:                - minimum time of 7 frames where sticky state is kept avoids flickering of vehicle detected/lost/detected in icon bypass scenarios
  CHANGES:                --- Added comments ---  uidt9253 [Jan 24, 2013 2:19:27 PM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.205 2013/01/22 12:06:27CET Fischer, Alexander (uidv8778) 
  CHANGES:                HLA-R Internal Highway Decision
  CHANGES:                --- Added comments ---  uidv8778 [Jan 22, 2013 12:06:27 PM CET]
  CHANGES:                Change Package : 173113:1 http://mks-psad:7002/im/viewissue?selection=173113
  CHANGES:                Revision 1.204 2013/01/18 07:45:56CET Brunn, Marcus (brunnm) 
  CHANGES:                initial matrix beam version for BMW I210
  CHANGES:                --- Added comments ---  brunnm [Jan 18, 2013 7:45:56 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.203 2013/01/16 17:56:17CET Zechner, Stefan (uidt9253) 
  CHANGES:                - fix point version of the additional features in LRF icon classifier
  CHANGES:                - remove unused variable isChainOfLights in struct HLAAnalysisResultState_t
  CHANGES:                --- Added comments ---  uidt9253 [Jan 16, 2013 5:56:18 PM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.202 2013/01/15 15:22:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Clean-up, added some const keywords
  CHANGES:                --- Added comments ---  uidv7867 [Jan 15, 2013 3:22:57 PM CET]
  CHANGES:                Change Package : 167173:23 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.201 2013/01/11 10:35:29CET Zechner, Stefan (uidt9253) 
  CHANGES:                - icon classifier uses additional features from other HLA components (like tracking information) in MLP classification
  CHANGES:                - visualization of icon LED detection information
  CHANGES:                --- Added comments ---  uidt9253 [Jan 11, 2013 10:35:34 AM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.200 2013/01/07 15:39:25CET Zechner, Stefan (uidt9253) 
  CHANGES:                rename the 32-bit enum size type again to avoid a lot of ansi-c compiler errors
**************************************************************************** */

#ifndef HLA_BASE_INCLUDED
#define HLA_BASE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "glob_type.h"

#include "hla_type.h"
#include "hla_defs.h"
#include "hla_cfg.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/*! Type definition for camera data (hla roi, function roi) */
typedef struct
{
  /* indicates if cam data have been changed */
  uint8  newCamData;

  /* foe in abs imager coordinates */
  uint16 FOE_x;
  uint16 FOE_y;

  /* HLA roi data */ 
  /* in absolute imager coordinates */

  uint16 RoiX1;     /* first pixel of HLA ROI */ 
  uint16 RoiX2;     /* last  pixel of HLA ROI */ 
  uint16 RoiY1;     /* first line of HLA ROI  */ 
  uint16 RoiY2;     /* last  line of HLA ROI  */
  uint16 RoiYu;     /* upper function ROI border: no vehicles above this line */
  uint16 RoiWidth;  /* = (X2- X1) +1 */
  uint16 RoiHeight; /* = (Y2- Y1) +1 */

  float32 dtime_s;     /* [s] time since last segmentation (always > 0)                                               */
  float32 dtimeFwd_s;  /* [s] forward driving time since last segmentation (driving forwards > 0, backwards = 0)      */
  float32 ddist_m;     /* [m] distance since last segmentation (driving forwards > 0, backwards = 0)                  */
  float32 ddistFwd_m;  /* [m] forward driving distance since last segmentation (driving forwards > 0, backwards = 0)  */
  float32 radius_m;    /* [m] radius of curvature                                                                     */
  float32 radiusAbs_m; /* [m] (> 0) absolute radius of curvature                                                      */

  /* dFrame regarding HLA cycle time */
  float32 dFrameHLACycle;
  float32 dFrameHLACycle_inv;

}HLACameraData_t;


/**********************************/
/* defines/ typedefs for icon box */
/**********************************/
/* ICON ID is only used for measfreeze and write pgm */
typedef enum
{
  ICON_INIT    = 0u,     /* no ROI Handle -> ROI define necessary   */
  ICON_FREE    = 1u,     /* ROI Handle available -> update possible */
  ICON_DELETED = 2u,     /* icon deleted in this frame -> roi define possible in the next frame */
  ICON_WHITE   = 3u,
  ICON_RED     = 4u,
  ICON_MISC    = 5u,

  ICON_ID_LAST = SI32_T_MAX
}eHLAIconID_t;

typedef enum
{
  ICON_ERR_INIT              = 0u,
  ICON_NO_ERR                = 1u,
  ICON_NO_FREE_BOX           = 2u,
  ICON_INVALID_DATA_POINTER  = 3u,
  ICON_INVALID_DATA          = 4u,
  ICON_BUSY                  = 5u,            /* new icon data from last request not received (icon callback) or still in processing */
  ICON_ROI_ERR               = 6u,            /* -> see ROI Error */
  ICON_NO_CALLBACK           = 7u,            /* no icon callback function */
  ICON_WRONG_ROI_HANDLE      = 8u,            /* callback fits not to ROI_Handle/ icon */
  ICON_WRONG_ICON_ID         = 9u,            /* icon ID in callback fits not to requested icon */    
  ICON_ICON_OUTSIDE_HLA_ROI  = 10u,           /* icon not within the HLA ROI */
  ICON_ICON_SAMPLING_ABORTED = 11u,           /* sampling aborted */

  ICON_ERROR_LAST        = SI32_T_MAX
}eHLAIconErr_t;

typedef enum
{
  ICON_STATE_INIT       = 0u,          /* init state -> icon define is possible                         */
  ICON_STATE_IDLE       = 1u,          /* idle state -> icon processing finished, new HLAIconSetBox()   */
  ICON_STATE_DATA_VALID = 2u           /* icon data is valid -> start icon processing                   */
}eHLAIconState_t;

typedef struct
{
  uint16            X1;
  uint16            X2;
  uint8             Width;
  uint16            Y1;
  uint16            Y2;
  uint8             Height;
}HLAIconPosition_t;

typedef struct
{
  eHLAIconID_t      eIconID;   /* icon ID                                                                          */
  t_PixelData*      pData;     /* Pointer to icon memory, segmentation will copy icon image data into this memory  */
  eHLAIconState_t   eState;    /* icon state                                                                       */ 
  HLAIconPosition_t Pos;       /* position of current icon                                                         */
  void*             pRef;      /* pointer to reference data e.g. tracking list                                     */
} HLAIconData_t;

typedef struct HLAIconList_t
{
  HLAIconData_t*        pData;
  struct HLAIconList_t* pNext;
} HLAIconList_t;

typedef HLAIconList_t* pHLAIconList_t;
/**********************************/
/* defines/ typedefs for icon box */
/**********************************/


/***********************/
/* SEGMENTATION OUTPUT */
/***********************/

typedef union
{
  /* the 12 Bit raw value is valid from binarize row until segmentation process roi */
  /* the algo should always use the lux- value !!! */
  /*!< [12Bit] bayer pattern intensities (not linear) */
  uint16 raw;        /*!< [12Bit] bayer pattern intensities (not linear) */
    
  /* during process roi the 12 Bit value is converted into a linear lux value */
  /* the algo should only use this value                                      */ 
  uint16 lux;    /*!< [Lux] bayer pattern intensities in lux (linear + white balance for rgb) */
} HLASegNgb_t;

/*! @brief  internal structure for a local red maximum */
typedef struct
{
  uint16 x;                     /*!< maximum: horizontal position within ROI */
  uint16 y;                     /*!< maximum: vertical position within ROI   */
  uint8  i_ngb;                 /*!< index of maxima in ngb array            */
  ARRAY(HLASegNgb_t, HLA_SEG_MAX_NUM_NGB, ngb);  /*!< neighbour pixels of maxima */
                                                 /* ngb[0] always starts on green pixel in red row and blue column */ 
}HLASegMaxima_t;


/* Segline buffer interface version numbers */
#define SEGLINE_BUF_INTERFACE_VERSION_NUMBER_MAIN    2
#define SEGLINE_BUF_INTERFACE_VERSION_NUMBER_SUB     0
#define SEGLINE_BUF_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define SEGLINE_BUF_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN       << 24) \
                                              | (SEGLINE_BUF_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                              | (SEGLINE_BUF_INTERFACE_VERSION_NUMBER_SUB  << 8) \
                                              | (SEGLINE_BUF_INTERFACE_VERSION_NUMBER_BUGFIX) \
                                             )

typedef struct
{
  uint16 x;         /*!< horizontal position within ROI in absolute imager coordinates     */
  uint16 y1;        /*!< vertical start position within ROI in absolute imager coordinates */
  uint16 y2;        /*!< vertical end position within ROI in absolute imager coordinates   */
  uint16 yMax;      /*!< maximum position in this line in absolute imager coordinates      */
  uint16 iLineNext; /*!< index to next line of the region                                  */
} HLASegLine_t;

typedef struct
{
  uint16 iLine;  /* start position */
  uint16 nLines; /* number of lines of this level */
}HLASegLineLevel_t;

typedef struct 
{
  uint32                ui32_InterfaceVersionNumber;    /*!< Segline buffer interface number */    
  AlgoCycleCounter_t    HLAS_Cnt;                       /*!< HLAS cycle counter   */
  AlgoCycleCounter_t    FrameCnt;                       /*!< [1] image counter    */  
  AlgoDataTimeStamp_t   TimeStamp_Image_us;             /*!< [us] Image Timestamp */
  
  uint16 nLines; /* number of all seg. lines of all levels */
  /* only a subset of all segmented lines could be used (e.g. 800 lines, due to runtime) */
  /* the higher level will be used first */
  uint16 iLevelHigh;
  uint16 iLevelLow;
  ARRAY(HLASegLineLevel_t, RTE_HLA_SEG_MAX_NUM_LEVELS, Level);

  ARRAY(HLASegLine_t, HLA_SEG_MAX_NUM_SEG_LINES, Line); /* line data: position, iLineNext */

  /* padding bytes to be aligned to HLA_DSP_CACHE_LINE_SIZE */
  uint8 dummy[12u];
}HLASegLineBuffer_t;

typedef struct
{
  uint32 IsAssToTrack          : 1;  /*!< flag for region for which a light has been associated to a track */
  uint32 IsAssToPairedTrack    : 1;  /*!< flag for region for which a light has been associated to a track within a pair */
  uint32 numOPAss              : 2;  /*!< Bit02 */
  uint32 numLightAss           : 2;  /*!< Bit04 */
  uint32 IsRegionAboveROI      : 1;  /*!< Bit06 */
  uint32 Bit07                 : 1;  /*!< Bit07 */

  uint32 Bit08                 : 1;  /*!< Bit08 */
  uint32 Bit09                 : 1;  /*!< Bit09 */
  uint32 Bit10                 : 1;  /*!< Bit10 */
  uint32 Bit11                 : 1;  /*!< Bit11 */
  uint32 Bit12                 : 1;  /*!< Bit12 */
  uint32 Bit13                 : 1;  /*!< Bit13 */
  uint32 Bit14                 : 1;  /*!< Bit14 */
  uint32 Bit15                 : 1;  /*!< Bit15 */

  uint32 numLightInRegion      : 8;  /*!< Bit16 */

  uint32 LightCreated          : 1;  /*!< region created a light */
  uint32 LedLightCreated       : 1;  /*!< region created a LED light */
  uint32 MinorRegion           : 1;  /*!< Minor region = region below superior region, minor regions can not create a light */
  uint32 Bit27                 : 1;  /*!< Bit27 */
  uint32 Bit28                 : 1;  /*!< Bit28 */
  uint32 Bit29                 : 1;  /*!< Bit29 */
  uint32 Bit30                 : 1;  /*!< Bit30 */
  uint32 Bit31                 : 1;  /*!< Bit31 */
} HLASegRegionStatus_t;


typedef struct HLASegLineRegion_t
{
  /* x coordinate of left upper corner */
  uint16 x1;
  /* y coordinate of left upper corner */
  uint16 y1;

  /* x coordinate of right lower corner */
  uint16 x2;
  /* y coordinate of right lower corner */
  uint16 y2;

  uint8  Level; /* level of the region [0..7] */
  uint16 iLine; /* index to next line within this region */
  uint16 iLineLast; /* last Line of line chain */
  uint32 ySum;
  HLASegRegionStatus_t  Status; /* bitfield status for this region */
  
  struct HLASegLineRegion_t* pRegionBelow;
  uint8 iNext;
} HLASegLineRegion_t;


/* TRACKING defines */
#define    HLA_TRACKING3D_ASSOCTYPE_STATICROBUST    0u
#define    HLA_TRACKING3D_ASSOCTYPE_STATIC          1u
#define    HLA_TRACKING3D_ASSOCTYPE_DYNAMIC         2u

#define    HLA_TRACKING3D_TRACKERCLASS_UNKNOWN      1u
#define    HLA_TRACKING3D_TRACKERCLASS_STATIC       2u  /*!< track is a static point */
#define    HLA_TRACKING3D_TRACKERCLASS_DYNAMIC      3u  /*!< track is a dynamic point */

#define    HLA_TRACK_KALMANINPUTCMD_PREDICT                 1u
#define    HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT            2u
#define    HLA_TRACK_KALMANINPUTCMD_UPDATE_NOLIGHT          3u
#define    HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTLEFT        4u
#define    HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTRIGHT       5u

#define    HLA_TRACKSTAGE_KALMAN_INIT               0u
#define    HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS        1u
#define    HLA_TRACKSTAGE_KALMAN_RUN_FAIL           2u

#define    HLA_TRACKSTAGE_MAX_TRACK_TIME        63u
#define    HLA_TRACKSTAGE_MAX_TRACE_TIME        63u
#define    HLA_TRACKSTAGE_MAX_LOST_TIME         63u
#define    HLA_TRACKSTAGE_MAX_WIN_TIME          63u
#define    HLA_TRACKSTAGE_MAX_BITSIZE           6u /*  ceil(log2(63u)) */


typedef struct 
{
  uint32       statusTimeUpdate        : 2;
  uint32       statusPred              : 2;
  uint32       statusUpdate            : 2;
  uint32       statusDelayedUpdate     : 2;
  uint32       trackTimeToReinit       : HLA_TRACKSTAGE_MAX_BITSIZE;
  uint32       traceTimeToReinit       : HLA_TRACKSTAGE_MAX_BITSIZE;
  uint32       lostTime                : HLA_TRACKSTAGE_MAX_BITSIZE;
  uint32       winTime                 : HLA_TRACKSTAGE_MAX_BITSIZE;
}HLATrackerStage_t;


/*! Define type for classification results */
#define   HLA_RESULT_IDLE       0u
#define   HLA_RESULT_NEGATIVE   1u
#define   HLA_RESULT_POSITIVE   2u
#define   HLA_RESULT_ERROR      3u

#if (defined PC_SIM || defined EVAL_BOARD)
typedef struct
{
  uint32 setupNewTrack                                   : 1;

  uint32 newTrackReasonIsolatedLight                     : 1;
  uint32 newTrackReasonNotInPredArea                     : 1;
  uint32 newTrackReasonTestPairSuccess                   : 1;
  uint32 newTrackReasonIsolatedAboveROI                  : 1;
  
  uint32 noNewTrackReasonMaybeMissed                     : 1;
  uint32 noNewTrackReasonRedinWhiteRegion                : 1;
  uint32 noNewTrackReasonNotBrightEnough                 : 1;
  uint32 noNewTrackReasonIn2ManyPredArea                 : 1;
  uint32 noNewTrackReasonClosestTrackForMoreThan2Light   : 1;
  uint32 noNewTrackReasonOtherOPAssociated               : 1;
  uint32 noNewTrackReasonNotIsolatedAboveROI             : 1;
 
}HLASegLightForNewTrackAnalysis_t;
#endif

#define UI13_T_MAX  (8191u)   /* max for ui_dist */

typedef struct
{
  uint32               type          : 2 ;
  uint32               IDL           : 8 ;
  uint32               IDT           : 8 ;
  uint32               ui_dist       : 13;
  uint32               validHamming  : 1;

  uint32               invalidInt    : 1;
  uint32               invalidColor  : 1;
  uint32               free          : 30; 
#ifdef PC_SIM
  uint32               disthamming;
  float32              dist_int; 
  float32              dist_color;
  float32              dist_eucl;
  float32              IntensityTrack;
  float32              IntensityLight;
#endif
}HLACoupleData_t;

/* ~CodeReview ~ID:4edc8f369aff7d46d7077bf1ab3efd97 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:improve description of structure */
typedef struct
{
  uint32               ID            : 8;   /* the best association */
  uint32               ui_dist       : 13;
  uint32               count         : 3;   /* max 7 */
  uint32               invalidInt    : 1;
  uint32               invalidColor  : 1;
  uint32               free          : 6;
}HLAAssocInfo_t;


/* kalman measurement: position part */
typedef struct
{
  float32 x;            /*!< normalized horizontal coordinate */
  float32 y;            /*!< normalized vertical coordinate */
  float32 cxx;          /*!< variance of measurement x */  
  float32 cyy;          /*!< variance of measurement y */
  float32 cyx;          /*!< covariance of measurement y */
} HLAKalmanMeasPos_t;

typedef struct
{
  float32 x_center_pix;         /*!< light center in pixels */  
  float32 y_center_pix;         /*!< light center in pixels */
  float32 x_radius_pix;         /*!< horizontal radius in pixels */  
  float32 y_radius_pix;         /*!< vertical   radius in pixels */

} HLAKalmanMeasPosPix_t;

/* kalman measurement: position part */
typedef struct
{
  uint16  xmin,xmax;
  uint16  ymin,ymax;

} HLAKalmanMeasPosPixArea_t;

/* kalman measurement: intensity part */
typedef struct
{
  float32 ik;
  float32 sii;
} HLAKalmanMeasInt_t;

/* kalman measurement: color part */
typedef struct
{
  float32 ck;     /* red */
  float32 gk;     /* green */
  float32 scc;
  float32 sgg;
} HLAKalmanMeasCol_t;

/* kalman measurement (used for pairing) */
typedef struct
{
  /* position */
  HLAKalmanMeasPos_t              pos;

  /* intensity */
  HLAKalmanMeasInt_t              intL;

  /* color */
  HLAKalmanMeasCol_t              col;

} HLAKalmanMeas_t;

typedef struct
{
  uint32 Bit00                 : 1;  /*!<  */
  uint32 Bit01                 : 1;  /*!<  */
  uint32 HotPixel              : 1;  /*!< light is identified as a hot pixel and will not start a new track */
  uint32 associated            : 1;  /*!< if set, this light is associated a track */
  uint32 isOPLight             : 1;  /*!< flag for light created with the oncoming pair detection  */  
  uint32 testPair              : 1;  /*!< Bit6  */
  uint32 isAnyNGBSaturated     : 1;  /*!< indicates if any pixel in the ngb maxima is saturated */
  uint32 Bit07                 : 1;  

  uint32 countInPredArea       : 2;  /*!< count number of time light is inisde prediction area of a track ( < 4) */
  uint32 resultOP              : 2;  /*!< result of oncoming pair segmentation */
  uint32 assoc_type            : 2;  /*!< */
  uint32 isIsolatedLight       : 1;  /*!< */
  uint32 isInitializingTrack   : 1;  /*!< */

  uint32 Bit13                 : 1;
  uint32 Bit14                 : 1;
  uint32 DoNotStartNewTrack    : 1; /* do not start a new track on this light */
  uint32 Sat                   : 1; /* any pixel in T123 saturation -> do not trust the color */
  uint32 Sat_T1                : 1; /* any pixel in T1 saturation (motion Blur or pulsed light) -> do not trust the color */
  uint32 isPotRed              : 1; /* potential red light */
  uint32 isPotRed_dark         : 1; /* potential dark red light */
  uint32 isPotLed              : 1; /* potential Led light */
 
  uint32 isNewPairLight        : 1; /* new pair light */
  uint32 free                  : 7;
} HLASegLightStatus_t;


/* passed reason */
/* rejection reason */
#define HLA_SEG_LIGHT_PR_RED_BOTTOMUP 1
#define HLA_SEG_LIGHT_PR_RED_HIGHVALUE 2
#define HLA_SEG_LIGHT_PR_BRIGHT_BOTTOMUP 4
#define HLA_SEG_LIGHT_PR_LED_BOOTOMUP 8
typedef uint8 HLASegLightPassedReason_t;


/* rejection reason */
#define HLA_SEG_LIGHT_RR_DARKLIGHT 1
#define HLA_SEG_LIGHT_RR_LIGHTREDUCTION 2
typedef uint8 HLASegLightRejectedReason_t;


/*! @brief  structure for a segmented light */
typedef struct {
  uint16 xcenter;              /*!< horizontal position within ROI */
  uint16 ycenter;              /*!< vertical position within ROI */
  
  uint8 current_R;             /*!< 8Bit Trichromatic coordinates: current_R + current_G + current_B = 255 */
  uint8 current_G;             /*!< 8Bit Trichromatic coordinates: current_R + current_G + current_B = 255 */
  uint8 current_B;             /*!< 8Bit Trichromatic coordinates: current_R + current_G + current_B = 255 */
  
    
  uint8 nT1Sat; /* number of pixels in T1 saturation */

  uint8 RegionLevel0_ID;       /*!< region level 0 ID (= buffer index) */
  
  /* ~CodeReview ~ID:b89abfe264fcb2b6cf67bd63c3ec49ab ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:improve description of variable contents */
  uint8 LightID;               /*!< light identifier */
  uint8 LightID_RTE;           /* light array index in rte output */
  uint8 TrackID0;              /*!< TrackID of the first possible associated track */  

  uint8 iLightNext;     /*!< index of next light */
  uint8 iLightNext_sub; /*!< index to next light of the the sub category (red, led, bright light) */
    
  uint8 Dummy1;  

  uint16 MaxInt;      /*!< max. intensity in lux */

  HLASegMaxima_t Maxima;
  
  HLASegLightStatus_t Status;  /*!< light status */

  /* passed/rejected reason of light */
  HLASegLightPassedReason_t   PassedReason[2];    /* 1st [index 0] (rte output) and 2nd [index 1] (hla tracking input) filter stage */
  HLASegLightRejectedReason_t RejectedReason[2];  /* 1st [index 0] (rte output) and 2nd [index 1] (hla tracking input) filter stage */
  
  HLAAssocInfo_t   infoAssoc2Light[2];

  HLASegLineRegion_t *pRegion; /*!< pointer to underlying region used for clustering */

#if (defined PC_SIM || defined EVAL_BOARD)
  HLASegLightForNewTrackAnalysis_t    newTrackAnalysis;
  uint8     nLightInRegionsBelow;
  uint16    xLmin,xLmax,yLmin,yLmax;
  
  /* pixel coordinates */
  HLAKalmanMeasPosPix_t    posPix;
#endif

} HLASegLight_t;

typedef struct
{
  uint32               HLAS_Cnt;           /*!< HLAS cycle counter   */
  AlgoCycleCounter_t   FrameCnt;           /*!< [1] image counter    */  
  AlgoDataTimeStamp_t  TimeStamp_Image_us; /*!< [us] Image Timestamp */
  ARRAY(HLASegLight_t, HLA_SEG_MAX_NUM_LIGHTS, Light);
} HLASegLightBuffer_t;

typedef enum 
{
  HLA_DATA_STATE_INIT     = 0u, /*!< init value    */
  HLA_DATA_STATE_VALID    = 1u, /*!< valid value   */
  HLA_DATA_STATE_INVALID  = 2u, /*!< invalid value */
  HLA_DATA_STATE_ERROR    = 3u, /*!< ERROR         */

  HLA_DATA_STATE_LAST     = SI32_T_MAX
} eHLADataState_t;

#define HLA_DATA_STATE_MAX_CNT 63u

typedef struct
{
  uint8 State : 2;  /* = eHLASegSubImageState_t: init/ valid/ invalid value or Error */
  uint8 Cnt   : 6;  /* state counter: how many cycles in this state                  */
} HLADataState_t;

typedef struct
{
  ARRAY(float32, HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES,        Mean);
  float32         Mean_HistMedian; /* median of history */
  ARRAY(float32, HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES,        Median);
  float32         Median_HistMedian; /* median of history */
  float32         Min;
  float32         Max;
  ARRAY(float32, HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES,        Max80);
  float32         Max80_HistMedian; /* median of history */
  HLADataState_t  State;
} HLASegSubImageStatistic_t;

typedef struct
{
  /* subsampled image, active when hla is active, active at night */
  ARRAY2D(float32, HLA_SEG_INTENSITY_SUB_IMG_HEIGHT, HLA_SEG_INTENSITY_SUB_IMG_WIDTH,   SubImage_lux);      /* [lux] */
  ARRAY(float32, HLA_SEG_INTENSITY_SUB_IMG_HEIGHT * HLA_SEG_INTENSITY_SUB_IMG_WIDTH,    SubImageSort_lux);  /* [lux] sorted array */
  ARRAY(HLADataState_t, HLA_SEG_INTENSITY_SUB_IMG_HEIGHT,                               SubImage_State);

  /* hla roi (above roi and hla function roi) */
  HLASegSubImageStatistic_t RoiInt; /* all intensity values in lux */

  /* above hla function roi */
  HLASegSubImageStatistic_t AboveRoiInt; /* all intensity values in lux */
  
  /* hla function roi */
  HLASegSubImageStatistic_t FunctRoiInt; /* all intensity values in lux */
  
  /* below horizon roi */
  HLASegSubImageStatistic_t BelowHorRoiInt; /* all intensity values in lux */
  
  uint32          iArrayCurCycle; /* array position of current cycle */
} HLASegSubImage_t;


typedef struct
{
  AlgoCycleCounter_t     HLAS_Cnt;           /*!< HLAS cycle counter   */
  AlgoCycleCounter_t     FrameCnt;           /*!< [1] image counter    */  
  AlgoDataTimeStamp_t    TimeStamp_Image_us; /*!< [us] Image Timestamp */

  /* lux level which defines the regions  */
  HLA_t_ObjectRegionLevel RegionLevel;
  

  /* pointer to segmentation line buffer */
  HLASegLineBuffer_t *pLineBuffer;
  /* segmentation region array */
  HLASegLineRegion_t *Region;
  /* segmentation light array */
  HLASegLight_t *Light;

  /* index of first light in the list (chain) */
  uint8 iLight;
  /* pointer to start of light buffer memory  */
  /* only used to derive the Light ID = position in the array */ 
  HLASegLight_t           *pLightMemoryStart;
  /* number of segmented lights  = merged maxima */
  uint8                   nLights;

  /* subsampled image */
  HLASegSubImage_t        SubImage;
   
  HLA_t_Fingerprint       Fingerprint;
} HLASegOut_t;
/***********************/
/* SEGMENTATION OUTPUT */
/***********************/


#ifdef PC_SIM
typedef struct 
{
  uint32   isDelayedUpdateNegStatic      : 1;
  uint32   isDelayedUpdateNegDynamic     : 1;
  uint32   isNewTrackTooClose            : 1;
  uint32   isOutOfImage                  : 1;
  uint32   isTooMuchRelativeLostTime     : 1;
  uint32   isTooMuchAbsoluteLostTime     : 1;
  uint32   isBigUncertaintyStateDynamic  : 1;
} DeathReason_t;
#endif

typedef struct 
{
  uint16 distMin_cm;                    /* min distance */                        
  uint16 distMax_cm;                    /* max. distance */
}HLATrackDist_t;                                 


typedef struct 
{
  /* cross-correlation between landmarks */
  float32 cuu,cuv,cud;
  float32 cvu,cvv,cvd;
  float32 cdu,cdv,cdd;
} TracksCrossCorr_t;

typedef struct FullEgoData_t
{
  /* position of track in global track buffer */  
  TracksCrossCorr_t   *pCrossCorrelations;

  /* static state part */
  float32             uw,vw,dw;

  /* variances */
  float32             cuu,cvv,cdd;

  /* cross-correlation between landmark variable */
  float32             cvu,cdu,cdv;

  /* cross-correlation between landmark and online cali */
  float32             cuy,cup,cur;
  float32             cvy,cvp,cvr;
  float32             cdy,cdp,cdr;

  /* cross-correlation between landmark and egomotion */
  float32             euy,eup,eur;
  float32             evy,evp,evr;
  float32             edy,edp,edr;

  /* temporary values */
  float32             v00,v01,v02,v03,v04,v05;
  float32             v06,v07,v08,v09,v10,v11;
  float32             v12,v13,v14,v15,v16;
  
  /* tracker stage */
  HLATrackerStage_t   stageTrackSlam;

  /* position in memory */
  uint8               slot;

  /*! pointer to next full ego track inside the list */  
  struct FullEgoData_t* next;

  /*! pointer to next full ego track inside the list sorted by increasing distance to prediction */  
  struct FullEgoData_t* next_sorted;

  /*! pointer to corresponding track */  
  struct HLATrack_t* pTrack;

} FullEgoData_t;

#define  HLA_TV_TRAFFIC_TYPE_UNKWOWN      0
#define  HLA_TV_TRAFFIC_TYPE_ONCOMING     1
#define  HLA_TV_TRAFFIC_TYPE_AHEAD        2
#define  HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS  3

#define  HLA_TV_DEATHREASON_MAX_CYCLE_PAIR_LOST                0x0001 /* bit  00 */
#define  HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK_INPAIR        0x0002 /* bit  01 */
#define  HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK_INPAIR       0x0004 /* bit  02 */
#define  HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK               0x0008 /* bit  03 */
#define  HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK              0x0010 /* bit  04 */
#define  HLA_TV_DEATHREASON_LEFT_TRACK_REMOVED                 0x0020 /* bit  05 */
#define  HLA_TV_DEATHREASON_RIGHT_TRACK_REMOVED                0x0040 /* bit  06 */
#define  HLA_TV_DEATHREASON_PAIR_EARLY_DEATH                   0x0080 /* bit  07 */
#define  HLA_TV_DEATHREASON_NOT_COMFIRMED_PAIR                 0x0100 /* bit  08 */
#define  HLA_TV_DEATHREASON_PD_OUT_OF_RANGE                    0x0200 /* bit  09 */
#define  HLA_TV_DEATHREASON_PS_OUT_OF_RANGE                    0x0400 /* bit  10 */
#define  HLA_TV_DEATHREASON_PA_OUT_OF_RANGE                    0x0800 /* bit  11 */
#define  HLA_TV_DEATHREASON_PR_OUT_OF_RANGE                    0x1000 /* bit  12 */
#define  HLA_TV_DEATHREASON_KALMAN_FAILED                      0x2000 /* bit  13 */


typedef struct HLAPair_t
{
  /* pair state */
  float32 pd;         /* distance */
  float32 pl;         /* lateral position */
  float32 ph;         /* height */
  float32 pr;         /* roll as a delta-height */
  float32 py;         /* yaw */
  float32 ps;         /* velocity */

  /* appearence state */
  float32 pa;         /* intensity constant */
  float32 pc;         /* red chromaticity */
  float32 pg;         /* green chromaticity */

  /* covariance of pair state */
  float32 ppdd;
  float32 ppld,ppll;
  float32 pphd,pphl,pphh;
  float32 pprd,pprl,pprh,pprr;
  float32 ppyd,ppyl,ppyh,ppyr,ppss;
  float32 ppsd,ppsl,ppsh,ppsr,ppys,ppyy;

  /* covariance on appearence state */
  float32 ppaa;
  float32 ppcc;
  float32 ppgg;

  /* 3D occupation */
  /* ~CodeReview ~ID:cd1d698438d3c20787a381473d05b1f3 ~Reviewer:CW01\uidt9253 ~Date:6/27/2012 ~Priority:2 ~Comment:should be local variables to save RAM */
  float32 xwmin;
  float32 xwmax;
  float32 ywmin;
  float32 ywmax;

  /* relative velocity */
  float32 relVel;

  /* pair confidence */
  float32  confidence;

  /* trace time */
  uint16  track_time_pair2;
  uint16  trace_time_pair;

  /* lost time */
  uint8   lost_time_left;
  uint8   lost_time_right;
  uint8   lost_time_pair;

  /* bit flags */
  /* ~CodeReview ~ID:0cb4ec7d6f0ab9aadbd87a77b56f3ba7 ~Reviewer:CW01\uidt9253 ~Date:6/26/2012 ~Priority:3 ~Comment:put bit field into a struct data type, i.e. the SDL compiler fails on open bit fields */
  uint8 bit_willBeRemoved                         : 1;   /*!< Bit_00 */
  uint8 bit_TrafficType                           : 2;   /*!< Bit_01-02 */
  uint8 bit_isTracked                             : 1;   /*!< Bit_03 */
  uint8 bit_canBeTracked                          : 1;   /*!< Bit_04 */
  uint8 bit_bornFromPairTest                      : 1;   /*!< Bit_05 */
  uint8 bit_isAssocToRemove                       : 1;   /*!< Bit_06 */
  uint8 bit_dummies                               : 1;  /*!<  */

  /* tracker stage */
  HLATrackerStage_t   stageTrackPair;  

  /* pair death analysis */
  uint16              pairDeathAnalysis;

  /*! pointer to next target vehicle inside the list */  
  struct HLAPair_t* next;

  /*! pointer to next target vehicle inside a temporary chain */  
  /* ~CodeReview ~ID:7e90dbd028316a2518fe513a9959379d ~Reviewer:CW01\uidt9253 
         ~Date:6/27/2012 ~Priority:2 ~Comment:should be local variable to save RAM */
  ARRAY(struct HLAPair_t*, HLA_TRACKING_MAX_NUM_PAIRS, tableTVNext);
  struct HLAPair_t** ppPairNext;

  /*! pointer to corresponding track */  
  struct HLATrack_t* pTLeft;
  struct HLATrack_t* pTRight;

#ifdef PC_SIM
  uint8 PairID;
  uint8 has2meas;
  float32 db_pd;
  float32 db_pl;         /* lateral position */
  float32 db_ph;         /* height */
  float32 db_pa;         /* light intensity constant  */
  float32 db_pr;         /* roll as a delta-height */
  float32 db_pc;         /* color state: red chromaticity */
  float32 db_pg;         /* color state: green chromaticity */
  float32 db_mli;
  float32 db_mlc;
  float32 db_mlg;
  float32 db_mri;
  float32 db_mrc;
  float32 db_mrg;
#endif

} HLAPair_t;

#if defined(PC_SIM) || defined(EVAL_BOARD)
typedef struct 
{
  float32 xbLeftLane[HLA_TRACKING3D_NUM_LANE_POINTS_VISU_YAW_RATE];
  float32 ybLeftLane[HLA_TRACKING3D_NUM_LANE_POINTS_VISU_YAW_RATE];
  float32 xbRightLane[HLA_TRACKING3D_NUM_LANE_POINTS_VISU_YAW_RATE];
  float32 ybRightLane[HLA_TRACKING3D_NUM_LANE_POINTS_VISU_YAW_RATE];
} YawRateVisu_t;
#endif

#define  HLA_ICONRESULT_NEGATIVE   0
#define  HLA_ICONRESULT_POSITIVE   1
#define  HLA_ICONRESULT_SATURATED  2

#define  HLA_ICONRESULT_MAX_CLASS_RESPONSE    10

typedef struct
{
  uint8 result                        : 2;           /* icon classification result */
  sint8 classResponse                 : 5;           /* classification response value */
  uint8 iconMissed                    : 1;           /* Bit is set for missed Icon */
} IconResultInfo_t;

typedef struct 
{
  uint16 iconRequested                 : 1;           /* icon is requested for the next frame */
  uint16 ledDetectionCalled            : 1;           /* icon led detection has been applied */
  uint16 streetLampDetectionCalled     : 1;           /* icon street lamp classifier has been applied */
  uint16 redLightDetectionCalled       : 1;           /* icon red light classifier has been applied */
  uint16 successivePosResultCnt        : 2;           /* counter for consecutive positive icon classification results */
  uint16 successiveNegResultCnt        : 2;           /* counter for consecutive positive icon classification results */

  uint16 skippedBadPosition            : 1;           /* classification skipped because the predicted position didn't match the track position */
  uint16 Bit_09_15                     : 7;           /* Bit 09 - 15 */
} IconStatus_t;

typedef struct  
{
  IconResultInfo_t resultInfo;
  IconStatus_t status;           /* various status bits */
  uint8 cyclesNoClass;           /* cycles since last icon classification, reset to 0 after each classification */
  uint8 classCnt;                /* total number of applied icon classifications */
  sint16 classResultSum;         /* summed up classification response result from IconResultInfo. Increased for vehicle, decreased for no vehicle. */

#ifdef PC_SIM
  float32 classResultThresholdSizePenalty;
  float32 classResultThresholdBrightnessPenalty;
  float32 classResultThresholdPositionPenalty;
  float32 classResultThreshold;

  uint16  redCountLed;
  uint16  redCountTotal;
  float32 redCountThreshold;
  uint16  greenCountLed;
  uint16  greenCountTotal;
  float32 greenCountThreshold;
  uint16  redGreenCountLed;
  uint16  redGreenCountTotal;
  float32 redGreenCountThreshold;
  uint16  blueCountLed;
  uint16  blueCountTotal;
  t_PixelData maxRed;
  t_PixelData maxGreen;
  t_PixelData maxBlue;
#endif

} IconState_t;

#ifdef PC_SIM

/*! typedef struct for the camera parameters */
typedef struct
{
  struct {
    ARRAY(int,    4, pair_searchbox);                 /*!< the search box for light pairs. */ 
    ARRAY(float,  2, size_dist);
    unsigned char is_valid_proj;
    ARRAY(float,  2, proj_dist);
    ARRAY(float,  2, single_dist);
    signed char is_valid_pair;
    float pair_dint;
    float pair_drgb;
    float pair_dx, pair_dy;
    float pair_dsize;
    float pair_dmotion;
    float pair_dslope;
    int   pair_match_value;
    short pair_dist;
    int   pair_id;
    float cur_dist;
  }distEst;
  union {
    int allBits;
    struct {
      int   accepted           : 1;
      int   not_dieing         : 1;
      int   above_horizon      : 1;
      int   short_tracktime    : 1;
      int   not_oncoming       : 1;
      int   not_lateral_moving : 1;
      int   too_slow_min_speed : 1;   
    }bit;
  }trafficStyleReason;
  struct {
    struct {
      unsigned char trace : 1;            /*!< track was used for oc by trace */
      unsigned char pair  : 1;            /*!< track was used for oc by pair distance */
    }accepted;
    float img_height_from_pair_dist;      /*!< img height that would match pair distance */
    sint16 xcenter_start;
    sint16 ycenter_start;
  }onlineCalibration;
  struct {
    int curr_classification; /*0=unknown, 1=ahead, 2=oncoming*/
    float nn_out;
  }drivingDirection;
} HLADebugTrackListnode_t;
#endif

/*! Analysis status for vehicles */
typedef struct
{
  uint32 isPotentialVehicleOncoming1st  : 1;  /*!< flag for potential oncoming traffic after 1st analysis level */
  uint32 isPotentialVehicleAhead1st     : 1;  /*!< flag for potential leading traffic after 1st analysis level  */
  uint32 isPotentialVehicleOncoming2nd  : 1;  /*!< flag for potential oncoming traffic after 2nd analysis level */
  uint32 isPotentialVehicleAhead2nd     : 1;  /*!< flag for potential leading traffic after 2nd analysis level  */
  uint32 isVehicleOncoming              : 1;  /*!< flag for reliably detected oncoming traffic */
  uint32 isVehicleAhead                 : 1;  /*!< flag for reliably detected leading traffic  */
  uint32 isTooBright                    : 1;  /*!< flag for objects, which lay over defined intensity thresholds */
  uint32 isRed                          : 1;  /*!< flag for red objects */
                                                       
  uint32 isPulsedLight                  : 1;  /*!< flag for pulsed lights, like LED tail lamps */
  uint32 isRed2                         : 1;  /*!< flag #2 for red objects */
  uint32 isMovingWhite                  : 1;  /*!< flag for contra motion with white color */
  uint32 isMovingNonWhite               : 1;  /*!< flag for contra motion with non-white color */
  uint32 isOncomingPair                 : 1;  /*!< flag for oncoming pair detection */
  uint32 isCenterBright                 : 1;  /*!< flag for centered bright objects */
  uint32 isExtremeBright                : 1;  /*!< flag for extreme bright objects */
  uint32 isLateralBright                : 1;  /*!< flag for lateral bright objects */

  uint32 isHighwayBright                : 1;  /*!< flag for a light oncoming on a highway */
  uint32 isHighwayBrightTruckLights     : 1;  /*!< Bit_17 */
  uint32 Bit_18                         : 1;  /*!< Bit_18 */
  uint32 Bit_19                         : 1;  /*!< Bit_19 */
  uint32 isPotentialVehicleHighProbable : 1;  /*!< flag for potential candidate with high probability to become a detected vehicle soon */
  uint32 Bit_21                         : 1;  /*!< Bit_21 */
  uint32 Bit_22                         : 1;  /*!< Bit_22 */
  uint32 Bit_23                         : 1;  /*!< Bit_23 */

  /* flags for the 2nd level analysis */
  uint32 isClassResultReached           : 1;  /*!< flag for successful icon classification result */
  uint32 isSuddenlyAppearingVehicle     : 1;  /*!< flag for overriding icon classification because of suddenly appearing vehicle */
  uint32 isDriveDistAheadReached        : 1;  /*!< flag for overriding icon classification because of long driving behind traffic ahead */
  uint32 isDriveDistAheadDynamicReached : 1;  /*!< flag for overriding icon classification because of long driving behind traffic ahead detected as dynamic */
  uint32 isDriveDistAheadPairReached    : 1;  /*!< flag for overriding icon classification because of long driving behind traffic ahead detected as pair light */
  uint32 isOvertaker                    : 1;  /*!< flag for overriding icon classification because of overtaking vehicle */
  uint32 isHighwayOncomingCar           : 1;  /*!< flag for overriding icon classification because of fast oncoming detector on highways */
  uint32 Bit_31                         : 1;  /*!< Bit_31 */
} HLAStatusAnalysisVehicle_t;

/*! Analysis status for other objects */
typedef struct
{
  uint32 isBrigthSLS                    : 1;  /*!< flag for object that is bright enough to be a Scene Street Lamp9 */
  uint32 isAboveROI                     : 1;  /*!< flag for object that are above main ROI. */
  /* ~CodeReview ~ID:2b5b807ea35f324d1cbe68b8e95d133e ~Reviewer:CW01\uid28828 ~Date:27/03/2012 ~Priority:3 ~Comment:isInfinite is not updated */
  uint32 isInfinite                     : 1;  /*!< flag for very far objects */
  /* ~CodeReview ~ID:3d17554235ccc05946c0a1d28d321009 ~Reviewer:CW01\uid28828 ~Date:27/03/2012 ~Priority:3 ~Comment:is3DCorrect is not updated */
  uint32 is3DCorrect                    : 1;  /*!< flag for object with a correct static 3D estimation */
  uint32 isFarToRoi                      : 1;  /*!< flag for object that are far to main ROI*/
  uint32 isFarToFOE                     : 1;  /*!< flag for object that are far to FOE */
  uint32 isChainOfLight                 : 1;  /*!< flag for object that are in a chain of light */
  uint32 isHotTrack                     : 1;  /*!< flag for tracks detected as hot pixels */

  uint32 isFarAboveHorizon              : 1;  /*!< flag for objects far above horizon */
  uint32 isAboveHorizon                 : 1;  /*!< flag for objects above horizon */
  uint32 isSceneStreetLamp              : 1;  /*!< flag for object that are scene street lamp */
  uint32 isLeavingStreetLamp            : 1;  /*!< flag for object that are leaving street lamp */
  uint32 isBrightObject                 : 1;  /*!< flag for bright objects which could blind the driver (headlamp dimming candidates) */
  uint32 isNOTLeavingStreetLamp         : 1;  /*!< flag for objects which cannot be detected as leaving street lamp */
  uint32 isSceneStreetLampLowInt        : 1;  /*!< flag for object that are scene street lamps for signal */
  uint32 isSceneStreetLampIcon          : 1;  /*!< Bit_15 */
                                                         
  uint32 isConverging                   : 1;  /*!< Bit_16 */
  uint32 isFarObject                    : 1;  /*!< Bit_17 */
  uint32 isLeavingStreetLamp_MaybeCity  : 1;  /*!< Bit_18 */
  uint32 isSceneStreetLampTunnel        : 1;  /*!< Bit_19 */
  uint32 isBrigthSLS_Tunnel             : 1;  /*!< Bit_20 */
  uint32 isInTruckLightRegion           : 1;  /*!< Bit_21 */
  uint32 isPotentialTruckLight          : 1;  /*!< Bit_22 */
  uint32 Bit_23                         : 1;  /*!< Bit_23 */
                                                       
  uint32 Bit_24                         : 1;  /*!< Bit_24 */
  uint32 Bit_25                         : 1;  /*!< Bit_25 */
  uint32 Bit_26                         : 1;  /*!< Bit_26 */
  uint32 Bit_27                         : 1;  /*!< Bit_27 */
  uint32 Bit_28                         : 1;  /*!< Bit_28 */
  uint32 Bit_29                         : 1;  /*!< Bit_29 */
  uint32 Bit_30                         : 1;  /*!< Bit_30 */
  uint32 Bit_31                         : 1;  /*!< Bit_31 */
} HLAStatusAnalysisMisc_t;

/*! @brief Track status word */
typedef struct 
{
  uint32 willBeRemoved               : 1;  /*!< flaf for tracks to be removed next cycle */
  uint32 reinitStaticNextChance      : 1;  /*!< reinit static tracker with next association */
  uint32 IsSLAssociated              : 1;  /*!< Is associated to a Street Lamp Node */
  uint32 isOneToOneAssociation       : 1;  /*!< set to 1 when track can only be associated to ONE light, and associated 
                                                light can only be associated to this track, and light is isolated : it's a robust association */
  uint32 isAssocToRemove             : 1;  /*!< Bit_04 */
  uint32 isAnyNGBSaturatedLastLight  : 1;  /*!< Bit_05 */
  uint32 isCodePatternAvailable      : 1;  /*!< Bit_06 */
  uint32 isPotLedLastLight           : 1;  /*!< Bit_07 */
  
  uint32 isLinked2Pair               : 1;  /*!< flag for tracks linked to a pair of tracks */
  uint32 isLinked2PairTemp           : 1;  /*!< temporary flag for tracks linked to a pair of tracks */  
  uint32 isTrackedInPair             : 1;  /*!< flag for tracks tracked within a pair */
  uint32 isRepjFromPair              : 1;  /*!< Track reprojection comes from the pair traker */
  uint32 isPredFromPair              : 1;  /*!< Track prediction comes from the pair traker */
  uint32 isAssocFromPair             : 1;  /*!< Track to Light Association was made with the pair tracker */
  uint32 isBornFromPairTest          : 1;  /*!< flag for tracks born because they form a pair with another track */
  uint32 testPairForBirth            : 1;  /*!< flag for tracks that should be tested by the pair detection algo in order to confirm their birth */
  
  uint32 deathDueToBornFromPairTest  : 1;  /*!< Bit_16 */
  uint32 isTrackedPairToRemove       : 1;  /*!< Bit_17 */
  uint32 isTTBFromPair               : 1;  /*!< Bit_18 */
  uint32 Bit_19                      : 1;  /*!< Bit_19 */
  uint32 isEpipolarConsistent        : 1;  /*!< Bit_20 */
  uint32 isEpipolarConsistentTemp    : 1;  /*!< Bit_20 */
  uint32 Bit_22                      : 1;  /*!< Bit_22 */
  uint32 Bit_23                      : 1;  /*!< Bit_23 */
  
  uint32 isRGBAvailable              : 1;  /*!< Bit_24 */
  uint32 Bit_25                      : 1;  /*!< Bit_25 */
  uint32 Bit_26                      : 1;  /*!< Bit_26 */
  uint32 Bit_27                      : 1;  /*!< Bit_27 */
  uint32 Bit_28                      : 1;  /*!< Bit_28 */
  uint32 Bit_29                      : 1;  /*!< Bit_29 */
  uint32 Bit_30                      : 1;  /*!< Bit_30 */
  uint32 Bit_31                      : 1;  /*!< Bit_31 */
} StatusWord_t;

/*! Type definition for the result state. */
typedef struct 
{
  sint8 confidence  :6; /*!< confidence range from -31 (negative) over 0 (unknown) to 31 (positive) */
  uint8 result      :2; /*!< the result state for the analysis. */
} HLAResultState_t;

/*! Type definition for the analysis result state. */
typedef struct 
{
  HLAResultState_t isTooBright;                         /*!< analysis result state from too bright classification  */
  HLAResultState_t isContraMotion;                      /*!< analysis result state from contra motion classification */
  HLAResultState_t isCloseReflector;                    /*!< analysis result state from close reflector classification */
  HLAResultState_t isOncomingPair;                      /*!< analysis result state from oncoming pair classification */
  HLAResultState_t isCenterBright;                      /*!< analysis result state from centered bright classification */
  HLAResultState_t isExtremeBright;                     /*!< analysis result state from extreme bright classification */
  HLAResultState_t isOtherColor;                        /*!< analysis result state from other-color classification */
  HLAResultState_t isWhiteOrRed;                        /*!< analysis result state from white-or-red classification */
  HLAResultState_t isPulsedLight;                       /*!< analysis result state from pulsed light classification */
  HLAResultState_t isLateralBright;                     /*!< analysis result state from lateral bright classification */
  HLAResultState_t isDynamicMotion;                     /*!< analysis result state from dynamic tracked object classification */
  HLAResultState_t isStaticHigh;                        /*!< analysis result state from static high object classification */
  HLAResultState_t isHighwayBright;                     /*!< analysis result state from highway oncoming lights classification */
  HLAResultState_t isHighwayBrightTruckLights;
} HLAAnalysisResultState_t;

/*! Type definition for the identification result state. */
typedef struct 
{
  HLAResultState_t isTooBright;                         /*!< identification result state from too bright classification */
  HLAResultState_t isContraMotion;                      /*!< identification result state from contra motion classification */
  HLAResultState_t isCloseReflector;                    /*!< identification result state from close reflector classification */
  HLAResultState_t isStreetLamp;                        /*!< identification result state from street lamp classification */
  HLAResultState_t isChainOfLights;                     /*!< identification result state from chain of lights classification */
  HLAResultState_t isOncomingPair;                      /*!< identification result state from oncoming pair classification */
  HLAResultState_t isCenterBright;                      /*!< identification result state from centered bright classification */
  HLAResultState_t isExtremeBright;                     /*!< identification result state from extreme bright classification */
  HLAResultState_t isOtherColor;                        /*!< identification result state from other-color classification */
  HLAResultState_t isWhiteOrRed;                        /*!< identification result state from white-or-red classification */
  HLAResultState_t isPulsedLight;                       /*!< identification result state from pulsed light classification */
  HLAResultState_t isLateralBright;                     /*!< identification result state from lateral bright classification */
  HLAResultState_t isDynamicMotion;                     /*!< identification result state from dynamic tracked object classification */
  HLAResultState_t hasHighIntensityFlux;                /*!< result state 14 */
  HLAResultState_t isStaticHigh;                        /*!< identification result state from static high object classification */
  HLAResultState_t isHighwayBright;                     /*!< identification result state from highway oncoming lights classification */
  HLAResultState_t isHighwayBrightTruckLights;
} HLAIdentificationResultState_t;


/***********************/
    /* CITY */
/***********************/
/* Max number of analyzed street lamps */
#define MAX_NUM_SL 40

/* STREET LAMP OUTPUT */
typedef enum
{
  HLA_SL_CLOSE          = 0u, /* Close to own vehicule */
  HLA_SL_MIDDLE         = 1u, /* Middle distance to own vehicule */
  HLA_SL_FAR            = 2u, /* Far to own vehicule */

  HLA_SL_DIST_LAST      = SI32_T_MAX
}eEstDist_t;

/* STREET LAMP HISTORY */
typedef struct
{
  /* Raw Intensity History */
  ARRAY(float32, SL_LP_ORDER_PLUS_ONE, RawIntHist);

  /* Low Pass Filtered Intensity History */
  ARRAY(float32, SL_LP_ORDER_PLUS_ONE, LPIntHist);

  /* Nb Tot of Sample */
  sint16 NbTotSample;

  /* (#Sample) Last Filtered Intensity Local Maximum */
  sint16 LastMaxNb;

  /* (#Sample) Last Filtered Intensity Local Minimum */
  sint16 LastMinNb;

  /* Last Filtered Intensity Local Maximum Value in Lux */
  float32  LastMaxLux;

  /* Last Filtered Intensity Local Minimum Value in Lux */
  float32  LastMinLux;

  /* Estimation of the Distance */
  eEstDist_t eEstDist;

}HLAStreetLampHist;

/* STREET LAMP */


typedef enum
{
  HLA_SL_SHAPE_IDLE        = 0u, /* Idle State */
  HLA_SL_SHAPE_1time      = 1u, /* Once Street Lamp Shape Detected */
  HLA_SL_SHAPE_DTCD        = 2u, /* Street Lamp Shape Detected */
  HLA_SL_TOO_BRIGHT        = 3u, /* Too Bright */
  HLA_SL_RED_LAMP         = 4u, /* Red Lamp */
  HLA_SL_NOT_FLICKERING    = 5u, /* Not Flickering Light */

  HLA_SL_SHAPE_LAST        = SI32_T_MAX
} eStreetLampShape_t; /* Street Lamp detection output */

#ifdef PC_SIM
  typedef enum
  {
     HLA_SL_BEHAVE_IDLE     = 0u,   /* Idle State */
     HLA_SL_3D_DYN_OK       = 1u,   /* Good 3d & good dynamic */
     HLA_SL_3D_BAD          = 2u,   /* Bad 3D */
     HLA_SL_ND              = 3u,   /* Negative Detection */
     HLA_SL_LOW_3D_CONF      = 4u,   /* Low confidence on 3D coordinates */
     HLA_SL_TOO_LARGE       = 5u,   /* Too Large */
     HLA_SL_NOT_STATIC      = 6u,   /* Not Static */
     HLA_SL_BAD_2D_DIR      = 7u,   /* Bad 2D Direction */
    HLA_SL_BEHAVE_LAST      = SI32_T_MAX
  } eStreetLampBehave_t; /* Street Lamp detection output */
  typedef enum
  {
    HLA_SL_TRUE            = 0u,
    HLA_SL_FALSE           = 1u,
    HLA_SL_IDLE            = 2u,

    HLA_SL_STATE_LAST      = SI32_T_MAX
  } eSignatureState_t; /* Street Lamp detection output */

#endif

typedef struct HLA_SL_ListNode_t
{
  /*! Street Lamp History */
  HLAStreetLampHist      Hist;

  /*! Street Lamp Shape */
  eStreetLampShape_t      eStreetLampShape;

  /*! next street lamp */
  struct HLA_SL_ListNode_t  *next;

  /*! Associated Track */
  struct HLATrack_t  *pT;

}HLA_SL_ListNode_t;
/***********************/
    /* CITY */
/***********************/
typedef struct  
{
  uint8 Bit_00                  : 1;  /*!< Bit_00 */
  uint8 isBehind                : 1;  /*!< Bit_01 */   
  uint8 Bit_02                  : 1;  /*!< Bit_02 */
  uint8 isDecisiveForTurnOff1   : 1;  /*!< Bit_03 */
  uint8 isDecisiveForTurnOff2   : 1;  /*!< Bit_04 */
  uint8 Bit_05                  : 1;  /*!< Bit_05 */
  uint8 Bit_06                  : 1;  /*!< Bit_06 */
  uint8 Bit_07                  : 1;  /*!< Bit_07 */
} HLA_City_ListNode_Status_t;

typedef struct HLA_City_ListNode_t
{
  HLA_City_ListNode_Status_t status;

  uint8   numSceneStreetLampInSameCorridor;
  uint8   numBorderingStreetLamp;

  float32   sumSL_y;
  float32   sumsquareSL_y;
  float32   sumSL_x;
  float32   odometer;

  sint16    xw100;
  sint16    xwUnfiltered100;
  sint16    yw100;
  sint16    MinDistSceneSL100;
  sint16    xwStraightRd100;

  /*! next street lamp */
  struct HLA_City_ListNode_t  *next;

}HLA_City_ListNode_t;
#ifdef PC_SIM

typedef enum
{
  SCENESL_GOOD             = 0,
  SCENESL_NOT_LEAVING      = 1,
  SCENESL_POSITION_2D      = 2,
  SCENESL_VEHICLE          = 3,
  SCENESL_SHORT_TRACK_TIME = 4,
  SCENESL_MOVING_DOWN      = 5,
  SCENESL_SKY_LIGHT        = 6,
  SCENESL_RED_LIGHT        = 7,
  SCENESL_NOT_SL_IDRES     = 8,
  SCENESL_POSITION_3D      = 9,
  SCENESL_ISFAROBJECT      = 10,
  SCENESL_LOWINTENSITYFLUX = 11,
  SCENESL_LEAV_GAP         = 12,
  SCENESL_MOVING_BKWARD    = 13,
  SCENESL_LEAVINGSL        = 14
}eHLASceneSL_t;


typedef enum
{
  SCENESL_TUNNEL_GOOD          = 0,
  SCENESL_TUNNEL_NOT_SCENESL   = 1,
  SCENESL_TUNNEL_LOWINT        = 2,
  SCENESL_TUNNEL_POSITION_3D   = 3,
  SCENESL_TUNNEL_POSITION_2D   = 4,
  SCENESL_TUNNEL_NOT_CONVERGING = 5
}eHLASceneSL_Tunnel_t;

typedef enum
{
  SCENESL_ICON_GOOD           = 0,
  SCENESL_ICON_NOT_SCENESL    = 1,
  SCENESL_ICON_LOW_SCORE      = 2,
  SCENESL_ICON_NOT_CONVERGING = 3,
  SCENESL_ICON_LEAV_GAP       = 4
}eHLASceneSL_Icon_t;

typedef enum
{
  LEAVSL_GOOD           = 0,
  LEAVSL_NOT_SCENESL    = 1,
  LEAVSL_NOT_LEAVING    = 2,
  LEAVSL_POSITION_3D    = 3,
  LEAVSL_ICON_LOW_SCORE = 4
}eHLALeavingSL_t;

#endif

/*! @brief track list node */
/* List of modules to define parameter usage
0 head_light_assist
1 auto_eval
2 auto_label
3 hla_analysis
4 hla_blackboard
5 hla_decision
6 hla_distanalysis
7 hla_tracking
8 hla_visualization
9 fba_classification
A fba_output
B fba_track_veh_pos
C fba_veh_hypotheses
D fba_visualization
E full_beam_assist
F fba_outputResults
*/
/* Used in modules: 123456789ABCDEF */
/* ~CodeReview ~ID:e4ec6947271ba8a059f4712afb29f61b ~Reviewer:CW01\uidt9253 ~Date:6/26/2012 ~Priority:3 ~Comment:restructure HLATrack_t by sorting and grouping variables into substructures */
/* ~CodeReview ~ID:d9a468749aaab0e27d40da91522fdae4 ~Reviewer:CW01\uidt9253 ~Date:6/26/2012 ~Priority:3 ~Comment:remove the obsolete CSF comments, document variables */
typedef struct HLATrack_t
{
  /*! analysis result state buffer */
  HLAAnalysisResultState_t anaResStat;

  /*! identification result state buffer */
  HLAIdentificationResultState_t idResStat;

  /*! status buffer for the vehicle analysis */
  HLAStatusAnalysisVehicle_t statusAnalysisVehicle;

  /*! status buffer for the analysis of other objects */
  HLAStatusAnalysisMisc_t statusAnalysisMisc;

  uint16 driveDistCmPotAhead1st;               /*! driven distance in centimeters where potential proceeding vehicle in 1st level was indicated */
  uint16 driveDistCmPotAhead1stDynamic;        /*! driven distance in centimeters where potential proceeding vehicle in 1st level classified as dynamic tracking object was indicated */
  uint16 driveDistCmPotAhead1stPair;           /*! driven distance in centimeters where potential proceeding vehicle in 1st level classified as pair light was indicated */

  /* distance to prediction */
  uint16      dist2Pred;

  /*! pointer to next track inside the list */  
  struct HLATrack_t* next;           /* Used in modules: 123456789ABCDEF */ /* 32 Bit Element #11 */

  /*! pointer to next track for temporary listing */  
  /* ~CodeReview ~ID:e55e0f3b38043febc70c05214c6b616d ~Reviewer:CW01\uidt9253 ~Date:6/19/2012 ~Priority:2 ~Comment:memory (4*85=340 byte) can be avoided when used as local memory */
  struct HLATrack_t* nextTemp;           /* Used in modules: 123456789ABCDEF */ /* 32 Bit Element #11 */

  /*! final association */  
  HLASegLight_t* light_ref;                  /* Used in modules: --3--678-A--D-F */ /* 32 Bit Element #19 */

  /*! distance estimation paired track */
  struct HLATrack_t* dist_est_pair_link;  /* Used in modules: --3--67-----D-F */

  /*! Bit field of tracking status */
  StatusWord_t TrackingStatus;              /* Used in modules: 123-56789-BCDEF */ /* 32 Bit Element #1 */  

  /*! lowpass filtered track motion inside the image (without any ego motion compensation) */
  float32 delta_x_lp, delta_y_lp;            /* Used    in modules: 1-3-56789---DEF */ /* 32 Bit Element #6, #7 */
                                                 /* Updated in modules: ------7-------- */

  /* Pointer to the leaving street lamp associated in the leaving street lamp list used for CITY */
  HLA_City_ListNode_t* pAssociatedLeavSL;

  /*! long time filtered motion inside the image */
  float32 delta_y_lp_lt;       /* Used    in modules: 1-3-5-7-------- */ /* 32 Bit Element #21, #22 */
                                                 /* Updated in modules: ------7-------- */
  /*! time to border */
  float32 ttb;                              /* Used    in modules: 1-3-5-789----E- */ /* 32 Bit Element #20 */
                                            /* Updated in modules: --3------------ */    

  /* Modified ttb for a border at 18° in world cs. Calculated using 3D information */
  float32 ttb18;

  /* distance estimation from pairing */
  HLATrackDist_t          objectDist;

  /* distance estimation from height hypothesis */
  HLATrackDist_t          lightDist;

  /*! age of the track */
  uint16 trace_time;

  /*! number of associations during lifetime */
  uint16 track_time;

  /*! trace time of first vehicle detection */
  uint16 trace_time_firstVehicleDetection;

  /*! position of the track in image coordinates */
  sint16 xcenter, ycenter;

  /*! track motion inside the image (without any ego motion compensation) */
  sint16 delta_x, delta_y;

  /* ~CodeReview ~ID:643e067be8def8f446c9c7b5409c6db4 ~Reviewer:CW01\uidt9253 ~Date:6/19/2012 ~Priority:2 ~Comment:not used in algo but filled in HLA output interface for historical reasons */
  /*! first detection position of track in ROI coordinates */
  sint16 xcenter_FD, ycenter_FD;            


  IconState_t iconState;
  IconState_t iconStateCity;

  /* stores the length of chain of light, if the node is part of the chain. 
  In other case the value is undefined and should not be used.
  the value is in range [0, 100] */
  uint8 lengthChainOfLight;

  uint16 MaxInt;         /*! [lux] max. intensity in lux                   */
#ifdef PC_SIM
  float32 MaxIntOfTrack;  /*! [lux] max. intensity of track during lifetime */
  float32 MaxIntFirst;    /*! [lux] first intensity of track                */
  float32 LuminousFlux;
#endif
  uint16 AverageMaxInt;   /*! [lux] running average of the max intensity */

  /*! count hot track detection */
  uint8 countHotTrack;

  /*! Hash value to save last associated light */
  uint8 LightHash;

  /* red light counter */
  uint8       RedLightCnt;
  uint8       RedLightCnt4City; /* used in city detection */
  /* ------------------------- */
  /* --- PC_SIM variables --- */
  /* ------------------------- */

#ifdef PC_SIM

  float32 dist_motion_m;

  /* NO USE WITH EGOMOTION except TrackID */

  /*! serial counter for each light */  
  uint32 lightCount;                        /* Used in modules: 12----78-A--D-F */
  /*! stores the minimum max_intensity value */
  uint8 minimumIntensityOfTrack;            /* Used in modules: ------78-A--D-- */
  /*! stores the time need to detect the oncoming traffic. */
  uint16 trackTimeToTurnOff;                /* Used in modules: --3---78----D-- */

  /*! PC_SIM: link to debug parameter struct */
  HLADebugTrackListnode_t DebugParameter;   /* Used in modules: -----6-8----D-F */

  /* Street Lamp Debug */
  eStreetLampBehave_t eStreetLampBehave;
  eSignatureState_t e3D;
  eSignatureState_t e2D;
  eSignatureState_t eDyn;

  /* World coordinates for City */
  float32 xwSL,ywSL;

  uint32 specFirstTurnOffReason;

  /* Traffic style */
  RTE_HLA_TrafficStyle eTrafficStyle;
#endif

  /* ---------------------------------------------------------*/
  /* DATA FROM EGOMOTION */

  /* tracker stage */
  HLATrackerStage_t   stageTrackStatic;
  HLATrackerStage_t   stageTrackDynamic;

  /*! store trackID */
  uint8               TrackID;

  /*! number of lost updates (reset if track is updated)   */
  uint8               lost_time;

  /* tracker class (dynbamic/static/static robust) */
  uint8               TrackerClass;

  /* result of death analysis */
  uint8               trackDeathAnalysis;

  /* static state part */
  float32             uw,vw,dw;

  /* variances */
  float32             cuu,cvv,cdd;

  /* cross-correlation between landmark variable */
  float32             cvu,cdu,cdv;

  /* min-max Xw world coordinates (depth) with 0.01m resolution */
  uint16              xwmin100,xwmax100;

  /* min-max Yw world coordinates (lateral) with 0.01m resolution */
  sint16              ywmin100,ywmax100;

  /* min-max Zw world coordinates (lateral) with 0.01m resolution */
  sint16              zwmin100,zwmax100;

  /* pointer to full egomotion data */
  FullEgoData_t     *pFullEgoData;

  /* Dynamic prediction part */
  float32             ox_p, oy_p;
  float32             osxx; 
  float32             osxy,osyy;

  uint16              xmin,xmax;
  uint16              ymin,ymax;

  /* pairing roi to the right */ 
  /* ~CodeReview ~ID:64a84aefee44972b01b3e37139e6ed8b ~Reviewer:CW01\uidt9253 ~Date:6/19/2012 ~Priority:2 ~Comment: memory (8*85=680 byte) can be avoided when used as local memory*/
  uint16              xminR,xmaxR;
  uint16              yminR,ymaxR;

  /* Dynamic state part */
  float32             ouk,ovk;
  float32             ouw,ovw,odw,os,ol;
  float32             ofw;

  /* Covariances of dynamic state part */
  float32             couu;
  float32             covu,covv;
  float32             codu,codv,codd;
  float32             cosu,cosv,cosd,coss;
  float32             colu,colv,cold,cols,coll;

  /* counters for dynamic object detection */
  uint8               timeLastPatternUpdate;
  uint8               countRobustStatic;

  /* intensity filter */
  uint16              minInt12bits;
  /* ~CodeReview ~ID:0f58823787740d08e7db2f50bff1c5c3 ~Reviewer:CW01\uidt9253 ~Date:6/19/2012 ~Priority:2 ~Comment:can be reduced to uint16 (rounding error of the running average to be analyzed) */
  float32             MaxIntFilt;

  /* track pattern */
  uint32              codePattern;

  uint8               current_R;
  uint8               current_G;
  uint8               current_B;
  uint8               timeLastRGBUpdate;

  /* association data */
  HLAAssocInfo_t      infoAssoc2Track[2];
 
#ifdef PC_SIM

  DeathReason_t       DeathReason;

  /* visu data static part */
  ARRAY(float32, 2,             xb_pred_pix);
  ARRAY(float32, 2,             xb_pred_pix_3sig);

  /* visu data dynamic part */
  ARRAY(float32, 2,             xb_pred_dynamic_pix);
  ARRAY(float32, 2,             xb_pred_dynamic_pix_3sig);

  /* visu data dynamic part */
  ARRAY(float32, 2,             xb_pred_dynamic_tracker_pix);
  ARRAY(float32, 2,             xb_pred_dynamic_tracker_pix_3sig);

  /* visu exclusion area */
  float32             ex_xmin,ex_xmax;
  float32             ex_ymin,ex_ymax;

  float32             min_dist_dynamic;
  float32             max_dist_dynamic;

  float32             varMeasInit;

  uint32            numFrameStart;
  uint32            numFrameEnd;

  /* hamming distance between light and track pattern */
  uint32              dist_hamming;

  /* association data debug */
  HLACoupleData_t         db_assoc_final;
  ARRAY(HLACoupleData_t, DB_HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK,         db_lights);
  uint32              db_n;
  uint8               db_new_pattern;

  /* SL exclusion reason */
  eHLASceneSL_t eHLASceneSL;
  eHLASceneSL_Tunnel_t eHLASceneSL_Tunnel;
  eHLASceneSL_Icon_t eHLASceneSL_Icon;
  eHLALeavingSL_t eHLALeavingSL;

  /* optical flow visualization */
  float32             xs,ys;
  float32             dxs,dys;

  uint8 isCityMoving;
  uint8 bCitySceneSL_gap;
  uint8 bCityLeavSL_POS3D;
  uint8 bCityLeavSL_NotLeaving;
  uint8 bCitySceneSL_POS2D;
  uint8 bCitySceneSL_POS3D;
  uint8 bCitySceneSL_TUNNEL_POS2D;
  uint8 bCitySceneSL_TUNNEL_POS3D;  
  uint8 bCityMoveState;

#endif

} HLATrack_t;


/*! typedef struct for the internal headlight control data. */
/* ~CodeReview ~ID:ee5b7f4df0ef4a64d4b9755727e9d37a ~Reviewer:CW01\uidt9253 ~Date:7/13/2012 ~Priority:3 ~Comment:unused data type */
typedef struct
{
  
  RTE_HLAF_HighBeamState      HighBeamState; /* internal hla (NOT HLA PLUS !!!) high beam state */
} HLAHeadlightControlDataInternal_t;



/****************************/
/* highway detection output */
/****************************/
/* Highway structures */
#define HLA_HIGHWAY_DEATH_AREA_NUM_MEAN  20 /* should not be superior to 20*/

/* Oncoming Struct */
typedef  struct  
{
  sint16                      DeathAreaX;
  sint16                      DeathAreaY;
  RTE_HLAR_HighwayLatPosState e_LateralPosition;
} HLAHighwayStatusOncoming_t;

/* Internal Data */
typedef struct
{
  /* Mean Death Area */
  ARRAY(HLAHighwayStatusOncoming_t, HLA_HIGHWAY_DEATH_AREA_NUM_MEAN, OncomingHist);
  uint8  DeathAreaInd;
  float32 DistToLastOncoming;

  /* Counters */
  uint16 CountOncoming;
  uint16 LastCount;
  uint8 NewDeathCount;
  uint8 NewPreDeathCount;
  boolean bLastCountFirstUpdate;
  boolean bLastCountSecondUpdate;

  /* Highway detection */
  float32 DistHwayDction;
  float32 DistHwayUndef;
  float32 DistHwaySpeedDction;

  /* Divided Rdway detection */
  sint16 ThreshDividedRdwayXb;
  sint16 ThreshDividedRdwayYb;

  /* Normal Rdway detection */
  sint16 ThreshNormalRdwayXb;
  sint16 ThreshNormalRdwayYb;

  /* Occlusion Detection */
  sint16  ThreshPrematureX;
  sint16  ThreshPrematureY;
  sint32  OcclusionCount;

  /* Confidences */
  float32  ConfLatPos;
  float32  ConfEgoMotion;
  float32  ConfOcclDction;

  /* Results */
  RTE_HLAR_HighwayLatPosState          eLateralPosition;
  RTE_HLAR_HighwayEgoMotionState       eEgoMotion;
  RTE_HLAR_eHighwayOcclusionState      eOcclusionDetection;
  RTE_HLAR_eHighwaySpeedDetectionState eHighwaySpeedDetection;

  /* Highway Exit Detection */
  float32  Curvature;
  float32  DistPossibleExit;
  float32  YawIntegrate;
  float32  YawIntegrateMin;
  float32  YawIntegrateMax;
  boolean  bHwayExit;

  /*Internal Highway state*/
  RTE_HLAF_MotorwayState internalHighwayState;

#ifdef PC_SIM
  /* Min Death Area */
  sint16 MinDeathAreaX;
  sint16 MinDeathAreaY;

  /* Max Death Area */
  sint16 MaxDeathAreaX;
  sint16 MaxDeathAreaY;
  float32 MaxDeathAreaCoeff;

  /* Odometer filter with oncoming traffic */
  float32 Odometer;
#endif

}HLAHighwayInternalData_t;

/****************************/
/* highway detection output */
/****************************/

/*! typedef struct for the internal weather detection data */
typedef struct
{
  RTE_HLAR_WeatherState eWeatherState;   /* internal weather state    */
  uint16              FogLampCnt;     /* fog lamp on / off counter */
  uint16              Dummy;
} HLAWeatherData_t;

/*! Type definition for on-line cali data */
typedef struct
{
  /* online cali */
  float32                     cal_yaw;
  float32                     cal_pitch;
  float32                     cal_roll;

  float32                     ccyy;
  float32                     ccpy, ccpp;
  float32                     ccry, ccrp, ccrr;
  
  float32                     odometerOnLineCaliM;
  float32                     cal_yaw_conf;
  float32                     cal_pitch_conf;
  float32                     cal_roll_conf;

  float32                     ccyymax,ccppmax,ccrrmax;
  float32                     ccyymin,ccppmin,ccrrmin;

  uint8                       cal_pitch_changed;
  uint8                       cal_yaw_changed;
  uint8                       cal_roll_changed;

#if defined(PC_SIM) || defined(EVAL_BOARD)
  /* on-line cali visu */
  float32                     xbCalLeft;
  float32                     ybCalLeftMin;
  float32                     ybCalLeftMax;
  float32                     xbCalRight;
  float32                     ybCalRightMin;
  float32                     ybCalRightMax;

  float32                     ybCalUp;
  float32                     xbCalUpMin;
  float32                     xbCalUpMax;
  float32                     ybCalDown;
  float32                     xbCalDownMin;
  float32                     xbCalDownMax;
#endif
} HLATracking3DDataCali_t;

/*! Type definition for egomotion data */
typedef struct
{
  /* egomotion */
  float32                     ego_length;
  float32                     ego_yaw;
  float32                     ego_pitch;
  float32                     ego_roll;

  float32                     eeyy;
  float32                     eepy, eepp;
  float32                     eery, eerp, eerr;

  /* extreme values of egomotion */
  float32                     eeyy_ex;
  float32                     eepp_ex;
  float32                     eerr_ex;

  /* correlations between online cali and egomotion */
  float32                     ecyy, ecyp, ecyr;
  float32                     ecpy, ecpp, ecpr;
  float32                     ecry, ecrp, ecrr;

  /* interframe delta time in s */
  float32                      dt;                

  /* vehicke speed */
  float32                     ego_speed;
  float32                     ego_yawrate;

  /* number of tracks used for online cali and egomotion*/      
  uint8                       numTracksCrossCorr;
  uint8                       numTracksCrossCorrUpdated;

  /* number of iterations in the RANSAC algorithm for essential matrix estimation */
  uint32                      numIterRANSACEpipol;

#if defined(PC_SIM) || defined(EVAL_BOARD)
  /* yaw rate visualization */
  YawRateVisu_t        vdyYawRateVisu;
  YawRateVisu_t        egoYawRateVisu;
#endif

} HLATracking3DDataEgomotion_t;

/*! Type definition tracking3D debug info */
typedef struct
{
  float32                     confPairingGlobal;
  uint8                       numPairsTracked;
  uint8                       numPairsCanBeTracked;
  
#if defined(PC_SIM) || defined(EVAL_BOARD)
  uint32            numFrame;
#endif
} HLATracking3DDataDebug_t;

/* 3D tracking Output */
typedef struct
{
  HLATrack_t*                         pTrack;                 /* list of tracked lights */
  uint8                               numTracks;              /* number of tracks */
  HLAPair_t                           *pPairs;                /* list of vehicles */
  uint8                               numPairs;               /* number of vehicles */
  HLATracking3DDataCali_t             dataCali;               /* on-line cali data */
  HLATracking3DDataEgomotion_t        dataEgomotion;          /* egomotion data */
  HLATracking3DDataDebug_t            dataDebug;              /* data for debug */
  
}HLATracking3DOutput_t;

/* function prototypes */

/* Street Lamp analysis Input */
typedef struct
{
  HLA_SL_ListNode_t*                pStreetLampsBufferFree;
  HLA_SL_ListNode_t*                pStreetLampsBuffer;
  const HLA_t_Tracking3DParameters*  pTracking3DParams;
}HLASLInput_t;


typedef struct  
{
  uint8 StreetLampSignal            :1;
  uint8 StreetLampSignal_LowInt     :1;
  uint8 InhibAtFirst                :1;
  uint8 MaybeCity                   :1;
  uint8 bInit                       :1;
  uint8 unused                      :3;
} HLACityData_Status_t;

/*! typedef struct for the city detection data. */
typedef struct
{
  RTE_HLAR_CityState      internalCityState;

  HLACityData_Status_t  status;

  uint8                 numConsecutiveStreetLampState;
  uint8                 numConsecutiveStreetLampState_LowInt;

  float32               numFrames;
  sint16               distLeavSL100_NoMaybeLeavSL;

  /* allocate memory for SL_ListNode */
  ARRAY(HLA_City_ListNode_t, HLA_CITY_NUM_STREETLAMP, hlaFreeLeavSLBuffer);
  HLA_City_ListNode_t*  pLeavSLBufferFree;
  HLA_City_ListNode_t*  pLeavSLBuffer;      /* Leaving Street Lamps in front or behind the car */

#ifdef PC_SIM
  boolean bCityEntry;
  boolean bCityExit;
  float32 HeightAssumpSL;
  float32 LeavingSLdistance;
  float32 maxDistStreetLamp100;
  float32 filter;
  uint8 eDetecion;
  float32 maxYwDist_3dEstLeav_Left;
  float32 maxYwDist_3dEstLeav_Right;
  float32 Radius;
#endif

  float32 subimagesum;
  ARRAY(float32, 9, CityLuxSum);
  ARRAY(float32, 9, CityLuxFeat);
  ARRAY(float32, 9, CityLuxFeatThresh);
  uint8 IsLowAmbientLight;
  
  HLAResultState_t IsAmbientLight;
  HLAResultState_t TooBright;

} HLACityData_t;


/**********************************************
 ***            TUNNEL DETECTION            ***
 **********************************************/

/* definition for tunnel detection inputs */
typedef struct
{
  const HLASegSubImage_t*     pHLASubImage;
  /* const HLA_t_MotionState*    pHLAMotionState; */
  HLATrack_t*                 pTrackStart;
  RTE_HLAR_BrightnessState    eBrightnessState;
  RTE_HLAR_CityState          eCityState;
  float32                     dDistFwd_m;
} HLATunnelInput_t;

/* definition of internal tunnel state machine */
typedef enum eTunnelStateMachine_t
{
  TSM_NO_TUNNEL,      /* no tunnel detected */
  TSM_ENTRY,          /* possible tunnel entry */
  TSM_INSIDE_TUNNEL,  /* inside tunnel */
  TSM_EXIT            /* tunnel exit detected */
} eTunnelStateMachine_t;

/* definition for tunnel detection types */
typedef enum eTunnelDetectionType_t
{
  TDT_UNKNOWN,  /* unknown status in the beginning */
  TDT_DAY,      /* day time */
  TDT_NIGHT     /* night time */
} eTunnelDetectionType_t;

/* structure of the analysis data for tunnel recognition  */
typedef struct HLATunnelFeatures_t
{
  /* array to store the 10 different luminance groups for a frame */
  ARRAY(float32, TUNNEL_FEATURE_NUMBER, frame_luminances);
  /* distance covered within one frame */
  float32                     frame_distance;
  /* pointer to the next feature structure */
  struct HLATunnelFeatures_t* pNext;

  /* TODO: need further fields? */

} HLATunnelFeatures_t;

/* structure to store the output of tunnel recognition  */
typedef struct
{
  /* feature struct which contains the averaged feature values */
  HLATunnelFeatures_t         filteredFeat;
  /* pointer to start element of feature history */
  struct HLATunnelFeatures_t* pFeaturesStart;
  /* array to store the lux values at tunnel entry*/
  ARRAY(float32, TUNNEL_THRESHOLD_NUMBER, threshValue);
  /* frame counter for tunnel detection */
  float32                     detected_dist;
  /* covered distance within a frame */
//  float32                     frame_dist;
  /* internal tunnel state machine */
  eTunnelStateMachine_t       tunnelState;
  /* internal tunnel detection type */
  eTunnelDetectionType_t      eTunnelDetectionType;
} HLATunnelOutput_t;

typedef struct
{
  /* allocate memory for analysis data */
  ARRAY(HLATunnelFeatures_t, TUNNEL_FEATURE_LENGTH, tunnel_feature_buffer);
  /* internal flag to ensure that enough data was filtered */
  boolean bBufferReady;
} HLATunnelData_t;

/****************************/
/* Chain of Light           */
/****************************/

/*! typedef struct for the chain of light detection. */
typedef struct
{
    /* Associate track */
    HLATrack_t* pT;

    /* Indice + 1 to upper track in the array trackClusterList from the HLAChainOfLightData_t struct */
    uint8 tCntUp;

    /* Indice + 1 to track below  in the array trackClusterList from the HLAChainOfLightData_t struct */
    uint8 tCntBelow;

    /* angle between the vector through Reference-Upper-Nodes and Reference-Lower-Nodes */
    sint32 angleUL;

    /* Only for debugging needed */
    uint8 up1;
    uint8 up2;
    uint8 below1;
    uint8 below2;

}HLATrackClusterList_Node_t;

/*! typedef struct for the chain of light detection. */
typedef struct
{
    /* The 2D-list with tracks of all chains */
    ARRAY2D(HLATrack_t*,NB_OF_CHAINS, MAX_LENGTH_CHAIN,clusterTrackList);

    /* list with trackClusters look at HLATrackClusterList_Node_t */
    ARRAY(HLATrackClusterList_Node_t, NB_OF_TRACKS, trackClusterList);

    /* number of detected chains */
    uint8 chaincounter;

    /* number of tracks used for chain of light detection */
    uint8 numberOfTracks;
}HLAChainOfLightData_t;

#endif /* #ifndef HLA_BASE_INCLUDED */
