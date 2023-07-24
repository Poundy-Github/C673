/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_quality.cpp  

  DESCRIPTION:    Rectification quality measurement

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_quality.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:33CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:23CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.23 2014/02/06 13:44:57CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adaption to changed stereo image map sizes
  CHANGES:        - Added comments -  uidw0251 [Feb 6, 2014 1:44:57 PM CET]
  CHANGES:        Change Package : 216853:1 http://mks-psad:7002/im/viewissue?selection=216853
  CHANGES:        Revision 1.22 2013/08/15 14:29:03CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:03 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.21 2013/08/01 11:39:45CEST Mueller, Reik (muellerr5) 
  CHANGES:        - introduced disparity image type from CCT
  CHANGES:        --- Added comments ---  muellerr5 [Aug 1, 2013 11:39:45 AM CEST]
  CHANGES:        Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.20 2012/07/05 08:47:09CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tag (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 8:47:09 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.19 2012/06/25 09:41:09CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added code review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:41:09 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.18 2012/04/19 15:19:01CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:01 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.17 2012/03/20 16:11:44CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 20, 2012 4:11:45 PM CET]
  CHANGES:        Change Package : 101150:14 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.16 2012/03/02 11:24:52CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Mar 2, 2012 11:24:52 AM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.15 2012/02/22 17:28:48CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:49 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.14 2011/11/16 19:37:53CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Nov 16, 2011 7:37:53 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.13 2011/10/21 17:00:50CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Use only 2 vertical bins for coarse calibration (epipolar constraint)
  CHANGES:        --- Added comments ---  uid26778 [Oct 21, 2011 5:00:50 PM CEST]
  CHANGES:        Change Package : 80275:3 http://mks-psad:7002/im/viewissue?selection=80275
  CHANGES:        Revision 1.12 2011/10/19 08:59:53CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        runtime optimization on viscr_quality_disparity function
  CHANGES:        --- Added comments ---  uid26778 [Oct 19, 2011 8:59:54 AM CEST]
  CHANGES:        Change Package : 80275:2 http://mks-psad:7002/im/viewissue?selection=80275
  CHANGES:        Revision 1.11 2011/10/04 08:50:56CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 8:50:56 AM CEST]
  CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.10 2011/09/20 19:24:18CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Enable input and output error checks
  CHANGES:        --- Added comments ---  uid26778 [Sep 20, 2011 7:24:18 PM CEST]
  CHANGES:        Change Package : 77279:1 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.9 2011/09/16 11:08:15CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Check if powerflow is valid to perform quality check
  CHANGES:        --- Added comments ---  uid26778 [Sep 16, 2011 11:08:15 AM CEST]
  CHANGES:        Change Package : 77279:4 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.8 2011/09/15 14:38:11CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Reduce the calibration buffer from 11 to 3
  CHANGES:        Increase the coarse calibration ROI
  CHANGES:        Improve right left powerflow resolution
  CHANGES:        --- Added comments ---  uid26778 [Sep 15, 2011 2:38:11 PM CEST]
  CHANGES:        Change Package : 77279:4 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.7 2011/09/13 18:21:40CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        usage of fabs( ) instead of abs() (DSP compile problem)
  CHANGES:        --- Added comments ---  uidt8688 [Sep 13, 2011 6:21:40 PM CEST]
  CHANGES:        Change Package : 63914:4 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.6 2011/08/26 13:31:38CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        corner check is done inside the klt shift function
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 1:31:38 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.5 2011/07/22 16:19:45CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve rectification quality measurement
  CHANGES:        --- Added comments ---  uid26778 [Jul 22, 2011 4:19:45 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.4 2011/07/08 16:57:47CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve disparity quality measurement
  CHANGES:        --- Added comments ---  uid26778 [Jul 8, 2011 4:57:48 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.3 2011/07/07 13:11:49CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add quality measurement based on disparity map density
  CHANGES:        --- Added comments ---  uid26778 [Jul 7, 2011 1:11:49 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.2 2011/06/17 13:37:25CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve rectification quality module
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:37:26 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.1 2011/05/31 19:22:24CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj
  

**************************************************************************** */


#include <viscr_quality.hpp>
#include <viscr_corner_check.hpp>
#if (VISCR_QUALITY_DEBUG == 1)
#include <string.h>  // memset/memcpy
#endif
#include "cct_disparity_element.h"

// ~CodeReview ~ID:fba8fa2e5dcfe685a49ee57649d4bd75 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Remove or comment dead code
#if 0 // CODE NOT USED
SACCalibQuality_t viscr_quality_rightleftpowerlow(
  const SAC_Powerflow_t &Powerflow
  )
  {
  i32_t index;
  i32_t size_u;
  i32_t size_v;
  size_u = Powerflow.Width_px;
  size_v = Powerflow.Height_px;
  i32_t bin_u;
  i32_t is_rectified[VISCR_QUALITY_RAW_BIN_U];
  
  SACCalibQuality_t b_is_rectified = SAC_CalibQuality_undefined;

  if (Powerflow.valid == 1)
    {
    for (i32_t i=0; i<VISCR_QUALITY_RAW_BIN_U; i++)
      {is_rectified[i] = 0;}
    for (i32_t u = 0; u < size_u; u++)
      {
      bin_u = (u*VISCR_QUALITY_RAW_BIN_U) / size_u;
      for (i32_t v = 0; v < size_v; v++)
        {
        index = u+(v*size_u);
        if ((static_cast<ui8_t>(Powerflow.Powerflow_p[index].i8_DV)!= 0x80))
          {
          //if (std::abs(((viscr_coord)Powerflow.Powerflow_p[index].i8_DV)) <= 1)
          if (static_cast<viscr_coord>(Powerflow.Powerflow_p[index].i8_DV) == 0)
            {is_rectified[bin_u]++;}
          else
            {is_rectified[bin_u]--;}
          }
        }
      }
    ///////////////// MERGE WINDOW //////////////////
    b_is_rectified = SAC_CalibQuality_sufficient;
    for (i32_t i=0; i<VISCR_QUALITY_RAW_BIN_U; i++)
      {
      if (is_rectified[i] < VISCR_QUALITY_RAW_MIN_RECTIFIED)
        {b_is_rectified = SAC_CalibQuality_insufficient;}
      }
    }
  return b_is_rectified;
  }

#endif

uint32 viscr_quality_disparity(float32 & viscr_quality_disparity_output,
                              const DisparityImage_t *disparity)
{
  //initialize return values
  viscr_quality_disparity_output = -1.F;
  uint32 returnCode = C_SACErrors::i32_SAC_NO_ERROR;

  ui32_t viscr_quality_disparity_cnt = 0U;
  ui32_t index;

  //assert quality roi to be within the bounds of the disparity image
  if(VISCR_QUALITY_ROI2_U_MIN < 0 || VISCR_QUALITY_ROI2_V_MIN < 0
    || VISCR_QUALITY_ROI2_U_MAX >= disparity->sImgHeader.uiWidth
    || VISCR_QUALITY_ROI2_V_MAX >= disparity->sImgHeader.uiHeight) {
      returnCode = C_SACErrors::i32_SAC_INPUT_ERROR_DISPARITY_QUALITY_ROI_OUT_OF_DISPARITY_MAP_BOUNDS;
    return returnCode;
  }

  for (ui32_t v = static_cast<ui32_t>(VISCR_QUALITY_ROI2_V_MIN); v < static_cast<ui32_t>(VISCR_QUALITY_ROI2_V_MAX); v = v + static_cast<ui32_t>(VISCR_QUALITY_ROI2_SAMPLING))
  {
    for (ui32_t u = static_cast<ui32_t>(VISCR_QUALITY_ROI2_U_MIN); u < static_cast<ui32_t>(VISCR_QUALITY_ROI2_U_MAX); u = u + static_cast<ui32_t>(VISCR_QUALITY_ROI2_SAMPLING))
    {
      index = u + (v*static_cast<ui32_t>(disparity->sImgHeader.uiWidth));
      const cct::CDisparityElement dispElement = disparity->pDisparityData[index];
      /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 18.04.2012 reason: indexing by pointer faster */
      if ( dispElement.isValid() )
      {
         viscr_quality_disparity_cnt = viscr_quality_disparity_cnt + static_cast<ui32_t>((VISCR_QUALITY_ROI2_SAMPLING * VISCR_QUALITY_ROI2_SAMPLING));
      }
    }
  }
  viscr_quality_disparity_output = static_cast<f32_t>(viscr_quality_disparity_cnt) * (1.0F / static_cast<f32_t>((VISCR_QUALITY_ROI2_U_MAX-VISCR_QUALITY_ROI2_U_MIN)*(VISCR_QUALITY_ROI2_V_MAX-VISCR_QUALITY_ROI2_V_MIN)));
  // ~CodeReview ~ID:6e3da69362d72b64f38a891fc20320fd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Use define instead of magic number 1.0F
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Limit parameter to value 1. */
  if (viscr_quality_disparity_output > 1.0F)
  {
    // ~CodeReview ~ID:8689f056495002204eac4b792d373d86 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Use define instead of magic numer 1.0F
    viscr_quality_disparity_output = 1.0F;
  }

  return returnCode;
}




  




