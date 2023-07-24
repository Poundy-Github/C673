
// $Revision: 1.1 $
// invert correction via formular vu = v * ( 1+ k1 r + k2 * r * r)

uniform double fK1;
uniform double fK2;
uniform vec2 v2Center;


float Cardano( double p, double q)
{
  double u=pow( float( -q/2.0 + sqrt( q*q/4.0 + p*p*p/27.0)), float( 1.0/3.0));
  return float( u-p/(3.0*u));
}

double Dist2UndistTailor( double f, float r2, double fK1, double fK2, float fu)
{
  return f * ( 1 + fK1 * r2 + fK2 * r2 * r2) - fu;
}

double Dist2UndistDerived( double x, double y, double fK1, double fK2)
{
  return 1.0 + fK1*y*y + fK2*y*y*y*y + 3.0*(fK1+2.0*fK2*y*y)*x*x + 5.0*fK2*x*x*x*x;
}

vec2 CameraUndistorted2Distored( vec2 pos)
{
  if( fK2 == 0.0F)
  {
    // if fK1 == 0 an analytic solution is possible with cardano
    if( fK1 != 0.0F)
    {
      // Use Cardano method to solve x(r)=x(r)( 1+k1*r2)
      // Cardano can be used if x*x term is avoided
      pos -= v2Center;
      float r2 = dot( pos, pos);
      dvec2 tmp;
      tmp.x = Cardano( pos.y*pos.y + 1.0/fK1, -pos.x/fK1);
      tmp.y = Cardano( pos.x*pos.x + 1.0/fK1, -pos.y/fK1);
      pos = tmp + v2Center;
    }
  }
  // no analytic solution is possible -> do an approximation
  else
  {
    pos -= v2Center;
    float r2 = dot( pos, pos);
    vec2 p1 = pos;

    for( int i=0; i < 5; i++)
    {
      dvec2 p2;
      p2.x = pos.x - ( Dist2UndistTailor( p1.x, r2, fK1, fK2, pos.x) / Dist2UndistDerived( p1.x, p1.y, fK1, fK2));
      p2.y = pos.y - ( Dist2UndistTailor( p1.y, r2, fK1, fK2, pos.y) / Dist2UndistDerived( p1.y, p1.x, fK1, fK2));
      p1 = p2;
    }

    pos = p1 + v2Center;
  }
  return pos;
}

void main()
{
  vec4 p4d = ftransform();
  vec2 p2d = vec2( p4d.x, p4d.y);
  p2d = CameraUndistorted2Distored( p2d);
  gl_Position = vec4( p2d, p4d.z, p4d.w);
  gl_FrontColor = gl_Color;
  gl_BackColor = gl_Color;
}
