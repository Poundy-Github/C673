/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Dcm.Dsn.File.CommunicationControl.ConfigC,1 */

/*==================[inclusions]=================================================================*/
#include <Dcm_CommunicationControl_Cfg.h>
#include <SchM_Dcm.h>

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

#if (DCM_NUM_COMMUNICATIONCONTROL_ALL_CHANNEL > 0U)

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array of configuration information for Communication Control All Channels */
CONST(Dcm_CommunicationControlAllChannelType, DCM_CONST) Dcm_CommunicationControlAllChannel[DCM_NUM_COMMUNICATIONCONTROL_ALL_CHANNEL] =
{
  /* Network Id */
  0U,
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>
#endif

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#if (DCM_NUM_COMMUNICATIONCONTROL_SPECIFIC_CHANNEL > 0U)
/* Array of configuration information for Communication Control All Channels */
CONST(Dcm_CommunicationControlSpecificChannelType, DCM_CONST) Dcm_CommunicationControlSpecificChannel[DCM_NUM_COMMUNICATIONCONTROL_SPECIFIC_CHANNEL] =
{
};
#endif

#if (DCM_NUM_COMMUNICATIONCONTROL_SUBNODE_CHANNEL > 0U)
/* Array of configuration information for Communication Control SubNode Channels */
CONST(Dcm_CommunicationControlSubNodeChannelType, DCM_CONST) Dcm_CommunicationControlSubNodeChannel[DCM_NUM_COMMUNICATIONCONTROL_SUBNODE_CHANNEL] =
{
};
#endif

#if (DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE > 0U)
/* Array of ComMChannels and SchM Switch pointers for CommunicationControl */
CONST(Dcm_CommunicationControlLookupType, DCM_CONST) Dcm_CommunicationControlLookUpTable[DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE] =
{
  {
    /* Pointer to SchM Switch for DcmCommunicationControl */
    &SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Public,
    /* Network Id */
    0U,
  },
};
#endif /* #if (DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE > 0U) */


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
