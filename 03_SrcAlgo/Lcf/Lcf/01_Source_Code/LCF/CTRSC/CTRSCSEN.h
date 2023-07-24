/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : CTRSC
  MODULES       : CSCLTA
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     CTRSCSEN.h
//! @brief     (CTRSC) Sub-Component Sensor Header.

#ifndef CTRSCSEN_H_
#define CTRSCSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "CSCLTA/CSCLTA.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	CTRSC sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] CTRSC_SenOutPtr Pointer to CTRSC sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html CTRSC_SenInitOutPtr_callsequence.png CTRSC Output Initialization Call Sequence
 *		@startuml "CTRSC_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant CTRSC as SubCmp <<Sub-Component>>
 *			participant CSCLTA as CSCLTA <<Module>>
 *			
 *			Task -> SubCmp: CTRSC_SenInitOutPtr(CTRSC_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> CSCLTA: CSCLTA_SenInitOutPtr(&CTRSC_SenOutPtr->CSCLTA_SenOutData)
 *			activate CSCLTA
 *			CSCLTA --> SubCmp: return
 *			deactivate CSCLTA
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
#define CTRSC_SenInitOutPtr(CTRSC_SenOutPtr) CSCLTA_SenInitOutPtr(&(CTRSC_SenOutPtr)->CSCLTA_SenOutData)

/*!
 *	CTRSC sub-component sensor reset function.
 *	
 *	@pre
 *		- The CTRSC sensor initialization function(s) must be called once.
 *		- The CTRSC sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html CTRSC_SenReset_callsequence.png CTRSC Reset Call Sequence
 *		@startuml "CTRSC_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant CTRSC as SubCmp <<Sub-Component>>
 *			participant CSCLTA as CSCLTA <<Module>>
 *			
 *			Task -> SubCmp: CTRSC_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> CSCLTA: CSCLTA_SenReset()
 *			activate CSCLTA
 *			CSCLTA --> SubCmp: return
 *			deactivate CSCLTA
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
#define CTRSC_SenReset CSCLTA_SenReset

/*!
 *	CTRSC sub-component sensor process function.
 *	
 *	@pre
 *		- The CTRSC sensor initialization function(s) must be called once.
 *		- The CTRSC sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html CTRSC_SenProcess_callsequence.png CTRSC Process Call Sequence
 *		@startuml "CTRSC_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant CTRSC as SubCmp <<Sub-Component>>
 *			participant CSCLTA as CSCLTA <<Module>>
 *			
 *			Task -> SubCmp: CTRSC_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> CSCLTA: CSCLTA_SenProcess()
 *			activate CSCLTA
 *			CSCLTA --> SubCmp: return
 *			deactivate CSCLTA
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
#define CTRSC_SenProcess CSCLTA_SenProcess

#ifdef __cplusplus
}
#endif

#endif // CTRSCSEN_H_
