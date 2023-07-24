/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_solve.cpp  

  DESCRIPTION:    solve Ax=b for overdetermined systems of equations

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_solve.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:38CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:36CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.16 2013/08/15 14:28:55CEST uidw3458 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        - Added comments -  uidw3458 [Aug 15, 2013 2:28:55 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.15 2012/08/10 14:25:32CEST Cui, Baomin (cuib) 
  CHANGES:        - merged coverage tags and misra comments from branch to trunk
  CHANGES:        --- Added comments ---  cuib [Aug 10, 2012 2:25:32 PM CEST]
  CHANGES:        Change Package : 151187:4 http://mks-psad:7002/im/viewissue?selection=151187
  CHANGES:        Revision 1.14 2012/07/24 08:59:07CEST Behrens, Alexander (uidv2823) 
  CHANGES:        merged coverage tags and misra comments from branch to trunk
  CHANGES:        --- Added comments ---  uidv2823 [Jul 24, 2012 8:59:08 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.13 2012/07/12 18:13:08CEST Garcia, Lucien (uid26778) 
  CHANGES:        Update priority
  CHANGES:        --- Added comments ---  uid26778 [Jul 12, 2012 6:13:08 PM CEST]
  CHANGES:        Change Package : 138467:2 http://mks-psad:7002/im/viewissue?selection=138467
  CHANGES:        Revision 1.12 2012/07/05 13:48:31CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code review tag
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 1:48:31 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.11 2012/07/05 08:32:06CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        Revision 1.10 2012/07/04 16:55:17CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code review comment
  CHANGES:        Revision 1.9 2012/07/03 17:41:01CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jul 3, 2012 5:41:01 PM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.8 2012/04/20 11:21:22CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Apr 20, 2012 11:21:22 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.6 2012/03/14 17:44:37CET Exner, Christian (uidt8578) 
  CHANGES:        - viscr_solve_LU() defined a variable m, that was only used in a assert -> changed it to use the assigned value directly
  CHANGES:        --- Added comments ---  uidt8578 [Mar 14, 2012 5:44:37 PM CET]
  CHANGES:        Change Package : 101435:5 http://mks-psad:7002/im/viewissue?selection=101435
  CHANGES:        Revision 1.5 2012/01/19 14:22:27CET Garcia, Lucien (uid26778) 
  CHANGES:        First integration of stereo EOL calibration
  CHANGES:        --- Added comments ---  uid26778 [Jan 19, 2012 2:22:27 PM CET]
  CHANGES:        Change Package : 94275:1 http://mks-psad:7002/im/viewissue?selection=94275
  CHANGES:        Revision 1.4 2011/10/04 17:05:02CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 5:05:02 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273



**************************************************************************** */

#include <cmath>
#include <viscr_solve.hpp>
#include <viscr_tools.hpp>

/*################################# cholesky #################################*/
boolean_t 
viscr_compute_cholesky( 
    viscr_matrix & L,
    const viscr_matrix & A,
    const viscr_float mu)
{
  viscr_uint m=A.rows;
  viscr_uint n=A.cols;
  assert( L.rows==m);
  assert( L.cols==n);

  boolean_t isspd = true;
  viscr_float temp_float_for_misra;

  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Variable control check. */
  if (m != n)
    {isspd =  false;}
  else
  {
    for ( viscr_uint j = 0U; j < n; j++) 
    {
      viscr_float d = 0.0F;
      for ( viscr_uint k = 0U; k < j; k++) 
      {
        viscr_float s = 0.0F;
        /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 14.07.2012 reason: Perform for loop. */
        for ( viscr_uint i = 0U; i < k; i++) 
          {
            temp_float_for_misra = L(k,i);
            s += temp_float_for_misra*L(j,i);
        }
        /* ~CodeReview ~ID:04bb0cb9478247c25c27f02548e15468 ~Reviewer:CW01\uidt8688 ~Date:03.07.2012 ~Priority:2 ~Comment:Potential Division by Zero */
        s = (A(j,k) - s)/L(k,k);
        L(j,k) = s;
        d = d + (s*s);
        isspd = isspd && (fabsf(A(k,j) - A(j,k))<C_F32_DELTA); /* <ln_offset:+0 COVERAGE reviewer name: Baomin Cui date: 10.08.2012 reason: Variable control Check. */
      }
      d = (A(j,j)+mu) - d;
      isspd = isspd && (d > 0.0F);/* <ln_offset:+0 COVERAGE reviewer name: Baomin Cui date: 10.08.2012 reason: Variable control Check. */
      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Check if data is valid. */
      L(j,j) = ((d > 0.0F) ? sqrtf(d) : 0.0F);
      for (viscr_uint k = j+1U; k < n; k++) 
        {L(j,k) = 0.0F;}
    }
  }
  return isspd;
}


boolean_t
viscr_solve_cholesky(
    viscr_vector & x,
    const viscr_matrix & L,
    const viscr_vector & b)
{
  viscr_float temp_float_for_misra;
  viscr_uint  temp_uint_for_misra;

  viscr_uint n = L.rows;
  assert( b.length==n);

  viscr_vec_copy( x, b);

  // Solve L*y = b;
  for (viscr_uint k = 0U; k < n; k++) 
  {
    for (viscr_uint i = 0U; i < k; i++) 
      {
        temp_float_for_misra = x[i];
        x[k] -= temp_float_for_misra*L(k,i);
      }
    x[k] /= L(k,k);

  }

  // Solve L'*X = Y;
  for (viscr_int k = (static_cast<viscr_int>(n)-1); k >= 0; k--) 
  {
    temp_uint_for_misra = static_cast<viscr_uint>(k);
    for (viscr_uint i = (static_cast<viscr_uint>(k)+1U); i < n; i++)
    {
      temp_float_for_misra = x[i];
      x[temp_uint_for_misra] -= temp_float_for_misra*L(i,temp_uint_for_misra);
    }
    /* ~CodeReview ~ID:aa847d0c32483033e7d52334bc14154c ~Reviewer:CW01\uidt8688 ~Date:03.07.2012 ~Priority:2 ~Comment:potential division by zero */
    x[temp_uint_for_misra] /= L(temp_uint_for_misra,temp_uint_for_misra);
  }

  /* ~CodeReview ~ID:50b013b71c92a29958ebe1a3c4380f5c ~Reviewer:CW01\uidv2823 ~Date:04.07.2012 ~Priority:2 ~Comment:Function seems to return always true. */
  return true;
}

/*############################# LU decomposition #############################*/
boolean_t
viscr_compute_LU( 
    viscr_matrix & LU,
    viscr_uint * const piv,
    viscr_float * const LUcolj,
    const viscr_matrix & A)
{
  viscr_float temp_float_for_misra;
  boolean_t result = true;
  assert( LU.rows==A.rows);
  assert( LU.cols==A.cols);

  viscr_uint m=A.rows;
  viscr_uint n=A.cols;

  viscr_mat_copy( LU, A);

  // Use a "left-looking", dot-product, Crout/Doolittle algorithm.

  viscr_uint i;
  viscr_uint j;
  viscr_uint k=0U;

  for( i = 0U; i < m; ++i) 
    {
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
     piv[i] = i;
    }

  viscr_float * LUrowi = static_cast<viscr_float *>(NULL);

  for( j = 0U; j < n; ++j) 
  {
    // Make a copy of the j-th column to localize references.
    for (i = 0U; i < m; i++)
    {
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      LUcolj[i] = LU(i,j);
    }

    // Apply previous transformations.
    for( i = 0U; i < m; i++) 
    {
      LUrowi = &LU(i,0U);

      // Most of the time is spent in the following dot product.
      viscr_uint kmax = viscr_uint_min(i,j);
      viscr_float s = 0.0F;
      for( k = 0U; k < kmax; k++) 
        {
          /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
          s += LUrowi[k]*LUcolj[k];
        }

      //       LUrowi[j] = LUcolj[i] -= s;
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      LUcolj[i] -= s;
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      LUrowi[j] = LUcolj[i];
    }
   
    // Find pivot and exchange if necessary.
    viscr_uint p = j;
    for( i = j+1U; i < m; ++i) 
    {
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      if( fabsf( LUcolj[i]) > fabsf( LUcolj[p]))
        {p = i;}
    }
    if( p != j) 
    {
      for( k = 0U; k < n; ++k) 
      {
        viscr_float t = LU(p,k); 
        temp_float_for_misra = LU(j,k);
        LU(p,k) = temp_float_for_misra; 
        LU(j,k) = t;
      }
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      k = piv[p]; 
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      piv[p] = piv[j]; 
     /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
      piv[j] = k;
    }

    // Compute multipliers.
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Control check if data is valid for multiplier computation. */
    if ((j < m) && (fabsf(LU(j,j)) > C_F32_DELTA)) 
    {
      for (i = j+1U; i < m; ++i) 
        {
          temp_float_for_misra =  LU(j,j);
          /* ~CodeReview ~ID:ccbcd1af2b09137be0e5c1bb7b2e7bf8 ~Reviewer:CW01\uidt8688 ~Date:03.07.2012 ~Priority:2 ~Comment:potential division by zero */
          LU(i,j) /= temp_float_for_misra;
        }
    }
  }

  // Check for singularity
  /* ~CodeReviewBegin ~ID:60856f3b49c7994ec1f21bf161b9e871 ~Reviewer:CW01\uidt8688 ~Date:03.07.2012 ~Priority:2 ~Comment:singularity check too late in function  */
  for( j = 0U; j < n; ++j) 
  {
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Singularity control check. */
    if (fabsf(LU(j,j)) < C_F32_DELTA)
      {result= false;}
  }
  return result;
  /* ~CodeReviewEnd   ~ID:60856f3b49c7994ec1f21bf161b9e871 */
}


boolean_t
viscr_solve_LU(
    viscr_matrix & X,
    const viscr_matrix & LU,
    const viscr_uint * const piv,
    const viscr_matrix & B)
{
  viscr_float temp_float_for_misra;
  viscr_uint n=LU.cols;

  viscr_uint nx = B.cols;

  /* Dimensions: A is mxn, X is nxk, B is mxk */
  assert( B.rows==LU.rows);
  assert( X.rows==n);
  assert( X.cols==nx);
  
  viscr_uint i; viscr_uint j;
  viscr_int k;

  // Copy right hand side with pivoting
  for( i = 0U; i < n; ++i)
  {
    for( j = 0U; j < nx; ++j) 
      {
        /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 19.04.2012 reason: indexing by pointer faster */
        X(i,j) = B(piv[i],j);
      }
  }

  // Solve L*Y = B(piv,:)
  for( k = 0L; k < static_cast<viscr_int>(n); ++k)
  {
    for( i = (static_cast<viscr_uint>(k)+1U); i < n; ++i) 
    {
      for( j = 0U; j < nx; ++j) 
      {
        temp_float_for_misra = X(static_cast<viscr_uint>(k),j);
        X(i,j) -= temp_float_for_misra*LU(i,static_cast<viscr_uint>(k));
      }
    }
  }
  // Solve U*X = Y;
  for( k = (static_cast<viscr_int>(n)-1); k >= 0; --k) 
  {
    for( j = 0U; j < nx; ++j)
    {
      X(static_cast<viscr_uint>(k),j) /= LU(static_cast<viscr_uint>(k),static_cast<viscr_uint>(k));
    }
    for( i = 0U; i < static_cast<viscr_uint>(k); ++i)
    {
      for( j = 0U; j < nx; ++j)
      {
        temp_float_for_misra = X(static_cast<viscr_uint>(k),j);
        X(i,j) -= temp_float_for_misra*LU(i,static_cast<viscr_uint>(k));
      }
    }
  }
 /* ~CodeReview ~ID:50b013b71c92a29958ebe1a3c4380f5c ~Reviewer:CW01\uidv2823 ~Date:04.07.2012 ~Priority:2 ~Comment:Function seems to return always true. */

  return true;
}
