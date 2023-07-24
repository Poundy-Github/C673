/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_cfg.c

  DESCRIPTION:            HLAF parameter definitions.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_cfg.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:01CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:43CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:32CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.36 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_cfg.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_cfg.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGE:                 Revision 1.35 2013/12/13 16:44:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:49 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2013/04/12 12:45:12CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:13 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.33 2013/04/11 16:20:56CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:56 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.32 2013/03/08 10:29:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:01 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.31 2013/01/18 07:45:58CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:45:58 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.30 2012/10/18 15:50:38CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 revert: - increase deactivate/activate speed from 25/30 km/h to 30/35 km/h
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 3:50:38 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.29 2012/10/18 15:44:43CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - increase deactivate/activate speed from 25/30 km/h to 30/35 km/h
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 3:44:44 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.28 2012/09/20 14:30:20CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - removed unused parameter
  CHANGE:                 - HLAlight parameter optimization for Sprinter (requested from Daimler, Daniel Haebich)
  CHANGE:                 --- Added comments ---  brunnm [Sep 20, 2012 2:30:20 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.27 2012/07/18 07:51:44CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 7:51:44 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.26 2012/04/25 19:19:20CEST Brunn, Marcus (brunnm) 
  CHANGE:                 HLAF:
  CHANGE:                 - reduced TurnOff_minTTB from 2 to 1sec
  CHANGE:                 - fixed maybecity full HB turn off
  CHANGE:                 - turn off partial HB for preceding vehicles in less than 25m
  CHANGE:                 --- Added comments ---  brunnm [Apr 25, 2012 7:19:20 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.25 2012/04/21 15:04:28CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:29 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.24 2012/04/20 19:26:10CEST Kaps, Alexander (kapsa) 
  CHANGE:                 introduced time and distance thresholds for blockage handling
  CHANGE:                 --- Added comments ---  kapsa [Apr 20, 2012 7:26:11 PM CEST]
  CHANGE:                 Change Package : 112707:1 http://mks-psad:7002/im/viewissue?selection=112707
  CHANGE:                 Revision 1.23 2012/03/12 06:00:33CET Brunn, Marcus (brunnm) 
  CHANGE:                 keep off bugfix for potential vehicles
  CHANGE:                 --- Added comments ---  brunnm [Mar 12, 2012 6:00:33 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.22 2012/02/23 16:37:54CET Brunn, Marcus (brunnm) 
  CHANGE:                 added minTurnOnDelayTTBPreceedingWiperOn
  CHANGE:                 --- Added comments ---  brunnm [Feb 23, 2012 4:37:55 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.21 2012/02/13 19:43:16CET Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update:
  CHANGE:                 short turn on delay for preceding cars
  CHANGE:                 Revision 1.20 2012/02/13 18:08:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed history
  CHANGE:                 --- Added comments ---  brunnm [Feb 13, 2012 6:08:08 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.19 2012/02/13 15:25:50CET Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_cfg.h"


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

const HLAFParameter_t hlafParameter =
{
  /* City */ 
  {
    /* minCityDist_m */ 100.0f,
    /* minCityTime_s */ 6.0f,
    /* maxMayBeCityDist_m */ 200.0f,
    /* minMayBeCityDist_m */ 50.0f,
    /* minMayBeCityTime_s */ 1.0f,
    /* minHBonTime_s */ 1.0f
  },
  /* Highway */
  {
    /* minConf */ 0.8f
  },
  /* Speed Partial */
  {
    /* DeactivateSpeed */ 11.1111f,
    /* ActivateSpeed */ 12.5f,
    /* AlwaysActiveSpeed */ 999.99f,
    /* KeepOff_VeryLowSpeed */ 3.5f,
    /* KeepOff_LowRadius */ 150.0f,
    /* KeepOff_HighAcceleration */ 2.5f,
    /* KeepOff_AccTime */ 2.5f,
    /* KeepOff_Delay */ 2.0f,
  },
  /* Blockage */
  {
    /* DistThresh */             500.0f,
    /* TimeThresh */             30.f,
    /* ToggleThresh */           2.0f,
    /* MinDistDrivenThresh */    50.0f,
    /* MinDistBlockedThresh */   50.0f,
    /* MinTimeBlockedThresh */   2.5f,
    /* MinTimeUnblockedThresh */ 120.0f,
  },
  /* Weather */
  {
    /* ~CodeReview ~ID:f0b7d5e32aded95123a925e70b648249 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:unused parameter */
    /* Dummy */ 0.0f
  },
  /* HLA Standard */
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
        /* minRadius2TurnsOn */ 120.0f,
        /* maxSmallRadiusDelay_s */ 0.25f
      },

      /* KeepOffMinTimeHBOff */
      {
        /* minTimeHBOff_s */ 2.0f
        },

        /* KeepOffPotVeh */
        {
          /* Delay_Onc */ 1.0f,
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
   
    /* LightDistance */
    {
      /* minLightDist */ 1,
      /* maxLightDist */ 600,
      /* maxLightDistOncoming */ 150,
      /* parFiltLPOncomingApproach */ 1.0f,
      /* parFiltLPOncomingDepart */ 0.005f,
      /* parFiltLPPreceedApproach */ 0.015f,
      /* parFiltLPPreceedDepart */ 0.01f,
      /* MinLightingDist */ 65.0f,
      /* MaxLightingDist */ 600.0f,
    },

    /* ChangeOverLevel */
    {
      /* Max */ 14,
      /* TurnOnHigh */ 8,
      /* TurnOnLow */ 1,
      /* TurnOffHigh */ 13,
      /* TurnOffMedium */ 10,
      /* TurnOffLow */ 6,
      /* minDist_Onc_TurnOffHigh */ 150.0f,
      /* minDist_Prec_TurnOffMedium */ 150.0f
    }
  },
  /* HLA Light */
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
        /* minRadius2TurnsOn */ 120.0f,
        /* maxSmallRadiusDelay_s */ 0.25f
      },

      /* KeepOffMinTimeHBOff */
      {
        /* minTimeHBOff_s */ 2.0f
      },

      /* KeepOffPotVeh */
      {
        /* Delay_Onc */ 1.0f,
        /* Delay_Prec */ 1.0f,
        /* DelayGlobal */ 1.0f
      },
      /* MayBeCity */ 
      {
        /* Delay_Onc */ 1.0f,
        /* Delay_Prec */ 1.0f,
        /* DelayGlobal */ 1.0f
      } 
    }
  }  
};

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

