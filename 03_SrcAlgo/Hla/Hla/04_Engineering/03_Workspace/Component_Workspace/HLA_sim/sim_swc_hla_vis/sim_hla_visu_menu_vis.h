/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_menu_vis.h

  DESCRIPTION:            Drawing of menu and handling of activated submenus

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.1 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_MENUVIS_H
#define SIM_HLA_VISU_MENUVIS_H

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>

#include "sim_hla_visu_type.h"
#include "sim_hla_meas.h"
#include "sim_hla_visu_color.h"
#include "sim_hla_visu_font.h"
#include "sim_hla_visu_menusub.h"

#include "glob_type.h"

using namespace std;

/************************************************************************/
/************************************************************************/
/*  CSimHlaMenuVisOnly                                                  */
/************************************************************************/
/************************************************************************/

class CSimHlaMenuVisOnly
  :public virtual CSimHlaColor
{
public:
  CSimHlaMenuVisOnly ();
  CSimHlaMenuVisOnly (const uint16 xPos, const uint16 yPos);
  ~CSimHlaMenuVisOnly ();

  void checkSubMenuActivation(  mouseInfo& mouseInfo, keyboardInfo& keyboardInfo );
  void draw( const ISimRenderContext* pContext );
  void SetPos ( const uint16 xPos, const uint16 yPos, const uint16 menuWidth = 0, const uint16 menuHeight = 0 );
  uint16 getMenuWidth();
  uint16 getMenuHeight();
  
  void updateOverlay( SimuOverlayActivation& overlayActivation, boolean ETH_KAFASInputs, boolean CAN_bKafas2_ObjMabAsst_Valid );

protected:

private:
  void drawBackground(const uint16 xPos,
                      const uint16 yPos,
                      const uint16 width,
                      const uint16 height,
                      const color_e color = color_noColor,
                      const float32 alpha = 1.0f,
                      const color_e borderColor = color_noColor
                      );

  uint16 m_xPos; /* x postion to draw at */
  uint16 m_yPos; /* y postion to draw at */
  uint16 m_menuWidth;
  uint16 m_menuHeight;

  int m_oldLclickCnt;
  int m_oldKeyCnt;
  int m_oldWheelCnt;
 
  CSimHlaSubMenu m_general;
};

#endif // SIM_HLA_VISU_MENUVIS_H