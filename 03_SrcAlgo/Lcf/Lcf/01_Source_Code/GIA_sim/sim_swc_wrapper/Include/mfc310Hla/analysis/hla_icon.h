/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_icon.h

  DESCRIPTION:            Functions for icon handling.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          05.05.2011

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_icon.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:46CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:03CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:19CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.7 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_icon.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_icon.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.6 2013/11/21 17:53:15CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:15 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.5.1.2 2013/11/12 13:44:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:41 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.5.1.1 2013/10/18 13:27:55CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:55 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.5 2013/02/05 11:41:02CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - fix misra warnings
  CHANGE:                 --- Added comments ---  uidt9253 [Feb 5, 2013 11:41:02 AM CET]
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGE:                 Revision 1.4 2013/02/04 10:34:03CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 added possibility for for direct image access for icon creation.
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 4, 2013 10:34:04 AM CET]
  CHANGE:                 Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGE:                 Revision 1.3 2012/01/19 09:51:52CET Brunn, Marcus (brunnm) 
  CHANGE:                 updated diagnosis debug message (64Bit)
  CHANGE:                 - added icon result (HB on), HLAF turn off reason, keep off reason and hla version
  CHANGE:                 --- Added comments ---  brunnm [Jan 19, 2012 9:51:52 AM CET]
  CHANGE:                 Change Package : 93893:1 http://mks-psad:7002/im/viewissue?selection=93893
  CHANGE:                 Revision 1.2 2011/05/10 16:41:11CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 removed MISRA Errros
  CHANGE:                 --- Added comments ---  brunnm [May 10, 2011 4:41:11 PM CEST]
  CHANGE:                 Change Package : 53526:2 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.1 2011/05/06 05:46:27CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE: 
  CHANGE:                 
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_ICON_INCLUDED
#define HLA_ICON_INCLUDED

/* includes */
#include "hla_type.h"
#include "hlar_ext.h"
#include "hla_cfg.h"
#include "hla_base.h"


/*****************************************************************************
  Variables 
*****************************************************************************/
typedef struct
{
  HLAIconList_t     hlaIconList[HLA_ICON_MAX_BOXES];
  HLAIconList_t     *phlaIconList;  /* list of all requested icons */
  uint32            iNoIcons;       /* number of requested icons   */
} hlaIcon_t;

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

void HLAIconInit(hlaIcon_t*     pIcon,
                 t_PixelData*   pImg);

void HLAIconPrepareThisFrame(HLATrack_t*                          pTLB_Start,
                             HLAIconData_t                        IconData[],
                             const HLACameraData_t*               pCamData,
                             const HLA_t_CameraParameter*         pCameraParameter,
                             const HLATracking3DParametersMeasurement_t*     pTracking3DParamsMeasurement
                             );



#endif
