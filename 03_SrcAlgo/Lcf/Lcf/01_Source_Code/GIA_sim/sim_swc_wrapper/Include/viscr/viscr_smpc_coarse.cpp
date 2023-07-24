/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_smpc_coarse.cpp  

  DESCRIPTION:    Coarse calibration algorithms (without disparity map)

  AUTHOR:         L. GARCIA

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_smpc_coarse.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:36CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:30CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.51 2014/02/28 10:19:34CET Ruland, Thomas (uidw0251) 
  CHANGES:        - New optimization framework (still using floating point objective)
  CHANGES:        - Single correspondence OdoYAC test framework
  CHANGES:        - Added comments -  uidw0251 [Feb 28, 2014 10:19:34 AM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.50 2014/02/14 15:12:55CET Ruland, Thomas (uidw0251) 
  CHANGES:        Added more detailed Rta instrumentation to kernel
  CHANGES:        --- Added comments ---  uidw0251 [Feb 14, 2014 3:12:55 PM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.49 2013/08/15 14:29:02CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:03 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.48 2012/08/21 13:58:18CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> First disparity refinement implementation
  CHANGES:        --- Added comments ---  uidt2765 [Aug 21, 2012 1:58:20 PM CEST]
  CHANGES:        Change Package : 156068:1 http://mks-psad:7002/im/viewissue?selection=156068
  CHANGES:        Revision 1.47 2012/07/05 13:41:09CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tag
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 1:41:10 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.46 2012/07/04 17:06:35CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 5:06:35 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.45 2012/07/02 13:17:31CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Modify priority of some findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jul 2, 2012 1:17:34 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.44 2012/06/29 18:18:40CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 29, 2012 6:18:40 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.43 2012/05/31 14:59:57CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 2:59:57 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.42 2012/05/31 14:07:20CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 2:07:21 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.41 2012/04/19 15:18:59CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:18:59 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.40 2012/04/19 13:02:53CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add corner check on left images to avoid wrong correspondences
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 1:02:53 PM CEST]
  CHANGES:        Change Package : 112131:1 http://mks-psad:7002/im/viewissue?selection=112131
  CHANGES:        Revision 1.39 2012/03/13 18:17:13CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warning (bitexactness test done)
  CHANGES:        --- Added comments ---  uid26778 [Mar 13, 2012 6:17:13 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.38 2012/02/21 15:25:13CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 21, 2012 3:25:13 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.37 2011/11/29 16:55:08CET Garcia, Lucien (uid26778) 
  CHANGES:        Improve Fine calibration runtime : less features selected per frame
  CHANGES:        --- Added comments ---  uid26778 [Nov 29, 2011 4:55:09 PM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.36 2011/11/16 19:34:11CET Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Nov 16, 2011 7:34:11 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.35 2011/11/14 11:48:48CET Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve runtime consumption
  CHANGES:        --- Added comments ---  uid26778 [Nov 14, 2011 11:48:48 AM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.34 2011/10/14 12:25:02CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.2.0 Bugfix -> Input check after initialisation of depth filed
  CHANGES:        --- Added comments ---  uidt6711 [Oct 14, 2011 12:25:02 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.33 2011/10/04 08:52:28CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 8:52:28 AM CEST]
  CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.32 2011/09/19 19:39:33CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove compilation warnings
  CHANGES:        --- Added comments ---  uid26778 [Sep 19, 2011 7:39:33 PM CEST]
  CHANGES:        Change Package : 77279:5 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.31 2011/09/15 14:38:12CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Reduce the calibration buffer from 11 to 3
  CHANGES:        Increase the coarse calibration ROI
  CHANGES:        Improve right left powerflow resolution
  CHANGES:        --- Added comments ---  uid26778 [Sep 15, 2011 2:38:12 PM CEST]
  CHANGES:        Change Package : 77279:4 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.30 2011/09/14 15:40:53CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        update profiling instrumentation
  CHANGES:        --- Added comments ---  uidt8688 [Sep 14, 2011 3:40:53 PM CEST]
  CHANGES:        Change Package : 63914:4 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.29 2011/09/09 17:22:20CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        ADD extended fine calibration mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 9, 2011 5:22:21 PM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.28 2011/09/09 15:43:20CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add extented fine calibration mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 9, 2011 3:43:20 PM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.27 2011/08/26 13:32:13CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        corner check if done inside kft shift function
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 1:32:13 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.26 2011/07/29 10:49:41CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Rejection function could be call just before to save the points in order to save run-time
  CHANGES:        Reduce the distance between correspondences
  CHANGES:        --- Added comments ---  uid26778 [Jul 29, 2011 10:49:41 AM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.25 2011/07/28 13:10:46CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add new filtering mode VISCR_SMPC_FILTERING_MODE = 1
  CHANGES:        Improve quality measurements
  CHANGES:        --- Added comments ---  uid26778 [Jul 28, 2011 1:10:46 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.24 2011/07/08 14:48:05CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        bugfix for feature rejection mechanism
  CHANGES:        --- Added comments ---  uidt8688 [Jul 8, 2011 2:48:06 PM CEST]
  CHANGES:        Change Package : 63914:2 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.23 2011/07/07 17:55:11CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        Bug fix for rejection mechanism
  CHANGES:        --- Added comments ---  uidt8688 [Jul 7, 2011 5:55:11 PM CEST]
  CHANGES:        Change Package : 63914:2 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.22 2011/07/07 16:10:43CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        bugfix formal error related to new parameter VISCR_SMPC_KLT_SHIFT_MAX_COARSE
  CHANGES:        --- Added comments ---  uidt8688 [Jul 7, 2011 4:10:43 PM CEST]
  CHANGES:        Change Package : 63914:2 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.21 2011/07/07 13:19:03CEST Kozek Werner (uidt8688) (uidt8688) 
  CHANGES:        minor changes for feature rejection logic
  CHANGES:        --- Added comments ---  uidt8688 [Jul 7, 2011 1:19:03 PM CEST]
  CHANGES:        Change Package : 63914:2 http://mks-psad:7002/im/viewissue?selection=63914
  CHANGES:        Revision 1.20 2011/07/06 19:01:44CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Autocalibration quality measurementand improvement
  CHANGES:        --- Added comments ---  uid26778 [Jul 6, 2011 7:01:45 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.19 2011/06/17 13:50:04CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Use epipolar constraint on rectified image instead of raw image. 
  CHANGES:        Should be more accurate (normal distribution) and faster (no raw image transformation)
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:50:04 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  
**************************************************************************** */

#include <cassert>
#include <cmath>
#include <viscr_SMPC.hpp>
#include <viscr_klt_shift.hpp>
#include <viscr_levmar.hpp>
#include <viscr_rotation.hpp>
#include <viscr_SMPC_constants.hpp>
#include <viscr_SMPC_calibration.hpp>
#include "sac_profile.h"
#include "sac_algo.h"
#include <viscr_corner_check.hpp>
//#include <viscr_sad.hpp>

extern C_SACAlgo c_SACAlgo;

/* ~CodeReview ~ID:5c22001eb2dd3cc457eff8364f1b0c6e ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_DEEPTRACE always defined? */
#ifndef VISCR_SMPC_DEEPTRACE
#error VISCR_SMPC_DEEPTRACE is not defined
#endif

/* ~CodeReview ~ID:fde777ebf3cf27a0e67a007f0b15d06e ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_DEEPTRACE always equal to 0? */
#if (VISCR_SMPC_DEEPTRACE!=0)
#include <..\Simulation\sim_ssc\viscr_deep_tracer.hpp>
#endif

#ifdef PC_SIM
#include "..\Simulation\sim_ssc\sim_ssc.h"
extern CSimStaticStereoCalibration *pCSimSSC;
#endif

/* ~CodeReview ~ID:4adcfccda3824263089c5303da5f57ba ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Please clarify the whole function viscr_SMPC_refine_epipolar (too many unexplained intelinked #ifdef; #else, dead code...) */
void
viscr_SMPC_refine_epipolar(
    viscr_SMPC_data & data,
    CorrespondenceRectionReason & correspondenceRectionReason,
    const viscr_image & k0,
    const viscr_image & k1,
    const viscr_coord u0, 
    const viscr_coord v0,
    const viscr_coord u1,
    const viscr_coord v1,
    const viscr_int klt_shift_max
    )
{
  // Find the bin this point would fall into
  viscr_int iBin=static_cast<viscr_int>(viscr_SMPC_coord2bin( data.param, u0, v0));

/* ~CodeReview ~ID:0639b8133ff7d52a478d932e0ff14359 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_RANDOM_SHUFFLE equal to 2? */
#if (VISCR_SMPC_RANDOM_SHUFFLE !=2 )
  // in order to avoid features with identical location
  for(viscr_uint i=0; i < data.bin_cnt_epipolar[iBin]; i++)
  {
    viscr_int16 u_dist = abs((viscr_int16) data.binned_epipolar_point_index[i][iBin][0] - u0);
    viscr_int16 v_dist = abs((viscr_int16) data.binned_epipolar_point_index[i][iBin][1] - v0);
    if (    (u_dist < MIN_DIST_BIN_FEATURE ) &&  (   v_dist < MIN_DIST_BIN_FEATURE )     )
      return;
  }
#endif


  // does the bin need more points 
  viscr_uint nBins=data.param.bins_u*data.param.bins_v;
  /* ~CodeReview ~ID:c1b5b9dedc706036e9ea6c8c4330cc6d ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use of assert function for error management: unknown behavior in case of errors */
  assert( 0<=iBin);
  assert( (viscr_uint)iBin<nBins);

  viscr_uint ptsInBins=0U;
  for( viscr_uint i=0U; i<nBins; ++i)
     { ptsInBins+=data.bin_cnt_epipolar[i]; }

  /* ~CodeReview ~ID:2aaf3c5d02b79b7ef15d94ea9522f2b6 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Else case not managed: what is happening if data.bin_cnt_epipolar[iBin] >= data.param.points_per_epipolar_bin_max[iBin]) ? */
  if( data.bin_cnt_epipolar[iBin]<data.param.points_per_epipolar_bin_max[iBin] )
     /* ~CodeReview ~ID:2061d24d27c3f2f3f7cf42974b71faef ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
     /* &&
      viscr_uint(abs( u0-u1))>=(LOW2HIGH_D(data.param.min_disp))*/
      //&& viscr_corner_check(k0,u0,v0)
  {
    // try to make it accurate
    viscr_float su=0.0F;
    viscr_float sv=0.0F;

    M_SAC_PROFILE_START(sSACRun_ACFine_ProcFineEpi_Refine_KLTshift)

#if (VISCR_SMPC_RANDOM_SHUFFLE == 2 )
      // in order to avoid features with identical location
      for(viscr_uint i=0U; i < data.bin_cnt_epipolar[iBin]; i++)
      {
        viscr_int16 temp_int_for_misra;
        temp_int_for_misra = static_cast<viscr_int16>(data.binned_epipolar_point_index[i][iBin][0]) - u0;
        viscr_int16 u_dist = ABS(temp_int_for_misra);
        temp_int_for_misra = static_cast<viscr_int16>(data.binned_epipolar_point_index[i][iBin][1]) - v0;
        viscr_int16 v_dist = ABS(temp_int_for_misra);
        //if (    (u_dist < MIN_DIST_BIN_FEATURE_DET ) &&  (   v_dist < MIN_DIST_BIN_FEATURE_DET )     )
        if (  (u_dist+v_dist) < MIN_DIST_BIN_FEATURE_DET )
        { goto FUNCTION_EXIT; }
      }
#endif

    viscr_bool klt_ok=viscr_klt_shift_fp( su, sv, 
        k0, u0, v0,
        k1, u1, v1,
        data.param.klt_shift_rad,
        data.param.klt_shift_min_grey,
        data.param.klt_shift_max_grey,
        &data.klt_accu[0],
        viscr_true);

    M_SAC_PROFILE_END(sSACRun_ACFine_ProcFineEpi_Refine_KLTshift)

    if((klt_ok==viscr_true) && (fabsf(su)<static_cast<viscr_float>(klt_shift_max)) && (fabsf(sv)<static_cast<viscr_float>(klt_shift_max)))
    {
      viscr_float u1_sad;
      viscr_float v1_sad;

#if (VISCR_SMPC_SAD_ENABLE == 1)
      if ((data.rectification_quality == SAC_CalibQuality_insufficient) && (data.algo_state == VISCR_SMPC_STATE_BUFFER_FULL) && (data.num_calib_in_state > VISCR_SMPC_SAD_ENABLE_NUM_CALIB))
      {
        M_SAC_PROFILE_START(sSACRun_ACFine_ProcFineEpi_Refine_SAD)
          viscr_sad_process( k0,  u0, v0, k1,(viscr_float)u1+su,(viscr_float)v1+sv,u1_sad,v1_sad);
        M_SAC_PROFILE_END(sSACRun_ACFine_ProcFineEpi_Refine_SAD)
      }
      else
      {
        u1_sad = (viscr_float)u1+su;
        v1_sad = (viscr_float)v1+sv;
      }
#endif
#if (VISCR_SMPC_SAD_ENABLE == 0)
       u1_sad = static_cast<viscr_float>(u1)+su;
       v1_sad = static_cast<viscr_float>(v1)+sv;
#endif

       if (viscr_corner_check(k1,static_cast<viscr_coord>(u1_sad),static_cast<viscr_coord>(v1_sad))==viscr_true) 
       {
        // transform to normalised coordinates and add to bin
        viscr_SMPC_epipolar_corr & corr=data.binned_epipolar_points[ptsInBins];

        // Add the shift only at side of secondary camera, this gives less
        // noise than symmetrical shifts.
        viscr_vec3 ptEpi0;
        viscr_vec3 ptEpi1;
        viscr_vec3 ptOri0;
        viscr_vec3 ptOri1;
        ptOri0.data[2]=1.0F;
        ptOri1.data[2]=1.0F;

        ptEpi0.data[0]=static_cast<viscr_float>(u0);
        ptEpi0.data[1]=static_cast<viscr_float>(v0);
        ptEpi0.data[2]=1.0F;
        ptEpi1.data[0]=u1_sad;//(viscr_float)u1+su;
        ptEpi1.data[1]=v1_sad;//(viscr_float)v1+sv;
        ptEpi1.data[2]=1.0F;

  #ifdef PC_SIM
        //if (pCSimSSC != NULL)
        //{
        //  pCSimSSC->SSCSetOutputDataEpiCorresp(ptEpi0.data[0], ptEpi0.data[1], ptEpi1.data[0], ptEpi1.data[1], iBin, ptsInBins);
        //}
  #endif

        // check if list of epi points has been reset
        if (ptsInBins == 0U)
        {
          // clear epipolar bins for measfreeze output
          for (viscr_uint i = 0U; i < nBins; i++)
          {
            c_SACAlgo.m_pOutputData->DebugDataOutput.bin_cnt_epipolar[i] = 0U;
          }
          for (viscr_uint i = 0U; i < 120U; i++)
          {
            c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[i].u0 = 0.0F;
            c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[i].v0 = 0.0F;
            c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[i].u1 = 0.0F;
            c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[i].v1 = 0.0F;
          }
        }

        // !!! Reik , you will have to change this, when m_pOutputData is set to const.
        // fill epipolar bins for measfreeze output
        c_SACAlgo.m_pOutputData->DebugDataOutput.bin_cnt_epipolar[iBin]++;
        c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[ptsInBins].u0 = ptEpi0.data[0];
        c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[ptsInBins].v0 = ptEpi0.data[1];
        c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[ptsInBins].u1 = ptEpi1.data[0];
        c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp[ptsInBins].v1 = ptEpi1.data[1];
        c_SACAlgo.m_pOutputData->DebugDataOutput.epicorresp_new[ptsInBins] = 1U;

/* ~CodeReview ~ID:272b7229b14761931d25c6b440b5d135 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: Is VISCR_SMPC_DEEPTRACE always equal to 0?  */
#if (VISCR_SMPC_DEEPTRACE!=0)
        {
        //   viscr_deeptrace_vector( "epi_corr", 0, ptEpi0.v);
        //   viscr_deeptrace_vector( "epi_corr", 1, ptEpi1.v);
        //   viscr_deeptrace_point( "raw_corr", 0, 2, (double)u0,(double)v0);
        //   viscr_deeptrace_point( "raw_corr", 1, 2, (double)u1,(double)v1);
        viscr_deeptrace_point_2d( "ptEpi", 0,(double)ptEpi0.data[0],(double)ptEpi0.data[1]); 
        viscr_deeptrace_point_2d( "ptEpi", 1,(double)ptEpi1.data[0],(double)ptEpi1.data[1]); 
        }
#endif
/* ~CodeReview ~ID:0ae8e68e1780f8eb3e3aa1c16fc27aca ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_EPIPOLAR_CALIBRATION_MODE always different from 0?  */
#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 0)
        // Transform to undistorted coordinates
        viscr_mat_mult_vec( ptOri0.v, data.stereo_camera.invT_k0.m, ptEpi0.v);
        viscr_mat_mult_vec( ptOri1.v, data.stereo_camera.invT_k1.m, ptEpi1.v);

        // Normalise points.
        corr.u0=(ptOri0.data[0]/ptOri0.data[2]-data.calib_k0.cu)/data.calib_k0.f;
        corr.v0=(ptOri0.data[1]/ptOri0.data[2]-data.calib_k0.cv)/(data.calib_k0.f*data.calib_k0.fs);
        corr.u1=(ptOri1.data[0]/ptOri1.data[2]-data.calib_k1.cu)/data.calib_k1.f;
        corr.v1=(ptOri1.data[1]/ptOri1.data[2]-data.calib_k1.cv)/(data.calib_k1.f*data.calib_k1.fs);
#endif
#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 1) 
        /* ~CodeReview ~ID:7fcd3ba334640d99837aaa1330e044bd ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible divisions by zero: check if data.stereo_camera.f != 0 */
        const viscr_float f_camera_f_inverse=1.0F/data.stereo_camera.f;
        corr.u0=(ptEpi0.data[0]-data.stereo_camera.u)*f_camera_f_inverse;
        corr.v0=(ptEpi0.data[1]-data.stereo_camera.v)*f_camera_f_inverse;
        corr.u1=(ptEpi1.data[0]-data.stereo_camera.u)*f_camera_f_inverse;
        corr.v1=(ptEpi1.data[1]-data.stereo_camera.v)*f_camera_f_inverse;
#endif
        /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Parameter control check. */
        if ((u0 > 0) && (v0 > 0))
        {
          /* <ln_offset:1 MISRA Rule 5-0-4: reviewer name: Garcia Lucien date: 31.05.2012 reason: u0 is positive */
          data.binned_epipolar_point_index[data.bin_cnt_epipolar[iBin]][iBin][0] = u0;
          /* <ln_offset:1 MISRA Rule 5-0-4: reviewer name: Garcia Lucien date: 31.05.2012 reason: v0 is positive */
          data.binned_epipolar_point_index[data.bin_cnt_epipolar[iBin]][iBin][1] = v0;
    /* ~CodeReview ~ID:a5d2203054ddd1ccfd8231d40c8fe2de ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
    //      data.binned_epipolar_point_index[data.bin_cnt_epipolar[iBin]][iBin][0] = u0;
    //      data.binned_epipolar_point_index[data.bin_cnt_epipolar[iBin]][iBin][1] = v0;
          data.bin_cnt_epipolar[iBin]++;
        }

       } else {
         //correspondence rejected by second corner check
         correspondenceRectionReason = RejectionReason_CornerCheck2nd;
       }
    } else {
      //correspondence rejected by klt-shift
      correspondenceRectionReason = RejectionReason_KLT;
    }
  }  //end of if( data.bin_cnt_epipolar[iBin]<data.param.points_per_epipolar_bin)
  else
  {
    //correspondence rejected because corresponding bin is full
    correspondenceRectionReason = RejectionReason_BinFull;
  }
FUNCTION_EXIT:
;
}


/// Process the images and extract a randomly selected number of points.
/// The sub-pixel accurate position is computed here. Points are transformed
/// to normalised coordinates here.
static void 
fill_bins( 
    viscr_SMPC_data & data, 
    const viscr_image & k0,
    const viscr_image & k1,
    const viscr_powerflow_result & stereo)
{
  /* ~CodeReview ~ID:9c15420924846247d34b32099fd85e3f ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use of assert function for error management: unknown behavior in case of errors */
  assert( stereo.nPoints<=data.param.max_input_coarse);

  /* ~CodeReview ~ID:fe5b91d3163574daa7cc66c76d930bfc ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
  // Go through the points in random order
  //for( viscr_uint nRandPt=stereo.nPoints; nRandPt; )
  //{
  //  viscr_uint iPt=data.random_point_index[data.random_seed_epi];
  //  ++data.random_seed_epi;
  //  if( data.random_seed_epi>=data.param.max_input_coarse)
  //    data.random_seed_epi=0;
  //  if( iPt<stereo.nPoints)
  //  {
  //    viscr_SMPC_refine_epipolar( data, 
  //        k0,
  //        k1,
  //        LOW2HIGH_U(stereo.points[iPt].u0), LOW2HIGH_V(stereo.points[iPt].v0), 
  //        LOW2HIGH_U(stereo.points[iPt].u1), LOW2HIGH_V(stereo.points[iPt].v1));
  //    --nRandPt;
  //  }
  //}

#if ((VISCR_SMPC_RANDOM_SHUFFLE == 2) || (VISCR_SMPC_RANDOM_SHUFFLE == 3))

  //reset correspondence statistics
  data.cCorrespondencesAccepted = 0;
  data.cCorrespondencesRejectedByKlt = 0;
  data.cCorrespondencesRejectedByCornerCheck1st = 0;
  data.cCorrespondencesRejectedByCornerCheck2nd = 0;
  data.cCorrespondencesRejectedByBinFull = 0;

  for( viscr_uint j = 0U; j < stereo.nPoints; j++ )
  {
    CorrespondenceRectionReason correspondenceRejectionReason;
    viscr_SMPC_refine_epipolar( data,
            correspondenceRejectionReason,
	          k0,
	          k1,
	          stereo.points[j].u0, stereo.points[j].v0, 
	          stereo.points[j].u1, stereo.points[j].v1,
            static_cast<viscr_int>(VISCR_SMPC_KLT_SHIFT_MAX_COARSE));
    if(RejectionReason_NotRejected == correspondenceRejectionReason) {
      ++data.cCorrespondencesAccepted;
    } else if(RejectionReason_KLT == correspondenceRejectionReason) {
      ++data.cCorrespondencesRejectedByKlt;
    } else if(RejectionReason_CornerCheck2nd == correspondenceRejectionReason) {
      ++data.cCorrespondencesRejectedByCornerCheck2nd;
    } else if(RejectionReason_BinFull == correspondenceRejectionReason) {
      ++data.cCorrespondencesRejectedByBinFull;
    }

	if(viscr_true == viscr_SMPC_epipolar_bins_are_full(data)) {
		break;
	}
  }

#else

  viscr_uint32 iPt = (data.random_seed_epi % stereo.nPoints);

  for( viscr_uint j = 0; j < stereo.nPoints; j++ )
  {
	    iPt = (  sac_rand(iPt) % stereo.nPoints);
		viscr_SMPC_refine_epipolar( data, 
	          k0,
	          k1,
	          LOW2HIGH_U(stereo.points[iPt].u0), LOW2HIGH_V(stereo.points[iPt].v0), 
	          LOW2HIGH_U(stereo.points[iPt].u1), LOW2HIGH_V(stereo.points[iPt].v1),
			  VISCR_SMPC_KLT_SHIFT_MAX_COARSE);

		if( viscr_SMPC_epipolar_bins_are_full( data))
			break;
  }

  data.random_seed_epi = iPt;

#endif

}


/// Perform the calibration and manage the results
/* ~CodeReview ~ID:143bab831e6eb471cbbf5c2c7f8e85c1 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Void function: maybe it could be better to return the coarse calibration process status (e.g. an int32) */
static void
calibrate_coarse(
    viscr_SMPC_data & data, 
    const viscr_timestamp & now,
    const SACCallBackHdlr_t & callBackHandler)
{
  // Compute the objective function.
  viscr_float a=0.0F;
  viscr_float c=0.0F;
  viscr_float rmse_epipolar = 0.0F;
  viscr_float rmse_improvement = 0.0F;
  
//  viscr_bool fail;
  viscr_SMPC_epipolar_calibration( data, a, c,rmse_epipolar,rmse_improvement, callBackHandler);
  
    // calibration ok, use the results
    viscr_SMPC_set_rotation( data, a, data.current_angles[1], c,rmse_epipolar,rmse_improvement, now);

    // For the first few calibrations we do not report the result
    //if( data.median_buffer_entries==data.param.median_len)
    {
      viscr_SMPC_calib_available( data);
//      fail=viscr_false;
    }
  
  /* ~CodeReview ~ID:73d2977801ad8860c3a67eee7958c4ff ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
//  if( fail==viscr_true)
	//{ viscr_SMPC_calib_taken( data); }
}

/// Perform image processing and calibration
/* ~CodeReview ~ID:b307ed24fccc6cf353557185f50c7c19 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Void function: maybe it could be better to return the calibration status */
void 
viscr_SMPC_process_coarse(
    viscr_SMPC_data & data, 
    const viscr_image & k0,
    const viscr_image & k1,
    const viscr_powerflow_result & stereo,
    const viscr_timestamp & now,
    const SACCallBackHdlr_t & callBackHandler)
{
  

  // Bins not full, the put data in the bins
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if bins are not full. */
  if( viscr_SMPC_epipolar_bins_are_full( data)==viscr_false)
    { fill_bins( data, k0, k1, stereo); }

  // If bins are full now, calibrate
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if the bin are filled. */
  if( viscr_SMPC_epipolar_bins_are_full( data)==viscr_true) {
    calibrate_coarse(data, now, callBackHandler);
  }
}
