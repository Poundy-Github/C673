/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                CSF2xx

  CPU:                    M32192

  COMPONENT:              hla

  MODULNAME:              hla_hotpixels.c

  DESCRIPTION:            Functions for light track analysis.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          01.09.2010

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_hotpixels.c  $  
  CHANGE:                 Revision 1.1 2021/12/13 17:26:51CET Wang, David (Wangd3)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj  
  CHANGE:                 Revision 1.0 2017/03/03 10:38:28CET Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj  
  CHANGE:                 Revision 1.1 2014/04/17 16:05:24CEST Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj  
  CHANGE:                 Revision 1.7 2014/03/26 11:27:28CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed some mandatory QAC warnings  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:29 AM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.6 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Member moved from hla_hotpixels.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_hotpixels.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.  
  CHANGE:                 Revision 1.5 2014/03/19 16:30:48CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h  
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)  
  CHANGE:                 Clean-up of no longer needed files in simulation  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:48 PM CET]  
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959  
  CHANGE:                 Revision 1.4 2014/03/10 13:20:48CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Fixed some new critical QAC warnings  
  CHANGE:                 Moved suppressions from .hoc file to comment in source code  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:48 PM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.3 2014/03/04 16:52:01CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Fixed QAC warnings  
  CHANGE:                 Coding style  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:02 PM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.2 2013/11/21 17:53:47CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Merge from NEW_SEG branch  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:47 PM CET]  
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.1.1.2 2013/11/12 13:44:42CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed SegOut from function arguments  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:42 PM CET]  
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787  
  CHANGE:                 Revision 1.1.1.1 2013/10/18 13:27:54CEST Brunn, Marcus (brunnm)   
  CHANGE:                 intial version of new segmentation  
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:54 PM CEST]  
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639  
  CHANGE:                 Revision 1.1 2013/08/05 17:01:55CEST Manz, Alexander (uidv8777)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj  
  CHANGE:                 Revision 1.1.1.36 2013/03/11 18:02:04CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Replace some types by RTE ones  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 6:02:05 PM CET]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.35 2013/03/11 16:48:22CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Replaced  no longer needed macros by RTE ones  
  CHANGE:                 - HLAR_MAX_NUM_DEFECT_PIXEL  
  CHANGE:                 - HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS  
  CHANGE:                 - HLAF_NIGHTVIEW_OBJECTS  
  CHANGE:                 - HLA_FINGERPRINT_PIXELS  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:48:22 PM CET]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.34 2013/03/11 16:13:43CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Replaced no longer needed types by RTE ones  
  CHANGE:                 - HLA_t_eSignalState  
  CHANGE:                 - HLA_t_eLightStyle  
  CHANGE:                 - HLA_t_eTunnel  
  CHANGE:                 - HLA_t_eCityState  
  CHANGE:                 - HLA_t_eWeatherState  
  CHANGE:                 - HLA_t_eMotorwayState  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:43 PM CET]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.33 2013/03/11 14:33:01CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Placed no longer needed by RTE ones  
  CHANGE:                 - HLA_t_eBrightnessState  
  CHANGE:                 - HLA_t_eLightOutput  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:01 PM CET]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.32 2013/01/25 16:59:40CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Changed enums to rte like types for missing hlar input params/signals  
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 25, 2013 4:59:40 PM CET]  
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.31 2013/01/24 19:13:45CET Brunn, Marcus (brunnm)   
  CHANGE:                 Switched to rte like types for  
  CHANGE:                 - HLA_t_eSignalState  
  CHANGE:                 - HLAF_t_eNightViewObjectType  
  CHANGE:                 - HLAF_t_eNightViewSpot  
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 7:13:45 PM CET]  
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112  
  CHANGE:                 Revision 1.1.1.30 2013/01/24 16:37:08CET Brunn, Marcus (brunnm)   
  CHANGE:                 Switched to rte like types for  
  CHANGE:                 - HLA_t_eTunnel  
  CHANGE:                 - HLA_t_eBrightnessState  
  CHANGE:                 - HLA_t_eMotorwayState  
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:08 PM CET]  
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112  
  CHANGE:                 Revision 1.1.1.29 2013/01/23 16:39:53CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Converted enum to rte like type for  
  CHANGE:                 - HLA_t_eHeadLightMode  
  CHANGE:                 - HLA_t_eSpotLight  
  CHANGE:                 - HLA_t_eWindshieldType  
  CHANGE:                 - HLA_t_eDefectPixelType  
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 23, 2013 4:39:53 PM CET]  
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173  
**************************************************************************** */



/***************************************************************************/
/* local includes -------------------------------------------------------- */
/***************************************************************************/
#include <math.h>
#include "hla_hotpixels.h"
#include <string.h>


/***************************************************************************/
/* local defines ----------------------------------------------------------*/
/***************************************************************************/

/***************************************************************************/
/* extern vars ------------------------------------------------------------*/
/***************************************************************************/

/***************************************************************************/
/* global vars ------------------------------------------------------------*/
/***************************************************************************/


/***************************************************************************/
/* local function ---------------------------------------------------------*/
/***************************************************************************/
static void  HLAHotPixelsDetect(
                                HLATrack_t                    *pT,
                                const HLAHotPixelParameters_t *pParamsHotPixels
                                );

static void  HLAHotPixelsUpdate(
                                HLA_t_DefectPixelList         *pDefPixList, 
                                uint8                         ProcessHotPix, 
                                HLATrack_t                    *pTStart,
                                const HLAHotPixelParameters_t *pParamsHotPixels
                                );

static void  HLAHotPixelsVerification(
                                      HLAHotPixelsData_t            *pDataHotPixels, 
                                      uint8                         ProcessHotPix,
                                      const HLAHotPixelParameters_t *pParamsHotPixels
                                      );

/* ***********************************************************************/ /*! 
  @fn            void HLAHotPixelsInit(HLAHotPixelsData_t *pDataHotPixels)


  @brief         Init function of HLAHotPixels

  @description   

  @return        void 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLAHotPixelsInit(
                      HLAHotPixelsData_t *pDataHotPixels
                      )
{
  if(pDataHotPixels!=0)
  {
    (void)memset(pDataHotPixels, 0, sizeof(HLAHotPixelsData_t));
    pDataHotPixels->hlaDefectPixelList.e_DefectsListLengthSigStat = AL_SIG_STATE_INIT;
  }
}

/* ***********************************************************************/ /*! 

  @fn               void HLAHotPixels(void)
  @brief            HLA Hot Pixels process main function

  @description      HLA Hot Pixels process main function

  @return           void
  @pre              -
  @post             -
  @author           Bertrand Godreau

**************************************************************************** */
void HLAHotPixels( 
                  const HLA_t_MotionState         *pMotionState,
                  const RTE_HLAR_BrightnessState  eBrightnessState,
                  HLATrack_t                      *pTStart,
                  HLAHotPixelsData_t              *pDataHotPixels,
                  const HLAHotPixelParameters_t   *pParamsHotPixels
                  )
{
  uint8 ProcessHotPix;

  ProcessHotPix = 1;
  
  /* check, if hot pixel processing is useful this cycle */
  if(   (eBrightnessState != RTE_HLAR_BRT_NIGHT)
    &&  (eBrightnessState != RTE_HLAR_BRT_TWLGT_2)
    &&  (eBrightnessState != RTE_HLAR_BRT_TWLGT_3)
    )
  {
    /* day, no segmentation -> no hot pixel processing */
    ProcessHotPix = 0;
  }
  else if(   (pMotionState->f32_Speed > pParamsHotPixels->minSpeedAllCurves)
          || (    (pMotionState->f32_Speed > pParamsHotPixels->minSpeedCurvyRoad) 
               && (fabsf(pMotionState->f32_YawRate) > pParamsHotPixels->minYawRateCurvyRoad)))
  {
    ProcessHotPix = 1;
  }
  else
  {
    ProcessHotPix = 0;
  }

  /* update hot pixels list */
  HLAHotPixelsUpdate(&(pDataHotPixels->hlaDefectPixelList), ProcessHotPix, pTStart, pParamsHotPixels);
  
  /* check hot pixel status */
  HLAHotPixelsVerification(pDataHotPixels, ProcessHotPix, pParamsHotPixels);

  /* update signal status */
  pDataHotPixels->hlaDefectPixelList.e_DefectsListLengthSigStat = AL_SIG_STATE_OK;
}

/* ***********************************************************************/ /*! 

  @fn            void HLAHotPixelsUpdate(void)
  @brief         Hot Pixels update routine

  @description      
                    


  @return        void 
  @pre              -
  @post             -
  @author           Bertrand Godreau

**************************************************************************** */
static void HLAHotPixelsUpdate(
                               HLA_t_DefectPixelList         *pDefPixList, 
                               uint8                          ProcessHotPix, 
                               HLATrack_t                    *pTStart,
                               const HLAHotPixelParameters_t *pParamsHotPixels
                               )
{
  HLA_t_ICDefectPixel      *pH;
  HLATrack_t               *pT;

  /* loop over all tracks */
  pT = pTStart;
  while (pT != NULL)
  { 
    if(pT->statusAnalysisMisc.isHotTrack == 0)
    {
      /* reset hot track detection if car is standing */
      if (ProcessHotPix==0)
      {
        pT->countHotTrack = 0;
        pT->LightHash = 0;
      }

      /* call hot track detection */
      HLAHotPixelsDetect(pT, pParamsHotPixels);
    
      /* add new hot pixel to the list */
      if(pT->countHotTrack >= pParamsHotPixels->HotPixelMinConsequentAssoc)
      {
        /* flag hot track */
        pT->statusAnalysisMisc.isHotTrack = 1;
      }
    }

    /* add new hot pixel to the list */
    /* ~CodeReview ~ID:6b898024f6e34e54bbd35eb750c5a058 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:2 ~Comment:uint8 variable compared to uint16 define */
    if(   (pT->statusAnalysisMisc.isHotTrack == 1)
      &&  (pDefPixList->ui8_DefectsListLength < RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH)
      )
    {
      /* remove hot track from track list next cycle and replace it by a defect pixel in defect pixel list */
      pT->TrackingStatus.willBeRemoved = 1;

      /* add new hot pixel in the queue */
      pH = &(pDefPixList->as_DefectList[pDefPixList->ui8_DefectsListLength]);
      
      /* ic defect list is in absolute imager coordinates !!! */
      pH->ui16_xPos        = pT->light_ref->Maxima.x;
      pH->ui16_yPos        = pT->light_ref->Maxima.y;
      pH->e_DefectType     = RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX;
      pH->ui16_Count       = 1;

      /* increase number of hot pixel */
      pDefPixList->ui8_DefectsListLength++;
    }

    pT = pT->next;
  }
}


/* ***********************************************************************/ /*! 
  @fn            void HLAHotPixelsDetect(HLATrack_t* pTrack, const HLAHotPixelParameters_t *pParamsHotPixels)


  @brief         Detect hot tracks

  @description   --

  @param[in,out] pTrack

  @return        uint8 

  @pre           -

  @post          -

  @author        Florian Foelster, Bertrand Godreau
**************************************************************************** */
static void HLAHotPixelsDetect(
                               HLATrack_t                    *pT,
                               const HLAHotPixelParameters_t *pParamsHotPixels
                               )
{
  uint8 LocalLightHash;

  /* hot track need to have a very long life time */
  if(pT->trace_time > pParamsHotPixels->HotPixelMinTrackAge)
  {
    pT->countHotTrack = CML_Max(pT->countHotTrack, 1u);

    if(pT->light_ref != NULL)
    {
      /* build Hash value based on 4bit modulo */
      LocalLightHash = (uint8) ( (pT->light_ref->Maxima.x % 16u) );
      LocalLightHash += 16;
      LocalLightHash  = (uint8) ( LocalLightHash + (pT->light_ref->Maxima.y % 16u) );

      /* if function is entered for the first time, set LightHash*/
      if (pT->countHotTrack == 1)
      {
        pT->LightHash = LocalLightHash;
        pT->countHotTrack = 2u;
      }
      else
      {
        if (pT->LightHash == LocalLightHash) 
        {
          /* if light hash keeps constant, increase counter */
          if (pT->countHotTrack < 255u)
          {
            pT->countHotTrack++;
          }
        }
        else
        {
          /* if light hash changes, pixel is not hot */
          pT->countHotTrack = 0u;
          pT->LightHash = 0u;
        }
      }
    }
    else
    {
        /* if no light was assigned, pixel is not hot */
        pT->countHotTrack = 0u;
        pT->LightHash = 0u;
    }
  }
}

/* ***********************************************************************/ /*! 
  @fn            void HLAHotPixelsVerification(HLAHotPixelsData_t *pDataHotPixels, uint8 ProcessHotPix, const HLAHotPixelParameters_t *pParamsHotPixels)


  @brief         Check if hot pixel are still hot

  @description   A counter is used to check whether hot pixels are still segmentated

  @return        void 

  @pre           -

  @post          -

  @todo

  @author        Florian Foelster, Bertrand Godreau
**************************************************************************** */
static void HLAHotPixelsVerification(
                                     HLAHotPixelsData_t            *pDataHotPixels, 
                                     uint8                         ProcessHotPix,
                                     const HLAHotPixelParameters_t *pParamsHotPixels
                                     )
{
  HLA_t_ICDefectPixel   *pH;
  HLA_t_ICDefectPixel   *pHj;
  HLA_t_DefectPixelList *pDefPixList;
  sint16 i;
  sint16 j;
  uint16 HotPixelUpdateLimit;

  /* get defect pixels list */
  pDefPixList = &(pDataHotPixels->hlaDefectPixelList);

  /* update hot pixel parameter */
  HotPixelUpdateLimit = (uint16) (pParamsHotPixels->HotPixelValidaionCycle * pParamsHotPixels->HotPixelValidaionRate);

  if(ProcessHotPix > 0)
  {
    /* validate hot pixel status every n cycles */
    if(pDataHotPixels->HotPixelTimeCounter == 0)
    {
      /* go through list (only dynamic hot pixels) */
      pH = &pDefPixList->as_DefectList[0];
      i = 0;
      while(i < pDefPixList->ui8_DefectsListLength)
      {
        if (   (pH->ui16_Count > 1)                       /* init new hot tracks for statistic calculation */
            && (pH->ui16_Count < HotPixelUpdateLimit) 
            && (pH->e_DefectType == RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX)   /* do not remove bad pixel from production/ micron : delete only the dynamic hot pixels*/
            )
        {
          /* decrease number of hot pixel */
          pDefPixList->ui8_DefectsListLength--;

          /* copy remaining items of the list to remove empty space */
          j = i;
          pHj = pH;
          while(j<pDefPixList->ui8_DefectsListLength)
          {
            *(pHj) = *(pHj+1);
            pHj++;
            j++;
          }

          /* reset last item */
          pHj->ui16_xPos        = 0;
          pHj->ui16_yPos        = 0;
          pHj->e_DefectType     = RTE_HLAR_DEFECT_PIXEL_PIX_OK; 
          pHj->ui16_Count       = 0;
        } 
        else
        {
          /* reset counter */
          pH->ui16_Count = 2;
        }

        /* go to next hot pixel */
        pH++;
        i++;
      }
    }
  }
  else
  {
    /* go through list (only dynamic hot pixels) */
    pH = &pDefPixList->as_DefectList[0];
    i = 0;
    while(i < pDefPixList->ui8_DefectsListLength)
    {
      if(   (pH->e_DefectType == RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX)
        &&  (pH->ui16_Count < UI16_T_MAX)
        &&  (pH->ui16_Count >= 2)
        )
      {
        pH->ui16_Count++;
      }

      /* go to next hot pixel */
      pH++;
      i++;
    }
  }

  /* increase hot pixel validation cycle counter */
  pDataHotPixels->HotPixelTimeCounter++;
  pDataHotPixels->HotPixelTimeCounter %= pParamsHotPixels->HotPixelValidaionCycle;
}/* PRQA S 861 1 */
 /* J.Häfer: Redundant including of math.h is checked */