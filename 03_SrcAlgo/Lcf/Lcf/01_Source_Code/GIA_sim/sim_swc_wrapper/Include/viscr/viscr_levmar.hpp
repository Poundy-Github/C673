#ifndef _viscr_levmar_hpp_
#define _viscr_levmar_hpp_

#include <viscr_types.hpp>
#include <viscr_vector.hpp>
#include <viscr_matrix.hpp>

typedef enum { LEVMAR_CONTINUE, LEVMAR_NEXT_ITER, LEVMAR_FOUND, LEVMAR_ERROR } tUpdateResult;
typedef enum { LEVMAR_BEFORE, LEVMAR_NORMAL, LEVMAR_NEW_F } tState;

/// Parameters for Levenberg-Marquardt optimisation
//{{{
struct viscr_levmar_param
{
  /// Maximal number of iterations
  viscr_uint max_iter;


  /// Initial scaling of main diagonal of Hessian to get mu
  viscr_float tau;


  /// Maximal error to stop iteration
  viscr_float eps1;


  /// Maximal improvement to stop iteration
  viscr_float eps2;


  /// Minimal mu for stable solution
  viscr_float muMin;


  /// Set meaningful default values
  viscr_levmar_param():
    max_iter( 100),
    tau( 1e-3f),
    eps1( 1e-4f),
    eps2( 1e-8f),
    muMin( 1e-14f)
  {
  }
  
  private:
    viscr_levmar_param( const viscr_levmar_param &);
    viscr_levmar_param & operator=( const viscr_levmar_param &);
};
/*}}}*/


/** @name Levenberg-Marquardt optimiser */
/*@{*/

/// Objective function
typedef void (*viscr_levmar_objfun)( 
    viscr_vector & phi, 
    viscr_matrix & JtJ, 
    viscr_vector & Jte, 
    viscr_float & Fx, 
    void * userData);


/** Find the value of phi that minimises the objective function. See 
 * \todo separate documentation 
 * on this function. 
 */
extern void
viscr_levmar( 
    viscr_vector & phi, 
    const viscr_levmar_param & opt_param, 
    viscr_levmar_objfun const objFun, 
    void * const ud, 
    viscr_matrix & JtJ, 
    viscr_vector & Jte,
    viscr_matrix & L,
    viscr_vector & phi_old,
    viscr_vector & Jte_old,
    viscr_vector & delta);
/*@}*/

extern tUpdateResult
levmar_update(
              viscr_vector & phi, 
              const viscr_matrix & JtJ, 
              const viscr_vector & Jte, 
              const viscr_levmar_param & param,
              viscr_float FxMeasured, 
              viscr_matrix & L,
              viscr_vector & phi_old,
              viscr_vector & Jte_old,
              viscr_vector & delta,
              tState & state,
              viscr_float & Fx_last,
              viscr_float & mu,
              viscr_float & v
              );

/** @name M-Estimator helper
 */
/*@{*/

/// Compute the corresponding weight wt for error e
typedef void (*viscr_levmar_mEstimator)(
    viscr_float e,
    viscr_float & wt, 
    void * userData,
    void * mEstData
    );

/*@}*/


/** @name Numerical derivatives helper */
/*@{*/

/// Objective function for numerical derivatives, scalar objective functions
typedef void (*viscr_levmar_objfun_num_der)( 
    const viscr_vector & phi, 
    viscr_vector & f, 
    viscr_float scale,
    const void * const sampleData, 
    void * const userData);


/// Compute the numerical derivative for the current sample, scalar objective functions
extern void
viscr_levmar_num_der_mEst( 
    viscr_levmar_objfun_num_der const objFun, 
    viscr_levmar_mEstimator const mEst,
    viscr_float const dPhi,
    viscr_vector & phi, 
    viscr_matrix & JtJ, 
    viscr_vector & Jte, 
    viscr_float & Fx,
    viscr_vector & delta,
    viscr_matrix & smallJ,
    viscr_vector & row, 
    const void * const sampleData,
    void * const userData,
    void * const mEstData);

/*@}*/


#endif

