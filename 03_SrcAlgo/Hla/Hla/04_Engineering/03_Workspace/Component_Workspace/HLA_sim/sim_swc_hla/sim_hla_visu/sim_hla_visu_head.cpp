/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_head.cpp

  DESCRIPTION:            Virtual class providing importand data for all child
                          classes

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */

#include "sim_hla_visu_head.h"


CSimHlaVisuHead::CSimHlaVisuHead() :
  m_DrawImageOffsetX(0),
  m_DrawImageOffsetY(30)
{
}

CSimHlaVisuHead::~CSimHlaVisuHead()
{
}

void CSimHlaVisuHead::update_drawColor(int measfreezeVisu)
{
  m_drawColor = color_sil;
  switch(measfreezeVisu)
  {
    case VISU_SIL:
    {
      m_drawColor = color_sil;
      break;
    }
    case VISU_ECU:
    {
      m_drawColor = color_ecu;
      break;
    }
    case VISU_EVM:
    {
      m_drawColor = color_evm;
      break;
    }
    case VISU_ENET:
    {
      m_drawColor = color_eth;
      break;
    }
    case VISU_CAN:
    {
      m_drawColor = color_can;
      break;
    }
    default:
    {
      m_drawColor = color_sil;
      break;
    }
  }
  return;
}