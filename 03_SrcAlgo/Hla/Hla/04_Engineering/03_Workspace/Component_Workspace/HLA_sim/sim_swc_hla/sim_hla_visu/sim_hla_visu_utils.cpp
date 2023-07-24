#include "stdafx.h"
#include "resource.h"

#include <string>
#include <cmath>

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#include "sim_hla_visu_utils.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")



/* Shape class functions */

CSimHlaVisuUtils::CSimHlaVisuUtils(void)
{
}

CSimHlaVisuUtils::~CSimHlaVisuUtils(void)
{
}

/* draw a filled rectangle at specified coordinates */
void CSimHlaVisuUtils::drawFilledRect( const int x1,
                                       const int y1,
                                       const int x2,
                                       const int y2
                                      )
{
  glBegin(GL_QUADS);
  {
    glVertex3i(x1, y1, 1);
    glVertex3i(x1, y2, 1);
    glVertex3i(x2, y2, 1);
    glVertex3i(x2, y1, 1);
  }
  glEnd();
}

/* draw a rectangle at specified coordinates */
void CSimHlaVisuUtils::drawRect( const int x1,
                                 const int y1,
                                 const int x2,
                                 const int y2
                                )
{
  const float32 x1Draw = (float32)x1;
  const float32 x2Draw = (float32)x2 + DXY2;
  const float32 y1Draw = (float32)y1;
  const float32 y2Draw = (float32)y2 + DXY2;
  glBegin(GL_LINES);
  {
    glVertex3f(x1Draw, y1Draw, 1);
    glVertex3f(x1Draw, y2Draw, 1);

    glVertex3f(x1Draw, y2Draw, 1);
    glVertex3f(x2Draw, y2Draw, 1);

    glVertex3f(x2Draw, y2Draw, 1);
    glVertex3f(x2Draw, y1Draw, 1);

    glVertex3f(x2Draw, y1Draw, 1);
    glVertex3f(x1Draw, y1Draw, 1);
  }
  glEnd();
}


/* draw a filled rectangle at specified coordinates */
void CSimHlaVisuUtils::drawFilledRectf( const float x1,
                                        const float y1,
                                        const float x2,
                                        const float y2
                                       )
{
  glBegin(GL_QUADS);
  {
    glVertex3f(x1, y1, 1);
    glVertex3f(x1, y2, 1);
    glVertex3f(x2, y2, 1);
    glVertex3f(x2, y1, 1);
  }
  glEnd();
}

/* draw a rectangle at specified coordinates */
void CSimHlaVisuUtils::drawRectf( const float x1,
                                  const float y1,
                                  const float x2,
                                  const float y2
                                 )
{
  glBegin(GL_LINES);
  {
    glVertex3f(x1, y1, 1);
    glVertex3f(x1, y2, 1);

    glVertex3f(x1, y2, 1);
    glVertex3f(x2, y2, 1);

    glVertex3f(x2, y2, 1);
    glVertex3f(x2, y1, 1);

    glVertex3f(x2, y1, 1);
    glVertex3f(x1, y1, 1);
  }
  glEnd();
}

void CSimHlaVisuUtils::drawMarker( const int x,
                                   const int y,
                                   const int size,
                                   const int markerType,
                                   const int drawPlane
                                  )
{
  int delta_x, delta_y;

  switch (markerType)
  {
  case HLA_UTILS_DRAW_PLUS:
    /* draw a + on the screen */
    glBegin(GL_LINES);
    {
      glVertex3i(x             , y - (size    ), drawPlane);
      glVertex3i(x             , y + (size + 1), drawPlane);
      glVertex3i(x - (size    ), y             , drawPlane);
      glVertex3i(x + (size + 1), y             , drawPlane);
    }
    glEnd();
    break;
  case HLA_UTILS_DRAW_CROSS:
    /* draw a x on the screen */
    glBegin(GL_LINES);
    {
      glVertex3i(x - (size    ), y - (size    ), drawPlane);
      glVertex3i(x + (size + 1), y + (size + 1), drawPlane);
      glVertex3i(x - (size    ), y + (size    ), drawPlane);
      glVertex3i(x + (size + 1), y - (size + 1), drawPlane);
    }
    glEnd();
    break;
  case HLA_UTILS_DRAW_SQUARE:
    glBegin(GL_LINE_LOOP);
    {
      glVertex3i(x - size, y - size, drawPlane);
      glVertex3i(x + size, y - size, drawPlane);
      glVertex3i(x + size, y + size, drawPlane);
      glVertex3i(x - size, y + size, drawPlane);
    }
    glEnd();
    break;
  case HLA_UTILS_DRAW_TRIANGLE:
    delta_y = (int)(size / tan(CML_Deg2Rad(30))) + 1;
    delta_x = (int)((size + delta_y) * tan(CML_Deg2Rad(30)));

    glBegin(GL_LINE_LOOP);
    {
      glVertex3i(x          , y - delta_y   , drawPlane);
      glVertex3i(x + delta_x, y + (size + 1), drawPlane);
      glVertex3i(x - delta_x, y + (size + 1), drawPlane);
    }
    glEnd();
    break;
  case HLA_UTILS_DRAW_DIAMOND:
    glBegin(GL_LINE_LOOP);
    {
      glVertex3i(x       , y - size, drawPlane);
      glVertex3i(x + size, y       , drawPlane);
      glVertex3i(x       , y + size, drawPlane);
      glVertex3i(x - size, y       , drawPlane);
    }
    glEnd();
    break;
  }
  glLineWidth(1);
}

/* Text class functions */
void CSimHlaVisuUtils::drawBitField( const char*     pTxtOut,
                                     const uint32    Status,
                                           IGDVFont& font,
                                     const int       textPosX,
                                     const int       textPosY
                                    )
{
  if(Status)
  {
    SetTextColor(color_red, font);
    font.RenderTextf(textPosX, textPosY, 1, "%s:", pTxtOut);
    font.RenderTextf(textPosX+150, textPosY, 1, "1"); 
  }
  else
  {
    SetTextColor(color_yellow, font);
    font.RenderTextf(textPosX, textPosY, 1, "%s", pTxtOut);
    font.RenderTextf(textPosX+150, textPosY, 1, "0");
  }
}

void CSimHlaVisuUtils::drawBitField( const char*              pTxtOut,
                                     const uint32             Status,
                                     const ISimRenderContext* pContext,
                                           CSimTable          &cTable,
                                     const uint16             row
                                    )
{
  if(Status)
  {
    cTable.SetRow<char*>(row, color_red, pTxtOut, "1");
  }
  else
  {
    cTable.SetRow<char*>(row, color_yellow, pTxtOut, "0");
  }
}

/* create false color map */
void CSimHlaVisuUtils::falseColor(float32 val4color)
{
  float32 logLux      = log(val4color + 1);
  float32 level_size  = 1.316f; /* max @ logLux = 9.212 => Lux = 10016,61 */
  float32 slot        = CML_f_Min((logLux / level_size), 7.0f);

  float32 r           = 0.0f; 
  float32 g           = 0.0f;
  float32 b           = 0.0f;
  float32 temp        = 0.0f;

  if(slot >= 0.0f && slot <= 1.0f)
  {
    /* black to blue */
    r = 0.0f;
    g = 0.0f;
    b = slot; 
  }
  else if (slot > 1.0f && slot <= 2.0f)
  {
    r = 0.0f;
    g = (slot - 1.0f);
    b = 1.0;
  }
  else if (slot > 2.0f && slot <= 3.0f)
  {
    r = 0.0f;
    g = 1.0f;
    b = 3.0f - slot;
  }
  else if (slot > 3.0f && slot <= 4.0f)
  {
    r = (slot - 3.0f);
    g = 1.0f;
    b = 0.0f;
  }
  else if (slot > 4.0f && slot <= 5.0f)
  {
    r = 1.0f;
    g = (5.0f - slot);
    b = 0.0f;
  }
  else if (slot > 5.0f && slot <= 6.0f)
  {
    r = 1.0f;
    g = 0.0f;
    b = (slot - 5.0f);
  }
  else if (slot > 6.0f) /* && slot <= 7.0f) */
  {
    r = 1.0f;
    g = (slot - 6.0f);
    b = 1.0f;
  }

  glColor3f(r,g,b);
}
