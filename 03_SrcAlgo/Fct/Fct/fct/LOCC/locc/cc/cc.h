/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/CC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               cc_int.h

DESCRIPTION:               Internal header file for CC in LOCC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.5 $

---*/ /*---
CHANGES:                    $Log: cc.h  $
CHANGES:                    Revision 1.5 2018/06/21 11:24:12CEST uidj5069 
CHANGES:                    Remove residuals of old "Start Coordination"
CHANGES:                    Revision 1.4 2018/06/11 14:12:16CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Remove old "Start Coordination"
CHANGES:                    Revision 1.3 2017/11/02 15:46:48CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Implementation of new StateMachine to improve Stop&Go Behaviour
CHANGES:                    Revision 1.2 2017/10/26 17:04:43CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Static Variable <t_CC_StandStillTime> added for Function <CC_v_UpdateStandStill()>
CHANGES:                    Revision 1.1 2017/10/05 08:22:02CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOCC_LongitudinalCruiseControl/04_Engineering/01_Source_Code/LOCC/locc/cc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

#ifndef CC_H_INCLUDED
#define CC_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_locc.h"
#include "cc_cfg.h"
#include "cc_par.h"

#if ((FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC))

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (KOMPONENTENINTERN)
*****************************************************************************/

/*! @activation state of CC sub-component */
typedef enum
{
  CC_AS_PASSIVE,    /*!< function passive */
  CC_AS_ACTIVE      /*!< function active */
}
CC_ActiveState_t;

/*! @engagement state of CC sub-component */
typedef enum
{
  CC_ES_STANDARD,
  CC_ES_AFTER_ENGAGEMENT,
  CC_ES_DURING_OVERRIDE,
  CC_ES_AFTER_OVERRIDE
}
CC_EngageState_t;

/*****************************************************************************
  KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENINTERN)
*****************************************************************************/

/*! Actual Operation */
  extern ACT_CC_OP_t t_CC_Operation_Act;

/*! Activation State */
  extern CC_ActiveState_t t_CC_Active_State;

/*! Engagement State */
  extern CC_EngageState_t t_CC_Engage_State;

/*! SetSpeed Stored */
  extern boolean b_CC_Speed_Stored;

/*! SetSpeed */
  extern setspeed_t u_CC_Set_Speed;

/*! Filtered Ego Speed */
  extern float f_CC_EgoVeloFilt;


/*! Input Ports required by CC component for processing */
  extern LOCC_CruiseControlCommandPort_t t_CC_IN_CCCP;
  extern LOCC_EgoVehicleInfoPort_t t_CC_IN_EVIP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  extern LOCC_VehicleSpeedStatePort_t at_CC_IN_VSSP[ACT_CFG_CC_VSC_PORT_CNT];
  extern LOCC_VehicleSpeedCommandPort_t at_CC_OUT_VSCP[ACT_CFG_CC_VSC_PORT_CNT];
#endif

/*! Output Ports provided by CC component after processing */
  extern LOCC_CruiseControlStatePort_t t_CC_OUT_CCSP;


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/*--- cc_main.c ---*/


/*--- cc_cruise.c ---*/
extern void CC_v_CruiseProcess(uint8 u_VSC_ID);

/*--- cc_curve.c ---*/
extern void CC_v_CurveProcess(uint8 u_VSC_ID);

/*--- cc_customfunctions.c ---*/
extern void CC_v_Dummy_CustomProcess(const CC_ProPortList_t *pProvidePorts);

#ifdef __cplusplus
};
#endif

#endif /* (FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC) */
#endif /* CC_H_INCLUDED */

