/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_standard.h

  DESCRIPTION:            HLA standard function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_standard.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:33CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/standard/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:15CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/standard/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:52CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/standard/project.pj
  CHANGES:                Revision 1.21 2014/03/25 18:41:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_standard.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_standard.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/standard/project.pj.
  CHANGES:                Revision 1.20 2013/12/13 16:44:43CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:44 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.19 2013/03/11 18:01:54CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace some types by RTE ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 6:01:54 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.18 2013/01/18 07:46:05CET Brunn, Marcus (brunnm) 
  CHANGES:                initial matrix beam version for BMW I210
  CHANGES:                --- Added comments ---  brunnm [Jan 18, 2013 7:46:06 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.17 2012/11/15 09:56:53CET Brunn, Marcus (brunnm) 
  CHANGES:                interface update for MFC4B0, BMW I210 (without RTE)
  CHANGES:                --- Added comments ---  brunnm [Nov 15, 2012 9:56:54 AM CET]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.16 2012/04/21 15:04:41CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced first hla light version
  CHANGES:                --- Added comments ---  brunnm [Apr 21, 2012 3:04:41 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.15 2012/03/07 07:19:35CET Brunn, Marcus (brunnm) 
  CHANGES:                HLAFStandardData_t:
  CHANGES:                - removed OutWork, OutPrev
  CHANGES:                - added Out
  CHANGES:                --- Added comments ---  brunnm [Mar 7, 2012 7:19:37 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.14 2012/02/20 16:40:38CET Brunn, Marcus (brunnm) 
  CHANGES:                hlaf optimization in curvy roads
  CHANGES:                --- Added comments ---  brunnm [Feb 20, 2012 4:40:38 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.13 2012/02/08 16:57:54CET Brunn, Marcus (brunnm) 
  CHANGES:                - fixed detection of relevant traffic
  CHANGES:                - hla plus: fast HB on when oncoming traffic passed
  CHANGES:                Revision 1.12 2012/01/31 06:39:46CET Brunn, Marcus (brunnm) 
  CHANGES:                restructuring of HLAF Plus
  CHANGES:                --- Added comments ---  brunnm [Jan 31, 2012 6:39:46 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.11 2012/01/19 09:52:02CET Brunn, Marcus (brunnm) 
  CHANGES:                updated diagnosis debug message (64Bit)
  CHANGES:                - added icon result (HB on), HLAF turn off reason, keep off reason and hla version
  CHANGES:                Revision 1.10 2011/12/07 14:38:34CET Brunn, Marcus (brunnm) 
  CHANGES:                HLAF fixes as result of Woltermann test drive from 2.12.2011
  CHANGES:                --- Added comments ---  brunnm [Dec 7, 2011 2:38:34 PM CET]
  CHANGES:                Change Package : 90722:1 http://mks-psad:7002/im/viewissue?selection=90722
  CHANGES:                Revision 1.9 2011/12/05 15:21:22CET Brunn, Marcus (brunnm) 
  CHANGES:                keep off HB max 1sec when potential vehicle is detected
  CHANGES:                --- Added comments ---  brunnm [Dec 5, 2011 3:21:22 PM CET]
  CHANGES:                Change Package : 90722:1 http://mks-psad:7002/im/viewissue?selection=90722
  CHANGES:                Revision 1.8 2011/11/29 09:20:55CET Brunn, Marcus (brunnm) 
  CHANGES:                reworked of HLA Standard
  CHANGES:                Revision 1.7 2011/11/24 12:56:36CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                improved target driving direction detection for oncoming vehicles
  CHANGES:                Revision 1.6 2011/11/15 19:34:25CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                MISRA fix
  CHANGES:                --- Added comments ---  brunnm [Nov 15, 2011 7:34:26 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.5 2011/11/15 18:08:12CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                - moved full HB turn off and keep off reason to hlaf standard
  CHANGES:                --- Added comments ---  brunnm [Nov 15, 2011 6:08:12 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.4 2011/11/11 14:57:23CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                added hlaf measfreezes
  CHANGES:                --- Added comments ---  brunnm [Nov 11, 2011 2:57:24 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.3 2011/09/27 16:50:37CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                udate for HLAR/ F separation
  CHANGES:                Revision 1.2 2011/09/27 13:39:56CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                separation of HLAR/ HLAF
  CHANGES:                --- Added comments ---  brunnm [Sep 27, 2011 1:39:56 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.1 2011/02/24 15:04:33CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_STANDARD_INCLUDED
#define HLAF_STANDARD_INCLUDED

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

typedef struct
{
  RTE_HLAF_ObjStatus    eTargetDrivingDirection;  /* internal target driving direction */
  float32               DelayTimer_s;             /* change target driving direction from oncoming to preceding (if detected) after a certain delay (e.g. 2sec on country roads, 5 sec on highways) */
} HLAFStandardTargetDrivingDir_t;

typedef struct
{
  const HLA_t_Object  *pVeh;              /* closest vehicle  */
  float32             MinDist_m;          /* min distance (oncoming limited to 150m) */
  float32             Ang;                /* horizontal angle */
  boolean             bOncomingDetected;  /* any oncoming vehicle detected */
} HLAFStandardVehicleClosest;


/* hla standard data (internal data) */
typedef struct
{ 
  HLAFStandardTargetDrivingDir_t  TargetDrivingDir;
  HLAFStandardVehicleClosest      VehicleClosest;

  HLAFPenaltyTimer_t              PenaltyTimer;
  HLAFRelevantVehicle_t           RelevantVehicle;      /* relevant vehicle -> e.g. max TTB */
  
  /* turn off reason */
  HLAFStdTurnOffReason_t          TurnOffReason;        /* turn off reason for full high beam */
  
  /* keep off reason */
  HLAFStdKeepOffReason_t          KeepOffReason;        /* keep off reason for full high beam */
      
  HLAFStdOut_t                    Out;                  /* output data */
} HLAFStandardData_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern HLAFStandardData_t hlafStdData;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAFStandardInit(const HLAFParameterStandard_t *pPar);

void HLAFStandardMain( /* input */
                       const HLAF_t_RequiredInputs   *ps_In,
                       const HLAFParameterStandard_t *pPar,
                       const HLAFData_t              *pFData,
                       /* output */
                       HLAFStdOut_t                  *pOut
                     );

void HLAFStandardMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);

/* avoid cyclic binding ---------------------------------------------------*/
#endif
