/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_eol_filter1.cpp  

  DESCRIPTION:    viscr_eol_filter1

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  19.01.2012

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_eol_filter1.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:27CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:10CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.17 2012/07/14 14:41:12CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage for dev 4.6.0
  CHANGES:        - Added comments -  uidv2823 [Jul 14, 2012 2:41:13 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.16 2012/07/13 09:50:04CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tag
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 9:50:04 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.15 2012/07/05 15:37:55CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add coverage tags
  CHANGES:        --- Added comments ---  uid26778 [Jul 5, 2012 3:37:56 PM CEST]
  CHANGES:        Change Package : 133274:1 http://mks-psad:7002/im/viewissue?selection=133274
  CHANGES:        Revision 1.14 2012/07/04 16:22:28CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 4:22:29 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.13 2012/07/04 13:48:33CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tag
  CHANGES:        Revision 1.12 2012/06/25 09:38:31CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added code review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:38:31 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.11 2012/05/31 17:32:42CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:32:44 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.10 2012/05/31 11:56:11CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 11:56:11 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.9 2012/05/21 20:03:56CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add error code for eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [May 21, 2012 8:03:58 PM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.8 2012/04/26 10:49:24CEST Garcia, Lucien (uid26778) 
  CHANGES:        Stereo end of line update
  CHANGES:        --- Added comments ---  uid26778 [Apr 26, 2012 10:49:25 AM CEST]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.7 2012/04/19 15:18:57CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:18:57 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2012/04/19 14:31:36CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove static variables on SAC kernel
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 2:31:36 PM CEST]
  CHANGES:        Change Package : 106188:1 http://mks-psad:7002/im/viewissue?selection=106188
  CHANGES:        Revision 1.5 2012/04/06 16:34:48CEST Garcia, Lucien (uid26778) 
  CHANGES:        EOL calibration could manage target at 4m (from front vehicle axe)
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 4:34:48 PM CEST]
  CHANGES:        Change Package : 106060:1 http://mks-psad:7002/im/viewissue?selection=106060
  CHANGES:        Revision 1.4 2012/03/15 16:45:15CET Garcia, Lucien (uid26778) 
  CHANGES:        Integrate EOL function on SAC branch
  CHANGES:        --- Added comments ---  uid26778 [Mar 15, 2012 4:45:15 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.3 2012/03/12 14:23:08CET Exner, Christian (uidt8578) 
  CHANGES:        - removed useless const
  CHANGES:        --- Added comments ---  uidt8578 [Mar 12, 2012 2:23:08 PM CET]
  CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.2 2012/03/01 15:00:40CET Exner, Christian (uidt8578) 
  CHANGES:        - added debugging adaptation code
  CHANGES:        Revision 1.1 2012/01/19 14:20:51CET Garcia, Lucien (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj



**************************************************************************** */

#include <viscr_eol_filter1.hpp>
#include <sac_errors.h>
#ifdef PC_SIM
#if VISCR_EOL_DEBUG_PC_SIM
#include <viscr_eol_calib_debug.hpp>
#endif
#endif
static viscr_eol_filter1 eol_filter1; 
static S_INTERNAL_IMAGE_POINT m_as_InternalPointList[sl_MAX_NO_OF_POINTS];

/* **************************************************************************** 
Functionname : C_TAC_FindChessboardPatterns::rl32_GetSubPixel             */ /*!  
Description  : Calculates the subpixel value
@param[in]	   ub_Left 
@param[in]	   ub_Middle
@param[in]	   ub_Right
@return        maximum subpixel value
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static viscr_float rl32_GetSubPixel(const viscr_uint8 ub_Left,const viscr_uint8 ub_Middle,const viscr_uint8 ub_Right) 
{
	viscr_float rl32_Pos = 0.0F;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Dead code. */
	if( 0 == ((static_cast<viscr_int>(ub_Left)+static_cast<viscr_int>(ub_Right))-(2*static_cast<viscr_int>(ub_Middle))))
	{
		rl32_Pos = 0.0F;//never enter here; this case is verified and treated before calling the function
	}
	else
	{
		rl32_Pos = (static_cast<viscr_float>(ub_Left)-static_cast<viscr_float>(ub_Right))/((static_cast<viscr_float>(ub_Left)+static_cast<viscr_float>(ub_Right))-(2.0F*static_cast<viscr_float>(ub_Middle)));
	}

	return rl32_Pos;
}


/* **************************************************************************** 
Functionname : viscr_eol_init()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static void viscr_eol_run_filter1(const viscr_image & p_image,viscr_eol_filter1 & p_eol_filter, const  viscr_float PatOutCircleDiameter, const  viscr_float PatInnerCircleDiameter, const  viscr_float f, const  viscr_float TargetDist)
{
////////////////////////////////////////////////////
// IMAGE FILTERING
////////////////////////////////////////////////////
       
//h = [ 0  0  0  1  0  0  0  0  0  1  0  0  0;
//      0  0  0  0  0  0  0  0  0  0  0  0  0;
//      0  0  0  0  0  0 -1  0  0  0  0  0  0;
//      1  0  0  0 -1  0 -1  0 -1  0  0  0  1;
//      0  0  0 -1  0  0  0  0  0 -1  0  0  0;
//      0  0  0  0  0  0  1  0  0  0  0  0  0;
//      0  0 -1 -1  0  1  1  1  0 -1 -1  0  0;
//      0  0  0  0  0  0  1  0  0  0  0  0  0;
//      0  0  0 -1  0  0  0  0  0 -1  0  0  0;
//      1  0  0  0 -1  0 -1  0 -1  0  0  0  1;
//      0  0  0  0  0  0 -1  0  0  0  0  0  0;
//      0  0  0  0  0  0  0  0  0  0  0  0  0;
//      0  0  0  1  0  0  0  0  0  1  0  0  0]

  // ~CodeReview ~ID:9174ef3ed773c3b1a7410a5be712b99d ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
  const viscr_int d_size = 7;
  viscr_float a;
  a = PatInnerCircleDiameter/2.0F;
  viscr_float b;
  b = PatOutCircleDiameter/2.0F;
  viscr_float d[d_size];
  d[0] = a/2.0F;
  d[1] = ((b-a)/3.0F) + a;
  d[2] = ((2.0F*(b-a))/3.0F) + a;
  // ~CodeReview ~ID:7e2cb689997ae65a01e0abbd1830ba12 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
  d[3] = (a+((b-a)/2.0F))*0.8660F;  // cos(30) = 0.8660F
  d[4] = (a+((b-a)/2.0F))*0.5F;     // sin(30) = 0.5F
  d[5] = (a+b)*0.8660F;
  d[6] = (a+b)*0.5F;

  viscr_int d_px[d_size];
  f32_t temp_float_for_misra;
  for (viscr_int i=0; i<d_size;i++)
  {
    temp_float_for_misra = ((d[i]*f)/TargetDist)+0.5F;
    d_px[i] = static_cast<viscr_int>(temp_float_for_misra);
  }
  const viscr_int filter_less_size = 16;
  const viscr_int filter_add_size = 13;
  viscr_int filter_add[filter_add_size];
  viscr_int filter_less[filter_less_size];

  filter_add[0] = 0;
  filter_add[1] = d_px[0];
  filter_add[2] = -d_px[0];
  filter_add[3] = d_px[0]*image_width;
  filter_add[4] = -d_px[0]*image_width;
  filter_add[5] = d_px[5]+(d_px[6]*image_width);
  filter_add[6] = -d_px[5]+(d_px[6]*image_width);
  filter_add[7] = -d_px[5]-(d_px[6]*image_width);
  filter_add[8] = d_px[5]-(d_px[6]*image_width);
  filter_add[9] = d_px[6]+(d_px[5]*image_width);
  filter_add[10] = -d_px[6]+(d_px[5]*image_width);
  filter_add[11] = -d_px[6]-(d_px[5]*image_width);
  filter_add[12] = d_px[6]-(d_px[5]*image_width);

  filter_less[0] = d_px[1];
  filter_less[1] = -d_px[1];
  filter_less[2] = d_px[1]*image_width;
  filter_less[3] = -d_px[1]*image_width;
  filter_less[4] = d_px[2];
  filter_less[5] = -d_px[2];
  filter_less[6] = d_px[2]*image_width;
  filter_less[7] = -d_px[2]*image_width;
  filter_less[8] = d_px[3]+(d_px[4]*image_width);
  filter_less[9] = -d_px[3]+(d_px[4]*image_width);
  filter_less[10] = -d_px[3]-(d_px[4]*image_width);
  filter_less[11] = d_px[3]-(d_px[4]*image_width);
  filter_less[12] = d_px[4]+(d_px[3]*image_width);
  filter_less[13] = -d_px[4]+(d_px[3]*image_width);
  filter_less[14] = -d_px[4]-(d_px[3]*image_width);
  filter_less[15] = d_px[4]-(d_px[3]*image_width);

  viscr_int * p_filter_add;
  viscr_int * p_filter_less;
  p_filter_add = &filter_add[0];
  p_filter_less = &filter_less[0];
 
  viscr_int u_start = p_eol_filter.filter_start_width; 
  viscr_int u_stop = p_eol_filter.filter_start_width + (p_eol_filter.filter_width*2); 
  viscr_int v_start = p_eol_filter.filter_start_height;
  viscr_int v_stop = p_eol_filter.filter_start_height + (p_eol_filter.filter_height*2); 
  viscr_int index_filter=0;
  viscr_int  index_image=0;
  for (viscr_int v=v_start; v<v_stop; v=v+p_eol_filter.filter_sampling_height)
  {
      for (viscr_int u=u_start; u<u_stop; u=u+p_eol_filter.filter_sampling_width)
      {
        viscr_int filter_sum = 0;
        index_image = (v*image_width)+u;
        p_eol_filter.filter[index_filter] = 0U;
        for (viscr_int index=0;index<filter_add_size; index++) 
        {
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 17.04.2012 reason: indexing by pointer faster */
          filter_sum = filter_sum + static_cast<viscr_int>(p_image.data[index_image+p_filter_add[index]]);
        }
        for (viscr_int index=0;index<filter_less_size; index++) 
        {
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 17.04.2012 reason: indexing by pointer faster */
          filter_sum = filter_sum - static_cast<viscr_int>(p_image.data[index_image+p_filter_less[index]]);
        }
        if (filter_sum<0)
        {
          filter_sum  = 0;
        }
        // ~CodeReview ~ID:2ec10afe42a46c423c5ec78f90eb6901 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
        filter_sum = filter_sum/(filter_add_size*16);
        p_eol_filter.filter[index_filter] = static_cast<viscr_uint8>(filter_sum);
        index_filter++;
      }
  }

#if (VISCR_EOL_DEBUG==1) // DEBUG 
  viscr_int8 numstr[256];
  sprintf(numstr,"Z:/OUT/viscr_eol_filter1.pgm");
  
	FILE * fo=fopen( numstr, "w");
	if( fo)
	{
		fprintf( fo, "P2\n%d %d\n255\n", p_eol_filter.filter_width, p_eol_filter.filter_height);
			const viscr_uint n=p_eol_filter.filter_width*p_eol_filter.filter_height;
		for( viscr_uint i=0; i<n; ++i)
      {fprintf( fo, "%d ", p_eol_filter.filter[i]);}
		fclose( fo);
    }
  // matlab vizualization with :
  // figure;surf(double(pgm_read('z:\OUT\viscr_eol_filter1.pgm')));

  sprintf(numstr,"Z:/OUT/image.pgm");
  
	fo=fopen( numstr, "w");
	if( fo)
	{
		fprintf( fo, "P2\n%d %d\n4095\n", p_image.size.u, p_image.size.v);

	const viscr_uint n=p_image.size.u*p_image.size.v;
		for( viscr_uint i=0; i<n; ++i)
      {fprintf( fo, "%d ", p_image.data[i]);}
		fclose( fo);
    }


#endif
}

/* **************************************************************************** 
Functionname : viscr_eol_findpointlist()                                  */ /*!  
Description  : 
@param		     filter,Width,Height
@return        as_PointList,sl_PointListSize
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
static viscr_int viscr_eol_findpointlist(   const viscr_uint8 filter[],
																						const viscr_int Width,
																						const viscr_int Height,
																						S_F_POINT as_PointList[],
																						viscr_int &sl_PointListSize, 
                                                                                        const viscr_int sl_MIN_WHITE_QUANTITY)
													
{
  //number of grey levels in the image
	static const viscr_int sl_NUMBER_OF_GREY_LEVELS = 256;
  //the maximum grey level value in the image
	static const viscr_uint8 ub_MAX_GREY_LEVEL_VALUE = 255U;
	//minumum pixels size of the object
	static const viscr_uint ul_MIN_REGION_SIZE = 4U;
  const viscr_int sl_SIZEOF_SL_POINT = static_cast<viscr_int>(sizeof(S_SL_POINT));
  const viscr_int sl_SIZEOF_INTERNAL_IMAGE_POINT = static_cast<viscr_int>(sizeof(S_INTERNAL_IMAGE_POINT));
// ~CodeReview ~ID:f5c7ab7af401a3d689657359f0629f43 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document dead code
// YME  static S_INTERNAL_IMAGE_POINT m_as_InternalPointList[sl_MAX_NO_OF_POINTS];
	//number of neighbours to check for finding a point
	static const viscr_int sl_NO_OF_NEIGHBOURS = 8;
	//array containing the neigbours pairs
	static const S_SL_POINT m_as_Neighbours[sl_NO_OF_NEIGHBOURS] 	= {  {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1} };


	viscr_int sl_Ret = 0;
	viscr_int sl_I;
  viscr_int  sl_J;
	viscr_int asl_Histogram[sl_NUMBER_OF_GREY_LEVELS];
	viscr_uint8 ub_Threshold = ub_MAX_GREY_LEVEL_VALUE;
	viscr_int sl_Sum = 0;
	
 // ~CodeReview ~ID:6a85ce536c57a2df2fa7c53890373ef5 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document dead code
	//const viscr_int sl_MIN_WHITE_QUANTITY = 36;//18

	//reset image point list actual size
	sl_PointListSize = 0;

	//check image buffer
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
	if ( 0 == filter)
	{
		sl_Ret = 1;//e_ERROR_INVALID_IMAGE_BUFFER;
  // ~CodeReview ~ID:7a185de6a6657d207f7443b3df46ac36 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
		goto FUNCTION_EXIT;
	}

	//reset the histogram
	for( sl_I = 0; sl_I < sl_NUMBER_OF_GREY_LEVELS; sl_I++)
	{
		asl_Histogram[sl_I] = 0;
	}

	//create the histogram
	//the index is the grey level and the value is the nr of pixels of this value
	for ( sl_I = 0; sl_I < Height; sl_I++ )
	{
		for ( sl_J = 0; sl_J < Width; sl_J++)
		{
			asl_Histogram[filter[(sl_I*Width) + sl_J]]++;
		}
	}
	
	//find threshold
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: While loop is always started. */
	while( (ub_Threshold > static_cast<viscr_uint8>(0)) && (sl_Sum < sl_MIN_WHITE_QUANTITY) )
	{
		sl_Sum += asl_Histogram[ub_Threshold];
		ub_Threshold--;
	}

 // ~CodeReview ~ID:45ec493144001314d6e83883d8e6a67e ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
	if(ub_Threshold == static_cast<viscr_uint8>(254))
	{
		sl_Ret = 2;//e_ERROR_TOO_MANY_WHITE_POINTS;
  // ~CodeReview ~ID:1048168d6073feb7ff7859a9108c9281 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
		goto FUNCTION_EXIT;
	}

	ub_Threshold++;

	const viscr_uint8 ub_USED = static_cast<viscr_uint8>(255);
	viscr_uint8 ub_Value;
	S_INTERNAL_IMAGE_POINT s_P;
	viscr_int sl_StackX;
  viscr_int sl_StackY;
	viscr_int sl_Last;

	//initialize the temporary image (for all the pixels which have the value 255
	//they are replaced by value 254)
	for ( sl_I = 0; sl_I < (Width*Height); sl_I++ )
	{
  // ~CodeReview ~ID:4d0b73819cb83df8ecaa7aca5ca4dd1d ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check valid filter values. */
		if ( static_cast<viscr_uint8>(255) != filter[sl_I] )
		{
			eol_filter1.m_aub_TempImage[sl_I] = filter[sl_I];
		}
		else
		{
   // ~CodeReview ~ID:88ed251ae538fb2d6612a5194df451f6 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
			eol_filter1.m_aub_TempImage[sl_I] = static_cast<viscr_uint8>(254);//never enter here; should be a really black-white image to enter
		}
	}

	//reset stack size
	viscr_int m_sl_ActualStackSize = 0;
	memset(&m_as_Stack[0],0, sl_MAX_NO_OF_POINTS*sl_SIZEOF_SL_POINT);

	//reset internal list actual size
	viscr_int m_sl_ActualInternalPointListSize = 0;
	memset (&m_as_InternalPointList[0], 0, sl_MAX_NO_OF_POINTS*sl_SIZEOF_INTERNAL_IMAGE_POINT);

	//search all the pixels above the treshold
	for ( sl_I = 1; sl_I < (Height-1); sl_I++ )
	{
		for ( sl_J = 1; sl_J < (Width-1); sl_J++)
		{
			ub_Value = eol_filter1.m_aub_TempImage[(sl_I*Width) + sl_J];
			
			if( (ub_Value > ub_Threshold) && (ub_Value != ub_USED) )
			{
				s_P.sl_X = sl_J;
				s_P.sl_Y = sl_I;
				s_P.ub_Max = ub_Value;
				s_P.ul_No = 1UL;
				
				//add the point in the list
        /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if point list size is less than maximum value. */
				if (m_sl_ActualInternalPointListSize < sl_MAX_NO_OF_POINTS)
				{
					m_as_InternalPointList[m_sl_ActualInternalPointListSize] = s_P;
					m_sl_ActualInternalPointListSize++;
				}
				else
				{
					sl_Ret = 4;//e_ERROR_TOO_MANY_POINTS;
          // ~CodeReview ~ID:b11940167bbd39e5ac877ebf6fb642f4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
					goto FUNCTION_EXIT;
				}
				
				//add in stack
				//this add is made in a for loop. At each step of the for loop the m_sl_ActualStackSize
				//is set to 0 by the while loop, so no need for stack overflow is needed
				m_as_Stack[m_sl_ActualStackSize].sl_X = sl_J;
				m_as_Stack[m_sl_ActualStackSize].sl_Y = sl_I;
				m_sl_ActualStackSize++;
				//mark it as used
				eol_filter1.m_aub_TempImage[(sl_I*Width) + sl_J] = ub_USED;

				while(m_sl_ActualStackSize > 0)
				{
					//take out last element from stack
					sl_StackX = m_as_Stack[m_sl_ActualStackSize-1].sl_X;
					sl_StackY = m_as_Stack[m_sl_ActualStackSize-1].sl_Y;
					m_sl_ActualStackSize--;

					//take the 8-neighbours and put then in the stack
					sl_Last = m_sl_ActualInternalPointListSize-1;
	
					for (viscr_int sl_Index = 0; sl_Index < sl_NO_OF_NEIGHBOURS; sl_Index++)
					{
						viscr_int sl_X = m_as_Neighbours[sl_Index].sl_X;
						viscr_int sl_Y = m_as_Neighbours[sl_Index].sl_Y;
						ub_Value = eol_filter1.m_aub_TempImage[((sl_StackY+sl_Y)*Width)+sl_StackX+sl_X];
						
						if( (ub_Value > ub_Threshold) && (ub_Value != ub_USED) )
						{
							//add in stack
              /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if stack size is less than maximum value. */
							if (m_sl_ActualStackSize < sl_MAX_NO_OF_POINTS)
							{
								m_as_Stack[m_sl_ActualStackSize].sl_X = sl_StackX + sl_X;
								m_as_Stack[m_sl_ActualStackSize].sl_Y = sl_StackY + sl_Y;
								m_sl_ActualStackSize++;
							}
							else
							{
								 sl_Ret = 6;//e_ERROR_TOO_MANY_POINTS;
         // ~CodeReview ~ID:4718f6b8ec7feec41252d2b862bc1f69 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
								 goto FUNCTION_EXIT;
							}
							m_as_InternalPointList[sl_Last].ul_No++;

							//compare with max
							//if one neighbour has a bigger value, then it becomes 
							//the new point representing the center of the pattern
							if(m_as_InternalPointList[sl_Last].ub_Max < ub_Value)
							{
								m_as_InternalPointList[sl_Last].sl_X = sl_StackX + sl_X;
								m_as_InternalPointList[sl_Last].sl_Y = sl_StackY + sl_Y;
								m_as_InternalPointList[sl_Last].ub_Max = ub_Value;
							}

							//mark it as used
							eol_filter1.m_aub_TempImage[((sl_StackY+sl_Y)*Width )+ sl_StackX + sl_X] = ub_USED;
						}
					}
				}
			}
		}
	}

	//make subpixeling of the obtained point list
	viscr_int sl_XMin;
  viscr_int sl_XMax;
	viscr_int sl_YMin;
  viscr_int sl_YMax;
	S_F_POINT s_RP;
	viscr_uint8 ub_Element;//used only for time and code optimisation

	for(sl_I = 0; sl_I < m_sl_ActualInternalPointListSize; sl_I++)
	{
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if object size is valid. */
		if(m_as_InternalPointList[sl_I].ul_No >= ul_MIN_REGION_SIZE)
		{
			s_P = m_as_InternalPointList[sl_I];
			ub_Element = filter[(s_P.sl_Y*Width) + s_P.sl_X];

			//search on Ox and Oy if there are other elements with the same value
			//if a region (conected pixels which have the same gray level) is found, due to the
			//filtering direction (from up to down and left to right), the x and y of the first point
			//found in the stack are the x min and y min
			sl_XMin = s_P.sl_X;
			sl_XMax = s_P.sl_X+1;
      /* <ln_offset:+1 COVERAGE reviewer name: Garcia Lucien date: 05.07.2012 reason: Only one max on the recordings. */
			while(filter[(s_P.sl_Y*Width) + sl_XMax] == ub_Element) 
			{
				sl_XMax++;
			}
			sl_XMax--;

			sl_YMin =s_P.sl_Y;
			sl_YMax =s_P.sl_Y+1;
      /* <ln_offset:+1 COVERAGE reviewer name: Garcia Lucien date: 05.07.2012 reason: Only one max on the recordings. */
			while(filter[(sl_YMax*Width) + s_P.sl_X] == ub_Element) 
			{
				sl_YMax++;
			}
			sl_YMax--;
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if neighbours are valid. */
			if(sl_XMin == sl_XMax)//left and right neighbour are different then the element itself
			{
        /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if thresholds are passed. */
				if((filter[(s_P.sl_Y*Width) + (s_P.sl_X-1)] > ub_Threshold) && (filter[(s_P.sl_Y*Width) + (s_P.sl_X+1)]>ub_Threshold))
				{
					s_RP.sl_X = static_cast<viscr_float>(s_P.sl_X) + rl32_GetSubPixel(filter[(s_P.sl_Y*Width) + (s_P.sl_X-1)],
															  filter[(s_P.sl_Y*Width) + s_P.sl_X],
															  filter[(s_P.sl_Y*Width) + (s_P.sl_X+1)]);
				}
				else
				{
					s_RP.sl_X = static_cast<viscr_float>(s_P.sl_X);//never enter here, because of precondition : nr of points >= ul_MIN_REGION_SIZE
				}
			}
			else
			{
				s_RP.sl_X = (static_cast<viscr_float>(sl_XMax) + static_cast<viscr_float>(sl_XMin))/2.0F;
			}

      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if neighbours are valid. */
			if(sl_YMin == sl_YMax)//up and down neighbour are different then the element itself
			{
        /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if thresholds are passed. */
				if((filter[((s_P.sl_Y-1)*Width) + s_P.sl_X]>ub_Threshold) && (filter[((s_P.sl_Y+1)*Width) + s_P.sl_X]>ub_Threshold))
				{
					s_RP.sl_Y = static_cast<viscr_float>(s_P.sl_Y) + rl32_GetSubPixel(filter[((s_P.sl_Y-1)*Width) + s_P.sl_X],
															 filter[(s_P.sl_Y*Width) + s_P.sl_X],
															 filter[((s_P.sl_Y+1)*Width) + s_P.sl_X]);
				}
				else
				{
					s_RP.sl_Y = static_cast<viscr_float>(s_P.sl_Y);//never enter here, because of precondition : nr of points >= ul_MIN_REGION_SIZE
				}
			}
			else
			{
				s_RP.sl_Y = (static_cast<viscr_float>(sl_YMax) + static_cast<viscr_float>(sl_YMin))/2.0F;
			}

			//these operations are insed a for loop. This loop has n steps that do not exceed the
			//maximum stack size. At each step sl_PointListSize is increased by 1, therefore
			//a check for stack overflow is redundant
      /* <ln_offset:+2 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if filter value exceeds minimum score. */
      /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Garcia Lucien date: 31.05.2012 reason: cannot modify macro function */
      		if (filter[(static_cast<viscr_int>(ROUND(s_RP.sl_Y))*Width) + static_cast<viscr_int>(ROUND(s_RP.sl_X))] > VISCR_EOL_FILTER1_MIN_SCORE)
      		{
			  as_PointList[sl_PointListSize] = s_RP;
			  sl_PointListSize++;
      		}
		}
	}

FUNCTION_EXIT:
	return sl_Ret;

}
/* **************************************************************************** 
Functionname : viscr_eol_filter1_init()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* <ln_offset:+1to+3 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_filter1_init( )
{
}

/* **************************************************************************** 
Functionname : viscr_eol_filter1_run()                                           */ /*!  
Description  : 
@param		     p_eol_mono_input
@return        p_eol_filter1_output
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
void viscr_eol_filter1_run(
    const viscr_eol_filter1_input * const p_eol_filter1_input,
    viscr_eol_filter1_output *  const p_eol_filter1_output)
{
  viscr_float temp_float_for_misra;
  const viscr_int sl_SIZEOF_INTERNAL_IMAGE_POINT = static_cast<viscr_int>(sizeof(S_INTERNAL_IMAGE_POINT));
  memset (&m_as_InternalPointList[0], 0, sl_MAX_NO_OF_POINTS*sl_SIZEOF_INTERNAL_IMAGE_POINT);

  p_eol_filter1_output->Errors = C_EOL_FILTER1_Errors::EOL_FILTER1_NO_ERROR;
  //////////////////////////////////////////////////////////////////////////////////////
  // PROCESS_2:STEP_2:Calculate ROI (here default configuration is used for the moment
  //////////////////////////////////////////////////////////////////////////////////////
  eol_filter1.filter_sampling_width = 2;
  eol_filter1.filter_sampling_height = 2;

  eol_filter1.filter_start_width = p_eol_filter1_input->filter_start_width;
  eol_filter1.filter_start_height = p_eol_filter1_input->filter_start_height;
  eol_filter1.filter_width = p_eol_filter1_input->filter_width/eol_filter1.filter_sampling_width;
  eol_filter1.filter_height = p_eol_filter1_input->filter_height/eol_filter1.filter_sampling_height;
  //////////////////////////////////////////////////////////////////////////////////////
  // 2 - PROCESS_2:STEP_3:Find rough pattern positions
  //////////////////////////////////////////////////////////////////////////////////////

  viscr_eol_run_filter1(p_eol_filter1_input->image,  eol_filter1,  p_eol_filter1_input->PatOutCircleDiameter,
  p_eol_filter1_input->PatInnerCircleDiameter,p_eol_filter1_input->f, p_eol_filter1_input->TargetDist);

  S_F_POINT as_PointList_Filter[10];
  viscr_int sl_PointListSize;
  viscr_int sl_MIN_WHITE_QUANTITY;
  viscr_int temp_int_for_misra;
  /* <ln_offset:1 MISRA Rule 5-0-7: reviewer name: Garcia Lucien date: 25.05.2012 reason: pixel position */
  temp_int_for_misra =  static_cast<viscr_int>(((((p_eol_filter1_input->PatInnerCircleDiameter)/2.0F)*p_eol_filter1_input->f)/p_eol_filter1_input->TargetDist)+0.5F);
  /* <ln_offset:+2 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Limit values if necessary. */
  // ~CodeReview ~ID:3ddf97093ad1e069e6834f609853136e ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
  if (temp_int_for_misra<3)
  {
    temp_int_for_misra = 3;
  }
  sl_MIN_WHITE_QUANTITY = (temp_int_for_misra*temp_int_for_misra)*2;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
  if (viscr_eol_findpointlist(&eol_filter1.filter[0],eol_filter1.filter_width,eol_filter1.filter_height ,&as_PointList_Filter[0], sl_PointListSize, sl_MIN_WHITE_QUANTITY) == 0)
  {
    /* <ln_offset:+2 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if pointlistsize has correct size. */
    // ~CodeReview ~ID:e6609f4f89828e600c6f14f7743eb67a ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
    if (sl_PointListSize == 2)
    {
      for (viscr_int i=0; i<sl_PointListSize; i++)
      {
        temp_float_for_misra = as_PointList_Filter[i].sl_X*static_cast<viscr_float>(eol_filter1.filter_sampling_width);
        p_eol_filter1_output->as_PointList[i].sl_X = static_cast<viscr_int>(temp_float_for_misra) + eol_filter1.filter_start_width;
        temp_float_for_misra = as_PointList_Filter[i].sl_Y*static_cast<viscr_float>(eol_filter1.filter_sampling_height);
        p_eol_filter1_output->as_PointList[i].sl_Y = static_cast<viscr_int>(temp_float_for_misra) + eol_filter1.filter_start_height;
      }
      p_eol_filter1_output->sl_PointListSize = sl_PointListSize;
    }
    /* <ln_offset:+1to+19 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Condition is covered, if point list is empty or invalid -> errors are reported. */
    else
    {
      if (sl_PointListSize == 0)
      {
        p_eol_filter1_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_NO_MARKERS);
      }
      else
      {
        // ~CodeReview ~ID:ca45ae544edc3dfdd03099186e528fd2 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Use meaningful defines instead of magic numbers
        if (sl_PointListSize < 2)
        {
          p_eol_filter1_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_NOT_ENOUGH_MARKERS);
        }
        else 
        {
          p_eol_filter1_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_TOO_MANY_MARKERS);
        }
      }
    }
  }
  else
  {
    p_eol_filter1_output->Errors = static_cast<viscr_uint>(C_SACErrors::i32_SAC_ERROR_EOL_UPDATE_TOO_MANY_MARKERS);
  }


#ifdef PC_SIM
#if (VISCR_EOL_DEBUG_PC_SIM)
  {
    SAC::EOL::CStereoCalibrationDebugData::SMonoData& data = SAC::EOL::CStereoCalibrationDebugData::instance()->monoData();
    std::memcpy(&data.filter1Input,    p_eol_filter1_input,  sizeof(data.filter1Input));
    std::memcpy(&data.filter1Output,   p_eol_filter1_output, sizeof(data.filter1Output));
    std::memcpy(&data.filter1Instance, &eol_filter1,         sizeof(data.filter1Instance));
    data.filter1valid = true;
  }
#endif
#endif
}

/* **************************************************************************** 
Functionname : viscr_eol_filer1_exit()                                           */ /*!  
Description  : 
@param		     -
@return        -
@pre           -
@post          -
@author        Garcia Lucien
**************************************************************************** */
/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Empty. Dead code. */
void viscr_eol_filer1_exit( )
{
 
}


