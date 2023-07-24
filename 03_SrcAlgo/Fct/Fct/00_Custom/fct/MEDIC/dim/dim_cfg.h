/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_cfg.h

DESCRIPTION:               cfg of the DIM driver 

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2019/09/13 12:00:12CEST $

VERSION:                   $Revision: 1.2.2.11 $

LEGACY VERSION:            1.10.1.4
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_CFG_H_INCLUDED
#define DIM_CFG_H_INCLUDED

#include "frame_medic/medic_cfg.h"

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*
  Config: Component DIM Driver Intention Monitoring
**************************************************************************/

/*! @brief       DIM_CFG_HYPO_EBA
    @general     Enable DIM for EBA
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_HYPO_EBA                MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

/*! @brief       DIM_CFG_HYPO_SI
    @general     Enable DIM for SI
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_HYPO_SI                 DIM_CFG_OUTPUT_CUSTOM_FCT_SEN_INPUT

/*! @brief       DIM_CFG_HYPO_ALDW
    @general     Enable DIM for ALDW
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_HYPO_ALDW               MEDIC_OFF


/*
  Config: Select Hypothesis
**************************************************************************/

/* TODO: Switch does not work */
/*! @brief       DIM_CFG_HYPOTHESIS_SPORTSTYLE
    @general     FCT hypothesis driver SportStyle calculation
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_HYPOTHESIS_SPORTSTYLE             MEDIC_OFF

/*! @brief       DIM_CFG_HYPOTHESIS_LANECHANGE
    @general     FCT hypothesis driver LaneChange calculation
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_HYPOTHESIS_LANECHANGE             MEDIC_OFF


/* TODO: Switch does not work */
/*! @brief       DIM_CFG_HYPOTHESIS_DISTRACTION
    @general     FCT hypothesis driver distraction calculation
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_HYPOTHESIS_DISTRACTION            MEDIC_OFF

/*! @brief       DIM_CFG_OUT_CALIB
    @general     FCT driver hypothesis output calibration
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_OUT_CALIB                     MEDIC_ON

/*
  Config: Select Optional Functionalities
**************************************************************************/
/*! @brief       DIM_CFG_CALC_STEERING_ANGLE_GRADIENT
    @general     switch to enable swa gradient calculation,
                 use this switch in the OR condition in DIM_CFG_IN_PREPROC
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_CALC_STEERING_ANGLE_GRADIENT      MEDIC_ON

/*! @brief       DIM_CFG_CALC_GAS_PEDAL_GRADIENT
    @general     switch to enable gas pedal gradient calculation,
                 use this switch in the OR condition in DIM_CFG_IN_PREPROC
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_CALC_GAS_PEDAL_GRADIENT           MEDIC_ON

/*! @brief       DIM_CFG_IN_PREPROC
    @general     FCT DIM input preprocessing module
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_IN_PREPROC                    ((DIM_CFG_CALC_GAS_PEDAL_GRADIENT)||(DIM_CFG_CALC_STEERING_ANGLE_GRADIENT))

/*! @brief       DIM_CFG_USE_KICKDOWN_INPUT
    @general     Enable Usage of KickDown Boolean Information 
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_USE_KICKDOWN_INPUT            MEDIC_OFF

/*! @brief       DIM_CFG_USE_DRV_OVRRDE_INPUT
    @general     Allow external driver override signal
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_USE_DRV_OVRRDE_INPUT          MEDIC_OFF


/*! @brief       DIM_CFG_USE_GREATER_THN_EQUAL_DRV_VRYACTIVE
    @general     Greater than equal to (>=),Will be using while comparing steering wheel angle with thresould.
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_USE_GREATER_THN_EQUAL_DRV_VRYACTIVE     MEDIC_OFF

/*! @brief       DIM_CFG_USE_WEAKNEG_HIGHTHRES_CHECK
    @general     High Gas padel position is not using while checking for Feedback WeakNegative
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_USE_WEAKNEG_HIGHTHRES_CHECK         MEDIC_ON

/*! @brief       DIM_USE_SWA_OFFSET_CORRECTION
    @general     Enable to use offset corrected steering wheel angle
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_USE_SWA_OFFSET_CORRECTION     MEDIC_OFF

/*! @brief       DIM_CFG_ACTIVITY_USE_STEERWHLANGLE
    @general     Enable to use steering wheen angle for low activity check
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_OFF   @unit -     @min -   @max -   */
#define DIM_CFG_ACTIVITY_USE_STEERWHLANGLE     MEDIC_ON


/*! @brief       DIM_CFG_ATTENTION_USE_VELOCITY
    @general     Enable to use steering wheen angle for low activity check
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_ATTENTION_USE_VELOCITY     MEDIC_ON


/*! Use weak driver feedback instead of "fall into brake pedal recognition"  */
/*! @brief       DIM_CFG_NO_FALL_IN_BRAKE_DETECTION
    @general     Long and general description
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     MEDIC_ON   @unit -     @min -   @max -   */
#define DIM_CFG_NO_FALL_IN_BRAKE_DETECTION    MEDIC_ON

#endif
#endif
/**@}*/
