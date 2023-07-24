/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrix.c

  DESCRIPTION:            HLA matrix beam function.

  CREATION DATE:          2012-11-05
  
  CPU:                    Independent

  VERSION:                $Revision: 1.23.1.1 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hlaf_type.h"
#include "hlaf_matrix.h"
#include "hlaf_matrixgfa.h"
#include "hla_measfreeze_data.h"


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


/****************************************************************************
 * GLOBAL FUNCTION DEFINTIONS
*****************************************************************************/
/* *******************************************************************************
  Initializes matrix data and controls GFA and internal object list initialization

******************************************************************************* */
void HLAFMatrix_Init( HLAFData_t* const pFData )
{
  /* init glare free areas */
  HLAFMatrixGFA_Init( &(pFData->hlafMatrixData.Matrix.GFA) );
}

#ifdef PC_SIM
/* *******************************************************************************
  @fn             HLAFMatrixMeasfreeze                                       */ /*!

  @brief          Sends internal HLA matrix data via measfreeze to MTS.

  @description    Performs the required measFreeze for matrix data.

  @param[in]      pfMeasFreeze          Pointer to measFreeze function
  @param[in]      pMatrixParameters  Pointer to matrix parameters

  @return         void
******************************************************************************** */
void HLAFMatrixMeasfreeze( const AS_t_MeasHdlr             pfMeasFreeze,
                           const t_MatrixParameters* const pMatrixParameters,
                           const HLAFMatrixData_t*   const pHlafMatrixData
                         )
{
  AS_t_MeasInfo HlafMatrixParameterMeasInfo = {HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER, sizeof(*pMatrixParameters), TASK_ID_HLA, TASK_ID_HLA};
  AS_t_MeasInfo HlafMatrixDataMeasInfo      = {HLA_MEAS_VADDR_HLAF_MATRIX_DATA,      sizeof(*pHlafMatrixData),   TASK_ID_HLA, TASK_ID_HLA};

  pfMeasFreeze(&HlafMatrixParameterMeasInfo, pMatrixParameters, NULL);
  pfMeasFreeze(&HlafMatrixDataMeasInfo, pHlafMatrixData, NULL);
}
#endif


/* *******************************************************************************
  Copies the internal matrix data to output structure
******************************************************************************** */
void HLAFMatrix_SetOutput( const HLAFMatrixData_t* const pData,
                           const uint8                   calibrationConfidence,
                                 HLAFMatrixOut_t*  const pOutNext
                          )
{
  uint32 iGFA;

  pOutNext->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_DATA_VALID;

  /* HB off and GFA defined? -> copy all GFAs */
  if(   (pOutNext->Matrix.HighBeamState == (uint8)RTE_HLAF_HB_STATE_OFF)
      && (pData->Matrix.GFA.nGFA > 0u)
    )
  {
    for(iGFA = 0u; iGFA < pData->Matrix.GFA.nGFA; iGFA++)
    {
      /* <ArrayOOBCheck> 2016-04-20 */ /* M.Rameez: pData->Matrix.GFA.nGFA is limited by RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS which is the size of pOutNext->Matrix.GFA and pData->Matrix.GFA.GFA */
      /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
      /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
      (void)memcpy(&pOutNext->Matrix.GFA[iGFA], &pData->Matrix.GFA.GFA[iGFA].Ext, CML_Min(sizeof(pOutNext->Matrix.GFA[iGFA]), sizeof(pData->Matrix.GFA.GFA[iGFA].Ext)));
      /* COU_COV_ENABLE */
    }
    pOutNext->Matrix.nGFA = pData->Matrix.GFA.nGFA;
  }

}


/* *******************************************************************************
  Depending on the provided HLA function data the turn off reasons will be set in
  the output structure.
******************************************************************************** */
void HLAFMatrix_SetTurnOffReason( const HLAFData_t*      const pFData,
                                        HLAFMatrixOut_t* const pOutNext
                                )
{
  pOutNext->Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_UNKNOWN;


  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_CITY) == b_TRUE)
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_CITY);
  }

  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_TUNNEL) == b_TRUE)
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_TUNNEL);
  }

  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BRIGHTNESS) == b_TRUE)
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_BRIGHTNESS);
  }

  if(    (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MIN_SPEED) == b_TRUE)
      || (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_MAX_SPEED) == b_TRUE)
     )
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_SPEED);
  }

  if(    (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_ONCOMING)      == b_TRUE)
      || (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_ONC) == b_TRUE)
    )
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_ONC);
  }

  if(    (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_PRECEDING)      == b_TRUE)
      || (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_EM_OBJECT_PREC) == b_TRUE)
      || (CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_RADAR_OBJECT)   == b_TRUE)
    )
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_PREC);
  }
  
  /* blockage detected */
  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BLOCKAGE) == b_TRUE)
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_BLOCKAGE);
  }

  /* Fog detected */
  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_FOG) == b_TRUE)
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_FOG);
  }

  /* Bad weather detected */
  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, HLAF_TURN_OFF_REASON_BAD_WEATHER) == b_TRUE)
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_WEATHER);
  }

  /* HB off and no turn off reason set -> set RTE_HLAF_TURNOFFREASON_DELAY */
  if(    (pOutNext->Matrix.TurnOffReason == 0u)
      && (pOutNext->Matrix.HighBeamState == (uint8)RTE_HLAF_HB_STATE_OFF)
    ) 
  {
    CML_SetBit(pOutNext->Matrix.TurnOffReason, (uint16)RTE_HLAF_TURNOFFREASON_DELAY);
  }
}

/* *******************************************************************************
  Memsets the matrix output data.
******************************************************************************** */
void HLAFMatrix_InitOutput( HLAFMatrixOut_t* const pOut)
{
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset(pOut, 0, sizeof(*pOut));
}
/****************************************************************************
 * LOCAL FUNCTION DEFINTIONS
 *****************************************************************************/
