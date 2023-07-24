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
/*==================[inclusions]=================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,3 */
/* !LINKSTO WDGM.EB.Dbg3,1 */
#include <WdgM_Trace_Stc.h>
#include <WdgM_Rte_Lcfg.h>                           /* Module internal Rte declarations and API */

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal data]==============================================================*/

/*==================[external data]==============================================================*/

/*==================[internal constants]=========================================================*/
static CONST(uint8, WDGM_CONST) WdgM_RteSwitch_SE_Idx[WDGM_EB_SE_NUM] =
{
  0, /* Index in WdgM_Core_X_RteSwitch for WdgM_SE_AS_HM */
  0, /* Index in WdgM_Core_X_RteSwitch for WdgM_SE_SWC_MONITOR */
  1, /* Index in WdgM_Core_X_RteSwitch for WdgM_SE_CameraTemp */
  2, /* Index in WdgM_Core_X_RteSwitch for WdgM_SE_ConfigReg */
  3, /* Index in WdgM_Core_X_RteSwitch for WdgM_SE_FS_MAIN */
  4, /* Index in WdgM_Core_X_RteSwitch for WdgM_SE_FS_ADC */
};
/*==================[external constants]=========================================================*/

/*==================[external function definitions]==============================================*/

#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

FUNC(void, WDGM_CODE) WdgM_RteIndividualModeSwitch
(
  WdgM_SupervisedEntityIdType       SEID,
  WdgM_LocalStatusType              LocalStatus,
  WdgM_EB_CoreIdType                CoreID
)
{
  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTEINDIVIDUALMODESWITCH_ENTRY(SEID,LocalStatus,CoreID);

  switch(CoreID) {
  case 0 :  WdgM_RteIndividualModeSwitch_CORE_0(WdgM_RteSwitch_SE_Idx[SEID], LocalStatus);
            break;
  case 1 :  WdgM_RteIndividualModeSwitch_CORE_1(WdgM_RteSwitch_SE_Idx[SEID], LocalStatus);
            break;
  default: WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
           break;
  }

  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTEINDIVIDUALMODESWITCH_EXIT(SEID,LocalStatus,CoreID);
}

#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
