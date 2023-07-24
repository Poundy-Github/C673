/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysisstreetlamps.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-05-24

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysisstreetlamps.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:44CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:00CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:18CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.9 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysisstreetlamps.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysisstreetlamps.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.8 2014/03/04 16:51:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:52 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.7 2013/03/04 11:15:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:06 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.6 2012/03/22 10:28:24CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Code review findings
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 22, 2012 10:28:25 AM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.5 2011/09/29 16:33:35CEST Brunn, Marcus (brunnm) 
  CHANGE:                 added Streetlamp init function
  CHANGE:                 --- Added comments ---  brunnm [Sep 29, 2011 4:33:35 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.4 2011/09/29 16:25:00CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 added Streetlamp init function
  CHANGE:                 --- Added comments ---  brunnm [Sep 29, 2011 4:25:00 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.3 2011/09/06 13:58:19CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - remove redundant structure motionData from blackboard and replaced by input interface motionState
  CHANGE:                 --- Added comments ---  uidt9253 [Sep 6, 2011 1:58:19 PM CEST]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.2 2011/06/21 16:16:26CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> first integration of city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Jun 21, 2011 4:16:26 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.1 2011/05/26 17:43:20CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj

**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_ANALYSIS_STREET_LAMPS_INCLUDED
#define HLA_ANALYSIS_STREET_LAMPS_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_cam_rot.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do the Street Lamp Analysis . 
- HLAStreetLamp_Behave : check the 2D signature, the 3D static position, the dynamic/static status, the ligth size
- HLAStreetLamp_Shape : use a low pass filter to detect track intensity oscillation (a maximum of 40 tracks can be analyzed simultaneously)
- HLAStreetLamp_Decision : update isStreetLamp identification result
- HLASLAddLights : select potential tracks to be analyzed in HLAStreetLamp_Shape
- HLASLRemoveLights : select tracks not suitable for HLAStreetLamp_Shape
*/

void HLAAnalysisStreetLamps(      HLASLInput_t*           pIn,
                            const HLA_t_MotionState*      pMotionData, 
                                  HLATrack_t*             pTLB_Start,
                            const HLACameraData_t*        pCamData,
                            const HLA_t_StreetLampsParam* pParams, 
                            const HLACamRot*              pcamRot,
                            const HLA_t_CameraParameter*  pCamPar);

/* Do the street lamp analysis initialization */

void HLAAnalysisStreetLampsInit(      HLASLInput_t*               pSLInput,
                                      HLA_SL_ListNode_t*          pFreeStreetLampsBuffer,
                                const HLA_t_Tracking3DParameters* pTracking3DParameters
                               );
/* avoid cyclic binding ---------------------------------------------------*/
#endif