/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrix.h

  DESCRIPTION:            HLA matrix beam function.

  CREATION DATE:          2012-11-05
  
  CPU:                    Independent

  VERSION:                $Revision: 1.15.1.1 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLAF_MATRIX_H
#define H_HLAF_MATRIX_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_type.h"
#include "HLA_MatrixParameters.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  GLOBAL FUNCTIONS DECLARATION 
*****************************************************************************/
/** ************************************************************************************************
  \brief  
    Initializes GFA data and internal object list.
  
  \pre
    None

  \post
    None

  \param [in,out]  pFData  Pointer to HLA function data

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Calls HLAFMatrixGFA_Init() to initialize GFA data and HLAFMatrix_InitObjectList() to initialize
    internal object list.

  \callsequence
    @startuml 
    title Sequence diagram of HLAFMatrix_Init()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_matrix.c    as this
    participant hlaf_matrixgfa.c    as matrixgfa
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_v_Init()**"" calls\n""**HLAFMatrix_Init()**""
    Activate this
    this ->> matrixgfa: Init glare free areas
    Activate matrixgfa
    matrixgfa -->> this: void
    Deactivate matrixgfa
    this ->> this: Init internal object list
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFMatrix_Init(HLAFData_t* const pFData);

/** ************************************************************************************************
  \brief  
    Initializes matrix output data to zero.
  
  \pre
    None

  \post
    None

  \param [in,out]  pOut  Pointer to matrix output data

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Memset of the HLAFMatrixOut_t struct.

  \callsequence
    @startuml 
    title Sequence diagram of HLAFMatrix_InitOutput()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_matrix.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFMatrix_InitOutput()**""
    Activate this
    this ->> this: Set matrix out struct to zero
    this -->> Main: void
    Deactivate this
    @enduml

  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFMatrix_InitOutput(HLAFMatrixOut_t* const pOut);

/** ************************************************************************************************
  \brief  
    Copies the internal matrix data to output structure and sets the GFA status.
  
  \pre
    GFA calculation was performed.

  \post
    None

  \param [in]      pData                  Pointer to internal matrix structure
  \param [in]      calibrationConfidence  Confidence from 0..100 how trustworthy the LSD outputs are 
                                          compared to reality.
  \param [in,out]  pOutNext               Pointer to output matrix structure

  \return
    Void

  \globals
    None

  \InOutCorrelation
    The GFA status is set to valid depending on calibration confidence of LSD. The calibration confidence must
    be 100% and turn off reason blockage is not set. Then GFA status is set to valid. If GFAs exist (high beam
    off and nGFA > 0) they are copied from internal list to output structure. If none exist, nothing is copied.

    @startuml
    title HLAFMatrix_SetOutput()
    
    start
    if(Calibration is below 100 or turn off reason blockage is set) then (Yes)
      :Set GFAStatus to invalid;
    else(No)
      :Set GFAStatus to valid;
    endif
    if(HB off and nGFA is at least 1) then (Yes)
      :Copy GFA data to output interface;
    else(No)
    endif
    end
    
    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFMatrix_SetOutput()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_matrix.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFMatrix_SetOutput()**""
    Activate this
    this ->> this: Set GFA data in output struct
    this -->> Main: void
    Deactivate this
    @enduml
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFMatrix_SetOutput( const HLAFMatrixData_t* const pData,
                           const uint8                   calibrationConfidence,
                                 HLAFMatrixOut_t*  const pOutNext
                          );

/** ************************************************************************************************
  \brief  
    Depending on the provided HLA function data the turn off reasons will be set in the output
    structure.
  
  \pre
    Global turn off reasons are set.

  \post
    None

  \param [in]      pFData    Pointer to HLA function data
  \param [in,out]  pOutNext  Pointer to output matrix structure

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Depending on the provided HLA function data the turn off reasons will be set in the output
    structure. The TurnOffReason is set to unknown, then all turn off reasons in the decision
    data is checked and the according turn off reason in the matrix out structure is set. For the
    delay it is check if the high beam is off, but no other turn off reason was set, which means
    that there is no global turn off reasons but e.g. a keep off reason like a delay, which keeps
    the high beam off.\n
    Every global turn off reason corresponds to a turn off reason in the matrix struct. The details
    of the mapping are visualized in the image below.

    @startuml
    title Mapping of turn off reasons to output interface
    legend left
    Mapping of turn off reasons to output interface

    |  | Internal Data (pFData->DecisionData.TurnOffReason.Reason) | Turn Off Reason Bit|
    | City | HLAF_TURN_OFF_REASON_CITY | RTE_HLAF_TURNOFFREASON_CITY |
    | Tunnel | HLAF_TURN_OFF_REASON_TUNNEL | RTE_HLAF_TURNOFFREASON_TUNNEL |
    | Brightness | HLAF_TURN_OFF_REASON_BRIGHTNESS | RTE_HLAF_TURNOFFREASON_BRIGHTNESS |
    | Min Speed | HLAF_TURN_OFF_REASON_MIN_SPEED or\n HLAF_TURN_OFF_REASON_MAX_SPEED | RTE_HLAF_TURNOFFREASON_SPEED |
    | Oncoming Vehicle | HLAF_TURN_OFF_REASON_ONCOMING or \n HLAF_TURN_OFF_REASON_EM_OBJECT_ONC | RTE_HLAF_TURNOFFREASON_ONC |
    | Preceding Vehicle | HLAF_TURN_OFF_REASON_PRECEDING or \n HLAF_TURN_OFF_REASON_EM_OBJECT_PREC or \n HLAF_TURN_OFF_REASON_RADAR_OBJECT | RTE_HLAF_TURNOFFREASON_PREC |
    | Blockage | HLAF_TURN_OFF_REASON_BLOCKAGE | RTE_HLAF_TURNOFFREASON_BLOCKAGE |
    | Fog | HLAF_TURN_OFF_REASON_FOG | RTE_HLAF_TURNOFFREASON_FOG |
    | Bad Weather | HLAF_TURN_OFF_REASON_BAD_WEATHER | RTE_HLAF_TURNOFFREASON_WEATHER |
    | Delay | Matrix.TurnOffReason == 0 and\n Matrix.HighBeamState == RTE_HLAF_HB_STATE_OFF | RTE_HLAF_TURNOFFREASON_DELAY |

    end legend

    @enduml

  \callsequence
    @startuml 
    title Sequence diagram of HLAFMatrix_SetTurnOffReason()

    box "Function" #LightGreen
    participant hlaf.c       as Main
    participant hlaf_matrix.c    as this
    end box

    autonumber "<b>[00]"
    Main ->> this: ""**HLAF_SetLightStates()**"" calls\n""**HLAFMatrix_SetTurnOffReason()**""
    Activate this
    this ->> this: Set turn off reasons on basis of decision data
    this -->> Main: void
    Deactivate this
    @enduml

  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLAFMatrix_SetTurnOffReason( const HLAFData_t*      const pFData,
                                        HLAFMatrixOut_t* const pOutNext
                                );

#ifdef PC_SIM
void HLAFMatrixMeasfreeze( const AS_t_MeasHdlr             pfMeasFreeze,
                           const t_MatrixParameters* const pMatrixParameters,
                           const HLAFMatrixData_t*   const pHlafMatrixData
                         );
#endif

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLAF_MATRIX_H */ 
