/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_vector.cpp  

  DESCRIPTION:    Vector library

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_vector.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:41CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:42CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.19 2014/02/20 13:46:14CET Sadran, Emal (uidw7976) 
  CHANGES:        reactived floating point version of the epipolar_objfun for test purposes
  CHANGES:        - Added comments -  uidw7976 [Feb 20, 2014 1:46:15 PM CET]
  CHANGES:        Change Package : 196075:4 http://mks-psad:7002/im/viewissue?selection=196075
  CHANGES:        Revision 1.18 2013/10/18 10:06:22CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - fixing SRoi pose by applying rectifying rotation onto the croi pose
  CHANGES:        --- Added comments ---  uidw0251 [Oct 18, 2013 10:06:22 AM CEST]
  CHANGES:        Change Package : 200304:1 http://mks-psad:7002/im/viewissue?selection=200304
  CHANGES:        Revision 1.17 2013/08/15 14:29:07CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:07 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.16 2013/03/15 19:14:54CET Ruland, Thomas (uidw0251) 
  CHANGES:        - first complete version of wrapper
  CHANGES:        --- Added comments ---  uidw0251 [Mar 15, 2013 7:14:55 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.15 2012/07/17 15:45:54CEST Garcia, Lucien (uid26778) 
  CHANGES:        pc lint
  CHANGES:        --- Added comments ---  uid26778 [Jul 17, 2012 3:45:54 PM CEST]
  CHANGES:        Change Package : 138467:2 http://mks-psad:7002/im/viewissue?selection=138467
  CHANGES:        Revision 1.14 2012/07/05 15:43:46CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add coverage tags
  CHANGES:        --- Added comments ---  uid26778 [Jul 5, 2012 3:43:46 PM CEST]
  CHANGES:        Change Package : 133274:1 http://mks-psad:7002/im/viewissue?selection=133274
  CHANGES:        Revision 1.13 2012/07/03 17:34:12CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 3, 2012 5:34:12 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.12 2012/07/02 14:46:02CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Modify priority of findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jul 2, 2012 2:46:02 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.11 2012/06/22 13:31:05CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 22, 2012 1:31:05 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.10 2012/04/19 15:18:56CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:18:56 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.9 2012/03/29 11:29:06CEST Garcia, Lucien (uid26778) 
  CHANGES:        Implement distance test and merge eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [Mar 29, 2012 11:29:07 AM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.8 2012/03/14 17:45:24CET Exner, Christian (uidt8578) 
  CHANGES:        - bugfix: when using <cmath> as interface one has to call fabs, sqrt et al. via std:: namespace!
  CHANGES:        --- Added comments ---  uidt8578 [Mar 14, 2012 5:45:24 PM CET]
  CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.7 2012/03/09 15:15:18CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Mar 9, 2012 3:15:18 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2012/02/24 16:07:10CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 24, 2012 4:07:10 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.5 2012/02/22 17:28:51CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:51 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.4 2011/10/04 09:50:07CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove PC lints warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 9:50:07 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273


**************************************************************************** */

#include <cmath>
#include <viscr_vector.hpp>

void
viscr_vec_zero( 
    viscr_vector & v)
{
  viscr_float* pfloat_for_misra = v.data;
  for( viscr_uint i=0U; i<v.length; ++i)
     {
	  *pfloat_for_misra = 0.0F;
      pfloat_for_misra++;
     }
}

void
viscr_vec_assign(
    viscr_vec3 & v,
    const viscr_float & c0,
    const viscr_float & c1,
    const viscr_float & c2)
{
  v.v.data[0] = c0;
  v.v.data[1] = c1;
  v.v.data[2] = c2;
}

void
viscr_vec_assign(
    viscr_vec2 & v,
    const viscr_float & c0,
    const viscr_float & c1)
{
  v.v.data[0] = c0;
  v.v.data[1] = c1;
}

void
viscr_vec_copy(
    viscr_vector & out,
    const viscr_vector & in)
{
  const viscr_float* pfloat_in_for_misra = in.data;
  viscr_float* pfloat_out_for_misra = out.data;
  assert( out.length==in.length);
  for( viscr_uint i=0U; i<out.length; ++i)
     {
      *pfloat_out_for_misra = *pfloat_in_for_misra;
      pfloat_in_for_misra++;
      pfloat_out_for_misra++;
     }
}

/* ~CodeReview ~ID:5e443d9008ca958391b525897abfc046 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
void
viscr_vec_copy_n(
    viscr_vector & out,
    const viscr_vector & in,
    const viscr_uint n)
{
  assert( n<=in.length);
  assert( n<=out.length);
  for( viscr_uint i=0U; i<n; ++i)
    {out.data[i]=in.data[i];}
}
#endif

void
viscr_vec_normalize(
    viscr_vector & v)
{
  viscr_float* pfloat_for_misra = v.data;
  viscr_uint n=v.length;
  viscr_float l=0.0F;
  for( viscr_uint i=0U; i<n; ++i)
  {
	  l+=(*pfloat_for_misra)*(*pfloat_for_misra);
    pfloat_for_misra++;
  }
  
  /* ~CodeReview ~ID:cd96c2769a52639a72fde3ca51edd051 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Magic number 1e-30 use define instead */
  /* ~CodeReview ~ID:0a62924fe4d8e12bb6d0c8354fb712ba ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Useless if: modify test condition for readability */
    /* <ln_offset:+1 COVERAGE reviewer name: Garcia Lucien date: 05.07.2012 reason: no null vector is normalized. */
  if( std::fabsf(l)<1e-30)
  {}
  else
  {
    l=static_cast<viscr_float>(std::sqrtf(l));
	pfloat_for_misra = v.data;
    for( viscr_uint i=0U; i<n; ++i)
      {
	   *pfloat_for_misra/=l;
       pfloat_for_misra++;
	  }
  }
  return;
}

/* ~CodeReview ~ID:f061a94ecd74f6cc36c4985b5cf4ea0e ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
viscr_float
viscr_vec_normalize_n(
    viscr_vector & v,
    const viscr_uint n)
{
  assert( n<=v.length);
  viscr_float l=0.0F;
  for( viscr_uint i=0U; i<n; ++i)
    {l+=v.data[i]*v.data[i];}
  l=sqrt(l);
  if( fabs(l)>1e-16)
  {
    for( viscr_uint i=0U; i<n; ++i)
      {v.data[i]/=l;}
  } 
  return l;
}
#endif
/* <ln_offset:+1to+11 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by condition in "levmar_update". */
viscr_float
viscr_vec_max(
    const viscr_vector & v)
{
  viscr_float res;
  viscr_uint index;

  viscr_vec_max(res, index, v);

  return res;
}

/* <ln_offset:+1to+11 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by "viscr_vec_max() (line 168)". */
void
viscr_vec_max(
    viscr_float & value,
    viscr_uint & index,
    const viscr_vector & v)
{
  const viscr_float* pfloat_for_misra = v.data;
  assert( v.length>=1U);
  viscr_uint n=v.length;
  value=*pfloat_for_misra;
  index=0U;
  for( viscr_uint i=1U; i<n; ++i)
  {
    pfloat_for_misra++;
    if( *pfloat_for_misra>=value) {
      value=*pfloat_for_misra;
      index=i;
    }
  }
}


viscr_float
viscr_vec_norm(
    const viscr_vector & v)
{
  const viscr_float* pfloat_for_misra = v.data;
  viscr_uint n=v.length;
  viscr_float l=0.0F;
  for( viscr_uint i=0U; i<n; ++i)
     {
	  l+=(*pfloat_for_misra)*(*pfloat_for_misra);
      pfloat_for_misra++;
     }
  return static_cast<viscr_float>(std::sqrt(l));
}


void
viscr_vec_sub(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b)
{
  const viscr_float* pfloat_a_for_misra = a.data;
  const viscr_float* pfloat_b_for_misra = b.data;
  viscr_float* pfloat_c_for_misra = c.data;
  assert( c.length==a.length);
  assert( c.length==b.length);
  viscr_uint n=a.length;
  for( viscr_uint i=0U; i<n; ++i)
     {
	  *pfloat_c_for_misra=*pfloat_a_for_misra-*pfloat_b_for_misra;
	  pfloat_a_for_misra++;
	  pfloat_b_for_misra++;
	  pfloat_c_for_misra++;
     }
}

/* ~CodeReview ~ID:9fb86fee28ff6c8578d8c68d4ca4c2ea ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
void
viscr_vec_sub_n(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n)
{
  assert( a.length>=n);
  assert( b.length>=n);
  assert( c.length>=n);
  for( viscr_uint i=0U; i<n; ++i)
    {c.data[i]=a.data[i]-b.data[i];}
}
#endif

/* ~CodeReview ~ID:72e194364c12b7c6bd36cda114c7c7b7 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
void
viscr_vec_add_n(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n)
{
  assert( a.length>=n);
  assert( b.length>=n);
  assert( c.length>=n);
  for( viscr_uint i=0U; i<n; ++i)
    {c.data[i]=a.data[i]+b.data[i];}
}
#endif

/* ~CodeReview ~ID:7910275163278515e778e30dc177c2ed ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
void
viscr_vec_sub(
    viscr_vector & a,
    const viscr_vector & b)
{
  assert( a.length==b.length);
  viscr_uint n=a.length;
  for( viscr_uint i=0U; i<n; ++i)
    {a.data[i]-=b.data[i];}
}
#endif

void
viscr_vec_add(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b)
{
  const viscr_float* pfloat_a_for_misra = a.data;
  const viscr_float* pfloat_b_for_misra = b.data;
  viscr_float* pfloat_c_for_misra = c.data;
  assert( c.length==a.length);
  assert( c.length==b.length);
  viscr_uint n=a.length;
  for( viscr_uint i=0U; i<n; ++i)
     {
	  *pfloat_c_for_misra=*pfloat_a_for_misra+*pfloat_b_for_misra;
	  pfloat_a_for_misra++;
	  pfloat_b_for_misra++;
	  pfloat_c_for_misra++;
     }
}


/* ~CodeReview ~ID:577b0487e8ee0f5f58a8e9155520c5c8 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
void
viscr_vec_add(
    viscr_vector & a,
    const viscr_vector & b)
{
  assert( a.length==b.length);
  viscr_uint n=a.length;
  for( viscr_uint i=0U; i<n; ++i)
    {a.data[i]+=b.data[i];}
}
#endif

viscr_float
viscr_vec_dot(
    const viscr_vector & a,
    const viscr_vector & b)
{
  assert( a.length==b.length);
  viscr_float s=0.0F;
  for( viscr_uint i=0U; i<a.length; ++i)
    {s+=a[i]*b[i];}
  return s;
}

#if 0 // CODE NOT USED
viscr_float
viscr_vec_dot_n(
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n)
{
  assert( a.length>=n);
  assert( b.length>=n);
  viscr_float s=0.0F;
  for( viscr_uint i=0U; i<n; ++i)
    {s+=a[i]*b[i];}
  return s;
}
void
viscr_vec_div_scalar(
    viscr_vector & a,
    const viscr_float b)
{
  for( viscr_uint i=0U; i<a.length; ++i)
    {a[i]/=b;}
}

void
viscr_vec_div_scalar(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_float b)
{
  assert(a.length == c.length);
  for( viscr_uint i=0U; i<a.length; ++i)
    {c[i]=a[i]/b;}
}
#endif


void
viscr_vec_mult_scalar(
    viscr_vector & a,
    const viscr_float b)
{
  for( viscr_uint i=0U; i<a.length; ++i)
    {a[i]*=b;}
}


void
viscr_vec_mult_scalar(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_float b)
{
  assert(a.length == c.length);

  for( viscr_uint i=0U; i<a.length; ++i)
    {c[i]=a[i]*b;}
}

/* <ln_offset:+1to+11 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is currently not used. */
void
viscr_vec_negate(
    viscr_vector & a)
{
  viscr_float temp_float_for_misra;
  for( viscr_uint i=0U; i<a.length; ++i)
    { 
      temp_float_for_misra = a[i];
      a[i]=-temp_float_for_misra;
  }
}



/* ~CodeReview ~ID:2b3c0fb1035aebbd933d3725abbaee0a ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
void
viscr_vec_cross(
    viscr_vec3 & c,
    const viscr_vec3 & a,
    const viscr_vec3 & b)
{
  c.data[0]= (a.data[1]*b.data[2])-(a.data[2]*b.data[1]);
  c.data[1]=-(a.data[0]*b.data[2])+(a.data[2]*b.data[0]);
  c.data[2]= (a.data[0]*b.data[1])-(a.data[1]*b.data[0]);
}

void
viscr_vec_homogenize(
	viscr_vector & b,
	const viscr_vector & a)
{
	assert(b.length == (a.length + 1U));

  for( viscr_uint i=0U; i<a.length; ++i)
    {b[i]=a[i];}
  b[a.length] = 1U;
}

void
viscr_vec_dehomogenize(
	viscr_vector & b,
	const viscr_vector & a)
{
	assert(b.length == (a.length - 1U));

  for( viscr_uint i=0U; i<b.length; ++i)
    {b[i]=a[i]/a[b.length];}
}
#endif


/* ~CodeReview ~ID:a75cd9b9d1f34053667311b97d5d32bd ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
viscr_float
viscr_vec_dist2_n(
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n)
{
  assert( a.length>=n);
  assert( b.length>=n);
  viscr_float dist=0.0F;
  for( viscr_uint i=0U; i<n; ++i)
  {
    viscr_float d = a.data[i]-b.data[i];
    dist += d*d;
  }

  return dist;
}
#endif

/* ~CodeReview ~ID:2ac3f853d8cb912a225e63282a7565a3 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
viscr_float
viscr_vec2_cross_z(
    const viscr_vec2 & a,
    const viscr_vec2 & b)
{
  return (a.data[0]*b.data[1])-(a.data[1]*b.data[0]);
}

void
viscr_vec_on_line( 
    viscr_vector & pt,
    const viscr_vector & start,
    const viscr_vector & dir,
    const viscr_float offs)
{
  assert( pt.length==start.length);
  assert( pt.length==dir.length);
  for( viscr_uint i=0U; i<pt.length; ++i)
    {pt.data[i]=start.data[i]+(dir.data[i]*offs);}
}
#endif
