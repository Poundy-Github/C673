/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : VDPR
  MODULES       : VDPDRV
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     VDPRSEN.h
//! @brief     (VDPR) Sub-Component Sensor Header.

#ifndef VDPRSEN_H_
#define VDPRSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "VDPDRV/VDPDRV.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	VDPR sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] VDPR_SenDbgPtr Pointer to VDPR sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html VDPR_SenInitDbgPtr_callsequence.png VDPR Debug Initialization Call Sequence
 *		@startuml "VDPR_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant VDPR as SubCmp <<Sub-Component>>
 *			participant VDPDRV as VDPDRV <<Module>>
 *			
 *			Task -> SubCmp: VDPR_SenInitDbgPtr(VDPR_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> VDPDRV: VDPDRV_SenInitDbgPtr(&VDPR_SenDbgPtr->VDPDRV_SenDbgData)
 *			activate VDPDRV
 *			VDPDRV --> SubCmp: return
 *			deactivate VDPDRV
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
#define VDPR_SenInitDbgPtr(VDPR_SenDbgPtr) VDPDRV_SenInitDbgPtr(&(VDPR_SenDbgPtr)->VDPDRV_SenDbgData)

/*!
 *	VDPR sub-component sensor reset function.
 *	
 *	@pre
 *		- The VDPR sensor initialization function(s) must be called once.
 *		- The VDPR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html VDPR_SenReset_callsequence.png VDPR Reset Call Sequence
 *		@startuml "VDPR_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant VDPR as SubCmp <<Sub-Component>>
 *			participant VDPDRV as VDPDRV <<Module>>
 *			
 *			Task -> SubCmp: VDPR_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> VDPDRV: VDPDRV_SenReset()
 *			activate VDPDRV
 *			VDPDRV --> SubCmp: return
 *			deactivate VDPDRV
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
#define VDPR_SenReset VDPDRV_SenReset

/*!
 *	VDPR sub-component sensor process function.
 *	
 *	@pre
 *		- The VDPR sensor initialization function(s) must be called once.
 *		- The VDPR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html VDPR_SenProcess_callsequence.png VDPR Process Call Sequence
 *		@startuml "VDPR_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant VDPR as SubCmp <<Sub-Component>>
 *			participant VDPDRV as VDPDRV <<Module>>
 *			
 *			Task -> SubCmp: VDPR_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> VDPDRV: VDPDRV_SenProcess()
 *			activate VDPDRV
 *			VDPDRV --> SubCmp: return
 *			deactivate VDPDRV
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
#define VDPR_SenProcess VDPDRV_SenProcess

#ifdef __cplusplus
}
#endif

#endif // VDPRSEN_H_
