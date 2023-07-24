/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Vehicle
  SUB-COMPONENTS : DRVMN,TRJPLN,TRJCTR,LATDMC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFVEH.h
//! @brief    Lateral Control Functions - Vehicle (LCFVEH) Task Header.

#ifndef LCFVEH_H_
#define LCFVEH_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRVMN/DRVMNVEH.h"
#include "TRJPLN/TRJPLNVEH.h"
#include "TRJCTR/TRJCTRVEH.h"
#include "LATDMC/LATDMCVEH.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCFVEH task debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] LCF_VehDbgArg Pointer to LCFVEH debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html DPU_LCF_VehInitDbgPtr_callsequence.png LCFVEH Debug Initialization Call Sequence
 *		@startuml "DPU_LCF_VehInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFVEH as TaskFrame <<Task-Frame>>
 *			participant LCFVEH as TaskAlgo <<Task-Algo>>
 *			participant DRVMN as DRVMN <<Sub-Component>>
 *			participant TRJPLN as TRJPLN <<Sub-Component>>
 *			participant TRJCTR as TRJCTR <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_VehInitDbgPtr(LCF_VehDbgArg)
 *			activate TaskAlgo
 *			
 *			TaskAlgo -> DRVMN: DRVMN_VehInitDbgPtr(&LCF_VehDbgArg->DRVMN_VehDbgData)
 *			activate DRVMN
 *			DRVMN --> TaskAlgo: return
 *			deactivate DRVMN
 *			
 *			TaskAlgo -> TRJPLN: TRJPLN_VehInitDbgPtr(&LCF_VehDbgArg->TRJPLN_VehDbgData)
 *			activate TRJPLN
 *			TRJPLN --> TaskAlgo: return
 *			deactivate TRJPLN
 *			
 *			TaskAlgo -> TRJCTR: TRJCTR_VehInitDbgPtr(&LCF_VehDbgArg->TRJCTR_VehDbgData)
 *			activate TRJCTR
 *			TRJCTR --> TaskAlgo: return
 *			deactivate TRJCTR
 *			
 *			TaskAlgo --> TaskFrame: return
 *			deactivate TaskAlgo
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void LCF_VehInitDbgPtr(LCF_VehDbgType *LCF_VehDbgArg);

/*!
 *	LCFVEH task output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] LCF_VehOutPtr Pointer to LCFVEH output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html DPU_LCF_VehInitOutPtr_callsequence.png LCFVEH Output Initialization Call Sequence
 *		@startuml "DPU_LCF_VehInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFVEH as TaskFrame <<Task-Frame>>
 *			participant LCFVEH as TaskAlgo <<Task-Algo>>
 *			participant DRVMN as DRVMN <<Sub-Component>>
 *			participant TRJPLN as TRJPLN <<Sub-Component>>
 *			participant TRJCTR as TRJCTR <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_VehInitOutPtr(LCF_VehOutPtr)
 *			activate TaskAlgo
 *			
 *			TaskAlgo -> DRVMN: DRVMN_VehInitOutPtr(&LCF_VehOutPtr->DRVMN_VehOutData)
 *			activate DRVMN
 *			DRVMN --> TaskAlgo: return
 *			deactivate DRVMN
 *			
 *			TaskAlgo -> TRJPLN: TRJPLN_VehInitOutPtr(&LCF_VehOutPtr->TRJPLN_VehOutData)
 *			activate TRJPLN
 *			TRJPLN --> TaskAlgo: return
 *			deactivate TRJPLN
 *			
 *			TaskAlgo -> TRJCTR: TRJCTR_VehInitOutPtr(&LCF_VehOutPtr->TRJCTR_VehOutData)
 *			activate TRJCTR
 *			TRJCTR --> TaskAlgo: return
 *			deactivate TRJCTR
 *			
 *			TaskAlgo --> TaskFrame: return
 *			deactivate TaskAlgo
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void LCF_VehInitOutPtr(LCF_VehOutType *LCF_VehOutPtr);

/*!
 *	LCFVEH task reset function.
 *	
 *	@pre
 *		- The LCFVEH initialization function(s) must be called once.
 *		- The LCFVEH debug/output data pointer(s) should not be NULL.
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
 *		@image html DPU_LCF_VehReset_callsequence.png LCFVEH Reset Call Sequence
 *		@startuml "DPU_LCF_VehReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFVEH as TaskFrame <<Task-Frame>>
 *			participant LCFVEH as TaskAlgo <<Task-Algo>>
 *			participant DRVMN as DRVMN <<Sub-Component>>
 *			participant TRJPLN as TRJPLN <<Sub-Component>>
 *			participant TRJCTR as TRJCTR <<Sub-Component>>
 *			participant LATDMC as LATDMC <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_VehReset()
 *			activate TaskAlgo
 *			
 *			TaskAlgo -> DRVMN: DRVMN_VehReset()
 *			activate DRVMN
 *			DRVMN --> TaskAlgo: return
 *			deactivate DRVMN
 *			
 *			TaskAlgo -> TRJPLN: TRJPLN_VehReset()
 *			activate TRJPLN
 *			TRJPLN --> TaskAlgo: return
 *			deactivate TRJPLN
 *			
 *			TaskAlgo -> TRJCTR: TRJCTR_VehReset()
 *			activate TRJCTR
 *			TRJCTR --> TaskAlgo: return
 *			deactivate TRJCTR
 *			
 *			TaskAlgo -> LATDMC: LATDMC_VehReset()
 *			activate LATDMC
 *			LATDMC --> TaskAlgo: return
 *			deactivate LATDMC
 *			
 *			TaskAlgo --> TaskFrame: return
 *			deactivate TaskAlgo
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void LCF_VehReset(void);

/*!
 *	LCFVEH task process function.
 *	
 *	@pre
 *		- The LCFVEH initialization function(s) must be called once.
 *		- The LCFVEH debug/output data pointer(s) should not be NULL.
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
 *		@image html DPU_LCF_VehProcess_callsequence.png LCFVEH Process Call Sequence
 *		@startuml "DPU_LCF_VehProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFVEH as TaskFrame <<Task-Frame>>
 *			participant LCFVEH as TaskAlgo <<Task-Algo>>
 *			participant DRVMN as DRVMN <<Sub-Component>>
 *			participant TRJPLN as TRJPLN <<Sub-Component>>
 *			participant TRJCTR as TRJCTR <<Sub-Component>>
 *			participant LATDMC as LATDMC <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_VehProcess()
 *			activate TaskAlgo
 *			TaskAlgo -> TaskAlgo: update cycle counter
 *			
 *			alt called every 2 cycle(s)
 *				TaskAlgo -> DRVMN: DRVMN_VehProcess()
 *				activate DRVMN
 *				DRVMN --> TaskAlgo: return
 *				deactivate DRVMN
 *			end
 *			
 *			alt called every 2 cycle(s)
 *				TaskAlgo -> TRJPLN: TRJPLN_VehProcess()
 *				activate TRJPLN
 *				TRJPLN --> TaskAlgo: return
 *				deactivate TRJPLN
 *			end
 *			
 *			alt called every 2 cycle(s)
 *				TaskAlgo -> TRJCTR: TRJCTR_VehProcess()
 *				activate TRJCTR
 *				TRJCTR --> TaskAlgo: return
 *				deactivate TRJCTR
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> LATDMC: LATDMC_VehProcess()
 *				activate LATDMC
 *				LATDMC --> TaskAlgo: return
 *				deactivate LATDMC
 *			end
 *			
 *			TaskAlgo --> TaskFrame: return
 *			deactivate TaskAlgo
 *		@enduml
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void LCF_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* LCFVEH_H_ */
