/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3CN15
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MFJSCT
  MODULES       : JCNCTR
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MFJSCTSEN.h
//! @brief     (MFJSCT) Sub-Component Sensor Header.

#ifndef MFJSCTSEN_H_
#define MFJSCTSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "JCNCTR/JCNCTR.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

#define MFJSCT_SenInitDbgPtr(MFJSCT_SenDbgPtr) JCNCTR_SenInitDbgPtr(&(MFJSCT_SenDbgPtr)->JCNCTR_SenDbgData)

/*!
 *	MFJSCT sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] MFJSCT_SenOutPtr Pointer to MFJSCT sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html MFJSCT_SenInitOutPtr_callsequence.png MFJSCT Output Initialization Call Sequence
 *		@startuml "MFJSCT_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant MFJSCT as SubCmp <<Sub-Component>>
 *			participant JCNCTR as JCNCTR <<Module>>
 *			
 *			Task -> SubCmp: MFJSCT_SenInitOutPtr(MFJSCT_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> JCNCTR: JCNCTR_SenInitOutPtr(&MFJSCT_SenOutPtr->JCNCTR_SenOutData)
 *			activate JCNCTR
 *			JCNCTR --> SubCmp: return
 *			deactivate JCNCTR
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
#define MFJSCT_SenInitOutPtr(MFJSCT_SenOutPtr) JCNCTR_SenInitOutPtr(&(MFJSCT_SenOutPtr)->JCNCTR_SenOutData)

/*!
 *	MFJSCT sub-component sensor reset function.
 *	
 *	@pre
 *		- The MFJSCT sensor initialization function(s) must be called once.
 *		- The MFJSCT sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html MFJSCT_SenReset_callsequence.png MFJSCT Reset Call Sequence
 *		@startuml "MFJSCT_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant MFJSCT as SubCmp <<Sub-Component>>
 *			participant JCNCTR as JCNCTR <<Module>>
 *			
 *			Task -> SubCmp: MFJSCT_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> JCNCTR: JCNCTR_SenReset()
 *			activate JCNCTR
 *			JCNCTR --> SubCmp: return
 *			deactivate JCNCTR
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
#define MFJSCT_SenReset JCNCTR_SenReset

/*!
 *	MFJSCT sub-component sensor process function.
 *	
 *	@pre
 *		- The MFJSCT sensor initialization function(s) must be called once.
 *		- The MFJSCT sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html MFJSCT_SenProcess_callsequence.png MFJSCT Process Call Sequence
 *		@startuml "MFJSCT_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant MFJSCT as SubCmp <<Sub-Component>>
 *			participant JCNCTR as JCNCTR <<Module>>
 *			
 *			Task -> SubCmp: MFJSCT_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> JCNCTR: JCNCTR_SenProcess()
 *			activate JCNCTR
 *			JCNCTR --> SubCmp: return
 *			deactivate JCNCTR
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
#define MFJSCT_SenProcess JCNCTR_SenProcess

#ifdef __cplusplus
}
#endif

#endif // MFJSCTSEN_H_
