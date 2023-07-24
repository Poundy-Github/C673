/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULES       : TPLLCO,TPLCEN,TPLFRT,TPLTJC,TPLFBT
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TRJPLNVEH.h
//! @brief     (TRJPLN) Sub-Component Vehicle Header.

#ifndef TRJPLNVEH_H_
#define TRJPLNVEH_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLLCO/TPLLCO.h"
#include "TPLCEN/TPLCEN.h"
#include "TPLFRT/TPLFRT.h"
#include "TPLTJC/TPLTJC.h"
#include "TPLFBT/TPLFBT.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TRJPLN sub-component vehicle debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] TRJPLN_VehDbgPtr Pointer to TRJPLN vehicle debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html TRJPLN_VehInitDbgPtr_callsequence.png TRJPLN Debug Initialization Call Sequence
 *		@startuml "TRJPLN_VehInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJPLN as SubCmp <<Sub-Component>>
 *			participant TPLLCO as TPLLCO <<Module>>
 *			participant TPLCEN as TPLCEN <<Module>>
 *			participant TPLFRT as TPLFRT <<Module>>
 *			participant TPLTJC as TPLTJC <<Module>>
 *			participant TPLFBT as TPLFBT <<Module>>
 *			
 *			Task -> SubCmp: TRJPLN_VehInitDbgPtr(TRJPLN_VehDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> TPLLCO: TPLLCO_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLLCO_VehDbgData)
 *			activate TPLLCO
 *			TPLLCO --> SubCmp: return
 *			deactivate TPLLCO
 *			
 *			SubCmp -> TPLCEN: TPLCEN_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLCEN_VehDbgData)
 *			activate TPLCEN
 *			TPLCEN --> SubCmp: return
 *			deactivate TPLCEN
 *			
 *			SubCmp -> TPLFRT: TPLFRT_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLFRT_VehDbgData)
 *			activate TPLFRT
 *			TPLFRT --> SubCmp: return
 *			deactivate TPLFRT
 *			
 *			SubCmp -> TPLTJC: TPLTJC_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLTJC_VehDbgData)
 *			activate TPLTJC
 *			TPLTJC --> SubCmp: return
 *			deactivate TPLTJC
 *			
 *			SubCmp -> TPLFBT: TPLFBT_VehInitDbgPtr(&TRJPLN_VehDbgPtr->TPLFBT_VehDbgData)
 *			activate TPLFBT
 *			TPLFBT --> SubCmp: return
 *			deactivate TPLFBT
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
extern void TRJPLN_VehInitDbgPtr(TRJPLN_VehDbgType *TRJPLN_VehDbgPtr);

/*!
 *	TRJPLN sub-component vehicle output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] TRJPLN_VehOutPtr Pointer to TRJPLN vehicle output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html TRJPLN_VehInitOutPtr_callsequence.png TRJPLN Output Initialization Call Sequence
 *		@startuml "TRJPLN_VehInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJPLN as SubCmp <<Sub-Component>>
 *			participant TPLLCO as TPLLCO <<Module>>
 *			participant TPLCEN as TPLCEN <<Module>>
 *			participant TPLFRT as TPLFRT <<Module>>
 *			participant TPLFBT as TPLFBT <<Module>>
 *			
 *			Task -> SubCmp: TRJPLN_VehInitOutPtr(TRJPLN_VehOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> TPLLCO: TPLLCO_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLLCO_VehOutData)
 *			activate TPLLCO
 *			TPLLCO --> SubCmp: return
 *			deactivate TPLLCO
 *			
 *			SubCmp -> TPLCEN: TPLCEN_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLCEN_VehOutData)
 *			activate TPLCEN
 *			TPLCEN --> SubCmp: return
 *			deactivate TPLCEN
 *			
 *			SubCmp -> TPLFRT: TPLFRT_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLFRT_VehOutData)
 *			activate TPLFRT
 *			TPLFRT --> SubCmp: return
 *			deactivate TPLFRT
 *			
 *			SubCmp -> TPLFBT: TPLFBT_VehInitOutPtr(&TRJPLN_VehOutPtr->TPLFBT_VehOutData)
 *			activate TPLFBT
 *			TPLFBT --> SubCmp: return
 *			deactivate TPLFBT
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
extern void TRJPLN_VehInitOutPtr(TRJPLN_VehOutType *TRJPLN_VehOutPtr);

/*!
 *	TRJPLN sub-component vehicle reset function.
 *	
 *	@pre
 *		- The TRJPLN vehicle initialization function(s) must be called once.
 *		- The TRJPLN vehicle debug/output data pointer(s) should not be NULL.
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
 *		@image html TRJPLN_VehReset_callsequence.png TRJPLN Reset Call Sequence
 *		@startuml "TRJPLN_VehReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJPLN as SubCmp <<Sub-Component>>
 *			participant TPLLCO as TPLLCO <<Module>>
 *			participant TPLCEN as TPLCEN <<Module>>
 *			participant TPLFRT as TPLFRT <<Module>>
 *			participant TPLTJC as TPLTJC <<Module>>
 *			participant TPLFBT as TPLFBT <<Module>>
 *			
 *			Task -> SubCmp: TRJPLN_VehReset()
 *			activate SubCmp
 *			
 *			SubCmp -> TPLLCO: TPLLCO_VehReset()
 *			activate TPLLCO
 *			TPLLCO --> SubCmp: return
 *			deactivate TPLLCO
 *			
 *			SubCmp -> TPLCEN: TPLCEN_VehReset()
 *			activate TPLCEN
 *			TPLCEN --> SubCmp: return
 *			deactivate TPLCEN
 *			
 *			SubCmp -> TPLFRT: TPLFRT_VehReset()
 *			activate TPLFRT
 *			TPLFRT --> SubCmp: return
 *			deactivate TPLFRT
 *			
 *			SubCmp -> TPLTJC: TPLTJC_VehReset()
 *			activate TPLTJC
 *			TPLTJC --> SubCmp: return
 *			deactivate TPLTJC
 *			
 *			SubCmp -> TPLFBT: TPLFBT_VehReset()
 *			activate TPLFBT
 *			TPLFBT --> SubCmp: return
 *			deactivate TPLFBT
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
extern void TRJPLN_VehReset(void);

/*!
 *	TRJPLN sub-component vehicle process function.
 *	
 *	@pre
 *		- The TRJPLN vehicle initialization function(s) must be called once.
 *		- The TRJPLN vehicle debug/output data pointer(s) should not be NULL.
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
 *		@image html TRJPLN_VehProcess_callsequence.png TRJPLN Process Call Sequence
 *		@startuml "TRJPLN_VehProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant TRJPLN as SubCmp <<Sub-Component>>
 *			participant TPLLCO as TPLLCO <<Module>>
 *			participant TPLCEN as TPLCEN <<Module>>
 *			participant TPLFRT as TPLFRT <<Module>>
 *			participant TPLTJC as TPLTJC <<Module>>
 *			participant TPLFBT as TPLFBT <<Module>>
 *			
 *			Task -> SubCmp: TRJPLN_VehProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> TPLLCO: TPLLCO_VehProcess()
 *			activate TPLLCO
 *			TPLLCO --> SubCmp: return
 *			deactivate TPLLCO
 *			
 *			SubCmp -> TPLCEN: TPLCEN_VehProcess()
 *			activate TPLCEN
 *			TPLCEN --> SubCmp: return
 *			deactivate TPLCEN
 *			
 *			SubCmp -> TPLFRT: TPLFRT_VehProcess()
 *			activate TPLFRT
 *			TPLFRT --> SubCmp: return
 *			deactivate TPLFRT
 *			
 *			SubCmp -> TPLTJC: TPLTJC_VehProcess()
 *			activate TPLTJC
 *			TPLTJC --> SubCmp: return
 *			deactivate TPLTJC
 *			
 *			SubCmp -> TPLFBT: TPLFBT_VehProcess()
 *			activate TPLFBT
 *			TPLFBT --> SubCmp: return
 *			deactivate TPLFBT
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
extern void TRJPLN_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TRJPLNVEH_H_
