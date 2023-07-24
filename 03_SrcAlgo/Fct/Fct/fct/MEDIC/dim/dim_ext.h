/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_ext.h

DESCRIPTION:               External Header of the DIM component

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:37:36CEST $

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            1.24.1.1
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_EXT_INCLUDED
#define DIM_EXT_INCLUDED

#include "dim/dim_autoversion.h"
#include "dim/dim_cfg.h"
#include "dim/dim_par.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  MACROS
*****************************************************************************/

/*==============================================================================================================================================*/

/*! @brief       Dim internal hypotheses count of EBA
    @general     No. of EBA Hypotheses in DIM Module
    @conseq      @incp  DIM will iterate one more count for EBA hypothesis check
                 @decp  DIM will iterate one less count for EBA hypothesis check
    @attention   [None]
    @typical     NA
    @unit        1 Count
    @min         1
    
*/
#define DIM_NR_OF_EBA_HYPOTHESES (3u)


/*! @brief       FeedBack buffer size

    @general     Dim feedback buffer size used for Accelbuffer

    @conseq      [none]

    @attention   [none]

    @typical     [none]     @unit [none]    @min 0    @max 20   */
#define DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE (20u)


/*! @brief       Number of calibrating hypotheses 
    @general     Number of calibrating hypotheses in DIM Module
    @conseq      @incp  DIM will have one more Calibrating hypothesis to check
                 @decp  DIM will have one less Calibrating hypothesis to check
    @attention   [None]
    @typical     NA   
    @unit        1 Count     
    @min         1       */
#define DIM_NO_CALIB_HYPS     3u 


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/* ****************************************************************
    TYPEDEF ENUM DIMState_t
   **************************************************************** */
/*! @brief DIM operating modes.

    @general range of this enum is from 0 to 1
    
    @conseq [None]
    
    @attention [None]
    
    */
typedef enum
{
  DIM_STATE_INIT = 0u,                /*!> initialize all    */
  DIM_STATE_OK   = 1u                 /*!> normal processing */
} DIMState_t;

/* ****************************************************************
    TYPEDEF STRUCT DIMHypothesisList_t
   **************************************************************** */
/*! @brief DIM Hypothesis List

    @general It contains total list of DIM_EBA, DIM_SI Hypothesis
    
    @conseq [None]
    
    @attention [None]
    
    */
typedef struct 
{
  GDB_DMHypothesis_t rgDimHypEBA[DIM_NR_OF_EBA_HYPOTHESES];   /*!< Array of the Driver Intention Monitor Hypotheses for EBA */
} DIMHypothesisList_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief     Structure for DIMInternalDataModAttention_t

    @general 

    @conseq    [ None ]

    @attention [ None ]

    */
typedef struct 
{
  sint16  iProbability;          /*!< save hypothesis probability @unit:%  @range: -100 to +100*/
  sint16  iConfidence;           /*!< save hypothesis confidence @unit:%  @range: -100 to +100*/
  float32 fVeryHighKeepTime;     /*!< current timer for very high attention time  @unit:s  @min:0*/
  float32 fHigherKeepTime;       /*!< current timer for very high attention time  @unit:s  @min:0*/
  float32 fHighKeepTime;         /*!< current timer for high attention time @unit:s  @min:0*/
  float32 fLowKeepTime;          /*!< current timer for low attention time @unit:s  @min:0*/
  float32 fConstVelTime;         /*!< current time of const velocity @unit:s  @min:0*/
  float32 fNoGasPedalGradTime;   /*!< current timer of no gas pedal gradients time @unit:s  @min:0*/
  float32 fConstVelocity;        /*!< current stored velocity @unit:m/s  @min:0*/
} DIMInternalDataModAttention_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Dim data modfeedback

    @general All data for feedback are clubed for data feedback

    @conseq [none]

    @attention [none]

    */
typedef struct 
{
  sint16  iProbability;         /*!< save hypothesis probability @unit:%  @range: -100 to +100*/
  sint16  iConfidence;          /*!< save hypothesis confidence @unit:%  @range: -100 to +100*/  
  float32 fNegFeedbackTime;     /*!< timer for negative feedback  @unit:s  @min:0*/
  #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
  float32 fNegWeakFeedbackTime; /*!< timer for negative feedback  @unit:s  @min:0*/
  #endif
  float32 fPosFeedbackTime;     /*!< timer for positive feedback  @unit:s  @min:0*/
  float32 fFallIntoBrakeTime;   /*!< timer for not falling into brake @unit:s  @min:0*/
  float32 fCurrentAccelGrad;    /*!< current  @unit:m/s^3*/
  boolean bDriverWasBraking;    /*!< driver was braking in the last n cycles  @unit:bool*/
  uint8   uiAccelBufferPointer; /*!< current position in AccelBuffer  @range: 0 to 65,535*/  
  sint8   iAccelBuffer[DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE]; /*!< buffer for last accelerations (scaled by 10)  @unit:m/s^2 @resolution:0.1*/
  boolean bBoolBuffer[DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE]; /*!< buffer where the information "driver braking"  @unit:bool*/
} DIMInternalDataModFeedback_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief DIM Activity hypothesis structure

    @general Structure to save DIM module activity hypothesis parameters

    @conseq [None] 

    @attention [None]

    */
typedef struct 
{
  sint16 iProbability;          /*!< save hypothesis probability @unit:%  @range: -100 to +100*/
  sint16 iConfidence;           /*!< save hypothesis confidence @unit:%   @range: -100 to +100*/
  float32 fActivityLowTimer;    /*!< current timer for low activity time  @unit:s*/
  float32 fActivityTimer;       /*!< current timer for activity time  @unit:s  min:0*/
  float32 fActivityHoldTimer;   /*!< current timer for activity hold time  @unit:s  min:0*/
  float32 fGradPeakTimer;       /*!< current timer for Steering Wheel Gradien Peak @unit:s  min:0*/
  float32 fEmergencySteerTimer; /*!< current timer for emergency steering time  @unit:s  min:0*/
  float32 fGradLowPassTimer;    /*!< current timer for Steering Wheel Gradient Filter  @unit:s  min:0*/
  float32 fGradLowPassOutput;   /*!< current output of the Steering Wheel Gradient Filter @unit:degree/s*/
} DIMInternalDataModActivity_t;

/* ****************************************************************
    TYPEDEF STRUCT DIMInteralDataEBA_t
    **************************************************************** */
/*! @brief DIM Internal EBA Data Structure

    @general Internal Data Structure holding different DIM EBA Hypothesis

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  DIMInternalDataModAttention_t Internal_Attention; /*!< DIM Internal Attention */
  DIMInternalDataModFeedback_t  Internal_Feedback;/*!< DIM Internal Feedback */
  DIMInternalDataModActivity_t  Internal_Activity;/*!< DIM Internal Activity */
} DIMInteralDataEBA_t;

/* ****************************************************************
    TYPEDEF STRUCT DIMData_t
 **************************************************************** */
/*! @brief DIM Data Structure

    @general DIM Data Structure with DIMMTSHeaderData_t, DIMInputData_t, DIMInteralDataEBA_t, DIMInteralDataALDW_t and DIMInteralDataSI_t members

    @conseq [None]

    @attention [None]
    */
typedef struct 
{
  DIMMTSHeaderData_t   DIMHeaderData;                   /*!< Header                   */
  DIMInputData_t       DimInputData;                    /*!< DIM input data           */
  #if (DIM_CFG_HYPO_EBA)
  DIMInteralDataEBA_t Internal_Data_EBA;                /*!< DIM module internal data */
  #endif
} DIMData_t;


/* Dynamic Data - Adding to DIMData will exceed address range */
#if (DIM_CFG_OUT_CALIB)
/* ****************************************************************
    TYPEDEF STRUCT DIM_HYPOUT_CAL_DATA_t
    **************************************************************** */
/*! @brief      Stuck specific hypothesis output value

    @general    This parameter provides the opportunity to calibrate the value of specific driver hypothesis.
                Parameter is indented to use for vehicle test in order to avoid driver intention to delay or 
                suppress desired interventions
    
    @conseq     As soon as calibration mask is set different from zero, the output value for hypothesis 
                corresponding to bit position is defined parameter value instead of the calculated one. 
    
    @attention  [None]
    */
typedef struct 
{ 
  uint8         CalibMask;                               /*!< bit0: attention, bit1: feedback, bit2: activity */
  sint8         Probability[DIM_NO_CALIB_HYPS];          /*!< -100 -> +100%*/
  percentage_t  Confidence[DIM_NO_CALIB_HYPS];           /*!< hypothesis confidence*/          
} DIM_HYPOUT_CAL_DATA_t;
#else
typedef uint8 DIM_HYPOUT_CAL_DATA_t ; /* dummy definition to save memory */
#endif // DIM_CFG_OUT_CALIB

/*****************************************************************************
  VARIABLES
*****************************************************************************/



/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
extern void DIM_v_SetState(const  DIMState_t t_DIMOpModeValue);
extern void DIMInit(const float32 fCycleTime);
extern void DIMProcess(const float32 fCycleTime);

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* DIM_EXT_INCLUDED */
/**@}*/

