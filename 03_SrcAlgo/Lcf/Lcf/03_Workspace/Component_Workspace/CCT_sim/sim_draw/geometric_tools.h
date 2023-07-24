#ifndef geometric_tools_h__
#define geometric_tools_h__

#include "sim_swc_draw_base.h"
#include "sim_gl_tools.h"
#include "sim_gl_rgbacolor.h"

#include <sstream>

#define GEOMETRIC_TOOLS_INTFVER 1

/// Draw a circle.
/// @param[in] centerX   The x coordinate in pixel of the center position.
/// @param[in] centerY   The y coordinate in pixel of the center position.
/// @param[in] radius    The radius of the circle in pixels.
/// @param[in] lineWidth The line width of the square.
/// @param[in] color     The color of the circle.
static void drawCircle(const float32 centerX, const float32 centerY, const float32 radius, const float32 lineWidth, const set::gl::RGBAColor& color)
{
  const int numCirclePoints = 160;
  const float32 angleIncr   = 2 * em::par::global::PI/numCirclePoints;
  glPushAttrib(GL_COLOR_BUFFER_BIT);
  {
    glColor4f(color.r, color.g, color.b, color.a);
    glEnable(GL_BLEND);
    glEnable( GL_LINE_SMOOTH );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(lineWidth);
    glBegin(GL_LINE_LOOP);
    {
      float32 currAngle = angleIncr;
      for (int i = 0 ; i < numCirclePoints ; i++)
      {
        glVertex2d(centerX + cml::cos(currAngle) * radius, centerY + cml::sin(currAngle) * radius);
        currAngle += angleIncr;
      }
      currAngle = 0.0F;
      glVertex2d(centerX + cml::cos(currAngle) * radius, centerY + cml::sin(currAngle) * radius);
    }
    glEnd();
    glLineWidth(1.0F);
  }
  glPopAttrib();
}

/// Draw a solid circle.
/// @param[in] centerX   The x coordinate in pixel of the center position.
/// @param[in] centerY   The y coordinate in pixel of the center position.
/// @param[in] lineWidth The line width of the square.
/// @param[in] radius    The radius of the circle in pixels.
/// @param[in] color     The color of the circle.
static void drawSolidCircle(const float32 centerX, const float32 centerY, const float32 radius, const float32 lineWidth, const ::set::gl::RGBAColor& color)
{
  const int numCirclePoints = 85;
  const float32 angleIncr   = 2 * em::par::global::PI/numCirclePoints;

  glPushAttrib(GL_COLOR_BUFFER_BIT);
  {
    glColor4f(color.r, color.g, color.b, color.a);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(lineWidth);
    glBegin(GL_TRIANGLE_FAN);
    {
      glVertex2d(centerX, centerY);
      float32 currAngle = 0.0F;
      for (int i = 0 ; i < numCirclePoints ; i++)
      {
        glVertex2d(centerX + cml::cos(currAngle) * radius, centerY + cml::sin(currAngle) * radius);
        currAngle += angleIncr;
      }
      currAngle = 0.0F;
      glVertex2d(centerX + cml::cos(currAngle) * radius, centerY + cml::sin(currAngle) * radius);
    }
    glEnd();
    glLineWidth(1.0F);
  }
  glPopAttrib();
}

/// Draw a square.
/// @param[in] centerX   The x coordinate in pixel of the center position.
/// @param[in] centerY   The y coordinate in pixel of the center position.
/// @param[in] lineWidth The line width of the square.
/// @param[in] radius    The radius of the square in pixels.
/// @param[in] color     The color of the square.
static void drawSquare(const float32 centerX, const float32 centerY, const float32 radius, const float32 lineWidth, const set::gl::RGBAColor& color)
{
  glPushAttrib(GL_COLOR_BUFFER_BIT);
  {
    glColor4f(color.r, color.g, color.b, color.a);
    glEnable(GL_BLEND);
    glEnable( GL_LINE_SMOOTH );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(lineWidth);
    glBegin(GL_LINE_STRIP);
    {
      glVertex2d(centerX + radius, centerY + radius);
      glVertex2d(centerX + radius, centerY - radius);
      glVertex2d(centerX - radius, centerY - radius);
      glVertex2d(centerX - radius, centerY + radius);
      glVertex2d(centerX + radius, centerY + radius);
    }
    glEnd();
    glLineWidth(1.0F);
  }
  glPopAttrib();
}

/// Draw a solid square.
/// @param[in] centerX   The x coordinate in pixel of the center position.
/// @param[in] centerY   The y coordinate in pixel of the center position.
/// @param[in] radius    The radius of the square in pixels.
/// @param[in] lineWidth The line width of the square.
/// @param[in] color     The color of the square.
static void drawSolidSquare(const float32 centerX, const float32 centerY, const float32 radius, const float32 lineWidth, const set::gl::RGBAColor& color)
{
  glPushAttrib(GL_COLOR_BUFFER_BIT);
  {
    glColor4f(color.r, color.g, color.b, color.a);
    glEnable(GL_BLEND);
    glEnable( GL_LINE_SMOOTH );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(lineWidth);
    glBegin(GL_TRIANGLE_FAN);
    {
      glVertex2d(centerX + radius, centerY + radius);
      glVertex2d(centerX + radius, centerY - radius);
      glVertex2d(centerX - radius, centerY - radius);
      glVertex2d(centerX - radius, centerY + radius);
      glVertex2d(centerX + radius, centerY + radius);
    }
    glEnd();
    glLineWidth(1.0F);
  }
  glPopAttrib();
}

/// Draw a symbol.
/// @param[in] ctx      Sim render context.
/// @param[in] symbol   The string/character to be rendered.
/// @param[in] centerX  The x coordinate in pixel of the center position.
/// @param[in] centerY  The y coordinate in pixel of the center position.
/// @param[in] fontSize The size of the symbol.
/// @param[in] color    The color of the symbol.
static void drawSymbol(const ISimRenderContext& ctx, std::string symbol, const float32 centerX, const float32 centerY, const float32 fontSize, const set::gl::RGBAColor& color)
{
  IGDVFont& detailsFont    = ctx.GetWindow().GetFontInterface("Terminal", static_cast<int>(fontSize));
  const float32 lineWidth  = static_cast<float32>(detailsFont.GetTextWidth( symbol.c_str()));
  const float32 lineHeight = static_cast<float32>(detailsFont.GetTextHeight(symbol.c_str()));
  detailsFont.BeginRender();
  {
    detailsFont.SetTextColor(color.r, color.g, color.b, color.a);
    const float32 posX = -0.5F * lineWidth;
    const float32 posY = 0.5F * lineHeight;
    detailsFont.RenderText(symbol.c_str(), posX + centerX, posY + centerY, 0);
  }
  detailsFont.EndRender();
}

#endif // geometric_tools_h__
