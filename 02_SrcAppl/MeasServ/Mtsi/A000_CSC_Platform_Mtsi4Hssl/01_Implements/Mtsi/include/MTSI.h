// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.3 $

#ifndef MTSI_H
#define MTSI_H

#include <MTSI_Custom.h>
#include <Meas.h>
#if (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE))
//#include <TestStimuli.h>
#endif
#if (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE))
#define SHORTTERMADJUSTMENT 0
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief    Initialization of MTSI component
///           Accomplish initialization of all MTSI modules:
///           - Driver
///           - Custom
///           - Statistics
///           - PAL
/// @pre      none
/// @post     none
/// @param    none
/// @return   void
/// @globals
///   @ref InitDone
/// @InOutCorrelation
///   This function handles the initialization routines of the MTSI.
///   All of the structures that will be used in the general handling are initialized (sync buffers, async queues, statistics part, HW abstraction part).
///   Function does not take input, it is just called in the ECUM InitList.
///   To be noted that this MUST be called before any freeze is requested from external components.
/// @callsequence
///   @image html MTSI_Init.png MTSI Initialization
/// @testmethod
///   1) TEST_MTSI_Init_1 : Code coverage for MTSI_Init() function.
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-457-0005ebe0"><strong> MTSI_Init L4 Design Specification</strong></a>
/// @return void 
void MTSI_Init(void);


/// @brief      DeInitialization of MTSI component
/// @pre        none
/// @post       none
/// @param      none
/// @return     void
/// @globals
///   @ref InitDone
/// @InOutCorrelation
///   It will deinitialize the driver module as well as PAL, and reset the flag which indicates if initialization of MTSI is done.
/// @callsequence
///   @image html MTSI_DeInit.png MTSI Deinitialization
/// @testmethod
///   1) TEST_MTSI_DeInit_1 : Call MTSI_DeInit() function and deinitialize the driver module. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-458-0005ebe0"><strong> MTSI_DeInit L4 Design Specification</strong></a>
/// @return     void
void MTSI_DeInit(void);


/// @brief      Cyclic 10ms function
///             This function must be called cyclically every 10ms by the base SW.
/// @pre     none
/// @post    none
/// @param   none
/// @return  void
/// @globals none
/// @InOutCorrelation
///   If a measfreeze has been lost/rejected by MTSI, it will report a DEMevent.
/// @callsequence
///   @image html MTSI_MainFunction.png MTSI Main Function
/// @testmethod
///   1) TEST_MTSI_MainFunction_1 : Code coverage for function MTSI_MainFunction() when measfreeze has not been lost. \n
///   2) TEST_MTSI_MainFunction_2 : Code coverage for function MTSI_MainFunction() when measfreeze has been lost.
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-459-0005ebe0"><strong> MTSI_MainFunction L4 Design Specification</strong></a>
/// @return     void
void MTSI_MainFunction(void);


#if (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE))
/// @brief Description: called by TestStimuli_FunctionCalls. \n
///		   Stimuli for Dem reporting
/// @pre       Stimuli tests are cyclicly called by the test stimuli main function
/// @post      none
/// @param[in] u_TestModuleId  : ID for module test \n
///	@param[in] u_TestCaseId    : ID representing the particular test case to be triggered  \n
/// @param[in] u_TestAction    : Action that determines the behavior of the particular test case \n
/// @param[in] u_Value   	   : The value to be used (number for the stimuli max virtual address)
/// @return    void
/// @globals   none
/// @InOutCorrelation
///    Acquire u_TestModuleId (if not handed over) and calls v_MTSIDem() which will call the MEASFreezeDataMTS function if u_TestAction == SHORTTERMADJUSTMENT (the signal is locked and adjust to the given value).  
/// @callsequence  None
/// @testmethod
///   1) TEST_MTSI_v_Dem_TestManager_1 : Code coverage for function MTSI_v_Dem_TestManager() when the signal is locked and the stimuli are set for max virtual address. \n
///   2) TEST_MTSI_v_Dem_TestManager_2 : Code coverage for function MTSI_v_Dem_TestManager() when the signal is locked and adjust to the given value (0x03) \n
///   3) TEST_MTSI_v_Dem_TestManager_3 : Code coverage for function MTSI_v_Dem_TestManager() when the signal is unlock.
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-674-0005ebe0"><strong> MTSI_v_Dem_TestManager L4 Design Specification</strong></a>
///New TestStimuli architecture
void MTSI_v_Dem_TestManager(const uint16 u_TestModuleId, const uint16 u_TestCaseId, const uint8 u_TestAction, const uint32 u_Value);
#endif // (defined(CFG_MTSI_TST_ENABLED) && (CFG_MTSI_TST_ENABLED == TRUE))

#ifdef __cplusplus
}
#endif

#endif


