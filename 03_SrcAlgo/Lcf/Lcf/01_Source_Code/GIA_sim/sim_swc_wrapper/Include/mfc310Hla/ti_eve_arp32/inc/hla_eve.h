/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve.h

  DESCRIPTION:            Definitions, etc. what is needed inside HLA EVE implementation

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-06-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:47CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:38CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:02CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.20 2014/03/22 10:28:28CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added project specific defines
  CHANGES:                Replaced defines for CORE by predefined ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:28 AM CET]
  CHANGES:                Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.19 2014/03/12 18:07:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:13 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.18 2014/03/11 15:43:44CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Took cfg_project.h into use
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:44 PM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.17 2014/03/11 10:33:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced SRLCAM_4T0 by CFG_SRLCAM==1
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2014 10:33:56 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.16 2014/02/06 16:01:01CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:02 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.15 2014/01/10 18:33:49CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:49 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.14 2013/12/16 14:28:43CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated SRLCam specific macro
  CHANGES:                --- Added comments ---  uidv7867 [Dec 16, 2013 2:28:43 PM CET]
  CHANGES:                Change Package : 207432:23 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.13 2013/12/11 09:34:54CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Revert previous change
  CHANGES:                --- Added comments ---  uidv7867 [Dec 11, 2013 9:34:55 AM CET]
  CHANGES:                Change Package : 207432:12 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.12 2013/12/11 09:32:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated SRLCam performance settings (clock frequency, etc.)
  CHANGES:                --- Added comments ---  uidv7867 [Dec 11, 2013 9:32:56 AM CET]
  CHANGES:                Change Package : 207432:12 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.11 2013/11/29 16:48:15CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved find max position to vcop
  CHANGES:                --- Added comments ---  uidv7867 [Nov 29, 2013 4:48:15 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.10 2013/10/31 17:43:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed missing seglines (now we are bit exact to dll)
  CHANGES:                smaller changes
  CHANGES:                --- Added comments ---  uidv7867 [Oct 31, 2013 5:43:08 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.9 2013/10/29 18:21:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:58 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.8 2013/10/16 14:59:20CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:20 PM CEST]
  CHANGES:                Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.7 2013/09/20 19:17:29CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Switch to alias memory view
  CHANGES:                --- Added comments ---  uidv7867 [Sep 20, 2013 7:17:29 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.6 2013/09/18 17:39:43CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Usage of memory sections
  CHANGES:                Revision 1.5 2013/08/24 15:01:23CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Further eve optimizations:
  CHANGES:                - Run interpreter in parallel to edma/vcop
  CHANGES:                - Get rid of interpreter prologue
  CHANGES:                - Return vcop init errors
  CHANGES:                - ROI size at most cROI size + 2 pixels
  CHANGES:                --- Added comments ---  uidv7867 [Aug 24, 2013 3:01:24 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.4 2013/08/21 18:21:09CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved sorting on EVE quite a lot
  CHANGES:                --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:10 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.3 2013/08/15 14:16:52CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved EDMA handling on EVE side
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:16:52 PM CEST]
  CHANGES:                Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:02CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:02 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:44CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:
**************************************************************************** */

#ifndef HLA_EVE_H
#define HLA_EVE_H

#include "glob_type.h"
#include "vcop.h"
#include "arp32.h"
#include "hla_base.h"
#include "hla_eve_ext.h"
#include "hla_eve_vcop.h"
#include "hla_eve_seg_main.h"
#include "hla_eve_lrf_main.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/
/* macros for identification of IBUFA and IBUFB*/
#define HLA_EVE_IBUFA 0u
#define HLA_EVE_IBUFB 1u

/* Debugging */
/* Add this flag to enable debug output printfs */
// #define HLA_EVE_DEBUG
#ifdef HLA_EVE_DEBUG
#include <stdio.h>
#define DBG(x) printf x
/* DEBUG_2 give more detailed information but takes much longer per frame */
//#define HLA_EVE_DEBUG_2
#else
#define DBG(x)
#endif

/* Return values as bit field */
/* limited to 16 bits, cf. hla_eve.c where HLAEveSegMain is checked */
#define HLA_EVE_SEG_RETURN_OK                        0x0000
#define HLA_EVE_SEG_RETURN_ERR_HEIGHT                0x0001
#define HLA_EVE_SEG_RETURN_ERR_WIDTH                 0x0002
#define HLA_EVE_SEG_RETURN_ERR_SRC_BUF               0x0004
#define HLA_EVE_SEG_RETURN_ERR_SEG_BUF               0x0008
#define HLA_EVE_SEG_RETURN_ERR_FOUND_SEGLINES_BUF    0x0010
#define HLA_EVE_SEG_RETURN_ERR_MAX_SEG_LINES         0x0020
#define HLA_EVE_SEG_RETURN_ERR_VCOP_PARAMS           0x0040

/* limited to 16 bits, cf. hla_eve.c where HLAEveLrfMain is checked */
#define HLA_EVE_LRF_RETURN_OK                        0x0000
#define HLA_EVE_LRF_RETURN_ERR_TANH_LUT              0x0001
#define HLA_EVE_LRF_RETURN_ERR_PRE_PROC_IMAGE        0x0002
#define HLA_EVE_LRF_RETURN_ERR_RFS                   0x0004
#define HLA_EVE_LRF_RETURN_ERR_HIDDEN_NEURONS        0x0008
#define HLA_EVE_LRF_RETURN_ERR_NUM_RFS               0x0010
#define HLA_EVE_LRF_RETURN_ERR_VCOP_PARAMS_FEATURES  0x0020
#define HLA_EVE_LRF_RETURN_ERR_VCOP_PARAMS_NEURONS   0x0040

/* general return codes, must not be defined in one of above return codes */
#define HLA_EVE_EDMA_RETURN_ERR_CFG_SEG_IN           0x1000
#define HLA_EVE_EDMA_RETURN_ERR_CFG_1D1D             0x2000
#define HLA_EVE_EDMA_RETURN_ERR_CFG_LINKED_1D1D      0x4000

/* Time measurement */
#if (CFG_SRLCAM ==1)
/* Time of one ARP32 cycle in micro seconds assuming a frequency of 265 MHz */
#define HLA_EVE_CYCLE_TIME_ARP32_US  (0.0037735849f)
#else
/* Time of one ARP32 cycle in micro seconds assuming a frequency of 200 MHz */
#define HLA_EVE_CYCLE_TIME_ARP32_US  (0.005f)
#endif

/* offset between IBUFA and IBUFB: 0x4007 0000 - 0x4005 0000 = 0x2 0000*/
#define HLA_EVE_IBUFS_OFFSET 0x20000


/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DECLARATIONS                     */
/*---------------------------------------------------*/
/* Time meas functions */
/* Stores current cycle count in timeStart variable */
inline void HLAEveTimeMeasStart(uint64* timeStart)
{
  *timeStart = _tsc_gettime();
}

/* Subtracts current cycle count from timeStart and returns corresponding time difference in microseconds */
inline uint16 HLAEveTimeMeasEnd(uint64  timeStart)
{
  return (uint16)((float32)(_tsc_gettime() - timeStart) * HLA_EVE_CYCLE_TIME_ARP32_US + 0.5f);
}

#endif /* HLA_EVE_H */
