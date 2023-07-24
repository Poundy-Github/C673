/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_pluscfg.h

  DESCRIPTION:            HLA plus parameter.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_pluscfg.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:27CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:07CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:47CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.11 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_pluscfg.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_pluscfg.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGES:                Revision 1.10 2013/07/09 20:03:43CEST Brunn, Marcus (brunnm) 
  CHANGES:                removed changes from ÄJ (ÄJ must be on branch)
  CHANGES:                --- Added comments ---  brunnm [Jul 9, 2013 8:03:43 PM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.9 2013/07/08 15:47:31CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Added Turn On Delay for potential oncoming Truck Lights
  CHANGES:                --- Added comments ---  uidv8778 [Jul 8, 2013 3:47:31 PM CEST]
  CHANGES:                Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGES:                Revision 1.8 2013/07/04 13:07:27CEST Brunn, Marcus (brunnm) 
  CHANGES:                - introduced separate curve tolerance angle for highway and country road
  CHANGES:                - increased curve tol. angle for country road depending on spotlight width:
  CHANGES:                spotlight navl -> +0°
  CHANGES:                spotlight width = 2.0° -> +1°
  CHANGES:                spotlight width = 2.5° -> +2°
  CHANGES:                ...
  CHANGES:                spotlight width = 5.0° -> +7°
  CHANGES:                --- Added comments ---  brunnm [Jul 4, 2013 1:07:27 PM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.7 2013/05/15 14:15:06CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced separate tolerance angle for pixel light (4 to 6 deg)
  CHANGES:                --- Added comments ---  brunnm [May 15, 2013 2:15:06 PM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.6 2012/09/24 11:28:48CEST Brunn, Marcus (brunnm) 
  CHANGES:                hlaf plus: introduced road type depending turn on delay (partial HB -> full HB: highway = 5sec, country road = 1sec)
  CHANGES:                --- Added comments ---  brunnm [Sep 24, 2012 11:28:49 AM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.5 2012/07/23 12:57:54CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - code review comments from Humic
  CHANGES:                --- Added comments ---  uidt9253 [Jul 23, 2012 12:57:54 PM CEST]
  CHANGES:                Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGES:                Revision 1.4 2012/04/21 15:04:36CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced first hla light version
  CHANGES:                --- Added comments ---  brunnm [Apr 21, 2012 3:04:36 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.3 2012/02/23 16:42:07CET Brunn, Marcus (brunnm) 
  CHANGES:                - fixed some issues for left hand traffic
  CHANGES:                - increased HB turn on delay when wiper is on stage 6
  CHANGES:                - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGES:                - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGES:                --- Added comments ---  brunnm [Feb 23, 2012 4:42:07 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.2 2012/02/20 16:40:34CET Brunn, Marcus (brunnm) 
  CHANGES:                hlaf optimization in curvy roads
  CHANGES:                Revision 1.1 2012/01/31 06:43:25CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_PLUS_CFG_INCLUDED
#define HLAF_PLUS_CFG_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* ~CodeReview ~ID:d2aa3a6e00e19e44abdc838c3cbd3a63 ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:Remove superfluous include of global_type */
#include "glob_type.h"
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

#define HLA_PLUS2_ACT_DEACT_REGION_LUT 6

/*! typedef struct for IHC Plus interface 2 parameters */
typedef struct
{
  float32   Dist_m[HLA_PLUS2_ACT_DEACT_REGION_LUT]; 
  float32   Ang_rad[HLA_PLUS2_ACT_DEACT_REGION_LUT];
  float32   CurveLightAngleFactor;
  /* track should stay for a min. time/ distance in the current region before the HB will be switched on or off */  
  float32   minTime_s;
  float32   minDist_m;
  /* keep partial HB on, when the vehicle will be back in the activation region in the next cycles */
  float32   minTimeBackInActRegion_s;
  /* track should stay for a min time the the FOV -> otherwise turn off partial HB */
  float32   minTTB_s;
}HLAplusActDeactRegionPar_t;


typedef struct 
{
  HLAplusActDeactRegionPar_t  ActRegion_LowBeam; /* activation region for partial high beam coming from low beam  */
  HLAplusActDeactRegionPar_t  ActRegion_HighBeam;/* activation region for partial high beam coming from high beam */
  HLAplusActDeactRegionPar_t  DeactRegion;       /* deactivation region  */
}HLAplus2ActDeactRegionPO_t; /* PO: preceding/ oncoming */


typedef struct 
{
  float32   FullHBWidth_left;    /* [rad] w.r.t to cut off angle */ 
  float32   FullHBWidth_right;   /* [rad] w.r.t to cut off angle */   

  float32   PartHBWidth_left;    /* [rad] part HB width w.r.t. to cutoff angle */
  float32   PartHBWidth_right;   /* [rad] part HB width w.r.t. to cutoff angle */

  float32   SpotLightWidth_left; /* [rad] spot light width w.r.t. to cutoff angle */
  float32   SpotLightWidth_right;/* [rad] spot light width w.r.t. to cutoff angle */

  float32   SpotLightOverlap; /* [rad] spot light overlap with partial HB */    
}HLAplus2ParHBCharacteristic_t;


typedef struct 
{
  float32 Alpha;
  /* dAng_max_perCylces/ dAng_min_perCylces depending on the cycles */
  float32 dAng_min_perCycle[2];
  float32 dAng_max_perCycle[2];
  uint32  Cycles[2];
} HLAplus2ParHBAngFilter_t;

typedef struct 
{
  uint16 LostCnt_0; /* reduce gap with dAng_0 per cycle */
  uint16 LostCnt_1; /* reduce gap with dAng_1 per cycle */
  uint16 LostCnt_2; /* reduce gap with dAng_2 per cycle */
  float32 dAng_0;
  float32 dAng_1;
  float32 dAng_2;
}HLAplus2ParHBAngTargetLost_t;

typedef struct 
{
  /* transition (full HB -> Part on) or (HB off -> Part HB ) */
  /* first cycles (InitialSafetyCnt_0)                       */
  /* -> add initial safety angle to min safety angle         */
  /* then filter InitialSafety to zero                       */
  float32 InitialSafety;    /* initial safety angle (always >= 0) */
  uint8   InitialSafetyCnt_0; /* keep initial safety angle */
  uint8   InitialSafetyCnt_1; /* filter initial safety angle to zero */

  /* min. safety margin (always >= 0) for partial high beam angle   */
  /* depends on online cali odometer, Odometer 0     -> 1.0° safety */
  /*                                  Odometer 5000m -> 0.5° safety */
  float32 minSafety[2];         
  float32 minSafety_CaliOdo_m[2]; /* min. safety margin (always >= 0) for partial high beam angle */
  /* = min angle between detected vehicle light and requested partial high beam angle */
  float32 maxSafety; /* max  safety margin (always >= 0) for partial high beam angle  */

  /* yaw angle depending safety angle */
  float32 Yaw_Safety_Min[3];  /* the min. safety angle (always >= 0) is defined by a LUT    */ 
  float32 Yaw_Safety_Max[3];  /* the max. safety angle (always >= 0) is defined by a LUT    */
  float32 Yaw[3];         /* linear interpolation between the points, Yaw[0] < Yaw[1] < Yaw[2] */

  /* safety angle depending on distance of preceding car */
  /* lateral safety distance                             */
  float32 Dist_SafteyWidth; /* >= 0m */
  float32 Dist_Min; /* minimum distance for a preceding car */
  float32 Dist_Max; /* maximum distance for a preceding car */
  float32 Dist_MinTime; /* minimum time to preceding car (typical 2sec -> 100km/h -> min Dist = 55m) */
} HLAplus2ParHBAngSafetyMargin_t;

typedef struct 
{
  float32 min; /* [rad] minimum partial HB angle, physical limit */
  float32 max; /* [rad] maximum partial HB angle, physical limit */
  float32 CurveTol; /* [rad] maximal curve light tolerance, L: (CurveLightAng_L - Tolerance) < left  partial HB Ang */
  /*                                      R: (CurveLightAng_R + Tolerance) > right partial HB Ang */
   
  /* filter parameter for min max HB ang */
  float32 Filter_Alpha; /* alpha */
  float32 Filter_Tol_Start;  /* fabs(raw - filtered Value) > Filter_Tol_Start -> start filter */
  float32 Filter_Tol_Stop;   /* fabs(raw - filtered Value) < Filter_Tol_Stop  -> stop filter  */
}HLAplus2ParHBAngMinMax_t;

typedef struct 
{
  HLAplus2ParHBAngFilter_t Filter_Inner;
  HLAplus2ParHBAngFilter_t Filter_Inner_Fast; /* follow object -> fast filter */
  HLAplus2ParHBAngFilter_t Filter_Outer;
  HLAplus2ParHBAngFilter_t Filter_OuterMax;
  HLAplus2ParHBAngFilter_t Filter_NoVeh;

  float32 HBAng_Tol_Inner; /* desired HB angle within old HB Angle +/- Tolerance */
  float32 HBAng_Tol_Outer; /* -> do not change old lp angle                      */

  float32 HBAng_Tol_Target; /* tolerance angle to detect if the target angle (vehicle or curve angle) is reached */

  uint8   LockCnt; /* HBAng_TargetReachedCnt > LockCnt -> lock target angle */

  /* target lost                        */
  /* keep old HB angle for some cycles  */
  uint8 NoVeh_KeepHBAng_Cnt;

  /* fast object following -> (number of the cycles following the same object) > FastFilterCycleCnt)  */
  /* use fast filter parameter set                                                                    */
  uint16 FastFilterCycleCnt;

  HLAplus2ParHBAngSafetyMargin_t SafetyMargin; /* safety margin between detected vehicle light and requested vertical cutoff angle */
  HLAplus2ParHBAngMinMax_t       MinMax; /* min/ max HB angle parameter */
}HLAplus2ParHBAng_t;


typedef struct 
{
  float32 Ang2TurnOff;   
}HLAplus2ParTurnOff_A2L_t;

typedef struct 
{
  float32 dAng2TurnOff;   
  float32 MinTimeOff_s;    /* keep partial HB off for minimal time due to dA2L */
}HLAplus2ParTurnOff_dA2L_t;

typedef struct 
{
  HLAplus2ParTurnOff_A2L_t  A2L;  /* angle of outermost vehicle is too large */
  HLAplus2ParTurnOff_dA2L_t dA2L; /* requested delta angle for the partial HB is too large */
}HLAplus2ParTurnOff_t;


typedef struct 
{
  /*******************************/
  /* country road (not motorway) */
  /*******************************/
  /* oncoming vehicles */
  HLAplus2ActDeactRegionPO_t   RegOncom; /* activation/ deactivation region for oncoming  traffic  */
  /* preceding traffic */
  HLAplus2ActDeactRegionPO_t   RegPreced;/* activation/ deactivation region for preceding traffic  */

  /************/
  /* motorway */
  /************/
  /* oncoming vehicles */
  HLAplus2ActDeactRegionPO_t   RegOncom_Motorway; /* activation/ deactivation region for oncoming  traffic  */
  /* preceding traffic */
  HLAplus2ActDeactRegionPO_t   RegPreced_Motorway;/* activation/ deactivation region for preceding traffic  */

  /* keep partial HB off for minimal time after the last oncoming vehicles passed */
  float32 MinTimeLowNoOncoming_s;        /* country road */ 

  float32 MinTimeLow2PartHB_s;            /* minimum low beam to partial high beam time */
  float32 MinTimeLow2FullHB_s;            /* minimum low beam          to full high beam time */  
  float32 MinTimePart2FullHB_s;           /* minimum partial high beam to full high beam time */  

  float32 TTD_Threshold;      /* a turn on delay will be triggered, if a TTD falls below this threshold */
  float32 TTD_MaxTurnOnDelay; /* a turn on delay will be set to maximal TTD_MaxTurnOnDelay, if a TTD falls below TTD_Threshold */

  float32 PredictionTime_Oncom_s; /* prediction time for outer most angle of oncoming  vehicles */
  float32 PredictionTime_Preced_s;/* prediction time for outer most angle of preceding vehicles */

  HLAplus2ParHBCharacteristic_t HBCharacteristic; /* high beam characteristic */

  HLAplus2ParHBAng_t HBAng_Onc;  /* high beam angle filter parameter for oncoming vehicles  */
  HLAplus2ParHBAng_t HBAng_Prec; /* high beam angle filter parameter for preceding vehicles */

  HLAplus2ParTurnOff_t TurnOff; /* turn off parameter */
}HLAplus2LeftRightParameters_t;

typedef struct
{
  /* hla standard turn on delay */
  HLAFParameterTurnOnDelay_t Std; 
  /* hla plus turn on delay */

  /* max partial HB on without relevant vehicle */
  /* for country road and highway               */
  float32 PartHBwithoutVeh_Country_s;
  float32 PartHBwithoutVeh_Highway_s;
} HLAplusParameterTurnOnDelay_t;

/*! typedef struct for HLA Plus interface 2 parameters */
typedef struct
{
  HLAplus2LeftRightParameters_t Left;   /* left  headlamp */
  HLAplus2LeftRightParameters_t Right;  /* right headlamp */

  /* parameters for HB keep off */
  HLAplusParameterTurnOnDelay_t TurnOnDelay; /* turn on delay */

  float32   KeepOff_MaxGap;         /* [rad] keep off partial HB if the gap between left and right partial HB is too large */
  float32   KeepOff_MinTimeToDeact; /* [s] keep off partial HB if the opposite partial HB will turn off in some frames */


  /* changeOverLevel selection depending on ttb */
  /* partial HB -> HB off                       */
  uint16   ChangeOverLevel_7_TTB; /* ttb < ChangeOverLevel_7_TTB -> changeOverLevel = 7 */
  uint16   ChangeOverLevel_6_TTB; /* ttb < ChangeOverLevel_6_TTB -> changeOverLevel = 6 */
  uint16   ChangeOverLevel_5_TTB; /* ttb < ChangeOverLevel_5_TTB -> changeOverLevel = 5 */
  uint16   ChangeOverLevel_4_TTB; /* ttb < ChangeOverLevel_4_TTB -> changeOverLevel = 4 */

}HLAplusParameters_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern const HLAplusParameters_t hlafPlusParameter;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/


/* avoid cyclic binding ---------------------------------------------------*/
#endif
