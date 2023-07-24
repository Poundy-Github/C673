/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_seglightfilter.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_seglightfilter.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:38CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:22CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:55CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_seglightfilter.h" 

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
static void HLASegLightFilterReduction( const uint16                 MaxNumLights,
                                        const uint8                  iFilter,
                                              HLASegLightDataRoi_t*  pLightData,
                                              HLASegLightBuffer_t*   pLightBuffer                                        
                                      );

static void HLASegLightFilterPassRed( const uint16                 MaxNumLightsBottomUp,
                                      const uint16                 MaxNumLightsBottomUpPass,
                                      const uint16                 yImgMin,  /* 1. stage: bottom up passed light must be below this line */
                                                                             /* 2. stage: take all bottom up lights independent of y position in the image */
                                      const uint16                 MaxNumLightsHighestRedValue,
                                      const uint8                  iFilter,
                                            HLASegLightDataRoi_t*  pLightData,
                                            HLASegLightBuffer_t*   pLightBuffer
                                    );

static void HLASegLightFilterPassBrightBottomUp( const uint16                 MaxNumLightsBottomUp,
                                                 const uint16                 MaxNumLightsBottomUpPass,
                                                 const uint16                 yImgMin, /* 1. stage: bottom up passed light must be below this line */
                                                                                       /* 2. stage: take all bottom up lights independent of y position in the image */
                                                 const uint8                  iFilter,
                                                       HLASegLightDataRoi_t*  pLightData,
                                                       HLASegLightBuffer_t*   pLightBuffer                                                 
                                               );

static void HLASegLightFilterPassLedBottomUp( const uint16                 MaxNumLightsBottomUpPass,
                                              const uint16                 yImgMin, /* bottom up passed light must be below this line */
                                              const uint8                  iFilter,
                                                    HLASegLightDataRoi_t*  pLightData,
                                                    HLASegLightBuffer_t*   pLightBuffer
                                             );
    
/******************************************************************************
* FUNCTION DEFINITIONS
******************************************************************************/


/* ****************************************************************************
  Functionname:     HLASegLightFilter
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegLightFilter( const HLACameraData_t*                        pCamData,
                        const HLA_t_SegmentationParametersBrightness* pParBrightness,
                        const uint8                                   iFilter,			
                              HLASegData_t*                           pData,
                              HLASegLightBuffer_t*                    pLightBuffer
                      )
{
  uint16 MaxNumLights_FunctRoi;

  /* remove the darkest lights in City ROI (AboveROI) until we reaches MaxNumLights_AboveRoi */
  if(pData->LightData.AboveRoi.nLights[iFilter] > pParBrightness->MaxNumLights[iFilter].AboveRoi)
  {
    HLASegLightFilterReduction( pParBrightness->MaxNumLights[iFilter].AboveRoi,
                                iFilter,
                          &pData->LightData.AboveRoi,
                                pLightBuffer
                              );
  }
  MaxNumLights_FunctRoi = pParBrightness->MaxNumLights[iFilter].Roi - pData->LightData.AboveRoi.nLights[iFilter];


  /*     pass MaxNumLightsBottomUpRed pot. red lights from bottom up */
  /* and pass the pot. red lights lights with highest red value  */
  HLASegLightFilterPassRed( (uint16)((pParBrightness->MaxNumLights[iFilter].RedBottomUp*MaxNumLights_FunctRoi) + 0.5f),
                            (uint16)((pParBrightness->MaxNumLights[iFilter].RedBottomUpPass*MaxNumLights_FunctRoi) + 0.5f),
                            (uint16)(pCamData->FOE_y-pParBrightness->MaxNumLights[iFilter].RedBottomUp_dyFOE),
                            (uint16)((pParBrightness->MaxNumLights[iFilter].RedHighestRedValue*MaxNumLights_FunctRoi) + 0.5f),
                            iFilter,
                            &pData->LightData.FunctRoi_Red,
                            pLightBuffer 
                          );
  /* pass the bright lights from bottom up */
  HLASegLightFilterPassBrightBottomUp( (uint16)((pParBrightness->MaxNumLights[iFilter].BrightBottomUp*MaxNumLights_FunctRoi) + 0.5f),
                                       (uint16)((pParBrightness->MaxNumLights[iFilter].BrightBottomUpPass*MaxNumLights_FunctRoi) + 0.5f),
                                       (uint16)(pCamData->FOE_y-pParBrightness->MaxNumLights[iFilter].BrightBottomUp_dyFOE),
                                       iFilter,
                                       &pData->LightData.FunctRoi_Bright,
                                       pLightBuffer                                         
                                     );
  /* pass the bright lights from bottom up */
  HLASegLightFilterPassLedBottomUp( (uint16)((pParBrightness->MaxNumLights[iFilter].LedBottomUpPass*MaxNumLights_FunctRoi) + 0.5f),
                                    (uint16)(pCamData->FOE_y-pParBrightness->MaxNumLights[iFilter].LedBottomUp_dyFOE),
                                    iFilter,
                                    &pData->LightData.FunctRoi_Led,
                                    pLightBuffer
                                  );
  /* remove the darkest lights in Function ROI until we reaches MaxNumLightsNonRed (except the passed marked lights) */
  HLASegLightFilterReduction( MaxNumLights_FunctRoi,
                              iFilter,
                              &pData->LightData.FunctRoi,
                              pLightBuffer
                             );			    
}

/* ****************************************************************************
  Functionname:     HLASegLightFilterReduction
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightFilterReduction( const uint16                 MaxNumLights,
                                        const uint8                  iFilter,
                                              HLASegLightDataRoi_t*  pLightData,
                                              HLASegLightBuffer_t*   pLightBuffer                                        
                                      )
{
  HLASegLight_t* restrict Light = &(pLightBuffer->Light[0]);
  

  /* start light reduction ? */  
  if(pLightData->nLights[iFilter] > MaxNumLights)
  {
    /* remove the darkest lights */
    while(pLightData->nLights[iFilter] > MaxNumLights)
    {
      uint8 *piLight = &pLightData->iLight;
      uint8 *piLightDark = NULL;

      while(*piLight < HLA_SEG_MAX_NUM_LIGHTS)
      {
        if(Light[*piLight].PassedReason[iFilter] == 0)
        {
          if(piLightDark == NULL)
          {
            piLightDark = piLight;
          }
          else if(Light[*piLight].MaxInt < Light[*piLightDark].MaxInt)
          {
            piLightDark = piLight;
          }
        }
        piLight = &Light[*piLight].iLightNext;
      }

      /* remove dark light from light list */
      if(piLightDark)
      {
        /* remove dark light */
        Light[*piLightDark].RejectedReason[iFilter] |= HLA_SEG_LIGHT_RR_LIGHTREDUCTION;
        pLightData->nLights[iFilter]--;
             
        *piLightDark = Light[*piLightDark].iLightNext;
      }
      else
      {
        break;
      }
    }
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightFilterPassRed
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightFilterPassRed( const uint16                 MaxNumLightsBottomUp,
                                      const uint16                 MaxNumLightsBottomUpPass,
                                      const uint16                 yImgMin,  /* 1. stage: bottom up passed light must be below this line */
                                                                             /* 2. stage: take all bottom up lights independent of y position in the image */
                                      const uint16                 MaxNumLightsHighestRedValue,
                                      const uint8                  iFilter,
                                            HLASegLightDataRoi_t*  pLightData,
                                            HLASegLightBuffer_t*   pLightBuffer
                                    )
{
  HLASegLight_t *Light      = &(pLightBuffer->Light[0]);
  uint16 MaxNumLightsPassed = MaxNumLightsBottomUpPass + MaxNumLightsHighestRedValue;
  uint8 nLights_Passed = 0;


  /* start pot. red light reduction ? */
  if(pLightData->nLights[iFilter] > MaxNumLightsPassed)
  {
    /* let pass MaxNumLightsBottomUpPass from MaxNumLightsBottomUp Lights */
    /* with the highest red value                                         */
    /* which are below yImgMax                                            */
    while(nLights_Passed < MaxNumLightsBottomUpPass)
    {
      uint8 iLight = pLightData->iLight;
      uint8 i = 0;
      uint8 iLightPassed = HLA_SEG_MAX_NUM_LIGHTS;


      /* find the light with highest red value */
      while(    (iLight < HLA_SEG_MAX_NUM_LIGHTS)
             && (i < MaxNumLightsBottomUp)
        )
      {
        if(    (Light[iLight].PassedReason[iFilter] == 0)
            && (Light[iLight].ycenter > yImgMin)
          )
        {
          if(iLightPassed == HLA_SEG_MAX_NUM_LIGHTS)
          {
            iLightPassed = iLight;
          }
          else if((Light[iLight].current_R*Light[iLight].MaxInt) > (Light[iLightPassed].current_R*Light[iLightPassed].MaxInt))
          {
            iLightPassed = iLight;
          }
        }
        i++;
        iLight = Light[iLight].iLightNext_sub;
      }

      /* do not remove this bottom up light */
      if(iLightPassed < HLA_SEG_MAX_NUM_LIGHTS)
      {
        Light[iLightPassed].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_RED_BOTTOMUP;
        nLights_Passed++;
      }
      else
      {
        /* break while because no light fulfills the criteria anymore */
        break;
      }
    }
    

    /* let pass MaxNumLightsBottomUpPass from MaxNumLightsBottomUp Lights */
    /* with the highest red value                                         */
    /* independent of the y position in the image                         */
    while(nLights_Passed < MaxNumLightsBottomUpPass)
    {
      uint8 iLight = pLightData->iLight;
      uint8 i = 0;
      uint8 iLightPassed = HLA_SEG_MAX_NUM_LIGHTS;


      /* find the light with highest red value */
      while(    (iLight < HLA_SEG_MAX_NUM_LIGHTS)
             && (i < MaxNumLightsBottomUp)
           )
      {
        if(Light[iLight].PassedReason[iFilter] == 0)
        {
          if(iLightPassed == HLA_SEG_MAX_NUM_LIGHTS)
          {
            iLightPassed = iLight;
          }
          else if((Light[iLight].current_R*Light[iLight].MaxInt) > (Light[iLightPassed].current_R*Light[iLightPassed].MaxInt))
          {
            iLightPassed = iLight;
          }
        }
        i++;
        iLight = Light[iLight].iLightNext_sub;
      }

      /* do not remove this bottom up light */
      if(iLightPassed < HLA_SEG_MAX_NUM_LIGHTS)
      {
        Light[iLightPassed].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_RED_BOTTOMUP;
        nLights_Passed++;
      }
      else
      {
        /* break while because no light fulfills the criteria anymore */
        break;
      }
    }
      

    /* let pass the pot. red lights with the highest red value */
    while(nLights_Passed < MaxNumLightsPassed)
    {
      uint8 iLight = pLightData->iLight;
      uint8 iLightPassed = HLA_SEG_MAX_NUM_LIGHTS;

      /* find the light with highest red value */
      while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
      {
        if(Light[iLight].PassedReason[iFilter] == 0)
        {
          if(iLightPassed == HLA_SEG_MAX_NUM_LIGHTS)
          {
            iLightPassed = iLight;
          }
          else if((Light[iLight].current_R*Light[iLight].MaxInt) > (Light[iLightPassed].current_R*Light[iLightPassed].MaxInt))
          {
            iLightPassed = iLight;
          }
        }
        iLight = Light[iLight].iLightNext_sub;
      }
              
      /* do not remove this red light */
      if(iLightPassed < HLA_SEG_MAX_NUM_LIGHTS)
      {
        Light[iLightPassed].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_RED_HIGHVALUE;
        nLights_Passed++;
      }
      else
      {
        /* break while because no light fulfills the criteria anymore */
        break;
      }
    }
  }
  else
  {
    /* reduction of red lights is not necessary  */
    /* -> set passed for all pot. red lights     */
    uint8 iLight = pLightData->iLight;
  
    while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
    {
      Light[iLight].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_RED_BOTTOMUP;
      iLight = Light[iLight].iLightNext_sub;
    }
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightFilterPassBrightBottomUp
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightFilterPassBrightBottomUp( const uint16                 MaxNumLightsBottomUp,
                                                 const uint16                 MaxNumLightsBottomUpPass,
                                                 const uint16                 yImgMin, /* 1. stage: bottom up passed light must be below this line */
                                                                                       /* 2. stage: take all bottom up lights independent of y position in the image */
                                                 const uint8                  iFilter,
                                                       HLASegLightDataRoi_t*  pLightData,
                                                       HLASegLightBuffer_t*   pLightBuffer                                                 
                                               )
{
  HLASegLight_t* Light = &(pLightBuffer->Light[0]);
    

  if(pLightData->nLights[iFilter] > MaxNumLightsBottomUpPass)
  {
    uint8 nLights_Passed = 0;
   

    /* let pass MaxNumLightsBottomUpPass from MaxNumLightsBottomUp Lights */
    /* with the highest intensity                                         */
    /* and below yImgMin                                                  */
    while(nLights_Passed < MaxNumLightsBottomUpPass)
    {
      uint8 iLight = pLightData->iLight;
      uint8 i = 0;
      uint8 iLightPassed = HLA_SEG_MAX_NUM_LIGHTS;


      /* find the light with highest intensity */
      while(    (iLight < HLA_SEG_MAX_NUM_LIGHTS)
             && (i < MaxNumLightsBottomUp)
           )
      {
        if(    (Light[iLight].PassedReason[iFilter] == 0)
            && (Light[iLight].ycenter > yImgMin)
          )
        {
          if(iLightPassed == HLA_SEG_MAX_NUM_LIGHTS)
          {
            iLightPassed = iLight;
          }
          else if(Light[iLight].MaxInt > Light[iLightPassed].MaxInt)
          {
            iLightPassed = iLight;
          }
        }
        i++;
        iLight = Light[iLight].iLightNext_sub;
      }

      /* do not remove this bottom up light */
      if(iLightPassed < HLA_SEG_MAX_NUM_LIGHTS)
      {
        Light[iLightPassed].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_BRIGHT_BOTTOMUP;
        nLights_Passed++;
      }
      else
      {
        /* break while because no light fulfills the criteria anymore */
        break;
      }
    }


    /* let pass MaxNumLightsBottomUpPass from MaxNumLightsBottomUp Lights */
    /* with the highest intensity                                         */
    /* independent of y position in the image                             */
    while(nLights_Passed < MaxNumLightsBottomUpPass)
    {
      uint8 iLight = pLightData->iLight;
      uint8 i = 0;
      uint8 iLightPassed = HLA_SEG_MAX_NUM_LIGHTS;


      /* find the light with highest intensity */
      while(    (iLight < HLA_SEG_MAX_NUM_LIGHTS)
        && (i < MaxNumLightsBottomUp)
        )
      {
        if(Light[iLight].PassedReason[iFilter] == 0)
        {
          if(iLightPassed == HLA_SEG_MAX_NUM_LIGHTS)
          {
            iLightPassed = iLight;
          }
          else if(Light[iLight].MaxInt > Light[iLightPassed].MaxInt)
          {
            iLightPassed = iLight;
          }
        }
        i++;
        iLight = Light[iLight].iLightNext_sub;
      }

      /* do not remove this bottom up light */
      if(iLightPassed < HLA_SEG_MAX_NUM_LIGHTS)
      {
        Light[iLightPassed].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_BRIGHT_BOTTOMUP;
        nLights_Passed++;
      }
      else
      {
        /* break while because no light fulfills the criteria anymore */
        break;
      }
    }
  }
  else
  {
    /* reduction of bright lights is not necessary */
    /* -> set passed for all bright lights         */
    uint8 iLight = pLightData->iLight;

    while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
    {
      Light[iLight].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_BRIGHT_BOTTOMUP;
      iLight = Light[iLight].iLightNext_sub;
    }
  }
}

/* ****************************************************************************
  Functionname:     HLASegLightFilterPassLedBottomUp
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegLightFilterPassLedBottomUp( const uint16                 MaxNumLightsBottomUpPass,
                                              const uint16                 yImgMin, /* bottom up passed light must be below this line */
                                              const uint8                  iFilter,
                                                    HLASegLightDataRoi_t*  pLightData,
                                                    HLASegLightBuffer_t*   pLightBuffer
                                             )                                             
{
  HLASegLight_t* Light = &(pLightBuffer->Light[0]);
  uint8 i= 0;
  uint8 iLight = pLightData->iLight;

      
  while(     (iLight < HLA_SEG_MAX_NUM_LIGHTS)
          && (i < MaxNumLightsBottomUpPass)
        )
  {
    if(Light[iLight].ycenter > yImgMin)
    {
      /* do not remove this bottom up light */
      Light[iLight].PassedReason[iFilter] |= HLA_SEG_LIGHT_PR_LED_BOOTOMUP;
      i++;
      iLight = Light[iLight].iLightNext_sub;
    }
  }
}
