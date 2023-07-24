/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrix.h

  DESCRIPTION:            HLA matrix beam function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-11-05

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_matrix.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:21CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:59CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:41CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.9 2014/03/25 18:38:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_matrix.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_matrix.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/matrix/project.pj.
  CHANGES:                Revision 1.8 2014/03/04 12:59:00CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for I390 RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 12:59:01 PM CET]
  CHANGES:                Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.7 2013/12/13 16:45:05CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:06 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.6 2013/03/12 10:59:26CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:26 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.5 2013/03/11 16:48:20CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced  no longer needed macros by RTE ones
  CHANGES:                - HLAR_MAX_NUM_DEFECT_PIXEL
  CHANGES:                - HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
  CHANGES:                - HLAF_NIGHTVIEW_OBJECTS
  CHANGES:                - HLA_FINGERPRINT_PIXELS
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 4:48:21 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.4 2013/03/11 10:37:34CET Brunn, Marcus (brunnm) 
  CHANGES:                initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
  CHANGES:                --- Added comments ---  brunnm [Mar 11, 2013 10:37:35 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.3 2013/03/08 17:43:05CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed HeadlightState and taken RTE type into use
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:06 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.2 2013/03/08 10:30:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:58 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2012/12/03 13:02:02CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_MATRIX_INCLUDED
#define HLAF_MATRIX_INCLUDED

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


typedef struct  
{
  uint8 ObjID; /* object ID of the first vehicle in this glare free area */

  /* min/max TTB18 for left/ right border */
  float32 TTB18Left_min;
  float32 TTB18Left_max;
  float32 TTB18Right_min;
  float32 TTB18Right_max;

  /* elapsed time since last vehicle in GFA */
  float32 TimerNoVeh_s;
}HLAFMatrixGFADataInt_t;

typedef struct  
{
  HLAF_t_MatrixGFA        Ext; /* external */
  HLAFMatrixGFADataInt_t  Int; /* internal */
}HLAFMatrixGFAData_t;


typedef struct  
{
  ARRAY(HLAFMatrixGFAData_t, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS, GFA);  /*!< glare free area list          */
  uint32                  nGFA;   /*!< number of Glare free areas                                      */
  RTE_HLAF_SignalStatus   GFAStatus; /*!< glare free area status (GFA valid, GFA invalid, signal invalid) */
}HLAFMatrixGFA_t; 

typedef struct  
{
  HLAFMatrixGFA_t         GFA;

  RTE_HLAF_HighBeamState  HighBeamState; /*!< HLA high beam state */
  uint32                  TurnOffReason; /*!< HLA turn off reason */
}HLAFMatrixInt_t;

/* internal object data */
typedef struct  
{
  uint8 TrackID;     /* TrackID */
  uint8 TrackIDPair; /* TrackID of pair light */


  uint8  ObjID;     /* [0.. RTE_HLAR_OBJECT_LIST_LENGTH] object ID */
  uint8  ObjIDPair; /* [0.. RTE_HLAR_OBJECT_LIST_LENGTH] object ID */
  
  uint8  ObjNext;   /* next object in this glare free area */
  uint8  GFA; /* best matching GFA */

}HLAObjectDataInt_t;


/* hla matrix beam data */
typedef struct
{
  ARRAY(HLAObjectDataInt_t, RTE_HLAR_OBJECT_LIST_LENGTH, Object);      /*!< object list */
  
  HLAFMatrixInt_t Matrix;


  HLAFPenaltyTimer_t      PenaltyTimer;
  HLAFRelevantVehicle_t   RelevantVehicle;      /* relevant vehicle -> e.g. max TTB */

  /* turn off reason */
  HLAFStdTurnOffReason_t  TurnOffReason;        /* turn off reason for full high beam */

  /* keep off reason */
  HLAFStdKeepOffReason_t  KeepOffReason;        /* keep off reason for full high beam */


  HLAFMatrixOut_t        Out;                  /* output data */

} HLAFMatrixData_t;


/* hla matrix beam input data */
typedef struct
{
  float32 Dummy;
} HLAFMatrixInput_t;



/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAFMatrixInit(HLAFMatrixOut_t *pOut);

void HLAFMatrixMain( /* input */
                      const HLAF_t_RequiredInputs  *ps_In,
                      const HLAFMatrixParameter_t *pPar,
                      const HLAFData_t             *pFData,
                      /* output */
                      HLAFMatrixOut_t             *pOut
                    );

void HLAFMatrixMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);


/* avoid cyclic binding ---------------------------------------------------*/
#endif
