/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_seglight.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_seglight.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:37CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:19CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:53CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.2 2014/03/26 14:44:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:47 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1 2014/03/25 18:48:08CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_seglight.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* DEFINITIONS
******************************************************************************/
static void HLASegLightAddLight2List( const uint8                     iRegion,
                                      const uint16                    RoiYu,
                                            HLASegLineRegionBuffer_t* pRegionBuffer,
                                            HLASegLightBuffer_t*      pLightBuffer,
                                            HLASegLightData_t*        pLightData,
                                            HLASegLightDataRoi_t*     pLight_AboveRoi,
                                            HLASegLightDataRoi_t*     pLight_FunctRoi
                                    );

static void HLASegLightAddLight( const uint8                     iRegion,
                                const uint16                    RoiYu,
                                      HLASegLineRegionBuffer_t* pRegionBuffer,
                                      HLASegLightBuffer_t*      pLightBuffer,
                                      HLASegLightData_t*        pLightData,
                                      HLASegLightDataRoi_t*     pLight_AboveRoi,
                                      HLASegLightDataRoi_t*     pLight_FunctRoi
                                );

static uint8 HLASegLightGetRegionIndex( HLASegLineRegion_t*        pRegion,
                                        HLASegLineRegionBuffer_t*  pRegionBuffer
                                      );

/******************************************************************************
* FUNCTION DEFINITIONS
******************************************************************************/

/* ****************************************************************************
  Functionname:     HLASegLightBuildChainOut
  Description:      Build chain of all lights for segmentation output.
                    1. lights in function roi                
                    2. lights in above roi
  @param[in]             

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
void HLASegLightBuildChainOut( HLASegLightData_t* pDat,
                               HLASegOut_t*       pOut
                             )
{
  HLASegLight_t* Light = &pOut->Light[0];
  uint8 *piLightEnd;

  /* add lights from above roi */
  if(pDat->AboveRoi.iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    pOut->iLight = pDat->AboveRoi.iLight;
  }
  /* add function roi lights before above roi lights */
  if(pDat->FunctRoi.iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    piLightEnd = &pDat->FunctRoi.iLight;
    
    /* find last light function roi light list */
    while(*piLightEnd < HLA_SEG_MAX_NUM_LIGHTS)
    {
      piLightEnd = &Light[*piLightEnd].iLightNext;
    }
    *piLightEnd = pOut->iLight;
    pOut->iLight = pDat->FunctRoi.iLight;
  }
   
  /* number of all lights */
  pOut->nLights = pDat->AboveRoi.nLights[1] + pDat->FunctRoi.nLights[1];
}

/* ****************************************************************************
  Functionname:     HLASegLightBuildList
  Description:      Find new lights in current region level 3,2 or 1.

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightBuildList( const uint16                    RoiYu,
                                 HLASegLineRegionBuffer_t* pRegionBuffer,
                                 HLASegLightBuffer_t*      pLightBuffer,
                                 uint8                     iRegionStart,
                                 HLASegLightData_t*        pLightData,
                                 HLASegLightDataRoi_t*     pLight_AboveRoi,
                                 HLASegLightDataRoi_t*     pLight_FunctRoi
                          )

{
  uint8 nLightIn;
  uint8 nLightOut;
  HLASegLineRegion_t* pRb;
  uint8 iRegion = iRegionStart;
  HLASegLineRegion_t* Region = &(pRegionBuffer->Region[0]);


  while(iRegion < HLA_SEG_MAX_NUM_REGIONS)
  {
    /* No more space left in seglight buffer */
    if(pLightData->iLightFree >= HLA_SEG_MAX_NUM_LIGHTS)
    {
      break;
    }
    /* only superior regions can create a light ? */
    if(Region[iRegion].Status.MinorRegion == 0)
    {
      nLightIn = pLight_AboveRoi->nLights_Raw + pLight_FunctRoi->nLights_Raw;

      HLASegLightAddLight( /* input */
                           iRegion,
                           RoiYu,
                           pRegionBuffer,
                           pLightBuffer,
                           /* output */
                           pLightData,
                           pLight_AboveRoi,
                           pLight_FunctRoi
                         );

      /* count number of lights inside region */
      nLightOut = pLight_AboveRoi->nLights_Raw + pLight_FunctRoi->nLights_Raw;
    
      pRb = &Region[iRegion];
      while(pRb)
      {
        pRb->Status.numLightInRegion += (nLightOut - nLightIn);
        pRb = pRb->pRegionBelow;
      }
    }
    
    iRegion = Region[iRegion].iNext;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightBuildPairLights
  Description:      

  @param[in]          

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightBuildPairLights(       HLASegLightDataRoi_t*            pLightData,
                                       HLASegLineRegionBuffer_t*        pRegionBuffer,
                                       HLASegLightBuffer_t*             pLightBuffer,
                                 const HLACameraData_t*                 pCamData,
                                 const HLASegmentationParametersPair_t* pPar
                               )
{
  HLASegLight_t* Light = &(pLightBuffer->Light[0]);
  HLASegLineRegion_t* Reg = &(pRegionBuffer->Region[0]);
  uint8 iLight1 = pLightData->iLight;
  uint16 MinInt = (uint16)HLAImager_GetGreen_Lux(pPar->minInt);
  uint16 MaxInt = (uint16)HLAImager_GetGreen_Lux(pPar->maxInt);

  uint8 iReg1, iReg2, iLight2;

  while(iLight1 < HLA_SEG_MAX_NUM_LIGHTS)
  {
    iReg1 = Light[iLight1].RegionLevel0_ID;   

    /* J.Häfer: No Possible Side Effect */
    /* PRQA S 3415 6 */
    if(    (Light[iLight1].Maxima.ngb[Light[iLight1].Maxima.i_ngb].raw > MinInt)
        && (Light[iLight1].Maxima.ngb[Light[iLight1].Maxima.i_ngb].raw < MaxInt)
        && (abs(Light[iLight1].Maxima.x - pCamData->FOE_x) < pPar->dxFOE)
        && (abs(Light[iLight1].Maxima.y - pCamData->FOE_y) < pPar->dyFOE)
        && (iReg1 < HLA_SEG_MAX_NUM_REGIONS)
      )
    {
      if(    ((Reg[iReg1].x2-Reg[iReg1].x1) < pPar->maxRegSize_x)
          && ((Reg[iReg1].y2-Reg[iReg1].y1) < pPar->maxRegSize_y)
        ) 
      {
        iLight2 = Light[iLight1].iLightNext;

        while(iLight2 < HLA_SEG_MAX_NUM_LIGHTS)
        {
          iReg2 = Light[iLight2].RegionLevel0_ID;

          /* check pair criteria */
          /* J.Häfer: No Possible Side Effect */
          /* PRQA S 3415 6 */
          if(    (abs(Light[iLight1].Maxima.y - Light[iLight2].Maxima.y) <= pPar->dy)
              && (abs(Light[iLight1].Maxima.x - Light[iLight2].Maxima.x) <= pPar->dx)
              && (Light[iLight2].Maxima.ngb[Light[iLight2].Maxima.i_ngb].raw > MinInt)
              && (Light[iLight2].Maxima.ngb[Light[iLight2].Maxima.i_ngb].raw < MaxInt)
              && (iReg2 < HLA_SEG_MAX_NUM_REGIONS)
            )
          {
            if(    ((Reg[iReg2].x2-Reg[iReg2].x1) < pPar->maxRegSize_x)
                && ((Reg[iReg2].y2-Reg[iReg2].y1) < pPar->maxRegSize_y)
              ) 
            {
              /* pair light detected */
              Light[iLight1].Status.isOPLight = 1;
              Light[iLight2].Status.isOPLight = 1;
            }
          }
          iLight2 = Light[iLight2].iLightNext;
        }
      }
    }
    iLight1 = Light[iLight1].iLightNext;
  }  
}

/* ****************************************************************************
  Functionname:     HLASegLightSearchPairLights
  Description:      

  @param[in]          

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightSearchPairLights( const HLA_t_CameraParameter*                  pCameraParameter,
                                  const HLACameraData_t*                        pCamData,
                                        t_PixelData*                            pImg,
                                        HLASegData_t* restrict                  pData,
                                        HLASegLightDataRoi_t*                   pLightData,
                                  const HLASegmentationParametersPair_t*        pPar,
                                        HLASegLineRegionBuffer_t*               pRegionBuffer,
                                        HLASegLightBuffer_t*                    pLightBuffer
                                )
{
  HLASegLight_t* restrict Light    = &(pLightBuffer->Light[0]);
  HLASegLineRegion_t* restrict Reg = &(pRegionBuffer->Region[0]);
  uint8 iLight            = pLightData->iLight;
  /* offset in pixels to get to next row in memory */
  sint32 rowOffsetPixels  = pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes;
  sint32 rowOffsetPixels2 = 2 * rowOffsetPixels;
  uint16 MinInt = (uint16)HLAImager_GetGreen_Lux(pPar->minInt);
  uint16 MaxInt = (uint16)HLAImager_GetGreen_Lux(pPar->maxInt);

  uint8 iReg, iLight1, SaveNewPairLight, iLightNew;
  sint32 dx = 0;
  sint32 dy = 0;
  t_PixelData *pPixLight, *pPix, *pPixMax, *pPixStart;  
  sint32 i1, i2, i, j;
  uint16 NewMax_x, NewMax_y;
  HLASegLineRegion_t *pReg;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    /* search for pair maxima */
    iReg = Light[iLight].RegionLevel0_ID;

    /* J.Häfer: No Possible Side Effect */
    /* PRQA S 3415 6 */
    if(   (Light[iLight].Status.isOPLight == 0)
       && (Light[iLight].Maxima.ngb[Light[iLight].Maxima.i_ngb].raw > MinInt)
       && (Light[iLight].Maxima.ngb[Light[iLight].Maxima.i_ngb].raw < MaxInt)
       && (abs(Light[iLight].Maxima.x - pCamData->FOE_x) < pPar->dxFOE)
       && (abs(Light[iLight].Maxima.y - pCamData->FOE_y) < pPar->dyFOE)
       && (iReg < HLA_SEG_MAX_NUM_REGIONS)
      )
    {
      if(    ((Reg[iReg].x2-Reg[iReg].x1) < pPar->maxRegSize_x)
          && ((Reg[iReg].y2-Reg[iReg].y1) < pPar->maxRegSize_y)
        ) 
      {
        pPixLight = pImg + (Light[iLight].Maxima.x - pCameraParameter->s_CroppedRoiX1.ui32_x) + (rowOffsetPixels*(sint32)(Light[iLight].Maxima.y - pCameraParameter->s_CroppedRoiX1.ui32_y));
        pPixMax = NULL;        

        /* search maxima on left side of current light*/
        {
          i1 = -pPar->dx;
          i2 = -3;
          pPixStart = pPixLight + i1;         

          for(j = -pPar->dy; j <= pPar->dy; j++)
          {
            pPix = pPixStart + (j*rowOffsetPixels);

            for(i = i1; i <= i2; i++)
            {
              if(    (*pPix > MinInt)
                  && (*pPix > *(pPix-2))
                  && (*pPix > *(pPix+2))
                  && (*pPix > *(pPix-rowOffsetPixels2))
                  && (*pPix > *(pPix+rowOffsetPixels2))
                )
              {
                /* new maxima detected */
                if(pPixMax != NULL)
                {
                  if(*pPix > *pPixMax)
                  {
                    pPixMax = pPix;
                    dx = i;
                    dy = j;
                  }
                }
                else
                {
                  pPixMax = pPix;
                  dx = i;
                  dy = j;
                }
              }
              pPix++;
            }
          }
        }
        /* search maxima on right side of current light*/
        {
          i1 = 3;
          i2 = pPar->dx;
          pPixStart = pPixLight + i1;
          
          for(j = -1; j <= 1; j++)
          {
            pPix = pPixStart + (j*rowOffsetPixels);

            for(i = i1; i <= i2; i++)
            {
              if(    (*pPix > MinInt)
                  && (*pPix > *(pPix-2))
                  && (*pPix > *(pPix+2))
                  && (*pPix > *(pPix-rowOffsetPixels2))
                  && (*pPix > *(pPix+rowOffsetPixels2))
                )
              {
                /* new maxima detected */
                if(pPixMax != NULL)
                {
                  if(*pPix > *pPixMax)
                  {
                    pPixMax = pPix;
                    dx = i;
                    dy = j;
                  }
                }
                else
                {
                  pPixMax = pPix;
                  dx = i;
                  dy = j;
                }
              }
              pPix++;
            }
          }
        } 
        
        /* pair light found */
        if(pPixMax)
        {
          /* check if another light is near to this light */
          iLight1 = pLightData->iLight;
          SaveNewPairLight = 1;
          /* J.Häfer: Misra Rule 9.1 unset variabel isn't possible, will be setted with pPixMax */
          /* PRQA S 3353 2 */
          NewMax_x = (uint16)(Light[iLight].Maxima.x + dx);
          NewMax_y = (uint16)(Light[iLight].Maxima.y + dy);

          while(iLight1 < HLA_SEG_MAX_NUM_LIGHTS)
          {
            if(iLight1 != iLight)
            {
              /* J.Häfer: No Possible Side Effect */
              /* PRQA S 3415 6 */
              if(    (abs(Light[iLight1].Maxima.x - NewMax_x) < 3)
                  && (abs(Light[iLight1].Maxima.y - NewMax_y) < 3)
                )
              {
                SaveNewPairLight = 0;
              }
            }
            iLight1 = Light[iLight1].iLightNext;
          }

          /* -> save new pair light */
          if(    (SaveNewPairLight != 0)
              && (pData->LightData.iLightFree < HLA_SEG_MAX_NUM_LIGHTS)
            )
          {
            HLASegLight_t *Light = &(pLightBuffer->Light[0]);

            /* add new light to list */
            iLightNew = pData->LightData.iLightFree;

            /* set pLightFree to next free light          */
            /* before data for the new light will be set  */
            pData->LightData.iLightFree = Light[iLightNew].iLightNext;
            
            /* save maxima pixels */
            HLASegUtilsSaveMaxima( pCameraParameter,
                                   pImg,
                                   pPixMax,
                                   &Light[iLightNew]
                                 );
                                    
            /* set light position */
            Light[iLightNew].xcenter = Light[iLightNew].Maxima.x;
            Light[iLightNew].ycenter = Light[iLightNew].Maxima.y;
            Light[iLight].xcenter = Light[iLight].Maxima.x;
            Light[iLight].ycenter = Light[iLight].Maxima.y;

            /* set region */
            Light[iLightNew].pRegion = Light[iLight].pRegion;
            Light[iLightNew].RegionLevel0_ID = Light[iLight].RegionLevel0_ID;

            /* update numLightInRegion */
            {
              pReg = Light[iLight].pRegion;

              while(pReg)
              {
                pReg->Status.numLightInRegion++;
                pReg = pReg->pRegionBelow;
              }
            }

            /* set pair flag */
            Light[iLightNew].Status.isNewPairLight = 1;
            Light[iLightNew].Status.DoNotStartNewTrack = 1;
            Light[iLightNew].Status.isOPLight = 1;
            Light[iLight].Status.isOPLight = 1;

            /* add new light to the beginning of the list */
            Light[iLightNew].iLightNext  = pLightData->iLight;
            pLightData->iLight = iLightNew;
            pLightData->nLights_Raw++;
            pLightData->nLights[0]++;
          }
        }   
      }
    }
    iLight = Light[iLight].iLightNext;
  }  
}


/* ****************************************************************************
  Functionname:     HLASegLightAddLight
  Description:      Add new light into light list chain.

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightAddLight( const uint8                     iRegion,
                                const uint16                    RoiYu,
                                      HLASegLineRegionBuffer_t* pRegionBuffer,
                                      HLASegLightBuffer_t*      pLightBuffer,
                                      HLASegLightData_t*        pLightData,
                                      HLASegLightDataRoi_t*     pLight_AboveRoi,
                                      HLASegLightDataRoi_t*     pLight_FunctRoi
                                )

{
  HLASegLineRegion_t* Region = &(pRegionBuffer->Region[0]);
  sint32 dx = (Region[iRegion].x2 - Region[iRegion].x1) + 2;
  sint32 dy = Region[iRegion].y2 - Region[iRegion].y1;
  sint32 dx1, dy1;
  float32 MaxAspectRatio = (float32)(CML_Max(dx, dy))/(float32)(CML_Min(dx, dy)); /* aspect of region */
  float32 FillFactor = (2.0f * Region[iRegion].ySum)/(dx*dy);
  float32 MaxAspectRatio1; /* aspect of region below */
  boolean bAddNewLight = b_FALSE;

  if(Region[iRegion].pRegionBelow)
  {
    dx1 = (Region[iRegion].pRegionBelow->x2 - Region[iRegion].pRegionBelow->x1) +2;
    dy1 = Region[iRegion].pRegionBelow->y2 - Region[iRegion].pRegionBelow->y1;
    MaxAspectRatio1 = (float32)(CML_Max(dx1, dy1))/(float32)(CML_Min(dx1, dy1));
  }
  else
  {
    dx1 = dx;
    dy1 = dy;
    MaxAspectRatio1 = MaxAspectRatio;
  }

  /* determine bAddNewLight */
  /* small fill factor */
  if(FillFactor < 0.5f)
  {
    bAddNewLight = b_TRUE;
  }
  /* small light source */
  else if(    (dx < 15)
           && (dy < 15)
         )
  {
    bAddNewLight = b_TRUE;
  }
  else if(    (dx < 50)
           && (dy < 50)
           && (dx1 < 100)
           && (dy1 < 100)
           && (MaxAspectRatio  < 5.0f)
           && (MaxAspectRatio1 < 5.0f)
         )
  {
    bAddNewLight = b_TRUE;
  }
  else
  {
    /* No new light, bAddNewLight already set to b_FALSE */
  }
  

  if(bAddNewLight == b_TRUE)
  {
    /* generate new light  */
    HLASegLightAddLight2List( /* input  */
                              iRegion,
                              RoiYu,
                              pRegionBuffer,
                              pLightBuffer,
                              /* output */
                              pLightData,
                              pLight_AboveRoi,
                              pLight_FunctRoi
                            );
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightAddLight2List
  Description:      Add new light into light list chain.

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightAddLight2List( const uint8                     iRegion,
                                      const uint16                    RoiYu,
                                            HLASegLineRegionBuffer_t* pRegionBuffer,
                                            HLASegLightBuffer_t*      pLightBuffer,
                                            HLASegLightData_t*        pLightData,
                                            HLASegLightDataRoi_t*     pLight_AboveRoi,
                                            HLASegLightDataRoi_t*     pLight_FunctRoi
                                    )
{
  uint8 iLight;
  HLASegLineRegion_t* Region = &(pRegionBuffer->Region[0]);
  HLASegLight_t* Light = &(pLightBuffer->Light[0]);
  HLASegLineRegion_t* pReg = &Region[iRegion];

  /* region creates a light */
  Region[iRegion].Status.LightCreated = 1;

  /* add new light to list */
  iLight = pLightData->iLightFree;

  /* set pLightFree to next free light          */
  /* before data for the new light will be set  */
  pLightData->iLightFree = Light[pLightData->iLightFree].iLightNext;

  Light[iLight].pRegion     = &Region[iRegion];

  /* set light position */
  Light[iLight].xcenter       = (Region[iRegion].x1 + Region[iRegion].x2) >> 1;
  Light[iLight].ycenter       = (Region[iRegion].y1 + Region[iRegion].y2) >> 1;

  /* set region level0 ID */

  while(pReg->pRegionBelow)
  {
    pReg = pReg->pRegionBelow;
  }
  Light[iLight].RegionLevel0_ID = HLASegLightGetRegionIndex(pReg, pRegionBuffer);

  /* light in above roi or function roi */
  if(Light[iLight].ycenter < RoiYu)
  {
    /* above roi                                  */
    /* add new light to the beginning of the list */
    if(pLight_AboveRoi->iLight == HLA_SEG_MAX_NUM_LIGHTS)
    {
      /* first light in the list */
      Light[iLight].iLightNext    = HLA_SEG_MAX_NUM_LIGHTS;
      pLight_AboveRoi->iLight     = iLight;
    }
    else
    {
      Light[iLight].iLightNext  = pLight_AboveRoi->iLight;
      pLight_AboveRoi->iLight   = iLight;
    }
    pLight_AboveRoi->nLights_Raw++;
  }
  else
  {
    /* function roi                               */
    /* add new light to the beginning of the list */
    if(pLight_FunctRoi->iLight == HLA_SEG_MAX_NUM_LIGHTS)
    {
      /* first light in the list */
      Light[iLight].iLightNext    = HLA_SEG_MAX_NUM_LIGHTS;
      pLight_FunctRoi->iLight     = iLight;
    }
    else
    {
      Light[iLight].iLightNext  = pLight_FunctRoi->iLight;
      pLight_FunctRoi->iLight   = iLight;
    }
    pLight_FunctRoi->nLights_Raw++;
  }
} 

/* ****************************************************************************
  Functionname:     HLASegRegionGetIndex */ /*!
  Description:      Returns index of pRegion

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static uint8 HLASegLightGetRegionIndex( HLASegLineRegion_t*        pRegion,
                                        HLASegLineRegionBuffer_t*  pRegionBuffer
                                      )
{
  uint8 Index;

  /* J.Häfer: Misra Rule 11.3 pointer casting wanted to save runtime */
  /* PRQA S 306 1 */
  Index = (uint8)(((uint32)pRegion - (uint32)&(pRegionBuffer->Region[0]))/sizeof(HLASegLineRegion_t));

  return Index;
}


