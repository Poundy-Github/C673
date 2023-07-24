/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc.h

DESCRIPTION:               Internal header file for TC in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

---*/ /*---
CHANGES:                    $Log: tc.h  $
CHANGES:                    Revision 1.4 2018/11/06 16:23:28CET uidj5069 
CHANGES:                    Implementation of "Target Follower System" for reference distance generation
CHANGES:                    Revision 1.3 2017/11/21 10:39:44CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Revision 1.2 2017/10/17 13:54:17CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    State Definitions added
CHANGES:                    Revision 1.1 2017/10/05 09:47:40CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/01_Source_Code/LOHP/lohp/tc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

#ifndef TC_H_INCLUDED
#define TC_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lohp.h"
#include "tc_cfg.h"
#include "tc_par.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (KOMPONENTENINTERN)
*****************************************************************************/

/*! @activation state of TC sub-component */
typedef enum
{
  TC_AS_PASSIVE,    /*!< function passive */
  TC_AS_ACTIVE      /*!< function active */
}
TC_ActiveState_t;

/*! @engagement state of TC sub-component */
typedef enum
{
  TC_ES_STANDARD,
  TC_ES_AFTER_ENGAGEMENT,
  TC_ES_DURING_OVERRIDE,
  TC_ES_AFTER_OVERRIDE
}
TC_EngageState_t;

/*! @reference target follower state */
typedef struct
{
  float32     f_Distance;       /*!< reference distance between follower and target vehicle */
  float32     f_Velocity;       /*!< reference velocity of follower */
  float32     f_Acceleration;   /*!< reference acceleration of follower */
 	ObjNumber_t s_ObjectID;       /*!< object ID of target vehicle */
}
TC_RefTargetFollower_t;

/*****************************************************************************
  KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENINTERN)
*****************************************************************************/

/*! Last TimeStamp of Runnable */
	extern AlgoDataTimeStamp_t u_TC_TimeStamp;
/*! Last Cycle Time of Runnable */
  extern float32 f_TC_CycleTime;
/*! Activation State */
  extern TC_ActiveState_t t_TC_Active_State;
/*! Engagement State */
  extern TC_EngageState_t t_TC_Engage_State;
/*! Reference Target Follower State */
  extern TC_RefTargetFollower_t at_TC_Target_Follower[];


/*! Input Ports required by TC component for processing */
  extern LOHP_TargetControlCommandPort_t t_TC_IN_TCCP;
  extern LOHP_EgoVehicleInfoPort_t t_TC_IN_EVIP;
  extern LOHP_TargetVehicleInfoPort_t t_TC_IN_TVIP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
  extern LOHP_TargetFollowStatePort_t at_TC_IN_TFSP[FCT_CFG_HP_TFC_PORT_CNT];
  extern LOHP_TargetFollowCommandPort_t at_TC_OUT_TFCP[FCT_CFG_HP_TFC_PORT_CNT];
#endif

/*! Output Ports provided by TC component after processing */
  extern LOHP_TargetControlStatePort_t t_TC_OUT_TCSP;


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/*--- tc_main.c ---*/

/*--- tc_generic.c ---*/
extern void TC_v_Generic_Process(void);

/*--- tc_customfunctions.c ---*/
extern void TC_v_Custom_Process(void);

#ifdef __cplusplus
};
#endif

#endif /* (FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC) */
#endif /* TC_H_INCLUDED */

