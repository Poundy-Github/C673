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

#if (FRIF_CHECKWAKEUPBYTRANSCEIVER_API_ENABLE == STD_ON)

#if (TS_MERGED_COMPILE == STD_OFF)
#define FRIF_START_SEC_CODE
#include <FrIf_MemMap.h>  /* !LINKSTO FrIf.ASR40.FrIf05088,1 */
#endif /* TS_MERGED_COMPILE */

/**
 * \brief   FlexRay transceiver driver check wakeup routine.
 *
 * \param FrIf_CtrlIdx (in)       FlexRay controller index.
 * \param FrIf_ChnlIdx (in)       FlexRay channel index.
 *
 */

FUNC(void,FRIF_CODE) FrIf_CheckWakeupByTransceiver
    (
        uint8 FrIf_CtrlIdx,
        Fr_ChannelType FrIf_ChnlIdx
    )
{
    DBG_FRIF_CHECKWAKEUPBYTRANSCEIVER_ENTRY(FrIf_CtrlIdx,FrIf_ChnlIdx);
/* check if development error detection is disabled */
#if (FRIF_DEV_ERROR_DETECT == STD_OFF)

#if (FRIF_SINGLE_CTRL_OPT_ENABLE == STD_ON)

    /* if single controller optimization is enabled, parameter FrIf_CtrlIdx is not used */

    TS_PARAM_UNUSED(FrIf_CtrlIdx);

#endif /* FRIF_SINGLE_CTRL_OPT_ENABLE */

#else   /* FRIF_DEV_ERROR_DETECT == STD_OFF */
    /* check for successfully initialized module */
    /* Report to DET and return in case module was not initialized before */
    if(FrIf_ModuleInitialized == FRIF_UNINIT)
    {
        /* Report to DET */
        FrIf_Det_ReportError(FRIF_CHECKWAKEUPBYTRANSCEIVER_SERVICE_ID, FRIF_E_NOT_INITIALIZED);
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
        FrIf_Det_ReportError(FRIF_CHECKWAKEUPBYTRANSCEIVER_SERVICE_ID, FRIF_E_INV_CTRL_IDX);
    }

    /* check whether the channel argument is valid */
    else if((FrIf_ChnlIdx != FR_CHANNEL_A) && (FrIf_ChnlIdx != FR_CHANNEL_B))
    {
        /* Report to DET */
        FrIf_Det_ReportError(FRIF_CHECKWAKEUPBYTRANSCEIVER_SERVICE_ID, FRIF_E_INV_CHNL_IDX);
    }

    /* check if a transceiver was configured for this channel */
    else if(FRIF_INVALID_ENTRY ==
        FRIF_GET_CONFIG_ADDR(FrIf_CtrlType,
            FrIf_RootConfigPtr->FrIf_CtrlRef)[FRIF_CTRLIDX].Trcv[FrIf_ChnlIdx].TrcvDeviceIdx)
    {
        /* Report to DET */
        FrIf_Det_ReportError(FRIF_CHECKWAKEUPBYTRANSCEIVER_SERVICE_ID, FRIF_E_INV_CHNL_IDX);
    }

    /* all DET checks passed */
    else

#endif  /* FRIF_DEV_ERROR_DETECT == STD_OFF */

    {
#if (FRIF_SINGLE_FRTRCV_OPT_ENABLE == STD_OFF)

        /* check whether a NULL_PTR is assigned to this function pointer, or not */
        if((FRIF_FRTRCV_INSTANCE_IDX != FRIF_INVALID_ENTRY) &&
           (FrIf_Get_FrTrcvFunctionPtr(FRIF_FRTRCV_INSTANCE_IDX,CheckWakeupByTransceiver) != NULL_PTR))

#endif /* FRIF_SINGLE_FRTRCV_OPT_ENABLE */
        {
            /* call wrapped FrTrcv service */
            (void) FrIf_Call_FrTrcv(FRIF_FRTRCV_INSTANCE_IDX,CheckWakeupByTransceiver)
                (
                    FRIF_GET_CONFIG_ADDR(FrIf_CtrlType,FrIf_RootConfigPtr->FrIf_CtrlRef)
                    [FRIF_CTRLIDX].Trcv[FrIf_ChnlIdx].TrcvDeviceIdx
                );
        }
    }

    DBG_FRIF_CHECKWAKEUPBYTRANSCEIVER_EXIT(FrIf_CtrlIdx,FrIf_ChnlIdx);
}

/* stop code section declaration */
#if (TS_MERGED_COMPILE == STD_OFF)
#define FRIF_STOP_SEC_CODE
#include <FrIf_MemMap.h>  /* !LINKSTO FrIf.ASR40.FrIf05088,1 */
#endif /* TS_MERGED_COMPILE */

#endif /* FRIF_CHECKWAKEUPBYTRANSCEIVER_API_ENABLE */
