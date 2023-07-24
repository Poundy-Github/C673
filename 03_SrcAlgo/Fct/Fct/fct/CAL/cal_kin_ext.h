/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_kin_ext.h

DESCRIPTION:               Physical Funktion of all kinematical functions

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.3.1.1

**************************************************************************** */
#ifndef CAL_KIN_EXT_INCLUDED
#define CAL_KIN_EXT_INCLUDED

/** @defgroup fct_phys_kyn CAL_KIN
@brief     Function which converts acceleration to torque and vise versa
   @ingroup fct_veh

@{ */
#include "fct_glob_ext.h"
#include "fct_types.h"


#if (FCT_CFG_LOHP_COMPONENT)


/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */
extern acceleration_t PHYS_CALC_NEEDED_DECEL(const acceleration_t long_accel, const velocity_t long_velocity, times_t reaction_time, const velocity_t obj_rel_long_velocity, const acceleration_t obj_rel_long_accel, const velocity_t obj_long_velocity, const acceleration_t obj_long_accel, const distance_t obj_long_diplacement);
extern times_t PHYS_CALCULATE_TTC(const velocity_t ObjectVelocity, const acceleration_t ObjectAccel, const velocity_t HostVelocity, const acceleration_t HostAccel, const distance_t ObjectDistance, velocity_t *ImpactVelocity);

#endif  /* (FCT_CFG_LOHP_COMPONENT) */
#endif  /* (CAL_KIN_EXT_INCLUDED) */
/** @} end defgroup */
