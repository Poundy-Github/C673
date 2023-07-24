/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v1ABPR
  MODULES       : ABPLBP,ABPREP
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     v1ABPRSEN.h
//! @brief     (v1ABPR) Sub-Component Sensor Header.

#ifndef V1ABPRSEN_H_
#define V1ABPRSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPLBP/ABPLBP.h"
#include "ABPREP/ABPREP.h"
#include "v1ABPRSEN_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	v1ABPR sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] v1ABPR_SenDbgPtr Pointer to v1ABPR sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html v1ABPR_SenInitDbgPtr_callsequence.png v1ABPR Debug Initialization Call Sequence
 *		@startuml "v1ABPR_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1ABPR as SubCmp <<Sub-Component>>
 *			participant ABPLBP as ABPLBP <<Module>>
 *			participant ABPREP as ABPREP <<Module>>
 *			
 *			Task -> SubCmp: v1ABPR_SenInitDbgPtr(v1ABPR_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> ABPLBP: ABPLBP_SenInitDbgPtr(&v1ABPR_SenDbgPtr->ABPLBP_SenDbgData)
 *			activate ABPLBP
 *			ABPLBP --> SubCmp: return
 *			deactivate ABPLBP
 *			
 *			SubCmp -> ABPREP: ABPREP_SenInitDbgPtr(&v1ABPR_SenDbgPtr->ABPREP_SenDbgData)
 *			activate ABPREP
 *			ABPREP --> SubCmp: return
 *			deactivate ABPREP
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
extern void v1ABPR_SenInitDbgPtr(v1ABPR_SenDbgType *v1ABPR_SenDbgPtr);

/*!
 *	v1ABPR sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] v1ABPR_SenOutPtr Pointer to v1ABPR sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html v1ABPR_SenInitOutPtr_callsequence.png v1ABPR Output Initialization Call Sequence
 *		@startuml "v1ABPR_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1ABPR as SubCmp <<Sub-Component>>
 *			participant ABPLBP as ABPLBP <<Module>>
 *			participant ABPREP as ABPREP <<Module>>
 *			
 *			Task -> SubCmp: v1ABPR_SenInitOutPtr(v1ABPR_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> ABPLBP: ABPLBP_SenInitOutPtr(&v1ABPR_SenOutPtr->ABPLBP_SenOutData)
 *			activate ABPLBP
 *			ABPLBP --> SubCmp: return
 *			deactivate ABPLBP
 *			
 *			SubCmp -> ABPREP: ABPREP_SenInitOutPtr(&v1ABPR_SenOutPtr->ABPREP_SenOutData)
 *			activate ABPREP
 *			ABPREP --> SubCmp: return
 *			deactivate ABPREP
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
extern void v1ABPR_SenInitOutPtr(v1ABPR_SenOutType *v1ABPR_SenOutPtr);

/*!
 *	v1ABPR sub-component sensor reset function.
 *	
 *	@pre
 *		- The v1ABPR sensor initialization function(s) must be called once.
 *		- The v1ABPR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html v1ABPR_SenReset_callsequence.png v1ABPR Reset Call Sequence
 *		@startuml "v1ABPR_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1ABPR as SubCmp <<Sub-Component>>
 *			participant ABPLBP as ABPLBP <<Module>>
 *			participant ABPREP as ABPREP <<Module>>
 *			
 *			Task -> SubCmp: v1ABPR_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> ABPLBP: ABPLBP_SenReset()
 *			activate ABPLBP
 *			ABPLBP --> SubCmp: return
 *			deactivate ABPLBP
 *			
 *			SubCmp -> ABPREP: ABPREP_SenReset()
 *			activate ABPREP
 *			ABPREP --> SubCmp: return
 *			deactivate ABPREP
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
extern void v1ABPR_SenReset(void);

/*!
 *	v1ABPR sub-component sensor process function.
 *	
 *	@pre
 *		- The v1ABPR sensor initialization function(s) must be called once.
 *		- The v1ABPR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html v1ABPR_SenProcess_callsequence.png v1ABPR Process Call Sequence
 *		@startuml "v1ABPR_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1ABPR as SubCmp <<Sub-Component>>
 *			participant ABPLBP as ABPLBP <<Module>>
 *			participant ABPREP as ABPREP <<Module>>
 *			
 *			Task -> SubCmp: v1ABPR_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> ABPLBP: ABPLBP_SenProcess()
 *			activate ABPLBP
 *			ABPLBP --> SubCmp: return
 *			deactivate ABPLBP
 *			
 *			SubCmp -> ABPREP: ABPREP_SenProcess()
 *			activate ABPREP
 *			ABPREP --> SubCmp: return
 *			deactivate ABPREP
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
extern void v1ABPR_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // V1ABPRSEN_H_
