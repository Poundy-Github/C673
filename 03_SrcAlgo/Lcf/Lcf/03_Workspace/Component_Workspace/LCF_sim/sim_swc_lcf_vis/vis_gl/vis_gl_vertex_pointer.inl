
#include "vis_gl_normal.h"

namespace GL
{
  inline
  VertexPointer::VertexPointer( Pos const * pos, int iStride)
  : m_bHasColor( false)
  , m_bHasNormal( false)
  {
    glEnableClientState( GL_VERTEX_ARRAY);
    glVertexPointer( 3, GL_FLOAT, iStride, * pos);
  }

  inline
  VertexPointer::VertexPointer( Pixel const * pixel, int iStride)
  : m_bHasColor( false)
  {
    glEnableClientState( GL_VERTEX_ARRAY);
    glVertexPointer( 2, GL_FLOAT, iStride, *pixel);
  }

  inline
  void VertexPointer::AddColor( std::vector<Color> const & vecColor)
  {
    glEnableClientState( GL_COLOR_ARRAY);
    glColorPointer( 4, GL_FLOAT, 0, & vecColor[0].m_fR);
    m_bHasColor = true;
  }

  inline
  void VertexPointer::AddNormal( std::vector<Normal> const & vecNormal)
  {
    glEnableClientState( GL_NORMAL_ARRAY);
    glNormalPointer( GL_FLOAT, 0, vecNormal[0]);
    m_bHasNormal = true;
  }

  inline
  VertexPointer::~VertexPointer()
  {
    glDisableClientState( GL_VERTEX_ARRAY);
    if( m_bHasColor)
      glDisableClientState( GL_COLOR_ARRAY);
    if( m_bHasNormal)
      glDisableClientState( GL_NORMAL_ARRAY);
  }

  inline
  void VertexPointer::DrawArrays( GLenum mode, GLint first, size_t count) const
  {
    glDrawArrays( mode, first, (GLsizei) count);
  }
}
