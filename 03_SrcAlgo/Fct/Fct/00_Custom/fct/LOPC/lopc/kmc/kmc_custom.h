/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               kmc_custom.h

DESCRIPTION:               Custom header file for KMC in LOPC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             25.02.2018

VERSION:                   $Revision: 1.5.2.4 $

**************************************************************************** */

#ifndef _KMC_CUSTOM_H_INCLUDED
#define _KMC_CUSTOM_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         kmc_custom_h   Kmc_Custom_h
@ingroup          kmc_custom
@brief            Custom header file for KMC
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "kmc.h"

#ifdef __cplusplus
extern "C" {
#endif

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC))

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

#if (FCT_CFG_CC)

#ifndef FCT_MEAS_ID_LOPC_KMC_STATIC_MEM
#define FCT_MEAS_ID_LOPC_KMC_STATIC_MEM (0x20021000u)
#endif

#endif  /* FCT_CFG_CC */

  /* Definition of the required MTS alignment, added to unions to assure that
  the alignment requirements are met */
#define MTS_ALIGNMENT_DUMMY     uint32 MTS_DUMMY; // PRQA S 3412
  /* date: 2015-09-16, reviewer: Chirag Patel, reason: Not safety critical */

/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

#define ACC_f_PI 									3.14F
/* HMI Output */
typedef struct cc_driver_information_t {
  uint8               OBJECT_DISTANCE;              /*!< The relevant object distance @unit:m */
  uint8               REQUESTED_DISTANCE;           /*!< The requested distance setting */
  setspeed_t          SET_SPEED;                    /*!< The set speed @unit:km/h or mp/h */
  setspeed_t          OBJECT_SPEED;                 /*!< Speed of the relevant object @unit:km/h or mp/h */
  uint8               BIT_FCA_ALERT;
  uint8               BIT_ACC_ALERT;
  uint8               BIT_DM_ALERT;
  uint8               DM_STATE;
  setspeed_t          RECOMMENDED_SPEED;
  percentage_t        HEADWAY_SETTING;
  uint8               ACC_DRIVE_OFF_POSSIBLE;
  display_op_status_t OPERATIONAL_MODE;
  uint8               REPORTED_ERROR;
  uint8               OBJECT_DETECTED;
  uint8               DRIVER_CONFIRMATION_NEEDED;
  boolean             ACC_SLOPE_STATE;    
  uint8               COUNTER_SLOPE;  
  uint8               COUNTER_EXIT_SLOPE;
  uint16              CC_DRIVER_BELT_CNT;
  uint16              CC_DRIVER_DOOR_CNT;
} cc_driver_information_t;

#if (CFG_ACC_LEVER_INPUT)
/* HMI Input */
typedef struct cc_driver_inputs_t {

  switch_t CC_Main_SWITCH;  //zzz
  switch_t CC_Mode_SWITCH;  //zzz
  switch_t CC_TJA_SWITCH;       //zzz
  switch_t CC_AUTOFOLLOW_SWITCH;//zzz

  switch_t CC_SET_SWITCH;
  switch_t CC_RESUME_SWITCH;
  switch_t CC_CANCEL_SWITCH;
  switch_t CC_CANCEL_SWITCH_WITHOUT_BOM;
  switch_t CC_ACCEL_SWITCH_1;
  switch_t CC_ACCEL_SWITCH_2;
  switch_t CC_DECEL_SWITCH_1;
  switch_t CC_DECEL_SWITCH_2;
  switch_t CC_HEADWAY_INC_SWITCH;
  switch_t CC_HEADWAY_DEC_SWITCH;
  boolean  CC_ACCEL_PEDAL;
} cc_driver_inputs_t;
#endif

typedef enum
{
  eAutoGoMode_BASE     = 0,
  eAutoGoMode_ENABLED  = 1,
  eAutoGoMode_DISABLED = 2,
  eAutoGoMode_CREEP    = 3,
  eAutoGoMode_STOP     = 4
} cc_auto_go_mode_t;

#if (CFG_FCT_CC_PARAMS_DEBUG)
/*! @brief Collection of CC parameter values for debugging*/
typedef struct cc_params { 
  sint16 CC_ACCEL_CURVE[2*Cc_curve_points];
  sint16 CC_MAX_VEHICLE_ACCEL[2*Cc_max_vehicle_accel_points];
  sint16 CC_MAX_VEHICLE_DECEL[2*Cc_max_vehicle_decel_points];
  sint16 CC_MAX_ACCEL_CURVE_EU[2*Cc_max_accel_curve_points];
  sint16 CC_MAX_DECEL_DURING_OVERRIDE;
  sint16 CC_MAX_DECEL_AFTER_OVERRIDE;
  sint16 CC_MAX_DECEL_AFTER_ENGAGE;
  sint16 CC_MAX_POS_GRAD_DEFAULT_NEG_ACCEL[2*Cc_pos_grad_neg_accel_points];
  sint16 CC_MAX_POS_GRAD_DEFAULT_POS_ACCEL[2*Cc_pos_grad_pos_accel_points];
  sint16 CC_MAX_NEG_GRAD_DEFAULT[2*Cc_neg_grad_points];
  sint16 CC_ACC_TO_CC_TRANSITON_FACTOR_DEFAULT;
  sint16 CC_LONG_ACCEL_CURVE[2*Cc_long_accel_curve_points]; /*curves for lateral acceleration limiter*/
  sint16 CC_ALAT_SPEED_CURVE_DEFAULT[2*Cc_alat_speed_curve_points];
  sint16 CC_SLA_MANUAL_USAGE_TIME;
} cc_params_t;
#endif


/* Combined struct with debug signals for KMC custom */
typedef struct kmc_static_mem {

#if (FCT_CFG_CC)
#if (CFG_FCT_CC_PARAMS_DEBUG)
  cc_params_t                 CC_PARAMS;              /*!< CC Parameters */
#endif
  cc_status_t                 CC_STATUS;              /*!< The cruise control status information */
#if (CFG_ACC_LEVER_INPUT)
  cc_driver_inputs_t          CC_DRIVER_INPUTS;       /*!< The driver inputs to CC function */
#endif
  cc_input_data_t             CC_INPUT_DATA;          /*!< Cruise control input data */
  cc_driver_information_t     CC_DRIVER_INF;          /*!< The CC_DRIVER_INFORMATION */
  cart_das_input_data_t       DAS_INPUT_DATA;         /*!< The real data */
  cc_driver_controls_t        CC_DRIVER_CONTROLS;     /*!< The cruise control driver controls */
  cart_das_output_data_t      DAS_OUTPUT_DATA;        /*!< The real data */
  cc_auto_go_mode_t           KMC_Auto_Go_Mode;        /*!< KMC stop and go / autogo state */
  cc_error_data_t             CC_ERROR_DATA;          /*!< The cruise control error data */
  uint16                      Inhibit_nr;             /*!< The currently active inhibition number from INHIBIT_BUFFER.INHiBIT_NR */
  
#endif  /* FCT_CFG_CC */

} kmc_static_mem_t;

typedef union {
  kmc_static_mem_t KMC_STATIC_MEMORY;
  MTS_ALIGNMENT_DUMMY
} kmc_static_mem_u_t;


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

#endif  /* ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC)) */


#ifdef __cplusplus
};
#endif

/** @} end defgroup */

/* End of conditional inclusion */
#endif  /*!< _KMC_CUSTOM_H_INCLUDED */
