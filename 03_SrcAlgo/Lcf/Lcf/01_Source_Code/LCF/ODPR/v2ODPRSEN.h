/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v2ODPR
  MODULES       : ODPFOP,ODPFOH
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:22:08CEST $
  $Log: v2ODPRSEN.h  $
  Revision 1.1.1.2 2020/04/09 14:22:08CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.1.1.1 2019/11/29 09:02:00CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     v2ODPRSEN.h
//! @brief     (v2ODPR) Sub-Component Sensor Header.

#ifndef V2ODPRSEN_H_
#define V2ODPRSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ODPFOP/ODPFOP.h"
#include "ODPFOH/ODPFOH.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	v2ODPR sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] v2ODPR_SenDbgPtr Pointer to v2ODPR sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html v2ODPR_SenInitDbgPtr_callsequence.png v2ODPR Debug Initialization Call Sequence
 *		@startuml "v2ODPR_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v2ODPR as SubCmp <<Sub-Component>>
 *			participant ODPFOP as ODPFOP <<Module>>
 *			participant ODPFOH as ODPFOH <<Module>>
 *			
 *			Task -> SubCmp: v2ODPR_SenInitDbgPtr(v2ODPR_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> ODPFOP: ODPFOP_SenInitDbgPtr(&v2ODPR_SenDbgPtr->ODPFOP_SenDbgData)
 *			activate ODPFOP
 *			ODPFOP --> SubCmp: return
 *			deactivate ODPFOP
 *			
 *			SubCmp -> ODPFOH: ODPFOH_SenInitDbgPtr(&v2ODPR_SenDbgPtr->ODPFOH_SenDbgData)
 *			activate ODPFOH
 *			ODPFOH --> SubCmp: return
 *			deactivate ODPFOH
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
extern void v2ODPR_SenInitDbgPtr(v2ODPR_SenDbgType *v2ODPR_SenDbgPtr);

/*!
 *	v2ODPR sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] v2ODPR_SenOutPtr Pointer to v2ODPR sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html v2ODPR_SenInitOutPtr_callsequence.png v2ODPR Output Initialization Call Sequence
 *		@startuml "v2ODPR_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v2ODPR as SubCmp <<Sub-Component>>
 *			participant ODPFOH as ODPFOH <<Module>>
 *			
 *			Task -> SubCmp: v2ODPR_SenInitOutPtr(v2ODPR_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> ODPFOH: ODPFOH_SenInitOutPtr(&v2ODPR_SenOutPtr->ODPFOH_SenOutData)
 *			activate ODPFOH
 *			ODPFOH --> SubCmp: return
 *			deactivate ODPFOH
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
#define v2ODPR_SenInitOutPtr(v2ODPR_SenOutPtr) ODPFOH_SenInitOutPtr(&(v2ODPR_SenOutPtr)->ODPFOH_SenOutData) //ElNa, ODPFOH was used instead of ODPOOP
//extern void ODPR_SenInitOutPtr(ODPR_SenOutType *ODPR_SenOutPtr);

/*!
 *	v2ODPR sub-component sensor reset function.
 *	
 *	@pre
 *		- The v2ODPR sensor initialization function(s) must be called once.
 *		- The v2ODPR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html v2ODPR_SenReset_callsequence.png v2ODPR Reset Call Sequence
 *		@startuml "v2ODPR_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v2ODPR as SubCmp <<Sub-Component>>
 *			participant ODPFOP as ODPFOP <<Module>>
 *			participant ODPFOH as ODPFOH <<Module>>
 *			
 *			Task -> SubCmp: v2ODPR_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> ODPFOP: ODPFOP_SenReset()
 *			activate ODPFOP
 *			ODPFOP --> SubCmp: return
 *			deactivate ODPFOP
 *			
 *			SubCmp -> ODPFOH: ODPFOH_SenReset()
 *			activate ODPFOH
 *			ODPFOH --> SubCmp: return
 *			deactivate ODPFOH
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
extern void v2ODPR_SenReset(void);

/*!
 *	v2ODPR sub-component sensor process function.
 *	
 *	@pre
 *		- The v2ODPR sensor initialization function(s) must be called once.
 *		- The v2ODPR sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html v2ODPR_SenProcess_callsequence.png v2ODPR Process Call Sequence
 *		@startuml "v2ODPR_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v2ODPR as SubCmp <<Sub-Component>>
 *			participant ODPFOP as ODPFOP <<Module>>
 *			participant ODPFOH as ODPFOH <<Module>>
 *			
 *			Task -> SubCmp: v2ODPR_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> ODPFOP: ODPFOP_SenProcess()
 *			activate ODPFOP
 *			ODPFOP --> SubCmp: return
 *			deactivate ODPFOP
 *			
 *			SubCmp -> ODPFOH: ODPFOH_SenProcess()
 *			activate ODPFOH
 *			ODPFOH --> SubCmp: return
 *			deactivate ODPFOH
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
extern void v2ODPR_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* V2ODPRSEN_H_*/
