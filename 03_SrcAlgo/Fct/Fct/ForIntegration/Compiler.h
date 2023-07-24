/*! \file **********************************************************************

  COMPANY:              Continental

  COMPONENT:            RTE_SIM

  MODULNAME:            Compiler.h

  DESCRIPTION:          RTE Simulation compiler settings for MS-VC

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        15.02.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: Compiler.h  $
  CHANGES:              Revision 1.1 2020/02/23 14:47:16CET uidm9800 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/externals/sim/include/sim_rte/project.pj
  CHANGES:              Revision 1.1 2019/12/12 04:08:13CET Xu, Yuanzhi (uidm9800) (uidm9800) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/externals/sim/include/sim_rte/project.pj
  CHANGES:              Revision 1.3 2018/09/11 11:30:51CEST HossuC 
  CHANGES:              Update - support for GNUC.
  CHANGES:              Revision 1.2 2018/04/25 13:53:28CEST Hossu, Cristian (HossuC) 
  CHANGES:              update from Alin Danciu.
  CHANGES:              Revision 1.1 2010/02/15 11:15:12CET gungvary 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/01_Source_Code/rte_sim/project.pj

**************************************************************************** */
/* REF 1 - MISRA-C:2004 19.10 VIOLATION: Macro parameter not in brackets
This violation is due to parameters in the macro body not enclosed in brackets
This cannot be fixed since these macros are used for compiler wrapping and
use of brackets around parameters results in compilation errors.
******************************************************************************/

/* [COMPILER047] */
#ifndef COMPILER_H
#define COMPILER_H

/*#include "Compiler_Cfg.h"*/

/* [COMPILER043] */
#define COMPILER_VENDOR_ID		?? /* Have not found the vendor ID table */
#define COMPILER_AR_MAJOR_VERSION	2
#define COMPILER_AR_MINOR_VERSION	1
#define COMPILER_AR_PATCH_VERSION	0
#define COMPILER_SW_MAJOR_VERSION	0
#define COMPILER_SW_MINOR_VERSION	0
#define COMPILER_SW_PATCH_VERSION	1

#define AUTOMATIC
#define _STATIC_ static
#define NULL_PTR ((void *)0)

/* MISRA-C:2004 19.10 VIOLATION: Refer to REF 1 above */
/* This is applicable for the following lines of code */

/* COMPILER001 */
#define FUNC(rettype, memclass) rettype

/* COMPILER006 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/* COMPILER013 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

/* COMPILER031 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/* COMPILER032 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/* COMPILER039 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/* COMPILER023 */
/* Do not define CONST as it clashes with the object-like macro in the
MS-VC standard includes. This function like macro seems to be used in
the adapter headers only, thus it should not be needed for simulation */
/*#define CONST(consttype, memclass) const consttype*/

/* COMPILER026 */
#define VAR(vartype, memclass) vartype
/* MISRA-C:2004 19.10 VIOLATION: End of code block */

/***************************MS-VC***********************/
#if defined(_MSC_VER) || defined(FCT_SIMU)
  /* Prototypes for intrinsic functions */
  #define _INLINE_ __inline
  #define INTERRUPT_FUNC __interrupt
#elif __GNUC__
#else
//# error This file shall be only used for compilation with the Microsoft C-compiler or GNUC!
#endif /* #ifdef _MSC_VER */


#endif /* #ifndef COMPILER_H */
