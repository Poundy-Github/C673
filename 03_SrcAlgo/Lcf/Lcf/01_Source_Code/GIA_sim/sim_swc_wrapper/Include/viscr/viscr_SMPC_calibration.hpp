#ifndef _viscr_smpc_calibration_hpp_
#define _viscr_smpc_calibration_hpp_

#include <viscr_types.hpp>
#include <viscr_SMPC.hpp>

/** @name Calibration helpers, shared by coarse and fine calibration.  */
/*@{*/


/** @name Ramp m-estimator parameter */
/*@{*/

/** m-Estimator as simple approximation of corrupted Gaussian noise. The
 * function is flat around zero and decreases for values of e between rampMin
 * and rampMax from 1 to lowWeight. \param ud is not used, \param mEstData
 * must be a viscr_SMPC_rampme_data
 */
extern void
viscr_SMPC_ramp_mEstimator(
    const viscr_float e,
    viscr_float & wt,
    void * ud,
    void * const mEstData);

/*@}*/

/// User data struct for rotation matrix estimation
struct viscr_SMPC_epipolar_calib_userdata
{
  /// Camera constant for m-estimator unit-conversion
  viscr_float f;


  /// Pointer to SMPC application parameters
  viscr_SMPC_param * param;


  /// M-Estimator data
  viscr_SMPC_rampme_data mEstData;


  /// Cross-product matrix of translation vector
  viscr_mat33 Tx;


  /// Yaw angle from calibration
  viscr_float yaw;

  
  /// Pointer to bins
  const viscr_SMPC_epipolar_corr * corr;


  /// Temporal storage for one row of the equation system
  viscr_vec2 row;


  /// Temporal storage for one set of error
  viscr_vec2 delta;


  /// Temporal storage for one sub-Jacobian
  viscr_mat22 smallJ;


  viscr_SMPC_epipolar_calib_userdata() { }
  
  private:
    viscr_SMPC_epipolar_calib_userdata( const viscr_SMPC_epipolar_calib_userdata &);
    viscr_SMPC_epipolar_calib_userdata & operator=( const viscr_SMPC_epipolar_calib_userdata &);
};



/// Prepare and perform the optimisation 
extern void
viscr_SMPC_epipolar_calibration( 
    viscr_SMPC_data & data, 
    viscr_float & a,
    viscr_float & c,
    viscr_float & rmse_epipolar,
    viscr_float & rmse_improvement,
    const SACCallBackHdlr_t & callBackHandler);

extern void
epipolar_derivatives(
     viscr_vector & phi,
     viscr_matrix & JtJ, 
     viscr_vector & Jte, 
     viscr_float & Fx,
     void * const ud);

extern void
epipolar_objfun_floatingpoint(
                  const viscr_vector & phi,
                  viscr_vector & f,
                  const viscr_float scale,
                  const void * const sampleData,
                        void * const ud);

/*@}*/

#endif

