#include "crosshair.h"

#include <algorithm>
#include <cmath>
#include "stdafx.h"
#include "gl/GL.h"
#include "sim_gdvfont_ifc.h"
#include "sim_gl_tools.h"

Crosshair::Crosshair()
{
  // just show the actual position with a crosshair
  m_currentAction = CH_ACTION_NONE;
}

void Crosshair::draw( const int xMouse, const int yMouse, IGDVFont& font )
{
  glPushAttrib( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT );

  glEnable( GL_DEPTH_TEST );
  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

  glGetDoublev( GL_MODELVIEW_MATRIX,  m_mv );
  glGetDoublev( GL_PROJECTION_MATRIX, m_pv );
  glGetIntegerv( GL_VIEWPORT, m_viewport );

  m_font = &font;
  m_xVp  = xMouse;
  m_yVp  = m_viewport[3] - yMouse + m_viewport[1];

  if ( set::gl::viewport2ModelviewKnownMVZ(m_xVp, m_yVp, 0, m_mv, m_pv, m_viewport, m_xWorld, m_yWorld) == false )
    return;

  // draw crosshair at current position (m_xWorld, m_yWorld)
  glMatrixMode( GL_MODELVIEW );
  glPushMatrix( );
  {
    // draw crosshair at current position
    drawCrossAt( m_xWorld, m_yWorld );

    if ( m_currentAction == CH_ACTION_MEAS )
    {
      const double xDiff = static_cast<double>( m_prevXworld - m_xWorld );
      const double yDiff = static_cast<double>( m_prevYworld - m_yWorld );

      // show additional measurements
      drawRefMeasRect( xDiff, yDiff );
      drawRefMeasCirc( xDiff, yDiff );
      drawCrosshairInfoMeas( abs(xDiff), abs(yDiff) );
    }
    else
      drawCrosshairInfoNoMeas( m_xWorld, m_yWorld );
  }
  glPopMatrix(); // GL_MODELVIEW
  glPopAttrib();
}

void Crosshair::toggleAction( )
{
  if (m_currentAction == CH_ACTION_NONE)
  {
    // remember last position to show various measurements between last position and curernt one
    m_prevXworld    = m_xWorld;
    m_prevYworld    = m_yWorld;
    m_currentAction = CH_ACTION_MEAS;
  }
  else
    m_currentAction = CH_ACTION_NONE;
}

void Crosshair::drawCrosshairInfoMeas( const double xWorld, const double yWorld ) const
{
  const char format[] = "dx=%.1f dy=%.1f r=%.1f";
  drawCrosshairInfo( xWorld, yWorld, format, true );
}

void Crosshair::drawCrosshairInfoNoMeas( const double xWorld, const double yWorld ) const
{
  const char format[] = "x=%.1f y=%.1f";
  drawCrosshairInfo( xWorld, yWorld, format, false );
}

void Crosshair::drawCrosshairInfo( const double xWorld, const double yWorld, const char format[], const bool showMeas ) const
{
  const double arcRadius = sqrt(xWorld * xWorld + yWorld * yWorld);

  glMatrixMode( GL_PROJECTION );
  glPushMatrix();
  glLoadIdentity();
  glOrtho( 0, m_viewport[2] - 1, 0, m_viewport[3] - 1, -1, 1 );

  glMatrixMode( GL_MODELVIEW );
  glPushMatrix();
  glLoadIdentity();

  const int textHeight = static_cast<int>( m_font->GetCharHeight( 'X' ) );
  int textWidth;
  if (showMeas)
    textWidth  = _scprintf( format, xWorld, yWorld, arcRadius ) * static_cast<int>( m_font->GetCharWidth('X') );
  else
    textWidth  = _scprintf( format, xWorld, yWorld ) * static_cast<int>( m_font->GetCharWidth('X') );

  glColor3d( 1, 0.5, 0.5 );
  glBegin( GL_QUADS );
  {
    glVertex2i(m_xVp + textWidth + 10,  m_yVp);
    glVertex2i(m_xVp + textWidth + 10,  m_yVp + textHeight + 5);
    glVertex2i(m_xVp                 ,  m_yVp + textHeight + 5);
    glVertex2i(m_xVp                 ,  m_yVp);
  }
  glEnd();

  m_font->BeginRender();
  m_font->SetTextColor( 1, 1, 1, 1 );
  m_font->RenderTextf( m_xVp + 4, m_yVp + textHeight + 3, 0, format, xWorld, yWorld, arcRadius );
  m_font->EndRender();

  glPopMatrix();
  glMatrixMode( GL_PROJECTION );
  glPopMatrix();
  glMatrixMode( GL_MODELVIEW );
}

void Crosshair::drawCrossAt( const double xPos, const double yPos ) const
{
  glTranslated( xPos, yPos, 0 );

  glLineWidth(1);
  glColor4f( 0.5f, 1.0f, 0.5f, 1.0f );
  glBegin( GL_LINES );
  {
    glVertex2i( -100000, 0 );
    glVertex2i( 100000, 0 );
    glVertex2i( 0, -100000 );
    glVertex2i( 0, 100000 );
  }
  glEnd();
}

void Crosshair::drawRefMeasRect( const double xPos, const double yPos ) const
{
  // draw reference axis when showing distance
  glEnable( GL_LINE_STIPPLE );
  glLineStipple( 4, 0xAAAA );

  drawCrossAt( xPos, yPos );
}

void Crosshair::drawRefMeasCirc( const double xPos, const double yPos ) const
{
  const double arcRadius = sqrt(xPos * xPos + yPos * yPos);

  glLineWidth(1);
  glColor4f( 0.5f, 1.0f, 0.5f, 0.8f );
  glEnable( GL_LINE_STIPPLE );
  glLineStipple( 4, 0xAAAA );

  // draw line from previously clicked position to current position
  glBegin( GL_LINES );
  {
    glVertex2d( 0, 0 );
    glVertex2d( -xPos, -yPos );
  }
  glEnd();

  glBegin( GL_LINE_LOOP );
  {
    for ( int a = 0; a < 360; a += 10 )
    {
      const double angle = a * 3.1415926535897932384626433832795 / 180;
      glVertex2d( std::sin(angle) * arcRadius, std::cos(angle) * arcRadius );
    }
  }
  glEnd();
}
