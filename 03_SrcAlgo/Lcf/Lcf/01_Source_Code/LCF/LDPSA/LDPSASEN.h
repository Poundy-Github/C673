/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULES       : DPLSIA,DPLSMI,DPLSMW,DPLTTG,DPLTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LDPSASEN.h
//! @brief     (LDPSA) Sub-Component Sensor Header.

#ifndef LDPSASEN_H_
#define LDPSASEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLSIA/DPLSIA.h"
#include "DPLSMI/DPLSMI.h"
#include "DPLSMW/DPLSMW.h"
#include "DPLTTG/DPLTTG.h"
#include "DPLTVG/DPLTVG.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LDPSA sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] LDPSA_SenDbgPtr Pointer to LDPSA sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html LDPSA_SenInitDbgPtr_callsequence.png LDPSA Debug Initialization Call Sequence
 *		@startuml "LDPSA_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant LDPSA as SubCmp <<Sub-Component>>
 *			participant DPLSIA as DPLSIA <<Module>>
 *			participant DPLSMI as DPLSMI <<Module>>
 *			participant DPLSMW as DPLSMW <<Module>>
 *			participant DPLTTG as DPLTTG <<Module>>
 *			
 *			Task -> SubCmp: LDPSA_SenInitDbgPtr(LDPSA_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> DPLSIA: DPLSIA_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLSIA_SenDbgData)
 *			activate DPLSIA
 *			DPLSIA --> SubCmp: return
 *			deactivate DPLSIA
 *			
 *			SubCmp -> DPLSMI: DPLSMI_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLSMI_SenDbgData)
 *			activate DPLSMI
 *			DPLSMI --> SubCmp: return
 *			deactivate DPLSMI
 *			
 *			SubCmp -> DPLSMW: DPLSMW_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLSMW_SenDbgData)
 *			activate DPLSMW
 *			DPLSMW --> SubCmp: return
 *			deactivate DPLSMW
 *			
 *			SubCmp -> DPLTTG: DPLTTG_SenInitDbgPtr(&LDPSA_SenDbgPtr->DPLTTG_SenDbgData)
 *			activate DPLTTG
 *			DPLTTG --> SubCmp: return
 *			deactivate DPLTTG
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
extern void LDPSA_SenInitDbgPtr(LDPSA_SenDbgType *LDPSA_SenDbgPtr);

/*!
 *	LDPSA sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] LDPSA_SenOutPtr Pointer to LDPSA sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html LDPSA_SenInitOutPtr_callsequence.png LDPSA Output Initialization Call Sequence
 *		@startuml "LDPSA_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant LDPSA as SubCmp <<Sub-Component>>
 *			participant DPLSMI as DPLSMI <<Module>>
 *			participant DPLSMW as DPLSMW <<Module>>
 *			participant DPLTTG as DPLTTG <<Module>>
 *			participant DPLTVG as DPLTVG <<Module>>
 *			
 *			Task -> SubCmp: LDPSA_SenInitOutPtr(LDPSA_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> DPLSMI: DPLSMI_SenInitOutPtr(&LDPSA_SenOutPtr->DPLSMI_SenOutData)
 *			activate DPLSMI
 *			DPLSMI --> SubCmp: return
 *			deactivate DPLSMI
 *			
 *			SubCmp -> DPLSMW: DPLSMW_SenInitOutPtr(&LDPSA_SenOutPtr->DPLSMW_SenOutData)
 *			activate DPLSMW
 *			DPLSMW --> SubCmp: return
 *			deactivate DPLSMW
 *			
 *			SubCmp -> DPLTTG: DPLTTG_SenInitOutPtr(&LDPSA_SenOutPtr->DPLTTG_SenOutData)
 *			activate DPLTTG
 *			DPLTTG --> SubCmp: return
 *			deactivate DPLTTG
 *			
 *			SubCmp -> DPLTVG: DPLTVG_SenInitOutPtr(&LDPSA_SenOutPtr->DPLTVG_SenOutData)
 *			activate DPLTVG
 *			DPLTVG --> SubCmp: return
 *			deactivate DPLTVG
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
extern void LDPSA_SenInitOutPtr(LDPSA_SenOutType *LDPSA_SenOutPtr);

/*!
 *	LDPSA sub-component sensor reset function.
 *	
 *	@pre
 *		- The LDPSA sensor initialization function(s) must be called once.
 *		- The LDPSA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html LDPSA_SenReset_callsequence.png LDPSA Reset Call Sequence
 *		@startuml "LDPSA_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant LDPSA as SubCmp <<Sub-Component>>
 *			participant DPLSIA as DPLSIA <<Module>>
 *			participant DPLSMI as DPLSMI <<Module>>
 *			participant DPLSMW as DPLSMW <<Module>>
 *			participant DPLTTG as DPLTTG <<Module>>
 *			participant DPLTVG as DPLTVG <<Module>>
 *			
 *			Task -> SubCmp: LDPSA_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> DPLSIA: DPLSIA_SenReset()
 *			activate DPLSIA
 *			DPLSIA --> SubCmp: return
 *			deactivate DPLSIA
 *			
 *			SubCmp -> DPLSMI: DPLSMI_SenReset()
 *			activate DPLSMI
 *			DPLSMI --> SubCmp: return
 *			deactivate DPLSMI
 *			
 *			SubCmp -> DPLSMW: DPLSMW_SenReset()
 *			activate DPLSMW
 *			DPLSMW --> SubCmp: return
 *			deactivate DPLSMW
 *			
 *			SubCmp -> DPLTTG: DPLTTG_SenReset()
 *			activate DPLTTG
 *			DPLTTG --> SubCmp: return
 *			deactivate DPLTTG
 *			
 *			SubCmp -> DPLTVG: DPLTVG_SenReset()
 *			activate DPLTVG
 *			DPLTVG --> SubCmp: return
 *			deactivate DPLTVG
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
extern void LDPSA_SenReset(void);

/*!
 *	LDPSA sub-component sensor process function.
 *	
 *	@pre
 *		- The LDPSA sensor initialization function(s) must be called once.
 *		- The LDPSA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html LDPSA_SenProcess_callsequence.png LDPSA Process Call Sequence
 *		@startuml "LDPSA_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant LDPSA as SubCmp <<Sub-Component>>
 *			participant DPLSIA as DPLSIA <<Module>>
 *			participant DPLSMI as DPLSMI <<Module>>
 *			participant DPLSMW as DPLSMW <<Module>>
 *			participant DPLTTG as DPLTTG <<Module>>
 *			participant DPLTVG as DPLTVG <<Module>>
 *			
 *			Task -> SubCmp: LDPSA_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> DPLSIA: DPLSIA_SenProcess()
 *			activate DPLSIA
 *			DPLSIA --> SubCmp: return
 *			deactivate DPLSIA
 *			
 *			SubCmp -> DPLSMI: DPLSMI_SenProcess()
 *			activate DPLSMI
 *			DPLSMI --> SubCmp: return
 *			deactivate DPLSMI
 *			
 *			SubCmp -> DPLSMW: DPLSMW_SenProcess()
 *			activate DPLSMW
 *			DPLSMW --> SubCmp: return
 *			deactivate DPLSMW
 *			
 *			SubCmp -> DPLTTG: DPLTTG_SenProcess()
 *			activate DPLTTG
 *			DPLTTG --> SubCmp: return
 *			deactivate DPLTTG
 *			
 *			SubCmp -> DPLTVG: DPLTVG_SenProcess()
 *			activate DPLTVG
 *			DPLTVG --> SubCmp: return
 *			deactivate DPLTVG
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
extern void LDPSA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // LDPSASEN_H_
