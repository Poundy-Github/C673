/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_ext.h

DESCRIPTION:               External header file for FCA functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.6.1.3

**************************************************************************** */

#ifndef FCA_EXT_H
#define FCA_EXT_H


#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))

/* Moved from brake_ext.h */
/*! @brief Brake status bits */
typedef struct brake_status_t {
  ubit8_t BRAKE_FAILED       :1;
  ubit8_t OVER_HEATED        :1;
  ubit8_t PEDAL_INIT_TRAVEL  :1;
ubit8_t                    :5;
} brake_status_t;

/*! @brief FCA Status bits*/
typedef struct fca_input_status_t {
  ubit8_t FCA_ON   :1;
  ubit8_t INHIBIT  :1;
  ubit8_t          :6;
} fca_input_status_t;

/*! @brief FCA input interface: input data*/
typedef struct fca_input_data_t {
  speedometer_speed_t SPEEDO_SPEED;
  velocity_t          LONG_VELOCITY;
  acceleration_t      LONG_ACCELERATION;
  fca_input_status_t  CONTROL;
  brake_status_t      BRAKE_STATUS;
} fca_input_data_t;

#define Fca_status_off          ((fca_state_t)0)
#define Fca_status_on_inactive  ((fca_state_t)1)
#define Fca_status_on_active    ((fca_state_t)2)
typedef enum_t fca_state_t; /*!< @values: Fca_status_off, Fca_status_on_inactive, Fca_status_on_active */

/*! @brief Status bits for the Forward Collision Alert algorithm */
typedef struct fca_status_t {
  ubit8_t FCA_ALERT    :1;
ubit8_t              :7;
} fca_status_t;

/*! @brief Data needed to perform the Forward Collision Alert task */
typedef struct fca_output_data_t {
  acceleration_t  NEEDED_ACCEL;
  fca_state_t     FCA_STATE;
  fca_status_t    FCA_STATUS;
} fca_output_data_t;

/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */
extern void FCA_v_Process(const times_t cycle_time, const fca_input_data_t* input_data, fca_output_data_t* output_data, const acc_object_t* Object);
extern void FCA_v_OutInit(fca_output_data_t *fca_output_data);
#endif  /* FCT_CFG_FCA */

#endif

