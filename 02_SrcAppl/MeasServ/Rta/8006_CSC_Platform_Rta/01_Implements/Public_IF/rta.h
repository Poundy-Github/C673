// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT:      RTA - Real-Time Analysis
/// \file
/// \brief The public interface of the RTA component

#ifndef RTA_H
#define RTA_H

#include <rta_types.h>
#include <rta_globalids.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** Description: This define is used to ensure compatibility.\n
 *               \b Note: It has to be incremented whenever the enum RTA_t_Events or the typedef RTA_t_ServiceAddEvent is changed\n
 * */
#define RTA_INTERFACE_VERSION 6

/// initialization of the RTA component, mainly by calling of function v_InitDataSet
/// \pre
///   The systemTime has to be available
/// \post
///   After successful run of this function the RTA is ready to use.
/// \param
///   void
/// \return
///   void
void RTA_v_Init(void);

/// main function, toggles and freezes RTA buffer \n
/// There are 2 ways of calling RTA, either the main function is called from task index,
/// or RTA_v_SwitchBuffer is called at cycleStart from interrupt context and RTA_v_FreezeBuffer afterwards from task index. \n
/// The main function is used in case there is not enough RAM given to RTA buffers to be called only once per cycle. \n
/// Disadvantage: visualization jitter in MO when it's called more often from task index. Advantage: less RAM used.
/// \pre
///   RTA must be initialized
/// \post
///   RTA buffer is toggled and frozen to MTSI
/// \param
///   void
/// \return
///   void
void RTA_v_MainFunction(void);

/// switches the rtaBuffers of the dataSet
/// It also fills the systemTime and the localTime in the new writeBuffer
/// which is used as reference to calculate the deltaTime for each new event.
/// \pre
///   The RTA component has to be initialized and interrupts need to be enabled
/// \post
///   The buffer that has been filled with rtaEvents is marked for freezing to MTSI and
///   the recently frozen buffer is marked for filling with upcoming rtaEvents
/// \param
///   void
/// \return
///   void
void RTA_v_SwitchBuffer(void);

/// freezes the RTA buffer that is currently not used/marked for writing
/// \pre
///   The RTA component has to be initialized
/// \post
///   The rtaBuffer that has been frozen can be overwritten by new rtaEvents in the next cycle
/// \param
///   void
/// \return
///   void
void RTA_v_FreezeBuffer(void);

/// adds a new rtaEvent to the rtaBuffer, called by user
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
///   [in] u_optData: provides additional information e.g. errorID, clusterID, Range: 0x0 ... 0xFF \n
/// \return
///   void
void RTA_v_AddEvent(const RTA_t_Events event, const RTA_t_GlobalID u_globalID, const RTA_t_LocalID u_localID, const RTA_t_OptData u_optData);

#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_H

