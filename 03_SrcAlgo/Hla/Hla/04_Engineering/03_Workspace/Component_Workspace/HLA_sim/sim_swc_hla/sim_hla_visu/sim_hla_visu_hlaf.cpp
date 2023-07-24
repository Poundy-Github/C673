/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_hlaf.h

  DESCRIPTION:            Drawing of interfaces for hlaf and hlar

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.11.1.3 $

  ---*/ /*---

**************************************************************************** */

#include "stdafx.h"
#include "resource.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "HLA_DecisionParameters.h"
#include "HLA_MatrixParameters.h"
#ifdef __cplusplus
}
#endif

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#include <stdio.h>
#include <string>
#include <cmath>

#include "sim_hla_visu_table.h"

#include "sim_hla_visu_hlaf.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")


CSimHlaVisuHlaf::CSimHlaVisuHlaf()
//: 
{
}

CSimHlaVisuHlaf::~CSimHlaVisuHlaf()
{
}

void CSimHlaVisuHlaf::drawHLAF(const ISimRenderContext*  pContext, CSimVisuSubMenu* pInterfaces, CSimVisuSubMenu* pFunction)
{

  /* draw recognition output */
  if(pInterfaces->getItemActivation(MENU_BUTTON_INTF_LSD))
  {
    drawLsdInputInterface( pContext, 
                           pm_rteInputs, 
                           m_drawColor,
                           pm_hlaInternMeasdata->pHlafData,
                           m_drawPlane,
                           0 //TODO planesToDraw
                         );

  }

  if(pInterfaces->getItemActivation(MENU_BUTTON_INTF_LIGHT_SIZE))
  {
    drawLsdLightSize( pContext, 
                      pm_rteInputs, 
                      m_drawColor
                    );

  }

  /* draw input interface */
  if (pInterfaces->getItemActivation(MENU_BUTTON_INTF_BUS) == true)
  {
    drawInputInterface( pContext,
                        pm_rteInputs,
                        m_drawColor,
                        0.1f
                       );
  }

  /* draw function output */
  if(    (pFunction->getItemActivation(MENU_BUTTON_FUNC_MATRIX))
      && (pm_rteInputs)
    )
  { 
    const RTE_HLAF_MatrixGFA_t* pMatrixGFA;
          uint32                nGFA;
          bool                  inputAvailable = false;
    /* draw requested HB state in image */
    /* HLA Matrix */
    if(pm_rteOutputs)
    {        
      /* Set GFA and nGFA depending of project and subkey */
      if(pm_rteOutputs->pHlaf_HeadlightControl)
      {
        pMatrixGFA = pm_rteOutputs->pHlaf_HeadlightControl->Matrix.GFA;
        nGFA = pm_rteOutputs->pHlaf_HeadlightControl->Matrix.nGFA;
        inputAvailable = true;
      }
      /* draw High beam in Image */
      if(inputAvailable)
      {
        drawGFAs( pContext,
                  (pFunction->getItemActivation(MENU_BUTTON_FUNC_MATRIX, MENU_BUTTON_FUNC_MATRIX_S_CAM)),
                  pm_rteInputs,
                  pMatrixGFA,
                  nGFA,
                  m_drawColor,
                  0.2f
                  );
      }
    }
  }
}

void CSimHlaVisuHlaf::drawHLAFInfo( const ISimRenderContext*  pContext,
                                          CSimVisuSubMenu*    pInterfacesMenu,
                                          CSimVisuSubMenu*    pFunctionMenu,
                                          int&                textPosX
                                   )
{
  /* draw recognition output */
  if (pInterfacesMenu->getItemActivation(MENU_BUTTON_INTF_LSD) == true)
  {
    drawOutputInterfaceInfo(pContext, 
                            pm_rteInputs,
                            textPosX
                           );
  }


  /* draw input interface */
  if (pInterfacesMenu->getItemActivation(MENU_BUTTON_INTF_BUS) == true)
  {
    drawInputInterfaceDetailsText(pContext,
                                  pm_rteInputs,
                                  textPosX
                                  );
  }

  /* draw textual information */
  if (pFunctionMenu->getItemActivation(MENU_BUTTON_FUNC_OUTPUT) == true)
  {
    /* HLAF Output */
    drawHLAFOutput( pContext,
                    pm_rteOutputs, 
                    m_drawColor, 
                    textPosX
                    );
  }
  else if(pFunctionMenu->getItemActivation(MENU_BUTTON_FUNC_MATRIX) == true)
  {
    drawHLAFMatrix( pContext,
                    pm_rteInputs, 
                    pm_rteOutputs,
                    textPosX
                  );
  }

  if (pFunctionMenu->getItemActivation(MENU_BUTTON_FUNC_HB_DATA) == true)
  {
    drawHLAFHBData( pContext,
                    pm_hlaInternMeasdata->pHlafData
                   );
  }

}

void CSimHlaVisuHlaf::Init()
{
}

/* draw glare free areas in image */
void CSimHlaVisuHlaf::drawGFAs(const ISimRenderContext*    pContext,
                                     boolean               bDrawAng,
                               const reqHlaPrtList_t*      pRTEin,
                               const RTE_HLAF_MatrixGFA_t* pGFA,
                               const uint32                nGFA,
                               const color_e               color,
                                     float32               alpha,
                                     sint16                drawOffsetX, /* = 0 */
                                     sint16                drawOffsetY  /* = 0 */
                              )
{
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", 8);

  uint32 iGFA;

  float32 LeftBorderX[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];
  float32 RightBorderX[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];
  float32 LowerBorderY[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];
  float32 UpperBorderY[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];

  float32 FocalY = 0;
  float32 FocalX = 0;
  float32 yFOE = 0;
  float32 xFOE = 0;

  const RTE_HLAF_MatrixGFA_t* pGFAToDraw;

  /****************************************************************************************************************/
  /*                                                                                                              */
  /*     (X1, Y1)             (LeftBorderX, Y1)                     (RightBorderX, Y1)         (X2, Y1)           */
  /*                                  | (*1)                                |(*4)                                 */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*      (LeftBorderX, UpperBorderY) | ------------------------------------| (RightBorderX, UpperBorderY)        */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*                                  | (*2)                                |(*3)                                 */
  /*      (LeftBorderX, LowerBorderY) |-------------------------------------| (RightBorderX, LowerBorderY)        */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*                                  |                                     |                                     */
  /*     (X1, Y2)             (LeftBorderX, Y2)                    (RightBorderX, Y2)        (X2, Y2)             */
  /*                                                                                                              */
  /****************************************************************************************************************/

  if(pRTEin && pGFA)
  {
    /* get data */
    FocalY = pRTEin->pMonoCalibration->sIntrinsic.fFocalY;
    FocalX = pRTEin->pMonoCalibration->sIntrinsic.fFocalX;
    yFOE = pRTEin->pLsdLightObjectList->roi.yFOE;
    xFOE = pRTEin->pLsdLightObjectList->roi.xFOE;

    for(iGFA = 0; iGFA < nGFA; iGFA++)
    {
      pGFAToDraw = &pGFA[iGFA];

      /* calculate borders */
      if(bDrawAng == b_TRUE)
      {
        LeftBorderX[iGFA] = xFOE - (GDBtan_52(pGFAToDraw->BndryLeft_Ang) * FocalX);
        RightBorderX[iGFA] = xFOE - (GDBtan_52(pGFAToDraw->BndryRight_Ang) * FocalX);
      }
      else
      {
        LeftBorderX[iGFA] = xFOE - (GDBtan_52(pGFAToDraw->BndryLeft_Ang_Cam) * FocalX);
        RightBorderX[iGFA] = xFOE - (GDBtan_52(pGFAToDraw->BndryRight_Ang_Cam) * FocalX);
      }
      LowerBorderY[iGFA] = (GDBtan_52(pGFAToDraw->BndryLower_Ang_Cam) * FocalY) + yFOE;
      UpperBorderY[iGFA] = (GDBtan_52(pGFAToDraw->BndryUpper_Ang_Cam) * FocalY) + yFOE;
       
    }

    /* get sorted index of GFA (from left 2 right) */
    uint32 GFAIndexFromLeft2Right[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];
    float32 AngMax_prev = CML_Deg2Rad(90.0f);

    for(iGFA = 0; iGFA < nGFA; iGFA++)
    {
      uint32 iGfaMax = 0;
      float32 AngMax = CML_Deg2Rad(-90.0f);

      for(uint32 iGFA1 = 0; iGFA1 < nGFA; iGFA1++)
      {

        pGFAToDraw = &pGFA[iGFA1];

        if(   (pGFAToDraw->BndryLeft_Ang > AngMax)
           && (pGFAToDraw->BndryLeft_Ang < AngMax_prev)
          ) 
        {
          iGfaMax = iGFA1;
          AngMax = pGFAToDraw->BndryLeft_Ang;
        }
      }

      GFAIndexFromLeft2Right[iGFA] = iGfaMax;
      AngMax_prev = AngMax;
    }

    glEnable (GL_BLEND); 
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    SetColor(color, alpha);
    glBegin(GL_QUADS);
    {
      /* draw left area of GFA  (1st part)*/
      glVertex3f((float)m_HLARoi.X1, (float)m_HLARoi.Y1, 1);
      glVertex3f((float)m_HLARoi.X1, (float)m_HLARoi.Y2, 1);

      for(iGFA = 0; iGFA < nGFA; iGFA++)
      {
        uint32 iGFAs = GFAIndexFromLeft2Right[iGFA];

        /* draw left area of GFA  (2nd part)*/
        glVertex3f(LeftBorderX[iGFAs], (float)m_HLARoi.Y2, 1);
        glVertex3f(LeftBorderX[iGFAs], (float)m_HLARoi.Y1, 1);

        /* draw area below */
        glVertex3f(LeftBorderX[iGFAs], LowerBorderY[iGFAs], 1);
        glVertex3f(LeftBorderX[iGFAs], (float)m_HLARoi.Y2, 1);
        glVertex3f(RightBorderX[iGFAs], (float)m_HLARoi.Y2, 1);
        glVertex3f(RightBorderX[iGFAs], LowerBorderY[iGFAs], 1);

        /* draw area above */
        glVertex3f(LeftBorderX[iGFAs], (float)m_HLARoi.Y1, 1);
        glVertex3f(LeftBorderX[iGFAs], UpperBorderY[iGFAs], 1);
        glVertex3f(RightBorderX[iGFAs], UpperBorderY[iGFAs], 1);
        glVertex3f(RightBorderX[iGFAs], (float)m_HLARoi.Y1, 1);

        /* draw right area of GFA (1st part)*/
        glVertex3f(RightBorderX[iGFAs], (float)m_HLARoi.Y1, 1);
        glVertex3f(RightBorderX[iGFAs], (float)m_HLARoi.Y2, 1);

      }

      /* draw right area of GFA (2nd part)*/
      glVertex3f((float)m_HLARoi.X2, (float)m_HLARoi.Y2, 1);
      glVertex3f((float)m_HLARoi.X2, (float)m_HLARoi.Y1, 1);

    }
    glEnd();

    /* draw all GFA Lines */
    SetColor(color);
    glBegin(GL_LINES);
    {
      for(iGFA = 0; iGFA < nGFA; iGFA++)
      {
        /* lower border of GFA */
        glVertex3i((int)(LeftBorderX[iGFA] +drawOffsetX + 0.5f), (int)(LowerBorderY[iGFA] + drawOffsetY + 0.5f), 1);
        glVertex3i((int)(RightBorderX[iGFA] +drawOffsetX + 0.5f), (int)(LowerBorderY[iGFA] + drawOffsetY + 0.5f), 1);

        /* upper border of GFA */
        glVertex3i((int)(LeftBorderX[iGFA] +drawOffsetX + 0.5f), (int)(UpperBorderY[iGFA] + drawOffsetY + 0.5f), 1);
        glVertex3i((int)(RightBorderX[iGFA] +drawOffsetX + 0.5f), (int)(UpperBorderY[iGFA] + drawOffsetY + 0.5f), 1);

        /* left border of GFA */
        glVertex3i((int)(LeftBorderX[iGFA] +drawOffsetX + 0.5f), (int)(m_HLARoi.Y1 + drawOffsetY + 0.5f), 1);
        glVertex3i((int)(LeftBorderX[iGFA] +drawOffsetX + 0.5f), (int)(LowerBorderY[iGFA] + drawOffsetY + 0.5f), 1);

        /* right border of GFA */
        glVertex3i((int)(RightBorderX[iGFA] +drawOffsetX + 0.5f), (int)(m_HLARoi.Y1 + drawOffsetY + 0.5f), 1);
        glVertex3i((int)(RightBorderX[iGFA] +drawOffsetX + 0.5f), (int)(LowerBorderY[iGFA] + drawOffsetY + 0.5f), 1);
      }  
    }
    glEnd();

    /* Draw GFA index */
    font.BeginRender2D();
    SetTextColor(color_orange, font);
    for(iGFA = 0; iGFA < nGFA; iGFA++)
    {
      /* draw number at upper left border of GFA */
      font.RenderTextf(LeftBorderX[iGFA], UpperBorderY[iGFA], 1, "%d", iGFA);
    }
    font.EndRender2D();

  }
}

/*******************************************************************************************/
/******************************** HLAF Output  *********************************************/
/*******************************************************************************************/
void CSimHlaVisuHlaf::drawHLAFOutput(const ISimRenderContext*  pContext,
                                     const SimHlaProPrtList_t* pRTEout,
                                     const color_e             color,
                                           int&                textPosX
                                    )
{
  char Txt[255];

  CSimTable foutList;
  uint16 row = 0;
  color_e drawColor = color_yellow;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  IGDVFont& font = pContext->GetWindow().GetFontInterface("", 7);
 
  if ( (pRTEout != NULL) && (pRTEout->pHlaf_HeadlightControl != NULL) && (pRTEout->pHlaf_HeadlightControl->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    SetTextColor(color_white, font);
  
    foutList.SetCell(row, COL_0, "HLAF Output", color);

    foutList.SetCell(++row, COL_0, "HeadlightControl:", drawColor);

    switch(pRTEout->pHlaf_HeadlightControl->Common.TrafficStyle)
    {
    case RTE_HLA_TRAFFIC_STYLE_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "(%d) TRAFFIC_STYLE_UNKNOWN", pRTEout->pHlaf_HeadlightControl->Common.TrafficStyle);
      break;
    case RTE_HLA_TRAFFIC_STYLE_RHT:
      _snprintf(tmpTxt, maxTxt, "(%d) TRAFFIC_STYLE_RHT", pRTEout->pHlaf_HeadlightControl->Common.TrafficStyle);
      break;
    case RTE_HLA_TRAFFIC_STYLE_LHT:
      _snprintf(tmpTxt, maxTxt, "(%d) TRAFFIC_STYLE_LHT", pRTEout->pHlaf_HeadlightControl->Common.TrafficStyle);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "Error");
      break;
    }
    foutList.SetRow<char*>(++row, drawColor, "e_TrafficStyle:", tmpTxt);

    switch(pRTEout->pHlaf_HeadlightControl->Common.CityState)
    {
    case RTE_HLAR_CITY_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "CITY_UNKNOWN", pRTEout->pHlaf_HeadlightControl->Common.CityState);
      break;
    case RTE_HLAR_CITY_NOT_DTCD:
      _snprintf(tmpTxt, maxTxt, "CITY_NOT_DTCD", pRTEout->pHlaf_HeadlightControl->Common.CityState);
      break;
    case RTE_HLAR_CITY_DTCD:
      _snprintf(tmpTxt, maxTxt, "CITY_DTCD", pRTEout->pHlaf_HeadlightControl->Common.CityState);
      break;
    case RTE_HLAR_CITY_MAYBE:
      _snprintf(tmpTxt, maxTxt, "CITY_MAYBE", pRTEout->pHlaf_HeadlightControl->Common.CityState);
      break;
    case RTE_HLAR_CITY_INVALID:
      _snprintf(tmpTxt, maxTxt, "CITY_INVALID", pRTEout->pHlaf_HeadlightControl->Common.CityState);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "Error");
      break;
    }
    foutList.SetRow<char*>(++row, drawColor, "e_CityState:", tmpTxt);   

    switch(pRTEout->pHlaf_HeadlightControl->Common.WeatherState)
    {
    case RTE_HLAR_WEATHER_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "WEATHER_UNKNOWN", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    case RTE_HLAR_WEATHER_GOOD:
      _snprintf(tmpTxt, maxTxt, "WEATHER_GOOD", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    case RTE_HLAR_WEATHER_BAD:
      _snprintf(tmpTxt, maxTxt, "WEATHER_BAD", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    case RTE_HLAR_WEATHER_LIGHT_FOG:
      _snprintf(tmpTxt, maxTxt, "WEATHER_LIGHT_FOG", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    case RTE_HLAR_WEATHER_MEDIUM_FOG:
      _snprintf(tmpTxt, maxTxt, "WEATHER_MEDIUM_FOG", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    case RTE_HLAR_WEATHER_HEAVY_FOG:
      _snprintf(tmpTxt, maxTxt, "WEATHER_HEAVY_FOG", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    case RTE_HLAR_WEATHER_INVALID:
      _snprintf(tmpTxt, maxTxt, "WEATHER_INVALID", pRTEout->pHlaf_HeadlightControl->Common.WeatherState);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "Error");
      break;
    }
    foutList.SetRow<char*>(++row, drawColor, "e_WeatherState:", tmpTxt);

    switch(pRTEout->pHlaf_HeadlightControl->Common.TunnelState)
    {
    case RTE_HLAR_TUNNEL_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "TUNNEL_UNKNOWN", pRTEout->pHlaf_HeadlightControl->Common.TunnelState);
      break;
    case RTE_HLAR_TUNNEL_NOT_DTCD:
      _snprintf(tmpTxt, maxTxt, "TUNNEL_NOT_DTCD", pRTEout->pHlaf_HeadlightControl->Common.TunnelState);
      break;
    case RTE_HLAR_TUNNEL_UPFRONT:
      _snprintf(tmpTxt, maxTxt, "TUNNEL_UPFRONT", pRTEout->pHlaf_HeadlightControl->Common.TunnelState);
      break;
    case RTE_HLAR_TUNNEL_INSIDE:
      _snprintf(tmpTxt, maxTxt, "TUNNEL_INSIDE", pRTEout->pHlaf_HeadlightControl->Common.TunnelState);
      break;
    case RTE_HLAR_TUNNEL_INVALID:
      _snprintf(tmpTxt, maxTxt, "TUNNEL_INVALID", pRTEout->pHlaf_HeadlightControl->Common.TunnelState);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "Error");
      break;
    }
    foutList.SetRow<char*>(++row, drawColor, "e_TunnelState:", tmpTxt);

    switch(pRTEout->pHlaf_HeadlightControl->Common.MotorwayState)
    {
    case RTE_HLAF_MTWY_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "(%d) RTE_HLAF_MTWY_UNKNOWN", pRTEout->pHlaf_HeadlightControl->Common.MotorwayState);
      break;
    case RTE_HLAF_MTWY_COUNTRY:
      _snprintf(tmpTxt, maxTxt,"(%d) RTE_HLAF_MTWY_COUNTRY", pRTEout->pHlaf_HeadlightControl->Common.MotorwayState);
      break;
    case RTE_HLAF_MTWY_MOTORWAY:
      _snprintf(tmpTxt, maxTxt, "(%d) RTE_HLAF_MTWY_MOTORWAY", pRTEout->pHlaf_HeadlightControl->Common.MotorwayState);
      break;
    case RTE_HLAF_MTWY_INVALID:
      _snprintf(tmpTxt, maxTxt, "(%d) RTE_HLAF_MTWY_INVALID", pRTEout->pHlaf_HeadlightControl->Common.MotorwayState);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "Error");
      break;
    }
    foutList.SetRow<char*>(++row, drawColor, "e_MotorwayState:", tmpTxt);

    getHLABrightnessStateTxt(pRTEout->pHlaf_HeadlightControl->Common.BrightnessState, Txt);
    foutList.SetRow<char*>(++row, drawColor, "e_BrightnessState:", Txt);

    getHLASensModeTxt(pRTEout->pHlaf_HeadlightControl->Common.SensMode, Txt);
    foutList.SetRow<char*>(++row, drawColor, "e_SensMode:", Txt);

    getHLASceneInfoTxt(pRTEout->pHlaf_HeadlightControl->Common.SceneInfo, Txt);
    foutList.SetRow<char*>(++row, drawColor, "SceneInfo:", Txt);

    getHLASpeedStateTxt(pRTEout->pHlaf_HeadlightControl->Common.SpeedState, Txt);
    foutList.SetRow<char*>(++row, drawColor, "SpeedState:", Txt);

    /* Visualization mode */
    foutList.SetPos(textPosX, 20);
    foutList.draw(pContext);
    textPosX += foutList.getTableWidth() +10;
  }
  else 
  {
    /* nothing */
  }
}

void CSimHlaVisuHlaf::getHLABrightnessStateTxt(const uint8 BrightnessState, 
                                                     char* pTxtOut
                                              )
{
  switch(BrightnessState)
  {
  case RTE_HLAR_BRT_UNKNOWN:
    sprintf(pTxtOut, "BRT_UNKNOWN", BrightnessState);
    break;
  case RTE_HLAR_BRT_DAY:
    sprintf(pTxtOut, "BRT_DAY", BrightnessState);
    break;
  case RTE_HLAR_BRT_TWLGT_1:
    sprintf(pTxtOut, "BRT_TWLGT_1", BrightnessState);
    break;
  case RTE_HLAR_BRT_TWLGT_2:
    sprintf(pTxtOut, "BRT_TWLGT_2", BrightnessState);
    break;
  case RTE_HLAR_BRT_TWLGT_3:
    sprintf(pTxtOut, "BRT_TWLGT_3", BrightnessState);
    break;
  case RTE_HLAR_BRT_NIGHT:
    sprintf(pTxtOut, "BRT_NIGHT", BrightnessState);
    break;
  default:
    sprintf(pTxtOut, "%i", BrightnessState);
    break;
  }
}

void CSimHlaVisuHlaf::getHLASensModeTxt( const uint8 SensMode, 
                                               char* pTxtOut
                                        )
{
  switch(SensMode)
  {
  case RTE_HLA_SENSMODE_UNKNOWN:
    sprintf(pTxtOut, "SENS_UNKNOWN", SensMode);
    break;
  case RTE_HLA_SENSMODE_NORMAL:
    sprintf(pTxtOut, "SENS_NORMAL", SensMode);
    break;
  case RTE_HLA_SENSMODE_US:
    sprintf(pTxtOut, "SENS_US", SensMode);
    break;
  case RTE_HLA_SENSMODE_INVALID:
    sprintf(pTxtOut, "SENS_INVALID", SensMode);
    break;
  default:
    sprintf(pTxtOut, "%i", SensMode);
    break;
  }
}

void CSimHlaVisuHlaf::getHLASceneInfoTxt( const uint8 SceneInfo, 
                                                char* pTxtOut
                                         )
{
  switch(SceneInfo)
  {
  case RTE_HLA_SCENEINFO_UNKNOWN:
    sprintf(pTxtOut, "SCENEINFO_UNKNOWN", SceneInfo);
    break;
  case RTE_HLA_SCENEINFO_ONCOMING_PASSING:
    sprintf(pTxtOut, "SCENEINFO_ONCOMING_PASSING", SceneInfo);
    break;
  case RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING:
    sprintf(pTxtOut, "SCENEINFO_PRECEDING_OVERTAKING", SceneInfo);
    break;
  case RTE_HLA_SCENEINFO_INVALID:
    sprintf(pTxtOut, "CENEINFO_INVALID", SceneInfo);
    break;
  default:
    sprintf(pTxtOut, "%i", SceneInfo);
    break;
  }
}

void CSimHlaVisuHlaf::getHLASpeedStateTxt(const uint32 Status, 
                                                char*  pTxtOut
                                         )
{
  switch(Status)
  {
  case RTE_HLAF_SPEEDSTATE_UNKNOWN:
    sprintf(pTxtOut, "(%d) UNKNOWN", RTE_HLAF_SPEEDSTATE_UNKNOWN);
    break;
  case RTE_HLAF_SPEEDSTATE_TOO_LOW:
    sprintf(pTxtOut, "(%d) TOO_LOW", RTE_HLAF_SPEEDSTATE_TOO_LOW);
    break;
  case RTE_HLAF_SPEEDSTATE_IN_RANGE:
    sprintf(pTxtOut, "(%d) IN_RANGE", RTE_HLAF_SPEEDSTATE_IN_RANGE);
    break;
  case RTE_HLAF_SPEEDSTATE_TOO_HIGH:
    sprintf(pTxtOut, "(%d) TOO_HIGH", RTE_HLAF_SPEEDSTATE_TOO_HIGH);
    break;
  default:
    sprintf(pTxtOut, "%i", Status);
    break;
  }
}

void CSimHlaVisuHlaf::drawLsdInputInterface( const ISimRenderContext*  pContext,
                                             const reqHlaPrtList_t*    pRteInputs,
                                             const color_e             color,
                                                   HLAFData_t*         pHlafData,
                                                   uint8               drawPlane,    /* = 1*/
                                                   uint8               planesToDraw, /* = 1*/
                                                   sint16              drawOffsetX,  /* = 0*/
                                                   sint16              drawOffsetY   /* = 0*/
                                           )
{

}

void CSimHlaVisuHlaf::drawLsdLightSize( const ISimRenderContext* pContext,
                                        const reqHlaPrtList_t*   pRteInputs,
                                        const color_e            color,
                                        sint16                   drawOffsetX,  /* = 0*/
                                        sint16                   drawOffsetY   /* = 0*/
                                      )
{
  if(   (pRteInputs)
      &&(pRteInputs->pLsdLightObjectList != NULL)
      &&(pRteInputs->pLsdLightList != NULL)
      &&(pRteInputs->pLsdLightObjectList->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
      &&(pRteInputs->pLsdLightList->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    /* draw the light size of all lights in lsd object list */
    for (unsigned int i=0; i<pRteInputs->pLsdLightObjectList->numObjects; i++)
    {
      /* get lsd object */
      const LSD_LightObject_t& lsdObject = pRteInputs->pLsdLightObjectList->lightObjects[i];
      /* get corresponding light */
      const LSD_Light_t& lsdLight = pRteInputs->pLsdLightList->lights[lsdObject.general.lightID];

      SetColor(color);
      drawRect(lsdLight.x1  +drawOffsetX, lsdLight.y1  +drawOffsetY, lsdLight.x2  +drawOffsetX, lsdLight.y2  +drawOffsetY);
    }
  }

}

const LSD_LightObject_t* CSimHlaVisuHlaf::getCorrespodingLightObject( const HLAObjectDataInt_t*    pInternalHLAOBject,
                                                                      const HLAFData_t*            pHlafData,
                                                                      const LSD_LightObjectList_t* pLsdLightObjectList
                                                                     )
{
  const LSD_LightObject_t* pLSDLightObject = NULL;
  /* check if object is from EM object list */
  if (pInternalHLAOBject->EMObjID != UI8_T_MAX)
  {
    pLSDLightObject = NULL;
  }
  else
  {
    for (unsigned int i=0; i< pLsdLightObjectList->numObjects; i++)
    {
      if (pInternalHLAOBject->LiObjID == pLsdLightObjectList->lightObjects[i].general.lightObjectID)
      {
        pLSDLightObject = &pLsdLightObjectList->lightObjects[i];
      }
    }
  }

  return pLSDLightObject;
}

void CSimHlaVisuHlaf::drawOutputInterfaceInfo( const ISimRenderContext*  pContext,
                                               const reqHlaPrtList_t*    pRteInputs,
                                                     int                 &infoPosX,
                                                     sint16              drawOffsetX,
                                                     sint16              drawOffsetY
                                              )
{
  char Txt[255];

  CSimTable outList;
  uint16 row = 0;
  uint16 col = 0;
  color_e drawColor = color_yellow;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  if(pRteInputs == NULL)
  {
    return;
  }

  outList.SetCell(row, col, "Input Interface ", m_drawColor);

  if(   (pRteInputs->pLsdLightObjectList != NULL)
     && (pRteInputs->pLsdLightObjectList->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    for(uint32 i = 0u; i < pRteInputs->pLsdLightObjectList->numObjects; i++)
    {
      const LSD_LightObject_t& pObject = pRteInputs->pLsdLightObjectList->lightObjects[i];

      for (uint32 j = 0u; j < pRteInputs->pLsdLightObjectList->numObjects; j++)
      {
        if(   (pRteInputs->pLsdLightObjectList->lightObjects[i].general.lightID == pObject.general.lightObjectIDPaired)
           && (pRteInputs->pLsdLightObjectList->lightObjects[i].general.lightObjectIDPaired == 255)
          )
        {
          _snprintf(tmpTxt, maxTxt, "-Placeholder-");
        }
      }

      /* draw objects the mouse is pointing to */
      if(  std::abs(pObject.kinematic.camera.x + drawOffsetX - m_mouseInfo.current.x) < 5
        && std::abs(pObject.kinematic.camera.y + drawOffsetY - m_mouseInfo.current.y) < 5
      )
      {
        drawObjectOutputListText(pObject, pContext, infoPosX);
      }

      /* draw locked objects */
      for (LockedObjectList::const_iterator it = m_lockedObjects.objectList.begin(); it != m_lockedObjects.objectList.end(); ++it)
      {
        if (it->pObjectTrackId == pObject.general.lightObjectID)
        {
          drawObjectOutputListText(pObject, pContext, infoPosX);
        }
      }

    }

    outList.SetRow<unsigned int>(++row, drawColor, "Measurement counter:", pRteInputs->pLsdLightObjectList->sSigHeader.uiMeasurementCounter);
    outList.SetCell(++row, COL_0);
  }

  /* ENVIRONMENT DATA */
  if(   (pRteInputs->pLsdEnvironmentData != NULL) 
     && (pRteInputs->pLsdEnvironmentData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    outList.SetCell(++row, COL_0, "ENVIRONMENT DATA:", color_bronze);

    CSimHlaVisuHlaf::getHLABrightnessStateTxt(pRteInputs->pLsdEnvironmentData->brightnessState, Txt);
    outList.SetRow<char*>(++row, drawColor, "Brightness:", Txt);

    outList.SetCell(++row, COL_0, "City:", drawColor);
    switch(pRteInputs->pLsdEnvironmentData->cityState)
    {
    case LSD_ENVIRONMENT_DATA_CITY_STATE_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "CITY_STATE_UNKNOWN", LSD_ENVIRONMENT_DATA_CITY_STATE_UNKNOWN);
      break;
    case LSD_ENVIRONMENT_DATA_CITY_STATE_NONE:
      _snprintf(tmpTxt, maxTxt, "CITY_STATE_NONE", LSD_ENVIRONMENT_DATA_CITY_STATE_NONE);
      break;
    case LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED:
      _snprintf(tmpTxt, maxTxt, "CITY_STATE_DETECTED", LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED);
      break;
    case LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE:
      _snprintf(tmpTxt, maxTxt,  "CITY_STATE_MAYBE", LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "%i", pRteInputs->pLsdEnvironmentData->cityState);
      break;
    }
    outList.SetCell(row, COL_1, tmpTxt, drawColor);

    outList.SetCell(++row, COL_0, "TrafficStyle:", drawColor);
    switch(pRteInputs->pLsdEnvironmentData->trafficStyleState)
    {
    case LSD_TRAFFIC_STYLE_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "(%d) TRAFFIC_STYLE_UNKNOWN", LSD_TRAFFIC_STYLE_UNKNOWN);
      break;
    case LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC:
      _snprintf(tmpTxt, maxTxt, "(%d) TRAFFIC_STYLE_RHT", LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC);
      break;
    case LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC:
      _snprintf(tmpTxt, maxTxt, "(%d) TRAFFIC_STYLE_LHT", LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "%i", pRteInputs->pLsdEnvironmentData->trafficStyleState);
      break;
    }
    outList.SetCell(row, COL_1, tmpTxt, drawColor);
    outList.SetCell(++row, COL_0, "Tunnel:", drawColor);
    switch(pRteInputs->pLsdEnvironmentData->tunnelState)
    {
    case LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "TUNNEL_UNKNOWN", LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UNKNOWN);
      break;
    case LSD_ENVIRONMENT_DATA_TUNNEL_STATE_NONE:
      _snprintf(tmpTxt, maxTxt,  "TUNNEL_NOT_DTCD", LSD_ENVIRONMENT_DATA_TUNNEL_STATE_NONE);
      break;
    case LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UPFRONT:
      _snprintf(tmpTxt, maxTxt,  "TUNNEL_UPFRONT", LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UPFRONT);
      break;
    case LSD_ENVIRONMENT_DATA_TUNNEL_STATE_INSIDE:
      _snprintf(tmpTxt, maxTxt,  "TUNNEL_INSIDE", LSD_ENVIRONMENT_DATA_TUNNEL_STATE_INSIDE);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "%i", pRteInputs->pLsdEnvironmentData->tunnelState);
      break;
    }
    outList.SetCell(row, COL_1, tmpTxt, drawColor);

    outList.SetCell(++row, COL_0, "Highway:", drawColor);
    switch(pRteInputs->pLsdEnvironmentData->highwayState)
    {
    case LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_UNKNOWN:
      _snprintf(tmpTxt, maxTxt, "HIGHWAY_STATE_UNKNOWN", LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_UNKNOWN);
      break;
    case LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE:
      _snprintf(tmpTxt, maxTxt, "HIGHWAY_STATE_NONE", LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE);
      break;
    case LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED:
      _snprintf(tmpTxt, maxTxt,  "HIGHWAY_STATE_DETECTED", LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "%i", pRteInputs->pLsdEnvironmentData->highwayState);
      break;
    }
    outList.SetCell(row, COL_1, tmpTxt, drawColor);

    outList.SetCell(++row, COL_0, "RedReflectorArea:", drawColor);
    switch(pRteInputs->pLsdEnvironmentData->highReflectorDensityState)
    {
    case LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_UNKNOWN:
      _snprintf(tmpTxt, maxTxt,"HIGH_REFLECTOR_DENSITY_STATE_UNKNOWN", LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_UNKNOWN);
      break;
    case LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE:
      _snprintf(tmpTxt, maxTxt,"HIGH_REFLECTOR_DENSITY_STATE_NONE", LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE);
      break;
    case LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_DETECTED:
      _snprintf(tmpTxt, maxTxt,"HIGH_REFLECTOR_DENSITY_STATE_DETECTED", LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_DETECTED);
      break;
    default:
      _snprintf(tmpTxt, maxTxt, "%i", pRteInputs->pLsdEnvironmentData->highReflectorDensityState);
      break; 
    }
    outList.SetCell(row, COL_1, tmpTxt, drawColor);
    outList.SetCell(++row, COL_0);
  }

  if(   (pRteInputs->pLsdLightObjectList != NULL)
     && (pRteInputs->pLsdLightObjectList->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    outList.SetCell(++row, COL_0, "OBJECT LIST:", color_bronze);
    outList.SetRow<unsigned int>(++row, drawColor, "#Objects:",  pRteInputs->pLsdLightObjectList->numObjects);

    outList.SetCell(++row, COL_0, "ROI:", color_bronze);
    outList.SetRow<unsigned int>(++row, drawColor, "X1:", pRteInputs->pLsdLightObjectList->roi.x1);
    outList.SetRow<unsigned int>(++row, drawColor, "X_FOE:", pRteInputs->pLsdLightObjectList->roi.xFOE);
    outList.SetRow<unsigned int>(++row, drawColor, "X2:", pRteInputs->pLsdLightObjectList->roi.x2);
    outList.SetRow<unsigned int>(++row, drawColor, "Y1:", pRteInputs->pLsdLightObjectList->roi.y1);
    outList.SetRow<unsigned int>(++row, drawColor, "YuVehicle:", pRteInputs->pLsdLightObjectList->roi.yVehicleSplit);
    outList.SetRow<unsigned int>(++row, drawColor, "Yu:", pRteInputs->pLsdLightObjectList->roi.ySplit);
    outList.SetRow<unsigned int>(++row, drawColor, "Y_FOE:", pRteInputs->pLsdLightObjectList->roi.yFOE);
    outList.SetRow<unsigned int>(++row, drawColor, "Y2:", pRteInputs->pLsdLightObjectList->roi.y2);
  }

  outList.SetPos(infoPosX , 20);
  outList.draw(pContext);
  infoPosX += outList.getTableWidth() + 10;
}

void CSimHlaVisuHlaf::drawObjectOutputListText( const LSD_LightObject_t&  hlaObject,
                                                const ISimRenderContext*  pContext,
                                                      int&                textPosX
                                               )
{
  CSimTable outputList;
  uint16 row = 0;
  color_e drawColor = color_yellow;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];
 
  outputList.SetRow<unsigned int>(row, m_drawColor, "Object ID:", hlaObject.general.lightObjectID);

  outputList.SetRow<unsigned int>(++row, drawColor, "LightID: ",   hlaObject.general.lightID);
  outputList.SetRow<unsigned int>(++row, drawColor, "IdPairLight:",hlaObject.general.lightObjectIDPaired);
  outputList.SetRow<unsigned int>(++row, drawColor, "Trace time:", hlaObject.general.cyclesTraced);

  outputList.SetRow<unsigned int>(++row, drawColor, "Lost time:", hlaObject.general.cyclesLost);

  _snprintf(tmpTxt, maxTxt, "%i,%i", hlaObject.kinematic.camera.x, hlaObject.kinematic.camera.y);
  outputList.SetRow<char*>(++row, drawColor, "Center Pos x,y:", tmpTxt);

  _snprintf(tmpTxt, maxTxt, "%.2f, %.2f, %.2f", hlaObject.kinematic.world.x, hlaObject.kinematic.world.y, hlaObject.kinematic.world.z);
  outputList.SetRow<char*>(++row, drawColor, "World Pos x,y,z:", tmpTxt);

  _snprintf(tmpTxt, maxTxt, "%.2fs", hlaObject.kinematic.world.horizontalAngle);
  outputList.SetRow<char*>(++row, drawColor, "Horizontal Angle [rad]:", tmpTxt);

  _snprintf(tmpTxt, maxTxt, "%i,%i", hlaObject.kinematic.camera.deltaX, hlaObject.kinematic.camera.deltaY);
  outputList.SetRow<char*>(++row, drawColor, "Delta x,y:", tmpTxt);

  _snprintf(tmpTxt, maxTxt, "%i,%i",  hlaObject.kinematic.camera.deltaXFiltered, hlaObject.kinematic.camera.deltaYFiltered);
  outputList.SetRow<char*>(++row, drawColor, "Delta LowPassed x,y:", tmpTxt);

  outputList.SetRow<unsigned int>(++row, drawColor, "Blinking Confidence:", hlaObject.attributes.blinkingConfidence);

  outputList.SetRow<unsigned int>(++row, drawColor, "Probability Oncoming:", hlaObject.attributes.probabilityVehicleOncoming);

  outputList.SetRow<unsigned int>(++row, drawColor, "Probability Preceding:", hlaObject.attributes.probabilityVehiclePreceding);

  outputList.SetRow<unsigned int>(++row, drawColor, "Probability Street Lamp:", hlaObject.attributes.probabilityStreetLamp);


  outputList.SetCell(++row, COL_0, "Status Flags:", drawColor);
  outputList.SetCell(++row,COL_0);

  drawBitField("Truck Light",(hlaObject.attributes.statusBits & LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT),pContext, outputList, ++row);
  drawBitField("Will be Removed",(hlaObject.attributes.statusBits & LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED),pContext, outputList, ++row);
  drawBitField("Bright non Vehicle",(hlaObject.attributes.statusBits & LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE),pContext, outputList, ++row);
  outputList.SetRow<unsigned int>(++row, drawColor, "Max Intensity [lux]:", hlaObject.attributes.intensity);

  _snprintf(tmpTxt, maxTxt, "%.2fs", hlaObject.attributes.luminousFlux);
  outputList.SetRow<char*>(++row, drawColor, "Luminous flux [lux]:", tmpTxt);

  _snprintf(tmpTxt, maxTxt, "%.2fs", hlaObject.kinematic.timeToHlaBorder);
  outputList.SetRow<char*>(++row, drawColor, "Time To Border:", tmpTxt);

  outputList.SetPos(textPosX, 20);
  outputList.draw(pContext);

  textPosX += outputList.getTableWidth()+5;
}

void CSimHlaVisuHlaf::drawObjectOutputPopUp( const ISimRenderContext*  pContext,
                                             const LSD_LightObject_t&  lsdObject,                                                         
                                                   int                 textPosX,
                                                   int&                textPosY
                                             )
{
  CSimTable popUpList;
  uint16 row = 0;
  color_e drawColor = color_yellow;

  popUpList.SetCell(row, COL_0, "Output", color_blue);
 
  popUpList.SetRow<unsigned int>(++row, drawColor, "TrackID: ",   lsdObject.general.lightID);
  popUpList.SetRow<unsigned int>(++row, drawColor, "IdPairLight:",lsdObject.general.lightObjectIDPaired);

  popUpList.SetRow<unsigned int>(++row, drawColor, "Max Intensity [lux]:", lsdObject.attributes.intensity);
  popUpList.SetRow<char*>(++row, drawColor, "Angle:", CML_Rad2Deg(lsdObject.kinematic.world.horizontalAngle));

  popUpList.SetFontContext(*pContext);
  textPosY -= popUpList.getTableHeight();
  popUpList.SetPos(textPosX, textPosY);
  popUpList.draw(pContext);
}

/*******************************************************************************************/
/******************************** Input Interface ******************************************/
/*******************************************************************************************/
void CSimHlaVisuHlaf::drawInputInterface(const ISimRenderContext*  pContext,
                                         const reqHlaPrtList_t*    pRTEin,
                                         const color_e             color,
                                               float32             alpha,
                                               sint16              drawOffsetX, /* = 0 */
                                               sint16              drawOffsetY  /* = 0 */
                                        )
{
  int textPosX = 1176;
  const int textHeight = 10;
  float r,g,b;

  uint32 i;

  CSimColor().ConvertColor(color,r,g,b);
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-3);

  RTE_HLAF_Matrix_t tempMatrix;

  if(pRTEin == NULL)
  {
    return;
  }

  /* draw GFAs */
  if(   (pRTEin->pHlaBusInputSignals != NULL)
     && (pRTEin->pHlaBusInputSignals->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    /* Initialization */
    memset(&tempMatrix, 0, sizeof(tempMatrix));
    
    /* Map data from bus input signals to Matrix data structure */
    tempMatrix.LowBeam_Dist = CML_f_Min(601.0f, pRTEin->pHlaBusInputSignals->lightDistance);
    tempMatrix.HighBeamState = pRTEin->pHlaBusInputSignals->headLightState;
    tempMatrix.nGFA = CML_Min(pRTEin->pHlaBusInputSignals->numGlareFreeAreas, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS);
    
    for (i = 0u; i < tempMatrix.nGFA; i++)
    {
      tempMatrix.GFA[i].ClosestObj_Dist = CML_f_Max(65.0f, pRTEin->pHlaBusInputSignals->lightDistance);
      tempMatrix.GFA[i].BndryLeft_Dist  = CML_f_Max(65.0f, pRTEin->pHlaBusInputSignals->lightDistance);
      tempMatrix.GFA[i].BndryRight_Dist = CML_f_Max(65.0f, pRTEin->pHlaBusInputSignals->lightDistance);
    
      /* TODO: To be checked which angles should be taken? Camera or world? */
      tempMatrix.GFA[i].BndryLeft_Ang = pRTEin->pHlaBusInputSignals->glareFreeAreas[i].cutOffAngleLeft;
      tempMatrix.GFA[i].BndryRight_Ang = pRTEin->pHlaBusInputSignals->glareFreeAreas[i].cutOffAngleRight;
      tempMatrix.GFA[i].BndryUpper_Ang_Cam = pRTEin->pHlaBusInputSignals->glareFreeAreas[i].cutOffAngleUpper;
      tempMatrix.GFA[i].BndryLower_Ang_Cam = pRTEin->pHlaBusInputSignals->glareFreeAreas[i].cutOffAngleLower;
    }

    CSimHlaVisuHlaf::drawGFAs( pContext,
                               b_TRUE,
                               pRTEin,
                               tempMatrix.GFA,
                               tempMatrix.nGFA,
                               color,
                               alpha,
                               drawOffsetX,
                               drawOffsetY
                              );
  }
}

void CSimHlaVisuHlaf::drawInputInterfaceDetailsText(const ISimRenderContext* pContext,
                                                    const reqHlaPrtList_t*   pRTEin,
                                                          int&               textPosX
                                                    )
{

}

void CSimHlaVisuHlaf::getHLAHighBeamStateTxt(const uint8 HighBeamState, 
                                                   char* pTxtOut
                                            )
{
  switch(HighBeamState)
  {
  case RTE_HLAF_HB_STATE_UNKNOWN:
    sprintf(pTxtOut, "(%d) UNKNOWN", RTE_HLAF_HB_STATE_UNKNOWN);
    break;
  case RTE_HLAF_HB_STATE_OFF:
    sprintf(pTxtOut, "(%d) OFF", RTE_HLAF_HB_STATE_OFF);
    break;
  case RTE_HLAF_HB_STATE_FULL_ON:
    sprintf(pTxtOut, "(%d) FULL", RTE_HLAF_HB_STATE_FULL_ON);
    break;
  case RTE_HLAF_HB_STATE_PARTIAL:
    sprintf(pTxtOut, "(%d) PART", RTE_HLAF_HB_STATE_PARTIAL);
    break;
  case RTE_HLAF_HB_STATE_SPOT:
    sprintf(pTxtOut, "(%d) SPOT", RTE_HLAF_HB_STATE_SPOT);
    break;
  case RTE_HLAF_HB_STATE_INVALID:
    sprintf(pTxtOut, "(%d) INVALID", RTE_HLAF_HB_STATE_INVALID);
    break;
  default:
    sprintf(pTxtOut, "Error");
    break;
  }
}

/*******************************************************************************************/
/******************************** HLA Matrix   *********************************************/
/*******************************************************************************************/
void CSimHlaVisuHlaf::drawHLAFMatrix(const ISimRenderContext*  pContext,
                                     const reqHlaPrtList_t*    pRteInputs,
                                     const SimHlaProPrtList_t* pRteOutputs,
                                           int&                textPosX
                                    )
{
  int textPosY = 30;
  uint8 iGFA;
  char Txt[255];
  boolean bGFASelected = FALSE;

  CSimTable matrixList;
  uint16 row = 0;
  color_e drawColor = color_yellow;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  if(!(pRteInputs && pRteOutputs))
  {
    return;
  }

  matrixList.SetCell(row, COL_0, "HLAF Matrix", m_drawColor);

  matrixList.SetCell(++row, COL_0, "GFA Data", drawColor);
  getHLAFSignalStatusTxt(pRteOutputs->pHlaf_HeadlightControl->Matrix.GFAStatus, Txt);
  matrixList.SetRow<char*>(++row, drawColor, "GFAStatus:", Txt);
  matrixList.SetRow<unsigned int>(++row, drawColor, "nGFA", pRteOutputs->pHlaf_HeadlightControl->Matrix.nGFA);

  matrixList.SetCell(++row, COL_0);

  for(iGFA=0; iGFA < pRteOutputs->pHlaf_HeadlightControl->Matrix.nGFA; iGFA++)
  {
    float32 MouseAngHor_Cam  = atanf(           (pRteInputs->pLsdLightObjectList->roi.xFOE - (m_mouseInfo.current.x) ) / pRteInputs->pMonoCalibration->sIntrinsic.fFocalX);
    float32 MouseAngVert_Cam = atanf(  (float32)( (m_mouseInfo.current.y) - pRteInputs->pLsdLightObjectList->roi.yFOE) / pRteInputs->pMonoCalibration->sIntrinsic.fFocalY);
    
    int dx_GFA = 110;
    const RTE_HLAF_MatrixGFA_t *pGFA = &pRteOutputs->pHlaf_HeadlightControl->Matrix.GFA[iGFA];


    if(     (MouseAngHor_Cam <= (pGFA->BndryLeft_Ang_Cam + CML_Deg2Rad(0.25f)))
      &&  (MouseAngHor_Cam >= (pGFA->BndryRight_Ang_Cam - CML_Deg2Rad(0.25f)))
      &&  (MouseAngVert_Cam <= (pGFA->BndryLower_Ang_Cam + CML_Deg2Rad(0.25f)))
      )
    {
      bGFASelected = TRUE;

      matrixList.SetRow<unsigned int>(++row, drawColor, "GFA_ID:", iGFA);
      matrixList.SetCell(++row, COL_0);
      matrixList.SetCell(++row, COL_0, "external GFA Data", drawColor);
      matrixList.SetRow<unsigned int>(++row, drawColor, "ExistenceProb:", pGFA->ExistenceProb);
      matrixList.SetCell(++row, COL_0);

      _snprintf(tmpTxt, maxTxt, "%.4f°",CML_Rad2Deg(pGFA->BndryLeft_Ang));
      matrixList.SetRow<char*>(++row, drawColor, "BndryLeft_Ang:", tmpTxt);

      _snprintf(tmpTxt, maxTxt, "%.0fm",(pGFA->BndryLeft_Dist));
      matrixList.SetRow<char*>(++row, drawColor, "BndryLeft_Dist:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->BndryLeft_DistState, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "BndryLeft_DistState:", Txt);
      matrixList.SetRow<unsigned int>(++row, drawColor, "BndryLeft_ObjId:", (pGFA->BndryLeft_ObjId));

      _snprintf(tmpTxt, maxTxt, "%.1f°",CML_Rad2Deg(pGFA->BndryLeft_Ang_Cam));
      matrixList.SetRow<char*>(++row, drawColor, "BndryLeft_Ang_Cam:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->BndryLeft_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "BndryLeft_Status:", Txt);
      matrixList.SetCell(++row, COL_0);

      _snprintf(tmpTxt, maxTxt, "%.4f°",CML_Rad2Deg(pGFA->BndryRight_Ang));
      matrixList.SetRow<char*>(++row, drawColor, "BndryRight_Ang:", tmpTxt);

      _snprintf(tmpTxt, maxTxt, "%.0fm",(pGFA->BndryRight_Dist));
      matrixList.SetRow<char*>(++row, drawColor, "BndryRight_Dist:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->BndryRight_DistState, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "BndryRight_DistState:", Txt);

      matrixList.SetRow<unsigned int>(++row, drawColor, "BndryRight_ObjId:", (pGFA->BndryRight_ObjId));

      _snprintf(tmpTxt, maxTxt, "%.1f°",CML_Rad2Deg(pGFA->BndryRight_Ang_Cam));
      matrixList.SetRow<char*>(++row, drawColor, "BndryRight_Ang_Cam:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->BndryRight_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "BndryRight_Status:", Txt);
      matrixList.SetCell(++row, COL_0);

      _snprintf(tmpTxt, maxTxt, "%.4f°",CML_Rad2Deg(pGFA->BndryLower_Ang_Cam));
      matrixList.SetRow<char*>(++row, drawColor, "BndryLower_Ang_Cam:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->BndryLower_DistState, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "BndryLower_DistState:", Txt);

      matrixList.SetRow<unsigned int>(++row, drawColor, "BndryLower_ObjId:", (pGFA->BndryLower_ObjId));

      getHLAFMatrixObjStatusTxt(pGFA->BndryLower_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "BndryLower_Status:", Txt);
      matrixList.SetCell(++row, COL_0);

      _snprintf(tmpTxt, maxTxt, "%.0fm",pGFA->ClosestObj_Dist);
      matrixList.SetRow<char*>(++row, drawColor, "ClosestObj_Dist:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->ClosestObj_DistState, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "ClosestObj_DistState:", Txt);

      matrixList.SetRow<unsigned int>(++row, drawColor, "ClosestObj_ObjId:", (pGFA->ClosestObj_ObjId));

      getHLAFMatrixObjStatusTxt(pGFA->ClosestObj_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "ClosestObj_Status:", Txt);

      _snprintf(tmpTxt, maxTxt, "%.0fm",pGFA->MinLight_Dist);
      matrixList.SetRow<char*>(++row, drawColor, "MinLight_Dist:", tmpTxt);

      getHLAFMatrixObjStatusTxt(pGFA->MinLight_DistState, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "MinLight_DistState:", Txt);

      matrixList.SetRow<unsigned int>(++row, drawColor, "MinLight_ObjId:", (pGFA->MinLight_ObjId));

      getHLAFMatrixObjStatusTxt(pGFA->MinLight_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "MinLight_Status:", Txt);
      matrixList.SetCell(++row, COL_0);

      _snprintf(tmpTxt, maxTxt, "%.2fs",pGFA->ttb18Left);
      matrixList.SetRow<char*>(++row, drawColor, "TTB18Left:", tmpTxt);

      getHLAFMatrixTTB18StatusTxt(pGFA->ttb18Left_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "TTB18Left_Status:", Txt);

      _snprintf(tmpTxt, maxTxt, "%.2fs",pGFA->ttb18Right);
      matrixList.SetRow<char*>(++row, drawColor, "TTB18Right:", tmpTxt);

      getHLAFMatrixTTB18StatusTxt(pGFA->ttb18Right_Status, Txt);
      matrixList.SetRow<char*>(++row, drawColor, "TTB18Right_Status:", Txt);
      matrixList.SetCell(++row, COL_0);

      matrixList.SetPos(textPosX, textPosY);

      /* break for loop */
      break;
    }
  }

  /* output data */
  if(bGFASelected == FALSE)
  {
    int textPosXold = textPosX;
    int textPosYold = textPosY;

    matrixList.SetCell(++row, COL_0, "Output", drawColor);

    getHLAHighBeamStateTxt(pRteOutputs->pHlaf_HeadlightControl->Matrix.HighBeamState, Txt);
    matrixList.SetRow<char*>(++row, drawColor, "eHighBeamState:", Txt);

    _snprintf(tmpTxt, maxTxt,"%.0fm",pRteOutputs->pHlaf_HeadlightControl->Matrix.LowBeam_Dist);
      matrixList.SetRow<char*>(++row, drawColor, "LowBeam_Dist:", tmpTxt);

    _snprintf(tmpTxt, maxTxt,"%.1f°",CML_Rad2Deg(pRteOutputs->pHlaf_HeadlightControl->Matrix.LowBeam_Ang));
      matrixList.SetRow<char*>(++row, drawColor, "LowBeam_Ang:", tmpTxt);

    getHLAFMatrixObjStatusTxt(pRteOutputs->pHlaf_HeadlightControl->Matrix.LowBeam_Status, Txt);
    matrixList.SetRow<char*>(++row, drawColor, "LowBeam_Status:", Txt);
    matrixList.SetCell(++row, COL_0);

    matrixList.SetPos(textPosX, textPosYold);
  }
  
  matrixList.draw(pContext);
  textPosX += matrixList.getTableWidth() +10;
}

void CSimHlaVisuHlaf::getHLAFSignalStatusTxt(const uint32  Status, 
                                                   char*   pTxtOut
                                            )
{
  switch(Status)
  {
  case RTE_HLAF_SIGSTAT_UNKNOWN:
    sprintf(pTxtOut, "(%d) UNKNOWN", RTE_HLAF_SIGSTAT_UNKNOWN);
    break;
  case RTE_HLAF_SIGSTAT_INIT:
    sprintf(pTxtOut, "(%d) INIT", RTE_HLAF_SIGSTAT_INIT);
    break;
  case RTE_HLAF_SIGSTAT_DATA_VALID:
    sprintf(pTxtOut, "(%d) DATA_VALID", RTE_HLAF_SIGSTAT_DATA_VALID);
    break;
  case RTE_HLAF_SIGSTAT_DATA_INVALID:
    sprintf(pTxtOut, "(%d) DATA_INVALID", RTE_HLAF_SIGSTAT_DATA_INVALID);
    break;
  case RTE_HLAF_SIGSTAT_INVALID:
    sprintf(pTxtOut, "(%d) INVALID", RTE_HLAF_SIGSTAT_INVALID);
    break;
  default:
    sprintf(pTxtOut, "ERROR");
    break;
  }
}

void CSimHlaVisuHlaf::getHLAFMatrixObjStatusTxt(const uint32 Status, 
                                                      char*  pTxtOut
                                               )
{
  switch(Status)
  {
  case RTE_HLAF_OBJSTA_UNKNOWN:
    sprintf(pTxtOut, "(%d) UNKNOWN", RTE_HLAF_OBJSTA_UNKNOWN);
    break;
  case RTE_HLAF_OBJSTA_NO_OBJ:
    sprintf(pTxtOut, "(%d) NO_OBJ", RTE_HLAF_OBJSTA_NO_OBJ);
    break;
  case RTE_HLAF_OBJSTA_UNKNOWN_OBJ:
    sprintf(pTxtOut, "(%d) UNKNOWN_OBJ", RTE_HLAF_OBJSTA_UNKNOWN_OBJ);
    break;
  case RTE_HLAF_OBJSTA_PREC_OBJ:
    sprintf(pTxtOut, "(%d) PREC_OBJ", RTE_HLAF_OBJSTA_PREC_OBJ);
    break;
  case RTE_HLAF_OBJSTA_ONC_OBJ:
    sprintf(pTxtOut, "(%d) ONC_OBJ", RTE_HLAF_OBJSTA_ONC_OBJ);
    break;
  case RTE_HLAF_OBJSTA_INVALID:
    sprintf(pTxtOut, "(%d) INVALID", RTE_HLAF_OBJSTA_INVALID);
    break;
  default:
    sprintf(pTxtOut, "ERROR");
    break;
  }
}

void CSimHlaVisuHlaf::getHLAFMatrixDistStateTxt(const uint32 Status, 
                                                      char*  pTxtOut
                                               )
{
  switch(Status)
  {
    case RTE_HLAF_DISTSTATE_UNKNOWN:
      sprintf(pTxtOut, "(%d) UNKNOWN", Status);
      break;
    case RTE_HLAF_DISTSTATE_SINGLELIGHT:
      sprintf(pTxtOut, "(%d) SINGLELIGHT", Status);
      break;
    case RTE_HLAF_DISTSTATE_PAIRLIGHT:
      sprintf(pTxtOut, "(%d) PAIRLIGHT", Status);
      break;
    case RTE_HLAF_DISTSTATE_INVALID:
      sprintf(pTxtOut, "(%d) INVALID", Status);
      break;
    default:
      sprintf(pTxtOut, "ERROR");
      break;
  }
}

void CSimHlaVisuHlaf::getHLAFMatrixTTB18StatusTxt(const uint32 Status, 
                                                        char*  pTxtOut
                                                 )
{
  switch(Status)
  {
  case RTE_HLAF_TTBSTA_UNKNOWN:
    sprintf(pTxtOut, "(%d) UNKNOWN", RTE_HLAF_TTBSTA_UNKNOWN);
    break;
  case RTE_HLAF_TTBSTA_NO_OBJ:
    sprintf(pTxtOut, "(%d) NO_OBJ", RTE_HLAF_TTBSTA_NO_OBJ);
    break;
  case RTE_HLAF_TTBSTA_DIR_UNKNOWN:
    sprintf(pTxtOut, "(%d) UNKNOWN", RTE_HLAF_TTBSTA_DIR_UNKNOWN);
    break;
  case RTE_HLAF_TTBSTA_DIR_LEFT:
    sprintf(pTxtOut, "(%d) LEFT", RTE_HLAF_TTBSTA_DIR_LEFT);
    break;
  case RTE_HLAF_TTBSTA_DIR_RIGHT:
    sprintf(pTxtOut, "(%d) RIGHT", RTE_HLAF_TTBSTA_DIR_RIGHT);
    break;
  case RTE_HLAF_TTBSTA_INVALID:
    sprintf(pTxtOut, "(%d) INVALID", RTE_HLAF_TTBSTA_INVALID);
    break;
  default:
    sprintf(pTxtOut, "ERROR");
    break;
  }
}

void CSimHlaVisuHlaf::drawHLAF_Bar( const int     PosX, 
                                    const int     PosY,
                                    const int     Height,
                                    const int     Length,
                                    const float   FillPercentage, 
                                    const color_e color
                                   )
{
  SetColor(color);

  glBegin(GL_LINES);
  {
    glVertex3i(PosX,        PosY+1       , 1);
    glVertex3i(PosX+Length, PosY+1       , 1);

    glVertex3i(PosX+Length, PosY+1       , 1);
    glVertex3i(PosX+Length, PosY+Height-1, 1);

    glVertex3i(PosX+Length, PosY+Height-1, 1);
    glVertex3i(PosX       , PosY+Height-1, 1);

    glVertex3i(PosX       , PosY+Height-1, 1);
    glVertex3i(PosX       , PosY+1       , 1);
  }
  glEnd();

  glBegin(GL_QUADS);
  {
    glVertex3i(PosX       , PosY+Height-1, 1);
    glVertex3i(PosX,        PosY+1       , 1);

    glVertex3i(PosX+(int)(FillPercentage*Length), PosY+1       , 1);
    glVertex3i(PosX+(int)(FillPercentage*Length), PosY+Height-1, 1);
  }
  glEnd();
}

void CSimHlaVisuHlaf::drawHLAFTurnOffReason(const ISimRenderContext*       pContext,
                                            const HLAFTurnOffReason_t*     pTurnOffReason,
                                                  int*                     pTextPosX,
                                            const int                      textPosY
                                           )
{
  int textHeight = 0;
  int barLength  = 30;
  int xOffset = 119;

  CSimTable turnOffList("",0,0,xOffset+barLength+1);
  uint16 row = 0;
  color_e drawColor = color_yellow;

  turnOffList.SetFontContext(*pContext);
  textHeight = turnOffList.GetTextHeight();

  /* Keep off reason */
  turnOffList.SetCell(row, COL_0, "Turn off reason", m_drawColor);

  /* not released */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_NOT_RELEASED) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Not Released", drawColor);

  /* not active */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_NOT_ACTIVE) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Not Active", drawColor);

  /* not available */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_NOT_AVL) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Not Available", drawColor);

  /* blockage */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_BLOCKAGE) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Blockage", drawColor);

  /* fog */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_FOG) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Fog", drawColor);

  /* brightness */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Brightness", drawColor);

  /* city */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_CITY) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "City", drawColor);

  /* tunnel */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_TUNNEL) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Tunnel", drawColor);

  /* min speed */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_MIN_SPEED) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Min Speed", drawColor);

  /* max speed */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_MAX_SPEED) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Max Speed", drawColor);

  /* oncoming */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_ONCOMING) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Oncoming", drawColor);

  /* preceding */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_PRECEDING) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Preceding", drawColor);

  /* em object oncoming */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "EM Object Oncoming", drawColor);

  /* em object preceding */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_PREC) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "EM Object Preceding", drawColor);

  /* bad weather */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Bad Weather", drawColor);

  /* radar object */
  drawColor = (CML_GetBit(pTurnOffReason->Reason, HLAF_TURN_OFF_REASON_RADAR_OBJECT) == b_TRUE) ? color_red : color_yellow;
  turnOffList.SetCell(++row, COL_0, "Radar Object", drawColor);

  turnOffList.SetPos(*pTextPosX, textPosY);
  turnOffList.draw(pContext);

  *pTextPosX = *pTextPosX + turnOffList.getTableWidth();
}

/*******************************************************************************************/
/************* HLAF Standard internal data (used for matrix, std, light) *******************/
/*******************************************************************************************/
void CSimHlaVisuHlaf::drawHLAFHBData( const ISimRenderContext* const pContext,
                                      const HLAFData_t*        const pHlafData
                                    )
{
  int xPos = 20;
  int yPos = 350;
  int textHeight = 0;
  int barLength  = 30;
  int xOffset = 119;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  CSimTable HBDataList("",0,0,xOffset+barLength+1);
  uint16 row = 0;
  color_e drawColor = color_yellow;

  if(pHlafData != NULL)
  {
    getHLAHighBeamStateTxt(pHlafData->hlafMatrixData.Out.Matrix.HighBeamState, tmpTxt);
  
    HBDataList.SetRow<char*>(++row, drawColor, "HighBeamState:", tmpTxt);
    HBDataList.SetPos(xPos, yPos);
    HBDataList.draw(pContext);
  
    drawHLAFTurnOffReason( pContext,
                           &pHlafData->DecisionData.TurnOffReason,
                           &xPos,
                           yPos + HBDataList.getTableHeight()
                         );
  
    drawHLAFKeepOffReason( pContext,
                           &pHlafData->DecisionData.KeepOffReason,
                           xPos + 10,
                           yPos + HBDataList.getTableHeight()
                         );
  }
}
/*******************************************************************************************/
/******************************** HLA Keep off reason **************************************/
/*******************************************************************************************/
void CSimHlaVisuHlaf::drawHLAFKeepOffReason(const ISimRenderContext*       pContext,
                                            const HLAFKeepOffReason_t*     pKeepOffReason,
                                            const int                      textPosX,
                                            const int                      textPosY
                                            )
{
  int textHeight = 0;
  int barLength  = 30;
  int xOffset = 119;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  CSimTable keepOffList("",0,0,xOffset+barLength+1);
  uint16 row = 0;
  color_e drawColor = color_yellow;

  keepOffList.SetFontContext(*pContext);
  textHeight = keepOffList.GetTextHeight();

  /* Keep off reason */
  keepOffList.SetCell(row, COL_0, "Keep off reason", m_drawColor);

  /* speed acc */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_SPEED_ACC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "SpdAcc", drawColor);

  /* small radius */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_SMALL_RADIUS) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "SmallRadius", drawColor);
  /* addition data for small radius */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->SmallRadius.DelayTimer_s);
  keepOffList.SetCell(row, COL_1, "DelayTimer:", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* min time high beam off */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MIN_TIME_HB_OFF) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "MinTimeHBOff", drawColor);
  /* addition data for min time high beam off */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->MinTimeHBoff.HBOffTimer_s);
  keepOffList.SetCell(row, COL_1, "HBOffTimer", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* turn on delay init */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_INIT) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "TurnOnDelay_Init", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->TurnOnDelay.InitTimer_s);
  keepOffList.SetCell(row, COL_1, "InitTimer", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* turn on delay oncoming */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "TurnOnDelay_Onc", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_s);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Onc", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* turn on delay oncoming truck lights */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_ONC_TRUCK_LIGHTS) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "TurnOnDelay_TL", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->TurnOnDelay.TurnOnTimer_Onc_TL_s);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Onc_TL", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* turn on delay preceding */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "TurnOnDelay_Prec", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_s);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Prec", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* turn on delay preceding slow overtaker */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_TURN_ON_DELAY_PREC_SLOW_OVERTAKER) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "TurnOnDelay_Prec_SO", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->TurnOnDelay.TurnOnTimer_Prec_SO_s);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Prec_SO", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* preceding vehicle lost */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_PREC_VEHICLE_LOST) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "PrecedingVehLost", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->PrecedingVehLost.distance2cover);
  keepOffList.SetCell(row, COL_1, "distance2cover", color_yellow);
  keepOffList.SetCell(row, COL_2, tmpTxt, color_yellow);
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->PrecedingVehLost.rMax);
  keepOffList.SetCell(++row, COL_1, "rMax", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* maybe city oncoming */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_ONC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "MaybeCity_Onc", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->MayBeCity.TurnOnTimer_Onc);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Onc", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* maybe city preceding */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_PREC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "MaybeCity_Prec", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->MayBeCity.TurnOnTimer_Prec);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Prec", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* maybe city glob */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_MAYBE_CITY_GLOB) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "MaybeCity_Glob", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->MayBeCity.TurnOnTimer_Glob);
  keepOffList.SetCell(row, COL_1, "TurnOnTimer_Glob", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* potention vehicle oncoming */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_POT_VEH_ONC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "PotVeh_Onc", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->PotVeh.DelayTimer_Onc);
  keepOffList.SetCell(row, COL_1, "DelayTimer_Onc", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* potention vehicle preceding */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_POT_VEH_PREC) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "PotVeh_Prec", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->PotVeh.DelayTimer_Prec);
  keepOffList.SetCell(row, COL_1, "DelayTimer_Prec", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* potention vehicle glob */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_POT_VEH_GLOB) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "PotVeh_Glob", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->PotVeh.DelayTimer_Glob);
  keepOffList.SetCell(row, COL_1, "DelayTimer_Glob", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* fog */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_FOG) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "Fog", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->FogBadWeather.DelayTimer_Fog);
  keepOffList.SetCell(row, COL_1, "DelayTimer_Fog", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  /* bad weather */
  drawColor = (CML_GetBit(pKeepOffReason->Reason, HLAF_KEEP_OFF_REASON_BAD_WEATHER) == b_TRUE) ? color_red : color_yellow;
  keepOffList.SetCell(++row, COL_0, "Bad Weather", drawColor);
  /* addition data for turn on delay */
  _snprintf(tmpTxt, maxTxt, "%.2f", pKeepOffReason->FogBadWeather.DelayTimer_BadWeather);
  keepOffList.SetCell(row, COL_1, "DelayTimer_BadWeather", drawColor);
  keepOffList.SetCell(row, COL_2, tmpTxt, drawColor);

  keepOffList.SetPos(textPosX, textPosY);
  keepOffList.draw(pContext);

}

