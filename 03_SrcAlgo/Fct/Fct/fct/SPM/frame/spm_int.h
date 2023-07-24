// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.31 $

/***********************************************************************
CHANGES:                   $Log: spm_int.h  $
CHANGES:                   Revision 1.31 2020/10/23 15:46:02CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Adaptation for situation when SLATE and ACC are both turned OFF simultaniously
CHANGES:                   Revision 1.30 2020/06/30 16:28:04CEST Pallo, Istvan (palloi) 
CHANGES:                   Revert SRR SPM split changes on trunk
CHANGES:                   Revision 1.29 2020/06/25 08:08:40CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.28 2019/05/28 08:45:15CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.27 2019/05/21 09:41:44CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add  RTA_LOCAL_ID_FOR_XML_GENERATION tag
CHANGES:                   Revision 1.26 2019/05/16 10:27:56CEST Pallo, Istvan (palloi) 
CHANGES:                   Renaming SPMRtaMapping enum to SPM_t_LocalID
CHANGES:                   Revision 1.25 2018/11/19 13:27:42CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Added config switch for some SPM_v_ProcessPorts function parameters
CHANGES:                   Revision 1.24 2018/09/24 15:15:09CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.23 2018/08/14 12:53:27CEST Pallo, Istvan (palloi) 
CHANGES:                   Change VDY interface version threshold from 9 to 32
CHANGES:                   Revision 1.22 2018/04/13 09:48:50CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new define for veh dyn interface version threshold
CHANGES:                   Revision 1.21 2018/04/03 11:46:30CEST Pallo, Istvan (palloi) 
CHANGES:                   Fixes for functions detailed design.
CHANGES:                   Revision 1.20 2018/04/03 10:54:11CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new functions detailed design and update the old design
CHANGES:                   Revision 1.19 2018/03/09 13:20:29CET Pallo, Istvan (palloi) 
CHANGES:                   Remove definition type for spm version and rename member
CHANGES:                   Revision 1.18 2018/03/09 10:47:49CET Pallo, Istvan (palloi) 
CHANGES:                   Remove define of types as they are moved to type file.
CHANGES:                   Revision 1.17 2018/02/28 11:36:24CET Pallo, Istvan (palloi) 
CHANGES:                   Change RTA parameters position in order to have a full array of elements
CHANGES:                   Revision 1.16 2018/02/27 17:10:14CET Pallo, Istvan (palloi) 
CHANGES:                   Add new address defines and remove PDO comments
CHANGES:                   Revision 1.15 2018/02/27 11:48:43CET Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for function header.
CHANGES:                   Remove const from function parameters.
CHANGES:                   Revision 1.14 2018/02/23 14:27:00CET Pallo, Istvan (palloi) 
CHANGES:                   Add new function headers and remove obsolute function headers.
CHANGES:                   New include files.
CHANGES:                   Revision 1.13 2018/01/17 08:00:53CET Pallo, Istvan (palloi) 
CHANGES:                   Uncomment config switches
CHANGES:                   Revision 1.12 2018/01/17 07:37:58CET Pallo, Istvan (palloi) 
CHANGES:                   Design updates
CHANGES:                   Revision 1.11 2018/01/16 08:56:37CET Pallo, Istvan (palloi) 
CHANGES:                   Update design
CHANGES:                   Revision 1.10 2017/12/05 18:45:20CET Pallo, Istvan (palloi) 
CHANGES:                   Update function header
CHANGES:                   Revision 1.9 2017/11/23 14:02:47CET Pepenar, Alin (pepenara) 
CHANGES:                   Update detailed design: added traceability
CHANGES:                   Revision 1.8 2017/11/14 13:58:53CET Pallo, Istvan (palloi) 
CHANGES:                   Update design and test method for functions.
CHANGES:                   Revision 1.7 2017/11/08 15:35:02CET Pallo, Istvan (palloi) 
CHANGES:                   Add define for ARS5xx cycle ID
CHANGES:                   Revision 1.6 2017/10/17 15:09:20CEST Pallo, Istvan (palloi) 
CHANGES:                   New function headers for check ports and ref sync
CHANGES:                   Revision 1.5 2017/08/11 08:34:05CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functions uml diagrams
CHANGES:                   Revision 1.4 2017/07/28 07:03:58CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functionality from AL_FCT_ARS400_02.86.00.
CHANGES:                   Revision 1.3 2017/07/10 08:37:57CEST Umesh Babu, Harsha (uidj3583) 
CHANGES:                   Removed extra semicolon
CHANGES:                   Revision 1.2 2017/06/21 09:52:43CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new functions headers.
CHANGES:                   Change file header.
CHANGES:                   Revision 1.1 2017/03/17 13:16:57CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

*****************************************************************************/
#ifndef SPM_INT_H_INCLUDED
#define SPM_INT_H_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_sen.h"
#include "spm_ver.h"
#include "spm_types.h"
#include "spm_access_func.h"

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if(FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERN)
*****************************************************************************/
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#ifndef FCT_MEAS_ID_SEN_SPM_FRAME_DATA
#define FCT_MEAS_ID_SEN_SPM_FRAME_DATA  (0x20270700u)  //TODO: define in interface sheet
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE) /* to be clarified */
#ifndef FCT_MEAS_ID_SEN_SPM_COMP_STATE
#define FCT_MEAS_ID_SEN_SPM_COMP_STATE      to be definded
#endif
#endif

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA) /* to be clarified */
#ifndef FCT_MEAS_ID_SEN_SPM_CTRL_DATA
#define FCT_MEAS_ID_SEN_SPM_CTRL_DATA       to be definded
#endif
#endif

// Macro to acces OOI list properties. OOI list is populated by SLATE
#if (FCT_CFG_SLATE_COMPONENT)
#if((FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF))
  #define SPM_OBJ_GET_OOI_POS(iObj)                 FCTSEN_pSPMPubFctObj->ObjList[iObj].ObjOfInterest.eObjOOI // SPM, ACC, Simulation
  #define SPM_OBJ_GET_OOI_LIST_OBJ_IDX(iOoiPos)     FCTSEN_pSPMPubFctObj->HeaderAssessedObjList.aiOOIList[iOoiPos] // SPM, ACC, Sim
  #define SPM_OBJ_GET_FUNC_LANE_ASSOC(iObj)         FCTSEN_pSPMPubFctObj->ObjList[iObj].LaneInformation.eFuncAssociatedLane
#endif
#endif

#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
#define SPM_GET_EM_PUB_OBJ_DATA_PTR                   FCTSEN_pSPMEmGenObjList
#else
#define SPM_GET_EM_PUB_OBJ_DATA_PTR                   FCTSEN_pSPMEmObjList
#endif

/* utility macro to access per-object data */
#define SPM_GET_EM_GEN_OBJ(iObj)                      SPM_GET_EM_PUB_OBJ_DATA_PTR->aObject[iObj]
/* Object kinematic */
#define SPM_OBJ_KINEMATIC(iObj)                       SPM_GET_EM_GEN_OBJ(iObj).Kinematic

#define SPM_OBJ_LONG_DISPLACEMENT(iObj)               SPM_OBJ_KINEMATIC(iObj).fDistX
#define SPM_OBJ_LONG_VREL(iObj)                       SPM_OBJ_KINEMATIC(iObj).fVrelX
#define SPM_OBJ_LONG_AREL(iObj)                       SPM_OBJ_KINEMATIC(iObj).fArelX

#define SPM_OBJ_LAT_DISPLACEMENT(iObj)                SPM_OBJ_KINEMATIC(iObj).fDistY
#define SPM_OBJ_LAT_VREL(iObj)                        SPM_OBJ_KINEMATIC(iObj).fVrelY
#define SPM_OBJ_LAT_AREL(iObj)                        SPM_OBJ_KINEMATIC(iObj).fArelY


#define SPM_OBJ_GENERAL(iObj)                         SPM_GET_EM_GEN_OBJ(iObj).General
#define SPM_OBJ_LIFECYCLES(iObj)                      SPM_OBJ_GENERAL(iObj).uiLifeCycles


#define SPM_GET_EM_ARS_OBJ_LIST_PTR                   FCTSEN_pSPMEmARSObjList

#define SPM_GET_EM_ARS_OBJ_PUB(iObj)                  SPM_GET_EM_ARS_OBJ_LIST_PTR->aObject[iObj]
#define SPM_OBJ_ARS_GEOMETRY(iObj)                    SPM_GET_EM_ARS_OBJ_PUB(iObj).Geometry
#define SPM_OBJ_ARS_MOTIONATTRIBUTES(iObj)            SPM_GET_EM_ARS_OBJ_PUB(iObj).MotionAttributes
#define SPM_OBJ_ARS_SENSORSPECIFIC(iObj)              SPM_GET_EM_ARS_OBJ_PUB(iObj).SensorSpecific
#define SPM_OBJ_ARS_LEGACY(iObj)                      SPM_GET_EM_ARS_OBJ_PUB(iObj).Legacy
#define SPM_OBJ_ARS_ATTRIBUTES(iObj)                  SPM_GET_EM_ARS_OBJ_PUB(iObj).Attributes

#define SPM_OT_GET_OBJ_WIDTH(iObj)                    SPM_OBJ_ARS_GEOMETRY(iObj).fWidth

#define SPM_OBJ_DYNAMIC_PROPERTY(iObj)                SPM_OBJ_ARS_MOTIONATTRIBUTES(iObj).eDynamicProperty

#define SPM_OBJ_RCS(iObj)                             SPM_OBJ_ARS_SENSORSPECIFIC(iObj).fRCS

#define SPM_OBJ_IS_MEASURED(iObj, ucMask)             ((SPM_OBJ_ARS_SENSORSPECIFIC(iObj).ucMeasuredSources & (ucMask)) ? TRUE : FALSE)
#define SPM_OBJ_IS_DELETED(iObj)                      (SPM_OBJ_GENERAL(iObj).eMaintenanceState == EM_GEN_OBJECT_MT_STATE_DELETED)

#define SPM_OBJ_ANGLE(iObj)                           SPM_OBJ_ARS_LEGACY(iObj).fAngle

#define SPM_OBJ_CLASSIFICATION(iObj)                  SPM_OBJ_ARS_ATTRIBUTES(iObj).eClassification

#if (FCT_CFG_SENSOR_TYPE_RADAR)
#if(EM_ARS_OBJECT_LIST_INTFVER >= 5u)
#if (ALGO_SensorType != ALGO_CFG_ARS400Entry)
#define OBJ_RCS_NEAR(iObj)                        SPM_OBJ_ARS_SENSORSPECIFIC(iObj).fCurrTgtRCSNear
#define OBJ_RCS_FAR(iObj)                         SPM_OBJ_ARS_SENSORSPECIFIC(iObj).fCurrTgtRCSFar
#endif
#endif
#endif

#define SPM_GET_EM_FCT_CYCLE_MODE_PTR             FCTSEN_pSPMEmFctCycleMode//FCTSEN_pACCEmFctCycleMode
#define SPM_CYCLE_TIME                            SPM_GET_EM_FCT_CYCLE_MODE_PTR->fEmFctCycleTime//TASK_CYCLE_TIME        // TPGetCycleTime()
#define SPM_GDB_CYCLE_MODE                        SPM_GET_EM_FCT_CYCLE_MODE_PTR->eCycleMode        //TPGetCycleMode();


#define SPM_GET_PERF_DEG_DATA_PTR                     FCTSEN_pSPMPerfDegrData

#if (EM_PERF_DEGR_INTFVER  >= 6u) 
#if (ALGO_SensorType == ALGO_CFG_ARS400Entry)
#define SPM_PD_GET_FUSED_RANGE_NEAR_VALUE                 SPM_GET_PERF_DEG_DATA_PTR->RangeFused[SYS_SCAN_NEAR].fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
#else
#define SPM_PD_GET_FUSED_RANGE_NEAR_VALUE                 SPM_GET_PERF_DEG_DATA_PTR->RangeFused[SYS_SCAN_NEAR].fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
#define SPM_PD_GET_FUSED_RANGE_FAR_VALUE                  SPM_GET_PERF_DEG_DATA_PTR->RangeFused[SYS_SCAN_FAR].fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
#endif
#else
#define SPM_PD_GET_FUSED_RANGE_VALUE                  SPM_GET_PERF_DEG_DATA_PTR->RangeFused.fFusedRange        //PDGetRange(RangeData) RangeData.Val[PD_RANGE_MEAN]
#endif

#define SPM_GET_EGO_RAW_DATA_PTR                      FCTSEN_pSPMEgoDynRaw

#define SPM_EGO_CURVE_RAW                             SPM_GET_EGO_RAW_DATA_PTR->Lateral.Curve.Curve

#define GET_SPM_DATA_PTR                              FCTSEN_pSPMSysPerfMonStates //SPM

  /*! The FCT-Sen FuncID used for meas-freezes */
#if(defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor)) /* ARS4xx / ARS5xx case*/
  #if(defined(ALGO_ARS400Sensor) && (ALGO_ARS400Sensor)) /* ARS4xx case */
    #define FCT_SPM_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
    /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
    #define FCT_SPM_MEAS_FUNC_CHAN_ID   60u
  #elif(defined(ALGO_ARS500Sensor) && (ALGO_ARS500Sensor))
    #define FCT_SPM_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
    /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
    #define FCT_SPM_MEAS_FUNC_CHAN_ID   60u
  #else /* SRR case */
    #define FCT_SPM_MEAS_FUNC_ID        COMP_ID_FCT60
    /*! The FCT-Sen FuncChannelID used for meas-freezes */
    #define FCT_SPM_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
  #endif
#else /* camera case */
  #define FCT_SPM_MEAS_FUNC_ID        COMP_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
  #define FCT_SPM_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
#define FCT_SPM_FREEZE_DATA(pInfo, pData, Callback)        (pFCTSenServiceFuncts->pfMeasFreeze)((pInfo), (pData), (Callback))
#else
#define FCT_SPM_FREEZE_DATA(pInfo, pData, Callback)         MEASFreezeDataMTS((pInfo), (pData), (Callback))
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT INTERN)
*****************************************************************************/

/*! operating modes of sub-component */
typedef enum FCTSenSPMState{
  FCT_SEN_SPM_INIT,       /*!< initialize all    */
  FCT_SEN_SPM_RUN,        /*!< normal processing */
  FCT_SEN_SPM_RG_HIGH,    /*!< normal processing, but set RGLength to HIGH Resolution */
  FCT_SEN_SPM_SHUTDOWN,   /*!< shutdown (system in error, but recovery possible) */
  FCT_SEN_SPM_ERROR       /*!< fatal error, no recovery*/
} FCTSenSPMState_t;

typedef struct FCTSenSPMFrame {
  AlgoCycleCounter_t  uiCycleCounter;    /*!< The FCT_SEN cycle counter */
  boolean             bFirstCycleDone;   /*!< Boolean showing if first cycle was done */
  boolean             bSPMIsInitialized; /* Flag that shows if SPM was or was not initialized*/
  FCT_OP_MODE_t       eSPMOpMode;        /*!< FCT requested operation mode */
  SPMCompState_t      eSPMState;         /*!< SPM current operation mode */
  SPMVersions_t Versions;                /*!< SPM versions */
} FCTSenSPMFrame_t;

/* date: 2015-06-17, reviewer: Lonard jaison manohar(uidj2547), reason: Simulation specific macro */
typedef enum {
  FCTSEN_RTA_SPM,                           /* System Performance Monitoring runtime */
  SPM_RTA_PRE_PROCESS,                      /* SPM pre process RTA event */
  SPM_RTA_BLOCKAGE_PROCESS,                 /* SPM blockage process RTA event*/
  FCTSEN_RTA_SPM_NOF_CHECKPOINTS            /* This line has to be the last to determine the size of the structure */
} SPM_t_LocalID; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

#if FCT_CFG_RUNTIME_MEAS
/* Virtual address for FCT ACC runtime measurement freeze in the device (to be moved to rte) */
#ifndef FCT_MEAS_ID_SPM_RUNTIME_DEBUG
#define FCT_MEAS_ID_SPM_RUNTIME_DEBUG 0x202737F0u //TODO: define in interface sheet
#endif

typedef struct FCT_SPMRuntimeInfo
{
  uint32 uRuntime[FCTSEN_RTA_SPM_NOF_CHECKPOINTS];
}FCT_SPMRuntimeInfo_t;
#endif

#if(FCT_SEN_ERROR_OUT_INTFVER < 0xB)
typedef enum{
  SPM_INIT_ERROR,
  SPM_ALN_ERROR, 
  SPM_VDY_ERROR 
} SPM_t_e_Error;
#endif

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*! data of object loss statistic */
extern MEMSEC_REF SPMObjectLoss_t    SPMObjectLoss;

/*! data of SPM */
extern MEMSEC_REF SPMData_t SPMData;

/*****************************************************************************
  FUNCTION
*****************************************************************************/

/*****************************************************************************
  CONSTANTS (COMPONENT INTERN)
*****************************************************************************/
#define VDY_VEH_DYN_INT_VER_THLD (32U)

/*****************************************************************************
  VARIABLES (COMPONENT INTERN)
*****************************************************************************/
extern FCTSenSPMFrame_t t_FCTSenSPMFrame;

//#if (FCT_CFG_EM_FCT_CYCLEMODE)
//extern MEMSEC_REF const EmFctCycleMode_t       * FCTSEN_pSPMEmFctCycleMode;   /*!< Global system cycle mode etc. data */
//#endif

//extern MEMSEC_REF const PerfDegr_t             * FCTSEN_pSPMPerfDegrData;     /*!< Performance degradation input data */

//extern MEMSEC_REF const VehDyn_t               * FCTSEN_pSPMEgoDynRaw;        /*!< Performance degradation input data */

//extern MEMSEC_REF SysPerfMonStates_t           * FCTSEN_pSPMSysPerfMonStates; /*!< System performance monitor output data */

//#if (FCT_CFG_OBJECT_LIST_PROC)
//#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
//extern MEMSEC_REF const AssessedObjList_t      * FCTSEN_pSPMPubFctObj;         /*!< The public FCT object data */
//#endif
//#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
//extern MEMSEC_REF const EM_t_GenObjectList     * FCTSEN_pSPMEmGenObjList;     /*!< The generic EM object data */
//#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
//extern MEMSEC_REF const EM_t_ARSObjectList     * FCTSEN_pSPMEmARSObjList;
//#endif
//#else
//extern MEMSEC_REF const ObjectList_t           * FCTSEN_pSPMEmObjList;        /*!< The public EM object data */
//#endif
//#endif

//#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
//extern MEMSEC_REF const SLATE_SPM_Data_t * FCTSEN_pSLATE_SPM_Data;
//#endif

/*****************************************************************************
  FUNCTIONS (COMPONENT INTERN)
*****************************************************************************/

/// @brief Set operation mode of SPM sub-component in FCT_SEN task
///
/// @pre                Check for SPM operating mode and FCT operating mode
/// @post               None
///
/// @param[in] t_SPMCompState : SPM operation mode
///
/// @return             void
///
/// @globals
///          t_FCTSenSPMFrame.eSPMState : SPM Operation mode
///
/// @InOutCorrelation   Set the SPM operating mode in FCT_SEN task with the value given in t_SPMOpModeValue
/// @startuml "Call sequence for FCTSen_v_SetSPMOperationMode"
///
/// spm_algocontrol -> spm_main : FCTSen_v_SPMProcessStates() calls FCTSen_v_SetSPMOperationMode(t_SPMCompState)
/// activate spm_main
///   spm_main --> spm_algocontrol : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-532-0006e2e0
///
extern void FCTSen_v_SetSPMOperationMode(const SPMCompState_t t_SPMCompState);


/// @brief Set SPM operationg mode based on FCT operating mode
///
/// @pre                None
/// @post               None
///
/// @param[in] eOpMode : the operation mode of FCT to use [FCT_OP_MODE_t as in Rte_Type.h]
///
/// @return             void
///
/// @globals
///          b_FCTSenSPMIsInitialized :  Fct sen SPM and it's subcomponents initialization status\n
///          StateSPM : StateSPM : SPM sub-module state [StateSPM_t as in spm_ext.h]\n
///          FCTSenFrame.eFCTState : FCT current operation mode [FCTSenState_t as in fct_sen-h]\n
///
/// @InOutCorrelation   Based on FCT_SEN operating mode given in eOpMode set the SPM operating mode according to
///                     FCT_SEN opperating mode.
/// @startuml "Call sequence for FCTSen_v_SPMProcessStates"
///
/// spm_main -> spm_algocontrol : FCTSen_SPM_Exec() calls FCTSen_v_SPMProcessStates(FCT_OP_MODE_t)
/// activate spm_algocontrol
///   spm_algocontrol --> spm_main : 
/// deactivate spm_algocontrol
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-536-0006e2e0
///
extern void FCTSen_v_SPMProcessStates (FCT_OP_MODE_t eOpMode);


/// @brief Set operation modes of SPM sub-component in case of Error
///
/// @pre                Check for availability of SPM require ports and FCT_SEN operating mode
/// @post               None
///
/// @param[in] isRecoveryPossible : Status to inform whether the shutdown should takes place or not [TRUE, FASLE]
///
/// @return             void
///
/// @globals
///          b_FCTSenSPMIsInitialized : FCT_SEN SPM and it's subcomponents initialization status [TRUE, FALSE]\n
///          SPM_GET_PERF_DEG_DATA_PTR->sSigHeader.eSigStatus : Performance degradation data signal status 
///                   [AlgoSignalState_t as defined in rte_type.h]\n
///
/// @InOutCorrelation   Set operation mode of SPM component in case of error indicating whenever the shutdown shouldd
///                     take place or not.
/// @startuml "Call sequence for FCTSen_v_SPMSignalErrorShutdown"
///
/// spm_main -> spm_algocontrol : FCT_v_SetSenSPMFrameData() calls FCTSen_v_SPMSignalErrorShutdown(boolean)
/// activate spm_algocontrol
///   spm_algocontrol --> spm_main : 
/// deactivate spm_algocontrol
/// @enduml
///
/// @testmethod         Test order of calls (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-539-0006e2e0
///
extern void FCTSen_v_SPMSignalErrorShutdown(const boolean isRecoveryPossible);


/// @brief FCT MEAS callback function
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals            None
///
/// @InOutCorrelation   Callback function as requested by MEASFreezeData. Right now this is dummy function.
/// @startuml "Call sequence for FCTSen_v_SPMMeasCallback"
///
/// spm -> spm_meas : MEASFreezeDataMTS() calls FCTSen_v_SPMMeasCallback()
/// activate spm_meas
///   spm_meas --> spm : 
/// deactivate spm_meas
/// @enduml
///
/// @testmethod         None, dummy function
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-535-0006e2e0
///
extern void FCTSen_v_SPMMeasCallback(void);

#if (FCT_MEASUREMENT == SWITCH_ON)
/// @brief Freezes Frame Measurement Data
///
/// @pre                The passed pFrame pointer filled, and the area pointed to remains static 
///                     (i.e.: buffered meas freeze may be used)
/// @post               None
///
/// @return             void
///
/// @globals
///          t_FCTSenSPMFrame : Frame information about SPM component [FCTSenSPMFrame_t as defined in spm_ext.h]\n
///          t_FCTSenSPMSyncRef : Simulation sync structure contains Signal Headers of every Input Port[FCTSen_SPMSyncRef_t as defined in spm_ext.h]\n
///          FCTSEN_pSPMSenCompState : SPM component state [AlgoCompState_t as defined in acdc_int.h]\n
///
/// @InOutCorrelation   Freezes Frame Measurement Data (SW versions)
/// @startuml "Call sequence for FCTSen_v_SPMFrameFreeze"
///
/// spm_main -> spm_meas : FCTSen_v_SPMFrameFreeze()
/// activate spm_meas
///   alt #Green FCT_SEN_CFG_FREEZE_USE_CALLBACK == SWITCH_ON
///     spm_meas -> spm_int : FCT_SPM_FREEZE_DATA(pInfo, pData, Callback)
///     spm_int --> spm_meas : 
///     spm_meas -> spm_int : FCT_SPM_FREEZE_DATA(pInfo, pData, Callback)
///     spm_int --> spm_meas : 
///   else FCT_SEN_CFG_FREEZE_USE_CALLBACK == SWITCH_OFF
///     spm_meas -> spm_int : FCT_SPM_FREEZE_DATA(pInfo, pData, NULL)
///     spm_int --> spm_meas : 
///     spm_meas -> spm_int : FCT_SPM_FREEZE_DATA(pInfo, pData, NULL)
///     spm_int --> spm_meas : 
///   end
///   group #LightBlue FCT_CFG_USE_ALGOCOMPSTATE == SWITCH_ON
///     alt #Green FCT_SEN_CFG_FREEZE_USE_CALLBACK == SWITCH_ON
///       spm_meas -> string : memcpy(FCTSen_SPMFreezeBufferSenCompState, FCTSEN_pSPMSenCompState, sizeof(AlgoCompState_t))
///       string --> spm_meas : 
///       spm_meas -> spm_int : FCT_SPM_FREEZE_DATA(pInfo, pData, Callback)
///       spm_int --> spm_meas : 
///     else FCT_SEN_CFG_FREEZE_USE_CALLBACK == SWITCH_OFF
///       spm_meas -> spm_int : FCT_SPM_FREEZE_DATA(pInfo, pData, Callback)
///       spm_int --> spm_meas : 
///     end
///   end
/// deactivate spm_meas
/// spm_meas --> spm_main : 
/// @enduml
///
/// @testmethod         Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-534-0006e2e0
///
extern void FCTSen_v_SPMFrameFreeze(void);
#endif

/// @brief Initialization of port handler list for SPM
///
/// @pre                None
/// @post               None
///
/// @param[in] bKeepMeasDataCycle : Flag that shows if meas data are kept at initialization of handler list.
///
/// @return             void
///
/// @globals
///          SPMPortHandlerList : List of SPM provide and require port handlers
///
/// @InOutCorrelation   Initialize all port handlers to devault values (NULL/0).
/// @startuml "Call sequence for SPM_v_InitPortHandlerList"
///
/// spm_algocontrol -> spm_io : FCTSen_v_SPMProcessStates() calls SPM_v_InitPortHandlerList(bKeepMeasDataCycle)
/// activate spm_io
///   spm_io --> spm_algocontrol : 
/// deactivate spm_io
/// spm_io -> spm_io : SPM_v_ProcessPorts() calls SPM_v_InitPortHandlerList(bKeepMeasDataCycle)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
extern void SPM_v_InitPortHandlerList(boolean bKeepMeasDataCycle);

/// @brief Processing of SPM provide and request ports
///
/// @pre                None
/// @post               None
///
/// @param[in] pRequestPorts : SPM component require ports
/// @param[in] pProvidePorts :  SPM component provide ports
#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/// @param[in] pServiceFuncts : Service pointer provided by frame SW
#endif
#if(FCT_CFG_USE_ALGOCOMPSTATE)
/// @param[in,out] pErrorBuffer : the Error to set [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]
#endif
///
/// @return             void
///
/// @globals
///          SPMPortHandlerList : List of SPM provide and require port handlers
///
/// @InOutCorrelation   Call all the functions that are necessary for SPM port handler processing. Initialize SPM port
///                     handlers by keeping meas data, setup provide and request port handlers and check ports for errors.
///                     If errors were discovered then signal shut down of SPM without recover posibility.
/// @startuml "Call sequence for SPM_v_ProcessPorts"
///
/// spm_main -> spm_io : FCTSen_SPM_Exec() calls SPM_v_ProcessPorts(pRequestPorts, pProvidePorts, pServiceFuncts, pErrorBuffer)
/// activate spm_io
///   spm_io --> spm_main : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       
///
extern void SPM_v_ProcessPorts( reqFCTSenSPMPrtList_t const * const pRequestPorts,
                                SPMProPort_t          const * const pProvidePorts
#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                , AS_t_ServiceFuncts  const * const pServiceFuncts
#endif
#if(FCT_CFG_USE_ALGOCOMPSTATE)
                                , GenAlgoQualifiers_t       * const pErrorBuffer
#endif
                                );

/// @brief Setup of SPM request port handlers
///
/// @pre                None
/// @post               None
///
/// @param[in] pRequirePorts : Require ports of SPM component
/// @param[out] pPortHandlerList : SPM port handler list
///
/// @return             void
///
/// @InOutCorrelation   Setup information of each request port handler. If the request port has a valid header then it 
///                     will be used to setup the header of request port. Otherwise the header of request port will be 
///                     will be set using default values.
/// @startuml "Call sequence for SPM_v_SetupReqPortHandlers"
///
/// spm_io -> spm_io : SPM_v_ProcessPorts() calls SPM_v_SetupReqPortHandlers(pRequirePorts, pPortHandlerList)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       
///
static void SPM_v_SetupReqPortHandlers(reqFCTSenSPMPrtList_t const * const pRequirePorts, SPMPortHandlerList_t * const pPortHandlerList);

/// @brief Setup of SPM provide port handlers
///
/// @pre                None
/// @post               None
///
/// @param[in] pProvidePorts : Provide ports of SPM component
/// @param[in] pRequirePorts : Require ports of SPM component
/// @param[out] pPortHandlerList : SPM port handler list
///
/// @return             void
///
/// @InOutCorrelation   Setup information for each provide port handler based on request and provide ports of SPM component.
/// @startuml "Call sequence for SPM_v_SetupProPortHandlers"
///
/// spm_io -> spm_io : SPM_v_ProcessPorts() calls SPM_v_SetupProPortHandlers(pProvidePorts, pRequirePorts, pPortHandlerList)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       
///
static void SPM_v_SetupProPortHandlers(SPMProPort_t const * const pProvidePorts, reqFCTSenSPMPrtList_t const * const pRequirePorts, SPMPortHandlerList_t * const pPortHandlerList);

/// @brief Copy source signal header into destination signal header
///
/// @pre                Port signal header is not null
/// @post               None
///
/// @param[in] pSourceSigHeader : Source signal header
/// @param[in] eSigState : Signal state as defined in Rte_Type.h
/// @param[out] pDestSigHeader : Destination signal header.
///
/// @return             void
///
/// @InOutCorrelation   Copy data from source signal header into destination signal header and set signal state according
///                     to the parameter received.
/// @startuml "Call sequence for SPM_v_SetSigHeader"
///
/// spm_io -> spm_io : SPM_b_PortSpecificHandling() calls SPM_v_SetSigHeader(pDestSigHeader, pSourceSigHeader, eSigState) \nSPM_v_FillProPortHeaders() calls SPM_v_SetSigHeader(pDestSigHeader, pSourceSigHeader, eSigState)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static void SPM_v_SetSigHeader(SignalHeader_t * const pDestSigHeader, SignalHeader_t const * const pSourceSigHeader, AlgoSignalState_t eSigState);

/// @brief Set signal header in case of error
///
/// @pre                Request port is null, request port signal header is null orFCT control data pointer is null
/// @post               None
///
/// @param[out] pSigHeader : Signal header to be set
///
/// @return             void
///
/// @InOutCorrelation   Set header time and measurement counter to 0. Copy SPM cycle counter into header cycle counter and 
///                     set signal status to invalid.
/// @startuml "Call sequence for SPM_v_SetSigHeaderError"
///
/// spm_io -> spm_io : SPM_b_SetupPorts() calls SPM_v_SetSigHeaderError(pSigHeader) \nSPM_b_PortSpecificHandling() calls SPM_v_SetSigHeaderError(pSigHeader) \nSPM_v_FillProPortHeaders() calls SPM_v_SetSigHeaderError(pSigHeader)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static void SPM_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);

#if(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/// @brief Check for errors of service function pointer
///
/// @pre                None
/// @post               None
///
/// @param[in] pServiceFuncts : Service function pointer
///
/// @return             boolean : Flag that shows if there is an error relared to service function pointer
///
/// @InOutCorrelation   Check if service function pointer has valid information. If at least one information is not valid 
///                     then set error flag to true.
/// @startuml "Call sequence for SPM_b_CheckServiceFunctions"
///
/// spm_io -> spm_io : SPM_v_ProcessPorts() calls SPM_b_CheckServiceFunctions(pServiceFuncts)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static boolean SPM_b_CheckServiceFunctions(const AS_t_ServiceFuncts * pServiceFuncts);
#endif

/// @brief Setup request and provide ports of SPM component
///
/// @pre                None
/// @post               None
///
/// @param[in] pPortHandlerList : SPM port handler list
///
/// @return             boolean : Flag that shows ig there was error in setting port process
///
/// @InOutCorrelation   Setup request and provide ports global variable pointer. If the port which is set is null then 
///                     signalize error. In case that the port wich is set is a request port check for signal status and 
///                     port update. Signalize error if signal status is invalid or port was not updated for too many cicles.
/// @startuml "Call sequence for SPM_b_SetupPorts"
///
/// spm_io -> spm_io : SPM_v_ProcessPorts() calls SPM_b_SetupPorts(pPortHandlerList)
/// activate spm_io
///   spm_io -> spm_io : SPM_b_CheckPortUpdate(pInputPortMeasCycle, pLastMeasCycle, fTargetCycleTime, uAcceptableDrops)
///   spm_io -> spm_io : SPM_v_SetSigHeaderError(pSigHeader)
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static boolean SPM_b_SetupPorts(SPMPortHandlerList_t * pPortHandlerList);

/// @brief Check for specific SPM request and/or provide ports
///
/// @pre                None
/// @post               None
///
/// @param[in] pRequirePorts : Request ports of SPM component
/// @param[in] pProvidePorts : Provide ports of SPM component
///
/// @return             boolean : Flag that shows if there was an error related to the SPM specific request or provide ports
///
/// @InOutCorrelation   Check specific ports of SPM component to be valid and not to have an invalid signal status. If 
///                     the ports are not OK then signal shut down without recover posibility and set error flag to true.
/// @startuml "Call sequence for SPM_b_PortSpecificHandling"
///
/// spm_io -> spm_io : SPM_v_ProcessPorts() calls SPM_b_PortSpecificHandling(pRequirePorts, pProvidePorts)
/// activate spm_io
///   spm_io -> spm_io : SPM_v_SetSigHeader(pDestSigHeader, pSourceSigHeader, eSigState)
///   spm_io -> spm_io : SPM_v_SetSigHeaderError(pSigHeader)
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static boolean SPM_b_PortSpecificHandling(const reqFCTSenSPMPrtList_t * pRequirePorts, const SPMProPort_t * pProvidePorts);

/// @brief Check for request port update
///
/// @pre                Request port signal header is not null
/// @post               None
///
/// @param[in] pInputPortMeasCycle : Current request port time stamp
/// @param[in] pLastMeasCycle : Last measured cycle time
/// @param[in] fTargetCycleTime : Target cycle time
/// @param[in] uAcceptableDrops : Acceptable number of cycle drops
///
/// @return             boolean : Flag that shows if request port was not updated for too long time
///
/// @InOutCorrelation   For each request port of SPM component check the time between last update of port and current cycle.
///                     If the passed time is higher than a threshold then set error flag to true in order to signalize 
///                     that request port was not updated.
/// @startuml "Call sequence for SPM_b_CheckPortUpdate"
///
/// spm_io -> spm_io : SPM_b_SetupPorts() calls SPM_b_CheckPortUpdate(pInputPortMeasCycle, pLastMeasCycle, fTargetCycleTime, uAcceptableDrops)
/// activate spm_io
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static boolean SPM_b_CheckPortUpdate(AlgoDataTimeStamp_t const * const pInputPortMeasCycle, 
                                    sMeasCycleMonitor * const pLastMeasCycle, 
                                    float32 const fTargetCycleTime, uint8 uAcceptableDrops);

/// @brief Copy values computed by SPM into provide ports
///
/// @pre                None
/// @post               None
///
/// @param[in] tBlockageState : State of blockage (unknown, active, inactive)
/// @param[in] tSelftestState : State of selftest (unknown, active, inactive)
/// @param[out] pProvidePorts : SPM provide ports
///
/// @return             void
///
/// @InOutCorrelation   Copy blockage and selftest states into SPM provide ports. If LOHP component is active then set 
///                     blockage flag whenever blockage is active or selftest state is not inactive. Afterwards copy SPM 
///                     errors into error out data structure.
/// @startuml "Call sequence for SPM_v_SetProPortsData"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls SPM_v_SetProPortsData(pProvidePorts, tBlockageState, tSelftestState)
/// activate spm_main
///   spm_main -> spm_error : FCTSen_v_SPMFillErrorOut(pt_ErrorOut)
///   activate spm_error 
///   spm_error --> spm_main : 
///   deactivate spm_error
///   spm_main -->spm_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
static void SPM_v_SetProPortsData(SPMProPort_t * const pProvidePorts, AlgoErrorState_t * tBlockageState, AlgoErrorState_t * tSelftestState);

/// @brief Fill SPM provide ports headers
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///          SPMPortHandlerList : List of SPM provide and require port handlers
///
/// @InOutCorrelation   Fill SPM provide ports headers based on component state. If component is in error state then set 
///                     signal states to invalide. If component is in init or not running state then set signals state to 
///                     init. If component is in running or in success state then set signal state based on SPM dependent 
///                     request port signal state. Otherwise set signals state to invalid.
/// @startuml "Call sequence for SPM_v_FillProPortHeaders"
///
/// spm_main -> spm_io : FCTSen_SPM_Exec() calls SPM_v_FillProPortHeaders()
/// activate spm_io
///   spm_io -> spm_io : SPM_v_SetSigHeader(pDestSigHeader, pSourceSigHeader, eSigState)
///   spm_io -> spm_io : SPM_v_SetSigHeaderError(pSigHeader)
///   spm_io --> spm_io : 
/// deactivate spm_io
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///                     
///
/// @traceability       
///
extern void SPM_v_FillProPortHeaders(void);

#if(FCT_CFG_USE_ALGOCOMPSTATE)
/// @brief Set algo component scheduler based on SPM component state, scheduled operation mode and qualifier
///
/// @pre                Provide ports not null
/// @post               None
///
/// @param[in] scheduledOpMode : Provided operation mode
/// @param[in] bufferedQualifier : Internal buffer for AlgoQualifier (error status)
/// @param[out] pSenCompState : AlgoCompState interface to scheduler
///
/// @return             void
///
/// @InOutCorrelation   Set AlgoCompState based on SPM operation mode. If SPM operation mode is NOT_RUNNING or 
///                     TEMPORARY_ERROR set AlgoCompState component state to TEMPORARY_ERROR and error code to UNKNOWN.
///                     Otherwise set AlgoCompState component state to STATE_RUNNING and error to NO_ERROR.
/// @startuml "Call sequence for SPM_v_SetCompState"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls SPM_v_SetCompState(pSenCompState, scheduledOpMode, bufferedQualifier)
/// activate spm_main
///   spm_main --> spm_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       
///
  static void SPM_v_SetCompState(AlgoCompState_t * const pSenCompState, FCT_OP_MODE_t const scheduledOpMode, GenAlgoQualifiers_t const bufferedQualifier);
#endif
#endif

#ifdef __cplusplus
};
#endif

#endif // FCT_CFG_SIGNAL_PERF_MONITORING
#endif

/* End of conditional inclusion */
//#else
#endif  /*!<SPM_INT_H_INCLUDED */

