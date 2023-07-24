/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#include "stdafx.h"
#include "resource.h"

#ifdef __cplusplus
extern "C"
{
#endif
//TODO #include "hla_imager.h"
#ifdef __cplusplus
}
#endif

#include "sim_swc_hla_vis.h"
#include "sim_swc_hla_vis_version.h"
#include "sim_swc_dbg.h"

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"



#include <math.h>
#include <sstream>

// the client port names
//const char* CSimhlaVis::CP_CALCULATIONDONE      = "CalculationDone";
//const char* CSimhlaVis::CP_DISTRIBUTEOUTPUTDATA = "DistributeOutputData";

// the provide port names
//const char* CSimhlaVis::PP_OUTPUT               = "Output";

/* Menu names */
const string MENU_VIS = "[v]isualisation";
const string MENU_VIS_S_ECU = "ECU";
const string MENU_VIS_S_ETH = "ETH";
const string MENU_VIS_S_CAN = "CAN";
const string MENU_INPU = "I[n]put Interface";
const string MENU_LSDIN = "[l]sd Inputs";
const string MENU_BRIGHTOBJ = "[b]right Objects";
const string MENU_ERRORLIST = "[e]rror List";
const string MENU_ERRORLIST_S_NONE = "";
const string MENU_ERRORLIST_S_ALL = "all";
const string MENU_ERRORLIST_S_NOINFO = "no information";
const string MENU_ERRORLIST_S_NOWARN = "no warnings";
const string MENU_FUNCTION = "[f]unction";
const string MENU_FUNCTION_S_NONE = "";
const string MENU_FUNCTION_S_CAM = "Cam";
const string MENU_FUNCTION_S_CAMANG = "Cam Ang";
const string MENU_HBSYMBOL = "[d]raw high beam symbol";
const string MENU_HBSYMBOL_S_NONE = "";
const string MENU_HBSYMBOL_S_BIG = "big";
const string MENU_HBSYMBOL_S_SMALL = "small";

CSimhlaVis::CSimhlaVis()
// TODO: change data type of buffer id input port if needed
: CSimSwcDrawBase (10, "__BufferDataID", simI64_t, "__DoStore", "../gia_sim/adapter.dll")
, CSimSwcSynchronization        (this)
, CSimHlaEthernet               (reinterpret_cast<CSimSwcBase*>(this))
, CSimHlaCan                    (reinterpret_cast<CSimSwcBase*>(this))
, CSimVisuMenu                  (56, 216)
, m_rpCPAR_HLAF_Parameter       (this, "pCPar_HlafPar",           CPAR_HLAF_Parameter_t(),       CPAR_HLAF_PARAMETER_INTFVER)
, m_rpMonoCalibration           (this, "pMonoCalibration",        MonoCalibration_t(),           MONO_CALIBRATION_INTFVER)
, m_rpHlaBusInputSignals        (this, "pHlaBusInputSignals",     HLA_BusInputSignals_t(),       HLA_BUS_INPUT_SIGNALS_INTFVER)
, m_rpVehSig                    (this, "pVehSig",                 VehSig_t(),                    BSW_VEH_SIG_INTFVER)
, m_rpVehDyn                    (this, "pVehDyn",                 VehDyn_t(),                    VDY_VEH_DYN_INTFVER)
, m_rpCB_t_ProvidedOutputs      (this, "pCbOutputs",              CB_t_ProvidedOutputs_t(),      CB_PROVIDED_OUTPUTS_INTFVER)
, m_rpLsdEnvironmentData        (this, "pLsdEnvironmentData",     LSD_EnvironmentData_t(),       LSD_ENVIRONMENT_DATA_INTFVER)
, m_rpLsdLightObjectList        (this, "pLsdLightObjectList",     LSD_LightObjectList_t(),       LSD_LIGHT_OBJECT_LIST_INTFVER)
, m_rpLsdLightList              (this, "pLsdLightList",           LSD_LightList_t(),             LSD_LIGHT_LIST_INTFVER)
// 
, m_rpAlgoCompState             (this, "pAlgoCompState",          AlgoCompState_t(),             COMP_STATE_INTFVER)
, m_rpRTE_HLAF_HeadlightControl (this, "pHlaf_HeadlightControl",  RTE_HLAF_HeadlightControl_t(), RTE_HLAF_HEADLIGHTCONTROL_INTFVER)

/* Internal Measfreeze */
, m_rpHLA_ErrorStack            (this, "HLA_ErrorStack", t_ErrorHandling_ErrorStack())
, m_rpHLAFData                  (this, "HLAFData", HLAFData_t())
, m_bAlgoWasExecuted(false)
, m_redrawCounter(0)
, m_old_ui32_HLAR_CycleCount(0)
, m_general("Menu", 'M')
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "hla version " << HLAALL_SW_MAIN_VER_NO << "." << HLAALL_SW_SUB_VER_NO << "." << HLAALL_SW_BUG_FIX_LEV << "." << HLAALL_SW_BUG_FIX_LEV2;
  dataTxt   << "hla (hla Visualization Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

  dataTxt.str("");
#ifdef _DEBUG
  dataTxt << "Debug ";
#else
  dataTxt << "Release ";
#endif
  dataTxt << "build at " << __DATE__ << " " << __TIME__;
  AddInternalData("Compiling Info", dataTxt.str().c_str());

  /* Create server Ports */
  AddServerPort("Reset", Reset, this);
  AddServerPort("Init",  Init,  this);
  AddServerPort("Doit",  Doit,  this);

  // Create drawing ports
  AddDrawServerPort("HlaDrawFunc", DrawFunction, this);
  AddDrawServerPort("DrawHlaSubMenu", DrawFunction2, this);

  // Create algorithm ports
  SetupPorts();

  memset(&m_keyboardInfo, 0, sizeof(m_keyboardInfo));
  memset(&m_mouseInfo, 0, sizeof(m_mouseInfo));

  // Init lists for locked output objects
  memset(&m_lockedObjects, 0, sizeof(m_lockedObjects));
  m_lockedObjects.trackList   = std::vector<LockedTrackListItem>();
  m_lockedObjects.objectList  = std::vector<LockedObjectListItem>();

  memset(&m_HLARoi, 0, sizeof(m_HLARoi));

  m_labelTool.labelMode       = 0;
  m_labelTool.labelGroup      = 0;
  m_labelTool.labelClass      = 0;

  m_ReqPorts.pCPar_HlafPar       = &m_rpCPAR_HLAF_Parameter.val();
  m_ReqPorts.pMonoCalibration    = &m_rpMonoCalibration.val();
  m_ReqPorts.pHlaBusInputSignals = &m_rpHlaBusInputSignals.val();
  m_ReqPorts.pVehSig             = &m_rpVehSig.val();
  m_ReqPorts.pVehDyn             = &m_rpVehDyn.val();
  m_ReqPorts.pCbOutputs          = &m_rpCB_t_ProvidedOutputs.val();
  m_ReqPorts.pLsdEnvironmentData = &m_rpLsdEnvironmentData.val();
  m_ReqPorts.pLsdLightObjectList = &m_rpLsdLightObjectList.val();
  m_ReqPorts.pLsdLightList       = &m_rpLsdLightList.val();

  m_ProPorts.pAlgoCompState                 = &m_rpAlgoCompState.val();
  m_ProPorts.pHlaf_HeadlightControl         = &m_rpRTE_HLAF_HeadlightControl.val();

  ResetReceivePorts(true);

  /* Menu Set-Up */
  m_general.setItem(MENU_VIS);
  m_general.setSubItem(MENU_VIS_S_ECU);
  m_general.setSubItem(MENU_VIS_S_ETH);
  m_general.setSubItem(MENU_VIS_S_CAN);
  m_general.setItem(MENU_INPU);
  m_general.setItem(MENU_LSDIN);
  m_general.setItem(MENU_BRIGHTOBJ);
  m_general.setItem(MENU_ERRORLIST);
  m_general.setSubItem(MENU_ERRORLIST_S_NONE);
  m_general.setSubItem(MENU_ERRORLIST_S_ALL);
  m_general.setSubItem(MENU_ERRORLIST_S_NOINFO);
  m_general.setSubItem(MENU_ERRORLIST_S_NOWARN);
  m_general.setItem(MENU_FUNCTION);
  m_general.setSubItem(MENU_FUNCTION_S_NONE);
  m_general.setSubItem(MENU_FUNCTION_S_CAM);
  m_general.setSubItem(MENU_FUNCTION_S_CAMANG);
  m_general.setItem(MENU_HBSYMBOL);
  m_general.setSubItem(MENU_HBSYMBOL_S_NONE);
  m_general.setSubItem(MENU_HBSYMBOL_S_BIG);
  m_general.setSubItem(MENU_HBSYMBOL_S_SMALL);

  /* rows activated by default */
  m_general.activateItem(MENU_VIS);
  m_general.activateItem(MENU_LSDIN);
  m_general.activateItem(MENU_ERRORLIST, MENU_ERRORLIST_S_ALL);
  m_general.activateItem(MENU_FUNCTION, MENU_FUNCTION_S_CAM);

  m_subMenuMap.push_back(&m_general);

  /* Set menu position */
  SetMenuPosition(845, 20, 200);

  /* Set pointer to ethernet and can data */
  m_hlaMeasdataETH = CSimHlaEthernet::GetEthernetData();
  m_hlaMeasdataCAN = CSimHlaCan::GetCanData();
}

CSimhlaVis::~CSimhlaVis()
{
}

void CSimhlaVis::SetupPorts()
{
  /* initialize input port map */
  m_receivePortMap.clear();

  /* HLA RTE OUTPUT*/
  /* AlgoCompState_t */
  m_rpAlgoCompState.setupSyncData(&m_rpSyncRefHeader.val().sSigHeader, &m_rpSyncRefHeader.val().sBaseCtrl.sSigHeader);
  m_rpAlgoCompState.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpAlgoCompState);

  /* RTE_HLAF_HeadlightControl_t */
  m_rpRTE_HLAF_HeadlightControl.setupSyncData(&m_rpSyncRefHeader.val().sSigHeader, &m_rpAlgoCompState.val().sSigHeader);
  m_rpRTE_HLAF_HeadlightControl.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpRTE_HLAF_HeadlightControl);

  /* HLA RTE INPUT */
  /* CPAR_HLAF_Parameter_t */
  m_rpCPAR_HLAF_Parameter.setupSyncData(&m_rpSyncRefHeader.val().pCPar_HlafPar, &m_rpAlgoCompState.val().sSigHeader);
  m_rpCPAR_HLAF_Parameter.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpCPAR_HLAF_Parameter);

  /* MonoCalibration_t */
  m_rpMonoCalibration.setupSyncData(&m_rpSyncRefHeader.val().pMonoCalibration, &m_rpAlgoCompState.val().sSigHeader);
  m_rpMonoCalibration.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpMonoCalibration);

  /* HLA_BusInputSignals_t */
  m_rpHlaBusInputSignals.setupSyncData(&m_rpSyncRefHeader.val().pHlaBusInputSignals, &m_rpAlgoCompState.val().sSigHeader);
  m_rpHlaBusInputSignals.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpHlaBusInputSignals);

  /* VehSig_t */
  m_rpVehSig.setupSyncData(&m_rpSyncRefHeader.val().pVehSig, &m_rpAlgoCompState.val().sSigHeader);
  m_rpVehSig.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpVehSig);

  /* VehDyn_t */
  m_rpVehDyn.setupSyncData(&m_rpSyncRefHeader.val().pVehDyn, &m_rpAlgoCompState.val().sSigHeader);
  m_rpVehDyn.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpVehDyn);

  /* CB_t_ProvidedOutputs_t */
  m_rpCB_t_ProvidedOutputs.setupSyncData(&m_rpSyncRefHeader.val().pCbOutputs, &m_rpAlgoCompState.val().sSigHeader);
  m_rpCB_t_ProvidedOutputs.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpCB_t_ProvidedOutputs);

  /* LSD Environment Data */
  m_rpLsdEnvironmentData.setupSyncData(&m_rpSyncRefHeader.val().pLsdEnvironmentData, &m_rpAlgoCompState.val().sSigHeader);
  m_rpLsdEnvironmentData.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpLsdEnvironmentData);

  /* LSD Light Object List */
  m_rpLsdLightObjectList.setupSyncData(&m_rpSyncRefHeader.val().pLsdLightObjectList, &m_rpAlgoCompState.val().sSigHeader);
  m_rpLsdLightObjectList.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpLsdLightObjectList);

  /* LSD Light List */
  m_rpLsdLightList.setupSyncData(&m_rpSyncRefHeader.val().pLsdLightList, &m_rpAlgoCompState.val().sSigHeader);
  m_rpLsdLightList.getDefaultValues(true);
  m_receivePortMap.push_back(&m_rpLsdLightList);
}

void CSimhlaVis::Reset()
{
  // TODO: Call internal data buffer clear if available
  ResetReceivePorts(true);

  CSimHlaEthernet::ResetEthReceivePorts();

  /* Init cam rot */
  // HLACamRotInit();

}

void CSimhlaVis::Init()
{
  ResetReceivePorts(true);

  CSimHlaEthernet::ResetEthReceivePorts();

  /* Init cam rot */
  // HLACamRotInit();

//TODO   CSimHlaVisuError::Init();

}

void CSimhlaVis::Doit()
{

  /* Check RTE Ports */
  CheckPortsDataReceived();

  /* Check Ethernet Input & Copy to RTE Structs */
  CSimHlaEthernet::CollectKAFASInputs();

  /* Update HLACamRot */
  UpdateCameraSimu(&m_ReqPorts);

  /* ROI Pre-Calculation */
  CalcROI(&m_ProPorts, &m_ReqPorts);

  ResetReceivePorts(false);
}


void CSimhlaVis::DrawFunction(const ISimRenderContext* pContext)
{
  // TODO: The buffer mechanism of the ports will take care of thread locking and data synchronization.
  //       Just use the according members for the ports and place your openGL drawing code here.
  //       For proper buffering along with the inputs some id has to be provided to the '__BufferDataID'
  //       port and the '__DoStore' server port has to be called.


  const RTE_HLAF_MatrixGFA_t* pMatrixGFA;
  uint32 nGFA;
  uint8 testSymbols = 0;
  int activePlane = VISU_NONE;
  int activeErrorList = 0;
  int symbol_size   = 30; 
  int border_size   = 2;
  int symbol_gap    = 8;
  int infoPosX = m_HLARoi.X2 + 80;
  int textPosX = 25;
  boolean bMenuUpdated = b_FALSE;
  ImageOffsetX = 0;
  ImageOffsetY = 0;


  glTranslatef(0.375f, 0.375f, 0.0f);
  glEnable (GL_BLEND); 
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  bMenuUpdated = CheckSubMenuActivation( m_keyboardInfo,
                                         m_mouseInfo
                                        );

  /* Set color */
  if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_ECU))
  {
    activePlane = VISU_ECU;
  }
  else if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_ETH))
  {
    activePlane = VISU_ENET;
  }
  else if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_CAN))
  {
    activePlane = VISU_CAN;
  }

  update_drawColor(activePlane);


  if(m_ProPorts.pHlaf_HeadlightControl != NULL)
  {
    m_bAlgoWasExecuted = (m_ProPorts.pHlaf_HeadlightControl->sSigHeader.uiCycleCounter != m_old_ui32_HLAR_CycleCount);
    m_old_ui32_HLAR_CycleCount = m_ProPorts.pHlaf_HeadlightControl->sSigHeader.uiCycleCounter;
  }

  UpdateLockedObjects();

  DrawSimuVersion(pContext);

  /* Draw head light symbol */
  if (m_general.getItemActivation(MENU_HBSYMBOL) == true)
  {
    draw2HeadlightStateRequestVis( pContext,
                                   &m_ReqPorts,
                                   (const reqHlaPrtList_t*)&m_hlaMeasdataCAN.ReqPorts,
                                   (const reqHlaPrtList_t*)&m_hlaMeasdataETH.ReqPorts,
                                   NULL,
                                   &m_ProPorts,
                                   m_general.getItemActivation(MENU_HBSYMBOL, MENU_HBSYMBOL_S_BIG)
                                  );
  }

  drawROI( pContext );

  drawFunctionSymbolsDraw( &m_ProPorts,
                           testSymbols,
                           color_ecu,
                           m_HLARoi.X2 + 5,
                           m_HLARoi.Y1,
                           symbol_size, 
                           border_size, 
                           symbol_gap
                          );

  if(m_general.getItemActivation(MENU_INPU) == true)
  {
    drawInputInterface( pContext, 
                        &m_ReqPorts,
                        color_inp,
                        0.2f,
                        ImageOffsetX,
                        ImageOffsetY
                       );

    drawInputInterfaceDetailsText( pContext,
                                   &m_ReqPorts,
                                   infoPosX
                                  );


  }

  if (m_general.getItemActivation(MENU_LSDIN) == true)
  {
    drawLsdInputInterface( pContext,
                         &m_ReqPorts,
                         color_ecu,
                         &(m_rpHLAFData.val()),
                         1,
                         1,
                         ImageOffsetX,
                         ImageOffsetY
                        );

    drawOutputInterfaceInfo( pContext, 
                             &m_ReqPorts,
                             infoPosX,
                             ImageOffsetX,
                             ImageOffsetY
                            );
  }

  if (m_general.getItemActivation(MENU_BRIGHTOBJ) == true)
  {
    DrawBrightObjects( pContext,
                       &m_ReqPorts,
                       &m_ProPorts
                      );
  }

  if(    (m_general.getItemActivation(MENU_FUNCTION, MENU_FUNCTION_S_CAM) == true)
      || (m_general.getItemActivation(MENU_FUNCTION, MENU_FUNCTION_S_CAMANG) == true)
    )
  {
    if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_ECU) == true)
    {
      /* Set GFA and nGFA depending of project and subkey */
      pMatrixGFA = m_ProPorts.pHlaf_HeadlightControl->Matrix.GFA;
      nGFA = m_ProPorts.pHlaf_HeadlightControl->Matrix.nGFA;

      drawGFAs( pContext,
                m_general.getItemActivation(MENU_FUNCTION, MENU_FUNCTION_S_CAM),
                &m_ReqPorts, 
                pMatrixGFA,
                nGFA,
                m_drawColor,
                0.2f,
                ImageOffsetX,
                ImageOffsetY
               );

      drawHLAFOutput( pContext,
                      &m_ProPorts,
                      m_drawColor,
                      infoPosX
                      );
    }
    else if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_ETH) == true)
    {
      drawGFAs( pContext,
                b_TRUE,
                (const reqHlaPrtList_t*)&m_hlaMeasdataETH.ReqPorts,
                m_hlaMeasdataETH.ProPorts.pHlaf_HeadlightControl->Matrix.GFA,
                m_hlaMeasdataETH.ProPorts.pHlaf_HeadlightControl->Matrix.nGFA,
                m_drawColor,
                0.2f,
                ImageOffsetX,
                ImageOffsetY
                );
      
      drawHLAFOutput( pContext,
                      &m_hlaMeasdataETH.ProPorts,
                      m_drawColor,
                      infoPosX
                      );
    }
    else if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_CAN) == true)
    {
     drawGFAs( pContext,
               b_TRUE,
               (const reqHlaPrtList_t*)&m_hlaMeasdataCAN.ReqPorts,
               m_hlaMeasdataCAN.ProPorts.pHlaf_HeadlightControl->Matrix.GFA,
               m_hlaMeasdataCAN.ProPorts.pHlaf_HeadlightControl->Matrix.nGFA,
               color_can,
               0.2f,
               ImageOffsetX,
               ImageOffsetY
             );

      drawHLAFOutput( pContext,
                      &m_hlaMeasdataCAN.ProPorts,
                      m_drawColor,
                      infoPosX
                      );
    }
  }

  /* Draw algo/wrapper version */
  draw2EntityVersionVis( pContext,
                         &m_ProPorts
                        );  

  m_drawColor = color_black;

  if(m_general.getItemActivation(MENU_ERRORLIST, MENU_ERRORLIST_S_ALL) == true)
  {
    activeErrorList = 1;
  }
  if(m_general.getItemActivation(MENU_ERRORLIST, MENU_ERRORLIST_S_NOINFO) == true)
  {
    activeErrorList = 2;
  }
  if(m_general.getItemActivation(MENU_ERRORLIST, MENU_ERRORLIST_S_NOWARN) == true)
  {
    activeErrorList = 3;
  }

  drawErrorStack( pContext,
                  m_bAlgoWasExecuted,
                  activePlane,
                  activeErrorList,
                  &(m_rpHLA_ErrorStack.val()),
                  textPosX, 
                  -107
                 );

  /* Update counter for re-drawing. Re-drawing is needed since position of some parts in visu depend on others, thus prevents wrong drawing positions due to circular dependencies. */
  if(   (bMenuUpdated == b_TRUE)
     || (m_bAlgoWasExecuted == b_TRUE)
    )
  {
    m_redrawCounter = 3;
  }

  /* Trigger re-drawing */
  if(m_redrawCounter > 0)
  {
    InvalidateRect(pContext->GetWindow().GetWindowHandle(), NULL, FALSE);
    m_redrawCounter--;
  }
}

void CSimhlaVis::DrawFunction2(const ISimRenderContext* pContext)
{
  // TODO: The buffer mechanism of the ports will take care of thread locking and data synchronization.
  //       Just use the according members for the ports and place your openGL drawing code here.
  //       For proper buffering along with the inputs some id has to be provided to the '__BufferDataID'
  //       port and the '__DoStore' server port has to be called.

  RTE_HLAF_MatrixTurnOffReason TurnOffReason;
  const RTE_HLAF_HeadlightControl_Common_t *pHeadlightControlCommon;
  RTE_HLAF_HighBeamState eHighBeamState;
  int symbol_size = 30;
  int border_size = 2;
  int symbol_gap = 6;
  bool kafasInputs = false;
  bool canInputs = false;
  boolean bMenuUpdated = b_FALSE;

  glTranslatef(0.375f, 0.375f, 0.0f);
  glEnable (GL_BLEND); 
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  bMenuUpdated = CheckSubMenuActivation( m_keyboardInfo,
                                         m_mouseInfo
                                        );

  /* Draw head light symbols */
  draw2HeadlightStateRequestVis( pContext,
                                 &m_ReqPorts,
                                 (const reqHlaPrtList_t*)&m_hlaMeasdataCAN.ReqPorts,
                                 (const reqHlaPrtList_t*)&m_hlaMeasdataETH.ReqPorts,
                                 NULL,
                                 &m_ProPorts
                                );

  
  /* draw menu */
  DrawMenu(pContext, m_mouseInfo, m_keyboardInfo);

  drawMouseStatus(pContext);

  /* Draw turn off reasons */
  if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_ECU) == true)
  {
    TurnOffReason           = m_ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason;
    eHighBeamState          = m_ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState;
    pHeadlightControlCommon = &m_ProPorts.pHlaf_HeadlightControl->Common;

    draw2MatrixTurnOffReasonHBStateDrawVis( pContext,
                                            "ECU",
                                            TurnOffReason,
                                            eHighBeamState,
                                            pHeadlightControlCommon,
                                            0,
                                            color_ecu,
                                            20,
                                            25,
                                            symbol_size, 
                                            border_size, 
                                            symbol_gap,
                                            true
                                          );
  }
  else if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_CAN) == true)
  {
    draw2MatrixTurnOffReasonHBStateDrawVis( pContext,
                                            "CAN",
                                            m_hlaMeasdataCAN.ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason,
                                            m_hlaMeasdataCAN.ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState,
                                            NULL,
                                            0,
                                            color_can,
                                            20,
                                            25,
                                            symbol_size, 
                                            border_size, 
                                            symbol_gap,
                                            true
                                          );
  }
  else if(m_general.getItemActivation(MENU_VIS, MENU_VIS_S_ETH) == true)
  {
    draw2MatrixTurnOffReasonHBStateDrawVis( pContext,
                                            "ENET",
                                            m_hlaMeasdataETH.ProPorts.pHlaf_HeadlightControl->Matrix.TurnOffReason,
                                            m_hlaMeasdataETH.ProPorts.pHlaf_HeadlightControl->Matrix.HighBeamState,
                                            &m_hlaMeasdataCAN.ProPorts.pHlaf_HeadlightControl->Common,
                                            0,
                                            color_eth,
                                            20,
                                            25,
                                            symbol_size, 
                                            border_size, 
                                            symbol_gap,
                                            true
                                          );
  }

  /* Update counter for re-drawing. Re-drawing is needed since position of some parts in visu depend on others, thus prevents wrong drawing positions due to circular dependencies. */
  if(   (bMenuUpdated == b_TRUE)
     || (m_bAlgoWasExecuted == b_TRUE)
    )
  {
    m_redrawCounter = 3;
  }

  /* Trigger re-drawing */
  if(m_redrawCounter > 0)
  {
    InvalidateRect(pContext->GetWindow().GetWindowHandle(), NULL, FALSE);
    m_redrawCounter--;
  }
}

CVersionInfoImpl CSimhlaVis::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}

void CSimhlaVis::CalcROI( const SimHlaProPrtList_t* rteOutput, const reqHlaPrtList_t* rteInput )
{

  if (m_rpLsdLightObjectList.isDirty())
  {
    m_HLARoi.X1     = rteInput->pLsdLightObjectList->roi.x1;
    m_HLARoi.Y1     = rteInput->pLsdLightObjectList->roi.y1;
    m_HLARoi.X2     = rteInput->pLsdLightObjectList->roi.x2;
    m_HLARoi.Y2     = rteInput->pLsdLightObjectList->roi.y2;
    m_HLARoi.Yu     = rteInput->pLsdLightObjectList->roi.ySplit;
    m_HLARoi.Height = rteInput->pLsdLightObjectList->roi.y2 - rteInput->pLsdLightObjectList->roi.y1;
    m_HLARoi.Width  = rteInput->pLsdLightObjectList->roi.x2 - rteInput->pLsdLightObjectList->roi.x1;

    m_SilRoi.X1     = rteInput->pLsdLightObjectList->roi.x1;
    m_SilRoi.Y1     = rteInput->pLsdLightObjectList->roi.y1;
    m_SilRoi.X2     = rteInput->pLsdLightObjectList->roi.x2;
    m_SilRoi.Y2     = rteInput->pLsdLightObjectList->roi.y2;
    m_SilRoi.Yu     = rteInput->pLsdLightObjectList->roi.ySplit;
    m_SilRoi.Height = rteInput->pLsdLightObjectList->roi.y2 - rteInput->pLsdLightObjectList->roi.y1;
    m_SilRoi.Width  = rteInput->pLsdLightObjectList->roi.x2 - rteInput->pLsdLightObjectList->roi.x1;
  }
}

bool CSimhlaVis::OnMouseMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
  const int x = (int)CML_Round(LOWORD(windowMessage.GetLParam()));
  const int y = (int)CML_Round(HIWORD(windowMessage.GetLParam()));

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

bool CSimhlaVis::OnKeyboardMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
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

bool CSimhlaVis::OnWindowMessage(const ISimRenderContext& context, const ISimWindowMessage& windowMessage)
{
  return false;
}

void CSimhlaVis::UpdateLockedObjects(void)
{
  const LSD_LightObject_t*  pObject;
  const LSD_LightObject_t*  pObjectFound;
  uint8                     iObject;

  const LSD_LightObjectList_t* pObjectList;

  int minDistance;

  /* select appropriate object output list */
  //pObjectList = m_ProPorts.pHlar_ObjList; 
  pObjectList = m_ReqPorts.pLsdLightObjectList;

  /* check if a middle mouse click happened */
  if (m_mouseInfo.singleClickMiddle.count > m_lockedObjects.oldClickMiddleCount)
  {
    /* new mouse click middle */
    m_lockedObjects.oldClickMiddleCount = m_mouseInfo.singleClickMiddle.count;

    /* flush track list */
    m_lockedObjects.trackList.clear();

    /* flush RTE_object list */
    m_lockedObjects.objectList.clear();
  }

  /* mass-select crosses via rectangle select */
  if (m_mouseInfo.rect.eState == t_MouseInfo::s_rect::STATE_VALID)
  {
    /* check RTE_Objects */
    for(iObject = 0; iObject < pObjectList->numObjects; iObject++)
    {
      /* get RTE_Object */
      pObject = &(pObjectList->lightObjects[iObject]);

      /* check if RTE_Object is next to mouse pointer */
      if (   (pObject->kinematic.camera.x /*- m_HLARoi.X1*/ > m_mouseInfo.rect.left - 2)
          && (pObject->kinematic.camera.x /*- m_HLARoi.X1*/ < m_mouseInfo.rect.right + 2)
          && (pObject->kinematic.camera.y /*- m_HLARoi.Y1*/ > m_mouseInfo.rect.top - 2)
          && (pObject->kinematic.camera.y /*- m_HLARoi.Y1*/ < m_mouseInfo.rect.bottom +2)
         )
      {
        /* RTE_Object is in rect */
        bool objectAlreadySelected = false;

        /* loop over selected RTE_Objects */
        for (LockedObjectList::iterator it = m_lockedObjects.objectList.begin(); it != m_lockedObjects.objectList.end(); ++it)
        {
          /* if RTE_Object has already been selected, skip it */
          if (pObject->general.lightObjectID == it->pObjectTrackId)
          {
            objectAlreadySelected = true;
            break;
          }
        }

        /* if RTE_Object has not been selected, add it to selection list */
        if (objectAlreadySelected == false)
        {
          LockedObjectListItem item;
          item.pObjectTrackId       = pObject->general.lightObjectID;
          item.oldpObjectTraceTime  = pObject->general.cyclesTraced;
          item.oldpObjectxcenter    = pObject->kinematic.camera.x;
          item.oldpObjectycenter    = pObject->kinematic.camera.y;
          m_lockedObjects.objectList.push_back(item);
        }
      }
    }
  }

  /* a new mouse left double click happened */
  if (m_mouseInfo.doubleClickLeft.count > m_lockedObjects.oldClickLeftCount)
  {
    /* new mouse click left */
    m_lockedObjects.oldClickLeftCount = m_mouseInfo.doubleClickLeft.count;

    /* check RTE_Objects */
    minDistance = 10000;

    for(iObject = 0; iObject < pObjectList->numObjects; iObject++)
    {
      /* get RTE_Object */
      pObject = &(pObjectList->lightObjects[iObject]);

      /* calculate distance to mouse position */
      const int distance =   std::abs(pObject->kinematic.camera.x - m_mouseInfo.doubleClickLeft.x)
                           + std::abs(pObject->kinematic.camera.y - m_mouseInfo.doubleClickLeft.y);

      /* get RTE_Object with least distance */
      if (distance < minDistance)
      {
        minDistance = distance;
        pObjectFound = pObject;
      }
    }

    /* if minDistance has been undercut */
    if (minDistance <= 5)
    {
      bool objectErased = false;

      /* loop over RTE_Objects */
      for (LockedObjectList::iterator it = m_lockedObjects.objectList.begin(); it != m_lockedObjects.objectList.end(); ++it)
      {
        /* deselect RTE_Object if object has been selected */
        if (pObjectFound->general.lightObjectID == it->pObjectTrackId)
        {
          m_lockedObjects.objectList.erase(it);
          objectErased = true;
          break;
        }
      }

      /* if no RTE_Object has been deselected */
      if (objectErased == false)
      {
        LockedObjectListItem item;
        item.pObjectTrackId       = pObjectFound->general.lightObjectID;
        item.oldpObjectTraceTime  = pObjectFound->general.cyclesTraced;
        item.oldpObjectxcenter    = pObjectFound->kinematic.camera.x;
        item.oldpObjectycenter    = pObjectFound->kinematic.camera.y;
        m_lockedObjects.objectList.push_back(item);
      }
    }
  }

  /* validate locked objects */
  LockedObjectList::iterator it_obj = m_lockedObjects.objectList.begin();
  while (it_obj != m_lockedObjects.objectList.end())
  {
    /* validate that locked track still exists */
    bool pObjectLockedFound = false;
    pObjectFound = NULL;

    /* check RTE_Objects */
    for(iObject = 0; iObject < pObjectList->numObjects; iObject++)
    {
      /* get RTE_Object */
      pObject = &(pObjectList->lightObjects[iObject]);

      /* RTE_Object is in selection list */
      if(it_obj->pObjectTrackId == pObject->general.lightObjectID)
      {
        pObjectLockedFound = true;
        pObjectFound = pObject;
        break;
      }
    }

    /* RTE_Object in selection list has not been found in RTE_Objects list -> remove it */
    if(!pObjectLockedFound)
    {
      /* remove RTE_Object from selection list */
      it_obj = m_lockedObjects.objectList.erase(it_obj);
      continue;
    }
    else
    {
      /* validate that locked RTE_Object has not become a new RTE_Object */
      if (   (pObjectFound->general.cyclesTraced < it_obj->oldpObjectTraceTime)      /*    track has a smaller tracing time than before  */
          || (   (pObjectFound->general.cyclesTraced == it_obj->oldpObjectTraceTime) /* or track has same trace time BUT                 */
              && (   (pObjectFound->kinematic.camera.x != it_obj->oldpObjectxcenter)  /*       x_center is not same as before             */
                  || (pObjectFound->kinematic.camera.y != it_obj->oldpObjectycenter)  /*    or y_center is not same as before             */
                 )
             )
         )
      {
        /* remove RTE_Object from selection list */
        it_obj = m_lockedObjects.objectList.erase(it_obj);
        continue;
      }
    }

    /* update trace time and center coordinates */
    it_obj->oldpObjectTraceTime = pObjectFound->general.cyclesTraced;
    it_obj->oldpObjectxcenter   = pObjectFound->kinematic.camera.x;
    it_obj->oldpObjectycenter   = pObjectFound->kinematic.camera.y;

    /* go to next item */
    ++it_obj;
  }
}

void  CSimhlaVis::DrawBrightObjects( const ISimRenderContext*      pContext,
                                     const reqHlaPrtList_t*        m_rteInputs,
                                     const SimHlaProPrtList_t*     m_rteOutputs
                                    )
{
  if(m_rpRTE_HLAF_HeadlightControl.isDirty())
  {
    uint8 counter;
    /* float32 borderAng; */
    float32 x_border;
    float32 borderAng;
    float32 alpha = 1.0f;

    /* indicate status of area */
    glBegin(GL_QUADS);
    {
      if (m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[0] == RTE_HLAF_DIMM_LEVEL_NO_REDUCT)
      {
        alpha = 0.0f;
      }
      else if (m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[0] == RTE_HLAF_DIMM_LEVEL_REDUCT_1)
      {
        alpha = 0.2f;
      }
      else if (m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[0] == RTE_HLAF_DIMM_LEVEL_REDUCT_2)
      {
        alpha = 0.4f;
      }
      CSimColor::SetColor(color_white, alpha);

      glVertex3i(m_HLARoi.X2, m_HLARoi.Y1, 1);
      glVertex3i(m_HLARoi.X2, m_HLARoi.Y2, 1);

      for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS_BORDERS ; counter++)
      {
        borderAng = m_rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[counter];

        /* minimal check for degree-coded border angles */
        if(fabs(borderAng) > 1.5f)
        {
          borderAng = CML_Deg2Rad(borderAng);
        }

        x_border = m_rteInputs->pMonoCalibration->sIntrinsic.fFocalX * tanf(borderAng);

        glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y2, 1);
        glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y1, 1);

        if (m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[counter+1] == RTE_HLAF_DIMM_LEVEL_NO_REDUCT)
        {
          alpha = 0.0f;
        }
        else if (m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[counter+1] == RTE_HLAF_DIMM_LEVEL_REDUCT_1)
        {
          alpha = 0.2f;
        }
        else if (m_rteOutputs->pHlaf_HeadlightControl->Dimming.DimmingArea[counter+1] == RTE_HLAF_DIMM_LEVEL_REDUCT_2)
        {
          alpha = 0.4f;
        }
        CSimColor::SetColor(color_white, alpha);

        glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y1, 1);
        glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y2, 1);
      }

      glVertex3i(m_HLARoi.X1, m_HLARoi.Y2, 1);
      glVertex3i(m_HLARoi.X1, m_HLARoi.Y1, 1);
    }
    glEnd();

    /* draw lines for the codeable regions */
    CSimColor::SetColor(color_green);
    for (counter = 0; counter < RTE_HLA_NUM_DIMM_AREAS_BORDERS; counter++)
    {
      borderAng = m_rteInputs->pCPar_HlafPar->Dimming.AreaRightBorderArray[counter];

      /* minimal check for degree-coded border angles */
      if(fabs(borderAng) > 1.5f)
      {
        borderAng = CML_Deg2Rad(borderAng);
      }

      x_border = m_rteInputs->pMonoCalibration->sIntrinsic.fFocalX * tanf(borderAng);

      glBegin(GL_LINES);
      {
        glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y1, 1);
        glVertex3f(m_HLARoi.X2 - (m_HLARoi.Width * 0.5f) - x_border, (float32)m_HLARoi.Y2, 1);
      }
      glEnd();
    }

    const LSD_LightObject_t* pHLAObj = &m_rteInputs->pLsdLightObjectList->lightObjects[0];

    for (unsigned int i = 0; i < m_rteInputs->pLsdLightObjectList->numObjects; i++)
    {
      if( (pHLAObj->attributes.statusBits & LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE) == LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE)
      {
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        CSimColor::SetColor(color_yellow, 0.5f);
        glBegin(GL_QUADS);
        {
          glVertex3i(pHLAObj->kinematic.camera.x - 5 +ImageOffsetX, pHLAObj->kinematic.camera.y - 5 +ImageOffsetY, 1);
          glVertex3i(pHLAObj->kinematic.camera.x + 5 +ImageOffsetX, pHLAObj->kinematic.camera.y - 5 +ImageOffsetY, 1);
          glVertex3i(pHLAObj->kinematic.camera.x + 5 +ImageOffsetX, pHLAObj->kinematic.camera.y + 5 +ImageOffsetY, 1);
          glVertex3i(pHLAObj->kinematic.camera.x - 5 +ImageOffsetX, pHLAObj->kinematic.camera.y + 5 +ImageOffsetY, 1);
        }
        glEnd();
      }
      pHLAObj++;
    }
  }
}

void CSimhlaVis::DrawSimuVersion(const ISimRenderContext* pContext)
{

  IGDVFont& font = pContext->GetWindow().GetFontInterface("", 7);

  font.BeginRender2D();

  CSimColor::SetTextColor(color_green, font);
  font.RenderTextf(m_HLARoi.X1, m_HLARoi.Y1-15, 1, "Simu Version: %d.%d.%d.%d", HLAALL_SW_MAIN_VER_NO, HLAALL_SW_SUB_VER_NO, HLAALL_SW_BUG_FIX_LEV, HLAALL_SW_BUG_FIX_LEV2);

  font.EndRender2D();

}

void CSimhlaVis::drawMouseStatus(const ISimRenderContext* pContext)
{
  const int textHeight    = 10;
  const int textPosXCol1  = (int)845 + GetMenuWidth() + 5;
  const int textPosY      = (int)20-5;
  int textLine            = 1;
  IGDVFont& font          = pContext->GetWindow().GetFontInterface("", textHeight-3);

  CSimColor::SetColor(color_yellow, 0.3f);
  drawFilledRect(textPosXCol1-5, textPosY, textPosXCol1-5 + 75, textPosY + GetMenuHeight());
  CSimColor::SetColor(color_yellow);
  drawRect(      textPosXCol1-5, textPosY, textPosXCol1-5 + 75, textPosY + GetMenuHeight());

  font.BeginRender2D();
  /* General information */
  {
    CSimColor::SetTextColor(color_white, font);
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "MTS (%i,%i)", m_mouseInfo.current.x, m_mouseInfo.current.y); textLine++; textLine++;
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "ABS (%i,%i)", m_mouseInfo.current.x, m_mouseInfo.current.y); textLine++; textLine++;
    font.RenderTextf(textPosXCol1, textPosY + (textLine*textHeight), 1, "Wheel: %i", m_mouseInfo.current.wheel); textLine++; textLine++;
  }

  font.EndRender2D();
}

char* CSimhlaVis::GetSigStatus(AlgoSignalState_t SignalState)
{
  char* sigState;
  switch(SignalState)
  {
  case AL_SIG_STATE_INIT:
    sigState =  "Init";
    break;
  case AL_SIG_STATE_OK:
    sigState =  "Ok";
    break;
  case AL_SIG_STATE_INVALID:
    sigState = "Invalid";
    break;
  default:
    sigState = "Error";
    break;
  }
  return sigState;
}

void CSimhlaVis::UpdateCameraSimu(const reqHlaPrtList_t* rteInput)
{
  /*
  if(m_rpMonoCalibration.isDirty())
  {
    HLACamRotSetData( -rteInput->pMonoCalibration->sPoseCalibration.fPitch - CML_Deg2Rad(90.0f),
                      rteInput->pMonoCalibration->sPoseCalibration.fRoll,
                      rteInput->pMonoCalibration->sPoseCalibration.fYaw - CML_Deg2Rad(90.0f),
                      rteInput->pMonoCalibration->sPoseCalibration.fTx,
                      rteInput->pMonoCalibration->sPoseCalibration.fTy,
                      rteInput->pMonoCalibration->sPoseCalibration.fTz,
                      rteInput->pMonoCalibration->sIntrinsic.fFocalX,
                      rteInput->pMonoCalibration->sIntrinsic.fFocalY, 
                      rteInput->pMonoCalibration->sIntrinsic.fCenterX,
                      rteInput->pMonoCalibration->sIntrinsic.fCenterY 
                     );
  }
  */
}
