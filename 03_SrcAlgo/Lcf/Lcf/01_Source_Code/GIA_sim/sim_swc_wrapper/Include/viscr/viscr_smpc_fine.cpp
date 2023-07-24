/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_smpc_fine.cpp  

  DESCRIPTION:    Fine calibration algorithms (with disparity map)

  AUTHOR:         L. GARCIA

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_smpc_fine.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:37CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:34CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.63 2014/03/20 13:16:30CET Mueller, Reik (muellerr5) 
  CHANGES:        - added flag VISCR_SMPC_STEREO_YAW_CALIBRATION_NONE to enable process_fine function
  CHANGES:        - Added comments -  muellerr5 [Mar 20, 2014 1:16:30 PM CET]
  CHANGES:        Change Package : 199840:1 http://mks-psad:7002/im/viewissue?selection=199840
  CHANGES:        Revision 1.62 2014/02/28 10:19:28CET Ruland, Thomas (uidw0251) 
  CHANGES:        - New optimization framework (still using floating point objective)
  CHANGES:        - Single correspondence OdoYAC test framework
  CHANGES:        --- Added comments ---  uidw0251 [Feb 28, 2014 10:19:28 AM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.61 2014/02/27 12:13:31CET Caron, Thibault (uidw3103) 
  CHANGES:        StereoYaw Calibration connection with SAC
  CHANGES:        --- Added comments ---  uidw3103 [Feb 27, 2014 12:13:31 PM CET]
  CHANGES:        Change Package : 207661:2 http://mks-psad:7002/im/viewissue?selection=207661
  CHANGES:        Revision 1.60 2014/02/14 15:12:52CET Ruland, Thomas (uidw0251) 
  CHANGES:        Added more detailed Rta instrumentation to kernel
  CHANGES:        --- Added comments ---  uidw0251 [Feb 14, 2014 3:12:52 PM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.59 2014/02/06 13:44:48CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adaption to changed stereo image map sizes
  CHANGES:        --- Added comments ---  uidw0251 [Feb 6, 2014 1:44:49 PM CET]
  CHANGES:        Change Package : 216853:1 http://mks-psad:7002/im/viewissue?selection=216853
  CHANGES:        Revision 1.58 2013/12/05 16:03:36CET Ruland, Thomas (uidw0251) 
  CHANGES:        Added PoseParameter Quality values and upgraded to i330 Rte
  CHANGES:        --- Added comments ---  uidw0251 [Dec 5, 2013 4:03:36 PM CET]
  CHANGES:        Change Package : 209690:1 http://mks-psad:7002/im/viewissue?selection=209690
  CHANGES:        Revision 1.57 2013/10/19 16:22:32CEST Mueller, Reik (muellerr5) 
  CHANGES:        - updated fill_bins_yaw():
  CHANGES:          - restricted number of new samples added to yaw bins per frame
  CHANGES:        --- Added comments ---  muellerr5 [Oct 19, 2013 4:22:33 PM CEST]
  CHANGES:        Change Package : 202434:1 http://mks-psad:7002/im/viewissue?selection=202434
  CHANGES:        Revision 1.56 2013/08/24 15:27:49CEST Mueller, Reik (muellerr5) 
  CHANGES:        - fix: use factor 0.5 on disparity values (because CCT accessor yiels the full resolution disparity)
  CHANGES:        --- Added comments ---  muellerr5 [Aug 24, 2013 3:27:50 PM CEST]
  CHANGES:        Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.55 2013/08/15 14:29:06CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:06 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.54 2013/08/01 11:40:49CEST Mueller, Reik (muellerr5) 
  CHANGES:        - introduced disparity image type from CCT
  CHANGES:        - fixed potential floating-point exception
  CHANGES:        --- Added comments ---  muellerr5 [Aug 1, 2013 11:40:50 AM CEST]
  CHANGES:        Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.53 2012/09/14 14:10:19CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> update stereo-yawangle-code (reviewed by Lucien)
  CHANGES:        --- Added comments ---  uidt2765 [Sep 14, 2012 2:10:21 PM CEST]
  CHANGES:        Change Package : 158543:1 http://mks-psad:7002/im/viewissue?selection=158543
  CHANGES:        Revision 1.52 2012/08/21 13:58:20CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> First disparity refinement implementation
  CHANGES:        --- Added comments ---  uidt2765 [Aug 21, 2012 1:58:22 PM CEST]
  CHANGES:        Change Package : 156068:1 http://mks-psad:7002/im/viewissue?selection=156068
  CHANGES:        Revision 1.51 2012/07/05 08:23:02CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 8:23:02 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.50 2012/07/02 13:15:34CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Modify priority of some findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jul 2, 2012 1:15:34 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.49 2012/06/29 18:18:42CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 29, 2012 6:18:43 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.48 2012/03/09 15:15:18CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Mar 9, 2012 3:15:18 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.47 2012/03/05 18:36:30CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Mar 5, 2012 6:36:30 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.46 2012/03/02 11:10:46CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Mar 2, 2012 11:10:46 AM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.45 2012/02/24 16:07:09CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 24, 2012 4:07:10 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.44 2012/02/22 17:28:50CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:51 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.43 2011/10/21 17:00:52CEST Garcia, Lucien (uid26778) 
  CHANGES:        Use only 2 vertical bins for coarse calibration (epipolar constraint)
  CHANGES:        --- Added comments ---  uid26778 [Oct 21, 2011 5:00:52 PM CEST]
  CHANGES:        Change Package : 80275:3 http://mks-psad:7002/im/viewissue?selection=80275
  CHANGES:        Revision 1.42 2011/10/06 16:43:03CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        remove misra lint issue
  CHANGES:        --- Added comments ---  spruckj [Oct 6, 2011 4:43:03 PM CEST]
  CHANGES:        Change Package : 79035:1 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.41 2011/10/04 18:24:33CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 6:24:33 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.40 2011/10/04 08:55:11CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 8:55:11 AM CEST]
  CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.39 2011/09/29 15:18:06CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        Integrate Radar-based Yaw-Calibration
  CHANGES:        --- Added comments ---  uidt6711 [Sep 29, 2011 3:18:06 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.38 2011/09/19 19:39:34CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove compilation warnings
  CHANGES:        --- Added comments ---  uid26778 [Sep 19, 2011 7:39:34 PM CEST]
  CHANGES:        Change Package : 77279:5 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.37 2011/09/14 10:46:49CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add extented fine mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 14, 2011 10:46:50 AM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.36 2011/09/12 17:05:26CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add extended fine mode
  CHANGES:        --- Added comments ---  uid26778 [Sep 12, 2011 5:05:26 PM CEST]
  CHANGES:        Change Package : 77279:2 http://mks-psad:7002/im/viewissue?selection=77279
  CHANGES:        Revision 1.35 2011/09/05 17:17:34CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve disparity accuracy
  CHANGES:        --- Added comments ---  uid26778 [Sep 5, 2011 5:17:34 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.34 2011/08/26 13:35:04CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Corner check in done inside klt shift function
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 1:35:04 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.33 2011/08/26 10:25:25CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Integration of new yaw angle calibration algoritm (Daimler update)
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 10:25:25 AM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.32 2011/08/22 13:08:18CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        started to implement the corrected yaw angle correction via stereo
  CHANGES:        --- Added comments ---  uidt6711 [Aug 22, 2011 1:08:18 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.31 2011/07/06 19:01:46CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Autocalibration quality measurementand improvement
  CHANGES:        --- Added comments ---  uid26778 [Jul 6, 2011 7:01:46 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.30 2011/06/17 13:52:06CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Check corner only if the bins are not full
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:52:06 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298

  
**************************************************************************** */

#include <cmath>
//#include <cfloat>
#include <viscr_SMPC.hpp>
#include <viscr_SMPC_constants.hpp>
#include <viscr_SMPC_calibration.hpp>
#include <viscr_levmar.hpp>
#include <viscr_rotation.hpp>
#include <viscr_klt_shift.hpp>
#include <viscr_corner_check.hpp>
#include "sac_profile.h"
#include <viscr_transformation.hpp>

#include "sac_image_access.h"
#include "sac_rta.h"

#include "cct_disparity_element.h"


#ifndef VISCR_SMPC_DEEPTRACE_YAW
#error VISCR_SMPC_DEEPTRACE_YAW is not defined
#endif


#if (VISCR_SMPC_DEEPTRACE_YAW!=0)
#include <..\Simulation\sim_ssc\viscr_deep_tracer.hpp>
int deep_tracer;
#endif

#ifndef VISCR_SMPC_DEEPTRACE
#error VISCR_SMPC_DEEPTRACE is not defined
#endif


#if (VISCR_SMPC_DEEPTRACE!=0)
#include <..\Simulation\sim_ssc\viscr_deep_tracer.hpp>
#endif


/*#ifndef VISCR_SMPC_REMOVE_YAW_IN_FINE
#error VISCR_SMPC_REMOVE_YAW_IN_FINE is not defined
#endif*/

#ifndef VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER
#error VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER is not defined
#endif

#ifndef VISCR_SMPC_RIGHT_REFERENCE
#error VISCR_SMPC_RIGHT_REFERENCE is not defined
#endif

/// Get a coded disparity value from the disparity image
static DisparityElement_t
get_disparity_value(
    const DisparityImage_t * disp_img,
    const viscr_coord u,
    const viscr_coord v)
{
  return disp_img->pDisparityData[u + (v * disp_img->sImgHeader.uiWidth)];
}


/// Return true if the coded disparity value has its valid flag set.
static boolean_t
valid_disparity(
    const viscr_pixel coded_disp)
{
 // return ((coded_disp & 1U) != 0);
	boolean_t result = false;
	if ((coded_disp & 1U) > static_cast<viscr_pixel>(0))
	   {
         result = true;
	   }

	return result;
}


/// Remove the valid flag and return the 7.4 fix point value
static viscr_pixel
fp_disparity( 
    const viscr_pixel coded_disp)
{
  /* ~CodeReview ~ID:d504189ce5135a54a4deb42935715744 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use of assert function for error management: unknown behavior in case of \$r\$r\$nerrors */
  assert( valid_disparity( coded_disp));
  return (coded_disp ^ 1U) >> 1;
}


/* ~CodeReview ~ID:177a5492f05b8eb8293e1fbbb99546e4 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISC_SMPC_REMOVE_YAW_IN_FINE always equal to 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// Convert an entry in the disparity image to a pixel displacement. Round to
/// nearest pixel.
static viscr_uint disp2pix( const viscr_pixel coded_disp)
{
  return (static_cast<viscr_uint>(fp_disparity( coded_disp)+7U)/16U);
}
#endif

/// Convert an entry in the disparity image to a sub-pixel displacement
static viscr_float
disp2float( 
    const viscr_pixel coded_disp)
{
  /* ~CodeReview ~ID:ff6b4c9d8f23259c1c4e1b6c3d041caf ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers */
  return (static_cast<viscr_float>(fp_disparity( coded_disp))/16.0F);
}

/* ~CodeReview ~ID:0a7e9421c7cf99691a7a488b76f7d4ab ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISC_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// The disparity is added because the right camera is the reference
static viscr_coord add_disparity(const viscr_coord u,const viscr_coord d)
{
#if (VISCR_SMPC_RIGHT_REFERENCE==1)
  return (u+d);
#else
  return (u-d);
#endif
}
#endif

/// The disparity is added because the right camera is the reference
static viscr_float change_disparity_float(const viscr_coord d,const viscr_float su)
{
#if (VISCR_SMPC_RIGHT_REFERENCE==1)
  return (static_cast<viscr_float>(d)+su);
#else
  return (static_cast<viscr_float>(d)-su);
#endif
}

/** Go through all flow points and build the correspondences. */
static void
fill_bins_epipolar(
    viscr_SMPC_data & data,
    const viscr_image & k0,
    const viscr_image & k1,
    const DisparityImage_t * disparity,
    const viscr_powerflow_result & flow,
    const FlowImage_t * pFlowImageTemporal
    )
{
#if ((VISCR_SMPC_RANDOM_SHUFFLE == 1 )|| (VISCR_SMPC_RANDOM_SHUFFLE == 2))

	viscr_uint iFlow; // = (data.random_seed_epi % flow.nPoints);
  viscr_uint bin_cnt_epipolar_old = data.bin_cnt_epipolar[0]+data.bin_cnt_epipolar[1]+data.bin_cnt_epipolar[2]+data.bin_cnt_epipolar[3];
  viscr_uint bin_cnt_epipolar_new = bin_cnt_epipolar_old;
  viscr_uint bin_cnt_epipolar_dif_max;
  bin_cnt_epipolar_dif_max = MAX_POINTS_PER_FRAME_FINE;
/* ~CodeReview ~ID:16f60941a0cb103dd2d0cff7a2475442 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_SAD_ENABLE always different from 1? */
#if (VISCR_SMPC_SAD_ENABLE == 1)
  if ((data.rectification_quality == SAC_CalibQuality_insufficient) && (data.algo_state == VISCR_SMPC_STATE_BUFFER_FULL) && (data.num_calib_in_state > VISCR_SMPC_SAD_ENABLE_NUM_CALIB))
     bin_cnt_epipolar_dif_max = MAX_POINTS_PER_FRAME_FINE_SAD; 
#endif

  //flow image temporal access
  SAC::ImageAccess fitAccess(pFlowImageTemporal->sImgHeader);
  /* ~CodeReview ~ID:f3b4c49e94cbdeba61d8c48cc4a24a1e ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:The incrementation condition does not only depend on j, but also on bin_cnt_epipolar_new-bin_cnt_epipolar_old: make sure that the for loop is OK. */

  //reset correspondence statistics
  data.cCorrespondencesAccepted = 0;
  data.cCorrespondencesRejectedByKlt = 0;
  data.cCorrespondencesRejectedByCornerCheck1st = 0;
  data.cCorrespondencesRejectedByCornerCheck2nd = 0;
  data.cCorrespondencesRejectedByBinFull = 0;
  for( viscr_uint j = 0U; ((j < flow.nPoints) && ((bin_cnt_epipolar_new-bin_cnt_epipolar_old) < bin_cnt_epipolar_dif_max)); j++ )
  {
    //iFlow = (  viscr_SMPC_rand(iFlow) % flow.nPoints);
    iFlow = j;

    // There is a corner at u,v in the current k0 image.
    viscr_coord u0=flow.points[iFlow].u0;
    viscr_coord v0=flow.points[iFlow].v0;

    // The corresponding point is in the same row, but displaced by the
    // disparity.
    
    // ATTENTION: In the following line, it is assumed that both FlowImage and
    // Disparity image/map have the same vertical offset i.e. to get the disparity
    // at a feature location one can access the same coordinate u0, v0. This is
    // not true anymore if disp and flow map have different iOffsetY.
    const cct::CDisparityElement dispElement = get_disparity_value(disparity, u0, v0);
    if( dispElement.isValid() )
    {
      //viscr_coord u1= add_disparity(u0,disp2pix( coded_disp));
      viscr_float temp_float_for_misra = static_cast<viscr_float>(fitAccess.LOW2HIGH_U_FLOAT(change_disparity_float(u0, dispElement.asFloat()*0.5f)));
	  viscr_coord u1_high = static_cast<viscr_coord>(temp_float_for_misra);
      viscr_coord v1=v0;

      /* ~CodeReview ~ID:de2c3f47d7019180ac27f558d95766e3 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
      //if( viscr_corner_check(
      //	k0,
      //	LOW2HIGH_U(u0),
      //	LOW2HIGH_V(v0)))
      //    28*16)) // 12 bit image 28 was for 8 bit
      //{

      // Process and store the point.
      CorrespondenceRectionReason correspondenceRejectionReason;
      M_SAC_PROFILE_START(sSACRun_ACFine_ProcFineEpi_Refine)
			viscr_SMPC_refine_epipolar( data, correspondenceRejectionReason, k0, k1, fitAccess.LOW2HIGH_U(u0), fitAccess.LOW2HIGH_V(v0), u1_high/*LOW2HIGH_U(u1)*/, fitAccess.LOW2HIGH_V(v1),static_cast<viscr_int>(VISCR_SMPC_KLT_SHIFT_MAX_FINE));
      M_SAC_PROFILE_END(sSACRun_ACFine_ProcFineEpi_Refine)
        if(RejectionReason_NotRejected == correspondenceRejectionReason) {
          ++data.cCorrespondencesAccepted;
        } else if(RejectionReason_KLT == correspondenceRejectionReason) {
          ++data.cCorrespondencesRejectedByKlt;
        } else if(RejectionReason_CornerCheck2nd == correspondenceRejectionReason) {
          ++data.cCorrespondencesRejectedByCornerCheck2nd;
        } else if(RejectionReason_BinFull == correspondenceRejectionReason) {
          ++data.cCorrespondencesRejectedByBinFull;
        }
        //}
      bin_cnt_epipolar_new = data.bin_cnt_epipolar[0]+data.bin_cnt_epipolar[1]+data.bin_cnt_epipolar[2]+data.bin_cnt_epipolar[3];
    }

    if( viscr_SMPC_epipolar_bins_are_full( data) == viscr_true) {
		break;
	}
  } // end of ( viscr_uint j = 0; j < flow.nPoints; j++ )

  //data.random_seed_epi = iFlow;

#endif
/* ~CodeReview ~ID:fa9182adfca1bd45a42011728d1da3f4 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_RANDOM_SHUFFLE always different from 0? */
#if (VISCR_SMPC_RANDOM_SHUFFLE == 0) // deterministic choice of flow vectors

  // Go through the points in deterministic order
  for( viscr_uint iFlow = 0; iFlow < flow.nPoints; iFlow++   ) // flow.nPoints is determined by 
  {
      // There is a corner at u,v in the current k0 image.
      viscr_coord u0=flow.points[iFlow].u0;
      viscr_coord v0=flow.points[iFlow].v0;

      // The corresponding point is in the same row, but displaced by the disparity.
      viscr_pixel coded_disp=get_disparity_value( disparity, u0, v0);
      if( valid_disparity( coded_disp))
      {
		    //viscr_coord u1= add_disparity(u0,disp2pix( coded_disp));
      viscr_coord u1_high = LOW2HIGH_U_FLOAT(change_disparity_float(u0,disp2float( coded_disp)));
            viscr_coord v1=v0;

			//if (viscr_corner_check(k0, 
			//	                  LOW2HIGH_U(u0),
			//					  LOW2HIGH_V(v0))   )
			{
			 // Process and store the point.
			 M_SAC_PROFILE_START(sSACRun_ACFine_ProcFineEpi_Refine)
				viscr_SMPC_refine_epipolar( data, k0, k1, LOW2HIGH_U(u0), LOW2HIGH_V(v0), u1_high/*LOW2HIGH_U(u1)*/, LOW2HIGH_V(v1));
			 M_SAC_PROFILE_END(sSACRun_ACFine_ProcFineEpi_Refine)
			}// 
	  } // if( valid_disparity( coded_disp))
  }  // end of loop: for( viscr_uint iFlow = 0; iFlow < flow.nPoints; iFlow++   )
#endif
}
/* ~CodeReview ~ID:a588c36864f994ca286e95b493d7cf33 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// Compute the 3d reconstruction of a point from disparity
static void
reconstruct(
  viscr_vec4 & p,
  const viscr_coord u,  
  const viscr_coord v, 
  const viscr_float d, 
  const viscr_stereo_camera & stereo_camera)
{
  /* ~CodeReview ~ID:2242b41013d478df7d61257e1049901e ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible divisions by zero: check if d != 0 and stereo_camera.f != 0 */
  viscr_float z=(stereo_camera.f*stereo_camera.b)/d;
  p.data[0]=(z*(static_cast<viscr_float>(u)-stereo_camera.u))/stereo_camera.f;
  p.data[1]=(z*(static_cast<viscr_float>(v)-stereo_camera.v))/stereo_camera.f;
  p.data[2]=z;
}
#endif

/* ~CodeReview ~ID:ad008646dd9008de46c969d9c6882904 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// Check if the projected point pn is close to (u,v)
static bool 
similar_flow(
    const viscr_vec4 & pn,
    const viscr_stereo_camera & stereo_camera,
    const viscr_SMPC_param & param,
    const viscr_coord u,
    const viscr_coord v)
{
  /* ~CodeReview ~ID:408651ea150453d365dcdad295efddd2 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible division by zero: check if pn.data[2] != 0 */
  viscr_float un=((stereo_camera.f*pn.data[0])/pn.data[2])+stereo_camera.u;
  viscr_float vn=((stereo_camera.f*pn.data[1])/pn.data[2])+stereo_camera.v;
#if (VISCR_SMPC_DEEPTRACE_SIMILARFLOW == 1)
  
  viscr_deeptrace_point("Observed_flow",0,2, (double)(u),(double)(v) );
  viscr_deeptrace_point("Predicted_flow",0,2, (double)(un),(double)(vn) );

  if (fabs(un-u)<=param.max_flow_error_horizontal && fabs(vn-v)<=param.max_flow_error_vertical)
  {
    viscr_deeptrace_point("Accepted_flow",0,2, (double)(u),(double)(v) );
  }
  else
  {
    viscr_deeptrace_point("Rejected_flow",0,2, (double)(u),(double)(v) );
  }
#endif
  /* ~CodeReview ~ID:ef1354b36221daf6ad4e9af88c9889a0 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Split up complicated statement into multiple more comprehensible ones */
  return (((fabsf(un-static_cast<viscr_float>(u))<=static_cast<viscr_float>(param.max_flow_error_horizontal)) && (fabsf(vn-static_cast<viscr_float>(v))<=static_cast<viscr_float>(param.max_flow_error_vertical))));
}



/** Compute the length of the flow vector.  */
static viscr_uint 
compute_flow_len(
    const viscr_coord u0,
    const viscr_coord v0,
    const viscr_coord u1,
    const viscr_coord v1)
{
  viscr_coord du=u0-u1;
  viscr_coord dv=v0-v1;

  return (static_cast<viscr_uint>((du*du)+(dv*dv)));
}
#endif

/* ~CodeReview ~ID:71451a651c47ca794afca094157b187f ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/** refine the raw correspondences by klt shift. If this succeeds, store as
* much of as we have room for.
*/
static void 
refine_and_store_corr(
                      viscr_SMPC_data & data,
                      const viscr_image & new_k0,
                      const viscr_image & new_k1,
                      viscr_coord u_new,
                      viscr_coord v_new,
                      viscr_coord d_new,
                      const viscr_image & old_k0,
                      const viscr_image & old_k1,
                      viscr_coord u_old,
                      viscr_coord v_old,
                      viscr_coord d_old,
                      const viscr_uint iBin,
                      const viscr_mat44 & H_cam_new_old,
                      const viscr_mat44 & H_cam_old_new)
{
  // Refine the disparities by KLT_shift. This is for the current image. Get a
  // better disparity and a vertical displacement.
  viscr_float su_new=0.0F;
  viscr_float sv_new=0.0F;
  viscr_bool klt_new_ok=viscr_klt_shift_fp( su_new, sv_new,
    new_k0, u_new, v_new,
    new_k1, add_disparity(u_new,d_new), v_new,
    data.param.klt_shift_rad,
    data.param.klt_shift_min_grey,
    data.param.klt_shift_max_grey,
    &data.klt_accu[0],
    viscr_true);
  // if the klt shift was ok and gives reasonable results
#if !defined KLT_SHIFT
  if( (klt_new_ok == viscr_true) && (std::fabsf(su_new)<VISCR_SMPC_KLT_SHIFT_MAX_FINE) && (std::fabsf(sv_new)<VISCR_SMPC_KLT_SHIFT_MAX_FINE))
#endif
  {
	  
  /* ~CodeReview ~ID:7c46250f8914047465bb5b9a77083477 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove or document possible useless comments */
  //  // Check if we can reuse this correspondence for the epipolar constraint
  //  // as well. We use the closer one to get larger disparities
  //  viscr_uint iBin_epi=viscr_SMPC_coord2bin( data.param, u_new, v_new);

  //  // does the bin need more points 
  //  viscr_uint nBins=data.param.bins_u*data.param.bins_v;
  
  /* ~CodeReview ~ID:8a1d16f21ab538a4183a3fef1b61052f ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:use of assert function for error management. Unknown behavior in case of \$r\$r\$nerrors */
  //  assert( 0<=iBin_epi);
  //  assert( (viscr_uint)iBin_epi<nBins);

  //  //assert( d_new>=viscr_coord(data.param.min_disp));
  //  if( data.bin_cnt_epipolar[iBin_epi]<data.param.points_per_epipolar_bin)
  //  {
  //    viscr_uint ptsInBins_epi=0;
  //    for( viscr_uint i=0; i<nBins; ++i)
  //      ptsInBins_epi+=data.bin_cnt_epipolar[i];
  //   
  //   // assert( ptsInBins_epi<data.binned_epipolar_points.size());
  //    viscr_SMPC_epipolar_corr & corr=data.binned_epipolar_points[ptsInBins_epi];

  //    // Add the shift only at side of secondary camera, this gives less
  //    // noise than symmetrical shifts.
  //    viscr_vec3 ptEpi0;
  //    viscr_vec3 ptEpi1;
  //    viscr_vec3 ptOri0;
  //    viscr_vec3 ptOri1;
  //    ptOri0.data[2]=1.0f;
  //    ptOri1.data[2]=1.0f;

  //    ptEpi0.data[0]=(viscr_float)u_new;
  //    ptEpi0.data[1]=(viscr_float)v_new;
  //    ptEpi0.data[2]=1.0f;
  //    ptEpi1.data[0]=(viscr_float)add_disparity(u_new,d_new)+su_new;
  //    ptEpi1.data[1]=(viscr_float)v_new+sv_new;
  //    ptEpi1.data[2]=1.0f;

  //    // Transform to undistorted coordinates
  //    viscr_mat_mult_vec( ptOri0.v, data.stereo_camera.invT_k0.m, ptEpi0.v);
  //    viscr_mat_mult_vec( ptOri1.v, data.stereo_camera.invT_k1.m, ptEpi1.v);

  //    // Normalise points.
  /* ~CodeReview ~ID:e3deaeaf7cf2a14d808e138e6e22223d ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible divisions by zero */
  //    corr.u0=(ptOri0.data[0]/ptOri0.data[2]-data.calib_k0.cu)/data.calib_k0.f;
  //    corr.v0=(ptOri0.data[1]/ptOri0.data[2]-data.calib_k0.cv)/(data.calib_k0.f*data.calib_k0.fs);
  //    corr.u1=(ptOri1.data[0]/ptOri1.data[2]-data.calib_k1.cu)/data.calib_k1.f;
  //    corr.v1=(ptOri1.data[1]/ptOri1.data[2]-data.calib_k1.cv)/(data.calib_k1.f*data.calib_k1.fs);

  //    data.bin_cnt_epipolar[iBin_epi]++;
  //  }


  //// Accumulate for yaw angle
  /*viscr_float su_old=0.0f;
  viscr_float sv_old=0.0f;*/
  //viscr_bool klt_old_ok=viscr_klt_shift_fp( su_old, sv_old,
  //    old_k0, u_old, v_old,
  //    old_k1, add_disparity(u_old,d_old), v_old,
  //    data.param.klt_shift_rad,
  //    data.param.klt_shift_min_grey,
  //    data.param.klt_shift_max_grey,
  //    &data.klt_accu[0],
  //    viscr_true);
  //if( klt_old_ok && fabs(su_old)<VISCR_SMPC_KLT_SHIFT_MAX_FINE && fabs(sv_old)<VISCR_SMPC_KLT_SHIFT_MAX_FINE)
  //{
  //  viscr_uint ptsInBins=iBin*data.param.points_per_yaw_bin+data.bin_cnt_yaw[iBin];
  //  viscr_SMPC_yaw_corr & corr=data.binned_yaw_points[ptsInBins];
  //  viscr_mat_copy( corr.H_cam_new_old.m, H_cam_new_old.m);
  //  viscr_mat_copy( corr.H_cam_old_new.m, H_cam_old_new.m);

  //  // Sub-pixel shifts must be subtracted as disparity gets subtracted
  //  // also.
  //  corr.pt_new.u=u_new;
  //  corr.pt_new.v=v_new;
  //  corr.pt_new.d=change_disparity_float(d_new,su_new);

  //  corr.pt_old.u=u_old;
  //  corr.pt_old.v=v_old;
  //  corr.pt_old.d=change_disparity_float(d_old,su_old);

  //  data.bin_cnt_yaw[iBin]++;
  //}

  // Accumulate for yaw angle
  viscr_float su_old=0.0F;
  viscr_float sv_old=0.0F;
  viscr_bool klt_old_ok=viscr_klt_shift_fp( su_old, sv_old,
    old_k0, u_old, v_old,
    old_k1, add_disparity(u_old,d_old), v_old,
    data.param.klt_shift_rad,
    data.param.klt_shift_min_grey,
    data.param.klt_shift_max_grey,
    &data.klt_accu[0], 
    viscr_true);
	
#if !defined KLT_SHIFT
  if( (klt_old_ok==viscr_true) && (std::fabsf(su_old)<VISCR_SMPC_KLT_SHIFT_MAX_FINE) && (std::fabsf(sv_old)<VISCR_SMPC_KLT_SHIFT_MAX_FINE))
#endif
  {
    viscr_uint ptsInBins=(iBin*data.param.points_per_yaw_bin)+data.bin_cnt_yaw[iBin];
    viscr_SMPC_yaw_corr & corr=data.binned_yaw_points[ptsInBins];

    // Sub-pixel shifts must be subtracted as disparity gets subtracted
    // also.
    corr.pt_new.u=u_new;
    corr.pt_new.v=v_new;
    corr.pt_new.d=change_disparity_float(d_new,su_new);

    corr.pt_old.u=u_old;
    corr.pt_old.v=v_old;
    corr.pt_old.d=change_disparity_float(d_old,su_old);

    // new and old subpixel accurate disparities 
    viscr_float cd_new = corr.pt_new.d;
    viscr_float cd_old = corr.pt_old.d;

    /// camera constant
    viscr_float fb = data.stereo_camera.f*data.stereo_camera.b;

    // Driven distance
    viscr_float driven_distance = viscr_transformation_translationNorm( H_cam_new_old);

    // calculate error
    viscr_float cd_add = (cd_old + cd_new);
    
    // We only do it while driving forward
    if( cd_old < cd_new)
    { 
      /* ~CodeReview ~ID:641f53bf139a6dd23b0d064c1597f2f6 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible division by zero: check if driven_distance != 0 */
      /* ~CodeReview ~ID:e925867b3879dd0a72dc440ea6dcec7b ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use meaningful define instead of magic numbers */
      viscr_float dd_radikant = ((cd_add*cd_add)/4.0F) + (((fb/driven_distance) * (cd_new-cd_old)) - (cd_old * cd_new));
      /* ~CodeReview ~ID:9ca5e93e2c48ecfb3ce118a43067672b ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers */
      if( dd_radikant >= 1e-9F)
      {
        /* ~CodeReview ~ID:e925867b3879dd0a72dc440ea6dcec7b ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible square root of a negative number: check if dd_radikant >= 0 */
        viscr_float f_dd_radikant_sqrt=sqrtf(dd_radikant);      //helper variable to reduce the number of sqrts
        viscr_float dd1 = -(cd_add/2.0F) + f_dd_radikant_sqrt;
        viscr_float dd2 = -(cd_add/2.0F) - f_dd_radikant_sqrt;
        // We need to take the smaller value as the second solution would
        // decalibrate such that our point pair reconstructs behind the
        // camera.
        if( std::fabsf(dd1) < std::fabsf(dd2))
          {corr.deltaD = dd1;}
        else
          {corr.deltaD = -dd1;}

#if (VISCR_SMPC_DEEPTRACE_YAW!=0)
        viscr_deeptrace_point( "yaw_bin_pt_raw", 0, 8, 
          viscr_float(ptsInBins),
          viscr_float(u_new), 
          viscr_float(v_new), 
          viscr_float(d_new), 
          viscr_float(u_old), 
          viscr_float(v_old), 
          viscr_float(d_old),
          viscr_float(dd1));
#endif

        data.bin_cnt_yaw[iBin]++;
      }
    }
  }
  }
}
#endif
/* ~CodeReview ~ID:77908cbe906a2707e37044aba3a7d834 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// Find all points that can be used to fill the yaw bins.
static void
fill_bins_yaw( 
    viscr_SMPC_data & data,
#ifdef _TMS320C6X
    const DisparityImage_t *restrict disparity_old,
    const DisparityImage_t *restrict disparity_new,
#else
    const DisparityImage_t * disparity_old,
    const DisparityImage_t * disparity_new,
#endif
    const viscr_powerflow_result & flow,
    const viscr_mat44 & H_car_new_old,
    const viscr_image & new_k0,
    const viscr_image & new_k1,
    const viscr_image & old_k0,
    const viscr_image & old_k1,
    const FlowImage_t * pFlowImageTemporal)
{
  viscr_vec4 pt0;
  viscr_vec4 pt1;
  /* ~CodeReview ~ID:11c8302026f593937f911e5f5276951e ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers */
  pt0.data[3]=1.0F;

  // Compute the total camera motion. This is important for tight curves as
  // the displacement between camera and rear axle becomes important.
  //
  // H_cam_new_old=H_cam_car * H_car_new_old * H_car_cam
  viscr_mat44 H_cam_new_old;
  viscr_mat44 temp;
  viscr_mat_mult_mat( temp.m, H_car_new_old.m, data.param.H_car_cam.m);
  viscr_mat_mult_mat( H_cam_new_old.m, data.param.H_cam_car.m, temp.m);

  // Invert the transformation
  viscr_mat44 H_cam_old_new;
  viscr_invert_transformation( H_cam_old_new, H_cam_new_old);

  // save bin count before loop
  viscr_uint old_bin_count = data.bin_cnt_yaw[0];

  //disparity image access
  SAC::ImageAccess diAccess(disparity_new->sImgHeader);

  //flow image temporal access
  SAC::ImageAccess fitAccess(pFlowImageTemporal->sImgHeader);

  // Go through the points in random order
  //for( viscr_uint iRandPt=0; iRandPt<data.param.max_input_coarse; ++iRandPt)
  for( viscr_uint j = 0U; j < flow.nPoints; j++ )
	{
		viscr_uint iFlow = j;
    //viscr_uint iFlow=data.random_point_index[iRandPt];
    //if( iFlow<flow.nPoints)
    {
      // There is a flow vector at u,v in the current image.
      viscr_coord u_new=flow.points[iFlow].u0;
      viscr_coord v_new=flow.points[iFlow].v0;
      viscr_coord u_old=flow.points[iFlow].u1;
      viscr_coord v_old=flow.points[iFlow].v1;

   /* ~CodeReview ~ID:c784af3d20b5ec45aa87a9576ff4d27c ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
   //   if( viscr_corner_check(
   //     new_k0,
   //     LOW2HIGH_U(u_new),
   //     LOW2HIGH_V(v_new),
   //     28*16)) // 12 bit image 28 was for 8 bit
      {

        if( v_new>=static_cast<viscr_coord>(data.param.horizon) )
        {
          viscr_uint flow_len=compute_flow_len( u_new, v_new, u_old, v_old);
          if( flow_len>=data.param.min_flow_len)
          {
            // ATTENTION: In the following line, it is assumed that both FlowImage and
            // Disparity image/map have the same vertical offset i.e. to get the disparity
            // at a feature location one can access the same coordinate u0, v0. This is
            // not true anymore if disp and flow map have different iOffsetY.
            cct::CDisparityElement dispElement_new = get_disparity_value(disparity_new, u_new, v_new);
            cct::CDisparityElement dispElement_old = get_disparity_value(disparity_old, u_old, v_old);

            if( dispElement_new.isValid() && dispElement_old.isValid() ) 
            {
              /* ~CodeReview ~ID:cc0cb3b6a10d2ba7154b596d44f82727 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove possible useless comments */
              //viscr_uint d_new=disp2pix(coded_disp_new);
              //viscr_uint d_old=disp2pix(coded_disp_old);
              viscr_float d_new = dispElement_new.asFloat()*0.5f;
              viscr_float d_old = dispElement_old.asFloat()*0.5f;
              if( (data.param.min_disp<=d_new) && (data.param.min_disp<=d_old))
              {
                // Find the bin this point would fall into
                viscr_uint dBin=static_cast<viscr_uint>(d_old);
                if( dBin>=data.param.max_disp)
                  {dBin=(data.param.max_disp-1U);}
                /* ~CodeReview ~ID:2e62807bd04a767315b37eb08572056b ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible division by zero: check if data.param.max_disp-data.param.min_disp != 0 */
                viscr_uint iBin=( (data.param.bins_d*(dBin-data.param.min_disp))/(data.param.max_disp-data.param.min_disp));
                /* ~CodeReview ~ID:a5334cac78ed382940f7fb2ca129f6da ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use of assert function for error management: unknown behavior in case of \$r\$r\$nerrors */
                assert( iBin<data.param.bins_d);

                if (   (data.bin_cnt_yaw[iBin] < data.param.points_per_yaw_bin)
                    && ((data.bin_cnt_yaw[iBin] - old_bin_count) < MAX_YAW_SAMPLES_PER_FRAME)
                   )
                {
                  // check if the flow is predicted by the odometry.
                  reconstruct(
                      pt0,
                      fitAccess.LOW2HIGH_U(u_new),
                      fitAccess.LOW2HIGH_V(v_new),
					            diAccess.LOW2HIGH_D_FLOAT(dispElement_new.asFloat()*0.5f),
                      data.stereo_camera);
                  viscr_mat_mult_vec( pt1.v, H_cam_old_new.m, pt0.v);


                  if( similar_flow( pt1, data.stereo_camera, data.param, fitAccess.LOW2HIGH_U(u_old), fitAccess.LOW2HIGH_V(v_old)))
                    {refine_and_store_corr( 
                        data,
                        new_k0, new_k1, fitAccess.LOW2HIGH_U(u_new), fitAccess.LOW2HIGH_V(v_new), static_cast<viscr_coord>(diAccess.LOW2HIGH_D_FLOAT(d_new)),
                        old_k0, old_k1, fitAccess.LOW2HIGH_U(u_old), fitAccess.LOW2HIGH_V(v_old), static_cast<viscr_coord>(diAccess.LOW2HIGH_D_FLOAT(d_old)),
                        iBin,
                        H_cam_new_old,
                        H_cam_old_new
                        );}
                } //if( data.bin_cnt_yaw[iBin]<data.param.points_per_yaw_bin)
                else
                {
                  // stop loop if max points to add are reached
                  break;
                }
              } //if( data.param.min_disp<=d_new && data.param.min_disp<=d_old)
            } //if( valid_disparity( coded_disp_new) && valid_disparity( coded_disp_old))
          } // if( v_new>=(viscr_coord)data.param.horizon )
        } //if( v_new>=(viscr_coord)data.param.horizon )
      } //viscr_corner_check
    }
  }
}
#endif

/* ~CodeReview ~ID:f9d40951b2da48ad14ac66f708f6b5fb ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
// User data for yaw angle estimation. 
struct est_yaw_helper
{
  /// Pointer to SMPC application data
  viscr_SMPC_data * data;


  /// M-Estimator data
  viscr_SMPC_rampme_data mEstData;


  viscr_vec4 pt0;
  viscr_vec4 pt1;

  /// Temporal storage for one row of the equation system
  viscr_vec1 row;


  /// Temporal storage for one set of error
  viscr_vec2 delta;


  /// Temporal storage for one sub-Jacobian
  viscr_mat21 smallJ;


  /// Default constructor to make compiler happy
  est_yaw_helper() { }

  private:
    est_yaw_helper( const est_yaw_helper &);
    est_yaw_helper & operator=( const est_yaw_helper &);
};
#endif

/* ~CodeReview ~ID:632ecaa9522ec1e4893aafc9850a5a3c ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/** Compute the 3D position p3 from the given correspondence p2, assuming the
 * camera k1 is rotated by angle beta from standard geometry. Since this
 * standard geometry, we can do this in 2d (bird's eye view).
 */
static void
unproject( 
    viscr_vec4 & P3,
    const viscr_SMPC_yaw_point & p2,
    viscr_float disparity,
    const est_yaw_helper * const data)
{
  reconstruct( P3, p2.u, p2.v, disparity, data->data->stereo_camera);
}
#endif
/* ~CodeReview ~ID:57db35916bc3f30e59b9a6b7c9a47305 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/** Compute the disparity using the old stereo camera. */
static viscr_float
project(
    const viscr_vec4 & P3,
    const est_yaw_helper * const data)
{
  // d=f*b/z

  /* ~CodeReview ~ID:624b5fb462c0114cee616c51ed13524c ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible division by zero: check if P3.data[2] != 0 */
  return (data->data->stereo_camera.f*data->data->stereo_camera.b)/P3.data[2];
}
#endif

/* ~CodeReview ~ID:7b9a9e7c09ac13f8f1fd3d650dbbad9a ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove or document the following comments */
/// Non-robust objective function for yaw constraint
//static void
//yaw_objfun(
//    const viscr_vector & phi,
//    viscr_vector & f,
//    viscr_float scale,
//    void * sampleData,
//    void * ud)
//{
// const viscr_SMPC_yaw_corr * corr=(const viscr_SMPC_yaw_corr *)sampleData;
//  est_yaw_helper * data=(est_yaw_helper*)ud;
//
//  // For both old and new point, reconstruct it, transform to other time
//  // coordinate system and predict the disparity there. Compute the difference
//  // to the measured disparity. All this is done in 2d (seen from above) as we
//  // know the influence of a yaw angle on the angle of the epipolar line is
//  // small.
//  
//  // The t indices are those that are supposed to be transformed and then
//  // compared to the d indices.
//
//  // Compute corrected disparities
//
//  viscr_float phi0=phi.data[0];
//  viscr_float cd_new=corr->pt_new.d;
//  viscr_float cd_old=corr->pt_old.d;
//
//  // Compute corrected point in current image
//  unproject( data->pt0, corr->pt_new, cd_new, data);
//
//  // Transform to other image
//  viscr_mat_mult_vec( data->pt1.v, corr->H_cam_old_new.m, data->pt0.v);
//  viscr_float t_new=project( data->pt1, data);
//
//  // Compare with corrected point in old image
//  f.data[0]+= scale*(t_new-cd_old-phi0);
// 
//
//  // Compute corrected point in old image
//  unproject( data->pt0, corr->pt_old, cd_old, data);
//
//  // Transform to other image
//  viscr_mat_mult_vec( data->pt1.v, corr->H_cam_new_old.m, data->pt0.v);
//  viscr_float t_old=project( data->pt1, data);
//
//  // Compare with corrected point in new image
//  f.data[1]+= scale*(cd_new-(t_old+phi0));
//}


///// Objective function interface that calls computes the derivatives point by
///// point.
//static void
//yaw_derivatives(
//    viscr_vector & phi,
//    viscr_matrix & JtJ, 
//    viscr_vector & Jte, 
//    viscr_float & Fx,
//    void * ud)
//{
//  est_yaw_helper * data=(est_yaw_helper*)ud;
//
//  // Go through the yaw points 
//  viscr_uint iPt=0;
//  for( viscr_uint iBin=0; iBin<data->data->param.bins_d; ++iBin)
//    for( viscr_uint iPtInBin=0; iPtInBin<data->data->param.points_per_yaw_bin; ++iPtInBin)
//    {
//      viscr_levmar_num_der_mEst( 
//            yaw_objfun, 
//            viscr_SMPC_ramp_mEstimator, 
//            1e-4f, 
//            phi, 
//            JtJ, 
//            Jte, 
//            Fx, 
//            data->delta.v,
//            data->smallJ.m,
//            data->row.v, 
//            (void*)(&data->data->binned_yaw_points[iPt]), 
//            ud, 
//            &data->mEstData);
//      ++iPt;
//    }
//}
//
//
///** Prepare and perform the yaw angle optimisation. 
// * Algo:
// * - For each disparity bin, compute the median of the measured disparity and
// *   the median of the transformed disparity.
// * - Keep the indices of the respective entries for both flow directions
// *   (old-new and new-old)
// * - Objective function:
// *   - compensate the disparities by phi and minimise the disparity difference
// *     to the other end of the flow vector
//*/
//static bool
//yaw_calibration_lm( 
//    viscr_SMPC_data & data, 
//    viscr_float & b)
//{
//  viscr_mat11 JtJ;
//  viscr_mat11 L;
//  viscr_vec1 Jte;
//  viscr_vec1 phi;
//  viscr_vec1 phi_old;
//  viscr_vec1 Jte_old;
//  viscr_vec1 delta;
//  phi.data[0]=0.0f;
//
//  est_yaw_helper est_yaw_data;
//  est_yaw_data.data=&data;
//
//  // Deactivate m-estimator
//  est_yaw_data.mEstData.f=1.0f;
//  est_yaw_data.mEstData.rampMin=data.param.rampme_yaw.rampMin;
//  est_yaw_data.mEstData.rampMax=data.param.rampme_yaw.rampMax;
//  est_yaw_data.mEstData.lowWeight=data.param.rampme_yaw.lowWeight;
//
//  est_yaw_data.pt0.data[3]=1.0f;
//  est_yaw_data.pt1.data[3]=1.0f;
//
//  viscr_levmar_param opt_param;
//  opt_param.max_iter=20;
//
//  viscr_levmar( 
//        phi.v, 
//        opt_param, 
//        yaw_derivatives, 
//        &est_yaw_data, 
//        JtJ.m, 
//        Jte.v, 
//        L.m,
//        phi_old.v,
//        Jte_old.v,
//        delta.v);
//
//  // Phi is in pixel, convert to rad
//  b=data.current_angles[1]+atan(phi.data[0]/data.stereo_camera.f);
//}

///** Very simple calibration by mean error estimation.  */
/* ~CodeReview ~ID:11521760c0f94d792046e77d95e46bb2 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
static bool
yaw_calibration_mean( 
                     const viscr_SMPC_data & data, 
                     viscr_float & b,
                     viscr_float & currentYawError)
{
  viscr_float sum_d=0.0F;
  for( viscr_uint iBin=0U; iBin<data.param.bins_d; ++iBin)/*loop over all the bins*/
  {
    /* ~CodeReview ~ID:2685894fe0ad2458532b2f55b8923673 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use of assert function for error management: unknown behavior in case of \$r\$r\$nerrors  */
    assert( data.bin_cnt_yaw[iBin]==data.param.points_per_yaw_bin);
    for( viscr_uint iPtInBin=0U; iPtInBin<data.param.points_per_yaw_bin; ++iPtInBin)
    {
      viscr_uint iPt=(iBin*data.param.points_per_yaw_bin)+iPtInBin;
      const viscr_SMPC_yaw_corr & corr=data.binned_yaw_points[iPt];

      sum_d += corr.deltaD;
    }
  }

  // Phi is in pixel, convert to rad
  /* ~CodeReview ~ID:45670a3d991a002180277185bd956865 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:2 ~Comment:Possible division by zero */
  /* ~CodeReview ~ID:45670a3d991a002180277185bd956865 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Split up complicated statement into multiple more comprehensible ones */
  currentYawError = -atanf(sum_d/(2.0F*data.param.bins_d*data.param.points_per_yaw_bin*data.stereo_camera.f));
  b=data.current_angles[1] + currentYawError;
  return true;
}

#endif

/* ~CodeReview ~ID:7ecbbb11769b5b3764712069b3dd5ba1 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove or document possible useless code */
///** Very simple calibration by mean error estimation.  */
//static bool
//yaw_calibration_mean(
//    viscr_SMPC_data & data,
//    viscr_float & b)
//{
//  viscr_float sum_d=0.0f;
//
//  viscr_vec4 pt0, pt1;
//  pt0.data[3]=1.0f;
//  pt1.data[3]=1.0f;
//
//  for( viscr_uint iBin=0; iBin<data.param.bins_d; ++iBin)
//  {
//    assert( data.bin_cnt_yaw[iBin]==data.param.points_per_yaw_bin);
//    for( viscr_uint iPtInBin=0; iPtInBin<data.param.points_per_yaw_bin; ++iPtInBin)
//    {
//      viscr_uint iPt=iBin*data.param.points_per_yaw_bin+iPtInBin;
//      const viscr_SMPC_yaw_corr & corr=data.binned_yaw_points[iPt];
//
//      viscr_float cd_new=corr.pt_new.d;
//      viscr_float cd_old=corr.pt_old.d;
//
//      // Compute corrected point in current image
//      reconstruct( pt0, corr.pt_new.u, corr.pt_new.v, cd_new,data.stereo_camera);
//
//      // Transform to other image
//      viscr_mat_mult_vec( pt1.v, corr.H_cam_old_new.m, pt0.v);
//      viscr_float t_new=(data.stereo_camera.f*data.stereo_camera.b)/pt1.data[2];
//
//      // Compare with corrected point in old image
//      sum_d+= (t_new-cd_old);
//
//      // Compute corrected point in old image
//      reconstruct( pt0, corr.pt_old.u, corr.pt_old.v, cd_old, data.stereo_camera);
//
//      // Transform to other image
//      viscr_mat_mult_vec( pt1.v, corr.H_cam_new_old.m, pt0.v);
//      viscr_float t_old=(data.stereo_camera.f*data.stereo_camera.b)/pt1.data[2];
//
//      // Compare with corrected point in new image
//      sum_d += (cd_new-t_old);
//
//     #if (VISCR_SMPC_DEEPTRACE_YAW!=0)
//        if (deep_tracer == 0)
//        {
//          viscr_deeptrace_init("VISCR_deeptrace");
//          deep_tracer++;
//        }
//        else
//        {
//          viscr_deeptrace_point("disparity_difference",0,2, (double)(t_new-cd_old),(double)(cd_new-t_old) );
//        }
//     #endif
//
//    }
// 
//  }
//  #if (VISCR_SMPC_DEEPTRACE_YAW!=0)
//  if ( deep_tracer >= 1)
//  {
//     viscr_deeptrace_event( "disparity_difference_done", 0);
//     deep_tracer++;
//     if (deep_tracer == 2)
//     viscr_deeptrace_close();  
//  }
//
//  #endif
//  // Phi is in pixel, convert to rad
//  b=data.current_angles[1]+atan(sum_d/(2*data.param.bins_d*data.param.points_per_yaw_bin*data.stereo_camera.f));
//  return true;
//}



/* ~CodeReview ~ID:1ec8a60cb07bf47cd081c599ba0cfdba ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0
/** Calibration by grid search.  */
static bool
yaw_calibration( 
    viscr_SMPC_data & data, 
    viscr_float & b)
{
  viscr_vec2 delta;
  viscr_vec1 phi;

  est_yaw_helper est_yaw_data;
  est_yaw_data.data=&data;
  est_yaw_data.pt0.data[3]=1.0F;
  est_yaw_data.pt1.data[3]=1.0F;

  viscr_float best_phi=0.0F;
  viscr_float best_e=FLT_MAX;

  for( phi.data[0]=-3.0F; phi.data[0]<=3.0F; phi.data[0]+=0.1F)
  {
    viscr_float e=0.0F;

    for( viscr_uint iBin=0; iBin<data.param.bins_d; ++iBin)
    {
      assert( data.bin_cnt_yaw[iBin]==data.param.points_per_yaw_bin);
      for( viscr_uint iPtInBin=0; iPtInBin<data.param.points_per_yaw_bin; ++iPtInBin)
      {
        viscr_uint iPt=iBin*data.param.points_per_yaw_bin+iPtInBin;
        viscr_vec_zero( delta.generic);
        yaw_objfun(
            phi.generic,
            delta.generic,
            1.0F,
            (void*)(&data.binned_yaw_points[iPt]), 
            (void*)(&est_yaw_data));
        e+=delta.data[0]*delta.data[0]+delta.data[1]*delta.data[1];
      }
    }

    e/=(data.param.points_per_yaw_bin*data.param.bins_d);

    if( e<best_e)
    {
      best_e=e;
      best_phi=phi.data[0];
    }
  }

  // Phi is in pixel, convert to rad
  b=data.current_angles.ang[1]+atan(best_phi/data.stereo_camera.f);
  return true;
}
#endif


void
viscr_SMPC_process_fine_epi_only(
    viscr_SMPC_data & data, 
    const viscr_image & k0,
    const viscr_image & k1,
    const DisparityImage_t * disparity,
    const viscr_powerflow_result & flow,
    const FlowImage_t * pFlowImageTemporal)
{
  // we have room in the epipolar bins, we put more points there
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Check if buffers are not full. */
  if( viscr_SMPC_epipolar_bins_are_full( data) == viscr_false)
    {fill_bins_epipolar( data, k0, k1, disparity, flow, pFlowImageTemporal);}
}

/* ~CodeReview ~ID:f0b41c330e126f9cc9d5da412be6d281 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
void
viscr_SMPC_process_fine_all(
    viscr_SMPC_data & data, 
    const DisparityImage_t * disparity_old,
    const DisparityImage_t * disparity_new,
    const viscr_powerflow_result & flow,
    const viscr_mat44 & H_car_new_old,
    const viscr_image & new_k0,
    const viscr_image & new_k1,
    const viscr_image & old_k0,
    const viscr_image & old_k1,
    const FlowImage_t * pFlowImageTemporal
    )
{
  // If we have room in the yaw bins, we place points in the epipolar bins and
  // in the yaw bins as well.
  if( viscr_SMPC_yaw_bins_are_full( data) == viscr_false){
    fill_bins_yaw( 
        data, 
        disparity_old, disparity_new, flow, 
        H_car_new_old,
        new_k0, new_k1,
        old_k0, old_k1,
        pFlowImageTemporal);
  }
}
#endif

/* ~CodeReview ~ID:c70e0fd818c892a0a6dc7e6a39bf3783 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/* The computation of the partial
 * derivatives has two parts: The epipolar constraint like in the coarse mode
 * and the yaw angle/speed constraint. Since the yaw angle/speed constraint
 * depends on one parameter only, we compute its Jacobian in a separate matrix
 * and manually add them to the epipolar constraints.
 */
void
viscr_SMPC_process_fine(
    viscr_SMPC_data & data,
    const viscr_timestamp & now)
{
  if( (viscr_SMPC_epipolar_bins_are_full( data) == viscr_true)
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0)   
    && (viscr_SMPC_yaw_bins_are_full(data) == viscr_true)
#endif
	)
  {
    // Compute the objective function.
    viscr_float a=0.0F;
    viscr_float b;//=0.0F;

#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==1) 
    viscr_float current_angles[3];
    viscr_RotationMatrix2XYZFixedAngles(current_angles[0],current_angles[1],current_angles[2],data.calib_k1.m2c_r); 
    b = current_angles[1];
#endif
    viscr_float c=0.0F;
    //viscr_bool fail=viscr_true;
    viscr_float rmse_epipolar = 0.0F;
    viscr_float rmse_improvement = 0.0F;
    viscr_SMPC_epipolar_calibration( data, a, c,rmse_epipolar, rmse_improvement);


#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0)   
      if( yaw_calibration_mean( data, b))
#endif
      {
        // calibration ok, use the results
        viscr_SMPC_set_rotation( data, a, b, c,rmse_epipolar,rmse_improvement, now);
        viscr_SMPC_calib_available( data);
//        fail=viscr_false;
      }
    //if( fail)
    //  viscr_SMPC_calib_taken( data);
  }

}
#endif

/* ~CodeReview ~ID:abc530ec2330bb7dfeb1a820bfdec444 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_REMOVE_YAW_IN_FINE always different from 0? */
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
void viscr_SMPC_process_fine_pitch_yaw_roll(
    viscr_SMPC_data & data,
    const viscr_timestamp & now,
    const SACCallBackHdlr_t & callBackHandler)
{
  if( (viscr_SMPC_epipolar_bins_are_full( data) == viscr_true)
    && (viscr_SMPC_yaw_bins_are_full(data) == viscr_true)
    )
  {
    //Epipolar calibration - main optimization call
    viscr_float a=0.0F;
    viscr_float b=0.0F;
    viscr_float c=0.0F;
    viscr_bool fail=viscr_true;
    viscr_float rmse_epipolar = 0.0F;
    viscr_float rmse_improvement = 0.0F;
    viscr_SMPC_epipolar_calibration( data, a, c,rmse_epipolar,rmse_improvement, 
      callBackHandler);  

    //Odometer YAW Angle calibration
    if(callBackHandler.pfct_AlgoServiceAddEvent) {
      callBackHandler.pfct_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_SAC, 
        RTA_ID_SAC_YAC, 0xFE);
    }
    if(yaw_calibration_mean( data, b, data.currentYawError))
    {
      // calibration ok, use the results
      viscr_SMPC_set_rotation( data, a, b, c,rmse_epipolar,rmse_improvement, now);
      viscr_SMPC_calib_available( data);
      fail=viscr_false;
    }
    if(callBackHandler.pfct_AlgoServiceAddEvent) {
      callBackHandler.pfct_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_SAC, 
        RTA_ID_SAC_YAC, 0xFE);
    }

    if( fail == viscr_true) {
      viscr_SMPC_calib_taken(data);
    }
  }
}
#endif

/* ~CodeReview ~ID:73585df33f0a3fefb8f4d8b4421cd5d0 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Dead code: is VISCR_SMPC_APPLYRADAR_YAW always different from 0? */
#if ((VISCR_SMPC_STEREO_YAW_CALIBRATION_NONE == 1) || (VISCR_SMPC_STEREO_YAW_CALIBRATION_ODOMETER == 1) || (VISCR_SMPC_STEREO_YAW_CALIBRATION_IMAGE ==1))//(VISCR_SMPC_APPLYRADAR_YAW == 0)

void viscr_SMPC_process_fine_pitch_roll(
    viscr_SMPC_data & data,
    const viscr_timestamp & now, 
    const SACCallBackHdlr_t & callBackHandler)
{
  //data.param.points_per_epipolar_bin = POINTS_PER_EPIPOLAR_BIN_FINE;
  if( viscr_SMPC_epipolar_bins_are_full( data) == viscr_true )
  {
    // Compute the objective function.
    /* ~CodeReview ~ID:2d0dedb53fb93bc4d18265cc46ef8709 ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use more explicit variables names than a, b, c */
    viscr_float a=0.0F;
    viscr_float b;//=0.0F;
    viscr_float current_angles[3];
    viscr_RotationMatrix2XYZFixedAngles(current_angles[0],current_angles[1],current_angles[2],data.calib_k1.m2c_r); 
    b = current_angles[1];
    viscr_float c=0.0F;
    //viscr_bool fail=viscr_true;
    viscr_float rmse_epipolar = 0.0F;
    viscr_float rmse_improvement = 0.0F;
    viscr_SMPC_epipolar_calibration(data, a, c, rmse_epipolar, rmse_improvement, 
      callBackHandler);
    // calibration ok, use the results
    viscr_SMPC_set_rotation( data, a, b, c,rmse_epipolar,rmse_improvement, now);
    viscr_SMPC_calib_available( data );

    //viscr_SMPC_calib_taken( data);
  }
}
#endif
void viscr_SMPC_process_fine_pitch_roll_radaryaw(
                                        viscr_SMPC_data & data,
                                        const viscr_timestamp & now,
                                        const f32_t yaw,
                                        const SACCallBackHdlr_t & callBackHandler)
{
  //data.param.points_per_epipolar_bin = POINTS_PER_EPIPOLAR_BIN_FINE;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Check if all buffer are filled for processing. */
  if( viscr_SMPC_epipolar_bins_are_full( data) == viscr_true )
  {
    // Compute the objective function.
    /* ~CodeReview ~ID:4d40b74f2184ae0df3ff5ef9953bf10c ~Reviewer:CW01\uidv0048 ~Date:6/29/2012 ~Priority:3 ~Comment:Use more explicit variable names than a, b and c */
    viscr_float a=0.0F;
    viscr_float b;//=0.0F;
    viscr_float current_angles[3];
    viscr_RotationMatrix2XYZFixedAngles(current_angles[0],current_angles[1],current_angles[2],data.calib_k1.m2c_r); 
    b = yaw;
    viscr_float c=0.0F;
    //viscr_bool fail=viscr_true;
    viscr_float rmse_epipolar = 0.0F;
    viscr_float rmse_improvement = 0.0F;
    viscr_SMPC_epipolar_calibration( data, a, c,rmse_epipolar,rmse_improvement,
      callBackHandler);
    // calibration ok, use the results
    viscr_SMPC_set_rotation( data, a, b, c,rmse_epipolar,rmse_improvement, now);
    viscr_SMPC_calib_available( data );

    //viscr_SMPC_calib_taken( data);
  }
}
