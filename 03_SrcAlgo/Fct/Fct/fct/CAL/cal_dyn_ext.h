/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_dyn_ext.h

DESCRIPTION:               External Header file of Physical Funktions of
                           all kinematical functions

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.4.1.1

**************************************************************************** */
#ifndef CAL_DYN_EXT_INCLUDED
#define CAL_DYN_EXT_INCLUDED

/** @defgroup fct_phys_dyn CAL_DYN 
@brief              Function which converts acceleration to torque and vise-versa.
   @ingroup fct_veh

@{ */
#include "fct_glob_ext.h"
#include "fct_types.h"

#if ((FCT_CFG_ACC_CAL) && (FCT_CFG_LODMC_COMPONENT))

typedef struct CALVehOperationalParams{
  uint16                  VEHICLE_WEIGHT;   /*%scale:0.1 unit:kg*/
  uint16                  STAT_WHEEL_CIRCUMFERENCE;      /*%scale:0.001 unit:m*/   /*!< @todo: Currently used, but newer versions have VehPar for this! */
  sint16                  AIR_RESISTANCE;     /*%scale:0.001*/
  sint16                  ROLL_RESISTANCE;    /*% @resolution 0.001 @unit [m/(s*s)] */
  sint16                  ACCEL_RESISTANCE;   /*%scale:0.001*/
} CALVehOperationalParams_t;

#if (0) /* Disabling unused functions */
/* FUNCTION PROTOTYPES (COMPONENT EXTERNAL) */
extern acceleration_t PHYS_CONVERT_T2A(const torque_t T, const CALVehOperationalParams_t* op_params, const velocity_t vehicle_speed);
extern torque_t PHYS_CONVERT_A2T(const acceleration_t a, const CALVehOperationalParams_t* op_params, const velocity_t vehicle_speed);
#endif /* (0) Unused functions */

#endif  /* END IF ((FCT_CFG_ACC_CAL) && (FCT_CFG_LODMC_COMPONENT)) */

#endif /* CAL_DYN_EXT_INCLUDED */
/** @} end defgroup */