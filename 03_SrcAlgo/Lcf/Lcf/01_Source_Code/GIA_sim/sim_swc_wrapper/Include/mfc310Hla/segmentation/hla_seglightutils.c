/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_seglightutils.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_seglightutils.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:38CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:23CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:56CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.2 2014/03/26 14:44:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:47 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1 2014/03/25 18:48:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include "hla_seglightutils.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* PROTOTYPES
******************************************************************************/
static void HLASegLightUtilsIsPotRed( const HLACameraData_t*                        pCamData,
                                      const HLASegmentationParametersRedLightDet_t* pPar,
                                            HLASegLight_t*                          pLight
                                     );

static void HLASegLightUtilsQuickSortWithRef( const sint32  elements,
                                                    uint16* arr,
                                                    uint8*  ref                                              
                                            );

/******************************************************************************
* FUNCTION DEFINITIONS
******************************************************************************/

/* ****************************************************************************
  Functionname:     HLASegLightUtilsDetectionSaturation
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsDetectionSaturation( HLASegLightDataRoi_t* pLightData,
                                          HLASegLightBuffer_t*  pLightBuffer
                                        )

{
  uint16 iLight = pLightData->iLight;
  uint16 T1Sat_L = HLAImager_GetT1SatLow();
  uint16 T1Sat_H = HLAImager_GetT1SatHigh();
  uint16 Sat = HLAImager_GetSaturation();


  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    HLASegLight_t *pLight = &(pLightBuffer->Light[iLight]);
    HLASegMaxima_t *pMax = &pLight->Maxima;
    uint8  i_ngb_max = pMax->i_ngb;
    sint8 ix, iy;
    uint8 i_ngb;
    uint8 nSat = 0; 
    uint8 nSatT1 = 0;
    uint16 pix;


    /* check only the direct surrounding pixels */
    i_ngb = (i_ngb_max-1)-HLA_SEG_MAX_NUM_NGB_XY;
    
    for(iy = -1; iy < 2; iy++)
    {
      for(ix = -1; ix < 2; ix++)
      { 
        pix = pMax->ngb[i_ngb].raw;
        
        if(pix >= Sat)
        {
          nSat++;
        }
        else if(    (pix >= T1Sat_L)
                 && (pix <= T1Sat_H)
               )
        {
          nSatT1++;
        }

        i_ngb++;
      }
      i_ngb = (i_ngb + HLA_SEG_MAX_NUM_NGB_XY) - 3;
    }
    
    if(nSat > 0)
    {
      pLight->Status.Sat = 1;
    }
    else if(nSatT1 > 1)
    {
      pLight->Status.Sat_T1 = 1;
    }

    iLight = pLight->iLightNext;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsPotentialRedDetection
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsPotentialRedDetection( const HLACameraData_t*                        pCamData,
                                            const HLA_t_SegmentationParametersBrightness* pPar,
                                                  HLASegLightDataRoi_t*                   pLightData,
                                                  HLASegLightBuffer_t*                    pLightBuffer						
                                          )
    {
  HLASegLight_t* restrict Light = &(pLightBuffer->Light[0]);
  uint8 iLight = pLightData->iLight;
 

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    
    /* potential red light  ? */
    HLASegLightUtilsIsPotRed( pCamData, 
                              &pPar->RedLightDet,
                              &Light[iLight]
                            );
    
    iLight = Light[iLight].iLightNext;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsPotentialLEDDetection
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsPotentialLEDDetection( const HLACameraData_t*                        pCamData,
                                            const HLA_t_SegmentationParametersBrightness* pParBrightness,
                                                  HLASegLightDataRoi_t*                   pLightData,
                                                  HLASegLightBuffer_t*                    pLightBuffer
                                          )

{
  HLASegLight_t *Light = &(pLightBuffer->Light[0]);
  uint8 iLight = pLightData->iLight;
  uint16 T1Sat_L = HLAImager_GetT1SatLow();
  uint16 T1Sat_H = HLAImager_GetT1SatHigh(); 

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    sint32 dx = (Light[iLight].pRegion->x2 - Light[iLight].pRegion->x1) + 2;
    sint32 dy = Light[iLight].pRegion->y2 - Light[iLight].pRegion->y1;
    float32 MaxAspectRatio = (float32)(CML_Max(dx,dy))/(float32)(CML_Min(dx,dy));

    if(    ((Light[iLight].pRegion->Level) >= (pParBrightness->Light.iT1SatLevel))
        && ((Light[iLight].pRegion->Level) <= (pParBrightness->Light.iT1SatLevel + 1))
        && ((Light[iLight].ycenter) > (pCamData->FOE_y - 20))
        && (dx >= 2)
        && (dy >= 2)
        && (dx < 20)
        && (dy < 20)
        && (MaxAspectRatio < 5.0f)
      )
    {
      uint8 nT1Sat = 0; /* number of pixels with intensity between T1Sat_L and T1Sat_H */
      uint8 i;
        
      /* count the number of T1Sat Pixels and pixels above IntThres */
      for(i=0; i<HLA_SEG_MAX_NUM_NGB; i++)
      {
        if(    (Light[iLight].Maxima.ngb[i].raw >= T1Sat_L)
            && (Light[iLight].Maxima.ngb[i].raw <= T1Sat_H)
          )
        {
          nT1Sat++;
        }
      }
    
      Light[iLight].nT1Sat = nT1Sat;
    
      /* potential LED light ? */
      if(nT1Sat > 6)
      {
        Light[iLight].Status.isPotLed = 1;
      }
    }
    iLight = Light[iLight].iLightNext;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsSetLightPosition
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsSetLightPosition( const uint8                iLBStart,
                                             HLASegLightBuffer_t* pLightBuffer
                                     )
{
  uint8 iLight = iLBStart;

  /* Stuff needed inside while loop, defined outside for sw-pipelining */
  HLASegLight_t* restrict       pLight;
  HLASegLineRegion_t* restrict pRegion;
  uint16 regionX1;
  uint16 regionX2;
  uint16 regionY1;
  uint16 regionY2;
  uint16 xMax;
  uint16 yMax;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    /* Stuff defined here due to sw-pipelining */
    pLight = &(pLightBuffer->Light[iLight]);
    pRegion = pLight->pRegion;
    regionX1 = pRegion->x1;
    regionX2 = pRegion->x2;
    regionY1 = pRegion->y1;
    regionY2 = pRegion->y2;
    xMax = pLight->Maxima.x;
    yMax = pLight->Maxima.y;

    /* small light -> light position = maxima position */
    if(    ((regionX2 - regionX1) < 5u)
        || ((regionY2 - regionY1) < 5u)
      )
    {
      pLight->xcenter = xMax;
      pLight->ycenter = yMax;
    }
    else
    {
      pLight->xcenter = (regionX2 + regionX1 + 1u)>>1;
      pLight->ycenter = (regionY2 + regionY1 + 1u)>>1;
    }

    iLight = pLight->iLightNext;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsSetMaxInt
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsSetMaxInt( HLASegData_t*  pData,
                                HLASegOut_t*   pOut
                              )
{
  HLASegLight_t *Light = &pOut->Light[0];
  uint16 iLight = pOut->iLight;
  uint16 MaxInt = 0;
  uint16 i;


  pData->MaxInt.iHist++;
  if(pData->MaxInt.iHist >= HLA_SEG_LIGHT_MAX_INT_HIST_LEN)
  {
    pData->MaxInt.iHist = 0;
  }

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    MaxInt = CML_Max(MaxInt, Light[iLight].MaxInt);
   
    iLight = Light[iLight].iLightNext;
  }

  pData->MaxInt.Hist[pData->MaxInt.iHist] = MaxInt;

  for(i=0;i<HLA_SEG_LIGHT_MAX_INT_HIST_LEN;i++)
  {
    MaxInt = CML_Max(MaxInt, pData->MaxInt.Hist[i]);
  }    
  pData->MaxInt.maxInt = MaxInt;
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsSortFromBottomUp
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsSortFromBottomUp( HLASegLightDataRoi_t* pLightData,
                                       HLASegLightBuffer_t*  pLightBuffer
                                     )
{
  uint16 Light_PosY[HLA_SEG_MAX_NUM_LIGHTS];
  uint8  Light_Id[HLA_SEG_MAX_NUM_LIGHTS];
  uint8  iLight = pLightData->iLight;
  uint8  n = 0;
  uint32 i;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    Light_PosY[n] = pLightBuffer->Light[iLight].ycenter;
    Light_Id[n]   = iLight;
    
    iLight = pLightBuffer->Light[iLight].iLightNext_sub;
    n++;
  }

  if(n>0)
  {
    HLASegLightUtilsQuickSortWithRef( n, 
                                      &Light_PosY[0],
                                      &Light_Id[0]
                                    );
    
    pLightData->iLight = Light_Id[n-1];
    for(i=(n-1);i>0;i--)
    {
      pLightBuffer->Light[Light_Id[i]].iLightNext_sub = Light_Id[i-1];
    }
    pLightBuffer->Light[Light_Id[0]].iLightNext_sub = HLA_SEG_MAX_NUM_LIGHTS;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsSplitLightList
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsSplitLightList( HLASegLightBuffer_t*  pLightBuffer,
                                     HLASegLightDataRoi_t* pLightData_In,
                                     HLASegLightDataRoi_t* pLightData_Red,
                                     HLASegLightDataRoi_t* pLightData_Led,
                                     HLASegLightDataRoi_t* pLightData_Bright
                                   )
{
  uint8 iLight = pLightData_In->iLight;
  uint8* piLight_Red = &pLightData_Red->iLight;
  uint8* piLight_Led = &pLightData_Led->iLight;
  uint8* piLight_Bright = &pLightData_Bright->iLight;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    /* pot. red light */
    if(    (pLightBuffer->Light[iLight].Status.isPotRed == 1)
        || (pLightBuffer->Light[iLight].Status.isPotRed_dark == 1)
      )
    {
      *piLight_Red = iLight;
      piLight_Red = &pLightBuffer->Light[iLight].iLightNext_sub;

      pLightData_Red->nLights_Raw++;
    }
    /* pot. led light */
    else if(pLightBuffer->Light[iLight].Status.isPotLed)
    {
      *piLight_Led = iLight;
      piLight_Led = &pLightBuffer->Light[iLight].iLightNext_sub;

      pLightData_Led->nLights_Raw++;
    }
    /* all other lights (bright lightss) */
    else
    {
      *piLight_Bright = iLight;
      piLight_Bright = &pLightBuffer->Light[iLight].iLightNext_sub;

      pLightData_Bright->nLights_Raw++;
    }

    iLight = pLightBuffer->Light[iLight].iLightNext;
  }
  /* finalize list */
  *piLight_Red    = HLA_SEG_MAX_NUM_LIGHTS;
  *piLight_Led    = HLA_SEG_MAX_NUM_LIGHTS;
  *piLight_Bright = HLA_SEG_MAX_NUM_LIGHTS;
}

/* ****************************************************************************
  Functionname:     HLASegLightUtilsRemoveDarkLights
  Description:      

  @param[in]          

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightUtilsRemoveDarkLights( const HLACameraData_t*                        pCamData,
                                       const HLA_t_SegmentationParametersBrightness* pParBrightness,
                                             HLASegLightDataRoi_t* restrict          pLightData,
                                             HLASegLightBuffer_t*                    pLightBuffer
                                     )
{
  HLASegLight_t* restrict Light = &(pLightBuffer->Light[0]);
  uint8* piLight = &pLightData->iLight;
  uint8* piLightDark;    

  /* remove lights below min intensity */
  while(*piLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    /*     do not remove potential pair lights */
    /* and do not remove potential Led lights  */
    if(    (Light[*piLight].Status.isOPLight == 0)
        && (Light[*piLight].Status.isPotLed == 0)
      )
    {  
      piLightDark = NULL;
      float32 MinInt_x;
      float32 MinInt_y;
      float32 MinInt;
      const HLA_t_SegmentationParametersDarkLight *pParDark;

      if(Light[*piLight].ycenter < pCamData->RoiYu)
      {
        /* Light in above ROI (City ROI) */
        float32 dFunctAbove = CML_f_Max(1.0f, (float32)(pCamData->RoiYu - pCamData->RoiY1));
        pParDark = &pParBrightness->DarkNonRedLight;

        MinInt = pParDark->minInt_FunctRoiBorder + (((pCamData->RoiYu-Light[*piLight].ycenter)/dFunctAbove)*(pParDark->minInt_AboveRoiBorder-pParDark->minInt_FunctRoiBorder));
        MinInt = CML_f_MinMax(pParDark->minInt_FunctRoiBorder, pParDark->minInt_AboveRoiBorder, MinInt);
      }
      else
      {
        /* Light in Function ROI */
        if(    (Light[(*piLight)].Status.isPotRed == 1)
            || (Light[(*piLight)].Status.isPotRed_dark == 1)
          )
        {
           pParDark = &pParBrightness->DarkRedLight;
        }
        else
        {
           pParDark = &pParBrightness->DarkNonRedLight;
        }
      
        /* calc. MinInt_x */
        if(Light[*piLight].xcenter < (pCamData->FOE_x-pParDark->dxFOE))
        {
          float32 dFoeRoiBorder = CML_f_Max(1.0f, (float32)((pCamData->FOE_x-pParDark->dxFOE) - pCamData->RoiX1));
          
          MinInt_x = pParDark->minInt_FOE + ((((pCamData->FOE_x-pParDark->dxFOE)-Light[*piLight].xcenter)/dFoeRoiBorder)*(pParDark->minInt_FunctRoiBorder-pParDark->minInt_FOE));
        }
        else if(Light[*piLight].xcenter > (pCamData->FOE_x+pParDark->dxFOE))
        {
          float32 dFoeRoiBorder = CML_f_Max(1.0f, (float32)(pCamData->RoiX2 - (pCamData->FOE_x+pParDark->dxFOE)));

          MinInt_x = pParDark->minInt_FOE + (((Light[*piLight].xcenter- (pCamData->FOE_x+pParDark->dxFOE))/dFoeRoiBorder)*(pParDark->minInt_FunctRoiBorder-pParDark->minInt_FOE));
        }
        else
        {
          MinInt_x = pParDark->minInt_FOE;
        }
        MinInt_x = CML_f_MinMax(pParDark->minInt_FOE, pParDark->minInt_FunctRoiBorder, MinInt_x);

        /* calc. MinInt_y */
        if(Light[*piLight].ycenter < (pCamData->FOE_y - pParDark->dyFOE))
        {
          float32 dFoeRoiBorder = CML_f_Max(1.0f, (float32)((pCamData->FOE_y - pParDark->dyFOE) - pCamData->RoiYu));

          MinInt_y = pParDark->minInt_FOE + ((((pCamData->FOE_y - pParDark->dyFOE)-Light[*piLight].ycenter)/dFoeRoiBorder)*(pParDark->minInt_FunctRoiBorder-pParDark->minInt_FOE));
        }
        else if(Light[*piLight].ycenter > (pCamData->FOE_y + pParDark->dyFOE))
        {
          float32 dFoeRoiBorder = CML_f_Max(1.0f, (float32)(pCamData->RoiY2 - (pCamData->FOE_y + pParDark->dyFOE)));

          MinInt_y = pParDark->minInt_FOE + (((Light[*piLight].ycenter- (pCamData->FOE_y + pParDark->dyFOE))/dFoeRoiBorder)*(pParDark->minInt_FunctRoiBorder-pParDark->minInt_FOE));
        }
        else
        {
          MinInt_y = pParDark->minInt_FOE;
        }
        MinInt_y = CML_f_MinMax(pParDark->minInt_FOE, pParDark->minInt_FunctRoiBorder, MinInt_y);

        MinInt = CML_Max(MinInt_x, MinInt_y);
      }

      if(Light[*piLight].MaxInt < MinInt)
      {
        piLightDark = piLight;
      }
        
      if(piLightDark)
      {
        /* remove dark light from light list */
        Light[*piLightDark].RejectedReason[0] |= HLA_SEG_LIGHT_RR_DARKLIGHT;
        *piLightDark = Light[*piLightDark].iLightNext;
        pLightData->nLights[0]--;
      }
      else
      {
        piLight = &Light[*piLight].iLightNext;
      }
    }
    else
    {
      piLight = &Light[*piLight].iLightNext;
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLASegUtilsQuickSortWithRef   (static)                */ /*!
  Description:      quick sort with reference array

  @param[in]        
  @param[out]      
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightUtilsQuickSortWithRef( const sint32  elements,
                                                    uint16* arr,
                                                    uint8*  ref                                              
                                            )
{
  uint16 piv;
  uint8  piv_ref;
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
      piv_ref = ref[L];

      while(L<R)
      {
        while ((arr[R]>=piv) && (L<R)) R--;
        if(L<R)
        {
          arr[L]=arr[R];
          ref[L]=ref[R];
          L++;
        }
        while((arr[L]<=piv) && (L<R)) L++;
        if(L<R)
        {
          arr[R]=arr[L];
          ref[R]=ref[L];
          R--;
        }  
      }
      arr[L]=piv;
      ref[L]=piv_ref;
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
  Functionname:     HLASegLightUtilsIsPotRed
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightUtilsIsPotRed( const HLACameraData_t*                        pCamData,
                                      const HLASegmentationParametersRedLightDet_t* pPar,
                                            HLASegLight_t*                          pLight
                                     )
{
  uint16 R = (uint16)pLight->current_R;
  uint16 G = (uint16)pLight->current_G;
  uint16 B = (uint16)pLight->current_B;

  /* red light */
  if(    (pLight->Status.isPotLed == 0)
      && (pLight->Status.Sat_T1 == 0)
      && (pLight->Status.Sat == 0)
    )
  {
    /* potential red light */  
    if(   (R >= (pPar->MinR2G * G))
       && (R >= (pPar->MinR2B * B))
       )
    {
      pLight->Status.isPotRed = 1;
    }
    /* potential dark red light */  
    /* J.Häfer: No Possible Side Effect */
    /* PRQA S 3415 6 */  
    else if(    (abs(pLight->xcenter - pCamData->FOE_x) < pPar->dxFOE_dark) 
             && (abs(pLight->ycenter - pCamData->FOE_y) < pPar->dyFOE_dark) 
             && (pLight->MaxInt < pPar->MaxInt_dark)
             && (R >= (pPar->MinR2G_dark * G))
             && (R >= (pPar->MinR2B_dark * B))
           )
    {
      pLight->Status.isPotRed_dark = 1;
    }
    else
    {
      /* do nothing */
    }
  }
}/* PRQA S 861 1 */
