/*! \file **********************************************************************

  COMPANY:                Continental Automotive , 

  PROJECT:                MFC300

  CPU:                    MPC567x

  COMPONENT:              ROI

  MODULNAME:              glob_cfg.h

  DESCRIPTION:            This file contains global defs.

  AUTHOR:                 Lars Perske (b-plus GmbH)

  CREATION DATE:          22.12.2009

  VERSION:                $Revision: 1.1 $


  ---*/ /*---
    CHANGES:              $Log: glob_cfg.h  $
    CHANGES:              Revision 1.1 2021/12/13 17:22:59CET Wang, David (Wangd3) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
    CHANGES:              Revision 1.0 2017/03/03 10:34:39CET Sorge, Sven (uidg3181) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
    CHANGES:              Revision 1.5 2013/10/09 10:27:47CEST Friedrichs-EXT, Edmund02 (uidt2925) 
    CHANGES:              added M3Algo as S13
    CHANGES:              - Added comments -  uidt2925 [Oct 9, 2013 10:27:47 AM CEST]
    CHANGES:              Change Package : 197320:2 http://mks-psad:7002/im/viewissue?selection=197320
    CHANGES:              Revision 1.4 2013/06/05 11:26:56CEST Stura, Georg (uidv7871) 
    CHANGES:              Update for the RTA
    CHANGES:              --- Added comments ---  uidv7871 [Jun 5, 2013 11:26:56 AM CEST]
    CHANGES:              Change Package : 176638:1 http://mks-psad:7002/im/viewissue?selection=176638
    CHANGES:              Revision 1.3 2013/03/22 08:49:22CET Stura, Georg (uidv7871) 
    CHANGES:              Allign header file
    CHANGES:              --- Added comments ---  uidv7871 [Mar 22, 2013 8:49:23 AM CET]
    CHANGES:              Change Package : 176636:1 http://mks-psad:7002/im/viewissue?selection=176636
    CHANGES:              Revision 1.2 2013/03/12 09:26:03CET Sautter-Steisslinger, Frank (uidw0362) 
    CHANGES:              VDY define added
    CHANGES:              --- Added comments ---  uidw0362 [Mar 12, 2013 9:26:03 AM CET]
    CHANGES:              Change Package : 173705:6 http://mks-psad:7002/im/viewissue?selection=173705
    CHANGES:              Revision 1.4 2013/01/28 15:16:25CET Stura, Georg (uidv7871) 
    CHANGES:              VDY define added
    CHANGES:              --- Added comments ---  uidv7871 [Jan 28, 2013 3:16:25 PM CET]
    CHANGES:              Change Package : 171730:1 http://mks-psad:7002/im/viewissue?selection=171730
    CHANGES:              Revision 1.3 2013/01/11 11:38:44CET Stura, Georg (uidv7871) 
    CHANGES:              Cleaned some flags
    CHANGES:              --- Added comments ---  uidv7871 [Jan 11, 2013 11:38:45 AM CET]
    CHANGES:              Change Package : 171730:1 http://mks-psad:7002/im/viewissue?selection=171730
    CHANGES:              Revision 1.2 2013/01/02 09:49:42CET Stura, Georg (uidv7871) 
    CHANGES:              Some defines are cleaned
    CHANGES:              --- Added comments ---  uidv7871 [Jan 2, 2013 9:49:42 AM CET]
    CHANGES:              Change Package : 169102:1 http://mks-psad:7002/im/viewissue?selection=169102
    CHANGES:              Revision 1.1 2012/12/13 15:55:41CET Stura, Georg (uidv7871) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/SW/SW_MFC4xx/SW_SMFC400_PR/S00_ALL/04_Engineering/01_Source_Code/soc/project.pj
    CHANGES:              Revision 1.5 2012/09/28 09:39:47CEST Scherer, Michael (uidu3109) 
    CHANGES:              + added I200 switch
    CHANGES:              --- Added comments ---  uidu3109 [Sep 28, 2012 9:39:48 AM CEST]
    CHANGES:              Change Package : 158388:1 http://mks-psad:7002/im/viewissue?selection=158388
    CHANGES:              Revision 1.4 2012/09/27 17:40:12CEST Scherer, Michael (uidu3109) 
    CHANGES:              * disable predetermined processing
    CHANGES:              Revision 1.3 2012/09/27 15:24:13CEST Scherer, Michael (uidu3109) 
    CHANGES:              + added compiler switch for reference image
    CHANGES:              --- Added comments ---  uidu3109 [Sep 27, 2012 3:24:13 PM CEST]
    CHANGES:              Change Package : 158388:1 http://mks-psad:7002/im/viewissue?selection=158388
    CHANGES:              Revision 1.2 2012/09/10 17:12:14CEST Scherer, Michael (uidu3109) 
    CHANGES:              + added compiler switch CFG_CROI_ACQUIRED_WIDTH from mfc310 project
    CHANGES:              --- Added comments ---  uidu3109 [Sep 10, 2012 5:12:14 PM CEST]
    CHANGES:              Change Package : 158388:1 http://mks-psad:7002/im/viewissue?selection=158388
    CHANGES:              Revision 1.1 2012/09/04 09:53:04CEST Budea, Candin (uidl6104) 
    CHANGES:              Initial revision
    CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC400/05_Software/SOC/HIS/HIS_CA8/his_glob/project.pj

**************************************************************************** */


/** @defgroup GlobalProjectConfiguration Configuration
 This is the current configuration of the project.
 (1) functionality available
 (0) functionality not available
 *  @{
 */


/* conditional include */
#ifndef GLOB_CFG_H
#define GLOB_CFG_H

#include "glob_defs.h"   /*!< include of global definitions like SWITCH_ON and SWITCH_OFF */

/******************************************************************************************************************/
/******************************************************************************************************************/
/*                                                                                                                */
/*                                              hla component                                                     */
/*                                                                                                                */
/******************************************************************************************************************/
/******************************************************************************************************************/
/*! use the own VDY data because VDY is not available in I210 */
#define CFG_HLA_USE_VDY_DATA   SWITCH_OFF

/*! switch to enable/disable using predetermined image */
#define CFG_HLA_USE_PREDETERMINED_IMAGE  SWITCH_OFF

/******************************************************************************************************************/
/******************************************************************************************************************/
/*                                                                                                                */
/*                                        ROI (IA) settings                                              */
/*                                                                                                                */
/******************************************************************************************************************/
/******************************************************************************************************************/

#define CFG_ROI_TEST_MODE   SWITCH_OFF

/******************************************************************************************************************/
/******************************************************************************************************************/
/*                                                                                                                */
/*                                        Core ID's                                             */
/*                                                                                                                */
/******************************************************************************************************************/
/******************************************************************************************************************/

enum DSPCoreID {
     e_CoreInvalid = 0, //Value 0 for not valid value.
     e_CoreCA8_0 = 11, //Cortex A8 core
     e_CoreM3_0 = 12, //Cortex M3 VIDEO in TI docs VICP
     e_CoreM3_Algo = 13, //Cortex M3Algo in TI docs VPSS
     e_CoreDSP_0 = 14, //DSP674 core
     e_CoreEVE_0 = 16, //ARP32 Core of EVE system
     e_CoreCA8_1 = 21, //Cortex A8 core of stereo DSP
     e_CoreM3_1 = 22, //Cortex M3 VIDEO of stereo DSP
     e_CoreDSP_1 = 25, //DSP674 core of stereo DSP
     e_CoreEVE_1 = 27, //ARP32 Core of stereo DSP
     e_CoreNumber = 8, //Marker for number of enums in cores type
     /* DSPCoreID must be smaller than 256 */
     /* compiler workaround */
     e_DSPCoreID_EVT_LAST_ENTRY  = 65536
 };


#endif

/** @} */ 
