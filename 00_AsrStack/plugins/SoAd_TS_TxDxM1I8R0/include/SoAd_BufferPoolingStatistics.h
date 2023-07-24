/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.8.18
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#if (!defined SOAD_BUFFERPOOLING_STATISTICS_H)
#define SOAD_BUFFERPOOLING_STATISTICS_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

/* Check if BASE_DBG_ENABLE is defined and set to STD_ON.
 * If so, include Base_Dbg.h which includes a custom header file */
#if (defined BASE_DBG_ENABLE)
#if (BASE_DBG_ENABLE == STD_ON)

#include <Base_Dbg.h>

#endif
#endif

#include <SoAd.h>

/*==[Declaration of functions with external linkage]==========================*/

#define SOAD_START_SEC_CODE
#include <SoAd_MemMap.h>

extern FUNC(void, SOAD_CODE) SoAd_BP_DUMMY
(
  SoAd_SoConIdType SoConGroupId
);

#define SOAD_STOP_SEC_CODE
#include <SoAd_MemMap.h>

/*==[Macros]==================================================================*/
#ifndef SOAD_BUFFERPOOLING_UDPPDUSENT
#define SOAD_BUFFERPOOLING_UDPPDUSENT(SoConGroupId)
#endif

#ifndef SOAD_BUFFERPOOLING_UDPPDUDROP
#define SOAD_BUFFERPOOLING_UDPPDUDROP(SoConGroupId) SoAd_BP_DUMMY((SoConGroupId))
#endif

#ifdef SOAD_BUFFERPOOLING_CONVERT_SOCONGROUPID_TO_SOCONFIRSTID /* To prevent double definition */
#error SOAD_BUFFERPOOLING_CONVERT_SOCONGROUPID_TO_SOCONFIRSTID already defined!
#endif

#define SOAD_BUFFERPOOLING_CONVERT_SOCONGROUPID_TO_SOCONFIRSTID(SoConGroupId, SoConFirstIdPtr) \
do \
{ \
    CONSTP2CONST(SoAd_SoConGroupType, AUTOMATIC, SOAD_APPL_DATA) SoConGroupPtr = \
      &SOAD_CFG(SoConGroup, SoConGroupId); \
    *SoConFirstIdPtr = SoConGroupPtr->SoConFirstId; \
}while(0)



#endif /* !defined SOAD_BUFFERPOOLING_STATISTICS_H */
