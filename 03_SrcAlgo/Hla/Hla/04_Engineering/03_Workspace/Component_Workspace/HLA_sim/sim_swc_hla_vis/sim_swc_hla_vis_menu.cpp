/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_swc_hla_vis_menu.cpp

  DESCRIPTION:            Drawing of menu and handling of activated submenus

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */

#include <sstream>
#include "sim_swc_hla_vis_menu.h"

/************************************************************************/
/************************************************************************/
/*  CSimHlaMenuVisOnly                                                  */
/************************************************************************/
/************************************************************************/

CSimHlaMenuVisOnly::CSimHlaMenuVisOnly()
{
  m_xPos = 0;
  m_yPos = 0;
  m_menuWidth = 0;
  m_menuHeight = 0;
  m_oldLclickCnt = 0;
  m_oldKeyCnt = 0;
  m_oldWheelCnt = 0;
}

CSimHlaMenuVisOnly::CSimHlaMenuVisOnly(const uint16 xPos, const uint16 yPos )
: m_xPos(xPos)
, m_yPos(yPos)
, m_menuWidth(0)
, m_menuHeight(0)
, m_oldLclickCnt(0)
, m_oldKeyCnt(0)
, m_oldWheelCnt(0)
, m_general     ("Menu",      xPos, yPos)
{
  m_general.setCell(1,0,"[v]isualisation", color_magenta, 'v');
  m_general.setCell(1,1,"ECU",color_ecu);
  m_general.setCell(1,2,"ETH",color_eth);
  m_general.setCell(1,3,"CAN",color_can);
  m_general.setCell(2,0,"I[n]put Interface", color_magenta, 'n');
  m_general.setCell(3,0,"[o]utput Interface", color_magenta, 'o');
  m_general.setCell(4,0,"[b]right Objects", color_magenta, 'b');
  m_general.setCell(5,0,"[e]rror List", color_magenta, 'e');
  m_general.setCell(5,1,"", color_yellow);
  m_general.setCell(5,2,"all", color_yellow);
  m_general.setCell(5,3,"no information", color_yellow);
  m_general.setCell(5,4,"no warnings", color_yellow);
  m_general.setCell(6,0,"[f]unction", color_magenta, 'f');
  m_general.setCell(6,1,"", color_yellow);
  m_general.setCell(6,2,"Output", color_yellow);
  m_general.setCell(6,3,"Matrix", color_yellow);
  m_general.setCell(7,0,"[k]ali online", color_magenta, 'k');
  m_general.setCell(8,0,"[1]Sigheader", color_magenta, '1');
  m_general.setCell(9,0,"[d]raw big HB symbol", color_magenta, 'd');
  m_general.setCell(9,1,"off",color_yellow);
  m_general.setCell(9,2,"big",color_yellow);
  m_general.setCell(9,3,"small",color_yellow);

  /* rows activated by default */
  m_general.SetRowActivation(0, SIM_ROW_ACTIVATED);
  m_general.SetRowActivation(1, SIM_ROW_ACTIVATED);
  m_general.SetRowActivation(3, SIM_ROW_ACTIVATED);
  m_general.SetRowActivation(5, SIM_ROW_ACTIVATED, 2);
}

CSimHlaMenuVisOnly::~CSimHlaMenuVisOnly()
{
}

/************************************************************************/
/*  checkSubMenuActivation                                              */
/************************************************************************/
void CSimHlaMenuVisOnly::checkSubMenuActivation(mouseInfo& mouseInfo, keyboardInfo& keyboardInfo)
{
  if(mouseInfo.singleClickLeft.count != m_oldLclickCnt)
  {
    m_oldLclickCnt = mouseInfo.singleClickLeft.count;

    /* general */
    if (m_general.clickedInSubMenu(mouseInfo))
    {
      m_general.checkRowActivation(mouseInfo);
    }
  }
  if(keyboardInfo.count != m_oldKeyCnt)
  {
    m_oldKeyCnt = keyboardInfo.count;
    /* general */
    m_general.checkRowActivation(keyboardInfo);
  }
  if(mouseInfo.current.wheel != m_oldWheelCnt)
  {
    e_mouseWheel eWheel;
    if(mouseInfo.current.wheel > m_oldWheelCnt)
    {
      eWheel = eWheelUp;
    }
    else
    {
      eWheel = eWheelDown;
    }
    m_oldWheelCnt = mouseInfo.current.wheel;

    /* general */
    if (m_general.mouseInSubMenu(mouseInfo))
    {
      m_general.checkRowActivation(mouseInfo,eWheel);
    }
  }
  return;
}

/************************************************************************/
/*  draw                                                                */
/************************************************************************/
void CSimHlaMenuVisOnly::draw(const ISimRenderContext* pContext)
{
  uint8  spaceBetween = 5;
  uint16 menuWidth = 0;
  uint16 menuHeight = 0;

  /* set drawing context */
  m_general.SetContext(pContext);
  
  /* draw background */
  menuWidth = m_general.getSubMenuWidth()
             + (2)*spaceBetween;

  menuHeight = m_general.getSubMenuHeight() + spaceBetween;

  if(menuWidth < m_menuWidth)
  {
    menuWidth = m_menuWidth;
  }
  else
  {
    menuWidth += 2*spaceBetween;
  }

  if(menuHeight < m_menuHeight)
  {
    menuHeight = m_menuHeight;
  }
  else
  {
    menuHeight += spaceBetween;
  }

  drawBackground((m_xPos-spaceBetween), (m_yPos-spaceBetween), menuWidth, menuHeight, color_black, 1.0f, color_yellow);

  /* update menu width and menu heigth */
  m_menuWidth = menuWidth;
  m_menuHeight = menuHeight;

  /* draw menu */
  m_general.SetPos(m_xPos,m_yPos);
  m_general.draw();
  return;
}

/************************************************************************/
/*  SetPos                                                           */
/************************************************************************/
void CSimHlaMenuVisOnly::SetPos(const uint16 xPos, const uint16 yPos, const uint16 menuWidth/* =0 */, const uint16 menuHeight/* =0 */)
{
  m_xPos = xPos+5;
  m_yPos = yPos;

  m_menuWidth = menuWidth;
  m_menuHeight = menuHeight;

  return;
}

/************************************************************************/
/*  getMenuWidth                                                        */
/************************************************************************/
uint16 CSimHlaMenuVisOnly::getMenuWidth()
{
  return m_menuWidth;
}

/************************************************************************/
/*  getMenuHeight                                                       */
/************************************************************************/
uint16 CSimHlaMenuVisOnly::getMenuHeight()
{
  return m_menuHeight;
}

/************************************************************************/
/*  updateOverlay                                                       */
/************************************************************************/
void CSimHlaMenuVisOnly::updateOverlay(SimuOverlayActivation& overlayActivation, boolean ETH_KAFASInputs, boolean CAN_bKafas2_ObjMabAsst_Valid)
{
  vector<uint8>  tmpActivatedRows;
  vector<uint16> tmpColActive;
  static bool firstActivation = true; /* variable to set default row activation */

  /* general */
  m_general.getActivation(tmpActivatedRows, tmpColActive);
  if(tmpActivatedRows[0] == SIM_ROW_ACTIVATED)
  {
    /* when the menu appears, set the default row activation */
    if(firstActivation)
    {
      m_general.SetRowActivation(1, SIM_ROW_ACTIVATED);
      m_general.SetRowActivation(3, SIM_ROW_ACTIVATED);
      m_general.SetRowActivation(5, SIM_ROW_ACTIVATED, 2); /* all errors */
      firstActivation = false;
    }
    /* visualization */
    if(   (tmpColActive[1] == 2)
       && (ETH_KAFASInputs)
       )
    {
      overlayActivation.activePlane = 3; /* VISU_ENET */
    }
    else if(   (tmpColActive[1] == 3)
            && (CAN_bKafas2_ObjMabAsst_Valid)
            )
    {
      overlayActivation.activePlane = 4; /* VISU_CAN */
    }
    else
    {
      overlayActivation.activePlane = 1; /* VISU_ECU */
    }
    overlayActivation.activeInputInterface        = (tmpActivatedRows[2]) ? true:false;
    overlayActivation.activeLsdInputInterface       = (tmpActivatedRows[3]) ? true:false;
    overlayActivation.activeBrightObjects         = (tmpActivatedRows[4]) ? true:false;
    overlayActivation.activeErrorList             = tmpColActive[5] - 1;
    overlayActivation.activeHLAFunction           = tmpColActive[6] - 1;
    overlayActivation.activeCaliOnline            = (tmpActivatedRows[7]) ? true:false;
    overlayActivation.activePortInput             = (tmpActivatedRows[8]) ? true:false;
    overlayActivation.activeHeadlightStateRequest = tmpColActive[9] - 1;
  }
  else
  {
    firstActivation = true;
    overlayActivation.activePlane                 = 1; /* VISU_ECU */
    overlayActivation.activeInputInterface        = 0;
    overlayActivation.activeLsdInputInterface       = 1;
    overlayActivation.activeBrightObjects         = 0;
    overlayActivation.activeErrorList             = 0;
    overlayActivation.activeHLAFunction           = 0;
    overlayActivation.activeCaliOnline            = 0;
    overlayActivation.activePortInput             = 0;
    overlayActivation.activeHeadlightStateRequest = 0;
  }
}

/************************************************************************/
/* drawBackground                                                       */
/************************************************************************/
void CSimHlaMenuVisOnly::drawBackground(const uint16 xPos,
                                        const uint16 yPos,
                                        const uint16 width,
                                        const uint16 height,
                                        const color_e color /*= color_noColor*/,
                                        const float32 alpha /*= 1.0f*/,
                                        const color_e borderColor /*= color_noColor*/
                                       )
{
  GLint top_left_x = xPos;
  GLint top_left_y = yPos;
  GLint top_right_x = xPos + width;
  GLint top_right_y = top_left_y;
  GLint bottom_right_x = top_right_x;
  GLint bottom_right_y = yPos + height;
  GLint bottom_left_x = top_left_x;
  GLint bottom_left_y = bottom_right_y;

  SetColor(color, alpha);
  glBegin(GL_QUADS);
  {
    glVertex3i( top_left_x,     top_left_y,     1);
    glVertex3i( top_right_x,    top_right_y,    1);
    glVertex3i( bottom_right_x, bottom_right_y, 1);
    glVertex3i( bottom_left_x,  bottom_left_y,  1);
  }
  glEnd();

  /* draw border */
  if( borderColor != color_noColor )
  {
    SetColor(borderColor);
    glBegin(GL_LINE_LOOP);
    glVertex3i( top_left_x,    top_left_y,     1);
    glVertex3i( top_right_x,   top_right_y,    1);
    glVertex3i( bottom_right_x,bottom_right_y, 1);
    glVertex3i( bottom_left_x, bottom_left_y,  1);
    glEnd();
  }
}