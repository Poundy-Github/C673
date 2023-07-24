/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim.h

DESCRIPTION:               Internal Header of the DIM component

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/06/19 13:18:03CEST $

VERSION:                   $Revision: 1.20 $

LEGACY VERSION:            1.36
  
**************************************************************************** */

/**
@ingroup Medic_dim
@{ **/

#ifndef DIM_H_INCLUDED
#define DIM_H_INCLUDED

#include "frame_medic/medic_int.h"
#include "dim/dim_cfg.h"
#include "dim/dim_par.h"

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)
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
  eDIMInputSignalType_Float       = 0,  /*!< value type is a float        */
  eDIMInputSignalType_SignedInt   = 1,  /*!< value type is a signed int   */
  eDIMInputSignalType_UnsignedInt = 2,  /*!< value type is a unsigned int */
  eDIMInputSignalType_Bool        = 3,  /*!< value type is a bool         */
  eDIMInputSignalType_Max         = 4    
} eDIMInputSignalType_t;

/*! @brief      uint8 DIMInputSignalType_t   */
typedef uint8 DIMInputSignalType_t;

/* Define signal input type values */
/*! @brief       DIMInputSignalType_Float   */
#define DIMInputSignalType_Float         ((DIMInputSignalType_t) eDIMInputSignalType_Float)
/*! @brief       DIMInputSignalType_SignedInt   */
#define DIMInputSignalType_SignedInt     ((DIMInputSignalType_t) eDIMInputSignalType_SignedInt)
/*! @brief       DIMInputSignalType_UnsignedInt   */
#define DIMInputSignalType_UnsignedInt   ((DIMInputSignalType_t) eDIMInputSignalType_UnsignedInt)
/*! @brief       DIMInputSignalType_Bool   */
#define DIMInputSignalType_Bool          ((DIMInputSignalType_t) eDIMInputSignalType_Bool)
/*! @brief       DIMInputSignalType_Max   */
#define DIMInputSignalType_Max           ((DIMInputSignalType_t) eDIMInputSignalType_Max)

/*! @brief       Number of previous input samples to be saved by the differentiator
    @general     differentiator will save this number based on how much previous input samples are available and processed
    @attention   [none]
    @typical     3        @unit [none]     @min 0   @max 65535   */
#define NO_PRE_INPUT_SAMPLES 3

/*! @brief       Number of previous time samples to be saved by the differentiator
    @general     differentiator will save this number based on how much previous time samples are available and processed
    @attention   [none]
    @typical     2        @unit [none]     @min 0   @max 65535   */
#define NO_PRE_TIME_SAMPLES  2

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
  uint32 uiValues;                              /*!< Number of values to be considered in calculation */
} DimIirFilt_t;

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
  uint8  dummy1;                                          /*!< explicit padding */
  uint8  dummy2;                                          /*!< explicit padding */
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
                                  case (DIMInputSignalState_t)DIMInputSignalType_SignedInt: \
                                    (outputValue) = (outputValueType)((pInputSignal).uValue.iValue); \
                                    break; \
                                  case (DIMInputSignalState_t)DIMInputSignalType_UnsignedInt: \
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
                                  case (DIMInputSignalState_t)DIMInputSignalType_SignedInt: \
                                  case (DIMInputSignalState_t)DIMInputSignalType_UnsignedInt: \
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
#define DIMGetInputValue(inputValue, outputValue, defaultValue, outputValueType) \
                                                  do{ \
                                                    switch( (inputValue).eSignalType ) \
                                                    { \
                                                      case DIMInputSignalType_Float: \
                                                        (outputValue) = (outputValueType)((inputValue).uValue.fValue); \
                                                        break; \
                                                      case DIMInputSignalType_SignedInt: \
                                                        (outputValue) = (outputValueType)((inputValue).uValue.iValue); \
                                                        break; \
                                                      case DIMInputSignalType_UnsignedInt: \
                                                        (outputValue) = (outputValueType)((inputValue).uValue.uiValue); \
                                                        break; \
                                                      case DIMInputSignalType_Bool: \
                                                        (outputValue) = (outputValueType) ((((inputValue).uValue.bValue) > 0u) ? TRUE : FALSE); \
                                                        break; \
                                                      default: \
                                                        (outputValue) = (outputValueType)(defaultValue); \
                                                        break; \
                                                    } \
                                                  }while(0)

/*! @brief       DIMGetInputStdDev(inputValue)   */
#define DIMGetInputStdDev(inputValue) ((inputValue).fStdDev)
/*! @brief      DIMGetInputQuality(inputValue)    */
#define DIMGetInputQuality(inputValue)  ((inputValue).eSignalQuality)
/*! @brief       DIMIsInputOK(inputValue)   */
#define DIMIsInputOK(inputValue)       ((((inputValue).eSignalQuality == DIMInputSignalState_OK)) ? TRUE : FALSE)
/*! @brief       BITMASK_UINT8   */
#define BITMASK_UINT8 (0xFFu)
/*! @brief       CLEAR_BIT_UINT8   */
#define CLEAR_BIT_UINT8(source, bitmask) ( (source)&= (uint8)( (~(bitmask)) & BITMASK_UINT8) )

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
  DIMInputValue_t SteeringWheelAngle;         /*!< Steering wheel angle (degree ->left: pos, right: neg)*/
  DIMInputValue_t SteeringWheelGradient;      /*!< Steering wheel angle gradient (degree/s  ->left: pos, right: neg) */
  #if (DIM_CFG_USE_KICKDOWN_INPUT)
  DIMInputValue_t KickDown;                   /*!< KickDown Switch pressed */
  #endif
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
  DIMInputValue_t DriverOverride;             /*!< external driver override signal */
  #endif
  DIMInputValue_t SpeedLimiter;              /*!< SpeedLimiter */    
  #ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
  #if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
  DIMInputValue_t MasterCylPressure;
  #endif
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


#if (DIM_CFG_IN_PREPROC)
extern void DIMRunSigPreProc(float32 fCycleTime, DIMInputDataGlobal_t *pDimInput);
extern void DIMInitSigPreProc(void);
#endif /* DIM_CFG_IN_PREPROC */

extern void DIMFillCustomOut(const float32 fCycleTime, const DIMInputDataGlobal_t *const pInputData);

#endif
#endif /* DIM_H_INCLUDED */
/**@}*/

