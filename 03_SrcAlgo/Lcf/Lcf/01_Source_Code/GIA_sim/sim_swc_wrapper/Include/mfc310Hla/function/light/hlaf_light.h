/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_light.h

  DESCRIPTION:            HLA light function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_light.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:12CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/light/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:56CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/light/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:39CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/light/project.pj
  CHANGES:                Revision 1.4 2014/03/25 18:39:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_light.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_light.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/light/project.pj.
  CHANGES:                Revision 1.3 2013/12/13 16:45:06CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:06 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.2 2012/04/21 15:04:33CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced first hla light version
  CHANGES:                --- Added comments ---  brunnm [Apr 21, 2012 3:04:33 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.1 2011/02/24 15:04:31CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_LIGHT_INCLUDED
#define HLAF_LIGHT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"
#include "hlaf_type.h"
#include "hlaf_cfg.h"
#include "hlaf_ext.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* hla light data (internal data) */
typedef struct
{ 
  HLAFPenaltyTimer_t      PenaltyTimer;
  HLAFRelevantVehicle_t   RelevantVehicle;      /* relevant vehicle -> e.g. max TTB */
    
  /* turn off reason */
  HLAFStdTurnOffReason_t  TurnOffReason;        /* turn off reason for full high beam */

  /* keep off reason */
  HLAFStdKeepOffReason_t  KeepOffReason;        /* keep off reason for full high beam */
   
  HLAFLightOut_t          Out;                  /* output data */
} HLAFLightData_t;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern HLAFLightData_t hlafLightData;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAFLightInit(const HLAFParameterLight_t *pPar);

void HLAFLightMain( /* input */
                    const HLAF_t_RequiredInputs  *ps_In,
                    const HLAFParameterLight_t   *pPar,
                    const HLAFData_t             *pFData,
                    /* output */
                    HLAFLightOut_t               *pOut
                  );

void HLAFLightMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);

/* avoid cyclic binding ---------------------------------------------------*/
#endif
