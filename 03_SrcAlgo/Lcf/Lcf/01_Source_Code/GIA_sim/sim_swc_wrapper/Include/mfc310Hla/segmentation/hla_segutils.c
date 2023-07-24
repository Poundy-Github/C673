/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segutils.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segutils.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:41CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:29CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:59CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:14CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_segutils.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* MACROS / DEFINES
******************************************************************************/


/******************************************************************************
* GLOBALS
******************************************************************************/


/* ****************************************************************************
  Functionname:     HLASegUtilsFindMaxima
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegUtilsFindMaxima( const HLA_t_CameraParameter* pCameraParameter,
                            const HLASegLineBuffer_t*    pLineBuffer,
                                  t_PixelData*           pImg,
                            const HLASegLightDataRoi_t*  pLightData,
                                  HLASegLightBuffer_t*   pLightBuffer
                          )
{
  uint16 iLight                = pLightData->iLight;
  /* offset in pixels to get to next row in memory */
  const sint32 rowOffsetPixels = pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes;
  uint16 loopCounter1          = 0;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    HLASegLight_t* restrict pLight     = &(pLightBuffer->Light[iLight]);
    uint16                  iLine      = pLight->pRegion->iLine;
    const HLASegLine_t*     Line       = &pLineBuffer->Line[0];
    t_PixelData*            ppixel_Max = NULL;

    /* TODO: Breaking is not enough. We should do a proper error handling */
    /* in order to prevent hanger, more than HLA_SEG_MAX_NUM_LIGHTS cannot be linked */
    if (loopCounter1 > HLA_SEG_MAX_NUM_LIGHTS)
    {
      break;
    }

#ifdef HLA_SEGMENTATION_ON_EVE
    uint32 offset;
    t_PixelData* ppixel0;
    t_PixelData* ppixel1;
    t_PixelData* ppixel2;
    t_PixelData* ppixel3;
    t_PixelData nullPix = 0;
    /* Set pointer to global maximum pixel initially */
    ppixel_Max = &nullPix;

    /* go through all lines and search maxima */
    #pragma MUST_ITERATE( , HLA_SEG_MAX_NUM_SEG_LINES, )
    while(iLine < HLA_SEG_MAX_NUM_SEG_LINES)
    {
      offset  = (uint32)((sint64)(Line[iLine].yMax - pCameraParameter->s_CroppedRoiX1.ui32_y) * rowOffsetPixels);
      offset += Line[iLine].x - pCameraParameter->s_CroppedRoiX1.ui32_x;
      ppixel0 = pImg + offset;
      ppixel1 = ppixel0 + 1u;
      ppixel2 = ppixel0 + rowOffsetPixels;
      ppixel3 = ppixel2 + 1u;

      /* Search for pointer to local maximum pixel of that segline and compare whether this pixel is greater than global max of that light */
      if(*ppixel0 > *ppixel_Max)
      {
        ppixel_Max = ppixel0;
      }
      if(*ppixel1 > *ppixel_Max)
      {
        ppixel_Max = ppixel1;
      }
      if(*ppixel2 > *ppixel_Max)
      {
        ppixel_Max = ppixel2;
      }
      if(*ppixel3 > *ppixel_Max)
      {
        ppixel_Max = ppixel3;
      }

      iLine = Line[iLine].iLineNext;
    }
#else          
    /* go through all lines and search maxima */
    while(iLine < HLA_SEG_MAX_NUM_SEG_LINES)
    {
      uint32 offset;
      t_PixelData *ppixel;

      sint32 yEnd;  /* signed integer to handle y2 < y1 properly; this shouldn't happen but you never know */
      sint16 iy = 0;

      offset  = (Line[iLine].y1 - pCameraParameter->s_CroppedRoiX1.ui32_y) * (uint32) rowOffsetPixels;
      offset += Line[iLine].x - pCameraParameter->s_CroppedRoiX1.ui32_x;
      ppixel  = pImg + offset;
      yEnd = Line[iLine].y2 - Line[iLine].y1;

      if(ppixel_Max == NULL)
      {
        ppixel_Max = ppixel;
      }

      while(iy <= yEnd)
      {
        if(*ppixel > *ppixel_Max)
        {
          ppixel_Max = ppixel;
        }
        if(*(ppixel+1) > *ppixel_Max)
        {
          ppixel_Max = ppixel+1;
        }
        ppixel += rowOffsetPixels;
        iy++;
      }
      iLine = Line[iLine].iLineNext;
    }
#endif

    /* save Maxima */
    HLASegUtilsSaveMaxima( pCameraParameter,
                           pImg,
                           ppixel_Max,
                           pLight
                         );
       
    iLight = pLight->iLightNext;
    loopCounter1++;
  }
}

/* ****************************************************************************
  Functionname:     HLASegFindMaxima_Lux (static)
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegUtilsFindMaxima_Lux( HLASegLightDataRoi_t* pLightData,
                                HLASegLightBuffer_t*  pLightBuffer
                              )
{
  uint16 iLight = pLightData->iLight;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    HLASegLight_t *pLight = &(pLightBuffer->Light[iLight]);
    HLASegMaxima_t* restrict pMax = &pLight->Maxima;
    uint8  i_ngb_max = pMax->i_ngb;
    uint16 lux_max = pMax->ngb[i_ngb_max].lux;
    uint16 local_lux_max;
    sint8 ix, iy;
    sint8 dx_max, dy_max;
    uint8 i_ngb;

    /* check only the direct surrounding pixels */
    i_ngb = (i_ngb_max-1)-HLA_SEG_MAX_NUM_NGB_XY;
    dx_max = 0;
    dy_max = 0;
    for(iy = -1; iy < 2; iy++)
    {
#ifdef _TMS320C6X
      #pragma UNROLL(3)
#endif
      for(ix = -1; ix < 2; ix++)
      { 
        local_lux_max = pMax->ngb[i_ngb].lux;
        if(local_lux_max > lux_max)
        {
          lux_max = local_lux_max;
          i_ngb_max = i_ngb;
          dx_max = ix;
          dy_max = iy;
        }
        i_ngb++;
      }
      i_ngb = (i_ngb + HLA_SEG_MAX_NUM_NGB_XY) - 3;
    }
        
    /* correct the maxima position */
    if(i_ngb_max != pMax->i_ngb)
    {
      pMax->x = pMax->x + dx_max;
      pMax->y = pMax->y + dy_max;
      pMax->i_ngb = i_ngb_max;
    } 
   
    iLight = pLight->iLightNext;
  }
}

/* **************************************************************************** 
  Functionname:     HLASegUtilsSaveMaxima                  */ /*!
  Description:      

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegUtilsSaveMaxima( const HLA_t_CameraParameter* pCameraParameter,
                                  t_PixelData*           pImg,
                                  t_PixelData*           ppixel_Max,
                                  HLASegLight_t*         pLight
                          )
{
  if(ppixel_Max != NULL)
  {
    uint32 dpix;
    uint32 dyCroi, dxCroi;
    /* offset in pixels to get to next row in memory, should be always positive */
    uint32 rowOffsetPixels = (uint32) (pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes);

    /* save neighborhood of current local maximum */
    /* offset of maximum pixel to start of image (cRoi) in pixels*/
    dpix = (uint32) (ppixel_Max - pImg);
    /* offset in y-direction */
    dyCroi = (dpix / rowOffsetPixels);
    /* offset in x-direction */
    dxCroi = (dpix % rowOffsetPixels);
    /* Add cRoi values as we use total imager coordinates */
    pLight->Maxima.x = (uint16)(dxCroi + pCameraParameter->s_CroppedRoiX1.ui32_x);      
    pLight->Maxima.y = (uint16)(dyCroi + pCameraParameter->s_CroppedRoiX1.ui32_y);

    /* copy all pixel */
    {
      t_PixelData *ppixel = NULL;
      uint32 iy, ix;

      if(   ((pLight->Maxima.x & 0x1) == 1)
         && ((pLight->Maxima.y & 0x1) == 0)
        )
      {
        /* maxima on red pixel */
        ppixel = (ppixel_Max - HLA_SEG_NGB_OFFSET_R_X) - (HLA_SEG_NGB_OFFSET_R_Y * rowOffsetPixels);
        pLight->Maxima.i_ngb = HLA_SEG_NGB_OFFSET_R_X + (HLA_SEG_NGB_OFFSET_R_Y * HLA_SEG_MAX_NUM_NGB_XY);
      }
      else if(   ((pLight->Maxima.x & 0x1) == 0)
              && ((pLight->Maxima.y & 0x1) == 1)
             )
      {
        /* maxima on blue pixel */
        ppixel = (ppixel_Max - HLA_SEG_NGB_OFFSET_B_X) - (HLA_SEG_NGB_OFFSET_B_Y * rowOffsetPixels);
        pLight->Maxima.i_ngb = HLA_SEG_NGB_OFFSET_B_X + (HLA_SEG_NGB_OFFSET_B_Y * HLA_SEG_MAX_NUM_NGB_XY);
      }
      else if(   ((pLight->Maxima.x & 0x1) == 0)
              && ((pLight->Maxima.y & 0x1) == 0)
        )
      {
        /* maxima on green pixel on the red row */
        ppixel = (ppixel_Max - HLA_SEG_NGB_OFFSET_GR_X) - (HLA_SEG_NGB_OFFSET_GR_Y * rowOffsetPixels);
        pLight->Maxima.i_ngb = HLA_SEG_NGB_OFFSET_GR_X + (HLA_SEG_NGB_OFFSET_GR_Y * HLA_SEG_MAX_NUM_NGB_XY);
      }
      else if(   ((pLight->Maxima.x & 0x1) == 1)
              && ((pLight->Maxima.y & 0x1) == 1)
             )
      {
        /* maxima on green pixel on the blue row */
        ppixel = (ppixel_Max - HLA_SEG_NGB_OFFSET_GB_X) - (HLA_SEG_NGB_OFFSET_GB_Y * rowOffsetPixels);
        pLight->Maxima.i_ngb = HLA_SEG_NGB_OFFSET_GB_X + (HLA_SEG_NGB_OFFSET_GB_Y * HLA_SEG_MAX_NUM_NGB_XY);
      }

      ix = 0;
      for(iy=0; iy < HLA_SEG_MAX_NUM_NGB_XY; iy++)
      {
        memcpy(&pLight->Maxima.ngb[ix].raw, ppixel, sizeof(t_PixelData)*HLA_SEG_MAX_NUM_NGB_XY);
        ppixel += rowOffsetPixels;
        ix += HLA_SEG_MAX_NUM_NGB_XY;
      }
    }
  }
} 

/* **************************************************************************** 
  Functionname:     HLASegUtilsBinarizeImage_SetThreshold     (static)            */ /*!
  Description:      

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegUtilsBinarizeImage_SetThreshold(const HLA_t_SegmentationParametersBrightness* pParBrightness, 
                                                 HLASegData_t*                           pData
                                          )
{
  uint32 i;
  float32 StepSize_lux = 200.0f;
  float32 Hysteresis_lux = 0.2f* StepSize_lux;
  float32 MaxThresLastFrame_lux = pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT];

  /* normal lights */  
  for(i=0; i<=HLA_SEG_LEVEL_LIGHT; i++)
  {
    pData->BinarizeImgData.Threshold.Lux.Level[i] = pParBrightness->Light.Level[i].IntThreshold;
    pData->BinarizeImgData.Threshold.GV.Level[i]  = (uint16)HLAImager_GetRed_Lux(pParBrightness->Light.Level[i].IntThreshold);
  }
  pData->BinarizeImgData.Threshold.Lux.Level[pParBrightness->Light.iT1SatLevel] = HLAImager_GetIntT1SatLow_RedLux();
  pData->BinarizeImgData.Threshold.GV.Level[pParBrightness->Light.iT1SatLevel]  = HLAImager_GetT1SatLow();   

  /* set HLA_SEG_LEVEL_LIGHT threshold if necessary */
  {
    float32 Thres = 0.8f*pData->MaxInt.maxInt;

    if(CML_f_Abs(MaxThresLastFrame_lux-Thres) > Hysteresis_lux)
    {
      i = (uint32)CML_f_MinMax(0.0f, 10.0f, ((Thres - pParBrightness->Light.Level[HLA_SEG_LEVEL_LIGHT].IntThreshold)/StepSize_lux));
      
      pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT] = pParBrightness->Light.Level[HLA_SEG_LEVEL_LIGHT].IntThreshold + (i * StepSize_lux);
      pData->BinarizeImgData.Threshold.GV.Level[HLA_SEG_LEVEL_LIGHT]  = (uint16)HLAImager_GetRed_Lux(pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT]);
    }
    else if(MaxThresLastFrame_lux > 0.0f)
    {
      pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT] = MaxThresLastFrame_lux;
      pData->BinarizeImgData.Threshold.GV.Level[HLA_SEG_LEVEL_LIGHT]  = (uint16)HLAImager_GetRed_Lux(pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT]);
    }
  }

  /* set (HLA_SEG_LEVEL_LIGHT-1) threshold */
  {
    pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT-1] = 0.3333f*(pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT]);
    pData->BinarizeImgData.Threshold.GV.Level[HLA_SEG_LEVEL_LIGHT-1]  = (uint16)HLAImager_GetRed_Lux(pData->BinarizeImgData.Threshold.Lux.Level[HLA_SEG_LEVEL_LIGHT-1]);
  }
}

/* **************************************************************************** 
  Functionname:     HLASegCopyFingerPrint (static)
  Description:      copy finger print pixel in internal variable

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegUtilsCopyFingerPrint( const HLAR_t_RequiredInputs* ps_In,
                                 const t_PixelData*           pImg, 
                                       HLA_t_Fingerprint*     pFingerprint
                               )
{
  /* copy fingerprint */
  pFingerprint->FrameNumber = ps_In->uiFrameCnt;
  pFingerprint->x           = HLA_FINGERPRINT_X;
  pFingerprint->y           = HLA_FINGERPRINT_Y;
    
  (void)memcpy(&pFingerprint->pix[0], (pImg + HLA_FINGERPRINT_X + (HLA_FINGERPRINT_Y * (ps_In->s_Par.s_CameraParameter.s_ImageHeader.iRowBytes / ps_In->s_Par.s_CameraParameter.s_ImageHeader.iPixelBytes))), (HLA_FINGERPRINT_PIXELS * sizeof(t_PixelData)));
}
