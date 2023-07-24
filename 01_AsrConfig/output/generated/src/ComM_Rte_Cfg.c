/**
 * \file
 *
 * \brief AUTOSAR ComM
 *
 * This file contains the implementation of the AUTOSAR
 * module ComM.
 *
 * \version 5.19.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO ComM503_Refine,1 */

/*==================[inclusions]============================================*/

/* prevent RTE symbols defined in ComM.h to be visible for ComM's .c files */
#if (defined COMM_INTERNAL_USAGE)
#error COMM_INTERNAL_USAGE already defined
#endif
#define COMM_INTERNAL_USAGE

#include <ComM_BSW.h>         /* public API symbols */
#include <ComM_Rte_Cfg.h>    /* internal Rte config dependent header */

#if (COMM_INCLUDE_RTE == STD_ON)
/* Functions defined by RTE: Rte_Mode_UM_*_currentMode() */
/* !LINKSTO ComM506_Refine_Rte,1 */
#include <Rte_ComM.h>
#endif

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

#define COMM_START_SEC_CONST_UNSPECIFIED
#include <ComM_MemMap.h>

#if (COMM_INCLUDE_RTE == STD_ON)
#if (COMM_NUM_USERS != 0U)
CONST(ComM_RteSwitchCbkType, COMM_CONST) ComM_RteSwitchCbk[USER_ARRAY_SIZE] =
{
  /* user ComMUser_Public, ID=0 */
  &Rte_Switch_UM_ComMUser_Public_currentMode,
  /* user ComMUser_Private, ID=1 */
  &Rte_Switch_UM_ComMUser_Private_currentMode,
};
#endif


#if (COMM_CURRENTCHANNELREQUEST_ENABLED == STD_ON)
CONST(ComM_RteWriteCbkType, COMM_CONST) ComM_RteWriteCbk[COMM_NUM_CHANNELS] =
{
  /* channel ComMChannel_Public, ID=0 */
  NULL_PTR, /* ComM_CurrentChannelRequest not used for this channel */
  /* channel ComMChannel_Private, ID=1 */
  NULL_PTR, /* ComM_CurrentChannelRequest not used for this channel */
};
#endif /* COMM_CURRENTCHANNELREQUEST_ENABLED */

#endif /* COMM_INCLUDE_RTE */

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include <ComM_MemMap.h>

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#if ((COMM_INCLUDE_RTE == STD_ON) && (COMM_NUM_USERS != 0U))

#define COMM_START_SEC_VAR_CLEARED_8
#include <ComM_MemMap.h>



VAR(ComM_ASR40_ModeType, COMM_VAR) ComM_RteModeUser[USER_ARRAY_SIZE];

#define COMM_STOP_SEC_VAR_CLEARED_8
#include <ComM_MemMap.h>

#endif /* #if ((COMM_INCLUDE_RTE == STD_ON) && (COMM_NUM_USERS != 0U))*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
