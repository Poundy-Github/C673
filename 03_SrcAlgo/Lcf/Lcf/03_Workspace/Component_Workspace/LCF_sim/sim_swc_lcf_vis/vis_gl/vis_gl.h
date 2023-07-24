#pragma once

#ifndef GL_POS_H
#define GL_POS_H

/** \defgroup ld_vis2_opengl OpenGL classes and functions
 *
 *  - convinient and abstract datatypes also for multiple count of verteces for
 *    - <b>2D Viewport : </b> GL::Pixel, GL::PixelLine, ...
 *    - <b>3D AutoSAR : </b> GL::Pos, GL::Rect, ...
 *  - convinient Drawing functions
 *  - optimized for std::vector<GL::Pos> and std::vector<GL::Pixel>
 *  - use abstract states on the stack with Push and Pop guard Objects:
 *    - GL::AttribGuard
 *    - GL::ClientAttribGuard
 *    - GL::VertexPointer
 *
 */

/** \defgroup ld_vis2_opengl_3d OpenGL 3d interface
 *
 *  Collection of classes to draw an 3d autosar coordinate system.
 *
 *  \ingroup ld_vis2_opengl
 */

/** \defgroup ld_vis2_opengl_2d OpenGL 2d interface
 *
 *  Collection of classes to draw an 2d raster image.
 *
 *  \ingroup ld_vis2_opengl
 */

#include "glew.h"

#include <vector>

#include "vis_gl_screen.h"
#include <windows.h>
#ifdef VIS_GL_USE_MTS
#  include "sim_gdvfont_ifc.h"
#  include "sim_rendercontext_ifc.h"
#endif

// class ISimRenderContext;
// interface class IGDVFont;

#undef DrawText

/** \namespace GL
 *
 *  \brief functions to encapsulate opengl calls
 *
 *  - convinient and abstract datatypes also for multiple count of verteces for
 *    - <b>2D Viewport : </b> GL::Pixel, GL::PixelLine, ...
 *    - <b>3D AutoSAR : </b> GL::Pos, GL::Rect, ...
 *  - convinient Drawing functions
 *  - optimized for std::vector<GL::Pos> and std::vector<GL::Pixel>
 *  - use abstract states on the stack with Push and Pop guard Objects:
 *    - GL::AttribGuard
 *    - GL::ClientAttribGuard
 *    - GL::VertexPointer
 *
 *  \ingroup ld_vis2_opengl
 *  \sa \ref ld_vis2_opengl
 */

namespace GL
{
  class Pos;
  class Line;
  class Tri;
  class Rect;
  class Pixel;
  class PixelLine;
  class PixelRect;
  class PixelTri;
  class Color;
  class Screen;
  class ScreenQuad;
  class Normal;
  class Mat;

  void Init();

  /// \anchor vis_gl_func
  /** \name Atom Opengl wrapper functions */
  ///\{
  void Vertex( Pos const & glPos);
  void Vertex( Pixel const & glPixel);
  void TexCoord( Pos const & glPos);
  void TexCoord( Pixel const & glPixel);
  void Color3( Color const & color);
  void Color4( Color const & color);
  Screen GetViewport();
  Screen GetClientRect( HWND hwnd);
  Screen WindowPos2GLScreen( POINT point, HWND hwnd);
  void Viewport( Screen const & ext, Screen const & ori = Screen( 0, 0));
  Pixel GetRasterPos();
  void ClearColor( Color const & color);
  template<typename T>
  void GetTexImage2D( GLenum format, T * pixel, int iLevel = 0);
  /// @param internalformat : GL_RGBA, GL_RGB, ...
  /// @param format : GL_RGB, GL_RGBA, GL_RED, ...
  /// @param border : 0, 1
  /// @param dim : extension
  /// @param pixels : data
  /// @param level : 0, 1, 2, ...
  template<typename T>
  void TexImage2D( GLint internalformat, GL::Pixel const & dim, GLint border, GLenum format, const T * pixels, GLint level = 0);
  template<typename T>
  void ReadPixels( GL::Pixel const & origin, GL::Pixel const & ext, GLenum format, T * pixels);
  void BindTexture2D( GLuint texture);
  void TexParameter2D( GLenum pname, GLint param);
  void TexParameter2D( GLenum pname, GLfloat param);
  GLuint GenTexture();
  GLuint GenFramebuffer();
  void FramebufferTexture2D( GLenum attachment, GLuint texture, GLint level = 0);
  void DeleteTexture( GLuint texture);
  void DeleteFramebuffer( GLuint fb);
  Pixel GetTexExtend( int iLevel = 0);
  void BindFramebuffer( GLuint framebuffer);
  void MultMatrix( Mat const & mat);
  void LoadMatrix( Mat const & mat);
  Mat  GetProjectionMatrix();  ///< wrapper arounnd glGet( GL_PROJECTION_MATRIX)
  Mat  GetModelViewMatrix();   ///< wrapper arounnd glGet( GL_MODELVIEW_MATRIX)
  void Get( GLenum pname, GLint * values);
  void Get( GLenum pname, GLdouble * values);
  void Get( GLenum pname, GLfloat * values);
  void Get( GLenum pname, GLboolean * values);
  void PixelTransfer( double dScale = 1, double dBias = 0);
  ///@}

  /// \anchor vis_gl_func_3d
  /// @name 3D drawing
  ///@{
  void Draw( Pos const & point, float fSize, Color const & color);
  void Draw( std::vector<Pos> const & points, float fPointSize, Color const & color);
  void Draw( GLenum mode, std::vector<Pos> const & points, float fPointSize, Color const & color);
  void Draw( std::vector<Pos> const & points, float fPointSize, std::vector<Color> const & vecColor);
  void Draw( Line const & line, float fSize, Color const & color);
  void Draw( std::vector<Tri> const & vecTri, Color const & color);
  void Draw( std::vector<Line> const & lines, float fSize, Color const & color);
  void Draw( std::vector<Line> const & vecLines, float fSize, std::vector<Color> const & vecColor);
  void Draw( Rect const & rect, Color const & color);
  void Draw( Rect const & rect, float fLineSize, Color const & color);
  void Draw( std::vector<Rect> const & vecRect, Color const & color);
  void Draw( std::vector<Rect> const & vecRect, float fLineSize, Color const & color);
  void Draw( std::vector<Rect> const & vecRect, float fLineSize, std::vector<Color> const & color);
  void Draw( std::vector<Rect> const & vecRect, std::vector<Color> const & vecColor);
  void DrawTriangleFan( std::vector<Pos> const & vecPos, GL::Color const & color);
  void DrawLineStrip( std::vector<Pos> const & linePositions, float fLineSize, Color const & color);
  void DrawLineStrip( std::vector<std::vector<Pos> > const & lines, float fLineSize, Color const & color);

  // Texture usage
  void Draw( Rect const & rect);          ///< draws textCoord
  void Draw( Rect const & rect, Rect const & texCoord);          ///< draws textCoord
  void Draw( std::vector<GL::Rect> const & vecRect, std::vector<GL::Rect>  const & vecTexCoord);
  void Draw( std::vector<GL::Rect> const & vecRect, std::vector<GL::PixelRect>  const & vecTexCoord);
  void DrawTriangleFan( std::vector<Pos> const & vecPos);
  ///@}

  /// \anchor vis_gl_func_2d
  /// @name 2D drawing
  ///@{
  void Draw( Pixel const & point, float fPointSize, Color const & color);
  void Draw( PixelLine const & line, float fLineSize, Color const & color);
  void Draw( PixelRect const & rect, Color const & color);
  void Draw( PixelRect const & rect);   ///< draws textCoord
  void Draw( PixelRect const & rect, float fLineSize, Color const & color);
  void Draw( PixelTri const & triangle, Color const & color);
  void Draw( std::vector<GL::Pixel> const & vecPixel, float fPointSize, Color const & color);
  void Draw( std::vector<PixelLine> const & pixelLine, float fLineSize, std::vector<GL::Color> const & vecColor);
  void Draw( std::vector<PixelLine> const & pixelLine, float fLineSize, GL::Color const & color);
  void Draw( std::vector<GL::PixelRect> const & vecPixel, float fLineSize, std::vector<GL::Color> const & vecColor);
  void Draw( std::vector<GL::Pixel> const & vecPixel, float fPointSize, std::vector<GL::Color> const & vecColor);
  void DrawLineStrip( std::vector<Pixel> const & linePositions, float fLineSize, Color const & color);
  void DrawQuadStrip( std::vector<GL::Pos> const & vecPos, Color const & color, bool bEnableTexture = false);
  void DrawBackground( GL::Color const & color);  ///< drawing instead of glClear with background calls shader

  /**
   * displays text in viewport coordinate system translated from AutoSAR coordinate system
   * @param glPixelPos position translated from AutoSAR to Viewport
   * @param color Color
   * @param sText text to display
   * @param rFont interface to font drawing
   */
#ifdef VIS_GL_USE_MTS
  void DrawText2D( Pixel const & glPixelPos, Color const & color, std::string const & sText, IGDVFont& rFont);
#endif
  ///@}

  ///@name 2D screen drawing
  ///@{
  void Draw( ScreenQuad const & rect, Color const & color);
#ifdef VIS_GL_USE_MTS
  void DrawText2D( Screen const & glPixelPos, Color const & color, std::string const & sText, IGDVFont& rFont);
#endif
  ///@}

  /// \anchor vis_gl_coord_transform
  /// @name Coordinate transformation
  /// @{
  void Translate( Pixel const & offset);  ///< glTranslate wrapper
  void Translate( Pos const & offset);  ///< glTranslate wrapper
  void Scale( Pixel const & scale);
  void RotateZ( double dCcwRad);   ///< @param dCcwRad rotation in ccw ( counter clock wise ) in rad
  /// Modify GL_MODELVIEW matrix to draw inside an area specified by ( originPos, originExt).
  /// The new coordinate system is modified to ( newOrigin, newExt);
  void ModelViewScaleTranslateTo( Pixel const & originPos, Pixel const & originExt, Pixel const & newOrigin, Pixel const & newExt);

  GL::Screen                  Project( GL::Pos const & glPos);  ///< like gluProject
  GL::ScreenQuad              Project( GL::Rect const & glRect);  ///< like gluProject
  std::vector<GL::ScreenQuad> Project( std::vector<GL::Rect> const & glRect);  ///< like gluProject
  GL::Screen                  Project( GL::Pixel const & glPos);  ///< like gluProject
  GL::Pixel                   UnProject( GL::Screen const & glScreenPos, float fZ = 0.0F);  ///< like gluUnProject
  GL::Pixel                   UnProject( GL::Screen const & glScreenPos, double * dProjMat16, double * dModelMat16, GLint * dViewport4, float fZ = 0.0F);  ///< like gluUnProject
  GL::PixelRect               UnProject( GL::ScreenQuad const & glScreenQuad, float fZ = 0.0F);  ///< like gluUnProject
  /// @}

  /// Checks whether an opengl error occurs -> exception if GL_DEBUG = 1 compiled ( default should off )
  void CheckError();

  /// \anchor vis_gl_normal_anchor
  ///@name Normal section
  /// @{
  Normal CalcNormal( Line const & l1, Line const & l2);
  Normal CalcZNormal( Line const & line);
  std::vector<Normal> CalcZNormal( std::vector<Line> const & vecLIine);
  /// @}

  /// @name Light
  ///@{
  /// @param iLightNum 0 .. GL_MAX_LIGHTS - 1
  void LightSpotDirection( int iLightNum, Normal const & n);
  void LightPosition( int iLightNum, Pos const & p);
  void LightAmbient( int iLightNum, Color const & clr);
  void LightDiffuse( int iLightNum, Color const & clr);
  void LightSpecular( int iLightNum, Color const & clr);
  ///@}

  /// @name Utility
  ///@{
  /// @param p1, directionPoint both points
  /// @param fLength length from p1 to directionPoint. Could be more than distance
  /// @return calculated position
  Pos GetDirPoint( GL::Pos const & p1, GL::Pos const & directionPoint, double fLength); ///< Calculates a point with distance from p1 in direction from p1 to p2
  ///@}

  /// @name AutoSAR proejction
  ///@{
  /// AutoSAR's and OpenGL coordinate systems are not same oriented
  /// Project2AutoSAR is called to transform AutoSAR coordinate orientation
  /// to OpenGL orientation where z is deep, x up and y right
  ///
  /// Typical calling sequence:
  /// - gluPerspective(..)
  /// - Project2AutoSAR()
  /// - GL::Translate( - camera.GetPos());
  ///
  void Project2AutoSAR();
  Mat  GetAutoSARMat( GL::Pos const & carPos, double dAzimuthX);
  Mat  OrthoMat( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
  Mat  OrthoInvMat( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
  Mat  GetViewportMat( int x, int y, int width, int height);
  Mat  GetViewportMatInv( int x, int y, int width, int height);
  void SetPixelProjectionTL( GL::Screen const & viewPort, GL::Pixel const & extension);  ///< origin is TopLeft
  void SetPixelProjectionBL( GL::Screen const & viewPort, GL::Pixel const & extension);  ///< origin is BottomLeft
  ///@}

  /// @param cFile Windows Bitmap fileformat
  /// @return texture id. on failure -1
  int CreateTextureFromFile( char const * cFile);

  /// Like gluBuild2DMipmaps but on GPU
  /// internally a famebuffer is used
  /// @param iTexture filled unilt iMinLevel
  /// @param iMaxLevel should be filled up to
  /// @param iMinLevel minimal filled level
  void TexCreateMipmaps2D( int iTexture, int iMaxLevel, int iMinLevel = 0);

}  // namespace GL

#include "vis_gl_color.h"
#include "vis_gl_attrib_guard.h"
#include "vis_gl_line.h"
#include "vis_gl_matrix_guard.h"
#include "vis_gl_pixel.h"
#include "vis_gl_pixel_line.h"
#include "vis_gl_pixel_rect.h"
#include "vis_gl_pixel_tri.h"
#include "vis_gl_rect.h"
#include "vis_gl_vertex_pointer.h"
#include "vis_gl_client_attrib_guard.h"
#include "vis_gl_screen.h"
#include "vis_gl_normal.h"
#include "vis_gl_tri.h"
#include "vis_gl_mat.h"
#include "vis_gl_tex_guard.h"
#include "vis_gl_bitmap.h"
#include "vis_gl_shader_base.h"
#include "vis_gl_texture_2d.h"
#include "vis_gl_screen_quad.h"

#include "vis_gl.inl"

#endif // GL_POS_H
