/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision_blockage.c

  DESCRIPTION:            HLA decision on blockage state.

  CREATION DATE:          2014-10-31
    
  CPU:                    Independent

  VERSION:                $Revision: 1.9 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_decision_blockage.h"
#include "hla_errorhandling.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static void HLAFDecisionBlockage_TransitionsClearMeas( const CB_t_ProvidedOutputs_t*       const pCbOutputs,
                                                       const t_DecisionParametersBlockage* const pParams,
                                                       const HLAFCameraData_t*             const pCamData,
                                                             HLAFBlockage_t*               const pData
                                                     );


static void HLAFDecisionBlockage_TransitionsNoBlockage( const CB_t_ProvidedOutputs_t* const pCbOutputs,
                                                              HLAFBlockage_t*         const pData
                                                      );

static void HLAFDecisionBlockage_TransitionsBlockage( const CB_t_ProvidedOutputs_t*          const pCbOutputs,
                                                      const RTE_HLAF_ParameterTurnOnDelay_t* const pRTETurnOnDelayPar,
                                                      const HLAFCameraData_t*                const pCamData,
                                                            HLAFBlockage_t*                  const pData
                                                    );

static void HLAFDecisionBlockage_TransitionsCondensation( const CB_t_ProvidedOutputs_t* const pCbOutputs,
                                                                HLAFBlockage_t*         const pData
                                                        );


/****************************************************************************
 * GLOBAL FUNCTION DEFINTIONS
*****************************************************************************/

/* *******************************************************************************
  Based on the input from camera blockage the current blockage situation is assessed
  and according to the result the blockage output is set and possibly an error will
  be stored. For each blockage input the blockage output will be set and the
  transition for the next frame will be done.
******************************************************************************** */
void HLAFDecisionBlockage_Main( const CB_t_ProvidedOutputs_t*          const pCbOutputs,
                                const RTE_HLAF_ParameterTurnOnDelay_t* const pRTETurnOnDelayPar,
                                const t_DecisionParametersBlockage*    const pParams,
                                const HLAFCameraData_t*                const pCamData,
                                      HLAFBlockage_t*                  const pData
                              )
{

  /* blockage state machine */
  switch(pData->eBlockageState)
  {
  case HLAF_BLOCKAGE_CLEAR_MEAS:
    /* state transition(s) */
    HLAFDecisionBlockage_TransitionsClearMeas(pCbOutputs,
                                              pParams,
                                              pCamData,
                                              pData
                                             );
    break;

  case HLAF_BLOCKAGE_NO_BLOCKAGE:
    /* state transition(s) */
    HLAFDecisionBlockage_TransitionsNoBlockage( pCbOutputs,
                                                pData
                                              );
    break;

  case HLAF_BLOCKAGE_BLOCKAGE:
    /* state transition(s) */
    HLAFDecisionBlockage_TransitionsBlockage( pCbOutputs,
                                              pRTETurnOnDelayPar,
                                              pCamData,
                                              pData
                                            );
    break;

  case HLAF_BLOCKAGE_CONDENSATION:
    /* state transition(s) */ 
    HLAFDecisionBlockage_TransitionsCondensation( pCbOutputs,
                                                  pData
                                                );
    break;

  case HLAF_BLOCKAGE_LAST: 
  default:
    /* There is nothing to be done here except breaking */
    break;
  }

}


/****************************************************************************
 * LOCAL FUNCTION DEFINTIONS
 *****************************************************************************/

/* *******************************************************************************
  @fn             HLAFDecisionBlockage_TransitionsClearMeas                 */ /*!

  @brief          Blockage state machine transitions from Clearance

  @description    Blockage transition from Clearance Measurement to
                   a) No Blockage: if NO_BLOCKAGE has been reported and a para-
                      meter based distance has been driven (currently 50 m)
                   b) Blockage, if BLOCKAGE has been reported
                   c) Condensation, if CONDENSATION has been reported and a para-
                      meter based distance has been driven (currently 50m)
                  When there is no valid output by camera blockage algo after a parameter based
                  distance (500m) and time (30s) an error will be set, which causes HLA to go into
                  temp error.
                  While clearance measurement is legally ongoing, elapsed time and
                  covered distance are increased and the manual override is done.

  @param[in]      pCbOutputs          Pointer to blockage output
  @param[in]      pParams             Pointer to parameters
  @param[in]      pCamData            Pointer to camera data
  @param[in,out]  pData               Pointer to store blockage history

  @return         void
******************************************************************************** */
static void HLAFDecisionBlockage_TransitionsClearMeas( const CB_t_ProvidedOutputs_t*       const pCbOutputs,
                                                       const t_DecisionParametersBlockage* const pParams,
                                                       const HLAFCameraData_t*             const pCamData,
                                                             HLAFBlockage_t*               const pData
                                                     )
{
  /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_NO_BLOCKAGE */
  if (   (pCbOutputs->ui8_BlockageStatus == (uint8)GB_NO_BLOCKAGE)
      && (pData->DistTraveled >= pParams->ClearMeas2NoBlockage_DistThres)
     )
  {
    pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  }
  /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_BLOCKAGE */
  else if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_BLOCKAGE)
  {
      pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;

  }
  /* HLAF_BLOCKAGE_CLEAR_MEAS -> HLAF_BLOCKAGE_CONDENSATION */
  else if (   (pCbOutputs->ui8_BlockageStatus == (uint8)GB_CONDENSATION)
           && (pData->DistTraveled >= pParams->ClearMeas2NoBlockage_DistThres)
          )
  {
    pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
  }
  /* No valid input after clearance measurement was finished */
  else if (    (pData->DistTraveled > pParams->ClearMeas2Blockage_DistThres)
            && (pData->TimeElapsed > pParams->ClearMeas2Blockage_TimeThres)
           )
  {
    /* Set error */
    HLA_ErrorHandling_SetError(HLA_ERROR_BLOCKAGE_NO_VALID_INPUT);
  }
  else
  { 
    pData->TimeElapsed = pData->TimeElapsed + pCamData->dtimeFwd_s;
    pData->DistTraveled = pData->DistTraveled + pCamData->ddistFwd_m;
  }
}

/* *******************************************************************************
  @fn             HLAFDecisionBlockage_TransitionsNoBlockage                       */ /*!

  @brief          Blockage state machine transitions from No Blockage

  @description    Blockage transition from NO_BLOCKAGE to
                   a) Blockage, if BLOCKAGE has been reported
                   b) Condensation, if CONDENSATION is reported
                  Otherwise NO_BLOCKAGE is kept.

  @param[in]      pCbOutputs      Pointer to blockage output
  @param[in,out]  pData           Pointer to store blockage history

  @return         void
******************************************************************************** */
static void HLAFDecisionBlockage_TransitionsNoBlockage( const CB_t_ProvidedOutputs_t* const pCbOutputs,
                                                              HLAFBlockage_t*         const pData
                                                      )
{
  /* HLAF_BLOCKAGE_NO_BLOCKAGE -> HLAF_BLOCKAGE_BLOCKAGE */
  if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_BLOCKAGE)
  {
    pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  }
  /* HLAF_BLOCKAGE_NO_BLOCKAGE -> HLAF_BLOCKAGE_CONDENSATION */
  else if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_CONDENSATION)
  {
    pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
  }
  else
  {
    /* Remain in HLAF_BLOCKAGE_NO_BLOCKAGE */
  }
}


/* *******************************************************************************
  @fn             HLAFDecisionBlockage_TransitionsBlockage                         */ /*!

  @brief          Blockage state machine transitions from Blockage

  @description    Blockage transition from BLOCKAGE to
                   a) No Blockage, if NO_BLOCKAGE is reported and the vehicle is
                      above activation speed for longer than a parameter based
                      threshold (currently 2 s)
                   b) Condensation, if CONDENSATION is reported and the vehicle is
                      above activation speed for longer than a parameter based
                      threshold (currently 2 s)
                  Otherwise BLOCKAGE is kept.

  @param[in]      pCbOutputs           Pointer to blockage output
  @param[in]      pRTETurnOnDelayPar   Pointer to RTE TurnOnDelay parameters
  @param[in]      pCamData             Pointer to camera data
  @param[in,out]  pData                Pointer to store blockage history

  @return         void
******************************************************************************** */
static void HLAFDecisionBlockage_TransitionsBlockage( const CB_t_ProvidedOutputs_t*          const pCbOutputs,
                                                      const RTE_HLAF_ParameterTurnOnDelay_t* const pRTETurnOnDelayPar,
                                                      const HLAFCameraData_t*                const pCamData,
                                                            HLAFBlockage_t*                  const pData
                                                    )
{
  /* PRQA S 3121 ++ # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
  /* HLAF_BLOCKAGE_BLOCKAGE -> HLAF_BLOCKAGE_NO_BLOCKAGE */
  if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_NO_BLOCKAGE)
  {
      /* Check if thresholds for time while unblocked is reached */
      if (pData->BlockageTime > pRTETurnOnDelayPar->Blockage)
      {
        pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
        /* Reset blockage counter */
        pData->BlockageTime = 0.f;
      }
      else
      {
        /* Update counter */
        pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
      }

  }
  /* HLAF_BLOCKAGE_BLOCKAGE -> HLAF_BLOCKAGE_CONDENSATION */
  else if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_CONDENSATION)
  {
    /* Check if thresholds for time while unblocked is reached */
    if (pData->BlockageTime > pRTETurnOnDelayPar->Blockage)
    {
      pData->eBlockageState = HLAF_BLOCKAGE_CONDENSATION;
      /* Reset blockage counter */
      pData->BlockageTime = 0.f;
    }
    else
    {
      /* Update counter */
      pData->BlockageTime = pData->BlockageTime + pCamData->dtimeFwd_s;
    }
  }
  else
  {
    /* Reset blockage counter */
    pData->BlockageTime = 0.f;
  }
  /* PRQA S 3121 -- */
}


/* *******************************************************************************
  @fn             HLAFDecisionBlockage_TransitionsCondensation                     */ /*!

  @brief          Blockage state machine transitions from Condensation

  @description    Blockage transition from CONDENSTATION to
                   a) No Blockage if NO_BLOCKAGE was reported
                   b) Blockage if BLOCKAGE was reported
                   Otherwise CONDENSTATION is kept.

  @param[in]      pCbOutputs      Pointer to blockage output
  @param[in,out]  pData           Pointer to store blockage history

  @return         void
******************************************************************************** */
static void HLAFDecisionBlockage_TransitionsCondensation( const CB_t_ProvidedOutputs_t* const pCbOutputs,
                                                                HLAFBlockage_t*         const pData
                                                        )
{
  /* HLAF_BLOCKAGE_CONDENSATION -> HLAF_BLOCKAGE_NO_BLOCKAGE */
  if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_NO_BLOCKAGE)
  {
    pData->eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  }
  /* HLAF_BLOCKAGE_CONDENSATION -> HLAF_BLOCKAGE_BLOCKAGE */
  else if (pCbOutputs->ui8_BlockageStatus == (uint8)GB_BLOCKAGE)
  {
    pData->eBlockageState = HLAF_BLOCKAGE_BLOCKAGE;
  }
  else
  { 
    /* Remain in HLAF_BLOCKAGE_CONDENSATION */
  }
}

