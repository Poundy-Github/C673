/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_turnoff.h

  DESCRIPTION:            Draw general things like turnoff reasons

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.5 $

  ---*/ /*---

**************************************************************************** */

#include "stdafx.h"
#include "resource.h"

#include <cmath>
#include <string>

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#include "sim_hla_visu_turnoff.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")


void CALLBACK tessBeginCB(GLenum which)
{
    glBegin(which);
}

void CALLBACK tessEndCB()
{
    glEnd();
}

void CALLBACK tessVertexCB(const GLvoid *data)
{
    // cast back to double type
    const GLdouble *ptr = (const GLdouble*)data;
    glVertex3dv(ptr);
}


CSimHlaVisuTurnoff::CSimHlaVisuTurnoff()
//: 
{
}

CSimHlaVisuTurnoff::~CSimHlaVisuTurnoff()
{
}

void CSimHlaVisuTurnoff::Init()
{
}

void CSimHlaVisuTurnoff::draw2HeadlightStateRequest( const ISimRenderContext* pContext,
                                                           CSimVisuSubMenu*   pMenu,
                                                     const uint16             menuWidth /* = 0 */
                                                   )
{
  const reqHlaPrtList_t*       pRteIn_MCU  = (const reqHlaPrtList_t*)&pm_hlaMeasdata[VISU_ECU].ReqPorts;
  const reqHlaPrtList_t*       pRteIn_CAN  = (const reqHlaPrtList_t*)&pm_hlaMeasdata[VISU_CAN].ReqPorts;
  const reqHlaPrtList_t*       pRteIn_ENET = (const reqHlaPrtList_t*)&pm_hlaMeasdata[VISU_ENET].ReqPorts;
  const SimHlaProPrtList_t*    pRteOut_SIL = &pm_hlaMeasdata[VISU_SIL].ProPorts;
  const SimHlaProPrtList_t*    pRteOut_MCU = &pm_hlaMeasdata[VISU_ECU].ProPorts;

  const int textHeight = 10;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-3);
  /* draw colors for headlight symbol */
  color_e statusColor;
  color_e headlightColor;
  int x, y, xBig, yBig;
  float r_small = 15;
  float r_big = 120;
  uint16 space = 40;

  RTE_HLAF_HighBeamState eHighBeamState;

  if(m_HLARoi.X2 >= (menuWidth+m_HLARoi.X1))
  {
    x = m_HLARoi.X2 + 55;
    y = m_HLARoi.Y2 + 135;
  }
  else
  {
    x = menuWidth + m_HLARoi.X1 + 55;
    y = m_HLARoi.Y2 + 135;
  }

  xBig = m_HLARoi.X1 + (m_HLARoi.X2 - m_HLARoi.X1)/2 + 120; /* 120 = r */
  yBig = m_HLARoi.Y1 + (m_HLARoi.Y2 - m_HLARoi.Y1)/2;

  /*  draw high beam status Headlight, DLL and MCU */
  /* 0. Headlight state */
  const reqHlaPrtList_t* pRIn = NULL;
  switch(m_activePlane)
  {
  case VISU_CAN:
    pRIn = pRteIn_CAN;

    headlightColor = color_can;

    /* red */
    statusColor = color_red;

    break;
  case VISU_ENET:
    pRIn = pRteIn_ENET;

    /* orange */
    headlightColor = color_eth;

    /* red */
    statusColor = color_red;

    break;
  case VISU_SIL:
  case VISU_ECU:
  default:
    pRIn = pRteIn_MCU;

    /* yellow */
    headlightColor = color_yellow;

    /* red */
    statusColor = color_red;

    break;
  }

  if(   (pRIn != NULL)
     && (pRIn->pHlaBusInputSignals != NULL)
    )
  {
    if(    (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_SMALL) == true)
        || (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_ALL) == true)
      )
    {
      font.BeginRender2D();
      SetTextColor(headlightColor, font);
      font.RenderTextf(x+20, y-5, 1, "BUS");
      font.EndRender2D();

      draw2HeadlightStateIcon( pRIn->pHlaBusInputSignals->headLightState,
                               x,
                               y,
                               r_small,
                               headlightColor,
                               statusColor
                              );
    }
  }

  /* 1. ECU */
  if(   (pRteOut_MCU != NULL) 
    && (pRteOut_MCU->pHlaf_HeadlightControl != NULL)
    )
  {
    headlightColor = color_ecu;
    statusColor = color_red;

    if(pRteOut_MCU->pHlaf_HeadlightControl->Matrix.HighBeamState == RTE_HLAF_HB_STATE_OFF)
    {
      if(   (pRteOut_MCU->pHlaf_HeadlightControl->Matrix.nGFA > 0)
        && false //TODO secretView
        )
      {
        eHighBeamState = RTE_HLAF_HB_STATE_PARTIAL;
      }
      else
      {
        eHighBeamState = RTE_HLAF_HB_STATE_OFF;
      }
    }
    else if (pRteOut_MCU->pHlaf_HeadlightControl->Matrix.HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
    {
      eHighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else
    {
      eHighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;
    }
    
    if(    (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_SMALL) == true)
        || (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_ALL) == true)
      )
    {
      y += space;
      font.BeginRender2D();
      SetTextColor(headlightColor, font);
      font.RenderTextf(x+20, y-5, 1, "ECU");
      font.EndRender2D();

      draw2HeadlightStateIcon( eHighBeamState,
                               x,
                               y,
                               r_small,
                               headlightColor,
                               statusColor
                              );
    }
    if(    (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_BIG) == true)
        || (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_ALL) == true)
      )
    {
      draw2HeadlightStateIcon( eHighBeamState,
                               xBig,
                               yBig,
                               r_big,
                               headlightColor,
                               statusColor,
                               0.2f
                              );
    }
  }

  /* 2. DLL */
  if(   (pRteOut_SIL != NULL)
    && (pRteOut_SIL->pHlaf_HeadlightControl != NULL)
    )
  {
    headlightColor = color_sil;
    statusColor = color_red;

    if(pRteOut_SIL->pHlaf_HeadlightControl->Matrix.HighBeamState == RTE_HLAF_HB_STATE_OFF)
    {
      if(   (pRteOut_SIL->pHlaf_HeadlightControl->Matrix.nGFA > 0)
        && false //TODO secretView
        )
      {
        eHighBeamState = RTE_HLAF_HB_STATE_PARTIAL;
      }
      else
      {
        eHighBeamState = RTE_HLAF_HB_STATE_OFF;
      }
    }
    else if(pRteOut_SIL->pHlaf_HeadlightControl->Matrix.HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
    {
      eHighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else
    {
      eHighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;
    }

    if(    (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_SMALL) == true)
        || (pMenu->getItemActivation(MENU_BUTTON_DIAG_HLSTATEREQ, MENU_BUTTON_DIAG_HLSTATEREQ_S_ALL) == true)
      )
    {
      y += space;
      font.BeginRender2D();
      SetTextColor(headlightColor, font);
      font.RenderTextf(x+20, y-5, 1, "DLL");
      font.EndRender2D();

      draw2HeadlightStateIcon( eHighBeamState,
                               x,
                               y,
                               r_small,
                               headlightColor,
                               statusColor
                              );
    }
  }
}

void CSimHlaVisuTurnoff::draw2HeadlightStateRequestVis( const ISimRenderContext*  pContext,
                                                         const reqHlaPrtList_t*    pRteIn_MCU,
                                                         const reqHlaPrtList_t*    pRteIn_CAN,
                                                         const reqHlaPrtList_t*    pRteIn_ENET,
                                                         const SimHlaProPrtList_t* pRteOut_SIL,
                                                         const SimHlaProPrtList_t* pRteOut_MCU,
                                                               boolean             drawBig /* = false */
                                                       )
{
  const int textHeight = 10;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-3);
  /* draw colors for headlight symbol */
  color_e statusColor;
  color_e headlightColor;
  int x = 770;
  int y = 10;
  int xBig, yBig;
  float r = 30;
  float r_big = 100;
  uint16 space = 40;

  xBig = m_HLARoi.X1 + (m_HLARoi.X2 - m_HLARoi.X1)/2 + 120; /* 120 = r */
  yBig = m_HLARoi.Y1 + (m_HLARoi.Y2 - m_HLARoi.Y1)/2;
  RTE_HLAF_HighBeamState eHighBeamState;

  /*  draw high beam status Headlight, DLL and MCU */
  /* 0. Headlight state */
  const reqHlaPrtList_t* pRIn = NULL;
  switch(m_activePlane)
  {
  case VISU_CAN:
    pRIn = pRteIn_CAN;

    headlightColor = color_can;

    /* red */
    statusColor = color_red;

    break;
  case VISU_ENET:
    pRIn = pRteIn_ENET;

    /* orange */
    headlightColor = color_eth;

    /* red */
    statusColor = color_red;

    break;
  case VISU_SIL:
  case VISU_ECU:
  default:
    pRIn = pRteIn_MCU;

    /* yellow */
    headlightColor = color_yellow;

    /* red */
    statusColor = color_red;

    break;
  }

  if(   (pRIn != NULL)
     && (pRIn->pHlaBusInputSignals != NULL)
    )
  {
     if(!drawBig)
     {
       /*x -= (int)(4*r);*/
       font.BeginRender2D();
       SetTextColor(headlightColor, font);
       font.RenderTextf(x-(int)(3*r), y, 1, "BUS HIGHBEAM STATE");
       font.EndRender2D();

       draw2HeadlightStateIcon( pRIn->pHlaBusInputSignals->headLightState,
                                x,
                                y + (int)(2*r),
                                r,
                                headlightColor,
                                statusColor
                               );
     }
  }

  /* 1. ECU */
  if(   (pRteOut_MCU != NULL) 
     && (pRteOut_MCU->pHlaf_HeadlightControl != NULL)
    )
  {
    headlightColor = color_ecu;
    statusColor = color_red;

    if(pRteOut_MCU->pHlaf_HeadlightControl->Matrix.HighBeamState == RTE_HLAF_HB_STATE_OFF)
    {
      if(   (pRteOut_MCU->pHlaf_HeadlightControl->Matrix.nGFA > 0)
        && false //TODO secretView
        )
      {
        eHighBeamState = RTE_HLAF_HB_STATE_PARTIAL;
      }
      else
      {
        eHighBeamState = RTE_HLAF_HB_STATE_OFF;
      }
    }
    else if (pRteOut_MCU->pHlaf_HeadlightControl->Matrix.HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
    {
      eHighBeamState = RTE_HLAF_HB_STATE_FULL_ON;
    }
    else
    {
      eHighBeamState = RTE_HLAF_HB_STATE_UNKNOWN;
    }
    
    if(drawBig)
    {
      draw2HeadlightStateIcon( eHighBeamState,
                               xBig,
                               yBig,
                               r_big,
                               headlightColor,
                               statusColor,
                               0.2f
                              );
    }
    else
    {
      x -= (int)(5*r);
      font.BeginRender2D();
      SetTextColor(headlightColor, font);
      font.RenderTextf(x-(int)(3*r), y, 1, "ECU HIGHBEAM REQ");
      font.EndRender2D();
      
      draw2HeadlightStateIcon( eHighBeamState,
                                x,
                                y + (int)(2*r),
                                r,
                                headlightColor,
                                statusColor
                              );
    }
  }
}


void CSimHlaVisuTurnoff::draw2HeadlightStateIcon( const RTE_HLAF_HighBeamState  eHighBeamState,
                                                         int                     posx,
                                                         int                     posy,
                                                         float                   r,
                                                   const color_e                 headlightColor,
                                                   const color_e                 statusColor,
                                                         float                   alpha /* = 1.0f */
                                                   )
{
  /* circles */
  const int num_segments = 180/2;
  const int num_segments2 = 180/4;
  float r2 = r/2;
  float posxTmp = 0;
  float posyTmp = 0;
  float arc_angle = CML_f_Pi;
  float start_angle = -CML_f_Pi/2;  
  float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
  float tangetial_factor = tanf(theta);
  float radial_factor = cosf(theta);
  float x = 0;//we now start at the start angle
  float y = 0;
  float tx = 0; 
  float ty = 0; 

  /* brigth bars */
  float brigthX = (float)posx - r/2 - r2;
  const float  brightLengthMax = 2*r;
  
  GLdouble  outside[2*(num_segments2-1)+(num_segments-1)+7][3];
  GLdouble  inside[2*(num_segments2-1)+(num_segments-1)+7][3];

  /* outer headlamp corpus */
  outside[0][0] = (float)posx; 
  outside[0][1] = (float)posy + r;
  outside[0][2] = 1;

  outside[1][0] = (float)posx - r/2; 
  outside[1][1] = (float)posy + r;
  outside[1][2] = 1;

  posxTmp = (float)posx - r/2;
  posyTmp = (float)posy + r - r2;
  arc_angle = CML_f_Pi/2;
  start_angle = CML_f_Pi/2;  
  theta = arc_angle / float(num_segments2 - 1);
  tangetial_factor = tanf(theta);
  radial_factor = cosf(theta);

  x = r2 * cosf(start_angle);//we now start at the start angle
  y = r2 * sinf(start_angle); 
  for(int ii = 0; ii < num_segments2; ii++)
  {
    outside[ii+2][0] = x + posxTmp; 
    outside[ii+2][1] = y + posyTmp;
    outside[ii+2][2] = 1;

    tx = -y; 
    ty = x; 

    x += tx * tangetial_factor; 
    y += ty * tangetial_factor; 

    x *= radial_factor; 
    y *= radial_factor; 
  }
  outside[num_segments2+2][0] = (float)posx- r/2 -r2; 
  outside[num_segments2+2][1] = (float)posy + r - r2;
  outside[num_segments2+2][2] = 1;

  outside[num_segments2+3][0] = (float)posx- r/2 -r2; 
  outside[num_segments2+3][1] = (float)posy - r + r2;
  outside[num_segments2+3][2] = 1;

  posxTmp = (float)posx - r/2;
  posyTmp = (float)posy - r + r2;
  arc_angle = CML_f_Pi/2;
  start_angle = CML_f_Pi;  
  theta = arc_angle / float(num_segments2 - 1);
  tangetial_factor = tanf(theta);
  radial_factor = cosf(theta);

  x = r2 * cosf(start_angle);//we now start at the start angle
  y = r2 * sinf(start_angle); 
  for(int ii = 0; ii < num_segments2; ii++)
  { 
    outside[num_segments2+4+ii][0] = x + posxTmp; 
    outside[num_segments2+4+ii][1] = y + posyTmp;
    outside[num_segments2+4+ii][2] = 1;

    tx = -y; 
    ty = x; 

    x += tx * tangetial_factor; 
    y += ty * tangetial_factor; 

    x *= radial_factor; 
    y *= radial_factor; 
  }
  
  arc_angle = CML_f_Pi;
  start_angle = -CML_f_Pi/2;
  theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
  tangetial_factor = tanf(theta);
  radial_factor = cosf(theta);
  x = 0;//we now start at the start angle
  y = 0;
  tx = 0; 
  ty = 0; 
  
  x = r * cosf(start_angle);//we now start at the start angle
  y = r * sinf(start_angle); 
  for(int ii = 0; ii < num_segments; ii++)
  { 
    outside[2*num_segments2+4+ii][0] = x + (float)posx; 
    outside[2*num_segments2+4+ii][1] = y + (float)posy;
    outside[2*num_segments2+4+ii][2] = 1;

    tx = -y; 
    ty = x; 

    x += tx * tangetial_factor; 
    y += ty * tangetial_factor; 

    x *= radial_factor; 
    y *= radial_factor; 
  }

  /* inner headlamp corpus */
  float rs = (7*r)/12;
  float rs2 = rs/2;

  inside[0][0] = (float)posx; 
  inside[0][1] = (float)posy + rs;
  inside[0][2] = 1;

  inside[1][0] = (float)posx - rs/2; 
  inside[1][1] = (float)posy + rs;
  inside[1][2] = 1;

  posxTmp = (float)posx - rs/2;
  posyTmp = (float)posy + rs - rs2;
  arc_angle = CML_f_Pi/2;
  start_angle = CML_f_Pi/2;  
  theta = arc_angle / float(num_segments2 - 1);
  tangetial_factor = tanf(theta);
  radial_factor = cosf(theta);

  x = rs2 * cosf(start_angle);//we now start at the start angle
  y = rs2 * sinf(start_angle); 
  for(int ii = 0; ii < num_segments2; ii++)
  {
    inside[ii+2][0] = x + posxTmp; 
    inside[ii+2][1] = y + posyTmp;
    inside[ii+2][2] = 1;

    tx = -y; 
    ty = x; 

    x += tx * tangetial_factor; 
    y += ty * tangetial_factor; 

    x *= radial_factor; 
    y *= radial_factor; 
  }
  inside[num_segments2+2][0] = (float)posx- rs/2 -rs2; 
  inside[num_segments2+2][1] = (float)posy + rs - rs2;
  inside[num_segments2+2][2] = 1;

  inside[num_segments2+3][0] = (float)posx- rs/2 -rs2; 
  inside[num_segments2+3][1] = (float)posy - rs + rs2;
  inside[num_segments2+3][2] = 1;

  posxTmp = (float)posx - rs/2;
  posyTmp = (float)posy - rs + rs2;
  arc_angle = CML_f_Pi/2;
  start_angle = CML_f_Pi;  
  theta = arc_angle / float(num_segments2 - 1);
  tangetial_factor = tanf(theta);
  radial_factor = cosf(theta);

  x = rs2 * cosf(start_angle);//we now start at the start angle
  y = rs2 * sinf(start_angle); 
  for(int ii = 0; ii < num_segments2; ii++)
  { 
    inside[num_segments2+4+ii][0] = x + posxTmp; 
    inside[num_segments2+4+ii][1] = y + posyTmp;
    inside[num_segments2+4+ii][2] = 1;

    tx = -y; 
    ty = x; 

    x += tx * tangetial_factor; 
    y += ty * tangetial_factor; 

    x *= radial_factor; 
    y *= radial_factor; 
  }
  
  arc_angle = CML_f_Pi;
  start_angle = -CML_f_Pi/2;
  theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
  tangetial_factor = tanf(theta);
  radial_factor = cosf(theta);
  x = 0;//we now start at the start angle
  y = 0;
  tx = 0; 
  ty = 0; 
  
  x = rs * cosf(start_angle);//we now start at the start angle
  y = rs * sinf(start_angle); 
  for(int ii = 0; ii < num_segments; ii++)
  { 
    inside[2*num_segments2+4+ii][0] = x + (float)posx; 
    inside[2*num_segments2+4+ii][1] = y + (float)posy;
    inside[2*num_segments2+4+ii][2] = 1;

    tx = -y; 
    ty = x; 

    x += tx * tangetial_factor; 
    y += ty * tangetial_factor; 

    x *= radial_factor; 
    y *= radial_factor; 
  }

  SetColor(headlightColor, alpha);

  GLuint id = glGenLists(1);
  GLUtesselator *tess = gluNewTess();

  // register callback functions
  gluTessCallback(tess, GLU_TESS_BEGIN, (void (__stdcall*)(void))tessBeginCB);
  gluTessCallback(tess, GLU_TESS_END, (void (__stdcall*)(void))tessEndCB);
  gluTessCallback(tess, GLU_TESS_VERTEX, (void (__stdcall*)())tessVertexCB);

  gluTessBeginPolygon(tess, 0);                       // with NULL data
      gluTessBeginContour(tess);                      // outer quad
        for(int i = 0; i < (2*(num_segments2-1)+(num_segments-1)+7) ; i++)
        {
          gluTessVertex(tess, outside[i], outside[i]);
        }
      gluTessEndContour(tess);
      gluTessBeginContour(tess);                      // inner quad (hole)
        for(int i = 0; i < (2*(num_segments2-1)+(num_segments-1)+7) ; i++)
        {
          gluTessVertex(tess, inside[i], inside[i]);
        }
      gluTessEndContour(tess);
  gluTessEndPolygon(tess);

  gluDeleteTess(tess);        // delete after tessellation

  /* draw "beams" of headlamps */
  /* outer right */

  drawFilledRectf(brigthX - brightLengthMax, (float)posy - (4*r/5) + (r/10), brigthX -  r2/2, (float)posy - (3*r/5) + (r/10));
  if(eHighBeamState != RTE_HLAF_HB_STATE_PARTIAL)
  {
    /* inner right */
    drawFilledRectf(brigthX - brightLengthMax, (float)posy - (2*r/5) + (r/10), brigthX -  r2/2, (float)posy - (1*r/5) + (r/10));
    /* inner left */
    drawFilledRectf(brigthX - brightLengthMax, (float)posy + (1*r/5) - (r/10), brigthX -  r2/2, (float)posy + (2*r/5) - (r/10));
  }
  /* outer left */
  drawFilledRectf(brigthX - brightLengthMax, (float)posy + (3*r/5) - (r/10), brigthX -  r2/2, (float)posy + (4*r/5) - (r/10));

  /* right frames */
  drawRectf(brigthX - brightLengthMax, (float)posy - (4*r/5) + (r/10), brigthX -  r2/2, (float)posy - (3*r/5) + (r/10));
  drawRectf(brigthX - brightLengthMax, (float)posy - (2*r/5) + (r/10), brigthX -  r2/2, (float)posy - (1*r/5) + (r/10));
  /* left frames */
  drawRectf(brigthX - brightLengthMax, (float)posy + (1*r/5) - (r/10), brigthX -  r2/2, (float)posy + (2*r/5) - (r/10));
  drawRectf(brigthX - brightLengthMax, (float)posy + (3*r/5) - (r/10), brigthX -  r2/2, (float)posy + (4*r/5) - (r/10));

  /* HB off -> strike through */
  if(    (eHighBeamState  == RTE_HLAF_HB_STATE_OFF)
    || (eHighBeamState  == RTE_HLAF_HB_STATE_UNKNOWN)
    )
  {
    SetColor(statusColor, alpha);
    glBegin(GL_QUADS);
    {
      glVertex3f(brigthX + (2*brightLengthMax/5), (float)posy - (6*r/5), 1);
      glVertex3f(brigthX - (4*brightLengthMax/5), (float)posy + (6*r/5), 1);
      glVertex3f(brigthX - (2*brightLengthMax/5), (float)posy + (6*r/5), 1);
      glVertex3f(brigthX + (4*brightLengthMax/5), (float)posy - (6*r/5), 1);
    }
    glEnd();  
  }
}

void CSimHlaVisuTurnoff::draw2MatrixTurnOffReasonHBStateDraw(  const ISimRenderContext*                  pContext,
                                                               const char*                               Name,
                                                               const RTE_HLAF_MatrixTurnOffReason        TurnOffReason,
                                                               const RTE_HLAF_HighBeamState              eHighBeamState,
                                                               const RTE_HLAF_HeadlightControl_Common_t* pHeadlightControlCommon,
                                                               const uint8                               testSymbols,
                                                               const color_e                             color,
                                                                     int                                 xpos,
                                                                     int                                 ypos,
                                                               const int                                 symbol_size, 
                                                               const int                                 border_size, 
                                                               const int                                 symbol_gap,
                                                               const bool                                swichOff
                                                              )
{
  const int textHeight = 13;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-5);

  font.BeginRender2D();
  SetTextColor(color, font);
  font.RenderTextf(xpos, ypos, 1, Name);
  font.EndRender2D();
  ypos += 20;


  /* ********** Draw oncoming vehicle symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_ONC)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_ONCOMING_VEHICLE, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw preceding symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_PREC)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_PRECEDING_VEHICLE, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw highway symbol ********** */
  if( (testSymbols == 1)
    ||(   (pHeadlightControlCommon != NULL)
       && (pHeadlightControlCommon->MotorwayState == RTE_HLAF_MTWY_MOTORWAY)
      )
    )
  {
    /* highway */
    drawRGBimageInFrame(IDR_IMAGE_HIGHWAY_DTCT, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else if(   (pHeadlightControlCommon != NULL)
          && (pHeadlightControlCommon->MotorwayState == RTE_HLAF_MTWY_UNKNOWN)
         )
  {
     /* highway with question mark */
     drawRGBimageInFrame(IDR_IMAGE_HIGHWAY_IDLE, xpos, ypos, symbol_size, symbol_size, border_size, color);
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw Traffic style symbol ********** */
  if(    (testSymbols == 1)
    || (   (pHeadlightControlCommon != NULL)
        && (pHeadlightControlCommon->TrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHT)
       )
    )
  {
    /* left hand traffic detected */
    drawRGBimageInFrame(IDR_IMAGE_LHT_TRAFFIC, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else if(    (pHeadlightControlCommon != NULL)
          &&  (pHeadlightControlCommon->TrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHT)
    )
  {
    /* left hand traffic detected */
    drawRGBimageInFrame(IDR_IMAGE_RHT_TRAFFIC, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* do nothing - traffic style unknown */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw brightness symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_BRIGHTNESS)
    )
  {
    if(pHeadlightControlCommon == NULL)
    {
      /* sunshine */
      drawRGBimageInFrame(IDR_IMAGE_DAYLIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color);
    }
    else
    {      
      if(pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_DAY)
      {
        /* sunshine */
        drawRGBimageInFrame(IDR_IMAGE_DAYLIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color);
      }
      else if(pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_TWLGT_1)
      {
        /* twilight 1 */
        drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_1, xpos, ypos, symbol_size, symbol_size, border_size, color);   
      }
      else if (pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_TWLGT_2)
      {
        /* twilight 2 */
        drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_2, xpos, ypos, symbol_size, symbol_size, border_size, color);
      }
      else if (pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_TWLGT_3)
      {
        /* twilight 3 */
        drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_3, xpos, ypos, symbol_size, symbol_size, border_size, color);
      }
      else if (pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_NIGHT)
      {
        /* nothing */
      }
      else /* testSymbol */
      {
        /* sunshine */
        drawRGBimageInFrame(IDR_IMAGE_DAYLIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color);
      }
    }
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw delay symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_DELAY)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_DELAY, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw low speed symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_SPEED)
    )
  {
    /* low speed */
    drawRGBimageInFrame(IDR_IMAGE_MIN_SPEED, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw city symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_CITY)
    ) 
  {
    /* city */
    drawRGBimageInFrame(IDR_IMAGE_CITY_DTCT, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;
  
#if 1
  /* ********** Draw Tunnel symbol ********** */
  if(   (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_TUNNEL)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_TUNNEL_INSIDE, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else if(  (pHeadlightControlCommon != NULL)
         && (pHeadlightControlCommon->TunnelState == RTE_HLAR_TUNNEL_UPFRONT)
         )
  {
    /* tunnel with arrow */
    drawRGBimageInFrame(IDR_IMAGE_TUNNEL_AHEAD, xpos, ypos, symbol_size, symbol_size, border_size, color);
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;
#endif

  /* ********** Draw fog symbol ********** */
  if(    (testSymbols == 1)
      || (TurnOffReason & RTE_HLAF_TURNOFFREASON_FOG)
    )
  {
    /* fog */
    drawRGBimageInFrame(IDR_IMAGE_FOG, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw bad weather symbol ********** */
  if(    (testSymbols == 1)
      || (TurnOffReason & RTE_HLAF_TURNOFFREASON_WEATHER)
    )
  {
    /* rain cloud */
    drawRGBimageInFrame(IDR_IMAGE_BAD_WEATHER, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw US sensitivity symbol ********** */
  if(  (testSymbols == 1)
    || (   (pHeadlightControlCommon != NULL)
        && (pHeadlightControlCommon->SensMode == RTE_HLA_SENSMODE_US)
       )
    )
  {
    /* US sensitivity icon */
    drawRGBimageInFrame(IDR_IMAGE_MERICA, xpos, ypos, symbol_size, symbol_size, border_size, color);
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

    /* ********** Draw Blockage symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_BLOCKAGE)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_BLOCKAGE_FULLBLIND, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }

  ypos += symbol_size + symbol_gap;

  /* ********** Draw turn off reason error symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_ERROR)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_TURNOFF_ERROR, xpos, ypos, symbol_size, symbol_size, border_size, color);
    if(swichOff == true)
    {
      drawSwitchOfFrame(xpos, ypos, symbol_size, symbol_size, border_size/2);
    }
  }
  else
  {
    /* nothing */
  }
  
  ypos += symbol_size + symbol_gap;

}  

void CSimHlaVisuTurnoff::draw2MatrixTurnOffReasonHBStateDrawVis(const ISimRenderContext*                  pContext,
                                                                 const char*                               Name,
                                                                 const RTE_HLAF_MatrixTurnOffReason        TurnOffReason,
                                                                 const RTE_HLAF_HighBeamState              eHighBeamState,
                                                                 const RTE_HLAF_HeadlightControl_Common_t* pHeadlightControlCommon,
                                                                 const uint8                               testSymbols,
                                                                 const color_e                             color,
                                                                       int                                 xpos,
                                                                       int                                 ypos,
                                                                 const int                                 symbol_size, 
                                                                 const int                                 border_size, 
                                                                 const int                                 symbol_gap,
                                                                 const bool                                swichOff
                                                                )
{
  const int textHeight = 13;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-5);

  font.BeginRender2D();
  SetTextColor(color, font);
  font.RenderTextf(xpos, ypos, 1, Name);
  font.EndRender2D();
  xpos += 40;


  /* ********** Draw oncoming vehicle symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_ONC)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_ONCOMING_VEHICLE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw preceding symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_PREC)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_PRECEDING_VEHICLE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw low speed symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_SPEED)
    )
  {
    /* low speed */
    drawRGBimageInFrame(IDR_IMAGE_MIN_SPEED, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }



  /* ********** Draw brightness symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_BRIGHTNESS)
    )
  {
    if(pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_DAY)
    {
      /* sunshine */
      drawRGBimageInFrame(IDR_IMAGE_DAYLIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    }
    else if(pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_TWLGT_1)
    {
      /* twilight 1 */
      drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_1, xpos, ypos, symbol_size, symbol_size, border_size, color, true);   
    }
    else if (pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_TWLGT_2)
    {
      /* twilight 2 */
      drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_2, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    }
    else if (pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_TWLGT_3)
    {
      /* twilight 3 */
      drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_3, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    }
    else if (pHeadlightControlCommon->BrightnessState == RTE_HLAR_BRT_NIGHT)
    {
      /* nothing */
    }
    else /* testSymbol */
    {
      /* sunshine */
      drawRGBimageInFrame(IDR_IMAGE_DAYLIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    }
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw city symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_CITY)
    ) 
  {
    /* city */
    drawRGBimageInFrame(IDR_IMAGE_CITY_DTCT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw fog symbol ********** */
  if(    (testSymbols == 1)
      || (TurnOffReason & RTE_HLAF_TURNOFFREASON_FOG)
    )
  {
    /* fog */
    drawRGBimageInFrame(IDR_IMAGE_FOG, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw bad weather symbol ********** */
  if(    (testSymbols == 1)
      || (TurnOffReason & RTE_HLAF_TURNOFFREASON_WEATHER)
    )
  {
    /* rain cloud */
    drawRGBimageInFrame(IDR_IMAGE_BAD_WEATHER, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw delay symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_DELAY)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_DELAY, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw Blockage symbol ********** */
  if(    (testSymbols == 1)
    || (TurnOffReason & RTE_HLAF_TURNOFFREASON_BLOCKAGE)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_BLOCKAGE_FULLBLIND, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }
  
  /* ********** Draw highway symbol ********** */
  if( (testSymbols == 1)
    ||(   (pHeadlightControlCommon != NULL)
       && (pHeadlightControlCommon->MotorwayState == RTE_HLAF_MTWY_MOTORWAY)
      )
    )
  {
    /* highway */
    drawRGBimageInFrame(IDR_IMAGE_HIGHWAY_DTCT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else if(   (pHeadlightControlCommon != NULL)
          && (pHeadlightControlCommon->MotorwayState == RTE_HLAF_MTWY_UNKNOWN)
         )
  {
     /* highway with question mark */
     drawRGBimageInFrame(IDR_IMAGE_HIGHWAY_IDLE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
     xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw Traffic style symbol ********** */
  if(    (testSymbols == 1)
    || (   (pHeadlightControlCommon != NULL)
    && (pHeadlightControlCommon->TrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHT)
    )
    )
  {
    /* left hand traffic detected */
    drawRGBimageInFrame(IDR_IMAGE_LHT_TRAFFIC, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else if(    (pHeadlightControlCommon != NULL)
    &&  (pHeadlightControlCommon->TrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHT)
    )
  {
    /* right hand traffic detected */
    drawRGBimageInFrame(IDR_IMAGE_RHT_TRAFFIC, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* do nothing - traffic style unknown */
  }

  /* ********** Draw US sensitivity symbol ********** */
  if(  (testSymbols == 1)
    || (   (pHeadlightControlCommon != NULL)
        && (pHeadlightControlCommon->SensMode == RTE_HLA_SENSMODE_US)
       )
    )
  {
    /* US sensitivity icon */
    drawRGBimageInFrame(IDR_IMAGE_MERICA, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw high beam state ********** */
  if(    (testSymbols == 1)
    || (eHighBeamState == RTE_HLAF_HB_STATE_OFF)
    )
  {
    drawRGBimageInFrame(IDR_IMAGE_HB_OFF, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else if(eHighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
  {
    drawRGBimageInFrame(IDR_IMAGE_HB_ON, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else if(eHighBeamState == RTE_HLAF_HB_STATE_PARTIAL)
  {
    drawRGBimageInFrame(IDR_IMAGE_HB_PARTIAL_LEFT_RIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
    xpos += symbol_size + symbol_gap;
  }
  else
  {
    /* nothing */
  }
}  

void CSimHlaVisuTurnoff::drawRGBimageInFrame( const unsigned long resourceID, 
                                               const int           x, 
                                               const int           y, 
                                               const int           width, 
                                               const int           height, 
                                               const int           border_size, 
                                               const color_e       color,
                                               const bool          withFrame
                                              )
{
  SetColor(color);

  if(withFrame)
  {
    glBegin(GL_QUADS);
    {
      /* left */
      glVertex3i(x - border_size, y - border_size , 1);
      glVertex3i(x - border_size, y + height + border_size , 1);
      glVertex3i(x, y + height + border_size, 1);
      glVertex3i(x, y - border_size, 1);
      /* right */
      glVertex3i(x + width, y - border_size , 1);
      glVertex3i(x + width, y + height + border_size , 1);
      glVertex3i(x + width + border_size, y + height + border_size, 1);
      glVertex3i(x + width + border_size, y - border_size, 1);
      /* top */
      glVertex3i(x, y - border_size, 1);
      glVertex3i(x, y, 1);
      glVertex3i(x + width, y, 1);
      glVertex3i(x + width, y - border_size, 1);
      /* bottom */
      glVertex3i(x, y + height, 1);
      glVertex3i(x, y + height + border_size, 1);
      glVertex3i(x + width, y + height + border_size, 1);
      glVertex3i(x + width, y + height, 1);
    }
    glEnd();
  }

  drawRGBimage(resourceID, x, y, width, height);
}

void CSimHlaVisuTurnoff::drawSwitchOfFrame( const int x, 
                                             const int y, 
                                             const int width, 
                                             const int height, 
                                             const int border_size
                                            )
{
  SetColor(color_red);

  glBegin(GL_QUADS);
  {
    /* left */
    glVertex3i(x - border_size, y - border_size , 1);
    glVertex3i(x - border_size, y + height + border_size , 1);
    glVertex3i(x, y + height + border_size, 1);
    glVertex3i(x, y - border_size, 1);
    /* right */
    glVertex3i(x + width, y - border_size , 1);
    glVertex3i(x + width, y + height + border_size , 1);
    glVertex3i(x + width + border_size, y + height + border_size, 1);
    glVertex3i(x + width + border_size, y - border_size, 1);
    /* top */
    glVertex3i(x, y - border_size, 1);
    glVertex3i(x, y, 1);
    glVertex3i(x + width, y, 1);
    glVertex3i(x + width, y - border_size, 1);
    /* bottom */
    glVertex3i(x, y + height, 1);
    glVertex3i(x, y + height + border_size, 1);
    glVertex3i(x + width, y + height + border_size, 1);
    glVertex3i(x + width, y + height, 1);
  }
  glEnd();
}

void CSimHlaVisuTurnoff::drawRGBimage( const  unsigned long resourceID,
                                        const int           x, 
                                        const int           y,
                                        const int           width,
                                        const int           height
                                       )
{
  extern HANDLE g_hModule;
  HRSRC myResource = ::FindResource((HMODULE)g_hModule, MAKEINTRESOURCE(resourceID), RT_RCDATA);
  HGLOBAL myResourceData = ::LoadResource((HMODULE)g_hModule, myResource);
  unsigned char* pimg = (unsigned char*)::LockResource(myResourceData);

  GLuint textureName;
  glGenTextures(1, &textureName);

  glColor4ub(255, 255, 255, 255);     // set white color

  glEnable(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, textureName);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, pimg);

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex2f((float)x          , (float)y);
  glTexCoord2f(1.0f, 0.0f); glVertex2f((float)(x + width), (float)y);
  glTexCoord2f(1.0f, 1.0f); glVertex2f((float)(x + width), (float)(y + height));
  glTexCoord2f(0.0f, 1.0f); glVertex2f((float)x          , (float)(y + height));
  glEnd();

  glBindTexture(GL_TEXTURE_2D, 0);

  glDisable(GL_TEXTURE_2D);

  glDeleteTextures(1, &textureName);  // free texture

}

void CSimHlaVisuTurnoff::drawFunctionSymbolsDraw( const SimHlaProPrtList_t* pRteOut,
                                                   const uint8               testSymbols,
                                                   const color_e             color,
                                                   const int                 xpos,
                                                         int                 ypos,
                                                   const int                 symbol_size, 
                                                   const int                 border_size, 
                                                   const int                 symbol_gap
                                                  )
{
  float r,g,b;
  ConvertColor(color,r,g,b);
  ypos += 20;
  /* ********** Draw Target driving direction ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {        
    RTE_HLAF_ObjStatus ObjStatus;

    ObjStatus = pRteOut->pHlaf_HeadlightControl->Matrix.LowBeam_Status;

    if(   (ObjStatus == RTE_HLAF_OBJSTA_ONC_OBJ)
       || (testSymbols == 1)
      )
    {
      /* oncoming vehicle */
      drawRGBimageInFrame(IDR_IMAGE_ONCOMING_VEHICLE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (ObjStatus == RTE_HLAF_OBJSTA_PREC_OBJ)
    {
      /* preceding vehicle */
      drawRGBimageInFrame(IDR_IMAGE_PRECEDING_VEHICLE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else
    {
      /* nothing */
    }
  }
  else
  {
    /* nothing */
  }
  

  /* ********** Draw low speed symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(    (pRteOut->pHlaf_HeadlightControl->Common.SpeedState & RTE_HLAF_SPEEDSTATE_TOO_LOW)
      || (testSymbols == 1)
      )
    {
      /* low speed */
      drawRGBimageInFrame(IDR_IMAGE_MIN_SPEED, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else
    {
      /* nothing */
    }
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw brightness symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(    (pRteOut->pHlaf_HeadlightControl->Common.BrightnessState == RTE_HLAR_BRT_DAY)
        || (testSymbols == 1)
      )
    {
      /* sunshine */
      drawRGBimageInFrame(IDR_IMAGE_DAYLIGHT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if(pRteOut->pHlaf_HeadlightControl->Common.BrightnessState == RTE_HLAR_BRT_TWLGT_1)
    {
      /* twilight 1 */
      drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_1, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.BrightnessState == RTE_HLAR_BRT_TWLGT_2)
    {
      /* twilight 2 */
      drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_2, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.BrightnessState == RTE_HLAR_BRT_TWLGT_3)
    {
      /* twilight 3 */
      drawRGBimageInFrame(IDR_IMAGE_TWILIGHT_3, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.BrightnessState == RTE_HLAR_BRT_NIGHT)
    {
      /* nothing */
    }
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw city symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(   (pRteOut->pHlaf_HeadlightControl->Common.CityState == RTE_HLAR_CITY_DTCD)
       || (testSymbols == 1)
      )
    {
      /* city */
      drawRGBimageInFrame(IDR_IMAGE_CITY_DTCT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else
    {
      /* nothing */
    }
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw bad weather symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(    (pRteOut->pHlaf_HeadlightControl->Common.WeatherState == RTE_HLAR_WEATHER_BAD)
      || (testSymbols == 1)
      )
    {
      /* rain cloud */
      drawRGBimageInFrame(IDR_IMAGE_BAD_WEATHER, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else
    {
      /* nothing */
    }

  }
  else
  {
    /* nothing */
  }


  /* ********** Draw highway symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(    (pRteOut->pHlaf_HeadlightControl->Common.MotorwayState == RTE_HLAF_MTWY_UNKNOWN)
      || (testSymbols == 1)
      )
    {
      /* highway with question mark */
      drawRGBimageInFrame(IDR_IMAGE_HIGHWAY_IDLE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.MotorwayState == RTE_HLAF_MTWY_COUNTRY)
    {
      /* nothing */
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.MotorwayState == RTE_HLAF_MTWY_MOTORWAY)
    {
      /* highway */
      drawRGBimageInFrame(IDR_IMAGE_HIGHWAY_DTCT, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
  }
  else
  {
    /* nothing */
  }
  

  /* ********** Draw tunnel symbol ********** */
  if (    (pRteOut != NULL) 
       && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(     (pRteOut->pHlaf_HeadlightControl->Common.TunnelState == RTE_HLAR_TUNNEL_UPFRONT)
      ||  (testSymbols == 1)
      )  
    {
      /* tunnel with arrow */
      drawRGBimageInFrame(IDR_IMAGE_TUNNEL_AHEAD, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.TunnelState == RTE_HLAR_TUNNEL_INSIDE)
    {
      /* tunnel */
      drawRGBimageInFrame(IDR_IMAGE_TUNNEL_INSIDE, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else
    {
      /* nothing */
    }
  }
  else
  {
    /* nothing */
  }


  /* ********** Draw traffic style symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(    (pRteOut->pHlaf_HeadlightControl->Common.TrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHT)
      || (testSymbols == 1)
      )
    {
      /* left hand traffic */
      drawRGBimageInFrame(IDR_IMAGE_LHT_TRAFFIC, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    else if (pRteOut->pHlaf_HeadlightControl->Common.TrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHT)
    {
      /* right hand traffic */
      drawRGBimageInFrame(IDR_IMAGE_RHT_TRAFFIC, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw US sensitivity symbol ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(   (pRteOut->pHlaf_HeadlightControl->Common.SensMode == RTE_HLA_SENSMODE_US)
       || (testSymbols == 1)
      )
    {
      /* US sensitivity icon */
      drawRGBimageInFrame(IDR_IMAGE_MERICA, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
    /* rest of world has nothing */
  }
  else
  {
    /* nothing */
  }

  /* ********** Draw turn off reason error ********** */
  if (   (pRteOut != NULL) 
      && (pRteOut->pHlaf_HeadlightControl != NULL)
    )
  {
    if(    (pRteOut->pHlaf_HeadlightControl->Matrix.TurnOffReason & RTE_HLAF_TURNOFFREASON_ERROR)
        || (testSymbols == 1)
      )
    {
      drawRGBimageInFrame(IDR_IMAGE_TURNOFF_ERROR, xpos, ypos, symbol_size, symbol_size, border_size, color, true);
      ypos += symbol_size + symbol_gap;
    }
  }
  else
  {
    /* nothing */
  }
}