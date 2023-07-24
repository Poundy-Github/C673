#ifndef VISCR_TRANSFORMATION_HPP_
#define VISCR_TRANSFORMATION_HPP_

#include <viscr_vector.hpp>
#include <viscr_matrix.hpp>
#include <viscr_defs.h>

/* ~CodeReview ~ID:2f1fc6165464ce3678a27bd1019011e7 ~Reviewer:CW01\uid28828 ~Date:19/06/2012 ~Priority:3 ~Comment:Remove dead code for readability */


/// Invert a homogeneous transformation
extern void
viscr_transformation_invert(viscr_mat44 & HInv, const viscr_mat44 & H);

/// Decompose homogeneous transformation
extern void
viscr_transformation_decompose_tPrime(viscr_mat33 & R, viscr_vec3 & t_prime,
    const viscr_mat44 & T);

/// Compose homogeneous transformation
extern void
viscr_transformation_compose_tPrime(viscr_mat44 & T, const viscr_mat33 & R,
    const viscr_vec3 & t_prime);

extern void
viscr_transformation_compose(viscr_mat44 & T, const viscr_mat33 & R,
    const viscr_vec3 & t);
//#endif
#if (VISCR_SMPC_REMOVE_YAW_IN_FINE==0) 
/// Return the norm of the translation vector of the transform.
extern viscr_float
viscr_transformation_translationNorm(const viscr_mat44 & H);
#endif
#if 0 // CODE NOT USED
/// Converts t_X into t_X_prime of a transformation T_X using R_X
extern void
viscr_transformation_tXToTXPrime(viscr_vec3 & t_X_prime,
    const viscr_mat33 & R_X, const viscr_vec3 & t_X);
#endif
/// Converts t_X_prime into t_X of a transformation T_X using R_X
extern void
viscr_transformation_tXPrimeToTX(viscr_vec3 & t_X, const viscr_mat33 & R_X,
    const viscr_vec3 & t_X_prime);
#if 0 // CODE NOT USED
/// Applies Eucledean (rigid body) transformation (in-place)
extern void
viscr_transformation_euclidean(viscr_vec3 & v, const viscr_mat33 & R,
    const viscr_vec3 & t);
#endif
#endif /* VISCR_TRANSFORMATION_HPP_ */
