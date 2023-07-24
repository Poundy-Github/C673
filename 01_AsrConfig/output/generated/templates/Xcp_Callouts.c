/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \version 2.12.2
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#include <Xcp.h>               /* Module public API */
#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
#include <Xcp_Int.h>           /* Module internal interface */
#include <Xcp_Cbk.h>           /* callbacks and callouts of Xcp */
#include <TSAutosar.h>         /* EB specific standard types, TS_PARAM_UNUSED*/
#include <Xcp_UserCallouts.h>  /* Xcp callouts */
#include <Xcp_Trace.h>

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

#define XCP_START_SEC_APPL_CODE
#include <Xcp_MemMap.h>

/*------------------[Callouts to compare key]--------------------------------*/

FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplCompareKey
(
  uint8 ResourceIdentifier,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) KeyBufferPtr,
  uint8 KeyLength
)
{
  DBG_XCP_APPLCOMPAREKEY_ENTRY(ResourceIdentifier,KeyBufferPtr,KeyLength);
  TS_PARAM_UNUSED(ResourceIdentifier); /* Remove if parameter is used */
  TS_PARAM_UNUSED(KeyBufferPtr); /* Remove if parameter is used */
  TS_PARAM_UNUSED(KeyLength); /* Remove if parameter is used */

  /* insert your code here */
  DBG_XCP_APPLCOMPAREKEY_EXIT(E_OK,ResourceIdentifier,KeyBufferPtr,KeyLength);

  return E_OK;
}

/*------------------[Callouts to generate seed]------------------------------*/

FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplGetSeed
(
  uint8 ResourceIdentifier,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferLengthPtr
)
{
  Std_ReturnType RetValue = E_NOT_OK;
  DBG_XCP_APPLGETSEED_ENTRY(ResourceIdentifier,SeedBufferPtr,SeedBufferLengthPtr);

  
#if (XCP_DEV_ERROR_DETECT == STD_ON)
  if ((SeedBufferPtr == NULL_PTR) || (SeedBufferLengthPtr == NULL_PTR))
  {
    XCP_DET_REPORT_ERROR(XCP_SID_APPL_COMMAND, XCP_E_NULL_POINTER);
  }
  else
#endif
  {
    TS_PARAM_UNUSED(ResourceIdentifier);  /* Remove if parameter is used */
    TS_PARAM_UNUSED(SeedBufferPtr);       /* Remove if parameter is used */
    TS_PARAM_UNUSED(SeedBufferLengthPtr); /* Remove if parameter is used */

    /* insert your code here */
    RetValue = E_OK;
  }

  DBG_XCP_APPLGETSEED_EXIT(RetValue,ResourceIdentifier,SeedBufferPtr,SeedBufferLengthPtr);
  
  return RetValue;
}






#define XCP_STOP_SEC_APPL_CODE
#include <Xcp_MemMap.h>

/*==================[internal function definitions]==========================*/

#endif /* ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) ) */
/*==================[end of file]============================================*/
