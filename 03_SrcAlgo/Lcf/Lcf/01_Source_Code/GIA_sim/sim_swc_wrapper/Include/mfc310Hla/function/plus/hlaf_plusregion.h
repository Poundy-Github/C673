/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plusregion.h

  DESCRIPTION:            Set all region depending data (vehicle in activation/ deactivation or hold region).

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_plusregion.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:29CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:11CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:49CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.4 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_plusregion.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusregion.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGES:                Revision 1.3 2012/02/13 06:24:10CET Brunn, Marcus (brunnm) 
  CHANGES:                used relevant traffic flag from extended object list
  CHANGES:                --- Added comments ---  brunnm [Feb 13, 2012 6:24:11 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.2 2012/02/06 15:27:45CET Brunn, Marcus (brunnm) 
  CHANGES:                turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGES:                Revision 1.1 2012/01/31 06:43:28CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_PLUS_REGION_INCLUDED
#define HLAF_PLUS_REGION_INCLUDED

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
void HLAPlusRegion_VehiclePosition( const HLAF_t_RequiredInputs *pIn,
                                    const HLAplusInputData_t    *pPlusInput,
                                    const HLAFData_t            *pFData,
                                    HLAplusData_t               *pPlusData,
                                    const HLAplusParameters_t   *pPar,
                                    eHLAplusHBState_t  eHBState_Left,
                                    eHLAplusHBState_t  eHBState_Right
                                  );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
