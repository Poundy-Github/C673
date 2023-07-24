/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_color.h

  DESCRIPTION:            Definition of several colors for openGl drawing

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.7 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_COLOR_H
#define SIM_VISU_COLOR_H

/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include <gl/GL.h>
#include "sim_gdvfont_ifc.h"


typedef enum
{
  color_noColor,
  color_black,
  color_red,
  color_bright_red,
  color_green,
  color_blue,
  color_yellow,
  color_cyan,
  color_magenta,
  color_rose,
  color_grey,
  color_light_grey,
  color_dark_grey,
  color_dark_green,
  color_lawn_green,
  color_dark_red,
  color_purple,
  color_teal,
  color_dark_blue,
  color_royal_blue,
  color_orange,
  color_bronze,
  color_silver,
  color_gold,
  color_steel_blue,
  color_pink,
  color_pastel_blue,
  color_sil,
  color_ecu,
  color_eth,
  color_can,
  color_evm,
  color_inp,
  color_white
} color_e;



/* main class -------------------------------------------------------------- */
class CSimColor
{

public:

  CSimColor  ();
  ~CSimColor ();

  void SetColor     ( const color_e color, const float alpha = 1.0f ) const;
  void SetTextColor ( const color_e color, IGDVFont& font, const float alpha = 1.0f) const;
  void ConvertColor ( const color_e color, float &red, float &green, float &blue) const;

protected:
private:
};


#endif // SIM_VISU_COLOR_H
