/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE

PACKAGENAME:               slate_io.c
DESCRIPTION:               Function Processing I/O-Wrapper Main Module

AUTHOR:                    $Author: Chittepu, Karthik (uids6470) $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.33 $

LEGACY VERSION:            Revision: 2.1.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h" /*  PRQA S 0380 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: This will not have any effect on functionality */

#if (FCT_CFG_SLATE_COMPONENT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup frame_io In-/Output
@ingroup frame
@brief          The In-/Output module contains functions that handle the updating of In- and Outputs as soon as 
                the Transformation matrices.\n\n
@description    The module provides the following functionalities:
                - Process the Input to SLATE : @ref SLATE_v_ProcessInput
                - Check the SLATE Ports and set up the necessary globals to enable SLATE to run properly: @ref SLATE_v_ProcessPorts
                - Fill the Signal headers of the SLATE provide ports after the subcomponents have been called: @ref SLATE_v_FillProPortHeaders
                - Return the current transformation matrix: @ref SLATE_p_GetTrafoMatrix2DCOFForward
                .
                If a new port shall be added, the following steps have to be executed:
                - Require Port:
                  - Add port to @ref reqSLATEPortList_t
                  - Add port to @ref t_SLATESyncRef
                  - Create a new global pointer of the same type as the port and define it in slate_obj_main.c. Declare it in slate.h
                  - Add the ports switch to the macro @ref SLATE_NOF_REQ_PORTS
                  - Add the port to the function @ref SLATE_v_SetupReqPortHandlers, where its PortHandler has to be filled.
                - Provide Port:
                  - Add port to @ref provSLATEPortList_t
                  - Create a new global pointer of the same type as the port and define it in slate_obj_main.c. Declare it in slate.h
                  - Add the ports switch to the macro @ref SLATE_NOF_PRO_PORTS
                  - Add the port to the function @ref SLATE_v_SetupProPortHandlers, where its PortHandler has to be filled:
                    - Decide which subcomponent the ProPorts signal state shall depend on.
                    - Decide which ReqPort shall fill the ProPorts signal header.
                    - Decide if the port shall be frozen (assign MeasFreezeAdress) or not (assign 0).
@{
                   
*/

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @brief    Fill the information of a provide port into a provide port handler.*/
#define SLATE_SET_PROPORT_HANDLER(pPROPORT, pREQPORT, pGLOBAL, pCOMPSTATE, uVERNUMBER, uFREEZEADDRESS, pREQPORTS, pPROPORTS, pHANDLERLIST)  \
  do{                                                                                                               \
  SLATEProPortHandler_t * pCurrProHandler = &((pHANDLERLIST)->ProPortHandler[(pHANDLERLIST)->uNofProPorts]);     \
  (pCurrProHandler)->pGlobal                = (void**)&(pGLOBAL);                                               \
  (pCurrProHandler)->pProNewSignalState     = (pCOMPSTATE);                                                     \
  (pCurrProHandler)->uProNewVersionNumber   = (uVERNUMBER);                                                     \
  (pCurrProHandler)->uMeasFreezeAddress     = (uFREEZEADDRESS);                                                 \
  if(((pREQPORTS) != NULL) && ((pREQPORT) != NULL))                                                             \
      {                                                                                                             \
      (pCurrProHandler)->pReqPortSignalHeader = &((pREQPORT)->sSigHeader);                                        \
      }                                                                                                             \
      if(((pPROPORTS) != NULL) && ((pPROPORT) != NULL))                                                             \
      {                                                                                                             \
      (pCurrProHandler)->uSize                = sizeof(*(pPROPORT));                                              \
      (pCurrProHandler)->pProPort             = (void*)(pPROPORT);                                                \
      (pCurrProHandler)->pProVersionNumber    = (uint32 *)&((pPROPORT)->uiVersionNumber);                         \
      (pCurrProHandler)->pProPortSignalHeader = &((pPROPORT)->sSigHeader);                                        \
      }                                                                                                             \
      (pHANDLERLIST)->uNofProPorts++;                                                                               \
  }while(0)		/* PRQA S 3456 */
  /* date: 2020-02-26, reviewer: Dhamodharan Subramanian, reason: Not safety critical. */

/*! @brief    Fill the information of a require port into a require port handler.*/
#define SLATE_SET_REQPORT_HANDLER(pREQPORT, pGLOBAL, pSYNCREF, pREQPORTS, pHANDLERLIST)                              \
  do{                                                                                                               \
  SLATEReqPortHandler_t * pCurrReqHandler = &((pHANDLERLIST)->ReqPortHandler[(pHANDLERLIST)->uNofReqPorts]);     \
  (pCurrReqHandler)->pGlobal                  = (void const **)&(pGLOBAL);                                      \
  (pCurrReqHandler)->pReqSignalHeaderSyncRef  = (pSYNCREF);                                                     \
  if(((pREQPORTS)!= NULL) && ((pREQPORT) != NULL))                                                              \
      {                                                                                                             \
      (pCurrReqHandler)->uSize                  = sizeof(*(pREQPORT));                                            \
      (pCurrReqHandler)->pReqPort               = (const void *)(pREQPORT);                                       \
      (pCurrReqHandler)->pReqPortSignalHeader   = &((pREQPORT)->sSigHeader);                                      \
      }                                                                                                             \
      (pHANDLERLIST)->uNofReqPorts++;                                                                               \
  }while(0)		/* PRQA S 3456 */
  /* date: 2020-02-26, reviewer: Dhamodharan Subramanian, reason: Not safety critical. */

/*! @brief    Fill the information of a require port that does not have a signal header into a require port handler.*/
#define SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER(pREQPORT, pGLOBAL, pSYNCREF, pREQPORTS, pHANDLERLIST)                 \
  do{                                                                                                               \
  SLATEReqPortHandler_t * pCurrReqHandler = &((pHANDLERLIST)->ReqPortHandler[(pHANDLERLIST)->uNofReqPorts]);     \
  (pCurrReqHandler)->pGlobal                  = (void const**)(&(pGLOBAL));                                     \
  (pCurrReqHandler)->pReqSignalHeaderSyncRef  = (pSYNCREF);                                                     \
  if(((pREQPORTS)!= NULL) && ((pREQPORT) != NULL))                                                              \
      {                                                                                                             \
      (pCurrReqHandler)->uSize                  = sizeof(*(pREQPORT));                                            \
      (pCurrReqHandler)->pReqPort               = (void const *)(pREQPORT);                                       \
      (pCurrReqHandler)->pReqPortSignalHeader   = NULL;                                                           \
      }                                                                                                             \
      (pHANDLERLIST)->uNofReqPorts++;                                                                               \
  }while(0)		/* PRQA S 3456 */
  /* date: 2020-02-26, reviewer: Dhamodharan Subramanian, reason: Not safety critical. */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/


SET_MEMSEC_VAR(SLATETrMat2DForward)
static GDBTrafoMatrix2D_t SLATETrMat2DForward;    /*!< forward motion transformation Matrix */
SET_MEMSEC_VAR(SLATETrMat2DBackward)
static GDBTrafoMatrix2D_t SLATETrMat2DBackward;   /*!< backward motion transformation Matrix */


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void SLATE_v_CalcMotionMatrices(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);
#if (SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
static boolean SLATE_b_CheckPortUpdated( AlgoDataTimeStamp_t const * const pInputPortMeasCycle, 
                                                 sMeasCycleMonitor * const pLastMeasCycle,
                                                           float32   const fTargetCycleTime, 
                                                             uint8         iAcceptableDrops);
#endif
static void SLATE_v_SetSignalHeader(   SignalHeader_t       * const pDestSignalHeader, 
                                       SignalHeader_t const * const pSourceSignalHeader, 
                                       AlgoSignalState_t               eSignalState);
static void SLATE_v_SetSignalHeaderError(SignalHeader_t * const pSignalHeader);
static void SLATE_v_SetupReqPortHandlers( reqSLATEPortList_t const * const pRequirePorts,
                                          SLATEPortHandlerList_t   * const pPortHandlerList);

static void SLATE_v_SetupProPortHandlers(    provSLATEPortList_t const * const pProvidePorts,
                                              reqSLATEPortList_t const * const pRequirePorts,
                                          SLATEPortHandlerList_t       * const pPortHandlerList);
static boolean SLATE_b_CheckServiceFunctions(AS_t_ServiceFuncts const * const pServiceFuncts);
static boolean SLATE_b_SetupPorts(SLATEPortHandlerList_t * const pPortHandlerList);
static boolean SLATE_b_PortSpecificHandling(  reqSLATEPortList_t const * const pRequirePorts, 
                                             provSLATEPortList_t const * const pProvidePorts);
/*****************************************************************************
  FUNCTION
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         SLATE_v_InitReqPortHandlerListMeasCycleData                                                                   */ /*!

  @brief                Resets the elements of the meascycle monitor in the req port handler list.

  @description          This function sets all the elements of the meas cycle monitor in the req port
                        to 0. These elements should be initialized only in the INIT mode with 
                        b_KeepMeasCycleData set on FALSE.
                        @startuml
                        Partition SLATE_v_InitReqPortHandlerListMeasCycleData  {
                        Start
                             partition "Execute for all elements of the MeasCycleMonitor in the Req port" {
                              if(Kept Meas Cycle Data is FALSE) then (Yes)
                                      -Set last update counter and time stamp for all elements of MeasCycle monitor to 0
                              Endif
                              }
                        } 
                        end
                        @enduml


  @return               void

  @param[in]            b_KeepMeasCycleData : Flag indicating whether the MeasCycle information in the PortHandler 
                                             shall be deleted (FALSE) or not (TRUE).

  @glob_in              @ref t_SLATEPortHandlerList
  @glob_out             @ref t_SLATEPortHandlerList

  @c_switch_part        -
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT

  @pre                  -
  @post                 -

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
extern void SLATE_v_InitReqPortHandlerListMeasCycleData(boolean b_KeepMeasCycleData)
{
  SLATEPortHandlerList_t *pPortHandlerList = &t_SLATEPortHandlerList;
  uint8 u_PortNo;
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  for (u_PortNo = 0u; u_PortNo < SLATE_NOF_REQ_PORTS; u_PortNo++)/* PRQA S 4548 */ 
  {
    /*MeasCycle data has to be kept over the cycles. It shall only be reseted in case of an external init*/
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Integral promotion is fine  */
    if (b_KeepMeasCycleData == FALSE)/* PRQA S 1863 */
    {
      pPortHandlerList->ReqPortHandler[u_PortNo].MeasCycleMonitor.uiLastUpdateCounter  = 0u;
      pPortHandlerList->ReqPortHandler[u_PortNo].MeasCycleMonitor.uiTimeStamp          = 0u;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         SLATE_v_InitPortHandlerList                                                                   */ /*!

  @brief                Resets all elements in the Port handler list.

  @description          Sets all elements of the port handler list to 0. Keeps the information of 
                        the MeasCycleMonitoring if desired (Flag b_KeepMeasCycleData on TRUE). \n
                        This function should be called each cycle at the beginning of the PortProcessing.
                       @startuml
                       Partition SLATE_v_InitPortHandlerList  {
                       Start
                        partition "Execute for all Required ports" {
                          -Set all elements of Required ports to 0
                        }
                        partition "Execute for all Provide ports" {
                          -Set all elements of Provide ports to 0
                        }
                       End
                       } 
                       @enduml


  @return               void

  @param[in]            -

  @glob_in              @ref t_SLATEPortHandlerList
  @glob_out             @ref t_SLATEPortHandlerList

  @c_switch_part        -
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT

  @pre                  -
  @post                 -

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
extern void SLATE_v_InitPortHandlerList(void)
{
  SLATEPortHandlerList_t *pPortHandlerList = &t_SLATEPortHandlerList;
  uint8 uPortNo;
  pPortHandlerList->uNofProPorts = 0u;
  pPortHandlerList->uNofReqPorts = 0u;
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  for (uPortNo = 0u; uPortNo < SLATE_NOF_REQ_PORTS; uPortNo++)/* PRQA S 4548 */ 
  {
    pPortHandlerList->ReqPortHandler[uPortNo].pGlobal                  = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqPort                 = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqPortSignalHeader     = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].pReqSignalHeaderSyncRef  = NULL;
    pPortHandlerList->ReqPortHandler[uPortNo].uSize                    =   0u;
  }
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  for (uPortNo = 0u; uPortNo < SLATE_NOF_PRO_PORTS; uPortNo++)/* PRQA S 4548 */ 
  {
    pPortHandlerList->ProPortHandler[uPortNo].pGlobal                  = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProNewSignalState       = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProPort                 = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProPortSignalHeader     = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pProVersionNumber        = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].pReqPortSignalHeader     = NULL;
    pPortHandlerList->ProPortHandler[uPortNo].uMeasFreezeAddress       =   0u;
    pPortHandlerList->ProPortHandler[uPortNo].uProNewVersionNumber     =   0u;
    pPortHandlerList->ProPortHandler[uPortNo].uSize                    =   0u;
  }
}

/*************************************************************************************************************************
  Functionname:         SLATE_v_SetupReqPortHandlers                                                                  */ /*!

  @brief                Sets up the port handlers for all require ports.

  @description          Sets up the handlers of all require ports by executing macros (see @ref SLATE_SET_REQPORT_HANDLER 
                        / @ref SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER) to add the following information to the handler:
                        - Global variable for component internal port access.
                        - Pointer to the SyncRef structure that corresponds to the require port.
                        .
                        More information regarding the Port Handler concept can be found here: @ref SLATE_v_ProcessPorts.
                       @startuml
                       Partition SLATE_v_SetupReqPortHandlers  {
                       Start
                           partition "Execute for each require port" {
                            if(Required ports is not NULL) then (Yes)
                               - Fill the information of a require port into a require port handler
                            endif
                           }
                       End
                       }
                       @enduml


  @return               void

  @param[in]            pRequirePorts    : Pointer to a structure containing all require port pointers.
  @param[in,out]        pPortHandlerList : Pointer to a list with all port handlers.

  @glob_in              @ref pSLATE_SenCtrlData       \n
                        @ref pSLATE_EgoDynObjSync     \n
                        @ref pSLATE_EgoDynRaw         \n
                        @ref pSLATE_EgoStaticData     \n
                        @ref pSLATE_EmFctCycleMode    \n
                        @ref pSLATE_EmGenObjList      \n
                        @ref pSLATE_EmCustObjList     \n
                        @ref pSLATE_EmARSObjList      \n
                        @ref pSLATE_EmCamObjList      \n
                        @ref pSLATE_EmObjList         \n
                        @ref pSLATE_MovObjTraces      \n
                        @ref pSLATE_PerfDegrData      \n
                        @ref pSLATE_RoadData          \n
                        @ref pSLATE_RSPContextData    \n
                        @ref pSLATE_CustomInput       \n
                        @ref pSLATE_CameraObjData     \n
                        @ref pSLATE_AlignmentMonInput \n
                        @ref pSLATE_ME_in             \n
                        @ref pSLATE_BswAlgoParameters \n
                        @ref pSLATE_NaviData          \n
                        @ref pSLATE_CamLaneData       \n
                        @ref pSLATE_CamSLAInputData

  @glob_out             None

  @c_switch_part        @ref FCT_CFG_USE_BASECTRLDATA               \n
                        @ref FCT_CFG_EM_FCT_CYCLEMODE               \n
                        @ref FCT_CFG_OBJECT_LIST_PROC               \n
                        @ref FCT_USE_EM_GENERIC_OBJECT_LIST         \n
                        @ref FCT_USE_EM_CUSTOM_OBJECT_LIST          \n
                        @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST        \n
                        @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST        \n
                        @ref SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES  \n
                        @ref FCT_CFG_SIGNAL_PERF_MONITORING         \n
                        @ref FCT_CFG_ROAD_INPUT                     \n
                        @ref FCT_CFG_RSP_CONTEXT_INPUT              \n
                        @ref FCT_CFG_CUSTOM_IO_INTERFACE            \n
                        @ref FCT_CFG_CAMERA_OBJECT_DETECTION        \n
                        @ref FCT_CFG_ALIGNMENT_MONITORING_INPUT     \n
                        @ref FCT_CFG_INCLUDE_UNUSED_INTF            \n
                        @ref FCT_CFG_ME_INPUT_FOR_DEBUG             \n
                        @ref FCT_CFG_BSW_ALGO_PARAMS                \n
                        @ref SLATE_CFG_SIMPLE_NAVI_INTERFACE        \n
                        @ref SLATE_CFG_CAM_LANE_INTERFACE           \n
                        @ref FCT_CFG_LONG_CTRL_SLA_SUPPORT

  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT

  @pre                  Require port information filled in port handler 
  @post                 None

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SLATE_v_SetupReqPortHandlers( reqSLATEPortList_t const * const pRequirePorts,
                                          SLATEPortHandlerList_t   * const pPortHandlerList)
{
/* PRQA S 0314 TYPE_CAST_TO_VOID_REQPORT */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Its safe to convert a pointer-to-object to a pointer-to-void  */
/* PRQA S 0310 TYPE_CAST_REQPORT */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Type casting follows allignment requirement. */
  /*                                      |                  Require Port                |     Global Pointer     |          Pointer to SyncRef         |Require Ports |Port handler List|*/
#if (FCT_CFG_USE_BASECTRLDATA)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pSenCtrlData                  , pSLATE_SenCtrlData      , &(t_SLATESyncRef.SenCtrlData)      , pRequirePorts, pPortHandlerList);
#else
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pSenCtrlData                  , pSLATE_SenCtrlData      , &(t_SLATESyncRef.SenCtrlData)      , pRequirePorts, pPortHandlerList);
#endif
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEgoDynObjSync                , pSLATE_EgoDynObjSync    , &(t_SLATESyncRef.EgoDynObjSync)    , pRequirePorts, pPortHandlerList);
#endif
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEgoDynRaw                    , pSLATE_EgoDynRaw        , &(t_SLATESyncRef.EgoDynRaw)        , pRequirePorts, pPortHandlerList);
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEgoStaticData                , pSLATE_EgoStaticData    , &(t_SLATESyncRef.EgoStaticData)    , pRequirePorts, pPortHandlerList);
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER   (pRequirePorts->pEmFctCycleMode               , pSLATE_EmFctCycleMode   , &(t_SLATESyncRef.EmFctCycleMode)   , pRequirePorts, pPortHandlerList);
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)

  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEmGenObjList                 , pSLATE_EmGenObjList     , &(t_SLATESyncRef.EmGenObjList)     , pRequirePorts, pPortHandlerList);
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEmCustObjList                , pSLATE_EmCustObjList    , &(t_SLATESyncRef.EmCustObjList)    , pRequirePorts, pPortHandlerList);
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEmARSObjList                 , pSLATE_EmARSObjList     , &(t_SLATESyncRef.EmARSObjList)     , pRequirePorts, pPortHandlerList);
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEmCamObjList                 , pSLATE_EmCamObjList     , &(t_SLATESyncRef.EmCamObjList)     , pRequirePorts, pPortHandlerList);
#endif

#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pMovObjTraces                 , pSLATE_MovObjTraces     , &(t_SLATESyncRef.MovObjTraces)     , pRequirePorts, pPortHandlerList);
#endif
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pPerfDegrData                 , pSLATE_PerfDegrData     , &(t_SLATESyncRef.PerfDegrData)     , pRequirePorts, pPortHandlerList);
#endif
#if (FCT_CFG_ROAD_INPUT)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pRoadData                     , pSLATE_RoadData         , &(t_SLATESyncRef.RoadData)         , pRequirePorts, pPortHandlerList);
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pRSPContextData               , pSLATE_RSPContextData   , &(t_SLATESyncRef.RSPContextData)   , pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pFCTCustomInput               , pSLATE_CustomInput      , &(t_SLATESyncRef.FCTCustomInput)   , pRequirePorts, pPortHandlerList);
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) &&  (!FCT_USE_EM_CUSTOM_OBJECT_LIST)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pCameraObjData                , pSLATE_CameraObjData    , &(t_SLATESyncRef.CameraObjData)    , pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pAlignmentMonInput            , pSLATE_AlignmentMonInput, &(t_SLATESyncRef.AlignmentMonInput), pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pME_in                        , pSLATE_ME_in            , &(t_SLATESyncRef.ME_in)            , pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER   (pRequirePorts->pBswAlgoParameters            , pSLATE_BswAlgoParameters, &(t_SLATESyncRef.BswAlgoParameters), pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pNaviData                     , pSLATE_NaviData         , &(t_SLATESyncRef.NaviData)         , pRequirePorts, pPortHandlerList);
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pEmFusionObjList              , pSLATE_FusionObjList    , &(t_SLATESyncRef.EmFusionObjList)  , pRequirePorts, pPortHandlerList);
#endif
#if ((SLATE_CFG_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pCamLaneData                  , pSLATE_CamLaneData      , &(t_SLATESyncRef.CamLaneData)      , pRequirePorts, pPortHandlerList);
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pTSAInputData                 , pSLATE_TSAInputData     , &(t_SLATESyncRef.CamTSAInputData)  , pRequirePorts, pPortHandlerList);
#elif ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pCamSLAInputData              , pSLATE_CamSLAInputData  , &(t_SLATESyncRef.CamSLAInputData)  , pRequirePorts, pPortHandlerList);
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
  SLATE_SET_REQPORT_HANDLER                (pRequirePorts->pLongCtrlResp                 , pSLATE_LongCtrlResp     , &(t_SLATESyncRef.LongCtrlResp)     , pRequirePorts, pPortHandlerList);
#endif /* ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)) */
}// PRQA S 7004
 /* date: 2018-01-02, reviewer: Shruthi Ramaiah, reason: Cyclometric complexity, Not safety critical */
/* PRQA L:TYPE_CAST_REQPORT */
/* PRQA L:TYPE_CAST_TO_VOID_REQPORT */

/*************************************************************************************************************************
  Functionname:         SLATE_v_SetupProPortHandlers                                                                  */ /*!

  @brief                Sets up the port handlers for all provide ports.

  @description          Sets up the handlers of all provide ports by executing macros (see @ref SLATE_SET_PROPORT_HANDLER) 
                        to add the following information to the handler:
                        - Source signal header for the provide port signal header.
                        - Global variable for component internal port access.
                        - Component state to set the provide port signal header state.
                        - Interface version of the provide port.
                        - Address for a possible meas freeze.
                        .
                        More information regarding the Port Handler concept can be found here: @ref SLATE_v_ProcessPorts.
                       @startuml
                       Partition SLATE_v_SetupProPortHandlers  {
                       Start
                       	partition "Execute for each provide port" {
                       		if(Required ports is not NULL) then (Yes)
                       			- Assign Required ports signal header to the provide ports signal header 
                       		endif
                       		If(Provide ports is not null) then (Yes)
                       		    - Fill the information of a provide port into a provide port handler.
                       		endif
                       		}
                       End
                       }
                       @enduml

  
  @return               -

  @param[in]            pProvidePorts :     Pointer to a structure containing all provide port pointers.
  @param[in]            pRequirePorts :     Pointer to a structure containing all require port pointers.
  @param[in,out]        pPortHandlerList :  Pointer to a list with all port handlers.

  @glob_in              @ref pSLATE_ErrorOut            \n
                        @ref pSLATE_SenCompState        \n
                        @ref pSLATE_PubFctObjList       \n
                        @ref pSLATE_CustomOutput        \n
                        @ref pSLATE_FCTSenBusDebugData  \n
                        @ref pSLATE_AccOOIData          \n
						@ref pSLATE_TJAOOIData          \n
						@ref pSLATE_HC_Data             \n
                        @ref pSLATE_HC_Data             \n
						@ref pSLATE_SPM_Data            \n
						@ref pSLATE_CD_Data             \n
						@ref pSLATE_SLAData
						
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_USE_ALGOCOMPSTATE           \n
                        @ref FCT_CFG_ERROR_OUTPUT_SEN            \n
						@ref FCT_CFG_OBJECT_LIST_PROC            \n
						@ref FCT_CFG_ASSESSED_OBJ_OUT_INTF       \n
						@ref FCT_CFG_CUSTOM_IO_INTERFACE         \n
						@ref FCT_CFG_INCLUDE_UNUSED_INTF         \n
                        @ref FCT_CFG_SHORT_RANGE_FUNCTIONS       \n
						@ref FCT_CFG_USE_BUS_DEBUG               \n
						@ref FCT_CFG_SEN2VEH_ACC_OOI_PORT        \n
						@ref FCT_CFG_SEN2TJA_ACC_OOI_PORT        \n
						@ref FCT_CFG_LOHP_COMPONENT              \n
						@ref FCT_CFG_SIGNAL_PERF_MONITORING      \n
						@ref FCT_CFG_COLLISION_DETECTION         \n
						@ref FCT_CFG_SLA_FEATURE
						
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT

  @pre                  None
  @post                 Pro port information filled in PortHandler

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SLATE_v_SetupProPortHandlers(    provSLATEPortList_t const * const pProvidePorts,
                                             reqSLATEPortList_t const * const pRequirePorts,
                                          SLATEPortHandlerList_t       * const pPortHandlerList)
{
/* PRQA S 0314 TYPE_CAST_TO_VOID_PROPORT */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Its safe to convert a pointer-to-object to a pointer-to-void  */
/* PRQA S 0310 TYPE_CAST_PROPORT */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Type casting follows allignment requirement. */
  /*                        |         Provide port               |Require Port (for Sig Header) |  Global Variable          |          Rel State         |     Version Number           |Measfreeze address (0:No freeze) | Require Ports | Provide Ports | PortHandlerList  |*/
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pt_SLATEErrorOut     , pRequirePorts->pEmGenObjList , pSLATE_ErrorOut           , &(t_SLATEFrame.SLATEState) , FCT_SEN_ERROR_OUT_INTFVER    , FCT_MEAS_ID_SLATE_ERRORDATA     , pRequirePorts , pProvidePorts , pPortHandlerList );
#endif 
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pSenCompState        , pRequirePorts->pEmGenObjList , pSLATE_SenCompState       , &(t_SLATEFrame.SLATEState) , COMP_STATE_INTFVER           , FCT_MEAS_ID_ACCSEN_COMP_STATE   , pRequirePorts , pProvidePorts , pPortHandlerList );
#endif
#if ((FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF))
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pPubFctObj           , pRequirePorts->pEmGenObjList , pSLATE_PubFctObjList      , &(t_SLATEFrame.SLATEState) , FCT_ASSESSED_OBJ_INTFVER     , 0u                               , pRequirePorts , pProvidePorts , pPortHandlerList ); 
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF) || (FCT_CFG_SHORT_RANGE_FUNCTIONS))
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pFCTCustomOutput     , pRequirePorts->pEmGenObjList , pSLATE_CustomOutput       , &(t_SLATEFrame.SLATEState) , FCT_CUSTOM_OUTPUT_INTFVER    , 0u                               , pRequirePorts , pProvidePorts , pPortHandlerList ); 
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pFCTSenBusDebugData  , pRequirePorts->pEmGenObjList , pSLATE_FCTSenBusDebugData , &(t_SLATEFrame.SLATEState) , DUMMY_INTERFACE_VERSION      , 0u                               , pRequirePorts , pProvidePorts , pPortHandlerList ); 
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pFCTAccOOIData       , pRequirePorts->pEmGenObjList , pSLATE_AccOOIData         , &(t_SLATEFrame.SLATEState) , FCT_SEN_ACC_OOI_INTFVER      , FCT_MEAS_ID_FCT_SEN_ACC_OOI     , pRequirePorts , pProvidePorts , pPortHandlerList ); 
#endif
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pFCTTJAOOIData       , pRequirePorts->pEmGenObjList , pSLATE_TJAOOIData         , &(t_SLATEFrame.SLATEState) , FCT_TJA_TARGET_OBJ_INTFVER   , FCT_MEAS_ID_TJA_TARGET_OBJ      , pRequirePorts , pProvidePorts , pPortHandlerList ); 
#endif
#if (FCT_CFG_LOHP_COMPONENT)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pSLATE_HC_Data       , pRequirePorts->pEmGenObjList , pSLATE_HC_Data            , &(t_SLATEFrame.SLATEState) , DUMMY_INTERFACE_VERSION_HC   , FCT_MEAS_ID_SEN_SLATE_HC_DATA   , pRequirePorts , pProvidePorts , pPortHandlerList ); /* PRQA S 0499, 4542 ,4543*/
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason:  Left shift is safe due to integral promotion   */
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pSLATE_SPM_Data      , pRequirePorts->pEmGenObjList , pSLATE_SPM_Data           , &(t_SLATEFrame.SLATEState) , (uint32)DUMMY_INTERFACE_VERSION_SPM  , 0u                               , pRequirePorts , pProvidePorts , pPortHandlerList );/* PRQA S 0499, 4542,4543 */
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason:  Left shift is safe due to integral promotion   */
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pSLATE_CD_Data       , pRequirePorts->pEmGenObjList , pSLATE_CD_Data            , &(t_SLATEFrame.SLATEState) , (uint32)DUMMY_INTERFACE_VERSION_CD   , 0u                               , pRequirePorts , pProvidePorts , pPortHandlerList );/* PRQA S 0499,4542,4543 */
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason:  Left shift is safe due to integral promotion   */
#endif
#if (FCT_CFG_SLA_FEATURE)
  SLATE_SET_PROPORT_HANDLER (pProvidePorts->pSLAData             , pRequirePorts->pEmGenObjList , pSLATE_SLAData            , &(t_SLATEFrame.SLATEState) , SLAData_INTFVER              , FCT_MEAS_ID_SLADATA             , pRequirePorts , pProvidePorts , pPortHandlerList ); 
#endif

}/* PRQA S 7004 */
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/
/* PRQA L:TYPE_CAST_PROPORT */
/* PRQA L:TYPE_CAST_TO_VOID_PROPORT */
/*************************************************************************************************************************
  Functionname:         SLATE_v_SetSignalHeader                                                                      */ /*!

  @brief                Copies information from one signal header to another. 

  @description          Copies Time Stamp and Measurement counter from pSourceSignalHeader to pDestSignalHeader. 
                        Sets the cycle counter of pDestSignalHeader to the Cycle counter of @ref t_SLATEFrame and its \n
                        Signal state to a given signal state.
						@startuml
                        Partition SLATE_v_SetSignalHeader  {
                        Start
                        - Copies Time Stamp and Measurement counter from pSourceSignalHeader to pDestSignalHeader
                        End
                        }
                        @enduml


  @return               -

  @param[in,out]        pDestSignalHeader   : The signal header to be filled.
  @param[in]            pSourceSignalHeader : The source signal header.
  @param[in]            eSignalState        : The signal state that shall be written to the DestSignal header.

  @glob_in              @ref t_SLATEFrame
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT

  @pre                  Assure that pointers are valid.
  @post                 -

  @InOutCorrelation     see description

  @author               Gergely Ungvary
*************************************************************************************************************************/
static void SLATE_v_SetSignalHeader(   SignalHeader_t       * const pDestSignalHeader, 
                                      SignalHeader_t const * const pSourceSignalHeader, 
                                   AlgoSignalState_t               eSignalState)
{
  pDestSignalHeader->uiTimeStamp           = pSourceSignalHeader->uiTimeStamp;
  pDestSignalHeader->uiMeasurementCounter  = pSourceSignalHeader->uiMeasurementCounter;
  pDestSignalHeader->uiCycleCounter        = t_SLATEFrame.uiCycleCounter;
  pDestSignalHeader->eSigStatus            = eSignalState;
}

/*************************************************************************************************************************
  Functionname:         SLATE_v_SetSignalHeaderError                                                                 */ /*!

  @brief                Resets the Signal Header of a signal for which an error was detected. 
                        The current cycle counter is kept.

  @description          Init the @ref SignalHeader_t structure with default values for SLATE. These default 
                        values are the cycle counter of SLATE and the signal state @ref AL_SIG_STATE_INVALID. \n
                        Timestamp and measurement counter are set to zero.
						@startuml
                        Partition SLATE_v_SetSignalHeaderError {
                        Start
                        - Resets the Signal Header of a signal for which an error was detected. 
                        -The current cycle counter is kept
                        end
                        }
                        @enduml


  @return               -

  @param[in,out]        pSignalHeader : Header of a signal for which an error was detected.

  @glob_in              @ref t_SLATEFrame : uiCycleCounter, used to set signal header cycle counter
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT

  @pre                  -
  @post                 -

  @InOutCorrelation     see description

  @author               Gergely Ungvary
*************************************************************************************************************************/
static void SLATE_v_SetSignalHeaderError(SignalHeader_t * const pSignalHeader)
{
  pSignalHeader->uiTimeStamp           = 0u;
  pSignalHeader->uiMeasurementCounter  = 0u;
  pSignalHeader->uiCycleCounter        = t_SLATEFrame.uiCycleCounter;
  pSignalHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

/*************************************************************************************************************************
  Functionname:         SLATE_b_CheckServiceFunctions                                                                 */ /*!

  @brief                Checks the Service function structure for NULL pointers

  @description          Checks if the pointer to the service function structure is valid. If this is the case,
                        the Pointers inside of the structure are checked.
                       @startuml 
						Partition SLATE_b_CheckServiceFunctions {
						start
						if(Pointer to service function structure is Valid?) then (Yes)
						partition "Execute for each service function pointer" {
						if(Pointer is NULL pointer?) then (Yes)
							-Raise error flag
						else(No)
						endif
						}
						else(No)
						-Raise error flag
						endif
						-Return Error Flag
						Stop
						}
						@enduml


  @return               boolean b_Error : True if error was detected.

  @param[in]            pServiceFuncts : Pointer to a structure containing all service function pointers.

  @glob_in              None
  @glob_out             @ref pSLATE_ServiceFuncts

  @c_switch_part        @ref FCT_CFG_USE_DEM \n
                        @ref FCT_CFG_RTA_PROFILING \n
                        @ref FCT_CFG_USE_FREEZE_CYCLE_START \n
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT \n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean SLATE_b_CheckServiceFunctions(AS_t_ServiceFuncts const * const pServiceFuncts)// PRQA S 3219
/* date: 2018-03-22, reviewer: Ravikiran Gurrala, reason: It is used under a switch*/
{
  boolean b_Error = FALSE;

  if(pServiceFuncts != NULL)
  {
    b_Error |= (boolean)(pServiceFuncts->pfMeasFreeze == NULL);/* PRQA S 2986 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: This will not have any effect on functionality */
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    b_Error |= (boolean)(pServiceFuncts->pfMeasStartFuncCycle == NULL);
#endif
#if (FCT_CFG_RTA_PROFILING)
    b_Error |= (boolean)(pServiceFuncts->pfRTAAlgoServiceAddEvent == NULL);
#endif
#if (FCT_CFG_USE_DEM)
    b_Error |= (boolean)(pServiceFuncts->pfDem_SetEventStatus == NULL);
#endif
  }
  else
  {
    SLATE_ASSERT(FALSE);
    b_Error = TRUE;
  }

  return b_Error;
}

/*************************************************************************************************************************
  Functionname:         SLATE_b_SetupPorts                                                                            */ /*!

  @brief                Uses the port handler structure to set up require and provide ports as soon as related structures 
                        at the beginning of each cycle.

  @description          This function loops through the previously filled PortHandler structure. It checks and 
                        sets up all Ports. The following actions are executed for valid require ports:
                        - Write port pointer to global variable for component internal access.
                        - Copy port signal header to the SyncRef structure for simulation purposes.
                        - Check signal status for the state INVALID
                        - Check if port has been updated within the required time
                        .
                        Most of the provide port handling has to be done after the call of the subcomponents 
                        (see @ref SLATE_v_FillProPortHeaders). Only one action has to executed before:
                        - Write port pointer to global variable for component internal access.
                        .
                        If one of the given ports is a NULL pointer or the require port signal check failed, 
                        the function returns an error.
                        @startuml 
                         Partition SLATE_b_SetupPorts {
                         start
                         if(Have all require and provide ports been written into the Handler List?) Then (Yes)
                         else(No)
                         -Raise Error flag and display warning
                         endif
                         partition "Execute for all Require Ports in the SLATE Port Handler List"{
                         if(Require Port is NULL pointer?) then (No)
                         -Set pointer of global to corresponding port pointer
                         if(SignalHeader is Null Pointer?) then (Yes)
                         -Reset corresponding SyncRef structure <b>SLATE_v_SetSignalHeaderError</b> >
                         note left
                         Some Ports do not have a Signal header
                         If this is the case, the signal header pointer in the Port Handler is set explicitly to NULL. This is no error case!
                         end note
                         else(No)
                         -Copy Port Signal Header to corresponding SyncRef Structure;
                         partition #LightBlue **SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK** {
                         -Check Signal Header for Signal Status other than **INVALID**
                         -Check if ports have been updated within the required time <b>SLATE_b_CheckPortUpdate</b> >
                         if(Both Checks passed?) then (Yes)
                         else(No)
                         -Raise **Error flag**
                         endif
                         }
                         endif
                         else(Yes)
                         -Reset corresponding SyncRef structure:<b>SLATE_v_SetSignalHeaderError</b> >
                         -Set corresponding global to NULL pointer
                         -Raise **Error flag** and display warning **SLATE_ASSERT** |
                         endif
                         }
                         partition "Execute for all Provide Ports in the t_SLATEPortHandlerList"{
                         note left
                         Further Provide port handling has to be done after the 
                         call of the subcomponents. (see **SLATE_v_FillProPortHeaders**)
                         end note
                         if(Provide Port is NULL pointer?) then (No)
                         -Set pointer of global to corresponding port pointer
                         else(Yes)
                         -Set corresponding global to NULL pointer
                         -Raise **Error flag** and display warning:<b>SLATE_ASSERT</b> |
                         endif
                         }
                         Stop
                         }
                         @enduml


  @return               boolean b_Error : Error flag, True if error was detected.

  @param[in,out]        pPortHandlerList : List containing Port handlers for all require and provide ports.

  @glob_in              -
  @glob_out             -

  @c_switch_part        @ref SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK\n
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT\n

  @pre                  t_SLATEPortHandlerList has been filled by calls to the functions 
                        @ref SLATE_v_SetupReqPortHandlers and @ref SLATE_v_SetupProPortHandlers
  @post                 None

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean SLATE_b_SetupPorts(SLATEPortHandlerList_t * const pPortHandlerList)
{
  uint8 u_PortNo = 0u;
  boolean b_Error = FALSE;
#if (SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
  boolean b_SigHeaderError = FALSE;
#endif
  SLATEReqPortHandler_t * pt_CurrReqPort;
  SLATEProPortHandler_t * pt_CurrProPort;

    /*Check if number of ports matches number of activated ports. Can help to detect unchecked ports.
  This is done in two separate "ifs" to distinguish between the asserts for Pro and Req Ports*/
  if(pPortHandlerList->uNofProPorts != SLATE_NOF_PRO_PORTS)/* PRQA S 4548 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  {
    SLATE_ASSERT(FALSE);
    b_Error = TRUE;
  }
  if(pPortHandlerList->uNofReqPorts != SLATE_NOF_REQ_PORTS)/* PRQA S 4548 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  {
    SLATE_ASSERT(FALSE);
    b_Error = TRUE;
  }

  /*Setup Require Ports*/
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  for (u_PortNo = 0u; u_PortNo < MIN(pPortHandlerList->uNofReqPorts, SLATE_NOF_REQ_PORTS); ++u_PortNo)/* PRQA S 4548 */
  {
    pt_CurrReqPort = &(pPortHandlerList->ReqPortHandler[u_PortNo]);
    if(pt_CurrReqPort->pReqPort!=NULL)
    {
      *(pt_CurrReqPort->pGlobal) = pt_CurrReqPort->pReqPort;

      /*Check signal header*/
      if(pt_CurrReqPort->pReqPortSignalHeader != NULL)
      {
        *(pt_CurrReqPort->pReqSignalHeaderSyncRef)  = *(pt_CurrReqPort->pReqPortSignalHeader);
#if (SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
        b_SigHeaderError |= (boolean)(pt_CurrReqPort->pReqPortSignalHeader->eSigStatus == AL_SIG_STATE_INVALID);
        b_SigHeaderError |= SLATE_b_CheckPortUpdated( &(pt_CurrReqPort->pReqPortSignalHeader->uiTimeStamp), 
          &(pt_CurrReqPort->MeasCycleMonitor), 
          FCT_SEN_CYCLE_TIME, 
          SLATE_INPUT_ACCEPTABLE_DROPS);
#endif
      }
      else
      { /* Pointer is set to 0 if a port does not have a signal header. This is not an error case! */
        SLATE_v_SetSignalHeaderError(pt_CurrReqPort->pReqSignalHeaderSyncRef);
      }
    }
    else
    {
      SLATE_v_SetSignalHeaderError(pt_CurrReqPort->pReqSignalHeaderSyncRef);
      *(pt_CurrReqPort->pGlobal) = NULL;
      b_Error = TRUE;
      SLATE_ASSERT(FALSE);
    }
  }

  /*Set Up Provide Ports*/
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  for (u_PortNo = 0u; u_PortNo < MIN(pPortHandlerList->uNofProPorts,SLATE_NOF_PRO_PORTS); ++u_PortNo)/* PRQA S 4548 */
  {
    pt_CurrProPort = &(pPortHandlerList->ProPortHandler[u_PortNo]);
    if(pt_CurrProPort->pProPort!=NULL)
    {
      *(pt_CurrProPort->pGlobal)            = pt_CurrProPort->pProPort;
    }
    else
    {
      *(pt_CurrProPort->pGlobal) = NULL;
      b_Error = TRUE;
      SLATE_ASSERT(FALSE);
    }
  }

#if (SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
  /*If Sigstate check is active: treat it like a pointer error*/
  b_Error |= b_SigHeaderError;
#endif

  return b_Error;
}

  /*************************************************************************************************************************
  Functionname:         ACDC_b_PortSpecificHandling                                                                  */ /*!

  @brief                Handles special logic that shall only be executed for selected ports.

  @description          For certain ports special checks shall be executed. Therefore this function is used.
                        As at this point in the cycle it is not clear if the ports are valid, all port checks \n
                        have to be done again for each port here. Also the switches that de-/activate a port have 
                        to be repeated here.\n
                        Currently the following ports are handled different from the generic port handling:
                        - **EmGenObjList:** \n
                          If @ref ACDC_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK is active, all signal states are checked 
                          in the function @ref ACDC_b_SetupPorts. If a signal state is found to be invalid, an error \n
                          is triggered. Even if this switch is invalid, the GenObjectList Signal state shall be checked 
                          for validity. If it is found to be invalid, all subcomponents are called in state 
                          @ref COMP_STATE_NOT_INITIALIZED
                        - **EgoDynRaw:** \n
                          The VDY Signal EgoDynRaw has a special structure State, that indicates the current quality 
                          of its content. This quality shall be checked before the port is used.\n
                          Therefore a global counter @ref uiVDYSigErrorCnt is increased if a state is found to be invalid.
                          If the counter exceeds a given limit (@ref ACDC_MAX_VDY_SIG_ERRORS) the State of the CD subcomponent \n
                          (@ref CDState) is set to COMP_STATE_TEMPORARY_ERROR. The consequence is a call of CD in State 
                          @ref COMP_STATE_NOT_INITIALIZED
                          and an invalidation of all output ports.
                          .
                        <b>ATTENTION:</b> Try to keep this function as small as possible. The ports should be handled 
                        as generic as possible to simplify maintainability.
                        @startuml 
                        Partition ACDC_b_PortSpecificHandling  {
                        start
                        if(Pointer to Require Ports is valid?) then (Yes)
                        if(Pointer to GenObjectList is valid?\nANDGenObjectList Signal State is invalid?) then (Yes)
                        -set error
                        else(No)
                        endif
                        endif
                        stop
                        }
                        @enduml


  @return               boolean bError : TRUE if an error was detected

  @param[in]            pRequirePorts : Pointer to all require ports.
  @param[in]            pProvidePorts : Pointer to all provide ports.

  @glob_in              @ref uiVDYSigErrorCnt
  @glob_out             @ref uiVDYSigErrorCnt

  @c_switch_part        -
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static boolean SLATE_b_PortSpecificHandling(  reqSLATEPortList_t const * const pRequirePorts, 
                                             provSLATEPortList_t const * const pProvidePorts)
{
  boolean b_Error = FALSE;
  if (pRequirePorts != NULL)
  {
    /*Check the SignalStatus of the GenObjectList*/
    if(pRequirePorts->pEmGenObjList!= NULL)
    {
      if(pRequirePorts->pEmGenObjList->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
      {
        b_Error = TRUE;        
      }
    }
  }
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Required by software design to avoid compiler warning*/
/* PRQA S 3119  2*/
  _PARAM_UNUSED(pRequirePorts);
  _PARAM_UNUSED(pProvidePorts);
  return b_Error;
}

/*************************************************************************************************************************
  Functionname:         SLATE_v_FillProPortHeaders                                                                    */ /*!

  @brief                Fills the provide port signal headers after the call to the subcomponents.

  @description          Fills the signal header of a provide port according to the signal header of a require port. \n
                        Fills the state of this signal header according to the operation state of a subcomponent. \n
                        Sets all signal states to invalid if an error was detected.
                        @startuml 
                        Partition SLATE_v_FillProPortHeaders {
                        start
                             partition "Execute for all provide port handlers" {
                                if(Provide Port Pointer is valid?) then (Yes)
                                   -Write version number to the port
                                if(Pointer to the related require\nport signal header is valid?) then (Yes)
                                   -Set signal state according to the assigned subcomponent state
                        note left
                        RUNNING, SUCCESS -> Sig state from Req Port
                        NOT RUNNING, NOT INITIALIZED -> INIT
                        TEMPORARY/PERMANENT ERROR, REDUCED AVAILABILITY -> INVALID
                        end note
                        -Copy signal header information from require port to provide port. <b>SLATE_v_SetSignalHeader</b> >
                        else(No)
                        -Set Signal header to default and Signal State to **INVALID**:<b>SLATE_v_SetSignalHeaderError</b> >
                        endif
                        if(SLATE State is **Not Initialized**?\nAND SignalState is not **INVALID**?) Then (Yes)
                        -Set Signal State to **INIT**
                        elseif(SLATE State is **Error**?) Then (Yes)
                        -Set Signal State to **INVALID**;
                        else(No)
                        -Keep signal state;
                        endif
                        else(No)
                        -Display warning:<b>SLATE_ASSERT</b> |
                        note right
                        Assert is not necessary here, as it
                        would already have been triggered 
                        in SLATE_v_ProcessPorts. Nevertheless 
                        keep here to assure safety.
                        end note
                        endif
                        }
                        Stop
                        }
                        @enduml


  @return               void

  @glob_in              @ref t_SLATEPortHandlerList
  @glob_out             @ref t_SLATEPortHandlerList

  @c_switch_part        None
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT\n

  @pre                  @ref SLATE_v_ProcessPorts has been called at the beginning of the cycle.
  @post                 None

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
extern void SLATE_v_FillProPortHeaders(void)
{
  uint8                   u_PortNo             = 0u;
  AlgoSignalState_t       t_NewSigState        = AL_SIG_STATE_INVALID;
  SLATEPortHandlerList_t * pt_PortHandlerList  = &t_SLATEPortHandlerList;
  SLATEProPortHandler_t  * pt_CurrPort;

  for (u_PortNo = 0u; (u_PortNo < pt_PortHandlerList->uNofProPorts); ++u_PortNo)
  { 
    pt_CurrPort = &(pt_PortHandlerList->ProPortHandler[u_PortNo]);
    if (pt_CurrPort->pProPort != NULL)
    {
      /* If ProPort pointer is valid, fill the provide ports signal header */
      *(pt_CurrPort->pProVersionNumber) = pt_CurrPort->uProNewVersionNumber;
      
      if(pt_CurrPort->pReqPortSignalHeader != NULL)
      {
        switch(*(pt_CurrPort->pProNewSignalState))
        {
          case COMP_STATE_PERMANENT_ERROR:
          case COMP_STATE_TEMPORARY_ERROR:
          case COMP_STATE_REDUCED_AVAILABILITY:
               t_NewSigState = AL_SIG_STATE_INVALID;
               break;
          case COMP_STATE_NOT_INITIALIZED:
          case COMP_STATE_NOT_RUNNING:
               t_NewSigState = AL_SIG_STATE_INIT;
               break;
          case COMP_STATE_RUNNING:
          case COMP_STATE_SUCCESS:
               t_NewSigState = pt_CurrPort->pReqPortSignalHeader->eSigStatus;
               break;
          default:            
               t_NewSigState = AL_SIG_STATE_INVALID;
               SLATE_ASSERT(FALSE);
               break;
        }
        /*Fill with given ReqPort SigHeader if the ReqPort Signal was valid*/
        SLATE_v_SetSignalHeader(pt_CurrPort->pProPortSignalHeader,
                                pt_CurrPort->pReqPortSignalHeader,
                                t_NewSigState                    );
      }
      else
      {
        /*Fill with default if ReqPort Signal was invalid*/
        SLATE_v_SetSignalHeaderError(pt_CurrPort->pProPortSignalHeader);
      }
      /* If SLATE is not in running mode, all provide port headers shall be filled (if possible), 
      afterwards the signal header is set to invalid. The only exception is the init mode: All 
      Provide ports are set to INIT, unless they have been set to INVALID*/
      if(    (t_SLATEFrame.SLATEState                           == COMP_STATE_NOT_INITIALIZED)
          && (pt_CurrPort->pProPortSignalHeader->eSigStatus != AL_SIG_STATE_INVALID      ) )
      {
        pt_CurrPort->pProPortSignalHeader->eSigStatus = AL_SIG_STATE_INIT;
      }
      else
      {
        if(t_SLATEFrame.SLATEState != COMP_STATE_RUNNING)
        {
          pt_CurrPort->pProPortSignalHeader->eSigStatus = AL_SIG_STATE_INVALID;
        }
      }
    }
    else
    {
      /*Not necessary, as assert is already set in previous step*/
      SLATE_ASSERT(FALSE);
    }
  }
}

/*************************************************************************************************************************
  Functionname:         SLATE_v_ProcessPorts                                                                          */ /*!

  @brief                Processes require ports, provide ports and service functions to enable an error free 
                        operation of the SLATE component. 

  @description          Executes pointer and signal state checks and sets up all internal data that is 
                        related to the ports. This is done by means of Port Handlers. Each require and \n
                        provide port has its own handler (see @ref t_SLATEPortHandlerList), that is filled in the 
                        functions @ref SLATE_v_SetupProPortHandlers or @ref SLATE_v_SetupProPortHandlers. \n
                        The handlers contain all information that is necessary to set up a port. The advantage 
                        of this procedure is the generic handling of all ports: The Possibility to fill the \n
                        handlers at one point in the code eliminates the eventuality of missing a port in a 
                        later processing step. The handlers are processed in two functions:
                        - After the handlers are filled, the function @ref SLATE_b_SetupPorts is called. It checks the 
                          pointers and signal state and initializes global variables.
                        - The function @ref SLATE_v_FillProPortHeaders is called AFTER the call of the subcomponents. It fills 
                          the provide port signal headers according to the calculation results.
                        .
                        @startuml 
                        partition SLATE_v_ProcessPorts {
                        start
                        -Initialize the PortHandler List
                        -Set up the require port handlers:<b>SLATE_v_SetupReqPortHandlers</b> >
                        -Set up the provide port handlers:<b>SLATE_v_SetupProPortHandlers</b> >
                        partition #LightBlue **FCT_CFG_USE_SERVICE_POINTER_FUNCTS** {
                        -Check Service function pointers for NULL pointer:<b>SLATE_b_CheckServiceFunctions</b> >
                        }
                        -Check and set up all require and provide ports by using the port handlers <b>SLATE_b_SetupPorts</b> >
                        -Execute port specific handling for certain ports: <b>SLATE_b_PortSpecificHandling</b> >
                        if(**Error flag** was set by one\nof the function calls?) then (Yes)
                        partition #LightBlue **FCT_CFG_USE_DEM** { 
                        -Set DEM event **Failed**: <b>SLATE_v_SetDem</b> > 
                        }
                        partition #LightBlue **FCT_CFG_USE_ALGOCOMPSTATE** {
                        -Write **Critical error** to error buffer: <b>SLATE_v_SetAlgoErrorBuffer</b> >
                        }
                        -Switch to SLATE Error Mode: <b>SLATE_v_SignalErrorShutdown</b> >
                        else(No)
                        partition #LightBlue **FCT_CFG_USE_DEM** { 
                        -Set DEM event **Passed**: <b>SLATE_v_SetDem</b> >
                        }
                        endif
                        stop
                        }
                        @enduml


  @return               void

  @param[in]            pRequirePorts :  Pointer to a structure with all require port pointers.
  @param[in]            pProvidePorts :  Pointer to a structure with all provide port pointers.
  @param[in]            pServiceFuncts : Pointer to a structure with all service function pointers.
  @param[in]            pErrorBuffer :   Error buffer to which the current error shall be written.

  @glob_in              @ref t_SLATEPortHandlerList
  @glob_out             @ref t_SLATEPortHandlerList

  @c_switch_part        @ref FCT_CFG_USE_ALGOCOMPSTATE\n
                        @ref FCT_CFG_USE_DEM\n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        @ref FCT_CFG_SLATE_COMPONENT\n

  @pre                  None
  @post                 @ref SLATE_v_FillProPortHeaders has to be called after the call of the subcomponents.

  @InOutCorrelation     see description

  @author               Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
extern void SLATE_v_ProcessPorts(   reqSLATEPortList_t const * const pRequirePorts,
                                  provSLATEPortList_t const * const pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                               , AS_t_ServiceFuncts const * const pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                              , GenAlgoQualifiers_t       * const pErrorBuffer
#endif
  )
{
  SLATEPortHandlerList_t * pPortHandlerList = &t_SLATEPortHandlerList;
  boolean b_Error = FALSE;

  /*Initialize the PortHandler List*/
  SLATE_v_InitPortHandlerList();

  /* Evaluate and Set up Require Ports */
  SLATE_v_SetupReqPortHandlers(pRequirePorts, pPortHandlerList);

  /* Evaluate and Set up Provide Ports */
  SLATE_v_SetupProPortHandlers(pProvidePorts, pRequirePorts, pPortHandlerList);

  /* Evaluate Service Function pointers*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  b_Error |= SLATE_b_CheckServiceFunctions(pServiceFuncts);
#endif

  /*Check and set up all ports by evaluating the Port handlers*/
  b_Error |= SLATE_b_SetupPorts(pPortHandlerList); /* PRQA S 2986 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Required by software design */

  /*Execute specific handling for certain ports*/
  b_Error |= SLATE_b_PortSpecificHandling(pRequirePorts,pProvidePorts);
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Integral promotion is fine  */
  if (b_Error == TRUE) /* PRQA S 1863 */
  {
    /* Some port pointer is NULL => DEM and shutdown */
    /* Validity of service pointer isn't clear here, anyway assign internal global alias*/
#if FCT_CFG_USE_DEM
    SLATE_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    SLATE_v_SetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    /* When SLATE_v_SignalErrorShutdown is called with FALSE, then SLATE is shutting down with error and goes to TEMPORARY ERROR State */
    SLATE_v_SignalErrorShutdown(FALSE);
  }
  else
  {
#if FCT_CFG_USE_DEM
    SLATE_v_SetDem(FCTSEN_DEM_SW, DEM_EVENT_STATUS_PASSED);
#endif
  }
}

#if (SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/* ***********************************************************************
  @fn             SLATE_v_CheckPortUpdated */ /*! 
  @brief          compares saved and current meas timestamp
  @description    checks current timestamp against last timestamp
                  counts frozen cycles (expected but not received data)
                  if duration since last update is greater than given in debounce and cycle time set error
				  @startuml
                  Partition SLATE_b_CheckPortUpdated {
                  Start
                   If(pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp) then (yes)
                     -OVERFLOW
                   Else
                     -NO Overflow
                     If(uiDeltaTimeUs is 0)then (yes)
                       -NO update
                     Else
                       -update
                  End
                  }
                  @enduml


  @param[in]      pInputPortMeasCycle   : currently received timestamp of interface
  @param[in]      fTargetCycleTime      : expected reception cycle time
  @param[in]      iAcceptableDrops      : number of acceptable frame drops
  @param[in,out]  pLastMeasCycle        : contains last seen timestamp and the dropped frame counter;
                                          is updated with currently received timestamp
  @return         error (!= zero) in case of frozen port
  @author         Christian Obst
**************************************************************************** */
static boolean SLATE_b_CheckPortUpdated( AlgoDataTimeStamp_t const * const pInputPortMeasCycle, 
                                                sMeasCycleMonitor * const pLastMeasCycle,
                                                          float32   const fTargetCycleTime, 
                                                            uint8         iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /*20150325 C. Obst: intended behavior to cast float to uInt. fractional part is neglectible.*/
  /*PRQA S 4119 3*/
  const AlgoDataTimeStamp_t uiReceiveCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * SLATE_TIMESTAMP_TO_MICROSECONDS);         /*conversion second to microsecond*/
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiReceiveCycleTimeUs ); /*accepted drops + current Cycle + 0.5 safety margin*/
  const AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_SEN_CYCLE_TIME * SLATE_TIMESTAMP_TO_MICROSECONDS);

  boolean b_Error = 0u;

  /*Calculating Time since last input*/
  if ( *pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp )
  {
    /*OVERFLOW*/
    uiDeltaTimeUs = ( (0u)^(0u)) - (pLastMeasCycle->uiTimeStamp - *pInputPortMeasCycle);
  }
  else 
  {
    /*NO Overflow*/
    uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
  }
  
  if ( uiDeltaTimeUs == 0u)
  {
    /*NO update*/
    if ( ((pLastMeasCycle->uiLastUpdateCounter + 1) * uiTargetCycleTimeCallUs)  < uiMaxAcceptableDropTimeUs)
    {
      /*no update needed (max time including drops not reached)*/
      pLastMeasCycle->uiLastUpdateCounter += 1u;   /*increment update counter*/
    }
    else
    {
      /*update expected*/
      b_Error = TRUE;        /*raise error*/
    }
  }
  else
  {
    /*update*/
    if ( uiDeltaTimeUs > uiMaxAcceptableDropTimeUs )
    {
      /*skipped cycle*/
      b_Error = TRUE;        /*raise error*/
    }
    else
    {
      /*new cycle received in time*/
      pLastMeasCycle->uiLastUpdateCounter = 0u;    /*reset update counter*/
    }
    pLastMeasCycle->uiTimeStamp = *pInputPortMeasCycle;
  }
  return b_Error;
}
#endif

/*************************************************************************************************************************
  Functionname:    SLATE_v_ProcessInput                                                                       */ /*!

  @brief           Calculates the sensor position relative to CoG and Updates ego motion matrices based on current motion data

  @description     Calculates the sensor position relative to CoG and Updates ego motion matrices based on current motion data
                   @startuml
                   Partition SLATE_v_ProcessInput  {
                   Start
                   - Calculate the Sensor Position Relative to CoG
                   Partition SLATE_v_CalcMotionMatrices  {
                   -Update ego motion matrices based on current motion data
                   }
                   End
                   }
                   @enduml


  @return          void

  @param[in]       fCycleTime : The cycle time since the last call                                         [full range of datatype float32 >= 0.F]
                                (for first call the nominal cycle time to use)
  @param[in]       pEgoDyn : Reference to the ego vehicle dynamic information

  @glob_in         GET_EGO_STATIC_DATA_PTR : Get Macro to retrieve ego vehicle static parameters
                     GET_EGO_STATIC_DATA_PTR->VehParMain.WheelBase : Wheelbase distance           [full range of data float32 >= 0.F]
                     GET_EGO_STATIC_DATA_PTR->VehParMain.AxisLoadDistr : Axial load distribution  [full range of data float32 >= 0.F]
                     GET_EGO_STATIC_DATA_PTR->VehParAdd.OverhangFront : Front overhang distance   [full range of data float32 >= 0.F]

  @glob_out        FCT_fBumperToCoG : distance from Bumper to Center of Gravity                   [full range of datatype float32 >= 0.F]

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         
  @changed         12/4/2015
  
  @author          Gergely Ungvary & Jochen Spruck
*************************************************************************************************************************/
void SLATE_v_ProcessInput(fTime_t fCycleTime, const VehDyn_t * pEgoDyn)
{
/*--- VARIABLES ---*/
  /* Calculate the Sensor Position Relative to CoG */
  FCT_fBumperToCoG = (GET_EGO_STATIC_DATA_PTR->VehParMain.WheelBase 
    * GET_EGO_STATIC_DATA_PTR->VehParMain.AxisLoadDistr)
    + GET_EGO_STATIC_DATA_PTR->VehParAdd.OverhangFront;

  SLATE_v_CalcMotionMatrices(fCycleTime, pEgoDyn);
}

/*************************************************************************************************************************
  Functionname:    SLATE_v_CalcMotionMatrices                                                                            */ /*!

  @brief           Update ego motion matrices based on current motion data

  @description     Update ego motion matrices based on current motion data
                   @startuml
                   Partition SLATE_v_CalcMotionMatrices  {
                   Start
                   If(MotionState is equal to moving reverse) then (yes)
                   -correct for sign
                   endif
                   partition GDBmathCalculateCOFEgomotionMatrices {
                   -calculate matrices for ego motion compensation
                   }
                   End
                   }
                   @enduml


  @return          static void

  @param[in]       fCycleTime : The cycle time since the last call                                     [ftime_t datatype as in Rte_Type.h][0...+3.4e+038]
                                (for first call the nominal cycle time to use)
  @param[in]       pEgoDyn : Reference to the ego vehicle dynamic information
                     pEgoDyn->Longitudinal.MotVar.Accel : Longitudinal acceleration of ego vehicle     [full range of datatype float32]
                     pEgoDyn->Lateral.YawRate.YawRate : Yaw rate of ego vehicle                        [full range of datatype float32]
                     pEgoDyn->Longitudinal.MotVar.Velocity : Velocity of ego vehicle                   [full range of datatype float32]
                     pEgoDyn->MotionState.MotState : Ego motion state                                  [MotState_t as in Rte_Type.h]

  @glob_in         SLATETrMat2DForward : Forward motion transformation Matrix
  @glob_in         FCTTrMat2DBackward : Backward motion transformation Matrix
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             Transformation matrices updated
  @post            -

  @created         
  @changed         12/4/2015

  @author          Gergely Ungvary | gergely.ungvary@contiautomotive.com
*************************************************************************************************************************/
static void SLATE_v_CalcMotionMatrices(fTime_t fCycleTime, const VehDyn_t * pEgoDyn)
{
  fAccel_t fAcceleration = SLATE_f_GetEgoAccelObjSync();
  fYawRate_t fYawRate = SLATE_f_GetEgoYawRateObjSync();
  fVelocity_t fCorrVelo = SLATE_f_GetEgoVelObjSync();

  /* Since corrected speed is unsigned, correct for sign if moving reverse */
  if ((pEgoDyn->MotionState.MotState == VDY_LONG_MOT_STATE_MOVE_RWD) &&
      (fCorrVelo > 0))/* PRQA S 1802 */
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Implict conversion is safe.  */
  {
    fCorrVelo = -fCorrVelo;
  }

  /*! calculate matrices for ego motion compensation */
  GDBmathCalculateCOFEgomotionMatrices(&SLATETrMat2DForward,
                                       &SLATETrMat2DBackward,
                                       fCorrVelo,
                                       fAcceleration,
                                       fYawRate,
                                       fCycleTime );
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetTrafoMatrix2DCOFForward                                                                    */ /*!

  @brief           Get TranslationMatrix from last cycle CenterOfGravity
                   Coordinate-System to actual CenterOfGravity Coordinate-System

  @description     Detailed Design
                   @startuml
                   Start
                   Partition SLATE_p_GetTrafoMatrix2DCOFForward {
                   -Get TranslationMatrix from last cycle CenterOfGravity Coordinate-System to actual CenterOfGravity Coordinate-System
                   } 
                   end
                   @enduml


  @return          const GDBTrafoMatrix2D_t * : const pointer to the transformation matrix

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             Transformation matrix was updated for current data via function SLATE_v_CalcMotionMatrices
  @post            -

  @created         
  @changed         12/4/2015

  @author          Norman Apel | norman.apel@contiautomotive.com
*************************************************************************************************************************/
const GDBTrafoMatrix2D_t * SLATE_p_GetTrafoMatrix2DCOFForward(void)
{
  return &SLATETrMat2DForward;
}

/*************************************************************************************************************************
  Functionname:    SLATE_p_GetTrafoMatrix2DCOFBackward                                                                   */ /*!

  @brief           Get TranslationMatrix from current cycle CenterOfGravity 
                   Coordinate-System to last cycle CenterOfGravity Coordinate-System

  @description     Detailed Design
                   @startuml
                   Start
                   Partition SLATE_p_GetTrafoMatrix2DCOFBackward {
                   -Get TranslationMatrix from current cycle CenterOfGravity Coordinate-System to last cycle CenterOfGravity Coordinate-System
                   } 
                   end
                   @enduml


  @return          const GDBTrafoMatrix2D_t * : const pointer to the transformation matrix

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             Transformation matrix was updated for current data via function SLATE_v_CalcMotionMatrices
  @post            -

  @created         
  @changed         12/4/2015

  @author          Norman Apel | norman.apel@contiautomotive.com
*************************************************************************************************************************/
const GDBTrafoMatrix2D_t * SLATE_p_GetTrafoMatrix2DCOFBackward(void)
{
  return &SLATETrMat2DBackward;
}


/**********************************************************************************
  Slate_access_Function definitions										*/ /*!
  
  @comment : Temporary (all function definitions needs to be moved to a new .c file
***********************************************************************************/


/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjLongDisp                                                                         */ /*!

  @brief           Inline function for accessing the pointer to longitudinal displacement of object
  @return          Reference to longitudinal displacement of object
                   @startuml
                   Start
                   Partition SLATE_pf_GetObjLongDisp {
                   -Perform range check before accessing an object
                   - return longitudinal displacement of object
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
float32 const * SLATE_pf_GetObjLongDisp(ObjNumber_t iObj)
{
  float32 const * pf_LongDisp;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_LongDisp = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fDistX);


  return pf_LongDisp;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjLatDisp                                                                          */ /*!

  @brief           Inline function for accessing the pointer to lateral displacement of object
  @return          Reference to lateral displacement of object
                   @startuml
                   Start
                   Partition SLATE_pf_GetObjLatDisp {
                   -Perform range check before accessing an object
                   - return lateral displacement of object
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         09.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
float32 const * SLATE_pf_GetObjLatDisp(ObjNumber_t iObj)
{
  float32 const* pf_LatDisp;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));


  pf_LatDisp = (float32 const*) &(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fDistY);

  return pf_LatDisp;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjVrelX                                                                            */ /*!

  @brief           Inline function for accessing the pointer to relative longitudinal velocity of object
  @return          Reference to relative longitudinal velocity of object
                   @startuml
                   Start
                   Partition SLATE_pf_GetObjVrelX {
                   -Perform range check before accessing an object
                   - return relative longitudinal velocity of object
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
float32 const * SLATE_pf_GetObjVrelX(ObjNumber_t iObj)
{
  float32 const* pf_VrelX;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_VrelX = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fVrelX);

  return pf_VrelX;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjVrelY                                                                            */ /*!

  @brief           Inline function for accessing the pointer to relative lateral velocity of object
  @return          Reference to relative lateral velocity of object
                   @startuml
                   Start
                   Partition SLATE_pf_GetObjVrelY {
                   -Perform range check before accessing an object
                   - return relative lateral velocity of object
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
float32 const * SLATE_pf_GetObjVrelY(ObjNumber_t iObj)
{
  float32 const* pf_VrelY;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_VrelY = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fVrelY);

  return pf_VrelY;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pf_GetObjArelX                                                                            */ /*!

  @brief           Inline function for accessing the pointer to relative longitudinal acceleration of object
  @return          Reference to relative longitudinal acceleration of object
                   @startuml
                   Start
                   Partition SLATE_pf_GetObjArelX {
                   -Perform range check before accessing an object
                   - return relative longitudinal acceleration of object
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
float32 const * SLATE_pf_GetObjArelX(ObjNumber_t iObj)
{
  float32 const* pf_ArelX;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_ArelX = (float32 const*)&(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fArelX);

  return pf_ArelX;
}

/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjDynProperty                                                                      */ /*!

  @brief           Inline function for accessing the pointer to object dynamic property
  @return          Reference to object dynamic property
                   @startuml
                   Start
                   Partition SLATE_pt_GetObjDynProperty {
                   -Perform range check before accessing an object
                   - return object dynamic property
                   } 
                   end
                   @enduml

  @param[in]       -
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
SLATE_t_Obj_DynamicProperty const * SLATE_pt_GetObjDynProperty(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  return &(pSLATE_EmARSObjList->aObject[iObj].MotionAttributes.eDynamicProperty);
#else
  return &(pSLATE_EmGenObjList->aObject[iObj].Attributes.eDynamicProperty);
#endif
}

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjDynSubProperty                                                                   */ /*!

  @brief           Inline function for accessing the pointer to object dynamic sub property
  @return          Reference to object dynamic sub property
                   @startuml
                   Start
                   Partition SLATE_pt_GetObjDynSubProperty {
                   -Perform range check before accessing an object
                   - return object dynamic sub property
                   } 
                   end
                   @enduml

  @param[in]       -
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
SLATE_t_Obj_DynamicSubProperty const * SLATE_pt_GetObjDynSubProperty(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(pSLATE_EmARSObjList->aObject[iObj].MotionAttributes.eDynamicSubProperty);
}
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */

/*************************************************************************************************************************
  Functionname:    SLATE_pt_GetObjClassification                                                                   */ /*!

  @brief           Inline function for accessing the pointer to object classification
  @return          Reference to object classification
                   @startuml
                   Start
                   Partition SLATE_pt_GetObjClassification {
                   -Perform range check before accessing an object
                   - return object classification
                   } 
                   end
                   @enduml

  @param[in]       -
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
SLATE_t_Obj_CLassification const * SLATE_pt_GetObjClassification(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  return &(pSLATE_EmARSObjList->aObject[iObj].Attributes.eClassification);
#else
  return &(pSLATE_EmGenObjList->aObject[iObj].Attributes.eClassification);
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjOrientation                                                                      */ /*!

  @brief           Inline function for accessing the pointer to object orientation
  @return          Reference to object orientation
                   @startuml
                   Start
                   Partition SLATE_f_GetObjOrientation {
                   -Perform range check before accessing an object
                   - return object orientation
                   } 
                   end
                   @enduml

  @param[in]       -
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         15.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
float32 SLATE_f_GetObjOrientation(ObjNumber_t iObj)
{
  float32 f_Orientation;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  f_Orientation = (pSLATE_EmARSObjList->aObject[iObj].Geometry.fOrientation);
#else
  f_Orientation = 0.F; /* VACC is not available, should be computed from shape points as done in ACDC */
  _PARAM_UNUSED(iObj);
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
 return f_Orientation;
}

/*************************************************************************************************************************
  Functionname:    SLATE_b_GetObjIsRelevant                                                                         */ /*!

  @brief           Inline function for accessing the boolean if object is relevant
  @return          Boolean if object is relevant
                   @startuml
                   Start
                   Partition SLATE_b_GetObjIsRelevant {
                   -Perform range check before accessing an object
                   If(object is relevant) then (yes)
                   -return true
                   Else(no)
                   -return false
                   endif
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         22.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
boolean SLATE_b_GetObjIsRelevant(ObjNumber_t iObj)
{
  boolean b_ObjIsRel = FALSE;
  /* Perform range check before accessing an object */
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  if(FCTSEN_pPubFctObjList->ObjList[iObj].ObjOfInterest.eObjOOI == OBJ_NEXT_OOI)
  {
    b_ObjIsRel = TRUE;
  }
  else
  {
    b_ObjIsRel = FALSE;
  }

  return b_ObjIsRel;
}

/*************************************************************************************************************************
  Functionname:    SLATE_b_GetObjIsShadow                                                                          */ /*!

  @brief           Inline function for accessing the boolean if object is shadow
  @return          boolean if object is shadow
                   @startuml
                   Start
                   Partition SLATE_b_GetObjIsShadow {
                   -Perform range check before accessing an object
                   - return boolean if object is shadow
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_full   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         16.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
boolean SLATE_b_GetObjIsShadow(ObjNumber_t iObj)
{
  boolean bObjIsShadow;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  bObjIsShadow =  (boolean)((pSLATE_EmARSObjList->aObject[iObj].SensorSpecific.eObjRelationsClass==ARS_LONGVEHICLE_TYPE_SHADOW) || (pSLATE_EmARSObjList->aObject[iObj].SensorSpecific.eObjRelationsClass==ARS_LONGVEHICLE_TYPE_MIDDLE));
#else
/* PRQA S 4404  1*/ /* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe, doesnot affect functionality  */
bObjIsShadow = FALSE; //VACC camera should not have those problems
  _PARAM_UNUSED(iObj);
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
  return bObjIsShadow;
}

/*************************************************************************************************************************
  Functionname:    SLATE_b_GetObjIsMovingToStationary                                                              */ /*!

  @brief           Inline function for accessing boolean if moving object is stationary
  @return          boolean if moving object is stationary
                   @startuml
                   Start
                   Partition SLATE_b_GetObjIsMovingToStationary {
                   -Perform range check before accessing an object
                   - return boolean if moving object is stationary
                   } 
                   end
                   @enduml

  @param[in]       -
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @created         14.12.2016
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
boolean SLATE_b_GetObjIsMovingToStationary(ObjNumber_t iObj)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  return ((boolean)(pSLATE_EmARSObjList->aObject[iObj].MotionAttributes.uiStoppedConfidence > 80u));
#else
  return ((boolean)(pSLATE_EmGenObjList->aObject[iObj].Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED));
#endif
}

/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjDistYVar                                                                          */ /*!

  @brief           Inline function for accessing the pointer to std deviation of lateral dispalcement
  @return          Reference to std deviation of lateral dispalcement
                   @startuml
                   Start
                   Partition SLATE_f_GetObjDistYVar {
                   -Perform range check before accessing an object
                   - return standerded deviation of lateral dispalcement
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         21.12.2016
  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
float32 SLATE_f_GetObjDistYVar(ObjNumber_t iObj)
{
  float32 pf_DistYVar;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_DistYVar = (float32)SQR(pSLATE_EmGenObjList->aObject[iObj].Kinematic.fDistYStd);

  return pf_DistYVar;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjDistYStd                                                                          */ /*!

  @brief           Function for accessing the pointer to std deviation of lateral dispalcement
  @return          Reference to std deviation of lateral dispalcement
                   @startuml
                   Start
                   Partition SLATE_f_GetObjDistYStd {
                   -Perform range check before accessing an object
                   - return standerded deviation of lateral dispalcement
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         30.11.2020
  @author          Mekala Rajeev| mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/
float32 SLATE_f_GetObjDistYStd(ObjNumber_t iObj)
{
  float32 pf_DistYStd;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_DistYStd = (float32)pSLATE_EmGenObjList->aObject[iObj].Kinematic.fDistYStd;

  return pf_DistYStd;
}
/*************************************************************************************************************************
  Functionname:    SLATE_f_GetObjVrelYStd                                                                          */ /*!

  @brief           Function for accessing the pointer to std deviation of lateral velocity
  @return          Reference to std deviation of lateral velocity
                   @startuml
                   Start
                   Partition SLATE_f_GetObjVrelYStd {
                   -Perform range check before accessing an object
                   - return standerded deviation of lateral velocity
                   } 
                   end
                   @enduml

  @param[in]       iObj : EM Object number [0 ... EM_N_OBJECTS)
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @created         30.11.2020
  @author          Mekala Rajeev| mekala.rajeev@continental-corporation.com
*************************************************************************************************************************/
float32 SLATE_f_GetObjVrelYStd(ObjNumber_t iObj)
{
  float32 pf_VrelYStd;
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  pf_VrelYStd = (float32)pSLATE_EmGenObjList->aObject[iObj].Kinematic.fVrelYStd;

  return pf_VrelYStd;
}
/* ************************************************************************** */


///@}
#endif /* END IF FCT_CFG_SLATE_COMPONENT */


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */



