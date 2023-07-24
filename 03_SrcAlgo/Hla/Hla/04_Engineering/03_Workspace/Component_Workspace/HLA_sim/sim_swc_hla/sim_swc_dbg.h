/*! \file **********************************************************************

  COMPANY:                Continental AG, PL FAS, A.D.C. GmbH

  PROJECT:                ARS3xx

  CPU:                    Intel x86

  COMPONENT:              sim_swc_dbg

  MODULNAME:              sim_swc_dbg.h

  DESCRIPTION:            

  AUTHOR:                 Thomas Berndt

  CREATION DATE:          02.07.2007

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                 $Log: sim_swc_dbg.h  $
  CHANGES:                 Revision 1.1 2017/02/28 15:29:49CET Fischer, Stephan02 (uidg9447) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /ADAS/SW/Components/HLA_HeadLightAssist/04_Engineering/03_Workspace/Component_Workspace/HLA_sim/sim_swc_hla/project.pj
  CHANGES:                 Revision 1.1 2014/03/18 16:35:28CET Mutschler, Matthias (uidv7867) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/project.pj
  CHANGES:                 Revision 1.1 2012/12/06 14:24:56CET Zechner, Stefan (uidt9253) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/src/project.pj
  CHANGES:                 Revision 1.1 2012/10/17 15:35:41CEST Spruck, Jochen (spruckj) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/03_Workspace/algo/externals/sim_extensions/project.pj
  CHANGES:                 Revision 1.1 2012/10/17 15:22:49CEST Spruck, Jochen (spruckj) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/03_Workspace/algo/externals/sim_extensions/project.pj

**************************************************************************** */
#ifndef SIM_SWC_DBG_H_INCLUDED
#define SIM_SWC_DBG_H_INCLUDED

#include "fpieee.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

typedef enum 
{
  FPEErrors_Unknown = 0,
  FPEErrors_Inexact,
  FPEErrors_Underflow,
  FPEErrors_Overflow,
  FPEErrors_ZeroDivide,
  FPEErrors_InvalidOperation
}eFPEErrors_t;

/*****************************************************************************
  ENUMERATION
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

extern void SimDbgSetupFPU(unsigned int *cwOriginal);
extern void SimDbgRestoreFPU(unsigned int cwOriginal);
extern int SimDbgEvaluateException(int exceptionCode, LPEXCEPTION_POINTERS pExcp);

eFPEErrors_t SimGetFPUError(void);

#endif
