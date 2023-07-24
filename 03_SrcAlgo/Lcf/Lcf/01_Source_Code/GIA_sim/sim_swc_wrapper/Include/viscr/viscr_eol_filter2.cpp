/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_filter2.cpp  

  DESCRIPTION:    viscr_eol_filter2

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_filter2.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:27CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:11CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.15 2012/07/17 15:54:02CEST Garcia, Lucien (uid26778) 
  CHANGES:        Pc lint
  CHANGES:        - Added comments -  uid26778 [Jul 17, 2012 3:54:02 PM CEST]
  CHANGES:        Change Package : 138467:2 http://mks-psad:7002/im/viewissue?selection=138467
  CHANGES:        Revision 1.14 2012/07/13 17:12:48CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage for dev 4.6.0
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 5:12:48 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.13 2012/07/05 15:38:31CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add coverage tags
  CHANGES:        --- Added comments ---  uid26778 [Jul 5, 2012 3:38:31 PM CEST]
  CHANGES:        Change Package : 133274:1 http://mks-psad:7002/im/viewissue?selection=133274
  CHANGES:        Revision 1.12 2012/07/04 16:32:13CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 4:32:13 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/06/25 09:38:43CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added code review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:38:43 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.10 2012/05/31 17:33:49CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:33:50 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.9 2012/05/21 20:03:51CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:03:52 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.8 2012/04/26 10:49:25CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:25 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.7 2012/04/19 15:19:07CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:07 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2012/03/15 16:45:13CET Garcia, Lucien (uid26778) 
  CHANGES:        Integrate EOL function on SAC branch
  CHANGES:        --- Added comments ---  uid26778 [Mar 15, 2012 4:45:13 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.5 2012/03/12 14:23:25CET Exner, Christian (uidt8578) 
  CHANGES:        - removed useless const
  CHANGES:        --- Added comments ---  uidt8578 [Mar 12, 2012 2:23:25 PM CET]
  CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.4 2012/03/09 15:15:19CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Mar 9, 2012 3:15:19 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.3 2012/03/05 18:36:30CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Mar 5, 2012 6:36:30 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2012/03/05 15:50:20CET Exner, Christian (uidt8578) 
  CHANGES:        - added filter 2 visualization
  CHANGES:        --- Added comments ---  uidt8578 [Mar 5, 2012 3:50:20 PM CET]
  CHANGES:        Change Package : 101435:2 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.1 2012/01/19 14:20:52CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */

#include <viscr_eol_filter2.hpp>
#include <viscr_solve.hpp>
#include <sac_errors.h>
#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
#include <viscr_eol_calib_debug.hpp>
#endif
#endif

static viscr_eol_filter2 eol_filter2; 

/* **************************************************************************** 
Functionname : viscr_eol_run_filter2()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_eol_run_filter2(const viscr_image & p_image,viscr_eol_filter2 & p_eol_filter2, const viscr_float TargetDist, const viscr_float PatInnerCircleDiameter, const viscr_float f)
{
  const viscr_int d_size = 10;
  viscr_float a;
  a = PatInnerCircleDiameter/2.0F;
  viscr_float d[d_size];
  // cos(45°) = 0.7071; cos(30°) = 0.8660F; sin(30°) = 0.5F; cos(22.5°) = 0.9239; cos(67.5°) = 0.3827
  d[0] = a/4.0F;
  d[1] = a/2.0F;
  d[2] = a*0.7071F;
  d[3] = (3.0F*a)/4.0F;
  d[4] = ((3.0F*a)/4.0F)* 0.8660F;
  d[5] = ((3.0F*a)/4.0F)* 0.5F;
  d[6] = a*0.9239F;
  d[7] = a*0.7071F;
  d[8] = a*0.3827F;
  d[9] = a;
  viscr_int d_px[d_size];
  f32_t temp_float_for_misra;
  for (viscr_int i=0; i<d_size;i++)
  {
    // ~CodeReview ~ID:012e2b920b91f465eba9049ad45f1950 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Potential Div by zero
    temp_float_for_misra = ((d[i]*f)/TargetDist);
    d_px[i] = static_cast<viscr_int>(temp_float_for_misra);
  }

  const viscr_int filter_add_3_size = 13;
  viscr_int filter_add_3[filter_add_3_size];
  filter_add_3[0] = 0;
  filter_add_3[1] = d_px[0];
  filter_add_3[2] = -d_px[0];
  filter_add_3[3] = d_px[0]*image_width;
  filter_add_3[4] = -d_px[0]*image_width;
  filter_add_3[5] = d_px[1];
  filter_add_3[6] = -d_px[1];
  filter_add_3[7] = d_px[1]*image_width;
  filter_add_3[8] = -d_px[1]*image_width;
  filter_add_3[9] = d_px[2]+(d_px[2]*image_width);
  filter_add_3[10] = d_px[2]-(d_px[2]*image_width);
  filter_add_3[11] = -d_px[2]+(d_px[2]*image_width);
  filter_add_3[12] = -d_px[2]-(d_px[2]*image_width);

  const viscr_int filter_add_2_size = 12;
  viscr_int filter_add_2[filter_add_2_size];
  filter_add_2[0] = d_px[3];
  filter_add_2[1] = -d_px[3];
  filter_add_2[2] = d_px[3]*image_width;
  filter_add_2[3] = -d_px[3]*image_width;
  filter_add_2[4] = d_px[4]+(d_px[5]*image_width);
  filter_add_2[5] = -d_px[4]+(d_px[5]*image_width);
  filter_add_2[6] = d_px[4]-(d_px[5]*image_width);
  filter_add_2[7] = -d_px[4]-(d_px[5]*image_width);
  filter_add_2[8] = d_px[5]+(d_px[4]*image_width);
  filter_add_2[9] = -d_px[5]+(d_px[4]*image_width);
  filter_add_2[10] = d_px[5]-(d_px[4]*image_width);
  filter_add_2[11] = -d_px[5]-(d_px[4]*image_width);

  const viscr_int filter_add_1_size = 16;
  viscr_int filter_add_1[filter_add_1_size];
  filter_add_1[0] = d_px[6]+(d_px[8]*image_width);
  filter_add_1[1] = -d_px[6]+(d_px[8]*image_width);
  filter_add_1[2] = d_px[6]-(d_px[8]*image_width);
  filter_add_1[3] = -d_px[6]-(d_px[8]*image_width);
  filter_add_1[4] = d_px[8]+(d_px[6]*image_width);
  filter_add_1[5] = -d_px[8]+(d_px[6]*image_width);
  filter_add_1[6] = d_px[8]-(d_px[6]*image_width);
  filter_add_1[7] = -d_px[8]-(d_px[6]*image_width);
  filter_add_1[8] = d_px[7]+(d_px[7]*image_width);
  filter_add_1[9] = -d_px[7]+(d_px[7]*image_width);
  filter_add_1[10] = d_px[7]-(d_px[7]*image_width);
  filter_add_1[11] = -d_px[7]-(d_px[7]*image_width);
  filter_add_1[12] = d_px[9];
  filter_add_1[13] = -d_px[9];
  filter_add_1[14] = (d_px[9]*image_width);
  filter_add_1[15] = -(d_px[9]*image_width);

  viscr_int * p_filter_add_1;
  viscr_int * p_filter_add_2;
  viscr_int * p_filter_add_3;
  p_filter_add_1 = &filter_add_1[0];
  p_filter_add_2 = &filter_add_2[0];
  p_filter_add_3 = &filter_add_3[0];

  viscr_int u_start = p_eol_filter2.filter_start_width; 
  viscr_int u_stop = p_eol_filter2.filter_start_width + p_eol_filter2.filter_width; 
  viscr_int v_start = p_eol_filter2.filter_start_height;
  viscr_int v_stop = p_eol_filter2.filter_start_height + p_eol_filter2.filter_height; 

  viscr_int index_filter=0;
  viscr_int  index_image=0;
  viscr_pixel temp_pixel_for_misra;
  viscr_int   temp_index_for_misra;
  for (viscr_int v=v_start; v<v_stop; v=v+1)
  {
      for (viscr_int u=u_start; u<u_stop; u=u+1)
      {
        viscr_uint filter_sum = 0U;
        index_image = (v*image_width)+u;
        p_eol_filter2.filter[index_filter] = 0U;

        for (viscr_int index=0;index<filter_add_3_size; index++) 
        {
		      /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
          temp_index_for_misra = index_image+p_filter_add_3[index];
          // ~CodeReview ~ID:9d9fddf68d90ba9b26df5e6c6f1b4b6f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 734 (loss of precision) not commented
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
		      temp_pixel_for_misra = 3U*p_image.data[static_cast<viscr_uint>(temp_index_for_misra)];
          filter_sum  = filter_sum + static_cast<viscr_uint>(temp_pixel_for_misra);
        }

        for (viscr_int index=0;index<filter_add_2_size; index++) 
        {
		      /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
          temp_index_for_misra = index_image+p_filter_add_2[index];
          // ~CodeReview ~ID:933277aba2bb73add55ce04331201b1c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 734 (loss of precision) not commented
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
		      temp_pixel_for_misra = 2U*p_image.data[static_cast<viscr_uint>(temp_index_for_misra)];
          filter_sum = filter_sum + temp_pixel_for_misra;
        }

        for (viscr_int index=0;index<filter_add_1_size; index++) 
        {
		      /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
          temp_index_for_misra = index_image+p_filter_add_1[index];
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
		      temp_pixel_for_misra = p_image.data[static_cast<viscr_uint>(temp_index_for_misra)];
          filter_sum = filter_sum + temp_pixel_for_misra;
        }
        p_eol_filter2.filter[index_filter] = filter_sum;
        index_filter++;
      }
  }

#if (VISCR_EOL_DEBUG==1) // DEBUG 
  viscr_int8 numstr[256];
  sprintf(numstr,"Z:/OUT/viscr_eol_filter2.pgm");
  
	FILE * fo=fopen( numstr, "w");
	if( fo)
	{
		fprintf( fo, "P2\n%d %d\n4095\n", p_eol_filter2.filter_width, p_eol_filter2.filter_height);
			const viscr_uint n=p_eol_filter2.filter_width*p_eol_filter2.filter_height;
		for( viscr_uint i=0; i<n; ++i)
			fprintf( fo, "%d ", p_eol_filter2.filter[i]/80);
		fclose( fo);
    }
  // matlab vizualization with :
  // figure;surf(double(pgm_read('z:\OUT\viscr_eol_filter2.pgm')));
#endif
}

/* **************************************************************************** 
Functionname : viscr_eol_findmax_filter2()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static viscr_int viscr_eol_findmax_filter2(const viscr_eol_filter2 & p_eol_filter2, S_F_POINT & as_PointList)
{
  viscr_int i32_Ret = C_SACErrors::i32_SAC_NO_ERROR;
  S_SL_POINT as_PointMax;
  viscr_uint as_PointMaxValue = 0U;
  viscr_int index_filter = 0;
  as_PointMax.sl_X = 0;
  as_PointMax.sl_Y = 0;
  for (viscr_int v=0; v<p_eol_filter2.filter_height; v=v+1)
  {
    for (viscr_int u=0; u<p_eol_filter2.filter_width; u=u+1)
    {
      if (p_eol_filter2.filter[index_filter]>as_PointMaxValue)
      {
        as_PointMax.sl_X = u;
        as_PointMax.sl_Y = v;
        as_PointMaxValue = p_eol_filter2.filter[index_filter];
      }
      index_filter++;
    }
  }
  viscr_mat96 A;
  viscr_vec9 b;
  viscr_mat91 B;
  viscr_int A_index=0;
  viscr_int b_index=0;
  viscr_int temp_int_for_misra;
  for (viscr_int v=(as_PointMax.sl_Y-1);v<=(as_PointMax.sl_Y+1);v++)
  {
    for (viscr_int u=(as_PointMax.sl_X-1);u<=(as_PointMax.sl_X+1);u++)
    {
   // ~CodeReview ~ID:f96221278984e09812da929c9c8c4262 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Indent should be corrected
	  temp_int_for_misra = u*u;
      A.data[A_index] = static_cast<viscr_float>(temp_int_for_misra);
   // ~CodeReview ~ID:24429473e3827ae3d5517b0ebb14d194 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Indent should be corrected
	  temp_int_for_misra = v*v;
      A.data[A_index+1] = static_cast<viscr_float>(temp_int_for_misra);
   // ~CodeReview ~ID:18fd0fa8aec7305e339e1c3dc4abebba ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Indent should be corrected
	  temp_int_for_misra = u*v;
      A.data[A_index+2] = static_cast<viscr_float>(temp_int_for_misra);
      A.data[A_index+3] = static_cast<viscr_float>(u);
      A.data[A_index+4] = static_cast<viscr_float>(v);
      A.data[A_index+5] = 1.0F;
      A_index = A_index + 6;
      b.data[b_index] = static_cast<viscr_float>(p_eol_filter2.filter[u+(v*p_eol_filter2.filter_width)]);
      B.data[b_index] = static_cast<viscr_float>(p_eol_filter2.filter[u+(v*p_eol_filter2.filter_width)]);
      b_index = b_index + 1;
    }
  }

  viscr_mat96 LU;
  viscr_uint piv[9];
  viscr_float LUcol[9];
  viscr_mat61 X;
  as_PointList.sl_X = 0.0F;
  as_PointList.sl_Y = 0.0F;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: LU decomposition is valid. */
  if( viscr_compute_LU( LU.m,&piv[0],&LUcol[0], A.m))
  {
    /* <ln_offset:+1 COVERAGE reviewer name: GARCIA Lucien date: 05.07.2012 reason: viscr_solve_LU always return true. */
    if( viscr_solve_LU( X.m,LU.m,&piv[0],B.m))
    {
      // Calculate the paraboloid maximums
      // ~CodeReview ~ID:d8a6011bdf9bd57dd2b05534148fbc7a ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Potential Div by Zero
      as_PointList.sl_X = ((2.0F*X.data[3]* X.data[1]) -  (X.data[2]* X.data[4]))  / ( (X.data[2]*X.data[2]) - (4.0F*X.data[0]*X.data[1])   );
      // ~CodeReview ~ID:d05c541ae9a1c9c7dc691f766ea601f1 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Potential Div by Zero
      as_PointList.sl_Y = ((2.0F*X.data[0]* X.data[4]) -  (X.data[3]* X.data[2]))  / ( (X.data[2]*X.data[2]) - (4.0F*X.data[0]*X.data[1])   );
    }
    else
    {
      i32_Ret = C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_NUMERICAL_PROBLEM;
    }
  }
  else
  {
    i32_Ret = C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_NUMERICAL_PROBLEM;
  }
  return i32_Ret;
}

/* **************************************************************************** 
Functionname : viscr_eol_filter2_init()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* <ln_offset:+1to+3 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_filter2_init( )
{
}

/* **************************************************************************** 
Functionname : viscr_eol_filter2_run()                                           */ /*!  
Description  : 
@param		     p_eol_mono_input
@return        p_eol_filter1_output
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_filter2_run(
    const viscr_eol_filter2_input *  const p_eol_filter2_input,
    viscr_eol_filter2_output *  const p_eol_filter2_output)
{
  p_eol_filter2_output->Errors = C_EOL_FILTER2_Errors::EOL_FILTER2_NO_ERROR;
  for (viscr_int i=0; i<2; i++)
  {
    eol_filter2.filter_width = VISCR_EOL_FILTER2_WIDTH;
    eol_filter2.filter_height = VISCR_EOL_FILTER2_HEIGHT;
    eol_filter2.filter_start_width = p_eol_filter2_input->as_PointList[i].sl_X - (eol_filter2.filter_width/2);
    eol_filter2.filter_start_height = p_eol_filter2_input->as_PointList[i].sl_Y - (eol_filter2.filter_height/2);

    viscr_eol_run_filter2(p_eol_filter2_input->image,  eol_filter2, p_eol_filter2_input->TargetDist, p_eol_filter2_input->PatInnerCircleDiameter, p_eol_filter2_input->f);
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
    if (viscr_eol_findmax_filter2(eol_filter2, p_eol_filter2_output->as_PointList[i]) != C_SACErrors::i32_SAC_NO_ERROR)
    {
      p_eol_filter2_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_UNCORRESPONDING_MARKERS);
      p_eol_filter2_output->as_PointList[i].sl_X = 0.0F;
      p_eol_filter2_output->as_PointList[i].sl_Y = 0.0F;
    }
    else
    {
      p_eol_filter2_output->as_PointList[i].sl_X = static_cast<viscr_float>(eol_filter2.filter_start_width) + p_eol_filter2_output->as_PointList[i].sl_X;
      p_eol_filter2_output->as_PointList[i].sl_Y = static_cast<viscr_float>(eol_filter2.filter_start_height) + p_eol_filter2_output->as_PointList[i].sl_Y;
    }


#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
    {
      SAC::EOL::CStereoCalibrationDebugData::SMonoData& data = SAC::EOL::CStereoCalibrationDebugData::instance()->monoData();
      std::memcpy(&data.filter2Data[i], &eol_filter2, sizeof(data.filter2Data[i]));
    }
#endif
#endif
  }

#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
  {
    SAC::EOL::CStereoCalibrationDebugData::SMonoData& data = SAC::EOL::CStereoCalibrationDebugData::instance()->monoData();
    std::memcpy(&data.filter2Input,    p_eol_filter2_input,  sizeof(data.filter2Input));
    std::memcpy(&data.filter2Output,   p_eol_filter2_output, sizeof(data.filter2Output));
    data.filter2valid = true;
  }
#endif
#endif
}

/* **************************************************************************** 
Functionname : viscr_eol_filer2_exit()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_filter2_exit( )
{
 
}


