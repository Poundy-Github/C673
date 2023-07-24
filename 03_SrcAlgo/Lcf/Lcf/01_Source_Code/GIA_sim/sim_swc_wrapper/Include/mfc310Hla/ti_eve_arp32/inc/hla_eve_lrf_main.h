/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_lrf_main.h

  DESCRIPTION:            LRF classifier on EVE, main routines

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-10-08

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_lrf_main.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:46CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:35CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:03CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.4 2014/03/12 18:07:19CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:19 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.3 2014/01/10 18:33:33CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:34 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.2 2013/10/29 18:21:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:58 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.1 2013/10/16 15:00:14CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
**************************************************************************** */

#ifndef HLA_EVE_LRF_MAIN_H
#define HLA_EVE_LRF_MAIN_H

#include "hla_analysisicon.h"
#include "hla_eve.h"


/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/
/* LRF */
#define HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_FEATURES  38u                             /* number of used parameter registers for vcop, depending on argument list of HLAEveLrfVcopCalcFeatures() */
#define HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_NEURONS   20u                             /* number of used parameter registers for vcop, depending on argument list of HLAEveLrfVcopCalcNeurons() */

#define HLA_EVE_LRF_ICON_SIZE (HLA_ICON_WINDOW_WIDTH * HLA_ICON_WINDOW_HEIGHT)   /* icon size */
#define HLA_EVE_LRF_MAX_NUM_OF_VCOP_RUNS          2u                             /* Eve code design: How often vcop can run, i.e. how many RFs can be calculated */
/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/

/* LRF input data depending on icon type */
typedef union
{
  HlaLrfInputsXenonLED_t RFs_XenonLED;
  HlaLrfInputsHalogen_t RFs_Halogen;
  HlaLrfInputsRedLight_t RFs_RedLight;
  HlaLrfInputsCityLight_t RFs_CityLight;
} RFs_t;

typedef struct
{
  /* vcop intermediate result of loop 1, i.e. list of all calculated features per icon (already truncated/saturated) */
  uint8 tempFeatureList[HLA_EVE_LRF_NUM_RFS_PARALLEL * (HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH * HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT)];
  /* hidden neurons for each vcop run, maximum are 2 runs */
  sint32 hiddenNeuronHigh[HLA_EVE_LRF_MAX_NUM_OF_VCOP_RUNS][HLA_EVE_LRF_NUM_RFS_PARALLEL];
  uint32 hiddenNeuronLow[HLA_EVE_LRF_MAX_NUM_OF_VCOP_RUNS][HLA_EVE_LRF_NUM_RFS_PARALLEL];
} WbufLrf_t;

typedef struct
{
  /* Tanh Look-up table; address must be 256-bit aligned, hence keep it at the beginning. */
  sint32 tanhLuTInterleaved[HLA_EVE_LRF_TANH_LUT_INTERLEAVED_SIZE];
  /* pre-processed image data, i.e. icon */
  uint8 preProcImage[HLA_EVE_LRF_ICON_SIZE];
  /* LRF input data like weights, offsets, etc. */
  RFs_t RFs;
  /* place where arguments for vcop are stored */
  uint16 argsBlockVcopCalcFeatures[HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_FEATURES];
  /* place where arguments for vcop are stored */
  uint16 argsBlockVcopCalcNeurons[HLA_EVE_LRF_NUM_ARGS_VCOP_CALC_NEURONS];
} IbufLLrf_t;

typedef struct
{
  /* vcop output after tanh LUT; list of all calculated and looked-up features per icon */
  sint32 tanhFeatureList[HLA_EVE_LRF_NUM_RFS_PARALLEL * (HLA_ICON_LRF_ICON_EFFECTIVE_WIDTH * HLA_ICON_LRF_ICON_EFFECTIVE_HEIGHT)];
} IbufHLrf_t;

/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DECLARATIONS                     */
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
                     );

#endif /* HLA_EVE_LRF_MAIN_H */
