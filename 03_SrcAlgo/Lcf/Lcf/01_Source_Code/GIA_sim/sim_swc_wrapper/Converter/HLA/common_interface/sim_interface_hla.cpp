/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_adapter

MODULNAME:            sim_interface_hla.cpp

DESCRIPTION:          

AUTHOR:               Marcus Brunn

CREATION DATE:        03.08.2010

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_interface_hla.cpp  $
CHANGES:              Revision 1.1 2021/12/13 17:23:25CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/common_interface/project.pj
CHANGES:              Revision 1.0 2017/03/03 10:34:56CET Sorge, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/common_interface/project.pj
CHANGES:              Revision 1.1 2014/03/18 16:58:48CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/hla_adapter/common_interface/project.pj
CHANGES:              Revision 1.96 2014/03/12 18:07:25CET Mutschler, Matthias (uidv7867) 
CHANGES:              Added LRF on EVE
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:26 PM CET]
CHANGES:              Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.95 2014/03/10 17:13:27CET Brunn, Marcus (brunnm) 
CHANGES:              support hlar_in interface  version 2.4.0
CHANGES:              --- Added comments ---  brunnm [Mar 10, 2014 5:13:28 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.94 2014/03/10 13:05:12CET Manz, Alexander (uidv8777) 
CHANGES:              Update:
CHANGES:               - changed DimmingAreas to match the specs of BMW
CHANGES:               - implemented visualization
CHANGES:              --- Added comments ---  uidv8777 [Mar 10, 2014 1:05:13 PM CET]
CHANGES:              Change Package : 224162:1 http://mks-psad:7002/im/viewissue?selection=224162
CHANGES:              Revision 1.93 2014/03/04 18:00:49CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed ppars and vehpar from RTE and internal interface
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:50 PM CET]
CHANGES:              Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.92 2014/03/04 12:58:53CET Mutschler, Matthias (uidv7867) 
CHANGES:              Support for I390 RTE
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:53 PM CET]
CHANGES:              Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.91 2014/02/06 16:02:33CET Mutschler, Matthias (uidv7867) 
CHANGES:              Refactoring of hla debug output (time meas, removed redundant stuff)
CHANGES:              Centralized Null pointer checks
CHANGES:              Refactored dframe calculation
CHANGES:              --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:34 PM CET]
CHANGES:              Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
CHANGES:              Revision 1.90 2014/01/30 16:13:10CET Brunn, Marcus (brunnm) 
CHANGES:              adapter update for mfc4xx I320 rec-files
CHANGES:              --- Added comments ---  brunnm [Jan 30, 2014 4:13:10 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.89 2014/01/10 18:33:46CET Mutschler, Matthias (uidv7867) 
CHANGES:              First part of LRF on EVE (disabled)
CHANGES:              Merged LRF inputs into one struct
CHANGES:              Fixed exception handling of internal cali 
CHANGES:              Removed all tabs in the code and further clean-up
CHANGES:              --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:47 PM CET]
CHANGES:              Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.88 2013/12/05 17:47:52CET Mutschler, Matthias (uidv7867) 
CHANGES:              Update to RTE I330
CHANGES:              --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:52 PM CET]
CHANGES:              Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.87 2013/11/21 17:53:43CET Mutschler, Matthias (uidv7867) 
CHANGES:              Merge from NEW_SEG branch
CHANGES:              --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:43 PM CET]
CHANGES:              Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.86.1.1 2013/11/21 13:38:12CET Mutschler, Matthias (uidv7867) 
CHANGES:              Improved Icon normalize
CHANGES:              Bug fixes in segmentation
CHANGES:              Removed no longer compiler switches
CHANGES:              --- Added comments ---  uidv7867 [Nov 21, 2013 1:38:12 PM CET]
CHANGES:              Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.86 2013/11/19 13:44:23CET Brunn, Marcus (brunnm) 
CHANGES:              - clean up -> removed unused vars/ functions
CHANGES:              - added detailed time measurement for segmentation
CHANGES:              --- Added comments ---  brunnm [Nov 19, 2013 1:44:23 PM CET]
CHANGES:              Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
CHANGES:              Revision 1.85 2013/10/24 12:20:05CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Added more time meas for segmentation internally
CHANGES:              --- Added comments ---  uidv7867 [Oct 24, 2013 12:20:05 PM CEST]
CHANGES:              Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
CHANGES:              Revision 1.84 2013/10/24 11:16:32CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Adapted HIL to latest changes
CHANGES:              Fixed segline buffer visu
CHANGES:              --- Added comments ---  uidv7867 [Oct 24, 2013 11:16:32 AM CEST]
CHANGES:              Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
CHANGES:              Revision 1.83 2013/08/28 11:19:15CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Changed adapter according to new camera parameter struct
CHANGES:              --- Added comments ---  uidv7867 [Aug 28, 2013 11:19:15 AM CEST]
CHANGES:              Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
CHANGES:              Revision 1.82 2013/08/27 17:13:33CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed icon extraction
CHANGES:              --- Added comments ---  uidv7867 [Aug 27, 2013 5:13:33 PM CEST]
CHANGES:              Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
CHANGES:              Revision 1.81 2013/08/21 18:21:02CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Improved sorting on EVE quite a lot
CHANGES:              --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:02 PM CEST]
CHANGES:              Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
CHANGES:              Revision 1.80 2013/08/09 17:51:33CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed time measurement of HIL
CHANGES:              --- Added comments ---  uidv7867 [Aug 9, 2013 5:51:33 PM CEST]
CHANGES:              Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.79 2013/08/05 20:41:20CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed EVE/DSP caching issues
CHANGES:              Added time meas struct for EVE
CHANGES:              --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:21 PM CEST]
CHANGES:              Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.78 2013/07/31 10:36:17CEST Manz, Alexander (uidv8777) 
CHANGES:              Fix: replaced GenTargetList_t with the correct EM_t_GenObjectList to be used for EcoLight Detection
CHANGES:              --- Added comments ---  uidv8777 [Jul 31, 2013 10:36:17 AM CEST]
CHANGES:              Change Package : 192041:1 http://mks-psad:7002/im/viewissue?selection=192041
CHANGES:              Revision 1.77 2013/07/26 17:28:54CEST Manz, Alexander (uidv8777) 
CHANGES:              Update:
CHANGES:              - First implementation of EcoLight functionality
CHANGES:              - Changed measFreeze addresses of HLAR_In, HLAR_Out, HLAF_In, HLAF_Out and HLA_SystemInfo due to overlapping regions
CHANGES:              --- Added comments ---  uidv8777 [Jul 26, 2013 5:28:54 PM CEST]
CHANGES:              Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
CHANGES:              Revision 1.76 2013/07/18 18:12:13CEST Manz, Alexander (uidv8777) 
CHANGES:              Updates due to RTE change:
CHANGES:              Includes: 
CHANGES:               - new HeadlightState
CHANGES:               - EcoLight Feature
CHANGES:               - Light Dimming Areas Feature
CHANGES:               - Light adaptive image display settings for MTS visu
CHANGES:               - SRLCam rec file support in visu
CHANGES:              --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:13 PM CEST]
CHANGES:              Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
CHANGES:              Revision 1.75 2013/04/11 16:20:53CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Implemented some coding parameters
CHANGES:              Tunnel is now global turn off reason
CHANGES:              --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:54 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.74 2013/04/09 16:30:04CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE (SW_COMMON_03.01.01_INT-4)
CHANGES:              --- Added comments ---  uidv7867 [Apr 9, 2013 4:30:05 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.73 2013/03/26 17:27:52CET Manz, Alexander (uidv8777) 
CHANGES:              Adapted Tunnel Detection to use BMW Kodierparameter
CHANGES:               == Warning: not fully tested yet, though it should work (with an emphasis on should) ==
CHANGES:              --- Added comments ---  uidv8777 [Mar 26, 2013 5:27:53 PM CET]
CHANGES:              Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
CHANGES:              Revision 1.72 2013/03/21 17:20:26CET Manz, Alexander (uidv8777) 
CHANGES:              First step of US Sensitivity Mode implementation.
CHANGES:               - added Sensitivity to HLA_t_Availability
CHANGES:               - added visualization
CHANGES:              Revision 1.71 2013/03/18 14:13:40CET Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to new RTE (not yet released)
CHANGES:              --- Added comments ---  uidv7867 [Mar 18, 2013 2:13:41 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.70 2013/03/13 19:11:55CET Brunn, Marcus (brunnm) 
CHANGES:              HLAF: used Matrix.MaxNumGlarefreeArea from HLAF Parameter input
CHANGES:              --- Added comments ---  brunnm [Mar 13, 2013 7:11:55 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.69 2013/03/13 17:34:33CET Brunn, Marcus (brunnm) 
CHANGES:              added HLA parameter to HLAR/F input interface
CHANGES:              --- Added comments ---  brunnm [Mar 13, 2013 5:34:34 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.68 2013/03/12 14:12:02CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 2:12:03 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.67 2013/03/12 10:59:23CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:24 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.66 2013/03/11 18:02:03CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replace some types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 6:02:03 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.65 2013/03/11 16:13:40CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLA_t_eLightStyle
CHANGES:              - HLA_t_eTunnel
CHANGES:              - HLA_t_eCityState
CHANGES:              - HLA_t_eWeatherState
CHANGES:              - HLA_t_eMotorwayState
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:40 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.64 2013/03/11 14:32:58CET Mutschler, Matthias (uidv7867) 
CHANGES:              Placed no longer needed by RTE ones
CHANGES:              - HLA_t_eBrightnessState
CHANGES:              - HLA_t_eLightOutput
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:58 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.63 2013/03/11 10:37:26CET Brunn, Marcus (brunnm) 
CHANGES:              initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
CHANGES:              --- Added comments ---  brunnm [Mar 11, 2013 10:37:27 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.62 2013/03/08 17:42:58CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed HeadlightState and taken RTE type into use
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 5:42:58 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.61 2013/03/08 10:30:56CET Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:56 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.60 2013/03/04 11:53:47CET Mutschler, Matthias (uidv7867) 
CHANGES:              Added HLAF timemeas
CHANGES:              Renamed tunnel timemeas
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2013 11:53:48 AM CET]
CHANGES:              Change Package : 167173:27 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.59 2013/02/06 08:41:26CET Brunn, Marcus (brunnm) 
CHANGES:              updated adapter for i210
CHANGES:              --- Added comments ---  brunnm [Feb 6, 2013 8:41:27 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.58 2013/01/28 15:06:48CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eRedReflectorArea
CHANGES:              - HLA_t_eHighwayLatPosState
CHANGES:              - HLA_t_eHighwayEgoMotionState
CHANGES:              - HLA_t_eHighwayOcclusionState
CHANGES:              --- Added comments ---  brunnm [Jan 28, 2013 3:06:48 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.57 2013/01/25 16:59:44CET Mutschler, Matthias (uidv7867) 
CHANGES:              Changed enums to rte like types for missing hlar input params/signals
CHANGES:              --- Added comments ---  uidv7867 [Jan 25, 2013 4:59:45 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.56 2013/01/24 19:14:24CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLAF_t_eNightViewObjectType
CHANGES:              - HLAF_t_eNightViewSpot
CHANGES:              --- Added comments ---  brunnm [Jan 24, 2013 7:14:24 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.55 2013/01/24 17:51:47CET Mutschler, Matthias (uidv7867) 
CHANGES:              Changed ROI bottom calculation
CHANGES:              --- Added comments ---  uidv7867 [Jan 24, 2013 5:51:47 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.54 2013/01/24 16:37:32CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eTunnel
CHANGES:              - HLA_t_eBrightnessState
CHANGES:              - HLA_t_eMotorwayState
CHANGES:              --- Added comments ---  brunnm [Jan 24, 2013 4:37:32 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.53 2013/01/24 10:33:13CET Mutschler, Matthias (uidv7867) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eGlareReductionState
CHANGES:              - HLA_t_eLightModuleState
CHANGES:              --- Added comments ---  uidv7867 [Jan 24, 2013 10:33:13 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.52 2013/01/23 17:57:56CET Brunn, Marcus (brunnm) 
CHANGES:              Converted enum to rte like type for
CHANGES:              - HLA_t_eCityState
CHANGES:              - HLA_t_eWeatherState
CHANGES:              --- Added comments ---  brunnm [Jan 23, 2013 5:57:56 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.51 2013/01/23 16:40:00CET Mutschler, Matthias (uidv7867) 
CHANGES:              Converted enum to rte like type for
CHANGES:              - HLA_t_eHeadLightMode
CHANGES:              - HLA_t_eSpotLight
CHANGES:              - HLA_t_eWindshieldType
CHANGES:              - HLA_t_eDefectPixelType
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 4:40:01 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.50 2013/01/23 14:56:47CET Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed type in Convert_HLA_eLightStyle_v1
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 2:56:47 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.49 2013/01/23 13:27:05CET Brunn, Marcus (brunnm) 
CHANGES:              convert enums from MFC300 to MFC400 (rte types)
CHANGES:              --- Added comments ---  brunnm [Jan 23, 2013 1:27:06 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.48 2013/01/23 10:55:49CET Mutschler, Matthias (uidv7867) 
CHANGES:              Switched from enum to rte like types for
CHANGES:              - HLA_t_eHeadLightType;
CHANGES:              - HLA_t_eHeadLightMechanics;
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 10:55:50 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.47 2013/01/22 16:39:32CET Brunn, Marcus (brunnm) 
CHANGES:              introduced RTE like types for 
CHANGES:              - HLA_t_eState
CHANGES:              - HLA_t_eLevelState
CHANGES:              - HLA_t_eLightOutput
CHANGES:              --- Added comments ---  brunnm [Jan 22, 2013 4:39:33 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.46 2013/01/22 14:12:38CET Mutschler, Matthias (uidv7867) 
CHANGES:              Fix for previous version
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 2:12:38 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.45 2013/01/22 14:02:13CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced enum by uint32 for HLA_t_eLightStyle
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 2:02:13 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.44 2013/01/22 12:14:11CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced more traffic style enums by uint32
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 12:14:11 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.43 2013/01/22 09:55:18CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced enum by uint32 for traffic style
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 9:55:19 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.42 2013/01/18 07:46:48CET Brunn, Marcus (brunnm) 
CHANGES:              initial matrix beam version for BMW I210
**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "hlar_input/sim_hlar_input_data.h"
#include "hlar_ext.h"
#include "mfc3_type/mfc3_type.h"


uint32 Convert_HLA_SWVersionNumber_v1(uint32 in)
{
  uint32 out;
  uint32 temp;
  uint32 swVerMajor, swVerMinor, swVerBugfix;
  

  temp = (in & 0x00FF0000) >> 16;
  swVerMajor  = (temp/16) * 10 + (temp%16);
  temp = (in & 0x0000FF00) >> 8;
  swVerMinor = (temp/16) * 10 + (temp%16);
  temp = (in & 0x000000FF) >> 0;
  swVerBugfix = (temp/16) * 10 + (temp%16);
  
  
  out = (swVerMajor<<24) | (swVerMinor<<16) | (swVerBugfix<<8);
  
  return(out);
}


RTE_HLAF_HighBeamState Convert_HLA_eHighBeamState_v1(HLA_t_enum8 e_HBState)
{
  /*! Type definition for HLA driving direction */
  typedef enum
  {
    HLA_HB_OFF_V1         = 0u,                                   /*!< high beam off        */
    HLA_HB_FULL_ON_V1     = 1u,                                   /*!< full high beam on    */
    HLA_HB_PARTIAL_V1     = 2u,                                   /*!< partial high beam on */
    HLA_HB_SPOT_V1        = 3u                                    /*!< hazard/ spot light   */
  } HLA_t_eHighBeamState_v1;

  RTE_HLAF_HighBeamState eOut;

  switch(e_HBState)
  {
    case HLA_HB_OFF_V1:
      eOut = RTE_HLAF_HB_STATE_OFF;
      break;
    case HLA_HB_FULL_ON_V1:
      eOut = RTE_HLAF_HB_STATE_FULL_ON;
      break;
    case HLA_HB_PARTIAL_V1:
      eOut = RTE_HLAF_HB_STATE_PARTIAL;
      break;
    case HLA_HB_SPOT_V1:
      eOut = RTE_HLAF_HB_STATE_SPOT;
      break;  
    default:
      eOut = RTE_HLAF_HB_STATE_INVALID;
      break;
  }

  return(eOut);
}


RTE_HLA_State Convert_HLA_eState_v1(HLA_t_enum8 eState)
{
  typedef enum
  {
    HLA_STATE_NAVL_V1   = 0u,                                   /*!< HLA not available */
    HLA_STATE_IDLE_V1   = 1u,                                   /*!< HLA idle */
    HLA_STATE_ACTV_V1   = 2u,                                   /*!< HLA activated */
    HLA_STATE_FAULT_V1  = 3u                                    /*!< HLA temporarily not available */
  } HLA_t_eState_v1;

  RTE_HLA_State eOut;


  switch(eState)
  {
    case HLA_STATE_NAVL_V1:
      eOut = RTE_HLA_STATE_NAVL;
      break;
    case HLA_STATE_IDLE_V1:
      eOut = RTE_HLA_STATE_IDLE;
      break;
    case HLA_STATE_ACTV_V1:
      eOut = RTE_HLA_STATE_ACTV;
      break;
    case HLA_STATE_FAULT_V1:
      eOut = RTE_HLA_STATE_FAULT;
      break;  
    default:
      eOut = RTE_HLA_STATE_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLA_State Convert_HLA_eState_v2(HLA_t_enum8 eState)
{
  typedef enum
  {
    HLA_STATE_UNKNOWN_V2 = 0u,  
    HLA_STATE_NAVL_V2    = 1u,                                   /*!< HLA not available */
    HLA_STATE_IDLE_V2    = 2u,                                   /*!< HLA idle */
    HLA_STATE_ACTV_V2    = 3u,                                   /*!< HLA activated */
    HLA_STATE_FAULT_V2   = 4u                                    /*!< HLA temporarily not available */
  } HLA_t_eState_v2;

  RTE_HLA_State eOut;

  switch(eState)
  {
  case HLA_STATE_UNKNOWN_V2:
    eOut = RTE_HLA_STATE_UNKNOWN;
    break;
  case HLA_STATE_NAVL_V2:
    eOut = RTE_HLA_STATE_NAVL;
    break;
  case HLA_STATE_IDLE_V2:
    eOut = RTE_HLA_STATE_IDLE;
    break;
  case HLA_STATE_ACTV_V2:
    eOut = RTE_HLA_STATE_ACTV;
    break;
  case HLA_STATE_FAULT_V2:
    eOut = RTE_HLA_STATE_FAULT;
    break;  
  default:
    eOut = RTE_HLA_STATE_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLA_Type Convert_HLA_eType_v1(HLA_t_enum8 eType)
{
  /*! Type definition for HLA type */
  typedef enum
  {
    HLA_TYPE_NAVL_V1      = 0u, /*!< HLA not available */
    HLA_TYPE_BINARY_V1    = 1u, /*!< HLA light, binary switching mode */
    HLA_TYPE_STANDARD_V1  = 2u, /*!< HLA standard (low beam range adaptation) */
    HLA_TYPE_PLUS_V1      = 3u, /*!< HLA plus (glare-free high beam, 1 glare free area) */
    HLA_TYPE_MATRIX_V1    = 4u  /*!< HLA matrix beam (1-5 glare free areas) */
  } HLA_t_eType_v1;

  RTE_HLA_Type eOut;


  switch(eType)
  {
    case HLA_TYPE_NAVL_V1:
      eOut = RTE_HLA_TYPE_NAVL;
      break;
    case HLA_TYPE_BINARY_V1:
      eOut = RTE_HLA_TYPE_LIGHT;
      break;
    case HLA_TYPE_STANDARD_V1:
      eOut = RTE_HLA_TYPE_STANDARD;
      break;
    case HLA_TYPE_PLUS_V1:
      eOut = RTE_HLA_TYPE_PLUS;
      break;
    case HLA_TYPE_MATRIX_V1:
      eOut = RTE_HLA_TYPE_MATRIX;
      break; 
    default:
      eOut = RTE_HLA_TYPE_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLA_Type Convert_HLA_eType_v2(HLA_t_enum8 eType)
{
  /*! Type definition for HLA type */
  typedef enum
  {
    HLA_TYPE_UNKNOWN_V2   = 0u, /*!< HLA not available */
    HLA_TYPE_NAVL_V2      = 1u, /*!< HLA not available */
    HLA_TYPE_BINARY_V2    = 2u, /*!< HLA light, binary switching mode */
    HLA_TYPE_STANDARD_V2  = 3u, /*!< HLA standard (low beam range adaptation) */
    HLA_TYPE_PLUS_V2      = 4u, /*!< HLA plus (glare-free high beam, 1 glare free area) */
    HLA_TYPE_MATRIX_V2    = 5u  /*!< HLA matrix beam (1-5 glare free areas) */
  } HLA_t_eType_v2;

  RTE_HLA_Type eOut;


  switch(eType)
  {
  case HLA_TYPE_UNKNOWN_V2:
    eOut = RTE_HLA_TYPE_UNKNOWN;
    break;
  case HLA_TYPE_NAVL_V2:
    eOut = RTE_HLA_TYPE_NAVL;
    break;
  case HLA_TYPE_BINARY_V2:
    eOut = RTE_HLA_TYPE_LIGHT;
    break;
  case HLA_TYPE_STANDARD_V2:
    eOut = RTE_HLA_TYPE_STANDARD;
    break;
  case HLA_TYPE_PLUS_V2:
    eOut = RTE_HLA_TYPE_PLUS;
    break;
  case HLA_TYPE_MATRIX_V2:
    eOut = RTE_HLA_TYPE_MATRIX;
    break;  
  default:
    eOut = RTE_HLA_TYPE_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAR_CityState Convert_HLA_eCityState_v1(HLA_t_enum8 eCityState)
{
  /*! Type definition for HLA type */
  typedef enum
  {
    HLA_CITY_IDLE_V1         = 0u,  /*!< No city detected */
    HLA_CITY_DETECTED_V1     = 1u,  /*!< City detected */
    HLA_CITY_MAYBE_V1        = 2u   /*!< maybe city detected */
  } HLA_t_eCityState_v1;

  RTE_HLAR_CityState eOut;


  switch(eCityState)
  {
    case HLA_CITY_IDLE_V1:
      eOut = RTE_HLAR_CITY_NOT_DTCD;
      break;
    case HLA_CITY_DETECTED_V1:
      eOut = RTE_HLAR_CITY_DTCD;
      break;
    case HLA_CITY_MAYBE_V1:
      eOut = RTE_HLAR_CITY_MAYBE;
      break;
    default:
      eOut = RTE_HLAR_CITY_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAR_CityState Convert_HLA_eCityState_v2(HLA_t_enum8 eCityState)
{
  /*! Type definition for HLA type */
  typedef enum
  {
    HLAR_CITY_UNKNOWN_V2     = 0u,  
    HLAR_CITY_NOT_DTCD_V2    = 1u,  /*!< No city detected */
    HLAR_CITY_DTCD_V2        = 2u,  /*!< City detected */
    HLAR_CITY_MAYBE_V2       = 3u   /*!< maybe city detected */
  } HLA_t_eCityState_v2;

  RTE_HLAR_CityState eOut;

  switch(eCityState)
  {
  case HLAR_CITY_UNKNOWN_V2:
    eOut = RTE_HLAR_CITY_UNKNOWN;
    break;
  case HLAR_CITY_NOT_DTCD_V2:
    eOut = RTE_HLAR_CITY_NOT_DTCD;
    break;
  case HLAR_CITY_DTCD_V2:
    eOut = RTE_HLAR_CITY_DTCD;
    break;
  case HLAR_CITY_MAYBE_V2:
    eOut = RTE_HLAR_CITY_MAYBE;
    break;
  default:
    eOut = RTE_HLAR_CITY_INVALID;
    break;
  }

  return(eOut);
}



RTE_HLAR_WeatherState Convert_HLA_eWeatherState_v1(HLA_t_enum8 eWeatherState)
{
  typedef enum
  {
    HLA_WEATHER_IDLE_V1 = 0u, /*!< No bad weather detected */
    HLA_WEATHER_BAD_V1  = 1u  /*!< Bad weather detected */
  } HLA_t_eWeatherState_v1;

  RTE_HLAR_WeatherState eOut;


  switch(eWeatherState)
  {
    case HLA_WEATHER_IDLE_V1:
      eOut = RTE_HLAR_WEATHER_GOOD;
      break;
    case HLA_WEATHER_BAD_V1:
      eOut = RTE_HLAR_WEATHER_BAD;
      break;
    default:
      eOut = RTE_HLAR_WEATHER_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAR_WeatherState Convert_HLA_eWeatherState_v2(HLA_t_enum8 eWeatherState)
{
  typedef enum
  {
    HLAR_WEATHER_UNKNOWN_V2     = 0u,
    HLAR_WEATHER_GOOD_V2        = 1u,
    HLAR_WEATHER_BAD_V2         = 2u,
    HLAR_WEATHER_LIGHT_FOG_V2   = 3u,
    HLAR_WEATHER_MEDIUM_FOG_V2  = 4u,
    HLAR_WEATHER_HEAVY_FOG_V2   = 5u
  } HLA_t_eWeatherState_v2;

  RTE_HLAR_WeatherState eOut;

  switch(eWeatherState)
  {
  case HLAR_WEATHER_UNKNOWN_V2:
    eOut = RTE_HLAR_WEATHER_UNKNOWN;
    break;
  case HLAR_WEATHER_GOOD_V2:
    eOut = RTE_HLAR_WEATHER_GOOD;
    break;
  case HLAR_WEATHER_BAD_V2:
    eOut = RTE_HLAR_WEATHER_BAD;
    break;
  case HLAR_WEATHER_LIGHT_FOG_V2:
    eOut = RTE_HLAR_WEATHER_LIGHT_FOG;
    break;
  case HLAR_WEATHER_MEDIUM_FOG_V2:
    eOut = RTE_HLAR_WEATHER_MEDIUM_FOG;
    break;    
  case HLAR_WEATHER_HEAVY_FOG_V2:
    eOut = RTE_HLAR_WEATHER_HEAVY_FOG;
    break;
  default:
    eOut = RTE_HLAR_WEATHER_INVALID;
    break;
  }

  return(eOut);
}


RTE_HLAR_Tunnel Convert_HLA_eTunnel_v1(HLA_t_enum8 eTunnel)
{
  typedef enum
  {
    HLA_TUNNEL_IDLE_V1           = 0u,  /*!< No tunnel */
    HLA_TUNNEL_UPFRONT_V1        = 1u,  /*!< Tunnel ahead */
    HLA_TUNNEL_INSIDE_V1         = 2u   /*!< Inside the tunnel */
  } HLA_t_eTunnel_v1;

  RTE_HLAR_Tunnel eOut;


  switch(eTunnel)
  {
    case HLA_TUNNEL_IDLE_V1:
      eOut = RTE_HLAR_TUNNEL_NOT_DTCD;
      break;
    case HLA_TUNNEL_UPFRONT_V1:
      eOut = RTE_HLAR_TUNNEL_UPFRONT;
      break;
    case HLA_TUNNEL_INSIDE_V1:
      eOut = RTE_HLAR_TUNNEL_INSIDE;
      break;
    default:
      eOut = RTE_HLAR_TUNNEL_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAR_Tunnel Convert_HLA_eTunnel_v2(HLA_t_enum8 eTunnel)
{
  typedef enum
  {
    HLAR_TUNNEL_UNKNOWN_V2      = 0u,
    HLAR_TUNNEL_NOT_DTCD_V2     = 1u,  /*!< No tunnel */
    HLAR_TUNNEL_UPFRONT_V2      = 2u,  /*!< Tunnel ahead */
    HLAR_TUNNEL_INSIDE_V2       = 3u   /*!< Inside the tunnel */
  } HLA_t_eTunnel_v2;

  RTE_HLAR_Tunnel eOut;

  switch(eTunnel)
  {
  case HLAR_TUNNEL_UNKNOWN_V2:
    eOut = RTE_HLAR_TUNNEL_UNKNOWN;
    break;
  case HLAR_TUNNEL_NOT_DTCD_V2:
    eOut = RTE_HLAR_TUNNEL_NOT_DTCD;
    break;
  case HLAR_TUNNEL_UPFRONT_V2:
    eOut = RTE_HLAR_TUNNEL_UPFRONT;
    break;
  case HLAR_TUNNEL_INSIDE_V2:
    eOut = RTE_HLAR_TUNNEL_INSIDE;
    break;
  default:
    eOut = RTE_HLAR_TUNNEL_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAF_MotorwayState Convert_HLA_eMotorwayState_v1(HLA_t_enum8 eMotorwayState)
{
  typedef enum
  {
    HLA_MTWY_IDLE_V1      = 0u, /*!< idle state */
    HLA_MTWY_COUNTRY_V1   = 1u, /*!< country road state, road not divided */
    HLA_MTWY_MOTORWAY_V1  = 2u  /*!< motorway state, road divided*/
  } HLA_t_eMotorwayState_v1;

  RTE_HLAF_MotorwayState eOut;

  switch(eMotorwayState)
  {
    case HLA_MTWY_IDLE_V1:
      eOut = RTE_HLAF_MTWY_UNKNOWN;
      break;
    case HLA_MTWY_COUNTRY_V1:
      eOut = RTE_HLAF_MTWY_COUNTRY;
      break;
    case HLA_MTWY_MOTORWAY_V1:
      eOut = RTE_HLAF_MTWY_MOTORWAY;
      break;
    default:
      eOut = RTE_HLAF_MTWY_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAR_BrightnessState Convert_HLA_eBrightnessState_v1(HLA_t_enum8 eBrightnessState)
{
  typedef enum
  {
    HLA_BRT_IDLE_V1           = 0u,
    HLA_BRT_DAY_V1            = 1u,
    HLA_BRT_TWLGT_1_V1        = 2u,
    HLA_BRT_TWLGT_2_V1        = 3u,
    HLA_BRT_TWLGT_3_V1        = 4u,
    HLA_BRT_NIGHT_V1          = 5u,
    HLA_BRT_CLEARANCE_V1      = 249u,
    HLA_BRT_BLOCKAGE_V1       = 250u
  } HLA_t_eBrightnessState_v1;

  RTE_HLAR_BrightnessState eOut;


  switch(eBrightnessState)
  {
    case HLA_BRT_IDLE_V1:
      eOut = RTE_HLAR_BRT_UNKNOWN;
      break;
    case HLA_BRT_DAY_V1:
      eOut = RTE_HLAR_BRT_DAY;
      break;
    case HLA_BRT_TWLGT_1_V1:
      eOut = RTE_HLAR_BRT_TWLGT_1;
      break;
    case HLA_BRT_TWLGT_2_V1:
      eOut = RTE_HLAR_BRT_TWLGT_2;
      break;
    case HLA_BRT_TWLGT_3_V1:
      eOut = RTE_HLAR_BRT_TWLGT_3;
      break;
    case HLA_BRT_NIGHT_V1:
      eOut = RTE_HLAR_BRT_NIGHT;
      break;
    case HLA_BRT_CLEARANCE_V1:
    case HLA_BRT_BLOCKAGE_V1:
      eOut = RTE_HLAR_BRT_UNKNOWN;
      break;
    default:
      eOut = RTE_HLAR_BRT_INVALID;
      break;
  }

  return(eOut);
}

AlgoSignalState_t Convert_HLA_eSignalState_v1(HLA_t_enum8 eSignalState)
{
  typedef enum 
{
  HLA_SIG_INIT_V1 = 0u,
  HLA_SIG_OK_V1 = 1u,
  HLA_SIG_NOT_OK_V1 = 2u,
  HLA_SIG_TIMEOUT_V1 = 3u,
  HLA_SIG_OK_BUT_SENSOR_NOT_INIT_V1 = 4u,
  HLA_SIG_OUT_OF_RANGE_V1 = 5u
} HLA_t_eSigStatus_v1;

  AlgoSignalState_t eOut;


  switch(eSignalState)
  {
    case HLA_SIG_INIT_V1:
      eOut = AL_SIG_STATE_INIT;
      break;
    case HLA_SIG_OK_V1:
      eOut = AL_SIG_STATE_OK;
      break;
    case HLA_SIG_NOT_OK_V1:
    case HLA_SIG_TIMEOUT_V1:
    case HLA_SIG_OK_BUT_SENSOR_NOT_INIT_V1:
    case HLA_SIG_OUT_OF_RANGE_V1:
    default:
      eOut = AL_SIG_STATE_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAF_NightViewObjectType Convert_HLA_eNightViewObjectType_v1(HLA_t_enum8 eNightViewObjectType)
{
  typedef enum
  {
    HLAF_NV_OBJ_IDLE_V1         = 0u,
    HLAF_NV_OBJ_PEDESTRIAN_V1   = 1u,
    HLAF_NV_OBJ_ANIMAL_SMALL_V1 = 2u,
    HLAF_NV_OBJ_ANIMAL_BIG_V1   = 3u
  } HLAF_t_eNightViewObjectType_v1;

  RTE_HLAF_NightViewObjectType eOut;


  switch(eNightViewObjectType)
  {
    case HLAF_NV_OBJ_IDLE_V1:
      eOut = RTE_HLAF_NV_OBJ_NO_OBJ;
      break;
    case HLAF_NV_OBJ_PEDESTRIAN_V1:
      eOut = RTE_HLAF_NV_OBJ_PEDESTRIAN;
      break;
    case HLAF_NV_OBJ_ANIMAL_SMALL_V1:
      eOut = RTE_HLAF_NV_OBJ_ANIMAL_SMALL;
      break;
    case HLAF_NV_OBJ_ANIMAL_BIG_V1:
      eOut = RTE_HLAF_NV_OBJ_ANIMAL_BIG;
      break;
    default:
      eOut = RTE_HLAF_NV_OBJ_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAF_NightViewObjectType Convert_HLA_eNightViewObjectType_v2(HLA_t_enum8 eNightViewObjectType)
{
  typedef enum
  {
    HLAF_NV_OBJ_UNKNOWN_V2         = 0u,
    HLAF_NV_OBJ_NO_OBJ_V2          = 1u,
    HLAF_NV_OBJ_UNKNOWN_OBJ_V2     = 2u,
    HLAF_NV_OBJ_PEDESTRIAN_V2      = 3u,
    HLAF_NV_OBJ_ANIMAL_SMALL_V2    = 4u,
    HLAF_NV_OBJ_ANIMAL_BIG_V2      = 5u
  } HLAF_t_eNightViewObjectType_v2;

  RTE_HLAF_NightViewObjectType eOut;


  switch(eNightViewObjectType)
  {
  case HLAF_NV_OBJ_UNKNOWN_V2:
    eOut = RTE_HLAF_NV_OBJ_UNKNOWN;
    break;
  case HLAF_NV_OBJ_NO_OBJ_V2:
    eOut = RTE_HLAF_NV_OBJ_NO_OBJ;
    break;
  case HLAF_NV_OBJ_UNKNOWN_OBJ_V2:
    eOut = RTE_HLAF_NV_OBJ_UNKNOWN_OBJ;
    break;
  case HLAF_NV_OBJ_PEDESTRIAN_V2:
    eOut = RTE_HLAF_NV_OBJ_PEDESTRIAN;
    break;
  case HLAF_NV_OBJ_ANIMAL_SMALL_V2:
    eOut = RTE_HLAF_NV_OBJ_ANIMAL_SMALL;
    break;
  case HLAF_NV_OBJ_ANIMAL_BIG_V2:
    eOut = RTE_HLAF_NV_OBJ_ANIMAL_BIG;
    break;
  default:
    eOut = RTE_HLAF_NV_OBJ_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAF_NightViewSpot Convert_HLA_eNightViewSpot_v1(HLA_t_enum8 eNightViewSpot)
{
  typedef enum
  {
    HLAF_NV_SPOT_OFF_V1   = 0u,
    HLAF_NV_SPOT_BLINK_V1 = 1u,
    HLAF_NV_SPOT_CONT_V1  = 2u,
    HLAF_NV_SPOT_ABORT_V1 = 3u
  } HLAF_t_eNightViewSpot_v1;

  RTE_HLAF_NightViewSpot eOut;

  switch(eNightViewSpot)
  {
    case HLAF_NV_SPOT_OFF_V1:
      eOut = RTE_HLAF_NV_SPOT_OFF;
      break;
    case HLAF_NV_SPOT_BLINK_V1:
      eOut = RTE_HLAF_NV_SPOT_BLINK;
      break;
    case HLAF_NV_SPOT_CONT_V1:
      eOut = RTE_HLAF_NV_SPOT_CONT;
      break;
    case HLAF_NV_SPOT_ABORT_V1:
      eOut = RTE_HLAF_NV_SPOT_ABORT;
      break;
    default:
      eOut = RTE_HLAF_NV_SPOT_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAF_NightViewSpot Convert_HLA_eNightViewSpot_v2(HLA_t_enum8 eNightViewSpot)
{
  typedef enum
  {
    HLAF_NV_SPOT_UNKNOWN_V2 = 0u,
    HLAF_NV_SPOT_OFF_V2     = 1u,
    HLAF_NV_SPOT_BLINK_V2   = 2u,
    HLAF_NV_SPOT_CONT_V2    = 3u,
    HLAF_NV_SPOT_ABORT_V2   = 4u
  } HLAF_t_eNightViewSpot_v2;

  RTE_HLAF_NightViewSpot eOut;

  switch(eNightViewSpot)
  {
  case HLAF_NV_SPOT_UNKNOWN_V2:
    eOut = RTE_HLAF_NV_SPOT_UNKNOWN;
    break;
  case HLAF_NV_SPOT_OFF_V2:
    eOut = RTE_HLAF_NV_SPOT_OFF;
    break;
  case HLAF_NV_SPOT_BLINK_V2:
    eOut = RTE_HLAF_NV_SPOT_BLINK;
    break;
  case HLAF_NV_SPOT_CONT_V2:
    eOut = RTE_HLAF_NV_SPOT_CONT;
    break;
  case HLAF_NV_SPOT_ABORT_V2:
    eOut = RTE_HLAF_NV_SPOT_ABORT;
    break;
  default:
    eOut = RTE_HLAF_NV_SPOT_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAR_RedReflectorArea Convert_HLA_eRedReflectorArea_v1(HLA_t_enum8 eRedReflectorArea)
{
  typedef enum
  {
    HLA_RED_REFLECTOR_AREA_IDLE_V1 = 0u,  /*!< no red reflector area */
    HLA_RED_REFLECTOR_AREA_V1      = 1u   /*!< red reflector area detected */
  } HLA_t_eRedReflectorArea_v1;

  RTE_HLAR_RedReflectorArea eOut;

  switch(eRedReflectorArea)
  {
  case HLA_RED_REFLECTOR_AREA_IDLE_V1:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD;
    break;
  case HLA_RED_REFLECTOR_AREA_V1:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_DTCD;
    break;
  default:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAR_RedReflectorArea Convert_HLA_eRedReflectorArea_v2(HLA_t_enum8 eRedReflectorArea)
{
  typedef enum
  {
    HLAR_RED_REFLECTOR_AREA_UNKNOWN_V2  = 0u,
    HLAR_RED_REFLECTOR_AREA_NOT_DTCD_V2 = 1u,
    HLAR_RED_REFLECTOR_AREA_DTCD_V2     = 2u
  } HLA_t_eRedReflectorArea_v2;

  RTE_HLAR_RedReflectorArea eOut;

  switch(eRedReflectorArea)
  {
  case HLAR_RED_REFLECTOR_AREA_UNKNOWN_V2:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_UNKNOWN;
    break;
  case HLAR_RED_REFLECTOR_AREA_NOT_DTCD_V2:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD;
    break;
  case HLAR_RED_REFLECTOR_AREA_DTCD_V2:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_DTCD;
    break;
  default:
    eOut = RTE_HLAR_RED_REFLECTOR_AREA_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAR_HighwayLatPosState Convert_HLA_eHighwayLatPosState_v1(HLA_t_enum8 eHighwayLatPosState)
{
  typedef enum
  {
    HLA_HIGHWAY_RDWAY_IDLE_V1        = 0u,  /* Idle State */
    HLA_HIGHWAY_RDWAY_NORMAL_V1      = 1u,  /* Normal Roadway Type */
    HLA_HIGHWAY_RDWAY_DIVIDED_V1     = 2u   /* Divided Roadway Type */
  } HLA_t_eHighwayLatPosState_v1;

  RTE_HLAR_HighwayLatPosState eOut;

  switch(eHighwayLatPosState)
  {
    case HLA_HIGHWAY_RDWAY_IDLE_V1:
      eOut = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
      break;
    case HLA_HIGHWAY_RDWAY_NORMAL_V1:
      eOut = RTE_HLAR_HIGHWAY_LP_NOT_DTCD;
      break;
    case HLA_HIGHWAY_RDWAY_DIVIDED_V1:
      eOut = RTE_HLAR_HIGHWAY_LP_DTCD;
      break;
    default:
      eOut = RTE_HLAR_HIGHWAY_LP_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAR_HighwayLatPosState Convert_HLA_eHighwayLatPosState_v2(HLA_t_enum8 eHighwayLatPosState)
{
  typedef enum
  {
    HLAR_HIGHWAY_LP_UNKNOWN_V2  = 0u,
    HLAR_HIGHWAY_LP_NOT_DTCD_V2 = 1u,
    HLAR_HIGHWAY_LP_DTCD_V2     = 2u 
  } HLA_t_eHighwayLatPosState_v2;

  RTE_HLAR_HighwayLatPosState eOut;

  switch(eHighwayLatPosState)
  {
  case HLAR_HIGHWAY_LP_UNKNOWN_V2:
    eOut = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
    break;
  case HLAR_HIGHWAY_LP_NOT_DTCD_V2:
    eOut = RTE_HLAR_HIGHWAY_LP_NOT_DTCD;
    break;
  case HLAR_HIGHWAY_LP_DTCD_V2:
    eOut = RTE_HLAR_HIGHWAY_LP_DTCD;
    break;
  default:
    eOut = RTE_HLAR_HIGHWAY_LP_INVALID;
    break;
  }

  return(eOut);
}

RTE_HLAR_HighwayEgoMotionState Convert_HLA_eHighwayEgoMotionState_v1(HLA_t_enum8 eHighwayEgoMotionState)
{
  typedef enum
  {
    HLA_HIGHWAY_IDLE_V1	     = 0u,  /* Idle State */
    HLA_HIGHWAY_NOT_DTCD_V1  = 1u,  /* NOT Highway Detected */
    HLA_HIGHWAY_DTCD_V1      = 2u,  /* Highway Detected (> 65km/h) */
    HLA_HIGHWAY_LOW_SPEED_V1 = 3u   /* Highway Detected at low speed (< 65km/h) */
  } HLA_t_eHighwayEgoMotionState_v1;

  RTE_HLAR_HighwayEgoMotionState eOut;

  
  switch(eHighwayEgoMotionState)
  {
    case HLA_HIGHWAY_IDLE_V1:
      eOut = RTE_HLAR_HIGHWAY_EM_UNKNOWN;
      break;
    case HLA_HIGHWAY_NOT_DTCD_V1:
      eOut = RTE_HLAR_HIGHWAY_EM_NOT_DTCD;
      break;
    case HLA_HIGHWAY_DTCD_V1:
      eOut = RTE_HLAR_HIGHWAY_EM_DTCD;
      break;
    case HLA_HIGHWAY_LOW_SPEED_V1:
      eOut = RTE_HLAR_HIGHWAY_EM_LOW_SPEED;
      break;
    default:
      eOut = RTE_HLAR_HIGHWAY_EM_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAR_eHighwayOcclusionState Convert_HLA_eHighwayOcclusionState_v1(HLA_t_enum8 eHighwayEgoMotionState)
{
  typedef enum
  {
    HLA_HIGHWAY_OCCL_IDLE_V1      = 0u,  /* Idle State */
    HLA_HIGHWAY_OCCL_NOT_DTCD_V1  = 1u,  /* NOT Occlusion Detected */
    HLA_HIGHWAY_OCCL_DTCD_V1      = 2u   /* Occlusion Detected */
  } HLA_t_eHighwayOcclusionState_v1;

  RTE_HLAR_eHighwayOcclusionState eOut;
 

  switch(eHighwayEgoMotionState)
  {
    case HLA_HIGHWAY_OCCL_IDLE_V1:
      eOut = RTE_HLAR_HIGHWAY_OC_UNKNOWN;
      break;
    case HLA_HIGHWAY_OCCL_NOT_DTCD_V1:
      eOut = RTE_HLAR_HIGHWAY_OC_NOT_DTCD;
      break;
    case HLA_HIGHWAY_OCCL_DTCD_V1:
      eOut = RTE_HLAR_HIGHWAY_OC_DTCD;
      break;
    default:
      eOut = RTE_HLAR_HIGHWAY_OC_INVALID;
      break;
  }

  return(eOut);
}

RTE_HLAF_MatrixTurnOffReason Convert_HLA_eTurnOffReason_v1(HLA_t_enum32 eTurnOffReason)
{
  typedef enum
  {
    HLAF_TURNOFFREASON_ONC_V1          = (0x0001u),
    HLAF_TURNOFFREASON_PREC_V1         = (0x0002u),
    HLAF_TURNOFFREASON_LOW_SPEED_V1    = (0x0004u),
    HLAF_TURNOFFREASON_BRIGHTNESS_V1   = (0x0008u),
    HLAF_TURNOFFREASON_CITY_V1         = (0x0010u),
    HLAF_TURNOFFREASON_FOG_V1          = (0x0020u),
    HLAF_TURNOFFREASON_HIGHWAY_V1      = (0x0040u),
    HLAF_TURNOFFREASON_DELAY_V1        = (0x0080u),
    HLAF_TURNOFFREASON_TUNNEL_V1       = (0x0100u),
    HLAF_TURNOFFREASON_BLOCKAGE_V1     = (0x0200u),
    HLAF_TURNOFFREASON_TRAFFICSTYLE_V1 = (0x0400u),
    HLAF_TURNOFFREASON_INVALID_V1      = (0xFFFFu)
  } HLAF_t_MatrixTurnOffReason_v1;

  RTE_HLAF_MatrixTurnOffReason eOut;

  eOut = RTE_HLAF_TURNOFFREASON_UNKNOWN;
  if(eTurnOffReason & HLAF_TURNOFFREASON_ONC_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_ONC;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_PREC_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_PREC;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_LOW_SPEED_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_LOW_SPEED;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_BRIGHTNESS_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_BRIGHTNESS;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_CITY_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_CITY;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_FOG_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_FOG;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_DELAY_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_DELAY;
  }
  if(eTurnOffReason & HLAF_TURNOFFREASON_BLOCKAGE_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_BLOCKAGE;
  }
  if(eTurnOffReason == HLAF_TURNOFFREASON_INVALID_V1)
  {
    eOut |= RTE_HLAF_TURNOFFREASON_INVALID;
  }

  return(eOut);
}

void Set_HLA_Availability( HLA_t_Availability  *pDest,
                                          RTE_HLA_Type         e_Type,
                                          RTE_HLA_State        e_State,
                                          RTE_HLA_US_Sens      e_USSens
                                        )
{
  pDest->e_State  = e_State;
  pDest->e_Type   = e_Type;
  pDest->e_USSens = e_USSens;
}
void Set_HLA_Availability_Default(HLA_t_Availability   *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_Availability));
  }
}

void Set_HLA_HeadlightState_v1(HLA_t_HeadlightState        *pDest,
                                              RTE_HLA_LightStyle          e_LightStyle_Lt,
                                              RTE_HLA_LightStyle          e_LightStyle_Rt,
                                              HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt,
                                              HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt,
                                              HLA_t_fLightAngle           f32_PartHBCutoffAng_Lt,
                                              HLA_t_fLightAngle           f32_PartHBCutoffAng_Rt,
                                              RTE_HLAF_HighBeamState      e_HighBeamState,
                                              RTE_HLA_LightModuleState    e_LightModuleState,
                                              HLA_t_fLightDistance        f32_LightDistance,
                                              HLA_t_f32LightOutput        f32_LightOutput,
                                              RTE_HLA_GlareReductionState e_GlareReductionState
                                             )
{
  pDest->e_LightModuleState            = e_LightModuleState;
  pDest->e_HighBeamState               = e_HighBeamState;
  pDest->f32_CurveLightRotAngle_Lt     = f32_CurveLightRotAngle_Lt;
  pDest->f32_CurveLightRotAngle_Rt     = f32_CurveLightRotAngle_Rt;
  pDest->e_GlareReductionState         = e_GlareReductionState;
  pDest->f32_LightOutput               = f32_LightOutput;
  pDest->nGFA                          = 1;

  /* this is the case for old recordings with only one GFA present */
  pDest->GFA[0].f32_PartHBCutoffAng_Lt = f32_PartHBCutoffAng_Lt;
  pDest->GFA[0].f32_PartHBCutoffAng_Rt = f32_PartHBCutoffAng_Rt;
  pDest->GFA[0].f32_HorCutOffAng       = 0.0f;
  pDest->GFA[0].f32_LightDistance      = f32_LightDistance;
  pDest->GFA[0].e_HorCutOffAngState    = RTE_HLA_CUTOFFLINE_UNKNOWN;
  pDest->GFA[0].e_LightDistanceState   = RTE_HLA_CUTOFFLINE_UNKNOWN;
  pDest->GFA[0].e_LightStyle_Lt        = e_LightStyle_Lt;
  pDest->GFA[0].e_LightStyle_Rt        = e_LightStyle_Rt;
}
void Set_HLA_HeadlightState_v2(HLA_t_HeadlightState        *pDest,
                                              RTE_HLA_LightModuleState    e_LightModuleState,
                                              RTE_HLAF_HighBeamState      e_HighBeamState,
                                              HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt,
                                              HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt,
                                              RTE_HLA_GlareReductionState e_GlareReductionState,
                                              HLA_t_f32LightOutput        f32_LightOutput,
                                              uint32                      nGFA
                                             )
{
  pDest->e_LightModuleState        = e_LightModuleState;
  pDest->e_HighBeamState           = e_HighBeamState;
  pDest->f32_CurveLightRotAngle_Lt = f32_CurveLightRotAngle_Lt;
  pDest->f32_CurveLightRotAngle_Rt = f32_CurveLightRotAngle_Rt;
  pDest->e_GlareReductionState     = e_GlareReductionState;
  pDest->f32_LightOutput           = f32_LightOutput;
  pDest->nGFA                      = nGFA;
}
void Set_HLA_HeadlightState_Default(HLA_t_HeadlightState *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_Availability));
  }
}

void Set_HLA_MatrixGFAState_v1( HLA_t_MatrixGFAState     *pDest,
                                               HLA_t_fLightAngle        f32_PartHBCutoffAng_Lt,
                                               HLA_t_fLightAngle        f32_PartHBCutoffAng_Rt,
                                               HLA_t_fLightAngle        f32_HorCutOffAng,
                                               HLA_t_fLightDistance     f32_LightDistance,
                                               RTE_HLA_CutOffLineState  e_HorCutOffAngStatus,
                                               RTE_HLA_CutOffLineState  e_LightDistanceStatus,
                                               RTE_HLA_LightStyle       e_LightStyle_Lt,
                                               RTE_HLA_LightStyle       e_LightStyle_Rt
                                             )
{
  pDest->f32_PartHBCutoffAng_Lt = f32_PartHBCutoffAng_Lt;
  pDest->f32_PartHBCutoffAng_Rt = f32_PartHBCutoffAng_Rt;
  pDest->f32_HorCutOffAng       = f32_HorCutOffAng;
  pDest->f32_LightDistance      = f32_LightDistance;
  pDest->e_HorCutOffAngState    = e_HorCutOffAngStatus;
  pDest->e_LightDistanceState   = e_LightDistanceStatus;
  pDest->e_LightStyle_Lt        = e_LightStyle_Lt;
  pDest->e_LightStyle_Rt        = e_LightStyle_Rt;
}
void Set_HLA_MatrixGFAState_Default(HLA_t_MatrixGFAState *pDest)
{
  if (pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_MatrixGFAState));
  }
}

void Set_HLA_ImagerState( HLA_t_ImagerState         *pDest,
                                         HLA_t_eActiveChar         e_ActiveChar,
                                         float32                   f32_Brightness_Lux,
                                         uint32                    ui32_ExposureTime_us,
                                         uint32                    ui32_FrameNumber,
                                         float32                   f32_Noise,
                                         uint32                    ui32_R1, 
                                         uint32                    ui32_R2, 
                                         float32                   f32_T1_us,
                                         float32                   f32_T2_us,
                                         float32                   f32_T3_us,
                                         float32                   f32_Gain,
                                         /* response curve */
                                         uint16                    ui16_Blacklevel_R_Greyvalue,
                                         uint16                    ui16_Blacklevel_G_Greyvalue,
                                         uint16                    ui16_Blacklevel_B_Greyvalue,
                                         uint16                    ui16_Kneepoint1_Greyvalue,
                                         float32                   f32_Kneepoint1_R_Lux,
                                         float32                   f32_Kneepoint1_G_Lux,
                                         float32                   f32_Kneepoint1_B_Lux,
                                         uint16                    ui16_Kneepoint2_Greyvalue,
                                         float32                   f32_Kneepoint2_R_Lux,
                                         float32                   f32_Kneepoint2_G_Lux,
                                         float32                   f32_Kneepoint2_B_Lux,
                                         uint16                    ui16_Saturation_Greyvalue,
                                         float32                   f32_Saturation_R_Lux,
                                         float32                   f32_Saturation_G_Lux,
                                         float32                   f32_Saturation_B_Lux
                                       )
{
  pDest->e_ActiveChar             = e_ActiveChar;
  pDest->f32_Brightness_Lux       = f32_Brightness_Lux;
  pDest->ui32_ExposureTime_us     = ui32_ExposureTime_us;
  pDest->ui32_FrameNumber         = ui32_FrameNumber;
  pDest->f32_Noise                = f32_Noise;

  pDest->s_ImagerCharacteristic.ui32_R1   = ui32_R1;
  pDest->s_ImagerCharacteristic.ui32_R2   = ui32_R2;
  pDest->s_ImagerCharacteristic.f32_T1_us = f32_T1_us;
  pDest->s_ImagerCharacteristic.f32_T2_us = f32_T2_us;
  pDest->s_ImagerCharacteristic.f32_T3_us = f32_T3_us;
  pDest->s_ImagerCharacteristic.f32_Gain  = f32_Gain;

  /* imager response curve */
  pDest->s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_R_Greyvalue  = ui16_Blacklevel_R_Greyvalue;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_G_Greyvalue  = ui16_Blacklevel_G_Greyvalue;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_B_Greyvalue  = ui16_Blacklevel_B_Greyvalue;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.ui16_Kneepoint1_Greyvalue    = ui16_Kneepoint1_Greyvalue;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux         = f32_Kneepoint1_R_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux         = f32_Kneepoint1_G_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux         = f32_Kneepoint1_B_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.ui16_Kneepoint2_Greyvalue    = ui16_Kneepoint2_Greyvalue;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux         = f32_Kneepoint2_R_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux         = f32_Kneepoint2_G_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux         = f32_Kneepoint2_B_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.ui16_Saturation_Greyvalue    = ui16_Saturation_Greyvalue;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux         = f32_Saturation_R_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux         = f32_Saturation_G_Lux;
  pDest->s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux         = f32_Saturation_B_Lux;
}
void Set_HLA_ImagerState_Default(HLA_t_ImagerState *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_ImagerState));
  }
}


void Set_HLA_MotionState( HLA_t_MotionState     *pDest,
                                         float32               f32_SpeedDisplay,
                                         float32               f32_Speed,
                                         float32               f32_Acceleration,
                                         float32               f32_YawRateRaw,
                                         float32               f32_YawRate,
                                         float32               f32_YawRateQuality,
                                         float32               f32_YawRateVariance,
                                         float32               f32_SteeringWheelAngle,
                                         float32               f32_SteeringAngle,
                                         HLA_t_eMovementState  e_MoveState,
                                         float32               f32_MoveStateConfidence
                                       )
{
  if(e_MoveState == HLA_MOVE_STATE_REV)
  {
    /* driving backwards */
    pDest->f32_SpeedDisplay         = -fABS(f32_SpeedDisplay);
    pDest->f32_Speed                = -fABS(f32_Speed);
  }
  else
  {
    /* driving forwards */
    pDest->f32_SpeedDisplay         = fABS(f32_SpeedDisplay);
    pDest->f32_Speed                = fABS(f32_Speed);
  }
  pDest->f32_Acceleration         = f32_Acceleration;
  pDest->f32_YawRateRaw           = f32_YawRateRaw;
  pDest->f32_YawRate              = f32_YawRate;
  pDest->f32_YawRateQuality       = f32_YawRateQuality;
  pDest->f32_YawRateVariance      = f32_YawRateVariance;
  pDest->f32_SteeringWheelAngle   = f32_SteeringWheelAngle;
  pDest->f32_SteeringAngle        = f32_SteeringAngle;
  pDest->e_MoveState              = e_MoveState;
  pDest->f32_MoveStateConfidence  = f32_MoveStateConfidence;
}
void Set_HLA_MotionState_Default(HLA_t_MotionState *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_MotionState));
  }
}


void Set_HLA_VehicleState( HLA_t_VehicleState       *pDest,
                                          boolean                  b_FogLampFront,
                                          boolean                  b_FogLampRear,
                                          boolean                  b_RainSensor,
                                          uint8                    ui8_WiperState,
                                          HLA_t_eWiperWasherState  e_WiperWasherFrontState,
                                          HLA_t_eWiperStage        e_WiperStage,
                                          HLA_t_VehLevel_v1        s_VehicleLevel
                                        )
{
  pDest->b_FogLampFront           = b_FogLampFront;
  pDest->b_FogLampRear            = b_FogLampRear;
  pDest->b_RainSensor             = b_RainSensor;
  pDest->ui8_WiperState           = ui8_WiperState;
  pDest->e_WiperWasherFrontState  = e_WiperWasherFrontState;
  pDest->e_WiperStage             = e_WiperStage;
  pDest->s_VehicleLevel.f32_FrontLeft = s_VehicleLevel.f32_FrontLeft;
  pDest->s_VehicleLevel.f32_FrontRight = s_VehicleLevel.f32_FrontRight;
  pDest->s_VehicleLevel.f32_RearLeft = s_VehicleLevel.f32_RearLeft;
  pDest->s_VehicleLevel.f32_RearRight = s_VehicleLevel.f32_RearRight;
}
void Set_HLA_VehicleState_Default(HLA_t_VehicleState *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_VehicleState));
  }
}

void Set_HLA_CaliOnline( HLA_t_CaliOnline  *pDest,
                                        float32           f32_OdoCali_m,
                                        float32           f32_Pitch,
                                        float32           f32_Roll,
                                        float32           f32_Yaw)
{
  pDest->f32_OdoCali_m = f32_OdoCali_m;
  pDest->f32_Pitch = f32_Pitch;
  pDest->f32_Roll = f32_Roll;
  pDest->f32_Yaw = f32_Yaw;
}
void Set_HLA_CaliOnline_Default(HLA_t_CaliOnline *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_CaliOnline));
  }
}

void Set_HLA_CameraParameter( HLA_t_CameraParameter       *pDest,
                                             HLA_t_eBayerPatternType     e_bayerPattern,
                                             float32                     f32_cycleTime,
                                             HLA_t_FocalLength_v1        s_FocalLength,
                                             HLA_t_ImageSize_v1          s_ImageSize,
                                             HLA_t_ImageSize_v1          s_CroppedRoiSize,
                                             HLA_t_CroppedRoiX_v1        s_CroppedRoiX1,
                                             HLA_t_LensCenter_v1         s_LensCenter,

                                             /* camera distortion parameter */
                                             float32                     f32_K1,
                                             float32                     f32_K2,
                                             float32                     f32_K3,
                                             float32                     f32_K4,
                                             float32                     f32_K5,
                                             /* camera distortion parameter */

                                             /* Image header parameter */
                                             uint16                      uiBitsPerChannel,
                                             sint16                      iPixelBytes,
                                             sint32                      iRowBytes,
                                             sint32                      iSizeBytes,
                                             uint16                      uiWidth,
                                             uint16                      uiHeight,
                                             sint8                       iScaleX,
                                             sint8                       iScaleY,
                                             sint16                      iOffsetX,
                                             sint16                      iOffsetY,
                                             ImageDataFormat_t           eDataFormat,
                                             ParameterID_t               uiParameterId
                                             /* Image header parameter */
                                             )
{
  pDest->e_bayerPattern           = e_bayerPattern;
  pDest->f32_cycleTime            = f32_cycleTime;
  pDest->s_FocalLength.f32_x      = s_FocalLength.f32_x;
  pDest->s_FocalLength.f32_y      = s_FocalLength.f32_y;
  pDest->s_ImageSize.ui32_x       = s_ImageSize.ui32_x;
  pDest->s_ImageSize.ui32_y       = s_ImageSize.ui32_y;
  pDest->s_CroppedRoiSize.ui32_x  = s_CroppedRoiSize.ui32_x;
  pDest->s_CroppedRoiSize.ui32_y  = s_CroppedRoiSize.ui32_y;
  pDest->s_CroppedRoiX1.ui32_x    = s_CroppedRoiX1.ui32_x;
  pDest->s_CroppedRoiX1.ui32_y    = s_CroppedRoiX1.ui32_y;
  pDest->s_LensCenter.f32_x       = s_LensCenter.f32_x;
  pDest->s_LensCenter.f32_y       = s_LensCenter.f32_y;

  /* HLA_t_CalibratedRGBLuxTable */
  
  /* camera distortion parameter */
  pDest->s_Distortion.f32_K1 = f32_K1;
  pDest->s_Distortion.f32_K2 = f32_K2;
  pDest->s_Distortion.f32_K3 = f32_K3;
  pDest->s_Distortion.f32_K4 = f32_K4;
  pDest->s_Distortion.f32_K5 = f32_K5;
  /* camera distortion parameter */

  /* Image header parameter */
  pDest->s_ImageHeader.uiBitsPerChannel = uiBitsPerChannel;
  pDest->s_ImageHeader.iPixelBytes      = iPixelBytes;
  pDest->s_ImageHeader.iRowBytes        = iRowBytes;
  pDest->s_ImageHeader.iSizeBytes       = iSizeBytes;
  pDest->s_ImageHeader.uiWidth          = uiWidth;
  pDest->s_ImageHeader.uiHeight         = uiHeight;
  pDest->s_ImageHeader.iScaleX          = iScaleX;
  pDest->s_ImageHeader.iScaleY          = iScaleY;
  pDest->s_ImageHeader.iOffsetX         = iOffsetX;
  pDest->s_ImageHeader.iOffsetY         = iOffsetY;
  pDest->s_ImageHeader.eDataFormat      = eDataFormat;
  pDest->s_ImageHeader.uiParameterId    = uiParameterId;
  /* Image header parameter */
}

void Set_HLA_CameraParameter_Default(HLA_t_CameraParameter *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_CameraParameter));
  } 
}

void Set_HLA_ParameterRoi( RTE_HLAR_ParameterRoi_t *pDest,
                                          float32 FOV_Horizontal,
                                          float32 FOV_FunctionRoiAboveHorizon,
                                          float32 FOV_MinBelowHorizon,
                                          float32 FOV_MinAboveHorizon,
                                          float32 PrecVehLight_minDistance,
                                          float32 PrecVehLight_minHeight,
                                          float32 StreetLamp_Distance,
                                          float32 StreetLamp_Height
                                        )
{
  pDest->FOV_Horizontal               = FOV_Horizontal;
  pDest->FOV_FunctionRoiAboveHorizon  = FOV_FunctionRoiAboveHorizon;
  pDest->FOV_MinBelowHorizon          = FOV_MinBelowHorizon;
  pDest->FOV_MinAboveHorizon          = FOV_MinAboveHorizon;
  pDest->PrecVehLight_minDistance     = PrecVehLight_minDistance;
  pDest->PrecVehLight_minHeight       = PrecVehLight_minHeight;
  pDest->StreetLamp_Distance          = StreetLamp_Distance;
  pDest->StreetLamp_Height            = StreetLamp_Height;
}

void Set_HLA_ParameterCity( RTE_HLAR_ParameterCity_t *pDest,
                                           float32 SpeedThresholdLow,
                                           float32 SpeedThresholdHigh,
                                           uint16  NumLeavingStreetlamp_LowSpeed,
                                           uint16  NumLeavingStreetlamp_HighSpeed,
                                           uint16  NumSceneStreetlamp_LowSpeed,
                                           uint16  NumSceneStreetlamp_HighSpeed,
                                           uint16  AmbientLevel_LowSpeed,
                                           uint16  AmbientLevel_HighSpeed,
                                           float32 StreetLampMaxInterDist_LowSpeed,
                                           float32 StreetLampMaxInterDist_HighSpeed,
                                           float32 StreetLampMaxDist_LowSpeed,
                                           float32 StreetLampMaxDist_HighSpeed,
                                           float32 LeavingCityDelay_LowSpeed,
                                           float32 LeavingCityDelay_HighSpeed,
                                           float32 LeavingCityDelaySceneStreetlamp_LowInt,
                                           float32 LeavingCityDelaySceneStreetlamp_HighInt,
                                           uint16  NumTunnelStreetlamp
                                          )
{
  pDest->SpeedThresholdLow                       = SpeedThresholdLow;
  pDest->SpeedThresholdHigh                      = SpeedThresholdHigh;
  pDest->NumLeavingStreetlamp_LowSpeed           = NumLeavingStreetlamp_LowSpeed;
  pDest->NumLeavingStreetlamp_HighSpeed          = NumLeavingStreetlamp_HighSpeed;
  pDest->NumSceneStreetlamp_LowSpeed             = NumSceneStreetlamp_LowSpeed;
  pDest->NumSceneStreetlamp_HighSpeed            = NumSceneStreetlamp_HighSpeed;
  pDest->AmbientLevel_LowSpeed                   = AmbientLevel_LowSpeed;
  pDest->AmbientLevel_HighSpeed                  = AmbientLevel_HighSpeed;
  pDest->StreetLampMaxInterDist_LowSpeed         = StreetLampMaxInterDist_LowSpeed;
  pDest->StreetLampMaxInterDist_HighSpeed        = StreetLampMaxInterDist_HighSpeed;
  pDest->StreetLampMaxDist_LowSpeed              = StreetLampMaxDist_LowSpeed;
  pDest->StreetLampMaxDist_HighSpeed             = StreetLampMaxDist_HighSpeed;
  pDest->LeavingCityDelay_LowSpeed               = LeavingCityDelay_LowSpeed;
  pDest->LeavingCityDelay_HighSpeed              = LeavingCityDelay_HighSpeed;
  pDest->LeavingCityDelaySceneStreetlamp_LowInt  = LeavingCityDelaySceneStreetlamp_LowInt;
  pDest->LeavingCityDelaySceneStreetlamp_HighInt = LeavingCityDelaySceneStreetlamp_HighInt;
  pDest->NumTunnelStreetlamp                     = NumTunnelStreetlamp;
}

void Set_HLA_ParameterHighway( RTE_HLAR_ParameterHighway_t *pDest,
                                              float32 SpeedDetThreshold_Fast,
                                              float32 SpeedDetThreshold,
                                              float32 SpeedDetThresholdDistance,
                                              float32 EgoMotionDetThresholdHigh,
                                              float32 EgoMotionDetThresholdLow,
                                              uint16  LateralPositionUsedTracks,
                                              float32 LateralPositionConfidenceThreshHigh,
                                              float32 LateralPositionConfidenceThreshLow,
                                              uint16  OcclusionOncomingLeavingLightsThresh,
                                              float32 OcclusionConfidenceStep
                                             )
{
  pDest->SpeedDetThreshold_Fast               = SpeedDetThreshold_Fast;
  pDest->SpeedDetThreshold                    = SpeedDetThreshold;
  pDest->SpeedDetThresholdDistance            = SpeedDetThresholdDistance;
  pDest->EgoMotionDetThresholdHigh            = EgoMotionDetThresholdHigh;
  pDest->EgoMotionDetThresholdLow             = EgoMotionDetThresholdLow;
  pDest->LateralPositionUsedTracks            = LateralPositionUsedTracks;
  pDest->LateralPositionConfidenceThreshHigh  = LateralPositionConfidenceThreshHigh;
  pDest->LateralPositionConfidenceThreshLow   = LateralPositionConfidenceThreshLow;
  pDest->OcclusionOncomingLeavingLightsThresh = OcclusionOncomingLeavingLightsThresh;
  pDest->OcclusionConfidenceStep              = OcclusionConfidenceStep;
}

void Set_HLA_ParameterTunnel(RTE_HLAR_ParameterTunnel_t *pDest,
                                            float32 EntryThreshHigh,
                                            float32 EntryThreshLow,
                                            float32 EntryDistanceMin,
                                            float32 EntryDistanceMax,
                                            float32 ExitThreshHigh,
                                            float32 ExitThreshLow,
                                            float32 ExitDistanceMin,
                                            float32 DetectionTypeDistance
                                           )
{
  pDest->EntryThreshHigh        = EntryThreshHigh;
  pDest->EntryThreshLow         = EntryThreshLow;
  pDest->EntryDistanceMin       = EntryDistanceMin;
  pDest->EntryDistanceMax       = EntryDistanceMax;
  pDest->ExitThreshHigh         = ExitThreshHigh;
  pDest->ExitThreshLow          = ExitThreshLow;
  pDest->ExitDistanceMin        = ExitDistanceMin;
  pDest->DetectionTypeDistance  = DetectionTypeDistance;
}

void Set_HLA_ParameterTrafficStyle( RTE_HLAR_ParameterTrafficStyle_t *pDest,
                                                   uint16 NumOncLightsThres,
                                                   uint16 NumOncLightsLock
                                                  )
{
  pDest->NumOncLightsThres = NumOncLightsThres;
  pDest->NumOncLightsLock = NumOncLightsLock;
}

void Set_HLA_ParameterAmbient( RTE_HLAR_ParameterAmbient_t *pDest,
                                              float32 SpeedThreshold,
                                              uint16  AmbientLevel_LowSpeed,
                                              uint16  AmbientLevel_HighSpeed,
                                              float32 Day2NightTimeThres_LowSpeed,
                                              float32 Day2NightTimeThres_HighSpeed,
                                              float32 Day2NightDistThres_LowSpeed,
                                              float32 Day2NightDistThres_HighSpeed,
                                              float32 Night2DayTimeThres_LowSpeed,
                                              float32 Night2DayTimeThres_HighSpeed,
                                              float32 Night2DayDistThres_LowSpeed,
                                              float32 Night2DayDistThres_HighSpeed
                                             )
{
  pDest->SpeedThreshold               = SpeedThreshold;
  pDest->AmbientLevel_LowSpeed        = AmbientLevel_LowSpeed;
  pDest->AmbientLevel_HighSpeed       = AmbientLevel_HighSpeed;
  pDest->Day2NightTimeThres_LowSpeed  = Day2NightTimeThres_LowSpeed;
  pDest->Day2NightTimeThres_HighSpeed = Day2NightTimeThres_HighSpeed;
  pDest->Day2NightDistThres_LowSpeed  = Day2NightDistThres_LowSpeed;
  pDest->Day2NightDistThres_HighSpeed = Day2NightDistThres_HighSpeed;
  pDest->Night2DayTimeThres_LowSpeed  = Night2DayTimeThres_LowSpeed;
  pDest->Night2DayTimeThres_HighSpeed = Night2DayTimeThres_HighSpeed;
  pDest->Night2DayDistThres_LowSpeed  = Night2DayDistThres_LowSpeed;
  pDest->Night2DayDistThres_HighSpeed = Night2DayDistThres_HighSpeed;
}

void Set_HLA_ParameterVehDet( RTE_HLAR_ParameterVehDet_t *pDest,
                                             uint16 OncSensitivity,
                                             uint16 PrecSensitivity
                                            )
{
  pDest->OncSensitivity = OncSensitivity;
  pDest->PrecSensitivity = PrecSensitivity;
}

void Set_HLA_ParameterLightPair( RTE_HLAR_ParameterLightPair_t *pDest,
                                                float32 TaillightWidth_Min,
                                                float32 TaillightWidth_Max,
                                                float32 HeadlightWidth_Min,
                                                float32 HeadlightWidth_Max,
                                                float32 TaillightHeight_Min,
                                                float32 TaillightHeight_Max,
                                                float32 HeadlightHeight_Min,
                                                float32 HeadlightHeight_Max
                                               )
{
  pDest->TaillightWidth_Min  = TaillightWidth_Min;
  pDest->TaillightWidth_Max  = TaillightWidth_Max;
  pDest->HeadlightWidth_Min  = HeadlightWidth_Min;
  pDest->HeadlightWidth_Max  = HeadlightWidth_Max;
  pDest->TaillightHeight_Min = TaillightHeight_Min;
  pDest->TaillightHeight_Max = TaillightHeight_Max;
  pDest->HeadlightHeight_Min = HeadlightHeight_Min;
  pDest->HeadlightHeight_Max = HeadlightHeight_Max;
}

void Set_HLA_ParameterDistEst( RTE_HLAR_ParameterDistEst_t *pDest,
                                              float32 LightHeight_Min,
                                              float32 LightHeight_Max,
                                              float32 DistFilterConst
                                             )
{
  pDest->LightHeight_Min = LightHeight_Min;
  pDest->LightHeight_Max = LightHeight_Max;
  pDest->DistFilterConst = DistFilterConst;
}

void Set_HLA_ParameterTTBEst( RTE_HLAR_ParameterTTBEst_t *pDest,
                                             float32 ttbAngle
                                            )
{
  pDest->ttbAngle = ttbAngle;
}

void Set_HLA_SensorAngles( HLA_t_SensorAngles                    *pDest,
                                          float32                               f32_Pitch,
                                          float32                               f32_Roll,
                                          float32                               f32_Yaw,
                                          float32                               f32_Quality,
                                          eMonoCalibrationVerificationStatus_t  e_State
  )
{
  pDest->f32_Pitch   = f32_Pitch;
  pDest->f32_Roll    = f32_Roll;
  pDest->f32_Yaw     = f32_Yaw;
  pDest->f32_Quality = f32_Quality;
  pDest->e_caliState = e_State;
}

void Set_HLA_SensorAngles_Default(HLA_t_SensorAngles *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_SensorAngles));
  } 
}

void Set_HLA_ParameterAlgoCfg( RTE_HLA_ParameterAlgoCfg_t *pDest,
                                              RTE_HLA_TestMode          TestMode,
                                              RTE_HLA_CityDetection     CityDetection,
                                              RTE_HLA_TunnelDetection   TunnelDetection,
                                              RTE_HLA_BadPixelDetection BadPixelDetection,
                                              RTE_HLA_FogDetection      FogDetection,
                                              RTE_HLA_BlockageDetection BlockageDetection
                                             )
{
  pDest->TestMode          = TestMode;
  pDest->CityDetection     = CityDetection;
  pDest->TunnelDetection   = TunnelDetection;
  pDest->BadPixelDetection = BadPixelDetection;
  pDest->FogDetection      = FogDetection;
  pDest->BlockageDetection = BlockageDetection;
}

void Set_HLA_ParameterHeadlight( RTE_HLA_ParameterHeadlight_t *pDest,
                                                RTE_HLA_HeadlightType      HeadLightType,
                                                RTE_HLA_HeadLightMechanics HeadLightMechanics,
                                                RTE_HLA_SpotLight          SpotLight,
                                                float32                    SpotLightWidth,
                                                float32                    FullHBDefaultPos_Left,
                                                float32                    FullHBDefaultPos_Right,
                                                float32                    HeadLampLatency,
                                                float32                    SpotLightTolerance
                                              )
{
  pDest->HeadLightType          = HeadLightType;
  pDest->HeadLightMechanics     = HeadLightMechanics;
  pDest->SpotLight              = SpotLight;
  pDest->SpotLightWidth         = SpotLightWidth;
  pDest->FullHBDefaultPos_Left  = FullHBDefaultPos_Left;
  pDest->FullHBDefaultPos_Right = FullHBDefaultPos_Right;
  pDest->HeadLampLatency        = HeadLampLatency;
  pDest->SpotLightTolerance     = SpotLightTolerance;
}

void Set_HLA_ParameterCountry( RTE_HLA_ParameterCountry_t *pDest,
                                              RTE_HLA_TrafficStyle       TrafficStyle,
                                              RTE_HLA_SensMode           SensitivityMode,
                                              RTE_HLA_MultipleReflectors CountryWithMultipleReflectors
                                            )
{
  pDest->TrafficStyle                  = TrafficStyle;
  pDest->SensitivityMode               = SensitivityMode;
  pDest->CountryWithMultipleReflectors = CountryWithMultipleReflectors;
}

void Set_HLA_ParameterVehicle( RTE_HLA_ParameterVehicle_t *pDest,
                                              RTE_HLA_WindshieldType WindshieldType 
                                            )
{
  pDest->WindshieldType = WindshieldType;
}

void Set_HLA_ParameterTurnOff( RTE_HLAF_ParameterTurnOff_t *pDest,
                                              float32 TTBThreshold,
                                              float32 HorAngThreshold
                                             )
{
  pDest->TTBThreshold    = TTBThreshold;
  pDest->HorAngThreshold = HorAngThreshold;
}

void Set_HLA_ParameterKeepOff( RTE_HLAF_ParameterKeepOff_t *pDest,
                                              float32 Radius2TurnsOnThres,
                                              float32 TurnOnDelay
                                             )
{
  pDest->SmallRadius.Radius2TurnsOnThres = Radius2TurnsOnThres;
  pDest->SmallRadius.TurnOnDelay         = TurnOnDelay;
}

void Set_HLA_ParameterTurnOnDelay( RTE_HLAF_ParameterTurnOnDelay_t *pDest,
                                                  float32 OncomingMin_DistThreshold,
                                                  float32 OncomingMin_LatDistThreshold,
                                                  float32 OncomingMin,
                                                  float32 OncomingMax,
                                                  float32 OncomingMaxHighway,
                                                  float32 PrecedingMin,
                                                  float32 PrecedingTimeGap_Threshold,
                                                  float32 PrecedingTimeGap,
                                                  float32 PrecedingMinWiperOn,
                                                  float32 PrecedingMaxShort,
                                                  float32 PrecedingMaxLong,
                                                  float32 SlowOvertaking,
                                                  float32 Fog,
                                                  float32 City,
                                                  float32 Tunnel
                                                 )
{
  pDest->OncomingMin_DistThreshold    = OncomingMin_DistThreshold;
  pDest->OncomingMin_LatDistThreshold = OncomingMin_LatDistThreshold;
  pDest->OncomingMin                  = OncomingMin;
  pDest->OncomingMax                  = OncomingMax;
  pDest->OncomingMaxHighway           = OncomingMaxHighway;
  pDest->PrecedingMin                 = PrecedingMin;
  pDest->PrecedingTimeGap_Threshold   = PrecedingTimeGap_Threshold;
  pDest->PrecedingTimeGap             = PrecedingTimeGap;
  pDest->PrecedingMinWiperOn          = PrecedingMinWiperOn;
  pDest->PrecedingMaxShort            = PrecedingMaxShort;
  pDest->PrecedingMaxLong             = PrecedingMaxLong;
  pDest->SlowOvertaking               = SlowOvertaking;
  pDest->Fog                          = Fog;
  pDest->City                         = City;
  pDest->Tunnel                       = Tunnel;
}

void Set_HLA_ParameterSpeed( RTE_HLAF_ParameterSpeed_t *pDest,
                                            float32 DeactivateSpeed,
                                            float32 ActivateSpeed,
                                            float32 AlwaysActiveSpeed,
                                            float32 KeepOff_VeryLowSpeed,
                                            float32 KeepOff_LowRadius,
                                            float32 KeepOff_HighAcceleration,
                                            float32 KeepOff_AccTime,
                                            float32 KeepOff_Delay
                                           )
{
  pDest->DeactivateSpeed          = DeactivateSpeed;
  pDest->ActivateSpeed            = ActivateSpeed;
  pDest->AlwaysActiveSpeed        = AlwaysActiveSpeed;
  pDest->KeepOff_VeryLowSpeed     = KeepOff_VeryLowSpeed;
  pDest->KeepOff_LowRadius        = KeepOff_LowRadius;
  pDest->KeepOff_HighAcceleration = KeepOff_HighAcceleration;
  pDest->KeepOff_AccTime          = KeepOff_AccTime;
  pDest->KeepOff_Delay            = KeepOff_Delay;
}

void Set_HLA_ParameterBlockage( RTE_HLAF_ParameterBlockage_t *pDest,
                                               float32                         ConfidenceThreshold,
                                               float32                         ClearMeas2Blockage_DistThres,
                                               float32                         ClearMeas2Blockage_TimeThres,
                                               float32                         ClearMeas2NoBlockage_DistThres,
                                               float32                         NoBlockage2Blockage_DistThres,
                                               float32                         NoBlockage2Blockage_TimeThres,
                                               float32                         Blockage2NoBlockage_TimeThres,
                                               RTE_HLA_BlockageManualOverwrite ManualOverwrite
                                              )
{
  pDest->ConfidenceThreshold            = ConfidenceThreshold;
  pDest->ClearMeas2Blockage_DistThres   = ClearMeas2Blockage_DistThres;
  pDest->ClearMeas2Blockage_TimeThres   = ClearMeas2Blockage_TimeThres;
  pDest->ClearMeas2NoBlockage_DistThres = ClearMeas2NoBlockage_DistThres;
  pDest->NoBlockage2Blockage_DistThres  = NoBlockage2Blockage_DistThres;
  pDest->NoBlockage2Blockage_TimeThres  = NoBlockage2Blockage_TimeThres;
  pDest->Blockage2NoBlockage_TimeThres  = Blockage2NoBlockage_TimeThres;
  pDest->ManualOverwrite                = ManualOverwrite;
}

void Set_HLA_ParameterFog( RTE_HLAF_ParameterFog_t *pDest,
                                          uint16 ConfidenceThreshold,
                                          uint16 Sensitivity
                                         )
{
  pDest->ConfidenceThreshold = ConfidenceThreshold;
  pDest->Sensitivity         = Sensitivity;
}

void Set_HLA_ParameterMatrixBeam( RTE_HLAF_ParameterMatrixBeam_t *pDest,
                                                 uint16 MaxNumGlarefreeArea 
                                               )
{
  pDest->MaxNumGlarefreeArea = MaxNumGlarefreeArea;
}

void Set_HLA_Matrix( HLAF_t_Matrix                *pDest,
                                    uint32                       nGFA,
                                    RTE_HLAF_SignalStatus        GFAStatus,
                                    RTE_HLAF_HighBeamState       HighBeamState,
                                    float32                      LowBeam_Dist,
                                    float32                      LowBeam_Ang,
                                    RTE_HLAF_ObjStatus           LowBeam_Status,
                                    RTE_HLAF_MatrixTurnOffReason TurnOffReason
                                  )
{
  pDest->nGFA           = nGFA;
  pDest->GFAStatus      = GFAStatus;
  pDest->HighBeamState  = HighBeamState;
  pDest->LowBeam_Dist   = LowBeam_Dist;
  pDest->LowBeam_Ang    = LowBeam_Ang;
  pDest->LowBeam_Status = LowBeam_Status;
  pDest->TurnOffReason  = TurnOffReason;
}

void Set_HLA_Matrix_Default(HLAF_t_Matrix *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLAF_t_Matrix));
  } 
}

void Set_HLA_MatrixGFA( HLAF_t_MatrixGFA *pDest,
                                       float32 BndryLeft_Ang,
                                       float32 BndryLeft_Dist,
                                       float32 BndryRight_Ang,
                                       float32 BndryRight_Dist,
                                       float32 BndryLeft_Ang_Cam,
                                       float32 BndryRight_Ang_Cam,
                                       float32 BndryLower_Ang_Cam,
                                       float32 ClosestObj_Dist,
                                       float32 ClosestObj_Ang,
                                       float32 MinLight_Dist,
                                       float32 MinLight_Ang,
                                       float32 ttb18Left,
                                       float32 ttb18Right,

                                       RTE_HLAF_ObjStatus BndryLeft_Status,
                                       RTE_HLAF_ObjStatus BndryRight_Status,
                                       RTE_HLAF_ObjStatus BndryLower_Status,
                                       RTE_HLAF_ObjStatus ClosestObj_Status,
                                       RTE_HLAF_ObjStatus MinLight_Status,
                                       RTE_HLAF_TTBStatus ttb18Left_Status,
                                       RTE_HLAF_TTBStatus ttb18Right_Status,
                                       uint8 ExistenceProb
                                      )
{
  pDest->BndryLeft_Ang      = BndryLeft_Ang;
  pDest->BndryLeft_Dist     = BndryLeft_Dist;
  pDest->BndryRight_Ang     = BndryRight_Ang;
  pDest->BndryRight_Dist    = BndryRight_Dist;
  pDest->BndryLeft_Ang_Cam  = BndryLeft_Ang_Cam;
  pDest->BndryRight_Ang_Cam = BndryRight_Ang_Cam;
  pDest->BndryLower_Ang_Cam = BndryLower_Ang_Cam;
  pDest->ClosestObj_Dist    = ClosestObj_Dist;
  pDest->ClosestObj_Ang     = ClosestObj_Ang;
  pDest->MinLight_Dist      = MinLight_Dist;
  pDest->MinLight_Ang       = MinLight_Ang;
  pDest->ttb18Left          = ttb18Left;
  pDest->ttb18Right         = ttb18Right;
  pDest->BndryLeft_Status   = BndryLeft_Status;
  pDest->BndryRight_Status  = BndryRight_Status;
  pDest->BndryLower_Status  = BndryLower_Status;
  pDest->ClosestObj_Status  = ClosestObj_Status;
  pDest->MinLight_Status    = MinLight_Status;
  pDest->ttb18Left_Status   = ttb18Left_Status;
  pDest->ttb18Right_Status  = ttb18Right_Status;
  pDest->ExistenceProb      = ExistenceProb;
}
void Set_HLA_MatrixGFA_Default(HLAF_t_MatrixGFA *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLAF_t_MatrixGFA));
  } 
}


void Set_HLA_EcoLight( HLAF_EcoLight_t                       *pDest,
                                      RTE_HLAF_EcoLight_eAvailabilityState  AvailabilityState,
 	                                    RTE_HLAF_EcoLight_eDetectionState     DetectionState,
 	                                    float32                               ObjectDist,
 	                                    RTE_HLAF_EcoLight_eVehicleType        ObjectType,
 	                                    RTE_HLAF_EcoLight_eVehicleLight       ObjectLightState
                                    )
{
  pDest->e_AvailabilityState = AvailabilityState;
  pDest->e_DetectionState    = DetectionState;
  pDest->ObjectDist          = ObjectDist;
  pDest->e_ObjectLightState  = ObjectLightState;
  pDest->e_ObjectType        = ObjectType;
}
void Set_HLA_EcoLight_Default(HLAF_EcoLight_t *pDest)
{
  if (pDest)
  {
    memset(pDest, 0, sizeof(HLAF_EcoLight_t));
  }
}

/* TODO AManz: fix output here */
void Set_HLA_LightDimmingArea(HLAF_DimmingArea_t   *pDest,
                              float32              BndryLeft_Ang_Cam,
                              float32              BndryRight_Ang_Cam,
                              float32              BndryLower_Ang_Cam,
                              RTE_HLAF_LightOutput LightOutput)
{
  pDest->BndryLeft_Ang_Cam  = BndryLeft_Ang_Cam;
  pDest->BndryLower_Ang_Cam = BndryLower_Ang_Cam;
  pDest->BndryRight_Ang_Cam = BndryRight_Ang_Cam;
  pDest->e_LightOutput      = LightOutput;
}
void Set_HLA_LightDimmingArea_Default(HLAF_DimmingArea_t *pDest)
{
  if (pDest)
  {
    memset(pDest, 0, sizeof(HLAF_DimmingArea_t));
  }
}


void Set_HLA_LightDimming(HLAF_LightDimming_t    *pDest,
                          RTE_HLAF_DimmingStatus DimmingStatus,
                          uint32                 nDimmingArea
                         )
{
  pDest->eDimmingStatus = DimmingStatus;
  pDest->nDimmingArea  = nDimmingArea;
}
void Set_HLA_LightDimming_Default(HLAF_LightDimming_t *pDest)
{
  if (pDest)
  {
    memset(pDest, 0, sizeof(HLAF_LightDimming_t));
  }
}


void Set_HLA_Blockage( HLA_t_Blockage     *pDest,
                                      boolean            b_ClearanceMeasurement,
                                      boolean            b_Condensation,
                                      boolean            b_Blockage,
                                      boolean            b_ManualOverride,
                                      AlgoSignalState_t  e_SigStatus  
                                    )
{
  pDest->b_ClearanceMeasurement = b_ClearanceMeasurement;
  pDest->b_Condensation         = b_Condensation;
  pDest->b_Blockage             = b_Blockage;
  pDest->b_ManualOverride       = b_ManualOverride;
  pDest->e_SigStatus            = e_SigStatus;
}
void Set_HLA_Blockage_Default(HLA_t_Blockage *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_Blockage));
  } 
}


void Set_ICDefectPixel( HLA_t_ICDefectPixel *pDest,
                                       uint16              ui16_xPos,
                                       uint16              ui16_yPos,
                                       RTE_HLAR_DefectPixelType e_DefectType,
                                       uint16              ui16_Count
                                     )
{
  pDest->ui16_xPos    = ui16_xPos;
  pDest->ui16_yPos    = ui16_yPos;
  pDest->e_DefectType = e_DefectType;
  pDest->ui16_Count   = ui16_Count;
}
void Set_ICDefectPixel_Default(HLA_t_ICDefectPixel *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLA_t_ICDefectPixel));
  } 
}

void Set_HLAF_NightViewObject( HLAF_t_NightViewObject       *pDest,
                                              uint8                        ui8_ID,
                                              RTE_HLAF_NightViewObjectType e_ObjType,
                                              RTE_HLAF_NightViewSpot       e_Spot,
                                              float32                      f32_Distance_m,
                                              float32                      f32_HorAng_rad
                                            )
{
  pDest->e_ObjType      = e_ObjType;
  pDest->e_Spot         = e_Spot;
  pDest->f32_Distance_m = f32_Distance_m;
  pDest->f32_HorAng_rad = f32_HorAng_rad;
}

void Set_HLAF_NightViewObject_Default(HLAF_t_NightViewObject *pDest)
{
  if(pDest)
  {
    memset(pDest, 0, sizeof(HLAF_t_NightViewObject));
  } 
}


void Set_HLAF_ecoLightObject(EM_t_GenObject              *pDest,
                                            uint8                       uiID,
                                            float32                     fDistX,
                                            float32                     fDistY,
                                            EM_t_GenObjMaintenanceState eMaintenanceState,
                                            EM_t_GenObjClassification   eClassification
                                           )
{
  if (pDest)
  {
    /* init state */
    memset(pDest, 0, sizeof(EM_t_GenObject));

    pDest->Kinematic.fDistX           = fDistX;
    pDest->Kinematic.fDistY           = fDistY;
    pDest->General.uiID               = uiID;
    pDest->General.eMaintenanceState  = eMaintenanceState;
    pDest->Attributes.eClassification = eClassification;
  }
}

void Set_HLAF_ecoLightObject_default(EM_t_GenObject  *pDest)
{
  if (pDest)
  {
    memset(pDest, 0, sizeof(EM_t_GenObject));
  }
}


RTE_HLA_TrafficStyle Convert_HLA_eTrafficStyle_v1(HLA_t_enum8 e_TrafficStyle)
{
  /*! Type definition for HLA right/left hand traffic style */
  typedef enum
  {
    HLA_TRAFFIC_STYLE_IDLE_V1    = 0u,                            /*!< No detection */
    HLA_TRAFFIC_STYLE_RHD_V1     = 1u,                            /*!< Right hand traffic */
    HLA_TRAFFIC_STYLE_LHD_V1     = 2u                             /*!< Left hand traffic */
  } HLA_t_eTrafficStyle_v1;

  RTE_HLA_TrafficStyle eOut;

  switch(e_TrafficStyle)
  {
  case HLA_TRAFFIC_STYLE_IDLE_V1:
    eOut = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    break;
  case HLA_TRAFFIC_STYLE_RHD_V1:
    eOut = RTE_HLA_TRAFFIC_STYLE_RHD;
    break;
  case HLA_TRAFFIC_STYLE_LHD_V1:
    eOut = RTE_HLA_TRAFFIC_STYLE_LHD;
    break;
  default:
    eOut = RTE_HLA_TRAFFIC_STYLE_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLAR_TrafficStyleLearningState Convert_HLA_eTrafficStyleLearningState_v1(HLA_t_enum8 e_TrafficStyleLearningState)
{
  /*! Type definition for HLA right/left hand traffic style */
  typedef enum
  {
    HLA_TRAFFIC_0_V1             = 0u,                                 /*!< No detection */
    HLA_TRAFFIC_RHD_1_V1         = 1u,                                 /*!< Right hand traffic */
    HLA_TRAFFIC_RHD_2_V1         = 2u,                                 /*!< Right hand traffic */
    HLA_TRAFFIC_RHD_3_V1         = 3u,                                 /*!< Right hand traffic */
    HLA_TRAFFIC_LHD_1_V1         = 4u,                                 /*!< Left hand traffic */
    HLA_TRAFFIC_LHD_2_V1         = 5u,                                 /*!< Left hand traffic */
    HLA_TRAFFIC_LHD_3_V1         = 6u                                  /*!< Left hand traffic */
  } HLA_t_eTrafficStyleLearningState_v1;

  RTE_HLAR_TrafficStyleLearningState eOut;

  switch(e_TrafficStyleLearningState)
  {
  case HLA_TRAFFIC_0_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_0;
    break;
  case HLA_TRAFFIC_RHD_1_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_RHD_1;
    break;
  case HLA_TRAFFIC_RHD_2_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_RHD_2;
    break;
  case HLA_TRAFFIC_RHD_3_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_RHD_3;
    break;
  case HLA_TRAFFIC_LHD_1_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_LHD_1;
    break;
  case HLA_TRAFFIC_LHD_2_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_LHD_2;
    break;
  case HLA_TRAFFIC_LHD_3_V1:
    eOut = RTE_HLAR_TRAFFIC_LEARN_LHD_3;
    break;
  default:
    eOut = RTE_HLAR_TRAFFIC_LEARN_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLAR_TrafficStyleLearningState Convert_HLA_eTrafficStyleLearningState_v2(HLA_t_enum8 e_TrafficStyleLearningState)
{
  /*! Type definition for HLA right/left hand traffic style */
  typedef enum
  {
    HLAR_TRAFFIC_LEARN_UNKNOWN_V2     = 0u,                                 
    HLAR_TRAFFIC_LEARN_0_V2           = 1u,                                 /*!< No detection */
    HLAR_TRAFFIC_LEARN_RHD_1_V2       = 2u,                                 /*!< Right hand traffic */
    HLAR_TRAFFIC_LEARN_RHD_2_V2       = 3u,                                 /*!< Right hand traffic */
    HLAR_TRAFFIC_LEARN_RHD_3_V2       = 4u,                                 /*!< Right hand traffic */
    RTE_HLAR_TRAFFIC_LEARN_LHD_1_V2   = 5u,                                 /*!< Left hand traffic */
    RTE_HLAR_TRAFFIC_LEARN_LHD_2_V2   = 6u,                                 /*!< Left hand traffic */
    RTE_HLAR_TRAFFIC_LEARN_LHD_3_V2   = 7u                                  /*!< Left hand traffic */
  } HLA_t_eTrafficStyleLearningState_v2;

  RTE_HLAR_TrafficStyleLearningState eOut;

  switch(e_TrafficStyleLearningState)
  {
  case HLAR_TRAFFIC_LEARN_UNKNOWN_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_UNKNOWN;
    break;
  case HLAR_TRAFFIC_LEARN_0_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_0;
    break;
  case HLAR_TRAFFIC_LEARN_RHD_1_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_RHD_1;
    break;
  case HLAR_TRAFFIC_LEARN_RHD_2_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_RHD_2;
    break;
  case HLAR_TRAFFIC_LEARN_RHD_3_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_RHD_3;
    break;
  case RTE_HLAR_TRAFFIC_LEARN_LHD_1_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_LHD_1;
    break;
  case RTE_HLAR_TRAFFIC_LEARN_LHD_2_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_LHD_2;
    break;
  case RTE_HLAR_TRAFFIC_LEARN_LHD_3_V2:
    eOut = RTE_HLAR_TRAFFIC_LEARN_LHD_3;
    break;
  default:
    eOut = RTE_HLAR_TRAFFIC_LEARN_INVALID;
    break;
  }
  return(eOut);
}
