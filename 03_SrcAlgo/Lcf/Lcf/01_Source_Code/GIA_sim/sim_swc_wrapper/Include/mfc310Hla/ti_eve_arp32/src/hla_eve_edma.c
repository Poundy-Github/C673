/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_edma.c

  DESCRIPTION:            EDMA functions for ARP32/EVE

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-05-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_edma.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:51CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:41CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:05CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.7 2014/03/12 18:07:42CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:43 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.6 2014/02/06 16:02:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:52 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.5 2014/01/10 18:33:50CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:50 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.4 2013/10/31 17:43:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed missing seglines (now we are bit exact to dll)
  CHANGES:                smaller changes
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:43:09 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.3 2013/10/30 13:49:24CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed previous check-in
  CHANGES:                --- Added comments ---  uidv7867 [Oct 30, 2013 1:49:24 PM CET]
  CHANGES:                Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.2 2013/10/29 18:21:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:59 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.1 2013/10/16 15:00:33CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.6 2013/09/20 19:17:29CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Switch to alias memory view
  CHANGES:                --- Added comments ---  uidv7867 [Sep 20, 2013 7:17:29 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.5 2013/09/18 17:39:43CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Usage of memory sections
  CHANGES:                --- Added comments ---  uidv7867 [Sep 18, 2013 5:39:43 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.4 2013/08/24 15:01:25CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimiztations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:26 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.3 2013/08/15 14:16:55CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved EDMA handling on EVE side
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:16:55 PM CEST]
  CHANGES:                Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:22CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:23 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:49CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
  CHANGES:
**************************************************************************** */

#include <assert.h>
#include "hla_eve_edma.h"
//#include "hla_eve_seg_main.h"
#include "hla_eve.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/

/* SEGMENTATION */


/* LRF */

/*---------------------------------------------------*/
/*  LOCAL VARIABLES                                  */
/*---------------------------------------------------*/

#pragma SET_DATA_SECTION ("ALGO_SCRATCHBUFF_DMEM")
static CSL_EdmaccRegsOvly HLAEveEdmaChannelCtrl;
static volatile uint32 *HLAEveEdmaTriggerParam;
static uint32 HLAEveEdmaOpt1d1d;
static uint32 HLAEveEdmaOpt1d1dLinkChain;
static uint32 HLAEveEdmaOpt2d1d;
static uint64 timeStartEdma;
#pragma SET_DATA_SECTION () /* End of ALGO_SCRATCHBUFF_DMEM */

/* SEGMENTATION */


/* LRF */

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/


/* Use pack2 function if running code on EVE  */
static inline uint32 HLAEveSegEdmaPack2 (uint16 hi, uint16 lo);


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITONS                       */
/*---------------------------------------------------*/


void HLAEveEdmaInit(void)
{
  uint32 restoreInterrupts;

  /*-------------------------------------------------------------------*/
  /*  Anchor HLAEveEdmaChannelCtrl to the start of the EDMA CC0, we have */
  /*  only one Channel Controller so it is CC0.                        */
  /*-------------------------------------------------------------------*/
  HLAEveEdmaChannelCtrl =  CSL_EDMACC_0_REGS;

  DBG(("HLAEveEdmaChannelCtrl:0x%.8x \n", HLAEveEdmaChannelCtrl));

  assert ((uint32)HLAEveEdmaChannelCtrl == 0x400A0000);

  /*---------------------------------------------------------------*/
  /*  Disable interrupts during the entire period of IDMA          */
  /*  registers programming and transfer for correct operation.    */
  /*  The IDMA is a shared resource and other threads should wait  */
  /*  for the completion. Note we can disable this disable of      */
  /*  interrupts later, as we will be in an ISR, and therefore     */
  /*  interrupts cannot happen anyway.                             */
  /*---------------------------------------------------------------*/
  restoreInterrupts   = _disable_interrupts();

  /*-------------------------------------------------------------------*/
  /* We choose dma_attr = EDMA_CHAN; evt_no = 0; tcc_no = 1;           */
  /*  HLAEveEdmaSegTriggerParam = 0x400A4020; num_param = 8;           */
  /*-------------------------------------------------------------------*/

  /* HLAEveEdmaChannelCtrl->QUETCMAP  =                                  */
  /*   (CSL_EDMACC_CCCFG_NUM_TC_1 << CSL_EDMACC_QUETCMAP_TCNUMQ0_SHIFT)*/
  /* | (CSL_EDMACC_CCCFG_NUM_TC_2 << CSL_EDMACC_QUETCMAP_TCNUMQ1_SHIFT)*/

  /* #define CSL_QUE_PRI0     0                                        */
  /* #define CSL_QUE_PRI3     3                                        */
  /* HLAEveEdmaChannelCtrl->QUEPRI    =                                  */
  /*   (CSL_QUE_PRI3  <<  CSL_EDMACC_QUEPRI_PRIQ0_SHIFT)               */
  /* | (CSL_QUE_PRI0  <<  CSL_EDMACC_QUEPRI_PRIQ1_SHIFT)               */

  /* HLAEveEdmaChannelCtrl->QWMTHRA  = (CSL_EDMACC_QWMTHRA_RESETVAL & 0xFFFF); */

  HLAEveEdmaChannelCtrl->QUETCMAP  = 0x00000010;
  HLAEveEdmaChannelCtrl->QUEPRI    = 0x00000003;
  HLAEveEdmaChannelCtrl->QWMTHRA   = 0x00001010;
  HLAEveEdmaChannelCtrl->DCHMAP[0] = 0x00000020;
  HLAEveEdmaChannelCtrl->DMAQNUM[0] = 0x00000000;

  /*---------------------------------------------------------------*/
  /* Options field for 1D src to 1D dst.                           */
  /*---------------------------------------------------------------*/
  /*
  chan       =  0x0;
  itccEn     =  CSL_EDMACC_OPT_ITCCHEN_DISABLE;
  tccEn      =  CSL_EDMACC_OPT_TCCHEN_DISABLE;
  itcintEn   =  CSL_EDMACC_OPT_ITCINTEN_DISABLE; 
  tcintEn    =  CSL_EDMACC_OPT_TCINTEN_ENABLE;
  tcc        =  dma_state_struct.tcc_val[chan];
  tccMode    =  CSL_EDMACC_OPT_TCCMODE_NORMAL; 
  fwid       =  CSL_EDMACC_OPT_FWID_8;
  stat       =  CSL_EDMACC_OPT_STATIC_STATIC;
  syncDim    =  CSL_EDMACC_OPT_SYNCDIM_ASYNC;
  dam        =  CSL_EDMACC_OPT_DAM_INCR;
  sam        =  CSL_EDMACC_OPT_SAM_INCR;
  CSL_EDMA_OPT_MAKE
    (itccEn,tccEn,itcintEn,tcintEn,tcc,tccMode,fwid,stat,syncDim,dam,sam);
   */   
  HLAEveEdmaOpt1d1d = 0x00101008;

  /*---------------------------------------------------------------*/
  /*  Options field for 1D -> 1D with linking and chaining.        */
  /*---------------------------------------------------------------*/
/*
  chan       =  0x0;
  itccEn     =  CSL_EDMACC_OPT_ITCCHEN_DISABLE;
  tccEn      =  CSL_EDMACC_OPT_TCCHEN_ENABLE;
  itcintEn   =  CSL_EDMACC_OPT_ITCINTEN_DISABLE;
  tcintEn    =  CSL_EDMACC_OPT_TCINTEN_DISABLE;
  evt_no     =  dma_state_struct.physical_chan[chan];
  tccMode    =  CSL_EDMACC_OPT_TCCMODE_EARLY;
  fwid       =  CSL_EDMACC_OPT_FWID_8;
  stat       =  CSL_EDMACC_OPT_STATIC_NORMAL;
  syncDim    =  CSL_EDMACC_OPT_SYNCDIM_ASYNC;
  dam        =  CSL_EDMACC_OPT_DAM_INCR;
  sam        =  CSL_EDMACC_OPT_SAM_INCR;
  CSL_EDMA_OPT_MAKE
   (itccEn,tccEn,itcintEn,tcintEn,evt_no,tccMode,fwid,stat,syncDim,dam,sam);
*/
  HLAEveEdmaOpt1d1dLinkChain = 0x00400800;

  /*---------------------------------------------------------------*/
  /* Options field for 2D src to 1D dst.                           */
  /*---------------------------------------------------------------*/
  /*
  chan       =  0x0;
  itccEn     =  CSL_EDMACC_OPT_ITCCHEN_DISABLE;
  tccEn      =  CSL_EDMACC_OPT_TCCHEN_DISABLE;
  itcintEn   =  CSL_EDMACC_OPT_ITCINTEN_DISABLE;
  tcintEn    =  CSL_EDMACC_OPT_TCINTEN_ENABLE;
  tcc        =  dma_state_struct.tcc_val[chan];
  tccMode    =  CSL_EDMACC_OPT_TCCMODE_NORMAL;
  fwid       =  CSL_EDMACC_OPT_FWID_8;
  stat       =  CSL_EDMACC_OPT_STATIC_STATIC;
  syncDim    =  CSL_EDMACC_OPT_SYNCDIM_ABSYNC;
  dam        =  CSL_EDMACC_OPT_DAM_INCR;
  sam        =  CSL_EDMACC_OPT_SAM_INCR;
  CSL_EDMA_OPT_MAKE
    (itccEn,tccEn,itcintEn,tcintEn,tcc,tccMode,fwid,stat,syncDim,dam,sam);
   */
  HLAEveEdmaOpt2d1d = 0x0010100C;

  _restore_interrupts(restoreInterrupts);
}

void HLAEveEdmaTriggerDma(void)
{
  HLAEveTimeMeasStart(&timeStartEdma);
  /* DMA_SUBMIT */
  HLAEveEdmaChannelCtrl->ESR  = (CSL_EDMACC_ESR_E0_SET << 0x00000000);
}

void HLAEveEdmaWait4Dma(uint16 *pTimeMeasEntry)
{
  /*---------------------------------------------------------------*/
  /* clear either IPR/IPRH.                                        */
  /*---------------------------------------------------------------*/
  /* DMA_WAIT */
  /* tcc value is here 0x00000001 */
  while(!(HLAEveEdmaChannelCtrl->IPR & (0x1 << 0x00000001)));
  HLAEveEdmaChannelCtrl->ICR  = (0x1 << 0x00000001);

  assert (HLAEveEdmaChannelCtrl->IPR == 0);
  assert (HLAEveEdmaChannelCtrl->CCERR == 0);
  *pTimeMeasEntry += HLAEveTimeMeasEnd(timeStartEdma);
}

void HLAEveEdmaTeardownDma(void)
{
  HLAEveEdmaChannelCtrl->EECR = 0xFFFFFFFF;
}

uint16 HLAEveEdmaCfg1d1d( const void* pSrc,
                          const void* pDst,
                          const uint16 numBytes,
                          const uint8  channel
                         )
{
  uint16 retVal = HLA_EVE_SEG_RETURN_OK;

  if (   channel > 0u
      && channel < 512u  /* according to declaration of PARAMENTRY type in cslr_edmacc.h */
     )
  {
    uint32 restoreInterrupts;

    restoreInterrupts       = _disable_interrupts();
    HLAEveEdmaTriggerParam  = (volatile uint32 *) (&HLAEveEdmaChannelCtrl->PARAMENTRY[channel]);

    /* configure edma */
    HLAEveEdmaTriggerParam[0]  = HLAEveEdmaOpt1d1d;                  /* OPT: option word, basic edma configuration, i.e. 1d->1d in this case*/
    HLAEveEdmaTriggerParam[1]  = (uint32)pSrc;                       /* SRC: pointer to source buffer */
    HLAEveEdmaTriggerParam[2]  = HLAEveSegEdmaPack2(1u, numBytes);   /* 1st (BCNT): height of block to be transfered; 2nd (ACNT): width of block to be transfered */
    HLAEveEdmaTriggerParam[3]  = (uint32)pDst;                       /* DST: pointer to destination buffer */
    HLAEveEdmaTriggerParam[4]  = 0u;                                 /* 1st (DSTBIDX): offset to next block; 2nd (SRCBIDX): offset to next row */
    HLAEveEdmaTriggerParam[5]  = HLAEveSegEdmaPack2(1u, 0xFFFF);     /* 1st (BCNTRLD): length of block; 2nd (LINK): next edma channel, in this case no linking, i.e. 0xFFFF */
    HLAEveEdmaTriggerParam[6]  = 0u;                                 /* only needed for 3rd dimension */
    HLAEveEdmaTriggerParam[7]  = 1u;                                 /* CCNT: no 3rd dimension in our case */

    /* Restore the previous state. */
    _restore_interrupts(restoreInterrupts);
  }
  else
  {
      DBG(("Channel for 1d_1d transfer is out of range!\n"));
      retVal = HLA_EVE_EDMA_RETURN_ERR_CFG_1D1D;
  }

  return retVal;
}


uint16 HLAEveEdmaCfgLinked1d1d( const void* pSrc,
                                const void* pDst,
                                const uint16 numBytes,
                                const uint8  channel
                               )
{
  uint16 retVal = HLA_EVE_SEG_RETURN_OK;

  if (   channel > 0u
      && channel < (512u - 1u)  /* according to declaration of PARAMENTRY type in cslr_edmacc.h; -1 due to linking */
     )
  {
    uint32 restoreInterrupts;
    uint32 linkAddr;

    restoreInterrupts       = _disable_interrupts();
    HLAEveEdmaTriggerParam  = (volatile uint32 *) (&HLAEveEdmaChannelCtrl->PARAMENTRY[channel]);
    linkAddr                = (uint32) (&HLAEveEdmaChannelCtrl->PARAMENTRY[channel + 1u]);
    linkAddr               &= 0xFFFF;                                /* clean option word */

    /* configure edma */
    HLAEveEdmaTriggerParam[0]  = HLAEveEdmaOpt1d1dLinkChain;         /* OPT: option word, basic edma configuration, i.e. 1d->1d linked chain in this case*/
    HLAEveEdmaTriggerParam[1]  = (uint32)pSrc;                       /* SRC: pointer to source buffer */
    HLAEveEdmaTriggerParam[2]  = HLAEveSegEdmaPack2(1u, numBytes);   /* 1st (BCNT): height of block to be transfered; 2nd (ACNT): width of block to be transfered */
    HLAEveEdmaTriggerParam[3]  = (uint32)pDst;                       /* DST: pointer to destination buffer */
    HLAEveEdmaTriggerParam[4]  = 0u;                                 /* 1st (DSTBIDX): offset to next block; 2nd (SRCBIDX): offset to next row */
    HLAEveEdmaTriggerParam[5]  = HLAEveSegEdmaPack2(1u, linkAddr);   /* 1st (BCNTRLD): length of block; 2nd (LINK): next edma channel */
    HLAEveEdmaTriggerParam[6]  = 0u;                                 /* only needed for 3rd dimension */
    HLAEveEdmaTriggerParam[7]  = 1u;                                 /* CCNT: no 3rd dimension in our case */

    /* Restore the previous state. */
    _restore_interrupts(restoreInterrupts);
  }
  else
  {
      DBG(("Channel for linked 1d_1d transfer is out of range!\n"));
      retVal = HLA_EVE_EDMA_RETURN_ERR_CFG_LINKED_1D1D;
  }

  return retVal;
}


/* SEGMENTATION */
uint16 HLAEveEdmaSegCfgInputTransfer( const HLAEveSegParams_t *psHLAEveSegParams,
                                      const uint16            *pSrcBuf,
                                      const uint16            *pDstBuf,
                                      const uint8              blockCounter
                                     )
{
  uint32 restoreInterrupts;
  uint32 inputBufOffset;
  
  uint16 retVal = HLA_EVE_SEG_RETURN_OK;

  /*---------------------------------------------------------------*/
  /*  Disable interrupts during the entire period of IDMA          */
  /*  registers programming and transfer for correct operation.    */
  /*  The IDMA is a shared resource and other threads should wait  */
  /*  for the completion. Note we can disable this disable of      */
  /*  interrupts later, as we will be in an ISR, and therefore     */
  /*  interrupts cannot happen anyway.                             */
  /*---------------------------------------------------------------*/
  restoreInterrupts   = _disable_interrupts();

  inputBufOffset = blockCounter * HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH;
  /* Check input buffer overflow */
  if (inputBufOffset > psHLAEveSegParams->processingWidth)
  {
      DBG(("Input buffer offset is bigger than input buffer width!\n"));
      retVal = HLA_EVE_EDMA_RETURN_ERR_CFG_SEG_IN;
  }
  HLAEveEdmaTriggerParam  = (volatile uint32 *) (&HLAEveEdmaChannelCtrl->PARAMENTRY[1]);

  HLAEveEdmaTriggerParam[0] = (uint32) (HLAEveEdmaOpt2d1d);                                                                    /* OPT: option word, basic edma configuration, i.e. 2d->1d in this case*/
  HLAEveEdmaTriggerParam[1] = (uint32) (pSrcBuf + inputBufOffset);                                                             /* SRC: pointer to source buffer */
  HLAEveEdmaTriggerParam[2] = HLAEveSegEdmaPack2(psHLAEveSegParams->processingHeight, HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH * 2u); /* 1st (BCNT): height of block to be transfered; 2nd (ACNT): width of block to be transfered */
  HLAEveEdmaTriggerParam[3] = (uint32) pDstBuf;                                                                                /* DST: pointer to destination buffer */
  HLAEveEdmaTriggerParam[4] = HLAEveSegEdmaPack2(HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH * 2u, psHLAEveSegParams->rowOffset * 2u);   /* 1st (DSTBIDX): offset to next block; 2nd (SRCBIDX): offset to next row */
  HLAEveEdmaTriggerParam[5] = HLAEveSegEdmaPack2(psHLAEveSegParams->processingHeight, 0xFFFF);                                 /* 1st (BCNTRLD): length of block; 2nd (LINK): next edma channel, in this case no linking, i.e. 0xFFFF */
  HLAEveEdmaTriggerParam[6] = (0x0);                                                                                           /* only needed for 3rd dimension */
  HLAEveEdmaTriggerParam[7] = 1u;                                                                                              /* CCNT: no 3rd dimension in our case */

  /*---------------------------------------------------------------*/
  /* Restore the previous state. This finishes submission phase    */
  /* of EDMA.                                                      */
  /*---------------------------------------------------------------*/
  _restore_interrupts(restoreInterrupts);

  return retVal;
}



/* LRF */


/*---------------------------------------------------*/
/*  LOCAL FUNCTION DEFINITIONS                       */
/*---------------------------------------------------*/
static inline uint32 HLAEveSegEdmaPack2 (uint16 hi, uint16 lo)
{
  uint32 ret_val;
  ret_val = (((hi << 16) & 0xFFFF0000) | (lo & 0x0000FFFF));
  return (ret_val);
}


