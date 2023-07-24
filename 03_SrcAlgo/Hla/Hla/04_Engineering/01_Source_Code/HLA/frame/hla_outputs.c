/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_outputs.c

  DESCRIPTION:            headlight assist output

  CREATION DATE:          2014-01-20
  
  CPU:                    Independent

  VERSION:                $Revision: 1.7 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hla_outputs.h"
#include "hla_defs.h"
#include "hlaf_ext.h"
#include "hla_ver.h"

/****************************************************************************
 * SYMBOLIC CONSTANTS
 *****************************************************************************/


/****************************************************************************
 * LOCAL TYPEDEFS
 *****************************************************************************/
 

/****************************************************************************
 * GLOBAL VARIABLES
 *****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static RTE_HLAF_FunctionStatus HLA_Comp2FunctionState(const CompState_t compState);

/*****************************************************************************
  GLOBAL FUNCTIONS DEFINITION
*****************************************************************************/
/* *******************************************************************************
  Initializes all provide ports with default data.
******************************************************************************** */
void HLA_SetOutputDefaults( const CompState_t               compState,
                            const CompErrorCode_t           errorCode,
                            const GenAlgoQualifiers_t       algoQualifier,
                            const AlgoSignalState_t         sigState,
                            const AlgoDataTimeStamp_t       timeStamp,
                            const AlgoCycleCounter_t        measurementCounter,
                            const AlgoCycleCounter_t        cycleCounter,
                                  Hla_SyncRef_t*      const pHlaSyncRef,
                                  proHlaPrtList_t*    const pProPorts
                           )
{
  static const uint8 versionInfo[ALGO_VERSION_INFO_LENGTH] = HLA_SW_VERSION_INFO;

  /* COMPONENT STATE */
  pProPorts->pAlgoCompState->uiVersionNumber                 = COMP_STATE_INTFVER;
  pProPorts->pAlgoCompState->sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
  pProPorts->pAlgoCompState->sSigHeader.uiCycleCounter       = cycleCounter;
  pProPorts->pAlgoCompState->sSigHeader.uiMeasurementCounter = measurementCounter;
  pProPorts->pAlgoCompState->sSigHeader.uiTimeStamp          = timeStamp;
  pProPorts->pAlgoCompState->uiAlgoVersionNumber             = HLA_SW_VERSION_NUMBER;
  pProPorts->pAlgoCompState->uiApplicationNumber             = HLA_PROJECT;
  pProPorts->pAlgoCompState->eCompState                      = compState;
  pProPorts->pAlgoCompState->eErrorCode                      = errorCode;
  pProPorts->pAlgoCompState->eShedulerSubModeRequest         = BASE_SSM_NONE;
  pProPorts->pAlgoCompState->eGenAlgoQualifier               = algoQualifier;
  /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
  /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
  (void)memcpy( pProPorts->pAlgoCompState->AlgoVersionInfo, versionInfo, CML_Min(sizeof(versionInfo), sizeof(pProPorts->pAlgoCompState->AlgoVersionInfo)));
  /* COU_COV_ENABLE */

  /* HEADLIGHT CONTROL DATA */
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset( pProPorts->pHlaf_HeadlightControl, 0, sizeof(*(pProPorts->pHlaf_HeadlightControl)));
  pProPorts->pHlaf_HeadlightControl->uiVersionNumber                 = RTE_HLAF_HEADLIGHTCONTROL_INTFVER;
  pProPorts->pHlaf_HeadlightControl->sSigHeader.eSigStatus           = sigState;
  pProPorts->pHlaf_HeadlightControl->sSigHeader.uiCycleCounter       = cycleCounter;
  pProPorts->pHlaf_HeadlightControl->sSigHeader.uiMeasurementCounter = measurementCounter;
  pProPorts->pHlaf_HeadlightControl->sSigHeader.uiTimeStamp          = timeStamp;
  pProPorts->pHlaf_HeadlightControl->hlaFunctionStatus               = HLA_Comp2FunctionState(compState);

  /* SYNC REF SIGNAL HEADER */
  pHlaSyncRef->sSigHeader.eSigStatus           = sigState;
  pHlaSyncRef->sSigHeader.uiCycleCounter       = cycleCounter;
  pHlaSyncRef->sSigHeader.uiMeasurementCounter = measurementCounter;
  pHlaSyncRef->sSigHeader.uiTimeStamp          = timeStamp;
}

/* *******************************************************************************
  Random data for some provide ports for demonstration reasons.
******************************************************************************** */
void HLA_SetOutputDemo( proHlaPrtList_t* const pProPorts )
{
  /* PRQA S 3120 ++ # 2019-05-28 A.Fischer: Magic numbers ok, since this is just a demo output */
  /* PRQA S 3121 ++ # 2019-05-28 A.Fischer: Magic numbers ok, since this is just a demo output */
  uint32 idx;

  /* set learning values to NULL so no chance of corrupting our NVM */

  /* Fill matrix data for one GFA */
  pProPorts->pHlaf_HeadlightControl->Matrix.GFAStatus      = RTE_HLAF_SIGSTAT_DATA_VALID;
  pProPorts->pHlaf_HeadlightControl->Matrix.HighBeamState  = RTE_HLAF_HB_STATE_PARTIAL;
  pProPorts->pHlaf_HeadlightControl->Matrix.LowBeam_Ang    = C_HALFPI;
  pProPorts->pHlaf_HeadlightControl->Matrix.LowBeam_Dist   = 42.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.LowBeam_Status = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  pProPorts->pHlaf_HeadlightControl->Matrix.nGFA           = 1u;
  pProPorts->pHlaf_HeadlightControl->Matrix.TurnOffReason  = 1u;

  /* set up one GFA with nonsense values */
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang        = C_HALFPI;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Ang_Cam    = CML_f_Pi / 4.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Dist       = 42.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_Status     = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_ObjId      = 0u;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLeft_DistState  = RTE_HLAF_DISTSTATE_PAIRLIGHT;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Ang_Cam   = 1.3f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_Status    = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_ObjId     = 1u;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryLower_DistState = RTE_HLAF_DISTSTATE_SINGLELIGHT;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang       = -(C_HALFPI);
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Ang_Cam   = -(CML_f_Pi / 4.0f);
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Dist      = 42.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_Status    = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_ObjId     = 2u;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].BndryRight_DistState = RTE_HLAF_DISTSTATE_PAIRLIGHT;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Ang       = 1.5f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Dist      = 42.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_Status    = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_ObjId     = 3u;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ClosestObj_DistState = RTE_HLAF_DISTSTATE_PAIRLIGHT;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ExistenceProb        = 21;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Ang         = 1.25f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Dist        = 42.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].MinLight_Status      = RTE_HLAF_OBJSTA_UNKNOWN_OBJ;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left            = 1.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Left_Status     = RTE_HLAF_TTBSTA_DIR_LEFT;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right           = 1.0f;
  pProPorts->pHlaf_HeadlightControl->Matrix.GFA[0].ttb18Right_Status    = RTE_HLAF_TTBSTA_DIR_RIGHT;

  /* set demo values at dimming fields */
  for(idx = 0u; idx < (uint32)RTE_HLA_NUM_DIMM_AREAS; idx++)
  {
    /* <ArrayOOBCheck> 2016-05-25 */ /* M.Rameez: idx < RTE_HLA_NUM_DIMM_AREAS i.e. size of pProPorts->pHlaf_HeadlightControl->Dimming.DimmingArea  */
    pProPorts->pHlaf_HeadlightControl->Dimming.DimmingArea[idx] = RTE_HLAF_DIMM_LEVEL_NO_REDUCT;
  }
  pProPorts->pHlaf_HeadlightControl->Dimming.DimmingStatus = RTE_HLAF_DIMM_STATE_AVL;
  /* PRQA S 3120 -- */
  /* PRQA S 3121 -- */
}

/*****************************************************************************
  LOCAL FUNCTIONS DEFINITION
*****************************************************************************/
/** ************************************************************************************************
  \brief            Conversion from component state to hla function status.
                    
  \pre              None
  \post             None
                    
  \param[in]        compState     HLA component status

  \return           HLA function status

  \globals          None

  \InOutCorrelation Simple mapping of all component states to hla function status.

  \callsequence     

  \testmethod

  \traceability
***************************************************************************************************/
static RTE_HLAF_FunctionStatus HLA_Comp2FunctionState(const CompState_t compState)
{
  RTE_HLAF_FunctionStatus functionStatus;

  switch(compState)
  {
  case (uint8)COMP_STATE_NOT_INITIALIZED:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF;
    break;
  case (uint8)COMP_STATE_RUNNING:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_RUNNING;
    break;
  case (uint8)COMP_STATE_TEMPORARY_ERROR:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF;
    break;
  case (uint8)COMP_STATE_PERMANENT_ERROR:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF;
    break;
  case (uint8)COMP_STATE_SUCCESS:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF;
    break;
  case (uint8)COMP_STATE_REDUCED_AVAILABILITY:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_RUNNING;
    break;
  case (uint8)COMP_STATE_NOT_RUNNING:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF;
    break;
  default:
    functionStatus = RTE_HLAF_FUNCTION_STATUS_INVALID;
  	break;
  }

  return functionStatus;
}
