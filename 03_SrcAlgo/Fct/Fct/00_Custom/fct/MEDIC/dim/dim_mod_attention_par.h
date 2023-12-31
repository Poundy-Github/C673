/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_attention_par.h

DESCRIPTION:               header of the DIM driver attention parameters

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/11/25 15:13:59CET $

VERSION:                   $Revision: 1.1.2.9 $

LEGACY VERSION:            1.18
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_MOD_DRV_ATT_PAR_INCLUDED
#define DIM_MOD_DRV_ATT_PAR_INCLUDED

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)
/*---- default values ------*/
/*! @brief      DIM_ATTENTION_DEFAULT_DrvBraking
    @general    -
    @conseq     -
    @attention  -
    @typical    FALSE    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_DrvBraking         (FALSE)

/*! @brief      DIM_ATTENTION_DEFAULT_GasPedalPos
    @general    -
    @conseq     -
    @attention  -
    @typical    100.0f    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_GasPedalPos        (100.0f)

/*! @brief      DIM_ATTENTION_DEFAULT_GasPedalGrad
    @general    -
    @conseq     -
    @attention  -
    @typical    0.0f    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_GasPedalGrad       (0.0f)

/*! @brief      DIM_ATTENTION_DEFAULT_TurnIndicator
    @general    -
    @conseq     -
    @attention  -
    @typical    3u    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_TurnIndicator      (3u)

/*! @brief      DIM_ATTENTION_DEFAULT_SteeringWheelGrad
    @general    -
    @conseq     -
    @attention  -
    @typical    0.0f    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_SteeringWheelGrad  (0.0f)

/*! @brief      DIM_ATTENTION_DEFAULT_LongAccel
    @general    -
    @conseq     -
    @attention  -
    @typical    0.0f    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_LongAccel          (0.0f)

/*! @brief      DIM_ATTENTION_DEFAULT_LongVelocity
    @general    -
    @conseq     -
    @attention  -
    @typical    0.0f    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_DEFAULT_LongVelocity       (0.0f)

/*---- definitions ------*/

/*! @brief      DIM_ATTENTION_PAR_VeryHighPercentage
    @general    -
    @conseq     -
    @attention  -
    @typical    100    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_VeryHighPercentage     (100)

/*! @brief      DIM_ATTENTION_PAR_HigherPercentage
    @general    -
    @conseq     -
    @attention  -
    @typical    90    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_HigherPercentage       (90)

/*! @brief      DIM_ATTENTION_PAR_HighPercentage
    @general    -
    @conseq     -
    @attention  -
    @typical    66    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_HighPercentage         (66)

/*! @brief      DIM_ATTENTION_PAR_LowPercentage
    @general    -
    @conseq     -
    @attention  -
    @typical    33    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_LowPercentage          (33)

/*! @brief      DIM_ATTENTION_PAR_UnknownPercentage
    @general    -
    @conseq     -
    @attention  -
    @typical    0    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_UnknownPercentage      (0)

/*! @brief      DIM_ATTENTION_PAR_NormalConfidence
    @general    -
    @conseq     -
    @attention  -
    @typical    100    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_NormalConfidence       (100)

/*! @brief      DIM_ATTENTION_PAR_MissingConfidenceDelta
    @general    -
    @conseq     -
    @attention  -
    @typical    20    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_MissingConfidenceDelta (20)

/*---- parameters -------*/
/*! @brief      DIM_ATTENTION_PAR_PROP_THRES_UNKN
    @general    -
    @conseq     -
    @attention  -
    @typical    25    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PROP_THRES_UNKN        (25)

/*! @brief      DIM_ATTENTION_PROP_THRES_LOW
    @general    -
    @conseq     -
    @attention  -
    @typical    50    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PROP_THRES_LOW         (50)

/*! @brief      DIM_ATTENTION_PROP_THRES_HIGH
    @general    -
    @conseq     -
    @attention  -
    @typical    75    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PROP_THRES_HIGH        (75)

/*! @brief      DIM_ATTENTION_PROP_THRES_HIGHER
    @general    -
    @conseq     -
    @attention  -
    @typical    95    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PROP_THRES_HIGHER      (95)

/*! @brief      DIM_ATTENTION_PAR_AccelCurve_POINTS
    @general    -
    @conseq     -
    @attention  -
    @typical    2    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_AccelCurve_POINTS (4)
/*! @brief      DIM_ATTENTION_PAR_GasPedalPosCurve_POINTS
    @general    -
    @conseq     -
    @attention  -
    @typical    2    @unit  -   @min -   @max -   */
#define DIM_ATTENTION_PAR_GasPedalPosCurve_POINTS (2)

/*! @brief      Driver pedal position to detect kick-down during limiter 
                (long. velocity) mode
    @general    During kick-down driver attention is assumed to be attentive
    @conseq     @incp  (+) earlier detection of kick-down
                @decp  (-) later detection of kick-down
    @attention  -
    @typical    95    @unit  %   @min 50.0   @max 100.0   */
#define DIM_ATTENTION_PAR_GasPedal_KickDown  95.0F

#if (DIM_CFG_USE_KICKDOWN_INPUT)
/*! @brief      Driver gas pedal position set when KickDown Switch is pressed
    @general    Set value for driver gas pedal position in KickDown
    @conseq     -
    @attention  -
    @typical    100.0    @unit  %   @min 0.0   @max 100.0   */
#define DIM_ATTENTION_PAR_GasPedal_KickDown_Value 100.0F
#endif

/*! @brief      Driver pedal position set value to inhibit influence on driver attention 
                estimation
    @general    Passive set value to ignore driver pedal position
    @conseq     -
    @attention  -
    @typical    5.0    @unit  %   @min 0.0   @max 10.0   */
#define DIM_ATTENTION_PAR_GasPedal_Passive_Value 5.0F

/* ****************************************************************
    TYPEDEF STRUCT DIM_ATTENTION_PAR_struct_t
    **************************************************************** */
/*! @brief DIM_ATTENTION_PAR_struct_t
    @general please refer to dim_mod_attention_par_eba.c for values of this structure.
    @conseq [ None ]
    @attention [ None ] */
typedef struct 
{
  CML_t_Vector2D fAccelCurve[DIM_ATTENTION_PAR_AccelCurve_POINTS];             /*!< @values: CML_t_Vector2D[DIM_ATTENTION_PAR_AccelCurve_POINTS]*/
  CML_t_Vector2D fGasPedalPosCurve[DIM_ATTENTION_PAR_GasPedalPosCurve_POINTS]; /*!< @values: CML_t_Vector2D[DIM_ATTENTION_PAR_GasPedalPosCurve_POINTS]*/
  float32 fGasPedalGradLowPositive;           /*!< 100%/s for low feedback*/
  float32 fGasPedalGradLowNegative;           /*!< -40%/s for low feedback*/
  float32 fGasPedalLowNegMeasured;            /*!< -4%/s lowest measurable negative gradient*/
  float32 fGasPedalLowNegMeasuredPos;         /*!< 1% lowest measurable real gas pedal position*/
  float32 fRobotControlledVelocityThresh;     /*!< tolerance for detection of constant velocity*/
  float32 fNoGasPedalGradientThresh;          /*!< tolerance for detection of very low gas pedal gradients*/
  float32 fSteeringGradLow;                   /*!< 100 degree per second steering wheel angle gradient for low attention*/
  float32 fVeryHighTime;                      /*!< 1.5s*/
  float32 fHigherTime;                        /*!< 1.5s*/
  float32 fHighTime;                          /*!< 1.0s*/
  float32 fLowTime;                           /*!< 2.5s*/
  float32 fRobotControlledVelocityTime;       /*!< timer to detect very constant velocity*/
  float32 fNoGasPedalGradientTime;            /*!< timer to detect only very low gas pedal gradients*/
  float32 fLowKeepRobotTime;                  /*!< if robot was detected fLowTime is set to this*/
  float32 fTurnIndicatorMinVelocity;          /*!< min. velocity to use turn indicator */
  float32 fBrakePedalMaxVelocity;             /*!< max. velocity to use driver braking for higher attention */
  float32 fDriverBrakingMaxAcceleration;      /*!< min. deleleration to use driver braking */
} DIM_ATTENTION_PAR_struct_t;

#endif
#endif /*_DIM_MOD_DRV_ATT_PAR_INCLUDED*/
/**@}*/
