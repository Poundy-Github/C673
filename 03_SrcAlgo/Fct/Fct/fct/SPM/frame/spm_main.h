// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.29 $

/// This file contains the headers of main functions of SPM component.
///
/// @file       spm_main.h
///
/// @page       SPM_SensorPerformanceMonitoring

/***********************************************************************
CHANGES:                   $Log: spm_main.h  $
CHANGES:                   Revision 1.29 2020/08/06 10:01:41CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update design based on new changes
CHANGES:                   Revision 1.28 2020/06/25 08:07:38CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.27 2020/06/02 16:21:32CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove weather factor function header.
CHANGES:                   Revision 1.26 2020/03/09 13:32:05CET Pallo, Istvan (palloi) 
CHANGES:                   Update blockage over ignition cycle config switch name
CHANGES:                   Revision 1.25 2020/03/05 08:26:25CET Pallo, Istvan (palloi) 
CHANGES:                   Update design with new config switches for CBO
CHANGES:                   Revision 1.24 2020/03/03 08:22:20CET Pallo, Istvan (palloi) 
CHANGES:                   Add function header for weather factor computation.
CHANGES:                   Revision 1.23 2020/02/24 09:29:52CET Pallo, Istvan (palloi) 
CHANGES:                   Add define for BSW parameters interface version to correct file
CHANGES:                   Revision 1.22 2020/02/20 13:16:51CET Pallo, Istvan (palloi) 
CHANGES:                   Add new parameter to SPMInit function
CHANGES:                   Revision 1.21 2019/05/28 07:32:17CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.20 2018/11/19 13:25:44CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Design update
CHANGES:                   Revision 1.19 2018/09/24 15:13:01CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.18 2018/04/24 08:16:58CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove eAlignState from SPMProcess header
CHANGES:                   Revision 1.17 2018/04/13 10:01:44CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove veh dyn interface version check from function header
CHANGES:                   Revision 1.16 2018/04/12 14:39:39CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove variable from function header and use data structure instead
CHANGES:                   Revision 1.15 2018/04/03 10:32:34CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove duplicate header and wrong parameters
CHANGES:                   Revision 1.14 2018/03/09 08:59:41CET Pallo, Istvan (palloi) 
CHANGES:                   Remove const from function header
CHANGES:                   Revision 1.13 2018/02/23 10:36:58CET Pallo, Istvan (palloi) 
CHANGES:                   Remove function headers which are no longer needed. Add new function headers.
CHANGES:                   Revision 1.12 2018/01/17 07:38:21CET Pallo, Istvan (palloi) 
CHANGES:                   Design updates
CHANGES:                   Revision 1.11 2018/01/16 08:57:09CET Pallo, Istvan (palloi) 
CHANGES:                   Update design
CHANGES:                   Revision 1.10 2017/12/05 18:48:07CET Pallo, Istvan (palloi) 
CHANGES:                   New global variable for SPMErrorOut.
CHANGES:                   Update functions headers with new SPM ports naming.
CHANGES:                   Revision 1.9 2017/11/23 14:04:25CET Pepenar, Alin (pepenara) 
CHANGES:                   Update detailed design: added traceability
CHANGES:                   Revision 1.8 2017/11/16 14:52:58CET Pallo, Istvan (palloi) 
CHANGES:                   Function heade for set provide ports signal status.
CHANGES:                   Revision 1.7 2017/11/14 13:59:42CET Pallo, Istvan (palloi) 
CHANGES:                   Update design and add test method for each function
CHANGES:                   Revision 1.6 2017/10/27 08:12:58CEST Pallo, Istvan (palloi) 
CHANGES:                   New function header for add service header
CHANGES:                   Revision 1.5 2017/08/18 10:20:15CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix for LA dependency - replace with spm config switch
CHANGES:                   Revision 1.4 2017/08/11 08:30:13CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functions uml diagrams. Remove static and external from functions
CHANGES:                   Revision 1.3 2017/07/28 07:06:26CEST Pallo, Istvan (palloi) 
CHANGES:                   New function declarations and headers.
CHANGES:                   Revision 1.2 2017/06/21 09:42:40CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new function headers.
CHANGES:                   Revision 1.1 2017/03/17 13:16:58CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

*****************************************************************************/

#ifndef SPM_MAIN_H_INCLUDED
#define SPM_MAIN_H_INCLUDED

#include "spm_cfg.h"
#include "spm_int.h"
#include "spm_ext.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#include "fct_config.h"
#endif

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  DEFINES
*****************************************************************************/
#define BSW_PARAMS_BLK_STATE_INT_VER              (44U)

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
//#if (FCT_CFG_ERROR_OUTPUT_SEN)
//extern MEMSEC_REF SPMErrorOutProPort_t           * SPM_pErrorOut;
//#endif

//extern MEMSEC_REF SPMPortHandlerList_t SPMPortHandlerList;

/*****************************************************************************
  FUNCTION HEADERS
*****************************************************************************/

/// @brief Main function for processing the blockage algorithm
///
/// @pre                None
/// @post               None
///
/// @param[in] pPerfDegrData : pPerfDegrData : reference to blockage data collected from EM
/// @param[in] bRollerTestBench : lag that indicates if roller bench tests are made[TRUE, FALSE]
#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO)
/// @param[in] SRDDampState : RD blocakge state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]
#endif
#if( ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) && ((SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE) || (SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)))
/// @param[in] pAlignmentMonInput : Alignment algorithm input for SPM blockage
#endif
#if(SPM_USE_CUSTOM_OBJECT_SELECTION == SWITCH_ON)
/// @param[in] pEmCustObjList : Custom objects list for lane association.
#endif
/// @param[in] fOwnSpeed : Ego car speed [-100.F ... 100.F]
/// @param[in] fCurrCycleTime : Current cycle time [full range of fTime_t as defined in rte_type.h]
/// @param[in] ps_blockage_parameters : Blockage shuton/shutoff thresholds
///
/// @param[out] puiBlockageEvent : Reference to blockage event [AlgoErrorState_t as defined in Rte_Type.h]
/// @param[out] puiSelftestEvent : Reference to selftest event [AlgoErrorState_t as defined in Rte_Type.h]
///
/// @return             void
///
/// @globals
///        SPMData.SPMSelftestState : SPM selftest state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///
/// @InOutCorrelation   Call all for the selftest, object loss and blockage determination.
/// @startuml "Call sequence for SPMProcess"
///
/// spm_main -> spm : FCTSen_SPM_Exec() calls\nSPMProcess( PerfDegr_t, AlgoErrorState_t, AlgoErrorState_t, boolean, SYSDampState_t, e_AlignState_t, float32, fTime_t, Fct_blockage_algo_parameters_t)
/// activate spm
///   spm -> spm_blockage : SPMSetBlockageParameters(SPMBlockageParameters_t, Fct_blockage_algo_parameters_t, PerfDegr_t)
///   spm_blocckage --> spm : 
///   spm -> spm :  SPMBlockagePreventIfHighTempAndNoRain(boolean, boolean, boolean)
///   spm -> spm_selftest : SPMSelftest(PerfDegr_t, float32, boolean, AlgoErrorState_t, AlgoErrorState_t)
///   spm_selftest --> spm : 
///   spm -> spm_objectloss : SPMProcessObjectLoss(fSpeed_t, float32, PerfDegr_t)
///   spm_objectloss --> spm : 
///   spm -> spm_objectloss : SPMCancelObjLossObservation()
///   spm_objectloss --> spm :
///   group #LightBlue SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON
///     spm -> spm_blockage : SPMALNPartialBlockageState(e_AlignState_t, fSpeed_t)
///     spm_blockage --> spm : 
///   end
///   spm -> spm_blockage : SPMDetermineBlockProb(PerfDegr_t)
///   spm_blockage --> spm : 
///   alt #Green SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON
///     spm -> spm_blocakge : SPMDetermineBlockageState(PerfDegr_t)
///     spm_blockage --> spm : 
///   else SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_OFF
///     spm -> spm_blocakge : SPMDetermineBlockageState()
///     spm_blockage --> spm : 
///   end
///   group #LightBlue  SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
///     spm -> spm: SPM_v_SetBlockageType()
///     spm -> spm: SPM_v_ComputeBlockageCategory(pPerfDegrData)
///     group #LightBlue  SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
///       spm -> spm: SPM_v_ComputePartialBlockageLevel(pAlignmentMonInput)
///     end
///    end
///   spm -> spm_blocakge : SPMBlockageSetDEMEvents(AlgoErrorState_t)
///   spm_blockage --> spm : 
///   spm -> spm_interference : SPMInterferenceRange()
///   spm_interference --> spm : 
///   group #LightBlue FCT_CFG_CUSTOM_IO_INTERFACE == SWITCH_ON
///     spm -> spm_output : SPM_v_CustomProcess()
///     spm_output --> spm : 
///   end
///   spm -> spm_selftest : SPMSelftest(PerfDegr_t, float32, boolean, AlgoErrorState_t, AlgoErrorState_t)
///   spm_selftest --> spm : 
///   spm -> spm : SPMInit(AlgoErrorState_t, AlgoErrorState_t)
/// deactivate spm
/// spm --> spm_main : 
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-554-0006e2e0
///
void SPMProcess (const PerfDegr_t *pPerfDegrData,
                 AlgoErrorState_t *puiBlockageEvent,
                 AlgoErrorState_t *puiSelftestEvent,
                 const Boolean bRollerTestBench,
                #if (SPM_CFG_SHORT_RANGE_SENSOR_INFO)
                  const SYSDampState_t SRDDampState,
                #endif
                #if( ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) && ((SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE) || (SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)))
                  const ALN_S_Monitoring_t *pAlignmentMonInput,
                #endif
                #if(SPM_USE_CUSTOM_OBJECT_SELECTION == SWITCH_ON)
                  const EM_t_ObjectList_Custom *pEmCustObjList,
                #endif
                fSpeed_t fOwnSpeed,
                fTime_t fCurrCycleTime,
                const Fct_blockage_algo_parameters_t *ps_blockage_parameters);

/// @brief Initialize of SPM data
///
/// @pre                 None
/// @post                None
///
/// @param[in] ps_blockage_parameters : Blockage parameters as defined in Rte_Type.h
/// @param[out] puiBlockageEvent : Reference to blockage event [AlgoErrorState_t as defined in Rte_Type.h]
/// @param[out] puiSelftestEvent : Reference to selftest event [AlgoErrorState_t as defined in Rte_Type.h]
///
/// @return              void
///
/// @globals
///        SPMData.SPMBlockageState : SPM blocakge state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSRDSysDamp : SRD blocakge state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMALNPartialDamp : Alignment partial blocakge state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMALNPartialDampDelayTimer : Partial damping delay reactivation timer[0.0f ... 120.0f]\n
///        SPMData.SPMFullBlockageTimer : Full blockage timer [Full range of float32]\n
///        SPMData.SPMReactivationDelayTimer : Delay timer for system reactivation after SRR damping [full range of float32]\n
///        SPMData.SPMBlockageRange : Blockage range [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageRangeConf : Blocakge range confidence [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeProb : Blocakge range probability[0.0f ... 1.0f]\n
///        SPMData.SPMRangeHoldCounter : Timer used to delay blocakge report [full range of float32]\n
///        SPMData.SPMBlockagePreviousRange[SYS_NUM_OF_SCANS] : Blockage range for previous cycle on each 
///                                 scan [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageCurrentRange[SYS_NUM_OF_SCANS] : Blockage range for current cycle on each 
///                                 scan [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageRangeGradient[SYS_NUM_OF_SCANS] : Blockage range gradient which shows the 
///                                 variance of range for near or far scan whitin the last minute [full range of float32]\n
///        SPMData.SPMBlockageRangeConfidenceGradient[SYS_NUM_OF_SCANS] : Blockage range confidence 
///                                 gradient which shows the variation of range confidence for near or far scan whitin
///                                 the last minute [full range of flat32]\n
///        SPMData.SPMScanRangeConfidencePrevious[SYS_NUM_OF_SCANS] : Blocakge range confidence gradient 
///                                 for previous cycle [full range of float32]\n
///        SPMData.SPMBlockageTimeoutTimeCounter : Timeout time counter [full range of float32]\n
///        SPMData.SPMBlockageTimeoutWayCounter : Timeout way counter [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageTimeoutBlockProb : Timeout blockage probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageTimeoutBlockConf : Timeout blocakge confidence[0.0f ... 1.0f]\n
///        SPMData.SPMCurrentObjLossWeight : ObjectLoss observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentRangeWeight : Range observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentTimeoutWeight : Timeout observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageObjLossProb :  Object loss probability in SPMData [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageObjLossConf : Object loss confidence in SPMData [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageProbability : SPM blocakge probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageConfidence : SPM blocakge confidence [0.0f ... 1.0f]\n
///        SPMData.bSPMPreventBlckIfHighTempNoRain : Flag for preventing blockage if higg temperature and 
///                                 no rain detected [TRUE, FALSE]\n
///        SPMData.SPMSelftestState : Selftest current state [GDB_PD_OFF ... GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestStateLast : Selftest previous state [GDB_PD_OFF ... GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestTimeCounter : Current time counter for selftest [full range of float32]\n
///        SPMData.SPMSelftestTimeCounterThld : Selftest time counter threshold [120.0]s\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeMov : Range for moving objects [full range of float32]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeMovConf : Moving range confidence [0.0f ...1.0f]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeSta :  Range for stationary objects [full range of float32]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeStaMax : Maximum range for stationary objects [full range of float32]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeStaConf : Stationary range confidence [0.0f ... 1.0f]\n
///        SPMData.SPMInterferenceState : Flag to show it interference was or was not detected [TRUE, FALSE]\n
///        SPMData.SPMInterferenceRange : Interference range [full range of data type float32]\n
///        SPMData.SPMInterference : Interference on number of cycles before [full range of uint32]\n
///        SPMData.SPMInterferenceHoldCnt : Interference range hold count [full range of float32 > 0.0F]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibility : Road visibility [0 ... 100]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibilityQuality : Road visibility quality [0 ... 100]\n
///
/// @InOutCorrelation   Initialize SPMData structure with default values. Set blockage errors and selftest errors to 
///                     inactive. If BSW algo parameters interface version is greater or equal with v44 then blockage state
///                     and partial blockage state will be initialized with the values saved in NVM at the end of previous 
///                     ignition cycle.
/// @startuml "Call sequence for SPMInit"
///
/// spm -> spm : SPMProcess() calls SPMInit(AlgoErrorState_t, AlgoErrorState_t)
/// activate spm
///   spm -> spm_objectloss : SPMInitObjectloss()
///   spm_objectloss --> spm : 
///   spm -> spm : SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
/// deactivate spm
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)\n
///                     Test of memory corruption (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-553-0006e2e0
///
void SPMInit(AlgoErrorState_t *puiBlockageEvent,
             AlgoErrorState_t *puiSelftestEvent
#if((BSW_ALGOPARAMETERS_INTFVER >= BSW_PARAMS_BLK_STATE_INT_VER) && (FCT_CFG_PRESERVE_BLOCKAGE_STATE_OVER_IGNITION == SWITCH_ON))
             ,const Fct_blockage_algo_parameters_t   *ps_blockage_parameters
#endif
             );


/// @brief Fill FCT_SEN error output structure with SPM errors
///
/// @pre                 None
/// @post                None
///
/// @param[out] pDest : pointer to FCT_SEN error output structure of type FCTSenErrorOut_t [FCTSenErrorOut_t as in Rte_Type.h]
///
/// @return              void
///
/// @globals
///        SPMErrStates : SPM error states as an array of type AlgoErrorState_t and of size SPM_ERREV_NUM_ERRORS\n
///
/// @InOutCorrelation    Copy the SPM errors from SPMErrStates array to pDest pointer.
/// @startuml "Call sequence for SPMFillSenErrors"
///
/// spm_error -> spm : FCTSen_v_SPMFillErrorOut() calls SPMFillSenErrors(SPMErrorOutProPort_t)
/// activate spm
///   spm --> spm_error :
/// deactivate spm
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-552-0006e2e0
///
extern void SPMFillSenErrors(SPMErrorOutProPort_t * pDest);

/// @brief Fill FCT_SEN SPM error output structure
///
/// @pre                None
/// @post               None
///
/// @param[out] pt_ErrorOut : Reference to SPM error output structure that is filled in this function
///
/// @return             void
///
/// @globals            None
///
/// @InOutCorrelation    Fill the FCT_SEN SPM error out structure with data after SPM processing is done.
/// @startuml "Call sequence for FCTSen_v_SPMFillErrorOut"
///
/// spm_main -> spm_error : SPM_v_SetProPortsData(pProvidePorts, tBlockageState, tSelftestState) calls\n  FCTSen_v_SPMFillErrorOut(SPMErrorOutProPort_t)
/// spm_error --> spm_main:
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-545-0006e2e0
///
void FCTSen_v_SPMFillErrorOut(SPMErrorOutProPort_t * pt_ErrorOut);

/// @brief Freeze SPM component data
///
/// @pre                None
/// @post               None
///
/// @param[in] pProvidePorts : SPM component provide ports [SPMProPort_t as defined in spm_ext.h]
///
/// @return             void
///
/// @globals            None
///
/// @InOutCorrelation   Call all function necessary to freeze SPM component data for MTS simulation framework.
/// @startuml "Call sequence for FCTSen_v_SPMProcessMeasFreeze"
///
/// spm_main -> spm_meas : FCTSen_SPM_Exec() calls FCTSen_v_SPMProcessMeasFreeze(SPMProPort_t)
/// activate spm_meas
///   group #LightBlue FCT_MEASUREMENT == SWITCH_ON
///     spm_meas -> spm_meas : FCTSenSPMFreezeInput()
///   end
/// deactivate spm_meas
/// spm_meas --> spm_main : 
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-547-0006e2e0
///
extern void FCTSen_v_SPMProcessMeasFreeze(SPMProPort_t * const pProvidePorts);

#if (FCT_MEASUREMENT)
/// @brief Freeze SPM component data
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals            None
///
/// @InOutCorrelation   Freeze the sensor input for SPM component.
/// @startuml "Call sequence for FCTSenSPMFreezeInput"
///
/// spm_meas -> spm_meas : FCTSen_v_SPMProcessMeasFreeze() calls FCTSenSPMFreezeInput()
/// activate spm_meas
///   spm_meas --> spm_meas : 
/// deactivate spm_meas
/// @enduml
///
/// @testmethod         Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-549-0006e2e0
///
static void FCTSenSPMFreezeInput(void);
#endif

#ifdef RTA_INTERFACE_VERSION
  #if(RTA_INTERFACE_VERSION >= 4)
/// @brief Determine runtime of FCT component based on service functions provided by Base SW
///
/// @pre                None
/// @post               None
///
/// @param[in] RtaEvtType : Rta event type as in algo_service_types.h
/// @param[in] u_IdLocal : Index of runtime measurement array [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[
/// @param[in] u_OptData : Dummy variable which is unused. Necessary for compatibility with camera projects.
///                                [full range of datatype uint8]
///
/// @return             void
///
/// @globals
///          pFCTSenSPMServiceFuncts : SPM service pointer\n
///          pFCTSenSPMServiceFuncts->pfGetTimestampuS32 : Pointer to FCT timestamp\n
///
/// @InOutCorrelation   Determine runtime of FCT component based on service functions depending on wheter 
///                     pfRTAAlgoServiceAddEvent are available or not. If it is available this function is used 
///                     otherwise the function FCTSEN_SERVICE_ADD_EVENT_FCT is called which determines the time 
///                     difference between start and end events.
/// @startuml "Call sequence for FCTSEN_SPM_SERVICE_ADD_EVENT"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls FCTSEN_SPM_SERVICE_ADD_EVENT(RTA_t_Events, uint8, uint8)
/// activate spm_main
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT_FCT(AS_t_RtaEventType, sint32)
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-541-0006e2e0
///
    static void FCTSEN_SPM_SERVICE_ADD_EVENT( const RTA_t_Events RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData);
  #else
/// @brief Determine runtime of FCT component based on service functions provided by Base SW
///
/// @pre                None
/// @post               None
///
/// @param[in] RtaEvtType : Rta event type as in algo_service_types.h
/// @param[in] u_IdLocal : Index of runtime measurement array [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[
/// @param[in] u_OptData : Dummy variable which is unused. Necessary for compatibility with camera projects.
///                                [full range of datatype uint8]
///
/// @return             void
///
/// @globals
///          pFCTSenSPMServiceFuncts : SPM service pointer\n
///          pFCTSenSPMServiceFuncts->pfGetTimestampuS32 : Pointer to FCT timestamp\n
///
/// @InOutCorrelation   Determine runtime of FCT component based on service functions depending on wheter 
///                     pfRTAAlgoServiceAddEvent are available or not. If it is available this function is used 
///                     otherwise the function FCTSEN_SERVICE_ADD_EVENT_FCT is called which determines the time 
///                     difference between start and end events.
/// @startuml "Call sequence for FCTSEN_SPM_SERVICE_ADD_EVENT"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls FCTSEN_SPM_SERVICE_ADD_EVENT(AS_t_RtaEventType, uint8, uint8)
/// activate spm_main
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT_FCT(AS_t_RtaEventType, sint32)
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-542-0006e2e0
///
    static void FCTSEN_SPM_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData);
  #endif
#else
/// @brief Determine runtime of FCT component based on service functions provided by Base SW
///
/// @pre                None
/// @post               None
///
/// @param[in] RtaEvtType : Rta event type as in algo_service_types.h
/// @param[in] u_IdLocal : Index of runtime measurement array [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[
/// @param[in] u_OptData : Dummy variable which is unused. Necessary for compatibility with camera projects.
///                                [full range of datatype uint8]
///
/// @return             void
///
/// @globals
///          pFCTSenSPMServiceFuncts : SPM service pointer\n
///          pFCTSenSPMServiceFuncts->pfGetTimestampuS32 : Pointer to FCT timestamp\n
///
/// @InOutCorrelation   Determine runtime of FCT component based on service functions depending on wheter 
///                     pfRTAAlgoServiceAddEvent are available or not. If it is available this function is used 
///                     otherwise the function FCTSEN_SERVICE_ADD_EVENT_FCT is called which determines the time 
///                     difference between start and end events.
/// @startuml "Call sequence for FCTSEN_SPM_SERVICE_ADD_EVENT"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls FCTSEN_SPM_SERVICE_ADD_EVENT(AS_t_RtaEventType, uint8, uint8)
/// activate spm_main
///   spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT_FCT(AS_t_RtaEventType, sint32)
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-542-0006e2e0
///
  static void FCTSEN_SPM_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData);
#endif

#if (FCT_CFG_RUNTIME_MEAS == SWITCH_ON)
/// @brief Init global FCT runtime measurement array
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///          t_FCTSEN_SPMRuntimeInfo.uRuntime : Array of size FCTSEN_RTA_NOF_CHECKPOINTS containing the runtime 
//                        of FCT_SEN subcomponents (microseconds) [0u ... 1s]\n
///
/// @InOutCorrelation   Init global FCT runtime measurement array
/// @startuml "Call sequence for FCTSEN_SPMRuntimeMeasInit"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls FCTSEN_SPMRuntimeMeasInit()
/// activate spm_main
///   spm_main --> spm_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test for memory access violation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-544-0006e2e0
///
static void FCTSEN_SPMRuntimeMeasInit(void);
#endif

#if (FCT_CFG_RUNTIME_MEAS)
/// @brief Determine runtime of FCT (Radar) component based on service functions provided by Base SW.
///
/// @pre                Data available and before calling the function
/// @post               None
///
/// @param[in] t_RuntimeEvtType : Event type [full range of datatype FCT_t_ACCRuntimeCheckpointTypeEnum as in fct_sen.h]
/// @param[in] u_EventID : ID of the event which is set [full range of datatype uint8]
///
/// @return             void
///
/// @globals
///          t_FCT_SPMTimeArray : FCT ACC runtime info\n
///          t_FCT_ACCTimeArray[i] [full range of datatype uint32] with i in [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[\n
///
/// @InOutCorrelation   Determine runtime of FCT (Radar)  component based on service functions provided by Base SW.
///                     The time difference is determined between start and end events.
/// @startuml "Call sequence for FCTSEN_SPM_SERVICE_ADD_EVENT_FCT"
///
/// spm_main -> spm_main : FCTSEN_SPM_SERVICE_ADD_EVENT() calls FCTSEN_SPM_SERVICE_ADD_EVENT_FCT(AS_t_RtaEventType, sint32)
/// activate spm_main
///   spm_main --> spm_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-543-0006e2e0
///
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
 static void FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( const RTA_t_Events       t_RuntimeEvtType, const sint32 u_EventID);
#else
 static void FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID);
#endif
#else
 static void FCTSEN_SPM_SERVICE_ADD_EVENT_FCT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID);
#endif
#endif

/// @brief Set the Frame Data for Freeze
///
/// @pre                 None
/// @post                None
///
/// @param[in] pRequirePorts : the inputs passed to the FCT_SEN main function [reqFCTSenPrtList_t as defined in fct_sen_ext.h]
#if (FCT_CFG_USE_ALGOCOMPSTATE)
/// @param[in] pErrorBuffer : error buffer [full range of datatype GenAlgoQualifiers_t as in Rte_Type.h]
#endif
///
/// @return              void
///
/// @globals
///          FCTSenFrame :  FCT frame consisting of cycle time, cycle counter and opmode [as defined in fct_sen.h]\n
///          FCTSenFrame.eFCTOpMode : FCT requested operation mode [FCT_OP_MODE_t as defined in Rte_Type.h]\n
///          FCTSenFrame.uiCycleCounter : The FCT_SEN cycle counter [AlgoCycleCounter_t as defined in Rte_Type.h]\n
///          FCTSenFrame.Versions.uiCP : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.uiSI : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.uiCD : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.uiSPM : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.uiFIP : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.uProjectID : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.FctVersionNumVar : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///          FCTSenFrame.Versions.uiFCTSEN : FCT sub-component version [FCTACCSwVersion_t as defined in fct_acc_ver.h]\n
///
/// @InOutCorrelation    Set the Frame Data for Freeze, i.e. FCT operation mode and component version number
/// @startuml "Call sequence for FCT_v_SetSenSPMFrameData"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls FCT_v_SetSenSPMFrameData(reqFCTSenSPMPrtList_t, GenAlgoQualifiers_t)
/// activate spm_main
///   group #lightBlue FCT_CFG_USE_ALGOCOMPSTATE == SWITCH_ON
///     spm_main -> spm_algocontrol: FCTSenSetAlgoErrorBuffer(GenAlgoQualifiers_t, GenAlgoQualifiers_t)
///     spm_algocontrol --> spm_main : 
///   end
///   spm_main -> spm_algocontrol : FCTSen_v_SPMSignalErrorShutdown(boolean)
///   spm_algocontrol --> spm_main : 
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test of memory corruption (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-540-0006e2e0
///
static void FCT_v_SetSenSPMFrameData( const reqFCTSenSPMPrtList_t * pRequirePorts
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  , GenAlgoQualifiers_t *const pErrorBuffer
#endif
  );

//static void FCTSen_v_SPMAlgoInit (void);

/// @brief Set SPM rocessing states based on SPM running state.
///
/// @pre                 None
/// @post                None
///
/// @param[in] pRequirePorts : the inputs passed to the FCT_SEN main function [reqFCTSenPrtList_t as defined in fct_sen_ext.h]
/// @param[in] pProvidePorts : SPM component provide ports [SPMProPort_t as defined in spm_ext.h]
///
/// @return              void
///
/// @globals
///          t_FCTSenSPMFrame : FCT frame data pointer\n
///          t_FCTSenSPMFrame.eFCTState : FCT current operation mode\n
///          t_FCTSenSPMFrame.bFirstCycleDone : Boolean showing if first cycle was done \n
///
/// @InOutCorrelation    If SPM operating mode is set on running call the shut down function without error. Call all the 
///                      necessary functions to initialize the SPM state based on FCT SPM running state. If SPM state is 
///                      RUN then set flag for first cycle done on true. Otherwise call SPM algo init function.
/// @startuml "Call sequence for FCTSen_v_SPMPreProcessing"
///
/// spm_main -> spm_main : FCTSen_SPM_Exec() calls\nFCTSen_v_SPMPreProcessing(reqFCTSenSPMPrtList_t, SPMProPort_t, AS_t_ServiceFuncts, GenAlgoQualifiers_t)
/// activate spm_main
///   spm_main -> spm_algocontrol : FCTSen_v_SPMSignalErrorShutdown(boolean)
///   spm_algocontrol --> spm_main : 
///   spm_main -> spm_main : FCTSen_v_SPMAlgoInit()
/// deactivate spm_main
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-546-0006e2e0
///
static void FCTSen_v_SPMPreProcessing(const reqFCTSenSPMPrtList_t * pRequirePorts, SPMProPort_t * const pProvidePorts);
#endif

#endif
