/**
 * \file
 *
 * \brief AUTOSAR FrIf
 *
 * This file contains the implementation of the AUTOSAR
 * module FrIf.
 *
 * \version 5.3.26
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*======================[Include Section]=====================================*/

#include <FrIf_guards.h> /* Include define guards */
#include <FrIf_Trace.h>
#include <FrIf_Priv.h>

/*======================[Local Macros]========================================*/

/*======================[Local Data Types]====================================*/

/*======================[Local Data]==========================================*/

/*======================[Local Functions]=====================================*/

/*======================[Global Functions]====================================*/

#if (FRIF_GETIRQSTATUS_API_ENABLE == STD_ON)

/* only available if Fr-integration is disabled */
#if (FRIF_FR_INTEGRATION_ENABLE == STD_OFF)

#if (TS_MERGED_COMPILE == STD_OFF)
#define FRIF_START_SEC_CODE
#include <FrIf_MemMap.h>  /* !LINKSTO FrIf.ASR40.FrIf05088,1 */
#endif /* TS_MERGED_COMPILE */

/**
 * \brief  Wraps the corresponding Fr-API service
 *
 * \param FrIf_CtrlIdx (in)       FlexRay controller index.
 * \param FrIf_AbsTimerIdx (in)      Absolute timer index.
 * \param FrIf_IRQStatusPtr (out)   Address the timer IRQ status is stored to
 *
 * \retval  E_OK               Function serviced successfully.
 * \retval  E_NOT_OK           Function execution failed.
 */

FUNC(Std_ReturnType,FRIF_CODE) FrIf_GetAbsoluteTimerIRQStatus
    (
        uint8 FrIf_CtrlIdx,
        uint8 FrIf_AbsTimerIdx,
        P2VAR(boolean,AUTOMATIC,FRIF_APPL_DATA) FrIf_IRQStatusPtr
    )
{
    Std_ReturnType RetValue = E_NOT_OK;

    DBG_FRIF_GETABSOLUTETIMERIRQSTATUS_ENTRY(FrIf_CtrlIdx,FrIf_AbsTimerIdx,FrIf_IRQStatusPtr);

/* check if development error detection is disabled */
#if (FRIF_DEV_ERROR_DETECT == STD_OFF)

#if (FRIF_SINGLE_CTRL_OPT_ENABLE == STD_ON)

    /* if single controller optimization is enabled, parameter FrIf_CtrlIdx is not used */
    TS_PARAM_UNUSED(FrIf_CtrlIdx);

#endif /* FRIF_SINGLE_CTRL_OPT_ENABLE */

#else /* FRIF_DEV_ERROR_DETECT == STD_OFF */
    /* check for successfully initialized module */
    /* Report to DET and return Error in case module was not initialized before */
    if(FrIf_ModuleInitialized == FRIF_UNINIT)
    {
        /* Report to DET */
        FrIf_Det_ReportError(FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID, FRIF_E_NOT_INITIALIZED);
    }

#if (FRIF_SINGLE_CTRL_OPT_ENABLE == STD_ON)
    /* check that controller index is 0 if single controller optimization is enabled*/
    else if (FrIf_CtrlIdx != (uint8) 0U)

#else /* FRIF_SINGLE_CTRL_OPT_ENABLE */
    /* otherwise check that the index is not out of configuration-bounds */
    else if(FRIF_CTRLIDX >= FrIf_RootConfigPtr->FrIf_CtrlNum)

#endif  /* FRIF_SINGLE_CTRL_OPT_ENABLE */
    {
        /* Report to DET */
        FrIf_Det_ReportError(FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID, FRIF_E_INV_CTRL_IDX);
    }

    else

#endif  /* FRIF_DEV_ERROR_DETECT == STD_OFF */
    {
        /* call wrapped Fr service */
        RetValue = FrIf_Call_Fr_Arg3(FRIF_FR_INSTANCE_IDX,GetAbsoluteTimerIRQStatus,FRIF_FR_CTRLIDX, FrIf_AbsTimerIdx, FrIf_IRQStatusPtr);
    }

    /* return result */

    DBG_FRIF_GETABSOLUTETIMERIRQSTATUS_EXIT(RetValue,FrIf_CtrlIdx,FrIf_AbsTimerIdx,FrIf_IRQStatusPtr);
    return RetValue;
}

/* stop code section declaration */
#if (TS_MERGED_COMPILE == STD_OFF)
#define FRIF_STOP_SEC_CODE
#include <FrIf_MemMap.h>  /* !LINKSTO FrIf.ASR40.FrIf05088,1 */
#endif /* TS_MERGED_COMPILE */

#endif /* FRIF_FR_INTEGRATION_ENABLE */

#endif /* FRIF_GETIRQSTATUS_API_ENABLE */
