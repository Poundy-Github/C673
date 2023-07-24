/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_seg_main.h

  DESCRIPTION:            Segmentation on EVE, main routines

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-06-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_seg_main.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:47CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:37CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:04CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.11 2014/03/03 16:51:34CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:34 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.10 2013/12/10 14:49:28CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Cosmetic changes
  CHANGES:                --- Added comments ---  uidv7867 [Dec 10, 2013 2:49:28 PM CET]
  CHANGES:                Change Package : 207432:7 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.9 2013/12/05 17:47:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:53 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.8 2013/11/29 16:48:19CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved find max position to vcop
  CHANGES:                --- Added comments ---  uidv7867 [Nov 29, 2013 4:48:19 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.7 2013/10/31 17:43:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed missing seglines (now we are bit exact to dll)
  CHANGES:                smaller changes
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:43:09 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.6 2013/10/30 13:05:21CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved runtime a bit on vcop side
  CHANGES:                --- Added comments ---  uidv7867 [Oct 30, 2013 1:05:21 PM CET]
  CHANGES:                Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.5 2013/10/29 18:21:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:57 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.4 2013/10/16 14:59:25CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:25 PM CEST]
  CHANGES:                Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.3 2013/08/24 15:01:26CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimizations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:27 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:15CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:15 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:47CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:
**************************************************************************** */

#ifndef HLA_EVE_SEG_MAIN_H
#define HLA_EVE_SEG_MAIN_H

#include "hla_eve_ext.h"
#include "hla_eve.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/
/* SEGMENTATION */
#define HLA_EVE_SEG_NUM_ARGS_VCOP_EXEC  46u                                      /* number of used parameter registers for vcop, depending on argument list of HLAEveSegVcopExec() */

#define HLA_EVE_SEG_NUM_BINNED_COLUMNS    VCOP_SIMD_WIDTH                        /* due to 2x2 -> 1x1 binning output width of each block is only 8 pixels/columns */
#define HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH (2u * HLA_EVE_SEG_NUM_BINNED_COLUMNS)  /* 2 * 8 pixels in parallel as we have 8 ALUs and do a 2x2 -> 1x1 binning */
#define HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_RUN 2997u                              /* maximum number of seglines vcop can output in one run, i.e. in one 16pix * imgHeight block; strange number as we just fill IBUFH buffer */
#define HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_LEVEL HLA_SEG_MAX_NUM_SEG_LINES        /* maximum number of seglines to be stored for each level */


/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/
typedef struct
{
  uint16 totalSum;                                                                                       /* Total sum of all found seglines of this level */
  uint16 foundSeglinesBlock[HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH / HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH];    /* Sum of all found seglines of this level for each block */
} HLAEveSegFoundSeglines;

typedef struct
{
  uint32 yStop:    9;
  uint32 yStart:   9;
  uint32 yMax:     10;
  uint32 column:   4;
} HLAEveSegLineRaw_t;

typedef struct
{
  HLAEveSegFoundSeglines foundSeglinesLevel[RTE_HLA_SEG_MAX_NUM_LEVELS];                                 /* Contains detailed information about found seglines for each level */
  HLAEveSegLineRaw_t     posBuf[RTE_HLA_SEG_MAX_NUM_LEVELS][HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_LEVEL];    /* segline buffer, i.e. position storage sorted by level */
} WbufSeg_t;

typedef struct
{
  uint16 srcBufRawData[HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT * HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH];   /* input buffer that contains height * block width (16) pixels */
} IbufLSeg_t;

typedef struct
{
  uint16 argsBlockVcopExec[HLA_EVE_SEG_NUM_ARGS_VCOP_EXEC];                                                    /* place where arguments for vcop are stored */
  uint32 columnIndexTab[HLA_EVE_SEG_NUM_BINNED_COLUMNS];                                                       /* per column we have an index stored in vcop output */
  uint16 thresholdTab[RTE_HLA_SEG_MAX_NUM_LEVELS];                                                            /* per level we have a different threshold */
  uint16 binnedPixelMask[RTE_HLA_SEG_MAX_NUM_LEVELS];                                                         /* per level we have a different pixel mask (mask needed due to separate handling of LEDs) */
  uint16 tempBufBinnedData[(HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT * HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH) / 4u];   /* temporary buffer for binned data (2x2 -> 1x1), i.e. 1/4 of IBUFL srcBufRawData */
  uint16 tempBufZeroPix[HLA_EVE_SEG_NUM_BINNED_COLUMNS];                                                       /* + 8 binned pixels of value 0 (to close open seglines) which are only needed in case of psHLAEveSegParams->processingHeight == HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT */
  uint16 destBufSumSeglines[RTE_HLA_SEG_MAX_NUM_LEVELS * HLA_EVE_SEG_NUM_BINNED_COLUMNS];                     /* number of found seglines per level and column */
  uint32 destBufSeglines[HLA_EVE_SEG_MAX_NUM_SEG_LINES_PER_RUN];
} IbufHSeg_t;


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DECLARATIONS                     */
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
                     );

#endif /* HLA_EVE_SEG_MAIN_H */
