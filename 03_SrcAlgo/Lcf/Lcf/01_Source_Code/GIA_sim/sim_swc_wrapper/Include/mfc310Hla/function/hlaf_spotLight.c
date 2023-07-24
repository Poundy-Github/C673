/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_spotLight.c

  DESCRIPTION:            HLAF spot light control

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-07-18

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hlaf_spotLight.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:05CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:50CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:36CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.20 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_spotLight.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_spotLight.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGE:                 Revision 1.19 2014/03/10 13:20:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:49 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2014/02/24 11:44:35CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - tunnel detection types changed
  CHANGE:                  - removed some unnecessary flags from the simulation INI file (all related to very old visu)
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 24, 2014 11:44:36 AM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.17 2014/01/21 09:12:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:13:00 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2013/11/21 17:53:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:45 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15.1.1 2013/11/21 13:38:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:38:13 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2013/03/13 17:33:01CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:33:01 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.14 2013/03/12 10:59:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:28 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.13 2013/03/11 16:48:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced  no longer needed macros by RTE ones
  CHANGE:                 - HLAR_MAX_NUM_DEFECT_PIXEL
  CHANGE:                 - HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
  CHANGE:                 - HLAF_NIGHTVIEW_OBJECTS
  CHANGE:                 - HLA_FINGERPRINT_PIXELS
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:48:21 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.12 2013/03/06 12:43:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed compiler warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 6, 2013 12:43:55 PM CET]
  CHANGE:                 Change Package : 167173:24 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.11 2013/03/04 11:14:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:49 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.10 2013/01/24 19:13:45CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLAF_t_eNightViewObjectType
  CHANGE:                 - HLAF_t_eNightViewSpot
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 7:13:46 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.9 2012/10/18 17:56:05CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:56:06 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.8 2012/09/03 12:34:25CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed many FP and FN for 2. SpotLight Object
  CHANGE:                 --- Added comments ---  brunnm [Sep 3, 2012 12:34:28 PM CEST]
  CHANGE:                 Change Package : 158042:1 http://mks-psad:7002/im/viewissue?selection=158042
  CHANGE:                 Revision 1.7 2012/04/24 12:46:53CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - add visu: red line for future predicted vehicle position
  CHANGE:                 --- Added comments ---  uidt9253 [Apr 24, 2012 12:46:55 PM CEST]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.6 2012/04/23 21:02:40CEST Brunn, Marcus (brunnm) 
  CHANGE:                 used si16_delta_x instead of si16_delta_x_lp
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 9:02:41 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.5 2012/04/21 15:04:39CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:40 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.4 2012/04/02 16:52:48CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - added comments from code review
  CHANGE:                 --- Added comments ---  uidt9253 [Apr 2, 2012 4:52:48 PM CEST]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.3 2012/01/24 16:59:11CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - debugViewSpotLight: visualization of the night view targets
  CHANGE:                 --- Added comments ---  uidt9253 [Jan 24, 2012 4:59:12 PM CET]
  CHANGE:                 Change Package : 90757:1 http://mks-psad:7002/im/viewissue?selection=90757
  CHANGE:                 Revision 1.2 2011/12/01 17:43:26CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - hlaf nightview blinking spot uses new interface vehicle parameters f32_SpotLightTolerance_rad and f32_HeadLampLatency
  CHANGE:                 - spot light tolerance adds additional space to the spot width for the night view blinking safety area
  CHANGE:                 - correct prediction based on the specified head lamp latency of the hla objects
  CHANGE:                 --- Added comments ---  uidt9253 [Dec 1, 2011 5:43:26 PM CET]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.1 2011/07/18 19:42:49CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>

#include "hlaf_spotLight.h"

#ifdef PC_SIM
#include "stdafx.h"
#include "sim_headlightassist.h"
#include "param.h"

extern CSimHeadLightAssist* pHLAInstance;
extern HLACamRot            hlaCamRot;
#endif


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

void HLAFSpotLight(const HLA_t_CameraParameter                    *ps_CameraParameter,
                   const RTE_HLA_ParameterHeadlight_t             *ps_HeadlightParameter,
                   const HLAF_t_NightView                         *ps_NightViewIn,
                   const HLA_t_ObjectList                         *ps_ObjectList, 
                   HLAF_t_NightView                               *ps_NightViewOut)
{
  uint32 i, k;
  HLAF_t_NightViewObject* pNightViewObject = &ps_NightViewOut->as_Obj[0];
  
  const float32 safetyWidth_rad = (0.5f * ps_HeadlightParameter->SpotLightWidth) + ps_HeadlightParameter->SpotLightTolerance;
  /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() */
  const float32 predictedAnglePerDeltaX = (ps_HeadlightParameter->HeadLampLatency / ps_CameraParameter->f32_cycleTime) * atanf(1.0f / ps_CameraParameter->s_FocalLength.f32_x);

  (void)memcpy(ps_NightViewOut, ps_NightViewIn, sizeof(HLAF_t_NightView));

  for (i=0; i<RTE_HLAF_NIGHTVIEW_OBJECT_LIST_LENGTH; i++)
  {
    const HLA_t_Object* pHLAObj = &ps_ObjectList->as_Object[0];

    if ((pNightViewObject->e_Spot == RTE_HLAF_NV_SPOT_BLINK) ||
        (pNightViewObject->e_Spot == RTE_HLAF_NV_SPOT_CONT))
    {

      for (k=0; k<ps_ObjectList->ui32_NumVehicles; k++)
      {
        const float32 predictedObjectHorAng = pHLAObj->f32_ObjectHorAng_rad - (predictedAnglePerDeltaX * pHLAObj->si16_delta_x);

        if ((predictedObjectHorAng > (pNightViewObject->f32_HorAng_rad - safetyWidth_rad)) &&
            (predictedObjectHorAng < (pNightViewObject->f32_HorAng_rad + safetyWidth_rad))
           )
        {
          pNightViewObject->e_Spot = RTE_HLAF_NV_SPOT_ABORT;
          break;
        }

        pHLAObj++;
      }
    }

    pNightViewObject++;
  }
}/* PRQA S 861 1 */
