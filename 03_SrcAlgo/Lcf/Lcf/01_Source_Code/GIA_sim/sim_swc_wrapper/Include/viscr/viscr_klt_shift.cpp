/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_klt_shift.cpp 

  DESCRIPTION:    Subpixel feature correspondences

  AUTHOR:         L. GARCIA

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_klt_shift.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:29CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:16CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.14 2012/08/21 13:58:14CEST Lugez, Boris (uidt2765) 
  CHANGES:        -> First disparity refinement implementation
  CHANGES:        - Added comments -  uidt2765 [Aug 21, 2012 1:58:16 PM CEST]
  CHANGES:        Change Package : 156068:1 http://mks-psad:7002/im/viewissue?selection=156068
  CHANGES:        Revision 1.13 2012/07/13 10:46:29CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 10:46:29 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.12 2012/07/04 16:50:51CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 4, 2012 4:50:52 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/07/03 17:44:32CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jul 3, 2012 5:44:32 PM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.10 2012/04/19 15:19:01CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:19:01 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.9 2012/04/03 13:12:57CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning correction : bitexactness done + mts simulation
  CHANGES:        --- Added comments ---  uid26778 [Apr 3, 2012 1:12:57 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.8 2012/02/22 17:28:52CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:52 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.7 2011/11/16 19:43:05CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Nov 16, 2011 7:43:05 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2011/10/04 08:50:13CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 8:50:13 AM CEST]
  CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.5 2011/08/26 13:31:11CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Check if it is a corner before making a klt shift
  CHANGES:        --- Added comments ---  uid26778 [Aug 26, 2011 1:31:11 PM CEST]
  CHANGES:        Change Package : 76623:1 http://mks-psad:7002/im/viewissue?selection=76623
  CHANGES:        Revision 1.4 2011/06/17 13:34:37CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add mean calculation on whole window instead of center only (should be more accurate)
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:34:38 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298



**************************************************************************** */



// ~CodeReview ~ID:75bd52c214646d606c68d1bf24b9c856 ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
//#include <cmath>
#include <viscr_klt_shift.hpp>
#include <viscr_matrix.hpp>
// ~CodeReview ~ID:7b03a4e6d9a77b0ec0dd9612902f01ac ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
//#include <viscr_vector.hpp>

// ~CodeReviewBegin ~ID:33d5a84d5cc9a69ff571020c2de79463 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error (Unused .h files)
#include <viscr_lms.hpp>
#include <viscr_solve.hpp>
#include <viscr_defs.h>
// ~CodeReviewEnd   ~ID:33d5a84d5cc9a69ff571020c2de79463
#include <viscr_corner_check.hpp>

/// Check if the centre pixel coordinate is ok for extracting the whole
/// window.
static viscr_bool
coordinate_ok(
    const viscr_image & img,
    const viscr_coord u,
    const viscr_coord v,
    const viscr_coord rad)
{
  viscr_bool result = viscr_true;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Parameter check. */
  if( (u<(rad+1)) || (v<(rad+1)))
    {result = viscr_false;}
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Parameter check. */
  if( ((u+rad)>=static_cast<viscr_coord>(img.size.u)) || ((v+rad)>=static_cast<viscr_coord>(img.size.v)))
    {result = viscr_false;}
  return result;
}

const viscr_int64 FP_BASE = 1024;

// ~CodeReviewBegin ~ID:149a1617677104fcd5c7d25a74111c61 ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
#if 0 // CODE NOT USED
viscr_bool
viscr_klt_shift(
    viscr_float & su,
    viscr_float & sv,
    const viscr_image & k0, 
    viscr_coord u0,
    viscr_coord v0,
    const viscr_image & k1, 
    viscr_coord u1,
    viscr_coord v1,
    viscr_uint rad,
    viscr_pixel min_grey,
    viscr_pixel max_grey,
    viscr_pixel_accu * dy
    )
{
  // Check if we can correctly perform the operation on both images.
  if( !coordinate_ok( k0, u0, v0, rad) ||
      !coordinate_ok( k1, u1, v1, rad))
    {return viscr_false;}

  // Read the value of the window centres to approximate the mean.
  // Making the window mean free gives a better conditioned system of
  // equations.
  viscr_pixel_accu mean1=viscr_image_getPixel( k0, u0, v0);
  viscr_pixel_accu mean2=viscr_image_getPixel( k1, u1, v1);

  // Pointers to traverse images
  const viscr_pixel * t0=viscr_image_get_pointer( k0, (u0-rad), ((v0-rad)-1));
  const viscr_pixel * t1=viscr_image_get_pointer( k1, (u1-rad), ((v1-rad)-1));

  // Read the first line into the buffer
  viscr_uint n=(2*rad)+1;
  for( viscr_uint i=0; i<n; ++i)
  {
    viscr_pixel_accu p1=*t0;
    viscr_pixel_accu p2=*t1;

    if( p1<min_grey || p1>max_grey ||
        p2<min_grey || p2>max_grey)
      {return viscr_false;}

    p1-=mean1;
    p2-=mean2;

    dy[i]=(p1+p2)/2;

    ++t0;
    ++t1;
  }

  // Put the pointers to the next row
  t0+=k0.size.u-n;
  t1+=k1.size.u-n;

  // Iterate over the window and build the system of equations.
  viscr_mat22 L;
  viscr_mat22 AtA;
  viscr_vec2 Atb;
  viscr_vec2 row;
  viscr_pixel_accu dx;

  viscr_mat_zero( AtA.m);
  viscr_vec_zero( Atb.v);
          
  for( viscr_uint r=0; r<n; ++r)
  {
    viscr_pixel_accu p1=t0[-1];
    viscr_pixel_accu p2=t1[-1];

    if( (p1<min_grey) || (p1>max_grey) ||
        (p2<min_grey) || (p2>max_grey))
      {return viscr_false;}

    p1-=mean1;
    p2-=mean2;

    dx=(p1+p2)/2;

    for( viscr_uint c=0; c<n; ++c)
    {
      viscr_pixel_accu p1=*t0;
      viscr_pixel_accu p2=*t1;

      if( (p1<min_grey) || (p1>max_grey) ||
          (p2<min_grey) || (p2>max_grey))
        {return viscr_false;}

      p1-=mean1;
      p2-=mean2;

      viscr_pixel_accu g=(p1+p2)/2;

      row.data[0]=viscr_float(g-dx);
      row.data[1]=viscr_float(g-dy[c]);

      viscr_lms_addRow( AtA.m, Atb.v, row.v, viscr_float(p1-p2));

      dx=g;
      dy[c]=g;
      ++t0;
      ++t1;
    }
    t0+=k0.size.u-n;
    t1+=k1.size.u-n;
  }

  // Check if condition number is ok
  viscr_float p=-AtA.m(0,0)-AtA.m(1,1);
  viscr_float q=(AtA.m(0,0)*AtA.m(1,1))-(AtA.m(0,1)*AtA.m(1,0));

  viscr_float D=((p*p)/4.0F)-q;
  if( D<0.0F)
    {return viscr_false;}

  /* This test is redundant! D<0.0 is more strict
  viscr_float l1=p/2.0f+sqrt(D);
  viscr_float l2=p/2.0f-sqrt(D);

  // D>=0 -> l2<=l1
  viscr_float rcond=l2/l1;
  if( rcond<0.875f)
    return viscr_false;
  */

  // Solve the system of equations
  if( !viscr_compute_cholesky( L.m, AtA.m))
    {return viscr_false;}
  if( !viscr_solve_cholesky( row.v, L.m, Atb.v))
    {return viscr_false;}
  su=row.data[0];
  sv=row.data[1];

  return viscr_true;
}
#endif
// ~CodeReviewEnd   ~ID:149a1617677104fcd5c7d25a74111c61

viscr_bool
viscr_klt_shift_fp(
    viscr_float & su,
    viscr_float & sv,
    const viscr_image & k0, 
    const viscr_coord u0,
    const viscr_coord v0,
    const viscr_image & k1, 
    const viscr_coord u1,
    const viscr_coord v1,
    const viscr_uint rad,
    const viscr_pixel min_grey,
    const viscr_pixel max_grey,
    viscr_pixel_accu * const dy,
    const viscr_bool use_cornercheck
    )
{
  viscr_bool result;

  // Check if we can correctly perform the operation on both images.
  /* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Check if parameters meet limitations. */
  if( (coordinate_ok( k0, u0, v0, static_cast<viscr_coord>(rad))==viscr_false) ||
      (coordinate_ok( k1, u1, v1, static_cast<viscr_coord>(rad))==viscr_false) ||
      ((use_cornercheck==viscr_true)&&(viscr_corner_check(k0,u0,v0)==viscr_false))
      )
    {
	  result = viscr_false;
   // ~CodeReview ~ID:33d7d9fce690d55ec7ca119606f4d271 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	  goto FUNCTION_EXIT;
    }

  // Read the value of the window centres to approximate the mean.
  // Making the window mean free gives a better conditioned system of
  // equations.
#if (VISCR_KLT_SHIFT_MEAN == 0)
  viscr_pixel_accu mean1=static_cast<viscr_pixel_accu>(viscr_image_getPixel( k0, u0, v0));
  viscr_pixel_accu mean2=static_cast<viscr_pixel_accu>(viscr_image_getPixel( k1, u1, v1));
#endif

  // Pointers to traverse images
  const viscr_pixel * t0=viscr_image_get_pointer( k0, u0-static_cast<viscr_coord>(rad), (v0-static_cast<viscr_coord>(rad))-1);
  const viscr_pixel * t1=viscr_image_get_pointer( k1, u1-static_cast<viscr_coord>(rad), (v1-static_cast<viscr_coord>(rad))-1);

  // Read the first line into the buffer
  viscr_uint n=(2U*rad)+1U;

#if (VISCR_KLT_SHIFT_MEAN == 1)
  // mean calculation
    viscr_pixel_accu mean1 = 0;
    viscr_pixel_accu mean2 = 0;
    for( viscr_int i=-rad; i<=rad; i++)
    {
      for( viscr_int j=-rad; j<=rad; j++)
      {
        mean1+=viscr_image_getPixel( k0, u0+i, v0+j);
        mean2+=viscr_image_getPixel( k1, u1+i, v1+j);
      }
    }
    mean1 = mean1 / (n*n);
    mean2 = mean2 / (n*n);
#endif

  viscr_pixel_accu* pdy_for_misra = dy;

  for( viscr_uint i=0U; i<n; ++i)
  {
    viscr_pixel_accu p1=static_cast<viscr_pixel_accu>(*t0);
    viscr_pixel_accu p2=static_cast<viscr_pixel_accu>(*t1);

    /* <ln_offset:+2 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
    if( (p1<static_cast<viscr_pixel_accu>(min_grey)) || (p1>static_cast<viscr_pixel_accu>(max_grey)) ||
        (p2<static_cast<viscr_pixel_accu>(min_grey)) || (p2>static_cast<viscr_pixel_accu>(max_grey)))
      {
	   result = viscr_false;
    // ~CodeReview ~ID:09d70f774ee208c2ce0e31a7e1a0545a ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	   goto FUNCTION_EXIT;
      }

    p1-=mean1;
    p2-=mean2;

    *pdy_for_misra=(p1+p2)/2;

	pdy_for_misra++;
    ++t0;
    ++t1;
  }

  // Put the pointers to the next row
  /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 08.03.2012 reason: indexing by pointer faster */
  /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 08.03.2012 reason: indexing by pointer faster */
  t0+=k0.size.u-static_cast<viscr_int>(n);
  t1+=k1.size.u-static_cast<viscr_int>(n);

  // Iterate over the window and build the system of equations.
  viscr_int32 AtA[2][2];
  viscr_int32 Atb[2];
  viscr_int32 row[2];
  viscr_pixel_accu dx;

  for( viscr_uint r=0U; r<2U; ++r)
  {
    Atb[r]=0;
    for( viscr_uint c=0U; c<2U; ++c)
	{ AtA[r][c]=0; }
  }

  for( viscr_uint r=0U; r<n; ++r)
  {
	t0--;
	t1--;
    viscr_pixel_accu p1=static_cast<viscr_pixel_accu>(*t0);
    viscr_pixel_accu p2=static_cast<viscr_pixel_accu>(*t1);
	t0++;
	t1++;

    /* <ln_offset:+1to+2 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Check if parameters meet limitations. */
    if( (p1<static_cast<viscr_pixel_accu>(min_grey)) || (p1>static_cast<viscr_pixel_accu>(max_grey)) ||
        (p2<static_cast<viscr_pixel_accu>(min_grey)) || (p2>static_cast<viscr_pixel_accu>(max_grey)))
      {
	   result = viscr_false;
    // ~CodeReview ~ID:49cab8928fa5c504215d0d485fcb2376 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	   goto FUNCTION_EXIT;
      }
    p1-=mean1;
    p2-=mean2;

    dx=(p1+p2)/2;

	pdy_for_misra = dy;
    for( viscr_uint c=0U; c<n; ++c)
    {
      viscr_pixel_accu p3=static_cast<viscr_pixel_accu>(*t0);
      viscr_pixel_accu p4=static_cast<viscr_pixel_accu>(*t1);

      /* <ln_offset:+2 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
      if( (p3<static_cast<viscr_pixel_accu>(min_grey)) || (p3>static_cast<viscr_pixel_accu>(max_grey)) ||
          (p4<static_cast<viscr_pixel_accu>(min_grey)) || (p4>static_cast<viscr_pixel_accu>(max_grey)))
        {
	      result = viscr_false;
      // ~CodeReview ~ID:474ca42829c2c610f1f8523efd9b37d4 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	     goto FUNCTION_EXIT;
        }

      p3-=mean1;
      p4-=mean2;

      viscr_pixel_accu g=(p3+p4)/2;

      row[0]=g-dx;
      row[1]=g-*pdy_for_misra;

      viscr_pixel_accu e=p3-p4;

      // AtA += row' * row
      // Atb += row * e
      // TODO: A[0][1]=A[1][0] -> do not compute both
      // ~CodeReviewBegin ~ID:f728dc3f0c7939691140037081de01b1 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:3 ~Comment:Consider using a define for array dimensions
      for( viscr_uint r2=0U; r2<2U; ++r2)
      {
        Atb[r2]+=row[r2]*e;
        for( viscr_uint c2=0U; c2<2U; ++c2)
		   { AtA[r2][c2]+=row[r2]*row[c2]; }
      }

      // ~CodeReviewEnd   ~ID:f728dc3f0c7939691140037081de01b1
      dx=g;
      *pdy_for_misra=g;
      pdy_for_misra++;
      ++t0;
      ++t1;
    }
    /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 08.03.2012 reason: indexing by pointer faster */
    /* <ln_offset:2 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 08.03.2012 reason: indexing by pointer faster */
    t0+=k0.size.u-static_cast<viscr_int>(n);
    t1+=k1.size.u-static_cast<viscr_int>(n);
  }

  // Check if condition number is ok
  viscr_int64 p=-static_cast<viscr_int64>(AtA[0][0])-static_cast<viscr_int64>(AtA[1][1]);
  viscr_int64 q=(viscr_int64(AtA[0][0])*viscr_int64(AtA[1][1]))-(viscr_int64(AtA[0][1])*viscr_int64(AtA[1][0]));

// ~CodeReviewBegin ~ID:b8122df68794693b4a42290b43e8dfa0 ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
// ~CodeReviewBegin ~ID:d85819d58c96ce1a5fcfcbbcbfbca2d8 ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
#if 0
  // Derivation of fixed threshold
  viscr_float D=p*p/4.0F-q;
  if( D<0.0F)
    return viscr_false;

  if( p*p/4.0F-q<0.0F)
  if( p*p/4.0F<q)
  if( p*p<q*4.0F)
#endif
// ~CodeReviewEnd   ~ID:d85819d58c96ce1a5fcfcbbcbfbca2d8
  // ~CodeReviewBegin ~ID:6c1c95995ea2837d7d8ed1f31a9f8626 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:3 ~Comment:Use define for magic number 4
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
  if( (p*p)<(q*4))
    {
  // ~CodeReviewEnd   ~ID:6c1c95995ea2837d7d8ed1f31a9f8626
	 result = viscr_false;
  // ~CodeReview ~ID:6fc6ca48d15dcc8bf3c454c05b981ef5 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	 goto FUNCTION_EXIT;
    }

// ~CodeReviewBegin ~ID:685525dddc721a6692d28c587a935149 ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
#if 0
  // Derivation of fixed threshold

  // Make fixpoint if possible
  viscr_float D=p*p/4.0F-q;

  // D>=0 -> l2<=l1
  assert( D>=0.0F);

  viscr_float l1=p/2.0F+sqrt(D);
  viscr_float l2=p/2.0F-sqrt(D);
  viscr_float rcond=l2/l1;

  const viscr_float thresh=0.875;
  const viscr_float thresh1=1.0F-thresh;
  const viscr_float thresh2=1.0+2.0F*thresh;
  const viscr_float thresh1s=thresh1*thresh1;
  const viscr_float thresh2s=thresh2*thresh2;
  if( rcond<thresh)
    return viscr_false;
  if( (p/2.0F-sqrt(D))/(p/2.0F+sqrt(D))<thresh)

      assert p/2+sqrt(D)>0


  if( (p/2.0F-sqrt(D))<thresh*(p/2.0F+sqrt(D)))
  if( p/2.0F<thresh*(p/2.0F+sqrt(D))+sqrt(D))
  if( p/2.0F<thresh*p/2.0F+thresh*sqrt(D)+sqrt(D))
  if( p<thresh*p+2.0F*thresh*sqrt(D)+sqrt(D))
  if( p-thresh*p<2.0F*thresh*sqrt(D)+sqrt(D))
  if( (1.0-thresh)*p<(1.0F+2.0F*thresh)*sqrt(D))
  if( thresh1*p<thresh2*sqrt(D))
  if( thresh1s*p*p<thresh2s*D)
  if( thresh1s*p*p<thresh2s*(p*p/4.0F-q))
  if( thresh1s*p*p<thresh2s*p*p/4.0F-thresh2s*q)
  if( (thresh2s-4.0*thresh1s)*p*p>thresh2s*4.0*q)
  if( 7.5*p*p>30.25*q)
  if( 30*p*p<121*q)
    return viscr_false;
#endif
// ~CodeReviewEnd   ~ID:685525dddc721a6692d28c587a935149

  // Solve the system of equations AtA * [su;sv] = Atb
  {
    viscr_int64 a=AtA[0][0];
    viscr_int64 b=AtA[0][1];
    viscr_int64 c=Atb[0];
    viscr_int64 d=AtA[1][0];
    viscr_int64 e=AtA[1][1];
    viscr_int64 f=Atb[1];

    viscr_int64 ae_db=-(a*e)+(d*b);
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Error check. */
    if( ae_db==0)
      {
	   result = viscr_false;
    // ~CodeReview ~ID:f6afe460da60b4557c6ecb9de3bc8963 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	   goto FUNCTION_EXIT;
      }
    if( d==0)
      {
	   result = viscr_false;
    // ~CodeReview ~ID:36bd7ac36c6ea5c7bb7079aee380cfb0 ~Reviewer:Lint error 801 (use of goto is deprecated) not commented ~Date:03.07.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
	   goto FUNCTION_EXIT;
      }
    viscr_int64 dc_af=(d*c)-(a*f);
    // TODO: Give output in fix point too

    viscr_int64 temp_int_for_misra = (FP_BASE*((f*ae_db)-(e*dc_af)))/(d*ae_db);
	su=static_cast<viscr_float>(temp_int_for_misra)/static_cast<viscr_float>(FP_BASE);
// ~CodeReview ~ID:50b8a6259c706a777739d81045ef714b ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
//	su=viscr_float((FP_BASE*( (f*ae_db)-(e*dc_af)))/(d*ae_db))/FP_BASE;


    temp_int_for_misra = (FP_BASE*dc_af)/ae_db;
    sv=viscr_float(temp_int_for_misra)/viscr_float(FP_BASE);
// ~CodeReview ~ID:df2bf0cdaf81d982e3009be58e35ee8e ~Reviewer:CW01\uidk7517 ~Date:03.07.2012 ~Priority:3 ~Comment:Remove or comment dead code
//    sv=viscr_float((FP_BASE*dc_af)/ae_db)/FP_BASE;


  }
  result = viscr_true;

FUNCTION_EXIT:
  return result;
}
