/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm.h

DESCRIPTION:               Internal header file for distance monitoring function

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.6

**************************************************************************** */
#ifndef DM_H
#define DM_H

/* includes */
#include "lohp.h"
#include "dm_cfg.h"
#include "dm_par.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

/* GLOBAL VARIABLES (KOMPONENT EXTERNAL) */


/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */
extern void DM_v_DetermineAlertState(const dm_input_data_t* input, dm_output_data_t* output);
extern void DM_v_DetermineAlert(const times_t cycle_time, const dm_input_data_t* input, dm_output_data_t* output, const acc_object_t* object, dm_status_t *dm_status);

#endif  /* FCT_CFG_DM */

#endif

