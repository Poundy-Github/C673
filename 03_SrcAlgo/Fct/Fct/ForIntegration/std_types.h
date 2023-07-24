/*! \file **********************************************************************

  COMPONENT:              RTE_SIM

  MODULENAME:             std_types.h

  @brief                  This file contains the standard RTE types for simulation

  ---*/ /*---

  CHANGES
  ---------------

  VERSIONNUMBER:          $Revision: 1.1 $

  EDITOR NAME:            $Author: uidm9800 $
  
  CHANGES:                $Log: std_types.h  $
  CHANGES:                Revision 1.1 2020/02/23 14:47:17CET uidm9800 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/externals/sim/include/sim_rte/project.pj
  CHANGES:                Revision 1.1 2019/12/12 04:08:14CET Xu, Yuanzhi (uidm9800) (uidm9800) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/externals/sim/include/sim_rte/project.pj
  CHANGES:                Revision 1.1 2010/02/15 11:15:51CET gungvary 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/01_Source_Code/rte_sim/project.pj

*****************************************************************************/
#ifndef STD_TYPES_H       /* Requirement STD_014 */
#define STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

/* [STD002] */
#define STD_AR_MAJOR_VERSION 2
#define STD_AR_MINOR_VERSION 1
#define STD_AR_PATCH_VERSION 0

/* [STD005] */
/* [STD011]: E_OK, E_NOT_OK, 0x02-0x3F */
typedef uint8 Std_ReturnType;

/* [STD015] */
typedef struct
{
    uint16 vendorID;
    uint8  moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;


/* [STD006] */
#ifndef STATUSTYPEDEFINED 
  #define STATUSTYPEDEFINED 
  #define E_OK      ((uint8)0x00U)

  typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK    ((uint8)0x01U)

/* [STD007] */
#define STD_HIGH    0x01   /* Physical state 5V or 3.3V */
#define STD_LOW     0x00   /* Physical state 0V         */


/* [STD013] */
#define STD_ACTIVE  0x01   /* Logical state active */
#define STD_IDLE    0x00   /* Logical state idle   */

/* [STD010] */
#define STD_ON      0x01
#define STD_OFF     0x00

#endif
