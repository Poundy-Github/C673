/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_spotLight.h

  DESCRIPTION:            HLAF spot light control

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-07-18

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hlaf_spotLight.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:06CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:51CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:37CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.5 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_spotLight.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_spotLight.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGE:                 Revision 1.4 2013/03/13 17:33:17CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:33:17 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.3 2012/04/02 16:52:48CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - added comments from code review
  CHANGE:                 --- Added comments ---  uidt9253 [Apr 2, 2012 4:52:48 PM CEST]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.2 2011/12/01 17:43:25CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - hlaf nightview blinking spot uses new interface vehicle parameters f32_SpotLightTolerance_rad and f32_HeadLampLatency
  CHANGE:                 - spot light tolerance adds additional space to the spot width for the night view blinking safety area
  CHANGE:                 - correct prediction based on the specified head lamp latency of the hla objects
  CHANGE:                 --- Added comments ---  uidt9253 [Dec 1, 2011 5:43:25 PM CET]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.1 2011/07/18 19:42:50CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

#ifndef HLA_SPOTLIGHT_H__
#define HLA_SPOTLIGHT_H__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_ext.h"


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
                   HLAF_t_NightView                               *ps_NightViewOut);

#endif
