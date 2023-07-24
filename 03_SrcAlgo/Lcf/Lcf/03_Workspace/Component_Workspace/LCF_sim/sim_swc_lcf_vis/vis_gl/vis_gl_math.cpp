
#include "vis_gl_math.h"

bool GL::IntersectX( double x0, double y0, double x1, double y1, double x, double y)
{
  x0 -= x;
  x1 -= x;
  y0 -= y;
  y1 -= y;

  if( x0 < 0 && x1 < 0 ||
      y0 > 0 && y1 > 0 ||
      y0 < 0 && y1 < 0)
    return false;

  if( x1 == x0)
    return y0 <= 0 && y1 > 0 || y1 < 0 && y0 >= 0;

  if( y1 == y0)
    return x0 <= 0 && x1 > 0 || x1 < 0 && x0 >= 0;

  double m = ( y1 - y0)/( x1 - x0);
  double b = y0 - m * x0;

  return - b / m > 0;
}
