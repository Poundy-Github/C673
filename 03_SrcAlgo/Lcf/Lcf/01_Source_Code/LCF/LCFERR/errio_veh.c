/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 errio_veh.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.12 $


  ---*/ /*---
  CHANGES:                   $Log: errio_veh.c  $
  CHANGES:                   Revision 1.12 2020/01/14 11:36:35CET Grosu, George (uidl9584) 
  CHANGES:                   adapt ALGO_FUSI_DEBOUNCE_TIME
  CHANGES:                   fix some qaf findings
  CHANGES:                   Revision 1.11 2019/11/26 13:46:33CET Grosu, George (uidl9584) 
  CHANGES:                   Bring changes from TA19 to trunk
  CHANGES:                   Revision 1.10 2019/07/04 14:26:46CEST Grosu, George (uidl9584) 
  CHANGES:                   Update QAF for LCFERR
  CHANGES:                   Revision 1.9 2019/04/16 19:10:21CEST Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Update LCFERR files for TA19
  CHANGES:                   Revision 1.7 2019/03/21 15:38:07CET Grosu, George (uidl9584) 
  CHANGES:                   Overflow bugfix
  CHANGES:                   Revision 1.6 2019/03/07 14:51:42CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.5 2018/09/14 16:17:25CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.4 2018/09/11 16:19:51CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.3 2018/07/31 12:24:00CEST Grosu, George (uidl9584) 
  CHANGES:                   Update ERR after review
  CHANGES:                   Revision 1.2 2018/05/25 08:08:42CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR


**************************************************************************** */
#ifndef C_ERRIO_VEH_
#define C_ERRIO_VEH_
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "LCFERR/ERRIO_VehCustom.h"
#include "LCFERR/LCFERR_VehCustom.h"
#include "lcferr_veh.h"
#include "errio_veh.h"
#include "lcf_veh_iface.h"


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/



/*****************************************************************************
  VARIABLES
*****************************************************************************/
/* Status of input signal checks for each LCF checked function */
uint8 ERRIOVEH_ErrStateArray[ERRIOVEH_CHECKED_FUNCTIONS_NO];


ERRIO_HeaderParser_t  S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadNumber];

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
void ERRIOVEH_srTriggerAFF(uint8 ui8FailedCheck, uint8 ui8Index);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ***********************************************************************
  @fn               ERRIOVEH_CheckSignalSource */ /*!

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
void ERRIOVEH_CheckSignalSource(const uint8 *const sigStateArray, ERRIO_ErrConfigData configArray[], const uint8 sigNumber)
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
                for (j = 0u; j < ERRIOVEH_CHECKED_FUNCTIONS_NO; j++)
                    {
                        /* 1 bit of configuration for each function */
                        ui16Function_btf = ((uint16)1u)<<j;
                        /* check if signal is relevant for function */
                        if ((configArray[i].ui16LcfRelevantFct_btf & ui16Function_btf) == ui16Function_btf)
                        {
                            /* Transmit error to error handler */
                            S_ERRVEH_ErrMatrix_btf[ERRVEH_enERRIOVeh] |= ui16Function_btf;
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

void ERRIOVEH_ResetsigHeaderCnt(void)
{
    uint8 i;
    for(i=0;i<ERRIOVEH_enSigHeadNumber;i++)
    {
        S_ERRIOVEH_sigHeader[i].oldCycleCounter = 0;
        S_ERRIOVEH_sigHeader[i].oldMeasurementCounter = 0;
        S_ERRIOVEH_sigHeader[i].oldTimeStamp = 0;
        S_ERRIOVEH_sigHeader[i].constantCycles = 0;
        S_ERRIOVEH_sigHeader[i].MaxConstantCycles = ERRVEH_MAX_CONSTANT_CYCLES;/* (S_LCFRCV_SysCycleTimeSen_sec / S_LCFRCV_SysCycleTimeVeh_sec) + 1*/
		S_ERRIOVEH_sigHeader[i].MaxOvrflCycles = ERRVEH_MAX_CONSTANT_CYCLES;
        S_ERRIOVEH_sigHeader[i].sigHead = NULL;
        S_ERRIOVEH_sigHeader[i].EnableChecking_btf = 255;
    }
    ERRIOVEH_ResetSigHdrConstCycles();
    
}


void ERRIOVEH_CheckAllive(void)
{
    uint8 i;
    if(pLcfVehReqPorts != NULL)
    {
        ERRIOVEH_VehSetHeader(pLcfVehReqPorts);
    }
    SET_ERRIOVEH_AlliveError(0);
    
    for(i=1;i<ERRIOVEH_enSigHeadNumber;i++)/* GeGr: ignore BaseCtrlData */
    {
        if(S_ERRIOVEH_sigHeader[i].sigHead != NULL)
        {
            /* Check Measurement Counter */
            if( ( (S_ERRIOVEH_sigHeader[i].EnableChecking_btf & ERRIOVEH_CHECK_MC) == ERRIOVEH_CHECK_MC ) &&
                  (S_ERRIOVEH_sigHeader[i].sigHead->uiMeasurementCounter < S_ERRIOVEH_sigHeader[i].oldMeasurementCounter) )
            {
				/* Check overflow */
				if( ((LCF_MAX_ALGO_CYCLE_CNT - S_ERRIOVEH_sigHeader[i].oldMeasurementCounter) + S_ERRIOVEH_sigHeader[i].sigHead->uiMeasurementCounter)	> S_ERRIOVEH_sigHeader[i].MaxOvrflCycles )
				{
					/* Measurement counter is decreased. Bad boy. */
					SET_ERRIOVEH_AlliveError(GET_ERRIOVEH_AlliveError() | ERRIOVEH_ALLIVE_MC_FAIL);
					ERRIOVEH_srTriggerAFF(ERRIOVEH_ALLIVE_MC_FAIL,i);
					SET_D_LCFERR_AlliveFailedMC_btf(i);
				}
				else
				{
					/* Measurement counter increased with less than several cycles -> looks like a normal overflow */
					/* Controlled overflow. Everything is ok */
				}
            }
            
            /* Check Timestamp is monotonically increasing */
            if(( (S_ERRIOVEH_sigHeader[i].EnableChecking_btf & ERRIOVEH_CHECK_TS) == ERRIOVEH_CHECK_TS ) &&
                 (S_ERRIOVEH_sigHeader[i].sigHead->uiTimeStamp < S_ERRIOVEH_sigHeader[i].oldTimeStamp) )
            {
				if( ((LCF_MAX_TIMESTAMP - S_ERRIOVEH_sigHeader[i].oldTimeStamp) + S_ERRIOVEH_sigHeader[i].sigHead->uiTimeStamp)	> (ALGO_LCF_FUSI_DEBOUNCE_TIME) )
				{
					/* Timestamp is decreased. Bad boy. */
                	SET_ERRIOVEH_AlliveError(GET_ERRIOVEH_AlliveError() | ERRIOVEH_ALLIVE_TS_FAIL);
					ERRIOVEH_srTriggerAFF(ERRIOVEH_ALLIVE_TSMON_FAIL,i);
					SET_D_LCFERR_AlliveFailedTSMon_btf(i);
				}
				else
				{
					/* Timestamp increased with less than several cycles -> looks like a normal overflow */
					/* Controlled overflow. Everything is ok */
				}
            }
            
            /* Check how old is the timestap, relative to Base Ctrl Data */
            if(( (S_ERRIOVEH_sigHeader[i].EnableChecking_btf & ERRIOVEH_CHECK_TS) == ERRIOVEH_CHECK_TS ) &&
             (((S_ERRIOVEH_sigHeader[i].sigHead->uiTimeStamp)  < (S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp - (uint32)ALGO_LCF_FUSI_DEBOUNCE_TIME))
              && ((S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp) > (ALGO_LCF_FUSI_DEBOUNCE_TIME)) ))/* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */
            {
				/* GeGr: Take care of inputs newer than BCD, exactly at the input overflow momment */
				if( ((LCF_MAX_TIMESTAMP - S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp) + S_ERRIOVEH_sigHeader[i].sigHead->uiTimeStamp)	> ALGO_LCF_FUSI_DEBOUNCE_TIME )/* Choose a tolerance for how new the timestamp can be 10x debounce time should suffice */
				{
                /* Timestamp is decreased. Bad boy. */
                SET_ERRIOVEH_AlliveError(GET_ERRIOVEH_AlliveError() | ERRIOVEH_ALLIVE_TS_FAIL);
                ERRIOVEH_srTriggerAFF(ERRIOVEH_ALLIVE_TSBCD_FAIL,i);
                SET_D_LCFERR_AlliveFailedTSBcd_btf(i);
				}
            }
            
            /* Check if cycle counter is monotonically increasing */
            if((S_ERRIOVEH_sigHeader[i].EnableChecking_btf & ERRIOVEH_CHECK_CC) == ERRIOVEH_CHECK_CC )
            {
                if(S_ERRIOVEH_sigHeader[i].sigHead->uiCycleCounter < S_ERRIOVEH_sigHeader[i].oldCycleCounter)
                {
                    /* Check for wrap around */
					if( ((LCF_MAX_ALGO_CYCLE_CNT - S_ERRIOVEH_sigHeader[i].oldCycleCounter) + S_ERRIOVEH_sigHeader[i].sigHead->uiCycleCounter)	> S_ERRIOVEH_sigHeader[i].MaxOvrflCycles )
					{
                        /* Cycle counter is decreased. Bad boy. */
                        SET_ERRIOVEH_AlliveError(GET_ERRIOVEH_AlliveError() | ERRIOVEH_ALLIVE_CC_FAIL);
                        ERRIOVEH_srTriggerAFF(ERRIOVEH_ALLIVE_CC_FAIL,i);
                        SET_D_LCFERR_AlliveFailedCCMon_btf(i);
                    }
                    else
                    {
						/* Cycle counter increased with less than several cycles -> looks like a normal overflow */
						/* Controlled overflow. Everything is ok */
                        S_ERRIOVEH_sigHeader[i].constantCycles = 0;
                    }
                }
                else
                {
                    if(S_ERRIOVEH_sigHeader[i].sigHead->uiCycleCounter == S_ERRIOVEH_sigHeader[i].oldCycleCounter)
                    {
                        /* Yellow Alert. Constant cycleCounter */
                        S_ERRIOVEH_sigHeader[i].constantCycles ++;
                        if(S_ERRIOVEH_sigHeader[i].constantCycles > S_ERRIOVEH_sigHeader[i].MaxConstantCycles)
                        {
                            /* Red Alert */
                            SET_ERRIOVEH_AlliveError(GET_ERRIOVEH_AlliveError() | ERRIOVEH_ALLIVE_CC_FAIL);
                            ERRIOVEH_srTriggerAFF(ERRIOVEH_ALLIVE_CC_FAIL,i);
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
                        S_ERRIOVEH_sigHeader[i].constantCycles = 0;
                    }
                }
            }
            else
            {
                /* Do nothing. Do not check for Cycle Counters */
            }
            S_ERRIOVEH_sigHeader[i].oldCycleCounter = S_ERRIOVEH_sigHeader[i].sigHead->uiCycleCounter;
            S_ERRIOVEH_sigHeader[i].oldMeasurementCounter = S_ERRIOVEH_sigHeader[i].sigHead->uiMeasurementCounter;
            S_ERRIOVEH_sigHeader[i].oldTimeStamp = S_ERRIOVEH_sigHeader[i].sigHead->uiTimeStamp;
        }
    }
}

void ERRIOVEH_srTriggerAFF(uint8 ui8FailedCheck, uint8 ui8Index)
{
    static uint8 ui8SavedFF = 0u;
    if(ui8FailedCheck == ERRIOVEH_ALLIVE_TSMON_FAIL)
    {
        if((ui8SavedFF & 0x01u) == 0u)
        {   
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][0] = ui8FailedCheck;
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][1] = ui8Index;
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][2] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][3] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][4] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][5] = (uint8)( S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0x000000FFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][6] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].oldTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][7] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].oldTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][8] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].oldTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsMon][9] = (uint8)(S_ERRIOVEH_sigHeader[ui8Index].oldTimeStamp&0x000000FFu);
            ui8SavedFF |= 0x01u;
        }
    }
    else if (ui8FailedCheck == ERRIOVEH_ALLIVE_TSBCD_FAIL)
    {
        if((ui8SavedFF & 0x02u) == 0u)
        { 
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][0] = ui8FailedCheck;
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][1] = ui8Index;
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][2] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][3] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][4] = (uint8)(((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][5] = (uint8)(S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiTimeStamp&0x000000FFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][6] = (uint8)(((S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp&0xFF000000u) >> 24)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][7] = (uint8)(((S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp&0x00FF0000u) >> 16)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][8] = (uint8)(((S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp&0x0000FF00u) >> 8)&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFTsBcd][9] = (uint8)(S_ERRIOVEH_sigHeader[0].sigHead->uiTimeStamp&0x000000FFu);
            ui8SavedFF |= 0x02u;
        }
    }
    else
    {
         if((ui8SavedFF & 0x04u) == 0u)
        { 
            ERRVEH_AFFtb[ERRVEH_enFFCnt][0] = ui8FailedCheck;
            ERRVEH_AFFtb[ERRVEH_enFFCnt][1] = ui8Index;
            ERRVEH_AFFtb[ERRVEH_enFFCnt][2] = (uint8)(((uint16)((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiMeasurementCounter&0xFF00u) >> 8))&0x00FFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][3] = (uint8)(S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiMeasurementCounter&0x00FFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][4] = (uint8)(((uint16)((S_ERRIOVEH_sigHeader[ui8Index].oldMeasurementCounter&0xFF00u) >> 8))&0x00FFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][5] = (uint8)(S_ERRIOVEH_sigHeader[ui8Index].oldMeasurementCounter&0x00FFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][6] = (uint8)(((uint16)((S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiCycleCounter&0xFF00u) >> 8))&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][7] = (uint8)(S_ERRIOVEH_sigHeader[ui8Index].sigHead->uiCycleCounter&0x00FFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][8] = (uint8)(((uint16)((S_ERRIOVEH_sigHeader[ui8Index].oldCycleCounter&0xFF00u) >> 8))&0xFFu);
            ERRVEH_AFFtb[ERRVEH_enFFCnt][9] = (uint8)(S_ERRIOVEH_sigHeader[ui8Index].oldCycleCounter&0x00FFu);
            ui8SavedFF |= 0x04u;
        }
        
    }
}

#endif /* C_ERRIO_VEH_ */

