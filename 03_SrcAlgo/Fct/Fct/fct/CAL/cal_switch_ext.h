/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_switch_ext.h

DESCRIPTION:               This file contains all types, definitions and prototypes
                           concerning switches 

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.9.1.2


**************************************************************************** */

#ifndef CAL_SWITCH_EXT_H_INCLUDED
#define CAL_SWITCH_EXT_H_INCLUDED

/** @defgroup switch CAL_SWITCH
@brief  Function used to handle the ACC input switches            
   @ingroup fct_veh

@{ */
#include "fct_glob_ext.h"
#include "fct_types.h"

 
#if ((FCT_CFG_ACC_CAL) && (FCT_CFG_BUTTON_SWITCH_EVALUATION))

/* DEFINITIONS */

/*! @brief defines a value for CYCLE_TIMER where it is not initialized*/
#define switch_cycletimer_init 511
/*! @brief the highest value, for DURATION_TIME_INACTIVE*/
#define switch_dtia_max_val 1023
/*! @brief the highest value, for DURATION_TIME_ACTIVE*/
#define switch_dta_max_val 1023

/* ****************************************************************
    TYPEDEF switch_t
    **************************************************************** */
/*! @brief type definition for a SWITCH

    @general type definition for a SWITCH

    */
typedef struct switch_t { 
  ubit32           AKT_STATUS             :1;/*!<AKT_STATUS*/
  ubit32           LAST_STATUS            :1;/*!<LAST_STATUS*/
  ubit32           OK_WHILE_SWITCHED_ON   :1;/*!<OK_WHILE_SWITCHED_ON*/
  ubit32           CYCLE_TIMER            :9;  /*!< max cycle timer 510 cycles (=10s at 20ms cycles)*//*%unit:cycles*/ 
  ubit32           DURATION_TIME_INACTIVE :10; /*!< max duration measurement 1022 cycles (=20s at 20ms cycles)*/ /*%unit:cycles*/ 
  ubit32           DURATION_TIME_ACTIVE   :10; /*!< max duration measurement 1022 cycles (=20s at 20ms cycles)*/ /*%unit:cycles*/ 
} switch_t;

/*! @brief switch state enumeration */
typedef enum switch_state {
  SWITCH_STATE_OFF,/*!<SWITCH_STATE_OFF*/
  SWITCH_STATE_ON,/*!<SWITCH_STATE_ON*/
  SWITCH_STATE_ACTION_OFF  /*!< Special return value (3state): switch action but false condition */
} switch_state_t;

/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */

extern void SWITCH_INIT_SWITCH(switch_t * const pSwitch);
extern void SWITCH_SET_STATE(switch_t * const pSwitch, const boolean State);
extern switch_state_t SWITCH_RISING_EDGE(const switch_t * const pSwitch, const boolean Condition);
extern switch_state_t SWITCH_FALLING_EDGE(switch_t * const pSwitch, const boolean Condition);
extern switch_state_t SWITCH_HOLD_REPEAT(switch_t * const pSwitch, const boolean StartCondition, const boolean HoldCondition, uint16 StartTime, uint16 RepeatTime);
extern void SWITCH_SET_COND_COUNTER(const boolean Condition, const uint16 InitValue, const uint16 DecValue, uint16 * const pCounter, const boolean SelectedFunctionActive);
extern void SWITCH_SET_COUNTER(const uint16 DecValue, uint16 * const pCounter);

#endif /*((FCT_CFG_ACC_CAL) && (FCT_CFG_BUTTON_SWITCH_EVALUATION))*/

#endif /* #ifndef CAL_SWITCH_EXT_H_INCLUDED */
/** @} end defgroup */

