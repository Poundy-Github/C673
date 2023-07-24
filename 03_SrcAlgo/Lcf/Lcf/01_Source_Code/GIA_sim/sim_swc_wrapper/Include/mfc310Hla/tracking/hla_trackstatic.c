/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackstatic.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackstatic.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:12CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:56CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:13CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.22 2014/03/26 11:27:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:30 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackstatic.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackstatic.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.20 2014/03/21 09:38:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:41 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2014/03/19 16:30:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:59 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.18 2014/03/10 13:20:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:50 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.17 2014/03/05 11:05:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:26 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/03/04 16:52:14CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:15 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/01/24 13:37:56CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:56 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.14 2014/01/21 13:09:19CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:19 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.13 2014/01/10 18:33:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:49 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.12 2013/11/21 17:53:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:51 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11.1.2 2013/11/21 14:15:29CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:29 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.11.1.1 2013/11/21 13:38:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:38:13 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
**************************************************************************** */

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>

#include "hla_trackstatic.h"
#include "hla_trackmeas.h"
#include "hla_trackmodel.h"

/* kalman update */
static void HLATrackStaticKalmanPredictOrUpdate(      HLATrack_t*                             pTrack,
                                                      uint16*                                 p_assoc_type,
                                                const HLAKalmanMeasPos_t*                     pLNorm,
                                                const HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                                const HLATracking3DDataRotations_t*           pDataRotations,
                                                const HLATracking3DParametersStaticTracker_t* pParamStatic
#ifdef PC_SIM
                                              , const HLATracking3DDataPreComputed_t     *pDataPreComputed
#endif
                                               );

/* kalman delayed time update */
static void HLATrackStaticKalmanDelayedUpdate(      HLATrack_t*                   pTrack,
                                              const HLATracking3DDataEgomotion_t* pDataEgomotion,
                                              const HLATracking3DDataRotations_t* pDataRotations
                                             );

/* update world distance in cm */
static void HLATrackStaticWorldDistanceEstimate(      HLATrack_t*                     pTrack,
                                                const HLATracking3DDataPreComputed_t* pDataPreComputed
                                               );

/* **************************************************************************** 
  Functionname:     HLATrackStaticKalmanInit                                           */ /*!  
  Description:      initialize static track


  @param[in]        
                    
  @param[out]       
                    

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
/* ~CodeReview ~ID:62f0946f8415c127e98e89605106653f ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
/* ~CodeReview ~ID:285cbbff30a5b8fb7b2478331310d018 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: pointer parameters of exported functions are not checked for NULL. */
void HLATrackStaticKalmanInit(      HLATrack_t*                     pTrack,
                              const HLAKalmanMeasPos_t*             pLNorm,
                              const HLATracking3DDataPreComputed_t* pDataPreComputed,
                              const HLATracking3DDataRotations_t*   pDataRotations
                             )
{
  /* landmark state */
  float32 uw, vw, dw;
  float32 cuu;
  float32 cvu, cvv;
  float32 cdu, cdv, cdd;

  /* image measurement */
  float32 xk;
  float32 yk;
  float32 fk;

  float32 cxx;
  float32 cyy;
  float32 cff;

  /* jacobian data */
  float32 HJ[9];
  float32 hj0, hj2;
  float32 hj4, hj5;
  float32 hj8;

  float32 pqhj0;
  float32 pqhj4;
  float32 pqhj6, pqhj7, pqhj8;

  /* reset static counter */
  pTrack->stageTrackStatic.trackTimeToReinit = 1;
  pTrack->stageTrackStatic.traceTimeToReinit = 1;
  pTrack->stageTrackStatic.lostTime = 0;
  pTrack->stageTrackStatic.winTime = 0;

  /* reset robust static counter */
  pTrack->countRobustStatic = 0;

  /* get image measurement */
  xk = pLNorm->x;
  yk = pLNorm->y;
  fk = pDataPreComputed->dw_init;   /* initial depth */

  cxx = pLNorm->cxx;
  cyy = pLNorm->cyy;
  cff = pDataPreComputed->cdd_init;   /* depth uncertainty */

  /* get projective coordinates in world cs */
  HLATrackModelInit(&uw,
                    &vw,
                    &dw,
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
  cuu = (hj0*pqhj0) + (hj1*pqhj3) + (hj2*pqhj6);
  cvu = (hj3*pqhj0) + (hj4*pqhj3) + (hj5*pqhj6);
  cdu = (hj6*pqhj0) + (hj7*pqhj3) + (hj8*pqhj6);

  cvv = (hj3*pqhj1) + (hj4*pqhj4) + (hj5*pqhj7);
  cdv = (hj6*pqhj1) + (hj7*pqhj4) + (hj8*pqhj7);

  cdd = (hj6*pqhj2) + (hj7*pqhj5) + (hj8*pqhj8);
  */

  cuu = (hj0*pqhj0)               + (hj2*pqhj6);
  cvu =                             (hj5*pqhj6);
  cdu =                             (hj8*pqhj6);

  cvv =               (hj4*pqhj4) + (hj5*pqhj7);
  cdv =                             (hj8*pqhj7);

  cdd =                             (hj8*pqhj8);

  /* fill landmark covariance matrix element */
  pTrack->uw = uw;
  pTrack->vw = vw;
  pTrack->dw = dw;

  pTrack->cuu = cuu;
  pTrack->cvu = cvu;     pTrack->cvv = cvv;
  pTrack->cdu = cdu;     pTrack->cdv = cdv;   pTrack->cdd = cdd;

  /* min max of world coordinate */
  HLATrackStaticWorldDistanceEstimate(pTrack,
                                      pDataPreComputed
                                     );
}

/* **************************************************************************** 
  Functionname:     HLATrackStaticKalmanUpdate                                */ /*!  
  Description:      Perform update of the kalman static filter (3D position).


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackStaticKalmanUpdate(      HLATrack_t*                             pTrack,
                                const HLAKalmanMeasPos_t*                     pLNorm,
                                const HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                const HLATracking3DDataRotations_t*           pDataRotations,
                                const HLATracking3DDataPreComputed_t*         pDataPreComputed,
                                const HLATracking3DParametersStaticTracker_t* pParamStatic
                               )
{
  /* ~CodeReview ~ID:d4a4660a74d2429d214e064a021116dd ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Preferably declare variables within the scope (compound statement) where they are used (general to this file). */
  uint16 assoc_type;

  if(pTrack->TrackingStatus.reinitStaticNextChance == 1)
  {
    if(pLNorm != 0)
    {
      HLATrackStaticKalmanInit( pTrack,
                                pLNorm,
                                pDataPreComputed,
                                pDataRotations
                              );
      pTrack->TrackingStatus.reinitStaticNextChance = 0;
    }
    else
    {
      /* delayed update static tracker */
      HLATrackStaticKalmanDelayedUpdate(pTrack,
                                        pDataEgomotion,
                                        pDataRotations
                                       );

      pTrack->stageTrackStatic.winTime = 0;
    }

    /* calculate min-max 3D world coordinates */
    HLATrackStaticWorldDistanceEstimate(pTrack,
                                        pDataPreComputed
                                       );
  }
  else
  {


    /* only tracks not used in SLAM */
    if(   (pTrack->light_ref != 0)
       && (pLNorm != 0)
      )
    {
      /* update static tracker */
      HLATrackStaticKalmanPredictOrUpdate(pTrack,
                                          &assoc_type,
                                          pLNorm,
                                          pDataEgomotion,
                                          pDataRotations,
                                          pParamStatic
  #ifdef PC_SIM
                                        , pDataPreComputed
  #endif
                                         );

      /* if meas failed then association is no more static */
      pTrack->light_ref->Status.assoc_type = assoc_type;
    }
#ifdef PC_SIM
    else
    {
      HLATrackStaticKalmanPredictOrUpdate(pTrack,
                                          0,
                                          0,
                                          pDataEgomotion,
                                          pDataRotations,
                                          pParamStatic,
                                          pDataPreComputed
                                         );
    }
#endif

    /* update static tracker counter */
    if(pTrack->stageTrackStatic.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
    {
      if(pTrack->stageTrackStatic.trackTimeToReinit < HLA_TRACKSTAGE_MAX_TRACK_TIME)
      {
        pTrack->stageTrackStatic.trackTimeToReinit++;
      }

      pTrack->stageTrackStatic.lostTime = 0;
    }
    else
    {
      pTrack->stageTrackStatic.winTime = 0;
    }

    /* update robust static counter */
    if(   (pTrack->stageTrackStatic.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
       && (pTrack->light_ref != 0)
       && (pTrack->TrackingStatus.isEpipolarConsistent == 1)
       && (pTrack->light_ref->Status.assoc_type == HLA_TRACKING3D_ASSOCTYPE_STATICROBUST)
      )
    {
      if(pTrack->countRobustStatic < 255)
      {
        pTrack->countRobustStatic++;
      }
    }
    else
    {
      pTrack->countRobustStatic = 0;
    }

    /* delayed update static tracker */
    HLATrackStaticKalmanDelayedUpdate(pTrack,
                                      pDataEgomotion,
                                      pDataRotations
                                     );


    /* check reinitialization of static kalman filter */
    if(   (pTrack->stageTrackStatic.lostTime > pParamStatic->maxCycleLostTimeStatic)
       || ((pTrack->stageTrackStatic.lostTime + pTrack->stageTrackStatic.lostTime) == pTrack->stageTrackStatic.traceTimeToReinit)
       || (pTrack->dw > pParamStatic->maxInverseDepth)
      )
    {
      if(pLNorm != 0)
      {
        HLATrackStaticKalmanInit( pTrack,
                                  pLNorm,
                                  pDataPreComputed,
                                  pDataRotations
                                );
      }
      else
      {
        pTrack->TrackingStatus.reinitStaticNextChance = 1;
      }
    }

    /* calculate min-max 3D world coordinates */
    HLATrackStaticWorldDistanceEstimate(pTrack,
                                        pDataPreComputed
                                       );
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackStaticKalmanPredictOrUpdate                                           */ /*!  
  Description:      measurement equation of the extended Kalman filter (static and full)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackStaticKalmanPredictOrUpdate(      HLATrack_t*                             pTrack,
                                                      uint16*                                 p_assoc_type,
                                                const HLAKalmanMeasPos_t*                     pLNorm,
                                                const HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                                const HLATracking3DDataRotations_t*           pDataRotations,
                                                const HLATracking3DParametersStaticTracker_t* pParamStatic
#ifdef PC_SIM
                                              , const HLATracking3DDataPreComputed_t*         pDataPreComputed
#endif
                                               )
{
  /* egomotion */
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* 3D landmark  */
  float32 uw;
  float32 vw;
  float32 dw;

  float32 cuu;
  float32 cvu, cvv;
  float32 cdu, cdv, cdd;

  /* innovation */
  float32 x_p, y_p;
  float32 sxx;
  float32 sxy, syy;

  float32 sixx;
  float32 sixy, siyy;

  float32 dx,dy;

  /* kalman gain */
  float32 pehp0;/*,pehp1;*/
  float32 pehp2, pehp3;
  float32 pehp4, pehp5;

  float32 pjhp0, pjhp1;
  float32 pjhp2, pjhp3;
  float32 pjhp4, pjhp5;

  float32 kj0, kj1, kj2, kj3, kj4, kj5;

 
  /* measurement equation jacobians */
  float32 HE[6];
  float32 HJ[6];

  float32 he0;
  float32 he4, he5;

  float32 hj0, hj2;
  float32 hj4, hj5;

  float32 dist;

#ifdef PC_SIM
  pTrack->xb_pred_pix[0] = 0;
  pTrack->xb_pred_pix[1] = 0;
  pTrack->xb_pred_pix_3sig[0] = 0;
  pTrack->xb_pred_pix_3sig[1] = 0;
#endif

  /*-----------------------------------------------------------------------------------------*/
  /* get state */

  /* get 3D landmark */
  uw = pTrack->uw;
  vw = pTrack->vw;
  dw = pTrack->dw;

  cuu = pTrack->cuu;
  cvu = pTrack->cvu;    cvv = pTrack->cvv;
  cdu = pTrack->cdu;    cdv = pTrack->cdv;    cdd = pTrack->cdd;

  /* get egomotion */
  eeyy = pDataEgomotion->eeyy;
  eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
  eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;

  /*-----------------------------------------------------------------------------------------*/
  /* predict landmark */
  HLATrackModelMeasurement( uw,
                            vw,
                            dw,
                            1.0f,
                            &(x_p),
                            &(y_p),
                            0,
                            HE,
                            HJ,
                            pDataRotations
                          );

  /*-----------------------------------------------------------------------------------------*/
  /* get jacobians */
  he0 = HE[0];          /*he1 = 0;*//*HE[1];*/    /*he2 = 0;*//*HE[2];*/
  /*he3 = 0;*//*HE[3];*/    he4 = HE[4];          he5 = HE[5];

  hj0 = HJ[0];          /*hj1 = 0;*//*HJ[1];*/    hj2 = HJ[2];
  /*hj3 = 0;*//*HJ[3];*/    hj4 = HJ[4];          hj5 = HJ[5];


  /*-----------------------------------------------------------------------------------------*/
  /* calculate innovation matrix */     /*valid*/

  /* PEHp = PE*HE' */
  pehp0 = (eeyy * he0);
  /* pehp1 = (eepy * he4) + (eery * he5); */

  pehp2 = (eepy * he0);
  pehp3 = (eepp * he4) + (eerp * he5);

  pehp4 = (eery * he0);
  pehp5 = (eerp * he4) + (eerr * he5);

  /* PJHp = PJJ*HJ' */
  pjhp0 = (cuu * hj0) + (cdu * hj2);
  pjhp1 = (cvu * hj4) + (cdu * hj5);

  pjhp2 = (cvu * hj0) + (cdv * hj2);
  pjhp3 = (cvv * hj4) + (cdv * hj5);

  pjhp4 = (cdu * hj0) + (cdd * hj2);
  pjhp5 = (cdv * hj4) + (cdd * hj5);

  /* S = HE*(PEHp) + HJ*(PJHp) */
  sxx = (he0 * pehp0);
  sxy = (he4 * pehp2) + (he5 * pehp4);
  syy = (he4 * pehp3) + (he5 * pehp5);

  sxx += (hj0 * pjhp0) + (hj2 * pjhp4);
  sxy += (hj4 * pjhp2) + (hj5 * pjhp4);
  syy += (hj4 * pjhp3) + (hj5 * pjhp5);

  /* init assoc type */
  if(p_assoc_type != NULL)
  {
    *p_assoc_type = HLA_TRACKING3D_ASSOCTYPE_DYNAMIC;
  }

  if(   (sxx<0)
     || (syy<0)
    )
  {
    /* do nothing */
  }
  else
  {
    /* set prediction flag */
    pTrack->stageTrackStatic.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

#ifdef PC_SIM
    pTrack->xb_pred_pix[0] = (x_p)*(pDataPreComputed->FX) + (pDataPreComputed->XO);
    pTrack->xb_pred_pix[1] = (y_p)*(pDataPreComputed->FY) + (pDataPreComputed->YO);

    if(sxx>=0)
    {
      pTrack->xb_pred_pix_3sig[0] = 3*(pDataPreComputed->FX)*sqrtf(sxx);
    }
    else
    {
      pTrack->xb_pred_pix_3sig[0] = 0;
    }

    if(syy>=0)
    {
      pTrack->xb_pred_pix_3sig[1] = 3*(pDataPreComputed->FY)*sqrtf(syy);
    }
    else
    {
      pTrack->xb_pred_pix_3sig[1] = 0;
    }
#endif


    /*-----------------------------------------------------------------------------------------*/
    /* KALMAN UPDATE if associated measure avalaible */
    if(   (pLNorm!=0)
       && (pParamStatic!=0)
      )
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
        /* do nothing */
      }
      else
      {
        /* calculate diff vector */
        dx = pLNorm->x - x_p;
        dy = pLNorm->y - y_p;

        /* calculate distance */
        dist =  dx * dx * sixx;
        dist += dy * dy * siyy;
        dist += dx * dy * (sixy + sixy);

        /* check again maha test */
        if(dist < HLA_CHI2_VALUE_N2)
        {
          /* calculate current landmark kalman gain and egomotion update state and state covariance*/
          /*
            KJ  = (PJJ*HJ')*Sinv
                = (PJHp)*Sinv
            XJ  = XJ + KJ*xb
            PJJ = PJJ - PJHp*KJ'
          */

          /* kjalman gain KJ = PJHp*Sinv */
          kj0 = (pjhp0 * sixx) + (pjhp1 * sixy);
          kj1 = (pjhp0 * sixy) + (pjhp1 * siyy);
          kj2 = (pjhp2 * sixx) + (pjhp3 * sixy);
          kj3 = (pjhp2 * sixy) + (pjhp3 * siyy);
          kj4 = (pjhp4 * sixx) + (pjhp5 * sixy);
          kj5 = (pjhp4 * sixy) + (pjhp5 * siyy);

          /* 3D landmark update update XJ += KJ*xb */
          uw += (kj0 * dx) + (kj1 * dy);
          vw += (kj2 * dx) + (kj3 * dy);
          dw += (kj4 * dx) + (kj5 * dy);

          /* state covariance update PJJ = PJJ - PJHp*KJ' */
          cuu -= (pjhp0 * kj0) + (pjhp1 * kj1);

          cvu -= (pjhp2 * kj0) + (pjhp3 * kj1);
          cvv -= (pjhp2 * kj2) + (pjhp3 * kj3);

          cdu -= (pjhp4 * kj0) + (pjhp5 * kj1);
          cdv -= (pjhp4 * kj2) + (pjhp5 * kj3);
          cdd -= (pjhp4 * kj4) + (pjhp5 * kj5);

          if(   (cuu<0)
             || (cvv<0)
             || (cdd<0) 
            )
          {
            /* do nothing */
          }
          else
          {
            /* set meas flag */
            pTrack->stageTrackStatic.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;
            
            /* set 3D landmark */
            pTrack->uw = uw;
            pTrack->vw = vw;
            pTrack->dw = dw;

            pTrack->cuu = cuu;
            pTrack->cvu = cvu;    pTrack->cvv = cvv;
            pTrack->cdu = cdu;    pTrack->cdv = cdv;    pTrack->cdd = cdd;

            /* set association type */
            if(p_assoc_type != NULL)
            {
              (*p_assoc_type) = HLA_TRACKING3D_ASSOCTYPE_STATIC;
              
              /* check if static association is robust */
              /* ~CodeReview ~ID:2b26fbc48fc4964ae2b8a6f06d0e2c4b ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Potential division by zero! */
              /* Godreau B, code review findings priority changed from 1 to 3 : sxx>=0 and pLNorm->cxx can not be zero */
              dist = (dx*dx)/(sxx);
              if( dist < pParamStatic->chi2_1_StaticRobust )
              {
                (*p_assoc_type) = HLA_TRACKING3D_ASSOCTYPE_STATICROBUST;
              }
            }
          }
        }
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackStaticKalmanDelayedUpdate                                         */ /*!  
  Description:      Delayed update equation for slam
                    
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackStaticKalmanDelayedUpdate(      HLATrack_t*                   pTrack,
                                              const HLATracking3DDataEgomotion_t* pDataEgomotion,
                                              const HLATracking3DDataRotations_t* pDataRotations
                                             )
{
  /* egomotion */
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* 3D landmark */
  float32 uw;
  float32 vw;
  float32 dw;

  float32 cuu;
  float32 cvu,cvv;
  float32 cdu,cdv,cdd;

  /* intermediate calculations */
  float32 pehp0;
  float32 pehp3,pehp4;
  float32 pehp6,pehp7;

  float32 pjhp0;
  float32 pjhp3,pjhp4;
  float32 pjhp6,pjhp7,pjhp8;

  /* delayed equation jacobians */
  float32 HE[9];
  float32 HJ[9];

  float32 he0;
  float32 he4,he5;

  float32 hj0,hj2;
  float32 hj4,hj5;
  float32 hj8;

  /*-----------------------------------------------------------------------------------------*/
  /* get state */

  /* get egomotion */
  eeyy = pDataEgomotion->eeyy;
  eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
  eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;

  /* get 3D landmark */
  uw = pTrack->uw;
  vw = pTrack->vw;
  dw = pTrack->dw;

  cuu = pTrack->cuu;
  cvu = pTrack->cvu;    cvv = pTrack->cvv;
  cdu = pTrack->cdu;    cdv = pTrack->cdv;    cdd = pTrack->cdd;

  /*------------------------------------------------------------------------------------*/  
  /* apply static delayed update equation */
  HLATrackModelMapUpdate( uw,
                          vw,
                          dw,
                          &(uw),
                          &(vw),
                          &(dw),
                          HE,
                          HJ,
                          pDataRotations
                        );


  /*-----------------------------------------------------------------------------------------*/
  /* get jacobians */
  he0 = HE[0];          /*he1 = 0;*//*HE[1];*/    /*he2 = 0;*//*HE[2];*/
  /*he3 = 0;*//*HE[3];*/    he4 = HE[4];          he5 = HE[5];
  /*he6 = 0;*//*HE[6];*/    /*he7 = 0;*//*HE[7];*/    /*he8 = 0;*//*HE[8];*/

  hj0 = HJ[0];          /*hj1 = 0;*//*HJ[1];*/    hj2 = HJ[2];
  /*hj3 = 0;*//*HJ[3];*/    hj4 = HJ[4];          hj5 = HJ[5];
  /*hj6 = 0;*//*HJ[6];*/    /*hj7 = 0;*//*HJ[7];*/        hj8 = HJ[8];

  /*----------------------------------------------------*/
  /* UPDATE COVARIANCE MATRIX */

  /* PJ = HE*(PE*HE' + PJE'*HJ') + HJ*(PJE*HE' + PJ*HJ') for full egomotion */
  /* PJ = HE*(PE*HE') + HJ*(PJ*HJ') for simple static tracker */


  /* PEHp = PE*HE' */
  pehp0 = (eeyy * he0);

  pehp3 = (eepy * he0);
  pehp4 = (eepp * he4) + (eerp * he5);

  pehp6 = (eery * he0);
  pehp7 = (eerp * he4) + (eerr * he5);

  /* PJHJp = PJ*HJ' */
  pjhp0 = (cuu * hj0) + (cdu * hj2);

  pjhp3 = (cvu * hj0) + (cdv * hj2);
  pjhp4 = (cvv * hj4) + (cdv * hj5);

  pjhp6 = (cdu * hj0) + (cdd * hj2);
  pjhp7 = (cdv * hj4) + (cdd * hj5);
  pjhp8 = (cdd * hj8);

  
  /* PJ = HE*(PEHp) + HJ*(PJHJp) */
  cuu = (he0 * pehp0) + (hj0 * pjhp0) + (hj2 * pjhp6);

  cvu = (he4 * pehp3) + (he5 * pehp6) + (hj4 * pjhp3) + (hj5 * pjhp6);
  cvv = (he4 * pehp4) + (he5 * pehp7) + (hj4 * pjhp4) + (hj5 * pjhp7);

  cdu = (hj8 * pjhp6);
  cdv = (hj8 * pjhp7);
  cdd = (hj8 * pjhp8);

  if(   (cuu<0)
     || (cvv<0)
     || (cdd<0) 
    )
  {
    /* do nothing */
  }
  else
  {
    pTrack->stageTrackStatic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;
    
    /* save state */
    pTrack->uw = uw;
    pTrack->vw = vw;
    pTrack->dw = dw;

    pTrack->cuu = cuu;
    pTrack->cvu = cvu;    pTrack->cvv = cvv;
    pTrack->cdu = cdu;    pTrack->cdv = cdv;    pTrack->cdd = cdd;
  }

}
/* **************************************************************************** 
  Functionname:     HLATrackStaticWorldDistanceEstimate                                       
  Description:      
                    calculate world coordinates and their uncertainty

                    xw = 1/dw
                    yw = uw/dw
                    zw = vw/dw

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
static void HLATrackStaticWorldDistanceEstimate(      HLATrack_t*                     pTrack,
                                                const HLATracking3DDataPreComputed_t* pDataPreComputed
                                               )
{
  float32 xw, yw, zw;
  float32 varxw, varyw, varzw;
  float32 hxd, hyu, hyd, hzv, hzd;

  float32 ixw, ixw2, sig3;


  /* temporary values */
  /* ~CodeReview ~ID:7bde6a0c5eb45b5bbcc54c1b0b8d8a81 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Potential division by zero! */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
  ixw = (1/pTrack->dw);
  ixw2 = ixw*ixw;

  /* world coordinates */
  xw = ixw;
  yw = (pTrack->uw*ixw);
  zw = (pTrack->vw*ixw);

  /* world coordinates derivates along dw*/
  hxd = - ixw2;
  hyd = - (pTrack->uw*ixw2);
  hzd = - (pTrack->vw*ixw2);

  hyu = ixw;
  hzv = ixw;

  /* variance in xw,yw,zw */
  varxw = (hxd*hxd)*(pTrack->cdd);
  varyw = ((hyd*hyd)*(pTrack->cdd)) + ((hyu*hyu)*(pTrack->cuu)) + ((2*(hyu*hyd))*(pTrack->cdu));
  varzw = ((hzd*hzd)*(pTrack->cdd)) + ((hzv*hzv)*(pTrack->cvv)) + ((2*(hzv*hzd))*(pTrack->cdv));

  /* min max of world coordinate (3 sigma) */
  if(varxw >= 0)
  {
    sig3 = 3.0f*sqrtf(varxw);
    pTrack->xwmin100 = (uint16)CML_MinMax(pDataPreComputed->xwmin100_absolute, pDataPreComputed->xwmax100_absolute, 100*(xw - sig3));
    pTrack->xwmax100 = (uint16)CML_MinMax(pDataPreComputed->xwmin100_absolute, pDataPreComputed->xwmax100_absolute, 100*(xw + sig3));
  }
  else
  {
    pTrack->xwmin100 = 0;
    pTrack->xwmax100 = UI16_T_MAX;
  }

  if(varyw >= 0)
  {
    sig3 = 3.0f*sqrtf(varyw);
    pTrack->ywmin100 = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, 100*(yw - sig3));
    pTrack->ywmax100 = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, 100*(yw + sig3));
  }
  else
  {
    pTrack->ywmin100 = SI16_T_MIN;
    pTrack->ywmax100 = SI16_T_MAX;
  }

  if(varzw >= 0)
  {
    sig3 = 3.0f*sqrtf(varzw);
    pTrack->zwmin100 = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, 100*(zw - sig3));
    pTrack->zwmax100 = (sint16)CML_MinMax(SI16_T_MIN, SI16_T_MAX, 100*(zw + sig3));
  }
  else
  {
    pTrack->zwmin100 = SI16_T_MIN;
    pTrack->zwmax100 = SI16_T_MAX;
  }
}/* PRQA S 861 1 */
