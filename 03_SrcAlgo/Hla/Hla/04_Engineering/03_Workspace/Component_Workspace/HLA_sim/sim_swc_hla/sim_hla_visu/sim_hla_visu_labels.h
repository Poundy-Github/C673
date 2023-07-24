/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_labels.h

  DESCRIPTION:            Drawing of database labels

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_LABELS_H
#define SIM_HLA_VISU_LABELS_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"
#include "sim_hla_visu_head.h"
#include "sim_visu_menusub.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class CSimHlaVisuLabels
  :public virtual CSimHlaVisuHead
{
public:
  CSimHlaVisuLabels();

  ~CSimHlaVisuLabels();

  void Init();
  
  void CSimHlaVisuLabels::drawLabelOverlay(const ISimRenderContext*  pContext,
                                           const unsigned __int64*   uiTimeStamp,
                                                 int                 textPosX,
                                                 int                 textPosY,
                                                 CSimVisuSubMenu*    pInterfacesMenu 
                                          );

private:
  void drawCarLightLabelDB( const ISimRenderContext*  pContext,
                            const unsigned __int64*   uiTimeStamp,
                                  uint32              textPosX,
                                  uint32              textLine,
                                  uint32              textHeight
                          );

  void drawHLALabelDB(const ISimRenderContext*  pContext,
                      const unsigned __int64*   uiTimeStamp,
                            unsigned int        imagetype,
                            uint32              textPosX,
                            uint32              textLine,
                            uint32              textHeight
                    );

  void drawHighwayLabelDB(const ISimRenderContext*  pContext,
                          const unsigned __int64*   uiTimeStamp,
                                uint32              textPosX,
                                uint32              textLine,
                                uint32              textHeight
                        );

  void drawCityLabelDB( const ISimRenderContext*  pContext,
                              const unsigned __int64*   uiTimeStamp,
                                    uint32              textPosX,
                                    uint32              textLine,
                                    uint32              textHeight
                       );

};

#endif // SIM_HLA_VISU_LABELS_H
