/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_lightdist.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_lightdist.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:08CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:47CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:08CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.16 2014/03/28 10:53:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Better distance estimation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:53:10 AM CET]
  CHANGE:                 Change Package : 207432:50 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/03/26 11:27:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:37 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.14 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_lightdist.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_lightdist.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.13 2014/03/19 16:30:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:38 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.12 2014/03/10 13:20:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:56 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11 2014/03/04 16:52:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:04 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.10 2014/02/06 16:01:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:34 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.9 2013/12/18 15:18:04CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:04 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.8 2013/08/02 15:25:52CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:52 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.7 2013/04/12 12:45:14CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:15 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.6 2012/10/18 17:55:47CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:55:48 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.5 2012/08/09 12:00:00CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 Anayse Humic code review findings
  CHANGE:                 Set proper priorities
  CHANGE:                 --- Added comments ---  uid28828 [Aug 9, 2012 12:00:00 PM CEST]
  CHANGE:                 Change Package : 135871:2 http://mks-psad:7002/im/viewissue?selection=135871
  CHANGE:                 Revision 1.4 2012/07/23 12:57:59CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:57:59 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.3 2012/02/20 15:07:48CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Finish restucturing of tracking algo
  CHANGE:                 --- Added comments ---  uid28828 [Feb 20, 2012 3:07:48 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.2 2012/01/26 14:35:51CET Godreau, Bertrand (uid28828) 
  CHANGE:                 fix light/object distance for very close objects
  CHANGE:                 --- Added comments ---  uid28828 [Jan 26, 2012 2:35:51 PM CET]
  CHANGE:                 Change Package : 94857:1 http://mks-psad:7002/im/viewissue?selection=94857
  CHANGE:                 Revision 1.1 2012/01/25 17:34:18CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */
#include "hla_lightdist.h"

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>


/* init lighting distance */
static void HLALightDistInit(
                      HLATrack_t                                     *pT,
                      const HLATracking3DDataRotations_t             *pDataRotations,
                      const HLATracking3DDataPreComputed_t           *pDataPreComputed,
                      const HLATracking3DParametersDistFromHeight_t  *pParamDistFromHeight
                      );

static void HLALightDistFilter(
                              HLATrackDist_t                   *pdistFilt,
                              const float32                    dmean_new_meter,
                              const float32                    deltad_new_meter,
                              const float32                    minDist_meter,
                              const float32                    maxDist_meter,
                              const float32                    c0
                              );

static void HLALightDistFromVehicleHeightHypothesis(float32                                        *pdmean,
                                               float32                                        *pdeltad,
                                               const HLATrack_t                               *pT, 
                                               const HLATracking3DDataRotations_t             *pDataRotations,
                                               const HLATracking3DDataPreComputed_t           *pDataPreComputed,
                                               const HLATracking3DParametersDistFromHeight_t  *pParamDistFromHeight
                                               );

static void HLALightModelDistFromHeight( 
                                              float32 *pxw, 
                                              float32 *pHJ, 
                                              float32 *pHC, 
                                              const float32 uk, 
                                              const float32 vk,
                                              const float32 zw,
                                              const HLATracking3DDataRotations_t    *pDataRotations
                                              );



/* **************************************************************************** 
  Functionname:     HLALightDistInit                            */ /*!  
  Description:      


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
/* ~CodeReview ~ID:db9f36252f96791c5f89ca516daf84aa ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: poorly documented. */
static void HLALightDistInit(
                      HLATrack_t                                     *pT,
                      const HLATracking3DDataRotations_t             *pDataRotations,
                      const HLATracking3DDataPreComputed_t           *pDataPreComputed,
                      const HLATracking3DParametersDistFromHeight_t  *pParamDistFromHeight
                      )
{
  float32 dmean_height;
  float32 deltad_height;

  /* get new distance measurement from height hypothesis */
  HLALightDistFromVehicleHeightHypothesis(&dmean_height,
    &deltad_height,
    pT, 
    pDataRotations,
    pDataPreComputed,
    pParamDistFromHeight
    );

  /* distance estimation */
  pT->lightDist.distMin_cm  = (uint16)(100*CML_f_MinMax(pParamDistFromHeight->minDist,pParamDistFromHeight->maxDist, dmean_height - deltad_height));
  pT->lightDist.distMax_cm  = (uint16)(100*CML_f_MinMax(pParamDistFromHeight->minDist,pParamDistFromHeight->maxDist, dmean_height + deltad_height));
  pT->objectDist.distMin_cm = pT->lightDist.distMin_cm;
  pT->objectDist.distMax_cm = pT->lightDist.distMax_cm;
}


/* **************************************************************************** 
  Functionname:     HLATracking3DUpdateLightingDistance                            */ /*!  
  Description:      update lighting distance and object distance output for function part


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
/* ~CodeReview ~ID:d0ff3bf1d674f5c9acce427961085411 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Not all pointer parameters of exported functions are not checked for NULL. */
void HLALightDistUpdate(
                         HLATrack_t                                    *pTLB_Start,
                         HLAPair_t                                     *pPairStart,
                         const HLATracking3DDataPreComputed_t          *pDataPreComputed, 
                         const HLATracking3DDataRotations_t            *pDataRotations,
                         const HLATracking3DParametersDistFromHeight_t *pParamDistFromHeight,
                         const HLATracking3DParametersPairing_t        *pParamPairing,
                         const RTE_HLAR_ParameterDistEst_t             *pCpar_DistEst
                        )
{
  HLATrack_t *pT;
  
  float32 c0;
  /* ~CodeReview ~ID:57a7708c349059074af5bf8c83881c82 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Preferably declare variables within the scope (compound statement) where they are used (general to this file). */
  float32 dmean_height;
  float32 deltad_height;
  float32 dmean_pair;
  float32 deltad_pair;
  float32 minDist;
  float32 maxDist;
  HLAPair_t *pPair;

  /* distance filter constant */
  c0 = pCpar_DistEst->DistFilterConst;

  pT = pTLB_Start;
  while(pT != NULL)
  {
    if(pT->trace_time == 1)
    {
      /* init light/object distance */
      HLALightDistInit(pT, pDataRotations, pDataPreComputed, pParamDistFromHeight);
    }
    else
    {
      if(pT->TrackingStatus.isTrackedInPair == 0)
      {
        /* get new distance measurement from height hypothesis */
        HLALightDistFromVehicleHeightHypothesis(&dmean_height,
                                           &deltad_height,
                                           pT, 
                                           pDataRotations,
                                           pDataPreComputed,
                                           pParamDistFromHeight
                                           );

        /* ------------------------------------------------------------------------------------------- */
        /* update lighting distance */
        HLALightDistFilter(&(pT->lightDist),
                                    dmean_height,
                                    deltad_height,
                                    pParamDistFromHeight->minDist,
                                    pParamDistFromHeight->maxDist,
                                    c0
                                    );

        /* ------------------------------------------------------------------------------------------- */
        /* update object dist */
        HLALightDistFilter(&(pT->objectDist),
                                    dmean_height,
                                    deltad_height,
                                    pParamDistFromHeight->minDist,
                                    pParamDistFromHeight->maxDist,
                                    c0
                                    );
      }
    }

    /* next object track */
    pT = pT->next; 
  }


  /* update object distance for pairs */
  pPair = pPairStart;
  while(pPair != NULL)
  {
    if(pPair->bit_isTracked == 1)
    {
      /* -------------------------------------------------------------------------- */
      /* get distance new measurement from pairing  */
      dmean_pair  = pPair->pd;
      deltad_pair = 3.0f*sqrtf(pPair->ppdd); 

      /* get max/min distance from traffic type */
      if( pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_ONCOMING)
      {
        minDist = pParamPairing->paramPairOncoming.minDistEnd;
        maxDist = pParamPairing->paramPairOncoming.maxDist;
      }
      else if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
      {
        minDist = pParamPairing->paramPairTruckLights.minDistEnd;
        maxDist = pParamPairing->paramPairTruckLights.maxDist;
      }
      else
      {
        minDist = pParamPairing->paramPairAhead.minDistEnd;
        maxDist = pParamPairing->paramPairAhead.maxDist;
      }

      /* -------------------------------------------------------------------------- */
      /* update left object distance with pair measurement */
      HLALightDistFilter(&(pPair->pTLeft->objectDist),
                                  dmean_pair,
                                  deltad_pair,
                                  minDist,
                                  maxDist,
                                  c0
                                  );
#if 0
      /* get distance measurement from height hypothesis */
      HLALightDistFromVehicleHeightHypothesis(&dmean_height,
                                         &deltad_height,
                                         pPair->pTLeft, 
                                         pDataRotations,
                                         pDataPreComputed,
                                         pParamDistFromHeight
                                         );

      /* update left lighting distance with the safest distance */
      if( (dmean_pair - deltad_pair) < (dmean_height - deltad_height) )
      {
#endif
        HLALightDistFilter(&(pPair->pTLeft->lightDist),
                                    dmean_pair,
                                    deltad_pair,
                                    minDist,
                                    maxDist,
                                    c0
                                    );
#if 0 
      }
      else
      {
        HLALightDistFilter(&(pPair->pTLeft->lightDist),
                                    dmean_height,
                                    deltad_height,
                                    minDist,
                                    maxDist,
                                    c0
                                    );
      }
#endif
      /* -------------------------------------------------------------------------- */
      /* update right object distance  with pair measurement */
      HLALightDistFilter(&(pPair->pTRight->objectDist),
                                  dmean_pair,
                                  deltad_pair,
                                  minDist,
                                  maxDist,
                                  c0
                                  );
#if 0
      /* get distance measurement from height hypothesis */
      HLALightDistFromVehicleHeightHypothesis(&dmean_height,
                                         &deltad_height,
                                         pPair->pTRight, 
                                         pDataRotations,
                                         pDataPreComputed,
                                         pParamDistFromHeight
                                         );

      /* update right lighting distance with the safest distance */
      if( (dmean_pair - deltad_pair) < (dmean_height - deltad_height) )
      {
#endif
        HLALightDistFilter(&(pPair->pTRight->lightDist),
                                    dmean_pair,
                                    deltad_pair,
                                    minDist,
                                    maxDist,
                                    c0
                                    );
#if 0
      }
      else
      {
        HLALightDistFilter(&(pPair->pTRight->lightDist),
                                    dmean_height,
                                    deltad_height,
                                    minDist,
                                    maxDist,
                                    c0
                                    );
      }
#endif
    }

    pPair = pPair->next;
  }

}



/* **************************************************************************** 
  Functionname:     HLATracking3DFilterDistance                            */ /*!  
  Description:      filter for distance update


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLALightDistFilter(
                                     HLATrackDist_t                   *pdistFilt,
                                     const float32                    dmean_new_meter,
                                     const float32                    deltad_new_meter,
                                     const float32                    minDist_meter,
                                     const float32                    maxDist_meter,
                                     const float32                    c0
                                     )
{
  float32 c1;
  float32 dmean;
  float32 deltad;

  /* distance filter constant */
  c1 = (1.0f - c0)*100;

  /* ------------------------------------------------------------------------------------------- */
  /* update lighting distance */
  dmean  = ((float32)pdistFilt->distMax_cm + (float32)pdistFilt->distMin_cm)*0.5f;
  deltad = ((float32)pdistFilt->distMax_cm - (float32)pdistFilt->distMin_cm)*0.5f; 

  /* low-pass filter */
  dmean  = (c0*dmean)  + (c1*dmean_new_meter);
  deltad = (c0*deltad) + (c1*deltad_new_meter);

  pdistFilt->distMin_cm = (uint16)CML_f_MinMax(minDist_meter*100.0f,maxDist_meter*100.0f,dmean - deltad);
  pdistFilt->distMax_cm = (uint16)CML_f_MinMax(minDist_meter*100.0f,maxDist_meter*100.0f,dmean + deltad);
}



/* **************************************************************************** 
  Functionname:     HLATracking3DDynamicUpdateDistance                                       
  Description:      
                    calculate dynamic distance based on a vehicle height assomption

                    xw = dw       + tkx
                    zw = vw*dw    + tkz

                    xw = (zw - tkz)/vw      + tkx

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
static void HLALightDistFromVehicleHeightHypothesis(float32                                        *pdmean,
                                               float32                                        *pdeltad,
                                               const HLATrack_t                               *pT, 
                                               const HLATracking3DDataRotations_t             *pDataRotations,
                                               const HLATracking3DDataPreComputed_t           *pDataPreComputed,
                                               const HLATracking3DParametersDistFromHeight_t  *pParamDistFromHeight
                                               )
{
  float32 xw;
  float32 varxw;

  float32 dist;
  float32 dmin,dmax;

  /* inputs */
  float32 h;
  float32 chh;

  /* jacobians */
  float32 HJ[3];
  float32 hh;

  /* get height hypothesis */
  h = pDataPreComputed->qh;
  chh = pDataPreComputed->qqhh;

  /* calculate distance with height hypothesis */
  HLALightModelDistFromHeight( 
                            &xw, 
                            HJ, 
                            0, 
                            pT->ouk, 
                            pT->ovk,
                            h,
                            pDataRotations
                            );

  /* get jacobians */
  hh = HJ[2];

  /* get covariance on distance */
  varxw = (hh*hh)*chh;

  /* test distance is in the desired range */
  HLATrackUtilsMaha11( &dist, xw - pDataPreComputed->qd, varxw + pDataPreComputed->qqdd);

  /* update output */
  if(   (dist>=0)
    &&  (dist<HLA_CHI2_VALUE_N1)
    )
  {
    *pdmean  = xw;
    *pdeltad = 3.0f*sqrtf(varxw);
  }
  else
  {
    *pdmean  = xw;
    *pdeltad = 3.0f*sqrtf(varxw);

    dmin = (*pdmean) - (*pdeltad);
    dmax = (*pdmean) + (*pdeltad);

    if(    ( dmin < pParamDistFromHeight->minDist)
      &&   ( dmax < pParamDistFromHeight->maxDist)
      &&   ( dmin > 0.0f)
      )
    {
      /* keep dmean and deltad as it is */
    }
    else
    {
      *pdmean  = pParamDistFromHeight->maxDist;
      *pdeltad = 0;
    }    
  }
}



/* **************************************************************************** 
  Functionname:     HLATracking3DModelDistFromHeight                                         */ /*!  
  Description:      

                    calculate distance with height hypothesis

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLALightModelDistFromHeight( 
                            float32 *pxw, 
                            float32 *pHJ, 
                            float32 *pHC, 
                            const float32 uk, 
                            const float32 vk,
                            const float32 zw,
                            const HLATracking3DDataRotations_t    *pDataRotations
                            )
{
  float32 iz;
  float32 a;
  float32 fa,fx,fz;

  float32 xw0,zw0;
  float32 dxw0,dzw0;

  const float32 *RK,*dRK_dcy,*dRK_dcp,*dRK_dcr;
  const float32 *TK;
  float32 rk00, rk02, rk10, rk12, rk20, rk22;

  /* get world to cam transform */
  TK = &pDataRotations->TK[0];
  RK = &pDataRotations->RK[0];
  rk00 = RK[0];       rk02 = RK[2];
  rk10 = RK[3];       rk12 = RK[5];
  rk20 = RK[6];       rk22 = RK[8];

  /* get unscaled world coordinate centered on camera (same axis as camera) */
  xw0 = (rk00*uk) + (rk10*vk) + rk20;
  zw0 = (rk02*uk) + (rk12*vk) + rk22;

  /* temporary values */
  a = (zw - TK[2]);
  /* ~CodeReview ~ID:e7f79e81085407a0e5a57e0e91286355 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:2 ~Comment:Potential division by zero! */
  /* Godreau B, code review findings priority changed from 1 to 2 : can only happen when camera pitch is exactly 0.0f and point (uk,vk) is exactly at optical center: very very low probability*/
  iz = 1/(zw0);
  fa = (xw0*iz);

  /* update state */
  *pxw = (a*fa) + TK[0];
  
  if(   (pHC != 0)
    ||  (pHJ != 0)
    )
  {
    /* temporary values */
    fx = (a*iz);
    fz = -(fx*fa);

    /* generic jacobian */
    /*
    dxw = da*(xw0*iz) + a*(dxw0*iz + xw0*((-iz*iz)*dzw0));
    dxw = fa*da + fx*dxw0 + fz*dzw0;

    with 
    fa = (xw0*iz)
    fx = (a*iz)
    fz = (a*xw0*(-iz*iz)) = -(fx*fa)
    */

    /*------------------------------------------------------------------------------------*/
    /* X world derivates */
    if(pHC != 0)
    {
      /* get roation jac pointers */
      dRK_dcy = &pDataRotations->dRK_dcy[0];
      dRK_dcp = &pDataRotations->dRK_dcp[0];
      dRK_dcr = &pDataRotations->dRK_dcr[0];

      /* along cal YAW  */
      /*
      dxw0 = (dRK_dcy[0]*uk) + (dRK_dcy[3]*vk) + dRK_dcy[6];
      dzw0 = (dRK_dcy[2]*uk) + (dRK_dcy[5]*vk) + dRK_dcy[8];

      pHC[0] = fx*dxw0 + fz*dzw0;
      */
      dxw0 = (dRK_dcy[0]*uk) + (dRK_dcy[3]*vk) + dRK_dcy[6];

      pHC[0] = fx*dxw0;

      /* along cal PITCH  */
      /*
      dxw0 = (dRK_dcp[0]*uk) + (dRK_dcp[3]*vk) + dRK_dcp[6];
      dzw0 = (dRK_dcp[2]*uk) + (dRK_dcp[5]*vk) + dRK_dcp[8];
      
      pHC[1] = fx*dxw0 + fz*dzw0;
      */
      dxw0 = (dRK_dcp[3]*vk) + dRK_dcp[6];
      dzw0 = (dRK_dcp[5]*vk) + dRK_dcp[8];
      
      pHC[1] = (fx*dxw0) + (fz*dzw0);

      /* along cal ROLL  */
      dxw0 = (dRK_dcr[0]*uk) + (dRK_dcr[3]*vk) + dRK_dcr[6];
      dzw0 = (dRK_dcr[2]*uk) + (dRK_dcr[5]*vk) + dRK_dcr[8];
      
      pHC[2] = (fx*dxw0) + (fz*dzw0);
    }

    /*------------------------------------------------------------------------------------------*/
    if(pHJ != 0)
    {
      /* calculate dX/(uk)  */
      /*
      dxw0 = rk00;
      dzw0 = rk02;

      pHJ[0] = fx*dxw0 + fz*dzw0;
      */
      pHJ[0] = (fx*rk00) + (fz*rk02);

      /* calculate dX/(vk)  */
      /*
      dxw0 = rk10;
      dzw0 = rk12;

      pHJ[1] = fx*dxw0 + fz*dzw0;
      */
      pHJ[1] = (fx*rk10) + (fz*rk12);

      /* calculate dX/(zw)  */
      pHJ[2] = fa;
    }
  }
}/* PRQA S 861 1 */
