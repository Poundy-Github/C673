/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/HMI (Adaptive Cruise Control - Interface and State Coordinator - Human Machine Interface)

PACKAGENAME:               hmi.h

DESCRIPTION:               Internal header file for HMI in ISC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

---*/ /*---
CHANGES:                    $Log: hmi.h  $
CHANGES:                    Revision 1.4 2018/06/11 14:56:17CEST uidj5069 
CHANGES:                    New Ports added for LOPC based Start Coordination
CHANGES:                    Revision 1.3 2017/10/12 16:28:51CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port for Target Control (ACC) added
CHANGES:                    Revision 1.2 2017/10/06 15:30:27CEST Mistry, Niraj (uidq5738) 
CHANGES:                    ACT Gen 4 Frame setup
CHANGES:                    Revision 1.1 2017/10/05 08:35:01CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/hmi/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

#ifndef HMI_H_INCLUDED
#define HMI_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "isc.h"
#include "hmi_cfg.h"
#include "hmi_par.h"

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

/*! Input Ports required by HMI component for processing */
extern ISC_HMI_InformationPort_t t_HMI_IN_HMIP;
extern ISC_HMI_CommandPort_t t_HMI_IN_HMCP;
extern ISC_SM_StatusPort_t t_HMI_IN_SMSP;
extern ISC_LOC_StatePort_t t_HMI_IN_LVSP;

/*! Output Ports provided by HMI component after processing */
extern ISC_SM_CommandPort_t t_HMI_OUT_SMCP;
extern ISC_HMI_StatusPort_t t_HMI_OUT_HMSP;

#if (FCT_CFG_LOCC_COMPONENT)
  extern ISC_CC_DegradationPort_t t_HMI_OUT_CCDP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  extern ISC_TC_DegradationPort_t t_HMI_OUT_TCDP;
#endif

extern ISC_LOC_CommandPort_t t_HMI_OUT_LVCP;

/*! Local Buffered Input Command State */
extern ACT_ISC_Command_t t_HMI_LOC_ISCC;

/* Local Headway Setting Stage */
extern uint8 u_HMI_LOC_Headway_Stage;

/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/*--- hmi_main.c ---*/

/*--- hmi_generic.c ---*/
void HMI_v_Generic_Process(void);

/*--- hmi_customfunctions.c ---*/
void HMI_v_Custom_Process(void);

#ifdef __cplusplus
};
#endif


#endif /* (FCT_CFG_ISC_COMPONENT) */
#endif

