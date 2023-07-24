/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_highway.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-02-14

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_highway.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:57CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:38CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:29CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.20 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_highway.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_highway.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.19 2014/01/10 18:33:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:33 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.18 2013/04/19 14:49:45CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Implemented BMW Highway Codierparamter
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 19, 2013 2:49:45 PM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.17 2013/03/11 14:33:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:05 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.16 2013/03/08 10:31:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:03 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.15 2013/03/04 11:14:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:54 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.14 2013/01/22 12:06:59CET Fischer, Alexander (uidv8778) 
  CHANGE:                 HLA-R Internal Highway Decision
  CHANGE:                 --- Added comments ---  uidv8778 [Jan 22, 2013 12:06:59 PM CET]
  CHANGE:                 Change Package : 173113:1 http://mks-psad:7002/im/viewissue?selection=173113
  CHANGE:                 Revision 1.13 2011/09/06 13:58:09CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - remove redundant structure motionData from blackboard and replaced by input interface motionState
  CHANGE:                 --- Added comments ---  uidt9253 [Sep 6, 2011 1:58:09 PM CEST]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.12 2011/07/04 17:22:47CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 interface for MFC310 Release 3.1.0 (object list, error list)
  CHANGE:                 --- Added comments ---  brunnm [Jul 4, 2011 5:22:47 PM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.11 2011/06/21 16:25:38CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> first integration of city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Jun 21, 2011 4:25:38 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.10 2011/06/07 18:30:36CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Warm Start for Highway Debugging
  CHANGE:                 --- Added comments ---  uidt2765 [Jun 7, 2011 6:30:36 PM CEST]
  CHANGE:                 Change Package : 54240:1 http://mks-psad:7002/im/viewissue?selection=54240
  CHANGE:                 Revision 1.9 2011/05/23 13:58:43CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 - renamed seg_TracklistNode into HLATrack_t
  CHANGE:                 - renamed seg_ListNode into HLASegLight_t
  CHANGE:                 --- Added comments ---  brunnm [May 23, 2011 1:58:43 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.8 2011/04/14 19:01:22CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D tracking clean-up.
  CHANGE:                 Remove use of global variables.
  CHANGE:                 Set-up of an input/output/data archi
  CHANGE:                 --- Added comments ---  uid28828 [Apr 14, 2011 7:01:22 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.7 2011/04/14 15:48:17CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Solve MISRA Problems
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 14, 2011 3:48:17 PM CEST]
  CHANGE:                 Change Package : 54240:1 http://mks-psad:7002/im/viewissue?selection=54240
**************************************************************************** */
/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_HIGHWAY_INCLUDED
#define HLA_HIGHWAY_INCLUDED

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

/* Input */
typedef struct
{
  HLATrack_t*                         pTLB;
  const HLACameraData_t*              pCamData;
  const HLACamRot*                    pcamRot;
  const HLA_t_MotionState*            pMotionData;
  const RTE_HLA_TrafficStyle*         pTrafficStyle;
  const HLA_t_CameraParameter*        pCameraParameter;
  const HLA_t_Tracking3DParameters*   pTracking3DParams;
  RTE_HLAR_BrightnessState            eBrightnessState;
}HLAHighwayInput_t;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do the Highway Detection . */
void HLAHighwayInit( HLAHighwayInternalData_t* pD,HLA_t_Highway* pOut);

/*! Do the Highway Detection . */
void HLAHighway( HLAHighwayInternalData_t* pData,HLA_t_Highway* pOut,const HLAHighwayInput_t* pIn,const HLA_t_HighwayParameters* pParams,const RTE_HLAR_ParameterHighway_t* pHwyParams);

/* avoid cyclic binding ---------------------------------------------------*/
#endif