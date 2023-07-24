// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief The public RTA interfaces for auxiliary core functionality


#ifndef RTA_AUX_CORES_H
#define RTA_AUX_CORES_H


#include <rta.h>


#ifdef __cplusplus
extern "C"
{
#endif

/// The type for the ID of the auxiliary core. It is used as an argument in the RTA_v_AddEventAuxiliaryCores() function
typedef uint8 RTA_t_auxCoreID;


/// \brief
///   adds a new rtaEvent to the rtaBuffer, called by user
/// \pre
///   The RTA component has to be initialized.
/// \post
///   The rtaEvent is created and will be visible on the MO (MTS).
/// \param
///   [in] u_auxCoreID: used to identify the Auxiliary Core which will hold new Event
///          As quantity of Auxiliary Cores is defined by macro RTA_NO_OF_AUX_CORES
///          stored in RTA_Cfg.h, permitted values are from 0 to RTA_NO_OF_AUX_CORES-1
///   [in] event provides the type of the rtaEvent, see RTA_t_Events
/// \param
///   [in] u_globalID: used to map the rtaEvent to a certain group. Range: 0x0 ... 0xFFF \n
///          As globalIDs only the RTA_GLOBALID_xxx provided in rta_globalids.h must be used!
///          This is very important as the xml-File needed by the rtaMOs are generated based on the
///          rta_globalids.h. \n
///          In case there is no adequate RTA_GLOBALID_xxx for your component or your your use case
///          please contact Matthias Kammerl.
/// \param
///   [in] u_localID: used in the MO to visualize an event within a specific "group"
///          determined by provided u_GLOBALID. All localIDs used for one u_GLOBALID must be unique and have
///          to be defined in an "localID-Enumeration". All the "localID-Enumeration" must be tagged with
///          "RTA_LOCAL_ID_FOR_XML_GENERATION" (in a c-style multiLine comment. \n
///          This is very important as only then the RtaXmlGenerator is able to generate the related localID.xml
///          based on the "localID-Enumeration". Please refer to the following manual for details: \n
///          https://github-am.geo.conti.de/ADAS/RtaGeneratorToolChain/blob/master/doc/GenerationOfRtaLocalIdXmlFiles.pptx\n
///          Range: 0x0 ... 0xFFF \n
/// \param
///   [in] u_optData: provides additional information eg. errorID, clusterID, Range: 0x0 ... 0xFF \n
/// \return
///   void
/// \InOutCorrelation
///   Get information from the desired AuxCore, if all checks are ok, then add the event into container.\nExpected Output is the data will be seen in RTA or an Overflow Flag will be shown in case the operation fails.\n
/// \callsequence
/// \image html RTA_v_AddEventAuxiliaryCores.png Sequence Diagram
/// \startuml "RTA_v_AddEventAuxiliaryCores"
/// title RTA_v_AddEventAuxiliaryCores Sequence Diagram
/// [--> RTA_Aux_Cores: RTA_v_AddEventAuxiliaryCores (const uint8 u_auxCoreID, const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optDataA)
/// activate RTA_Aux_Cores
/// alt if DataSet of the AuxCore is NOT null
/// alt if DataSet is initialized
/// RTA_Aux_Cores -> RTA_Req_If : RTA_v_GetSpinLock(p_dataSet->p_params->u_spinlockId)
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Aux_Cores : // (done) //
/// deactivate RTA_Req_If
/// note right of RTA_Aux_Cores : check if RTA is suspended or not
/// RTA_Aux_Cores -> RTA_Suspend : RTA_b_Suspended()
/// activate RTA_Suspend
/// RTA_Suspend --> RTA_Aux_Cores : // return status //
/// deactivate RTA_Suspend
/// alt if RTA is NOT suspended
/// note right of RTA_Aux_Cores : Get address of current rtaBuffer and get the current eventIndex.\nCheck if there is still place in eventContainer.\nGet next free index of the eventContainer.\nFill in the relevant data.\nIncrement the event index.\n
/// else ELSE
/// note right of RTA_Aux_Cores : Buffer is full, set OverFlow flag.
/// end
/// end
/// RTA_Aux_Cores -> RTA_Req_If : Unlock AuxCore
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Aux_Cores : // done //
/// deactivate RTA_Req_If
/// else ELSE
/// alt if DataSet is not NULL
/// note right of RTA_Aux_Cores : Set warning flag (NOT_INIT)
/// end
/// end
/// [<-- RTA_Aux_Cores : // done //
/// deactivate RTA_Aux_Cores
/// \enduml
/// \testmethod
///   \ref TEST01_RTA_v_AddEventAuxiliaryCores \n
///   \ref TEST02_RTA_v_AddEventAuxiliaryCores \n
///   \ref TEST03_RTA_v_AddEventAuxiliaryCores \n
///   \ref TEST04_RTA_v_AddEventAuxiliaryCores \n
///   \ref TEST05_RTA_v_AddEventAuxiliaryCores \n
///   \ref TEST06_RTA_v_AddEventAuxiliaryCores \n
/// \traceability
///   to be added
void RTA_v_AddEventAuxiliaryCores (const RTA_t_auxCoreID u_auxCoreID, const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData);

/// Adds a new event to virtualCore (always the last auxiliaryCore (index = RTA_NO_OF_AUX_CORES-1))
/// This function just calls RTA_v_AddEventAuxiliaryCores with hardcoded u_AUX_CORE_ID to RTA_NO_OF_AUX_CORES-1
/// It is implemented for special use case, for example when the start event is coming from the different core than the end event.
/// If for example DPU_0 core initiated start event, and DPU_1 core initiates stop event, the whole operation can be tracked like it is running on one "virtual" core.
/// \pre
///   The RTA component has to be initialized.
/// \post
///   The rtaEvent is created and will be visible on the MO (MTS).
/// \param
///   [in] event provides the type of the rtaEvent, see RTA_t_Events
/// \param
///   [in] u_globalID: used to map the rtaEvent to a certain group. Range: 0x0 ... 0xFFF \n
///          As globalIDs only the RTA_GLOBALID_xxx provided in rta_globalids.h must be used!
///          This is very important as the xml-File needed by the rtaMOs are generated based on the
///          rta_globalids.h. \n
///          In case there is no adequate RTA_GLOBALID_xxx for your component or your your use case
///          please contact Matthias Kammerl.
/// \param
///   [in] u_localID: used in the MO to visualize an event within a specific "group"
///          determined by provided u_GLOBALID. All localIDs used for one u_GLOBALID must be unique and have
///          to be defined in an "localID-Enumeration". All the "localID-Enumeration" must be tagged with
///          "RTA_LOCAL_ID_FOR_XML_GENERATION" (in a c-style multiLine comment. \n
///          This is very important as only then the RtaXmlGenerator is able to generate the related localID.xml
///          based on the "localID-Enumeration". Please refer to the following manual for details: \n
///          https://github-am.geo.conti.de/ADAS/RtaGeneratorToolChain/blob/master/doc/GenerationOfRtaLocalIdXmlFiles.pptx\n
///          Range: 0x0 ... 0xFFF \n
/// \param
///   [in] u_optData: provides additional information eg. errorID, clusterID, Range: 0x0 ... 0xFF \n
/// \return
///   void
/// \InOutCorrelation
///   Add Event to the last auxiliary core(virtual core).
/// \callsequence
/// \image html RTA_v_AddEventVirtCore.png Sequence Diagram
/// \startuml "RTA_v_AddEventVirtCore"
/// title RTA_v_AddEventVirtCore Sequence Diagram
/// [--> RTA_Aux_Cores: RTA_v_AddEventVirtCore(const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData)
/// activate RTA_Aux_Cores
/// note right of RTA_Aux_Cores : Virtual core should always be the last auxiliaryCore.
/// RTA_Aux_Cores -> RTA_Aux_Cores : RTA_v_AddEventAuxiliaryCores((uint8)(u_NUMBER_OF_AUX_CORES - 1uL), event, u_globalID, u_localID, u_optData)
/// activate RTA_Aux_Cores
/// deactivate RTA_Aux_Cores
/// [<-- RTA_Aux_Cores : // done //
/// deactivate RTA_Aux_Cores
/// \enduml
/// \testmethod
///   \ref TEST01_RTA_v_AddEventVirtCore \n
/// \traceability
///   to be added
void RTA_v_AddEventVirtCore(const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData);


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_AUX_CORES_H
