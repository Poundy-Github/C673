
/******************************************************************************
**                                                                           **
**                                                                           **
** EB Automotive C Source File                                               **
**                                                                           **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : CanIf_Cbk_stub.c                                            **
**                                                                           **
**                                                                           **
**  PLATFORM   : Infineon AURIX2G                                            **
**                                                                           **
**                                                                           **
**  DESCRIPTION : Stub Implementation of CAN Interface callback functions.   **
**				  Function is defined as stub since its unavailable in       **
**				  Can_If as its ASR4.0.3     								 **
**                This file is for Evaluation Purpose Only                   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef CANIF_CBK_STUB_H
#define CANIF_CBK_STUB_H

/*==================[inclusions]============================================*/
#include <ComStack_Types.h>

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/

#define CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
#include "Can_17_McmCan_MemMap.h"

/* Declaration of CanIf_TriggerTransmit */
extern Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr);

#define CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
#include "Can_17_McmCan_MemMap.h"

#endif 

