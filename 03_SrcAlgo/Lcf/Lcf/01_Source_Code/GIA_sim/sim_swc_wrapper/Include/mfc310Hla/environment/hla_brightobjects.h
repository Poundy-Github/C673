/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_brightobjects.h

  DESCRIPTION:            Detection of bright objects which could blind the driver (headlamp dimming candidates)

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-11-07

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_brightobjects.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:56CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:35CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:27CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.5 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_brightobjects.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_brightobjects.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.4 2014/03/10 13:05:13CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - changed DimmingAreas to match the specs of BMW
  CHANGE:                  - implemented visualization
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 10, 2014 1:05:14 PM CET]
  CHANGE:                 Change Package : 224162:1 http://mks-psad:7002/im/viewissue?selection=224162
  CHANGE:                 Revision 1.3 2012/10/05 12:44:45CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:44:45 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.2 2012/04/02 16:52:40CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - added comments from code review
  CHANGE:                 --- Added comments ---  uidt9253 [Apr 2, 2012 4:52:40 PM CEST]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.1 2011/11/07 18:42:40CET Zechner, Stefan (uidt9253) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

#ifndef HLA_BRIGHTOBJECTS_H__
#define HLA_BRIGHTOBJECTS_H__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hlar_ext.h"

#include "hla_segmentation.h"

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
void HLABrightObjects(      HLATrack_t*   pTrackStart,
                      const HLASegOut_t*  pSegOut
                     );


#endif // HLA_BRIGHTOBJECTS_H__
