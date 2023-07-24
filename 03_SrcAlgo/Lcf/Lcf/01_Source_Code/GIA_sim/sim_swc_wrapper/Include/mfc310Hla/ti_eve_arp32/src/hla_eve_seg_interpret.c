/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_seg_interpret.c

  DESCRIPTION:            Segmented lines calculation

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-05-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_seg_interpret.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:52CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:43CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:07CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.14 2014/03/03 16:51:32CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:32 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.13 2014/02/06 09:54:14CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed overflowing LED seglines on eve side in addition to Marcus' commit
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 9:54:14 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.12 2014/01/10 18:34:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:08 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.11 2013/12/10 14:49:46CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added a few more debug printfs
  CHANGES:                --- Added comments ---  uidv7867 [Dec 10, 2013 2:49:46 PM CET]
  CHANGES:                Change Package : 207432:7 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.10 2013/12/05 17:47:49CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:49 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.9 2013/11/29 16:48:18CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved find max position to vcop
  CHANGES:                --- Added comments ---  uidv7867 [Nov 29, 2013 4:48:19 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.8 2013/10/31 17:43:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed missing seglines (now we are bit exact to dll)
  CHANGES:                smaller changes
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:43:09 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.7 2013/10/29 18:21:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:57 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.6 2013/10/16 14:59:24CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                Revision 1.5 2013/10/14 12:52:16CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Added DMEM section
  CHANGES:                --- Added comments ---  uidv7867 [Oct 14, 2013 12:52:16 PM CEST]
  CHANGES:                Change Package : 201097:1 http://mks-psad:7002/im/viewissue?selection=201097
  CHANGES:                Revision 1.4 2013/08/24 15:01:26CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimiztations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:26 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.3 2013/08/21 18:21:01CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved sorting on EVE quite a lot
  CHANGES:                --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:01 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:24CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:24 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:50CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
  CHANGES:
**************************************************************************** */

#include <string.h>
#include "hla_eve_seg_interpret.h"
#include "hla_eve.h"


/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/

/*---------------------------------------------------*/
/*  LOCAL FUNCTION DECLARATIONS                      */
/*---------------------------------------------------*/

/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/


/* Initializes the WBUF */
void HLAEveSegInterpretInit(WbufSeg_t *pWbuf)
{
  memset((void*)pWbuf, 0x00, sizeof(*pWbuf));
}

/* Copy vcop output to WBUF */
void HLAEveSegInterpretSaveVcopOut( const HLAEveSegParams_t *psHLAEveSegParams,
                                    const uint16             currentBlock,
                                    uint32                  *pVcopOutBuf,
                                    uint16                  *pVcopOutSumSegLines,
                                    WbufSeg_t               *pWbuf,
                                    HLAEveTimeMeas_t        *pTimeMeas
                                   )
{
  uint64 timeStart;
  uint32 i, j;
  uint16 copiedSeglinesSoFar = 0;
  uint16 positionOffsets[RTE_HLA_SEG_MAX_NUM_LEVELS][HLA_EVE_SEG_NUM_BINNED_COLUMNS];

  HLAEveTimeMeasStart(&timeStart);

  /* Copy sum of found seglines for each level to WBUF */
  for (i = 0; i < RTE_HLA_SEG_MAX_NUM_LEVELS; i++)
  {
    uint16 seglinesPerLevel = 0;
    /* First offset is always 0 */
    positionOffsets[i][0] = 0;
    for (j = 0; j < HLA_EVE_SEG_NUM_BINNED_COLUMNS - 1u; j++)
    {
      /* Save number of found seglines for this level and this block for each column */
      positionOffsets[i][j + 1u] = positionOffsets[i][j] + *pVcopOutSumSegLines;
      /* Sum up number of found seglines of this block */
      seglinesPerLevel += *pVcopOutSumSegLines++;

#ifdef HLA_EVE_DEBUG_2
      if (*pVcopOutSumSegLines > 0)
      {
        DBG(("Found %d seglines of block %d for level %d in column %d.\n", *pVcopOutSumSegLines, currentBlock, i, j));
      }
#endif  
    }
    /* Add 8th item */
    seglinesPerLevel += *pVcopOutSumSegLines++;
    /* Check whether buffer will overflow; if yes we reduce number of to be copied seglines */
    if (seglinesPerLevel + pWbuf->foundSeglinesLevel[i].totalSum > HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_LEVEL )
    {
      seglinesPerLevel = HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_LEVEL - pWbuf->foundSeglinesLevel[i].totalSum;
    }
    pWbuf->foundSeglinesLevel[i].totalSum += seglinesPerLevel;
    pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[currentBlock] = seglinesPerLevel;
  }



  /* Copy vcop output to WBUF */
  /* Loop over all levels */
  for ( i = 0; i < RTE_HLA_SEG_MAX_NUM_LEVELS; i++)
  {
    /* Check whether buffer is full, i.e. found seglines are 0 ... */
    if (   (pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[currentBlock] > 0)
        /* ... or no more outputs from VCOP */
        && (copiedSeglinesSoFar + pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[currentBlock] <= HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_RUN)
       )
    {
      /* Find index in temporary segline buffer of next free position of this level */
      const uint16 freePos = pWbuf->foundSeglinesLevel[i].totalSum - pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[currentBlock];
      for (j= 0; j < pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[currentBlock]; j++)
      {
        /* Check column (x-position) of this Vcop output element; % just to be sure to have no buffer overflow */
        const uint8 xPosSegline = ((HLAEveSegLineRaw_t*) pVcopOutBuf)->column % HLA_EVE_SEG_NUM_BINNED_COLUMNS;
        /* Calculate offset in segline buffer relative to this block */
        const uint16 positionOffset = positionOffsets[i][xPosSegline];
        /* Copy element to temporary segline buffer at correct position so that segline buffer is sorted regarding x-position */
        memcpy((void*)&(pWbuf->posBuf[i][freePos + positionOffset]), (void*)pVcopOutBuf, sizeof(*pVcopOutBuf));
        pVcopOutBuf++;
        positionOffsets[i][xPosSegline]++;
#ifdef HLA_EVE_DEBUG
        if (pWbuf->posBuf[i][freePos + positionOffset].yStop < pWbuf->posBuf[i][freePos + positionOffset].yStart)
        {
          DBG(("Wrong raw segline! i: %d, idxRawSegline: %d, yStart: %d, yStop: %d\n", i, freePos + positionOffset, pWbuf->posBuf[i][freePos + positionOffset].yStart, pWbuf->posBuf[i][freePos + positionOffset].yStop));
        }
        if (   (pWbuf->posBuf[i][freePos + positionOffset].yMax < pWbuf->posBuf[i][freePos + positionOffset].yStart)
            || (pWbuf->posBuf[i][freePos + positionOffset].yMax > pWbuf->posBuf[i][freePos + positionOffset].yStop)
           )
        {
          DBG(("yMax out of segline! level: %d, vcop out element: %d, idxFreeSegline: %d, column: %d, yStart: %d, yStop: %d, yMax: %d\n", i, j, freePos + positionOffset, pWbuf->posBuf[i][freePos + positionOffset].column, pWbuf->posBuf[i][freePos + positionOffset].yStart, pWbuf->posBuf[i][freePos + positionOffset].yStop, pWbuf->posBuf[i][freePos + positionOffset].yMax));
        }
#endif
      }
    }
    copiedSeglinesSoFar += pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[currentBlock];
  }

  pTimeMeas->dTimeEveSegMainInterpretSaveVcopOut_us += HLAEveTimeMeasEnd(timeStart);
}

/* Interpret raw seglines from Wbuf and put HLA_SEG_MAX_NUM_SEG_LINES seglines in local segline buffer */
void HLAEveSegInterpretStoreSeglines( const HLAEveSegParams_t *psHLAEveSegParams,
                                      WbufSeg_t               *pWbuf,
                                      HLASegLine_t            *pLocalSeglineBuf,
                                      uint16                  *pLocalFoundSeglinesBuf,
                                      HLAEveTimeMeas_t        *pTimeMeas
                                     )
{
  uint64 timeStart;
  uint16 idxFreeSegline = 0;
  uint32 i, j, k;

  HLAEveTimeMeasStart(&timeStart);

  /* Saving seglines starting from highest level downwards */
  /* !!! start at 1 since we skip LEDs for now !!! */
  for (i = 1u; i < RTE_HLA_SEG_MAX_NUM_LEVELS; i++)
  {
    uint16 idxRawSegline = 0;
    /* check whether there is enough space in local segline buffer */
    if (idxFreeSegline + pWbuf->foundSeglinesLevel[i].totalSum > HLA_SEG_MAX_NUM_SEG_LINES)
    {
      /* We assume if segline buffer would be overloaded by this level that all other lower levels will also overload it */
      break;
    }
    /* Loop over all blocks */
    for (j = 0; j < HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH / HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH; j++)
    {
      /* Loop over all found seglines of this block */
      for (k = 0; k < pWbuf->foundSeglinesLevel[i].foundSeglinesBlock[j]; k++)
      {
        /* Store segline in local segline buffer.
         * There can be no overflow of idxRawSegline since we checked pWbuf->foundSeglinesLevel[i].totalSum < HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_RUN during saving of vcop output.
         */
                                                    /* x-pos within block */                     /* block offset */        /* 2u: binning */   /* roi offset to get total imager coordinates */
        pLocalSeglineBuf[idxFreeSegline].x    = ((pWbuf->posBuf[i][idxRawSegline].column + (j * HLA_EVE_SEG_NUM_BINNED_COLUMNS)) * 2u) + psHLAEveSegParams->xOffsetRoi;
        pLocalSeglineBuf[idxFreeSegline].y1   = (pWbuf->posBuf[i][idxRawSegline].yStart * 2u) + psHLAEveSegParams->yOffsetRoi;
        pLocalSeglineBuf[idxFreeSegline].y2   = (pWbuf->posBuf[i][idxRawSegline].yStop * 2u) - 1u + psHLAEveSegParams->yOffsetRoi;
        pLocalSeglineBuf[idxFreeSegline].yMax = (pWbuf->posBuf[i][idxRawSegline].yMax * 2u) + psHLAEveSegParams->yOffsetRoi;
#ifdef HLA_EVE_DEBUG
        if (   (pLocalSeglineBuf[idxFreeSegline].yMax < pLocalSeglineBuf[idxFreeSegline].y1)
            || (pLocalSeglineBuf[idxFreeSegline].yMax > pLocalSeglineBuf[idxFreeSegline].y2)
           )
        {
          DBG(("yMax out of segline! level: %d, block: %d, segline: %d, idxFreeSegline: %d, x: %d, y1: %d, y2: %d, yMax: %d\n", i, j, k, idxFreeSegline, pLocalSeglineBuf[idxFreeSegline].x, pLocalSeglineBuf[idxFreeSegline].y1, pLocalSeglineBuf[idxFreeSegline].y2, pLocalSeglineBuf[idxFreeSegline].yMax));
        }
#endif
        idxFreeSegline++;
        idxRawSegline++;
      }
    }
    /* Copy number of found seglines of this level to output local buffer */
    pLocalFoundSeglinesBuf[i] = pWbuf->foundSeglinesLevel[i].totalSum;
  }

  /* make sure that we send back a 0 for all levels that were not filled to segline buffer */
  for (j = i; j < RTE_HLA_SEG_MAX_NUM_LEVELS; j++)
  {
    pLocalFoundSeglinesBuf[j] = 0;
  }

  pTimeMeas->dTimeEveSegMainInterpretStoreSeglines_us = HLAEveTimeMeasEnd(timeStart);
}



