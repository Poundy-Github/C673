/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_hlaf.h

  DESCRIPTION:            Drawing of interfaces for hlaf and hlar

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.8 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_HLAF_H
#define SIM_HLA_VISU_HLAF_H

#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"

#include "hla_defs.h"

#include "hlaf_type.h"
#include "hlaf_matrix.h"

#include "sim_visu_type.h"
#include "sim_hla_visu_head.h"
#include "sim_hla_visu_utils.h"

#include "sim_hla_visu_table.h"

#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class CSimHlaVisuHlaf 
  :public virtual CSimHlaVisuHead,
   public virtual CSimHlaVisuUtils
{
public:
  CSimHlaVisuHlaf();
  ~CSimHlaVisuHlaf();

  void drawHLAF(const ISimRenderContext*  pContext, CSimVisuSubMenu* pInterfaces, CSimVisuSubMenu* pFunction);

  void drawHLAFInfo( const ISimRenderContext*  pContext,
                           CSimVisuSubMenu*    pInterfacesMenu,
                           CSimVisuSubMenu*    pFunctionMenu,
                           int&                textPosX
                   );

  void Init();

  /* draw all GFAs into image */
  void CSimHlaVisuHlaf::drawGFAs( const ISimRenderContext*    pContext,
                                        boolean               bDrawAng,
                                  const reqHlaPrtList_t*      pRTEin,
                                  const RTE_HLAF_MatrixGFA_t* pGFA,
                                  const uint32                nGFA,
                                  const color_e               color,
                                        float32               alpha,
                                        sint16                drawOffsetX = 0,
                                        sint16                drawOffsetY = 0
                              );

  void drawHLAFOutput(const ISimRenderContext*  pContext,
                      const SimHlaProPrtList_t* pRTEout,
                      const color_e             color,
                            int&                textPosX
                      );

  void getHLABrightnessStateTxt(const uint8 BrightnessState, 
                                      char* pTxtOut
                                );
  void getHLASensModeTxt( const uint8 SensMode, 
                                char* pTxtOut
                         );

  void getHLASceneInfoTxt( const uint8 SceneInfo, 
                                  char* pTxtOut
                         );

  void getHLASpeedStateTxt( const uint32 Status, 
                                  char*  pTxtOut
                          );

  void drawLsdInputInterface( const ISimRenderContext*  pContext,
                              const reqHlaPrtList_t*    pRteInputs,
                              const color_e             color,
                                    HLAFData_t*         pHlafData,
                                    uint8               drawPlane = 1,
                                    uint8               planesToDraw = 1,
                                    sint16              drawOffsetX = 0,
                                    sint16              drawOffsetY = 0
                            );

  void drawLsdLightSize( const ISimRenderContext*  pContext,
                         const reqHlaPrtList_t*    pRteInputs,
                         const color_e             color,
                         sint16              drawOffsetX = 0,
                         sint16              drawOffsetY = 0 
                       );

  void drawOutputInterfaceInfo( const ISimRenderContext*  pContext,
                                const reqHlaPrtList_t*    pRteInputs,
                                      int                 &infoPosX,
                                      sint16              drawOffsetX = 0,
                                      sint16              drawOffsetY = 0
                                );

  void drawObjectOutputListText( const LSD_LightObject_t&  hlaObject,
                                 const ISimRenderContext*  pContext,
                                       int&                textPosX
                                );

  void drawObjectOutputPopUp( const ISimRenderContext*  pContext,
                              const LSD_LightObject_t&  lsdObject,                                                         
                                    int                 textPosX,
                                    int&                textPosY
                            );

  void drawInputInterface(const ISimRenderContext*  pContext,
                          const reqHlaPrtList_t*    pRTEin,
                          const color_e             color,
                                float32             alpha,
                                sint16              drawOffsetX = 0,
                                sint16              drawOffsetY = 0
                          );

  void drawInputInterfaceDetailsText( const ISimRenderContext* pContext,
                                      const reqHlaPrtList_t*   pRTEin,
                                            int&               textPosX
                                    );

  void getHLAHighBeamStateTxt(const uint8 HighBeamState, 
                                    char* pTxtOut
                              );

  void drawHLAFMatrix(const ISimRenderContext*  pContext,
                      const reqHlaPrtList_t*    pRteInputs,
                      const SimHlaProPrtList_t* pRteOutputs,
                            int&                textPosX
                      );

  void getHLAFSignalStatusTxt(const uint32  Status, 
                                    char*   pTxtOut
                              );

  void getHLAFMatrixObjStatusTxt( const uint32 Status, 
                                        char*  pTxtOut
                                );

  void getHLAFMatrixDistStateTxt(const uint32 Status, 
                                       char*  pTxtOut
                                 );

  void getHLAFMatrixTTB18StatusTxt(const uint32 Status, 
                                         char*   pTxtOut
                                   );

  void drawHLAF_Bar(const int     PosX, 
                    const int     PosY,
                    const int     Height,
                    const int     Length,
                    const float   FillPercentage, 
                    const color_e color
                  );
  /* Turn off reason */
  void drawHLAFTurnOffReason( const ISimRenderContext*       pContext,
                              const HLAFTurnOffReason_t*     pTurnOffReason,
                                    int*                     pTextPosX,
                              const int                      textPosY
                            );

  /* Keep off reason */
  void drawHLAFKeepOffReason( const ISimRenderContext*          pContext,
                                    const HLAFKeepOffReason_t*  pKeepOffReason,
                                    const int                   textPosX,
                                    const int                   textPosY
                                  );

  void drawHLAFHBData( const ISimRenderContext* const pContext,
                       const HLAFData_t*        const pHlafData
                     );

  const LSD_LightObject_t* getCorrespodingLightObject( const HLAObjectDataInt_t*    pInternalHLAOBject,
                                                       const HLAFData_t*            pHlafData,
                                                       const LSD_LightObjectList_t* pLsdLightObjectList
                                                      );

  //  void drawEMObjects( const ISimRenderContext*        pContext,
  //                      const EM_t_GenObjectList*       pEMObjectsList
  //                    );

  //void getEMObjectsType( const EM_t_GenObject* pEMObject,
  //                             string*         pEMObjectInfo
  //                     );

  //void getEMObjectsDynProperty( const EM_t_GenObject* pEMObject,
  //                                    string*         pEMObjectInfo
  //                            );

private:

};

#endif // SIM_HLA_VISU_HLAF_H
