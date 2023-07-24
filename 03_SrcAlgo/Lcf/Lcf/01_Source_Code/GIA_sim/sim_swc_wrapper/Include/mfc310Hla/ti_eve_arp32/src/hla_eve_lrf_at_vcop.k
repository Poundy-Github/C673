/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_lrf_vcop.k

  DESCRIPTION:            LRF Classifier

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2014-01-16

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_lrf_at_vcop.k  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:51CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:42CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:06CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.2 2014/03/28 13:09:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed hidden neuron calculation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 28, 2014 1:09:59 PM CET]
  CHANGES:                Change Package : 198642:9 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.1 2014/03/12 17:47:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
**************************************************************************** */

#include "hla_eve_vcop.h"
/*
 * Main function that does feature calculation within LRF classifier
 */
/*
 * !!! IN CASE OF ANY CHANGE OF FOLLOWING FUNCTION INTERFACE (ARGUMENTS)
 * !!! check .c file how many parameter registers are used.
 * !!! If there are changes you have to change HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_FEATURES in hla_lrf_main.h
 */
void HLAEveLrfVcopCalcFeatures( __vptr_uint8   pSrcBufPreProcIcon,            /* pointer to source buffer: pre-processed icon */
                                unsigned char  iconEffectiveWidth,            /* effective width icon due to displacement and RF window size */
                                unsigned char  iconEffectiveHeight,           /* effective height icon due to displacement and RF window size */
                                unsigned char  iconWidth,                     /* real icon width needed for address calculations */
                                unsigned char  iconDisplacement,              /* step size while processing icon, e.g. only every 2nd pixels is taken into account */
                                unsigned char  RFWidth,                       /* width (x-direction) of RF */
                                unsigned char  RFHeight,                      /* height (y-direction) of RF */
                                __vptr_uint16  pRFWeightsLow,                 /* pointer to buffer of RF weights, 16 low bits */
                                __vptr_int16   pRFWeightsHigh,                /* pointer to buffer of RF weights, 16 high bits */
                                __vptr_int32   pFeatureOffsets,               /* pointer to feature offsets */
                                __vptr_uint8   pTempBufFeatures,              /* pointer to temporary buffer: output of loop 1 */
                                __vptr_int32   pTanhLut,                      /* pointer to tanh look-up table */
                                __vptr_int32   pDestBufTanhFeatures           /* pointer to output buffer: output of loop 2 */
                              )
{
  __agen AddrZero = 0;
  /* read feature offsets for that block of RFs */
  __vector VfeatureOffsets = pFeatureOffsets[AddrZero];

  /* ****************************************************************
   * LOOP 1 - Raw feature calculation
   * ****************************************************************/

  /* loop over all lines of pre-processed icon with a displacement of iconDisplacement and with respect to RF window size */
  for (int iconY = 0; iconY < iconEffectiveHeight; iconY++)
  {
    /* loop over all rows of pre-processed icon with a displacement of iconDisplacement and with respect to RF window size */
    for (int iconX = 0; iconX < iconEffectiveWidth; iconX++)
    {
      __agen   AddrFeatures;
      __vector Vfeatures;

      /* address where to store calculated feature */
      AddrFeatures =   iconY * (iconEffectiveWidth * VECTORSIZE(pTempBufFeatures))   /* move to next line of blocks block of features output by inner loops */
                     + iconX * (VECTORSIZE(pTempBufFeatures));                       /* move to next block of features output by inner loops */

      /* Start features with offset */
      Vfeatures = VfeatureOffsets;

      /* loop over all lines of RF window */
      for (int RFY = 0; RFY < RFHeight; RFY++)
      {
        /* loop over all rows of RF window */
        for (int RFX = 0; RFX < RFWidth; RFX++)
        {
          __agen   AddrIcon;                                    /* address generator pointing to pixels of pre-processed icons */
          __agen   AddrRFWeights;                               /* address generator pointing to RF weights */
          __vector ViconPix;                                    /* vector register containing one pixel of icon */
          __vector VrfWeightLow;                                /* vector register containing lower 16 bits of RF weights */
          __vector VrfWeightHigh;                               /* vector register containing higher 16 bits of RF weights */
          __vector Vscr0;                                       /* scratch register */
          __vector Vconst16 = 16;

          /* address of pixel of pre-processed icon */
          AddrIcon =   iconY * (iconWidth * iconDisplacement * ELEMSIZE(pSrcBufPreProcIcon))    /* move to next line but one */
                     + iconX * (iconDisplacement * ELEMSIZE(pSrcBufPreProcIcon))                /* move to next element of this line but one */
                     + RFY * (iconWidth * ELEMSIZE(pSrcBufPreProcIcon))                         /* move to next line of RF window */
                     + RFX * (ELEMSIZE(pSrcBufPreProcIcon));                                    /* move to next element of RF window */

          /* address of weight of RFs */
          AddrRFWeights =   RFY * (RFWidth * 2 * VECTORSIZE(pRFWeightsLow))                     /* move to next line of blocks of RF weights; factor of 2 due to de-interleaved load */
                          + RFX * (2 * VECTORSIZE(pRFWeightsLow));                              /* move to next block of RF weights; factor of 2 due to de-interleaved load */

          /* read one pixel for all 8 RFs */
          ViconPix = pSrcBufPreProcIcon[AddrIcon].onept();

          /* read RF weights for that pixel. Use down-sample operator ds2() to filter for high/low part */
          VrfWeightLow = pRFWeightsLow[AddrRFWeights].ds2();
          VrfWeightHigh = pRFWeightsHigh[AddrRFWeights].ds2();

          /* calculate sub-feature and add it to total one */
          /* calculate product of lower part */
          Vfeatures += (VrfWeightLow * ViconPix);
          /* calculate product of higher part */
          Vscr0 = (VrfWeightHigh * ViconPix);
          Vscr0 = (Vscr0 << Vconst16);
          Vfeatures += Vscr0;
        }
      }

      /* saturate and truncate output which is interpreted as index of tanh LUT in next loop */
      pTempBufFeatures[AddrFeatures] = Vfeatures.truncate(VCOP_RF_FIXPOINT_EXPONENT).saturate(0, 2 * VCOP_NUM_INDEX_TANH_LUT - 1);
    }
  }


/* ****************************************************************
 * LOOP 2 - TanH Look-up table
 * ****************************************************************/
  __vector Vindex;                /* vector register containing table indices, i.e. calculated features from loop 1 */
  __vector Vtabledata;            /* vector register containing looked-up data depending on table index */

  _LOOKUP(VCOP_NUM_PARALLEL_TABLES, VCOP_NUM_POINTS_PER_TABLE);
  /* loop over all calculated features */
  for (int features = 0; features < iconEffectiveHeight * iconEffectiveWidth; features++)
  {
    __agen AddrIndex;             /* address generator pointing to input buffer */
    __agen AddrLuT = 0;           /* address generator pointing to beginning of interleaved tanh look-up table */
    __agen AddrOut;               /* address generator pointing to output buffer */

    AddrIndex = features * (VCOP_NUM_PARALLEL_TABLES * ELEMSIZE(pTempBufFeatures));
    AddrOut = features * (VCOP_NUM_PARALLEL_TABLES * ELEMSIZE(pDestBufTanhFeatures));

    /* Read VCOP_NUM_PARALLEL_TABLES, i.e. 8 indices at once */
    Vindex = pTempBufFeatures[AddrIndex];
    /* Lookup those indices */
    Vtabledata = pTanhLut[AddrLuT].lookup(Vindex);
    /* Store looked-up values in output buffer */
    pDestBufTanhFeatures[AddrOut].table_npt() = Vtabledata;
  }
}


/*
 * Function that does hidden neuron calculation within LRF classifier
 */
/*
 * !!! IN CASE OF ANY CHANGE OF FOLLOWING FUNCTION INTERFACE (ARGUMENTS)
 * !!! check .c file how many parameter registers are used.
 * !!! If there are changes you have to change HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_NEURONS in hla_lrf_main.h
 */
void HLAEveLrfVcopCalcNeurons( __vptr_uint16   pSrcBufTanhFeaturesLow,        /* pointer to source buffer: calculated features, 16 low bits */
                               __vptr_int16    pSrcBufTanhFeaturesHigh,       /* pointer to source buffer: calculated features, 16 high bits */
                                unsigned short numTanhFeatures,               /* number of calculated features in previous step */
                                __vptr_uint16  pNeuronWeightsLow,             /* pointer to buffer of hidden neuron weights, 16 low bits */
                                __vptr_int16   pNeuronWeightsHigh,            /* pointer to buffer of hidden neuron weights, 16 high bits */
                                __vptr_uint32  pDestBufNeuronLow,             /* pointer to destination buffer: accumulated sub-neurons, 32 low bits */
                                __vptr_int32   pDestBufNeuronHigh             /* pointer to destination buffer: accumulated sub-neurons, 32 high bits */
                              )
{
  /* ****************************************************************
   * LOOP 1 - 32-bit x 32-bit multiplication
   *
   * VFLo = pSrcBufTanhFeaturesLow
   * VFHi = pSrcBufTanhFeaturesHigh
   * VWLo = pNeuronWeightsLow
   * VWHi = pNeuronWeightsHigh
   *
   * VA = VFLo * VWLo             0000 0000 | VAHi VALo
   * VB = VFHi * VWHi             VBHi VBLo | 0000 0000
   * VC = VFLo * VWHi             0000 VCHi | VCLo 0000
   * VD = VFHi * VWLo             0000 VDHi | VDLo 0000
   *
   * pDestBufNeuronLow  = VAHi + VALo + VCLo + VDLo with implicit casting to 32-bits
   * pDestBufNeuronHigh = VBHi + VBLow + VCHi + VDHi + hi(pDestBufNeuronLow) which means overflow bits 39..32
   * ****************************************************************/

  __agen AddrZero = 0;
  /* read already calculated neuron values  */
  __vector VneuronLow  = pDestBufNeuronLow[AddrZero];
  __vector VneuronHigh = pDestBufNeuronHigh[AddrZero];

  /* dummy loop only needed for being able to store results at the end */
  for (int dummy = 0; dummy < 1; dummy++)
  {
    /* loop over all previously calculated features */
    for (int features = 0; features < numTanhFeatures; features++)
    {
      __agen AddrInputs;                  /* address generator pointing to previously calculated tanh features and hidden neuron weights */
      __vector VfeaturesLow;              /* vector register containing lower 16 bits of tanh features */
      __vector VfeaturesHigh;             /* vector register containing higher 16 bits of tanh features */
      __vector VneuronWeightsLow;         /* vector register containing lower 16 bits of hidden neuron weights */
      __vector VneuronWeightsHigh;        /* vector register containing higher 16 bits of hidden neuron weights */
      __vector VCLow;                     /* vector register containing lower 16 bits of multiplication of pSrcBufTanhFeaturesLow * pNeuronWeightsHigh */
      __vector VCHigh;                    /* vector register containing higher 16 bits of multiplication of pSrcBufTanhFeaturesLow * pNeuronWeightsHigh */
      __vector VDLow;                     /* vector register containing lower 16 bits of multiplication of pSrcBufTanhFeaturesHigh * pNeuronWeightsLow */
      __vector VDHigh;                    /* vector register containing higher 16 bits of multiplication of pSrcBufTanhFeaturesHigh * pNeuronWeightsLow */
      __vector Vscr0;                     /* scratch register */
      __vector VconstMask = 0xFFFFFFFFU;

      /* Address of inputs, factor of 2 due to split in high/low */
      AddrInputs  = features * (2 * VECTORSIZE(pSrcBufTanhFeaturesLow));

      /* Read inputs */
      VfeaturesLow       = pSrcBufTanhFeaturesLow[AddrInputs].ds2();
      VfeaturesHigh      = pSrcBufTanhFeaturesHigh[AddrInputs].ds2();
      VneuronWeightsLow  = pNeuronWeightsLow[AddrInputs].ds2();
      VneuronWeightsHigh = pNeuronWeightsHigh[AddrInputs].ds2();

      /* Multiply lower parts (VA) and add it to output neuron lower part */
      VneuronLow += (VfeaturesLow * VneuronWeightsLow);

      /* Multiply higher parts (VB) and add it to output neuron higher part */
      VneuronHigh += (VfeaturesHigh * VneuronWeightsHigh);

      /* Multiply mixed parts */
      /* VC: */
      Vscr0 = (VfeaturesLow * VneuronWeightsHigh);
      /* Separate higher 16 and lower 16 bits */
      (VCLow, VCHigh) = jus16(Vscr0);
      /* VD: */
      Vscr0 = (VfeaturesHigh * VneuronWeightsLow);
      /* Separate higher 16 and lower 16 bits */
      (VDLow, VDHigh) = jus16(Vscr0);

      /* Added lower parts of mixed parts */
      VneuronLow += (VCLow + VDLow);

      /* Added higher parts of mixed parts */
      VneuronHigh += (VCHigh + VDHigh);
      /* Added overflowing bits (39..32) of lower parts */
      VneuronHigh += hi(VneuronLow);

      /* Clean lower part from overflow bits */
      VneuronLow &= VconstMask;
    }

    /* Write calculated neurons back to buffer */
    pDestBufNeuronLow[AddrZero]  = VneuronLow;
    pDestBufNeuronHigh[AddrZero] = VneuronHigh;
  }
}
