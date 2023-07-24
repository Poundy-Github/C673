/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrixgfa.h

  DESCRIPTION:            HLA matrix beam function.
                          Module clusters the vehicle lights to a desired number of glare free areas (1..5).


  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2013-03-07

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_matrixgfa.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:22CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:02CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:42CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.3 2014/03/25 18:38:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_matrixgfa.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_matrixgfa.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/matrix/project.pj.
  CHANGES:                Revision 1.2 2013/03/13 19:11:42CET Brunn, Marcus (brunnm) 
  CHANGES:                HLAF: used Matrix.MaxNumGlarefreeArea from HLAF Parameter input
  CHANGES:                --- Added comments ---  brunnm [Mar 13, 2013 7:11:43 PM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.1 2013/03/11 10:39:39CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_MATRIXGFA_INCLUDED
#define HLAF_MATRIXGFA_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"
#include "hlaf_type.h"
#include "hlaf_cfg.h"
#include "hlaf_ext.h"
#include "hlaf_matrixcfg.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/* init GFA List */
void HLAFMatrixGFAInit(HLAFMatrixGFA_t *pGFA);
/* cluster vehicle lights to desired number of glare free areas (GFA) */
void HLAFMatrixGFAMain( /* input */
                        const HLAF_t_RequiredInputs *ps_In,
                        const HLAFMatrixParameter_t *pPar,
                        const HLAFData_t *pFData,
                        /* output */  
                        HLAFMatrixData_t *pData
                      );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
