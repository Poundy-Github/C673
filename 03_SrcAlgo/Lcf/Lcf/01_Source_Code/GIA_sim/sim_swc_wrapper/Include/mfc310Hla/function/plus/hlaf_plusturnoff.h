/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_pluskeepoff.h

  DESCRIPTION:            HLA plus keep off functions.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_plusturnoff.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:29CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:12CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:50CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.5.1.1 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_plusturnoff.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusturnoff.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGES:                Revision 1.5 2013/04/15 15:38:18CEST Brunn, Marcus (brunnm) 
  CHANGES:                implemented TurnOffLeft_OncOnly and TurnOffLeft_LeftOnly (Daimler ÄJ topic)
  CHANGES:                --- Added comments ---  brunnm [Apr 15, 2013 3:38:19 PM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.4 2012/03/12 07:27:36CET Brunn, Marcus (brunnm) 
  CHANGES:                removed use of global variable (hlafPlusData)
  CHANGES:                --- Added comments ---  brunnm [Mar 12, 2012 7:27:36 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.3 2012/02/08 16:57:53CET Brunn, Marcus (brunnm) 
  CHANGES:                - fixed detection of relevant traffic
  CHANGES:                - hla plus: fast HB on when oncoming traffic passed
  CHANGES:                Revision 1.2 2012/02/06 15:27:46CET Brunn, Marcus (brunnm) 
  CHANGES:                turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGES:                Revision 1.1 2012/01/31 06:43:30CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_PLUS_TURNOFF_INCLUDED
#define HLAF_PLUS_TURNOFF_INCLUDED

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
void HLAPlusTurnOffPart( const HLAF_t_RequiredInputs  *ps_In,
                         const HLAFData_t             *pFData,
                         const HLA_t_CameraParameter  *pCamPar,
                         const HLAplusInputData_t     *pPlusIn,
                         const HLAFPlusOut_t          *pPlusOut,
                         HLAplusData_t                *pPlusData,
                         HLAplusTurnOffReason_t       *pTurnOffReason_left,
                         HLAplusTurnOffReason_t       *pTurnOffReason_right
                       );
void HLAPlusTurnOffFull( const HLAF_t_RequiredInputs  *ps_In,
                         const HLAplusData_t          *pPlusData,
                         const HLAFPlusOut_t          *pPlusOut,
                         const HLAFTrafficStyleOut_t  *pTrafficStyle,
                         HLAplusTurnOffReasonFullHB_t *pTurnOffReasom_FullHB
                       );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
