/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : HMIOC
  MODULES       : HMODFL
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     HMIOCSEN.h
//! @brief     (HMIOC) Sub-Component Sensor Header.

#ifndef HMIOCSEN_H_
#define HMIOCSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "HMODFL/HMODFL.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	HMIOC sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] HMIOC_SenOutPtr Pointer to HMIOC sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html HMIOC_SenInitOutPtr_callsequence.png HMIOC Output Initialization Call Sequence
 *		@startuml "HMIOC_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant HMIOC as SubCmp <<Sub-Component>>
 *			participant HMODFL as HMODFL <<Module>>
 *			
 *			Task -> SubCmp: HMIOC_SenInitOutPtr(HMIOC_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> HMODFL: HMODFL_SenInitOutPtr(&HMIOC_SenOutPtr->HMODFL_SenOutData)
 *			activate HMODFL
 *			HMODFL --> SubCmp: return
 *			deactivate HMODFL
 *			
 *			SubCmp --> Task: return
 *			deactivate SubCmp
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
#define HMIOC_SenInitOutPtr(HMIOC_SenOutPtr) HMODFL_SenInitOutPtr(&(HMIOC_SenOutPtr)->HMODFL_SenOutData)

/*!
 *	HMIOC sub-component sensor reset function.
 *	
 *	@pre
 *		- The HMIOC sensor initialization function(s) must be called once.
 *		- The HMIOC sensor debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html HMIOC_SenReset_callsequence.png HMIOC Reset Call Sequence
 *		@startuml "HMIOC_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant HMIOC as SubCmp <<Sub-Component>>
 *			participant HMODFL as HMODFL <<Module>>
 *			
 *			Task -> SubCmp: HMIOC_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> HMODFL: HMODFL_SenReset()
 *			activate HMODFL
 *			HMODFL --> SubCmp: return
 *			deactivate HMODFL
 *			
 *			SubCmp --> Task: return
 *			deactivate SubCmp
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
#define HMIOC_SenReset HMODFL_SenReset

/*!
 *	HMIOC sub-component sensor process function.
 *	
 *	@pre
 *		- The HMIOC sensor initialization function(s) must be called once.
 *		- The HMIOC sensor debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html HMIOC_SenProcess_callsequence.png HMIOC Process Call Sequence
 *		@startuml "HMIOC_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant HMIOC as SubCmp <<Sub-Component>>
 *			participant HMODFL as HMODFL <<Module>>
 *			
 *			Task -> SubCmp: HMIOC_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> HMODFL: HMODFL_SenProcess()
 *			activate HMODFL
 *			HMODFL --> SubCmp: return
 *			deactivate HMODFL
 *			
 *			SubCmp --> Task: return
 *			deactivate SubCmp
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
#define HMIOC_SenProcess HMODFL_SenProcess

#ifdef __cplusplus
}
#endif

#endif // HMIOCSEN_H_
