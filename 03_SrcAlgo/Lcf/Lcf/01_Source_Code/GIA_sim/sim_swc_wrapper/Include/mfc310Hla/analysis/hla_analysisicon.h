/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysisicon.h

  DESCRIPTION:            Extract and classify an image area (icon)

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-04-04

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysisicon.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:42CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:56CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:15CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.43 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysisicon.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysisicon.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.42 2014/03/12 18:07:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:31 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.41 2014/02/18 13:21:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:51 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.40 2014/02/06 16:02:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:37 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.39 2014/01/28 11:46:53CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 -fixed: use only global add features
  CHANGE:                 -remove unused parameter
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 11:46:54 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.38 2014/01/28 10:48:10CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 -renaming of some unclear variables
  CHANGE:                 -changes to meet coding guideline
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:11 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.37 2014/01/13 16:58:17CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 pass pHighwayData to IconClassifier
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 13, 2014 4:58:17 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.36 2014/01/10 18:33:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:22 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.35 2013/12/13 16:45:08CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:08 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2013/12/04 16:18:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Use L2 Cache for SegLightBuffer, SegLineRegionBuffer
  CHANGE:                 Fixed deadlock in segmentation
  CHANGE:                 
  CHANGE:                 Review by AlexM.
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 4, 2013 4:18:28 PM CET]
  CHANGE:                 Change Package : 207432:10 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.33 2013/11/21 17:53:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:47 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.32 2013/11/21 11:45:49CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 moved LRF classifier to seperate header files
  CHANGE:                 --- Added comments ---  uidv8776 [Nov 21, 2013 11:46:06 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.31.1.2 2013/11/21 13:37:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:34 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.31.1.1 2013/11/12 13:45:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added restrict keyword
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:48 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Fixed Lint errors
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 8, 2013 1:23:45 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.30 2013/03/21 11:47:41CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 adding trackID to debugIcon
  CHANGE:                 --- Added comments ---  uidv8776 [Mar 21, 2013 11:47:41 AM CET]
  CHANGE:                 Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGE:                 Revision 1.29 2013/03/08 10:31:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:01 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.28 2013/03/04 11:15:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:10 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.27 2013/02/05 11:40:59CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - fix misra warnings
  CHANGE:                 --- Added comments ---  uidt9253 [Feb 5, 2013 11:41:00 AM CET]
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGE:                 Revision 1.26 2013/02/04 10:34:06CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 added possibility for for direct image access for icon creation.
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 4, 2013 10:34:07 AM CET]
  CHANGE:                 Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGE:                 Revision 1.25 2013/01/11 10:35:58CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - icon classifier uses additional features from other HLA components (like tracking information) in MLP classification
  CHANGE:                 - visualization of icon LED detection information
**************************************************************************** */

#ifndef HLA_ANALYSISICON_H__
#define HLA_ANALYSISICON_H__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_analysis.h"  
#include "hlar_ext.h"
#include "hla_debug.h"

#ifdef HLA_LRF_ON_EVE
#include "hla_eve_ext.h"
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_ICON_WINDOW_WIDTH           20
#define HLA_ICON_WINDOW_HEIGHT          40

/* must be multiple of 4 or HLA_ICON_COLORIMAGE_WIDTH/2 is not the same 
   Bayer Pattern type like the upper left corner of the color image */
#define HLA_ICON_COLORIMAGE_WIDTH       20
#define HLA_ICON_COLORIMAGE_HEIGHT      20

#define HLA_ICON_FULLIMAGE_WIDTH        40
#define HLA_ICON_FULLIMAGE_HEIGHT       40

/*****************************************************************************
  MACROS 
*****************************************************************************/
#define HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA    4

#define HLA_ICON_LRF_NRF_XENONLED         15
#define HLA_ICON_LRF_NRF_HALOGEN          15
#define HLA_ICON_LRF_NRF_REDLIGHT         5
#define HLA_ICON_LRF_NRF_CITYLIGHT        5

#define HLA_ICON_LRF_FS                   5
#define HLA_ICON_LRF_DS                   2
#define HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH  ((HLA_ICON_WINDOW_WIDTH/HLA_ICON_LRF_DS) - (HLA_ICON_LRF_FS/HLA_ICON_LRF_DS))
#define HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT ((HLA_ICON_WINDOW_HEIGHT/HLA_ICON_LRF_DS) - (HLA_ICON_LRF_FS/HLA_ICON_LRF_DS))

#define HLA_ICON_LRF_HIDDEN_NEURONS       1
#define HLA_ICON_LRF_SIGMOID_STEEPNESS    0.9f

#define HLA_ICON_LRF_FIXPOINT_SCALE_LOG2  23
#define HLA_ICON_LRF_FIXPOINT_SCALE       8388608  // 2^(HLA_ICON_LRF_FIXPOINT_SCALE_LOG2 - 1)
#define HLA_ICON_TANH_LOOKUP_TABLE_SIZE   10

#define HLA_ICON_ADDITIONAL_FEATURES     9

#define HLA_ICON_REGROW_PIXEL_STACK_SIZE        (HLA_ICON_COLORIMAGE_WIDTH*(HLA_ICON_COLORIMAGE_HEIGHT/2))

#define HLA_ICON_RESULT_POS_CLASS_RESPONSE      8
#define HLA_ICON_RESULT_NEG_CLASS_RESPONSE      (-8)


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct 
{
  sint32 offset;
  uint32 scale;
} HlaTanhLUT_t;

typedef enum 
{
  LRF_TYPE_XENONLED  = 0u,
  LRF_TYPE_HALOGEN   = 1u,
  LRF_TYPE_REDLIGHT  = 2u,
  LRF_TYPE_CITYLIGHT = 3u,
  LRF_TYPE_LAST      = SI32_T_MAX
} HlaLrfTypes_t;

#ifdef HLA_LRF_ON_EVE
#define HLA_LRF_INPUTS_STRUCT(LRF_NRF,TYPE_NAME) \
typedef struct  \
{ \
  HlaLrfTypes_t lrfType; \
  uint8 lrf_NRF; \
  ARRAY(sint32, LRF_NRF, lrf_TH); \
  /* lrf_RF[LRF_NRF][HLA_ICON_LRF_FS][HLA_ICON_LRF_FS]  but must be a multiple of HLA_EVE_LRF_NUM_RFS_PARALLEL */ \
  ARRAY(sint32, ((((LRF_NRF - 1) / HLA_EVE_LRF_NUM_RFS_PARALLEL) + 1) * HLA_EVE_LRF_NUM_RFS_PARALLEL) * (HLA_ICON_LRF_FS * HLA_ICON_LRF_FS), lrf_RF); \
  /* lrf_hiddenNeuronWeights[HLA_ICON_LRF_HIDDEN_NEURONS][1 + LRF_NRF*[HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT][HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH] + HLA_ICON_ADDITIONAL_FEATURES 
   * but must be a multiple of HLA_EVE_LRF_NUM_RFS_PARALLEL 
   */ \
  ARRAY(sint32, HLA_ICON_LRF_HIDDEN_NEURONS * (1 + (((((LRF_NRF - 1) / HLA_EVE_LRF_NUM_RFS_PARALLEL) + 1) * HLA_EVE_LRF_NUM_RFS_PARALLEL) * (HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT * HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH)) + HLA_ICON_ADDITIONAL_FEATURES), lrf_hiddenNeuronWeights); \
  ARRAY(float32, HLA_ICON_LRF_HIDDEN_NEURONS + 1, lrf_outputNeuronWeights); \
} TYPE_NAME
#else
#define HLA_LRF_INPUTS_STRUCT(LRF_NRF,TYPE_NAME) \
typedef struct  \
{ \
  HlaLrfTypes_t lrfType; \
  uint8 lrf_NRF; \
  ARRAY(sint32, LRF_NRF, lrf_TH); \
  /* lrf_RF[LRF_NRF][HLA_ICON_LRF_FS][HLA_ICON_LRF_FS] */ \
  ARRAY(sint32, LRF_NRF * (HLA_ICON_LRF_FS * HLA_ICON_LRF_FS), lrf_RF); \
  /* lrf_hiddenNeuronWeights[HLA_ICON_LRF_HIDDEN_NEURONS][1 + LRF_NRF*[HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT][HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH] + HLA_ICON_ADDITIONAL_FEATURES */ \
  ARRAY(sint32, HLA_ICON_LRF_HIDDEN_NEURONS * (1 + (LRF_NRF * (HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT * HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH)) + HLA_ICON_ADDITIONAL_FEATURES), lrf_hiddenNeuronWeights); \
  ARRAY(float32, HLA_ICON_LRF_HIDDEN_NEURONS + 1, lrf_outputNeuronWeights); \
} TYPE_NAME
#endif

HLA_LRF_INPUTS_STRUCT(HLA_ICON_LRF_NRF_XENONLED, HlaLrfInputsXenonLED_t);
HLA_LRF_INPUTS_STRUCT(HLA_ICON_LRF_NRF_HALOGEN, HlaLrfInputsHalogen_t);
HLA_LRF_INPUTS_STRUCT(HLA_ICON_LRF_NRF_REDLIGHT, HlaLrfInputsRedLight_t);
HLA_LRF_INPUTS_STRUCT(HLA_ICON_LRF_NRF_CITYLIGHT, HlaLrfInputsCityLight_t);
/* Only needed during simulation or evalboard, i.e. #ifdef ICON_MEASFREEZE */
typedef struct  
{
  HLAIconPosition_t pos;
  boolean cityIcon;
  IconState_t iconState;
  uint8 defaultClassifierResult;
  uint8 iconPreProcImage[HLA_ICON_WINDOW_WIDTH * HLA_ICON_WINDOW_HEIGHT];
  uint8 iconPreProcSegmentationImage[HLA_ICON_COLORIMAGE_WIDTH * HLA_ICON_COLORIMAGE_HEIGHT];
  sint16 trackID;
} DebugIcon_t;

typedef struct
{
  DebugIcon_t debugIcon[2 * HLA_ICON_ANALYSIS_MAX_BOXES];
  uint8 count;
} HLADebugIconList_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

void HLAAnalysisIconInit();

/*! hla icon classification */
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
                          );

void HLAIconMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);

#endif // HLA_ANALYSISICON_H__
