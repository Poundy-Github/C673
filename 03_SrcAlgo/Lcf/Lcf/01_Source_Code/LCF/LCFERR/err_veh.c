/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Functions)

  MODULNAME:                 err_veh.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.12 $


  ---*/ /*---
  CHANGES:                   $Log: err_veh.c  $
  CHANGES:                   Revision 1.12 2019/11/26 12:11:25CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.11 2019/04/10 03:46:26CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.10 2019/03/15 10:50:40CET Grosu, George (uidl9584) 
  CHANGES:                   Reset outputs every cycle in case of no error
  CHANGES:                   Revision 1.9 2019/03/13 10:38:37CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.8 2019/02/25 15:19:19CET Grosu, George (uidl9584) 
  CHANGES:                   Remove unused function
  CHANGES:                   Revision 1.7 2019/02/19 13:14:26CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.6 2019/02/04 16:41:10CET Grosu, George (uidl9584) 
  CHANGES:                   Update LCF_ERR tables
  CHANGES:                   Revision 1.5 2018/09/14 16:17:24CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.4 2018/09/11 16:19:52CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.3 2018/07/31 12:23:59CEST Grosu, George (uidl9584) 
  CHANGES:                   Update ERR after review
  CHANGES:                   Revision 1.2 2018/05/25 08:08:42CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR


**************************************************************************** */

#ifndef C_ERR_VEH_
#define C_ERR_VEH_

#include "LCFERR/LCFERR_VehCustom.h"
#include "lcferr_veh.h"
#include "LCFERR/ERRIO_VehCustom.h"
#include "errio_veh.h"
#include "lcf_veh_iface.h"
#include <string.h>/* memcpy used */


void ERRVEH_srErrQualification(void);
void ERRVEH_srErrReaction(void);
void ERRVEH_srNoError(uint16 ui16ErrIndex, uint1 bErrorDetected);
void ERRVEH_srErrDetected(uint16 ui16ErrIndex, uint1 bErrorDetected);
void ERRVEH_srErrConfirmed(uint16 ui16ErrIndex, uint1 bErrorDetected);
void ERRVEH_srWriteHistory(uint16 ui16ErrIndexParam);
void ERRVEH_srDeleteHistoryLine (uint8 ui8Line);
void ERRVEH_srWriteHistoryLine(uint16 ui16ErrIndexParam);


/* INPUTS */
volatile uint32 S_ERRVEH_ErrMatrix_btf[ERRVEH_enNoOfModules];


/* OUTPUTS */
volatile uint32 S_ERRVEH_ActionFlag_btf;/*  */
volatile uint8 S_ERRVEH_DemEvents_btf;/*  */

/* Internal signals */
volatile LCFERR_ErrStateType_t S_ERRVEH_ErrState_st[C_ERRVEH_NumOfErrors];




/* Public Functions */
void ERRVEH_Reset(void)
{
    /* Initialize all internal signals and outputs */
    uint8 i;

    for(i=0;i<ERRVEH_enNoOfModules;i++)
    {
        /* ToDo: Remove initialization, since is output of other components */
        S_ERRVEH_ErrMatrix_btf[i] = 0u;/* No error at the beggining */
    }
    ERRIOVEH_ResetsigHeaderCnt();
    S_ERRVEH_ActionFlag_btf = 0u;
    S_ERRVEH_DemEvents_btf = 0u;
    
    /* Reset S_ERRVEH_ErrBuff */
    S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf = LCFERR_cui8FaultHistorySize - 1u;
    for (i=0;i<LCFERR_cui8FaultHistorySize;i++)
    {
        S_ERRVEH_ErrBuff.aFaultHistoryBuf[i].ui16ErrorCode = 0u;
		S_ERRVEH_ErrBuff.aFaultHistoryBuf[i].ui16ErrIndex = 0u;
		S_ERRVEH_ErrBuff.aFaultHistoryBuf[i].ui32TimeStamp = 0u;
		S_ERRVEH_ErrBuff.aFaultHistoryBuf[i].eErrState = LCFERR_enNoError;
    }
    
    /* Reset S_ERRVEH_ErrState_st */
    for(i=0;i<C_ERRVEH_NumOfErrors;i++)
    {
        S_ERRVEH_ErrState_st[i].ui16ErrorCode = 0u;
        S_ERRVEH_ErrState_st[i].eErrState = LCFERR_enNoError;
        S_ERRVEH_ErrState_st[i].ui16ErrCntr = 0u;
        S_ERRVEH_ErrState_st[i].bSuppressed = 0u;
    }
	
	/* Clean up actions */
    for (i=0;i<ERRIOVEH_CHECKED_FUNCTIONS_NO;i++)
    {
        SET_ERRIOVEH_ErrStateArray(i, 0);
    }
}


void ERRVEH_srErrReaction(void)
{
    uint8 i;
    
    /* Clean up actions from previous cycle */
    for (i=0;i<ERRIOVEH_CHECKED_FUNCTIONS_NO;i++)
    {
        SET_ERRIOVEH_ErrStateArray(i, 0);
    }
    
	ERRVEH_CustomErrReaction();
	
    /* Take local actions */
    for(i=0;i<C_ERRVEH_NumOfActions;i++)
    {
        if( (S_ERRVEH_ActionFlag_btf & S_ERRVEH_ActionTable[i].ui32ActionMask) !=0 )
        {
            if( S_ERRVEH_ActionTable[i].psrAction != NULL )
            {
                S_ERRVEH_ActionTable[i].psrAction();
            }
        }
    }
    /* Reset for next algo cycle */
    S_ERRVEH_ActionFlag_btf = 0;
    
    /* Check for DEM events */
    for(i=0;i<C_ERRVEH_NumberOfDemEvents;i++)
    {
        if( (S_ERRVEH_DemEvents_btf & (1u<<i)) != 0u)
        {
            /* Report DEM event as active */
            SET_LCFVEH_DEM_EVENT_STATUS(S_ERRVEH_DemEvents[i], DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Report DEM event as passive */
            SET_LCFVEH_DEM_EVENT_STATUS(S_ERRVEH_DemEvents[i], DEM_EVENT_STATUS_PASSED);
        }
    }
    /* Reset for next algo cycle */
    S_ERRVEH_DemEvents_btf = 0u;
}

void ERRVEH_srErrQualification(void)
{
    /* Parse the error matrix */
    uint16 i;
    LCFERR_enErrState_t enCurrErrState;
    uint8 bErrorDetected;
  
    for(i=0u;i<C_ERRVEH_NumOfErrors;i++)
    {
    /* Check every configured error */
        if((S_ERRVEH_ConfigTable[i].ui32CompErrorMask & S_ERRVEH_ErrMatrix_btf[S_ERRVEH_ConfigTable[i].ui8CompCode]) != 0)
        {
            /* Error Detected -> start debouncing */
            bErrorDetected = 1u;
        }
        else
        {
            /* Error not detected -> check for redebounce */
            bErrorDetected = 0u;
        }
        
        enCurrErrState = S_ERRVEH_ErrState_st[i].eErrState;
        
        switch(enCurrErrState)
        {

         case LCFERR_enNoError:
            /* If no event suppression */
            if( S_ERRVEH_ErrState_st[i].bSuppressed != LCFERR_EVENT_SUSPENDED )
            {  
               /* Process no error state */
               ERRVEH_srNoError( i, bErrorDetected);
            }
            else
            {  
               /* Error is suppresed. Detection skipped */
            }
            break;

         case LCFERR_enErrDetected:
            /* If no event suppression  */
            if(S_ERRVEH_ErrState_st[i].bSuppressed != LCFERR_EVENT_SUSPENDED)
            {
               /* Process error detected state */
               ERRVEH_srErrDetected( i, bErrorDetected);
            }
            else
            {  
               /* Error is suppresed. Detection skipped */
            }
            break;
         case LCFERR_enErrConfirmed:  
            /* Process error confirmed state */
            ERRVEH_srErrConfirmed( i, bErrorDetected);
            break;

         default:
            /* Not possible */
            break;

        } 
        
        /* Update Error history */
        ERRVEH_srWriteHistory(i);
    }

}
    

void ERRVEH_srNoError(uint16 ui16ErrIndex, uint1 bErrorDetected)
{
    if(bErrorDetected != 0u)
    {
        S_ERRVEH_ErrState_st[ui16ErrIndex].eErrState = LCFERR_enErrDetected;
        S_ERRVEH_ActionFlag_btf |= S_ERRVEH_ActionTable[S_ERRVEH_ConfigTable[ui16ErrIndex].eActDetErr].ui32ActionMask;
        /* Check if error need a confirmation or not */
        if ( (S_ERRVEH_ConfigTable[ui16ErrIndex].ui16IncValue) 
           < (S_ERRVEH_ConfigTable[ui16ErrIndex].ui16MaxCounter) )    
        {
            /* Transition from No error to Error Detected */
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr = S_ERRVEH_ConfigTable[ui16ErrIndex].ui16IncValue;
        }
        else
        {
            /* ERROR does not need confirmation => call "error detected" function right now */
            ERRVEH_srErrDetected( ui16ErrIndex, bErrorDetected);
        }
    }
    else
    {
        /* Error not detected before or now. Do nothing */
    }
}
    
    
void ERRVEH_srErrDetected(uint16 ui16ErrIndex, uint1 bErrorDetected)
{
    /* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* GeGr: Defensive programming */
    /* PRQA S 2981 1 */
    uint32 ui32NewCounter = 0u;/* Use uint32 variable to avoid overflow */
    
    if(bErrorDetected != 0u)
    {
        /* Increment counter */
        ui32NewCounter = S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr + S_ERRVEH_ConfigTable[ui16ErrIndex].ui16IncValue;
        if(ui32NewCounter >= S_ERRVEH_ConfigTable[ui16ErrIndex].ui16MaxCounter)
        {
            /* Error persist too much */
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr = S_ERRVEH_ConfigTable[ui16ErrIndex].ui16MaxCounter;
            /* Transition from Error Detected -> Error Confirmed */
            S_ERRVEH_ErrState_st[ui16ErrIndex].eErrState = LCFERR_enErrConfirmed;
            S_ERRVEH_ActionFlag_btf |= S_ERRVEH_ActionTable[S_ERRVEH_ConfigTable[ui16ErrIndex].eActConfErr].ui32ActionMask;
            S_ERRVEH_DemEvents_btf |= S_ERRVEH_DemArray[S_ERRVEH_ConfigTable[ui16ErrIndex].eDemEventErr];
        }
        else
        {
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr = (uint16)ui32NewCounter;
        }
    }
    else
    {
        /* Error was detected before, but not this algo cycle */
        if(S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr <= S_ERRVEH_ConfigTable[ui16ErrIndex].ui16DecValue)
        {
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr = 0u;
            /* Counter reached 0. Transition Error Detected -> No Error */
            /* Let's say it was a false alarm */
            S_ERRVEH_ErrState_st[ui16ErrIndex].eErrState = LCFERR_enNoError;
            /* No action for this transition */
            /* No Dem Event */
        }
        else
        {
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr -= S_ERRVEH_ConfigTable[ui16ErrIndex].ui16DecValue;
        }
    }
}

void ERRVEH_srErrConfirmed(uint16 ui16ErrIndex, uint1 bErrorDetected)
{
    /* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* GeGr: Defensive programming */
    /* PRQA S 2981 1 */
    uint32 ui32NewCounter = 0;/* Use uint32 variable to avoid overflow */
    if( (bErrorDetected != 0u)  /* Error still active */
      ||((S_ERRVEH_ConfigTable[ui16ErrIndex].ui8RestCond & LCFERR_REST_AT_IGNITION) == LCFERR_REST_AT_IGNITION) /* Error cannot be redebounced */
      )
    {
        if((S_ERRVEH_ConfigTable[ui16ErrIndex].ui8RestCond & LCFERR_REST_AT_IGNITION) != LCFERR_REST_AT_IGNITION)
        {
            /* Adjust counter */
            ui32NewCounter = S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr + S_ERRVEH_ConfigTable[ui16ErrIndex].ui16IncValue;
            if(ui32NewCounter >= S_ERRVEH_ConfigTable[ui16ErrIndex].ui16MaxCounter)
            {
                S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr = S_ERRVEH_ConfigTable[ui16ErrIndex].ui16MaxCounter;
            }
        }
        
        /* If error is confirmed, report DEM event every algo cycle */
        S_ERRVEH_DemEvents_btf |= S_ERRVEH_DemArray[S_ERRVEH_ConfigTable[ui16ErrIndex].eDemEventErr];
        /* Also, take all configured actions */
        S_ERRVEH_ActionFlag_btf |= S_ERRVEH_ActionTable[S_ERRVEH_ConfigTable[ui16ErrIndex].eActConfErr].ui32ActionMask;
    }
    else
    {
        if(S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr <= S_ERRVEH_ConfigTable[ui16ErrIndex].ui16DecValue)
        {
            /* Counter reached 0. Transition Error Confirmed -> No Error */
            /* A moment of joy: error is gone */
            S_ERRVEH_ErrState_st[ui16ErrIndex].eErrState = LCFERR_enNoError;
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr = 0;
            S_ERRVEH_ActionFlag_btf |= S_ERRVEH_ActionTable[S_ERRVEH_ConfigTable[ui16ErrIndex].eActRestErr].ui32ActionMask;
            /* No Dem Event */
        }
        else
        {
            S_ERRVEH_ErrState_st[ui16ErrIndex].ui16ErrCntr -= S_ERRVEH_ConfigTable[ui16ErrIndex].ui16DecValue;
            /* If error is confirmed, report DEM event every algo cycle */
            S_ERRVEH_DemEvents_btf |= S_ERRVEH_DemArray[S_ERRVEH_ConfigTable[ui16ErrIndex].eDemEventErr];
            /* Also, take all configured actions */
            S_ERRVEH_ActionFlag_btf |= S_ERRVEH_ActionTable[S_ERRVEH_ConfigTable[ui16ErrIndex].eActConfErr].ui32ActionMask;
        }
    }
}


void ERRVEH_Process(void)
{
    ERRVEH_srErrQualification();
    ERRVEH_srErrReaction();
}

void ERRVEH_srWriteHistory(uint16 ui16ErrIndexParam)
{
    /* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /*  GeGr: Defensive programming */
    /* PRQA S 2981 2 */
    uint8 i=0u;
    uint8 bErrorExists = 0u;
    /* Search if current error is already in the buffer */
    i=0u;
    bErrorExists = 0u;
    /*for(i=0u; ( (i<LCFERR_cui8FaultHistorySize) && (0u == bErrorExists) ) ;i++)*/
     while( (i<LCFERR_cui8FaultHistorySize) && (0u == bErrorExists) )
    {
        if(S_ERRVEH_ErrBuff.aFaultHistoryBuf[i].ui16ErrIndex == ui16ErrIndexParam)
        {
            bErrorExists = 1u;
            /* Error already in the buffer. Update status */
            /* Circular buffer->Do not erase in case of no_error->it will be overwritten by a new error when necessary */
            S_ERRVEH_ErrBuff.aFaultHistoryBuf[i].eErrState = S_ERRVEH_ErrState_st[ui16ErrIndexParam].eErrState;
        }
        else
        {
            /* Error not here. Keep searching */
        }
        i++;
    }
    /* Do not write false history. Check if error is indeed active */
    if( (0u == bErrorExists) && (S_ERRVEH_ErrState_st[ui16ErrIndexParam].eErrState == LCFERR_enErrConfirmed) )
    {
        /* Error not in the buffer. Write a new line in the history */
        ERRVEH_srWriteHistoryLine(ui16ErrIndexParam);
    }
}

void ERRVEH_srWriteHistoryLine(uint16 ui16ErrIndexParam)
{
    /* Increment last entry index */
    S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf = ( (S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf + 1) % LCFERR_cui8FaultHistorySize );
    /* Fill each column in Error History */
    S_ERRVEH_ErrBuff.aFaultHistoryBuf[S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf].eErrState = S_ERRVEH_ErrState_st[ui16ErrIndexParam].eErrState;
    S_ERRVEH_ErrBuff.aFaultHistoryBuf[S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf].ui16ErrIndex = ui16ErrIndexParam;
    S_ERRVEH_ErrBuff.aFaultHistoryBuf[S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf].ui16ErrorCode = S_ERRVEH_ConfigTable[ui16ErrIndexParam].ui16ErrorCode;
    S_ERRVEH_ErrBuff.aFaultHistoryBuf[S_ERRVEH_ErrBuff.ui8LastEntryFaultHistoryBuf].ui32TimeStamp = pLcfVehReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    
}




#endif /* C_ERR_VEH_ */
