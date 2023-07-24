/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision.c

  DESCRIPTION:            HLA decision. This module makes some "pre" decisions.
                          The HLAR outputs will be analysed for the hla light,
                          standard and plus function.
                          e.g.:
                          - brightness analysis (dark enough for high beams ?)  
                          - state machine for highway, city, tunnel detection
                          ...

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_decision.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:02CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:45CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:33CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.110 2014/03/26 11:27:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:48 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.109 2014/03/25 19:11:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:50 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.108 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_decision.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_decision.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGE:                 Revision 1.107 2014/03/19 16:30:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:42 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.106 2014/03/05 11:05:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:30 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.105 2014/03/04 16:52:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:19 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.104 2014/03/04 12:59:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for I390 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 12:59:07 PM CET]
  CHANGE:                 Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.103 2014/02/20 08:12:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC critical warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 20, 2014 8:12:54 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.102 2014/02/06 16:01:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:01 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.101 2014/01/16 11:28:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed NVM calibration reset mode
  CHANGE:                 Added headlightstate as mandatory request port
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 16, 2014 11:28:50 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.100 2014/01/10 18:33:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:38 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.99 2013/12/18 15:18:59CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 turn on delays for HighwayOncomingTruckLights
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:59 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.98 2013/10/24 10:44:20CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some not needed variables
  CHANGE:                 Made HLA working on evalboard
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:21 AM CEST]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.97 2013/09/26 11:21:36CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced specific HLA opmodes by TestMode CPar
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:37 AM CEST]
  CHANGE:                 Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.96 2013/08/23 09:26:34CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Switch off the "high beam switch off due to runtime" as it showed to have bad impact on performance
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 23, 2013 9:26:34 AM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_decision.h"
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

static void HLAFDecSetKeepOffReasonSmallRadius( /* input */
                                               const HLAFCameraData_t   *pCamData,
                                               const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                               const HLAFParStdKeepOffSmallRadius_t *pPar,
                                               /* history */
                                               HLAFStdKeepOffSmallRadius_t *pSmallRadius, 
                                               /* output */
                                               HLAFStdKeepOffReason_t *pKeepOffReason
                                               );

static void HLAFDecSetKeepOffReasonMinTimeHBoff( /* input */
                                                const HLAFCameraData_t   *pCamData,
                                                const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                                const HLAFParStdKeepOffMinTimeHBOff_t *pPar,
                                                const HLAFPenaltyTimer_t  *pPenaltyTimer,
                                                /* history */
                                                HLAFStdKeepOffMinTimeHBOff_t *pMinTimeOff, 
                                                /* output */
                                                HLAFStdKeepOffReason_t *pKeepOffReason
                                                );

static void HLAFDecSetKeepOffReasonTurnOnDelay( /* input */
                                                const HLAFData_t                 *pFData,
                                                const RTE_HLAF_HighBeamState      eHighBeamStatePrev,
                                                const HLAFRelevantVehicle_t      *pRelVeh,
                                                const HLAFPenaltyTimer_t         *pPenaltyTimer,
                                                const HLAFParameterTurnOnDelay_t *pPar,
                                                /* history and output */
                                                HLAFStdKeepOffReason_t           *pKeepOffReason
                                              );
                                              
static void HLAFDecSetKeepOffReason_TurnOnDelay_Oncoming_TruckLights( /* input */
                                                                      const HLAF_t_RequiredInputs*  ps_In,
                                                                      const HLAFData_t*             pFData,
                                                                      const RTE_HLAF_HighBeamState  eHighBeamStatePrev,
                                                                      const HLAFPenaltyTimer_t*     pPenaltyTimer,
                                                                      /* history and output */
                                                                            HLAFStdKeepOffReason_t* pKeepOffReason
                                                                    );

static void HLAFDecSetKeepOffPrecedingVehLost( /* input */
                                               const HLAF_t_RequiredInputs    *ps_In,
                                               const HLAFData_t               *pFData,
                                               const HLAFParameterKeepOff_t   *pPar,   
                                               const HLA_t_ObjectList         *pObjectList,
                                               /* History/ output */
                                               HLAFStdKeepOffPrecedingVehicleLost  *pPrecVehLost
                                              );

static void HLAFDecSetKeepOffReasonPotentialVehicle( /* input */
                                                     const HLAF_t_RequiredInputs    *ps_In,
                                                     const HLAFData_t               *pFData,
                                                     const RTE_HLAF_HighBeamState    eHighBeamStatePrev,
                                                     const HLAFParStdKeepOffPotVeh_t   *pPar,
                                                     /* history and output */
                                                     HLAFStdKeepOffReason_t         *pKeepOffReason
                                                   );

static boolean HLAFDecBlockageTurnOffActive(const HLAFTurnOffReasonGlob_t  *pTurnOffReason);

static void HLAFDecSetKeepOffReasonMayBeCity( /* input */
                                             const HLAFData_t *pFData,
                                             const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                             const HLAFStdTurnOffReason_t *pTurnOffReason,
                                             const HLAFRelevantVehicle_t *pRelVeh,
                                             const HLAFParameterKeepOff_t *pParKeepOff,
                                             /* history and output */
                                             HLAFStdKeepOffReason_t *pKeepOffReason
                                            );

/* **************************************************************************** 
  Functionname:     HLAFDecisionBrightness                                */ /*!  
  Description:      


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
/* ~CodeReview ~ID:e9aea798637f01eafed1dde36a452e13 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
void HLAFDecisionBrightness( /* input */
                             const RTE_HLAR_BrightnessState *peStateIn,
                             /* history */
                             /* output */
                             RTE_HLAR_BrightnessState       *peStateOut
                           )
{
  *peStateOut = *peStateIn;
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionSpeed                                     */ /*!  
  Description:      speed analysis


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn, Stefan Zechner
**************************************************************************** */
void HLAFDecisionSpeed( /* input */
                        const HLA_t_MotionState    *pMotionState,
                        const HLA_t_ObjectList     *ps_ObjectList,
                        float32                    dT,
                        float32                    deactivateSpeed,
                        float32                    activateSpeed,
                        float32                    alwaysActiveSpeed,
                        float32                    keepOffVeryLowSpeed,
                        float32                    keepOffLowRadius,
                        float32                    keepOffHighAcceleration,
                        float32                    keepOffAccelTime,
                        float32                    keepOffDelay,
                        /* history / output */
                        HLAFSpeed_t                *pDat
                      )
{
  /* update the speed state */
  if((pMotionState->f32_SpeedDisplay >= alwaysActiveSpeed) &&
     (pMotionState->e_MoveState == HLA_MOVE_STATE_FWD))
  {
    pDat->state = SPEED_STATE_ALWAYSACTIVE;
  }
  else if ((pMotionState->f32_SpeedDisplay >= activateSpeed) &&
           (pMotionState->e_MoveState == HLA_MOVE_STATE_FWD))
  {
    if (pDat->state == SPEED_STATE_LOW)
    {
      /* state transition from state low to high. Set the activate penalty timer */
      if (pDat->keepOffEvents.u8 > 0)
      {
        pDat->activatePenaltyTimer = keepOffDelay;
      }
      else
      {
        pDat->activatePenaltyTimer = 0.0f;
      }
    }
    pDat->state = SPEED_STATE_HIGH;
  }
  else if ((pMotionState->f32_SpeedDisplay <= deactivateSpeed) ||
           (pMotionState->e_MoveState != HLA_MOVE_STATE_FWD))
  {
    pDat->state = SPEED_STATE_LOW;
  }
  else
  {
    /* Do nothing */
  }

  /* trigger the actions depending on the state */
  if (pDat->state == SPEED_STATE_LOW)
  {
    /* set the low speed events */
    if (pMotionState->f32_SpeedDisplay < keepOffVeryLowSpeed)
    {
      pDat->keepOffEvents.Bit.VerySlow = 1;
    }

    if (ps_ObjectList->ui32_NumVehicles > 0)
    {
      pDat->keepOffEvents.Bit.RecentVehicleDetection = 1;
    }
 
    if(    (CML_f_Abs(pMotionState->f32_YawRateRaw) > 0.001f)
        && ((pMotionState->f32_SpeedDisplay / pMotionState->f32_YawRateRaw) < keepOffLowRadius)
      )
    {
      pDat->keepOffEvents.Bit.HighCurvature = 1;
    }

    if(    (pMotionState->f32_SpeedDisplay > 1.0f)
        && (pMotionState->f32_Acceleration > keepOffHighAcceleration)
      )
    {
      pDat->keepOffEvents.Bit.HighAcceleration = 1;
    }

    pDat->disableHLABySpeed = 1;
  }
  else if (pDat->state == SPEED_STATE_HIGH)
  {
    /* decrease timer */
    pDat->activatePenaltyTimer -= dT;
    if (pDat->activatePenaltyTimer < 0)
    {
      /* timer expired -> activate */
      pDat->disableHLABySpeed = 0;
      pDat->keepOffEvents.u8 = 0;
    }
    else
    {
      /* reset timer when acceleration indicates that velocity will fall below activation speed */
      if((pMotionState->f32_SpeedDisplay + (keepOffAccelTime * pMotionState->f32_Acceleration)) < activateSpeed)
      {
        pDat->activatePenaltyTimer = keepOffDelay;
      }
    }
  }
  else
  {
    /* always active state. Reset everything */
    pDat->disableHLABySpeed = 0;
    pDat->keepOffEvents.u8 = 0;
  }

  /* keep high beams off when acceleration indicates that velocity will fall below activation speed */
  if((pMotionState->f32_SpeedDisplay + (keepOffAccelTime * pMotionState->f32_Acceleration)) < activateSpeed)
  {
    pDat->keepOffHLABySpeed = 1;
  }
  else
  {
    pDat->keepOffHLABySpeed = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionPenaltyTimer                             */ /*!  
  Description:      HB on time below 5sec -> increase penalty time +0.5sec
                  
  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionPenaltyTimer(  /* input */
                                const RTE_HLAF_HighBeamState eHBState,
                                const float32                dtime_s,
                                /* history/ output */
                                HLAFPenaltyTimer_t          *pPenalty
                             )
{
  
  if(    (pPenalty->eHBStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (   (eHBState == RTE_HLAF_HB_STATE_FULL_ON)
          || (eHBState == RTE_HLAF_HB_STATE_PARTIAL)
         )
    )
  {
    /* switching HB on */
    /* reset on timer  */
    pPenalty->HBOnTime_s = 0.0f;
  }
  else if(   (eHBState == RTE_HLAF_HB_STATE_FULL_ON)
          || (eHBState == RTE_HLAF_HB_STATE_PARTIAL)
         )
  {
    /* HB on */
    pPenalty->HBOnTime_s += dtime_s;
  }
  else if(    (    (pPenalty->eHBStatePrev == RTE_HLAF_HB_STATE_FULL_ON)
                || (pPenalty->eHBStatePrev == RTE_HLAF_HB_STATE_PARTIAL)
              )
           && (eHBState == RTE_HLAF_HB_STATE_OFF)
         )
  {
    /* switching HB off */
    /* ~CodeReview ~ID:7742269b121815f1b7b7dfa79479496f ~Reviewer:CW01\uidu4053 ~Date:16.07.2012 ~Priority:3 ~Comment:Replace magic number with parameter */
    uint32 i = (uint32)(pPenalty->HBOnTime_s/ 5.0f);
    if(i == 0)
    {
      /* HB on for less than 5sec  */
      /* -> increase Penalty Timer */
      /* ~CodeReview ~ID:e939f67b996d59b2b12ea9b18c543ad1 ~Reviewer:CW01\uidu4053 ~Date:16.07.2012 ~Priority:3 ~Comment:Replace magic number with parameter */
      pPenalty->activatePenaltyTime_s = CML_f_Min(3.0f, (pPenalty->activatePenaltyTime_s + 0.5f));
    }
    else
    {
      /* HB on for more than 5sec */
      /* decrease penalty time: 0.5s per 5sec HB on */
      pPenalty->activatePenaltyTime_s = CML_f_Max(0.0f, (pPenalty->activatePenaltyTime_s - (i * 0.5f)));
    }
  }
  else
  {
    /* Do nothing */
  }

  /* save HB state for next frame */
  pPenalty->eHBStatePrev = eHBState;
}

/* **************************************************************************** 
  Functionname:     HLAFDecisionChangeOverLevel_TurnOff                  */ /*!
  Description:      get change over level when full/partial HB turned off
                    (decreasing light)
                                      
  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
uint8 HLAFDecisionChangeOverLevel_TurnOff( /* input */
                                           const HLA_t_fLightDistance LowBeamDist,
                                           const RTE_HLAF_ObjStatus eTargetDrivingDirection,
                                           const HLAFParStdChangeOverLevel_t *pParChangeOverLevel
                                         )
{
  uint8 ChangeOverLevel;


  /* oncoming traffic detected */
  if(eTargetDrivingDirection == RTE_HLAF_OBJSTA_ONC_OBJ)
  {
    if(LowBeamDist < pParChangeOverLevel->minDist_Onc_TurnOffHigh)
    {
      /* near oncoming traffic */
      ChangeOverLevel = pParChangeOverLevel->TurnOffHigh;  
    }
    else
    {
      /* far oncoming traffic */
      ChangeOverLevel = pParChangeOverLevel->TurnOffMedium;
    }
  }
  /* leading traffic detected ? */
  else if(eTargetDrivingDirection == RTE_HLAF_OBJSTA_PREC_OBJ)
  {
    /* preceding traffic */
    if(LowBeamDist < pParChangeOverLevel->minDist_Prec_TurnOffMedium)
    {
      /* close preceding traffic */
      ChangeOverLevel = pParChangeOverLevel->TurnOffMedium;  
    } 
    else
    { 
      /* far preceding traffic */
      ChangeOverLevel = pParChangeOverLevel->TurnOffLow;
    }
  }
  /* no vehicle detected */
  else
  {
    /* any other turn off reason              */
    /* e.g. city, min speed, brightness, ...  */
    ChangeOverLevel = pParChangeOverLevel->TurnOffLow;
  }

  return(ChangeOverLevel);
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionTurnOnDelayTTB                           */ /*!
  Description:      Get turn on delay based on TTB
                  
  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionTurnOnDelayTTB( /* input */
                                 const HLA_t_Object                   *pObj,
                                 const float32                        Speed,
                                 const RTE_HLAF_MotorwayState         eMotorwayState,
                                 const RTE_HLA_TrafficStyle           eTrafficStyle,
                                 const HLAF_t_RequiredInputs          *pIn,
                                 /* history/ output */
                                 float32                              *pTurnOnDelayOut_s
                               )
{
  /* ~CodeReview ~ID:a05971545dd8b0707c9e3a023ecebb20 ~Reviewer:CW01\uidu4053 ~Date:16.07.2012 ~Priority:3 ~Comment:Replace magic numbers with parameters */
  float32 xw_m          = 0.005f * (float32)(pObj->s_ObjectPos_xw.ui16_distMin_cm + pObj->s_ObjectPos_xw.ui16_distMax_cm);
  float32 yw_m          = 0.01f * pObj->si16_ObjectPos_yw_cm;
  float32 TurnOnDelay_s = 0.0f;

  if(pObj->s_Status.isVehicleAhead == 1)
  {
    /* traffic ahead */
    float32 timegap = xw_m/ CML_f_Max(0.1f, Speed);

    if(timegap < pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingTimeGap_Threshold)
    {
      TurnOnDelay_s = CML_f_Max(timegap, pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingTimeGap);
    }
    else
    {
      /* timegap is larger than PrecedingTimeGap_Threshold 2.0 s */

      /* preceding car with low intensity  (<  75 lx) -> long turn on delay, depending object ttb */
      /*               with high intensity (>= 75 lx) -> short turn on delay */
      /* ~CodeReview ~ID:0840b97901891ec193dd43fd316df93e ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120930 Magic number 75. Consider central definition of this number. */
      if(pObj->ui16_Intensity_lux < 75)
      {
        /* vehicle lost due to low intensity  */
        /* -> take ttb from Object            */
        TurnOnDelay_s = CML_f_MinMax(pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingMaxShort, pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingMaxLong, pObj->ui16_ttb18_ms*0.001f);
      }
      else
      {
        /* vehicle lost with high intensity (e.g. behind bush/ tree) */
        /* -> short turn on delay                                    */
        TurnOnDelay_s = pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingMaxShort;
      }
    }
    /* ~CodeReview ~ID:42ce0829c61ad5ebc4fe3e6c07cfb701 ~Reviewer:PC2357\dijkstg/CW01\uidu4053 ~Date:17-7-2012 ~Priority:3 ~Comment:120930 Magic number 14. Consider central definition of this number. */
    if(pIn->s_Sig.ps_VehicleState->ui8_WiperState >= 14)
    {
      TurnOnDelay_s = CML_f_Max(pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingMinWiperOn, TurnOnDelay_s);
    }
    else
    {
      TurnOnDelay_s = CML_f_Max(pIn->s_Par.s_HlafPar.TurnOnDelay.PrecedingMin, TurnOnDelay_s);
    }
  }
  else 
  {
    /* oncoming traffic */
    if(eMotorwayState == RTE_HLAF_MTWY_MOTORWAY)
    {
      /* on motorway -> use max. TTB for oncomings */
      TurnOnDelay_s = pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMaxHighway;
    }
    else if(    /* right hand traffic */
                (   (eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
                 && (xw_m < pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMin_DistThreshold)
                 && (yw_m > pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMin_LatDistThreshold)
                )
                /* left hand traffic */
             || (   (eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
                 && (xw_m < pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMin_DistThreshold)
                 && (yw_m < -pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMin_LatDistThreshold)
                )
           )
    {
      /* RTE_HLA_TRAFFIC_STYLE_RHD:             */
      /* oncoming passed on left side */
      /* -> fast high beam switch on  */
      TurnOnDelay_s = pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMin;
    }
    else
    {
      /* light belongs to oncoming vehicle or ego vehicle is not moving */
      TurnOnDelay_s = CML_f_Min(pObj->ui16_ttb18_ms*0.001f, pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMax);
    }
    TurnOnDelay_s = CML_f_Max(pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMin, TurnOnDelay_s);
  }

  *pTurnOnDelayOut_s = TurnOnDelay_s;
}

/* **************************************************************************** 
  Functionname:     HLAFDecisionRelevantVehicle2TurnOff                          */ /*!
  Description:      relevant traffic detected to turn off the HBs 
                  
  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
boolean HLAFDecisionRelevantVehicle2TurnOff( /* input */
                                             const RTE_HLAF_HighBeamState eHBState,
                                             const HLA_t_Object *pObj,
                                             const HLAFData_t *pFData,
                                             const RTE_HLAF_ParameterTurnOff_t *pParTurnOff,
                                             /* ROI */
                                             const HLA_t_ObjectRoi *pROI,
                                             /* Region of interest for relevant traffic              */
                                             /* vehicles within this region will be relevant traffic */
                                             /* - independent of TTB and object angle                */
                                             /* - region only used for partial HB and spot light     */   
                                             const float32 RoiAngLeft,
                                             const float32 RoiAngRight
                                           )
{
  boolean bRelevantVeh = b_FALSE;
  
  /* vehicle detected ? */
  if(   (pObj->s_Status.isVehicleAhead == 1)
     || (pObj->s_Status.isVehicleOncoming == 1)
    )
  {
    if(eHBState == RTE_HLAF_HB_STATE_OFF)
    {
      /* HB state off */
      if(   /* object within HLA ROI ? */
             (pObj->si16_xcenter > pROI->ui16_RoiX1)
          && (pObj->si16_xcenter < pROI->ui16_RoiX2)
          && (pObj->si16_ycenter < pROI->ui16_RoiY2)
          && (pObj->si16_ycenter > pROI->ui16_RoiYu)
        )
      {
        bRelevantVeh = b_TRUE;  
      } 
      else
      {
        bRelevantVeh = b_FALSE; 
      }
    } 
    else if(   /* object within HLA function ROI ? */
               (pObj->si16_xcenter > pROI->ui16_RoiX1)
            && (pObj->si16_xcenter < pROI->ui16_RoiX2)
            && (pObj->si16_ycenter < pROI->ui16_RoiY2)
            && (pObj->si16_ycenter > pROI->ui16_RoiYu)
            && (   (   (eHBState == RTE_HLAF_HB_STATE_FULL_ON)
                    && (pObj->ui8_lost_time == 0)
                   )
                || (eHBState == RTE_HLAF_HB_STATE_PARTIAL)
                || (eHBState == RTE_HLAF_HB_STATE_SPOT)
               )
           )
    {
      if(pFData->DecisionOut.Motorway.eStateInt == RTE_HLAF_MTWY_MOTORWAY)
      {
        /* highway */

        /* normalized object angle */  
        float32 ObjectHorAng_norm = pFData->DecisionOut.TrafficStyle.NormFactor * pObj->f32_ObjectHorAng_rad;

        if(ObjectHorAng_norm > 0.0f)
        {
          /* vehicle on the left side */
          bRelevantVeh = b_TRUE;
        }
        else
        {
          /* vehicle on the right side */
          if(    ((pObj->ui16_ttb18_ms*0.001f) > pParTurnOff->TTBThreshold)
              && (ObjectHorAng_norm > (-pParTurnOff->HorAngThreshold))
            )
          {
            bRelevantVeh = b_TRUE;
          }
          /* within region of interest ? */
          else if(    (ObjectHorAng_norm < RoiAngLeft)
                   && (ObjectHorAng_norm > RoiAngRight)
                 )
          {
            bRelevantVeh = b_TRUE;
          }
          else
          {
            /* Do nothing */
          }
        }
      }
      else
      {
        /* country road */
        /* ~CodeReview ~ID:a8b976e4cb14014b2d7bf4ff5d2cc9e6 ~Reviewer:PC2357\dijkstg/CW01\uidu4053 ~Date:17-7-2012 ~Priority:3 ~Comment:120930 Magic number 120.0f. Consider central definition of this number. */
        if(pFData->CamData.radiusAbs_m < 120.0f)
        {
          /* small radius */
          bRelevantVeh = b_TRUE;
        }
        /* vehicle moves fast into FOV            */
        /* overtaking car of oncoming in a curve  */
        else if(   /* left side */
                   (   (pObj->f32_ObjectHorAng_rad > 0.0f)
                    && (pObj->si16_delta_x > 3)
                   )
                   /* right side */
                || (   (pObj->f32_ObjectHorAng_rad < 0.0f)
                    && (pObj->si16_delta_x < -3)
                   )
               )
        {
          /* fast moving vehicle into FOV */
          bRelevantVeh = b_TRUE;
        }
        else if(    (CML_f_Abs(pObj->f32_ObjectHorAng_rad) < pParTurnOff->HorAngThreshold)
                 && (((float32)(pObj->ui16_ttb18_ms) * 0.001f) > pParTurnOff->TTBThreshold)
               )
        {
          bRelevantVeh = b_TRUE;
        }
        else if(    /* within region of interest ? */
                    (pObj->f32_ObjectHorAng_rad < RoiAngLeft)
                 && (pObj->f32_ObjectHorAng_rad > RoiAngRight)
               )
        {
          bRelevantVeh = b_TRUE;
        }
        else
        {
          bRelevantVeh = b_FALSE;
        }
      }
    }
    else
    {
      bRelevantVeh = b_FALSE;
    }
  }
  else
  {
    bRelevantVeh = b_FALSE;
  }
    
  return(bRelevantVeh);
}

static boolean HLAFDecBlockageTurnOffActive(const HLAFTurnOffReasonGlob_t  *pTurnOffReason)
{
  /* local variables */
  boolean b_TurnOffActive;

  /* Check for active turn offs */
  if (  (pTurnOffReason->Reason.Bit.Brightness == 1)
    ||(pTurnOffReason->Reason.Bit.City == 1)
    ||(pTurnOffReason->Reason.Bit.MinSpeed == 1)
    ||(pTurnOffReason->Reason.Bit.NotActive == 1)
    ||(pTurnOffReason->Reason.Bit.NotAvl == 1) )
  {
    b_TurnOffActive = b_TRUE;
  }
  else 
  {
    b_TurnOffActive = b_FALSE;
  }
  return (b_TurnOffActive);
}
      
/* **************************************************************************** 
  Functionname:     HLAFDecisionBlockage                                 */ /*!  
  Description:      Blockage detection


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Alexander Kaps
**************************************************************************** */
void HLAFDecisionBlockage( /* input */
                           const HLAF_t_Blockage          *pBlockageIn,
                           const HLAFParameterBlockage_t  *pPar,
                           const HLAFCameraData_t         *pCamData,
                           const HLAFTurnOffReasonGlob_t  *pTurnOffReason,
                           const RTE_HLA_State            IHCActivationState,
                           /* history */
                           HLAFBlockage_t                 *pData,
                           /* output */
                           HLA_t_Blockage                 *pBlockageOut,
                           HLA_t_SystemInfo               *ps_SystemInfo
                         )
{
  /* set signal state */
  pBlockageOut->e_SigStatus = AL_SIG_STATE_OK;

  /* blockage state machine */
  switch(pData->eBlockageState)
  {

  case HLAF_BLOCKAGE_INIT:
    /* set output */
    pBlockageOut->b_Blockage = FALSE;
    pBlockageOut->b_ClearanceMeasurement = FALSE;
    pBlockageOut->b_Condensation = FALSE;
    pBlockageOut->b_ManualOverride = FALSE;
    /* Init counters & variables */
    pData->DistTraveled = 0.f;
    pData->TimeElapsed = 0.f;
    pData->MinDistDriven = 0.f;
    pData->BlockageDist = 0.f;
    pData->BlockageTime = 0.f;
    pData->ToggleCountDown = pPar->ToggleThresh + 1.0f; /* all values larger than pPar->ToggleThresh signal "Countdown not engaged" */
    pData->IHCStateOld = IHCActivationState;
    /* state transition(s) */
    /* HLAF_BLOCKAGE_INIT -> HLAF_BLOCKAGE_CLEAR_MEAS */
    pData->eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;
    break;

  case HLAF_BLOCKAGE_CLEAR_MEAS:
    /* set output */
    pBlockageOut->b_Blockage = FALSE;
    pBlockageOut->b_ClearanceMeasurement = FALSE;
    pBlockageOut->b_Condensation = FALSE;
    pBlockageOut->b_ManualOverride = FALSE;
    /* state transition(s) */
    /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_NO_BLOCKAGE */
    if (  (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_NO_BLOCKAGE)
        &&(pData->MinDistDriven >= pPar->MinDistDrivenThresh) )
    {
      pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_BLOCKAGE */
    else if (  (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_BLOCKAGE)
             ||(  (pData->DistTraveled > pPar->DistThresh)
                &&(pData->TimeElapsed > pPar->TimeThresh) 
                ) 
             )
    {
      /* check for turn off reason -> no blockage when turn off reason present */
      if (HLAFDecBlockageTurnOffActive(pTurnOffReason) == b_FALSE)
      {
        /* Check if thresholds for time and distance while blocked are reached */
        if (  (pData->BlockageDist > pPar->MinDistBlockedThresh)
            &&(pData->BlockageTime > pPar->MinTimeBlockedThresh) )
        {
          pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
          /* Reset blockage counters */
          pData->BlockageDist = 0.f;
          pData->BlockageTime = 0.f;
        }
        else
        {
          /* Update counters */
          pData->BlockageDist = pData->BlockageDist + pCamData->ddistFwd_m;
          pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
        }
      }
      else
      {
        /* Reset blockage counters */
        pData->BlockageDist = 0.f;
        pData->BlockageTime = 0.f;
      }
    }
    /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_CONDENSATION */
    else if (  (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_CONDENSATION)
             &&(pData->MinDistDriven >= pPar->MinDistDrivenThresh) )
    {
      pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }  
    /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_MAN_OVERRIDE */
    else if (  (pData->IHCStateOld == RTE_HLA_STATE_IDLE)
             &&(IHCActivationState == RTE_HLA_STATE_ACTV)
             &&(pData->ToggleCountDown <= pPar->ToggleThresh) )
    {
      pData->eBlockageState = HLAF_BLOCKAGE_MAN_OVERRIDE;
      /* Reset manual override counters */
      pData->DistTraveled = 0.f;
      pData->TimeElapsed = 0.f;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    else 
    { 
      /* check for turn off reason */
      if (HLAFDecBlockageTurnOffActive(pTurnOffReason) == b_FALSE)
      {
        /* no turn off reason */
        pData->TimeElapsed = pData->TimeElapsed + pCamData->dtimeFwd_s;
        pData->DistTraveled = pData->DistTraveled + pCamData->ddistFwd_m;
      }
      else { /* do nothing */ }
      /* Manual override maneuver processing */
      if (pData->ToggleCountDown > pPar->ToggleThresh)
      {
        /* Countdown not engaged -> check for IHCAcitvationState change */
        if (  (pData->IHCStateOld == RTE_HLA_STATE_ACTV)
            &&(IHCActivationState == RTE_HLA_STATE_IDLE) )
        {
          pData->ToggleCountDown = pPar->ToggleThresh;
        }
        else { /* do nothing */ }
      }      
      else if (pData->ToggleCountDown >= 0.f)
      {
        /* Countdown engaged and not elapsed -> update remaining time for IHC reactivation */
        pData->ToggleCountDown = pData->ToggleCountDown - pCamData->dtimeFwd_s;
      }
      else
      {
        /* Countdown elapsed -> reset countdown */
        pData->ToggleCountDown = pPar->ToggleThresh + 1.0f;
      }
      /* Store current activation state for next cycle */
      pData->IHCStateOld = IHCActivationState;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    /* Estimate distance driven */
    pData->MinDistDriven = pData->MinDistDriven + pCamData->ddistFwd_m;
    break;

  case HLAF_BLOCKAGE_MAN_OVERRIDE:
    /* set output */
    pBlockageOut->b_Blockage = FALSE;
    pBlockageOut->b_ClearanceMeasurement = TRUE;
    pBlockageOut->b_Condensation = FALSE;
    pBlockageOut->b_ManualOverride = TRUE;
    /* state transition(s) */
    /* HLAF_BLOCKAGE_MAN_OVERRIDE -> HLAF_BLOCKAGE_NO_BLOCKAGE */
    if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_NO_BLOCKAGE)
    {
      pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    /* HLAF_BLOCKAGE_MAN_OVERRIDE -> HLAF_BLOCKAGE_BLOCKAGE */
    else if (  (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_BLOCKAGE)
             ||(  (pData->DistTraveled > pPar->DistThresh)
                &&(pData->TimeElapsed > pPar->TimeThresh) 
                ) 
             )
    {
      /* check for turn off reason -> no blockage when turn off reason present */
      if (HLAFDecBlockageTurnOffActive(pTurnOffReason) == b_FALSE)
      {
        /* Check if thresholds for time and distance while blocked are reached */
        if (  (pData->BlockageDist > pPar->MinDistBlockedThresh)
            &&(pData->BlockageTime > pPar->MinTimeBlockedThresh) )
        {
          pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
          /* Reset blockage counters */
          pData->BlockageDist = 0.f;
          pData->BlockageTime = 0.f;
        }
        else
        {
          /* Update counters */
          pData->BlockageDist = pData->BlockageDist + pCamData->ddistFwd_m;
          pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
        }
      }
      else
      {
        /* Reset blockage counters */
        pData->BlockageDist = 0.f;
        pData->BlockageTime = 0.f;
      }
    }
    /* HLAF_BLOCKAGE_MAN_OVERRIDE -> HLAF_BLOCKAGE_CONDENSATION */
    else if (  (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_CONDENSATION)
             &&(pData->MinDistDriven >= pPar->MinDistDrivenThresh) )
    {
      pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    else 
    {
      /* check for turn off reason */
      if (HLAFDecBlockageTurnOffActive(pTurnOffReason) == b_FALSE)
      {
        /* no turn off reason */
        pData->TimeElapsed = pData->TimeElapsed + pCamData->dtimeFwd_s;
        pData->DistTraveled = pData->DistTraveled + pCamData->ddistFwd_m;
      }
      else { /* do nothing */ }      
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    /* Estimate distance driven */
    pData->MinDistDriven = pData->MinDistDriven + pCamData->ddistFwd_m;
    break;

  case HLAF_BLOCKAGE_NO_BLOCKAGE:
    /* set output */
    pBlockageOut->b_Blockage = FALSE;
    pBlockageOut->b_ClearanceMeasurement = TRUE;
    pBlockageOut->b_Condensation = FALSE;
    pBlockageOut->b_ManualOverride = FALSE;
    /* state transition(s) */
    /* HLAF_BLOCKAGE_NO_BLOCKAGE -> HLAF_BLOCKAGE_BLOCKAGE */
    if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_BLOCKAGE)
    {
      /* check for turn off reason -> no blockage when turn off reason present */
      if (HLAFDecBlockageTurnOffActive(pTurnOffReason) == b_FALSE)
      {
        /* Check if thresholds for time and distance while blocked are reached */
        if (  (pData->BlockageDist > pPar->MinDistBlockedThresh)
            &&(pData->BlockageTime > pPar->MinTimeBlockedThresh) )
        {
          pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
          /* Reset blockage counters */
          pData->BlockageDist = 0.f;
          pData->BlockageTime = 0.f;
        }
        else
        {
          /* Update counters */
          pData->BlockageDist = pData->BlockageDist + pCamData->ddistFwd_m;
          pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
        }
      }
      else
      {
        /* Reset blockage counters */
        pData->BlockageDist = 0.f;
        pData->BlockageTime = 0.f;
      }
    }
    /* HLAF_BLOCKAGE_NO_BLOCKAGE -> HLAF_BLOCKAGE_CONDENSATION */
    else if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_CONDENSATION)
    {
      pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    else { /* Remain in HLAF_BLOCKAGE_NO_BLOCKAGE */ }
    break;

  case HLAF_BLOCKAGE_BLOCKAGE:
    /* set output */
    pBlockageOut->b_Blockage = TRUE;
    pBlockageOut->b_ClearanceMeasurement = TRUE;
    pBlockageOut->b_Condensation = FALSE;
    pBlockageOut->b_ManualOverride = FALSE;
    /* state transition(s) */
    /* HLAF_BLOCKAGE_BLOCKAGE -> HLAF_BLOCKAGE_NO_BLOCKAGE */
    if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_NO_BLOCKAGE)
    {
      /* check for turn off reason -> min speed turn off reason must not be active */
      if (pTurnOffReason->Reason.Bit.MinSpeed == 0)
      {
        /* Check if thresholds for time while unblocked is reached */
        if (pData->BlockageTime > pPar->MinTimeUnblockedThresh)
        {
          pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
          /* Reset blockage counter */
          pData->BlockageTime = 0.f;
        }
        else
        {
          /* Update counter */
          pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
        }
      }
      else { /* do nothing */ }
    }
    /* HLAF_BLOCKAGE_BLOCKAGE -> HLAF_BLOCKAGE_CONDENSATION */
    else if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_CONDENSATION)
    {
      /* check for turn off reason -> min speed turn off reason must not be active */
      if (pTurnOffReason->Reason.Bit.MinSpeed == 0)
      {
        /* Check if thresholds for time while unblocked is reached */
        if (pData->BlockageTime > pPar->MinTimeUnblockedThresh)
        {
          pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
          /* Reset blockage counter */
          pData->BlockageTime = 0.f;
        }
        else
        {
          /* Update counter */
          pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
        }
      }
      else { /* do nothing */ }
    }
    else
     {
      /* Reset blockage counter */
      pData->BlockageTime = 0.f;
    }        
    break;

  case HLAF_BLOCKAGE_CONDENSATION:
    /* set output */
    pBlockageOut->b_Blockage = FALSE;
    pBlockageOut->b_ClearanceMeasurement = TRUE;
    pBlockageOut->b_Condensation = TRUE;
    pBlockageOut->b_ManualOverride = FALSE;
    /* state transition(s) */
    /* HLAF_BLOCKAGE_CONDENSATION -> HLAF_BLOCKAGE_NO_BLOCKAGE */
    if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_NO_BLOCKAGE)
    {
      pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
      /* Reset blockage counters */
      pData->BlockageDist = 0.f;
      pData->BlockageTime = 0.f;
    }
    /* HLAF_BLOCKAGE_CONDENSATION -> HLAF_BLOCKAGE_BLOCKAGE */
    else if (pBlockageIn->e_BlockageStatus == HLAF_BLOCKAGE_STATUS_BLOCKAGE)
    {
      /* check for turn off reason -> no blockage when turn off reason present */
      if (HLAFDecBlockageTurnOffActive(pTurnOffReason) == b_FALSE)
      {
        /* Check if thresholds for time and distance while blocked are reached */
        if (  (pData->BlockageDist > pPar->MinDistBlockedThresh)
            &&(pData->BlockageTime > pPar->MinTimeBlockedThresh) )
        {
          pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
          /* Reset blockage counters */
          pData->BlockageDist = 0.f;
          pData->BlockageTime = 0.f;
        }
        else
        {
          /* Update counters */
          pData->BlockageDist = pData->BlockageDist + pCamData->ddistFwd_m;
          pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
        }
      }
      else
      {
        /* Reset blockage counters */
        pData->BlockageDist = 0.f;
        pData->BlockageTime = 0.f;
      }
    }
    else { /* Remain in HLAF_BLOCKAGE_CONDENSATION */ }
    break;

  case HLAF_BLOCKAGE_LAST: 
  default:
      break;
  }

  /* blockage detected ? */
  /* -> set error        */
  if(pBlockageOut->b_Blockage == TRUE)
  {  
    ps_SystemInfo->errors.error[HLA_ERRORID_BLOCKAGE].status = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_BLOCKAGE].optData = 0;
  }
  else
  {
    ps_SystemInfo->errors.error[HLA_ERRORID_BLOCKAGE].status = HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED;
    ps_SystemInfo->errors.error[HLA_ERRORID_BLOCKAGE].optData = 0;
  }
  /* <ln_offset+1 PCLINT Error 715: reviewer name: Marcus Brunn date: 2011-10-04 reason: Interface is agreed to provide more than is needed */
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionWeather                                  */ /*!  
  Description:      Weather detection


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn, Tobias Schwarz
**************************************************************************** */
void HLAFDecisionWeather(  /* input */
                           const HLAF_t_Blockage* pBlockageIn, 
                           /* history */
                           HLAFWeather_t*         pData,
                           /* output */
                           RTE_HLAR_WeatherState* peWeatherStateOut
                         )
{
  if(pBlockageIn->e_BlockageWeather == HLAF_BLOCKAGE_WEATHER_FOG)
  {
    switch(pBlockageIn->e_BlockageVisibility)
    {
      case HLAF_BLOCKAGE_VISIBILITY_UNKNOWN:
        *peWeatherStateOut = RTE_HLAR_WEATHER_UNKNOWN;
        break;

      case HLAF_BLOCKAGE_VISIBILITY_CLEAR:
        *peWeatherStateOut = RTE_HLAR_WEATHER_GOOD;
        break;

      case HLAF_BLOCKAGE_VISIBILITY_HIGH:
        *peWeatherStateOut = RTE_HLAR_WEATHER_LIGHT_FOG;
        break;

      case HLAF_BLOCKAGE_VISIBILITY_MEDIUM:
        *peWeatherStateOut = RTE_HLAR_WEATHER_MEDIUM_FOG;
        break;

      case HLAF_BLOCKAGE_VISIBILITY_LOW:
        *peWeatherStateOut = RTE_HLAR_WEATHER_HEAVY_FOG;
        break;
      
      case HLAF_BLOCKAGE_VISIBILITY_INVALID:
      /* use HLAF_BLOCKAGE_VISIBILITY_INVALID as default */
      default:
        *peWeatherStateOut = RTE_HLAR_WEATHER_INVALID;
        break;
    }
  }
  else
  {
    *peWeatherStateOut = RTE_HLAR_WEATHER_GOOD;
  }
  
  pData->dummy = 0;
  /* <ln_offset+1 PCLINT Error 715: reviewer name: Marcus Brunn date: 2011-10-04 reason: Interface is agreed to provide more than is needed */
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionCity                                     */ /*!  
  Description:      City detection


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionCity( /* input */
                       const RTE_HLAR_CityState         eCity,
                       const float32                    dTurnOnDelay,
                       const HLAFParameterCity_t*       pPar,
                       const RTE_HLAR_BrightnessState   e_Brightness,
                       /* history */
                       HLAFData_t*                      pFData,
                       /* output */
                       RTE_HLAR_CityState*              peCityOut
                       )
{
  
  switch(pFData->DecisionData.City.eCityState) /* internal city state */
  {
    case HLAF_CITY_IDLE:
      /* idle */
      /* reset city time and distance */
      pFData->DecisionData.City.timeInCity_s = 0.0f;
      pFData->DecisionData.City.distInCity_m = 0.0f;
      pFData->DecisionData.City.distOutCity_m = 0.0f;

      if(    (eCity == RTE_HLAR_CITY_DTCD)
          && (e_Brightness >= RTE_HLAR_BRT_TWLGT_3)
        )
      {
        /* city detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_DETECTED;
        
      }    
      else if(    (eCity == RTE_HLAR_CITY_MAYBE)
               && (e_Brightness >= RTE_HLAR_BRT_TWLGT_3)
             )
      {
        /* maybe city detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_MAYBE;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLAF_CITY_MAYBE:
      /* increment time and distance */
      pFData->DecisionData.City.timeInCity_s += pFData->CamData.dtimeFwd_s;
      pFData->DecisionData.City.distInCity_m += pFData->CamData.ddistFwd_m;

      if(    (eCity == RTE_HLAR_CITY_DTCD)
          && (e_Brightness >= RTE_HLAR_BRT_TWLGT_3)
        )
      {
        /* city detected */
        pFData->DecisionData.City.eCityState = HLAF_CITY_DETECTED;

        /* reset city time and distance */
        pFData->DecisionData.City.timeInCity_s = 0.0f;
        pFData->DecisionData.City.distInCity_m = 0.0f;
        pFData->DecisionData.City.distOutCity_m = 0.0f;
      }
      else if(eCity == RTE_HLAR_CITY_MAYBE)
      {
        /* stay only for maxMayBeCityDist_m in MayBeCity        */
        if(pFData->DecisionData.City.distInCity_m > pPar->maxMayBeCityDist_m)
        {
          /* leave maybe city */
          pFData->DecisionData.City.eCityState = HLAF_CITY_MAYBE_WAIT4IDLE;
        }
      }
      else if(      (eCity == RTE_HLAR_CITY_NOT_DTCD)
                 && (pFData->DecisionData.City.timeInCity_s > pPar->minMayBeCityTime_s)
                 && (pFData->DecisionData.City.distInCity_m > pPar->minMayBeCityDist_m)
                 && (    (e_Brightness >= RTE_HLAR_BRT_TWLGT_3)
                      || (   (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
                          && (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.MinSpeed == 0)
                         )
                    )
             )
      {
        /* city not detected */
        /* leave maybe city  */
        pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLAF_CITY_MAYBE_WAIT4IDLE:
      /* stayed to long in maybe city         */
      /* or HB switched on during maybe city  */
      /* -> wait for HLAR City idle           */
      if(    (eCity == RTE_HLAR_CITY_NOT_DTCD)
          || (eCity == RTE_HLAR_CITY_DTCD)
        )
      {
        pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
      }
      break;

    case HLAF_CITY_DETECTED:
      /* city detected */

      /* leave city state ? */
      if(      (eCity == RTE_HLAR_CITY_NOT_DTCD)
            && (pFData->DecisionData.City.timeInCity_s  > pPar->minCityTime_s)
            && (pFData->DecisionData.City.distInCity_m  > pPar->minCityDist_m)
            && (    (e_Brightness >= RTE_HLAR_BRT_TWLGT_3)
                 || (   (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
                     && (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.MinSpeed == 0)
                    )
               )
        )
      { 
        /* are we already far enough from city? */
        if (pFData->DecisionData.City.distOutCity_m >= dTurnOnDelay)
        {
          /* city not detected */
          pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE; 
        }
        pFData->DecisionData.City.distOutCity_m += pFData->CamData.ddistFwd_m;
      } 
      else
      {
        /* reset out_of_city_counter as we are back in city again */
        pFData->DecisionData.City.distOutCity_m = 0.0f;
      }

      /* increment time and distance for in_city_counters */
      pFData->DecisionData.City.timeInCity_s  += pFData->CamData.dtimeFwd_s;
      pFData->DecisionData.City.distInCity_m  += pFData->CamData.ddistFwd_m;
      break;

    case HLAF_CITY_LAST:
    default:
      pFData->DecisionData.City.eCityState = HLAF_CITY_IDLE;
      break;
  }
  

  /* set output data */
  switch(pFData->DecisionData.City.eCityState)
  {
    case HLAF_CITY_MAYBE:
      *peCityOut = RTE_HLAR_CITY_MAYBE;
      break;

    case HLAF_CITY_DETECTED:
      *peCityOut = RTE_HLAR_CITY_DTCD;
      break;

    case HLAF_CITY_LAST:
    case HLAF_CITY_IDLE:
    case HLAF_CITY_MAYBE_WAIT4IDLE:
    default:
      *peCityOut = RTE_HLAR_CITY_NOT_DTCD;
      break;
  }
}

/* **************************************************************************** 
  Functionname:     HLAFDecisionTunnel                                    */ /*!  
  Description:      Tunnel detection


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Matthias Mutschler
**************************************************************************** */
void HLAFDecisionTunnel( /* input */
                         const RTE_HLAR_Tunnel   eTunnel,
                         const float32           dTurnOnDelay,
                         /* history */
                         HLAFData_t*             pFData,
                         /* output */
                         RTE_HLAR_Tunnel*        peTunnelOut
                         )
{
  
  switch(pFData->DecisionData.Tunnel.eTunnelState) /* internal tunnel state */
  {
    case HLAF_TUNNEL_IDLE:
      /* idle */
      if(eTunnel == RTE_HLAR_TUNNEL_INSIDE)
      {
        /* tunnel detected */
        pFData->DecisionData.Tunnel.eTunnelState = HLAF_TUNNEL_DETECTED;
      }    
      else if(eTunnel == RTE_HLAR_TUNNEL_UPFRONT)
      {
        /* tunnel upfront detected */
        pFData->DecisionData.Tunnel.eTunnelState = HLAF_TUNNEL_UPFRONT;
      }
      else
      {
        /* Do nothing */
      }
      /* reset tunnel distance */
      pFData->DecisionData.Tunnel.distOutTunnel_m = 0.0f;

      break;

    case HLAF_TUNNEL_UPFRONT:
       /* idle */
      if(eTunnel == RTE_HLAR_TUNNEL_INSIDE)
      {
        /* tunnel detected */
        pFData->DecisionData.Tunnel.eTunnelState = HLAF_TUNNEL_DETECTED;
      }    
      else if(    (eTunnel == RTE_HLAR_TUNNEL_NOT_DTCD)
               || (eTunnel == RTE_HLAR_TUNNEL_UNKNOWN)
              )
      {
        /* back to idle state*/
        pFData->DecisionData.Tunnel.eTunnelState = HLAF_TUNNEL_IDLE;
      }
      else
      {
        /* Do nothing */
      }
      /* reset tunnel distance */
      pFData->DecisionData.Tunnel.distOutTunnel_m = 0.0f;

      break;

    case HLAF_TUNNEL_DETECTED:
      if(    (eTunnel == RTE_HLAR_TUNNEL_NOT_DTCD)
          || (eTunnel == RTE_HLAR_TUNNEL_UNKNOWN)
          || (eTunnel == RTE_HLAR_TUNNEL_UPFRONT)
         )
      {
        if (pFData->DecisionData.Tunnel.distOutTunnel_m >= dTurnOnDelay)
        {
          /* back to idle state */
          pFData->DecisionData.Tunnel.eTunnelState = HLAF_TUNNEL_IDLE;
        }
        /* increment distance */
        pFData->DecisionData.Tunnel.distOutTunnel_m += pFData->CamData.ddistFwd_m;
      }
      else 
      {
        /* reset tunnel distance as we are back in tunnel */
        pFData->DecisionData.Tunnel.distOutTunnel_m = 0.0f;
      }
      break;

    case HLAF_TUNNEL_LAST:
    default:
      pFData->DecisionData.Tunnel.eTunnelState = HLAF_TUNNEL_IDLE;
      break;
  }
  

  /* set output data */
  switch(pFData->DecisionData.Tunnel.eTunnelState)
  {
    case HLAF_TUNNEL_DETECTED:
      *peTunnelOut = RTE_HLAR_TUNNEL_INSIDE;
      break;

    case HLAF_TUNNEL_LAST:
    case HLAF_TUNNEL_UPFRONT:
    case HLAF_TUNNEL_IDLE:
    default:
      *peTunnelOut = RTE_HLAR_TUNNEL_NOT_DTCD;
      break;
  }
}

/* **************************************************************************** 
  Functionname:     HLAFDecisionHighway                                  */ /*!  
  Description:      Highway detection


  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionHighway( /* input */
                          const boolean                   bInternal, /* only internally used by HLAF */
                          const HLA_t_Highway             *pHighwayIn,   
                          const HLAFParameterHighway_t    *pPar,
                          const HLAFData_t                *pFData,
                          const RTE_HLAR_BrightnessState  e_Brightness,
                          /* output */
                          RTE_HLAF_MotorwayState          *peHighwayOut
                        )
{

  switch(*peHighwayOut)
  {
    case RTE_HLAF_MTWY_UNKNOWN:
      /* idle state */
      if(e_Brightness < RTE_HLAR_BRT_TWLGT_3)
      {
        /* too bright */
        *peHighwayOut = RTE_HLAF_MTWY_UNKNOWN;
      }
      else if( pHighwayIn->e_SpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD) /* Detection over speed only */
      {
          *peHighwayOut = RTE_HLAF_MTWY_MOTORWAY;
      }
      else if(   (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) /* motion, high speed */
              || (pHighwayIn->e_LateralPosition    == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)     /* high distance between own and oncoming lane */
              || (pHighwayIn->e_OcclusionDetection == RTE_HLAR_HIGHWAY_OC_NOT_DTCD)     /* occlusion detected */
             )
      {
        *peHighwayOut = RTE_HLAF_MTWY_COUNTRY;  
      }
      else if(   (    (pHighwayIn->e_LateralPosition      == RTE_HLAR_HIGHWAY_LP_DTCD)      /* high distance between own and oncoming lane */
                   && (pHighwayIn->f32_ConfLatPos >= pPar->minConf)
                   && (pHighwayIn->e_EgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)       /* motion, high speed */
                 )
              || (    (pHighwayIn->e_OcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD)        /* occlusion detected */
                   && (pHighwayIn->f32_ConfOcclDtction     >= pPar->minConf)
                   && (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_DTCD)     /* motion, high speed */
                 )
             )
      {
        *peHighwayOut = RTE_HLAF_MTWY_MOTORWAY;  
      }
      else
      {
        *peHighwayOut = RTE_HLAF_MTWY_UNKNOWN;  
      }
      break;     

    case RTE_HLAF_MTWY_COUNTRY:
      /* country road detected */
      if(    (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
          && (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.MinSpeed   == 0)
        )
      {
        /* too bright and vehicle speed above activation speed */
        *peHighwayOut = RTE_HLAF_MTWY_UNKNOWN;
      }
      else if( pHighwayIn->e_SpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD) /* Detection over speed only */
      {
          *peHighwayOut = RTE_HLAF_MTWY_MOTORWAY;
      }
      else if(    (    (pHighwayIn->e_LateralPosition  == RTE_HLAR_HIGHWAY_LP_DTCD)      /* high distance between own and oncoming lane */
                    && (pHighwayIn->f32_ConfLatPos >= pPar->minConf)
                    && (pHighwayIn->e_EgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)   /* motion, high speed */
                    && (e_Brightness >= RTE_HLAR_BRT_TWLGT_3) 
                  )
               || (    (pHighwayIn->e_OcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD)    /* occlusion detected */
                    && (pHighwayIn->f32_ConfOcclDtction     >= pPar->minConf)
                    && (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_DTCD) /* motion, high speed */
                    && (e_Brightness >= RTE_HLAR_BRT_TWLGT_3)
                  )
             )
      {
        /* highway detected */
        *peHighwayOut = RTE_HLAF_MTWY_MOTORWAY;  
      }
      else
      {
        /* stay in country road */
        *peHighwayOut = RTE_HLAF_MTWY_COUNTRY;  
      }
      break;
    
    case RTE_HLAF_MTWY_MOTORWAY:
      /* highway detected */
      if(    (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
          && (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.MinSpeed   == 0)
        )
      {
        /* too bright and vehicle speed above activation speed */
        *peHighwayOut = RTE_HLAF_MTWY_UNKNOWN;
      }
      else if( pHighwayIn->e_SpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD) /* Detection over speed only */
      {
          *peHighwayOut = RTE_HLAF_MTWY_MOTORWAY;
      }
      /* Highway Speed case */
      else if(        (pHighwayIn->e_SpeedDetection == RTE_HLAR_HIGHWAY_SP_NOT_DTCD)
          &&  (      (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) 
          || (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_LOW_SPEED)
          || (pHighwayIn->e_LateralPosition        == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
          )
          )
      {
          /* country road detected */
          *peHighwayOut = RTE_HLAF_MTWY_COUNTRY;
      }
      /* internal HLAF highway state: used by HLAF Light, Std and Plus */
      else if(    (bInternal == b_TRUE)
               && (    (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) /* motion, exit detected low speed */
                    || (pHighwayIn->e_LateralPosition        == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)     /* low distance between own and oncoming lane */
                  ) 
             )
      {
        /* country road detected */
        *peHighwayOut = RTE_HLAF_MTWY_COUNTRY;
      }
      /* external HLAF highway state: FR/ CAN output state */
      else if(    (bInternal == b_FALSE)
               && (    (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) /* motion, exit detected low speed */
                    || (pHighwayIn->e_EgoMotion   == RTE_HLAR_HIGHWAY_EM_LOW_SPEED) /* motion, exit detected low speed */
                    || (pHighwayIn->e_LateralPosition        == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)     /* low distance between own and oncoming lane */
                  ) 
             )
      {
        /* country road detected */
        *peHighwayOut = RTE_HLAF_MTWY_COUNTRY;  
      }
      else
      {
        *peHighwayOut = RTE_HLAF_MTWY_MOTORWAY;
      }
      break;
    
    default:
      /* Error */
      *peHighwayOut = RTE_HLAF_MTWY_UNKNOWN;
      break;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionDimmedLight                              */ /*!  
  Description:      Dimming the head lamps when bright objects are detected 
                    which could blind the driver

  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
void HLAFDecisionDimmedLight( /* input */
                              const HLA_t_HeadlightState          *ps_HeadlightState,
                              const HLA_t_ObjectList              *ps_ObjectList,
                              /* history */
                              HLAFDimmedLight_t                   *ps_DimmedLight,
                              /* output */
                              RTE_HLAF_LightOutput                *pe_LightOutput_Lt,
                              RTE_HLAF_LightOutput                *pe_LightOutput_Rt
                            )
{
  uint32 i;
  uint32 dimmRequestsLeft = 0;
  uint32 dimmRequestsRight = 0;
  const float32 headLampCenter = 0.5f * (ps_HeadlightState->f32_CurveLightRotAngle_Lt + ps_HeadlightState->f32_CurveLightRotAngle_Rt);
  const HLA_t_Object* pHLAObj = &ps_ObjectList->as_Object[0];

  ps_DimmedLight->dimmRequestLeft <<= 1;
  ps_DimmedLight->dimmRequestRight <<= 1;

  for (i=0; i<ps_ObjectList->ui32_NumObjects; i++)
  {
    if ((pHLAObj->s_Status.isBrightObject == 1) &&
        /* ~CodeReview ~ID:32392eb14ec1e1fbf92a0d331cde037c ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120930 Magic number 2500. Consider central definition of this number. */
        (pHLAObj->ui16_ttb18_ms > 2500))
    {
      if (pHLAObj->f32_ObjectHorAng_rad > headLampCenter)
      {
        ps_DimmedLight->dimmRequestLeft |= 0x01;
      }
      else
      {
        ps_DimmedLight->dimmRequestRight |= 0x01;
      }
    }

    pHLAObj++;
  }

  for (i=0; i<32; i++)
  {
    if ((ps_DimmedLight->dimmRequestLeft & ((uint32)0x01 << i)) > 0)
    {
      dimmRequestsLeft++;
    }
    if ((ps_DimmedLight->dimmRequestRight & ((uint32)0x01 << i)) > 0)
    {
      dimmRequestsRight++;
    }
  }

  if (dimmRequestsLeft >= 3)
  {
    *pe_LightOutput_Lt = RTE_HLAF_LIGHTOUTPUT_MIN;
  }
  else
  {
    *pe_LightOutput_Lt = RTE_HLAF_LIGHTOUTPUT_MAX;
  }

  if (dimmRequestsRight >= 3)
  {
    *pe_LightOutput_Rt = RTE_HLAF_LIGHTOUTPUT_MIN;
  }
  else
  {
    *pe_LightOutput_Rt = RTE_HLAF_LIGHTOUTPUT_MAX;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionTrafficStyle                              */ /*!  
  Description:      Set Traffic style output.
                    Set normalize factor for left/ right hand traffic.
                    

  @param[in]        
                    
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionTrafficStyle( /* input */
                               const RTE_HLA_TrafficStyle     eTrafficStyleIn,
                               /* history */
                               HLAFTrafficStyle_t             *pData,
                               /* output */
                               HLAFTrafficStyleOut_t          *pOut
                             )
{
  switch(pData->eTrafficStyle)
  {
    case RTE_HLA_TRAFFIC_STYLE_UNKNOWN:
      pData->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHD;
      break;
    case RTE_HLA_TRAFFIC_STYLE_RHD:
      if(eTrafficStyleIn == RTE_HLA_TRAFFIC_STYLE_LHD)
      {
        pData->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHD;
      }
      break;
    case RTE_HLA_TRAFFIC_STYLE_LHD:
      if(eTrafficStyleIn == RTE_HLA_TRAFFIC_STYLE_RHD)
      {
        pData->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHD;
      }
      break;
    default:
      pData->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHD;
      break;
  }

  pOut->eTrafficStyle = pData->eTrafficStyle;
  if(pOut->eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
  {
    pOut->NormFactor = -1.0f;    
  }
  else
  {
    pOut->NormFactor = 1.0f;
  }
}

/* **************************************************************************** 
  Functionname:     HLAFDecisionSetTurnOffReasonGlob                     */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
void HLAFDecisionSetTurnOffReasonGlob( const RTE_HLAR_BrightnessState   e_Brightness,
                                       const RTE_HLA_ParameterAlgoCfg_t *pAlgoCfg,
                                       const HLAFData_t                 *pFData,
                                       const HLA_t_Availability         *pAvail,
                                       /* output */ 
                                       HLAFTurnOffReasonGlob_t          *pTurnOffReason
                                     )
{
  HLAFDecicionDecTurnKeepOffCnt( &pTurnOffReason->Cnt.NotReleased,
                                  sizeof(pTurnOffReason->Cnt)
                               );

  /* HLA active ? */
  if(pAvail->e_State != RTE_HLA_STATE_ACTV)
  {
    pTurnOffReason->Reason.Bit.NotActive = 1;
    pTurnOffReason->Cnt.NotActive = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.NotActive = 0;
  }


  /* HLA available ? */
  if(pAvail->e_Type == RTE_HLA_TYPE_NAVL)
  {
    pTurnOffReason->Reason.Bit.NotAvl = 1;
    pTurnOffReason->Cnt.NotAvl = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.NotAvl = 0;
  }



  /* turn off high beam due to min speed check for PASSIVE_BY_V_MIN */
  if(pFData->DecisionData.Speed.disableHLABySpeed > 0)
  {
    /* min speed */
    pTurnOffReason->Reason.Bit.MinSpeed = 1;
    pTurnOffReason->Cnt.MinSpeed = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.MinSpeed = 0;
  }
    
  /* city detected ? */
  if(    (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_DTCD)
      && (pAlgoCfg->CityDetection == RTE_HLA_CITYDET_ACTIVE)
     )
  {
    pTurnOffReason->Reason.Bit.City = 1;
    pTurnOffReason->Cnt.City = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.City = 0;
  }

  /* tunnel detected ? */
  if(    (pFData->DecisionOut.eTunnelState == RTE_HLAR_TUNNEL_INSIDE)
      && (pAlgoCfg->TunnelDetection == RTE_HLA_TUNNELDET_ACTIVE)
     )
  {
    pTurnOffReason->Reason.Bit.Tunnel = 1;
    pTurnOffReason->Cnt.Tunnel = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.Tunnel = 0;
  }

  /* too many Maxima detected */
/* ~CodeReview ~ID:a5a3fa6068622d204a27bcc8a8402584 ~Reviewer:CW01\uidu4053/PC2357\dijkstg ~Date:16.07.2012 ~Priority:3 ~Comment:Comment, or remove dead code. */
#if 0
  if(0)
  {
    pTurnOffReason->Reason.Bit.Maxima = 1;
    pTurnOffReason->Cnt.Maxima = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.Maxima = 0;
  }
#endif

  /* too bright */
  if(e_Brightness < RTE_HLAR_BRT_NIGHT)
  {
    pTurnOffReason->Reason.Bit.Brightness = 1;
    pTurnOffReason->Cnt.Brightness = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.Brightness = 0;
  }
    
  /* clearance measurement running ? */
  if(    (pFData->DecisionOut.Blockage.b_ClearanceMeasurement == FALSE)
      && ((pAlgoCfg->TestMode == RTE_HLA_TESTMODE_NO_CLEARMEAS) == 0)
    )
  {
    pTurnOffReason->Reason.Bit.NotReleased = 1;
    pTurnOffReason->Cnt.NotReleased = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.NotReleased = 0;
  }
  
  /* blockage detected ? */
  if(   (pFData->DecisionOut.Blockage.b_Blockage == TRUE)
     && (pAlgoCfg->BlockageDetection == RTE_HLA_BLOCKDET_ACTIVE)
     && ((pAlgoCfg->TestMode == RTE_HLA_TESTMODE_NO_CLEARMEAS) == 0)
    )
  {
    pTurnOffReason->Reason.Bit.Blockage = 1;
    pTurnOffReason->Cnt.Blockage = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pTurnOffReason->Reason.Bit.Blockage = 0;
  }

  if(pTurnOffReason->Reason.u32 == 0)
  {
    /* reset timer */
    pTurnOffReason->Timer_TurnOffActive_s = 0.0f;
  } 
  else
  {
    /* increment timer */
    pTurnOffReason->Timer_TurnOffActive_s += pFData->CamData.dtimeFwd_s;
  }
}

/* **************************************************************************** 
  Functionname:     HLAFDecicionDecTurnKeepOffCnt                        */ /*!
  @brief            HLAF decrement turn off / keep off counter
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecicionDecTurnKeepOffCnt(uint8 *pui8_Cnt, uint32 length)
{
  uint32 i;
  
  for(i=0; i<length; i++)
  {
    if(*pui8_Cnt > 0)
    {
      *pui8_Cnt = *pui8_Cnt - 1;
    }
    pui8_Cnt++; 
  }
}

/* **************************************************************************** 
  Functionname:     HLAFDecicionLightStyle                               */ /*!
  @brief            detect the current light style like
                    symmetric: could be left hand Traffic
                    country:   should be right hand traffic on country road
                    motorway:  should be right hand traffic on highway
                    
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecicionLightStyle( /* input */
                             const HLAF_t_RequiredInputs *ps_In,
                             const float32 dTime_s, 
                             /* history */
                             HLAFLightStyle_t *pHist,
                             /* output */
                             HLAFLightStyleOut_t *pLightStyle
                           )
{
  const float32 MinTime_s = 5.0f;
  uint8 i;

  RTE_HLA_LightStyle lightStyle_l = RTE_HLA_LIGHTSTYLE_FULL_HB;
  RTE_HLA_LightStyle lightStyle_r = RTE_HLA_LIGHTSTYLE_FULL_HB;

  for (i = 0; i < CML_Min(RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS, ps_In->s_Sig.ps_HeadlightState->nGFA); i++)
  {
    lightStyle_l = CML_Min(lightStyle_l, ps_In->s_Sig.ps_HeadlightState->GFA[i].e_LightStyle_Lt);
    lightStyle_r = CML_Min(lightStyle_r, ps_In->s_Sig.ps_HeadlightState->GFA[i].e_LightStyle_Rt);
  }

  
  /* symmetric light */
  if(    (   (ps_In->s_Par.ps_HlaPar->Country.TrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
          && (lightStyle_r == RTE_HLA_LIGHTSTYLE_SYMM)
         )
      || (   (ps_In->s_Par.ps_HlaPar->Country.TrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
          && (lightStyle_l == RTE_HLA_LIGHTSTYLE_SYMM)
         )
    )
  {
    /* increment timer */
    pHist->TimerSymmetric_s += dTime_s;
  }
  else
  {
    /* reset timer */
    pHist->TimerSymmetric_s = 0.0f;
  }

  /* country light */
  if(    (lightStyle_l == RTE_HLA_LIGHTSTYLE_COUNTRY)
      || (lightStyle_r == RTE_HLA_LIGHTSTYLE_COUNTRY)
    )
  {
    /* increment timer */
    pHist->TimerCountry_s += dTime_s;
  }
  else
  {
    /* reset timer */
    pHist->TimerCountry_s = 0.0f;
  }

  /* motorway light */
  if(    (lightStyle_l == RTE_HLA_LIGHTSTYLE_MOTORWAY)
      || (lightStyle_r == RTE_HLA_LIGHTSTYLE_MOTORWAY)
    )
  {
    /* increment timer */
    pHist->TimerMotorway_s += dTime_s;
  }
  else
  {
    /* reset timer */
    pHist->TimerMotorway_s = 0.0f;
  }

  /* TODO: RTE_HLA_LIGHTSTYLE_UNKNOWN, RTE_HLA_LIGHTSTYLE_SPOT */
  
    
  /* light style state machine */
  switch(pHist->eState)
  {
    case HLAF_LIGHTSTYLE_SYMM:
    case HLAF_LIGHTSTYLE_COUNTRY:
    case HLAF_LIGHTSTYLE_MOTORWAY:
      /* normal mode */
      if(pHist->TimerSymmetric_s > MinTime_s)
      {
        /* symmetric light style detected */
        pHist->eState = HLAF_LIGHTSTYLE_SYMM;
      }
      else if(pHist->TimerCountry_s > MinTime_s)
      {
        /* country light style detected */
        pHist->eState = HLAF_LIGHTSTYLE_COUNTRY;
      }
      else if(pHist->TimerMotorway_s > MinTime_s)
      {
        /* motorway light style detected */
        pHist->eState = HLAF_LIGHTSTYLE_MOTORWAY;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLAF_LIGHTSTYLE_LAST:
    case HLAF_LIGHTSTYLE_IDLE:
    /* use HLAF_LIGHTSTYLE_IDLE as default */
    default:
      /* idle state */
      if(pHist->TimerSymmetric_s > MinTime_s)
      {
        /* symmetric light style detected */
        pHist->eState = HLAF_LIGHTSTYLE_SYMM;
      }
      else if(pHist->TimerCountry_s > MinTime_s)
      {
        /* country light style detected */
        pHist->eState = HLAF_LIGHTSTYLE_COUNTRY;
      }
      else if(pHist->TimerMotorway_s > MinTime_s)
      {
        /* motorway light style detected */
        pHist->eState = HLAF_LIGHTSTYLE_MOTORWAY;
      } 
      else if(   /* driving forwards */
                 (ps_In->s_Sig.ps_MotionState->e_MoveState == HLA_MOVE_STATE_FWD)
                 /* velocity above 1m/s */
              && (ps_In->s_Sig.ps_MotionState->f32_SpeedDisplay > 1.0f)
             )
      {
        if(pHist->TimerSymmetric_s > CML_f_Max(pHist->TimerCountry_s, pHist->TimerMotorway_s))
        {
          /* symmetric light style detected */
          pHist->eState = HLAF_LIGHTSTYLE_SYMM;
        } 
        else if(pHist->TimerCountry_s > CML_f_Max(pHist->TimerSymmetric_s,pHist->TimerMotorway_s))
        {
          /* country light style detected */
          pHist->eState = HLAF_LIGHTSTYLE_COUNTRY;
        }
        else if(pHist->TimerMotorway_s > CML_f_Max(pHist->TimerCountry_s,pHist->TimerMotorway_s))
        {
          /* motorway light style detected */
          pHist->eState = HLAF_LIGHTSTYLE_MOTORWAY;
        }
        else
        {
          /* Do nothing */
        }
      }
      else
      {
        /* Do nothing */
      }
      break;
  }

  /* set output */
  pLightStyle->eLightStyle = pHist->eState;
}



/******************************************/
/* keep off reason for standard and light */
/******************************************/

/* **************************************************************************** 
  Functionname:     HLAFDecSetKeepOffReasonSmallRadius                         */ /*!
  @brief            Keep HB off until the curvature is very small.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
static void HLAFDecSetKeepOffReasonSmallRadius( /* input */
                                                const HLAFCameraData_t    *pCamData,
                                                const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                                const HLAFParStdKeepOffSmallRadius_t *pPar,
                                                /* history */
                                                HLAFStdKeepOffSmallRadius_t     *pSmallRadius, 
                                                /* output */
                                                HLAFStdKeepOffReason_t *pKeepOffReason
                                              )
{
  /* decrement delay timer */
  pSmallRadius->DelayTimer_s -= pCamData->dtimeFwd_s;
  pSmallRadius->DelayTimer_s = CML_f_Max(pSmallRadius->DelayTimer_s, 0.0f);
  
  
  if(    (pCamData->radiusAbs_m < pPar->minRadius2TurnsOn)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
    )
  {
    pSmallRadius->DelayTimer_s = pPar->maxSmallRadiusDelay_s;
  }
  /* smallRadius in hold ? */
  /* wait some cycles after curve with small radius due to s-curves */
  if(pSmallRadius->DelayTimer_s > 0.0f)
  {
    pKeepOffReason->Reason.Bit.SmallRadius = 1;
    pKeepOffReason->Cnt.SmallRadius = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.SmallRadius = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecSetKeepOffReasonMinTimeHBoff                         */ /*!
  @brief            Keep HB off for a minimal time.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
static void HLAFDecSetKeepOffReasonMinTimeHBoff( /* input */
                                                 const HLAFCameraData_t   *pCamData,
                                                 const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                                 const HLAFParStdKeepOffMinTimeHBOff_t *pPar,
                                                 const HLAFPenaltyTimer_t  *pPenaltyTimer,
                                                 /* history */
                                                 HLAFStdKeepOffMinTimeHBOff_t *pMinTimeOff, 
                                                 /* output */
                                                 HLAFStdKeepOffReason_t *pKeepOffReason
                                               )
{
  /* refuse turning high beams on for a certain time after turning high beams off */
  if(eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
  {
    /* previous state = HB off*/
    pMinTimeOff->HBOffTimer_s -= pCamData->dtimeFwd_s;
    pMinTimeOff->HBOffTimer_s = CML_f_Max(pMinTimeOff->HBOffTimer_s, 0.0f);
  }
  else
  {
    /* previous state = HB on */
    /* set minimum number of cycles high beams has to be turned off */
    pMinTimeOff->HBOffTimer_s = pPar->minTimeHBOff_s + pPenaltyTimer->activatePenaltyTime_s;
  }
  
  if(    (pMinTimeOff->HBOffTimer_s > 0.0f)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
    )
  {
    pKeepOffReason->Reason.Bit.MinTimeHBOff = 1;
    pKeepOffReason->Cnt.MinTimeHBOff = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.MinTimeHBOff = 0;
  }    
}

/* **************************************************************************** 
  Functionname:     HLAFDecSetKeepOffReasonTurnOnDelay_Oncoming_TruckLights                   */ /*!
  @brief            Keep HB off depending on Oncoming Truck Lights
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Alexander Fischer
*****************************************************************************/
static void HLAFDecSetKeepOffReason_TurnOnDelay_Oncoming_TruckLights( /* input */
                                                                      const HLAF_t_RequiredInputs* pIn,
                                                                      const HLAFData_t*            pFData,
                                                                      const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                                                      const HLAFPenaltyTimer_t*    pPenaltyTimer,
                                                                      /* history and output */
                                                                      HLAFStdKeepOffReason_t*      pKeepOffReason
                                                                    )
{
  uint8 i;
  boolean potentialTL = FALSE;
  const HLA_t_ObjectList      *pObjList = pIn->s_Sig.ps_ObjectList;

  pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_TL_s -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_TL_s  = CML_f_Max(pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_TL_s, 0.0f);

  /* Oncoming Delay is set */
  if(pKeepOffReason->Reason.Bit.TurnOnDelay_Onc == 1)
  {

    /* Check Object List for potential truck lights*/
    for(i=0; i<pObjList->ui32_NumObjects; i++)
    {
      const HLA_t_Object    *pObj    = &pObjList->as_Object[i];

      if(pObj->s_Status.isPotentialTruckLight == 1)
      {
        potentialTL = b_TRUE;
      }

    }

    /* Any TL, HB off --> Set Timer */
    if(    (potentialTL == b_TRUE)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      )
    {//TODO schillinger OncomingMaxHighway ändern in eigenen wert
      pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_TL_s = pIn->s_Par.s_HlafPar.TurnOnDelay.OncomingMaxHighway + pPenaltyTimer->activatePenaltyTime_s;
    }
 
  }

  if(pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_TL_s > 0.0f)
  {
    /* keep HB off */
    pKeepOffReason->Reason.Bit.TurnOnDelay_Onc_TL = 1;
    pKeepOffReason->Cnt.TurnOnDelay_Onc_TL        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.TurnOnDelay_Onc_TL = 0;
  }



}
/* **************************************************************************** 
  Functionname:     HLAFDecSetKeepOffReasonTurnOnDelay                   */ /*!
  @brief            Keep HB off depending on max TTB of lost vehicle.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
static void HLAFDecSetKeepOffReasonTurnOnDelay( /* input */
                                                const HLAFData_t                 *pFData,
                                                const RTE_HLAF_HighBeamState      eHighBeamStatePrev,
                                                const HLAFRelevantVehicle_t      *pRelVeh,
                                                const HLAFPenaltyTimer_t         *pPenaltyTimer,
                                                const HLAFParameterTurnOnDelay_t *pPar,
                                                /* history and output */
                                                HLAFStdKeepOffReason_t           *pKeepOffReason
                                              )
{
  /* decrement turn on/ init timer */
  pKeepOffReason->TurnOnDelay.InitTimer_s   -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.InitTimer_s    = CML_f_Max(pKeepOffReason->TurnOnDelay.InitTimer_s, 0.0f);
  
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s  = CML_f_Max(pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s, 0.0f);

  pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s  = CML_f_Max(pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s, 0.0f);

  /* load init timer */
  if(    (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotActive == 1)
      || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotAvl == 1)
    )
  {
    pKeepOffReason->TurnOnDelay.InitTimer_s = pPar->initialTurnOnDelay;
  }  
  

  if(    (pRelVeh->bOncDetected == b_TRUE)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
    )
  {
    pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s = pRelVeh->Onc_s + pPenaltyTimer->activatePenaltyTime_s;
  }
  
  if(    (pRelVeh->bPrecDetected == b_TRUE)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
    )
  {
    pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s = pRelVeh->Prec_s + pPenaltyTimer->activatePenaltyTime_s;
  }

  if(pKeepOffReason->TurnOnDelay.InitTimer_s > 0.0f)
  {
    /* keep HB off */
    pKeepOffReason->Reason.Bit.TurnOnDelay_Init = 1;
    pKeepOffReason->Cnt.TurnOnDelay_Init        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.TurnOnDelay_Init = 0;
  }

  if(pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s > 0.0f)
  {
    /* keep HB off */
    pKeepOffReason->Reason.Bit.TurnOnDelay_Onc = 1;
    pKeepOffReason->Cnt.TurnOnDelay_Onc        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.TurnOnDelay_Onc = 0;
  }

  if(pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s > 0.0f)
  {
    /* keep HB off */
    pKeepOffReason->Reason.Bit.TurnOnDelay_Prec = 1;
    pKeepOffReason->Cnt.TurnOnDelay_Prec        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.TurnOnDelay_Prec = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecSetKeepOffReasonPotentialVehicle              */ /*!
  @brief            Keep HB off if potential vehicle is detected.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
static void HLAFDecSetKeepOffReasonPotentialVehicle( /* input */
                                                     const HLAF_t_RequiredInputs     *ps_In,
                                                     const HLAFData_t                *pFData,
                                                     const RTE_HLAF_HighBeamState     eHighBeamStatePrev,
                                                     const HLAFParStdKeepOffPotVeh_t *pPar,
                                                     /* history and output */
                                                     HLAFStdKeepOffReason_t          *pKeepOffReason
                                                   )
{
  uint32 i;
  boolean bPotVeh = FALSE;
  boolean bPotVehHighProbable = FALSE;


  /* decrement delay timer */
  pKeepOffReason->PotVeh.DelayTimer_Onc -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->PotVeh.DelayTimer_Onc  = CML_f_Max(pKeepOffReason->PotVeh.DelayTimer_Onc, 0.0f);

  pKeepOffReason->PotVeh.DelayTimer_Prec -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->PotVeh.DelayTimer_Prec  = CML_f_Max(pKeepOffReason->PotVeh.DelayTimer_Prec, 0.0f);

  pKeepOffReason->PotVeh.DelayTimer_Glob -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->PotVeh.DelayTimer_Glob  = CML_f_Max(pKeepOffReason->PotVeh.DelayTimer_Glob, 0.0f);

 
  for(i=0; i<ps_In->s_Sig.ps_ObjectList->ui32_NumObjects; i++)
  {
    HLA_t_Object *pObj = &ps_In->s_Sig.ps_ObjectList->as_Object[i];
    
    /* object inside HLA Roi ? */
    if(    (pObj->si16_xcenter > ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiX1)
        && (pObj->si16_xcenter < ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiX2)
        && (pObj->si16_ycenter > ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiY1)
        && (pObj->si16_ycenter < ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiY2)
      )
    {
      /* ~CodeReview ~ID:6b567c62636f6ef006461320e770d8e1 ~Reviewer:PC2357\dijkstg/CW01\uidu4053 ~Date:17-7-2012 ~Priority:3 ~Comment:120930 Magic number 3000. Consider central definition of this number. */
      if(pObj->ui16_ttb18_ms > 3000)
      {
        if(pObj->s_Status.isPotentialVehicleOncoming1st == 1)
        {
          bPotVeh = TRUE;
        }
        if(    (pObj->s_Status.isPotentialVehicleAhead1st == 1)
            && (ps_In->s_Sig.ps_Environment->e_RedReflectorArea == RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD)
          )
        {
          bPotVeh = TRUE;
        }
      }
      if(pObj->s_Status.isPotentialVehicleHighProbable == 1)
      {
        bPotVehHighProbable = TRUE;
      }
    }
    else
    {
      /* do nothing */
    }
  }
       
  /* global turn off active */
  /* load DelayTimer_Glob   */
  if(    (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (pFData->DecisionData.TurnOffReason_glob.Reason.u32 > 0)
      && (bPotVeh == b_TRUE)
    )
  {
    /* load short delay time */
    pKeepOffReason->PotVeh.DelayTimer_Glob = pPar->Delay_Glob;
  }
    
  /* TurnOnDelay_Onc active */
  /* load DelayTimer_Onc    */
  if(    (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (pKeepOffReason->Reason.Bit.TurnOnDelay_Onc == 1)
      && (bPotVeh == b_TRUE)
      && (bPotVehHighProbable == b_TRUE)
    )
  {
    /* load short delay time */
    pKeepOffReason->PotVeh.DelayTimer_Onc = pPar->Delay_Onc;
  }

  /* TurnOnDelay_Prec active */
  /* load DelayTimer_Prec    */
  if(    (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (pKeepOffReason->Reason.Bit.TurnOnDelay_Prec == 1)
      && (bPotVeh == b_TRUE)
      && (bPotVehHighProbable == b_TRUE)
    )
  {
    /* load short delay time */
    pKeepOffReason->PotVeh.DelayTimer_Prec = pPar->Delay_Prec;
  }

    
  if(    (pKeepOffReason->PotVeh.DelayTimer_Onc > 0.0f)
      && (bPotVeh == b_TRUE)
      && (bPotVehHighProbable == b_TRUE)
    )
  {
    pKeepOffReason->Reason.Bit.PotVeh_Onc = 1;
    pKeepOffReason->Cnt.PotVeh_Onc        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.PotVeh_Onc = 0;
  }
  if(    (pKeepOffReason->PotVeh.DelayTimer_Prec > 0.0f)
      && (bPotVeh == b_TRUE)
      && (bPotVehHighProbable == b_TRUE)
    )
  {
    pKeepOffReason->Reason.Bit.PotVeh_Prec = 1;
    pKeepOffReason->Cnt.PotVeh_Prec        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.PotVeh_Prec = 0;
  }
  if(    (pKeepOffReason->PotVeh.DelayTimer_Glob > 0.0f)
      && (bPotVeh == b_TRUE)
    )
  {
    pKeepOffReason->Reason.Bit.PotVeh_Glob = 1;
    pKeepOffReason->Cnt.PotVeh_Glob        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.PotVeh_Glob = 0;
  }
}

/* **************************************************************************** 
  Functionname:     HLAFDecSetKeepOffPrecedingVehLost                         */ /*!  
  Description:      Preceding vehicle lost -> keep HB off until we reached the position
                    where we have lost the vehicle.
                    
  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
#define HLA_STD_RMAX 10000.0f

static void HLAFDecSetKeepOffPrecedingVehLost( /* input */
                                          const HLAF_t_RequiredInputs    *ps_In,
                                          const HLAFData_t               *pFData,
                                          const HLAFParameterKeepOff_t   *pPar,  
                                          const HLA_t_ObjectList         *pObjectList,
                                          /* History/ output */
                                          HLAFStdKeepOffPrecedingVehicleLost  *pPrecVehLost
                                        )
{
  uint32 i;
    
     
  pPrecVehLost->distance2cover -= pFData->CamData.ddistFwd_m;
  pPrecVehLost->distance2cover  = CML_f_Max(0.0f, pPrecVehLost->distance2cover);
  
    
  for(i=0; i<pObjectList->ui32_NumVehicles; i++)
  {
    const HLA_t_Object *pObj = &pObjectList->as_Object[i];
   
    
    if(    (pObj->s_Status.isVehicleAhead == 1) 
        && (ps_In->s_Sig.ps_MotionState->f32_Speed > 0.1f)
        && (pObj->s_Status.willBeRemoved == 1)
      )
    {
      /* traffic ahead will be deleted in the next frame */
      float32 xw_m    = 0.005f * (float32)(pObj->s_ObjectPos_xw.ui16_distMin_cm + pObj->s_ObjectPos_xw.ui16_distMax_cm);
      float32 yw_m    = 0.01f * pObj->si16_ObjectPos_yw_cm; 
      float32 timegap = xw_m/ ps_In->s_Sig.ps_MotionState->f32_Speed;

      if(    (timegap < 2.0f)
          && (xw_m > pPrecVehLost->distance2cover)
        )
      {
        if(CML_f_Abs(yw_m) < 0.001f)
        {
          yw_m = 0.001f;
        }
        pPrecVehLost->rMax = ((xw_m * (0.5f * xw_m))/yw_m);

        /* check rMax */
        if(CML_f_Abs(pPrecVehLost->rMax) < HLA_STD_RMAX)
        {
          pPrecVehLost->distance2cover = CML_f_Min(xw_m, pPar->maxDist2Cover);
        }
      }
    }
  }
  
  if(pPrecVehLost->distance2cover <= 0.0f)
  {
    /* position where preceding vehicle disappeared is reached */

    /* check if we are in a curve -> keep HB off untill we are at the end of the curve */
    /* J.Häfer: No Possible Side Effect */
    /* PRQA S 3415 5 */
    if(    (CML_f_Abs(pPrecVehLost->rMax) < HLA_STD_RMAX) 
           /* J.Häfer Comparing floating point expressions can checked for equality through CML_Sign (MISRA 13.3) */
           /* PRQA S 3341 1 */
        && (CML_Sign(pPrecVehLost->rMax) == CML_Sign(pFData->CamData.radiusAbs_m))
        && (CML_f_Abs(pFData->CamData.radiusAbs_m) < CML_f_Abs (pPrecVehLost->rMax))
      )
    {
      /* we are in a curve */
      /* keep HB off       */
      pPrecVehLost->distance2cover = 1.0f;
    }
    else
    {
      /* preceding vehicle seems not be lost due to curve coverage */
      pPrecVehLost->distance2cover  = 0.0f;
      pPrecVehLost->rMax            = HLA_STD_RMAX;
    }
  }
}
#undef HLA_STD_RMAX


static void HLAFDecSetKeepOffReasonMayBeCity( /* input */
                                       const HLAFData_t *pFData,
                                       const RTE_HLAF_HighBeamState eHighBeamStatePrev,
                                       const HLAFStdTurnOffReason_t *pTurnOffReason,
                                       const HLAFRelevantVehicle_t *pRelVeh,
                                       const HLAFParameterKeepOff_t *pParKeepOff,
                                       /* history and output */
                                       HLAFStdKeepOffReason_t *pKeepOffReason
                                     )
{
  
  /* decrement delay timer */
  pKeepOffReason->MayBeCity.TurnOnTimer_Onc -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->MayBeCity.TurnOnTimer_Onc  = CML_f_Max(pKeepOffReason->MayBeCity.TurnOnTimer_Onc, 0.0f);

  pKeepOffReason->MayBeCity.TurnOnTimer_Prec -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->MayBeCity.TurnOnTimer_Prec  = CML_f_Max(pKeepOffReason->MayBeCity.TurnOnTimer_Prec, 0.0f);

  pKeepOffReason->MayBeCity.TurnOnTimer_Glob -= pFData->CamData.dtimeFwd_s;
  pKeepOffReason->MayBeCity.TurnOnTimer_Glob  = CML_f_Max(pKeepOffReason->MayBeCity.TurnOnTimer_Glob, 0.0f);


  /* load TurnOnTimer_Onc */
  if(    (pRelVeh->bOncDetected == b_TRUE)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
    )
  {
    /* load delay */
    pKeepOffReason->MayBeCity.TurnOnTimer_Onc = pParKeepOff->MayBeCity.Delay_Onc;
  }

  /* load TurnOnTimer_Prec */
  if(    (pRelVeh->bPrecDetected == b_TRUE)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
    )
  {
    /* load delay */
    pKeepOffReason->MayBeCity.TurnOnTimer_Prec = pParKeepOff->MayBeCity.Delay_Prec;
  }

  /* load TurnOnTimer_Glob */
  if(    (pTurnOffReason->Reason.u32 == 1)
      && (eHighBeamStatePrev == RTE_HLAF_HB_STATE_OFF)
      && (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
    )
  {
    /* load delay */
    pKeepOffReason->MayBeCity.TurnOnTimer_Glob = pParKeepOff->MayBeCity.Delay_Global;
  }

  /* MaybeCity_Onc */
  if(    (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
      && (pKeepOffReason->MayBeCity.TurnOnTimer_Onc  > 0.0f)
    )
  {
    pKeepOffReason->Reason.Bit.MaybeCity_Onc = 1;
    pKeepOffReason->Cnt.MaybeCity_Onc = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.MaybeCity_Onc = 0;
  }

  /* MaybeCity_Prec */
  if(    (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
      && (pKeepOffReason->MayBeCity.TurnOnTimer_Prec  > 0.0f)
    )
  {
    pKeepOffReason->Reason.Bit.MaybeCity_Prec = 1;
    pKeepOffReason->Cnt.MaybeCity_Onc = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.MaybeCity_Prec = 0;
  }

  /* MaybeCity_Glob */
  if(    (pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
    && (pKeepOffReason->MayBeCity.TurnOnTimer_Glob  > 0.0f)
    )
  {
    pKeepOffReason->Reason.Bit.MaybeCity_Glob = 1;
    pKeepOffReason->Cnt.MaybeCity_Glob = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.MaybeCity_Glob = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionSetKeepOffReason                         */ /*!
  @brief            set keep off reason for hla light and standard.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
void HLAFDecisionSetKeepOffReason( /* input */
                                   const HLAF_t_RequiredInputs      *ps_In,
                                   const HLAFData_t                 *pFData,
                                   const HLAFParameterKeepOff_t     *pParKeepOff,
                                   const HLAFParameterTurnOnDelay_t *pParTurnOnDelay,
                                   const RTE_HLAF_HighBeamState      eHighBeamStatePrev,
                                   const HLAFRelevantVehicle_t      *pRelVeh,
                                   const HLAFPenaltyTimer_t         *pPenaltyTimer,
                                   const HLAFStdTurnOffReason_t     *pTurnOffReason,
                                   /* history and  output */
                                   HLAFStdKeepOffReason_t           *pKeepOffReason
                                 )
{
  HLAFDecicionDecTurnKeepOffCnt( &pKeepOffReason->Cnt.SpdAcc,
                                 sizeof(pKeepOffReason->Cnt)
                               );


  /* velocity will fall below activation speed in some seconds */
  /* -> keep full HB off                                       */
  if(pFData->DecisionData.Speed.keepOffHLABySpeed > 0u)
  {
    pKeepOffReason->Reason.Bit.SpdAcc = 1;
    pKeepOffReason->Cnt.SpdAcc = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.SpdAcc = 0;
  }


  /* may be city detected                                           */
  /* keep full HB off because city will be detected in same Frames  */
  HLAFDecSetKeepOffReasonMayBeCity( /* input */
                                    pFData,
                                    eHighBeamStatePrev,
                                    pTurnOffReason,
                                    pRelVeh,
                                    pParKeepOff,
                                    /* history and output */
                                    pKeepOffReason
                                  );
   

  /* small radius -> keep HB off */
  HLAFDecSetKeepOffReasonSmallRadius( /* input */
                                      &pFData->CamData,
                                      eHighBeamStatePrev,
                                      &pParKeepOff->KeepOffSmallRadius,
                                      /* history */
                                      &pKeepOffReason->SmallRadius, 
                                      /* output */
                                      pKeepOffReason
                                    );


  /* keep HB off for a minimal time */
  HLAFDecSetKeepOffReasonMinTimeHBoff( /* input */
                                       &pFData->CamData,
                                       eHighBeamStatePrev,
                                       &pParKeepOff->KeepOffMinTimeHBOff,
                                       pPenaltyTimer,
                                       /* history */
                                       &pKeepOffReason->MinTimeHBoff,
                                       /* output */
                                       pKeepOffReason
                                     );

  /* keep HB off depending on the TTB of the target vehicle */
  HLAFDecSetKeepOffReasonTurnOnDelay( /* input */
                                      pFData,
                                      eHighBeamStatePrev,
                                      pRelVeh,
                                      pPenaltyTimer,
                                      pParTurnOnDelay,
                                      /* history and output */
                                      pKeepOffReason
                                    );
  /* keep HB off because of oncoming truck lights */
  HLAFDecSetKeepOffReason_TurnOnDelay_Oncoming_TruckLights( /* input */
    ps_In,
    pFData,
    eHighBeamStatePrev,
    pPenaltyTimer,
    /* history and output */
    pKeepOffReason);

  
  /* preceding vehicle lost in curve                                                  */
  /* keep HB off until we reached the position (xw) we we lost the preceding vehicle  */
  /* keep HB off until we are at the end of the curve                                 */
  HLAFDecSetKeepOffPrecedingVehLost( /* input */
                                     ps_In,
                                     pFData,
                                     pParKeepOff,
                                     ps_In->s_Sig.ps_ObjectList,
                                     /* History/ output */
                                     &pKeepOffReason->PrecedingVehLost
                                   );

  if(CML_f_IsNonZero(pKeepOffReason->PrecedingVehLost.distance2cover))
  {
    pKeepOffReason->Reason.Bit.PrecedingVehLost = 1;
    pKeepOffReason->Cnt.PrecedingVehLost        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.PrecedingVehLost = 0;
  }

  /* potential */
  HLAFDecSetKeepOffReasonPotentialVehicle( /* input */
                                           ps_In,
                                           pFData,
                                           eHighBeamStatePrev,
                                           &pParKeepOff->KeepOffPotVeh,
                                           /* history and output */
                                           pKeepOffReason
                                         );
    
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionSetTurnOffReason                         */ /*!
  @brief            Set turn off reason. e.g. relevant preceding or oncoming vehicles detected. 
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
void HLAFDecisionSetTurnOffReason( /* input */
                                   const HLAFRelevantVehicle_t *pRelVeh,
                                   /* output */
                                   HLAFStdTurnOffReason_t      *pTurnOffReason
                                 )
{ 
  HLAFDecicionDecTurnKeepOffCnt( &pTurnOffReason->Cnt.OncDetected,
                                 sizeof(pTurnOffReason->Cnt)
                               );

  /* relevant oncoming vehicle detected ? */
  if(pRelVeh->bOncDetected == b_TRUE)
  {
    /* relevant oncoming vehicle detected */
    pTurnOffReason->Reason.Bit.OncDetected = 1;
    pTurnOffReason->Cnt.OncDetected = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    /* no relevant oncoming vehicle detected */
    pTurnOffReason->Reason.Bit.OncDetected = 0;
  }

  /* relevant preceding vehicle detected ? */
  if(pRelVeh->bPrecDetected == b_TRUE)
  {
    /* relevant oncoming vehicle detected */
    pTurnOffReason->Reason.Bit.PrecDetected = 1;
    pTurnOffReason->Cnt.PrecDetected = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    /* no relevant oncoming vehicle detected */
    pTurnOffReason->Reason.Bit.PrecDetected = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionFindRelevantVehicle                      */ /*!  
  Description:      Find relevant Vehicle with maximum ttb.
                    
  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionFindRelevantVehicle( /* input */
                                      const HLAF_t_RequiredInputs          *ps_In,
                                      const HLAFData_t                     *pFData,
                                      const HLA_t_ObjectList               *pObjectList,
                                      const RTE_HLAF_HighBeamState          eHighBeamStatePrev,
                                      /* History/ output */
                                      HLAFRelevantVehicle_t                *pRelVeh
                                    )
{
  /* get local copy of global pointer */
  uint32 i;
  boolean bPrecDet = b_FALSE;
  boolean bOncDet  = b_FALSE;  
  float32 TurnOnDelay_Onc  = 0.0f;
  float32 TurnOnDelay_Prec = 0.0f;
   
    
  for(i=0; i<pObjectList->ui32_NumVehicles; i++)
  {
    const HLA_t_Object *pObj = &pObjectList->as_Object[i];
    float32 TurnOnDelay_s = 0.0f;
    boolean bRelevantVehicle;


    bRelevantVehicle = HLAFDecisionRelevantVehicle2TurnOff( /* input */
                                                            eHighBeamStatePrev,
                                                            pObj,
                                                            pFData,
                                                            &ps_In->s_Par.s_HlafPar.TurnOff,
                                                            &ps_In->s_Sig.ps_ObjectList->s_ObjectRoi,
                                                            /* Region of interest for relevant traffic              */
                                                            /* vehicles within this region will be relevant traffic */
                                                            /* - independent of TTB and object angle                */
                                                            /* - region only used for partial HB and spot light     */
                                                            0.0f,
                                                            0.0f
                                                          );
    if(bRelevantVehicle == b_TRUE)
    {
      /* relevant object                                        */
      /* HB off:                                                */
      /*    take all objects alive or lost and low or high ttb  */
      /* HB on:                                                 */
      /*    take only alive objects with high ttb               */
      
      /* get turn on delay */
      HLAFDecisionTurnOnDelayTTB( /* input */
                                  pObj,
                                  ps_In->s_Sig.ps_MotionState->f32_Speed,
                                  pFData->DecisionOut.Motorway.eStateInt,
                                  pFData->DecisionOut.TrafficStyle.eTrafficStyle,
                                  ps_In,
                                  /* history/ output */
                                  &TurnOnDelay_s
                                );
    
      if(pObj->s_Status.isVehicleOncoming == 1)
      {
        /* oncoming vehicle */
        bOncDet    = b_TRUE;
        TurnOnDelay_Onc = CML_f_Max(TurnOnDelay_Onc, TurnOnDelay_s);
      }
      else
      {
        /* preceding vehicle */
        bPrecDet   = b_TRUE;
        TurnOnDelay_Prec = CML_f_Max(TurnOnDelay_Prec, TurnOnDelay_s);
      }
    }
  }
  pRelVeh->bOncDetected   = bOncDet;
  pRelVeh->bPrecDetected  = bPrecDet;    
  pRelVeh->Onc_s          = TurnOnDelay_Onc;
  pRelVeh->Prec_s         = TurnOnDelay_Prec;
  pRelVeh->All_s          = CML_f_Max(TurnOnDelay_Onc, TurnOnDelay_Prec);
}


/* **************************************************************************** 
  Functionname:     HLAFDecisionSetHBState                               */ /*!  
  Description:      Set HB state {HB on or off} 


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFDecisionSetHBState( /* input */
                             const HLAFTurnOffReasonGlob_t *pTurnOffReason_glob,
                             const HLAFStdTurnOffReason_t  *pTurnOffReason,
                             const HLAFStdKeepOffReason_t  *pKeepOffReason,
                             const RTE_HLAF_HighBeamState   eHighBeamStatePrev,
                             /* output */  
                             RTE_HLAF_HighBeamState        *peHighBeamStateOut
                           )
{
  /* no global turn off reason */
  if(pTurnOffReason_glob->Reason.u32 == 0)
  {
    /* HLA normal operating mode */
    if(eHighBeamStatePrev == RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* previous HB state = HB on */

      if(pTurnOffReason->Reason.u32 > 0)
      {
        /* transition HB full on -> HB off */  
        *peHighBeamStateOut = RTE_HLAF_HB_STATE_OFF;
      }
      else
      {
        /* keep enabled */
        *peHighBeamStateOut = RTE_HLAF_HB_STATE_FULL_ON;
      }
    }
    else
    {
      /* previous HB state = off */

      /* keep HB off ?           */
      if(    (pTurnOffReason->Reason.u32 == 0)
             /* keep high beam off ? */
          && (pKeepOffReason->Reason.u32 == 0)
        )
      {
        /* turn on */
        *peHighBeamStateOut = RTE_HLAF_HB_STATE_FULL_ON;
      }
      else
      {
        /* keep disabled */
        *peHighBeamStateOut = RTE_HLAF_HB_STATE_OFF;
      }
    }
  }
  else
  {
    /* global turn off reason */
    *peHighBeamStateOut = RTE_HLAF_HB_STATE_OFF;
  }
}
