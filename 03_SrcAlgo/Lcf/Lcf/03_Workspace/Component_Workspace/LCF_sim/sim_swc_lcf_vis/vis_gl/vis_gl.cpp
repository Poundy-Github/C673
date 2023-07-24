
#include <windows.h>
extern "C" {
  #include "glew.c"
}
#include "vis_gl.h"

#include <windows.h>
#include "GL/Glu.h"

#include <algorithm>
#include <functional>
#include <assert.h>
#include <math.h>
#include <io.h>
#include <fcntl.h>
#include <math.h>

#pragma comment (lib, "GLu32.lib")
#pragma comment ( lib, "Opengl32.lib")

// #include "sim_gdvfont_ifc.h"
// #include "sim_swc_gdv_ifc.h"
// #include "sim_rendercontext_ifc.h"

#undef DrawText

#define open _open
#define O_RDONLY _O_RDONLY

#define M_PI       3.14159265358979323846 //?? problem with inclusion of math.h

using namespace std;
using namespace GL;

#ifndef GL_DEBUG
#  define GL_DEBUG 0
#endif

GLint AttribGuard::iMaxAttribStack = 0;
GLint ClientAttribGuard::iMaxStack = 0;


#if _MSC_VER < 1800

// Visual C++ 2005 doesn't newest support math.h -> maybe newer one.

namespace
{
  double rint( double v)
  {
    if( v >= 0)
      return ceil( v);
    else
      return floor( v);
  }
  float rint( float v)
  {
    if( v >= 0)
      return static_cast<float>( ceil( v));
    else
      return static_cast<float>( floor( v));
  }
}

#endif

void GL::CheckError()
{
#if GL_DEBUG
  GLenum rc = glGetError();
  switch( rc)
  {
  case GL_NO_ERROR: return;
  case GL_INVALID_ENUM: throw "GL_INVALID_ENUM";
  case GL_INVALID_VALUE: throw "GL_INVALID_VALUE";
  case GL_INVALID_OPERATION: throw "GL_INVALID_OPERATION";
  case GL_STACK_OVERFLOW: throw "GL_STACK_OVERFLOW";
  case GL_STACK_UNDERFLOW: throw "GL_STACK_UNDERFLOW";
  case GL_OUT_OF_MEMORY: throw "GL_OUT_OF_MEMORY";
  default: assert( 0 && "never reach"); throw "unexpected glGetError()";
  }
#endif
}

void GL::Draw( ScreenQuad const & rect, Color const & color)
{
  GL::PixelRect r = UnProject( rect);
  Draw( r, color);
}

void GL::Draw( Pos const & point, float fSize, Color const & color)
{
  glPointSize( fSize);
  glBegin( GL_POINTS);
    Color4( color);
    Vertex( point);
  glEnd();
  CheckError();
}

void GL::Draw( vector<Pos> const & points, float fSize, Color const & color)
{
  if( points.empty())
    return;
  glPointSize( fSize);
  Color4( color);
  VertexPointer vertexPointer( & points[0]);
  glDrawArrays( GL_POINTS, 0, (GLsizei) points.size());
  CheckError();
}

void GL::Draw( GLenum mode, vector<Pos> const & points, float fSize, Color const & color)
{
  if( points.empty())
    return;
  glPointSize( fSize);
  Color4( color);
  VertexPointer vertexPointer( & points[0]);
  glDrawArrays( mode, 0, (GLsizei) points.size());
  CheckError();
}
void GL::Draw( std::vector<Rect> const & vecRect, Color const & color)
{
  if( vecRect.empty())
    return;
  Color4( color);
  VertexPointer vertexPointer( vecRect[0]);
  vertexPointer.DrawArrays( GL_QUADS, 0, static_cast<GLsizei>( 4 * vecRect.size()));
  CheckError();
}

void GL::Draw( Pixel const & point, float fPointSize, Color const & color)
{
  glPointSize( fPointSize);
  glBegin( GL_POINTS);
    Color4( color);
    Vertex( point);
  glEnd();
}

void GL::Draw( std::vector<Rect> const & vecRect, float fLineSize, Color const & color)
{
  if( vecRect.empty())
    return;
  AttribGuard attrGuard;
  glLineWidth( fLineSize);
  Color4( color);
  glPolygonMode( GL_FRONT_AND_BACK, GL_LINE);
  VertexPointer vertexPointer( vecRect[0]);
  glDisableClientState( GL_TEXTURE_COORD_ARRAY);
  glDisableClientState( GL_COLOR_ARRAY);
  glDisableClientState( GL_EDGE_FLAG_ARRAY);
  glDisableClientState( GL_INDEX_ARRAY);
  glDisableClientState( GL_NORMAL_ARRAY );
  glDrawArrays( GL_QUADS, 0, static_cast<GLsizei>( 4 * vecRect.size()));
  CheckError();
}

void GL::Draw( Rect const & rect, Color const & color)
{
  glBegin( GL_QUADS);
    Color4( color);
    Vertex( rect.m_p00);
    Vertex( rect.m_p01);
    Vertex( rect.m_p11);
    Vertex( rect.m_p10);
  glEnd();
  CheckError();
}

void GL::Draw( Rect const & rect, Rect const & texCoord)
{
#ifdef _DEBUG
  GLint iTextureEnabled = 0;
  glGetIntegerv( GL_TEXTURE_2D, & iTextureEnabled);
  assert( iTextureEnabled);
#endif
  glBegin( GL_QUADS);
    Color3( GL::Color::white);
    TexCoord( texCoord.m_p00);
    Vertex( rect.m_p00);
    TexCoord( texCoord.m_p01);
    Vertex( rect.m_p01);
    TexCoord( texCoord.m_p11);
    Vertex( rect.m_p11);
    TexCoord( texCoord.m_p10);
    Vertex( rect.m_p10);
  glEnd();
  CheckError();
}

void GL::Draw( std::vector<GL::Rect> const & vecRect, std::vector<GL::Rect>  const & vecTexCoord)
{
  if( vecRect.empty())
    return;

  VertexPointer vp( vecRect[0]);
  vp.AddTexCoord( vecTexCoord[0]);
  vp.DrawArrays( GL_QUADS, 0, vecRect.size() * 4);
}

void GL::Draw( std::vector<GL::Rect> const & vecRect, std::vector<GL::PixelRect>  const & vecTexCoord)
{
  if( vecRect.empty())
    return;

  VertexPointer vp( vecRect[0]);
  vp.AddTexCoord( vecTexCoord[0]);
  vp.DrawArrays( GL_QUADS, 0, vecRect.size() * 4);
}

void GL::Draw( Rect const & rect)
{
#ifdef _DEBUG
  GLint iTextureEnabled = 0;
  glGetIntegerv( GL_TEXTURE_2D, & iTextureEnabled);
  assert( iTextureEnabled);
#endif
  glBegin( GL_QUADS);
    Color4( GL::Color::white);
    glTexCoord2f( 0, 0);
    Vertex( rect.m_p00);
    glTexCoord2f( 0, 1);
    Vertex( rect.m_p01);
    glTexCoord2f( 1, 1);
    Vertex( rect.m_p11);
    glTexCoord2f( 1, 0);
    Vertex( rect.m_p10);
  glEnd();
  CheckError();
}

void GL::Draw( Rect const & rect, float fLineSize, Color const & color)
{
  glLineWidth( fLineSize);
  glBegin( GL_LINE_LOOP);
    Color4( color);
    Vertex( rect.m_p00);
    Vertex( rect.m_p01);
    Vertex( rect.m_p11);
    Vertex( rect.m_p10);
  glEnd();
  CheckError();
}

void GL::Draw( PixelLine const & line, float fLineSize, Color const & color)
{
  glLineWidth( fLineSize);
  glBegin( GL_LINES);
    Color4( color);
    Vertex( line.m_p0);
    Vertex( line.m_p1);
  glEnd();
  CheckError();
}

void GL::Draw( std::vector<GL::Pixel> const & vecPixel, float fPointSize, Color const & color)
{
  if( vecPixel.empty())
    return;
  glPointSize( fPointSize);
  GL::Color4( color);
  VertexPointer vp( & vecPixel[0]);
  vp.DrawArrays( GL_POINTS, 0, vecPixel.size());
}

void GL::Draw( PixelTri const & triangle, Color const & color)
{
  glBegin( GL_TRIANGLES);
    Color4( color);
    Vertex( triangle.m_p0);
    Vertex( triangle.m_p1);
    Vertex( triangle.m_p2);
  glEnd();
  CheckError();
}

void GL::Draw( PixelRect const & rect)
{
#ifdef _DEBUG
  GLint iTextureEnabled = 0;
  glGetIntegerv( GL_TEXTURE_2D, & iTextureEnabled);
  assert( iTextureEnabled);
#endif
  glBegin( GL_QUADS);
    Color3( GL::Color::white);
    glTexCoord2d( 0, 0);
    Vertex( rect.m_p00);
    glTexCoord2d( 0, 1);
    Vertex( rect.m_p01);
    glTexCoord2d( 1, 1);
    Vertex( rect.m_p11);
    glTexCoord2d( 1, 0);
    Vertex( rect.m_p10);
  glEnd();
  CheckError();
}

void GL::Draw( PixelRect const & rect, Color const & color)
{
  Color4( color);
  glBegin( GL_QUADS);
    Vertex( rect.m_p00);
    Vertex( rect.m_p01);
    Vertex( rect.m_p11);
    Vertex( rect.m_p10);
  glEnd();
  CheckError();
}

void GL::Draw( Line const & line, float fSize, Color const & color)
{
  glLineWidth( fSize); 
  glBegin( GL_LINES);
    Color4( color);
    Vertex( line.m_p0);
    Vertex( line.m_p1);
  glEnd();
  CheckError();
}

void GL::Draw( vector<Line> const & lines, float fSize, Color const & color)
{
  if( lines.empty())
    return;
  glLineWidth( fSize);
  Color4( color);
  VertexPointer vertexPointer( lines[0]);
  vertexPointer.DrawArrays( GL_LINES, 0, (GLsizei) lines.size() * 2);
  CheckError();
}

void GL::Draw( vector<Tri> const & vecTri, Color const & color)
{
  if( vecTri.empty())
    return;

  Color4( color);
  VertexPointer vertexPointer( vecTri[0]);
  vertexPointer.DrawArrays( GL_TRIANGLES, 0, vecTri.size() * 3);
  CheckError();
}

void GL::DrawLineStrip( std::vector<Pos> const & lines, float fLineSize, Color const & color)
{
  if( lines.empty())
    return;

  glLineWidth( fLineSize);
  Color4( color);
  GL::VertexPointer vertexGuard( & lines[0]);
  vertexGuard.DrawArrays( GL_LINE_STRIP, 0, (GLsizei) lines.size());
  CheckError();
}

void GL::DrawQuadStrip( std::vector<GL::Pos> const & vecPos, Color const & color, bool bEnableTexture)
{
  if( vecPos.empty())
    return;
  Color4( color);
  GL::VertexPointer vp( & vecPos[0]);
  if( bEnableTexture)
    vp.AddTexCoord( vecPos);
  vp.DrawArrays( GL_QUAD_STRIP, 0, vecPos.size());
  CheckError();
}

void GL::DrawLineStrip( std::vector<Pixel> const & linePositions, float fLineSize, Color const & color)
{
  if( linePositions.empty())
    return;

  glLineWidth( fLineSize);
  Color4( color);
  GL::VertexPointer vertexGuard( & linePositions[0]);
  vertexGuard.DrawArrays( GL_LINE_STRIP, 0, (GLsizei) linePositions.size());
  CheckError();
}

void GL::DrawLineStrip( std::vector<std::vector<Pos> > const & lines, float fLineSize, Color const & color)
{
  for( size_t i=0; i < lines.size(); i++)
    DrawLineStrip( lines[i], fLineSize, color);
}

Pixel GL::GetRasterPos()
{
  float f4[4];
  glGetFloatv( GL_CURRENT_RASTER_POSITION, f4);
  CheckError();
  return Pixel( f4[0], f4[1]);
}

GL::Screen GL::Project( GL::Pos const & glPos)
{
  GLdouble  dModelMat16[4][4];
  GLdouble  dProjMat16[4][4];
  GLint     iViewport[2][2];
  glGetDoublev( GL_MODELVIEW_MATRIX, dModelMat16[0]);
  glGetDoublev( GL_PROJECTION_MATRIX, dProjMat16[0]);
  glGetIntegerv( GL_VIEWPORT, iViewport[0]);

  GLdouble x, y, z;
  gluProject( glPos.m_x, glPos.m_y, glPos.m_z
            , dModelMat16[0], dProjMat16[0], iViewport[0]
            , & x, & y, & z);

  CheckError();

  return GL::Screen( (int) rint( x), (int) rint( y));
}

GL::ScreenQuad GL::Project( GL::Rect const & glRect)
{
  GL::Screen s00 = Project( glRect.m_p00);
  GL::Screen s01 = Project( glRect.m_p01);
  GL::Screen s10 = Project( glRect.m_p10);
  GL::Screen s11 = Project( glRect.m_p11);
  return GL::ScreenQuad( s00, s01, s11, s10);
}

std::vector<GL::ScreenQuad> GL::Project( std::vector<GL::Rect> const & vecRect)
{
  std::vector<GL::ScreenQuad> ret;
  ret.resize( vecRect.size());
  for( size_t i=0; i < vecRect.size(); i++)
    ret[i] = GL::Project( vecRect[i]);
  return ret;
}


GL::Screen GL::Project( GL::Pixel const & glPixel)
{
  GLdouble  dModelMat16[4][4];
  GLdouble  dProjMat16[4][4];
  GLint     iViewport[2][2];
  glGetDoublev( GL_MODELVIEW_MATRIX, dModelMat16[0]);
  glGetDoublev( GL_PROJECTION_MATRIX, dProjMat16[0]);
  glGetIntegerv( GL_VIEWPORT, iViewport[0]);

  GLdouble x, y, z;
  gluProject( glPixel.m_x, glPixel.m_y, 0
            , dModelMat16[0], dProjMat16[0], iViewport[0]
            , & x, & y, & z);

  CheckError();

  return GL::Screen( (int) rint( x), (int) rint( y));
}

GL::Pixel GL::UnProject( GL::Screen const & glScreenPos, double * dProjMat16, double * dModelMat16, GLint * dViewport4, float fZ)
{
  GLdouble x, y, z;
  gluUnProject( glScreenPos.m_x, glScreenPos.m_y, fZ
              , dModelMat16, dProjMat16, dViewport4
              , & x, & y, & z);

  CheckError();

  return GL::Pixel( (float) x, (float) y);
}

GL::Pixel GL::UnProject( GL::Screen const & glScreenPos, float fZ)
{
  GLdouble  dModelMat16[4][4];
  GLdouble  dProjMat16[4][4];
  GLint     iViewport[2][2];
  glGetDoublev( GL_MODELVIEW_MATRIX, dModelMat16[0]);
  glGetDoublev( GL_PROJECTION_MATRIX, dProjMat16[0]);
  glGetIntegerv( GL_VIEWPORT, iViewport[0]);

  return UnProject( glScreenPos, dProjMat16[0], dModelMat16[0], iViewport[0], fZ);
}

GL::PixelRect GL::UnProject( GL::ScreenQuad const & glScreenQuad, float fZ)
{
  GLdouble  dModelMat16[4][4];
  GLdouble  dProjMat16[4][4];
  GLint     iViewport[2][2];
  glGetDoublev( GL_MODELVIEW_MATRIX, dModelMat16[0]);
  glGetDoublev( GL_PROJECTION_MATRIX, dProjMat16[0]);
  glGetIntegerv( GL_VIEWPORT, iViewport[0]);

  PixelRect ret;
  ret.m_p00 = UnProject( glScreenQuad.m_p00, dProjMat16[0], dModelMat16[0], iViewport[0], fZ);
  ret.m_p01 = UnProject( glScreenQuad.m_p01, dProjMat16[0], dModelMat16[0], iViewport[0], fZ);
  ret.m_p10 = UnProject( glScreenQuad.m_p10, dProjMat16[0], dModelMat16[0], iViewport[0], fZ);
  ret.m_p11 = UnProject( glScreenQuad.m_p11, dProjMat16[0], dModelMat16[0], iViewport[0], fZ);
  return ret;
}


#ifdef VIS_GL_USE_MTS
void GL::DrawText2D( Pixel const & glPixelPos, Color const & color, std::string const & sText, IGDVFont& rFont)
{
  // Call of RenderText can always make something nasty
  AttribGuard guard;
  MatrixGuard matGuard( GL_PROJECTION);
  MatrixGuard modGuard( GL_MODELVIEW);
  glPushClientAttrib( GL_CLIENT_ALL_ATTRIB_BITS);

  rFont.BeginRender2D();

  rFont.SetTextColor( color.RedFloat(), color.GreenFloat(), color.BlueFloat());
  rFont.RenderText( sText.c_str(), glPixelPos.m_x, glPixelPos.m_y);

  rFont.EndRender2D();

  glPopClientAttrib();

  CheckError();
}

void GL::DrawText2D( Screen const & glscreenPos, Color const & color, std::string const & sText, IGDVFont& rFont)
{
  DrawText2D( UnProject( glscreenPos), color, sText, rFont);
}

#endif
GLint MatrixGuard::iMaxProjStack = 0;
GLint MatrixGuard::iMaxModelStack = 0;
GLint MatrixGuard::iMaxTexStack = 0;

template<class T>
std::vector<T> DoubleArray( std::vector<T> const & v)
{
  std::vector<T> ret;
  ret.reserve( v.size() * 2);
  for( size_t i=0; i < v.size(); i++)
  {
    ret.push_back( v[i]);
    ret.push_back( v[i]);
  }
  return ret;
}

template<class T>
std::vector<T> QuadArray( std::vector<T> const & v)
{
  std::vector<T> ret;
  ret.reserve( v.size() * 4);
  for( size_t i=0; i < v.size(); i++)
  {
    ret.push_back( v[i]);
    ret.push_back( v[i]);
    ret.push_back( v[i]);
    ret.push_back( v[i]);
  }
  return ret;
}

void GL::Draw( std::vector<PixelLine> const & pixelLine, float fLineSize, std::vector<GL::Color> const & vecColor)
{
  if( pixelLine.empty())
    return;

  glLineWidth( fLineSize);

  VertexPointer vp( pixelLine[0]);

  if( pixelLine.size() == vecColor.size())
  {
    std::vector<GL::Color> tmpColor = DoubleArray( vecColor);
    vp.AddColor( tmpColor);
    vp.DrawArrays( GL_LINES, 0, (int) tmpColor.size());
  }
  else if( pixelLine.size() * 2 == vecColor.size())
  {
    vp.AddColor( vecColor);
    vp.DrawArrays( GL_LINES, 0, (int) vecColor.size());
  }
  else
  {
    assert( 0 && "pixelLine and vecColor has wrong size");
  }
}

void GL::Draw( PixelRect const & rect, float fLineSize, Color const & color)
{
  glLineWidth( fLineSize);
  glBegin( GL_LINE_LOOP);
    Color4( color);
    Vertex( rect.m_p00);
    Vertex( rect.m_p01);
    Vertex( rect.m_p11);
    Vertex( rect.m_p10);
  glEnd();
#if 0
  VertexPointer vertexPointer( rect);
  vertexPointer.DrawArrays( GL_LINES, 0, 4);
#endif
}

void GL::Draw( std::vector<Rect> const & vecRect, float fLineSize, std::vector<Color> const & vecColor)
{
  if( vecRect.empty())
    return;

  glLineWidth( fLineSize);

  VertexPointer vp( vecRect[0]);
  if( vecRect.size() == vecColor.size())
  {
    vector<GL::Color> tmpColor = QuadArray( vecColor);
    vp.AddColor( tmpColor);
    vp.DrawArrays( GL_QUADS, 0, (GLsizei) vecColor.size());
  }
  else if( vecRect.size() == vecColor.size() * 4)
  {
    vp.AddColor( vecColor);
    vp.DrawArrays( GL_QUADS, 0, (GLsizei) vecColor.size());
  }
  else
    assert( 0 && "pixelLine and vecColor has wrong size");
}

void GL::Draw( std::vector<GL::PixelRect> const & vecRect, float fLineSize, std::vector<GL::Color> const & vecColor)
{
  assert( vecRect.size() == vecColor.size());

  if( vecRect.empty())
    return;

  glLineWidth( fLineSize);
  VertexPointer vp( vecRect[0]);
  vector<GL::Color> tmpColor = QuadArray( vecColor);
  vp.AddColor( tmpColor);
  vp.DrawArrays( GL_QUADS, 0, vecRect.size() * 4);
}

void GL::Draw( std::vector<GL::Pixel> const & vecPixel, float fPointSize, std::vector<GL::Color> const & vecColor)
{
  if( vecPixel.empty())
    return;

  glPointSize( fPointSize);
  VertexPointer vp( & vecPixel[0]);
  vp.AddColor( vecColor);
  vp.DrawArrays( GL_POINTS, 0, vecPixel.size());
}

void GL::Draw( std::vector<Rect> const & vecRect, std::vector<Color> const & vecColor)
{
  if( vecRect.empty())
    return;

  VertexPointer vp( vecRect[0]);
  if( vecRect.size() == vecColor.size())
  {
    vector<GL::Color> tmpColor = QuadArray( vecColor);
    vp.AddColor( tmpColor);
    vp.DrawArrays( GL_QUADS, 0, (GLsizei) tmpColor.size());
  }
  else if( vecRect.size() * 4 == vecColor.size())
  {
    vp.AddColor( vecColor);
    vp.DrawArrays( GL_QUADS, 0, (GLsizei) vecColor.size());
  }
  else
    assert( 0 && "pixelLine and vecColor has wrong size");
}


void GL::Draw( std::vector<Line> const & vecLines, float fSize, std::vector<Color> const & vecColor)
{
  if( vecLines.empty())
    return;

  glLineWidth( fSize);

  if( vecLines.size() == vecColor.size())
  {
    std::vector<GL::Color> tmpColor = DoubleArray( vecColor);
    VertexPointer vp( vecLines[0]);
    vp.AddColor( tmpColor);
    vp.DrawArrays( GL_LINES, 0, (int) tmpColor.size());
  }
  else if( vecLines.size() * 2 == vecColor.size())
  {
    VertexPointer vp( vecLines[0]);
    vp.AddColor( vecColor);
    vp.DrawArrays( GL_LINES, 0, (int) vecColor.size());
  }
}

void GL::Draw( std::vector<PixelLine> const & pixelLine, float fLineSize, GL::Color const & color)
{
  if( pixelLine.empty())
    return;

  glLineWidth( fLineSize);
  Color4( color);
  VertexPointer vp( pixelLine[0]);
  vp.DrawArrays( GL_LINES, 0, (int) pixelLine.size() * 2);
}

void GL::Draw( std::vector<Pos> const & points, float fPointSize, std::vector<Color> const & vecColor)
{
  if( points.empty())
    return;
  assert( points.size() == vecColor.size());

  glPointSize( fPointSize);
  VertexPointer vp( & points[0]);
  vp.AddColor( vecColor);
  vp.DrawArrays( GL_POINTS, 0, (GLsizei) points.size());
}

Normal GL::CalcNormal( Line const & l1, Line const & l2)
{
  assert( l1.m_p0 == l2.m_p0);

  Pos p1 = l1.m_p1 - l1.m_p0;
  Pos p2 = l2.m_p1 - l2.m_p0;

  return Normal( GL::Pos::Cross( p1, p2));
}

Normal GL::CalcZNormal( Line const & line)
{
  Pos p = line.m_p1 - line.m_p0;
  Normal n = Normal( GL::Pos::Cross( p, Pos( 0, 0, -1)));
  Pos pn( n.m_nx, n.m_ny, n.m_nz);
  return GL::Normal( GL::Pos::Cross( p, pn));
}

std::vector<Normal> GL::CalcZNormal( std::vector<Line> const & vecLine)
{
  std::vector<Normal> vecN;
  vecN.reserve( vecLine.size() * 2);

  vecN.push_back( CalcZNormal( vecLine[0]));

  for( size_t i=1; i < vecLine.size(); i++)
  {
    Normal n1 = CalcZNormal( vecLine[i-1]);
    Normal n2 = CalcZNormal( vecLine[i-0]);
    Normal n = ( n1 + n2 ) / 2;
    vecN.push_back( n);
    vecN.push_back( n);
  }
  return vecN;
}

void GL::Scale( Pixel const & scale)
{
  glScaled( scale.m_x, scale.m_y, 0);
}

GL::Screen GL::GetViewport()
{
  GLint vp[2][2];
  glGetIntegerv( GL_VIEWPORT, vp[0]);
  GL::CheckError();
  return GL::Screen( vp[1][0], vp[1][1]);
}

GL::Screen GL::GetClientRect( HWND hwnd)
{
  assert( hwnd);
  RECT r;
  BOOL rc = GetClientRect( hwnd, & r);
  assert( rc);
  return Screen( r.right, r.bottom);
}

GL::Screen GL::WindowPos2GLScreen( POINT point, HWND hwnd)
{
  RECT r;
  GetClientRect( hwnd, & r);
  return GL::Screen( point.x, r.bottom - point.y);
}

void GL::ModelViewScaleTranslateTo( Pixel const & originPos, Pixel const & originExt, Pixel const & newOrigin, Pixel const & newExt)
{
  glMatrixMode( GL_MODELVIEW);

  Translate( originPos);
  Scale( originExt);
  Scale( 1.0F / newExt);
  Translate( - newOrigin);
}


void GL::Color3( Color const & color)
{
  glColor3fv( color);
}

void GL::Color4( Color const & color)
{
  glColor4fv( color);
}

void GL::Vertex( Pos const & glPos)
{
  glVertex3dv( glPos);
}

void GL::Vertex( Pixel const & glPixel)
{
  // glVertex2dv( glPixel);
  glVertex2fv( glPixel);
}

void GL::TexCoord( Pos const & glPos)
{
  glTexCoord3f( static_cast<float>( glPos.m_x), static_cast<float>( glPos.m_y), static_cast<float>( glPos.m_z));
}

void GL::TexCoord( Pixel const & glPixel)
{
  glTexCoord2f( glPixel.m_x, glPixel.m_y);
}

void GL::Translate( Pixel const & offset)
{
  glTranslated( offset.m_x, offset.m_y, 0);
}

void GL::Translate( Pos const & offset)
{
  glTranslated( offset.m_x, offset.m_y, offset.m_z);
}

void GL::LightSpotDirection( int iLightNum, Normal const & n)
{
  float f3[3];
  f3[0] = static_cast<float>( n.m_nx);
  f3[1] = static_cast<float>( n.m_ny);
  f3[2] = static_cast<float>( n.m_nz);
  glLightfv( GL_LIGHT0 + iLightNum, GL_SPOT_DIRECTION, f3);
}

void GL::LightPosition( int iLightNum, Pos const & p)
{
  float f3[3];
  f3[0] = static_cast<float>( p.m_x);
  f3[1] = static_cast<float>( p.m_y);
  f3[2] = static_cast<float>( p.m_z);
  glLightfv( GL_LIGHT0 + iLightNum, GL_POSITION, f3);
}

void GL::LightAmbient( int iLightNum, Color const & clr)
{
  glLightfv( GL_LIGHT0 + iLightNum, GL_AMBIENT, clr);
}

void GL::LightDiffuse( int iLightNum, Color const & clr)
{
  glLightfv( GL_LIGHT0 + iLightNum, GL_DIFFUSE, clr);
}

void GL::LightSpecular( int iLightNum, Color const & clr)
{
  glLightfv( GL_LIGHT0 + iLightNum, GL_SPECULAR, clr);
}

GL::Pos GL::GetDirPoint( GL::Pos const & p1, GL::Pos const & pDirection, double fLength)
{
  GL::Pos norDir = ( pDirection - p1 ).GetNormalised();
  return p1 + ( norDir  * fLength);
}

void GL::Project2AutoSAR()
{
  GLfloat f16[4][4];
  for( int i=0; i < sizeof( f16) / sizeof( f16[0][0]); i++)
  {
    (&f16[0][0])[i] = 0;
  }
  f16[0][2] = -1;
  f16[1][0] = -1;
  f16[2][1] =  1;
  f16[3][3] =  1;
  glMultMatrixf( f16[0]);
}

void GL::ClearColor( Color const & color)
{
  glClearColor( color.RedFloat(), color.GreenFloat(), color.BlueFloat(), color.AlphaFloat());
}

static void readok( int fd, void * vp, int iSize)
{
  int rc = read( fd, vp, iSize);
  if( rc != iSize)
    throw "error reading file";
}

int GL::CreateTextureFromFile( char const * cBmpFile)
{
  GLuint iTexture = 0;
  Bitmap bmp( cBmpFile);
  glGenTextures( 1, & iTexture);
  if( iTexture == 0)
    throw "invalid texuture id -> set current context";
  glBindTexture( GL_TEXTURE_2D, iTexture);
  bmp.TexImage();
  glBindTexture( GL_TEXTURE_2D, 0);

  return iTexture;
}

void GL::MultMatrix( Mat const & mat)
{
  glMultMatrixd( mat.GetTransposed().m_a[0]);
}

void GL::LoadMatrix( Mat const & mat)
{
  glLoadMatrixd( mat.GetTransposed().m_a[0]);
}

Mat GL::GetProjectionMatrix()
{
  Mat m;
  glGetDoublev( GL_PROJECTION_MATRIX, m.m_a[0]);
  return m.GetTransposed();
}

Mat GL::GetModelViewMatrix()
{
  Mat m;
  glGetDoublev( GL_MODELVIEW_MATRIX, m.m_a[0]);
  return m.GetTransposed();
}

Mat GL::GetAutoSARMat( GL::Pos const & carPos, double dAzimuthX)
{
  return Mat::RotateZ( - dAzimuthX) * Mat::Translate( - carPos);
}

Mat GL::OrthoMat( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
  double tx = - ( right + left)/(right - left);
  double ty = - ( top + bottom)/(top - bottom);
  double tz = - ( zFar + zNear)/(zFar - zNear);

  double m[4][4];
  for( int i=0;i < 16; i++)
    (&m[0][0])[i] = 0;
  m[0][0] = 2/(right - left);
  m[1][1] = 2/(top-bottom);
  m[2][2] = 2/(zFar-zNear);
  m[0][3] = tx;
  m[1][3] = ty;
  m[2][3] = tz;
  m[3][3] = -1;

  return GL::Mat( m[0]);
}

Mat GL::OrthoInvMat( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
  double tx = - ( right + left)/(right - left);
  double ty = - ( top + bottom)/(top - bottom);
  double tz = - ( zFar + zNear)/(zFar - zNear);

  double m[4][4];
  for( int i=0;i < 16; i++)
    (&m[0][0])[i] = 0;
  m[0][0] = (right - left)/2;
  m[1][1] = (top-bottom)/2;
  m[2][2] = (zFar-zNear)/2;
  m[0][3] = tx * m[0][0];
  m[1][3] = ty * m[1][1];
  m[2][3] = tz * m[2][2];
  m[3][3] = -1;

  return GL::Mat( m[0]);
}

Mat GL::GetViewportMat( int x, int y, int width, int height)
{
  double m[4][4];
  for( int i=0; i < 16; i++)
    (&m[0][0])[i] = 0;
  m[0][0] = width/2;
  m[1][1] = height/2;
  m[2][2] = 1;
  m[0][3] = width/2+x;
  m[1][3] = height/2+y;
  m[3][3] = 1;
  return Mat( m[0]);
}

Mat GL::GetViewportMatInv( int x, int y, int width, int height)
{
  double m[4][4];
  for( int i=0; i < 16; i++)
    (&m[0][0])[i] = 0;
  m[0][0] = 2./width;
  m[1][1] = 2./height;
  m[2][2] = 1;
  m[0][3] = - ( width/2.+x) * m[0][0];
  m[1][3] = - ( height/2.+y) * m[1][1];
  m[3][3] = 1;
  return Mat( m[0]);
}

void GL::BindTexture2D( GLuint texture)
{
  glBindTexture( GL_TEXTURE_2D, texture);
  GL::CheckError();
}

void GL::TexParameter2D( GLenum pname, GLint param)
{
  glTexParameteri( GL_TEXTURE_2D, pname, param);
  GL::CheckError();
}

void GL::TexParameter2D( GLenum pname, GLfloat param)
{
  glTexParameterf( GL_TEXTURE_2D, pname, param);
  GL::CheckError();
}

GLuint GL::GenTexture()
{
  GLuint iTexture = 0;
  glGenTextures( 1, & iTexture);
  assert( iTexture != 0);
  GL::CheckError();
  return iTexture;
}

#ifdef GL_ARB_framebuffer_object
GLuint GL::GenFramebuffer()
{
  GLuint fb;
  glGenFramebuffers( 1, & fb);
  GL::CheckError();
  return fb;
}

void GL::DeleteFramebuffer( GLuint fb)
{
  glDeleteFramebuffers( 1, & fb);
  GL::CheckError();
}

void GL::BindFramebuffer( GLuint framebuffer)
{
  glBindFramebuffer( GL_FRAMEBUFFER, framebuffer);
  GL::CheckError();
}

void GL::FramebufferTexture2D( GLenum attachment, GLuint texture, GLint level)
{
  glFramebufferTexture2D( GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture, level);
  GL::CheckError();
}

namespace
{
  GLenum GetFormat( GLint internalFormat)
  {
    switch( internalFormat)
    {
    case 3: return GL_RGB;
    case 4: return GL_RGBA;
    case GL_RGBA16: return GL_RGBA;
    case GL_RGB16: return GL_RGB;
    default:
      assert( 0 && "never reach");
      throw "never reach";
    }
  }
}

void GL::TexCreateMipmaps2D( int iTexture, int iMaxLevel, int iMinLevel)
{
  if( iMinLevel >= iMaxLevel)
    return;

  {
    GLint iProgramUsed;
    GL::Get( GL_CURRENT_PROGRAM, & iProgramUsed);
    assert( iProgramUsed == 0);

    MatrixGuard texGuard( GL_TEXTURE);
    glLoadIdentity();
    MatrixGuard model( GL_MODELVIEW);
    glLoadIdentity();
    MatrixGuard prj( GL_PROJECTION);
    glLoadIdentity();

    GLint oldTexture = 0;
    GL::Get( GL_TEXTURE_BINDING_2D, & oldTexture);

    //------  texture section  ---------------

    GL::BindTexture2D( iTexture);

    GLint x, y, internalFormat;
    glGetTexLevelParameteriv( GL_TEXTURE_2D, iMinLevel, GL_TEXTURE_WIDTH, & x);
    glGetTexLevelParameteriv( GL_TEXTURE_2D, iMinLevel, GL_TEXTURE_HEIGHT, & y);
    glGetTexLevelParameteriv( GL_TEXTURE_2D, iMinLevel, GL_TEXTURE_INTERNAL_FORMAT, & internalFormat);
    x /= 2;
    y /= 2;

    glTexImage2D( GL_TEXTURE_2D, iMinLevel + 1, internalFormat, x, y, 0, GetFormat( internalFormat), GL_UNSIGNED_BYTE, NULL);

    GL::TexParameter2D( GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    GL::TexParameter2D( GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    //------  framebuffer section  -------------

    GLuint frameBuffer;
    glGenFramebuffers( 1, & frameBuffer);
    BindFramebuffer( frameBuffer);
    FramebufferTexture2D( GL_COLOR_ATTACHMENT0, iTexture, iMinLevel + 1);
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    assert( status == GL_FRAMEBUFFER_COMPLETE);


    Viewport( Screen( x, y));

    Draw( PixelRect( -1, 1, -1, 1));

    // recover old state
    GL::BindTexture2D( oldTexture);

    glDeleteFramebuffers( 1, & frameBuffer);
  }

  TexCreateMipmaps2D( iTexture, iMaxLevel, iMinLevel + 1);
}

#endif // GL_ARB_framebuffer_object

void GL::DeleteTexture( GLuint texture)
{
  glDeleteTextures( 1, & texture);
  GL::CheckError();
}

GL::Pixel GL::GetTexExtend( int iLevel)
{
  GLint x, y;
  glGetTexLevelParameteriv( GL_TEXTURE_2D, iLevel, GL_TEXTURE_WIDTH , & x);
  glGetTexLevelParameteriv( GL_TEXTURE_2D, iLevel, GL_TEXTURE_HEIGHT, & y);
  GL::CheckError();
  return GL::Pixel( static_cast<Pixel::Type>( x), static_cast<Pixel::Type>( y));
}

void GL::Get( GLenum pname, GLint * values)
{
  glGetIntegerv( pname, values);
  GL::CheckError();
}

void GL::Get( GLenum pname, GLdouble * values)
{
  glGetDoublev( pname, values);
  GL::CheckError();
}

void GL::Get( GLenum pname, GLfloat * values)
{
  glGetFloatv( pname, values);
  GL::CheckError();
}

void GL::Get( GLenum pname, GLboolean * values)
{
  glGetBooleanv( pname, values);
  GL::CheckError();
}

void GL::DrawBackground( GL::Color const & color)
{
  AttribGuard attr;
  GL::Screen vp = GL::GetViewport();
  MatrixGuard mdl( GL_PROJECTION);
  glLoadIdentity();
  MatrixGuard prj( GL_MODELVIEW);
  glLoadIdentity();
  Viewport( vp);
  glPolygonMode( GL_FRONT_AND_BACK , GL_FILL);
  Draw( PixelRect( -1, 1, -1, 1), color);
}

void GL::Viewport( Screen const & ext, Screen const & ori)
{
  glViewport( ori.m_x, ori.m_y, ext.m_x, ext.m_y);
  GL::CheckError();
}

void GL::RotateZ( double dCcwRad)
{
  glRotated( dCcwRad * 180 / M_PI, 0, 0, 1);
}

void GL::PixelTransfer( double dScale, double dBias)
{
  glPixelTransferf( GL_RED_SCALE  , static_cast<float>( dScale));
  glPixelTransferf( GL_GREEN_SCALE, static_cast<float>( dScale));
  glPixelTransferf( GL_BLUE_SCALE , static_cast<float>( dScale));
  glPixelTransferf( GL_RED_BIAS   , static_cast<float>( dBias));
  glPixelTransferf( GL_GREEN_BIAS , static_cast<float>( dBias));
  glPixelTransferf( GL_BLUE_BIAS  , static_cast<float>( dBias));
}

void GL::SetPixelProjectionTL( GL::Screen const & viewPort, GL::Pixel const & ext)
{
  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  glOrtho( 0, ext.m_x - 1, ext.m_y - 1, 0, -1, 1);
  glViewport( 0, 0, static_cast<GLsizei>( viewPort.m_x), static_cast<GLsizei>( viewPort.m_y));

  glMatrixMode( GL_MODELVIEW);
  glLoadIdentity();
}

void GL::SetPixelProjectionBL( GL::Screen const & viewPort, GL::Pixel const & ext)
{
  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  glOrtho( 0, ext.m_x - 1, 0, ext.m_y - 1, -1, 1);
  glViewport( 0, 0, static_cast<GLsizei>( viewPort.m_x), static_cast<GLsizei>( viewPort.m_y));

  glMatrixMode( GL_MODELVIEW);
  glLoadIdentity();
}

void GL::DrawTriangleFan( std::vector<Pos> const & vecPos)
{
  VertexPointer vp( & vecPos[0]);
  vp.AddTexCoord( & vecPos[0]);
  vp.DrawArrays( GL_TRIANGLE_FAN, 0, (GLsizei) vecPos.size());
}

void GL::DrawTriangleFan( std::vector<Pos> const & vecPos, GL::Color const & color)
{
  GL::Color4( color);
  VertexPointer vp( & vecPos[0]);
  vp.DrawArrays( GL_TRIANGLE_FAN, 0, (GLsizei) vecPos.size());
}

void GL::Init()
{
  static bool bGlewInit = false;
  if( ! bGlewInit)
  {
    bGlewInit = true;
    if( glewInit() != GLEW_OK)
      throw "glew can not be init";
  }
}
