/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segsubimage.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segsubimage.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:40CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:28CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:59CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_segsubimage.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* PROTOTYPES
******************************************************************************/
static void HLASegSubImageSetAccInt( const sint32                CurRow, 
                                           t_PixelData*          pCurRow, 
                                     const HLASegIn_t*           pIn, 
                                           HLASegSubImageData_t* pData
                                    );

static void HLASegSubImageQuickSort( const sint32   elements, 
                                           float32* arr                                    
                                    );

static void HLASegSubImageCalcStatistc( const float32                    Int[],
                                        const sint32                     IntLength,
                                        const HLADataState_t*            pState,
                                        const uint32                     iArrayCurCycle,
                                              HLASegSubImageStatistic_t* pStat 
                                      );

static void HLASegSubImageCalcHistMedian( const float32         Hist[],
                                          const uint32          iArrayCurCycle,
                                          const HLADataState_t* pState,
                                                float32*        pMedian
                                        );

/******************************************************************************
* FUNCTION DEFINITIONS
******************************************************************************/

/* **************************************************************************** 
  Functionname:     HLASegSubImageCalcIntensities  (static)                 */ /*!
  Description:      Calculate the intensities for the subsampled image

  @param[in]           
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegSubImageCalcIntensities( const HLA_t_CameraParameter*         pCameraParameter,
                                          t_PixelData*                   pImg,
                                    const HLACameraData_t*               pCamData,
                                    const HLASegIn_t*                    pSegIn,
                                          HLASegSubImageData_t*          pData,
                                          HLASegOut_t*          restrict pOut
                                   )
{
  uint16 ix, iy;
  sint32 iCurRow;
  t_PixelData *pCurRow;
  /* offset in pixels to get to next row in memory */
  sint32 rowOffsetPixels = pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes;

  /* set subsampled image */
  /* start on red row */
  pCurRow = pImg + (pCamData->RoiX1 - pCameraParameter->s_CroppedRoiX1.ui32_x) + ((sint32)(pCamData->RoiY1 - pCameraParameter->s_CroppedRoiX1.ui32_y) * rowOffsetPixels);
  for(iCurRow = pCamData->RoiY1; iCurRow < pCamData->RoiY2; (iCurRow = iCurRow +2), (pCurRow = pCurRow + (2 * rowOffsetPixels)))
  {
    HLASegSubImageSetAccInt( iCurRow,
                             pCurRow, 
                             pSegIn, 
                             pData
                           );
  }

  /* set current cycle array index */
  if(pOut->SubImage.iArrayCurCycle < (HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES-1))
  {
    pOut->SubImage.iArrayCurCycle++;
  }
  else
  {
    pOut->SubImage.iArrayCurCycle = 0;
  }   

  for(iy=0u; iy<HLA_SEG_INTENSITY_SUB_IMG_HEIGHT; iy++)
  { 
    if(pData->accCnt[iy])
    {
      for(ix=0u; ix<HLA_SEG_INTENSITY_SUB_IMG_WIDTH; ix++)
      {
        pOut->SubImage.SubImage_lux[iy][ix] = HLAImager_GetLux_Red( (uint16) ( pData->accInt[iy][ix] / pData->accCnt[iy] ) );
      }

      /* set state                    */
      /* same state as cycle before ? */
      if(pOut->SubImage.SubImage_State[iy].State == (uint32)HLA_DATA_STATE_VALID)
      {
        /* same state as one cycle before */
        /* -> increment state counter     */
        if(pOut->SubImage.SubImage_State[iy].Cnt < HLA_DATA_STATE_MAX_CNT)
        {
          pOut->SubImage.SubImage_State[iy].Cnt++; 
        }
      }
      else
      {
        /* state changed          */
        /* -> reset state counter */
        pOut->SubImage.SubImage_State[iy].Cnt = 0u;
      }
      pOut->SubImage.SubImage_State[iy].State = (uint32)HLA_DATA_STATE_VALID;
    }
    else
    {
      /* invalid data (sampling stops before end of hla roi = sampling aborted) */
      (void)memset((void*)(&pOut->SubImage.SubImage_lux[iy][0]), 0, (sizeof(pOut->SubImage.SubImage_lux[0][0])*HLA_SEG_INTENSITY_SUB_IMG_WIDTH));
      
      /* set state                    */
      /* same state as cycle before ? */
      if(pOut->SubImage.SubImage_State[iy].State == (uint32)HLA_DATA_STATE_INVALID)
      {
        /* same state as one cycle before */
        /* -> increment state counter     */
        if(pOut->SubImage.SubImage_State[iy].Cnt < HLA_DATA_STATE_MAX_CNT)
        {
          pOut->SubImage.SubImage_State[iy].Cnt++; 
        }
      }
      else
      {
        /* state changed          */
        /* -> reset state counter */
        pOut->SubImage.SubImage_State[iy].Cnt = 0u;
      }
      pOut->SubImage.SubImage_State[iy].State = (uint32)HLA_DATA_STATE_INVALID;
    }
  }
  
  /* sort SubImage_lux */
  (void)memcpy((void*)&pOut->SubImage.SubImageSort_lux[0], (void*)&pOut->SubImage.SubImage_lux[0][0], (HLA_SEG_INTENSITY_SUB_IMG_SIZE) * sizeof(float32));
  HLASegSubImageQuickSort(HLA_SEG_INTENSITY_SUB_IMG_SIZE, &pOut->SubImage.SubImageSort_lux[0]);

  /* calc all statistic values for all rois */
  /* complete ROI */
  HLASegSubImageCalcStatistc( /* input */
                              &pOut->SubImage.SubImage_lux[0][0],
                              (HLA_SEG_INTENSITY_SUB_IMG_SIZE),
                              &pOut->SubImage.SubImage_State[HLA_SEG_INTENSITY_SUB_IMG_HEIGHT-1],
                              pOut->SubImage.iArrayCurCycle,
                              /* output */ 
                              &pOut->SubImage.RoiInt
                            );

  /* above ROI */
  HLASegSubImageCalcStatistc( /* input */
                              &pOut->SubImage.SubImage_lux[0][0],
                              HLA_SEG_INTENSITY_SUB_IMG_WIDTH,
                              &pOut->SubImage.SubImage_State[0],
                              pOut->SubImage.iArrayCurCycle,
                              /* output */ 
                              &pOut->SubImage.AboveRoiInt
                            );
  
  /* hla function ROI */
  HLASegSubImageCalcStatistc( /* input */
                              &pOut->SubImage.SubImage_lux[1][0],
                              ((HLA_SEG_INTENSITY_SUB_IMG_HEIGHT-1) * HLA_SEG_INTENSITY_SUB_IMG_WIDTH),
                              &pOut->SubImage.SubImage_State[HLA_SEG_INTENSITY_SUB_IMG_HEIGHT-1],
                              pOut->SubImage.iArrayCurCycle,
                              /* output */ 
                              &pOut->SubImage.FunctRoiInt
                            );
  
  /* below horizon ROI (incl. horizon) */
  HLASegSubImageCalcStatistc( /* input */
                              &pOut->SubImage.SubImage_lux[2][0],
                              ((HLA_SEG_INTENSITY_SUB_IMG_HEIGHT-2) * HLA_SEG_INTENSITY_SUB_IMG_WIDTH),
                              &pOut->SubImage.SubImage_State[HLA_SEG_INTENSITY_SUB_IMG_HEIGHT-1],
                              pOut->SubImage.iArrayCurCycle,
                              /* output */ 
                              &pOut->SubImage.BelowHorRoiInt
                            );

}

/* **************************************************************************** 
  Functionname:     HLASegUtilsQuickSort                               */ /*!
  Description:      quick sort 

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegSubImageQuickSort( const sint32   elements, 
                                           float32* arr                                    
                                   )
{
  float32 piv;
  sint32  swap, L, R, i=0, beg[HLA_SEG_INTENSITY_SUB_IMG_SIZE], end[HLA_SEG_INTENSITY_SUB_IMG_SIZE];

  beg[0]= 0;
  end[0]= elements;

  while(i>=0)
  {
    L=beg[i];
    R=end[i]-1;
    
    if(L<R)
    {
      piv=arr[L];
      while(L<R)
      {
        while ((arr[R]>=piv) && (L<R)) R--;
        if(L<R)
        {
          arr[L]=arr[R];
          L++;
        }
        while((arr[L]<=piv) && (L<R)) L++;
        if(L<R)
        {
          arr[R]=arr[L];
          R--;
        }  
      }
      arr[L]=piv;
      beg[i+1]=L+1;
      end[i+1]=end[i];
      end[i]=L;
      i++;
      if((end[i]-beg[i])>(end[i-1]-beg[i-1]))
      {
        swap=beg[i]; beg[i]=beg[i-1]; beg[i-1]=swap;
        swap=end[i]; end[i]=end[i-1]; end[i-1]=swap;
      }
    }
    else
    {
      i--;
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLASegSubImageCalcHistMedian                         */ /*!  
  Description:      Calculate the median of history array

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegSubImageCalcHistMedian( const float32         Hist[],
                                          const uint32          iArrayCurCycle,
                                          const HLADataState_t* pState,
                                                float32*        pMedian
                                        )
{
  float32 Array[HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES];
  

  if(pState->Cnt >= (uint8)HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES)
  {
    (void)memcpy((void*)&Array[0], (void*)&Hist[0], (sizeof(float32)*HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES));
    HLASegSubImageQuickSort(HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES, &Array[0]);

    *pMedian = Array[HLA_SEG_INTENSITY_SUB_IMG_HISTORY_CYCLES>>1];
  }
  else
  {
    *pMedian = Hist[iArrayCurCycle];
  }
}


/* **************************************************************************** 
  Functionname:     HLASegSubImageCalcStatistc                                */ /*!  
  Description:      Calculate the statistics of an area

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegSubImageCalcStatistc( const float32                    Int[],
                                        const sint32                     IntLength,
                                        const HLADataState_t*            pState,
                                        const uint32                     iArrayCurCycle,
                                              HLASegSubImageStatistic_t* pStat 
                                      )
{
  float32 Array[HLA_SEG_INTENSITY_SUB_IMG_WIDTH*HLA_SEG_INTENSITY_SUB_IMG_HEIGHT];
  uint32  index;
  sint32  i;
  uint32  size;  
  float32 Sum;
  

  /* copy intensities into array */
  /* and sort array              */
  /* expecting IntLength to be always positive! */
  size = (uint32) CML_MinMax(0, SI32_T_MAX, IntLength) * sizeof(float32);
  (void)memcpy((void*)&Array[0], (void*)&Int[0], size);
  HLASegSubImageQuickSort(IntLength, &Array[0]);


  /* calc Max80 */
  /* ~CodeReview ~ID:57adf74fccadf1eb2c9140aa351a4321 ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:3 ~Comment:magic number */
  index = (uint32)(0.8f * IntLength);
  /* ~CodeReview ~ID:0fe8582281403ef93818e53840c487e2 ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:2 ~Comment:Check that index is > 0 */
  pStat->Max80[iArrayCurCycle] = Array[index-1];
  /* calc. Max80_HistMedian */
  HLASegSubImageCalcHistMedian( &pStat->Max80[0],
                                iArrayCurCycle,
                                pState,
                                &pStat->Max80_HistMedian
                              ); 


  /* calc. Median */
  index = ( (uint32) IntLength) >> 1;
  pStat->Median[iArrayCurCycle] = Array[index];
  /* calc. Median_HistMedian */
  HLASegSubImageCalcHistMedian( &pStat->Median[0],
                                iArrayCurCycle,
                                pState,
                                &pStat->Median_HistMedian
                              ); 


  /* save Min, Max */
  pStat->Min = Array[0];
  pStat->Max = Array[IntLength-1];
  

  /* calc Mean */
  Sum = 0.0f;
  for(i=0; i<IntLength; i++)
  {
    Sum += Int[i];
  }
  /* ~CodeReview ~ID:bd893d957ea92d4113d5deb4c136305c ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:2 ~Comment:Check for devision by zero (IntLength) */
  pStat->Mean[iArrayCurCycle] = Sum/IntLength;
  /* calc. Mean_HistMedian */
  HLASegSubImageCalcHistMedian( &pStat->Mean[0],
                                iArrayCurCycle,
                                pState,
                                &pStat->Mean_HistMedian
                              ); 

  /* copy current state */
  pStat->State = *pState;  
}


/* **************************************************************************** 
  Functionname:     HLASegSubImageSetAccInt                           */ /*!  
  Description:      set accumulated intensity of the subsampled image

  @param[in]        CurRow: current row in absolute imager coordinates

  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegSubImageSetAccInt( const sint32                CurRow, 
                                           t_PixelData*          pCurRow, 
                                     const HLASegIn_t*           pIn, 
                                           HLASegSubImageData_t* pData
                                    )
{
  t_PixelData *pCurRowStart = pCurRow + HLA_SEGMENTATION_RED_OFFSET + pData->accPixOffset;
  uint32      *pAccInt;

  /* ~CodeReview ~ID:b5e81f8a18823cc4484afe5a88054063 ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:3 ~Comment:accIntCallCounter is only for debug purpose */
  pData->accIntCallCounter++;
  
  /* switch to next row of the subsampled image ? */
  if(CurRow > pIn->SubImage_EndRow[pData->currentRow])
  {
    pData->currentRow++;
    pData->currentRow = CML_Min(pData->currentRow, (HLA_SEG_INTENSITY_SUB_IMG_HEIGHT-1u));
  }
    
  /* accumulate intensity */
  pAccInt = &pData->accInt[pData->currentRow][0];
  
  /* ~CodeReview ~ID:65ad51580171a35a123db87a59d72e39 ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:2 ~Comment:(2148-2152) It is not made sure, that data is accessed correctly. There is a possibility that data outside the ringbuffer is accessed. */
  *pAccInt     += *(pCurRowStart + HLA_SEG_INTENSITY_PIX_OFFSET_0);
  *(pAccInt+1) += *(pCurRowStart + HLA_SEG_INTENSITY_PIX_OFFSET_1);
  *(pAccInt+2) += *(pCurRowStart + HLA_SEG_INTENSITY_PIX_OFFSET_2);
  *(pAccInt+3) += *(pCurRowStart + HLA_SEG_INTENSITY_PIX_OFFSET_3);
  *(pAccInt+4) += *(pCurRowStart + HLA_SEG_INTENSITY_PIX_OFFSET_4);
 
  pData->accCnt[pData->currentRow]++;
 

  /* set next pixel offset */
  pData->accPixOffset += HLA_SEG_INTENSITY_PIX_OFFSET_STEP;
  if(pData->accPixOffset >= HLA_SEG_INTENSITY_PIX_OFFSET_MAX)
  {
    pData->accPixOffset = 0u;
  }
}
