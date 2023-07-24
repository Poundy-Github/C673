/**
 * \file Med_Type.h
 *
 * \brief This file contains related data types of Med.
 *
 * \version refer the Med_Core.h.
 *
 */

#ifndef MED_TYPE_H
#define MED_TYPE_H

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Med_Cfg.h"

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/
typedef enum
{
	Med_InitStatus_None = 0x00,
	Med_InitStatus_Uninit = 0x01,
	Med_InitStatus_Init = 0x02,
	Med_InitStatus_Max = 0xFF
}e_Med_InitStatus_t;

/*
 * \brief 	Error Detection Status
 * 			In the Med_ErrDetMode_Coincide,the software shall check the test failed or test passed condition base on Error Detection Status
 * */
typedef enum
{
	Med_ErrDetSts_None = 0x00, /*In this status,Pending*/
	Med_ErrDetSts_Init = 0x01, /*In this status,check test failed*/
	Med_ErrDetSts_TestFailed = 0x10, /*In this status,check test passed*/
	Med_ErrDetSts_TestPassed = 0x20, /*In this status,check test failed*/
	Med_ErrDetSts_Max = 0xFF /*In this status,Pending*/
}e_Med_ErrorDetectionStatus_t;

typedef enum
{
	Med_ErrDetMode_None = 0x00,
	Med_ErrDetMode_Mutex = 0x01,
	Med_ErrDetMode_Coincide = 0x02,
	Med_ErrDetMode_Max = 0xFF
}e_Med_ErrorDetectionMode_t;

typedef struct
{
#if (MED_USE_RTE_REPORT_EVENT_STATUS == STD_OFF)
	/**
	 * \brief   EventId,Use for SetEventStatus to Dem,if the Error not report to Dem,Please set the EventId to 0x00.
	 * */
	uint16 EventId;
#endif
	uint16 MonitorCycle;
	/**
	 * \brief   it means the error debounce in Med or debounce in Dem
	 * 			STD_ON : debounce in Med,so set event ststus use for DEM_EVENT_STATUS_FAILED and DEM_EVENT_STATUS_PASSED;
	 * 			STD_OFF : debounce in Med,so set event ststus use for DEM_EVENT_STATUS_PREFAILED and DEM_EVENT_STATUS_PREPASSED;
	 * */
	uint8 DebounceEnable;

	/**
	 * \brief   it means the error detection mode
	 * 			Med_ErrDetMode_Mutex : the test failed condition and test passed condition is mutex.
	 * 								   When the function pointer of Op_TestFailed return TURE,it means the error test failed;else the error test passed.
	 * 								   In this case,the function of Op_TestPassed can be configation to NULL_PTR.
	 * 			Med_ErrDetMode_Coincide : it means the test failed condition condition and test passed condition may coincide.
	 * 									  Only the function pointer of Op_TestFailed,it means the error test failed;
	 * 									  Only the function pointer of Op_TestPassed,it means the error test passed;
	 * */
	e_Med_ErrorDetectionMode_t Mode;
	/**
	 * \brief 	It is a function pointer,use for check pre-condition of Error.
	 * 			If the Error detection not need check pre-condition,it shall fill the NULL_PTR,it means skip the pre-condition check.
	 *
	 * 	parameters-in none
	 *
	 * 	parameters-out none
	 *
	 * 	return  TRUE : 	the pre-condition is satisfy
	 * 			FALSE : the pre-condition is not satisfy
	 *
	 * */
	boolean (*Op_CheckPreCond)(void);
	/**
	 * \brief 	It is a function pointer,use for check  test failed condition of Error.
	 *
	 * 	parameters-in none
	 *
	 * 	parameters-out none
	 *
	 * 	return  TRUE : 	the test failed condition is satisfy
	 * 			FALSE : the test failed condition is not satisfy
	 *
	 * */
	boolean (*Op_TestFailed)(void);
	/**
	 * \brief 	It is a function pointer,use for check  test passed condition of Error.
	 *
	 * 	parameters-in none
	 *
	 * 	parameters-out none
	 *
	 * 	return  TRUE : 	the test passed condition is satisfy
	 * 			FALSE : the test passed condition is not satisfy
	 *
	 * */
	boolean (*Op_TestPassed)(void);
#if (MED_USE_RTE_REPORT_EVENT_STATUS == STD_ON)
	/**
	 * \brief 	It is a function pointer,the function generation by Rte, use rte call Dem function
	 *
	 * 	parameters-in staus,the target event status for events
	 *
	 * 	parameters-out none
	 *
	 * 	return	uint8,please refer Dem_SetEventStstus
	 *
	 * */
	uint8 (*Op_SetEventStatus)(uint8 status);
#endif
#if (MED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION == STD_ON)
	/**
	 * \brief 	It is a function pointer,use for when error detection status changed,trigger this functions
	 *
	 * 	parameters-in status
	 * 				  status_last
	 *
	 * 	parameters-out none
	 *
	 * 	return	none
	 *
	 * */
	void (*Notify_ErrDetStsChanged)(e_Med_ErrorDetectionStatus_t status,e_Med_ErrorDetectionStatus_t status_last);
#endif
}s_Med_ErrorDetectionConfig_t;

typedef struct
{
	e_Med_ErrorDetectionStatus_t Status;
#if (MED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION == STD_ON)
	e_Med_ErrorDetectionStatus_t Status_Last;
#endif
	uint16 MonitorCycleCounter;
}s_Med_ErrorDetectionState_t;

#endif /* MED_TYPE_H */
