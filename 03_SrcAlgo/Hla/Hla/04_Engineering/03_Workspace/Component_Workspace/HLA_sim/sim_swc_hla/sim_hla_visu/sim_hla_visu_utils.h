/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_utils.h

  DESCRIPTION:            Providing basic tools like drawing rectangles, crosses, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.3 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_UTILS_H
#define SIM_HLA_VISU_UTILS_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"
#include "sim_hla_visu_table.h"

#include "sim_visu_type.h"
#include "sim_hla_visu_head.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

/* define marker types */
#define HLA_UTILS_DRAW_PLUS     0u
#define HLA_UTILS_DRAW_CROSS    1u
#define HLA_UTILS_DRAW_SQUARE   2u
#define HLA_UTILS_DRAW_TRIANGLE 3u
#define HLA_UTILS_DRAW_DIAMOND  4u

class CSimHlaVisuUtils
  :public virtual CSimHlaVisuHead,
   public CSimFont
{
public:
  CSimHlaVisuUtils(void);
  ~CSimHlaVisuUtils(void);

  void drawFilledRect( const int x1,
                       const int y1,
                       const int x2,
                       const int y2
                      );

  void drawRect( const int x1,
                 const int y1,
                 const int x2,
                 const int y2
                );

  void drawFilledRectf( const float x1,
                        const float y1,
                        const float x2,
                        const float y2
                       );

  void drawRectf( const float x1,
                  const float y1,
                  const float x2,
                  const float y2
                 );

  void drawMarker( const int x,
                   const int y,
                   const int size,
                   const int markerType,
                   const int drawPlane = 1
                  );

  void drawZoomedIcon( const uint8*  pDat,
                       const uint16  wndX,
                       const uint16  wndY,
                       const uint16  scale,
                       const color_e color,
                       const uint8*  pDatSeg = NULL
                      );

  void drawBitField( const char*     pTxtOut,
                     const uint32    Status,
                           IGDVFont& font,
                     const int       textPosX,
                     const int       textPosY
                    );

  void drawBitField( const char*              pTxtOut,
                     const uint32             Status,
                     const ISimRenderContext* pContext,
                           CSimTable          &cTable,
                     const uint16             row
                    );

  void falseColor(float32 val4color);
};
#endif // SIM_HLA_VISU_UTILS_H