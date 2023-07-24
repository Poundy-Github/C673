/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf.c

  DESCRIPTION:            HLAF main module. This module calls all sub functions for HLAF.

  CREATION DATE:          2011-02-23
  
  CPU:                    Independent

  VERSION:                $Revision: 1.32.1.1 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hlaf_ext.h"
#include "hlaf_type.h"
#include "HLA_DecisionParameters.h"
#include "HLA_MatrixParameters.h"
#include "hlaf_decision.h"
#include "hlaf_decision_blockage.h"
#include "hlaf_decision_environment.h"
#include "hlaf_decision_keepoff.h"
#include "hlaf_matrix.h"
#include "hla_ver.h"
#if (HLA_DIMMING == STD_ON)
#include "hlaf_dimming.h"
#endif
#include "hla_utils.h"
#include "hla_measfreeze_data.h"
#if (HLA_CAM_ROT == STD_ON)
#include "hla_cam_rot.h"
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/

/* HLAF internal Data */
HLA_GLOBAL_STATIC HLAFData_t  hlafData;

/* Store timestamp counter of previous call */
HLA_GLOBAL_STATIC AlgoDataTimeStamp_t timeStampPrevCycle = 0u;

/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/
static void HLAF_Measfreeze( const AS_t_MeasHdlr               pfMeasFreeze, 
                             const t_DecisionParameters* const pDecisionParameters
                           );

HLA_GLOBAL_STATIC void HLAF_FillData( const reqHlaPrtList_t* const pReqPorts,
                                            HLAFData_t*      const pFData
                                     );

HLA_GLOBAL_STATIC void HLAF_FillOutputData( const reqHlaPrtList_t*    const pReqPorts,
                                            const HLAFData_t*         const pFData,
                                            const t_MatrixParameters* const pMatrixParameters,
                                                  proHlaPrtList_t*    const pProPorts
                                           );

HLA_GLOBAL_STATIC void HLAF_FillOutputDataMatrixBeam( const reqHlaPrtList_t*    const pReqPorts,
                                                      const HLAFData_t*         const pFData,
                                                      const t_MatrixParameters* const pMatrixParameters,
                                                            RTE_HLAF_Matrix_t*  const pMatrixOut
                                                     );

static void HLAF_EnvironmentDecisions( const reqHlaPrtList_t*      const pReqPorts,
                                       const t_DecisionParameters* const pDecisionParameters
                                      );

static void HLAF_SetLightStates( const reqHlaPrtList_t*      const pReqPorts,
                                 const t_DecisionParameters* const pDecisionParameters,
                                 const t_MatrixParameters*   const pMatrixParameters,
                                       proHlaPrtList_t*      const pProPorts
                               );

HLA_GLOBAL_STATIC void HLAF_CopySortedMatrixData( const RTE_HLAF_Matrix_t*   const pMatrixIn,
                                                        RTE_HLAF_Matrix_t*   const pMatrixOut
                                                );

HLA_GLOBAL_STATIC void HLAF_LimitOutputs( const t_MatrixParameters* const pMatrixParameters,
                                                RTE_HLAF_Matrix_t*  const pMatrixOut
                                        );

/****************************************************************************
 * GLOBAL FUNCTION DEFINTIONS
*****************************************************************************/
/* *******************************************************************************
  Initializes the HLA function part in reset mode.
  ******************************************************************************** */
void HLAF_v_Init( const reqHlaPrtList_t*    const pReqPorts)
{

  HLAUtilsAddDetailedRtaEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_INIT, 0u);

  timeStampPrevCycle = pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;

  /* init hlaf internal data */
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset( &hlafData, 0, sizeof(hlafData));
  hlafData.FrameCnt                             = pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
  hlafData.TimeStamp_HLA_ms                     = pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
  hlafData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_CLEAR_MEAS;

#if (HLA_CAM_ROT == STD_ON )
  /* Init Cam Rot */
  HLACamRotInit();
#endif

  /* Init HLAF matrix */
  HLAFMatrix_Init(&hlafData);

#if (HLA_DIMMING == STD_ON )
  /* Init HLAF dimmingAreas */
  HLAFDimming_InitAreas(&hlafData.DecisionData.DimmingAreas);
#endif

  HLAUtilsAddDetailedRtaEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_INIT, 0u);
}


/* *******************************************************************************
  Executes the HLA function part.
******************************************************************************** */
void HLAF_v_Exec( const reqHlaPrtList_t*    const pReqPorts,
                        proHlaPrtList_t*    const pProPorts,
                  const AS_t_ServiceFuncts* const Services
                 )
{
  const t_DecisionParameters* pDecisionParameters  = GetDecisionParameters();
  const t_MatrixParameters*   pMatrixParameters    = GetMatrixParameters();


#if (HLA_CAM_ROT == STD_ON )
  /* PRQA S 3121 3 # 2019-05-28 A.Fischer: magic number is justified in this context */
  HLACamRotSetData( -pReqPorts->pMonoCalibration->sPoseCalibration.fPitch - CML_Deg2Rad(90.0f),
                    pReqPorts->pMonoCalibration->sPoseCalibration.fRoll,
                    pReqPorts->pMonoCalibration->sPoseCalibration.fYaw - CML_Deg2Rad(90.0f),
                    pReqPorts->pMonoCalibration->sPoseCalibration.fTx,
                    pReqPorts->pMonoCalibration->sPoseCalibration.fTy,
                    pReqPorts->pMonoCalibration->sPoseCalibration.fTz,
                    pReqPorts->pMonoCalibration->sIntrinsic.fFocalX,
                    pReqPorts->pMonoCalibration->sIntrinsic.fFocalY, 
                    pReqPorts->pMonoCalibration->sIntrinsic.fCenterX,
                    pReqPorts->pMonoCalibration->sIntrinsic.fCenterY 
                   );
#endif
  /* Fill hlaf data */
  HLAF_FillData( pReqPorts,
                 &hlafData
                );
  
#if ( HLA_MATRIX == STD_ON )
  /* init internal object list */
  HLAFMatrix_InitObjectList(&(hlafData.hlafMatrixData.Object[0]));
#endif
  HLAUtilsAddDetailedRtaEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_DECISION, 0u);
  /* TAKE DECISIONS */
  HLAF_EnvironmentDecisions( pReqPorts,
                             pDecisionParameters
                            );
  HLAUtilsAddDetailedRtaEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_DECISION, 0u);
#if ( HLA_MATRIX == STD_ON )  
  HLAUtilsAddDetailedRtaEvent(e_RTA_EVT_AlgoStart, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_MATRIX, 0u);

  /* MATRIX CALCULATIONS */
  HLAFMatrix_Main( pReqPorts,
                   pMatrixParameters,
                   &hlafData
                  );

  HLAUtilsAddDetailedRtaEvent(e_RTA_EVT_AlgoEnd, (uint8)RTA_GLOBALID_HLA, (uint8)HLA_RTA_HLAF_MATRIX, 0u);
#endif
  /* SET LIGHT STATE */
  HLAF_SetLightStates( pReqPorts,
                       pDecisionParameters,
                       pMatrixParameters,
                       pProPorts
                      );

#ifndef HLA_REMOVE_SERVICEFCT
  /* Measfreezes */
  HLAF_Measfreeze( Services->pfMeasFreeze,
                   pDecisionParameters
                  );
#endif
#ifdef PC_SIM
  /* send HLAF matrix measfreezes */
  HLAFMatrixMeasfreeze( Services->pfMeasFreeze,
                        pMatrixParameters,
                        &(hlafData.hlafMatrixData)
                       );
#endif
}


/****************************************************************************
 * LOCAL FUNCTION DEFINTIONS
 *****************************************************************************/
/** ************************************************************************************************
  \brief
    Sets environment related decisions
  
  \pre
    Valid input pointers.

  \post
    None.

  \param[in]    pReqPorts            Request port pointer list
  \param[in]    pDecisionParameters  Pointer to parameters


  \return
    void

  \globals
    \ref hlafData

  \InOutCorrelation
    Updated are the blockage, speed, city and weather states in internal decision data. The brightness, tunnel, 
    traffic style and highway states are directly taken over from the LSD inputs, since the decision was already 
    done in the LSD component. Based on these decisions the global turn off reasons for min speed, max speed, 
    city, tunnel, brightness, blockage and fog are set.

  \callsequence
  
  \testmethod

  \traceability
***************************************************************************************************/
static void HLAF_EnvironmentDecisions( const reqHlaPrtList_t*      const pReqPorts,
                                       const t_DecisionParameters* const pDecisionParameters
                                      )
{

  /* *************************************************************************** */
  /*   HLA STATE MACHINES   */
  /* *************************************************************************** */
#if ( HLA_BLOCKAGE == STD_ON )
  /* blockage detection */
  HLAFDecisionBlockage_Main( pReqPorts->pCbOutputs,
                             &(pReqPorts->pCPar_HlafPar->TurnOnDelay),
                             &(pDecisionParameters->Blockage),
                             &(hlafData.CamData),
                             &(hlafData.DecisionData.Blockage)
                            );
  #else
  hlafData.DecisionData.Blockage.eBlockageState = HLAF_BLOCKAGE_NO_BLOCKAGE;
  #endif

  /* speed state machine */
  HLAFDecisionEnv_Speed( pReqPorts->pVehDyn,
                         pReqPorts->pVehSig,
                         &(pReqPorts->pCPar_HlafPar->Speed),
                         hlafData.CamData.dtimeFwd_s,
                         &(hlafData.DecisionData.Speed)
                        );

  /* city detection state machine */
  HLAFDecisionEnv_City( pReqPorts->pLsdEnvironmentData->cityState,
                        pReqPorts->pLsdEnvironmentData->brightnessState,
                        &(pDecisionParameters->City),
                        &(hlafData),
                        &(hlafData.DecisionOut.eCityState)
                       );
  /* weather decision */
  HLAFDecisionEnv_Weather( pReqPorts->pCbOutputs,
                           &(pReqPorts->pVehSig->VehSigAdd.WiperStage),
                           &(hlafData.CamData),
                           &(hlafData.DecisionData.WeatherData),
                           &(hlafData.DecisionOut.eWeatherState)
                          );

  /* *************************************************************************** */
  /*   LSD DIRECT MAPPING   */
  /* *************************************************************************** */
  hlafData.DecisionOut.eBrightnessState = pReqPorts->pLsdEnvironmentData->brightnessState;
  hlafData.DecisionOut.eTunnelState     = pReqPorts->pLsdEnvironmentData->tunnelState;
  hlafData.DecisionOut.eTrafficStyle    = pReqPorts->pLsdEnvironmentData->trafficStyleState;
  hlafData.DecisionOut.eHighwayState    = pReqPorts->pLsdEnvironmentData->highwayState;

  /* ************************************************************************* */
  /* set global turn off reason like city, min speed, ... */
  /* ************************************************************************* */
  HLAFDecision_SetTurnOffReasonGlob( pReqPorts->pLsdEnvironmentData->brightnessState,
                                     pReqPorts,
                                     &(hlafData),
                                     &(hlafData.DecisionData.TurnOffReason)
                                    );
}


/** ************************************************************************************************
  \brief
    Sets final high beam recommendation and turn off reasons
  
  \pre
    Valid input pointers.

  \post
    None.

  \param[in]      pReqPorts            Pointer to request ports structure
  \param[in]      pDecisionParameters  Pointer to decision parameters
  \param[in]      pMatrixParameters    Pointer to matrix parameters
  \param[in,out]  pProPorts            Pointer to provide ports structure

  \return
    void

  \globals
    \ref hlafData

  \InOutCorrelation
    Sets final high beam recommendation and turn off reasons according to the decisions made and the GFAs calculated. 
    The internal object and em object list are checked for relevant vehicles. Turn off and keep off reasons are updated,
    then the high beam state, low beam distance and scene info are set. The output is set and the provide ports filled.
    If the dimming detection was activated by coding the dimming decision is performed.

  \callsequence
  
  \testmethod

  \traceability
***************************************************************************************************/
static void HLAF_SetLightStates( const reqHlaPrtList_t*      const pReqPorts,
                                 const t_DecisionParameters* const pDecisionParameters,
                                 const t_MatrixParameters*   const pMatrixParameters,
                                       proHlaPrtList_t*      const pProPorts
                                )
{
  HLAFMatrixOut_t MatrixOut_Next; /* next matrix output data */

  /* init matrix output */
  HLAFMatrix_InitOutput( &MatrixOut_Next );

  /* check track list for existing target 
     use HoRot iHBC indicator to replace relevant vehicle flag*/
//  HLAFDecision_FindRelevantVehicle( pReqPorts,
//                                    &(hlafData.hlafMatrixData.RelevantVehicle)
//                                  );

  /* set turn off reason */
  HLAFDecision_SetTurnOffReason( &(hlafData.hlafMatrixData.RelevantVehicle),
                                 &(hlafData.DecisionData.TurnOffReason)
                               );

  /* set keep off reason */
  HLAFDecision_SetKeepOffReason( pReqPorts,
                                 &(hlafData),
                                 &(pDecisionParameters->KeepOff),
                                 &(pDecisionParameters->TurnOnDelay),
                                 hlafData.hlafMatrixData.Out.Matrix.HighBeamState,
                                 &(hlafData.hlafMatrixData.RelevantVehicle),
                                 &(hlafData.DecisionData.TurnOffReason),
                                 &(hlafData.DecisionData.KeepOffReason)
                               );

  /* set HB state {HB on or off} */
  HLAFDecision_SetHBState( 
#ifdef HLA_CHANGAN_CURVE_FEATURE
                           &(hlafData.VehData),
#endif
                           &(hlafData.DecisionData.TurnOffReason),
                           &(hlafData.DecisionData.KeepOffReason),
                           hlafData.hlafMatrixData.Out.Matrix.HighBeamState,
                           &(MatrixOut_Next.Matrix.HighBeamState)
                         );

  /* set output turn off reason */
  HLAFMatrix_SetTurnOffReason( &(hlafData),
                               &(MatrixOut_Next)
                             );

  /* set scene info */
  HLAFDecisionEnv_SceneInfo( &(hlafData),
                             &(pDecisionParameters->SceneInfo),
                             &(MatrixOut_Next),
                             pReqPorts->pLsdLightObjectList,
                             &(hlafData.DecisionOut.eSceneInfo)
                           );

  /* set output interface */
  HLAFMatrix_SetOutput( &(hlafData.hlafMatrixData),
                        pReqPorts->pLsdLightObjectList->calibrationConfidence,
                        &(MatrixOut_Next)
                       );

  hlafData.hlafMatrixData.Out = MatrixOut_Next;

  /* ************************************************************************* */
  /* output decision data */
  /* ************************************************************************* */
  /* fill output data */ 
  HLAF_FillOutputData(pReqPorts,
                      &hlafData,
                      pMatrixParameters,
                      pProPorts
                     );
#if (HLA_DIMMING == STD_ON )
  /* ************************************************************************* */
  /* dimming decision */
  /* ************************************************************************* */
  if(pReqPorts->pCPar_HlafPar->Dimming.DimmingDetection == (uint8)RTE_HLA_DIMMDET_ACTIVE)
  {
    /* Dimming feature is enabled in configuration, fill with valid dimming data */
    HLAFDimming_DecisionAreas( pReqPorts,
                               pReqPorts->pLsdLightObjectList,
                               &(hlafData.DecisionOut.eCityState),
                               &(hlafData.HLAMatrixOut),
                               &(hlafData.DecisionData.DimmingAreas)
                              );
  }
  else
  {
    /* Dimming feature is disabled in configuration, invalidate dimming data */
    HLAFDimming_InvalidateAreas( &(hlafData.DecisionData.DimmingAreas) );
  }
#endif
}

/** ************************************************************************************************
  \brief
    Fills the HLA matrix output structure \c pMatrixOut.
  
  \pre
    Valid input pointers.

  \post
    None.

  \param[in]      pReqPorts          Pointer to request port list
  \param[in]      pFData             Pointer to HLA function data
  \param[in]      pMatrixParameters  Pointer to HLA matrix parameters
  \param[in,out]  pMatrixOut         Pointer to HLA matrix output structure

  \return
    void

  \globals
    None

  \InOutCorrelation
    In case we are not moving forward and per parameter the bAlwaysOutputGFAData is not set no GFAs are set in
    \c pMatrixOut. Low beam distance is set to default value from parameters. Only TurnOffReason and high beam
    state are set from \c hlafMatrixData.Out.Matrix.

    In case we are moving forward whole matrix structure is copied from \c hlafMatrixData.Out.Matrix to output
    structure \c pMatrixOut. The HLAF_CopySortedMatrixData() function is called to sort the GFA areas and then
    the HLAF_LimitOutputs() function to limit the outputs to the range defined as parameters.
    
  \callsequence
    @startuml
    title Fill GFA output data 

    start
    if(Motion state is not forward and bAlwaysOutputGFAData is set to false) than (Yes)
      :Set nGFA to zero;
      :Set GFAStatus to RTE_HLAF_SIGSTAT_DATA_INVALID;
      :Set LowBeam_Dist to default value;
      :Set TurnOffReason to value from matrix output;
      :Set HighBeamState to value from matrix output;
    else(No)
      :Copy complete matrix output struct;
      :Call HLAF_CopySortedMatrixData() to sort and copy GFAs;
      :Call HLAF_LimitOutputs() to limit output to parameter values;
    endif
    end

    @enduml
  
  \testmethod

  \traceability
***************************************************************************************************/
HLA_GLOBAL_STATIC void HLAF_FillOutputDataMatrixBeam( const reqHlaPrtList_t*    const pReqPorts,
                                                      const HLAFData_t*         const pFData,
                                                      const t_MatrixParameters* const pMatrixParameters,
                                                            RTE_HLAF_Matrix_t*  const pMatrixOut
                                                     )
{

  if(    (pReqPorts->pVehDyn->MotionState.MotState != (uint8)VDY_LONG_MOT_STATE_MOVE_FWD)
      && (pMatrixParameters->Cfg.bMotionIndOutputGFAData == b_FALSE)
    )
  {
    /* During backwards driving no GFAs should be set, i.e. keep default values and set status to invalid */
    pMatrixOut->nGFA          = 0u;
    pMatrixOut->GFAStatus     = RTE_HLAF_SIGSTAT_DATA_INVALID;
    pMatrixOut->LowBeam_Dist  = pMatrixParameters->Output.LowBeam_Dist_Default;
    pMatrixOut->TurnOffReason = pFData->hlafMatrixData.Out.Matrix.TurnOffReason;
    pMatrixOut->HighBeamState = pFData->hlafMatrixData.Out.Matrix.HighBeamState;
  } 
  else
  {
    /* copy matrix beam data */
    /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
    /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
    (void)memcpy(pMatrixOut, &pFData->hlafMatrixData.Out.Matrix, CML_Min(sizeof(*pMatrixOut), sizeof(pFData->hlafMatrixData.Out.Matrix)));
    /* COU_COV_ENABLE */

    /* Sort GFA data and copy it to output struct */
    HLAF_CopySortedMatrixData( &pFData->hlafMatrixData.Out.Matrix,
                               pMatrixOut
                             );

    /* Limit outputs */
    HLAF_LimitOutputs( pMatrixParameters,
                       pMatrixOut
                     );

  }
}

/** ************************************************************************************************
  \brief
    Sort GFAs according to angle and copy them to the output structure
  
  \pre
    None

  \post
    None.

  \param[in]      pMatrixIn             Pointer to HLA matrix input structure
  \param[in,out]  pMatrixOut            Pointer to HLA matrix output structure

  \return
    void

  \globals
    None

  \InOutCorrelation
    The GFAs are sorted either from left to right.
    Then they are copied in the correct order to the matrix output structure.
    
  \callsequence
    @startuml
    title Copy sorted matrix data

    start
    :Set the maximum left angle to 90 deg;
    :loop over all GFAs;
    :Set the maximum right angle to -90 deg;
    :second loop over all GFAs;
    if(left angle boundary of GFA is bigger than maximum right angle \n and left angle boundary is smaller than maximum left angle) then (Yes)
      :Store GFA index;
      :Set maximum right angle to left angle boundary;
    else(No)
    endif
    :End of second loop;
    :Fill sorted GFA array from left to right with stored GFA index;
    :Set maximum angle left to maximum angle right;
    :end of first loop;
    :Copy every GFA von matrix in to matrix out accoring to the order in the sorted GFA array;
    end

    @enduml
  
  \testmethod

  \traceability
***************************************************************************************************/
HLA_GLOBAL_STATIC void HLAF_CopySortedMatrixData( const RTE_HLAF_Matrix_t*   const pMatrixIn,
                                                        RTE_HLAF_Matrix_t*   const pMatrixOut
                                                )
{
  uint8 iGFA, iGFA1, iGFAMax;
  /* current number of GFAs */
  uint8 numGFA = CML_Min(pMatrixIn->nGFA, (uint8)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS);
  /* max angle right side */
  float32 AngMaxRight;
  /* max angle left side */
  /* PRQA S 3121 1 # 2019-05-28 A.Fischer: magic number is justified in this context */
  float32 AngMaxLeft = CML_Deg2Rad(90.0f);
  /* pointer to current GFA */
  const RTE_HLAF_MatrixGFA_t* pGFA;

  /* sorted index array of GFA */
  uint8 GFAIndexSorted[RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS];

  /* initialize array */
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset(&GFAIndexSorted[0], 0, (size_t)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS * sizeof(GFAIndexSorted[0]));

  /* loop over all GFAs */
  for(iGFA = 0; iGFA < numGFA; iGFA++)
  {
    iGFAMax = 0;
    /* Set maximum right angle */
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: magic number is justified in this context */
    AngMaxRight = CML_Deg2Rad(-90.0f);

    /* second loop */
    for(iGFA1 = 0; iGFA1 < numGFA; iGFA1++)
    {
      /* get current GFA */
      pGFA = &pMatrixIn->GFA[iGFA1];

      /* Check if left angle is between left and right border*/
      if(    (pGFA->BndryLeft_Ang > AngMaxRight)
          && (pGFA->BndryLeft_Ang < AngMaxLeft)
        ) 
      {
        /* store index of found GFA */
        iGFAMax = iGFA1;
        /* reduce right border to current GFA value*/
        AngMaxRight = pGFA->BndryLeft_Ang;
      }
    }

    /* fill from left to right */
    GFAIndexSorted[iGFA] = iGFAMax;

    /* reduce left border to boundary left angle */
    AngMaxLeft = AngMaxRight;
  }

  /* fill output struct */
  for(iGFA = 0; iGFA < numGFA; iGFA++)
  {
    /* get index from sorted array */
    iGFA1 = GFAIndexSorted[iGFA];
    /* copy GFA to output struct */
    /* COU_COV_DISABLE: Defensive programming to make sure that no buffers are overwritten and garbage data is read, respectively. */
    /* PRQA S 0315, 3494 1 # 2019-05-06 A.Manz: 0315: Implicit conversion intended, only way how this is working. 3494: Defensive programming */
    (void)memcpy( &pMatrixOut->GFA[iGFA], &pMatrixIn->GFA[iGFA1], CML_Min(sizeof(pMatrixOut->GFA[iGFA]), sizeof(pMatrixIn->GFA[iGFA1])));
    /* COU_COV_ENABLE */
  }

}

/** ************************************************************************************************
  \brief
    Limits the matrix outputs to values specified in internal parameters
  
  \pre
    Valid input pointers.

  \post
    None.

  \param[in]      pMatrixParameters  Pointer to HLA matrix parameters
  \param[in,out]  pMatrixOut         Pointer to HLA matrix output structure

  \return
    void

  \globals
    None

  \InOutCorrelation
    LowBeam_Dist and LowBeam_Ang are limited to the range defined as parameters.
    For all available GFAs all angles and distances are limited to the range defined 
    as parameters, time to border is reset to zero and its status is set to "No object" as well as existence 
    probability is set to 100 percent.
    
  \callsequence
    @startuml
    title Limit GFA output

    start
    :Limit LowBeam_Dist to LowBeam_Dist_Min or LowBeam_Dist_Max;
    :Limit LowBeam_Dist to LowBeam_Ang_Min or LowBeam_Ang_Max;
    :Loop over every GFA;
    :Limit BndryLeft_Ang to BndryLeft_Ang_Min and BndryLeft_Ang_Max;
    :Limit BndryLeft_Ang_Cam to BndryLeft_Ang_Min and BndryLeft_Ang_Max;
    :Limit BndryRight_Ang to BndryRight_Ang_Min and BndryRight_Ang_Max;
    :Limit BndryRight_Ang_Cam to BndryRight_Ang_Min and BndryRight_Ang_Max;
    :Limit BndryLower_Ang_Cam to BndryLower_Ang_Min and BndryLower_Ang_Max;
    :Limit BndryUpper_Ang_Cam to BndryLower_Ang_Min and BndryLower_Ang_Max;
    :Limit ClosestObj_Dist to ClosestObj_Dist_Min and ClosestObj_Dist_Max;
    :Limit ClosestObj_Ang to ClosestObj_Ang_Min and ClosestObj_Ang_Max;
    :Limit MinLight_Dist to MinLight_Dist_Min and MinLight_Dist_Max;
    :Limit MinLight_Ang to MinLight_Ang_Min and MinLight_Ang_Max;
    :Set ttb18Left to zero;
    :Set ttb18Left_Status to RTE_HLAF_TTBSTA_NO_OBJ;
    :Set ttb18Right to zero;
    :Set ttb18Right_Status to RTE_HLAF_TTBSTA_NO_OBJ;
    :Set ExistenceProb to 100;
    :End of GFA loop;
    end

    @enduml
  
  \testmethod

  \traceability
***************************************************************************************************/
HLA_GLOBAL_STATIC void HLAF_LimitOutputs( const t_MatrixParameters* const pMatrixParameters,
                                                RTE_HLAF_Matrix_t*  const pMatrixOut
                                        )
{
  uint32 i;

  /* set low beam distance */
  pMatrixOut->LowBeam_Dist = CML_f_MinMax( pMatrixParameters->Output.LowBeam_Dist_Min,
                                           pMatrixParameters->Output.LowBeam_Dist_Max,
                                           pMatrixOut->LowBeam_Dist
                                          );

  /* set low beam angle */
  pMatrixOut->LowBeam_Ang  = CML_f_MinMax( pMatrixParameters->Output.LowBeam_Ang_Min,
                                           pMatrixParameters->Output.LowBeam_Ang_Max,
                                           pMatrixOut->LowBeam_Ang
                                          );

  /* limit outputs values/ set to default */
  for(i = 0u; i < CML_Min(pMatrixOut->nGFA, (uint32)RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS); i++)
  {
    /* limit outputs */
    /* <ArrayOOBCheck> 2016-04-18 */ /* M.Rameez: i is less than the size of pMatrixOut->GFA (limited to RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS) */
    pMatrixOut->GFA[i].BndryLeft_Ang = CML_f_MinMax( pMatrixParameters->Output.BndryLeft_Ang_Min,
                                                     pMatrixParameters->Output.BndryLeft_Ang_Max,
                                                     pMatrixOut->GFA[i].BndryLeft_Ang
                                                    );
    pMatrixOut->GFA[i].BndryLeft_Ang_Cam = CML_f_MinMax( pMatrixParameters->Output.BndryLeft_Ang_Min,
                                                         pMatrixParameters->Output.BndryLeft_Ang_Max,
                                                         pMatrixOut->GFA[i].BndryLeft_Ang_Cam
                                                        );
    pMatrixOut->GFA[i].BndryRight_Ang = CML_f_MinMax( pMatrixParameters->Output.BndryRight_Ang_Min,
                                                      pMatrixParameters->Output.BndryRight_Ang_Max,
                                                      pMatrixOut->GFA[i].BndryRight_Ang
                                                     );
    pMatrixOut->GFA[i].BndryRight_Ang_Cam = CML_f_MinMax( pMatrixParameters->Output.BndryRight_Ang_Min,
                                                          pMatrixParameters->Output.BndryRight_Ang_Max,
                                                          pMatrixOut->GFA[i].BndryRight_Ang_Cam
                                                         );
    pMatrixOut->GFA[i].BndryLower_Ang_Cam = CML_f_MinMax( pMatrixParameters->Output.BndryLower_Ang_Min,
                                                          pMatrixParameters->Output.BndryLower_Ang_Max,
                                                          pMatrixOut->GFA[i].BndryLower_Ang_Cam
                                                        );
    pMatrixOut->GFA[i].BndryUpper_Ang_Cam = CML_f_MinMax( pMatrixParameters->Output.BndryUpper_Ang_Min,
                                                          pMatrixParameters->Output.BndryUpper_Ang_Max,
                                                          pMatrixOut->GFA[i].BndryUpper_Ang_Cam
                                                        );
    pMatrixOut->GFA[i].ClosestObj_Dist = CML_f_MinMax( pMatrixParameters->Output.ClosestObj_Dist_Min,
                                                       pMatrixParameters->Output.ClosestObj_Dist_Max,
                                                       pMatrixOut->GFA[i].ClosestObj_Dist
                                                      );
    pMatrixOut->GFA[i].ClosestObj_Ang = CML_f_MinMax( pMatrixParameters->Output.ClosestObj_Ang_Min,
                                                      pMatrixParameters->Output.ClosestObj_Ang_Max,
                                                      pMatrixOut->GFA[i].ClosestObj_Ang
                                                     );
    pMatrixOut->GFA[i].MinLight_Dist = CML_f_MinMax( pMatrixParameters->Output.MinLight_Dist_Min,
                                                     pMatrixParameters->Output.MinLight_Dist_Max,
                                                     pMatrixOut->GFA[i].MinLight_Dist
                                                    );
    pMatrixOut->GFA[i].MinLight_Ang = CML_f_MinMax( pMatrixParameters->Output.MinLight_Ang_Min,
                                                    pMatrixParameters->Output.MinLight_Ang_Max,
                                                    pMatrixOut->GFA[i].MinLight_Ang
                                                   );
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
    pMatrixOut->GFA[i].ttb18Left           = 0.0f;
    pMatrixOut->GFA[i].ttb18Left_Status    = RTE_HLAF_TTBSTA_NO_OBJ;
    /* PRQA S 3121 1 # 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
    pMatrixOut->GFA[i].ttb18Right          = 0.0f;
    pMatrixOut->GFA[i].ttb18Right_Status   = RTE_HLAF_TTBSTA_NO_OBJ;
    /* PRQA S 3120 1 # 2019-05-28 A.Fischer: magic number is justified in this context */
    pMatrixOut->GFA[i].ExistenceProb       = 100;
  }
}


/** ************************************************************************************************
  \brief
    Fills the HLA function output data structure
  
  \pre
    Valid input pointers.

  \post
    None.

  \param[in]      pReqPorts          Pointer to request port list
  \param[in]      pFData             Pointer to HLA function data
  \param[in]      pMatrixParameters  Pointer to HLA matrix parameters
  \param[in,out]  pProPorts          Pointer to provide ports structure

  \return
    void

  \globals
    None

  \InOutCorrelation
    Based on data in \c DecisionOut common part of \c HeadLightControl provide port is filled for
    - Traffic Style
    - City
    - Motorway
    - Tunnel
    - Brightness
    - weather state

    Based on detected turnoff reason in \c DecisionData common part of \c HeadLightControl provide port is filled for
    - Speed state

    US sensitivity mode in common part of \c HeadLightControl provide port is set to \c US in case we are in SAE mode 
    (coding parameter and bus signal) or in SAE test mode. In any other case it is set to \c NORMAL.

    Finally, filling of matrix and dimming data is called.

  \callsequence
  
  \testmethod

  \traceability
***************************************************************************************************/
HLA_GLOBAL_STATIC void HLAF_FillOutputData( const reqHlaPrtList_t*    const pReqPorts,
                                            const HLAFData_t*         const pFData,
                                            const t_MatrixParameters* const pMatrixParameters,
                                                  proHlaPrtList_t*    const pProPorts
                                           )
{ 
  /* set US sensitivity mode when we are in SAE test mode or when US-sens mode is available and selected */
  if (   (pReqPorts->pCPar_HlafPar->AlgoCfg.TestMode == (uint8)RTE_HLA_TESTMODE_SAE)
      || (   (pReqPorts->pHlaBusInputSignals->sensitivityModeSignal == (uint8)RTE_HLA_SENSMODE_US)
          && (pReqPorts->pCPar_HlafPar->AlgoCfg.sensitivityMode == (uint8)RTE_HLA_CPAR_SENSITIVITY_MODE_US)
          )
      )
  {
    pProPorts->pHlaf_HeadlightControl->Common.SensMode = RTE_HLA_SENSMODE_US;
  }
  else
  {
    pProPorts->pHlaf_HeadlightControl->Common.SensMode = RTE_HLA_SENSMODE_NORMAL;
  }

  /* -> report current traffic style */
  if(pFData->DecisionOut.eTrafficStyle == (uint8)LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC)
  {
    pProPorts->pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHT;
  }
  else if(pFData->DecisionOut.eTrafficStyle == (uint8)LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC)
  {
    pProPorts->pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHT;
  }
  else
  {
    pProPorts->pHlaf_HeadlightControl->Common.TrafficStyle = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
  }

  /* set city detection state */
  if(pFData->DecisionOut.eCityState == (uint8)RTE_HLAR_CITY_DTCD)
  {
    pProPorts->pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_DTCD;
  }
  else
  {
    pProPorts->pHlaf_HeadlightControl->Common.CityState = RTE_HLAR_CITY_NOT_DTCD;
  }

  /* set tunnel state */
  if(pFData->DecisionOut.eTunnelState == (uint8)LSD_ENVIRONMENT_DATA_TUNNEL_STATE_INSIDE)
  {
    pProPorts->pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_INSIDE;
  }
  else
  {
    pProPorts->pHlaf_HeadlightControl->Common.TunnelState = RTE_HLAR_TUNNEL_NOT_DTCD;
  }

  /* set highway state */
  if(pFData->DecisionOut.eHighwayState == (uint8)LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED)
  {
    pProPorts->pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_MOTORWAY;
  }
  else
  {
    pProPorts->pHlaf_HeadlightControl->Common.MotorwayState = RTE_HLAF_MTWY_COUNTRY;
  }

  /* set brightness state */
  switch (pFData->DecisionOut.eBrightnessState)
  {
  case (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY:
    pProPorts->pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_DAY;
    break;
  case (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1:
    pProPorts->pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_TWLGT_1;
    break;
  case (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2:
    pProPorts->pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_TWLGT_2;
    break;
  case (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3:
    pProPorts->pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_TWLGT_3;
    break;
  case (uint8)LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT:
    pProPorts->pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_NIGHT;
    break;
  default:
    pProPorts->pHlaf_HeadlightControl->Common.BrightnessState = RTE_HLAR_BRT_INVALID;
    break;
  }

  /* set weather state */
  pProPorts->pHlaf_HeadlightControl->Common.WeatherState = pFData->DecisionOut.eWeatherState;
  /* set scene info */
  pProPorts->pHlaf_HeadlightControl->Common.SceneInfo    = pFData->DecisionOut.eSceneInfo;

  /* set speed state */
  if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, (uint32)HLAF_TURN_OFF_REASON_MIN_SPEED) == b_TRUE)
  {
    pProPorts->pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_TOO_LOW;
  }
  else if(CML_GetBit(pFData->DecisionData.TurnOffReason.Reason, (uint32)HLAF_TURN_OFF_REASON_MAX_SPEED) == b_TRUE)
  {
    pProPorts->pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_TOO_HIGH;
  }
  else
  {
    pProPorts->pHlaf_HeadlightControl->Common.SpeedState = RTE_HLAF_SPEEDSTATE_IN_RANGE;
  }
  
  /* set matrix beam output */
  HLAF_FillOutputDataMatrixBeam(pReqPorts,
                                pFData,
                                pMatrixParameters,
                                &(pProPorts->pHlaf_HeadlightControl->Matrix)
                               );
  #if (HLA_DIMMING == STD_ON )
  /* set dimming areas */
  HLAFDimming_FillAreas(&(pFData->DecisionData.DimmingAreas),
                        &(pProPorts->pHlaf_HeadlightControl->Dimming)
                       );
  #endif
}


/** ************************************************************************************************
  \brief
    Fills internal HLA function data.
  
  \pre
    Valid input pointers.

  \post
    None.

  \param[in]      pReqPorts   Pointer to request port list
  \param[in,out]  pFData      Pointer to HLA function data


  \return
    void

  \globals
    \ref timeStampPrevCycle

  \InOutCorrelation
    Timestamp and measurement counter in internal data is taken from the base control data. 

    First of all delta time to previous cycle is calculated. Previous cycle time is updated with current one, then.
    If time difference is bigger than twice \ref ALGO_FUSI_DEBOUNCE_TIME time difference shall be reset to zero and a
    corresponding warning issued. This can happen during simulation if a ECU reset was re-simulated.

    From vdy data the velocity is used to calculate the inter frame distance (vel * time = dist).
    In case motion state from vdy data is in forward direction driven distance and delta time stored to corresponding
    variables (dtimeFwd_s, ddistFwd_m). In all other cases they are zero.

    The inverse of the curve from vdy data is stored as radius in hlaf internal data as well as its absolute value. 
    If curve is zero the radius is limited to 10km.

  \callsequence
  
  \testmethod

  \traceability
***************************************************************************************************/
 HLA_GLOBAL_STATIC void HLAF_FillData( const reqHlaPrtList_t* const pReqPorts,
                                             HLAFData_t*      const pFData
                                      )
{
  const float32 maxRadius = 100000.0f;
  sint64 timeStampDiff;

  /* fill frame counter, timestamps,... */
  pFData->FrameCnt         = pReqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
  pFData->TimeStamp_HLA_ms = pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;

  /* update delta and cycle time and distance since last processed image */
  timeStampDiff = (sint64)pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp - (sint64)timeStampPrevCycle;

  /* wrap around? */
  if(timeStampDiff < 0)
  {
    timeStampDiff += (sint64)UI32_T_MAX;
  }

  /* Too many consecutive frame drops (occurs when re-simulating ECU reset)? -> Reset time difference */
  /* PRQA S 3120 1 # 2019-05-28 A.Fischer: magic number is justified in this context */
  if(timeStampDiff > (2 * ALGO_FUSI_DEBOUNCE_TIME))
  {
    timeStampDiff = 0;
    HLA_ErrorHandling_SetWarning(HLA_WARNING_TIME_DIFF_BETWEEN_TWO_CYCLES_TOO_BIG);
  }

  /* PRQA S 3121 1# 2019-05-28 A.Fischer: magic number is justified in this context */
  pFData->CamData.dtime_s = (float32)timeStampDiff * 0.001f;
  pFData->CamData.ddist_m = pFData->CamData.dtime_s * pReqPorts->pVehDyn->Longitudinal.Velocity;

  /* Store time stamp */
  timeStampPrevCycle = pReqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;

  if(pReqPorts->pVehDyn->MotionState.MotState == (uint8)VDY_LONG_MOT_STATE_MOVE_FWD)
  {
    pFData->CamData.dtimeFwd_s = pFData->CamData.dtime_s;
    pFData->CamData.ddistFwd_m = pFData->CamData.ddist_m;
  }
  else
  {
    /* PRQA S 3121 2# 2019-05-28 A.Fischer: 0.0f can not be considered a magic number */
    pFData->CamData.dtimeFwd_s = 0.0f;
    pFData->CamData.ddistFwd_m = 0.0f;
  }
  
  /* compute radius of curve */
  if(CML_f_IsNonZero(pReqPorts->pVehDyn->Lateral.Curve.Curve) == b_TRUE)
  {
    /* PRQA S 3121 1# 2019-05-28 A.Fischer: 1.0f can not be considered a magic number */
    pFData->CamData.radius_m = 1.0f / pReqPorts->pVehDyn->Lateral.Curve.Curve;
  }
  else
  {
    pFData->CamData.radius_m = maxRadius;
  }
  pFData->CamData.radiusAbs_m = CML_f_Abs(pFData->CamData.radius_m);
#ifdef HLA_CHANGAN_CURVE_FEATURE
  pFData->VehData.swaAbs_deg = CML_f_Abs(pReqPorts->pVehDyn->Lateral.OffCompStWheelAngle);
  pFData->VehData.lataccAbs_ms2 = CML_f_Abs(pReqPorts->pVehDyn->Lateral.Accel.LatAccel);
  pFData->VehData.yawrateAbs_rads = CML_f_Abs(pReqPorts->pVehDyn->Lateral.YawRate.YawRate);
  pFData->VehData.ABSStatus = pReqPorts->pVehSig->Brake.ABSCtrl;
  // todo: RTE change add ESP and UDLC to vehsig
  pFData->VehData.ESPStatus = pReqPorts->pVehSig->VehSigAdd.EspStatus;  /**/
  pFData->VehData.UDLCStatus = pReqPorts->pVehSig->VehSigAdd.UdlcStatus;  /**/
#endif
}

/** ************************************************************************************************
  \brief
    Sends internal HLA data via measFreeze to MTS.
  
  \pre
    None

  \post
    None.

  \param[in]      pfMeasFreeze         Pointer to measFreeze function
  \param[in]      pDecisionParameters  Pointer to HLA function parameters

  \return
    void

  \globals
    \ref hlafData

  \InOutCorrelation
    Performs the measFreeze for HLA function data (\ref hlafData) and its parameters.

  \callsequence
  
  \testmethod

  \traceability
***************************************************************************************************/
static void HLAF_Measfreeze( const AS_t_MeasHdlr               pfMeasFreeze,
                             const t_DecisionParameters* const pDecisionParameters
                            )
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo HlafDataMeasInfo      = {HLA_MEAS_VADDR_HLAF_DATA,      sizeof(hlafData),             TASK_ID_HLA, TASK_ID_HLA};
  AS_t_MeasInfo HlafParameterMeasInfo = {HLA_MEAS_VADDR_HLAF_PARAMETER, sizeof(*pDecisionParameters), TASK_ID_HLA, TASK_ID_HLA};

  /* PRQA S 0314 2 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)pfMeasFreeze(&HlafDataMeasInfo,      (const void*)&hlafData,           NULL);
  (void)pfMeasFreeze(&HlafParameterMeasInfo, (const void*)pDecisionParameters, NULL);

  /* Add number of measfreeze bytes to internal counter */
  HLA_ErrorHandling_AddMeasfreezeAmount(HlafDataMeasInfo.Length);
  HLA_ErrorHandling_AddMeasfreezeAmount(HlafParameterMeasInfo.Length);
#endif
}
