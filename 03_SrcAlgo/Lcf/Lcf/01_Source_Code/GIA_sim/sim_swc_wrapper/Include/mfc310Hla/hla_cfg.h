/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_cfg.h

  DESCRIPTION:            Configuration file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2009-11-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_cfg.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:31CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:42CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:06CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.262 2014/03/26 14:44:47CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:47 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.261 2014/03/25 19:02:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced fABS by CML_f_abs
  CHANGES:                Introduced CML_f_Round
  CHANGES:                Removed QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 25, 2014 7:02:59 PM CET]
  CHANGES:                Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.260 2014/03/22 10:28:32CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added project specific defines
  CHANGES:                Replaced defines for CORE by predefined ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:32 AM CET]
  CHANGES:                Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.259 2014/03/19 15:18:46CET Fischer, Alexander (uidv8778) 
  CHANGES:                Added numSLInSceneLeaveCityJapan Parameter (japan specific)
  CHANGES:                --- Added comments ---  uidv8778 [Mar 19, 2014 3:18:47 PM CET]
  CHANGES:                Change Package : 226009:1 http://mks-psad:7002/im/viewissue?selection=226009
  CHANGES:                Revision 1.258 2014/03/11 10:33:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced SRLCAM_4T0 by CFG_SRLCAM==1
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2014 10:33:58 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.257 2014/03/04 16:51:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:57 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.256 2014/03/03 16:51:44CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:44 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.255 2014/02/28 15:04:52CET Brunn, Marcus (brunnm) 
  CHANGES:                - improved light filtering
  CHANGES:                - preparation of light list for new rte interface i390
  CHANGES:                --- Added comments ---  brunnm [Feb 28, 2014 3:04:52 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.254 2014/02/21 16:53:51CET Manz, Alexander (uidv8777) 
  CHANGES:                Update: changed "Vehicle" to "Pair" for better understandability in macro name
  CHANGES:                --- Added comments ---  uidv8777 [Feb 21, 2014 4:53:52 PM CET]
  CHANGES:                Change Package : 207634:3 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGES:                Revision 1.253 2014/02/11 09:20:14CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed time meas
  CHANGES:                Fixed dframe calculation on HIL
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:14 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.252 2014/02/07 09:59:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added restrictions (light/track reduction by ~30%; 1 icon less)
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2014 9:59:48 AM CET]
  CHANGES:                Change Package : 207432:29 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.251 2014/02/06 16:02:41CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:41 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.250 2014/02/05 15:26:51CET Brunn, Marcus (brunnm) 
  CHANGES:                removed LED segmentation
  CHANGES:                --- Added comments ---  brunnm [Feb 5, 2014 3:26:52 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.249 2014/01/16 14:29:18CET Schillinger, Patrick (uidv8776) 
  CHANGES:                remove defines:
  CHANGES:                HLA_COLOR_USE_OPTIMIZED_CODE 
  CHANGES:                HLA_HEADLIGHTTYPE_HALOGE
  CHANGES:                HLA_HEADLIGHTTYPE_XENON_LED
  CHANGES:                --- Added comments ---  uidv8776 [Jan 16, 2014 2:29:18 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.248 2014/01/10 18:33:43CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:44 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.247 2013/12/18 15:18:03CET Schillinger, Patrick (uidv8776) 
  CHANGES:                introduction of new HighwayOncomingTruckLight detection
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:03 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.246 2013/12/17 17:32:43CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGES:                --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:44 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.245 2013/11/21 17:53:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:48 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.244.1.8 2013/11/21 13:37:34CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved Icon normalize
  CHANGES:                Bug fixes in segmentation
  CHANGES:                Removed no longer compiler switches
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:35 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.244.1.7 2013/11/19 07:51:00CET Brunn, Marcus (brunnm) 
  CHANGES:                - removed day segmentation
  CHANGES:                --- Added comments ---  brunnm [Nov 19, 2013 7:51:00 AM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.244.1.6 2013/11/14 09:47:29CET Brunn, Marcus (brunnm) 
  CHANGES:                - hla segmentation: clean up of region parameters
  CHANGES:                - removed unused defines
  CHANGES:                --- Added comments ---  brunnm [Nov 14, 2013 9:47:29 AM CET]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.244.1.5 2013/10/29 18:21:32CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Time meas fixes
  CHANGES:                New roi calculation (alignment to eve)
  CHANGES:                Call EVE in segmentation now
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:32 PM CET]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.244.1.4 2013/10/25 15:17:32CEST Brunn, Marcus (brunnm) 
  CHANGES:                improved detection of preceding cars (reduced thresholds for birth of red lights)
  CHANGES:                --- Added comments ---  brunnm [Oct 25, 2013 3:17:32 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.244.1.3 2013/10/24 10:44:16CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some not needed variables
  CHANGES:                Made HLA working on evalboard
  CHANGES:                --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:17 AM CEST]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.244.1.2 2013/10/21 16:00:27CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced preprocessing function: HLASegPreProcImage()
  CHANGES:                --- Added comments ---  brunnm [Oct 21, 2013 4:00:27 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.244.1.1 2013/10/18 13:27:49CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:49 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.244 2013/08/26 14:44:35CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Decreased HLA restrictions from 40 to 60% #lights
  CHANGES:                --- Added comments ---  uidv7867 [Aug 26, 2013 2:44:35 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.243 2013/08/24 15:01:27CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimiztations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:27 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.242 2013/08/02 16:18:30CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Integrated HLA runtime restrictions (down to 3 icons and 40% of lights)
  CHANGES:                --- Added comments ---  uidv7867 [Aug 2, 2013 4:18:31 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.241 2013/07/26 17:04:21CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Added first part of EVE implementation
  CHANGES:                --- Added comments ---  uidv7867 [Jul 26, 2013 5:04:22 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.240 2013/07/12 11:20:40CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Further restructuring of chain of light
  CHANGES:                --- Added comments ---  uidv8778 [Jul 12, 2013 11:20:41 AM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.239 2013/04/19 14:48:03CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Changed city paramter from cm to m
  CHANGES:                --- Added comments ---  uidv8778 [Apr 19, 2013 2:48:04 PM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.238 2013/04/12 12:45:27CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Took more coding parameters into use
  CHANGES:                --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:27 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.237 2013/04/12 10:55:11CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Implemented BMW Codierparameter for city and traffic style
  CHANGES:                --- Added comments ---  uidv8778 [Apr 12, 2013 10:55:11 AM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.236 2013/04/09 16:10:43CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Cleaned-up no longer needed struct (tunnel)
  CHANGES:                --- Added comments ---  uidv7867 [Apr 9, 2013 4:10:44 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.235 2013/03/27 12:56:19CET Schillinger, Patrick (uidv8776) 
  CHANGES:                magic numbers of highway oncoming car detection are now paramaters in hlaAnalysisParameters
  CHANGES:                --- Added comments ---  uidv8776 [Mar 27, 2013 12:56:19 PM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.234 2013/03/15 12:56:44CET Manz, Alexander (uidv8777) 
  CHANGES:                Tunnel detection update includes ability to work with parameter and create measFreezes
  CHANGES:                --- Added comments ---  uidv8777 [Mar 15, 2013 12:56:44 PM CET]
  CHANGES:                Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGES:                Revision 1.233 2013/02/26 09:19:55CET Fischer, Alexander (uidv8778) 
  CHANGES:                Highway detection over high speed implemented
  CHANGES:                --- Added comments ---  uidv8778 [Feb 26, 2013 9:19:55 AM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.232 2013/02/22 16:21:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added system info errors for roi calculation in x direction
  CHANGES:                --- Added comments ---  uidv7867 [Feb 22, 2013 4:21:56 PM CET]
  CHANGES:                Change Package : 167173:25 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.231 2013/02/22 09:09:26CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Exchanged modulo count magic number by macro
  CHANGES:                --- Added comments ---  uidv7867 [Feb 22, 2013 9:09:26 AM CET]
  CHANGES:                Change Package : 167173:25 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.230 2013/02/12 15:08:26CET Fischer, Alexander (uidv8778) 
  CHANGES:                Optimization to avoid truck lights to be detected as SL
  CHANGES:                --- Added comments ---  uidv8778 [Feb 12, 2013 3:08:26 PM CET]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.229 2013/01/24 18:26:49CET Zechner, Stefan (uidt9253) 
  CHANGES:                - increase HLA_ICON_ANALYSIS_VEHICLE_MAX_BOXES to 5
  CHANGES:                --- Added comments ---  uidt9253 [Jan 24, 2013 6:26:50 PM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.228 2013/01/24 14:19:26CET Zechner, Stefan (uidt9253) 
  CHANGES:                - minimum time of 7 frames where sticky state is kept avoids flickering of vehicle detected/lost/detected in icon bypass scenarios
  CHANGES:                --- Added comments ---  uidt9253 [Jan 24, 2013 2:19:27 PM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.227 2013/01/22 12:06:41CET Fischer, Alexander (uidv8778) 
  CHANGES:                HLA-R Internal Highway Decision

**************************************************************************** */

#ifndef HLA_CFG_INCLUDED
#define HLA_CFG_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* expected number of dframes for each HLA call */
#define HLA_NUM_EXPECTED_DFRAMES       (2)

/* object list verion number */
#define HLA_OBJECT_LIST_VERSION_NUMBER      0x040000

/* imager parameter */
#define HLA_MAX_PHYS_IMAGE_WIDTH  1288
#define HLA_MAX_PHYS_IMAGE_HEIGHT  968

/* absolute fingerprint position in (x,y) */
#define HLA_FINGERPRINT_X   372
#define HLA_FINGERPRINT_Y   600

#define HLA_SEG_MAX_NUM_NGB_XY            8 
#define HLA_SEG_MAX_NUM_NGB            (HLA_SEG_MAX_NUM_NGB_XY*HLA_SEG_MAX_NUM_NGB_XY)

#define HLA_SEG_MAX_NUM_SEG_LINES       800u   /*!< max. number of lines (level 1-n)           */
#define HLA_SEG_MAX_NUM_REGIONS         200u   /*!< max. number of regions (level 1-n)         */
#define HLA_SEG_MAX_NUM_LIGHTS          150u   /*!< (internal lights) max. number of segmented lights per frame  */

#define HLA_SEG_ERR_THRESHOLD_ROI_OUTSIDE_CROI_X  40  /*!< Is requested ROI outside of cROI we set error when this threshold is exceeded */
#define HLA_SEG_ERR_THRESHOLD_ROI_OUTSIDE_CROI_Y   1  /*!< Is requested ROI outside of cROI we set error when this threshold is exceeded */


/* segmentation kernel size  */
/*             R             */
/*          B  G  B          */
/*       R  G  R  G  R       */
/*          B  G  B          */
/*             R             */
#define HLA_SEGMENTATION_KERNEL_SIZE   5u
#define HLA_SEGMENTATION_KERNEL_OFFSET 2

/* the roi will always start at an even pixel (X1 = even) */
/* the bayer Pattern for MFC300 is GRBG                   */
#define HLA_SEGMENTATION_BAYER_PATTERN  HLA_BAYERPATTERN_GRBG
#define HLA_SEGMENTATION_GREEN_OFFSET   0u
#define HLA_SEGMENTATION_RED_OFFSET     1u

/* subsampled image size */
#define HLA_SEG_INTENSITY_SUB_IMG_WIDTH       5u
#define HLA_SEG_INTENSITY_SUB_IMG_HEIGHT      5u
#define  HLA_SEG_INTENSITY_SUB_IMG_SIZE  (HLA_SEG_INTENSITY_SUB_IMG_HEIGHT * HLA_SEG_INTENSITY_SUB_IMG_WIDTH)
/* intensity history cycles */
#define HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES 5u    

/*************/
/* hla icons */
/*************/
/* analysis icons */
#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
#define HLA_ICON_ANALYSIS_VEHICLE_MAX_BOXES     1
#else
#define HLA_ICON_ANALYSIS_VEHICLE_MAX_BOXES     2
#endif
#define HLA_ICON_ANALYSIS_CITY_MAX_BOXES        1
#define HLA_ICON_ANALYSIS_MAX_BOXES             (HLA_ICON_ANALYSIS_VEHICLE_MAX_BOXES + HLA_ICON_ANALYSIS_CITY_MAX_BOXES)
#define HLA_ICON_ANALYSIS_MAX_SIZE_X            52
#define HLA_ICON_ANALYSIS_MAX_SIZE_Y            56

/* max. number of all icon boxes (Analysis + possible other future icon requester) */
#define HLA_ICON_MAX_BOXES                      (HLA_ICON_ANALYSIS_MAX_BOXES)

/*! @brief maximal number of tracks */
#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
#define HLA_TRACKING_MAX_NUM_TRACKS                       25
#else
#define HLA_TRACKING_MAX_NUM_TRACKS                       35
#endif
#define HLA_TRACKING_MAX_NUM_PAIRS                        12
#define HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR          12
#define HLA_TRACKING3D_MAX_NUM_CROSS_CORR                 (HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR*(HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR-1)/2)
#define HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK         3

#if defined(PC_SIM) || defined(EVAL_BOARD)
#define HLA_TRACKING3D_NUM_LANE_POINTS_VISU_YAW_RATE    42
#define DB_HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK    10
#endif

/* HLA brightness: max number of used criteria */
#define HLA_BRIGHTNESS_NUM_POS_CRITERIA 1
#define HLA_BRIGHTNESS_NUM_NEG_CRITERIA 2
/* HLA brightness min/ max intensity */
#define HLA_BRIGHTNESS_MIN_INTENSITY_LUX (-1.0f)
#define HLA_BRIGHTNESS_MAX_INTENSITY_LUX  9999999999.0f

#define HLA_SLPARAM_ARRAYCONFIDENCE 18

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


typedef struct
{
  float32 AboveRoi_MinInt_lux;
  float32 AboveRoi_MaxInt_lux;
  float32 Roi_MeanIntF_lux;
} HLABrightnessParThresPosNeg_t;

typedef struct
{
  /* negative 2 positive */
  float32 Neg2Pos_MinInt_lux;
  float32 Neg2Pos_MaxInt_lux;
  /* positive 2 negative */
  float32 Pos2Neg_MinInt_lux;
  float32 Pos2Neg_MaxInt_lux;

  /* high intensity -> increase filter speed */
  float32 MaxFactor;
} HLABrightnessParThresTurbo_t;

typedef struct
{
  float32 Radius0_m;  /* radius < radius0 -> increase distance only with (Factor0_ddist*ddist) */
  float32 Radius1_m;  /* radius > radius0 -> increase distance only with (ddist) */
  float32 Factor0_ddist; 
} HLABrightnessParThresRadius_t;

typedef struct
{
  float32 MinTimePos_s;
  float32 MinDistPos_m;
  float32 MinTimeNeg_s;
  float32 MinDistNeg_m;

  float32 MinTimePosInit_s;
  float32 MinTimeNegInit_s;

  /* maximal time to init state (standstill or driving backwards) */
  /* MinTimePos_s,MinDistPos_m, ... will be decremented to zero   */
  float32 MaxTime2InitState_s;
} HLABrightnessParThresMinDistTime_t;

typedef struct
{
  uint8 NumberOfUsedPosCriteria; /* number of used positive criteria */
  uint8 NumberOfUsedNegCriteria; /* number of used negative criteria */
  HLABrightnessParThresPosNeg_t Pos[HLA_BRIGHTNESS_NUM_POS_CRITERIA];
  HLABrightnessParThresPosNeg_t Neg[HLA_BRIGHTNESS_NUM_NEG_CRITERIA];

  HLABrightnessParThresTurbo_t Turbo;
  HLABrightnessParThresRadius_t Radius;

  HLABrightnessParThresMinDistTime_t MinDistTime;
} HLABrightnessParThres_t;

typedef struct
{
  /* the sub image consists of 5 rows and 5 columns   */
  /* the last line of each row is defined as follows: */
  /* EndRow0 = Yu, end of above roi = city roi        */
  /* EndRow1 = Yu + EndRow1_factor * (Y_FOE - Yu)     */
  float32 EndRow1_factor;  
  /* EndRow2,3,4 is defined in 3d world coordinates   */
  float32 xw_EndRow2_m; /* [m] distance on the road, zw = 0.0m,  yw= 0.0m */
  float32 xw_EndRow3_m; /* [m] distance on the road, zw = 0.0m,  yw= 0.0m */
  float32 xw_EndRow4_m; /* [m] distance on the road, zw = 0.0m,  yw= 0.0m */
} HLABrightnessParSubImage_t;

typedef struct 
{
  HLABrightnessParSubImage_t SubImage;
  HLABrightnessParThres_t Twilight_1;
  HLABrightnessParThres_t Twilight_2;
  HLABrightnessParThres_t Twilight_3;
  HLABrightnessParThres_t Night;
  uint32                  MeanIntFMaxIndex; /* must be <= (HLA_SEG_INTENSITY_SUB_IMG_HEIGHT*HLA_SEG_INTENSITY_SUB_IMG_WIDTH)        */
                                            /* mean int = average of the darkest sub sampled pixels (MeanIntFMaxIndex out of 25=5x5) */  
} HLABrightnessParameters_t;


/****************************/
/*! segmentation parameters */
/****************************/
typedef struct 
{
  uint16 minInt_FOE;
  uint16 minInt_FunctRoiBorder;
  uint16 minInt_AboveRoiBorder;
  uint16 dxFOE;
  uint16 dyFOE;
}HLA_t_SegmentationParametersDarkLight;


/* level dependent light parameter */
typedef struct
{
  float32 IntThreshold;   /* [lux] minimum intensity threshold for lights @certain level */
  float32 dInt4NewLight;  /* [lux] region will create a new light when the maxInt > (IntThreshold[iLevel] + dInt4NewLight[iLevel]) */
} HLASegmentationParametersLightLevel_t;


typedef struct
{
  uint16 nLevels;                                                           /* number of used levels */
  uint16 iT1SatLevel;                                                       /* level index of the T1 saturation level (typical pulsed LED saturation)*/
  HLASegmentationParametersLightLevel_t Level[RTE_HLA_SEG_MAX_NUM_LEVELS]; /* level dependent parameter */
} HLASegmentationParametersLight_t;


typedef struct 
{
  uint16 dy4dx0; /* dy=0 ...  10 pixels for dx=0 in y-direction is possible  */
  uint16 dy4dx1; /* dy=0 ...  10 pixels for dx=1 in y-direction is possible  */
} HLASegmentationParametersLineClusterPar_t;

typedef struct 
{
  uint16 dxFOE;
  uint16 dyFOE;

  HLASegmentationParametersLineClusterPar_t ClusterFOE;
  HLASegmentationParametersLineClusterPar_t ClusterBorder;
} HLASegmentationParametersLineCluster_t;


typedef struct
{
  /* red light with low intensity */
  /* dark red lights could only be detected around the FOE (dxFOE_dark, dyFOE_dark) */
  uint16  dxFOE_dark;
  uint16  dyFOE_dark;
  uint16  MaxInt_dark; /* [lux] max intensity for red light */
  float32 MinR2G_dark;
  float32 MinR2B_dark;

  /* normal red lights */
  float32 MinR2G;
  float32 MinR2B;
}HLASegmentationParametersRedLightDet_t;

typedef struct 
{
  /* maximal number of lights (output, used by tracking) */
  uint16 Roi;                 /* function + above ROI */  
  uint16 AboveRoi;            /* only above ROI       */

  float32 BrightBottomUp;      /* only xxxBottomUpPass percentage of the lights from xxxBottomUp lights will pass the filter */
  float32 BrightBottomUpPass;  /* the ones with the highest intensity */
  uint16  BrightBottomUp_dyFOE;/* 1. stage: bottom up passed lights must be below (y_FOE - dyFOE) */
                               /* 2. stage: take all bottom up lights independent of y position in the image */

  float32 RedBottomUp;         /* only xxxBottomUpPass percentage of the lights from xxxBottomUp lights will pass the filter */
  float32 RedBottomUpPass;     /* the ones with the highest red value */
  uint16  RedBottomUp_dyFOE;   /* 1. stage: bottom up passed lights must be below (y_FOE - dyFOE) */
                               /* 2. stage: take all bottom up lights independent of y position in the image */
  float32 RedHighestRedValue;  /* maximal percentage of passed pot. red lights in the function roi with highest red value  */
  /* -> total sum of max. passed pot. red lights = MaxNumLightsRedBottomUp + MaxNumLightsRedHighestRedValue */

  float32 LedBottomUpPass;     /* only xxxBottomUpPass lights led lights will pass the filter */
  uint16  LedBottomUp_dyFOE;   /* only led lights below (y_FOE - dyFOE) could pass the bottom up filter */
} HLA_t_SegmentationParametersMaxNumLights;


typedef struct  
{
  float32 minInt; /* [lux] min. intensity to become a pair light */
  float32 maxInt; /* [lux] max. intensity to become a pair light */
  
  /* max. region size of lowest region */
  uint16 maxRegSize_x;
  uint16 maxRegSize_y;

  /* max. distance between two lights to become a pair */
  uint16 dx;
  uint16 dy;

  /* search/ build pair lights only around the FOE */
  uint16 dxFOE; 
  uint16 dyFOE;
}HLASegmentationParametersPair_t;

typedef struct 
{
  /* line cluster parameter */
  HLASegmentationParametersLineCluster_t LineCluster;
  
  HLASegmentationParametersLineCluster_t LineCluster_Led; /* LED level */

  /* light parameters: for new light generation */
  HLASegmentationParametersLight_t Light;

  HLASegmentationParametersRedLightDet_t RedLightDet; /* potential red light detection */
  
  HLASegmentationParametersPair_t Pair;

  /* dark light parameter for function/ above (city) ROI */
  HLA_t_SegmentationParametersDarkLight DarkNonRedLight;
  HLA_t_SegmentationParametersDarkLight DarkRedLight;
  
  /* maximal number of segmented lines */
  uint16 MaxNumLines;  
  
  /* maximal number of lights (filter parameter) */
  /* 1st (index 0, RTE output) and 2nd (index 1, hla tracking input) stage light filtering parameter */
  HLA_t_SegmentationParametersMaxNumLights MaxNumLights[2]; 
} HLA_t_SegmentationParametersBrightness;


/*! Type definition for the segmentation parameters. */
typedef struct 
{
  /* brightness dependent parameters */
  HLA_t_SegmentationParametersBrightness Twilight;
  HLA_t_SegmentationParametersBrightness Night;
} HLA_t_SegmentationParameters;

/*! typedef struct for 3D tracking based on-line cali and egomotion parameters */
typedef struct
{
  float32                     errCalYawMax;           
  float32                     errCalPitchMax;
  float32                     errCalRollMax;
  float32                     errCalYawMin;
  float32                     errCalPitchMin;
  float32                     errCalRollMin;
  uint8                       minNumFullEgoTracksToUpdateOnlineCaliOdometer;
  float32                     maxOdometerOnLineCaliM;    
} HLATracking3DParametersCali_t;

/*! typedef struct for 3D tracking based on-line cali and egomotion parameters */
typedef struct
{
  float32                     errMaxYawRate;
  float32                     errEgoPitchRadian;
  float32                     errEgoRollRadian;
  float32                     extremeErrYawRate;
  float32                     extremeErrEgoPitchRadian;
  float32                     extremeErrEgoRollRadian;   
} HLATracking3DParametersEgomotion_t;

/*! typedef struct for 3D tracking static tracker parameters */
typedef struct
{
  float32                     minTrackDist;
  float32                     initDistanceStatic;
  float32                     chi2_1_StaticRobust;
  float32                     maxInverseDepth;
  uint8                       maxCycleLostTimeStatic;
} HLATracking3DParametersStaticTracker_t;

/*! typedef struct for 3D tracking dynamic tracker parameters */
typedef struct
{
  float32                     initDistanceDynamic;
  float32                     codd_init;
  float32                     minDistDynamic;
  float32                     maxDistDynamic;
  float32                     errXWVelocityInit;
  float32                     errYWVelocityInit;
  float32                     errXWVelocityProc;
  float32                     errYWVelocityProc;
  float32                     maxErrHorizontalInPix;
  float32                     maxErrVerticalInPix;
  float32                     maxRMSE;
} HLATracking3DParametersDynamicTracker_t;

/*! typedef struct measurement paramters parameters */
typedef struct
{
  float32                     errMeasPixelMin;    
  float32                     errMeasPixelMax;    
} HLATracking3DParametersMeasurement_t;

/*! typedef struct data matching parameters */
typedef struct
{
  float32                     errMeasIntensityGreyLevel;
  float32                     factorMaxIntDecrease;
  float32                     constMaxIntFilter;
  float32                     maxEuclDistAssocTrack2Light;
  uint32                      threshHammingAssocDistance[4];
  float32                     penaltyAssocDistance[4];
  uint32                      threshHammingPatternUpdate;
  uint8                       maxTimeWithoutPatternUpdate;
  uint8                       maxTimeWithoutRGBUpdate;
} HLATracking3DParametersMatching_t;

/*! typedef struct 3D tracking analysis parameters */
typedef struct
{
  uint8                       minNumFrameFromUnknownToStatic;
  uint8                       minNumFrameFromUnknownToDynamic;
  uint8                       minNumFrameFromStaticToUnknown;
  uint8                       minNumFrameFromDynamicToUnknown;
  float32                     minRatioStaticDepthConvergence;
  float32                     minDwForLonelyStaticTrack;
  float32                     minSpeedToAddSlamFeatures;
  float32                     minSpeedToKeepSlamFeatures; 
  uint16                      numCyclesDlpLt;         /*!< low pass filter length for long term motion filter*/
  float32                     h_dlp_tk1;              /*! delta low pass filter constant when track time is 1 */
  float32                     h_dlp_tk2;              /*! delta low pass filter constant when track time is 2 */
  float32                     hx_dlp_tkn;             /*! delta_x low pass filter constant when track time is >2 */
  float32                     hy_dlp_tkn;             /*! delta_y low pass filter constant when track time is >2 */
} HLATracking3DParametersAnalysis_t;

/*! typedef struct track birth parameters */
typedef struct
{
  float32                     minLuxIntensity4newTrack; /* min intensity for non isolated lights */
  float32                     minLuxIntensity4newTrackIsolatedLight;
  float32                     minLuxIntensity4newRedTrackIsolatedLight; /* red light: R>MinR && G<MaxG && B<MaxB */
  float32                     MinR; 
  float32                     MaxG;
  float32                     MaxB;
  uint8                       MaxNumberOfNewTracks;     /*!< maximal number of new tracks per cycle */
} HLATracking3DParametersBirth_t;

/*! typedef struct track birth parameters */
typedef struct
{
  uint8                       maxCyclesTrackLost; 
  uint8                       maxCyclesPairLost; 
  uint8                       maxCyclesTrackLostInPair; 
  float32                     minRelVelToUseMaxCyclePair;
  sint32                      pixelMarginOutOfRoi;
} HLATracking3DParametersDeath_t;

/*! typedef struct hot pixel parameters */
typedef struct
{
  uint8                   HotPixelMinTrackAge;        /*!< minimal track age (trace time) before track might be considered as hot*/ 
  uint8                   HotPixelMinConsequentAssoc; /*!< minimal cycles of consequent identical associations to mark track as hot */
  uint16                  HotPixelValidaionCycle;     /*!< cycle time for periodical hot pixel validation */
  float32                 HotPixelValidaionRate;      /*!< minimal update rate the keep hot pixel alive */
  float32                 minSpeedAllCurves;          /*! < minimal speed to process hot pixels regardless of road curvature */
  float32                 minSpeedCurvyRoad;          /*! < minimal speed to process hot pixels in curvy road */
  float32                 minYawRateCurvyRoad;        /*! < yaw rate trehshold for curvy road definition */
} HLAHotPixelParameters_t;

/*! typedef struct pair parameters */
typedef struct
{
  float32                 minDistStart;
  float32                 minDistEnd;
  float32                 maxDist;
  float32                 minHeight;
  float32                 maxHeight;
  float32                 minInterDist;
  float32                 maxInterDist;
  float32                 minIcst;
  float32                 maxIcst;
  float32                 minRedChromaticity;
  float32                 maxRedChromaticity;
  float32                 minGreenChromaticity;
  float32                 maxGreenChromaticity;
  float32                 maxRollStart;
  float32                 maxRollEnd;
  float32                 minStartSpeed;
  float32                 maxStartSpeed;
  float32                 minStartYaw;
  float32                 maxStartYaw;
  float32                 errMeasRedChromaticity;
  float32                 errMeasGreenChromaticity;
  uint32                  errMeasGreyValue;
  float32                 errMeasPositionVerticalPixel;
  float32                 errMeasPositionHorizontalPixel;
  float32                 maxAcc;
  float32                 maxYawRate;
  float32                 maxHeightSpeed;
  float32                 maxDeltaHeightSpeed;
  float32                 minSpeedForYawEst;
} HLATracking3DParametersPair_t;

/*! typedef struct pair parameters */
typedef struct
{
  float32                         maxVehicleLength;
  HLATracking3DParametersPair_t   paramPairOncoming;
  HLATracking3DParametersPair_t   paramPairAhead;
  HLATracking3DParametersPair_t   paramPairTruckLights;
} HLATracking3DParametersPairing_t;

/*! typedef struct dist from height parameters */
typedef struct
{
  float32                         minDist;
  float32                         maxDist;
} HLATracking3DParametersDistFromHeight_t;

/*! typedef struct for ttb calculation */
typedef struct
{
  float32                         maxTTB;
} HLATracking3DParametersTTB_t;

/*! typedef struct egomotion estimation */

typedef struct
{
  HLATracking3DParametersCali_t              paramCali;          /* online cali parameters */
  HLATracking3DParametersEgomotion_t         paramEgomotion;     /* egomotion parameters */
  HLATracking3DParametersStaticTracker_t     paramStaticTracker; /* static tracker */
  HLATracking3DParametersDynamicTracker_t    paramDynamicTracker;/* dynamic tracker */
  HLATracking3DParametersMeasurement_t       paramMeasurement;   /* measurement */
  HLATracking3DParametersMatching_t          paramMatching;      /* data matching */
  HLATracking3DParametersAnalysis_t          paramAnalysis;      /* track analysis */
  HLATracking3DParametersBirth_t             paramBirth;         /* track birth */ 
  HLATracking3DParametersDeath_t             paramDeath;         /* track death */
  HLAHotPixelParameters_t                    paramHotPixel;      /* hot pixels */
  HLATracking3DParametersPairing_t           paramPair;          /* light pairs */ 
  HLATracking3DParametersDistFromHeight_t    paramDistFromHeight;/* dist from height */
  HLATracking3DParametersTTB_t               paramTTB;           /* ttb parameters */
}HLA_t_Tracking3DParameters;

/* Parameters for street lamps analysis */
#define SL_LP_ORDER_PLUS_ONE 6 /* Street Lamp Low Pass Filter Order*/
typedef struct       
{
  float32 Thresh_Max_Lux;
  float32 Thresh_Max_Var;
  float32 Thresh_Min_Delta_Lux;
  float32 Thresh_Min_Extremum;
  float32 Thresh_Max_Extremum;
  uint16 SL_MaxWidth;
  uint16 SL_MaxHeight;
  float32 Thresh_Min_Zw100;
}HLA_SL_Decision_t;

typedef struct
{
  /* Low Pass Filter Params */
  float32 LowPassFilterZeros[SL_LP_ORDER_PLUS_ONE];
  float32 LowPassFilterPoles[SL_LP_ORDER_PLUS_ONE];

  /* Distance Thresholds */
  float32 ThreshFarSL;
  float32 ThreshMiddleSL;

  /* */

  /* SL Decision dependant to distance */
  HLA_SL_Decision_t SL_Decision_Far;
  HLA_SL_Decision_t SL_Decision_Middle;
  HLA_SL_Decision_t SL_Decision_Close;

  /* Other SL Decision */
  sint16 Thresh_Min_Time_Diff;
  sint16 Thresh_Max_Time_Diff;
  sint16 Thresh_Max_Time_Diff2;
  float32 Thresh_Max_DeltaXw100;
  float32 Thresh_Max_DeltaYw100;
  float32 Thresh_Max_DeltaZw100;

  /* Confidence */
  sint8  ThreshSLConfNeg;
  uint8  ThreshSLConfPos;
  sint8  SLConf_Min;
  uint8  SLConf_Max;

  float32 MinSpeed_Direction;

  float32 minSpeed;
  float32 default_distance;
  float32 yawRateFilterConstant;
  float32 minYawRate;
  float32 minVelocity;
  float32 defaultRadius;

  float32 minRadius;
  float32 maxCentralAngle;

  uint16 minPixAboveHorizonEx;
  uint16 maxTrackTime;
  uint8 maxOuterStreetLampCount;
  float32 maxDistStreetLamp;
  float32 minHeightStreetLamp;

  sint8 ArrayConfPos[HLA_SLPARAM_ARRAYCONFIDENCE];
  sint8 ArrayConfNeg[HLA_SLPARAM_ARRAYCONFIDENCE];
}HLA_t_StreetLampsParam;

/* Parameters for chain of light analysis */
typedef struct
{
  /* Maximal distances to the line through upper and lower track relative to a reference track */
  float32 MaxDistToLine_UL;
  float32 CoeffMaxInt;
  /* multiplication factor used in distances comparison 
  to decide if distances are equal or not. 
  if ( d1 < MaxDistRatio * d2 && d2 < d1 * MaxDistRatio )
  then both distances are considered as equal */
  float32 MaxDistRatio;
  float32 MaxDist2_FarHor;
  float32 MaxDist2_CloseHor;
  sint16 MinDist_X_FarHor;
  sint16 MinDist_Y_FarHor;
  sint16 MinDist_X_CloseHor;
  sint16 MinDist_Y_CloseHor;
  sint16 MinDistUnderHor;
  sint16 MinDistAboveHor;
  uint16 maxDiffSize;
  uint16 maxTrackTimeDiff;
  uint8 minNbOfTrackInChain;
  sint8 Conf_max;
  sint8 Conf_min;
  sint8 Conf_stepPos;
  sint8 Conf_stepNeg;
  sint8 Conf_threshPos;
  sint8 Conf_threshNeg;
}HLA_t_ChainParam;

/*! Type definition for the red light parameters */
typedef struct
{
  float32   minRed_pos;
  float32   maxGreen_pos;
  float32   maxBlue_pos;
  float32   minInt;

  float32   minRed_neg;
  float32   maxGreen_neg;
  float32   maxBlue_neg;

  /* red light detection for city detection */
  float32   minRed_City;
  float32   maxGreen_City;
  float32   maxBlue_City;
  float32   minInt_City;
} HLA_t_AnalysisRedLightParameters;

typedef struct
{
  uint16    ttbBorder;
  float32   maxTTB;
  float32   ttbLowPassFactor;
} HLA_t_AnalysisTTB;

typedef struct  
{
  sint16 classResultSumMin;
  sint16 classResultSumMax;

  float32 lrf_outputOffset_XenonLED;
  float32 lrf_outputOffset_Halogen;
  float32 lrf_outputOffset_RedLight;
  float32 lrf_outputOffset_CityLight;

  float32 crtOncomingMin;
  float32 crtOncomingSizeMin;
  float32 crtOncomingSizeMax;
  float32 crtOncomingSizeC0;
  float32 crtOncomingSizeC1;
  float32 crtOncomingBrightnessMin;
  float32 crtOncomingBrightnessMax;
  float32 crtOncomingBrightnessC0;
  float32 crtOncomingBrightnessC1;
  float32 crtOncomingPositionMin;
  float32 crtOncomingPositionMax;
  float32 crtOncomingPositionC0;
  float32 crtOncomingPositionC1;

  float32 crtAheadMin;
  float32 crtAheadSizeMin;
  float32 crtAheadSizeMax;
  float32 crtAheadSizeC0;
  float32 crtAheadSizeC1;
  float32 crtAheadBrightnessMin;
  float32 crtAheadBrightnessMax;
  float32 crtAheadBrightnessC0;
  float32 crtAheadBrightnessC1;
  float32 crtAheadPositionMin;
  float32 crtAheadPositionMax;
  float32 crtAheadPositionC0;
  float32 crtAheadPositionC1;

  uint16 stickyMinTime;
} HLA_t_AnalysisIcon;

/*! Type definition for the analysis parameters */
typedef struct 
{
  float32                   tooBrightMinInt;

  float32                   aboveRoiTolerance_pix;

  float32                   contraMotionMinDist2FOE;
  float32                   contraMotionMinDisplacement;
  float32                   contraMotionLowerAlphaThresh;
  float32                   contraMotionUpperAlphaThresh;
  float32                   contraMotionMinIntensityLux;

  float32                   dynamicMotionMaxInt;

  float32                   closeReflectorMaxDistRange;
  float32                   closeReflectorMaxStaticDist;
  float32                   closeReflectorMaxIntensity;
  uint16                    closeReflectorMinTrackTime;
  float32                   closeReflectorStraightRoadMinRadius;
  uint8                     closeReflectorMinDist2FOE;

  float32                   staticHighDeltaYThresholdPos;
  float32                   staticHighDeltaYThresholdNeg;

  float32                   centerBrightLeftRightRad;
  float32                   centerBrightTopRad;
  float32                   centerBrightBottomRad;
  float32                   centerBrightMaxInt;

  float32                   lateralBrightMinInt;
  float32                   lateralBrightMaxInt;
  float32                   lateralBrightSlopeInt;

  float32                   extremeBrightMaxInt;
  float32                   extremeBrightMinInt;

  float32                   highwayBrightMinInt;
  float32                   highwayBrightMinTrackTime;
  sint16                    highwayBrightMinClassResult;

  float32                   highwayBrightMinIntTruckLights;       /* Min Intensity for the detection of Truck Lights */
  float32                   highwayBrightMinTrackTimeTruckLights; /* Min Track time for the detection of Truck Lights*/
  float32                   highwayBrightMinTrackDeltaX;

  /* Parameters for chain of light analysis */
  HLA_t_ChainParam hlaChainParam;

  /* Parameters for Street Lamps Analysis */
  HLA_t_StreetLampsParam hlaSLParam;
  
  /* Parameters for red light analysis */
  HLA_t_AnalysisRedLightParameters  RedLight;

  /* Parameters for TTB calculation*/
  HLA_t_AnalysisTTB         ttb;

  HLA_t_AnalysisIcon        icon;

} HLA_t_AnalysisParameters;


/*! size of leaving street lamp table */
#define HLA_CITY_NUM_STREETLAMP 10

/*! Type definition for the city detection parameters */
typedef struct 
{
  float32                 CityAccelFactorMax;                                  /* max factor apply to distance when decelerating */
  float32                 CityAccelFactorMin;                                  /* min factor apply to distance when decelerating */
  uint16                  maxDistTurnOnDelay100;                               /* [cm] min. distance after passing of last streetlamp to turn city state off */
  uint16                  minDistTurnOffDelay100;                              /* [cm] min. distance between two leaving street lamps */
  uint16                  minDistTurnOffDelayLeav100;                          /* [cm] min. distance between two leaving street lamps */
  uint16                  maxDistTurnOffDelay100;                              /* [cm] max. distance between two leaving street lamps */
  uint16                  maxDistTurnOffDelay100_LowInt;                       /* [cm] max. distance between two leaving street lamps */
  uint16                  mindistStreetLamp100;                                /* [cm] max. distance of potential streetlamp (light) to keep ctiy state ON */
  uint16                  maxdistStreetLamp100;                                /* [cm] max. distance of potential streetlamp (light) to keep ctiy state ON */
  float32                 MinIntensityStreetLampUpperRoi;                      /* [lux] minimum intensity to accept streetlamp and switch city mode ON if street lamp is in upper Roi*/
  float32                 MinIntensityStreetLamp;                              /* [lux] minimum intensity to accept streetlamp and switch city mode ON */
  float32                 MinIntensityStreetLampUpperRoi_Tunnel;               /* [lux] minimum intensity to accept streetlamp and switch city mode ON if street lamp is in upper Roi*/
  float32                 MinIntensityStreetLamp_Tunnel;                       /* [lx] minimum intensity to accept streetlamp and switch city mode ON */
  uint16                  sizeCorridor100;                                     /* [cm] [resolution: 0.1m] max. lateral offset between 2 street lamps of the same cluster */
  float32                 sizeCorridorTight100;                                /* [cm] [resolution: 0.1m] max. lateral offset between 2 street lamps of the same cluster in a tunnel */
  float32                 sizeCorridorLoose100;                                /* [cm] [resolution: 0.1m] max. lateral offset between 2 street lamps of the same cluster. Used for city 
                                                                                  confirmation on a street lamp far in the scene */
  uint16                  maxStreetLampY_Wide100;                              /* [cm] max. lateral offset of streetlamp for Ymax calculation */
  uint16                  maxStreetLampY_Narrow100;                            /* [cm] max. lateral offset of streetlamp for Ymax calculation */
  uint16                  maxStreetLampY_Tunnel100;                            /* [cm] max. lateral offset of streetlamp for Ymax calculation */
  float32                 minHeightAssumpSL;                                   /* minimal Height Assumption for Street Lamps */
  float32                 maxHeightAssumpSL;                                   /* maximal Height Assumption for Street Lamps */
  float32                 minSpeedHeightAssumpSL;                              /* minimal speed to modify Height Assumption for Street Lamps */
  float32                 maxSpeedHeightAssumpSL;                              /* maximal speed to modify Height Assumption for Street Lamps */
  float32                 minLeavingSLdistance;                                /* Distance after which Street Lamp are leaving */
  float32                 maxLeavingSLdistance;                                /* Distance after which Street Lamp are leaving */
  uint16                  maxDistInterStreetLamp100;
  float32                 maxDistInterStreetLampVariance;
  float32                 maxDistInterStreetLampVarianceShort;
  uint16                  maxStreetLampTunnelYw100;                            /* [cm] [resolution: 0.1m] max. lateral offset of streetlamp for tunnel street lamps */
  float32                 maxStreetLampTunnelYwVar;                            /* [m*m] max. lateral offset variance in a streetlamp straight line. Used for tunnel street lamps */
  float32                 maxVarRatio;                                         /* maximal variace tolerated ratio with mean value */
  uint16                  minStreetLampTunnelXwInter100;                       /* [cm] [resolution: 0.1m] min. distance between street lamps in a streetlamp straightline. Used for tunnel street lamps */
  uint16                  maxStreetLampTunnelXwInter100;                       /* [cm] [resolution: 0.1m] min. distance between street lamps in a streetlamp straightline. Used for tunnel street lamps */
  uint16                  minRoadYw100;                                        /* [cm] Minimal distance for two street lamps for being at different side of the road */
  uint16                  maxXwDist100_3dEst;                                  /* [cm] maximal frontal distance estimated by tracking */
  uint16                  maxYwDist100_3dEst;                                  /* [cm] maximal lateral distance estimated by tracking */
  uint16                  maxXwDist100_3dEst_Tunnel;                           /* [cm] maximal frontal distance estimated by tracking for tunnel */
  uint16                  maxYwDist100_3dEst_Tunnel;                           /* [cm] maximal lateral distance estimated by tracking for tunnel */
  uint16                  maxXwDist100_3dEstLeav;                              /* [cm] maximal frontal distance estimated by tracking */
  uint16                  maxYwDist100_3dEstLeav_Wide;                         /* [cm] maximal lateral distance estimated by tracking */
  uint16                  maxYwDist100_3dEstLeav_Narrow;                       /* [cm] maximal lateral distance estimated by tracking */
  uint16                  maxYwDist100_3dEstLeav_InCities;                     /* [cm] maximal lateral distance estimated by tracking when city is detected */  
  uint16                  minRadiusCityOn;                                     /* [cm] min. turn radius to count host movement for city ON detection */  
  uint16                  minDistInterStreetLampUnfiltered;
  float32                  minYwDistSide100;
  uint16                  minSLsize;
  uint16                  VarToConverge;
  uint16                  VarToDiverge;
  sint16                  minIconConf; 
  uint8                   numFramesSLSignalOnToOff;
  uint8                   numFramesSLSignalOffToOn;
  uint8                   minRadiusCityOff;                                    /* [cm] min. turn radius to count host movement for city OFF detection */
  uint8                   speedLimitLOW_HIGH;                                  /* [kmh] speed limit for LOW and HIGH mode for city detection */
  uint8                   AHBC_NASL_LOW;                                       /* number of leaving street lamp to detect city in LOW mode */
  uint8                   AHBC_NASL_HIGH;                                      /* number of leaving street lamp to detect city in HIGH mode */
  uint8                   AHBC_NSCENESL_LOW;                                   /* number of scene street lamp to detect city in LOW mode */
  uint8                   AHBC_NSCENESL_HIGH;                                  /* number of scene street lamp to detect city in HIGH mode */
  uint8                   AHBC_NSCENESL_TUNNEL;
  uint8                   SafetyGapTop;
  uint8                   SafetyGapSide;
  uint8                   minTrackTimeToReinit;
  float32                 minRadiusDelatYw;
  float32                 maxRadiusDelatYw;
  float32                 minDeltaYwCurve100;
  float32                 maxDeltaYwCurve100;
  uint16                  HighIntensityExtraGap100;                            /* Extra lateral gap allowance for leaving street lamps */
  float32                 luminousFluxMin;
  float32                 luminousFluxMax;
  sint16                  MinYwDist100;
  sint16                  MaxYwDist100;
  sint8                   MaxConfHighIntensityFlux;
  sint8                   MinConfHighIntensityFlux;
  sint8                   HighIntensityFluxThreshPositif;
  sint8                   HighIntensityFluxThreshNegative;
  uint16                  MaxDistToLeavCityInCurve100;                         /* Maximal driving distance without leaving city in curve */
  float32                 MaxRadius;                                           /* Radius which could lead to some bordering own lane street lamp not in the FOV */
  float32                 DeathAreaX;
  float32                 DeathAreaY;
  float32                 DeathAreaZ;
  uint8                   numSLInSceneLeaveCityJapan;                                /* num of SL needed to leave city - only valid when Japan CountryCode is set */
} HLA_t_CityDetectionParameters;


/*! Type definition for the street lamp identification parameters */
typedef struct 
{
  sint8                   contraMoverNegativeBound;
  sint8                   contraMoverPositiveBound;
  sint8                   contraMoverConfStepSize;
  sint8                   dynamicMotionNegativeBound;
  sint8                   dynamicMotionPositiveBound;
  sint8                   dynamicMotionConfStepSize;
  sint8                   tooBrightNegativeBound;
  sint8                   tooBrightPositiveBound;
  sint8                   tooBrightConfStepSize;
  sint8                   closeReflectorNegativeBound;
  sint8                   closeReflectorPositiveBound;
  sint8                   oncomingPairNegativeBound;
  sint8                   oncomingPairPositiveBound;
  sint8                   oncomingPairConfStepSize;
  sint8                   centerBrightNegativeBound;
  sint8                   centerBrightPositiveBound;
  sint8                   centerBrightConfStepSize;
  sint8                   lateralBrightNegativeBound;
  sint8                   lateralBrightPositiveBound;
  sint8                   lateralBrightConfStepSize;
  sint8                   otherColorNegativeBound;
  sint8                   otherColorPositiveBound;
  sint8                   otherColorConfStepSizeNormal;
  sint8                   otherColorConfStepSizeFast;
  sint8                   otherColorConfStepSizeNeutral;
  sint8                   whiteOrRedNegativeBound;
  sint8                   whiteOrRedPositiveBound;
  sint8                   whiteOrRedConfStepSize;
  sint8                   pulsedLightNegativeBound;
  sint8                   pulsedLightPositiveBound;
  sint8                   pulsedLightConfStepSize;
  sint8                   staticHighNegativeBound;
  sint8                   staticHighPositiveBound;
  sint8                   staticHighConfStepSize;
} HLA_t_IdentificationParameters;


typedef struct
{
  /* Oncoming Filtering Thresholds */
  sint16 FilterTracksMinDeltaX;
  sint16 FilterTracksMinDeltaY;
  float32 FilterTracksMinSpeed;/* [m/s] */
  uint16 FilterTracksMinTrackTime;
  float32 FilterTracksCurvature;

  /* Divided Rdway detection */
  float32 ThreshDividedRdwayXwUp;
  float32 ThreshDividedRdwayYwUp;
  float32 ThreshDividedRdwayZwUp;
  float32 ThreshDividedRdwayXwDown;
  float32 ThreshDividedRdwayYwDown;
  float32 ThreshDividedRdwayZwDown;
  float32 ThreshCurvatureDivided;

  /* Normal Rdway detection */
  float32 ThreshNormalRdwayXwDown;
  float32 ThreshNormalRdwayYwDown;
  float32 ThreshNormalRdwayZwDown;
  float32 ThreshNormalRdwayXwUp;
  float32 ThreshNormalRdwayYwUp;
  float32 ThreshNormalRdwayZwUp;

  /* Highway Detection */
  float32 HighwayThreshSpeedUp;
  float32 HighwayThreshSpeedDown;
  float32 HighwayThreshCurvatureUp;
  float32 HighwayThreshCurvatureDown;

  /* Occlusion Detection */
  float32 MinDeathAreaCoeff;
  uint16  ThreshPrematureCount;
  float32 OcclusionDelay;
  float32 ThreshPreDeathCoeff;

  /* Confidence */
  float32 StepConfDvdRdway;
  float32 StepConfCtryRdway;
  float32 StepConfOccl;
  float32 StepConfOcclDtcd;
  float32 StepConfHway;
  float32 MinConf;
  float32 MaxConf;
  float32 TreshConfDividedRdway;
  float32 TreshConfNormalRdway;
  float32 ThreshDistToLastOncoming;
  float32 ThreshDistHwayDction;

  /* Highway Exit */
  float32 ThreshCurvatureExit;
  float32 ThreshDistExit;
  float32 ThreshYawIntegrate;
  float32 CurvMinSpeed;

  /* Maybe Highway */
  float32 MaybeHwayConfOccl;
  float32 MaybeHwayConfRdwayType;

  /* Min confidence for transition: idle/country road -> highway */
  float32 minConfTrans;

  /* Min Speed for Decision */
  float32 minSpeedThresh; /*[m/s]*/

  /* Highway Speed Detection */
  float32 HighwaySpeedThreshHigh;
  float32 HighwaySpeedThreshLow;
  float32 ThreshDistHwaySpeedDction;
  float32 HighwaySpeedExitThresh;
}HLA_t_HighwayParameters;

typedef struct
{
  float32                   trafficStyleMinDeltaX;
  sint32                    trafficStyleHysteresis;
  sint16                    trafficStyleCountDiscard;
  sint16                    trafficStyleCountLock;
  float32                   trafficStyleMinTrackSecs;               /*!< minimal track time [s] */
  float32                   trafficStyleSpeedFactor;
  float32                   trafficStyleYawRateFactor;
  float32                   trafficStyleMinSpeed;
  float32                   trafficStyleStepThresh;
  float32                   minOdometerLock;
}HLA_t_TrafficStyleParameters;

/*! Chain of Light */

#define NB_OF_TRACKS 100
#define NB_OF_CHAINS 10
#define MAX_LENGTH_CHAIN 32


/**********************************************
 ***            TUNNEL DETECTION            ***
 **********************************************/

/* Tunnel detection defines */
#define TUNNEL_FEATURE_LENGTH   21
#define TUNNEL_FEATURE_NUMBER   10
#define TUNNEL_THRESHOLD_NUMBER  3

#define TUNNEL_FEATURES_NEXT_GEN SWITCH_OFF

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern const HLABrightnessParameters_t                hlaBrightnessParameters;
extern const HLA_t_AnalysisParameters                 hlaAnalysisParameters;
extern const HLA_t_IdentificationParameters           hlaIdentParam;
extern const HLA_t_HighwayParameters                  hlaHighwayParams;
extern const HLA_t_SegmentationParameters             hlaSegmentationParameters;
extern const HLA_t_Tracking3DParameters               hlaTracking3DParameters;
extern const HLA_t_CityDetectionParameters            hlaCityDetectionParameters;
extern const HLA_t_TrafficStyleParameters             hlaTrafficStyleParameters;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

#endif /* #ifndef HLA_CFG_INCLUDED */
