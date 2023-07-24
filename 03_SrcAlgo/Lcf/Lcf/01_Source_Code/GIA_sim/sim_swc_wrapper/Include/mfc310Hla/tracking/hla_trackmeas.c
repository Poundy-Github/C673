/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackmeas.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackmeas.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:09CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:51CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:10CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.23 2014/03/28 10:36:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Introduced CML_u_Round2Uint
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:22 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/03/26 11:27:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:35 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackmeas.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackmeas.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.20 2014/03/19 16:30:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:55 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.19 2014/03/04 16:52:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:10 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2014/02/28 15:04:58CET Brunn, Marcus (brunnm) 
  CHANGE:                 - improved light filtering
  CHANGE:                 - preparation of light list for new rte interface i390
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:04:59 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.17 2014/02/11 17:24:53CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fixes:
  CHANGE:                  - improved selection of region for tracking
  CHANGE:                  - minor bug fixes for tracking 
  CHANGE:                 
  CHANGE:                 Update in visu:
  CHANGE:                  - new pair visualization
  CHANGE:                  - new features to disable horizon, ROI and vehicle data visu parts
  CHANGE:                  - tunnel visu moved to be part of environment
  CHANGE:                  - minor restructuring of hotkeys
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 11, 2014 5:24:53 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.16 2014/02/05 15:26:55CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed LED segmentation
  CHANGE:                 --- Added comments ---  brunnm [Feb 5, 2014 3:26:55 PM CET]
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGE:                 Revision 1.15 2014/01/24 13:37:48CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:49 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.14 2014/01/21 13:57:33CET Glebov, Roman (uidg4759) 
  CHANGE:                 removed implicite cast of uint32 to uint16
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 21, 2014 1:57:33 PM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.13 2013/11/21 17:53:16CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:17 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.12.1.5 2013/11/21 14:15:30CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:30 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.12.1.4 2013/11/21 13:37:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:26 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.12.1.3 2013/11/12 13:44:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:45 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.12.1.2 2013/10/21 10:18:30CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t
  CHANGE:                 - removed bit field for line position
  CHANGE:                 - moved  level index from line to region
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 10:18:31 AM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.12.1.1 2013/10/18 13:27:59CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:59 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.12 2012/10/18 17:56:00CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:56:00 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.11 2012/10/10 13:02:46CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:02:46 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.10 2012/10/05 12:46:48CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:46:48 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.9 2012/04/18 17:55:55CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 increase pitch range for tracking to avoid track losses on bumpers
  CHANGE:                 -> remove pitch range Vs speed concept
  CHANGE:                 -> sort SLAM features: update SLAM beginning with the closest light to the prediction, ending with the further one
  CHANGE:                 -> use a wider noise measurement for the isolated lights used in SLAM
  CHANGE:                 --- Added comments ---  uid28828 [Apr 18, 2012 5:55:56 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.8 2012/04/11 17:14:48CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 code review finding fix (no changes in perf): 
  CHANGE:                 split HLATrackMeasGetMeasurementExt() into smaller functions (access to light position)
  CHANGE:                   -> split corresponding structure into smaller structs
  CHANGE:                   -> affects tracking, pairs and icon functions
  CHANGE:                 --- Added comments ---  uid28828 [Apr 11, 2012 5:14:49 PM CEST]
  CHANGE:                 Change Package : 110195:1 http://mks-psad:7002/im/viewissue?selection=110195
  CHANGE:                 Revision 1.7 2012/03/28 12:30:32CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review (added new findings from Humic)
  CHANGE:                 --- Added comments ---  uidt9253 [Mar 28, 2012 12:30:32 PM CEST]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.6 2012/03/27 16:41:33CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 Findings for code review tracking PART 1  (Algo review partner, Stefan Zechner)
  CHANGE:                 --- Added comments ---  uid28828 [Mar 27, 2012 4:41:33 PM CEST]
  CHANGE:                 Change Package : 94916:1 http://mks-psad:7002/im/viewissue?selection=94916
  CHANGE:                 Revision 1.5 2012/03/22 19:08:03CET Godreau, Bertrand (uid28828) 
  CHANGE:                 improve data association for the "Oncoming_1stLevelSuppression" rec files
  CHANGE:                 --- Added comments ---  uid28828 [Mar 22, 2012 7:08:04 PM CET]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.4 2012/03/12 13:50:28CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Rework of dynamic object classification
  CHANGE:                 -> Separate static kalman part from SLAM and static tracker
  CHANGE:                 --- Added comments ---  uid28828 [Mar 12, 2012 1:50:28 PM CET]
  CHANGE:                 Change Package : 94859:1 http://mks-psad:7002/im/viewissue?selection=94859
  CHANGE:                 Revision 1.3 2012/03/05 10:48:53CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> clarify track removal criteria and pair removal criteria
  CHANGE:                 -> create special rule for the two tracks to two lights association case
  CHANGE:                 -> tune maxErrHorizontalInPix and maxErrVerticalInPix
  CHANGE:                 -> Use traceTimeToReinit instead_of trace_time for early track death
  CHANGE:                 -> do not kill tracks because of pair lost
  CHANGE:                 --- Added comments ---  uid28828 [Mar 5, 2012 10:48:53 AM CET]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.2 2012/02/01 09:58:39CET Brunn, Marcus (brunnm) 
  CHANGE:                 - RAM opt. -> lux values now in 16 Bit integer
  CHANGE:                 --- Added comments ---  brunnm [Feb 1, 2012 9:58:39 AM CET]
  CHANGE:                 Change Package : 94876:1 http://mks-psad:7002/im/viewissue?selection=94876
  CHANGE:                 Revision 1.1 2012/01/25 17:34:52CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */
#include "hla_trackmeas.h"
#include "hla_imager.h"

#ifdef PC_SIM
#include <string.h>
#endif


static void HLATrackMeasSelectRegion(       HLASegLineRegion_t**  ppRegion,
                                      const HLASegLight_t*        pLight
                                    );

static void HLATrackMeasSelectRegionForIsolatedLights(      HLASegLineRegion_t**  ppRegion,
                                                      const HLASegLight_t*        pLight
                                                     );

static void HLATrackMeasGetCenterAndRadiusPixel(      HLAKalmanMeasPosPix_t*                pLPix,
                                                const HLASegLineRegion_t*                   pRegion,
                                                const HLASegLight_t*                        pLight,
                                                const HLATracking3DParametersMeasurement_t* pParamMeas
                                               );

static void HLATrackMeasGetNormalizedCoordinates(       HLAKalmanMeasPos_t*             pLightNorm,
                                                  const HLAKalmanMeasPosPix_t*          pLightPix,
                                                  const HLATracking3DDataPreComputed_t* pDataPreComputed
                                                );

static void HLATrackMeasGetIntAndCol(       HLAKalmanMeasInt_t*                 pMeasInt,
                                            HLAKalmanMeasCol_t*                 pMeasCol,
                                      const HLASegLight_t*                      pLight,
                                      const uint16                              Int12bits,
                                      const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                    );

static void HLATrackMeasNGBFilter(      HLASegNgb_t*  pNgb_out,
                                  const HLASegNgb_t*  pNgb_in
                                 );

static void HLATrackMeasPseudoCensusCode(       uint32*     pCodePattern,
                                         const HLASegNgb_t* pNgb
                                        );


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasSelectRegion(void)


  @brief         

  @description   --

  @return        

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasSelectRegion(       HLASegLineRegion_t**  ppRegion,
                                      const HLASegLight_t*        pLight
                                    )
{
  HLASegLineRegion_t* pTempRegion;

  /* test if valid region is available */
  if(pLight->pRegion != NULL)
  {
    pTempRegion = pLight->pRegion;
    /* if a valid region below is available, select it */
    if(   (pTempRegion->pRegionBelow != NULL)
       && (pTempRegion->pRegionBelow->Level > 0)
      )
    {
      pTempRegion = pTempRegion->pRegionBelow;
    }
    /* return selected 'good' region */
    (*ppRegion) = pTempRegion;
  }

#if 0
  /* select the good region */
  /* isolated light */
  if(pLight->Status.isIsolatedLight == 1)
  {
    /* isolated light: if possible select region level 1, but min. one level below */
    while(   (pTempRegion)
          && (pTempRegion->Level >= 4) // A.Manz 3 instead of 1
         )
    {
      (*ppRegion) = pTempRegion;
      pTempRegion = pTempRegion->pRegionBelow;
    }
  }
  /* light not from oncoming pair and not a red in white light */
  else if(   (pLight->Status.isOPLight == 0)
          && (pLight->Status.DoNotStartNewTrack == 0)
         )
  {
    /* street lamp case? */
    if(   (pLight->Status.isInitializingTrack == 0)
       && (pLight->pRegion->pRegionBelow != 0)
       && (pLight->pRegion->pRegionBelow->Level == 0)
       && (pLight->pRegion->pRegionBelow->Status.IsRegionAboveROI == 1)
       && (   (pLight->pRegion->pRegionBelow->Status.numLightInRegion == 1)
           || (pLight->pRegion->pRegionBelow->Status.numLightAss == 1)
          )
      )
    {
      *ppRegion = pLight->pRegion->pRegionBelow;
      /* completely useless case */
      if(pLight->pRegion->pRegionBelow->Level == 4) // A.Manz 4 instead of 1
      {
        /* only use region below when width>height */
        if( ( (*ppRegion)->x2 - (*ppRegion)->x1 ) < ( (*ppRegion)->y2 - (*ppRegion)->y1 ) )
        {
          *ppRegion = pLight->pRegion;
        }
      }
    }
    else
    {
      if(   (pTempRegion->Level == 0)
         || (pTempRegion->Level == 6) /* red level */
         || (pTempRegion->Level == 7) /* LED level */
        )
      {
        /* *ppRegion is already ready to roll */
      }
      else
      {
        while(   (pTempRegion)
              && (pTempRegion->Level >= 4) // A.Manz 4 instead of 1
             )
        {
          (*ppRegion) = pTempRegion;
          pTempRegion = pTempRegion->pRegionBelow;
        }
      }
    }
  }
  /* case of oncoming pair light */
  else
  {
    /* special handling OP */
    if(   (pLight->Status.isInitializingTrack == 0)
       && (   (pLight->Status.isOPLight==1)
           && (pLight->pRegion->Status.numOPAss==1)
          )
      )
    {
      /* only one OP was associated : use then the region */
      /* (*ppRegion) = pLight->pRegion; */
      /* check if region below is even better */
      if(   (pLight->pRegion->pRegionBelow != 0)
         && (   (pLight->pRegion->pRegionBelow->Level == 6)     /* LED case */ /* A.Manz: change from 1 to 6 */
             || (   (pLight->pRegion->pRegionBelow->Level == 0) /* street lamp case */
                 && (pLight->pRegion->pRegionBelow->Status.IsRegionAboveROI == 1)
                )
            )
         && (   (pLight->pRegion->pRegionBelow->Status.numLightInRegion == 1)
             || (pLight->pRegion->pRegionBelow->Status.numLightAss == 1)
            )
        )
      {
        (*ppRegion) = pLight->pRegion->pRegionBelow;

        if(pLight->pRegion->pRegionBelow->Level == 4) // A.Manz 4 instead of 1
        {
          /* only use region below when width>height */
          if(((*ppRegion)->x2 - (*ppRegion)->x1)<((*ppRegion)->y2 - (*ppRegion)->y1))
          {
            (*ppRegion) = pLight->pRegion;
          }
        }
      }
    }
    else
    {
      (*ppRegion) = 0;
    }
  }
#endif
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasSelectRegionForIsolatedLights(void)


  @brief         

  @description   --

  @return        

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasSelectRegionForIsolatedLights(      HLASegLineRegion_t**  ppRegion,
                                                      const HLASegLight_t*        pLight
                                                     )
{
  HLASegLineRegion_t* pTempRegion;

  /* if possible ...          */
  /* select region level 1    */
  /* but min. one level below */
  if(   (pLight->pRegion->pRegionBelow != NULL)
     && (pLight->pRegion->pRegionBelow->Level > 0)
    )
  {
    pTempRegion = pLight->pRegion->pRegionBelow;
  }
  else
  {
    pTempRegion = pLight->pRegion;
  }
  (*ppRegion) = pTempRegion;

#if 0
  /* select region level 1 */
  while(   (pTempRegion)
        && (pTempRegion->Level >= 4) // A.Manz 4 instead of 1
       )
  {
    (*ppRegion) = pTempRegion;
    pTempRegion = pTempRegion->pRegionBelow;
  }
#endif
}

/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetCenterAndRadiusPixel(void)


  @brief         

  @description   --

  @return        

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasGetCenterAndRadiusPixel(      HLAKalmanMeasPosPix_t*                pLightPix,
                                                const HLASegLineRegion_t*                   pRegion,
                                                const HLASegLight_t*                        pLight,
                                                const HLATracking3DParametersMeasurement_t* pParamMeas
                                               )
{
  if(pRegion != NULL)
  {
    /* Test: use light center as centroid for tracking */
    pLightPix->x_center_pix = 0.5f * (pRegion->x2 + pRegion->x1);
    pLightPix->y_center_pix = 0.5f * (pRegion->y2 + pRegion->y1);
    /*pLightPix->x_center_pix = pLight->xcenter*/ /*Maxima.x*/ ;
    /*pLightPix->y_center_pix = pLight->ycenter*/ /*Maxima.y*/ ;

    pLightPix->x_radius_pix = CML_f_MinMax(pParamMeas->errMeasPixelMin, pParamMeas->errMeasPixelMax, (float32)(pRegion->x2 - pRegion->x1)/2.0f);
    pLightPix->y_radius_pix = CML_f_MinMax(pParamMeas->errMeasPixelMin, pParamMeas->errMeasPixelMax, (float32)(pRegion->y2 - pRegion->y1)/2.0f);
  }
  else
  {
    pLightPix->x_center_pix = pLight->xcenter /*Maxima.x*/ ;
    pLightPix->y_center_pix = pLight->ycenter /*Maxima.y*/ ;

    pLightPix->x_radius_pix = pParamMeas->errMeasPixelMin;
    pLightPix->y_radius_pix = pParamMeas->errMeasPixelMin;
  }
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetNormalizedCoordinates(void)


  @brief         

  @description   --

  @return        

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasGetNormalizedCoordinates(       HLAKalmanMeasPos_t*             pLightNorm,
                                                  const HLAKalmanMeasPosPix_t*          pLightPix,
                                                  const HLATracking3DDataPreComputed_t* pDataPreComputed
                                                )
{
  /* calculate normalized coordinates */
  pLightNorm->x = (pLightPix->x_center_pix - (pDataPreComputed->XO)) * (pDataPreComputed->invFX);
  pLightNorm->y = (pLightPix->y_center_pix - (pDataPreComputed->YO)) * (pDataPreComputed->invFY);

  /* horizontal measurement covariance */
  pLightNorm->cxx = (pLightPix->x_radius_pix) * (pLightPix->x_radius_pix) * (pDataPreComputed->factorCxx);

  /* vertical measurement covariance */
  pLightNorm->cyy = (pLightPix->y_radius_pix) * (pLightPix->y_radius_pix) * (pDataPreComputed->factorCyy);

  /* yx covariance */
  pLightNorm->cyx = 0;
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetIntensity12bits(void)


  @brief         

  @description   --

  @return        

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetIntensity12bits(      uint16*         pInt12bits,
                                    const HLASegLight_t*  pLight
                                   )
{
  float32 int12;

  /* get back 12 bit valu of the track */
  /* ~CodeReview ~ID:9841a0b176b870179e38c08af6e514e9 ~Reviewer:CW01\uid28828 ~Date:26/03/2012 ~Priority:2 ~Comment:MaxInt is not always on red pixel */
  int12 = HLAImager_GetRed_Lux((float32)pLight->MaxInt);
  (*pInt12bits) = (uint16)CML_MinMax(0, UI12_T_MAX, int12);
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetIntAndCol(void)


  @brief         

  @description   --

  @return        

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasGetIntAndCol(       HLAKalmanMeasInt_t*                 pMeasInt,
                                            HLAKalmanMeasCol_t*                 pMeasCol,
                                      const HLASegLight_t*                      pLight,
                                      const uint16                              Int12bits,
                                      const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                     )
{
  uint32  MaxIntGreyValue;
  float32 minMaxInt;
  float32 maxMaxInt;

  /*--------------------------------------------------------------------------------------------------------------------------------*/
  /* get color */
  pMeasCol->ck = pLight->current_R;
  pMeasCol->gk = pLight->current_G;

  /* color uncertainty */
  pMeasCol->scc = pDataPreComputedPair->scc;
  pMeasCol->sgg = pDataPreComputedPair->sgg;

  /*--------------------------------------------------------------------------------------------------------------------------------*/
  /* get intensity */
  pMeasInt->ik = pLight->MaxInt;

  /* lux intensity uncertainty */
  MaxIntGreyValue   = Int12bits;
  minMaxInt = HLAImager_GetLux_Red( (uint16) CML_Max(MaxIntGreyValue - pDataPreComputedPair->errMaxIntGreyValue, 0) );
  maxMaxInt = HLAImager_GetLux_Red( (uint16) CML_Min(MaxIntGreyValue + pDataPreComputedPair->errMaxIntGreyValue, UI12_T_MAX) );

  pMeasInt->sii = ((maxMaxInt - minMaxInt)*(maxMaxInt - minMaxInt))/9.0f;
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetNormAndPixCoordinates(void)


  @brief         

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetNormAndPixCoordinates(      HLAKalmanMeasPos_t*                   pLightNorm,
                                                HLAKalmanMeasPosPix_t*                pLightPix,
                                          const HLASegLight_t*                        pLight,
                                          const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                          const HLATracking3DParametersMeasurement_t* pParamMeas
                                         )
{
  /* get pixel coordinates */
  HLATrackMeasGetPixCoordinates(pLightPix,
                                pLight,
                                pParamMeas
                               );

  /* calculate normalized coordinates */
  HLATrackMeasGetNormalizedCoordinates( pLightNorm,
                                        pLightPix,
                                        pDataPreComputed
                                      );
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetNormCoordinates(void)


  @brief         

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetNormCoordinates(      HLAKalmanMeasPos_t *                  pLightNorm,
                                    const HLASegLight_t*                        pLight,
                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                   )
{
  /* pixel coordinates */
  HLAKalmanMeasPosPix_t pixCoordTemp;

  HLATrackMeasGetNormAndPixCoordinates( pLightNorm,
                                        &(pixCoordTemp),
                                        pLight,
                                        pDataPreComputed,
                                        pParamMeas
                                      );
}



/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetNormCoordinatesForIsolatedLights(void)


  @brief         

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetNormCoordinatesForIsolatedLights(       HLAKalmanMeasPos_t*                   pLightNorm,
                                                      const HLASegLight_t*                        pLightIsolated,
                                                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                                      const HLATracking3DParametersMeasurement_t* pParamMeas
                                                     )
{
  /* pixel coordinates */
  HLAKalmanMeasPosPix_t pixCoordTemp;

  /* region */
  HLASegLineRegion_t* pRegion;

  /* select the good underlying region */
  HLATrackMeasSelectRegionForIsolatedLights(&(pRegion),
                                            pLightIsolated
                                           );

  /* calculate light center and radius in pixel coordinates*/
  HLATrackMeasGetCenterAndRadiusPixel(&(pixCoordTemp),
                                      pRegion,
                                      pLightIsolated,
                                      pParamMeas
                                     );

  /* calculate normalized coordinates */
  HLATrackMeasGetNormalizedCoordinates( pLightNorm,
                                        &(pixCoordTemp),
                                        pDataPreComputed
                                      );
}

/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetPixCoordinates(void)


  @brief         

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetPixCoordinates(       HLAKalmanMeasPosPix_t*                pLightPix,
                                    const HLASegLight_t*                        pLight,
                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                  )
{
  /* region */
  HLASegLineRegion_t* pRegion;

  /* select the good underlying region */
  HLATrackMeasSelectRegion( &(pRegion),
                            pLight
                          );

  /* calculate light center and radius in pixel coordinates*/
  HLATrackMeasGetCenterAndRadiusPixel(pLightPix,
                                      pRegion,
                                      pLight,
                                      pParamMeas
                                     );
}


/* ***********************************************************************/ /*! 
  @fn            void HLATrackMeasGetKalmanMeas(void)


  @brief         

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetKalmanMeas(       HLAKalmanMeas_t*                      pMeas,
                                const HLASegLight_t*                        pLight,
                                const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                const HLATracking3DParametersMeasurement_t* pParamMeas,
                                const HLATracking3DDataPreComputedPair_t*   pDataPreComputedPair
                              )
{
  /* region */
  HLASegLineRegion_t*   pR;
  HLAKalmanMeasPosPix_t pixCoord;
  uint16                Int12bits;

  /* select the good underlying region */
  HLATrackMeasSelectRegion( &(pR),
                            pLight
                          );

  /* calculate light center and radius in pixel coordinates*/
  HLATrackMeasGetCenterAndRadiusPixel(&(pixCoord),
                                      pR,
                                      pLight,
                                      pParamMeas
                                     );

  /* calculate normalized coordinates */
  HLATrackMeasGetNormalizedCoordinates( &(pMeas->pos),
                                        &(pixCoord),
                                        pDataPreComputed
                                      );

  /* 12bits intensity */
  HLATrackMeasGetIntensity12bits( &(Int12bits),
                                  pLight
                                );

  /* color and intensity */
  HLATrackMeasGetIntAndCol( &(pMeas->intL),
                            &(pMeas->col),
                            pLight,
                            Int12bits,
                            pDataPreComputedPair
                          );
}




/* **************************************************************************** 
  Functionname:     HLATrackMeasAddMeasurement                     */ /*!  
  Description:     

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackMeasAddMeasurement(      HLATrack_t*     pTrack,
                                      HLASegLight_t*  pLight,
                                const uint16          ui_dist
                               )
{
  HLASegLineRegion_t* pRegion;

  /* new association */
  pTrack->light_ref = pLight;
  pTrack->dist2Pred = ui_dist;

  if (pTrack->track_time < UI16_T_MAX)
  {
    pTrack->track_time  = pTrack->track_time + (uint16)1;
  }

  /* set isOneToOneAssociation flag */
  if(   (pLight->Status.countInPredArea   == 1)
     && (pLight->Status.isIsolatedLight   == 1)
     && (pTrack->infoAssoc2Track[0].count == 1)
    )
  {
    pTrack->TrackingStatus.isOneToOneAssociation = 1;
  }

  /* count number of times in the region, an OP was asociated */
  if(pLight->Status.isOPLight == 1)
  {
    pLight->pRegion->Status.numOPAss++;
  }

  /* lock regions */
  pRegion = pLight->pRegion;
  while(pRegion != NULL)
  {
    pRegion->Status.IsAssToTrack = 1;

    if(pRegion->Status.numLightAss<3)
    {
      pRegion->Status.numLightAss++;
    }

    if(pTrack->TrackingStatus.isTrackedInPair == 1)
    {
      pRegion->Status.IsAssToPairedTrack = 1;
    }

    pRegion = pRegion->pRegionBelow;
  }

  /* lock light */
  pLight->Status.associated  = 1;

}


/* **************************************************************************** 
  Functionname:     HLATrackMeasRemoveMeasurement                     */ /*!  
  Description:     

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackMeasRemoveMeasurement( HLATrack_t* pTrack )
{
  HLASegLight_t*      pL;
  HLASegLineRegion_t* pRb;

  pL = pTrack->light_ref;

  pTrack->light_ref = 0;

  if (pTrack->track_time > 0)
  {
    pTrack->track_time  = pTrack->track_time - (uint16)1;
  }

  /* reset isOneToOneAssociation flag */
  pTrack->TrackingStatus.isOneToOneAssociation = 0;

#ifdef PC_SIM
  (void)memset((void*)(&(pTrack->db_assoc_final)), 0, sizeof(HLACoupleData_t));
#endif

  /* unlock light */
  pL->Status.associated  = 0;
  pL->Status.assoc_type = HLA_TRACKING3D_ASSOCTYPE_DYNAMIC;
  /*if(pL->Status.countInPredArea > 0)
  {
    pL->Status.countInPredArea = pL->Status.countInPredArea - 1;
  }*/

  /* count number of times in the region, an OP was asociated */
  if(pL->Status.isOPLight == 1)
  {
    if(pL->pRegion->Status.numOPAss>0)
    {
      pL->pRegion->Status.numOPAss--;
    }
  }

  /* unlock regions */
  pRb = pL->pRegion;
  while(pRb != NULL)
  {
    if(pRb->Status.numLightAss>0)
    {
      pRb->Status.numLightAss--;
    }
    if(pRb->Status.numLightAss==0)
    {
      pRb->Status.IsAssToTrack = 0;
    }

    pRb = pRb->pRegionBelow;
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackMeasHammingDistance                         */ /*!  
  Description:      hamming distance between 32 bit values


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackMeasHammingDistance(       uint32* pDist,
                                  const uint32  x,
                                  const uint32  y
                                )
{
  uint32 dist = 0;
  uint32 val  = x ^ y;
 
  /* Count the number of set bits */
  while(val > 0)
  {
    ++dist; 
    val &= val - 1;
  }

  *pDist = dist;
}

/* **************************************************************************** 
  Functionname:     HLATrackMeasGetLightPattern                         */ /*!  
  Description:      calculate pseudo-census image pattern from the filtered light 13 pixels


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackMeasGetLightPattern(       uint32*       pCodePattern,
                                  const HLASegNgb_t*  pNgb
                                )
{
  HLASegNgb_t ngb_filt[HLA_SEG_MAX_NUM_NGB];

  HLATrackMeasNGBFilter(ngb_filt,
                        pNgb
                       );

  HLATrackMeasPseudoCensusCode( pCodePattern,
                                ngb_filt
                              );
}


/* **************************************************************************** 
  Functionname:     HLATrackMeasNGBFilter                         */ /*!  
  Description:      filter light 13 pixels


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasNGBFilter(      HLASegNgb_t*  pNgb_out,
                                  const HLASegNgb_t*  pNgb_in
                                 )
{
  float32 Help;
  /* red */
  Help = 0.166667f*(float32)(pNgb_in[NGB_4].lux + pNgb_in[NGB_6].lux + pNgb_in[NGB_8].lux);
  pNgb_out[NGB_0].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_0].lux)  + Help);
  pNgb_out[NGB_12].lux = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_12].lux) + Help);
  
  Help = 0.166667f*(float32)(pNgb_in[NGB_0].lux + pNgb_in[NGB_6].lux + pNgb_in[NGB_12].lux);
  pNgb_out[NGB_4].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_4].lux)  + Help);
  pNgb_out[NGB_8].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_8].lux)  + Help);
  
  pNgb_out[NGB_6].lux = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_6].lux) + (0.125f*(float32)(pNgb_in[NGB_0].lux + pNgb_in[NGB_4].lux + pNgb_in[NGB_8].lux + pNgb_in[NGB_12].lux)));

  /* blue */
  pNgb_out[NGB_1].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_1].lux)  + (0.166667f*(float32)(pNgb_in[NGB_3].lux + pNgb_in[NGB_9].lux + pNgb_in[NGB_11].lux)));
  pNgb_out[NGB_3].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_3].lux)  + (0.166667f*(float32)(pNgb_in[NGB_1].lux + pNgb_in[NGB_9].lux + pNgb_in[NGB_11].lux)));
  pNgb_out[NGB_9].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_9].lux)  + (0.166667f*(float32)(pNgb_in[NGB_1].lux + pNgb_in[NGB_3].lux + pNgb_in[NGB_11].lux)));
  pNgb_out[NGB_11].lux = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_11].lux) + (0.166667f*(float32)(pNgb_in[NGB_1].lux + pNgb_in[NGB_3].lux + pNgb_in[NGB_9].lux)));


  /* green */
  Help = 0.25f*(float32)(pNgb_in[NGB_5].lux + pNgb_in[NGB_7].lux);
  pNgb_out[NGB_2].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_2].lux)  + Help);
  pNgb_out[NGB_10].lux = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_10].lux) + Help);

  Help = 0.25f*(float32)(pNgb_in[NGB_2].lux + pNgb_in[NGB_10].lux); 
  pNgb_out[NGB_5].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_5].lux)  + Help);
  pNgb_out[NGB_7].lux  = (uint16)CML_u_Round2Uint((0.5f*(float32)pNgb_in[NGB_7].lux)  + Help);
  
}



/* **************************************************************************** 
  Functionname:     HLATrackMeasPseudoCensusCode                         */ /*!  
  Description:      calculate pseudo-census image pattern from the light 13 pixels


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackMeasPseudoCensusCode(       uint32*       pCodePattern,
                                          const HLASegNgb_t*  pNgb
                                        )
{
  /*         R                   0         */
  /*      B  G  B             1  2  3      */
  /*   R  G  R  G  R       4  5  6  7  8   */
  /*      B  G  B             9 10 11      */
  /*         R                  12         */

  *pCodePattern = 0;

  if(pNgb[NGB_6].lux < pNgb[NGB_1].lux)
      *pCodePattern |= 1u;

  if(pNgb[NGB_6].lux < pNgb[NGB_2].lux)
      *pCodePattern |= (1u << 1);

  if(pNgb[NGB_6].lux < pNgb[NGB_3].lux)
      *pCodePattern |= (1u << 2);

  if(pNgb[NGB_6].lux < pNgb[NGB_7].lux)
      *pCodePattern |= (1u << 3);

  if(pNgb[NGB_6].lux < pNgb[NGB_11].lux)
      *pCodePattern |= (1u << 4);

  if(pNgb[NGB_6].lux < pNgb[NGB_10].lux)
      *pCodePattern |= (1u << 5);

  if(pNgb[NGB_6].lux < pNgb[NGB_9].lux)
      *pCodePattern |= (1u << 6);

  if(pNgb[NGB_6].lux < pNgb[NGB_5].lux)
      *pCodePattern |= (1u << 7);

  /*----------------------------*/
  if(pNgb[NGB_7].lux < pNgb[NGB_2].lux)
      *pCodePattern |= (1u << 8);

  if(pNgb[NGB_7].lux < pNgb[NGB_3].lux)
      *pCodePattern |= (1u << 9);

  if(pNgb[NGB_7].lux < pNgb[NGB_8].lux)
      *pCodePattern |= (1u << 10);

  if(pNgb[NGB_7].lux < pNgb[NGB_11].lux)
      *pCodePattern |= (1u << 11);

  if(pNgb[NGB_7].lux < pNgb[NGB_10].lux)
      *pCodePattern |= (1u << 12);


  /*----------------------------*/
  if(pNgb[NGB_10].lux < pNgb[NGB_5].lux)
      *pCodePattern |= (1u << 13);

  if(pNgb[NGB_10].lux < pNgb[NGB_11].lux)
      *pCodePattern |= (1u << 14);

  if(pNgb[NGB_10].lux < pNgb[NGB_12].lux)
      *pCodePattern |= (1u << 15);

  if(pNgb[NGB_10].lux < pNgb[NGB_9].lux)
      *pCodePattern |= (1u << 16);


  /*----------------------------*/
  if(pNgb[NGB_5].lux < pNgb[NGB_1].lux)
      *pCodePattern |= (1u << 17);

  if(pNgb[NGB_5].lux < pNgb[NGB_2].lux)
      *pCodePattern |= (1u << 18);

  if(pNgb[NGB_5].lux < pNgb[NGB_9].lux)
      *pCodePattern |= (1u << 19);

  if(pNgb[NGB_5].lux < pNgb[NGB_4].lux)
      *pCodePattern |= (1u << 20);

  /*----------------------------*/
  if(pNgb[NGB_2].lux < pNgb[NGB_0].lux)
      *pCodePattern |= (1u << 21);

  if(pNgb[NGB_2].lux < pNgb[NGB_3].lux)
      *pCodePattern |= (1u << 22);

  if(pNgb[NGB_2].lux < pNgb[NGB_1].lux)
      *pCodePattern |= (1u << 23);

  /*----------------------------*/
  if(pNgb[NGB_3].lux < pNgb[NGB_0].lux)
      *pCodePattern |= (1u << 24);

  if(pNgb[NGB_3].lux < pNgb[NGB_8].lux)
      *pCodePattern |= (1u << 25);

  /*----------------------------*/
  if(pNgb[NGB_11].lux < pNgb[NGB_8].lux)
      *pCodePattern |= (1u << 26);

  if(pNgb[NGB_11].lux < pNgb[NGB_12].lux)
      *pCodePattern |= (1u << 27);


  /*----------------------------*/
  if(pNgb[NGB_9].lux < pNgb[NGB_12].lux)
      *pCodePattern |= (1u << 28);

  if(pNgb[NGB_9].lux < pNgb[NGB_4].lux)
      *pCodePattern |= (1u << 29);

  /*----------------------------*/
  if(pNgb[NGB_1].lux < pNgb[NGB_4].lux)
      *pCodePattern |= (1u << 30);

  if(pNgb[NGB_1].lux < pNgb[NGB_0].lux)
      *pCodePattern |= (1u << 31);
}

/* **************************************************************************** 
  Functionname:     HLATrackMeasInitMatchingData                         */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackMeasInitMatchingData(      HLATrack_t*     pTrack,
                                  const HLASegLight_t*  pLight
                                 )
{
  /* intensity filter */
  pTrack->MaxIntFilt = pLight->MaxInt;
  pTrack->minInt12bits = 0;

  /* code Pattern */
  if(pTrack->TrackingStatus.isCodePatternAvailable == 0)  /* check it's not a reinit */
  {
    if(pLight->Status.isAnyNGBSaturated == 1)
    {
      /* saturation info */
      pTrack->TrackingStatus.isAnyNGBSaturatedLastLight = 1;
      pTrack->TrackingStatus.isCodePatternAvailable = 0;
    }
    else
    {
      HLATrackMeasGetLightPattern(&(pTrack->codePattern),
                                  &(pLight->Maxima.ngb[0])
                                 );

      /* saturation info */
      pTrack->TrackingStatus.isAnyNGBSaturatedLastLight = 0;
      pTrack->TrackingStatus.isCodePatternAvailable = 1;

#ifdef PC_SIM
      pTrack->db_new_pattern = 1;
#endif
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackMeasUpdateMatchingData                         */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackMeasUpdateMatchingData(      HLATrack_t*                         pTrack,
                                    const HLASegLight_t*                      pLight,
                                    const HLATracking3DParametersMatching_t*  pParamMatching
                                   )
{
  /* hamming distance */
  uint32 lightPattern;
  uint32 disthamming;

  /* kalman filter intensity*/
  /* ~CodeReview ~ID:0883404d3765f6b1f9215d368313838d ~Reviewer:CW01\uid28828 ~Date:27/03/2012 ~Priority:3 ~Comment:can be reduced to 16 bit variable. */
  pTrack->MaxIntFilt = (pParamMatching->constMaxIntFilter * pTrack->MaxIntFilt) + ((1 - pParamMatching->constMaxIntFilter) * pLight->MaxInt);

/* M.Brunn */
  /* update RGB only when one to-one association (avoid drift of the template) */
  if(   (   (pLight->Status.countInPredArea   == 1)
         && (pTrack->infoAssoc2Track[0].count == 1)
         && (pLight->Status.isAnyNGBSaturated == 0)
         && (pLight->Status.isPotLed          == 0)
        )
     || (pTrack->timeLastRGBUpdate > pParamMatching->maxTimeWithoutRGBUpdate)
    )
  {
    
    pTrack->current_R = pLight->current_R;
    pTrack->current_G = pLight->current_G;
    pTrack->current_B = pLight->current_B;
    pTrack->TrackingStatus.isRGBAvailable = 1;
  }
  else
  {
    /* update number of time RGB was not updated */
    pTrack->timeLastRGBUpdate++;
  } 
/* M.Brunn */

  /* update template only when one to-one association (avoid drift of the template) */
  /*if(pTrack->TrackingStatus.isOneToOneAssociation)*/
  if(   (pLight->Status.countInPredArea   == 1)
     && (pTrack->infoAssoc2Track[0].count == 1)
     && (pLight->Status.isAnyNGBSaturated == 0)
    )
  {
    /* light Pattern */
    HLATrackMeasGetLightPattern(&lightPattern,
                                &(pLight->Maxima.ngb[0])
                               );

    if(pTrack->TrackingStatus.isCodePatternAvailable == 1)
    {
      /* calculate hamming distance */

      /* hamming distance */
      HLATrackMeasHammingDistance(&disthamming,
                                  pTrack->codePattern,
                                  lightPattern
                                 );

#ifdef PC_SIM
      pTrack->dist_hamming = disthamming;
#endif

      /* update number of time pattern was not updated */
      pTrack->timeLastPatternUpdate++;

      if(   (disthamming <= pParamMatching->threshHammingPatternUpdate)
        || (pTrack->timeLastPatternUpdate >= pParamMatching->maxTimeWithoutPatternUpdate)
        )
      {
        /* update code Pattern */
        pTrack->codePattern = lightPattern;
#ifdef PC_SIM
        pTrack->db_new_pattern = 1;
#endif

        pTrack->timeLastPatternUpdate = 0;
      }
    }
    else
    {
      /* update code Pattern */
      pTrack->codePattern = lightPattern;
#ifdef PC_SIM
      pTrack->db_new_pattern = 1;
#endif

      pTrack->timeLastPatternUpdate = 0;
      pTrack->TrackingStatus.isCodePatternAvailable = 1;
    }
  }
}
