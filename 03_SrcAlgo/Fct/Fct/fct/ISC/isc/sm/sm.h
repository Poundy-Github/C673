/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/SM (Adaptive Cruise Control - Interface and State Coordinator - State Machine)

PACKAGENAME:               sm.h

DESCRIPTION:               Internal header file for SM in ISC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---
CHANGES:                    $Log: sm.h  $
CHANGES:                    Revision 1.6 2018/06/21 08:46:47CEST uidj5069 
CHANGES:                    Additional State Input Port from LOC
CHANGES:                    Revision 1.5 2018/04/16 16:35:55CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    External reference to <b_SM_LOC_SYS_Disable> removed
CHANGES:                    Revision 1.4 2017/10/23 16:32:09CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of State Machine Logic by checking new <b_Ready> state of CruiseControl and TargetControl for conditional activation
CHANGES:                    Revision 1.3 2017/10/12 16:46:39CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Ports for Target Control (ACC) added
CHANGES:                    Revision 1.2 2017/10/06 15:30:18CEST Mistry, Niraj (uidq5738) 
CHANGES:                    ACT Gen 4 Frame setup
CHANGES:                    Revision 1.1 2017/10/05 08:35:21CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/sm/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

#ifndef SM_H_INCLUDED
#define SM_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "isc.h"
#include "sm_cfg.h"
#include "sm_par.h"

#if (FCT_CFG_ISC_COMPONENT)
/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENINTERN)
*****************************************************************************/

/*! Input Ports required by SM component for processing */
extern ISC_SM_CommandPort_t t_SM_IN_SMCP;

#if (FCT_CFG_LOCC_COMPONENT)
  extern ISC_CC_StatePort_t t_SM_IN_CCSP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  extern ISC_TC_StatePort_t t_SM_IN_TCSP;
#endif

extern ISC_LOC_StatePort_t t_SM_IN_LOCSP;

/*! Output Ports provided by SM component after processing */
#if (FCT_CFG_LOCC_COMPONENT)
  extern ISC_CC_CommandPort_t t_SM_OUT_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  extern ISC_TC_CommandPort_t t_SM_OUT_TCCP;
#endif

extern ISC_SM_StatusPort_t t_SM_OUT_SMSP;


/*! Static Local System Command State Variables */
extern boolean b_SM_LOC_SYS_Enable;

/*! Static Local State Variable */
extern ISC_SM_STATE_t t_SM_LOC_STATE;

/*! Static Local CC Command State Variables */
#if (FCT_CFG_LOCC_COMPONENT)
  extern ACT_CC_OP_t t_SM_LOC_CC_OP_Gen;
  extern ACT_CC_OP_t t_SM_LOC_CC_OP_Out;
#endif

/*! Static Local TC Command State Variables */
#if (FCT_CFG_LOHP_COMPONENT)
#endif

/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/*--- sm_main.c ---*/

/*--- sm_generic.c ---*/
extern void SM_v_Generic_Process(void);

/*--- sm_customfunctions.c ---*/
extern void SM_v_Custom_Process(void);

#ifdef __cplusplus
};
#endif

#endif /* #if (FCT_CFG_ISC_COMPONENT) */
#endif

