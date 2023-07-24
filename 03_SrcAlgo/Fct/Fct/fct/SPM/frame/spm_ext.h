// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.40 $

// This file contains the headers of functions called from frame FCT and defines of request/provide SPM ports.
//
// @file       spm_ext.h
//
// @mainpage   SPM_SensorPerformanceMonitoring
// @section    TEMPLATE General description
//             SPM component is responsible by monitoring the performance of the sensor and trigger blockage in case
//             that the performance cannot satisfy the safety requirements. The peformance of the sensor is evaluated
//             by monitoring the visibility range of the sensor, the relevant object in front of ego car and situations
//             in which the sensor is unable to detect any surrounding object(full blindness). 
// @section    Modules
//             The SPM component is splitted into the follwoing modules
// @subsection Main 
//             This module is responsible with call of main processing functions, setting the SPM provide ports
//             and the frame data\n
// @subsection Algocontrol
//            This module is responsible with setting the operation mode and the shutdown error signal of SPM\n
// @subsection Error
//             This module is responsible with fill of the output errors based on SPM information about blocakge, 
//             selftest and interference\n
// @subsection Meas
//             This module is responsible with freezing SPM data for simulation framework\n
// @subsection Output
//             This module is responsible with setting SPM custom output based on SPM information about blockage and 
//             selftest\n
// @subsection Spm
//             This module is responsible with calling all the necessary processing functions for selftest, object loss,
//             interference and blocakge state determination\n
// @subsection Selftest
//             This module is responsible with the range observer in order to determine if the sensor is able to detect 
//             the surounding environment\n
// @subsection Objectloss
//             This module is responsible with monitoring of relevant object (the object in front of ego)\n
// @subsection Interference
//             This module is responsible with computing the interference range and communicate the computed range to 
//             DEM component\n
// @subsection Blockage
//             This module is responsible with determining the blocakge state based on inputs recieved from Pefrormance 
//             Degradation component, from Alignment and from ObjectLoss observer\n

/***********************************************************************
CHANGES:                   $Log: spm_ext.h  $
CHANGES:                   Revision 1.40 2020/06/30 16:27:54CEST Pallo, Istvan (palloi) 
CHANGES:                   Revert SRR SPM split changes on trunk
CHANGES:                   Revision 1.39 2020/06/25 13:10:56CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix compilation errors in ARS
CHANGES:                   Revision 1.38 2020/06/25 08:09:42CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.37 2020/06/02 16:24:48CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove VehSig request port and sig header
CHANGES:                   Revision 1.36 2020/03/03 07:58:10CET Pallo, Istvan (palloi) 
CHANGES:                   Update SPM port list and add new sig header for VehSig
CHANGES:                   Revision 1.35 2020/01/16 10:56:50CET Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added VisibilityRange implementation for SRR
CHANGES:                   Revision 1.34 2019/09/16 15:57:39CEST Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added Interference Detection Logic for SRR
CHANGES:                   Revision 1.33 2019/06/12 20:35:15CEST Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added blockage logic for Roller Bench test
CHANGES:                   Revision 1.31 2019/05/28 07:49:19CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.30 2019/04/23 06:15:32CEST Pallo, Istvan (palloi) 
CHANGES:                   Add missing config switch for vehiche info sig header
CHANGES:                   Revision 1.29 2019/04/22 13:22:45CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new request port for SPM
CHANGES:                   Revision 1.28 2018/11/19 13:29:12CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update design for SPMProcess function
CHANGES:                   Revision 1.27 2018/09/24 15:15:38CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch and code for SRR
CHANGES:                   Revision 1.26 2018/04/30 08:51:25CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove unused sig headers from SPMSyncRef
CHANGES:                   Revision 1.25 2018/04/13 10:03:41CEST Pallo, Istvan (palloi) 
CHANGES:                   Correct config switch for ALN sync ref sig header
CHANGES:                   Revision 1.24 2018/04/12 14:31:14CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove variable type request ports and add structure type ports
CHANGES:                   Revision 1.23 2018/03/26 14:11:04CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove set ports function headers
CHANGES:                   Revision 1.22 2018/03/15 14:00:36CET Pallo, Istvan (palloi) 
CHANGES:                   New request port and sinc ref signal header for ALN monitoring
CHANGES:                   Revision 1.21 2018/03/12 14:50:29CET Pallo, Istvan (palloi) 
CHANGES:                   New addresses for SPMErrorOut and SPMHcData in order to avoid memory overlap in ARS430BW18_LSB_DevPath
CHANGES:                   Revision 1.20 2018/03/09 13:19:22CET Pallo, Istvan (palloi) 
CHANGES:                   Rename spm sw version to spm version
CHANGES:                   Revision 1.19 2018/03/09 08:59:12CET Pallo, Istvan (palloi) 
CHANGES:                   Add address defines for SPM error out and SPM hc data
CHANGES:                   Revision 1.18 2018/02/28 13:21:29CET Pallo, Istvan (palloi) 
CHANGES:                   Update address for SPMSyncRef
CHANGES:                   Revision 1.17 2018/02/28 11:32:03CET Pallo, Istvan (palloi) 
CHANGES:                   Relocate SPMSyncRef near to SPMParams in order to avoid memory overlap with SLATE data structures.
CHANGES:                   Revision 1.16 2018/02/28 08:08:32CET Pallo, Istvan (palloi) 
CHANGES:                   Update SPM sync ref address to avoid memory overlap
CHANGES:                   Revision 1.15 2018/02/27 17:09:38CET Pallo, Istvan (palloi) 
CHANGES:                   Remove PDO comment
CHANGES:                   Revision 1.14 2018/02/26 15:10:11CET Pallo, Istvan (palloi) 
CHANGES:                   Add align state sync ref sig header
CHANGES:                   Revision 1.13 2018/02/26 08:53:02CET Pallo, Istvan (palloi) 
CHANGES:                   Add signal header and uiVersionNo for SPM HC data pro port
CHANGES:                   Revision 1.12 2018/02/23 10:44:48CET Pallo, Istvan (palloi) 
CHANGES:                   Remove commented sync ref and add missing ones.
CHANGES:                   Restructure existing headers.
CHANGES:                   Revision 1.11 2018/01/17 08:01:48CET Pallo, Istvan (palloi) 
CHANGES:                   Add desing missing parameter
CHANGES:                   Revision 1.10 2018/01/17 07:37:41CET Pallo, Istvan (palloi) 
CHANGES:                   Design updates
CHANGES:                   Revision 1.9 2018/01/16 08:56:15CET Pallo, Istvan (palloi) 
CHANGES:                   Update design
CHANGES:                   Revision 1.8 2017/12/05 18:44:55CET Pallo, Istvan (palloi) 
CHANGES:                   Remove error out structure - added into fct_types.
CHANGES:                   Update SPM ports naming and function headers
CHANGES:                   Revision 1.7 2017/11/23 14:01:51CET Pepenar, Alin (pepenara) 
CHANGES:                   Update detailed design: added traceability
CHANGES:                   Revision 1.6 2017/11/22 08:07:15CET Pallo, Istvan (palloi) 
CHANGES:                   Replace LOPC config switch with LOHP config switch as pSPM_HC_Data is used in LOHP
CHANGES:                   Revision 1.5 2017/11/14 13:56:58CET Pallo, Istvan (palloi) 
CHANGES:                   Update design and add test method for each function
CHANGES:                   Revision 1.4 2017/10/17 15:08:25CEST Pallo, Istvan (palloi) 
CHANGES:                   Change ref sync starting address. Add headers
CHANGES:                   Revision 1.3 2017/08/11 08:34:55CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functions uml diagrams
CHANGES:                   Revision 1.2 2017/06/21 09:53:32CEST Pallo, Istvan (palloi) 
CHANGES:                   New functions headers.
CHANGES:                   New functions declarations.
CHANGES:                   New file header.
CHANGES:                   Revision 1.1 2017/03/17 13:16:57CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

****************************************************************************/
#ifndef SPM_EXT_H_INCLUDED
#define SPM_EXT_H_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "algo_type.h"
#include "fct_glob_ext.h"
#include "spm_types.h"
#include "spm_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if(FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)
/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

#ifndef FCT_MEAS_ID_SEN_SPM_INPUT_SIGHEADERS
#define FCT_MEAS_ID_SEN_SPM_INPUT_SIGHEADERS (0x20240701u)// TODO define in interface sheet
#endif

#ifndef SPM_MEAS_ID_ERROR_OUT_PORT
#define SPM_MEAS_ID_ERROR_OUT_PORT (0x202407C0u)
#endif

#ifndef SPM_MEAS_ID_HC_DATA_PORT
#define SPM_MEAS_ID_HC_DATA_PORT (0x202407E0u)
#endif
/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/* TPW version number */
#define SPM_VERSION (0x035500uL)

#if(FCT_CFG_LOHP_COMPONENT)
typedef struct  
{
  SignalHeader_t sSigHeader; /* Port signal header */
  uint32 uiVersionNumber;    /* Port version number */
  boolean b_SensorBlocked;	 /* Flag that shows if sensor is blocked or not */
}SPM_HC_Data_t;
#endif

/*! SPM provide ports struct */
typedef struct FctSenSPMProPort{

#if (FCT_CFG_ERROR_OUTPUT_SEN)
  SPMErrorOutProPort_t * pErrorOut;
#endif

#if (SYS_PERF_MON_OUT_INTFVER >= 3u)
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SysPerfMonStates_t * pSysPerfMonStates;  /*!< System performance monitor output data */
#endif /* ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF)) */
#endif /* (!FCT_CFG_SHORT_RANGE_FUNCTIONS) */

#endif /* (SYS_PERF_MON_OUT_INTFVER >= 3u) */
#if (FCT_CFG_LOHP_COMPONENT)
  SPM_HC_Data_t * pSPM_HC_Data;
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    AlgoCompState_t * pSenCompState;  /* AlgoCompState interface to scheduler */
#endif
}SPMProPort_t;

/*! operating modes of sub-component */
typedef enum {
  SPM_INIT,                /*!< initialize all */
  SPM_OK,                  /*!< normal processing */
  SPM_FREEZE,              /*!< freeze SPM data without processing */
  SPM_EOL                  /*!< end of line mode */
} StateSPM_t;

/*! sub-module state */
extern SPMCompState_t SPMState;

/*! Inputs required by SPM component for sensor cycle processing */
typedef struct reqFCTSenSPMPrtList{
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const ALN_S_Monitoring_t                    * pt_ALNMonitoring;   /* Alignment monitoring input for SPM */
#endif
  const VehDyn_t                              * pEgoDynObjSync;     /* The dynamic vehicle ego data object sync */
  const Fct_blockage_algo_parameters_t        * pt_BSWAlgoBlockage; /* BSW blockage parameters*/
  const FCTCtrlData_t                         * pSenCtrlData;       /* FCT control data */
  const VehDyn_t                              * pEgoDynRaw;         /* The dynamic vehicle ego data raw */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const FctVeh2SenInfo_t                 * pFctVehLongOut;  /* Longitudinal control */
#endif
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  const EmFctCycleMode_t                      * pEmFctCycleMode;    /* The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  const EM_t_GenObjectList                    * pEmGenObjList;      /* EM generic object list */
  #if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    const EM_t_ARSObjectList                  * pEmARSObjList;      /* EM ARS-technology-specific object list */
  #endif
#else
  const ObjectList_t                          * pPubEmObj;          /* The public EM object data */
#endif
#endif
  const PerfDegr_t                            * pPerfDegrData;      /* Performance degradation input data */
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const PerfDegrExtInput_t                    * pPerfDegrExtInput;  /* Performance degradation external input (short range sensor info) */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  const AssessedObjList_t                     * pPubFctObj;         /* The public FCT object data */
#endif
#endif
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  const SLATE_SPM_Data_t                      * pSLATE_SPM_Data;    /* Slate data for SPM*/
#endif
} reqFCTSenSPMPrtList_t;

/*! @brief Simulation sync structure contains Signal Headers of every Input Port */
typedef struct FCTSen_SPMSyncRef {
  SignalHeader_t sSigHeader;      /* sSigHeader */
  SignalHeader_t SenCtrlData;     /* SenCtrlData */
  SignalHeader_t EgoDynRaw;       /*The dynamic vehicle ego data raw */
  SignalHeader_t EgoDynObjSync;   /* The dynamic vehicle ego data object sync */
  #if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    SignalHeader_t FctVehLongOut;    /* Longitudinal control*/
  #endif
  #if (FCT_CFG_EM_FCT_CYCLEMODE)
    SignalHeader_t EmFctCycleMode;  /* The global sensor state */
  #endif
  #if (FCT_CFG_OBJECT_LIST_PROC)
    #if (FCT_USE_EM_GENERIC_OBJECT_LIST)
      SignalHeader_t EmGenObjList;    /* EM generic object list */
      #if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
        SignalHeader_t EmARSObjList;    /* EM ARS-technology-specific object list */
      #endif
    #else
      SignalHeader_t PubEmObj;        /* The public EM object data */
    #endif
    #if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
      SignalHeader_t PubFctObj;         /* The public FCT object data */
    #endif
  #endif
  #if (FCT_CFG_SIGNAL_PERF_MONITORING)
    SignalHeader_t PerfDegrData;    /* Performance degradation input data */
  #endif
  #if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    SignalHeader_t BswAlgoParameters;  /* Input algo parameters from BSW */
  #endif
#if((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    SignalHeader_t PerfDegrExtInput;
#endif
#if(FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
    SignalHeader_t SlateData;
#endif
#if((FCT_CFG_ALIGNMENT_MONITORING_INPUT) && (FCT_CFG_ALIGNMENT_MONITORING_INPUT))
    SignalHeader_t ALNMonitoring;
#endif
  boolean b_Dummy;
} FCTSen_SPMSyncRef_t;

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/// @brief Entry point of SPM component
///
/// @pre                 None
/// @post                None
///
/// @param[in] p_RequirePorts : SPM request ports
/// @param[in] t_FCTSenFrameFCTOpMode : FCT operation mode as defined in rte_type.h
/// @param[in] p_ServiceFuncts : Reference to service functions provided by Frame [AS_t_ServiceFuncts as defined in algo_services_types.h]
///
/// @param[out] p_ProvidePorts : SPM provide ports as defined in spm_ext.h
///
/// @return              void
///
/// @globals
///          e_RTA_EVT_AlgoStart : Start event set when starting the processing\n
///          e_RTA_EVT_AlgoEnd : End event set when the data processing finished\n
///          FCTSEN_RTA_SPM : System Performance Monitoring runtime for SPM component\n
///
/// @InOutCorrelation    Call all functions for setting SPM operating mode based on FCT operating, pocess of the data
///                      which are received through the request ports and freeze the SPM data for simulation framework.
///                      After all the computations were done call the functions to set the corresponding output on the
///                      provide ports.
/// @startuml "Call sequence for FCT_Sen_SPM_Exec"
///
/// fct_sen_main -> spm_main : **FCTSen_Exec()** calls\n**FCTSen_SPM_Exec**(p_RequirePorts, p_ProvidePorts, t_FCTSenFrameFCTOpMode, p_ServiceFuncts)
/// activate spm_main
///   group #LightBlue IF FCT_CFG_RUNTIME_MEAS == SWITCH_ON
///     spm_main -> spm_main : FCTSEN_SPMRuntimeMeasInit()
///   end
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, FCTSEN_RTA_SPM, u_OptData)
///   alt #Green FCT_CFG_USE_ALGOCOMPSTATE == SWITCH_ON
///     spm_main -> spm_main : FCT_v_SetSenSPMFrameData(p_RequirePorts, &AlgoErrorBuffer)
///   else FCT_CFG_USE_ALGOCOMPSTATE == SWITCH_OFF
///     spm_main -> spm_main : FCT_v_SetSenSPMFrameData(p_RequirePorts)
///   end
///   spm_main -> spm_algocontrol : FCTSen_v_SPMProcessStates(t_FCTSenFrameFCTOpMode)
///   spm_algocontrol --> spm_main : 
///   spm_main -> spm_main : FCTSen_v_SPMSetupPorts(p_RequirePorts, p_ProvidePorts)
///   spm_main -> spm_main : FCTSen_v_SPMPreProcessing(p_RequirePorts, p_ProvidePorts, p_ServiceFuncts, &AlgoErrorBuffer)
///   spm_main -> spm : SPMProcess( PerfDegr_t, AlgoErrorState_t, AlgoErrorState_t, boolean, SYSDampState_t, e_AlignState_t, float32, fTime_t, Fct_blockage_algo_parameters_t)
///   spm --> spm_main
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, FCTSEN_RTA_SPM, u_OptData)
///   group #LightBlue FCT_MEASUREMENT == SWITCH_ON
///     spm_main -> spm_meas : FCTSen_v_SPMProcessMeasFreeze(p_ProvidePorts)
///     spm_meas --> spm_main : 
///   end
///   alt #Green FCT_MEASUREMENT == SWITCH_ON AND FCT_CFG_USE_SERVICE_POINTER_FUNCTS == SWITCH_ON
///     spm_main -> spm_meas : FCTSen_v_SPMFrameFreeze()
///     spm_meas --> spm_main : 
///   else FCT_MEASUREMENT == SWITCH_OFF OR FCT_CFG_USE_SERVICE_POINTER_FUNCTS == SWITCH_OFF
///     spm_main -> spm_meas : FCTSen_v_SPMFrameFreeze()
///     spm_meas --> spm_main : 
///   end
///   spm_main --> fct_sen_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-528-0006e2e0
///
extern void FCTSen_SPM_Exec(const reqFCTSenSPMPrtList_t * p_RequirePorts, SPMProPort_t * const p_ProvidePorts, const FCT_OP_MODE_t t_FCTSenFrameFCTOpMode,
                            const AS_t_ServiceFuncts *p_ServiceFuncts);
#else
/// @brief Entry point of SPM component
///
/// @pre                 None
/// @post                None
///
/// @param[in] p_RequirePorts : SPM request ports
/// @param[in] t_FCTSenFrameFCTOpMode : FCT operation mode [as defined in rte_type.h]
///
/// @param[out] p_ProvidePorts : SPM provide ports [as defined in spm_ext.h]
///
/// @return              void
///
/// @globals
///        e_RTA_EVT_AlgoStart : Start event set when starting the processing\n
///        e_RTA_EVT_AlgoEnd : End event set when the data processing finished\n
///        FCTSEN_RTA_SPM : System Performance Monitoring runtime for SPM component\n
///
/// @InOutCorrelation    Call all functions for setting SPM operating mode based on FCT operating, pocess of the data
///                      which are received through the request ports and freeze the SPM data for simulation framework.
///                      After all the computations were done call the functions to set the corresponding output on the
///                      provide ports.
/// @startuml "Call sequence for FCT_Sen_SPM_Exec"
///
/// fct_sen_main -> spm_main : **FCTSen_Exec()** calls\n**FCTSen_SPM_Exec**(p_RequirePorts, p_ProvidePorts, t_FCTSenFrameFCTOpMode, p_ServiceFuncts)
/// activate spm_main
///   group #LightBlue IF FCT_CFG_RUNTIME_MEAS == SWITCH_ON
///     spm_main -> spm_main : FCTSEN_SPMRuntimeMeasInit()
///   end
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, FCTSEN_RTA_SPM, u_OptData)
///   alt #Green FCT_CFG_USE_ALGOCOMPSTATE == SWITCH_ON
///     spm_main -> spm_main : FCT_v_SetSenSPMFrameData(p_RequirePorts, &AlgoErrorBuffer)
///   else FCT_CFG_USE_ALGOCOMPSTATE == SWITCH_OFF
///     spm_main -> spm_main : FCT_v_SetSenSPMFrameData(p_RequirePorts)
///   end
///   spm_main -> spm_algocontrol : FCTSen_v_SPMProcessStates(t_FCTSenFrameFCTOpMode)
///   spm_algocontrol --> spm_main : 
///   spm_main -> spm_main : FCTSen_v_SPMSetupPorts(p_RequirePorts, p_ProvidePorts)
///   spm_main -> spm_main : FCTSen_v_SPMPreProcessing(p_RequirePorts, p_ProvidePorts, p_ServiceFuncts, &AlgoErrorBuffer)
///   spm_main -> spm : SPMProcess( PerfDegr_t, AlgoErrorState_t, AlgoErrorState_t, boolean, SYSDampState_t, e_AlignState_t, float32, fTime_t, Fct_blockage_algo_parameters_t)
///   spm --> spm_main
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, FCTSEN_RTA_SPM, u_OptData)
///   group #LightBlue FCT_MEASUREMENT == SWITCH_ON
///     spm_main -> spm_meas : FCTSen_v_SPMProcessMeasFreeze(p_ProvidePorts)
///     spm_meas --> spm_main : 
///   end
///   alt #Green FCT_MEASUREMENT == SWITCH_ON AND FCT_CFG_USE_SERVICE_POINTER_FUNCTS == SWITCH_ON
///     spm_main -> spm_meas : FCTSen_v_SPMFrameFreeze()
///     spm_meas --> spm_main : 
///   else
///     spm_main -> spm_meas : FCTSen_v_SPMFrameFreeze()
///     spm_meas --> spm_main : 
///   end
///   spm_main --> fct_sen_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-528-0006e2e0
///
extern void FCTSen_SPM_Exec(const reqFCTSenSPMPrtList_t * p_RequirePorts, SPMProPort_t * const p_ProvidePorts,  const FCT_OP_MODE_t t_FCTSenFrameFCTOpMode);
#endif


/// @brief Initialization of ACC FCT_SEN variables/states
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///        t_FCTSenSPMFrame.bFirstCycleDone : Flag that shows that first cycle was done for SPM component [TRUE, FALSE]\n
///        b_FCTSenSPMIsInitialized : Fct sen SPM and it's subcomponents initialization status [TRUE, FALSE]\n
///
/// @InOutCorrelation   Initialization of ACC FCT_SEN frame (resets global FCTSenFrame.bFirstCycleDone flag).
///                     Init external object IDs.
/// @startuml "Call sequence for FCTSen_v_SPMAlgoInit"
///
/// fct_sen_main -> spm_main : FCTSen_Exec() calls FCTSen_v_SPMAlgoInit()
/// activate spm_main
///   spm_main --> fct_sen_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (black box test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-531-0006e2e0
///
extern void FCTSen_v_SPMAlgoInit (void);
#endif//FCT_CFG_SIGNAL_PERF_MONITORING
#else
  /*****************************************************************************
    MACROS
  *****************************************************************************/
  
  /*****************************************************************************
    SYMBOLIC CONSTANTS (COMPONENT EXTERN)
  *****************************************************************************/
  /* TPW version number */
  #define SPM_SW_MAIN_VER_NO      3
  #define SPM_SW_SUB_VER_NO       55
  #define SPM_SW_BUG_FIX_LEV      0
  #define SPM_SW_VERSION_NUMBER ((uint32)((uint32)SPM_SW_MAIN_VER_NO << 16) + (uint32)((uint32)SPM_SW_SUB_VER_NO << 8) + (uint32)((uint32)SPM_SW_BUG_FIX_LEV))
  
  /*Object Loss Parameter*/
  #define SPM_MAX_NUM_USED_REL_OBJ_BSD   3U
  #define SPM_INDEX_USED_REL_OBJ_LCA     SPM_MAX_NUM_USED_REL_OBJ_BSD
  #define SPM_MAX_NUM_USED_REL_OBJ_LCA   1U
  #if ((SPM_MAX_NUM_USED_REL_OBJ_LCA) > 0 || (SPM_INDEX_USED_REL_OBJ_LCA > 0))
  #define SPM_MAX_NUM_USED_REL_OBJ       (SPM_MAX_NUM_USED_REL_OBJ_BSD + SPM_MAX_NUM_USED_REL_OBJ_LCA)
  #else
  #define SPM_MAX_NUM_USED_REL_OBJ 1U
  #endif

  #define EM_PERF_INTERFERENCE_INT_VER_THLD         (8U)  // Minimum interface version needed for interference implementation
  #define SENSOR_FAR_RANGE_LIMIT	100.8F
  #define UNKNOWN_RANGE  0.0F
  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/
  /*! states for configuration of azimuth misalignment state maschine */
  typedef enum {
    SAFETY,
    AVAILABILITY
  }SPMAzimuthConfigState_t;
  
  /*****************************************************************************
    TYPEDEFS (KOMPONENTENEXTERN)
  *****************************************************************************/
  
  /*! operating modes of sub-component */
  typedef enum {
    SPM_INIT                /*!< initialize all */
    ,SPM_OK                  /*!< normal processing */
    ,SPM_EOL                 /*!< end of line mode */
    ,SPM_PAUSE               /*!< pause processing */
  } StateSPM_t;
  
  /// This structure contains Relevant Object data that are used in ObjectLoss Observer
  typedef struct
  {
    float32        fRelObjRCSFiltered;
    float32        fLastRelObjDistX;
    float32        fLastRelObjDistY;
    float32        fLastRelObjTTC;
    float32        fLastRelObjTTCThreshold;
    float32        fDeadTimeCounter;
    float32        fExRelObjPosFollowTimer;           /* Maximum time period for position prediction of deleted relevant objects */ 
    float32        fLastRelObjVrelX;                  /* x-velocity of the relevant object in the last cycle */
    float32        fRelObjObsTimer;
    float32        fDist2Course;
    float32        fArelX;
    ObjNumber_t    iCurrRelObjID;
    ObjNumber_t    iLastRelObjID;
    uint8          uLastRelObjAssociatedLane;
    boolean        bObjectWasPresent;
    boolean        bObjectNowPresent;                 /* A moving object is now present at the position of the deleted object */
    boolean        bRelevanceLossDetected;
    boolean        bRelObjWasMov;
    boolean        bMergedState;
  } ObserverData_t;
  
  /// This structure contains parameters and flags that are used in ObjectLoss Observer
  typedef struct
  {
    float32   fBSDResetTimer;
    float32   fLCAResetTimer;
    float32   fBSDDampRecoveryCounter;      /* [s] */
    float32   fLCADampRecoveryCounter;      /* [s] */
    uint8     uBSDNoOfRelObjLosses;
    uint8     uLCANoOfRelObjLosses;
    uint8     uBSDOverallNoRelObj;
    uint8     uLCAOverallNoRelObj;
    boolean   bBSDPerfDegrFlag;     /* FALSE/TRUE */
    boolean   bLCAPerfDegrFlag;     /* FALSE/TRUE */
  } CommonData_t;
  
  /// This structure contains general info for ObjectLoss Observer (CommonData Structure, max number used for revelant object)
  typedef struct
  {
    ObserverData_t Observer[SPM_MAX_NUM_USED_REL_OBJ];
    CommonData_t CommonData;
  } SPMObjectLossGeneralInfo_t;
  
  
  
  /// This structure contains Selfest data (RangeMoving, RangeStationary and Confidance)
  typedef struct
  {
    float32  SPMSelftestRangeMov;             /* [m] */
    float32  SPMSelftestRangeMovConf;         /* (0...1) */
    float32  SPMSelftestRangeSta;             /* [m] */
    float32  SPMSelftestRangeStaMax;          /* [m] */
    float32  SPMSelftestRangeStaConf;         /* (0...1) */
  } SPMSelftest_t;
  
  /// This structure contains Blockage data (Range Performance Degradation, Timeout data, Interference data, Selftest data, ObjectLoss data, Wiper data, ALN data)
  typedef struct
  {
    /*****************/
    /* Blockage data */
    /*****************/
    /* Range result members */
    float32  SPMBlockageRange;                /* [m] */
    float32  SPMBlockageRangeConf;            /* (0...1) */
    /* Decision Time counter for Performance Degradation or Recovery */
    float32  SPMBSDRangeDeterminationCounter;
    float32  SPMLCARangeDeterminationCounter; 
    float32  SPMFCTARangeDeterminationCounter;
    /* Range Performance Degradation flag */
    boolean  bLCARangeFullDamp;     /* FALSE/TRUE */ 
    boolean  bBSDRangeFullDamp;     /* FALSE/TRUE */ 
    boolean  bFCTARangeFullDamp;     /* FALSE/TRUE */
    boolean  bLCARangeINCDamp;     /* FALSE/TRUE */ 
    boolean  bBSDRangeINCDamp;     /* FALSE/TRUE */
    boolean  bFCTARangeINCDamp;     /* FALSE/TRUE */ 
  
    /* Timeout result members */
    boolean  bBSDTimeoutFullDamp;          /* FALSE/TRUE */
    boolean  bLCATimeoutFullDamp;          /* FALSE/TRUE */
    boolean  bFCTATimeoutFullDamp;         /* FALSE/TRUE */
    float32  SPMFullDampRecoveryCounter;      /* [s] */
    float32  SPMBlockageTimeoutTimeCounter;   /* [s] */
    float32  SPMBlockageTimeoutWayCounter;    /* [m] */

	#if((EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD) && (FCT_SEN_ERROR_OUT_INTFVER >= 20U))
	/* Interference data */
	float32 SPMInterferenceRange;
	uint32 SPMInterference;
	uint32 SPMInterferenceHoldCnt;
	boolean SPMInterferenceState;
	float32 InterferenceRangeThld;
	float32 SensorFarRangeLimit;
	#endif
    /*****************/
    /* Selftest data */
    /*****************/
    eGDBPDStates_t SPMSelftestState;                /* States: STARTUP - ON - OFF - ROADBEAM */  
    float32        SPMSelftestTimeCounter;          /* [s] */
    float32        SPMSelftestTimeCounterThld;      /* [s] */
    SPMSelftest_t  SPMSelftestInput;                /* Range Move and Range Sta */
  
    /*****************/
    /* Object Loss data */
    /*****************/
    uint8   uObjLossBSDNoOfRelObjLosses;    /*Numbe of BSD rel Object Losses*/
    uint8   uObjLossLCANoOfRelObjLosses;    /*Numbe of LCA rel Object Losses*/
    boolean bObjectLossBSDPerfDegrFlag;     /* FALSE/TRUE */
    boolean bObjectLossLCAPerfDegrFlag;     /* FALSE/TRUE */
    /*****************/
    /* Wiper data */
    /*****************/
    boolean bWiperBlockageHoldOff;
    boolean bWiperBlockageHoldOn;
    /**********************************/
    /* Partial blockage from ALN data */
    /**********************************/
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT== SWITCH_ON)
    boolean bSPMFullBlockageGenByALN;
  #endif
  
  } SPMData_t;
  
  /// This structure contains Wiper data
  typedef struct
  {
    boolean bBlockageWiperPermit;
    boolean bLastBlockageWiperPermit;
    boolean bExtendblockage;
    boolean bPartialBlockage;
    float32 fBlockageWiperPermitTimer;
    float32 fExtendBlockageTimer;
    float32 fPartialBlockageTimer;
  } SPMWiperData_t;
  /*****************************************************************************
    (SYMBOLIC) CONSTANTS
  *****************************************************************************/
  
  /*****************************************************************************
    VARIABLES
  *****************************************************************************/
  /*! sub-module state */
  extern StateSPM_t     StateSPM;
  
  /*! data of object loss statistic                       vaddr: 0x20005500 */
  extern SPMObjectLossGeneralInfo_t    SPMObjectLossGeneralInfo;
  
  /*! data of SPM */
  extern SPMData_t SPMData;
  extern SPMWiperData_t  SPMWiperData;
  /*****************************************************************************
    FUNCTION
  *****************************************************************************/
  
  /// System Performance Monitoring main function <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              fOwnSpeed               Ego Speed
  /// @param[in]              fCurrCycleTime          Cycletime
  /// @param[in]              pPerfDegrData           Blockage data collected from EM
  /// @param[in]              ps_blockage_parameters  BSW algo blockage parameters
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT== SWITCH_ON)
  /// @param[in]              ps_PartialBlockageInfo  Partial blockage status from ALN
  #endif
  ///
  /// @param[out]             puiBlockageEvent     Blockage event
  /// @param[out]             puiSelftestEvent     Selftest event     
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       System Performance Monitoring main function, handles Selftest, Blockage, Interference, ObjectLoss, Signal Quality Check and Azimuth Misalignment Monitoring
  ///
  /// @startuml       "Call sequence for SPMProcess"
  ///
  /// group  #LightBlue  IF FCT_CFG_SIGNAL_PERF_MONITORING
  /// fct_sen_main ->  spm: **FCTSen_Exec()** call \n **SPMProcess()**
  /// end
  ///     activate spm
  ///        spm -> spm: **SPMSetBlockageParameters()**
  ///         group #LightBlue case SPM_OK
  ///         spm -> spm: **SPMSelftest(pPerfDegrData, puiBlockageEvent, puiSelftestEvent)**
  ///           group #LightSeaGreen IF SPM_CFG_USE_OBJECTLOSS
  ///              spm -> spm: **SPMProcessObjectLoss(fOwnSpeed)**
  ///           end
  ///           group #LightSeaGreen IF SPM_CFG_USE_WIPER_ADAPT
  ///             spm -> spm: ** SPMWiperAdaptBlockageState()**
  ///           end
  ///         spm -> spm: **SPMProcessBlockageState()**
  ///         end
  ///         group #LightBlue case SPM_EOL
  ///            spm -> spm: **SPMSelftest(pPerfDegrData, puiBlockageEvent, puiSelftestEvent)**
  ///         end
  ///         group #LightBlue case SPM_INIT
  ///            spm -> spm: **SPMInit()**
  ///         end
  ///         group #LightBlue default
  ///            spm -> spm: **SPMInit()**
  ///         end
  ///        spm -> spm: **FCT_FREEZE_DATA(&SPMDataMeasInfo, &SPMData, &FCTSenMeasCallback)**
  ///          spm -> spm: **FCT_FREEZE_DATA(&SPMBlockageParametersMeasInfo, &SPMBlockageParameters, &FCTSenMeasCallback)**
  ///        spm --> fct_sen_main: 
  ///     deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test order of calls (dynamic module test) \n
  ///                         Test of code coverage (dynamic module test)
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-563-0006e2e0
  ///          
  void SPMProcess (const PerfDegr_t                       *pPerfDegrData         ,
                         FCTSenErrorOut_t                 *puiBlockageEvent      ,
                         AlgoErrorState_t                 *puiSelftestEvent      ,
                         fSpeed_t                          fOwnSpeed             ,
                         fTime_t                           fCurrCycleTime        ,
						 const boolean bRollerTestBench							 ,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT== SWITCH_ON)        
                   const PartialBlockage_t                *ps_PartialBlockageInfo,   
  #endif
                   const Fct_blockage_algo_parameters_t   *ps_blockage_parameters );
  
  /*! spm_main.c */
  #if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  void SPMFillSenErrors(FCTSenErrorOut_t * pDest);
  #endif
#endif

#ifdef __cplusplus
};
#endif


/* End of conditional inclusion */
#endif  /*!< _FRAME_SPM_EXT_INCLUDED */


