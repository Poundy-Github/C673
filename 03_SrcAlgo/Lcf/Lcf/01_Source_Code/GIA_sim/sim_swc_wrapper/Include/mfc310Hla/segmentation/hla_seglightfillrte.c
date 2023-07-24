/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_seglightfillrte.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_seglightfillrte.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:37CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:20CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:54CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_seglightfillrte.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* FUNCTION PROTOTYPES
******************************************************************************/
static void HLASegLightFillRteOutputSetLightData( const uint8                LightID,
                                                  const HLASegLight_t*       pSrc,
              RTE_HLA_Seg_Light_t* pDest
                                                );

static void HLASegLightFillRteOutputSetRegionData( const HLASegLineRegion_t*   pSrc,
                     RTE_HLA_Seg_Region_t* pDest
                                                 );

/******************************************************************************
* FUNCTION DEFINITONS
******************************************************************************/

/* ****************************************************************************
  Functionname:     HLASegLightFillRteOutput
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightFillRteOutput( const HLASegData_t*             pData,
                               const HLASegOut_t*              pOut,
                                     HLASegLightBuffer_t*      pLightBuffer,
                               const HLASegLineRegionBuffer_t* pRegionBuffer,
                               const HLACameraData_t*          pCamData,
                                     RTE_HLA_Seg_LightList_t*  ps_SegLightList /* RTE Out */
                             )
{
  if(ps_SegLightList)
  {
    HLASegLight_t *LightSrc = &pLightBuffer->Light[0];
    RTE_HLA_Seg_Light_t *LightDest = &ps_SegLightList->Light[0];
    uint8 iLightSrc;
    uint8 iLightDest;
    uint8 LightIDTab_Dest2Src[RTE_HLA_SEG_LIGHT_LIST_LENGTH];


    memset(&LightIDTab_Dest2Src[0],  UI8_T_MAX, sizeof(uint8)*RTE_HLA_SEG_LIGHT_LIST_LENGTH);

    /* set all data to zero */
    memset(ps_SegLightList, 0, sizeof(RTE_HLA_Seg_LightList_t));


    /* 1. fill hla relevant lights (tracked lights) */ 
    /*    from function and above ROI               */
    iLightDest = 0;
    iLightSrc = pOut->iLight;
    while(   (iLightSrc<HLA_SEG_MAX_NUM_LIGHTS)
          && (iLightDest<RTE_HLA_SEG_LIGHT_LIST_LENGTH)
         )
    {
      HLASegLightFillRteOutputSetLightData(iLightDest, &LightSrc[iLightSrc], &LightDest[iLightDest]);
      LightSrc[iLightSrc].LightID_RTE = iLightDest;
      LightIDTab_Dest2Src[iLightDest] = iLightSrc;
      iLightDest++;
      iLightSrc = LightSrc[iLightSrc].iLightNext;
    }
      
    /* 2. fill rte relevant lights */
    for(iLightSrc=0; iLightSrc<(pData->LightData.FunctRoi.nLights_Raw+pData->LightData.AboveRoi.nLights_Raw); iLightSrc++)
    {
      /* 1st filter stage let pass the light    */
      /* and 2nd filter stage rejects the light */
      /* -> new light for rte output            */
      if(    (LightSrc[iLightSrc].RejectedReason[0] == 0)
          && (LightSrc[iLightSrc].RejectedReason[1] > 0)
          && (iLightDest < RTE_HLA_SEG_LIGHT_LIST_LENGTH)
        )
      {
        HLASegLightFillRteOutputSetLightData(iLightDest, &LightSrc[iLightSrc], &LightDest[iLightDest]);
        LightSrc[iLightSrc].LightID_RTE = iLightDest;
        LightIDTab_Dest2Src[iLightDest] = iLightSrc;
        iLightDest++;
      }
    }

    /* set number of rte lights */
    ps_SegLightList->NumLights = iLightDest;

    /* fill region data */
    {
      RTE_HLA_Seg_Region_t *RegDest = &ps_SegLightList->Region[0];
      uint8 iRegDest = 0;
      uint8 RegIDTab_Src2Dest[HLA_SEG_MAX_NUM_REGIONS]; 

      memset(&RegIDTab_Src2Dest[0],  UI8_T_MAX, sizeof(uint8)*HLA_SEG_MAX_NUM_REGIONS);    
    
      /* fill regions from top to bottom */
      /* 1. all top regions              */
      for(iLightDest=0; iLightDest<ps_SegLightList->NumLights; iLightDest++)
      {
        HLASegLineRegion_t *pRegSrc = LightSrc[LightIDTab_Dest2Src[iLightDest]].pRegion;
        uint8 iRegSrc;

        if(pRegSrc)
        {
          /* uint8 is always >= 0 */
          iRegSrc = CML_Min((uint8)(HLA_SEG_MAX_NUM_REGIONS - 1u), (uint8)(pRegSrc - &pRegionBuffer->Region[0]));
        }
        else
        {
          iRegSrc = UI8_T_MAX;
        }

        if(    (iRegDest<RTE_HLA_SEG_REGION_LIST_LENGTH)
            && (iRegSrc<HLA_SEG_MAX_NUM_REGIONS)
          )
        {
          if(RegIDTab_Src2Dest[iRegSrc] >= HLA_SEG_MAX_NUM_REGIONS)
          {
            /* region not in rte output */
            HLASegLightFillRteOutputSetRegionData( pRegSrc,
                                                   &RegDest[iRegDest]
                                                 );
            LightDest[iLightDest].Region_Id = iRegDest;
            RegIDTab_Src2Dest[iRegSrc] = iRegDest;
            iRegDest++;
          }
          else
          {
            /* region was stored in rte output before */
            /* -> do not store region again           */
            /* save region id in light destination    */
            LightDest[iLightDest].Region_Id = RegIDTab_Src2Dest[iRegSrc];
          }
        }
      }

      /* fill regions from top to bottom */
      /* 2. all regions below top region */
      for(iLightDest=0; iLightDest<ps_SegLightList->NumLights; iLightDest++)
      {
        HLASegLineRegion_t *pRegSrc = LightSrc[LightIDTab_Dest2Src[iLightDest]].pRegion;
        uint8 iRegSrc;

        if(pRegSrc)
        {
          pRegSrc = pRegSrc->pRegionBelow;

          if(pRegSrc)
          {
            /* uint8 is always >= 0 */
            iRegSrc = CML_Min((uint8)(HLA_SEG_MAX_NUM_REGIONS-1u), (uint8)(pRegSrc - &pRegionBuffer->Region[0]));
          }
          else
          {
            iRegSrc = UI8_T_MAX;
          }
        }
        else
        {
          iRegSrc = UI8_T_MAX;
        } 

        if(    (iRegDest<RTE_HLA_SEG_REGION_LIST_LENGTH)
            && (iRegSrc<HLA_SEG_MAX_NUM_REGIONS)
            && (LightDest[iLightDest].Region_Id<RTE_HLA_SEG_REGION_LIST_LENGTH)
          )
        {
          if(RegIDTab_Src2Dest[iRegSrc] >= HLA_SEG_MAX_NUM_REGIONS)
          {
            /* region not in rte output */
            HLASegLightFillRteOutputSetRegionData( pRegSrc,
                                                   &RegDest[iRegDest]
                                                 );
            RegDest[LightDest[iLightDest].Region_Id].RegionBelow_Id = iRegDest;
            RegIDTab_Src2Dest[iRegSrc] = iRegDest;
            iRegDest++;
          }
          else
          {
            /* region was stored in rte output before */
            /* -> do not store region again           */
            /* save region id in RegionBelow_Id destination */
            RegDest[LightDest[iLightDest].Region_Id].RegionBelow_Id = RegIDTab_Src2Dest[iRegSrc];
          }
        }
      }
  
      /* fill regions from top to bottom */
      /* 3. all other below regions until rte region output buffer is full */
      for(iLightDest=0; iLightDest<ps_SegLightList->NumLights; iLightDest++)
      {
        HLASegLineRegion_t *pRegSrc = LightSrc[LightIDTab_Dest2Src[iLightDest]].pRegion;
        uint8 iRegSrc;
        uint8 iRegDestUpper;     
      
        if(pRegSrc)
        {
          iRegSrc = (uint8)(pRegSrc - &pRegionBuffer->Region[0]);
          pRegSrc = pRegSrc->pRegionBelow;        

          while(   pRegSrc 
                && (iRegDest<RTE_HLA_SEG_REGION_LIST_LENGTH)
               )
          {
            iRegDestUpper = RegIDTab_Src2Dest[iRegSrc];
            iRegSrc = (uint8)(pRegSrc - &pRegionBuffer->Region[0]);

            if(iRegSrc<HLA_SEG_MAX_NUM_REGIONS)
            {
              if(RegIDTab_Src2Dest[iRegSrc] >= HLA_SEG_MAX_NUM_REGIONS)
              {
                /* region not in rte output */
                HLASegLightFillRteOutputSetRegionData( pRegSrc,
                                                       &RegDest[iRegDest]
                                                      );
                RegDest[iRegDestUpper].RegionBelow_Id = iRegDest;
                RegIDTab_Src2Dest[iRegSrc] = iRegDest;
                iRegDest++;
              }
              else
              {
                /* region was stored in rte output before */
                /* -> do not store region again           */
                /* save region id in RegionBelow_Id destination */
                RegDest[iRegDestUpper].RegionBelow_Id = RegIDTab_Src2Dest[iRegSrc];
              }
            }
            pRegSrc = pRegSrc->pRegionBelow;
          }
        }
      }
    }

    /* fill SegRoi */
    ps_SegLightList->SegRoi.X1 = pCamData->RoiX1;
    ps_SegLightList->SegRoi.Y1 = pCamData->RoiY1;
    ps_SegLightList->SegRoi.X2 = pCamData->RoiX2;
    ps_SegLightList->SegRoi.Y2 = pCamData->RoiY2;  

    /* fill SegLevel */
    {
      uint8 i;
      for(i=0;i<=HLA_SEG_LEVEL_LIGHT;i++)
      {
        ps_SegLightList->SegLevel.Level_lux[i] = pData->BinarizeImgData.Threshold.Lux.Level[i];
      }
    }

    /* set version number */
    ps_SegLightList->VersionNumber = RTE_HLA_SEG_LIGHTLIST_INTFVER;
    
    /* set header data */
    ps_SegLightList->Header.eSigStatus = AL_SIG_STATE_OK;
    ps_SegLightList->Header.uiCycleCounter = pData->HLAS_Cnt;
    ps_SegLightList->Header.uiMeasurementCounter = pData->FrameCnt;
    ps_SegLightList->Header.uiTimeStamp = pData->TimeStamp_Image_us;
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightFillRteOutputSetLightData
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightFillRteOutputSetLightData( const uint8                LightID,
                                                  const HLASegLight_t*       pSrc,
                                                        RTE_HLA_Seg_Light_t* pDest
                                                )
{
  pDest->Light_Id = LightID;
  /* Region_Id will set in HLASegLightFillRteOutputSetRegiontData() */
  pDest->MaxPos_x = pSrc->Maxima.x;
  pDest->MaxPos_y = pSrc->Maxima.y;
  pDest->R = pSrc->current_R;
  pDest->G = pSrc->current_G;
  pDest->B = pSrc->current_B;
  pDest->MaxInt = pSrc->MaxInt;

  /* RTE_HLA_Seg_LightStatus */
  pDest->Status = 0;
  if(    (pSrc->Status.isPotRed == 1) 
      || (pSrc->Status.isPotRed_dark == 1)
    )
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_POT_RED;
  }
  if(pSrc->Status.isPotLed)
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_POT_LED;
  }
  if(pSrc->Status.Sat_T1)
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_SATURATED_T1;
  }
  if(pSrc->Status.Sat)
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_SATURATED;
  }
  if(pSrc->Status.HotPixel)
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_HOT_PIXEL;
  }
  if(pSrc->Status.isOPLight)
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_POT_FAR_PAIR_LIGHT;
  }
  if(pSrc->Status.isIsolatedLight)
  {
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_ISOLATED;
  }
  if(pSrc->Status.DoNotStartNewTrack)
  {                                                                /* J.Häfer: Conversion doesn't matter */
    pDest->Status |= RTE_HLA_SEG_LIGHT_STA_DO_NOT_START_NEW_TRACK; /* PRQA S 3757 */
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightFillRteOutputSetRegionData
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightFillRteOutputSetRegionData( const HLASegLineRegion_t*   pSrc,
                                                         RTE_HLA_Seg_Region_t* pDest
                                                 )
{
  sint32 dx = (pSrc->x2 - pSrc->x1) + 2;
  sint32 dy = pSrc->y2 - pSrc->y1;
  float32 FillFactor = (2.0f * pSrc->ySum)/(dx*dy);


  pDest->Level = pSrc->Level;
  /* region below id will be set later */
  pDest->RegionBelow_Id = UI8_T_MAX;
  pDest->FillFactor = (uint8)CML_f_Min(100.0f, ((FillFactor*100.0f)+0.5f));
  pDest->Dummy = 0;
  pDest->x1 = pSrc->x1;
  pDest->y1 = pSrc->y1;
  pDest->x2 = pSrc->x2;
  pDest->y2 = pSrc->y2;
}

