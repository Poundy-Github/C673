#include <cassert>
#include <viscr_lms.hpp>
#include <viscr_levmar.hpp>
#include <viscr_math.hpp>
#include <viscr_solve.hpp>
#include <viscr_defs.h>

#include "sac_profile.h"



/// Helper function to compute a single Levenberg-Marquardt update. Taken from
/// DCIBV
tUpdateResult
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
    )
{
  extern i8_t fine_flag;
  viscr_bool return_flag = viscr_false ;

  FxMeasured /= 2.0F;

  tUpdateResult res = LEVMAR_CONTINUE;

  // Second half of update code {{{
  if( state == LEVMAR_NEW_F)
  {
    state = LEVMAR_NORMAL;

    viscr_float Fxn = FxMeasured;
    viscr_float Fx = Fx_last;

    viscr_float dL = 0.0F;
    viscr_float ftemp;
    for( viscr_uint i = 0U; i < JtJ.rows; ++i)
    {
      ftemp = delta[i];
      dL += (-delta[i]) * ((-mu * ftemp) - Jte_old[i]);
    }
    dL /= 2.0F;
    viscr_float rho = (Fx - Fxn) / dL;
    
    if( rho > 0.0F )
    {
      if( viscr_vec_max( Jte) < param.eps1)
      {
        res = LEVMAR_FOUND;
        return_flag = viscr_true;
      }
      else
      {
        viscr_float dmu = ((2.0F * rho) - 1.0F);
        dmu = 1.0F - (dmu * (dmu * dmu));
        mu = mu * viscr_float_max( dmu, 0.333333F);
        v = 2.0F;
        res = LEVMAR_NEXT_ITER;
      }
    }
    else
    {
      viscr_vec_copy( phi, phi_old);
      mu *= v;
      v += v;
      res = LEVMAR_NEXT_ITER;
      return_flag = viscr_true;
    }
    M_SAC_PROFILE_END(sSpare03)
  }

  if ( return_flag == viscr_false ) 
  {
    viscr_float JtJmax = viscr_mat_max_diag( JtJ);
    if (state == LEVMAR_BEFORE)
    {
      // First iteration, initialise mu to maximal A diagonal element
      mu=param.tau * JtJmax;
      if (fine_flag == 1)
      {
		     mu = static_cast<viscr_float>(LM_MU_FINE_ONLY);
      }
      state = LEVMAR_NORMAL;
    }

    mu = viscr_float_max( mu, param.muMin * JtJmax);

    viscr_uint solvIt = 10U;
    for( ; solvIt > 0U; --solvIt)
    {
      if( viscr_compute_cholesky( L, JtJ, mu))
      {
        if( viscr_solve_cholesky( delta , L, Jte))
        {
          break;
        }
      }
      mu = mu * 10.0F;
    }
    if(solvIt == 0U)
    {
      res = LEVMAR_ERROR;
    }
    else
    {
      if( viscr_vec_norm(delta) < (param.eps2 * (viscr_vec_norm( phi) + param.eps2)))
      {
        res = LEVMAR_FOUND;
      }
      else
      {
        viscr_vec_copy( phi_old, phi);
        viscr_vec_copy( Jte_old, Jte);
        viscr_vec_sub( phi, phi, delta);
  
        state = LEVMAR_NEW_F;
        Fx_last = FxMeasured;
        if (fine_flag == 1)
        {
          res = LEVMAR_FOUND;
        }
      }
    }
  }
  return res;
}


// This is a direct port of Madsen et al.'s Matlab implementation with one
// modification: The iteration is split so that only one call to the objective
// function is made. For some iterations, the derivatives are computed, but
// not used. If this causes performance problems, a flag can be passed to the
// objective function whether or not the derivatives should be computed.
void
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
    viscr_vector & delta)
{
  assert( JtJ.rows==JtJ.cols);
  assert( JtJ.rows==Jte.length);
  assert( L.rows==L.cols);
  assert( JtJ.rows==L.rows);
  assert( phi.length==JtJ.rows);
  assert( phi_old.length==JtJ.rows);
  assert( Jte_old.length==JtJ.rows);
  assert( delta.length==JtJ.rows);

  // Increase of mu for unsuccesful step
  viscr_float v = 2.0F;

  // Levenberg-Marquardt factor (influence of gradient descent)
  viscr_float mu = -1.0F;

  // Current function value
  viscr_float Fx;

  // Last function value
  viscr_float Fx_last = -1.0F;

  // State of FSM for iteration split.
  tState state = LEVMAR_BEFORE;


  M_SAC_PROFILE_START(sSpare02)

  for( viscr_uint iter = 0U; iter < opt_param.max_iter; )
  {
    viscr_mat_zero( JtJ);
    viscr_vec_zero( Jte);

    Fx = 0.0F;

    objFun( phi, JtJ, Jte, Fx, ud);

    // Update the current vector.
    switch( levmar_update( phi, JtJ, Jte, opt_param, Fx, L, phi_old, Jte_old, delta, state, Fx_last, mu, v))
    {
      case LEVMAR_CONTINUE:
        break;
      case LEVMAR_NEXT_ITER:
        ++iter;
        break;
      case LEVMAR_FOUND:
      case LEVMAR_ERROR:  // TODO: connect to fine-flag
      default:
        iter = opt_param.max_iter;
        break;
    }
  }
  M_SAC_PROFILE_END(sSpare02)
}


void
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
    void * const mEstData)
{
  viscr_uint nSam = delta.length;
  viscr_uint nDims = phi.length;

  M_SAC_PROFILE_START(sSpare00)
  // Compute derivatives by finite differences
  for( viscr_uint j = 0U; j < nDims; ++j)
  {
    viscr_float oldPhi = phi[j];

    viscr_vec_zero( delta);

    phi[j] = oldPhi + dPhi;
    objFun( phi, delta,  1.0F, sampleData, userData);

    phi[j] = oldPhi - dPhi;
    objFun( phi, delta, -1.0F, sampleData, userData);

    phi[j] = oldPhi;

    for( viscr_uint k = 0U; k < nSam; ++k)
    {
      smallJ(k,j) = delta[k] / (dPhi + dPhi);
    }
  }
  M_SAC_PROFILE_END(sSpare00)
  M_SAC_PROFILE_START(sSpare01)
  // Compute error
  viscr_vec_zero( delta);
  objFun( phi, delta, 1.0F, sampleData, userData);

  // Compute m-estimator value and integrate sub-Jacobian into linear
  // estimation.
  viscr_float ftemp;
  for( viscr_uint k = 0U; k < nSam; ++k )
  {
    ftemp = delta[k];
    Fx += (delta[k] * ftemp);
    for( viscr_uint j = 0U; j < nDims; ++j)
    {
      row[j] = smallJ(k, j);
    }
    viscr_float wt = 0.0F;
    mEst( delta[k], wt, userData, mEstData);
    viscr_lms_addRow_weight( JtJ, Jte, row, delta[k], wt);
  }
  M_SAC_PROFILE_END(sSpare01)
}
