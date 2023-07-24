#include <cmath>
#include <viscr_odometry.hpp>

/// Minimal rotation for odometry computations
static const viscr_float VISCR_ODOMETRY_MINALPHA = 0.000001F;

/// Minimal speed in m/s for odometry computations
static const viscr_float VISCR_ODOMETRY_MINSPEED = 0.01F;

void
viscr_odometry_to_transformation_constant(
    viscr_mat44 & H,
    const viscr_odometry & odometry,
    viscr_float const deltaT)
{
  /* movement to right and front in this timestep*/
  viscr_float dr; 
  viscr_float df; 
  /* turn taken in this timestep*/
  viscr_float alpha = odometry.yawRate * deltaT;
  
  // Too slow, didn't move
  if( odometry.v < VISCR_ODOMETRY_MINSPEED) 
  {
    viscr_mat_identity( H.m);
  }
  else
  {
    /* ~CodeReview ~ID:1c40410fd3042b874bb5c5eba2c012aa ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:Explain transform is for a point in world CS from time (t) to time (t-1) */
    /* straight ahead*/
    if( std::fabsf(alpha) < VISCR_ODOMETRY_MINALPHA)
    {
      df = odometry.v * deltaT;
      dr = 0.0F;
    }
    else
    {
      // Radius of the driven circle
      viscr_float R = odometry.v / odometry.yawRate;
      df = R * std::sinf(alpha);
      dr = R * (1.0F - std::cosf(alpha));
    }

    // Turn into transformation
    viscr_mat_zero( H.m);

    viscr_float cosa = std::cosf( alpha);
    viscr_float sina = std::sinf( alpha);
    viscr_float H00 = cosa;
    viscr_float H01 = -sina;
    viscr_float H10 = sina;
    viscr_float H11 = cosa;

    H.m(0U, 0U) = H00;
    H.m(0U, 1U) = H01;
    H.m(1U, 0U) = H10;
    H.m(1U, 1U) = H11;
    H.m(2U, 2U) = 1.0F;

    H.m(0U, 3U)= df;//df*H00 + dr*H01; -- Bug from Daimler
    H.m(1U, 3U)= dr;//df*H10 + dr*H11; -- Bug from Daimler

    H.m(3U, 3U)= 1.0F;
  }
}

