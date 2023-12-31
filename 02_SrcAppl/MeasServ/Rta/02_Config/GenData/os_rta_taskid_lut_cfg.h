// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: OS
/// @file
/// @brief This file contains the initializer for the RtaTaskID LookUpTable.
///        It is generated by the RtaTaskIdLutGenerator and has to be updated whenever the 
///        OS configuration is changed. 

#ifndef OS_RTA_TASKID_LUT_CFG_INCLUDED
#define OS_RTA_TASKID_LUT_CFG_INCLUDED

#include <os_rta_task_ids.h>

//Generated file - no manual changes please!****************************************************************************

/* This is the check whether the this file is compatible to the rest of the os configuration files.
   ___GENERATOR_TAG___COMPATIBILITY_CHECK___SECTION_START___  */

#include <Os_user.h>

#if OS_GENERATION_ID_OS_H != 0xe00962e5UL
#error "The taskID_Lut does not match to the os configuration! Please update this file by running the RtaTaskIdLutGenerator on current OsConfgFiles."
#endif

/* ___GENERATOR_TAG___COMPATIBILITY_CHECK___SECTION_END___
   Do not alter or remove the generatorFlag above as it is needed by the generators! */


/* This is a list of OsTaskIds and RtaTaskIds sorted by taskPriority in desending order. In case of multiCoreOs, also the 
   osCoreID is part of the list entries indicating on which core the tasks are running on
   
   This list is needed by the RtaXmlGenerator to ensure that the tasks are displayed in the rtaVisu in the order of priority.
   Do not alter or remove the following generatorFlag as it is needed by the generators! 
   ___GENERATOR_TAG___AUX_TASK_LIST___SECTION_START___

  Core0_DefaultTask                 , OS_RTA_TASKID_Default              , 0
  Core0_InitTask_Appl               , OS_RTA_TASKID_InitAppl             , 0
  Core0_OsTask_FunctionSafety_5ms   , OS_RTA_TASKID_FunctionSafety5ms    , 0
  Core0_OsTask_OperationInovkedProxy, OS_RTA_TASKID_OperationInovkedProxy, 0
  Core0_OsTask_Bsw_5ms              , OS_RTA_TASKID_Bsw5ms               , 0
  Core3_DefaultTask                 , OS_RTA_TASKID_Default              , 3
  Core1_DefaultTask                 , OS_RTA_TASKID_Default              , 1
  Core1_InitTask_Appl               , OS_RTA_TASKID_InitAppl             , 1
  Core3_InitTask_Appl               , OS_RTA_TASKID_InitAppl             , 3
  Core0_OsTask_Appl_5ms             , OS_RTA_TASKID_Appl5ms              , 0
  Core0_OsTask_Bsw_10ms             , OS_RTA_TASKID_Bsw10ms              , 0
  Core2_DefaultTask                 , OS_RTA_TASKID_Default              , 2
  Core2_InitTask_Appl               , OS_RTA_TASKID_InitAppl             , 2
  Core3_OsTask_OperationInovkedProxy, OS_RTA_TASKID_OperationInovkedProxy, 3
  Core1_OsTask_OperationInovkedProxy, OS_RTA_TASKID_OperationInovkedProxy, 1
  Core1_OsTask_Appl_10ms            , OS_RTA_TASKID_Appl10ms             , 1
  Core0_OsTask_Appl_10ms            , OS_RTA_TASKID_Appl10ms             , 0
  Core3_OsTask_Appl_60ms            , OS_RTA_TASKID_Appl60ms             , 3
  Core1_OsTask_Bsw_20ms             , OS_RTA_TASKID_Bsw20ms              , 1
  Core0_OsTask_Bsw_20ms             , OS_RTA_TASKID_Bsw20ms              , 0
  Core2_OsTask_OperationInovkedProxy, OS_RTA_TASKID_OperationInovkedProxy, 2
  Core3_OsTask_Appl_10ms            , OS_RTA_TASKID_Appl10ms             , 3
  Core0_OsTask_Appl_20ms            , OS_RTA_TASKID_Appl20ms             , 0
  Core2_OsTask_Appl_5ms             , OS_RTA_TASKID_Appl5ms              , 2
  Core3_OsTask_Bsw_20ms             , OS_RTA_TASKID_Bsw20ms              , 3
  Core1_OsTask_Appl_20ms            , OS_RTA_TASKID_Appl20ms             , 1
  Core2_OsTask_Bsw_20ms             , OS_RTA_TASKID_Bsw20ms              , 2
  Core3_OsTask_Appl_50ms            , OS_RTA_TASKID_Appl50ms             , 3
  Core0_OsTask_Appl_60ms            , OS_RTA_TASKID_Appl60ms             , 0
  Core1_OsTask_Appl_60ms            , OS_RTA_TASKID_Appl60ms             , 1

   ___GENERATOR_TAG___AUX_TASK_LIST___SECTION_END___   
   Do not alter or remove the generatorFlag above as it is needed by the generators!  */


/* This is the initializer macro for the taskIdLookupTable used in RTA. It contains all RtaTaskID in the order of the OsTaskID.
   ___GENERATOR_TAG___LUT___SECTION_START___  */

#define OS_RTA_TASKID_LUT_INITIALIZER \
  (uint8)OS_RTA_TASKID_Bsw5ms               , \
  (uint8)OS_RTA_TASKID_Appl20ms             , \
  (uint8)OS_RTA_TASKID_Appl60ms             , \
  (uint8)OS_RTA_TASKID_OperationInovkedProxy, \
  (uint8)OS_RTA_TASKID_Bsw20ms              , \
  (uint8)OS_RTA_TASKID_Appl10ms             , \
  (uint8)OS_RTA_TASKID_Bsw20ms              , \
  (uint8)OS_RTA_TASKID_Appl5ms              , \
  (uint8)OS_RTA_TASKID_Bsw20ms              , \
  (uint8)OS_RTA_TASKID_OperationInovkedProxy, \
  (uint8)OS_RTA_TASKID_Default              , \
  (uint8)OS_RTA_TASKID_InitAppl             , \
  (uint8)OS_RTA_TASKID_FunctionSafety5ms    , \
  (uint8)OS_RTA_TASKID_Bsw10ms              , \
  (uint8)OS_RTA_TASKID_Bsw20ms              , \
  (uint8)OS_RTA_TASKID_Appl5ms              , \
  (uint8)OS_RTA_TASKID_Appl10ms             , \
  (uint8)OS_RTA_TASKID_Default              , \
  (uint8)OS_RTA_TASKID_InitAppl             , \
  (uint8)OS_RTA_TASKID_Appl20ms             , \
  (uint8)OS_RTA_TASKID_Appl60ms             , \
  (uint8)OS_RTA_TASKID_OperationInovkedProxy, \
  (uint8)OS_RTA_TASKID_Default              , \
  (uint8)OS_RTA_TASKID_InitAppl             , \
  (uint8)OS_RTA_TASKID_OperationInovkedProxy, \
  (uint8)OS_RTA_TASKID_Default              , \
  (uint8)OS_RTA_TASKID_InitAppl             , \
  (uint8)OS_RTA_TASKID_Appl10ms             , \
  (uint8)OS_RTA_TASKID_Appl50ms             , \
  (uint8)OS_RTA_TASKID_Appl60ms             


  /// The NumberOfTaskDefine used as array size of the taskLookupTable
  #define OS_NUMBER_OF_TASKS 30U
  
/* ___GENERATOR_TAG___LUT___SECTION_END___ 
   Do not alter or remove the generatorFlag above as it is needed by the generators! */



//Generated file - no manual changes please!****************************************************************************

#endif //OS_RTA_TASKID_LUT_CFG_INCLUDED
