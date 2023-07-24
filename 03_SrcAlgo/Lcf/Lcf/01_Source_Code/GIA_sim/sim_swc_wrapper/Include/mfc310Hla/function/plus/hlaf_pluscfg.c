/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_pluscfg.c

  DESCRIPTION:            HLA plus parameter.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_pluscfg.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:27CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:07CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:46CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.18 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_pluscfg.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_pluscfg.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.17 2014/03/19 16:31:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:27 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.16 2013/12/13 16:45:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:07 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2013/04/11 16:20:58CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:58 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.14 2013/01/21 13:39:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra/ lint errors
  CHANGE:                 --- Added comments ---  brunnm [Jan 21, 2013 1:39:08 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.13 2012/09/24 11:28:50CEST Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf plus: introduced road type depending turn on delay (partial HB -> full HB: highway = 5sec, country road = 1sec)
  CHANGE:                 --- Added comments ---  brunnm [Sep 24, 2012 11:28:50 AM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.12 2012/09/20 14:28:02CEST Brunn, Marcus (brunnm) 
  CHANGE:                 removed unused parameter
  CHANGE:                 --- Added comments ---  brunnm [Sep 20, 2012 2:28:02 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.11 2012/07/18 07:51:46CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 7:51:47 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.10 2012/04/24 18:15:23CEST Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update
  CHANGE:                 -> reduced partial blinding of oncoming vehicles
  CHANGE:                 --- Added comments ---  brunnm [Apr 24, 2012 6:15:24 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/04/23 20:19:05CEST Brunn, Marcus (brunnm) 
  CHANGE:                 reduced partial blinding of preceding cars in curvy situations
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 8:19:05 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.8 2012/04/21 15:04:36CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:36 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/02/23 16:42:06CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed some issues for left hand traffic
  CHANGE:                 - increased HB turn on delay when wiper is on stage 6
  CHANGE:                 - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGE:                 - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGE:                 Revision 1.6 2012/02/21 19:18:33CET Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update for motorway
  CHANGE:                 --- Added comments ---  brunnm [Feb 21, 2012 7:18:33 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.5 2012/02/20 16:40:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf optimization in curvy roads
  CHANGE:                 Revision 1.4 2012/02/13 18:04:02CET Brunn, Marcus (brunnm) 
  CHANGE:                 updated activation region parameter set for highway
  CHANGE:                 --- Added comments ---  brunnm [Feb 13, 2012 6:04:02 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.3 2012/02/02 17:48:02CET Brunn, Marcus (brunnm) 
  CHANGE:                 parameter update: deact partial HB after 50m and 2 sec in deact region
  CHANGE:                 Revision 1.2 2012/02/02 06:40:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 changed SpotLightOverlap to 0.5°
  CHANGE:                 --- Added comments ---  brunnm [Feb 2, 2012 6:40:35 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.1 2012/01/31 06:43:25CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_pluscfg.h"


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
const HLAplusParameters_t hlafPlusParameter = 
{
  /* Left */
  {
    /* RegOncom */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {50.0f, 50.0f, 300.0f, 600.0f, 600.0f, 600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {50.0f, 50.0f, 300.0f, 600.0f, 600.0f, 600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f 
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {0.0f, 25.0f, 25.0f, 100.0f, 300.0f, 600.0f},
            /* Ang_rad */
          {0.0f, 0.0f, 0.0f, 0.0f, CML_Deg2Rad(2.5f), CML_Deg2Rad(3.0f)},
          /* CurveLightAngleFactor */ 0.25f,
          /* minTime_s */ -1.0f,
          /* minDist_m */ -1.0f,
          /* minTimeBackInActRegion_s */ -1.0f,
          /* minTTB_s */ 0.0f
        }
    },
    /* RegPreced */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {          50.0f,         50.0f,        300.0f,        600.0f,        600.0f,        600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), CML_Deg2Rad(3.0f), CML_Deg2Rad(4.0f), CML_Deg2Rad(4.0f), CML_Deg2Rad(4.0f), CML_Deg2Rad(4.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {          50.0f,         50.0f,        300.0f,        600.0f,        600.0f,        600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), CML_Deg2Rad(2.0f), CML_Deg2Rad(6.0f), CML_Deg2Rad(4.0f), CML_Deg2Rad(4.0f), CML_Deg2Rad(4.0f)},
        /* CurveLightAngleFactor */  1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {          0.0f,          25.0f,         25.0f,        100.0f,        300.0f,        600.0f},
          /* Ang_rad */
          {CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(3.0f), CML_Deg2Rad(6.0f), CML_Deg2Rad(8.0f), CML_Deg2Rad(6.0f)},
          /* CurveLightAngleFactor */ 1.0f,
          /* minTime_s */ 2.0f,
          /* minDist_m */ 50.0f,
          /* minTimeBackInActRegion_s */ 6.0f,
          /* minTTB_s */ 3.0f
        }
    },
    /* RegOncom_Motorway */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {         100.0f,          100.0f,          300.0f,          600.0f,          600.0f,          600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {         100.0f,          100.0f,          300.0f,          600.0f,          600.0f, 600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {0.0f, 50.0f, 50.0f, 200.0f, 200.0f, 600.0f},
            /* Ang_rad */
          {CML_Deg2Rad(-1.0f), CML_Deg2Rad(-1.0f), CML_Deg2Rad(-1.0f), CML_Deg2Rad(-1.0f), CML_Deg2Rad(-40.0f), CML_Deg2Rad(-40.0f)},
          /* CurveLightAngleFactor */ 0.25f,
          /* minTime_s */ -1.0f,
          /* minDist_m */ -1.0f,
          /* minTimeBackInActRegion_s */ -1.0f,
          /* minTTB_s */ 0.0f
        }
    },
    /* RegPreced_Motorway */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {100.0f, 100.0f, 300.0f, 600.0f, 600.0f, 600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {100.0f, 100.0f, 300.0f, 600.0f, 600.0f, 600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(-40.0f), 0.0f, CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {0.0f, 50.0f, 50.0f, 100.0f, 300.0f, 600.0f},
            /* Ang_rad */
          {CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f), CML_Deg2Rad(1.5f), CML_Deg2Rad(1.5f)},
          /* CurveLightAngleFactor */ 1.0f,
          /* minTime_s */ 1.0f,
          /* minDist_m */ 25.0f,
          /* minTimeBackInActRegion_s */ 6.0f,
          /* minTTB_s */ 3.0f
        }
    },

      /* MinTimeLowNoOncoming_s */ 2.0f, 
      /* MinTimeLow2PartHB_s */ 2.0f,
      /* MinTimeLow2FullHB_s */ 2.0f,
      /* MinTimePart2FullHB_s */ 1.0f,

      /* TTD_Threshold */ 3.0f,
      /* TTD_MaxTurnOnDelay*/ 0.5f,

      /* PredictionTime_Oncom_s */ 0.5f,
      /* PredictionTime_Preced_s */ 0.3f,

      /* HBCharacteristic */
    {
      /* FullHBWidth_left */ CML_Deg2Rad(40.0f),
        /* FullHBWidth_right */ CML_Deg2Rad(40.0f),  

        /* PartHBWidth_left */ CML_Deg2Rad(40.0f),
        /* PartHBWidth_right */ CML_Deg2Rad(40.0f),

        /* SpotLightWidth_left */ 0.0f,
        /* SpotLightWidth_right */ CML_Deg2Rad(40.0f),

        /* SpotLightOverlap */ CML_Deg2Rad(0.5f)
    },

    /* HBAng_Onc */
    {
      /* Filter_Inner */
      {
        /* Alpha */ 0.2f,
          /* dAng_min_perCycle */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.1f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.25f)},
        /* Cycles[2] */
        {8, 17}
      },
        /* Filter_Inner_Fast */
      {
        /* Alpha */ 0.0f,
          /* dAng_min_perCycle */
        {0.0f, 0.0f},
        /* dAng_max_perCycle[2] */
        {0.0f, 0.0f},
        /* Cycles[2] */
        {0, 0}
      },
        /* Filter_Outer */
      {
        /* Alpha */ 0.5f,
          /* dAng_min_perCycle */
        {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.05f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(1.0f)},
        /* Cycles[2] */
        {5, 8}
      },
        /* Filter_OuterMax */
      {
        /* Alpha */ 1.0f,
          /* dAng_min_perCycle */
        {CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
        /* Cycles[2] */
        {0, 0}
      },
        /* Filter_NoVeh */
      {
        /* Alpha */ 0.2f,
          /* dAng_min_perCycle */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.3f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.5f)},
        /* Cycles[2] */
        {10, 17}
      },

        /* HBAng_Tol_Inner */ 0.0f,
        /* HBAng_Tol_Outer */ 0.0f,

        /* HBAng_Tol_Target */ CML_Deg2Rad(0.1f),

        /* LockCnt */ 3,

        /* NoVeh_KeepHBAng_Cnt */ 5,

        /* FastFilterCycleCnt */ UI16_T_MAX,

        /* SafetyMargin */
      {
        /* InitialSafety */ 0.0f,
        /* InitialSafetyCnt_0 */ 0,
        /* InitialSafetyCnt_1 */ 0,

        /* minSafety[2] */ 
        {CML_Deg2Rad(1.0f),CML_Deg2Rad(0.5f)},
        /* minSafety_CaliOdo_m[2] */
        {0,            5000},
        /* maxSafety */ CML_Deg2Rad( 4.0f),

        /* Yaw_Safety_Min */
        {CML_Deg2Rad( 1.0f), CML_Deg2Rad( 1.0f), CML_Deg2Rad( 4.0f)},
        /* Yaw_Safety_Max */
        {CML_Deg2Rad( 2.0f), CML_Deg2Rad( 2.0f), CML_Deg2Rad( 6.0f)},
        /* Yaw */
        {CML_Deg2Rad(-18.0f), 0.0f, CML_Deg2Rad( 18.0f)},

        /* Dist_SafteyWidth */ 0.0f,
        /* Dist_Min */ 0.0f,
        /* Dist_Max */ 0.0f,
        /* Dist_MinTime */ 0.0f
      },

      /* MinMax */
      {
        /* min */ CML_Deg2Rad(-7.5f),
          /* max */ CML_Deg2Rad(15.0f),
          /* CurveTol */ CML_Deg2Rad(4.0f),

          /* Filter_Alpha */ 0.2f,
          /* Filter_Tol_Start */ CML_Deg2Rad(0.6f),
          /* Filter_Tol_Stop */ CML_Deg2Rad(0.3f)
        }
      },
      /* HBAng_Prec */
      {
        /* Filter_Inner */
        {
          /* Alpha */ 0.2f,
            /* dAng_min_perCycle */
          {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.05f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.25f)},
          /* Cycles[2] */
          {16, 33}
        },
          /* Filter_Inner_Fast */
        {
          /* Alpha */ 0.5f,
            /* dAng_min_perCycle */
          {0.0f, CML_Deg2Rad(0.05f)},
          /* dAng_max_perCycle[2] */
          {0.0f, CML_Deg2Rad(0.5f)},
          /* Cycles[2] */
          {5, 16}
        },
          /* Filter_Outer */
        {
          /* Alpha */ 0.5f,
            /* dAng_min_perCycle */
          {CML_Deg2Rad(0.05f),  CML_Deg2Rad(0.05f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.5f)},
          /* Cycles[2] */
          {8, 33}
        },
          /* Filter_OuterMax */
        {
          /* Alpha */ 1.0f,
            /* dAng_min_perCycle */
          {CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
          /* Cycles[2] */
          {0, 0}
        },
          /* Filter_NoVeh */
        {
          /* Alpha */ 0.2f,
            /* dAng_min_perCycle */
          {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.3f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.5f)},
          /* Cycles[2] */
          {10, 17}
        },

          /* HBAng_Tol_Inner */ -CML_Deg2Rad(0.3f),
          /* HBAng_Tol_Outer */ CML_Deg2Rad(0.1f),

          /* HBAng_Tol_Target */ CML_Deg2Rad(0.1f),

          /* LockCnt */ 3,

          /* NoVeh_KeepHBAng_Cnt */ 17,

          /* FastFilterCycleCnt */ 83,

          /* SafetyMargin */
        {
          /* InitialSafety */ CML_Deg2Rad(0.5f),
          /* InitialSafetyCnt_0 */ 50,
          /* InitialSafetyCnt_1 */ 50,

          /* minSafety[2] */ 
          {CML_Deg2Rad(0.75f),CML_Deg2Rad(0.25f)},
          /* minSafety_CaliOdo_m[2] */
          {0,            5000},
          /* maxSafety */ CML_Deg2Rad( 4.0f),

            /* Yaw_Safety_Min */
          {CML_Deg2Rad( 1.0f), 0.0f, CML_Deg2Rad( 4.0f)},
          /* Yaw_Safety_Max */
          {CML_Deg2Rad( 3.0f), CML_Deg2Rad( 2.0f), CML_Deg2Rad( 6.0f)},
          /* Yaw */
          {CML_Deg2Rad(-18.0f), 0.0f, CML_Deg2Rad( 18.0f)},

          /* Dist_SafteyWidth */ 0.75f,
          /* Dist_Min */ 30.0f,
          /* Dist_Max */ 200.0f,
          /* Dist_MinTime */ 2.0f 
        },

        /* MinMax */
        {
          /* min */ CML_Deg2Rad(-7.5f),
            /* max */ CML_Deg2Rad(15.0f),
            /* CurveTol */ CML_Deg2Rad(4.0f),

            /* Filter_Alpha */ 0.2f,
            /* Filter_Tol_Start */ CML_Deg2Rad(0.6f),
            /* Filter_Tol_Stop */ CML_Deg2Rad(0.3f)
          }
      },

      /* TurnOff */
      {
        /* A2L */
        {
          /* Ang2TurnOff */ CML_Deg2Rad(10.0f)
        },
        /* dA2L */
        {
          /* dAng2TurnOff */ CML_Deg2Rad(3.0f),
          /* MinTimeOff_s */ 1.0f
        }
      }
  },
  /* Right */
  {
    /* RegOncom */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {0.0f, 50.0f,          50.0f,         300.0f,         600.0f,         600.0f},
          /* Ang_rad */
        {0.0f,  0.0f, CML_Deg2Rad(-2.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */  0.5f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {0.0f,          50.0f,        300.0f,         600.0f,         600.0f,         600.0f},
          /* Ang_rad */
        {0.0f, CML_Deg2Rad(-2.0f),CML_Deg2Rad(-6.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f 
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {0.0f,           0.0f,         300.0f,         600.0f,         600.0f,         600.0f},
            /* Ang_rad */
          {0.0f, CML_Deg2Rad(-4.0f), CML_Deg2Rad(-8.0f), CML_Deg2Rad(-5.0f), CML_Deg2Rad(-5.0f), CML_Deg2Rad(-5.0f)},
          /* CurveLightAngleFactor */ 1.0f,
          /* minTime_s */ -1.0f,
          /* minDist_m */ -1.0f,
          /* minTimeBackInActRegion_s */ -1.0f,
          /* minTTB_s */ 0.0f
        }
    },
    /* RegPreced */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {         50.0f,          50.0f,         300.0f,         600.0f,         600.0f,         600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(40.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */  0.5f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {         50.0f,          50.0f,         300.0f,         600.0f,         600.0f,         600.0f},
          /* Ang_rad */
        {CML_Deg2Rad(40.0f), CML_Deg2Rad(-2.0f), CML_Deg2Rad(-6.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f), CML_Deg2Rad(-4.0f)},
        /* CurveLightAngleFactor */  1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {         0.0f,         25.0f,          25.0f,         100.0f,         300.0f,         600.0f},
            /* Ang_rad */
          {CML_Deg2Rad(3.0f), CML_Deg2Rad(3.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-6.0f), CML_Deg2Rad(-8.0f), CML_Deg2Rad(-6.0f)},
          /* CurveLightAngleFactor */ 1.0f,
          /* minTime_s */ 2.0f,
          /* minDist_m */ 50.0f,
          /* minTimeBackInActRegion_s */ 6.0f,
          /* minTTB_s */ 3.0f
        }
    },
    /* RegOncom_Motorway */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {0.0f, 100.0f,         100.0f,         300.0f,         600.0f,         600.0f},
        /* Ang_rad */
        {0.0f,   0.0f, CML_Deg2Rad(-2.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {0.0f,         100.0f,         300.0f,         600.0f,         600.0f,         600.0f},
          /* Ang_rad */
        {0.0f, CML_Deg2Rad(-2.0f), CML_Deg2Rad(-6.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f), CML_Deg2Rad(-3.0f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {0.0f,           0.0f,         300.0f,         600.0f,         600.0f,         600.0f},
            /* Ang_rad */
          {0.0f, CML_Deg2Rad(-4.0f), CML_Deg2Rad(-8.0f), CML_Deg2Rad(-5.0f), CML_Deg2Rad(-5.0f), CML_Deg2Rad(-5.0f)},
          /* CurveLightAngleFactor */ 1.0f,
          /* minTime_s */ -1.0f,
          /* minDist_m */ -1.0f,
          /* minTimeBackInActRegion_s */ -1.0f,
          /* minTTB_s */ 0.0f
        }
    },
    /* RegPreced_Motorway */
    {
      /* ActRegion_LowBeam */
      {
        /* Dist_m */
        {        100.0f,         100.0f,         300.0f,         600.0f,         600.0f,         600.0f},
        /* Ang_rad */
        {CML_Deg2Rad(40.0f), CML_Deg2Rad(-1.5f), CML_Deg2Rad(-2.5f), CML_Deg2Rad(-2.5f), CML_Deg2Rad(-2.5f), CML_Deg2Rad(-2.5f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
      },
      /* ActRegion_HighBeam */
      {
        /* Dist_m */
        {        100.0f,         100.0f,         300.0f,         600.0f,         600.0f,         600.0f},
        /* Ang_rad */
        {CML_Deg2Rad(40.0f), CML_Deg2Rad(-1.5f), CML_Deg2Rad(-2.5f), CML_Deg2Rad(-2.5f), CML_Deg2Rad(-2.5f), CML_Deg2Rad(-2.5f)},
        /* CurveLightAngleFactor */ 1.0f,
        /* minTime_s */ -1.0f,
        /* minDist_m */ -1.0f,
        /* minTimeBackInActRegion_s */ -1.0f,
        /* minTTB_s */ 0.0f
        },
        /* DeactRegion */
        {
          /* Dist_m */
          {         0.0f,         50.0f,          50.0f,         100.0f,         300.0f,         600.0f},
          /* Ang_rad */
          {CML_Deg2Rad(2.5f), CML_Deg2Rad(2.5f), CML_Deg2Rad(-1.5f), CML_Deg2Rad(-3.5f), CML_Deg2Rad(-8.0f), CML_Deg2Rad(-5.0f)},
          /* CurveLightAngleFactor */ 1.0f,
          /* minTime_s */ 1.0f,
          /* minDist_m */ 25.0f,
          /* minTimeBackInActRegion_s */ 6.0f,
          /* minTTB_s */ 3.0f
        }
    },

      /* MinTimeLowNoOncoming_s */ 0.0f, 
      /* MinTimeLow2PartHB_s */ 2.0f,
      /* MinTimeLow2FullHB_s */ 2.0f,
      /* MinTimePart2FullHB_s */ 1.0f,

      /* TTD_Threshold */ 8.0f,
      /* TTD_MaxTurnOnDelay*/ 1.0f,

      /* PredictionTime_Oncom_s */ 0.18f,
      /* PredictionTime_Preced_s */ 0.3f,

      /* HBCharacteristic */
    {
      /* FullHBWidth_left */ 0.0f,
      /* FullHBWidth_right */ CML_Deg2Rad(40.0f),  

      /* PartHBWidth_left */ CML_Deg2Rad(40.0f),
      /* PartHBWidth_right */ CML_Deg2Rad(40.0f),

      /* SpotLightWidth_left */ CML_Deg2Rad(40.0f),
      /* SpotLightWidth_right */ CML_Deg2Rad(40.0f),

      /* SpotLightOverlap */ 0.0f
    },

    /* HBAng_Onc */
    {
      /* Filter_Inner */
      {
        /* Alpha */ 0.2f,
        /* dAng_min_perCycle */
        {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.05f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.25f)},
        /* Cycles[2] */
        {16, 33}
      },
      /* Filter_Inner_Fast */
      {
        /* Alpha */ 0.5f,
        /* dAng_min_perCycle */
        {0.0f, CML_Deg2Rad(0.05f)},
        /* dAng_max_perCycle[2] */
        {0.0f, CML_Deg2Rad(0.5f)},
        /* Cycles[2] */
        {5, 16}
      },
      /* Filter_Outer */
      {
        /* Alpha */ 0.3f,
        /* dAng_min_perCycle */
        {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.1f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.5f)},
        /* Cycles[2] */
        {1, 8}
      },
      /* Filter_OuterMax */
      {
        /* Alpha */ 0.5f,
        /* dAng_min_perCycle */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.1f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(1.0f)},
        /* Cycles[2] */
        {3, 8}
      },
      /* Filter_NoVeh */
      {
        /* Alpha */ 0.2f,
        /* dAng_min_perCycle */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.3f)},
        /* dAng_max_perCycle[2] */
        {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.5f)},
        /* Cycles[2] */
        {10, 17}
      },

      /* HBAng_Tol_Inner */ CML_Deg2Rad(0.3f),
      /* HBAng_Tol_Outer */ -CML_Deg2Rad(0.1f),

      /* HBAng_Tol_Target */ CML_Deg2Rad(0.1f),

      /* LockCnt */ 3,

      /* NoVeh_KeepHBAng_Cnt */ 5,

      /* FastFilterCycleCnt */ 83,

      /* SafetyMargin */
      {
        /* InitialSafety */ 0.0f,
        /* InitialSafetyCnt_0 */ 0,
        /* InitialSafetyCnt_1 */ 0,

        /* minSafety[2] */ 
        {CML_Deg2Rad(1.0f),CML_Deg2Rad(0.5f)},
        /* minSafety_CaliOdo_m[2] */
        {0,            5000},
        /* maxSafety */ CML_Deg2Rad( 4.0f),

          /* Yaw_Safety_Min */
        {CML_Deg2Rad( 0.5f), CML_Deg2Rad( 0.5f), CML_Deg2Rad( 4.0f)},
        /* Yaw_Safety_Max */
        {CML_Deg2Rad( 0.5f), CML_Deg2Rad( 0.5f), CML_Deg2Rad( 4.0f)},
        /* Yaw */
        {CML_Deg2Rad(-18.0f), 0.0f, CML_Deg2Rad( 18.0f)},

        /* Dist_SafteyWidth */ 0.0f,
        /* Dist_Min */ 0.0f,
        /* Dist_Max */ 0.0f,
        /* Dist_MinTime */ 0.0f
      },

      /* MinMax */
      {
        /* min */ CML_Deg2Rad(-15.0f),
          /* max */ CML_Deg2Rad(7.5f),
          /* CurveTol */ CML_Deg2Rad(4.0f),

          /* Filter_Alpha */ 0.2f,
          /* Filter_Tol_Start */ CML_Deg2Rad(0.6f),
          /* Filter_Tol_Stop */ CML_Deg2Rad(0.3f)
        }
      },
      /* HBAng_Prec */
      {
        /* Filter_Inner */
        {
          /* Alpha */ 0.2f,
          /* dAng_min_perCycle */
          {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.05f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.25f)},
          /* Cycles[2] */
          {16, 33}
        },
        /* Filter_Inner_Fast */
        {
          /* Alpha */ 0.5f,
          /* dAng_min_perCycle */
          {0.0f, CML_Deg2Rad(0.05f)},
          /* dAng_max_perCycle[2] */
          {0.0f, CML_Deg2Rad(0.5f)},
          /* Cycles[2] */
          {5, 16}
        },
        /* Filter_Outer */
        {
          /* Alpha */ 0.5f,
          /* dAng_min_perCycle */
          {CML_Deg2Rad(0.05f),  CML_Deg2Rad(0.05f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(0.05f), CML_Deg2Rad(0.5f)},
          /* Cycles[2] */
          {8, 33}
        },
        /* Filter_OuterMax */
        {
          /* Alpha */ 1.0f,
          /* dAng_min_perCycle */
          {CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(1.0f), CML_Deg2Rad(1.0f)},
          /* Cycles[2] */
          {0, 0}
        },
          /* Filter_NoVeh */
        {
          /* Alpha */ 0.2f,
            /* dAng_min_perCycle */
          {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.3f)},
          /* dAng_max_perCycle[2] */
          {CML_Deg2Rad(0.1f), CML_Deg2Rad(0.5f)},
          /* Cycles[2] */
          {10, 17}
        },

          /* HBAng_Tol_Inner */ CML_Deg2Rad(0.3f),
          /* HBAng_Tol_Outer */ -CML_Deg2Rad(0.1f),

          /* HBAng_Tol_Target */ CML_Deg2Rad(0.1f),

          /* LockCnt */ 3,

          /* NoVeh_KeepHBAng_Cnt */ 17,

          /* FastFilterCycleCnt */ 83,

          /* SafetyMargin */
        {
          /* InitialSafety */ CML_Deg2Rad(0.5f),
          /* InitialSafetyCnt_0 */ 50,
          /* InitialSafetyCnt_1 */ 50,

          /* minSafety[2] */ 
          {CML_Deg2Rad(0.75f),CML_Deg2Rad(0.25f)},
          /* minSafety_CaliOdo_m[2] */
          {0,            5000},
          /* maxSafety */ CML_Deg2Rad( 4.0f),

          /* Yaw_Safety_Min */
          {CML_Deg2Rad( 4.0f), 0.0f, CML_Deg2Rad( 1.0f)},
          /* Yaw_Safety_Max */
          {CML_Deg2Rad( 6.0f), CML_Deg2Rad( 2.0f), CML_Deg2Rad( 3.0f)},
          /* Yaw */
          {CML_Deg2Rad(-18.0f), 0.0f, CML_Deg2Rad( 18.0f)},

          /* Dist_SafteyWidth */ 0.75f,
          /* Dist_Min */ 30.0f,
          /* Dist_Max */ 200.0f,
          /* Dist_MinTime */ 2.0f 
        },

        /* MinMax */
        {
          /* min */ CML_Deg2Rad(-15.0f),
            /* max */ CML_Deg2Rad(7.5f),
            /* CurveTol */ CML_Deg2Rad(4.0f),

            /* Filter_Alpha */ 0.2f,
            /* Filter_Tol_Start */ CML_Deg2Rad(0.6f),
            /* Filter_Tol_Stop */ CML_Deg2Rad(0.3f)
          }
      },

        /* TurnOff */
      {
        /* A2L */
        {
          /* Ang2TurnOff */ CML_Deg2Rad(-10.0f)
        },
        /* dA2L */
        {
          /* dAng2TurnOff */ CML_Deg2Rad(5.0f),
          /* MinTimeOff_s */ 1.0f
        }
      }
  },

  /* TurnOnDelay */
  {
    /* Std */
    {
      /* initialTurnOnDelay */ 1.5f,
    },
    /* PartHBwithoutVeh_Country_s */ 1.0f,
    /* PartHBwithoutVeh_Highway_s */ 5.0f,
  },

  /* KeepOff_MaxGap */ CML_Deg2Rad(5.0f),
  /* KeepOff_MinTimeToDeact */ 5.0f,

  /* ChangeOverLevel_7_TTB */  500, /* [ms] */
  /* ChangeOverLevel_6_TTB */ 1000, /* [ms] */
  /* ChangeOverLevel_5_TTB */ 2000, /* [ms] */
  /* ChangeOverLevel_4_TTB */ 3000, /* [ms] */
};

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
