/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_seg_vcop.k

  DESCRIPTION:            Segmentation of 8 rg rows

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-05-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_seg_at_vcop.k  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:51CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:43CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:06CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.10 2014/03/12 18:07:22CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:23 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.9 2013/12/10 14:50:43CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Bug fix of max pos finding on vcop
  CHANGES:                --- Added comments ---  uidv7867 [Dec 10, 2013 2:50:43 PM CET]
  CHANGES:                Change Package : 207432:7 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.8 2013/11/29 16:48:16CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved find max position to vcop
  CHANGES:                --- Added comments ---  uidv7867 [Nov 29, 2013 4:48:17 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.7 2013/10/31 17:43:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed missing seglines (now we are bit exact to dll)
  CHANGES:                smaller changes
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:43:08 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.6 2013/10/30 13:05:21CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved runtime a bit on vcop side
  CHANGES:                --- Added comments ---  uidv7867 [Oct 30, 2013 1:05:22 PM CET]
  CHANGES:                Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.5 2013/10/29 18:21:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:22:00 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.4 2013/08/24 15:01:25CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimizations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:25 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.3 2013/08/21 18:21:13CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved sorting on EVE quite a lot
  CHANGES:                --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:13 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/15 14:16:54CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved EDMA handling on EVE side
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:16:55 PM CEST]
  CHANGES:                Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.1 2013/07/26 17:12:49CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
  CHANGES:
**************************************************************************** */

#include "hla_eve_vcop.h"

/*
 * Main function that does segmentation of 8 image columns
 */
/*
 * !!! IN CASE OF ANY CHANGE OF FOLLOWING FUNCTION INTERFACE (ARGUMENTS)
 * !!! check .c file how many parameter registers are used.
 * !!! If there are changes you have to change HLA_EVE_SEG_NUM_ARGS_VCOP_EXEC in hla_eve_seg_main.h
 */
void HLAEveSegVcopExec( __vptr_uint16  pSrcBufRawData,
                        __vptr_uint16  pTempBufBinnedData,
                        __vptr_uint32  pColumnIdx,
                        __vptr_uint16  pThresholds,
                        unsigned short thresholdLedUpper,
                        unsigned short thresholdLedLower,
                        __vptr_uint16  pBinnedPixMask,
                        unsigned short binnedImgHeight,
                        unsigned char  numLevels,
                        __vptr_uint16  pDestBufSumSeglines,
                        __vptr_uint32  pDestBufSeglinBuffer
                      )
{
  __agen AddrZero = 0;
  __vector VconstColIdx;                     /* Backup of column index (x-position) */
  __vector VconstFilterLedBit;               /* Filter for LED bit, i.e. 0x8000) */

  /* -------------------------------------------------------------------------------- */
  /* Get a 2x2 pixel block from pSrcBufRawData and reduce each block to a single      */
  /* pixel (1x1) by searching for a maximum which is written to pTempBufBinnedData.   */
  /*                                                                                  */
  /*  ---- ---- ---- ---- ---- ----               --------- --------- ---------       */
  /* | A1 | A2 | B1 | B2 | C1 | C2 | ...         |         |         |         |      */
  /*  ---- ---- ---- ---- ---- ----              |    A    |    B    |    C    |  ... */
  /* | A3 | A4 | B3 | B4 | C3 | C4 | ...         |         |         |         |      */
  /*  ---- ---- ---- ---- ---- ----        ==>    --------- --------- ---------       */
  /* | Q1 | Q2 | R1 | R2 | S1 | S2 | ...         |         |         |         |      */
  /*  ---- ---- ---- ---- ---- ----              |    Q    |    R    |    S    |  ... */
  /* | Q3 | Q4 | R3 | R4 | S3 | s4 | ...         |         |         |         |      */
  /*  ---- ---- ---- ---- ---- ----               --------- --------- ---------       */
  /*  ...  ...  ...  ...  ...  ...                   ...       ...      ...           */
  /*                                                                                  */
  /* LED thresholds:                                                                  */
  /* After detection, we set additionally bit #15 in temp buffer.                     */
  /* LOOP2 will detect those LED thresholds as Level8 Pixel.                          */
  /* -------------------------------------------------------------------------------- */
  for (int binnedRow = 0; binnedRow < binnedImgHeight; binnedRow++)
  {
    __agen AddrSrc, AddrDest;
    __vector VIn0, VIn1, VIn2, VIn3;                      /* input register containing raw pixels */
    __vector Vscr0, Vscr1;                                /* scratch register */
    __vector VledPix;                                     /* register containing Led yes/no */
    __vector Vmax0, Vmax1;                                /* maximum register containing local/global maximum */
    __vector VthresholdLedUpper = thresholdLedUpper;      /* registers containing upper LED threshold */
    __vector VthresholdLedLower = thresholdLedLower;      /* registers containing lower LED threshold */
    __vector VconstShiftToBit16 = 15;


                 /* 16 Bytes */     /* 4 = 2 * 2 = every 2nd line (2x2 binning) * every 2nd block (16 Pixel of each row are in the buffer pSrc) */
    AddrSrc = binnedRow * VECTORSIZE(pSrcBufRawData) * 4u;
    AddrDest = binnedRow * VECTORSIZE(pTempBufBinnedData);

    /* Take 16 pixels from first row */
    (VIn0, VIn1) = pSrcBufRawData[AddrSrc].deinterleave();
    /* Find local maximum of first row */
    Vmax0 = max(VIn0, VIn1);
    /* Compare Vin0 pixel against the LED thresholds */
    Vscr0 = (VIn0 >= VthresholdLedLower);
    Vscr1 = (VIn0 <= VthresholdLedUpper);
    Vscr0 &= Vscr1;
    /* Move this information (LED yes/no) to bit 16 */
    VledPix = Vscr0 << VconstShiftToBit16;
    /* Compare Vin1 pixel against the LED thresholds */
    Vscr0 = (VIn1 >= VthresholdLedLower);
    Vscr1 = (VIn1 <= VthresholdLedUpper);
    Vscr0 &= Vscr1;
    /* Move this information (LED yes/no) to bit 16 */
    VledPix |= Vscr0 << VconstShiftToBit16;

    /* Take pixels from second row, offset is 32 Bytes, i.e. 16 pixel */
    (VIn2, VIn3) = (pSrcBufRawData + 32u)[AddrSrc].deinterleave();
    /* Find local maximum of second row */
    Vmax1 = max(VIn2, VIn3);
    /* Compare VIn2 pixel against the LED thresholds */
    Vscr0 = (VIn2 >= VthresholdLedLower);
    Vscr1 = (VIn2 <= VthresholdLedUpper);
    Vscr0 &= Vscr1;
    /* Move this information (LED yes/no) to bit 16 */
    VledPix |= Vscr0 << VconstShiftToBit16;
    /* Compare VIn3 pixel against the LED thresholds */
    Vscr0 = (VIn3 >= VthresholdLedLower);
    Vscr1 = (VIn3 <= VthresholdLedUpper);
    Vscr0 &= Vscr1;
    /* Move this information (LED yes/no) to bit 16 */
    VledPix |= Vscr0 << VconstShiftToBit16;

    /* Find maximum of both rows */
    Vmax0 = max(Vmax0, Vmax1);
    /* Add LED information (in bit 16) */
    Vmax0 |= VledPix;
    /* Save maximum to output buffer */
    pTempBufBinnedData[AddrDest] = Vmax0;
  }


  /* ------------------------------------------------------------------------------ */
  /* Now we want to compare each binned pixel against numLevels (8) thresholds.     */
  /* We start at the top of the binned image and handle 8 (VCOP_SIMD_WIDTH) binned  */
  /* pixels in parallel. Hence, in every row we try to detect these threshold cross */
  /* overs. Whenever we detect one 0 to 1 we start a segline. This row is stored    */
  /* temporary in a register. Once we detect the counter part (cross over from 1 to */
  /* 0) we can close the segline. Both start and end (x-position) as well as column */
  /* (y-position) are stored in a 32-bit word ready for going out. In parallel we   */
  /* try to find the maximum of each segline and store that as well. With "collate" */
  /* we can store in every row only the 32-bit word of a just closed segline.       */
  /*                                                                                */
  /* Output register:                                                               */
  /* bits   0..3: column index (x-position)                                         */
  /* bits  4..13: maximum inside segline (y-position)                               */
  /* bits 14..22: start of segline (y-position)                                     */
  /* bits 23..31: end of segline (y-position)                                       */
  /* ------------------------------------------------------------------------------ */

  /* Copy column indices (y-position) to corresponding register */
  VconstColIdx = pColumnIdx[AddrZero];
  /* Copy LED bit filter to register */
  VconstFilterLedBit = pBinnedPixMask[AddrZero].onept();

  /* Loop over all levels/thresholds */
  for (int level = 0; level < numLevels; level++)
  {
    __vector Vscr2;                         /* scratch register */
    __vector Vscr3;                         /* scratch register */
    __vector VbinnedPixGreyValue;           /* contains grey value part of binned pixel, i.e. LED is filtered out */
    __vector VsumSeglines;                  /* counts number of seglines per column */
    __vector VseglineStart;                 /* Beginning of segline, i.e. row (y-position) */
    __vector VbinnedPixMask;                /* Mask for separating LEDs from rest of binned pixel */
    __vector Vthresholds;                   /* contains threshold of this level */
    __vector VaboveThresholds;              /* contains booleans reflection whether this pixel is above Vthresholds or not */
    __vector VRowIdx;                       /* current y-position */
    __vector VMaxPos;                       /* current y-position of the maximum in this segline */
    __vector VMaxValue;                     /* current value of the maximum in this segline */
    __vector Vconst1  =  1;
    __vector Vconst9  =  9;
    __vector Vconst18 = 18;

    /* Copy thresholds of current level to corresponding register */
    __agen AddrScalarLoad, AddrSumSeglineBuf;
    AddrScalarLoad = level * ELEMSIZE(pThresholds);
    /* Scalar load of current threshold value */
    Vthresholds = pThresholds[AddrScalarLoad].onept();
    /* Scalar load of current pixel mask (as pThresholds has same size as pBinnedPixMask we can use same address generator */
    VbinnedPixMask = pBinnedPixMask[AddrScalarLoad].onept();

    /* Init VseglineStart with column index (x-position) */
    VseglineStart = VconstColIdx;

    VaboveThresholds = 0;
    VsumSeglines = 0;
    VRowIdx = 0;
    VMaxPos = 0;
    VMaxValue = 0;

    /* loop over all binned pixels from top to bottom */
    _COLLATE(pDestBufSeglinBuffer);
    for (int binnedRow = 0; binnedRow < binnedImgHeight + 1u; binnedRow++)
    {
      /* copy 8 binned pixels to a scratch register */
      __agen AddrCol;
      AddrCol = binnedRow * VECTORSIZE(pTempBufBinnedData);
      Vscr3 = pTempBufBinnedData[AddrCol];

      /* filter out real grey value needed for determination of maximum position by inverting LED bit filter */
      VbinnedPixGreyValue = Vscr3 & ~VconstFilterLedBit;
      /* filter LED bit, i.e. in case of LED it contains 0x8000 or 0, in all other cases same as VbinnedPixGreyValue */
      Vscr3 &= VbinnedPixMask;

      /* Backup crucial information regarding thresholds from previous row  */
      Vscr2 = VaboveThresholds;
      /* Compare binned raw pixel against current thresholds */
      VaboveThresholds = (Vscr3 >= Vthresholds);

      /* Comparing to previous row, i.e. start/end of segline */
      Vscr3 = (Vscr2 ^ VaboveThresholds);

      /* START OF SEGLINE */
      Vscr2 = (Vscr3 & VaboveThresholds);
      /* Reset max pos/value register to current values in case of start of new segline */
      VMaxValue = select(Vscr2, VbinnedPixGreyValue, VMaxValue);
      VMaxPos = select(Vscr2, VRowIdx, VMaxPos);
      /* Clear VseglineStart register by overwriting it with column index only depending on a start of segline
       * else do overwrite it with the current value
       */
      VseglineStart = select(Vscr2, VconstColIdx, VseglineStart);
      /* Add current row to scratch register */
      Vscr2 = Vscr2 * VRowIdx;
      /* Put start of segline (current row) to VselineStart and move that to higher 9 bits of that register */
      VseglineStart |= Vscr2 << Vconst9;

      /* END OF SEGLINE */
      Vscr3 = (Vscr3 & ~VaboveThresholds);
      /* Store maximum position of this segline in segline start register */
      Vscr2 = Vscr3 * VMaxPos;
      VseglineStart |= Vscr2 << Vconst18;

      /* Check for maximum in this row. It's important to do that after detection of end of segline
       * since this line is not part of segline, strictly speaking.
       */
      Vscr2 = (VbinnedPixGreyValue > VMaxValue);
      VMaxValue = max(VbinnedPixGreyValue, VMaxValue);
      VMaxPos = select(Vscr2, VRowIdx, VMaxPos);

      /* increase number of found seg lines */
      VsumSeglines += Vscr3;
      /* Add current row to scratch register */
      Vscr2 = Vscr3 * VRowIdx;
      /* Add also start of segline to scratch register */
      Vscr2 |= VseglineStart;

      /* Increase current row index */
      VRowIdx += Vconst1;
      /* Output only those parts of vector Vscr1 where Vsel_out is true, i.e. end of segline */
      (pDestBufSeglinBuffer)[collate(Vscr3)] = Vscr2;
    }
    AddrSumSeglineBuf = level * VECTORSIZE(pDestBufSumSeglines);
    /* output number of seglines found for current level */
    pDestBufSumSeglines[AddrSumSeglineBuf] = VsumSeglines;
  }
}

