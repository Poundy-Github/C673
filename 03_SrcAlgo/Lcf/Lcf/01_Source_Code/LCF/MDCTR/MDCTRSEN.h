/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULES       : MCTLFC
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MDCTRSEN.h
//! @brief     (MDCTR) Sub-Component Sensor Header.

#ifndef MDCTRSEN_H_
#define MDCTRSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "MCTLFC/MCTLFC.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	MDCTR sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] MDCTR_SenOutPtr Pointer to MDCTR sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html MDCTR_SenInitOutPtr_callsequence.png MDCTR Output Initialization Call Sequence
 *		@startuml "MDCTR_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant MDCTR as SubCmp <<Sub-Component>>
 *			participant MCTLFC as MCTLFC <<Module>>
 *			
 *			Task -> SubCmp: MDCTR_SenInitOutPtr(MDCTR_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> MCTLFC: MCTLFC_SenInitOutPtr(&MDCTR_SenOutPtr->MCTLFC_SenOutData)
 *			activate MCTLFC
 *			MCTLFC --> SubCmp: return
 *			deactivate MCTLFC
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
#define MDCTR_SenInitOutPtr(MDCTR_SenOutPtr) MCTLFC_SenInitOutPtr(&(MDCTR_SenOutPtr)->MCTLFC_SenOutData)

/*!
 *	MDCTR sub-component sensor reset function.
 *	
 *	@pre
 *		- The MDCTR sensor initialization function(s) must be called once.
 *		- The MDCTR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html MDCTR_SenReset_callsequence.png MDCTR Reset Call Sequence
 *		@startuml "MDCTR_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant MDCTR as SubCmp <<Sub-Component>>
 *			participant MCTLFC as MCTLFC <<Module>>
 *			
 *			Task -> SubCmp: MDCTR_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> MCTLFC: MCTLFC_SenReset()
 *			activate MCTLFC
 *			MCTLFC --> SubCmp: return
 *			deactivate MCTLFC
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
#define MDCTR_SenReset MCTLFC_SenReset

/*!
 *	MDCTR sub-component sensor process function.
 *	
 *	@pre
 *		- The MDCTR sensor initialization function(s) must be called once.
 *		- The MDCTR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html MDCTR_SenProcess_callsequence.png MDCTR Process Call Sequence
 *		@startuml "MDCTR_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant MDCTR as SubCmp <<Sub-Component>>
 *			participant MCTLFC as MCTLFC <<Module>>
 *			
 *			Task -> SubCmp: MDCTR_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> MCTLFC: MCTLFC_SenProcess()
 *			activate MCTLFC
 *			MCTLFC --> SubCmp: return
 *			deactivate MCTLFC
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
#define MDCTR_SenProcess MCTLFC_SenProcess

#ifdef __cplusplus
}
#endif

#endif // MDCTRSEN_H_
