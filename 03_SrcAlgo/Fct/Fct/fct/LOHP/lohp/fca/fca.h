/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca.h

DESCRIPTION:               Internal header file for FCA functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.5.1.2

**************************************************************************** */

#ifndef FCA_H
#define FCA_H

/* includes            */
#include "lohp.h"
#include "fca_cfg.h"
#include "fca_par.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))

/* GLOBAL VARIABLES (KOMPONENT EXTERNAL) */


/* FUNKTION PROTOTYPES (KOMPONENT EXTERNAL) */
extern void FCA_v_DetermineAlertState(const fca_input_data_t* input, fca_output_data_t* output);
extern void FCA_v_DetermineAlert(fca_output_data_t* AlertData, const object_t *Object);

#endif  /* FCT_CFG_FCA */

#endif

