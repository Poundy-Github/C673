/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackdynamic.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackdynamic.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:08CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:48CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:09CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.27 2014/03/26 11:27:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:45 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.26 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackdynamic.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackdynamic.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.25 2014/03/21 09:38:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:43 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.24 2014/03/19 16:31:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:42 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.23 2014/03/10 13:21:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:08 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/03/04 16:52:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:08 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21 2014/02/24 11:44:39CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - tunnel detection types changed
  CHANGE:                  - removed some unnecessary flags from the simulation INI file (all related to very old visu)
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 24, 2014 11:44:40 AM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.20 2014/02/11 17:24:54CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fixes:
  CHANGE:                  - improved selection of region for tracking
  CHANGE:                  - minor bug fixes for tracking 
  CHANGE:                 
  CHANGE:                 Update in visu:
  CHANGE:                  - new pair visualization
  CHANGE:                  - new features to disable horizon, ROI and vehicle data visu parts
  CHANGE:                  - tunnel visu moved to be part of environment
  CHANGE:                  - minor restructuring of hotkeys
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 11, 2014 5:24:55 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.19 2014/01/24 13:37:46CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:46 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.18 2014/01/21 13:09:11CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:11 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.17 2014/01/05 22:56:38CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: replaced log with logf
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:56:38 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.16 2013/11/21 17:53:36CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:36 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15.1.4 2013/11/21 14:15:30CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:31 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.15.1.3 2013/11/21 13:37:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:30 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15.1.2 2013/11/12 13:44:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:47 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.15.1.1 2013/10/18 13:27:58CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:58 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.15 2013/08/02 15:25:53CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:54 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
**************************************************************************** */
#include "hla_trackdynamic.h"

 /* ~CodeReview ~ID:c69dba4d0a11b0c1773fa9daea874506 ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:(general) pointer parameters (in non-static functions) are not checked for !NULL  */
 /* ~CodeReview ~ID:bfcdeaef2387aa487884503b1d5e22d2 ~Reviewer:CW01\uidv0772 ~Date:17.07.2012 ~Priority:3 ~Comment:(general)  signed and unsigned assignents mixed (e.g. uint8 i = 0; instead of uint8 i = 0u) */
   
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#ifdef PC_SIM
#include <string.h>
#endif

#include "hla_trackmeas.h"
#include "hla_trackmodel.h"
#include "hla_imager.h"


/* kalman time update */
static void HLATrackDynamicKalmanTimeUpdate(      HLATrack_t*                     pTrack,
                                            const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                            const HLATracking3DDataEgomotion_t*   pDataEgomotion
                                           );

/* kalman prediction/update function */
static void HLATrackDynamicKalmanPredictOrUpdate(       HLATrack_t*                     pTrack,
                                                  const HLAKalmanMeasPos_t*             pLNorm,
                                                  const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                                  const HLATracking3DDataRotations_t*   pDataRotations,
                                                  const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                                  const uint8                           inputCommand
                                                );

/* AUTOSAR distance estimate from dynamic tracker */
#ifdef PC_SIM
static void HLATrackDynamicWorldDistanceEstimate(       HLATrack_t*                               pTrack,
                                                  const HLATracking3DDataPreComputed_t*           pDataPreComputed,
                                                  const HLATracking3DParametersDynamicTracker_t*  pParamDynamic
                                                );
#endif


/* dynamic models */
static boolean HLATrackDynamicModelMapUpdate(       float32                       ouw_in,
                                                    float32                       ovw_in,
                                                    float32                       odw_in,
                                                    float32                       ofw_in,
                                                    float32                       os_in,
                                                    float32                       ol_in,
                                                    float32*                      pouw_out,
                                                    float32*                      povw_out,
                                                    float32*                      podw_out,
                                                    float32*                      pofw_out,
                                                    float32*                      pos_out,
                                                    float32*                      pol_out,
                                                    float32*                      pHE,
                                                    float32*                      pHJ,
                                              const HLATracking3DDataRotations_t* pDataRotations
                                            );

static boolean HLATrackDynamicModelTimeUpdate(      float32                       ouw_in,
                                                    float32                       ovw_in,
                                                    float32                       odw_in,
                                                    float32                       ofw_in,
                                                    float32                       os_in,
                                                    float32                       ol_in,
                                                    float32*                      pouw_out,
                                                    float32*                      povw_out,
                                                    float32*                      podw_out,
                                                    float32*                      pofw_out,
                                                    float32*                      pHJ,
                                                    float32*                      pHV,
                                              const HLATracking3DDataEgomotion_t* pDataEgomotion
                                             );

/* **************************************************************************** 
  Functionname:     HLATrackDynamicPredict                               */ /*!  
  Description:      predict track position if static and if dynamic.
                    calculate exclusion area for possible light associations to speed up association algo.

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackDynamicPredict(      HLATrack_t*                         pTrackStart,
                            const HLATracking3DDataEgomotion_t*       pDataEgomotion,
                            const HLATracking3DDataRotations_t*       pDataRotations,
                            const HLATracking3DDataPreComputed_t*     pDataPreComputed,
                            const HLATracking3DParametersMatching_t*  pParamMatching
                           )
{
  HLATrack_t* pTrack;

  /* min-max lux intensity */
  float32     minIntLux;

  /* prepare tracking data */
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    /* dynamic kalman time update */
    HLATrackDynamicKalmanTimeUpdate(pTrack,
                                    pDataPreComputed,
                                    pDataEgomotion
                                   );
   
    /* predict dynamic position and calculate innovation matrix */
    if(pTrack->TrackingStatus.isPredFromPair == 0)
    {
      /* default exclusion area (track will not be able to be associated with any light) */
      pTrack->xmin = UI16_T_MAX;
      pTrack->xmax = 0;
      pTrack->ymin = UI16_T_MAX;
      pTrack->ymax = 0;

      /* calculate dynamic tracker prediction (ox_p,oy_p,osxx,osxy,osyy) and exclusion areea */
      HLATrackDynamicKalmanPredictOrUpdate( pTrack,
                                            0,
                                            pDataEgomotion,
                                            pDataRotations,
                                            pDataPreComputed,
                                            HLA_TRACK_KALMANINPUTCMD_PREDICT
                                          );

      /* predict intensity measurement */
      if(pTrack->stageTrackDynamic.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      {
        minIntLux = HLAImager_GetRed_Lux(pTrack->MaxIntFilt * pParamMatching->factorMaxIntDecrease) - pParamMatching->errMeasIntensityGreyLevel;

        pTrack->minInt12bits = (uint16)CML_f_Max(minIntLux, 0.0f);
      }
    }

#ifdef PC_SIM
    if(   (pTrack->stageTrackDynamic.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      ||  (pTrack->TrackingStatus.isPredFromPair == 1)
      )
    {
      pTrack->xb_pred_dynamic_pix[0] = (pTrack->ox_p)*(pDataPreComputed->FX) + (pDataPreComputed->XO);
      pTrack->xb_pred_dynamic_pix[1] = (pTrack->oy_p)*(pDataPreComputed->FY) + (pDataPreComputed->YO);

      if(pTrack->osxx>=0)
      {
        pTrack->xb_pred_dynamic_pix_3sig[0] = 3*(pDataPreComputed->FX)*sqrtf(pTrack->osxx);
      }
      else
      {
        pTrack->xb_pred_dynamic_pix_3sig[0] = 0;
      }

      if(pTrack->osyy>=0)
      {
        pTrack->xb_pred_dynamic_pix_3sig[1] = 3*(pDataPreComputed->FY)*sqrtf(pTrack->osyy);
      }
      else
      {
        pTrack->xb_pred_dynamic_pix_3sig[1] = 0;
      }
    }

    /* visu exclusion area */
    pTrack->ex_xmin = (float32)pTrack->xmin;
    pTrack->ex_xmax = (float32)pTrack->xmax;
    pTrack->ex_ymin = (float32)pTrack->ymin;
    pTrack->ex_ymax = (float32)pTrack->ymax;
#endif

    pTrack = pTrack->next;
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackDynamicPredictNextCycle                     */ /*!  
  Description:      perform time update for dynamic tracker


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackDynamicPredictNextCycle(       HLATrack_t*                   pTrackStart,
                                      const HLATracking3DDataRotations_t* pDataRotations,
                                      const HLATracking3DDataEgomotion_t* pDataEgomotion
                                    )
{
  HLATrack_t* pTrack;

  /* 3D dynamic landmark */
  float32 ouw;
  float32 ovw;
  float32 odw;
  float32 os;
  float32 ol;
  float32 ofw;

  /* prediction next cycle */
  float32 u_p;
  float32 v_p;

  float32 factor;

  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    /* default prediction */
    u_p = pTrack->ouk;
    v_p = pTrack->ovk; 

  
    /*------------------------------------------------------------*/
    /* dynamic tracker time update */


    /* get 3D dynamic landmark landmark */
    ouw = pTrack->ouw;
    ovw = pTrack->ovw;
    odw = pTrack->odw;
    os = pTrack->os;
    ol = pTrack->ol;
    ofw = pTrack->ofw;

    /* apply dynamic object update */
    boolean bTimeUpdateSuccess = HLATrackDynamicModelTimeUpdate( ouw,
                                                                ovw,
                                                                odw,
                                                                ofw,
                                                                os,
                                                                ol,
                                                                &(ouw),
                                                                &(ovw),
                                                                &(odw),
                                                                &(ofw),
                                                                0,
                                                                0,
                                                                pDataEgomotion
                                                              );

    if(bTimeUpdateSuccess == TRUE)
    {
      /* predict track position if vehicle keeps same motion */
      factor = ofw;
      HLATrackModelMeasurement( ouw,
                                ovw,
                                factor,
                                0.0f,
                                &u_p,
                                &v_p,
                                0,
                                0,
                                0,
                                pDataRotations
                              );
    }

    /* save prediction */
    pTrack->ox_p = u_p;
    pTrack->oy_p = v_p;

    pTrack = pTrack->next;
  }
}




/* **************************************************************************** 
  Functionname:     HLATrackDynamicKalmanUpdate                                */ /*!  
  Description:      Perform update of the kalman dynamic filter (3D position and speed).


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackDynamicKalmanUpdate(       HLATrack_t*                      pTrack,
                                  const HLAKalmanMeasPos_t*              pLNorm,
                                  const HLATracking3DDataEgomotion_t*    pDataEgomotion,
                                  const HLATracking3DDataRotations_t*    pDataRotations,
                                  const HLATracking3DDataPreComputed_t*  pDataPreComputed
#ifdef PC_SIM
                                 ,const HLATracking3DParametersDynamicTracker_t* pParamDynamic
#endif
                                )
{
  if(pLNorm != NULL)
  {
    /* redo prediction before update since egomotion/online cali has changed */
    pTrack->stageTrackDynamic.statusPred = HLA_TRACKSTAGE_KALMAN_INIT;

    /* update dynamic tracker with the associated light */
    HLATrackDynamicKalmanPredictOrUpdate( pTrack,
                                          pLNorm,
                                          pDataEgomotion,
                                          pDataRotations,
                                          pDataPreComputed,
                                          HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT
                                        );

    /* update dynamic tracker counter */
    if(pTrack->stageTrackDynamic.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
    {
      if(pTrack->stageTrackDynamic.trackTimeToReinit < HLA_TRACKSTAGE_MAX_TRACK_TIME)
      {
        pTrack->stageTrackDynamic.trackTimeToReinit++;
      }

      pTrack->stageTrackDynamic.lostTime = 0;
    }
  }
  else
  {
    /* simple update of the dynamic tracker */
    HLATrackDynamicKalmanPredictOrUpdate( pTrack,
                                          0,
                                          pDataEgomotion,
                                          pDataRotations,
                                          pDataPreComputed,
                                          HLA_TRACK_KALMANINPUTCMD_UPDATE_NOLIGHT
                                        );
  }

  if(pTrack->stageTrackDynamic.statusUpdate != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
  {
    pTrack->stageTrackDynamic.winTime = 0;
  }
  
  /* update dynamic tracker distance estimation */
#ifdef PC_SIM
  HLATrackDynamicWorldDistanceEstimate( pTrack,
                                        pDataPreComputed,
                                        pParamDynamic
                                      );
#endif
}

/* **************************************************************************** 
  Functionname:     HLATrackDynamicKalmanTimeUpdate                                   */ /*!  
  Description:      perform time update for dynamic tracker


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackDynamicKalmanTimeUpdate(      HLATrack_t*                     pTrack,
                                            const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                            const HLATracking3DDataEgomotion_t*   pDataEgomotion
                                           )
{
  /* 3D dynamic landmark */
  float32 ouw;
  float32 ovw;
  float32 odw;
  float32 os;
  float32 ol;
  float32 ofw;

  float32 couu;
  float32 covu,covv;
  float32 codu,codv,codd;
  float32 cosu,cosv,cosd,coss;
  float32 colu,colv,cold,cols,coll;

  /* 3D dynamic landmark time update jacobians */
  float32 HJ[9];
  float32 HV[6];

  float32 hj0,hj2;
  float32 hj4,hj5;
  float32 hj8;

  float32 hv0,hv1;
  float32 hv2;
  float32 hv4;

  /* intermediate calculations */
  float32 pwh0;/*, pwh1, pwh2;*/
  float32 pwh3, pwh4;/*, pwh5;*/
  float32 pwh6, pwh7, pwh8;

  float32 psh0, psh1, psh2;
  float32 psh3, psh4, psh5;

  /*------------------------------------------------------------*/
  /* dynamic tracker time update */
  if(pTrack->stageTrackDynamic.statusTimeUpdate != HLA_TRACKSTAGE_KALMAN_INIT)
  {
    /* update status flag */
    pTrack->stageTrackDynamic.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
  }
  else
  {
    /* get 3D dynamic landmark landmark */
    ouw = pTrack->ouw;
    ovw = pTrack->ovw;
    odw = pTrack->odw;
    os = pTrack->os;
    ol = pTrack->ol;
    ofw = pTrack->ofw;
    
    couu = pTrack->couu;
    covu = pTrack->covu;   covv = pTrack->covv;
    codu = pTrack->codu;   codv = pTrack->codv;   codd = pTrack->codd;
    cosu = pTrack->cosu;   cosv = pTrack->cosv;   cosd = pTrack->cosd;    coss = pTrack->coss;
    colu = pTrack->colu;   colv = pTrack->colv;   cold = pTrack->cold;    cols = pTrack->cols;    coll = pTrack->coll;

    /* apply dynamic object update */
    boolean bTimeUpdateSuccess = HLATrackDynamicModelTimeUpdate( ouw,
                                                                ovw,
                                                                odw,
                                                                ofw,
                                                                os,
                                                                ol,
                                                                &(ouw),
                                                                &(ovw),
                                                                &(odw),
                                                                &(ofw),
                                                                HJ,
                                                                HV,
                                                                pDataEgomotion
                                                              );
    if(bTimeUpdateSuccess == b_FALSE)
    {
      /* update status flag */
      pTrack->stageTrackDynamic.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
    }
    else
    {
      /*-----------------------------------------------------------------------------------------*/
      /* get jacobians */
      hj0 = HJ[0];        /*hj1 = HJ[1];*/    hj2 = HJ[2];
      /*hj3 = HJ[3];*/    hj4 = HJ[4];        hj5 = HJ[5];
      /*hj6 = HJ[6];*/    /*hj7 = HJ[7];*/    hj8 = HJ[8];

      hv0 = HV[0];          hv1 = HV[1];
      hv2 = HV[2];          /*hv3 = HV[3];*/
      hv4 = HV[4];          /*hv5 = HV[5];*/

      /* update covariance matrix */
      
      /* PWH = PW*HJ' + PSW'*HV' */
      pwh0 = (couu * hj0) + (codu * hj2)   +   (cosu * hv0) + (colu * hv1);
      /*pwh1 = (covu * hj4) + (codu * hj5)   +   (cosu * hv2);*/
      /*pwh2 = (codu * hj8)                  +   (cosu * hv4);*/

      pwh3 = (covu * hj0) + (codv * hj2)   +   (cosv * hv0) + (colv * hv1);
      pwh4 = (covv * hj4) + (codv * hj5)   +   (cosv * hv2);
      /*pwh5 = (codv * hj8)                  +   (cosv * hv4);*/

      pwh6 = (codu * hj0) + (codd * hj2)   +   (cosd * hv0) + (cold * hv1);
      pwh7 = (codv * hj4) + (codd * hj5)   +   (cosd * hv2);
      pwh8 = (codd * hj8)                  +   (cosd * hv4);

      /* PSH = PSW*HJ' + PS*HV' */
      psh0 = (cosu * hj0) + (cosd * hj2)   +   (coss * hv0) + (cols * hv1);
      psh1 = (cosv * hj4) + (cosd * hj5)   +   (coss * hv2);
      psh2 = (cosd * hj8)                  +   (coss * hv4);

      psh3 = (colu * hj0) + (cold * hj2)   +   (cols * hv0) + (coll * hv1);
      psh4 = (colv * hj4) + (cold * hj5)   +   (cols * hv2);
      psh5 = (cold * hj8)                  +   (cols * hv4);

      /* PW = HJ*PWH + HV*PSH */
      couu = (hj0 * pwh0) + (hj2 * pwh6)   +   (hv0 * psh0) + (hv1 * psh3);
      covu = (hj4 * pwh3) + (hj5 * pwh6)   +   (hv2 * psh0);
      codu = (hj8 * pwh6)                  +   (hv4 * psh0);

      covv = (hj4 * pwh4) + (hj5 * pwh7)   +   (hv2 * psh1);
      codv = (hj8 * pwh7)                  +   (hv4 * psh1);

      codd = (hj8 * pwh8)                  +   (hv4 * psh2);

      /* PSW = PSH */
      cosu = psh0;      cosv = psh1;      cosd = psh2;
      colu = psh3;      colv = psh4;      cold = psh5;

      /* PS = PS */

      if(   (couu < 0)
         || (covv < 0)
         || (codd < 0)
         || (coss < 0)
         || (coll < 0)
         || (odw > HLA_FLT_MAX_LOG)
        )
      {
        /* update status flag */
        pTrack->stageTrackDynamic.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
      }
      else
      {
        /* update status flag */
        pTrack->stageTrackDynamic.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

        /* add process noise to dynamic object tracker */
        coss += pDataPreComputed->coss_proc;
        coll += pDataPreComputed->coll_proc;

        /* set 3D dynamic landmark state */
        pTrack->ouw = ouw;
        pTrack->ovw = ovw;
        pTrack->odw = odw;
        pTrack->os = os;
        pTrack->ol = ol;
        pTrack->ofw = ofw;

        pTrack->couu = couu;
        pTrack->covu = covu;   pTrack->covv = covv;
        pTrack->codu = codu;   pTrack->codv = codv;   pTrack->codd = codd;
        pTrack->cosu = cosu;   pTrack->cosv = cosv;   pTrack->cosd = cosd;    pTrack->coss = coss;
        pTrack->colu = colu;   pTrack->colv = colv;   pTrack->cold = cold;    pTrack->cols = cols;    pTrack->coll = coll;
      }
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackDynamicKalmanPredictOrUpdate                                           */ /*!  
  Description:      measurement equation of the extended Kalman filter (dynamic tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackDynamicKalmanPredictOrUpdate(       HLATrack_t*                     pTrack,
                                                  const HLAKalmanMeasPos_t*             pLNorm,
                                                  const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                                  const HLATracking3DDataRotations_t*   pDataRotations,
                                                  const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                                  const uint8                           inputCommand
                                                )
{
  /* egomotion */
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* 3D dynamic landmark state */
  float32 ouw;
  float32 ovw;
  float32 odw;
  float32 ofw;
  float32 os;
  float32 ol;

  float32 couu;
  float32 covu,covv;
  float32 codu,codv,codd;
  float32 cosu,cosv,cosd,coss;
  float32 colu,colv,cold,cols,coll;

  float32 factor;
  float32 dfactor_dsd;

  /* innovation */
  float32 x_p,y_p;

  float32 sexx;
  float32 sexy,seyy;

  float32 sjxx;
  float32 sjxy,sjyy;

  float32 sxx;
  float32 sxy,syy;

  float32 sixx;
  float32 sixy,siyy;

  float32 dx,dy;

  /* kalman gain */
  float32 pehp0;/*,pehp1;*/
  float32 pehp2,pehp3;
  float32 pehp4,pehp5;
  float32 pehp6,pehp7;

  float32 pjhp0,pjhp1;
  float32 pjhp2,pjhp3;
  float32 pjhp4,pjhp5;
  float32 pjhp6,pjhp7;
  float32 pjhp8,pjhp9;

  float32 kj0,kj1;
  float32 kj2,kj3;
  float32 kj4,kj5;
  float32 kj6,kj7;
  float32 kj8,kj9;

  /* measurement equation jacobians */
  float32 HE[9];
  float32 HJ[9];

  float32 he0;
  float32 he4,he5;

  float32 hj0,hj2;
  float32 hj4,hj5;
  float32 hj8;

  /* exclusion are */
  float32 delta,p;

  /* maha distance */
  float32 dist;

  /* check depth */
  float32 coddmin;
  float32 dodw;

  /*-----------------------------------------------------------------------------------------*/
  /* get state */

  /* get dynamic 3D landmark */
  ouw = pTrack->ouw;
  ovw = pTrack->ovw;
  odw = pTrack->odw;
  ofw = pTrack->ofw;
  os = pTrack->os;
  ol = pTrack->ol;

  couu = pTrack->couu;
  covu = pTrack->covu;   covv = pTrack->covv;
  codu = pTrack->codu;   codv = pTrack->codv;   codd = pTrack->codd;
  cosu = pTrack->cosu;   cosv = pTrack->cosv;   cosd = pTrack->cosd;    coss = pTrack->coss;
  colu = pTrack->colu;   colv = pTrack->colv;   cold = pTrack->cold;    cols = pTrack->cols;    coll = pTrack->coll;

  /* get egomotion */
  eeyy = pDataEgomotion->eeyy;
  eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
  eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;


  /* KALMAN PREDICTION */
  if(   (inputCommand == HLA_TRACK_KALMANINPUTCMD_PREDICT)
     || (inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT)
    )
  {
    if(   (pTrack->stageTrackDynamic.statusPred != HLA_TRACKSTAGE_KALMAN_INIT)
       || (pTrack->stageTrackDynamic.statusTimeUpdate != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      )
    {
      /* set flag */
      pTrack->stageTrackDynamic.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
    }
    else
    {
      /*-----------------------------------------------------------------------------------------*/
      /* predict dynamic landmark */
      factor = ofw;
      dfactor_dsd = ofw;
      HLATrackModelMeasurement( ouw,
                                ovw,
                                factor,
                                dfactor_dsd,
                                &(x_p),
                                &(y_p),
                                0,
                                HE,
                                HJ,
                                pDataRotations
                              );

      /*-----------------------------------------------------------------------------------------*/
      /* get jacobians */
      he0 = HE[0];        /*he1 = HE[1];*/      /*he2 = HE[2];*/
      /*he3 = HE[3];*/    he4 = HE[4];          he5 = HE[5];

      hj0 = HJ[0];        /*hj1 = HJ[1];*/      hj2 = HJ[2];
      /*hj3 = HJ[3];*/    hj4 = HJ[4];          hj5 = HJ[5];



      /* ------------------------------------------------------------------------------------------*/
      /* ------------------------------------------------------------------------------------------*/
      /* calculate innovation matrix */
      /*
      S = HE*(PEHp)
      */

      /* PEHp = PE*HE' */
      pehp0 = (eeyy * he0);
      /*pehp1 = (eepy * he4) + (eery * he5);*/

      pehp2 = (eepy * he0);
      pehp3 = (eepp * he4) + (eerp * he5);

      pehp4 = (eery * he0);
      pehp5 = (eerp * he4) + (eerr * he5);

      /* PJHp = PJJ*HJ' */
      pjhp0 = (couu * hj0) + (codu * hj2);
      /* pjhp1 = (cvu * hj6) + (cdu * hj7);*/

      pjhp2 = (covu * hj0) + (codv * hj2);
      pjhp3 = (covv * hj4) + (codv * hj5);

      pjhp4 = (codu * hj0) + (codd * hj2);
      pjhp5 = (codv * hj4) + (codd * hj5);
      /*
      pjhp6 = (csu * hj0) + (csd * hj2);
      pjhp7 = (csv * hj6) + (csd * hj7);

      pjhp8 = (clu * hj0) + (cld * hj2);
      pjhp9 = (clv * hj6) + (cld * hj7);
      */

      /* S = HC*(PCHp) + HE*(PEHp) + HJ*(PJHp) */
      sexx = (he0 * pehp0);
      sexy = (he4 * pehp2) + (he5 * pehp4);
      seyy = (he4 * pehp3) + (he5 * pehp5);

      sjxx = (hj0 * pjhp0) + (hj2 * pjhp4);
      sjxy = (hj4 * pjhp2) + (hj5 * pjhp4); 
      sjyy = (hj4 * pjhp3) + (hj5 * pjhp5);

      sxx = sexx + sjxx;
      sxy = sexy + sjxy;
      syy = seyy + sjyy;

      /* check validity of the predicted covariance on the measurement */
      if(   (sxx < 0)
         || (syy < 0)
         || (sxx > pDataPreComputed->osxx_max)
         || (syy > pDataPreComputed->osyy_max)
        )
      {
        /* set flag */
        pTrack->stageTrackDynamic.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
      }
      else
      {
        /* set flag */
        pTrack->stageTrackDynamic.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

        /* set output data */
        pTrack->ox_p = x_p;
        pTrack->oy_p = y_p;

        pTrack->osxx = sxx;
        pTrack->osxy = sxy;   pTrack->osyy = syy;
      }

      /* calculate exclusion area for data association */
      if(inputCommand == HLA_TRACK_KALMANINPUTCMD_PREDICT)
      {
        if(pTrack->stageTrackDynamic.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
        {
          /* calculate exclusion area (based on extreme values of egomotion angles ) */

          /* get egomotion extreme */
          eeyy = pDataEgomotion->eeyy_ex;
          eepp = pDataEgomotion->eepp_ex;
          eerr = pDataEgomotion->eerr_ex;

          /* PEHp = PE*HE' */
          pehp0 = (eeyy * he0);
          /*pehp1 = (eepy * he4) + (eery * he5);*/

          /*pehp2 = 0;*/
          pehp3 = (eepp * he4);

          /*pehp4 = 0;*/
          pehp5 = (eerr * he5);

          /* S = HC*(PCHp) + HE*(PEHp) + HJ*(PJHp) */
          sexx = (he0 * pehp0);
          seyy = (he4 * pehp3) + (he5 * pehp5);

          sxx = sexx + sjxx;
          syy = seyy + sjyy;

          if(   (sxx >= 0)
             && (syy >= 0)
            )
          {
            /* width of exclusion area */
            delta = 3.0f * (pDataPreComputed->FX) * sqrtf(sxx);

            /* prediction of horizontal track pixel position */
            p = (pTrack->ox_p * pDataPreComputed->FX) + (pDataPreComputed->XO);
            
            /* horizontal min/max of exclusion area */
            pTrack->xmin = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p - delta);
            pTrack->xmax = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p + delta);

            /* height of exclusion area */
            delta = 3.0f * (pDataPreComputed->FY) * sqrtf(syy);

            /* prediction of vertical track pixel position */
            p = (pTrack->oy_p*pDataPreComputed->FY) + (pDataPreComputed->YO);
            
            /* vertical min/max of exclusion area */
            pTrack->ymin = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p - delta);
            pTrack->ymax = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p + delta);
          }
        }
      }

      /* KALMAN UPDATE */
      if(inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT)
      {
        if(   (pTrack->stageTrackDynamic.statusUpdate != HLA_TRACKSTAGE_KALMAN_INIT)
           || (pLNorm == 0)    /* should be always true when inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT */
           || (pTrack->stageTrackDynamic.statusPred != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
          )
        {
          /* set flag */
          pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
        }
        else
        {
          /* add measurement noise */
          sxx += pLNorm->cxx;
          syy += pLNorm->cyy;

          /* inverse innovation */
          boolean bInverseSuccess = HLATrackUtilsInverseInnovation(sxx,
                                                                  syy,
                                                                  sxy,
                                                                  &sixx,
                                                                  &siyy,
                                                                  &sixy
                                                                 );
          if(bInverseSuccess == b_FALSE)
          {
            /* set flag */
            pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;

            /* remove association */
            pTrack->TrackingStatus.isAssocToRemove = 1;
          }
          else
          {
            /* calculate diff vector */
            dx = pLNorm->x - x_p;
            dy = pLNorm->y - y_p;

            /* calculate distance */
            dist  = dx * dx * sixx;
            dist += dy * dy * siyy;
            dist += dx * dy * (sixy + sixy);

            /* check again maha test */
            if(dist >= HLA_CHI2_VALUE_N2)
            {
              /* set flag */
              pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;

              /* remove association (light outside new prediction area) */
              pTrack->TrackingStatus.isAssocToRemove = 1;
            }
            else
            {
              /* remaining values of PJHp = PJJ*HJ' */
              pjhp1 = (covu * hj4) + (codu * hj5);
            
              pjhp6 = (cosu * hj0) + (cosd * hj2);
              pjhp7 = (cosv * hj4) + (cosd * hj5);

              pjhp8 = (colu * hj0) + (cold * hj2);
              pjhp9 = (colv * hj4) + (cold * hj5);

            /*
              KJ = (PJJ*HJ')*Sinv
              XJ = XJ + KJ*xb
              PJJ = PJJ - KJ*S*KJ'
            */

              /* kalman gain KJ = Temp*Sinv */
              kj0 = (pjhp0 * sixx) + (pjhp1 * sixy);
              kj1 = (pjhp0 * sixy) + (pjhp1 * siyy);

              kj2 = (pjhp2 * sixx) + (pjhp3 * sixy);
              kj3 = (pjhp2 * sixy) + (pjhp3 * siyy);

              kj4 = (pjhp4 * sixx) + (pjhp5 * sixy);
              kj5 = (pjhp4 * sixy) + (pjhp5 * siyy);

              kj6 = (pjhp6 * sixx) + (pjhp7 * sixy);
              kj7 = (pjhp6 * sixy) + (pjhp7 * siyy);

              kj8 = (pjhp8 * sixx) + (pjhp9 * sixy);
              kj9 = (pjhp8 * sixy) + (pjhp9 * siyy);

              /* state update XJ += KJ*xb */
              ouw += (kj0 * dx) + (kj1 * dy);
              ovw += (kj2 * dx) + (kj3 * dy);
              odw += (kj4 * dx) + (kj5 * dy);
              os += (kj6 * dx) + (kj7 * dy);
              ol += (kj8 * dx) + (kj9 * dy);

              /* state covariance update PJJ = PJJ - KJ*S*KJ'*/
              couu -= (pjhp0*kj0) + (pjhp1*kj1);

              covu -= (pjhp2*kj0) + (pjhp3*kj1);
              covv -= (pjhp2*kj2) + (pjhp3*kj3);

              codu -= (pjhp4*kj0) + (pjhp5*kj1);
              codv -= (pjhp4*kj2) + (pjhp5*kj3);
              codd -= (pjhp4*kj4) + (pjhp5*kj5);

              cosu -= (pjhp6*kj0) + (pjhp7*kj1);
              cosv -= (pjhp6*kj2) + (pjhp7*kj3);
              cosd -= (pjhp6*kj4) + (pjhp7*kj5);
              coss -= (pjhp6*kj6) + (pjhp7*kj7);

              colu -= (pjhp8*kj0) + (pjhp9*kj1);
              colv -= (pjhp8*kj2) + (pjhp9*kj3);
              cold -= (pjhp8*kj4) + (pjhp9*kj5);
              cols -= (pjhp8*kj6) + (pjhp9*kj7);
              coll -= (pjhp8*kj8) + (pjhp9*kj9);

              if(   (couu < 0)
                 || (covv < 0)
                 || (codd < 0)
                 || (coss < 0)
                 || (coll < 0)
                 || (odw > HLA_FLT_MAX_LOG)
                )
              {
                /* set flag */
                pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
              }
              else
              {
                /* set flag */
                pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

                /* update ofw */
                ofw = expf(odw);
              }
            }             
          }
        }
      }
    }
  }
 

  /* KALMAN DELAYED UPDATE */
  if(   (inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT)
     || (inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_NOLIGHT)
    )
  {
    if(   (pTrack->stageTrackDynamic.statusDelayedUpdate != HLA_TRACKSTAGE_KALMAN_INIT)
       || (pTrack->stageTrackDynamic.statusTimeUpdate != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
       || (pTrack->stageTrackDynamic.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
       || (   (pTrack->stageTrackDynamic.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
           && (pTrack->TrackingStatus.isAssocToRemove == 0)
          )
      )
    {
      /* set flag */
      pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
    }
    else
    {
      /* apply delayed update equation */
      boolean bMapUpdateSuccess = HLATrackDynamicModelMapUpdate(ouw,
                                                                ovw,
                                                                odw,
                                                                ofw,
                                                                os,
                                                                ol,
                                                                &(ouw),
                                                                &(ovw),
                                                                &(odw),
                                                                &(ofw),
                                                                &(os),
                                                                &(ol),
                                                                HE,
                                                                HJ,
                                                                pDataRotations
                                                               );
      if(bMapUpdateSuccess == b_FALSE)
      {
        /* set flag */
        pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
      }
      else
      {
        /*-----------------------------------------------------------------------------------------*/
        /* get jacobians */
        he0 = HE[0];        /*he1 = HE[1];*/      /*he2 = HE[2];*/
        /*he3 = HE[3];*/    he4 = HE[4];          he5 = HE[5];
        /*he6 = HE[6];*/    /*he7 = HE[7];*/      /*he8 = HE[8];*/

        hj0 = HJ[0];        /*hj1 = HJ[1];*/      hj2 = HJ[2];
        /*hj3 = HJ[3];*/    hj4 = HJ[4];          hj5 = HJ[5];
        /*hj6 = HJ[6];*/    /*hj7 = HJ[7];*/      hj8 = HJ[8];
      
        /*
        hde0 = HDE[0];   hde1 = HDE[1];   hde2 = HDE[2]; 
        hde3 = HDE[3];   hde4 = HDE[4];   hde5 = HDE[5]; 

        hd0 = HD[0];   hd1 = HD[1]; 
        hd2 = HD[2];   hd3 = HD[3]; 
        */
      
        /*
        hde0 = 0;   hde1 = 0;   hde2 = 0; 
        hde3 = 0;   hde4 = 0;   hde5 = 0; 
        
        hd0 = 1;   hd1 = 0; 
        hd2 = 0;   hd3 = 1;
        */

        /* PEHE = PE*HE' */
        pehp0 = (eeyy * he0);
        /*pehp1 = (eepy * he4) + (eery * he5);*/
        /*pehp2 = 0;*/

        pehp3 = (eepy * he0);
        pehp4 = (eepp * he4) + (eerp * he5);
        /*pehp5 = 0;*/

        pehp6 = (eery * he0);
        pehp7 = (eerp * he4) + (eerr * he5);
        /*pehp8 = 0;*/

        /* PH = PW*HJ' */
        pjhp0 = (couu * hj0) + (codu * hj2);
        /*pjhp1 = (covu * hj4) + (codu * hj5);*/
        /*pjhp2 = (codu * hj8);*/

        pjhp3 = (covu * hj0) + (codv * hj2);
        pjhp4 = (covv * hj4) + (codv * hj5);
        /*pjhp5 = (codv * hj8);*/

        pjhp6 = (codu * hj0) + (codd * hj2);
        pjhp7 = (codv * hj4) + (codd * hj5);
        pjhp8 = (codd * hj8);

        /* PW = HE*PE*HE' + HJ*PW*HJ' */
        couu = (he0 * pehp0)                      + (hj0 * pjhp0) + (hj2 * pjhp6);
        covu = (he4 * pehp3) + (he5 * pehp6)      + (hj4 * pjhp3) + (hj5 * pjhp6);
        codu =                                      (hj8 * pjhp6);

        covv = (he4 * pehp4) + (he5 * pehp7)      + (hj4 * pjhp4) + (hj5 * pjhp7);
        codv =                                      (hj8 * pjhp7);

        codd =                                      (hj8 * pjhp8);

        /* PH = PSW*HJ' */
        pjhp0 = (cosu * hj0) + (cosd * hj2);
        pjhp1 = (cosv * hj4) + (cosd * hj5);
        pjhp2 = (cosd * hj8);

        pjhp3 = (colu * hj0) + (cold * hj2);
        pjhp4 = (colv * hj4) + (cold * hj5);
        pjhp5 = (cold * hj8);

        /* PSW = HDE*PE*HE' + HD*PSW*HJ' */
        /*
        cosu = (hde0 * pehp0) + (hde1 * pehp3) + (hde2 * pehp6)     + (hd0 * pjhp0) + (hd1 * pjhp3);
        cosv = (hde0 * pehp1) + (hde1 * pehp4) + (hde2 * pehp7)     + (hd0 * pjhp1) + (hd1 * pjhp4);
        cosd = (hde0 * pehp2) + (hde1 * pehp5) + (hde2 * pehp8)     + (hd0 * pjhp2) + (hd1 * pjhp5);

        colu = (hde3 * pehp0) + (hde4 * pehp3) + (hde5 * pehp6)     + (hd2 * pjhp0) + (hd3 * pjhp3);
        colv = (hde3 * pehp1) + (hde4 * pehp4) + (hde5 * pehp7)     + (hd2 * pjhp1) + (hd3 * pjhp4);
        cold = (hde3 * pehp2) + (hde4 * pehp5) + (hde5 * pehp8)     + (hd2 * pjhp2) + (hd3 * pjhp5);
        */

        cosu = (pjhp0);
        cosv = (pjhp1);
        cosd = (pjhp2);

        colu = (pjhp3);
        colv = (pjhp4);
        cold = (pjhp5);


        /* pehp = PE*HDE' */
        /*
        pehe0 = (eeyy * hde0) + (eepy * hde1) + (eery * hde2);
        pehe1 = (eeyy * hde3) + (eepy * hde4) + (eery * hde5);

        pehe2 = (eepy * hde0) + (eepp * hde1) + (eerp * hde2);
        pehe3 = (eepy * hde3) + (eepp * hde4) + (eerp * hde5);

        pehe4 = (eery * hde0) + (eerp * hde1) + (eerr * hde2);
        pehe5 = (eery * hde3) + (eerp * hde4) + (eerr * hde5);
        */

        /* PH = PS * HD' */
        /*
        ph0 = (coss * hd0) + (cols * hd1);
        ph1 = (coss * hd2) + (cols * hd3);

        ph2 = (cols * hd0) + (coll * hd1);
        ph3 = (cols * hd2) + (coll * hd3);
        */

        /* PS = HDE*PE*HDE' + HD*PS*HD' */
        /*
        coss = (hde0 * pehe0) + (hde1 * pehe2) + (hde2 * pehe4)       + (hd0 * ph0) + (hd1 * ph2);
        cols = (hde3 * pehe0) + (hde4 * pehe2) + (hde5 * pehe4)       + (hd2 * ph0) + (hd3 * ph2);

        coll = (hde3 * pehe1) + (hde4 * pehe3) + (hde5 * pehe5)       + (hd2 * ph1) + (hd3 * ph3);
        */


        /* check estimated distance from dynamic tracker is not too low */
        /* expf(-(pTrack->odw + 3*sqrtf(pTrack->codd)))  <  minDistDynamic */
        /* pTrack->odw + 3*sqrtf(pTrack->codd) > -log(minDist) */
        /* pTrack->codd > [(-log(minDist) - pTrack->odw)/3.0f]^2  */
        dodw = (pDataPreComputed->odw_max - odw)/3.0f;
        coddmin = dodw*dodw;

        if(   (couu < 0)
           || (covv < 0)
           || (codd < 0)
           || (coss < 0)
           || (coll < 0)
           || (odw  > HLA_FLT_MAX_LOG)
           || (codd > coddmin)
          )
        {
          /* set flag */
          pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
        }
        else
        {
          /* reproject dynamic tracker */
          HLATrackModelWorldToCam(&x_p,
                                  &y_p,
                                  ouw,
                                  ovw,
                                  ofw,
                                  pDataRotations
                                 );

          /* check reprojection error */
          dist = 0.0f;
          if(   (pLNorm != 0)
             && (pTrack->TrackingStatus.isAssocToRemove==0)
            )
          {
            HLATrackUtilsMaha22Diag(&dist,
                                    pLNorm->x - x_p,
                                    pLNorm->y - y_p, 
                                    pLNorm->cxx + pLNorm->cxx + pDataPreComputed->sxxRMSE,
                                    pLNorm->cyy + pLNorm->cyy + pDataPreComputed->syyRMSE
                                   );

          }


          if(dist > HLA_CHI2_VALUE_N2)
          {
            /* set flag */
            pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
          }
          else
          {
            /* set flag */
            pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

            /* set 3D dynamic landmark state */
            pTrack->ouw = ouw;
            pTrack->ovw = ovw;
            pTrack->odw = odw;
            pTrack->os  = os;
            pTrack->ol  = ol;
            pTrack->ofw = ofw;

            if(pTrack->TrackingStatus.isRepjFromPair==0)
            {
              pTrack->ouk = x_p;
              pTrack->ovk = y_p;
            }

            pTrack->couu = couu;
            pTrack->covu = covu;   pTrack->covv = covv;
            pTrack->codu = codu;   pTrack->codv = codv;   pTrack->codd = codd;
            pTrack->cosu = cosu;   pTrack->cosv = cosv;   pTrack->cosd = cosd;    pTrack->coss = coss;
            pTrack->colu = colu;   pTrack->colv = colv;   pTrack->cold = cold;    pTrack->cols = cols;    pTrack->coll = coll;
          }
        }        
      }
    }

    /* state and reprojection when update failed */
    if(pTrack->stageTrackDynamic.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
    {
      /*! DECIDE WHAT TO DO WITH THAT TRACK !*/
      if(   (pLNorm != 0)
         && (pTrack->light_ref != 0)
        )
      {
        if(   (pTrack->TrackingStatus.isAssocFromPair == 1)
           || (   (pTrack->TrackingStatus.isAssocFromPair == 0)
               && (pTrack->infoAssoc2Track[0].ID == pTrack->light_ref->LightID)   /* best association to track is light_ref */
               && (pTrack->light_ref->infoAssoc2Light[0].ID == pTrack->TrackID)   /* best association to light_ref is current track */
               && (pTrack->TrackingStatus.isAssocToRemove == 0)
              )
          )
        {
          /*! SAVE TRACK HERE !*/
          /* reinit dynamic tracker */
          HLATrackDynamicKalmanInit(pTrack,
                                    pLNorm,
                                    pDataPreComputed,
                                    pDataRotations
                                   );

          /* set update flag */
          pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_INIT;
          pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

          /* reprojection */
          if(pTrack->TrackingStatus.isRepjFromPair == 0)
          {
            pTrack->ouk = pLNorm->x;
            pTrack->ovk = pLNorm->y;
          }

          /* initialize matching data */
          HLATrackMeasInitMatchingData( pTrack,
                                        pTrack->light_ref
                                      );
        }
        else
        {
          /* remove association */
          pTrack->TrackingStatus.isAssocToRemove = 1;

          /* redo the update but with no light */
          pTrack->stageTrackDynamic.statusUpdate = HLA_TRACKSTAGE_KALMAN_INIT;
          pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_INIT;
          /* A.Manz: recursion is no problem as there is a switch preventing this behaviour */
          /* PRQA S 3670 7 */
          HLATrackDynamicKalmanPredictOrUpdate( pTrack,
                                                0,
                                                pDataEgomotion,
                                                pDataRotations,
                                                pDataPreComputed,
                                                HLA_TRACK_KALMANINPUTCMD_UPDATE_NOLIGHT
                                              );
        }
      }

      /* FOR TRACKS TO BE REMOVED: ensure it still gets a reprojection */
      if(pTrack->stageTrackDynamic.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
      {
        if(pTrack->TrackingStatus.isRepjFromPair == 0)
        {
          if(pTrack->stageTrackDynamic.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
          {
            pTrack->ouk = pTrack->ox_p;
            pTrack->ovk = pTrack->oy_p;
          }
          else
          {
            /* use bad prediction as reprojection */
            factor      = pTrack->ofw;
            dfactor_dsd = pTrack->ofw;
            HLATrackModelMeasurement( pTrack->ouw,
                                      pTrack->ovw,
                                      factor,
                                      dfactor_dsd,
                                      &(x_p),
                                      &(y_p),
                                      0,
                                      0,
                                      0,
                                      pDataRotations
                                    );
            pTrack->ouk = x_p;
            pTrack->ovk = y_p;
          }
        }
      }
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackDynamicKalmanInit                                     */ /*!  
  Description:      initialize dynamic track


  @param[in]        
                    
  @param[out]       
                    

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackDynamicKalmanInit(       HLATrack_t*                     pTrack,
                                const HLAKalmanMeasPos_t*             pLNorm,
                                const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                const HLATracking3DDataRotations_t*   pDataRotations
                              )
{
  /* landmark state */
  float32 ouw,ovw,odw;
  float32 couu;
  float32 covu,covv;
  float32 codu,codv,codd;

  /* landmark depth state */
  float32 ofw;
  float32 cofu,cofv,coff;

  /* jacobian */
  float32 h;
  float32 HJ[9];
  /*
  float32 hj0,hj1,hj2;
  float32 hj3,hj4,hj5;
  float32 hj6,hj7,hj8;

  float32 pqhj0,pqhj1,pqhj2;
  float32 pqhj3,pqhj4,pqhj5;
  float32 pqhj6,pqhj7,pqhj8;
  */

  float32 hj0,hj2;
  float32 hj4,hj5;
  float32 hj8;

  float32 pqhj0;
  float32 pqhj4;
  float32 pqhj6,pqhj7,pqhj8;

  /* image measurement */
  float32 xk;
  float32 yk;
  float32 fk;

  float32 cxx;
  float32 cyy;
  float32 cff;

  /* reset counter */
  pTrack->stageTrackDynamic.trackTimeToReinit = 1;
  pTrack->stageTrackDynamic.traceTimeToReinit = 1;
  pTrack->stageTrackDynamic.lostTime = 0;
  pTrack->stageTrackDynamic.winTime = 0;

  /* get image measurement */
  xk = pLNorm->x;
  yk = pLNorm->y;
  fk = pDataPreComputed->ofw_init;    /* initial depth */

  cxx = pLNorm->cxx;
  cyy = pLNorm->cyy;
  cff = pDataPreComputed->coff_init;    /* depth uncertainty */

  /* get uw and dw */
  HLATrackModelInit(&ouw,
                    &ovw,
                    &ofw,
                    HJ,
                    0,
                    xk,
                    yk,
                    fk,
                    pDataRotations
                   );

  /* get jacobians */
  /*
  hj0 = HJ[0];    hj1 = HJ[1];    hj2 = HJ[2];
  hj3 = HJ[3];    hj4 = HJ[4];    hj5 = HJ[5];
  hj6 = HJ[6];    hj7 = HJ[7];    hj8 = HJ[8];
  */
  hj0 = HJ[0];                    hj2 = HJ[2];
                  hj4 = HJ[4];    hj5 = HJ[5];
                                  hj8 = HJ[8];

  /* calculate PQHJp = Q*HJ' */
  /*
  pqhj0 = (cxx*hj0) + (cyx*hj1) + (cfx*hj2);
  pqhj1 = (cxx*hj3) + (cyx*hj4) + (cfx*hj5);
  pqhj2 = (cxx*hj6) + (cyx*hj7) + (cfx*hj8);
 
  pqhj3 = (cyx*hj0) + (cyy*hj1) + (cfy*hj2);
  pqhj4 = (cyx*hj3) + (cyy*hj4) + (cfy*hj5);
  pqhj5 = (cyx*hj6) + (cyy*hj7) + (cfy*hj8);
 
  pqhj6 = (cfx*hj0) + (cfy*hj1) + (cff*hj2);
  pqhj7 = (cfx*hj3) + (cfy*hj4) + (cff*hj5);
  pqhj8 = (cfx*hj6) + (cfy*hj7) + (cff*hj8);
  */

  pqhj0 = (cxx*hj0);

  pqhj4 = (cyy*hj4);
 
  pqhj6 = (cff*hj2);
  pqhj7 = (cff*hj5);
  pqhj8 = (cff*hj8);

  /* calculate CovUV = H*Q*H' + HC*PC*HC'  = HJ*PQHJp + HC*PCHCp */
  /*
  couu = (hj0*pqhj0) + (hj1*pqhj3) + (hj2*pqhj6);
  covu = (hj3*pqhj0) + (hj4*pqhj3) + (hj5*pqhj6);
  cofu = (hj6*pqhj0) + (hj7*pqhj3) + (hj8*pqhj6);

  covv = (hj3*pqhj1) + (hj4*pqhj4) + (hj5*pqhj7);
  cofv = (hj6*pqhj1) + (hj7*pqhj4) + (hj8*pqhj7);

  coff = (hj6*pqhj2) + (hj7*pqhj5) + (hj8*pqhj8);
  */

  couu = (hj0*pqhj0)               + (hj2*pqhj6);
  covu =                             (hj5*pqhj6);
  cofu =                             (hj8*pqhj6);

  covv =               (hj4*pqhj4) + (hj5*pqhj7);
  cofv =                             (hj8*pqhj7);

  coff =                             (hj8*pqhj8);


  /* transform depth parametrization in odw = log(ofw) */
  odw = logf(ofw);
  h = 1/ofw;  /* jacobian */

  codu = h*cofu;
  codv = h*cofv;
  codd = (h*h)*coff;

  /* fill state vector*/
  pTrack->ouw = ouw;
  pTrack->ovw = ovw;
  pTrack->ofw = ofw;
  pTrack->odw = odw;

  pTrack->couu = couu;
  pTrack->covu = covu;     pTrack->covv = covv;
  pTrack->codu = codu;     pTrack->codv = codv;   pTrack->codd = codd;

  /* initialize speed vector */
  pTrack->os  = 0;
  pTrack->ol  = 0;

  pTrack->coss = pDataPreComputed->coss_init;
  pTrack->coll = pDataPreComputed->coll_init;

  /* set covariances */   
  pTrack->cosu = 0;           pTrack->cosv = 0;       pTrack->cosd = 0;
  pTrack->colu = 0;           pTrack->colv = 0;       pTrack->cold = 0;           pTrack->cols = 0;
}

/* **************************************************************************** 
  Functionname:     HLATrackDynamicKalmanInitFromPair                                     */ /*!  
  Description:      when pair is broken, initialize the dynamic tracker with the pairing state


  @param[in]        
                    
  @param[out]       
                    

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackDynamicKalmanInitFromPair(       HLATrack_t*                           pTrack,
                                        const HLAPair_t*                            pPair,
                                        const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                        const HLATracking3DDataRotations_t*         pDataRotations,
                                        const HLATracking3DParametersMeasurement_t* pParamMeas
                                      )
{
  /* landmark state */
  float32             ouw,ovw,odw;
  float32             couu;
  float32             covu,covv;
  float32             codu,codv,codd;

  /* landmark depth state */
  float32             ofw;
  float32             cofu,cofv,coff;

  /* image measurement */
  float32 xk;
  float32 yk;
  float32 fk;

  float32 cxx;
  float32 cyy;
  float32 cff;

  /* jacobian */
  float32 HJ[9];
  /*
  float32 hj0,hj1,hj2;
  float32 hj3,hj4,hj5;
  float32 hj6,hj7,hj8;

  float32 pqhj0,pqhj1,pqhj2;
  float32 pqhj3,pqhj4,pqhj5;
  float32 pqhj6,pqhj7,pqhj8;
  */

  float32 hj0,hj2;
  float32 hj4,hj5;
  float32 hj8;

  float32 h,hfd;

  float32 pqhj0;
  float32 pqhj4;
  float32 pqhj6,pqhj7,pqhj8;

  /* speed vector update */
  float32 cosy,siny;
  float32 hss,hsy;
  float32 hls,hly;

  float32 p0,p1;
  float32 p2,p3;

  /* light radius */
  float32 radius_pixel_h,radius_pixel_v;

  /* set init flag*/
  pTrack->stageTrackDynamic.trackTimeToReinit = 1;
  pTrack->stageTrackDynamic.traceTimeToReinit = 1;
  pTrack->stageTrackDynamic.lostTime = 0;
  pTrack->stageTrackDynamic.winTime = 0;

  /* get light position */
  xk = pTrack->ouk;
  yk = pTrack->ovk;

  radius_pixel_h = pParamMeas->errMeasPixelMin;
  radius_pixel_v = pParamMeas->errMeasPixelMin;

  cxx = (radius_pixel_h) * (radius_pixel_h) * (pDataPreComputed->factorCxx);
  cyy = (radius_pixel_v) * (radius_pixel_v) * (pDataPreComputed->factorCxx);

  /* calculate inverse scale factor from pair distance */
  /* ~CodeReview ~ID:3825f7346ecd93e3e2b991d4c45fcaea ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:possible divide-by-zero; pP is param of non-static function, is it safe to presume pP->pd is unequal to zero? */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the pair pP can have a 0m distance pd (it would have been removed from the pair list) */
  fk = 1 / pPair->pd;

  /* derivate of fk along pd */
  hfd = - fk * fk;

  /* covariance on fk */
  cff = (hfd) * (pPair->ppdd) * (hfd);

  /* init landmark state */
  HLATrackModelInit(&ouw,
                    &ovw,
                    &ofw,
                    HJ,
                    0,
                    xk,
                    yk,
                    fk,
                    pDataRotations
                   );

  /* get jacobians */
  /*
  hj0 = HJ[0];    hj1 = HJ[1];    hj2 = HJ[2];
  hj3 = HJ[3];    hj4 = HJ[4];    hj5 = HJ[5];
  hj6 = HJ[6];    hj7 = HJ[7];    hj8 = HJ[8];
  */
  hj0 = HJ[0];                    hj2 = HJ[2];
                  hj4 = HJ[4];    hj5 = HJ[5];
                                  hj8 = HJ[8];

  /* calculate PQHJp = Q*HJ' */
  /*
  pqhj0 = (cxx*hj0) + (cyx*hj1) + (cfx*hj2);
  pqhj1 = (cxx*hj3) + (cyx*hj4) + (cfx*hj5);
  pqhj2 = (cxx*hj6) + (cyx*hj7) + (cfx*hj8);
 
  pqhj3 = (cyx*hj0) + (cyy*hj1) + (cfy*hj2);
  pqhj4 = (cyx*hj3) + (cyy*hj4) + (cfy*hj5);
  pqhj5 = (cyx*hj6) + (cyy*hj7) + (cfy*hj8);
 
  pqhj6 = (cfx*hj0) + (cfy*hj1) + (cff*hj2);
  pqhj7 = (cfx*hj3) + (cfy*hj4) + (cff*hj5);
  pqhj8 = (cfx*hj6) + (cfy*hj7) + (cff*hj8);
  */

  pqhj0 = (cxx*hj0);

  pqhj4 = (cyy*hj4);
 
  pqhj6 = (cff*hj2);
  pqhj7 = (cff*hj5);
  pqhj8 = (cff*hj8);

  /* calculate CovUV = H*Q*H' + HC*PC*HC'  = HJ*PQHJp + HC*PCHCp */
  /*
  couu = (hj0*pqhj0) + (hj1*pqhj3) + (hj2*pqhj6);
  covu = (hj3*pqhj0) + (hj4*pqhj3) + (hj5*pqhj6);
  cofu = (hj6*pqhj0) + (hj7*pqhj3) + (hj8*pqhj6);

  covv = (hj3*pqhj1) + (hj4*pqhj4) + (hj5*pqhj7);
  cofv = (hj6*pqhj1) + (hj7*pqhj4) + (hj8*pqhj7);

  coff = (hj6*pqhj2) + (hj7*pqhj5) + (hj8*pqhj8);
  */

  couu = (hj0*pqhj0)               + (hj2*pqhj6);
  covu =                             (hj5*pqhj6);
  cofu =                             (hj8*pqhj6);

  covv =               (hj4*pqhj4) + (hj5*pqhj7);
  cofv =                             (hj8*pqhj7);

  coff =                             (hj8*pqhj8);

  /* transform depth parametrization in odw = log(ofw) */
  odw = logf(ofw);
  h = 1/ofw;  /* jacobian */

  codu = h * cofu;     
  codv = h * cofv;   
  codd = (h * h) * coff;

  /* fill state vector*/
  pTrack->ouw = ouw;
  pTrack->ovw = ovw;
  pTrack->odw = odw;
  pTrack->ofw = ofw;

  /* transform depth parametrization in odw = log(ofw) */
  pTrack->couu = couu;
  pTrack->covu = covu;     pTrack->covv = covv;
  pTrack->codu = codu;     pTrack->codv = codv;   pTrack->codd = codd;

  /* get yaw sinus and cosinus */
  cosy = cosf(pPair->py);
  siny = sinf(pPair->py);

  /* initialize speed vector */
  pTrack->os = (pPair->ps)*cosy;
  pTrack->ol = (pPair->ps)*siny;

  /* get jacobian */
  hss = cosy;
  hsy = (pPair->ps)*(-siny);

  hls = siny;
  hly = (pPair->ps)*(cosy);

  /* initialize covariance on speed vector */
  p0 = (pPair->ppss*hss) + (pPair->ppys*hsy);
  p1 = (pPair->ppss*hls) + (pPair->ppys*hly);

  p2 = (pPair->ppys*hss) + (pPair->ppyy*hsy);
  p3 = (pPair->ppys*hls) + (pPair->ppyy*hly);

  pTrack->coss = (hss*p0) + (hsy*p2);
  pTrack->cols = (hls*p0) + (hly*p2);

  pTrack->coll = (hls*p1) + (hly*p3);

  /* set covariances */   
  pTrack->cosu = 0;           pTrack->cosv = 0;       pTrack->cosd = 0;
  pTrack->colu = 0;           pTrack->colv = 0;       pTrack->cold = 0;
}

/* **************************************************************************** 
  Functionname:     HLATrackDynamicWorldDistanceEstimate                                */ /*!  
  Description:      

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
#ifdef PC_SIM
static void HLATrackDynamicWorldDistanceEstimate(       HLATrack_t*                               pTrack,
                                                  const HLATracking3DDataPreComputed_t*           pDataPreComputed,
                                                  const HLATracking3DParametersDynamicTracker_t*  pParamDynamic
                                                )
{
  float32 min_odw;
  float32 max_odw;

  /* default values */
  pTrack->min_dist_dynamic = pParamDynamic->minDistDynamic;
  pTrack->max_dist_dynamic = pParamDynamic->maxDistDynamic;

  if(pTrack->stageTrackDynamic.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
  {
    if(pTrack->codd >= 0)
    {
      min_odw = pTrack->odw - (3 * sqrtf(pTrack->codd));
      max_odw = pTrack->odw + (3 * sqrtf(pTrack->codd));

      if(    (max_odw>pDataPreComputed->odw_min)
          && (max_odw<pDataPreComputed->odw_max)
          )
      {
        pTrack->min_dist_dynamic = expf(-max_odw);
      }

      if(    (min_odw>pDataPreComputed->odw_min)
          && (min_odw<pDataPreComputed->odw_max)
         )
      {
        pTrack->max_dist_dynamic = expf(-min_odw);
      }
    }
  }

}
#endif


/* **************************************************************************** 
  Functionname:     HLATrackDynamicModelMapUpdate                                         */ /*!  
  Description:      

                    compute landmark dynamic state (ouw,ovw,odw,os,ol) in the current coordinate system
                    depending on:
                    - previous landmark state (ouw(t-1),ovw(t-1),odw(t-1),os(t-1),ol(t-1))
                    - interframe motion


                    -----------------------------------------
                    interframe rotation and translation
                    Xw(t) = RE*(Xw(t-1) - RE)

                    -----------------------------------------
                    landmark parametrisation for dynamic at (t-1)
                    f(t-1) = exp(odw(t-1))
                    xw(t-1) = 1/f(t-1)
                    yw(t-1) = ouw(t-1)/f(t-1)
                    zw(t-1) = ovw(t-1)/f(t-1)

                    -----------------------------------------
                    landmark parametrisation for dynamic at (t)
                    xw(t) = exp(-odw(t))
                    yw(t) = ouw(t)*exp(-odw(t))
                    zw(t) = ovw(t)*exp(-odw(t))


                    -----------------------------------------
                    to sum up:
                    Xw(t-1) = A(t-1)/f(t-1)
 
                    for dynamic:
                    a(t-1) = 1
                    b(t-1) = ouw(t-1)
                    c(t-1) = ovw(t-1)
                    and f(t-1) = exp(odw)

                    Xw(t) = A(t)
 
                    with for dynamic:
                    a(t) = exp(-odw(t))
                    b(t) = ouw(t)*exp(-odw(t))
                    c(t) = ovw(t)*exp(-odw(t))


                    -----------------------------------------
                    developement of interframe rotation and translation
                    Xw(t) = RE*(Xw(t-1) - RE)

                    A(t)  = RE*(A(t-1)/f(t-1) - RE)


                    A(t) = RE*A(t-1)/f(t-1) + RE*(- RE)

                    A(t) = (RE*A(t-1) + f(t-1)*TD)/f(t-1)
                    A(t) = (An(t))/f(t-1)

                    -----------------------------------------
                    solve for odw
                    a(t) = an(t)/f(t-1)

                    exp(-odw(t)) = an(t)/f(t-1)

                    odw(t) = - log(an(t)/f(t-1))
                           = log(f(t-1)) - log(an(t))
                           = odw(t-1) - log(an(t))

                    -----------------------------------------
                    final equation
                    odw(t) = odw(t-1) - log(an(t))
                    ouw(t) = bn(t)/an(t)
                    ovw(t) = cn(t)/an(t)

                    constant speed
                    os(t) = os(t-1)   
                    ol(t) = ol(t-1)


                    with An(t) = RE*A(t-1) + f(t-1)*TD

                    and TD = RE*(- RE)



  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static boolean HLATrackDynamicModelMapUpdate( /* input values */
                                                    float32                       ouw_in,
                                                    float32                       ovw_in,
                                                    float32                       odw_in,
                                                    float32                       ofw_in,
                                                    float32                       os_in,
                                                    float32                       ol_in,
                                              /* output values */
                                                    float32*                      pouw_out,
                                                    float32*                      povw_out,
                                                    float32*                      podw_out,
                                                    float32*                      pofw_out,
                                                    float32*                      pos_out,
                                                    float32*                      pol_out,
                                                    float32*                      pHE,
                                                    float32*                      pHJ,
                                              const HLATracking3DDataRotations_t* pDataRotations
                                            )
{
  boolean bRet;
  float32 iz;
  float32 xiz2;
  float32 yiz2;
  float32 izwm;

  const float32* RE;
  const float32* dRE_dey;
  const float32* dRE_dep;
  const float32* dRE_der;
  float32  re00, re01, re02, re10, re11, re12,re20, re21, re22;

  const float32* VE;
  const float32* dVE_dep;
  const float32* dVE_der;
  float32  ve0, ve1, ve2;

  float32  xw,yw,zw;
  float32  dxw, dyw, dzw;
  
  float32 factor;
  float32 dfactor_dsd;

  RE = &pDataRotations->RE[0];            /* egomotion rotation matrix RE               */
  dRE_dey = &pDataRotations->dRE_dey[0];  /* egomotion derivate along yaw               */
  dRE_dep = &pDataRotations->dRE_dep[0];  /* egomotion derivate along pitch             */
  dRE_der = &pDataRotations->dRE_der[0];  /* egomotion derivate along roll              */

  VE = &pDataRotations->VE[0];            /* egomotion translation vector VE = -RE * TE */
  dVE_dep = &pDataRotations->dVE_dep[0];  /* egomotion derivate along pitch             */
  dVE_der = &pDataRotations->dVE_der[0];  /* egomotion derivate along roll              */

  bRet = b_FALSE;

  /* get factor */
  factor      = ofw_in;
  dfactor_dsd = ofw_in;

  /* calculate egomotion rotation matrix: RE */
  re00 = RE[0];   re01 = RE[1];   re02 = RE[2];
  re10 = RE[3];   re11 = RE[4];   re12 = RE[5];
  re20 = RE[6];   re21 = RE[7];   re22 = RE[8];

  /* get resulting translation */
  ve0 = VE[0];
  ve1 = VE[1];
  ve2 = VE[2];

  /* update xw, yw, zw */
  xw = re00 + (re01*ouw_in) + (re02*ovw_in) + (factor*(ve0));
  yw = re10 + (re11*ouw_in) + (re12*ovw_in) + (factor*(ve1));
  zw = re20 + (re21*ouw_in) + (re22*ovw_in) + (factor*(ve2));

  if(xw < 0)
  {
    bRet = b_FALSE;
  }
  else
  {
    bRet = b_TRUE;

    /* temporary values */
    iz = 1/(xw);

    /* update state */
    *pouw_out = yw*iz;              /* yw / xw          */
    *povw_out = zw*iz;              /* zw / xw          */
    *podw_out = odw_in - logf(xw);  /* ofw_in - log(xw) */
    *pofw_out = ofw_in*iz;          /* ofw_in / xw      */

  /* ~CodeReview ~ID:30c7bfe284b44b0fe7280e9496aed43f ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, code intended to be commented out?\$r\$n */
  /*
    *pos_out = (re00*os_in) + (re01*ol_in);
    *pol_out = (re10*os_in) + (re11*ol_in);
  */
    *pos_out = os_in;
    *pol_out = ol_in;

    if(   (pHE != 0)
       && (pHJ != 0)
      )
    {
      /* temporary values */
      xiz2 = - ((*pouw_out) * iz);
      yiz2 = - ((*povw_out) * iz);
      izwm = - iz;


      /*------------------------------------------------------------------------------------*/
      /* X world derivates */

      /* along ego yaw  */
      /* ~CodeReview ~ID:30c7bfe284b44b0fe7280e9496aed43f ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, code intended to be commented out?\$r\$n */
      /*
      dxw = dRE_dey[0] + (dRE_dey[1]*ouw_in) + (factor*(dVE_dey[0]));
      dyw = dRE_dey[3] + (dRE_dey[4]*ouw_in) + (factor*(dVE_dey[1]));
      dzw = dRE_dey[6] + (dRE_dey[7]*ouw_in) + (factor*(dVE_dey[2]));

      pHE[0] = (dyw*iz) + (dxw*xiz2);
      pHE[3] = (dzw*iz) + (dxw*yiz2);
      pHE[6] = dxw*izwm;*/

      dxw = dRE_dey[0] + (dRE_dey[1]*ouw_in);
      dyw = dRE_dey[3] + (dRE_dey[4]*ouw_in);

      pHE[0] = (dyw*iz) + (dxw*xiz2);

      /* along ego pitch */
      /* ~CodeReview ~ID:30c7bfe284b44b0fe7280e9496aed43f ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, code intended to be commented out?\$r\$n */
      /*
      dxw = dRE_dep[0] + (dRE_dep[1]*ouw_in) + (dRE_dep[2]*ovw_in) + (factor*(dVE_dep[0]));
      dyw = dRE_dep[3] + (dRE_dep[4]*ouw_in) + (dRE_dep[5]*ovw_in) + (factor*(dVE_dep[1]));
      dzw = dRE_dep[6] + (dRE_dep[7]*ouw_in) + (dRE_dep[8]*ovw_in) + (factor*(dVE_dep[2]));

      pHE[1] = (dyw*iz) + (dxw*xiz2);
      pHE[4] = (dzw*iz) + (dxw*yiz2);
      pHE[7] = dxw*izwm;
      */

      dxw = dRE_dep[0] + (dRE_dep[1]*ouw_in) + (dRE_dep[2]*ovw_in) + (factor*(dVE_dep[0]));
      dzw = dRE_dep[6] + (dRE_dep[7]*ouw_in) + (dRE_dep[8]*ovw_in) + (factor*(dVE_dep[2]));

      pHE[4] = (dzw*iz) + (dxw*yiz2);

      /* along ego ROLL */
      /* ~CodeReview ~ID:30c7bfe284b44b0fe7280e9496aed43f ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, code intended to be commented out?\$r\$n */
      /*
      dxw = dRE_der[0] + (dRE_der[1]*ouw_in) + (dRE_der[2]*ovw_in) + (factor*(dVE_der[0]));
      dyw = dRE_der[3] + (dRE_der[4]*ouw_in) + (dRE_der[5]*ovw_in) + (factor*(dVE_der[1]));
      dzw = dRE_der[6] + (dRE_der[7]*ouw_in) + (dRE_der[8]*ovw_in) + (factor*(dVE_der[2]));

      pHE[2] = dyw*iz;
      pHE[5] = dzw*iz;
      pHE[8] = 0;
      */

      dzw = dRE_der[6] + (dRE_der[7]*ouw_in) + (dRE_der[8]*ovw_in) + (factor*(dVE_der[2]));

      pHE[5] = dzw*iz;

      /*------------------------------------------------------------------------------------------*/
      /* calculate dX/(u)  */
      /* ~CodeReview ~ID:30c7bfe284b44b0fe7280e9496aed43f ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, code intended to be commented out?\$r\$n */
      /*
      dxw = re01;
      dyw = re11;
      dzw = re21;

      pHJ[0] = (dyw*iz) + (dxw*xiz2);
      pHJ[3] = (dzw*iz) + (dxw*yiz2);
      pHJ[6] = dxw*izwm;*/

      pHJ[0] = (re11*iz) + (re01*xiz2);

      /* calculate dX/(v)  */
      /* ~CodeReview ~ID:30c7bfe284b44b0fe7280e9496aed43f ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, code intended to be commented out?\$r\$n */
      /*
      dxw = re02;
      dyw = re12;
      dzw = re22;

      pHJ[1] = (dyw*iz) + (dxw*xiz2);
      pHJ[4] = (dzw*iz) + (dxw*yiz2);
      pHJ[7] = dxw*izwm;*/

      pHJ[4] = (re22*iz) + (re02*yiz2);

      /* calculate dX/(sd)  */
      dxw = dfactor_dsd*ve0;
      dyw = dfactor_dsd*ve1;
      dzw = dfactor_dsd*ve2;

      pHJ[2] = (dyw*iz) + (dxw*xiz2);
      pHJ[5] = (dzw*iz) + (dxw*yiz2);
      pHJ[8] = 1 + (dxw*izwm);

  /* ~CodeReview ~ID:9b6e52ab683b5f5e2c73829573f896b6 ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:120938, Is disabled code intended to be disabled? \$r\$n */
  #if 0
      /* ------------------------------------------------- */
      /* speed vector jacobian */

      /* along ego yaw  */
      pHDE[0] = (dRE_dey[0]*os_in) + (dRE_dey[1]*ol_in);
      pHDE[3] = (dRE_dey[3]*os_in) + (dRE_dey[4]*ol_in);
      
      /* along ego pitch */
      pHDE[1] = (dRE_dep[0]*os_in) + (dRE_dep[1]*ol_in);
      pHDE[4] = (dRE_dep[3]*os_in) + (dRE_dep[4]*ol_in);

      /* along ego ROLL */
      pHDE[2] = 0;
      pHDE[5] = (dRE_der[3]*os_in) + (dRE_der[4]*ol_in);

      /* along os */
      pHD[0] = re00;
      pHD[2] = re10;

      /* along ol */
      pHD[1] = re01;
      pHD[3] = re11;
  #endif
    }
  }

  return(bRet);
}

/* **************************************************************************** 
  Functionname:     HLATrackDynamicModelTimeUpdate
  Description:      
 
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
static boolean HLATrackDynamicModelTimeUpdate(/* input */
                                                    float32                       ouw_in,
                                                    float32                       ovw_in,
                                                    float32                       odw_in,
                                                    float32                       ofw_in,
                                                    float32                       os_in,
                                                    float32                       ol_in,
                                              /* output */
                                                    float32*                      pouw_out,
                                                    float32*                      povw_out,
                                                    float32*                      podw_out,
                                                    float32*                      pofw_out,
                                                    float32*                      pHJ,
                                                    float32*                      pHV,
                                              const HLATracking3DDataEgomotion_t* pDataEgomotion
                                             )
{
  boolean bRet = b_FALSE;
  float32 dt = pDataEgomotion->dt;
  float32 factor;
  float32 dfactor_dsd;

  float32 iz;
  float32 xiz2;
  float32 yiz2;
  float32 izwm;

  float32  xw,yw,zw;
  float32  dxw, dyw;

  float32 vxwdt, vywdt, factor_dt;

  /* get factor */
  factor = ofw_in;
  dfactor_dsd = ofw_in;
  
  /* get speed vector */
  factor_dt = factor * dt;
  vxwdt = dt * os_in;
  vywdt = dt * ol_in;

  /* update xw */
  xw = 1      + (factor_dt * os_in);
  yw = ouw_in + (factor_dt * ol_in);
  zw = ovw_in;

  if(xw < 0)
  {
    bRet = b_FALSE;
  }
  else
  {
    /* temporary values */
    iz = 1/(xw);

    /* update uw,vw,dw */
    *pouw_out = yw * iz;
    *povw_out = zw * iz;
    *podw_out = odw_in - logf(xw);
    *pofw_out = ofw_in * iz;

    /* jacobian calculation */
    if(   (pHJ != 0)
       || (pHV != 0)
      )
    {
      /* temporary values */
      xiz2 = - ((*pouw_out) * iz);
      yiz2 = - ((*povw_out) * iz);
      izwm = - iz;

      if(pHJ != NULL)
      {
        /*------------------------------------------------------------------------------------------*/
        /* calculate dX/(u)  */
        /* ~CodeReview ~ID:bd9a752c5b353784c8bcd3b59405fe2d ~Reviewer:CW01\uidv0772 ~Date:18.07.2012 ~Priority:3 ~Comment:(5 times)120938, code intended to be commented out?\$r\$n */
        /*
        dxw = 0;
        dyw = 1;
        dzw = 0;

        pHE[0] = (dyw*iz) + (dxw*xiz2);
        pHE[3] = (dzw*iz) + (dxw*yiz2);
        pHE[6] = dxw*izwm;
        */
        
        pHJ[0] = iz;

        /* calculate dX/(v)  */
        /*
        dxw = 0;
        dyw = 0;
        dzw = 1;

        pHE[1] = (dyw*iz) + (dxw*xiz2);
        pHE[4] = (dzw*iz) + (dxw*yiz2);
        pHE[7] = dxw*izwm;
        */

        pHJ[4] = iz;

        /* calculate dX/(sd)  */
        /*
        dxw = (dfactor_dsd*(vxwdt));
        dyw = (dfactor_dsd*(vywdt));
        dzw = 0;

        pHJ[2] = (dyw*iz) + (dxw*xiz2);
        pHJ[5] = (dzw*iz) + (dxw*yiz2);
        pHJ[8] = 1 + (dxw*izwm);
        */

        dxw = dfactor_dsd * (vxwdt);
        dyw = dfactor_dsd * (vywdt);

        pHJ[2] = (dyw * iz) + (dxw * xiz2);
        pHJ[5] = (dxw * yiz2);
        pHJ[8] = 1 + (dxw * izwm);
      }

      if(pHV != NULL)
      {
        /* calculate dX/(os)  */
        /*
        dxw = factor_dt;
        dyw = 0;
        dzw = 0;

        pHV[0] = dyw*iz + dxw*xiz2;
        pHV[2] = dzw*iz + dxw*yiz2;
        pHV[4] = dxw*izwm;
        */

        pHV[0] = factor_dt * xiz2;
        pHV[2] = factor_dt * yiz2;
        pHV[4] = factor_dt * izwm;

        /* calculate dX/(ol)  */
        /*
        dxw = 0;
        dyw = factor_dt;
        dzw = 0;

        pHV[1] = dyw*iz + dxw*xiz2;
        pHV[3] = dzw*iz + dxw*yiz2;
        pHV[5] = dxw*izwm;
        */

        pHV[1] = factor_dt * iz;
      }
    }

    bRet = b_TRUE;
  }

  return(bRet);
}/* PRQA S 861 1 */
