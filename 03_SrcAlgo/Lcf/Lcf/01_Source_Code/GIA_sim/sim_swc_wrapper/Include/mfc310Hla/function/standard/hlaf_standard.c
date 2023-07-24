  /*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_standard.c

  DESCRIPTION:            HLA standard function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_standard.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:32CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/standard/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:15CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/standard/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:51CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/standard/project.pj
  CHANGE:                 Revision 1.49 2014/03/26 11:27:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:43 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.48 2014/03/25 18:41:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_standard.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_standard.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/standard/project.pj.
  CHANGE:                 Revision 1.47 2014/03/19 16:30:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:13 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.46 2014/03/10 13:21:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:02 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.45 2014/03/04 16:52:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:31 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.44 2013/12/13 16:44:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:48 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.43 2013/08/29 12:39:36CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:36 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.42 2013/07/18 18:12:21CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Updates due to RTE change:
  CHANGE:                 Includes: 
  CHANGE:                  - new HeadlightState
  CHANGE:                  - EcoLight Feature
  CHANGE:                  - Light Dimming Areas Feature
  CHANGE:                  - Light adaptive image display settings for MTS visu
  CHANGE:                  - SRLCam rec file support in visu
  CHANGE:                 --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:21 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.41 2013/04/12 12:45:15CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:15 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.40 2013/04/11 16:21:01CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:21:02 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.39 2013/03/11 18:01:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace some types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 6:01:55 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.38 2013/03/08 17:43:08CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:08 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.37 2013/01/18 07:46:05CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:05 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.36 2012/11/15 09:56:53CET Brunn, Marcus (brunnm) 
  CHANGE:                 interface update for MFC4B0, BMW I210 (without RTE)
  CHANGE:                 --- Added comments ---  brunnm [Nov 15, 2012 9:56:53 AM CET]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.35 2012/07/23 12:58:02CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:02 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.34 2012/04/23 15:49:45CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGE:                 - delayed HB turn on after vehicles goes lost
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 3:49:46 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.33 2012/04/21 15:04:40CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:40 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.32 2012/03/23 11:36:15CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGE:                 time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hlaf_standard.h"
#include "hlaf_decision.h"


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

/* internal data */
HLAFStandardData_t    hlafStdData;


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLAFStandardSetChangeOverLevel( /* input */
                                            const HLAF_t_RequiredInputs        *ps_In,
                                            const HLAFParStdChangeOverLevel_t  *pPar,
                                            /* output */  
                                            HLAFStdOut_t                       *pOut
                                          );

static void HLAFStandardFindClosestVehicle( /* input */
                                            const HLA_t_ObjectList        *pObjectList,
                                            const HLAFParameterStandard_t *pPar,
                                            /* output */
                                            HLAFStandardVehicleClosest    *pVeh
                                          );

static void HLAFStandardSetTargetDrivingDirection( /* input */
                                                   const HLAFStandardVehicleClosest *pVehClosest,
                                                   const HLAFData_t                 *pFData,
                                                   /* history */
                                                   HLAFStandardData_t               *pStdData,
                                                   /* output */
                                                   HLAFStdOut_t                *pOut
                                                 );

static void HLAFStandardSetLightDistanceAngle( /* input */
                                               const HLAFData_t                   *pFData,
                                               const HLAFParameterLightDistance_t *pPar,
                                               const HLAFStandardData_t           *pData,
                                               /* output */  
                                               HLAFStdOut_t                       *pOut
                                             );


/* **************************************************************************** 
  Functionname:     HLAFStandardInit                                     */ /*!
  @brief            Initialize HLA standard.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
/* ~CodeReview ~ID:f2ef6628e1c06fed5ebd453f94610ecc ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
/* ~CodeReview ~ID:b33fc98427762211706a031fec3b1f5c ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:General: pointer parameters of exported functions are not checked for NULL. */
void HLAFStandardInit(const HLAFParameterStandard_t *pPar)
{
  /* init decision data */
  (void)memset((void*)&hlafStdData, 0, sizeof(hlafStdData));

  hlafStdData.KeepOffReason.TurnOnDelay.InitTimer_s = pPar->TurnOnDelay.initialTurnOnDelay;
      
  hlafStdData.Out.eHighBeamState          = RTE_HLAF_HB_STATE_OFF;
  hlafStdData.Out.LowBeamDist             = pPar->LightDistance.MinLightingDist;
  hlafStdData.Out.eTargetDrivingDirection = RTE_HLAF_OBJSTA_UNKNOWN;
  hlafStdData.Out.ChangeoverLevel         = 15;
   
}

/* **************************************************************************** 
  Functionname:     HLAFStandardMain                                     */ /*!
  @brief            HLA standard processing
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFStandardMain( /* input */
                       const HLAF_t_RequiredInputs   *ps_In,
                       const HLAFParameterStandard_t *pPar,
                       const HLAFData_t              *pFData,
                       /* output */
                       HLAFStdOut_t                  *pOut
                     )
{
  HLAFStdOut_t StdOut_Next = hlafStdData.Out;
  

  /* HB on time < 3sec -> increase penalty timer +0.5sec */
  HLAFDecisionPenaltyTimer( /* input */
                            hlafStdData.Out.eHighBeamState,
                            pFData->CamData.dtimeFwd_s,
                            /* history/ output */
                            &hlafStdData.PenaltyTimer
                          );

  HLAFStandardFindClosestVehicle( /* input */
                                  ps_In->s_Sig.ps_ObjectList,
                                  pPar,
                                  /* output */
                                  &hlafStdData.VehicleClosest
                                );
  

  /* check track list for existing target */
  HLAFDecisionFindRelevantVehicle( /* Input */
                                 ps_In,
                                 pFData,
                                 ps_In->s_Sig.ps_ObjectList,
                                 hlafStdData.Out.eHighBeamState,
                                 /* History/ Output */
                                 &hlafStdData.RelevantVehicle
                               );
  

  /* set turn off reason */
  HLAFDecisionSetTurnOffReason( /* input */
                                &hlafStdData.RelevantVehicle,
                                /* output */
                                &hlafStdData.TurnOffReason
                              );
  
  /* set keep off reason */
  HLAFDecisionSetKeepOffReason( /* input */
                                ps_In,
                                pFData,
                                &pPar->KeepOff,
                                &pPar->TurnOnDelay,
                                hlafStdData.Out.eHighBeamState,
                                &hlafStdData.RelevantVehicle,
                                &hlafStdData.PenaltyTimer,
                                &hlafStdData.TurnOffReason,
                                /* history and output */
                                &hlafStdData.KeepOffReason
                              );

  /* set HB state {HB on or off} */
  HLAFDecisionSetHBState( /* input */
                          &pFData->DecisionData.TurnOffReason_glob,
                          &hlafStdData.TurnOffReason,
                          &hlafStdData.KeepOffReason,
                          hlafStdData.Out.eHighBeamState,
                          /* output */
                          &StdOut_Next.eHighBeamState
                        );

  /* set the target driving direction of the relevant object */
  HLAFStandardSetTargetDrivingDirection( /* input */
                                         &hlafStdData.VehicleClosest,
                                         pFData,
                                         /* history */
                                         &hlafStdData,
                                         /* output */
                                         &StdOut_Next
                                       );  

  /*  set low beam distance and angle */
  HLAFStandardSetLightDistanceAngle( /* input */
                                     pFData,
                                     &pPar->LightDistance,
                                     &hlafStdData,
                                     /* output */  
                                     &StdOut_Next
                                   );
    
  /* calculate change over level */
  HLAFStandardSetChangeOverLevel( /* input */
                                  ps_In,
                                  &pPar->ChangeOverLevel,
                                  /* output */
                                  &StdOut_Next
                                );

  /* write data into output struct */
  StdOut_Next.TurnOffReason = hlafStdData.TurnOffReason.Reason;
  StdOut_Next.KeepOffReason = hlafStdData.KeepOffReason.Reason;
  StdOut_Next.activatePenaltyTime_s = hlafStdData.PenaltyTimer.activatePenaltyTime_s;
  hlafStdData.Out = StdOut_Next; 
  *pOut = StdOut_Next;
}


/* **************************************************************************** 
  Functionname:     HLAFStandardSetChangeOverLevel                       */ /*!  
  Description:      Calculate change over level for Headlamps. 


  @param[in]         

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFStandardSetChangeOverLevel( /* input */
                                            const HLAF_t_RequiredInputs        *ps_In,
                                            const HLAFParStdChangeOverLevel_t  *pPar,
                                            /* output */  
                                            HLAFStdOut_t                       *pOut
                                          )
{
if(pOut->eHighBeamState == RTE_HLAF_HB_STATE_OFF)
  {
    /* max. possible LightDistance is 200.0, therefore 201.0 is good enough */
    float32 min_lightDist = 201.0f;
    uint8 i;

    for (i=0; i<ps_In->s_Sig.ps_HeadlightState->nGFA; i++)
    {
      if (ps_In->s_Sig.ps_HeadlightState->GFA[i].e_LightDistanceState == RTE_HLA_CUTOFFLINE_ACTIVE)
      {
        min_lightDist = CML_f_Min(min_lightDist, ps_In->s_Sig.ps_HeadlightState->GFA[i].f32_LightDistance);
      }
    }

    if(pOut->LowBeamDist >= min_lightDist)
    {
      /* increasing lighting distance       */
      /* set change over level to low speed */
      pOut->ChangeoverLevel = pPar->TurnOnLow;
    }
    else
    {
      /* decreasing lighting distance */
      pOut->ChangeoverLevel = HLAFDecisionChangeOverLevel_TurnOff( /* input */
                                                                   pOut->LowBeamDist,
                                                                   pOut->eTargetDrivingDirection,
                                                                   pPar
                                                                 );
      
    }
  }
  else
  {
    /* set HLALightingDistance and changeover level for "high beam on" */
    pOut->ChangeoverLevel = pPar->TurnOnHigh;  
  }
}


/* **************************************************************************** 
  Functionname:     HLAFStandardSetLightDistanceAngle                    */ /*!  
  Description:      Set light distance and angle for headlamps.


  @param[in]        
                    

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFStandardSetLightDistanceAngle( /* input */
                                               const HLAFData_t                   *pFData,
                                               const HLAFParameterLightDistance_t *pPar,
                                               const HLAFStandardData_t           *pData,
                                               /* output */  
                                               HLAFStdOut_t                       *pOut
                                             )
{
  /* any global turn off reason ? */
  if(pFData->DecisionData.TurnOffReason_glob.Reason.u32 > 0)
  {
    /* global turn off reason   */  
    /* -> dist = 65m, Ang = 0°  */
    pOut->LowBeamDist  = pPar->MinLightingDist;
    pOut->LowBeamAngle = 0.0f;
  }
  else
  {
    /* no global turn off reason */
    if(pData->Out.eHighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* previous HB state = full on */
      if(pOut->eHighBeamState == RTE_HLAF_HB_STATE_OFF)
      {
        /* HB will be switched off in this cycle                  */
        /* -> use current min distance                            */
        /* -> distance filter starts at current vehicle distance  */
        pOut->LowBeamDist  = pData->VehicleClosest.MinDist_m;
        pOut->LowBeamAngle = pData->VehicleClosest.Ang;
      }
      else
      {
        /* HB still on */
        pOut->LowBeamDist  = pPar->MaxLightingDist;
        pOut->LowBeamAngle = 0.0f;
      }
    }
    else if (pData->Out.eHighBeamState == RTE_HLAF_HB_STATE_OFF)
    {
      /* previous HB state = off */
      if(pOut->eHighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* HB will be turned on in this cycle */
        pOut->LowBeamDist  = pPar->MaxLightingDist;
        pOut->LowBeamAngle = 0.0f;
      }
      else
      {
        /* HB off */

        /* no relevant vehicle detected ? */
        if(    (pData->TurnOffReason.Reason.Bit.OncDetected  == 0)
            && (pData->TurnOffReason.Reason.Bit.PrecDetected == 0)
          )
        {
          /* no relevant vehicle detected                 */
          /* -> keep old distance                         */
          /*    HBs will be switched on soon              */
          /* or lost preceding car will be detected again */
          if(pOut->eTargetDrivingDirection == RTE_HLAF_OBJSTA_NO_OBJ)
          {
            /* keep old distance and  */
            pOut->LowBeamDist  = pData->Out.LowBeamDist;
            pOut->LowBeamAngle = 0.0f;
          }
          else
          {
            /* keep old distance and angle until target driving direction is idle */
            pOut->LowBeamDist  = pData->Out.LowBeamDist;
            pOut->LowBeamAngle = pData->Out.LowBeamAngle;
          }
        }
        else
        {
          /* -> filter light distance */
          float32 MinDist_m = pData->VehicleClosest.MinDist_m;
              
          if(MinDist_m > pData->Out.LowBeamDist)
          {
            /* increasing lighting distance */
            if(pData->Out.eTargetDrivingDirection == RTE_HLAF_OBJSTA_ONC_OBJ)
            {
              /* oncoming traffic */

              /* keep lighting distance because further oncoming traffic is close -> save mechanics of headlights*/
              pOut->LowBeamDist  = pData->Out.LowBeamDist;
              pOut->LowBeamAngle = pData->VehicleClosest.Ang;//pData->Out.LowBeamAngle;
            }
            else if(    (pData->KeepOffReason.Reason.Bit.SpdAcc == 1)
                     || (pData->KeepOffReason.Reason.Bit.MaybeCity_Onc  == 1)
                     || (pData->KeepOffReason.Reason.Bit.MaybeCity_Prec == 1)
                     || (pData->KeepOffReason.Reason.Bit.MaybeCity_Glob == 1)
                   )
            { 
              /* velocity will fall below activation speed in less than 2 to 3 seconds            */
              /* or maybe city detected                                                           */
              /*    decreasing LowBeamDist is allowed                                             */
              /*    increasing LowBeamDist is not meaningful because velocity will fall           */
              /*             below activation speed in 2 to 3 sec.                                */
              
              /* keep old low beam distance */
              pOut->LowBeamDist  = pData->Out.LowBeamDist;
              pOut->LowBeamAngle = pData->Out.LowBeamAngle;
            }
            else
            {
              /* preceding traffic or unknown direction */
              pOut->LowBeamDist =   ((1 - pPar->parFiltLPPreceedDepart) * pData->Out.LowBeamDist)
                                  + (pPar->parFiltLPPreceedDepart * MinDist_m);
              pOut->LowBeamAngle = pData->VehicleClosest.Ang;
            }
          }
          else
          {
            /* decreasing lighting distance */
            if(pOut->eTargetDrivingDirection == RTE_HLAF_OBJSTA_ONC_OBJ)
            {
              /* oncoming traffic */
              pOut->LowBeamDist =   ((1 - pPar->parFiltLPOncomingApproach) * pData->Out.LowBeamDist)
                                  + (pPar->parFiltLPOncomingApproach * MinDist_m);
            }
            else
            {
              /* preceding traffic or direction unknown */
              pOut->LowBeamDist =   ((1 - pPar->parFiltLPPreceedApproach) * pData->Out.LowBeamDist)
                                  + (pPar->parFiltLPPreceedApproach * MinDist_m);
            }
            pOut->LowBeamAngle = pData->VehicleClosest.Ang;
          }

          /* limit set value of lighting distance to maximum lighting distance */
          if(pOut->eTargetDrivingDirection == RTE_HLAF_OBJSTA_ONC_OBJ)
          {
            pOut->LowBeamDist = CML_f_Min(pOut->LowBeamDist, (float32) pPar->maxLightDistOncoming);
          }
        }
      }
    }
    else
    {
      /* Do nothing */
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLAFStandardFindClosestVehicle                       */ /*!
  @brief            Find closest vehicle
  @description      Find closest object and save distance and horizontal angle.
                                        
  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFStandardFindClosestVehicle( /* input */
                                            const HLA_t_ObjectList        *pObjectList,
                                            const HLAFParameterStandard_t *pPar,
                                            /* output */
                                            HLAFStandardVehicleClosest    *pVeh
                                          )
{
  uint32              i;
  const HLA_t_Object  *pObjClosest;
  float32             min_dist_m;
  boolean             bOncomingDetected = FALSE;
  
  /* search nearest vehicle light */
  min_dist_m  = pPar->LightDistance.maxLightDist;
  pObjClosest = (HLA_t_Object*)NULL;
 
  for(i=0; i<pObjectList->ui32_NumVehicles; i++)
  {
    const HLA_t_Object  *pObj = &pObjectList->as_Object[i];
    float32 xw_m = 0.01f * pObj->s_LightDist.ui16_distMin_cm;

    /* limit distance off oncoming vehicles */
    if(pObj->s_Status.isVehicleOncoming == 1)
    {
      xw_m = CML_f_Min(xw_m, pPar->LightDistance.maxLightDistOncoming);
    }
    xw_m = CML_f_Max(xw_m, pPar->LightDistance.minLightDist);

    if(xw_m < min_dist_m)
    {
      pObjClosest = pObj;
      min_dist_m  = xw_m;
    }

    /* oncoming vehicle detected ? */
    if(pObj->s_Status.isVehicleOncoming == 1)
    {
      bOncomingDetected = TRUE;
    } 
  }

  if(pObjClosest != NULL)
  {
    pVeh->pVeh              = pObjClosest;
    pVeh->MinDist_m         = min_dist_m;
    pVeh->Ang               = pObjClosest->f32_ObjectHorAng_rad;
    pVeh->bOncomingDetected = bOncomingDetected;
  }
  else
  {
    pVeh->pVeh              = NULL;
    pVeh->MinDist_m         = pPar->LightDistance.maxLightDist;
    pVeh->Ang               = 0.0f;
    pVeh->bOncomingDetected = FALSE;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFStandardSetTargetDrivingDirection                */ /*!
  @brief            Set target driving direction.
  @description      
                    
  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFStandardSetTargetDrivingDirection( /* input */
                                                   const HLAFStandardVehicleClosest *pVehClosest,
                                                   const HLAFData_t                 *pFData,
                                                   /* history */
                                                   HLAFStandardData_t               *pStdData,
                                                   /* output */
                                                   HLAFStdOut_t                *pOut
                                                 )
{
  RTE_HLAF_ObjStatus eTargetDrivingDirection = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;


  if(pVehClosest->pVeh != NULL)
  {  
    /* set target driving direction */  
    if(pVehClosest->pVeh->s_Status.isVehicleAhead == 1)
    {
      if(    (pStdData->TargetDrivingDir.eTargetDrivingDirection == RTE_HLAF_OBJSTA_ONC_OBJ)
          && (pStdData->TargetDrivingDir.DelayTimer_s > 0.0f)
        )  
      {
        /* keep RTE_HLAF_OBJSTA_ONC_OBJ until (DelayTimer_s == 0) */
        eTargetDrivingDirection = RTE_HLAF_OBJSTA_ONC_OBJ;
      }
      else
      {
        /* leading traffic */
        eTargetDrivingDirection = RTE_HLAF_OBJSTA_PREC_OBJ;
        /* set delay timer */
        pStdData->TargetDrivingDir.DelayTimer_s = pVehClosest->pVeh->ui16_ttb_ms * 0.001f;
      }
    }
    else
    {
      /* oncoming traffic */
      eTargetDrivingDirection = RTE_HLAF_OBJSTA_ONC_OBJ;
      /* load delay timer */
      pStdData->TargetDrivingDir.DelayTimer_s = pVehClosest->pVeh->ui16_ttb_ms * 0.001f;
    }
  }

 
  if(pOut->eHighBeamState == RTE_HLAF_HB_STATE_OFF)
  {
    /* HB off             */
    /* vehicle detected ? */
    if(pVehClosest->pVeh != NULL)
    {
      pStdData->TargetDrivingDir.eTargetDrivingDirection = eTargetDrivingDirection;
    }
    else if(   (pStdData->TargetDrivingDir.eTargetDrivingDirection == RTE_HLAF_OBJSTA_ONC_OBJ)
            && (pStdData->KeepOffReason.Reason.Bit.TurnOnDelay_Onc == 1)
           )
    {
      /* no oncoming vehicle detected anymore -> keep old target driving direction */
      /* until vehicle is out off FOV (keep off -> max TTB == 0)                   */ 
      pStdData->TargetDrivingDir.eTargetDrivingDirection = RTE_HLAF_OBJSTA_ONC_OBJ;
    }
    else if(   (pStdData->TargetDrivingDir.eTargetDrivingDirection == RTE_HLAF_OBJSTA_PREC_OBJ)
            && (pStdData->KeepOffReason.Reason.Bit.TurnOnDelay_Prec == 1)
           )
    {
      /* no preceding vehicle detected anymore -> keep old target driving direction */
      /* until vehicle is out off FOV (keep off -> max TTB == 0)                    */ 
      pStdData->TargetDrivingDir.eTargetDrivingDirection = RTE_HLAF_OBJSTA_PREC_OBJ;
    }
    else
    {
      /* no vehicle detected */
      pStdData->TargetDrivingDir.eTargetDrivingDirection = RTE_HLAF_OBJSTA_NO_OBJ;
    }
  }
  else
  {
    /* HB on */
    pStdData->TargetDrivingDir.eTargetDrivingDirection = RTE_HLAF_OBJSTA_NO_OBJ;
  }
  
  /* decrement delay timer */
  if(pStdData->TargetDrivingDir.DelayTimer_s > 0.0f)
  {
    /* ~CodeReview ~ID:2ae45daee08cb0c2527f91acb4725760 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:2 ~Comment:DelayTimer_s can get negative here. Is this intentional? */
    pStdData->TargetDrivingDir.DelayTimer_s -= pFData->CamData.dtimeFwd_s;
  }  
  else
  {
    pStdData->TargetDrivingDir.DelayTimer_s = 0.0f;
  }

  /* copy internal eTargetDrivingDirection to output */
  pOut->eTargetDrivingDirection = pStdData->TargetDrivingDir.eTargetDrivingDirection;
}


/* ****************************************************************************
  Functionname:     HLAFStandardMeasfreeze                          */ /*!
  Description:      send internal hla standard data via measfreeze to MTS. 



  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           
**************************************************************************** */
void HLAFStandardMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo HlafStandardDataMeasInfo = {HLA_MEAS_VADDR_HLAF_STANDARD_DATA, sizeof(hlafStdData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};

  (void)pfMeasFreeze(&HlafStandardDataMeasInfo, (void*)&hlafStdData, NULL);
#endif   
}/* PRQA S 861 1 */
