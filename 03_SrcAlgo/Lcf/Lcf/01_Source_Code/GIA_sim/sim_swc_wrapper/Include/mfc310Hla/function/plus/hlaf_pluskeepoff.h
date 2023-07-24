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
  CHANGES:                $Log: hlaf_pluskeepoff.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:28CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:10CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:48CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.7 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_pluskeepoff.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_pluskeepoff.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGES:                Revision 1.6 2013/05/23 10:31:04CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed PC-LINT errors
  CHANGES:                --- Added comments ---  uidv7867 [May 23, 2013 10:31:04 AM CEST]
  CHANGES:                Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.5 2013/04/25 11:03:03CEST Brunn, Marcus (brunnm) 
  CHANGES:                implemented hla plus configuration switch 
  CHANGES:                implemented TurnOffLeft_OncOnly, TurnOffLeft_LeftOnly, KeepOffLeft_LeftOnly and AsymmetricMode
  CHANGES:                --- Added comments ---  brunnm [Apr 25, 2013 11:03:04 AM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.4 2012/09/24 11:28:49CEST Brunn, Marcus (brunnm) 
  CHANGES:                hlaf plus: introduced road type depending turn on delay (partial HB -> full HB: highway = 5sec, country road = 1sec)
  CHANGES:                --- Added comments ---  brunnm [Sep 24, 2012 11:28:49 AM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.3 2012/03/12 07:27:35CET Brunn, Marcus (brunnm) 
  CHANGES:                removed use of global variable (hlafPlusData)
  CHANGES:                --- Added comments ---  brunnm [Mar 12, 2012 7:27:35 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.2 2012/02/20 16:40:35CET Brunn, Marcus (brunnm) 
  CHANGES:                hlaf optimization in curvy roads
  CHANGES:                Revision 1.1 2012/01/31 06:43:27CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_PLUS_KEEEPOFF_INCLUDED
#define HLAF_PLUS_KEEEPOFF_INCLUDED

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
void HLAPlusKeepOffPart_Stage1(  const HLAF_t_RequiredInputs  *ps_In,
                                 const HLAFData_t             *pFData,
                                 const HLAFPlusOut_t          *pPlusOut,
                                 const float32                dTime_s,
                                 HLAplusData_t                *pPlusData,
                                 HLAplusKeepOffReasonPartHB_t *pKeepOffReasom_left,
                                 HLAplusKeepOffReasonPartHB_t *pKeepOffReasom_right
                              );
void HLAPlusKeepOffFull( const HLAFData_t             *pFData,
                         const float32                dTime_s,
                         const HLAplusParameterTurnOnDelay_t *pTurnOnDelay,
                         HLAplusData_t                *pPlusData,
                         HLAplusKeepOffReasonFullHB_t *pKeepOffReason
                       );

void HLAPlusKeepOffPart_Stage2( const HLAF_t_RequiredInputs  *ps_In,
                                const HLAplusInputData_t     *pPlusIn,
                                const HLAFData_t             *pFData,
                                HLAplusData_t                *pPlusData
                              );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
