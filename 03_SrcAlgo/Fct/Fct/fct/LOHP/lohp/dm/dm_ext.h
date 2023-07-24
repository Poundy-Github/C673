/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm_ext.h

DESCRIPTION:               External header file for distance monitoring function

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.7.1.2

**************************************************************************** */

#ifndef DM_EXT_H
#define DM_EXT_H

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

/*! @brief DM input status*/
typedef struct dm_input_status_t {
  ubit8_t DM_ON    :1;
  ubit8_t INHIBIT  :1;
  ubit8_t          :6;
} dm_input_status_t;

/*! @brief DM input interface: input data*/
typedef struct dm_input_data_t {
  speedometer_speed_t SPEEDO_SPEED;
  velocity_t          LONG_VELOCITY;
  acceleration_t      LONG_ACCELERATION;
  dm_input_status_t   CONTROL;
} dm_input_data_t;

/*! @brief DM status data*/
typedef struct dm_status_t {
  uint16  StaticAlertCounter;
  times_t DM_ESTIMATED_TIMEGAP;
} dm_status_t;

/* Alert level, moved from display_Ext.h */
#define Display_alert_level0 (display_alert_level_t)0
#define Display_alert_level1 (display_alert_level_t)1
#define Display_alert_level2 (display_alert_level_t)2
#define Display_alert_level3 (display_alert_level_t)3
#define Display_alert_level4 (display_alert_level_t)4
typedef enum_t display_alert_level_t;

/*! Distance Monitor Status */
#define Dm_off          ((dm_state_t)0)
#define Dm_on_inactive  ((dm_state_t)1)
#define Dm_on_active    ((dm_state_t)2)
typedef enum_t dm_state_t;  /*!< @values: Dm_off,Dm_on_inactive,Dm_on_active */

/*! @brief Data needed to perform the Distance Monitoring task */
typedef struct {
  dm_state_t            DM_STATE;
  display_alert_level_t DM_ALERT_LEVEL;
} dm_output_data_t;

/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */
extern void DM_v_Process(const times_t cycle_time, const dm_input_data_t* input, dm_output_data_t* output, const acc_object_t* object, dm_status_t *dm_status);
extern void DM_v_Init(dm_status_t *dm_status);
extern void DM_v_OutInit(dm_output_data_t *dm_output_data);
#endif  /* FCT_CFG_DM */

#endif
