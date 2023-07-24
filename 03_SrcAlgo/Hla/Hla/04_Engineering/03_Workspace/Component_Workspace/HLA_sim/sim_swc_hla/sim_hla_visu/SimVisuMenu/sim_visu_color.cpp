/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_color.cpp

  DESCRIPTION:            Definition of several colors for openGl drawing

  CPU:                    Independent

  CREATION DATE:          2016-02-02

  VERSION:                $Revision: 1.6 $

  ---*/ /*---

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_visu_color.h"


CSimColor::CSimColor()
{
}


CSimColor::~CSimColor()
{
}

void CSimColor::SetColor( const color_e color, const float alpha /* = 1.0f */) const
{
  float red, green, blue;
  ConvertColor(color, red, green, blue);
  glColor4f(red, green, blue, alpha);
}

void CSimColor::SetTextColor( const color_e color, IGDVFont& font, const float alpha /* = 1.0f */) const
{
  float red, green, blue;
  ConvertColor(color, red, green, blue);
  font.SetTextColor(red, green, blue);
}

void CSimColor::ConvertColor( const color_e color, float &red, float &green, float &blue ) const
{
  switch(color)
  {
  case color_black:
    red = 0.0f; green = 0.0f; blue = 0.0f;
    break;
  case color_red:
    red = 1.0f; green = 0.0f; blue = 0.0f;
    break;
  case color_bright_red:
    red = 1.0f; green = 0.3f; blue = 0.3f;
    break;
  case color_green:
    red = 0.0f; green = 1.0f; blue = 0.0f;
    break;
  case color_blue:
    red = 0.0f; green = 0.0f; blue = 1.0f;
    break;
  case color_yellow:
    red = 1.0f; green = 1.0f; blue = 0.0f;
    break;
  case color_cyan:
    red = 0.0f; green = 1.0f; blue = 1.0f;
    break;
  case color_magenta:
    red = 1.0f; green = 0.0f; blue = 1.0f;
    break;
  case color_rose:
    red = 1.0f; green = 0.66f; blue = 0.66f;
    break;
  case color_grey:
    red = 0.5f; green = 0.5f; blue = 0.5f;
    break;
  case color_light_grey:
    red = 0.82f; green = 0.82f; blue = 0.82f;
    break;
  case color_dark_grey:
    red = 0.35f; green = 0.35f; blue = 0.35f;
    break;
  case color_dark_green:
    red = 0.0f; green = 0.5f; blue = 0.0f;
    break;
  case color_dark_red:
    red = 0.5f; green = 0.0f; blue = 0.0f;
    break;
  case color_dark_blue:
    red = 0.0f; green = 0.0f; blue = 0.5f;
    break;
  case color_purple:
    red = 0.5f; green = 0.0f; blue = 0.5f;
    break;
  case color_teal:
    red = 0.0f; green = 0.5f; blue = 0.5f;
    break;
  case color_orange:
    red = 1.0f; green = 0.64f; blue = 0.0f;
    break;
  case color_bronze:
    red = 0.8f; green = 0.5f; blue = 0.19f;
    break;
  case color_silver:
    red = 0.75f; green = 0.75f; blue = 0.75f;
    break;
  case color_gold:
    red = 1.0f; green = 0.84f; blue = 0.0f;
    break;
  case color_steel_blue:
    red = 0.27f; green = 0.5f; blue = 0.7f;
    break;
  case color_pink:
    red = 1.0f; green = 0.5f; blue = 0.5f;
    break;
  case color_pastel_blue:
    red = 0.5f; green = 0.5f; blue = 1.0f;
    break;
  case color_sil:
    red = 0.0f; green = 0.58f; blue = 1.0f;
    break;
  case color_ecu:
    red = 0.1f; green = 0.7f; blue = 0.0f;
    break;
  case color_evm:
    red = 0.1f; green = 0.8f; blue = 0.7f;
    break;
  case color_eth:
    red = 1.0f; green = 0.5f; blue = 0.0f;
    break;
  case color_can:
    red = 1.0f; green = 0.0f; blue = 1.0f;
    break;
  case color_inp:
    red = 1.0f; green = 1.0f; blue = 0.0f;
    break;
  case color_white:
  default:
    red = 1.0f; green = 1.0f; blue = 1.0f;
    break;
  }

}
