/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu.cpp

  DESCRIPTION:            Native SimDraw openGl visualization overlays including
                          support for mouse and keyboard interaction

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.10 $

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
  #include "hla_utils.h"
#ifdef __cplusplus
}
#endif

#include "sim_hla_visu.h"
#include <string>
#include <cmath>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")

/* Odometer */
static float32 OdometerTurnOffDLL_m = 0.0f;
static float32 OdometerTurnOffECU_m = 0.0f;
static uint32  frameCounter = 0;

CSimHlaVisu::CSimHlaVisu(      CSimSwcBase*      pSimPlgBase,
                         const char*             recFileName,
                               SimHlaMeasdata_t* phlaMeasdata,
                         const unsigned __int64* timestamp
                        )
: CSimVisuMenu(56, 216 ),
  m_pSimPlgBase(pSimPlgBase),
  m_recFileName(recFileName),
  m_lastDrawnTimestamp(0),
  m_currentTimstamp(timestamp),
  m_redrawCounter(0),
  m_updatedMenu(0),
  m_HlaMeasurementCounterPreviousCycle(0),
  /* menu buttons */
  m_function    ("[F]unction"   ),
  m_diagnosis   ("[D]iagnosis"  ), 
  m_interfaces  ("[I]nterfaces" ), 
  m_general     ("[G]eneral"    ), 
  m_planes      ("[P]lanes"     )
{

  pm_hlaInternMeasdata = &(phlaMeasdata[VISU_SIL].hlaInternMeasdata); 
  pm_rteInputs =        (const reqHlaPrtList_t*)&(phlaMeasdata[VISU_SIL].ReqPorts);
  pm_rteOutputs =       (const SimHlaProPrtList_t*)&(phlaMeasdata[VISU_SIL].ProPorts);
  pm_hlaMeasdata = phlaMeasdata;
  m_drawPlane = 0;
  m_drawColor = color_sil;

  memset(&m_keyboardInfo, 0, sizeof(m_keyboardInfo));
  memset(&m_mouseInfo, 0, sizeof(m_mouseInfo));

  memset(&m_lockedObjects, 0, sizeof(m_lockedObjects));
  m_lockedObjects.trackList   = std::vector<LockedTrackListItem>();
  m_lockedObjects.objectList  = std::vector<LockedObjectListItem>();

  m_labelTool.labelMode       = 0;
  m_labelTool.labelGroup      = 0;
  m_labelTool.labelClass      = 0;

  InitRoi();

  /* Init menu/buttons */
  SetupMenu();

  /* load old menu config */
  LoadVisuMenu("hla");

}

CSimHlaVisu::~CSimHlaVisu()
{
  SaveMenu("hla");
}

bool CSimHlaVisu::OnMouseMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
  ISimModifiableParameterMap& paramMap = context.GetSharedParameterMap();

  float xScale = CSimRenderParamHelper::GetParamByVal<float>(paramMap, "scaleX", 1.0F);
  float yScale = CSimRenderParamHelper::GetParamByVal<float>(paramMap, "scaleY", 1.0F);

  float imagePosX = CSimRenderParamHelper::GetParamByVal<float>(paramMap, "imagePosX", 0.0F);
  float imagePosY = CSimRenderParamHelper::GetParamByVal<float>(paramMap, "imagePosY", 0.0F);

  const int x = (int)CML_Round((LOWORD(windowMessage.GetLParam()) - imagePosX * xScale) / xScale);
  const int y = (int)CML_Round((HIWORD(windowMessage.GetLParam()) - imagePosY * yScale) / yScale);

  if (windowMessage.GetMessageId() == WM_LBUTTONDBLCLK)
  {
    m_mouseInfo.doubleClickLeft.count++;
    m_mouseInfo.doubleClickLeft.x = x;
    m_mouseInfo.doubleClickLeft.y = y;
  }
  if (windowMessage.GetMessageId() == WM_MBUTTONDOWN)
  {
    m_mouseInfo.singleClickMiddle.count++;
    m_mouseInfo.singleClickMiddle.x = x;
    m_mouseInfo.singleClickMiddle.y = y;

    m_mouseInfo.current.wheel = 0;
    m_mouseInfo.rect.eState = t_MouseInfo::s_rect::STATE_INVALID;
  }
  if (windowMessage.GetMessageId() == WM_MOUSEWHEEL)
  {
    m_mouseInfo.current.wheel += (GET_WHEEL_DELTA_WPARAM(windowMessage.GetWParam()) / WHEEL_DELTA);
  }
  if (windowMessage.GetMessageId() == WM_LBUTTONDOWN)
  {
    if (m_mouseInfo.rect.eState != t_MouseInfo::s_rect::STATE_FIRST_POINT_SET)
    {
      m_mouseInfo.rect.left = x;
      m_mouseInfo.rect.top = y;
      m_mouseInfo.rect.eState = t_MouseInfo::s_rect::STATE_FIRST_POINT_SET;
    }
    m_mouseInfo.singleClickLeft.tmpX = x;
    m_mouseInfo.singleClickLeft.tmpY = y;
  }
  if (windowMessage.GetMessageId() == WM_LBUTTONUP)
  {
    if (  (ABS(m_mouseInfo.singleClickLeft.tmpX - x) < 2)
        &&(ABS(m_mouseInfo.singleClickLeft.tmpY - y) < 2)
       )
    {
        m_mouseInfo.singleClickLeft.count++;
        m_mouseInfo.singleClickLeft.x = m_mouseInfo.singleClickLeft.tmpX;
        m_mouseInfo.singleClickLeft.y = m_mouseInfo.singleClickLeft.tmpY;
    }
    if (m_mouseInfo.rect.eState == t_MouseInfo::s_rect::STATE_FIRST_POINT_SET)
    {
      if (x < m_mouseInfo.rect.left)
      {
        m_mouseInfo.rect.right = m_mouseInfo.rect.left;
        m_mouseInfo.rect.left = x;
      }
      else
      {
        m_mouseInfo.rect.right = x;
      }

      if (y < m_mouseInfo.rect.top)
      {
        m_mouseInfo.rect.bottom = m_mouseInfo.rect.top;
        m_mouseInfo.rect.top = y;
      }
      else
      {
        m_mouseInfo.rect.bottom = y;
      }

      m_mouseInfo.rect.eState = t_MouseInfo::s_rect::STATE_VALID;
    }
  }

  switch (windowMessage.GetMessageId())
  {
  case WM_LBUTTONDOWN:
  case WM_MBUTTONDOWN:
  case WM_RBUTTONDOWN:
  case WM_LBUTTONUP:
  case WM_MBUTTONUP:
  case WM_RBUTTONUP:
  case WM_MOUSEMOVE:
  case WM_LBUTTONDBLCLK:
    m_mouseInfo.current.x = x;
    m_mouseInfo.current.y = y;
  case WM_MOUSEWHEEL:
    return true;
  }

  return false;

}

bool CSimHlaVisu::OnKeyboardMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
  if (windowMessage.GetMessageId() == WM_CHAR)
  {
    m_keyboardInfo.count++;
    m_keyboardInfo.character = (char)windowMessage.GetWParam();
  }

  switch (windowMessage.GetMessageId())
  {
  case WM_CHAR:
  case WM_HOTKEY:
  case WM_KEYDOWN:
  case WM_KEYUP:
    return true;
  }

  return false;
}

bool CSimHlaVisu::OnWindowMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
  return false;
}

void CSimHlaVisu::InitRoi()
{
  m_HLARoi.Width  = 864;
  m_HLARoi.Height = 344;
  m_HLARoi.X1     = 130 + m_DrawImageOffsetX;
  m_HLARoi.Y1     = 40  + m_DrawImageOffsetY;
  m_HLARoi.X2     = m_HLARoi.X1 + m_HLARoi.Width;
  m_HLARoi.Y2     = m_HLARoi.Y1 + m_HLARoi.Height;
  m_HLARoi.Yu     = 100 + m_DrawImageOffsetY;

  m_SilRoi.Width  = 864;
  m_SilRoi.Height = 344;
  m_SilRoi.X1     = 130 + m_DrawImageOffsetX;
  m_SilRoi.Y1     = 40 + m_DrawImageOffsetY;
  m_SilRoi.X2     = m_SilRoi.X1 + m_SilRoi.Width;
  m_SilRoi.Y2     = m_SilRoi.Y1 + m_SilRoi.Height;
  m_SilRoi.Yu     = 100 + m_DrawImageOffsetY;

  m_SilColorRoi.Width  = 1152;
  m_SilColorRoi.Height = 640;
  m_SilColorRoi.X1     = 80;
  m_SilColorRoi.Y1     = 0;
  m_SilColorRoi.X2     = m_SilColorRoi.X1 + m_SilColorRoi.Width;
  m_SilColorRoi.Y2     = m_SilColorRoi.Y1 + m_SilColorRoi.Height;
}

void CSimHlaVisu::SetupMenu()
{
  m_subMenuMap.push_back(&m_planes);
  m_subMenuMap.push_back(&m_interfaces);
  m_subMenuMap.push_back(&m_function);
  m_subMenuMap.push_back(&m_diagnosis);
  m_subMenuMap.push_back(&m_general);

  m_function.setItem(MENU_BUTTON_FUNC_OUTPUT);
  m_function.setItem(MENU_BUTTON_FUNC_MATRIX);
  m_function.setSubItem(MENU_BUTTON_FUNC_MATRIX_S_NONE);
  m_function.setSubItem(MENU_BUTTON_FUNC_MATRIX_S_CAM);
  m_function.setSubItem(MENU_BUTTON_FUNC_MATRIX_S_CAMANG);
  m_function.setItem(MENU_BUTTON_FUNC_HB_DATA);

  m_diagnosis.setItem(MENU_BUTTON_DIAG_TIMEMEAS);
  m_diagnosis.setItem(MENU_BUTTON_DIAG_HLSTATEREQ);
  m_diagnosis.setSubItem(MENU_BUTTON_DIAG_HLSTATEREQ_S_SMALL);
  m_diagnosis.setSubItem(MENU_BUTTON_DIAG_HLSTATEREQ_S_BIG);
  m_diagnosis.setSubItem(MENU_BUTTON_DIAG_HLSTATEREQ_S_ALL);  
  m_diagnosis.setItem(MENU_BUTTON_DIAG_DATABLABEL);

  m_interfaces.setItem(MENU_BUTTON_INTF_BUS);
  m_interfaces.setItem(MENU_BUTTON_INTF_LSD);
  m_interfaces.setItem(MENU_BUTTON_INTF_EMOBJECT);
  m_interfaces.setItem(MENU_BUTTON_INTF_DIMMING);
  m_interfaces.setItem(MENU_BUTTON_INTF_LIGHT_SIZE);

  m_general.setItem(MENU_BUTTON_GEN_ERRORLIST);
  m_general.setSubItem(MENU_BUTTON_GEN_ERRORLIST_S_NONE);
  m_general.setSubItem(MENU_BUTTON_GEN_ERRORLIST_S_ALL);
  m_general.setSubItem(MENU_BUTTON_GEN_ERRORLIST_S_NOINFO);
  m_general.setSubItem(MENU_BUTTON_GEN_ERRORLIST_S_NOWARN);
  m_general.setItem(MENU_BUTTON_GEN_HORIZON);
  m_general.setItem(MENU_BUTTON_GEN_ROI);
  m_general.setItem(MENU_BUTTON_GEN_VEHINFO);
  m_general.setItem(MENU_BUTTON_GEN_RESET);

  m_planes.setItem(MENU_BUTTON_PLANE_SIL);
  m_planes.setItem(MENU_BUTTON_PLANE_ECU);
  m_planes.setItem(MENU_BUTTON_PLANE_EVM);
  m_planes.setItem(MENU_BUTTON_PLANE_ETH);
  m_planes.setItem(MENU_BUTTON_PLANE_CAN);

  DefaultMenuActivation();
}

void CSimHlaVisu::DefaultMenuActivation()
{
  m_general.activateItem(MENU_BUTTON_GEN_ERRORLIST, MENU_BUTTON_GEN_ERRORLIST_S_ALL);
  m_general.activateItem(MENU_BUTTON_GEN_ROI);
  m_general.activateItem(MENU_BUTTON_GEN_VEHINFO);
  m_interfaces.activateItem(MENU_BUTTON_INTF_LSD);
  m_planes.activateItem(MENU_BUTTON_PLANE_SIL); 
}

void CSimHlaVisu::Init(void)
{
  m_labelTool.labelMode = 0;

  CSimHlaVisuBasic::Init();

  CSimHlaVisuError::Init();
}

void CSimHlaVisu::DrawFunction1(const ISimRenderContext* pContext)
{
  bool somethingToDraw = false;
  IGDVFont& font = pContext->GetWindow().GetFontInterface("", 10);

  glTranslatef(0.375f, 0.375f, 0.0f);
  glEnable(GL_BLEND); 
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  pm_hlaInternMeasdata = &(pm_hlaMeasdata[VISU_SIL].hlaInternMeasdata);

  /* draw general information and recalculate some member variables */
  drawGeneral(pContext);

  int textPosX = m_HLARoi.X1 + 5 + 75;
  int textPosY = m_HLARoi.Y2 + 5;
    
  /* draw basic */
  drawBasic( pContext,
             &m_general,
             &m_planes,
             textPosX,
             textPosY
           );

  /* draw label db overlay */
  drawLabelOverlay( pContext,
                    m_currentTimstamp,
                    textPosX,
                    textPosY,
                    &m_diagnosis
                    );

  /* draw headlight state request */
  draw2HeadlightStateRequest( pContext,
                              &m_diagnosis,
                              GetMenuWidth()
                             );   
 
  m_activePlane = VISU_NONE;
  int activeErrorList = 0;
  textPosX =  m_HLARoi.X1;
  m_drawPlane = 0;
  for(int i = 0; i <= VISU_MAX; i++)
  {

    checkActivatedPlanes( i,
                          &m_planes,
                          &m_activePlane 
                         );

    if (m_activePlane < VISU_NONE)
    {
      m_drawPlane++;
      update_drawColor(m_activePlane);

      pm_rteInputs         = (const reqHlaPrtList_t*)&(pm_hlaMeasdata[m_activePlane].ReqPorts);
      pm_rteOutputs        = (const SimHlaProPrtList_t*)&(pm_hlaMeasdata[m_activePlane].ProPorts);
      pm_hlaInternMeasdata = &(pm_hlaMeasdata[m_activePlane].hlaInternMeasdata);

      if(    (pm_rteInputs->pCPar_HlafPar   != NULL)
          //&& (pm_rteInputs->pInputImageOdd  != NULL)
          //&& (pm_rteInputs->pSig_ImgCharOdd != NULL)
        )
      {
        somethingToDraw = true;

        /* draw HLAF */
        drawHLAF(pContext, &m_interfaces, &m_function);

        drawInterface(pContext, &m_interfaces);

        checkErrorList( &m_general, &activeErrorList );

        /* draw error list */
        drawErrorStack( pContext, 
                        m_bAlgoWasExecuted,
                        m_activePlane,
                        activeErrorList,
                        pm_hlaInternMeasdata->pHlaErrorStack,
                        textPosX,
                        GetMenuHeight()
                       );

      }
    }
  }

  font.BeginRender2D();
  CSimColor::SetTextColor(color_white, font);
  if(!somethingToDraw)
  {
    font.RenderTextf(m_HLARoi.X1 + (m_HLARoi.Width/2-80), m_HLARoi.Y1 + (m_HLARoi.Height/2-15), 1, "DrawFunction1 OK - No RTE Input");
  }
  else if(pm_hlaMeasdata[VISU_SIL].ReqPorts.pBaseCtrlData->eOpMode == BASE_OM_RESET)
  {
    font.RenderTextf(m_HLARoi.X1 + (m_HLARoi.Width/2-80), m_HLARoi.Y1 + (m_HLARoi.Height/2-15), 1, "DrawFunction1 OK - OpMode RESET");
  }
  font.EndRender2D();

  if(pm_hlaMeasdata[VISU_SIL].ProPorts.pHlaf_HeadlightControl)
  {
    m_HlaMeasurementCounterPreviousCycle = pm_hlaMeasdata[VISU_SIL].ProPorts.pHlaf_HeadlightControl->sSigHeader.uiMeasurementCounter;
  }

  /* Trigger re-drawing */
  if(m_redrawCounter > 0)
  {
    InvalidateRect(pContext->GetWindow().GetWindowHandle(), NULL, FALSE);
    m_redrawCounter--;
  }
}

void CSimHlaVisu::DrawFunction2(const ISimRenderContext* pContext)
{
  glTranslatef(0.375f, 0.375f, 0.0f);
  glEnable(GL_BLEND); 
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  int infoPosX = 20;
  int measfreezeVisuTmp = VISU_NONE;
  m_drawPlane = 0;
  for(int i = 0; i <= VISU_MAX; i++)
  {
    checkActivatedPlanes( i,
                          &m_planes,
                          &measfreezeVisuTmp 
                         );

    if (measfreezeVisuTmp < VISU_NONE)
    {
      m_drawPlane++;
      update_drawColor(measfreezeVisuTmp);

      pm_rteInputs  =        (const reqHlaPrtList_t*)&(pm_hlaMeasdata[measfreezeVisuTmp].ReqPorts);
      pm_rteOutputs =        (const SimHlaProPrtList_t*)&(pm_hlaMeasdata[measfreezeVisuTmp].ProPorts);
      pm_hlaInternMeasdata = &(pm_hlaMeasdata[measfreezeVisuTmp].hlaInternMeasdata);


      /*int infoPosX = 20;*/
      if(    (pm_rteInputs->pCPar_HlafPar != NULL)
          //&& (pm_rteInputs->pInputImageOdd != NULL)
          //&& (pm_rteInputs->pSig_ImgCharOdd != NULL)
        )
      {
        /* draw HLAF */
        drawHLAFInfo( pContext,
                     &m_interfaces,
                     &m_function,
                      infoPosX
                    );
      }
    }
  }
}

void CSimHlaVisu::checkErrorList( CSimVisuSubMenu* errorList, int* activeErrorList )
{

  if(errorList->getItemActivation(MENU_BUTTON_GEN_ERRORLIST, MENU_BUTTON_GEN_ERRORLIST_S_ALL) == true)
  {
    (*activeErrorList) = 1;
  }
  if(errorList->getItemActivation(MENU_BUTTON_GEN_ERRORLIST, MENU_BUTTON_GEN_ERRORLIST_S_NOINFO) == true)
  {
    (*activeErrorList) = 2;
  }
  if(errorList->getItemActivation(MENU_BUTTON_GEN_ERRORLIST, MENU_BUTTON_GEN_ERRORLIST_S_NOWARN) == true)
  {
    (*activeErrorList) = 3;
  }

}

void CSimHlaVisu::checkActivatedPlanes( int i, CSimVisuSubMenu* planes, int* activePlane )
{

  *activePlane = VISU_NONE;

  if(    (i == VISU_SIL)
      && (planes->getItemActivation(MENU_BUTTON_PLANE_SIL))
    )
  {
    *activePlane = VISU_SIL;
  }
  if(    (i == VISU_ECU)
     && (planes->getItemActivation(MENU_BUTTON_PLANE_ECU))
    )
  {
    *activePlane = VISU_ECU;
  }
  if(     (i == VISU_EVM)
    && (planes->getItemActivation(MENU_BUTTON_PLANE_EVM))
    )
  {
    *activePlane = VISU_EVM;
  }
  if(    (i == VISU_ENET)
    && (planes->getItemActivation(MENU_BUTTON_PLANE_ETH))
    )
  {
    *activePlane = VISU_ENET;
  }
  if(     (i == VISU_CAN)
    && (planes->getItemActivation(MENU_BUTTON_PLANE_CAN))
    )
  {
    *activePlane = VISU_CAN;
  }

}

void CSimHlaVisu::draw2MatrixTurnOffReasonHBState( const ISimRenderContext*  pContext )
{
  RTE_HLAF_MatrixTurnOffReason TurnOffReason;
  const RTE_HLAF_HeadlightControl_Common_t *pHeadlightControlCommon;
  const SimHlaProPrtList_t*  pRteOut_SIL = &pm_hlaMeasdata[VISU_SIL].ProPorts;
  const SimHlaProPrtList_t*  pRteOut_MCU = &pm_hlaMeasdata[VISU_ECU].ProPorts;
  const SimHlaProPrtList_t*  pRteOut_EVM = &pm_hlaMeasdata[VISU_EVM].ProPorts;
  const RTE_HLAF_Matrix_t*   pCAN_BMW_Matrix = &pm_hlaMeasdata[VISU_CAN].ProPorts.pHlaf_HeadlightControl->Matrix;
  const RTE_HLAF_Matrix_t*   pENET_BMW_Matrix = &pm_hlaMeasdata[VISU_ENET].ProPorts.pHlaf_HeadlightControl->Matrix;
  uint8 testSymbols = 0;
  uint8 NumSymbols = 10;
  int xpos;
  int ypos;
  int symbol_size = 30;
  int border_size = 2;
  int symbol_gap = 6;
  RTE_HLAF_HighBeamState eHighBeamState;
  bool switchOff = false;

  xpos = (int)m_HLARoi.X2 + 5;
  ypos = (int)m_HLARoi.Y1;

  int measfreezeVisuTmp = VISU_NONE;
  for(int i = 0; i <= VISU_MAX; i++)
  {  
    //measfreezeVisuTmp = m_overlayActivation.planes[i];

    checkActivatedPlanes( i,
                          &m_planes,
                          &measfreezeVisuTmp 
                         );

    switch(measfreezeVisuTmp)
    {
    case VISU_SIL:
      {
        break;
      }
    case VISU_ECU:
      if (   (pRteOut_MCU != NULL) 
        && (pRteOut_MCU->pHlaf_HeadlightControl != NULL)
      )
      {

        TurnOffReason           = pRteOut_MCU->pHlaf_HeadlightControl->Matrix.TurnOffReason;
        eHighBeamState          = pRteOut_MCU->pHlaf_HeadlightControl->Matrix.HighBeamState;
        pHeadlightControlCommon = &pRteOut_MCU->pHlaf_HeadlightControl->Common;

        draw2MatrixTurnOffReasonHBStateDraw( pContext,
                                             "ECU",
                                             TurnOffReason,
                                             eHighBeamState,
                                             pHeadlightControlCommon,
                                             testSymbols,
                                             color_ecu,
                                             xpos,
                                             ypos,
                                             symbol_size, 
                                             border_size, 
                                             symbol_gap,
                                             switchOff
                                            );
        xpos += symbol_size + symbol_gap;
      }
      else
      {
      /* nothing */
      }
      break;     
 
    case VISU_EVM:
      if (   (pRteOut_EVM != NULL) 
        && (pRteOut_EVM->pHlaf_HeadlightControl != NULL)
      )
      {

        TurnOffReason           = pRteOut_EVM->pHlaf_HeadlightControl->Matrix.TurnOffReason;
        eHighBeamState          = pRteOut_EVM->pHlaf_HeadlightControl->Matrix.HighBeamState;
        pHeadlightControlCommon = &pRteOut_EVM->pHlaf_HeadlightControl->Common;

        draw2MatrixTurnOffReasonHBStateDraw( pContext,
                                             "EVM",
                                             TurnOffReason,
                                             eHighBeamState,
                                             pHeadlightControlCommon,
                                             testSymbols,
                                             color_evm,
                                             xpos,
                                             ypos,
                                             symbol_size, 
                                             border_size, 
                                             symbol_gap,
                                             switchOff
                                            );
        xpos += symbol_size + symbol_gap;
      }
      else
      {
      /* nothing */
      }
      break;      

    case VISU_ENET:
      if(pm_hlaMeasdata[VISU_ENET].ProPorts.pHlaf_HeadlightControl)
      {
        TurnOffReason           = pENET_BMW_Matrix->TurnOffReason;
        eHighBeamState          = pENET_BMW_Matrix->HighBeamState;
        //pHeadlightControlCommon = ;

        draw2MatrixTurnOffReasonHBStateDraw( pContext,
                                             "ENET",
                                             TurnOffReason,
                                             eHighBeamState,
                                             &pm_hlaMeasdata[VISU_ENET].ProPorts.pHlaf_HeadlightControl->Common,
                                             testSymbols,
                                             color_eth,
                                             xpos,
                                             ypos,
                                             symbol_size, 
                                             border_size, 
                                             symbol_gap,
                                             switchOff
                                            );
        xpos += symbol_size + symbol_gap;
      }
      break;

    case VISU_CAN:
      if(   (pCAN_BMW_Matrix)
         &&(pCAN_BMW_Matrix->TurnOffReason != 0)
        )
      {
        TurnOffReason           = pCAN_BMW_Matrix->TurnOffReason;
        eHighBeamState          = pCAN_BMW_Matrix->HighBeamState;
        pHeadlightControlCommon = NULL;

        draw2MatrixTurnOffReasonHBStateDraw( pContext,        
                                             "CAN",
                                             TurnOffReason,
                                             eHighBeamState,
                                             pHeadlightControlCommon,
                                             testSymbols,
                                             color_can,
                                             xpos,
                                             ypos,
                                             symbol_size, 
                                             border_size, 
                                             symbol_gap,
                                             switchOff
                                            );
        xpos += symbol_size + symbol_gap;
      }
      break;

    default:
      break;
    }
  }

  /* draw DLL turn off reason */
  if ( (pRteOut_SIL != NULL) && (pRteOut_SIL->pHlaf_HeadlightControl != NULL) )
  {
    TurnOffReason           = pRteOut_SIL->pHlaf_HeadlightControl->Matrix.TurnOffReason;
    eHighBeamState          = pRteOut_SIL->pHlaf_HeadlightControl->Matrix.HighBeamState;
    pHeadlightControlCommon = &pRteOut_SIL->pHlaf_HeadlightControl->Common;
  }
  else
  {
    TurnOffReason           = 0;
    eHighBeamState          = RTE_HLAF_HB_STATE_UNKNOWN;
    pHeadlightControlCommon = NULL;
  }

  if(pRteOut_SIL->pAlgoCompState->eCompState == COMP_STATE_NOT_INITIALIZED)
  {
    testSymbols = 1;
  }
  else
  {
    testSymbols = 0;
  }

  draw2MatrixTurnOffReasonHBStateDraw( pContext,
                                       "DLL",
                                       TurnOffReason,
                                       eHighBeamState,
                                       pHeadlightControlCommon,
                                       testSymbols,
                                       color_sil,
                                       xpos,
                                       ypos,
                                       symbol_size, 
                                       border_size, 
                                       symbol_gap,
                                       switchOff
                                      );
}

void CSimHlaVisu::updateLockedObjects()
{

}

void CSimHlaVisu::drawFunctionSymbols( const ISimRenderContext*  pContext,
                                       const SimHlaProPrtList_t* pRteOut_SIL,
                                       const SimHlaProPrtList_t* pRteOut_MCU,
                                       const reqHlaPrtList_t*    pRteIn_SIL,
                                       const reqHlaPrtList_t*    pRteIn_MCU
                                      )
{

}

void CSimHlaVisu::drawMouseStatus(const ISimRenderContext* pContext)
{
  const int textHeight    = 10;
  const int textPosXCol1  = (int)m_HLARoi.X1 + 5;
  const int textPosY      = (int)m_HLARoi.Y2 + 5; /*+ 235;*/
  int textLine            = 1;
  IGDVFont& font          = pContext->GetWindow().GetFontInterface("", textHeight-3);

  CSimColor::SetColor(color_yellow, 0.3f);
  drawFilledRect(m_HLARoi.X1, textPosY, m_HLARoi.X1 + 75, textPosY + 92);
  CSimColor::SetColor(color_yellow);
  drawRect(m_HLARoi.X1, textPosY, m_HLARoi.X1 + 75, textPosY + 92);

  font.BeginRender2D();
  /* General information */
  {
    CSimColor::SetTextColor(color_white, font);
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "MTS (%i,%i)", m_mouseInfo.current.x, m_mouseInfo.current.y);                             textLine++; textLine++;
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "ROI (%i,%i)", m_mouseInfo.current.x - m_HLARoi.X1, m_mouseInfo.current.y - m_HLARoi.Y1); textLine++; textLine++;
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "ABS (%i,%i)", m_mouseInfo.current.x , m_mouseInfo.current.y); textLine++; textLine++;
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "Wheel: %i", m_mouseInfo.current.wheel);                                                  textLine++; textLine++;
  }

  font.EndRender2D();
}


void CSimHlaVisu::updateRois()
{
  if(pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList)
  {
    m_DrawImageOffsetX = 0;
    m_DrawImageOffsetY = 0;

    m_HLARoi.X1     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x1;
    m_HLARoi.Y1     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y1;
    m_HLARoi.X2     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x2;
    m_HLARoi.Y2     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y2;
    m_HLARoi.Yu     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.ySplit;
    m_HLARoi.Height = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y2 - pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y1;
    m_HLARoi.Width  = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x2 - pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x1;

    m_SilRoi.X1     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x1;
    m_SilRoi.Y1     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y1;
    m_SilRoi.X2     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x2;
    m_SilRoi.Y2     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y2;
    m_SilRoi.Yu     = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.ySplit;
    m_SilRoi.Height = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y2 - pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.y1;
    m_SilRoi.Width  = pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x2 - pm_hlaMeasdata[VISU_ECU].ReqPorts.pLsdLightObjectList->roi.x1;
  }
}

void CSimHlaVisu::drawGeneral(const ISimRenderContext* pContext)
{
  boolean bMenuUpdated = b_FALSE;

  if(pm_hlaMeasdata[VISU_SIL].ProPorts.pHlaf_HeadlightControl)
  {
    m_bAlgoWasExecuted = (pm_hlaMeasdata[VISU_SIL].ProPorts.pHlaf_HeadlightControl->sSigHeader.uiMeasurementCounter != m_HlaMeasurementCounterPreviousCycle); // uicyclecounter == ui32_HLAR_Cnt ??????????
  }

  bMenuUpdated = CheckSubMenuActivation( m_keyboardInfo,
                                         m_mouseInfo
                                        );
  updateRois();

  /* Draw Menu */
  SetMenuPosition((uint16)m_HLARoi.X1 + 5, (uint16)m_HLARoi.Y2 + 107, (uint16)(m_HLARoi.X2-m_HLARoi.X1));
  DrawMenu(pContext, m_mouseInfo, m_keyboardInfo);   

  /* draw mouse position */
  drawMouseStatus(pContext);

  draw2MatrixTurnOffReasonHBState(pContext);

  /* Reset Menu to default */
  if (m_general.getItemActivation(MENU_BUTTON_GEN_RESET))
  {
    InitMenu();
    DefaultMenuActivation();
  }

  /* Update counter for re-drawing. Re-drawing is needed since position of some parts in visu depend on others, thus prevents wrong drawing positions due to circular dependencies. */
  if(   (bMenuUpdated == b_TRUE)
     || (m_bAlgoWasExecuted == b_TRUE)
    )
  {
    m_redrawCounter = 3;
  }
}
