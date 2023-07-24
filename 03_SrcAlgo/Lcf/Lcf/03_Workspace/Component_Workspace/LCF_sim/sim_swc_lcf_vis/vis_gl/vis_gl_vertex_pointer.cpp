
#include "vis_gl_vertex_pointer.h"
#include "vis_gl_pos.h"
#include "vis_gl_pixel.h"
#include "vis_gl_color.h"
#include "vis_gl_attrib_guard.h"
#include "vis_gl_normal.h"

#include <assert.h>

GL::VertexPointer::VertexPointer( Pos const * pos, int iStride)
: m_bHasColor( false)
, m_bHasNormal( false)
, m_bHasTex( false)
{
  glPushClientAttrib( GL_CLIENT_ALL_ATTRIB_BITS);
  glEnableClientState( GL_VERTEX_ARRAY);
  glDisableClientState( GL_COLOR_ARRAY);
  glDisableClientState( GL_NORMAL_ARRAY);
  glDisableClientState( GL_TEXTURE_COORD_ARRAY);

  glVertexPointer( 3, Pos::GLType, iStride, * pos);
}

GL::VertexPointer::VertexPointer( Pixel const * pixel, int iStride)
: m_bHasColor( false)
, m_bHasNormal( false)
, m_bHasTex( false)
{
  glPushClientAttrib( GL_CLIENT_ALL_ATTRIB_BITS);
  glEnableClientState( GL_VERTEX_ARRAY);
  glDisableClientState( GL_COLOR_ARRAY);
  glDisableClientState( GL_NORMAL_ARRAY);
  glDisableClientState( GL_TEXTURE_COORD_ARRAY);

  glVertexPointer( 2, Pixel::GLType, iStride, *pixel);
}

GL::VertexPointer::~VertexPointer()
{
  glPopClientAttrib();
}

void GL::VertexPointer::AddColor( std::vector<Color> const & vecColor)
{
  glEnableClientState( GL_COLOR_ARRAY);
  glColorPointer( 4, Color::GLType, 0, (float const*) vecColor[0]);
  m_bHasColor = true;
}

void GL::VertexPointer::AddNormal( std::vector<Normal> const & vecNormal)
{
  glEnableClientState( GL_NORMAL_ARRAY);
  glNormalPointer( Normal::GLType, 0, vecNormal[0]);
  m_bHasNormal = true;
}

void GL::VertexPointer::DrawArrays( GLenum mode, GLint first, size_t count) const
{
  GL::AttribGuard attrGuard( GL_ENABLE_BIT);
  if( m_bHasTex)
    glEnable( GL_TEXTURE_2D);
  glDrawArrays( mode, first, (GLsizei) count);
}

void GL::VertexPointer::AddTexCoord( Pixel const * pPixel, int iStride)
{
  glEnableClientState( GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer( 2, Pixel::GLType, iStride, pPixel);
  m_bHasTex = true;
}

void GL::VertexPointer::AddTexCoord( Pos const * pPos, int iStride)
{
  glEnableClientState( GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer( 3, Pos::GLType, iStride, pPos);
  m_bHasTex = true;
}


void GL::VertexPointer::AddTexCoord( std::vector<Pos> const & vecPos, int iStride)
{
  glEnableClientState( GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer( 3, Pos::GLType, iStride, vecPos[0]);
  m_bHasTex = true;
}

void GL::VertexPointer::AddTexCoord( std::vector<Pixel> const & vecPixel, int iStride)
{
  glEnableClientState( GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer( 2, Pixel::GLType, iStride, vecPixel[0]);
  m_bHasTex = true;
}
