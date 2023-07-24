/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_icon.h

  DESCRIPTION:            Functions for icon handling.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          05.05.2011

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_brightness.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:55CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:34CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:27CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.8 2014/03/25 18:36:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_brightness.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_brightness.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.7 2014/02/18 13:21:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:47 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.6 2013/03/11 14:33:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:10 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.5 2012/10/18 17:55:41CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:55:42 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.4 2012/09/04 19:01:36CEST Brunn, Marcus (brunnm) 
  CHANGE:                 improved brightness state detection
  CHANGE:                 --- Added comments ---  brunnm [Sep 4, 2012 7:01:36 PM CEST]
  CHANGE:                 Change Package : 143736:3 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.3 2012/03/26 16:36:42CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced special handling after startup, at standstill and while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 26, 2012 4:36:42 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.2 2012/03/22 18:27:10CET Brunn, Marcus (brunnm) 
  CHANGE:                 reworked brightness calculation (fixed false HB turn on during twilight3)
  CHANGE:                 Revision 1.1 2011/05/17 13:01:07CEST Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.2 2011/05/10 16:41:11CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 removed MISRA Errros
  CHANGE:                 --- Added comments ---  brunnm [May 10, 2011 4:41:11 PM CEST]
  CHANGE:                 Change Package : 53526:2 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.1 2011/05/06 05:46:27CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE: 
  CHANGE:                 
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_BRIGHTNESS_INCLUDED
#define HLA_BRIGHTNESS_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"
#include "hlar_ext.h"
#include "hla_cfg.h"
#include "hla_base.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  /* positiv result */
  float32   distPos_m;      /* incremented only while driving forwards */
  float32   timePos_s;      /* incremented only while driving forwards */
  float32   timePosAll_s;   /* incremented all the time even at standstill or while driving backwards */
  /* negativ result */
  float32   distNeg_m;      /* incremented only while driving forwards */
  float32   timeNeg_s;      /* incremented only while driving forwards */
  float32   timeNegAll_s;   /* incremented all the time even at standstill or while driving backwards */
  
  float32   factor_radius;
  float32   factor_turbo;        
  float32   factor_signal; /* signal/ threshold factor */
  float32   factor_total;

  /* positive or negative criteria fulfilled ? */
  ARRAY(boolean, HLA_BRIGHTNESS_NUM_POS_CRITERIA, bCriteriaPosFulfilled);  /* true: criteria fulfilled, false: criteria not fulfilled */
  ARRAY(boolean, HLA_BRIGHTNESS_NUM_NEG_CRITERIA, bCriteriaNegFulfilled);  /* true: criteria fulfilled, false: criteria not fulfilled */
} HLABrightnessDistTime_t;

/*! Type definition for brightness outside state */
typedef enum
{
  HLA_BRIGHTNESS_RESULT_INIT         = 0u,
  HLA_BRIGHTNESS_RESULT_INIT_NEGATIV = 1u,
  HLA_BRIGHTNESS_RESULT_INIT_POSITIV = 2u,
  HLA_BRIGHTNESS_RESULT_NEGATIV      = 3u,
  HLA_BRIGHTNESS_RESULT_POSITIV      = 4u,
  HLA_BRIGHTNESS_RESULT_UNKNOWN      = 5u,
  HLA_BRIGHTNESS_RESULT_ERROR        = 6u
} eHLABrightnessResult;


typedef struct
{
  float32         Int;
  HLADataState_t  State;
} HLABrightnessInt_t;

typedef struct
{
  HLABrightnessInt_t        RoiIntF;  /* mean intensity of the n darkest cells of the sub sampled image (5x5 cells) */ 
                                      /* "f" : filtered intensity over the 25 cells and not over time               */  

  HLABrightnessDistTime_t   Twilight_1;
  HLABrightnessDistTime_t   Twilight_2;
  HLABrightnessDistTime_t   Twilight_3;
  HLABrightnessDistTime_t   Night;

  eHLABrightnessResult      eTwilight_1;
  eHLABrightnessResult      eTwilight_2;
  eHLABrightnessResult      eTwilight_3;
  eHLABrightnessResult      eNight;
} HLABrightnessData_t;


/*****************************************************************************
  Variables 
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
void HLABrightnessInit( HLABrightnessData_t*      pBrightnessData,
                        RTE_HLAR_BrightnessState* pBrightnessState
                       );
void HLABrightnessExec( /* input */
                        const HLASegSubImage_t          *pSubImg, 
                        const HLACameraData_t           *pCamData,
                        const HLA_t_eMovementState      eMoveState,
                        const HLABrightnessParameters_t *pPar,
                        /* history */
                        HLABrightnessData_t             *pBrightness,
                        /* output */
                        RTE_HLAR_BrightnessState        *peBrightnessState
                      );

#endif