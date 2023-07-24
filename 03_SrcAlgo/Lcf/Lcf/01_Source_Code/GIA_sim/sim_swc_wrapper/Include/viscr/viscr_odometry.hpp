#ifndef _viscr_odometry_hpp_
#define _viscr_odometry_hpp_

#include <viscr_types.hpp>
#include <viscr_matrix.hpp>

/// Information about the movement of the car
struct viscr_odometry
{
  /// Driven speed in m/s
  viscr_float v;

  /// yaw rate in rad/s, left turn is positive yaw rate
  viscr_float yawRate;

  /* ~CodeReview ~ID:0046cdabbc61a7a542eff2c717a66bc3 ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:uninitialized member variables */
  viscr_odometry() { }

  private:
    viscr_odometry( const viscr_odometry &);
    viscr_odometry & operator=( const viscr_odometry &);
};


/// Compute the resulting transformation between the two car positions
/// according to the odometry information and time, assuming constant speed.
extern void
viscr_odometry_to_transformation_constant(
    viscr_mat44 & H,
    const viscr_odometry & odometry,
    viscr_float deltaT);


#endif

