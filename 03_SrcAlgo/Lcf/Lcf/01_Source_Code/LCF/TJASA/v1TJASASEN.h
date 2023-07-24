/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : v1TJASA
  MODULES       : TJALKA,TJAOBF,TJACMB,TJAGEN,TJASTM,TJATTG,TJATVG
  AUTHOR        : SubComponent_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.3 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:25:13CEST $
  $Log: v1TJASASEN.h  $
  Revision 1.1.1.3 2020/04/09 14:25:13CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.1.1.2 2019/11/29 09:04:44CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     v1TJASASEN.h
//! @brief     (v1TJASA) Sub-Component Sensor Header.

#ifndef V1TJASASEN_H_
#define V1TJASASEN_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TJALKA/TJALKA.h"
#include "TJAOBF/TJAOBF.h"
#include "TJACMB/TJACMB.h"
#include "TJAGEN/TJAGEN.h"
#include "TJASTM/TJASTM.h"
#include "TJATTG/TJATTG.h"
#include "TJATVG/TJATVG.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	v1TJASA sub-component sensor debug initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] v1TJASA_SenDbgPtr Pointer to v1TJASA sensor debug data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html v1TJASA_SenInitDbgPtr_callsequence.png v1TJASA Debug Initialization Call Sequence
 *		@startuml "v1TJASA_SenInitDbgPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1TJASA as SubCmp <<Sub-Component>>
 *			participant TJALKA as TJALKA <<Module>>
 *			participant TJAOBF as TJAOBF <<Module>>
 *			participant TJACMB as TJACMB <<Module>>
 *			participant TJAGEN as TJAGEN <<Module>>
 *			participant TJASTM as TJASTM <<Module>>
 *			participant TJATTG as TJATTG <<Module>>
 *			
 *			Task -> SubCmp: v1TJASA_SenInitDbgPtr(v1TJASA_SenDbgPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> TJALKA: TJALKA_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJALKA_SenDbgData)
 *			activate TJALKA
 *			TJALKA --> SubCmp: return
 *			deactivate TJALKA
 *			
 *			SubCmp -> TJAOBF: TJAOBF_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJAOBF_SenDbgData)
 *			activate TJAOBF
 *			TJAOBF --> SubCmp: return
 *			deactivate TJAOBF
 *			
 *			SubCmp -> TJACMB: TJACMB_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJACMB_SenDbgData)
 *			activate TJACMB
 *			TJACMB --> SubCmp: return
 *			deactivate TJACMB
 *			
 *			SubCmp -> TJAGEN: TJAGEN_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJAGEN_SenDbgData)
 *			activate TJAGEN
 *			TJAGEN --> SubCmp: return
 *			deactivate TJAGEN
 *			
 *			SubCmp -> TJASTM: TJASTM_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJASTM_SenDbgData)
 *			activate TJASTM
 *			TJASTM --> SubCmp: return
 *			deactivate TJASTM
 *			
 *			SubCmp -> TJATTG: TJATTG_SenInitDbgPtr(&v1TJASA_SenDbgPtr->TJATTG_SenDbgData)
 *			activate TJATTG
 *			TJATTG --> SubCmp: return
 *			deactivate TJATTG
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
extern void v1TJASA_SenInitDbgPtr(v1TJASA_SenDbgType *v1TJASA_SenDbgPtr);

/*!
 *	v1TJASA sub-component sensor output initialization function.
 *	
 *	@pre
 *		
 *	@post
 *		
 *	@param
 *		[in] v1TJASA_SenOutPtr Pointer to v1TJASA sensor output data.
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		
 *	@InOutCorrelation
 *		
 *	@callsequence
 *		@image html v1TJASA_SenInitOutPtr_callsequence.png v1TJASA Output Initialization Call Sequence
 *		@startuml "v1TJASA_SenInitOutPtr_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1TJASA as SubCmp <<Sub-Component>>
 *			participant TJALKA as TJALKA <<Module>>
 *			participant TJAOBF as TJAOBF <<Module>>
 *			participant TJACMB as TJACMB <<Module>>
 *			participant TJAGEN as TJAGEN <<Module>>
 *			participant TJASTM as TJASTM <<Module>>
 *			participant TJATTG as TJATTG <<Module>>
 *			participant TJATVG as TJATVG <<Module>>
 *			
 *			Task -> SubCmp: v1TJASA_SenInitOutPtr(v1TJASA_SenOutPtr)
 *			activate SubCmp
 *			
 *			SubCmp -> TJALKA: TJALKA_SenInitOutPtr(&v1TJASA_SenOutPtr->TJALKA_SenOutData)
 *			activate TJALKA
 *			TJALKA --> SubCmp: return
 *			deactivate TJALKA
 *			
 *			SubCmp -> TJAOBF: TJAOBF_SenInitOutPtr(&v1TJASA_SenOutPtr->TJAOBF_SenOutData)
 *			activate TJAOBF
 *			TJAOBF --> SubCmp: return
 *			deactivate TJAOBF
 *			
 *			SubCmp -> TJACMB: TJACMB_SenInitOutPtr(&v1TJASA_SenOutPtr->TJACMB_SenOutData)
 *			activate TJACMB
 *			TJACMB --> SubCmp: return
 *			deactivate TJACMB
 *			
 *			SubCmp -> TJAGEN: TJAGEN_SenInitOutPtr(&v1TJASA_SenOutPtr->TJAGEN_SenOutData)
 *			activate TJAGEN
 *			TJAGEN --> SubCmp: return
 *			deactivate TJAGEN
 *			
 *			SubCmp -> TJASTM: TJASTM_SenInitOutPtr(&v1TJASA_SenOutPtr->TJASTM_SenOutData)
 *			activate TJASTM
 *			TJASTM --> SubCmp: return
 *			deactivate TJASTM
 *			
 *			SubCmp -> TJATTG: TJATTG_SenInitOutPtr(&v1TJASA_SenOutPtr->TJATTG_SenOutData)
 *			activate TJATTG
 *			TJATTG --> SubCmp: return
 *			deactivate TJATTG
 *			
 *			SubCmp -> TJATVG: TJATVG_SenInitOutPtr(&v1TJASA_SenOutPtr->TJATVG_SenOutData)
 *			activate TJATVG
 *			TJATVG --> SubCmp: return
 *			deactivate TJATVG
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
extern void v1TJASA_SenInitOutPtr(v1TJASA_SenOutType *v1TJASA_SenOutPtr);

/*!
 *	v1TJASA sub-component sensor reset function.
 *	
 *	@pre
 *		- The v1TJASA sensor initialization function(s) must be called once.
 *		- The v1TJASA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html v1TJASA_SenReset_callsequence.png v1TJASA Reset Call Sequence
 *		@startuml "v1TJASA_SenReset_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1TJASA as SubCmp <<Sub-Component>>
 *			participant TJALKA as TJALKA <<Module>>
 *			participant TJAOBF as TJAOBF <<Module>>
 *			participant TJACMB as TJACMB <<Module>>
 *			participant TJAGEN as TJAGEN <<Module>>
 *			participant TJASTM as TJASTM <<Module>>
 *			participant TJATTG as TJATTG <<Module>>
 *			participant TJATVG as TJATVG <<Module>>
 *			
 *			Task -> SubCmp: v1TJASA_SenReset()
 *			activate SubCmp
 *			
 *			SubCmp -> TJALKA: TJALKA_SenReset()
 *			activate TJALKA
 *			TJALKA --> SubCmp: return
 *			deactivate TJALKA
 *			
 *			SubCmp -> TJAOBF: TJAOBF_SenReset()
 *			activate TJAOBF
 *			TJAOBF --> SubCmp: return
 *			deactivate TJAOBF
 *			
 *			SubCmp -> TJACMB: TJACMB_SenReset()
 *			activate TJACMB
 *			TJACMB --> SubCmp: return
 *			deactivate TJACMB
 *			
 *			SubCmp -> TJAGEN: TJAGEN_SenReset()
 *			activate TJAGEN
 *			TJAGEN --> SubCmp: return
 *			deactivate TJAGEN
 *			
 *			SubCmp -> TJASTM: TJASTM_SenReset()
 *			activate TJASTM
 *			TJASTM --> SubCmp: return
 *			deactivate TJASTM
 *			
 *			SubCmp -> TJATTG: TJATTG_SenReset()
 *			activate TJATTG
 *			TJATTG --> SubCmp: return
 *			deactivate TJATTG
 *			
 *			SubCmp -> TJATVG: TJATVG_SenReset()
 *			activate TJATVG
 *			TJATVG --> SubCmp: return
 *			deactivate TJATVG
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
extern void v1TJASA_SenReset(void);

/*!
 *	v1TJASA sub-component sensor process function.
 *	
 *	@pre
 *		- The v1TJASA sensor initialization function(s) must be called once.
 *		- The v1TJASA sensor debug/output data pointer(s) should not be NULL.
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
 *		@image html v1TJASA_SenProcess_callsequence.png v1TJASA Process Call Sequence
 *		@startuml "v1TJASA_SenProcess_callsequence.png"
 *			skinparam componentStyle uml2
 *			skinparam participant {
 *				backgroundColor<<Task-Algo>> lightgray
 *				backgroundColor<<Sub-Component>> yellow
 *				backgroundColor<<Module>> lightyellow
 *			}
 *			
 *			participant LCFSEN as Task <<Task-Algo>>
 *			participant v1TJASA as SubCmp <<Sub-Component>>
 *			participant TJALKA as TJALKA <<Module>>
 *			participant TJAOBF as TJAOBF <<Module>>
 *			participant TJACMB as TJACMB <<Module>>
 *			participant TJAGEN as TJAGEN <<Module>>
 *			participant TJASTM as TJASTM <<Module>>
 *			participant TJATTG as TJATTG <<Module>>
 *			participant TJATVG as TJATVG <<Module>>
 *			
 *			Task -> SubCmp: v1TJASA_SenProcess()
 *			activate SubCmp
 *			
 *			SubCmp -> TJALKA: TJALKA_SenProcess()
 *			activate TJALKA
 *			TJALKA --> SubCmp: return
 *			deactivate TJALKA
 *			
 *			SubCmp -> TJAOBF: TJAOBF_SenProcess()
 *			activate TJAOBF
 *			TJAOBF --> SubCmp: return
 *			deactivate TJAOBF
 *			
 *			SubCmp -> TJACMB: TJACMB_SenProcess()
 *			activate TJACMB
 *			TJACMB --> SubCmp: return
 *			deactivate TJACMB
 *			
 *			SubCmp -> TJAGEN: TJAGEN_SenProcess()
 *			activate TJAGEN
 *			TJAGEN --> SubCmp: return
 *			deactivate TJAGEN
 *			
 *			SubCmp -> TJASTM: TJASTM_SenProcess()
 *			activate TJASTM
 *			TJASTM --> SubCmp: return
 *			deactivate TJASTM
 *			
 *			SubCmp -> TJATTG: TJATTG_SenProcess()
 *			activate TJATTG
 *			TJATTG --> SubCmp: return
 *			deactivate TJATTG
 *			
 *			SubCmp -> TJATVG: TJATVG_SenProcess()
 *			activate TJATVG
 *			TJATVG --> SubCmp: return
 *			deactivate TJATVG
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
extern void v1TJASA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* V1TJASASEN_H_*/
