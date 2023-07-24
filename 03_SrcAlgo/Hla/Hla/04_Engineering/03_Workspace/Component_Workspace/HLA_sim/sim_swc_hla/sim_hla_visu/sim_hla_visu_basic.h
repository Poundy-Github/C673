/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_basic.h

  DESCRIPTION:            Draw general things like ROIs, horizon, odometer, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.3 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_BASIC_H
#define SIM_HLA_VISU_BASIC_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"

#include "sim_visu_type.h"
#include "sim_hla_visu_head.h"

#include "sim_hla_visu_table.h"
#include "sim_hla_visu_utils.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class CSimHlaVisuBasic
  :public virtual CSimHlaVisuHead,
   public virtual CSimHlaVisuUtils
{
public:
  CSimHlaVisuBasic(void);
  ~CSimHlaVisuBasic(void);

  /* basic init */
  void Init();

  /* draw functions */
  void drawBasic( const ISimRenderContext*   pContext,
                        CSimVisuSubMenu*     pSubMenu,
                        CSimVisuSubMenu*     pSubMenuPlanes,
                        int&                 textPosX,
                        int                  textPosY
                );

  /* most important stuff from old visu */
  /* ROI drawing function */
  void drawROI( const ISimRenderContext*  pContext );

  /* Horizon drawing function */
  void drawHorizon( const ISimRenderContext*  pContext );

  /* Distance bars drawing function*/
  void drawDistBars( const ISimRenderContext*  pContext );

  /* Vehicle dynamics drawing function */
  void drawVDyn(const ISimRenderContext*      pContext,
                const reqHlaPrtList_t*        pRTEin,
                      int&                    textPosX,
                      int                     textPosY,
                const color_e                 color
                );

  /* Odometer statistics drawing function */
  void drawOdometer( const ISimRenderContext*  pContext,
                     const int                 textPosY,
                           int&                textPosX
                    );

  void draw2EntityVersion( const ISimRenderContext*  pContext );

  void draw2EntityVersionVis(const ISimRenderContext*  pContext,
                             const SimHlaProPrtList_t* pRteOut_MCU
                             );

private:
  void draw2VersionString(IGDVFont&   font,
                          int         posx,
                          int         posy,
                          uint32      versionNumber
                          );

  /* Odometer */
  float32 m_OdometerTurnOffDLL;
  float32 m_OdometerTurnOffECU;
  uint32  m_frameCounter;
};

#endif //SIM_HLA_VISU_BASIC_H
