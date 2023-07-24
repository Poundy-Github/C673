/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_seg_interpret.h

  DESCRIPTION:            Interpretation of vcop output:
                            Segmented lines calculation

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-06-19

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_seg_interpret.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:46CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:36CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:03CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.4 2013/10/29 18:22:00CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:22:00 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.3 2013/08/21 18:21:30CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved sorting on EVE quite a lot
  CHANGES:                --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:30 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:23CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:23 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:46CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:
**************************************************************************** */

#ifndef HLA_EVE_SEG_INTERPRET_H
#define HLA_EVE_SEG_INTERPRET_H

#include "hla_eve_seg_main.h"

#define HLA_EVE_SEG_INTERPRET_INDEX_LEVEL_1  0
#define HLA_EVE_SEG_INTERPRET_INDEX_LEVEL_2  1
#define HLA_EVE_SEG_INTERPRET_INDEX_LEVEL_3  2
#define HLA_EVE_SEG_INTERPRET_INDEX_LED      3
#ifdef HLA_EVE_SEG_WITH_LED_BAND
#define HLA_EVE_SEG_INTERPRET_INDEX_MAX      4    /* LED, L3, L2, L1 */
#else
#define HLA_EVE_SEG_INTERPRET_INDEX_MAX      3    /* L3, L2, L1 */
#endif

#define HLA_EVE_SEG_INTERPRET_EMPTY_PATTERN_TEMP_STORAGE 0xFFFFFFFF

#define HLA_EVE_SEG_INTERPRET_PATTERN_LEVELS  0x000F   /* Bit mask for LED, L3, L2, L1 levels */
#define HLA_EVE_SEG_INTERPRET_PATTERN_ROW     0x00F0   /* Bit mask for corresponding row */

#define HLA_EVE_SEG_INTERPRET_PATTERN_LED     0x01     /* Bit field  0001*/
#define HLA_EVE_SEG_INTERPRET_PATTERN_LEVEL_3 0x02     /* Bit field  0010*/
#define HLA_EVE_SEG_INTERPRET_PATTERN_LEVEL_2 0x04     /* Bit field  0100*/
#define HLA_EVE_SEG_INTERPRET_PATTERN_LEVEL_1 0x08     /* Bit field  1000*/

#ifdef HLA_EVE_SEG_PROCESS_ONLY_RED
#define HLA_EVE_SEG_INTERPRET_X2_OFFSET 2u    /* 2 since we process every 2nd pixel */
#else
#define HLA_EVE_SEG_INTERPRET_X2_OFFSET 1u    /* 1 since we process every pixel */
#endif
/*
 * GLOBAL FUNCTIONS
 */

void HLAEveSegInterpretInit(WbufSeg_t *pWbuf);
void HLAEveSegInterpretSaveVcopOut( const HLAEveSegParams_t *psHLAEveSegParams,
                                    const uint16             currentBlock,
                                    uint32                  *pVcopOutBuf,
                                    uint16                  *pVcopOutSumSegLines,
                                    WbufSeg_t               *pWbuf,
                                    HLAEveTimeMeas_t        *pTimeMeas
                                   );
void HLAEveSegInterpretStoreSeglines( const HLAEveSegParams_t *psHLAEveSegParams,
                                      WbufSeg_t               *pWbuf,
                                      HLASegLine_t            *pLocalSeglineBuf,
                                      uint16                  *pLocalFoundSeglinesBuf,
                                      HLAEveTimeMeas_t        *pTimeMeas
                                     );

#endif /* HLA_EVE_SEG_INTERPRET_H */
