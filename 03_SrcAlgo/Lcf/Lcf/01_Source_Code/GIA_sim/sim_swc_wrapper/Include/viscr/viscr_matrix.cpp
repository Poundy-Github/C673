/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_matrix.cpp  

  DESCRIPTION:    Matrix library

  AUTHOR:         L. GARCIA
  Last Author     $Author: Wang, David (Wangd3) $

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_matrix.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:31CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:20CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.22 2014/02/20 13:46:17CET Sadran, Emal (uidw7976) 
  CHANGES:        reactived floating point version of the epipolar_objfun for test purposes
  CHANGES:        - Added comments -  uidw7976 [Feb 20, 2014 1:46:17 PM CET]
  CHANGES:        Change Package : 196075:4 http://mks-psad:7002/im/viewissue?selection=196075
  CHANGES:        Revision 1.21 2013/08/15 14:29:08CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:08 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.20 2013/03/15 19:14:55CET Ruland, Thomas (uidw0251) 
  CHANGES:        - first complete version of wrapper
  CHANGES:        --- Added comments ---  uidw0251 [Mar 15, 2013 7:14:55 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.19 2012/07/17 16:11:25CEST Garcia, Lucien (uid26778) 
  CHANGES:        pc lint
  CHANGES:        --- Added comments ---  uid26778 [Jul 17, 2012 4:11:25 PM CEST]
  CHANGES:        Change Package : 138467:2 http://mks-psad:7002/im/viewissue?selection=138467
  CHANGES:        Revision 1.18 2012/07/13 10:27:12CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add function coverage tag
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 10:27:12 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.17 2012/07/05 08:49:27CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        Revision 1.16 2012/07/03 17:14:35CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add Code Coverage reports
  CHANGES:        Revision 1.15 2012/06/26 11:19:33CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Code review comments added
  CHANGES:        --- Added comments ---  uidk7517 [Jun 26, 2012 11:19:34 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.14 2012/05/25 14:55:54CEST Exner, Christian (uidt8578) 
  CHANGES:        - added another viscr_mat_copy overload (from array to viscr_matrix)
  CHANGES:        --- Added comments ---  uidt8578 [May 25, 2012 2:55:55 PM CEST]
  CHANGES:        Change Package : 116950:2 http://mks-psad:7002/im/viewissue?selection=116950
  CHANGES:        Revision 1.13 2012/04/19 15:18:56CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:18:56 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.12 2012/03/12 10:56:34CET Konarski-EXT, Witek (uidt8403) 
  CHANGES:        Removed a PC-Lint/Misra errors.
  CHANGES:        --- Added comments ---  uidt8403 [Mar 12, 2012 10:56:34 AM CET]
  CHANGES:        Change Package : 101150:13 http://mks-psad:7002/im/viewissue?selection=101150
  CHANGES:        Revision 1.11 2012/02/22 17:28:51CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove unused code
  CHANGES:        --- Added comments ---  uid26778 [Feb 22, 2012 5:28:51 PM CET]
  CHANGES:        Change Package : 80273:2 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.10 2011/10/04 16:19:35CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 4:19:35 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
 

**************************************************************************** */

#include <cmath>
#include <cassert>
#include <limits>
#include <algorithm>

#include <viscr_matrix.hpp>

// ~CodeReview ~ID:6e885247eb8faf09e6d7a62d168344eb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 1764 not commented (m could be declared const ref)
void viscr_mat_zero( viscr_matrix & m)
{
  viscr_float* pfloat_for_misra;
  pfloat_for_misra = m.data;
  for( viscr_uint i=0U; i<(m.rows*m.cols); ++i)
    {
      *pfloat_for_misra=0.0F;
      pfloat_for_misra++;
    }
}


void viscr_mat_copy(viscr_matrix &A, const mat3 &B)
{
  for( viscr_uint r=0U; r<A.rows; ++r)
  {
    for( viscr_uint c=0U; c<A.cols; ++c)
      {A(r,c)=B(static_cast<viscr_int>(r),static_cast<viscr_int>(c));}
  }
}

void viscr_mat_copy(mat3 &A, const viscr_matrix &B)
{
  for( viscr_uint r=0U; r<B.rows; ++r)
  {
    for( viscr_uint c=0U; c<B.cols; ++c)
      {A(static_cast<viscr_int>(r),static_cast<viscr_int>(c))=B(r,c);}
  }
}

void viscr_mat_copy(f32_t A[9], const mat3 &B)
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A[(r*3U)+c]=B(static_cast<viscr_int>(r),static_cast<viscr_int>(c));}
  }
}

void viscr_mat_copy(f32_t A[9], const f32_t B[9])
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A[(r*3U)+c]=B[(r*3U)+c];}
  }
}

void viscr_mat_copy(viscr_matrix &A, const f32_t B[9])
{
  for( viscr_uint r=0U; r<A.rows; ++r)
  {
    for( viscr_uint c=0U; c<A.cols; ++c)
      {A(r,c)=B[(r*3U)+c];}
  }
}

void viscr_mat_copy(f32_t (&A)[9], const viscr_matrix &B)
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
    /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Garcia Lucien date: 17.07.2012 reason: indexing by pointer faster */
    {A[(r*3U)+c] = B(r,c);}
  }
}


void viscr_mat_transpose_copy(viscr_matrix &A, const f32_t B[9])
{
  for( viscr_uint r=0U; r<A.rows; ++r)
  {
    for( viscr_uint c=0U; c<A.cols; ++c)
      {A(c,r)=B[(r*3U)+c];}
  }
}

/* <ln_offset:+1to+8 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is currently not used (dead code). */
void viscr_mat_transpose_copy(f32_t A[9], const f32_t B[9])
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A[(r*3U)+c]=B[(c*3U)+r];}
  }
}


void viscr_mat_transpose_copy(mat3 &A, const f32_t B[9])
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A(static_cast<viscr_int>(c),static_cast<viscr_int>(r))=B[(r*3U)+c];}
  }
}

/* <ln_offset:+1to+8 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is currently not used (dead code). */
void viscr_mat_copy(mat3 &A, const f32_t B[9])
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A(static_cast<viscr_int>(r),static_cast<viscr_int>(c))=B[(r*3U)+c];}
  }
}

/* <ln_offset:+1to+8 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is currently not used (dead code). */
void viscr_mat_transpose_copy(f32_t A[9],const viscr_matrix & B)
{
  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A[(r*3U)+c]=B(c,r);}
  }
}

void viscr_mat_transpose_copy(f32_t A[9],const mat3 &B)
{

  for( viscr_uint r=0U; r<3U; ++r)
  {
    for( viscr_uint c=0U; c<3U; ++c)
      {A[(r*3U)+c]=B(static_cast<viscr_int>(c),static_cast<viscr_int>(r));}
  }
}

/* <ln_offset:+1to+17 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Function to do matrix vector multiplication(currently may not be used). */
void
viscr_mat_mult_vec(
  viscr_vector & c,
  const viscr_matrix & A,
  const viscr_vector & b)
{
  viscr_uint M = A.rows;
  viscr_uint K = b.length;
  assert(A.cols == K);
  for( viscr_uint i=0U; i<M; ++i) 
  {
    viscr_float sum=0.0F;
    for( viscr_uint k=0U; k<K; ++k)
      {sum += A(i,k) * b[k];}
    c[i] = sum;
  }
}

// ~CodeReview ~ID:c979a5f3d6bcf166a6659f3af04b17a8 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//#if 0 // CODE NOT USED
void
viscr_mat_mult_vec_left(
  viscr_vector & c,
  const viscr_vector & a,
  const viscr_matrix & B)
{
  viscr_uint M = B.rows;
  viscr_uint N = B.cols;
  viscr_uint K = a.length;
  assert(M == K);
  for( viscr_uint i=0U; i<N; ++i) 
  {
    viscr_float sum=0.0F;
    for( viscr_uint k=0U; k<K; ++k)
      {sum += B(k,i) * a[k];}
    c[i] = sum;
  }
}
//#endif


viscr_float
viscr_mat_max_diag(
  const viscr_matrix & A)
{
  assert( A.rows==A.cols);
  assert( A.rows>=1U);
  viscr_float res=A(0U,0U);
  viscr_uint n=A.rows;
  for( viscr_uint i=1U; i<n; ++i)
  {
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Paremete control check. */
    if( A(i,i)>res)
      {res=A(i,i);}
  }
  return res;
}


void
viscr_mat_copy(
  viscr_matrix & A,
  const viscr_matrix & B)
{
  assert( A.rows==B.rows);
  assert( A.cols==B.cols);

  for( viscr_uint r=0U; r<A.rows; ++r)
  {
    for( viscr_uint c=0U; c<A.cols; ++c)
      {A(r,c)=B(r,c);}
  }
}


void
viscr_mat_transpose_copy(
  viscr_matrix & A,
  const viscr_matrix & B)
{
  assert( A.rows==B.cols);
  assert( A.cols==B.rows);

  for( viscr_uint r=0U; r<A.rows; ++r)
  {
    for( viscr_uint c=0U; c<A.cols; ++c)
      {A(r,c)=B(c,r);}
  }
}


void
viscr_mat_mult_mat(
  viscr_matrix & C,
  const viscr_matrix & A,
  const viscr_matrix & B)
{
  viscr_uint dim1_a=A.rows;
  viscr_uint dim2_b=B.cols;
  viscr_uint dim1_b=B.rows;
  assert(A.cols==dim1_b);
  assert(C.rows==dim1_a);
  assert(C.cols==dim2_b);

  for( viscr_uint i=0U; i<dim1_a; ++i)
  {
    for( viscr_uint j=0U; j<dim2_b; ++j)
    {
      viscr_float sum = 0.0F;
      for( viscr_uint k=0U; k<dim1_b; ++k)
        {sum += A(i,k) * B(k,j);}
      C(i,j) = sum;
    }
  }
}


void
viscr_mat_identity(
    viscr_matrix & m)
{
  assert( m.rows==m.cols);
  viscr_mat_zero( m);
  for( viscr_uint i=0U; i<m.rows; ++i)
    {m(i,i)=1.0F;}
}

extern viscr_float
viscr_mat_norm_Linfty(
  const viscr_matrix & A)
{
  viscr_float *pData = A.data;
  viscr_float maxVal = -std::numeric_limits<viscr_float>::infinity();
  for( viscr_uint i=0U; i<(A.rows*A.cols); ++i, pData++)
  {
    maxVal = std::max(maxVal, *pData);
  }
  return maxVal;
}

extern viscr_float
viscr_mat_norm_LinftyAbsDelta(
  const viscr_matrix & A,
  const viscr_matrix & B)
{
  assert(A.rows==B.rows);
  assert(A.cols==B.cols);
  viscr_float *pA = A.data;
  viscr_float *pB = B.data;
  viscr_float maxVal = -std::numeric_limits<viscr_float>::infinity();
  for( viscr_uint i=0U; i<(A.rows*A.cols); ++i, pA++, pB++)
  {
    maxVal = std::max(maxVal, fabsf(*pA - *pB));
  }
  return maxVal;
}


#if 0
// Deactivated until specialised solver for identity matrix is implemented.
bool
viscr_mat_invert(
    viscr_matrix & A,
    viscr_matrix & LU,
    viscr_int * piv,
    const viscr_matrix & B)
{
  assert( A.rows==B.cols);
  assert( A.cols==B.rows);
  assert( A.rows==LU.rows);
  assert( A.cols==LU.cols);


}
#endif

