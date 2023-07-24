/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_mono.cpp  

  DESCRIPTION:    viscr_eol_mono

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_mono.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:28CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:12CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.12 2012/07/13 17:14:28CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage for dev 4.6.0
  CHANGES:        - Added comments -  uidv2823 [Jul 13, 2012 5:14:28 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/07/05 09:08:22CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 9:08:22 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.10 2012/06/20 13:29:27CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 20, 2012 1:29:27 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.9 2012/05/31 17:34:21CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:34:22 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.8 2012/05/21 20:04:01CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:04:03 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.7 2012/04/26 10:49:25CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:25 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.6 2012/04/19 15:19:00CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:00 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.5 2012/04/06 16:34:48CEST Garcia, Lucien (uid26778) 
  CHANGES:        EOL calibration could manage target at 4m (from front vehicle axe)
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 4:34:48 PM CEST]
  CHANGES:        Change Package : 106060:1 http://mks-psad:7002/im/viewissue?selection=106060
  CHANGES:        Revision 1.4 2012/03/15 16:45:15CET Garcia, Lucien (uid26778) 
  CHANGES:        Integrate EOL function on SAC branch
  CHANGES:        --- Added comments ---  uid26778 [Mar 15, 2012 4:45:15 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.3 2012/03/06 15:29:05CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra Errors
  CHANGES:        --- Added comments ---  uidt8403 [Mar 6, 2012 3:29:05 PM CET]
  CHANGES:        Change Package : 101150:1 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.2 2012/03/02 13:04:24CET Exner, Christian (uidt8578) 
  CHANGES:        - added debugging connection to SAC::EOL::CStereoCalibrationDebug
  CHANGES:        --- Added comments ---  uidt8578 [Mar 2, 2012 1:04:24 PM CET]
  CHANGES:        Change Package : 101435:2 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.1 2012/01/19 14:20:53CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#include <viscr_eol_mono.hpp>
#include <viscr_eol_filter1.hpp>
#include <viscr_eol_filter2.hpp>
#include <viscr_eol_calib.hpp>
#include <viscr_rotation.hpp>

#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
#include <viscr_eol_calib_debug.hpp>
#endif
#endif
//using namespace std;

/* **************************************************************************** 
Functionname : viscr_eol_mono_ROI()                                     */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_eol_mono_ROI(
                          const viscr_eol_mono_input *  const p_eol_mono_input,  
                          viscr_int &filter_width, 
                          viscr_int &filter_height, 
                          viscr_int &filter_start_width, 
                          viscr_int &filter_start_height)
{
  viscr_vec3  P_1;
  viscr_vec3  P_2;
  viscr_mat41  PH_2;
  viscr_mat41  PH_C;
  viscr_mat44  H_2_C;
  viscr_mat33  R_2_C;
  viscr_mat44  H_C_2;

  P_1.data[0] = p_eol_mono_input->PatDistCircle2Center + (p_eol_mono_input->PatDistCircle2Center/2.0F);
  P_1.data[1] = (p_eol_mono_input->PatOutCircleDiameter/2.0F) + (p_eol_mono_input->PatDistCircle2Center/2.0F);
  P_1.data[2] = 0.0F;
  viscr_vec_add(P_2.v,p_eol_mono_input->T_2_1.v,P_1.v);
  PH_2.data[0] = P_2.data[0];
  PH_2.data[1] = P_2.data[1];
  PH_2.data[2] = P_2.data[2];
  PH_2.data[3] = 1.0F;
  viscr_XYZFixedAngles2RotationMatrix(R_2_C,(p_eol_mono_input->R_2_C_mean.data[0]+p_eol_mono_input->R_2_C_std.data[0]),(p_eol_mono_input->R_2_C_mean.data[1]-p_eol_mono_input->R_2_C_std.data[1]),p_eol_mono_input->R_2_C_mean.data[2]);
  
  for( viscr_uint r=0U; r<3U; ++r)
  {
    H_2_C.m(r,3U) = p_eol_mono_input->T_2_C.data[r];
    for( viscr_uint c=0U; c<3U; ++c)
    {
      H_2_C.m(r,c) = R_2_C.m(r,c);
    }
  }
  for( viscr_uint c=0U; c<3U; ++c)
  {
    H_2_C.m(3U,c) = 0.0F;
  }
  H_2_C.m(3U,3U) = 1.0F;

  viscr_invert_transformation(H_C_2,H_2_C);
  viscr_mat_mult_mat(PH_C.m,H_C_2.m,PH_2.m);
  
  viscr_float u_max; 
  viscr_float v_max; 
  u_max = ((p_eol_mono_input->f * PH_C.data[0]) / PH_C.data[2]) + p_eol_mono_input->u0;
  v_max = ((p_eol_mono_input->f * PH_C.data[1]) / PH_C.data[2]) + p_eol_mono_input->v0;

  P_1.data[0] = - p_eol_mono_input->PatDistCircle2Center - (p_eol_mono_input->PatDistCircle2Center/2.0F);
  P_1.data[1] = - (p_eol_mono_input->PatOutCircleDiameter/2.0F) - (p_eol_mono_input->PatDistCircle2Center/2.0F);
  P_1.data[2] = 0.0F;
  viscr_vec_add(P_2.v,p_eol_mono_input->T_2_1.v,P_1.v);
  PH_2.data[0] = P_2.data[0];
  PH_2.data[1] = P_2.data[1];
  PH_2.data[2] = P_2.data[2];
  PH_2.data[3] = 1.0F;

  viscr_XYZFixedAngles2RotationMatrix(R_2_C,(p_eol_mono_input->R_2_C_mean.data[0]-p_eol_mono_input->R_2_C_std.data[0]),(p_eol_mono_input->R_2_C_mean.data[1]+p_eol_mono_input->R_2_C_std.data[1]),p_eol_mono_input->R_2_C_mean.data[2]);
  
  for( viscr_uint r=0U; r<3U; ++r)
  {
    H_2_C.m(r,3U) = p_eol_mono_input->T_2_C.data[r];
    for( viscr_uint c=0U; c<3U; ++c)
    {
      H_2_C.m(r,c) = R_2_C.m(r,c);
    }
  }
  for( viscr_uint c=0U; c<3U; ++c)
  {
    H_2_C.m(3U,c) = 0.0F;
  }
  H_2_C.m(3U,3U) = 1.0F;

  viscr_invert_transformation(H_C_2,H_2_C);
  viscr_mat_mult_mat(PH_C.m,H_C_2.m,PH_2.m);

  viscr_float u_min; 
  viscr_float v_min; 
  u_min = ((p_eol_mono_input->f * PH_C.data[0]) / PH_C.data[2]) + p_eol_mono_input->u0;
  v_min = ((p_eol_mono_input->f * PH_C.data[1]) / PH_C.data[2]) + p_eol_mono_input->v0;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Check filter size for initialization. */
  if (u_min>static_cast<viscr_float>(filer1_border))
  {
    filter_start_width = static_cast<viscr_int>(u_min);
  }
  else
  {
    filter_start_width = filer1_border;
  }
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Check filter size for initialization . */
  if (v_min>static_cast<viscr_float>(filer1_border))
  {
    filter_start_height = static_cast<viscr_int>(v_min);
  }
  else
  {
    filter_start_height = filer1_border;
  }
  viscr_int tmp;
  tmp = p_eol_mono_input->image.size.u-filer1_border;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Control if filter size is too big. */
  if (u_max>static_cast<viscr_float>(tmp))
  {
    filter_width = (p_eol_mono_input->image.size.u-filer1_border) - filter_start_width;
  }
  else
  {
    filter_width = static_cast<viscr_int>(u_max) - filter_start_width;
  }
  tmp = p_eol_mono_input->image.size.v-filer1_border;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Control if filter size is too big. */
  if (v_max>static_cast<viscr_float>(tmp))
  {
     filter_height = (p_eol_mono_input->image.size.v-filer1_border) - filter_start_height;
  }
  else
  {
    filter_height = static_cast<viscr_int>(v_max) - filter_start_height;
  }
}


/* **************************************************************************** 
Functionname : viscr_eol_mono_init()                                     */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* ~CodeReview ~ID:4dc227ef1b4df179e45a5ab3c03fb2af ~Reviewer:CW01\uidv0048 ~Date:6/20/2012 ~Priority:3 ~Comment:This function is defined but it is empty and not called anywhere. Remove it for readability or modify it.  */
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_mono_init( )
{

}


/* **************************************************************************** 
Functionname : viscr_eol_mono_run()                                      */ /*!  
Description  : 
@param		     p_eol_mono_input
@return        p_eol_mono_output
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_mono_run(
    const viscr_eol_mono_input * const p_eol_mono_input,
    viscr_eol_mono_output * const p_eol_mono_output)
{
  viscr_eol_filter1_input m_eol_filter1_input;
  viscr_eol_filter1_output m_eol_filter1_output;

  viscr_eol_filter2_input m_eol_filter2_input; 
  viscr_eol_filter2_output m_eol_filter2_output;

  viscr_eol_calib_input m_eol_calib_input; 
  viscr_eol_calib_output m_eol_calib_output;

  p_eol_mono_output->Errors = C_EOL_MONO_Errors::EOL_MONO_NO_ERROR;

  m_eol_filter1_input.image.data = p_eol_mono_input->image.data;
  m_eol_filter1_input.image.size.u = p_eol_mono_input->image.size.u;
  m_eol_filter1_input.image.size.v = p_eol_mono_input->image.size.v;

  viscr_eol_mono_ROI( p_eol_mono_input, m_eol_filter1_input.filter_width,m_eol_filter1_input.filter_height,m_eol_filter1_input.filter_start_width,m_eol_filter1_input.filter_start_height);

  m_eol_filter1_input.PatOutCircleDiameter = p_eol_mono_input->PatOutCircleDiameter;
  m_eol_filter1_input.PatInnerCircleDiameter = p_eol_mono_input->PatInnerCircleDiameter;
  m_eol_filter1_input.f = p_eol_mono_input->f;
  m_eol_filter1_input.TargetDist = p_eol_mono_input->T_2_1.data[2] - p_eol_mono_input->T_2_C.data[2];
  viscr_eol_filter1_run(&m_eol_filter1_input,&m_eol_filter1_output);
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: No error check. */
  if (m_eol_filter1_output.Errors == C_EOL_FILTER1_Errors::EOL_FILTER1_NO_ERROR)
  {
    m_eol_filter2_input.image.data = p_eol_mono_input->image.data;
    m_eol_filter2_input.image.size.u = p_eol_mono_input->image.size.u;
    m_eol_filter2_input.image.size.v = p_eol_mono_input->image.size.v;
    m_eol_filter2_input.as_PointList[0].sl_X = m_eol_filter1_output.as_PointList[0].sl_X;
    m_eol_filter2_input.as_PointList[0].sl_Y = m_eol_filter1_output.as_PointList[0].sl_Y;
    m_eol_filter2_input.as_PointList[1].sl_X = m_eol_filter1_output.as_PointList[1].sl_X;
    m_eol_filter2_input.as_PointList[1].sl_Y = m_eol_filter1_output.as_PointList[1].sl_Y;
    m_eol_filter2_input.PatInnerCircleDiameter = p_eol_mono_input->PatInnerCircleDiameter;
    m_eol_filter2_input.f = p_eol_mono_input->f;
    m_eol_filter2_input.TargetDist = p_eol_mono_input->T_2_1.data[2] - p_eol_mono_input->T_2_C.data[2];
    //viscr_eol_filter2_init();
    viscr_eol_filter2_run(&m_eol_filter2_input,&m_eol_filter2_output);
    //viscr_eol_filter2_exit();
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: No error check. */
    if (m_eol_filter2_output.Errors == C_EOL_FILTER2_Errors::EOL_FILTER2_NO_ERROR)
    {
      m_eol_calib_input.f = p_eol_mono_input->f;
      m_eol_calib_input.u0 = p_eol_mono_input->u0;
      m_eol_calib_input.v0 = p_eol_mono_input->v0;
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Check if values must be exchanged. */
      if (m_eol_filter2_output.as_PointList[0].sl_X > m_eol_filter2_output.as_PointList[1].sl_X)
      {
        m_eol_calib_input.PI_C.m(0U,0U) = m_eol_filter2_output.as_PointList[0].sl_X;
        m_eol_calib_input.PI_C.m(1U,0U) = m_eol_filter2_output.as_PointList[0].sl_Y;
        m_eol_calib_input.PI_C.m(0U,1U) = m_eol_filter2_output.as_PointList[1].sl_X;
        m_eol_calib_input.PI_C.m(1U,1U) = m_eol_filter2_output.as_PointList[1].sl_Y;
      }
      else
      {
        m_eol_calib_input.PI_C.m(0U,0U) = m_eol_filter2_output.as_PointList[1].sl_X;
        m_eol_calib_input.PI_C.m(1U,0U) = m_eol_filter2_output.as_PointList[1].sl_Y;
        m_eol_calib_input.PI_C.m(0U,1U) = m_eol_filter2_output.as_PointList[0].sl_X;
        m_eol_calib_input.PI_C.m(1U,1U) = m_eol_filter2_output.as_PointList[0].sl_Y;
      }


      viscr_vec_zero(m_eol_calib_input.RA_2_C.v);
      viscr_vec_copy( m_eol_calib_input.T_2_C.v,p_eol_mono_input->T_2_C.v);
      //       *
      viscr_vec3  P_1[2];
      // right point
      P_1[0].data[0] = p_eol_mono_input->PatDistCircle2Center;
      P_1[0].data[1] = 0.0F;
      P_1[0].data[2] = 0.0F;
      // left point
      P_1[1].data[0] = -p_eol_mono_input->PatDistCircle2Center;
      P_1[1].data[1] = 0.0F;
      P_1[1].data[2] = 0.0F;
      viscr_vec_add(m_eol_calib_input.P_2[0].v,p_eol_mono_input->T_2_1.v,P_1[0].v);
      viscr_vec_add(m_eol_calib_input.P_2[1].v,p_eol_mono_input->T_2_1.v,P_1[1].v);
      viscr_vec_copy(m_eol_calib_input.T_2_1_std.v,p_eol_mono_input->T_2_1_std.v);
      viscr_vec_copy(m_eol_calib_input.T_2_3_std.v,p_eol_mono_input->T_2_3_std.v);
      viscr_eol_calib_run(&m_eol_calib_input,&m_eol_calib_output);
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: No error check. */
      if (m_eol_calib_output.Errors != C_EOL_CALIB_Errors::EOL_CALIB_NO_ERROR)
      { 
        p_eol_mono_output->Errors = m_eol_calib_output.Errors;
      }
      viscr_vec_copy(p_eol_mono_output->RA_2_C.v,m_eol_calib_output.RA_2_C.v);

    }


    else
    {
      p_eol_mono_output->Errors = m_eol_filter2_output.Errors;
    }

  }
  else 
  {
    p_eol_mono_output->Errors = m_eol_filter1_output.Errors;
  }

#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
  {
    SAC::EOL::CStereoCalibrationDebugData::SMonoData& data = SAC::EOL::CStereoCalibrationDebugData::instance()->monoData();
    std::memcpy(&data.input,  p_eol_mono_input,  sizeof(data.input));
    std::memcpy(&data.output, p_eol_mono_output, sizeof(data.output));
    data.valid = true;
  }
#endif
#endif
}

/* **************************************************************************** 
Functionname : viscr_eol_mono_exit()                                     */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */

/* ~CodeReview ~ID:90c2719d2a038a955d02912807e2573b ~Reviewer:CW01\uidv0048 ~Date:6/20/2012 ~Priority:3 ~Comment:This function is defined but it is empty and not called anywhere. Remove it for readability or modify it. */
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_mono_exit( )
{
 
}


