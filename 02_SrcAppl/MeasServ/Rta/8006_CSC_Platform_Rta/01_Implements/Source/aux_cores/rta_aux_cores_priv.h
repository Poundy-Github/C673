// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares all public functions of the feature 'auxiliary cores', which are called inside the RTA.

#ifndef RTA_AUX_CORES_PRIV_H
#define RTA_AUX_CORES_PRIV_H

#include <rta_defs.h>
#include <rta.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// \brief Initialization of the RTA component, mainly by calling of function v_Init_DataSetAuxCore.
///
/// \pre
///   The systemTime has to be available
/// \post
///   After successful run of this function the RTA AuxiliaryCores is ready to use.
/// \param
///   void
/// \return
///   void
///
/// \globals
///   [in, out] RTA_t_Ctrl::b_initialized \n
///   This flag indicates whether the rta has been initialized already or not.
///   It is used to prevent multiple initialization. \n
///   \n
///   [out] RTA_t_AuxCoresDataSet p_DataSet: core specific data set
///
/// \InOutCorrelation
///   If b_initialized is true, status warning RTA_ALREADY_INIT is set, otherwise initialization
///   is done for each core and for each task on core 0. At end of initialization
///   p_dataSet->p_ctrl->b_initialized is set true.
///   During initialization the core/task specific data sets are set zero and local and system time
///   are initialized.
///
/// \callsequence
///   \image html RTA_v_AuxCoresInit_sequence.png Sequence Diagram
///   \startuml RTA_v_AuxCoresInit_sequence.png
///   title The initialization of the RTA component
///   legend left
///     Task:           Any initialization task (depends on the platform on which the RTA is used)
///     Task priority:  Depends on the platform on which the RTA is used
///     Cycle time:     No cyclic call, just once at initialization time
///     **Note:**
///     Init_PlatformX, SysTime and SysMem are platform specific files
///     which call also platform specific functions.
///     The abstraction is completely done in the interface abstraction layer (RTA_Ial).
///   end legend
///   note left
///     Start of each periodic cycle,
///     every time, the same core switchs buffers
///   end note
///   Init_PlatformX -> RTA_AuxCores: InitFctX() calls RTA_v_AuxCoresInit()
///   note left
///   Call condition:
///    - SystemTime has to be available
///    - The RTA must not be initialized
///   endnote
///   loop x RTA_NO_OF_AUX_CORES
///     activate RTA_AuxCores
///     rnote over RTA_AuxCores: Get p_dataSetSpecificCore based on loop counter
///     opt p_dataSetSpecificCore->p_ctrl-> != NULL
///          rnote over RTA_AuxCores: set status warning RTA_ALREADY_INIT
///     else
///       RTA_AuxCores -> RTA_AuxCores: calls v_Init_DataSetAuxCore() for specific core related to counter
///       == function v_Init_DataSetAuxCore ==
///       note over RTA_AuxCores #FFAAAA
///         Setting pointers p_ctrl, p_params, p_callbackCnt, a_ptrRtaBuffer, p_measCallbackFct,
///       end note
///       RTA_AuxCores -> RTA_Ial: RTA_MEM_SET
///       deactivate RTA_AuxCores
///       activate RTA_Ial
///       RTA_Ial -> SysMem: MEM_SET
///       deactivate RTA_Ial
///       activate SysMem
///       SysMem -->> RTA_AuxCores: return
///       deactivate SysMem
///       activate RTA_AuxCores
///       RTA_AuxCores -> RTA_Ial: RTA_GET_LOCALTIME_COUNTER_TICKS
///       deactivate RTA_AuxCores
///       activate RTA_Ial
///       RTA_Ial -> SysTime: GET_LOCALTIME_COUNTER_TICKS
///       deactivate RTA_Ial
///       activate SysTime
///       SysTime -->> RTA_AuxCores: p_dataSet->p_ctrl->u_localTime
///       deactivate SysTime
///       activate RTA_AuxCores
///       loop x RTA_NO_OF_BUFFERS
///         RTA_AuxCores -> RTA_Ial: RTA_GET_SYSTEM_TIME_US
///         deactivate RTA_AuxCores
///         activate RTA_Ial
///         RTA_Ial -> SysTime: GET_SYSTEM_TIME_US
///         deactivate RTA_Ial
///         activate SysTime
///         SysTime -->> RTA_AuxCores: p_buffer->u_RefTs_us
///         deactivate SysTime
///       end
///       activate RTA_AuxCores
///       rnote over RTA_AuxCores: set p_dataSet->p_ctrl->b_initialized = b_TRUE
///       == end of v_Init_DataSetAuxCore ==
///     end
///   end
///   RTA_AuxCores -->> Init_PlatformX:  return
///   deactivate RTA_AuxCores
///   \enduml
///
/// \traceability
///   TODO
void RTA_v_AuxCoresInit(void);


/// \brief Calls RTA_v_AuxCoresSwitchAllBuffers for every Auxiliary Core
///
/// \pre
///   The RTA component has to be initialized
/// \param
///   void
/// \return
///   void
/// \InOutCorrelation
///   Get the CoreID, then switch the RTA Buffers of the DataSet using v_AuxCoresSwitchBuffer interface.
/// \callsequence
/// \image html RTA_v_AuxCoresSwitchAllBuffers.png Sequence Diagram
/// \startuml "RTA_v_AuxCoresSwitchAllBuffers"
/// title RTA_v_AuxCoresSwitchAllBuffers Sequence Diagram
/// [--> RTA_Aux_Cores: RTA_v_AuxCoresSwitchAllBuffers(void)
/// activate RTA_Aux_Cores
/// RTA_Aux_Cores -> RTA_Req_If : RTA_ReqIf_u_GetCoreId()
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Aux_Cores : // CoreId //
/// deactivate RTA_Req_If
/// alt if the CoreID received is equal to the Core Owner, call function to switch the RTA Buffers of the DataSet.
/// loop u_NUMBER_OF_AUX_CORES > u_index
/// RTA_Aux_Cores -> RTA_Aux_Cores : v_AuxCoresSwitchBuffer(u_index)
/// activate RTA_Aux_Cores
/// deactivate RTA_Aux_Cores
/// end
/// end
/// [<-- RTA_Aux_Cores : // done //
/// deactivate RTA_Aux_Cores
/// \enduml
///
/// \traceability
///   TODO
void RTA_v_AuxCoresSwitchAllBuffers(void);


/// \brief Calls RTA_v_AuxCoresFreezeBuffer for every Auxiliary Core.
///
/// \pre
///   The RTA component has to be initialized
/// \param
///   void
/// \return
///   void
/// \InOutCorrelation
///   Get the CoreID, then freeze the RTA Buffer that is currently not used/marked for writing.
/// \callsequence
/// \image html RTA_v_AuxCoresFreezeAllBuffers.png Sequence Diagram
/// \startuml "RTA_v_AuxCoresFreezeAllBuffers"
/// title RTA_v_AuxCoresFreezeAllBuffers Sequence Diagram
/// [--> RTA_Aux_Cores: RTA_v_AuxCoresFreezeAllBuffers(void)
/// activate RTA_Aux_Cores
/// RTA_Aux_Cores -> RTA_Req_If : RTA_ReqIf_u_GetCoreId()
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Aux_Cores : // CoreId //
/// deactivate RTA_Req_If
/// alt if the CoreID received is equal to the Core Owner, call function to freeze the RTA Buffer.
/// loop u_NUMBER_OF_AUX_CORES > u_index
/// RTA_Aux_Cores -> RTA_Aux_Cores : v_AuxCoresFreezeBuffer(u_index)
/// activate RTA_Aux_Cores
/// deactivate RTA_Aux_Cores
/// end
/// end
/// [<-- RTA_Aux_Cores : // done //
/// deactivate RTA_Aux_Cores
/// \enduml
///
/// \traceability
///   TODO
void RTA_v_AuxCoresFreezeAllBuffers(void);


#ifdef __cplusplus
}
#endif

#endif //#ifndef RTA_AUX_CORES_PRIV_H
