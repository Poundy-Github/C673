  /*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_lrf_main.c

  DESCRIPTION:            LRF classifier on EVE, main routine

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-10-08

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_lrf_main.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:51CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:42CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:06CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.4 2014/03/19 16:30:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:38 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.3 2014/03/12 18:07:21CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:22 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.2 2013/10/29 18:21:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:59 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.1 2013/10/16 15:00:34CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
**************************************************************************** */

#include <string.h>
#include "hla_eve_edma.h"
#include "hla_eve_lrf_main.h"
#include "hla_eve_lrf_at_vcop.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/

/* compiler check to make sure that vcop input data struct from DSP matches expectations */
#if(HLA_EVE_LRF_NUM_RFS_PARALLEL != VCOP_SIMD_WIDTH)
  #error HLA_EVE_LRF_NUM_RFS_PARALLEL and VCOP_SIMD_WIDTH is no longer aligned as expected.
#endif
/* compiler checks to make sure that vcop implementation is still aligned to fixpointed RFs */
#if((HLA_ICON_LRF_FIXPOINT_SCALE_LOG2 - VCOP_RF_FIXPOINT_EXPONENT) != 3)
  #error HLA_ICON_LRF_FIXPOINT_SCALE_LOG2 and VCOP_RF_FIXPOINT_EXPONENT are no longer aligned as expected.
#endif
/* DSP implementation expects 10 indices of tanh LUT. As we shift by 2 bits less there is a factor of 2^2 = 4 */
#if((HLA_ICON_TANH_LOOKUP_TABLE_SIZE * (2 * 2)) != VCOP_NUM_INDEX_TANH_LUT)
  #error HLA_ICON_LRF_FIXPOINT_SCALE_LOG2 and VCOP_RF_FIXPOINT_EXPONENT are no longer aligned as expected.
#endif
/* check that tanh lut interleaved from DSP has expected size */
#if((2 * VCOP_NUM_INDEX_TANH_LUT * VCOP_NUM_PARALLEL_TABLES) != HLA_EVE_LRF_TANH_LUT_INTERLEAVED_SIZE)
  #error HLA_EVE_LRF_TANH_LUT_INTERLEAVED_SIZE and VCOP_NUM_INDEX_TANH_LUT * VCOP_NUM_PARALLEL_TABLE are no longer aligned as expected.
#endif
/* check that number of parallel calculated RFs is aligned what vcop can do  */
#if(HLA_EVE_LRF_MAX_NUM_OF_VCOP_RUNS * VCOP_NUM_PARALLEL_TABLES != HLA_EVE_LRF_NUM_EVE_OUTPUTS)
  #error HLA_EVE_LRF_MAX_NUM_OF_VCOP_RUNS * VCOP_NUM_PARALLEL_TABLES and HLA_EVE_LRF_NUM_EVE_OUTPUTS are no longer aligned as expected.
#endif

/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/

#pragma SET_DATA_SECTION ("ALGO_SCRATCHBUFF_DMEM")
static uint64 timeStartVcop;
static uint32 activeBufArp32;

/* lrf type dependent data */
static uint32 sizeRFStruct;
static const sint32* pLrfRF;
static sint32* pLrfTH;
static const sint32* pLrfHiddenNeuronWeights;

#pragma SET_DATA_SECTION () /* End of ALGO_SCRATCHBUFF_DMEM */



/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/

static void HLAEveLrfSetLrftypeSpecificData( const HlaLrfTypes_t lrfType,
                                                   IbufLLrf_t*   pIbufL
                                            );
static uint16 HLAEveLrfCheckArguments( const void*  pSrcBufTanhLut,
                                       const uint32 srcBufTanhLutSize,
                                       const void*  pSrcBufPreProcImage,
                                       const uint32 srcBufPreProcImageSize,
                                       const void*  pSrcBufRFs,
                                       const uint32 srcBufRFsSize,
                                       const void*  pDestBufHiddenNeuronsLow,
                                       const uint32 destBufHiddenNeuronsLowSize,
                                       const void*  pDestBufHiddenNeuronsHigh,
                                       const uint32 destBufHiddenNeuronsHighSize
                                      );
static uint16 HLAEveLrfInitVcop( const WbufLrf_t*  pWbuf,
                                 const IbufLLrf_t* pIbufL,
                                 const IbufHLrf_t* pIbufH
                                );
static inline void HLAEveLrfIbufsToggle(void);
static inline void HLAEveLrfTriggerVcop(IbufLLrf_t* pIbufL);
static inline void HLAEveLrfWait4Vcop(HLAEveTimeMeas_t* pTimeMeas);


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/
uint16 HLAEveLrfMain( const HLAEveLrfParams_t* psHLAEveLrfParams,
                      const void*              pSrcBufTanhLut,
                      const uint32             srcBufTanhLutSize,
                      const void*              pSrcBufPreProcImage,
                      const uint32             srcBufPreProcImageSize,
                      const void*              pSrcBufRFs,
                      const uint32             srcBufRFsSize,
                      const void*              pDestBufHiddenNeuronsLow,
                      const uint32             destBufHiddenNeuronsLowSize,
                      const void*              pDestBufHiddenNeuronsHigh,
                      const uint32             destBufHiddenNeuronsHighSize,
                      WbufLrf_t*               pWbuf,
                      IbufLLrf_t*              pIbufL,
                      IbufHLrf_t*              pIbufH,
                      HLAEveTimeMeas_t*        pTimeMeas
                     )
{
  /* Init return value with ok */
  uint16 retVal = HLA_EVE_LRF_RETURN_OK;
  uint64 timeStart;
  uint32 i;
  /* constant offset for features so that tanh look-up table has only positive indices, i.e. 40 * 2^20 = 0x280 0000 */
  const sint32 tanhLutOffset = VCOP_NUM_INDEX_TANH_LUT * (1 << VCOP_RF_FIXPOINT_EXPONENT);

  HLAEveTimeMeasStart(&timeStart);

  HLAEveLrfSetLrftypeSpecificData( (HlaLrfTypes_t)psHLAEveLrfParams->lrfType,
                                   pIbufL
                                  );

  retVal |= HLAEveLrfCheckArguments( pSrcBufTanhLut,
                                     srcBufTanhLutSize,
                                     pSrcBufPreProcImage,
                                     srcBufPreProcImageSize,
                                     pSrcBufRFs,
                                     srcBufRFsSize,
                                     pDestBufHiddenNeuronsLow,
                                     destBufHiddenNeuronsLowSize,
                                     pDestBufHiddenNeuronsHigh,
                                     destBufHiddenNeuronsHighSize
                                    );


  /* MAIN PART STARTS HERE */
  if (retVal == HLA_EVE_LRF_RETURN_OK)
  {
    /* ---------------------------------------------------
     * INIT PHASE
     * ---------------------------------------------------*/
    /* Set alias memory view */
    VCOP_SET_MEM_VIEW (ALIAS_128K_VIEW);
    /* Assign all buffers to ARP32 and EDMA */
    VCOP_BUF_SWITCH_SET (WBUF_SYST, IBUFHB_SYST, IBUFHA_SYST, IBUFLB_SYST, IBUFLA_SYST);

    /* Initialize Edma */
    HLAEveEdmaInit();

    /* Initialize vcop, i.e. copy parameters to WBUF, IBUFHA and IBUFHB, respectively */
    retVal |= HLAEveLrfInitVcop( pWbuf,
                                 pIbufL,
                                 pIbufH
                                );
    /* Reset hidden neurons since vcop expects real data in it */
    (void)memset((void*)pWbuf->hiddenNeuronHigh, 0, sizeof(pWbuf->hiddenNeuronHigh));
    (void)memset((void*)pWbuf->hiddenNeuronLow, 0u, sizeof(pWbuf->hiddenNeuronLow));

    pTimeMeas->dTimeEveLrfInit_us = HLAEveTimeMeasEnd(timeStart);


    /* ---------------------------------------------------
     * MAIN PHASE
     * ---------------------------------------------------*/
    HLAEveTimeMeasStart(&timeStart);

    /* Set IBUFAs as first buffer to be filled by edma */
    activeBufArp32 = HLA_EVE_IBUFA;

    /* Configure and trigger EDMA to fill IBUFLA and wait until it has finished */
    retVal |= HLAEveEdmaCfgLinked1d1d( pSrcBufTanhLut,
                                       (void*)&(pIbufL->tanhLuTInterleaved[0]),
                                       (uint16)srcBufTanhLutSize,
                                       1u
                                      );
    retVal |= HLAEveEdmaCfgLinked1d1d( pSrcBufPreProcImage,
                                       (void*)&(pIbufL->preProcImage[0]),
                                       (uint16)srcBufPreProcImageSize,
                                       2u
                                      );
    retVal |= HLAEveEdmaCfg1d1d( pSrcBufRFs,
                                 (void*)&(pIbufL->RFs),
                                 (uint16)srcBufRFsSize,
                                 3u
                                );
    HLAEveEdmaTriggerDma();
    HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveLrfMainEdma_us);
    /* Add constant offset to feature offsets for tanh LuT */
    for (i = 0; i < CML_Min(psHLAEveLrfParams->numRFs, HLA_EVE_LRF_NUM_RFS_PARALLEL); i++)
    {
      pLrfTH[i] = tanhLutOffset - pLrfTH[i];
    }

    /* check number of RFs */
    if (psHLAEveLrfParams->numRFs > HLA_EVE_LRF_NUM_EVE_OUTPUTS)
    {
      /* Right now, eve code is designed to need at most 2 vcop runs per icon */
      retVal |= HLA_EVE_LRF_RETURN_ERR_NUM_RFS;
    }

    /* Toggle IBUFs so that EDMA can write to IBUFB and VCOP can work on IBUFA  */
    HLAEveLrfIbufsToggle();

    /* Trigger VCOP to work on IBUFA and wait until it has finished*/
    HLAEveLrfTriggerVcop(pIbufL);
    HLAEveLrfWait4Vcop(pTimeMeas);

    /* Check whether we need another vcop run */
    if (psHLAEveLrfParams->numRFs > HLA_EVE_LRF_NUM_RFS_PARALLEL)
    {
      /* Configure and trigger EDMA to fill IBUFLB and wait until it has finished */
      retVal |= HLAEveEdmaCfgLinked1d1d( pSrcBufTanhLut,
                                         (void*)&(pIbufL->tanhLuTInterleaved[0]),
                                         (uint16)srcBufTanhLutSize,
                                         1u
                                        );
      retVal |= HLAEveEdmaCfgLinked1d1d( pSrcBufPreProcImage,
                                         (void*)&(pIbufL->preProcImage[0]),
                                         (uint16)srcBufPreProcImageSize,
                                         2u
                                        );
      retVal |= HLAEveEdmaCfg1d1d( pSrcBufRFs,
                                   (void*)&(pIbufL->RFs),
                                   (uint16)srcBufRFsSize,
                                   3u
                                  );
      HLAEveEdmaTriggerDma();
      HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveLrfMainEdma_us);
      /* Add constant offset to feature offsets (2nd half) for tanh LuT */
      for (i = HLA_EVE_LRF_NUM_RFS_PARALLEL; i < CML_Min(psHLAEveLrfParams->numRFs, 2u * HLA_EVE_LRF_NUM_RFS_PARALLEL); i++)
      {
        (pLrfTH + (HLA_EVE_IBUFS_OFFSET / 4u))[i] = tanhLutOffset - (pLrfTH + (HLA_EVE_IBUFS_OFFSET / 4u))[i];
      }

      /* Toggle IBUFs so that VCOP can work on IBUFB  */
      HLAEveLrfIbufsToggle();

      /* Trigger VCOP to work on IBUFB and wait until it has finished*/
      HLAEveLrfTriggerVcop(pIbufL);
      HLAEveLrfWait4Vcop(pTimeMeas);
    }

    pTimeMeas->dTimeEveLrfMain_us = HLAEveTimeMeasEnd(timeStart);

    /* ---------------------------------------------------
     * EXIT PHASE
     * ---------------------------------------------------*/
    HLAEveTimeMeasStart(&timeStart);

    /* Write output back to DDR */

    /* Assign all buffers to ARP32 and EDMA for writing back to DDR3 */
     VCOP_BUF_SWITCH_SET (WBUF_SYST, IBUFHB_SYST, IBUFHA_SYST, IBUFLB_SYST, IBUFLA_SYST);
    memcpy((void*)pDestBufHiddenNeuronsLow, (void*)&(pWbuf->hiddenNeuronLow), sizeof(pWbuf->hiddenNeuronLow));
    memcpy((void*)pDestBufHiddenNeuronsHigh, (void*)&(pWbuf->hiddenNeuronHigh), sizeof(pWbuf->hiddenNeuronHigh));

    /* Reset memory view to flat view since this is the default view */
    VCOP_SET_MEM_VIEW (MEM_BUF_VIEW);
    /* Clear edma event registers */
    HLAEveEdmaTeardownDma();

    DBG(("----------------------EDMA_CHAIN-------------------------------\n"));
    DBG((" one icon classified \n"));
    DBG(("---------------------------------------------------------------\n"));
    pTimeMeas->dTimeEveLrfExit_us = HLAEveTimeMeasEnd(timeStart);
  }
  return retVal;
}

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/

static void HLAEveLrfSetLrftypeSpecificData( const HlaLrfTypes_t lrfType,
                                                   IbufLLrf_t*   pIbufL
                                            )
{
   switch (lrfType)
  {
  case LRF_TYPE_HALOGEN:
    sizeRFStruct = sizeof(HlaLrfInputsHalogen_t);
    pLrfRF = &(pIbufL->RFs.RFs_Halogen.lrf_RF[0]);
    pLrfTH = &(pIbufL->RFs.RFs_Halogen.lrf_TH[0]);
    pLrfHiddenNeuronWeights = &(pIbufL->RFs.RFs_Halogen.lrf_hiddenNeuronWeights[0]);
    break;
  case LRF_TYPE_REDLIGHT:
    sizeRFStruct = sizeof(HlaLrfInputsRedLight_t);
    pLrfRF = &(pIbufL->RFs.RFs_RedLight.lrf_RF[0]);
    pLrfTH = &(pIbufL->RFs.RFs_RedLight.lrf_TH[0]);
    pLrfHiddenNeuronWeights = &(pIbufL->RFs.RFs_RedLight.lrf_hiddenNeuronWeights[0]);
    break;
  case LRF_TYPE_CITYLIGHT:
    sizeRFStruct = sizeof(HlaLrfInputsCityLight_t);
    pLrfRF = &(pIbufL->RFs.RFs_CityLight.lrf_RF[0]);
    pLrfTH = &(pIbufL->RFs.RFs_CityLight.lrf_TH[0]);
    pLrfHiddenNeuronWeights = &(pIbufL->RFs.RFs_CityLight.lrf_hiddenNeuronWeights[0]);
    break;
    /* use XENONLED as default */
    case LRF_TYPE_XENONLED:
    default:
      sizeRFStruct = sizeof(HlaLrfInputsXenonLED_t);
      pLrfRF = &(pIbufL->RFs.RFs_XenonLED.lrf_RF[0]);
      pLrfTH = &(pIbufL->RFs.RFs_XenonLED.lrf_TH[0]);
      pLrfHiddenNeuronWeights = &(pIbufL->RFs.RFs_XenonLED.lrf_hiddenNeuronWeights[0]);
      break;
  }
}

static uint16 HLAEveLrfCheckArguments( const void*  pSrcBufTanhLut,
                                       const uint32 srcBufTanhLutSize,
                                       const void*  pSrcBufPreProcImage,
                                       const uint32 srcBufPreProcImageSize,
                                       const void*  pSrcBufRFs,
                                       const uint32 srcBufRFsSize,
                                       const void*  pDestBufHiddenNeuronsLow,
                                       const uint32 destBufHiddenNeuronsLowSize,
                                       const void*  pDestBufHiddenNeuronsHigh,
                                       const uint32 destBufHiddenNeuronsHighSize
                                      )
{
  uint16 retVal = HLA_EVE_LRF_RETURN_OK;

  /* Check input/output buffers */
  if (  (srcBufTanhLutSize > HLA_EVE_LRF_TANH_LUT_INTERLEAVED_SIZE * sizeof(sint32))
     || (!pSrcBufTanhLut)
    )
  {
    /* Input buffer is bigger than expected
     * OR pointer is invalid
     */
    retVal |= HLA_EVE_LRF_RETURN_ERR_TANH_LUT;
  }

  if (  (srcBufPreProcImageSize > (HLA_EVE_LRF_ICON_SIZE + 96) * sizeof(uint8))  /* 96: padding bytes to match HLA_DSP_CACHE_LINE */
     || (!pSrcBufPreProcImage)
    )
  {
    /* Input buffer is bigger than expected
     * OR pointer is invalid
     */
    retVal |= HLA_EVE_LRF_RETURN_ERR_PRE_PROC_IMAGE;
  }

  if (   (srcBufRFsSize > sizeRFStruct)
      || (!pSrcBufRFs)
      )
  {
    /* Input buffer pointer is invalid */
    retVal |= HLA_EVE_LRF_RETURN_ERR_RFS;
  }

  if (   (destBufHiddenNeuronsLowSize < HLA_EVE_LRF_NUM_RFS_PARALLEL * sizeof(uint32))
      || (destBufHiddenNeuronsHighSize < HLA_EVE_LRF_NUM_RFS_PARALLEL * sizeof(sint32))
      || (!pDestBufHiddenNeuronsLow)
      || (!pDestBufHiddenNeuronsHigh)
    )
  {
    /* Output buffers are smaller than expected
     * OR pointers are invalid
     */
    retVal |= HLA_EVE_LRF_RETURN_ERR_HIDDEN_NEURONS;
  }

  return retVal;
}


static uint16 HLAEveLrfInitVcop( const WbufLrf_t*  pWbuf,
                                 const IbufLLrf_t* pIbufL,
                                 const IbufHLrf_t* pIbufH
                                )
{
  uint32  numParamRegsVcopFeatures;
  uint32  numParamRegsVcopNeurons;
  uint16  retVal = HLA_EVE_LRF_RETURN_OK;

  /* Register argument list at vcop side in IBUFHA to process first HLA_EVE_LRF_NUM_RFS_PARALLEL RFs */
  numParamRegsVcopFeatures = HLAEveLrfVcopCalcFeatures_init( (uint8*)pIbufL->preProcImage,
                                                             (uint8)HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH,
                                                             (uint8)HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT,
                                                             (uint8)HLA_ICON_WINDOW_WIDTH,
                                                             (uint8)HLA_ICON_LRF_DS,
                                                             (uint8)HLA_ICON_LRF_FS,
                                                             (uint8)HLA_ICON_LRF_FS,
                                                             /* filters 16 low bits */
                                                             (uint16*)pLrfRF,
                                                             /* filters 16 high bits */
                                                             ((sint16*)pLrfRF) + 1,
                                                             (sint32*)pLrfTH,
                                                             (uint8*)pWbuf->tempFeatureList,
                                                             (sint32*)pIbufL->tanhLuTInterleaved,
                                                             (sint32*)pIbufH->tanhFeatureList,
                                                             /* place to store above parameters */
                                                             (uint16*)pIbufL->argsBlockVcopCalcFeatures
                                                            );
  numParamRegsVcopNeurons = HLAEveLrfVcopCalcNeurons_init( /* filters 16 low bits */
                                                           (uint16*)(pIbufH->tanhFeatureList),
                                                           /* filters 16 high bits */
                                                           ((sint16*)pIbufH->tanhFeatureList) + 1,
                                                           (uint16)(HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH * HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT),
                                                           /* +1u since first element of that list is the static offset; filters 16 low bits */
                                                           (uint16*)(pLrfHiddenNeuronWeights + 1u),
                                                           /* +1u since first element of that list is the static offset; filters 16 high bits */
                                                           ((sint16*)(pLrfHiddenNeuronWeights + 1u)) + 1,
                                                           (uint32*)&(pWbuf->hiddenNeuronLow[0]),
                                                           (sint32*)&(pWbuf->hiddenNeuronHigh[0]),
                                                           /* place to store above parameters */
                                                           (uint16*)pIbufL->argsBlockVcopCalcNeurons
                                                          );

  /* Register argument list at vcop side in IBUFHB to process next HLA_EVE_LRF_NUM_RFS_PARALLEL RFs */
  numParamRegsVcopFeatures = HLAEveLrfVcopCalcFeatures_init( (uint8*)pIbufL->preProcImage,
                                                             (uint8)HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH,
                                                             (uint8)HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT,
                                                             (uint8)HLA_ICON_WINDOW_WIDTH,
                                                             (uint8)HLA_ICON_LRF_DS,
                                                             (uint8)HLA_ICON_LRF_FS,
                                                             (uint8)HLA_ICON_LRF_FS,
                                                             /* filters 16 low bits in 2nd block of 8 RFs */
                                                             (uint16*)(pLrfRF + HLA_EVE_LRF_NUM_RFS_PARALLEL * (HLA_ICON_LRF_FS * HLA_ICON_LRF_FS)),
                                                             /* filters 16 high bits in 2nd block of 8 RFs */
                                                             ((sint16*)(pLrfRF + HLA_EVE_LRF_NUM_RFS_PARALLEL * (HLA_ICON_LRF_FS * HLA_ICON_LRF_FS))) + 1,
                                                             (sint32*)(pLrfTH + HLA_EVE_LRF_NUM_RFS_PARALLEL),
                                                             (uint8*)pWbuf->tempFeatureList,
                                                             (sint32*)pIbufL->tanhLuTInterleaved,
                                                             (sint32*)pIbufH->tanhFeatureList,
                                                             /* place to store above parameters */
                                                             (uint16*)(pIbufL->argsBlockVcopCalcFeatures + (HLA_EVE_IBUFS_OFFSET / 2u))
                                                            );
  numParamRegsVcopNeurons = HLAEveLrfVcopCalcNeurons_init( /* filters 16 low bits */
                                                           (uint16*)(pIbufH->tanhFeatureList),
                                                           /* filters 16 high bits */
                                                           ((sint16*)pIbufH->tanhFeatureList) + 1,
                                                           (uint16)(HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH * HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT),
                                                           /* +1u since first element of that list is the static offset; filters 16 low bits */
                                                           (uint16*)(pLrfHiddenNeuronWeights + 1u + HLA_EVE_LRF_NUM_RFS_PARALLEL * (HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT * HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH)),
                                                           /* +1u since first element of that list is the static offset; filters 16 high bits */
                                                           ((sint16*)(pLrfHiddenNeuronWeights + 1u + HLA_EVE_LRF_NUM_RFS_PARALLEL * (HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT * HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH))) + 1,
                                                           (uint32*)&(pWbuf->hiddenNeuronLow[1]),
                                                           (sint32*)&(pWbuf->hiddenNeuronHigh[1]),
                                                           /* place to store above parameters */
                                                           (uint16*)(pIbufL->argsBlockVcopCalcNeurons + (HLA_EVE_IBUFS_OFFSET / 2u))
                                                          );

  if (numParamRegsVcopFeatures != HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_FEATURES)
  {
    DBG(("!!! Number of argument registers returned from vcop (%d) not matching corresponding buffer size for 'CalcFeatures' call: %d !!!\n", numParamRegsVcopFeatures, HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_FEATURES));
    retVal |= HLA_EVE_LRF_RETURN_ERR_VCOP_PARAMS_FEATURES;
  }
  if (numParamRegsVcopNeurons != HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_NEURONS)
  {
    DBG(("!!! Number of argument registers returned from vcop (%d) not matching corresponding buffer size for 'CalcNeurons' call: %d !!!\n", numParamRegsVcopNeurons, HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_NEURONS));
    retVal |= HLA_EVE_LRF_RETURN_ERR_VCOP_PARAMS_NEURONS;
  }

  return retVal;
}

static inline void HLAEveLrfIbufsToggle(void)
{
  if (activeBufArp32 == HLA_EVE_IBUFA)
  {
    VCOP_BUF_SWITCH_SET(WBUF_VCOP, IBUFHB_SYST, IBUFLB_SYST, IBUFHA_VCOP, IBUFLA_VCOP);
  }
  else
  {
    VCOP_BUF_SWITCH_SET(WBUF_VCOP, IBUFHB_VCOP, IBUFLB_VCOP, IBUFHA_SYST, IBUFLA_SYST);
  }
  activeBufArp32 = (activeBufArp32 ^ 0x1);
}

static inline void HLAEveLrfTriggerVcop(IbufLLrf_t* pIbufL)
{
  HLAEveTimeMeasStart(&timeStartVcop);
  /* Call vcop to start feature caculation */
  HLAEveLrfVcopCalcFeatures_vloops(pIbufL->argsBlockVcopCalcFeatures);
  /* Call vcop to start neuron caculation */
  HLAEveLrfVcopCalcNeurons_vloops(pIbufL->argsBlockVcopCalcNeurons);
}

static inline void HLAEveLrfWait4Vcop(HLAEveTimeMeas_t* pTimeMeas)
{
  /* Wait until vcop returns */
  _vcop_vloop_done();
  DBG(("VCOP called\n"));

  pTimeMeas->dTimeEveLrfMainVcop_us += HLAEveTimeMeasEnd(timeStartVcop);
}
