/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_errorCheck.h

  DESCRIPTION:            Error checking routines

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-06-29

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_errorCheck.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:33CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:44CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:08CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.22 2014/03/12 18:07:32CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:32 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.21 2014/02/07 16:33:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed dframe calculation
  CHANGE:                 Updated time meas inside segmentation
  CHANGE:                 Updated HIL according to latest changes
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 4:33:01 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.20 2014/02/06 16:02:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:40 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.19 2013/10/24 12:30:42CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added NULL pointer check of image data pointer
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 12:30:42 PM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.18 2013/08/09 17:53:32CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Eve bug fixes:
  CHANGE:                 - # of seglines of function roi
  CHANGE:                 - eve return code
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 9, 2013 5:53:33 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.17 2013/03/11 14:33:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:03 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.16 2013/03/04 11:14:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
**************************************************************************** */

#ifndef HLA_ERRORCHECK_H__
#define HLA_ERRORCHECK_H__

/* ~CodeReview ~ID:52764fe24974ce9db47e728d5c3fab75 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:missing documentation and function header descriptions */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hlar_ext.h"
#include "hla_cam_rot.h"
#include "hla_segmentation.h"
#include "hla_analysis.h"

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


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAErrorCheck_Init(void);

boolean HLAErrorCheck_NullPointer( const HLAR_t_RequiredInputs*  pReqIn,
                                   const HLAR_t_ProvidedOutputs* pProvOut,
                                   const t_PixelData*            pImgData,
                                   const AS_t_ServiceFuncts*     Services,
                                         HLA_t_SystemInfo*       pSystemInfo
                                  );

uint8 HLAErrorCheck_Vehicle(HLA_t_SystemInfo                           *ps_SystemInfo,
                            const HLA_t_HeadlightState                 *pHeadlightState);

uint8 HLAErrorCheck_ImageData(HLA_t_SystemInfo*                 ps_SystemInfo,
                              const HLA_t_ImagerCharacteristic* imagerCharacteristic,
                              const HLA_t_CameraParameter*      cameraParameter
                             );

uint8 HLAErrorCheck_Calibration(HLA_t_SystemInfo                           *ps_SystemInfo,
                                const HLA_t_CameraParameter                *pCamParam,
                                const HLACameraData_t                      *pCamData,
                                const HLACamRot                            *pCamRot);

uint8 HLAErrorCheck_Input( const HLAR_t_RequiredInputs*    pIn,
                           const HLA_t_MotionState*        pMotionState,
                           const HLA_t_Availability*       pAvailability,
                           const RTE_HLAR_BrightnessState  eBrightnessState,
                           const sint16                    dFrameCnt,
                                 HLA_t_SystemInfo*         ps_SystemInfo
                          );

uint8 HLAErrorCheck_Fatal(HLA_t_SystemInfo                           *ps_SystemInfo,
                          const HLA_t_DefectPixelList                *pDefectPixelList
                         );

uint8 HLAErrorCheck_Segmentation( const HLASegData_t*     pSegData,
                                        HLA_t_SystemInfo* pSystemInfo
                                );
uint8 HLAErrorCheck_Analysis( const HLAAnalysisData_t* pAnalysisData,
                                    HLA_t_SystemInfo*  pSystemInfo
                             );

#endif
