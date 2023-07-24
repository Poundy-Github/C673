/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/HMI (Adaptive Cruise Control - Interface and State Coordinator - Human Machine Interface)

PACKAGENAME:               hmi_par.h

DESCRIPTION:               Internal header file for function HMI in ISC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.2 $

---*/ /*---
CHANGES:                    $Log: hmi_par.h  $
CHANGES:                    Revision 1.2 2017/10/12 16:34:58CEST uidj5069 
CHANGES:                    Added Parameters for Target Control (ACC)
CHANGES:                    Revision 1.1 2017/10/05 08:42:30CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/00_Projects/ARS510/ISC/isc/hmi/project.pj
CHANGES:                    Derived from Version 1.24.1.2 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/acc/project.pj

**************************************************************************** */

/* conditional include */
#ifndef HMI_PAR_INCLUDED
#define HMI_PAR_INCLUDED


#if (FCT_CFG_ISC_COMPONENT)

#define HMI_ACC_HEADWAY_STAGE_MAX           (4u)
#define HMI_ACC_HEADWAY_STAGE_INIT          (0u)

#endif  /* (FCT_CFG_ISC_COMPONENT) */

#endif
