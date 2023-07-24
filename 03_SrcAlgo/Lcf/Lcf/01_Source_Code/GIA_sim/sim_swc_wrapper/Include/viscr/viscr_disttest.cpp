/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Distance Test

  MODULNAME:      viscr_disttest.cpp  

  DESCRIPTION:    viscr_disttest

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_disttest.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:25CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:07CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.20 2014/02/06 13:44:57CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adaption to changed stereo image map sizes
  CHANGES:        - Added comments -  uidw0251 [Feb 6, 2014 1:44:58 PM CET]
  CHANGES:        Change Package : 216853:1 http://mks-psad:7002/im/viewissue?selection=216853
  CHANGES:        Revision 1.19 2013/08/01 11:39:26CEST Mueller, Reik (muellerr5) 
  CHANGES:        - introduced disparity image type from CCT
  CHANGES:        --- Added comments ---  muellerr5 [Aug 1, 2013 11:39:26 AM CEST]
  CHANGES:        Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.18 2013/07/09 13:31:26CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - replacing SacFlowImage by Rte's FlowImage_t inside the sac kernel
  CHANGES:          (this makes flow warpping obsolete)
  CHANGES:        --- Added comments ---  uidw0251 [Jul 9, 2013 1:31:26 PM CEST]
  CHANGES:        Change Package : 184641:1 http://mks-psad:7002/im/viewissue?selection=184641
  CHANGES:        Revision 1.17 2012/11/08 09:58:13CET Garcia, Lucien (uid26778) 
  CHANGES:        wrong offset managment on right left powerflow
  CHANGES:        --- Added comments ---  uid26778 [Nov 8, 2012 9:58:15 AM CET]
  CHANGES:        Change Package : 165790:1 http://mks-psad:7002/im/viewissue?selection=165790
  CHANGES:        Revision 1.16 2012/09/04 11:00:06CEST Cui, Baomin (cuib) 
  CHANGES:        - merged coverage tags and misra comments from branch to trunk
  CHANGES:        --- Added comments ---  cuib [Sep 4, 2012 11:00:09 AM CEST]
  CHANGES:        Change Package : 146867:11 http://mks-psad:7002/im/viewissue?selection=146867
  CHANGES:        Revision 1.15 2012/08/21 16:38:11CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from delta code review (from 4.6 to 4.7 release)
  CHANGES:        --- Added comments ---  uidv0048 [Aug 21, 2012 4:38:13 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.14 2012/08/21 13:58:10CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> First disparity refinement implementation
  CHANGES:        --- Added comments ---  uidt2765 [Aug 21, 2012 1:58:12 PM CEST]
  CHANGES:        Change Package : 156068:1 http://mks-psad:7002/im/viewissue?selection=156068
  CHANGES:        Revision 1.13 2012/07/20 11:04:23CEST Garcia, Lucien (uid26778) 
  CHANGES:        Improve distance test accuracy at 10m (new requirement) by making several calibrations instead of one.
  CHANGES:        --- Added comments ---  uid26778 [Jul 20, 2012 11:04:23 AM CEST]
  CHANGES:        Change Package : 142649:1 http://mks-psad:7002/im/viewissue?selection=142649
  CHANGES:        Revision 1.12 2012/07/14 10:19:01CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage for dev 4.6.0
  CHANGES:        --- Added comments ---  uidv2823 [Jul 14, 2012 10:19:01 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/07/13 10:42:14CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 10:42:15 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.10 2012/07/04 15:25:53CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always true/false cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 3:25:53 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.9 2012/06/26 14:09:17CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        --- Added comments ---  uid28828 [Jun 26, 2012 2:09:18 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.8 2012/05/31 11:47:12CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 11:47:13 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.7 2012/05/24 09:54:36CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add distance test debug data to sac output
  CHANGES:        --- Added comments ---  uid26778 [May 24, 2012 9:54:36 AM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.6 2012/04/27 16:41:58CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add low pass filter for yaw computation
  CHANGES:        --- Added comments ---  uid26778 [Apr 27, 2012 4:41:58 PM CEST]
  CHANGES:        Change Package : 106059:1 http://mks-psad:7002/im/viewissue?selection=106059
  CHANGES:        Revision 1.5 2012/04/19 15:19:01CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:01 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.4 2012/04/06 16:36:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Test and implement 3D box for distance test
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 4:36:09 PM CEST]
  CHANGES:        Change Package : 106059:1 http://mks-psad:7002/im/viewissue?selection=106059
  CHANGES:        Revision 1.3 2012/03/30 13:37:00CEST Garcia, Lucien (uid26778) 
  CHANGES:        code correction
  CHANGES:        --- Added comments ---  uid26778 [Mar 30, 2012 1:37:00 PM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/03/29 17:13:23CEST Garcia, Lucien (uid26778) 
  CHANGES:        Update distance test function
  CHANGES:        --- Added comments ---  uid26778 [Mar 29, 2012 5:13:23 PM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.1 2012/03/29 11:30:32CEST Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#include <viscr_disttest.hpp>
#include <viscr_rotation.hpp>
#include <viscr_transformation.hpp>
#include <viscr_klt_shift.hpp>

#include "sac_image_access.h"

#include "cct_flow_element.h"
#include "cct_disparity_element.h"

#if (VISCR_DISTTEST_DEBUG == 1)
#include <stdio.h>
static void viscr_disttest_run_debug(const viscr_disttest_input * const p_disttest_input, viscr_disttest_output * const p_disttest_output)
{
  viscr_int8 numstr[256];
  sprintf(numstr,"Z:/OUT/viscr_distest_disparity.pgm");
	FILE * fo=fopen( numstr, "w");
	if( fo)
	{
    fprintf( fo, "P2\n%d %d\n255\n", p_disttest_input->image_disp.size.u , p_disttest_input->image_disp.size.v);
		const viscr_uint n=(p_disttest_input->image_disp.size.u * p_disttest_input->image_disp.size.v);
		for( viscr_uint i=0; i<n; ++i)
    {
      fprintf( fo, "%d ", p_disttest_input->image_disp.data[i]);
    }
		fclose( fo);
  }
}
#endif

/* **************************************************************************** 
Functionname : viscr_disttest_run_reset_output()                          */ /*!  
Description  : 
@param		     p_disttest_output
@return        
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_disttest_run_reset_output(viscr_disttest_output * const p_disttest_output)
{
  /***********************************************************************/
  /* Reset the outputs                                                   */
  /***********************************************************************/
  p_disttest_output->disparity_min = 0U;
  p_disttest_output->disparity_max = 0U;
  p_disttest_output->disparity_density = 0.0F;
  p_disttest_output->disparity_mean = 0.0F;
  p_disttest_output->disparity_std = 0.0F;
  p_disttest_output->T_5_1_mean.data[0] = 0.0F;
  p_disttest_output->T_5_1_mean.data[1] = 0.0F;
  p_disttest_output->T_5_1_mean.data[2] = 0.0F;
  p_disttest_output->T_5_1_norm = 0.0F;
  p_disttest_output->T_5_1_z_std = 0.0F;
  p_disttest_output->T_5_1_z_min = 0.0F;
  p_disttest_output->T_5_1_z_max = 0.0F;
  p_disttest_output->RA_6_5_y = 0.0F;
  viscr_mat_identity(p_disttest_output->R_4_3.m);
  p_disttest_output->Errors = C_DISTTEST_Errors::DISTTEST_NO_ERROR;
/* ~CodeReview ~ID:5ae41cb8c41fd0b0e4b6048e06cd31ce ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:"TopLeft_image_disp, BottomRight_image_disp, T_5_1_z_input" not reseted */

}

/* **************************************************************************** 
Functionname : viscr_disttest_run_reset_output()                          */ /*!  
Description  : 
@param		     p_disttest_output
@return        
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_disttest_run_calc_disparity_box(const viscr_disttest_input *  const p_disttest_input,viscr_disttest_output * const p_disttest_output)
{
  //disparity image access
  SAC::ImageAccess diAccess(p_disttest_input->pDispImage->sImgHeader);
  
  switch (p_disttest_input->CoordinateSystem)
  {
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Switch case control. */
  case C_DISTTEST_Coordinate::DISTTEST_CoordinateSystem_Vehicle:
    {
    // Use this interface : viscr_transformation_compose
    // Not coded
    viscr_mat33 R_2_5;
    viscr_mat33 R_3_5;
    viscr_mat44 H_2_5;
    viscr_mat44 H_5_2;

    // R_2_5 = R_2_3 * R_3_5
    viscr_mat_transpose_copy(R_3_5.m,p_disttest_input->R_5_3.m);

    viscr_mat_mult_mat(R_2_5.m,p_disttest_input->R_2_3.m,R_3_5.m);
    viscr_transformation_compose(H_2_5,R_2_5,p_disttest_input->T_2_3); //T_2_3 = T_2_5
    viscr_transformation_invert(H_5_2,H_2_5);
    viscr_mat42 P_2;
    P_2.m(0U,0U) = -p_disttest_input->TopLeft[0]; // conversion from Autosar to image coordinate system
    P_2.m(1U,0U) = -p_disttest_input->TopLeft[1]; // conversion from Autosar to image coordinate system
    P_2.m(2U,0U) = p_disttest_input->TargetDistanceNorm + p_disttest_input->T_2_3.data[2];  // It is just an estimation but it is enough to select the image box
    P_2.m(3U,0U) = 1.0F;
    P_2.m(0U,1U) = -p_disttest_input->BottomRight[0]; // conversion from Autosar to image coordinate system
    P_2.m(1U,1U) = -p_disttest_input->BottomRight[1]; // conversion from Autosar to image coordinate system
    P_2.m(2U,1U) = p_disttest_input->TargetDistanceNorm + p_disttest_input->T_2_3.data[2];  // It is just an estimation but it is enough to select the image box
    P_2.m(3U,1U) = 1.0F;
    viscr_mat42 P_5;
    viscr_mat_mult_mat(P_5.m,H_5_2.m,P_2.m);

    /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
    p_disttest_output->TopLeft_image_disp[0] = diAccess.HIGH2LOW_U(((p_disttest_input->f*P_5.m(0U,0U))/P_5.m(2U,0U))+p_disttest_input->u0);
    /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
    p_disttest_output->TopLeft_image_disp[1] = diAccess.HIGH2LOW_V(((p_disttest_input->f*P_5.m(1U,0U))/P_5.m(2U,0U))+p_disttest_input->v0);
    /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
    p_disttest_output->BottomRight_image_disp[0] = diAccess.HIGH2LOW_U(((p_disttest_input->f*P_5.m(0U,1U))/P_5.m(2U,1U))+p_disttest_input->u0);
    /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
    p_disttest_output->BottomRight_image_disp[1] = diAccess.HIGH2LOW_V(((p_disttest_input->f*P_5.m(1U,1U))/P_5.m(2U,1U))+p_disttest_input->v0);

    }
    break;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Switch case control. */
  case C_DISTTEST_Coordinate::DISTTEST_CoordinateSystem_Camera_rectified_image:
    {
      /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
      p_disttest_output->TopLeft_image_disp[0] = diAccess.HIGH2LOW_U(p_disttest_input->TopLeft[0]);
      /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
      p_disttest_output->TopLeft_image_disp[1] = diAccess.HIGH2LOW_V(p_disttest_input->TopLeft[1]);
      /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
      p_disttest_output->BottomRight_image_disp[0] = diAccess.HIGH2LOW_U(p_disttest_input->BottomRight[0]);
      /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Yannick Mescam date: 19.04.2012 reason: cannot modify macro function */
      p_disttest_output->BottomRight_image_disp[1] = diAccess.HIGH2LOW_V(p_disttest_input->BottomRight[1]);
    }
    break;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Switch case control. */
  case C_DISTTEST_Coordinate::DISTTEST_CoordinateSystem_Camera_disparity_image:
    {
      p_disttest_output->TopLeft_image_disp[0] = static_cast<viscr_coord>(p_disttest_input->TopLeft[0]);
      p_disttest_output->TopLeft_image_disp[1] = static_cast<viscr_coord>(p_disttest_input->TopLeft[1]);
      p_disttest_output->BottomRight_image_disp[0] = static_cast<viscr_coord>(p_disttest_input->BottomRight[0]);
      p_disttest_output->BottomRight_image_disp[1] = static_cast<viscr_coord>(p_disttest_input->BottomRight[1]);
    }
    break;


  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Switch case control. Default case. */
  default:
    {
      p_disttest_output->Errors = C_DISTTEST_Errors::DISTTEST_ERROR;
    }
    break;
  }
}

/* **************************************************************************** 
Functionname : viscr_disttest_run()                                     */ /*!  
Description  : 
@param		     p_disttest_input
@return        p_disttest_output
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_disttest_run(
    const viscr_disttest_input *  const p_disttest_input,
    viscr_disttest_output * const p_disttest_output)
{
  viscr_bool bKltShift;
  viscr_uint index = 0U;
  viscr_uint index_powerflow = 0U;
  viscr_coord u_powerflow = 0;
  viscr_coord v_powerflow = 0;
  viscr_uint image_disp_valid = 0U;
  viscr_pixel image_disp_value = 0U;
  viscr_coord image_disp_value_tmp = 0;
  viscr_uint image_disp_value_sum = 0U;
  viscr_pixel image_disp_min = 0xFFFFU;
  viscr_pixel image_disp_max = 0U;
  viscr_coord temp_coord_for_misra;
  viscr_float image_disp_std = 0.0F;
  viscr_float temp_float_for_misra;
  viscr_float temp_float_for_misra2;
  viscr_float su_fp;
  viscr_float sv_fp;

  /***********************************************************************/
  /* Reset dist test outputs                                             */
  /***********************************************************************/
  viscr_disttest_run_reset_output(p_disttest_output);
  

  /***********************************************************************/
  /* Calculate disparity box                                             */
  /***********************************************************************/
  viscr_disttest_run_calc_disparity_box(p_disttest_input,p_disttest_output);
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if no error is present. */
  
  //disparity image access
  SAC::ImageAccess diAccess(p_disttest_input->pDispImage->sImgHeader);

  if (p_disttest_output->Errors ==  C_DISTTEST_Errors::DISTTEST_NO_ERROR)
  {
    
    /***********************************************************************/
    /* Find minimum, maximum, mean, density of the cropped disparity image */
    /***********************************************************************/
    for (viscr_coord v = p_disttest_output->TopLeft_image_disp[1]; v < p_disttest_output->BottomRight_image_disp[1]; v += 1)
    {
      for (viscr_coord u = p_disttest_output->TopLeft_image_disp[0]; u < p_disttest_output->BottomRight_image_disp[0]; u += 1)
      {
        /* <ln_offset:1 PCLINT Error 571: reviewer name: Yannick Mescam date: 19.04.2012 reason: Suspicious cast */
        index = static_cast<viscr_uint>(u) + (static_cast<viscr_uint>(v)*static_cast<viscr_uint>(p_disttest_input->pDispImage->sImgHeader.uiWidth));
        //u_powerflow = LOW2HIGH_U(u);// - static_cast<viscr_coord>(p_disttest_input->imageDataRightLeftPowerflow.StartX_px);
        ///* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Boris Lugez date: 21.08.2012 reason: cannot modify macro function */
        //u_powerflow = HIGH2LOW_U( static_cast<viscr_float>(u_powerflow) );

        //v_powerflow = LOW2HIGH_V(v);// - static_cast<viscr_coord>(p_disttest_input->imageDataRightLeftPowerflow.StartY_px);
        ///* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Boris Lugez date: 21.08.2012 reason: cannot modify macro function */
        //v_powerflow = HIGH2LOW_V( static_cast<viscr_float>(v_powerflow) );

        u_powerflow = u;
        v_powerflow = v;

        /* <ln_offset:1 PCLINT Error 571: reviewer name: Boris Lugez date: 21.08.2012 reason: Suspicious cast */
        index_powerflow = static_cast<viscr_uint>(u_powerflow) + (static_cast<viscr_uint>(v_powerflow)*static_cast<viscr_uint>(p_disttest_input->pFlowImageSpatial->sImgHeader.uiWidth));
        const cct::CDisparityElement dispElement = p_disttest_input->pDispImage->pDisparityData[index];
        /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
        if ( dispElement.isValid() )
        {

           /* Calculate disparity */ 
	         /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
           //image_disp_value = (p_disttest_input->image_disp.data[index] ^ 1U) >> 1;
           // ~CodeReview ~ID:cea5dd53346e26c102f0475d2a17dcae ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic number 16.0
           //temp_float_for_misra = static_cast<viscr_float>(image_disp_value) / 16.0F;
          temp_float_for_misra2 = ROUND( static_cast<viscr_float>(diAccess.LOW2HIGH_U_FLOAT(dispElement.asFloat())) );
           image_disp_value_tmp = static_cast<viscr_coord>(temp_float_for_misra2);
           const cct::CFlowElement flowElement = p_disttest_input->pFlowImageSpatial->pFlowData[index_powerflow];
         /* <ln_offset:+7to+10 COVERAGE reviewer name: Baomin Cui date: 03.09.2012 reason: Powerflow check. */
         // ~CodeReview ~ID:2ee1814d9107a86c0a3e4f7948ea0438 ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:2 ~Comment:cast signed to unsigned: possible lost of sign!!
         // ~CodeReview ~ID:b827018cf318b4cbbff1c1947f3a336e ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers 0x80
		       /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		       /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		       /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		       /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
           if ( flowElement.isValid()
             && (abs(flowElement.dyInt()) < VISCR_DISTTEST_DV_MAX)
             && (abs(static_cast<viscr_int>(flowElement.dxInt()) - static_cast<viscr_int>(image_disp_value_tmp)) < VISCR_DISTTEST_DU_MAX) )
           {
              /* Apply klt shift to refine the disparity */
              viscr_coord u0;
              viscr_coord v0;
		          /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		          /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
              u0 = diAccess.LOW2HIGH_U(u) - static_cast<viscr_coord>(flowElement.dxInt());
              v0 = diAccess.LOW2HIGH_V(v) - static_cast<viscr_coord>(flowElement.dyInt());
              viscr_coord u1;
              viscr_coord v1;
              u1 = diAccess.LOW2HIGH_U(u);
              v1 = diAccess.LOW2HIGH_V(v);
              bKltShift = viscr_klt_shift_fp(
                        su_fp, 
                        sv_fp, 
                        p_disttest_input->g_image_DistTest_rect_k0, /* right image */
                        u0, /* Initially used with Powerflow coordinates? */
                        v0, 
                        p_disttest_input->g_image_DistTest_rect_k1, /* left image */
                        u1, 
                        v1, 
                        p_disttest_input->g_smpc_DistTest_param.klt_shift_rad,
                        p_disttest_input->g_smpc_DistTest_param.klt_shift_min_grey,
                        p_disttest_input->g_smpc_DistTest_param.klt_shift_max_grey,
                        &p_disttest_output->DistTest_klt_accu[0],
                        viscr_false);
              if ((bKltShift == viscr_true) && (fabsf(su_fp)<VISCR_DISTTEST_KLTSHIFTMAX_SU) && (fabsf(sv_fp)<VISCR_DISTTEST_KLTSHIFTMAX_SV))
              {
                temp_float_for_misra = ( ( static_cast<viscr_float>(u1) - static_cast<viscr_float>(u0) ) + su_fp )*16.0F;
                /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Boris Lugez date: 21.08.2012 reason: cannot modify macro function */
                temp_coord_for_misra = diAccess.HIGH2LOW_U(temp_float_for_misra);
                temp_float_for_misra = ROUND( static_cast<viscr_float>( temp_coord_for_misra ) );
                image_disp_value = static_cast<viscr_pixel>( temp_float_for_misra );

                if (image_disp_value > image_disp_max)
                {
                  image_disp_max = image_disp_value;
                }
                if (image_disp_value < image_disp_min)
                {
                  image_disp_min = image_disp_value;
                }
                image_disp_value_sum += image_disp_value;
                image_disp_valid += 1U;
              }
           }

        }
      }
    }
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if valid values are present. */
    if ((image_disp_valid != 0U) && (p_disttest_input->f > C_F32_DELTA)&& (p_disttest_input->b > C_F32_DELTA))
    {

      /***********************************************************************/
      /* Record minimim of the cropped disparity image                       */
      /***********************************************************************/
      p_disttest_output->disparity_min = image_disp_min;

      /***********************************************************************/
      /* Record maximum of the cropped disparity image                       */
      /***********************************************************************/
      p_disttest_output->disparity_max = image_disp_max;

      /***********************************************************************/
      /* Calculate the density of the cropped disparity image                */
      /***********************************************************************/
      // ~CodeReview ~ID:00d0bda9756f23d710265377501f3034 ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:2 ~Comment:Is the denominator always different from zero?
      p_disttest_output->disparity_density = static_cast<viscr_float>(image_disp_valid) / ((static_cast<viscr_float>(p_disttest_output->BottomRight_image_disp[1])-static_cast<viscr_float>(p_disttest_output->TopLeft_image_disp[1]))*(static_cast<viscr_float>(p_disttest_output->BottomRight_image_disp[0])-static_cast<viscr_float>(p_disttest_output->TopLeft_image_disp[0])));

      /***********************************************************************/
      /* Calculate the mean of the cropped disparity image                   */
      /***********************************************************************/
      p_disttest_output->disparity_mean = static_cast<viscr_float>(image_disp_value_sum) / static_cast<viscr_float>(image_disp_valid);

      /***********************************************************************/
      /* Calculate the standard deviation of the cropped disparity image     */
      /***********************************************************************/
      //disparity image access
      SAC::ImageAccess diAccess(p_disttest_input->pDispImage->sImgHeader);
      //spatial flow image access
      SAC::ImageAccess fisAccess(p_disttest_input->pFlowImageSpatial->sImgHeader);
      for (viscr_coord v = p_disttest_output->TopLeft_image_disp[1]; v < p_disttest_output->BottomRight_image_disp[1]; v += 1)
      {
        for (viscr_coord u = p_disttest_output->TopLeft_image_disp[0]; u < p_disttest_output->BottomRight_image_disp[0]; u += 1)
        {
          /* <ln_offset:1 PCLINT Error 571: reviewer name: Yannick Mescam date: 19.04.2012 reason: Suspicious cast */
          index = static_cast<viscr_uint>(u) + (static_cast<viscr_uint>(v)*static_cast<viscr_uint>(p_disttest_input->pDispImage->sImgHeader.uiWidth));
          //u_powerflow = LOW2HIGH_U(u);// - static_cast<viscr_coord>(p_disttest_input->imageDataRightLeftPowerflow.StartX_px);
          ///* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Boris Lugez date: 21.08.2012 reason: cannot modify macro function */
          //u_powerflow = HIGH2LOW_U( static_cast<viscr_float>(u_powerflow) );

          //v_powerflow = LOW2HIGH_V(v);// - static_cast<viscr_coord>(p_disttest_input->imageDataRightLeftPowerflow.StartY_px);
          ///* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Boris Lugez date: 21.08.2012 reason: cannot modify macro function */
          //v_powerflow = HIGH2LOW_V( static_cast<viscr_float>(v_powerflow) );

          u_powerflow = u;
          v_powerflow = v;

          /* <ln_offset:1 PCLINT Error 571: reviewer name: Boris Lugez date: 21.08.2012 reason: Suspicious cast */
          index_powerflow = static_cast<viscr_uint>(u_powerflow) + (static_cast<viscr_uint>(v_powerflow)*static_cast<viscr_uint>(p_disttest_input->pFlowImageSpatial->sImgHeader.uiWidth));
          const cct::CDisparityElement dispElement = p_disttest_input->pDispImage->pDisparityData[index];
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
          if ( dispElement.isValid() )
          {

             /* Calculate disparity */ 
	           /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
             //image_disp_value = (p_disttest_input->image_disp.data[index] ^ 1U) >> 1;
             // ~CodeReview ~ID:fd04b0bc10bfeb50ef00f82c5e446c99 ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic number 16.0
             //temp_float_for_misra = static_cast<viscr_float>(image_disp_value) / 16.0F;
             temp_float_for_misra2 = ROUND( static_cast<viscr_float>(diAccess.LOW2HIGH_U_FLOAT(dispElement.asFloat())) );
             image_disp_value_tmp = static_cast<viscr_coord>(temp_float_for_misra2);
             const cct::CFlowElement flowElement = p_disttest_input->pFlowImageSpatial->pFlowData[index_powerflow];
           /* <ln_offset:+7to+10 COVERAGE reviewer name: Baomin Cui date: 03.09.2012 reason: Powerflow check. */
           // ~CodeReview ~ID:2ee1814d9107a86c0a3e4f7948ea0438 ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:2 ~Comment:cast signed to unsigned: possible lost of sign!!
           // ~CodeReview ~ID:16a2f498ba8d7cf8b58d07f5706af57b ~Reviewer:CW01\uidv0048 ~Date:8/21/2012 ~Priority:3 ~Comment:Use meaningful define instead of magic number 0x80
		         /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		         /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		         /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		         /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
             if (flowElement.isValid()
               && (abs(flowElement.dyInt()) < VISCR_DISTTEST_DV_MAX)
               && (abs(static_cast<viscr_int>(flowElement.dxInt()) - static_cast<viscr_int>(image_disp_value_tmp)) < VISCR_DISTTEST_DU_MAX) )
             {
                /* Apply klt shift to refine the disparity */
                viscr_coord u0;
                viscr_coord v0;
		            /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
		            /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Boris Lugez date: 21.08.2012 reason: indexing by pointer faster */
                u0 = fisAccess.LOW2HIGH_U(u) - static_cast<viscr_coord>(flowElement.dxInt());
                v0 = fisAccess.LOW2HIGH_V(v) - static_cast<viscr_coord>(flowElement.dyInt());
                viscr_coord u1;
                viscr_coord v1;
                u1 = fisAccess.LOW2HIGH_U(u);
                v1 = fisAccess.LOW2HIGH_V(v);
                bKltShift = viscr_klt_shift_fp(
                          su_fp, 
                          sv_fp, 
                          p_disttest_input->g_image_DistTest_rect_k0, /* right image */
                          u0, /* Initially used with Powerflow coordinates? */
                          v0, 
                          p_disttest_input->g_image_DistTest_rect_k1, /* left image */
                          u1, 
                          v1, 
                          p_disttest_input->g_smpc_DistTest_param.klt_shift_rad,
                          p_disttest_input->g_smpc_DistTest_param.klt_shift_min_grey,
                          p_disttest_input->g_smpc_DistTest_param.klt_shift_max_grey,
                          &p_disttest_output->DistTest_klt_accu[0],
                          viscr_false);

                  if ((bKltShift == viscr_true) && (fabsf(su_fp)<VISCR_DISTTEST_KLTSHIFTMAX_SU) && (fabsf(sv_fp)<VISCR_DISTTEST_KLTSHIFTMAX_SV))
                  {
                    temp_float_for_misra = ( ( static_cast<viscr_float>(u1) - static_cast<viscr_float>(u0) ) + su_fp )*16.0F;
                    /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Boris Lugez date: 21.08.2012 reason: cannot modify macro function */
                    temp_coord_for_misra = fisAccess.HIGH2LOW_U(temp_float_for_misra);
                    temp_float_for_misra = ROUND( static_cast<viscr_float>( temp_coord_for_misra ) );
                    image_disp_value = static_cast<viscr_pixel>( temp_float_for_misra );
                    temp_float_for_misra = static_cast<viscr_float>(image_disp_value)-p_disttest_output->disparity_mean;
                    image_disp_std += fabsf(temp_float_for_misra);
                  }
                }
          }
        }
      }
      p_disttest_output->disparity_std = image_disp_std / static_cast<viscr_float>(image_disp_valid);

      /***********************************************************************/
      /* Calculate the target position                                       */
      /***********************************************************************/
      viscr_float dist_mainpoint[2];
      /* <ln_offset:2 MISRA Rule 5-0-7: reviewer name: Garcia Lucien date: 31.05.2012 reason: cannot modify macro function */
      /* <ln_offset:1 MISRA Rule 5-0-8: reviewer name: Garcia Lucien date: 31.05.2012 reason: cannot modify macro function */
      dist_mainpoint[0] = ((static_cast<viscr_float>(diAccess.LOW2HIGH_U(p_disttest_output->TopLeft_image_disp[0]))+static_cast<viscr_float>(diAccess.LOW2HIGH_U(p_disttest_output->BottomRight_image_disp[0])))/2.0F)-p_disttest_input->u0;
      /* <ln_offset:2 MISRA Rule 5-0-7: reviewer name: Garcia Lucien date: 31.05.2012 reason: cannot modify macro function */
      /* <ln_offset:1 MISRA Rule 5-0-8: reviewer name: Garcia Lucien date: 31.05.2012 reason: cannot modify macro function */
      dist_mainpoint[1] = ((static_cast<viscr_float>(diAccess.LOW2HIGH_V(p_disttest_output->TopLeft_image_disp[1]))+static_cast<viscr_float>(diAccess.LOW2HIGH_V(p_disttest_output->BottomRight_image_disp[1])))/2.0F)-p_disttest_input->v0;

      temp_float_for_misra = static_cast<viscr_float>(p_disttest_output->disparity_mean)/16.0F;
      /* ~CodeReview ~ID:5df1d317d8bff179427cb0039c0c1d2b ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:check for division by zero */
      p_disttest_output->T_5_1_mean.data[2] = (p_disttest_input->b*p_disttest_input->f)/diAccess.LOW2HIGH_D_FLOAT(temp_float_for_misra);
      p_disttest_output->T_5_1_mean.data[0] = (dist_mainpoint[0]*p_disttest_output->T_5_1_mean.data[2])/p_disttest_input->f;
      p_disttest_output->T_5_1_mean.data[1] = (dist_mainpoint[1]*p_disttest_output->T_5_1_mean.data[2])/p_disttest_input->f;
      p_disttest_output->T_5_1_norm = viscr_vec_norm(p_disttest_output->T_5_1_mean.v);
      temp_float_for_misra = static_cast<viscr_float>(p_disttest_output->disparity_mean)/16.0F;
      /* ~CodeReview ~ID:dc262cab1dffd6266bfee8820785cfa7 ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:check for division by zero */
      temp_float_for_misra2 = static_cast<viscr_float>(p_disttest_output->disparity_mean+p_disttest_output->disparity_std)/16.0F;
      /* ~CodeReview ~ID:73d4aacefacc7f604eb2a3abadf69fd9 ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:check for division by zero */
      p_disttest_output->T_5_1_z_std = fabsf((p_disttest_input->b*p_disttest_input->f)/diAccess.LOW2HIGH_D_FLOAT(temp_float_for_misra)) - ((p_disttest_input->b*p_disttest_input->f)/diAccess.LOW2HIGH_D_FLOAT(temp_float_for_misra2));

      temp_float_for_misra = static_cast<viscr_float>(p_disttest_output->disparity_min)/16.0F;
      /* ~CodeReview ~ID:6e70217c7bbbddd4921c8cebb5f2f282 ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:check for division by zero */
      p_disttest_output->T_5_1_z_max = (p_disttest_input->b*p_disttest_input->f)/diAccess.LOW2HIGH_D_FLOAT(temp_float_for_misra);      
      temp_float_for_misra = static_cast<viscr_float>(p_disttest_output->disparity_max)/16.0F;
      /* ~CodeReview ~ID:1390b7df445e4085dff55be39bb56f3a ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:check for division by zero */
      p_disttest_output->T_5_1_z_min = (p_disttest_input->b*p_disttest_input->f)/diAccess.LOW2HIGH_D_FLOAT(temp_float_for_misra);

      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Condition is covered if Disttest_Mode_Calibrate is active. */
      if (p_disttest_input->mode == C_DISTTEST_Mode::DISTTEST_Mode_Calibrate)
      {
        /* ~CodeReview ~ID:d92fb40fa35770f22d40adc9dbd23c13 ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:3 ~Comment:Describe model used and meaning of outputs */

        /* calculate the target depth */   
        viscr_float norm_mainpoint = sqrtf(((dist_mainpoint[0]*dist_mainpoint[0])+(dist_mainpoint[1]*dist_mainpoint[1])));
        viscr_float angle_mainpoint = atanf((norm_mainpoint/p_disttest_input->f));
        p_disttest_output->T_5_1_z_input = p_disttest_input->TargetDistanceNorm * cosf(angle_mainpoint);

        temp_float_for_misra = p_disttest_output->T_5_1_z_std/p_disttest_output->T_5_1_mean.data[2];
        /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if parameters are valid. */
        if (  (fabsf(p_disttest_output->T_5_1_z_input) > C_F32_DELTA) 
              && (fabsf(temp_float_for_misra) <  VISCR_DISTTEST_T_5_1_z_accuracy_min)  /* CHECK DISPARITY STD */
              && (p_disttest_output->disparity_density > VISCR_DISTTEST_DENSITY_MIN)                                                  /* CHECK DISPARITY DENSITY */
              )
        {
          /* calculate the yaw angle delta on rectified images */
          p_disttest_output->RA_6_5_y = atanf(p_disttest_input->b*((1.0F/(p_disttest_output->T_5_1_mean.data[2])) - (1.0F/(p_disttest_output->T_5_1_z_input)) ));
          /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Accuracy of yaw is met. */
          //if (std::fabsf(p_disttest_output->RA_6_5_y) < (2.0F*VISCR_DISTTEST_YAW_ACCURACY)) /* Yaw accuracy */
          //{
          //  p_disttest_output->RA_6_5_y = p_disttest_output->RA_6_5_y/3.0F;
          //}
          
          /* R_4_3 = R_4_6 * R_6_5 * R_5_3 */
          viscr_mat33 R_6_5;
          viscr_mat33 R_6_3;
          viscr_mat33 R_4_6;
          viscr_XYZFixedAngles2RotationMatrix( R_6_5,0.0F,p_disttest_output->RA_6_5_y,0.0F);
          viscr_mat_mult_mat(R_6_3.m,R_6_5.m,p_disttest_input->R_5_3.m);
          viscr_mat_transpose_copy(R_4_6.m,p_disttest_input->R_6_4.m);
          viscr_mat_mult_mat(p_disttest_output->R_4_3.m,R_4_6.m,R_6_3.m);        
        }
        else
        {
          // Input target position is missing or distance accuracy not enought accurate
          p_disttest_output->Errors = C_DISTTEST_Errors::DISTTEST_ERROR;
        }
      }
    }
    else
    {
      // some rectified parameter are missing or the disparity cropped image is invalid
      p_disttest_output->Errors = C_DISTTEST_Errors::DISTTEST_ERROR;
    }

#if (VISCR_DISTTEST_DEBUG == 1)
    viscr_disttest_run_debug(p_disttest_input,p_disttest_output);
#endif

  }

}




