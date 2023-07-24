/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_env.h

  DESCRIPTION:            Drawing of environment data like city, highway, tunnel, etc.

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.3 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_INT_H
#define SIM_HLA_VISU_INT_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"

#include "hla_defs.h"

#include "sim_hla_visu_head.h"
#include "sim_hla_visu_utils.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class CSimHlaVisuInt
  :public virtual CSimHlaVisuHead,
   public virtual CSimHlaVisuUtils
{
public:
  CSimHlaVisuInt(void);
  ~CSimHlaVisuInt(void);

  void drawInterface( const ISimRenderContext*  pContext,
                            CSimVisuSubMenu* pInterfacesMenu
                    );

  /* Bright object detection visualization */
  void drawDimming( const ISimRenderContext*  pContext,
                          const reqHlaPrtList_t*    rteInputs,
                          const SimHlaProPrtList_t* rteOutputs,
                          const color_e             color
                        );

  void drawDimmingDetails( const ISimRenderContext*  pContext,
                                 const reqHlaPrtList_t*    m_rteInputs,
                                 const SimHlaProPrtList_t* m_rteOutputs,
                                 const color_e             color,
                                 const unsigned int        index
                               );

  void drawEMObjects( const ISimRenderContext*        pContext,
                      const EM_t_GenObjectList*       pEMObjectsList
                     );
  void getEMObjectsType( const EM_t_GenObject* pEMObject,
                               string*         pEMObjectInfo
                        );
  void getEMObjectsDynProperty( const EM_t_GenObject* pEMObject,
                                      string*         pEMObjectInfo
                               );
};
#endif //SIM_HLA_VISU_INT_H
