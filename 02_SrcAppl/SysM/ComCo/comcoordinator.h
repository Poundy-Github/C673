/**
 * \file comcoordinator.h
 *
 * \brief  Communication Coordinator
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2023.01.22			Jinlong Zhang			Init version
 *
 *
 */

#ifndef _COMCOORDINATOR_H_ 
#define _COMCOORDINATOR_H_ //PRQA S 0602,0603

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros definitions]====================================*/
/*The below parameter shall be decide from OEM*/
#define IGN_OFF_THSLD    (4.5f)

#define IGN_ON_THSLD     (6.0f)

#define VEHSPD_THSLD     (3.0f)

#define VEHSPD_VALID     (0x00u)
/*****************************************************************************/
#define	PDUINACTIVE 	   (0x00u)

#define	PDURXACTIVE 	   (0x01u)

#define	PDUTXACTIVE 	   (0x02u)

#define	PDURXTXACTIVE 	   (0x03u)

#define	PDUINVALID  	   (0x04u)

#define RX_NMPDU_OK        (0x01u)

#define RX_NMPDU_NOK       (0x00u)

#define WAKEUP_SUCCESSFUL  (0x01u)

#define WAKEUP_FAILED      (0x00u)

#define GET_COMCO_GVARS_INITIALIZED()    (s_Comco_StatusInfoData.GlobVarsInitialized)

#define SET_COMCO_GVARS_INITIALIZED(val) (s_Comco_StatusInfoData.GlobVarsInitialized = val)

#define GET_COMCO_RXSPECNMPDU()          (s_Comco_StatusInfoData.RxSpecNMPdu)

#define SET_COMCO_RXSPECNMPDU(val)       (s_Comco_StatusInfoData.RxSpecNMPdu = val)

#define GET_COMCO_PDUSTATE()             (s_Comco_StatusInfoData.PduState)

#define SET_COMCO_PDUSTATE(val)          (s_Comco_StatusInfoData.PduState = val)

#define GET_COMCO_WAKEUPLFAG()           (s_Comco_StatusInfoData.WakeupFlag)

#define SET_COMCO_WAKEUPFLAG(val)        (s_Comco_StatusInfoData.WakeupFlag = val)

#define GET_COMCO_CURRENT_NMSTATE()      (s_Comco_StatusInfoData.nmCurrentState)

#define SET_COMCO_CURRENT_NMSTATE(val)   (s_Comco_StatusInfoData.nmCurrentState = val)

#define GET_COMCO_PREVIOUS_NMSTATE()     (s_Comco_StatusInfoData.nmPreviousState)

#define SET_COMCO_PREVIOUS_NMSTATE(val)  (s_Comco_StatusInfoData.nmPreviousState = val)


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_Comco_NMStateType_t,
 *			The internal NM state show in the below list,
 * */
typedef enum
{
    nm_state_unit = 0,
    nm_state_bus_sleep,
	nm_state_Prepare_bus_sleep,
	nm_state_ready_sleep,
	nm_state_normal_operation,
	nm_state_repeat_message
}e_Comco_NMStateType_t;

/*
 * \brief 	s_Comco_StatusInfo_t,
 *			the some infomation of Comco shall be limit in struct data buffer,
 * */
typedef struct
{
    boolean GlobVarsInitialized; /* Indicate the module comcoordinator initial competed*/
	uint8 RxSpecNMPdu;           /* If get valid PDU ,will be set to 0x01.*/
	uint8 PduState;
	boolean WakeupFlag;  /* TRUE: Wakeup successful FALSE: Wakeup failed */
    e_Comco_NMStateType_t nmPreviousState; /*Store the previous nm state.*/
	e_Comco_NMStateType_t nmCurrentState; /*Store the current nm state. */
}s_Comco_StatusInfo_t;


/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/


/*==================[external function declarations]=========================*/
#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
extern FUNC(void, RTE_CODE) Comco_Init(void);
extern FUNC(Std_ReturnType, RTE_CODE) CanIfTransmit_UserCallout(void);
#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

#endif /*COMCOORDINATOR_H*/


