/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_edma.h

  DESCRIPTION:            EDMA functions for ARP32/EVE

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-05-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_edma.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:46CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:34CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:02CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.4 2014/03/12 18:07:39CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:39 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.3 2014/02/06 16:02:49CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:50 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.2 2013/10/29 18:21:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:59 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.1 2013/10/16 15:00:13CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.6 2013/09/20 19:17:28CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Switch to alias memory view
  CHANGES:                --- Added comments ---  uidv7867 [Sep 20, 2013 7:17:28 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.5 2013/09/18 17:39:44CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Usage of memory sections
  CHANGES:                --- Added comments ---  uidv7867 [Sep 18, 2013 5:39:44 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.4 2013/08/24 15:01:24CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimiztations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:24 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.3 2013/08/15 14:16:53CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved EDMA handling on EVE side
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:16:53 PM CEST]
  CHANGES:                Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:22CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:22 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:46CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:
**************************************************************************** */

#ifndef HLA_EVE_EDMA_H
#define HLA_EVE_EDMA_H

/*---------------------------------------------------*/
/*  INCLUDES                                         */
/*---------------------------------------------------*/

#include "csl_edma.h"
#include "cslr_edmacc.h"
#include "eve.h"    

#include "hla_eve.h"
#include "hla_eve_lrf_main.h"


/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  EXTERNAL FUNCTION DECLARATIONS                   */
/*---------------------------------------------------*/

void HLAEveEdmaInit(void);
void HLAEveEdmaTriggerDma(void);
void HLAEveEdmaWait4Dma(uint16 *pTimeMeasEntry);
void HLAEveEdmaTeardownDma(void);
uint16 HLAEveEdmaCfg1d1d( const void* pSrc,
                          const void* pDst,
                          const uint16 numBytes,
                          const uint8  channel
                         );
uint16 HLAEveEdmaCfgLinked1d1d( const void* pSrc,
                                const void* pDst,
                                const uint16 numBytes,
                                const uint8  channel
                               );

/* SEGMENTATION */
uint16 HLAEveEdmaSegCfgInputTransfer( const HLAEveSegParams_t *psHLAEveSegParams,
                                      const uint16            *pSrcBuf,
                                      const uint16            *pDstBuf,
                                      const uint8              blockCounter
                                     );

/* LRF */

#endif /* HLA_EVE_EDMA_H */
