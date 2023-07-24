/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysisicon.c

  DESCRIPTION:            Extract and classify an image area (icon)

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-04-04

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysisicon.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:42CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:56CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:15CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.224 2014/03/28 10:36:19CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:19 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.223 2014/03/28 10:04:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed scons warnings
  CHANGE:                 Removed compiler warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:04:42 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.222 2014/03/26 11:27:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:27 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.221 2014/03/25 19:11:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:48 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.220 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysisicon.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysisicon.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.219 2014/03/24 18:33:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed boost assert
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 24, 2014 6:33:29 PM CET]
  CHANGE:                 Change Package : 207432:44 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.218 2014/03/22 10:28:20CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added project specific defines
  CHANGE:                 Replaced defines for CORE by predefined ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:20 AM CET]
  CHANGE:                 Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.217 2014/03/19 16:30:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:22 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.216 2014/03/18 16:15:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Made some symbols not static
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 18, 2014 4:15:36 PM CET]
  CHANGE:                 Change Package : 207432:22 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.215 2014/03/13 10:10:50CET Glebov, Roman (uidg4759) 
  CHANGE:                 Added Penalty when a light is a part of a chain of light:
  CHANGE:                 in this case when there is a positive classification result the (half of the length)*SCALE_FACTOR
  CHANGE:                 is substracted
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 13, 2014 10:10:50 AM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.214 2014/03/12 18:07:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:33 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.213 2014/03/11 15:43:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took cfg_project.h into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:40 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.212 2014/03/10 13:20:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:45 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.211 2014/03/04 16:51:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:49 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.210 2014/02/28 15:51:19CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 - make HLAIconNormalize and HLAIconCheckSaturation global static for usage inicon generator tool
  CHANGE:                 - pass pointer in HLAIconFillAdditionalFeatures instead global array for usage inicon generator tool
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 28, 2014 3:51:20 PM CET]
  CHANGE:                 Change Package : 217405:1 http://mks-psad:7002/im/viewissue?selection=217405
  CHANGE:                 Revision 1.209 2014/02/18 13:21:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:54 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.208 2014/02/11 09:20:15CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed time meas
  CHANGE:                 Fixed dframe calculation on HIL
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:16 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.207 2014/02/07 09:49:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:49:56 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.206 2014/02/06 16:02:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:43 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.205 2014/01/28 17:18:26CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 fixed reset of skipped bad position
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 5:18:26 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.204 2014/01/28 11:46:52CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 -fixed: use only global add features
  CHANGE:                 -remove unused parameter
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 11:46:53 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.203 2014/01/28 10:48:09CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 -renaming of some unclear variables
  CHANGE:                 -changes to meet coding guideline
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:10 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.202 2014/01/23 14:46:18CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 moving additional features array to global position to solve QAC error
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 23, 2014 2:46:19 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.201 2014/01/21 09:12:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:52 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.200 2014/01/17 10:58:57CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 analysis2 clean up
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 17, 2014 10:58:58 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.199 2014/01/16 14:29:17CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 remove defines:
  CHANGE:                 HLA_COLOR_USE_OPTIMIZED_CODE 
  CHANGE:                 HLA_HEADLIGHTTYPE_HALOGE
  CHANGE:                 HLA_HEADLIGHTTYPE_XENON_LED
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 16, 2014 2:29:17 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.198 2014/01/15 17:20:00CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 clean up Level2 Analysis
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 15, 2014 5:20:01 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.197 2014/01/13 16:57:44CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 clean up 2nd level analysis
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 13, 2014 4:57:44 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.196 2014/01/13 13:02:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 13, 2014 1:02:49 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.195 2014/01/10 18:33:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:24 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.194 2014/01/05 22:50:31CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicit conversion from int to unsigned int and float32 to double and vise versa removed
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:50:31 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.193 2013/12/18 15:14:35CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 detect HighwayOncomingTruckLights as isHighwayOncomingCar
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:14:35 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.192 2013/12/13 16:45:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:09 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.191 2013/11/21 17:53:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:49 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.190 2013/11/21 11:48:40CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 moved LRF classifier to separate header files
  CHANGE:                 --- Added comments ---  uidv8776 [Nov 21, 2013 11:48:40 AM CET]
  CHANGE:                 Revision 1.189.1.2 2013/11/21 13:37:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:35 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.189.1.1 2013/11/12 13:45:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added restrict keyword
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:47 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.189 2013/08/26 15:34:54CEST Schillinger, Patrick (uidv8776) 
  CHANGE:                 reduce additional features to reduce negative influence on laser light
  CHANGE:                 --- Added comments ---  uidv8776 [Aug 26, 2013 3:34:55 PM CEST]
  CHANGE:                 Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include <math.h>
#ifdef PC_SIM
#include <assert.h>
#endif

#include "hla_analysisicon.h"
#include "hla_camera.h"
#include "hla_imager.h"
#include "hla_icon.h"
#include "hla_trackmeas.h"

#ifdef HLA_LRF_ON_EVE
#include "glob_comp_id.h"
#include "hla_main.h"
#include "hla_eve_ext.h"
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* ~CodeReview ~ID:5e14a283029c2ab4efa74f3f31dd5d28 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:document members */
typedef struct
{
  uint8 x;
  uint8 y;
} HLAReGrow_Pixel_t;

typedef struct
{
  uint16 count;                     /* number of items on stack */
  ARRAY(HLAReGrow_Pixel_t, HLA_ICON_REGROW_PIXEL_STACK_SIZE, item);
} HLAReGrow_PixelStack_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
/* Defined in hla_lrf_xenonled.c */
extern const HlaLrfInputsXenonLED_t HlaLrfInputsXenonLED;
/* Defined in hla_lrf_halogen.c */
extern const HlaLrfInputsHalogen_t HlaLrfInputsHalogen;
/* Defined in hla_lrf_redlight.c */
extern const HlaLrfInputsRedLight_t HlaLrfInputsRedLight;
/* Defined in hla_lrf_citylight.c */
extern const HlaLrfInputsCityLight_t HlaLrfInputsCityLight;
/* Defined in hla_lrf_tanhlut.c */
#ifdef HLA_LRF_ON_EVE
extern const sint32 TanhLuTInterleaved[HLA_EVE_LRF_TANH_LUT_INTERLEAVED_SIZE];
#else
extern const ARRAY(HlaTanhLUT_t, HLA_ICON_TANH_LOOKUP_TABLE_SIZE, tanhLUT);
#endif

HLADebugIconList_t    hlaDebugIconList;

/* array for preprocessed image of icon */
#ifdef HLA_LRF_ON_EVE
/* We have to make sure that end of lrf inputs and start of icon buffer is 128 bytes aligned due to cache invalidation/edma transfer */
#pragma DATA_ALIGN (iconPreProcImage,  HLA_DSP_CACHE_LINE_SIZE)
//#pragma DATA_SECTION   (iconPreProcImage, ".memsec_shared_data_eve")
#endif
HLA_GLOBAL_STATIC ARRAY(uint8, HLA_ICON_WINDOW_WIDTH * HLA_ICON_WINDOW_HEIGHT + 96u, iconPreProcImage); /* 96 padding bytes to be aligned to HLA_DSP_CACHE_LINE_SIZE */
/* preProcImage box position (the color part) extracted from full icon */
static uint8 brightBoxColorLeft;
static uint8 brightBoxColorTop;
/* array for segmentation image of preprocessed icon */
static ARRAY(uint8, HLA_ICON_COLORIMAGE_WIDTH * HLA_ICON_COLORIMAGE_HEIGHT, iconPreProcSegmentationImage);

/* array for the additional features */
static ARRAY(sint32, HLA_ICON_ADDITIONAL_FEATURES, additionalFeatures);

/* array for the 8-bit normalized image of icon */
#ifdef HLA_LRF_ON_EVE
/* We have to make sure that end of icon buffer is 128 bytes aligned due to cache invalidation */
#pragma DATA_ALIGN (iconNormalized,  HLA_DSP_CACHE_LINE_SIZE)
#endif
static ARRAY(uint8, HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y, iconNormalized);

#ifdef HLA_LRF_ON_EVE
#pragma DATA_ALIGN (HlaLrfHiddenNeuronsHigh, HLA_DSP_CACHE_LINE_SIZE)
static sint32 HlaLrfHiddenNeuronsHigh[HLA_EVE_LRF_NUM_EVE_OUTPUTS + 16u];   /* 4 * 16 = 64 -> 64 padding bytes needed to be aligned to HLA_DSP_CACHE_LINE_SIZE */
#pragma DATA_ALIGN (HlaLrfHiddenNeuronsLow, HLA_DSP_CACHE_LINE_SIZE)
static uint32 HlaLrfHiddenNeuronsLow[HLA_EVE_LRF_NUM_EVE_OUTPUTS + 16u];   /* 4 * 16 = 64 -> 64 padding bytes needed to be aligned to HLA_DSP_CACHE_LINE_SIZE */
#pragma DATA_ALIGN (EVETimeMeas, HLA_DSP_CACHE_LINE_SIZE)
static HLAEveTimeMeas_t EVETimeMeas;
#endif

static sint64 HlaLrfHiddenNeurons[HLA_ICON_LRF_HIDDEN_NEURONS];

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

/*! hla icon identification */
static void HLAIconIdentification( const HLAIconData_t*                         pIcon,
                                   const HLAR_t_RequiredInputs*                 pRequiredIn,
                                   const HLACameraData_t*                       pCamData,
                                   const HLATracking3DParametersMeasurement_t*  pTracking3DParamsMeasurement,
                                   const AS_t_ServiceFuncts*                    Services,
                                   const HLA_t_Highway*                         pHighwayData,
                                   const HLA_t_AnalysisParameters*              pAnalysisParamIn,
                                         HLADebugOutputs_t*                     phlaDebugOutputs,
                                         HLAAnalysisData_t*                     pAnalysisData
                                 );


HLA_GLOBAL_STATIC void HLAIconNormalize( const HLA_t_CameraParameter*  pCameraParameter,
                                                const t_PixelData* restrict   pSrcData,
                                                const uint8                   srcWidth,
                                                const uint8                   srcHeight,
                                                const HLAIconData_t* restrict pIcon,
                                                      uint8* restrict         pDstData
                                              );

static void HLAIconPreProcess( const HLA_t_eBayerPatternType  e_bayerPattern, 
                               const uint8*                   pSrcData,
                               const HLAIconData_t*           pIcon,
                               const uint8                    srcWidth, 
                               const uint8                    srcHeight,                
                               const float32                  lightPosX,
                               const float32                  lightPosY,
                                     uint8*                   pDstData
                             );

HLA_GLOBAL_STATIC IconResultInfo_t HLAIconCheckSaturation(const HLAIconData_t* pIcon);

HLA_GLOBAL_STATIC void HLAIconFillAdditionalFeatures( const HLACameraData_t*        pCamData,
                                                      const HLATrack_t*             pTrack,
                                                      const float32                 lightPosY,
                                                      sint32*                       addFeatures
                                                    );

static IconResultInfo_t HLAIconRunLRFClassifier( const HlaLrfTypes_t        lrfType,
                                                 const float32              lrf_outputOffset,
                                                 const AS_t_ServiceFuncts*  Services,
                                                       HLADebugOutputs_t*   phlaDebugOutputs,
                                                       HLAAnalysisData_t*   pAnalysisData
                                                );

static void HLAIconPrepareInputs( const HLAIconData_t*          pIcon,
                                  const HLAR_t_RequiredInputs*  pRequiredIn,
                                  const HLACameraData_t*        pCamData,
                                  const HLATrack_t*             pTrack,
                                  const float32                 lightPosX,
                                  const float32                 lightPosY,
                                        HLATimeMeasurement_t*   pTimeMeasurement,
                                        AS_t_GetTimestampuS32   pfGetTimestampuS32
                                 );

static void HLAIdentificationPotVehOncoming2ndLevel( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                                           HLATrack_t*                pTrack );

static void HLAIdentificationPotVehAhead2ndLevel( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                                        HLATrack_t*               pTrack );

static void HLAAnalysisPotVeh2ndLevelInit( const uint32                 driveDistCm,
                                                 HLATrack_t*            pTrack
                                         );

static void HLAAnalysisPotVeh2ndLevelSuddentlyAppearingVehicle( const HLASegLineRegion_t*     pLevel2Region,
                                                                const HLATracking3DOutput_t*  pHlaTrackOut,
                                                                      HLATrack_t*             pTrack
                                                              );

static void HLAAnalysisPotVeh2ndLevelHighwayOncomingCar( const HLATracking3DOutput_t*     pHlaTrackOut,
                                                         const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                                         HLATrack_t*                      pTrack
                                                       );

static void HLAAnalysisPotVeh2ndLevelClassificationResultReachedOncoming( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                                                          const HLACameraData_t*          pCamData,
                                                                          const float32                   size,
                                                                                HLATrack_t*               pTrack
                                                                        );

static void HLAAnalysisPotVeh2ndLevelClassificationResultReachedAhead( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                                                       const HLACameraData_t*           pCamData,
                                                                       const float32                    size,
                                                                             HLATrack_t*                pTrack
                                                                     );

static void HLAAnalysisPotVeh2ndLevelDrivenDistanceReached( const HLAAnalysisData_t*  pAnalysisData,
                                                                  HLATrack_t*         pTrack );

static void HLAAnalysisPotVeh2ndLevelIsOvertaker( const HLACameraData_t*    pCamData,
                                                  const HLASegLineRegion_t* pLevel2Region,
                                                        HLATrack_t*         pTrack
                                                );

static HLASegLineRegion_t* HLAAnalysisPotVeh2ndLevelSearchRegion2( const HLATrack_t* pTrack );

static uint32 HLAAnalysisPotVeh2ndLevelCalculateDrivenDistance( const HLAR_t_RequiredInputs* pRequiredIn );

static float32 HLAAnalysisPotVeh2ndLevelCalculateSize( const HLASegLineRegion_t* pLevel2Region);

static void HLAIconIdentificationInit( HLATrack_t* pTrack );

static void HLAIconIdentificationCalcAndVerifyPosition( const HLAIconData_t*                        pIcon,
                                                        const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                                                              HLATrack_t*                           pTrack,
                                                              HLAKalmanMeasPosPix_t*                lightPosPix
                                                      );



/*! hla icon led light detector */
static void HLAReGrow_Push(HLAReGrow_PixelStack_t* pixelStack, uint8 x, uint8 y);
static HLAReGrow_Pixel_t HLAReGrow_Pop(HLAReGrow_PixelStack_t* pixelStack);
static boolean HLAReGrow_Empty(const HLAReGrow_PixelStack_t* pixelStack);
static void HLARegionGrowing(uint8 startX, uint8 startY, uint8 minIntensity, boolean greenPixel);
static IconResultInfo_t HLAIconLedLightDetection(const HLA_t_eBayerPatternType e_bayerPattern, const HLAIconData_t* pIcon);



/* **************************************************************************** 
  Functionname:     HLAAnalysisIconInit                                */ /*!  
  Description:      hla icon classification initialization


  @param[in]        -

  @return           -
  @pre              -
  @post             -
  @author           Matthias Mutschler
**************************************************************************** */
void HLAAnalysisIconInit()
{
#ifdef ICON_MEASFREEZE
  (void)memset((void*)&hlaDebugIconList, 0, sizeof(hlaDebugIconList));
#endif
}

/* **************************************************************************** 
  Functionname:     HLAIconClassification                                */ /*!  
  Description:      hla icon classification


  @param[in]        seg_TrackListnode*          pTrack_Start

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
void HLAIconClassification( const HLAR_t_RequiredInputs*                pRequiredIn,
                            const HLATracking3DOutput_t*                pHlaTrackOut,
                            const HLACameraData_t*                      pCamData,
                            const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                            const AS_t_ServiceFuncts*                   Services,
                            const HLA_t_Highway*                        pHighwayData,
                            const HLA_t_AnalysisParameters*             pAnalysisParamIn,
                                  HLAAnalysisData_t*                    pAnalysisData,
                                  HLAIconData_t*                        IconData,
                                  HLADebugOutputs_t*                    phlaDebugOutputs
                          )
{
  HLATrack_t* pTrack = pHlaTrackOut->pTrack;
  uint8 i;

  /* Reset time meas */
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel2ndNormalize_us = 0;
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel2ndPreProcess_us = 0;
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel2ndLRF_us = 0;

#ifdef ICON_MEASFREEZE
  hlaDebugIconList.count = 0;
#endif


  /* Init the Icon Identification:
   * update cycle count for all potential vehicle and city tracks
   * and count classResultSum back to zero when first level analysis becomes inactive */
  while (pTrack != NULL)
  { 
    HLAIconIdentificationInit( pTrack );
    
    /* go to next object */
    pTrack = pTrack->next;
  }
  
  /* process all valid icon handles */
  for ( i=0; i<HLA_ICON_ANALYSIS_MAX_BOXES; i++ )
  {
    HLAIconData_t* pIcon = &IconData[i];

    if(pIcon->eState == ICON_STATE_DATA_VALID)
    { /* data valid -> start icon processing (normalization, pre processing and classification) */
      HLAIconIdentification( pIcon, 
                             pRequiredIn,
                             pCamData,
                             pTracking3DParamsMeasurement,
                             Services,
                             pHighwayData,
                             pAnalysisParamIn,
                             phlaDebugOutputs,
                             pAnalysisData
                           );

      /* set IconState to Idle TODO schillinger: replace IconState by Boolean  */
      pIcon->eState = ICON_STATE_IDLE;
    }    
  }


  /* set 2nd level potential vehicle state
   * check for all tracks if general classification result is reached 
   * or if a bypass condition is met */
  pTrack = pHlaTrackOut->pTrack;

  /* calculate the driven distance since last frame */
  const uint32 driveDistCm = HLAAnalysisPotVeh2ndLevelCalculateDrivenDistance( pRequiredIn );

  /* analyze potential vehicles Level2 criteria */
  while (pTrack != NULL)
  {
    HLASegLineRegion_t* pLevel2Region = NULL;
    float32 size = 0;

    /* initialize the potential 2nd Level vehicle analysis.
     * update driven distance and reset flags */
    HLAAnalysisPotVeh2ndLevelInit( driveDistCm, pTrack );
    
    /* check criteria used for vehicles oncoming and ahead and calculate level2 region and size of light */
    if (    (pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1)
         || (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
       )
    {
      /* search for level 2 region and set pLevel2Region if available */
      pLevel2Region = HLAAnalysisPotVeh2ndLevelSearchRegion2( pTrack );

      /* calculate the size of the light size = width+height of pLevel2Region */
      size = HLAAnalysisPotVeh2ndLevelCalculateSize( pLevel2Region );

      /* Bypass for suddenly appearing vehicle: very bright whole life time, big light */
      HLAAnalysisPotVeh2ndLevelSuddentlyAppearingVehicle( pLevel2Region, pHlaTrackOut, pTrack );   
    }

    /* check criteria for potential vehicles oncoming */
    if (pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1)
    {
      /* Bypass for Oncoming Cars and Oncoming Trucks on Highway */
      HLAAnalysisPotVeh2ndLevelHighwayOncomingCar( pHlaTrackOut, pAnalysisParamIn, pTrack );

      /* check if classification result is reached for oncoming cars */
      HLAAnalysisPotVeh2ndLevelClassificationResultReachedOncoming( pAnalysisParamIn, pCamData, size, pTrack );

      /* Identify potential oncoming vehicle 2nd Level */
      HLAIdentificationPotVehOncoming2ndLevel( pAnalysisParamIn, pTrack);
    }

    /* check criteria for potential vehicles ahead */
    if (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
    {
      /* check if classification result is reached for preceding cars */
      HLAAnalysisPotVeh2ndLevelClassificationResultReachedAhead( pAnalysisParamIn, pCamData, size, pTrack );

      /* bypass for preceding tracks which are followed a long distance without becoming a preceding vehicle  */
      HLAAnalysisPotVeh2ndLevelDrivenDistanceReached( pAnalysisData, pTrack );

      /* bypass for overtaking vehicles */
      HLAAnalysisPotVeh2ndLevelIsOvertaker( pCamData, pLevel2Region, pTrack ); 

      /* Identify potential preceding vehicle 2nd Level */
      HLAIdentificationPotVehAhead2ndLevel( pAnalysisParamIn, pTrack );
    }
      
    /* go to next object */
    pTrack = pTrack->next;
  }

}


/* **************************************************************************** 
  Functionname:     HLAIconIdentification                                */ /*!  
  Description:      hla icon identification


  @param[in]        void

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIconIdentification( const HLAIconData_t*                         restrict pIcon,
                                   const HLAR_t_RequiredInputs*                 restrict pRequiredIn,
                                   const HLACameraData_t*                       restrict pCamData,
                                   const HLATracking3DParametersMeasurement_t*  restrict pTracking3DParamsMeasurement,
                                   const AS_t_ServiceFuncts*                             Services,
                                   const HLA_t_Highway*                         restrict pHighwayData,
                                   const HLA_t_AnalysisParameters*                       pAnalysisParamIn,
                                         HLADebugOutputs_t*                     restrict phlaDebugOutputs,
                                         HLAAnalysisData_t*                              pAnalysisData                                         
                                  )
{
  HLATrack_t* pTrack = (HLATrack_t*)pIcon->pRef;
  HLAKalmanMeasPosPix_t lightPosPix;
    
  if (pTrack != NULL)
  {   
    /* TODO schillinger: CHECK if distinction between vehicle Icon and City Icon is really needed */
    
    if (pTrack->iconState.status.iconRequested == 1)
    { /* reset the icon status flags */
      pTrack->iconState.status.ledDetectionCalled = 0;
      pTrack->iconState.status.streetLampDetectionCalled = 0;
      pTrack->iconState.status.redLightDetectionCalled = 0;
      pTrack->iconState.status.skippedBadPosition = 0;
    }

    if (pTrack->iconStateCity.status.iconRequested == 1)
    { /* reset the icon status flags */
      pTrack->iconStateCity.status.ledDetectionCalled = 0;
      pTrack->iconStateCity.status.streetLampDetectionCalled = 0;
      pTrack->iconStateCity.status.redLightDetectionCalled = 0;
      pTrack->iconStateCity.status.skippedBadPosition = 0;
    }


    /* calculate the position of the light in the image (world- to pix-coordinates)
     * and verify the position in the icon
     * if not verified skippedBadPosition is set */
    if (   (pTrack->iconState.status.iconRequested == 1)
        || (pTrack->iconStateCity.status.iconRequested == 1)
       )
    {
      HLAIconIdentificationCalcAndVerifyPosition( pIcon, pTracking3DParamsMeasurement, pTrack , &lightPosPix );
    }

    /* if a valid vehicle-icon or a valid city-icon is requested for analysis,
     * prepare the inputs for Icon Classification */
    if(    ( (pTrack->iconState.status.skippedBadPosition == 0)     && (pTrack->iconState.status.iconRequested == 1) ) 
        || ( (pTrack->iconStateCity.status.skippedBadPosition == 0) && (pTrack->iconStateCity.status.iconRequested == 1) )
      )
    {
      /* J.Häfer: Misra Rule 9.1 unset variabel isn't possible, set in HLAIconIdentificationCalcAndVerifyPosition */
      /* PRQA S 3353 6 */
      HLAIconPrepareInputs( pIcon, 
                            pRequiredIn,
                            pCamData,
                            pTrack,
                            lightPosPix.x_center_pix, 
                            lightPosPix.y_center_pix,
                            &phlaDebugOutputs->timeMeas,
                            Services->pfGetTimestampuS32
                          );
    }

    /* this is a normal vehicle classification icon and Icon-position is valid */
    if (   (pTrack->iconState.status.iconRequested == 1)
        && (pTrack->iconState.status.skippedBadPosition == 0)
       )
    { 
      /* reset the Icon requested flag */
      pTrack->iconState.status.iconRequested = 0;

      /* reset the icon no classification cycle counter */
      pTrack->iconState.cyclesNoClass = 0;

      /* increase the icon classification counter */
      pTrack->iconState.classCnt = CML_Min( pTrack->iconState.classCnt + 1u , UI8_T_MAX );
        
      /* check if light in Icon is in saturation */
      pTrack->iconState.resultInfo = HLAIconCheckSaturation(pIcon);

      /* if light in Icon is not saturated run default classifier */
      if (pTrack->iconState.resultInfo.result != HLA_ICONRESULT_SATURATED)
      {

        /* if HeadLightType is Halogen, run default classifier for Halogen light */
        if (pRequiredIn->s_Par.s_HlaPar.Headlight.HeadLightType == RTE_HLA_LTYPE_HALOGENE)
        {
          pTrack->iconState.resultInfo = HLAIconRunLRFClassifier( HlaLrfInputsHalogen.lrfType,
                                                                  pAnalysisParamIn->icon.lrf_outputOffset_Halogen,
                                                                  Services,
                                                                  phlaDebugOutputs,
                                                                  pAnalysisData
                                                                 );
        }
        /* else Xenon or LED headlamp is in use => run default classifier for Xenon and LED light */
        else
        {
          pTrack->iconState.resultInfo = HLAIconRunLRFClassifier( HlaLrfInputsXenonLED.lrfType,
                                                                  pAnalysisParamIn->icon.lrf_outputOffset_XenonLED,
                                                                  Services,
                                                                  phlaDebugOutputs,
                                                                  pAnalysisData
                                                                 ); 
        }
      }

#ifdef ICON_MEASFREEZE
      hlaDebugIconList.debugIcon[hlaDebugIconList.count].defaultClassifierResult = pTrack->iconState.resultInfo.result;
#endif

      /* check for LED pulsed light criteria:
        * if Analysis1 detected isPulsedLight
        * and NOT red colored
        * and NOT moving non white object
        * and no potential vehicle on Level1
        * and analysis1 result state of Pulsed Light detection is positive
        *
        * or the current Icon Classification result is negative
        *    and the analysis1 Identification confidence for pulsed light detection is positive */
      if ( 
              (    (pTrack->statusAnalysisVehicle.isPulsedLight == 1)
                && (pTrack->statusAnalysisVehicle.isRed == 0)
                && (pTrack->statusAnalysisVehicle.isRed2 == 0)
                && (pTrack->statusAnalysisVehicle.isMovingNonWhite == 0)
                && (pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 0)
                && (pTrack->anaResStat.isPulsedLight.result == HLA_RESULT_POSITIVE)
              )
            || (    (pTrack->iconState.resultInfo.result == HLA_ICONRESULT_NEGATIVE)
                && (pTrack->idResStat.isPulsedLight.confidence > 0)
              )
          )
      {
        /* check for LED pulsed light harder criteria TODO schillinger clean testversion and kill magic number
            do not check for LED when light is moving down 
            while light is above horizon to prevent check on LED signs) */
        if(  !((pTrack->delta_y_lp_lt <= 0.3 )&&(pTrack->statusAnalysisMisc.isAboveHorizon == 1)) )
        {
          pTrack->iconState.resultInfo = HLAIconLedLightDetection(pRequiredIn->s_Par.s_CameraParameter.e_bayerPattern, pIcon);
          pTrack->iconState.status.ledDetectionCalled = 1;
        }
            
            
      }
      /* if default classifier result is positive check for special red active light classifier pre condition */
      else if (pTrack->iconState.resultInfo.result == HLA_ICONRESULT_POSITIVE)
      {
        /* light was detected Red in the current frame
          * or the confidence of the color is pointing to red
          * or the light is detected as pulsed light */
        if (    (pTrack->RedLightCnt > 5)
             || (pTrack->idResStat.isWhiteOrRed.confidence < 0) 
             || (pTrack->statusAnalysisVehicle.isPulsedLight == 1)
           )
        { 
          /* the light must be higher than horizon and not linked as pair
              or the light must be higher than horizon and highway is detected */
          if (    (pTrack->statusAnalysisMisc.isAboveHorizon == 1)
               && (    (    (pTrack->TrackingStatus.isLinked2Pair   == 0)
                          && (pTrack->TrackingStatus.isTrackedInPair == 0)
                        )
                    || (pHighwayData->e_HighwayOutInternal == RTE_HLAF_MTWY_MOTORWAY)
                  )
             )
          {
            /* start additional classification against active red lights (i.e. red traffic lights) */
            pTrack->iconState.resultInfo = HLAIconRunLRFClassifier( HlaLrfInputsRedLight.lrfType, 
                                                                    pAnalysisParamIn->icon.lrf_outputOffset_RedLight,
                                                                    Services,
                                                                    phlaDebugOutputs,
                                                                    pAnalysisData
                                                                   );
            pTrack->iconState.status.redLightDetectionCalled = 1;
          }
        }
      }
      else
      {
        /* Do nothing when red pulse light criteria analysis failed */
      }

      /* add vehicle icon classifier result to class result sum */
      switch( pTrack->iconState.resultInfo.result )
      {
        case HLA_ICONRESULT_NEGATIVE:
          pTrack->iconState.classResultSum = CML_Max( pTrack->iconState.classResultSum + pTrack->iconState.resultInfo.classResponse , pAnalysisParamIn->icon.classResultSumMin );       
          pTrack->iconState.status.successiveNegResultCnt = CML_Min ( pTrack->iconState.status.successiveNegResultCnt + 1u , 3u);
          pTrack->iconState.status.successivePosResultCnt = 0u;
          break;

        case HLA_ICONRESULT_POSITIVE:
          pTrack->iconState.classResultSum = CML_Min( pTrack->iconState.classResultSum + pTrack->iconState.resultInfo.classResponse , pAnalysisParamIn->icon.classResultSumMax );
          pTrack->iconState.status.successivePosResultCnt = CML_Min ( pTrack->iconState.status.successivePosResultCnt + 1u , 3u);
          pTrack->iconState.status.successiveNegResultCnt = 0u;
          break;

        case HLA_ICONRESULT_SATURATED:
          pTrack->iconState.classResultSum = CML_Min( pTrack->iconState.classResultSum + HLA_ICON_RESULT_POS_CLASS_RESPONSE , pAnalysisParamIn->icon.classResultSumMax );
          pTrack->iconState.status.successivePosResultCnt = CML_Min ( pTrack->iconState.status.successivePosResultCnt + 1u , 3u);
          pTrack->iconState.status.successiveNegResultCnt = 0u;
          break;

        default:
          break;
      }
        
#ifdef ICON_MEASFREEZE
        hlaDebugIconList.debugIcon[hlaDebugIconList.count].trackID = pTrack->TrackID;
        hlaDebugIconList.debugIcon[hlaDebugIconList.count].pos = pIcon->Pos;
        hlaDebugIconList.debugIcon[hlaDebugIconList.count].cityIcon = b_FALSE;
        hlaDebugIconList.debugIcon[hlaDebugIconList.count].iconState = pTrack->iconState;
        memcpy(hlaDebugIconList.debugIcon[hlaDebugIconList.count].iconPreProcImage, &iconPreProcImage[0], sizeof(uint8) * HLA_ICON_WINDOW_WIDTH * HLA_ICON_WINDOW_HEIGHT);
        memcpy(hlaDebugIconList.debugIcon[hlaDebugIconList.count].iconPreProcSegmentationImage, &iconPreProcSegmentationImage[0], sizeof(uint8) * HLA_ICON_COLORIMAGE_WIDTH * HLA_ICON_COLORIMAGE_HEIGHT);
        hlaDebugIconList.count++;
#endif

    }

    /* this is a city classification icon and Icon-position is valid */
    if (   (pTrack->iconStateCity.status.iconRequested == 1)
        && (pTrack->iconStateCity.status.skippedBadPosition == 0)
       )
    {
      /* reset the icon requested flag */
      pTrack->iconStateCity.status.iconRequested = 0;

      /* reset the icon no classification cycle counter */
      pTrack->iconStateCity.cyclesNoClass = 0;

      /* increase the icon classification counter */
      pTrack->iconStateCity.classCnt = CML_Min( pTrack->iconStateCity.classCnt + 1u , UI8_T_MAX );

      /* get classification result of city classifier */
      pTrack->iconStateCity.resultInfo = HLAIconRunLRFClassifier( HlaLrfInputsCityLight.lrfType, 
                                                                  pAnalysisParamIn->icon.lrf_outputOffset_CityLight,
                                                                  Services,
                                                                  phlaDebugOutputs,
                                                                  pAnalysisData
                                                                 );

      /* add city icon classifier result to class result sum */
      switch( pTrack->iconStateCity.resultInfo.result )
      {
        case HLA_ICONRESULT_NEGATIVE:
          pTrack->iconStateCity.classResultSum = CML_Max( pTrack->iconStateCity.classResultSum + pTrack->iconStateCity.resultInfo.classResponse , pAnalysisParamIn->icon.classResultSumMin );
          pTrack->iconStateCity.status.successiveNegResultCnt = CML_Min( pTrack->iconStateCity.status.successiveNegResultCnt + 1u , 3u);
          pTrack->iconStateCity.status.successivePosResultCnt = 0;
          break;

        case HLA_ICONRESULT_POSITIVE:
          pTrack->iconStateCity.classResultSum = CML_Min( pTrack->iconStateCity.classResultSum + pTrack->iconStateCity.resultInfo.classResponse , pAnalysisParamIn->icon.classResultSumMax );
          pTrack->iconStateCity.status.successivePosResultCnt = CML_Min( pTrack->iconStateCity.status.successivePosResultCnt + 1u , 3u);
          pTrack->iconStateCity.status.successiveNegResultCnt = 0;
          break;

        case HLA_ICONRESULT_SATURATED:
          pTrack->iconStateCity.classResultSum = pAnalysisParamIn->icon.classResultSumMax;
          break;

        default:
          break;
      }
       
#ifdef ICON_MEASFREEZE
          hlaDebugIconList.debugIcon[hlaDebugIconList.count].pos = pIcon->Pos;
          hlaDebugIconList.debugIcon[hlaDebugIconList.count].cityIcon = b_TRUE;
          hlaDebugIconList.debugIcon[hlaDebugIconList.count].iconState = pTrack->iconStateCity;
          hlaDebugIconList.debugIcon[hlaDebugIconList.count].defaultClassifierResult = pTrack->iconStateCity.resultInfo.result;
          memcpy(hlaDebugIconList.debugIcon[hlaDebugIconList.count].iconPreProcImage, &iconPreProcImage[0], sizeof(uint8) * HLA_ICON_WINDOW_WIDTH * HLA_ICON_WINDOW_HEIGHT);
          memcpy(hlaDebugIconList.debugIcon[hlaDebugIconList.count].iconPreProcSegmentationImage, &iconPreProcSegmentationImage[0], sizeof(uint8) * HLA_ICON_COLORIMAGE_WIDTH * HLA_ICON_COLORIMAGE_HEIGHT);
          hlaDebugIconList.count++;
#endif

    }

  }
}

/* **************************************************************************** 
  Functionname:     HLAIconNormalize                                     */ /*!  
  @description:     Normalize the 12 bit icon image to a 8-bit logarithmic 
                    image by applying the imager characteristic

  @param[in]        uint8* pSrcData             pointer to input image
  @param[in]        uint8 srcWidth              width of input image
  @param[in]        uint8 srcHeight             height of input image
  @param[out]       uint8* pDstData             pointer to output image
  @param[in]        HLAIconData_t* pIcon        pointer to icon data

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
HLA_GLOBAL_STATIC void HLAIconNormalize( const HLA_t_CameraParameter*  pCameraParameter,
                                                const t_PixelData* restrict   pSrcData,
                                                const uint8                   srcWidth,
                                                const uint8                   srcHeight,
                                                const HLAIconData_t* restrict pIcon,
                                                uint8* restrict               pDstData
                                               )
{
  const uint8 srcWidth_2 = srcWidth/2;
  const uint8 srcHeight_2 = srcHeight/2;

  const uint8 patternH = (uint8)(((uint32)(pCameraParameter->e_bayerPattern) % 2) + pIcon->Pos.X1) % 2;
  const uint8 patternV = (uint8)(((uint32)(pCameraParameter->e_bayerPattern) / 2) + pIcon->Pos.Y1) % 2;

  uint32 x, y;

  if ((patternH == 1) && (patternV == 0))
  {


#ifdef _TMS320C6X
    const uint16 greyValueBlacklevelGreen = hlaImagerPar.ui16Blacklevel_G_Greyvalue;
    const uint16 greyValueBlacklevelRed   = hlaImagerPar.ui16Blacklevel_R_Greyvalue;
    const uint16 greyValueBlacklevelBlue  = hlaImagerPar.ui16Blacklevel_B_Greyvalue;
    const uint16 greyValueKneepoint1      = hlaImagerPar.ui16Kneepoint1_Greyvalue;
    const uint16 greyValueKneepoint2      = hlaImagerPar.ui16Kneepoint2_Greyvalue;
    const uint16 greyValueSaturation      = hlaImagerPar.ui16Saturation_Greyvalue;

    #pragma MUST_ITERATE(HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2, HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2, HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2)
    for (y = 0; y < srcHeight_2; y++)
    {
      const t_PixelData* pSrcDataTemp = pSrcData;
      uint8* pDstDataTemp = pDstData;

      /* Process green/red pixels (upper row of bayer pattern) */
      #pragma UNROLL(2)
      #pragma MUST_ITERATE(HLA_ICON_ANALYSIS_MAX_SIZE_X / 2, HLA_ICON_ANALYSIS_MAX_SIZE_X / 2, HLA_ICON_ANALYSIS_MAX_SIZE_X / 2)
      for (x = 0; x < srcWidth_2; x++)
      {
        /* Load grey values of pixels */
        const t_PixelData pix0 = *pSrcDataTemp;          /* Green pixel */
        const t_PixelData pix1 = *(pSrcDataTemp + 1u);   /* Red pixel */

        /* Check whether pix0..pix1 are between black level and kneepoint1 */
        const boolean pix0BelowKneepoint1 = (boolean)((pix0 < greyValueKneepoint1) & (pix0 >= greyValueBlacklevelGreen));
        const boolean pix1BelowKneepoint1 = (boolean)((pix1 < greyValueKneepoint1) & (pix1 >= greyValueBlacklevelRed));

        /* Check whether pix0..pix1 are between kneepoint1 and kneepoint2 */
        const boolean pix0BelowKneepoint2 = (boolean)((pix0 < greyValueKneepoint2) & (pix0 >= greyValueKneepoint1));
        const boolean pix1BelowKneepoint2 = (boolean)((pix1 < greyValueKneepoint2) & (pix1 >= greyValueKneepoint1));

        /* Check whether pix0..pix1 are between kneepoint2 and saturation */
        const boolean pix0BelowSaturation = (boolean)((pix0 < greyValueSaturation) & (pix0 >= greyValueKneepoint2));
        const boolean pix1BelowSaturation = (boolean)((pix1 < greyValueSaturation) & (pix1 >= greyValueKneepoint2));

        /* Only pix0BelowKneepoint1 OR pix0BelowKneepoint2 OR pix0BelowSaturation is TRUE */

        /* Calculate difference of gray values to next kneepoint */
        const sint32 pix0DiffKneepoint = (pix0BelowKneepoint1 * (pix0 - greyValueBlacklevelGreen))
                                       + (pix0BelowKneepoint2 * (pix0 - greyValueKneepoint1))
                                       + (pix0BelowSaturation * (pix0 - greyValueKneepoint2));
        const sint32 pix1DiffKneepoint = (pix1BelowKneepoint1 * (pix1 - greyValueBlacklevelRed))
                                       + (pix1BelowKneepoint2 * (pix1 - greyValueKneepoint1))
                                       + (pix1BelowSaturation * (pix1 - greyValueKneepoint2));

        /* Calculate lookupBin for pix0..pix3 */
        const sint32 pix0LookUpBin = (pix0BelowKneepoint1 * (pix0DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2))
                                   + (pix0BelowKneepoint2 * (pix0DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2))
                                   + (pix0BelowSaturation * (pix0DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2));
        const sint32 pix1LookUpBin = (pix1BelowKneepoint1 * (pix1DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2))
                                   + (pix1BelowKneepoint2 * (pix1DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2))
                                   + (pix1BelowSaturation * (pix1DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2));

        /* Look up lux calculation parameters */
        const HLAImagerLogLuxLookupTable* pix0LUT = (HLAImagerLogLuxLookupTable*)
                                                    ((pix0BelowKneepoint1 * (sint32)&hlaImagerPar.logLuxLookupTableGreenKnee1[pix0LookUpBin])
                                                  + (pix0BelowKneepoint2 * (sint32)&hlaImagerPar.logLuxLookupTableGreenKnee2[pix0LookUpBin])
                                                  + (pix0BelowSaturation * (sint32)&hlaImagerPar.logLuxLookupTableGreenKnee3[pix0LookUpBin]));
        const HLAImagerLogLuxLookupTable* pix1LUT = (HLAImagerLogLuxLookupTable*)
                                                    ((pix1BelowKneepoint1 * (sint32)&hlaImagerPar.logLuxLookupTableRedKnee1[pix1LookUpBin])
                                                  + (pix1BelowKneepoint2 * (sint32)&hlaImagerPar.logLuxLookupTableRedKnee2[pix1LookUpBin])
                                                  + (pix1BelowSaturation * (sint32)&hlaImagerPar.logLuxLookupTableRedKnee3[pix1LookUpBin]));

       /* Calculate lux values and store them */
       *pDstDataTemp        = (uint8)CML_Min(UI8_T_MAX, (uint16)(pix0LUT->offset + (pix0DiffKneepoint * pix0LUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
       *(pDstDataTemp + 1u) = (uint8)CML_Min(UI8_T_MAX, (uint16)(pix1LUT->offset + (pix1DiffKneepoint * pix1LUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);

        /* Move address pointers to next block */
        pDstDataTemp += 2u;
        pSrcDataTemp += 2u;
      }

      /* Move pointers to next row */
      pDstDataTemp = pDstData + srcWidth;
      pSrcDataTemp = pSrcData + srcWidth;

      /* Process blue/green pixels (lower row of bayer pattern) */
#pragma UNROLL(2)
#pragma MUST_ITERATE(HLA_ICON_ANALYSIS_MAX_SIZE_X / 2, HLA_ICON_ANALYSIS_MAX_SIZE_X / 2, HLA_ICON_ANALYSIS_MAX_SIZE_X / 2)
      for (x = 0; x < srcWidth_2; x++)
      {
        /* Load grey values of pixels */
        const t_PixelData pix2 = *pSrcDataTemp;         /* Blue pixel */
        const t_PixelData pix3 = *(pSrcDataTemp + 1u);  /* Green pixel */

        /* Check whether pix2..pix3 are between black level and kneepoint1 */
        const boolean pix2BelowKneepoint1 = (boolean)((pix2 < greyValueKneepoint1) & (pix2 >= greyValueBlacklevelBlue));
        const boolean pix3BelowKneepoint1 = (boolean)((pix3 < greyValueKneepoint1) & (pix3 >= greyValueBlacklevelGreen));

        /* Check whether pix2..pix3 are between kneepoint1 and kneepoint2 */
        const boolean pix2BelowKneepoint2 = (boolean)((pix2 < greyValueKneepoint2) & (pix2 >= greyValueKneepoint1));
        const boolean pix3BelowKneepoint2 = (boolean)((pix3 < greyValueKneepoint2) & (pix3 >= greyValueKneepoint1));

        /* Check whether pix2..pix3 are between kneepoint2 and saturation */
        const boolean pix2BelowSaturation = (boolean)((pix2 < greyValueSaturation) & (pix2 >= greyValueKneepoint2));
        const boolean pix3BelowSaturation = (boolean)((pix3 < greyValueSaturation) & (pix3 >= greyValueKneepoint2));

        /* Only pix0BelowKneepoint1 OR pix0BelowKneepoint2 OR pix0BelowSaturation is TRUE */

        /* Calculate difference of gray values to next kneepoint */
        const sint32 pix2DiffKneepoint = (pix2BelowKneepoint1 * (pix2 - greyValueBlacklevelBlue))
                                       + (pix2BelowKneepoint2 * (pix2 - greyValueKneepoint1))
                                       + (pix2BelowSaturation * (pix2 - greyValueKneepoint2));
        const sint32 pix3DiffKneepoint = (pix3BelowKneepoint1 * (pix3 - greyValueBlacklevelGreen))
                                       + (pix3BelowKneepoint2 * (pix3 - greyValueKneepoint1))
                                       + (pix3BelowSaturation * (pix3 - greyValueKneepoint2));

        /* Calculate lookupBin for pix0..pix3 */
        const sint32 pix2LookUpBin = (pix2BelowKneepoint1 * (pix2DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2))
                                   + (pix2BelowKneepoint2 * (pix2DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2))
                                   + (pix2BelowSaturation * (pix2DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2));
        const sint32 pix3LookUpBin = (pix3BelowKneepoint1 * (pix3DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE1_TABLE_BINSIZE_LOG2))
                                   + (pix3BelowKneepoint2 * (pix3DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE2_TABLE_BINSIZE_LOG2))
                                   + (pix3BelowSaturation * (pix3DiffKneepoint >> HLA_IMAGER_LOGLUX_KNEE3_TABLE_BINSIZE_LOG2));

        /* Look up lux calculation parameters */
        const HLAImagerLogLuxLookupTable* pix2LUT = (HLAImagerLogLuxLookupTable*)
                                                    ((pix2BelowKneepoint1 * (sint32)&hlaImagerPar.logLuxLookupTableBlueKnee1[pix2LookUpBin])
                                                  + (pix2BelowKneepoint2 * (sint32)&hlaImagerPar.logLuxLookupTableBlueKnee2[pix2LookUpBin])
                                                  + (pix2BelowSaturation * (sint32)&hlaImagerPar.logLuxLookupTableBlueKnee3[pix2LookUpBin]));
        const HLAImagerLogLuxLookupTable* pix3LUT = (HLAImagerLogLuxLookupTable*)
                                                    ((pix3BelowKneepoint1 * (sint32)&hlaImagerPar.logLuxLookupTableGreenKnee1[pix3LookUpBin])
                                                  + (pix3BelowKneepoint2 * (sint32)&hlaImagerPar.logLuxLookupTableGreenKnee2[pix3LookUpBin])
                                                  + (pix3BelowSaturation * (sint32)&hlaImagerPar.logLuxLookupTableGreenKnee3[pix3LookUpBin]));

        /* Calculate lux values and store them */
        *pDstDataTemp        = (uint8)CML_Min(UI8_T_MAX, (uint16)(pix2LUT->offset + (pix2DiffKneepoint * pix2LUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);
        *(pDstDataTemp + 1u) = (uint8)CML_Min(UI8_T_MAX, (uint16)(pix3LUT->offset + (pix3DiffKneepoint * pix3LUT->scale)) >> HLA_IMAGER_LOGLUX_FIXPOINT_SCALE_LOG2);

        /* Move address pointers to next block */
        pDstDataTemp += 2u;
        pSrcDataTemp += 2u;
      }

      /* Move pointer to next row */
      pDstData += 2u * srcWidth;
      pSrcData += 2u * srcWidth;
    }
#else
    for (y = 0; y < srcHeight_2; y++)
    {
      for (x = 0; x < srcWidth_2; x++)
      {
        *pDstData = HLAImager_GetLogLux_Green(*pSrcData);
        pSrcData++;
        pDstData++;
        *pDstData = HLAImager_GetLogLux_Red(*pSrcData);
        pSrcData++;
        pDstData++;
      }

      for (x = 0; x < srcWidth_2; x++)
      {
        *pDstData = HLAImager_GetLogLux_Blue(*pSrcData);
        pSrcData++;
        pDstData++;
        *pDstData = HLAImager_GetLogLux_Green(*pSrcData);
        pSrcData++;
        pDstData++;
      }
    }
#endif
  }
  else
  {
#ifdef PC_SIM
    assert(1);
#endif
  }
}

/* **************************************************************************** 
  Functionname:     HLAIconPreProcess                                    */ /*!  
  @description:     Preprocessing for icon. Generates a new image which is the
                    one passed to the classifier

  @param[in]        uint8* pSrcData             pointer to input image
  @param[in]        uint8 srcWidth              width of input image
  @param[in]        uint8 srcHeight             height of input image
  @param[out]       uint8* pDstData             pointer to output image
  @param[in]        uint8 dstWidth              width of output image
  @param[in]        uint8 dstHeight             height of output image
  @param[in]        HLAIconData_t* *pIcon       pointer to icon data

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIconPreProcess(  const HLA_t_eBayerPatternType e_bayerPattern, 
                                const uint8* restrict         pSrcData,
                                const HLAIconData_t* restrict pIcon,
                                const uint8                   srcWidth, 
                                const uint8                   srcHeight,                                                       
                                const float32                 lightPosX,
                                const float32                 lightPosY,
                                      uint8* restrict         pDstData
                             )
{
  static uint8 brightBoxSubsampledLeft;
  static uint8 brightBoxSubsampledTop;

  uint8 x, y;

  {
    /* estimate the extracted bright box centered on the brightest pixel */
    uint8 patternH;
    uint8 patternV;

    uint8 brightestColorValue = 0;
    uint8 brightestColorX = srcWidth/2;
    uint8 brightestColorY = srcHeight/2;

    uint8 brightestSubsampledValue = 0;
    uint8 brightestSubsampledX = srcWidth/2;
    uint8 brightestSubsampledY = srcHeight/2;

    const uint8 startX = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_WIDTH  / 2, srcWidth  - (HLA_ICON_FULLIMAGE_WIDTH  / 2), (CML_s_Round2Int(lightPosX) - pIcon->Pos.X1) - HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);
    const uint8 endX   = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_WIDTH  / 2, srcWidth  - (HLA_ICON_FULLIMAGE_WIDTH  / 2), ((sint32)lightPosX - pIcon->Pos.X1) + HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);
    const uint8 startY = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_HEIGHT / 2, srcHeight - (HLA_ICON_FULLIMAGE_HEIGHT / 2), (CML_s_Round2Int(lightPosY) - pIcon->Pos.Y1) - HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);
    const uint8 endY   = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_HEIGHT / 2, srcHeight - (HLA_ICON_FULLIMAGE_HEIGHT / 2), ((sint32)lightPosY - pIcon->Pos.Y1) + HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);

    /* find the brightest pixel close to the center of the source image */
    for (y = startY; y <= endY; y++)
    {
      const uint8* pSrc = pSrcData + (y * srcWidth) + startX;
      const uint8* pSrcBelow = pSrc + srcWidth;

      for (x = startX; x <= endX; x++)
      {
        const uint8 colorValue = *pSrc;
        const uint8 subsampledValue = (*(pSrc) + *(pSrc+1) + *(pSrcBelow) + *(pSrcBelow+1)) / 4;

        if (colorValue > brightestColorValue)
        {
          brightestColorValue = colorValue;
          brightestColorX = x;
          brightestColorY = y;
        }

        if (subsampledValue > brightestSubsampledValue)
        {
          brightestSubsampledValue = subsampledValue;
          brightestSubsampledX = x;
          brightestSubsampledY = y;
        }

        pSrc++;
        pSrcBelow++;
      }
    }

    brightBoxColorLeft = brightestColorX - (HLA_ICON_COLORIMAGE_WIDTH/2);
    brightBoxColorTop = brightestColorY - (HLA_ICON_COLORIMAGE_HEIGHT/2);

    patternH = (uint8)(((uint32)(e_bayerPattern) % 2) + pIcon->Pos.X1 + brightBoxColorLeft) % 2;
    patternV = (uint8)(((uint32)(e_bayerPattern) / 2) + pIcon->Pos.Y1 + brightBoxColorTop ) % 2;

    if (patternH == 1)
    {
      brightBoxColorLeft++;
    }
    if (patternV == 1)
    {
      brightBoxColorTop++;
    }

    brightBoxSubsampledLeft = brightestSubsampledX - (HLA_ICON_FULLIMAGE_WIDTH/2);
    brightBoxSubsampledTop = brightestSubsampledY - (HLA_ICON_FULLIMAGE_HEIGHT/2);
  }

  {
    uint8* pDst = pDstData;

    for (y = 0; y < HLA_ICON_COLORIMAGE_HEIGHT; y++)
    {
      const uint8* pSrc = pSrcData + ((brightBoxColorTop + y) * srcWidth) + brightBoxColorLeft;

      for (x = 0; x < HLA_ICON_COLORIMAGE_WIDTH; x++)
      {
        *pDst = *pSrc;
        pDst++;
        pSrc++;
      }
    }

    for (y = 0; y < (HLA_ICON_FULLIMAGE_HEIGHT/2); y++)
    {
      const uint8* pSrc = pSrcData + ((brightBoxSubsampledTop + (2*y)) * srcWidth) + brightBoxSubsampledLeft;
      const uint8* pSrcBelow = pSrc + srcWidth;

      for (x = 0; x < (HLA_ICON_FULLIMAGE_WIDTH/2); x++)
      {
        *pDst = (*(pSrc) + *(pSrc+1) + *(pSrcBelow) + *(pSrcBelow+1)) / 4;
        pDst++;
        pSrc += 2;
        pSrcBelow += 2;
      }
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLAIconCheckSaturation                                    */ /*!  
  @description:     Check if icon contains multiple saturated pixels

**************************************************************************** */
HLA_GLOBAL_STATIC IconResultInfo_t HLAIconCheckSaturation(const HLAIconData_t* pIcon)
{
  HLATrack_t* pTrack = (HLATrack_t*)pIcon->pRef;
  IconResultInfo_t resultInfo;
  resultInfo.result = HLA_ICONRESULT_NEGATIVE;
  resultInfo.classResponse = 0;

  if (pTrack->statusAnalysisMisc.isFarAboveHorizon == 0)
  {
    uint8 x, y;
    uint16 satPixelCount = 0;
    const uint16 satLevel = HLAImager_GetSaturation();

    for (y = 0; y < HLA_ICON_COLORIMAGE_HEIGHT; y++)
    {
      const t_PixelData* ptrIcon = pIcon->pData + ((brightBoxColorTop + y) * pIcon->Pos.Width) + brightBoxColorLeft;

      for (x = 0; x < HLA_ICON_COLORIMAGE_WIDTH; x++)
      {
        if (*ptrIcon >= satLevel)
        {
          satPixelCount++;
        }

        ptrIcon++;
      }
    }

    if (satPixelCount >= 6)
    {
      resultInfo.result = HLA_ICONRESULT_SATURATED;
    }
  }

  return resultInfo;
}

/* **************************************************************************** 
  Functionname:     HLAIconFillAdditionalFeatures                         */ /*!  
  Description:      fill the additionalFeatures vector with useful information
                    from HLA detectors outside the icon classifier

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
HLA_GLOBAL_STATIC void HLAIconFillAdditionalFeatures( const HLACameraData_t*        restrict pCamData,
                                                      const HLATrack_t*             restrict pTrack,
                                                      const float32                          lightPosY,
                                                      sint32*                                addFeatures
                                                    )
{
  float32 tmpFloat32;

  /* calculate relative distance of y light position from y-Focus */
  tmpFloat32 = (lightPosY - pCamData->FOE_y) * (HLA_ICON_LRF_FIXPOINT_SCALE / 200.0f);

  /* [0]: relative distance of light's y-position from y-Focus */
  addFeatures[0] = CML_MinMax(-HLA_ICON_LRF_FIXPOINT_SCALE, HLA_ICON_LRF_FIXPOINT_SCALE, (sint32)tmpFloat32);

  /* [1]: absolute distance of light's y-position from y-Focus */
  addFeatures[1] = abs(addFeatures[0]);

  /* [2]: dynamic motion result: negative = MIN , positive = MAX , else = 0 */
  addFeatures[2] = ( (uint8) pTrack->anaResStat.isDynamicMotion.result  == HLA_RESULT_NEGATIVE) ? 
    -HLA_ICON_LRF_FIXPOINT_SCALE : 
    (( (uint8) pTrack->anaResStat.isDynamicMotion.result   == HLA_RESULT_POSITIVE) ?
          HLA_ICON_LRF_FIXPOINT_SCALE : 
          0 );

  /* [3]: static high result: negative = MIN , positive = MAX , else = 0 */
  addFeatures[3] = ( (uint8) pTrack->anaResStat.isStaticHigh.result     == HLA_RESULT_NEGATIVE) ?
    -HLA_ICON_LRF_FIXPOINT_SCALE : 
    (( (uint8) pTrack->anaResStat.isStaticHigh.result      == HLA_RESULT_POSITIVE) ? 
          HLA_ICON_LRF_FIXPOINT_SCALE : 
          0 );

  /* [4]: confidence of Street Lamp identification */
  addFeatures[4] = pTrack->idResStat.isStreetLamp.confidence         * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [5]: confidence of Chain of Light identification */
  addFeatures[5] = pTrack->idResStat.isChainOfLights.confidence      * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [6]: confidence of White or Red color identification */
  addFeatures[6] = pTrack->idResStat.isWhiteOrRed.confidence         * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [7]: confidence of Static High identification */
  addFeatures[7] = pTrack->idResStat.isStaticHigh.confidence         * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [8]: Is Bright Object: positive = MAX , negative = 0 */
  addFeatures[8] = (pTrack->statusAnalysisMisc.isBrightObject                == 1) ? HLA_ICON_LRF_FIXPOINT_SCALE : 0;
  
}

/* **************************************************************************** 
  Functionname:     HLAIconRunLRFClassifier                                */ /*!  
  Description:      Run LRF classifier on iconPreProcImage

  @param[in]        HLAIconClassifier_t*    Trained classifier

  @return           IconResultInfo_t
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static IconResultInfo_t HLAIconRunLRFClassifier( const HlaLrfTypes_t        lrfType,
                                                 const float32              lrf_outputOffset,
                                                 const AS_t_ServiceFuncts*  Services,
                                                       HLADebugOutputs_t*   phlaDebugOutputs,
                                                       HLAAnalysisData_t*   pAnalysisData
                                                )
{
  IconResultInfo_t       resultInfo;
  uint32                 TimeStart_us;
  uint8                  lrf_NRF;
  const sint32*          lrf_hiddenNeuronWeights;
  const float32*         lrf_outputNeuronWeights;

#ifdef HLA_LRF_ON_EVE
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(TanhLuTInterleaved);
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(iconPreProcImage);
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(HlaLrfHiddenNeuronsLow);
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(HlaLrfHiddenNeuronsHigh);
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(EVETimeMeas);

  AS_t_EVEContainer lrfEveContainer;
  HLAEveLrfParams_t lrfEveParams;
  sint32            lrfEveHandle;
  uint32            lrfEveReturnCode;
  uint8             retValEveTrigger = 0;
  uint8             retValEveWait    = 0;
  void*             pLrfInputStruct;
  uint16            sizeLrfInputStruct;
  uint32            i;
#else
  const sint32*          lrf_TH;
  const sint32*          lrf_RF;
  const sint32 dd  = (HLA_ICON_WINDOW_WIDTH - HLA_ICON_LRF_FS) + 1;
  const sint32 dd0 = HLA_ICON_LRF_DS*(HLA_ICON_WINDOW_WIDTH - HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH);
  sint32 f;
#endif

  TimeStart_us = Services->pfGetTimestampuS32();

#ifdef HLA_LRF_ON_EVE

  /* Take LRF parameters from global structure */
  switch (lrfType)
  {
  case LRF_TYPE_HALOGEN:
    lrf_NRF                  = HlaLrfInputsHalogen.lrf_NRF;
    lrf_hiddenNeuronWeights  = &HlaLrfInputsHalogen.lrf_hiddenNeuronWeights[0];
    lrf_outputNeuronWeights  = &HlaLrfInputsHalogen.lrf_outputNeuronWeights[0];
    pLrfInputStruct          = (void *) &HlaLrfInputsHalogen;
    sizeLrfInputStruct       = sizeof(HlaLrfInputsHalogen);
    break;
  case LRF_TYPE_REDLIGHT:
    lrf_NRF                  = HlaLrfInputsRedLight.lrf_NRF;
    lrf_hiddenNeuronWeights  = &HlaLrfInputsRedLight.lrf_hiddenNeuronWeights[0];
    lrf_outputNeuronWeights  = &HlaLrfInputsRedLight.lrf_outputNeuronWeights[0];
    pLrfInputStruct          = (void *) &HlaLrfInputsRedLight;
    sizeLrfInputStruct       = sizeof(HlaLrfInputsRedLight);
    break;
  case LRF_TYPE_CITYLIGHT:
    lrf_NRF                  = HlaLrfInputsCityLight.lrf_NRF;
    lrf_hiddenNeuronWeights  = &HlaLrfInputsCityLight.lrf_hiddenNeuronWeights[0];
    lrf_outputNeuronWeights  = &HlaLrfInputsCityLight.lrf_outputNeuronWeights[0];
    pLrfInputStruct          = (void *) &HlaLrfInputsCityLight;
    sizeLrfInputStruct       = sizeof(HlaLrfInputsCityLight);
    break;
  /* use XENON_LED as default */
  case LRF_TYPE_XENONLED:
  default:
    lrf_NRF                  = HlaLrfInputsXenonLED.lrf_NRF;
    lrf_hiddenNeuronWeights  = &HlaLrfInputsXenonLED.lrf_hiddenNeuronWeights[0];
    lrf_outputNeuronWeights  = &HlaLrfInputsXenonLED.lrf_outputNeuronWeights[0];
    pLrfInputStruct          = (void *) &HlaLrfInputsXenonLED;
    sizeLrfInputStruct       = sizeof(HlaLrfInputsXenonLED);
    break;
  } 

  /* Initialization */
  lrfEveHandle              = 0;
  lrfEveReturnCode          = 0;

  /* Fill Eve Params */
  lrfEveParams.lrfType = (uint8)lrfType;
  lrfEveParams.numRFs  = (uint8)lrf_NRF;

  /* Setup eve container for Lrf */
  lrfEveContainer.u_VersionNumber                  = HLA_EVE_INTERFACE_VERSION_NUMBER;
  lrfEveContainer.eveParams.u_LocalFuncID          = HLA_EVE_FUNC_ID_LRF;
  lrfEveContainer.eveParams.parBuf.p_Buff          = (void*) &lrfEveParams;
  lrfEveContainer.eveParams.parBuf.u_BuffLength    = sizeof(lrfEveParams);
  /* source buffer pointer pointing to start of interleaved tanh look-up table */
  lrfEveContainer.eveParams.srcBuf[0].p_Buff       = (void*) (&TanhLuTInterleaved[0]);
  lrfEveContainer.eveParams.srcBuf[0].u_BuffLength = sizeof(TanhLuTInterleaved);
  /* source buffer pointer pointing to start of pre-processed icons array */
  lrfEveContainer.eveParams.srcBuf[1].p_Buff       = (void*) (&iconPreProcImage[0]);
  lrfEveContainer.eveParams.srcBuf[1].u_BuffLength = sizeof(iconPreProcImage);
  /* source buffer pointer pointing to start of lrf input struct */
  lrfEveContainer.eveParams.srcBuf[2].p_Buff       = pLrfInputStruct;
  lrfEveContainer.eveParams.srcBuf[2].u_BuffLength = sizeLrfInputStruct;
  /* destination buffer pointer pointing to start hidden neurons array */
  lrfEveContainer.eveParams.dstBuf[0].p_Buff       = (void*) &EVETimeMeas;
  lrfEveContainer.eveParams.dstBuf[0].u_BuffLength = sizeof(EVETimeMeas);
  lrfEveContainer.eveParams.dstBuf[1].p_Buff       = (void*) &HlaLrfHiddenNeuronsLow[0];
  lrfEveContainer.eveParams.dstBuf[1].u_BuffLength = sizeof(HlaLrfHiddenNeuronsLow);
  lrfEveContainer.eveParams.dstBuf[2].p_Buff       = (void*) &HlaLrfHiddenNeuronsHigh[0];
  lrfEveContainer.eveParams.dstBuf[2].u_BuffLength = sizeof(HlaLrfHiddenNeuronsHigh);

  /* Write back pre-processed icon since it was modified recently */
  Services->pfCacheWbInv((void *) &iconPreProcImage[0], sizeof(iconPreProcImage));

  /* Stop time measurement before calling EVE */
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel2ndLRF_us += (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

  /* Call EVE to run lrf classifier on that icon */
  retValEveTrigger = Services->pfEVETrigger(&lrfEveContainer, &lrfEveHandle, COMP_ID_HLA);
  retValEveWait = Services->pfEVEWait(lrfEveHandle, (sint32*)&lrfEveReturnCode);

  /* Start time measurement again */
  TimeStart_us = Services->pfGetTimestampuS32();



  /* Invalidate caches of output buffers so that we fetch eve's output buffers properly */
  Services->pfCacheInv((void*) &HlaLrfHiddenNeuronsLow[0], sizeof(HlaLrfHiddenNeuronsLow));
  Services->pfCacheInv((void*) &HlaLrfHiddenNeuronsHigh[0], sizeof(HlaLrfHiddenNeuronsHigh));
  Services->pfCacheInv((void*) &EVETimeMeas, sizeof(EVETimeMeas));

  /* Handle EVE output*/
  phlaDebugOutputs->timeMeasEve.dTimeEve_us            += EVETimeMeas.dTimeEve_us;
  phlaDebugOutputs->timeMeasEve.dTimeEveLrf_us         += EVETimeMeas.dTimeEve_us;
  phlaDebugOutputs->timeMeasEve.dTimeEveLrfInit_us     += EVETimeMeas.dTimeEveLrfInit_us;
  phlaDebugOutputs->timeMeasEve.dTimeEveLrfMain_us     += EVETimeMeas.dTimeEveLrfMain_us;
  phlaDebugOutputs->timeMeasEve.dTimeEveLrfMainEdma_us += EVETimeMeas.dTimeEveLrfMainEdma_us;
  phlaDebugOutputs->timeMeasEve.dTimeEveLrfMainVcop_us += EVETimeMeas.dTimeEveLrfMainVcop_us;
  phlaDebugOutputs->timeMeasEve.dTimeEveLrfExit_us     += EVETimeMeas.dTimeEveLrfExit_us;

  /* first element is not handled by EVE */
  HlaLrfHiddenNeurons[0] = (sint64)HLA_ICON_LRF_FIXPOINT_SCALE * (sint64)(*lrf_hiddenNeuronWeights);
  /* accumulate eve's hidden neurons */
  for (i = 0; i < HLA_EVE_LRF_NUM_EVE_OUTPUTS; i++)
  {
    HlaLrfHiddenNeurons[0] += ((sint64)HlaLrfHiddenNeuronsHigh[i] << 32u) | HlaLrfHiddenNeuronsLow[i];
  }

  /* move pointer of hidden neuron weights to point to weights for additional features */
  lrf_hiddenNeuronWeights = (sint32*)lrf_outputNeuronWeights - HLA_ICON_ADDITIONAL_FEATURES;

#else

  /* Take LRF parameters from global structure */
  switch (lrfType)
  {
    case LRF_TYPE_HALOGEN:
      lrf_NRF                  = HlaLrfInputsHalogen.lrf_NRF;
      lrf_TH                   = &HlaLrfInputsHalogen.lrf_TH[0];
      lrf_RF                   = &HlaLrfInputsHalogen.lrf_RF[0];
      lrf_hiddenNeuronWeights  = &HlaLrfInputsHalogen.lrf_hiddenNeuronWeights[0];
      lrf_outputNeuronWeights  = &HlaLrfInputsHalogen.lrf_outputNeuronWeights[0];
      break;

    case LRF_TYPE_REDLIGHT:
      lrf_NRF                  = HlaLrfInputsRedLight.lrf_NRF;
      lrf_TH                   = &HlaLrfInputsRedLight.lrf_TH[0];
      lrf_RF                   = &HlaLrfInputsRedLight.lrf_RF[0];
      lrf_hiddenNeuronWeights  = &HlaLrfInputsRedLight.lrf_hiddenNeuronWeights[0];
      lrf_outputNeuronWeights  = &HlaLrfInputsRedLight.lrf_outputNeuronWeights[0];
      break;

    case LRF_TYPE_CITYLIGHT:
      lrf_NRF                  = HlaLrfInputsCityLight.lrf_NRF;
      lrf_TH                   = &HlaLrfInputsCityLight.lrf_TH[0];
      lrf_RF                   = &HlaLrfInputsCityLight.lrf_RF[0];
      lrf_hiddenNeuronWeights  = &HlaLrfInputsCityLight.lrf_hiddenNeuronWeights[0];
      lrf_outputNeuronWeights  = &HlaLrfInputsCityLight.lrf_outputNeuronWeights[0];
      break;

    case LRF_TYPE_XENONLED:
    /* use LRF_TYPE_XENON_LED as default */
    default:
      lrf_NRF                  = HlaLrfInputsXenonLED.lrf_NRF;
      lrf_TH                   = &HlaLrfInputsXenonLED.lrf_TH[0];
      lrf_RF                   = &HlaLrfInputsXenonLED.lrf_RF[0];
      lrf_hiddenNeuronWeights  = &HlaLrfInputsXenonLED.lrf_hiddenNeuronWeights[0];
      lrf_outputNeuronWeights  = &HlaLrfInputsXenonLED.lrf_outputNeuronWeights[0];
      break;
  }

  HlaLrfHiddenNeurons[0] = (sint64)HLA_ICON_LRF_FIXPOINT_SCALE * (sint64)(*lrf_hiddenNeuronWeights);
  lrf_hiddenNeuronWeights++;

  for (f=0; f < lrf_NRF; ++f)
  {
    sint32 y;
    const sint32* lrf_RF_start = lrf_RF + (f * (HLA_ICON_LRF_FS*HLA_ICON_LRF_FS));
    const uint8* pSrc          = &iconPreProcImage[0];
    const sint32 featureOffset = -lrf_TH[f];

    for (y=HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT; y>0; --y)
    {
      sint32 x;
      for (x=HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH; x>0; --x)
      {
        sint32 j;
        sint32 feature = featureOffset;
        sint32 tanhFeature;
        const sint32* weight = lrf_RF_start;
        const uint8* pSrcConv = pSrc;

        for (j=HLA_ICON_LRF_FS; j>0; --j)
        {
          feature += (*weight) * (*pSrcConv);
          weight++;
          pSrcConv++;

          feature += (*weight) * (*pSrcConv);
          weight++;
          pSrcConv++;

          feature += (*weight) * (*pSrcConv);
          weight++;
          pSrcConv++;

          feature += (*weight) * (*pSrcConv);
          weight++;
          pSrcConv++;

          feature += (*weight) * (*pSrcConv);
          weight++;
          pSrcConv += dd;
        }

        if (feature >= 0)
        {
          const uint32 absFeature = (uint32)feature;
          sint32 tanhLookupBin    = (sint32) absFeature >> (HLA_ICON_LRF_FIXPOINT_SCALE_LOG2-1);
          if (tanhLookupBin >= HLA_ICON_TANH_LOOKUP_TABLE_SIZE)
          {
            tanhFeature = HLA_ICON_LRF_FIXPOINT_SCALE;
          }
          else
          {
            const HlaTanhLUT_t* pLUT = &tanhLUT[0] + tanhLookupBin;
            tanhFeature = pLUT->offset + (sint32)(((uint64)pLUT->scale * (uint64)absFeature) >> HLA_ICON_LRF_FIXPOINT_SCALE_LOG2);
          }
        }
        else
        {
          const uint32 absFeature = (uint32)(-feature);
          sint32 tanhLookupBin    = (sint32) absFeature >> (HLA_ICON_LRF_FIXPOINT_SCALE_LOG2-1);
          if (tanhLookupBin >= HLA_ICON_TANH_LOOKUP_TABLE_SIZE)
          {
            tanhFeature = -HLA_ICON_LRF_FIXPOINT_SCALE;
          }
          else
          {
            const HlaTanhLUT_t* pLUT = &tanhLUT[0] + tanhLookupBin;
            tanhFeature = -(pLUT->offset + (sint32)(((uint64)pLUT->scale * (uint64)absFeature) >> HLA_ICON_LRF_FIXPOINT_SCALE_LOG2));
          }
        }

        HlaLrfHiddenNeurons[0] += (sint64)(tanhFeature) * (sint64)(*lrf_hiddenNeuronWeights);
        lrf_hiddenNeuronWeights++;

        pSrc += HLA_ICON_LRF_DS;
      }

      pSrc+=dd0;
    }
  }
#endif /* HLA_LRF_ON_EVE */

  {
    sint32 i;
    const sint32* pAdditionalFeatures = &additionalFeatures[0];

    for (i=0; i<HLA_ICON_ADDITIONAL_FEATURES; i++)
    {
      HlaLrfHiddenNeurons[0] += (sint64)(*pAdditionalFeatures) * (sint64)(*lrf_hiddenNeuronWeights);
      lrf_hiddenNeuronWeights++;
      pAdditionalFeatures++;
    }
  }

  {
    float32 outputNeuron = lrf_outputNeuronWeights[0];
    outputNeuron += (float32) tanh( HLA_ICON_LRF_SIGMOID_STEEPNESS * 
                                    (
                                       (float32) HlaLrfHiddenNeurons[0] / 
                                      ((float32) HLA_ICON_LRF_FIXPOINT_SCALE * (float32)HLA_ICON_LRF_FIXPOINT_SCALE)
                                     )
                                    ) * lrf_outputNeuronWeights[1];

    outputNeuron = (float32) tanh(HLA_ICON_LRF_SIGMOID_STEEPNESS * outputNeuron);

    outputNeuron -= lrf_outputOffset;

#ifdef HLA_LRF_ON_EVE
  /* Error handling */
  if (   (retValEveTrigger != EVE_NO_ERROR)
      || (retValEveWait != EVE_NO_ERROR)
     )
  {
    /* In this case EVE has even not been called */
    /* Set LRF output to a neutral value */
    outputNeuron = 0;
  }
  if (lrfEveReturnCode != HLA_EVE_RETURN_OK)
  {
    /* In case of an error on EVE side we provide return code to system info struct for visualization */
    pAnalysisData->EveErrorCode = lrfEveReturnCode;
    /* Set LRF output to a neutral value */
    outputNeuron = 0;
  }
#endif

    if (outputNeuron < 0)
    {
      resultInfo.result = HLA_ICONRESULT_POSITIVE;
    }
    else
    {
      resultInfo.result = HLA_ICONRESULT_NEGATIVE;
    }
    resultInfo.classResponse = CML_MinMax(-HLA_ICONRESULT_MAX_CLASS_RESPONSE, HLA_ICONRESULT_MAX_CLASS_RESPONSE, (sint8)CML_s_Round2Int((float32)(-HLA_ICONRESULT_MAX_CLASS_RESPONSE) * outputNeuron));
  }

  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel2ndLRF_us += (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);
  return resultInfo;
}

static void HLAIconPrepareInputs( const HLAIconData_t*          restrict pIcon,
                                  const HLAR_t_RequiredInputs*  restrict pRequiredIn,
                                  const HLACameraData_t*        restrict pCamData,
                                  const HLATrack_t*             restrict pTrack,
                                  const float32                          lightPosX,
                                  const float32                          lightPosY,
                                        HLATimeMeasurement_t*   restrict pTimeMeasurement,
                                        AS_t_GetTimestampuS32            pfGetTimestampuS32
                                )
{
  uint32 TimeStart_us;

  /* apply normalization */
  TimeStart_us = pfGetTimestampuS32();
  HLAIconNormalize( &pRequiredIn->s_Par.s_CameraParameter,
                    pIcon->pData,
                    pIcon->Pos.Width,
                    pIcon->Pos.Height,
                    pIcon,
                    &iconNormalized[0]
                  );
  pTimeMeasurement->dTimeAnalysisLevel2ndNormalize_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

  /* apply preprocessing */
  TimeStart_us = pfGetTimestampuS32();
  HLAIconPreProcess( pRequiredIn->s_Par.s_CameraParameter.e_bayerPattern,
                     &iconNormalized[0],
                     pIcon,
                     pIcon->Pos.Width,
                     pIcon->Pos.Height,
                     lightPosX,
                     lightPosY,
                     &iconPreProcImage[0]
                   );
  pTimeMeasurement->dTimeAnalysisLevel2ndPreProcess_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

  /* fill global array additional classification features */
  HLAIconFillAdditionalFeatures( pCamData,
                                 pTrack,
                                 lightPosY,
                                 &additionalFeatures[0]
                               );
}

static void HLAReGrow_Push(HLAReGrow_PixelStack_t* pixelStack, uint8 x, uint8 y)
{
  HLAReGrow_Pixel_t* pixel;

  if (pixelStack->count < HLA_ICON_REGROW_PIXEL_STACK_SIZE)
  {
    pixel = &pixelStack->item[pixelStack->count];
    pixel->x = x;
    pixel->y = y;
    pixelStack->count++;
  }
}

/* ~CodeReview ~ID:fadb6e3443614bb9012c86f0dc5c9278 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:document the precondition pixelStack->count elements > 0 */
static HLAReGrow_Pixel_t HLAReGrow_Pop(HLAReGrow_PixelStack_t* pixelStack)
{
  HLAReGrow_Pixel_t pixel = pixelStack->item[pixelStack->count-1];
  pixelStack->count--;
  return pixel;
}

static boolean HLAReGrow_Empty(const HLAReGrow_PixelStack_t* pixelStack)
{
  return (pixelStack->count > 0) ? b_FALSE : b_TRUE;
}

/* **************************************************************************** 
  Functionname:     HLARegionGrowing                                      */ /*!  
  Description:      Standard Region Growing on preprocessed icon image writing
                    the result into a segmentation image (0 means pixel position
                    is not part of the segment, 1 means pixel is part of the 
                    segment.

  @param[in]        uint8 startX                    seed point position x
                    uint8 startY                    seed point position y
                    uint8 minIntensity              min intensity growing criteria

  @return           void
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLARegionGrowing(uint8 startX, uint8 startY, uint8 minIntensity, boolean greenPixel)
{
  HLAReGrow_PixelStack_t pixelStack;
  HLAReGrow_Pixel_t curPixel = HLAReGrow_Pop(&pixelStack);
  uint16 segmentOffset;

  /* Initialize pixel stack */
  pixelStack.count = 0;
  HLAReGrow_Push(&pixelStack, startX, startY);

  while (HLAReGrow_Empty(&pixelStack) == b_FALSE)
  {
    curPixel = HLAReGrow_Pop(&pixelStack);
    segmentOffset = (curPixel.y * HLA_ICON_COLORIMAGE_WIDTH) + curPixel.x;

    if ((iconPreProcSegmentationImage[segmentOffset] == 0) &&
        (iconPreProcImage[segmentOffset] >= minIntensity))
    {
      if (greenPixel == b_TRUE)
      {
        if ((curPixel.x >= 1) &&
            (curPixel.y >= 1))
        {
          HLAReGrow_Push(&pixelStack, curPixel.x-1, curPixel.y-1);
        }
        if ((curPixel.x < (HLA_ICON_COLORIMAGE_WIDTH - 1)) &&
            (curPixel.y >= 1))
        {
          HLAReGrow_Push(&pixelStack, curPixel.x+1, curPixel.y-1);
        }
        if ((curPixel.x < (HLA_ICON_COLORIMAGE_WIDTH  - 1)) &&
            (curPixel.y < (HLA_ICON_COLORIMAGE_HEIGHT - 1)))
        {
          HLAReGrow_Push(&pixelStack, curPixel.x+1, curPixel.y+1);
        }
        if ((curPixel.x >= 1) &&
            (curPixel.y < (HLA_ICON_COLORIMAGE_HEIGHT - 1)))
        {
          HLAReGrow_Push(&pixelStack, curPixel.x-1, curPixel.y+1);
        }
      }
      else
      {
        if (curPixel.x >= 2)
        {
          HLAReGrow_Push(&pixelStack, curPixel.x-2, curPixel.y  );
        }
        if (curPixel.y >= 2)
        {
          HLAReGrow_Push(&pixelStack, curPixel.x  , curPixel.y-2);
        }
        if (curPixel.x < (HLA_ICON_COLORIMAGE_WIDTH - 2))
        {
          HLAReGrow_Push(&pixelStack, curPixel.x+2, curPixel.y  );
        }
        if (curPixel.y < (HLA_ICON_COLORIMAGE_HEIGHT - 2))
        {
          HLAReGrow_Push(&pixelStack, curPixel.x  , curPixel.y+2);
        }
      }

      iconPreProcSegmentationImage[segmentOffset] = 1;
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAIconLedLightDetection                                */ /*!  
  Description:      Check the icon for potential LED light

  @param[in]        -

  @return           IconResultInfo_t result
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static IconResultInfo_t HLAIconLedLightDetection(const HLA_t_eBayerPatternType e_bayerPattern, const HLAIconData_t* pIcon)
{
  const HLATrack_t* pTrack = (const HLATrack_t*)pIcon->pRef;

  uint16 redGreenCountTotal = 0u;
  uint16 redGreenCountLed = 0u;

  uint16 redCountLed = 0u;
  uint16 redCountTotal = 0u;
  uint16 greenCountLed = 0u;
  uint16 greenCountTotal = 0u;
  uint16 blueCountLed = 0u;
  uint16 blueCountTotal = 0u;

  t_PixelData maxRed = 0;
  t_PixelData maxGreen = 0;
  t_PixelData maxBlue = 0;

  t_PixelData* ptrIcon;

  uint8 y;
  uint8 x;
  uint8 patternH;
  uint8 patternV;

  uint8* ptrSeg;

  /* valid range of imager kneepoint 1 saturation */
  const uint16 minLed = HLAImager_GetT1SatLow();
  const uint16 maxLed = HLAImager_GetT1SatHigh();

  /* red */
  const uint8 maxIntRed = CML_Max(CML_Max(CML_Max(CML_Max(
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2) - 2) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2)    )],
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2)    ) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2) - 2)]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2)    ) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2)    )]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2)    ) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2) + 2)]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2) + 2) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2)    )]);

  /* green */
  const uint8 maxIntGreen = CML_Max(CML_Max(CML_Max(
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2) - 1) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2)    )],
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2)    ) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2) - 1)]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2)    ) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2) + 1)]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT / 2) + 1) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH / 2)    )]);

  /* blue */
  const uint8 maxIntBlue = CML_Max(CML_Max(CML_Max(
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT/2)-1) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH/2)-1)],
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT/2)-1) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH/2)+1)]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT/2)+1) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH/2)+1)]),
      iconPreProcImage[(((HLA_ICON_COLORIMAGE_HEIGHT/2)+1) * HLA_ICON_COLORIMAGE_WIDTH) + ((HLA_ICON_COLORIMAGE_WIDTH/2)-1)]);

  IconResultInfo_t resultInfo;
  resultInfo.result = HLA_ICONRESULT_NEGATIVE;
  resultInfo.classResponse = HLA_ICON_RESULT_NEG_CLASS_RESPONSE;

  /* light segmentation on the preprocessed icon by region growing on red and green color channels */
  (void)memset(&iconPreProcSegmentationImage[0], 0, HLA_ICON_COLORIMAGE_WIDTH * HLA_ICON_COLORIMAGE_HEIGHT);

  /* red */
  HLARegionGrowing( HLA_ICON_COLORIMAGE_WIDTH / 2, 
                    HLA_ICON_COLORIMAGE_HEIGHT / 2,
                    maxIntRed - 20,
                    b_FALSE
                  );

  /* green */
  HLARegionGrowing( (HLA_ICON_COLORIMAGE_WIDTH / 2) - 1, 
                    HLA_ICON_COLORIMAGE_HEIGHT / 2,
                    maxIntGreen - 16,
                    b_TRUE
                  );

  /* blue */
  HLARegionGrowing( (HLA_ICON_COLORIMAGE_WIDTH/2) - 1, 
                    (HLA_ICON_COLORIMAGE_HEIGHT/2) - 1,
                    maxIntBlue - 20,
                    b_FALSE
                  );

  {
    ptrSeg = &iconPreProcSegmentationImage[0];

    patternH = (uint8)(((uint32)(e_bayerPattern) % 2) + pIcon->Pos.X1 + brightBoxColorLeft) % 2;
    patternV = (uint8)(((uint32)(e_bayerPattern) / 2) + pIcon->Pos.Y1 + brightBoxColorTop ) % 2;

    for (y=0; y<HLA_ICON_COLORIMAGE_HEIGHT; y++)
    {
      ptrIcon = pIcon->pData + ((brightBoxColorTop + y) * pIcon->Pos.Width) + brightBoxColorLeft;

      for (x=0; x<HLA_ICON_COLORIMAGE_WIDTH; x++)
      {
        if (*ptrSeg > 0)
        {
          if ((patternH == 0) && (patternV == 0))
          {
            /* red position */
            redCountTotal++;

            if ((*ptrIcon >= minLed) &&
                (*ptrIcon <= maxLed))
            {
              redCountLed++;
            }

            if (*ptrIcon > maxRed)
            {
              maxRed = *ptrIcon;
            }
          }
          else if ((patternH == 1) && (patternV == 1))
          {
            /* blue position */
            blueCountTotal++;

            if ((*ptrIcon >= minLed) &&
                (*ptrIcon <= maxLed))
            {
              blueCountLed++;
            }

            if (*ptrIcon > maxBlue)
            {
              maxBlue = *ptrIcon;
            }
          }
          else
          {
            /* green position */
            greenCountTotal++;

            if ((*ptrIcon >= minLed) &&
                (*ptrIcon <= maxLed))
            {
              greenCountLed++;
            }

            if (*ptrIcon > maxGreen)
            {
              maxGreen = *ptrIcon;
            }
          }
        }

        ptrIcon++;
        ptrSeg++;

        patternH = patternH ^ 1;
      }

      patternV = patternV ^ 1;
    }
  }

  /* LED pixel amount analysis (no detection when light exceeds icon size) */
  if (   (    ( redCountTotal < 70) 
           && ( greenCountTotal < 140) 
           && ( blueCountTotal < 70)
         ) 
      || (    ( pTrack->light_ref != NULL) 
           && ( pTrack->light_ref->pRegion != NULL) 
           && ( ((pTrack->light_ref->pRegion->x2 - pTrack->light_ref->pRegion->x1) * (pTrack->light_ref->pRegion->y2 - pTrack->light_ref->pRegion->y1)) < 2000)
         )
     )
  {
    /* majority of LED pixels must not be blue (to filter green and blue LED lights) */
    if (    (maxBlue <= maxLed) 
         && (blueCountLed <= redCountLed) 
         && (blueCountLed <= greenCountLed)
       )
    {
      /* red LED pixel analysis */
      if (    (maxRed >= minLed) 
           && (maxRed <= maxLed) 
           && (redCountTotal >= 3) 
           && (redCountLed >= ((0.37f * redCountTotal) + 0.8f))
         )
      {
        resultInfo.result = HLA_ICONRESULT_POSITIVE;
        resultInfo.classResponse = HLA_ICON_RESULT_POS_CLASS_RESPONSE;
      }
      /* green LED pixel analysis */
      else if (    (maxGreen >= minLed) 
                && (maxGreen <= maxLed) 
                && (greenCountTotal >= 3) 
                && (greenCountLed >= (uint16)((0.37f * (float32)greenCountTotal) + 0.8f)) 
                && (maxRed >= minLed)
              )
      {
        resultInfo.result = HLA_ICONRESULT_POSITIVE;
        resultInfo.classResponse = HLA_ICON_RESULT_POS_CLASS_RESPONSE;
      }
      else
      {
        redGreenCountTotal = redCountTotal + greenCountTotal;
        redGreenCountLed = redCountLed + greenCountLed;

        /* red + green LED pixel analysis */
        if (    (maxRed >= minLed) 
             && (maxRed <= maxLed) 
             && (maxGreen >= minLed) 
             && (maxGreen <= maxLed) 
             && (redGreenCountTotal >= 3) 
             && (redGreenCountLed >= (uint16)((0.37f * (float32)redGreenCountTotal) + 0.8f))
           )
        {
          resultInfo.result = HLA_ICONRESULT_POSITIVE;
          resultInfo.classResponse = HLA_ICON_RESULT_POS_CLASS_RESPONSE;
        }
      }
    }
  }

#ifdef PC_SIM
  ((HLATrack_t*)pTrack)->iconState.redCountLed = redCountLed;
  ((HLATrack_t*)pTrack)->iconState.redCountTotal = redCountTotal;
  ((HLATrack_t*)pTrack)->iconState.redCountThreshold = (0.37f * redCountTotal) + 0.8f;
  ((HLATrack_t*)pTrack)->iconState.greenCountLed = greenCountLed;
  ((HLATrack_t*)pTrack)->iconState.greenCountTotal = greenCountTotal;
  ((HLATrack_t*)pTrack)->iconState.greenCountThreshold = (0.37f * greenCountTotal) + 0.8f;
  ((HLATrack_t*)pTrack)->iconState.redGreenCountLed = redCountLed + greenCountLed;
  ((HLATrack_t*)pTrack)->iconState.redGreenCountTotal = redCountTotal + greenCountTotal;
  ((HLATrack_t*)pTrack)->iconState.redGreenCountThreshold = (0.37f * (redCountTotal + greenCountTotal)) + 0.8f;
  ((HLATrack_t*)pTrack)->iconState.blueCountLed = blueCountLed;
  ((HLATrack_t*)pTrack)->iconState.blueCountTotal = blueCountTotal;
  ((HLATrack_t*)pTrack)->iconState.maxRed = maxRed;
  ((HLATrack_t*)pTrack)->iconState.maxGreen = maxGreen;
  ((HLATrack_t*)pTrack)->iconState.maxBlue = maxBlue;
#endif

  return resultInfo;
}

#ifdef ICON_MEASFREEZE
void HLAIconMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
  AS_t_MeasInfo DebugIconListMeasInfo = {HLA_MEAS_VADDR_DEBUG_ICON_LIST, sizeof(hlaDebugIconList), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  (void)pfMeasFreeze(&DebugIconListMeasInfo, (void*)&hlaDebugIconList, NULL);
  /* <ln_offset+2 PCLINT Error 715: reviewer name: Stefan Zechner date: 2012-04-20 reason: Function required for debugging purposes */
  /* <ln_offset+1 MISRA Rule 16.7: reviewer name: Stefan Zechner date: 2012-04-20 reason: Function required for debugging purposes */
}
#endif


/* **************************************************************************** 
  Functionname:     HLAIdentificationPotVehOncoming2ndLevel                               */ /*!  
  Description:      Check if potential vehicle form Level1 also passed Level2

  @param[in]        HLATrack_t* pTrack

  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAIdentificationPotVehOncoming2ndLevel( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                                           HLATrack_t*                pTrack )
{
  
  if(    (    (pTrack->statusAnalysisVehicle.isVehicleOncoming == 1)                       /* detected last frame as vehicle */
           && (    ((pTrack->trace_time - pTrack->trace_time_firstVehicleDetection) < pAnalysisParamIn->icon.stickyMinTime)
                || (pTrack->iconState.classResultSum >= 0)                                  /* and is still positive classified -> sticky status */
              )
         )
      || (pTrack->statusAnalysisVehicle.isClassResultReached == 1)                        /* classified as vehicle */
      || (pTrack->statusAnalysisVehicle.isSuddenlyAppearingVehicle == 1)                  /* suddenly appearing vehicle */
      || (pTrack->statusAnalysisVehicle.isHighwayOncomingCar == 1)                        /* Oncoming car on highway */
    )
  {
    pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming2nd = 1;
  }
  else
  {
    pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming2nd = 0;
  }
  
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationPotVehAhead2ndLevel                               */ /*!  
  Description:      Check if potential vehicle form Level1 also passed Level2

  @param[in]        HLATrack_t* pTrack

  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAIdentificationPotVehAhead2ndLevel( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                                        HLATrack_t*               pTrack )
{

  if(    (    (pTrack->statusAnalysisVehicle.isVehicleAhead == 1)                          /* detected last frame as vehicle */
           && (    ((pTrack->trace_time - pTrack->trace_time_firstVehicleDetection) < pAnalysisParamIn->icon.stickyMinTime)
                || (pTrack->iconState.classResultSum >= 0)                                  /* and is still positive classified -> sticky status */
             )
         )
      || (pTrack->statusAnalysisVehicle.isClassResultReached == 1)                        /* classified as vehicle */
      || (pTrack->statusAnalysisVehicle.isSuddenlyAppearingVehicle == 1)                  /* suddenly appearing vehicle */
      || (pTrack->statusAnalysisVehicle.isDriveDistAheadReached == 1)                     /* light was visible over a long driven distance */
      || (pTrack->statusAnalysisVehicle.isDriveDistAheadDynamicReached == 1)              /* dynamic light was visible over a long driven distance */
      || (pTrack->statusAnalysisVehicle.isDriveDistAheadPairReached == 1)                 /* pair light was visible over a long driven distance */
      || (pTrack->statusAnalysisVehicle.isOvertaker == 1)                                 /*  */
    )
  {
    pTrack->statusAnalysisVehicle.isPotentialVehicleAhead2nd = 1;
  }
  else
  {
    pTrack->statusAnalysisVehicle.isPotentialVehicleAhead2nd = 0;
  }

}


/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelInit                              */ /*!  
  Description:      Initialize 2nd Level potential vehicle analysis

  @param[in]        const HLAR_t_RequiredInputs* pRequiredIn   required Inpus
  @param[in]        HLATrack_t*                  pTrack  current Track

  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelInit( const uint32                 driveDistCm,
                                                 HLATrack_t*            pTrack
                                         )
{
  /* reset all flags */
  pTrack->statusAnalysisVehicle.isClassResultReached = 0u;
  pTrack->statusAnalysisVehicle.isSuddenlyAppearingVehicle = 0u;
  pTrack->statusAnalysisVehicle.isDriveDistAheadReached = 0u;
  pTrack->statusAnalysisVehicle.isDriveDistAheadDynamicReached = 0u;
  pTrack->statusAnalysisVehicle.isDriveDistAheadPairReached = 0u;
  pTrack->statusAnalysisVehicle.isOvertaker = 0u;
  pTrack->statusAnalysisVehicle.isHighwayOncomingCar = 0u;
  pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming2nd = 0u;
  pTrack->statusAnalysisVehicle.isPotentialVehicleAhead2nd = 0u;

  /* update driven distance */
  if (    (pTrack->light_ref != NULL)
       && (pTrack->light_ref->pRegion != NULL)
     )
  {
    if (    (    (pTrack->statusAnalysisVehicle.isRed == 1u)
              || (pTrack->statusAnalysisVehicle.isRed2 == 1u)
              || (pTrack->statusAnalysisVehicle.isMovingNonWhite == 1u)
            )
         && (    (pTrack->statusAnalysisMisc.isAboveHorizon == 0u) 
              || (pTrack->delta_y_lp_lt > 0.0f)
            )
         && (pTrack->ttb > 5.0f)
         && (pTrack->lost_time == 0u)
       )
    {
      /* search for level 1 region */
      const HLASegLineRegion_t* pLevel1Region = pTrack->light_ref->pRegion;
      while (pLevel1Region->pRegionBelow != NULL)
      {
        pLevel1Region = pLevel1Region->pRegionBelow;
      }

      /* size check on level 1 region */
      if (    ((pLevel1Region->x2 - pLevel1Region->x1) >= 2)
           && ((pLevel1Region->y2 - pLevel1Region->y1) >= 2)
         )
      {
        pTrack->driveDistCmPotAhead1st = (uint16)CML_Min(UI16_T_MAX, pTrack->driveDistCmPotAhead1st + driveDistCm);

        if (pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_DYNAMIC)
        {
          pTrack->driveDistCmPotAhead1stDynamic = (uint16)CML_Min(UI16_T_MAX, pTrack->driveDistCmPotAhead1stDynamic + driveDistCm);
        }

        if (    (pTrack->TrackingStatus.isLinked2Pair   == 1) 
             || (pTrack->TrackingStatus.isTrackedInPair == 1)
           )
        {
          pTrack->driveDistCmPotAhead1stPair = (uint16)CML_Min(UI16_T_MAX, pTrack->driveDistCmPotAhead1stPair + driveDistCm);
        }
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelSuddentlyAppearingVehicle                              */ /*!  
  Description:      Analyze Suddently Appearing Vehicle

  @param[in]        HLASegLineRegion_t*          pLevel2Region
  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        const HLATracking3DOutput_t*  pHlaTrackOut   pointer to tracks
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelSuddentlyAppearingVehicle( const HLASegLineRegion_t*     pLevel2Region,
                                                                const HLATracking3DOutput_t*  pHlaTrackOut,
                                                                      HLATrack_t*             pTrack
                                                              )
{
  /* TODO schillinger: replace magic numbers */
  if (    (pTrack->track_time >= 3)
       && (pTrack->track_time <= 20)
       && (pTrack->statusAnalysisMisc.isAboveHorizon == 0)
       && (pTrack->AverageMaxInt > 8000)
       && (pTrack->MaxInt > 11000)
       && (pLevel2Region != NULL)
     )
  {
    /* size check on level 2 region */
    if (    ((pLevel2Region->x2 - pLevel2Region->x1) >= 12)
         && ((pLevel2Region->y2 - pLevel2Region->y1) >= 8)
       )
    {
      boolean iconClassifiedInRegion = b_FALSE;
      const HLASegLineRegion_t* pLevel1Region = pLevel2Region->pRegionBelow;
      HLATrack_t* pTrackinsideRegion = pHlaTrackOut->pTrack;

      while (pTrackinsideRegion != NULL)
      {
        if (    (pTrackinsideRegion->xcenter >= pLevel1Region->x1)
             && (pTrackinsideRegion->xcenter <= pLevel1Region->x2)
             && (pTrackinsideRegion->ycenter >= pLevel1Region->y1)
             && (pTrackinsideRegion->ycenter <= pLevel1Region->y2)
             && (pTrackinsideRegion->iconState.classResultSum < 0)
           )
        {
          iconClassifiedInRegion = b_TRUE;
          break;
        }

        pTrackinsideRegion = pTrackinsideRegion->next;
      }

      if (iconClassifiedInRegion == b_FALSE)
      {
        pTrack->statusAnalysisVehicle.isSuddenlyAppearingVehicle = 1;
      }
    }
  }

}


/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelHighwayOncomingCar                              */ /*!  
  Description:      Analyze Highway Oncoming Car

  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        const HLATracking3DOutput_t*  pHlaTrackOut   pointer to tracks
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelHighwayOncomingCar( const HLATracking3DOutput_t*     pHlaTrackOut,
                                                         const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                                               HLATrack_t*                pTrack
                                                       )
{
  HLAPair_t *pPair;

  /* highway oncoming car
  * if Light is detected as highway bright light 
  * and the class Result Sum is higher than the min threshold
  * and this last frame classifier result was not negative
  * the light is becoming an highway oncoming car*/
  if (    (pTrack->statusAnalysisVehicle.isHighwayBright == 1)
       && (pTrack->iconState.classResultSum > pAnalysisParamIn->highwayBrightMinClassResult)
       && (pTrack->iconState.cyclesNoClass == 0)
       && (pTrack->iconState.resultInfo.result != HLA_ICONRESULT_NEGATIVE)
     )
  {
    pTrack->statusAnalysisVehicle.isHighwayOncomingCar = 1;
  }

  /* check all existing pairs. If both lights of a pair are detected as truck lights both lights are becoming an highway oncoming car */
  pPair = pHlaTrackOut->pPairs;
  while(pPair != NULL)
  {
    if(    (pPair->pTLeft->statusAnalysisVehicle.isHighwayBrightTruckLights == 1)
        && (pPair->pTRight->statusAnalysisVehicle.isHighwayBrightTruckLights == 1)
        && (pPair->pTLeft->iconState.cyclesNoClass == 0)
        && (pPair->pTRight->iconState.cyclesNoClass == 0)
      )
    {
      pPair->pTLeft->statusAnalysisVehicle.isHighwayOncomingCar = 1;
      pPair->pTRight->statusAnalysisVehicle.isHighwayOncomingCar = 1;
    }

    pPair = pPair->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelClassificationResultReachedOncoming                            */ /*!  
  Description:      Analyze Highway Oncoming Car

  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        const HLACameraData_t* pCamData
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelClassificationResultReachedOncoming( const HLA_t_AnalysisParameters*   pAnalysisParamIn,
                                                                          const HLACameraData_t*            pCamData,
                                                                          const float32                     size,
                                                                                HLATrack_t*                 pTrack
                                                                        )
{
  const float32 sizePenalty = CML_f_MinMax( pAnalysisParamIn->icon.crtOncomingSizeMin,
                                      pAnalysisParamIn->icon.crtOncomingSizeMax,
                                      pAnalysisParamIn->icon.crtOncomingSizeC0 
                                      + (pAnalysisParamIn->icon.crtOncomingSizeC1 * size)
                                    );

  const float32 brightnessPenalty = CML_f_MinMax( pAnalysisParamIn->icon.crtOncomingBrightnessMin,
                                            pAnalysisParamIn->icon.crtOncomingBrightnessMax,
                                            pAnalysisParamIn->icon.crtOncomingBrightnessC0
                                            + (pAnalysisParamIn->icon.crtOncomingBrightnessC1 * pTrack->MaxInt)
                                          );

  const float32 positionPenalty = CML_f_MinMax( pAnalysisParamIn->icon.crtOncomingPositionMin,
                                          pAnalysisParamIn->icon.crtOncomingPositionMax,
                                          pAnalysisParamIn->icon.crtOncomingPositionC0
                                          + (pAnalysisParamIn->icon.crtOncomingPositionC1
                                              * ((float32)(pCamData->FOE_y - pTrack->ycenter) / (pCamData->FOE_y - pCamData->RoiYu))
                                            )
                                        );

  const float32 classResultThreshold = pAnalysisParamIn->icon.crtOncomingMin + sizePenalty + brightnessPenalty + positionPenalty;

  if(    (pTrack->statusAnalysisMisc.isChainOfLight == TRUE) 
      && (pTrack->iconState.resultInfo.result != HLA_ICONRESULT_NEGATIVE)
    )
  {
    pTrack->iconState.classResultSum = CML_MinMax( pAnalysisParamIn->icon.classResultSumMin, 
                                                   pAnalysisParamIn->icon.classResultSumMax, 
                                                   (pTrack->iconState.classResultSum - ((pTrack->lengthChainOfLight * HLA_ICONRESULT_MAX_CLASS_RESPONSE) / 2))
                                                 );
  }

  #ifdef PC_SIM
  pTrack->iconState.classResultThresholdSizePenalty = sizePenalty;
  pTrack->iconState.classResultThresholdBrightnessPenalty = brightnessPenalty;
  pTrack->iconState.classResultThresholdPositionPenalty = positionPenalty;
  pTrack->iconState.classResultThreshold = classResultThreshold;
  #endif

  if (   (pTrack->iconState.cyclesNoClass == 0)
       &&(pTrack->iconState.classResultSum >= (classResultThreshold * HLA_ICONRESULT_MAX_CLASS_RESPONSE))
     )
  {
    pTrack->statusAnalysisVehicle.isClassResultReached = 1;
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelClassificationResultReachedAhead                            */ /*!  
  Description:      Analyze Highway Oncoming Car

  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        const HLACameraData_t* pCamData
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelClassificationResultReachedAhead( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                                                       const HLACameraData_t*           pCamData,
                                                                       const float32                    size,
                                                                       HLATrack_t*                      pTrack
                                                                     )
{
  const float32 sizePenalty = CML_f_MinMax( pAnalysisParamIn->icon.crtAheadSizeMin,
                                      pAnalysisParamIn->icon.crtAheadSizeMax,
                                      pAnalysisParamIn->icon.crtAheadSizeC0
                                      + (pAnalysisParamIn->icon.crtAheadSizeC1 * size)
                                    );

  const float32 brightnessPenalty = 
            ((pTrack->iconState.status.ledDetectionCalled == 1) && (pTrack->iconState.resultInfo.result == HLA_ICONRESULT_POSITIVE)) ? sizePenalty :
            CML_f_MinMax( pAnalysisParamIn->icon.crtAheadBrightnessMin,
                    pAnalysisParamIn->icon.crtAheadBrightnessMax,
                    pAnalysisParamIn->icon.crtAheadBrightnessC0
                    + (pAnalysisParamIn->icon.crtAheadBrightnessC1 * pTrack->MaxInt)
                  );

  const float32 positionPenalty = CML_f_MinMax( pAnalysisParamIn->icon.crtAheadPositionMin,
                                                pAnalysisParamIn->icon.crtAheadPositionMax,
                                                (   pAnalysisParamIn->icon.crtAheadPositionC0
                                                  + (   pAnalysisParamIn->icon.crtAheadPositionC1
                                                      * ((float32)(pCamData->FOE_y - pTrack->ycenter) / (pCamData->FOE_y - pCamData->RoiYu))
                                                    )
                                                )
                                              );

  const float32 classResultThreshold = pAnalysisParamIn->icon.crtAheadMin + sizePenalty + brightnessPenalty + positionPenalty;

  if(    (pTrack->statusAnalysisMisc.isChainOfLight == TRUE) 
      && (pTrack->iconState.resultInfo.result != HLA_ICONRESULT_NEGATIVE) 
    )
  {
    pTrack->iconState.classResultSum = CML_MinMax( pAnalysisParamIn->icon.classResultSumMin, 
                                                   pAnalysisParamIn->icon.classResultSumMax, 
                                                   (pTrack->iconState.classResultSum - ((pTrack->lengthChainOfLight * HLA_ICONRESULT_MAX_CLASS_RESPONSE) / 2))
                                                 );
  }

#ifdef PC_SIM
  pTrack->iconState.classResultThresholdSizePenalty = sizePenalty;
  pTrack->iconState.classResultThresholdBrightnessPenalty = brightnessPenalty;
  pTrack->iconState.classResultThresholdPositionPenalty = positionPenalty;
  pTrack->iconState.classResultThreshold = classResultThreshold;
#endif

  if (    (pTrack->iconState.cyclesNoClass == 0u)
       && (pTrack->iconState.classResultSum >= (classResultThreshold * HLA_ICONRESULT_MAX_CLASS_RESPONSE))
     )
  {
    pTrack->statusAnalysisVehicle.isClassResultReached = 1u;
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelDrivenDistanceReached                            */ /*!  
  Description:      Bypass for cars which are followed for a long distance without becoming a preceding car

  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        const HLAAnalysisData_t*  pAnalysisData
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelDrivenDistanceReached( const HLAAnalysisData_t*  pAnalysisData,
                                                                  HLATrack_t*         pTrack )
{
  /* driven distance 
   * TODO schillinger: replace magic numbers */
  if (pAnalysisData->bRedReflectorArea == b_TRUE)
  {
    if (pTrack->driveDistCmPotAhead1st > 60000u)
    {
      pTrack->statusAnalysisVehicle.isDriveDistAheadReached = 1u;
    }
    if (pTrack->driveDistCmPotAhead1stDynamic > 20000u)
    {
      pTrack->statusAnalysisVehicle.isDriveDistAheadDynamicReached = 1u;
    }
    if (pTrack->driveDistCmPotAhead1stPair > 22000u)
    {
      pTrack->statusAnalysisVehicle.isDriveDistAheadPairReached = 1u;
    }
  }
  else
  {
    if (pTrack->driveDistCmPotAhead1st > 40000u)
    {
      pTrack->statusAnalysisVehicle.isDriveDistAheadReached = 1u;
    }
    if (pTrack->driveDistCmPotAhead1stDynamic > 14000u)
    {
      pTrack->statusAnalysisVehicle.isDriveDistAheadDynamicReached = 1u;
    }
    if (pTrack->driveDistCmPotAhead1stPair > 18000u)
    {
      pTrack->statusAnalysisVehicle.isDriveDistAheadPairReached = 1u;
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelDrivenDistanceReached                            */ /*!  
  Description:      Bypass for cars which are followed for a long distance without becoming a preceding car

  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        const HLACameraData_t* pCamData
  @param[in]        const HLASegLineRegion_t* HLASegLineRegion_t* pLevel2Region
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAAnalysisPotVeh2ndLevelIsOvertaker( const HLACameraData_t*    pCamData,
                                                  const HLASegLineRegion_t* pLevel2Region,
                                                        HLATrack_t*         pTrack
                                                )
{
  /* isOvertaker */
  if (    (pTrack->statusAnalysisVehicle.isMovingNonWhite == 1u)
       && (pTrack->statusAnalysisMisc.isFarAboveHorizon == 0u)
       && (   (pTrack->MaxInt > 2000u)
            ||(pTrack->idResStat.isPulsedLight.confidence > 0)
          )
       && (
              (    (pTrack->xcenter < (pCamData->RoiX1 + ((pCamData->FOE_x - pCamData->RoiX1) / 2)))
                && (pTrack->delta_x_lp > 0)
              )
           || (    (pTrack->xcenter > (pCamData->RoiX2 - ((pCamData->RoiX2 - pCamData->FOE_x) / 2)))
                && (pTrack->delta_x_lp < 0)
              )
          ) 
       && (pLevel2Region != NULL)
       && ((pLevel2Region->x2 - pLevel2Region->x1) >= 6)
       && ((pLevel2Region->y2 - pLevel2Region->y1) >= 4)
     )
  {
    pTrack->statusAnalysisVehicle.isOvertaker = 1;
  }

}


/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVeh2ndLevelSearchRegion2                           */ /*!  
  Description:      search for Level2 Region and set if available

  @param[in]        HLATrack_t*                  pTrack             current Track
  @param[in]        HLASegLineRegion_t* pLevel2Region
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static HLASegLineRegion_t* HLAAnalysisPotVeh2ndLevelSearchRegion2( const HLATrack_t* pTrack )
{
  HLASegLineRegion_t* pLevel2Region = NULL;

  if (    (pTrack->light_ref != NULL)
       && (pTrack->light_ref->pRegion != NULL)
       && (pTrack->light_ref->pRegion->pRegionBelow != NULL)
     )
  {
    pLevel2Region = pTrack->light_ref->pRegion;
    while (pLevel2Region->pRegionBelow->pRegionBelow != NULL)
    {
      pLevel2Region = pLevel2Region->pRegionBelow;
    }
  }

  return pLevel2Region;

}


static uint32 HLAAnalysisPotVeh2ndLevelCalculateDrivenDistance( const HLAR_t_RequiredInputs* pRequiredIn )
{
  uint32 drivenDist;
  
  if(pRequiredIn->s_Sig.s_MotionState.f32_Speed > 0)
  {
     drivenDist = (uint32)(100.0f * (pRequiredIn->s_Sig.s_MotionState.f32_Speed * pRequiredIn->s_Par.s_CameraParameter.f32_cycleTime));
  }
  else
  {
    drivenDist = 0;
  }

  return drivenDist;
}


static float32 HLAAnalysisPotVeh2ndLevelCalculateSize( const HLASegLineRegion_t* pLevel2Region)
{
  float32 size;

  if(pLevel2Region == NULL)
  {
    size = 0.0f;
  }
  else
  {
    size = (float32)((pLevel2Region->x2 - pLevel2Region->x1) + (pLevel2Region->y2 - pLevel2Region->y1));
  }

  return size;
}


/* **************************************************************************** 
  Functionname:     HLAIconIdentificationInit                           */ /*!  
  Description:      Init Icon Identification (update counter)

  @param[in]        HLATrack_t*                  pTrack             current Track
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAIconIdentificationInit( HLATrack_t* pTrack )
{
  /* update cycle count for all potential vehicle tracks */
  if (    (pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1)
       || (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
     )
  {
    if (pTrack->iconState.cyclesNoClass < UI8_T_MAX)
    {
      pTrack->iconState.cyclesNoClass++;
    }
  }

  /* update cycle count for all potential city lights */
  /* ~CodeReview ~ID:0b335dace4d85d6fe4ec0a1401bf3122 ~Reviewer:CW01\uidt9253 ~Date:3/22/2012 ~Priority:3 ~Comment:create function for boolean expression (potential city candidate) */
  if (    (pTrack->statusAnalysisMisc.isSceneStreetLamp == 1)
       || (pTrack->statusAnalysisMisc.isSceneStreetLampLowInt == 1)
       || (pTrack->statusAnalysisMisc.isLeavingStreetLamp == 1)
    )
  {
    if (pTrack->iconStateCity.cyclesNoClass < UI8_T_MAX)
    {
      pTrack->iconStateCity.cyclesNoClass++;
    }
  }

  /* count classResultSum back to zero when first level analysis becomes inactive */
  if (    (pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 0)
       && (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 0)
       && (pTrack->iconState.classResultSum > 0)
     )
  {
    pTrack->iconState.classResultSum = CML_Max(0, pTrack->iconState.classResultSum + HLA_ICON_RESULT_NEG_CLASS_RESPONSE);
  }
}

/* **************************************************************************** 
  Functionname:     HLAIconIdentificationVerifyPosition                           */ /*!  
  Description:      Calculate the position of the light in the image and verify it in the icon

  @param[in]        HLATrack_t*                  pTrack             current Track
  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
static void HLAIconIdentificationCalcAndVerifyPosition( const HLAIconData_t*                        pIcon,
                                                        const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                                                              HLATrack_t*                           pTrack,
                                                              HLAKalmanMeasPosPix_t*                lightPosPix
                                                      )
{
  sint32 xDiffTrack2Center = 0;
  sint32 yDiffTrack2Center = 0;

  /* check if track was not lost and track has a valid light-pointer */
  if (    (pTrack->lost_time > 0)
       || (pTrack->light_ref == NULL)
     )
  {
    if (pTrack->iconState.status.iconRequested == 1)
    {
      pTrack->iconState.status.skippedBadPosition = 1;
    }
    if (pTrack->iconStateCity.status.iconRequested == 1)
    {
      pTrack->iconStateCity.status.skippedBadPosition = 1;
    }       
  }
  else
  { /* calculate pixel-coordinates (x,y in image) with the given world-coordinates of the track */  
    HLATrackMeasGetPixCoordinates( lightPosPix, pTrack->light_ref, pTracking3DParamsMeasurement );

    xDiffTrack2Center = (sint32)(CML_f_Abs(lightPosPix->x_center_pix - (pIcon->Pos.X1 + (pIcon->Pos.Width  / 2))));
    yDiffTrack2Center = (sint32)(CML_f_Abs(lightPosPix->y_center_pix - (pIcon->Pos.Y1 + (pIcon->Pos.Height / 2))));

    /* if the pixel-coordinates of the track is to far away from the center-position of the Icon, skip as bad position */
    if (    ( xDiffTrack2Center > ((pIcon->Pos.Width  - HLA_ICON_FULLIMAGE_WIDTH) / 2 ))
         || ( yDiffTrack2Center > ((pIcon->Pos.Height - HLA_ICON_FULLIMAGE_HEIGHT) / 2 ))
       )
    {
      if (pTrack->iconState.status.iconRequested == 1)
      {
        pTrack->iconState.status.skippedBadPosition = 1;
      }
      if (pTrack->iconStateCity.status.iconRequested == 1)
      {
        pTrack->iconStateCity.status.skippedBadPosition = 1;
      }  
    }
  }
}
