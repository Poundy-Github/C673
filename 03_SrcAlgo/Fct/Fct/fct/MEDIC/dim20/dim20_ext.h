/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_ext.h

DESCRIPTION:               External Header of the DIM component

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/07/29 15:03:36CEST $

VERSION:                   $Revision: 1.20 $
  
**************************************************************************** */

#ifndef DIM20_EXT_INCLUDED
#define DIM20_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "dim20/dim20_autoversion.h"
#include "dim20/dim20_cfg.h"
#if (DIM_CFG_HYPO_EBA)
#include "dim20/dim20_eba.h"
#endif
#include "dim20/dim20.h"

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
#define DIM_NR_OF_EBA_HYPOTHESES            (3u)
#define DIM_NO_CALIB_HYPS                   (3u)
#define NUM_OF_GAZE_ZONES                   (6u)
/*! @brief       FeedBack buffer size
    @general     Dim feedback buffer size used for Accelbuffer
    @conseq      none
    @attention   none
    @typical     none     @unit none    @min 0    @max 20   */
#define DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE   (20u)


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
  GDB_DMHypothesis_t rgDimHypEBA[DIM_EBA_HYP_MAX];   /*!< Array of the Driver Intention Monitor Hypotheses for EBA */
} DIMHypothesisList_t;

/* ****************************************************************
    TYPEDEF STRUCT uDIMInputGlobalUnion_t
 **************************************************************** */
/*! @brief DIM data union for MTS

    @general union with members accessed as strutures and array

    @conseq [None]

    @attention [None]

    */
typedef union 
{
  DIMInputDataGlobal_t Global;
  DIMInputValue_t aDIMInputGlobal[NUM_OF_SIG];
} uDIMInputGlobal_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief     Structure for DIMInternalDataModAttention_t

    @general 

    @conseq    None

    @attention None

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

    @conseq none

    @attention none

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

    @conseq none 

    @attention none

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
  float32 fGradLowPassOutput;   /*!< current output of the Steering Wheel Gradient Filter @unit:°/s*/
} DIMInternalDataModActivity_t;

#if (DIM_CFG_HYPOTHESIS_AOI_SEEN||DIM_CFG_HYPOTHESIS_OBJECTSEEN)

/* ****************************************************************
    TYPEDEF STRUCT DIMGazeZonePosition_t
    **************************************************************** */
/*! @brief driver gaze zone thresholds

    @general Structure to save DIM module object-seen hypothesis parameters

    @conseq none 

    @attention none

    */
typedef struct
{
  float32 fZonePosition[2]; /*!< indicates the angle with reference to driver at which the gaze zone starts along horizontal plane @unit:° */
} DIMGazeZonePosition_t;

/* ****************************************************************
    TYPEDEF STRUCT DIMGazeZoneData_t
    **************************************************************** */
/*! @brief driver gaze zone parameters

    @general Structure to save driver LoS parameters

    @conseq none 

    @attention none

    */
typedef struct
{
  float32 iCurrentCycProb;                /*!< save zone seen probability @unit:prob  @range: 0 to 1*/
  float32 iConfidence;                    /*!< save zone seen confidence @unit:prob   @range: -100 to +100*/
  float32 fMeanProb;                      /*!< save zone seen confidence @unit:prob   @range: 0 to 1*/
} DIMGazeZoneData_t;

/* ****************************************************************
    TYPEDEF STRUCT DIMInternalDataModObjectSeen_t
    **************************************************************** */
/*! @brief DIM Object-Seen hypothesis structure

    @general Structure to save DIM module object-seen hypothesis parameters

    @conseq none 

    @attention none

    */
typedef struct 
{
  #if (DIM_CFG_HYPOTHESIS_OBJECTSEEN)
  uint8 uObjectSeenProbLevel[ACDC_MAX_NUM_OF_HYPS]; /*!< save object seen probability @unit:%  @range: -100 to +100*/
  #endif
  DIMGazeZoneData_t GazeZones[NUM_OF_GAZE_ZONES];   /*!< save gaze zone parameters */
  float32 fLineOfSightAngle;                        /*!< save the direction of LOS with respect to x, y axes, which is also mu @unit:°*/
  float32 fStdDev;                                  /*!< standard deviation for probability normal distribution */
  float32 uDriverFoVLeftEnd;                        /*!< left boundary of driver FoV */
  float32 uDriverFoVRightEnd;                       /*!< right boundary of driver FoV */
  uint8 uNumOfGazeZones;                            /*!< number of zones to which the driver FoV is divided */
  uint8 uiModuleCycleCounter;
} DIMInternalDataModDriverLoS_t;
#endif

/* ****************************************************************
    TYPEDEF STRUCT DIMInteralDataEBA_t
    **************************************************************** */
/*! @brief DIM Internal EBA Data Structure

    @general Internal Data Structure holding different DIM EBA Hypothesis

    @conseq none

    @attention none

    */
typedef struct 
{
  DIMInternalDataModAttention_t Internal_Attention; /*!< DIM Internal Attention    */
  DIMInternalDataModFeedback_t  Internal_Feedback;  /*!< DIM Internal Feedback     */
  DIMInternalDataModActivity_t  Internal_Activity;  /*!< DIM Internal Activity     */
  #if (DIM_CFG_HYPOTHESIS_AOI_SEEN||DIM_CFG_HYPOTHESIS_OBJECTSEEN)
  DIMInternalDataModDriverLoS_t Internal_LineOfSight;/*!< DIM Internal Object-Seen  */
  #endif
} DIMInteralDataEBA_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
    /*! @brief Structure DIMMTSHeaderData_t

     @general more description here if any,otherwise skip this

     @conseq    [ None ]

     @attention [ None ]

        */
typedef struct
{
  uint32 uiBaseVersion;               /*!< uiBaseVersion*/
  uint32 uiStructSize;                /*!< @unit:bytes  @range: 0 to 65,535*/
} DIMMTSHeaderData_t;

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
  DIMMTSHeaderData_t  DIMHeaderData;                   /*!< @name:Header*/
  uDIMInputGlobal_t   DimInputData;
  #if (DIM_CFG_HYPO_EBA)
  DIMInteralDataEBA_t Internal_Data_EBA;                /*!< DIM module internal data*/
  #endif
  float32 DimCustOutput1;
  uint32              uDummy;                           /*!< Align for MTS */
} DIMData_t;

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
  uint32        uDummy;                                  /*!< Align for MTS */
} DIM_HYPOUT_CAL_DATA_t;
#else
typedef uint8 DIM_HYPOUT_CAL_DATA_t; /* dummy definition to save memory */
#endif

#if (DIM_CFG_IN_PREPROC)
/* ****************************************************************
    TYPEDEF STRUCT DimIirFilt_t
    **************************************************************** */
    /*! @brief Differentiator structure for calculation of the DIM steering wheel angular velocity

    @general Differentiator structure for calculation of the DIM steering wheel angular velocity

    @conseq [None]

    @attention [None]

        */
typedef struct
{
  float32 fInputs[NO_PRE_INPUT_SAMPLES];        /*!< Array of previous input samples */
  float32 fCycleTimes[NO_PRE_TIME_SAMPLES];     /*!< Array of previous cycle time samples */
  uint32  uiValues;                             /*!< Number of values to be considered in calculation */
} DimIirFilt_t;
#endif

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/*external functions*/
extern void DIMProcess( const float32 fCycleTime );
extern void DIMInit(void);

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* DIM_EXT_INCLUDED */

