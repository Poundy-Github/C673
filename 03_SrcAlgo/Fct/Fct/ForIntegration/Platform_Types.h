/*! \file **********************************************************************

  COMPONENT:              RTE_SIM

  MODULENAME:             platform_types.h

  @brief                  This file contains all RTE simulation platform types

  ---*/ /*---

  CHANGES
  ---------------

  VERSIONNUMBER:          $Revision: 1.1 $

  EDITOR NAME:            $Author: uidm9800 $
  
  CHANGES:                $Log: Platform_Types.h  $
  CHANGES:                Revision 1.1 2020/02/23 14:47:17CET uidm9800 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/externals/sim/include/sim_rte/project.pj
  CHANGES:                Revision 1.1 2019/12/12 04:08:13CET Xu, Yuanzhi (uidm9800) (uidm9800) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/externals/sim/include/sim_rte/project.pj
  CHANGES:                Revision 1.10 2018/09/07 14:04:52CEST HossuC 
  CHANGES:                Update with b_TRUE and b_FALSE(MFC510\520 - Patrick Zaech)
  CHANGES:                Revision 1.9 2018/08/22 11:19:51CEST Hossu, Cristian (HossuC) 
  CHANGES:                Enable uint32_t and uint64_t type definition only for the projects that require it.
  CHANGES:                Revision 1.8 2018/04/17 15:02:14CEST Hossu, Cristian (HossuC) 
  CHANGES:                Disabled uint32_t and uint64_t definition.
  CHANGES:                Revision 1.7 2018/03/21 15:35:26CET Hossu, Cristian (HossuC) 
  CHANGES:                Update Platform_Types.h to cotain latest changes in Swap.h
  CHANGES:                Revision 1.6 2018/03/14 16:00:30CET Hossu, Cristian (HossuC) 
  CHANGES:                Updated with types: sint64 and uint64.
  CHANGES:                Revision 1.5 2017/08/07 08:31:05CEST Dinu, Marius (DinuM) 
  CHANGES:                defined DISABLE_LEAST_TYPE_GENERATION for solving conflict of type redefinition when projects typedef themselves
  CHANGES:                Revision 1.4 2013/06/06 06:51:34CEST Dinu, Marius (DinuM) 
  CHANGES:                updated faulty MKS change log
  CHANGES:                - Added comments -  DinuM [Jun 6, 2013 6:51:34 AM CEST]
  CHANGES:                Change Package : 182011:1 http://mks-psad:7002/im/viewissue?selection=182011
  CHANGES:                Revision 1.3 2013/06/05 06:50:19CEST Dinu, Marius (DinuM) 
  CHANGES:                Updated the definition from
  CHANGES:                typedef unsigned int uint32;           to              typedef unsigned long uint32;           
  CHANGES:                --- Added comments ---  DinuM [Jun 5, 2013 6:50:20 AM CEST]
  CHANGES:                Change Package : 182011:1 http://mks-psad:7002/im/viewissue?selection=182011
  CHANGES:                Revision 1.2 2011/08/02 13:19:35CEST Spruck, Jochen (spruckj) 
  CHANGES:                Add int64 type to the platform types file
  CHANGES:                --- Added comments ---  spruckj [Aug 2, 2011 1:19:35 PM CEST]
  CHANGES:                Change Package : 74444:1 http://mks-psad:7002/im/viewissue?selection=74444
  CHANGES:                Revision 1.1 2010/02/15 11:15:25CET gungvary 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/01_Source_Code/rte_sim/project.pj

*****************************************************************************/

/* REF 1 - MISRA-C:2004 19.4 VIOLATION: Macro contains unacceptable items
This violation is due to the C type keyword 'boolean' used
inside the macro. This cannot be fixed since AUTOSAR requires
TRUE and FALSE to be defined like this.
******************************************************************************/
/* [PLATFORM002]: It is not allowed to add any extension to this file. */
/* Any extension invalidates the AUTOSAR conformity */

/* PROG044 */
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/* [PLATFORM012] */
#define PLATFORM_VENDOR_ID			43
#define PLATFORM_AR_MAJOR_VERSION	2
#define PLATFORM_AR_MINOR_VERSION	1
#define PLATFORM_AR_PATCH_VERSION	0
#define PLATFORM_SW_MAJOR_VERSION	0
#define PLATFORM_SW_MINOR_VERSION	9
#define PLATFORM_SW_PATCH_VERSION	1

/* [PLATFORM057] */
#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define MSB_FIRST 0
#define LSB_FIRST 1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1
/* [PLATFORM010],[PLATFORM031] */
#define CPU_TYPE (CPU_TYPE_32)            /* [PLATFORM004],[PLATFORM044],[PLATFORM045] - CPU_TYPE_32, CPU_TYPE_16, CPU_TYPE_8 */
#define CPU_BIT_ORDER (LSB_FIRST)         /* [PLATFORM043],[PLATFORM038],[PLATFORM048] - MSB_FIRST (bit), LSB_FIRST (little) */
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)  /* [PLATFORM046],[PLATFORM050],[PLATFORM039],[PLATFORM050] - HIGH_BYTE_FIRST, LOW_BYTE_FIRST */
#define DISABLE_LEAST_TYPE_GENERATION    /* solving conflict for redefinition of different types when the projects typedef themselves */ 

typedef unsigned char boolean;          /* [PLATFORM026],[PLATFORM027] */
typedef signed char sint8;              /* [PLATFORM016] */
typedef unsigned char uint8;            /* [PLATFORM013] */
typedef signed short sint16;            /* [PLATFORM017] */
typedef unsigned short uint16;          /* [PLATFORM014] */
typedef signed long sint32;             /* [PLATFORM018] */
typedef unsigned long uint32;           /* [PLATFORM015] */
typedef unsigned int uint8_least;       /* [PLATFORM020],[PLATFORM005] */
typedef unsigned int uint16_least;      /* [PLATFORM021],[PLATFORM005] */

//typedef unsigned int uint32_least;      /* [PLATFORM022],[PLATFORM005] */

typedef signed int sint8_least;         /* [PLATFORM023],[PLATFORM005] */
typedef signed int sint16_least;       	/* [PLATFORM024],[PLATFORM005] */

//typedef signed int sint32_least;        /* [PLATFORM025],[PLATFORM005] */

typedef unsigned long long    uint64;   /* 0 .. 18446744073709551615   */
typedef float float32;                  /* [PLATFORM041] */
typedef double float64;                 /* [PLATFORM042] */
/* Description: signed long long
   Range: (-2^63...2^63-1)*/
typedef signed long long sint64;
#ifdef DEFINE_UINT32_T
typedef unsigned long uint32_t;
#endif
#ifdef DEFINE_UINT64_T
typedef unsigned long long uint64_t;
#endif

/* [PLATFORM54], [PLATFORM55], [PLATFORM56] */
/* MISRA-C:2004 19.4 VIOLATION: Refer to REF 1 above */
#ifndef TRUE
    #define TRUE ((boolean) 1)
#endif
#ifndef b_TRUE
    #define b_TRUE TRUE
#endif
#ifndef FALSE
    #define FALSE ((boolean) 0)
#endif
#ifndef b_FALSE
    #define b_FALSE FALSE
#endif

#endif /* #ifndef PLATFORM_TYPES_H */
