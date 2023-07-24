  /*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_seg_main.c

  DESCRIPTION:            Segmentation on EVE, main routine

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-06-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_seg_main.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:52CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:44CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:07CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.19 2014/03/12 18:07:21CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:21 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.18 2014/03/03 16:51:36CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:36 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.17 2014/01/10 18:33:41CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:42 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.16 2013/12/05 17:47:55CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:56 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.15 2013/11/29 16:48:14CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved find max position to vcop
  CHANGES:                --- Added comments ---  uidv7867 [Nov 29, 2013 4:48:15 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.14 2013/10/31 17:43:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed missing seglines (now we are bit exact to dll)
  CHANGES:                smaller changes
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:43:08 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.13 2013/10/30 13:49:23CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed previous check-in
  CHANGES:                --- Added comments ---  uidv7867 [Oct 30, 2013 1:49:23 PM CET]
  CHANGES:                Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.12 2013/10/30 13:05:21CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved runtime a bit on vcop side
  CHANGES:                --- Added comments ---  uidv7867 [Oct 30, 2013 1:05:21 PM CET]
  CHANGES:                Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.11 2013/10/29 18:21:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:57 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.10 2013/10/16 14:59:18CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:19 PM CEST]
  CHANGES:                Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.9 2013/10/14 12:52:17CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Added DMEM section
  CHANGES:                --- Added comments ---  uidv7867 [Oct 14, 2013 12:52:17 PM CEST]
  CHANGES:                Change Package : 201097:1 http://mks-psad:7002/im/viewissue?selection=201097
  CHANGES:                Revision 1.8 2013/09/20 19:17:28CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Switch to alias memory view
  CHANGES:                --- Added comments ---  uidv7867 [Sep 20, 2013 7:17:28 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.7 2013/09/18 17:39:43CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Usage of memory sections
  CHANGES:                --- Added comments ---  uidv7867 [Sep 18, 2013 5:39:43 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.6 2013/08/26 14:44:54CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Possibility to do proper runtime measurement
  CHANGES:                --- Added comments ---  uidv7867 [Aug 26, 2013 2:44:55 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.5 2013/08/24 15:01:23CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimiztations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:23 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.4 2013/08/21 18:21:04CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved sorting on EVE quite a lot
  CHANGES:                --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:05 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.3 2013/08/15 14:16:51CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved EDMA handling on EVE side
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:16:51 PM CEST]
  CHANGES:                Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:17CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:18 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:50CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
  CHANGES:
**************************************************************************** */

#include <string.h>
#include "hla_eve_edma.h"
#include "hla_eve_seg_main.h"
#include "hla_eve_seg_interpret.h"
#include "hla_eve_seg_at_vcop.h"


/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/
/* check that number of parallel calculated RFs is aligned what vcop can do  */
#if(HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT != HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH)
  #error HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT and HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH are no longer aligned as expected.
#endif

/* maximum number of output elements from vcop */
#define HLA_EVE_SEG_VCOP_OUTPUT_MAX_NUM_ELEMS (HLA_SEG_MAX_NUM_SEG_LINES * 2u)


/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/

#pragma SET_DATA_SECTION ("ALGO_SCRATCHBUFF_DMEM")
static uint64 timeStartVcop;
static uint32 activeBufArp32;

/* Local variables that are copied at the end to DDR (output buffers) */
static HLASegLine_t localSegLineBuf[HLA_SEG_MAX_NUM_SEG_LINES];
static uint16 localFoundSegLineBuf[RTE_HLA_SEG_MAX_NUM_LEVELS];
#pragma SET_DATA_SECTION () /* End of ALGO_SCRATCHBUFF_DMEM */

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/

static uint16 HLAEveSegCheckArguments( const HLAEveSegParams_t *psHLAEveSegParams,
                                       const void              *pSrcBuf,
                                       const uint32             srcBufSize,
                                       const void              *pSegLineBuf,
                                       const uint32             SegLineBufSize,
                                       const void              *pNumFoundSegLines,
                                       const uint32             NumFoundSegLinesSize,
                                       const WbufSeg_t         *pWbuf
                                      );
static uint16 HLAEveSegInitVcop( const HLAEveSegParams_t *psHLAEveSegParams,
                                 const IbufLSeg_t        *pIbufL,
                                 IbufHSeg_t              *pIbufH
                                );
static inline void HLAEveSegIbufsToggle(void);
static inline void HLAEveSegTriggerVcop(uint16 *pArgsBlockVcopExec);
static inline void HLAEveSegWait4Vcop(HLAEveTimeMeas_t *pTimeMeas, uint16 currentBlock);


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/

uint16 HLAEveSegMain( const HLAEveSegParams_t *psHLAEveSegParams,
                      const void              *pSrcBuf,
                      const uint32             srcBufSize,
                      const void              *pSegLineBuf,
                      const uint32             SegLineBufSize,
                      const void              *pNumFoundSegLines,
                      const uint32             NumFoundSegLinesSize,
                      WbufSeg_t               *pWbuf,
                      IbufLSeg_t              *pIbufL,
                      IbufHSeg_t              *pIbufH,
                      HLAEveTimeMeas_t        *pTimeMeas
                     )
{
  /* Init return value with ok */
  uint16 retVal = HLA_EVE_SEG_RETURN_OK;

  retVal |= HLAEveSegCheckArguments( psHLAEveSegParams,
                                     pSrcBuf,
                                     srcBufSize,
                                     pSegLineBuf,
                                     SegLineBufSize,
                                     pNumFoundSegLines,
                                     NumFoundSegLinesSize,
                                     pWbuf
                                    );

  /* MAIN PART STARTS HERE */
  if (retVal == HLA_EVE_SEG_RETURN_OK)
  {
    uint64 timeStart;
    uint16 currentBlock;

    /* INIT PHASE */
    HLAEveTimeMeasStart(&timeStart);

    /* Set alias memory view */
    VCOP_SET_MEM_VIEW (ALIAS_128K_VIEW);
     /* Assign all buffers to the ARP32 and EDMA */
    VCOP_BUF_SWITCH_SET (WBUF_SYST, IBUFHB_SYST, IBUFHA_SYST, IBUFLB_SYST, IBUFLA_SYST);

    /* Prepare internal storage */
    memset((void*)localSegLineBuf, 0x00, sizeof(localSegLineBuf));

    /* Initialize edma  */
    HLAEveEdmaInit();
    /* Initialize vcop, i.e. copy parameters to WBUF, IBUFHA and IBUFHB, respectively */
    retVal |= HLAEveSegInitVcop( psHLAEveSegParams,
                                 pIbufL,
                                 pIbufH
                                );
    /* Initialize interpreter */
    HLAEveSegInterpretInit(pWbuf);


    pTimeMeas->dTimeEveSegInit_us = HLAEveTimeMeasEnd(timeStart);
    /* MAIN PHASE */

    HLAEveTimeMeasStart(&timeStart);
    /* ----------------------------------------------------------------------- */
    /* Prologue:                                                               */
    /* ----------------------------------------------------------------------- */
    /* Set IBUFAs as first buffer to be filled by edma */
    activeBufArp32 = HLA_EVE_IBUFA;

    /* Configure and trigger EDMA to fill IBUFA and wait until it has finished */
    HLAEveEdmaSegCfgInputTransfer(psHLAEveSegParams, pSrcBuf, pIbufL->srcBufRawData, 0u);
#ifdef HLA_EVE_DEBUG
    memset((void*)pIbufL->srcBufRawData, 0x55, sizeof(pIbufL->srcBufRawData));
    memset((void*)pIbufH->tempBufBinnedData, 0x55, sizeof(pIbufH->tempBufBinnedData));
    memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
    HLAEveEdmaTriggerDma();
    HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveSegMainEdma_us);
    /* Toggle IBUFs so that EDMA can write to IBUFB and VCOP can work on IBUFA  */
    HLAEveSegIbufsToggle();

    /* Configure and trigger EDMA to fill IBUFB */
    HLAEveEdmaSegCfgInputTransfer(psHLAEveSegParams, pSrcBuf, pIbufL->srcBufRawData, 1u);
#ifdef HLA_EVE_DEBUG
    memset((void*)(pIbufL->srcBufRawData + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufL->srcBufRawData));
    memset((void*)(pIbufH->tempBufBinnedData + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->tempBufBinnedData));
    memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS) + (HLA_EVE_IBUFS_OFFSET / 2u)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
    HLAEveEdmaTriggerDma();
#ifdef HLA_EVE_SERIAL_MODE
    HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveSegMainEdma_us);
#endif
    /* Trigger VCOP to work on IBUFA and wait until it has finished*/
    HLAEveSegTriggerVcop(pIbufH->argsBlockVcopExec);
    HLAEveSegWait4Vcop(pTimeMeas, 0);
    /* Wait until DMA has finished */
#ifndef HLA_EVE_SERIAL_MODE
    HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveSegMainEdma_us);
#endif

    /* ------------------------------------------------------------------------ */
    /* Processing loop:                                                         */
    /* The next 16 columns are transfered by the EDMA controller.               */
    /* The former 8 binned columns are segmented in parallel by the VCOP.       */
    /* As last step the arp32 interprets the VCOP results and fills             */
    /* the detected lines into the related HLA structures.                      */
    /* ------------------------------------------------------------------------ */
    for (currentBlock = 0u; currentBlock < (psHLAEveSegParams->processingWidth / HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH) - 2u; currentBlock++)
    {
      /* Toggle IBUFs */
      HLAEveSegIbufsToggle();

      /* Configure and trigger EDMA */
      HLAEveEdmaSegCfgInputTransfer(psHLAEveSegParams, pSrcBuf, pIbufL->srcBufRawData, currentBlock + 2u);
#ifdef HLA_EVE_DEBUG
      if (activeBufArp32 == HLA_EVE_IBUFA)
      {
        memset((void*)pIbufL->srcBufRawData, 0x55, sizeof(pIbufL->srcBufRawData));
      }
      else
      {
        memset((void*)(pIbufL->srcBufRawData + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufL->srcBufRawData));
      }
#endif
      HLAEveEdmaTriggerDma();
#ifdef HLA_EVE_SERIAL_MODE
      HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveSegMainEdma_us);
#endif

      /* Trigger VCOP to start segmentation */
      HLAEveSegTriggerVcop(pIbufH->argsBlockVcopExec);
#ifdef HLA_EVE_SERIAL_MODE
      HLAEveSegWait4Vcop(pTimeMeas, currentBlock + HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH);
#endif

      /* Interpret vcop output and fill the HLA-structures */
      if (activeBufArp32 == HLA_EVE_IBUFA)
      {
        HLAEveSegInterpretSaveVcopOut( psHLAEveSegParams,
                                       currentBlock,
                                       pIbufH->destBufSeglines,
                                       pIbufH->destBufSumSeglines,
                                       pWbuf,
                                       pTimeMeas
                                      );
#ifdef HLA_EVE_DEBUG
        memset((void*)pIbufH->destBufSeglines, 0x55, sizeof(pIbufH->destBufSeglines));
        memset((void*)pIbufH->destBufSumSeglines, 0x55, sizeof(pIbufH->destBufSumSeglines));
        memset((void*)pIbufH->tempBufBinnedData, 0x55, sizeof(pIbufH->tempBufBinnedData));
        memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
      }
      else
      {
        HLAEveSegInterpretSaveVcopOut( psHLAEveSegParams,
                                       currentBlock,
                                       pIbufH->destBufSeglines + (HLA_EVE_IBUFS_OFFSET / 4u),
                                       pIbufH->destBufSumSeglines + (HLA_EVE_IBUFS_OFFSET / 2u),
                                       pWbuf,
                                       pTimeMeas
                                      );
#ifdef HLA_EVE_DEBUG
        memset((void*)(pIbufH->destBufSeglines + (HLA_EVE_IBUFS_OFFSET / 4u)), 0x55, sizeof(pIbufH->destBufSeglines));
        memset((void*)(pIbufH->destBufSumSeglines + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->destBufSumSeglines));
        memset((void*)(pIbufH->tempBufBinnedData + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->tempBufBinnedData));
        memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS) + (HLA_EVE_IBUFS_OFFSET / 2u)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
      }
      /* Wait until VCOP and EDMA have finished */
#ifndef HLA_EVE_SERIAL_MODE
      HLAEveSegWait4Vcop(pTimeMeas, currentBlock + 1u);
      HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveSegMainEdma_us);
#endif
    }

    /* ----------------------------------------------------------------------- */
    /* Epilogue:                                                               */
    /* ----------------------------------------------------------------------- */

    /* Toggle IBUFs */
    HLAEveSegIbufsToggle();

    /* Trigger VCOP to start segmentation */
    HLAEveSegTriggerVcop(pIbufH->argsBlockVcopExec);

    /* Interpret vcop output and fill the HLA-structures */
    if (activeBufArp32 == HLA_EVE_IBUFA)
    {
      HLAEveSegInterpretSaveVcopOut( psHLAEveSegParams,
                                     currentBlock,
                                     pIbufH->destBufSeglines,
                                     pIbufH->destBufSumSeglines,
                                     pWbuf,
                                     pTimeMeas
                                    );
#ifdef HLA_EVE_DEBUG
        memset((void*)pIbufH->destBufSeglines, 0x55, sizeof(pIbufH->destBufSeglines));
        memset((void*)pIbufH->destBufSumSeglines, 0x55, sizeof(pIbufH->destBufSumSeglines));
        memset((void*)pIbufH->tempBufBinnedData, 0x55, sizeof(pIbufH->tempBufBinnedData));
        memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
    }
    else
    {
      HLAEveSegInterpretSaveVcopOut( psHLAEveSegParams,
                                     currentBlock,
                                     pIbufH->destBufSeglines + (HLA_EVE_IBUFS_OFFSET / 4u),
                                     pIbufH->destBufSumSeglines + (HLA_EVE_IBUFS_OFFSET / 2u),
                                     pWbuf,
                                     pTimeMeas
                                    );
#ifdef HLA_EVE_DEBUG
        memset((void*)(pIbufH->destBufSeglines + (HLA_EVE_IBUFS_OFFSET / 4u)), 0x55, sizeof(pIbufH->destBufSeglines));
        memset((void*)(pIbufH->destBufSumSeglines + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->destBufSumSeglines));
        memset((void*)(pIbufH->tempBufBinnedData + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->tempBufBinnedData));
        memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS) + (HLA_EVE_IBUFS_OFFSET / 2u)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
    }
    /* Wait until VCOP has finished */
    HLAEveSegWait4Vcop(pTimeMeas, currentBlock + 1u);

    /* Toggle IBUFs */
    HLAEveSegIbufsToggle();
    /* Interpret vcop output and fill the HLA-structures */
    if (activeBufArp32 == HLA_EVE_IBUFA)
    {
      HLAEveSegInterpretSaveVcopOut( psHLAEveSegParams,
                                     currentBlock + 1u,
                                     pIbufH->destBufSeglines,
                                     pIbufH->destBufSumSeglines,
                                     pWbuf,
                                     pTimeMeas
                                    );
#ifdef HLA_EVE_DEBUG
        memset((void*)pIbufH->destBufSeglines, 0x55, sizeof(pIbufH->destBufSeglines));
        memset((void*)pIbufH->destBufSumSeglines, 0x55, sizeof(pIbufH->destBufSumSeglines));
        memset((void*)pIbufH->tempBufBinnedData, 0x55, sizeof(pIbufH->tempBufBinnedData));
        memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
    }
    else
    {
      HLAEveSegInterpretSaveVcopOut( psHLAEveSegParams,
                                     currentBlock + 1u,
                                     pIbufH->destBufSeglines + (HLA_EVE_IBUFS_OFFSET / 4u),
                                     pIbufH->destBufSumSeglines + (HLA_EVE_IBUFS_OFFSET / 2u),
                                     pWbuf,
                                     pTimeMeas
                                    );
#ifdef HLA_EVE_DEBUG
        memset((void*)(pIbufH->destBufSeglines + (HLA_EVE_IBUFS_OFFSET / 4u)), 0x55, sizeof(pIbufH->destBufSeglines));
        memset((void*)(pIbufH->destBufSumSeglines + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->destBufSumSeglines));
        memset((void*)(pIbufH->tempBufBinnedData + (HLA_EVE_IBUFS_OFFSET / 2u)), 0x55, sizeof(pIbufH->tempBufBinnedData));
        memset((void*)(pIbufH->tempBufBinnedData + ((psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS) + (HLA_EVE_IBUFS_OFFSET / 2u)), 0, sizeof(pIbufH->tempBufZeroPix));
#endif
    }
    pTimeMeas->dTimeEveSegMain_us = HLAEveTimeMeasEnd(timeStart);

    /* EXIT PHASE */
    HLAEveTimeMeasStart(&timeStart);

    /* Copy relevant raw seglines into local segline buffer */
    HLAEveSegInterpretStoreSeglines( psHLAEveSegParams,
                                     pWbuf,
                                     localSegLineBuf,
                                     localFoundSegLineBuf,
                                     pTimeMeas
                                    );

    /* Copy EVE results back to DDR for DSP via EDMA */
    retVal |= HLAEveEdmaCfgLinked1d1d( (void*)localSegLineBuf,
                                       pSegLineBuf,
                                       sizeof(localSegLineBuf),
                                       1u
                                      );
    retVal |= HLAEveEdmaCfg1d1d( (void*)localFoundSegLineBuf,
                                 pNumFoundSegLines,
                                 sizeof(localFoundSegLineBuf),
                                 2u
                                );
    /* Trigger EDMA and wait for it */
    HLAEveEdmaTriggerDma();
    HLAEveEdmaWait4Dma(&pTimeMeas->dTimeEveSegMainEdma_us);


    /* Reset memory view to flat view since this is the default view */
    VCOP_SET_MEM_VIEW (MEM_BUF_VIEW);
    /* Clear edma event registers */
    HLAEveEdmaTeardownDma();

    DBG(("----------------------EDMA_CHAIN-------------------------------\n"));
    DBG((" one frame done \n"));
    DBG(("---------------------------------------------------------------\n"));
    pTimeMeas->dTimeEveSegExit_us = HLAEveTimeMeasEnd(timeStart);
  }

  return retVal;
}


/*---------------------------------------------------*/
/*  LOCAL FUNCTIONS DEFINITIONS                      */
/*---------------------------------------------------*/

static uint16 HLAEveSegCheckArguments( const HLAEveSegParams_t *psHLAEveSegParams,
                                       const void              *pSrcBuf,
                                       const uint32             srcBufSize,
                                       const void              *pSegLineBuf,
                                       const uint32             SegLineBufSize,
                                       const void              *pNumFoundSegLines,
                                       const uint32             NumFoundSegLinesSize,
                                       const WbufSeg_t         *pWbuf
                                      )
{
  uint16 retVal = HLA_EVE_SEG_RETURN_OK;

  /* Check input parameters */
  if(   (psHLAEveSegParams->processingHeight % HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT != 0)
     || (psHLAEveSegParams->processingHeight > HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT)
    )
  {
    /* roi height is not modulo 2 which is needed due to binning
     * OR greater than max supported image height
     */
    retVal |= HLA_EVE_SEG_RETURN_ERR_HEIGHT;
  }
  if(   (psHLAEveSegParams->processingWidth % HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT != 0)
     || (psHLAEveSegParams->processingWidth > HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH)
    )
  {
    /* roi width is not modulo 16 which is needed due to binning of 8 pixels in parallel
     * OR greater than max supported image width
     */
    retVal |= HLA_EVE_SEG_RETURN_ERR_WIDTH;
  }
  if(   (srcBufSize < (psHLAEveSegParams->rowOffset * (psHLAEveSegParams->processingHeight - 1u) + psHLAEveSegParams->processingWidth)) * 2u
     || (!pSrcBuf)
    )
  {
    /* input buffer (raw bayer image) is smaller than what we would expect
     * We want to see from start until end of roi at least
     * OR pointer is invalid
     */
    retVal |= HLA_EVE_SEG_RETURN_ERR_SRC_BUF;
  }
  if(   (SegLineBufSize < sizeof(localSegLineBuf))
     || (!pSegLineBuf)
    )
  {
    /* output buffer is smaller than our internal segline buffer
     * OR pointer is invalid
     */
    retVal |= HLA_EVE_SEG_RETURN_ERR_SEG_BUF;
  }
  if(   (NumFoundSegLinesSize < sizeof(localFoundSegLineBuf))
     || (!pNumFoundSegLines)
    )
  {
    retVal |= HLA_EVE_SEG_RETURN_ERR_FOUND_SEGLINES_BUF;
  }
  if(psHLAEveSegParams->maxSeglines > HLA_SEG_MAX_NUM_SEG_LINES)
  {
    /* maximum number of to be stored seglines is greater than buffer */
    retVal |= HLA_EVE_SEG_RETURN_ERR_MAX_SEG_LINES;
  }
  return retVal;
}

static uint16 HLAEveSegInitVcop( const HLAEveSegParams_t *psHLAEveSegParams,
                                 const IbufLSeg_t        *pIbufL,
                                 IbufHSeg_t              *pIbufH
                                )
{
  uint32 numParamRegsVcop;
  uint16 retVal = 0;
  uint32 i;
  const uint32 columnIndexTab[] = {0x00000000, 0x10000000, 0x20000000, 0x30000000,
                                   0x40000000, 0x50000000, 0x60000000, 0x70000000};
  const uint16 offsetBinndedDataEnd = (psHLAEveSegParams->processingHeight / 2u) * HLA_EVE_SEG_NUM_BINNED_COLUMNS;

  /* Register argument list at vcop side in IBUFHA */
  numParamRegsVcop = HLAEveSegVcopExec_init( (uint16*)pIbufL->srcBufRawData,
                                             (uint16*)pIbufH->tempBufBinnedData,
                                             (uint32*)pIbufH->columnIndexTab,
                                             (uint16*)pIbufH->thresholdTab,
                                             psHLAEveSegParams->thresholdLedUpper,
                                             psHLAEveSegParams->thresholdLedLower,
                                             (uint16*)pIbufH->binnedPixelMask,
                                             psHLAEveSegParams->processingHeight / 2u,
                                             RTE_HLA_SEG_MAX_NUM_LEVELS,
                                             (uint16*)pIbufH->destBufSumSeglines,
                                             (uint32*)pIbufH->destBufSeglines,
                                             /* place to store above parameters */
                                             (uint16*)pIbufH->argsBlockVcopExec
                                            );
  /* copy column index tab to buffer where VCOP can access them once it is called */
  memcpy((void*)pIbufH->columnIndexTab, (void*)columnIndexTab, sizeof(pIbufH->columnIndexTab));
  /* copy threshold tab to buffer where VCOP can access them once it is called */
  memcpy((void*)pIbufH->thresholdTab, (void*)psHLAEveSegParams->thresholdTab, sizeof(pIbufH->thresholdTab));
  /* Pixels mask for LEDs is same as meta threshold. For all other levels it's just the inverse (bit wise) */
  pIbufH->binnedPixelMask[0] = HLA_EVE_SEG_LED_META_THRESHOLD;
  for (i = 1; i < RTE_HLA_SEG_MAX_NUM_LEVELS; i++)
  {
    pIbufH->binnedPixelMask[i] = HLA_EVE_SEG_LED_META_THRESHOLD ^ 0xFFFF;
  }
  /* Zero pixels needed after end of binned pixel data in order to close still open seglines */
  memset((void*)(pIbufH->tempBufBinnedData + offsetBinndedDataEnd), 0, sizeof(pIbufH->tempBufZeroPix));

  /* Register argument list at vcop side in IBUFHB */
  numParamRegsVcop = HLAEveSegVcopExec_init( (uint16*)pIbufL->srcBufRawData,
                                             (uint16*)pIbufH->tempBufBinnedData,
                                             (uint32*)pIbufH->columnIndexTab,
                                             (uint16*)pIbufH->thresholdTab,
                                             psHLAEveSegParams->thresholdLedUpper,
                                             psHLAEveSegParams->thresholdLedLower,
                                             (uint16*)pIbufH->binnedPixelMask,
                                             psHLAEveSegParams->processingHeight / 2u,
                                             RTE_HLA_SEG_MAX_NUM_LEVELS,
                                             (uint16*)pIbufH->destBufSumSeglines,
                                             (uint32*)pIbufH->destBufSeglines,
                                             /* place to store above parameters */
                                             (uint16*)(pIbufH->argsBlockVcopExec + (HLA_EVE_IBUFS_OFFSET / 2u))
                                            );
  /* copy column index tab to buffer where VCOP can access them once it is called */
  memcpy((void*)(pIbufH->columnIndexTab + (HLA_EVE_IBUFS_OFFSET / 4u)), (void*)columnIndexTab, sizeof(pIbufH->columnIndexTab));
  /* copy threshold tab to buffer where VCOP can access them once it is called */
  memcpy((void*)(pIbufH->thresholdTab + (HLA_EVE_IBUFS_OFFSET / 2u)) , (void*)psHLAEveSegParams->thresholdTab, sizeof(pIbufH->thresholdTab));
  /* Pixels mask for LEDs is same as meta threshold. For all other levels it's just the inverse (bit wise) */
  (pIbufH->binnedPixelMask + (HLA_EVE_IBUFS_OFFSET / 2u))[0] = HLA_EVE_SEG_LED_META_THRESHOLD;
  for (i = 1; i < RTE_HLA_SEG_MAX_NUM_LEVELS; i++)
  {
    (pIbufH->binnedPixelMask + (HLA_EVE_IBUFS_OFFSET / 2u))[i] = HLA_EVE_SEG_LED_META_THRESHOLD ^ 0xFFFF;
  }
  /* Zero pixels needed after end of binned pixel data in order to close still open seglines */
  memset((void*)(pIbufH->tempBufBinnedData + offsetBinndedDataEnd + (HLA_EVE_IBUFS_OFFSET / 2u)), 0, sizeof(pIbufH->tempBufZeroPix));

  if (numParamRegsVcop != HLA_EVE_SEG_NUM_ARGS_VCOP_EXEC)
  {
    DBG(("!!! Number of argument registers returned from vcop (%d) not matching corresponding buffer size for 'Exec' call: %d !!!\n", numParamRegsVcop, HLA_EVE_SEG_NUM_ARGS_VCOP_EXEC));
    retVal = HLA_EVE_SEG_RETURN_ERR_VCOP_PARAMS;
  }

  return retVal;

}


static inline void HLAEveSegIbufsToggle(void)
{
  if (activeBufArp32 == HLA_EVE_IBUFA)
  {
    VCOP_BUF_SWITCH_SET(WBUF_SYST, IBUFHB_SYST, IBUFLB_SYST, IBUFHA_VCOP, IBUFLA_VCOP);
  }
  else
  {
    VCOP_BUF_SWITCH_SET(WBUF_SYST, IBUFHB_VCOP, IBUFLB_VCOP, IBUFHA_SYST, IBUFLA_SYST);
  }
  activeBufArp32 = (activeBufArp32 ^ 0x1);
}

static inline void HLAEveSegTriggerVcop(uint16 *pArgsBlockVcopExec)
{
  HLAEveTimeMeasStart(&timeStartVcop);
  /* Call vcop to start segmentation*/
  HLAEveSegVcopExec_vloops(pArgsBlockVcopExec);
}

static inline void HLAEveSegWait4Vcop(HLAEveTimeMeas_t *pTimeMeas, uint16 currentBlock)
{
  /* Wait until vcop returns */
  _vcop_vloop_done();
  DBG(("VCOP called for processing from column %d to column %d\n", (currentBlock * HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH) + 1u, (currentBlock + 1u) * HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH));

  pTimeMeas->dTimeEveSegMainVcop_us += HLAEveTimeMeasEnd(timeStartVcop);
}
