/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu.h

  DESCRIPTION:            Native SimDraw openGl visualization overlays including
                          support for mouse and keyboard interaction

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.7 $

  ---*/ /*---

**************************************************************************** */

#ifndef SIM_HLA_VISU_H
#define SIM_HLA_VISU_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"

#include "sim_hla_visu_head.h"

#include "sim_hla_visu_hlaf.h"
#include "sim_hla_visu_turnoff.h"
#include "sim_hla_visu_labels.h"
#include "sim_hla_visu_basic.h"
#include "sim_hla_visu_error.h"
#include "sim_hla_visu_interface.h"

#include "sim_visu_type.h"
#include "hla_evm_hil_ports.h"

#include "hlaf_type.h"

#include "sim_visu_menu.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

#define ROI_MIN  60

class CSimHlaVisu
  : public CSimHlaVisuBasic,
    public CSimHlaVisuError,
    public CSimHlaVisuHlaf,
    public CSimHlaVisuTurnoff,
    public CSimVisuMenu,
    public CSimHlaVisuLabels,
    public CSimHlaVisuInt
  /*: CSimHlaVisuHlaf,
    CSimHlaVisuError,
    CSimHlaVisuTurnoff,
    CSimHlaVisuBasic,
    CSimHlaVisuEnv,
    CSimHlaVisuSeg,
    CSimHlaVisuSegColor,
    CSimHlaVisuTracking*/
{
public:
  CSimHlaVisu(      CSimSwcBase*      pSimPlgBase,
              const char*             recFileName,
                    SimHlaMeasdata_t* phlaMeasdata,
              const unsigned __int64* timestamp
             );
  ~CSimHlaVisu();

  bool OnMouseMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage);
  bool OnKeyboardMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage);  
  bool OnWindowMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage);

  void Init(void);
  void DrawFunction1(const ISimRenderContext* pContext);
  void DrawFunction2(const ISimRenderContext* pContext);
  unsigned __int64 getLastDrawnTimestamp() { return m_lastDrawnTimestamp; }

private:
  void InitRoi();
  /* call draw functions */
  void drawGeneral(const ISimRenderContext*  pContext);

  /* DrawFunction2 */
  void draw2MatrixTurnOffReasonHBState( const ISimRenderContext*                  pContext );


  /* DrawFunction1 */
  void drawFunctionSymbols( const ISimRenderContext*  pContext,
                            const SimHlaProPrtList_t* pRteOut_SIL,
                            const SimHlaProPrtList_t* pRteOut_MCU,
                            const reqHlaPrtList_t*    pRteIn_SIL,
                            const reqHlaPrtList_t*    pRteIn_MCU
                          );

  void updateLockedObjects();

  void updateRois();

  void drawMouseStatus(const ISimRenderContext* pContext);

  void checkActivatedPlanes( int i, CSimVisuSubMenu* planes, int* activePlane );

  void checkErrorList( CSimVisuSubMenu* errorList, int* activeErrorList );

  void SetupMenu();

  void DefaultMenuActivation();

  CSimSwcBase* m_pSimPlgBase;

  const char*             m_recFileName;
  unsigned __int64        m_lastDrawnTimestamp;

  const unsigned __int64* m_currentTimstamp;
  sint8  m_redrawCounter;

  /* algo was executed since last visu execution */
  bool m_bAlgoWasExecuted;
  uint32 m_HlaMeasurementCounterPreviousCycle;

  CSimVisuSubMenu m_function;
  CSimVisuSubMenu m_diagnosis;
  CSimVisuSubMenu m_interfaces;
  CSimVisuSubMenu m_general;
  CSimVisuSubMenu m_planes;

  int m_updatedMenu;

  struct s_labelTool
  {
    std::string oldRecFilename;
    int labelMode;
    int labelGroup;
    int labelClass;
  } m_labelTool;
};

#endif // SIM_HLA_VISU_H
