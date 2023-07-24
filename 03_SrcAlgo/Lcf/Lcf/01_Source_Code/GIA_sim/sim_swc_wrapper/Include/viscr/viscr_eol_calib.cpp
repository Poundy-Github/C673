/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_calib.cpp  

  DESCRIPTION:    viscr_eol_calib

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_calib.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:26CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:08CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.12 2012/07/14 14:01:14CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage for dev 4.6.0
  CHANGES:        - Added comments -  uidv2823 [Jul 14, 2012 2:01:14 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/07/13 09:31:47CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 9:31:47 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.10 2012/07/04 15:38:43CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        Revision 1.9 2012/06/26 14:09:18CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        --- Added comments ---  uid28828 [Jun 26, 2012 2:09:19 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.8 2012/05/31 17:31:58CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:32:00 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.7 2012/05/21 20:03:52CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:03:55 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.6 2012/05/11 09:55:35CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove unless loop because of coding rules, no bug the behaviour is the same.
  CHANGES:        --- Added comments ---  uid26778 [May 11, 2012 9:55:37 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.5 2012/04/26 10:48:39CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:48:39 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.4 2012/03/08 11:21:46CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra error.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 8, 2012 11:21:46 AM CET]
  CHANGES:        Change Package : 101150:3 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.3 2012/03/07 15:17:17CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 7, 2012 3:17:17 PM CET]
  CHANGES:        Change Package : 101150:3 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.2 2012/02/22 17:28:49CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:49 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.1 2012/01/19 14:20:50CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#include <viscr_eol_calib.hpp>
#include <viscr_solve.hpp>
#include <viscr_rotation.hpp>
#include <sac_errors.h>

/* **************************************************************************** 
Functionname : viscr_eol_calib_P_2_to_P_C()                                           */ /*!  
Description  : P_C = R_C_2*P_2 + T_C_2
@param		     RA_2_C,T_2_C,P_2
@return        P_C
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_eol_calib_P_2_to_P_C(const viscr_mat31 & RA_2_C, const viscr_vec3 & T_2_C, const viscr_mat42 & P_2, viscr_mat42 & P_C)
{
  viscr_mat33 R_2_C;
  viscr_XYZFixedAngles2RotationMatrix(R_2_C,RA_2_C.data[0],RA_2_C.data[1],RA_2_C.data[2]);
  viscr_mat44 H_2_C;
  for( viscr_uint r=0U; r<3U; ++r)
  {
    H_2_C.m(r,3U) = T_2_C.data[r];
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

  viscr_mat44 H_C_2;
  viscr_invert_transformation(H_C_2,H_2_C);
  viscr_mat_mult_mat(P_C.m,H_C_2.m,P_2.m);
}

/* **************************************************************************** 
Functionname : viscr_eol_calib_P_C_to_PI_C()                              */ /*!  
Description  : P_C = R_C_2*P_2 + T_C_2
@param		     RA_2_C,T_2_C,P_2
@return        P_C
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_eol_calib_P_C_to_PI_C(const viscr_mat42 & P_C,const viscr_float & f,const viscr_float & u0,const viscr_float & v0,viscr_mat22 & PI_C)
{
  for(viscr_uint c=0U; c<P_C.m.cols;c++)
  {
    PI_C.m(0U,c) = ((f * P_C.m(0U,c)) / P_C.m(2U,c)) + u0;
    PI_C.m(1U,c) = ((f * P_C.m(1U,c)) / P_C.m(2U,c)) + v0;
  }
}
/* **************************************************************************** 
Functionname : viscr_eol_calib_norm()                              */ /*!  
Description  : 
@param		     
@return        
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_eol_calib_norm(viscr_mat22 & PI_C_true,viscr_mat22 &PI_C, viscr_mat22 &m_rl_Diff, viscr_float &m_rl_DiffNorm)
{
  viscr_float m_rl_DiffSquare = 0.0F;
  for( viscr_uint r=0U; r<2U; ++r)
  {
    for( viscr_uint c=0U; c<2U; ++c)
    {
      m_rl_Diff.m(r,c) = PI_C_true.m(r,c) - PI_C.m(r,c);
      m_rl_DiffSquare += m_rl_Diff.m(r,c)*m_rl_Diff.m(r,c);
    }
  }
  m_rl_DiffNorm = sqrtf(m_rl_DiffSquare);
}

/* **************************************************************************** 
Functionname : viscr_eol_calib_init()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_calib_init()
{
 
}

/* **************************************************************************** 
Functionname : viscr_eol_run()                                           */ /*!  
Description  : 
@param		     p_eol_input
@return        p_eol_output
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_calib_run(
    viscr_eol_calib_input *  const p_eol_calib_input,
    viscr_eol_calib_output *  const p_eol_calib_output)
{
  viscr_mat42 P_2;
  viscr_mat42 P_C;
  viscr_mat31 RA_2_C;
  viscr_mat31 RA_2_C_diff;
  viscr_vec3 T_2_C;
  viscr_int sl_NIter = 0;
  viscr_vec2 m_rl_DiffNorm;
  viscr_mat22 m_rl_Diff;
  viscr_mat22 PI_C;
  m_rl_DiffNorm.data[0] = 0.0F;
  m_rl_DiffNorm.data[1] = 0.0F;
  viscr_mat43 m_aarl_Jacob;
  viscr_mat41 m_arl_Err;  

  viscr_mat33 m_aarl_Jacob2;
  viscr_mat31 m_arl_Err2;  
  /* ~CodeReview ~ID:f050590af2f41f812ed70f84a318f0db ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:3 ~Comment:Magic number */
  const viscr_int max_loop=10;
  
  bool_t terminate_loop = FALSE;

  p_eol_calib_output->Errors = C_EOL_CALIB_Errors::EOL_CALIB_NO_ERROR;

  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<2U; ++c)
    {
      P_2.m(r,c) = p_eol_calib_input->P_2[c].data[r];
    }
  }
  P_2.m(3U,0U) = 1.0F;
  P_2.m(3U,1U) = 1.0F;

  RA_2_C.data[0] = p_eol_calib_input->RA_2_C.data[0];
  RA_2_C.data[1] = p_eol_calib_input->RA_2_C.data[1];
  RA_2_C.data[2] = p_eol_calib_input->RA_2_C.data[2];

  /* ~CodeReview ~ID:cdb86aac84bb4726ff80ff2df11f36a7 ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:3 ~Comment:useless copy */
  viscr_vec_copy(T_2_C.v, p_eol_calib_input->T_2_C.v);

	//Loop
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Run for loop. */
  for(viscr_int i_loop=0;i_loop<=max_loop;i_loop++)
	{
    viscr_eol_calib_P_2_to_P_C(RA_2_C, p_eol_calib_input->T_2_C, P_2, P_C);

    viscr_eol_calib_P_C_to_PI_C(P_C,p_eol_calib_input->f,p_eol_calib_input->u0,p_eol_calib_input->v0,PI_C);

    viscr_eol_calib_norm(p_eol_calib_input->PI_C,PI_C,m_rl_Diff, m_rl_DiffNorm.data[0]);

	  //apply the stop condition (difference between the current norm and the precedent norm)
    if((fabsf(m_rl_DiffNorm.data[1]-m_rl_DiffNorm.data[0])>0.0000000001F) && (sl_NIter<max_loop))
    {
			//increment the number of iteration
			sl_NIter++;

	    //compute the error vector and the jacobian matrix
      for(viscr_uint sl_NPt=0U ; sl_NPt<p_eol_calib_input->PI_C.m.cols ; sl_NPt++)
      {	
        // A * x = b and we should find b
        m_arl_Err.data[2U*sl_NPt] = m_rl_Diff.m(0U,sl_NPt);
        m_arl_Err.data[(2U*sl_NPt)+1U] = m_rl_Diff.m(1U,sl_NPt);
        viscr_float z_square;
        viscr_float f;
        z_square = P_C.m(2U,sl_NPt) *P_C.m(2U,sl_NPt);
        f = p_eol_calib_input->f;
        /* ~CodeReview ~ID:9480ef8e3f34c662f652d7c45d2e0b22 ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:Hard to believe jacobian does not depend on roation matrix elements or input angles */
        m_aarl_Jacob.m(((2U*sl_NPt)),0U) = -(f * (P_C.m(0U,sl_NPt)*P_C.m(1U,sl_NPt))) / z_square;
        m_aarl_Jacob.m(((2U*sl_NPt)+1U),0U) = -f * (1.0F + ((P_C.m(1U,sl_NPt)*P_C.m(1U,sl_NPt)) / z_square));
        m_aarl_Jacob.m(((2U*sl_NPt)),1U) = f * (1.0F +  ((P_C.m(0U,sl_NPt)*P_C.m(0U,sl_NPt)) / z_square));
        m_aarl_Jacob.m(((2U*sl_NPt)+1U),1U) = -m_aarl_Jacob.m(((2U*sl_NPt)),0U);
        m_aarl_Jacob.m(((2U*sl_NPt)),2U) = -(f * P_C.m(1U,sl_NPt)) / P_C.m(2U,sl_NPt);
        m_aarl_Jacob.m(((2U*sl_NPt)+1U),2U) = (f * P_C.m(0U,sl_NPt)) / P_C.m(2U,sl_NPt);
      }

      /* ~CodeReview ~ID:c8c25b1156f1cc9a446ff45ccec65d3d ~Reviewer:CW01\uid28828 ~Date:26/06/2012 ~Priority:2 ~Comment:Not clear why merging two equations into one */
      for (viscr_uint i=0U ; i<m_aarl_Jacob.m.cols ; i++)
      {
        m_aarl_Jacob2.m(0U,i) = m_aarl_Jacob.m(0U,i) + m_aarl_Jacob.m(2U,i);
        m_aarl_Jacob2.m(1U,i) = m_aarl_Jacob.m(1U,i);
        m_aarl_Jacob2.m(2U,i) = m_aarl_Jacob.m(3U,i);
      }
      m_arl_Err2.m(0U,0U) = m_arl_Err.m(0U,0U) + m_arl_Err.m(2U,0U);
      m_arl_Err2.m(1U,0U) = m_arl_Err.m(1U,0U);
      m_arl_Err2.m(2U,0U) = m_arl_Err.m(3U,0U);                              

      viscr_mat33 LU;
      viscr_uint piv[3];
      viscr_float LUcol[3];

      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: LU decomposition passed. */
      if (viscr_compute_LU( LU.m,&piv[0],&LUcol[0], m_aarl_Jacob2.m))
      {
        /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: LU solved. */
        if (viscr_solve_LU( RA_2_C_diff.m,LU.m,&piv[0],m_arl_Err2.m))
        {
          /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Valid for loop coverage. */
          for(viscr_uint i=0U ; i<RA_2_C_diff.m.rows ; i++)
          {
            RA_2_C.data[i] -= RA_2_C_diff.data[i];
          }
          //record the last norm of Diff
          m_rl_DiffNorm.data[1] = m_rl_DiffNorm.data[0];
        }
        else
        {
          p_eol_calib_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_NUMERICAL_PROBLEM);
          terminate_loop = TRUE;
        }

      }
      else 
      {
        p_eol_calib_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_NUMERICAL_PROBLEM);
        terminate_loop = TRUE;
      }
    }		
    else //record the solution
    {
      // Calculate VISCR_EOL_CALIB_MAX_ERROR 
      viscr_float TargetDist = p_eol_calib_input->P_2[0].data[2]-p_eol_calib_input->T_2_C.data[2];
      viscr_float TargetDist_std = p_eol_calib_input->T_2_1_std.data[2] + p_eol_calib_input->T_2_3_std.data[2];
      viscr_float TargetSize = p_eol_calib_input->P_2[0].data[0] - p_eol_calib_input->P_2[1].data[0];
      viscr_float Max_rl_Diff = ((TargetSize*p_eol_calib_input->f)/(TargetDist-TargetDist_std))-((TargetSize*p_eol_calib_input->f)/(TargetDist));
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Value is in range. */
      if (Max_rl_Diff<VISCR_EOL_CALIB_MAX_ERROR)
      {
        Max_rl_Diff=VISCR_EOL_CALIB_MAX_ERROR;
      }

      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Value is out of range. */
      if (m_rl_DiffNorm.data[0]>Max_rl_Diff)
      {
        p_eol_calib_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_PATTERN_ADJUSTMENT);
      }
      for(viscr_uint i=0U ; i<RA_2_C_diff.m.rows ; i++)
      {
        p_eol_calib_output->RA_2_C.data[i] = RA_2_C.data[i];
      }
      terminate_loop = TRUE;
    }
    if ( terminate_loop == TRUE )
    {
        break;
    }
  } // infinite loop
}

/* **************************************************************************** 
Functionname : viscr_eol_calib_exit()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_calib_exit( )
{
 
}


