/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_vector.hpp  

  DESCRIPTION:    Vector library

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_vector.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:41CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:43CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.16 2014/03/06 11:35:30CET Ruland, Thomas (uidw0251) 
  CHANGES:        Fixed templating mistakes
  CHANGES:        - Added comments -  uidw0251 [Mar 6, 2014 11:35:30 AM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.15 2014/02/28 10:19:41CET Ruland, Thomas (uidw0251) 
  CHANGES:        - New optimization framework (still using floating point objective)
  CHANGES:        - Single correspondence OdoYAC test framework
  CHANGES:        --- Added comments ---  uidw0251 [Feb 28, 2014 10:19:41 AM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.14 2014/02/20 13:46:16CET Sadran-EXT, Emal (uidw7976) 
  CHANGES:        reactived floating point version of the epipolar_objfun for test purposes
  CHANGES:        --- Added comments ---  uidw7976 [Feb 20, 2014 1:46:17 PM CET]
  CHANGES:        Change Package : 196075:4 http://mks-psad:7002/im/viewissue?selection=196075
  CHANGES:        Revision 1.13 2013/10/18 10:06:25CEST Ruland, Thomas (uidw0251) 
  CHANGES:        - fixing SRoi pose by applying rectifying rotation onto the croi pose
  CHANGES:        --- Added comments ---  uidw0251 [Oct 18, 2013 10:06:25 AM CEST]
  CHANGES:        Change Package : 200304:1 http://mks-psad:7002/im/viewissue?selection=200304
  CHANGES:        Revision 1.12 2013/03/15 19:14:56CET Ruland, Thomas (uidw0251) 
  CHANGES:        - first complete version of wrapper
  CHANGES:        --- Added comments ---  uidw0251 [Mar 15, 2013 7:14:56 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.11 2012/07/24 09:02:08CEST Behrens, Alexander (uidv2823) 
  CHANGES:        merged coverage tags and misra comments from branch to trunk
  CHANGES:        --- Added comments ---  uidv2823 [Jul 24, 2012 9:02:08 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.10 2012/06/22 13:31:06CEST Malot-EXT, Frederic (uidv0048) 
  CHANGES:        Add findings from code review
  CHANGES:        --- Added comments ---  uidv0048 [Jun 22, 2012 1:31:06 PM CEST]
  CHANGES:        Change Package : 130129:1 http://mks-psad:7002/im/viewissue?selection=130129
  CHANGES:        Revision 1.9 2012/03/29 11:29:07CEST Garcia, Lucien (uid26778) 
  CHANGES:        Implement distance test and merge eol calibration function
  CHANGES:        --- Added comments ---  uid26778 [Mar 29, 2012 11:29:07 AM CEST]
  CHANGES:        Change Package : 94275:2 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.8 2012/02/24 16:07:10CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 24, 2012 4:07:10 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.7 2012/02/22 17:28:52CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:52 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2012/01/19 14:22:27CET Garcia, Lucien (uid26778) 
  CHANGES:        First integration of stereo EOL calibration
  CHANGES:        --- Added comments ---  uid26778 [Jan 19, 2012 2:22:28 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.5 2011/10/04 09:50:07CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove PC lints warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 9:50:07 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273


**************************************************************************** */

#ifndef _viscr_vector_hpp_
#define _viscr_vector_hpp_

#include <cassert>
#include <cstdlib>
#include <viscr_types.hpp>

#include <glob_type.h>

/** @name Vectors
 * In order to avoid templates, fixed size vectors are generated by
 * aggregation: The data is stored as an array member of a struct and the
 * generic vector points to this data.
 */
/*@{*/

/// Generic vector. Cannot change its number of elements.
// {{{
struct viscr_vector
{
  /// Number of elements in vector.
  viscr_uint length;


  /// Pointer to the data.
  viscr_float * data;


  /// Default constructor to illegal vector.
  /* <ln_offset:+1to+3 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Default constructor to illegal vector. */
  viscr_vector():
    length(0),
    data(NULL) { }


  /// Normal constructor for aggregation
  viscr_vector( viscr_uint l, viscr_float * d):
    length( l),
    data( d) { }

/* <ln_offset:+1to+4 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Function has no callers. Dead code. */
  void setStorage( viscr_uint l, viscr_float * d) {
    length = l;
    data = d;
  }
  /// Read-access
  viscr_float operator[]( viscr_uint i) const
  {
    assert( i<length);
    return data[i];
  }

  /// Write access
  viscr_float & operator[]( viscr_uint i)
  {
    assert( i<length);
    return data[i];
  }

  /** @name Prohibit automatic copy operations. */
  /*@{*/
  private:
  viscr_vector( const viscr_vector &);
  viscr_vector & operator=( const viscr_vector &);
  /*@}*/
};
/*}}}*/


/// Set all elements to zero
extern void
viscr_vec_zero( 
    viscr_vector & v);


/// Copy the elements of a vector
extern void
viscr_vec_copy(
    viscr_vector & out,
    const viscr_vector & in);

/* ~CodeReview ~ID:07ca676ccf8853aaded923b97c9457b8 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Copy the first n elements of a vector
extern void
viscr_vec_copy_n(
    viscr_vector & out,
    const viscr_vector & in,
    const viscr_uint n);
#endif

/// Normalise the vector to unit length in place.
extern void
viscr_vec_normalize(
    viscr_vector & v);

/* ~CodeReview ~ID:b2287072e2667127d7075c05ea3411cf ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/** Normalise the first n dimensions of vector to unit length in place, return
 * the length.  */
extern viscr_float
viscr_vec_normalize_n(
    viscr_vector & v,
    const viscr_uint n);
#endif
/// Find the maximal element
extern viscr_float
viscr_vec_max(
    const viscr_vector & v);


/// Compute the L2 norm of the vector
extern viscr_float
viscr_vec_norm(
    const viscr_vector & v);

/* ~CodeReview ~ID:3b580e690c9f95b9a2b9456584cedd01 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Compute the squared L2 distance between the two vectors, do only for the first n dims
extern viscr_float
viscr_vec_dist2_n(
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n);
#endif

/// Compute element-wise c=a-b
extern void
viscr_vec_sub(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b);

/* ~CodeReview ~ID:1591b167e1a53e48cc19139b1168599b ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Compute element-wise c=a-b, do only for the first n dims
extern void
viscr_vec_sub_n(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n);
#endif

/* ~CodeReview ~ID:c4b2ebc322ac3eb985d48224b0a91207 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Compute element-wise inplace a-=b
extern void
viscr_vec_sub(
    viscr_vector & a,
    const viscr_vector & b);
#endif

/// Compute element-wise c=a+b
extern void
viscr_vec_add(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b);

/* ~CodeReview ~ID:b66687f6e88ee2e5d7f43ed94962cd7d ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Compute element-wise inplace a+=b
extern void
viscr_vec_add(
    viscr_vector & a,
    const viscr_vector & b);
#endif

/* ~CodeReview ~ID:b8bfc8788586e8df2149e9498d42c0df ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Compute element-wise c=a+b, do only for the first n dims
extern void
viscr_vec_add_n(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n);
#endif

/* ~CodeReview ~ID:0ab9e085d223b23433db29f06b46627b ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
//#if 0 // CODE NOT USED
/// Compute scalar product
extern viscr_float
viscr_vec_dot(
    const viscr_vector & a,
    const viscr_vector & b);

#if 0 // CODE NOT USED
/// Compute scalar product, do only for the first n dims
extern viscr_float
viscr_vec_dot_n(
    const viscr_vector & a,
    const viscr_vector & b,
    const viscr_uint n);

/// Element-wise in-place division a/=b
extern void
viscr_vec_div_scalar(
    viscr_vector & a,
    const viscr_float b);


/// Element-wise division c=a/b
extern void
viscr_vec_div_scalar(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_float b);
#endif


/// Element-wise in-place multiplication a*=b
extern void
viscr_vec_mult_scalar(
    viscr_vector & a,
    const viscr_float b);


/// Element-wise multiplication c=a*b
extern void
viscr_vec_mult_scalar(
    viscr_vector & c,
    const viscr_vector & a,
    const viscr_float b);

/// Element-wise in-place negation a=-a
extern void
viscr_vec_negate(
    viscr_vector & a);

/* ~CodeReview ~ID:0045a569acc351d68b16c46360d2a9b6 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Add a "1" row
extern void
viscr_vec_homogenize(
	viscr_vector & b,
	const viscr_vector & a);

/// Devide by last row and remove it
extern void
viscr_vec_dehomogenize(
	viscr_vector & b,
	const viscr_vector & a);

/// Displace a point along a line: pt = start + offs*dir
extern void
viscr_vec_on_line( 
    viscr_vector & pt,
    const viscr_vector & start,
    const viscr_vector & dir,
    const viscr_float offs);
#endif
#define MAKE_VECTOR(e) \
struct viscr_vec##e \
{ \
  viscr_vector v; \
  viscr_float data[e]; \
  viscr_vec##e(): v( e, data) { } \
 \
  viscr_vec##e( const viscr_vec##e & o): v( e, data) { viscr_vec_copy( v, o.v); } \
  viscr_vec##e & operator=( const viscr_vec##e & o) { viscr_vec_copy( v, o.v); return *this; } \
}

MAKE_VECTOR(1);
MAKE_VECTOR(2);
MAKE_VECTOR(3);
MAKE_VECTOR(4);
MAKE_VECTOR(6);
MAKE_VECTOR(9);
#undef MAKE_VECTOR

/* ~CodeReview ~ID:c38277c418b34f4c047c16d063476713 ~Reviewer:CW01\uidv0048 ~Date:6/21/2012 ~Priority:3 ~Comment:Remove dead code for readability */
#if 0 // CODE NOT USED
/// Cross product for 3d vectors (not a vector for anything else): c= a cross b;
extern void
viscr_vec_cross(
    viscr_vec3 & c,
    const viscr_vec3 & a,
    const viscr_vec3 & b);


/// Z-component of cross product of 3d vectors. Useful for left right
/// decisions in a plane.
extern viscr_float
viscr_vec2_cross_z(
    const viscr_vec2 & a,
    const viscr_vec2 & b);
#endif

//! Templated version of column vector definition to allow more flexible usage
template <uint32 cRow>
class viscr_vec
{
public:
  viscr_vector v;
  viscr_float data[cRow];
  viscr_vec() : v(cRow, data) { }
  
  viscr_vec(const viscr_vec & o) : v(cRow, data) {
    viscr_vec_copy(v, o.v);
  }
  viscr_vec & operator=(const viscr_vec & o) {
    viscr_vec_copy(v, o.v);
    return *this;
  }
};

/// Set elements of a 3 vector
extern void
viscr_vec_assign(
    viscr_vec3 & v,
    const viscr_float & c0,
    const viscr_float & c1,
    const viscr_float & c2);

/// Set elements of a 3 vector
extern void
viscr_vec_assign(
    viscr_vec2 & v,
    const viscr_float & c0,
    const viscr_float & c1);

/// Find the maximum element
extern void
viscr_vec_max(
    viscr_float & value,
    viscr_uint & index,
    const viscr_vector & v);

/// Find the maximum element
extern viscr_float
viscr_vec_max(
    const viscr_vector & v);

/*@}*/

#endif
