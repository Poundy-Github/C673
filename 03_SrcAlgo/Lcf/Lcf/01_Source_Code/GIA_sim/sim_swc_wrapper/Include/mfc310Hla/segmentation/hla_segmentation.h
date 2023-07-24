/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_segmentation.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segmentation.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:40CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:26CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:57CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.25 2014/03/25 19:11:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:45 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.24 2014/03/25 18:46:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_segmentation.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_segmentation.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj.
  CHANGE:                 Revision 1.23 2014/03/05 14:08:59CET Brunn, Marcus (brunnm) 
  CHANGE:                 added RTE_HLA_Seg_LightList_t
  CHANGE:                 --- Added comments ---  brunnm [Mar 5, 2014 2:08:59 PM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.22 2014/03/05 11:05:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:23 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21 2014/03/04 16:52:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:07 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.20 2014/03/03 16:51:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.1 interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:35 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2014/03/03 13:10:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced tabs by spaces
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 1:10:59 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2014/02/28 15:04:56CET Brunn, Marcus (brunnm) 
  CHANGE:                 - improved light filtering
  CHANGE:                 - preparation of light list for new rte interface i390
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:04:57 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.17 2014/02/11 09:20:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed time meas
  CHANGE:                 Fixed dframe calculation on HIL
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:07 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/02/06 16:02:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 Revision 1.15 2014/02/05 15:26:54CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed LED segmentation
  CHANGE:                 --- Added comments ---  brunnm [Feb 5, 2014 3:26:54 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.14 2014/01/10 18:33:16CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:16 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.13 2014/01/08 17:10:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 Revision 1.12 2013/12/13 16:45:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:09 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11 2013/12/05 17:47:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Update to RTE I330
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:55 PM CET]
  CHANGE:                 Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.10 2013/12/04 16:18:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Use L2 Cache for SegLightBuffer, SegLineRegionBuffer
  CHANGE:                 Fixed deadlock in segmentation
  CHANGE:                 
  CHANGE:                 Review by AlexM.
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 4, 2013 4:18:25 PM CET]
  CHANGE:                 Change Package : 207432:10 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9 2013/11/21 17:53:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:49 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.8.1.6 2013/11/19 13:44:06CET Brunn, Marcus (brunnm) 
  CHANGE:                 - clean up -> removed unused vars/ functions
  CHANGE:                 - added detailed time measurement for segmentation
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 1:44:06 PM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.8.1.5 2013/11/19 07:54:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 - removed day segmentation
  CHANGE:                 - updated HLASegLineBuffer_t
  CHANGE:                 - updated HLASegLineRegion_t (used region index instead of region pointer)
  CHANGE:                 - optimized region build
  CHANGE:                 - reduced max number of regions from 250 to 200
  CHANGE:                 Revision 1.8.1.4 2013/10/29 18:21:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Time meas fixes
  CHANGE:                 New roi calculation (alignment to eve)
  CHANGE:                 Call EVE in segmentation now
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:24 PM CET]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.8.1.3 2013/10/21 16:00:28CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced preprocessing function: HLASegPreProcImage()
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 4:00:28 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.8.1.2 2013/10/21 08:36:26CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - clean up
  CHANGE:                 - introduced adaptive thresholds for level 4 and 5
  CHANGE:                 Revision 1.8.1.1 2013/10/18 13:27:57CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 Revision 1.19.1.66 2013/07/26 17:04:11CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added first part of EVE implementation
  CHANGE:                 --- Added comments ---  uidv7867 [Jul 26, 2013 5:04:12 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19.1.65 2013/05/02 12:43:01CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE for I300
  CHANGE:                 --- Added comments ---  uidv7867 [May 2, 2013 12:43:02 PM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19.1.64 2013/04/09 16:30:10CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE (SW_COMMON_03.01.01_INT-4)
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 9, 2013 4:30:11 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19.1.63 2013/03/12 10:59:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:44 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19.1.62 2013/03/11 14:33:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:05 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19.1.61 2013/03/06 11:19:26CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - remove dependencies to algo_common
  CHANGE:                 - replace HLA type Pix16_t by RTE type t_PixelData
  CHANGE:                 --- Added comments ---  uidt9253 [Mar 6, 2013 11:19:26 AM CET]
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGE:                 Revision 1.19.1.60 2013/01/15 15:22:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Clean-up, added some const keywords
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 15, 2013 3:23:00 PM CET]
  CHANGE:                 Change Package : 167173:23 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19.1.59 2013/01/11 09:05:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 support new opmodes (segmentation: autothreshold off)
  CHANGE:                 --- Added comments ---  brunnm [Jan 11, 2013 9:05:08 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.19.1.58 2012/10/10 13:02:46CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:02:47 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.19.1.57 2012/10/05 12:46:32CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:46:32 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.19.1.56 2012/07/03 18:18:31CEST Mueller, Reik (muellerr5) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  muellerr5 [Jul 3, 2012 6:18:32 PM CEST]
  CHANGE:                 Change Package : 110788:1 http://mks-psad:7002/im/viewissue?selection=110788
  CHANGE:                 Revision 1.19.1.55 2012/03/29 23:17:45CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed blindings in spain where 85 tracks are not enough
  CHANGE:                 --- Added comments ---  brunnm [Mar 29, 2012 11:17:45 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.19.1.54 2012/02/23 06:05:05CET Brunn, Marcus (brunnm) 
  CHANGE:                 backwards driving: delete all lights (nlights = 0)
  CHANGE:                 --- Added comments ---  brunnm [Feb 23, 2012 6:05:05 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.19.1.53 2011/11/11 14:56:35CET Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update for Level 3 Threshold calculation 
  CHANGE:                 - improved light detection in foggy situations
  CHANGE:                 --- Added comments ---  brunnm [Nov 11, 2011 2:56:35 PM CET]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.19.1.52 2011/11/08 11:03:59CET Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 - fixed missing light in segmentation for LED Phaeton tail light
  CHANGE:                 - fixed frame to frame jumping level 3 threshold
  CHANGE:                 --- Added comments ---  brunnm [Nov 8, 2011 11:03:59 AM CET]
  CHANGE:                 Change Package : 87120:1 http://mks-psad:7002/im/viewissue?selection=87120
  CHANGE:                 Revision 1.19.1.51 2011/08/29 23:15:06CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 clean internal segmentation data after HLAR/F main function (not during segmentation)
  CHANGE:                 --- Added comments ---  brunnm [Aug 29, 2011 11:15:08 PM CEST]
  CHANGE:                 Change Package : 66902:2 http://mks-psad:7002/im/viewissue?selection=66902
  CHANGE:                 Revision 1.19.1.50 2011/06/30 08:20:32CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 fixed save maximas for oncomings in saturation (3999)
  CHANGE:                 --- Added comments ---  brunnm [Jun 30, 2011 8:20:32 AM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.19.1.49 2011/06/22 08:31:56CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 hla segmentation: init global vars before segmentation starts
  CHANGE:                 --- Added comments ---  brunnm [Jun 22, 2011 8:31:57 AM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.19.1.48 2011/06/20 15:30:13CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Segmentation: implemented light clustering
  CHANGE:                 Revision 1.19.1.47 2011/05/23 13:58:37CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 - renamed seg_TracklistNode into HLATrack_t
  CHANGE:                 - renamed seg_ListNode into HLASegLight_t
  CHANGE:                 --- Added comments ---  brunnm [May 23, 2011 1:58:37 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.19.1.46 2011/05/17 13:09:00CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 dusk/ dawn bugfix
  CHANGE:                 --- Added comments ---  brunnm [May 17, 2011 1:09:00 PM CEST]
  CHANGE:                 Change Package : 66902:1 http://mks-psad:7002/im/viewissue?selection=66902
  CHANGE:                 Revision 1.19.1.45 2011/05/06 06:17:35CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 implemented icon handler
  CHANGE:                 Revision 1.19.1.44 2011/04/14 10:17:10CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 runtime optimized segmentation
  CHANGE:                 --- Added comments ---  brunnm [Apr 14, 2011 10:17:11 AM CEST]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.19.1.43 2011/03/10 22:42:13CET Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 - added segmentation debug data
  CHANGE:                 Revision 1.19.1.42 2011/02/22 08:32:20CET Marcus Brunn (brunnm) 
  CHANGE:                 - calculate segmentation threshold before the first row starts
  CHANGE:                 - dInt = 0 for level 1 (region 1) during segmentation (because of the dark red lights)
  CHANGE:                 Revision 1.19.1.41 2011/02/14 08:53:52CET Marcus Brunn (brunnm) 
  CHANGE:                 - added roi parameter
  CHANGE:                 - moved global used type defintions to hla_base.h (e.g. tracking list, maxima list)
  CHANGE:                 - removed direct access to hlaCamData, instead added hlaCamData pointer to all functions
  CHANGE:                 Revision 1.19.1.40 2011/02/10 11:46:26CET Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 Improve 3D tracking run-time
  CHANGE:                 ->Add time measurements for debug
  CHANGE:                 ->Set maxNTestClusterAssoc=2000
  CHANGE:                 ->Set HLA_EGO_MAX_NUMBER_OF_TRACK_FULL_EGO=12
  CHANGE:                 ->Set HLAEGO_MAX_POSSIBLE_TRACKS=3
  CHANGE:                 --- Added comments ---  uid28828 [Feb 10, 2011 11:46:26 AM CET]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.39 2011/02/09 07:32:50CET Marcus Brunn (brunnm) 
  CHANGE:                 - implemented subsampled image (5x5 in lux)
  CHANGE:                 - adapted segmentation behaviour in bright scenes (city, dusk and dawn)
  CHANGE:                 --- Added comments ---  brunnm [Feb 9, 2011 7:32:50 AM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.19.1.38 2011/02/03 18:40:56CET Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 Tracking 3D: modify dynamic analysis when track is starting
  CHANGE:                 --- Added comments ---  uid28828 [Feb 3, 2011 6:40:58 PM CET]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.37 2010/12/14 19:24:28CET Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D tracking:
  CHANGE:                 -> improve runtime of light 2 track association function
  CHANGE:                 -> limit number of tree search up to 1000
  CHANGE:                 -> remove preprocessed data of segmented lights from RAM.
  CHANGE:                 --- Added comments ---  uid28828 [Dec 14, 2010 7:24:29 PM CET]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.36 2010/12/13 13:43:44CET Reik Mueller (x-muellerr5) 
  CHANGE:                 - switch to fast binarize row function also accounts for number of new maxima and new line segments
  CHANGE:                 --- Added comments ---  x-muellerr5 [Dec 13, 2010 1:43:44 PM CET]
  CHANGE:                 Change Package : 54107:1 http://mks-psad:7002/im/viewissue?selection=54107
  CHANGE:                 Revision 1.19.1.35 2010/12/03 10:41:25CET Marcus Brunn (brunnm) 
  CHANGE:                 improved segmentation for tunnels (above function ROI):
  CHANGE:                 - implemented separat parameter set for function ROI and above function ROI
  CHANGE:                 --- Added comments ---  brunnm [Dec 3, 2010 10:41:25 AM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.19.1.34 2010/12/02 13:33:37CET Marcus Brunn (brunnm) 
  CHANGE:                 imager:
  CHANGE:                 - added function to read T1 saturation region
  CHANGE:                 segmentation:
  CHANGE:                 - clustering: increased number of regions from 64 to 128
  CHANGE:                 - binarize row: implemented special feature for T1 saturation (dInt always 0)
  CHANGE:                 Revision 1.19.1.33 2010/12/01 14:54:38CET Marcus Brunn (brunnm) 
  CHANGE:                 segmentation:
  CHANGE:                 - create a new light for all maxima which belongs to no region
  CHANGE:                 - improvement for large traffic signs (dInt_Level2,3 = 0 for maxima < 200)
  CHANGE:                 - added handling for senarios with more than 500 line segments
  CHANGE:                 Revision 1.19.1.32 2010/11/30 09:39:36CET Marcus Brunn (brunnm) 
  CHANGE:                 segmentation:
  CHANGE:                 - added IntThreshold_Level1,2,3_lux to hlaSegdata
  CHANGE:                 Revision 1.19.1.31 2010/11/30 07:52:10CET Marcus Brunn (brunnm) 
  CHANGE:                 runtime improved segmentation:
  CHANGE:                 - do not segment the dark red pixels
  CHANGE:                 - increase thresholds to be below 500 maxima
  CHANGE:                 - switch to fast segmentation (every 2nd red pixel will be checked) when too many pixels in one row are above threshold level 1 (>= 100 pixel)
  CHANGE:                 - runtime optimized mean intensity calculation
  CHANGE:                 --- Added comments ---  brunnm [Nov 30, 2010 7:52:10 AM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.19.1.30 2010/11/25 17:16:00CET Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 Allow new tracks based on lux intensity.
  CHANGE:                 Don't allow initiation of a new track for a light: case when a single-light to single-track association has not been validated.
  CHANGE:                 --- Added comments ---  uid28828 [Nov 25, 2010 5:16:01 PM CET]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.29 2010/11/24 14:45:44CET Reik Mueller (x-muellerr5) 
  CHANGE:                 - removed pLastMaxima from seg_Listnode struct
  CHANGE:                 --- Added comments ---  x-muellerr5 [Nov 24, 2010 2:45:45 PM CET]
  CHANGE:                 Change Package : 54107:1 http://mks-psad:7002/im/viewissue?selection=54107
  CHANGE:                 Revision 1.19.1.28 2010/11/10 17:15:20CET Reik Mueller (x-muellerr5) 
  CHANGE:                 - fixed struct definition to avoid MFC300 compiler errors
  CHANGE:                 --- Added comments ---  x-muellerr5 [Nov 10, 2010 5:15:20 PM CET]
  CHANGE:                 Change Package : 54107:1 http://mks-psad:7002/im/viewissue?selection=54107
  CHANGE:                 Revision 1.19.1.27 2010/11/10 16:31:34CET Reik Mueller (x-muellerr5) 
  CHANGE:                 - added new features for seg_Listnode (adaption of 3D tracking for new segmentation)
  CHANGE:                 Revision 1.19.1.26 2010/11/10 16:21:27CET Reik Mueller (x-muellerr5) 
  CHANGE:                 - added new blob segmentation and maxima clustering
  CHANGE:                 Revision 1.19.1.25 2010/11/04 13:49:17CET Marcus Brunn (brunnm) 
  CHANGE:                 added 16bit raw pixel to HLASegNgb_t (save runtime during segmentation)
  CHANGE:                 --- Added comments ---  brunnm [Nov 4, 2010 1:49:18 PM CET]
  CHANGE:                 Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.19.1.24 2010/11/02 15:59:19CET Marcus Brunn (brunnm) 
  CHANGE:                 removed 12Bit ngbs from maxima list to save RAM
  CHANGE:                 Revision 1.19.1.23 2010/10/26 17:38:44CEST Marcus Brunn (brunnm) 
  CHANGE:                 - added hla_base.h, hla_debug.h
  CHANGE:                 - removed vdata/ vdy dependencies from CSF200 (PC_SIM)
  CHANGE:                 - read hla debug output measfreezes (turn off reason, time measurement, debug tracks)
  CHANGE:                 --- Added comments ---  brunnm [Oct 26, 2010 5:38:44 PM CEST]
  CHANGE:                 Change Package : 38437:4 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGE:                 Revision 1.19.1.22 2010/10/23 07:30:21CEST Marcus Brunn (brunnm) 
  CHANGE:                 added internal measfreezes
  CHANGE:                 --- Added comments ---  brunnm [Oct 23, 2010 7:30:21 AM CEST]
  CHANGE:                 Change Package : 38437:4 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGE:                 Revision 1.19.1.21 2010/10/21 19:02:26CEST Marcus Brunn (brunnm) 
  CHANGE:                 removed rgb lux table from CSF
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2010 7:02:26 PM CEST]
  CHANGE:                 Change Package : 38437:4 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGE:                 Revision 1.19.1.20 2010/10/13 14:01:15CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D Tracking: remove exclusion check when creating new tracks. Information is already avalaible when associating lights to tracks.
  CHANGE:                 --- Added comments ---  uid28828 [Oct 13, 2010 2:01:15 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.19 2010/10/12 19:07:15CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D tracking: rework clustering of tracks and lights
  CHANGE:                 --- Added comments ---  uid28828 [Oct 12, 2010 7:07:15 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.18 2010/10/06 18:50:57CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D Tracking: Change way associated lights are stored
  CHANGE:                 --- Added comments ---  uid28828 [Oct 6, 2010 6:50:57 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.17 2010/10/06 18:05:56CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D tracking Update to fit with hla_tracking_3D rev 1.9
  CHANGE:                 - Change ego_class and ego_stage to StaticTrackerStage DynamicTrackerStage and TrackerClass
  CHANGE:                 - Calculate min/max static distance from static/egomotion tracker
  CHANGE:                 - Add variance of measurement noise. Inverse innovation while associating light and track
  CHANGE:                 - Use light radius as measurement error
  CHANGE:                 - Fix bug derivatives for intensity prediction
  CHANGE:                 - isolate function for initialization of uw,vw
  CHANGE:                 - 3D tracking: parametrize pitch filter
  CHANGE:                 --- Added comments ---  uid28828 [Oct 6, 2010 6:05:56 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.19.1.16 2010/10/06 09:36:47CEST Marcus Brunn (brunnm) 
  CHANGE:                 bugfix for segmentation (function prototyp, maxima struct)
  CHANGE:                 --- Added comments ---  brunnm [Oct 6, 2010 9:36:47 AM CEST]
  CHANGE:                 Change Package : 38437:4 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGE:                 Revision 1.19.1.15 2010/10/01 10:38:21CEST Marcus Brunn (brunnm) 
  CHANGE:                 rework of hla segmentation
  CHANGE:                
**************************************************************************** */

#ifndef HLA_SEGMENTATION_INCLUDED
#define HLA_SEGMENTATION_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h" 
#include "hlar_ext.h"
#include "hla_debug.h"
#include "hla_segutils.h"



/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/* Region buffer interface version numbers */
#define SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER_MAIN    3
#define SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER_SUB     1
#define SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN              << 24) \
                                                     | (SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                                     | (SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER_SUB << 8) \
                                                     | (SEGLINE_REGION_BUF_INTERFACE_VERSION_NUMBER_BUGFIX))


/******************************************************************************
* TYPEDEFS
******************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

void HLASegmentationExec( const HLAR_t_RequiredInputs*        ps_In,
                          t_PixelData*                        pImg,
                          const HLACameraData_t*              pCamData,
                          const HLA_t_SegmentationParameters* pPar,
                          const HLASegIn_t*                   pIn,
                          HLASegData_t*                       pData,
                          HLASegOut_t*                        pOut,
                          HLASegLightBuffer_t*                pLightBuffer,
                          HLASegLineRegionBuffer_t*           pRegionBuffer,
                          RTE_HLA_Seg_LightList_t*            ps_SegLightList, /* RTE Out */
                          HLADebugOutputs_t*                  pDebug,
                          const AS_t_ServiceFuncts*           Services
                        );

void HLASegmentationMeasfreeze( const AS_t_MeasHdlr             pfMeasFreeze,
                                const HLASegLineRegionBuffer_t* pRegionBuffer,
                                const HLASegLightBuffer_t*      pLightBuffer
                               );

/*! initializes the segmentation after bootup (called only once) */
void HLASegmentationInit( HLASegLineRegionBuffer_t* pRegionBuffer,
                          HLASegLightBuffer_t*      pLightBuffer,
                          HLASegData_t*             pData, 
                          HLASegOut_t*              pOut,
                          RTE_HLA_Seg_LightList_t*  ps_SegLightList /* RTE Out */
                        );

/*! reinitializes the segmentation after each hlar main function call */
void HLASegmentationReInit( HLASegLineRegionBuffer_t* pRegionBuffer,
                            HLASegLightBuffer_t*      pLightBuffer,
                            HLASegData_t*             pData, 
                            HLASegOut_t*              pOut,
                            RTE_HLA_Seg_LightList_t*  ps_SegLightList /* RTE Out */
                          );

#endif

