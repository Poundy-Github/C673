/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    Renesas M32R

  COMPONENT:              HLA

  MODULNAME:              hla_analysis.h

  DESCRIPTION:            Functions for light track analysis.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          07.11.2006

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysis.h  $  
  CHANGE:                 Revision 1.1 2021/12/13 17:26:40CET Wang, David (Wangd3)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj  
  CHANGE:                 Revision 1.0 2017/03/03 10:37:51CET Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj  
  CHANGE:                 Revision 1.1 2014/04/17 16:05:12CEST Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj  
  CHANGE:                 Revision 1.8 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Member moved from hla_analysis.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysis.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.  
  CHANGE:                 Revision 1.7 2014/03/12 18:07:36CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Added LRF on EVE  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:36 PM CET]  
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642  
  CHANGE:                 Revision 1.6 2014/02/06 16:02:45CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)  
  CHANGE:                 Centralized Null pointer checks  
  CHANGE:                 Refactored dframe calculation  
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:46 PM CET]  
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576  
  CHANGE:                 Revision 1.5 2014/01/28 10:48:07CET Schillinger, Patrick (uidv8776)   
  CHANGE:                 -renaming of some unclear variables  
  CHANGE:                 -changes to meet coding guideline  
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:07 AM CET]  
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150  
  CHANGE:                 Revision 1.4 2014/01/10 18:33:26CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 First part of LRF on EVE (disabled)  
  CHANGE:                 Merged LRF inputs into one struct  
  CHANGE:                 Fixed exception handling of internal cali   
  CHANGE:                 Removed all tabs in the code and further clean-up  
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:26 PM CET]  
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642  
  CHANGE:                 Revision 1.3 2013/12/13 16:45:11CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Service functions are now passed in one struct  
  CHANGE:                 SDLfile definitions moved to separate file  
  CHANGE:                 Revision 1.2 2013/11/21 17:53:55CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Merge from NEW_SEG branch  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:55 PM CET]  
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.1.1.2 2013/11/12 13:44:42CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed SegOut from function arguments  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:43 PM CET]  
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787  
  CHANGE:                 Revision 1.1.1.1 2013/10/18 13:27:30CEST Brunn, Marcus (brunnm)   
  CHANGE:                 intial version of new segmentation  
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:30 PM CEST]  
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639  
  CHANGE:                 Revision 1.1 2013/08/05 17:01:54CEST Manz, Alexander (uidv8777)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj  
  CHANGE:                 Revision 1.16.1.37 2013/06/21 16:16:58CEST Fischer, Alexander (uidv8778)   
  CHANGE:                 Moved chain of light visu from hla_analysischain to sim_hla_visualisation_draw  
  CHANGE:                 --- Added comments ---  uidv8778 [Jun 21, 2013 4:16:58 PM CEST]  
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296  
  CHANGE:                 Revision 1.16.1.36 2013/03/08 10:31:09CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Updated to latest RTE  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:09 AM CET]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.16.1.35 2013/03/06 11:19:28CET Zechner, Stefan (uidt9253)   
  CHANGE:                 - remove dependencies to algo_common  
  CHANGE:                 - replace HLA type Pix16_t by RTE type t_PixelData  
  CHANGE:                 --- Added comments ---  uidt9253 [Mar 6, 2013 11:19:28 AM CET]  
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950  
  CHANGE:                 Revision 1.16.1.34 2013/03/04 11:14:46CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Integrated cam_rot into HLA  
  CHANGE:                 bug fix in jacobian calculation  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:47 AM CET]  
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.16.1.33 2013/02/05 11:40:58CET Zechner, Stefan (uidt9253)   
  CHANGE:                 - fix misra warnings  
  CHANGE:                 --- Added comments ---  uidt9253 [Feb 5, 2013 11:40:58 AM CET]  
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_ANALYSIS_INCLUDED
#define HLA_ANALYSIS_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_cam_rot.h"
#include "hla_main.h"
#include "hla_base.h"
#include "hlar_ext.h"
#include "hla_debug.h"
#include "hla_tracking.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* analysis data struct */
typedef struct
{
  /* red reflector area */
  float32 RedReflectorDensity;
  boolean bRedReflectorArea;

  uint32  EveErrorCode;
} HLAAnalysisData_t;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do the analysis. */
void HLAAnalysis( const HLAR_t_RequiredInputs*                pRequiredIn,
                  const HLATracking3DOutput_t*                pTrackOut,
                  HLATurnOffReason_t*                         pTOR,
                  const HLACamRot*                            pCamRot,
                  const HLACameraData_t*                      pCamData,
                  const RTE_HLA_TrafficStyle                  eTrafficStyle, 
                  /* icons */
                  HLAIconData_t                               IconData[],
                  HLASLInput_t*                               pSLInput,
                  const HLA_t_AnalysisParameters*             pAnalysisParameters,
                  HLAAnalysisData_t*                          pAnalysisData,
                  const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                  const HLA_t_Highway*                        pHighwayData,
                  HLAChainOfLightData_t*                      pCoLData,
                  HLAWeatherData_t*                           pWeatherData,
                  HLADebugOutputs_t*                          phlaDebugOutputs,
                  const AS_t_ServiceFuncts*                   Services
                 );


void HLAAnalysisInit(const HLAR_t_RequiredInputs* ps_In, HLAIconData_t IconData[], t_PixelData Icon[], HLAAnalysisData_t *pAnalysisData);

/* avoid cyclic binding ---------------------------------------------------*/
#endif




