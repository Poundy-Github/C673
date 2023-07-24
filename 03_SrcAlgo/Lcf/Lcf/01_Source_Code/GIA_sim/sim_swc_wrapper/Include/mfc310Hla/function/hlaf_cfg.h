/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_cfg.h

  DESCRIPTION:            HLAF parameter definitions.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_cfg.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:02CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:44CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:32CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.27 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_cfg.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_cfg.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGES:                Revision 1.26 2013/04/12 12:45:10CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Took more coding parameters into use
  CHANGES:                --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:10 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.25 2013/04/11 16:20:54CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Implemented some coding parameters
  CHANGES:                Tunnel is now global turn off reason
  CHANGES:                --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:54 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.24 2013/03/08 10:29:54CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:29:54 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.23 2013/01/18 07:45:58CET Brunn, Marcus (brunnm) 
  CHANGES:                initial matrix beam version for BMW I210
  CHANGES:                --- Added comments ---  brunnm [Jan 18, 2013 7:45:59 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.22 2012/09/20 14:34:10CEST Brunn, Marcus (brunnm) 
  CHANGES:                removed unused parameter (turn on delay)
  CHANGES:                --- Added comments ---  brunnm [Sep 20, 2012 2:34:10 PM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.21 2012/07/18 07:51:44CEST Brunn, Marcus (brunnm) 
  CHANGES:                - added code review tags
  CHANGES:                --- Added comments ---  brunnm [Jul 18, 2012 7:51:44 AM CEST]
  CHANGES:                Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGES:                Revision 1.20 2012/04/21 15:04:29CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced first hla light version
  CHANGES:                --- Added comments ---  brunnm [Apr 21, 2012 3:04:30 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.19 2012/04/20 19:27:18CEST Kaps, Alexander (kapsa) 
  CHANGES:                introduced time and distance thresholds for blockage handling
  CHANGES:                --- Added comments ---  kapsa [Apr 20, 2012 7:27:18 PM CEST]
  CHANGES:                Change Package : 112707:1 http://mks-psad:7002/im/viewissue?selection=112707
  CHANGES:                Revision 1.18 2012/03/12 06:00:33CET Brunn, Marcus (brunnm) 
  CHANGES:                keep off bugfix for potential vehicles
  CHANGES:                --- Added comments ---  brunnm [Mar 12, 2012 6:00:33 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.17 2012/02/23 16:38:15CET Brunn, Marcus (brunnm) 
  CHANGES:                added minTurnOnDelayTTBPreceedingWiperOn
  CHANGES:                Revision 1.16 2012/02/09 17:37:36CET Kaps, Alexander (kapsa) 
  CHANGES:                Min distance driven of 50 m introduced which is required for leaving clearance measurement to any state which enables HLA function
  CHANGES:                --- Added comments ---  kapsa [Feb 9, 2012 5:37:37 PM CET]
  CHANGES:                Change Package : 97587:1 http://mks-psad:7002/im/viewissue?selection=97587
  CHANGES:                Revision 1.15 2012/02/06 15:27:39CET Brunn, Marcus (brunnm) 
  CHANGES:                turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGES:                --- Added comments ---  brunnm [Feb 6, 2012 3:27:39 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.14 2012/01/25 21:37:23CET Brunn, Marcus (brunnm) 
  CHANGES:                moved some hlaf standard parameter in extra structure (turn on delay based on TTB)
  CHANGES:                --- Added comments ---  brunnm [Jan 25, 2012 9:37:23 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.13 2012/01/24 06:54:05CET Brunn, Marcus (brunnm) 
  CHANGES:                reduced blind flight time after oncoming vehicle passed
  CHANGES:                Revision 1.12 2011/11/29 09:20:07CET Brunn, Marcus (brunnm) 
  CHANGES:                reworked of HLA Standard
  CHANGES:                --- Added comments ---  brunnm [Nov 29, 2011 9:20:07 AM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.11 2011/11/17 19:07:38CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                city parameter update
  CHANGES:                --- Added comments ---  brunnm [Nov 17, 2011 7:07:38 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.10 2011/11/15 18:03:40CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                added parameter for maybe city
  CHANGES:                --- Added comments ---  brunnm [Nov 15, 2011 6:03:40 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.9 2011/11/14 15:27:31CET Kaps Alexander (kapsa) (kapsa) 
  CHANGES:                implemented blockage parameters
  CHANGES:                --- Added comments ---  kapsa [Nov 14, 2011 3:27:31 PM CET]
  CHANGES:                Change Package : 87858:2 http://mks-psad:7002/im/viewissue?selection=87858
  CHANGES:                Revision 1.8 2011/11/11 14:57:17CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                added hlaf measfreezes
  CHANGES:                --- Added comments ---  brunnm [Nov 11, 2011 2:57:17 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.7 2011/09/27 13:39:54CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                separation of HLAR/ HLAF
  CHANGES:                --- Added comments ---  brunnm [Sep 27, 2011 1:39:54 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.6 2011/07/18 18:02:45CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - hlaf speed decision considers acceleration
  CHANGES:                - hlaf plus contains an additional min speed based on the hla decision speed but activation speed is set to 40 and 45 km/h
  CHANGES:                --- Added comments ---  uidt9253 [Jul 18, 2011 6:02:45 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.5 2011/07/14 22:34:24CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - new HLAF activation / deactivation speed controlling (much lower activation speeds and time penalties for certain events)
  CHANGES:                - use displayed speed
  CHANGES:                --- Added comments ---  uidt9253 [Jul 14, 2011 10:34:24 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.4 2011/05/17 13:10:04CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                dusk/ dawn bugfix
  CHANGES:                --- Added comments ---  brunnm [May 17, 2011 1:10:04 PM CEST]
  CHANGES:                Change Package : 66902:1 http://mks-psad:7002/im/viewissue?selection=66902
  CHANGES:                Revision 1.3 2011/03/08 16:40:33CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                rework of hlaf (standard hla)
  CHANGES:                Revision 1.2 2011/03/01 21:46:10CET Marcus Brunn (brunnm) 
  CHANGES:                hlaf highway: toggle bugfix
  CHANGES:                Revision 1.1 2011/02/24 15:04:30CET Marcus Brunn (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_CFG_INCLUDED
#define HLAF_CFG_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*! turn on delay parameter set based on TTB of the vehicle */
typedef struct
{
  float32 initialTurnOnDelay;                     /*!< initial turn on delay in seconds after HLA activation. */
} HLAFParameterTurnOnDelay_t;

/*!< city detection parameter */
typedef struct 
{
  float32 minCityDist_m; /* stay in city state for min. distance */
  float32 minCityTime_s; /* stay in city state for min time      */
  float32 maxMayBeCityDist_m; /* stay only for maximal distance in MayBeCity */
  float32 minMayBeCityDist_m; /* stay minimal distance in MayBeCity */
  float32 minMayBeCityTime_s; /* stay minimal time in MayBeCity */
  float32 minHBonTime_s; /* stay in partial/ full HB on for min time */
}HLAFParameterCity_t;


/*!< highway detection parameter */
typedef struct 
{
  float32 minConf; /* min confidence for transition: idle/country road -> highway */
}HLAFParameterHighway_t;


/*!< blockage detection parameter */
typedef struct 
{
  float32 DistThresh;
  float32 TimeThresh;
  float32 ToggleThresh;
  float32 MinDistDrivenThresh;
  float32 MinDistBlockedThresh;
  float32 MinTimeBlockedThresh;
  float32 MinTimeUnblockedThresh;
  
}HLAFParameterBlockage_t;


/*!< weather detection parameter */
typedef struct 
{
  float32 Dummy;
}HLAFParameterWeather_t;

/*!< change over level parameter */
typedef struct 
{
  uint8 Max;            /*!< the maximal changeover level. */
  uint8 TurnOnHigh;     /*!< the high increase speed for the changeover level. */
  uint8 TurnOnLow;      /*!< the low increase speed for the changeover level. */
  uint8 TurnOffHigh;    /*!< the high decrease speed for the changeover level. */
  uint8 TurnOffMedium;  /*!< the medium decrease speed for the changeover level. */
  uint8 TurnOffLow;     /*!< the low decrease speed for the changeover level. */

  float32 minDist_Onc_TurnOffHigh;    /*!< dist(oncoming)  < minDist_Onc_TurnOffHigh    -> changeOverLevel = TurnOffHigh   */
                                      /*!<                                         else -> changeOverLevel = TurnOffMedium */
  float32 minDist_Prec_TurnOffMedium; /*!< dist(preceding) < minDist_Prec_TurnOffMedium -> changeOverLevel = TurnOffMedium */
                                      /*!<                                         else -> changeOverLevel = TurnOffLow    */
}HLAFParStdChangeOverLevel_t;


/*!< keep HB off for minimal time */
typedef struct 
{
  float32 minTimeHBOff_s;
}HLAFParStdKeepOffMinTimeHBOff_t;

/*!< keep HB off in curves with small radius */
typedef struct 
{
  float32 minRadius2TurnsOn;
  float32 maxSmallRadiusDelay_s;
}HLAFParStdKeepOffSmallRadius_t;

/*!< keep HB off when potential vehcile is detected */
typedef struct 
{
  float32 Delay_Onc;
  float32 Delay_Prec;
  float32 Delay_Glob;
}HLAFParStdKeepOffPotVeh_t;

/* conditions for turning off HB */
typedef struct 
{
  float32 Delay_Onc;    /*!< maximal turn on delay after oncoming passed (matrix or plus: probably partial HB on) */  
  float32 Delay_Prec;   /*!< maximal turn on delay after preceding vehcile gets lost (matrix or plus: probably partial HB on) */
  float32 Delay_Global; /*!< maximal turn on delay after global turn off reason (full HB off) */
}HLAFParStdKeepOffMayBeCity;

/* conditions for keeping HB off */
typedef struct 
{
  float32                         maxDist2Cover;       /*!< maximum distance to keep highbeams off when precceding car is lost. */
  HLAFParStdKeepOffSmallRadius_t  KeepOffSmallRadius;  /*!< parameter for keep off HB in curves with small radius */
  HLAFParStdKeepOffMinTimeHBOff_t KeepOffMinTimeHBOff; /*!< parameter for keep off HB for a minimal time */
  HLAFParStdKeepOffPotVeh_t       KeepOffPotVeh;       /*!< parameter for keep off HB when potential vehicle is detected */
  HLAFParStdKeepOffMayBeCity      MayBeCity;           /*!< parameter for keep off HB when may be city is detected */
}HLAFParameterKeepOff_t;

typedef struct 
{
  float32                         minLightDist;                           /*!< the minimal lighting distance. */
  float32                         maxLightDist;                           /*!< the maximal lighting distance. */
  uint16                          maxLightDistOncoming;                   /*!< the maximal lighting distance at oncoming traffic. */
  float32                         parFiltLPOncomingApproach;              /*!< filter parameter for lighting distance request on approaching oncoming targets */
  float32                         parFiltLPOncomingDepart;                /*!< filter parameter for lighting distance request on oncoming targets at increasing distance */
  float32                         parFiltLPPreceedApproach;               /*!< filter parameter for lighting distance request on approach to preceeding targets */
  float32                         parFiltLPPreceedDepart;                 /*!< filter parameter for lighting distance request on preceeding targets with incrasing distance */
  
  float32                         MinLightingDist;                        /*!< min. ligthning distance for the headlamps */
  float32                         MaxLightingDist;                        /*!< max. lightning distance for the headlamps */
}HLAFParameterLightDistance_t;

/*!< hla standard parameter */
typedef struct 
{
  /* turn on delay based on TTB of the tracks */
  HLAFParameterTurnOnDelay_t   TurnOnDelay;
  
  /* conditions for keeping HB off */
  HLAFParameterKeepOff_t          KeepOff;

  /* light distance parameter */
  HLAFParameterLightDistance_t    LightDistance;
  /* change over level parameter */
  HLAFParStdChangeOverLevel_t     ChangeOverLevel; 
}HLAFParameterStandard_t;

/*!< hla light parameter */
typedef struct 
{
  /* turn on delay based on TTB of the tracks */
  HLAFParameterTurnOnDelay_t   TurnOnDelay; 
 
  /* conditions for keeping HB off */
  HLAFParameterKeepOff_t          KeepOff;
}HLAFParameterLight_t;

/*! Type definition for the headlight control parameters. */
typedef struct 
{
  HLAFParameterCity_t         City;                 /*!< city detection parameter                                       */
  HLAFParameterHighway_t      Highway;              /*!< highway detection parameter                                    */
  RTE_HLAF_ParameterSpeed_t   SpeedPartial;         /*!< disable HLA Plus by speed parameter                            */
  HLAFParameterBlockage_t     Blockage;             /*!< blockage parameter                                             */
  HLAFParameterWeather_t      Weather;              /*!< bad weather parameter                                          */
  
  HLAFParameterStandard_t     HLAStandard;          /*!< hla standard parameter                                         */
  HLAFParameterLight_t        HLALight;             /*!< hla light parameter                                            */
  
} HLAFParameter_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern const HLAFParameter_t hlafParameter;
extern const uint32          hlafParameterVaddr;


/*****************************************************************************
  FUNCTION 
*****************************************************************************/


/* avoid cyclic binding ---------------------------------------------------*/
#endif
