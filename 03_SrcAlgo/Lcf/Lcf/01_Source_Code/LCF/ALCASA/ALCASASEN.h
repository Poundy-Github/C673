/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULES       : LCRSIA,LCRSMI,LCRTTG,LCRTVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ALCASASEN.h
//! @brief     (ALCASA) Sub-Component Sensor Header.

#ifndef ALCASASEN_H_
#define ALCASASEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCRSIA/LCRSIA.h"
#include "LCRSMI/LCRSMI.h"
#include "LCRTTG/LCRTTG.h"
#include "LCRTVG/LCRTVG.h"
#include "ALCASASEN_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	ALCASA sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] ALCASA_SenDbgPtr Pointer to ALCASA sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html ALCASA_SenInitDbgPtr_callsequence.png ALCASA Debug Initialization Call Sequence
 *		@startuml "ALCASA_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant ALCASA as SubCmp <<Sub-Component>>
 *			participant LCRSIA as LCRSIA <<Module>>
 *			participant LCRSMI as LCRSMI <<Module>>
 *			participant LCRTTG as LCRTTG <<Module>>
 *			participant LCRTVG as LCRTVG <<Module>>
 *			
 *			Task -> SubCmp: ALCASA_SenInitDbgPtr(ALCASA_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> LCRSIA: LCRSIA_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRSIA_SenDbgData)
 *			activate LCRSIA
 *			LCRSIA --> SubCmp: return
 *			deactivate LCRSIA
 *			
 *			SubCmp -> LCRSMI: LCRSMI_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRSMI_SenDbgData)
 *			activate LCRSMI
 *			LCRSMI --> SubCmp: return
 *			deactivate LCRSMI
 *			
 *			SubCmp -> LCRTTG: LCRTTG_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRTTG_SenDbgData)
 *			activate LCRTTG
 *			LCRTTG --> SubCmp: return
 *			deactivate LCRTTG
 *			
 *			SubCmp -> LCRTVG: LCRTVG_SenInitDbgPtr(&ALCASA_SenDbgPtr->LCRTVG_SenDbgData)
 *			activate LCRTVG
 *			LCRTVG --> SubCmp: return
 *			deactivate LCRTVG
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
extern void ALCASA_SenInitDbgPtr(ALCASA_SenDbgType *ALCASA_SenDbgPtr);

/*!
 *	ALCASA sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] ALCASA_SenOutPtr Pointer to ALCASA sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html ALCASA_SenInitOutPtr_callsequence.png ALCASA Output Initialization Call Sequence
 *		@startuml "ALCASA_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant ALCASA as SubCmp <<Sub-Component>>
 *			participant LCRSIA as LCRSIA <<Module>>
 *			participant LCRSMI as LCRSMI <<Module>>
 *			participant LCRTVG as LCRTVG <<Module>>
 *			
 *			Task -> SubCmp: ALCASA_SenInitOutPtr(ALCASA_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> LCRSIA: LCRSIA_SenInitOutPtr(&ALCASA_SenOutPtr->LCRSIA_SenOutData)
 *			activate LCRSIA
 *			LCRSIA --> SubCmp: return
 *			deactivate LCRSIA
 *			
 *			SubCmp -> LCRSMI: LCRSMI_SenInitOutPtr(&ALCASA_SenOutPtr->LCRSMI_SenOutData)
 *			activate LCRSMI
 *			LCRSMI --> SubCmp: return
 *			deactivate LCRSMI
 *			
 *			SubCmp -> LCRTVG: LCRTVG_SenInitOutPtr(&ALCASA_SenOutPtr->LCRTVG_SenOutData)
 *			activate LCRTVG
 *			LCRTVG --> SubCmp: return
 *			deactivate LCRTVG
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
extern void ALCASA_SenInitOutPtr(ALCASA_SenOutType *ALCASA_SenOutPtr);

/*!
 *	ALCASA sub-component sensor reset function.
 *	
 *	@pre
 *		- The ALCASA sensor initialization function(s) must be called once.
 *		- The ALCASA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html ALCASA_SenReset_callsequence.png ALCASA Reset Call Sequence
 *		@startuml "ALCASA_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant ALCASA as SubCmp <<Sub-Component>>
 *			participant LCRSIA as LCRSIA <<Module>>
 *			participant LCRSMI as LCRSMI <<Module>>
 *			participant LCRTTG as LCRTTG <<Module>>
 *			participant LCRTVG as LCRTVG <<Module>>
 *			
 *			Task -> SubCmp: ALCASA_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> LCRSIA: LCRSIA_SenReset()
 *			activate LCRSIA
 *			LCRSIA --> SubCmp: return
 *			deactivate LCRSIA
 *			
 *			SubCmp -> LCRSMI: LCRSMI_SenReset()
 *			activate LCRSMI
 *			LCRSMI --> SubCmp: return
 *			deactivate LCRSMI
 *			
 *			SubCmp -> LCRTTG: LCRTTG_SenReset()
 *			activate LCRTTG
 *			LCRTTG --> SubCmp: return
 *			deactivate LCRTTG
 *			
 *			SubCmp -> LCRTVG: LCRTVG_SenReset()
 *			activate LCRTVG
 *			LCRTVG --> SubCmp: return
 *			deactivate LCRTVG
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
extern void ALCASA_SenReset(void);

/*!
 *	ALCASA sub-component sensor process function.
 *	
 *	@pre
 *		- The ALCASA sensor initialization function(s) must be called once.
 *		- The ALCASA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html ALCASA_SenProcess_callsequence.png ALCASA Process Call Sequence
 *		@startuml "ALCASA_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant ALCASA as SubCmp <<Sub-Component>>
 *			participant LCRSIA as LCRSIA <<Module>>
 *			participant LCRSMI as LCRSMI <<Module>>
 *			participant LCRTTG as LCRTTG <<Module>>
 *			participant LCRTVG as LCRTVG <<Module>>
 *			
 *			Task -> SubCmp: ALCASA_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> LCRSIA: LCRSIA_SenProcess()
 *			activate LCRSIA
 *			LCRSIA --> SubCmp: return
 *			deactivate LCRSIA
 *			
 *			SubCmp -> LCRSMI: LCRSMI_SenProcess()
 *			activate LCRSMI
 *			LCRSMI --> SubCmp: return
 *			deactivate LCRSMI
 *			
 *			SubCmp -> LCRTTG: LCRTTG_SenProcess()
 *			activate LCRTTG
 *			LCRTTG --> SubCmp: return
 *			deactivate LCRTTG
 *			
 *			SubCmp -> LCRTVG: LCRTVG_SenProcess()
 *			activate LCRTVG
 *			LCRTVG --> SubCmp: return
 *			deactivate LCRTVG
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
extern void ALCASA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // ALCASASEN_H_
