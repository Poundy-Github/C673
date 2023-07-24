/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_menu.h

  DESCRIPTION:            Drawing of menu and handling of activated submenus

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.5 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_MENU_H
#define SIM_VISU_MENU_H

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>

#include "sim_visu_color.h"
#include "sim_visu_font.h"
#include "sim_visu_menusub.h"
#include "sim_visu_button.h"

using namespace std;

/************************************************************************/
/************************************************************************/
/*  CSimVisuMenu                                                         */
/************************************************************************/
/************************************************************************/
class CSimVisuMenu
  :public virtual CSimColor
{
public:
  CSimVisuMenu ();
  CSimVisuMenu (const uint16 xPos, const uint16 yPos);
  ~CSimVisuMenu ();

  bool SaveMenu(const string componentName);
  int tmpSave();
  bool LoadVisuMenu (const string componentName);
  void DrawMenu( const ISimRenderContext* const pContext, 
                 const t_MouseInfo&             mouseInfo, 
                 const t_KeyboardInfo&          keyboardInfo
                );
  void SetMenuPosition( const uint16 xPos, 
                        const uint16 yPos, 
                        const uint16 menuWidth = 0, 
                        const uint16 menuHeight = 0
                       );
  boolean CheckSubMenuActivation( const t_KeyboardInfo& keyboardInfo,
                                        t_MouseInfo&    mouseInfo
                                 );
  uint16 GetMenuWidth();
  uint16 GetMenuHeight();
  void InitMenu();

protected:

  typedef std::vector<CSimVisuSubMenu*> SubMenuMap_t;

  SubMenuMap_t m_subMenuMap;

private:


  void drawBackground( const uint16 xPos,
                       const uint16 yPos,
                       const uint16 width,
                       const uint16 height,
                       const color_e color = color_noColor,
                       const float32 alpha = 1.0f,
                       const color_e borderColor = color_noColor
                     );

  void drawActiveMenuFrame();

  void drawSubMenuFrame(CSimVisuSubMenu subMenu);

  void checkKeyActiveMenu( const t_KeyboardInfo& keyboardInfo,
                                 CSimVisuSubMenu subMenu
                          );
  void calculateMenuSize();

  uint16 m_xPos; /* x position to draw at */
  uint16 m_yPos; /* y position to draw at */
  uint16 m_menuWidth;
  uint16 m_menuHeight;
  uint16 m_maxSubMenuWidth;
  uint16 m_maxSubMenuHeight1st;

  int m_oldLclickCnt;
  int m_oldKeyCnt;
  int m_oldWheelCnt;

  bool m_fixMenu; /* check if menu is fixed */
  bool m_loaded;  /* check if menu have just been loaded */

  char m_keyActiveMenu;

  CSimVisuMenuButton m_minimizeButton;
  CSimVisuMenuButton m_freezeMenuButton;
};

#endif // SIM_VISU_MENU_H


