/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysischain.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-09-13

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trafficstyle.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:57CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:39CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:29CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.24 2014/03/26 11:27:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:44 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2014/03/25 19:11:50CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:51 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/03/25 18:36:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trafficstyle.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trafficstyle.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.21 2014/03/19 16:30:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:44 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.20 2014/03/10 13:21:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:07 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2014/03/04 16:52:16CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:17 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2013/04/12 11:00:13CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Implemented BMW Codierparameter for traffic style
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 12, 2013 11:00:14 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.17 2013/03/13 17:09:11CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:09:12 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.16 2013/03/12 14:11:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 2:11:37 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.15 2013/03/11 16:13:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:41 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.14 2013/03/08 10:30:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:58 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.13 2013/03/04 11:15:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:06 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.12 2013/01/23 17:57:30CET Brunn, Marcus (brunnm) 
  CHANGE:                 Converted enum to rte like type for
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 --- Added comments ---  brunnm [Jan 23, 2013 5:57:30 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.11 2013/01/22 12:14:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced more traffic style enums by uint32
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 22, 2013 12:14:07 PM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.10 2013/01/22 09:55:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced enum by uint32 for traffic style
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 22, 2013 9:55:12 AM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.9 2013/01/08 10:28:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Exchanged ABS by fABS for floating point calculations
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 8, 2013 10:28:49 AM CET]
  CHANGE:                 Change Package : 167173:21 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>

#include "hla_trafficstyle.h"

/*! Do the traffic style init . */
void HLATrafficStyleInit( const HLAR_t_RequiredInputs        *ps_In,
                          RTE_HLA_TrafficStyle               *peTrafficStyle,
                          RTE_HLAR_TrafficStyleState         *peTrafficStyleState,
                          RTE_HLAR_TrafficStyleLearningState *peTrafficStyleLearningState,
                          HLATrafficStyleHist_t              *pHist
                        )
{
  if(ps_In->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned != RTE_HLA_TRAFFIC_STYLE_UNKNOWN)
  {
    *peTrafficStyle       = ps_In->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
    *peTrafficStyleState  = RTE_HLAR_TRAFFIC_STATE_LAST_LEARNED;
  }
  else
  {
    *peTrafficStyle       = ps_In->s_Par.s_HlaPar.Country.TrafficStyle;
    *peTrafficStyleState  = RTE_HLAR_TRAFFIC_STATE_SCN;
  }

  *peTrafficStyleLearningState = ps_In->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;

  (void)memset((void*)pHist, 0, sizeof(HLATrafficStyleHist_t));
}

/*! Do the traffic style analysis . */
void HLATrafficStyle(const HLATrafficStyleInput_t*           pIn, 
                     RTE_HLA_TrafficStyle*                   peTrafficStyle,
                     RTE_HLAR_TrafficStyleState*             peTrafficStyleState,
                     RTE_HLAR_TrafficStyleLearningState*     peTrafficStyleLearningState,
                     HLATrafficStyleHist_t*                  pHist,
                     const HLA_t_TrafficStyleParameters*     pParams,
                     const RTE_HLAR_ParameterTrafficStyle_t* pTSParams
                    )
{
  /*--- VARIABLES ---*/
  
  /*internal static variables*/
  float32 counter = pHist->counter;       /* counts left(+) and right(-) car lights */
  float32 counter_sum = pHist->counter_sum;       /* counts left(+) and right(-) car lights */
  uint16 light_counter_total = pHist->light_counter_total;
  
  /*local variables*/
  float32 ROI_camCenter_x, ROI_camCenter_y;
  float32 abs_delta_x_lp;
  float32 abs_delta_y_lp;
  sint32 trafficStyleMinTrackFrames;
  HLATrack_t* pTLB;    /* track pointer */
  sint32 light_counter;        /* counts right and left car lights in current frame */
  /* Old implementation */
  //float32 StepThresh = pParams->trafficStyleStepThresh;
  float32 StepThresh = (pTSParams->NumOncLightsThres/4.0f);
#ifdef PC_SIM
  sint32 pair_light_counter;   /* counts paired lights */
#endif
  
  if (    ( (CML_f_Abs(counter_sum) < pTSParams->NumOncLightsLock) || (pIn->pOdometer->OdometerAll_m < pParams->minOdometerLock) )
      &&  (pIn->eCity == RTE_HLAR_CITY_NOT_DTCD)
     )
  {
    /* get image position of straight ahead forward world position */
    HLACamRotGetXb(pIn->pcamRot, &ROI_camCenter_x, &ROI_camCenter_y, 10000.0f, 0.0f, pIn->pcamRot->T[2]);
    
    /* convert minimal track time in seconds to number of frames */
    trafficStyleMinTrackFrames = (sint32)(0.5f 
      + (pParams->trafficStyleMinTrackSecs / pIn->ps_HLAR_In->s_Par.s_CameraParameter.f32_cycleTime));
    
    light_counter = 0;
#ifdef PC_SIM
    pair_light_counter = 0;
#endif
    
    /* check for minimal driving speed */
    if ( (pIn->ps_HLAR_In->s_Sig.s_MotionState.f32_Speed >= pParams->trafficStyleMinSpeed) 
      && (pIn->ps_HLAR_In->s_Sig.s_MotionState.e_MoveState == HLA_MOVE_STATE_FWD) )
    {
      /* walk through the list of tracks */
      pTLB = pIn->pTLB;
      while (pTLB != NULL)
      {
#ifdef PC_SIM
        pTLB->DebugParameter.trafficStyleReason.allBits = 0;
        pTLB->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
#endif
        /*
        check if track will be removed in next frame,
        if current track position is below horizon
        if track is at least trafficStyleMinTrackFrames frames old,
        if track is an oncoming light and
        if it moves horizontally
        */
                
        if (pTLB->TrackingStatus.willBeRemoved == 1)
        {
          if (pTLB->ycenter > ROI_camCenter_y)
          {
            if (pTLB->track_time >= trafficStyleMinTrackFrames)
            {
              if ( (pTLB->statusAnalysisVehicle.isVehicleOncoming == TRUE ) && ( pTLB->statusAnalysisVehicle.isVehicleAhead == FALSE ) )
              {
                abs_delta_x_lp = fabsf(pTLB->delta_x_lp);
                abs_delta_y_lp = fabsf(pTLB->delta_y_lp);
                if ( ( abs_delta_x_lp - abs_delta_y_lp ) > 0)
                {                  
                  /* check if current light pos is left of camera center */
                  if (pTLB->xcenter < ROI_camCenter_x)
                  {
                    /* check if track is moving outwards, with at least trafficStyleMinDeltaX pixel per frame */
                    if (pTLB->delta_x_lp < -pParams->trafficStyleMinDeltaX)
                    {
                      light_counter++;
#ifndef PC_SIM
                    }
#else
                      if ( (pTLB->dist_est_pair_link != NULL) && (pTLB->dist_est_pair_link->TrackingStatus.willBeRemoved == TRUE ) )
                      {
                        pair_light_counter++;
                      }
                      pTLB->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHD;
                    }else
                    {
                      pTLB->DebugParameter.trafficStyleReason.bit.too_slow_min_speed = 1;
                    }
#endif
                  }else
                  {
                    /* check if track is moving outwards, with at least trafficStyleMinDeltaX pixel per frame */
                    if (pTLB->delta_x_lp > pParams->trafficStyleMinDeltaX)
                    {
                      light_counter--;
#ifndef PC_SIM
                    }
                  }
                }
              }
            }
          }
        }
#else
                      if ( (pTLB->dist_est_pair_link != NULL) && (pTLB->dist_est_pair_link->TrackingStatus.willBeRemoved == TRUE) )
                      {
                        pair_light_counter--;
                      }
                      pTLB->eTrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHD;
                    }else
                    {
                      pTLB->DebugParameter.trafficStyleReason.bit.too_slow_min_speed = 1;
                    }
                  }
                }else
                {
                  pTLB->DebugParameter.trafficStyleReason.bit.not_lateral_moving = 1;
                }
              }else
              {
                pTLB->DebugParameter.trafficStyleReason.bit.not_oncoming = 1;
              }
            }else
            {
              pTLB->DebugParameter.trafficStyleReason.bit.short_tracktime = 1;
            }
          }else
          {
            pTLB->DebugParameter.trafficStyleReason.bit.above_horizon = 1;
          }
        }else
        {
          pTLB->DebugParameter.trafficStyleReason.bit.not_dieing = 1;
        }
#endif
        pTLB = pTLB->next;
      }
    
      if (light_counter_total < UI16_T_MAX) 
      {
        light_counter_total = light_counter_total + (uint16)(abs(light_counter));
      }
      if (light_counter_total > pParams->trafficStyleCountDiscard)
      {
        counter = CML_MinMax(-pTSParams->NumOncLightsLock,pTSParams->NumOncLightsLock,counter + light_counter);
        counter_sum = CML_MinMax(-pTSParams->NumOncLightsLock,pTSParams->NumOncLightsLock,counter_sum + light_counter);
      }else
      {
      }
    }
  
    /* State machine for peTrafficStyleLearningState */
    
    switch(*peTrafficStyleLearningState)
    {
      case RTE_HLAR_TRAFFIC_LEARN_LHD_1:
        if(counter >= StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_RHD_1;
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_LHD_2;
        }
        else
        {
          /* do nothing */
        }
        break;
      case RTE_HLAR_TRAFFIC_LEARN_LHD_2:
        if(counter >= StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_RHD_1;
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_LHD_3;
        }
        else
        {
          /* do nothing */
        }
        break;
      case RTE_HLAR_TRAFFIC_LEARN_LHD_3:
        if(counter >= StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_RHD_1;
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyle       = RTE_HLA_TRAFFIC_STYLE_LHD;
          *peTrafficStyleState  = RTE_HLAR_TRAFFIC_STATE_LEARN;
          /* peTrafficStyleLearningState is kept to RTE_HLAR_TRAFFIC_LEARN_LHD_3 state */
        }
        else
        {
          /* do nothing */
        }
        break;
      case RTE_HLAR_TRAFFIC_LEARN_RHD_1:
        if(counter >= StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_RHD_2;
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_LHD_1;
        }
        else
        {
          /* do nothing */
        }
        break;
      case RTE_HLAR_TRAFFIC_LEARN_RHD_2:
        if(counter >= StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_RHD_3;
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_LHD_1;
        }
        else
        {
          /* do nothing */
        }
        break;
      case RTE_HLAR_TRAFFIC_LEARN_RHD_3:
        if(counter >= StepThresh)
        {
          *peTrafficStyle       = RTE_HLA_TRAFFIC_STYLE_RHD;
          *peTrafficStyleState  = RTE_HLAR_TRAFFIC_STATE_LEARN;
          /* peTrafficStyleLearningState is kept to RTE_HLAR_TRAFFIC_LEARN_RHD_3 */
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_LHD_1;
        }
        else
        {
          /* do nothing */
        }
        break;
      case RTE_HLAR_TRAFFIC_LEARN_UNKNOWN:
      case RTE_HLAR_TRAFFIC_LEARN_INVALID:
      case RTE_HLAR_TRAFFIC_LEARN_0:
      /* use RTE_HLAR_TRAFFIC_LEARN_0 as default */
      default:
        if(counter >= StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_RHD_1;
        }
        else if(counter <= -StepThresh)
        {
          *peTrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_LHD_1;
        }
        else
        {
          /* do nothing */
        }
        break;
    }

    if( (counter >= StepThresh) || (counter <= -StepThresh) )
    {
      counter = 0;
    }
  
    /* set internal variables*/
    pHist->counter = counter;
    pHist->counter_sum = counter_sum;
    pHist->light_counter_total = light_counter_total;
  
  /*DEBUG Display*/
#ifdef PC_SIM
      pHist->dbgTrafficStyle_light_counter = light_counter;
      pHist->dbgTrafficStyle_pair_light_counter = pair_light_counter;
      pHist->dbgTrafficStyle_belowMotionData_speed = (pIn->ps_HLAR_In->s_Sig.s_MotionState.f32_Speed < pParams->trafficStyleMinSpeed);
#endif
  }
}/* PRQA S 861 1 */