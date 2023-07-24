/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_menu.cpp

  DESCRIPTION:            Drawing of menu and handling of activated submenus

  CREATION DATE:          2015-07-27

  CPU:                    Independent

  VERSION:                $Revision: 1.4 $

  ---*/ /*---

**************************************************************************** */

#include <sstream>
#include "sim_visu_menu.h"

/************************************************************************/
/*  CSimVisuMenu                                                         */
/************************************************************************/
CSimVisuMenu::CSimVisuMenu()
{
  m_xPos = 0;
  m_yPos = 0;
  m_menuWidth = 0;
  m_menuHeight = 0;
  m_maxSubMenuWidth = 0;
  m_maxSubMenuHeight1st = 0;
  m_oldLclickCnt = 0;
  m_oldKeyCnt = 0;
  m_oldWheelCnt = 0;
  m_loaded = b_FALSE;
  m_keyActiveMenu = 0;
}

CSimVisuMenu::CSimVisuMenu(const uint16 xPos, const uint16 yPos )
: m_xPos(xPos)
, m_yPos(yPos)
, m_menuWidth(0)
, m_menuHeight(0)
, m_maxSubMenuWidth(0)
, m_maxSubMenuHeight1st(0)
, m_oldLclickCnt(0)
, m_oldKeyCnt(0)
, m_oldWheelCnt(0)
, m_loaded(b_FALSE)
, m_keyActiveMenu(0)
, m_minimizeButton(0,0,50,50, color_gold, b_FALSE)
, m_freezeMenuButton(0,0,50,50, color_gold, b_TRUE)
{
  
}
CSimVisuMenu::~CSimVisuMenu()
{
}

/************************************************************************/
/*  DrawMenu                                                                */
/************************************************************************/
void CSimVisuMenu::DrawMenu( const ISimRenderContext* const pContext, 
                             const t_MouseInfo&             mouseInfo, 
                             const t_KeyboardInfo&          keyboardInfo
                            )
{
  uint16 relDrawPosX = 0;
  uint16 relDrawPosY = 0;
  uint8  spaceBetween = 10;

  uint16 x = 0, y = 0;
  uint16 menuWidth = 0;
  uint16 menuHeight = 0;
  uint16 maxMenuWidth = 0;
  uint16 maxMenuHeight1st = 0;
  uint16 maxMenuHeight2nd = 0;

  if(m_minimizeButton.getActivation())
  {
    m_minimizeButton.SetPos(m_xPos, m_yPos, 20, 20);
    menuWidth = m_minimizeButton.getButtonWidth() + spaceBetween;
    menuHeight = m_minimizeButton.getButtonHeight() + spaceBetween;

    drawBackground((m_xPos-spaceBetween/2), (m_yPos-spaceBetween/2), menuWidth, menuHeight, color_black, 1.0f, color_yellow);
    m_minimizeButton.draw(pContext);
  }
  else
  {
    /* Set context, to be on the safe side this is done every call, otherwise exceptions when requesting the context are possible */
    for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
    {
      CSimVisuSubMenu& subMenu = **it;
      /* set drawing context */
      subMenu.SetContext(pContext);
    }

    /* calculate menu size only once */
    if(m_maxSubMenuWidth == 0)
    {
      /* Calculate menu size */
      calculateMenuSize();
    }

    /* draw background */
    drawBackground((m_xPos-spaceBetween/2), (m_yPos-spaceBetween/2), m_menuWidth, m_menuHeight, color_black, 1.0f, color_yellow);

    x = m_xPos;
    y = m_yPos;

    /* draw sub menus on background */
    for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
    {
      CSimVisuSubMenu& subMenu = **it;
      subMenu.SetPos(x, y);
      subMenu.draw();
      /* use max height on first row as the position for the complete second row */
      y += m_maxSubMenuHeight1st + spaceBetween;

      if ((std::distance(m_subMenuMap.begin(), it) % 2) != 0)
      {
        x += m_maxSubMenuWidth;
        y = m_yPos;
      }

    }

    drawActiveMenuFrame();

    m_minimizeButton.SetPos(m_xPos+ m_menuWidth - spaceBetween - m_minimizeButton.getButtonWidth(), m_yPos+5, 20, 20);
    m_minimizeButton.draw(pContext);

    m_freezeMenuButton.SetPos(m_xPos+ m_menuWidth - spaceBetween - m_minimizeButton.getButtonWidth(), m_yPos+30, 20, 20);
    m_freezeMenuButton.draw(pContext);
  }


  return;
}
/************************************************************************/
/*  InitMenu                                                     */
/************************************************************************/
void CSimVisuMenu::InitMenu()
{
  for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
  {
    CSimVisuSubMenu& subMenu = **it;
    subMenu.reset();
  }
}
/************************************************************************/
/*  SetMenuPosition                                                     */
/************************************************************************/
void CSimVisuMenu::SetMenuPosition( const uint16 xPos, 
                                    const uint16 yPos, 
                                    const uint16 menuWidth, /* = 0 */
                                    const uint16 menuHeight /* = 0 */
                                   )
{
  m_xPos = xPos;
  m_yPos = yPos;

  m_menuWidth  = (menuWidth  != 0) ? menuWidth  : m_menuWidth;
  m_menuHeight = (menuHeight != 0) ? menuHeight : m_menuHeight;

  return;
}

/************************************************************************/
/*  calculateMenuSize                                                   */
/************************************************************************/
void CSimVisuMenu::calculateMenuSize()
{
  uint8  spaceBetween = 10;

  uint16 menuWidth = 0;
  uint16 menuHeight = 0;
  uint16 maxMenuWidth = 0;
  uint16 maxMenuHeight1st = 0;
  uint16 maxMenuHeight2nd = 0;

  for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
  {
    CSimVisuSubMenu& subMenu = **it;

    /* find max width for column */
    if (subMenu.getSubMenuWidth() > maxMenuWidth)
    {
      maxMenuWidth = subMenu.getSubMenuWidth();
    }

    /* find max height in first row */
    if (subMenu.getSubMenuHeight() > maxMenuHeight1st)
    {
      maxMenuHeight1st = subMenu.getSubMenuHeight();
    }

    if ((std::distance(m_subMenuMap.begin(), it) % 2) != 0)
    {
      /* find max height in second row  */
      if (subMenu.getSubMenuHeight() > maxMenuHeight2nd)
      {
        maxMenuHeight2nd = subMenu.getSubMenuHeight();
      }
    }
  }

  /* set total menu height */
  menuHeight = maxMenuHeight1st + maxMenuHeight2nd + 2*spaceBetween;

  /* menuWidth consists of number of colums * width of each colum, the two spaces at the beginning and the end, 
     width of the buttons at the right side */
  menuWidth = (m_subMenuMap.size()+1)/2 * maxMenuWidth + 2*spaceBetween + m_minimizeButton.getButtonWidth();

  /* Ensure that menu width is at least defined width */
  if(menuWidth < m_menuWidth)
  {
    menuWidth = m_menuWidth;
  }
  else
  {
    menuWidth += 2*spaceBetween;
  }

  /* Ensure that menu height is at least defined height */
  if(menuHeight < m_menuHeight)
  {
    menuHeight = m_menuHeight;
  }
  else
  {
    menuHeight += spaceBetween;
  }
  /*menuHeight = m_general.getSubMenuHeight() + spaceBetween;*/

  /* update menu width and menu height */
  m_menuWidth = menuWidth;
  m_menuHeight = menuHeight;
  m_maxSubMenuWidth = maxMenuWidth;
  m_maxSubMenuHeight1st = maxMenuHeight1st;
}

/************************************************************************/
/*  getMenuWidth                                                        */
/************************************************************************/
uint16 CSimVisuMenu::GetMenuWidth ()
{
  return m_menuWidth;
}

/************************************************************************/
/*  getMenuHeight                                                       */
/************************************************************************/
uint16 CSimVisuMenu::GetMenuHeight ()
{
  return m_menuHeight;
}

/************************************************************************/
/*  checkSubMenuActivation                                              */
/************************************************************************/
boolean CSimVisuMenu::CheckSubMenuActivation( const t_KeyboardInfo& keyboardInfo,
                                                    t_MouseInfo&    mouseInfo
                                             )
{
  boolean mainKey = b_FALSE;
  boolean bMenuUpdated = b_FALSE;

  if(mouseInfo.singleClickLeft.count != m_oldLclickCnt)
  {
    m_oldLclickCnt = mouseInfo.singleClickLeft.count;
    if(  (m_fixMenu == b_FALSE)
       &&(m_minimizeButton.getActivation() == b_FALSE)
      )
    {
      for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
      {
        CSimVisuSubMenu& subMenu = **it;
        if (subMenu.clickedInSubMenu(mouseInfo))
        {
          subMenu.checkRowActivation(mouseInfo);
          bMenuUpdated = b_TRUE;
        }
      }
    }/* if fixMenu or minimized */

    /* minimize button */
    m_minimizeButton.checkButtonPressed(mouseInfo);
    /* freeze button */
    m_freezeMenuButton.checkButtonPressed(mouseInfo);
  }

  if(keyboardInfo.count != m_oldKeyCnt)
  {
    m_oldKeyCnt = keyboardInfo.count;

    if(m_fixMenu == b_FALSE)
    {
      /* Check for key of sub menu group */
      for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
      {
        CSimVisuSubMenu& subMenu = **it;
        /* compare keyboard char with char of sub menu */
        if (keyboardInfo.character == subMenu.getCharacter())
        {
          checkKeyActiveMenu( keyboardInfo,
                              subMenu
                             );
          mainKey = b_TRUE;
          bMenuUpdated = b_TRUE;
          break;
        }
      }

      /* no key of sub menu was pressed */
      /* check for sub activations within sub menu group */
      if (mainKey == b_FALSE)
      {
        for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
        {
          CSimVisuSubMenu& subMenu = **it;
          /* compare active key with char of sub menu */
          if (m_keyActiveMenu == subMenu.getCharacter())
          {
            subMenu.checkRowActivation(keyboardInfo);
            bMenuUpdated = b_TRUE;
            break;
          }
        }
      }

      /* special handling of minimize button */
      if (keyboardInfo.character == '-')
      {
        m_minimizeButton.pressButton();
      }

    }/* if fixMenu */
  }
  if(mouseInfo.current.wheel != m_oldWheelCnt)
  {
    boolean wheelInMenu = b_FALSE;
    e_MouseWheel eWheel;
    if(mouseInfo.current.wheel > m_oldWheelCnt)
    {
      eWheel = eWheelUp;
    }
    else
    {
      eWheel = eWheelDown;
    }

    if(  (m_fixMenu == b_FALSE)
       &&(m_minimizeButton.getActivation() == b_FALSE)
      )
    {
      for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
      {
        CSimVisuSubMenu& subMenu = **it;
        if (subMenu.mouseInSubMenu(mouseInfo))
        {
          subMenu.checkRowActivation(mouseInfo,eWheel);
          wheelInMenu = b_TRUE;
          bMenuUpdated = b_TRUE;
        }
      }

    }/* if fixMenu */

    if(wheelInMenu)
    {
       mouseInfo.current.wheel = m_oldWheelCnt;
    }
    else
    {
      m_oldWheelCnt = mouseInfo.current.wheel;
    }
  }

  /* check if menu is locked */
  m_fixMenu = m_freezeMenuButton.getActivation();

  return bMenuUpdated;
}

/************************************************************************/
/*  tmpSave                                                                */
/************************************************************************/
int CSimVisuMenu::tmpSave()
{
  string filename = "tmp_menu.cfg";
  fstream outFile; 
  streampos begin,end;
  outFile.open (filename.c_str(), ios::out | ios::trunc | ios::binary);
  if(outFile.is_open())
  {
    outFile.write ( (char *)(&m_xPos), sizeof(m_xPos) );
    outFile.write ( (char *)(&m_yPos), sizeof(m_yPos) );

    for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
    {
      CSimVisuSubMenu& subMenu = **it;
      subMenu.save(outFile);
    }

    outFile.seekp (0, ios::beg);
    begin = outFile.tellp();

    outFile.seekp (0, ios::end);
    end = outFile.tellp();

    outFile.close();
    return (sint16)(end-begin);
  }
  else
  {
    outFile.close();
    return -1;
  }
}

/************************************************************************/
/*  save                                                                */
/************************************************************************/
bool CSimVisuMenu::SaveMenu(const string componentName)
{
  const string filename = componentName + "menu.cfg";
  fstream outFile; 
  outFile.open (filename.c_str(), ios::out | ios::trunc | ios::binary);
  if(outFile.is_open())
  {
    outFile.write ( (char *)(&m_xPos), sizeof(m_xPos) );
    outFile.write ( (char *)(&m_yPos), sizeof(m_yPos) );

    for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
    {
      CSimVisuSubMenu& subMenu = **it;
      subMenu.save(outFile);
    }

    outFile.close();
    return b_TRUE;
  }
  else
  {
    return b_FALSE;
  }
}

/************************************************************************/
/*  load                                                                */
/************************************************************************/
bool CSimVisuMenu::LoadVisuMenu(const string componentName)
{
  const string filename = componentName + "menu.cfg";
  fstream inFile;
  fstream oldInFile;
  sint16 newMenuSize;
  streampos begin,end;
  streampos size1 = 0;
  m_loaded = b_FALSE;
  inFile.open (filename.c_str(), ios::in | ios::binary);

  /* check size of config file */
  if(inFile.is_open())
  {
    inFile.seekg (0, ios::end);
    size1 = inFile.tellg();
  }

  inFile.close();

  /* get size of actual configuration */
  newMenuSize = this->tmpSave();

  /* if the size matches, load the data from the saved configuration */
  if((sint16)size1 == newMenuSize)
  {
    inFile.open(filename.c_str(), ios::in | ios::binary);

    inFile.seekg(0, ios::beg);
    inFile.read( (char *)(&m_xPos), sizeof(m_xPos) );
    inFile.read( (char *)(&m_yPos), sizeof(m_yPos) );

    for(SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
    {
      CSimVisuSubMenu& subMenu = **it;
      subMenu.load(inFile);
    }

    inFile.close();
    m_loaded = b_TRUE;
    return b_TRUE;
  }

  return b_FALSE;
}

/************************************************************************/
/* drawBackground                                                       */
/************************************************************************/
void CSimVisuMenu::drawBackground( const uint16 xPos,
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
    glVertex3i( top_left_x,     top_left_y,     0);
    glVertex3i( top_right_x,    top_right_y,    0);
    glVertex3i( bottom_right_x, bottom_right_y, 0);
    glVertex3i( bottom_left_x,  bottom_left_y,  0);
  }
  glEnd();

  /* draw border */
  if( borderColor != color_noColor )
  {
    SetColor(borderColor);
    glBegin(GL_LINE_LOOP);
    glVertex3i( top_left_x,    top_left_y,     0);
    glVertex3i( top_right_x,   top_right_y,    0);
    glVertex3i( bottom_right_x,bottom_right_y, 0);
    glVertex3i( bottom_left_x, bottom_left_y,  0);
    glEnd();
  }
}

/************************************************************************/
/* drawActiveMenuFrame                                                  */
/************************************************************************/
void CSimVisuMenu::drawActiveMenuFrame()
{
  for (SubMenuMap_t::iterator it = m_subMenuMap.begin(); it != m_subMenuMap.end(); ++it)
  {
    CSimVisuSubMenu& subMenu = **it;
    /* if active key matches sub menu character a frame around the menu will be drawn */
    if (m_keyActiveMenu == subMenu.getCharacter())
    {
      drawSubMenuFrame(subMenu);
    }
  }
}

/************************************************************************/
/* drawActiveMenuFrame                                                  */
/************************************************************************/
void CSimVisuMenu::drawSubMenuFrame(CSimVisuSubMenu subMenu)
{
  uint16 xPos, yPos;
  subMenu.getPos(xPos, yPos);
  GLint top_left_x = xPos;
  GLint top_left_y = yPos;
  GLint top_right_x = xPos + subMenu.getSubMenuWidth();
  GLint top_right_y = top_left_y;
  GLint bottom_right_x = top_right_x;
  GLint bottom_right_y = yPos + subMenu.getSubMenuHeight();
  GLint bottom_left_x = top_left_x;
  GLint bottom_left_y = bottom_right_y;

  SetColor(color_silver);
  glBegin(GL_LINE_LOOP);
  glVertex3i( top_left_x     -2,  top_left_y     -2, 0);
  glVertex3i( top_right_x    +6,  top_right_y    -2, 0);
  glVertex3i( bottom_right_x +6,  bottom_right_y +2, 0);
  glVertex3i( bottom_left_x  -2,  bottom_left_y  +2, 0);
  glEnd();
}

/************************************************************************/
/* checkKeyActiveMenu                                                   */
/************************************************************************/
void CSimVisuMenu::checkKeyActiveMenu( const t_KeyboardInfo& keyboardInfo,
                                             CSimVisuSubMenu subMenu
                                      )
{
  vector<uint8>  tmpActivatedRows;
  vector<uint16> tmpColActive;
  subMenu.getActivation(tmpActivatedRows, tmpColActive);
  if(  (tmpActivatedRows[0] == SIM_ROW_ACTIVATED)
      &&(m_keyActiveMenu == keyboardInfo.character)
      )
  {
    m_keyActiveMenu = 0;
  }
  else if(  (tmpActivatedRows[0] == SIM_ROW_ACTIVATED)
          &&(m_keyActiveMenu != keyboardInfo.character)
          )
  {
    m_keyActiveMenu = keyboardInfo.character;
  }
  else
  {
    subMenu.checkRowActivation(keyboardInfo);
  }
}