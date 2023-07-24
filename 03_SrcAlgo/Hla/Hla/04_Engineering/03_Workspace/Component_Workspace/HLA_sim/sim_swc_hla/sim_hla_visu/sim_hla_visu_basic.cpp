/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_basic.cpp

  DESCRIPTION:            Draw general things like ROIs, horizon, odometer, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.8 $

  ---*/ /*---

**************************************************************************** */

#include "stdafx.h"
#include "resource.h"
#include <string>
#include <cmath>

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "hla_defs.h"
#include "HLA_DecisionParameters.h"
#include "HLA_MatrixParameters.h"
#ifdef __cplusplus
}
#endif

#include "sim_hla_visu_basic.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")


/* constructor */
CSimHlaVisuBasic::CSimHlaVisuBasic(void)
{
  Init();
}

/* destructor */
CSimHlaVisuBasic::~CSimHlaVisuBasic(void)
{
}

/* basic init */
void CSimHlaVisuBasic::Init()
{
  m_OdometerTurnOffDLL = 0.0f;
  m_OdometerTurnOffECU = 0.0f;
  m_frameCounter = 0u;
}

/* draw functions */
void CSimHlaVisuBasic::drawBasic( const ISimRenderContext*   pContext,
                                        CSimVisuSubMenu*     pSubMenu,
                                        CSimVisuSubMenu*     pSubMenuPlanes,
                                        int&                 textPosX,
                                        int                  textPosY
                                )
{
  /* draw virtual horizon */
  if(pSubMenu->getItemActivation(MENU_BUTTON_GEN_HORIZON) == true)
  {
    drawHorizon(pContext);
  }

  /* draw ROI and distance bars */
  if (pSubMenu->getItemActivation(MENU_BUTTON_GEN_ROI) == true)
  {
    /* draw roi */
    drawROI(pContext);

    /* draw distance bars */
    drawDistBars( pContext ); 
  }

  if (pSubMenu->getItemActivation(MENU_BUTTON_GEN_VEHINFO) == true)
  {
    /* draw odometer information */
    drawOdometer( pContext,
                  textPosY,
                  textPosX
                 );

    int activePlane = VISU_NONE;
    bool isDrawn = false;

    if (pSubMenuPlanes->getItemActivation(MENU_BUTTON_PLANE_ECU) == true)
    {
      drawVDyn( pContext,
                (const reqHlaPrtList_t*)&(pm_hlaMeasdata[VISU_ECU].ReqPorts),
                textPosX,
                textPosY,
                color_ecu
              );
      isDrawn = true;
    }
    if(pSubMenuPlanes->getItemActivation(MENU_BUTTON_PLANE_SIL) == true)
    {
      drawVDyn( pContext,
                (const reqHlaPrtList_t*)&pm_hlaMeasdata[VISU_SIL].ReqPorts,
                textPosX,
                textPosY,
                color_sil
               );
      isDrawn = true;
    }

    if(isDrawn == false)
    {
      drawVDyn( pContext,
                (const reqHlaPrtList_t*)&pm_hlaMeasdata[VISU_SIL].ReqPorts,
                textPosX,
                textPosY,
                color_sil
               );
    }
  }

  draw2EntityVersion( pContext );
}

void CSimHlaVisuBasic::draw2EntityVersion( const ISimRenderContext*  pContext )
{
  const SimHlaProPrtList_t* pRteOutm_SilRoi = &pm_hlaMeasdata[VISU_SIL].ProPorts;
  const SimHlaProPrtList_t* pRteOut_MCU = &pm_hlaMeasdata[VISU_ECU].ProPorts;

  const int textHeight = 13;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-5);
  int x, y, y_offset, y_between, x_offset;

  x = 20;
  y = 5;
  y_offset = 12;
  y_between = 20;
  x_offset = 140;

  /* DLL Version */
  font.BeginRender2D();

  if((pRteOutm_SilRoi != NULL) && (pRteOutm_SilRoi->pAlgoCompState != NULL))
  {
    SetTextColor(color_sil, font);
    font.RenderTextf(x, y, 1, "HLA algo DLL version: ");
    draw2VersionString(font, x+x_offset, y, pRteOutm_SilRoi->pAlgoCompState->uiAlgoVersionNumber);

    y += y_offset;
    font.RenderTextf(x, y, 1, "HLA wrapper DLL version:");
    draw2VersionString(font, x+x_offset, y, pRteOutm_SilRoi->pAlgoCompState->uiApplicationNumber);
  }  
  else
  {
    /* nothing */
  }

  /* MPC Version */
  y = 5;
  x += x_offset + 80;
  if ((pRteOut_MCU != NULL) && (pRteOut_MCU->pAlgoCompState != NULL))
  {
    SetTextColor(color_ecu, font);
    font.RenderTextf(x, y, 1, "HLA algo ECU version:");
    draw2VersionString(font, x+x_offset, y, pRteOut_MCU->pAlgoCompState->uiAlgoVersionNumber);

    y += y_offset;
    font.RenderTextf(x, y, 1, "HLA wrapper ECU version:");
    draw2VersionString(font, x+x_offset, y, pRteOut_MCU->pAlgoCompState->uiApplicationNumber);  
  }
  else
  {
    /* nothing */
  }

  font.EndRender2D();
}

void CSimHlaVisuBasic::draw2EntityVersionVis(const ISimRenderContext*  pContext,
                                             const SimHlaProPrtList_t* pRteOut_MCU
                                             )
{
  const int textHeight = 13;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-5);
  int x, y, x_offset, x_offset2, x_between;

  x = 5;
  y = 0;
  x_offset = 115;
  x_offset2 = 135;
  x_between = 100;

  /* DLL Version */
  font.BeginRender2D();

  /* MPC Version */
  if ((pRteOut_MCU != NULL) && (pRteOut_MCU->pAlgoCompState != NULL))
  {
    SetTextColor(color_ecu, font);

    font.RenderTextf(x, y, 1, "HLA algo ECU version: ");

    x += x_offset;
    draw2VersionString(font, x, y, pRteOut_MCU->pAlgoCompState->uiAlgoVersionNumber);

    x += x_between;
    font.RenderTextf(x, y, 1, "HLA wrapper ECU version:");
  
    x += x_offset2;
    draw2VersionString(font, x, y, pRteOut_MCU->pAlgoCompState->uiApplicationNumber);
  }
  else
  {
    /* nothing */
  }

  font.EndRender2D();
}

void CSimHlaVisuBasic::draw2VersionString(IGDVFont&   font,
                                          int         posx,
                                          int         posy,
                                          uint32      versionNumber
                                         )
{
  uint32 swVerMain, swVerMajor, swVerMinor, swVerBugfix;

  swVerMain    = (versionNumber & 0xFF000000) >> 24;
  swVerMajor   = (versionNumber & 0x00FF0000) >> 16;
  swVerMinor   = (versionNumber & 0x0000FF00) >>  8;
  swVerBugfix  = (versionNumber & 0x000000FF);

  font.RenderTextf(posx, posy, 1, "%2d.%2d.%2d.%2d", swVerMain, swVerMajor, swVerMinor, swVerBugfix);
}

/* ROI drawing function */
void CSimHlaVisuBasic::drawROI(const ISimRenderContext*  pContext)
{
  SetColor(color_red, 0.7f);
  glBegin(GL_LINES);
  {
    glVertex3i(m_SilRoi.X1, m_SilRoi.Y1, 1);
    glVertex3i(m_SilRoi.X1, m_SilRoi.Y2, 1);

    glVertex3i(m_SilRoi.X1, m_SilRoi.Y2, 1);
    glVertex3i(m_SilRoi.X2, m_SilRoi.Y2, 1);

    glVertex3i(m_SilRoi.X2, m_SilRoi.Y2, 1);
    glVertex3i(m_SilRoi.X2, m_SilRoi.Y1, 1);

    glVertex3i(m_SilRoi.X2, m_SilRoi.Y1, 1);
    glVertex3i(m_SilRoi.X1, m_SilRoi.Y1, 1);

    glVertex3i(m_SilRoi.X1, m_SilRoi.Yu, 1);
    glVertex3i(m_SilRoi.X2, m_SilRoi.Yu, 1);

    SetColor(color_yellow, 0.125f);
    glVertex3i(m_SilRoi.X1, m_SilRoi.Yvu, 1);
    glVertex3i(m_SilRoi.X2, m_SilRoi.Yvu, 1);
  }
  glEnd();

}

/* Horizon drawing function */
void CSimHlaVisuBasic::drawHorizon(const ISimRenderContext*  pContext)
{

}

/* Distance bars */
void CSimHlaVisuBasic::drawDistBars( const ISimRenderContext* pContext )
{

}

/* Vehicle dynamics */
void CSimHlaVisuBasic::drawVDyn( const ISimRenderContext*      pContext,
                                              const reqHlaPrtList_t*        pRTEin,
                                                    int&                    textPosX,
                                                    int                     textPosY,
                                              const color_e                 color
                                             )
{
  color_e color_input;
  float32 speed, spdDis, accel, yawEst, wheel;
  RTE_HLAF_HighBeamState hbState;
  MotState_t motion;
  int textLine = 1;
  const int textHeight = 10;
  const int col1 = 0;
  const int col2 = 110;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight - 3);
  color_input = color;


  if (   (pRTEin != NULL)
      && (pRTEin->pVehDyn != NULL)
      && (pRTEin->pVehSig != NULL)
     )
  {
    if (pRTEin->pVehDyn->MotionState.MotState == VDY_LONG_MOT_STATE_MOVE_RWD)
    {
      speed = -(pRTEin->pVehDyn->Longitudinal.Velocity);
    } 
    else
    {
      speed = pRTEin->pVehDyn->Longitudinal.Velocity;
    }

    spdDis  = pRTEin->pVehSig->VehSigAdd.SpeedoSpeed / CML_f_Kmh2Ms;
    accel   = pRTEin->pVehDyn->Longitudinal.Accel;
    yawEst  = pRTEin->pVehDyn->Lateral.YawRate.YawRate;
    wheel   = pRTEin->pVehSig->VehSigAdd.RoadWhlAngFr;
    motion  = pRTEin->pVehDyn->MotionState.MotState;
    hbState = pRTEin->pHlaBusInputSignals->headLightState;

  }
  else
  {
    speed   = 0.0f;
    spdDis  = 0.0f;
    accel   = 0.0f;
    yawEst  = 0.0f;
    wheel   = 0.0f;
    motion  = VDY_LONG_MOT_STATE_STDST;
    hbState = RTE_HLAF_HB_STATE_UNKNOWN;
    color_input = color_red;
  }

  SetColor(color_input, 0.3f);
  drawFilledRect(textPosX - 5, textPosY, textPosX + 179, textPosY + 92);
  SetColor(color_input);
  drawRect(      textPosX - 5, textPosY, textPosX + 179, textPosY + 92);

  font.BeginRender2D();
  {
    SetTextColor(color_white, font);
    /* headline */
    font.RenderTextf(textPosX + col1, textPosY + (2), 1, "Vehicle State");
    textLine++;
    /* draw velocity */
    font.RenderTextf(textPosX + col1, textPosY + (textLine * (textHeight + 1)), 1, "Speed [km/h] (car|disp):");
    font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "%.2f / %.2f", speed * CML_f_Kmh2Ms, spdDis * CML_f_Kmh2Ms);
    textLine++;
    /* draw long. acc */
    font.RenderTextf(textPosX + col1, textPosY + (textLine * (textHeight + 1)), 1, "Long. Accel [m/s]:");
    font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "%.2f", accel);
    textLine++;
    /* draw est yaw */
    font.RenderTextf(textPosX + col1, textPosY + (textLine * (textHeight + 1)), 1, "Est. Yaw Rate[Deg/s]:");
    font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "%.2f", CML_Rad2Deg(yawEst));
    textLine++;
    /* draw steer wheel */
    font.RenderTextf(textPosX + col1, textPosY + (textLine * (textHeight + 1)), 1, "Steering Wheel [Deg]:");
    font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "%.2f", CML_Rad2Deg(wheel));
    textLine++;
    /* draw motion state */
    font.RenderTextf(textPosX + col1, textPosY + (textLine * (textHeight + 1)), 1, "Motion State:");
    switch (motion)
    {
    case 0:
      // VDY_LONG_MOT_STATE_MOVE
      SetTextColor(color_dark_grey, font);
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "Unknown Move");
      break;
    case 1:
      // VDY_LONG_MOT_STATE_MOVE_FWD
      SetTextColor(color_green, font);
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "Move forward");
      break;
    case 2:
      // VDY_LONG_MOT_STATE_MOVE_RWD
      SetTextColor(color_dark_green, font);
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "Move reverse");
      break;
    case 3:
      // VDY_LONG_MOT_STATE_STDST
      SetTextColor(color_red, font);
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "Standstill");
      break;
    default:
      SetTextColor(color_grey, font);
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "Unknown");
      break;
    }
    textLine++;
    SetTextColor(color_white, font);
    /* draw highbeam state */
    font.RenderTextf(textPosX + col1, textPosY + (textLine * (textHeight + 1)), 1, "Highbeam State:");
    if (hbState == RTE_HLAF_HB_STATE_FULL_ON)
    {
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "ON");
    }
    else
    {
      font.RenderTextf(textPosX + col2, textPosY + (textLine * (textHeight + 1)), 1, "OFF");
    }
  }
  font.EndRender2D();
  textPosX += 185;
}

/* Odometer statistics */
void CSimHlaVisuBasic::drawOdometer( const ISimRenderContext*  pContext,
                                     const int                 textPosY,
                                           int&                textPosX
                                   )
{

}

