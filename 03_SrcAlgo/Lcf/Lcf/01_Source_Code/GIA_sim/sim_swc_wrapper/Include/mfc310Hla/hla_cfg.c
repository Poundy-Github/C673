/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_cfg.c

  DESCRIPTION:            Configuration file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-09-30

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_cfg.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:31CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:41CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:06CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.190 2014/03/22 10:28:21CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added project specific defines
  CHANGES:                Replaced defines for CORE by predefined ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:21 AM CET]
  CHANGES:                Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.189 2014/03/19 16:30:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:54 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.188 2014/03/19 15:17:52CET Fischer, Alexander (uidv8778) 
  CHANGES:                Added numSLInSceneLeaveCityJapan Parameter (japan specific)
  CHANGES:                --- Added comments ---  uidv8778 [Mar 19, 2014 3:17:52 PM CET]
  CHANGES:                Change Package : 226009:1 http://mks-psad:7002/im/viewissue?selection=226009
  CHANGES:                Revision 1.187 2014/03/13 10:08:22CET Glebov, Roman (uidg4759) 
  CHANGES:                changed MaxIntParamter from 0.75 to 0.4
  CHANGES:                --- Added comments ---  uidg4759 [Mar 13, 2014 10:08:23 AM CET]
  CHANGES:                Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGES:                Revision 1.186 2014/03/11 10:33:51CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced SRLCAM_4T0 by CFG_SRLCAM==1
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2014 10:33:51 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.185 2014/03/06 13:38:12CET Brunn, Marcus (brunnm) 
  CHANGES:                fixed #ifdef SRLCAM_4T0
  CHANGES:                --- Added comments ---  brunnm [Mar 6, 2014 1:38:12 PM CET]
  CHANGES:                Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGES:                Revision 1.184 2014/03/06 10:18:11CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added SRLCam restrictions again
  CHANGES:                --- Added comments ---  uidv7867 [Mar 6, 2014 10:18:12 AM CET]
  CHANGES:                Change Package : 207432:29 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.183 2014/02/28 15:04:51CET Brunn, Marcus (brunnm) 
  CHANGES:                - improved light filtering
  CHANGES:                - preparation of light list for new rte interface i390
  CHANGES:                --- Added comments ---  brunnm [Feb 28, 2014 3:04:51 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.182 2014/02/11 17:24:55CET Manz, Alexander (uidv8777) 
  CHANGES:                Fixes:
  CHANGES:                 - improved selection of region for tracking
  CHANGES:                 - minor bug fixes for tracking 
  CHANGES:                
  CHANGES:                Update in visu:
  CHANGES:                 - new pair visualization
  CHANGES:                 - new features to disable horizon, ROI and vehicle data visu parts
  CHANGES:                 - tunnel visu moved to be part of environment
  CHANGES:                 - minor restructuring of hotkeys
  CHANGES:                --- Added comments ---  uidv8777 [Feb 11, 2014 5:24:56 PM CET]
  CHANGES:                Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGES:                Revision 1.181 2014/02/07 10:18:25CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed previous check-in
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2014 10:18:25 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.180 2014/02/07 09:59:47CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added restrictions (light/track reduction by ~30%; 1 icon less)
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2014 9:59:48 AM CET]
  CHANGES:                Change Package : 207432:29 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.179 2014/02/05 15:26:50CET Brunn, Marcus (brunnm) 
  CHANGES:                removed LED segmentation
  CHANGES:                --- Added comments ---  brunnm [Feb 5, 2014 3:26:51 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.178 2014/01/16 11:35:44CET Manz, Alexander (uidv8777) 
  CHANGES:                Update:
  CHANGES:                 - added some improvements for trucklights-on-highway pair tracking
  CHANGES:                 - changed pairing parameter for trucklights-on-highway pair tracking
  CHANGES:                 - removed switch between night and day visualization
  CHANGES:                
  CHANGES:                Minor fixes:
  CHANGES:                 - fixed some tabs
  CHANGES:                --- Added comments ---  uidv8777 [Jan 16, 2014 11:35:44 AM CET]
  CHANGES:                Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGES:                Revision 1.177 2014/01/10 18:33:45CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:46 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.176 2013/12/18 15:18:02CET Schillinger, Patrick (uidv8776) 
  CHANGES:                introduction of new HighwayOncomingTruckLight detection
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:03 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.175 2013/11/21 17:53:54CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:54 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.174.1.8 2013/11/21 14:15:25CET Manz, Alexander (uidv8777) 
  CHANGES:                Fix: 
  CHANGES:                 - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGES:                 - region selection for tracking fixed
  CHANGES:                 - minor bug in pseudo census code generation fixed
  CHANGES:                Updates:
  CHANGES:                 - some minor cosmetic changes in tracking files
  CHANGES:                 - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGES:                --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:25 PM CET]
  CHANGES:                Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGES:                Revision 1.174.1.7 2013/11/14 09:46:57CET Brunn, Marcus (brunnm) 
  CHANGES:                hla segmentation: clean up of region parameters
  CHANGES:                --- Added comments ---  brunnm [Nov 14, 2013 9:46:57 AM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174.1.6 2013/10/25 15:17:26CEST Brunn, Marcus (brunnm) 
  CHANGES:                improved detection of preceding cars (reduced thresholds for birth of red lights)
  CHANGES:                --- Added comments ---  brunnm [Oct 25, 2013 3:17:26 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174.1.5 2013/10/23 16:40:35CEST Brunn, Marcus (brunnm) 
  CHANGES:                fixed pairing:
  CHANGES:                updated minRedChromaticity, maxRedChromaticity
  CHANGES:                --- Added comments ---  brunnm [Oct 23, 2013 4:40:36 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174.1.4 2013/10/23 07:57:32CEST Brunn, Marcus (brunnm) 
  CHANGES:                changed segmentation line clustering parameter for twilight
  CHANGES:                --- Added comments ---  brunnm [Oct 23, 2013 7:57:32 AM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174.1.3 2013/10/21 16:00:26CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced preprocessing function: HLASegPreProcImage()
  CHANGES:                --- Added comments ---  brunnm [Oct 21, 2013 4:00:26 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174.1.2 2013/10/21 08:36:25CEST Brunn, Marcus (brunnm) 
  CHANGES:                - clean up
  CHANGES:                - introduced adaptive thresholds for level 4 and 5
  CHANGES:                --- Added comments ---  brunnm [Oct 21, 2013 8:36:25 AM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174.1.1 2013/10/18 13:27:35CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:35 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.174 2013/08/05 20:41:27CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:27 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.173 2013/04/19 14:47:15CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Changed city parameter from cm to m
  CHANGES:                --- Added comments ---  uidv8778 [Apr 19, 2013 2:47:16 PM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.172 2013/04/12 12:45:08CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Took more coding parameters into use
  CHANGES:                --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:09 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.171 2013/04/12 10:54:51CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Implemented BMW Codierparameter for city and traffic style
  CHANGES:                --- Added comments ---  uidv8778 [Apr 12, 2013 10:54:52 AM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.170 2013/04/09 16:10:42CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Cleaned-up no longer needed struct (tunnel)
  CHANGES:                --- Added comments ---  uidv7867 [Apr 9, 2013 4:10:43 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.169 2013/03/27 12:56:17CET Schillinger, Patrick (uidv8776) 
  CHANGES:                magic numbers of highway oncoming car detection are now paramaters in hlaAnalysisParameters
  CHANGES:                --- Added comments ---  uidv8776 [Mar 27, 2013 12:56:17 PM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.168 2013/03/15 12:56:43CET Manz, Alexander (uidv8777) 
  CHANGES:                Tunnel detection update includes ability to work with parameter and create measFreezes
  CHANGES:                --- Added comments ---  uidv8777 [Mar 15, 2013 12:56:44 PM CET]
  CHANGES:                Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGES:                Revision 1.167 2013/03/08 15:38:31CET Fischer, Alexander (uidv8778) 
  CHANGES:                First version of ambient city detection
  CHANGES:                --- Added comments ---  uidv8778 [Mar 8, 2013 3:38:32 PM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.166 2013/02/28 11:06:40CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed MISRA error
  CHANGES:                --- Added comments ---  uidv7867 [Feb 28, 2013 11:06:41 AM CET]
  CHANGES:                Change Package : 167173:25 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.165 2013/02/26 09:19:39CET Fischer, Alexander (uidv8778) 
  CHANGES:                Highway detection over high speed implemented
  CHANGES:                --- Added comments ---  uidv8778 [Feb 26, 2013 9:19:39 AM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.164 2013/02/12 15:08:41CET Fischer, Alexander (uidv8778) 
  CHANGES:                Optimization to avoid truck lights to be detected as SL
  CHANGES:                --- Added comments ---  uidv8778 [Feb 12, 2013 3:08:41 PM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.163 2013/01/24 14:19:23CET Zechner, Stefan (uidt9253) 
  CHANGES:                - minimum time of 7 frames where sticky state is kept avoids flickering of vehicle detected/lost/detected in icon bypass scenarios
  CHANGES:                --- Added comments ---  uidt9253 [Jan 24, 2013 2:19:24 PM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.162 2013/01/22 12:06:34CET Fischer, Alexander (uidv8778) 
  CHANGES:                HLA-R Internal Highway Decision
**************************************************************************** */

/* ~CodeReview ~ID:28187f9f9ecd5b1755982f09d3b5bc89 ~Reviewer:CW01\uidv0772 ~Date:16.07.2012 ~Priority:3 ~Comment:(general) assigning signed values to unsigned variables.  (e.g. assign 3 to an uint8)*/
    
/*****************************************************************************
  INCLUDES
*****************************************************************************/
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


/*****************************************************************************
  VARIABLES 
*****************************************************************************/

const HLABrightnessParameters_t hlaBrightnessParameters = {
  /* SubImage */
  {
    /* EndRow1_factor */ 0.666f,
    /* xw_EndRow2_m */ 65.0f,
    /* xw_EndRow3_m */ 20.0f,
    /* xw_EndRow4_m */ 12.0f
  },
  /* Twilight_1 */
  {
    /* NumberOfUsedPosCriteria */ 1,
    /* NumberOfUsedNegCriteria */ 2,

    /* positive (in) */
    {
      {
        /* AboveRoi_MinInt_lux  */ 400.0f,
        /* AboveRoi_MaxInt_lux  */ 400.0f,
        /* Roi_MeanIntF_lux */ 400.0f
      }
    },

    /* negative (out) */
    {
      /* normal situation */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ 800.0f,
        /* Roi_MeanIntF_lux */ 80.0f
      },
      /* very bright sky */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ 1000.0f,
        /* Roi_MeanIntF_lux */ 10.0f
      }
    },   
    
    /* Turbo */
    {
      /* Neg2Pos_MinInt_lux */  HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
      /* Neg2Pos_MaxInt_lux */  50.0f,
      /* Pos2Neg_MinInt_lux */  1000.0f,
      /* Pos2Neg_MaxInt_lux */  HLA_BRIGHTNESS_MAX_INTENSITY_LUX,

      /* high intensity (coming from night) -> increase filter speed */
      /* low intensity (coming from day)    -> increase filter speed */
      /* MaxFactor */ 5.0f
    },
    /* Radius */
    {
      /* Radius0_m */   150.0f, 
      /* Radius1_m */   300.0f,
      /* Factor0_ddist */ 0.3f
    },
    /* MinDistTime */
    {
      /* MinTimePos_s */   5.0f,
      /* MinDistPos_m */ 150.0f,
      /* MinTimeNeg_s */   3.0f,
      /* MinDistNeg_m */ 100.0f,
      /* MinTimePosInit_s */ 10.0f,
      /* MinTimeNegInit_s */ 10.0f,
      /* MaxTime2InitState_s */ 60.0f 
    }
  },
  /* Twilight_2 */
  {
    /* NumberOfUsedPosCriteria */ 1,
    /* NumberOfUsedNegCriteria */ 1,

    /* positive (in) */
    {
      {
        /* AboveRoi_MinInt_lux  */ 25.0f,
        /* AboveRoi_MaxInt_lux  */ 25.0f,
        /* Roi_MeanIntF_lux */ 25.0f
      }
    },

    /* negative (out) */
    {
      /* normal situation */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ 35.0f,
        /* Roi_MeanIntF_lux */ 2.0f
      },
      /* very bright sky */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* Roi_MeanIntF_lux */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX
      }
    },    
    
    /* Turbo */
    {
      /* Neg2Pos_MinInt_lux */  HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
      /* Neg2Pos_MaxInt_lux */  12.5f,
      /* Pos2Neg_MinInt_lux */  70.0f,
      /* Pos2Neg_MaxInt_lux */  HLA_BRIGHTNESS_MAX_INTENSITY_LUX,

      /* high intensity (coming from night) -> increase filter speed */
      /* low intensity (coming from day)    -> increase filter speed */
      /* MaxFactor */ 5.0f
    },
    /* Radius */
    {
      /* Radius0_m */   150.0f, 
      /* Radius1_m */   300.0f,
      /* Factor0_ddist */ 0.3f
    },
    /* MinDistTime */
    {
      /* MinTimePos_s */   5.0f,
      /* MinDistPos_m */ 150.0f,
      /* MinTimeNeg_s */   3.0f,
      /* MinDistNeg_m */ 100.0f,
      /* MinTimePosInit_s */ 10.0f,
      /* MinTimeNegInit_s */  3.0f,
      /* MaxTime2InitState_s */ 60.0f 
    }
  },
  /* Twilight_3 */
  {
    /* NumberOfUsedPosCriteria */ 1,
    /* NumberOfUsedNegCriteria */ 1,

    /* positive (in) */
    {
      {
        /* AboveRoi_MinInt_lux  */ 15.0f,
        /* AboveRoi_MaxInt_lux  */ 15.0f,
        /* Roi_MeanIntF_lux */ 15.0f
      }
    },

    /* negative (out) */
    {
      /* normal situation */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ 20.0f,
        /* Roi_MeanIntF_lux */ 1.0f
      },
      /* very bright sky */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* Roi_MeanIntF_lux */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX
      }
    },

    /* Turbo */
    {
      /* Neg2Pos_MinInt_lux */  HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
      /* Neg2Pos_MaxInt_lux */  7.5f,
      /* Pos2Neg_MinInt_lux */  40.0f,
      /* Pos2Neg_MaxInt_lux */  HLA_BRIGHTNESS_MAX_INTENSITY_LUX,

      /* high intensity (coming from night) -> increase filter speed */
      /* low intensity (coming from day)    -> increase filter speed */
      /* MaxFactor */ 5.0f
    },
    /* Radius */
    {
      /* Radius0_m */   150.0f, 
      /* Radius1_m */   300.0f,
      /* Factor0_ddist */ 0.3f
    },
    /* MinDistTime */
    {
      /* MinTimePos_s */   5.0f,
      /* MinDistPos_m */ 150.0f,
      /* MinTimeNeg_s */   3.0f,
      /* MinDistNeg_m */ 100.0f,
      /* MinTimePosInit_s */ 10.0f,
      /* MinTimeNegInit_s */ 3.0f,
      /* MaxTime2InitState_s */ 60.0f 
    }
  },
  /* Night */
  {
    /* NumberOfUsedPosCriteria */ 1,
    /* NumberOfUsedNegCriteria */ 2,

    /* positive (in) */
    {
      {
        /* AboveRoi_MinInt_lux  */ 1.0f,
        /* AboveRoi_MaxInt_lux  */ 20.0f,
        /* Roi_MeanIntF_lux */ 0.7f
      }
    },

    /* negative (out) */
    {
      /* normal situation */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ 3.0f,
        /* Roi_MeanIntF_lux */ 1.5f
      },
      /* very bright sky */
      {
        /* AboveRoi_MinInt_lux  */ HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
        /* AboveRoi_MaxInt_lux  */ 25.0f,
        /* Roi_MeanIntF_lux */ 1.3f
      }
    },

    /* Turbo */
    {
      /* Neg2Pos_MinInt_lux */  HLA_BRIGHTNESS_MIN_INTENSITY_LUX,
      /* Neg2Pos_MaxInt_lux */  1.5f,
      /* Pos2Neg_MinInt_lux */  30.0f,
      /* Pos2Neg_MaxInt_lux */  HLA_BRIGHTNESS_MAX_INTENSITY_LUX,

      /* high intensity (coming from night) -> increase filter speed */
      /* low intensity (coming from day)    -> increase filter speed */
      /* MaxFactor */ 5.0f
    },
    /* Radius */
    {
      /* Radius0_m */   150.0f, 
      /* Radius1_m */   300.0f,
      /* Factor0_ddist */ 0.3f
    },
    /* MinDistTime */
    {
      /* MinTimePos_s */   5.0f,
      /* MinDistPos_m */ 150.0f,
      /* MinTimeNeg_s */   3.0f,
      /* MinDistNeg_m */ 100.0f,
      /* MinTimePosInit_s */ 10.0f,
      /* MinTimeNegInit_s */ 3.0f,
      /* MaxTime2InitState_s */ 60.0f
    }
  },
  /* MeanIntFMaxIndex */ 17
};

const HLA_t_AnalysisParameters hlaAnalysisParameters = {
  /* tooBrightMinInt = */ 3700.0f,

  /* aboveRoiTolerance_pix = */ 10,

  /* contraMotionMinDist2FOE = */ 100.0f,
  /* contraMotionMinDisplacement = */ 6.0f,
  /* contraMotionLowerAlphaThresh = */ 0.0f,
  /* contraMotionUpperAlphaThresh = */ 0.5f,
  /* contraMotionMinIntensityLux = */ 1000.f,

  /* dynamicMotionMaxInt = */ 1000.0f,

  /* closeReflectorMaxDistRange = */ 10000.0f,
  /* closeReflectorMaxStaticDist = */ 20000.0f,
  /* closeReflectorMaxIntensity = */ 9000.0f,
  /* closeReflectorMinTrackTime = */ 3,
  /* closeReflectorStraightRoadMinRadius = */ 2000.0f,
  /* closeReflectorMinDist2FOE = */ 100,

  /* staticHighDeltaYThresholdPos = */ -0.1f,
  /* staticHighDeltaYThresholdNeg = */  0.1f,

  /* centerBrightLeftRightRad = */ 0.06f,
  /* centerBrightTopRad = */ 0.036f,
  /* centerBrightBottomRad = */ 0.048f,
  /* centerBrightMaxInt = */ 1400.0f,

  /* lateralBrightMinInt = */ 1800.0f,
  /* lateralBrightMaxInt = */ 5000.0f,
  /* lateralBrightSlopeInt = */ 9.3f,

  /* extremeBrightMaxInt = */ 20000.0f,
  /* extremeBrightMinInt = */ 5000.0f,

  /* highwayBrightMinInt = */ 2500.0f,
  /* highwayBrightMinTrackTime = */ 2.0f,
  /* highwayBrightMinClassResult = */ -20,

  /* highwayBrightMinIntTruckLights = */ 25.0f,      /*50.0f,*/
  /* highwayBrightMinTrackTimeTruckLights = */ 5.0f, /*10.0f,*/
  /* highwayBrightMinTrackDeltaX = */ 2.0f,

  /*****************************************************************/
  /* hlaChainParam = */{
                      /* MaxDistToLine_UD = */ 1500.0f,
                      /* CoeffMaxInt = */ 0.4f,
                      /* MaxDistRatio = */ 16.0f, /* 4*4 */
                      /* MaxDist2_FarHor = */ 6400.0f,/* 80*80*/
                      /* MaxDist2_CloseHor = */ 6400.0f,/* 80*80*/
                      /* MinDist_X_FarHor = */ 80,
                      /* MinDist_Y_FarHor = */ 35,
                      /* MinDist_X_CloseHor = */ 80,
                      /* MinDist_Y_CloseHor = */ 35,
                      /* MinDistUnderHor = */ 25,
                      /* MinDistAboveHor = */ 0,
                      /* maxDiffSize = */ 6,
                      /* maxTrackTimeDiff = */ 40,
                      /* minNbOfTrackInChain = */ 2u,
                      /* Conf_max = */ 20u,
                      /* Conf_min = */ 0u,
                      /* Conf_stepPos = */ 6u,
                      /* Conf_stepNeg = */ 2u,
                      /* Conf_threshPos = */ 15u,
                      /* Conf_threshNeg = */ 5u
                      },
  /*****************************************************************/

  /*hlaStreetLampsParam = */{
  /* LowPassFilterZeros[SL_LP_FILTER_ORDER = 6] = */{ 0.00000863284f,   
                            0.00004316421f,   
                            0.00008632843f,   
                            0.00008632843f, 
                            0.00004316421f,   
                            0.00000863284f},
  /* LowPassFilterPoles[SL_LP_FILTER_ORDER = 6] = */{ 1.0f,  
                            -4.5736813538f,   
                            8.46833018477f,  
                            -7.9290925293f, 
                            3.75269237178f,  
                            -0.7179724223f},
  /* ThreshFarSL = */ 200.0f,
  /* ThreshMiddleSL = */ 85.0f,
  /* SL_Decision_Far = */{/* Thresh_Max_Lux = */ 45000.0f, /* Lux */
                          /* Thresh_Max_Var = */ 15000.0f, /* Lux */
                          /* Thresh_Min_Delta_Lux = */ 0.8f,
                          /* Thresh_Min_Extremum = */ 150.0f, /* Lux */
                          /* Thresh_Max_Extremum = */ 3000.0f,
                          /* SL_MaxWidth = */ 8,
                          /* SL_MaxHeight = */8,
                          /* Thresh_Min_Zw100 = */ 700.0f
                        },
  /* SL_Decision_Middle = */{/* Thresh_Max_Lux = */ 45000.0f, /* Lux */
                            /* Thresh_Max_Var = */ 20000.0f, /* Lux */
                            /* Thresh_Min_Delta_Lux = */ 0.40f,
                            /* Thresh_Min_Extremum = */ 800.0f, /* Lux */
                            /* Thresh_Max_Extremum = */ 7500.0f,
                            /* SL_MaxWidth = */ 24,
                            /* SL_MaxHeight = */20,
                            /* Thresh_Min_Zw100 = */ 400.0f
                            },
  /* SL_Decision_Close = */{/* Thresh_Max_Lux = */ 60000.0f, /* Lux */
                            /* Thresh_Max_Var = */ 20000.0f, /* Lux */
                            /* Thresh_Min_Delta_Lux = */ 0.40f,
                            /* Thresh_Min_Extremum = */ 800.0f, /* Lux */
                            /* Thresh_Max_Extremum = */ 7500.0f,
                            /* SL_MaxWidth = */ 40,
                            /* SL_MaxHeight = */30,
                            /* Thresh_Min_Zw100 = */ 300.0f
                            },
  /* Thresh_Min_Time_Diff = */ 5, /* Frame */
  /* Thresh_Max_Time_Diff = */ 40, /* Frame */
  /* Thresh_Max_Time_Diff2 = */ 40,
  /* Thresh_Max_DeltaXw100 = */ 10000.0f,
  /* Thresh_Max_DeltaYw100 = */ 2000.0f,
  /* Thresh_Max_DeltaZw100 = */ 1000.0f,
  /* ThreshSLConfNeg = */ -3,
  /* ThreshSLConfPos = */ 5,
  /* SLConf_Min = */ -5,
  /* SLConf_Max = */ 15,
  /* MinSpeed_Direction = */ 1.0f,
  /* minSpeed = */ -0.5f,
  /* default_distance = */ 50.0f,  /* in [m] */
  /* yawRateFilterConstant = */ 0.9f, /* [0.0 .. 1.0] */
  /* minYawRate = */ 0.001f, /* in [rad] */
  /* minVelocity = */ 0.1f, /* in [m/s] */
  /* defaultRadius = */ 100000.0f, /* in [m] */
  /* minRadius = */ 400.0f, /* in [m] */
  /* maxCentralAngle = */ 45.0f, /* in [deg] */
  /* minPixAboveHorizonEx = */ 10,   /* in [pix] */
  /* maxTrackTime = */ 10, /* [0 .. 64k] */
  /* maxOuterStreetLampCount = */ 10, /* [0 .. 255] */
  /* maxDistStreetLamp = */ 250.0f,
  /* minHeightStreetLamp = */ 3.0f,
  /*                                       2D_OK  2D_IDLE  2D_BAD   */
  /* ArrayConfPos[18] = */ { /* 3D_OK   */   3,      1,      0,
                             /* 3D_IDLE */   1,      0,     -1,
                             /* 3D_BAD  */   0,     -1,     -3,

                                /* same table for dynamic tracker class */
                                            -1,      0,     -1,
                                            -1,      0,     -1,
                                            -1,     -1,     -3  },

  /*                                       2D_OK  2D_IDLE  2D_BAD   */
  /* ArrayConfNeg[18] = */ { /* 3D_OK   */   3,      1,      1,
                             /* 3D_IDLE */   1,      0,      0,
                             /* 3D_BAD  */   0,     -1,     -3,

                                /* same table for dynamic tracker class */
                                             0,      0,     -1,
                                             0,      0,     -1,
                                             0,     -1,     -3  }
                          },
  /*****************************************************************/

  /* RedLight */
  {
    /* minRed_pos */ 0.4f,//0.50f, //0.62f, 
    /* maxGreen_pos */ 0.4f, //0.335f,
    /* maxBlue_pos */ 0.4f, //0.20f,
    /* minInt */ 7.0f,

    /* minRed_neg */ 0.36f, 
    /* maxGreen_neg */ 0.45f,
    /* maxBlueneg */ 0.45f,

    /* minRed_City */ 0.62f,
    /* maxGreen_City */ 0.335f,
    /* maxBlue_City */ 0.20f,
    /* minInt_City */ 7.0f
  },
  /*****************************************************************/

  /* HLA_t_AnalysisTTB */
  {
    /* ttbBorder */ 10,
    /* maxTTB */ 10.0f,
    /* ttbLowPassFactor */ 0.6f
  },
  /*****************************************************************/

  /* HLA_t_AnalysisIcon */
  {
    /* classResultSumMin */ -48,
    /* classResultSumMax */ 200,

    /* lrf_outputOffset_XenonLED */ 0.4f,
    /* lrf_outputOffset_Halogen */ 0.4f,
    /* lrf_outputOffset_RedLight */ 0.4f,
    /* lrf_outputOffset_CityLight */ 0.0f,

    /* crtOncomingMin */ 1.89f,
    /* crtOncomingSizeMin */ 0.0f,
    /* crtOncomingSizeMax */ 2.1f,
    /* crtOncomingSizeC0 */ 2.1f,
    /* crtOncomingSizeC1 */ -0.21f,
    /* crtOncomingBrightnessMin */ 0.0f,
    /* crtOncomingBrightnessMax */ 4.2f,
    /* crtOncomingBrightnessC0 */ 4.2f,
    /* crtOncomingBrightnessC1 */ -0.00084f,
    /* crtOncomingPositionMin */ 0.0f,
    /* crtOncomingPositionMax */ 5.6f,
    /* crtOncomingPositionC0 */ 0.0f,
    /* crtOncomingPositionC1 */ 5.6f,

    /* crtAheadMin */ 2.59f,
    /* crtAheadSizeMin */ 0.0f,
    /* crtAheadSizeMax */ 2.1f,
    /* crtAheadSizeC0 */ 2.1f,
    /* crtAheadSizeC1 */ -0.35f,
    /* crtAheadBrightnessMin */ 0.0f,
    /* crtAheadBrightnessMax */ 4.2f,
    /* crtAheadBrightnessC0 */ 4.2f,
    /* crtAheadBrightnessC1 */ -0.0084f,
    /* crtAheadPositionMin */ 0.0f,
    /* crtAheadPositionMax */ 5.6f,
    /* crtAheadPositionC0 */ 0.0f,
    /* crtAheadPositionC1 */ 5.6f,

    /* stickyMinTime */ 7,
  },
  /*****************************************************************/
};

const HLA_t_IdentificationParameters hlaIdentParam = {
  /* contraMoverNegativeBound = */ -20,
  /* contraMoverPositiveBound = */ 20,
  /* contraMoverConfStepSize = */ 5,
  /* dynamicMotionNegativeBound = */ -10,
  /* dynamicMotionPositiveBound = */ 10,
  /* dynamicMotionConfStepSize = */ 5,
  /* tooBrightNegativeBound = */ 0,
  /* tooBrightPositiveBound = */ 31,
  /* tooBrightConfStepSize = */ 31,
  /* closeReflectorNegativeBound = */ -31,
  /* closeReflectorPositiveBound = */ 31,
  /* oncomingPairNegativeBound = */ -20,
  /* oncomingPairPositiveBound = */ 20,
  /* oncomingPairConfStepSize = */ 5,
  /* centerBrightNegativeBound = */ 0,
  /* centerBrightPositiveBound = */ 31,
  /* centerBrightConfStepSize = */ 31,
  /* lateralBrightNegativeBound = */ 0,
  /* lateralBrightPositiveBound = */ 31,
  /* lateralBrightConfStepSize = */ 31,
  /* otherColorNegativeBound = */ -5,
  /* otherColorPositiveBound = */ 5,
  /* otherColorConfStepSizeNormal = */ 1,
  /* otherColorConfStepSizeFast = */ 3,
  /* otherColorConfStepSizeNeutral = */ 2,
  /* whiteOrRedNegativeBound = */ -5,
  /* whiteOrRedPositiveBound = */ 5,
  /* whiteOrRedConfStepSize = */ 1,
  /* pulsedLightNegativeBound = */ -4,
  /* pulsedLightPositiveBound = */ 5,
  /* pulsedLightConfStepSize = */ 1,
  /* staticHighNegativeBound = */ 4,
  /* staticHighPositiveBound = */ 5,
  /* staticHighConfStepSize = */ 1,
};

const HLA_t_HighwayParameters hlaHighwayParams = {
  /* FilterTracksMinDeltaX = */ 75,
  /* FilterTracksMinDeltaY = */ 0,
  /* FilterTracksMinSpeed = */ 9.72f,/* 35 [km/h] */
  /* FilterTracksMinTrackTime = */ 15,
  /* FilterTracksCurvature = */ 0.002f, /* 1/500 [m/°] */
  /* ThreshDividedRdwayXwUp = */ 15.0f,
  /* ThreshDividedRdwayYwUp = */ 6.1f,
  /* ThreshDividedRdwayZwUp = */ 0.7f,
  /* ThreshDividedRdwayXwDown = */ 15.0f,
  /* ThreshDividedRdwayYwDown = */ 5.4f,
  /* ThreshDividedRdwayZwDown = */ 0.7f,
  /* ThreshCurvatureDivided = */ 0.001428f, /* 1/700 [m/°] */
  /* ThreshNormalRdwayXwDown = */ 15.0f,
  /* ThreshNormalRdwayYwDown = */ 3.6f,
  /* ThreshNormalRdwayZwDown = */ 0.7f,
  /* ThreshNormalRdwayXwUp = */ 15.0f,
  /* ThreshNormalRdwayYwUp = */ 3.8f,
  /* ThreshNormalRdwayZwUp = */ 0.7f,
  /* HighwayThreshSpeedUp = */ 22.22f,/* 80 [km/h]*/ /* replaced with CP */
  /* HighwayThreshSpeedDown = */ 18.05f,/* 65 [km/h] */
  /* HighwayThreshCurvatureUp = */   0.002f, /* 1/500 [m/°] */
  /* HighwayThreshCurvatureDown = */ 0.000333f,/* 1/3000 [°/m]*/
  /* MinDeathAreaCoeff = */ 0.5f,
  /* ThreshPrematureCount = */ 5,   /* replaced with CP */
  /* OcclusionDelay = */ 0.5f,
  /* ThreshPreDeathCoeff = */ 4.0f,
  /* StepConfDvdRdway = */  0.12f,
  /* StepConfCtryRdway = */ 0.5f,
  /* StepConfOccl = */ 0.0625f,
  /* StepConfOcclDtcd = */ 0.15f, /* replaced with CP */
  /* StepConfHway = */ 0.078125f,
  /* MinConf = */ 0,
  /* MaxConf = */ 1.0f,
  /* TreshConfDividedRdway = */ 0.75f, /* replaced with CP */
  /* TreshConfNormalRdway = */ 0.25f,
  /* ThreshDistToLastOncoming = */ 90000.0f, /* [m] */
  /* ThreshDistHwayDction = */ 200.0f,
  /* ThreshCurvatureExit = */ 0.003f,/* 0.17 [°/m] */
  /* ThreshDistExit = */ 130.0f,
  /* ThreshYawIntegrate = */ 0.7f, /* 40° */
  /* CurvMinSpeed = */ 0.1f,
  /* MaybeHwayConfOccl = */ 0.4f,
  /* MaybeHwayConfRdwayType = */ 0.5f,
  /* minConfTrans = */ 0.8f,
  /* minSpeedThresh = */ 6.39f, /* 23 [km/h] */
  /* HighwaySpeedThreshHigh = */ 38.89f, /* 140 [km/h] */ /* replaced with CP */
  /* HighwaySpeedThreshLow = */ 33.33f, /* 120 [km/h] */ /* replaced with CP */
  /* ThreshDistHwaySpeedDction = */ 400.0f, /* [m] */ /* replaced with CP */
  /* HighwaySpeedExitThresh = */ 30.55f /* 110 [km/h] */
};

const HLA_t_Tracking3DParameters hlaTracking3DParameters = {

  /* paramCali */
  {
    /* errCalYawMax   = */ CML_Deg2Rad(0.075f),
    /* errCalPitchMax = */ CML_Deg2Rad(0.1f),
    /* errCalRollMax  = */ CML_Deg2Rad(0.075f),
    /* errCalYawMin   = */ CML_Deg2Rad(0.075f),
    /* errCalPitchMin = */ CML_Deg2Rad(0.1f),
    /* errCalRollMin  = */ CML_Deg2Rad(0.075f),
    /* minNumFullEgoTracksToUpdateOnlineCaliOdometer = */ 0,
    /* maxOdometerOnLineCaliM = */ 3000000000.0f    
  },
  /* paramEgomotion */
  {
    /* errMaxYawRate = */ CML_Deg2Rad(1.0f),
    /* errEgoPitchRadian = */ CML_Deg2Rad(0.75f),
    /* errEgoRollRadian  = */ CML_Deg2Rad(0.35f),
    /* extremeErrYawRate = */  CML_Deg2Rad(1.0f),
    /* extremeErrEgoPitchRadian = */ CML_Deg2Rad(1.0f),
    /* extremeErrEgoRollRadian  = */ CML_Deg2Rad(0.35f),
  },
  /* paramStaticTracker */
  {
    /* minTrackDist = */ 8.0f,
    /* initDistanceStatic = */ 10000.0f,
    /* chi2_1_StaticRobust = */ 2.705543f,
    /* maxInverseDepth = */ 1.0f,
    /* maxCycleLostTimeStatic = */ 5
  },
  /* paramDynamicTracker */
  {
    /* initDistanceDynamic = */ 100.0f,
    /* codd_init = */ 0.5f,
    /* minDistDynamic = */ 3.0f,
    /* maxDistDynamic = */ 10000.0f,
    /* errXWVelocityInit = */ 55.0f,
    /* errYWVelocityInit = */ 40.0f,
    /* errXWVelocityProc = */ 5.0f,
    /* errYWVelocityProc = */ 0.5f,
    /* maxErrHorizontalInPix = */ 70,
    /* maxErrVerticalInPix = */ 40,
    /* maxRMSE = */ 5.0f
  },
  /* paramMeasurement */
  {
    /* errMeasPixelMin = */ 2,
    /* errMeasPixelMax = */ 40,
  },
  /* paramMatching */
  {
    /* errMeasIntensityGreyLevel = */ 200.0f,
    /* factorMaxIntDecrease = */ (1.0f/50.0f),
    /* constMaxIntFilter = */ 0.5f,
    /* maxEuclDistAssocTrack2Light = */ 50.0f,
    /* threshHammingAssocDistance = */ {5,10,15,20},
    /* penaltyAssocDistance = */       {0.0f, 1.0f, 2.5f, 5.0f},
    /* threshHammingPatternUpdate = */ 4,
    /* maxTimeWithoutPatternUpdate = */ 20,
    /* maxTimeWithoutRGBUpdate = */ 20
  },
  /* paramAnalysis */
  {
    /* minNumFrameFromUnknownToStatic = */ 5,
    /* minNumFrameFromUnknownToDynamic = */ 2,
    /* minNumFrameFromStaticToUnknown = */ 2,
    /* minNumFrameFromDynamicToUnknown = */ 50,
    /* minRatioStaticDepthConvergence = */ 0.5f,
    /* minDwForLonelyStaticTrack = */ (1.0f/20.0f),  /* inverse of 20 meters */
    /* minSpeedToAddSlamFeatures = */ (5.0f/3.6f),
    /* minSpeedToKeepSlamFeatures = */ (1.0f/3.6f),
    /* numCyclesDlpLt = */ 10,
    /* h_dlp_tk1 = */ 0.2000f,
    /* h_dlp_tk2 = */ 0.1429f,
    /* hx_dlp_tkn = */ 0.1429f,
    /* hy_dlp_tkn = */ 0.1071f
  },
  /* paramBirth */
  {
    /* ~CodeReview ~ID:91d40f65c7c976a4e50e3a25cafcf6eb ~Reviewer:CW01\uidv0772 ~Date:16.07.2012 ~Priority:3 ~Comment:assign int to float */
    /* minLuxIntensity4newTrack = */ 120,
    /* minLuxIntensity4newTrackIsolatedLight = */ 100,
    /* minLuxIntensity4newRedTrackIsolatedLight = */ 20,
    /* minR = */ 0.4f,
    /* maxG = */ 0.4f,
    /* maxB = */ 0.3f,
    /* MaxNumberOfNewTracks = */ 50
  },
  /* paramDeath */
  {
    /* maxCyclesTrackLost = */ 5,
    /* maxCyclesPairLost = */ 2,
    /* maxCyclesTrackLostInPair = */ 20,
    /* minRelVelToUseMaxCyclePair = */ (-20.0f/3.6f),
    /* pixelMarginOutOfRoi = */ 30
  },
  /* paramHotPixel */
  {
    /* HotPixelMinTrackAge = */ 100,
    /* HotPixelMinConsequentAssoc = */ 100,
    /* HotPixelValidaionCycle = */ 1000,   
    /* HotPixelValidaionRate = */ 0.7f,
    /* minSpeedAllCurves = */ 8.3333f,
    /* minSpeedCurvyRoad = */ (8.3333f/3.0f),
    /* minYawRateCurvyRoad = */ 0.035f
  },
  /* paramPair */
  {
    /* maxVehicleLength = */ 3.0f,
    /* paramPairOncoming */
    {
      /* minDistStart = */ 15.0f,
      /* minDistEnd = */ 4.0f,
      /* maxDist = */ 450.0f,
      /* minHeight = */ 0.50f,
      /* maxHeight = */ 1.2f,
      /* minInterDist = */ 1.0f,
      /* maxInterDist = */ 2.4f,
      /* minIcst = */                    28.0f,
      /* maxIcst = */                   400.0f,
      /* minRedChromaticity = */          0.25f, /*0.2f,*/
      /* maxRedChromaticity = */          0.35f, /*0.3f,*/
      /* minGreenChromaticity = */        0.25f, /*0.4f,*/
      /* maxGreenChromaticity = */        0.35f, /*0.5f,*/
      /* maxRollStart = */ CML_Deg2Rad(5.0f),
      /* maxRollEnd = */ CML_Deg2Rad(10.0f),
      /* minStartSpeed = */   (-200.0f/3.6f),
      /* maxStartSpeed = */   (30.0f/3.6f),
      /* minStartYaw = */  CML_Deg2Rad(-40.0f),
      /* maxStartYaw = */  CML_Deg2Rad(40.0f),
      /* errMeasRedChromaticity = */  0.2f,
      /* errMeasGreenChromaticity = */  0.2f,
      /* errMeasGreyValue = */  200,
      /* errMeasPositionVerticalPixel = */ 2.0f,
      /* errMeasPositionHorizontalPixel = */ 2.0f,
      /* maxAcc = */ (100.0f/3.6f)/6.0f,
      /* maxYawRate = */ CML_Deg2Rad(50.0f),
      /* maxHeightSpeed = */ (0.02f/0.06f),
      /* maxDeltaHeightSpeed = */ 0.17f,
      /* minSpeedForYawEst = */ (2.0f/3.6f)
    },
    /* paramPairAhead */
    {
      /* minDistStart = */ 15.0f,
      /* minDistEnd = */ 4.0f,
      /* maxDist = */ 450.0f,
      /* minHeight = */ 0.35f,
      /* maxHeight = */ 1.5f,
      /* minInterDist = */ 0.6f,
      /* maxInterDist = */ 2.2f,
      /* minIcst = */                     3.0f,
      /* maxIcst = */                    15.0f,
      /* minRedChromaticity = */          0.4f,             //0.3f,   //0.62f,
      /* maxRedChromaticity = */          1.0f,   //0.55f,  //0.7f,   //1.0f,
      /* minGreenChromaticity = */        0.00f,  //0.2f,   //0.0f,
      /* maxGreenChromaticity = */        0.30f,            //0.335f,
      /* maxRollStart = */ CML_Deg2Rad(5.0f),
      /* maxRollEnd = */ CML_Deg2Rad(10.0f),
      /* minStartSpeed = */   (-30.0f/3.6f),
      /* maxStartSpeed = */   (230.0f/3.6f),
      /* minStartYaw = */  CML_Deg2Rad(-40.0f),
      /* maxStartYaw = */  CML_Deg2Rad(40.0f),
      /* errMeasRedChromaticity = */  0.2f,
      /* errMeasGreenChromaticity = */  0.2f,
      /* errMeasGreyValue = */  60,
      /* errMeasPositionVerticalPixel = */ 2.0f,
      /* errMeasPositionHorizontalPixel = */ 2.0f,
      /* maxAcc = */ (100.0f/3.6f)/6.0f,
      /* maxYawRate = */ CML_Deg2Rad(50.0f),
      /* maxHeightSpeed = */ (0.02f/0.06f),
      /* maxDeltaHeightSpeed = */ 0.17f,
      /* minSpeedForYawEst = */ (2.0f/3.6f)
    },
    /* paramPairTruckLights */
    {
      /* minDistStart = */ 15.0f,
      /* minDistEnd = */ 4.0f,
      /* maxDist = */ 450.0f,
      /* minHeight = */ 2.00f, // 0.50f,
      /* maxHeight = */ 2.50f, //1.2f,
      /* minInterDist = */ 2.0f,
      /* maxInterDist = */ 2.2f, //2.4f,
      /* minIcst = */                     4.00f, /*28.0f,*/
      /* maxIcst = */                   100.00f, /*400.0f,*/
      /* minRedChromaticity = */          0.15f, /*0.2f,*/
      /* maxRedChromaticity = */          0.55f, /*0.3f,*/
      /* minGreenChromaticity = */        0.15f, /*0.4f,*/
      /* maxGreenChromaticity = */        0.55f, /*0.5f,*/
      /* maxRollStart = */ CML_Deg2Rad(5.0f),
      /* maxRollEnd = */ CML_Deg2Rad(10.0f),
      /* minStartSpeed = */   (-200.0f/3.6f),
      /* maxStartSpeed = */   (30.0f/3.6f),
      /* minStartYaw = */  CML_Deg2Rad(-40.0f),
      /* maxStartYaw = */  CML_Deg2Rad(40.0f),
      /* errMeasRedChromaticity = */  0.2f,
      /* errMeasGreenChromaticity = */  0.2f,
      /* errMeasGreyValue = */  200,
      /* errMeasPositionVerticalPixel = */ 2.0f,
      /* errMeasPositionHorizontalPixel = */ 2.0f,
      /* maxAcc = */ (100.0f/3.6f)/6.0f,
      /* maxYawRate = */ CML_Deg2Rad(50.0f),
      /* maxHeightSpeed = */ (0.02f/0.06f),
      /* maxDeltaHeightSpeed = */ 0.17f,
      /* minSpeedForYawEst = */ (2.0f/3.6f)
      }
  },
  /* paramDistFromHeight */
  {
    /* minDist = */  10.0f,
    /* maxDist = */  450.0f,
  },
  /* paramTTB */
  {
    /* maxTTB = */    10.0f,
  }
};  

const HLA_t_SegmentationParameters hlaSegmentationParameters = {
    
  /* Twilight */
  {
    /* LineCluster */
    {
      /* dxFOE */ 100,
      /* dyFOE */ 25,
      /* ClusterFOE */
      {
        /* dy4dx0 */ 1, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 0  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
      /* ClusterBorder */
      {
        /* dy4dx0 */ 4, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 2  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
    },
    /* LineCluster_Led */
    {
      /* dxFOE */ 100,
      /* dyFOE */ 25,
      /* ClusterFOE */
      {
        /* dy4dx0 */ 5, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 2  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
      /* ClusterBorder */
      {
        /* dy4dx0 */ 5, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 2  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
    },

    /* Light */
    {
      /* nLevels */ 6,
      /* iT1SatLevel */ 3,
      /* Level */
      {
        /* Level_0 */
        {
          /* IntThreshold [lux] */  30.0f, //8.0f
          /* dInt4NewLight [lux] */ 6.0f
        },
        /* Level_1 */
        {
          /* IntThreshold [lux] */ 40.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_2 */
        {
          /* IntThreshold [lux] */ 50.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_3 */
        {
          /* IntThreshold [lux] */ 100.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_4 */
        {
          /* IntThreshold [lux] */ 180.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_5 */
        {
          /* IntThreshold [lux] */ 333.33f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_6 */
        {
          /* IntThreshold [lux] */ 1000.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_7 (not used) */
        {
          /* IntThreshold [lux] */ 0.0f,
          /* dInt4NewLight [lux] */ 0.0f
        }
      }
    },

    /* RedLightDet */
    {
      /* dark red lights could only be detected around the FOE (dxFOE_dark, dyFOE_dark) */
      /* dxFOE_dark */ 100,
      /* dyFOE_dark */ 25,
      /* MaxInt_dark */ 200,
      /* MinR2G_dark */ 0.9f,
      /* MinR2B_dark */ 0.8f,

      /* MinR2G */ 1.35f,
      /* MinR2B */ 1.35f
    },

    /* Pair */
    {
      /* minInt [lux] */ 6.0f,
      /* maxInt [lux] */ 3000.0f,

      /* maxRegSize_x */ 15,
      /* maxRegSize_y */ 10,

      /* dx */ 6,
      /* dy */ 1,

      /* search/ build pair lights only around the FOE */
      /* dxFOE */ 100, 
      /* dyFOE */ 25
    },

    /* DarkNonRedLight */
    {
      /* minInt_FOE */ 200,
      /* minInt_FunctRoiBorder */ 500,
      /* minInt_AboveRoiBorder */ 500,
      /* dxFOE */ 100,
      /* dyFOE */ 25,
    },
    /* DarkRedLight */
    {
      /* minInt_FOE */ 200,
      /* minInt_FunctRoiBorder */ 500,
      /* minInt_AboveRoiBorder */ 500,
      /* dxFOE */ 100,
      /* dyFOE */ 25,
    },
    /* MaxNumLines */ HLA_SEG_MAX_NUM_SEG_LINES,
    

    /* maximal number of lights (filter parameter) */
    {
      /* 1st (index 0, RTE output) stage light filtering parameter */
      {
        /* MaxNumLights */ 60,
        /* MaxNumLights_AboveRoi */ 10,

        /* BrightBottomUp */ 0.4f,
        /* BrightBottomUpPass */ 0.25f,
        /* BrightBottomUp_dyFOE */ 25,

        /* RedBottomUp */ 0.4f,
        /* RedBottomUpPass */ 0.25f,
        /* RedBottomUp_dyFOE */ 25,
        /* RedHighRed */ 0.1f,

        /* LedBottomUpPass */ 0.15f,
        /* LedBottomUp_dyFOE */ 100
      },
      /* 2nd (index 1, hla tracking input) stage light filtering parameter */
      {
#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
        /* Roi */ 20,
        /* AboveRoi */ 7,
#else
        /* Roi */ 30,
        /* AboveRoi */ 10,
#endif
        /* BrightBottomUp */ 0.4f,
        /* BrightBottomUpPass */ 0.25f,
        /* BrightBottomUp_dyFOE */ 25,

        /* RedBottomUp */ 0.4f,
        /* RedBottomUpPass */ 0.25f,
        /* RedBottomUp_dyFOE */ 25,
        /* RedHighRed */ 0.1f,

        /* LedBottomUpPass */ 0.15f,
        /* LedBottomUp_dyFOE */ 100
      }
    }
  },

  /* Night */
  {
    /* LineCluster */
    {
      /* dxFOE */ 100,
      /* dyFOE */ 25,
      /* ClusterFOE */
      {
        /* dy4dx0 */ 1, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 0  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
      /* ClusterBorder */
      {
        /* dy4dx0 */ 4, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 2  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
    }, 
    /* LineCluster_Led */
    {
      /* dxFOE */ 100,
      /* dyFOE */ 25,
      /* ClusterFOE */
      {
        /* dy4dx0 */ 5, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 2  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
      /* ClusterBorder */
      {
        /* dy4dx0 */ 5, /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
        /* dy4dx1 */ 2  /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
      },
    },

    /* Light */
    {
      /* nLevels */ 6,
      /* iT1SatLevel */ 3,
      /* Level */
      {
        /* Level_0 */
        {
          /* IntThreshold [lux] */ 8.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_1 */
        {
          /* IntThreshold [lux] */ 25.0f,//30.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_2 */
        {
          /* IntThreshold [lux] */ 50.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_3 (T1 Saturation level) */
        {
          /* IntThreshold [lux] */ 78.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_4 */
        {
          /* IntThreshold [lux] */ 180.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_5 */
        {
          /* IntThreshold [lux] */ 333.33f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_6 */
        {
          /* IntThreshold [lux] */ 1000.0f,
          /* dInt4NewLight [lux] */ 0.0f
        },
        /* Level_7 (not used) */
        {
          /* IntThreshold [lux] */ 0.0f,
          /* dInt4NewLight [lux] */ 0.0f
        }
      }
    },

    /* RedLightDet */
    {
      /* dark red lights could only be detected around the FOE (dxFOE_dark, dyFOE_dark) */
      /* dxFOE_dark */ 100,
      /* dyFOE_dark */ 25,
      /* MaxInt_dark */ 200,
      /* MinR2G_dark */ 0.9f,
      /* MinR2B_dark */ 0.8f,
      
      /* MinR2G */ 1.35f,
      /* MinR2B */ 1.35f
    },
    
    /* Pair */
    {
      /* minInt [lux] */ 6.0f,
      /* maxInt [lux] */ 3000.0f,

      /* maxRegSize_x */ 15,
      /* maxRegSize_y */ 10,

      /* dx */ 6,
      /* dy */ 1,

      /* search/ build pair lights only around the FOE */
      /* dxFOE */ 100, 
      /* dyFOE */ 25
    },

    /* DarkNonRedLight */
    {
      /* minInt_FOE */ 100,
      /* minInt_FunctRoiBorder */ 200,
      /* minInt_AboveRoiBorder */ 200,
      /* dxFOE */ 100,
      /* dyFOE */ 25,
    },
    /* DarkRedLight */
    {
      /* minInt_FOE */ 8,
      /* minInt_FunctRoiBorder */ 100,
      /* minInt_AboveRoiBorder */ 200,
      /* dxFOE */ 100,
      /* dyFOE */ 25,
    },
    /* MaxNumLines */ HLA_SEG_MAX_NUM_SEG_LINES,

    /* maximal number of lights (filter parameter) */
    {
      /* 1st (index 0, RTE output) stage light filtering parameter */
      {
        /* MaxNumLights */ 60,
        /* MaxNumLights_AboveRoi */ 10,

        /* BrightBottomUp */ 0.4f,
        /* BrightBottomUpPass */ 0.25f,
        /* BrightBottomUp_dyFOE */ 25,

        /* RedBottomUp */ 0.4f,
        /* RedBottomUpPass */ 0.25f,
        /* RedBottomUp_dyFOE */ 25,
        /* RedHighRed */ 0.1f,

        /* LedBottomUpPass */ 0.15f,
        /* LedBottomUp_dyFOE */ 100
      },
      /* 2nd (index 1, hla tracking input) stage light filtering parameter */
      {
#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
        /* Roi */ 20,
        /* AboveRoi */ 7,
#else
        /* Roi */ 30,
        /* AboveRoi */ 10,
#endif
        /* BrightBottomUp */ 0.4f,
        /* BrightBottomUpPass */ 0.25f,
        /* BrightBottomUp_dyFOE */ 25,

        /* RedBottomUp */ 0.4f,
        /* RedBottomUpPass */ 0.25f,
        /* RedBottomUp_dyFOE */ 25,
        /* RedHighRed */ 0.1f,

        /* LedBottomUpPass */ 0.15f,
        /* LedBottomUp_dyFOE */ 100
      }
    }
  }
};

const HLA_t_CityDetectionParameters hlaCityDetectionParameters = {  
  /* ~CodeReview ~ID:0bd77d6017e101b7fe80a3488a55ffd3 ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:(40x) signed values assigned to unsigned values */
  /* CityAccelFactorMax */ -0.75f,            /* max factor apply to distance when decelerating */
  /* CityAccelFactorMin */ -1.5f,            /* min factor apply to distance when decelerating */
  /* maxDistTurnOnDelay100 */ 50,           /* [m] min. distance after passing of last streetlamp to turn city state off */
  /* minDistTurnOffDelay100  */10,          /* [m] min. distance between two leaving street lamps */
  /* minDistTurnOffDelayLeav100  */13,          /* [m] min. distance between two leaving street lamps*/
  /* maxDistTurnOffDelay100  */140,          /* [m] max. distance between two leaving street lamps*/
  /* maxDistTurnOffDelay100_LowInt */ 60,           /* [m] min. distance after passing of last streetlamp to turn city state off */
  /* mindistStreetLamp100  */80,                /* [m] max. distance of potential streetlamp (light) to keep ctiy state ON */ /* correspond to 4.8s at 50km/h */
  /* maxdistStreetLamp100  */160,                /* [m] max. distance of potential streetlamp (light) to keep ctiy state ON */ /* correspond to 4.8s at 120km/h */
  /* MinIntensityStreetLampUpperRoi */ 200.0f,            /* [lux] minimum intensity to accept streetlamp and switch city mode ON if street lamp is in upper Roi*/
  /* MinIntensityStreetLamp  */350.0f,      /* [lx] minimum intensity to accept streetlamp and switch city mode ON */
  /* MinIntensityStreetLampUpperRoi_Tunnel */ 150.0f,            /* [lux] minimum intensity to accept streetlamp and switch city mode ON if street lamp is in upper Roi*/
  /* MinIntensityStreetLamp_Tunnel  */300.0f,      /* [lx] minimum intensity to accept streetlamp and switch city mode ON */
  /* sizeCorridor100  */2,                  /* [m] [resolution: 0.01m] max. lateral offset between 2 street lamps of the same cluster */
  /* sizeCorridorTight100  */1.5f,              /* [m] [resolution: 0.01m] max. lateral offset between 2 street lamps of the same cluster in a tunnel */
  /* sizeCorridorLoose100  */5.5f,            /* [m] [resolution: 0.01m] max. lateral offset between 2 street lamps of the same cluster. Used for city confirmation on a street lamp far in the scene */
  /* maxStreetLampY_Wide100    */10,            /* [m] max. lateral offset of streetlamp for Ymax calculation */
  /* maxStreetLampY_Narrow100    */10,              /* [m] max. lateral offset of streetlamp for Ymax calculation */
  /* maxStreetLampY_Tunnel100    */7,              /* [m] max. lateral offset of streetlamp for Ymax calculation */
  /* minHeightAssumpSL */ 3.0f,                        /* minimal Height Assumption for Street Lamps */
  /* maxHeightAssumpSL */ 6.0f,                        /* maximal Height Assumption for Street Lamps */
  /* minSpeedHeightAssumpSL */ 16.67f,/* 60km/h */     /* minimal speed to modify Height Assumption for Street Lamps */
  /* maxSpeddHeightAssumpSL */ 27.77f,/* 100km/h */     /* maximal speed to modify Height Assumption for Street Lamps */
  /* minLeavingSLdistance */ 18.0f,                   /* minimal Distance after which Street Lamp are leaving */ /* correspond to 0.54s to border for a 3m height SL at 50km/h */
  /* maxLeavingSLdistance */ 48.0f,                   /* maximal Distance after which Street Lamp are leaving */ /* correspond to 0.54s to border for a 6m height SL at 120km/h */
  /* maxDistInterStreetLamp100 */ 105,          /* [m] */
  /* maxDistInterStreetLampVariance */ 400.0f,  /* check */
  /* maxDistInterStreetLampVarianceShort */ 225.0f, /* check */
  /* maxStreetLampTunnelYw100    */20,      /* [m] [resolution: 0.01m] max. lateral offset of streetlamp for tunnel street lamps */
  /* maxStreetLampTunnelYwVar   */0.2f,  /* [m*m] max. lateral offset variance in a streetlamp straight line. Used for tunnel street lamps */
  /* maxVarRatio */ 0.25f,                            /* maximal variace tolerated ratio with mean value */
  /* minStreetLampTunnelXwInter100   */2,  /* [m] [resolution: 0.01m] min. distance between street lamps in a streetlamp straightline. Used for tunnel street lamps */
  /* maxStreetLampTunnelXwInter100   */15,  /* [m] [resolution: 0.01m] min. distance between street lamps in a streetlamp straightline. Used for tunnel street lamps */
  /* minRoadYw100 */ 3,                              /* [m] Minimal distance for two street lamps for being at different side of the road */
  /* maxXwDist100_3dEst */ 200,                     /* [m] maximal frontal distance estimated by tracking */
  /* maxYwDist100_3dEst */ 30,                     /* [m] maximal lateral distance estimated by tracking */
  /* maxXwDist100_3dEst_Tunnel */ 150,             /* [m] maximal frontal distance estimated by tracking for tunnel */
  /* maxYwDist100_3dEst_Tunnel */ 10,              /* [m] maximal lateral distance estimated by tracking for tunnel */
  /* maxXwDist100_3dEstLeav */ 130,                /* [m] maximal frontal distance estimated by tracking */
  /* maxYwDist100_3dEstLeav_Wide */ 13,                      /* [m] maximal lateral distance estimated by tracking */
  /* maxYwDist100_3dEstLeav_Narrow */ 10,                      /* [m] maximal lateral distance estimated by tracking */
  /* maxYwDist100_3dEstLeav_InCities */ 16,                      /* [m] maximal lateral distance estimated by tracking */
  /* minRadiusCityOn */ 300,            /* [m] min. turn radius to count host movement for city ON detection */
  /* minDistInterStreetLampUnfiltered */ 20,
  /* minYwDistSide100 */ 0.5f,
  /* minSLsize */ 1,
  /* VarToConverge */ 100,        /* ->ok */
  /* VarToDiverge */ 350,       /* ->ok */
  /* minIconConf */ 25, 
  /* numFramesSLSignalOnToOff */ 17,
  /* numFramesSLSignalOffToOn */ 4,
  /* minRadiusCityOff  */100,            /* [m] min. turn radius to count host movement for city OFF detection */
  /* speedLimitLOW_HIGH  */80,            /* [km/h] speed limit for LOW and HIGH mode for city detection */
  /* AHBC_NASL_LOW  */2,                  /* number of leaving street lamp to detect city in LOW mode */
  /* AHBC_NASL_HIGH  */2,                /* number of leaving street lamp to detect city in HIGH mode */
  /* AHBC_NSCENESL_LOW  */1,              /* number of scene street lamp to detect city in LOW mode */
  /* AHBC_NSCENESL_HIGH  */1,            /* number of scene street lamp to detect city in HIGH mode */
  /* AHBC_NSCENESL_TUNNEL */ 3,
  /* SafetyGapTop */ 30,
  /* SafetyGapSide */ 30,
  /* minTrackTimeToReinit */ 8,
  /* minRadiusDelatYw */ 100.0f,
  /* maxRadiusDelatYw */ 1225.0f,
  /* ~CodeReview ~ID:a78e1875e04b784517097157cb00a216 ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:assigned signed int to float variable */
  /* minDeltaYwCurve100 */ 0,       /* [m] */
  /* maxDeltaYwCurve100 */ 5.0f,    /* [m] */
  /* HighIntensityExtraGap100 */ 3, /* [m]*/
  /* luminousFluxMin */ 120000.0f,
  /* luminousFluxMax */ 150000.0f,
  /* MinYwDist100 */ 10,    /* -> ok */
  /* MaxYwDist100 */ 20,    /* ->ok */
  /* MaxConfHighIntensityFlux */ 10,
  /* MinConfHighIntensityFlux */ -3,
  /* HighIntensityFluxThreshPositif */ 5,
  /* HighIntensityFluxThreshNegative */ 0,
  /* MaxDistToLeavCityInCurve100 */ 70,   /* [m]*/
  /* MaxRadius */ 500.0f,                   /* Radius which could lead to some bordering own lane street lamp not in the FOV */
  /* DeathAreaX */ 10.0f,
  /* DeathAreaY */ 3.0f,
  /* DeathAreaZ */ 3.0f,
  /* numSLInSceneLeaveCityJapan */ 1

};


const HLA_t_TrafficStyleParameters hlaTrafficStyleParameters = {
  /* trafficStyleMinDeltaX = */ 8.0f,
  /* trafficStyleHysteresis = */ 100,
  /* trafficStyleCountDiscard */ 25,
  /* trafficStyleCountLock */ 200,
  /* trafficStyleMinTrackSecs = */ 0.5,
  /* trafficStyleSpeedFactor = */ 0.7f,
  /* trafficStyleYawRateFactor = */ 0.7f,
  /* trafficStyleMinSpeed = */ 8.3333f,
  /* trafficStyleStepThresh = */ 25.0f,
  /* minOdometerLock = */ 5000.0f
};

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

