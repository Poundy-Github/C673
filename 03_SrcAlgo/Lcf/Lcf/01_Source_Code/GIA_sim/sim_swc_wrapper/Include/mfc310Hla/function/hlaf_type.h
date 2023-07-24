/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_type.h

  DESCRIPTION:            HLAF global type definitions.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_type.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:06CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:51CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:37CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.57 2014/03/25 18:42:31CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_type.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_type.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGES:                Revision 1.56 2014/03/19 16:30:40CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:41 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.55 2014/03/04 12:58:49CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for I390 RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:49 PM CET]
  CHANGES:                Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.54 2014/01/10 18:33:36CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:37 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.53 2014/01/08 17:10:18CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactored HLA_Exec() function
  CHANGES:                Replaced uint64 time stamps by uint32 ones
  CHANGES:                Smaller bug fixes
  CHANGES:                --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:18 PM CET]
  CHANGES:                Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.52 2013/12/18 15:18:58CET Schillinger, Patrick (uidv8776) 
  CHANGES:                turn on delays for HighwayOncomingTruckLights
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:58 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.51 2013/04/11 16:20:49CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Implemented some coding parameters
  CHANGES:                Tunnel is now global turn off reason
  CHANGES:                --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:49 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.50 2013/03/12 14:11:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2013 2:11:56 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.49 2013/03/11 18:01:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace some types by RTE ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 6:01:59 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.48 2013/03/11 16:13:32CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                - HLA_t_eSignalState
  CHANGES:                - HLA_t_eLightStyle
  CHANGES:                - HLA_t_eTunnel
  CHANGES:                - HLA_t_eCityState
  CHANGES:                - HLA_t_eWeatherState
  CHANGES:                - HLA_t_eMotorwayState
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:32 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.47 2013/03/11 14:32:51CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Placed no longer needed by RTE ones
  CHANGES:                - HLA_t_eBrightnessState
  CHANGES:                - HLA_t_eLightOutput
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:51 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.46 2013/03/11 10:37:25CET Brunn, Marcus (brunnm) 
  CHANGES:                initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
  CHANGES:                --- Added comments ---  brunnm [Mar 11, 2013 10:37:26 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.45 2013/03/08 17:42:55CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed HeadlightState and taken RTE type into use
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 5:42:56 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.44 2013/03/08 10:30:14CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:16 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.43 2013/01/24 16:37:23CET Brunn, Marcus (brunnm) 
  CHANGES:                Switched to rte like types for
  CHANGES:                - HLA_t_eTunnel
  CHANGES:                - HLA_t_eBrightnessState
  CHANGES:                - HLA_t_eMotorwayState
  CHANGES:                --- Added comments ---  brunnm [Jan 24, 2013 4:37:24 PM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.42 2013/01/18 08:04:16CET Brunn, Marcus (brunnm) 
  CHANGES:                initial matrix beam version for BMW I210
  CHANGES:                --- Added comments ---  brunnm [Jan 18, 2013 8:04:16 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.41 2013/01/18 07:46:06CET Brunn, Marcus (brunnm) 
  CHANGES:                initial matrix beam version for BMW I210
  CHANGES:                --- Added comments ---  brunnm [Jan 18, 2013 7:46:06 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.40 2013/01/07 15:39:48CET Zechner, Stefan (uidt9253) 
  CHANGES:                rename the 32-bit enum size type again to avoid a lot of ansi-c compiler errors
  CHANGES:                --- Added comments ---  uidt9253 [Jan 7, 2013 3:39:49 PM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.39 2012/11/26 10:18:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Enum size fixed to 32bit
  CHANGES:                --- Added comments ---  uidv7867 [Nov 26, 2012 10:18:48 AM CET]
  CHANGES:                Change Package : 167173:1 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.38 2012/11/15 09:56:54CET Brunn, Marcus (brunnm) 
  CHANGES:                interface update for MFC4B0, BMW I210 (without RTE)
  CHANGES:                --- Added comments ---  brunnm [Nov 15, 2012 9:56:54 AM CET]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.37 2012/07/18 07:51:48CEST Brunn, Marcus (brunnm) 
  CHANGES:                - added code review tags
  CHANGES:                --- Added comments ---  brunnm [Jul 18, 2012 7:51:48 AM CEST]
  CHANGES:                Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGES:                Revision 1.36 2012/04/25 19:26:00CEST Brunn, Marcus (brunnm) 
  CHANGES:                HLAF:
  CHANGES:                - reduced TurnOff_minTTB from 2 to 1sec
  CHANGES:                - fixed maybecity full HB turn off
  CHANGES:                - turn off partial HB for preceding vehicles in less than 25m
  CHANGES:                --- Added comments ---  brunnm [Apr 25, 2012 7:26:02 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.35 2012/04/23 15:49:59CEST Brunn, Marcus (brunnm) 
  CHANGES:                - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGES:                - delayed HB turn on after vehicles goes lost
  CHANGES:                --- Added comments ---  brunnm [Apr 23, 2012 3:49:59 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.34 2012/04/21 15:04:42CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced first hla light version
  CHANGES:                --- Added comments ---  brunnm [Apr 21, 2012 3:04:42 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.33 2012/04/20 19:27:09CEST Kaps, Alexander (kapsa) 
  CHANGES:                introduced time and distance thresholds for blockage handling
  CHANGES:                --- Added comments ---  kapsa [Apr 20, 2012 7:27:12 PM CEST]
  CHANGES:                Change Package : 112707:1 http://mks-psad:7002/im/viewissue?selection=112707
  CHANGES:                Revision 1.32 2012/03/23 11:36:16CET Brunn, Marcus (brunnm) 
  CHANGES:                introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGES:                time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGES:                
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_TYPE_INCLUDED
#define HLAF_TYPE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "glob_type.h"
#include "hla_type.h"
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

/* global turn off reason like City, too bright, ... */
typedef union
{
  uint32  u32;
  struct {
    uint32   NotReleased         : 1;  /*!< Bit_00   */
    uint32   NotReleasedRedPerf  : 1;  /*!< Bit_01   */   
    uint32   NotReleasedBlockage : 1;  /*!< Bit_02   */
    uint32   RedPerformance      : 1;  /*!< Bit_03   */
    uint32   Blockage            : 1;  /*!< Bit_04   */
    uint32   Bit_05              : 1;  /*!< Bit_05   */
    uint32   Bit_06              : 1;  /*!< Bit_06   */
    uint32   Bit_07              : 1;  /*!< Bit_07   */

    uint32   Brightness          : 1;  /*!< Bit_08   */
    uint32   Bit_09              : 1;  /*!< Bit_09   */
    uint32   Bit_10              : 1;  /*!< Bit_10   */
    uint32   Bit_11              : 1;  /*!< Bit_11   */
    uint32   Maxima              : 1;  /*!< Bit_12   */
    uint32   Lights              : 1;  /*!< Bit_13   */
    uint32   Bit_14              : 1;  /*!< Bit_14   */
    uint32   Bit_15              : 1;  /*!< Bit_15   */

    uint32   City                : 1;  /*!< Bit_16   */
    uint32   Tunnel              : 1;  /*!< Bit_17   */
    uint32   MinSpeed            : 1;  /*!< Bit_18   */
    uint32   Bit_19              : 1;  /*!< Bit_19   */
    uint32   Bit_20              : 1;  /*!< Bit_20   */
    uint32   Bit_21              : 1;  /*!< Bit_21   */
    uint32   Bit_22              : 1;  /*!< Bit_22   */
    uint32   Bit_23              : 1;  /*!< Bit_23   */

    uint32   NotActive           : 1;  /*!< Bit_24   */
    uint32   NotAvl              : 1;  /*!< Bit_25   */
    uint32   NotCalibrated       : 1;  /*!< Bit_26   */
    uint32   Bit_27              : 1;  /*!< Bit_27   */
    uint32   Bit_28              : 1;  /*!< Bit_28   */
    uint32   Error               : 1;  /*!< Bit_29   */
    uint32   Bit_30              : 1;  /*!< Bit_30   */
    uint32   Bit_31              : 1;  /*!< Bit_31   */
  } Bit;
} HLAFTurnOffReasonGlob_Reason_t;

typedef struct 
{
  uint8   NotReleased;
  uint8   NotReleasedRedPerf;
  uint8   NotReleasedBlockage;
  uint8   RedPerformance;
  uint8   Blockage;
  uint8   Cnt_05;
  uint8   Cnt_06;
  uint8   Cnt_07;

  uint8   Brightness;
  uint8   Cnt_09;
  uint8   Cnt_10;
  uint8   Cnt_11;
  uint8   Maxima;
  uint8   Lights;
  uint8   Cnt_14;
  uint8   Cnt_15;

  uint8   City;
  uint8   Tunnel;
  uint8   MinSpeed;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;
  
  uint8   NotActive;
  uint8   NotAvl;
  uint8   NotCalibrated;
  uint8   Cnt_27;
  uint8   Cnt_28;
  uint8   Error;
  uint8   Cnt_30;
  uint8   Cnt_31;
} HLAFTurnOffReasonGlob_Cnt_t;

typedef struct
{
  HLAFTurnOffReasonGlob_Reason_t  Reason;
  HLAFTurnOffReasonGlob_Cnt_t     Cnt;
  float32                         Timer_TurnOffActive_s; /* [s] */
} HLAFTurnOffReasonGlob_t;


typedef enum
{
  SPEED_STATE_LOW          = 0u,
  SPEED_STATE_HIGH         = 1u,
  SPEED_STATE_ALWAYSACTIVE = 2u,

  SPEED_STATE_LAST         = SI32_T_MAX
} SpeedState_t;

typedef union
{
  uint8  u8;
  struct {
    uint8   VerySlow                  : 1;  /*!< Vehicle Motion speed was very low */
    uint8   RecentVehicleDetection    : 1;  /*!< Recently a vehicle has been detected */   
    uint8   HighCurvature             : 1;  /*!< Vehicle Motion curvature was high */
    uint8   HighAcceleration          : 1;  /*!< Vehicle Motion acceleration was high */
    uint8   Bit_04                    : 1;  /*!< Bit_04   */
    uint8   Bit_05                    : 1;  /*!< Bit_05   */
    uint8   Bit_06                    : 1;  /*!< Bit_06   */
    uint8   Bit_07                    : 1;  /*!< Bit_07   */
  } Bit;
} SpeedKeepOffEvents_t;

/*! typedef struct for Speed analysis */
typedef struct
{
  uint8                     disableHLABySpeed;            /* HLA shall be disabled due to speed criterion */
  uint8                     keepOffHLABySpeed;            /* HLA shall be kept off due to speed criterion */

  SpeedState_t              state;
  SpeedKeepOffEvents_t      keepOffEvents;
  float32                   activatePenaltyTimer;
} HLAFSpeed_t;

/*! typedef struct for Penalty timer */
typedef struct
{
  float32                activatePenaltyTime_s;
  RTE_HLAF_HighBeamState eHBStatePrev; /* previous HB state */
  float32                HBOnTime_s;   /* partial/ full HB on time  */  
} HLAFPenaltyTimer_t;

/*! typedef struct for maximum turn on delay */
typedef struct
{
  boolean bPrecDetected;    /* relevant preceding vehicle detected    */
  boolean bOncDetected;     /* relevant oncoming vehicle detected     */
  float32 All_s;            /* all vehicles:       turn on delay  */
  float32 Onc_s;            /* oncoming vehicle:   turn on delay  */
  float32 Prec_s;           /* preceding vehicles: turn on delay  */
} HLAFRelevantVehicle_t;

/*! typedef struct for highway detection */
typedef struct
{
  /* ~CodeReview ~ID:02bfa2395378dc371393715c3cd71bcd ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:unused variable */
  uint32  dummy;
} HLAFHighway_t;


typedef enum
{
  HLAF_CITY_IDLE             = 0u, /*!< No city detected */
  HLAF_CITY_DETECTED         = 1u, /*!< City detected */
  HLAF_CITY_MAYBE            = 2u, /*!< maybe city detected */
  HLAF_CITY_MAYBE_WAIT4IDLE  = 3u, /*!< maybe city detected by HLAR but max time/ distance reached */
                                   /*!<   -> wait for HLAR city idle                               */
                                   /*!<   -> HLAF DecisionOut will report City idle                */
  HLAF_CITY_LAST             = SI32_T_MAX
} eHLAFCityState;


/*! typedef struct for city detection */
typedef struct
{
  eHLAFCityState        eCityState;       /* internal city state            */
  float32               distInCity_m;     /* [m] distance in city           */ 
  float32               timeInCity_s;     /* [s] time in city               */
  float32               distOutCity_m;    /* [m] distance outside of city   */ 
} HLAFCity_t;

typedef enum
{
  HLAF_TUNNEL_IDLE             = 0u, /*!< No tunnel detected */
  HLAF_TUNNEL_DETECTED         = 1u, /*!< Tunnel detected */
  HLAF_TUNNEL_UPFRONT          = 2u, /*!< Tunnel upfront detected */
  HLAF_TUNNEL_LAST             = SI32_T_MAX
} eHLAFTunnelState;


/*! typedef struct for tunnel detection */
typedef struct
{
  eHLAFTunnelState      eTunnelState;     /* internal tunnel state             */
  float32               distOutTunnel_m;  /* [m] distance outside of tunnnel   */ 
} HLAFTunnel_t;
/*! typedef struct for tunnel detection */

/* blockage states (do NOT change order -> only append!!!) */
typedef enum
{
  HLAF_BLOCKAGE_INIT           = 0u,
  HLAF_BLOCKAGE_CLEAR_MEAS     = 1u,
  HLAF_BLOCKAGE_MAN_OVERRIDE   = 2u,
  HLAF_BLOCKAGE_NO_BLOCKAGE    = 3u,
  HLAF_BLOCKAGE_BLOCKAGE       = 4u,
  HLAF_BLOCKAGE_CONDENSATION   = 5u,

  HLAF_BLOCKAGE_LAST           = SI32_T_MAX
}eHLAFBlockageState_t;

/*! typedef struct for blockage detection */
typedef struct
{
  eHLAFBlockageState_t      eBlockageState;
  float32                   TimeElapsed; /* in [s] */
  float32                   DistTraveled; /* in [m] */
  RTE_HLA_State             IHCStateOld;
  float32                   ToggleCountDown;
  float32                   MinDistDriven; /* in [m] */
  float32                   BlockageDist; /* in [m] */
  float32                   BlockageTime; /* in [s]  */
} HLAFBlockage_t;

/*! typedef struct for weather detection */
typedef struct
{
  /* ~CodeReview ~ID:38b04261568b49eb9cecee2ef965d553 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:unused variable */
  uint32  dummy;
} HLAFWeather_t;

typedef struct
{
  uint32  dimmRequestLeft;
  uint32  dimmRequestRight;
} HLAFDimmedLight_t;

typedef struct
{
  RTE_HLA_TrafficStyle   eTrafficStyle;
} HLAFTrafficStyle_t;

/*! Type definition for HLA light style */
typedef enum
{
  HLAF_LIGHTSTYLE_IDLE     = 0u,  /*!< idle state            */
  HLAF_LIGHTSTYLE_SYMM     = 1u,  /*!< symmetric light style */
  HLAF_LIGHTSTYLE_COUNTRY  = 2u,  /*!< Country light style   */
  HLAF_LIGHTSTYLE_MOTORWAY = 3u,  /*!< Motorway light style  */

  HLAF_LIGHTSTYLE_LAST     = SI32_T_MAX
} eHLAFLightStyle_t;

/*! typedef struct for city detection */
typedef struct
{
  float32           TimerSymmetric_s;
  float32           TimerCountry_s;
  float32           TimerMotorway_s;

  /* light style state */
  eHLAFLightStyle_t  eState;
} HLAFLightStyle_t;

/*! typedef struct for the headlight decision data. */
typedef struct
{
  /* hla standard/ binary/ plus: */ 
  /* global turn off reason      */
  HLAFTurnOffReasonGlob_t   TurnOffReason_glob; /* global turn off reason like City, Tunnel, too bright, ... */
  
  HLAFSpeed_t               Speed;
  HLAFCity_t                City;
  HLAFTunnel_t              Tunnel;
  HLAFHighway_t             Highway;
  HLAFBlockage_t            Blockage;
  HLAFWeather_t             Weather;
  HLAFDimmedLight_t         DimmedLight;
  HLAFTrafficStyle_t        TrafficStyle;
  HLAFLightStyle_t          LightStyle;
} HLAFDecisionData_t;


/*! Type definition for camera data */
typedef struct
{
  sint32  dCycle;      /* [1] hla Frame ("long" Frame) cycles since last segmentation (ECU always > 0, MTS while playing backwards < 0 )  */
  float32 dtime_s;     /* [s] time since last segmentation (always > 0)                                               */
  float32 dtimeFwd_s;  /* [s] forward driving time since last segmentation (driving forwards > 0, backwards = 0)      */
  float32 ddist_m;     /* [m] distance since last segmentation (driving forwards > 0, backwards = 0)                  */
  float32 ddistFwd_m;  /* [m] forward driving distance since last segmentation (driving forwards > 0, backwards = 0)  */
  float32 radius_m;    /* [m] radius of curvature                                                                     */
  float32 radiusAbs_m; /* [m] (> 0) absolute radius of curvature                                                      */
} HLAFCameraData_t;

/* type definition for hla standard turn off reason for full HB   */
/* -> turns full HB off                                           */
/* ~CodeReview ~ID:dc1b9248743fbb3d9f02456e7e6efad8 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef union
{
  uint32  u32;
  struct {
    uint32   OncDetected               : 1;  /*!< relevant oncoming  vehicle detected */
    uint32   PrecDetected              : 1;  /*!< relevant preceding vehicle detected */
    uint32   Bit_02                    : 1;  /*!< Bit_02   */
    uint32   Bit_03                    : 1;  /*!< Bit_03   */
    uint32   Bit_04                    : 1;  /*!< Bit_04   */
    uint32   Bit_05                    : 1;  /*!< Bit_05   */
    uint32   Bit_06                    : 1;  /*!< Bit_06   */
    uint32   Bit_07                    : 1;  /*!< Bit_07   */

    uint32   Bit_08                    : 1;  /*!< Bit_08   */
    uint32   Bit_09                    : 1;  /*!< Bit_09   */
    uint32   Bit_10                    : 1;  /*!< Bit_10   */
    uint32   Bit_11                    : 1;  /*!< Bit_11   */
    uint32   Bit_12                    : 1;  /*!< Bit_12   */
    uint32   Bit_13                    : 1;  /*!< Bit_13   */
    uint32   Bit_14                    : 1;  /*!< Bit_14   */
    uint32   Bit_15                    : 1;  /*!< Bit_15   */

    uint32   Bit_16                    : 1;  /*!< Bit_16   */
    uint32   Bit_17                    : 1;  /*!< Bit_17   */
    uint32   Bit_18                    : 1;  /*!< Bit_18   */
    uint32   Bit_19                    : 1;  /*!< Bit_19   */
    uint32   Bit_20                    : 1;  /*!< Bit_20   */
    uint32   Bit_21                    : 1;  /*!< Bit_21   */
    uint32   Bit_22                    : 1;  /*!< Bit_22   */
    uint32   Bit_23                    : 1;  /*!< Bit_23   */

    uint32   Bit_24                    : 1;  /*!< Bit_24   */
    uint32   Bit_25                    : 1;  /*!< Bit_25   */
    uint32   Bit_26                    : 1;  /*!< Bit_26   */
    uint32   Bit_27                    : 1;  /*!< Bit_27   */
    uint32   Bit_28                    : 1;  /*!< Bit_28   */
    uint32   Bit_29                    : 1;  /*!< Bit_29   */
    uint32   Bit_30                    : 1;  /*!< Bit_30   */
    uint32   Bit_31                    : 1;  /*!< Bit_31   */
  } Bit;
}HLAFStdTurnOffReason_Reason_t;

/* ~CodeReview ~ID:edbd4ee571c39dd07049a96e082fa78c ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct 
{
  uint8   OncDetected;
  uint8   PrecDetected;
  uint8   Cnt_02;
  uint8   Cnt_03;
  uint8   Cnt_04;
  uint8   Cnt_05;
  uint8   Cnt_06;
  uint8   Cnt_07;

  uint8   Cnt_08;
  uint8   Cnt_09;
  uint8   Cnt_10;
  uint8   Cnt_11;
  uint8   Cnt_12;
  uint8   Cnt_13;
  uint8   Cnt_14;
  uint8   Cnt_15;

  uint8   Cnt_16;
  uint8   Cnt_17;
  uint8   Cnt_18;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;

  uint8   Cnt_24;
  uint8   Cnt_25;
  uint8   Cnt_26;
  uint8   Cnt_27;
  uint8   Cnt_28;
  uint8   Cnt_29;
  uint8   Cnt_30;
  uint8   Cnt_31;
} HLAFStdTurnOffReason_Cnt_t;

typedef struct
{
  HLAFStdTurnOffReason_Reason_t  Reason;
  HLAFStdTurnOffReason_Cnt_t     Cnt;
} HLAFStdTurnOffReason_t;


/* keep off reason      */
/* -> keeps full HB off */
/* ~CodeReview ~ID:6d8b443d18bf459bf76f12de4a7424cb ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef union
{
  uint32  u32;
  struct {
    uint32   SpdAcc                    : 1;  /*!< velocity will fall below activation speed in less than 2.5 seconds */
    uint32   SmallRadius               : 1;  /*!< small radius */
    uint32   MinTimeHBOff              : 1;  /*!< keep HB off for a minimal time */
    uint32   TurnOnDelay_Init          : 1;  /*!< initial turn on delay       */
    uint32   TurnOnDelay_Onc           : 1;  /*!< turn on delay oncoming car  */
    uint32   TurnOnDelay_Prec          : 1;  /*!< turn on delay preceding car */
    uint32   PrecedingVehLost          : 1;  /*!< preceding vehicle lost in curve -> keep HB off until we reached the position and we are at the end of the curve */
    uint32   TurnOnDelay_Onc_TL        : 1;  /*!< Bit_07   */

    uint32   Bit_08                    : 1;  /*!< Bit_08   */
    uint32   Bit_09                    : 1;  /*!< Bit_09   */
    uint32   Bit_10                    : 1;  /*!< Bit_10   */
    uint32   Bit_11                    : 1;  /*!< Bit_11   */
    uint32   Bit_12                    : 1;  /*!< Bit_12   */
    uint32   Bit_13                    : 1;  /*!< Bit_13   */
    uint32   Bit_14                    : 1;  /*!< Bit_14   */
    uint32   Bit_15                    : 1;  /*!< Bit_15   */

    uint32   Bit_16                    : 1;  /*!< Bit_16   */
    uint32   Bit_17                    : 1;  /*!< Bit_17   */
    uint32   Bit_18                    : 1;  /*!< Bit_18   */
    uint32   Bit_19                    : 1;  /*!< Bit_19   */
    uint32   Bit_20                    : 1;  /*!< Bit_20   */
    uint32   Bit_21                    : 1;  /*!< Bit_21   */
    uint32   Bit_22                    : 1;  /*!< Bit_22   */
    uint32   Bit_23                    : 1;  /*!< Bit_23   */

    uint32   MaybeCity_Onc             : 1;  /*!< may be city detected keep full HB off because city will be detected in some frames (after oncoming vehicle was detected)  */
    uint32   MaybeCity_Prec            : 1;  /*!< may be city detected keep full HB off because city will be detected in some frames (after preceding vehicle was detected) */
    uint32   MaybeCity_Glob            : 1;  /*!< may be city detected keep full HB off because city will be detected in some frames (after global turn off reason)*/
    uint32   PotVeh_Onc                : 1;  /*!< potential vehicle detected after oncoming veh. passed */
    uint32   PotVeh_Prec               : 1;  /*!< potential vehicle detected after preceding vehicle gets lost */
    uint32   PotVeh_Glob               : 1;  /*!< potential vehcile detected after global turn off reason */
    uint32   Bit_30                    : 1;  /*!< Bit_30   */
    uint32   Bit_31                    : 1;  /*!< Bit_31   */
  } Bit;
}HLAFStdKeepOffReason_Reason_t;

/* ~CodeReview ~ID:94bbd1bdff720632d82b3fee47a0b83a ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct 
{
  uint8   SpdAcc;
  uint8   SmallRadius;
  uint8   MinTimeHBOff;
  uint8   TurnOnDelay_Init;
  uint8   TurnOnDelay_Onc;
  uint8   TurnOnDelay_Prec;
  uint8   PrecedingVehLost;
  uint8   TurnOnDelay_Onc_TL;

  uint8   Cnt_08;
  uint8   Cnt_09;
  uint8   Cnt_10;
  uint8   Cnt_11;
  uint8   Cnt_12;
  uint8   Cnt_13;
  uint8   Cnt_14;
  uint8   Cnt_15;

  uint8   Cnt_16;
  uint8   Cnt_17;
  uint8   Cnt_18;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;

  uint8   MaybeCity_Onc;
  uint8   MaybeCity_Prec;
  uint8   MaybeCity_Glob;
  uint8   PotVeh_Onc;
  uint8   PotVeh_Prec;
  uint8   PotVeh_Glob;
  uint8   Cnt_30;
  uint8   Cnt_31;
} HLAFStdKeepOffReason_Cnt_t;

/* keep off detailed data */
typedef struct
{
  float32  DelayTimer_s;
} HLAFStdKeepOffSmallRadius_t;

typedef struct
{
  float32 HBOffTimer_s;
} HLAFStdKeepOffMinTimeHBOff_t;

typedef struct
{
  float32 InitTimer_s;
  float32 TurnOnTimer_Onc_s;    /* oncoming  vehicle */
  float32 TurnOnTimer_Prec_s;   /* preceding vehicle */
  float32 TurnOnTimer_Onc_TL_s; /* oncoming  potential TL */
} HLAFStdKeepOffTurnOnDelay_t;

typedef struct
{
  float32 DelayTimer_Onc;
  float32 DelayTimer_Prec;
  float32 DelayTimer_Glob;
  uint32  Cnt; /* counts how often a potential vehicle was detected          */
  /* counter will be reseted after a turn off reason was active */
} HLAFStdKeepOffPotVeh_t;

typedef struct
{
  float32 TurnOnTimer_Onc;   /* maybe City delay after oncoming vehicle passed */
  float32 TurnOnTimer_Prec;  /* maybe City delay after preceding vehicle gets lost */
  float32 TurnOnTimer_Glob;  /* maybe City delay after global turn off reason */
} HLAFStdKeepOffMayBeCity_t;

typedef struct
{
  float32  distance2cover;
  float32  rMax;
} HLAFStdKeepOffPrecedingVehicleLost;

typedef struct
{
  HLAFStdKeepOffReason_Reason_t  Reason;
  HLAFStdKeepOffReason_Cnt_t     Cnt;

  /* keep off data */
  HLAFStdKeepOffPrecedingVehicleLost  PrecedingVehLost; /* preceding vehicle lost */
  HLAFStdKeepOffSmallRadius_t         SmallRadius;
  HLAFStdKeepOffMinTimeHBOff_t        MinTimeHBoff;
  HLAFStdKeepOffTurnOnDelay_t         TurnOnDelay;
  HLAFStdKeepOffPotVeh_t              PotVeh;           /* potential vehicle detected */
  HLAFStdKeepOffMayBeCity_t           MayBeCity;
} HLAFStdKeepOffReason_t;


/*! hla standard output data */
typedef struct
{
  RTE_HLAF_HighBeamState          eHighBeamState;
  HLA_t_fLightDistance            LowBeamDist;
  HLA_t_fLightAngle               LowBeamAngle;
  RTE_HLAF_ObjStatus              eTargetDrivingDirection;
  HLA_t_ui8ChangeoverLevel        ChangeoverLevel;

  HLAFStdTurnOffReason_Reason_t   TurnOffReason; /* turn off reason */
  HLAFStdKeepOffReason_Reason_t   KeepOffReason; /* keep off reason */

  /* penalty timer */
  float32                         activatePenaltyTime_s; 
} HLAFStdOut_t;

/*! hla standard output data */
typedef struct
{
  RTE_HLAF_HighBeamState          eHighBeamState;
  
  HLAFStdTurnOffReason_Reason_t   TurnOffReason; /* turn off reason */
  HLAFStdKeepOffReason_Reason_t   KeepOffReason; /* keep off reason */

  /* penalty timer */
  float32                         activatePenaltyTime_s; 
} HLAFLightOut_t;

/*! hla plus output data */
typedef struct
{
  RTE_HLAF_HighBeamState    eHighBeamState_Lt;
  RTE_HLAF_HighBeamState    eHighBeamState_Rt;
  float32                   RotAngleMin_Lt;
  float32                   RotAngleMin_Rt;
  RTE_HLAF_LightOutput      eLightOutput_Lt;
  RTE_HLAF_LightOutput      eLightOutput_Rt;
  HLA_t_ui8ChangeoverLevel  ChangeoverLevel_Lt;
  HLA_t_ui8ChangeoverLevel  ChangeoverLevel_Rt;
} HLAFPlusOut_t;


/* hla matrix beam output data */
typedef struct
{
  HLAF_t_Matrix Matrix;
}HLAFMatrixOut_t;


typedef struct
{
  /* factor to mirror the horizontal angle/ position for left hand traffic */
  float32 NormFactor; /*  right hand Traffic: factor =  1.0  */
  /*  left  hand Traffic: factor = -1.0  */
  
  RTE_HLA_TrafficStyle   eTrafficStyle;
} HLAFTrafficStyleOut_t;


typedef struct
{
  eHLAFLightStyle_t eLightStyle;
} HLAFLightStyleOut_t;


typedef struct
{
  RTE_HLAF_MotorwayState    eStateInt; /* only internally used by HLAF Std, Plus, Light, stays also below 65km/h in Highway when  */
                                       /* - no close vehicle was detected                                                         */
                                       /* - no exit was detected (radius < threshold over certain distance/time)                  */ 
  RTE_HLAF_MotorwayState    eStateExt; /* externally used -> FR/ CAN output, < 65km/h -> country road                             */
} HLAFMotorwayOut_t;


/*! typedef struct for the headlight decision data. */
typedef struct
{
  RTE_HLAR_CityState        eCityState;
  RTE_HLAR_WeatherState     eWeatherState;
  RTE_HLAR_Tunnel           eTunnelState;
  HLAFMotorwayOut_t         Motorway;
  RTE_HLAR_BrightnessState  eBrightnessState;
  HLA_t_Blockage            Blockage;
  RTE_HLAF_LightOutput      eLightOutput_Lt;
  RTE_HLAF_LightOutput      eLightOutput_Rt;
  HLAFTrafficStyleOut_t     TrafficStyle;
  HLAFLightStyleOut_t       LightStyle;
} HLAFDecisionOut_t;


/* HLAF data */
typedef struct
{
  AlgoCycleCounter_t  HLAF_Cnt;           /*!< HLAS cycle counter   */
  AlgoCycleCounter_t  FrameCnt;           /*!< [1] image counter    */  
  AlgoDataTimeStamp_t TimeStamp_HLA_us;   /*!< [us] HLA Timestamp   */
  AlgoDataTimeStamp_t TimeStamp_Image_us; /*!< [us] Image Timestamp */

  HLAFCameraData_t    CamData;
  HLAFDecisionData_t  DecisionData;

  HLAFDecisionOut_t   DecisionOut; /* decision output data      */
  HLAFStdOut_t        HLAStdOut;   /* HLA Standard output data  */
  HLAFLightOut_t      HLALightOut; /* HLA Light output data     */
  HLAFPlusOut_t       HLAPlusOut;  /* HLA Plus output data      */

  HLAFMatrixOut_t     HLAMatrixOut; /* HLA Matrix Output data */
} HLAFData_t;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAFDecicionDecTurnKeepOffCnt(uint8 *pui8_Cnt, uint32 length);


/* avoid cyclic binding ---------------------------------------------------*/
#endif
