// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.2 $
/// @file

#ifndef MTSI_Callouts_H
#define MTSI_Callouts_H

#include <Std_Types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// Operations

/// @brief     Returns the lane, on which data with a given function ID shall be transmitted.
/// @pre       none
/// @post      none
/// @param[in] FunctionId  Function ID of data as given by info block of freeze function.
/// @return    Custom LaneId depending on input parameters.
/// @globals   none
/// @InOutCorrelation none
/// @callsequence
///   @startuml "MTSI_CustomGetLaneId.png"
///   title Sequence Diagram for CustomGetLaneId Function
/// @testmethod
///   @ref TEST_MTSI_CustomGetLaneId_1: Code coverage for function MTSI_CustomGetLaneId() \n
/// @traceability
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-760-0005ebe0"><strong> MTSI_CustomGetLaneId L4 Design Specification</strong></a>
uint8 MTSI_CustomGetLaneId(const uint16 FunctionId);

/// @brief     Project specific initialization of the MTSI component
///            Output mode and instance number are set in this function.
/// @param[in] p_Mode Output mode of MTSI \n
/// @param[in] p_InstanceNr Instance number of ECU
/// @return    InitState - initialization state after processing the custom init part.
/// @globals
///   @ref ConfigMode
/// @InOutCorrelation
///   This function check the validity of input parameters and than set output mode, instance
///   number and status of initialization, if the usage of NvM parameters is enabled or disable.
/// @callsequence
///   @image html MTSI_CustomInit.png MTSI Main Function
/// @testmethod
///   1) @ref TEST_MTSI_CustomInit_1: Code coverage for function MTSI_CustomInit in case of invalid pointers. \n
///   2) @ref TEST_MTSI_CustomInit_2: Code coverage for function MTSI_CustomInit at regular circumstances. \n
///   3) @ref TEST_MTSI_CustomInit_3: Code coverage for function MTSI_CustomInit in case MTSI is disabled. \n
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-758-0005ebe0"><strong> MTSI_CustomInit L4 Design Specification</strong></a>
Std_ReturnType MTSI_CustomInit(uint8 * const p_Mode, uint8 * const p_InstanceNr);

#ifdef __cplusplus
}
#endif


#endif


