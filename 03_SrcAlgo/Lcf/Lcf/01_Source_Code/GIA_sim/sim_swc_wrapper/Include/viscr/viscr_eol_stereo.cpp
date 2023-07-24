/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_stereo.cpp  

  DESCRIPTION:    viscr_eol_stereo

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_stereo.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:28CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:14CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.12 2012/07/05 09:10:58CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        - Added comments -  uidv2823 [Jul 5, 2012 9:10:58 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/07/04 13:51:37CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 1:51:38 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.10 2012/05/31 17:35:00CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:35:00 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.9 2012/05/21 20:04:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:04:11 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.8 2012/04/26 10:49:26CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:26 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.7 2012/04/19 15:19:07CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:07 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2012/03/15 16:45:15CET Garcia, Lucien (uid26778) 
  CHANGES:        Integrate EOL function on SAC branch
  CHANGES:        --- Added comments ---  uid26778 [Mar 15, 2012 4:45:15 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.5 2012/03/13 11:53:03CET Garcia, Lucien (uid26778) 
  CHANGES:        Add Robustess Test for EOL calibration
  CHANGES:        --- Added comments ---  uid26778 [Mar 13, 2012 11:53:03 AM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.4 2012/03/07 10:30:43CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 7, 2012 10:30:43 AM CET]
  CHANGES:        Change Package : 101150:2 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.3 2012/03/06 11:54:10CET Garcia, Lucien (uid26778) 
  CHANGES:        Update EOL mode
  CHANGES:        --- Added comments ---  uid26778 [Mar 6, 2012 11:54:10 AM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.2 2012/03/02 13:04:24CET Exner, Christian (uidt8578) 
  CHANGES:        - added debugging connection to SAC::EOL::CStereoCalibrationDebug
  CHANGES:        --- Added comments ---  uidt8578 [Mar 2, 2012 1:04:24 PM CET]
  CHANGES:        Change Package : 101435:2 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.1 2012/01/19 14:20:54CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj



**************************************************************************** */

#include <viscr_eol_stereo.hpp>
#include <viscr_eol_mono.hpp>
#include <viscr_rotation.hpp>
#include <sac_errors.h>

#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
#include <viscr_eol_calib_debug.hpp>
#endif
#endif
/* **************************************************************************** 
Functionname : viscr_eol_stereo_init()                                    */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_stereo_init( )
{
 
}

/* **************************************************************************** 
Functionname : viscr_eol_stereo_run()                                     */ /*!  
Description  : 
@param		     p_eol_stereo_input
@return        p_eol_stereo_output
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_stereo_run(
    const viscr_eol_stereo_input *  const p_eol_stereo_input,
    viscr_eol_stereo_output * const p_eol_stereo_output)
{
  viscr_float temp_float_for_misra;

  p_eol_stereo_output->Errors = C_EOL_STEREO_Errors::EOL_STEREO_NO_ERROR; 

  // init right structure

#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
  SAC::EOL::CStereoCalibrationDebugData::instance()->setSide(SAC::EOL::CStereoCalibrationDebugData::S_RIGHT);
#endif
#endif

  viscr_eol_mono_input m_eol_mono_input;
  viscr_eol_mono_output m_eol_right_output;
  m_eol_mono_input.f = p_eol_stereo_input->f;
  m_eol_mono_input.u0 = p_eol_stereo_input->u0;  
  m_eol_mono_input.v0 = p_eol_stereo_input->v0;
  m_eol_mono_input.image.data = p_eol_stereo_input->image_right.data;
  m_eol_mono_input.image.size.u = p_eol_stereo_input->image_right.size.u;
  m_eol_mono_input.image.size.v = p_eol_stereo_input->image_right.size.v;
  viscr_vec_copy(m_eol_mono_input.R_2_C_mean.v,p_eol_stereo_input->RA_2_3_mean.v);
  viscr_vec_copy(m_eol_mono_input.R_2_C_std.v,p_eol_stereo_input->RA_2_3_std.v);
  viscr_vec_copy(m_eol_mono_input.T_2_C.v,p_eol_stereo_input->T_2_3_mean.v);
  viscr_vec_copy(m_eol_mono_input.T_2_1.v,p_eol_stereo_input->T_2_1_mean.v);

  m_eol_mono_input.PatDistCircle2Circle = p_eol_stereo_input->PatDistCircle2Circle;
  m_eol_mono_input.PatDistCircle2Center = p_eol_stereo_input->PatDistCircle2Center;
  m_eol_mono_input.PatOutCircleDiameter = p_eol_stereo_input->PatOutCircleDiameter;
  m_eol_mono_input.PatInnerCircleDiameter = p_eol_stereo_input->PatInnerCircleDiameter;
  viscr_vec_copy(m_eol_mono_input.T_2_1_std.v,p_eol_stereo_input->T_2_1_std.v);
  viscr_vec_copy(m_eol_mono_input.T_2_3_std.v,p_eol_stereo_input->T_2_3_std.v);
  viscr_eol_mono_run(&m_eol_mono_input,&m_eol_right_output);
  p_eol_stereo_output->Errors_right = m_eol_right_output.Errors;

  // init left structure
#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
  SAC::EOL::CStereoCalibrationDebugData::instance()->setSide(SAC::EOL::CStereoCalibrationDebugData::S_LEFT);
#endif
#endif

  viscr_eol_mono_output m_eol_left_output;
  m_eol_mono_input.image.data = p_eol_stereo_input->image_left.data;
  m_eol_mono_input.image.size.u = p_eol_stereo_input->image_left.size.u;
  m_eol_mono_input.image.size.v = p_eol_stereo_input->image_left.size.v;

  m_eol_mono_input.T_2_C.data[0] = m_eol_mono_input.T_2_C.data[0] + p_eol_stereo_input->T_5_6_mean.data[0];

  viscr_eol_mono_run(&m_eol_mono_input,&m_eol_left_output);

  p_eol_stereo_output->Errors_left = m_eol_left_output.Errors;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: No error check. */
  if ((p_eol_stereo_output->Errors_right == C_EOL_MONO_Errors::EOL_MONO_NO_ERROR) && (p_eol_stereo_output->Errors_left == C_EOL_MONO_Errors::EOL_MONO_NO_ERROR))
  {
    p_eol_stereo_output->Errors = C_EOL_STEREO_Errors::EOL_STEREO_NO_ERROR;
    // R_5_6 = R_2_5' x R_2_6
    // R_3_4 = R_3_5 x R_5_6 x R_6_4
    viscr_mat33 R_2_5;
    viscr_XYZFixedAngles2RotationMatrix(R_2_5,m_eol_right_output.RA_2_C.data[0],m_eol_right_output.RA_2_C.data[1],m_eol_right_output.RA_2_C.data[2]);
    viscr_mat33 R_2_6;
    viscr_XYZFixedAngles2RotationMatrix(R_2_6,m_eol_left_output.RA_2_C.data[0],m_eol_left_output.RA_2_C.data[1],m_eol_left_output.RA_2_C.data[2]);
    viscr_mat33 R_5_2;
    viscr_mat_transpose_copy(R_5_2.m,R_2_5.m);
    viscr_mat33 R_5_6;
    viscr_mat_mult_mat(R_5_6.m,R_5_2.m,R_2_6.m);
    viscr_mat33 R_tmp;
    viscr_mat33 R_5_3;
    viscr_XYZFixedAngles2RotationMatrix(R_5_3,p_eol_stereo_input->RA_5_3.data[0],p_eol_stereo_input->RA_5_3.data[1],p_eol_stereo_input->RA_5_3.data[2]);
    viscr_mat33 R_3_5;
    viscr_mat_transpose_copy(R_3_5.m,R_5_3.m);
    viscr_mat33 R_6_4;
    viscr_XYZFixedAngles2RotationMatrix(R_6_4,p_eol_stereo_input->RA_6_4.data[0],p_eol_stereo_input->RA_6_4.data[1],p_eol_stereo_input->RA_6_4.data[2]);
    viscr_mat33 R_3_4;
    viscr_mat_mult_mat(R_tmp.m,R_5_6.m,R_6_4.m);
    viscr_mat_mult_mat(R_3_4.m,R_3_5.m,R_tmp.m);
    viscr_mat_transpose_copy(R_tmp.m,R_3_4.m);
    viscr_RotationMatrix2XYZFixedAngles(p_eol_stereo_output->RA_4_3.data[0],p_eol_stereo_output->RA_4_3.data[1],p_eol_stereo_output->RA_4_3.data[2],R_tmp);
    
    for (viscr_int i=0; i<3; i++)
    {
      temp_float_for_misra = p_eol_stereo_output->RA_4_3.data[i] - p_eol_stereo_input->RA_4_3_mean.data[i];
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Error check. */
      if (fabsf(temp_float_for_misra)>p_eol_stereo_input->RA_4_3_std.data[i])
      {
        p_eol_stereo_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_RESULT_OUT_OF_RANGE);
        p_eol_stereo_output->RA_4_3.data[0] = 0.0F;
        p_eol_stereo_output->RA_4_3.data[1] = 0.0F;
        p_eol_stereo_output->RA_4_3.data[2] = 0.0F;
      }
    }
  }
  else
  {
    /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Is covered if errors will occur. */
    if (p_eol_stereo_output->Errors_right != C_EOL_MONO_Errors::EOL_MONO_NO_ERROR)
    {
      p_eol_stereo_output->Errors = p_eol_stereo_output->Errors_right;
    }
    /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Is covered if errors will occur. */
    if (p_eol_stereo_output->Errors_left != C_EOL_MONO_Errors::EOL_MONO_NO_ERROR)
    {
      p_eol_stereo_output->Errors = p_eol_stereo_output->Errors_left;
    }
    p_eol_stereo_output->RA_4_3.data[0] = 0.0F;
    p_eol_stereo_output->RA_4_3.data[1] = 0.0F;
    p_eol_stereo_output->RA_4_3.data[2] = 0.0F;
  }

#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
  {
    SAC::EOL::CStereoCalibrationDebugData& data = *SAC::EOL::CStereoCalibrationDebugData::instance();
    std::memcpy (&data.m_input,  p_eol_stereo_input,  sizeof(data.m_input ));
    std::memcpy (&data.m_output, p_eol_stereo_output, sizeof(data.m_output));
    data.m_valid = true;
  }
#endif
#endif
}

/* **************************************************************************** 
Functionname : viscr_eol_stereo_exit()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_stereo_exit( )
{
 
}


