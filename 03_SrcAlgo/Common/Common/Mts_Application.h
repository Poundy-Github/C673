// **********************************************************************
// 
//COMPANY:     Continental Automotive 
// 
//PROJECT:     ARS400
//    
//CPU:         MPC577xN, MPC567xK, SPC56AP60
// 
//Component:   Mts_Adaption_Cmp
// 
//MODULNAME:   FullModelElementName
// 
//Description:  MTS application supports the high level interfaces. 
//Data can be frozen here (also for peaklist), update the cycle id, 
//start new MTA frames, read and write NVM values, 
//select the lane configuration, set DEMs if necessary and set the instance number.
// 
// **********************************************************************         

//Suppressed QAC Messages:
//PRQA S 6005 MtsApplBlockDisable


#ifndef Mts_Application_H
#define Mts_Application_H

//needed for cycleids
#include "glob_comp_id.h"
//global type definitions
#include "glob_type.h"
//mts hal
//#include "Mts_HalRR.h"//Deleted by Mingfen
#include "Meas.h"//Added by Mingfen
/*## package ARS400_SW_Algo_Pkg::CoreComponents_Pkg::Mts_Pkg */

/*## class TopLevel::Mts_Application */
/*#[ ignore */
//Description:  MTS application supports the high level interfaces. 
//Data can be frozen here (also for peaklist), update the cycle id, 
//start new MTA frames, read and write NVM values, 
//select the lane configuration, set DEMs if necessary and set the instance number.
/*#]*/

#ifndef Std_Types_H
#include "Std_Types.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif


//Description:  Language for test
//Range:        -
//Resolution:   -
//Unit:         -



// Dummy implementation, will be removed in next versions
// Testenvironment

#define MTS_VA_NEW_PROTOCOL_1  0x80050100uL
#define MTS_VA_NEW_PROTOCOL_2  0x80050120uL
#define MTS_VA_NEW_PROTOCOL_3  0x80050130uL
#define MTS_VA_NEW_PROTOCOL_4  0x80050150uL
#define MTS_VA_NEW_PROTOCOL_5  0x80050170uL
#define MTS_VA_MTS_STATUS      0x80050200uL
#define MTS_VA_NEW_PROTOCOL_6  0x80050300uL
//      MTS_VA_MTS_CTRL_VAR    0x80050500uL
#define MTS_VA_NEW_PROTOCOL_7  0x80050600uL
#define MTS_VA_NEW_PROTOCOL_8  0x80050800uL
#define MTS_VA_NEW_PROTOCOL_9  0x80050C00uL

/* use this id just in MTS component */
#define MTS_TASK_ID            TASK_ID_SW_RADAR_CYCLE
#define MTS_FUNC_ID            COMP_ID_MEAS_MF


#define MEASStartFuncCycle(a) MTS_v_SetTaskCounter(a)   // PRQA S 3429, 3453
/*  3429 A function-like macro is being defined
    3453 A function could probably be used instead of this function-like macro.
date: 2014-07-08, reviewer: Sauter, reason: macros intended */


//Description:  callback type for MTS
//Range:        void
//Resolution:   -
//Unit:         -
typedef void (*MEAS_Callback_t)(void); 

//Description:  type for Function ID. Needed vor MTS Protocoll v2
//Range:        uint8
//Resolution:   -
//Unit:         -
typedef uint8 MEASFuncID_t;

//Description:  type for Function Channel ID. Needed vor MTS Protocoll v2
//Range:        uint8
//Resolution:   -
//Unit:         -
typedef uint8 MEASFuncChannelID_t;

//Description:  main header structure for freezes
//Range:        -
//Resolution:   -
//Unit:         -
//typedef struct MEASInfo_t {//Deleted by Mingfen
//  //Description:  locate the virual address
//  //Range:        uint32
//  //Resolution:   -
//  //Unit:         -
//  uint32 VirtualAddress;		/*## attribute VirtualAddress */
//  //Description:  payload size for mts freeze
//  //Range:        uint32
//  //Resolution:   -
//  //Unit:         -
//  uint32 Length;		/*## attribute Length */
//  //Description:  in protocol v1 the cycle id is stored here
//  //Range:        uint8
//  //Resolution:   -
//  //Unit:         -
//  MEASFuncID_t FuncID;		/*## attribute FuncID */
//  //Description:  in protocol v1 the chanel id is stored here
//  //Range:        uint8
//  //Resolution:   -
//  //Unit:         -
//  MEASFuncChannelID_t FuncChannelID;		/*## attribute FuncChannelID */
//} MEASInfo_t;

//Description:  return values of interface functions
//Range:        -
//Resolution:   -
//Unit:         -
//typedef enum MEASReturn_t {//Deleted by Mingfen
//  MEAS_OK = 0, //No error
//  MEAS_JOB_LIMIT = 1, //Error: Job limit
//  MEAS_FULL_BUFFER = 2, //Error: Full buffer
//  MEAS_BAD_GROUP_ID = 3, //Error: Bad group ID
//  MEAS_BAD_DATA_ALIGNMENT = 4, //Error: Bad data alignment
//  MEAS_CALL_FROM_IRQ_LEVEL = 5, //Error: Call from IRQ level
//  MEAS_JOB_REJECTED = 6, //Error: Job rejected in start phase
//  MEAS_BUFFER_SIZE_TOO_BIG = 7, //Error: Buffer size too big
//  MEAS_INFOBLOCK_WRONG = 8 //Error: Meas Infoblock wrong
//} MEASReturn_t;

//Description:  structure for instance number
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MtsInstanceNbrElem {
  //Description:  read instance vlaue 
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 u_RdValue;		/*## attribute u_RdValue */
  //Description:  value to set the instance number
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 u_SetValue;		/*## attribute u_SetValue */
  //Description:  enable flag to change the instance number
  //Range:        -
  //Resolution:   -
  //Unit:         -
  uint16 u_SetEnable;		/*## attribute u_SetEnable */
} MtsInstanceNbrElem;

//Description:  max value for task counter
//Range:        uint16
//Resolution:   -
//Unit:         -
/*## attribute MTS_TASK_COUNTER_MAX */
#define MTS_TASK_COUNTER_MAX 256

//Description:  version number for header file
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_VER_APPL_H */
#define MTS_VER_APPL_H (uint8) 32

//Description:  indicates the current selected lane configuration
//Range:        MTS_LaneConfig
//Resolution:   -
//Unit:         -
/*## attribute MTS_CurrLaneConfig */
extern MTS_LaneConfig MTS_CurrLaneConfig;

//Description:  Information for reading/setting instance number
//Range:        MtsInstanceNbrElem
//Resolution:   -
//Unit:         -
/*## attribute MtsInstanceNumber */
extern MtsInstanceNbrElem MtsInstanceNumber;

/***    User explicit entries    ***/


/* Operations */

//METHOD: void MTS_v_InitAppl().
//**************************************************************************
//Description:    init most of the MTS component
//Return value:   none
//Preconditions:  run in init list of OS before main
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitAppl() */
void MTS_v_InitAppl(void);

//METHOD: void MTS_v_MainfunctionAppl().
//**************************************************************************
//Description:    take timestamp, set correct lane configuration depend on NVM value
//set instance number if necessary, check DEM events, send status information via MTS
//Return value:   none
//Preconditions:  call every 10 ms
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_MainfunctionAppl() */
void MTS_v_MainfunctionAppl(void);

//METHOD: MEASReturn_t MEASFreezeDataMTS(MEASInfo_t MeasInfo_ptr,pvoid MeasData_ptr,MEAS_Callback_t MeasFct_ptr).
//**************************************************************************
//Description:    wrapper to support old MTS v1 protocol
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# MeasInfo_ptr [InOut] Description:  header information for MTS freeze
//Range:        MEASInfo_t
//Resolution:   -
//Unit:         -
//# MeasData_ptr [In] Description:  data pointer to payload
//Range:        pvoid
//Resolution:   -
//Unit:         -
//# MeasFct_ptr [In] Description:  callback for mts freeze caller
//Range:        MEAS_Callback_t
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MEASFreezeDataMTS(MEASInfo_t,pvoid,MEAS_Callback_t) */
MEASReturn_t MEASFreezeDataMTS(const MEASInfo_t* MeasInfo_ptr, pvoid MeasData_ptr, MEAS_Callback_t MeasFct_ptr);

//METHOD: MEASReturn_t MEASFreezeSPTConfig(MEASInfo_t MeasInfo_ptr,pvoid MeasData_ptr,MEAS_Callback_t MeasFct_ptr).
//**************************************************************************
//Description:    wrapper to send software SPT data from Algo
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# MeasInfo_ptr [InOut] Description:  header information for MTS freeze
//Range:        MEASInfo_t
//Resolution:   -
//Unit:         -
//
//# MeasData_ptr [In] Description:  data pointer to payload
//Range:        pvoid
//Resolution:   -
//Unit:         -
//# MeasFct_ptr [In] Description:  callback for mts freeze caller
//Range:        MEAS_Callback_t
//Resolution:   -
//Unit:         -
//
//
//**************************************************************************
/*## operation MEASFreezeSPTConfig(MEASInfo_t,pvoid,MEAS_Callback_t) */
MEASReturn_t MEASFreezeSPTConfig(const MEASInfo_t* MeasInfo_ptr, pvoid MeasData_ptr, MEAS_Callback_t MeasFct_ptr);

//METHOD: void MTS_v_SetTaskCounter(uint16 u_TaskId).
//**************************************************************************
//Description:    update the cycle ids and calculate amount of job and payload per cycle
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# u_TaskId [In] Description:  current task/ cycle id
//Range:        uint16
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MTS_v_SetTaskCounter(uint16) */
void MTS_v_SetTaskCounter(const uint16 u_TaskId);

//METHOD: uint16 MTS_u_GetTaskCounterValue(uint16 u_TaskId).
//**************************************************************************
//Description:    return the current value for a given cycle id
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# u_TaskId [In] Description:  take cycle id
//Range:        204-216 (see glob_comp_id)
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MTS_u_GetTaskCounterValue(uint16) */
uint16 MTS_u_GetTaskCounterValue(const uint16 u_TaskId);

//METHOD: MEASReturn_t MTS_v_FreezePeakList(MEASInfo_t p_PeakInfo,void p_PeakData,MEAS_Callback_t v_Callback).
//**************************************************************************
//Description:    main freeze interface for peaklist. Get the frozen data and store it in job buffer. Data will be prepared to send.
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# p_PeakInfo [InOut] Description:  header information for MTS freeze
//Range:        MEASInfo_t
//Resolution:   -
//Unit:         -
//
//# p_PeakData [InOut] Description:  data pointer to payload
//Range:        pvoid
//Resolution:   -
//Unit:         -
//# v_Callback [In] Description:  callback for mts freeze caller
//Range:        MEAS_Callback_t
//Resolution:   -
//Unit:         -
//
//
//**************************************************************************
/*## operation MTS_v_FreezePeakList(MEASInfo_t,void,MEAS_Callback_t) */
MEASReturn_t MTS_v_FreezePeakList(const MEASInfo_t* p_PeakInfo, void * p_PeakData, MEAS_Callback_t v_Callback);

//METHOD: void MTS_v_FiFo_ISRfunc().
//**************************************************************************
//Description:    interrupt handler of MTI interface. Occurances can be Lane transmit finish, data under/overflow...
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_FiFo_ISRfunc() */
void MTS_v_FiFo_ISRfunc(void);

//METHOD: MTS_LaneConfig MTS_GetLaneConfig().
//**************************************************************************
//Description:    returns the current lane configuration
//Return value:   MTS_LaneConfig
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_GetLaneConfig() */
MTS_LaneConfig MTS_GetLaneConfig(void);

//METHOD: boolean MTS_b_SetInstanceNumber(uint8 u_InstanceNbr).
//**************************************************************************
//Description:    possibility to set a new instance number. This can just be done once per ignition cycle
//Return value:   none
//Preconditions:  NVM must be initialized
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# u_InstanceNbr [In] Description:  set instance number
//Range:        uint8
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MTS_b_SetInstanceNumber(uint8) */
boolean MTS_b_SetInstanceNumber(const uint8 u_InstanceNbr);

/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif


#endif
/*
  6005) Unknown error: no change
*/
/* date: 2014-03-03, reviewer: Sauter, reason: see above, proven in use */
// PRQA L:MtsApplBlockDisable

/*********************************************************************
	File Path	: ..\..\..\04_Engineering\_gensrc\rhapsody\Mts_Application.h
*********************************************************************/

