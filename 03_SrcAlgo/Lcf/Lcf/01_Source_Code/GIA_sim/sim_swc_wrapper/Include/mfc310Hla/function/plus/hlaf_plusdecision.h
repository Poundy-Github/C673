/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plusdecision.h

  DESCRIPTION:            HLA plus decision.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_plusdecision.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:28CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:09CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:48CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.6 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_plusdecision.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusdecision.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGES:                Revision 1.5 2013/05/03 07:55:57CEST Brunn, Marcus (brunnm) 
  CHANGES:                fixed LINT/MISRA Errors
  CHANGES:                --- Added comments ---  brunnm [May 3, 2013 7:55:57 AM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.4 2012/02/20 16:40:34CET Brunn, Marcus (brunnm) 
  CHANGES:                hlaf optimization in curvy roads
  CHANGES:                --- Added comments ---  brunnm [Feb 20, 2012 4:40:35 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.3 2012/02/13 06:22:54CET Brunn, Marcus (brunnm) 
  CHANGES:                used relevant traffic flag from extended object list
  CHANGES:                Revision 1.2 2012/02/06 15:27:44CET Brunn, Marcus (brunnm) 
  CHANGES:                turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGES:                Revision 1.1 2012/01/31 06:43:26CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_PLUS_DECISION_INCLUDED
#define HLAF_PLUS_DECISION_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_plus.h"

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
boolean HLAPlusDecision_HBOff2PartHBOn( eHLAplusHBState_t             eHBState,
                                        const HLAFTurnOffReasonGlob_t TurnOffReason_glob,
                                        HLAplusTurnOffReason_t        TurnOffReason,
                                        HLAplusKeepOffReasonPartHB_t  KeepOffReason_PartHB,
                                        HLAplusKeepOffReasonFullHB_t  KeepOffReason_FullHB
                                      );

void HLAPlusDecision_FindRelevantVehicles( const HLAF_t_RequiredInputs *ps_In,
                                           const HLAFData_t            *pFData,
                                           /* output */ 
                                           HLAplusObjectList_t         *pObjListExt
                                         );


/* avoid cyclic binding ---------------------------------------------------*/
#endif
