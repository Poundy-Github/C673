/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULES       : DPRSIA,DPRSMI,DPRSMW,DPRTTG,DPRTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     RDPSASEN.h
//! @brief     (RDPSA) Sub-Component Sensor Header.

#ifndef RDPSASEN_H_
#define RDPSASEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRSIA/DPRSIA.h"
#include "DPRSMI/DPRSMI.h"
#include "DPRSMW/DPRSMW.h"
#include "DPRTTG/DPRTTG.h"
#include "DPRTVG/DPRTVG.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	RDPSA sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] RDPSA_SenDbgPtr Pointer to RDPSA sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html RDPSA_SenInitDbgPtr_callsequence.png RDPSA Debug Initialization Call Sequence
 *		@startuml "RDPSA_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant RDPSA as SubCmp <<Sub-Component>>
 *			participant DPRSIA as DPRSIA <<Module>>
 *			participant DPRSMI as DPRSMI <<Module>>
 *			participant DPRSMW as DPRSMW <<Module>>
 *			participant DPRTTG as DPRTTG <<Module>>
 *			
 *			Task -> SubCmp: RDPSA_SenInitDbgPtr(RDPSA_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> DPRSIA: DPRSIA_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRSIA_SenDbgData)
 *			activate DPRSIA
 *			DPRSIA --> SubCmp: return
 *			deactivate DPRSIA
 *			
 *			SubCmp -> DPRSMI: DPRSMI_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRSMI_SenDbgData)
 *			activate DPRSMI
 *			DPRSMI --> SubCmp: return
 *			deactivate DPRSMI
 *			
 *			SubCmp -> DPRSMW: DPRSMW_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRSMW_SenDbgData)
 *			activate DPRSMW
 *			DPRSMW --> SubCmp: return
 *			deactivate DPRSMW
 *			
 *			SubCmp -> DPRTTG: DPRTTG_SenInitDbgPtr(&RDPSA_SenDbgPtr->DPRTTG_SenDbgData)
 *			activate DPRTTG
 *			DPRTTG --> SubCmp: return
 *			deactivate DPRTTG
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
extern void RDPSA_SenInitDbgPtr(RDPSA_SenDbgType *RDPSA_SenDbgPtr);

/*!
 *	RDPSA sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] RDPSA_SenOutPtr Pointer to RDPSA sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html RDPSA_SenInitOutPtr_callsequence.png RDPSA Output Initialization Call Sequence
 *		@startuml "RDPSA_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant RDPSA as SubCmp <<Sub-Component>>
 *			participant DPRSMI as DPRSMI <<Module>>
 *			participant DPRSMW as DPRSMW <<Module>>
 *			participant DPRTTG as DPRTTG <<Module>>
 *			participant DPRTVG as DPRTVG <<Module>>
 *			
 *			Task -> SubCmp: RDPSA_SenInitOutPtr(RDPSA_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> DPRSMI: DPRSMI_SenInitOutPtr(&RDPSA_SenOutPtr->DPRSMI_SenOutData)
 *			activate DPRSMI
 *			DPRSMI --> SubCmp: return
 *			deactivate DPRSMI
 *			
 *			SubCmp -> DPRSMW: DPRSMW_SenInitOutPtr(&RDPSA_SenOutPtr->DPRSMW_SenOutData)
 *			activate DPRSMW
 *			DPRSMW --> SubCmp: return
 *			deactivate DPRSMW
 *			
 *			SubCmp -> DPRTTG: DPRTTG_SenInitOutPtr(&RDPSA_SenOutPtr->DPRTTG_SenOutData)
 *			activate DPRTTG
 *			DPRTTG --> SubCmp: return
 *			deactivate DPRTTG
 *			
 *			SubCmp -> DPRTVG: DPRTVG_SenInitOutPtr(&RDPSA_SenOutPtr->DPRTVG_SenOutData)
 *			activate DPRTVG
 *			DPRTVG --> SubCmp: return
 *			deactivate DPRTVG
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
extern void RDPSA_SenInitOutPtr(RDPSA_SenOutType *RDPSA_SenOutPtr);

/*!
 *	RDPSA sub-component sensor reset function.
 *	
 *	@pre
 *		- The RDPSA sensor initialization function(s) must be called once.
 *		- The RDPSA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html RDPSA_SenReset_callsequence.png RDPSA Reset Call Sequence
 *		@startuml "RDPSA_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant RDPSA as SubCmp <<Sub-Component>>
 *			participant DPRSIA as DPRSIA <<Module>>
 *			participant DPRSMI as DPRSMI <<Module>>
 *			participant DPRSMW as DPRSMW <<Module>>
 *			participant DPRTTG as DPRTTG <<Module>>
 *			participant DPRTVG as DPRTVG <<Module>>
 *			
 *			Task -> SubCmp: RDPSA_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> DPRSIA: DPRSIA_SenReset()
 *			activate DPRSIA
 *			DPRSIA --> SubCmp: return
 *			deactivate DPRSIA
 *			
 *			SubCmp -> DPRSMI: DPRSMI_SenReset()
 *			activate DPRSMI
 *			DPRSMI --> SubCmp: return
 *			deactivate DPRSMI
 *			
 *			SubCmp -> DPRSMW: DPRSMW_SenReset()
 *			activate DPRSMW
 *			DPRSMW --> SubCmp: return
 *			deactivate DPRSMW
 *			
 *			SubCmp -> DPRTTG: DPRTTG_SenReset()
 *			activate DPRTTG
 *			DPRTTG --> SubCmp: return
 *			deactivate DPRTTG
 *			
 *			SubCmp -> DPRTVG: DPRTVG_SenReset()
 *			activate DPRTVG
 *			DPRTVG --> SubCmp: return
 *			deactivate DPRTVG
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
extern void RDPSA_SenReset(void);

/*!
 *	RDPSA sub-component sensor process function.
 *	
 *	@pre
 *		- The RDPSA sensor initialization function(s) must be called once.
 *		- The RDPSA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html RDPSA_SenProcess_callsequence.png RDPSA Process Call Sequence
 *		@startuml "RDPSA_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant RDPSA as SubCmp <<Sub-Component>>
 *			participant DPRSIA as DPRSIA <<Module>>
 *			participant DPRSMI as DPRSMI <<Module>>
 *			participant DPRSMW as DPRSMW <<Module>>
 *			participant DPRTTG as DPRTTG <<Module>>
 *			participant DPRTVG as DPRTVG <<Module>>
 *			
 *			Task -> SubCmp: RDPSA_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> DPRSIA: DPRSIA_SenProcess()
 *			activate DPRSIA
 *			DPRSIA --> SubCmp: return
 *			deactivate DPRSIA
 *			
 *			SubCmp -> DPRSMI: DPRSMI_SenProcess()
 *			activate DPRSMI
 *			DPRSMI --> SubCmp: return
 *			deactivate DPRSMI
 *			
 *			SubCmp -> DPRSMW: DPRSMW_SenProcess()
 *			activate DPRSMW
 *			DPRSMW --> SubCmp: return
 *			deactivate DPRSMW
 *			
 *			SubCmp -> DPRTTG: DPRTTG_SenProcess()
 *			activate DPRTTG
 *			DPRTTG --> SubCmp: return
 *			deactivate DPRTTG
 *			
 *			SubCmp -> DPRTVG: DPRTVG_SenProcess()
 *			activate DPRTVG
 *			DPRTVG --> SubCmp: return
 *			deactivate DPRTVG
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
extern void RDPSA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // RDPSASEN_H_
