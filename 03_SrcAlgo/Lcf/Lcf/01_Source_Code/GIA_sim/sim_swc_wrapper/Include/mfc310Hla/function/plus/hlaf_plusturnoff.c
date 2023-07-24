/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plusturnoff.c

  DESCRIPTION:            HLA plus turn off functions.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_plusturnoff.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:29CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:12CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:50CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.31 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_plusturnoff.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusturnoff.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.30 2014/03/19 16:31:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:23 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.29 2014/03/04 16:52:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:30 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.28 2014/03/04 12:59:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for I390 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 12:59:03 PM CET]
  CHANGE:                 Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/01/21 09:12:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:59 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.26 2013/05/23 10:31:05CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed PC-LINT errors
  CHANGE:                 --- Added comments ---  uidv7867 [May 23, 2013 10:31:05 AM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.25 2013/04/25 11:03:06CEST Brunn, Marcus (brunnm) 
  CHANGE:                 implemented hla plus configuration switch 
  CHANGE:                 implemented TurnOffLeft_OncOnly, TurnOffLeft_LeftOnly, KeepOffLeft_LeftOnly and AsymmetricMode
  CHANGE:                 --- Added comments ---  brunnm [Apr 25, 2013 11:03:06 AM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.24 2013/03/13 17:32:28CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:32:29 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.23 2013/03/11 18:02:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace some types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 6:02:02 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.22 2013/03/11 16:13:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:38 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.21 2013/03/08 17:43:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:24 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.20 2013/03/08 10:30:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:43 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19 2013/01/28 15:06:15CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eRedReflectorArea
  CHANGE:                 - HLA_t_eHighwayLatPosState
  CHANGE:                 - HLA_t_eHighwayEgoMotionState
  CHANGE:                 - HLA_t_eHighwayOcclusionState
  CHANGE:                 --- Added comments ---  brunnm [Jan 28, 2013 3:06:15 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.18 2013/01/24 16:37:23CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:23 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.17 2013/01/23 17:57:40CET Brunn, Marcus (brunnm) 
  CHANGE:                 Converted enum to rte like type for
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 --- Added comments ---  brunnm [Jan 23, 2013 5:57:40 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.16 2013/01/18 07:46:04CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:05 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.15 2012/11/15 09:56:52CET Brunn, Marcus (brunnm) 
  CHANGE:                 interface update for MFC4B0, BMW I210 (without RTE)
  CHANGE:                 --- Added comments ---  brunnm [Nov 15, 2012 9:56:52 AM CET]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.14 2012/09/06 10:59:03CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed false keep off of left partial HB after leaving Highway
  CHANGE:                 --- Added comments ---  brunnm [Sep 6, 2012 10:59:05 AM CEST]
  CHANGE:                 Change Package : 158395:1 http://mks-psad:7002/im/viewissue?selection=158395
  CHANGE:                 Revision 1.13 2012/07/23 12:58:07CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:07 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.12 2012/07/18 09:21:54CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 9:21:54 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.11 2012/04/24 18:17:38CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed false turn off of partial HB on right side when oncoming/ preceding car detected in a curve
  CHANGE:                 --- Added comments ---  brunnm [Apr 24, 2012 6:17:39 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.10 2012/04/21 15:04:39CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:39 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/03/15 16:25:12CET Brunn, Marcus (brunnm) 
  CHANGE:                 added new highway state: HLAR_HIGHWAY_EM_LOW_SPEED
  CHANGE:                 Revision 1.8 2012/03/14 08:55:30CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed one cycle HB on bug (England test drive, city entry, 29.02.2012 22:25)
  CHANGE:                 Revision 1.7 2012/03/12 07:27:35CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed use of global variable (hlafPlusData)
  CHANGE:                 --- Added comments ---  brunnm [Mar 12, 2012 7:27:35 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.6 2012/02/23 16:42:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed some issues for left hand traffic
  CHANGE:                 - increased HB turn on delay when wiper is on stage 6
  CHANGE:                 - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGE:                 - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGE:                 --- Added comments ---  brunnm [Feb 23, 2012 4:42:08 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.5 2012/02/20 16:40:36CET Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf optimization in curvy roads
  CHANGE:                 Revision 1.4 2012/02/13 06:24:11CET Brunn, Marcus (brunnm) 
  CHANGE:                 used relevant traffic flag from extended object list
  CHANGE:                 Revision 1.3 2012/02/08 16:57:53CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed detection of relevant traffic
  CHANGE:                 - hla plus: fast HB on when oncoming traffic passed
  CHANGE:                 Revision 1.2 2012/02/06 15:27:46CET Brunn, Marcus (brunnm) 
  CHANGE:                 turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGE:                 Revision 1.1 2012/01/31 06:43:29CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_plusturnoff.h"
#include "hlaf_defs.h"

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
static void HLAPlusTurnOffPart_OncOnLeftSideOfPrec( /* input */
                                                   const HLAF_t_RequiredInputs  *ps_In,
                                                   const HLAFData_t             *pFData,
                                                   /* history */
                                                   HLAplusData_t                *pPlusData, 
                                                   /* output */
                                                   HLAplusTurnOffReason_t       *pTurnOffReason_left
                                                  );
static void HLAPlusTurnOffPart_OncomingTraffic(  const eHLAplusHeadlamp_t         eHeadlamp,
                                                 const HLA_t_Object               *pVehOutermost_Alive,
                                                 const HLAplusActDeactRegionPar_t *pDeactRegPar,
                                                 HLAplusTurnOffReason_t           *pTurnOffReason,
                                                 eHLAplusHBState_t                eState,
                                                 const HLAplusRegion_t            *pRegionOncom_Alive,
                                                 float32                          MinTimeToDeact,
                                                 float32                          MaxTimeToAct,
                                                 boolean                          bVehWithinHBRegion,
                                                 const HLA_t_Object               *pTrack_Alive,
                                                 const float32                    TTD_Threshold 
                                              );
static void HLAPlusTurnOffPart_PrecedingTraffic( const eHLAplusHeadlamp_t         eHeadlamp,
                                                 const HLAplusActDeactRegionPar_t *pDeactRegPar,
                                                 HLAplusTurnOffReason_t           *pTurnOffReason,
                                                 eHLAplusHBState_t                eState,
                                                 const HLAplusRegion_t            *pRegionPreced,
                                                 const HLAplusRegion_t            *pRegionPreced_Alive,
                                                 float32                          MinTimeToDeact,
                                                 float32                          MaxTimeToAct,
                                                 const HLA_t_Object               *pTrack_Alive,
                                                 const float32                    TTD_Threshold
                                               );
static void HLAPlusTurnOffPart_AngOutermost2Large(HLAplusTurnOffReason_t *pTurnOffReason, float32 AngOutermost, float32 MaxAng);
static void HLAPlusTurnOffPart_dAng2Large( eHLAplusHBState_t eState,
                                            float32                    dHighBeamAngle_Thres,
                                            float32                    dHighBeamAngle_Requested,
                                            uint8                      DelayCntStart,  
                                            uint8                      *pDelayCnt,
                                            HLAplusTurnOffReason_t    *pTurnOffReason
                                            );

static boolean HLAPlusTurnOffFull_VehicleWithinHBRegion(  const HLA_t_ObjectList               *pObjList,
                                                          const HLAplusObject_t                *pObjListExt,
                                                          const RTE_HLAF_HighBeamState          eHBState,
                                                          const HLAplus2ParHBCharacteristic_t  *pHBCh,
                                                          const float32                        HB_RotAng,
                                                          const float32                        SafetyAng,
                                                          const RTE_HLAF_ObjStatus             eTraffic,
                                                          const float32                        SpotLightWidth_left,
                                                          const float32                        SpotLightWidth_right,
                                                          const HLAFTrafficStyleOut_t          *pTrafficStyle
                                                       );


static void HLAPlusTurnOffPart_dAng2Large( eHLAplusHBState_t eState,
                                            float32                    dHighBeamAngle_Thres,
                                            float32                    dHighBeamAngle_Requested,
                                            uint8                      DelayCntStart,  
                                            uint8                      *pDelayCnt,
                                            HLAplusTurnOffReason_t    *pTurnOffReason
                                            )
{
  if(eState ==  HLA_PLUS_HB_STATE_PART_ON)
  {
    if(dHighBeamAngle_Requested > dHighBeamAngle_Thres)
    {
      pTurnOffReason->Reason.Bit.dAng2Large = 1;
      pTurnOffReason->Cnt.dAng2Large = HLAF_TURN_OFF_REASON_MAX_CNT;
      /* load delay counter */
      *pDelayCnt = DelayCntStart;  
    }
  }
  if(*pDelayCnt > 0)
  {
    *pDelayCnt = (*pDelayCnt) - 1;
  }
  else
  {
    /* time elapsed */
    /* remove flag  */
    pTurnOffReason->Reason.Bit.dAng2Large = 0;
  }
}


static void HLAPlusTurnOffPart_AngOutermost2Large(HLAplusTurnOffReason_t *pTurnOffReason, float32 AngOutermost, float32 MaxAng)
{
  if(AngOutermost > MaxAng)
  {
    pTurnOffReason->Reason.Bit.AngOutermost2Large = 1;
    pTurnOffReason->Cnt.AngOutermost2Large = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.AngOutermost2Large = 0;
  }
}

static void HLAPlusTurnOffPart_PrecedingTraffic( const eHLAplusHeadlamp_t         eHeadlamp,
                                                 const HLAplusActDeactRegionPar_t *pDeactRegPar,
                                                 HLAplusTurnOffReason_t           *pTurnOffReason,
                                                 eHLAplusHBState_t                eState,
                                                 const HLAplusRegion_t            *pRegionPreced,
                                                 const HLAplusRegion_t            *pRegionPreced_Alive,
                                                 float32                          MinTimeToDeact,
                                                 float32                          MaxTimeToAct,
                                                 const HLA_t_Object               *pTrack_Alive,
                                                 const float32                    TTD_Threshold
                                               )
{
   
  if(/* full HB on */
     /* and vehicle in Deactivation region */
        (   (    (eState == HLA_PLUS_HB_STATE_FULL_ON)
              || (eState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
              || (eState == HLA_PLUS_HB_STATE_PART_2_FULL_ON)
            )
         && (pRegionPreced_Alive->eRegion == HLA_PLUS_DEACT_REGION)
        )
     /* full HB on */
     /* and vehicle in Activation region */
     || (   (    (eState == HLA_PLUS_HB_STATE_FULL_ON)
              || (eState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
              || (eState == HLA_PLUS_HB_STATE_PART_2_FULL_ON)
            )
         && (pRegionPreced_Alive->eRegion == HLA_PLUS_ACT_REGION)
         /* preceding car detected on left side:  -> turn off only left  partial HB */
         /* preceding car detected on right side: -> turn off only right partial HB */
         && (   ((pTrack_Alive->f32_ObjectHorAng_rad > 0.0f) && (eHeadlamp == HLA_PLUS_LEFT_HEADLAMP))
             || ((pTrack_Alive->f32_ObjectHorAng_rad < 0.0f) && (eHeadlamp == HLA_PLUS_RIGHT_HEADLAMP))
            )
         /* vehicle stays long enough in activation/ hold region */
         /* ~CodeReview ~ID:b1c7da31a37959824d60aab229d2a34c ~Reviewer:CW01\uidu4053 ~Date:17.07.2012 ~Priority:3 ~Comment:Replace magic number with parameter */
         && (MinTimeToDeact < (0.8f * TTD_Threshold))
        )
     /* partial HB on */
     || (   (   (eState == HLA_PLUS_HB_STATE_PART_ON)
             || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
             || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
            )
         && (pRegionPreced_Alive->eRegion == HLA_PLUS_DEACT_REGION)
         /* object long enough in deactivation region ? */ 
         && (pRegionPreced_Alive->dist_m > pDeactRegPar->minDist_m)
         && (pRegionPreced_Alive->time_s > pDeactRegPar->minTime_s)
         /* vehicle will be back in Activation region in the next cycles */
         && (MaxTimeToAct > pDeactRegPar->minTimeBackInActRegion_s)
        )
     /* partial HB on */
     /* and vehicle will leave FOV in next seconds */
     || (   (    (eState == HLA_PLUS_HB_STATE_PART_ON)
              || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
              || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
            )  
         && (pRegionPreced_Alive->eRegion == HLA_PLUS_DEACT_REGION)
         && (pTrack_Alive != NULL)
         && ((pTrack_Alive->ui16_ttb18_ms*0.001f) < pDeactRegPar->minTTB_s)
        )
     /* HB off */
     || (   (    (eState == HLA_PLUS_HB_STATE_OFF)
              || (eState == HLA_PLUS_HB_STATE_PART_2_OFF)
              || (eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
            ) 
         && (   (pRegionPreced->eRegion == HLA_PLUS_DEACT_REGION)
             || (pRegionPreced->eRegion == HLA_PLUS_HOLD_REGION)
            )
        )
    )
  {
    pTurnOffReason->Reason.Bit.Preceding = 1;
    pTurnOffReason->Cnt.Preceding = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.Preceding = 0;
  }                                  
}


static void HLAPlusTurnOffPart_OncomingTraffic(  const eHLAplusHeadlamp_t         eHeadlamp,
                                                 const HLA_t_Object               *pVehOutermost_Alive,
                                                 const HLAplusActDeactRegionPar_t *pDeactRegPar,
                                                 HLAplusTurnOffReason_t           *pTurnOffReason,
                                                 eHLAplusHBState_t                eState,
                                                 const HLAplusRegion_t            *pRegionOncom_Alive,
                                                 float32                          MinTimeToDeact,
                                                 float32                          MaxTimeToAct,
                                                 boolean                          bVehWithinHBRegion,
                                                 const HLA_t_Object               *pTrack_Alive,
                                                 const float32                    TTD_Threshold 
                                              )
{
  /* outermost vehicle is oncoming */
  if(pVehOutermost_Alive->s_Status.isVehicleOncoming == 1)
  {
    if(/* full HB on */
      /* vehicle in deactivation region */
          (   (    (eState == HLA_PLUS_HB_STATE_FULL_ON)
                || (eState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
                || (eState == HLA_PLUS_HB_STATE_PART_2_FULL_ON)
              )
           && (pRegionOncom_Alive->eRegion == HLA_PLUS_DEACT_REGION)
           /* vehicle within HB region */
           && (bVehWithinHBRegion == TRUE)
          )
       /* full HB on */
       /* vehicle in activation region */ 
       || (   (    (eState == HLA_PLUS_HB_STATE_FULL_ON)
                || (eState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
                || (eState == HLA_PLUS_HB_STATE_PART_2_FULL_ON)
              )
           && (pRegionOncom_Alive->eRegion == HLA_PLUS_ACT_REGION)
           /* oncoming car detected on left side:  -> turn off only left  partial HB */
           /* oncoming car detected on right side: -> turn off only right partial HB */
           && (   ((pTrack_Alive->f32_ObjectHorAng_rad > 0.0f) && (eHeadlamp == HLA_PLUS_LEFT_HEADLAMP))
               || ((pTrack_Alive->f32_ObjectHorAng_rad < 0.0f) && (eHeadlamp == HLA_PLUS_RIGHT_HEADLAMP))
              )
           /* vehicle stays long enough in activation/ hold region */
           && (MinTimeToDeact < (0.5f * TTD_Threshold))
           /* vehicle within HB region */
           && (bVehWithinHBRegion == TRUE)
          )
       /* partial HB on */
       || (   (    (eState == HLA_PLUS_HB_STATE_PART_ON)
                || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
                || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
              )
           && (pRegionOncom_Alive->eRegion == HLA_PLUS_DEACT_REGION)
           /* object long enough in deactivation region ? */ 
           && (pRegionOncom_Alive->dist_m > pDeactRegPar->minDist_m)
           && (pRegionOncom_Alive->time_s > pDeactRegPar->minTime_s)
           /* vehicle will be back in Activation region in the next cycles */
           && (MaxTimeToAct > pDeactRegPar->minTimeBackInActRegion_s)
           /* vehicle within HB region */
           && (bVehWithinHBRegion == TRUE)
          )
       /* partial HB on */
       /* and vehicle will leave FOV in next seconds */
       || (   (    (eState == HLA_PLUS_HB_STATE_PART_ON)
                || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
                || (eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
              )
           && (pRegionOncom_Alive->eRegion == HLA_PLUS_DEACT_REGION)
           && (pTrack_Alive != NULL)
           && ((pTrack_Alive->ui16_ttb18_ms*0.001f) < pDeactRegPar->minTTB_s)
          ) 
       /* HB off */
       || (   (    (eState == HLA_PLUS_HB_STATE_OFF)
                || (eState == HLA_PLUS_HB_STATE_PART_2_OFF)
                || (eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
              ) 
           && (   (pRegionOncom_Alive->eRegion == HLA_PLUS_DEACT_REGION)
               || (pRegionOncom_Alive->eRegion == HLA_PLUS_HOLD_REGION)
              )
          )
      )
    {
      pTurnOffReason->Reason.Bit.Oncoming = 1;
      pTurnOffReason->Cnt.Oncoming = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pTurnOffReason->Reason.Bit.Oncoming = 0;
    }                                  
  }
  else
  {
    pTurnOffReason->Reason.Bit.Oncoming = 0;
  }
}



/*******************************************************************/
/* oncoming traffic detected on the left side of the preceding car */
/* -> deactivate partial high beam of the left headlamps           */
/*******************************************************************/
static void HLAPlusTurnOffPart_OncOnLeftSideOfPrec( /* input */
                                                    const HLAF_t_RequiredInputs  *ps_In,
                                                    const HLAFData_t             *pFData,
                                                    /* history */
                                                    HLAplusData_t                *pPlusData, 
                                                    /* output */
                                                    HLAplusTurnOffReason_t       *pTurnOffReason_left
                                                  )
{
  uint32 i;
  float32 AngOutermost_Prec = CML_Deg2Rad(-90.0f);
  float32 AngOutermost_Onc  = CML_Deg2Rad(-91.0f);
  boolean bPrec = b_FALSE;
  boolean bOnc = b_FALSE;
  
/* ~CodeReview ~ID:d7b1907bd8cf11b40a1e6bd77a938e1a ~Reviewer:PC2184\jongd ~Date:19-7-2012 ~Priority:2 ~Comment:Check that ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles <= RTE_HLAR_OBJECT_LIST_LENGTH */
  for(i=0; i<ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles; i++) 
  {
    HLA_t_Object *pObj = &ps_In->s_Sig.ps_ObjectList->as_Object[i];
    HLAplusObjectData_t *pObjExt_lt = &pPlusData->Object.Left.Obj[i];
    float32 HorAng_norm = pFData->DecisionOut.TrafficStyle.NormFactor * pObj->f32_ObjectHorAng_rad;    

    /* find outermost left preceding and oncoming car */
    if(   (pObjExt_lt->Status.isRelevantTraffic == 1)
       && (pObj->ui8_lost_time == 0)
      )
    {
      if(pObj->s_Status.isVehicleAhead == 1)
      {
        /* preceding car */
        bPrec = b_TRUE;
        if(HorAng_norm > AngOutermost_Prec)
        {
          AngOutermost_Prec = HorAng_norm;
        }
      }
      if(pObj->s_Status.isVehicleOncoming == 1)
      {
        /* oncoming car */
        bOnc = b_TRUE;
        if(HorAng_norm > AngOutermost_Onc)
        {
          AngOutermost_Onc = HorAng_norm;
        }
      }
    }
  }


  /* check if oncoming vehicle is on the left side of the preceding car */
  if(    (AngOutermost_Onc > AngOutermost_Prec)
      && (bPrec == b_TRUE)
      && (bOnc  == b_TRUE)
    )
  {
    /* deactivate left partial HB */
    pTurnOffReason_left->Reason.Bit.OncLeftPrec = 1;
    pTurnOffReason_left->Cnt.OncLeftPrec = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason_left->Reason.Bit.OncLeftPrec = 0;
  }
}


void HLAPlusTurnOffPart( const HLAF_t_RequiredInputs  *ps_In,
                         const HLAFData_t             *pFData,
                         const HLA_t_CameraParameter  *pCamPar,
                         const HLAplusInputData_t     *pPlusIn,
                         const HLAFPlusOut_t          *pPlusOut,
                         HLAplusData_t                *pPlusData,
                         HLAplusTurnOffReason_t       *pTurnOffReason_left,
                         HLAplusTurnOffReason_t       *pTurnOffReason_right
                       )
{
  boolean  bVehWithinHBRegion;
  float32  TrafficStyle_NormFactor = pFData->DecisionOut.TrafficStyle.NormFactor;

  HLAFDecicionDecTurnKeepOffCnt( &pTurnOffReason_left->Cnt.OncomingOnly,
    sizeof(pTurnOffReason_left->Cnt)
    );
  HLAFDecicionDecTurnKeepOffCnt( &pTurnOffReason_right->Cnt.OncomingOnly,
    sizeof(pTurnOffReason_right->Cnt)
    );

  /******************************************************************************/
  /* below activation speed                                                     */
  /******************************************************************************/
  /* HB on, vehicle detected and speed will fall below activation speed         */
  /* do not turn on partial HB because it will be turned off in the next cycles */
  /******************************************************************************/
  if(    /* below activation speed */
         (pPlusData->DecisionData.Speed.disableHLABySpeed == 1)
         /* HB on, vehicle detected and velocity will fall below activation speed in next cycles */
      || (   (pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON)
          && (pPlusData->Outermost.Right.bVehDet_Alive == TRUE)
          && (pPlusData->DecisionData.Speed.keepOffHLABySpeed == 1)
         )
    )
  {
    /* min speed */
    pTurnOffReason_left->Reason.Bit.MinSpeed = 1;
    pTurnOffReason_left->Cnt.MinSpeed = HLAF_TURN_OFF_REASON_MAX_CNT;
    pTurnOffReason_right->Reason.Bit.MinSpeed = 1;
    pTurnOffReason_right->Cnt.MinSpeed = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason_left->Reason.Bit.MinSpeed = 0;
    pTurnOffReason_right->Reason.Bit.MinSpeed = 0;
  }

  /************************************************************/
  /* HB on, vehicle  detected and maybe city detected         */
  /* do not turn on the partial HB because in the next cycles */
  /* partial HB will be switched off due to the city          */ 
  /************************************************************/
  if(    (pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON)
      && (pPlusData->Outermost.Right.bVehDet_Alive == TRUE)
      && (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
    )
  {
    /* maybe city */
    pTurnOffReason_left->Reason.Bit.MayBeCity = 1;
    pTurnOffReason_left->Cnt.MayBeCity = HLAF_TURN_OFF_REASON_MAX_CNT;
    pTurnOffReason_right->Reason.Bit.MayBeCity = 1;
    pTurnOffReason_right->Cnt.MayBeCity = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason_left->Reason.Bit.MayBeCity  = 0;
    pTurnOffReason_right->Reason.Bit.MayBeCity = 0;
  }


  /*************************************************/ 
  /* oncoming traffic which deactivates partial HB */
  /*************************************************/

  /* check if a vehicle is within the High Beam region */
  /* if no:  do not turn partial/ full HB off, because the oncoming vehicle will be not blinded */
  /* if yes: turn off partial/ full HB                                                          */
  bVehWithinHBRegion = TRUE;
  HLAPlusTurnOffPart_OncomingTraffic(
                                      HLA_PLUS_LEFT_HEADLAMP,
                                      &pPlusData->Outermost.Left.VehOutermost_Alive,
                                      pPlusData->Region.pDeactReg_left_oncom,
                                      pTurnOffReason_left,
                                      pPlusData->HBState.Left.eState,
                                      &pPlusData->Region.RegionOncom_Alive_left,
                                      pPlusData->Region.MinTimeToDeact_left_s,
                                      pPlusData->Region.MaxTimeToAct_left_s,
                                      bVehWithinHBRegion,
                                      pPlusData->Region.pObjOncom_Alive_left,
                                      hlafPlusParameter.Left.TTD_Threshold
                                    );

  /* check if a vehicle is within the High Beam region */
  /* if no:  do not turn partial/ full HB off, because the oncoming vehicle will be not blinded */
  /* if yes: turn off partial/ full HB                                                          */
  bVehWithinHBRegion = TRUE;
  HLAPlusTurnOffPart_OncomingTraffic(
                                      HLA_PLUS_RIGHT_HEADLAMP,
                                      &pPlusData->Outermost.Right.VehOutermost_Alive,
                                      pPlusData->Region.pDeactReg_right_oncom,
                                      pTurnOffReason_right,
                                      pPlusData->HBState.Right.eState,
                                      &pPlusData->Region.RegionOncom_Alive_right,
                                      pPlusData->Region.MinTimeToDeact_right_s,
                                      pPlusData->Region.MaxTimeToAct_right_s,
                                      bVehWithinHBRegion,
                                      pPlusData->Region.pObjOncom_Alive_right,
                                      hlafPlusParameter.Right.TTD_Threshold
                                    );

  /**************************************************/
  /* preceding traffic which deactivates partial HB */
  /**************************************************/
  HLAPlusTurnOffPart_PrecedingTraffic(
                                      HLA_PLUS_LEFT_HEADLAMP,
                                      pPlusData->Region.pDeactReg_left_preced,
                                      pTurnOffReason_left,
                                      pPlusData->HBState.Left.eState,
                                      &pPlusData->Region.RegionPreced_left,
                                      &pPlusData->Region.RegionPreced_Alive_left,
                                      pPlusData->Region.MinTimeToDeact_left_s,
                                      pPlusData->Region.MaxTimeToAct_left_s,
                                      pPlusData->Region.pObjPreced_Alive_left,
                                      hlafPlusParameter.Left.TTD_Threshold
                                      );
  HLAPlusTurnOffPart_PrecedingTraffic(
                                      HLA_PLUS_RIGHT_HEADLAMP,
                                      pPlusData->Region.pDeactReg_right_preced,
                                      pTurnOffReason_right,
                                      pPlusData->HBState.Right.eState,
                                      &pPlusData->Region.RegionPreced_right,
                                      &pPlusData->Region.RegionPreced_Alive_right,
                                      pPlusData->Region.MinTimeToDeact_right_s,
                                      pPlusData->Region.MaxTimeToAct_right_s,
                                      pPlusData->Region.pObjPreced_Alive_right,
                                      hlafPlusParameter.Right.TTD_Threshold
                                      );


  /******************************************/
  /* outermost angle is too large           */
  /******************************************/
  HLAPlusTurnOffPart_AngOutermost2Large( pTurnOffReason_left,
                                        CML_f_Max(pPlusData->Outermost.Left.AngOutermostPred_Alive, (TrafficStyle_NormFactor * pPlusData->Outermost.Left.VehOutermost_Alive.f32_ObjectHorAng_rad)),
                                        hlafPlusParameter.Left.TurnOff.A2L.Ang2TurnOff
                                        );
  HLAPlusTurnOffPart_AngOutermost2Large( pTurnOffReason_right,
                                        -CML_Min(pPlusData->Outermost.Right.AngOutermostPred_Alive, (TrafficStyle_NormFactor * pPlusData->Outermost.Right.VehOutermost_Alive.f32_ObjectHorAng_rad)),
                                        -hlafPlusParameter.Right.TurnOff.A2L.Ang2TurnOff
                                        );

  /**************************************************************************/
  /* difference between current and requested partial HB angle is too large */
  /**************************************************************************/
  {
    float32 dAng;
    uint8 DelayCntStart;
    

    /* left side */
    /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() */
    /* uint8 is always >= 0 */
    DelayCntStart = (uint8)CML_Min(255u, CML_u_Round2Uint(hlafPlusParameter.Left.TurnOff.dA2L.MinTimeOff_s / pCamPar->f32_cycleTime));
    /* criteria is only interesting for alive vehicles */
    if(pPlusData->Outermost.Left.bVehDet_Alive == TRUE)
    {
      dAng = ((TrafficStyle_NormFactor * pPlusData->Outermost.Left.VehOutermost_Alive.f32_ObjectHorAng_rad) - pPlusOut->RotAngleMin_Lt);
    }
    else
    {
      dAng = 0.0f;
    }  
    HLAPlusTurnOffPart_dAng2Large( pPlusData->HBState.Left.eState,
      hlafPlusParameter.Left.TurnOff.dA2L.dAng2TurnOff,
      dAng,
      DelayCntStart,
      /* history */
      &pPlusData->TurnOff.dA2L_DelayCnt_left,
      /* output */
      pTurnOffReason_left
      );
    /* right side */
    /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() */
    /* uint8 is always >= 0 */
    DelayCntStart = (uint8)CML_Min(255u, CML_u_Round2Uint(hlafPlusParameter.Right.TurnOff.dA2L.MinTimeOff_s/ pCamPar->f32_cycleTime));
    /* criteria is only interesting for alive vehicles */
    if(pPlusData->Outermost.Right.bVehDet_Alive == TRUE)
    {
      dAng = ((TrafficStyle_NormFactor * pPlusData->Outermost.Right.VehOutermost_Alive.f32_ObjectHorAng_rad) - pPlusOut->RotAngleMin_Rt);
    }
    else
    {
      dAng = 0.0f;
    }
    HLAPlusTurnOffPart_dAng2Large( pPlusData->HBState.Right.eState,
      hlafPlusParameter.Right.TurnOff.dA2L.dAng2TurnOff,
      -dAng,
      DelayCntStart,
      /* history */
      &pPlusData->TurnOff.dA2L_DelayCnt_right,
      /* output */
      pTurnOffReason_right
      );
  }

  /***************************************************************/
  /* only oncoming traffic detected (no preceding vehicles)      */
  /* -> deactivate partial high beam of the left headlamps       */
  /*    the unused left high beam could be used by the spot      */
  /*    to support the right partial high beam                   */
  /***************************************************************/
  if(   (pPlusData->Region.RegionOncom_Alive_right.eRegion  != HLA_PLUS_NO_OBJ)
      && (pPlusData->Region.RegionPreced_Alive_right.eRegion == HLA_PLUS_NO_OBJ)
      && (pPlusIn->Cfg.TurnOffLeft_OncOnly == 1) 
    )
  {
    /* turn off left high beam */
    pTurnOffReason_left->Reason.Bit.OncomingOnly = 1;
    pTurnOffReason_left->Cnt.OncomingOnly        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason_left->Reason.Bit.OncomingOnly  = 0;
    pTurnOffReason_right->Reason.Bit.OncomingOnly = 0;
  }


  /***************************************************************/
  /* oncoming traffic which deactivates right partial high beams */
  /* -> deactivate partial high beam of the left headlamps       */
  /***************************************************************/
  if(    (pTurnOffReason_right->Reason.Bit.Oncoming == 1)
      && (pPlusData->HBState.Right.eState      != HLA_PLUS_HB_STATE_OFF)
      && (pPlusIn->Cfg.TurnOffLeft_OncOnly == 1)
    )
  {
    pTurnOffReason_left->Reason.Bit.OncomingDeactRegion = 1;
    pTurnOffReason_left->Cnt.OncomingDeactRegion = HLAF_TURN_OFF_REASON_MAX_CNT;
  }

  /* delete flag when no oncoming traffic is detected */
  if(    (pPlusData->Region.RegionOncom_left.eRegion  == HLA_PLUS_NO_OBJ)
    && (pPlusData->Region.RegionOncom_right.eRegion == HLA_PLUS_NO_OBJ)
    )
  {
    pTurnOffReason_right->Reason.Bit.OncomingDeactRegion = 0;
    pTurnOffReason_left->Reason.Bit.OncomingDeactRegion = 0;
  }

  /*******************************************************************/
  /* oncoming traffic detected on the left side of the preceding car */
  /* -> deactivate partial high beam of the left headlamps           */
  /*******************************************************************/
  if(pPlusIn->Cfg.TurnOffLeft_OncOnly == 1)
  {
    HLAPlusTurnOffPart_OncOnLeftSideOfPrec( /* input */
                                            ps_In,
                                            pFData,
                                            /* history */
                                            pPlusData,
                                            /* output */
                                            pTurnOffReason_left
                                          );
  }
  

  /**************************************************************************/
  /* right hand traffic:                                                    */
  /*   deactivate left partial HB in advance when TTD is small              */
  /*   (reduce blinding of oncoming vehicles)                               */
  /**************************************************************************/
  pTurnOffReason_left->Reason.Bit.TTD  = 0;
  pTurnOffReason_right->Reason.Bit.TTD = 0;

  if(    (pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTD_s > 0.0f)
      && (pPlusData->Region.pObj_MinTimeToDeact_left != NULL)
      && (pPlusIn->Cfg.TurnOffLeft_OncOnly == 1)
    )
  {
    /* vehicle is moving downwards */
    /* ~CodeReview ~ID:0cc65a253375c4edb05be7daadbf137c ~Reviewer:CW01\uidu4053 ~Date:17.07.2012 ~Priority:3 ~Comment:Replace magic number with parameter */
    if(    (pPlusData->Region.pObj_MinTimeToDeact_left->si16_delta_y_lp > 3.0f)
        && (pPlusData->Region.pObj_MinTimeToDeact_left->s_Status.isVehicleOncoming == 1)
      )
    {
      pTurnOffReason_left->Reason.Bit.TTD = 1;
      pTurnOffReason_left->Cnt.TTD = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }

  /* motorway: */
  /* oncoming or preceding vehicle detected -> turn off left partial HB */
  if(pFData->DecisionOut.Motorway.eStateInt == RTE_HLAF_MTWY_MOTORWAY)
  {
    if(    (pPlusData->Region.RegionOncom_Alive_left.eRegion != HLA_PLUS_NO_OBJ)
        || (pPlusData->Region.RegionPreced_Alive_left.eRegion != HLA_PLUS_NO_OBJ)
      )
    {
      pTurnOffReason_left->Reason.Bit.Motorway = 1;
      pTurnOffReason_left->Cnt.Motorway = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
  /* release motorway flag */
  if(    (pFData->DecisionOut.Motorway.eStateInt != RTE_HLAF_MTWY_MOTORWAY)
      || (    (pPlusData->Region.RegionOncom_left.eRegion == HLA_PLUS_NO_OBJ)
           && (pPlusData->Region.RegionPreced_left.eRegion == HLA_PLUS_NO_OBJ)
         ) 
    )
  {
    pTurnOffReason_left->Reason.Bit.Motorway = 0;
  }


  /**************************************************************************/
  /* left partial HB only not allowed !!!                                   */
  /**************************************************************************/
  pTurnOffReason_left->Reason.Bit.RightOff  = 0;
  pTurnOffReason_right->Reason.Bit.RightOff = 0;
  if(   (pTurnOffReason_right->Reason.u32 > 0)
     && (pPlusIn->Cfg.TurnOffLeft_LeftOnly == 1)
    )
  {
    pTurnOffReason_left->Reason.Bit.RightOff = 1;
    pTurnOffReason_left->Cnt.RightOff = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
}


static boolean HLAPlusTurnOffFull_VehicleWithinHBRegion(const HLA_t_ObjectList               *pObjList,
                                                        const HLAplusObject_t                *pObjListExt,
                                                        const RTE_HLAF_HighBeamState          eHBState,
                                                        const HLAplus2ParHBCharacteristic_t  *pHBCh,
                                                        const float32                        HB_RotAng,
                                                        const float32                        SafetyAng,
                                                        const RTE_HLAF_ObjStatus             eTraffic,
                                                        const float32                        SpotLightWidth_left,
                                                        const float32                        SpotLightWidth_right,
                                                        const HLAFTrafficStyleOut_t          *pTrafficStyle
                                                       )
{
  boolean bVehWithinHBRegion = FALSE;
  float32 HBCutOffAng_left;
  float32 HBCutOffAng_right;
  uint32  i;
  float32 TrafficStyle_NormFactor = pTrafficStyle->NormFactor;


  /* set left and right HB cut off angle */
  switch(eHBState)
  {
    case RTE_HLAF_HB_STATE_OFF:
      HBCutOffAng_left  = HB_RotAng;
      HBCutOffAng_right = HB_RotAng;
      break;
    case RTE_HLAF_HB_STATE_FULL_ON:
      HBCutOffAng_left  = HB_RotAng + pHBCh->FullHBWidth_left;
      HBCutOffAng_right = HB_RotAng - pHBCh->FullHBWidth_right;
      break;
    case RTE_HLAF_HB_STATE_PARTIAL:
      HBCutOffAng_left  = HB_RotAng + pHBCh->PartHBWidth_left;
      HBCutOffAng_right = HB_RotAng - pHBCh->PartHBWidth_right;
      break;
    case RTE_HLAF_HB_STATE_SPOT:
      HBCutOffAng_left  = HB_RotAng + SpotLightWidth_left;
      HBCutOffAng_right = HB_RotAng - SpotLightWidth_right;
      break;
    case RTE_HLAF_HB_STATE_INVALID:
    default:
      HBCutOffAng_left  = HB_RotAng;
      HBCutOffAng_right = HB_RotAng;
      break;
  }

/* ~CodeReview ~ID:1e08c05cd9743cd6cad51b6fdce7d8e2 ~Reviewer:PC2184\jongd ~Date:19-7-2012 ~Priority:2 ~Comment:Check whether pObjList->ui32_NumVehicles <= RTE_HLAR_OBJECT_LIST_LENGTH. (Range checking) */
  /* check if any vehicle is detected within the HB region */  
  for(i=0; i<pObjList->ui32_NumVehicles; i++)
  {
    const HLA_t_Object        *pObj    = &pObjList->as_Object[i];
    const HLAplusObjectData_t *pObjExt = &pObjListExt->Obj[i];

    if(    (    (eTraffic == RTE_HLAF_OBJSTA_ONC_OBJ)
             && (pObj->s_Status.isVehicleOncoming == 1)
             && (pObjExt->Status.isRelevantTraffic == 1)
           )
        || (    (eTraffic == RTE_HLAF_OBJSTA_PREC_OBJ)
             && (pObj->s_Status.isVehicleAhead == 1)
             && (pObjExt->Status.isRelevantTraffic == 1)
           )
      )
    {
      float32 Ang = TrafficStyle_NormFactor * pObj->f32_ObjectHorAng_rad;

      if(    (Ang < (HBCutOffAng_left  + SafetyAng))
          && (Ang > (HBCutOffAng_right - SafetyAng))
        )
      {
        bVehWithinHBRegion = TRUE;
        break;
      }
    }
  }
  return bVehWithinHBRegion;
}

void HLAPlusTurnOffFull( const HLAF_t_RequiredInputs  *ps_In,
                         const HLAplusData_t          *pPlusData,
                         const HLAFPlusOut_t          *pPlusOut,
                         const HLAFTrafficStyleOut_t  *pTrafficStyle,
                         HLAplusTurnOffReasonFullHB_t *pTurnOffReasom_FullHB
                       )
{
  boolean bVehWithinHBRegion_Left;
  boolean bVehWithinHBRegion_Right;


  HLAFDecicionDecTurnKeepOffCnt( &pTurnOffReasom_FullHB->Cnt.OncDetected,
                                 sizeof(pTurnOffReasom_FullHB->Cnt)
                               );

  /**********************************************/
  /* oncoming traffic which deactivates full HB */
  /**********************************************/

  /* check if a oncoming vehicle is within the High Beam region                                 */
  /* if no:  do not turn partial/ full HB off, because the oncoming vehicle will be not blinded */
  /* if yes: turn off partial/ full HB                                                          */
  bVehWithinHBRegion_Left = HLAPlusTurnOffFull_VehicleWithinHBRegion( ps_In->s_Sig.ps_ObjectList,
                                                                      &pPlusData->Object.Left,
                                                                      pPlusOut->eHighBeamState_Lt,
                                                                      &hlafPlusParameter.Left.HBCharacteristic,
                                                                      pPlusOut->RotAngleMin_Lt,
                                                                      CML_Deg2Rad(0.5f), /* SafetyAng */
                                                                      RTE_HLAF_OBJSTA_ONC_OBJ,
                                                                      CML_f_Max(ps_In->s_Par.ps_HlaPar->Headlight.SpotLightWidth, hlafPlusParameter.Left.HBCharacteristic.SpotLightWidth_left),
                                                                      hlafPlusParameter.Left.HBCharacteristic.SpotLightWidth_right,
                                                                      pTrafficStyle
                                                                    );
  bVehWithinHBRegion_Right = HLAPlusTurnOffFull_VehicleWithinHBRegion( ps_In->s_Sig.ps_ObjectList,
                                                                       &pPlusData->Object.Right,
                                                                       pPlusOut->eHighBeamState_Rt,
                                                                       &hlafPlusParameter.Right.HBCharacteristic,
                                                                       pPlusOut->RotAngleMin_Rt,
                                                                       CML_Deg2Rad(0.5f), /* SafetyAng */
                                                                       RTE_HLAF_OBJSTA_ONC_OBJ,
                                                                       hlafPlusParameter.Right.HBCharacteristic.SpotLightWidth_left,
                                                                       hlafPlusParameter.Right.HBCharacteristic.SpotLightWidth_right,
                                                                       pTrafficStyle
                                                                     );
  if(pTurnOffReasom_FullHB->Reason.Bit.OncDetected  == 0)
  {
    if(   /* oncoming vehicle detected */
          (    (pPlusData->Region.RegionOncom_Alive_left.eRegion  != HLA_PLUS_NO_OBJ)
            || (pPlusData->Region.RegionOncom_Alive_right.eRegion != HLA_PLUS_NO_OBJ)
          )
       && (    (bVehWithinHBRegion_Left == TRUE)
            || (bVehWithinHBRegion_Right == TRUE)
          ) 
      )
    {
      pTurnOffReasom_FullHB->Reason.Bit.OncDetected = 1;
      pTurnOffReasom_FullHB->Cnt.OncDetected        = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
  else
  {
    /* reset oncoming present flag when no alive or lost oncoming vehicle is detected anymore */
    if(    (pPlusData->Region.RegionOncom_left.eRegion  == HLA_PLUS_NO_OBJ)
        && (pPlusData->Region.RegionOncom_right.eRegion == HLA_PLUS_NO_OBJ)
      )
    {
      pTurnOffReasom_FullHB->Reason.Bit.OncDetected = 0;
    }
    else
    {
      pTurnOffReasom_FullHB->Cnt.OncDetected        = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
  

  /***********************************************/
  /* preceding traffic which deactivates full HB */
  /***********************************************/
  bVehWithinHBRegion_Left = HLAPlusTurnOffFull_VehicleWithinHBRegion( ps_In->s_Sig.ps_ObjectList,
                                                                      &pPlusData->Object.Left,
                                                                      pPlusOut->eHighBeamState_Lt,
                                                                      &hlafPlusParameter.Left.HBCharacteristic,
                                                                      pPlusOut->RotAngleMin_Lt,
                                                                      CML_Deg2Rad(4.0f), /* SafetyAng */
                                                                      RTE_HLAF_OBJSTA_PREC_OBJ,
                                                                      CML_f_Max(ps_In->s_Par.ps_HlaPar->Headlight.SpotLightWidth, hlafPlusParameter.Left.HBCharacteristic.SpotLightWidth_left),
                                                                      hlafPlusParameter.Left.HBCharacteristic.SpotLightWidth_right,
                                                                      pTrafficStyle
                                                                    );
  bVehWithinHBRegion_Right = HLAPlusTurnOffFull_VehicleWithinHBRegion(  ps_In->s_Sig.ps_ObjectList,
                                                                        &pPlusData->Object.Right,
                                                                        pPlusOut->eHighBeamState_Rt,
                                                                        &hlafPlusParameter.Right.HBCharacteristic,
                                                                        pPlusOut->RotAngleMin_Rt,
                                                                        CML_Deg2Rad(4.0f), /* SafetyAng */
                                                                        RTE_HLAF_OBJSTA_PREC_OBJ,
                                                                        hlafPlusParameter.Right.HBCharacteristic.SpotLightWidth_left,
                                                                        hlafPlusParameter.Right.HBCharacteristic.SpotLightWidth_right,
                                                                        pTrafficStyle
                                                                     );

  if(pTurnOffReasom_FullHB->Reason.Bit.PrecDetected == 0)
  {
    if(   /* preceding vehicle detected */
          (    (pPlusData->Region.RegionPreced_Alive_left.eRegion  != HLA_PLUS_NO_OBJ)
            || (pPlusData->Region.RegionPreced_Alive_right.eRegion != HLA_PLUS_NO_OBJ)
          )
       && (    (bVehWithinHBRegion_Left == TRUE)
            || (bVehWithinHBRegion_Right == TRUE)
          ) 
      )
    {
      pTurnOffReasom_FullHB->Reason.Bit.PrecDetected = 1;
      pTurnOffReasom_FullHB->Cnt.PrecDetected        = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
  else
  {
    /* no alive or preceding vehicle present -> reset flag */
    if (    (pPlusData->Region.RegionPreced_left.eRegion  == HLA_PLUS_NO_OBJ)
         && (pPlusData->Region.RegionPreced_right.eRegion == HLA_PLUS_NO_OBJ)
      )
    {
      pTurnOffReasom_FullHB->Reason.Bit.PrecDetected = 0;
    }
    else
    {
      pTurnOffReasom_FullHB->Cnt.PrecDetected        = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
}
