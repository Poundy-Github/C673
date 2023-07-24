/**
 * \file
 *
 * \brief AUTOSAR WdgM
 *
 * This file contains the implementation of the AUTOSAR
 * module WdgM.
 *
 * \version 6.2.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef WDGM_RTE_LCFG_H
#define WDGM_RTE_LCFG_H

/*==================[inclusions]=================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,3 */
#include <WdgM.h>                                    /* WdgM types and APIs */
#include <WdgM_Int.h>                                /* For internal macros */
/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/
#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

extern FUNC(void, WDGM_CODE) WdgM_RteIndividualModeSwitch_CORE_0(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType LocalStatus);
extern FUNC(void, WDGM_CODE) WdgM_RteIndividualModeSwitch_CORE_1(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType LocalStatus);

#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

/*==================[external constants]=========================================================*/


/*==================[external data]==============================================================*/

#endif /* ifndef WDGM_RTE_LCFG_H  */
/*==================[end of file]================================================================*/
