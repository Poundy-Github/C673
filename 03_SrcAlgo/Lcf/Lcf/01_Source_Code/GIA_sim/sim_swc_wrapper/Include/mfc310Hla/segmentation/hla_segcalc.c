/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segcalc.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segcalc.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:36CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:18CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:53CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_segcalc.h" 

/*****************************************************************************
  DEFINITIONS
*****************************************************************************/


static void HLASegCalcLuxIntensityMaxima(HLASegMaxima_t* restrict pMax);

static uint16 HLASegCalcRGB_CalcLuminance( const uint16* pc, 
                                           const uint16  xImgWidth, 
                                           const uint16  BL
                                         );
                          
static void HLASegCalcRGB_GradientBasedInterp_Light(HLASegLight_t* pLight);

static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel1( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        );

#if 0
static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel2( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        );

static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel3( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        );

static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel4( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        );

static void HLASegCalcRGB_HighQualityLinInterp_Pixel( const uint16* pPix,
                                                      const uint16  xPix, 
                                                      const uint16  yPix,
                                                      const uint16  xImgWidth,
                                                      const uint16  BL, 
                                                            uint16* pR, 
                                                            uint16* pG,
                                                            uint16* pB
                                                    );
#endif


/* ****************************************************************************
  Functionname:     HLASegCalcLuxIntensity (static)
  Description:      converts maxima from 12Bit not linear greyvalue to lux intensity

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegCalcLuxIntensity( HLASegLightDataRoi_t* pLightData,
                             HLASegLightBuffer_t*  pLightBuffer
                           )
{
  uint16 iLight = pLightData->iLight;
  HLASegLight_t* pLight;

  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    pLight = &(pLightBuffer->Light[iLight]);

    /* calculate lux intensity for one light/ maxima */
    HLASegCalcLuxIntensityMaxima(&pLight->Maxima);

    iLight = pLight->iLightNext;
  }
}


/* ****************************************************************************
  Functionname:     HLASegCalcRGB_GradientBasedInterp
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegCalcRGB_GradientBasedInterp( const uint8                iLBStart,
                                              HLASegLightBuffer_t* pLightBuffer
                                       )
{ 
  uint8           iLB;
  HLASegLight_t   *Light = &(pLightBuffer->Light[0]);

  iLB = iLBStart;
  while(iLB < HLA_SEG_MAX_NUM_LIGHTS)
  {
    HLASegCalcRGB_GradientBasedInterp_Light(&Light[iLB]);
    
    iLB = Light[iLB].iLightNext;
  }
}


/* ****************************************************************************
  Functionname:     HLASegCalcRGB_GradientBasedInterp_Pixel
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegCalcRGB_GradientBasedInterp_Pixel( const uint16* pPix,
                                              const uint16  xPix, 
                                              const uint16  yPix,
                                              const uint16  xImgWidth,
                                              const uint16  BL, 
                                                    uint16* pR, 
                                                    uint16* pG,
                                                    uint16* pB
                                             )
{
  
  uint16 L1, L3, L7, L9;
  uint16 L2, L4, L6, L8;
  sint32 D1, D3, D7, D9;
  sint32 D2, D4, D6, D8;
  const uint16 *p1, *p3, *p7, *p9;
  const uint16 *p2, *p4, *p6, *p8;

  const boolean isXPixOdd = (boolean)(xPix & 0x1);
  const boolean isYPixOdd = (boolean)(yPix & 0x1);

 if (isXPixOdd == b_TRUE)
  {
    if (isYPixOdd == b_TRUE)
    {
      /* green in B row, R column */
      /*   G1   R2  G3 */
      /*   B4   G5  B6 */
      /*   G7   R8  G9 */

      *pG = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, (sint16)(*pPix - BL));

      /* calc. red pixel value at G5   */   
      /* calc. Luminance for R2 and R8 */
      p2 = (pPix - xImgWidth);
      p8 = (pPix + xImgWidth);
      L2 = HLASegCalcRGB_CalcLuminance(p2, xImgWidth, BL);
      L8 = HLASegCalcRGB_CalcLuminance(p8, xImgWidth, BL);
      D2 = *p2 - L2;
      D8 = *p8 - L8;
      /* uint16 is always >= 0 */
      /* true, but in D2 and D8 a buffer overflow can occur -> changed to sint32 and reintroduced MinMax */
      *pR = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, ((sint32)*pG + ((D2 + D8 + 1) >> 1)));

      /* calc. blue pixel value at G5  */
      /* calc. Luminance for B4 and B6 */
      p4 = pPix - 1;
      p6 = pPix + 1;
      L4 = HLASegCalcRGB_CalcLuminance(p4, xImgWidth, BL);
      L6 = HLASegCalcRGB_CalcLuminance(p6, xImgWidth, BL);
      D4 = *p4 - L4;
      D6 = *p6 - L6;
      /* uint16 is always >= 0 */
      /* true, but in D4 and D6 a buffer overflow can occur -> changed to sint32 and reintroduced MinMax */
      *pB = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, ((sint32)*pG + ((D4 + D6 + 1) >> 1)));
    }
    else /* (isXPixOdd == b_TRUE) && (isYPixOdd == b_FALSE) */
    {
      /* at red pixel */
      /*   B1   G2  B3 */
      /*   G4   R5  G6 */
      /*   B7   G8  B9 */

      *pR = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, (sint32)(*pPix - BL));
      //*pG = HLASegCalcRGB_CalcLuminance(pPix, xImgWidth, BL);
      *pG = HLASegCalcRGB_HighQualityLinInterp_Kernel1(pPix, xImgWidth, BL);

      /* calc. blue pixel value at R5          */
      /* calc. Luminance for B1, B3, B7 and B9 */
      p1 = ((pPix - xImgWidth) - 1);
      p3 = ((pPix - xImgWidth) + 1);
      p7 = ((pPix + xImgWidth) - 1);
      p9 = ((pPix + xImgWidth) + 1);
      L1 = HLASegCalcRGB_CalcLuminance(p1, xImgWidth, BL);
      L3 = HLASegCalcRGB_CalcLuminance(p3, xImgWidth, BL);
      L7 = HLASegCalcRGB_CalcLuminance(p7, xImgWidth, BL);
      L9 = HLASegCalcRGB_CalcLuminance(p9, xImgWidth, BL);
      D1 = *p1 - L1;
      D3 = *p3 - L3;
      D7 = *p7 - L7;
      D9 = *p9 - L9;
      /* uint16 is always >= 0 */
      /* true, but in D1, D3, D7 and D9 a buffer overflow can occur -> changed to sint32 and reintroduced MinMax */
      *pB = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, ((sint32)*pG + ((D1 + D3 + D7 + D9 + 1) >> 2)));
    }
  }
  else /* (isXPixOdd == b_FALSE) */
  {
    if (isYPixOdd == b_TRUE) 
    {
      /* blue in B row, B column */
      /*   R1   G2  R3 */
      /*   G4   B5  G6 */
      /*   R7   G8  R9 */

      *pB = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, (sint16)(*pPix - BL));
      //*pG = HLASegCalcRGB_CalcLuminance(pPix, xImgWidth, BL);
      *pG = HLASegCalcRGB_HighQualityLinInterp_Kernel1(pPix, xImgWidth, BL);

      /* calc. red pixel value at B5           */
      /* calc. Luminance for R1, R3, R7 and R9 */
      p1 = ((pPix - xImgWidth) - 1);
      p3 = ((pPix - xImgWidth) + 1);
      p7 = ((pPix + xImgWidth) - 1);
      p9 = ((pPix + xImgWidth) + 1);
      L1 = HLASegCalcRGB_CalcLuminance(p1, xImgWidth, BL);
      L3 = HLASegCalcRGB_CalcLuminance(p3, xImgWidth, BL);
      L7 = HLASegCalcRGB_CalcLuminance(p7, xImgWidth, BL);
      L9 = HLASegCalcRGB_CalcLuminance(p9, xImgWidth, BL);
      D1 = *p1 - L1;
      D3 = *p3 - L3;
      D7 = *p7 - L7;
      D9 = *p9 - L9;

      /* uint16 is always >= 0 */
      /* true, but in D1, D3, D7 and D9 a buffer overflow can occur -> changed to sint32 and reintroduced MinMax */
      *pR = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, ((sint32)*pG + ((D1 + D3 + D7 + D9 + 1) >> 2)));
    }
    else /* (isXPixOdd == b_FALSE) && (isYPixOdd == b_FALSE) */
    {
      /* green in R row, B column */
      /*   G1   B2  G3 */
      /*   R4   G5  R6 */
      /*   G7   B8  G9 */ 

      *pG = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, (sint16)(*pPix - BL));

      /* calc. blue pixel value at G5  */   
      /* calc. Luminance for B2 and B8 */
      p2 = (pPix - xImgWidth);
      p8 = (pPix + xImgWidth);
      L2 = HLASegCalcRGB_CalcLuminance(p2, xImgWidth, BL);
      L8 = HLASegCalcRGB_CalcLuminance(p8, xImgWidth, BL);
      D2 = *p2 - L2;
      D8 = *p8 - L8;
      /* uint16 is always >= 0 */
      /* true, but in D2 and D8 a buffer overflow can occur -> changed to sint32 and reintroduced MinMax */
      *pB = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, ((sint32)*pG + ((D2 + D8 + 1) >> 1)));

      /* calc. red pixel value at G5   */
      /* calc. Luminance for R4 and R6 */
      p4 = pPix - 1;
      p6 = pPix + 1;
      L4 = HLASegCalcRGB_CalcLuminance(p4, xImgWidth, BL);
      L6 = HLASegCalcRGB_CalcLuminance(p6, xImgWidth, BL);
      D4 = *p4 - L4;
      D6 = *p6 - L6;
      /* uint16 is always >= 0 */
      /* true, but in D4 and D6 a buffer overflow can occur -> changed to sint32 and reintroduced MinMax */
      *pR = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, ((sint32)*pG + ((D4 + D6 + 1) >> 1)));
    }
  }
}


/* ****************************************************************************
  Functionname:     HLASegCalcLuxIntensityMaxima
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegCalcLuxIntensityMaxima(HLASegMaxima_t* restrict pMax)
{
  /* calculate lux intensity */
  uint32 ir = 0; /* red row */
  uint32 ib = 0; /* green row */
  uint32 iy;
  uint32 i = 0;

#ifdef _TMS320C6X

  t_PixelData pix0, pix1, pix2, pix3;
  boolean pix0BelowKneepoint1, pix0BelowKneepoint2, pix0BelowSaturation, pix0AboveSaturation;
  boolean pix1BelowKneepoint1, pix1BelowKneepoint2, pix1BelowSaturation, pix1AboveSaturation;
  boolean pix2BelowKneepoint1, pix2BelowKneepoint2, pix2BelowSaturation, pix2AboveSaturation;
  boolean pix3BelowKneepoint1, pix3BelowKneepoint2, pix3BelowSaturation, pix3AboveSaturation;
  uint16 pix0LuxKneepoint1, pix0LuxKneepoint2, pix0LuxSaturation;
  uint16 pix1LuxKneepoint1, pix1LuxKneepoint2, pix1LuxSaturation;
  uint16 pix2LuxKneepoint1, pix2LuxKneepoint2, pix2LuxSaturation;
  uint16 pix3LuxKneepoint1, pix3LuxKneepoint2, pix3LuxSaturation;

  #pragma MUST_ITERATE(HLA_SEG_MAX_NUM_NGB_XY/2, HLA_SEG_MAX_NUM_NGB_XY/2, HLA_SEG_MAX_NUM_NGB_XY/2)
  for(iy = 0; iy < HLA_SEG_MAX_NUM_NGB_XY; iy +=2u)
  {
    /* red row */
    #pragma MUST_ITERATE(HLA_SEG_MAX_NUM_NGB_XY/2, HLA_SEG_MAX_NUM_NGB_XY/2, HLA_SEG_MAX_NUM_NGB_XY/2)
    for(ir = 0; ir < HLA_SEG_MAX_NUM_NGB_XY; ir += 2u)
    {
      pix0 = pMax->ngb[i].raw;
      pix1 = pMax->ngb[i + 1u].raw;

      /* Check whether pix0..pix1 are between black level and kneepoint1 */
      pix0BelowKneepoint1 = (boolean)((pix0 < hlaImagerPar.ui16Kneepoint1_Greyvalue) & (pix0 >= hlaImagerPar.ui16Blacklevel_G_Greyvalue));
      pix1BelowKneepoint1 = (boolean)((pix1 < hlaImagerPar.ui16Kneepoint1_Greyvalue) & (pix1 >= hlaImagerPar.ui16Blacklevel_R_Greyvalue));

      /* Check whether pix0..pix1 are between kneepoint1 and kneepoint2 */
      pix0BelowKneepoint2 = (boolean)((pix0 < hlaImagerPar.ui16Kneepoint2_Greyvalue) & (pix0 >= hlaImagerPar.ui16Kneepoint1_Greyvalue));
      pix1BelowKneepoint2 = (boolean)((pix1 < hlaImagerPar.ui16Kneepoint2_Greyvalue) & (pix1 >= hlaImagerPar.ui16Kneepoint1_Greyvalue));

      /* Check whether pix0..pix1 are between kneepoint2 and saturation */
      pix0BelowSaturation = (boolean)((pix0 < hlaImagerPar.ui16_Sat_Green) & (pix0 >= hlaImagerPar.ui16Kneepoint2_Greyvalue));
      pix1BelowSaturation = (boolean)((pix1 < hlaImagerPar.ui16_Sat_Red) & (pix1 >= hlaImagerPar.ui16Kneepoint2_Greyvalue));

      /* Check whether pix0..pix1 are above saturation */
      pix0AboveSaturation = (boolean)((pix0 >= hlaImagerPar.ui16_Sat_Green));
      pix1AboveSaturation = (boolean)((pix1 >= hlaImagerPar.ui16_Sat_Red));

      /* rounding -> 65536u/2u = 32768u */
      /* Calculate lux value if below kneepoint 1 */
      pix0LuxKneepoint1 = (uint16)((((pix0 - hlaImagerPar.ui16Blacklevel_G_Greyvalue) * hlaImagerPar.ui32Lux2G1) + 32768u) >> 16);
      pix1LuxKneepoint1 = (uint16)((((pix1 - hlaImagerPar.ui16Blacklevel_R_Greyvalue) * hlaImagerPar.ui32Lux2R1) + 32768u) >> 16);

      /* Calculate lux value if below kneepoint 2 */
      pix0LuxKneepoint2 = (uint16)((((pix0 - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2G2) + hlaImagerPar.ui32_Kneepoint1_G_Lux) >> 16);
      pix1LuxKneepoint2 = (uint16)((((pix1 - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2R2) + hlaImagerPar.ui32_Kneepoint1_R_Lux) >> 16);

      /* Calculate lux value if below saturation */
      pix0LuxSaturation = (uint16)((((pix0 - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2G3) + hlaImagerPar.ui32_Kneepoint2_G_Lux) >> 16);
      pix1LuxSaturation = (uint16)((((pix1 - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2R3) + hlaImagerPar.ui32_Kneepoint2_R_Lux) >> 16);

      pMax->ngb[i].lux = (   (pix0BelowKneepoint1 * pix0LuxKneepoint1)
                           + (pix0BelowKneepoint2 * pix0LuxKneepoint2)
                           + (pix0BelowSaturation * pix0LuxSaturation)
                           + (pix0AboveSaturation * hlaImagerPar.ui16_Sat_GreenLux)
                         );
      pMax->ngb[i + 1u].lux = (   (pix1BelowKneepoint1 * pix1LuxKneepoint1)
                                + (pix1BelowKneepoint2 * pix1LuxKneepoint2)
                                + (pix1BelowSaturation * pix1LuxSaturation)
                                + (pix1AboveSaturation * hlaImagerPar.ui16_Sat_RedLux)
                              );
      i += 2u;
    }
    /* blue row */
    #pragma MUST_ITERATE(HLA_SEG_MAX_NUM_NGB_XY/2, HLA_SEG_MAX_NUM_NGB_XY/2, HLA_SEG_MAX_NUM_NGB_XY/2)
    for(ib = 0; ib < HLA_SEG_MAX_NUM_NGB_XY; ib += 2u)
    {
      pix2 = pMax->ngb[i].raw;
      pix3 = pMax->ngb[i + 1u].raw;

      /* Check whether pix2..pix3 are between black level and kneepoint1 */
      pix2BelowKneepoint1 = (boolean)((pix2 < hlaImagerPar.ui16Kneepoint1_Greyvalue) & (pix2 >= hlaImagerPar.ui16Blacklevel_B_Greyvalue));
      pix3BelowKneepoint1 = (boolean)((pix3 < hlaImagerPar.ui16Kneepoint1_Greyvalue) & (pix3 >= hlaImagerPar.ui16Blacklevel_G_Greyvalue));

      /* Check whether pix2..pix3 are between kneepoint1 and kneepoint2 */
      pix2BelowKneepoint2 = (boolean)((pix2 < hlaImagerPar.ui16Kneepoint2_Greyvalue) & (pix2 >= hlaImagerPar.ui16Kneepoint1_Greyvalue));
      pix3BelowKneepoint2 = (boolean)((pix3 < hlaImagerPar.ui16Kneepoint2_Greyvalue) & (pix3 >= hlaImagerPar.ui16Kneepoint1_Greyvalue));

      /* Check whether pix2..pix3 are between kneepoint2 and saturation */
      pix2BelowSaturation = (boolean)((pix2 < hlaImagerPar.ui16_Sat_Blue) & (pix2 >= hlaImagerPar.ui16Kneepoint2_Greyvalue));
      pix3BelowSaturation = (boolean)((pix3 < hlaImagerPar.ui16_Sat_Green) & (pix3 >= hlaImagerPar.ui16Kneepoint2_Greyvalue));

      /* Check whether pix2..pix3 are above saturation */
      pix2AboveSaturation = (boolean)((pix2 >= hlaImagerPar.ui16_Sat_Blue));
      pix3AboveSaturation = (boolean)((pix3 >= hlaImagerPar.ui16_Sat_Green));

      /* rounding -> 65536u/2u = 32768u */
      /* Calculate lux value if below kneepoint 1 */
      pix2LuxKneepoint1 = (uint16)((((pix2 - hlaImagerPar.ui16Blacklevel_B_Greyvalue) * hlaImagerPar.ui32Lux2B1) + 32768u) >> 16);
      pix3LuxKneepoint1 = (uint16)((((pix3 - hlaImagerPar.ui16Blacklevel_G_Greyvalue) * hlaImagerPar.ui32Lux2G1) + 32768u) >> 16);

      /* Calculate lux value if below kneepoint 2 */
      pix2LuxKneepoint2 = (uint16)((((pix2 - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2B2) + hlaImagerPar.ui32_Kneepoint1_B_Lux) >> 16);
      pix3LuxKneepoint2 = (uint16)((((pix3 - hlaImagerPar.ui16Kneepoint1_Greyvalue) * hlaImagerPar.ui32Lux2G2) + hlaImagerPar.ui32_Kneepoint1_G_Lux) >> 16);

      /* Calculate lux value if below saturation */
      pix2LuxSaturation = (uint16)((((pix2 - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2B3) + hlaImagerPar.ui32_Kneepoint2_B_Lux) >> 16);
      pix3LuxSaturation = (uint16)((((pix3 - hlaImagerPar.ui16Kneepoint2_Greyvalue) * hlaImagerPar.ui32Lux2G3) + hlaImagerPar.ui32_Kneepoint2_G_Lux) >> 16);

      pMax->ngb[i].lux = (   (pix2BelowKneepoint1 * pix2LuxKneepoint1)
                           + (pix2BelowKneepoint2 * pix2LuxKneepoint2)
                           + (pix2BelowSaturation * pix2LuxSaturation)
                           + (pix2AboveSaturation * hlaImagerPar.ui16_Sat_BlueLux)
                         );
      pMax->ngb[i + 1u].lux = (   (pix3BelowKneepoint1 * pix3LuxKneepoint1)
                                + (pix3BelowKneepoint2 * pix3LuxKneepoint2)
                                + (pix3BelowSaturation * pix3LuxSaturation)
                                + (pix3AboveSaturation * hlaImagerPar.ui16_Sat_GreenLux)
                              );

      i += 2u;
    }
  }
#else
  for(iy = 0; iy < HLA_SEG_MAX_NUM_NGB_XY; iy +=2)
  {
    /* red row */
    for(ir = 0; ir < HLA_SEG_MAX_NUM_NGB_XY; ir += 2)
    {
      pMax->ngb[i].lux = HLAImager_GetIntLux_Green(pMax->ngb[i].raw); /* G-Pixel */
      i++;
      pMax->ngb[i].lux = HLAImager_GetIntLux_Red(pMax->ngb[i].raw);   /* R-Pixel */
      i++;
    }
    /* blue row */
    for(ib = 0; ib < HLA_SEG_MAX_NUM_NGB_XY; ib += 2)
    {
      pMax->ngb[i].lux = HLAImager_GetIntLux_Blue(pMax->ngb[i].raw); /* B-Pixel */
      i++;
      pMax->ngb[i].lux = HLAImager_GetIntLux_Green(pMax->ngb[i].raw);   /* G-Pixel */
      i++;
    }
  }
#endif
}


/* ****************************************************************************
  Functionname:     HLASegCalcRGB_GradientBasedInterp_Light
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegCalcRGB_GradientBasedInterp_Light(HLASegLight_t* pLight)
{
  uint16          r,g,b, rgb_max;
  float32         rgb_sum;
  float32         rgb_factor;
  uint8           r8,g8,b8;
 
  uint16 i_ngb = pLight->Maxima.i_ngb;


  HLASegCalcRGB_GradientBasedInterp_Pixel( (uint16*)&pLight->Maxima.ngb[i_ngb], 
                                           pLight->Maxima.x, 
                                           pLight->Maxima.y,
                                           HLA_SEG_MAX_NUM_NGB_XY,
                                           0u, /* Blacklevel */
                                           &r, 
                                           &g, 
                                           &b
                                         );

  /* calc. 8bit rgb values                        */
  /* Trichromatic coordinates                     */
  /* r + g + b = 1                                */
  /* with 8 bit values and a resolution of 1/255  */
  /* we get:                                      */
  /* r + g + b = 255                              */
  rgb_max    = CML_Max(CML_Max(r,g),b);
  rgb_sum    = CML_f_Max(0.01f, (float32)(r + g + b));
  rgb_factor = (float32)UI8_T_MAX/rgb_sum;

  r8        = (uint8)CML_u_Round2Uint((float32)r * rgb_factor);
  g8        = (uint8)CML_u_Round2Uint((float32)g * rgb_factor);
  b8        = (UI8_T_MAX - r8) - g8;

  /* uint16 is always >= 0 */
  pLight->MaxInt = CML_Min(UI16_T_MAX, rgb_max);

  pLight->current_R = r8;
  pLight->current_G = g8;
  pLight->current_B = b8;
}


/* ****************************************************************************
  Functionname:     HLASegCalcRGB_CalcLuminance
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static uint16 HLASegCalcRGB_CalcLuminance( const uint16* pc, 
                                           const uint16  xImgWidth, 
                                           const uint16  BL
                                         )
{
  sint32 fL;
  uint16  L;
  uint16 max, min;  

  /*       c      */
  /*       g      */
  /* c  g *pc g c */
  /*       g      */
  /*       c      */


  /* do not use the extreme green pixels for the mean value (max and min) */
  max = CML_Max(*(pc-1), *(pc+1));
  max = CML_Max(max, *(pc-xImgWidth));
  max = CML_Max(max, *(pc+xImgWidth));
  
  min = CML_Min(*(pc-1), *(pc+1));
  min = CML_Min(min, *(pc-xImgWidth));
  min = CML_Min(min, *(pc+xImgWidth));

  fL  = *(pc-1);
  fL += *(pc+1);
  fL += *(pc-xImgWidth);
  fL += *(pc+xImgWidth);
  fL -= min;
  fL -= max;
  /* divide by 2; +1 only for rounding */
  fL = (fL + 1) >> 1;

  L = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, (sint32)(fL - BL));

  /* return Luminance */
  return L;  
}


/* ****************************************************************************
  Functionname:     HLASegCalcRGB_HighQualityLinInterp_Kernel1
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel1( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        )
{
  sint32 fout = 0;
  /*        -1        */
  /*         2        */
  /*  -1  2  4  2 -1  */
  /*         2        */
  /*        -1        */

  fout -= (*(pPix - (2 * xImgWidth)) - BL);
  fout += 2 * (*(pPix - xImgWidth) - BL);
  fout -= (*(pPix - 2)) - BL;
  fout += 2 * (*(pPix - 1) - BL);
  fout += 4 * (*(pPix) - BL);
  fout += 2 * (*(pPix + 1) - BL);
  fout -= (*(pPix + 2)) - BL;
  fout += 2 * (*(pPix + xImgWidth) - BL);
  fout -= (*(pPix + (2 * xImgWidth))) - BL;

  /* divide by 8; +7 just for rounding */
  fout = (fout + 7) >> 3;

  return((uint16)(CML_MinMax(0, (sint32)UI16_T_MAX, fout)));
}

#if 0
/* ****************************************************************************
  Functionname:     HLASegCalcRGB_HighQualityLinInterp_Kernel2
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel2( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        )
{
  float32 fout = 0.0f;
  /*             0.5          */
  /*       -1        -1       */
  /*  -1    4    5    4   -1  */
  /*       -1        -1       */
  /*             0.5          */

  fout += 0.5f * ((*(pPix - (2 * xImgWidth))) - BL);
  fout -= (*(pPix - xImgWidth - 1) - BL);
  fout -= ((*((pPix - xImgWidth) + 1)) - BL);
  fout -= (*(pPix-2) - BL);
  fout += 4 * (*(pPix - 1) - BL);
  fout += 5 * (*(pPix) - BL);
  fout += 4 * (*(pPix+1) - BL);
  fout -= (*(pPix + 2) - BL);
  fout -= ((*((pPix + xImgWidth) - 1)) - BL);
  fout -= ((*((pPix + xImgWidth) + 1)) - BL);
  fout += 0.5f * (*(pPix + (2 * xImgWidth)) - BL);

  /* divide by 8.0 */
  fout *= 0.125f;

  return((uint16)MINMAX(0, UI16_T_MAX, CML_s_Round2Int(fout)));
}

/* ****************************************************************************
  Functionname:     HLASegCalcRGB_HighQualityLinInterp_Kernel3
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel3( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        )
{
  float32 fout = 0.0f;
  /*            -1            */
  /*       -1    4   -1       */
  /*  0.5        5       0.5  */
  /*       -1    4   -1       */
  /*            -1            */

  fout -= (*(pPix - (2 * xImgWidth))) - BL;
  fout -= (*((pPix - xImgWidth) - 1)) - BL;
  fout += 4 * ((*(pPix - xImgWidth)) - BL);
  fout -= (*((pPix - xImgWidth) + 1)) - BL;
  fout += 0.5f * ((*(pPix - 2)) - BL);
  fout += 5 * (*(pPix) - BL);
  fout += 0.5f * ((*(pPix + 2)) - BL);
  fout -= (*((pPix + xImgWidth) - 1)) - BL;
  fout += 4 * ((*(pPix + xImgWidth)) - BL);
  fout -= (*((pPix + xImgWidth) + 1)) - BL;
  fout -= (*(pPix + (2 * xImgWidth))) - BL;

  /* divide by 8.0 */
  fout *= 0.125f;

  return((uint16)MINMAX(0, UI16_T_MAX, CML_s_Round2Int(fout)));
}

/* ****************************************************************************
  Functionname:     HLASegCalcRGB_HighQualityLinInterp_Kernel4
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static uint16 HLASegCalcRGB_HighQualityLinInterp_Kernel4( const uint16* pPix, 
                                                          const uint16  xImgWidth, 
                                                          const uint16  BL
                                                        )
{
  float32 fout = 0.0f;
  /*            -1.5          */
  /*        2         2       */
  /* -1.5        6      -1.5  */
  /*        2         2       */
  /*            -1.5          */

  fout -= 1.5f * ((*(pPix - (2 * xImgWidth))) - BL);
  fout += 2 * ((*((pPix - xImgWidth) - 1)) - BL);
  fout += 2 * ((*((pPix - xImgWidth) + 1)) - BL);
  fout -= 1.5f * ((*(pPix - 2)) - BL);
  fout += 6 * (*(pPix) - BL);
  fout -= 1.5f * ((*(pPix + 2)) - BL);
  fout += 2 * ((*((pPix + xImgWidth) - 1)) - BL);
  fout += 2 * ((*((pPix + xImgWidth) + 1)) - BL);
  fout -= 1.5f * ((*(pPix + (2 * xImgWidth))) - BL);

  /* divide by 8.0 */
  fout *= 0.125f;

  return((uint16)MINMAX(0, UI16_T_MAX, CML_s_Round2Int(fout)));
}

/* ****************************************************************************
  Functionname:     HLASegCalcRGB_HighQualityLinInterp_Pixel
  Description:      gradient based rgb interpolation (LaRoche-Prescott) 

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegCalcRGB_HighQualityLinInterp_Pixel( const uint16* pPix,
                                               const uint16  xPix, 
                                               const uint16  yPix,
                                               const uint16  xImgWidth,
                                               const uint16  BL, 
                                                     uint16* pR, 
                                                     uint16* pG,
                                                     uint16* pB
                                              )
{
  const boolean isXPixOdd = (boolean)(xPix & 0x1);
  const boolean isYPixOdd = (boolean)(yPix & 0x1);

  if (isXPixOdd == b_TRUE)
  {
    if (isYPixOdd == b_TRUE)
    {
      *pG = CML_MinMax(0, UI16_T_MAX, (sint16)(*pPix - BL));
      /* R at green in B row, R column */
      /* Kernel 3 */
      *pR = HLASegCalcRGB_HighQualityLinInterp_Kernel3(pPix, xImgWidth, BL);
      /* B at green in B row, R column */
      /* Kernel 2 */
      *pB = HLASegCalcRGB_HighQualityLinInterp_Kernel2(pPix, xImgWidth, BL);
    }

    else /* (isXPixOdd == b_TRUE) && (isYPixOdd == b_FALSE) */
    {
      *pR = CML_MinMax(0, UI16_T_MAX, (sint16)(*pPix - BL));
      /* G at R location */
      /* Kernel 1 */
      *pG = HLASegCalcRGB_HighQualityLinInterp_Kernel1(pPix, xImgWidth, BL);
      /* B at red in R row, R column */
      /* Kernel 4 */
      *pB = HLASegCalcRGB_HighQualityLinInterp_Kernel4(pPix, xImgWidth, BL);
    }
  }
  else /* (isXPixOdd == b_FALSE) */
  {
    if (isYPixOdd == b_TRUE) 
    {
      *pB = CML_MinMax(0, UI16_T_MAX, (sint16)(*pPix - BL));
      /* R at blue in B row, B column */
      /* Kernel 4 */
      *pR = HLASegCalcRGB_HighQualityLinInterp_Kernel4(pPix, xImgWidth, BL);
      /* G at B location */
      /* Kernel 1 */
      *pG = HLASegCalcRGB_HighQualityLinInterp_Kernel1(pPix, xImgWidth, BL);

    }
    else /* (isXPixOdd == b_FALSE) && (isYPixOdd == b_FALSE) */
    {
      *pG = CML_MinMax(0, UI16_T_MAX, (sint16)(*pPix - BL));
      /* R at green in R row, B column */
      /* Kernel 2 */
      *pR = HLASegCalcRGB_HighQualityLinInterp_Kernel2(pPix, xImgWidth, BL);
      /* B at green in R row, B column */
      /* Kernel 3 */
      *pB = HLASegCalcRGB_HighQualityLinInterp_Kernel3(pPix, xImgWidth, BL);
    }
  }
}
#endif
