/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 errio_sen.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.26 $


  ---*/ /*---
  CHANGES:                   $Log: errio_sen.c  $
  CHANGES:                   Revision 1.26 2019/11/26 13:46:34CET Grosu, George (uidl9584) 
  CHANGES:                   Bring changes from TA19 to trunk
  CHANGES:                   Revision 1.25 2019/07/04 14:26:45CEST Grosu, George (uidl9584) 
  CHANGES:                   Update QAF for LCFERR
  CHANGES:                   Revision 1.24 2019/04/16 19:10:21CEST Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Update LCFERR files for TA19
  CHANGES:                   Revision 1.22 2019/03/21 15:38:08CET Grosu, George (uidl9584) 
  CHANGES:                   Overflow bugfix
  CHANGES:                   Revision 1.21 2019/03/13 10:38:37CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.20 2019/03/07 14:51:43CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.19 2018/11/15 08:40:21CET Grosu, George (uidl9584) 
  CHANGES:                   ERR: Add Local Freze Frames for Allive checks
  CHANGES:                   ERR: Temporary: No Dem Event for aalive checks
  CHANGES:                   Revision 1.18 2018/11/03 07:41:20CET Grosu, George (uidl9584) 
  CHANGES:                   Move lcf_sen_iface.h back to 01_SourceCode - step 2
  CHANGES:                   Revision 1.17 2018/11/03 06:23:10CET Grosu, George (uidl9584) 
  CHANGES:                   Move lcf_sen_iface.h back to 01_SourceCode - step1
  CHANGES:                   Revision 1.16 2018/10/31 10:03:57CET Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals for Error Handler
  CHANGES:                   Revision 1.15 2018/10/03 08:58:32CEST Grosu, George (uidl9584) 
  CHANGES:                   Include lcf_sen_iface.h from new location
  CHANGES:                   Revision 1.14 2018/10/02 14:44:39CEST Grosu, George (uidl9584) 
  CHANGES:                   temporary step to move lcf_sen_iface.h
  CHANGES:                   Revision 1.13 2018/09/14 16:17:25CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.12 2018/09/11 16:19:52CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.11 2018/08/05 18:09:15CEST Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals for ERR
  CHANGES:                   Revision 1.10 2018/07/31 12:23:59CEST Grosu, George (uidl9584) 
  CHANGES:                   Update ERR after review
  CHANGES:                   Revision 1.9 2018/05/25 08:08:42CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
  CHANGES:                   Revision 1.8 2018/05/24 13:07:15CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.7 2018/05/22 16:35:37CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files
  CHANGES:                   Revision 1.6 2018/05/18 16:24:18CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix
  CHANGES:                   Revision 1.5 2018/05/18 16:07:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Add Allive counter check
  CHANGES:                   Revision 1.4 2018/05/16 15:46:09CEST Grosu, George (uidl9584) 
  CHANGES:                   Add more checks
  CHANGES:                   Revision 1.3 2018/05/11 09:06:06CEST Grosu, George (uidl9584) 
  CHANGES:                   Error Handler v1
  CHANGES:                   Revision 1.2 2018/05/10 12:30:21CEST Grosu, George (uidl9584) 
  CHANGES:                   First version of LCFERR

**************************************************************************** */
#ifndef C_ERRIO_SEN_
#define C_ERRIO_SEN_
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "LCFERR/ERRIO_SenCustom.h"
#include "LCFERR/LCFERR_SenCustom.h"
#include "lcferr_sen.h"
#include "errio_sen.h"
#include "lcf_sen_iface.h"


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/



/*****************************************************************************
  VARIABLES
*****************************************************************************/
/* Status of input signal checks for each LCF checked function */
uint8 ERRIOSEN_ErrStateArray[ERRIOSEN_CHECKED_FUNCTIONS_NO];/* Initialized in the reset function */


ERRIO_HeaderParser_t  S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadNumber];

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
void ERRIOSEN_srTriggerAFF(uint8 ui8FailedCheck, uint8 ui8Index);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ***********************************************************************
  @fn               ERRIOSEN_CheckSignalSource */ /*!

  @brief            check status of relevant inputs from a particular signal source

  @description      

  @param[in]        sigStateArray array with states for all input signals from this signal source
  @param[in]        configArray   config array that contains the information which signals are relevant for LCF from this signal source
  @param[in]        sigNumber     number of input signals to be checked (configArray size)
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */ 
void ERRIOSEN_CheckSignalSource(const uint8 *sigStateArray, ERRIO_ErrConfigData configArray[], uint8 sigNumber)
{
    uint8 i;
    uint8 j;
    uint16 ui16Function_btf;

    /* For all relevant signals that need to be checked from this signal source */
    for (i = 0; i < sigNumber; i++)
    {
        if (configArray[i].ui8LcfSignalName != LCF_IO_POS_NotAvailable)
        {
            /* ui8LcfSignalName is the position for signal i in sigStateArray */
            if ((sigStateArray[configArray[i].ui8LcfSignalName] != (uint8)LCF_IO_STATE_VALID) &&
                (sigStateArray[configArray[i].ui8LcfSignalName] != (uint8)LCF_IO_STATE_NOTAVAIL)) /* JiYa: NA is for missing Bus signals; corresponding signals are mapped in the NORM with fix(safety) values */
            {
                /* We have an active error */
                /* Increment error debounce counter */
                configArray[i].ui8LcfErrDbcCounter += LCF_ERR_INC_STEP;
                /*Check if the error counter reached the threshold */ 
                if(configArray[i].ui8LcfErrDbcCounter >= LCF_ERR_MAXINC)
                {
                    /* persistent error */
                    configArray[i].ui8ErrorConfirmed_bool = LCF_IS_ERROR;
                    /* Limit counter to maxInc to avoid overflow */
                    configArray[i].ui8LcfErrDbcCounter = LCF_ERR_MAXINC;
                }
                else
                {
                    /* Do nothing. Error in course of qualification */
                }
            }
            else
            {
                /* No active error*/
                if(configArray[i].ui8LcfErrDbcCounter > LCF_ERR_DEC_STEP)
                {
                    /* Redebounce */
                    configArray[i].ui8LcfErrDbcCounter -= LCF_ERR_DEC_STEP;
                }
                else
                {
                    /* Keep it 0 */
                    configArray[i].ui8LcfErrDbcCounter = 0;
                    /* Redebounce counter reached 0: dequalify error */
                    configArray[i].ui8ErrorConfirmed_bool = LCF_NO_ERROR;
                }
            }/* End signal check */
            
            /* Check for qualified error */
            if(configArray[i].ui8ErrorConfirmed_bool != LCF_NO_ERROR)
            {
                /* Error is confirmed. Checked for relevant functions to inform */
                for (j = 0; j < ERRIOSEN_CHECKED_FUNCTIONS_NO; j++)
                    {
                        /* 1 bit of configuration for each function */
                        ui16Function_btf = ((uint16)1u)<<j;
                        /* check if signal is relevant for function */
                        if ((configArray[i].ui16LcfRelevantFct_btf & ui16Function_btf) == ui16Function_btf)
                        {
                            /* Transmit error to error handler */
                            S_ERRSEN_ErrMatrix_btf[ERRSEN_enERRIOSen] |= ui16Function_btf;
                        }
                        else
                        {
                            /* Do nothing. Signal is not relevant for current function */
                        }
                    }
            }
            else
            {
            }
        }
        else
        {
            /* LCF_IO_POS_NotAvailable -> older RTE or function not existing in current version */
            /* ignore position */
        }
    }
}


/* L3D_ALGO_22428 */
/* Signal header timestamp and measurement counter checks shall be conducted. Checks only apply for non-static signals (excluding e.g. CPAR, PPAR inputs) another exception are algo learning values during the reset op-mode. Measurement counters and timestamps have to increase monotonically (but not strictly monotonically). Be aware of possible wrap arounds. In comparison to the timestamp of the base control input no timestamp shall be older then 'ALGO_FUSI_DEBOUNCE_TIME'. For image inputs the measurement counter shall be checked for equality (or being smaller by 2 if the image is designated to be from the previous cycle) to the one from the base control data. In case the check fails the component shall enter an error state and the 'XXX_FUSI_ERROR' DEM event shall be issued. */

void ERRIOSEN_ResetsigHeaderCnt(void)
{
    uint8 i;
    for(i=0;i<ERRIOSEN_enSigHeadNumber;i++)
    {
        S_ERRIOSEN_sigHeader[i].oldCycleCounter = 0;
        S_ERRIOSEN_sigHeader[i].oldMeasurementCounter = 0;
        S_ERRIOSEN_sigHeader[i].oldTimeStamp = 0;
        S_ERRIOSEN_sigHeader[i].constantCycles = 0;
        S_ERRIOSEN_sigHeader[i].MaxConstantCycles = ERRSEN_MAX_CONSTANT_CYCLES;/* (S_LCFRCV_SysCycleTimeSen_sec / S_LCFRCV_SysCycleTimeVeh_sec) + 1*/
		S_ERRIOSEN_sigHeader[i].MaxOvrflCycles = ERRSEN_MAX_CONSTANT_CYCLES;
        S_ERRIOSEN_sigHeader[i].sigHead = NULL;
        S_ERRIOSEN_sigHeader[i].EnableChecking_btf = 255;
    }
    S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadBCD].MaxConstantCycles = 30;
    ERRIOSEN_ResetSigHdrConstCycles();
    
}


void ERRIOSEN_CheckAllive(void)
{
    uint8 i;
    if(pLcfSenReqPorts != NULL)
    {
        ERRIOSEN_SenSetHeader(pLcfSenReqPorts);
    }
    SET_ERRIOSEN_AlliveError(0);
    
    for(i=1;i<ERRIOSEN_enSigHeadNumber;i++)/* GeGr: ignore BaseCtrlData */
    {
        if(S_ERRIOSEN_sigHeader[i].sigHead != NULL)
        {
            /* Check Measurement Counter */
            if( ( (S_ERRIOSEN_sigHeader[i].EnableChecking_btf & ERRIOSEN_CHECK_MC) == ERRIOSEN_CHECK_MC ) &&
                  (S_ERRIOSEN_sigHeader[i].sigHead->uiMeasurementCounter < S_ERRIOSEN_sigHeader[i].oldMeasurementCounter) )
			{
				/* Check overflow */
				if( ((LCF_MAX_ALGO_CYCLE_CNT - S_ERRIOSEN_sigHeader[i].oldMeasurementCounter) + S_ERRIOSEN_sigHeader[i].sigHead->uiMeasurementCounter)	> S_ERRIOSEN_sigHeader[i].MaxOvrflCycles )
				{
					/* Measurement counter is decreased. Bad boy. */
					SET_ERRIOSEN_AlliveError(GET_ERRIOSEN_AlliveError() | ERRIOSEN_ALLIVE_MC_FAIL);
					ERRIOSEN_srTriggerAFF(ERRIOSEN_ALLIVE_MC_FAIL,i);
					SET_D_LCFERR_AlliveFailedMC_btf(i);
				}
				else
				{
					/* Measurement counter increased with less than several cycles -> looks like a normal overflow */
					/* Controlled overflow. Everything is ok */
				}
            }
            
            /* Check Timestamp is monotonically increasing */
            if(( (S_ERRIOSEN_sigHeader[i].EnableChecking_btf & ERRIOSEN_CHECK_TS) == ERRIOSEN_CHECK_TS ) &&
                 (S_ERRIOSEN_sigHeader[i].sigHead->uiTimeStamp < S_ERRIOSEN_sigHeader[i].oldTimeStamp) )
            {
				if( ((LCF_MAX_TIMESTAMP - S_ERRIOSEN_sigHeader[i].oldTimeStamp) + S_ERRIOSEN_sigHeader[i].sigHead->uiTimeStamp)	> (10*ALGO_FUSI_DEBOUNCE_TIME) )
				{
					/* Timestamp is decreased. Bad boy. */
					SET_ERRIOSEN_AlliveError(GET_ERRIOSEN_AlliveError() | ERRIOSEN_ALLIVE_TS_FAIL);
					ERRIOSEN_srTriggerAFF(ERRIOSEN_ALLIVE_TSMON_FAIL,i);
					SET_D_LCFERR_AlliveFailedTSMon_btf(i);
				}
				else
				{
					/* Timestamp increased with less than several cycles -> looks like a normal overflow */
					/* Controlled overflow. Everything is ok */
				}
            }
            
            /* Check how old is the timestap, relative to Base Ctrl Data */
            if(( (S_ERRIOSEN_sigHeader[i].EnableChecking_btf & ERRIOSEN_CHECK_TS) == ERRIOSEN_CHECK_TS ) &&
             (((S_ERRIOSEN_sigHeader[i].sigHead->uiTimeStamp)  < (S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp - (uint32)ALGO_FUSI_DEBOUNCE_TIME))
              && ((S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp) > (ALGO_FUSI_DEBOUNCE_TIME)) ))/* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */
            {
				/* GeGr: Take care of inputs newer than BCD, exactly at the input overflow momment */
				if( ((LCF_MAX_TIMESTAMP - S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp) + S_ERRIOSEN_sigHeader[i].sigHead->uiTimeStamp)	> 10*ALGO_FUSI_DEBOUNCE_TIME )/* Choose a tolerance for how new the timestamp can be 10x debounce time should suffice */
				{
					/* Timestamp is too old. Bad boy. */
					SET_ERRIOSEN_AlliveError(GET_ERRIOSEN_AlliveError() | ERRIOSEN_ALLIVE_TS_FAIL);
					ERRIOSEN_srTriggerAFF(ERRIOSEN_ALLIVE_TSBCD_FAIL,i);
					SET_D_LCFERR_AlliveFailedTSBcd_btf(i);
				}
            }
            
            /* Check if cycle counter is monotonically increasing */
            if((S_ERRIOSEN_sigHeader[i].EnableChecking_btf & ERRIOSEN_CHECK_CC) == ERRIOSEN_CHECK_CC )
            {
                if(S_ERRIOSEN_sigHeader[i].sigHead->uiCycleCounter < S_ERRIOSEN_sigHeader[i].oldCycleCounter)
                {
                    /* Check for wrap around */
					if( ((LCF_MAX_ALGO_CYCLE_CNT - S_ERRIOSEN_sigHeader[i].oldCycleCounter) + S_ERRIOSEN_sigHeader[i].sigHead->uiCycleCounter)	> S_ERRIOSEN_sigHeader[i].MaxOvrflCycles )
					{
						/* Cycle counter is decreased. Bad boy. */
                        SET_ERRIOSEN_AlliveError(GET_ERRIOSEN_AlliveError() | ERRIOSEN_ALLIVE_CC_FAIL);
                        ERRIOSEN_srTriggerAFF(ERRIOSEN_ALLIVE_CC_FAIL,i);
                        SET_D_LCFERR_AlliveFailedCCMon_btf(i);
					}
					else
					{
						/* Cycle counter increased with less than several cycles -> looks like a normal overflow */
						/* Controlled overflow. Everything is ok */
						S_ERRIOSEN_sigHeader[i].constantCycles = 0;
					}
                }
                else
                {
                    if(S_ERRIOSEN_sigHeader[i].sigHead->uiCycleCounter == S_ERRIOSEN_sigHeader[i].oldCycleCounter)
                    {
                        /* Yellow Alert. Constant cycleCounter */
                        S_ERRIOSEN_sigHeader[i].constantCycles ++;
                        if(S_ERRIOSEN_sigHeader[i].constantCycles > S_ERRIOSEN_sigHeader[i].MaxConstantCycles)
                        {
                            /* Red Alert */
                            SET_ERRIOSEN_AlliveError(GET_ERRIOSEN_AlliveError() | ERRIOSEN_ALLIVE_CC_FAIL);
                            ERRIOSEN_srTriggerAFF(ERRIOSEN_ALLIVE_CC_FAIL,i);
                            SET_D_LCFERR_AlliveFailedCCConst_btf(i);
                        }
                        else
                        {
                            /* Keep counting cycles. The moment will come */
                        }
                    }
                    else
                    {
                        /* Strictly monotonically. Good boy */
                        S_ERRIOSEN_sigHeader[i].constantCycles = 0;
                    }
                }
            }
            else
            {
                /* Do nothing. Do not check for Cycle Counters */
            }
            S_ERRIOSEN_sigHeader[i].oldCycleCounter = S_ERRIOSEN_sigHeader[i].sigHead->uiCycleCounter;
            S_ERRIOSEN_sigHeader[i].oldMeasurementCounter = S_ERRIOSEN_sigHeader[i].sigHead->uiMeasurementCounter;
            S_ERRIOSEN_sigHeader[i].oldTimeStamp = S_ERRIOSEN_sigHeader[i].sigHead->uiTimeStamp;
        }
    }
}

void ERRIOSEN_srTriggerAFF(uint8 ui8FailedCheck, uint8 ui8Index)
{
    static uint8 ui8SavedFF = 0u;
    if(ui8FailedCheck == ERRIOSEN_ALLIVE_TSMON_FAIL)
    {
        if((ui8SavedFF & 0x01u) == 0u)
        {   
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][0] = ui8FailedCheck;
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][1] = ui8Index;
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][2] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][3] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][4] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][5] = (uint8)(S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0x000000FFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][6] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].oldTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][7] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].oldTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][8] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].oldTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsMon][9] = (uint8)(S_ERRIOSEN_sigHeader[ui8Index].oldTimeStamp&0x000000FFu);
            ui8SavedFF |= 0x01u;
        }
    }
    else if (ui8FailedCheck == ERRIOSEN_ALLIVE_TSBCD_FAIL)
    {
        if((ui8SavedFF & 0x02u) == 0u)
        { 
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][0] = ui8FailedCheck;
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][1] = ui8Index;
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][2] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][3] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][4] = (uint8)(((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][5] =  (uint8)(S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiTimeStamp&0x000000FFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][6] = (uint8)(((S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][7] = (uint8)(((S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][8] = (uint8)(((S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRSEN_AFFtb[ERRSEN_enFFTsBcd][9] =  (uint8)(S_ERRIOSEN_sigHeader[0].sigHead->uiTimeStamp&0x000000FFu);
            ui8SavedFF |= 0x02u;
        }
    }
    else
    {
         if((ui8SavedFF & 0x04u) == 0u)
        { 
            ERRSEN_AFFtb[ERRSEN_enFFCnt][0] = ui8FailedCheck;
            ERRSEN_AFFtb[ERRSEN_enFFCnt][1] = ui8Index;
            ERRSEN_AFFtb[ERRSEN_enFFCnt][2] = (uint8)(((uint16)((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiMeasurementCounter&0xFF00u) >> 8u))&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][3] =(uint8)( S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiMeasurementCounter&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][4] = (uint8)(((uint16)((S_ERRIOSEN_sigHeader[ui8Index].oldMeasurementCounter&0xFF00u) >> 8u))&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][5] =(uint8)( S_ERRIOSEN_sigHeader[ui8Index].oldMeasurementCounter&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][6] = (uint8)(((uint16)((S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiCycleCounter&0xFF00u) >> 8u))&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][7] = (uint8)(S_ERRIOSEN_sigHeader[ui8Index].sigHead->uiCycleCounter&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][8] = (uint8)(((uint16)((S_ERRIOSEN_sigHeader[ui8Index].oldCycleCounter&0xFF00u) >> 8u))&0x00FFu);
            ERRSEN_AFFtb[ERRSEN_enFFCnt][9] = (uint8)(S_ERRIOSEN_sigHeader[ui8Index].oldCycleCounter&0x00FFu);
            ui8SavedFF |= 0x04u;
        }
        
    }
}

#endif /* C_ERRIO_SEN_ */

