/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_env.cpp

  DESCRIPTION:            Drawing of environment data like city, highway, tunnel, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.3 $

  ---*/ /*---

**************************************************************************** */

#include "stdafx.h"
#include "resource.h"

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "hlaf_matrix.h"
#ifdef __cplusplus
}
#endif

#include "sim_hla_visu_interface.h"
#include "hla_evm_hil_ports.h"

#include <string>
#include <cmath>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")

Hil2Mts_t cam;
Mts2Hil_t debug;

CSimHlaVisuInt::CSimHlaVisuInt(void)
{
}


CSimHlaVisuInt::~CSimHlaVisuInt(void)
{
}

void CSimHlaVisuInt::drawInterface( const ISimRenderContext* pContext,
                                          CSimVisuSubMenu*   pInterfacesMenu 
                                  )
{
  if (pInterfacesMenu->getItemActivation(MENU_BUTTON_INTF_EMOBJECT))
  {
    drawEMObjects(pContext, pm_rteInputs->pGenObjectList);
  }

  if (pInterfacesMenu->getItemActivation(MENU_BUTTON_INTF_DIMMING))
  {
    drawDimming(pContext, pm_rteInputs, pm_rteOutputs, m_drawColor);
  }
}

void CSimHlaVisuInt::drawDimming( const ISimRenderContext*        pContext,
                                        const reqHlaPrtList_t*    rteInputs,
                                        const SimHlaProPrtList_t* rteOutputs,
                                        const color_e             color
                                      )
{
  color_e color_input = color_white;
  uint8 counter;
  /* float32 borderAng; */
  float32 x_border;
  float32 x_border_old;

  float32 alpha = 1.0f;
  float32 blue  = 1.0f;
  unsigned int areaIndex;
  boolean areaSelected;

  if( !(rteInputs && rteOutputs ) 
     )
  {
    return;
  }
  /* indicate status of area */
  glBegin(GL_QUADS);
  {
    if (rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[0] == RTE_HLAF_DIMM_LEVEL_NO_REDUCT)
    {
      alpha = 0.0f;
    }
    else if (rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[0] == RTE_HLAF_DIMM_LEVEL_REDUCT_1)
    {
      alpha = 0.2f;
    }
    else if (rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[0] == RTE_HLAF_DIMM_LEVEL_REDUCT_2)
    {
      alpha = 0.4f;
      color_input = color_yellow;
    }
    SetColor(color_input, alpha);

    glVertex3i(m_HLARoi.X2, m_HLARoi.Y1, 1);
    glVertex3i(m_HLARoi.X2, m_HLARoi.Y2, 1);

    for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS_BORDERS ; counter++)
    {
      x_border = rteInputs->pMonoCalibration->sIntrinsic.fFocalX * tanf(rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[counter]);

      glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y2, 1);
      glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y1, 1);

      if (rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[counter+1] == RTE_HLAF_DIMM_LEVEL_NO_REDUCT)
      {
        alpha = 0.0f;
      }
      else if (rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[counter+1] == RTE_HLAF_DIMM_LEVEL_REDUCT_1)
      {
        alpha = 0.2f;
      }
      else if (rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[counter+1] == RTE_HLAF_DIMM_LEVEL_REDUCT_2)
      {
        alpha = 0.4f;
      }
      SetColor(color_input, alpha);

      glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y1, 1);
      glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y2, 1);
    }

    glVertex3i(m_HLARoi.X1, m_HLARoi.Y2, 1);
    glVertex3i(m_HLARoi.X1, m_HLARoi.Y1, 1);
  }
  glEnd();

  /* draw lines for the codeable regions */
  SetColor(color, 0.8f);

  areaSelected = b_FALSE;
  x_border_old = (float32)m_HLARoi.X2;
  for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS_BORDERS; counter++)
  {
    /* borderAng = rteInputs.pCPar_HlafPar->Dimming.AreaRightBorderArray[counter]; */
    x_border = m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - (rteInputs->pMonoCalibration->sIntrinsic.fFocalX * tanf(rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[counter]));

    glBegin(GL_LINES);
    {
      glVertex3f(x_border, (float32)m_HLARoi.Y1, 1);
      glVertex3f(x_border, (float32)m_HLARoi.Y2, 1);
    }
    glEnd();

    if(   (m_mouseInfo.current.x >= (int)x_border)
       && (m_mouseInfo.current.x <= (int)x_border_old)
       && (m_mouseInfo.current.y >= m_HLARoi.Y1)
       && (m_mouseInfo.current.y <= m_HLARoi.Y2)
      )
    {
      areaSelected = b_TRUE;
      areaIndex = counter;
    }
    x_border_old = x_border;
  }

  if(   (m_mouseInfo.current.x >= m_HLARoi.X1)
     && (m_mouseInfo.current.x <= (int)x_border_old)
     && (m_mouseInfo.current.y >= m_HLARoi.Y1)
     && (m_mouseInfo.current.y <= m_HLARoi.Y2)
    )
  {
    areaSelected = b_TRUE;
    areaIndex = 4;
  }


  const LSD_LightObject_t* pLSDObj = &rteInputs->pLsdLightObjectList->lightObjects[0];

  for (unsigned int i = 0; i < rteInputs->pLsdLightObjectList->numObjects; i++)
  {
    if(    (CML_GetBit(pLSDObj->attributes.statusBits, LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE) == true)
        && (pLSDObj->attributes.luminousFlux >= rteInputs->pCPar_HlafPar->Dimming.ReductThreshLevel1 * 166500u)
      )
    {
      SetColor(color_yellow, 0.5f);
      glBegin(GL_QUADS);
      {
        glVertex3i(pLSDObj->kinematic.camera.x /*- m_HLARoi.X1*/ - 5, pLSDObj->kinematic.camera.y /*- m_HLARoi.Y1*/ - 5, 1);
        glVertex3i(pLSDObj->kinematic.camera.x /*- m_HLARoi.X1*/ + 5, pLSDObj->kinematic.camera.y /*- m_HLARoi.Y1*/ - 5, 1);
        glVertex3i(pLSDObj->kinematic.camera.x /*- m_HLARoi.X1*/ + 5, pLSDObj->kinematic.camera.y /*- m_HLARoi.Y1*/ + 5, 1);
        glVertex3i(pLSDObj->kinematic.camera.x /*- m_HLARoi.X1*/ - 5, pLSDObj->kinematic.camera.y /*- m_HLARoi.Y1*/ + 5, 1);
      }
      glEnd();
    }
    pLSDObj++;
  }

  if (areaSelected == b_TRUE)
  {
    drawDimmingDetails( pContext,
                              rteInputs,
                              rteOutputs,
                              color,
                              areaIndex
                            );
  }
}

void CSimHlaVisuInt::drawDimmingDetails( const ISimRenderContext*  pContext,
                                               const reqHlaPrtList_t*    m_rteInputs,
                                               const SimHlaProPrtList_t* m_rteOutputs,
                                               const color_e             color,
                                               const unsigned int        index
                                              )
{
  int textLine = 1;
  int textPosX = 1150;
  int textCol2 = 120;
  const int textHeight = 10;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight - 3);
  char dimmTxt[255];

  font.BeginRender2D();
  {
    SetTextColor(color, font);
    font.RenderTextf(textPosX, textLine * textHeight, 1, "Dimming on Bright Objects"); textLine++;
    textLine++;
    font.RenderTextf(textPosX           , textLine * textHeight, 1, "Dimming Area:", index);
    font.RenderTextf(textPosX + textCol2, textLine * textHeight, 1, "%i", index); textLine++;
    font.RenderTextf(textPosX           , textLine * textHeight, 1, "Borders:");
    if(index == 0)
    {
      font.RenderTextf(textPosX + textCol2, textLine * textHeight, 1, "%1.0f°", CML_Rad2Deg(m_rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[0]));
    }
    else
    {
      font.RenderTextf(textPosX + textCol2, textLine * textHeight, 1, "%1.0f° to %1.0f°", CML_Rad2Deg(m_rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[index]), CML_Rad2Deg(m_rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[index-1]));
    }
    textLine++;
    font.RenderTextf(textPosX           , textLine * textHeight, 1, "Reduction Level:");

    switch(m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[index])
    {
    case RTE_HLAF_DIMM_LEVEL_NO_REDUCT:
      sprintf(dimmTxt, "(%d) RTE_HLAF_DIMM_LEVEL_NO_REDUCT", RTE_HLAF_DIMM_LEVEL_NO_REDUCT);
      break;
    case RTE_HLAF_DIMM_LEVEL_REDUCT_1:
      sprintf(dimmTxt, "(%d) RTE_HLAF_DIMM_LEVEL_REDUCT_1", RTE_HLAF_DIMM_LEVEL_REDUCT_1);
      break;
    case RTE_HLAF_DIMM_LEVEL_REDUCT_2:
      sprintf(dimmTxt, "(%d) RTE_HLAF_DIMM_LEVEL_REDUCT_2", RTE_HLAF_DIMM_LEVEL_REDUCT_2);
      break;
    case RTE_HLAF_DIMM_LEVEL_UNKNOWN:
    default:
      sprintf(dimmTxt, "(%d) RTE_HLAF_DIMM_LEVEL_UNKNOWN", RTE_HLAF_DIMM_LEVEL_UNKNOWN);
      break;
    }

    font.RenderTextf(textPosX + textCol2, textLine * textHeight, 1, dimmTxt); textLine++;
  }
  font.EndRender2D();
}

void CSimHlaVisuInt::drawEMObjects( const ISimRenderContext*        pContext,
                                    const EM_t_GenObjectList*       pEMObjectsList
                                   )
{

}

void CSimHlaVisuInt::getEMObjectsType( const EM_t_GenObject* pEMObject,
                                             string*         pEMObjectInfo
                                      )
{
  if ( pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_POINT)
  {
    *pEMObjectInfo += "Point: ";
  }
  else if ( pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_CAR)
  {
    *pEMObjectInfo += "Car: ";
  }
  else if(pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_TRUCK)
  {
    *pEMObjectInfo += "Truck: ";
  }
  else if(pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_PEDESTRIAN)
  {
    *pEMObjectInfo += "Pedestrian: ";
  }
  else if (pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_MOTORCYCLE)
  {
    *pEMObjectInfo += "Motorcycle: ";
  }
  else if (pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_BICYCLE)
  {
    *pEMObjectInfo += "Bicycle: ";
  }
  else if (pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_WIDE)
  {
    *pEMObjectInfo += "Wide: ";
  }
  else if (pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_UNCLASSIFIED)
  {
    *pEMObjectInfo += "Unclassified: ";
  }
  else if (pEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_OTHER_VEHICLE)
  {
    *pEMObjectInfo += "Other Vehicle: ";
  }

}

void CSimHlaVisuInt::getEMObjectsDynProperty( const EM_t_GenObject* pEMObject,
                                              string*               pEMObjectInfo
                                             )
{
  if ( pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_MOVING)
  {
    *pEMObjectInfo += "Moving";
  }
  else if(pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
  {
    *pEMObjectInfo += "Stationary";
  }
  else if (pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING)
  {
    *pEMObjectInfo += "Oncoming";
  }
  else if (pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT)
  {
    *pEMObjectInfo += "Cross Left";
  }
  else if (pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT)
  {
    *pEMObjectInfo += "Cross Right";
  }
  else if (pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN)
  {
    *pEMObjectInfo += "Unknown";
  }
  else if (pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)
  {
    *pEMObjectInfo += "Stopped";
  }
  else if (pEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES)
  {
    *pEMObjectInfo += "Max Diff Types";
  }

}
