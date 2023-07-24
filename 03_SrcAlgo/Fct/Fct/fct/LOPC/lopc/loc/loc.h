/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/LOC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               loc_int.h

DESCRIPTION:               Internal header file for LOC in LOPC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

---*/ /*---
CHANGES:                    $Log: loc.h  $
CHANGES:                    Revision 1.3 2018/07/12 17:33:17CEST uidj5069 
CHANGES:                    Unused extern reference removed
CHANGES:                    Revision 1.2 2018/06/12 10:52:16CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    New Start Coordination Function added
CHANGES:                    Revision 1.1 2017/10/05 09:05:30CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC_LongitudinalPlannerAndController/04_Engineering/01_Source_Code/LOPC/lopc/loc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

#ifndef LOC_H_INCLUDED
#define LOC_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lopc.h"
#include "loc_cfg.h"
#include "loc_par.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOC))

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/
#define LOC_TIME_HOLD_DETECT_MAX  (3000u) /* Max Time for Detection of Hold State [ms] (3s) */

/*****************************************************************************
  TYPEDEFS (KOMPONENTENINTERN)
*****************************************************************************/

/*! @motion state of LOC sub-component */
typedef enum
{
  LOC_MS_MOVE,
  LOC_MS_STOP,
  LOC_MS_STAND,
  LOC_MS_HOLD,
  LOC_MS_START
}
LOC_MotionState_t;

/*****************************************************************************
  KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENINTERN)
*****************************************************************************/
extern times_t t_StandstillTime;
extern LOC_MotionState_t t_LOC_MotState;

/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/* loc_main.c */

/* loc_generic.c */
extern void LOC_v_IdealVehicleControl_Process (float32 f_CycleTime, LOC_MotionState_t *pt_LOC_MS,
                                               const LOPC_IdealVehicleCommandPort_t *pt_LOC_IN_IVCP,
                                               const LOPC_LogicVehicleCommandPort_t *pt_LOC_IN_LVCP,
                                               const LOPC_EgoVehicleStatePort_t *pt_LOC_IN_EVSP,
                                               LOPC_IdealVehicleStatePort_t *pt_LOC_OUT_IVSP,
                                               LOPC_LogicVehicleStatePort_t *pt_LOC_OUT_LVSP,
                                               LOPC_EgoVehicleCommandPort_t *pt_LOC_OUT_EVCP);

/* loc_customfunctions.c */
extern void LOC_v_Custom_Process(void);

#ifdef __cplusplus
};
#endif

#endif /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOC) */
#endif /* LOC_H_INCLUDED */

