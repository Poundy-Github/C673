/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_button.cpp

  DESCRIPTION:            Drawing of button in menu which can be activated 
                          or deactivated

  CPU:                    Independent

  CREATION DATE:          2015-08-13

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */

#include "sim_visu_menu.h"

/************************************************************************/
/*  CSimVisuMenuButton                                                   */
/************************************************************************/

CSimVisuMenuButton::CSimVisuMenuButton()
{
  m_xPos = 0;
  m_yPos = 0;
  m_buttonWidth = 0;
  m_buttonHeight = 0;
  m_frameColor = color_noColor;
  m_fillColor = color_noColor;
  m_pressed = false;
}

CSimVisuMenuButton::CSimVisuMenuButton( const uint16  xPos,
                                        const uint16  yPos,
                                        const uint16  buttonWidth,
                                        const uint16  buttonHeight,
                                        const color_e frameColor,
                                        const bool    isLockButton,
                                        const color_e fillColor /* color_noColor */
                                       )
: m_xPos(xPos)
, m_yPos(yPos)
, m_buttonWidth(buttonWidth)
, m_buttonHeight(buttonHeight)
, m_frameColor(frameColor)
, m_fillColor(fillColor)
{
  m_pressed = false;
  m_lockButton = isLockButton;
}

CSimVisuMenuButton::~CSimVisuMenuButton ()
{
}

/************************************************************************/
/*  SetPos                                                              */
/************************************************************************/
void CSimVisuMenuButton::SetPos ( const uint16 xPos, 
                                  const uint16 yPos, 
                                  const uint16 buttonWidth, /* = 0 */
                                  const uint16 buttonHeight /* = 0 */ 
                                 )
{
  m_xPos = xPos;
  m_yPos = yPos;

  m_buttonWidth  = (buttonWidth  != 0) ? buttonWidth  : m_buttonWidth;
  m_buttonHeight = (buttonHeight != 0) ? buttonHeight : m_buttonHeight;

  return;
}

/************************************************************************/
/*  pressButton                                                         */
/************************************************************************/
void CSimVisuMenuButton::pressButton ()
{
  m_pressed = !m_pressed;
}

/************************************************************************/
/*  draw                                                                */
/************************************************************************/
void CSimVisuMenuButton::draw( const ISimRenderContext* const pContext )
{
  GLint top_left_x = m_xPos;
  GLint top_left_y = m_yPos;
  GLint top_right_x = m_xPos + m_buttonWidth;
  GLint top_right_y = top_left_y;
  GLint bottom_right_x = top_right_x;
  GLint bottom_right_y = m_yPos + m_buttonHeight;
  GLint bottom_left_x = top_left_x;
  GLint bottom_left_y = bottom_right_y;

  if(m_fillColor != color_noColor)
  {
    SetColor(m_fillColor);
    glBegin(GL_QUADS);
    {
      glVertex3i( top_left_x,     top_left_y,     0);
      glVertex3i( top_right_x,    top_right_y,    0);
      glVertex3i( bottom_right_x, bottom_right_y, 0);
      glVertex3i( bottom_left_x,  bottom_left_y,  0);
    }
    glEnd();
  }
  /* draw border */
  if( m_frameColor != color_noColor )
  {
    glLineWidth(2);
    SetColor(m_frameColor);
    glBegin(GL_LINE_LOOP);
    glVertex3i( top_left_x,    top_left_y,     0);
    glVertex3i( top_right_x,   top_right_y,    0);
    glVertex3i( bottom_right_x,bottom_right_y, 0);
    glVertex3i( bottom_left_x, bottom_left_y,  0);
    glEnd();
    glLineWidth(1);
  }

  if(m_lockButton == true)
  {
    IGDVFont& font = pContext->GetWindow().GetFontInterface("", 10);
    font.BeginRender2D();
    SetTextColor(color_white, font);
    if (m_pressed == true)
    {
      font.RenderTextf(m_xPos+5, m_yPos+2, 1, "L");
    }
    else
    {
      font.RenderTextf(m_xPos+5, m_yPos+2, 1, "U");
    }
    font.EndRender2D();
  }
  else
  {
    drawSign();
  }
}

/************************************************************************/
/*  checkButtonPressed                                                  */
/************************************************************************/
bool CSimVisuMenuButton::checkButtonPressed ( const t_MouseInfo& mouseInfo )
{
  sint16 Y1 = mouseInfo.singleClickLeft.y - m_yPos;
  sint16 X1 = mouseInfo.singleClickLeft.x - m_xPos;
  uint16 y2 = m_buttonHeight;
  uint16 X2 = m_buttonWidth;

  if(   (Y1 >  0)
      &&(Y1 < y2)
      &&(X1 >  0)
      &&(X1 < X2)
    )
  {
    m_pressed = !m_pressed;
    return true;
  }
  else
  {
    return false;
  }
}

/************************************************************************/
/*  getButtonHeight                                                     */
/************************************************************************/
uint16 CSimVisuMenuButton::getButtonHeight() const
{
  return m_buttonHeight;
}

/************************************************************************/
/*  getButtonWidth                                                      */
/************************************************************************/
uint16 CSimVisuMenuButton::getButtonWidth() const
{
  return m_buttonWidth;
}

/************************************************************************/
/*  getActivation                                                       */
/************************************************************************/
bool CSimVisuMenuButton::getActivation() const 
{
  return m_pressed;
}

/************************************************************************/
/*  drawSign                                                            */
/************************************************************************/
void CSimVisuMenuButton::drawSign(/*const ISimRenderContext* pContext*/)
{
  uint16 lineWidth = 2;

  GLint left_x = m_xPos + 5;
  GLint left_y =  m_yPos + (m_buttonHeight)/2 /*- lineWidth/2*/;
  GLint right_x = m_xPos + m_buttonWidth -5;
  GLint right_y = left_y;

  GLint top_x = m_xPos +(m_buttonWidth)/2 /*- lineWidth/2*/;
  GLint top_y = m_yPos + 5;
  GLint bottom_x = top_x;
  GLint bottom_y = m_yPos + m_buttonHeight -5;

  glLineWidth(lineWidth);
  SetColor(color_red);

  glBegin(GL_LINES);
  glVertex3i(left_x,    left_y,  0);
  glVertex3i(right_x,   right_y, 0);
  glEnd();

  if(m_pressed)
  {
    glLineWidth(lineWidth);
    SetColor(color_red);

    glBegin(GL_LINES);
    glVertex3i(top_x,      top_y,    0);
    glVertex3i(bottom_x,   bottom_y, 0);
    glEnd();
  }
  glLineWidth(1);
}
