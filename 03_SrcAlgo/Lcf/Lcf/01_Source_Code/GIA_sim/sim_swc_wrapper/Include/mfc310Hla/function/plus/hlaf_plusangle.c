/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plusangle.c

  DESCRIPTION:            HLA plus determine partial HB angle.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_plusangle.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:26CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:06CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:45CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.28 2014/03/26 14:44:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:46 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/03/26 11:27:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:40 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.26 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_plusangle.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusangle.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.25 2014/03/19 16:31:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:05 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.24 2014/03/04 16:52:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:27 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2014/02/20 08:12:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC critical warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 20, 2014 8:12:55 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2013/03/13 17:10:42CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:10:42 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.21 2013/03/11 16:13:20CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:20 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.20 2013/03/08 17:43:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:07 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19 2013/01/28 15:06:17CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eRedReflectorArea
  CHANGE:                 - HLA_t_eHighwayLatPosState
  CHANGE:                 - HLA_t_eHighwayEgoMotionState
  CHANGE:                 - HLA_t_eHighwayOcclusionState
  CHANGE:                 --- Added comments ---  brunnm [Jan 28, 2013 3:06:17 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.18 2013/01/24 16:37:20CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:21 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.17 2013/01/21 13:39:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra/ lint errors
  CHANGE:                 --- Added comments ---  brunnm [Jan 21, 2013 1:39:07 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.16 2013/01/18 07:46:02CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:02 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.15 2012/09/06 06:25:12CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed false reaction of right partial HB on non relevant vehicles
  CHANGE:                 --- Added comments ---  brunnm [Sep 6, 2012 6:25:13 AM CEST]
  CHANGE:                 Change Package : 143736:4 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.14 2012/07/23 12:58:00CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:00 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.13 2012/07/18 07:51:46CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 7:51:46 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.12 2012/04/23 21:02:38CEST Brunn, Marcus (brunnm) 
  CHANGE:                 used si16_delta_x instead of si16_delta_x_lp
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 9:02:38 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.11 2012/04/23 20:19:04CEST Brunn, Marcus (brunnm) 
  CHANGE:                 reduced partial blinding of preceding cars in curvy situations
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 8:19:04 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.10 2012/04/23 15:49:58CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGE:                 - delayed HB turn on after vehicles goes lost
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 3:49:58 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/04/21 15:04:35CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:35 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.8 2012/03/23 11:36:14CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGE:                 time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 23, 2012 11:36:14 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/03/15 16:25:11CET Brunn, Marcus (brunnm) 
  CHANGE:                 added new highway state: HLAR_HIGHWAY_EM_LOW_SPEED
  CHANGE:                 Revision 1.6 2012/03/14 08:52:55CET Brunn, Marcus (brunnm) 
  CHANGE:                 replaced NoVehCnt with NoVehTimer_s
  CHANGE:                 --- Added comments ---  brunnm [Mar 14, 2012 8:52:55 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.5 2012/03/13 10:09:14CET Brunn, Marcus (brunnm) 
  CHANGE:                 check if VehOutermost_Alive is present before using the detailed data
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2012 10:09:14 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.4 2012/02/23 16:42:06CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed some issues for left hand traffic
  CHANGE:                 - increased HB turn on delay when wiper is on stage 6
  CHANGE:                 - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGE:                 - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGE:                 Revision 1.3 2012/02/13 06:22:03CET Brunn, Marcus (brunnm) 
  CHANGE:                 used relevant traffic flag from extended object list
  CHANGE:                 --- Added comments ---  brunnm [Feb 13, 2012 6:22:04 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.2 2012/02/06 15:27:43CET Brunn, Marcus (brunnm) 
  CHANGE:                 turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGE:                 Revision 1.1 2012/01/31 06:43:22CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hlaf_plusangle.h"
 

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
static void HLAPlusAngle_RunStateMachine( /* input */
                                          const HLAFPlusOut_t              *pPlusOut,
                                          const float32                    dtime_s,
                                          const HLAplusData_t              *pPlusData,
                                          const HLAplusHBAng_t             *pHBAngle,
                                          const HLAplusOutermostData_t     *pOutermost,
                                          const HLAplus2ParHBAng_t         *pPar,
                                          const float32                    dHBAng_LP_LeftRight,  /* HBAng_LP_left - HBAng_LP_right */
                                          const eHLAplusHBState_t HBState,
                                          const eHLAplusHeadlamp_t        eHeadlamp,
                                          const HLAFTrafficStyleOut_t      *pTrafficStyle,
                                          /* history */
                                          /* output */
                                          HLAplusHBAngData_t      *pHBAngData
                                        );
static void HLAPlusAngle_CalcMinMaxAng(  /* input */
                                        const eHLAplusHBAngState_t  eHBAng_State,      /* HB angle state */
                                        const HLAplusInputData_t *pPlusIn,
                                        const eHLAplusHeadlamp_t   eHeadlamp,
                                        const HLAplus2ParHBAngMinMax_t *pPar,
                                        const HLAFDecisionOut_t        *pDecOut,
                                        const HLAplusData_t            *pPlusData,
                                        /* history/ output */
                                        HLAplusHBAngMinMax_t       *pDat
                                     );
static void HLAPlusAng_CalcSafetyAng( /* input */
                                      const HLAF_t_RequiredInputs *ps_In,
                                      const eHLAplusHBAngState_t eHBAng_State,      /* HB angle state */
                                      const eHLAplusHeadlamp_t eHeadlamp,
                                      const HLA_t_ObjectList *pObjList,
                                      const HLAplusObject_t *pObjListExt,
                                      const HLAplus2LeftRightParameters_t *pPar,
                                      const HLAFTrafficStyleOut_t *pTrafficStyle,
                                      /* history/ output */
                                      HLAplusSafetyMargin_t *pDat
                                      );
static void HLAPlusAng_CalcRawAng( /* output */
                                   float32  *pHBAng_Raw,
                                   /* input */
                                   const HLAplusHBAng_t        *pHBAngle,
                                   const HLAplusHBAngData_t    *pData,
                                   const HLAplusOutermostData_t *pOutermost,
                                   eHLAplusHeadlamp_t          eHeadlamp,
                                   /* curve angle */
                                   float32 CurveAng,
                                   float32 NoVeh_TargetAng         /* no vehicle: move cut off angle to target angle */
                                   );
static void HLAPlusAng_FilterAng( /* history/ output */
                                  HLAplusHBAngData_t *pData,
                                  /* input */
                                  const HLAplusTurnOffReason_Reason_t TurnOffReason,
                                  const eHLAplusHBState_t HBState,

                                  const HLAplusOutermostData_t *pOutermost,

                                  const HLAplus2ParHBAng_t *pPar,

                                  const eHLAplusHeadlamp_t eHeadlamp,
                                  const HLAFTrafficStyleOut_t *pTrafficStyle
                                  );
static void HLAPlusAng_CalcFilterPar( /* input */
                                      const uint16                    Cycle,
                                      const HLAplus2ParHBAngFilter_t  *pPar,
                                      /* output */
                                      float32 *pAlpha,
                                      float32 *pdAng_min_perCycle,
                                      float32 *pdAng_max_perCycle
                                    );


/* **************************************************************************** 
  Functionname:     HLAPlusAng_CalcFilterPar                  */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusAng_CalcFilterPar( /* input */
                                        const uint16                    Cycle,
                                        const HLAplus2ParHBAngFilter_t  *pPar,
                                        /* output */
                                        float32 *pAlpha,
                                        float32 *pdAng_min_perCycle,
                                        float32 *pdAng_max_perCycle
                                     )
{
  *pAlpha = pPar->Alpha;
  
  if(Cycle <= pPar->Cycles[0])
  {
    *pdAng_min_perCycle = pPar->dAng_min_perCycle[0];
    *pdAng_max_perCycle = pPar->dAng_max_perCycle[0];
  }
  else if(Cycle <= pPar->Cycles[1])
  {
    if(pPar->Cycles[0] != pPar->Cycles[1])
    {
      *pdAng_min_perCycle = pPar->dAng_min_perCycle[0] + (((pPar->dAng_min_perCycle[1] - pPar->dAng_min_perCycle[0])/(pPar->Cycles[1] - pPar->Cycles[0])) * Cycle);
      *pdAng_max_perCycle = pPar->dAng_max_perCycle[0] + (((pPar->dAng_max_perCycle[1] - pPar->dAng_max_perCycle[0])/(pPar->Cycles[1] - pPar->Cycles[0])) * Cycle);
    }
    else
    {
      *pdAng_min_perCycle = pPar->dAng_min_perCycle[0];
      *pdAng_max_perCycle = pPar->dAng_max_perCycle[0];
    }
  }
  else
  {
    *pdAng_min_perCycle = pPar->dAng_min_perCycle[1];
    *pdAng_max_perCycle = pPar->dAng_max_perCycle[1];
  }  
}

/* **************************************************************************** 
  Functionname:     HLAPlusAng_FilterAng                  */ /*!
  @brief            Calc. filtered HB angle
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
  static void HLAPlusAng_FilterAng( /* history/ output */
                                    HLAplusHBAngData_t *pData,
                                    /* input */
                                    const HLAplusTurnOffReason_Reason_t TurnOffReason,
                                    const eHLAplusHBState_t HBState,
                                                                              
                                    const HLAplusOutermostData_t *pOutermost,
                                    
                                    const HLAplus2ParHBAng_t *pPar,
                                    
                                    const eHLAplusHeadlamp_t eHeadlamp,
                                    const HLAFTrafficStyleOut_t *pTrafficStyle
                                  )
{                                         
  float32 Alpha, dAng_min_perCycle, dAng_max_perCycle;
  float32 Ang;
  float32 Sign;
  const float32 HBAng_Raw = pData->Ang_Raw;
  float32 *pHighBeamAngle_Raw = &pData->Ang_Raw;
  float32 *pHighBeamAngle_LP  = &pData->Ang_LP;
  const float32 HBAng_Min_phys = pPar->MinMax.min; /* absolute physical minimum */
  const float32 HBAng_Max_phys = pPar->MinMax.max; /* absolute physical maximum */



  /* mirror object angle for right headlamp */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    Sign = 1.0f;
  }
  else
  {
    /* right headlamp       */
    /* mirror object angles */
    Sign = -1.0f;
  } 
     
 
  /************************************/
  /* select alpha for low pass filter */
  /************************************/  
  if(    (HBState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
      || (HBState == HLA_PLUS_HB_STATE_FULL_2_PART_ON)
      || (HBState == HLA_PLUS_HB_STATE_FULL_2_OFF)
    )
  {
    /*    HB off to Part HB on                  */ 
    /* or full HB on to partial HB on           */
    /* -> move directly to the requested angle  */
    /* max. speed                               */
    Alpha             = 1.0f;
    dAng_min_perCycle = CML_Deg2Rad(90.0f);
    dAng_max_perCycle = CML_Deg2Rad(90.0f);
  }
  else
  {
    /* outermost object available ? */
    if(pOutermost->bVehDet == TRUE)
    {
      /* desired angle moves outwards */ 
      if(    (pData->eState == HLA_PLUS_ANG_MOVE_OUTWARDS)
          && ((Sign * HBAng_Raw) > (Sign * *pHighBeamAngle_LP))
        )
      {
        /* HB angle moves outwards */
        /* fast filter */
        {
          /*    partial HB switched off due to blinding                                      */
          /*    -> slow angle movement (otherwise the spot will blind the vehicle even more) */
          /*    -> fast changeOverLevel                                                      */
          /* OR                                                                              */
          /*    Oncoming detected left from preceding car                                    */
          /*    -> slow angle movement                                                       */
          /*    -> fast changeOverLevel                                                      */
          if(    (TurnOffReason.Bit.dAng2Large  == 1)
              || (TurnOffReason.Bit.OncLeftPrec == 1)
            )
          {
            HLAPlusAng_CalcFilterPar(  /* input */
                                        pData->MoveCnt_Outwards,
                                        &pPar->Filter_Inner,
                                        /* output */
                                        &Alpha,
                                        &dAng_min_perCycle,
                                        &dAng_max_perCycle
                                     );
          }
          /* blinding ? */
          else if(    (pOutermost->bVehDet_Alive == b_TRUE)
                   && (((Sign * pTrafficStyle->NormFactor) * pOutermost->VehOutermost_Alive.f32_ObjectHorAng_rad) > (Sign * *pHighBeamAngle_LP))
                 )
          {
            HLAPlusAng_CalcFilterPar( /* input */
                                      pData->MoveCnt_Outwards,
                                      &pPar->Filter_OuterMax,
                                      /* output */
                                      &Alpha,
                                      &dAng_min_perCycle,
                                      &dAng_max_perCycle
                                   );
          }
          else
          {
            HLAPlusAng_CalcFilterPar( /* input */
                                          pData->MoveCnt_Outwards,
                                          &pPar->Filter_Outer,
                                          /* output */
                                          &Alpha,
                                          &dAng_min_perCycle,
                                          &dAng_max_perCycle
                                       );
          }
        }
      }
      else if(   (pData->eState == HLA_PLUS_ANG_MOVE_INWARDS)
              && ((Sign * HBAng_Raw) < (Sign * *pHighBeamAngle_LP))
             ) 
      {
        /* HB angle moves inwards */
        /* slow filter */

        /* still moving to target angle */
        /* or curve light angle         */
        /* or out of tolerances ?       */      
        {
          /* init cycles              */
          if(pData->InitTargetCnt <= pPar->FastFilterCycleCnt)
          {
            /* follow the same object with high speed */
            HLAPlusAng_CalcFilterPar( /* input */
                                          pData->MoveCnt_Inwards,
                                          &pPar->Filter_Inner_Fast,
                                          /* output */
                                          &Alpha,
                                          &dAng_min_perCycle,
                                          &dAng_max_perCycle
                                        );
          }
          else
          {
            /* normal filter set */
            HLAPlusAng_CalcFilterPar( /* input */
                                          pData->MoveCnt_Inwards,
                                          &pPar->Filter_Inner,
                                          /* output */
                                          &Alpha,
                                          &dAng_min_perCycle,
                                          &dAng_max_perCycle
                                        );
          }
        }
      }
      else
      {
        /* stay at current angle position */
        Alpha             = 0.0f;
        dAng_min_perCycle = 0.0f;
        dAng_max_perCycle = 0.0f;
      }    
    }
    else
    {
      /* no vehicle detected */
                       
      /* slow filter */
      HLAPlusAng_CalcFilterPar( /* input */
                                 pData->StateCnt,
                                 &pPar->Filter_NoVeh,
                                 /* output */
                                 &Alpha,
                                 &dAng_min_perCycle,
                                 &dAng_max_perCycle
                               );
    }
  }
   
 
  /* filter angle */
  Ang =   ((1.0f-Alpha) * *pHighBeamAngle_LP)
        + (Alpha * *pHighBeamAngle_Raw);
  
  /* ensure min/max step size */
  if(*pHighBeamAngle_Raw >= *pHighBeamAngle_LP)
  {
    /* min step size */
    Ang = CML_f_Max(Ang, (*pHighBeamAngle_LP + dAng_min_perCycle));
    /* max step size */
    *pHighBeamAngle_LP = CML_f_MinMax((*pHighBeamAngle_LP - dAng_max_perCycle), (*pHighBeamAngle_LP + dAng_max_perCycle), Ang);
    /* ensure:  (filtered value) <= (raw value) */
    *pHighBeamAngle_LP = CML_f_Min(*pHighBeamAngle_Raw, *pHighBeamAngle_LP);
  } 
  else
  {
    /* *pHighBeamAngle_Raw < *pHighBeamAngle_LP */

    /* min step size */
    Ang = CML_f_Min(Ang, (*pHighBeamAngle_LP - dAng_min_perCycle));
    /* max step size */
    *pHighBeamAngle_LP = CML_f_MinMax((*pHighBeamAngle_LP - dAng_max_perCycle), (*pHighBeamAngle_LP + dAng_max_perCycle), Ang);
    /* ensure:  (filtered value) >= (raw value) */
    *pHighBeamAngle_LP = CML_f_Max(*pHighBeamAngle_Raw, *pHighBeamAngle_LP);
  }   
   
  /* check pHighBeamAngle_LP against physical min./ max. */
  *pHighBeamAngle_LP = CML_f_MinMax(HBAng_Min_phys, HBAng_Max_phys, *pHighBeamAngle_LP);
}


/* **************************************************************************** 
  Functionname:     HLAPlusAng_CalcRawAng               */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusAng_CalcRawAng(/* output */
                                   float32  *pHBAng_Raw,
                                   /* input */
                                   const HLAplusHBAng_t        *pHBAngle,
                                   const HLAplusHBAngData_t    *pData,
                                   const HLAplusOutermostData_t *pOutermost,
                                   eHLAplusHeadlamp_t          eHeadlamp,
                                   /* curve angle */
                                   float32 CurveAng,
                                   float32 NoVeh_TargetAng         /* no vehicle: move cut off angle to target angle */
                                 )
{
  float32 Sign;
  const eHLAplusHBAngState_t eHBAng_State = pData->eState;  /* HB angle state */
  const float32  HBAng_LP                 = pData->Ang_LP;
  /* ~CodeReview ~ID:6499f4f6914e3d5b1236f3d2f109d14e ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:Use const */
  float32  HBAng_Safety_Min = pData->SafetyMargin.Ang_Min;  /* absolute angle */
  float32  HBAng_Safety_Max = pData->SafetyMargin.Ang_Max;  /* absolute angle */


  /* mirror object angle for right headlamp */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    Sign = 1.0f;
  }
  else
  {
    /* right headlamp       */
    /* mirror object angles */
    Sign = -1.0f;
  }  

  /* set outermost angle with safety margin */
  /* outermost track available ? */
  if(pOutermost->bVehDet == TRUE)
  {
    /* lost time of outermost track == 0 */
    if(pOutermost->VehOutermost.ui8_lost_time == 0)
    {
      /* track is alive */
      *pHBAng_Raw = Sign * CML_f_MinMax((Sign*HBAng_Safety_Min), (Sign*HBAng_Safety_Max), (Sign*pOutermost->AngOutermostPred));
    }
    else
    {
      /* track is not alive */
      *pHBAng_Raw = HBAng_Safety_Min;
    }
  }
  else
  {
    /* no vehicle detected */
    /* keep old HB angle for some cycles */
    if(    (eHBAng_State == HLA_PLUS_ANG_LOST_TARGET)
        || (eHBAng_State == HLA_PLUS_ANG_KEEP_HBANG)
      )
    {
      /* keep old HB angle */
      *pHBAng_Raw = HBAng_LP;
    }  
    /* close gap */
    else if(eHBAng_State == HLA_PLUS_ANG_CLOSE_GAP)
    {
      /* move to gap = 0 */
      *pHBAng_Raw = NoVeh_TargetAng;
    }
    else if(eHBAng_State == HLA_PLUS_ANG_MOVE_2_CURVEANG)
    {
      /* move to curve angle            */
      /* -> ensure that no gap appears  */
      if(pHBAngle->Left.FullHBCutOffAng > pHBAngle->Right.FullHBCutOffAng)
      {
        /* move to curve angle  */
        *pHBAng_Raw = 0.5f * (pHBAngle->Left.FullHBCutOffAng +  pHBAngle->Right.FullHBCutOffAng);
      }
      else
      {
        *pHBAng_Raw = CurveAng;
      }
    }
    else
    {
      /* eHBAng_State == MOVING_CURVEANG */
      /* eHBAng_State == FOLLOW_CURVEANG */
      /* 3. move to curve angle */
      *pHBAng_Raw = CurveAng;
    }
  }

  /* check raw angle against min/max raw angle */
  *pHBAng_Raw = CML_f_MinMax(pData->MinMax.HBAng_Min, pData->MinMax.HBAng_Max, *pHBAng_Raw);

}


/* **************************************************************************** 
  Functionname:     HLAPlusAng_CalcSafetyAng                      */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusAng_CalcSafetyAng( /* input */
                                      const HLAF_t_RequiredInputs *ps_In,
                                      const eHLAplusHBAngState_t eHBAng_State,      /* HB angle state */
                                      const eHLAplusHeadlamp_t eHeadlamp,
                                      const HLA_t_ObjectList *pObjList,
                                      const HLAplusObject_t *pObjListExt, 
                                      const HLAplus2LeftRightParameters_t *pPar,
                                      const HLAFTrafficStyleOut_t *pTrafficStyle,
                                      /* history/ output */
                                      HLAplusSafetyMargin_t *pDat
                                    )
{
  float32 Ang_Min, Ang_Max;   /* absolute angles */
  float32 Ang_Outermost; /* outermost object angle */
  float32 Ang;
  float32 dAng;
  uint32  i;
  float32 Sign;
  

  /* mirror object angle for right headlamp */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    Sign = 1.0f;
  }
  else
  {
    /* right headlamp       */
    /* mirror object angles */
    Sign = -1.0f;
  }
 

  /* relevant vehicle detected ? */
  if(pObjListExt->numRelevantVehicles > 0)
  {
    float32 MinSafety_Onc, MinSafety_Prec;
        
    /* oncoming vehicles */
    if(ps_In->s_Sig.ps_CaliOnline->f32_OdoCali_m > pPar->HBAng_Onc.SafetyMargin.minSafety_CaliOdo_m[1])
    {
      MinSafety_Onc = pPar->HBAng_Onc.SafetyMargin.minSafety[1];
    }  
    else if(ps_In->s_Sig.ps_CaliOnline->f32_OdoCali_m > pPar->HBAng_Onc.SafetyMargin.minSafety_CaliOdo_m[0])
    {
      /* ~CodeReview ~ID:9457b1a096115e192a3c52516b509cdd ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
      float32 MinSafety_m = (pPar->HBAng_Onc.SafetyMargin.minSafety[1] - pPar->HBAng_Onc.SafetyMargin.minSafety[0])/(pPar->HBAng_Onc.SafetyMargin.minSafety_CaliOdo_m[1] - pPar->HBAng_Onc.SafetyMargin.minSafety_CaliOdo_m[0]);

      MinSafety_Onc = pPar->HBAng_Onc.SafetyMargin.minSafety[0] + (MinSafety_m * (ps_In->s_Sig.ps_CaliOnline->f32_OdoCali_m - pPar->HBAng_Onc.SafetyMargin.minSafety_CaliOdo_m[0])); 
    }
    else
    {
      MinSafety_Onc = pPar->HBAng_Onc.SafetyMargin.minSafety[0];
    }
    /* preceding vehicles */
    if(ps_In->s_Sig.ps_CaliOnline->f32_OdoCali_m > pPar->HBAng_Prec.SafetyMargin.minSafety_CaliOdo_m[1])
    {
      MinSafety_Prec = pPar->HBAng_Prec.SafetyMargin.minSafety[1];
    }  
    else if(ps_In->s_Sig.ps_CaliOnline->f32_OdoCali_m > pPar->HBAng_Prec.SafetyMargin.minSafety_CaliOdo_m[0])
    {
      /* ~CodeReview ~ID:65c6ef038b2e3a73e2f5055afaf2f2a8 ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
      float32 MinSafety_m = (pPar->HBAng_Prec.SafetyMargin.minSafety[1] - pPar->HBAng_Prec.SafetyMargin.minSafety[0])/(pPar->HBAng_Prec.SafetyMargin.minSafety_CaliOdo_m[1] - pPar->HBAng_Prec.SafetyMargin.minSafety_CaliOdo_m[0]);

      MinSafety_Prec = pPar->HBAng_Prec.SafetyMargin.minSafety[0] + (MinSafety_m * (ps_In->s_Sig.ps_CaliOnline->f32_OdoCali_m - pPar->HBAng_Prec.SafetyMargin.minSafety_CaliOdo_m[0]));
    }
    else
    {
      MinSafety_Prec = pPar->HBAng_Prec.SafetyMargin.minSafety[0];
    }


    /* go through all vehicle lights and find min/ max safety angle (absolute angle) */
    Ang_Min = -999.0f;
    Ang_Max = -999.0f;
    Ang_Outermost =  -999.0f;

    for(i= 0; i< pObjList->ui32_NumVehicles; i++)
    {
      float32 ObjAng_norm_mirrored;
      float32 ObjAng_norm;
      const HLAplus2ParHBAngSafetyMargin_t *pPar_Safety;
      const HLAplusObjectData_t *pObjExt = &pObjListExt->Obj[i];
      float32 MinSafety;
      
      
      /* relevant traffic ? */
      if(pObjExt->Status.isRelevantTraffic == 1)
      {
        /* select parameter set */
        if(pObjList->as_Object[i].s_Status.isVehicleOncoming == 1)
        {
          pPar_Safety = &pPar->HBAng_Onc.SafetyMargin;
          MinSafety   = MinSafety_Onc;
        }
        else
        {
          pPar_Safety = &pPar->HBAng_Prec.SafetyMargin;
          MinSafety   = MinSafety_Prec;
        }

        /* mirror object angle for right headlamp */
        ObjAng_norm          = pTrafficStyle->NormFactor * pObjList->as_Object[i].f32_ObjectHorAng_rad;
        ObjAng_norm_mirrored = Sign * ObjAng_norm;
        if(ObjAng_norm_mirrored > Ang_Outermost)
        {
          Ang_Outermost = CML_f_Max(Ang_Outermost, ObjAng_norm_mirrored);
        }
             

        /************************/
        /* minimal safety angle */
        /************************/

        /* absolute min. safety margin */
        Ang = ObjAng_norm_mirrored + MinSafety;
        Ang_Min = CML_f_Max(Ang, Ang_Min);
        

        /* safety angle depending on object yaw angle */
        if(ObjAng_norm < pPar_Safety->Yaw[1])
        {
          /* ~CodeReview ~ID:2e0f576eb325471e4b2bae0f51c0cf62 ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:Suggest to add assertion for delta yaw != 0 */
          /* ~CodeReview ~ID:0e0cbc578225ae689a3c2a4cdbda0b21 ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
          dAng = pPar_Safety->Yaw_Safety_Min[0] + (((pPar_Safety->Yaw_Safety_Min[1]-pPar_Safety->Yaw_Safety_Min[0])/(pPar_Safety->Yaw[1]-pPar_Safety->Yaw[0]))*(ObjAng_norm - pPar_Safety->Yaw[0]));
        }
        else
        {
          /* ~CodeReview ~ID:ff073519d8bfb6c6413fc8a7a9803b0f ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
          dAng = pPar_Safety->Yaw_Safety_Min[1] + (((pPar_Safety->Yaw_Safety_Min[2]-pPar_Safety->Yaw_Safety_Min[1])/(pPar_Safety->Yaw[2]-pPar_Safety->Yaw[1]))*(ObjAng_norm - pPar_Safety->Yaw[1]));
        }
        Ang  = dAng + ObjAng_norm_mirrored;
        Ang_Min = CML_f_Max(Ang, Ang_Min);


        /* safety angle depending on vehicle distance */
        if(   (pObjList->as_Object[i].s_Status.isVehicleAhead == 1)
           && (pObjList->as_Object[i].s_Status.isTrackedInPair == 1) 
          )
        {
          /* trust distance from pairing */
          float32 MinObjDist = ps_In->s_Sig.ps_MotionState->f32_Speed * pPar_Safety->Dist_MinTime;
          /* ~CodeReview ~ID:20e1da08dd91ef3188093513361dd6dc ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:General remark: Magic numbers, use defined types! */
          float32 ObjDist = 0.005f * (pObjList->as_Object[i].s_ObjectPos_xw.ui16_distMin_cm + pObjList->as_Object[i].s_ObjectPos_xw.ui16_distMax_cm);
          float32 Dist;

          MinObjDist = CML_f_MinMax(pPar_Safety->Dist_Min, pPar_Safety->Dist_Max, MinObjDist);
          
          Dist = CML_f_MinMax(MinObjDist, pPar_Safety->Dist_Max, ObjDist); 
          
          dAng = (pPar_Safety->Dist_SafteyWidth)/ CML_f_Max(1.0f, Dist);
          Ang  = dAng + ObjAng_norm_mirrored;
          Ang_Min = CML_f_Max(Ang_Min, Ang);
        }
              

        /************************/
        /* maximal safety angle */
        /************************/
        if(ObjAng_norm < pPar_Safety->Yaw[1])
        {
          /* ~CodeReview ~ID:6ec019f65389ae5ea07cae3abf5fa939 ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
          dAng = pPar_Safety->Yaw_Safety_Max[0] + (((pPar_Safety->Yaw_Safety_Max[1]-pPar_Safety->Yaw_Safety_Max[0])/(pPar_Safety->Yaw[1]-pPar_Safety->Yaw[0]))*(ObjAng_norm - pPar_Safety->Yaw[0]));
        }
        else
        {
          /* ~CodeReview ~ID:206389382b0c0f298dbd1e73a1386f41 ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
          dAng = pPar_Safety->Yaw_Safety_Max[1] + (((pPar_Safety->Yaw_Safety_Max[2]-pPar_Safety->Yaw_Safety_Max[1])/(pPar_Safety->Yaw[2]-pPar_Safety->Yaw[1]))*(ObjAng_norm - pPar_Safety->Yaw[1]));
        }
        dAng             = CML_f_Min(dAng, pPar_Safety->maxSafety);
        Ang              = ObjAng_norm_mirrored + dAng; 
        Ang_Max = CML_f_Max(Ang, Ang_Max);
      }
    } /* end for loop */
 
    pDat->Ang_Min = Sign * Ang_Min;
    pDat->Ang_Max = Sign * Ang_Max;


    /* add initial safety angle(relative angle)                                */
    /* when the object is first detected or the partial HB will be switched on */  
    if(eHBAng_State == HLA_PLUS_ANG_INIT_TARGET)
    {
      pDat->Safety_InitialCnt = (pPar->HBAng_Prec.SafetyMargin.InitialSafetyCnt_0 + pPar->HBAng_Prec.SafetyMargin.InitialSafetyCnt_1);
    }

    if(pDat->Safety_InitialCnt > 0)
    {
      float32 factor;
      
      if(pDat->Safety_InitialCnt > pPar->HBAng_Prec.SafetyMargin.InitialSafetyCnt_1)
      {
        /* keep InitialSafety for InitialSafetyCnt_0 cycles */
        factor = 1.0f;
      }
      else
      {
        /* transition from InitialSafety to zero */
        /* ~CodeReview ~ID:e5e8025186ca5bf2fc49413e128239af ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:division by zero not checked */
        factor = (float32)pDat->Safety_InitialCnt/ (float32)pPar->HBAng_Prec.SafetyMargin.InitialSafetyCnt_1;
      }      
      pDat->Safety_InitialCnt = pDat->Safety_InitialCnt - 1;
      pDat->Ang_Min = pDat->Ang_Min + (Sign * (pPar->HBAng_Prec.SafetyMargin.InitialSafety * factor));
      pDat->Ang_Min = Sign * CML_f_Min((Sign * pDat->Ang_Min),(Sign * pDat->Ang_Max));
    }
  }
  else
  {
    /* no vehicles detected */
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlusAngle_CalcMinMaxAng                      */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusAngle_CalcMinMaxAng( /* input */
                                       const eHLAplusHBAngState_t eHBAng_State,      /* HB angle state */
                                       const HLAplusInputData_t *pPlusIn,
                                       const eHLAplusHeadlamp_t  eHeadlamp,
                                       const HLAplus2ParHBAngMinMax_t *pPar,
                                       const HLAFDecisionOut_t        *pDecOut,
                                       const HLAplusData_t            *pPlusData,
                                       /* history/ output */
                                       HLAplusHBAngMinMax_t      *pDat
                                     )
{
  float32 min, max;

  /* min/ max values could be changed */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    /* left headlamp */
    min = CML_f_Max(pPar->min, (pPlusIn->CurveLightAngle_left - pPar->CurveTol));
    /* the curve light could not reduce the existing light (Ang_LP) */
    min = CML_f_Min(min, pPlusData->HBAngle.Left.Ang_LP);

    max = pPar->max;
  }
  else
  {
    /* right headlamp */
    min = pPar->min;
    max = CML_f_Min(pPar->max, (pPlusIn->CurveLightAngle_right + pPar->CurveTol));

    if(    (pDecOut->Motorway.eStateInt == RTE_HLAF_MTWY_MOTORWAY)
        && (pPlusData->Region.RegionPreced_left.eRegion == HLA_PLUS_NO_OBJ)
      )
    {
      /* motorway and                                             */
      /* only oncoming vehicles detected (no preceding vehicle)   */
      /* ensure: right partial HB angle < left curve light angle  */
      max = CML_f_Min(max, pPlusIn->CurveLightAngle_left);
    }
    /* the curve light could not reduce the existing light (Ang_LP) */
    max = CML_f_Max(max, pPlusData->HBAngle.Right.Ang_LP);
  }
   

  /* reinit filter ? */
  if(eHBAng_State == HLA_PLUS_ANG_INIT_TARGET)
  {
    pDat->eFilterState = HLA_PLUS_ANG_MINMAX_INIT;
  }
  
    
  /* filter state machine */
  switch(pDat->eFilterState)
  {
    case HLA_PLUS_ANG_MINMAX_INIT:
      pDat->HBAng_Min = min;
      pDat->HBAng_Max = max;
      pDat->eFilterState = HLA_PLUS_ANG_MINMAX_RUNNING;
      break;
    case HLA_PLUS_ANG_MINMAX_IDLE:
      /* J.Häfer: No Possible Side Effect */
      /* PRQA S 3415 6 */
      if(    (CML_f_Abs(min - pDat->HBAng_Min) > pPar->Filter_Tol_Start)
          || (CML_f_Abs(max - pDat->HBAng_Max) > pPar->Filter_Tol_Start)
        )
      {
        pDat->eFilterState = HLA_PLUS_ANG_MINMAX_RUNNING;
      }
      break;
    case HLA_PLUS_ANG_MINMAX_RUNNING:
      pDat->HBAng_Min = (pPar->Filter_Alpha * min) + ((1.0f-pPar->Filter_Alpha)*pDat->HBAng_Min);
      pDat->HBAng_Max = (pPar->Filter_Alpha * max) + ((1.0f-pPar->Filter_Alpha)*pDat->HBAng_Max);
      /* stop filter ? */
      /* J.Häfer: No Possible Side Effect */
      /* PRQA S 3415 6 */
      if(     (CML_f_Abs(min - pDat->HBAng_Min) < pPar->Filter_Tol_Stop)
          &&  (CML_f_Abs(max - pDat->HBAng_Max) < pPar->Filter_Tol_Stop)
        )
      {
        pDat->eFilterState = HLA_PLUS_ANG_MINMAX_IDLE;
      }
      break;
    default:
      pDat->eFilterState = HLA_PLUS_ANG_MINMAX_INIT;
      break;
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlusAngle_RunStateMachine                          */ /*!
  @brief            State machine for High beam angle movement.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusAngle_RunStateMachine(  /* input */
                                           const HLAFPlusOut_t              *pPlusOut,
                                           const float32                    dtime_s,
                                           const HLAplusData_t              *pPlusData,
                                           const HLAplusHBAng_t             *pHBAngle,
                                           const HLAplusOutermostData_t     *pOutermost,
                                           const HLAplus2ParHBAng_t         *pPar,
                                           const float32                    dHBAng_LP_LeftRight,  /* HBAng_LP_left - HBAng_LP_right */
                                           const eHLAplusHBState_t          HBState,
                                           const eHLAplusHeadlamp_t         eHeadlamp,
                                           const HLAFTrafficStyleOut_t      *pTrafficStyle,
                                           /* history */
                                           /* output */
                                           HLAplusHBAngData_t      *pHBAngData
                                        )
{
  float32 Sign;
  float32 HBAng_Raw = pHBAngData->Ang_Raw;
  float32 HBAng_LP  = pHBAngData->Ang_LP;
  float32 HBAng_max;
  /* ~CodeReview ~ID:04f0c2c61bb85741e37219320a2cdf69 ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:Use const */
  /* ~CodeReview ~ID:23f253d8c15a320c17d9ae2dbfa4706d ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
  float32 dAngTol = CML_Deg2Rad(0.05f);
  float32 delta_xTol = 1.0f;
  eHLAplusHBAngState_t eStatePrev = pHBAngData->eState;
  

  /* mirror all angles for right headlamp */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    /* left headlamp */
    Sign = 1.0f;
    HBAng_max = pPar->MinMax.max;
  }
  else
  {
    /* right headlamp     */
    /* mirror all angles  */
    Sign = -1.0f;
    HBAng_max = -pPar->MinMax.min;
  }

  /* HB off -> full HB           */
  /* -> follow curve angle !!!   */
  if(HBState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
  {
    pHBAngData->eState = HLA_PLUS_ANG_FOLLOW_CURVEANG;
  }

  /* vehicle detected ? */
  if(pOutermost->bVehDet == TRUE)
  {
    pHBAngData->NoVehTimer_s = 0.0f;
 
    /* vehicle detected */
    /* left headlamp    */
    switch(pHBAngData->eState)
    {
      case HLA_PLUS_ANG_INIT:
      case HLA_PLUS_ANG_CLOSE_GAP:
      case HLA_PLUS_ANG_MOVE_2_CURVEANG:
      case HLA_PLUS_ANG_FOLLOW_CURVEANG:
        /* vehicle detected the first time */
        pHBAngData->eState = HLA_PLUS_ANG_INIT_TARGET;
        /* ~CodeReview ~ID:b2eb485c8785a9d50d3a857bb0292ed9 ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:General remark: use U for unsigned integer values. */
        pHBAngData->TargetReachedCnt = 0;
        pHBAngData->MoveCnt_Inwards  = 0;
        pHBAngData->MoveCnt_Outwards = 0;
        pHBAngData->InitTargetCnt    = 0;
        break;

      case HLA_PLUS_ANG_LOST_TARGET:
      case HLA_PLUS_ANG_KEEP_HBANG:
        /* vehicle detected the first time */
        pHBAngData->eState = HLA_PLUS_ANG_RESUME_TARGET;
        pHBAngData->TargetReachedCnt = 0;
        pHBAngData->MoveCnt_Inwards  = 0;
        pHBAngData->MoveCnt_Outwards = 0;
        pHBAngData->InitTargetCnt    = 0;
        break;

      case HLA_PLUS_ANG_INIT_TARGET:
      case HLA_PLUS_ANG_RESUME_TARGET:
        /* check previous state */
        if(pHBAngData->eStatePrev == HLA_PLUS_ANG_MOVE_INWARDS)
        {
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_INWARDS;
        }
        else if(pHBAngData->eStatePrev == HLA_PLUS_ANG_MOVE_OUTWARDS)
        {
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_OUTWARDS;
        }
        /* check track movement */
        else if((Sign * pOutermost->VehOutermost.si16_delta_x) > 0)
        {
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_INWARDS;
        }
        else
        {
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_OUTWARDS;
        }
        pHBAngData->TargetReachedCnt = 0;
        pHBAngData->MoveCnt_Inwards  = 0;
        pHBAngData->MoveCnt_Outwards = 0;
        pHBAngData->InitTargetCnt    = 0;
        break;

      case HLA_PLUS_ANG_MOVE_INWARDS:
      case HLA_PLUS_ANG_MOVE_OUTWARDS:
        /* increment cycles since last HLA_PLUS_ANG_INIT_TARGET state */
        if(pHBAngData->InitTargetCnt < UI16_T_MAX)
        {
          pHBAngData->InitTargetCnt = pHBAngData->InitTargetCnt + 1;
        }      

        /* partial HB will be switched on ? */
        if(    (HBState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
            || (HBState == HLA_PLUS_HB_STATE_FULL_2_PART_ON)
          )
        {
          /* partial HB will be switched on in the next cycle */
          pHBAngData->eState = HLA_PLUS_ANG_INIT_TARGET;
        }

        /* target is moving */
        else
        {
          /* increment/ decrement MoveCnt_Inner/ Outer */
          if(pHBAngData->eState == HLA_PLUS_ANG_MOVE_INWARDS)
          {
            /* inner direction */
            if(pHBAngData->MoveCnt_Inwards < UI8_T_MAX)
            {
              pHBAngData->MoveCnt_Inwards = pHBAngData->MoveCnt_Inwards + 1;
            }
            if(pHBAngData->MoveCnt_Outwards > 0)
            {
              pHBAngData->MoveCnt_Outwards = pHBAngData->MoveCnt_Outwards - 1;
            }
          }
          else if(pHBAngData->eState == HLA_PLUS_ANG_MOVE_OUTWARDS)
          {
            /* outer direction */
            if(pHBAngData->MoveCnt_Outwards < UI8_T_MAX)
            {
              pHBAngData->MoveCnt_Outwards = pHBAngData->MoveCnt_Outwards + 1;
            }
            if(pHBAngData->MoveCnt_Inwards > 0)
            {
              pHBAngData->MoveCnt_Inwards = pHBAngData->MoveCnt_Inwards - 1;
            }
          }
          else
          {
            /* Do nothing */
          }

          /* desired angle moves outwards */ 
          if(   ((Sign * HBAng_Raw) > ((Sign * HBAng_LP) + dAngTol))
                /* outermost vehicle moves outwards ? */
             || ((Sign * pOutermost->VehOutermost_Alive.si16_delta_x) < (-delta_xTol))
                /* blinding ? */
             || (    (pOutermost->bVehDet_Alive == b_TRUE)
                  && (((Sign * pTrafficStyle->NormFactor) * pOutermost->VehOutermost_Alive.f32_ObjectHorAng_rad) > ((Sign * HBAng_LP) + dAngTol))
                  && (((Sign * HBAng_LP) + dAngTol) < (Sign * HBAng_max))
                )
            )
          {
            if(pHBAngData->eState == HLA_PLUS_ANG_MOVE_OUTWARDS)
            {
              /* reset inwards counter when the moving direction is outwards and the object is moving outwards */  
              pHBAngData->MoveCnt_Inwards  = 0;
            }
            else
            {
              /* current state = moving inwards */
              /* -> change to inwards ?         */
              pHBAngData->MoveCnt_Outwards = pHBAngData->MoveCnt_Outwards + 2;
              
              if(    (pHBAngData->MoveCnt_Outwards > 3)
                     /* blinding ? */
                  || (    (pOutermost->bVehDet_Alive == b_TRUE)
                       && (((Sign*pTrafficStyle->NormFactor) * pOutermost->VehOutermost_Alive.f32_ObjectHorAng_rad) > ((Sign * HBAng_LP) + dAngTol))
                       && (((Sign * HBAng_LP) + dAngTol) < (Sign * HBAng_max))
                     )
                )
              {
                /* moving direction changes from inwards to outwards */
                pHBAngData->MoveCnt_Inwards  = 0;
                pHBAngData->MoveCnt_Outwards = 0;
                /* init cycle finished because the target moves to other direction */
                pHBAngData->InitTargetCnt = UI16_T_MAX;
                pHBAngData->eState = HLA_PLUS_ANG_MOVE_OUTWARDS;
              }
            }
          }
          /* desired angle moves inwards */ 
          else if((Sign * HBAng_Raw) < ((Sign * HBAng_LP) - dAngTol))
          {
            if(pHBAngData->eState == HLA_PLUS_ANG_MOVE_INWARDS)
            {
              /* reset outwards counter when the moving direction is inwards and the object is moving inwards */
              pHBAngData->MoveCnt_Outwards  = 0;
            }
            else
            {
              /* current state = moving outwards */
              /* -> change to inwards ?          */
              pHBAngData->MoveCnt_Inwards = pHBAngData->MoveCnt_Inwards + 2;

              if(pHBAngData->MoveCnt_Inwards > 8)
              {
                /* moving direction changes from outwards to inwards */
                pHBAngData->MoveCnt_Inwards  = 0;
                pHBAngData->MoveCnt_Outwards = 0;
                /* init cycle finished because the target moves to other direction */
                pHBAngData->InitTargetCnt = UI16_T_MAX;
                pHBAngData->eState = HLA_PLUS_ANG_MOVE_INWARDS;
              }
            }
            
          }
          else
          {
            /* Do nothing */
          }
        }
        break;

      case HLA_PLUS_ANG_LOCKED_TARGET:
        /* reset reached counter */
        pHBAngData->TargetReachedCnt = 0;

        /* increment cycles since last HLA_PLUS_ANG_INIT_TARGET state */
        if(pHBAngData->InitTargetCnt < UI16_T_MAX)
        {
          pHBAngData->InitTargetCnt = pHBAngData->InitTargetCnt + 1;
        }

        /* target is moving outwards ? */
        if(    ((Sign * HBAng_Raw) > ((Sign * (HBAng_LP + pPar->HBAng_Tol_Outer)) + dAngTol))
               /* blinding ? */
            || (    (pOutermost->bVehDet_Alive == b_TRUE)
                 && (((Sign * pTrafficStyle->NormFactor) * pOutermost->VehOutermost_Alive.f32_ObjectHorAng_rad) > ((Sign * HBAng_LP) + dAngTol))
                 && (((Sign * HBAng_LP) + dAngTol) < (Sign * HBAng_max))
               )
          )
        {
          if(pHBAngData->MoveCnt_Outwards < UI8_T_MAX)
          {
            pHBAngData->MoveCnt_Outwards = pHBAngData->MoveCnt_Outwards + 1;
          }
        }
        /* moving inwards */
        else if((Sign * HBAng_Raw) < ((Sign * (HBAng_LP + pPar->HBAng_Tol_Inner)) - dAngTol))
        {
          if(pHBAngData->MoveCnt_Inwards < UI8_T_MAX)
          {
            pHBAngData->MoveCnt_Inwards = pHBAngData->MoveCnt_Inwards + 1;
          }
        }
        else
        {
          pHBAngData->MoveCnt_Inwards = 0;
          pHBAngData->MoveCnt_Outwards = 0;
        }

        /* partial HB will be switched on ? */
        if(    (HBState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
            || (HBState == HLA_PLUS_HB_STATE_FULL_2_PART_ON)
          )
        {
          /* partial HB will be switched on in the next cycle */
          pHBAngData->eState = HLA_PLUS_ANG_INIT_TARGET;
        }
        /* target is moving ... */
        /* outwards */
        else if(   (pHBAngData->MoveCnt_Outwards > 3)
                   /* blinding ? */
                || (    (pOutermost->bVehDet_Alive == b_TRUE)
                     && (((Sign * pTrafficStyle->NormFactor) * pOutermost->VehOutermost_Alive.f32_ObjectHorAng_rad) > ((Sign * HBAng_LP) + dAngTol))
                     && (((Sign * HBAng_LP) + dAngTol) < (Sign * HBAng_max))
                   )
               )  
        {
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_OUTWARDS;
        }
        /* inwards */
        else if(pHBAngData->MoveCnt_Inwards > 8)
        {
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_INWARDS;
        }
        /* target still locked */
        else
        {
          pHBAngData->eState = HLA_PLUS_ANG_LOCKED_TARGET;
        }
        break;

      default:
        /* Error */
        pHBAngData->eState = HLA_PLUS_ANG_INIT;     
        break;
    }
  }
  else
  {
    /* no vehicle detected */
    pHBAngData->TargetReachedCnt  = 0;
    pHBAngData->MoveCnt_Inwards   = 0;
    pHBAngData->MoveCnt_Outwards  = 0;
    pHBAngData->InitTargetCnt     = 0;
    
    /* increment no vehicle timer */
    pHBAngData->NoVehTimer_s += dtime_s;
    

    switch(pHBAngData->eState)
    {
      case HLA_PLUS_ANG_INIT:
        pHBAngData->eState = HLA_PLUS_ANG_FOLLOW_CURVEANG;
        break;

      case HLA_PLUS_ANG_INIT_TARGET:
      case HLA_PLUS_ANG_RESUME_TARGET:
      case HLA_PLUS_ANG_MOVE_INWARDS:
      case HLA_PLUS_ANG_MOVE_OUTWARDS:
      case HLA_PLUS_ANG_LOCKED_TARGET:
        /* left partial HB off and right partial HB on          */
        /* -> keep HB angle until HB will be switched on or off */
        if(   (    (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
                || (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
                || (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
              )
           && (    (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_PART_ON)
                || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
                || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_FULL_2_PART_ON)
              )
          )
        {
          /* keep current HB angle */
          pHBAngData->eState = HLA_PLUS_ANG_KEEP_HBANG;
          /* init delay counter */
          /* after HB switched on or off                                    */
          /* -> stay for min. time (=DelayCnt) at current HB angle position */  
          /* ~CodeReview ~ID:d49363fc2de7019705f3177b8a3d02be ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
          pHBAngData->DelayCnt = 33;
        }
        else
        {
          /* target lost */
          pHBAngData->eState = HLA_PLUS_ANG_LOST_TARGET;
        }
        break;
      
      case HLA_PLUS_ANG_KEEP_HBANG:
        /* keep HB angle */
        if(    (pPlusOut->eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
            || (pPlusOut->eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON)
          )
        {
          /* after HB switched on or off                                    */
          /* -> stay for min. time (=DelayCnt) at current HB angle position */  
          /* decrement delay counter                                        */
          if(pHBAngData->DelayCnt > 0)
          {
            pHBAngData->DelayCnt = pHBAngData->DelayCnt - 1;
          }
          else
          {
            /* close gap */
            pHBAngData->eState = HLA_PLUS_ANG_CLOSE_GAP;
          }
        }
        break;
  
      case HLA_PLUS_ANG_LOST_TARGET:
        if(pHBAngData->StateCnt > pPar->NoVeh_KeepHBAng_Cnt)
        {
          /* gap closed ? */
          if(    (CML_f_Abs(dHBAng_LP_LeftRight) < pPar->HBAng_Tol_Target)
              || (dHBAng_LP_LeftRight <= 0)
            )
          {
            /* move to curve angle */
            pHBAngData->eState = HLA_PLUS_ANG_MOVE_2_CURVEANG;
          }
          else
          {
            /* still closing the gap */
            pHBAngData->eState = HLA_PLUS_ANG_CLOSE_GAP;
          }
        }
        break;

      case HLA_PLUS_ANG_CLOSE_GAP:
        /* gap closed ? */
        if(    (CML_f_Abs(dHBAng_LP_LeftRight) < pPar->HBAng_Tol_Target)
            || (dHBAng_LP_LeftRight <= 0)
          )
        {
          /* move to curve angle */
          pHBAngData->eState = HLA_PLUS_ANG_MOVE_2_CURVEANG;
        }
        break;

      case HLA_PLUS_ANG_MOVE_2_CURVEANG:
        /* left AND right HB angle reached curve angle ? */
        /* J.Häfer: No Possible Side Effect */
        /* PRQA S 3415 6 */
        if(    ((CML_f_Abs(pHBAngle->Left.Ang_LP  - pHBAngle->Left.FullHBCutOffAng)  < pPar->HBAng_Tol_Target))
            && ((CML_f_Abs(pHBAngle->Right.Ang_LP - pHBAngle->Right.FullHBCutOffAng) < pPar->HBAng_Tol_Target))
          )
        {
          pHBAngData->eState = HLA_PLUS_ANG_FOLLOW_CURVEANG;
        }
        break;

      case HLA_PLUS_ANG_FOLLOW_CURVEANG:
        /* ~CodeReview ~ID:68a2e55faf0bce0744fede59ad334924 ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:Is it intentionaly to set the same state? */
        pHBAngData->eState = HLA_PLUS_ANG_FOLLOW_CURVEANG;
        break;

      default:
        /* Error */
        pHBAngData->eState = HLA_PLUS_ANG_INIT;
        break;
    }    
  }

  /* state changed -> reset State Counter     */
  /*   else        -> increment state counter */
  if(pHBAngData->eState != eStatePrev)
  {
    pHBAngData->StateCnt = 0;
  }
  else
  {
    if(pHBAngData->StateCnt < UI16_T_MAX)
    {
      pHBAngData->StateCnt++;
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlusAngle                                     */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAPlusAngle(/* input */
                  const HLAFData_t              *pFData,
                  const HLAF_t_RequiredInputs   *ps_In,
                  const HLAplusParameters_t     *pPar,
                  const HLA_t_ObjectList        *pObjList,
                  const HLAplusInputData_t      *pPlusInput,
                  /* output/ history */  
                  HLAplusData_t                 *pData
                )
{
  const HLAplus2ParHBAng_t  *pPar_left;
  const HLAplus2ParHBAng_t  *pPar_right;
  eHLAplusHBAngState_t      eStatePrev_left  = pData->HBAngle.Left.eState;
  eHLAplusHBAngState_t      eStatePrev_right = pData->HBAngle.Right.eState;


  /* set parameter depending on vehicle type (preceding or oncoming) */
  if(    (   (pData->Outermost.Left.bVehDet == TRUE)
          && (pData->Outermost.Left.VehOutermost.s_Status.isVehicleAhead == 1)
         ) 
      || (   (pData->Outermost.Left.bVehDet == FALSE)
          && (pData->Outermost.PrevVeh_left.VehOutermost.s_Status.isVehicleAhead == 1)
         )
    )
  {
    /* preceding vehicle */
    pPar_left = &pPar->Left.HBAng_Prec;
  }
  else
  {
    /* oncoming vehicle */
    pPar_left = &pPar->Left.HBAng_Onc;
  }
  if(    (   (pData->Outermost.Right.bVehDet == TRUE)
          && (pData->Outermost.Right.VehOutermost.s_Status.isVehicleAhead == 1)
         ) 
      || (   (pData->Outermost.Right.bVehDet == FALSE)
          && (pData->Outermost.PrevVeh_right.VehOutermost.s_Status.isVehicleAhead == 1)
         )
    )
  {
    /* preceding vehicle */
    pPar_right = &pPar->Right.HBAng_Prec;
  }
  else
  {
    /* oncoming vehicle */
    pPar_right = &pPar->Right.HBAng_Onc;
  }
  
  
  /* set curve light angle */
  pData->HBAngle.Left.FullHBCutOffAng  = (pPlusInput->CurveLightAngle_left  + ps_In->s_Par.ps_HlaPar->Headlight.FullHBDefaultPos_Left);
  pData->HBAngle.Right.FullHBCutOffAng = (pPlusInput->CurveLightAngle_right + ps_In->s_Par.ps_HlaPar->Headlight.FullHBDefaultPos_Right);

 
  /************************************/
  /* HB Angle state machine           */
  /************************************/
  /* left Headlamp */
  HLAPlusAngle_RunStateMachine(  /* input */
                                &pFData->HLAPlusOut,
                                pFData->CamData.dtimeFwd_s,
                                pData,
                                &pData->HBAngle,
                                &pData->Outermost.Left,
                                pPar_left,
                                pData->HBAngle.Left.Ang_LP - pData->HBAngle.Right.Ang_LP,  /* HBAng_LP_left - HBAng_LP_right */
                                pData->HBState.Left.eState,
                                HLA_PLUS_LEFT_HEADLAMP,
                                &pFData->DecisionOut.TrafficStyle,
                                /* history */
                                /* output */
                                &pData->HBAngle.Left
                             );
  /* right Headlamp */
  HLAPlusAngle_RunStateMachine(  /* input */
                                &pFData->HLAPlusOut,
                                pFData->CamData.dtimeFwd_s,
                                pData,
                                &pData->HBAngle,
                                &pData->Outermost.Right,
                                pPar_right,
                                pData->HBAngle.Left.Ang_LP - pData->HBAngle.Right.Ang_LP,  /* HBAng_LP_left - HBAng_LP_right */
                                pData->HBState.Right.eState,
                                HLA_PLUS_RIGHT_HEADLAMP,
                                &pFData->DecisionOut.TrafficStyle,
                                /* history */
                                /* output */
                                &pData->HBAngle.Right
                              );

  /* calc min/max partial HB angle */
  HLAPlusAngle_CalcMinMaxAng(  /* input */
                              pData->HBAngle.Left.eState,
                              pPlusInput,
                              HLA_PLUS_LEFT_HEADLAMP,
                              &pPar_left->MinMax,
                              &pFData->DecisionOut,
                              pData,
                              /* history/ output */
                              &pData->HBAngle.Left.MinMax
                           );
  HLAPlusAngle_CalcMinMaxAng(  /* input */
                              pData->HBAngle.Right.eState,
                              pPlusInput,
                              HLA_PLUS_RIGHT_HEADLAMP,
                              &pPar_right->MinMax,
                              &pFData->DecisionOut,
                              pData,
                              /* history/ output */
                              &pData->HBAngle.Right.MinMax
                           );


  /* calc target angle when no vehicle is detected      */
  /* -> close the gap between left and right partial HB */
  {
    float32 NoVeh_TargetAng_left;
    float32 NoVeh_TargetAng_right;

    if(    (pFData->HLAPlusOut.eHighBeamState_Lt == RTE_HLAF_HB_STATE_PARTIAL)
        || (pData->HBAngle.Right.Ang_LP <  pData->HBAngle.Right.FullHBCutOffAng)
      )
    {
      /* left partial HB on                                           */
      /* OR right partial HB angle < Curve light angle:               */ 
      /* target angle = center of left and right partial HB position  */
      NoVeh_TargetAng_left  = (0.5f*(pData->HBAngle.Left.Ang_LP + pData->HBAngle.Right.Ang_LP));
      /* check against physical limits */
      NoVeh_TargetAng_left  = CML_f_MinMax(pData->HBAngle.Left.MinMax.HBAng_Min,  pData->HBAngle.Left.MinMax.HBAng_Max,  NoVeh_TargetAng_left);
      NoVeh_TargetAng_left  = CML_f_MinMax(pData->HBAngle.Right.MinMax.HBAng_Min, pData->HBAngle.Right.MinMax.HBAng_Max, NoVeh_TargetAng_left);
      NoVeh_TargetAng_right = NoVeh_TargetAng_left;
    }
    else
    {
      /* left partial HB off and right partial HB angle < Curve light angle  */
      /* -> stay at current position                                         */
      NoVeh_TargetAng_left  = pData->HBAngle.Right.Ang_LP;
      NoVeh_TargetAng_right = NoVeh_TargetAng_left;
    }
    pData->HBAngle.Left.NoVehTargetAng  = NoVeh_TargetAng_left;
    pData->HBAngle.Right.NoVehTargetAng = NoVeh_TargetAng_right;
  }
      
  
  /* filter HB angle            */
  /* left headlamp              */  
  /* follow curve light angle ? */
  if(pData->HBAngle.Left.eState == HLA_PLUS_ANG_FOLLOW_CURVEANG)
  {
    /* country road */
    pData->HBAngle.Left.Ang_Raw = pData->HBAngle.Left.FullHBCutOffAng;
    pData->HBAngle.Left.Ang_LP  = pData->HBAngle.Left.FullHBCutOffAng;
  }
  else  
  {
    /* calc. safety angle */
    HLAPlusAng_CalcSafetyAng(  /* input */
                                ps_In,
                                pData->HBAngle.Left.eState,
                                HLA_PLUS_LEFT_HEADLAMP,
                                pObjList,
                                &pData->Object.Left,
                                &pPar->Left,
                                &pFData->DecisionOut.TrafficStyle,  
                                /* history/ output */
                                &pData->HBAngle.Left.SafetyMargin
                             );
    
    /* calc. raw HB angle */
    HLAPlusAng_CalcRawAng( /* output */
                            &pData->HBAngle.Left.Ang_Raw,
                            /* input */
                            &pData->HBAngle,
                            &pData->HBAngle.Left,
                            &pData->Outermost.Left,
                            HLA_PLUS_LEFT_HEADLAMP,
                            /* CurveAngle */
                            pData->HBAngle.Left.FullHBCutOffAng,
                            pData->HBAngle.Left.NoVehTargetAng /* NoVeh_TargetAng: no vehicle: move cut off angle to target angle */
                          );
    /* filter HB angle */
    HLAPlusAng_FilterAng( /* history/ output */
                           &pData->HBAngle.Left,
                           /* input */
                           pData->TurnOff.Reason_Left.Reason,
                           pData->HBState.Left.eState,
                                                                                             
                           &pData->Outermost.Left,
                                                    
                           pPar_left,
                           
                           HLA_PLUS_LEFT_HEADLAMP,
                           &pFData->DecisionOut.TrafficStyle
                         );
  }
  /* right headlamp */
  /* follow curve light angle ? */
  if(pData->HBAngle.Right.eState == HLA_PLUS_ANG_FOLLOW_CURVEANG)
  {
    pData->HBAngle.Right.Ang_Raw = pData->HBAngle.Right.FullHBCutOffAng;
    pData->HBAngle.Right.Ang_LP  = pData->HBAngle.Right.FullHBCutOffAng;
  }
  else  
  {
    /* calc. safety angle */

    HLAPlusAng_CalcSafetyAng(  /* input */
                                ps_In,
                                pData->HBAngle.Right.eState,
                                HLA_PLUS_RIGHT_HEADLAMP,
                                pObjList,
                                &pData->Object.Right,
                                &pPar->Right,
                                &pFData->DecisionOut.TrafficStyle,
                                /* history/ output */
                                &pData->HBAngle.Right.SafetyMargin
                             );
    
    /* calc. raw HB angle */
    HLAPlusAng_CalcRawAng( /* output */
                            &pData->HBAngle.Right.Ang_Raw,
                            /* input */
                            &pData->HBAngle,
                            &pData->HBAngle.Right,
                            &pData->Outermost.Right,
                            HLA_PLUS_RIGHT_HEADLAMP,
                            /* CurveAngle */
                            pData->HBAngle.Right.FullHBCutOffAng,
                            pData->HBAngle.Right.NoVehTargetAng/* NoVeh_TargetAng: no vehicle: move cut off angle to target angle */
                          );
    /* filter HB angle */
    HLAPlusAng_FilterAng( /* history/ output */
                           &pData->HBAngle.Right, 
                           /* input */
                           pData->TurnOff.Reason_Right.Reason,
                           pData->HBState.Right.eState,
                           
                           &pData->Outermost.Right,
                           
                           pPar_right,

                           HLA_PLUS_RIGHT_HEADLAMP,
                           &pFData->DecisionOut.TrafficStyle
                         );
  }
    
  /* set previous state */
  pData->HBAngle.Left.eStatePrev  = eStatePrev_left;
  pData->HBAngle.Right.eStatePrev = eStatePrev_right;
}
