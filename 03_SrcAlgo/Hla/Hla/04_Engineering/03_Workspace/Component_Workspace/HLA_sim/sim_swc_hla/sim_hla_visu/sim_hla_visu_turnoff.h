/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_turnoff.h

  DESCRIPTION:            Draw general things like turnoff reasons

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.7 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_TURNOFF_H
#define SIM_HLA_VISU_TURNOFF_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"

#include "hla_defs.h"

#include "hlaf_type.h"
#include "hlaf_matrix.h"

#include "sim_visu_type.h"
#include "sim_hla_visu_head.h"
#include "sim_visu_color.h"
#include "sim_hla_visu_utils.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class CSimHlaVisuTurnoff
  :public virtual CSimHlaVisuHead,
   public virtual CSimHlaVisuUtils
{
public:
  CSimHlaVisuTurnoff();

  ~CSimHlaVisuTurnoff();

  void Init();

  void draw2HeadlightStateRequest( const ISimRenderContext*     pContext,
                                         CSimVisuSubMenu*       pMenu,
                                   const uint16                 menuWidth = 0
                                 );

  void draw2HeadlightStateRequestVis( const ISimRenderContext*     pContext,
                                      const reqHlaPrtList_t*       pRteIn_MCU,
                                      const reqHlaPrtList_t*       pRteIn_CAN,
                                      const reqHlaPrtList_t*       pRteIn_ENET,
                                      const SimHlaProPrtList_t*    pRteOut_SIL,
                                      const SimHlaProPrtList_t*    pRteOut_MCU,
                                            boolean                drawBig = false 
                                    );

  void draw2MatrixTurnOffReasonHBStateDraw( const ISimRenderContext*                  pContext,
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
                                            );

  void draw2MatrixTurnOffReasonHBStateDrawVis(const ISimRenderContext*                  pContext,
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
                                              );

  void drawFunctionSymbolsDraw( const SimHlaProPrtList_t* pRteOut,
                                const uint8               testSymbols,
                                const color_e             color,
                                const int                 xpos,
                                      int                 ypos,
                                const int                 symbol_size, 
                                const int                 border_size, 
                                const int                 symbol_gap
                                );


private:
  void draw2HeadlightStateIcon (const RTE_HLAF_HighBeamState  eHighBeamState,
                                      int                     posx,
                                      int                     posy,
                                      float                   r,
                                const color_e                 headlightColor,
                                const color_e                 statusColor,
                                      float                   alpha = 1.0f
                                );

  void drawRGBimageInFrame( const unsigned long resourceID, 
                            const int           x, 
                            const int           y, 
                            const int           width, 
                            const int           height, 
                            const int           border_size, 
                            const color_e       color,
                            const bool          withFrame = false
                            );
  void drawSwitchOfFrame( const int           x, 
                          const int           y, 
                          const int           width, 
                          const int           height, 
                          const int           border_size
                          );

  void drawRGBimage(const unsigned long resourceID,
                    const int           x, 
                    const int           y,
                    const int           width,
                    const int           height
                  );
 
};

#endif // SIM_HLA_VISU_TURNOFF_H
