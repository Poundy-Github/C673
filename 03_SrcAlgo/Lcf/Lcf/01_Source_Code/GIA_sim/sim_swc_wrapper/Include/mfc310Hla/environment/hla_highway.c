/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_highway.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-02-14

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_highway.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:57CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:37CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:29CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.51 2014/03/26 11:27:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:41 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.50 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_highway.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_highway.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.49 2014/03/19 16:30:36CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:37 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.48 2014/03/10 13:21:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:01 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.47 2014/03/04 16:52:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:01 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.46 2014/01/10 18:33:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:35 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.45 2013/04/19 14:49:29CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Implemented BMW Highway Codierparamter
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 19, 2013 2:49:30 PM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.44 2013/03/12 14:11:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 2:11:35 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.43 2013/03/11 16:13:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:47 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.42 2013/03/11 14:33:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:07 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.41 2013/03/08 10:31:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:08 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.40 2013/03/04 11:14:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:58 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.39 2013/02/26 15:05:05CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Renamed highway variable
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 26, 2013 3:05:06 PM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.38 2013/02/26 09:20:11CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Highway detection over high speed implemented
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 26, 2013 9:20:11 AM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.37 2013/02/07 11:46:57CET Fischer, Alexander (uidv8778) 
  CHANGE:                 More errors caused by renaming fixed
  CHANGE:                 --- Added comments ---  uidv8778 [Feb 7, 2013 11:47:02 AM CET]
  CHANGE:                 Change Package : 173113:1 http://mks-psad:7002/im/viewissue?selection=173113
  CHANGE:                 Revision 1.36 2013/01/30 14:51:59CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Fixed error caused by renaming
  CHANGE:                 --- Added comments ---  uidv8778 [Jan 30, 2013 2:52:00 PM CET]
  CHANGE:                 Change Package : 173113:1 http://mks-psad:7002/im/viewissue?selection=173113
  CHANGE:                 Revision 1.35 2013/01/30 10:51:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 renamed Highway variables:
  CHANGE:                 - RdwayType -> LatPos
  CHANGE:                 - HwayDction -> EgoMotion
  CHANGE:                 --- Added comments ---  brunnm [Jan 30, 2013 10:51:35 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.34 2013/01/28 15:06:16CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eRedReflectorArea
  CHANGE:                 - HLA_t_eHighwayLatPosState
  CHANGE:                 - HLA_t_eHighwayEgoMotionState
  CHANGE:                 - HLA_t_eHighwayOcclusionState
  CHANGE:                 --- Added comments ---  brunnm [Jan 28, 2013 3:06:16 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.33 2013/01/24 16:37:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:08 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.32 2013/01/22 16:43:47CET Brunn, Marcus (brunnm) 
  CHANGE:                 MISRA fix (added blank line at end of file)
  CHANGE:                 --- Added comments ---  brunnm [Jan 22, 2013 4:43:48 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.31 2013/01/22 12:06:53CET Fischer, Alexander (uidv8778) 
  CHANGE:                 HLA-R Internal Highway Decision
  CHANGE:                 --- Added comments ---  uidv8778 [Jan 22, 2013 12:06:54 PM CET]
  CHANGE:                 Change Package : 173113:1 http://mks-psad:7002/im/viewissue?selection=173113
**************************************************************************** */

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hla_highway.h"

static void HLAHighwayIntersectionMainRoi(/*OUTPUT*/sint16  *pCoorOut_X, sint16  *pCoorOut_Y,
                  /*INPUT*/sint16 CoorIn_X, sint16 CoorIn_Y, const HLACameraData_t *pCamData,const RTE_HLA_TrafficStyle * pTrafficStyle);

static void HLAHighwayDecisionHighway(HLAHighwayInternalData_t* pData, const HLAHighwayInput_t* pIn, const HLA_t_HighwayParameters* pParams);

/* **************************************************************************** 
  Functionname:     HLAHighwayInit                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
void HLAHighwayInit( HLAHighwayInternalData_t* pData,HLA_t_Highway* pOut)
{
  uint8 Ind;

  /* reset Internal Data */
  (void)memset((void*) pData,0,sizeof(HLAHighwayInternalData_t));

  /* reset output Data */
  (void)memset((void*) pOut,0,sizeof(HLA_t_Highway));

  /* Set Oncoming History */
  for(Ind=0;Ind<HLA_HIGHWAY_DEATH_AREA_NUM_MEAN;Ind++)
  {
    pData->OncomingHist[Ind].e_LateralPosition = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
  }

  /* Set Detections states */
  pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_UNKNOWN;
  pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_UNKNOWN;
  pData->eLateralPosition = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
    pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_UNKNOWN;

  /* Set Detections states */
  pOut->e_EgoMotion = RTE_HLAR_HIGHWAY_EM_UNKNOWN;
  pOut->e_OcclusionDetection = RTE_HLAR_HIGHWAY_OC_UNKNOWN;
  pOut->e_LateralPosition = RTE_HLAR_HIGHWAY_LP_UNKNOWN;

  /* Set Internal Highway State*/
  pData->internalHighwayState = RTE_HLAF_MTWY_UNKNOWN;


}
/* **************************************************************************** 
  Functionname:     HLAHighway */ /*!
  Description:      Detection of Highway, Divided Roadway and Occlusion

  @param[in]    HLA_t_HighwayParameters    hlaHighwayParams
  @param[in,out]    -

  @return           -
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
void HLAHighway(HLAHighwayInternalData_t* pData,HLA_t_Highway* pOut,const HLAHighwayInput_t* pIn,const HLA_t_HighwayParameters* pParams, const RTE_HLAR_ParameterHighway_t* pHwyParams)
{
  /*--- VARIABLES ---*/
  /*- 32 bits -*/
  float32  xb_f=0,yb_f=0;
  float32 ThreshDividedRdwayXw,ThreshDividedRdwayYw,ThreshDividedRdwayZw;
  float32 ThreshNormalRdwayXw,ThreshNormalRdwayYw,ThreshNormalRdwayZw;
  HLATrack_t*    pTLB;

  /*- 16 bits -*/
  sint16  xb_predit,yb_predit;
  sint16  xb,yb;
  sint16  xb_int16,yb_int16;
  sint16  DeltaX = 0,DeltaXbis = 0;

  /*- 8 bits -*/
  uint8  Ind = 0;  
  uint8  i;

  /*- boolean -*/
  boolean bTrafficStyle_RHD;
  boolean bOncomingBiased = FALSE;

  
  if(*pIn->pTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
  {
    bTrafficStyle_RHD = TRUE;
  }
  else
  {
    bTrafficStyle_RHD = FALSE;
  }

  /* **********************************************
    Description:      SET THE THRESHOLDS
  **********************************************  */
  /* Case : Sure being divided */
  if(pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_DTCD)
  {
    ThreshDividedRdwayXw = pParams->ThreshDividedRdwayXwDown;
    ThreshDividedRdwayYw = pParams->ThreshDividedRdwayYwDown;
    ThreshDividedRdwayZw = pParams->ThreshDividedRdwayZwDown;

    ThreshNormalRdwayXw = pParams->ThreshNormalRdwayXwDown;
    ThreshNormalRdwayYw = pParams->ThreshNormalRdwayYwDown;
    ThreshNormalRdwayZw = pParams->ThreshNormalRdwayZwDown;
  }
  /* Case : Sure being normal */
  else if(pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
  {
    ThreshDividedRdwayXw = pParams->ThreshDividedRdwayXwUp;
    ThreshDividedRdwayYw = pParams->ThreshDividedRdwayYwUp;
    ThreshDividedRdwayZw = pParams->ThreshDividedRdwayZwUp;

    ThreshNormalRdwayXw = pParams->ThreshNormalRdwayXwUp;
    ThreshNormalRdwayYw = pParams->ThreshNormalRdwayYwUp;
    ThreshNormalRdwayZw = pParams->ThreshNormalRdwayZwUp;
  }
  /* Case : all the others */
  else
  {
    ThreshDividedRdwayXw = pParams->ThreshDividedRdwayXwUp;
    ThreshDividedRdwayYw = pParams->ThreshDividedRdwayYwUp;
    ThreshDividedRdwayZw = pParams->ThreshDividedRdwayZwUp;

    ThreshNormalRdwayXw = pParams->ThreshNormalRdwayXwDown;
    ThreshNormalRdwayYw = pParams->ThreshNormalRdwayYwDown;
    ThreshNormalRdwayZw = pParams->ThreshNormalRdwayZwDown;
  }

  /* Left Hand Traffic Style */
  if(bTrafficStyle_RHD == FALSE)
  {
    ThreshDividedRdwayYw = -ThreshDividedRdwayYw;
    ThreshNormalRdwayYw = -ThreshNormalRdwayYw;  
  }
  else
  {
    /* DO NOTHING */
  }

  /*--- SET DIVIDED ROADWAY THRESHOLD ---*/
  HLACamRotGetXb(pIn->pcamRot,&xb_f,&yb_f,ThreshDividedRdwayXw,ThreshDividedRdwayYw,ThreshDividedRdwayZw);

  xb_int16 = (sint16) (xb_f);
  yb_int16 = (sint16) (yb_f);

  /* Intersection with vanishing line and HLA Roi */
  HLAHighwayIntersectionMainRoi(&pData->ThreshDividedRdwayXb,&pData->ThreshDividedRdwayYb,xb_int16,yb_int16,pIn->pCamData,pIn->pTrafficStyle);
  
  /*--- SET NORMAL ROADWAY THRESHOLD ---*/
  HLACamRotGetXb(pIn->pcamRot,&xb_f,&yb_f,ThreshNormalRdwayXw,ThreshNormalRdwayYw,ThreshNormalRdwayZw);

  xb_int16 = (sint16) (xb_f);
  yb_int16 = (sint16) (yb_f);

  /* Intersection with vanishing line and HLA Roi */
  HLAHighwayIntersectionMainRoi(&pData->ThreshNormalRdwayXb,&pData->ThreshNormalRdwayYb,xb_int16,yb_int16,pIn->pCamData,pIn->pTrafficStyle);

  /*--- SET PREMATURE DEATH COORDINATES THRESHOLD ---*/
  pData->ThreshPrematureY = pData->ThreshNormalRdwayYb;
  if(bTrafficStyle_RHD == TRUE)
  {
    pData->ThreshPrematureX = (sint16)(pIn->pCamData->RoiX1);
  }
  else
  {
    pData->ThreshPrematureX = (sint16)(pIn->pCamData->RoiX2);
  }

  /* Update Curvature */
  if(     (pIn->pMotionData->f32_Speed > pParams->CurvMinSpeed)
      &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
      )
  {
    pData->Curvature = (float32)((pIn->pMotionData->f32_YawRate)/(pIn->pMotionData->f32_Speed));
  }
  else
  {
    pData->Curvature = 0;
  }

  /* Update DistToLastOncoming */
  pData->DistToLastOncoming += pIn->pCamData->ddistFwd_m;

  /* **********************************************
  Description:      SET the HLA_DEATH_AREA_NUM_MEAN^th LAST DEATH AREA
  **********************************************  */
  pData->NewDeathCount = 0;
  pData->NewPreDeathCount = 0;
  pTLB = pIn->pTLB;
  while(pTLB != NULL)
  {
    if(    (pTLB->statusAnalysisVehicle.isVehicleOncoming != 0)
      &&  (pTLB->light_ref != 0)
      )
    {  
      /* Update status of the track isFarToHLARoi */
      xb_predit = (sint16) ((float32)pTLB->xcenter + (pParams->ThreshPreDeathCoeff * pTLB->delta_x_lp) );
      yb_predit = (sint16) ((float32)pTLB->ycenter + pTLB->delta_y_lp);


      /* RIGHT Hand Traffic Style */
      if(bTrafficStyle_RHD == TRUE)
      {
        DeltaX = (sint16)(pIn->pCamData->FOE_x) - (sint16)(pTLB->xcenter);
        DeltaXbis = xb_predit - pData->ThreshPrematureX;
      }
      /* LEFT Hand Traffic Style */
      else
      {
        DeltaX = (sint16)(pTLB->xcenter) - (sint16)(pIn->pCamData->FOE_x);
        DeltaXbis = pData->ThreshPrematureX - xb_predit;
      }

      /* Set flag isFarToFOE*/
      if(DeltaX > pParams->FilterTracksMinDeltaX)
      {
        pTLB->statusAnalysisMisc.isFarToFOE = TRUE;
      }
      else
      {
        pTLB->statusAnalysisMisc.isFarToFOE = FALSE;
      }

      /* Set flag isFarToRoi */
      if(    (DeltaXbis > 0)
        &&  (yb_predit < pData->ThreshPrematureY)
        )
      {
        pTLB->statusAnalysisMisc.isFarToRoi = TRUE;
      }
      else
      {
        pTLB->statusAnalysisMisc.isFarToRoi = FALSE;
      }
    }

    /*--- DERIVE DEATH AREA ---*/
    if(      (pTLB->TrackingStatus.willBeRemoved == 1)
      &&  (pTLB->statusAnalysisVehicle.isVehicleOncoming == 1)
      )
    {
      xb = pTLB->xcenter;
      yb = pTLB->ycenter;
      /* Filter Tracks with a long life with oncoming status */
      if(    ( pTLB->delta_y_lp_lt > pParams->FilterTracksMinDeltaY)
        &&  (yb > (sint16)pIn->pCamData->RoiYu)
        &&  (pTLB->track_time >= pParams->FilterTracksMinTrackTime)
        &&  (pTLB->statusAnalysisVehicle.isVehicleAhead == FALSE)
        &&  (pTLB->statusAnalysisMisc.isFarToFOE == TRUE)
        &&  (fabsf(pData->Curvature) < pParams->FilterTracksCurvature)
        )
      {  
        /* Filter Premature Dead Oncoming tracks */
        if(pTLB->statusAnalysisMisc.isFarToRoi == 1)
        {
          /* Update Oncoming History Status */    
          if(pData->NewPreDeathCount < UI8_T_MAX)
          {
            pData->NewPreDeathCount ++;
          }

          pData->LastCount = pData->CountOncoming;
          pData->CountOncoming = 0;

          if((pData->bLastCountFirstUpdate) == TRUE)
          {
            pData->bLastCountSecondUpdate = TRUE;
          }
          pData->bLastCountFirstUpdate = TRUE;
        }
        else
        {
          /*--- Death Area ---*/
          HLAHighwayIntersectionMainRoi(  &pData->OncomingHist[pData->DeathAreaInd].DeathAreaX,
            &pData->OncomingHist[pData->DeathAreaInd].DeathAreaY,
            xb,yb,pIn->pCamData,pIn->pTrafficStyle);

          /* RIGHT Hand Traffic Style */
          if(bTrafficStyle_RHD == TRUE)
          {
            DeltaX = pData->OncomingHist[pData->DeathAreaInd].DeathAreaX - pData->ThreshNormalRdwayXb;
            DeltaXbis = pData->ThreshDividedRdwayXb - pData->OncomingHist[pData->DeathAreaInd].DeathAreaX;
          }
          /* LEFT Hand Traffic Style */
          else
          {
            DeltaX = pData->ThreshNormalRdwayXb - pData->OncomingHist[pData->DeathAreaInd].DeathAreaX;
            DeltaXbis = pData->OncomingHist[pData->DeathAreaInd].DeathAreaX - pData->ThreshDividedRdwayXb;
          }

          /* Update Oncoming History Status */
          bOncomingBiased = FALSE;
          if(      (pData->OncomingHist[pData->DeathAreaInd].DeathAreaY > pData->ThreshNormalRdwayYb)
            ||  ((pData->OncomingHist[pData->DeathAreaInd].DeathAreaY == pData->ThreshNormalRdwayYb) && (DeltaX > 0))
            )
          {
            pData->OncomingHist[pData->DeathAreaInd].e_LateralPosition = RTE_HLAR_HIGHWAY_LP_NOT_DTCD;
          }
          else if(  (pData->OncomingHist[pData->DeathAreaInd].DeathAreaY < pData->ThreshDividedRdwayYb)
            ||  ((pData->OncomingHist[pData->DeathAreaInd].DeathAreaY == pData->ThreshDividedRdwayYb) &&  (DeltaXbis > 0))
            )
          {
            /* Re filtering only for divided oncoming */
            if(     (fabsf(pData->Curvature) > pParams->ThreshCurvatureDivided)
              ||  (pIn->pMotionData->f32_Speed < pParams->FilterTracksMinSpeed)
              ||  (pIn->pMotionData->e_MoveState != HLA_MOVE_STATE_FWD)
              )
            {
              bOncomingBiased = TRUE;
            }
            else
            {
              pData->OncomingHist[pData->DeathAreaInd].e_LateralPosition = RTE_HLAR_HIGHWAY_LP_DTCD;
            }
          }
          else 
          {
            pData->OncomingHist[pData->DeathAreaInd].e_LateralPosition = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
          }

          /* update distance to last oncoming vehicle */
          pData->DistToLastOncoming = 0;

          /* Add oncoming to history */
          if(bOncomingBiased == FALSE)
          {
            /* Update New Death Count */
            if(pData->NewDeathCount < UI8_T_MAX)
            {
              pData->NewDeathCount ++;
            }

            /* Update DeathAreaInd */
            pData->DeathAreaInd ++;
            pData->DeathAreaInd = pData->DeathAreaInd % (uint8)pHwyParams->LateralPositionUsedTracks /*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/;

            /* Nb of oncoming +1 */
            if(pData->CountOncoming < UI8_T_MAX)
            {
              pData->CountOncoming ++;
            }
          }
        }    
      }
    }
    pTLB = pTLB->next;
  }

  /* ***********************************
  Description:      Make the decision on the detection of Highway
  *************************************** */

  /* Highway detection over Speed */
  /* Condition to move from IDLE to DTCD*/
  if(pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_UNKNOWN){
      /* Upper Threshold Instant Highway Mode */
      if(       (pIn->pMotionData->f32_Speed > pHwyParams->SpeedDetThreshold_Fast) 
          &&    (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
          &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
          )
      {
          pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_DTCD;
          pData->DistHwaySpeedDction = 0;
      }

      /* Lower Threshold */
      else if(       (pIn->pMotionData->f32_Speed > pHwyParams->SpeedDetThreshold)
          &&    (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureUp)
          &&    (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
          )
      {
          if(pData->DistHwaySpeedDction > pHwyParams->SpeedDetThresholdDistance)
          {
              pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_DTCD;
              pData->DistHwaySpeedDction = 0;
          }
          else
          {
              pData->DistHwaySpeedDction += pIn->pCamData->ddistFwd_m;
          }
      }
      /* Speed too low or curvature too high */
      else if(      (pIn->pMotionData->f32_Speed < pHwyParams->EgoMotionDetThresholdLow) 
                || (fabsf(pData->Curvature) > pParams->HighwayThreshCurvatureUp))
      {
            pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_NOT_DTCD;
            pData->DistHwaySpeedDction = 0;
      }
      else
      {
          pData->DistHwaySpeedDction = 0;
          /* Do nothing */
      }
  }

  /* Condition to move from NOT_DTCD to DTCD*/
  if(       (pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_NOT_DTCD)
      )
  {
      /* Upper Threshold Instant Highway Mode */
      if(       (pIn->pMotionData->f32_Speed > pHwyParams->SpeedDetThreshold_Fast)
          &&    (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
          &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
        )
      {
        pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_DTCD;
        pData->DistHwaySpeedDction = 0;
      }

      /* Lower Threshold */
      else if(       (pIn->pMotionData->f32_Speed > pHwyParams->SpeedDetThreshold)
          &&    (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
          &&    (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
        )
      {
          if(pData->DistHwaySpeedDction > pHwyParams->SpeedDetThresholdDistance)
          {
            pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_DTCD;
            pData->DistHwaySpeedDction = 0;
          }
          else
          {
            pData->DistHwaySpeedDction += pIn->pCamData->ddistFwd_m;
          }
      }
      else
      {
          /* Do nothing */
      }
  }
  /* Condition to move from DTCD to NOT_DTCD */
  if(pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD)
  {
      if( (pIn->pMotionData->f32_Speed < pParams->HighwaySpeedExitThresh) )
      {
        pData->eHighwaySpeedDetection = RTE_HLAR_HIGHWAY_SP_NOT_DTCD;
      }

  }

  /*---  Decision on Ego Motion Range for Highway  ---*/
  /* Conditions to move from Highway NOT Detected to Highway DETECTED */
  if(pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_NOT_DTCD)
  {  
    if(    (pIn->pMotionData->f32_Speed > pHwyParams->EgoMotionDetThresholdHigh)
      &&  (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
      &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
      )
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_DTCD;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
    else 
    {
      pData->eEgoMotion = pData->eEgoMotion;
    }
  }

  /* Conditions to move from Highway DETECTED to Highway NOT Detected : Exit Detected*/
  else if(   (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)
          && (pData->eOcclusionDetection != RTE_HLAR_HIGHWAY_OC_DTCD)
          && (pData->eLateralPosition != RTE_HLAR_HIGHWAY_LP_DTCD)
         )
  {
    if(     (pIn->pMotionData->f32_Speed < pHwyParams->EgoMotionDetThresholdLow) 
      || (fabsf(pData->Curvature) > pParams->HighwayThreshCurvatureUp)
      )
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_NOT_DTCD;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
    else 
    {
      /* Do Nothing */
    }
  }
  else if(pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)
  {
    if(pIn->pMotionData->f32_Speed < pHwyParams->EgoMotionDetThresholdLow) 
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_LOW_SPEED;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
  }
  else if(    (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_LOW_SPEED)
    )
  {
    if(    (pIn->pMotionData->f32_Speed > pHwyParams->EgoMotionDetThresholdHigh)
      &&  (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
      &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
      )
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_DTCD;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
    else if((pData->eOcclusionDetection != RTE_HLAR_HIGHWAY_OC_DTCD) &&  (pData->eLateralPosition != RTE_HLAR_HIGHWAY_LP_DTCD))
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_NOT_DTCD;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
    else
    {
      /* Do nothing */
    }
  }
  else if(pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_UNKNOWN)
  {
    if(    (pIn->pMotionData->f32_Speed > pHwyParams->EgoMotionDetThresholdHigh)
      &&  (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
      &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
      )
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_DTCD;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
    else if(     (pIn->pMotionData->f32_Speed < pHwyParams->EgoMotionDetThresholdLow) 
      || (fabsf(pData->Curvature) > pParams->HighwayThreshCurvatureUp)
      )
    {
      pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_NOT_DTCD;
      pData->ConfEgoMotion = 0.5f;
      pData->DistHwayDction = 0;
    }
    else 
    {
      pData->eEgoMotion = pData->eEgoMotion;
      pData->ConfEgoMotion = pParams->MinConf;
      pData->DistHwayDction = 0;
    }
  }
  else
  {
    /* Do Nothing */
  }

  /* Maybe Highway */
  if((pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_LOW_SPEED) || (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) )
  {
    /* Enable Divided Roadway detection */
    pData->ConfLatPos = CML_f_Min(pParams->MaybeHwayConfRdwayType,pData->ConfLatPos);

    /* Enable occlusion detection */
    if(pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD)
    {
      pData->ConfOcclDction = CML_f_Min(pParams->MaybeHwayConfOccl,pData->ConfOcclDction);
    }
  }

  /* ************************************
  Description:      Make the decision on the detection of a Premature Death of the track
  which could be due to an occlusion
  *************************************** */
  /* Conditions to move from NO occlusion Detected to Occlusion DETECTED */
  if(     (pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_NOT_DTCD) 
    && (pData->OcclusionCount == 0)
    )
  {
    if(    (pData->LastCount <= pHwyParams->OcclusionOncomingLeavingLightsThresh)
      &&  (pData->CountOncoming <= pHwyParams->OcclusionOncomingLeavingLightsThresh)
      &&  (pData->eLateralPosition != RTE_HLAR_HIGHWAY_LP_NOT_DTCD) /* Not Normal Rdway detected */
      )
    {
      pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_DTCD;
      pData->ConfOcclDction = CML_f_Max(  0.5f - (pData->NewPreDeathCount * pHwyParams->OcclusionConfidenceStep),
        pParams->MinConf);

      if(pIn->pCameraParameter->f32_cycleTime>0)
      {
        pData->OcclusionCount = (sint32)(pParams->OcclusionDelay/pIn->pCameraParameter->f32_cycleTime);
      }
      else
      {
        pData->OcclusionCount = 0;
      }
    }
    else
    {
      pData->eOcclusionDetection = pData->eOcclusionDetection;
    }
  }
  /* Conditions to move from occlusion DETECTED to NO Occlusion Detected */
  else if(   (pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD) 
          && (pData->OcclusionCount == 0)
         )
  {  
    if(pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
    {
      /* Set Occlusion detection */
      pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_NOT_DTCD;
      pData->ConfOcclDction = pParams->MinConf;
      pData->LastCount = pHwyParams->OcclusionOncomingLeavingLightsThresh + 1;
      pData->CountOncoming = pHwyParams->OcclusionOncomingLeavingLightsThresh + 1;
    }
    else if(    (pData->LastCount > pHwyParams->OcclusionOncomingLeavingLightsThresh)
      ||  (pData->CountOncoming > pHwyParams->OcclusionOncomingLeavingLightsThresh)
      )
    {
      pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_NOT_DTCD;
      pData->ConfOcclDction = 0.5f;

      if(pIn->pCameraParameter->f32_cycleTime>0)
      {
        pData->OcclusionCount = (sint32)(pParams->OcclusionDelay/pIn->pCameraParameter->f32_cycleTime);
      }
      else
      {
        pData->OcclusionCount = 0;
      }
    }
    else
    {
      pData->eOcclusionDetection = pData->eOcclusionDetection;
    }
  }
  /* Conditions to move from Idle State */
  else if(pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_UNKNOWN )
  {  
    if(    (pData->LastCount > pHwyParams->OcclusionOncomingLeavingLightsThresh) 
      ||  (pData->CountOncoming > pHwyParams->OcclusionOncomingLeavingLightsThresh)
      )
    {
      pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_NOT_DTCD;
      pData->ConfOcclDction = 0.5f;

      if(pIn->pCameraParameter->f32_cycleTime>0)
      {
        pData->OcclusionCount = (sint32)(pParams->OcclusionDelay/pIn->pCameraParameter->f32_cycleTime);
      }
      else
      {
        pData->OcclusionCount = 0;
      }
    }
    else if(    (pData->LastCount <= pHwyParams->OcclusionOncomingLeavingLightsThresh)
      &&  (pData->CountOncoming <= pHwyParams->OcclusionOncomingLeavingLightsThresh)
      &&  (pData->eLateralPosition != RTE_HLAR_HIGHWAY_LP_NOT_DTCD) /* Not Normal Rdway detected */
      &&  (pData->bLastCountSecondUpdate == TRUE)
      )
    {
      pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_DTCD;
      pData->ConfOcclDction = CML_f_Max(  0.5f - (pData->NewPreDeathCount * pHwyParams->OcclusionConfidenceStep),
        pParams->MinConf);

      if(pIn->pCameraParameter->f32_cycleTime>0)
      {
        pData->OcclusionCount = (sint32)(pParams->OcclusionDelay/pIn->pCameraParameter->f32_cycleTime);
      }
      else
      {
        pData->OcclusionCount = 0;
      }
    }
    else
    {
      pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_UNKNOWN;
      pData->OcclusionCount = 0;
      pData->ConfOcclDction = pParams->MinConf;
    }
  }
  else
  {
    pData->OcclusionCount = CML_Max( (pData->OcclusionCount - 1) ,0);
  }

  /* ************************************
  Description:      Confidence Calculation for Highway Detection
  *************************************** */
  /* Update DistHwayDction */
  if(    (pIn->pMotionData->f32_Speed > pHwyParams->EgoMotionDetThresholdHigh)
    &&  (pIn->pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
    &&  (fabsf(pData->Curvature) < pParams->HighwayThreshCurvatureDown)
    )
  {
    pData->DistHwayDction += pIn->pCamData->ddistFwd_m;
    pData->DistHwayUndef = 0;
  }
  else if(     (pIn->pMotionData->f32_Speed < pHwyParams->EgoMotionDetThresholdLow) 
    || (fabsf(pData->Curvature) > pParams->HighwayThreshCurvatureUp)
    )
  {
    pData->DistHwayDction += pIn->pCamData->ddistFwd_m;
    pData->DistHwayUndef = 0;
  }
  else
  {
    pData->DistHwayUndef += pIn->pCamData->ddistFwd_m;
    pData->DistHwayDction = 0;
  }
  /* Update Confidences */
  if( pData->DistHwayDction > pParams->ThreshDistHwayDction)
  {
    pData->ConfEgoMotion = CML_f_Min(  pData->ConfEgoMotion + pParams->StepConfHway,
      pParams->MaxConf );
    pData->DistHwayDction = 0;
  }
  else if(pData->DistHwayUndef > pParams->ThreshDistHwayDction)
  {
    pData->ConfEgoMotion = CML_f_Max(  pData->ConfEgoMotion - pParams->StepConfHway,
      pParams->MinConf );
    pData->DistHwayUndef = 0;
  }
  else
  {
    /* Do Nothing */
  }
  /* ************************************
  Description:      Confidence Calculation of Roadway Type Detection
  *************************************** */
  /* Init/Idle Mode */
  if(pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_UNKNOWN)
  {
    for(i=0;i<CML_Min(pHwyParams->LateralPositionUsedTracks /*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/,pData->NewDeathCount);i++)
    {
      Ind = (uint8) (( ((pData->DeathAreaInd - 1) - i) + pHwyParams->LateralPositionUsedTracks /*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/) % pHwyParams->LateralPositionUsedTracks/*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/);
      if(pData->OncomingHist[Ind].e_LateralPosition == RTE_HLAR_HIGHWAY_LP_DTCD)
      {
        pData->ConfLatPos = CML_f_Min(  pData->ConfLatPos + ((pHwyParams->LateralPositionUsedTracks != 0) ? (1.0f/pHwyParams->LateralPositionUsedTracks) : 0) /*pParams->StepConfDvdRdway*/,
          pParams->MaxConf );
      }
      else if(pData->OncomingHist[Ind].e_LateralPosition == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
      {    
        pData->ConfLatPos = CML_f_Max(  pData->ConfLatPos - pParams->StepConfCtryRdway,
          pParams->MinConf );
        pData->eLateralPosition = RTE_HLAR_HIGHWAY_LP_NOT_DTCD;
      }
      else
      {
        /* Do nothing */
      }
    }

    if(pData->ConfLatPos > pHwyParams->LateralPositionConfidenceThreshHigh)
    {
      pData->eLateralPosition = RTE_HLAR_HIGHWAY_LP_DTCD;
    }
    else
    {
      /* Keep previous state */
    }
  }
  /* Normal Mode */
  else
  {
    for(i=0;i<CML_Min(pHwyParams->LateralPositionUsedTracks/*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/,pData->NewDeathCount);i++)
    {
      Ind = (uint8)(( ((pData->DeathAreaInd - 1) - i) + pHwyParams->LateralPositionUsedTracks/*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/) % pHwyParams->LateralPositionUsedTracks/*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/);
      if(pData->OncomingHist[Ind].e_LateralPosition == RTE_HLAR_HIGHWAY_LP_DTCD)
      {
        pData->ConfLatPos = CML_f_Min(  pData->ConfLatPos + ((pHwyParams->LateralPositionUsedTracks != 0) ? (1.0f/pHwyParams->LateralPositionUsedTracks) : 0) /*pParams->StepConfDvdRdway*/,
          pParams->MaxConf );
      }
      else if(pData->OncomingHist[Ind].e_LateralPosition == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
      {    
        pData->ConfLatPos = CML_f_Max(  pData->ConfLatPos - pParams->StepConfCtryRdway,
          pParams->MinConf );
      }
      else
      {
        /* Do nothing */
      }
    }

    if(pData->ConfLatPos > pHwyParams->LateralPositionConfidenceThreshHigh) 
    {
      pData->eLateralPosition = RTE_HLAR_HIGHWAY_LP_DTCD;
    }
    else if(pData->ConfLatPos < pHwyParams->LateralPositionConfidenceThreshLow)
    {
      pData->eLateralPosition = RTE_HLAR_HIGHWAY_LP_NOT_DTCD;
    }
    else
    {
      /* Keep previous state */
    }
  }

  /* ************************************
  Description:      Confidence Calculation for Occlusion Detection
  *************************************** */
  if(pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD)
  {  
    pData->ConfOcclDction = CML_f_Min(  pData->ConfOcclDction + (pData->NewPreDeathCount * pHwyParams->OcclusionConfidenceStep),
      pParams->MaxConf);

    pData->ConfOcclDction = CML_f_Max(  pData->ConfOcclDction - (pData->NewDeathCount * pParams->StepConfOccl),
      pParams->MinConf);
  }
  else if(pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_NOT_DTCD)
  {
    pData->ConfOcclDction = CML_f_Min(  pData->ConfOcclDction + (pData->NewDeathCount * pParams->StepConfOccl),
                        pParams->MaxConf);

    pData->ConfOcclDction = CML_f_Max(  pData->ConfOcclDction - (pData->NewPreDeathCount * pHwyParams->OcclusionConfidenceStep),
                        pParams->MinConf);
  }
  else
  {
    pData->ConfOcclDction = pParams->MinConf;
  }

  /* ************************************
    Description:      Confidence calculation with distance information
  *************************************** */
  /* Update Confidences */
  if(pData->DistToLastOncoming > pParams->ThreshDistToLastOncoming /* = 999km (disactivate) */)
  {
    pData->ConfLatPos = CML_f_Max(  pData->ConfLatPos - pParams->StepConfDvdRdway,
      pParams->MinConf );
    pData->ConfOcclDction = CML_f_Max(  pData->ConfOcclDction - pParams->StepConfOccl,
      pParams->MinConf );
    pData->DistToLastOncoming = 0;
  }
  else
  {
    /* Do Nothing */
  }

/* ***********************************
    Description:      Highway Exit Detection : 
        -> Analyse the curvature of the road during a certain distance to detect Exit
  *************************************** */
  /* Threshold start integrate yaw */
  if(   (   (pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_DTCD) 
         || (pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD) 
     )
     && (   (pData->DistPossibleExit > 0) 
       || (fabsf(pData->Curvature) > pParams->ThreshCurvatureExit)
     )
     )
  {
    pData->DistPossibleExit += pIn->pCamData->ddistFwd_m;
    pData->YawIntegrate += pIn->pMotionData->f32_YawRate * pIn->pCameraParameter->f32_cycleTime;
    pData->YawIntegrateMin = CML_f_Min(pData->YawIntegrateMin,pData->YawIntegrate);
    pData->YawIntegrateMax = CML_f_Max(pData->YawIntegrateMax,pData->YawIntegrate);
  }
  else
  {
    /* Do Nothing */
  }

  /* Decision */
  if(fabsf(pData->YawIntegrateMax - pData->YawIntegrateMin) > pParams->ThreshYawIntegrate)
  {
    /* Exit Detected */
    pData->bHwayExit = TRUE;

    /* Reset DistPossibleExit */
    pData->DistPossibleExit = 0;
    pData->YawIntegrate = 0;
    pData->YawIntegrateMin = 0;
    pData->YawIntegrateMax = 0;

    /* Reset Death Area History */
    for(i=0;i<pHwyParams->LateralPositionUsedTracks/*HLA_HIGHWAY_DEATH_AREA_NUM_MEAN*/;i++)
    {
      if(bTrafficStyle_RHD == TRUE)
      {
        pData->OncomingHist[i].DeathAreaX = (sint16)(pIn->pCamData->RoiX1);
        pData->OncomingHist[i].DeathAreaY = (sint16)( ((float32)(pData->ThreshDividedRdwayYb)*0.5f) + ((float32)(pData->ThreshNormalRdwayYb)*0.5f) );
      }
      else
      {
        pData->OncomingHist[i].DeathAreaX = (sint16)(pIn->pCamData->RoiX2);
        pData->OncomingHist[i].DeathAreaY = (sint16)( ((float32)(pData->ThreshDividedRdwayYb)*0.5f) + ((float32)(pData->ThreshNormalRdwayYb)*0.5f) );
      }
      pData->OncomingHist[i].e_LateralPosition = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
    }

    /* Reset Rdway Type Detection */
    pData->eLateralPosition = RTE_HLAR_HIGHWAY_LP_UNKNOWN;
    pData->ConfLatPos = pParams->MinConf;

    /* Set Highway Detection */
    pData->eEgoMotion = RTE_HLAR_HIGHWAY_EM_NOT_DTCD;
    pData->ConfEgoMotion = 0.5f;

    /* Set Occlusion Detection */
    pData->eOcclusionDetection = RTE_HLAR_HIGHWAY_OC_NOT_DTCD;
    pData->ConfOcclDction = pParams->MinConf;
    pData->LastCount = pHwyParams->OcclusionOncomingLeavingLightsThresh + 1;
    pData->CountOncoming = pHwyParams->OcclusionOncomingLeavingLightsThresh + 1;
  }
  /* Not an Exit */
  else if(pData->DistPossibleExit > pParams->ThreshDistExit)
  {
    /* Reset DistPossibleExit */
    pData->DistPossibleExit = 0;
    pData->YawIntegrate = 0;
    pData->YawIntegrateMin = 0;
    pData->YawIntegrateMax = 0;
    pData->bHwayExit = FALSE;
  }
  else
  {
    pData->bHwayExit = FALSE;
  }


  /* Description: Set Internal Highway Decision */
  HLAHighwayDecisionHighway(pData, pIn, pParams);

    /* ************************************
  Description:      Set Output
  *************************************** */
  pOut->f32_ConfEgoMotion = pData->ConfEgoMotion;
  pOut->f32_ConfLatPos = pData->ConfLatPos;
  pOut->f32_ConfOcclDtction = pData->ConfOcclDction;

  pOut->e_EgoMotion = pData->eEgoMotion;
  pOut->e_LateralPosition = pData->eLateralPosition;
  pOut->e_OcclusionDetection = pData->eOcclusionDetection;
  pOut->e_SpeedDetection = pData->eHighwaySpeedDetection;

  pOut->e_HighwayOutInternal = pData->internalHighwayState;


}
/* **************************************************************************** 
  Functionname:     HLAHighwayIntersectionMainRoi */ /*!
  Description:      Estimate intersection between a line passing by vanishing point and (CoorIn_X,CoorIn_Y)
          and the left half of the HLA ROI

  @param[in]    -

  @return           -
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void HLAHighwayIntersectionMainRoi( /*OUTPUT*/sint16  *pCoorOut_X, sint16  *pCoorOut_Y,
                  /*INPUT*/sint16    CoorIn_X, sint16  CoorIn_Y, const HLACameraData_t *pCamData, const RTE_HLA_TrafficStyle * pTrafficStyle)
{
  /* Variables */
  float32  Coeff_Line = 0,
      X_Line = 0;
  uint16  hlaROI_X = 0,
      hlaROI_Y = pCamData->RoiY2;
  sint16  EstVanishPointX = (sint16)(pCamData->FOE_x),
      EstVanishPointY = (sint16)(pCamData->FOE_y);
  boolean bTrafficStyle_RHD;

  /* Set bTrafficStyle_RHD */
  if(*pTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
  {
    bTrafficStyle_RHD = TRUE;
  }
  else
  {
    bTrafficStyle_RHD = FALSE;
  }

  /* Set hlaROI_LD_X */
  if(bTrafficStyle_RHD == TRUE)
  {
    hlaROI_X = pCamData->RoiX1;
  }
  else
  {
    hlaROI_X = pCamData->RoiX2;
  }

  /* Line params determination */
  if(CoorIn_X == EstVanishPointX)
  {
    *pCoorOut_X = 0;
    *pCoorOut_Y = 0;
  }
  else if(CoorIn_Y == EstVanishPointY)
  {
    *pCoorOut_X = (sint16) (hlaROI_X);
    *pCoorOut_Y = CoorIn_Y;
  }
  else
  {
    /* Line Params */
    Coeff_Line = (float32)(CoorIn_Y - EstVanishPointY)/(float32)(CoorIn_X - EstVanishPointX);
    X_Line = ( ((float32)EstVanishPointY * (float32)CoorIn_X) - ((float32)EstVanishPointX * (float32)CoorIn_Y) )/((float32)CoorIn_X - (float32)EstVanishPointX);

    /*  Intersection coordinates */
    if( (( (Coeff_Line * (float32)hlaROI_X) + X_Line) - (float32)hlaROI_Y) <= 0) 
    {
      *pCoorOut_X = (sint16)(hlaROI_X);
      *pCoorOut_Y = (sint16)CML_s_Round2Int( (Coeff_Line * (float32)hlaROI_X) + X_Line);
    }
    else
    {
      *pCoorOut_Y = (sint16)(hlaROI_Y);
      *pCoorOut_X = (sint16)CML_s_Round2Int(((float32)hlaROI_Y - X_Line)/Coeff_Line);
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAHighwayDecisionHighway */ /*!
  Description:      Highway Decision - only for internal use

  @param[in]    -

  @return           -
  @pre              -
  @post             -
  @author           Alexander Fischer
**************************************************************************** */
static void HLAHighwayDecisionHighway(HLAHighwayInternalData_t* pData, const HLAHighwayInput_t* pIn, const HLA_t_HighwayParameters* pParams){

    switch(pData->internalHighwayState)
    {
    case RTE_HLAF_MTWY_UNKNOWN:
        if(pIn->eBrightnessState < RTE_HLAR_BRT_TWLGT_3)
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_UNKNOWN;
        }
        else if( pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD) /* Detection over speed only */
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_MOTORWAY;
        }
        else if(    (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_NOT_DTCD)
                    ||  (pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
                    ||  (pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_NOT_DTCD)
                )
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_COUNTRY;
        }
        else if(   (    (pData->eLateralPosition == RTE_HLAR_HIGHWAY_LP_DTCD)      /* high distance between own and oncoming lane */
                        && (pData->ConfLatPos >= pParams->minConfTrans)
                        && (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)       /* motion, high speed */
                    )
                || (    (pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD)        /* occlusion detected */
                    && (pData->ConfOcclDction >= pParams->minConfTrans)
                    && (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)     /* motion, high speed */
                    )
                )
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_MOTORWAY;
        }
        else
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_UNKNOWN;
        }
        break;
    case RTE_HLAF_MTWY_COUNTRY:
        /* country road detected */
        if(    (pIn->eBrightnessState < RTE_HLAR_BRT_TWLGT_3)
            && (pIn->pMotionData->f32_Speed > pParams->minSpeedThresh)
           )
        {
            /* too bright and vehicle speed above activation speed */
            pData->internalHighwayState = RTE_HLAF_MTWY_UNKNOWN;
        }
        else if( pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD) /* Detection over speed only */
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_MOTORWAY;
        }
        else if(    (    (pData->eLateralPosition  == RTE_HLAR_HIGHWAY_LP_DTCD)      /* high distance between own and oncoming lane */
                        && (pData->ConfLatPos >= pParams->minConfTrans)
                        && (pData->eEgoMotion == RTE_HLAR_HIGHWAY_EM_DTCD)   /* motion, high speed */
                        && (pIn->eBrightnessState >= RTE_HLAR_BRT_TWLGT_3) 
                    )
                || (    (pData->eOcclusionDetection == RTE_HLAR_HIGHWAY_OC_DTCD)    /* occlusion detected */
                    && (pData->ConfOcclDction     >= pParams->minConfTrans)
                    && (pData->eEgoMotion   == RTE_HLAR_HIGHWAY_EM_DTCD) /* motion, high speed */
                    && (pIn->eBrightnessState >= RTE_HLAR_BRT_TWLGT_3)
                    )
                )
        {
            /* highway detected */
            pData->internalHighwayState = RTE_HLAF_MTWY_MOTORWAY;  
        }
        else
        {
            /* stay in country road */
            pData->internalHighwayState = RTE_HLAF_MTWY_COUNTRY;  
        }
        break;
    case RTE_HLAF_MTWY_MOTORWAY:

        /* highway detected */
        if(    (pIn->eBrightnessState < RTE_HLAR_BRT_TWLGT_3)
            && (pIn->pMotionData->f32_Speed > pParams->minSpeedThresh)
           )
        {
            /* too bright and vehicle speed above activation speed */
            pData->internalHighwayState = RTE_HLAF_MTWY_UNKNOWN;
        }
        else if( pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_DTCD) /* Detection over speed only */
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_MOTORWAY;
        }
        /* Highway Speed case */
        else if(        (pData->eHighwaySpeedDetection == RTE_HLAR_HIGHWAY_SP_NOT_DTCD)
            &&  (      (pData->eEgoMotion   == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) 
            || (pData->eEgoMotion   == RTE_HLAR_HIGHWAY_EM_LOW_SPEED)
            || (pData->eLateralPosition        == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)
            )
            )
        {
            /* country road detected */
            pData->internalHighwayState = RTE_HLAF_MTWY_COUNTRY;  
        }
        /* external HLAF highway state: FR/ CAN output state */
        else if( (    (pData->eEgoMotion   == RTE_HLAR_HIGHWAY_EM_NOT_DTCD) /* motion, exit detected low speed */
                    || (pData->eEgoMotion   == RTE_HLAR_HIGHWAY_EM_LOW_SPEED) /* motion, exit detected low speed */
                    || (pData->eLateralPosition        == RTE_HLAR_HIGHWAY_LP_NOT_DTCD)     /* low distance between own and oncoming lane */
                  ) 
                )
        {
            /* country road detected */
            pData->internalHighwayState = RTE_HLAF_MTWY_COUNTRY;  
        }
        else
        {
            pData->internalHighwayState = RTE_HLAF_MTWY_MOTORWAY;
        }
        break;
    default:
        /*Error*/
        pData->internalHighwayState = RTE_HLAF_MTWY_UNKNOWN;
        break;
    }
}/* PRQA S 861 1 */
