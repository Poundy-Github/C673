/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Sensor
  SUB-COMPONENTS : v1ABPR,v2ODPR,VDPR,MFJSCT,LDPSA,RDPSA,ALCASA,v1TJASA,MDCTR,CTRSC,HMIOC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFSEN.h
//! @brief    Lateral Control Functions - Sensor (LCFSEN) Task Header.

#ifndef LCFSEN_H_
#define LCFSEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPR/v1ABPRSEN.h"
#include "ODPR/v2ODPRSEN.h"
#include "VDPR/VDPRSEN.h"
#include "MFJSCT/MFJSCTSEN.h"
#include "LDPSA/LDPSASEN.h"
#include "RDPSA/RDPSASEN.h"
#include "ALCASA/ALCASASEN.h"
#include "TJASA/v1TJASASEN.h"
#include "MDCTR/MDCTRSEN.h"
#include "CTRSC/CTRSCSEN.h"
#include "HMIOC/HMIOCSEN.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCFSEN task debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] LCF_SenDbgArg Pointer to LCFSEN debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html DPU_LCF_SenInitDbgPtr_callsequence.png LCFSEN Debug Initialization Call Sequence
 *		@startuml "DPU_LCF_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFSEN as TaskFrame <<Task-Frame>>
 *			participant LCFSEN as TaskAlgo <<Task-Algo>>
 *			participant v1ABPR as v1ABPR <<Sub-Component>>
 *			participant v2ODPR as v2ODPR <<Sub-Component>>
 *			participant VDPR as VDPR <<Sub-Component>>
 *			participant LDPSA as LDPSA <<Sub-Component>>
 *			participant RDPSA as RDPSA <<Sub-Component>>
 *			participant ALCASA as ALCASA <<Sub-Component>>
 *			participant v1TJASA as v1TJASA <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_SenInitDbgPtr(LCF_SenDbgArg)
 *			activate TaskAlgo
 *			
 *			TaskAlgo -> v1ABPR: v1ABPR_SenInitDbgPtr(&LCF_SenDbgArg->v1ABPR_SenDbgData)
 *			activate v1ABPR
 *			v1ABPR --> TaskAlgo: return
 *			deactivate v1ABPR
 *			
 *			TaskAlgo -> v2ODPR: v2ODPR_SenInitDbgPtr(&LCF_SenDbgArg->v2ODPR_SenDbgData)
 *			activate v2ODPR
 *			v2ODPR --> TaskAlgo: return
 *			deactivate v2ODPR
 *			
 *			TaskAlgo -> VDPR: VDPR_SenInitDbgPtr(&LCF_SenDbgArg->VDPR_SenDbgData)
 *			activate VDPR
 *			VDPR --> TaskAlgo: return
 *			deactivate VDPR
 *			
 *			TaskAlgo -> LDPSA: LDPSA_SenInitDbgPtr(&LCF_SenDbgArg->LDPSA_SenDbgData)
 *			activate LDPSA
 *			LDPSA --> TaskAlgo: return
 *			deactivate LDPSA
 *			
 *			TaskAlgo -> RDPSA: RDPSA_SenInitDbgPtr(&LCF_SenDbgArg->RDPSA_SenDbgData)
 *			activate RDPSA
 *			RDPSA --> TaskAlgo: return
 *			deactivate RDPSA
 *			
 *			TaskAlgo -> ALCASA: ALCASA_SenInitDbgPtr(&LCF_SenDbgArg->ALCASA_SenDbgData)
 *			activate ALCASA
 *			ALCASA --> TaskAlgo: return
 *			deactivate ALCASA
 *			
 *			TaskAlgo -> v1TJASA: v1TJASA_SenInitDbgPtr(&LCF_SenDbgArg->v1TJASA_SenDbgData)
 *			activate v1TJASA
 *			v1TJASA --> TaskAlgo: return
 *			deactivate v1TJASA
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
extern void LCF_SenInitDbgPtr(LCF_SenDbgType *LCF_SenDbgArg);

/*!
 *	LCFSEN task output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] LCF_SenOutPtr Pointer to LCFSEN output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html DPU_LCF_SenInitOutPtr_callsequence.png LCFSEN Output Initialization Call Sequence
 *		@startuml "DPU_LCF_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFSEN as TaskFrame <<Task-Frame>>
 *			participant LCFSEN as TaskAlgo <<Task-Algo>>
 *			participant v1ABPR as v1ABPR <<Sub-Component>>
 *			participant v2ODPR as v2ODPR <<Sub-Component>>
 *			participant LDPSA as LDPSA <<Sub-Component>>
 *			participant RDPSA as RDPSA <<Sub-Component>>
 *			participant ALCASA as ALCASA <<Sub-Component>>
 *			participant v1TJASA as v1TJASA <<Sub-Component>>
 *			participant MDCTR as MDCTR <<Sub-Component>>
 *			participant CTRSC as CTRSC <<Sub-Component>>
 *			participant HMIOC as HMIOC <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_SenInitOutPtr(LCF_SenOutPtr)
 *			activate TaskAlgo
 *			
 *			TaskAlgo -> v1ABPR: v1ABPR_SenInitOutPtr(&LCF_SenOutPtr->v1ABPR_SenOutData)
 *			activate v1ABPR
 *			v1ABPR --> TaskAlgo: return
 *			deactivate v1ABPR
 *			
 *			TaskAlgo -> v2ODPR: v2ODPR_SenInitOutPtr(&LCF_SenOutPtr->v2ODPR_SenOutData)
 *			activate v2ODPR
 *			v2ODPR --> TaskAlgo: return
 *			deactivate v2ODPR
 *			
 *			TaskAlgo -> LDPSA: LDPSA_SenInitOutPtr(&LCF_SenOutPtr->LDPSA_SenOutData)
 *			activate LDPSA
 *			LDPSA --> TaskAlgo: return
 *			deactivate LDPSA
 *			
 *			TaskAlgo -> RDPSA: RDPSA_SenInitOutPtr(&LCF_SenOutPtr->RDPSA_SenOutData)
 *			activate RDPSA
 *			RDPSA --> TaskAlgo: return
 *			deactivate RDPSA
 *			
 *			TaskAlgo -> ALCASA: ALCASA_SenInitOutPtr(&LCF_SenOutPtr->ALCASA_SenOutData)
 *			activate ALCASA
 *			ALCASA --> TaskAlgo: return
 *			deactivate ALCASA
 *			
 *			TaskAlgo -> v1TJASA: v1TJASA_SenInitOutPtr(&LCF_SenOutPtr->v1TJASA_SenOutData)
 *			activate v1TJASA
 *			v1TJASA --> TaskAlgo: return
 *			deactivate v1TJASA
 *			
 *			TaskAlgo -> MDCTR: MDCTR_SenInitOutPtr(&LCF_SenOutPtr->MDCTR_SenOutData)
 *			activate MDCTR
 *			MDCTR --> TaskAlgo: return
 *			deactivate MDCTR
 *			
 *			TaskAlgo -> CTRSC: CTRSC_SenInitOutPtr(&LCF_SenOutPtr->CTRSC_SenOutData)
 *			activate CTRSC
 *			CTRSC --> TaskAlgo: return
 *			deactivate CTRSC
 *			
 *			TaskAlgo -> HMIOC: HMIOC_SenInitOutPtr(&LCF_SenOutPtr->HMIOC_SenOutData)
 *			activate HMIOC
 *			HMIOC --> TaskAlgo: return
 *			deactivate HMIOC
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
extern void LCF_SenInitOutPtr(LCF_SenOutType *LCF_SenOutPtr);

/*!
 *	LCFSEN task reset function.
 *	
 *	@pre
 *		- The LCFSEN initialization function(s) must be called once.
 *		- The LCFSEN debug/output data pointer(s) should not be NULL.
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
 *		@image html DPU_LCF_SenReset_callsequence.png LCFSEN Reset Call Sequence
 *		@startuml "DPU_LCF_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFSEN as TaskFrame <<Task-Frame>>
 *			participant LCFSEN as TaskAlgo <<Task-Algo>>
 *			participant v1ABPR as v1ABPR <<Sub-Component>>
 *			participant v2ODPR as v2ODPR <<Sub-Component>>
 *			participant VDPR as VDPR <<Sub-Component>>
 *			participant MFJSCT as MFJSCT <<Sub-Component>>
 *			participant LDPSA as LDPSA <<Sub-Component>>
 *			participant RDPSA as RDPSA <<Sub-Component>>
 *			participant ALCASA as ALCASA <<Sub-Component>>
 *			participant v1TJASA as v1TJASA <<Sub-Component>>
 *			participant MDCTR as MDCTR <<Sub-Component>>
 *			participant CTRSC as CTRSC <<Sub-Component>>
 *			participant HMIOC as HMIOC <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_SenReset()
 *			activate TaskAlgo
 *			
 *			TaskAlgo -> v1ABPR: v1ABPR_SenReset()
 *			activate v1ABPR
 *			v1ABPR --> TaskAlgo: return
 *			deactivate v1ABPR
 *			
 *			TaskAlgo -> v2ODPR: v2ODPR_SenReset()
 *			activate v2ODPR
 *			v2ODPR --> TaskAlgo: return
 *			deactivate v2ODPR
 *			
 *			TaskAlgo -> VDPR: VDPR_SenReset()
 *			activate VDPR
 *			VDPR --> TaskAlgo: return
 *			deactivate VDPR
 *			
 *			TaskAlgo -> MFJSCT: MFJSCT_SenReset()
 *			activate MFJSCT
 *			MFJSCT --> TaskAlgo: return
 *			deactivate MFJSCT
 *			
 *			TaskAlgo -> LDPSA: LDPSA_SenReset()
 *			activate LDPSA
 *			LDPSA --> TaskAlgo: return
 *			deactivate LDPSA
 *			
 *			TaskAlgo -> RDPSA: RDPSA_SenReset()
 *			activate RDPSA
 *			RDPSA --> TaskAlgo: return
 *			deactivate RDPSA
 *			
 *			TaskAlgo -> ALCASA: ALCASA_SenReset()
 *			activate ALCASA
 *			ALCASA --> TaskAlgo: return
 *			deactivate ALCASA
 *			
 *			TaskAlgo -> v1TJASA: v1TJASA_SenReset()
 *			activate v1TJASA
 *			v1TJASA --> TaskAlgo: return
 *			deactivate v1TJASA
 *			
 *			TaskAlgo -> MDCTR: MDCTR_SenReset()
 *			activate MDCTR
 *			MDCTR --> TaskAlgo: return
 *			deactivate MDCTR
 *			
 *			TaskAlgo -> CTRSC: CTRSC_SenReset()
 *			activate CTRSC
 *			CTRSC --> TaskAlgo: return
 *			deactivate CTRSC
 *			
 *			TaskAlgo -> HMIOC: HMIOC_SenReset()
 *			activate HMIOC
 *			HMIOC --> TaskAlgo: return
 *			deactivate HMIOC
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
extern void LCF_SenReset(void);

/*!
 *	LCFSEN task process function.
 *	
 *	@pre
 *		- The LCFSEN initialization function(s) must be called once.
 *		- The LCFSEN debug/output data pointer(s) should not be NULL.
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
 *		@image html DPU_LCF_SenProcess_callsequence.png LCFSEN Process Call Sequence
 *		@startuml "DPU_LCF_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Frame>> gray
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *			}
 *			
 *			participant LCFSEN as TaskFrame <<Task-Frame>>
 *			participant LCFSEN as TaskAlgo <<Task-Algo>>
 *			participant v1ABPR as v1ABPR <<Sub-Component>>
 *			participant v2ODPR as v2ODPR <<Sub-Component>>
 *			participant VDPR as VDPR <<Sub-Component>>
 *			participant MFJSCT as MFJSCT <<Sub-Component>>
 *			participant LDPSA as LDPSA <<Sub-Component>>
 *			participant RDPSA as RDPSA <<Sub-Component>>
 *			participant ALCASA as ALCASA <<Sub-Component>>
 *			participant v1TJASA as v1TJASA <<Sub-Component>>
 *			participant MDCTR as MDCTR <<Sub-Component>>
 *			participant CTRSC as CTRSC <<Sub-Component>>
 *			participant HMIOC as HMIOC <<Sub-Component>>
 *			
 *			TaskFrame -> TaskAlgo: LCF_SenProcess()
 *			activate TaskAlgo
 *			TaskAlgo -> TaskAlgo: update cycle counter
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> v1ABPR: v1ABPR_SenProcess()
 *				activate v1ABPR
 *				v1ABPR --> TaskAlgo: return
 *				deactivate v1ABPR
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> v2ODPR: v2ODPR_SenProcess()
 *				activate v2ODPR
 *				v2ODPR --> TaskAlgo: return
 *				deactivate v2ODPR
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> VDPR: VDPR_SenProcess()
 *				activate VDPR
 *				VDPR --> TaskAlgo: return
 *				deactivate VDPR
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> MFJSCT: MFJSCT_SenProcess()
 *				activate MFJSCT
 *				MFJSCT --> TaskAlgo: return
 *				deactivate MFJSCT
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> LDPSA: LDPSA_SenProcess()
 *				activate LDPSA
 *				LDPSA --> TaskAlgo: return
 *				deactivate LDPSA
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> RDPSA: RDPSA_SenProcess()
 *				activate RDPSA
 *				RDPSA --> TaskAlgo: return
 *				deactivate RDPSA
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> ALCASA: ALCASA_SenProcess()
 *				activate ALCASA
 *				ALCASA --> TaskAlgo: return
 *				deactivate ALCASA
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> v1TJASA: v1TJASA_SenProcess()
 *				activate v1TJASA
 *				v1TJASA --> TaskAlgo: return
 *				deactivate v1TJASA
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> MDCTR: MDCTR_SenProcess()
 *				activate MDCTR
 *				MDCTR --> TaskAlgo: return
 *				deactivate MDCTR
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> CTRSC: CTRSC_SenProcess()
 *				activate CTRSC
 *				CTRSC --> TaskAlgo: return
 *				deactivate CTRSC
 *			end
 *			
 *			alt called every 1 cycle(s)
 *				TaskAlgo -> HMIOC: HMIOC_SenProcess()
 *				activate HMIOC
 *				HMIOC --> TaskAlgo: return
 *				deactivate HMIOC
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
extern void LCF_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* LCFSEN_H_ */
