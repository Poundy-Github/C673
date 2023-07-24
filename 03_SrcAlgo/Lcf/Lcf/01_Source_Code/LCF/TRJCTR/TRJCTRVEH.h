/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULES       : TCTEST,TCTDTE,TCTCDC,TCTFFC,TCTLGC,TCTCLM
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TRJCTRVEH.h
//! @brief     (TRJCTR) Sub-Component Vehicle Header.

#ifndef TRJCTRVEH_H_
#define TRJCTRVEH_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTEST/TCTEST.h"
#include "TCTDTE/TCTDTE.h"
#include "TCTCDC/TCTCDC.h"
#include "TCTFFC/TCTFFC.h"
#include "TCTLGC/TCTLGC.h"
#include "TCTCLM/TCTCLM.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TRJCTR sub-component vehicle debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] TRJCTR_VehDbgPtr Pointer to TRJCTR vehicle debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html TRJCTR_VehInitDbgPtr_callsequence.png TRJCTR Debug Initialization Call Sequence
 *		@startuml "TRJCTR_VehInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJCTR as SubCmp <<Sub-Component>>
 *			participant TCTEST as TCTEST <<Module>>
 *			participant TCTDTE as TCTDTE <<Module>>
 *			participant TCTCDC as TCTCDC <<Module>>
 *			participant TCTFFC as TCTFFC <<Module>>
 *			participant TCTLGC as TCTLGC <<Module>>
 *			participant TCTCLM as TCTCLM <<Module>>
 *			
 *			Task -> SubCmp: TRJCTR_VehInitDbgPtr(TRJCTR_VehDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> TCTEST: TCTEST_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTEST_VehDbgData)
 *			activate TCTEST
 *			TCTEST --> SubCmp: return
 *			deactivate TCTEST
 *			
 *			SubCmp -> TCTDTE: TCTDTE_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTDTE_VehDbgData)
 *			activate TCTDTE
 *			TCTDTE --> SubCmp: return
 *			deactivate TCTDTE
 *			
 *			SubCmp -> TCTCDC: TCTCDC_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTCDC_VehDbgData)
 *			activate TCTCDC
 *			TCTCDC --> SubCmp: return
 *			deactivate TCTCDC
 *			
 *			SubCmp -> TCTFFC: TCTFFC_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTFFC_VehDbgData)
 *			activate TCTFFC
 *			TCTFFC --> SubCmp: return
 *			deactivate TCTFFC
 *			
 *			SubCmp -> TCTLGC: TCTLGC_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTLGC_VehDbgData)
 *			activate TCTLGC
 *			TCTLGC --> SubCmp: return
 *			deactivate TCTLGC
 *			
 *			SubCmp -> TCTCLM: TCTCLM_VehInitDbgPtr(&TRJCTR_VehDbgPtr->TCTCLM_VehDbgData)
 *			activate TCTCLM
 *			TCTCLM --> SubCmp: return
 *			deactivate TCTCLM
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
extern void TRJCTR_VehInitDbgPtr(TRJCTR_VehDbgType *TRJCTR_VehDbgPtr);

/*!
 *	TRJCTR sub-component vehicle output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] TRJCTR_VehOutPtr Pointer to TRJCTR vehicle output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html TRJCTR_VehInitOutPtr_callsequence.png TRJCTR Output Initialization Call Sequence
 *		@startuml "TRJCTR_VehInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJCTR as SubCmp <<Sub-Component>>
 *			participant TCTLGC as TCTLGC <<Module>>
 *			
 *			Task -> SubCmp: TRJCTR_VehInitOutPtr(TRJCTR_VehOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> TCTLGC: TCTLGC_VehInitOutPtr(&TRJCTR_VehOutPtr->TCTLGC_VehOutData)
 *			activate TCTLGC
 *			TCTLGC --> SubCmp: return
 *			deactivate TCTLGC
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
#define TRJCTR_VehInitOutPtr(TRJCTR_VehOutPtr) TCTLGC_VehInitOutPtr(&(TRJCTR_VehOutPtr)->TCTLGC_VehOutData)

/*!
 *	TRJCTR sub-component vehicle reset function.
 *	
 *	@pre
 *		- The TRJCTR vehicle initialization function(s) must be called once.
 *		- The TRJCTR vehicle debug/output data pointer(s) should not be NULL.
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
 *		@image html TRJCTR_VehReset_callsequence.png TRJCTR Reset Call Sequence
 *		@startuml "TRJCTR_VehReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJCTR as SubCmp <<Sub-Component>>
 *			participant TCTEST as TCTEST <<Module>>
 *			participant TCTDTE as TCTDTE <<Module>>
 *			participant TCTCDC as TCTCDC <<Module>>
 *			participant TCTFFC as TCTFFC <<Module>>
 *			participant TCTLGC as TCTLGC <<Module>>
 *			participant TCTCLM as TCTCLM <<Module>>
 *			
 *			Task -> SubCmp: TRJCTR_VehReset()
 *			activate SubCmp
 *			
 *			SubCmp -> TCTEST: TCTEST_VehReset()
 *			activate TCTEST
 *			TCTEST --> SubCmp: return
 *			deactivate TCTEST
 *			
 *			SubCmp -> TCTDTE: TCTDTE_VehReset()
 *			activate TCTDTE
 *			TCTDTE --> SubCmp: return
 *			deactivate TCTDTE
 *			
 *			SubCmp -> TCTCDC: TCTCDC_VehReset()
 *			activate TCTCDC
 *			TCTCDC --> SubCmp: return
 *			deactivate TCTCDC
 *			
 *			SubCmp -> TCTFFC: TCTFFC_VehReset()
 *			activate TCTFFC
 *			TCTFFC --> SubCmp: return
 *			deactivate TCTFFC
 *			
 *			SubCmp -> TCTLGC: TCTLGC_VehReset()
 *			activate TCTLGC
 *			TCTLGC --> SubCmp: return
 *			deactivate TCTLGC
 *			
 *			SubCmp -> TCTCLM: TCTCLM_VehReset()
 *			activate TCTCLM
 *			TCTCLM --> SubCmp: return
 *			deactivate TCTCLM
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
extern void TRJCTR_VehReset(void);

/*!
 *	TRJCTR sub-component vehicle process function.
 *	
 *	@pre
 *		- The TRJCTR vehicle initialization function(s) must be called once.
 *		- The TRJCTR vehicle debug/output data pointer(s) should not be NULL.
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
 *		@image html TRJCTR_VehProcess_callsequence.png TRJCTR Process Call Sequence
 *		@startuml "TRJCTR_VehProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJCTR as SubCmp <<Sub-Component>>
 *			participant TCTEST as TCTEST <<Module>>
 *			participant TCTDTE as TCTDTE <<Module>>
 *			participant TCTCDC as TCTCDC <<Module>>
 *			participant TCTFFC as TCTFFC <<Module>>
 *			participant TCTLGC as TCTLGC <<Module>>
 *			participant TCTCLM as TCTCLM <<Module>>
 *			
 *			Task -> SubCmp: TRJCTR_VehProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> TCTEST: TCTEST_VehProcess()
 *			activate TCTEST
 *			TCTEST --> SubCmp: return
 *			deactivate TCTEST
 *			
 *			SubCmp -> TCTDTE: TCTDTE_VehProcess()
 *			activate TCTDTE
 *			TCTDTE --> SubCmp: return
 *			deactivate TCTDTE
 *			
 *			SubCmp -> TCTCDC: TCTCDC_VehProcess()
 *			activate TCTCDC
 *			TCTCDC --> SubCmp: return
 *			deactivate TCTCDC
 *			
 *			SubCmp -> TCTFFC: TCTFFC_VehProcess()
 *			activate TCTFFC
 *			TCTFFC --> SubCmp: return
 *			deactivate TCTFFC
 *			
 *			SubCmp -> TCTLGC: TCTLGC_VehProcess()
 *			activate TCTLGC
 *			TCTLGC --> SubCmp: return
 *			deactivate TCTLGC
 *			
 *			SubCmp -> TCTCLM: TCTCLM_VehProcess()
 *			activate TCTCLM
 *			TCTCLM --> SubCmp: return
 *			deactivate TCTCLM
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
extern void TRJCTR_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TRJCTRVEH_H_
