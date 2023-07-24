/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_solve.hpp  

  DESCRIPTION:    solve Ax=b for overdetermined systems of equations

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_solve.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:38CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:37CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.4 2012/04/20 11:22:09CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        - Added comments -  uid26778 [Apr 20, 2012 11:22:10 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2011/10/04 17:05:03CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 5:05:03 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273



**************************************************************************** */


#ifndef _viscr_solve_hpp_
#define _viscr_solve_hpp_

#include <viscr_matrix.hpp>
#include <viscr_vector.hpp>

/** \brief Cholesky factorization.
  <P>
  For a symmetric, positive definite matrix A, this function
  computes the Cholesky factorization, i.e. it computes a lower 
  triangular matrix L such that A = L*L'.
  If the matrix is not symmetric or positive definite, the function
  computes only a partial decomposition.  This can be tested with
  the is_spd() flag.

  <p>
  (Adapted from JAMA, a Java Matrix Library, developed by jointly 
  by the Mathworks and NIST; see  http://math.nist.gov/javanumerics/jama).

  This was taken from TNT.
*/
/*@{*/


/**
  Constructs a lower triangular matrix L, such that L*L'= A.
  If A is not symmetric positive-definite (SPD), only a
  partial factorization is performed.  \return
  true if the factorizaiton was successful.
  */
extern boolean_t
viscr_compute_cholesky( 
    viscr_matrix & L,
    const viscr_matrix & A,
    const viscr_float mu=0.0f);


/**
  Solve a linear system A*x = b, using the previously computed
  cholesky factorization of A: L*L'.

  @param  L   Output of viscr_compute_cholesky
  @param  b   A vector with as many elements as A.
  @param  x so that L*L'*x = b.  
  @return true for success
  */
extern boolean_t
viscr_solve_cholesky(
    viscr_vector & x,
    const viscr_matrix & L,
    const viscr_vector & b);

/*@}*/


/** @name LU decomposition from TNT
   <P>
   For an m-by-n matrix A with m >= n, the LU decomposition is an m-by-n
   unit lower triangular matrix L, an n-by-n upper triangular matrix U,
   and a permutation vector piv of length m so that A(piv,:) = L*U.
   If m < n, then L is m-by-m and U is m-by-n.
   <P>
   The LU decompostion with pivoting always exists, even if the matrix is
   singular, so the constructor will never fail.  The primary use of the
   LU decomposition is in the solution of square systems of simultaneous
   linear equations.  This will fail if isNonsingular() returns false.
 */
/*@{*/


/// Compute LU decomposition with pivoting, return false if failed
extern boolean_t
viscr_compute_LU( 
    viscr_matrix & LU,
    viscr_uint * piv,
    viscr_float * const LUcolj,
    const viscr_matrix & A);


/** Solve A*X = B
  @param  B   A Matrix with as many rows as A and any number of columns.
  @return     return false if failed.
  */
extern boolean_t
viscr_solve_LU(
    viscr_matrix & X,
    const viscr_matrix & LU,
    const viscr_uint * const piv,
    const viscr_matrix & B);
/*@}*/

#endif
