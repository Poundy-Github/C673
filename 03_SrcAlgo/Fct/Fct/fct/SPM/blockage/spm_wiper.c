/*! \file *******************************************************************
// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.3 $

---*/ /*---
CHANGES:                   $Log: spm_wiper.c  $
CHANGES:                   Revision 1.3 2020/07/01 07:38:51CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix empty C file warning
CHANGES:                   Revision 1.2 2020/06/25 08:13:47CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.1 2018/09/24 14:55:12CEST Pallo, Istvan (palloi) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/SPM/blockage/project.pj


*****************************************************************************/

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "spm_par.h"
#include "spm.h"

/*if wiper adapter is on, adapt blockage state depending on wiper signal*/
#if((SPM_CFG_USE_WIPER_ADAPT == SWITCH_ON) && (SPM_SRR_TECHNOLOGY == SWITCH_ON))
#if defined __cplusplus
extern "C"{
#endif
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/
SPMWiperData_t  SPMWiperData;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/  
/// Calculate the Blockage probabiltiy
///
/// @pre                    None
/// @post                   None 
/// @param[in]              eSPMBlockageState            Current Blockage state
///
/// @return                 -
///
/// @InOutCorrelation       Calculate the Blockage probabiltiy and maped the vlaue 0.0 - 1.0  to 1 - 10
///                                                
static uint8 SPMWiperComputeBlckProbability (const eBlockageStates_t eSPMBlockageState);
/// Check if the Wiper timer delay is reached to allow the Blockage
///
/// @pre                    None
/// @post                   None 
/// @param[in]              uInputWiperState   Input Wiper State Signal            
/// @param[in]              fWiperDelay        Algo Parmeter Blockage Wipere Delay in sec (vary between 0 and 180 seconds)     
/// @param[in]              bWiperPermit       Current Wiper permit state     
/// @param[in]              fCurrCycleTime     Cycletime
///
/// @return                 fBlockageProbability       Wiper permit state (True if Wiper  delay time is exceeded)
///
/// @InOutCorrelation       Check if the Wiper timer delay is reached to allow the Blockage
///   
static boolean SPMWiperPermit (      uint8   uInputWiperState,
                               const float32 fWiperDelay,
                               const boolean bWiperPermit,
                               const fTime_t fCurrCycleTime);
/// Check if Blockage Verification Timer is exit
///
/// @pre                    None
/// @post                   None 
/// @param[in]              fBlockage1VerificationTime Algo Parameter Blockage Verification Time Minimum Blockage Alert Time              
/// @param[in]              bExtendBlockageState       Current state of the Extended Blockage Timer      
/// @param[in]              eSPMBlockageState          Current Blockage state 
/// @param[in]              fCurrCycleTime             Current cycletime
///
/// @return                 bReturnValue       Wiper permit state (True if Wiper  delay time is exceeded)
///
/// @InOutCorrelation       Check if Blockage Verification Timer is exit
///   
static boolean SPMWiperExtendBlockageState (const float32 fBlockage1VerificationTime,
                                            const boolean bExtendBlockageState,
                                            const eBlockageStates_t eSPMBlockageState,
                                            const fTime_t fCurrCycleTime);
/// Set Wiper partial blockage state
///
/// @pre                    None
/// @post                   None 
/// @param[in]              bWiperPermit             
/// @param[in]              bLastWiperPermit             
/// @param[in]              bPartialBlockageState             
/// @param[in]              eSPMBlockageState            
/// @param[in]              fCurrCycleTime
///
/// @return                 bTempPatialBlockageState       Partial Blockage State
///
/// @InOutCorrelation       Set Wiper partial blockage state
///   
static boolean SPMWiperPartialBlockageState (const uint8   uBlockageProbability,
                                             const boolean bWiperPermit,
                                             const boolean bLastWiperPermit,
                                             const boolean bPartialBlockageState,
                                             const fTime_t fCurrCycleTime);
/// Wiper Blockage Hold Off
///
/// @pre                    None
/// @post                   None 
/// @param[in]              bWiperPermit              Wiper Permit       
/// @param[in]              bPartialBlockageState     Partial Blockage state           
/// @param[in]              eSPMBlockageState         Current Blockage state
///
/// @return                 bReturnValue       Return TRUE or FALSE
///
/// @InOutCorrelation       Wiper Blockage Hold Off
///   
static boolean SPMWiperBlockageHoldOff (const boolean bWiperPermit,
                                        const boolean bPartialBlockageState,
                                        const eBlockageStates_t eSPMBlockageState);
/// Wiper Blockage Hold On
///
/// @pre                    None
/// @post                   None 
/// @param[in]              bExtendblockage
///
/// @return                 bReturnValue       Return TRUE or FALSE
///
/// @InOutCorrelation       Wiper Blockage Hold On
///   
static boolean SPMWiperBlockageHoldOn (const boolean bExtendblockage);



/********************************************************

  Functionname:           SPMInitWiperData
  
  @brief                  Initializing of SPM Wiper data

*//************************************************************************/
void SPMInitWiperData(void)
{
  SPMWiperData.bBlockageWiperPermit      = FALSE;
  SPMWiperData.bExtendblockage           = TRUE;
  SPMWiperData.bLastBlockageWiperPermit  = FALSE;
  SPMWiperData.bPartialBlockage          = FALSE;
  SPMWiperData.fBlockageWiperPermitTimer = 0.0F;
  SPMWiperData.fExtendBlockageTimer      = 0.0F;
  SPMWiperData.fPartialBlockageTimer     = 0.0F;
}

/********************************************************

  Functionname:           SPMWiperAdaptBlockageState
  
  @brief                  Adapt the Belockage event

*//************************************************************************/
void SPMWiperAdaptBlockageState (const float32 fWiperDelay,
                                 const float32 fBlockage1VerificationTime,
                                 const eBlockageStates_t eSPMBlockageState,
                                 const fTime_t fCurrCycleTime,
                                       uint8 *uBlockageProbability)
{
  WiperState_t SPMWiperstate = GET_EGO_VEH_SIG_PTR->VehSigAdd.WiperState;
 
  /*calculate the Blockage probabiltiy of the different Blockage Observer
    (Timeout, Range and Objectloss observer and use the Max value of the three observer*/
  *uBlockageProbability = SPMWiperComputeBlckProbability (eSPMBlockageState);
  
  /* wiper state management */
  SPMWiperData.bBlockageWiperPermit = SPMWiperPermit (SPMWiperstate, 
                                                      fWiperDelay, 
                                                      SPMWiperData.bBlockageWiperPermit, 
                                                      fCurrCycleTime);

  /* blockage minimum warning time management */
  SPMWiperData.bExtendblockage = SPMWiperExtendBlockageState (fBlockage1VerificationTime, 
                                                              SPMWiperData.bExtendblockage, 
                                                              eSPMBlockageState, 
                                                              fCurrCycleTime);
  
  /* partial blockage time management */
  SPMWiperData.bPartialBlockage = SPMWiperPartialBlockageState (*uBlockageProbability,
                                                                SPMWiperData.bBlockageWiperPermit,
                                                                SPMWiperData.bLastBlockageWiperPermit,
                                                                SPMWiperData.bPartialBlockage,
                                                                fCurrCycleTime);

  SPMWiperData.bLastBlockageWiperPermit = SPMWiperData.bBlockageWiperPermit;
  
  /* Blockage overrides */
  SPMData.bWiperBlockageHoldOff = SPMWiperBlockageHoldOff (SPMWiperData.bBlockageWiperPermit,
                                                           SPMWiperData.bPartialBlockage,
                                                           eSPMBlockageState);
 
 
 SPMData.bWiperBlockageHoldOn   = SPMWiperBlockageHoldOn (SPMWiperData.bExtendblockage);

}

/********************************************************

  Functionname:           SPMWiperComputeBlckProbability
  
  @brief                  Calculate the Blockage probabiltiy

*//************************************************************************/
static uint8 SPMWiperComputeBlckProbability (const eBlockageStates_t eSPMBlockageState)
{
   /**/
  float32 fBlockageProbability = 0.0F;
  float32 fWayCounterPercent   = 0.0F;
  float32 fTimeCounterpercent  = 0.0F;
  float32 fRangePercent        = 0.0F;
  float32 fObjectLossPercent   = 0.0F;

  
  /* Full Blockage distance ('way') counter (percent)*/
  if(SPMBlockageParameters.fTimeoutShutOffWay > C_F32_DELTA)
  {
    fWayCounterPercent = SPMData.SPMBlockageTimeoutWayCounter/SPMBlockageParameters.fTimeoutShutOffWay;
  }
  fWayCounterPercent = MINMAX_FLOAT(0.0F,1.0F,fWayCounterPercent);

  /* Full Blockage timer counter (percent)*/
  if(SPMBlockageParameters.fTimeoutShutOffTime > C_F32_DELTA)
  {
    fTimeCounterpercent =  SPMData.SPMBlockageTimeoutTimeCounter/SPMBlockageParameters.fTimeoutShutOffTime;
  }
  fTimeCounterpercent = MINMAX_FLOAT(0.0F,1.0F,fTimeCounterpercent);
  fBlockageProbability = MAX_FLOAT(fWayCounterPercent, fTimeCounterpercent);

  /* Range (percent) */
  if(eSPMBlockageState == FCT_FULL_BLOCKAGE)
  {
    if(SPM_BLOCKAGE_REACTIVATION_DELAY > C_F32_DELTA)
    {
      fRangePercent = 1.0F - (SPMData.SPMBSDRangeDeterminationCounter * (1.0F/SPM_BLOCKAGE_REACTIVATION_DELAY));
    }
  }
  else
  { 
    if(SPMBlockageParameters.fBSDRangeHoldCounterTHLD > C_F32_DELTA)
    {
      fRangePercent = SPMData.SPMBSDRangeDeterminationCounter/SPMBlockageParameters.fBSDRangeHoldCounterTHLD;
    }
  }
  fRangePercent = MINMAX_FLOAT(0.0F,1.0F,fRangePercent);

  fBlockageProbability = MAX_FLOAT(fBlockageProbability, fRangePercent); 

  /*Object loss Precent*/
  if(SPMBlockageParameters.uiNoOfAllowedObjLosses > 0u)
  {
    if(eSPMBlockageState == FCT_FULL_BLOCKAGE)
    {
      if(SPM_BLOCKAGE_REACTIVATION_DELAY > C_F32_DELTA)
      {
        fObjectLossPercent = SPMObjectLossGeneralInfo.CommonData.fBSDDampRecoveryCounter/SPM_BLOCKAGE_REACTIVATION_DELAY;
      }
    }
    else 
    {
      fObjectLossPercent = (float32)SPMData.uObjLossBSDNoOfRelObjLosses / (float32)SPMBlockageParameters.uiNoOfAllowedObjLosses;
    }
  }

  /*use the max value of the tree observers*/
  fBlockageProbability = MAX_FLOAT(fBlockageProbability,fObjectLossPercent);
  
  fBlockageProbability = fBlockageProbability * 10.0F;

  return (uint8)fBlockageProbability;
}

/********************************************************

  Functionname:           SPMWiperPermit
  
  @brief                  check if the Wiper timer delay is reached to allow the Blockage

*//************************************************************************/
static boolean SPMWiperPermit (      uint8   uInputWiperState,
                               const float32 fWiperDelay,
                               const boolean bWiperPermit,
                               const fTime_t fCurrCycleTime
                           )
{
  boolean bReturnValue = bWiperPermit;
  // wiper state management
  //
  // input wiper state = reqPorts->pVehicleSignals->VehSigAdd.WiperState
  if (uInputWiperState == VEH_SIG_ADD_WIPER_STATE_ACTIVE)
  {
    // only allow blockage to output once wiper is on and delay time is exceeded
    if (bWiperPermit == FALSE)
    {
      if (SPMWiperData.fBlockageWiperPermitTimer < fWiperDelay)
      {
        // increment the timer
        SPMWiperData.fBlockageWiperPermitTimer = SPMWiperData.fBlockageWiperPermitTimer + fCurrCycleTime;
      }
      else
      {
        bReturnValue = TRUE;
      }
    }
  }
  else
  {
    /*CAN Signaltransitions back to off --> reset the counter*/
    SPMWiperData.fBlockageWiperPermitTimer = 0.0F;
    bReturnValue                           = FALSE;
  }
  return bReturnValue;
}

/********************************************************

  Functionname:           SPMWiperExtendBlockageState
  
  @brief                  check if Blockage Verification Timer is exit 

*//************************************************************************/
static boolean SPMWiperExtendBlockageState (const float32 fBlockage1VerificationTime,
                                            const boolean bExtendBlockageState,
                                            const eBlockageStates_t eSPMBlockageState,
                                            const fTime_t fCurrCycleTime
                                            )
{
  boolean bReturnValue = bExtendBlockageState;

  // if blockage was OFF last cycle then reset
  if ( eSPMBlockageState != FCT_FULL_BLOCKAGE )
  {
    SPMWiperData.fExtendBlockageTimer  = -1.0F;
    bReturnValue = FALSE;
  }
  else
  {
    if ( SPMWiperData.fExtendBlockageTimer <  -0.1F )
    {
      bReturnValue                       = TRUE;
      SPMWiperData.fExtendBlockageTimer  = 0.0F;
    }

    if ( SPMWiperData.fExtendBlockageTimer < fBlockage1VerificationTime )
    {
      // increment the timer
      SPMWiperData.fExtendBlockageTimer = SPMWiperData.fExtendBlockageTimer + fCurrCycleTime;
    }
    else
    {
      bReturnValue = FALSE;
    }
  }
  return  bReturnValue;

}

/********************************************************

  Functionname:           SPMWiperPartialBlockageState
  
  @brief                  

*//************************************************************************/
static boolean SPMWiperPartialBlockageState (const uint8   uBlockageProbability,
                                             const boolean bWiperPermit,
                                             const boolean bLastWiperPermit,
                                             const boolean bPartialBlockageState,
                                             const fTime_t fCurrCycleTime
                                            )
{
  boolean bTempPatialBlockageState = bPartialBlockageState;

  if (    (bLastWiperPermit     == TRUE  )
       && (bWiperPermit         == FALSE )
       && (uBlockageProbability  > 0u    ) )
  {
    bTempPatialBlockageState           = TRUE;
    SPMWiperData.fPartialBlockageTimer = 0.0F;
  }

  if ( bTempPatialBlockageState == TRUE )
  {
    // advance the timer
    SPMWiperData.fPartialBlockageTimer = SPMWiperData.fPartialBlockageTimer + fCurrCycleTime;
  
    // check for shut-off conditions
    if (    (SPMWiperData.fPartialBlockageTimer >  600.0F)
         || (uBlockageProbability               == 0u    ) )
    {
      bTempPatialBlockageState           = FALSE;
      SPMWiperData.fPartialBlockageTimer = -1.0F;
    }
  }
  return bTempPatialBlockageState; 
}

/********************************************************

  Functionname:           SPMWiperBlockageHoldOff
  
  @brief                  

*//************************************************************************/
static boolean SPMWiperBlockageHoldOff (const boolean bWiperPermit,
                                        const boolean bPartialBlockageState,
                                        const eBlockageStates_t eSPMBlockageState)
{
  boolean bReturnValue = FALSE;
   /* Blockage overrides */
  if (    ( bWiperPermit          == FALSE             )
       && ( bPartialBlockageState == FALSE             )
       && ( eSPMBlockageState     != FCT_FULL_BLOCKAGE ) )

  {
    bReturnValue = TRUE;
  }
  return bReturnValue;
}

/********************************************************

  Functionname:           SPMWiperBlockageHoldOn
  
  @brief                  

*//************************************************************************/
static boolean SPMWiperBlockageHoldOn (const boolean bExtendblockage)
{
  boolean bReturnValue = FALSE;

  if (bExtendblockage == TRUE)
  {
    bReturnValue = TRUE;
  }
  
  return bReturnValue;
}

#if defined __cplusplus
};
#endif

#endif


