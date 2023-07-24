/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20.h

DESCRIPTION:               Internal Header of the DIM component

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/04/23 12:21:48CEST $

VERSION:                   $Revision: 1.14 $
 
**************************************************************************** */

#ifndef DIM20_H_INCLUDED
#define DIM20_H_INCLUDED

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING && MEDIC_CFG_DIM20)

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief eDIMInputSignalType_t

    @general  range of this enum is 0 to 4

    @conseq    [ None ]

    @attention [ None ]

    */
typedef enum 
{
  eDIMInputSignalType_Float = 0,                       /*!<value type is a float*/
  eDIMInputSignalType_SignedInt = 1,                   /*!<value type is a signed int*/
  eDIMInputSignalType_UnsignedInt = 2,                 /*!<value type is a unsigned int*/
  eDIMInputSignalType_Bool = 3,                        /*!<value type is a bool*/
 
  eDIMInputSignalType_Max = 4    
} eDIMInputSignalType_t;

/* ****************************************************************
    TYPEDEF enum eDIMInputSig_t
    **************************************************************** */
    /*! @brief enum for all input signals of DIM

        @general enum for all input signals of DIM

        @conseq [None]

        @attention [None]

        */
typedef enum
{
    VehicleVelocity,
    VehicleAcceleration,
    DriverBraking,
    TurnIndicator,
    GasPedalPosition,
    GasPedalGradient,
    SteeringWheelAngle,
    SteeringWheelGradient,
#if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
    DriverOverride,
#endif
#if (DIM_CFG_USE_KICKDOWN_INPUT)
    KickDown,
#endif
    SpeedLimiter,  /* this is the end of vehicle signals, and from here starts the driver signals. Add all vehicle signals before this */
#if (DIM_CFG_USE_HEADPOSX_INPUT)
    HeadPosX,
#endif
#if (DIM_CFG_USE_HEADPOSY_INPUT)
    HeadPosY,
#endif
#if (DIM_CFG_USE_HEADPOSZ_INPUT)
    HeadPosZ,
#endif
#if (DIM_CFG_USE_HEADYAW_INPUT)
    HeadOrientationYaw,
#endif
#if (DIM_CFG_USE_HEADPITCH_INPUT)
    HeadOrientationPitch,
#endif
#if (DIM_CFG_USE_HEADROLL_INPUT)
    HeadOrientationRoll,
#endif
#if (DIM_CFG_USE_GAZEDIRX_INPUT)
    GazeDirectionX,
#endif
#if (DIM_CFG_USE_GAZEDIRY_INPUT)
    GazeDirectionY,
#endif
#if (DIM_CFG_USE_GAZEDIRZ_INPUT)
    GazeDirectionZ,
#endif
#if (DIM_CFG_USE_FATIGUELVL_INPUT)
    FatigueLevel,
#endif
#if (DIM_CFG_USE_CONVERSATIONLVL_INPUT)
    ConversationLevel,
#endif
#if (DIM_CFG_USE_MULTITASKINGLVL_INPUT)
    MultitaskingLevel,
#endif
#if (DIM_CFG_USE_HEADPOS_CONF_INPUT)
    HeadPosConf,
#endif
#if (DIM_CFG_USE_GAZEDIR_CONF_INPUT)
    GazeDirConf,
#endif
    NUM_OF_SIG
} eDIMInputSig_t;

/*! @brief      uint8 DIMInputSignalType_t   */
typedef uint8 DIMInputSignalType_t;

#define eDIMInputSignalType_UInt DIMInputSignalType_UInt

/* Define signal input type values */
/*! @brief       DIMInputSignalType_Float   */
#define DIMInputSignalType_Float         ((DIMInputSignalType_t) eDIMInputSignalType_Float)
/*! @brief       DIMInputSignalType_SInt   */
#define DIMInputSignalType_SInt          ((DIMInputSignalType_t) eDIMInputSignalType_SignedInt)
/*! @brief       DIMInputSignalType_UInt   */
#define DIMInputSignalType_UInt          ((DIMInputSignalType_t) eDIMInputSignalType_UnsignedInt)
/*! @brief       DIMInputSignalType_Bool   */
#define DIMInputSignalType_Bool          ((DIMInputSignalType_t) eDIMInputSignalType_Bool)
/*! @brief       DIMInputSignalType_Max   */
#define DIMInputSignalType_Max           ((DIMInputSignalType_t) eDIMInputSignalType_Max)

/* ****************************************************************
    TYPEDEF UNION
    **************************************************************** */
/*! @brief Union uDIMInputValueUnion_t

    @general typical structure for HEAD input values

    @conseq [ None ]

    @attention [ None ]

    */
typedef union 
{
  float32 fValue;     /*!< fValue*/  /*PRQA S 3629*//*access with get and set functions*/
  sint32  iValue;     /*!< iValue*/
  uint32  uiValue;    /*!< uiValue*/
  uint32  bValue;     /*!< bValue*/
} uDIMInputValueUnion_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief  Structure DIMInputValue_t

    @general more description here if any,otherwise skip this

    @conseq    [ None ]

    @attention [ None ]

    */
typedef struct 
{
  uDIMInputValueUnion_t uValue;                           /*!< uValue          @size:32 bit  @type:float or sint or uint or bool*/
  float32               fStdDev;                          /*!< fStdDev         @min: 0*/
  DIMInputSignalState_t eSignalQuality;                   /*!< eSignalQuality  @range: 0 to 5*/
  DIMInputSignalType_t  eSignalType;                      /*!< eSignalType     @range: 0 to 4*/
  uint8 dummy1;
  uint8 dummy2;
} DIMInputValue_t;


/*! @brief    This macros reads the value from the union according to the type field. The result value is cast into the target type.
              The goal of this macros is to retain the flexibility of the input value concept, while getting as much type safety as possible.
              The macro cannot be replaced by a single function safely, because this would imply that all values are cast to the most
              generic output type (float) and a possibly result-changing cast to the actual target type. If the macro is replaced by multiple
              functions, the type-dependend "switching" must be executed at each caller site.
 * @param[in] pInputSignal The input value structure from which the data is read.
 * @param[out] outputValue The output value variable where the data is stored.
 * @param[in] defaultValue The default value of the output value if the input value type is not supported.
 * @param[in] outputValueType The type of the output value variable.
 * @param[in] InvalidSignalCount The type of the output value variable.
 * @param[in] GlobalError The type of the output value variable.
 */

/* InvalidSignalCount and GDBError needs to be initialized before calling the macro */
#define DIMGetInputValueMacro(pInputSignal, outputValue, defaultValue, outputValueType, InvalidSignalCount, GlobalError) \
                            do{ \
                              if( (pInputSignal).eSignalQuality == DIMInputSignalState_OK ) \
                              { \
                                switch( (pInputSignal).eSignalType ) \
                                { \
                                  case (DIMInputSignalState_t)DIMInputSignalType_Float: \
                                    (outputValue) = (outputValueType)((pInputSignal).uValue.fValue); \
                                    break; \
                                  case (DIMInputSignalState_t)DIMInputSignalType_SInt: \
                                    (outputValue) = (outputValueType)((pInputSignal).uValue.iValue); \
                                    break; \
                                  case (DIMInputSignalState_t)DIMInputSignalType_UInt: \
                                    (outputValue) = (outputValueType)((pInputSignal).uValue.uiValue); \
                                    break; \
                                  case (DIMInputSignalState_t)DIMInputSignalType_Bool: \
                                    (outputValue) = (outputValueType) ((((pInputSignal).uValue.bValue) > 0u) ? TRUE : FALSE); \
                                    break; \
                                  default: \
                                    (outputValue) = (outputValueType)(defaultValue); \
                                    (InvalidSignalCount)++; \
                                    (GlobalError) = GDB_ERROR_VALUE_RANGE; \
                                    break; \
                                } \
                              } \
                              else \
                              { \
                                (outputValue) = (outputValueType)(defaultValue); \
                                (InvalidSignalCount)++; \
                              } \
                            }while(0)

/*! @brief       DIMGetInputStdDevMacro
 * @param[in]    pInputSignal The input value structure from which the data is read.
 * @param[out]   outputValue The output value variable where the data is stored.
 * @param[in]    defaultValue The default value of the output value if the input value type is not supported.
 * @param[in]    outputValueType The type of the output value variable.
 * @param[in]    InvalidSignalCount The type of the output value variable.
 * @param[in]    GlobalError The type of the output value variable.
 */

#define DIMGetInputStdDevMacro(pInputSignal, outputValue, defaultValue, outputValueType, InvalidSignalCount, GlobalError) \
                            do{ \
                              if( (pInputSignal).eSignalQuality == DIMInputSignalState_OK ) \
                              { \
                                switch( (pInputSignal).eSignalType ) \
                                { \
                                  case (DIMInputSignalState_t)DIMInputSignalType_Float: \
                                    (outputValue) = (outputValueType)((pInputSignal).fStdDev); \
                                    break; \
                                  case (DIMInputSignalState_t)DIMInputSignalType_SInt: \
                                  case (DIMInputSignalState_t)DIMInputSignalType_UInt: \
                                  case (DIMInputSignalState_t)DIMInputSignalType_Bool: \
                                  default: \
                                    (outputValue) = (outputValueType)(defaultValue); \
                                    (InvalidSignalCount)++; \
                                    (GlobalError) = GDB_ERROR_VALUE_RANGE; \
                                    MEDIC_ASSERT(FALSE); \
                                    break; \
                                } \
                              } \
                              else \
                              { \
                                (outputValue) = (outputValueType)(defaultValue); \
                                (InvalidSignalCount)++; \
                              } \
                            }while(0)

/*! @brief     DIMGetInputValue, DIM macro to get Input value
 * @param[in]  pInputSignal The input value structure from which the data is read.
 * @param[out] outputValue The output value variable where the data is stored.
 * @param[in]  defaultValue The default value of the output value if the input value type is not supported.
 * @param[in]  outputValueType The type of the output value variable.
 */
#define DIMGetInputValue(inputValue, outputValue, outputValueType) \
                                                  do{ \
                                                    switch( (inputValue).eSignalType ) \
                                                    { \
                                                      case DIMInputSignalType_Float: \
                                                        (outputValue) = (outputValueType)((inputValue).uValue.fValue); \
                                                        break; \
                                                      case DIMInputSignalType_SInt: \
                                                        (outputValue) = (outputValueType)((inputValue).uValue.iValue); \
                                                        break; \
                                                      case DIMInputSignalType_UInt: \
                                                        (outputValue) = (outputValueType)((inputValue).uValue.uiValue); \
                                                        break; \
                                                      case DIMInputSignalType_Bool: \
                                                        (outputValue) = (outputValueType) ((((inputValue).uValue.bValue) > 0u) ? TRUE : FALSE); \
                                                        break; \
                                                      default: \
                                                        break; \
                                                    } \
                                                  }while(0)

/*! @brief       DIMGetInputStdDev(inputValue)   */
#define DIMGetInputStdDev(inputValue) ((inputValue).fStdDev)
/*! @brief      DIMGetInputQuality(inputValue)    */
#define DIMGetInputQuality(inputValue)  ((inputValue).eSignalQuality)
/*! @brief       DIMIsInputOK(inputValue)   */
#define DIMIsInputOK(inputValue)       ((((inputValue).eSignalQuality == medic_DIMInputSignalState_OK)) ? b_TRUE : b_FALSE)
/*! @brief       BITMASK_UINT8   */
#define BITMASK_UINT8 (0xFFu)
/*! @brief       CLEAR_BIT_UINT8   */
#define CLEAR_BIT_UINT8(source, bitmask) ( (source)&= (uint8)( (~(bitmask)) & BITMASK_UINT8) )

#define DIM_NUM_OF_INPUT  NUM_OF_SIG
/* ****************************************************************
    TYPEDEF STRUCT DIMInputDataGlobal_t
    **************************************************************** */
/*! @brief  Structure DIMInputDataGlobal_t

    @general more description here if any,otherwise skip this

    @conseq    [ None ]

    @attention [ None ]

    */
typedef struct 
{
  DIMInputValue_t VehicleVelocity;            /*!< longitudinal ego vehicle speed (m/s) */
  DIMInputValue_t VehicleAcceleration;        /*!< longitudinal ego vehicle accel (m/s^2)*/
  DIMInputValue_t DriverBraking;              /*!< driver is braking (bool)*/
  DIMInputValue_t TurnIndicator;              /*!< defines the turnlight activity status (0: off, 1: left, 2:right, 3:both)*/
  DIMInputValue_t GasPedalPosition;           /*!< position of the gas pedal (%)*/
  DIMInputValue_t GasPedalGradient;           /*!< GasPedalGradient (%/s)*/
  DIMInputValue_t SteeringWheelAngle;         /*!< Steering wheel angle (° ->left: pos, right: neg)*/
  DIMInputValue_t SteeringWheelGradient;      /*!< Steering wheel angle gradient (°/s  ->left: pos, right: neg) */
#if DIM_CFG_USE_DRV_OVRRDE_INPUT
  DIMInputValue_t DriverOverride;             /*!< external driver override signal */
#endif
  DIMInputValue_t SpeedLimiter;               /*!< SpeedLimiter */    
#if DIM_CFG_USE_KICKDOWN_INPUT
  DIMInputValue_t KickDown;                   /*!< KickDown Switch pressed */
#endif
#if DIM_CFG_USE_HEADPOSX_INPUT
  DIMInputValue_t HeadPosX;                   /*!< Driver head position along X axis */    
#endif
#if DIM_CFG_USE_HEADPOSY_INPUT
  DIMInputValue_t HeadPosY;                   /*!< Driver head position along Y axis */ 
#endif
#if DIM_CFG_USE_HEADPOSZ_INPUT
  DIMInputValue_t HeadPosZ;                   /*!< Driver head position along Z axis */ 
#endif
#if DIM_CFG_USE_HEADYAW_INPUT
  DIMInputValue_t HeadOrientationYaw;         /*!< Driver head orientation along Y axis*/ 
#endif
#if DIM_CFG_USE_HEADPITCH_INPUT
  DIMInputValue_t HeadOrientationPitch;       /*!< Driver head orientation along X axis*/ 
#endif
#if DIM_CFG_USE_HEADROLL_INPUT
  DIMInputValue_t HeadOrientationRoll;        /*!< Driver head orientation along Z axis*/ 
#endif
#if DIM_CFG_USE_GAZEDIRX_INPUT
  DIMInputValue_t GazeDirectionX;             /*!< Driver gaze direction along X axis */    
#endif
#if DIM_CFG_USE_GAZEDIRY_INPUT
  DIMInputValue_t GazeDirectionY;             /*!< Driver gaze direction along Y axis */    
#endif
#if DIM_CFG_USE_GAZEDIRZ_INPUT
  DIMInputValue_t GazeDirectionZ;             /*!< Driver gaze direction along X axis */    
#endif
#if DIM_CFG_USE_FATIGUELVL_INPUT
  DIMInputValue_t FatigueLevel;               /*!< Driver fatigue level from 0 to 6 (0:NA, 1:invalid, 2:awake, 3:questionable, 4:drowsy, 5:beginning to sleeo, 6:sleeping)*/    
#endif
#if DIM_CFG_USE_CONVERSATIONLVL_INPUT
  DIMInputValue_t ConversationLevel;          /*!< Driver conversation level from 0 to 4 (0:NA, 1:invalid, 2:none, 3:medium, 4:heavy)*/    
#endif
#if DIM_CFG_USE_MULTITASKINGLVL_INPUT
  DIMInputValue_t MultitaskingLevel;          /*!< Driver multitasking level from 0 to 4 (0:NA, 1:invalid, 2:none, 3:medium, 4:heavy)*/    
#endif
} DIMInputDataGlobal_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Structure DIMInputData_t

    @general more description here if any,otherwise skip this

    @conseq [ None ]

    @attention [ None ]

    */
typedef struct 
{
  DIMInputDataGlobal_t Global;              /*!< Global */
} DIMInputData_t;

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
  DIM_STATE_INIT   = 0u,                /*!> initialize all    */
  DIM_STATE_OK     = 1u                 /*!> normal processing */
} DIMState_t;


#endif
#endif /* DIM_MAIN_H_INCLUDED */

