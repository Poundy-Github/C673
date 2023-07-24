// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - real time analysis
/// \file
/// \brief This file declares basic functions which are called in many other parts of the RTA.

#ifndef RTA_BASICS_H
#define RTA_BASICS_H

#include <rta_datasets.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// \brief Function which returns the particular dataSet for that core on which it has been called.
///
/// \pre
///   None
/// \post
///   None
/// \param
///   None
/// \return
///   RTA_t_DataSet p_dataSet: core specific data set
/// \InOutCorrelation
///   Get Core ID and set the pointer to it.
/// \callsequence
/// \image html RTA_p_GetDataSet.png
/// \startuml "RTA_p_GetDataSet"
/// title RTA_p_GetDataSet Sequence Diagram
/// [--> RTA_Basics : const RTA_t_DataSet* RTA_p_GetDataSet(void)
/// activate RTA_Basics
/// RTA_Basics -> RTA_Req_If: RTA_ReqIf_u_GetCoreId()
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Basics: // return Core ID //
/// deactivate RTA_Req_If
/// alt if Core ID < Number of Cores
/// note right of RTA_Basics: Select corresponding dataSet
/// else ELSE
/// note right of RTA_Basics: Set pointer to NULL
/// end
/// [<-- RTA_Basics : // return p_dataSet //
/// deactivate RTA_Basics
/// \enduml
///
/// \traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-405-0005ebe0">
///            doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-405-0005ebe0</a>
const RTA_t_DataSet* RTA_p_GetDataSet(void);


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_BASICS_H
