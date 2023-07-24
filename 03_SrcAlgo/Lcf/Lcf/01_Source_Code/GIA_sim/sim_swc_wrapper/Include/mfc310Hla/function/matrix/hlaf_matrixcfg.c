/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrixcfg.c

  DESCRIPTION:            HLA matrix beam parameter.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-11-05

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_matrixcfg.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:21CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:00CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:41CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.8 2014/03/25 18:38:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_matrixcfg.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_matrixcfg.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/matrix/project.pj.
  CHANGE:                 Revision 1.7 2014/03/19 16:30:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:44 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.6 2013/12/13 16:45:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:02 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.5 2013/04/12 12:45:24CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:24 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.4 2013/04/11 16:21:10CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:21:10 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.3 2013/03/11 10:37:46CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
  CHANGE:                 --- Added comments ---  brunnm [Mar 11, 2013 10:37:47 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.2 2013/01/17 06:39:26CET Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update from Thanos (BMW for I210)
  CHANGE:                 --- Added comments ---  brunnm [Jan 17, 2013 6:39:26 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.1 2012/12/03 13:02:04CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_matrixcfg.h"


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
const HLAFMatrixParameter_t hlafMatrixParameter = 
{
  /* TurnOnDelay */
  {
    /* initialTurnOnDelay */ 1.5f,
  },

  /* KeepOff */
  {
    /* maxDist2Cover */ 80.0f,
    /* KeepOffSmallRadius */
    {
      /* minRadius2TurnsOn */ 0.0f,
      /* maxSmallRadiusDelay_s */ 0.0f
    },

    /* KeepOffMinTimeHBOff */
    {
      /* minTimeHBOff_s */ 2.0f
    },

    /* KeepOffPotVeh */
    {
      /* Delay_Onc */ 0.4f,
      /* Delay_Prec */ 1.0f,
      /* DelayGlobal */ 1.0f
    },
    /* MayBeCity */ 
    {
      /* Delay_Onc */ 1.0f,
      /* Delay_Prec */ 1.0f,
      /* DelayGlobal */ 1.0f
    } 
  },
  /* GFA */
  {
    /* KeepGFAMinTime_s */ 1.0f
  },
  /* ClusterVeh2GFA */
  {
    /* dAngPrec [rad] */ CML_Deg2Rad(3.0f),
    /* dAngOnc [rad] */ CML_Deg2Rad(3.0f), 
    /* dAng [rad] */ CML_Deg2Rad(1.0f),
    /* WidthPrec [m] */ 3.0f,
    /* WidthOnc [m] */ 3.0f,
    /* Width [m] */ 1.0f
  },
  /* Output */
  {
    /* BndryLeft_Ang_Default */ 0.0f,
    /* BndryLeft_Ang_Min */ CML_Deg2Rad(-20.0f),//DEG2RAD(-10.4f),
    /* BndryLeft_Ang_Max */ CML_Deg2Rad(20.0f),//DEG2RAD(15.0f),

    /* BndryRight_Ang_Default */ 0.0f,
    /* BndryRight_Ang_Min */ CML_Deg2Rad(-20.0f),//DEG2RAD(-15.0f),
    /* BndryRight_Ang_Max */ CML_Deg2Rad(20.0f),//DEG2RAD(10.4f),

    /* BndryLower_Ang_Default */ 0.0f,
    /* BndryLower_Ang_Min */ CML_Deg2Rad(-5.0f),
    /* BndryLower_Ang_Max */ CML_Deg2Rad(5.0f),

    /* ClosestObj_Dist_Default */ 0.0f,
    /* ClosestObj_Dist_Min */ 0.0f,
    /* ClosestObj_Dist_Max */ 150.0f,

    /* ClosestObj_Ang_Default */ 0.0f,
    /* ClosestObj_Ang_Min */ CML_Deg2Rad(-20.0f),
    /* ClosestObj_Ang_Max */ CML_Deg2Rad(20.0f),

    /* MinLight_Dist_Default */ 0.0f,
    /* MinLight_Dist_Min */ 0.0f,
    /* MinLight_Dist_Max */ 150.0f,

    /* MinLight_Ang_Default */ 0.0f,
    /* MinLight_Ang_Min */ CML_Deg2Rad(-20.0f),
    /* MinLight_Ang_Max */ CML_Deg2Rad(20.0f),

    /* LowBeam_Dist_Default */ 65.0f,
    /* LowBeam_Dist_Min */ 0.0f,
    /* LowBeam_Dist_Max */ 600.0f,
    /* LowBeam_Dist_Onc_Min */ 0.0f,
    /* LowBeam_Dist_Onc_Max */ 150.0f,
    /* LowBeam_Dist_Prec_Min */ 0.0f,
    /* LowBeam_Dist_Prec_Max */ 600.0f,

    /* LowBeam_Ang_Default */ 0.0f,
    /* LowBeam_Ang_Onc_Min */ CML_Deg2Rad(-20.0f),
    /* LowBeam_Ang_Onc_Max */ CML_Deg2Rad(20.0f)
  }
};

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
