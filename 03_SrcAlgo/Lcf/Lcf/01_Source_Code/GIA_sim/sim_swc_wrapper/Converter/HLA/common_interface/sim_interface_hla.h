/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_adapter

MODULNAME:            sim_interface_hla.h

DESCRIPTION:          

AUTHOR:               Marcus Brunn

CREATION DATE:        03.08.2010

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_interface_hla.h  $
CHANGES:              Revision 1.1 2021/12/13 17:23:26CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/common_interface/project.pj
CHANGES:              Revision 1.0 2017/03/03 10:34:56CET Sorge, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/common_interface/project.pj
CHANGES:              Revision 1.2 2014/03/19 16:30:47CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replace macros from glob_defs.h by the ones defined in cml_ext.h
CHANGES:              Fixed hlar input adapter for old recordings (headlamp type)
CHANGES:              Clean-up of no longer needed files in simulation
CHANGES:              - Added comments -  uidv7867 [Mar 19, 2014 4:30:47 PM CET]
CHANGES:              Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
CHANGES:              Revision 1.1 2014/03/18 16:58:48CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/hla_adapter/common_interface/project.pj
CHANGES:              Revision 1.98 2014/03/12 18:07:26CET Mutschler, Matthias (uidv7867) 
CHANGES:              Added LRF on EVE
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:27 PM CET]
CHANGES:              Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.97 2014/03/10 17:13:26CET Brunn, Marcus (brunnm) 
CHANGES:              support hlar_in interface  version 2.4.0
CHANGES:              --- Added comments ---  brunnm [Mar 10, 2014 5:13:27 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.96 2014/03/04 18:00:51CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed ppars and vehpar from RTE and internal interface
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:51 PM CET]
CHANGES:              Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.95 2014/03/04 12:58:57CET Mutschler, Matthias (uidv7867) 
CHANGES:              Support for I390 RTE
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:58 PM CET]
CHANGES:              Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.94 2014/02/06 16:02:34CET Mutschler, Matthias (uidv7867) 
CHANGES:              Refactoring of hla debug output (time meas, removed redundant stuff)
CHANGES:              Centralized Null pointer checks
CHANGES:              Refactored dframe calculation
CHANGES:              --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:34 PM CET]
CHANGES:              Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
CHANGES:              Revision 1.93 2014/01/30 16:13:14CET Brunn, Marcus (brunnm) 
CHANGES:              adapter update for mfc4xx I320 rec-files
CHANGES:              --- Added comments ---  brunnm [Jan 30, 2014 4:13:14 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.92 2014/01/10 18:33:40CET Mutschler, Matthias (uidv7867) 
CHANGES:              First part of LRF on EVE (disabled)
CHANGES:              Merged LRF inputs into one struct
CHANGES:              Fixed exception handling of internal cali 
CHANGES:              Removed all tabs in the code and further clean-up
CHANGES:              --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:41 PM CET]
CHANGES:              Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.91 2013/11/19 13:44:24CET Brunn, Marcus (brunnm) 
CHANGES:              - clean up -> removed unused vars/ functions
CHANGES:              - added detailed time measurement for segmentation
CHANGES:              --- Added comments ---  brunnm [Nov 19, 2013 1:44:24 PM CET]
CHANGES:              Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
CHANGES:              Revision 1.90 2013/10/24 12:20:01CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Added more time meas for segmentation internally
CHANGES:              --- Added comments ---  uidv7867 [Oct 24, 2013 12:20:01 PM CEST]
CHANGES:              Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
CHANGES:              Revision 1.89 2013/10/24 11:16:35CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Adapted HIL to latest changes
CHANGES:              Fixed segline buffer visu
CHANGES:              --- Added comments ---  uidv7867 [Oct 24, 2013 11:16:35 AM CEST]
CHANGES:              Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
CHANGES:              Revision 1.88 2013/08/28 11:19:11CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Changed adapter according to new camera parameter struct
CHANGES:              --- Added comments ---  uidv7867 [Aug 28, 2013 11:19:11 AM CEST]
CHANGES:              Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
CHANGES:              Revision 1.87 2013/08/21 18:21:05CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Improved sorting on EVE quite a lot
CHANGES:              --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:05 PM CEST]
CHANGES:              Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
CHANGES:              Revision 1.86 2013/08/09 17:51:33CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed time measurement of HIL
CHANGES:              --- Added comments ---  uidv7867 [Aug 9, 2013 5:51:34 PM CEST]
CHANGES:              Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.85 2013/08/05 20:41:21CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed EVE/DSP caching issues
CHANGES:              Added time meas struct for EVE
CHANGES:              --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:21 PM CEST]
CHANGES:              Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.84 2013/08/02 16:18:26CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Integrated HLA runtime restrictions (down to 3 icons and 40% of lights)
CHANGES:              --- Added comments ---  uidv7867 [Aug 2, 2013 4:18:26 PM CEST]
CHANGES:              Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.83 2013/07/31 10:36:18CEST Manz, Alexander (uidv8777) 
CHANGES:              Fix: replaced GenTargetList_t with the correct EM_t_GenObjectList to be used for EcoLight Detection
CHANGES:              --- Added comments ---  uidv8777 [Jul 31, 2013 10:36:18 AM CEST]
CHANGES:              Change Package : 192041:1 http://mks-psad:7002/im/viewissue?selection=192041
CHANGES:              Revision 1.82 2013/07/26 17:28:50CEST Manz, Alexander (uidv8777) 
CHANGES:              Update:
CHANGES:              - First implementation of EcoLight functionality
CHANGES:              - Changed measFreeze addresses of HLAR_In, HLAR_Out, HLAF_In, HLAF_Out and HLA_SystemInfo due to overlapping regions
CHANGES:              --- Added comments ---  uidv8777 [Jul 26, 2013 5:28:50 PM CEST]
CHANGES:              Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
CHANGES:              Revision 1.81 2013/07/18 18:12:16CEST Manz, Alexander (uidv8777) 
CHANGES:              Updates due to RTE change:
CHANGES:              Includes: 
CHANGES:               - new HeadlightState
CHANGES:               - EcoLight Feature
CHANGES:               - Light Dimming Areas Feature
CHANGES:               - Light adaptive image display settings for MTS visu
CHANGES:               - SRLCam rec file support in visu
CHANGES:              --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:16 PM CEST]
CHANGES:              Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
CHANGES:              Revision 1.80 2013/05/22 13:38:00CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Adapted simulation adapter to I290 data structs
CHANGES:              Small simulation update
CHANGES:              --- Added comments ---  uidv7867 [May 22, 2013 1:38:00 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.79 2013/04/11 16:20:57CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Implemented some coding parameters
CHANGES:              Tunnel is now global turn off reason
CHANGES:              --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:57 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.78 2013/04/09 16:30:14CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE (SW_COMMON_03.01.01_INT-4)
CHANGES:              --- Added comments ---  uidv7867 [Apr 9, 2013 4:30:14 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.77 2013/03/26 17:27:50CET Manz, Alexander (uidv8777) 
CHANGES:              Adapted Tunnel Detection to use BMW Kodierparameter
CHANGES:               == Warning: not fully tested yet, though it should work (with an emphasis on should) ==
CHANGES:              --- Added comments ---  uidv8777 [Mar 26, 2013 5:27:51 PM CET]
CHANGES:              Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
CHANGES:              Revision 1.76 2013/03/21 17:20:25CET Manz, Alexander (uidv8777) 
CHANGES:              First step of US Sensitivity Mode implementation.
CHANGES:               - added Sensitivity to HLA_t_Availability
CHANGES:               - added visualization
CHANGES:              --- Added comments ---  uidv8777 [Mar 21, 2013 5:20:26 PM CET]
CHANGES:              Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
CHANGES:              Revision 1.75 2013/03/13 19:11:52CET Brunn, Marcus (brunnm) 
CHANGES:              HLAF: used Matrix.MaxNumGlarefreeArea from HLAF Parameter input
CHANGES:              --- Added comments ---  brunnm [Mar 13, 2013 7:11:53 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.74 2013/03/13 17:35:00CET Brunn, Marcus (brunnm) 
CHANGES:              added HLA parameter to HLAR/F input interface
CHANGES:              --- Added comments ---  brunnm [Mar 13, 2013 5:35:00 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.73 2013/03/12 15:57:55CET Mutschler, Matthias (uidv7867) 
CHANGES:              Smaller adapter fixes and clean-up
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 3:57:55 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.72 2013/03/12 14:12:03CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 2:12:03 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.71 2013/03/12 10:59:25CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:25 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.70 2013/03/11 18:02:03CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replace some types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 6:02:04 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.69 2013/03/11 16:48:20CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced  no longer needed macros by RTE ones
CHANGES:              - HLAR_MAX_NUM_DEFECT_PIXEL
CHANGES:              - HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
CHANGES:              - HLAF_NIGHTVIEW_OBJECTS
CHANGES:              - HLA_FINGERPRINT_PIXELS
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 4:48:20 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.68 2013/03/11 16:13:40CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLA_t_eLightStyle
CHANGES:              - HLA_t_eTunnel
CHANGES:              - HLA_t_eCityState
CHANGES:              - HLA_t_eWeatherState
CHANGES:              - HLA_t_eMotorwayState
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:41 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.67 2013/03/11 14:32:59CET Mutschler, Matthias (uidv7867) 
CHANGES:              Placed no longer needed by RTE ones
CHANGES:              - HLA_t_eBrightnessState
CHANGES:              - HLA_t_eLightOutput
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:59 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.66 2013/03/11 10:37:32CET Brunn, Marcus (brunnm) 
CHANGES:              initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
CHANGES:              --- Added comments ---  brunnm [Mar 11, 2013 10:37:32 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.65 2013/03/08 17:43:03CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed HeadlightState and taken RTE type into use
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:03 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.64 2013/03/08 10:30:57CET Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:57 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.63 2013/03/04 11:53:59CET Mutschler, Matthias (uidv7867) 
CHANGES:              Added HLAF timemeas
CHANGES:              Renamed tunnel timemeas
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2013 11:54:00 AM CET]
CHANGES:              Change Package : 167173:27 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.62 2013/02/20 09:31:33CET Brunn, Marcus (brunnm) 
CHANGES:              fixed HLAFin Blockage status
CHANGES:              --- Added comments ---  brunnm [Feb 20, 2013 9:31:34 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.61 2013/02/06 08:41:30CET Brunn, Marcus (brunnm) 
CHANGES:              updated adapter for i210
CHANGES:              --- Added comments ---  brunnm [Feb 6, 2013 8:41:31 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.60 2013/01/28 15:06:47CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eRedReflectorArea
CHANGES:              - HLA_t_eHighwayLatPosState
CHANGES:              - HLA_t_eHighwayEgoMotionState
CHANGES:              - HLA_t_eHighwayOcclusionState
CHANGES:              --- Added comments ---  brunnm [Jan 28, 2013 3:06:47 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.59 2013/01/25 16:59:44CET Mutschler, Matthias (uidv7867) 
CHANGES:              Changed enums to rte like types for missing hlar input params/signals
CHANGES:              --- Added comments ---  uidv7867 [Jan 25, 2013 4:59:44 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.58 2013/01/24 19:14:24CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLAF_t_eNightViewObjectType
CHANGES:              - HLAF_t_eNightViewSpot
CHANGES:              --- Added comments ---  brunnm [Jan 24, 2013 7:14:25 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.57 2013/01/24 17:51:43CET Mutschler, Matthias (uidv7867) 
CHANGES:              Changed ROI bottom calculation
CHANGES:              --- Added comments ---  uidv7867 [Jan 24, 2013 5:51:44 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.56 2013/01/24 16:37:33CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eTunnel
CHANGES:              - HLA_t_eBrightnessState
CHANGES:              - HLA_t_eMotorwayState
CHANGES:              --- Added comments ---  brunnm [Jan 24, 2013 4:37:34 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.55 2013/01/24 10:33:12CET Mutschler, Matthias (uidv7867) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eGlareReductionState
CHANGES:              - HLA_t_eLightModuleState
CHANGES:              --- Added comments ---  uidv7867 [Jan 24, 2013 10:33:13 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.54 2013/01/23 17:57:55CET Brunn, Marcus (brunnm) 
CHANGES:              Converted enum to rte like type for
CHANGES:              - HLA_t_eCityState
CHANGES:              - HLA_t_eWeatherState
CHANGES:              --- Added comments ---  brunnm [Jan 23, 2013 5:57:55 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.53 2013/01/23 16:39:59CET Mutschler, Matthias (uidv7867) 
CHANGES:              Converted enum to rte like type for
CHANGES:              - HLA_t_eHeadLightMode
CHANGES:              - HLA_t_eSpotLight
CHANGES:              - HLA_t_eWindshieldType
CHANGES:              - HLA_t_eDefectPixelType
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 4:40:00 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.52 2013/01/23 14:56:47CET Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed type in Convert_HLA_eLightStyle_v1
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 2:56:48 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.51 2013/01/23 13:27:05CET Brunn, Marcus (brunnm) 
CHANGES:              convert enums from MFC300 to MFC400 (rte types)
CHANGES:              --- Added comments ---  brunnm [Jan 23, 2013 1:27:05 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.50 2013/01/23 10:55:48CET Mutschler, Matthias (uidv7867) 
CHANGES:              Switched from enum to rte like types for
CHANGES:              - HLA_t_eHeadLightType;
CHANGES:              - HLA_t_eHeadLightMechanics;
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 10:55:48 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.49 2013/01/22 16:39:33CET Brunn, Marcus (brunnm) 
CHANGES:              introduced RTE like types for 
CHANGES:              - HLA_t_eState
CHANGES:              - HLA_t_eLevelState
CHANGES:              - HLA_t_eLightOutput
CHANGES:              Revision 1.48 2013/01/22 14:12:39CET Mutschler, Matthias (uidv7867) 
CHANGES:              Fix for previous version
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 2:12:39 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.47 2013/01/22 14:02:12CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced enum by uint32 for HLA_t_eLightStyle
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 2:02:13 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.46 2013/01/22 12:14:10CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced more traffic style enums by uint32
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 12:14:10 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.45 2013/01/22 09:55:18CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced enum by uint32 for traffic style
**************************************************************************** */
#pragma once
#include "glob_type.h"
#include "hla_base.h"
#include "hla_type.h"
#include "hlaf_ext.h"
#include "mfc3_type/mfc3_type.h"


   
void Set_HLA_Availability( HLA_t_Availability   *pDest,
                            RTE_HLA_Type         e_Type,
                            RTE_HLA_State        e_State,
                            RTE_HLA_US_Sens      e_USSens
                          );
void Set_HLA_Availability_Default(HLA_t_Availability   *pDest);
  
RTE_HLAF_HighBeamState Convert_HLA_eHighBeamState_v1(uint8 e_HBState);
uint32 Convert_HLA_SWVersionNumber_v1(uint32 in);
RTE_HLA_State Convert_HLA_eState_v1(uint8 eState);
RTE_HLA_State Convert_HLA_eState_v2(uint8 eState);
RTE_HLA_Type Convert_HLA_eType_v1(uint8 eType);
RTE_HLA_Type Convert_HLA_eType_v2(uint8 eType);
RTE_HLAR_CityState Convert_HLA_eCityState_v1(uint8 eCityState);
RTE_HLAR_CityState Convert_HLA_eCityState_v2(uint8 eCityState);
RTE_HLAR_WeatherState Convert_HLA_eWeatherState_v1(uint8 eWeatherState);
RTE_HLAR_WeatherState Convert_HLA_eWeatherState_v2(uint8 eWeatherState);
RTE_HLAR_Tunnel Convert_HLA_eTunnel_v1(uint8 eTunnel);
RTE_HLAR_Tunnel Convert_HLA_eTunnel_v2(uint8 eTunnel);
RTE_HLAF_MotorwayState Convert_HLA_eMotorwayState_v1(uint8 eMotorwayState);
RTE_HLAR_BrightnessState Convert_HLA_eBrightnessState_v1(uint8 eBrightnessState);
AlgoSignalState_t Convert_HLA_eSignalState_v1(uint8 eSignalState);
RTE_HLAF_NightViewObjectType Convert_HLA_eNightViewObjectType_v1(uint8 eNightViewObjectType);
RTE_HLAF_NightViewObjectType Convert_HLA_eNightViewObjectType_v2(uint8 eNightViewObjectType);
RTE_HLAF_NightViewSpot Convert_HLA_eNightViewSpot_v1(uint8 eNightViewSpot);
RTE_HLAF_NightViewSpot Convert_HLA_eNightViewSpot_v2(uint8 eNightViewSpot);
RTE_HLAR_RedReflectorArea Convert_HLA_eRedReflectorArea_v1(uint8 eRedReflectorArea);
RTE_HLAR_RedReflectorArea Convert_HLA_eRedReflectorArea_v2(uint8 eRedReflectorArea);
RTE_HLAR_HighwayLatPosState Convert_HLA_eHighwayLatPosState_v1(uint8 eHighwayLatPosState);
RTE_HLAR_HighwayLatPosState Convert_HLA_eHighwayLatPosState_v2(uint8 eHighwayLatPosState);
RTE_HLAR_HighwayEgoMotionState Convert_HLA_eHighwayEgoMotionState_v1(uint8 eHighwayEgoMotionState);
RTE_HLAR_eHighwayOcclusionState Convert_HLA_eHighwayOcclusionState_v1(uint8 eHighwayEgoMotionState);
RTE_HLAF_MatrixTurnOffReason Convert_HLA_eTurnOffReason_v1(uint32 eTurnOffReason);

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
                              );
void Set_HLA_HeadlightState_v2(HLA_t_HeadlightState        *pDest,
                                RTE_HLA_LightModuleState    e_LightModuleState,
                                RTE_HLAF_HighBeamState      e_HighBeamState,
                                HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt,
                                HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt,
                                RTE_HLA_GlareReductionState e_GlareReductionState,
                                HLA_t_f32LightOutput        f32_LightOutput,
                                uint32                      nGFA
                              );
void Set_HLA_HeadlightState_Default(HLA_t_HeadlightState *pDest);


void Set_HLA_MatrixGFAState_v1(HLA_t_MatrixGFAState     *pDest,
                                HLA_t_fLightAngle        f32_PartHBCutoffAng_Lt,
                                HLA_t_fLightAngle        f32_PartHBCutoffAng_Rt,
                                HLA_t_fLightAngle        f32_HorCutOffAng,
                                HLA_t_fLightDistance     f32_LightDistance,
                                RTE_HLA_CutOffLineState  e_HorCutOffAngStatus,
                                RTE_HLA_CutOffLineState  e_LightDistanceStatus,
                                RTE_HLA_LightStyle       e_LightStyle_Lt,
                                RTE_HLA_LightStyle       e_LightStyle_Rt
                              );
void Set_HLA_MatrixGFAState_Default(HLA_t_MatrixGFAState *pDest);


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
                        );
void Set_HLA_ImagerState_Default(HLA_t_ImagerState *pDest);


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
                        );
void Set_HLA_MotionState_Default(HLA_t_MotionState *pDest);


void Set_HLA_VehicleState( HLA_t_VehicleState       *pDest,
                            boolean                  b_FogLampFront,
                            boolean                  b_FogLampRear,
                            boolean                  b_RainSensor,
                            uint8                    ui8_WiperState,
                            HLA_t_eWiperWasherState  e_WiperWasherFrontState,
                            HLA_t_eWiperStage        e_WiperStage,
                            HLA_t_VehLevel_v1        s_VehicleLevel
                          );
void Set_HLA_VehicleState_Default(HLA_t_VehicleState *pDest);


void Set_HLA_CaliOnline(HLA_t_CaliOnline  *pDest,
                        float32           f32_OdoCali_m,
                        float32           f32_Pitch,
                        float32           f32_Roll,
                        float32           f32_Yaw);
void Set_HLA_CaliOnline_Default(HLA_t_CaliOnline *pDest);


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
                              );
void Set_HLA_CameraParameter_Default(HLA_t_CameraParameter *pDest);


void Set_HLA_ParameterRoi( RTE_HLAR_ParameterRoi_t *pDest,
                                          float32               FOV_Horizontal,
                                          float32               FOV_FunctionRoiAboveHorizon,
                                          float32               FOV_MinBelowHorizon,
                                          float32               FOV_MinAboveHorizon,
                                          float32               PrecVehLight_minDistance,
                                          float32               PrecVehLight_minHeight,
                                          float32               StreetLamp_Distance,
                                          float32               StreetLamp_Height
                                        );

void Set_HLA_ParameterCity( RTE_HLAR_ParameterCity_t *pDest,
                                            float32 SpeedThresholdLow,
                                            float32 SpeedThresholdHigh,
                                            uint16 NumLeavingStreetlamp_LowSpeed,
                                            uint16 NumLeavingStreetlamp_HighSpeed,
                                            uint16 NumSceneStreetlamp_LowSpeed,
                                            uint16 NumSceneStreetlamp_HighSpeed,
                                            uint16 AmbientLevel_LowSpeed,
                                            uint16 AmbientLevel_HighSpeed,
                                            float32 StreetLampMaxInterDist_LowSpeed,
                                            float32 StreetLampMaxInterDist_HighSpeed,
                                            float32 StreetLampMaxDist_LowSpeed,
                                            float32 StreetLampMaxDist_HighSpeed,
                                            float32 LeavingCityDelay_LowSpeed,
                                            float32 LeavingCityDelay_HighSpeed,
                                            float32 LeavingCityDelaySceneStreetlamp_LowInt,
                                            float32 LeavingCityDelaySceneStreetlamp_HighInt,
                                            uint16 NumTunnelStreetlamp
                                          );
 
void Set_HLA_ParameterHighway( RTE_HLAR_ParameterHighway_t *pDest,
                                              float32 SpeedDetThreshold_Fast,
                                              float32 SpeedDetThreshold,
                                              float32 SpeedDetThresholdDistance,
                                              float32 EgoMotionDetThresholdHigh,
                                              float32 EgoMotionDetThresholdLow,
                                              uint16 LateralPositionUsedTracks,
                                              float32 LateralPositionConfidenceThreshHigh,
                                              float32 LateralPositionConfidenceThreshLow,
                                              uint16 OcclusionOncomingLeavingLightsThresh,
                                              float32 OcclusionConfidenceStep
                                              );
  
void Set_HLA_ParameterTunnel(RTE_HLAR_ParameterTunnel_t  *pDest,
                                            float32                     EntryThreshHigh,
                                            float32                     EntryThreshLow,
                                            float32                     EntryDistanceMin,
                                            float32                     EntryDistanceMax,
                                            float32                     ExitThreshHigh,
                                            float32                     ExitThreshLow,
                                            float32                     ExitDistanceMin,
                                            float32                     DetectionTypeDistance
                                            );
  
void Set_HLA_ParameterTrafficStyle( RTE_HLAR_ParameterTrafficStyle_t *pDest,
                                                    uint16 NumOncLightsThres,
                                                    uint16 NumOncLightsLock
                                                  );

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
                                              );

void Set_HLA_ParameterVehDet( RTE_HLAR_ParameterVehDet_t *pDest,
                                              uint16 OncSensitivity,
                                              uint16 PrecSensitivity
                                            );

void Set_HLA_ParameterLightPair( RTE_HLAR_ParameterLightPair_t *pDest,
                                                float32 TaillightWidth_Min,
                                                float32 TaillightWidth_Max,
                                                float32 HeadlightWidth_Min,
                                                float32 HeadlightWidth_Max,
                                                float32 TaillightHeight_Min,
                                                float32 TaillightHeight_Max,
                                                float32 HeadlightHeight_Min,
                                                float32 HeadlightHeight_Max
                                                );

void Set_HLA_ParameterDistEst( RTE_HLAR_ParameterDistEst_t *pDest,
                                              float32 LightHeight_Min,
                                              float32 LightHeight_Max,
                                              float32 DistFilterConst
                                              );
  
void Set_HLA_ParameterTTBEst( RTE_HLAR_ParameterTTBEst_t *pDest,
                                              float32 ttbAngle
                                            );

void Set_HLA_SensorAngles( HLA_t_SensorAngles                    *pDest,
                                          float32                               f32_Pitch,
                                          float32                               f32_Roll,
                                          float32                               f32_Yaw,
                                          float32                               f32_Quality,
                                          eMonoCalibrationVerificationStatus_t  e_State
                                        );
void Set_HLA_SensorAngles_Default(HLA_t_SensorAngles *pDest);


void Set_HLA_ParameterAlgoCfg( RTE_HLA_ParameterAlgoCfg_t *pDest,
                                            RTE_HLA_TestMode TestMode,
                                            RTE_HLA_CityDetection CityDetection,
                                            RTE_HLA_TunnelDetection TunnelDetection,
                                            RTE_HLA_BadPixelDetection BadPixelDetection,
                                            RTE_HLA_FogDetection FogDetection,
                                            RTE_HLA_BlockageDetection BlockageDetection
                                          );

void Set_HLA_ParameterHeadlight( RTE_HLA_ParameterHeadlight_t *pDest,
                                                RTE_HLA_HeadlightType HeadLightType,
                                                RTE_HLA_HeadLightMechanics HeadLightMechanics,
                                                RTE_HLA_SpotLight SpotLight,
                                                float32 SpotLightWidth,
                                                float32 FullHBDefaultPos_Left,
                                                float32 FullHBDefaultPos_Right,
                                                float32 HeadLampLatency,
                                                float32 SpotLightTolerance
                                                );

void Set_HLA_ParameterCountry( RTE_HLA_ParameterCountry_t *pDest,
                                              RTE_HLA_TrafficStyle TrafficStyle,
                                              RTE_HLA_SensMode SensitivityMode,
                                              RTE_HLA_MultipleReflectors CountryWithMultipleReflectors
                                            );

void Set_HLA_ParameterVehicle( RTE_HLA_ParameterVehicle_t *pDest,
                                              RTE_HLA_WindshieldType WindshieldType 
                                            );

void Set_HLA_ParameterTurnOff( RTE_HLAF_ParameterTurnOff_t *pDest,
                                              float32 TTBThreshold,
                                              float32 HorAngThreshold
                                              );

void Set_HLA_ParameterKeepOff( RTE_HLAF_ParameterKeepOff_t *pDest,
                                              float32 Radius2TurnsOnThres,
                                              float32 TurnOnDelay
                                              );

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
                                                  );

void Set_HLA_ParameterSpeed( RTE_HLAF_ParameterSpeed_t *pDest,
                                            float32 DeactivateSpeed,
                                            float32 ActivateSpeed,
                                            float32 AlwaysActiveSpeed,
                                            float32 KeepOff_VeryLowSpeed,
                                            float32 KeepOff_LowRadius,
                                            float32 KeepOff_HighAcceleration,
                                            float32 KeepOff_AccTime,
                                            float32 KeepOff_Delay
                                            );

void Set_HLA_ParameterBlockage( RTE_HLAF_ParameterBlockage_t *pDest,
                                                float32                         ConfidenceThreshold,
                                                float32                         ClearMeas2Blockage_DistThres,
                                                float32                         ClearMeas2Blockage_TimeThres,
                                                float32                         ClearMeas2NoBlockage_DistThres,
                                                float32                         NoBlockage2Blockage_DistThres,
                                                float32                         NoBlockage2Blockage_TimeThres,
                                                float32                         Blockage2NoBlockage_TimeThres,
                                                RTE_HLA_BlockageManualOverwrite ManualOverwrite
                                              );

void Set_HLA_ParameterFog( RTE_HLAF_ParameterFog_t *pDest,
                                          uint16 ConfidenceThreshold,
                                          uint16 Sensitivity
                                          );

void Set_HLA_ParameterMatrixBeam( RTE_HLAF_ParameterMatrixBeam_t *pDest,
                                                  uint16 MaxNumGlarefreeArea 
                                                );


void Set_HLA_Matrix( HLAF_t_Matrix               *pDest,
                      uint32                       nGFA,
                      RTE_HLAF_SignalStatus        GFAStatus,
                      RTE_HLAF_HighBeamState       HighBeamState,
                      float32                      LowBeam_Dist,
                      float32                      LowBeam_Ang,
                      RTE_HLAF_ObjStatus           LowBeam_Status,
                      RTE_HLAF_MatrixTurnOffReason TurnOffReason
                    );
void Set_HLA_Matrix_Default( HLAF_t_Matrix *pDest);


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
                        );
void Set_HLA_MatrixGFA_Default( HLAF_t_MatrixGFA *pDest);


void Set_HLA_EcoLight(HLAF_EcoLight_t *pDest,
                      RTE_HLAF_EcoLight_eAvailabilityState AvailabilityState,
                      RTE_HLAF_EcoLight_eDetectionState DetectionState,
                      float32 ObjectDist,
                      RTE_HLAF_EcoLight_eVehicleType ObjectType,
                      RTE_HLAF_EcoLight_eVehicleLight ObjectLightState
                      );
void Set_HLA_EcoLight_Default(HLAF_EcoLight_t *pDest);


void Set_HLA_LightDimmingArea(HLAF_DimmingArea_t *pDest,
                              float32                 BndryLeft_Ang_Cam,
                              float32                 BndryRight_Ang_Cam,
                              float32                 BndryLower_Ang_Cam,
                              RTE_HLAF_LightOutput    LightOutput);
void Set_HLA_LightDimmingArea_Default(HLAF_DimmingArea_t *pDest);


void Set_HLA_LightDimming(HLAF_LightDimming_t *pDest,
                          RTE_HLAF_DimmingStatus DimmingStatus,
                          uint32 nDimmingArea
                          );
void Set_HLA_LightDimming_Default(HLAF_LightDimming_t *pDest);


void Set_HLA_Blockage(HLA_t_Blockage     *pDest,
                      boolean            b_ClearanceMeasurement,
                      boolean            b_Condensation,
                      boolean            b_Blockage,
                      boolean            b_ManualOverride,
                      AlgoSignalState_t  e_SigStatus  
                      );
void Set_HLA_Blockage_Default(HLA_t_Blockage *pDest);
 

void Set_ICDefectPixel( HLA_t_ICDefectPixel *pDest,
                        uint16              ui16_xPos,
                        uint16              ui16_yPos,
                        RTE_HLAR_DefectPixelType e_DefectType,
                        uint16              ui16_Count
                      );
void Set_ICDefectPixel_Default(HLA_t_ICDefectPixel *pDest);
  

void Set_HLAF_NightViewObject( HLAF_t_NightViewObject       *pDest,
                                uint8                        ui8_ID,
                                RTE_HLAF_NightViewObjectType e_ObjType,
                                RTE_HLAF_NightViewSpot       e_Spot,
                                float32                      f32_Distance_m,
                                float32                      f32_HorAng_rad
                              );
void Set_HLAF_NightViewObject_Default(HLAF_t_NightViewObject *pDest);


void Set_HLAF_ecoLightObject( EM_t_GenObject              *pDest,
                              uint8                       uiID,
                              float32                     fDistX,
                              float32                     fDistY,
                              EM_t_GenObjMaintenanceState eMaintenanceState,
                              EM_t_GenObjClassification   eClassification
                            );
void Set_HLAF_ecoLightObject_default(EM_t_GenObject  *pDest);


RTE_HLA_TrafficStyle Convert_HLA_eTrafficStyle_v1(uint8 e_TrafficStyle);
RTE_HLAR_TrafficStyleLearningState Convert_HLA_eTrafficStyleLearningState_v1(uint8 e_TrafficStyleLearningState);
RTE_HLAR_TrafficStyleLearningState Convert_HLA_eTrafficStyleLearningState_v2(uint8 e_TrafficStyleLearningState);
