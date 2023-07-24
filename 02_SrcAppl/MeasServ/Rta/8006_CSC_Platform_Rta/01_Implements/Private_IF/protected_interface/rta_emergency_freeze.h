// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares the functions related to emergency buffer freeze which needs to be called by ST in case of resets.

#ifndef RTA_EMERGENCY_FREEZE_H
#define RTA_EMERGENCY_FREEZE_H

#include <rta_common.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// \ brief The function RTA_v_EmergencyBufferFreeze does a bufferFreeze of all specified cores.
///
/// The function RTA_v_EmergencyBufferFreeze shall be called on the IUC in case of an exception before doing the reset.
/// It freezes the rtaBuffers of all cores of the specified buildUnit(s) to MTS. Therefore it is important that it is called before
/// the related cores go really in reset.
///
/// \pre
///   This function must be called ONLY in case something happened on any core which leads to an reset of the related buildUnit the core belongs to.
///   It is required that all other cores than the core doing the freeze have written back their rtaBuffers to real memory (flush) to ensure
///   that the content of the rtaBuffers in the memory is up to date and consistent. On the core which is doing the emergencyFreeze the function
///   RTA_v_CacheWriteBackRtaBuffers() has to be called before calling RTA_v_EmergencyBufferFreeze().
/// \post
///   The measFreeze of all rtaBuffers of all cores of the specified buildUnit(s) have been done either in the emergencyWay (-> emergencyFreezeFunction
///   of the MTSI is used) in case the tasking is disabled or in the normal way in case the tasking is not disabled.
///   Note: In case the tasking is NOT disabled the freezes are not completed once the function returns -> asynchronous freezes!
/// \param
///   BUILD_UNITS_TO_FREEZE: With this argument the caller can determine from which buildUnits the rtaBuffers shall be frozen.
///                          As it is bitCoded it is possible to freeze the buffers of one or more buildUnits.
///                          See \ref RTA_t_BuildUnits for details
/// \param
///   b_TASKING_DISABLED: With this argument the information has to be provided whether the tasking is enabled or disabled at the time this function is called.
///     b_TRUE:  Tasking is disabled
///     b_FALSE: Tasking is enabled
///
/// \return
///   void
///
/// \globals
///   rta_emergencyFreezeParamSetHandler is used to obtain the following information \n
///   - where to find the rtaBuffers \n
///   - virtAddress, funcID and funcChID \n
///   See \ref RTA_t_EmergencyFreezeParamSetHandler for details
///
/// \InOutCorrelation
///   This function freezes all rtaBuffers of all cores of given buildUnits. by using corresponding virtAddresses and funcIDs.
///   It freezes the rtaBuffers of every core in the correct order - the older buffer has to be frozen first.
///
/// \callsequence
///   In case of interrupts: Replace task with interrupt in legend of plantuml sequence
///   and describe the interrupt condition
///   \image html RTA_v_EmergencyFreezeAllRtaBuffers.png Sequence Diagram
///   \startuml "RTA_v_EmergencyFreezeAllRtaBuffers.png"
///   legend left
///     This function must be called only in case of a crash of any dpuCore.
///     It must be called only once on the IUC while preparing the reset.
///     After the function call there has to be some waitTime before the
///     reset is actually done to give the MTSI time for the freeze and to
///     complete the MTA-frame.
///   endlegend
///     ST -> RTA_EmergencyFreeze: RTA_v_EmergencyBufferFreeze()
///     activate RTA_EmergencyFreeze
///     loop rta_emergencyFreezeParamSetHandler.u_numberOfCores times
///       RTA_EmergencyFreeze -> RTA_EmergencyFreeze: v_DetermineBufferSendOrder(p_paramSet, a_bufferSendList)
///       activate RTA_EmergencyFreeze
///       RTA_EmergencyFreeze -->> RTA_EmergencyFreeze: return
///       deactivate RTA_EmergencyFreeze
///       loop RTA_NO_OF_BUFFERS times
///         RTA_EmergencyFreeze -> Meas: MEASFreezeDataMTS(&measInfo, &buffer, v_dummyCallbackFct)
///         activate Meas
///         Meas -->> RTA_EmergencyFreeze: return
///         deactivate Meas
///       end
///     end
///     RTA_EmergencyFreeze -->> ST: return
///     deactivate RTA_EmergencyFreeze
///   \enduml
///
///   \traceability
///      <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-845-0005ebe0">
///               doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-845-0005ebe0</a>
void RTA_v_EmergencyBufferFreeze(const RTA_t_BuildUnits BUILD_UNITS_TO_FREEZE, const boolean b_TASKING_DISABLED);


/// \brief The function RTA_v_CacheWriteBackRtaBuffers writes back the rtaBuffers of the core on which this function is called into physical memory.
///
/// \pre
///   Caches have to be up and running
/// \post
///   The rtaBuffers of the core on which this function is called are written back to physical memory.
/// \param
///   void
///
/// \return
///   void
///
/// \globals
///   The dataSet of the core on which the function is called - returned by RTA_p_GetDataSet()
///   See \ref RTA_t_EmergencyFreezeParamSetHandler for details
///
/// \image html RTA_v_CacheWriteBackRtaBuffers.png Sequence Diagram
/// \startuml "RTA_v_CacheWriteBackRtaBuffers.png"
/// [--> RTA_EmergencyFreeze: RTA_v_CacheWriteBackRtaBuffers()
/// activate RTA_EmergencyFreeze
/// RTA_EmergencyFreeze -> RTA_Basics: RTA_p_GetDataSet()
/// activate RTA_Basics
/// RTA_Basics --> RTA_EmergencyFreeze: // return p_dataSet //
/// deactivate RTA_Basics
/// alt if pointer is NOT NULL
/// note right of RTA_EmergencyFreeze: Calculate length of both buffers together\nCall the writeBackFunction providing the address of the first buffer in the array
/// RTA_EmergencyFreeze -> RTA_Req_If: RTA_ReqIf_v_WritebackCache((void*)p_dataSet->p_params->a_ptrRtaBuffer[0], u_length)
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_EmergencyFreeze: // Done //
/// deactivate RTA_Req_If
/// end
/// [<-- RTA_EmergencyFreeze: // Done //
/// deactivate RTA_EmergencyFreeze
/// \enduml
///
/// \InOutCorrelation
///   This function freezes all rtaBuffers of all cores of given buildUnits. by using corresponding virtAddresses and funcIDs.
///   It freezes the rtaBuffers of every core in the correct order - the older buffer has to be frozen first.
///
///   \traceability
///      TODO
void RTA_v_CacheWriteBackRtaBuffers(void);


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_EMERGENCY_FREEZE_H
