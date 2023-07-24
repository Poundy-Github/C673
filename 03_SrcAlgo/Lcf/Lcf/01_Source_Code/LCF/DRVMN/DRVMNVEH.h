/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULES       : DRMHOD,DRMDAE
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRVMNVEH.h
//! @brief     (DRVMN) Sub-Component Vehicle Header.

#ifndef DRVMNVEH_H_
#define DRVMNVEH_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRMHOD/DRMHOD.h"
#include "DRMDAE/DRMDAE.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DRVMN sub-component vehicle debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] DRVMN_VehDbgPtr Pointer to DRVMN vehicle debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html DRVMN_VehInitDbgPtr_callsequence.png DRVMN Debug Initialization Call Sequence
 *		@startuml "DRVMN_VehInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant DRVMN as SubCmp <<Sub-Component>>
 *			participant DRMHOD as DRMHOD <<Module>>
 *			participant DRMDAE as DRMDAE <<Module>>
 *			
 *			Task -> SubCmp: DRVMN_VehInitDbgPtr(DRVMN_VehDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> DRMHOD: DRMHOD_VehInitDbgPtr(&DRVMN_VehDbgPtr->DRMHOD_VehDbgData)
 *			activate DRMHOD
 *			DRMHOD --> SubCmp: return
 *			deactivate DRMHOD
 *			
 *			SubCmp -> DRMDAE: DRMDAE_VehInitDbgPtr(&DRVMN_VehDbgPtr->DRMDAE_VehDbgData)
 *			activate DRMDAE
 *			DRMDAE --> SubCmp: return
 *			deactivate DRMDAE
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
extern void DRVMN_VehInitDbgPtr(DRVMN_VehDbgType *DRVMN_VehDbgPtr);

/*!
 *	DRVMN sub-component vehicle output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] DRVMN_VehOutPtr Pointer to DRVMN vehicle output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html DRVMN_VehInitOutPtr_callsequence.png DRVMN Output Initialization Call Sequence
 *		@startuml "DRVMN_VehInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant DRVMN as SubCmp <<Sub-Component>>
 *			participant DRMHOD as DRMHOD <<Module>>
 *			participant DRMDAE as DRMDAE <<Module>>
 *			
 *			Task -> SubCmp: DRVMN_VehInitOutPtr(DRVMN_VehOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> DRMHOD: DRMHOD_VehInitOutPtr(&DRVMN_VehOutPtr->DRMHOD_VehOutData)
 *			activate DRMHOD
 *			DRMHOD --> SubCmp: return
 *			deactivate DRMHOD
 *			
 *			SubCmp -> DRMDAE: DRMDAE_VehInitOutPtr(&DRVMN_VehOutPtr->DRMDAE_VehOutData)
 *			activate DRMDAE
 *			DRMDAE --> SubCmp: return
 *			deactivate DRMDAE
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
extern void DRVMN_VehInitOutPtr(DRVMN_VehOutType *DRVMN_VehOutPtr);

/*!
 *	DRVMN sub-component vehicle reset function.
 *	
 *	@pre
 *		- The DRVMN vehicle initialization function(s) must be called once.
 *		- The DRVMN vehicle debug/output data pointer(s) should not be NULL.
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
 *		@image html DRVMN_VehReset_callsequence.png DRVMN Reset Call Sequence
 *		@startuml "DRVMN_VehReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant DRVMN as SubCmp <<Sub-Component>>
 *			participant DRMHOD as DRMHOD <<Module>>
 *			participant DRMDAE as DRMDAE <<Module>>
 *			
 *			Task -> SubCmp: DRVMN_VehReset()
 *			activate SubCmp
 *			
 *			SubCmp -> DRMHOD: DRMHOD_VehReset()
 *			activate DRMHOD
 *			DRMHOD --> SubCmp: return
 *			deactivate DRMHOD
 *			
 *			SubCmp -> DRMDAE: DRMDAE_VehReset()
 *			activate DRMDAE
 *			DRMDAE --> SubCmp: return
 *			deactivate DRMDAE
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
extern void DRVMN_VehReset(void);

/*!
 *	DRVMN sub-component vehicle process function.
 *	
 *	@pre
 *		- The DRVMN vehicle initialization function(s) must be called once.
 *		- The DRVMN vehicle debug/output data pointer(s) should not be NULL.
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
 *		@image html DRVMN_VehProcess_callsequence.png DRVMN Process Call Sequence
 *		@startuml "DRVMN_VehProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFVEH as Task <<Task-Algo>>
 *			participant DRVMN as SubCmp <<Sub-Component>>
 *			participant DRMHOD as DRMHOD <<Module>>
 *			participant DRMDAE as DRMDAE <<Module>>
 *			
 *			Task -> SubCmp: DRVMN_VehProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> DRMHOD: DRMHOD_VehProcess()
 *			activate DRMHOD
 *			DRMHOD --> SubCmp: return
 *			deactivate DRMHOD
 *			
 *			SubCmp -> DRMDAE: DRMDAE_VehProcess()
 *			activate DRMDAE
 *			DRMDAE --> SubCmp: return
 *			deactivate DRMDAE
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
extern void DRVMN_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DRVMNVEH_H_
