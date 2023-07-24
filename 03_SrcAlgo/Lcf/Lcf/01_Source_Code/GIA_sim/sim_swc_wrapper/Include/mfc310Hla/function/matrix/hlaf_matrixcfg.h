/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrixcfg.h

  DESCRIPTION:            HLA matrix beam parameter.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-11-05

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_matrixcfg.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:22CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:00CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:41CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGES:                Revision 1.4 2014/03/25 18:38:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_matrixcfg.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_matrixcfg.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/matrix/project.pj.
  CHANGES:                Revision 1.3 2013/04/12 12:45:21CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Took more coding parameters into use
  CHANGES:                --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:21 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.2 2013/03/11 10:37:40CET Brunn, Marcus (brunnm) 
  CHANGES:                initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
  CHANGES:                --- Added comments ---  brunnm [Mar 11, 2013 10:37:41 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.1 2012/12/03 13:02:05CET Brunn, Marcus (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_MATRIX_CFG_INCLUDED
#define HLAF_MATRIX_CFG_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* ~CodeReview ~ID:d2aa3a6e00e19e44abdc838c3cbd3a63 ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:Remove superfluous include of global_type */
#include "glob_type.h"
#include "hlaf_cfg.h"

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
  float32 BndryLeft_Ang_Default;
  float32 BndryLeft_Ang_Min;
  float32 BndryLeft_Ang_Max;

  float32 BndryRight_Ang_Default;
  float32 BndryRight_Ang_Min;
  float32 BndryRight_Ang_Max;

  float32 BndryLower_Ang_Default;
  float32 BndryLower_Ang_Min;
  float32 BndryLower_Ang_Max;

  float32 ClosestObj_Dist_Default;
  float32 ClosestObj_Dist_Min;
  float32 ClosestObj_Dist_Max;

  float32 ClosestObj_Ang_Default;
  float32 ClosestObj_Ang_Min;
  float32 ClosestObj_Ang_Max;

  float32 MinLight_Dist_Default;
  float32 MinLight_Dist_Min;
  float32 MinLight_Dist_Max;

  float32 MinLight_Ang_Default;
  float32 MinLight_Ang_Min;
  float32 MinLight_Ang_Max;

  float32 LowBeam_Dist_Default;
  float32 LowBeam_Dist_Min;
  float32 LowBeam_Dist_Max;
  float32 LowBeam_Dist_Onc_Min;
  float32 LowBeam_Dist_Onc_Max;
  float32 LowBeam_Dist_Prec_Min;
  float32 LowBeam_Dist_Prec_Max;
  
  float32 LowBeam_Ang_Default;
  float32 LowBeam_Ang_Min;
  float32 LowBeam_Ang_Max;
}HLAFMatrixParOutput_t;
  

typedef struct
{
  /* keep GFA for minimal time after vehicle is lost */
  /* -> then delete GFA                              */
  float32 KeepGFAMinTime_s;
} HLAFMatrixParGFA_t;

/* parameter set for clustering of vehicle 2 GFA */
typedef struct
{
  float32 dAngPrec; /* [rad] min. angle between two lights to cluster preceding with preceding lights */
  float32 dAngOnc;  /* [rad] min. angle between two lights to cluster oncoming with oncoming lights */
  float32 dAng;     /* [rad] min. angle between two lights to cluster preceding with oncoming lights */
  float32 WidthPrec;/* [m] min. lateral distance between two lights to cluster preceding with preceding lights */
  float32 WidthOnc; /* [m] min. lateral distance between two lights to cluster oncoming with oncoming lights */
  float32 Width;    /* [m] min. lateral distance between two lights to cluster preceding with oncoming lights */
} HLAFMatrixParClusterVeh2GFA_t;


/*! typedef struct for HLA Matrix beam parameters */
typedef struct
{
  /* turn on delay based on TTB of the tracks */
  HLAFParameterTurnOnDelay_t   TurnOnDelay; 

  /* conditions for keeping HB off */
  HLAFParameterKeepOff_t          KeepOff;

  HLAFMatrixParGFA_t GFA;

  HLAFMatrixParClusterVeh2GFA_t ClusterVeh2GFA;

  /* defaults, min and max value for output data */
  HLAFMatrixParOutput_t Output;
}HLAFMatrixParameter_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern const HLAFMatrixParameter_t hlafMatrixParameter;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/


/* avoid cyclic binding ---------------------------------------------------*/
#endif
