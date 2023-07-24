
#include "vis_gl_pixel_tri.h"

GL::PixelTri::PixelTri()
{}

GL::PixelTri::PixelTri( GL::Pixel const & p0, GL::Pixel const & p1, GL::Pixel const & p2)
: m_p0( p0)
, m_p1( p1)
, m_p2( p2)
{}
