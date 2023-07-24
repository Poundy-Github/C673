/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segline.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segline.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:39CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:24CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:56CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.3 2014/03/28 10:04:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed scons warnings
  CHANGE:                 Removed compiler warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:04:41 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.2 2014/03/26 14:44:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:46 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1 2014/03/25 18:48:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_segline.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* GLOBAL VARIABLES
******************************************************************************/
#ifdef HLA_SEGMENTATION_ON_EVE
/* We only need RTE_HLA_SEG_MAX_NUM_LEVELS elements. HLA_DSP_CACHE_LINE_SIZE / 2 is due to cache alignment reasons */
#pragma DATA_ALIGN (EveFoundSegLines, HLA_DSP_CACHE_LINE_SIZE)
static uint16 EveFoundSegLines[HLA_DSP_CACHE_LINE_SIZE / sizeof(uint16)];
#endif

/******************************************************************************
* DEFINITIONS
******************************************************************************/
#ifndef HLA_SEGMENTATION_ON_EVE
static void HLASegLineBinarizeImage_Level( const HLA_t_CameraParameter*      pCameraParameter,
                                           const HLACameraData_t*            pCamData,
                                           const uint16                      IntThreshold_low,
                                           const uint16                      IntThreshold_high,
                                           const boolean                     checkLed,
                                                 t_PixelData*                pImg,
                                                 HLASegPreProcImage_Level_t* pLinesLevel
                                          );
#endif

/* **************************************************************************** 
  Functionname:     HLASegmentationInitPreProcImage                   */ /*!
  Description:      

  @param[in]            
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLinePreProcImage( const HLA_t_CameraParameter* pCameraParameter,
                             const HLACameraData_t*       pCamData,
                             const AS_t_ServiceFuncts*    Services,
                                   t_PixelData*           pImg,
                                   HLASegData_t*          pData,
                                   HLADebugOutputs_t*     pDebug,
                                   HLASegLineBuffer_t*    pLineBuffer
#ifdef HLA_SEGMENTATION_ON_EVE
                                 , HLAEveTimeMeas_t*      pEVETimeMeas
#endif
                           )
{
  uint32 HWTime_us;
  uint32 i;

#ifdef HLA_SEGMENTATION_ON_EVE
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(*pLineBuffer);
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(EveFoundSegLines);
  HLA_SIZE_MATCHES_DSP_CACHE_SIZE(*pEVETimeMeas);

  AS_t_EVEContainer segEveContainer;
  HLAEveSegParams_t segEveParams;
  sint32 segEveHandle;
  uint32 segEveReturnCode;
  uint8 retValEveTrigger = 0;
  uint8 retValEveWait = 0;
  uint16 sumAllSeglines = 0;
  uint16 rowOffsetPixels = (uint16)(pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes);
#else
  HLASegPreProcImage_t hlaSegPreProcData;
  uint16 IntSat = HLAImager_GetSaturation() + 1;
#endif

  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32(); 

#ifdef HLA_SEGMENTATION_ON_EVE
  /* INITIALIZATION */
  segEveHandle = 0;
  segEveReturnCode = 0;
  memset((void*)EveFoundSegLines, 0, sizeof(EveFoundSegLines));
  memset((void*)pEVETimeMeas, 0, sizeof(*pEVETimeMeas));

  /* EVE CONTAINER I/F */
  /* Fill Eve parameters */
  segEveParams.processingWidth = pCamData->RoiX2 - pCamData->RoiX1 + 1u;
  segEveParams.processingHeight = pCamData->RoiY2 - pCamData->RoiY1 + 1u;
  segEveParams.rowOffset = rowOffsetPixels;
  segEveParams.thresholdTab[0] = HLA_EVE_SEG_LED_META_THRESHOLD;
  for (i = 0; i <= HLA_SEG_LEVEL_LIGHT; i++)
  {
    segEveParams.thresholdTab[RTE_HLA_SEG_MAX_NUM_LEVELS - 1u - i] = pData->BinarizeImgData.Threshold.GV.Level[i];
  }
  segEveParams.thresholdLedUpper = HLAImager_GetT1SatHigh();
  segEveParams.thresholdLedLower = HLAImager_GetT1SatLow();
  segEveParams.xOffsetRoi = pCamData->RoiX1;
  segEveParams.yOffsetRoi = pCamData->RoiY1;
  segEveParams.maxSeglines = HLA_SEG_MAX_NUM_SEG_LINES;
  /* Fill eve container for segmentation */
  segEveContainer.u_VersionNumber = HLA_EVE_INTERFACE_VERSION_NUMBER;
  segEveContainer.eveParams.u_LocalFuncID = HLA_EVE_FUNC_ID_SEGMENTATION;
  segEveContainer.eveParams.parBuf.p_Buff = (void*) &segEveParams;
  segEveContainer.eveParams.parBuf.u_BuffLength = sizeof(segEveParams);
  /* source buffer pointer pointing to start of above ROI */
  segEveContainer.eveParams.srcBuf[0].p_Buff = (void*) (   pImg /*   pointer to start of image (cRoi) */
                                                                /* + offset in x direction between roi and cRoi */
                                                        + (pCamData->RoiX1 - pCameraParameter->s_CroppedRoiX1.ui32_x) 
                                                                /* + offset in y direction between roi and cRoi */
                                                        + (rowOffsetPixels * (pCamData->RoiY1 - pCameraParameter->s_CroppedRoiX1.ui32_y)));
  /* buffer length is part of image starting at ROI start until ROI end */
  segEveContainer.eveParams.srcBuf[0].u_BuffLength = (uint32)(segEveParams.processingHeight * pCameraParameter->s_ImageHeader.iRowBytes);
  segEveContainer.eveParams.dstBuf[0].p_Buff = (void*) pEVETimeMeas;
  segEveContainer.eveParams.dstBuf[0].u_BuffLength = sizeof(*pEVETimeMeas);
  segEveContainer.eveParams.dstBuf[1].p_Buff = (void*) pLineBuffer->Line;
  segEveContainer.eveParams.dstBuf[1].u_BuffLength = sizeof(pLineBuffer->Line);
  segEveContainer.eveParams.dstBuf[2].p_Buff = (void*) &EveFoundSegLines;
  segEveContainer.eveParams.dstBuf[2].u_BuffLength = sizeof(EveFoundSegLines);

  /* CALL EVE */
  /* write back all modified data from cache to DDR */
  Services->pfCacheWbInv((void*) pLineBuffer, sizeof(*pLineBuffer));
  Services->pfCacheWbInv((void*) EveFoundSegLines, sizeof(EveFoundSegLines));
  Services->pfCacheWbInv((void*) pEVETimeMeas, sizeof(*pEVETimeMeas));

  /* Stop time measurement before calling EVE */
  pDebug->timeMeas.dTimeSegmentationPreProcImg_us += (uint16)(Services->pfGetTimestampuS32() - HWTime_us);
  /* Call EVE to process above ROI */
  retValEveTrigger = Services->pfEVETrigger(&segEveContainer, &segEveHandle, COMP_ID_HLA);
  retValEveWait = Services->pfEVEWait(segEveHandle, (sint32*)&segEveReturnCode);
  /* Start time measurement again */
  HWTime_us = Services->pfGetTimestampuS32();
  
  /* HANDLE EVE OUTPUT */
  /* Mark cache as invalid for eve output buffers */
  Services->pfCacheInv((void*) pLineBuffer, sizeof(*pLineBuffer));
  Services->pfCacheInv((void*) EveFoundSegLines, sizeof(EveFoundSegLines));
  Services->pfCacheInv((void*) pEVETimeMeas, sizeof(*pEVETimeMeas));

  /* Check return values of service functions */
  if (   (retValEveTrigger != EVE_NO_ERROR)
      || (retValEveWait != EVE_NO_ERROR)
     )
  {
    /* Error case: Reset eve buffers to be sure that everything goes ok in further code */
    (void)memset((void*)EveFoundSegLines, 0, sizeof(EveFoundSegLines));
    (void)memset((void*)pLineBuffer, 0, sizeof(*pLineBuffer));
  }

  /* In case of an error on EVE side we provide return code to system info struct for visualization */
  if (segEveReturnCode != HLA_EVE_RETURN_OK)
  {
    pData->EveErrorCode = segEveReturnCode;
  }

  /* Copy time meas struct to debug struct (this can be done here since this is first EVE call in algo*/
  pDebug->timeMeasEve = *pEVETimeMeas;
  /* Fill segmentation part */
  pDebug->timeMeasEve.dTimeEveSeg_us = pDebug->timeMeasEve.dTimeEve_us;

  for (i = 0; i < RTE_HLA_SEG_MAX_NUM_LEVELS; i++)
  {
    /* Add index of this level for segline buffer. As seglines are stored from top to bottom the index is just the sum of all higher levels */
    pLineBuffer->Level[RTE_HLA_SEG_MAX_NUM_LEVELS - 1u - i].iLine = sumAllSeglines;
    /* Add number of found seglines of this level to internal struct */
    pLineBuffer->Level[RTE_HLA_SEG_MAX_NUM_LEVELS - 1u - i].nLines = EveFoundSegLines[i];
    /* Sum up number of all seglines */
    sumAllSeglines += EveFoundSegLines[i];
  }
  pLineBuffer->nLines = sumAllSeglines;

#else /* Reference code for simulation */

  memset(&hlaSegPreProcData, 0, sizeof(hlaSegPreProcData));

  
  /* normal lights */
  for(i=0; i<=HLA_SEG_LEVEL_LIGHT; i++)
  {
    HLASegLineBinarizeImage_Level( pCameraParameter,
                                   pCamData,
                                   pData->BinarizeImgData.Threshold.GV.Level[i],
                                   IntSat,
                                   b_FALSE,
                                   pImg,
                                   &hlaSegPreProcData.Level[i]
                                 );
  }


  /* copy seg line data */
  {
    sint32 iLevel;
    uint32 iLineOut=0;

    
    for(iLevel=(RTE_HLA_SEG_MAX_NUM_LEVELS-1); iLevel >= 0; iLevel--)
    {
      uint32 iLine;

      /* current level fits into HLA_SEG_MAX_NUM_SEG_LINES */
      if((iLineOut + hlaSegPreProcData.Level[iLevel].nLines) < HLA_SEG_MAX_NUM_SEG_LINES)
      {
        pLineBuffer->Level[iLevel].nLines = hlaSegPreProcData.Level[iLevel].nLines;
        pLineBuffer->Level[iLevel].iLine = (uint16) iLineOut;

        for(iLine=0; iLine<hlaSegPreProcData.Level[iLevel].nLines; iLine++)
        {
          if(iLineOut < HLA_SEG_MAX_NUM_SEG_LINES)
          {
            pLineBuffer->Line[iLineOut].x    = hlaSegPreProcData.Level[iLevel].Line[iLine].x;
            pLineBuffer->Line[iLineOut].y1   = hlaSegPreProcData.Level[iLevel].Line[iLine].y1;
            pLineBuffer->Line[iLineOut].y2   = hlaSegPreProcData.Level[iLevel].Line[iLine].y2;
            pLineBuffer->Line[iLineOut].yMax = hlaSegPreProcData.Level[iLevel].Line[iLine].yMax;
        
            iLineOut++; 
          }
        }
      }
      else  
      {
        /* lines buffer full */
        /* break for loop    */
        break;
      }
    }

    /* iLineOut is smaller equal to HLA_SEG_MAX_NUM_SEG_LINES, which is currently 800u */
    pLineBuffer->nLines = (uint16) iLineOut;
  }

#endif

  pLineBuffer->iLevelHigh = HLA_SEG_LEVEL_LIGHT;
  pLineBuffer->iLevelLow  = 0;

  pDebug->timeMeas.dTimeSegmentationPreProcImg_us = (uint16)(Services->pfGetTimestampuS32() - HWTime_us);
}

/* **************************************************************************** 
  Functionname:     HLASegUtilsBinarizeImage_Level                */ /*!
  Description:      

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
#ifndef HLA_SEGMENTATION_ON_EVE
static void HLASegLineBinarizeImage_Level( const HLA_t_CameraParameter*      pCameraParameter,
                                           const HLACameraData_t*            pCamData,
                                           const uint16                      IntThreshold_low,
                                           const uint16                      IntThreshold_high,
                                           const boolean                     checkLed,
                                                 t_PixelData*                pImg,
                                                 HLASegPreProcImage_Level_t* pLinesLevel
                                          )
{
  uint16 ix, ixEnd;
  uint16 iyEnd, iyStart;
  t_PixelData *pColStart;
  uint16 iLine = 0;
  /* offset in pixels to get to next row in memory */
  sint32 rowOffsetPixels;
  HLASegPreProcImage_Line_t *Line = &pLinesLevel->Line[0];

  /* run over all columns */
  ix              = pCamData->RoiX1;
  ixEnd           = pCamData->RoiX2;
  iyStart         = pCamData->RoiY1;
  iyEnd           = pCamData->RoiY2;
  rowOffsetPixels = pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes;
  pColStart       = pImg + (ix - pCameraParameter->s_CroppedRoiX1.ui32_x) + ( (uint32) rowOffsetPixels * (iyStart - pCameraParameter->s_CroppedRoiX1.ui32_y));

  while(ix < ixEnd)
  {   
    t_PixelData *ppixel;
    uint16 Level_y1;
    uint16 Level_y2;
    uint16 iy;
    boolean bPrevPixBelowThreshold = b_TRUE;

    iy = iyStart;
    
    ppixel = pColStart;
        
    Level_y1 = iy;
    Level_y2 = iy - 1;

    /* run over all pixels in one column */
    while(iy < iyEnd)
    {
      boolean lineStartEnd = b_FALSE;
      t_PixelData pixel0, pixel1, pixel2, pixel3;
      pixel0 = *ppixel;
      pixel1 = *(ppixel+1);
      ppixel += rowOffsetPixels;
      pixel2 = *ppixel;
      pixel3 = *(ppixel+1);
      ppixel += rowOffsetPixels;

      if (checkLed == b_TRUE)
      {
        /* one of the 4 pixel within level ? */
        if(   (   (pixel0 >= IntThreshold_low)
                && (pixel0 <= IntThreshold_high)
              )
           || (   (pixel1 >= IntThreshold_low)
                && (pixel1 <= IntThreshold_high)
              )
           || (   (pixel2 >= IntThreshold_low)
                && (pixel2 <= IntThreshold_high)
              )
           || (   (pixel3 >= IntThreshold_low)
                && (pixel3 <= IntThreshold_high)
              )
          )
        {
          lineStartEnd = b_TRUE;
        }
      }
      else
      {
      /* Do binning of 4 pixels */
        t_PixelData pixelMax;
        pixelMax = MAX(pixel0, MAX(pixel1, MAX(pixel2, pixel3)));

        if(   (pixelMax >= IntThreshold_low)
           && (pixelMax <= IntThreshold_high)
          )
        {
          lineStartEnd = b_TRUE;
        }

      }

      if (lineStartEnd == b_TRUE)
      {
        /* start of new line ? */
        if(bPrevPixBelowThreshold == b_TRUE)
        {
          /* save line ? */
          if(    (Level_y2 >= Level_y1)
              && (iLine < HLA_SEG_MAX_NUM_SEG_LINES)
            )
          {
            Line[iLine].y1 = (uint16)Level_y1;
            Line[iLine].y2 = (uint16)Level_y2+1;
            Line[iLine].x  = ix;
            iLine++;
          }
          Level_y1 = iy;
        }
        Level_y2 = iy;
        bPrevPixBelowThreshold = b_FALSE;
      }
      else
      {
        bPrevPixBelowThreshold = b_TRUE;
      }
      
      iy += 2;
    }

    /* finish open line segments at end of column */
    if(    (Level_y2 >= Level_y1)
        && (iLine < HLA_SEG_MAX_NUM_SEG_LINES)
      )
    {
      Line[iLine].y1 = Level_y1;
      Line[iLine].y2 = Level_y2+1;
      Line[iLine].x  = ix;
      iLine++;
    }

    pColStart += 2;
    ix += 2;
  }
  
  pLinesLevel->nLines = iLine;
}
#endif
