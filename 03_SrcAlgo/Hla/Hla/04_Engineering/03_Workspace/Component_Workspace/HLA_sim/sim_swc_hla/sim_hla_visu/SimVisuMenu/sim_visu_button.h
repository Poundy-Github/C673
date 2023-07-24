/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_button.h

  DESCRIPTION:            Drawing of button in menu which can be activated 
                          or deactivated

  CPU:                    Independent

  CREATION DATE:          2015-08-13

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_BUTTON_H
#define SIM_VISU_BUTTON_H

#include "stdafx.h"

#include "sim_visu_interface.h"
#include "sim_visu_color.h"
#include "sim_visu_font.h"

using namespace std;


/************************************************************************/
/*  CSimVisuMenuButton                                                   */
/************************************************************************/
class CSimVisuMenuButton
  : public CSimFont
  , public CSimColor
{
public:
  CSimVisuMenuButton ();
  CSimVisuMenuButton ( const uint16  xPos,
                       const uint16  yPos,
                       const uint16  buttonWidth,
                       const uint16  buttonHeight,
                       const color_e frameColor,
                       const bool    isLockButton,
                       const color_e fillColor = color_noColor
                     );
  ~CSimVisuMenuButton ();

  void SetPos ( const uint16 xPos, 
                const uint16 yPos, 
                const uint16 buttonWidth = 0, 
                const uint16 buttonHeight = 0 
              );

  void pressButton();
  void draw ( const ISimRenderContext* const pContext );
  bool checkButtonPressed ( const t_MouseInfo& mouseInfo );
  void setLock( const bool lock);
  bool isLocked() const;
  uint16 getButtonHeight() const;
  uint16 getButtonWidth() const;
  bool getActivation() const; 

protected:

private:
  void drawSign();

  uint16 m_xPos;         /* x postion to draw at */
  uint16 m_yPos;         /* y postion to draw at */
  uint16 m_buttonWidth;  /* width of button*/
  uint16 m_buttonHeight; /* height of button*/
  bool m_pressed;
  bool m_lockButton;
  color_e m_frameColor;  
  color_e m_fillColor;
};

#endif //SIM_VISU_BUTTON_H
