/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_quality.hpp  

  DESCRIPTION:    Rectification quality measurement

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_quality.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:33CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:24CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.12 2014/02/06 13:44:51CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adaption to changed stereo image map sizes
  CHANGES:        - Added comments -  uidw0251 [Feb 6, 2014 1:44:51 PM CET]
  CHANGES:        Change Package : 216853:1 http://mks-psad:7002/im/viewissue?selection=216853
  CHANGES:        Revision 1.11 2013/08/01 11:39:52CEST Mueller, Reik (muellerr5) 
  CHANGES:        - introduced disparity image type from CCT
  CHANGES:        --- Added comments ---  muellerr5 [Aug 1, 2013 11:39:53 AM CEST]
  CHANGES:        Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.10 2012/06/25 09:41:06CEST uidk7517 
  CHANGES:        Added code review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:41:06 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.9 2012/03/02 11:24:52CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Mar 2, 2012 11:24:52 AM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.8 2012/02/22 17:28:49CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:49 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.7 2011/11/16 19:39:12CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Nov 16, 2011 7:39:12 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2011/10/19 08:59:54CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        runtime optimization on viscr_quality_disparity function
  CHANGES:        --- Added comments ---  uid26778 [Oct 19, 2011 8:59:54 AM CEST]
  CHANGES:        Change Package : 80275:2 http://mks-psad:7002/im/viewissue?selection=80275
  CHANGES:        Revision 1.5 2011/09/16 11:08:15CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Check if powerflow is valid to perform quality check
  CHANGES:        --- Added comments ---  uid26778 [Sep 16, 2011 11:08:15 AM CEST]
  CHANGES:        Change Package : 77279:4 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.4 2011/09/15 14:38:11CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Reduce the calibration buffer from 11 to 3
  CHANGES:        Increase the coarse calibration ROI
  CHANGES:        Improve right left powerflow resolution
  CHANGES:        --- Added comments ---  uid26778 [Sep 15, 2011 2:38:11 PM CEST]
  CHANGES:        Change Package : 77279:4 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.3 2011/07/22 16:19:45CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve rectification quality measurement
  CHANGES:        --- Added comments ---  uid26778 [Jul 22, 2011 4:19:45 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.2 2011/07/08 16:57:48CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve disparity quality measurement
  CHANGES:        --- Added comments ---  uid26778 [Jul 8, 2011 4:57:48 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.1 2011/05/31 19:22:25CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj
  

**************************************************************************** */




#ifndef _viscr_quality_hpp_
#define _viscr_quality_hpp_

#include <viscr_types.hpp>
#include "sac_algo.h"

#define VISCR_QUALITY_KLT_SHIFT_MAX 2.0f
#define VISCR_QUALITY_DV_MAX 5.0f

#define VISCR_QUALITY_BIN_U 4
#define VISCR_QUALITY_BIN_V 2
#define VISCR_QUALITY_MIN_BIN 6 
#define VISCR_QUALITY_MIN_POINTS_PER_BIN 10
#define VISCR_QUALITY_MAX_POINTS_PER_BIN 200

#define VISCR_QUALITY_KLT_SHIFT_MIN_GREY 5
#define VISCR_QUALITY_KLT_SHIFT_MAX_GREY (4095-5)
#define VISCR_QUALITY_KLT_SHIFT_RAD 3

//these defines do not seem to be used anymore
// #define VISCR_QUALITY_ROI_U_MIN 32
// #define VISCR_QUALITY_ROI_U_MAX 480
// #define VISCR_QUALITY_ROI_V_MIN 8
// #define VISCR_QUALITY_ROI_V_MAX 72

#define VISCR_QUALITY_ROI2_U_MIN 16
#define VISCR_QUALITY_ROI2_U_MAX 464
#define VISCR_QUALITY_ROI2_V_MIN 16
#define VISCR_QUALITY_ROI2_V_MAX 176
#define VISCR_QUALITY_ROI2_SAMPLING 2

#define VISCR_QUALITY_RAW_BIN_U 3
#define VISCR_QUALITY_RAW_MIN_RECTIFIED 30

#define VISCR_QUALITY_DEBUG 0

// ~CodeReview ~ID:b877fe472d77abd0911903d97da428b3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Remove or comment dead code
/*extern f32_t viscr_quality_rightleftpowerlow(
    const SAC_Powerflow_t &Powerflow,
    const viscr_image & new_k0,
    const viscr_image & new_k1
    );*/
#if 0 // CODE NOT USED
extern SACCalibQuality_t viscr_quality_rightleftpowerlow(
    const SAC_Powerflow_t &Powerflow
    );
#endif

extern uint32 viscr_quality_disparity(float32 & viscr_quality_disparity_output,
                                      const DisparityImage_t *disparity);


#endif

